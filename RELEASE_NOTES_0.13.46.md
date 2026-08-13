# Trinity v0.13.46 - Inventory Editor Stability

This update fixes a crash that could occur when opening an **Uncategorised**
group in the inventory editor.

Uncategorised groups now open in read-only safety mode. Trinity hides malformed,
unresolved, and sentinel inventory records and disables **Set All** on those
groups. Normal named inventory categories remain editable.

Tested on Crimson Desert 1.17.00 with God Mode, Infinite Stamina, and Infinite
Spirit enabled.

Back up your save before using inventory-editing features. Single-player use only.

## Credits

- **XeTrinityz** - original Trinity creator and maintainer
- **Orcax1399** - research insights, credited on the original mod
- **Gugi96** - working ASI reference that helped guide the 1.17 compatibility research
- **slingblade2047** - Crimson Desert 1.17 compatibility update
