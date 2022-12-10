// Fill out your copyright notice in the Description page of Project Settings.


#include "MediaPlayerWidget.h"
#include "IDesktopPlatform.h"
#include "DesktopPlatformModule.h"
#include "Misc/Paths.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "Components/Image.h"
#include "Components/Button.h"

#include "Runtime/MediaAssets/Public/MediaSoundComponent.h"
#include "Runtime/MediaAssets/Public/MediaPlayer.h"
#include "Runtime/MediaAssets/Public/FileMediaSource.h"
#include "Runtime/MediaAssets/Public/MediaPlaylist.h"

void UMediaPlayerWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//MediaPlayer = CreateDefaultSubobject<UMediaPlayer>("Player Display");
	FActorSpawnParameters SpawnParams;
	SpawnParams.bNoFail = true;
	SoundActor = GetWorld()->SpawnActor<AActor>(SpawnParams);

	Sound = NewObject<UMediaSoundComponent>(SoundActor);
	Sound->RegisterComponent();
	SoundActor->SetActorHiddenInGame(false);
	PlayerDisplay->SetBrushFromMaterial(DynMaterial);
}

void UMediaPlayerWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if(auto* Pawn = GetWorld()->GetFirstPlayerController()->GetPawnOrSpectator())
		Sound->SetWorldLocation(Pawn->GetActorLocation());
}

void UMediaPlayerWidget::OpenMedia()
{
	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	if (DesktopPlatform)
	{
		TArray<FString> OutFileNames;
		auto* ParentHandle = FSlateApplication::Get().FindBestParentWindowHandleForDialogs(nullptr);
		DesktopPlatform->OpenFileDialog(ParentHandle, "Choose file to open...", "", "", SupportedFileTypes, MultipleFilesSelection, OutFileNames);
		if (OutFileNames.Num() > 0)
		{
			if (MediaPlayer)
				MediaPlayer->Pause();

			//checking if videos were selected
			if (FPaths::GetExtension(OutFileNames[0]) == "MP4" && MediaPlayer)
			{
				DynMaterial->SetScalarParameterValue("IsVideo", 1.f);
				Sound->SetMediaPlayer(MediaPlayer);
				PlayerDisplay->SetBrushFromMaterial(DynMaterial); //redundancy setter
				if (MultipleFilesSelection) //several files could have been selected
				{
					for (auto Path : OutFileNames)
					{
						MediaPlayer->GetPlaylist()->AddFile(Path);
					}
					MediaPlayer->OpenSource(MediaPlayer->GetPlaylist()->Get(0)); //playing the first file in playlist right away
					PlayerDisplay->SetBrushFromMaterial(DynMaterial);
				}
				else //only one file selected
				{
					PathToFile = OutFileNames[0];
					UFileMediaSource* MediaSource = NewObject<UFileMediaSource>();
					MediaSource->SetFilePath(PathToFile);
					MediaPlayer->OpenSource(MediaSource);
					PlayerDisplay->SetBrushFromMaterial(DynMaterial);
				}
			}
				
			//images were selected
			else
			{
				if (MediaPlayer)
					MediaPlayer->Pause();
				DynMaterial->SetScalarParameterValue("IsVideo", 0.f);
				PlayerDisplay->SetBrushFromMaterial(DynMaterial);
				if (MultipleFilesSelection) //several files could have been selected
				{
					UTexture2D* Texture;
					for (auto Path : OutFileNames)
					{
						Texture = UKismetRenderingLibrary::ImportFileAsTexture2D(GetWorld(), Path);
						Images.Add(Texture);
					}
					if(PlayerDisplay && Images.Num() > 0)
						DynMaterial->SetTextureParameterValue("StaticTexture", Images[0]);
					PlayerDisplay->SetBrushFromMaterial(DynMaterial);
				}
				else //only one file selected
				{
					PathToFile = OutFileNames[0];
					Images.Empty();
					Images.Add(UKismetRenderingLibrary::ImportFileAsTexture2D(this, PathToFile));
					if (Images[0] && PlayerDisplay)
					{
						DynMaterial->SetTextureParameterValue("StaticTexture", Images[0]);
						PlayerDisplay->SetBrushFromMaterial(DynMaterial);
						float X = Images[0]->PlatformData->SizeX;
						float Y = Images[0]->PlatformData->SizeY;
						FVector2D Size{ X, Y};
						PlayerDisplay->SetBrushSize(Size);
					}
				}
			}
		}
	}
}

void UMediaPlayerWidget::OpenNextFile()
{
	if (MultipleFilesSelection)
	{
		if (MediaPlayer->GetPlaylist()->Num() > 0)
			//videos loaded
		{
			if ((SelectedFileIndex + 1) < MediaPlayer->GetPlaylist()->Num())
			{
				SelectedFileIndex++;
				if (MediaPlayer)
					MediaPlayer->OpenSource(MediaPlayer->GetPlaylist()->Get(SelectedFileIndex));
			}
		}
		else if (Images.Num() > 0)
			//images loaded
		{
			if ((SelectedFileIndex + 1) < Images.Num())
			{
				SelectedFileIndex++;
				if (PlayerDisplay)
					DynMaterial->SetTextureParameterValue("StaticTexture", Images[SelectedFileIndex]);
			}
		}
	}
}

void UMediaPlayerWidget::OpenPreviousFile()
{
	if (MultipleFilesSelection)
	{
		if (MediaPlayer->GetPlaylist()->Num() > 0)
			//videos loaded
		{
			if (SelectedFileIndex != 0)
			{
				SelectedFileIndex--;
				if (MediaPlayer)
					MediaPlayer->OpenSource(MediaPlayer->GetPlaylist()->Get(SelectedFileIndex));
			}
		}
		else if (Images.Num() > 0)
			//images loaded
		{
			if (SelectedFileIndex != 0)
			{
				SelectedFileIndex--;
				if (PlayerDisplay)
					DynMaterial->SetTextureParameterValue("StaticTexture", Images[SelectedFileIndex]);
			}
		}
	}
}
