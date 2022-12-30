// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Tank.h"
#include "EquipInterface.h"
//#include "Templates/SharedPointer.h"
#include <TankInventorySystem.h>
#include <TankInventorySystem/Public/ActorWithInventory.h>
#include "TankWithInventory.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(InvTankLog, All, All);
/**
 * 
 */
USTRUCT(BlueprintType)
struct FStatusHUDInfo
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly)
	int32 WeaponAmmo;

	UPROPERTY(BlueprintReadOnly)
	ACanon* CurrentWeapon = nullptr;
};

class UInventoryComponent;
class UEquipInventoryComponent;
class UInventoryManagerComponent;
class ABase_Consumable;
class AAmmoBox;

UCLASS()
class TANKOGEDDON_API ATankWithInventory : public ATank, public IEquipInterface, public IActorWithInventory
{
	GENERATED_BODY()

public:
	ATankWithInventory();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	UStaticMeshComponent* SecondaryTurretMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	UArrowComponent* SecondaryCanonMountingPoint;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UInventoryManagerComponent* InventoryManager;

protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UInventoryComponent* Inventory; 

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UEquipInventoryComponent* EquipInventory;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Tank Stats")
	int32 PrimaryAmmo = 20; //20 - default starting ammo

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Tank Stats")
	int32 SecondaryAmmo = 20; //20 - default starting ammo

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Tank Stats")
	float DMGReduction = 0; //how much damage mitigated by armor. 0.2 = 20% damage reduction. Default = 0;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Tank Stats")
	float MovementSpeedBoost = 0; //how much bonus speed tank has. 0.2 = 20% extra speed. Default = 0;

	UPROPERTY()
	FStatusHUDInfo StatusHUDInfo; //for status HUD widget

	UPROPERTY()
	ABase_Consumable* ConsumableInSlot;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Save-load functionality functions
	virtual void RegisterOnSaveFile() override;

	void UpdateSavedInventories();

	virtual void LoadState(FPawnState& InState) override;
	
	//internal inventory-related funcs
	void EquipCannon(const FInventoryItemInfo* InItemInfo, bool bToEquip, EEquipSlot CannonSlot);

	void EquipArmor(const FInventoryItemInfo* InItemInfo, bool bToEquip);

	void EquipPM(const FInventoryItemInfo* InItemInfo, bool bToEquip);

	void EquipConsumable(const FInventoryItemInfo* InItemInfo, bool bToEquip);
	
public:

	friend class USaveManager;
	
	//overriding classic tank functions to suit inventory style tank
	virtual void SetupCanon() override { return; };

	virtual void SwitchWeapon() override;

	virtual void ChangeCanon(TSubclassOf<ACanon> _CanonType) override { return; };

	UFUNCTION(BlueprintCallable)
	virtual ACanon* GetCannon() const override;

	virtual void PrimaryFire() override;

	virtual void SecondaryFire() override;

	virtual void MoveForward(const float ForwardAxisImpulse) override;

	virtual void TakeDamage(FDamageInfo DamageData) override;

	//inventory-related funcs
	UFUNCTION()
	void UseConsumable();

	UFUNCTION(BlueprintCallable)
	void SetNanites(int32 InCount);

	virtual void EquipItem(EEquipSlot Slot, FName ItemId, bool bToEquip) override;

	void PickUpItem(FInventorySlotInfo& InItem);

	void AmmoTopup(int32 ExtraAmmo);

	void HPTopup(float RestoredHP);
	
	virtual UInventoryManagerComponent* GetInventoryManager() override { return InventoryManager; }
	
	UFUNCTION()
	void ToggleInventoryWidget() const;

	UFUNCTION(BlueprintCallable)
	FStatusHUDInfo& GetHUDInfo() { return StatusHUDInfo; };//for status HUD widget

	//depricated or unused:
	virtual UStaticMeshComponent* GetEquipComponent(EEquipSlot Slot) override;
};
