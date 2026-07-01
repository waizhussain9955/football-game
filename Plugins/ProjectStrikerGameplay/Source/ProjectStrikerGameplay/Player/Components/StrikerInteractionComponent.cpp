#include "StrikerInteractionComponent.h"

UStrikerInteractionComponent::UStrikerInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStrikerInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UStrikerInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UStrikerInteractionComponent::InteractWithBall()
{
}
