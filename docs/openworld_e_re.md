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

## B. Racer AI (rewritten 2026-10-28, second pass; still PARTIAL: Q2 fork rule and the path producer are NOT read)

Tools: REA CLI (`rea.sh xrefs ... --provider ghidra --snapshot build/hopper/rea_ghidra.json`, snapshot now built, later
calls take seconds), Hopper export, capstone (`build/hopper/fdis.py <hex>` function listing, `build/hopper/scan.py <regex>`
whole-.text grep; both scratch). The REA MCP was not loaded; only the CLI xrefs ran (it gave no new fact beyond the
capstone scan). Asm offsets are trusted over Hopper types.

### B1. Correction: the racer lap is NOT the 0x34122 table
- The route the game calls TrackPath is chunks 0x34148 (header: flags 0x100 = closed, N, total length) and 0x34149
  (20 B nodes: x, y, cumulative distance @+16), inside container 0x80034147 (sub_444200 clears manager 0x7372b0..0x7372cc;
  count `dword_7372c0`, rows `dword_7372c4`). Debug name string "TrackPathCoordinate" (sub_444100). sub_443a10(mgr 0x7372b0,
  node) turns a point into a TrackPath coordinate; sub_442150 uses it to give every 0x34122 entry its distance. So 0x34122
  entries are marks placed ON the TrackPath; the TrackPath (0x34148/49) is the lap spine and has no 128/255 limit.
- Nothing in the exe references 0x34148/0x34149 as an immediate (capstone byte scan of the dword: 0 hits), so the chunk is
  read by a generic container loader, not by a per-id handler. NOT VERIFIED which function copies it to 0x7372c4.

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

### B4. NOT READ (needed before coding), in order
1. Who FILLS the path (ctx+0x3a8 list): the creator of the node objects that sub_5a6150 walks (module 0x5a5xxx-0x5a7xxx:
   sub_5a5340, sub_5a5730, sub_5a75c0, sub_5a7270, sub_5a7390, sub_5a6e10, sub_5a6d20). One hypothesis (inference, not read):
   the path is built once per race from the TrackPath (0x7372c4 nodes) snapped to road nodes; a closed TrackPath wraps,
   an open one (sprints) ends with the path and the action EndOfRace (sub_453730) fires.
2. Fork rule (Q2) and wrap (Q2): not found in 44cf30/45c370 (they only follow the list in order). If the list is a plain
   array of nodes, there is NO fork choice at racer level: the fork is decided when the list is built. Wrap = what the list
   builder does at the end of a closed route.
3. Q3 (non-lap modes): Free Run is QR_freerun (0x6c5edc, used at 0x4b7a0c in sub_4b70c0); the racer action for it was not read.
   AIActionDriveTrafficLane (0x452807) is a traffic-lane follower and DriveTrafficLane + Obey/AvoidCrossTraffic show the engine
   already has a "wander on lanes" action (kind 3, traffic: sub_59a2c0, node walkers sub_4563d0/sub_4561d0, successors from
   node bytes +0x81/+0x82). Whether a racer can be given it is open.

### B5. Proposal (Q4), ordered by cost
a) NO EXE PATCH, data only (preferred): since the racer reads path.count and the node objects of sections (<= 128 slots),
   and the lap spine is TrackPath 0x34148/49 (u16 count, no 255 limit), build ONE city-wide closed TrackPath: chain
   chosen street segments of the 16 routes (they are cuts of one mesh; the join points are where routes meet) into a loop
   of N nodes and set the closed flag 0x100 and total length @+12. Keep all road sections the base track has plus the
   sections of the used segments; the budget is 128 sections, so pick a loop that touches <= 128 section ids (dedupe by
   geometry first). 0x34122 entries only need to cover that loop (<= 255).
   Verify with: RN_TRACE on sub_45c370 (path.count at +0x3a8 and its entries) in a Free Run race, then build the loop.
b) If the loop cannot fit: make the path producer (B4.1) wrap a custom list; patch ONE function (the producer) rather than the
   byte index users.
c) Widening 128 -> more is NOT needed for a racer loop; it is for traffic everywhere (about 40 users of 0x77af30).
Next reading step (a quarter of the unknown): xrefs on sub_5a6150's node object ctor (writers of node+0x5c) with REA (the
Ghidra snapshot is ready) to find the path builder.

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
