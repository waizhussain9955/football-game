#include "StrikerRefereeManager.h"
#include "Entities/StrikerBall.h"
#include "Player/StrikerCharacter.h"

void UStrikerRefereeManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UStrikerRefereeManager::ReportFoul(AStrikerCharacter* Offender, AStrikerCharacter* Victim)
{
	// Pause play, assess card, setup freekick
}

void UStrikerRefereeManager::CheckOffside(AStrikerBall* Ball, AStrikerCharacter* PassingPlayer)
{
	// Query player positions to detect offside infractions
}
