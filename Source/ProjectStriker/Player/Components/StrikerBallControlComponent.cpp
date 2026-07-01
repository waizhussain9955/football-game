#include "StrikerBallControlComponent.h"

UStrikerBallControlComponent::UStrikerBallControlComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	ControlledBall = nullptr;
}

void UStrikerBallControlComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UStrikerBallControlComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// Handle dribbling logic, keeping the ball near the player's feet
}

bool UStrikerBallControlComponent::HasPossession() const
{
	return ControlledBall != nullptr;
}

void UStrikerBallControlComponent::ReceiveBall(AStrikerBall* Ball)
{
	ControlledBall = Ball;
	// Attach ball or start updating its position in tick
}

void UStrikerBallControlComponent::ReleaseBall()
{
	ControlledBall = nullptr;
}
