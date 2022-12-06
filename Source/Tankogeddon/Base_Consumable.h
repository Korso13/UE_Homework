// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Base_Consumable.generated.h"

class ABase_Pawn;
/**
 * 
 */
UCLASS()
class TANKOGEDDON_API ABase_Consumable : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
						UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const
						FHitResult& SweepResult);
public:
	ABase_Pawn* OwningPawn;

	virtual void UseConsumable();
	
};
