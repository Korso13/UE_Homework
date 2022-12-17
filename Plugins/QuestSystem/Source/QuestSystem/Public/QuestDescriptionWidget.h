// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuestDescriptionWidget.generated.h"

class UTextBlock;
class UScrollBox;
class UObjectiveWidget;
class AQuest;
/**
 * 
 */
UCLASS()
class QUESTSYSTEM_API UQuestDescriptionWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta=(BindWidget), EditAnywhere)
	UTextBlock* NameText;

	UPROPERTY(meta=(BindWidget), EditAnywhere)
	UTextBlock* DescriptionText;

	UPROPERTY(meta=(BindWidget), EditAnywhere)
	UScrollBox* ObjectivesList;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UObjectiveWidget> ObjectiveWidgetClass;
	
public:
	void Init(const AQuest* InQuest);

	void SetBlankFields();
};
