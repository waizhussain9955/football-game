#include "StrikerStadium.h"
#include "Components/StaticMeshComponent.h"
#include "Components/DirectionalLightComponent.h"
#include "Components/SkyLightComponent.h"

AStrikerStadium::AStrikerStadium()
{
	PrimaryActorTick.bCanEverTick = true;

	PitchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PitchMesh"));
	RootComponent = PitchMesh;

	SunLight = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("SunLight"));
	SunLight->SetupAttachment(RootComponent);
	SunLight->SetMobility(EComponentMobility::Movable); // For dynamic time of day

	SkyLight = CreateDefaultSubobject<USkyLightComponent>(TEXT("SkyLight"));
	SkyLight->SetupAttachment(RootComponent);
}

void AStrikerStadium::BeginPlay()
{
	Super::BeginPlay();
}

void AStrikerStadium::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AStrikerStadium::UpdateWeather(float CloudCoverage, float RainIntensity)
{
	// Adjust lighting, volumetric clouds, and spawn rain particles
}
