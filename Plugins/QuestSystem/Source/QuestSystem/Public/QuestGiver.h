// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseInteractionActor.h"
#include "QuestGiver.generated.h"

class AQuest;
class UObjective;
class UWidgetComponent;
class UUserWidget;
class UQuestDialogueWidget;
class USceneComponent;
/**
 * 
 */
UCLASS()
class QUESTSYSTEM_API AQuestGiver : public ABaseInteractionActor
{
	GENERATED_BODY()

public:
	AQuestGiver();
	
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USceneComponent* SceneComponent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UWidgetComponent* QuestAvailableSign;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DeprecatedProperty))
	TSubclassOf<UUserWidget> QuestSignWidgetClass;
	
public:

	virtual void BeginPlay() override;

	void UpdateQuestSign();

	void UpdateQuestSign(UObjective* InObjective);

	void UpdateQuestSign(const AQuest* InQuest);
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UQuestDialogueWidget> QuestDialogueWidgetClass;

	virtual void Interact_Implementation(AActor* InteractionInstigator) override;

	virtual void NotifyInteractionFinished(AActor* InteractableActor, AActor* InteractionInstigator) override;
};
