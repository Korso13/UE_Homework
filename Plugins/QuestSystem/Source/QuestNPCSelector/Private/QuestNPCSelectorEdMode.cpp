// Copyright Epic Games, Inc. All Rights Reserved.

#include "QuestNPCSelectorEdMode.h"
#include "QuestNPCSelectorEdModeToolkit.h"
#include "Toolkits/ToolkitManager.h"
#include "EditorModeManager.h"
#include "Objective.h"
#include "Quest.h"
#include "QuestGiver.h"
#include "Engine/Selection.h"
#include "Kismet/GameplayStatics.h"

const FEditorModeID FQuestNPCSelectorEdMode::EM_QuestNPCSelectorEdModeId = TEXT("EM_QuestNPCSelectorEdMode");

FQuestNPCSelectorEdMode::FQuestNPCSelectorEdMode()
{

}

FQuestNPCSelectorEdMode::~FQuestNPCSelectorEdMode()
{

}

void FQuestNPCSelectorEdMode::Enter()
{
	FEdMode::Enter();

	if (!Toolkit.IsValid() && UsesToolkits())
	{
		Toolkit = MakeShareable(new FQuestNPCSelectorEdModeToolkit);
		Toolkit->Init(Owner->GetToolkitHost());
		UpdateActorSelectionList();
	}
}

void FQuestNPCSelectorEdMode::Exit()
{
	if (Toolkit.IsValid())
	{
		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
		Toolkit.Reset();
	}

	// Call base Exit method to ensure proper cleanup
	FEdMode::Exit();
}

void FQuestNPCSelectorEdMode::ActorSelectionChangeNotify()
{
	FEdMode::ActorSelectionChangeNotify();

	UpdateActorSelectionList();
}

void FQuestNPCSelectorEdMode::UpdateActorSelectionList()
{
	SelectedActorList.Empty();

	USelection* ActorsSelection = GEditor->GetSelectedActors();

	for (FSelectionIterator Iter(*ActorsSelection); Iter; ++Iter)
	{
  
		if (AActor* LevelActor = Cast<AActor>(*Iter))
		{
			SelectedActorList.AddUnique(LevelActor);
		}
	}

	QuestGiversSelected = GetQuestGiversOrObjectives();
}

bool FQuestNPCSelectorEdMode::GetQuestGiversOrObjectives()
{
	TArray<AActor*> FoundQuests;
	TArray<const AQuestGiver*> FoundNPCs; //only for correct detection of selected QuestNPCs (in case they don't have quests attached)
	ActorsToHighlight.Empty();
	
	for(const auto LevelActor : SelectedActorList)
	{
		if(const AQuestGiver* QuestNPC = Cast<AQuestGiver>(LevelActor))
		{
			FoundNPCs.AddUnique(QuestNPC);
			QuestNPC->GetAttachedActors(FoundQuests, false);
		}
	}
	
	if(FoundNPCs.Num() > 0) //found QuestNPCs among selection. Objectives will be highlighted
	{
		for(const auto FoundQuest : FoundQuests)
		{
			if(const AQuest* Quest = Cast<AQuest>(FoundQuest))
			{
				for(const auto Objective : Quest->GetObjectives())
				{
					if(Objective->GetQuestActor() != nullptr)
					{
						ActorsToHighlight.AddUnique(Objective->GetQuestActor()); //adding objective to highlight
					}
				}
			}
		}

		return true; //Objectives will be highlighted
	}
	else //no Quest NPCs found among selected actors. Finding and highlighting all Quest NPCs on the level
	{
		if (GEditor)
		{
			TIndirectArray<FWorldContext> World = GEditor->GetWorldContexts(); //necessary instead of regular GetWorld in the context of Editor use!!!
			UGameplayStatics::GetAllActorsOfClass(World[0].World(), AQuestGiver::StaticClass(), ActorsToHighlight);
		}
		return false; //Quest NPCs will be highlighted
	}
}

void FQuestNPCSelectorEdMode::Render(const FSceneView* View, FViewport* Viewport, FPrimitiveDrawInterface* PDI)
{
	FEdMode::Render(View, Viewport, PDI);

	if(ActorsToHighlight.Num() > 0)
	{
		//determining render color based on what was selected for highlight in GetQuestGiversOrObjectives()
		FLinearColor RenderColor;
		if(QuestGiversSelected)
		{
			RenderColor = QuestObjectiveHighlightColor;
		}
		else
		{
			RenderColor = QuestNPCHighlightColor;
		}

		//rendering highlight
		for(const auto Actor : ActorsToHighlight)
		{
			DrawWireBox(PDI, Actor->GetComponentsBoundingBox(true), RenderColor, 0, 10.f);
		}
	}
}

void FQuestNPCSelectorEdMode::DrawHUD(FEditorViewportClient* ViewportClient, FViewport* Viewport,
	const FSceneView* View, FCanvas* Canvas)
{
	FEdMode::DrawHUD(ViewportClient, Viewport, View, Canvas);

	if(ActorsToHighlight.Num() > 0)
	{
		//determining render color based on what was selected for highlight in GetQuestGiversOrObjectives()
		FLinearColor RenderColor;
		if(QuestGiversSelected)
		{
			RenderColor = QuestObjectiveHighlightColor;
		}
		else
		{
			RenderColor = QuestNPCHighlightColor;
		}

		for(const auto HighlitedActor : ActorsToHighlight)
		{
			//getting coords of spot on top of highlight cube
			FBox Bounds = HighlitedActor->GetComponentsBoundingBox(true);
			FVector drawPos = Bounds.GetCenter() + FVector(0.f, 0.f, Bounds.GetExtent().Z);

			//converting to 2D and adjusting to screen resolution
			FVector2D PixelLocation;
			View->ScreenToPixel(View->WorldToScreen(drawPos), PixelLocation);
			PixelLocation /= ViewportClient->GetDPIScale();

			//rendering caption
			Canvas->DrawShadowedText(PixelLocation.X, PixelLocation.Y,
				FText::FromString(HighlitedActor->GetName()),
				GEngine->GetSmallFont(),
				RenderColor,
				FColor::Black);
		}
	}
}


bool FQuestNPCSelectorEdMode::UsesToolkits() const
{
	return true;
}




