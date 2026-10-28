# Open world phase E: how Speed.exe routes racer AI and traffic (partial RE, 2026-10-28)

Status: PARTIAL. The session stopped on quota after about 22 tool calls. Section A (data layout), section C
(traffic) and section D (merge list) are reasonably solid. Section B (racer AI) is weak: the structures it reads are
known, the exact "next node" function was not read.

Tools: the REA MCP was NOT available in this session. Every finding below comes from the Hopper export
(census/hopper/decomp.c, funcs.tsv) and from capstone disassembly of pc/Speed.exe (raw file offset = VA - 0x400000).
"asm" below means capstone; "Hopper" means the pseudo-code export. Hopper types some fields wrongly (it shows
eax[0x5] for a short at +0xa), so only the asm offsets are trusted. Nothing was run (no game, no build).
Confirm the NOT VERIFIED items with REA before coding.

## A. Data layout

Chunk handler sub_442dd0 (no direct callers: chunk-id dispatch). asm of sub_442dd0 and sub_442b70:

| Chunk | Stored in | Record | Count | Meaning (inferred from users) |
|---|---|---|---|---|
| 0x34121 | table 0x77af30 + 4*id (128 slots) and two circular lists in manager 0x77af20 | 0x27c header + n * 0x88 nodes | up to 128 sections | road SECTION |
| 0x34122 | dword_736150 / count dword_736154 = size >> 5 | 32 B | up to 255 in practice (byte indices, B/D) | PATH ENTRIES, sorted by distance |
| 0x34123 | dword_736158 / dword_73615c = size / 0x170 | 0x170 B | index field is 5 bits in sub_44d570 | per-section data read by traffic (sub_442100, caller 0x59b6d0) |
| 0x34124 | dword_736160 / dword_736164 = size / 0x108 | 0x108 B | sub_42ae20(i) = &rec[i]; sub_42ae30() = count | TRAFFIC route/junction record (C) |

sub_442b70 (asm, exact), edx = 0x77af20 (loaded by sub_442dd0 at 0x442ddd), r = each section record in the chunk:
- `[0x77af20 + 0x10 + 4*short(r+0xa)] = r`. The table has 128 entries: the unload sub_442bd0 clears exactly 0x80
  slots from manager+0x10, and sub_4430b0 loops `esi < 0x200` bytes. So section ids are 0..127.
- the int at r+0xc (0 or 1) picks list 0 (head manager+0) or list 1 (head manager+8); other values: in no list.
- next record = r + 0x27c + short(r+0x10) * 0x88. So the short at r+0x10 is the node count.

Node (0x88 B, first at r+0x27c). Fields seen (Hopper, offsets re-based from section = node0 + 0x27c):
- bytes at node+0x81 and node+0x82: indexes into the 0x34122 table, 0xff = none (sub_4430b0 remaps them after
  sorting; sub_4563d0 reads `(node+0x81+k)` and does `0x736150 + idx*32`).
- float at node+0x38, read by sub_5ab160.
Section header: flags at section+0x58 / +0x5c are set by sub_4430b0 from 0x34122 entries of type 5.

0x34122 entry (32 B): +0 float distance (written by sub_442150 from sub_443a10(node); 0x34122 is then sorted by
sub_442ed0), +0xa byte = section id, +0xb byte = type (5 is special in sub_4430b0), +0xc ushort = node index in
that section. Lookup by distance: sub_442200(float) (linear, unrolled by 4; callers sub_44a330 and sub_44ad00).

Post-load: sub_449870 (caller 0x4494f0) calls sub_4430b0: (1) set section flags from type-5 entries,
(2) sub_442980 for each existing section, (3) sub_442150 fill distances, (4) sort the entries (sub_442ed0) and
rewrite every node byte +0x81/+0x82 to the sorted index. Result: the merged file may leave 0x34122 unsorted.

## B. Racer AI

Known (Hopper):
- sub_44a330 is the AI vehicle base constructor (vtable 0x6c9820; callers sub_4620c0 and sub_582f90). It stores
  `vehicle[0x11d] = sub_442200(dist)`: the vehicle caches the 0x34122 entry index for its current distance.
  Its lane/side input is dword_78a2fc (also used by traffic).
- The vehicle keeps a 0x34122 index in ONE BYTE: sub_4629e0 and sub_462a00 store
  `((entry - 0x736150) >> 5) & 0xff`, sub_458bd0 computes the same masked value. Max 255 entries, 0xff = none.
- The racers' lap path is the sorted 0x34122 table (distance = progress) reached through node bytes +0x81/+0x82;
  two bytes per node suggest at most 2 successors/entries per node.
- 0x34124 is NOT the racer route. All callers of sub_42ae20 are traffic (0x598440, 0x5984d0, 0x598510, 0x599fc0,
  0x59b840) plus the pointer fixer sub_5aaf90. HANDOFF's "route = 0x34124" is, in the exe, the TRAFFIC table.

