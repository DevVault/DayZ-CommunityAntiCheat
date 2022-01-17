modded class DayZPlayerImplement
{
	override void OnSyncJuncture(int pJunctureID, ParamsReadContext pCtx)
	{
		if (GetGame().IsDedicatedServer())
		{
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_DEATH) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_DAMAGE_HIT) return;
			if (pJunctureID == DayZPlayerSyncJunctures.SJ_WEAPON_RAISE_COMPLETED) return;
		}

		super.OnSyncJuncture(pJunctureID, pCtx);
	}
};
