// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base_Pawn.h"
#include "Components/SphereComponent.h"
#include "Turret.generated.h"

UCLASS()
class TANKOGEDDON_API ATurret : public ABase_Pawn
{
	GENERATED_BODY()
public:

	//turret properties
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cannon Type")
	float TargetingUpdateRate = 0.3f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cannon Type")
	float Accuracy = 10;

	FTimerHandle TargetingTimer;
protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Components|Weapons")
	TSubclassOf<ACanon> CanonClass;

	int32 ScoreValue = 100;

private:

public:	
	// Sets default values for this actor's properties
	ATurret();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	virtual void FindBestTarget() override;

	void Targeting();

	bool CanFire();

	bool IsVisible(TWeakObjectPtr<AActor> CurrentTarget) const;

public:	
	virtual int32 GetScore() const override;
};
