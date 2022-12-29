// Copyright Epic Games, Inc. All Rights Reserved.

#include "QuestEditor/Public/QuestEditorCommands.h"

#define LOCTEXT_NAMESPACE "FQuestEditorModule"

void FQuestEditorCommands::RegisterCommands()
{
	UI_COMMAND(OpenQuestEditor, "QuestEditor", "Open QuestEditor tab", EUserInterfaceActionType::Button, FInputChord(EKeys::Q, false, true, false, false));
}

#undef LOCTEXT_NAMESPACE
