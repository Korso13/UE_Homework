// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"
#include "Tank.h"
/*#include "Components/AudioComponent.h"
#include "Components/BoxComponent.h"
#include "EnemyTankAIController.h"
#include "Projectile.h"*/
#include "Canon.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "DrawDebugHelpers.h"
#include "TankSaveGame.h"
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
		Cannon->SetCurrAmmo(TurretAmmo);
		DetectionSphere->OnComponentBeginOverlap.AddDynamic(this, &ATurret::OnBeginOverlap);
		DetectionSphere->OnComponentEndOverlap.AddDynamic(this, &ATurret::OnDetectionSphereEndOverlap);
	}

	GetWorld()->GetTimerManager().SetTimer(TargetingTimer, this, &ATurret::Targeting, TargetingUpdateRate, true);

	RegisterOnSaveFile();
}

void ATurret::RegisterOnSaveFile()
{
	ABase_Pawn::RegisterOnSaveFile();

	if(PawnState)
	{
		PawnState->PawnClass = GetClass();
		PawnState->PawnAmmoPrimary = 100;
	}
}

void ATurret::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == this || OtherActor == GetInstigator() || OtherActor == nullptr)
	{
		return;
	}
	//if (!OtherActor->IsA<APawn>())
	if (OtherActor->GetClass() != TargetType)
	{
		return;
	}
	Targets.Add(OtherActor);
	FindBestTarget();
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CanFire() && Cannon)
	{
		if(IsVisible(CurrentTarget) || Cannon->AngleTargetingNeeded)
		{
			Cannon->Fire(FireType::Primary);
			if(PawnState)
				PawnState->PawnAmmoPrimary = Cannon->GetCurrAmmo();
		}
	}
}

void ATurret::Targeting()
{
	if ((CurrentTarget.IsValid() && IsVisible(CurrentTarget)) || (CurrentTarget.IsValid() && Cannon->AngleTargetingNeeded))
	{
		FRotator TargetingRotation = UKismetMathLibrary::FindLookAtRotation(TurretMesh->GetComponentLocation(), CurrentTarget->GetActorLocation());
		FRotator TurretRotation = TurretMesh->GetComponentRotation();
		TargetingRotation.Pitch = TurretRotation.Pitch;
		TargetingRotation.Roll = TurretRotation.Roll;
		TurretMesh->SetWorldRotation(FMath::Lerp(TurretRotation, TargetingRotation, TurretRotationLerpKey));

		if(Cannon->AngleTargetingNeeded)
		{
			float dist = FVector::DistXY(CurrentTarget->GetActorLocation(), GetActorLocation());

			FVector TargetingSpot(GetActorLocation() + TurretMesh->GetForwardVector()*dist);
			TargetingSpot.Z = -10;
			DrawDebugSphere(GetWorld(), TargetingSpot, 32, 30, FColor::Red, false, -1, 1, 3);

			float TargetingAngleOffset = (dist-655) / 25 - 6.4; //(dist - 655)/25 - 6.4 = ExtraAngle with mass 10kg and speed 1200 under normal gravity
			if (TargetingAngleOffset < 0 || TargetingAngleOffset > Cannon->MaxFiringAngle)
				Cannon->ExtraAngle = 0;
			else
				Cannon->ExtraAngle = TargetingAngleOffset;
		}
	}
}

bool ATurret::CanFire()
{
	if (CurrentTarget.IsValid() && Cannon)
	{
		if (IsVisible(CurrentTarget) || Cannon->AngleTargetingNeeded)
		{
			if(FVector::DistXY(CurrentTarget->GetActorLocation(), GetActorLocation()) <= DetectionSphere->GetScaledSphereRadius())
			{
				FRotator TargetingRotation = UKismetMathLibrary::FindLookAtRotation(CanonMountingPoint->GetComponentLocation(), CurrentTarget->GetActorLocation());
				FRotator TurretRotation = CanonMountingPoint->GetComponentRotation();

				if (FMath::Abs(TargetingRotation.Yaw - TurretRotation.Yaw) <= Accuracy)
				{
					return true;
				}
			}
		}
	}

	return false;
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

//int32 ATurret::GetScore() const
//{
//	return ScoreValue;
//}
