// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Objective.generated.h"

UENUM()
enum class EObjectiveType :uint8
{
	OT_Location,
	OT_Interaction,
	OT_Extended
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnObjectiveCompleted, UObjective* /*Progressing quest*/)

/**
 * 
 */
UCLASS(Abstract)
class QUESTSYSTEM_API UObjective : public UObject
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere)
	EObjectiveType ObjectiveType;

	UPROPERTY(EditAnywhere)
	FText ObjectiveDescription;

	UPROPERTY(VisibleAnywhere)
	bool bCanBeCompleted = false;

	UPROPERTY(VisibleAnywhere)
	bool bIsCompleted = false;

	bool bDidOnce = false;
	
public:

	FOnObjectiveCompleted OnObjectiveCompleted;
	
	virtual void ActivateObjective(AActor* Instigator){}

	//getters:
	bool CanBeCompleted() const {return bCanBeCompleted;}

	bool IsCompleted() const {return bIsCompleted;}

	const FText& GetObjectiveDescription() const {return ObjectiveDescription;}

	//setters;
	void SetCanBeCompleted(bool InStatus) {bCanBeCompleted = InStatus;}

	void SetCompleted(){bIsCompleted = true;}
};

//Objective subtypes
class ABaseInteractionActor;

UCLASS()
class QUESTSYSTEM_API UInteractionObjective : public UObjective
{
	GENERATED_BODY()
public:
	UInteractionObjective();
	
protected:
	UPROPERTY(EditAnywhere/*, meta=(AllowedClasses="ABaseInteractionActor")*/)
	ABaseInteractionActor* InteractionObjectiveActor;

public:
	virtual void ActivateObjective(AActor* Instigator) override;
};

UCLASS()
class QUESTSYSTEM_API ULocationObjective : public UObjective
{
	GENERATED_BODY()
public:

	ULocationObjective();

protected:
	UPROPERTY(EditAnywhere/*, meta=(AllowedClasses="BP_QuestLocation")*/)
	AActor* LocationObjective;

public:
	virtual void ActivateObjective(AActor* Instigator) override;
};