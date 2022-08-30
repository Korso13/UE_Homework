// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Math/UnrealMathUtility.h"
#include "Tank.h"
#include "DrawDebugHelpers.h" //for drawing debuglines
//#include "Kismet/KismetMathLibrary.h"
#include "SlateBasics.h"


ATankPlayerController::ATankPlayerController()
{
	bShowMouseCursor = true;
}

void ATankPlayerController::OnPossess(APawn* InTankPawn)
{
	Super::OnPossess(InTankPawn);

	TankPawn = Cast<ATank>(InTankPawn);
	App = FSlateApplication::Get().GetPlatformApplication();
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
	InputComponent->BindAxis("TurretRotationY", this, &ATankPlayerController::StickRotationY);
	InputComponent->BindAxis("TurretRotationX", this, &ATankPlayerController::StickRotationX);

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//drawing debug aim lines
	DrawDebugLine(GetWorld(), TankPawn->CanonMountingPoint->GetComponentLocation(), TankPawn->CanonMountingPoint->GetComponentLocation() + TankPawn->CanonMountingPoint->GetForwardVector() * 700, FColor::Green, false, -1, 0, 1);

	if(App->IsGamepadAttached())
	{
	//gamepad aiming
	FVector StickData{ StickXAxis, StickYAxis, 0 };
	FVector PointerPosition = TankPawn->CanonMountingPoint->GetComponentLocation();
	StickData = TankPawn->BodyMesh->GetComponentRotation().RotateVector(StickData);
	if (StickXAxis != 0 && StickYAxis != 0)
	{
		PointerPosition += (StickData) * 1000;
		LastStickAxis = StickData;
	}
	else
		PointerPosition += LastStickAxis * 1000;
	WorldMousePosition = PointerPosition;

	//gamepad debugging line
	DrawDebugLine(GetWorld(), TankPawn->CanonMountingPoint->GetComponentLocation(), PointerPosition, FColor::Black, false, -1, 0, 1);
	}
	else
	{
	//getting mouse pointer at the height of a turret for turret rotation
	FVector MousePosition;
	FVector MouseDirection;
	DeprojectMousePositionToWorld(MousePosition, MouseDirection); //obtaining a vector from mouse pointer "on screen" and a point in 3D space it is supposedly pointing
	float Z = FMath::Abs(TankPawn->TurretMesh->GetComponentLocation().Z - MousePosition.Z); //height difference between turret and mouse pointer "on screen"
	WorldMousePosition = MousePosition - (MouseDirection * Z / MouseDirection.Z); //calculating final mouse pointer position in 3D space
	}
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

void ATankPlayerController::StickRotationY(float StickY)
{
	StickYAxis = StickY;
}

void ATankPlayerController::StickRotationX(float StickX)
{
	StickXAxis = StickX;
}


FVector ATankPlayerController::GetTargetLocation() const
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

