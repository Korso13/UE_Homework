// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();


	// ...
	
}


// Called every frame
//void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

void UInventoryComponent::SetItem(int32 SlotIndex, const FInventorySlotInfo& InItem)
{
	ClearItem(SlotIndex);
	InventoryContents.Add(SlotIndex, InItem);
}

void UInventoryComponent::ClearItem(int32 SlotIndex)
{
	InventoryContents.Remove(SlotIndex);
	InventoryContents.Add(SlotIndex, FInventorySlotInfo());
}

int32 UInventoryComponent::GetMaxItemAmount(int32 SlotIndex, const FInventoryItemInfo& InItem)
{
	FInventorySlotInfo* SlotPtr = InventoryContents.Find(SlotIndex);
	if (SlotPtr == nullptr)
		return -1; //error: slot not found, can't put item
	else
	{
		if (SlotPtr->ItemId == InItem.ItemId)
			return InItem.MaxStack - SlotPtr->ItemCount; //amount to top-up slot
		else
			return 0; //not equal items, can't stack, can switch them
	}

}
