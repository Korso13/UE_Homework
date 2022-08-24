// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"
#include "Tank.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ATurret::ATurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("TankCollision"));
	RootComponent = Collision;

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tank Body"));
	BodyMesh->SetupAttachment(Collision);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tank Turret"));
	TurretMesh->SetupAttachment(BodyMesh);

	CanonMountingPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("Canon Mounting Point"));
	CanonMountingPoint->AttachToComponent(TurretMesh, FAttachmentTransformRules::KeepRelativeTransform);

	DetectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Detection Sphere"));
	DetectionSphere->SetupAttachment(Collision);
	DetectionSphere->OnComponentBeginOverlap.AddDynamic(this, &ATurret::OnDetectionSphere_BeginOverlap);
	DetectionSphere->OnComponentEndOverlap.AddDynamic(this, &ATurret::OnDetectionSphereEndOverlap);

	HealthComponent = CreateDefaultSubobject<UHealthComponent>("Health Component");
	HealthComponent->OnDeath.AddUObject(this, &ATurret::OnDeath);
	HealthComponent->OnDamage.AddUObject(this, &ATurret::OnDamage);

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

	if (CanFire())
	{
		Cannon->Fire(FireType::Primary);
	}
}

void ATurret::Targeting()
{
	if (CurrentTarget.IsValid())
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

int32 ATurret::GetScore() const
{
	return ScoreValue;
}


void ATurret::OnDetectionSphere_BeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == this || OtherActor == GetInstigator() || OtherActor == nullptr)
	{
		return;
	}
	if (!OtherActor->IsA<ATank>())
	{
		return;
	}
	Targets.Add(OtherActor);
	FindBestTarget();
}

void ATurret::OnDetectionSphereEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == this || OtherActor == GetInstigator() || OtherActor == nullptr)
	{
		return;
	}
	if (!OtherActor->IsA<ATank>())
	{
		return;
	}

	Targets.Remove(OtherActor);
	if (OtherActor == CurrentTarget)
	{
		FindBestTarget();
	}
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

void ATurret::OnDamage(FDamageInfo Damage)
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString::Printf(TEXT("Turret took damage from %s, HP: %f"), ToCStr(Damage.Instigator->GetName()), HealthComponent->CurrentHP));
}
