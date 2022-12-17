// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestBoard.h"

#include "Quest.h"
#include "QuestDescriptionWidget.h"
#include "QuestListEntry.h"
#include "QuestManager.h"
#include "Components/VerticalBox.h"

void UQuestBoard::PickQuestForViewer(AQuest* InQuest)
{
	if(QuestDescription && InQuest && MainQuestsList && SideQuestsList)
	{
		QuestDescription->Init(InQuest);
		
		for(const auto QuestEntry : MainQuestsList->GetAllChildren())
		{
			UQuestListEntry* Entry = Cast<UQuestListEntry>(QuestEntry);
			if(!Entry)
			{
				continue;
			}

			if(Entry->GetQuest() != InQuest)
			{
				Entry->OnEntryDeselected();
			}
		}

		for(const auto QuestEntry : SideQuestsList->GetAllChildren())
		{
			UQuestListEntry* Entry = Cast<UQuestListEntry>(QuestEntry);
			if(!Entry)
			{
				continue;
			}

			if(Entry->GetQuest() != InQuest)
			{
				Entry->OnEntryDeselected();
			}
		}
	}

	QuestManager->SetActiveQuest(InQuest);
}

void UQuestBoard::Init(UQuestManager* InQuestManager)
{
	if(InQuestManager)
		QuestManager = InQuestManager;

	if(QuestListEntryClass && MainQuestsList && SideQuestsList && QuestDescription && QuestManager->GetQuests().Num() > 0)
	{
		MainQuestsList->ClearChildren();
		SideQuestsList->ClearChildren();
		
		for (const auto Quest : QuestManager->GetQuests())
		{
			UQuestListEntry* QuestListEntry = CreateWidget<UQuestListEntry>(GetWorld(), QuestListEntryClass);
			QuestListEntry->Init(Quest);
			QuestListEntry->OnNewEntryPicked.AddUFunction(this, "PickQuestForViewer");

			if(Quest->IsMainQuest())
			{
				MainQuestsList->AddChildToVerticalBox(QuestListEntry);
			}
			else
			{
				SideQuestsList->AddChildToVerticalBox(QuestListEntry);
			}
		}

		QuestDescription->SetBlankFields();
	}
}
