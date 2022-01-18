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

	override void OnSyncJuncture(int pJunctureID, ParamsReadContext pCtx)
	{
		if (GetGame().IsDedicatedServer())
		{
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_INJURY) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_PLAYER_STATES) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_QUICKBAR_SET_SHORTCUT) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_INVENTORY) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_INVENTORY_REPAIR) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_ACTION_INTERRUPT) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_ACTION_ACK_ACCEPT) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_ACTION_ACK_REJECT) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_WEAPON_ACTION_ACK_ACCEPT) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_WEAPON_ACTION_ACK_REJECT) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_WEAPON_SET_JAMMING_CHANCE) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_UNCONSCIOUSNESS) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_PLAYER_ADD_MODIFIER) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_KURU_REQUEST) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_GESTURE_REQUEST) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_WEAPON_LIFT) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_DELETE_ITEM) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_BROKEN_LEGS) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_SHOCK) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_STAMINA) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_STAMINA_MISC) return;
		}

		super.OnSyncJuncture(pJunctureID, pCtx);
	}

	override bool OnInputUserDataProcess(int userDataType, ParamsReadContext ctx)
	{
		if (GetGame().IsDedicatedServer())
		{
		}

		return super.OnInputUserDataProcess(userDataType, ctx);
	}

	override void OnGameplayDataHandlerSync()
	{
		if (GetGame().IsDedicatedServer())
			return;

		super.OnGameplayDataHandlerSync();
	}
};
