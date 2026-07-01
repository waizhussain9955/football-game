#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerStaminaComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerStaminaComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerStaminaComponent();
protected:
    virtual void BeginPlay() override;
public:	
    // Interfaces / Delegate Hooks
};
