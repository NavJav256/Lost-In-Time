// Fill out your copyright notice in the Description page of Project Settings.


#include "PinPuzzleMaster.h"
#include "Lost_In_Time/PuzzleObjects/Counter.h"

APinPuzzleMaster::APinPuzzleMaster()
{
	PrimaryActorTick.bCanEverTick = true;

}

void APinPuzzleMaster::BeginPlay()
{
	Super::BeginPlay();
	
}

void APinPuzzleMaster::Lock()
{

}

void APinPuzzleMaster::Unlock()
{

}

void APinPuzzleMaster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	bool bUnlocked = true;
	for (ACounter* Counter : Counters)
	{
		if (!Counter->IsCorrect())
		{
			bUnlocked = false;
		}
	}
	if (bUnlocked)
	{
		Unlock();
	}
	else
	{
		Lock();
	}
}
