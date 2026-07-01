#pragma once
#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "StrikerCameraManager.generated.h"

UCLASS()
class PROJECTSTRIKERCORE_API AStrikerCameraManager : public APlayerCameraManager
{
    GENERATED_BODY()
public:
    AStrikerCameraManager();
};
