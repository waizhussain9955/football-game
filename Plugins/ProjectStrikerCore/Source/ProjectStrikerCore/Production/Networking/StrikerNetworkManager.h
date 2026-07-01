#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "StrikerNetworkManager.generated.h"

UCLASS()
class PROJECTSTRIKERCORE_API UStrikerNetworkManager : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    UStrikerNetworkManager();
};
