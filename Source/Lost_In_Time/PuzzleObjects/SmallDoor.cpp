// Fill out your copyright notice in the Description page of Project Settings.


#include "SmallDoor.h"

ASmallDoor::ASmallDoor()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Root"));
	RootComponent = DefaultSceneRoot;

	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Frame"));
	DoorFrame->SetupAttachment(RootComponent);

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));
	DoorMesh->SetupAttachment(RootComponent);

	DoorTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Door Timeline Component"));

	DoorState = EDoorState::EDS_CLOSED;
}

void ASmallDoor::BeginPlay()
{
	Super::BeginPlay();
}

void ASmallDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASmallDoor::SwitchState()
{
	DoorTrack.BindDynamic(this, &ASmallDoor::UpdateDoor);
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

void ASmallDoor::UpdateDoor(float DoorUpdate)
{

}
