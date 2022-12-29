// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyTankAIController.h"
#include "Tank.h"
#include "Canon.h"
#include "Components/ArrowComponent.h"
#include "TankSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

void AEnemyTankAIController::OnPossess(APawn* InTankPawn)
{
	Super::OnPossess(InTankPawn);

	if(TankPawn)
	{
		TankPawn->OnTargetsChanged.Remove(TargetChangedDelegate);
	}

	TankPawn = Cast<ATank>(InTankPawn);
	if(TankPawn)
	{
		PatrollingPointTag = TankPawn->PatrollingPointTag;
	}
	RebuildWaypoints();

	if(TankPawn)
	{
		TargetChangedDelegate = TankPawn->OnTargetsChanged.AddUObject(this, &AEnemyTankAIController::OnTargetsChanged);
	}
}

void AEnemyTankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (CurrentWaypointIndex < 0 || CurrentWaypointIndex >= PatrollingPoints.Num())
	{
		CurrentWaypointIndex = 0;
	}

	if (TankPawn && PatrollingPoints.Num() >= 2)
	{
		TWeakObjectPtr<APatrollingPoint> Waypoint = PatrollingPoints[CurrentWaypointIndex];
		FVector WaypointLocation = Waypoint->GetActorLocation();
		FVector TankLocation = TankPawn->GetActorLocation();

		FVector MovementDirection = WaypointLocation - TankLocation;
		MovementDirection.Normalize();
		float TankForwardMovementAngle = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(TankPawn->GetActorForwardVector(), MovementDirection)));
		float TankRightAngle = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(TankPawn->GetActorRightVector(), MovementDirection)));

		float RotationToWaypoint = 0;
		if (TankForwardMovementAngle > 5)
			RotationToWaypoint = 1;
		if (TankRightAngle > 90)
			RotationToWaypoint = -RotationToWaypoint;
		TankPawn->RotateRight(RotationToWaypoint);

		if (TankForwardMovementAngle > 45)
			TankPawn->MoveForward(0);
		else
			TankPawn->MoveForward(1);


		//reached current waypoint check
		if (FVector::Dist2D(WaypointLocation, TankLocation) <= MovementAccuracy)
		{
			CurrentWaypointIndex++;
		}

		TankPawn->PawnState.PawnCurrentWaypointIndex = CurrentWaypointIndex;
	}

	if (CanFire())
		TankPawn->PrimaryFire();
}

void AEnemyTankAIController::BeginPlay()
{
	Super::BeginPlay();

	RebuildWaypoints();
}

void AEnemyTankAIController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);


}

void AEnemyTankAIController::RebuildWaypoints()
{
	//harvesting all patrolling points with pre-set tag for this AI pawn
	PatrollingPoints.Empty();
	CurrentWaypointIndex = 0;
	TArray<AActor*> HarvestedPoints;
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), APatrollingPoint::StaticClass(), PatrollingPointTag, HarvestedPoints);

	if(HarvestedPoints.Num() == 0)
	{
		return;
	}

	//need temporary storage for sorting via predicate
	TArray<APatrollingPoint*> TempPoints;
	for(const auto point :HarvestedPoints)
	{
		//CastChecked does not check validity of received class for casting - faster
		TempPoints.Add(CastChecked<APatrollingPoint>(point));
	}

	//sorting obtained waypoints by index
	if(TempPoints.Num() > 1)
		TempPoints.Sort([](const APatrollingPoint& A, const APatrollingPoint& B) {return A.Index < B.Index; });

	//adding them to patrolling path array
	for (const auto point : TempPoints)
	{
		PatrollingPoints.Add(point);
	}
}

void AEnemyTankAIController::FindBestTarget()
{
	if (!TankPawn)
		return;

	float MinRotation = 360;
	float MinDistance = 1000000000;
	TWeakObjectPtr<AActor> BestTarget;
	FVector const TurretLocation = TankPawn->GetActorLocation();
	FVector const TurretRotation = TankPawn->GetActorForwardVector();

	for (auto const Target : TankPawn->GetPossibleTargets())
	{
		if (Target.IsValid())
		{
			FVector TargetingVector = Target->GetActorLocation() - TurretLocation;
			TargetingVector.Normalize();
			float AimRotation = FMath::RadiansToDegrees(FVector::DotProduct(TurretRotation, TargetingVector));
			if (AimRotation < MinRotation && (MinRotation - AimRotation) < 15) //checking if rotation to Target is better than for the current best target
			{
				float const Distance = FVector::DistXY(TurretLocation, Target->GetActorLocation());
				if (Distance < MinDistance && IsVisible(Target)) //checking if Target is closer than current Best target + visibility check
				{
					MinDistance = Distance;
					MinRotation = AimRotation;
					BestTarget = Target;
				}
			}
			else if(IsVisible(Target)) //check IsVisible!
			{
				float const Distance = FVector::DistXY(TurretLocation, Target->GetActorLocation());
				MinDistance = Distance;
				MinRotation = AimRotation;
				BestTarget = Target;
			}
		}
	}

	if (BestTarget.IsValid())
	{
		CurrentTarget = BestTarget;
		TankPawn->CurrentTarget = CurrentTarget;
	}
	else
		CurrentTarget = nullptr;
}

bool AEnemyTankAIController::CanFire()
{
	if (!TankPawn)
		return false;

	if (CurrentTarget.IsValid() && TankPawn->Cannon)
	{
		FRotator TargetingRotation = UKismetMathLibrary::FindLookAtRotation(TankPawn->CanonMountingPoint->GetComponentLocation(), CurrentTarget->GetActorLocation());
		FRotator TurretRotation = TankPawn->CanonMountingPoint->GetComponentRotation();

		if (FMath::Abs(TargetingRotation.Yaw - TurretRotation.Yaw) <= TankPawn->Accuracy && IsVisible(CurrentTarget))
		{
				return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool AEnemyTankAIController::IsVisible(TWeakObjectPtr<AActor> InCurrentTarget) const
{
	FHitResult HitResult;
	FCollisionQueryParams CollParams;
	CollParams.AddIgnoredActor(TankPawn);
	CollParams.AddIgnoredActor(GetInstigator());
	CollParams.bTraceComplex = true;
	CollParams.bReturnPhysicalMaterial = false;
	CollParams.TraceTag = FName(TEXT("VisibilityTracer"));
	FVector start = TankPawn->Cannon->ProjectileSpawnPoint->GetComponentLocation();
	FVector end = InCurrentTarget->GetActorLocation();

	//drawing tracer
	if(GetWorld()->LineTraceSingleByChannel(HitResult, start, end, ECollisionChannel::ECC_Visibility, CollParams))
	{
		if (HitResult.GetActor() == InCurrentTarget)
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

void AEnemyTankAIController::OnTargetsChanged()
{
	if (!TankPawn)
	{
		return;
	}

	FindBestTarget();
}

FVector AEnemyTankAIController::GetTargetLocation() const
{
	if (!TankPawn)
		return FVector::ZeroVector;

	if(CurrentTarget.IsValid())
	{
		return CurrentTarget->GetActorLocation();
	}

	return TankPawn->GetActorLocation() + TankPawn->GetActorForwardVector();
}
