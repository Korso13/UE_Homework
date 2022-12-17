// Fill out your copyright notice in the Description page of Project Settings.


#include "Objective.h"
#include "BaseInteractionActor.h"
#include <mutex>
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
			if(CanBeCompleted() && QuestInstigator == InteractingActor) //actor, who interacted is the same that took quest
			{
				//set after interaction triggered delegate, which, in turn, triggered this lambda 
				SetCompleted();
				if(OnObjectiveCompleted.IsBound() && !bDidOnce)
				{
					OnObjectiveCompleted.Broadcast(this);
					bDidOnce = true;
				}
			}
		});
}

void ULocationObjective::ActivateObjective(AActor* QuestInstigator)
{
	if(AQuestLocationMarker* LocationActor = Cast<AQuestLocationMarker>(LocationObjective))
	{
		LocationActor->OnLocationReached.AddLambda([this, QuestInstigator](AActor* LocationMarkerActor, AActor* OverlappedActor)
		{
			if(OverlappedActor == QuestInstigator && CanBeCompleted())
			{
				SetCompleted();
				if(OnObjectiveCompleted.IsBound() && !bDidOnce)
				{
					OnObjectiveCompleted.Broadcast(this);
					bDidOnce = true;
				}
			}
		});
	}
}