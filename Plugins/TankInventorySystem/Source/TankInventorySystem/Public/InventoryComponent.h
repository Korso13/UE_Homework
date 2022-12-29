// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryStructs.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UInventoryManagerComponent;
UCLASS( ClassGroup="Inventory", meta=(BlueprintSpawnableComponent) )
class TANKINVENTORYSYSTEM_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	/** In inventory component leave this array empty if you use loadouts. In equipment component create values for every equipment slot.
	 * The keys must coincide with IndexInInventory values of equipment slots in widget (and contain appropriate items). Without it the game will crash!!!*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<int32, FInventorySlotInfo> InventoryContents;

public:
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY()
	UInventoryManagerComponent* OwningInventoryManager;
	
	//Getters:
	UFUNCTION(BlueprintCallable)
	int32 GetNanites() const { return GetItem(-1)->ItemCount; }

	FORCEINLINE const FInventorySlotInfo* GetItem(int32 SlotIndex) const { return InventoryContents.Find(SlotIndex);}

	FORCEINLINE const TMap<int32, FInventorySlotInfo>& GetInventory() const { return InventoryContents;}

	virtual void LoadInventory(TMap<int32, FInventorySlotInfo> InInventory); //for save-load mechanic
	
	FORCEINLINE int32 GetInventorySize() const {return InventoryContents.Num();}

	//Setters:

	virtual void SetItem(int32 SlotIndex, const FInventorySlotInfo& InItem);

	virtual void ClearItem(int32 SlotIndex);

	virtual int32 GetMaxItemAmount(int32 SlotIndex, const FInventoryItemInfo& InItem);

	void operator=(TMap<int32, FInventorySlotInfo> InInventory);
};
