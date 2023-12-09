// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LMG_T1 : ModuleRules
{
	public LMG_T1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
			{ "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "GameplayAbilities" });

		PrivateDependencyModuleNames.AddRange(new string[] {  "GameplayTags", "GameplayTasks" });

		
		// 如果你正在使用Slate UI，请取消注释以下代码
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// 如果你正在使用在线功能，请取消注释以下代码
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// 要包含OnlineSubsystemSteam，请在uproject文件的插件部分添加它，并将Enabled属性设置为true
	}
}