// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponBox.h"
#include "Canon.h"
#include "Components/BoxComponent.h"
#include "TankWithInventory.h"

// Sets default values
AWeaponBox::AWeaponBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box's Collision"));
	RootComponent = Collision;
	Collision->SetCollisionProfileName("Pickups");
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AWeaponBox::OnBeginOverlap);

	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon Box Body"));
	BoxMesh->SetupAttachment(Collision);


}

void AWeaponBox::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const
	FHitResult& SweepResult)
{
	if (OtherActor)
	{
		auto const Tank = Cast<ATankWithInventory>(OtherActor);
		if (Tank)
		{
			Tank->PickUpItem(WeaponBoxType);
			Destroy();
			return;
		}
		else
		{
			auto const TankOld = Cast<ATank>(OtherActor);
			if (TankOld)
			{
				TankOld->ChangeCanon(CanonClass);
				Destroy();
			}
		}
	}
}

// Called when the game starts or when spawned
void AWeaponBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
//void AWeaponBox::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

