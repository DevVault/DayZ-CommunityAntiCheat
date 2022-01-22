#ifdef CF_MODULES
/**
 * @brief Simple module for checking to see if server PBO's are being used on the client. 
 */ 
[CF_RegisterModule(CAC_LodModule)]
class CAC_LodModule : CF_ModuleWorld
{
	autoptr array<ref Param2<string, int>> m_ValidObjects = new array<ref Param2<string, int>>();
	autoptr map<string, int> m_PlayerObject = new map<string, int>();

	autoptr array<ref Param2<int, int>> m_PlayerTime = new array<ref Param2<int, int>>();
	int m_CurrentIndex;

	int m_NoResponseKickTime;

	override void OnInit()
	{
		super.OnInit();

		auto stream = new CF_FileStream("$profile:ValidObjects.txt", FileMode.READ);
		auto reader = new CF_TextReader(stream);

		m_NoResponseKickTime = reader.ReadInt();

		while (!reader.EOF())
		{
			reader.ReadWhitespace();
			string object = reader.ReadWord();
			reader.ReadWhitespace();
			int lodCount = reader.ReadInt();

			if (object != string.Empty && lodCount != 0)
			{
				m_ValidObjects.Insert(new Param2<string, int>(object, lodCount));
			}
		}

		GetRPCManager().AddRPC("CAC_LodModule", "RPC_VerifyClient", this);
		GetRPCManager().AddRPC("CAC_LodModule", "RPC_VerifyServer", this);

		EnableUpdate();

		EnableClientReady();
		EnableClientDisconnect();
	}

	bool GetPlayerObject(PlayerIdentity identity, out PlayerBase player)
	{
		int networkLow, networkHigh;
		GetGame().GetPlayerNetworkIDByIdentityID(identity.GetPlayerId(), networkLow, networkHigh);
		return Class.CastTo(player, GetGame().GetObjectByNetworkId(networkLow, networkHigh));
	}

	bool GetPlayerObject(int playerIdentityID, out PlayerBase player)
	{
		int networkLow, networkHigh;
		GetGame().GetPlayerNetworkIDByIdentityID(playerIdentityID, networkLow, networkHigh);
		return Class.CastTo(player, GetGame().GetObjectByNetworkId(networkLow, networkHigh));
	}

	override void OnUpdate(Class sender, CF_EventArgs args)
	{
		super.OnUpdate(sender, args);

		auto update = CF_EventUpdateArgs.Cast(args);

		if (m_CurrentIndex >= m_PlayerTime.Count()) m_CurrentIndex = 0;
		if (m_PlayerTime.Count() == 0) return;

		auto player = m_PlayerTime[m_CurrentIndex];
		if (player.param2 + m_NoResponseKickTime >= GetGame().GetTime())
		{
			PlayerBase object;
			PlayerIdentity identity;
			if (GetPlayerObject(player.param1, object))
			{
				identity = object.GetIdentity();
				HandlePlayer(object, identity, identity.GetId(), true, true);
			}

			m_PlayerTime.Remove(m_CurrentIndex);
		}
		else
		{
			m_CurrentIndex++;
		}
	}

	override void OnClientReady(Class sender, CF_EventArgs args)
	{
		super.OnClientReady(sender, args);

		auto cArgs = CF_EventPlayerArgs.Cast(args);
		if (!cArgs.Identity)
		{
			CF_Log.Critical("Attempting to verify player with no identity!");
			return;
		}

		auto uid = cArgs.Identity.GetId();
		auto playerIdentityID = cArgs.Identity.GetPlayerId();
		auto index = m_ValidObjects.GetRandomIndex();
		if (index < 0)
		{
			CF_Log.Critical("No valid objects to compare to.");
			return;
		}

		auto object = m_ValidObjects[index];
		auto time = GetGame().GetTime();
		auto param = new Param2<int, int>(playerIdentityID, time);

		m_PlayerObject[uid] = index;
		m_PlayerTime.Insert(param);

		GetRPCManager().SendRPC("CAC_LodModule", "RPC_VerifyServer", new Param1<string>(object.param1), true, cArgs.Identity); 
	}
	
