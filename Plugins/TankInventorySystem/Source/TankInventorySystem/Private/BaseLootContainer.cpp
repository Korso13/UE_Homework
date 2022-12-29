// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseLootContainer.h"
#include "Components/BoxComponent.h"
#include "InventoryComponent.h"
#include "InventoryManagerComponent.h"
//#include "TankWithInventory.h"
#include "ActorWithInventory.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetComponent.h"

// Sets default values
ABaseLootContainer::ABaseLootContainer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box's Collision"));
	RootComponent = Collision;
	Collision->SetCollisionProfileName("Pickups");
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ABaseLootContainer::OnBeginOverlap);
	Collision->OnComponentEndOverlap.AddDynamic(this, &ABaseLootContainer::OnComponentEndOverlap);

	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ammo Box Body"));
	BoxMesh->SetupAttachment(Collision);

	ButtonTooltip = CreateDefaultSubobject<UWidgetComponent>("Button 3D Tooltip");
	ButtonTooltip->SetupAttachment(RootComponent);

	Inventory = CreateDefaultSubobject<UInventoryComponent>("Inventory Component");
}

// Called when the game starts or when spawned
void ABaseLootContainer::BeginPlay()
{
	Super::BeginPlay();
	
	/*if(ButtonTooltipClass)
		ButtonTooltip->SetWidgetClass(ButtonTooltipClass);*/

	if (ButtonTooltip && ButtonTooltip->GetWidgetClass())
	{
		ButtonTooltip->GetWidget()->SetVisibility(ESlateVisibility::Collapsed);
	}

	if (ContainerContents && Inventory)
	{
		FString ContextString;
		TArray<FName> RowNames;
		RowNames = ContainerContents->GetRowNames();
		int32 i = 0;

		for (auto& Name : RowNames)
		{
			auto Row = ContainerContents->FindRow<FInventorySlotInfo>(Name, ContextString);
			if (Row)
			{
				Inventory->SetItem(i, *Row);
				i++;
			}
		}
	}
}

void ABaseLootContainer::OpenContainer()
{
	CloseContainer();

	auto Actor = Cast<IActorWithInventory>(ActorInRange);
	if (Actor)
	{
		Actor->GetInventoryManager()->Init(Inventory, EInventoryClass::IC_Chest);
		if (!Actor->GetInventoryManager()->IsInventoryOpen())
			Actor->GetInventoryManager()->ToggleInventoryWindow();
	}

	if (ButtonTooltip && ButtonTooltip->GetWidgetClass())
	{
		ButtonTooltip->GetWidget()->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void ABaseLootContainer::CloseContainer()
{
	auto Actor = Cast<IActorWithInventory>(ActorInRange);
	if (Actor)
	{
		Actor->GetInventoryManager()->CloseContainer();
		if (ButtonTooltip && ButtonTooltip->GetWidgetClass())
			ButtonTooltip->GetWidget()->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}
}

void ABaseLootContainer::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		ActorInRange = nullptr;
		ActorInRange = Cast<APawn>(OtherActor);
		if (ActorInRange)
		{
			auto Actor = Cast<IActorWithInventory>(ActorInRange);
		
			if (Actor)
			{
				ActorInRange->GetController()->InputComponent->BindAction("Open Container", IE_Released, this, &ABaseLootContainer::OpenContainer);
			
				if (!ButtonTooltip && ButtonTooltipClass)
				{
					auto Widget = CreateWidget<UUserWidget>(GetWorld(), ButtonTooltipClass);
					ButtonTooltip->SetWidget(Widget);
				}
				if (ButtonTooltip && ButtonTooltip->GetWidgetClass())
				{
					//ButtonTooltip->GetWidget()->AddToViewport();
					ButtonTooltip->GetWidget()->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
				}
			}
		}
	}
}

void ABaseLootContainer::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	CloseContainer();
	
	if (OtherActor == ActorInRange && ActorInRange != nullptr)
	{
		auto Actor = Cast<IActorWithInventory>(ActorInRange);
		if (Actor)
		{
			if(ActorInRange)
				ActorInRange->GetController()->InputComponent->RemoveActionBinding("Open Container", IE_Released);
			
			if (ButtonTooltip && ButtonTooltip->GetWidgetClass())
			{
				ButtonTooltip->GetWidget()->SetVisibility(ESlateVisibility::Collapsed);
				//ButtonTooltip->GetWidget()->RemoveFromParent();
			}

		}
		ActorInRange = nullptr;
	}
}


