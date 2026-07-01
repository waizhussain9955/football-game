#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StrikerStatisticsManager.generated.h"

UCLASS()
class PROJECTSTRIKERGAMEPLAY_API UStrikerStatisticsManager : public UObject
{
    GENERATED_BODY()
public:
    void InitializeStatistics();
    
    // Debug Hooks
    UFUNCTION(Exec)
    void DumpStatistics();
};
