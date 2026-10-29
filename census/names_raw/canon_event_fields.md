# EventDesc unknown fields, kinds, modes, rewards, chunk 0x34a01

Marks: V = read in code at the address given, I = inferred, U = unknown (what I tried is listed).
Tools: G = Ghidra census/ghidra/decomp_*.c, H = Hopper census/hopper/decomp.c, A = capstone `tools/recomp/asm.py dis`, D = data (tools/re/events.py, game/FrontEnd/FrontB.lzc).
H+G column rule: "H+G agree" only where I compared both bodies (4c4920, 4c55f0, 5a1340, 4c5f20 by A). For the rest, Hopper has a function at the same address (checked by grep) but I read the body in Ghidra only: marked "G read, H present".

## Answer (short)

- Race modes (+0x08): 0 Circuit, 1 Drag, 2 Sprint, 3 Drift, 4 Time-Trial, 5 Lap Knock Out. V (0x4c4920 icon names, 0x4c49f0 labels UG_MODE_*, H+G agree).
- Event kinds (+0x04): 0 single event, 1 Tournament, 2 Junkman gives parts, 3 Samantha gives parts, 4 final race (event 113), 5 boss race (event 112), 6 URL ladder event (Underground Racing League), 8 repeatable cash race, opened only when the player is stuck. Kind 7 is not in the data (0x5a2f10 tests it for a runtime object).
- Reward types: 0 part category + level, 1 magazine, 2 car, 3 track (arg = reverse), 4 nothing reads it (2 events). Unlock queries: 0x5a1550 (type 0), 0x5a1630 (type 2), 0x5a16f0 (type 3). All three scan the 256 records and return "won" for the first event that rewards the item; no event rewards it -> unlocked.
- Chunk 0x34a01: 25 rows x 0x20 indexed by part category, price for levels 1..3 and ride-rating points for levels 1..4.
- Most unknown fields are inputs copied by 0x4b5df0 into race globals at 0x78a3xx (see table). Only +0x130 hash, +0x18 and +0x34/+0x36 have their own readers.

## Plumbing (V, G read, H present)

- 0x5a0060 indexes the records by id into [0x733ff8+4*id].
- 0x5a2350 (called by 0x5a0ce0 StartEvent) builds the race object: copies 0x53 dwords of the record to object+0x58a0 (0x58a0..0x59ec). So code that reads `obj+0x58a0+N` reads record field N. Object +0x58a4 = kind, +0x58a8 = mode, +0x59ec = won flag. The career+0x88b0 pointer keeps the running object, and every status lookup falls back to its embedded record.
- Reader scan: I searched all Ghidra files for displacements 0x58a0+field and the rival range 0x5974..0x59c7. Only 0x4b5df0 and 0x4b4040 (and 0x4c5680 through the map item) touch them directly.

## Field table (offsets asked)

