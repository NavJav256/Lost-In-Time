// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "Lost_In_Time/Interfaces/Interactable.h"
#include "Door.generated.h"

UENUM(BlueprintType)
enum class EDoorState : uint8
{
	EDS_CLOSED UMETA(DisplayName = "Closed"),
	EDS_OPEN UMETA(DisplayName = "Open"),

	EDS_MAX UMETA(DisplayName = "Default Max")
};

UCLASS()
class LOST_IN_TIME_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:

	ADoor();

	virtual void SwitchState();

protected:

	virtual void BeginPlay();

	virtual void UpdateDoor(float DoorUpdate);

	UPROPERTY(VisibleAnywhere)
	EDoorState DoorState;

	UPROPERTY(VisibleAnywhere)
	UTimelineComponent* DoorTimeline;

	FOnTimelineFloat DoorTrack;

	UPROPERTY(EditAnywhere)
	UCurveFloat* DoorCurve;

public:

	FORCEINLINE EDoorState GetDoorState() { return DoorState; }

};
