# Changelog

## 0.13.49 - Crimson Desert 1.18 compatibility

- Restored Fast Travel after the 1.18 executable update.
- Restored the verified Add Item cleanup/destructor path.
- Restored Game Speed and Advance Time realm-clock discovery.
- Restored Dye Equipment component capture.
- Restored the NPC Trust Multiplier setter.
- Revalidated every replacement signature as unique in executable build 1.0.0.2435.
- Retained the quest-item, inventory-editor, and player-stat safety fixes from 0.13.46-0.13.48.

## 0.13.48 - Player-stat and inventory safety

- Fixed Infinite Stamina and Infinite Spirit being suspended when extra player-class bodies appeared.
- Filters stat writes to the first three stable party bodies.
- Ignores preview and duplicate bodies without disabling player stat features.
- Retains the v0.13.47 quest-safe inventory behavior.

## 0.13.47 - Quest-item acquisition safety (test)

- Removed the automatic one-second used-slot bookkeeping rewrite.
- Trinity no longer writes inventory counters during ordinary pickups or quest transactions.
- Add Item and direct quantity edits remain explicit user actions.
- Retains the v0.13.46 Uncategorized crash protection.

## 0.13.46 - Inventory editor stability

- Prevented a crash when opening an Uncategorized inventory group containing malformed or unresolved game records.
- Uncategorized inventory groups now use read-only safety mode.
- Hidden unresolved item names, invalid type IDs, and corrupted or sentinel quantities.
- Disabled bulk quantity editing on Uncategorized groups.
- Added an accepted/skipped record count to `Trinity.log` for diagnosis.
- Retained the player-stat transition guard introduced during 1.17 testing.

## 0.13.43 - Crimson Desert 1.17 compatibility

- Restored Add Item and durable inventory placement.
- Rebuilt the item catalog with corrected 1.17 table and entry layouts.
- Cleaned up inventory category labels.
- Restored Infinite Stamina and Infinite Spirit.
- Restored Fast Travel destination discovery.
- Updated the equipment component table from `+0x88` to `+0x80`.
- Updated equipped-entry stride from `0xC8` to `0xD0` and slot tag from `+0xC0` to `+0xC8`.
- Updated dye-record data/count fields from `+0x70/+0x78` to `+0x78/+0x80`.
- Restored the 1.17 dye apply and persistence functions.
- Added optional per-session file logging controlled by `fileLogging` in `Trinity.ini`.

### Known limitation

- Abyss Gear socket effects may require a save reload because the 1.17 effect-refresh function is unresolved.
