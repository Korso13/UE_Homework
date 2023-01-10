// Fill out your copyright notice in the Description page of Project Settings.


#include "DestructibleWall.h"

// Sets default values
ADestructibleWall::ADestructibleWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Collision = CreateDefaultSubobject<UBoxComponent>("Wall collision");
	RootComponent = Collision;
	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>("Wall mesh");
	BodyMesh->SetupAttachment(RootComponent);
	HealthComponent = CreateDefaultSubobject<UHealthComponent>("Wall health");
	HealthComponent->OnDeath.AddUObject(this, &ADestructibleWall::OnDeath);
}

// Called when the game starts or when spawned
void ADestructibleWall::BeginPlay()
{
	Super::BeginPlay();

}

void ADestructibleWall::OnDeath()
{
	Destroy();
}

float ADestructibleWall::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
}

void ADestructibleWall::TakeDamage(FDamageInfo DamageData)
{
	HealthComponent->TakeDamage(DamageData);
}

float ADestructibleWall::GetHealth() const
{
	return HealthComponent->CurrentHP;
}


// Called every frame
void ADestructibleWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

