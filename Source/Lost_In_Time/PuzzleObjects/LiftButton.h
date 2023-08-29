// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lost_In_Time/Interfaces/Interactable.h"
#include "LiftButton.generated.h"

UCLASS()
class LOST_IN_TIME_API ALiftButton : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:

	ALiftButton();

	void Interact();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Button;

	UPROPERTY(EditAnywhere)
	class ALift* TargetLift;

};
