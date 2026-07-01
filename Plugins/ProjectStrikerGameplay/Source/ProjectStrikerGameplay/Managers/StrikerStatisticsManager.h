#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "StrikerStatisticsManager.generated.h"

/**
 * Tracks match statistics like shots, possession percentage, fouls, and passes.
 */
UCLASS()
class PROJECTSTRIKERGAMEPLAY_API UStrikerStatisticsManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "Statistics")
	void RecordShot(int32 TeamIndex, bool bOnTarget);

	UFUNCTION(BlueprintCallable, Category = "Statistics")
	void RecordPass(int32 TeamIndex, bool bSuccessful);
};
