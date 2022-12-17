// Fill out your copyright notice in the Description page of Project Settings.


// ReSharper disable CppExpressionWithoutSideEffects
#include "QuestDialogueWidget.h"
#include "Quest.h"
#include "QuestDescriptionWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UQuestDialogueWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if(AcceptButton)
	{
		AcceptButton->OnReleased.AddDynamic(this, &UQuestDialogueWidget::OnAccepted);
	}

	if(RejectButton)
	{
		RejectButton->OnReleased.AddDynamic(this, &UQuestDialogueWidget::OnRejected);
	}

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController);
	PlayerController->bShowMouseCursor = true;
}

void UQuestDialogueWidget::Init(const AQuest* InQuest)
{
	if(QuestDescription)
		QuestDescription->Init(InQuest);
}

void UQuestDialogueWidget::HideDialogue()
{
	if(this->IsInViewport())
		RemoveFromViewport();

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
	if(bDisableMouseCursorOnDialogeEnd)
		PlayerController->bShowMouseCursor = false; 

	OnDialogueExit.ExecuteIfBound();
}

void UQuestDialogueWidget::OnAccepted()
{
	HideDialogue();
	OnQuestAccepted.ExecuteIfBound();
}

void UQuestDialogueWidget::OnRejected()
{
	HideDialogue();
}
