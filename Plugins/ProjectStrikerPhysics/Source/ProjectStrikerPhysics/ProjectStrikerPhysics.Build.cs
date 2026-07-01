using UnrealBuildTool;

public class ProjectStrikerPhysics : ModuleRules
{
	public ProjectStrikerPhysics(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"ProjectStrikerCore"
			}
		);
	}
}