	override void OnClientDisconnect(Class sender, CF_EventArgs args)
	{
		super.OnClientDisconnect(sender, args);

		auto cArgs = CF_EventPlayerDisconnectedArgs.Cast(args);

		int playerIdentityId = cArgs.Identity.GetPlayerId();
		int count = m_PlayerTime.Count();
		for (int index = 0; index < count; index++)
		{
			if (m_PlayerTime[index].param1 != playerIdentityId) 
			{
				continue;
			}

			m_PlayerTime.Remove(index);
			break;
		}

		m_PlayerObject.Remove(cArgs.UID);
	}

	void RPC_VerifyServer(CallType type, ParamsReadContext ctx, PlayerIdentity identity, Object target)
	{
		Print("RPC_VerifyServer");
		if (GetGame().IsServer())
		{
			return;
		}

		Param1<string> params;
		if (!ctx.Read(params) || !params)
		{
			return;
		}

		Print(params.param1);

		Object spawned = GetGame().CreateObject(params.param1, "0 0 0", true);
		if (!spawned)
		{
			return;
		}

		array<LOD> lods = new array<LOD>();
		spawned.GetLODS(lods);

		GetRPCManager().SendRPC("CAC_LodModule", "RPC_VerifyClient", new Param2<string, int>(params.param1, lods.Count()), true, null); 
	}

	void RPC_VerifyClient(CallType type, ParamsReadContext ctx, PlayerIdentity identity, Object target)
	{
		if (GetGame().IsClient())
		{
			return;
		}

		bool verified = true;

		string uid;
		if (verified && !identity) verified = false;
		else if (verified && identity) uid = identity.GetId();

		PlayerBase player;
		if (verified) GetPlayerObject(identity, player);

		Param2<string, int> params;
		if (verified && (!ctx.Read(params) || !params)) verified = false;

		int index = m_PlayerObject[uid];
		if (verified && m_ValidObjects[index].param1 != params.param1) verified = false;
		if (verified && m_ValidObjects[index].param2 != params.param2) verified = false;

		HandlePlayer(player, identity, uid, !verified);
	}

	void HandlePlayer(PlayerBase player, PlayerIdentity identity, string uid, bool kick, bool isUpdate = false)
	{
		if (kick)
		{
			if (!identity)
			{
				CF_Log.Critical("Attempting to kick player with no identity!");
				return;
			}

			string name = identity.GetName();

			if (player)
			{
				player.OnDisconnect();

				if (GetHive())
				{
					player.Save();
					GetHive().CharacterExit(player);		
				}
				
				player.ReleaseNetworkControls();

				if (player.IsAlive() && !player.IsRestrained() && !player.IsUnconscious())
				{
					// remove the body
					player.Delete();	
				}
				else if (player.IsUnconscious() || player.IsRestrained())
				{
					// kill character
					player.SetHealth("", "", 0.0);
				}
			}

			GetGame().DisconnectPlayer(identity, uid);
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SyncEvents.SendPlayerList, 1000);

			if (isUpdate)
			{
				CF_Log.Critical("Kicked " + uid + " (name=\"" + name + "\") for timeout!");
			}
			else
			{
				CF_Log.Critical("Kicked " + uid + " (name=\"" + name + "\") for incorrect lod count!");
			}
		}

		if (isUpdate)
		{
			m_PlayerTime.Remove(m_CurrentIndex);
		}
		else
		{
			int playerIdentityId = identity.GetPlayerId();
			int count = m_PlayerTime.Count();
			for (int index = 0; index < count; index++)
			{
				if (m_PlayerTime[index].param1 != playerIdentityId) continue;

				m_PlayerTime.Remove(index);
				break;
			}
		}

		m_PlayerObject.Remove(uid);
	}

	void RPC_Kick(CallType type, ParamsReadContext ctx, PlayerIdentity identity, Object target)
	{
		if (!GetGame().IsServer())
		{
			return;
		}

		GetGame().DisconnectSessionForce();
	}
};
#endif
