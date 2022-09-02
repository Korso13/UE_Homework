// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
//#include "Components/PointLightComponent.h"
#include "Tank.h"
#include "Components/SpotLightComponent.h"
#include "GameFramework/Actor.h"
#include "MapLoader.generated.h"

UCLASS()
class TANKOGEDDON_API AMapLoader : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapLoader();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		USceneComponent* SCP;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UBoxComponent* Collision;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UStaticMeshComponent* BodyMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		USpotLightComponent* ActiveLight;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		USpotLightComponent* InactiveLight;
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Status")
	bool IsActive = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		FName TargetLevelName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		TSubclassOf<ATank> AllowedPawn;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Activation|Destruction")
		bool IsTargetDestructionNeeded = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Activation|Scoring")
		bool IsTargetScoreGoalNeeded = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Activation|Scoring")
		int32 ScoreRequiredToWin = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Activation|Destruction")
		FName DestructionTargetTag;
private:
	UFUNCTION()
		virtual void OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void StatusCheck();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetActive(bool Active);
};
