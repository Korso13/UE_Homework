// Fill out your copyright notice in the Description page of Project Settings.


#include "TankWithInventory.h"
#include <TankInventorySystem.h>
#include "InventoryComponent.h"
#include "Base_Consumable.h"
#include "EquipInventoryComponent.h"
#include "InventoryManagerComponent.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>


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
			InventoryManager->Init(Inventory, EInventoryClass::IC_CharInventory);
		if(EquipInventory)
		{
			InventoryManager->Init(EquipInventory, EInventoryClass::IC_EquipInventory);
			for (const auto& [SlotNumber, SlotInfo] : EquipInventory->GetInventory())
			{
				EquipItem(EquipInventory->GetEquipSlotByIndex(SlotNumber), SlotInfo.ItemId, true);
			}
			InventoryManager->SetEquipInventory(EquipInventory);
			Cannon = nullptr;
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
			return;
		}
	}
}

void ATankWithInventory::EquipArmor(const FInventoryItemInfo* InItemInfo, bool bToEquip)
{
	if (!bToEquip)
	{
		DMGReduction = 0;
		return;
	}
	
	if (InItemInfo)
		if (InItemInfo->ItemCategory == EItemSubType::EST_Armor && bToEquip)
			DMGReduction = InItemInfo->Armor;
}

void ATankWithInventory::EquipPM(const FInventoryItemInfo* InItemInfo, bool bToEquip)
{
	if (!bToEquip)
	{
		MovementSpeedBoost = 0;
		return;
	}

	if (InItemInfo)
		if (InItemInfo->ItemCategory == EItemSubType::EST_EnginePowerModule && bToEquip)
			MovementSpeedBoost = InItemInfo->StatsBoost;
}

void ATankWithInventory::EquipConsumable(const FInventoryItemInfo* InItemInfo, bool bToEquip)
{
	UE_LOG(InvTankLog, Warning, TEXT("Equip consumable called with %s flag"), ((bToEquip) ? "True" : "False"));
	if (!bToEquip)
	{
		if (ConsumableInSlot)
			ConsumableInSlot->Destroy();
		ConsumableInSlot = nullptr;
		return;
	}

	if (InItemInfo)
	{
		UE_LOG(InvTankLog, Warning, TEXT("InItemInfo in EquipConsumable is valid"));
		if (/*InItemInfo->ItemArchType == EItemArchType::ET_Consumable && */bToEquip && InItemInfo->ItemClass != NULL)
		{
			UE_LOG(InvTankLog, Warning, TEXT("ItemArchType check in EquipConsumable is green"));
			ConsumableInSlot = NewObject<ABase_Consumable>(this, InItemInfo->ItemClass);
			if (ConsumableInSlot)
			{
				ConsumableInSlot->OwningPawn = this;
				UE_LOG(InvTankLog, Warning, TEXT("Consumable successfully spawned to slot"));
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
		UE_LOG(InvTankLog, Log, TEXT("Switch to secondary cannon called"));
		return;
	}
	UE_LOG(InvTankLog, Warning, TEXT("Didn't switch to secondary. FirstCannonUsed == %b, CannonTwo == %b"), FirstCannonUsed, (CannonTwo) ? true : false);
	if (SecondCannonUsed && CannonOne)
	{
		SecondCannonUsed = false;
		FirstCannonUsed = true;
		StatusHUDInfo.CurrentWeapon = CannonOne;
		StatusHUDInfo.WeaponAmmo = PrimaryAmmo;
		UE_LOG(InvTankLog, Warning, TEXT("Switch to primary cannon called"));
		return;
	}
	UE_LOG(InvTankLog, Warning, TEXT("Didn't switch to primary. SecondCannonUsed == %b, CannonOne == %b"), SecondCannonUsed, (CannonOne) ? true : false);

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
		InventoryManager->SetNanites(InCount);
}

void ATankWithInventory::TakeDamage(FDamageInfo DamageData)
{
	DamageData.DamageValue = DamageData.DamageValue * (1 - DMGReduction);
	HealthComponent->TakeDamage(DamageData);
}

void ATankWithInventory::UseConsumable()
{
	//UE_LOG(InvTankLog, Warning, TEXT("Use consumable called with %d available uses and %s consumable validity check"), (EquipInventory->GetInventory().Find(4)->ItemCount), ((ConsumableInSlot) ? "true" : "false"));
	if (ConsumableInSlot && (EquipInventory->GetInventory().FindChecked(4).ItemCount > 0))
	{
		ConsumableInSlot->UseConsumable();
		FInventorySlotInfo Slot = EquipInventory->GetInventory().FindChecked(4)/*.Find(4)*/;
		Slot.ItemCount--;
		if(Slot.ItemCount > 0)
			EquipInventory->SetItem(4, Slot);
		else
			EquipInventory->ClearItem(4);

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


