// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
		UBoxComponent* Collisions;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
		UStaticMeshComponent* ProjectileMesh;

	//properties
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = Projectile)
		float ProjectileSpeed = 700;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = Projectile)
		float FlightRange = 2000;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = Projectile)
		float Damage = 1;

	//IScorable::FOnScoredKill OnScoredKill;

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

private:
	UFUNCTION()
	void OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
