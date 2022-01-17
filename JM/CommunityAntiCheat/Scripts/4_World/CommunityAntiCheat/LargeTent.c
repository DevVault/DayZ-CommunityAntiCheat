modded class LargeTent
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		if (GetGame().IsDedicatedServer())
		{
			if (rpc_type == SoundTypeTent.REPACK) return;
		}

		super.OnRPC(sender, rpc_type, ctx);
	}
};
