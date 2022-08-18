// Fill out your copyright notice in the Description page of Project Settings.

#include "Math/UnrealMathUtility.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameStructs.h"
#include "Tank.h"

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
	SpringArm->TargetArmLength = 800;
	SpringArm->bDoCollisionTest = false;
};

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

	TankController = Cast<ATankPlayerController>(GetController());

	SetupCanon();
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//forward movement
	CurrentForwardAxisImpulse = FMath::Lerp(CurrentForwardAxisImpulse, ForwardAxisMoveValue, ForwardMovementLerpKey); //interpolating current speed by target speed
	FVector MovePosition = GetActorLocation() + GetActorForwardVector() * MoveSpeed * CurrentForwardAxisImpulse * DeltaTime; //using interpolated forward speed
	UE_LOG(TankLog, Warning, TEXT("Forward Impulse: %f, Forward Value: %f"), CurrentForwardAxisImpulse, ForwardAxisMoveValue); //debug!!
	SetActorLocation(MovePosition, true);
	//strafing
	CurrentStrafeAxisImpulse = FMath::Lerp(CurrentStrafeAxisImpulse, StrafeAxisMoveValue, StrafeLerpKey);
	FVector StrafePosition = GetActorLocation() + GetActorRightVector() * StrafeSpeed * CurrentStrafeAxisImpulse * DeltaTime;
	SetActorLocation(StrafePosition, true);
	//right axis rotation
	FRotator Rotation = GetActorRotation();
	CurrentRotationImpulse = FMath::Lerp(CurrentRotationImpulse, RightAxisRotationValue, RotationLerpKey);
	Rotation.Yaw = Rotation.Yaw + RotationSpeed * DeltaTime * CurrentRotationImpulse;
	UE_LOG(LogTemp, Warning, TEXT("Impulse: %f, RotationValue: %f"), CurrentRotationImpulse, RightAxisRotationValue); //debug!!
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
		TankCanon->Destroy();
	}
	FActorSpawnParameters spawnParams;
	spawnParams.Instigator = this;
	spawnParams.Owner = this;
	TankCanon = GetWorld()->SpawnActor<ACanon>(CanonClass, spawnParams);
	TankCanon->AttachToComponent(CanonMountingPoint, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

void ATank::PrimaryFire()
{
	if (!TankCanon)
	{
		return;
	}
	
	TankCanon->Fire(FireType::Primary);
}

void ATank::SecondaryFire()
{
	if (!TankCanon)
	{
		return;
	}
	TankCanon->Fire(FireType::Secondary);
}