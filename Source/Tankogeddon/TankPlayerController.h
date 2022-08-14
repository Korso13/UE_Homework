// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */

class ATank;

UCLASS()
class TANKOGEDDON_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

protected:
	ATank* TankPawn = nullptr;
public:
	//ATankPlayerController();

	virtual void OnPossess(APawn* InTankPawn) override;

	virtual void SetupInputComponent() override;

	UFUNCTION()
	void MoveForward(float ForwardAxisImpulse);
	UFUNCTION()
	void StrafeRight(float StrafeAxisImpulse);

};
