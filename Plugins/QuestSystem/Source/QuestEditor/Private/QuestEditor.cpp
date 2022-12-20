// Copyright Epic Games, Inc. All Rights Reserved.

#include "QuestEditor/Public/QuestEditor.h"

#include "AdvancedQuest.h"
#include "EngineUtils.h"
#include "QuestEditor/Public/QuestEditorStyle.h"
#include "QuestEditor/Public/QuestEditorCommands.h"
#include "Quest.h"
#include "LevelEditor.h"
#include "SelectionSet.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"
#include "Engine/Selection.h"
#include "Kismet/GameplayStatics.h"
#include "Slate/Private/Framework/MultiBox/SEditableTextBlock.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SEditableText.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"
#include "Widgets/Layout/SScaleBox.h"
#include "Widgets/Views/STableRow.h"

static const FName QuestEditorTabName("QuestEditor");

#define LOCTEXT_NAMESPACE "FQuestEditorModule"

void FQuestEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FQuestEditorStyle::Initialize();
	FQuestEditorStyle::ReloadTextures();

	FQuestEditorCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	//for binding UI button to commands
	PluginCommands->MapAction(
		FQuestEditorCommands::Get().OpenQuestEditor,
		FExecuteAction::CreateRaw(this, &FQuestEditorModule::QuestEditorCalled),
		FCanExecuteAction()
		);

	//UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FQuestEditorModule::RegisterMenus));

	//registering Editor tab under name set in QuestEditorTabName
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(QuestEditorTabName, FOnSpawnTab::CreateRaw(this, &FQuestEditorModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FQuestEditorTabTitle", "QuestEditor"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

	//placing UI button 
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender);

		MenuExtender->AddMenuExtension("Miscellaneous", 
		EExtensionHook::After,
		PluginCommands, 
		FMenuExtensionDelegate::CreateRaw(this, &FQuestEditorModule::AddMenuExtension)
		);

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}

}

void FQuestEditorModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FQuestEditorCommands::Get().OpenQuestEditor);
}

void FQuestEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FQuestEditorStyle::Shutdown();

	FQuestEditorCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(QuestEditorTabName);

	if(QuestList.IsValid())
		QuestList->Invalidate(EInvalidateWidgetReason::Layout);

	if(QuestName.IsValid())
		QuestName->Invalidate(EInvalidateWidgetReason::Layout);

	if(QuestDescription.IsValid())
		QuestDescription->Invalidate(EInvalidateWidgetReason::Layout);
	
	SelectedQuest = nullptr;

	Quests.Empty();

	
}

//Quest editor tab's Slate code:
TSharedRef<SDockTab> FQuestEditorModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	//setting up font settings and Quest list selector delegate to load selected quest data
	OnNewQuestSelected.AddLambda([this](const AQuest* InQuest)
	{
		if(InQuest && QuestName.IsValid() && QuestDescription.IsValid())
		{
			QuestDescription->SetText(InQuest->GetQuestDescription());
			QuestName->SetText(InQuest->GetQuestName());
		}
	});
	
	FSlateFontInfo DescriptionFontInfo = FQuestEditorStyle::Get().GetFontStyle(TEXT("NormalFont"));
	FSlateFontInfo NameFontInfo = FQuestEditorStyle::Get().GetFontStyle(TEXT("BoldFont"));
	DescriptionFontInfo.Size = 16;
	NameFontInfo.Size = 22;

	//Quest editor tab's slate code:
	
	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SVerticalBox)
			+SVerticalBox::Slot() //Button Box
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot() //find quests among selected
				[
					SNew(SButton)
					[
						SNew(STextBlock)
						.Text(FText::FromString(FString{"Filter out Quests"}))
						.Justification(ETextJustify::Center)
					]
					.OnClicked_Raw(this, &FQuestEditorModule::FilterQuestsFromSelection)
					.VAlign(VAlign_Center)
					.DesiredSizeScale(FVector2D{100, 20})
				]
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Fill)
				
				+SHorizontalBox::Slot() //find all quests
				[
					SNew(SButton)
					[
						SNew(STextBlock)
						.Text(FText::FromString(FString{"Get all Quests"}))
						.Justification(ETextJustify::Center)
					]
					.OnClicked_Raw(this, &FQuestEditorModule::ExtractAllQuestsOnLevel)
					.VAlign(VAlign_Center)
					.DesiredSizeScale(FVector2D{100, 20})
				]
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Fill)
			]   //end of Button Box contents
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Fill)
			.FillHeight(TAttribute<float>(0.025))

			+SVerticalBox::Slot()//Quest selector, editor, viewer
			[
				SNew(SHorizontalBox) //QuestEditor
				+SHorizontalBox::Slot() //Quest List
				[
					SAssignNew(QuestList, SListView<TSharedPtr<AQuest>>)
					.OnSelectionChanged_Raw(this, &FQuestEditorModule::QuestSelected)
					.ListItemsSource(&Quests)
					.OnGenerateRow_Raw(this, &FQuestEditorModule::CreateListRow)
				]
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.FillWidth(TAttribute<float>(0.2))

				+SHorizontalBox::Slot() //Quest editor main panel
				[
					SNew(SVerticalBox)
					/*here should be either SMultiColumnTableRow or a set of other slate widgets to edit selected quest.
					 *Any added widgets must be bound for update in lambda at the top of this function!*/
					/*+SVerticalBox::Slot()
					[
						SNew(SMultiColumnTableRow<AQuest*>)
					]
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					.FillHeight(TAttribute<float>(0.3))*/
					
					+SVerticalBox::Slot() //Quest name
					[
						SAssignNew(QuestName, SEditableTextBox)
						.OnTextCommitted_Lambda([this](const FText& Text, ETextCommit::Type& Type)
						{
							if(SelectedQuest)
								SelectedQuest->SetQuestName(Text);
						})
						.Font(NameFontInfo)
					]
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					.FillHeight(TAttribute<float>(0.1))
					.Padding(10.f, 10.f, 10.f, 10.f)
					
					+SVerticalBox::Slot() //Quest Description
					[
						SAssignNew(QuestDescription, SMultiLineEditableTextBox)
						.OnTextCommitted_Lambda([this](const FText& Text, ETextCommit::Type& Type)
						{
							if(SelectedQuest)
								SelectedQuest->SetQuestDescription(Text);
						})
						.Font(DescriptionFontInfo)
						.WrappingPolicy(ETextWrappingPolicy::DefaultWrapping)
						.AutoWrapText(1)
					]
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					.FillHeight(TAttribute<float>(0.5))
					.Padding(10.f, 10.f, 10.f, 10.f)
				] //end of Quest editor main panel
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.FillWidth(TAttribute<float>(0.8))
			] // end of Quest selector, editor, viewer
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.FillHeight(TAttribute<float>(0.9))
		]; //end of SDockTab and Quest editor tab's slate code
}

