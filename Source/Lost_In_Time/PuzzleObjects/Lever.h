// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "Lost_In_Time/Interfaces/Interactable.h"
#include "Lever.generated.h"

UENUM(BlueprintType)
enum class ELeverState : uint8 
{
	ELS_ON UMETA(DisplayName = "On"),
	ELS_OFF UMETA(DisplayName = "Off"),

	ELS_MAX UMETA(DisplayName = "Default Max")
};

UCLASS()
class LOST_IN_TIME_API ALever : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:

	ALever();

	void Interact();

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlapepdComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlapepdComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:

	UPROPERTY(VisibleAnywhere)
	ELeverState LeverState;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Base;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Handle;

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* AreaSphere;

	UPROPERTY(VisibleAnywhere)
	UTimelineComponent* HandleTimeline;

	FOnTimelineFloat HandleTrack;

	UFUNCTION()
	void UpdateHandle(float HandleRotation);

	UPROPERTY(EditAnywhere)
	UCurveFloat* HandleCurve;

public:

	FORCEINLINE ELeverState GetLeverState() { return LeverState; }
};
