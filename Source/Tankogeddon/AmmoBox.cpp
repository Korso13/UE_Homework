// Fill out your copyright notice in the Description page of Project Settings.

#include "AmmoBox.h"
#include "Tank.h"

// Sets default values
AAmmoBox::AAmmoBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box's Collision"));
	RootComponent = Collision;
	Collision->SetCollisionProfileName("Pickups");
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AAmmoBox::OnBeginOverlap);

	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ammo Box Body"));
	BoxMesh->SetupAttachment(Collision);
}

// Called when the game starts or when spawned
void AAmmoBox::BeginPlay()
{
	Super::BeginPlay();
	
}


void AAmmoBox::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const
	FHitResult& SweepResult)
{
	auto const Tank = Cast<ATank>(OtherActor);
	if(Tank)
	{
		auto const Cannon = Tank->GetCannon();
		if(Cannon)
		{
			Cannon->AddAmmo(AmmoRefillCount);
			Destroy();
		}
	}
}

// Called every frame
//void AAmmoBox::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

