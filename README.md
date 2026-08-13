# Trinity for Crimson Desert 1.17

Trinity is an in-game DirectX 12 mod menu for **Crimson Desert**, created by **XeTrinityz**. This repository contains a compatibility fork for game version **1.17.00**.

Official upstream project: [github.com/XeTrinityz/Trinity](https://github.com/XeTrinityz/Trinity)

> Single-player use only. Do not use this project in online or anti-cheat-protected modes. This community project is not affiliated with or endorsed by Pearl Abyss.

## Features

- Player options: God Mode, Infinite Stamina, Infinite Spirit, movement modifiers, damage multipliers, and Trust Multiplier
- Fast Travel with engine-derived destination groups and names
- Inventory browser, quantity editor, and Add Item catalog
- Item/category icons decoded from the game's `.paz` archives
- Dye Equipment with live preview and save persistence
- Abyss Gear socket editing
- World speed and time controls
- Keyboard, mouse, and controller navigation
- Optional per-session `Trinity.log`

## Version 1.17 compatibility

Version 0.13.47 includes the confirmed 1.17 repairs for:

- Add Item transaction and persistence
- Item catalog, names, categories, and icons
- Inventory entry alignment
- Fast Travel destination discovery
- Infinite Stamina and Infinite Spirit
- Equipment table and entry layout
- Dye record layout, live dye application, and persistence
- Inventory-editor safety for malformed or unresolved Uncategorised records
- Quest-safe inventory handling: no background counter writes during normal pickups

Uncategorised inventory groups are deliberately read-only. Invalid internal
records are hidden so they cannot be passed to the quantity editor and crash
the game. Valid named inventory categories remain editable.

Known limitation: Abyss Gear socket changes may require reloading the save before their effects become active because the 1.17 effect-refresh function is not yet resolved.

## Installation

1. Install a compatible ASI loader for the game.
2. Copy `Trinity.asi` beside `CrimsonDesert.exe` (or into the loader's configured plugin folder).
3. Start the game and load a single-player save.
4. Press **Insert**, or **LB + D-pad Down**, to toggle Trinity.

Back up your saves before using inventory, equipment, or dye editing features.

## Controls

| Action | Keyboard / mouse | Controller |
| --- | --- | --- |
| Open / close | Insert (Escape closes) | LB + D-pad Down |
| Navigate | Arrow keys, mouse | D-pad |
| Select | Enter or click | A |
| Back | Backspace | B |
| Adjust | Left / Right | D-pad Left / Right |

Bindings can be changed under **System > Keybinds**.

## Configuration and logging

`Trinity.ini` is stored beside `Trinity.asi`. File logging is enabled by default:

```ini
fileLogging=1
```

Set `fileLogging=0` to disable it. When enabled, Trinity creates a fresh `Trinity.log` for each game session beside the ASI. The console window remains available either way.

## Building

Requirements:

- Windows 10 or 11
- Visual Studio 2022 Build Tools with **Desktop development with C++**
- Windows SDK
- CMake 3.20 or newer
- Internet access during the first configure (for Dear ImGui and MinHook)

PowerShell helper:

```powershell
powershell -ExecutionPolicy Bypass -File .\Build_Trinity.ps1 -Configuration Release
```

Or build directly:

```powershell
cmake -S . -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Release
```

The resulting file is `Trinity.asi`.

## Project layout

- `src/core` - startup, settings, state, and logging
- `src/mem` - guarded memory access, signature scanning, and hook helpers
- `src/game` - game features and version-specific signatures/offsets
- `src/hooks` - DirectX 12, window input, and controller integration
- `src/gui` - overlay framework, widgets, icons, and menus
- `scripts` - data-generation utilities
- `tools` - development and diagnostic helpers

## Dependencies

- [Dear ImGui](https://github.com/ocornut/imgui), MIT License
- [MinHook](https://github.com/TsudaKageyu/minhook), BSD 2-Clause License

They are fetched during CMake configuration and are not vendored in this repository.

## Credits and license

Trinity was created by **XeTrinityz** and released as open source at the [official upstream repository](https://github.com/XeTrinityz/Trinity). The original copyright and MIT license are preserved in [LICENSE](LICENSE).

- **Orcax1399** - research insights, credited on the original mod
- **Gugi96** - working ASI reference that helped guide the 1.17 compatibility research
- **slingblade2047** - Crimson Desert 1.17 compatibility update

Crimson Desert and its assets are trademarks/copyrights of their respective owners. No game assets are distributed in this repository.
