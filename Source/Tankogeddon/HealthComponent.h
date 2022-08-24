// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageTaker.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKOGEDDON_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

	DECLARE_EVENT(UHealthComponent, FOnDeath);
	DECLARE_EVENT_OneParam(UHealthComponent, FOnDamage, FDamageInfo);

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Health")
		float MaxHP = 10;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Health")
		float CurrentHP = 10;

	FOnDeath OnDeath;
	FOnDamage OnDamage;

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void TakeDamage(FDamageInfo Damage);
};
