// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedObjectives.h"

#include "DestructibleGoal.h"
#include "Tankogeddon/Scorable.h"

UAdvancedObjectives::UAdvancedObjectives()
{
	ObjectiveType = EObjectiveType::OT_Extended;
}

UDestroyObjective::UDestroyObjective()
{
	EObjectiveTypeAdvanced = EObjectiveTypeAdvanced::OT_Destruction;
}

void UDestroyObjective::ActivateObjective(AActor* QuestInstigator)
{
	if(IDestructibleGoal* Destructible = Cast<IDestructibleGoal>(QuestTarget))
	{
		Destructible->OnTargetDestroyed.AddLambda([this, QuestInstigator](const AActor* DestroyedActor, const AActor* Destructor)
		{
			if(DestroyedActor == QuestTarget && CanBeCompleted() && Destructor == QuestInstigator)
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

AActor* UDestroyObjective::GetQuestActor() const
{
	return QuestTarget;
}

UScoreObjective::UScoreObjective()
{
	EObjectiveTypeAdvanced = EObjectiveTypeAdvanced::OT_Score;
}

void UScoreObjective::ActivateObjective(AActor* QuestInstigator)
{
	if(IScorable* ScoringTank = Cast<IScorable>(QuestInstigator))
	{
		ScoringTank->OnScoredKill.AddLambda([this, QuestInstigator](const FScoredKillData KillData)
		{
			CurrentScore += KillData.ScoreValue;
			if(CanBeCompleted() && CurrentScore >= ScoreTarget && KillData.Killer == QuestInstigator)
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
