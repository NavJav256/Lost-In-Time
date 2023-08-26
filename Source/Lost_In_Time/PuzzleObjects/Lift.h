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

private:

	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Base;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Platform;

};
