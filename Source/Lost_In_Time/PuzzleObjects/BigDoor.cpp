// Fill out your copyright notice in the Description page of Project Settings.


#include "BigDoor.h"
#include "Lever.h"

ABigDoor::ABigDoor()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Root"));
	RootComponent = DefaultSceneRoot;

	LeftColumn = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left Column"));
	LeftColumn->SetupAttachment(RootComponent);

	LeftDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left Door"));
	LeftDoor->SetupAttachment(RootComponent);

	RightDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right Door"));
	RightDoor->SetupAttachment(RootComponent);

	RightColumn = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right Column"));
	RightColumn->SetupAttachment(RootComponent);

	DoorTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Door Timeline Component"));

	DoorState = EDoorState::EDS_CLOSED;
	
}

void ABigDoor::BeginPlay()
{
	Super::BeginPlay();

	if (TargetLever)
	{
		TargetLeverState = TargetLever->GetLeverState();
	}
}

void ABigDoor::Tick(float DeltaTime)
{
	if (TargetLever && TargetLever->GetLeverState() != TargetLeverState) {
		SwitchState();
		TargetLeverState = TargetLever->GetLeverState();
	}
}

void ABigDoor::SwitchState()
{
	DoorTrack.BindDynamic(this, &ABigDoor::UpdateDoor);
	if (DoorTimeline && DoorCurve)
	{
		DoorTimeline->AddInterpFloat(DoorCurve, DoorTrack);
		if (DoorState == EDoorState::EDS_CLOSED)
		{
			DoorState = EDoorState::EDS_OPEN;
			DoorTimeline->Play();
		}
		else
		{
			DoorState = EDoorState::EDS_CLOSED;
			DoorTimeline->ReverseFromEnd();
		}
	}
}


void ABigDoor::UpdateDoor(float DoorUpdate)
{
	FVector LeftLocation = LeftDoor->GetRelativeLocation();
	FVector RightLocation = RightDoor->GetRelativeLocation();

	LeftLocation.Y = DoorUpdate;
	RightLocation.Y = -DoorUpdate;

	LeftDoor->SetRelativeLocation(LeftLocation);
	RightDoor->SetRelativeLocation(RightLocation);
}
