// Fill out your copyright notice in the Description page of Project Settings.


#include "HPBox.h"
#include "Components/BoxComponent.h"
#include "InventoryManagerComponent.h"
#include "TankWithInventory.h"

AHPBox::AHPBox()
{
	PrimaryActorTick.bCanEverTick = false;

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box's Collision"));
	RootComponent = Collision;
	Collision->SetCollisionProfileName("Pickups");
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AHPBox::OnBeginOverlap);

	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ammo Box Body"));
	BoxMesh->SetupAttachment(Collision);
}

void AHPBox::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		auto const Tank = Cast<ATankWithInventory>(OtherActor);
		if (Tank)
		{
			Tank->PickUpItem(HPBoxType);
			Destroy();
			return;
		}
	}
}

void AHPBox::UseConsumable()
{
	auto const Tank = Cast<ATankWithInventory>(OwningPawn);
	if (Tank)
	{
		Tank->HPTopup(Tank->InventoryManager->GetItemData(HPBoxType.ItemId)->ConsumableRestoreValue);
	}
}
