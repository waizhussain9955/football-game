#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerTackleComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKER_API UStrikerTackleComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStrikerTackleComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Tackling")
	void PerformStandingTackle();

	UFUNCTION(BlueprintCallable, Category = "Tackling")
	void PerformSlidingTackle();
};
