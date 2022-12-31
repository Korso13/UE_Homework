// Fill out your copyright notice in the Description page of Project Settings.


#include "TankWithInventory.h"
#include <TankInventorySystem.h>
#include "../Canon.h"
#include "../Projectile.h"
/*#include "Components/AudioComponent.h"
#include "Components/BoxComponent.h"*/
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "InventoryComponent.h"
#include "../Base_Consumable.h"
#include "EquipInventoryComponent.h"
#include "InventoryManagerComponent.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

#include "SaveManager.h"
#include "../TankGameInstance.h"
#include "TankSaveGame.h"


DEFINE_LOG_CATEGORY(InvTankLog);

ATankWithInventory::ATankWithInventory()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SecondaryTurretMesh = CreateDefaultSubobject<UStaticMeshComponent>("Secondary Turret esh");
	SecondaryTurretMesh->SetupAttachment(BodyMesh);
	SecondaryCanonMountingPoint = CreateDefaultSubobject<UArrowComponent>("Secondary Turret Mounting Point");
	SecondaryCanonMountingPoint->SetupAttachment(SecondaryTurretMesh);

	Inventory = CreateDefaultSubobject<UInventoryComponent>("Inventory Component");
	EquipInventory = CreateDefaultSubobject<UEquipInventoryComponent>("Equipment Component");
	InventoryManager = CreateDefaultSubobject<UInventoryManagerComponent>("Inventory Manager Component");
}

// Called when the game starts or when spawned
void ATankWithInventory::BeginPlay()
{
	Super::BeginPlay();

	if (InventoryManager)
	{
		if(Inventory)
		{
			InventoryManager->Init(Inventory, EInventoryClass::IC_CharInventory);
			InventoryManager->OnInventoryChanged.BindUObject(this, &ATankWithInventory::UpdateSavedInventories);
		}
		if(EquipInventory)
		{
			InventoryManager->Init(EquipInventory, EInventoryClass::IC_EquipInventory);
			for (const auto& [SlotNumber, SlotInfo] : EquipInventory->GetInventory())
			{
				EquipItem(EquipInventory->GetEquipSlotByIndex(SlotNumber), SlotInfo.ItemId, true);
			}
			InventoryManager->SetEquipInventory(EquipInventory);
			Cannon = nullptr;
			InventoryManager->OnEquipmentInventoryChanged.BindUObject(this, &ATankWithInventory::UpdateSavedInventories);
		}
	}

	if (CannonOne)
	{
		FirstCannonUsed = true;
		StatusHUDInfo.CurrentWeapon = CannonOne;
		StatusHUDInfo.WeaponAmmo = PrimaryAmmo;
	}
	else if (CannonTwo)
	{
		SecondCannonUsed = true;
		StatusHUDInfo.CurrentWeapon = CannonTwo;
		StatusHUDInfo.WeaponAmmo = SecondaryAmmo;
	}
	else
	{
		FirstCannonUsed = false;
		SecondCannonUsed = false;
	}
	
	RegisterOnSaveFile();
}

void ATankWithInventory::RegisterOnSaveFile()
{
	if(!SaveManager)
	{
		SaveManager = Cast<UTankGameInstance>(GetGameInstance())->GetSaveManager(GetWorld());
	}
	
	//PawnState = MakeShared<FPawnState>(SaveManager->CurrentSave->TankPawnState);
	PawnState = &SaveManager->CurrentSave->TankPawnState;
	
	if(!PawnState)
	{
		return;
	}
	
	PawnState->SavedPawn = this;
	PawnState->PawnClass = GetClass();
	PawnState->PawnLocation = GetActorLocation();
	PawnState->PawnRotation = GetActorRotation();
	PawnState->PlayerTotalScore = TotalScore;
	PawnState->IsAI = false;

	if(HealthComponent)
	{
		PawnState->PawnHP = HealthComponent->CurrentHP;
	}

	if(Inventory && EquipInventory)
	{
		PawnState->InventoryContents = Inventory->GetInventory();
		PawnState->EquipInventoryContents = EquipInventory->GetInventory();
	}

	PawnState->PawnAmmoPrimary = PrimaryAmmo;
	PawnState->PawnAmmoSecondary = SecondaryAmmo;
	PawnState->PlayerTotalScore = TotalScore;
}

void ATankWithInventory::UpdateSavedInventories()
{
	if(Inventory && EquipInventory && PawnState) 
	{
		PawnState->InventoryContents.Empty();
		PawnState->InventoryContents = Inventory->GetInventory();
		PawnState->EquipInventoryContents.Empty();
		PawnState->EquipInventoryContents = EquipInventory->GetInventory();
	}
}

