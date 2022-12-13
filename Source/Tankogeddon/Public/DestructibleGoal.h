// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DestructibleGoal.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UDestructibleGoal : public UInterface
{
	GENERATED_BODY()
};

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnTargetDestroyed, AActor* /*Destroyed Actor*/, AActor* /*Destroyer*/)
/**
 * 
 */
class TANKOGEDDON_API IDestructibleGoal
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	FOnTargetDestroyed OnTargetDestroyed;

	UFUNCTION(BlueprintCallable)
	virtual void TargetDestroyed(AActor* DestroyedActor, AActor* DestructionInstigator)
	{
		if(OnTargetDestroyed.IsBound())
			OnTargetDestroyed.Broadcast(DestroyedActor, DestructionInstigator);
	}
};
