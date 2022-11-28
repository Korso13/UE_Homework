// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InventoryStructs.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"


class UUniformGridPanel;
class UInventoryCellWidget;
/**
 * 
 */
UCLASS(Abstract)
class TANKOGEDDON_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UUniformGridPanel* InventoryPanel;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UInventoryCellWidget* NanitesSlot;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	TSubclassOf<UInventoryCellWidget> CellWidgetClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	int32 ItemsInRow = 4;

	UPROPERTY()
	TArray<UInventoryCellWidget*> CellWidgets;

	void OnItemDropFunc(UInventoryCellWidget* From, UInventoryCellWidget* To) const;

	UInventoryCellWidget* CreateCell();

public:
	FOnItemDrop OnItemDrop;

	void Init(int32 InventorySize);

	bool AddItem(const FInventorySlotInfo& InSlot, const FInventoryItemInfo& ItemInfo, int32 SlotIndex);
};
