// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "TankWithInventory.generated.h"

/**
 * 
 */

class UInventoryComponent;
class UInventoryManagerComponent;

UCLASS()
class TANKOGEDDON_API ATankWithInventory : public ATank
{
	GENERATED_BODY()

public:
	ATankWithInventory();
	
protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UInventoryComponent* Inventory; 

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UInventoryManagerComponent* InventoryManager;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION()
	void ToggleInventoryWidget() const;

	UFUNCTION(BlueprintCallable)
	void SetNanites(int32 InCount);
};
