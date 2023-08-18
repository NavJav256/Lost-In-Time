// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LITHUD.generated.h"

/**
 * 
 */
UCLASS()
class LOST_IN_TIME_API ALITHUD : public AHUD
{
	GENERATED_BODY()
	
public:

	virtual void DrawHUD() override;

protected:

	virtual void BeginPlay() override;
};
