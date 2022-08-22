// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Canon.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/Engine.h"
#include "GameStructs.h"

DECLARE_LOG_CATEGORY_EXTERN(TankLog, All, All);
DEFINE_LOG_CATEGORY(TankLog);

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("TankCollision"));
	RootComponent = Collision;

	TankBodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tank Body"));
	TankBodyMesh->SetupAttachment(Collision);

	TankTurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tank Turret"));
	TankTurretMesh->SetupAttachment(TankBodyMesh);

	CanonMountingPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("Canon Mounting Point"));
	CanonMountingPoint->AttachToComponent(TankTurretMesh, FAttachmentTransformRules::KeepRelativeTransform);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(TankBodyMesh);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bInheritYaw = false;
	SpringArm->TargetArmLength = 1000;
	SpringArm->bDoCollisionTest = true;
};

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

	TankController = Cast<ATankPlayerController>(GetController());
	CurrentCanonClass = FirstCannon;
	FirstCannonUsed = true;
	SecondCannonUsed = false;
	SetupCanon();
	CannonOne = TankCanon;
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//forward movement
	CurrentForwardAxisImpulse = FMath::Lerp(CurrentForwardAxisImpulse, ForwardAxisMoveValue, ForwardMovementLerpKey); //interpolating current speed by target speed
	FVector MovePosition = GetActorLocation() + GetActorForwardVector() * MoveSpeed * CurrentForwardAxisImpulse * DeltaTime; //using interpolated forward speed
	//UE_LOG(TankLog, Warning, TEXT("Forward Impulse: %f, Forward Value: %f"), CurrentForwardAxisImpulse, ForwardAxisMoveValue); //debug!!
	SetActorLocation(MovePosition, true);
	//strafing
	CurrentStrafeAxisImpulse = FMath::Lerp(CurrentStrafeAxisImpulse, StrafeAxisMoveValue, StrafeLerpKey);
	FVector StrafePosition = GetActorLocation() + GetActorRightVector() * StrafeSpeed * CurrentStrafeAxisImpulse * DeltaTime;
	SetActorLocation(StrafePosition, true);
	//right axis rotation
	FRotator Rotation = GetActorRotation();
	CurrentRotationImpulse = FMath::Lerp(CurrentRotationImpulse, RightAxisRotationValue, RotationLerpKey);
	Rotation.Yaw = Rotation.Yaw + RotationSpeed * DeltaTime * CurrentRotationImpulse;
	//UE_LOG(LogTemp, Warning, TEXT("Impulse: %f, RotationValue: %f"), CurrentRotationImpulse, RightAxisRotationValue); //debug!!
	SetActorRotation(Rotation);
	//turret rotation
	FVector MousePosition = TankController->GetMousePos(); //getting Mouse position for turret rotation
	FRotator TargetTurretRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), MousePosition);
	FRotator CurrentTurretRotation = TankTurretMesh->GetComponentRotation();
	TargetTurretRotation.Pitch = CurrentTurretRotation.Pitch;
	TargetTurretRotation.Roll = CurrentTurretRotation.Roll;
	TankTurretMesh->SetWorldRotation(FMath::Lerp(CurrentTurretRotation, TargetTurretRotation, TurretRotationLerpKey));
}

// Called to bind functionality to input
//void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

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
	if (TankCanon)
	{
		while(TankCanon->IsPendingKillPending())
		{
			//
		}
			TankCanon->Destroy();

	}
	FActorSpawnParameters spawnParams;
	spawnParams.Instigator = this;
	spawnParams.Owner = this;
	if(CurrentCanonClass)
	{
		//TankCanon = GetWorld()->SpawnActor<ACanon>(CurrentCanonClass, spawnParams);
		if(FirstCannonUsed)
		{
			if (CannonOne)
			{
				TankCanon = GetWorld()->SpawnActor<ACanon>(CurrentCanonClass, spawnParams);
				TankCanon->SetCurrAmmo(CannonOne->GetCurrAmmo());
			}
			else
			{
				TankCanon = GetWorld()->SpawnActor<ACanon>(CurrentCanonClass, spawnParams);
				TankCanon->ResetAmmo();
				CannonOne = TankCanon;
				CannonOne->ResetAmmo();
			}
		}
		else
		{
			if (CannonTwo)
			{
				TankCanon = GetWorld()->SpawnActor<ACanon>(CurrentCanonClass, spawnParams);
				TankCanon->SetCurrAmmo(CannonTwo->GetCurrAmmo());
			}
			else
			{
				TankCanon = GetWorld()->SpawnActor<ACanon>(CurrentCanonClass, spawnParams);
				TankCanon->ResetAmmo();
				CannonTwo = TankCanon;
				CannonTwo->ResetAmmo();
			}
		}
		TankCanon->AttachToComponent(CanonMountingPoint, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}

}

void ATank::ChangeCanon(TSubclassOf<ACanon> _CanonType)
{
	if(!SecondCannon)
	{
		SecondCannon = _CanonType;
		CurrentCanonClass = SecondCannon;
		SecondCannonUsed = true;
		FirstCannonUsed = false;
		SetupCanon();
		return;
	}

	if(FirstCannonUsed)
	{
		FirstCannon = _CanonType;
		CurrentCanonClass = FirstCannon;
		SecondCannonUsed = false;
		FirstCannonUsed = true;
		//TankCanon->Destroy();
		CannonOne->Destroy();
	}
	else
	{
		SecondCannon = _CanonType;
		CurrentCanonClass = SecondCannon;
		SecondCannonUsed = true;
		FirstCannonUsed = false;
		//TankCanon->Destroy();
		CannonTwo->Destroy();
	}
	SetupCanon();
}


void ATank::PrimaryFire() const
{
	if (!TankCanon)
	{
		return;
	}
	
	TankCanon->Fire(FireType::Primary);
}

void ATank::SecondaryFire() const
{
	if (!TankCanon)
	{
		return;
	}
	TankCanon->Fire(FireType::Secondary);
}


void ATank::Destroyed()
{
	Super::Destroyed();

	if(TankCanon)
	{
		TankCanon->Destroy();
	}
}

void ATank::SwitchWeapon()
{
	if(FirstCannonUsed)
	{
		if(SecondCannon)
		{
			CurrentCanonClass = SecondCannon;
			FirstCannonUsed = false;
			SecondCannonUsed = true;
			CannonOne = TankCanon;
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
		if(!SecondCannonUsed)
		{
			return;
		}
		else if(FirstCannon)
		{
			CurrentCanonClass = FirstCannon;
			FirstCannonUsed = true;
			SecondCannonUsed = false;
			CannonTwo = TankCanon;
			SetupCanon();
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, "Switched to first weapon", true);
		}
		else
		{
			return;
		}
	}
}

