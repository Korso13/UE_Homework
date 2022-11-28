// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterWithInventory.h"
#include "InventoryComponent.h"
#include "InventoryManagerComponent.h"

// Sets default values
ACharacterWithInventory::ACharacterWithInventory()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Inventory = CreateDefaultSubobject<UInventoryComponent>("Inventory Component");
	//InventoryManager = CreateDefaultSubobject<UInventoryManagerComponent>("Inventory Manager Component");
}

// Called when the game starts or when spawned
void ACharacterWithInventory::BeginPlay()
{
	Super::BeginPlay();
	
	//InventoryManager->Init(Inventory);
}

// Called every frame
void ACharacterWithInventory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
//void ACharacterWithInventory::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

