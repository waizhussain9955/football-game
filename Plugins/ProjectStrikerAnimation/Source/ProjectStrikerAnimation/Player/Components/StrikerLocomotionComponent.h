#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerLocomotionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERANIMATION_API UStrikerLocomotionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStrikerLocomotionComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Locomotion")
	void SetSprinting(bool bIsSprinting);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locomotion")
	float BaseSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locomotion")
	float SprintSpeed;
};
