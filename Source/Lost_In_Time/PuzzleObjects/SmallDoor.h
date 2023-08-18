// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Door.h"
#include "SmallDoor.generated.h"

/**
 * 
 */
UCLASS()
class LOST_IN_TIME_API ASmallDoor : public ADoor
{
	GENERATED_BODY()
	
public:

	ASmallDoor();

	virtual void SwitchState() override;

	virtual void Tick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void UpdateDoor(float DoorUpdate) override;

private:

	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DoorFrame;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DoorMesh;
};
