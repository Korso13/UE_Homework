// Fill out your copyright notice in the Description page of Project Settings.


#include "DraggableListWidget.h"
#include "FruitDragDropOperation.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "components/TextBlock.h"
#include "components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"

#include "Kismet/GameplayStatics.h"

void UDraggableListWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (NameText)
	{
		NameText->SetText(FruitName);
	}
}

void UDraggableListWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (NameText)
	{
		NameText->SetText(FruitName);
	}
}

FReply UDraggableListWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (Cast<UVerticalBox>(GetParent()) && InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
	{
		return UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent, this, EKeys::LeftMouseButton).NativeReply;
	}
	return FReply::Handled();
}

void UDraggableListWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation)
{
	OutOperation = UWidgetBlueprintLibrary::CreateDragDropOperation(UFruitDragDropOperation::StaticClass());
	UFruitDragDropOperation* FruitDragDropOperation = Cast<UFruitDragDropOperation>(OutOperation);
	
	if (FruitDragDropOperation)
	{
		FruitDragDropOperation->DefaultDragVisual = CreateWidget(this, GetClass());
		Cast<UDraggableListWidget>(FruitDragDropOperation->DefaultDragVisual)->FruitName = this->NameText->GetText();
		Cast<UDraggableListWidget>(FruitDragDropOperation->DefaultDragVisual)->NameText->SetText(this->NameText->GetText());
		
		FruitDragDropOperation->OriginalWidget = this;

		SetColorAndOpacity(FLinearColor(1.f, 1.f, 1.f, 0.7f));
		SetVisibility(ESlateVisibility::SelfHitTestInvisible);

		FruitDragDropOperation->OnDragCancelled.AddDynamic(this, &UDraggableListWidget::OnDragCancelledHandle);
	}
	else
	{
		Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);
	}
}

bool UDraggableListWidget::NativeOnDragOver(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	auto verticalBox = Cast<UVerticalBox>(GetParent());
	UFruitDragDropOperation* FruitDragDropOperation = Cast<UFruitDragDropOperation>(InOperation);

	if (FruitDragDropOperation && 
		verticalBox && 
		FruitDragDropOperation->OriginalWidget &&
		this != FruitDragDropOperation->OriginalWidget)
	{
		int32 IndexDragged = verticalBox->GetChildIndex(FruitDragDropOperation->OriginalWidget);

		if (IndexDragged >= 0)
		{
			verticalBox->RemoveChildAt(IndexDragged);
			
			const TArray<UWidget*> VBChildren = verticalBox->GetAllChildren();
			verticalBox->ClearChildren();

			for (int32 Counter = 0; Counter < VBChildren.Num(); Counter++)
			{
				if (VBChildren[Counter] == this)
				{
					FVector2D DraggedWidgetPosition = FruitDragDropOperation->DefaultDragVisual->GetCachedGeometry().GetAbsolutePosition(); 
					FVector2D CurrentWidgetPosition = InGeometry.GetAbsolutePositionAtCoordinates(FVector2D(0.5f, 0.5f));
					//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, FString::Printf(TEXT("DraggedWidget Y is: %f, UnderlayingWidget Y is: %f"), DraggedWidgetPosition.Y, CurrentWidgetPosition.Y), true);

					if (DraggedWidgetPosition.Y > CurrentWidgetPosition.Y)
					{
						verticalBox->AddChildToVerticalBox(FruitDragDropOperation->OriginalWidget)->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Center);
						verticalBox->AddChildToVerticalBox(VBChildren[Counter])->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Center);
					}
					else
					{
						verticalBox->AddChildToVerticalBox(VBChildren[Counter])->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Center);
						verticalBox->AddChildToVerticalBox(FruitDragDropOperation->OriginalWidget)->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Center);
					}
				}
				else
				{
					verticalBox->AddChildToVerticalBox(VBChildren[Counter])->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Center);
				}
			}
		}
	}
	return Super::NativeOnDragOver(InGeometry, InDragDropEvent, InOperation);
}

bool UDraggableListWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	if (InOperation && InOperation->DefaultDragVisual)
	{
		OnDragCancelledHandle(InOperation);
		return true;
	}
	return Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);
}


void UDraggableListWidget::OnDragCancelledHandle(UDragDropOperation* Operation)
{
	SetColorAndOpacity(FLinearColor(1.f, 1.f, 1.f, 1.f));
	SetVisibility(ESlateVisibility::Visible);
}


