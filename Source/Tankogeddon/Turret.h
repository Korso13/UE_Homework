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
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
	TSubclassOf<ACanon> CanonClass;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Type")
	int32 TurretAmmo = 100;

private:

public:	
	// Sets default values for this actor's properties
	ATurret();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void RegisterOnSaveFile() override;

	virtual void OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
		

private:

	void Targeting();

	bool CanFire();

	bool IsVisible(TWeakObjectPtr<AActor> CurrentTarget) const;
};
