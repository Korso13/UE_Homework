// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Tank.generated.h"

class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UBoxComponent;

UCLASS()
class TANKOGEDDON_API ATank : public APawn
{
	GENERATED_BODY()


public:
	// Sets default values for this pawn's properties
	ATank();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Motion")
		float MoveSpeed = 100;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Motion")
		float StrafeSpeed = 100;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Motion")
		FTransform TankTransform;

	
	float ForwardAxisMoveValue = 0;
	float StrafeAxisMoveValue = 0;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UStaticMeshComponent* TankBody;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UStaticMeshComponent* TankTurret;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		USpringArmComponent* SpringArm;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UCameraComponent* Camera;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		UBoxComponent* Collision;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void MoveForward(const float ForwardAxisImpulse);

	UFUNCTION()
	void StrafeRight(float StrafeAxisImpulse);

};
