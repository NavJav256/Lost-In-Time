// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPainting.h"
#include "Components/InstancedStaticMeshComponent.h"

AMovingPainting::AMovingPainting()
{
	PrimaryActorTick.bCanEverTick = false;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Root"));
	RootComponent = DefaultSceneRoot;

	Frame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Frame"));
	Frame->SetupAttachment(RootComponent);

	Painting = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Painting"));
	Painting->SetupAttachment(Frame);

	PaintingTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Painting Timeline"));

	bDown = true;
}

void AMovingPainting::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMovingPainting::MoveUp()
{
	bDown = false;
	PaintingTrack.BindDynamic(this, &AMovingPainting::MovePainting);
	if (PaintingTimeline && PaintingCurve)
	{
		PaintingTimeline->AddInterpFloat(PaintingCurve, PaintingTrack);
		PaintingTimeline->Play();
	}
}

void AMovingPainting::MoveDown()
{
	bDown = true;
	PaintingTrack.BindDynamic(this, &AMovingPainting::MovePainting);
	if (PaintingTimeline && PaintingCurve)
	{
		PaintingTimeline->AddInterpFloat(PaintingCurve, PaintingTrack);
		PaintingTimeline->ReverseFromEnd();
	}
}

void AMovingPainting::MovePainting(float PaintingPosition)
{
	FVector FLocation = Frame->GetRelativeLocation();
	FLocation.Z = PaintingPosition;

	Frame->SetRelativeLocation(FLocation);
}

