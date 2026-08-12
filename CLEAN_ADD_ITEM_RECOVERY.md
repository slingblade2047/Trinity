# Trinity 1.17 clean Add Item recovery

This candidate intentionally returns to the small Add Item implementation used by
the working Trinity 0.13.2-era build. It does not include the later transaction,
HolderInsert, or placement-commit diagnostic hooks.

The implementation in `src/game/inventory.cpp` preserves the behavior recovered
from the working ASI in Ghidra:

- observes containers through the normal transaction and HolderInsert hooks;
- keeps the container and its derived holder/context distinct;
- selects matching client and server holders;
- allocates one shared instance ID for both realms;
- temporarily switches the realm byte and restores it after every attempt;
- clears the complete item-value working buffer before construction;
- passes a one-element input vector with count and capacity both set to one;
- invokes HolderInsert with the normal pickup flags `0, 1, 1, 0`;
- consumes 0xE0-byte placement records and reads the slot at offset 0xD8;
- commits every returned placement; and
- always frees placements and destroys the item value when constructed.

The exact Crimson Desert 1.17 signatures remain in `src/game/offsets.h`. No
signature or offset was invented as part of this recovery.

## Test precautions

Back up the save first. Install only one `Trinity.asi` at a time. Test one ordinary
item at quantity 1, wait several seconds, then save and reload before testing more.
The dye apply signature is still unresolved for game 1.17 and is independent of
this Add Item candidate.

Version 0.13.17 also fixes a catalog initialization race: opening Add Item while
the game was still publishing the `iteminfo` runtime pointer previously cached an
empty catalog forever. The menu now retries the inexpensive pointer check until
the table becomes available, then builds the catalog once.
