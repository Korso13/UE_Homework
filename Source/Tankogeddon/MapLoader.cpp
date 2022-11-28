// Fill out your copyright notice in the Description page of Project Settings.


#include "MapLoader.h"

#include "Kismet/GameplayStatics.h"
#include "TankWithInventory.h"

// Sets default values
AMapLoader::AMapLoader()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SCP = CreateDefaultSubobject<USceneComponent>(TEXT("Scene component"));
	RootComponent = SCP;
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetupAttachment(SCP);

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body Mesh"));
	BodyMesh->SetupAttachment(SCP);

	ActiveLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("Active Light"));
	ActiveLight->SetupAttachment(SCP);
	InactiveLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("Inactive Light"));
	InactiveLight->SetupAttachment(SCP);

}

void AMapLoader::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor == this)
	{
		return;
	}
	if(IsActive && !TargetLevelName.IsNone() && OtherActor->GetClass() == AllowedPawn)
	{
		UGameplayStatics::OpenLevel(GetWorld(), TargetLevelName);
	}
}

void AMapLoader::StatusCheck()
{
	bool condition1{ false }, condition2{ false };
	if(IsTargetDestructionNeeded)
	{
		TArray<AActor*> Targets;
		UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), AActor::StaticClass(), DestructionTargetTag, Targets);
		if (Targets.Num() == 0)
			condition1 = true;
	}
	else
	{
		condition1 = true;
	}
	if(IsTargetScoreGoalNeeded)
	{
		auto player = Cast<ATankPlayerController>(GetGameInstance()->GetFirstLocalPlayerController());
		if(player)
		{
			if(player->GetPawn() != nullptr)
				if (player->TankPawn->GetTotalScore() >= ScoreRequiredToWin)
					condition2 = true;
		}
	}
	else
	{
		condition2 = true;
	}

	if(condition1 && condition2)
	{
		SetActive(true);
	}
	else
	{
		SetActive(false);
	}
}

// Called when the game starts or when spawned
void AMapLoader::BeginPlay()
{
	Super::BeginPlay();

	Collision->OnComponentBeginOverlap.AddDynamic(this, &AMapLoader::OnBeginOverlap);

	FTimerHandle ConditionsCheckTimer;
	GetWorld()->GetTimerManager().SetTimer(ConditionsCheckTimer, this, &AMapLoader::StatusCheck, 1, true, 1);
}

void AMapLoader::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	SetActive(IsActive);
}

// Called every frame
void AMapLoader::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMapLoader::SetActive(bool Active)
{
	IsActive = Active;
	ActiveLight->SetVisibility(Active);
	InactiveLight->SetVisibility(!Active);

}

