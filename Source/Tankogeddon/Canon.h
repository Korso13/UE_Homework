// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "Projectile.h"
#include "Tank.h"
#include "GameStructs.h"
#include "Canon.generated.h"


class AProjectile;
class UArrowComponent;

struct FProjPool
{
	//GENERATED_BODY()
	bool IsFree;
	AProjectile* Projectile;
};


UCLASS()
class TANKOGEDDON_API ACanon : public AActor
{
	GENERATED_BODY()
public:
	//meshes
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	USceneComponent* sceenecmp;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	UStaticMeshComponent* CanonMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	UArrowComponent* ProjectileSpawnPoint;

protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
		CanonType Type;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
		float FireRate = 1;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
		float RefireSpeed = 0.5f;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
		float EffectiveRange = 1000;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
		float LaserRange = 1300;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
		float Damage = 1;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
		int32 StartingAmmo = 5;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
		int32 AmmoPrimaryConsumption = 1;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
		int32 AmmoSecondaryConsumption = 1;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Components")
	TSubclassOf<AProjectile> AmmoType;

	FProjPool Pool[20];

private:
	int32 Ammo = StartingAmmo;
	FTimerHandle ReloadTimer;
	FTimerHandle RefireTimer;
	FTimerHandle RefireCD;
	bool ReadyToFire = true;

public:	
	// Sets default values for this actor's properties
	ACanon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool IsReadyToFire() const {return ReadyToFire;}

	void Reload() { ReadyToFire = true; }

	void Refire();

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void Fire(FireType att_type);

	UFUNCTION()
		void AddAmmo(int32 Count);

	UFUNCTION()
		int32 GetCurrAmmo() const;

	UFUNCTION()
		void SetCurrAmmo(int32 Count);

	UFUNCTION()
		void ResetAmmo() { Ammo = StartingAmmo; };


};
