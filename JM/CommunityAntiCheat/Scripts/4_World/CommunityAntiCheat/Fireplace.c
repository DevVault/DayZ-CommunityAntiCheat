modded class Fireplace
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		if (GetGame().IsDedicatedServer())
		{
			if (rpc_type == FirePlaceFailure.WIND) return;
			if (rpc_type == FirePlaceFailure.WET) return;
		}

		super.OnRPC(sender, rpc_type, ctx);
	}
};