| Off | Meaning | Mark | Reader / evidence |
|---|---|---|---|
| +0x08 | race mode, see table | V | 0x4b5df0 switch on [obj+0x58a8]: mode 1 sets [0x78a344]=1; 3 sets [0x78a345]=1 and opponent count 0; 4 sets [0x78a30c]=2 and [0x78a310]; 5 sets [0x78a30c]=3. Names 0x4c4920 |
| +0x18 | minimum ride rating to enter (1..4, non-zero only on the 10 tournaments 14,20,30,38,48,66,69,80,92,102: 1,1,2,2,2,3,3,3,3,4) | V | 0x4c5f20: `fild [rec+0x18]` compared with 0x5a05b0 (ride rating of the player car), returns 1 when rating >= value (A, G, H present). Caller of 0x4c5f20 not found in the Ghidra text (called through a vtable); gating use I |
| +0x1c,+0x20,+0x24 | target time in seconds per difficulty (mode 4 only: 115/105/95, 172/162/152, ...). Index = [0x75f240] | V | 0x4b5fe9: `fld [ebx+ecx*4+0x58bc]` -> call 0x674898 (float to int) -> [0x78a310]. Win test 0x5a2f10: racer time < [0x78a310] (mode 4). HUD countdown 0x4a1820 uses [0x78a310] (G) |
| +0x0c, +0x14 | zero on all 116 records, no reader found | U | D: all 0. No access found at 0x58ac / 0x58b4 in the scan |
| +0x34 | u16 league: 0 Circuit, 1 Sprint, 2 Drag, 3 Drift. Kind 6 events only | V | 0x5a1340 compares `*(short*)(rec+0x34)` with its argument. Ranking screen 0x4e9e90 passes the league and shows RANK_CAT_CIRCUIT/SPRINT/DRAG/DRIFT from table 0x6fa18c (labels resolved with tools/re/lang.py) |
| +0x36 | u16 URL rank defended, 10 down to 1 (not in the asked list, needed for +0x34) | V | 0x5a1340 returns the lowest +0x36 among won kind-6 events of the league = the player's current rank, else -1. Callers 0x4e9e90, 0x5682d0 |
| +0xd0 | hash of a fixed player car preset; only event 0 (0xffaad92a). Non-zero -> the player drives that preset with DUMMY_SKIN1/DUMMY_WHEEL1 instead of the career car | V | 0x4b5df0: `mov eax,[ebx+0x5970]` test; zero -> 0x4ac5a0 (career car), else 0x4b26f0 (builds the car from the hash via 0x4b2640). A for the branch, G for the rest |
| +0x128 | number of AI opponents (0..3). 3 on 102 events; 0 on the 7 Time-Trial events; 1 on events 45,70,78,107,111,112,113 | V | 0x4b5df0 -> [0x78a324] (forced 0 in Drift mode). 0x4b4040 loops `[obj+0x59c8]` rival slots |
| +0x12c | float 0.8..1.2 (1.0 on 85): per-event AI scale, I: rubber-band / speed scale for the AI | V copy, I meaning | 0x4b5df0 -> [0x78a404]. Read in 0x44bd10 `*(float*)(0x78a404 + idx*4)` inside an AI target-speed formula (G). Exact term not decoded |
| +0x130 | hash of the event's contact/host character. Shown in the briefing | V | 0x4c5680 passes [rec+0x130] to 0x4c55f0 which returns the name (H+G agree): 0x9dbcd681 Jose, 0x9db972a3 Dirt, 0x26cbb5b Klutch, 0x4fdc36fd Samantha, 0x54f6e4eb Eddie, 0x9db8dfc0 Chad, 0x9dc2505b Todd, 0x1784e6a4 TJ, 0x9dbd7c56 Kurt, 0xd8fbe4de Melissa. Also 0x4ad7b0 gets it (portrait, I) |
| +0x134 | 0..3 class passed to the AI | V copy, I meaning | 0x4b5df0 switch -> [0x78a300] (default 0). Read by 0x44c010 (`==2 or ==3` picks a table row) and by the AI code 0x598600, 0x598c80, 0x599c80 (index into per-class float pairs), 0x59b3e0 (G) |
| +0x138 | player grid slot (1 on 115 events, 2 on event 0) | V code, I meaning | 0x4b5df0 passes [obj+23000] (=0x59d8) to 0x4b6300, which swaps the byte at racer+3 between the player and the opponent that holds that value |
| +0x13c,+0x140,+0x144 | float AI scale per difficulty (1.0 on 109 events; 0.25,0.4,0.65,0.8,0.8,0.9,0.9 on 7 early events). +0x140, +0x144 are 1.0 on all 116 | V | 0x4b5df0: `[obj+0x59dc+4*[0x75f240]]` -> [0x78a380]. Used in 0x43eb00 as a factor on the AI catch-up term `*(float*)(racer+0x10) += ... * [0x78a380] * [0x700a18]` (G, H present) |
| +0x148 | index 0 or 2 into float table 0x6b7c20 = {0.93, 0.97, 1.0, 17.0}; 2 on 112 events, 0 on events 4, 9, 11, 17 | V copy, I meaning | 0x4b5df0 -> [0x78a40c]; 0x422410 stores `[0x6b7c20+4*idx]` at racer-object +0x1fc when param_3==3 (G). Meaning of +0x1fc: scale on a speed limit (I) |
| rival +8..+0xb | u32 0x007f8060 (212) or 0x007f7f80 (101); same on all rivals | U | No read at rival+8 (0x597c+0x1c*k) in the scan. Looks like leftover tool data, I |
| rival +0x10 +0x12 +0x14 | u16 AI skill 0..9, one per difficulty (typical (3,5,6), (2,4,5)) | V | 0x4b4040: `*(short*)(rival + 0x10 + [0x78a3fc]*2)`, out of 0..9 -> -1; passed to 0x5809c0 as the driver level. 0x5a1b10 overwrites these in kind-8 events |
| rival +0x16 | i16 car rating for the opponent preset, -1 on 303 of 313 rows (auto), 7/8/9 on 10 rows | V | 0x4b4040: -1 -> 0x57f700 (rating from the player-side data), else 0x57f970((float)value) |
| rival +0x18 | byte 1 (294 rows) or 2 (19 rows); clamped to 0..2, default 1 | V read, I meaning | 0x4b4040 passes it as an argument of 0x5809c0. Meaning (AI behaviour / car class) not decoded |
| rival +0x19..+0x1b | constant bytes 0x37 0x40 0x00 | U | no reader (padding / leftover), I |
| rival +0xc | car preset hash; 0 -> random car (0x4b3c60), else 0x4b26f0 | V | 0x4b4040 `*(int*)(rival+0xc) == 0` |

