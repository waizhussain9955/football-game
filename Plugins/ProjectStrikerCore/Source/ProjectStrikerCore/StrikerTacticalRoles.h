#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EStrikerTacticalRole : uint8
{
	Goalkeeper UMETA(DisplayName = "Goalkeeper"),
	CenterBack UMETA(DisplayName = "Center Back"),
	FullBack UMETA(DisplayName = "Full Back"),
	DefensiveMidfielder UMETA(DisplayName = "Defensive Midfielder"),
	CentralMidfielder UMETA(DisplayName = "Central Midfielder"),
	AttackingMidfielder UMETA(DisplayName = "Attacking Midfielder"),
	LeftWing UMETA(DisplayName = "Left Wing"),
	RightWing UMETA(DisplayName = "Right Wing"),
	SecondStriker UMETA(DisplayName = "Second Striker"),
	Striker UMETA(DisplayName = "Striker")
};
