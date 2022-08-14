// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"



// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TankBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tank Body"));
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("TankCollision"));
	RootComponent = Collision;
	TankBody->SetupAttachment(Collision);
	//RootComponent = TankBody;
	//Collision->SetupAttachment(TankBody);

	TankTurret = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tank Turret"));
	TankTurret->SetupAttachment(TankBody);
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(TankBody);
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

}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector MovePosition = GetActorLocation() + GetActorForwardVector() * MoveSpeed * ForwardAxisMoveValue * DeltaTime;
	SetActorLocation(MovePosition, true);

	FVector StrafePosition = GetActorLocation() + GetActorRightVector() * StrafeSpeed * StrafeAxisMoveValue * DeltaTime;
	SetActorLocation(StrafePosition, true);

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


