// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest.h"

#include "Objective.h"

// Sets default values
AQuest::AQuest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AQuest::BeginPlay()
{
	Super::BeginPlay();
	
}

void AQuest::OnObjectiveCompleted(UObjective* InObjective)
{
	if(bIsOrderedObjectives)
	{
		int32 ObjectiveIndex;
		if(Objectives.Find(InObjective, ObjectiveIndex) && Objectives.IsValidIndex(ObjectiveIndex + 1))
		{
			Objectives[ObjectiveIndex + 1]->SetCanBeCompleted(true); //open next objective for completion
		}
		else
		{
			bIsCompleted = true;
		}
	}

	if(OnQuestStatusChanged.IsBound())
	{
		OnQuestStatusChanged.Broadcast(this); //notify any subscribers about change in quest status
	}
}

// Called every frame
void AQuest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AQuest::TakeQuest(AActor* QuestTaker)
{
	if(bIsTaken)
		return;

	if(Objectives.Num() > 0)
	{
		for (size_t i = 0; i<Objectives.Num(); i++)
		{
			if(Objectives[i])
			{
				Objectives[i]->ActivateObjective(QuestTaker);
				Objectives[i]->SetCanBeCompleted(!bIsOrderedObjectives || i == 0);
				Objectives[i]->OnObjectiveCompleted.AddUObject(this, &AQuest::OnObjectiveCompleted);
			}
		}
	}

	AttachToActor(QuestTaker,FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	bIsTaken = true;
}

//resets Quest's location to that of parent that took it
void AQuest::ResetLocation()
{
	const AActor* ParentActor = GetAttachParentActor();
	if(ParentActor)
	{
		SetActorLocation(ParentActor->GetActorLocation());		
	}
}

//editor buttons to add extra objectives to selected quest
#if WITH_EDITOR
void AQuest::AddInteractObjective()
{
	Objectives.Add(NewObject<UInteractionObjective>(this));
}

void AQuest::AddLocationObjective()
{
	Objectives.Add(NewObject<ULocationObjective>(this));
}
#endif

