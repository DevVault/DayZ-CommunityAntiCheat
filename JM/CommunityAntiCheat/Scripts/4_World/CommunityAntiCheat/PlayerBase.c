modded class PlayerBase
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		if (GetGame().IsDedicatedServer())
		{
			if (rpc_type == ERPCs.RPC_SYNC_DISPLAY_STATUS) return;
			if (rpc_type == ERPCs.RPC_PLAYER_SYMPTOM_ON) return;
			if (rpc_type == ERPCs.RPC_PLAYER_SYMPTOM_OFF) return;
			if (rpc_type == ERPCs.RPC_CHECK_PULSE) return;
			if (rpc_type == ERPCs.RPC_PLAYER_SYMPTOMS_DEBUG_ON) return;
			if (rpc_type == ERPCs.RPC_PLAYER_SYMPTOMS_DEBUG) return;
			if (rpc_type == ERPCs.RPC_PLAYER_SYMPTOMS_EXIT) return;
			if (rpc_type == ERPCs.RPC_USER_ACTION_MESSAGE) return;
			if (rpc_type == ERPCs.RPC_STAMINA) return;
			if (rpc_type == ERPCs.RPC_SHOCK) return;
			if (rpc_type == ERPCs.RPC_ON_SET_CAPTIVE) return;
			if (rpc_type == ERPCs.RPC_DAMAGE_VALUE_SYNC) return;
			if (rpc_type == ERPCs.RPC_DEBUG_MONITOR_FLT) return;
			if (rpc_type == ERPCs.RPC_DEBUG_MONITOR_STR) return;
			if (rpc_type == ERPCs.RPC_SOFT_SKILLS_SPECIALTY_SYNC) return;
			if (rpc_type == ERPCs.RPC_SOFT_SKILLS_STATS_SYNC) return;
			if (rpc_type == ERPCs.DEV_PLAYER_DEBUG_DATA) return;
			if (rpc_type == ERPCs.DEV_AGENT_GROW) return;
			if (rpc_type == ERPCs.RPC_SYNC_THERMOMETER) return;
			if (rpc_type == ERPCs.DEV_RPC_AGENT_RESET) return;
			if (rpc_type == PlantType.TREE_HARD) return;
			if (rpc_type == PlantType.TREE_SOFT) return;
			if (rpc_type == PlantType.BUSH_HARD) return;
			if (rpc_type == PlantType.BUSH_SOFT) return;
		}

		super.OnRPC(sender, rpc_type, ctx);
	}

	override void OnGameplayDataHandlerSync()
	{
		if (GetGame().IsDedicatedServer())
			return;

		super.OnGameplayDataHandlerSync();
	}
};
