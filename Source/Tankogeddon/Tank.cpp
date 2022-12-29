// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Canon.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/Engine.h"
#include "GameStructs.h"
#include "TankPlayerController.h"
#include "TankSaveGame.h"
#include "EnemyTankAIController.h"

DECLARE_LOG_CATEGORY_EXTERN(TankLog, All, All);
DEFINE_LOG_CATEGORY(TankLog);

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(BodyMesh);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bInheritYaw = false;
	SpringArm->TargetArmLength = 1000;
	SpringArm->bDoCollisionTest = true;

	DetectionSphere->OnComponentBeginOverlap.AddDynamic(this, &ATank::OnBeginOverlap);
	DetectionSphere->OnComponentEndOverlap.AddDynamic(this, &ATank::OnDetectionSphereEndOverlap);

};

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

	TankController = Cast<IControllerTargeting>(GetController());
	CurrentCanonClass = FirstCannon;
	FirstCannonUsed = true;
	SecondCannonUsed = false;
	SetupCanon();
	if(Cannon)
	CannonOne = Cannon;
}

void ATank::RegisterOnSaveFile()
{
	Super::RegisterOnSaveFile();

	if(PawnState.IsValid())
	{
		PawnState->AIPawnPatrollingPointTag = PatrollingPointTag;
		PawnState->PawnCurrentWaypointIndex = Cast<AEnemyTankAIController>(GetController())->GetCurrentWaypointIndex();
	}
}

void ATank::LoadState(FPawnState& InState)
{
	Super::LoadState(InState);

	PatrollingPointTag = PawnState->AIPawnPatrollingPointTag;
	if(auto EnemyAIController = Cast<AEnemyTankAIController>(GetController()))
	{
		EnemyAIController->SetCurrentWaypointIndex(PawnState->PawnCurrentWaypointIndex);
	}
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//forward movement
	CurrentForwardAxisImpulse = FMath::Lerp(CurrentForwardAxisImpulse, ForwardAxisMoveValue, ForwardMovementLerpKey); //interpolating current speed by target speed
	Collision->AddForce(GetActorForwardVector() * MoveSpeed * 10000 * CurrentForwardAxisImpulse);
	//FVector MovePosition = GetActorLocation() + GetActorForwardVector() * MoveSpeed * CurrentForwardAxisImpulse * DeltaTime; //using interpolated forward speed
	//SetActorLocation(MovePosition, true);

	//strafing
	CurrentStrafeAxisImpulse = FMath::Lerp(CurrentStrafeAxisImpulse, StrafeAxisMoveValue, StrafeLerpKey);
	FVector StrafePosition = GetActorLocation() + GetActorRightVector() * StrafeSpeed * CurrentStrafeAxisImpulse * DeltaTime;
	SetActorLocation(StrafePosition, true);
	//right axis rotation
	FRotator Rotation = GetActorRotation();
	CurrentRotationImpulse = FMath::Lerp(CurrentRotationImpulse, RightAxisRotationValue, RotationLerpKey);
	Rotation.Yaw = Rotation.Yaw + RotationSpeed * DeltaTime * CurrentRotationImpulse;
	SetActorRotation(Rotation);
	//turret rotation
	if (TankController)
	{
		FVector MousePosition = TankController->GetTargetLocation(); //getting Mouse position for turret rotation
		FRotator TargetTurretRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), MousePosition);
		FRotator CurrentTurretRotation = TurretMesh->GetComponentRotation();
		TargetTurretRotation.Pitch = CurrentTurretRotation.Pitch;
		TargetTurretRotation.Roll = CurrentTurretRotation.Roll;
		TurretMesh->SetWorldRotation(FMath::Lerp(CurrentTurretRotation, TargetTurretRotation, TurretRotationLerpKey));
	}
	auto PlayerController = Cast<ATankPlayerController>(GetInstigator()->GetController());
	if (PlayerController)
	{
		//AmmoHUD
		//if (Cannon)
		//GEngine->AddOnScreenDebugMessage(20, 0.5f, FColor::Cyan, FString::Printf(TEXT("Ammo: %d"), Cannon->GetCurrAmmo()));

		//ScoreHUD
		//GEngine->AddOnScreenDebugMessage(21, 0.5f, FColor::Purple, FString::Printf(TEXT("Your Score: %d"), TotalScore));
	}
}

void ATank::MoveForward(const float ForwardAxisImpulse)
{
	ForwardAxisMoveValue = ForwardAxisImpulse;
}