void ATankWithInventory::LoadState(FPawnState& InState)
{
	PawnState = &InState;

	if(!PawnState)
	{
		return;
	}

	SetActorLocation(PawnState->PawnLocation);
	SetActorRotation(PawnState->PawnRotation);
	if(HealthComponent)
	{
		HealthComponent->CurrentHP = PawnState->PawnHP;
	}

	PrimaryAmmo = PawnState->PawnAmmoPrimary;
	if(CannonOne)
	{
		CannonOne->SetCurrAmmo(PrimaryAmmo);
	}
	SecondaryAmmo = PawnState->PawnAmmoSecondary;
	if(CannonTwo)
	{
		CannonTwo->SetCurrAmmo(SecondaryAmmo);
	}

	TotalScore = PawnState->PlayerTotalScore;
	
	if(InventoryManager)
	{
		InventoryManager->LoadInventoriesFromSave(PawnState->InventoryContents, PawnState->EquipInventoryContents);

		//updating tank's equipment from restored equip inventory
		for(auto [id, item] : EquipInventory->GetInventory())
		{
			switch (id)
			{
				case (0):
					{
						if(item.ItemId == "NoItem")
						{
							EquipItem(EEquipSlot::EQ_PrimaryCannon, item.ItemId, false);
						}
						else
						{
							EquipItem(EEquipSlot::EQ_PrimaryCannon, item.ItemId, true);
						}
						break;
					}
				case (1):
					{
						if(item.ItemId == "NoItem")
						{
							EquipItem(EEquipSlot::EQ_SecondaryCannon, item.ItemId, false);
						}
						else
						{
							EquipItem(EEquipSlot::EQ_SecondaryCannon, item.ItemId, true);
						}
						break;
					}
				case (2):
					{
						if(item.ItemId == "NoItem")
						{
							EquipItem(EEquipSlot::EQ_Armor, item.ItemId, false);
						}
						else
						{
							EquipItem(EEquipSlot::EQ_Armor, item.ItemId, true);
						}
						break;
					}
				case (3):
					{
						if(item.ItemId == "NoItem")
						{
							EquipItem(EEquipSlot::EQ_PowerModule, item.ItemId, false);
						}
						else
						{
							EquipItem(EEquipSlot::EQ_PowerModule, item.ItemId, true);
						}
						break;
					}
				case (4):
					{
						if(item.ItemId == "NoItem")
						{
							EquipItem(EEquipSlot::EQ_Consumable, item.ItemId, false);
						}
						else
						{
							EquipItem(EEquipSlot::EQ_Consumable, item.ItemId, true);
						}
						break;
					}
				default:
					{
						break;
					}
			}
		}
	}

	//updating info for HUD
	StatusHUDInfo.CurrentWeapon = (FirstCannonUsed ? CannonOne : CannonTwo);
	StatusHUDInfo.WeaponAmmo = (FirstCannonUsed ? PrimaryAmmo : SecondaryAmmo);
}

