modded class WrittenNoteData
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		if (GetGame().IsDedicatedServer())
		{
			if (rpc_type == ERPCs.RPC_WRITE_NOTE) return;
			if (rpc_type == ERPCs.RPC_READ_NOTE) return;
		}

		super.OnRPC(sender, rpc_type, ctx);
	}
};
