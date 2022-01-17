modded class LandMineTrap
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		if (GetGame().IsDedicatedServer())
		{
			if (rpc_type == SoundTypeMine.DISARMING) return;
		}

		super.OnRPC(sender, rpc_type, ctx);
	}
};
