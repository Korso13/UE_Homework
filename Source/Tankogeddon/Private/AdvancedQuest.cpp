// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedQuest.h"

#include "AdvancedObjectives.h"

#if WITH_EDITOR
void AAdvancedQuest::AddDestroyObjective()
{
	Objectives.Add(NewObject<UDestroyObjective>(this));
}

void AAdvancedQuest::AddScoreObjective()
{
	Objectives.Add(NewObject<UScoreObjective>(this));
}
#endif
