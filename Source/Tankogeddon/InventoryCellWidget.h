// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InventoryStructs.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryCellWidget.generated.h"

/**
 * 
 */
//struct FInventorySlotInfo;
class UImage;
class UTextBlock;
class UInventoryWidget;
class UInventoryComponent;

UCLASS(Abstract)
class TANKOGEDDON_API UInventoryCellWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY()
	bool bHasItem;

	UPROPERTY(EditAnywhere)
	bool bCanDrag;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UImage* ItemIcon;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* ItemCountText;

	UPROPERTY()
	FInventorySlotInfo Item;

	//Drag&Drop functionality
	FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);

	void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation);

	bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InMouseEvent, UDragDropOperation* InOperation);


public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 IndexInInventory = INDEX_NONE;

	FOnItemDrop OnItemDrop;

	UPROPERTY()
	UInventoryWidget* ParentInventoryWidget;

	FORCEINLINE bool HasItem() const { return bHasItem; };
	
	FORCEINLINE const FInventorySlotInfo& GetItem() const { return Item; };

	FORCEINLINE UInventoryComponent* GetParentInventory() const;

	void Clear();

	bool AddItem(const FInventorySlotInfo& InSlot, const FInventoryItemInfo& Info);

	void OmmitTextBlock();
};
