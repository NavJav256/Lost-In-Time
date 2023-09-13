// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Door.h"
#include "MuseumDoor.generated.h"

/**
 * 
 */
UCLASS()
class LOST_IN_TIME_API AMuseumDoor : public ADoor
{
	GENERATED_BODY()
	
public:

	AMuseumDoor();

	virtual void SwitchState();

protected:

	virtual void BeginPlay();

	UFUNCTION()
	virtual void UpdateDoor(float DoorUpdate);

private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DoorMesh;
};