NOT VERIFIED (read next, with REA): the function that computes a racer's goal point. Leads: sub_455530 (named AI
driver in tools/hopper/q_ai.py), sub_44adc0 (1155 lines, caller 0x44c250), sub_44c9c0 (caller 0x44b1b0),
sub_453120 / sub_453600 / sub_453c60 (vtable callers, use table 0x77af30 and sub_456e90). Questions: branch choice at a
fork, wrap at the last entry (probably distance modulo the lap length = largest entry distance).

## C. Traffic

All in 0x598xxx..0x59cxxx (Hopper; the field meaning is inferred).
- Spawner: sub_599c80 (caller 0x599830) and sub_598c80 pick a random world point near the camera (random =
  sub_4216f0 / sub_4216b0), up to 100 tries, then:
  1. sub_599fc0: for i in 0..sub_42ae30()-1 over 0x34124 records. Skips records whose short at +0x100 >= 6. Needs
     short at `rec + 4 + 2*lane` != -1 and byte `rec + 0xd0 + side*4 + lane*2` != 0. Floats at
     `rec + side*8 + 0x10 + lane*4` and `rec + side*8 + 0xe0 + lane*4` are extents; the position test uses
     sub_5ab160 and sub_443d60. Up to 8 candidates in a local array; one is picked with sub_4216b0(count).
  2. sub_5ab210: `node = table0x77af30[ *(int*)rec ] + 0x27c + short(rec + 4 + 2*lane) * 0x88`. So the FIRST INT of a
     0x34124 record is a SECTION ID and the shorts at +4 are node indices in that section. The same int is the
     record's id in save/load (sub_5aaf90 matches it).
  3. sub_599660 chooses a car model slot (not routing). sub_59b130 / sub_598fb0 check clearance; sub_59a7c0 spawns.
- Per-frame: sub_59a2c0 (3683 lines, one caller) is the traffic car update. It moves with the node walkers
  sub_4563d0 (caller 0x59a2c0) and sub_4561d0 (caller 0x59bd90): loop cap 0x19000 steps, successors from node bytes
  +0x81/+0x82 -> 0x34122 entry -> (section byte +0xa, node ushort +0xc). So junction transitions between
  sections go through 0x34122 entries. NOT VERIFIED: exact junction choice (random vs lane rule).
- Save/load: sub_5aaf90 and sub_442c20 / 442c80 / 442d10 convert pointers to indices: section pointer as
  `(sectionId << 16) | nodeIndex`, node as `(ptr - sectionBase - 0x27c) / 0x88`. Both 16-bit.

## D. What a merge (several tracks' 0x34121-24 concatenated) must rewrite

Limits seen in the exe:
1. Section ids: the short r+0xa indexes 128 slots. All merged sections together need ids 0..127. If the 16 networks
   have more sections, the exe table (sub_442b70, sub_442bd0, sub_4430b0 loop, sub_5ab160/5ab1b0/5ab210, about 40
   users of 0x77af30) would need patching. FIRST MEASURE the section count per track.
2. 0x34122 entries are indexed by a BYTE (0xff = none): at most 255 entries for all tracks (sub_4629e0, sub_462a00,
   sub_458bd0, node bytes +0x81/+0x82). More needs patches in those and in the node layout.
3. Rewrite together: section id in 0x34121 (short r+0xa), section byte in 0x34122 (+0xa), first int of each 0x34124
   record. Node indexes inside a section do not change.
4. Re-base the node bytes +0x81/+0x82 by the track's entry offset (keep 0xff). The exe re-sorts after load, so
   0x34122 may stay unsorted.
5. 0x34122 is also the racers' lap spine (distance). Concatenating tracks gives no sensible single lap; racers
   across the city need a new lap path or a different goal (needs section B read first). Keep the base track's
   0x34122 for racers until then.
6. 0x34123 (0x170 B): index is 5 bits in sub_44d570 (max 32); re-base per track and stay under 32.
7. 0x34124 records: keep the route-class short at +0x100 < 6 to be spawnable; the arm shorts at +4 stay valid inside
   the section.
8. Per-section int +0xc must stay 0 or 1 (list choice).
9. Counts come from chunk byte sizes: the merged chunk header size must be the concatenated size, 4-byte aligned.
   sub_442dd0 keeps only the last chunk of 0x34122/23/24 (one chunk each); 0x34121 can be split in several chunks
   (it adds to the table).
10. Section geometry is in world coordinates: the merged network is right only with the same offsets used by the
    geometry/collision merge (D1).

## Next steps
1. Count sections / entries / routes per track from the TRACKB files (census/openworld_build.json may have them):
   decides limits 1 and 2. If total sections <= 128 and total entries <= 255 a pure data rewrite (no exe patch) suffices.
2. REA: read sub_59a2c0 + sub_4563d0 (junction choice), sub_455530 + sub_44adc0 (racer goal), meaning of +0xb values.
3. Then write the merge in the openworld build (build.py currently keeps the base track's 0x34121-24).
