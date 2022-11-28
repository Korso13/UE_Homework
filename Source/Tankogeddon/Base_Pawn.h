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
#include "Components/SphereComponent.h"
#include "GameFramework/Pawn.h"
#include "Base_Pawn.generated.h"

class UStaticMeshComponent;
class UBoxComponent;
class ACanon;



UCLASS()
class TANKOGEDDON_API ABase_Pawn : public APawn, public IDamageTaker, public IScorable
{
	GENERATED_BODY()

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
		USphereComponent* DetectionSphere;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SFX")
		UParticleSystemComponent* OnDeathParticleEffect;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SFX")
		UAudioComponent* OnDeathAudioEffect;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SFX")
		UParticleSystemComponent* OnHitParticleEffect;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SFX")
		UAudioComponent* OnHitAudioEffect;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SFX")
		UForceFeedbackEffect* OnHitForceFeedback;



	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UHealthComponent* HealthComponent;

	//movement settings
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Motion|Turret Rotation Speed")
	float TurretRotationLerpKey = 0.1f;

	int32 TankSpawnID = -1;

protected:
	UPROPERTY()
	ACanon* Cannon;

	friend class AEnemyTankAIController;
	friend class ATankPlayerController;
	friend class ACanon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Scoring")
	int32 ScoreValue = 0;

	int32 TotalScore = 0;

	bool KilledInAction = false;
	
	TArray<TWeakObjectPtr<AActor>> Targets;

	TWeakObjectPtr<AActor> CurrentTarget;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Targeting")
	TSubclassOf<ABase_Pawn> TargetType;
public:
	// Sets default values for this pawn's properties
	ABase_Pawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Destroyed() override;

	UFUNCTION()
	void DestroyPawn();

	virtual void OnDeath();

	UFUNCTION(BlueprintNativeEvent)
	void OnTakingDamage(FDamageInfo Damage);

	UFUNCTION()
	virtual void ScoredKill(FScoredKillData KillData);

	UFUNCTION()
	virtual void OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	virtual void OnDetectionSphereEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual void FindBestTarget();

	FDelegateHandle OnScoredKillDelegate;

public:	
	virtual void TakeDamage(FDamageInfo DamageData) override;

	virtual int32 GetScore() const override;

	virtual void ResetScoreOnDeath() override { ScoreValue = 0; }

	virtual float GetHealth() const override;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetTotalScore() const;

	UFUNCTION(BlueprintCallable)
	bool IsKIA() const { return KilledInAction; }
};
