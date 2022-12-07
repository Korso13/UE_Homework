// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InventoryStructs.h"
#include "CoreMinimal.h"
#include "InventoryComponent.h"
#include "EquipInventoryComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = "Inventory", meta = (BlueprintSpawnableComponent))
class TANKINVENTORYSYSTEM_API UEquipInventoryComponent : public UInventoryComponent
{
	GENERATED_BODY()
public:
	UEquipInventoryComponent();

protected:
	UPROPERTY(EditAnywhere)
	TMap<int32, EEquipSlot> EquipSlots;

public:
	virtual void SetItem(int32 SlotIndex, const FInventorySlotInfo& InItem);

	virtual void ClearItem(int32 SlotIndex);

	virtual int32 GetMaxItemAmount(int32 SlotIndex, const FInventoryItemInfo& InItem);

	EEquipSlot GetEquipSlotByIndex(int32 InIndex) const { return EquipSlots.FindChecked(InIndex); }
};
