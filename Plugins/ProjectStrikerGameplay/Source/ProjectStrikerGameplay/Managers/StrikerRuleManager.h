#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StrikerRuleManager.generated.h"

UCLASS()
class PROJECTSTRIKERGAMEPLAY_API UStrikerRuleManager : public UObject
{
    GENERATED_BODY()
public:
    void InitializeRules();

    // Pipelines
    void EvaluateBallOut();
    void EvaluateOffside();
    void EvaluateFoul();

    // Debug Hooks
    UFUNCTION(Exec)
    void VisualizeRules();
};
