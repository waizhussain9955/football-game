#include "StrikerPossessionManager.h"
#include "Player/StrikerCharacter.h"

void UStrikerPossessionManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentPossessor = nullptr;
	PossessingTeamIndex = -1;
}

void UStrikerPossessionManager::SetPossession(AStrikerCharacter* NewPossessor, int32 TeamIndex)
{
	CurrentPossessor = NewPossessor;
	PossessingTeamIndex = TeamIndex;
	// Broadcast possession change to AI and HUD
}

void UStrikerPossessionManager::ClearPossession()
{
	CurrentPossessor = nullptr;
	// Note: Team index might remain the same for loose balls
}