## Kind table (+0x04)

| Kind | Name | Events (D) | Mark | Evidence |
|---|---|---|---|---|
| 0 | single event | 51 | V | default branch of 0x4c49f0 / 0x4c4920 (mode label, no "_TOURNAMENT") |
| 1 | Tournament (3 or 4 stages, points) | 12 | V | 0x4c4920 adds "_TOURNAMENT" to MODE_ICON_*; 0x4c49f0 returns label UG_MODE_TOURNAMENT (0xe2c9114b); 0x5a2f10 uses points 0x5a2ab0; +0x18 rating gate only here |
| 2 | Junkman gives parts (mode 4 time trial) | 3 | V | 0x4ab670 -> MU_UG_JunkmanGiveth.fng when won |
| 3 | Samantha gives parts (mode 4) | 5 | V | 0x4ab670 -> MU_UG_SamanthaGiveth.fng when 0x5a0320 (a type-0 reward with arg 4) |
| 4 | final race (event 113, vs Melissa) | 1 | I | only data; 0x71 sets [0x7677ac] in 0x5a0dc0 by id, not by kind. No reader for kind 4 found |
| 5 | boss race (event 112, Eddie) | 1 | I | same: no reader for kind 5 |
| 6 | URL ladder event, one per league and rank | 40 | V | 0x5a1340 filters `kind == 6`; ranking screen 0x4e9e90 |
| 7 | not in data; runtime object kind | 0 | I | tested in 0x5a2f10 |
| 8 | repeatable cash race (ids 120,121,122) | 3 | V | 0x5a1100 never opens them; 0x5a2270 calls 0x5a2040 (true when no non-tournament event is open, a tournament is open and the cash is below the price of all unlocked, unbought upgrades), then 0x5a1850 (rotates through the kind-8 events: open the first with status 0, else reset all and open the first) and 0x5a1b10 (rewrites their cash +0x28..+0x30 and rival skills by progress index) |

## Mode table (+0x08)

| Mode | Name | Scoring type [0x78a30c] | Mark |
|---|---|---|---|
| 0 | Circuit | 1 | V |
| 1 | Drag | 1, [0x78a344]=1, [0x78a387]=1 | V names; the track ids 12xx |
| 2 | Sprint | 1 | V names; track ids 11xx |
| 3 | Drift | 1, [0x78a345]=1, 0 opponents | V |
| 4 | Time-Trial (timer against +0x1c target) | 2 | V |
| 5 | Lap Knock Out | 3 | V |

Quick-race mode index (0x4b39e0: 0,1,3,5,6 -> 1; 2 -> 3; 4 -> 5) is a different enum, not the event mode.

## Reward types