void ATankWithInventory::EquipCannon(const FInventoryItemInfo* InItemInfo, bool bToEquip, EEquipSlot CannonSlot)
{
	if (!InItemInfo)
		return;

	if (CannonSlot == EEquipSlot::EQ_PrimaryCannon)
	{
		if (!bToEquip) //unequipping primary cannon
		{
			if (CannonOne)
			{
				CannonOne->Destroy();
				CannonOne = nullptr;
			}
			if (CannonTwo)
			{
				FirstCannonUsed = false;
				SecondCannonUsed = true;
				StatusHUDInfo.CurrentWeapon = CannonTwo;
				StatusHUDInfo.WeaponAmmo = SecondaryAmmo;
			}
			else
			{
				FirstCannonUsed = false;
				SecondCannonUsed = false;
				StatusHUDInfo.CurrentWeapon = nullptr;
				StatusHUDInfo.WeaponAmmo = 0;
			}
			//UpdateSavedInventories();
			return;
		}
		else if(InItemInfo->ItemClass && CanonMountingPoint)
		{
			FTransform CannonSetupTransform = CanonMountingPoint->GetComponentTransform();
			CannonOne = GetWorld()->SpawnActorDeferred<ACanon>(InItemInfo->ItemClass, CannonSetupTransform, this, this, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
			if (CannonOne)
			{
				CannonOne->SetCurrAmmo(PrimaryAmmo);
				CannonOne->AttachToComponent(TurretMesh, FAttachmentTransformRules::KeepWorldTransform);
				UGameplayStatics::FinishSpawningActor(CannonOne, CannonSetupTransform);
				if (!FirstCannonUsed && !SecondCannonUsed)
				{
					FirstCannonUsed = true;
					StatusHUDInfo.CurrentWeapon = CannonOne;
					StatusHUDInfo.WeaponAmmo = PrimaryAmmo;
				}
			}
			//UpdateSavedInventories();
			return;
		}
	}
	else if (CannonSlot == EEquipSlot::EQ_SecondaryCannon)
	{
		if (!bToEquip) //unequipping secondary cannon
		{
			if (CannonTwo)
			{
				CannonTwo->Destroy();
				CannonTwo = nullptr;
				SecondaryTurretMesh->SetVisibility(false);
			}
			if (CannonOne)
			{
				FirstCannonUsed = true;
				SecondCannonUsed = false;
				StatusHUDInfo.CurrentWeapon = CannonOne;
				StatusHUDInfo.WeaponAmmo = PrimaryAmmo;
			}
			else
			{
				FirstCannonUsed = false;
				SecondCannonUsed = false;
				StatusHUDInfo.CurrentWeapon = nullptr;
				StatusHUDInfo.WeaponAmmo = 0;
			}
			//UpdateSavedInventories();
			return;
		}
		else if (InItemInfo->ItemClass && SecondaryCanonMountingPoint)
		{
			FTransform SecondCannonSetupTransform = SecondaryCanonMountingPoint->GetComponentTransform();
			CannonTwo = GetWorld()->SpawnActorDeferred<ACanon>(InItemInfo->ItemClass, SecondCannonSetupTransform, this, this, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
			if (CannonTwo)
			{
				CannonTwo->SetCurrAmmo(SecondaryAmmo);
				CannonTwo->AttachToComponent(SecondaryTurretMesh, FAttachmentTransformRules::KeepWorldTransform);
				UGameplayStatics::FinishSpawningActor(CannonTwo, SecondCannonSetupTransform);
				SecondaryTurretMesh->SetVisibility(true);
				if (!FirstCannonUsed && !SecondCannonUsed)
				{
					SecondCannonUsed = true;
					StatusHUDInfo.CurrentWeapon = CannonTwo;
					StatusHUDInfo.WeaponAmmo = SecondaryAmmo;
				}
			}
			//UpdateSavedInventories();
			return;
		}
	}
}

void ATankWithInventory::EquipArmor(const FInventoryItemInfo* InItemInfo, bool bToEquip)
{
	if (!bToEquip)
	{
		DMGReduction = 0;
		//UpdateSavedInventories();
		return;
	}
	
	if (InItemInfo)
		if (InItemInfo->ItemCategory == EItemSubType::EST_Armor && bToEquip)
		{
			DMGReduction = InItemInfo->Armor;
			//UpdateSavedInventories();
		}
}

void ATankWithInventory::EquipPM(const FInventoryItemInfo* InItemInfo, bool bToEquip)
{
	if (!bToEquip)
	{
		MovementSpeedBoost = 0;
		//UpdateSavedInventories();
		return;
	}

	if (InItemInfo)
		if (InItemInfo->ItemCategory == EItemSubType::EST_EnginePowerModule && bToEquip)
		{
			MovementSpeedBoost = InItemInfo->StatsBoost;
			//UpdateSavedInventories();
		}
}

void ATankWithInventory::EquipConsumable(const FInventoryItemInfo* InItemInfo, bool bToEquip)
{
	//UE_LOG(InvTankLog, Warning, TEXT("Equip consumable called with %s flag"), ((bToEquip) ? "True" : "False"));
	if (!bToEquip)
	{
		if (ConsumableInSlot)
			ConsumableInSlot->Destroy();
		ConsumableInSlot = nullptr;
		//UpdateSavedInventories();
		return;
	}

	if (InItemInfo)
	{
		//UE_LOG(InvTankLog, Warning, TEXT("InItemInfo in EquipConsumable is valid"));
		if (/*InItemInfo->ItemArchType == EItemArchType::ET_Consumable && */bToEquip && InItemInfo->ItemClass != NULL)
		{
			//UE_LOG(InvTankLog, Warning, TEXT("ItemArchType check in EquipConsumable is green"));
			ConsumableInSlot = NewObject<ABase_Consumable>(this, InItemInfo->ItemClass);
			if (ConsumableInSlot)
			{
				ConsumableInSlot->OwningPawn = this;
				//UpdateSavedInventories();
				//UE_LOG(InvTankLog, Warning, TEXT("Consumable successfully spawned to slot"));
			}
		}

	}
}

void ATankWithInventory::SwitchWeapon()
{
	UE_LOG(InvTankLog, Log, TEXT("Tank Weapon switch called"));
	if (FirstCannonUsed && CannonTwo)
	{
		FirstCannonUsed = false;
		SecondCannonUsed = true;
		StatusHUDInfo.CurrentWeapon = CannonTwo;
		StatusHUDInfo.WeaponAmmo = SecondaryAmmo;
		//UE_LOG(InvTankLog, Log, TEXT("Switch to secondary cannon called"));
		return;
	}
	//UE_LOG(InvTankLog, Warning, TEXT("Didn't switch to secondary. FirstCannonUsed == %b, CannonTwo == %b"), FirstCannonUsed, (CannonTwo) ? true : false);
	if (SecondCannonUsed && CannonOne)
	{
		SecondCannonUsed = false;
		FirstCannonUsed = true;
		StatusHUDInfo.CurrentWeapon = CannonOne;
		StatusHUDInfo.WeaponAmmo = PrimaryAmmo;
		//UE_LOG(InvTankLog, Warning, TEXT("Switch to primary cannon called"));
		return;
	}
	//UE_LOG(InvTankLog, Warning, TEXT("Didn't switch to primary. SecondCannonUsed == %b, CannonOne == %b"), SecondCannonUsed, (CannonOne) ? true : false);

}

ACanon* ATankWithInventory::GetCannon() const
{
	return (FirstCannonUsed ? CannonOne : CannonTwo);
}

void ATankWithInventory::PrimaryFire()
{
	if (!FirstCannonUsed && !SecondCannonUsed)
		return;

	if (FirstCannonUsed && CannonOne)
	{
		UE_LOG(InvTankLog, Warning, TEXT("Primary fire uses primary weapon"));
		if (PrimaryAmmo >= CannonOne->GetAmmoComsumption())
		{
			if(CannonOne->Fire(FireType::Primary))
			{
				PrimaryAmmo -= CannonOne->GetAmmoComsumption();
				CannonOne->SetCurrAmmo(PrimaryAmmo);
				StatusHUDInfo.WeaponAmmo -= CannonOne->GetAmmoComsumption();
			}
		}

		if(PawnState)
			PawnState->PawnAmmoPrimary = PrimaryAmmo;
		return;
	}

	if (SecondCannonUsed && CannonTwo)
	{
		UE_LOG(InvTankLog, Warning, TEXT("Primary fire uses secondary weapon"));
		if (SecondaryAmmo >= CannonTwo->GetAmmoComsumption())
		{
			if(CannonTwo->Fire(FireType::Primary))
			{
				SecondaryAmmo -= CannonTwo->GetAmmoComsumption();
				CannonTwo->SetCurrAmmo(SecondaryAmmo);
				StatusHUDInfo.WeaponAmmo -= CannonTwo->GetAmmoComsumption();
			}
		}
		
		if(PawnState)
			PawnState->PawnAmmoSecondary = SecondaryAmmo;
		return;
	}
}

void ATankWithInventory::SecondaryFire()
{
	if (!FirstCannonUsed && !SecondCannonUsed)
		return;

	if (FirstCannonUsed && CannonOne)
	{
		if (PrimaryAmmo >= CannonOne->GetAltFireAmmoComsumption())
		{
			if(CannonOne->Fire(FireType::Secondary))
			{
				PrimaryAmmo -= CannonOne->GetAltFireAmmoComsumption();
				CannonOne->SetCurrAmmo(PrimaryAmmo);
				StatusHUDInfo.WeaponAmmo -= CannonOne->GetAltFireAmmoComsumption();
			}
		}
		return;
	}

	if (SecondCannonUsed && CannonTwo)
	{
		if (SecondaryAmmo >= CannonTwo->GetAltFireAmmoComsumption())
		{
			if(CannonTwo->Fire(FireType::Secondary))
			{
				SecondaryAmmo -= CannonTwo->GetAltFireAmmoComsumption();
				CannonTwo->SetCurrAmmo(SecondaryAmmo);
				StatusHUDInfo.WeaponAmmo -= CannonTwo->GetAltFireAmmoComsumption();
			}
		}
		return;
	}
}

void ATankWithInventory::MoveForward(const float ForwardAxisImpulse)
{
	ForwardAxisMoveValue = ForwardAxisImpulse * (1 + MovementSpeedBoost);
}

void ATankWithInventory::ToggleInventoryWidget() const
{
	InventoryManager->ToggleInventoryWindow();
}

void ATankWithInventory::SetNanites(int32 InCount)
{
	if (InventoryManager)
	{
		InventoryManager->SetNanites(InCount);
		UpdateSavedInventories();
	}
}

void ATankWithInventory::TakeDamage(FDamageInfo DamageData)
{
	DamageData.DamageValue = DamageData.DamageValue * (1 - DMGReduction);
	HealthComponent->TakeDamage(DamageData);
	
	if(PawnState)
		PawnState->PawnHP -= DamageData.DamageValue;
}

void ATankWithInventory::UseConsumable()
{
	//UE_LOG(InvTankLog, Warning, TEXT("Use consumable called with %d available uses and %s consumable validity check"), (EquipInventory->GetInventory().Find(4)->ItemCount), ((ConsumableInSlot) ? "true" : "false"));
	if (ConsumableInSlot && (EquipInventory->GetInventory().FindChecked(4).ItemCount > 0))
	{
		ConsumableInSlot->UseConsumable();
		FInventorySlotInfo Slot = EquipInventory->GetInventory().FindChecked(4);
		Slot.ItemCount--;
		if(Slot.ItemCount > 0)
			EquipInventory->SetItem(4, Slot);
		else
		{
			EquipInventory->ClearItem(4);
			ConsumableInSlot = nullptr;
		}

		InventoryManager->UpdateEquipWidget();
	}
	if (FirstCannonUsed)
	{
		StatusHUDInfo.WeaponAmmo = PrimaryAmmo;
	}
	else if (SecondCannonUsed)
	{
		StatusHUDInfo.WeaponAmmo = SecondaryAmmo;
	}
	UpdateSavedInventories();
}

void ATankWithInventory::EquipItem(EEquipSlot Slot, FName ItemId, bool bToEquip) //bToEquip determines whether we equip, or take off the item
{
	//UE_LOG(InvTankLog, Warning, "ItemEquipped");
	const FInventoryItemInfo* ItemInfo = InventoryManager->GetItemData(ItemId);
	switch (Slot)
	{
	case EEquipSlot::EQ_PrimaryCannon:
		EquipCannon(ItemInfo, bToEquip, EEquipSlot::EQ_PrimaryCannon);
		break;

	case EEquipSlot::EQ_SecondaryCannon:
		EquipCannon(ItemInfo, bToEquip, EEquipSlot::EQ_SecondaryCannon);
		break;

	case EEquipSlot::EQ_Armor:
		EquipArmor(ItemInfo, bToEquip);
		break;

	case EEquipSlot::EQ_PowerModule:
		EquipPM(ItemInfo, bToEquip);
		break;

	case EEquipSlot::EQ_Consumable:
		EquipConsumable(ItemInfo, bToEquip);
		break;

	default:
		break;
	}
	UpdateSavedInventories();
}

void ATankWithInventory::PickUpItem(FInventorySlotInfo& InItem)
{
	UE_LOG(InvTankLog, Warning, TEXT("Item pickup called"));
	InventoryManager->PickupAddItem(InItem);
}

void ATankWithInventory::AmmoTopup(int32 ExtraAmmo)
{
	UE_LOG(InvTankLog, Warning, TEXT("Ammo topup called"));
	
	PrimaryAmmo += ExtraAmmo;
	SecondaryAmmo += ExtraAmmo;
	if (CannonOne)
		CannonOne->SetCurrAmmo(PrimaryAmmo);
	if(CannonTwo)
		CannonTwo->SetCurrAmmo(SecondaryAmmo);
}

void ATankWithInventory::HPTopup(float RestoredHP)
{
	HealthComponent->CurrentHP += RestoredHP;
	if (HealthComponent->CurrentHP > HealthComponent->MaxHP)
		HealthComponent->CurrentHP = HealthComponent->MaxHP;
}

//to be depricated or repurposed:
 
UStaticMeshComponent* ATankWithInventory::GetEquipComponent(EEquipSlot Slot)
{
	FName EquipTag = "";
	switch (Slot)
	{
	case EEquipSlot::EQ_NONE:
		break;

	case EEquipSlot::EQ_PrimaryCannon: 
		EquipTag = "Primary_Cannon";
		break;

	case EEquipSlot::EQ_SecondaryCannon: 
		EquipTag = "Secondary_Cannon";
		break;

	case EEquipSlot::EQ_Armor:
		EquipTag = "Armor";
		break;

	case EEquipSlot::EQ_PowerModule:
		EquipTag = "PowerModule";
		break;

	default: 
		return nullptr;
	}

	TArray<UActorComponent*> Components = GetComponentsByTag(UStaticMeshComponent::StaticClass(), EquipTag);

	return Components.Num() > 0 ? Cast<UStaticMeshComponent>(Components[0]) : nullptr;
}


