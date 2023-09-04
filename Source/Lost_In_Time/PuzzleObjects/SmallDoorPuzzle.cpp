// Fill out your copyright notice in the Description page of Project Settings.


#include "SmallDoorPuzzle.h"
#include "Lost_In_Time/PuzzleObjects/EnergyCubeTrigger.h"
#include "Lost_In_Time/PuzzleObjects/SmallDoor.h"

ASmallDoorPuzzle::ASmallDoorPuzzle()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ASmallDoorPuzzle::BeginPlay()
{
	Super::BeginPlay();
	
	Trigger->OnUnlockEvent.AddDynamic(this, &ASmallDoorPuzzle::OnUnlockStateChanged);
}

void ASmallDoorPuzzle::OnUnlockStateChanged(bool bUnlock)
{
	Door->SwitchState();
}

