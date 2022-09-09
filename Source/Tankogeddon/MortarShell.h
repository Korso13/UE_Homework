// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "MortarShell.generated.h"

/**
 * 
 */
UCLASS()
class TANKOGEDDON_API AMortarShell : public AProjectile
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = Components)
		UProjectileMovementComponent* ProjectileMovement;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SFX")
		UParticleSystemComponent* TrailParticles;

	bool ExplodesOnImpact = true;

	//UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SFX")
	//	UParticleSystemComponent* HitExplosion;
	//UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SFX")
	//	UAudioComponent* HitExplosionSound;


	//UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Projectile")
	//	float ExplosionRadius = 200;

protected:
	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	virtual void OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

public:
	AMortarShell();

};
