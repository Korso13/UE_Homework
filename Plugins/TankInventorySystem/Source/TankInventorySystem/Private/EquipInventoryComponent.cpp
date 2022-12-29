// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipInventoryComponent.h"
#include "EquipInterface.h"
//#include "TankWithInventory.h"
#include "InventoryManagerComponent.h"

UEquipInventoryComponent::UEquipInventoryComponent()
{
	EquipSlots.Add(0, EEquipSlot::EQ_PrimaryCannon);
	EquipSlots.Add(1, EEquipSlot::EQ_SecondaryCannon);
	EquipSlots.Add(2, EEquipSlot::EQ_Armor);
	EquipSlots.Add(3, EEquipSlot::EQ_PowerModule);
	EquipSlots.Add(4, EEquipSlot::EQ_Consumable);
}

void UEquipInventoryComponent::SetItem(int32 SlotIndex, const FInventorySlotInfo& InItem)
{
	auto* Owner = GetOwner();
	if (!Owner->Implements<UEquipInterface>())
	{
		Super::SetItem(SlotIndex, InItem);
		return;
	}
	
	/*ClearItem(SlotIndex);
	InventoryContents.Add(SlotIndex, InItem);*/
	InventoryContents.Remove(SlotIndex);
	InventoryContents.Add(SlotIndex, InItem);
	//here goes equipment logic:

	if (IEquipInterface* EquipInterface = Cast<IEquipInterface>(Owner))
	{
		EEquipSlot EquipSlot = EquipSlots.FindChecked(SlotIndex);
		EquipInterface->EquipItem(EquipSlot, InventoryContents[SlotIndex].ItemId, false); //unequipping slotted item

		//Super::SetItem(SlotIndex, InItem); //altering InventoryContents as per parent class


		EquipInterface->EquipItem(EquipSlot, InItem.ItemId, true);
	}
}

void UEquipInventoryComponent::ClearItem(int32 SlotIndex)
{
	auto* Owner = GetOwner();
	if (!Owner->Implements<UEquipInterface>())
	{
		Super::ClearItem(SlotIndex);
		return;
	}

	/*ClearItem(SlotIndex);
	InventoryContents.Add(SlotIndex, InItem);*/
	
	//here goes equipment logic:

	if (IEquipInterface* EquipInterface = Cast<IEquipInterface>(Owner))
	{
		EEquipSlot EquipSlot = EquipSlots.FindChecked(SlotIndex);
		if (auto* EquippedItemInfo = GetItem(SlotIndex)) //if found item already in slot - remove it
		{
			EquipInterface->EquipItem(EquipSlot, EquippedItemInfo->ItemId, false); //unequipping current item
			EquipInterface->EquipItem(EquipSlot, FName{"NoItem"}, true); //equipping empty item
		}


		Super::ClearItem(SlotIndex); //altering InventoryContents as per parent class
	}
}

int32 UEquipInventoryComponent::GetMaxItemAmount(int32 SlotIndex, const FInventoryItemInfo& InItem)
{
	EEquipSlot* EquipSlotTypePtr = EquipSlots.Find(SlotIndex);
	if (InItem.ItemArchType == EItemArchType::ET_Equippable &&
		EquipSlotTypePtr &&
		*EquipSlotTypePtr == InItem.EquipSlot)
		return 0; //can put item in slot, mandatory swap of items!
	else
		return -1; //can't put item in slot
}

void UEquipInventoryComponent::LoadInventory(TMap<int32, FInventorySlotInfo> InInventory)
{
	InventoryContents.Empty();
	InventoryContents = InInventory;
	OwningInventoryManager->Init(this, EInventoryClass::IC_EquipInventory); //must be corrected in case of inclusion in foreign code!!
}
