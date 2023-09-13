// Fill out your copyright notice in the Description page of Project Settings.


#include "MDoorPinPuzzle.h"
#include "Lost_In_Time/PuzzleObjects/MuseumDoor.h"

void AMDoorPinPuzzle::Lock()
{
	if (MuseumDoor->GetDoorState() == EDoorState::EDS_OPEN)
	{
		MuseumDoor->SwitchState();
	}
}

void AMDoorPinPuzzle::Unlock()
{
	if (MuseumDoor->GetDoorState() == EDoorState::EDS_CLOSED)
	{
		MuseumDoor->SwitchState();
	}
}
