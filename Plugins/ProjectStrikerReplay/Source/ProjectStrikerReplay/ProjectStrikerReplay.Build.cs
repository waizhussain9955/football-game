using UnrealBuildTool;

public class ProjectStrikerReplay : ModuleRules
{
	public ProjectStrikerReplay(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "ProjectStrikerCore" });
	}
}
