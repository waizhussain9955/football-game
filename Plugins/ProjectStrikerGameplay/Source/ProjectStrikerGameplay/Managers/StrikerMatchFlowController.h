#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Events/StrikerGameplayEvents.h"
#include "StrikerMatchFlowController.generated.h"

UCLASS()
class PROJECTSTRIKERGAMEPLAY_API UStrikerMatchFlowController : public UWorldSubsystem
{
    GENERATED_BODY()
public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    
    // Core Flow API
    UFUNCTION(BlueprintCallable, Category="Striker|Flow")
    void StartMatch();
    UFUNCTION(BlueprintCallable, Category="Striker|Flow")
    void PauseMatch(EStrikerPauseState PauseType);
    UFUNCTION(BlueprintCallable, Category="Striker|Flow")
    void ResumeMatch();
    UFUNCTION(BlueprintCallable, Category="Striker|Flow")
    void RestartMatch();
    UFUNCTION(BlueprintCallable, Category="Striker|Flow")
    void EndMatch();
    UFUNCTION(BlueprintCallable, Category="Striker|Flow")
    void AbortMatch();

    // State Access
    EStrikerMatchState GetCurrentState() const { return CurrentState; }

    // Debug Hooks
    UFUNCTION(Exec)
    void DebugPrintStatus();

private:
    EStrikerMatchState CurrentState;
    void TransitionToState(EStrikerMatchState NewState);
    void ExecuteFailureRecovery(const FString& Reason);
};
