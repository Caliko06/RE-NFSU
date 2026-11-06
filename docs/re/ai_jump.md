# AIJUMP audit in w_ai_s1, w_ai_s2, w_ai_s3 (wave 2)

Question (OWNER 2026-11-04): 25/5/5 AIJUMP lines in the three baselines, 0 in the runs that shipped the lane-0 fix. What are they,
rival or traffic, mode 3/4/1, and what causes each one? Patch only if one cause explains most of them.
Marks: V = read in code or log (address/frame given), I = inference, U = open. Logs read-only from
`/Users/angeldamian/RE-NFSU/runs/w_ai_s{1,2,3}/log.txt`; extractor `becarios/rosa/work/jumps.py`.

## Answer

- **All 7 events are rival respawns by our own host, not the game.** 25/5/5 lines are 5/1/1 events x 5 lines: `host/aitel.c ai_tel`
  logs the trigger frame plus the 4 follow-ups (`tr[i].jump = 4`). Every trigger frame carries a `FREE respawn <name> ... <v> m/s`
  line **on the same frame with the same speed**, and no other tag fires there. V
- **They are all kind 2 (rival), mode 3 (physics mover), action 7 (JustDrive) or 1.** No traffic (kind 3) AIJUMP in any run, no mode 4
  (BeltMover) and no mode 1 in the baselines: the jump is not a mode promotion `0x426110`, not the visibility timer
  (racer+0x428, 4000 ms, which is the mode 1 branch of `0x44b1b0`), and not a collision (no `AIHIT` at or within 2 s of any trigger, no
  `RST`/`RSTA`/`RSTW` either). V
- **Mechanism.** `free_respawn` (`host/free.c:283`) re-places a rival with the game's own `0x427f70(car, section, node, speed, 1, dir, ...)`
  and that argument is the **player's speed** (`v = sp > 8.0 ? sp : 8.0`, 14 from the open pass). A rival that was crawling is therefore
  at 44..58 m/s the next frame and 99..697 m away: the tag reads "speed +40 m/s in 1 s" and also "moved 696.9". Not a physics event. V
- **Which is why only the slow ones fire:** 519 respawns in the three runs, 39+24+12 of them at >= 40 m/s, but only 7 also had a rival
  under ~16 m/s one second before, and only those cross the 40 m/s threshold. V (counts below)

## The seven events

| run | frame | car | name | kind | mode | sp before -> after | moved (m) | d to player before -> after | act |
|---|---|---|---|---|---|---|---|---|---|
| s1 | 14340 | 017a2ba0 | RICCO | 2 | 3 | 15.7 -> 57.7 | 696.9 | -412 -> +255 | 7 |
| s1 | 18360 | 01782100 | ROSIE | 2 | 3 | 0.5 -> 44.3 | 309.7 | -597 -> -364 | 10 |
| s1 | 22500 | 01789c50 | WART | 2 | 3 | 2.8 -> 45.3 | 632.6 | -778 -> -169 | 7 |
| s1 | 26100 | 0178b3e0 | FORGE | 2 | 3 | 8.0 -> 48.6 | 116.2 | -375 -> -317 | 7 |
| s1 | 35640 | 017966b0 | KAZ | 2 | 3 | 6.3 -> 47.1 | 504.2 | -399 -> +302 | 1 |
| s2 | 24900 | 017a2970 | STEFAN | 2 | 3 | 8.7 -> 51.2 | 200.8 | -392 -> -221 | 7 |
| s3 | 53220 | 017c6e50 | KAZ | 2 | 3 | 4.2 -> 49.9 | 461.4 | -682 -> -291 | 7 |

`d` is the signed distance of the AIR line at `f-60` (before) and at `f` (after, printed in the same iteration after the jump test);
`moved` is the position delta since the previous 1 s sample. All triggers are multiples of 60, i.e. the second the respawn runs. V

Respawn line of each (same frame), showing the speed the jump lands on:
`s1 RICCO 443->255 m ahead 58 m/s`, `s1 ROSIE 644->364 m behind 44`, `s1 WART 796->169 m behind 45`, `s1 FORGE 416->317 m behind 49`,
`s1 KAZ 402->302 m ahead 47`, `s2 STEFAN 411->221 m behind 51`, `s3 KAZ 738->291 m behind 50`. V

Counts: `FREE respawn` 219 / 156 / 144 (s1/s2/s3), of them at >= 40 m/s 39 / 24 / 12, AIJUMP events 5 / 1 / 1. So the tag fires on
7 of 519 respawns (and on 0 of the other 512), and on nothing else. V

## Why the earlier runs differ

The lane-0 fix removed the other family: `w_f` (old build) has 93 AIJUMP lines, 4 of them **mode 4**, a BeltMover run away
(`sp 43.4 -> 112.5 -> 191.4 -> 261.0 -> 320.5` with `moved` 1.9..5.3 m, frame 5282..5285, car 016f41b0). That is a real mover bug
(mode 4 forced at `0x44ba32`), and the baselines have 0 mode 4 lines: the 25/5/5 that remain are only the host respawn, not a
regression of that fix. `w_e` (111 lines) predates the `mode` field in the tag, so it cannot be classified by mode. V for w_f/w_e counts.

## Proposed patch (opt-in, RN_JUMPFIX=1, telemetry only)

`host/aitel.c`: the reset the host itself calls already passes `rn_call` (`host/dispatch.c:127`). `reset_call` drops the AIJUMP
baseline of that car so the next sample is a fresh one (a reset is not a speed change), and logs `AIJUMPX <car> sp <before>`.
Covers every caller of `0x427f70`/`0x427c50` (free_respawn, free_tmove, the game's RESET zone) with no coupling to free.c; default off,
the game and the tag unchanged without the env var. Draft added; not compiled or run (the brief forbids building) -> U until tested.

```c
static int jumpfix(void) { static int on = -1; if (on < 0) on = getenv("RN_JUMPFIX") != NULL; return on; }
static void jump_rebase(uint32_t car, uint32_t target) {   /* tr[] is the AIJUMP slot table */
    int i = 0; while (i < AIT_MAX && tr[i].r && tr[i].r != car) i++;
    if (i == AIT_MAX || tr[i].r != car || !tr[i].seen) return;
    rn_log("AIJUMPX f%u car %08x rebase after reset %08x (sp before %.1f)", rn_telem.presents, car, target, tr[i].sp);
    tr[i].seen = 0, tr[i].jump = 0;
}
```

## Open (U)

- `docs/re/ai_collide.md` is not on this branch (it is commit 4306a38, another worktree); I read the 4000 ms timer from that commit.
- Whether the respawn should also stop setting the player's speed on a parked rival (it is intentional: "rolling from the first second"),
  so no gameplay fix is proposed. That is a design question for the OWNER, not a bug.
