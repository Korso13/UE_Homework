// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Canon.h"
#include "Projectile.h"
#include "DamageTaker.h"
#include "HealthComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Scorable.h"
#include "GameFramework/Pawn.h"
#include "Base_Pawn.generated.h"

class UStaticMeshComponent;
class UBoxComponent;
class ACanon;

UCLASS()
class TANKOGEDDON_API ABase_Pawn : public APawn, public IDamageTaker, public IScorable
{
	GENERATED_BODY()

	//DECLARE_EVENT_OneParam(ABase_Pawn, FOnScoredKill, FScoredKillData);


public:
	//meshes and components
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UBoxComponent* Collision;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UStaticMeshComponent* BodyMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UStaticMeshComponent* TurretMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UArrowComponent* CanonMountingPoint;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UHealthComponent* HealthComponent;

	//movement settings
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Motion|Turret Rotation Speed")
	float TurretRotationLerpKey = 0.1f;

	FOnScoredKill OnScoredKill;

protected:
	UPROPERTY()
		ACanon* Cannon;


public:
	// Sets default values for this pawn's properties
	ABase_Pawn();

	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Destroyed() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Scoring")
		int32 ScoreValue = 0;

	int32 TotalScore = 0;

protected:
	virtual void OnDeath();
	//virtual void OnDamage(FDamageInfo Damage);

	UFUNCTION()
	virtual void ScoredKill(FScoredKillData KillData);

public:	

	virtual void TakeDamage(FDamageInfo DamageData) override;

	virtual int32 GetScore() const override;

};
