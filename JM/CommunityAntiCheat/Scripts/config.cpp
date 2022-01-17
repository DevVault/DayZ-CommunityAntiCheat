#include "\JM\CommunityAntiCheat\Defines\CommunityAntiCheatDefines.c"

class CfgPatches
{
	class JM_CommunityAntiCheat_Scripts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
		};
	};
};

class CfgMods
{
	class JM_CommunityFramework
	{
		dir = "JM/CommunityAntiCheat";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 1;
		name = "Community Framework";
		credits = "Jacob_Mango, Arkensor";
		creditsJson = "JM/CommunityAntiCheat/Scripts/Data/Credits.json";
		version = "0.0.0";
		versionPath = "JM/CommunityAntiCheat/scripts/Data/Version.hpp";
		author = "Jacob_Mango";
		authorID = "76561198103677868"; 
		extra = 0;
		type = "mod";
		
		dependencies[] = { "Core", "Game", "World", "Mission" };
		
		class defs
		{
			class engineScriptModule
			{
				value = "";
				files[] =
				{
					"JM/CommunityAntiCheat/Defines",
					"JM/CommunityAntiCheat/Scripts/1_Core"
				};
			};
			class gameLibScriptModule
			{
				value = "";
				files[] =
				{
				    "JM/CommunityAntiCheat/Defines",
				    "JM/CommunityAntiCheat/Scripts/2_GameLib"
				};
			};
			class gameScriptModule
			{
				value = "CommunityAntiCheat_CreateGame";
				files[] =
				{
					"JM/CommunityAntiCheat/Defines",
					"JM/CommunityAntiCheat/Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = ""; //! Doesn't work
				files[] =
				{
					"JM/CommunityAntiCheat/Defines",
					"JM/CommunityAntiCheat/Scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] =
				{
					"JM/CommunityAntiCheat/Defines",
					"JM/CommunityAntiCheat/Scripts/5_Mission"
				};
			};
		};
	};
};
