// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryStructs.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

UCLASS( ClassGroup="Inventory", meta=(BlueprintSpawnableComponent) )
class TANKOGEDDON_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TMap<int32, FInventorySlotInfo> InventoryContents;

public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Getters:
	UFUNCTION(BlueprintCallable)
	int32 GetNanites() const { return GetItem(-1)->ItemCount; }

	FORCEINLINE const FInventorySlotInfo* GetItem(int32 SlotIndex) const { return InventoryContents.Find(SlotIndex);}

	FORCEINLINE const TMap<int32, FInventorySlotInfo>& GetInventory() const { return InventoryContents;}

	FORCEINLINE int32 GetInventorySize() const {return InventoryContents.Num();}

	//Setters:

	virtual void SetItem(int32 SlotIndex, const FInventorySlotInfo& InItem);

	//void(UInventoryComponent::*SetterPtr)(int32, const FInventorySlotInfo&) = SetItem;

	//virtual void SetItem(int32 SlotIndex, const FInventorySlotInfo& InItem);

	virtual void ClearItem(int32 SlotIndex);

	virtual void SwitchItems(); //TBD!!!
};
