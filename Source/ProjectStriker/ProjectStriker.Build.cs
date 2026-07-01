using UnrealBuildTool;

public class ProjectStriker : ModuleRules
{
	public ProjectStriker(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore",
			"EnhancedInput",
			"ProjectStrikerCore",
			"ProjectStrikerGameplay",
			"ProjectStrikerAI",
			"ProjectStrikerPhysics",
			"ProjectStrikerAnimation"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
