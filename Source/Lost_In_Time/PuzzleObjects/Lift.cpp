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
}

void ALift::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALift::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

