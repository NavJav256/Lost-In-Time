// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Lost_In_Time/Structs/ItemDetails.h"
#include "LITPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class LOST_IN_TIME_API ALITPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	void AddHUDItem(FItemDetails Details);

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY()
	class ALITHUD* LITHUD;
};
