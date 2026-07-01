#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerRotationComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerRotationComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerRotationComponent();
protected:
    virtual void BeginPlay() override;
public:	
    // Interfaces / Delegate Hooks
};
