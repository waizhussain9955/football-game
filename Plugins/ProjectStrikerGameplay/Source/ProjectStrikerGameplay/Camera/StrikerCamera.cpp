#include "StrikerCamera.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AStrikerCamera::AStrikerCamera()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->bDoCollisionTest = false;
	RootComponent = SpringArmComp;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);
	
	CameraType = TEXT("Broadcast");
}

void AStrikerCamera::BeginPlay()
{
	Super::BeginPlay();
}

void AStrikerCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AStrikerCamera::TrackTarget(FVector TargetLocation, float DeltaTime)
{
	// Smoothly interpolate camera look at or position depending on CameraType
}
