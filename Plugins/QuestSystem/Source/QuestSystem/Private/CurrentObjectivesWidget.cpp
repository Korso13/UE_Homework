// Fill out your copyright notice in the Description page of Project Settings.


#include "CurrentObjectivesWidget.h"

#include "ObjectiveWidget.h"
#include "Quest.h"
#include "Components/VerticalBox.h"

void UCurrentObjectivesWidget::SetCurrentObjectives(const AQuest* InQuest)
{
	if(ObjectivesList && ObjectiveWidgetClass)
	{
		ObjectivesList->ClearChildren();

		for(const auto& Objective : InQuest->GetObjectives())
		{
			UObjectiveWidget* ObjWidget = CreateWidget<UObjectiveWidget>(GetWorld(), ObjectiveWidgetClass);
			ObjectivesList->AddChildToVerticalBox(ObjWidget);
			ObjWidget->Init(Objective);
		}
	}
}
