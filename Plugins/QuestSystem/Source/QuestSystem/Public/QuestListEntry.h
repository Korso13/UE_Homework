// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "QuestListEntry.generated.h"

class UBorder;
class AQuest;
class UTextBlock;

DECLARE_MULTICAST_DELEGATE_OneParam(FOnNewEntryPicked, const AQuest* /*NewlyPickedQuestEntry*/)
/**
 * 
 */
UCLASS()
class QUESTSYSTEM_API UQuestListEntry : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget))
	UTextBlock* QuestName;

	UPROPERTY(meta=(BindWidget), EditDefaultsOnly)
	UBorder* QuestEntryBorder;
	
	UPROPERTY()
	AQuest* Quest;

public:
	void Init(AQuest* InQuest);

	AQuest* GetQuest() const {return Quest;}

	void OnEntryDeselected();

	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	
	/*FOnClicked OnClicked;*/
	
	FOnNewEntryPicked OnNewEntryPicked;
};
