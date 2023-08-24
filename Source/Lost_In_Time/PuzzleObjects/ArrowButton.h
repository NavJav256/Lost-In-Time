// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lost_In_Time/Interfaces/Interactable.h"
#include "ArrowButton.generated.h"

UENUM(BlueprintType)
enum class EArrowDirection : uint8
{
	EAD_UP UMETA(DisplayName = "Up"),
	EAD_DOWN UMETA(DisplayName = "Down"),
	EAD_LEFT UMETA(DisplayName = "Left"),
	EAD_RIGHT UMETA(DisplayName = "Right"),

	EAD_MAX UMETA(DisplayName = "Default Max")
};

UCLASS()
class LOST_IN_TIME_API AArrowButton : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:

	AArrowButton();

	void Interact();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ButtonMesh;

	UPROPERTY(EditAnywhere)
	EArrowDirection ArrowDirection;

	UPROPERTY(EditAnywhere)
	class ACounter* TargetCounter;

};
