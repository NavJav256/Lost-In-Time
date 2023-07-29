// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryItem.generated.h"

/**
 * 
 */
UCLASS()
class LOST_IN_TIME_API UInventoryItem : public UUserWidget
{
	GENERATED_BODY()

public:

	void SetImage(class UTexture2D* Image);

	void SetQuantity(int32 Q);
	
private:

	UPROPERTY(meta = (BindWidget))
	class UImage* ItemIcon;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* QuantityText;
};
