#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "StrikerWeatherManager.generated.h"

UCLASS()
class PROJECTSTRIKERCORE_API UStrikerWeatherManager : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    UStrikerWeatherManager();
};
