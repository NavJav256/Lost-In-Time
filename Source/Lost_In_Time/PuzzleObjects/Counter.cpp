// Fill out your copyright notice in the Description page of Project Settings.


#include "Counter.h"
#include "Components/TextRenderComponent.h"

ACounter::ACounter()
{
	PrimaryActorTick.bCanEverTick = false;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Root"));
	RootComponent = DefaultSceneRoot;

	CounterBox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Counter Box"));
	CounterBox->SetupAttachment(RootComponent);

	CounterText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Counter Text"));
	CounterText->SetupAttachment(CounterBox);

}


void ACounter::BeginPlay()
{
	Super::BeginPlay();
	
	Count = 0;
	UpdateText();
}

void ACounter::Increment()
{
	if (Count + 1 > 9)
	{
		Count = 9;
	}
	else
	{
		Count++;
	}
	UpdateText();
}

void ACounter::Decrement()
{
	if (Count - 1 < 0)
	{
		Count = 0;
	}
	else
	{
		Count--;
	}
	UpdateText();
}

void ACounter::UpdateText()
{
	FString CText = FString::FromInt(Count);
	CounterText->SetText(FText::FromString(CText));
}