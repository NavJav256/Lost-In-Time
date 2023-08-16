// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "LaserWall.generated.h"

UCLASS()
class LOST_IN_TIME_API ALaserWall : public AActor
{
	GENERATED_BODY()
	
public:

	ALaserWall();

	virtual void OnConstruction(const FTransform& Transform) override;

	void Activate();

	void Deactivate();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* Lasers;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BlockArea;

	UPROPERTY(VisibleAnywhere)
	UTimelineComponent* LaserTimeline;

	FOnTimelineFloat LaserTrack;

	UFUNCTION()
	void UpdateLasers(float LaserOpacity);

	UPROPERTY(EditAnywhere)
	UCurveFloat* LaserCurve;

	UPROPERTY(VisibleAnywhere)
	UMaterialInstanceDynamic* DynamicLaserMaterialInstance;

	UPROPERTY(EditAnywhere)
	UMaterialInstance* LaserMaterialInstance;

	UPROPERTY(EditAnywhere)
	int32 NumRays;

	UPROPERTY(EditAnywhere)
	int32 RayLength;

	UPROPERTY(EditAnywhere)
	int32 RayStep;

	UPROPERTY(EditAnywhere)
	int32 OverlapWidth;

	UPROPERTY(EditAnywhere)
	int32 OverlapHeight;

	UPROPERTY(VisibleAnywhere)
	bool bActive;
};
