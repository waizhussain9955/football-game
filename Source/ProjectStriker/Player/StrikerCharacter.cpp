#include "StrikerCharacter.h"
#include "Components/StrikerLocomotionComponent.h"
#include "Components/StrikerBallControlComponent.h"
#include "Components/StrikerActionComponent.h"
#include "Components/StrikerTackleComponent.h"
#include "Components/StrikerAnimationComponent.h"
#include "Components/StrikerInputComponent.h"
#include "Components/StrikerPassingComponent.h"
#include "Components/StrikerShootingComponent.h"
#include "Components/StrikerCrossingComponent.h"
#include "Components/StrikerHeadingComponent.h"
#include "Components/StrikerCollisionComponent.h"
#include "Components/StrikerInteractionComponent.h"
#include "Components/StrikerStaminaComponent.h"
#include "Components/StrikerStatsComponent.h"

AStrikerCharacter::AStrikerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	LocomotionComp = CreateDefaultSubobject<UStrikerLocomotionComponent>(TEXT("LocomotionComp"));
	BallControlComp = CreateDefaultSubobject<UStrikerBallControlComponent>(TEXT("BallControlComp"));
	ActionComp = CreateDefaultSubobject<UStrikerActionComponent>(TEXT("ActionComp"));
	TackleComp = CreateDefaultSubobject<UStrikerTackleComponent>(TEXT("TackleComp"));
	AnimationComp = CreateDefaultSubobject<UStrikerAnimationComponent>(TEXT("AnimationComp"));
	StrikerInputComp = CreateDefaultSubobject<UStrikerInputComponent>(TEXT("StrikerInputComp"));
	PassingComp = CreateDefaultSubobject<UStrikerPassingComponent>(TEXT("PassingComp"));
	ShootingComp = CreateDefaultSubobject<UStrikerShootingComponent>(TEXT("ShootingComp"));
	CrossingComp = CreateDefaultSubobject<UStrikerCrossingComponent>(TEXT("CrossingComp"));
	HeadingComp = CreateDefaultSubobject<UStrikerHeadingComponent>(TEXT("HeadingComp"));
	CollisionComp = CreateDefaultSubobject<UStrikerCollisionComponent>(TEXT("CollisionComp"));
	InteractionComp = CreateDefaultSubobject<UStrikerInteractionComponent>(TEXT("InteractionComp"));
	StaminaComp = CreateDefaultSubobject<UStrikerStaminaComponent>(TEXT("StaminaComp"));
	StatsComp = CreateDefaultSubobject<UStrikerStatsComponent>(TEXT("StatsComp"));

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
