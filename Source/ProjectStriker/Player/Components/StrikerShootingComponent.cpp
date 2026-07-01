#include "StrikerShootingComponent.h"

UStrikerShootingComponent::UStrikerShootingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStrikerShootingComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UStrikerShootingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UStrikerShootingComponent::ExecuteShot(float Power, float Spin, float Curve)
{
}

void UStrikerShootingComponent::ExecuteFinesseShot(float Power)
{
}
