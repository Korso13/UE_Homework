// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ObjectiveWidget.generated.h"

class UCheckBox;
class UTextBlock;
class UObjective;
/**
 * 
 */
UCLASS()
class QUESTSYSTEM_API UObjectiveWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta=(BindWidget))
	UCheckBox* CompletionCheckbox;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* ObjectiveDescription;

	void Init(const UObjective* InObjective);
};
