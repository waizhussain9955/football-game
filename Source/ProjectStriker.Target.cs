using UnrealBuildTool;
using System.Collections.Generic;

public class ProjectStrikerTarget : TargetRules
{
	public ProjectStrikerTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5; // Update as needed for 5.6
		ExtraModuleNames.Add("ProjectStriker");
	}
}
