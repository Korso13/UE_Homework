// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ControllerTargeting.h"
#include "PatrollingPoint.h"
#include "EnemyTankAIController.generated.h"

/**
 * 
 */

class ATank;

UCLASS()
class TANKOGEDDON_API AEnemyTankAIController : public AAIController, public IControllerTargeting
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Patrolling")
		FName PatrollingPointTag;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Patrolling")
		float MovementAccuracy = 10;

private:
	TArray<TWeakObjectPtr<APatrollingPoint>> PatrollingPoints;
	UPROPERTY()
	ATank* TankPawn;

	TWeakObjectPtr<AActor> CurrentTarget;

protected:
	virtual void OnPossess(APawn* InTankPawn) override;

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void RebuildWaypoints();

	int32 CurrentWaypointIndex = 0;

	void FindBestTarget();

	bool CanFire();

	bool IsVisible(TWeakObjectPtr<AActor> CurrentTarget) const;

	void OnTargetsChanged();

	FDelegateHandle TargetChangedDelegate;
public:
	virtual FVector GetTargetLocation() const override;
};
