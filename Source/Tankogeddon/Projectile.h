// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageTaker.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class ACanon;

UCLASS()
class TANKOGEDDON_API AProjectile : public AActor
{
	GENERATED_BODY()

	//DECLARE_DELEGATE_OneParam(FOnScoredKill, FScoredKillData);

public: 
	//meshes and components
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = Components)
		UBoxComponent* Collisions;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = Components)
		UStaticMeshComponent* ProjectileMesh;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = Components)
		UStaticMeshComponent* ProjectileMesh2;

	//properties
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = Projectile)
		float ProjectileSpeed = 700;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = Projectile)
		float FlightRange = 2000;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = Projectile)
		float Damage = 1;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = Projectile)
		float HitImpulse = 1000;

	//explosive payload settings and components
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Projectile|Explosives")
	bool ExplodesOnImpact = false;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Projectile|Explosives")
	float ExplosionRadius = 200;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SFX")
	UParticleSystemComponent* HitExplosion;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SFX")
	UAudioComponent* HitExplosionSound;

protected:
	FVector LaunchPointVector;

	UPROPERTY()
	ACanon* LaunchingCanon;
public:	
	// Sets default values for this actor's properties
	AProjectile();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void DeferredDestruction();

	void GetAOEHits(TArray<FHitResult>& HitResults, const FVector HitLocation);

	void DealDamage(AActor* Actor, IDamageTaker* Damageable);

	void ApplyImpact(UPrimitiveComponent* PhysicsComponent, const FHitResult &SweepResult);

protected:
	UFUNCTION()
	virtual void OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
};
