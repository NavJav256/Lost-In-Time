// Fill out your copyright notice in the Description page of Project Settings.


#include "BridgePuzzle.h"
#include "Lost_In_Time/PuzzleObjects/EnergyCubeTrigger.h"
#include "Lost_In_Time/PuzzleObjects/Bridge.h"

ABridgePuzzle::ABridgePuzzle()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ABridgePuzzle::BeginPlay()
{
	Super::BeginPlay();
	
	Trigger->OnUnlockEvent.AddDynamic(this, &ABridgePuzzle::OnUnlockStateChanged);
}

void ABridgePuzzle::OnUnlockStateChanged(bool bUnlock)
{
	if (bUnlock)
	{
		Bridge->Activate();
	}
	else
	{
		Bridge->Deactivate();
	}
}
