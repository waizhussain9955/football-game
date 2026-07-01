#include "StrikerBall.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

AStrikerBall::AStrikerBall()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(11.0f); // standard football radius in cm
	CollisionComp->SetCollisionProfileName(TEXT("PhysicsActor"));
	CollisionComp->SetSimulatePhysics(true);
	RootComponent = CollisionComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);
}

void AStrikerBall::BeginPlay()
{
	Super::BeginPlay();
}

void AStrikerBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AStrikerBall::ApplyKickImpulse(FVector Direction, float Force)
{
	if (CollisionComp)
	{
		CollisionComp->AddImpulse(Direction.GetSafeNormal() * Force, NAME_None, true);
	}
}
