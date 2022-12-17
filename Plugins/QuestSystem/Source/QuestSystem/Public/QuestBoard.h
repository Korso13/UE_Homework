// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Delegates/DelegateCombinations.h"
#include "QuestBoard.generated.h"

class UQuestManager;
class UQuestDescriptionWidget;
class UVerticalBox;
class UQuestListEntry;
class AQuest;


/**
 * 
 */
UCLASS()
class QUESTSYSTEM_API UQuestBoard : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UQuestListEntry> QuestListEntryClass;

	UPROPERTY(meta=(BindWidget), EditAnywhere)
	UVerticalBox* MainQuestsList;

	UPROPERTY(meta=(BindWidget), EditAnywhere)
	UVerticalBox* SideQuestsList;

	UPROPERTY(meta=(BindWidget), EditAnywhere)
	UQuestDescriptionWidget* QuestDescription;

	UPROPERTY()
	UQuestManager* QuestManager;
	
public:

	UFUNCTION()
	void PickQuestForViewer(AQuest* InQuest);

	void Init(UQuestManager* InQuestManager);
};
