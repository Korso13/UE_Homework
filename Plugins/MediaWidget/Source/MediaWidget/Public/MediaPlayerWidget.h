// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MediaPlayerWidget.generated.h"

class UImage;
class UMediaPlayer;
class UMediaSoundComponent;
class UButton;
/**
 * 
 */
UCLASS()
class MEDIAWIDGET_API UMediaPlayerWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidgetOptional))
	UImage* PlayerDisplay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInstanceDynamic* DynMaterial;

	UPROPERTY(meta=(BindWidgetOptional))
	UButton* OpenFileButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMediaPlayer* MediaPlayer;

	UPROPERTY()
	AActor* SoundActor;

	UPROPERTY()
	UMediaSoundComponent* Sound;

	UPROPERTY()
	TArray<UTexture2D*> Images;

	UPROPERTY()
	int32 SelectedFileIndex = 0;

	UFUNCTION(BlueprintCallable)
	void OpenNextFile();

	UFUNCTION(BlueprintCallable)
	void OpenPreviousFile();
	
public:
	UPROPERTY()
	FString PathToFile;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool MultipleFilesSelection;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString SupportedFileTypes = /*"All Files(*.PNG;*.JPG;*.MP4)|*.PNG;*.JPG;*.MP4|"*/
       "Image Files(*.PNG;*.JPG;)|*.PNG;*.JPG;|"
		"Video Files(*.MP4)|*.MP4";

	UFUNCTION(BlueprintCallable)
	virtual void OpenMedia();
};
