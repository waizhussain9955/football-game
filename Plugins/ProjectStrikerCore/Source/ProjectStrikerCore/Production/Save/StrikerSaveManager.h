#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "StrikerSaveManager.generated.h"

UCLASS()
class PROJECTSTRIKERCORE_API UStrikerSaveManager : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    UStrikerSaveManager();
};
