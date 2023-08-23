// Fill out your copyright notice in the Description page of Project Settings.


#include "FogWall.h"

AFogWall::AFogWall()
{
	PrimaryActorTick.bCanEverTick = false;

	FogMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Fog"));
	RootComponent = FogMesh;
}

void AFogWall::BeginPlay()
{
	Super::BeginPlay();
	
	bVisible = true;
}

void AFogWall::ShowFog()
{
	if (!bVisible)
	{
		bVisible = true;
	}
}

void AFogWall::ClearFog()
{
	if (bVisible)
	{
		bVisible = false;
	}
}

