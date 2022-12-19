// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Views/TableViewTypeTraits.h"
#include "Modules/ModuleManager.h"
#include "Types/SlateEnums.h"
#include "Widgets/Views/STableRow.h"

class SMultiLineEditableTextBox;
class SEditableText;
class SEditableTextBox;
class SWidget;
class AQuest;
class UQuestListEntry;
class FToolBarBuilder;
class FMenuBuilder;
class FReply;
class ITableRow;

DECLARE_MULTICAST_DELEGATE_OneParam(FOnNewQuestSelected, AQuest* )

class FQuestEditorModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command (by default it will bring up plugin window) */
	void QuestEditorCalled();
	
private:

	void RegisterMenus();

	TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);

	AQuest* SelectedQuest;

	TArray<TSharedPtr<AQuest>> Quests;

	FOnNewQuestSelected OnNewQuestSelected;

	TSharedPtr<SEditableTextBox> QuestName;
	TSharedPtr<SMultiLineEditableTextBox> QuestDescription;
	TSharedPtr<SListView<TSharedPtr<AQuest>>> QuestList;
	
	void AddMenuExtension(FMenuBuilder& Builder);

	void QuestSelected(TSharedPtr<AQuest> InEntry, ESelectInfo::Type SelectInfo);

	TSharedRef<ITableRow> CreateListRow(TSharedPtr<AQuest> InEntry, const TSharedRef<class STableViewBase>& Owner);

	FReply FilterQuestsFromSelection();

	FReply ExtractAllQuestsOnLevel();
	
	TSharedPtr<class FUICommandList> PluginCommands;
};
