// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LanternPuzzle.generated.h"

UCLASS()
class LOST_IN_TIME_API ALanternPuzzle : public AActor
{
	GENERATED_BODY()
	
public:

	ALanternPuzzle();

protected:

	virtual void BeginPlay() override;

	void CheckSolution();

private:

	UPROPERTY(EditAnywhere)
	TArray<class AWallButton*> Buttons;

	UPROPERTY(EditAnywhere)
	TArray<bool> Solution;

	UPROPERTY(EditAnywhere)
	class AFogWall* Fog;

};
