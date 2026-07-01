#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "StrikerFormationManager.generated.h"

/**
 * Manages player positions based on active formations (e.g., 4-3-3, 4-4-2) dynamically relative to the ball.
 */
UCLASS()
class PROJECTSTRIKERGAMEPLAY_API UStrikerFormationManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "Formation")
	FVector GetTargetPositionForRole(int32 TeamIndex, uint8 RoleID, FVector BallLocation);
};
