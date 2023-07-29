// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"
#include "Components/HorizontalBox.h"
#include "Components/SizeBox.h"
#include "Components/Image.h"
#include "InventoryItem.h"

void UInventoryWidget::AddItem(FItemDetails Details)
{
	int32 Quantity = 0;
	for (FInvItem Item : Items)
	{
		if (Item.Name == Details.ItemName)
		{
			Quantity = Item.Amount;
		}
	}
	
	FInvItem InvItem;
	InvItem.Name = Details.ItemName;
	InvItem.Image = Details.ItemImage;
	InvItem.Amount = Quantity + 1;

	Items.Add(InvItem);
	UpdateInventory();
	
}

void UInventoryWidget::UpdateInventory()
{
	if (InventoryBox)
	{
		InventoryBox->ClearChildren();
		for (FInvItem InvItem : Items)
		{
			UImage* NewInvItem = NewObject<UImage>(InventoryBox);
			if (NewInvItem)
			{
				NewInvItem->SetBrushFromTexture(InvItem.Image, true);
				InventoryBox->AddChild(NewInvItem);
			}
			USizeBox* Spacer = NewObject<USizeBox>(InventoryBox);
			if (Spacer)
			{
				Spacer->SetMinDesiredWidth(10.f);
				InventoryBox->AddChild(Spacer);
			}
			
		}
	}
}
