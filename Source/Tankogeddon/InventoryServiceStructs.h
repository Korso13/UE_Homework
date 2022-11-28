// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "Engine/DataTable.h"
//
//UENUM(BlueprintType)
//enum class EItemArchType : uint8
//{
//	ET_Undefined = 0,
//	ET_Equippable = 1,
//	ET_Consumable = 2,
//	ET_Currency = 3
//};
//
//UENUM(BlueprintType)
//enum class EItemSubType : uint8
//{
//	EST_Undefined = 0,
//	EST_Weapon = 1,
//	EST_Armor = 2,
//	EST_Ammo = 3,
//	EST_HPItem = 4
//};
//
//class UInventoryCellWidget;
//
//DECLARE_MULTICAST_DELEGATE_TwoParams(FOnItemDrop, UInventoryCellWidget* /*from slot*/, UInventoryCellWidget* /*to slot*/ )
//
//USTRUCT(BlueprintType)
//struct FInventoryItemInfo : public FTableRowBase
//{
//	GENERATED_BODY()
//	
//	UPROPERTY(EditDefaultsOnly, Category = "General")
//	FName ItemId;
//
//	UPROPERTY(EditDefaultsOnly, Category = "General")
//	FText Name;
//
//	UPROPERTY(EditDefaultsOnly, Category = "Types")
//	EItemArchType ItemArchType;
//
//	UPROPERTY(EditDefaultsOnly, Category = "Types")
//	EItemSubType ItemCategory;
//
//	UPROPERTY(EditDefaultsOnly, Category = "Visual")
//	TSoftObjectPtr<UTexture2D> Icon;
//
//	UPROPERTY(EditDefaultsOnly, Category = "Visual")
//	TSoftObjectPtr<UStaticMesh> Mesh;
//
//	UPROPERTY(EditDefaultsOnly, Category = "Item stats")
//	float Damage;
//
//	UPROPERTY(EditDefaultsOnly, Category = "Item stats")
//	float Armor;
//
//	UPROPERTY(EditDefaultsOnly, Category = "Item stats")
//	float ConsumableRestoreValue;
//};
//
//USTRUCT(BlueprintType)
//struct FInventorySlotInfo : public FTableRowBase
//{
//	GENERATED_BODY()
//	
//	UPROPERTY(EditDefaultsOnly, Category = "ID")
//	FName ItemId;
//
//	UPROPERTY(EditDefaultsOnly, Category = "Count")
//	int32 ItemCount;
//};