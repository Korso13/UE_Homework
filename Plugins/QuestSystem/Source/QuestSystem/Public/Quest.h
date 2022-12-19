// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
/*#include "Quest."*/
/*#include "../../QuestSystem/Intermediate/Build/Win64/UE4Editor/Inc/QuestSystem/Quest.generated.h"*/
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
	bool bIsTaken;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIsOrderedObjectives;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIsMainQuest;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	bool bIsCompleted = false;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AQuest* PrerequisiteQuest;
	
	UFUNCTION()
	void OnObjectiveCompleted(UObjective* InObjective);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void TakeQuest(AActor* QuestTaker);

	FOnQuestStatusChanged OnQuestStatusChanged;

	//Getters:
	bool IsCompleted() const {return bIsCompleted;}

	bool IsTaken() const {return bIsTaken;}

	bool IsMainQuest() const {return bIsMainQuest;}

	bool IsOrderedObjectives() const {return bIsOrderedObjectives;}

	const AQuest* GetPrerequisiteQuest() const {return PrerequisiteQuest;}

	const TArray<UObjective*>& GetObjectives() const {return Objectives;}

	const FText& GetQuestName() const {return QuestName;}

	const FText& GetQuestDescription() const {return QuestDescription;}

	//Setters:
	void SetQuestName(FText InName) {QuestName = InName;}

	void SetQuestDescription(FText InDescription) {QuestDescription = InDescription;}
	
	//editor functions
	UFUNCTION(BlueprintCallable, CallInEditor)
	void ResetLocation();

#if WITH_EDITOR
	UFUNCTION( CallInEditor)
	void AddInteractObjective();
	
	UFUNCTION( CallInEditor)
	void AddLocationObjective();

#endif
	
};
