#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "StrikerAnimationManager.generated.h"

/**
 * High level animation coordination, tracking pose search databases and motion matching constraints.
 */
UCLASS()
class PROJECTSTRIKER_API UStrikerAnimationManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void RegisterPoseDatabase(FName DatabaseName);
};
