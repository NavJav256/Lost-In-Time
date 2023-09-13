// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DifferencePuzzle.generated.h"

UCLASS()
class LOST_IN_TIME_API ADifferencePuzzle : public AActor
{
	GENERATED_BODY()
	
public:

	ADifferencePuzzle();

	virtual void Tick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;

	void Lock();

	void Unlock();

private:

	UPROPERTY(EditAnywhere)
	TArray<class ACubeButton*> Buttons;

	UPROPERTY(EditAnywhere)
	class AMuseumDoor* MuseumDoor;

};
