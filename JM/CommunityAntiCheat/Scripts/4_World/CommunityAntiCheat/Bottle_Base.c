modded class Bottle_Base
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		if (GetGame().IsDedicatedServer())
		{
			if (rpc_type == SoundTypeBottle.POURING) return;
			if (rpc_type == SoundTypeBottle.EMPTYING) return;
		}

		super.OnRPC(sender, rpc_type, ctx);
	}
};
