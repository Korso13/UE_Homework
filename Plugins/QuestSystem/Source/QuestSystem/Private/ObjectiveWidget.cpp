// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectiveWidget.h"

#include "Objective.h"
#include "Components/CheckBox.h"
#include "Components/TextBlock.h"

void UObjectiveWidget::Init(const UObjective* InObjective)
{
	if(!InObjective)
		return;

	CompletionCheckbox->SetIsChecked(InObjective->IsCompleted());
	ObjectiveDescription->SetText(InObjective->GetObjectiveDescription());
}
