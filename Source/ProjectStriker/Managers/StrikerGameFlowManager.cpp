#include "StrikerGameFlowManager.h"

void UStrikerGameFlowManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UStrikerGameFlowManager::TransitionToPhase(uint8 NewPhase)
{
	// Broadcast phase change to other systems
}
