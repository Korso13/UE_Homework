// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "QuestDialogueWidget.generated.h"

class UQuestDescriptionWidget;
class UButton;
class AQuest;
/**
 * 
 */
UCLASS()
class QUESTSYSTEM_API UQuestDialogueWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	void Init(const AQuest* InQuest);

	FSimpleDelegate OnQuestAccepted;

	FSimpleDelegate OnDialogueExit;

protected:
	UPROPERTY(meta=(BindWidget), EditAnywhere)
	UButton* AcceptButton;

	UPROPERTY(meta=(BindWidget), EditAnywhere)
	UButton* RejectButton;

	UPROPERTY(meta=(BindWidget))
	UQuestDescriptionWidget* QuestDescription;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bDisableMouseCursorOnDialogeEnd = false; //enable if target game doesn't need cursor for gameplay!
	
	void HideDialogue();

	UFUNCTION()
	void OnAccepted();
	
	UFUNCTION()
	void OnRejected();
};
