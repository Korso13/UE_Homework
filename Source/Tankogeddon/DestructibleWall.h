// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HealthComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "DestructibleWall.generated.h"

UCLASS()
class TANKOGEDDON_API ADestructibleWall : public AActor, public IDamageTaker
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADestructibleWall();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	UBoxComponent* Collision;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	UStaticMeshComponent* BodyMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	UHealthComponent* HealthComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OnDeath();

	void TakeDamage(FDamageInfo DamageData);

	virtual float GetHealth() const override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
