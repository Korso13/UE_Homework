// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveManager.h"
#include "GameFramework/SaveGame.h"
#include "TankSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "Tankogeddon/Base_Pawn.h"
#include "Tankogeddon/TankFactory.h"
#include "TankWithInventory.h"

void USaveManager::OnGameLoadedFunc(const FString& SlotName, const int32 UserIndex, USaveGame* SaveGame)
{
	CurrentSave = Cast<UTankSaveGame>(SaveGame);
	if (OnGameLoaded.IsBound())
	{
		OnGameLoaded.Broadcast(SlotName);
	}

	//Starting to restore game state from loaded save file
	if(UGameplayStatics::GetCurrentLevelName(GetWorld()) != CurrentSave->CurrentLevel)
	{
		UGameplayStatics::OpenLevel(GetWorld(), FName{CurrentSave->CurrentLevel});
	}

	//restoring player tank's state
	Cast<ATankWithInventory>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn())->LoadState(CurrentSave->TankPawnState);

	//removing Proceduraly Spawned Actors that may not exist in loaded save state. Those, which did will be respawned later in this function
	for(auto ToBeScrappedActor : ProceduralySpawnedActors)
	{
		if(ToBeScrappedActor)
		{
			ToBeScrappedActor->Destroy();
			ToBeScrappedActor->DisableComponentsSimulatePhysics();
			ToBeScrappedActor->SetActorEnableCollision(false);
			ToBeScrappedActor->SetHidden(true);
		}
	}
	ProceduralySpawnedActors.Empty();

	//restoring enemy pawns
	for(auto [PawnName, Pawn] : CurrentSave->EnemyPawns)
	{
		if(!Pawn.SavedPawn.IsValid() && !Pawn.IsDead)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Name = FName{PawnName};
			SpawnParams.Instigator = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn();
			SpawnParams.Owner = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn();
			Pawn.SavedPawn = GetWorld()->SpawnActor<ABase_Pawn>(Pawn.PawnClass, Pawn.PawnLocation, Pawn.PawnRotation, SpawnParams);
		}

		if(Pawn.SavedPawn.IsValid() && Pawn.IsDead) //pawn should be dead but is valid in as per pre-load world.
		{
			Pawn.SavedPawn->Destroy();
			Pawn.SavedPawn->SetHidden(true);
			Pawn.SavedPawn->SetActorEnableCollision(false);
			Pawn.SavedPawn->LoadState(Pawn);
			break;
		}

		if(Pawn.SavedPawn.IsValid()) //pawn is and should be alive, restoring previous state
		{
			Pawn.SavedPawn->LoadState(Pawn);
		}
	}

	//restoring interactive Actor-buildings (Only TankFactory for now, TODO: add satellite stations, depots, pickups (preferably via an interface)
	for(auto [BuildingName, Building] : CurrentSave->Buildings)
	{
		if(!Building.SavedBuilding.IsValid() && !Building.IsDestroyed) //in case building can be fully removed from level
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Name = FName{BuildingName};
			SpawnParams.Instigator = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn();
			SpawnParams.Owner = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn();
			Building.SavedBuilding = GetWorld()->SpawnActor<ABase_Pawn>(Building.BuildingClass, Building.BuildingLocation, Building.BuildingRotation, SpawnParams);
		}

		//restoring tank factory TODO: remake via interface for all buildings
		if(Building.SavedBuilding.IsValid())
		{
			Cast<ATankFactory>(Building.SavedBuilding)->LoadState(Building);
		}
	}
}

void USaveManager::OnGameSavedFunc(const FString& SlotName, const int32 UserIndex, bool bSuccess)
{
	if (OnGameSaved.IsBound())
	{
		OnGameSaved.Broadcast(SlotName);
	}
}

void USaveManager::UpateDynamicSaveData()
{
	if(!CurrentSave)
	{
		return;
	}

	ATankWithInventory* PlayerPawn = Cast<ATankWithInventory>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn());
	CurrentSave->TankPawnState.PawnLocation = PlayerPawn->GetActorLocation();
	CurrentSave->TankPawnState.PawnRotation = PlayerPawn->GetActorRotation();
	CurrentSave->TankPawnState.PlayerTotalScore = PlayerPawn->GetTotalScore();

	for(auto& [PawnName, Pawn ]: CurrentSave->EnemyPawns)
	{
		if(Pawn.SavedPawn.IsValid() && !Pawn.IsDead)
		{
			Pawn.PawnLocation = Pawn.SavedPawn->GetActorLocation();
			Pawn.PawnRotation = Pawn.SavedPawn->GetActorRotation();
		}
	}

	CurrentSave->CurrentLevel = UGameplayStatics::GetCurrentLevelName(GetWorld());
}

void USaveManager::Init()
{
	CurrentSave = Cast<UTankSaveGame>(UGameplayStatics::CreateSaveGameObject(UTankSaveGame::StaticClass()));
}

void USaveManager::SaveGame(const FString SlotName)
{
	FAsyncSaveGameToSlotDelegate AsyncSaveDelegate;
	AsyncSaveDelegate.BindUObject(this, &USaveManager::OnGameSavedFunc);
	UpateDynamicSaveData();
	
	UGameplayStatics::AsyncSaveGameToSlot(CurrentSave, SlotName, 0, AsyncSaveDelegate);
}

void USaveManager::LoadGame(const FString SlotName)
{
	if(!IsSaveGameExist(SlotName))
	{
		return;
	}

	FAsyncLoadGameFromSlotDelegate AsyncLoadDelegate;
	AsyncLoadDelegate.BindUObject(this, &USaveManager::OnGameLoadedFunc);

	UGameplayStatics::AsyncLoadGameFromSlot(SlotName, 0, AsyncLoadDelegate);
}

bool USaveManager::IsSaveGameExist(const FString& SlotName) const
{
	return UGameplayStatics::DoesSaveGameExist(SlotName, 0);
}
