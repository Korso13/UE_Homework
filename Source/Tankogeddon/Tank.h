// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base_Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "TankPlayerController.h"
#include "Tank.generated.h"

class USpringArmComponent;
class UCameraComponent;
//class UStaticMeshComponent;
//class UBoxComponent;
//class ACanon;
class ATankPlayerController;


UCLASS()
class TANKOGEDDON_API ATank : public ABase_Pawn
{
	GENERATED_BODY()


public:

	//Tank settings
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Motion|Speed")
	float MoveSpeed = 100;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Motion|Speed")
	float StrafeSpeed = 100;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Motion|Speed")
	float RotationSpeed = 20;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Motion|Acceleration")
	float ForwardMovementLerpKey = 0.1f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Motion|Acceleration")
	float StrafeLerpKey = 0.1f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Motion|Acceleration")
	float RotationLerpKey = 0.1f;

	//camera components
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	USpringArmComponent* SpringArm;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	UCameraComponent* Camera;

	//service values
private:
	float ForwardAxisMoveValue = 0;
	float CurrentForwardAxisImpulse = 0;
	float StrafeAxisMoveValue = 0;
	float CurrentStrafeAxisImpulse = 0;
	float RightAxisRotationValue = 0; 
	float CurrentRotationImpulse = 0;

private:
	void OnDamage(FDamageInfo Damage);

protected:
	UPROPERTY()
	ACanon* CannonOne;
	UPROPERTY()
	ACanon* CannonTwo;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Components|Weapons")
	TSubclassOf<ACanon> FirstCannon;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Components|Weapons")
	TSubclassOf<ACanon> SecondCannon;

	bool FirstCannonUsed = false;
	bool SecondCannonUsed = false;
	TSubclassOf<ACanon> CurrentCanonClass;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Components")
	ATankPlayerController* TankController;
	
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Sets default values for this pawn's properties
	ATank();

	//Called every frame
	virtual void Tick(float DeltaTime) override;

	//Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SetupCanon();

	void ChangeCanon(TSubclassOf<ACanon> _CanonType);

	UFUNCTION()
	void MoveForward(const float ForwardAxisImpulse);

	UFUNCTION()
	void StrafeRight(float StrafeAxisImpulse);

	UFUNCTION()
	void RotateRight(float RightRotationImpulse);

	UFUNCTION()
	void PrimaryFire() const; 

	UFUNCTION()
	void SecondaryFire() const;

	UFUNCTION()
	void SwitchWeapon();

	UFUNCTION()
		ACanon* GetCannon() const { return Cannon; }

};
