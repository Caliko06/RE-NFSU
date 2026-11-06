# Rival driving profiles (WORLD, track 1010): what the AI really reads

Tools: `objdump -d pc/Speed.exe` (base 0x400000) and `census/hopper/decomp.c`. No game run, no build.
F = read in code with address/bytes; I = inference; NV = not verified. Leads: docs/openworld/re_rival_personality.md,
docs/openworld/re_rivals_ai.md; every row below was re-read in asm unless marked I.

## 0. Answer in six lines
1. There is no per-car "skill/aggression" float. The game varies a rival through **three things**: its **skill level 1..9**
   (`entrant+0x735`), its **style byte** (`entrant+0x736`, picks the Block ceiling), and the **per-level record** 0x779ff8 +
   0x54*level it selects with that level. All personality fields live in that record (or in that style table).
2. **Writer**: the level record and 0x77a340 are copied by 0x462070 from GLOBALB.BUN chunk 0x34b00 (I for the chunk, doc
   lead); the level arrives as argument 5 of 0x5809c0 → `movb %cl,0x735(%esi)` (F, 0x5809f6), style as arg 6 → `0x736`
   (F, 0x580a06); host/rivals.c `rival_tables`/`rival_style` overwrite both after the load.
3. **Readers** are the AI code: 0x44c550 (speed/lookahead), 0x44bd10 (catch-up), 0x44b1b0 (timers, JustDrive),
   0x462740 (target accept = mistakes/tolerance), 0x44dbd0 + 0x451176 (Block), 0x451b00 (stuck/mistake), 0x6b7680..90 (consts).
4. **Mistakes** = the accept draw + the lookahead jitter + the stuck timer; there is no literal mistake counter (F: no such read
   in 0x44b1b0/0x44c550/0x4627ac).
5. **Free-roam rival**: host/free.c `free_rival` sets arg 5 (RN_FREESKILL, default "2,5,9,4,7,3,6,8,1"), host/rivals.c
   `rival_style` sets arg 6, then 0x5809c0 registers it; the same record at 0x779ff8 applies (F in host code, run NV).
6. Safe ranges follow the shipped per-level columns (section 2): scale 0.90..1.06, accept 0..1, lookahead 0..255 nodes,
   Block ceiling 0..1000, catch-up gap 1.0..2.0.

## 1. Field table (offset, reader, writer, effect, safe range)
Record base = `0x779ff8 + 0x54*level`, level 0..9 from `entrant+0x735`.

| Off | Reader (F) | Writer | Effect in the decision code | Safe range |
|---|---|---|---|---|
| +0x0c | `0x4627ac fcomps 0x77a004(%eax)`, eax=level*0x54 (F) | 0x462070 copy; host `rival_tables` | accept chance for a new Pass/Avoid target; refused target stays 1 s (`[obj+0x4d0/0x4d4]`). This is "mistakes/patience" | 0..1 (shipped 1; doc lead 1) |
| +0x14 | `0x44c72b fmuls 0x77a00c(%eax)` then `fmuls 0x4b8(%ebx)` (F) | same | multiplies the route speed the node asks for, before catch-up. This is "aggressive/clean" | 0.90..1.06 (shipped 0.95..1.0) |
| +0x18 | `0x44bf4a movl 0x77a010(%eax)`, eax=level*0x54 (F) | same | catch-up cap per level | 0.7..0.95 shipped |
| +0x1c/+0x20 | 0x44b21a (doc lead) | same | random range of the rethink timer `[obj+0x4a0]` = reaction | negative floats, shipped -5..-1.5 / -4.3..-0.8 |
| +0x34/+0x38 | 0x462ca8 / 0x462cb4 (doc lead) | same | seconds before nitro/boost use; +0x38 on last lap | 15..35 s |
| +0x4c | `0x44bd9d fcomps 0x77a044(%eax)` (F) | same | race-clock seconds before the catch-up gap term runs | 3..19 s |
| +0x50 | `0x44c667 movzbl 0x77a048(%esi)` → rand(2*(b+1))-(b+1) → `0x404(%ebx)` (F) | same | lookahead jitter in route nodes: how far ahead the speed lookup may jump = braking margin | 0..127 nodes (shipped 4..8) |
| +0x51 | 0x44cb49 (doc lead) | same | same idea for the 0x44cac0 lookup | 2..5 |
| +0x52 | 0x462bf9 (doc lead) | same | flag of 0x462b30 (map/fork branch) | 0/1 |
| style table `0x77a340[style*8]` | `0x44dbd0 cmpl 0x77a340(,%edx,8),%edi` and `0x451176 movl 0x77a340(,%ecx,8)` with ecx=entrant+0x736 (F) | 0x462070 copy from BUN + host `rival_style` | Block priority ceiling vs current action priority: >=400 beats Avoid (300) and Pass (200). This is "blocker" | 0..1000 (doc lead: style 0/1 = 200, style 2 = 400) |
| `entrant+0x735` | `0x5809f6 movb %cl,0x735(%esi)` (F); read via racer vt+0x58 = 0x44ca10 | 0x5809c0 arg 5; host/free.c RN_FREESKILL | selects the record row (everything above) | 0..9 |
| `entrant+0x736` | `0x580a06 movb %dl,0x736(%esi)` (F) | 0x5809c0 arg 6; host `rival_style` | selects the Block ceiling row | 0..2 (3+ = NV) |
| `[0x78a400]` | 0x44c010 (Hopper 124835: `eax=*dword_78a400; if != 0` picks the catch-up branch) | race setup 0x5488d0 block (Hopper 94250) | master gate of the catch-up gap path | 0/1, race-level not per car |
| `[0x78a404+4*slot]` | 0x44bd10 (doc lead) | NV | catch-up strength per player slot | >0 |
| 0x6b7680 / 0x6b7684 | 0x451b00 (doc lead + host/rivals.c comment) | not written by the game; host `ai_tune` | stuck time 0.4 s and speed 5.0 m/s before GetUnstuck counts = clumsy/recovery | 0.4..1.5 s / 3..5 m/s (host uses 1.5 / 3.0) |
| 0x6b7688 / 0x6b768c | 0x451b94..0x451bdb (doc lead) | game constants | mode 3 <25 m/s, mode 4 <20 m/s stuck branch | 20..25 m/s |

