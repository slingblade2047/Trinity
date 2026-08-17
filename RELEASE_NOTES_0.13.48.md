# Trinity v0.13.48 - Crimson Desert 1.17

This update restores Infinite Stamina and Infinite Spirit in scenes where the
game exposes extra preview or duplicate player bodies. Trinity now limits stat
writes to the first three stable party bodies instead of disabling the features.

It also includes the quest-safe inventory correction from v0.13.47 and the
Uncategorized inventory crash protection from v0.13.46.

## Fixed

- Restored Infinite Stamina and Infinite Spirit when extra player-class bodies appear.
- Preserved stat behavior after opening and closing the character/equipment screen.
- Preserved normal quest-item acquisition and quest progression.
- Prevented malformed or unresolved Uncategorized records from reaching the editor.

## Logging changes

- Logs when extra player-class bodies are detected and filtered to the stable party set.
- Logs accepted and skipped record counts when an unsafe Uncategorized group opens.
- File logging remains controlled by `fileLogging` in `Trinity.ini`.

## Known limitation

- Abyss Gear socket changes may require reloading the save before their effects become active.

## Credits

- **XeTrinityz** - original Trinity creator and maintainer
- **Orcax1399** - research insights, credited on the original mod
- **Gugi96** - working ASI reference that helped guide the 1.17 compatibility research
- **slingblade2047** - Crimson Desert 1.17 compatibility update

Back up your save before using inventory-editing features. Single-player use only.
