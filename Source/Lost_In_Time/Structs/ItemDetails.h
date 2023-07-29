#pragma once

#include "ItemDetails.generated.h"

USTRUCT(BlueprintType)
struct FItemDetails
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, Category = "Pickup Properties")
    class UTexture2D* ItemImage;

    UPROPERTY(EditAnywhere, Category = "Pickup Properties")
    FString ItemName;
};