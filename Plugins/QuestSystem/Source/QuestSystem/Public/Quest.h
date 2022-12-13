// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Quest.generated.h"

class UObjective;

DECLARE_MULTICAST_DELEGATE_OneParam(FOnQuestStatusChanged, AQuest* /*Progressing quest*/)

UCLASS()
class QUESTSYSTEM_API AQuest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText QuestName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText QuestDescription;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<UObjective*> Objectives;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsTaken;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsOrderedObjectives;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsMainQuest;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AQuest* PrerequisiteQuest;

	FOnQuestStatusChanged OnQuestStatusChanged;

	UFUNCTION()
	void OnObjectiveCompleted(UObjective* InObjective);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void TakeQuest(AActor* QuestTaker);

	UFUNCTION(BlueprintCallable, CallInEditor)
	void ResetLocation();

#if WITH_EDITOR
	UFUNCTION( CallInEditor)
	void AddInteractObjective();
	
	UFUNCTION( CallInEditor)
	void AddLocationObjective();

#endif
	
};
