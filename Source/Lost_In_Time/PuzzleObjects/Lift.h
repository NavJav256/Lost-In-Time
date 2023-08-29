// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lift.generated.h"

UCLASS()
class LOST_IN_TIME_API ALift : public AActor
{
	GENERATED_BODY()
	
public:

	ALift();

	virtual void Tick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;

	void GoUp(float DeltaTime);

	void GoDown(float DeltaTime);

private:

	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Base;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Platform;

	UPROPERTY(EditAnywhere)
	float Speed = 200;

	UPROPERTY(EditAnywhere, META = (MakeEditWidget = true))
	FVector TargetLocation;

	FVector GlobalStartLocation;
	FVector GlobalTargetLocation;

	bool bLiftDown;
	bool bLiftMoving;

public:

	FORCEINLINE void ActivateLift() { bLiftMoving = true; }

};
