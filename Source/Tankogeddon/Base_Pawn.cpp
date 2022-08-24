// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_Pawn.h"
#include "Projectile.h"

// Sets default values
ABase_Pawn::ABase_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called every frame
//void ABase_Pawn::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

// Called to bind functionality to input
//void ABase_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

 //Called when the game starts or when spawned
void ABase_Pawn::BeginPlay()
{
	Super::BeginPlay();

	OnScoredKill.AddUObject(this, &ABase_Pawn::ScoredKill);
}

void ABase_Pawn::Destroyed()
{
	Super::Destroyed();

	if (Cannon)
	{
		Cannon->Destroy();
	}
}

void ABase_Pawn::OnDeath()
{
	Destroy();
}

void ABase_Pawn::TakeDamage(FDamageInfo DamageData)
{
	HealthComponent->TakeDamage(DamageData);
}

int32 ABase_Pawn::GetScore() const
{
	return ScoreValue;
}

void ABase_Pawn::ScoredKill(FScoredKillData KillData) //stub. to be overriden
{
	if(IsValid(KillData.Killer))
	{
		if((KillData.ScoreValue != 0) && KillData.Killer == this)
		{
			TotalScore += KillData.ScoreValue;
		}
	}
}

