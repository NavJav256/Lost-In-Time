// Fill out your copyright notice in the Description page of Project Settings.


#include "LanternPuzzle.h"
#include "Lost_In_Time/PuzzleObjects/WallButton.h"
#include "Lost_In_Time/PuzzleObjects/FogWall.h"

ALanternPuzzle::ALanternPuzzle()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ALanternPuzzle::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALanternPuzzle::CheckSolution()
{
	bool bValid = true;
	for (int32 i = 0; i < Buttons.Num(); i++)
	{
		if (Buttons[i]->IsPressed() != Solution[i])
		{
			bValid = false;
			if (Fog)
			{
				Fog->ShowFog();
			}
		}
	}
	if (bValid && Fog)
	{
		Fog->ClearFog();
	}
}

