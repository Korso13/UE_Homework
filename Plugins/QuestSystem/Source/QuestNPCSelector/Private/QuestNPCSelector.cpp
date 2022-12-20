// Copyright Epic Games, Inc. All Rights Reserved.

#include "QuestNPCSelector.h"
#include "QuestNPCSelectorEdMode.h"

#define LOCTEXT_NAMESPACE "FQuestNPCSelectorModule"

void FQuestNPCSelectorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FEditorModeRegistry::Get().RegisterMode<FQuestNPCSelectorEdMode>(FQuestNPCSelectorEdMode::EM_QuestNPCSelectorEdModeId, LOCTEXT("QuestNPCSelectorEdModeName", "QuestNPCSelectorEdMode"), FSlateIcon(), true);
}

void FQuestNPCSelectorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FEditorModeRegistry::Get().UnregisterMode(FQuestNPCSelectorEdMode::EM_QuestNPCSelectorEdModeId);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FQuestNPCSelectorModule, QuestNPCSelector)