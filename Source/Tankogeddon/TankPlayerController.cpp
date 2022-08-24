// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Math/UnrealMathUtility.h"
#include "Tank.h"
#include "DrawDebugHelpers.h" //for drawing debuglines


ATankPlayerController::ATankPlayerController()
{
	bShowMouseCursor = true;
}

void ATankPlayerController::OnPossess(APawn* InTankPawn)
{
	Super::OnPossess(InTankPawn);

	TankPawn = Cast<ATank>(InTankPawn);
}

void ATankPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("ForwardAxis", this, &ATankPlayerController::MoveForward);
	InputComponent->BindAxis("RightSlideAxis", this, &ATankPlayerController::StrafeRight);
	InputComponent->BindAxis("RightTurnAxis", this, &ATankPlayerController::RotateRight);
	InputComponent->BindAction("PrimaryFire", IE_Pressed, this, &ATankPlayerController::PrimaryFire);
	InputComponent->BindAction("SecondaryFire", IE_Pressed, this, &ATankPlayerController::SecondaryFire);
	InputComponent->BindAction("SwitchWeapon", IE_Pressed, this, &ATankPlayerController::SwitchWeapon); 
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//getting mouse pointer at the height of a turret for turret rotation
	FVector MousePosition;
	FVector MouseDirection;
	DeprojectMousePositionToWorld(MousePosition, MouseDirection); //obtaining a vector from mouse pointer "on screen" and a point in 3D space it is supposedly pointing
	float Z = FMath::Abs(TankPawn->TurretMesh->GetComponentLocation().Z - MousePosition.Z); //height difference between turret and mouse pointer "on screen"
	WorldMousePosition = MousePosition - (MouseDirection * Z / MouseDirection.Z); //calculating final mouse pointer position in 3D space
	//drawing debug aim lines
	DrawDebugLine(GetWorld(), TankPawn->CanonMountingPoint->GetComponentLocation(), TankPawn->CanonMountingPoint->GetComponentLocation() + TankPawn->CanonMountingPoint->GetForwardVector() * 700, FColor::Green, false, -1, 0, 1);
}

void ATankPlayerController::MoveForward(float ForwardAxisImpulse)
{
	if (TankPawn)
	{
		TankPawn->MoveForward(ForwardAxisImpulse);
	}
}

void ATankPlayerController::StrafeRight(float StrafeAxisImpulse)
{
	if (TankPawn)
	{
		TankPawn->StrafeRight(StrafeAxisImpulse);
	}
}

void ATankPlayerController::RotateRight(float RightRotationImpulse)
{
	if (TankPawn)
	{
		TankPawn->RotateRight(RightRotationImpulse);
	}
}

FVector ATankPlayerController::GetMousePos() const
{
	return WorldMousePosition;
}

void ATankPlayerController::PrimaryFire()
{
	if (TankPawn)
	{
		TankPawn->PrimaryFire();
	}
}

void ATankPlayerController::SecondaryFire()
{
	if (TankPawn)
	{
		TankPawn->SecondaryFire();
	}
}

void ATankPlayerController::SwitchWeapon()
{
	if (TankPawn)
	{
		TankPawn->SwitchWeapon();
	}
}

