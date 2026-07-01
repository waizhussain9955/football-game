#include "StrikerCharacter.h"
#include "Components/StrikerLocomotionComponent.h"
#include "Components/StrikerBallControlComponent.h"
#include "Components/StrikerActionComponent.h"
#include "Components/StrikerTackleComponent.h"

AStrikerCharacter::AStrikerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	LocomotionComp = CreateDefaultSubobject<UStrikerLocomotionComponent>(TEXT("LocomotionComp"));
	BallControlComp = CreateDefaultSubobject<UStrikerBallControlComponent>(TEXT("BallControlComp"));
	ActionComp = CreateDefaultSubobject<UStrikerActionComponent>(TEXT("ActionComp"));
	TackleComp = CreateDefaultSubobject<UStrikerTackleComponent>(TEXT("TackleComp"));

	TeamIndex = 0;
}

void AStrikerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AStrikerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AStrikerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
