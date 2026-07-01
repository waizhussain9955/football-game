#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StrikerCameraManager.generated.h"

UCLASS()
class PROJECTSTRIKERGAMEPLAY_API UStrikerCameraManager : public UObject
{
    GENERATED_BODY()
public:
    void TransitionToBroadcast();
    void TransitionToDynamicFollow();
    void TransitionToGoalCamera();
    void TransitionToReplay();
};