## 2. The AI object's own property block (per car, not per level)
0x44a6f0 registers the AICarController properties with sub_571c20 at `ecx+0x3f4,0x3ec,0x3f0,0x4c0,0x400,0x404,0x420,
0x424,0x428,0x42c` (F, Hopper 116045..116059): these are serialized per car, but their *readers* live in the action updates
(0x45f..), not in the personality code, so they are NOT a safe personality lever yet (NV which action reads which).

## 3. Four profiles as value sets (all fields named above, readers verified)
Level row chosen freely per rival (1..9); style via `entrant+0x736`.

| Profile | level row values | style | intent |
|---|---|---|---|
| **Aggressive** | +0x14 x1.04, +0x0c 1.0, +0x50 unchanged, +0x34/38 x0.5 | 2 (Block 400) | fastest line, blocks, nitro early |
| **Clean** | shipped record of its level | keep (0/1, Block 200) | no edits at all: shipped values are the clean baseline |
| **Blocker** | +0x14 x0.98, +0x0c 1.0, +0x50 x0.5 | 2 (Block 400) | slightly slower, parks in front, priority 400 > Avoid/Pass |
| **Clumsy** | +0x0c 0.35, +0x14 x0.94, +0x50 x2 (cap 127), +0x34/38 x1.4 | 1 (Block 200) | misses targets, wanders the speed lookup, brakes late |

Reaction and mistakes are only reachable through +0x1c/+0x20 (timer range) and +0x0c (accept) plus the global stuck
thresholds 0x6b7680/84; 0x6b7680..90 are global, so they cannot differ per rival without a per-car shim (NV).

## 4. How it reaches a free-roam rival (host/free.c)
`free_rival` computes the level from RN_FREESKILL into `a[4]`, `rival_ride`/`rival_style` rewrites `a[5]`, then
`call_guest(c, 0x5809c0, 7, a)` stores them into `entrant+0x735/0x736` (F, 0x5809f6/0x580a06). `rival_tables` copies the
shipped 10*0x54 block back and rewrites +0x0c/+0x14/+0x34/+0x38/+0x50 per level. So a WORLD rival's personality is decided
before its first tick and needs no patch to the AI code. Draft patch = this doc's profile table applied in
host/rivals.c `rival_tables` (one `switch` on profile, same fields) on branch bec/rosa; not written yet.

## 5. Open (NV)
- Shipped values of +0x0c/+0x14/+0x18/+0x4c/+0x50 per level were not read here (they live in GLOBALB, doc lead).
- 0x77a340 shipped rows (200/400) are a doc lead, not re-read.
- Who writes 0x78a404; whether 0x6b7680..90 could be made per car.
- Readers in the AI object property block 0x3f4..0x42c.
