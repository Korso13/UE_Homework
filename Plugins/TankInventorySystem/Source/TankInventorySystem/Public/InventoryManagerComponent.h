// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InventoryStructs.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryManagerComponent.generated.h"

class UDataTable;
class UInventoryComponent;
class UInventoryWidget;
class UInventoryCellWidget;
class UDataTable;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKINVENTORYSYSTEM_API UInventoryManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryManagerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UDataTable* ItemsData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString PathToItemsData = "D:/ItemList.json";

	UPROPERTY()
	FString JSONData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* StartingLoadout;

	UPROPERTY()
	UInventoryComponent* LocalInventory;

	UPROPERTY()
	UInventoryComponent* EquipInventory;

	UPROPERTY()
	UInventoryComponent* ExternalInventory;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MinInventorySize = 20;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UInventoryWidget> InventoryWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UInventoryWidget> EquipWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UInventoryWidget> ChestWidgetClass;

	UPROPERTY()
	UInventoryWidget* InventoryWidget;

	UPROPERTY()
	UInventoryWidget* EquipWidget;

	UPROPERTY()
	UInventoryWidget* ChestWidget;

	void OnItemDropFunc(UInventoryCellWidget* From, UInventoryCellWidget* To);

public:	
	// Called every frame
	/*virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;*/

	FSimpleDelegate OnInventoryChanged;

	FSimpleDelegate OnEquipmentInventoryChanged;

	UFUNCTION(BlueprintCallable)
	void SetNanites(int32 InCount);

	void SetEquipInventory(UInventoryComponent* InInventory);

	const FInventoryItemInfo* GetItemData(const FName& InID) const;

	void Init(UInventoryComponent* InInventory, EInventoryClass InventoryClass);

	void ToggleInventoryWindow() const;

	void ToggleEquipmentWindow();

	bool IsInventoryOpen() const;

	void UpdateEquipWidget();

	UFUNCTION(BlueprintCallable)
	void CloseContainer();

	UFUNCTION(BlueprintCallable)
	int32 GetNanites() const;

	void PickupAddItem(FInventorySlotInfo& InSlot);

	FORCEINLINE UInventoryComponent* GetLocalInventory() const{return LocalInventory;}

	FORCEINLINE UInventoryComponent* GetEquipInventory() const{return EquipInventory;}

	void LoadInventoriesFromSave(TMap<int32, FInventorySlotInfo> InInventory, TMap<int32, FInventorySlotInfo> InEquipment);
};
