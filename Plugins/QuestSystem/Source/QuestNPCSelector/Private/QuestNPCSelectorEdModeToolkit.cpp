// Copyright Epic Games, Inc. All Rights Reserved.

#include "QuestNPCSelectorEdModeToolkit.h"
#include "QuestNPCSelectorEdMode.h"
#include "Engine/Selection.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"
#include "EditorModeManager.h"

//#include "Customizations/ColorStructCustomization.h"
#include "Input/HittestGrid.h"
#include "Widgets/Colors/SColorBlock.h"
#include "Widgets/Colors/SColorPicker.h"

#define LOCTEXT_NAMESPACE "FQuestNPCSelectorEdModeToolkit"

FQuestNPCSelectorEdModeToolkit::FQuestNPCSelectorEdModeToolkit()
{
}

void FQuestNPCSelectorEdModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost)
{
	struct Locals
	{
		static bool IsWidgetEnabled()
		{
			return GEditor->GetSelectedActors()->Num() != 0;
		}

		/*static FReply OnButtonClick(FVector InOffset)
		{
			USelection* SelectedActors = GEditor->GetSelectedActors();

			// Let editor know that we're about to do something that we want to undo/redo
			GEditor->BeginTransaction(LOCTEXT("MoveActorsTransactionName", "MoveActors"));

			// For each selected actor
			for (FSelectionIterator Iter(*SelectedActors); Iter; ++Iter)
			{
				if (AActor* LevelActor = Cast<AActor>(*Iter))
				{
					// Register actor in opened transaction (undo/redo)
					LevelActor->Modify();
					// Move actor to given location
					LevelActor->TeleportTo(LevelActor->GetActorLocation() + InOffset, FRotator(0, 0, 0));
				}
			}

			// We're done moving actors so close transaction
			GEditor->EndTransaction();

			return FReply::Handled();
		}

		static TSharedRef<SWidget> MakeButton(FText InLabel, const FVector InOffset)
		{
			return SNew(SButton)
				.Text(InLabel)
				.OnClicked_Static(&Locals::OnButtonClick, InOffset);
		}*/
	};

	const float Factor = 256.0f;
	
	NPCColorPickerMouseDownHandler.BindRaw(this, &FQuestNPCSelectorEdModeToolkit::CallColorPicker, true);
	ObjectiveColorPickerMouseDownHandler.BindRaw(this, &FQuestNPCSelectorEdModeToolkit::CallColorPicker, false);

	OnQuestNPCHighlightColorChanged(FLinearColor::Yellow); //setting default color
	OnQuestObjectiveHighlightColorChanged(FLinearColor::Red);
	
	SAssignNew(ToolkitWidget, SBorder)
		[
			SNew(SVerticalBox) //vertical box holds actual widget contents
			/*+ SVerticalBox::Slot() 
			.AutoHeight()
			.HAlign(HAlign_Center)
			.Padding(50)*/
			
			+ SVerticalBox::Slot() //Quest NPC color picker here
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Text(FText::FromString("Quest NPC highlight color"))
						.Font(FStyleDefaults::GetFontInfo(12))
					]
					.FillWidth(1)
					.HAlign(HAlign_Left)
					.Padding(10,10, 15, 10)
					+ SHorizontalBox::Slot() //color picker goes here
					[
						SAssignNew(NPCColorBlockPicker, SColorBlock)
						.OnMouseButtonDown(NPCColorPickerMouseDownHandler)
						.Color(FLinearColor::Yellow)
						.Color_Raw(this, &FQuestNPCSelectorEdModeToolkit::OnNewNPCColorPicked)
						.Size(FVector2D(100,30))
						
					]
					.FillWidth(0.6f)
					.HAlign(HAlign_Right)
					.VAlign(VAlign_Center)
					.Padding(10)
				]
				.HAlign(HAlign_Fill)
				.AutoHeight()
				
			+ SVerticalBox::Slot() //Quest objectives color picker here
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Text(FText::FromString("Quest objectives highlight color"))
						.Font(FStyleDefaults::GetFontInfo(12))
					]
					.FillWidth(1)
					.HAlign(HAlign_Left)
					.Padding(10, 10, 15, 10)
					+ SHorizontalBox::Slot() //color picker goes here
					[
						SAssignNew(ObjectiveColorBlockPicker, SColorBlock)
						.OnMouseButtonDown(ObjectiveColorPickerMouseDownHandler)
						.Color(FLinearColor::Red)
						.Color_Raw(this, &FQuestNPCSelectorEdModeToolkit::OnNewObjectiveColorPicked)
						.Size(FVector2D(100,30))
					]
					.FillWidth(0.6f)
					.HAlign(HAlign_Right)
					.VAlign(VAlign_Center)
					.Padding(10)
				]
				.HAlign(HAlign_Fill)
				.AutoHeight()
				
		];//end of SBorder and widget
		
	FModeToolkit::Init(InitToolkitHost);
}

