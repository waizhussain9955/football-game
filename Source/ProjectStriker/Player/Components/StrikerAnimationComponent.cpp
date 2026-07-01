#include "StrikerAnimationComponent.h"
#include "GameFramework/Character.h"

UStrikerAnimationComponent::UStrikerAnimationComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStrikerAnimationComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UStrikerAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UStrikerAnimationComponent::PlayDynamicMontage(UAnimMontage* MontageToPlay, float PlayRate)
{
	if (ACharacter* Owner = Cast<ACharacter>(GetOwner()))
	{
		Owner->PlayAnimMontage(MontageToPlay, PlayRate);
	}
}
