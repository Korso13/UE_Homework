// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestDescriptionWidget.h"

#include "Quest.h"
#include "ObjectiveWidget.h"
#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"

void UQuestDescriptionWidget::Init(const AQuest* InQuest)
{
	if(!InQuest)
		return;

	if(NameText)
		NameText->SetText(InQuest->GetQuestName());

	if(DescriptionText)
		DescriptionText->SetText(InQuest->GetQuestDescription());

	if(ObjectivesList)
	{
		ObjectivesList->ClearChildren();
		for(const auto& Objective : InQuest->GetObjectives())
		{
			if(!Objective)
				continue;
			
			UObjectiveWidget* ObjectiveWidget = CreateWidget<UObjectiveWidget>(GetWorld(), ObjectiveWidgetClass);
			ObjectiveWidget->Init(Objective);
			ObjectivesList->AddChild(ObjectiveWidget);
		}
	}
}

void UQuestDescriptionWidget::SetBlankFields()
{
	if(NameText)
		NameText->SetText(FText{});

	if(DescriptionText)
		DescriptionText->SetText(FText{});

	if(ObjectivesList)
	{
		ObjectivesList->ClearChildren();
	}
}
