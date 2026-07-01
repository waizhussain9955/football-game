#include "StrikerGameModeBase.h"
#include "StrikerGameStateBase.h"

AStrikerGameModeBase::AStrikerGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	GameStateClass = AStrikerGameStateBase::StaticClass();
}

void AStrikerGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	// Initialize match
}

void AStrikerGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	// Update match logic, e.g. checking match time if not handled by GameState
}

void AStrikerGameModeBase::StartKickoff()
{
	// Logic to resume play
}

void AStrikerGameModeBase::EndHalfTime()
{
	// Logic to end half time and setup second half
}

void AStrikerGameModeBase::GoalScored(int32 TeamIndex)
{
	// Logic to handle goal scoring (update score, reset positions)
}
