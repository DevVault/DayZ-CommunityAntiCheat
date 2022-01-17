modded class DeferredTakeToDst
{
    override void ClearInventoryReservation(HumanInventory inventory)
    {
        if (!m_dst || !m_dst.GetItem()) return;

        if (!inventory) return;

		super.ClearInventoryReservation(inventory);
    }
};

modded class DeferredSwapEntities
{
    override void ClearInventoryReservation(HumanInventory inventory)
    {
        if (!m_dst || !m_item1) return;
        if (!m_dst2 || !m_item2) return;

        if (!inventory) return;

		super.ClearInventoryReservation(inventory);
    }
};

modded class DeferredForceSwapEntities
{
    override void ClearInventoryReservation(HumanInventory inventory)
    {
        if (!m_dst || !m_item1) return;
        if (!m_dst2 || !m_item2) return;

        if (!inventory) return;

		super.ClearInventoryReservation(inventory);
    }
};
