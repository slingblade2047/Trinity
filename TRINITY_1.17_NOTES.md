# Trinity 0.13.3 - Crimson Desert 1.17 Add Item compatibility pass

Target executable SHA-256: `A1DFC0329E177240A978EE4CC3D331E5DDD1903D1055787816199C559E16857C`

## Revalidated / updated for 1.17

- Table-resolver clone frame changed from `sub rsp, 0x40` to `sub rsp, 0x50`; updated the 32-bit and 16-bit string-anchored resolver walkers.
- Character-manager anchor #3 now reads the caller field at `+0x158` instead of `+0x160`.
- Inventory holder-insert planner frame changed from `0x2F0` to `0x310`.
- `TrItemValue` constructor signature was extended past the shared prologue to select the inventory constructor uniquely.
- `TrItemValue` destructor signature was updated for the new saved-RBP prologue and the `+0x98` member layout visible in 1.17.
- Time-of-day engine-global anchor was tightened to the engine-console registration site so the old duplicate match is rejected.

## Still fail-closed / optional in this pass

The 1.17 scan shows these old signatures no longer resolve and the deep probe did not provide a safe unique replacement yet:

- placement-vector cleanup (`kSig_InvFreePlacements`) - **Add Item is refused**, but inventory browse/edit still works.
- localisation getter (`kSig_LocStringGet`) - item/storage names fall back to engine keys.
- dye apply/upsert (`kSig_DyeApplyBatch`, `kSig_DyeUpsert`) - armor dyeing remains disabled rather than calling an unverified address.
- equipment effect refresh (`kSig_EquipEffectRefresh`) - socket/refine writes still work, but live effect refresh may wait for reload.

No unverified absolute addresses were added. The remaining failures are intentionally left safe rather than guessed.

## 0.13.3 Add Item cleanup re-derivation

- Re-derived `kSig_InvFreePlacements` for 1.17.00.
- The new target is a unique compact vector cleanup routine whose ABI matches the planner output: data at +0, count at +8, inline sentinel at +0x10, and 0xD8-byte placement records.
- Added a runtime uniqueness check before assigning the cleanup primitive. If a future build makes the signature ambiguous, Add Item remains fail-closed.
- Candidate selection was based on the 1.17 executable SHA256 `A1DFC0329E177240A978EE4CC3D331E5DDD1903D1055787816199C559E16857C`.
