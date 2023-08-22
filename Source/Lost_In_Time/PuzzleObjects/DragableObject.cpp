// Fill out your copyright notice in the Description page of Project Settings.


#include "DragableObject.h"

ADragableObject::ADragableObject()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

void ADragableObject::BeginPlay()
{
	Super::BeginPlay();
	
}


