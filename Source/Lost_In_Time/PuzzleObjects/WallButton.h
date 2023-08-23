// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WallButton.generated.h"

UCLASS()
class LOST_IN_TIME_API AWallButton : public AActor
{
	GENERATED_BODY()
	
public:

	AWallButton();

protected:

	virtual void BeginPlay() override;

	void PressButton();

private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ButtonMesh;

	UPROPERTY(VisibleAnywhere)
	bool bPressed;

public:

	FORCEINLINE bool IsPressed() { return bPressed; }

};
