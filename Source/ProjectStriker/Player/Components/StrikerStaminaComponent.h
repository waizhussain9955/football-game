#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerStaminaComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKER_API UStrikerStaminaComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStrikerStaminaComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
	float CurrentStamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
	float MaxStamina;

	UFUNCTION(BlueprintCallable, Category = "Stamina")
	void DepleteStamina(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Stamina")
	void RecoverStamina(float Amount);
};
