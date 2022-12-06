// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataTable.h"
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "InventoryStructs.generated.h"


UENUM(BlueprintType)
enum class EItemArchType : uint8
{
	ET_Undefined = 0,
	ET_Equippable = 1,
	ET_Consumable = 2,
	ET_Currency = 3
};

UENUM(BlueprintType)
enum class EItemSubType : uint8
{
	EST_Undefined = 0,
	EST_Weapon = 1,
	EST_Armor = 2,
	EST_Ammo = 3,
	EST_HPItem = 4,
	EST_EnginePowerModule = 5
};

UENUM(BlueprintType)
enum class EEquipSlot : uint8
{
	EQ_NONE = 100,
	EQ_PrimaryCannon = 0,
	EQ_SecondaryCannon = 1,
	EQ_Armor = 2,
	EQ_PowerModule = 3,
	EQ_Consumable = 4
};

UENUM(BlueprintType)
enum class EInventoryClass : uint8
{
	IC_CharInventory = 0,
	IC_EquipInventory = 1,
	IC_Chest = 2
};

class UInventoryCellWidget;

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnItemDrop, UInventoryCellWidget* /*from slot*/, UInventoryCellWidget* /*to slot*/)

USTRUCT(BlueprintType)
struct FInventoryItemInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "General")
	FName ItemId;

	UPROPERTY(EditDefaultsOnly, Category = "General")
	FText Name;

	UPROPERTY(EditDefaultsOnly, Category = "General")
	int32 MaxStack;

	UPROPERTY(EditDefaultsOnly, Category = "General")
	TSubclassOf<UObject> ItemClass;

	UPROPERTY(EditDefaultsOnly, Category = "Types")
	EItemArchType ItemArchType;

	UPROPERTY(EditDefaultsOnly, Category = "Types")
	EItemSubType ItemCategory;

	UPROPERTY(EditDefaultsOnly, Category = "Types")
	EEquipSlot EquipSlot;

	UPROPERTY(EditDefaultsOnly, Category = "Visual")
	TSoftObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditDefaultsOnly, Category = "Visual")
	TSoftObjectPtr<UStaticMesh> Mesh;

	UPROPERTY(EditDefaultsOnly, Category = "Item stats")
	float Damage;

	UPROPERTY(EditDefaultsOnly, Category = "Item stats")
	float Armor;

	UPROPERTY(EditDefaultsOnly, Category = "Item stats")
	float StatsBoost;

	UPROPERTY(EditDefaultsOnly, Category = "Item stats")
	float ConsumableRestoreValue;
};

USTRUCT(BlueprintType)
struct FInventorySlotInfo : public FTableRowBase
{
	GENERATED_BODY()

	FInventorySlotInfo() : ItemCount(-1) 
	{
		ItemId = FName{ "NoItem" };
	};

	UPROPERTY(EditDefaultsOnly, Category = "ID")
	FName ItemId;

	UPROPERTY(EditDefaultsOnly, Category = "Count")
	int32 ItemCount;
};