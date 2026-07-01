#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BuildProfile.generated.h"

UCLASS(BlueprintType)
class PROJECTSTRIKERCORE_API UBuildProfile : public UDataAsset
{
    GENERATED_BODY()
public:
    // Configurable production parameters to be defined in Blueprints
};
