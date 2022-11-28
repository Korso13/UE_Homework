// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "Canon.h"
#include "Base_Pawn.h"
//#include "Scorable.h"
#include "Components/AudioComponent.h"
#include "Particles/ParticleSystemComponent.h"

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

	ProjectileMesh2 = CreateDefaultSubobject<UStaticMeshComponent>("Projectile mesh part 2");
	ProjectileMesh2->SetupAttachment(ProjectileMesh/*, FAttachmentTransformRules::SnapToTargetIncludingScale*/);

	HitExplosion = CreateDefaultSubobject<UParticleSystemComponent>("Hit Explosion particles");
	HitExplosion->SetupAttachment(RootComponent);

	HitExplosionSound = CreateDefaultSubobject<UAudioComponent>("Explosion sound");
	HitExplosionSound->SetupAttachment(RootComponent);


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

void AProjectile::DeferredDestruction()
{
	ProjectileMesh->SetVisibility(false);
	ProjectileMesh2->SetVisibility(false);
	FTimerHandle DestroyTimer;
	FTimerDelegate DestroyDelegate;
	DisableComponentsSimulatePhysics();
	
	ProjectileSpeed = 0;
	SetActorEnableCollision(false);
	//Damage = 0;
	DestroyDelegate.BindLambda([this]()
		{
			Destroy();
		});
	GetWorld()->GetTimerManager().SetTimer(DestroyTimer, DestroyDelegate, 2, false, -1);
}

//sweep all targets hit by AOE blast
void AProjectile::GetAOEHits(TArray<FHitResult> &HitResults, const FVector HitLocation)
{
	FCollisionQueryParams CollParams;
	CollParams.AddIgnoredActor(this->GetInstigator());
	CollParams.AddIgnoredActor(this);
	CollParams.bTraceComplex = true;
	GetWorld()->SweepMultiByChannel(HitResults, HitLocation, HitLocation + FVector(0.1f), FQuat::Identity, ECollisionChannel::ECC_Visibility, FCollisionShape::MakeSphere(ExplosionRadius), CollParams);
}

//func to deal damage and earn kill score
void AProjectile::DealDamage(AActor* Actor, IDamageTaker* Damageable)
{
	FDamageInfo DamageData;
	DamageData.Instigator = GetInstigator();
	DamageData.DamageDealer = this;
	DamageData.DamageValue = Damage;

	IScorable* Scoreable = Cast<IScorable>(Actor);
	 //need to gather in advance just in case
	ScoreData.ScoreValue = 0;
	
	if (Scoreable)
	{
		ScoreData.Killer = GetInstigator();
		ScoreData.Killed = Actor->GetInstigator();
		ScoreData.ScoreValue = Scoreable->GetScore();
	}

	Damageable->TakeDamage(DamageData);
	
	if (Damageable->GetHealth() <= 0 && (Scoreable))
	{
		Scoreable->ResetScoreOnDeath();
		Cast<ABase_Pawn>(ScoreData.Killer)->OnScoredKill.Broadcast(ScoreData);
	}
}

//apply explosion impact
void AProjectile::ApplyImpact(UPrimitiveComponent* PhysicsComponent, const FHitResult& SweepResult)
{
	if (PhysicsComponent->IsSimulatingPhysics())
	{
		PhysicsComponent->AddImpulseAtLocation(HitImpulse * GetActorForwardVector() * Damage, SweepResult.ImpactPoint);
	}
}



void AProjectile::OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == this || GetInstigator() == OtherActor)
	{
		return;
	}

	if (OtherActor) //checking if hit actor is still alive
	{

		TSet<AActor*> HitActors;
		//checking if AOE payload and registering hit targets
		if(ExplodesOnImpact)
		{
			HitExplosion->Activate();
			HitExplosionSound->Play();
			TArray<FHitResult> HitResults;
			GetAOEHits(HitResults, GetActorLocation());
			for (auto const HitResult : HitResults)
			{
				HitActors.Add(HitResult.GetActor());
			}
		}
		else
		{
			HitActors.Add(OtherActor);
		}

		//dealing damage and impact to all affected actors, if possible
		for (auto const HitActor : HitActors)
		{
			if (!IsValid(HitActor))
			{
				continue;
			}
			IDamageTaker* Damageable = Cast<IDamageTaker>(HitActor);
			if(Damageable)
			{
				DealDamage(HitActor, Damageable);
			}
			else
			{
				UPrimitiveComponent* PhysComp = Cast<UPrimitiveComponent>(HitActor->GetRootComponent());
				if (PhysComp)
				{
					ApplyImpact(PhysComp, SweepResult);
				}
			}
		}
	}
	//launching deferred projectile destruction for SFX to safely play
	DeferredDestruction();
}

void AProjectile::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved,
	FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	DeferredDestruction();
}

