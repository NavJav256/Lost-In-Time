// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Counter.generated.h"

UCLASS()
class LOST_IN_TIME_API ACounter : public AActor
{
	GENERATED_BODY()
	
public:

	ACounter();

	void Increment();

	void Decrement();

protected:

	virtual void BeginPlay() override;

	void UpdateText();

private:

	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CounterBox;

	UPROPERTY(VisibleAnywhere)
	class UTextRenderComponent* CounterText;

	UPROPERTY(VisibleAnywhere)
	int32 Count;

	int32 Correct;

public:

	FORCEINLINE bool IsCorrect() { return Count == Correct; }

};
