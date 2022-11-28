// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"
#include "InventoryCellWidget.h"
#include "Components/UniformGridPanel.h"


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
		Cell->OnItemDrop.AddUObject(this, &UInventoryWidget::OnItemDropFunc);
		return Cell;
	}
	return nullptr;

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
}

bool UInventoryWidget::AddItem(const FInventorySlotInfo& InSlot, const FInventoryItemInfo& ItemInfo, int32 SlotIndex)
{
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
        return false;
    }

}
