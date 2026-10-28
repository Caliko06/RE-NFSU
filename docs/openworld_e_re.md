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

## B. Racer AI (third pass 2026-10-28: path walker, fork rule and TrackPath role read; solution in B5)

Tools: REA CLI (`rea.sh xrefs ... --provider ghidra --snapshot build/hopper/rea_ghidra.json`, snapshot now built, later
calls take seconds), Hopper export, capstone (`build/hopper/fdis.py <hex>` function listing, `build/hopper/scan.py <regex>`
whole-.text grep; both scratch). The REA MCP was not loaded; only the CLI xrefs ran (it gave no new fact beyond the
capstone scan). Asm offsets are trusted over Hopper types.

### B1. What a racer follows: the ROAD GRAPH, not the TrackPath (read in Speed.exe 2026-10-28, confirmed by a run)
Tools: Hopper export, capstone, runtime (RN_FREELOG path dump in host/free.c `free_tick`, REA MCP not loaded).
- Racer class = AIVehicle derived, vtable 0x6c89f0 (ctor sub_4620c0 -> base ctor sub_44a330). obj+4 = vehicle, ctx = obj+0x2c
  (sub_44cd30). `[ctx+0x3a8]` is a POINTER (not embedded) to a path object made by sub_457060 (type 0: sub_455270 vtable
  0x6c9030, type 1: sub_455390 vtable 0x6c8ff8; ctor sub_5a5340): count at +4, up to 40 node-object pointers from +8,
  current index at +0xac. Node object: section id (signed byte) at +0x5c, node index (short) at +0x5e.
- The path is grown ahead of the car by sub_5a58d0 (to a target distance, at most 0x28 nodes) using sub_5a53c0 (one step):
  at the current node, link slot 0 then 1 (node bytes +0x81/+0x82, 0xff = none) -> 0x34122 entry (32 B). A link is taken when
  sub_458bd0 accepts it (it first rejects a link whose entry byte +0xd (direction) does not match the walk direction, so the
  reverse entry d=1 is skipped on a forward walk; it caches decisions in 8 slots at decider+0xc and asks the decider, vtable
  slots 16/17/18 of 0x6c89f0 = 0x45d640, 0x462840, 0x4629e0). When no link is accepted the walker takes the NEXT NODE of the
  same section; at a section end with no link the path cannot extend.
- Fork rule for racers = sub_462840 on entry byte +0xb (type): type 2 ALWAYS taken; types 5 and 7 NEVER; type 8 only for the
  player (entrant kind 1); type 9 -> 0x454a20; types 0/1/3/4: entry +0xf != 0 -> no, else a random draw (0x4216f0) against
  per-skill thresholds at 0x779ff8 + 0x54*level (type 4 against float [0x6cc7dc]). So type 2 links make a FIXED route, the
  rest wander at random. sub_4629e0 stores the sorted index of the last type 2 entry in ctx+0x478.
- The TrackPath (0x34148/49) does NOT choose the route. It is used for: the distance of every entry (sub_442150 via sub_443a10,
  then sort sub_442ed0 and remap the node bytes), the extent of every section (sub_442980, all 128 slots), the lookup by
  distance (sub_442200, AIVehicle ctor sub_44a330 `esi[0x11d]`), the player's route point (0x4314a0 nearest node; reset at
  more than 5000 m from it, 0x426930). Record layout: 0x34148 = one 0x28 B record per path (u32 flags 0x100 closed, u16 count
  twice, u32 0, float length, 1.0f, start xy, end xy, 0 = runtime object pointer); 0x34149 nodes 20 B = x, y, u16 path index 0,
  three int16 -1 (+10..+14, the spatial grid refs), float cumulative distance (+16). Writing +8..+0xf as float NaN instead of
  `0000 ffff ffff ffff` crashes sub_443a10 (0x59d551, null object): the grid refs must be -1. No node cap found: sub_4432a0
  allocates (count + 3) * 16 B per path.
- Measured (RN_FREELOG, Free Run on 1010 = merged base 1001 net: 25 sections, 66 entries, 34 of type 2): the three rivals lap
  Olympic Square (x 979..2029, y -1806..-434), varying at the random forks; their path window holds 30..40 nodes.
- Node bytes: +0x83 = the node's own section id; +0x84 dword bits 20..24 = index of a 0x34123 record (31 = none; base 1001,
  1007, 1008 have no 0x34123 chunk and all nodes read 31; the readers are 0x44efd0, 0x454240, 0x4543d0, 0x454420, 0x454490,
  0x583c80, 0x5a6e10 through sub_44d570 / 0x442100).

### B2. The racer AI is an action/goal system, "JustDrive" is the racing action
- Strings: AIGoal, AIPlan, AIDriver, AIActionJustDrive (0x6c9570, used at 0x4501a7), ...Pass (0x4506b7), ...Draft,
  ...EndOfRace (0x453767), ...DriveTrafficLane (0x452807, traffic), ...GetUnstuck, ...PullOver, ...AvoidAvoidable. Each is
  a slot-pool class: sub_450170 builds a JustDrive action (vtable 0x6c9374; update slot sub_450210, other slots 0x453c60,
  0x4538a0, 0x453a60, 0x454c50). Created from sub_44b1b0 (the AI vehicle update, slot 3 of vtable 0x6c9820).
