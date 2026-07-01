#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerLocomotionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerLocomotionComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerLocomotionComponent();
protected:
    virtual void BeginPlay() override;
public:	
    // Interfaces / Delegate Hooks
};
