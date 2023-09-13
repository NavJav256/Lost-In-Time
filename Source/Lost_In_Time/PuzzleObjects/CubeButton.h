// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "Lost_In_Time/Interfaces/Interactable.h"
#include "CubeButton.generated.h"

UCLASS()
class LOST_IN_TIME_API ACubeButton : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:

	ACubeButton();

	void Interact();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Button;

	UPROPERTY(VisibleAnywhere)
	UTimelineComponent* ButtonTimeline;

	FOnTimelineFloat ButtonTrack;

	UFUNCTION()
	void UpdateButton(float ButtonPosition);

	UPROPERTY(EditAnywhere)
	UCurveFloat* ButtonCurve;
	
	UPROPERTY(EditAnywhere)
	bool bSolution;

	UPROPERTY(VisibleAnywhere)
	bool bPressed;

public:

	FORCEINLINE bool IsCorrect() { return bPressed == bSolution; }
};
