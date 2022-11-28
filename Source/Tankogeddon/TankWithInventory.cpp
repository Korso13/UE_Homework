// Fill out your copyright notice in the Description page of Project Settings.


#include "TankWithInventory.h"
#include "InventoryComponent.h"
#include "InventoryManagerComponent.h"

ATankWithInventory::ATankWithInventory()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Inventory = CreateDefaultSubobject<UInventoryComponent>("Inventory Component");
	InventoryManager = CreateDefaultSubobject<UInventoryManagerComponent>("Inventory Manager Component");
}

void ATankWithInventory::ToggleInventoryWidget() const
{
	InventoryManager->ToggleInventoryWindow();
}

void ATankWithInventory::SetNanites(int32 InCount)
{
	if (InventoryManager)
		InventoryManager->SetNanites(InCount);
}

// Called when the game starts or when spawned
void ATankWithInventory::BeginPlay()
{
	Super::BeginPlay();

	if (InventoryManager)
	{
		InventoryManager->Init(Inventory);
	}
}
