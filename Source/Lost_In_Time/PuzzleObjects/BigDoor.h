// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Door.h"
#include "BigDoor.generated.h"

/**
 * 
 */
UCLASS()
class LOST_IN_TIME_API ABigDoor : public ADoor
{
	GENERATED_BODY()

public:

	ABigDoor();

	virtual void SwitchState() override;

protected:

	virtual void BeginPlay() override;


	UFUNCTION()
	virtual void UpdateDoor(float DoorUpdate) override;

private:

	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LeftColumn;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LeftDoor;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* RightDoor;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* RightColumn;
};
