// Fill out your copyright notice in the Description page of Project Settings.


#include "LaserPinPuzzle.h"
#include "Lost_In_Time/PuzzleObjects/LaserWall.h"

void ALaserPinPuzzle::Lock()
{
	LaserWall->Activate();
}

void ALaserPinPuzzle::Unlock()
{
	LaserWall->Deactivate();
}
