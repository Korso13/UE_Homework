// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Toolkits/BaseToolkit.h"

class SColorBlock;
class SColorPicker;

class FQuestNPCSelectorEdModeToolkit : public FModeToolkit
{
public:

	FQuestNPCSelectorEdModeToolkit();
	
	/** FModeToolkit interface */
	virtual void Init(const TSharedPtr<IToolkitHost>& InitToolkitHost) override;

	/** IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual class FEdMode* GetEditorMode() const override;
	virtual TSharedPtr<class SWidget> GetInlineContent() const override { return ToolkitWidget; }

	/*FColor GetQuestNPCHighlightColor() const {return QuestNPCHighlightColor;}
	FColor GetObjectiveHighlightColor() const {return QuestObjectiveHighlightColor;}*/
	
private:
	/*FColor QuestNPCHighlightColor;
	FColor QuestObjectiveHighlightColor;*/
	TSharedPtr<SWidget> ToolkitWidget;
	TSharedPtr<SColorBlock> NPCColorBlockPicker;
	TSharedPtr<SColorBlock> ObjectiveColorBlockPicker;

	FLinearColor LastNPCColorPicked;
	FLinearColor LastObjectiveColorPicked;

	void OnQuestNPCHighlightColorChanged(FLinearColor InColor);
	void OnQuestObjectiveHighlightColorChanged(FLinearColor InColor);

	FLinearColor OnNewNPCColorPicked() const {return LastNPCColorPicked;};
	FLinearColor OnNewObjectiveColorPicked() const {return LastObjectiveColorPicked;};
	
	FPointerEventHandler NPCColorPickerMouseDownHandler;
	FPointerEventHandler ObjectiveColorPickerMouseDownHandler;
	FReply CallColorPicker(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, bool bNPCPicker);
};
