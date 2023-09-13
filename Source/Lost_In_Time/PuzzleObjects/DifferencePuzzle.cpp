// Fill out your copyright notice in the Description page of Project Settings.


#include "DifferencePuzzle.h"
#include "Lost_In_Time/PuzzleObjects/CubeButton.h"
#include "Lost_In_Time/PuzzleObjects/MuseumDoor.h"

ADifferencePuzzle::ADifferencePuzzle()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ADifferencePuzzle::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADifferencePuzzle::Lock()
{
	if (MuseumDoor->GetDoorState() == EDoorState::EDS_OPEN)
	{
		MuseumDoor->SwitchState();
	}
}

void ADifferencePuzzle::Unlock()
{
	if (MuseumDoor->GetDoorState() == EDoorState::EDS_CLOSED)
	{
		MuseumDoor->SwitchState();
	}
}

void ADifferencePuzzle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	bool bUnlocked = true;
	for (ACubeButton* Button : Buttons)
	{
		if (!Button->IsCorrect())
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

