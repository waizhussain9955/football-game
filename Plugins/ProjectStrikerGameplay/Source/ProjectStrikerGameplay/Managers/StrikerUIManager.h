#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "StrikerUIManager.generated.h"

/**
 * Handles the display and flow of Menus, HUDs, and Overlays.
 */
UCLASS()
class PROJECTSTRIKERGAMEPLAY_API UStrikerUIManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "UI")
	void ShowMainMenu();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void ShowMatchHUD();
};
