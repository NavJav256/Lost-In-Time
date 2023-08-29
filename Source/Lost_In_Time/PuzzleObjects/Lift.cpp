// Fill out your copyright notice in the Description page of Project Settings.


#include "Lift.h"

ALift::ALift()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Root"));
	RootComponent = DefaultSceneRoot;

	Base = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lift Base"));
	Base->SetupAttachment(RootComponent);

	Platform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lift Platform"));
	Platform->SetupAttachment(RootComponent);

	bLiftDown = true;
	bLiftMoving = false;
}

void ALift::BeginPlay()
{
	Super::BeginPlay();
	
	GlobalStartLocation = Platform->GetComponentLocation();
	GlobalTargetLocation = Platform->GetComponentTransform().TransformPosition(TargetLocation);
}

void ALift::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bLiftMoving)
	{
		if (bLiftDown)
		{
			GoUp(DeltaTime);
		}
		else
		{
			GoDown(DeltaTime);
		}
	}

}

void ALift::GoUp(float DeltaTime)
{
	bLiftMoving = true;
	FVector Location = Platform->GetComponentLocation();
	float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
	float JourneyTravelled = (Location - GlobalStartLocation).Size();
	if (JourneyTravelled > JourneyLength)
	{
		bLiftMoving = false;
		bLiftDown = false;
	}
	else
	{
		FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		Location += Speed * Direction * DeltaTime;
		Platform->SetWorldLocation(Location);
	}
}

void ALift::GoDown(float DeltaTime)
{
	bLiftMoving = true;
	FVector Location = Platform->GetComponentLocation();
	float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
	float JourneyTravelled = (Location - GlobalTargetLocation).Size();
	if (JourneyTravelled > JourneyLength)
	{
		bLiftMoving = false;
		bLiftDown = true;
	}
	else
	{
		FVector Direction = (GlobalStartLocation - GlobalTargetLocation).GetSafeNormal();
		Location += Speed * Direction * DeltaTime;
		Platform->SetWorldLocation(Location);
	}
}
