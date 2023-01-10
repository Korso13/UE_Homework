// Fill out your copyright notice in the Description page of Project Settings.


// ReSharper disable CppExpressionWithoutSideEffects
#include "InventoryManagerComponent.h"
#include "InventoryCellWidget.h"
#include "InventoryWidget.h"
#include "InventoryComponent.h"
#include "EquipInventoryComponent.h"
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
	ItemsData->RowStruct = FInventoryItemInfo::StaticStruct();

}


// Called when the game starts
void UInventoryManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	//initializing Items Data Table if path is set and data table is not selected
	if(!ItemsData)
	{
		ItemsData = NewObject<UDataTable>();
		ItemsData->RowStruct = FInventoryItemInfo::StaticStruct();
	}
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
		if(LocalInventory->GetInventorySize()>0 && LocalInventory->GetItem(-1))
		{
			OutCount = LocalInventory->GetItem(-1)->ItemCount;
			return OutCount;
		}
	}

	return 0;
}

void UInventoryManagerComponent::PickupAddItem(FInventorySlotInfo& InSlot)
{
	if (InventoryWidget && LocalInventory)
	{
		const FInventoryItemInfo* InItemInfo = GetItemData(InSlot.ItemId);
		if (InItemInfo == nullptr)
			return;
		InventoryWidget->AddItem(InSlot, *InItemInfo, LocalInventory->GetInventorySize());
	}
	if (LocalInventory)
	{
		LocalInventory->SetItem(LocalInventory->GetInventorySize(), InSlot);
		OnInventoryChanged.ExecuteIfBound();
	}
}

void UInventoryManagerComponent::LoadInventoriesFromSave(TMap<int32, FInventorySlotInfo> InInventory, TMap<int32, FInventorySlotInfo> InEquipment)
{
	if(LocalInventory)
	{
		*LocalInventory = InInventory;
		StartingLoadout = nullptr;
		Init(LocalInventory, EInventoryClass::IC_CharInventory);
	}

	if(EquipInventory)
	{
		*EquipInventory = InEquipment;
		Init(EquipInventory, EInventoryClass::IC_EquipInventory);
	}
}

