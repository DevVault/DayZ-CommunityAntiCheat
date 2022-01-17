modded class ToolBase
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		if (GetGame().IsDedicatedServer())
		{
			if (rpc_type == PlantType.TREE_HARD) return;
			if (rpc_type == PlantType.TREE_SOFT) return;
			if (rpc_type == PlantType.BUSH_HARD) return;
			if (rpc_type == PlantType.BUSH_SOFT) return;
		}

		super.OnRPC(sender, rpc_type, ctx);
	}
};
