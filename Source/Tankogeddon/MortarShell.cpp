// Fill out your copyright notice in the Description page of Project Settings.


#include "MortarShell.h"

#include "Base_Pawn.h"
#include "DamageTaker.h"
#include "Scorable.h"
#include "Components/AudioComponent.h"
#include "Particles/ParticleSystemComponent.h"

void AMortarShell::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

}

AMortarShell::AMortarShell()
{
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile Movement");

	TrailParticles = CreateDefaultSubobject<UParticleSystemComponent>("Trail Particles");
	TrailParticles->SetupAttachment(RootComponent);

	//HitExplosion = CreateDefaultSubobject<UParticleSystemComponent>("Hit Explosion particles");
	//HitExplosion->SetupAttachment(RootComponent);

	//HitExplosionSound = CreateDefaultSubobject<UAudioComponent>("Explosion sound");
	//HitExplosionSound->SetupAttachment(RootComponent);
}

void AMortarShell::NotifyHit(
	UPrimitiveComponent* MyComp, 
	AActor* Other, 
	UPrimitiveComponent* OtherComp,
	bool bSelfMoved, 
	FVector HitLocation, 
	FVector HitNormal, 
	FVector NormalImpulse, 
	const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	if (Other == this || GetInstigator() == Other)
	{
		return;
	}

	if (Other) //checking if hit actor is still alive
	{
		HitExplosion->Activate();
		HitExplosionSound->Play();
		TSet<AActor*> HitActors;
		//checking if AOE payload and registering hit targets
		if (ExplodesOnImpact)
		{
			TArray<FHitResult> HitResults;
			GetAOEHits(HitResults, GetActorLocation());
			for (auto const HitResult : HitResults)
			{
				HitActors.Add(HitResult.GetActor());
			}
		}
		else
		{
			HitActors.Add(Other);
		}

		//dealing damage and impact to all affected actors, if possible
		for (auto const HitActor : HitActors)
		{
			if (!IsValid(HitActor))
			{
				continue;
			}
			IDamageTaker* Damageable = Cast<IDamageTaker>(HitActor);
			if (Damageable)
			{
				DealDamage(HitActor, Damageable);
			}
			else
			{
				UPrimitiveComponent* PhysComp = Cast<UPrimitiveComponent>(HitActor->GetRootComponent());
				if (PhysComp)
				{
					ApplyImpact(PhysComp, Hit);
				}
			}
		}
	}
	//launching deferred projectile destruction for SFX to safely play
	DeferredDestruction();
}

void AMortarShell::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	return;
}
