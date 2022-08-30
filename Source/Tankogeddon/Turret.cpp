// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"
#include "Tank.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ATurret::ATurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//DetectionSphere->OnComponentBeginOverlap.AddDynamic(this, &ATurret::OnBeginOverlap);
	//DetectionSphere->OnComponentEndOverlap.AddDynamic(this, &ATurret::OnDetectionSphereEndOverlap);

}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();

	if (CanonClass)
	{
		FActorSpawnParameters spawnParams;
		spawnParams.Instigator = this;
		spawnParams.Owner = this;
		Cannon = GetWorld()->SpawnActor<ACanon>(CanonClass, spawnParams);
		Cannon->AttachToComponent(CanonMountingPoint, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}

	GetWorld()->GetTimerManager().SetTimer(TargetingTimer, this, &ATurret::Targeting, TargetingUpdateRate, true);
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CanFire() && IsVisible(CurrentTarget))
	{
		Cannon->Fire(FireType::Primary);
	}
}

void ATurret::Targeting()
{
	if (CurrentTarget.IsValid() && IsVisible(CurrentTarget))
	{
		FRotator TargetingRotation = UKismetMathLibrary::FindLookAtRotation(TurretMesh->GetComponentLocation(), CurrentTarget->GetActorLocation());
		FRotator TurretRotation = TurretMesh->GetComponentRotation();
		TargetingRotation.Pitch = TurretRotation.Pitch;
		TargetingRotation.Roll = TurretRotation.Roll;
		TurretMesh->SetWorldRotation(FMath::Lerp(TurretRotation, TargetingRotation, TurretRotationLerpKey));
	}
}

bool ATurret::CanFire()
{
	if (CurrentTarget.IsValid() && Cannon)
	{
		FRotator TargetingRotation = UKismetMathLibrary::FindLookAtRotation(CanonMountingPoint->GetComponentLocation(), CurrentTarget->GetActorLocation());
		FRotator TurretRotation = CanonMountingPoint->GetComponentRotation();

		if (FMath::Abs(TargetingRotation.Yaw - TurretRotation.Yaw) <= Accuracy)
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

bool ATurret::IsVisible(TWeakObjectPtr<AActor> InCurrentTarget) const
{
	FHitResult HitResult;
	FCollisionQueryParams CollParams;
	CollParams.AddIgnoredActor(this);
	CollParams.AddIgnoredActor(GetInstigator());
	CollParams.bTraceComplex = true;
	CollParams.bReturnPhysicalMaterial = false;
	CollParams.TraceTag = FName(TEXT("VisibilityTracer"));
	FVector start = Cannon->ProjectileSpawnPoint->GetComponentLocation();
	FVector end = InCurrentTarget->GetActorLocation();

	//drawing tracer
	if (GetWorld()->LineTraceSingleByChannel(HitResult, start, end, ECollisionChannel::ECC_Visibility, CollParams))
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

int32 ATurret::GetScore() const
{
	return ScoreValue;
}


void ATurret::FindBestTarget()
{
	float MinRotation = 360;
	float MinDistance = 1000000000;
	TWeakObjectPtr<AActor> BestTarget;
	FVector const TurretLocation = GetActorLocation();
	FVector const TurretRotation = GetActorForwardVector();

	for (auto const Target : Targets)
	{
		if (Target.IsValid())
		{
			FVector TargetingVector = Target->GetActorLocation() - TurretLocation;
			TargetingVector.Normalize();
			float AimRotation = FMath::RadiansToDegrees(FVector::DotProduct(TurretRotation, TargetingVector));
			if (AimRotation < MinRotation && (MinRotation - AimRotation) < 15)
			{
				float const Distance = FVector::DistXY(TurretLocation, Target->GetActorLocation());
				if (Distance < MinDistance)
				{
					MinDistance = Distance;
					MinRotation = AimRotation;
					BestTarget = Target;
				}
			}
			else
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
	}
}