void UInventoryManagerComponent::OnItemDropFunc(UInventoryCellWidget* From, UInventoryCellWidget* To)
{
	if (From == nullptr || To == nullptr) //remove To == nullptr condition, add if() - else below were ToItem is decalred. Add default constructor for FInventorySlotInfo and empty cell widgets
		return;

	UInventoryComponent* FromInventory = From->GetParentInventory();
	UInventoryComponent* ToInventory = To->GetParentInventory();

	if (FromInventory == nullptr || ToInventory == nullptr)
		return;

	const FInventorySlotInfo FromItem = From->GetItem();
	//if (FromItem.ItemCount == -1) //error: can't put item
	//	return;

	const FInventoryItemInfo* FromInfo = GetItemData(FromItem.ItemId);

	const FInventorySlotInfo ToItem = To->GetItem();

	const int32 ToItemAmount = ToInventory->GetMaxItemAmount(To->IndexInInventory, *FromInfo); //getting info on what operation should happen next and how much can be moved to To's stack if possible
	
	if (ToItemAmount == -1) //error: can't put item
		return;

	FInventorySlotInfo NewFromItem = ToItem;
	FInventorySlotInfo NewToItem = FromItem;

	const FInventoryItemInfo* NewFromInfo = GetItemData(NewFromItem.ItemId);
	const FInventoryItemInfo* NewToInfo = GetItemData(NewToItem.ItemId);;

	if (ToItemAmount > 0 && NewFromItem.ItemId == NewToItem.ItemId)
		//stack functionality enabled
	{
		NewToItem.ItemCount = ToItem.ItemCount + FMath::Min(ToItemAmount, FromItem.ItemCount);
		NewFromItem.ItemCount = FromItem.ItemCount - FMath::Min(ToItemAmount, FromItem.ItemCount);
		if (NewFromItem.ItemCount == 0) //all "From" stack moved to "To" stack
		{
			NewFromItem = FInventorySlotInfo();
			NewFromInfo = GetItemData(NewFromItem.ItemId);;
		}
	}

	From->Clear();
	if (NewFromInfo)
		From->AddItem(NewFromItem, *NewFromInfo);

	To->Clear();
	if (NewToInfo)
		To->AddItem(NewToItem, *NewToInfo);

	//registering widget changes in real inventory (component)
	FromInventory->SetItem(From->IndexInInventory, NewFromItem);
	ToInventory->SetItem(To->IndexInInventory, NewToItem);

	OnInventoryChanged.ExecuteIfBound();
	OnEquipmentInventoryChanged.ExecuteIfBound();
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

void UInventoryManagerComponent::SetEquipInventory(UInventoryComponent* InInventory)
{
	EquipInventory = InInventory;
}

const FInventoryItemInfo* UInventoryManagerComponent::GetItemData(const FName& InID) const
{
	if (ItemsData)
		return ItemsData ? ItemsData->FindRow<FInventoryItemInfo>(InID, "") : nullptr;
	else
		return nullptr;
}

void UInventoryManagerComponent::Init(UInventoryComponent* InInventory, EInventoryClass InventoryClass)
{
	switch (InventoryClass)
	{
	case EInventoryClass::IC_CharInventory:
	{
		if (InInventory && ItemsData && InventoryWidgetClass)
		{
			LocalInventory = InInventory;
			if (LocalInventory)
			{
				LocalInventory->OwningInventoryManager = this;
				//aligning inventory size to allow full rows of 4 cells and meet minimum inventory size requirement
				if (LocalInventory->GetInventorySize() < MinInventorySize + 1)
				{
					for (size_t i = LocalInventory->GetInventorySize(); i < MinInventorySize; i++) //<= because of currency slot in inventory
					{
						LocalInventory->SetItem(i, FInventorySlotInfo());
					}
				}
				else if (LocalInventory->GetInventorySize() > (MinInventorySize + 1) && ((LocalInventory->GetInventorySize() - 1) % 4 != 0))
				{
					MinInventorySize = (LocalInventory->GetInventorySize() - 1) + (4 - ((LocalInventory->GetInventorySize() - 1) % 4));
					for (size_t i = LocalInventory->GetInventorySize(); i < MinInventorySize; i++) //<= because of currency slot in inventory
					{
						LocalInventory->SetItem(i, FInventorySlotInfo());
					}
				}
				
				if (StartingLoadout)
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
							if (ItemsData)
							{
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
				}
				
				//spawning collapsed inventory widget
				InventoryWidget = CreateWidget<UInventoryWidget>(GetWorld(), InventoryWidgetClass);
				if (InventoryWidget)
				{
					InventoryWidget->ParentInventory = LocalInventory;
					InventoryWidget->AddToViewport();
					InventoryWidget->Init(LocalInventory->GetInventorySize() - 1); //currency slot doesn't count
					InventoryWidget->SetVisibility(ESlateVisibility::Collapsed);
					InventoryWidget->OnItemDrop.AddUObject(this, &UInventoryManagerComponent::OnItemDropFunc);
				}

				//filling widget with data from Inventory Component
				for (const auto& [SlotIndex, SlotInfo] : LocalInventory->GetInventory())
				{
					if (auto* Data = GetItemData(SlotInfo.ItemId))
					{
						InventoryWidget->AddItem(SlotInfo, *Data, SlotIndex);
					}
				}
			
			}
		}
	}
		break;
	
	case EInventoryClass::IC_EquipInventory:
	{
		if (InInventory && EquipWidgetClass)
		{
			EquipInventory = InInventory;
			EquipInventory->OwningInventoryManager = this;
			EquipWidget = CreateWidget<UInventoryWidget>(GetWorld(), EquipWidgetClass);
			if (EquipWidget)
			{
				EquipWidget->ParentInventory = InInventory;
				EquipWidget->InventoryManager = this;
				EquipWidget->OnItemDrop.AddUObject(this, &UInventoryManagerComponent::OnItemDropFunc);
				EquipWidget->AddToViewport();
				EquipWidget->SetVisibility(ESlateVisibility::Collapsed);
				EquipWidget->Init(InInventory->GetInventorySize());
			}
		}
	}
		break;
	case EInventoryClass::IC_Chest:
	{
		if (InInventory && ChestWidgetClass)
		{
			ExternalInventory = InInventory;

			if (ExternalInventory)
			{   //aligning inventory size to allow full rows of 4 cells and meet minimum inventory size requirement
				if (ExternalInventory->GetInventorySize() < MinInventorySize)
				{
					for (size_t i = ExternalInventory->GetInventorySize(); i < MinInventorySize; i++)
					{
						ExternalInventory->SetItem(i, FInventorySlotInfo());
					}
				}
				else if (ExternalInventory->GetInventorySize() > MinInventorySize && (ExternalInventory->GetInventorySize() % 4 != 0))
				{
					MinInventorySize = ExternalInventory->GetInventorySize() + (4 - (ExternalInventory->GetInventorySize() % 4));
					for (size_t i = ExternalInventory->GetInventorySize(); i < MinInventorySize; i++)
					{
						ExternalInventory->SetItem(i, FInventorySlotInfo());
					}
				}

				//spawning collapsed chest inventory widget
				ChestWidget = CreateWidget<UInventoryWidget>(GetWorld(), ChestWidgetClass);
				if (ChestWidget)
				{
					ChestWidget->ParentInventory = ExternalInventory;
					ChestWidget->AddToViewport();
					ChestWidget->Init(ExternalInventory->GetInventorySize());
					ChestWidget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
					ChestWidget->OnItemDrop.AddUObject(this, &UInventoryManagerComponent::OnItemDropFunc);
				}

				//filling widget with data from chest's Inventory Component
				for (const auto& [SlotIndex, SlotInfo] : ExternalInventory->GetInventory())
				{
					if (auto* Data = GetItemData(SlotInfo.ItemId))
					{
						ChestWidget->AddItem(SlotInfo, *Data, SlotIndex);
					}
				}
			}
		}
	}
		break;
	default:
		break;
	}
}


void UInventoryManagerComponent::ToggleInventoryWindow() const
{
	if (InventoryWidget)
	{
		if (InventoryWidget->Visibility == ESlateVisibility::Collapsed)
		{
			InventoryWidget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		}
		else
			InventoryWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UInventoryManagerComponent::ToggleEquipmentWindow()
{
	if (EquipWidget)
	{
		if (EquipWidget->Visibility == ESlateVisibility::Collapsed)
			EquipWidget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		else
			EquipWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
	else if(EquipInventory)
	{
		Init(EquipInventory, EInventoryClass::IC_EquipInventory);
	}
}

bool UInventoryManagerComponent::IsInventoryOpen() const
{
	if (InventoryWidget) 
		return (InventoryWidget->GetVisibility() == ESlateVisibility::SelfHitTestInvisible) ? true : false;
	else 
		return true;
}

void UInventoryManagerComponent::UpdateEquipWidget()
{
	if(EquipWidget)
		EquipWidget->Init(EquipInventory->GetInventorySize());
}

void UInventoryManagerComponent::CloseContainer()
{
	if (ChestWidget)
	{
		ChestWidget->SetVisibility(ESlateVisibility::Collapsed);
		ChestWidget->RemoveFromParent();
		ChestWidget->Destruct();
		ChestWidget = nullptr;
	}
	
	ExternalInventory = nullptr;
}



// Called every frame
//void UInventoryManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

