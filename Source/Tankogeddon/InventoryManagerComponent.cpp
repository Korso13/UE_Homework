// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryManagerComponent.h"
#include "InventoryStructs.h"
#include "InventoryCellWidget.h"
#include "InventoryWidget.h"
#include "InventoryComponent.h"
#include "Engine/DataTable.h"

#include "Misc/FileHelper.h"


// Sets default values for this component's properties
UInventoryManagerComponent::UInventoryManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	// ...

	ItemsData = CreateDefaultSubobject<UDataTable>("Loaded Data Table");

}


// Called when the game starts
void UInventoryManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	//initializing Items Data Table if path is set and data table is not selected
	if(!ItemsData)
		ItemsData = NewObject<UDataTable>();
	if (!PathToItemsData.IsEmpty() && ItemsData)
	{
		FFileHelper::LoadFileToString(JSONData, PathToItemsData.GetCharArray().GetData());
		
		ItemsData->RowStruct = FInventoryItemInfo::StaticStruct();
		if (!JSONData.IsEmpty())
			ItemsData->CreateTableFromJSONString(JSONData);
	}
}

int32 UInventoryManagerComponent::GetNanites() const
{
	if (LocalInventory)
	{
		int32 OutCount = 0;
		if(LocalInventory->GetInventorySize()>0)
			OutCount = LocalInventory->GetItem(-1)->ItemCount;
		return OutCount;
	}
	else
		return 0;
}

void UInventoryManagerComponent::OnItemDropFunc(UInventoryCellWidget* From, UInventoryCellWidget* To)
{
	FInventorySlotInfo FromItem = From->GetItem();
	FInventorySlotInfo ToItem = To->GetItem();

	//add interaction with InventoryComponent to change keys of swapped items there. 
	//Will need access to inventory bound to "From" widget for cross-inventory swaps, as well as extra methods in InventoryComponent!

	From->Clear();
	To->Clear();

	if (ItemsData)
	{
		To->AddItem(FromItem, *GetItemData(FromItem.ItemId));
		if (!ToItem.ItemId.IsNone())
			From->AddItem(ToItem, *GetItemData(ToItem.ItemId));
	}
}

void UInventoryManagerComponent::SetNanites(int32 InCount)
{
	if (LocalInventory)
	{
		FInventorySlotInfo OldNanites = *LocalInventory->GetItem(-1);
		OldNanites.ItemCount = InCount;
		LocalInventory->SetItem(-1, OldNanites);
		if (InventoryWidget)
			InventoryWidget->AddItem(*LocalInventory->GetItem(-1), *GetItemData(OldNanites.ItemId), -1);
	}
}

const FInventoryItemInfo* UInventoryManagerComponent::GetItemData(const FName& InID) const
{
	if (ItemsData)
		return ItemsData ? ItemsData->FindRow<FInventoryItemInfo>(InID, "") : nullptr;
	else
		return nullptr;
}

void UInventoryManagerComponent::Init(UInventoryComponent* InInventory)
{
	if (InInventory && ItemsData && InventoryWidgetClass)
	{
		LocalInventory = InInventory;

		if (StartingLoadout && LocalInventory)
		{
			FString ContextString;
			TArray<FName> RowNames;
			RowNames = StartingLoadout->GetRowNames();
			int32 i = 0;

			for (auto& Name : RowNames)
			{

				auto Row = StartingLoadout->FindRow<FInventorySlotInfo>(Name, ContextString);
				if (Row)
				{
					if(ItemsData)
						if (ItemsData->FindRow<FInventoryItemInfo>(Row->ItemId, "")->ItemArchType == EItemArchType::ET_Currency)
						{
							LocalInventory->SetItem(-1, *Row);
						}
						else
						{
							LocalInventory->SetItem(i, *Row);
							i++;
						}
				}
			}
		}

		InventoryWidget = CreateWidget<UInventoryWidget>(GetWorld(), InventoryWidgetClass);
		InventoryWidget->AddToViewport();
		InventoryWidget->Init(FMath::Max(MinInventorySize, LocalInventory->GetInventorySize()));
		InventoryWidget->SetVisibility(ESlateVisibility::Collapsed);
		InventoryWidget->OnItemDrop.AddUObject(this, &UInventoryManagerComponent::OnItemDropFunc);

		for (const auto& [SlotIndex, SlotInfo] : LocalInventory->GetInventory())
		{
			if (auto* Data = GetItemData(SlotInfo.ItemId))
			{
				InventoryWidget->AddItem(SlotInfo, *Data, SlotIndex);
			}
		}
	}
}

void UInventoryManagerComponent::ToggleInventoryWindow() const
{
	if (InventoryWidget)
	{
		if (InventoryWidget->Visibility == ESlateVisibility::Collapsed)
			InventoryWidget->SetVisibility(ESlateVisibility::Visible);
		else
			InventoryWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}



// Called every frame
//void UInventoryManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

