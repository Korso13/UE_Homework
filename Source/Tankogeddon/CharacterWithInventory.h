// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterWithInventory.generated.h"

class UInventoryComponent;
class UInventoryManagerComponent;

UCLASS()
class TANKOGEDDON_API ACharacterWithInventory : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterWithInventory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	UInventoryComponent* Inventory;

	UPROPERTY(EditDefaultsOnly)
	UInventoryManagerComponent* InventoryManager;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
