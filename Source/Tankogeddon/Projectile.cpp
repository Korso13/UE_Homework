// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "Scorable.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collisions = CreateDefaultSubobject<UBoxComponent>("Collision");
	RootComponent = Collisions;
	Collisions->SetCollisionProfileName("Projectile");
	Collisions->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::OnBeginOverlap);

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>("Projectile mesh");
	ProjectileMesh->SetupAttachment(RootComponent);

	LaunchingCanon = Cast<ACanon>(this->GetOwner());
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	LaunchPointVector = GetActorLocation();
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//projectile's movement
	SetActorLocation(GetActorLocation() + GetActorForwardVector() * DeltaTime * ProjectileSpeed);

	if(FVector::DistXY(LaunchPointVector, GetActorLocation()) >= FlightRange)
	{
		Destroy();
	}
}


void AProjectile::OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == this || GetInstigator() == OtherActor)
	{
		return;
	}

	IDamageTaker* Damageable = Cast<IDamageTaker>(OtherActor);
	IScorable* Scoreable = Cast<IScorable>(OtherActor);
	if (Damageable)
	{
		FDamageInfo DamageData;
		DamageData.Instigator = GetInstigator();
		DamageData.DamageDealer = this;
		DamageData.DamageValue = Damage;

		FScoredKillData ScoreData; //need to gather in advance just in case
		if(Scoreable)
		{
			ScoreData.Killer = GetInstigator();
			ScoreData.Killed = OtherActor->GetInstigator();
			ScoreData.ScoreValue = Scoreable->GetScore();
		}

		Damageable->TakeDamage(DamageData);

		if(OtherActor->IsPendingKillPending())
		{
			Cast<ABase_Pawn>(ScoreData.Killer)->OnScoredKill.Broadcast(ScoreData);
		}
	}
	else
	{
		OtherActor->Destroy();
	}
	Destroy();
}
