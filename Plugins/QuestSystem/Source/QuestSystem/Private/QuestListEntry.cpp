// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestListEntry.h"

#include "Quest.h"
#include "QuestBoard.h"
#include "Components/Border.h"
#include "Input/Reply.h"
#include "Components/TextBlock.h"

void UQuestListEntry::Init(AQuest* InQuest)
{
	if(!InQuest)
		return;

	if(QuestName)
	{
		QuestName->SetText(InQuest->GetQuestName());
		Quest = InQuest;
		SetVisibility(ESlateVisibility::Visible);
		
		/*OnClicked.BindLambda([this]()
		{
			if(OnNewEntryPicked.IsBound())
				OnNewEntryPicked.Broadcast(Quest);
			
			if(this->QuestEntryBorder)
			{
				const FLinearColor NewColor = QuestEntryBorder->BrushColor.CopyWithNewOpacity(0.5f);
				QuestEntryBorder->BrushColor = NewColor;
			}
		});*/
	}
}

void UQuestListEntry::OnEntryDeselected()
{
	if(QuestEntryBorder)
	{
		const FLinearColor NewColor = QuestEntryBorder->BrushColor.Desaturate(0);
		QuestEntryBorder->BrushColor = NewColor;
	}
}

FReply UQuestListEntry::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if(InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
	{
		if(OnNewEntryPicked.IsBound())
			OnNewEntryPicked.Broadcast(Quest);
			
		if(QuestEntryBorder)
		{
			const FLinearColor NewColor = QuestEntryBorder->BrushColor.Desaturate(1);
			QuestEntryBorder->BrushColor = NewColor;
		}
	}

	return FReply::Handled();
}
