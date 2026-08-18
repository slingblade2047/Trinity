# Trinity v0.13.63 — Stable Provenance Build

This release preserves the verified Crimson Desert 1.18.02 gameplay behavior
from Trinity v0.13.54 while adding durable project identity and attribution.

## Added

- Embedded maintainer, source, upstream, lineage, and research-credit record
- System → About & Credits page
- Identifying Windows ASI metadata
- Startup-log provenance record
- NOTICE.md and CONTRIBUTORS.md
- Build manifest and published ASI SHA-256

## Storage status

The storage-controller correction identified after the unsuccessful v0.13.56
test is documented for continued research. Remote storage is not enabled in
this stable build. This prevents the unsafe replay path responsible for the
v0.13.62 crash.

## Verified ASI hash

`D0CBABBBE8A9A26F8C3FFEDCF37844576C161478717973F6C3B35FA88C47861F`
