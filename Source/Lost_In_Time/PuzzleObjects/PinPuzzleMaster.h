// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PinPuzzleMaster.generated.h"

UCLASS()
class LOST_IN_TIME_API APinPuzzleMaster : public AActor
{
	GENERATED_BODY()
	
public:

	APinPuzzleMaster();

	virtual void Tick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;

	virtual void Lock();

	virtual void Unlock();

private:	

	UPROPERTY(EditAnywhere)
	TArray<class ACounter*> Counters;
};
