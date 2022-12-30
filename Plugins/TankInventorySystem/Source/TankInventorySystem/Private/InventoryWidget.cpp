// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"
#include "InventoryComponent.h"
#include "InventoryManagerComponent.h"
#include "InventoryCellWidget.h"
#include "Components/UniformGridPanel.h"

DECLARE_LOG_CATEGORY_EXTERN(InvWidget, All, All);
DEFINE_LOG_CATEGORY(InvWidget);

void UInventoryWidget::NativeConstruct()
{
    Super::NativeConstruct();

    for (auto* Cell : CellWidgets)
    {
        InitCell(Cell);
    }
    //if(ParentInventory)
    //    Init(ParentInventory->GetInventorySize());
}

void UInventoryWidget::OnItemDropFunc(UInventoryCellWidget* From, UInventoryCellWidget* To) const
{
	OnItemDrop.Broadcast(From, To);
}

UInventoryCellWidget* UInventoryWidget::CreateCell()
{
	if (CellWidgetClass)
	{
		auto* Cell = CreateWidget<UInventoryCellWidget>(this, CellWidgetClass);
		CellWidgets.Add(Cell);
        InitCell(Cell);
		return Cell;
	}
	return nullptr;

}

void UInventoryWidget::InitCell(UInventoryCellWidget* NewCell)
{
    if (NewCell)
    {
        NewCell->OnItemDrop.AddUObject(this, &UInventoryWidget::OnItemDropFunc);
        NewCell->ParentInventoryWidget = this;
    }
}


void UInventoryWidget::Init(int32 InventorySize)
{
	if (InventoryPanel)
	{
		InventoryPanel->ClearChildren();
		for (int i = 0; i < InventorySize; i++)
		{
			UInventoryCellWidget* Cell = CreateCell();
			if (Cell)
			{
				Cell->IndexInInventory = i;
				InventoryPanel->AddChildToUniformGrid(Cell, i / ItemsInRow, i % ItemsInRow);
			}
		}
	}
    else if(ParentInventory)
    {
        for (auto* Cell : CellWidgets)
        {
            FInventorySlotInfo SlotInfo;
            if(Cell && ParentInventory->GetInventory().Num() > 0)
                SlotInfo = ParentInventory->GetInventory()[Cell->IndexInInventory];
            else
            {
                SlotInfo = FInventorySlotInfo();
            }
            
            const FInventoryItemInfo* InitItemInfo = InventoryManager->GetItemData(SlotInfo.ItemId);
            if (InitItemInfo != nullptr)
            {
                Cell->Clear();
                Cell->AddItem(SlotInfo, *InitItemInfo);
            }
        }
    }
}

bool UInventoryWidget::AddItem(const FInventorySlotInfo& InSlot, const FInventoryItemInfo& ItemInfo, int32 SlotIndex)
{
    if (InSlot.ItemId != "NONE")
    {
        if (ItemInfo.ItemArchType == EItemArchType::ET_Currency)
        {
            if (NanitesSlot)
            {
                return NanitesSlot->AddItem(InSlot, ItemInfo);
            }
            return false;
        }

        if (InventoryPanel)
        {
            UInventoryCellWidget* FoundCell = nullptr;
            UInventoryCellWidget** FoundCellPtr = CellWidgets.FindByPredicate(
                [SlotIndex](UInventoryCellWidget* Cell)
                {
                    return Cell && Cell->IndexInInventory == SlotIndex;
                }
            );

            if (FoundCellPtr) //cell found by index in cell widgets' array 
            {
                FoundCell = *FoundCellPtr; //will pass found cell as return
            }
            else
            {
                for (UInventoryCellWidget* Cell : CellWidgets)
                {
                    if (!Cell->HasItem()) //searching for empty cell
                    {
                        FoundCell = Cell;
                        break;
                    }

                }
            }

            if (FoundCell) //writing into found cell (by index or first free one)
            {
                return FoundCell->AddItem(InSlot, ItemInfo);
            }

        }
    }
        return false;

};
