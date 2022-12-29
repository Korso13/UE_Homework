// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageTaker.h"
#include "HealthComponent.h"
#include "Scorable.h"
#include "Tank.h"
#include "TankSaveGame.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "TankFactory.generated.h"

struct FBuildingState;
static int32 TankSpawnID = 0;

UCLASS()
class TANKOGEDDON_API ATankFactory : public AActor, public IDamageTaker, public IScorable
{
	GENERATED_BODY()


public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UStaticMeshComponent* DestroyedBodyMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UBoxComponent* Collision;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UStaticMeshComponent* BodyMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UArrowComponent* SpawnPoint;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UHealthComponent* HealthComponent;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Tank Factory")
	TSubclassOf<ATank> TankClass;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SFX")
		UParticleSystemComponent* OnSpawnParticleEffect;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SFX")
		UAudioComponent* OnSpawnAudioEffect;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SFX")
		UParticleSystemComponent* OnDestructionEffect;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SFX")
		UParticleSystemComponent* PostDestructionPersistentEffect;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SFX")
		UAudioComponent* OnDestructionAudioEffect;



	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Tank Factory")
		bool IsWorkingOnSpawn = true;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Tank Factory|Production")
		bool StaticPatrollingTag = true;
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Tank Factory|Production")
	float SpawnRate = 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Tank Factory|Production")
	int32 MaxSpawns = 3;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Tank Factory")
	int32 ScoreValue = 1000;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Tank Factory|Production|Patrolling Tag(without ID)")
	FString PatrollingPointTag;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Tank Factory")
	class AMapLoader* DepricatedConnectedMapLoader;

	const FString DestroyedMeshPath = "StaticMesh'/Game/CSC/Meshes/SM_TankFactoryDestroyed.SM_TankFactoryDestroyed'";

private:
	FTimerHandle SpawnTimer;

	int32 CurrentPatrollingID = 0;
public:	
	// Sets default values for this actor's properties
	ATankFactory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnDeath();

	UFUNCTION(BlueprintNativeEvent)
	void OnDamage(FDamageInfo Damage);

	UFUNCTION()
		void SFXStop();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void TakeDamage(FDamageInfo DamageData) override;

	virtual float GetHealth() const override;

	virtual int GetScore() const override;

	virtual void ResetScoreOnDeath() override { ScoreValue = 0; }

	UFUNCTION(BlueprintCallable)
	void StartProduction();

	//Save-load functionality functions
	void RegisterOnSaveFile(); //registers building on save file object

	void UpdateBuildingState(); //updates dynamically changing data on save file object

	void LoadState(FBuildingState& InState); //called on GameLoad 

	//UPROPERTY()
	TSharedPtr<FBuildingState> BuildingSaveState /*= *(new FBuildingState())*/;
	
private:
	void OnSpawnTick();
};



