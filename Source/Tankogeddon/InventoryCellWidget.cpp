// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryCellWidget.h"
#include "InventoryWidget.h"
//#include "InventoryStructs.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include <Tankogeddon/InventoryComponent.h>


FReply UInventoryCellWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    if (bCanDrag && HasItem() && InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
    {
        return UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent, this, EKeys::LeftMouseButton).NativeReply;
    }
    else
        return FReply::Handled();
}

void UInventoryCellWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation)
{
    OutOperation = UWidgetBlueprintLibrary::CreateDragDropOperation(UDragDropOperation::StaticClass());
    if (OutOperation)
    {
        OutOperation->DefaultDragVisual = this; //might be replaced in future with CreateWidget, but requires extra method for CellWidget to recieve icon image and text outside AddItem()
    }
    else
        Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);
}

bool UInventoryCellWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InMouseEvent, UDragDropOperation* InOperation)
{
    if (InOperation
        && InOperation->DefaultDragVisual
        && InOperation->DefaultDragVisual != this)
    {
        if (auto* FromCell = Cast<UInventoryCellWidget>(InOperation->DefaultDragVisual))
        {
            OnItemDrop.Broadcast(FromCell, this);
            return true;
        }
    }
    return Super::NativeOnDrop(InGeometry, InMouseEvent, InOperation);
}

UInventoryComponent* UInventoryCellWidget::GetParentInventory() const
{
    return ParentInventoryWidget ? ParentInventoryWidget->ParentInventory : nullptr;
};

void UInventoryCellWidget::Clear()
{
    if (!bHasItem)
        return;

    if (ItemIcon && ItemCountText)
    {
        ItemIcon->SetVisibility(ESlateVisibility::Collapsed);
        ItemCountText->SetVisibility(ESlateVisibility::Collapsed);
    }

    bHasItem = false;
    bCanDrag = false;
    Item = {};
}

bool UInventoryCellWidget::AddItem(const FInventorySlotInfo& InSlot, const FInventoryItemInfo& Info)
{
    if (!bHasItem && ItemIcon && ItemCountText)
    {
        ItemIcon->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
        if(!Info.Icon.IsNull())
            ItemIcon->SetBrushFromTexture(Info.Icon.LoadSynchronous());
        if (InSlot.ItemCount > 0)
         ItemCountText->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
        else
            ItemCountText->SetVisibility(ESlateVisibility::Collapsed);
        ItemCountText->SetText(FText::FromString(FString::FromInt(InSlot.ItemCount)));

        if (InSlot.ItemCount < 0)
        {
            bHasItem = false;
            bCanDrag = false;
        }
        else
        {
            bHasItem = true;
            bCanDrag = true;
        }
        Item = InSlot;
        return true;
    }

    return false;
}

void UInventoryCellWidget::OmmitTextBlock()
{
    ItemCountText->SetVisibility(ESlateVisibility::Collapsed);
}

