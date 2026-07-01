using UnrealBuildTool;

public class ProjectStriker : ModuleRules
{
	public ProjectStriker(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "AIModule", "NavigationSystem" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
