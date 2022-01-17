/*
modded class ActionGetInTransport
{
	override void Start( ActionData action_data )
	{
		Transport trans = Transport.Cast(action_data.m_Target.GetObject());
		if (!trans) return;

		super.Start( action_data );
	}
};
*/