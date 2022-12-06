// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "Projectile.h"
#include "GameStructs.h"
#include "Canon.generated.h"


class ABase_Pawn;
class AProjectile;
class UArrowComponent;

USTRUCT()
struct FProjPool
{
	GENERATED_BODY()
	bool IsFree;
	TWeakObjectPtr<AProjectile> Projectile;
};

#define COLLISION_LASER ECC_GameTraceChannel1

UCLASS()
class TANKOGEDDON_API ACanon : public AActor
{
	GENERATED_BODY()
public:
	//meshes and components
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	UStaticMeshComponent* Base;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	UStaticMeshComponent* CanonMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	UArrowComponent* ProjectileSpawnPoint;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SFX")
	UParticleSystemComponent* ParticleEffect;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SFX")
	UAudioComponent* AudioEffect;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SFX")
	UForceFeedbackEffect* FeedbackEffect;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SFX")
	TSubclassOf<UCameraShakeBase> CameraShake;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cannon Type|Angle")
	bool AngleTargetingNeeded = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cannon Type|Angle")
	float BaseAngle;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cannon Type|Angle")
	float MaxFiringAngle = 27.4; //1500 firing distance under 1200 speed and 10kg and normal gravity
	float ExtraAngle = 0;
	float CurrentPitchAngle = 0;
protected:

	//Basic canon firing type
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
		CanonType Type;

	//firing properties
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
		float FireRate = 1;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
		float RefireSpeed = 0.5f; //used in secondary attack
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
		float EffectiveRange = 1000;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
		float LaserRange = 1300;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
		float Damage = 1;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
		float LaserDamage = 1;

	//ammo settings
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
		int32 StartingAmmo = 20;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
		int32 AmmoPrimaryConsumption = 1;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
		int32 AmmoSecondaryConsumption = 2;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
	TSubclassOf<AProjectile> AmmoType;


	UPROPERTY()
	TArray<FProjPool> Pool;
	UPROPERTY()
	ABase_Pawn* Pawn;
private:
	int32 Ammo = StartingAmmo;
	FTimerHandle ReloadTimer;
	FTimerHandle RefireTimer;
	FTimerHandle RefireCD;
	FTimerHandle AngleTargetingTimer;
	bool ReadyToFire = true;

public:	
	// Sets default values for this actor's properties
	ACanon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	void Reload() { ReadyToFire = true; }

	void Refire();

	virtual void Destroyed() override;

	UFUNCTION()
	void AngleTargeting();
public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	bool IsReadyToFire() const {return ReadyToFire;}

	UFUNCTION()
	bool Fire(FireType att_type);

	UFUNCTION()
	void AddAmmo(int32 Count);

	UFUNCTION(BlueprintCallable)
	int32 GetCurrAmmo() const;

	int32 GetAmmoComsumption() const { return AmmoPrimaryConsumption; };

	int32 GetAltFireAmmoComsumption() const { return AmmoSecondaryConsumption; };

	UFUNCTION()
		void SetCurrAmmo(int32 Count);

	UFUNCTION()
		void ResetAmmo() { Ammo = StartingAmmo; };

	TSubclassOf<AProjectile> GetAmmoType() const { return AmmoType; };
};
