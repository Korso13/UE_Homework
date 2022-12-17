// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"
#include "InventoryComponent.h"
#include "InventoryManagerComponent.h"
#include "InventoryCellWidget.h"
#include "Components/UniformGridPanel.h"


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
        FInventorySlotInfo SlotInfo;
        
        if (CellWidgets.Num() == InventorySize)
        {
            int32 i = 0;
            for (auto* Cell : CellWidgets)
            {
                if (ParentInventory->GetInventory().Find(i))
                    SlotInfo = *ParentInventory->GetInventory().Find(i);
                else
                    SlotInfo = FInventorySlotInfo();
                const FInventoryItemInfo* InitItemInfo1 = InventoryManager->GetItemData(SlotInfo.ItemId);
                if (InitItemInfo1 != nullptr)
                {
                    CellWidgets[i]->Clear();
                    CellWidgets[i]->AddItem(SlotInfo, *InitItemInfo1);
                    CellWidgets[i]->IndexInInventory = i;
                }
                i++;
            }
        }
        else
        {
            for (size_t i = 0; i < FMath::Min(CellWidgets.Num(), InventorySize); i++)
            {
                if (ParentInventory->GetInventory().Find(i))
                    SlotInfo = *ParentInventory->GetInventory().Find(i);
                else
                    SlotInfo = FInventorySlotInfo();
                const FInventoryItemInfo* InitItemInfo2 = InventoryManager->GetItemData(SlotInfo.ItemId);
                if (InitItemInfo2 != nullptr)
                {
                    CellWidgets[i]->Clear();
                    CellWidgets[i]->AddItem(SlotInfo, *InitItemInfo2);
                    CellWidgets[i]->IndexInInventory = i;
                }
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
