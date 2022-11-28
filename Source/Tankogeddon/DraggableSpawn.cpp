// Fill out your copyright notice in the Description page of Project Settings.


#include "DraggableSpawn.h"
#include "SpawnerPanel.h" 
#include "Components/TextBlock.h"
#include "Components/PanelWidget.h"
#include "TankPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Turret.h"
#include "TankWithInventory.h"

void UDraggableSpawn::NativePreConstruct()
{
	Super::NativePreConstruct();
	
}

void UDraggableSpawn::NativeConstruct()
{
	Super::NativeConstruct();

	TurretCostWidget->SetText(FText::FromString(FString::Printf(TEXT("%d"), TurretCost)));

	PlayerController = Cast<ATankPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if(PlayerController)
		PlayerController->OnMouseButtonUp.AddUObject(this, &UDraggableSpawn::OnMouseButtonUp);

	Spawner = Cast<USpawnerPanel>(GetParent()->GetOuter()->GetOuter());
}

FReply UDraggableSpawn::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton) && Spawner)
	{
		int32 NantiteReserve = Spawner->GetNantiteCount();
		if (NantiteReserve >= TurretCost)
		{
			FActorSpawnParameters params;
			params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
			Turret = GetWorld()->SpawnActor<ATurret>(TurretClass, params);
			if(Turret)
				Turret->SetActorEnableCollision(false);

			SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 0.5f));
		}
	}
	return FReply::Handled();
}

void UDraggableSpawn::NativeTick(const FGeometry& InGeometry, float DeltaTime)
{
	Super::NativeTick(InGeometry, DeltaTime);

	if (Turret && PlayerController)
	{
		FVector MousePosition;
		FVector MouseDirection;

		PlayerController->DeprojectMousePositionToWorld(MousePosition, MouseDirection);

		FCollisionQueryParams TracerParams;
		TracerParams.AddIgnoredActor(Turret);
		TracerParams.AddIgnoredActor(PlayerController->GetPawn());

		FHitResult TracerResult;
		GetWorld()->LineTraceSingleByChannel(TracerResult, MousePosition, MousePosition + MouseDirection*1000000.f, ECollisionChannel::ECC_WorldStatic, TracerParams);
		if (TracerResult.bBlockingHit)
		{
			FVector FixHeight;
			FixHeight.Z = 75;
			Turret->SetActorLocation(TracerResult.Location + FixHeight);
		}
	}
}

void UDraggableSpawn::OnMouseButtonUp()
{
	if (Spawner && Turret)
	{
		Spawner->SetNaniteCount(Spawner->GetNantiteCount() - TurretCost);
		ATankWithInventory* Tank = Cast<ATankWithInventory>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
		if (Tank)
			Tank->SetNanites(Spawner->GetNantiteCount());
		Turret->SetActorEnableCollision(true);
		Turret = nullptr;
	}
	RestoreVisuals();
}


void UDraggableSpawn::RestoreVisuals()
{
	SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.f));
}
