#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerInteractionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKER_API UStrikerInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStrikerInteractionComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void InteractWithBall();
};
