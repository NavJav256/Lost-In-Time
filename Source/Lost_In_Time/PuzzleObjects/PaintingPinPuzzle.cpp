// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintingPinPuzzle.h"
#include "Lost_In_Time/PuzzleObjects/MovingPainting.h"

void APaintingPinPuzzle::Lock()
{
	if (!Painting->IsPaintingDown())
	{
		Painting->MoveDown();
	}
}

void APaintingPinPuzzle::Unlock()
{
	if (Painting->IsPaintingDown())
	{
		Painting->MoveUp();
	}
}
