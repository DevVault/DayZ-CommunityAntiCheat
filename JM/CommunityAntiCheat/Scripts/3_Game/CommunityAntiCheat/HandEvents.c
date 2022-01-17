modded class HandEventBase
{
    override void ClearInventoryReservation()
    {
        InventoryLocation dst = GetDst();
        if (!dst || !dst.GetItem()) return;

        if (!m_Player || !m_Player.GetHumanInventory()) return;

		super.ClearInventoryReservation();
    }
};

modded class HandEventSwap
{
    override void ClearInventoryReservation()
    {
        if (!m_Dst || !m_Dst.GetItem()) return;
        if (!m_Dst2 || !m_Dst2.GetItem()) return;

        if (!m_Player || !m_Player.GetHumanInventory()) return;

		super.ClearInventoryReservation();
    }
};
