// Fill out your copyright notice in the Description page of Project Settings.


#include "MuseumDoor.h"

AMuseumDoor::AMuseumDoor()
{
	PrimaryActorTick.bCanEverTick = false;

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));
	RootComponent = DoorMesh;

	DoorTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Door Timeline Component"));

	DoorState = EDoorState::EDS_CLOSED;
}

void AMuseumDoor::BeginPlay()
{
	Super::BeginPlay();
}

void AMuseumDoor::SwitchState()
{
	DoorTrack.BindDynamic(this, &AMuseumDoor::UpdateDoor);
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

void AMuseumDoor::UpdateDoor(float DoorUpdate)
{
	FRotator Rotation = DoorMesh->GetRelativeRotation();
	Rotation.Yaw = DoorUpdate;

	DoorMesh->SetRelativeRotation(Rotation);
}
