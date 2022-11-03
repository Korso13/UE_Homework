// Fill out your copyright notice in the Description page of Project Settings.


#include "TankFactory.h"
#include "MapLoader.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ATankFactory::ATankFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Factory Collision"));
	RootComponent = Collision;

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Factory Body Mesh"));
	BodyMesh->SetupAttachment(RootComponent);
	DestroyedBodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Destroyed Factory Body Mesh"));
	DestroyedBodyMesh->SetupAttachment(RootComponent);
	DestroyedBodyMesh->SetVisibility(false);
	DestroyedBodyMesh->SetCollisionProfileName(FName("NoCollision"), false);

	SpawnPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("Tank Spawn Point"));
	SpawnPoint->SetupAttachment(RootComponent);

	HealthComponent = CreateDefaultSubobject<UHealthComponent>("Factory Health Component");
	HealthComponent->OnDeath.AddUObject(this, &ATankFactory::OnDeath);
	HealthComponent->OnDamage.AddUObject(this, &ATankFactory::OnDamage);

	OnSpawnAudioEffect = CreateDefaultSubobject<UAudioComponent>("On Spawn Audio SFX");
	OnSpawnAudioEffect->SetupAttachment(RootComponent);
	OnSpawnParticleEffect = CreateDefaultSubobject<UParticleSystemComponent>("On Spawn Visual SFX");
	OnSpawnParticleEffect->SetupAttachment(RootComponent);

	OnDestructionEffect = CreateDefaultSubobject<UParticleSystemComponent>("On Destruction Visual SFX");
	OnDestructionEffect->SetupAttachment(RootComponent);
	PostDestructionPersistentEffect = CreateDefaultSubobject<UParticleSystemComponent>("Destroyed Factory Visual SFX");
	PostDestructionPersistentEffect->SetupAttachment(RootComponent);
	OnDestructionAudioEffect = CreateDefaultSubobject<UAudioComponent>("On Destruction Audio SFX");
	OnDestructionAudioEffect->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ATankFactory::BeginPlay()
{
	Super::BeginPlay();

	//GetWorld()->GetTimerManager().SetTimer(SpawnTimer, this, &ATankFactory::OnSpawnTick, SpawnRate, true);
	if (IsWorkingOnSpawn)
		StartProduction();
	TankSpawnID = 0;
}

void ATankFactory::StartProduction()
{
	OnSpawnTick();
	GetWorld()->GetTimerManager().SetTimer(SpawnTimer, this, &ATankFactory::OnSpawnTick, SpawnRate, true);
}

void ATankFactory::OnDeath()
{
	GetWorld()->GetTimerManager().ClearTimer(SpawnTimer);

	//if(ConnectedMapLoader)
	//{
	//	ConnectedMapLoader->SetActive(true);
	//}

	//Destroy();
	Tags.Empty(); //for map loader goals proper work
	OnDestructionEffect->Activate();
	OnDestructionAudioEffect->Activate();
	DestroyedBodyMesh->ToggleVisibility();
	DestroyedBodyMesh->SetCollisionProfileName(FName("BlockAll"), false);
	BodyMesh->ToggleVisibility();

	PostDestructionPersistentEffect->Activate();
}

void ATankFactory::OnDamage_Implementation(FDamageInfo Damage)
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString::Printf(TEXT("%s took damage from %s, HP: %f"), ToCStr(this->GetName()), ToCStr(Damage.Instigator->GetName()), HealthComponent->CurrentHP));
}

// Called every frame
void ATankFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATankFactory::TakeDamage(FDamageInfo DamageData)
{
	HealthComponent->TakeDamage(DamageData);
}

float ATankFactory::GetHealth() const
{
	return HealthComponent->CurrentHP;
}

int ATankFactory::GetScore() const
{
	return ScoreValue;
}


void ATankFactory::OnSpawnTick()
{
	if (CurrentPatrollingID < MaxSpawns)
	{
		FTransform SpawnTransform = SpawnPoint->GetComponentTransform();
		ATank* Tank = GetWorld()->SpawnActorDeferred<ATank>(TankClass, SpawnTransform, nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding);
		if (!StaticPatrollingTag)
		{
			Tank->PatrollingPointTag = FName(FString::Printf(TEXT("%s%d"), ToCStr(PatrollingPointTag), CurrentPatrollingID));
		}
		else
			Tank->PatrollingPointTag = FName(FString::Printf(TEXT("%s"), ToCStr(PatrollingPointTag)));

		CurrentPatrollingID++;
		Tank->TankSpawnID = TankSpawnID;
		TankSpawnID++;
		UGameplayStatics::FinishSpawningActor(Tank, SpawnTransform);

		OnSpawnParticleEffect->Activate();
		OnSpawnAudioEffect->Play();
		FTimerHandle SFXTimer;
		FTimerDelegate SFXDelegate;
		SFXDelegate.BindUFunction(this, FName("SFXStop"));
		GetWorld()->GetTimerManager().SetTimer(SFXTimer, SFXDelegate, 1, false, -1);
	}
}

void ATankFactory::SFXStop()
{
	OnSpawnParticleEffect->Deactivate();
}


