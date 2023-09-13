// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PinPuzzleMaster.h"
#include "MDoorPinPuzzle.generated.h"

/**
 * 
 */
UCLASS()
class LOST_IN_TIME_API AMDoorPinPuzzle : public APinPuzzleMaster
{
	GENERATED_BODY()

protected:

	virtual void Lock() override;

	virtual void Unlock() override;

private:

	UPROPERTY(EditAnywhere)
	class AMuseumDoor* MuseumDoor;
	
};
