#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerDebugComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerDebugComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerDebugComponent();
protected:
    virtual void BeginPlay() override;
public:	
    // Interfaces / Delegate Hooks
};
