// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorPuzzle.h"
#include "Lost_In_Time/PuzzleObjects/FloorButton.h"
#include "Lost_In_Time/PuzzleObjects/LaserWall.h"
#include "Components/BoxComponent.h"

AFloorPuzzle::AFloorPuzzle()
{
	PrimaryActorTick.bCanEverTick = false;
	
}

void AFloorPuzzle::BeginPlay()
{
	Super::BeginPlay();
	
	SequenceIndex = 0;

	ResetButton->GetOverlapVolume()->OnComponentBeginOverlap.AddDynamic(this, &AFloorPuzzle::ResetPuzzle);

	for (AFloorButton* Button : PuzzleGrid)
	{
		Button->GetOverlapVolume()->OnComponentBeginOverlap.AddDynamic(this, &AFloorPuzzle::OnButtonOverlap);
	}

}

void AFloorPuzzle::OnButtonOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AFloorButton* TriggeredButton = Cast<AFloorButton>(OverlappedComponent->GetOwner());

	if (TriggeredButton && SequenceIndex < Solution.Num() && TriggeredButton == Solution[SequenceIndex])
	{
		SequenceIndex++;
		CheckSolution();
	}
	else
	{
		ResetPuzzle(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
		if (TargetLaserWall)
		{
			TargetLaserWall->Activate();
		}
	}
}

void AFloorPuzzle::ResetPuzzle(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	SequenceIndex = 0;
	
	if (TargetLaserWall)
	{
		TargetLaserWall->Deactivate();
	}
}

void AFloorPuzzle::CheckSolution()
{
	if (SequenceIndex == Solution.Num())
	{
		if (TargetLaserWall)
		{
			TargetLaserWall->Deactivate();
		}
	}
}

