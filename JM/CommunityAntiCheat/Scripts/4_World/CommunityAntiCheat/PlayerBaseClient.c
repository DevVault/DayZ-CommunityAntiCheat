modded class PlayerBaseClient
{
	override void OnGameplayDataHandlerSync()
	{
		if (GetGame().IsDedicatedServer())
			return;

		super.OnGameplayDataHandlerSync();
	}
};
