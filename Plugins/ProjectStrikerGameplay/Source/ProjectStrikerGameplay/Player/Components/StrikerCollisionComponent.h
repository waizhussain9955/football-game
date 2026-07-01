#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StrikerCollisionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSTRIKERGAMEPLAY_API UStrikerCollisionComponent : public UActorComponent
{
    GENERATED_BODY()
public:	
    UStrikerCollisionComponent();
protected:
    virtual void BeginPlay() override;
public:	
    // Interfaces / Delegate Hooks
};
