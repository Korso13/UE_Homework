// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/Engine.h"
#include "Canon.h"

// Sets default values
ACanon::ACanon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//setting up meshes
	sceenecmp = CreateDefaultSubobject<USceneComponent>("Scene CMP");
	RootComponent = sceenecmp;
	CanonMesh = CreateDefaultSubobject<UStaticMeshComponent>("Cannon mesh");
	CanonMesh->SetupAttachment(RootComponent);
	ProjectileSpawnPoint = CreateDefaultSubobject<UArrowComponent>("Projectile spawn point");
	ProjectileSpawnPoint->SetupAttachment(CanonMesh);
}

// Called when the game starts or when spawned
void ACanon::BeginPlay()
{
	Super::BeginPlay();
	
	Reload();
}

void ACanon::Fire(FireType att_type)
{
	if (!IsReadyToFire())
	{
		return;
	}
	if (Ammo <= 0)
	{
		return;
	}
	//firing
	ReadyToFire = false;
	switch (Type)
	{
	case(CanonType::ProjectileCanon):
		{
		if (att_type == FireType::Primary)
		{
			GEngine->AddOnScreenDebugMessage(10, 1, FColor::Red, "Firing projectile");
			Ammo--;
		}
		else
		{
			GetWorld()->GetTimerManager().SetTimer(RefireTimer, this, &ACanon::Refire, RefireSpeed, true);
			//ending RefireTimer
			FTimerDelegate Delegate;
			Delegate.BindLambda([&]() {GetWorld()->GetTimerManager().ClearTimer(RefireTimer); });
			GetWorld()->GetTimerManager().SetTimer(RefireCD, Delegate, 0.5f * 3, false);
			Ammo--;
		}
		break;
		}

	case(CanonType::LaserCanon):
		{
		if (att_type == FireType::Primary)
		{
			GEngine->AddOnScreenDebugMessage(10, 1, FColor::Red, "Firing laser");
			Ammo--;
		}
		else
		{
			GetWorld()->GetTimerManager().SetTimer(RefireTimer, this, &ACanon::Refire, RefireSpeed, true);
			//ending RefireTimer
			FTimerDelegate Delegate;
			Delegate.BindLambda([&]() {GetWorld()->GetTimerManager().ClearTimer(RefireTimer); });
			GetWorld()->GetTimerManager().SetTimer(RefireCD, Delegate, 0.5f * 3, false);
			Ammo--;
		}
		break;
		}

	default:
		break;
	}
	//seting up reload timer:
	GetWorld()->GetTimerManager().SetTimer(ReloadTimer, this, &ACanon::Reload, FireRate, false);
}

void ACanon::Refire()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Firing alternate fire");
}



