#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "StrikerMatchManager.generated.h"

/**
 * Manages the high-level lifetime of the match, bridging teams, rules, and logic.
 */
UCLASS()
class PROJECTSTRIKER_API UStrikerMatchManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Match")
	void PrepareMatch();

	UFUNCTION(BlueprintCallable, Category = "Match")
	void StartMatch();
};
