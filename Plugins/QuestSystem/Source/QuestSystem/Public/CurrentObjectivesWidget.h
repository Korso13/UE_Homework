// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CurrentObjectivesWidget.generated.h"

class UVerticalBox;
class UObjectiveWidget;
class AQuest;
/**
 * 
 */
UCLASS()
class QUESTSYSTEM_API UCurrentObjectivesWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget), BlueprintReadOnly)
	UVerticalBox* ObjectivesList;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UObjectiveWidget> ObjectiveWidgetClass;
	
public:
	UFUNCTION()
	void SetCurrentObjectives(const AQuest* InQuest);
};
