# AI metrics: rivals (kind 2) and traffic (kind 3) from the ghost logs

Question (OWNER 2026-11-04): do WORLD rivals and traffic move badly: slow, clumsy, faster than the player, broken?
Method `python3 -I becarios/chavo/aistat.py <run>/log.txt`, read only. Same window in every run: first AIP sample
with player sp >= 2 m/s to the last one; 1 sample = 1 s (1 Hz); hits = counter max - min in the window; AIT only
logs traffic within 80 m, so 80 is the cap. Columns: n, sp50/sp90 m/s, sp/pl = rival speed / player speed, stuck = s under 2 m/s, getun = GetUnstuck calls.

Answer, first: rivals are not slow, they are broken in contact. w_a: rivals run 1.10-1.36x the player and hit
walls 12-48/min. w_L3: 9 teleports, one 108 m in a single frame, speeds up to 84.5 m/s. Traffic: 28-54% frozen.

AISTAT run w_x_base  window f3480-f14280 = 180 s  (idle head 10 s, tail 0 s)
player  n 181  sp50   6.0  sp90  30.9  max  49.0  m/s | moving 126 s, idle 30% of window
RIVAL      n  sp50  sp90  sp/pl  stuck(s)  getun  wall/min  car/min
JET       181  14.2  35.0   1.00         4     10      3.00     4.00
NUTZ      181  21.2  36.8   1.47         7      4      1.00     1.00
CARLA     181  15.3  32.4   1.14        17     10      1.33     0.67
PAUL      181  15.9  36.1   1.16        19      9      0.67     4.00
JACKIE    181  17.4  33.6   1.30        14      5      1.33     3.67
ISHII     181  21.5  33.7   1.33        17      2      1.67     3.00
PROBES    181  14.2  28.2   0.95        19     12      1.67     2.33
VIONCE    181  17.8  30.5   1.01         6      5      1.67     3.67
AIJUMP >40 m/s  rivals 0 (0 cars)  traffic 0 (0 cars) | AIHIT >=4 m/s  kind2 112  kind3 32  = 48.0/min
TRAFFIC  cars 21  samples 1449 | <=80 m med 8.0 p90 12.0 max 13 | speed med   0.0 p90  13.8 | stopped(<0.5) 54%  parked 0%
        hits/min wall 7.33  car 3.00

AISTAT run w_a  window f3120-f23340 = 337 s  (idle head 7 s, tail 0 s)
player  n 338  sp50  23.4  sp90  43.7  max  52.9  m/s | moving 318 s, idle 5% of window
HECTOR    338  31.1  52.7   1.30         6     13     13.18    11.22
RICCO     338  28.8  50.0   1.17        16     19     35.07     9.79
TODD      338  35.7  55.2   1.36         5     16     31.16     5.88
TICKETS   338  27.2  51.2   1.10        37     29     19.05     5.70
ISHII     338  27.8  50.5   1.13        21     24     48.43     9.08
JACKIE    338  22.6  47.5   0.95        33     29     37.21     4.81
STEFAN    338  25.8  56.2   0.99        34     38     38.64     5.52
STEWART   338  25.7  47.5   1.03        12     21     12.28     6.94
AIJUMP >40 m/s  rivals 0 (0 cars)  traffic 0 (0 cars) | AIHIT >=4 m/s  kind2 1651  kind3 300  = 347.4/min
TRAFFIC  cars 21  samples 1682 | <=80 m med 5.0 p90 9.0 max 13 | speed med   5.8 p90  16.7 | stopped(<0.5) 28%  parked 0%
        hits/min wall 32.58  car 19.41

