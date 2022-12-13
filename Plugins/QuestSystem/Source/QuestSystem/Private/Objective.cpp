// Fill out your copyright notice in the Description page of Project Settings.


#include "Objective.h"
#include "BaseInteractionActor.h"
#include "InteractableActor.h"
#include "QuestLocationMarker.h"

//ObjectiveType

UInteractionObjective::UInteractionObjective()
{
	ObjectiveType = EObjectiveType::OT_Interaction;
}

ULocationObjective::ULocationObjective()
{
	ObjectiveType = EObjectiveType::OT_Location;
}


void UInteractionObjective::ActivateObjective(AActor* QuestInstigator)
{
	if(IInteractableActor* InteractionActor = Cast<IInteractableActor>(InteractionObjectiveActor))
		InteractionActor->OnInteractionFinished.AddLambda([this, QuestInstigator](
			AActor* InteractibleObject, const AActor* InteractingActor)
		{
			if(CanBeCompleted && QuestInstigator == InteractingActor) //actor, who interacted is the same that took quest
			{
				IsCompleted = true; //set after interaction triggered delegate, which, in turn, triggered this lambda 
				if(OnObjectiveCompleted.IsBound())
					OnObjectiveCompleted.Broadcast(this);
			}
		});
}

void ULocationObjective::ActivateObjective(AActor* QuestInstigator)
{
	if(AQuestLocationMarker* LocationActor = Cast<AQuestLocationMarker>(LocationObjective))
	{
		LocationActor->OnLocationReached.AddLambda([this, QuestInstigator](AActor* LocationMarkerActor, AActor* OverlappedActor)
		{
			if(OverlappedActor == QuestInstigator && CanBeCompleted)
			{
				IsCompleted = true;
				if(OnObjectiveCompleted.IsBound())
					OnObjectiveCompleted.Broadcast(this);
			}
		});
	}
}