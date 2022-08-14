// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

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

