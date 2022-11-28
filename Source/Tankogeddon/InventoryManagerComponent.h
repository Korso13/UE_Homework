// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "InventoryStructs.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryManagerComponent.generated.h"

class UDataTable;
class UInventoryComponent;
class UInventoryWidget;
class UInventoryCellWidget;
struct FInventoryItemInfo;
//struct FInventorySlotInfo;
class UDataTable;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKOGEDDON_API UInventoryManagerComponent : public UActorComponent
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

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MinInventorySize = 20;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UInventoryWidget> InventoryWidgetClass;

	UPROPERTY()
	UInventoryWidget* InventoryWidget;

	void OnItemDropFunc(UInventoryCellWidget* From, UInventoryCellWidget* To);

public:	
	// Called every frame
	/*virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;*/
	UFUNCTION(BlueprintCallable)
	void SetNanites(int32 InCount);

	const FInventoryItemInfo* GetItemData(const FName& InID) const;

	void Init(UInventoryComponent* InInventory);

	void ToggleInventoryWindow() const;

	UFUNCTION(BlueprintCallable)
	int32 GetNanites() const;
};
