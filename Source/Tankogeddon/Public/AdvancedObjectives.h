// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Objective.h"
#include "AdvancedObjectives.generated.h"

UENUM()
enum class EObjectiveTypeAdvanced : uint8
{
	OT_Location,
	OT_Interaction,
	OT_Destruction,
	OT_Score
};

/**
 * 
 */
UCLASS(Abstract)
class TANKOGEDDON_API UAdvancedObjectives : public UObjective
{
	GENERATED_BODY()

protected:
	UAdvancedObjectives();
	
	UPROPERTY(EditAnywhere)
	EObjectiveTypeAdvanced EObjectiveTypeAdvanced;
};

UCLASS()
class TANKOGEDDON_API UDestroyObjective : public UAdvancedObjectives
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	AActor* QuestTarget;
	
public:
	UDestroyObjective();

	virtual void ActivateObjective(AActor* QuestInstigator) override;
};

UCLASS()
class TANKOGEDDON_API UScoreObjective : public UAdvancedObjectives
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	int32 ScoreTarget;

	int32 CurrentScore = 0;
	
public:
	UScoreObjective();

	virtual void ActivateObjective(AActor* QuestInstigator) override;
};