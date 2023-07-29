// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Lost_In_Time/Structs/ItemDetails.h"
#include "InventoryWidget.generated.h"

USTRUCT(BlueprintType)
struct FInvItem {
	
	GENERATED_BODY()
	
	FString Name;

	class UTexture2D* Image;

	int32 Amount;
};

/**
 * 
 */
UCLASS()
class LOST_IN_TIME_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void AddItem(FItemDetails Details);

	void UpdateInventory();

private:

	UPROPERTY(meta = (BindWidget))
	class UHorizontalBox* InventoryBox;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> InvItemClass;

	UPROPERTY(VisibleAnywhere)
	TArray<FInvItem> Items;
};
