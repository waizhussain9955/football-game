#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StrikerStadium.generated.h"

class UStaticMeshComponent;
class UDirectionalLightComponent;
class USkyLightComponent;

UCLASS()
class PROJECTSTRIKER_API AStrikerStadium : public AActor
{
	GENERATED_BODY()
	
public:	
	AStrikerStadium();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stadium")
	UStaticMeshComponent* PitchMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Lighting")
	UDirectionalLightComponent* SunLight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Lighting")
	USkyLightComponent* SkyLight;

	UFUNCTION(BlueprintCallable, Category = "Environment")
	void UpdateWeather(float CloudCoverage, float RainIntensity);
};
