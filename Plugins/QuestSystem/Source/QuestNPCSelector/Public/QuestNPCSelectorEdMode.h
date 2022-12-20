// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EdMode.h"

class FQuestNPCSelectorEdMode : public FEdMode
{
private:

	TArray<AActor*> SelectedActorList;

	TArray<AActor*> ActorsToHighlight;

	bool QuestGiversSelected; //if true - highlight objectives, if false - highlight all Quest NPCs on level

	bool GetQuestGiversOrObjectives();

	FLinearColor QuestNPCHighlightColor;
	FLinearColor QuestObjectiveHighlightColor;
	
public:
	const static FEditorModeID EM_QuestNPCSelectorEdModeId;

	FQuestNPCSelectorEdMode();
	virtual ~FQuestNPCSelectorEdMode();

	// FEdMode interface
	virtual void Enter() override;
	virtual void Exit() override;
	bool UsesToolkits() const override;
	// End of FEdMode interface

	virtual void Render(const FSceneView* View, FViewport* Viewport, FPrimitiveDrawInterface* PDI) override;
	virtual void ActorSelectionChangeNotify() override;
	virtual void DrawHUD(FEditorViewportClient* ViewportClient, FViewport* Viewport, const FSceneView* View, FCanvas* Canvas) override;

	void UpdateActorSelectionList();

	void SetQuestNPCHighlightColor(FLinearColor InColor) { QuestNPCHighlightColor = InColor;};
	void SetQuestObjectiveHighlightColor(FLinearColor InColor) { QuestObjectiveHighlightColor = InColor;};
};



