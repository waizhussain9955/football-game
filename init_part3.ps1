$BaseDir = "d:\football-game"

# 1. Directories
$Dirs = @("Build", "Developer", "Documentation", "Tests", "Tools", "Scripts")
foreach ($d in $Dirs) {
    New-Item -ItemType Directory -Force -Path "$BaseDir\$d" | Out-Null
}

# 2. VCS & Standard Files
Set-Content -Path "$BaseDir\.gitignore" -Value @"
Binaries/
Build/
DerivedDataCache/
Intermediate/
Saved/
.vs/
*.sln
*.suo
*.opensdf
*.sdf
*.VC.db
*.VC.opendb
"@

Set-Content -Path "$BaseDir\.gitattributes" -Value @"
*.uasset filter=lfs diff=lfs merge=lfs -text
*.umap filter=lfs diff=lfs merge=lfs -text
"@

Set-Content -Path "$BaseDir\.editorconfig" -Value @"
root = true
[*]
indent_style = tab
indent_size = 4
end_of_line = crlf
charset = utf-8
trim_trailing_whitespace = true
insert_final_newline = true
"@

Set-Content -Path "$BaseDir\.clang-format" -Value @"
BasedOnStyle: LLVM
IndentWidth: 4
UseTab: Always
BreakBeforeBraces: Allman
AllowShortIfStatementsOnASingleLine: false
IndentCaseLabels: true
ColumnLimit: 120
"@

Set-Content -Path "$BaseDir\CHANGELOG.md" -Value "# Changelog`n`nAll notable changes to Project Striker will be documented in this file.`n"
Set-Content -Path "$BaseDir\LICENSE" -Value "Copyright (c) 2026. All rights reserved."

# 3. New Plugins
$NewPlugins = @("ProjectStrikerReplay", "ProjectStrikerAudio", "ProjectStrikerUI", "ProjectStrikerDeveloper", "ProjectStrikerTesting")
foreach ($Plugin in $NewPlugins) {
    $PluginDir = "$BaseDir\Plugins\$Plugin"
    $SourceDir = "$PluginDir\Source\$Plugin"
    New-Item -ItemType Directory -Force -Path $SourceDir | Out-Null

    $upluginContent = @"
{
	"FileVersion": 3,
	"Version": 1,
	"VersionName": "1.0",
	"FriendlyName": "$Plugin",
	"Description": "$Plugin module for Project Striker.",
	"Category": "Gameplay",
	"CreatedBy": "Waiz",
	"CanContainContent": true,
	"IsBetaVersion": false,
	"IsExperimentalVersion": false,
	"Installed": false,
	"Modules": [
		{
			"Name": "$Plugin",
			"Type": "Runtime",
			"LoadingPhase": "Default"
		}
	],
	"Plugins": [
		{
			"Name": "ProjectStrikerCore",
			"Enabled": true
		}
	]
}
"@
    Set-Content -Path "$PluginDir\$Plugin.uplugin" -Value $upluginContent

    $buildCsContent = @"
using UnrealBuildTool;

public class $Plugin : ModuleRules
{
	public $Plugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "ProjectStrikerCore" });
	}
}
"@
    Set-Content -Path "$SourceDir\$Plugin.Build.cs" -Value $buildCsContent
}

# 4. Core Logging Headers
$CorePublicDir = "$BaseDir\Plugins\ProjectStrikerCore\Source\ProjectStrikerCore\Public"
$CorePrivateDir = "$BaseDir\Plugins\ProjectStrikerCore\Source\ProjectStrikerCore\Private"
New-Item -ItemType Directory -Force -Path $CorePublicDir | Out-Null
New-Item -ItemType Directory -Force -Path $CorePrivateDir | Out-Null

Set-Content -Path "$CorePublicDir\StrikerLog.h" -Value @"
#pragma once
#include "CoreMinimal.h"

PROJECTSTRIKERCORE_API DECLARE_LOG_CATEGORY_EXTERN(LogGameplay, Log, All);
PROJECTSTRIKERCORE_API DECLARE_LOG_CATEGORY_EXTERN(LogAI, Log, All);
PROJECTSTRIKERCORE_API DECLARE_LOG_CATEGORY_EXTERN(LogAnimation, Log, All);
PROJECTSTRIKERCORE_API DECLARE_LOG_CATEGORY_EXTERN(LogPhysics, Log, All);
PROJECTSTRIKERCORE_API DECLARE_LOG_CATEGORY_EXTERN(LogReplay, Log, All);
PROJECTSTRIKERCORE_API DECLARE_LOG_CATEGORY_EXTERN(LogRules, Log, All);
PROJECTSTRIKERCORE_API DECLARE_LOG_CATEGORY_EXTERN(LogAudio, Log, All);
PROJECTSTRIKERCORE_API DECLARE_LOG_CATEGORY_EXTERN(LogCamera, Log, All);
PROJECTSTRIKERCORE_API DECLARE_LOG_CATEGORY_EXTERN(LogSave, Log, All);
PROJECTSTRIKERCORE_API DECLARE_LOG_CATEGORY_EXTERN(LogNetworking, Log, All);
PROJECTSTRIKERCORE_API DECLARE_LOG_CATEGORY_EXTERN(LogUI, Log, All);
"@

