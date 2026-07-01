import os

core_base = r"d:\football-game\Plugins\ProjectStrikerCore\Source\ProjectStrikerCore"

cam_dir = os.path.join(core_base, "Presentation", "Camera")
ui_dir = os.path.join(core_base, "Presentation", "UI")
aud_dir = os.path.join(core_base, "Presentation", "Audio")
rep_dir = os.path.join(core_base, "Presentation", "Replay")
data_dir = os.path.join(core_base, "DataAssets", "Presentation")

os.makedirs(cam_dir, exist_ok=True)
os.makedirs(ui_dir, exist_ok=True)
os.makedirs(aud_dir, exist_ok=True)
os.makedirs(rep_dir, exist_ok=True)
os.makedirs(data_dir, exist_ok=True)

# 1. Generate Managers
managers = [
    ("StrikerCameraManager", "APlayerCameraManager", "Camera/PlayerCameraManager.h", cam_dir),
    ("StrikerHUDManager", "AHUD", "GameFramework/HUD.h", ui_dir),
    ("StrikerAudioManager", "UGameInstanceSubsystem", "Subsystems/GameInstanceSubsystem.h", aud_dir),
    ("StrikerReplayManager", "UGameInstanceSubsystem", "Subsystems/GameInstanceSubsystem.h", rep_dir)
]

for cls, parent, include, dir_path in managers:
    h_content = f"""#pragma once
#include "CoreMinimal.h"
#include "{include}"
#include "{cls}.generated.h"

UCLASS()
class PROJECTSTRIKERCORE_API {"A" if parent.startswith("A") else "U"}{cls} : public {parent}
{{
    GENERATED_BODY()
public:
    {"A" if parent.startswith("A") else "U"}{cls}();
}};
"""
    cpp_content = f"""#include "Presentation/{os.path.basename(dir_path)}/{cls}.h"

{"A" if parent.startswith("A") else "U"}{cls}::{"A" if parent.startswith("A") else "U"}{cls}()
{{
}}
"""
    with open(os.path.join(dir_path, f"{cls}.h"), "w") as f: f.write(h_content)
    with open(os.path.join(dir_path, f"{cls}.cpp"), "w") as f: f.write(cpp_content)


# 2. Generate Data Assets
data_assets = [
    "CameraProfile",
    "ReplayProfile",
    "HUDProfile",
    "AudioProfile",
    "CommentaryProfile",
    "CrowdProfile",
    "MusicProfile"
]

for da in data_assets:
    da_h = f"""#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "{da}.generated.h"

UCLASS(BlueprintType)
class PROJECTSTRIKERCORE_API U{da} : public UDataAsset
{{
    GENERATED_BODY()
public:
    // Configurable presentation properties to be defined in Blueprints
}};
"""
    da_cpp = f"""#include "DataAssets/Presentation/{da}.h"
"""
    with open(os.path.join(data_dir, f"{da}.h"), "w") as f: f.write(da_h)
    with open(os.path.join(data_dir, f"{da}.cpp"), "w") as f: f.write(da_cpp)

print("Part 10 Presentation generation complete.")
