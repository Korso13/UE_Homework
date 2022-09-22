// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_Pawn.h"

#include "EnemyTankAIController.h"
#include "Projectile.h"
#include "TankPlayerController.h"
#include "Turret.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ABase_Pawn::ABase_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	RootComponent = Collision;

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body Mesh"));
	BodyMesh->SetupAttachment(Collision);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BodyMesh);

	CanonMountingPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("Canon Mounting Point"));
	CanonMountingPoint->AttachToComponent(TurretMesh, FAttachmentTransformRules::KeepRelativeTransform);

	HealthComponent = CreateDefaultSubobject<UHealthComponent>("Health Component");
	HealthComponent->OnDeath.AddUObject(this, &ABase_Pawn::OnDeath);
	HealthComponent->OnDamage.AddUObject(this, &ABase_Pawn::OnDamage);

	DetectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Detection Sphere"));
	DetectionSphere->SetupAttachment(Collision);

	OnHitAudioEffect = CreateDefaultSubobject<UAudioComponent>("On Hit Audio SFX");
	OnHitAudioEffect->SetupAttachment(RootComponent);
	OnHitParticleEffect = CreateDefaultSubobject<UParticleSystemComponent>("On Hit Visual SFX");
	OnHitParticleEffect->SetupAttachment(RootComponent);

	OnDeathAudioEffect = CreateDefaultSubobject<UAudioComponent>("On Death Audio SFX");
	OnDeathAudioEffect->SetupAttachment(RootComponent);
	OnDeathParticleEffect = CreateDefaultSubobject<UParticleSystemComponent>("On Death Visual SFX");
	OnDeathParticleEffect->SetupAttachment(RootComponent);
}

 //Called every frame
void ABase_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//auto PlayerController = Cast<ATankPlayerController>(GetInstigator()->GetController());
	if (IsPlayerControlled())
		GEngine->AddOnScreenDebugMessage(22, 0.5f, FColor::Red, FString::Printf(TEXT("Current HP: %2f"), HealthComponent->CurrentHP));
}

void ABase_Pawn::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Orange, FString::Printf(TEXT("Spawned Tank with ID: %d"), TankSpawnID));
}

 //Called when the game starts or when spawned
void ABase_Pawn::BeginPlay()
{
	Super::BeginPlay();

	OnScoredKill.AddUObject(this, &ABase_Pawn::ScoredKill);
}

void ABase_Pawn::OnDeath()
{
	SetActorTickEnabled(false);
	if(!IsA<ATurret>())
		GetInstigatorController()->SetActorTickEnabled(false);
	else if(IsA<ATurret>())
	{
		auto pawn = Cast<ATurret>(GetInstigator());
		GetWorld()->GetTimerManager().ClearTimer(pawn->TargetingTimer);
	}
	OnDeathParticleEffect->Activate();
	OnDeathAudioEffect->Play();
	FTimerHandle PawnDestructionTimer;
	FTimerDelegate PawnDestructionDel;
	PawnDestructionDel.BindUFunction(this, FName("DestroyPawn"));
	if(IsPlayerControlled())
		GetWorld()->GetTimerManager().SetTimer(PawnDestructionTimer, PawnDestructionDel, 2, false, -1);
	else
		GetWorld()->GetTimerManager().SetTimer(PawnDestructionTimer, PawnDestructionDel, 10, false, -1);
}

void ABase_Pawn::DestroyPawn()
{
	auto PlayerController = Cast<ATankPlayerController>(GetController());
	if(PlayerController)
	{
		UKismetSystemLibrary::QuitGame(GetWorld(), PlayerController, EQuitPreference::Quit, false);
	}
	Destroy();
}

void ABase_Pawn::Destroyed()
{
	Super::Destroyed();

	if (Cannon)
	{
		Cannon->Destroy();
	}
}

void ABase_Pawn::OnDamage(FDamageInfo Damage)
{
	auto IsPlayerController = Cast<APlayerController>(GetInstigatorController());
	if (IsPlayerController)
	{
		IsPlayerController->ClientPlayForceFeedback(OnHitForceFeedback);
	}
	OnHitParticleEffect->Activate();
	OnHitAudioEffect->Play();

	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString::Printf(TEXT("%s took damage from %s, HP: %f"), ToCStr(this->GetName()), ToCStr(Damage.Instigator->GetName()), HealthComponent->CurrentHP));
}


void ABase_Pawn::TakeDamage(FDamageInfo DamageData)
{
	HealthComponent->TakeDamage(DamageData);
}

int32 ABase_Pawn::GetScore() const
{
	return ScoreValue;
}

float ABase_Pawn::GetHealth() const
{
	return HealthComponent->CurrentHP;
}

int32 ABase_Pawn::GetTotalScore() const
{
	return TotalScore;
}

void ABase_Pawn::ScoredKill(FScoredKillData KillData) 
{
	if(IsValid(KillData.Killer))
	{
		if((KillData.ScoreValue != 0) && KillData.Killer == this)
		{
			TotalScore += KillData.ScoreValue;
		}
	}
}

void ABase_Pawn::OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == this || OtherActor == GetInstigator() || OtherActor == nullptr)
	{
		return;
	}
	//if (!OtherActor->IsA<APawn>())
	if (OtherActor->GetClass() != TargetType)
	{
		return;
	}
	Targets.Add(OtherActor);
	FindBestTarget();
}

void ABase_Pawn::OnDetectionSphereEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == this /*|| OtherActor == GetInstigator()*/ || OtherActor == nullptr)
	{
		return;
	}
	//if (!OtherActor->IsA<APawn>())
	if (OtherActor->GetClass() != TargetType)
	{
		return;
	}

	Targets.Remove(OtherActor);
	if (OtherActor == CurrentTarget)
	{
		FindBestTarget();
	}
}

void ABase_Pawn::FindBestTarget()
{
	float MinRotation = 360;
	float MinDistance = 1000000000;
	TWeakObjectPtr<AActor> BestTarget;
	FVector const AIUnitLocation = GetActorLocation();
	FVector const AIUnitRotation = GetActorForwardVector();

	for (auto const Target : Targets)
	{
		if (Target.IsValid())
		{
			FVector TargetingVector = Target->GetActorLocation() - AIUnitLocation;
			TargetingVector.Normalize();
			float AimRotation = FMath::RadiansToDegrees(FVector::DotProduct(AIUnitRotation, TargetingVector));
			if (AimRotation < MinRotation && (MinRotation - AimRotation) < 15)
			{
				float const Distance = FVector::DistXY(AIUnitLocation, Target->GetActorLocation());
				if (Distance < MinDistance)
				{
					MinDistance = Distance;
					MinRotation = AimRotation;
					BestTarget = Target;
				}
			}
			else
			{
				float const Distance = FVector::DistXY(AIUnitLocation, Target->GetActorLocation());
				MinDistance = Distance;
				MinRotation = AimRotation;
				BestTarget = Target;
			}
		}
	}

	if (BestTarget.IsValid())
	{
		CurrentTarget = BestTarget;
	}
	else
		CurrentTarget = nullptr;
}
