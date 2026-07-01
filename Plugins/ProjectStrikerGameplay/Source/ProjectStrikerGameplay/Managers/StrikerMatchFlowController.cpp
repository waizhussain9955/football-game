#include "Managers/StrikerMatchFlowController.h"
#include "StrikerLog.h" // Assuming this is linked via ProjectStrikerCore

void UStrikerMatchFlowController::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    CurrentState = EStrikerMatchState::Booting;
}

void UStrikerMatchFlowController::StartMatch() { TransitionToState(EStrikerMatchState::Loading); }
void UStrikerMatchFlowController::PauseMatch(EStrikerPauseState PauseType) {}
void UStrikerMatchFlowController::ResumeMatch() {}
void UStrikerMatchFlowController::RestartMatch() {}
void UStrikerMatchFlowController::EndMatch() { TransitionToState(EStrikerMatchState::FullTime); }
void UStrikerMatchFlowController::AbortMatch() { TransitionToState(EStrikerMatchState::Finished); }

void UStrikerMatchFlowController::TransitionToState(EStrikerMatchState NewState)
{
    // Enforcement of valid transitions would go here
    CurrentState = NewState;
    // Broadcast FMatchStateChangedMessage via GameplayMessageSubsystem
}

void UStrikerMatchFlowController::ExecuteFailureRecovery(const FString& Reason)
{
    // Retry -> Backup -> Abort Match pipeline
    AbortMatch();
}

void UStrikerMatchFlowController::DebugPrintStatus()
{
    UE_LOG(LogTemp, Warning, TEXT("MatchFlowController State: %d"), (int32)CurrentState);
}