AISTAT run w_b  window f3060-f21600 = 309 s  (idle head 5 s, tail 0 s)
player  n 310  sp50  22.3  sp90  42.8  max  57.3  m/s | moving 285 s, idle 8% of window
SAMANTHA  310  18.4  35.7   0.77        50     27     21.75     5.83
STEWART   310  20.6  39.8   0.83        31     16     30.49     7.38
STAN      310  25.6  35.4   0.99         9     21     30.29     3.50
ISHII     310  22.6  35.4   0.86        16     20     24.47     5.63
HECTOR    310  23.3  32.3   0.95         7     12     18.06     3.30
TODD      310  24.3  33.4   1.02         3      0      8.35     7.77
JOSE      310  23.9  35.0   0.91         6     12     11.65     6.60
FISH      310  25.0  34.9   0.99         7      8      7.77     7.18
AIJUMP >40 m/s  rivals 0 (0 cars)  traffic 0 (0 cars) | AIHIT >=4 m/s  kind2 1036  kind3 287  = 256.9/min
TRAFFIC  cars 21  samples 1485 | <=80 m med 5.0 p90 8.0 max 15 | speed med   5.9 p90  16.5 | stopped(<0.5) 28%  parked 1%
        hits/min wall 31.46  car 22.33

AISTAT run w_L3  window f3360-f39900 = 609 s  (idle head 9 s, tail 0 s)
player  n 610  sp50  18.4  sp90  42.2  max  53.3  m/s | moving 527 s, idle 13% of window
BRITTON   610  21.6  36.6   0.95        32     20      2.07     1.58
PRISS     610  24.2  39.5   1.06        29     20      1.77     2.17
DIRT      610  18.9  37.5   0.90        38     29      1.87     2.27
JARED     610  24.0  41.2   1.02        10     13      1.28     3.55
PROBES    610  21.2  39.0   0.90        25     19      1.58     2.46
TERRY     610  22.8  38.1   0.99        28     20      1.48     2.96
CARL      610  22.1  36.8   0.95        47     21      2.27     0.99
TJ        610  23.1  40.4   0.98        28     14      1.48     1.67
AIJUMP >40 m/s  rivals 9 (7 cars)  traffic 0 (0 cars) | AIHIT >=4 m/s  kind2 319  kind3 160  = 47.2/min
TRAFFIC  cars 21  samples 3975 | <=80 m med 6.0 p90 12.0 max 18 | speed med   5.1 p90  15.9 | stopped(<0.5) 37%  parked 0%
        hits/min wall 12.51  car 2.96

## What looks abnormal (V = read in log, I = inference, U = doubt)
- V w_a sp/pl: HECTOR 1.30, TODD 1.36, RICCO 1.17, TICKETS 1.10 vs player p90 43.7 m/s; rivals outrun him and still hit walls
  12-48/min (ISHII 48.4, STEFAN 38.6, RICCO 35.1); RICCO ends 197 wall + 55 car hits.
- V w_L3 AIJUMP mid-race f10740-f38580, 9 jumps on 7 cars: 0.6->40.8, 1.3->43.9, 21.1->65.1, 25.8->84.5, 1.4->72.6,
  8.3->63.3, 2.9->49.9, 25.1->66.3, 18.7->65.8, vs player max 53.3. f10740 also shows moved 108.8 m in one frame.
- I Same build, opposite failure: w_a/w_b rivals glued to walls, w_L3 rivals warp with the fewest wall hits (1.3-2.3/min).
- V w_b is the healthy one: rivals 0.77-1.02x the player, but SAMANTHA sits 50 s under 2 m/s with 27 GetUnstuck calls.
- V w_x_base is no baseline: player idle 30%, sp50 6.0, 2 min standstill with crash 2 on, traffic 54% frozen.

Proposed patch: none yet. Rerun w_ai_s1..s3 and diff. If AIJUMP repeats mid-race the suspect is the BeltMover/route
handoff (mode 3 vs 4, car+0x28; host/aitel.c AIBELT dumps it); if wall hits repeat at 30+/min it is collision response in
host/coll* (docs/re/coll_reset.md). U: hit counters are the game's own and the log does not say whether a long scrape counts
once or every frame; AIHIT is a rate (one crash emits several lines), not a count of cars. Read both between runs only.
