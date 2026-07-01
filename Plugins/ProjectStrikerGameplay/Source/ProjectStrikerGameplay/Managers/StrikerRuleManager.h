#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "StrikerRuleManager.generated.h"

/**
 * Handles the configuration and enforcement of football rules.
 */
UCLASS()
class PROJECTSTRIKERGAMEPLAY_API UStrikerRuleManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "Rules")
	bool IsOffsideEnabled() const;
};
