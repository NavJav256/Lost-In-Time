// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SmallDoorPuzzle.generated.h"

UCLASS()
class LOST_IN_TIME_API ASmallDoorPuzzle : public AActor
{
	GENERATED_BODY()
	
public:

	ASmallDoorPuzzle();

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnUnlockStateChanged(bool bUnlock);

private:

	UPROPERTY(EditAnywhere)
	class AEnergyCubeTrigger* Trigger;

	UPROPERTY(EditAnywhere)
	class ASmallDoor* Door;

};
