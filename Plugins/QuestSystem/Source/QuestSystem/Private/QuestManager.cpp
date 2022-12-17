// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestManager.h"
#include "CurrentObjectivesWidget.h"
#include "Quest.h"
#include "QuestBoard.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UQuestManager::UQuestManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UQuestManager::BeginPlay()
{
	Super::BeginPlay();

	//initiating current objectives (of selected active quest) widget
	if(CurrentObjectivesWidgetClass)
		ActiveQuestWidget = CreateWidget<UCurrentObjectivesWidget>(GetWorld(), CurrentObjectivesWidgetClass, "Active Quest Widget");

	if(ActiveQuestWidget)
	{
		OnActiveQuestChanged.AddUObject(ActiveQuestWidget, &UCurrentObjectivesWidget::SetCurrentObjectives);
		
		if(ActiveQuest && OnActiveQuestChanged.IsBound())
			OnActiveQuestChanged.Broadcast(ActiveQuest);

		ActiveQuestWidget->AddToViewport();
	}

	if(QuestBoardWidgetClass)
	{
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->InputComponent->BindKey(EKeys::Tab, IE_Released, this, &UQuestManager::SwitchQuestBoard);
	}
}

void UQuestManager::SwitchQuestBoard()
{
	if(!QuestBoardWidget && QuestBoardWidgetClass)
	{
		QuestBoardWidget = CreateWidget<UQuestBoard>(GetWorld(), QuestBoardWidgetClass);
	}

	if(QuestBoardWidget)
	{
		if(QuestBoardWidget->IsInViewport())
		{
			QuestBoardWidget->RemoveFromViewport();
		}
		else
		{
			QuestBoardWidget->Init(this);
			QuestBoardWidget->AddToViewport();
		}
	}
}


// Called every frame
void UQuestManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

//called by quest-giver via QuestDialogueWidget passing the AQuest they have
void UQuestManager::AddQuest(AQuest* InQuest)
{
	if(!InQuest)
		return;

	TakenQuests.AddUnique(InQuest);
	InQuest->TakeQuest(GetOwner());
	
	if(!ActiveQuest || ActiveQuest->IsCompleted())
	{
		ActiveQuest = InQuest;
		if(ActiveQuest && OnActiveQuestChanged.IsBound())
			OnActiveQuestChanged.Broadcast(ActiveQuest);
	}

	InQuest->OnQuestStatusChanged.AddLambda([this](AQuest* NewQuest)
	{
		if(NewQuest == ActiveQuest)
		{
			if(ActiveQuest && OnActiveQuestChanged.IsBound())
				OnActiveQuestChanged.Broadcast(ActiveQuest); //prompting active quest widget to reload objectives
		}
	});
	
}

void UQuestManager::SetActiveQuest(AQuest* NewActiveQuest)
{
	if(TakenQuests.Contains(NewActiveQuest))
	{
		ActiveQuest = NewActiveQuest;
		if(ActiveQuest && OnActiveQuestChanged.IsBound())
			OnActiveQuestChanged.Broadcast(ActiveQuest); 
	}
}

