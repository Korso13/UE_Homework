// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Base_Pawn.h"
#include "ControllerTargeting.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */

class ATank;



UCLASS()
class TANKOGEDDON_API ATankPlayerController : public APlayerController, public IControllerTargeting
{
	GENERATED_BODY()
	
private:
	FVector WorldMousePosition;
	FVector LastWorldMousePosition;
	FVector StickAxis;
	FVector LastStickAxis{0,0,0};
	float StickXAxis;
	float StickYAxis;


public:
	UPROPERTY()
	ATank* TankPawn = nullptr;

protected:
	TSharedPtr<GenericApplication, ESPMode::NotThreadSafe> App;

public:
	ATankPlayerController();

	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* InTankPawn) override;

	virtual void SetupInputComponent() override;

	virtual void Tick(float DeltaTime) override;

	virtual FVector GetTargetLocation() const override;

	void ToggleInventoryWindow();

	UFUNCTION()
	void MoveForward(float ForwardAxisImpulse);
	UFUNCTION()
	void StrafeRight(float StrafeAxisImpulse);
	UFUNCTION()
	void RotateRight(float RightRotationImpulse);

	UFUNCTION()
	void StickRotationY(float StickY);
	UFUNCTION()
	void StickRotationX(float StickX);


	UFUNCTION()
	void PrimaryFire();
	UFUNCTION()
	void SecondaryFire();
	UFUNCTION()
	void SwitchWeapon();
	
	UFUNCTION()
	void MouseButtonUp();

	FSimpleMulticastDelegate OnMouseButtonUp;
};


