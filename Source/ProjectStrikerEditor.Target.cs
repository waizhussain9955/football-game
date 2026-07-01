using UnrealBuildTool;
using System.Collections.Generic;

public class ProjectStrikerEditorTarget : TargetRules
{
	public ProjectStrikerEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5; // Update as needed for 5.6
		ExtraModuleNames.Add("ProjectStriker");
	}
}
