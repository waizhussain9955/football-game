#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StrikerCamera.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class PROJECTSTRIKERGAMEPLAY_API AStrikerCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	AStrikerCamera();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Settings")
	FName CameraType; // e.g., "Broadcast", "DynamicFollow", "Goal"

	UFUNCTION(BlueprintCallable, Category = "Camera")
	void TrackTarget(FVector TargetLocation, float DeltaTime);
};