void ATank::StrafeRight(float StrafeAxisImpulse)
{
	StrafeAxisMoveValue = StrafeAxisImpulse;
}

void ATank::RotateRight(float RightRotationImpulse)
{
	RightAxisRotationValue = RightRotationImpulse;
}

void ATank::SetupCanon()
{
	if (Cannon)
	{

		for (const auto child : Cannon->Children)
		{
			while (child->IsActorBeingDestroyed())
			{
				//
			};
		}
		Cannon->Destroy();

	}
	FActorSpawnParameters spawnParams;
	spawnParams.Instigator = this;
	spawnParams.Owner = this;
	if (CurrentCanonClass)
	{
		if (FirstCannonUsed)
		{
			if (CannonOne)
			{
				Cannon = GetWorld()->SpawnActor<ACanon>(CurrentCanonClass, spawnParams);
				Cannon->SetCurrAmmo(CannonOne->GetCurrAmmo());
			}
			else
			{
				Cannon = GetWorld()->SpawnActor<ACanon>(CurrentCanonClass, spawnParams);
				Cannon->ResetAmmo();
				CannonOne = Cannon;
				CannonOne->ResetAmmo();
			}
		}
		else
		{
			if (CannonTwo)
			{
				Cannon = GetWorld()->SpawnActor<ACanon>(CurrentCanonClass, spawnParams);
				Cannon->SetCurrAmmo(CannonTwo->GetCurrAmmo());
			}
			else 
			{
				Cannon = GetWorld()->SpawnActor<ACanon>(CurrentCanonClass, spawnParams);
				Cannon->ResetAmmo();
				CannonTwo = Cannon;
				CannonTwo->ResetAmmo();
			}
		}
		if (Cannon)
		Cannon->AttachToComponent(CanonMountingPoint, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}

}

void ATank::ChangeCanon(TSubclassOf<ACanon> _CanonType)
{
	if (!SecondCannon)
	{
		SecondCannon = _CanonType;
		CurrentCanonClass = SecondCannon;
		SecondCannonUsed = true;
		FirstCannonUsed = false;
		SetupCanon();
		return;
	}

	if (FirstCannonUsed)
	{
		FirstCannon = _CanonType;
		CurrentCanonClass = FirstCannon;
		SecondCannonUsed = false;
		FirstCannonUsed = true;
		CannonOne->Destroy();
	}
	else
	{
		SecondCannon = _CanonType;
		CurrentCanonClass = SecondCannon;
		SecondCannonUsed = true;
		FirstCannonUsed = false;
		CannonTwo->Destroy();
	}
	SetupCanon();
}


void ATank::PrimaryFire()
{
	if (!Cannon)
	{
		return;
	}

	Cannon->Fire(FireType::Primary);

	if(PawnState.IsValid())
		PawnState->PawnAmmoPrimary = Cannon->GetCurrAmmo();
}

void ATank::SecondaryFire()
{
	if (!Cannon)
	{
		return;
	}
	Cannon->Fire(FireType::Secondary);
}

void ATank::SwitchWeapon()
{
	if (!Cannon)
		return;

	if (FirstCannonUsed)
	{
		if (SecondCannon)
		{
			CurrentCanonClass = SecondCannon;
			FirstCannonUsed = false;
			SecondCannonUsed = true;
			CannonOne = Cannon;
			SetupCanon();
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, "Switched to second weapon", true);
		}
		else
		{
			return;
		}
	}
	else
	{
		if (!SecondCannonUsed)
		{
			return;
		}
		else if (FirstCannon)
		{
			CurrentCanonClass = FirstCannon;
			FirstCannonUsed = true;
			SecondCannonUsed = false;
			CannonTwo = Cannon;
			SetupCanon();
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, "Switched to first weapon", true);
		}
		else
		{
			return;
		}
	}
}

//for AI purposes
void ATank::OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == this || OtherActor == GetInstigator() || OtherActor == nullptr)
	{
		return;
	}
	if (OtherActor->GetClass() != TargetType)
	{
		return;
	}
	Targets.Add(OtherActor);
	OnTargetsChanged.Broadcast();
}

void ATank::OnDetectionSphereEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == this || OtherActor == GetInstigator() || OtherActor == nullptr)
	{
		return;
	}
	if (OtherActor->GetClass() != TargetType)
	{
		return;
	}

	Targets.Remove(OtherActor);
	if (OtherActor == CurrentTarget)
	{
		OnTargetsChanged.Broadcast();
	}
}
