#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerShootingComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKER_API UStrikerShootingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStrikerShootingComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Shooting")
	void ExecuteShot(float Power, float Spin, float Curve);

	UFUNCTION(BlueprintCallable, Category = "Shooting")
	void ExecuteFinesseShot(float Power);
};
