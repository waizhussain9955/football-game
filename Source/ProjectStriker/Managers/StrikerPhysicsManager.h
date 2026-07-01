#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "StrikerPhysicsManager.generated.h"

/**
 * Specialized physics orchestration, enforcing substepping and specific physical materials for turf and weather.
 */
UCLASS()
class PROJECTSTRIKER_API UStrikerPhysicsManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "Physics")
	void ApplyTurfFriction(float GroundWetness);
};
