// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestManager.generated.h"

class UQuestBoard;
class AQuest;
class UCurrentObjectivesWidget;

DECLARE_MULTICAST_DELEGATE_OneParam(FOnActiveQuestChanged, const AQuest* /*New active quest*/);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class QUESTSYSTEM_API UQuestManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UQuestManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	UCurrentObjectivesWidget* ActiveQuestWidget;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UQuestBoard> QuestBoardWidgetClass;

	void SwitchQuestBoard();
	
private:
	UPROPERTY()
	TArray<AQuest*> TakenQuests;

	UPROPERTY()
	AQuest* ActiveQuest;

	UPROPERTY()
	UQuestBoard* QuestBoardWidget;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddQuest(AQuest* InQuest);

	FOnActiveQuestChanged OnActiveQuestChanged;

	//Setters:
	void SetActiveQuest(AQuest* NewActiveQuest);

	//Getters:
	AQuest* GetActiveQuest() const {return ActiveQuest;};

	const TArray<AQuest*>& GetQuests() const {return TakenQuests;};

	UPROPERTY(EditAnywhere)
	TSubclassOf<UCurrentObjectivesWidget> CurrentObjectivesWidgetClass;
};
