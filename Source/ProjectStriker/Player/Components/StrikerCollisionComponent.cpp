#include "StrikerCollisionComponent.h"

UStrikerCollisionComponent::UStrikerCollisionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStrikerCollisionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UStrikerCollisionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UStrikerCollisionComponent::HandlePlayerCollision(AActor* OtherPlayer)
{
}
