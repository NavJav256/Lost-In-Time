// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeLaserPuzzle.generated.h"

UCLASS()
class LOST_IN_TIME_API ACubeLaserPuzzle : public AActor
{
	GENERATED_BODY()
	
public:

	ACubeLaserPuzzle();

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnUnlock();

private:

	UPROPERTY(EditAnywhere)
	class AEnergyCubeTrigger* Trigger;

	UPROPERTY(EditAnywhere)
	class ALaserWall* LaserWall;

};
