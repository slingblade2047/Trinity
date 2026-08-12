# Changelog

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
