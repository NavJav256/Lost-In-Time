// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryItem.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UInventoryItem::SetImage(UTexture2D* Image)
{
	if (ItemIcon)
	{
		ItemIcon->SetBrushFromTexture(Image);
	}
}

void UInventoryItem::SetQuantity(int32 Q)
{
	if (QuantityText)
	{
		FString AmountText = Q > 1 ? FString::Printf(TEXT("%d"), Q) : TEXT("");
		QuantityText->SetText(FText::FromString(AmountText));
	}
}
