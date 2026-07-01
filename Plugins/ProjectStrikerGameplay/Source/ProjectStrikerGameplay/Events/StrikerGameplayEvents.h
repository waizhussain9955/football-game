#pragma once
#include "CoreMinimal.h"
#include "StrikerGameplayEvents.generated.h"

UENUM(BlueprintType)
enum class EStrikerMatchState : uint8
{
    Booting, Loading, Preparing, Warmup, CoinToss, Kickoff, Playing,
    BallOutOfPlay, SetPiece, HalfTime, AddedTime, FullTime, Replay, Paused, Finished
};

UENUM(BlueprintType)
enum class EStrikerPauseState : uint8
{
    None, GameplayPause, ReplayPause, SystemPause, LoadingPause, MenuPause
};

USTRUCT(BlueprintType)
struct PROJECTSTRIKERGAMEPLAY_API FMatchStateChangedMessage
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite)
    EStrikerMatchState NewState;
};

USTRUCT(BlueprintType)
struct PROJECTSTRIKERGAMEPLAY_API FGoalScoredMessage
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite)
    int32 StrikerID;
    UPROPERTY(BlueprintReadWrite)
    int32 AssistID;
};

USTRUCT(BlueprintType)
struct PROJECTSTRIKERGAMEPLAY_API FKickoffMessage { GENERATED_BODY() };

USTRUCT(BlueprintType)
struct PROJECTSTRIKERGAMEPLAY_API FHalfTimeMessage { GENERATED_BODY() };

USTRUCT(BlueprintType)
struct PROJECTSTRIKERGAMEPLAY_API FFoulCommittedMessage
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite)
    int32 AggressorID;
    UPROPERTY(BlueprintReadWrite)
    int32 VictimID;
};

USTRUCT(BlueprintType)
struct PROJECTSTRIKERGAMEPLAY_API FSubstitutionMessage { GENERATED_BODY() };

UENUM(BlueprintType)
enum class EStrikerMovementState : uint8
{
    Idle, Walk, Jog, Run, Sprint, Accelerating, Decelerating,
    TurnLeft, TurnRight, Pivot, Stop, Backpedal, StrafeLeft, StrafeRight,
    Jump, Land, Recover, Stunned, Fallen, GettingUp, Disabled
};

UENUM(BlueprintType)
enum class EStrikerPlayerStatus : uint8
{
    Alive, Active, Recovering, Disabled
};

UENUM(BlueprintType)
enum class EStrikerBallState : uint8
{
    Idle, Ready, Kickoff, Controlled, Loose, Rolling, Sliding, Airborne, Curving, Bouncing, Deflected, Intercepted, OutOfPlay, Goal, Replay, Frozen, Destroyed
};