FName FQuestNPCSelectorEdModeToolkit::GetToolkitFName() const
{
	return FName("QuestNPCSelectorEdMode");
}

FText FQuestNPCSelectorEdModeToolkit::GetBaseToolkitName() const
{
	return NSLOCTEXT("QuestNPCSelectorEdModeToolkit", "DisplayName", "QuestNPCSelectorEdMode Tool");
}

void FQuestNPCSelectorEdModeToolkit::OnQuestNPCHighlightColorChanged(FLinearColor InColor)
{
	static_cast<FQuestNPCSelectorEdMode*>(GetEditorMode())->SetQuestNPCHighlightColor(InColor);
	/*SColorBlock::FArguments Args;
	Args.Color(InColor);
	NPCColorBlockPicker->Construct(Args);*/
	LastNPCColorPicked = InColor;
}

void FQuestNPCSelectorEdModeToolkit::OnQuestObjectiveHighlightColorChanged(FLinearColor InColor)
{
	static_cast<FQuestNPCSelectorEdMode*>(GetEditorMode())->SetQuestObjectiveHighlightColor(InColor);
	LastObjectiveColorPicked = InColor;
}

FReply FQuestNPCSelectorEdModeToolkit::CallColorPicker(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, bool bNPCPicker)
{
	FColorPickerArgs PickerArgs;
	
	PickerArgs.bUseAlpha = true;
	PickerArgs.bOnlyRefreshOnMouseUp = true;
	PickerArgs.bOnlyRefreshOnOk = true;
	PickerArgs.sRGBOverride = true;
	PickerArgs.DisplayGamma = TAttribute<float>::Create(TAttribute<float>::FGetter::CreateUObject(GEngine, &UEngine::GetDisplayGamma));
	if(bNPCPicker) //which highlight color are we changing with this color picker?
	{
		PickerArgs.OnColorCommitted = FOnLinearColorValueChanged::CreateSP(this, &FQuestNPCSelectorEdModeToolkit::OnQuestNPCHighlightColorChanged);
	}
	else
	{
		PickerArgs.OnColorCommitted = FOnLinearColorValueChanged::CreateSP(this, &FQuestNPCSelectorEdModeToolkit::OnQuestObjectiveHighlightColorChanged);
	}
	/*PickerArgs.OnColorPickerCancelled = FOnColorPickerCancelled::CreateSP(this,),
	PickerArgs.OnColorPickerWindowClosed = FOnWindowClosed::CreateSP(this, ),
	PickerArgs.OnInteractivePickBegin = FSimpleDelegate::CreateSP(this, ),
	PickerArgs.OnInteractivePickEnd = FSimpleDelegate::CreateSP(this, ),*/
	PickerArgs.InitialColorOverride = FLinearColor::White;
	PickerArgs.ParentWidget = ToolkitWidget;
	PickerArgs.OptionalOwningDetailsView = PickerArgs.ParentWidget;
	PickerArgs.bOpenAsMenu = true;
	
	OpenColorPicker(PickerArgs);

	return FReply::Handled();
}

class FEdMode* FQuestNPCSelectorEdModeToolkit::GetEditorMode() const
{
	return GLevelEditorModeTools().GetActiveMode(FQuestNPCSelectorEdMode::EM_QuestNPCSelectorEdModeId);
}

#undef LOCTEXT_NAMESPACE
