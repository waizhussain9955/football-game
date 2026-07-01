#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "StrikerCrowdManager.generated.h"

/**
 * Manages crowd visuals, LOD scaling, and localized crowd audio excitement levels.
 */
UCLASS()
class PROJECTSTRIKER_API UStrikerCrowdManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "Crowd")
	void SetCrowdExcitement(float ExcitementLevel);
};