void FQuestEditorModule::QuestEditorCalled()
{
	FGlobalTabmanager::Get()->TryInvokeTab(QuestEditorTabName);
}

//called whenever new quest is selected in the QuestList
void FQuestEditorModule::QuestSelected(TSharedPtr<AQuest> InEntry, ESelectInfo::Type SelectInfo)
{
	if(InEntry.IsValid())
	{
		SelectedQuest = InEntry.Get();
		if(OnNewQuestSelected.IsBound())
			OnNewQuestSelected.Broadcast(SelectedQuest);
	}
}

//delegate func for button filtering out quests out of teh selection
FReply FQuestEditorModule::FilterQuestsFromSelection()
{
	if (GEditor)
	{
		Quests.Empty();
		for (FSelectionIterator Iter((GEditor->GetSelectedActorIterator())); Iter; ++Iter)
		{
			AQuest* Quest = Cast<AQuest>(*Iter);
			if (Quest)
			{
				Quests.Add(TSharedPtr<AQuest>(Quest));
			}
		}
	}

	if(QuestList.IsValid())
	{
		QuestList->RebuildList();
	}
	
	return FReply::Handled();
}

//delegate func for getting all quests on teh level
FReply FQuestEditorModule::ExtractAllQuestsOnLevel()
{
	if (GEditor)
	{
		Quests.Empty();
		
		TArray<AActor*> GatheredActors;

		TIndirectArray<FWorldContext> World = GEditor->GetWorldContexts(); //nessesary instead of regular GetWorld in the context of Editor use!!!
		UGameplayStatics::GetAllActorsOfClass(World[0].World(), AQuest::StaticClass(), GatheredActors);
		if(GatheredActors.Num() > 0)
		{
			for(auto& Actor : GatheredActors)
			{
				AQuest* Quest = Cast<AQuest>(Actor);
				if (Quest)
				{
					Quests.Add(TSharedPtr<AQuest>(Quest));
				}
			}
		}
	}
	
	if(QuestList.IsValid())
	{
		QuestList->RebuildList();
	}
	
	return FReply::Handled();
}

TSharedRef<ITableRow> FQuestEditorModule::CreateListRow(TSharedPtr<AQuest> InEntry, const TSharedRef<class STableViewBase>& Owner)
{
	if(InEntry.IsValid())
	{
		return
		SNew(STableRow<TSharedPtr<AQuest>>, Owner)
		.Padding(FMargin(5, 5, 5, 5))
		[
		   SNew(STextBlock)
		   .Text(InEntry->GetQuestName())
		];
	}
	else
	{
		return
		SNew(STableRow<TSharedPtr<AQuest>>, Owner)
		.Padding(FMargin(5, 5, 5, 5))
		[
			SNew(STextBlock)
			.Text(FText{})
		];
	}
}

void FQuestEditorModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	
	/*{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FQuestEditorCommands::Get().OpenQuestEditor, PluginCommands);
		}
	}
	

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FQuestEditorCommands::Get().OpenQuestEditor));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}*/
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FQuestEditorModule, QuestEditor)