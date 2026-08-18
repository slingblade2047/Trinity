# Trinity v0.13.63 Stable Provenance Build

- Gameplay base: verified Trinity v0.13.54 for Crimson Desert 1.18.02
- Maintainer: slingblade2047
- Source: https://github.com/slingblade2047/Trinity
- Upstream: https://github.com/XeTrinityz/Trinity
- Research credits: Orcax1399; Gugi96
- License: MIT

## Storage research status

The controller-pinning correction discovered after the unsuccessful v0.13.56
test is recorded for future research. Remote storage replay is deliberately
excluded from this stable build because later candidates did not open the UI
reliably and v0.13.62 crashed when an invalid native object reached the title
activation routine.

## Safety scope

This build contains no Open Last Storage menu entry, storage replay request,
or synthetic storage-controller calls. Its gameplay behavior remains based on
the verified v0.13.54 release.

The published ASI SHA-256 is recorded in `SHA256.txt` after compilation.
