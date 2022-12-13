// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Quest.h"
#include "AdvancedQuest.generated.h"

/**
 * 
 */
UCLASS()
class TANKOGEDDON_API AAdvancedQuest : public AQuest
{
	GENERATED_BODY()

#if WITH_EDITOR
	UFUNCTION( CallInEditor)
	void AddDestroyObjective();
	
	UFUNCTION( CallInEditor)
	void AddScoreObjective();

#endif
};
