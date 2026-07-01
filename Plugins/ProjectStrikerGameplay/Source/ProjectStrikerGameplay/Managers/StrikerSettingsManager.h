#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "StrikerSettingsManager.generated.h"

/**
 * Manages game settings such as difficulty, match length, camera type, and graphics.
 */
UCLASS()
class PROJECTSTRIKERGAMEPLAY_API UStrikerSettingsManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "Settings")
	void ApplySettings();
};
