// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LITCharacter.generated.h"

UCLASS()
class LOST_IN_TIME_API ALITCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	ALITCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	virtual void BeginPlay() override;

private:



};
