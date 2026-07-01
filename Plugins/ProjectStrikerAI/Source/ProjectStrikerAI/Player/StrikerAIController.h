#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "StrikerTacticalRoles.h"
#include "StrikerAIController.generated.h"

class UStateTree;

UCLASS()
class PROJECTSTRIKERAI_API AStrikerAIController : public AAIController
{
	GENERATED_BODY()

public:
	AStrikerAIController();

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Tactics")
	EStrikerTacticalRole AssignedRole;

	// In a real project, we would use UStateTreeComponent. 
	// For architecture setup, we store references to the State Trees.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|StateTree")
	UStateTree* ActiveStateTree;

	UFUNCTION(BlueprintCallable, Category = "AI|Tactics")
	void AssignRole(EStrikerTacticalRole NewRole, UStateTree* RoleStateTree);
};
