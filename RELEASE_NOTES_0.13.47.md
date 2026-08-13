# Trinity v0.13.47 - Quest-Safe Inventory

This update fixes a regression that could prevent quests from advancing after
the player acquired a required quest item.

Trinity no longer performs automatic background writes to inventory used-slot
bookkeeping during ordinary gameplay. Normal pickups and quest-item transactions
are left to the game. Add Item and direct quantity editing remain available as
explicit user actions.

The v0.13.46 crash protection for malformed Uncategorised inventory groups is
also retained.

## Credits

- **XeTrinityz** - original Trinity creator and maintainer
- **Orcax1399** - research insights, credited on the original mod
- **Gugi96** - working ASI reference that helped guide the 1.17 compatibility research
- **slingblade2047** - Crimson Desert 1.17 compatibility update

Back up your save before using inventory-editing features. Single-player use only.
