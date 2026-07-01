#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerHeadingComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerHeadingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStrikerHeadingComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Heading")
	void AttemptHeaderClearance();

	UFUNCTION(BlueprintCallable, Category = "Heading")
	void AttemptHeaderShot();
};
