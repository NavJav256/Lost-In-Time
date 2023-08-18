// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorPuzzle.generated.h"

UCLASS()
class LOST_IN_TIME_API AFloorPuzzle : public AActor
{
	GENERATED_BODY()
	
public:

	AFloorPuzzle();

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnButtonOverlap(UPrimitiveComponent* OverlappeddComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void ResetPuzzle(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void CheckSolution();

private:

	UPROPERTY(EditAnywhere)
	class AFloorButton* ResetButton;

	UPROPERTY(EditAnywhere)
	TArray<AFloorButton*> PuzzleGrid;

	UPROPERTY(EditAnywhere)
	class ALaserWall* TargetLaserWall;

	UPROPERTY(EditAnywhere)
	TArray<AFloorButton*> Solution;

	int32 SequenceIndex;
};
