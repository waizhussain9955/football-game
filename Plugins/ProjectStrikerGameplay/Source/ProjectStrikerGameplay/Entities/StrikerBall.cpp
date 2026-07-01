#include "StrikerBall.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Player/StrikerCharacter.h"

AStrikerBall::AStrikerBall()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(11.0f);
	CollisionComp->SetCollisionProfileName(TEXT("PhysicsActor"));
	CollisionComp->SetSimulatePhysics(true);
	CollisionComp->SetGenerateOverlapEvents(true);
	RootComponent = CollisionComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);

	MagnusCoefficient = 0.05f;
	GroundFrictionCoefficient = 0.3f;
	CurrentSpin = FVector::ZeroVector;
	LastTouchedBy = nullptr;
}

void AStrikerBall::BeginPlay()
{
	Super::BeginPlay();
}

void AStrikerBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CalculateMagnusEffect(DeltaTime);
	DetectGoalAndPossession();
}

void AStrikerBall::ApplyKickImpulse(FVector Direction, float Force, FVector SpinAmount)
{
	if (CollisionComp)
	{
		CollisionComp->AddImpulse(Direction.GetSafeNormal() * Force, NAME_None, true);
		CurrentSpin = SpinAmount;
	}
}

void AStrikerBall::CalculateMagnusEffect(float DeltaTime)
{
	if (!CollisionComp || CurrentSpin.IsNearlyZero()) return;

	FVector Velocity = CollisionComp->GetComponentVelocity();
	if (Velocity.IsNearlyZero()) return;

	// Calculate Magnus force: Fm = 1/2 * p * v^2 * A * Cl
	// Simplified directional lift calculation based on spin vector cross velocity
	FVector MagnusForce = FVector::CrossProduct(CurrentSpin, Velocity) * MagnusCoefficient;
	CollisionComp->AddForce(MagnusForce, NAME_None, true);

	// Dampen spin over time
	CurrentSpin = FMath::VInterpTo(CurrentSpin, FVector::ZeroVector, DeltaTime, 0.5f);
}

void AStrikerBall::DetectGoalAndPossession()
{
	// Trigger volumes will handle goal detection via overlaps
	// Subsystems monitor velocity changes and overlaps for possession updates
}
