modded class ItemBase
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		if (GetGame().IsDedicatedServer())
		{
			if (rpc_type == ERPCs.RPC_SOUND_LOCK_ATTACH) return;
		}

		super.OnRPC(sender, rpc_type, ctx);
	}
};
