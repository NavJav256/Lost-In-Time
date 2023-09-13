// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "MovingPainting.generated.h"

UCLASS()
class LOST_IN_TIME_API AMovingPainting : public AActor
{
	GENERATED_BODY()
	
public:

	AMovingPainting();

	void MoveUp();

	void MoveDown();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Frame;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Painting;

	UPROPERTY(VisibleAnywhere)
	UTimelineComponent* PaintingTimeline;

	FOnTimelineFloat PaintingTrack;

	UFUNCTION()
	void MovePainting(float PaintingPosition);

	UPROPERTY(EditAnywhere)
	UCurveFloat* PaintingCurve;

	bool bDown;

public:

	FORCEINLINE bool IsPaintingDown() { return bDown; }
};