Set-Content -Path "$CorePrivateDir\StrikerLog.cpp" -Value @"
#include "StrikerLog.h"

DEFINE_LOG_CATEGORY(LogGameplay);
DEFINE_LOG_CATEGORY(LogAI);
DEFINE_LOG_CATEGORY(LogAnimation);
DEFINE_LOG_CATEGORY(LogPhysics);
DEFINE_LOG_CATEGORY(LogReplay);
DEFINE_LOG_CATEGORY(LogRules);
DEFINE_LOG_CATEGORY(LogAudio);
DEFINE_LOG_CATEGORY(LogCamera);
DEFINE_LOG_CATEGORY(LogSave);
DEFINE_LOG_CATEGORY(LogNetworking);
DEFINE_LOG_CATEGORY(LogUI);
"@

# 5. Configurations
$ConfigDir = "$BaseDir\Config"
New-Item -ItemType Directory -Force -Path $ConfigDir | Out-Null

Set-Content -Path "$ConfigDir\DefaultEditor.ini" -Value "[EditorLevelStats]`n`n"
Set-Content -Path "$ConfigDir\DefaultScalability.ini" -Value "[ScalabilitySettings]`nPerfIndexThresholds_ResolutionQuality=50 70 100 100`n"
Set-Content -Path "$ConfigDir\DefaultDeviceProfiles.ini" -Value "[DeviceProfiles]`n`n"
Set-Content -Path "$ConfigDir\CollisionProfiles.ini" -Value "[/Script/Engine.CollisionProfile]`nProfiles=(Name=`"Player`",CollisionEnabled=QueryAndPhysics,ObjectTypeName=`"Pawn`")`nProfiles=(Name=`"Ball`",CollisionEnabled=QueryAndPhysics,ObjectTypeName=`"PhysicsBody`")`n"
Set-Content -Path "$ConfigDir\Physics.ini" -Value "[/Script/Engine.PhysicsSettings]`nMaxSubsteps=6`nMaxSubstepDeltaTime=0.016667`n"
Set-Content -Path "$ConfigDir\Audio.ini" -Value "[/Script/Engine.AudioSettings]`nDefaultAudioBuses=`n"
Set-Content -Path "$ConfigDir\Rendering.ini" -Value "[/Script/Engine.RendererSettings]`nr.Nanite=True`nr.Lumen.TraceMeshSDFs=1`n"

# Gameplay Tags config
Set-Content -Path "$ConfigDir\DefaultGameplayTags.ini" -Value @"
[/Script/GameplayTags.GameplayTagsSettings]
GameplayTagList=(Tag="State.Match.Starting",DevComment="Match is about to begin")
GameplayTagList=(Tag="State.Match.Playing",DevComment="Match is ongoing")
GameplayTagList=(Tag="State.Match.HalfTime",DevComment="Half time break")
GameplayTagList=(Tag="State.Match.Ended",DevComment="Match is finished")
GameplayTagList=(Tag="State.Player.Sprinting",DevComment="")
GameplayTagList=(Tag="State.Player.Passing",DevComment="")
GameplayTagList=(Tag="State.Player.Shooting",DevComment="")
GameplayTagList=(Tag="State.Player.Tackling",DevComment="")
GameplayTagList=(Tag="State.Player.Injured",DevComment="")
GameplayTagList=(Tag="State.Team.Attacking",DevComment="")
GameplayTagList=(Tag="State.Team.Defending",DevComment="")
GameplayTagList=(Tag="State.Ball.Free",DevComment="")
GameplayTagList=(Tag="State.Ball.Controlled",DevComment="")
GameplayTagList=(Tag="Rule.Offside",DevComment="")
GameplayTagList=(Tag="Rule.Foul",DevComment="")
GameplayTagList=(Tag="Rule.Penalty",DevComment="")
GameplayTagList=(Tag="Rule.ThrowIn",DevComment="")
GameplayTagList=(Tag="Rule.Corner",DevComment="")
GameplayTagList=(Tag="Rule.GoalKick",DevComment="")
"@

Write-Output "Part 3 Initialization script complete."
