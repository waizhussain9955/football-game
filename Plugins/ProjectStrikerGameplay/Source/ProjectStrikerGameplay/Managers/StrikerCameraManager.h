#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "StrikerCameraManager.generated.h"

/**
 * Manages active cameras, smooth transitions between broadcast, dynamic follow, and replays.
 */
UCLASS()
class PROJECTSTRIKERGAMEPLAY_API UStrikerCameraManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "Camera")
	void SetCameraMode(FName ModeName);

	UFUNCTION(BlueprintCallable, Category = "Camera")
	void TriggerCinematicTransition();
};
