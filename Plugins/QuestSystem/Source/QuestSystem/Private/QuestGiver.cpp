// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestGiver.h"

#include "Objective.h"
#include "Quest.h"
#include "QuestManager.h"
#include "QuestDialogueWidget.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetComponent.h"

AQuestGiver::AQuestGiver()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>("Scene component");
	RootComponent = SceneComponent;
	QuestAvailableSign = CreateDefaultSubobject<UWidgetComponent>("Quest Sign Widget");
	QuestAvailableSign->SetupAttachment(RootComponent);
}

void AQuestGiver::BeginPlay()
{
	Super::BeginPlay();

	UpdateQuestSign();
}

void AQuestGiver::UpdateQuestSign()
{
	TArray<AActor*> AttachedActors; 
	GetAttachedActors(AttachedActors);
	if(AttachedActors.Num() == 0)
	{
		QuestAvailableSign->SetVisibility(false);
		return;
	}
	
	for(const auto& Actor : AttachedActors)
	{
		const AQuest* Quest = Cast<AQuest>(Actor);
		if(Quest)
		{
			if(Quest->GetPrerequisiteQuest())
			{
				if(Quest->GetPrerequisiteQuest()->IsCompleted())
				{
					QuestAvailableSign->SetVisibility(true);
					return;
				}
				else
				{
					for(const auto Objective : Quest->GetPrerequisiteQuest()->GetObjectives())
					{
						Objective->OnObjectiveCompleted.AddUObject(this, &AQuestGiver::UpdateQuestSign);
					}
					continue;
				}
			}
			QuestAvailableSign->SetVisibility(true);
			return;
		}
	}

	QuestAvailableSign->SetVisibility(false);
}

void AQuestGiver::UpdateQuestSign(UObjective* InObjective)
{
	UpdateQuestSign();
}

void AQuestGiver::UpdateQuestSign(const AQuest* InQuest)
{
	UpdateQuestSign();
}

void AQuestGiver::Interact_Implementation(AActor* InteractionInstigator)
{
	if(!InteractionInstigator)
		return;

	UQuestManager* QuestManager = Cast<UQuestManager>(InteractionInstigator->GetComponentByClass(UQuestManager::StaticClass()));

	if (!QuestManager)
		return;

	QuestManager->OnActiveQuestChanged.AddUObject(this, &AQuestGiver::UpdateQuestSign);
	TArray<AActor*> AttachedActors; 
	GetAttachedActors(AttachedActors);

	for(const auto& Actor : AttachedActors)
	{
		AQuest* Quest = Cast<AQuest>(Actor);
		if(!Quest)
			continue;

		if(Quest->IsTaken())
			continue;

		if(Quest->GetPrerequisiteQuest())
		{
			if(!Quest->GetPrerequisiteQuest()->IsCompleted())
				continue;
		}

		if(QuestDialogueWidgetClass)
		{
			UQuestDialogueWidget* QuestDialogueWidget = CreateWidget<UQuestDialogueWidget>(GetWorld(), QuestDialogueWidgetClass);

			QuestDialogueWidget->Init(Quest);
			QuestDialogueWidget->OnQuestAccepted.BindUObject(QuestManager, &UQuestManager::AddQuest, Quest);
			
			QuestDialogueWidget->OnDialogueExit.BindLambda([this, InteractionInstigator]()
			{
				NotifyInteractionFinished(this, InteractionInstigator);
			});

			QuestDialogueWidget->AddToViewport();
			return;
		}

		NotifyInteractionFinished(this, InteractionInstigator);
	}
	UpdateQuestSign();
}

void AQuestGiver::NotifyInteractionFinished(AActor* InteractableActor, AActor* InteractionInstigator)
{
	UpdateQuestSign();

	Super::NotifyInteractionFinished(InteractableActor, InteractionInstigator);

};