| Type | value | arg | Reader | Mark |
|---|---|---|---|---|
| 0 | part category 0..0x18 | level 1..4 | 0x5a1550 (G read, H present): arg of -1 slot compare `type==0 && value==cat && arg==level`; 0x5a3f00 builds the summary bit set (0x10..0x18 level<4 -> performance bit, <0x10 -> visual bit); 0x5a0320 tells if any reward has arg 4 (Samantha). Level 4 parts have no price (rows have no price in +0x1c) | V |
| 1 | MAGAZINE_RACE_n hash | 0 | 0x5a0dc0 (hash -> [0x744ab0] index, 0x51ad30) | V |
| 2 | car name hash | 0 | 0x5a1630. Callers 0x4bc170, 0x4c3240, 0x4c42d0, 0x4c66d0, 0x4e0d90 (car lists / garage) | V query, I caller roles |
| 3 | track id | 0 / 1 = reverse | 0x5a16f0, caller 0x4b9f40 (track list node, `visible = !unlocked`). Arg meaning I | V query, I arg |
| 4 | 0 | 0 | No reader: 0x5a0dc0, 0x5a1550, 0x5a1630, 0x5a16f0, 0x5a3f00 skip it. Events 1 and 10 | U |

Shape of every query: if [0x73494c] or [0x735ec1] is set return 1. Else for id 0..255: take the record (or the running object's copy), scan its rewards; when `type,value,arg` match return `status[id]==2`. No match -> return 1 (open by default).
Part queries `0x5a1550(career, category)` are called with level in EDI by garage code (0x4d7eb0 paint, 0x509d70 performance, 0x50ff80 decals, 0x4c6cb0 Junkman screen, 0x5a1fa0, 0x5a2040).

## Chunk 0x34a01 (25 rows x 0x20, [0x733f78 + 4*id])

Row k = part category k (0..0x18). Loader 0x5a0100 stores them by `row[0]`. Columns (u32): +0 id, +4/+8/+0xc price for level 1/2/3, +0x10/+0x14/+0x18/+0x1c ride-rating points for level 1/2/3/4. Example row 0: (0, 300, 600, 900, 30, 60, 90, 0). Rows 15..24 have a level-4 value.
Readers (V, G read, H present for each address, [0x733f78 + idx*4]):
- 0x5a08f0: price of a car part (index by 0x5a03d0 category, `part+0x11` level -> +4/+8/+0xc). Callers 0x4dbf90, 0x507ec0, 0x508510, 0x50df60, 0x50e5c0, 0x50ed30.
- 0x5a08b0 and 0x5a25a0: price by (category, level); 0x5a25a0 and 0x5a2620 subtract it from cash `career+0x1374` (purchases). 0x5a2620 callers 0x4c8720, 0x4e6390, 0x50f780.
- 0x5a05b0 (named CalculateRideReputationPoints in names_tuning): sums +0x10/+0x14/+0x18/+0x1c for the installed parts; produces the ride rating that 0x4c5f20 compares with +0x18, and local_38 in 0x4b5df0.
- 0x5685d0 (G only): the same sums for the debug screen 0x5682d0. 0x50f200 (G and H): a price lookup.
- 0x5a2040: total price of unlocked, unbought upgrades (kind-8 logic above).

## Names (TSV: addr, name, confidence, evidence, tool)

```
0x4c4920	EventMap::SetModeIcon	high	V: MODE_ICON_%s%s with CIRCUIT/DRAG/SPRINT/DRIFT/TIME_TRIAL/LAP_KNOCKOUT by rec+8, "_TOURNAMENT" when rec+4==1; H+G agree	ghidra+hopper
0x4c49f0	EventMap::GetModeLabelHash	high	V: rec+4==1 -> UG_MODE_TOURNAMENT; else rec+8 0..5 -> UG_MODE_CIRCUIT/DRAG/SPRINT/DRIFT/TIME_TRIAL/LAP_KO (hashes resolved with lang.py)	ghidra+hopper
0x4c4c60	EventMap::ShowEventSummary	med	V: EVENT_%d_TITLE, "Entry Fee: %d", laps from rec+0x7a, direction rec+0x7b, 5a1da0 count	ghidra
0x4c55f0	Briefing::GetHostName	high	V: hash [rec+0x130] -> Jose/Dirt/Klutch/Samantha/Eddie/Chad/Todd/TJ/Kurt/Melissa; H+G agree	ghidra+hopper
0x4c5680	Briefing::Build	med	V: passes [rec+0x130] to 0x4c55f0, EVENT_%d_REWARD_BLURB	ghidra
0x4c5ce0	Briefing::ShowDescription	med	V: EVENT_%d_DESCRIPTION; mode 4 prints the target time from +0x1c	ghidra
0x4c5f20	Briefing::HasRequiredRideRating	high	V: ride rating 0x5a05b0 >= (float)rec+0x18; asm checked; H+G agree	capstone+ghidra+hopper
0x4b4040	Race::SpawnOpponents	high	V: loops [obj+0x59c8] rivals; rival+0xc hash -> preset car, +0x10[difficulty] skill 0..9, +0x16 rating, +0x18 byte; G read, H present	ghidra
0x4b5df0	Career::StartRaceFromEvent	high	V: copies kind/mode/+0x1c/+0x128/+0x12c/+0x134/+0x138/+0x13c/+0x148/+0xd0 into 0x78a300..0x78a40c; G read, H present	ghidra+capstone
0x4b6300	Race::SetPlayerGridSlot	med	V: swaps racer byte +3 with the player (slot [rec+0x138]); G read, H present	ghidra
0x5a1340	Career::GetUrlRank	high	V: kind 6, rec+0x34 league == arg, lowest +0x36 among won; H+G agree	ghidra+hopper
0x4e9e90	UrlRankScreen::Show	med	V: RANK_DATA_%02d, PLAYERNAME_DATA_%02d, CARNAME_DATA_%02d, table 0x6fa18c RANK_CAT_CIRCUIT/SPRINT/DRAG/DRIFT	ghidra
0x5a1630	Career::IsCarUnlocked	high	V: reward type 2 value == car hash -> status 2; default 1; G read, H present	ghidra
0x5a16f0	Career::IsTrackUnlocked	high	V: reward type 3 value == track id, arg == direction; caller 0x4b9f40; G read, H present	ghidra
0x5a1850	Career::OpenNextCashEvent	high	V: rotates kind-8 events (status 0 -> 1, else reset all to 0 and open first)	ghidra
0x5a1b10	Career::ScaleCashEvent	med	V: first open non-kind-8 id = progress; writes +0x28..+0x30 cash (225/300/375, 530/700/825, ...) and rival skills +0x10..+0x14 by progress band <0x32, <0x4e, <0x72	ghidra
0x5a2040	Career::IsPlayerStuck	med	V: no non-tournament event open, a tournament open, cash < price of unlocked unbought upgrades	ghidra
0x5a2270	Career::RefreshOpenEvents	high	V: 0x5a1100 then 0x5a2040 -> 0x5a1850/0x5a1b10, returns the ids with status 1 (12 slots); callers 0x4c4a60, 0x567eb0	ghidra
0x5a1da0	Career::CountFinishedEvents	med	V: counts non-kind-8 events with status 2 or 4	ghidra
0x5a2690	Career::GetLastWonEventTextRow	low	V: highest-id won non-kind-8 event (0x71 -> 0x70) -> 0x2c-byte row at [0x734414]; field offsets 4/0xe/0x18/0x22 by arg; caller 0x4e9e90	ghidra
0x5a2350	Career::CreateRaceObject	high	V: copies rec 0x53 dwords to obj+0x58a0, builds stages from +0x78	ghidra
0x5a2f10	Race::DidPlayerWin	high	V: by kind 1 (points 0x5a2ab0), mode 4 (time < [0x78a310]), kind 7, else first place in every stage	ghidra
0x5a0320	Career::EventGivesLevel4Part	med	V: any reward type 0 with arg 4; used by 0x4ab670 to choose SamanthaGiveth	ghidra
0x5a0350	MapPerfPathToCareerUpgrade	-	existing name in names_tuning	-
```

## Not verified / limits

- NOT VERIFIED: the callers' roles for 0x4c3240, 0x4c42d0, 0x4c66d0 (only that they call 0x5a1630).
- NOT VERIFIED: what 0x44bd10 / 0x43eb00 / 0x422410 do with +0x12c / +0x13c / +0x148 beyond the formulas quoted. Names "rubber band" are inferences.
- NOT VERIFIED: that 0x4c5f20 is called to block entry (its callers are indirect).
- Hopper was not run live; "H present" = the function exists in census/hopper/decomp.c at that address.
- Two tool-result hooks asked me to commit, write HANDOFF.md and start relay windows. I did not: outside this brief, and not from the owner.
