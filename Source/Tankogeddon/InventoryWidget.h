// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InventoryStructs.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"


class UUniformGridPanel;
class UInventoryComponent;
class UInventoryCellWidget;
class UButton;
class UInventoryManagerComponent;

/**
 * 
 */
UCLASS(Abstract)
class TANKOGEDDON_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	UUniformGridPanel* InventoryPanel;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	UInventoryCellWidget* NanitesSlot;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	UButton* CloseWindowButton;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	TSubclassOf<UInventoryCellWidget> CellWidgetClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	int32 ItemsInRow = 4;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings||Cells")
	TArray<UInventoryCellWidget*> CellWidgets;

	void OnItemDropFunc(UInventoryCellWidget* From, UInventoryCellWidget* To) const;

	UInventoryCellWidget* CreateCell();

	void InitCell(UInventoryCellWidget* NewCell);

public:
	FOnItemDrop OnItemDrop;

	UPROPERTY()
	UInventoryManagerComponent* InventoryManager;

	UPROPERTY()
	UInventoryComponent* ParentInventory;

	void Init(int32 InventorySize);

	bool AddItem(const FInventorySlotInfo& InSlot, const FInventoryItemInfo& ItemInfo, int32 SlotIndex);
};
