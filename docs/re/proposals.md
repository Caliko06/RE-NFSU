# Proposals from the RE (none applied; the OWNER approves)

One row per idea: address, effect, risk, switch name. Source doc in the last column.

| Address | Effect | Risk | Switch | From |
|---|---|---|---|---|
| `0x705f48`/`0x705f5c` tables (data at `0x700178`, `0x7001a0`: max steering angle vs speed, 45° → 2.9°/7° at 160) | A lead for the OWNER's "rigid, late" handling. Before anything else, measure whether our keyboard path reaches the angle these tables allow (RN_STEERLOG vs `0x460a80` output) | Medium: changes feel; only toward the original if the input layer is the cause | `?steer=table` (A/B, off by default) | tuning.md, Corrections |
| `[0x7677ac]` career-beaten flag (read by the part-lock checks `0x4d7eb0`/`0x4d8180`) | A test-only switch to open every part in the garage, so the garage UI and part rendering can be checked without a full career | Low if test-only; it must never write the OWNER's save | `?unlock=all` (TEST-ONLY) | tuning.md §4 |
| `tools/re/carinfo.py` | A read-only garage table for the OWNER: per car, the stock vs L1..L3 numbers (mass, gears, rpm, nitrous) | None (data only) | none | tuning.md §1 |
| Music picker `0x53c3a0` (masks `0x758930`/`0x758934`) | None needed: the EA Trax jukebox toggles already work through the options block. Note for Web Audio: stream index = song + 1 | None | none | sound.md §3 |
