#include "StrikerActionComponent.h"
#include "StrikerBallControlComponent.h"

UStrikerActionComponent::UStrikerActionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStrikerActionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UStrikerActionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UStrikerActionComponent::PassBall(FVector TargetDirection, float Power)
{
	// Ensure owner has ball possession, apply impulse, update state
}

void UStrikerActionComponent::ShootBall(FVector TargetDirection, float Power)
{
	// Calculate shot trajectory and apply force
}

void UStrikerActionComponent::CrossBall(FVector TargetDirection, float Power)
{
	// Calculate lob/cross trajectory
}
