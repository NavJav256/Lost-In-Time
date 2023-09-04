// Fill out your copyright notice in the Description page of Project Settings.


#include "EnergyCubeTrigger.h"
#include "Components/BoxComponent.h"

AEnergyCubeTrigger::AEnergyCubeTrigger()
{
	PrimaryActorTick.bCanEverTick = false;

	Platform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform"));
	RootComponent = Platform;

	Indicator = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Power Indicator"));
	Indicator->SetupAttachment(Platform);

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetupAttachment(Platform);
}

void AEnergyCubeTrigger::OnConstruction(const FTransform& Transform)
{
	if (!bNeedsPower)
	{
		Indicator->SetVisibility(false);
	}
	else
	{
		Indicator->SetVisibility(true);
	}
}

void AEnergyCubeTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AEnergyCubeTrigger::OnOverlapBegin);
	Trigger->OnComponentEndOverlap.AddDynamic(this, &AEnergyCubeTrigger::OnOverlapEnd);
}

void AEnergyCubeTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Cube = Cast<AEnergyCube>(OtherActor);
	if (Cube)
	{
		if (bNeedsPower && Cube->GetVoltage() == 1.f)
		{
			OnUnlockEvent.Broadcast(true);
		}
		if (!bNeedsPower && Cube->GetVoltage() == 0.f)
		{
			OnUnlockEvent.Broadcast(true);
		}
	}
}

void AEnergyCubeTrigger::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Cube == OtherActor)
	{
		OnUnlockEvent.Broadcast(false);
		Cube = nullptr;
	}
}