- AI context object (ctor sub_44cd30, called with esi = context): [0] = vehicle, +8 = 4 slots of 0x38 B (+0x388 = current
  slot, signed byte), +0x38c/+0x394 = mode/lane ints, and an embedded PATH object at +0x3a8 (ctor sub_457060).
  asm 0x44cd8c `lea ecx,[esi+0x3a8]` ... 0x44cdb1 `call 0x457060`.
- PATH object = list of node objects: count at path+4, pointers at path+8+4*i (asm 0x45c398 `mov eax,[edi+4]`; sub_5a6150
  indexes `*(path + i*4 + 8)`). Each node object holds a section id byte at +0x5c (0xff = none), a node index short at +0x2f*4
  (= +0xbc), and a distance float at +0x58. Position of a node object = `*(0x77af30 + 4*sectionId) + 0x27c + nodeIdx*0x88`
  (sub_5a6150 asm: `mov eax,[eax*4+0x77af30]` ... `imul 0x88 ... +0x27c`). So the racer follows a list of ROAD-NODE
  OBJECTS of the section table (128 slots), the same (section, node) pairs as traffic uses.

### B3. The goal point is a lookahead on a 20-point plan polyline (answer to Q1)
- Plan struct (0x1c0 B, ctor/reset sub_458f10): byte [0] = point count (cap 0x14 = 20), points of 0x10 B from +0x10
  (x,y,z), per point: byte @+0x150+i (section id), ushort @+0x164+2i (node), byte @+0x18c+i (lane), float @+0x1ac = length.
  Append = sub_4594d0 (asm 0x4595f5..0x459635: `mov word ptr [esi+ecx*2+0x164],dx`).
- GOAL FUNCTION = sub_4590a0(vehicle, lookahead_dist, out_xyz): walks the plan polyline until `lookahead_dist` is
  reached and returns that point (asm 0x459182 `fst [esp+edx*4+0x20]` accumulates segment lengths, 0x459186 compares to
  arg 8). Plan type byte 1 = straight line to a point; the car steers to this point. sub_459710 finds the plan segment the
  car is on.
- Plan refill = sub_45c370 (callers 0x44feb0..0x45cae9, including JustDrive sub_450210 via sub_45ae10). With plan count 0 it
  takes the car's current path node (`[ebx+0x388]*0x38+ebx+8`), then loops i = idx+1 .. path.count-1: sub_45c640 (lateral/lane
  offset) + sub_45c500 (-> sub_5a7270 node position, then sub_4594d0) until 20 points. Otherwise sub_5a6150 finds the path
  index nearest the car, then the same loop. asm 0x45c398 `mov eax,[edi+4]` (path.count), 0x45c3df `dec eax`.
  => the racer only reads path.count and the node objects; DISTANCE/LAP LENGTH ARE NOT USED here, and the 0x34122 table is
  not read here either.
- Per frame (sub_44b1b0 -> sub_44cf30): finds the car's path index (sub_5a6700 -> sub_5a65b0 nearest node, sub_5a67d0),
  and when the car nears the end (sub_5a71f0 test) it extends the path through sub_44d0c0 (which uses sub_5a75c0 /
  sub_5a6150). sub_44cf30 also called by sub_583350 and sub_583700. Avoidance of other cars is sub_457590 (0x77a4ac global),
  not the goal.
- Reset: sub_458f10 re-seeds the plan from the car (nearest path node, sub_4594d0 with the node's section/node/lane).

### B4. Answers to the open questions of the first pass
1. Who fills the path: sub_5a58d0 / sub_5a53c0 (B1), from the road graph, as the racer drives.
2. Fork rule: sub_462840 (B1). Wrap: none needed, a closed route is a closed link loop.
3. Q3 (non-lap modes): the racer uses the same path walker in Free Run; measured, it never ends (RN_JUMP run of 10749 frames).

### B5. Data-only solution (built and run, docs/openworld/tour.md)
`tools/openworld/tour.py` writes build/openworld/TRACKB1010.lzc (the WORLD file; host/openworld.c serves it, the base 1001 file
when absent): the merged city with a new road net = a closed tour of whole sections of the street tracks joined only by type 2
links (4 chains 1104, 1106, 1109, 1107, 76 sections, 152 entries = 76 hops x pair, 42 km, x -538..2345, y -1906..734) and a new
closed TrackPath along it. No exe patch: 76 <= 128 sections, 152 <= 255 entries.

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

## E. Measured counts (2026-10-28, tools/hopper lib on pc TRACKB 1001-1109, script was a scratch count)
| | per track | sum of 16 | exe limit |
|---|---|---|---|
| 0x34121 sections | 12-43 (ids 1..109) | 392 | 128 slots @0x77af30 |
| nodes | 862-3216 | 27050 | node index ushort |
| 0x34122 path entries | 34-144 | 1193 | 255 (1-byte index) |
| 0x34124 traffic routes | 0-7 | 61 | ? |
Section ids are per-track, not city-global: of 65 distinct ids only 11 have the same node count and first node in
every track. So a naive union does NOT fit: 392 > 128 sections and 1193 > 255 entries. Options: (a) dedupe identical
streets by geometry first and re-count; (b) widen the table and the byte index in the exe (patch table); (c) swap the
active network by region as the player drives. Decide after (a).
