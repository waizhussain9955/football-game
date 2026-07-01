#include "StrikerGameStateBase.h"

AStrikerGameStateBase::AStrikerGameStateBase()
{
	CurrentPhase = EMatchPhase::PreMatch;
	TeamBlueScore = 0;
	TeamRedScore = 0;
	MatchTimeSeconds = 0.0f;
}

void AStrikerGameStateBase::UpdateMatchTime(float DeltaTime)
{
	if (CurrentPhase == EMatchPhase::FirstHalf || CurrentPhase == EMatchPhase::SecondHalf)
	{
		MatchTimeSeconds += DeltaTime;
	}
}

void AStrikerGameStateBase::AddScore(int32 TeamIndex, int32 Points)
{
	if (TeamIndex == 0) // Assume 0 is Blue
	{
		TeamBlueScore += Points;
	}
	else if (TeamIndex == 1) // Assume 1 is Red
	{
		TeamRedScore += Points;
	}
}
