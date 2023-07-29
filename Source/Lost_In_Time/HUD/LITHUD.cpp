// Fill out your copyright notice in the Description page of Project Settings.


#include "LITHUD.h"
#include "GameFramework/PlayerController.h"
#include "Lost_In_Time/Inventory/InventoryWidget.h"

void ALITHUD::BeginPlay()
{
	Super::BeginPlay();
}

void ALITHUD::AddInventory()
{
	APlayerController* PlayerController = GetOwningPlayerController();
	if (PlayerController && InventoryClass)
	{
		InventoryWidget = CreateWidget<UInventoryWidget>(PlayerController, InventoryClass);
		InventoryWidget->AddToViewport();
	}
}

void ALITHUD::DrawHUD()
{
	Super::DrawHUD();
}
