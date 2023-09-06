// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeLaserPuzzle.h"
#include "Lost_In_Time/PuzzleObjects/EnergyCubeTrigger.h"
#include "Lost_In_Time/PuzzleObjects/LaserWall.h"
#include "Lost_In_Time/PuzzleObjects/FloorButton.h"

ACubeLaserPuzzle::ACubeLaserPuzzle()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ACubeLaserPuzzle::BeginPlay()
{
	Super::BeginPlay();

	Trigger->OnUnlockEvent.AddDynamic(this, &ACubeLaserPuzzle::OnUnlock);
}

void ACubeLaserPuzzle::OnUnlock()
{
	LaserWall->Deactivate();
}

