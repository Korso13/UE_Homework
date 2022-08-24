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
	//meshes and components
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
		USphereComponent* DetectionSphere;

	//turret properties
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cannon Type")
	float TargetingUpdateRate = 0.3f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cannon Type")
	float Accuracy = 10;

protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Components|Weapons")
	TSubclassOf<ACanon> CanonClass;

	int32 ScoreValue = 100;

private:
	FTimerHandle TargetingTimer;

	TArray<TWeakObjectPtr<AActor>> Targets;

	TWeakObjectPtr<AActor> CurrentTarget;



public:	
	// Sets default values for this actor's properties
	ATurret();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void OnDetectionSphere_BeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnDetectionSphereEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void OnDamage(FDamageInfo Damage);


	void FindBestTarget();

	void Targeting();

	bool CanFire();

public:	
	virtual int32 GetScore() const override;
};
