# M8.6 completion matrix (docs/archive/PLAN.md), Pod side. One native build/speed per row, each in its own run dir (AGENTS.md:
# game/ as a hard-link copy, its own save/), the game's autopilot drives (RN_AUTOPILOT, RN_SEED), RN_RASTER keeps the CPU
# backend off the frames nobody looks at, RN_FLOWLOG logs the game-flow states and keeps a shot at each change.
# usage: completion.py launch ROW[.SEED] ...     start rows in the background (nohup), runs/<row>.<seed>/
#        completion.py queue N ROW[.SEED] ...    the same, at most N at a time through macgate.sh, blocking (run it under nohup)
#        completion.py collect                   runs/*/log.txt -> census/completion.json (one row per run dir), shots -> WebP
#        completion.py table                     runs/cjump_*/log.txt -> census/ghost_career.tsv
import json, os, re, shutil, subprocess, sys, time
R = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BIN = os.environ.get('RN_BIN', f'{R}/build/speed')   # a frozen copy under build/, so a rebuild does not change a batch halfway
SECS, GAP = 1300, 3000   # 6/8 comes near 840 s with 4 rows on 10 cores; leaving takes ~30 s more
SEEDS = ['0x1234', '0x5678', '0x9abc']

# Drag and Drift: the mode's Accept can open the tutorial movie first (event 0xc519bfc8 -> MU_UG_MovieTheaterViewer.fng,
# HANDOFF 2026-10-25); RETURNs skip it and are dropped when the car list is already up.
MOVIE = ['4000@!MU_QuickRaceCarSelect:RETURN'] * 2

def menu(mode, loc=0):
    # Each tap waits for its screen (host/input.c: "=" anchors on a front-end package, rn_fe). Timed taps lost a stage:
    # the splash ate a RETURN and the RIGHT, so the mode DOWN landed on the profile screen (runs/sprint.0x1234
    # 2026-10-25: "flow fe" MU_UG_NewOrLoad_PC2 at the DOWN, mode stayed 0). Title RETURN, RETURNs until the profile
    # screen, profile, Quick Race (the main menu starts on it), mode, car, transmission dialog, track, options.
    q = lambda scr, k, ms=1500: f'{ms}@={scr}:{k}'
    return (['RETURN'] + ['3000@!MU_UG_NewOrLoad_PC2:RETURN'] * 4 + [q('MU_UG_NewOrLoad_PC2', 'RETURN'), q('MU_Main_PC', 'RETURN')]
            + [q('MU_QuickRaceModeSelect', 'DOWN')] * mode
            + [q('MU_QuickRaceModeSelect', 'RETURN')] + MOVIE * (mode in (2, 3)) + [q('MU_QuickRaceCarSelect', 'RETURN'), '1500@!MU_QuickRaceTrackSelect:RETURN']
            + [q('MU_QuickRaceTrackSelect', 'RIGHT')] * loc + [q('MU_QuickRaceTrackSelect', 'RETURN'), q('MU_QuickRaceOptions_PC', 'RETURN')])

# Quick Race MODE rows: 0 Circuit, 1 Sprint, 2 Drag, 3 Drift, 4 Lap Knockout, 5 Free Run (the list wraps; explore_qr shots).
# The main menu starts on QUICK RACE; GO UNDERGROUND is one UP.
# explore_*: a menu path tapped step by step with a kept frame every 120 (RN_KEEP), to learn a path before it is a row.
ROWS = {'explore_career': ','.join(f'{20000 + 4000 * i}:RETURN' for i in range(12)),
        'explore_qr': ','.join(f'{20000 + 3000 * i}:{k}' for i, k in enumerate(['RETURN', 'RETURN', 'RIGHT', 'RETURN'] + ['DOWN'] * 8)),
        # GO UNDERGROUND (one UP on MU_Main_PC), then RETURNs every 4 s through the new-career screens until the race HUD,
        # the race (autopilot), then plain RETURNs (NONE never shows) to see where the career comes back.
        'explore_ug': ','.join(['20000:RETURN', '3000@!MU_UG_NewOrLoad_PC2:RETURN', '3000@!MU_UG_NewOrLoad_PC2:RETURN', '3000@!MU_UG_NewOrLoad_PC2:RETURN',
                                '3000@!MU_UG_NewOrLoad_PC2:RETURN', '1500@=MU_UG_NewOrLoad_PC2:RETURN', '1500@=MU_Main_PC:UP', '1500@=MU_Main_PC:RETURN']
                               + ['4000@!HUD_SingleRace:RETURN'] * 15 + ['3000@6:RETURN'] * 2 + ['3000@6/8:RETURN'] + ['4000@!NONE:RETURN'] * 12),
        # career.0, the first event of a new career: NEW DRIVER PROFILE is two UPs above the first profile; type a name.
        # GO UNDERGROUND opens MU_UG_Explained (starts on Exit: LEFT, RETURN), then MU_UG_NewCareerFMV and the race on 1003.
        # That race has no results screen (6/4 -> 7/0); RETURNs skip MU_UG_NewCareerExtroFMV until MU_UG_ChooseCareerCar
        # (0x4ab670: [[0x777ccc]+0x58a0] picks the return screen; 0x4e89b0 the hub, Hopper build/hopper/newcareer.txt).
        # A loss ends on 6/8 with RewardPopup "Sorry, you lost this event" (Chrome 2026-10-25): RETURNs to PostRaceMenu, which
        # starts on Restart; its confirm starts on Cancel (LEFT = OK). Up to 3 restarts; a win never shows 6/8 and goes on.
        'career0': ','.join(['20000:RETURN'] + ['3000@!MU_UG_NewOrLoad_PC2:RETURN'] * 4 + ['1500@=MU_UG_NewOrLoad_PC2:UP'] * 2
                            + ['1500@=MU_UG_NewOrLoad_PC2:RETURN', '3000@!NONE:Z', '1000@!NONE:Z', '1500@!NONE:RETURN']
                            + ['4000@!MU_Main_PC:RETURN'] * 4 + ['1500@=MU_Main_PC:UP', '1500@=MU_Main_PC:RETURN']
                            + ['1500@=MU_UG_Explained:LEFT', '1500@=MU_UG_Explained:RETURN']
                            + ['4000@!HUD_SingleRace:RETURN'] * 15 + ['3000@6:RETURN'] * 2
                            + (['3000@6/8:RETURN'] + ['4000@!PostRaceMenu:RETURN'] * 6 + ['1500@=PostRaceMenu:RETURN', '3000@6:LEFT', '1500@6:RETURN']) * 3
                            + ['3000@3:RETURN'] + ['4000@!MU_UG_ChooseCareerCar:RETURN'] * 3),
        'circuit': menu(0), 'sprint': menu(1), 'drag': menu(2), 'drift': menu(3), 'lapko': menu(4), 'freerun': menu(5)}

# career_trace (docs/archive/PLAN.md 6.1): career0's new profile and prologue, won by RN_FINISH (no 6/8: the prologue has no
# results), RETURNs through MU_UG_NewCareerExtroFMV to MU_UG_ChooseCareerCar; then RN_CAREER (host/input.c) plays the
# career from the game's own open list with the unlock patches off (RN_UNLOCK=0). Parse: tools/census/career_trace.py.
# prologue: what a new career shows with no key on a movie: boot movies, 01_DAY, the race won by RN_FINISH, 02_FAN_S, the car, 02_FAN_E,
# the map, Back (the menu bar's BACK key; ESCAPE does nothing there, Chrome 2026-11-01) to the hub, then the first garage visit = 04_GUM_s.
ROWS['prologue'] = ','.join(['3000@=LS_Splash_PC:RETURN'] + ['3000@!MU_UG_NewOrLoad_PC2:RETURN'] * 4 + ['1500@=MU_UG_NewOrLoad_PC2:UP'] * 2
                            + ['1500@=MU_UG_NewOrLoad_PC2:RETURN', '3000@!NONE:Z', '1000@!NONE:Z', '1500@!NONE:RETURN'] + ['4000@!MU_Main_PC:RETURN'] * 4
                            + ['1500@=MU_Main_PC:UP', '1500@=MU_Main_PC:RETURN', '1500@=MU_UG_Explained:LEFT', '1500@=MU_UG_Explained:RETURN']
                            + ['3000@6:RETURN'] * 2 + ['1500@=MU_UG_ChooseCareerCar:RETURN'] * 3
                            + ['1500@=MU_UG_MapScreen:BACK', '1500@=MU_UG_UndergroundMenu:DOWN', '1500@=MU_UG_UndergroundMenu:RETURN'])
ROWS['career_trace'] = ','.join(ROWS['career0'].split(',')[:ROWS['career0'].split(',').index('3000@6:RETURN')]
                                + ['3000@6:RETURN'] * 2 + ['3000@3:RETURN'] + ['4000@!MU_UG_ChooseCareerCar:RETURN'] * 3
                                + ['1500@=MU_UG_ChooseCareerCar:RETURN'] * 3)

# After the race (flow state 6/8), RETURN walks Results -> Race Style Points -> the post-race menu (Restart, Statistics,
# Leave Race; RETURN there opens "Restart Race? OK / Cancel", runs/leave_ret 2026-10-25). So: three RETURNs, DOWN DOWN to
# Leave Race, RETURN, then the confirm: it starts on Cancel, LEFT moves to OK (runs/circuit.0x5678 2026-10-25: 6/8 ->
# 7/0 at 9543 -> front end 3 at 9575 -> second race; the RETURN and RIGHT variants stayed on the dialog).
# Taps "ms@6/8:" wait for that state and count from the tap before (host/input.c). Then, back in the front end (state 3,
# any race state), RETURNs start the next race from wherever the menu lands.
# Race Style Points takes two RETURNs (the first skips the tally): runs/circuit.0x1234 DILOG, RETURN 8641 -> Points,
# RETURN 8701 -> tally 77..457 done, DOWN DOWN 8761/8810 lost on Points, RETURN 8821 -> menu (8880, cursor on Restart),
# RETURN 8881 -> "Restart Race?" (8940). The menu reads keys on edges only (0x5744b0), so a tap on Points is gone.
# The screens before the menu vary (0x49e100: Results, StyleAnimator, RewardPopup only with a reward, runs/lapko.0x5678
# "Style Reward" ate a RETURN), so RETURNs walk them until the flow log sees PostRaceMenu (host/d3d9.c rn_screen) and the
# rest are dropped; the menu taps wait for it.
_LEAVE = ['3000@6/8:RETURN'] + ['4000@!PostRaceMenu:RETURN'] * 6 + ['1500@=PostRaceMenu:DOWN'] * 2 + ['1500@=PostRaceMenu:RETURN']
LEAVE = [_LEAVE + ['3000@6:LEFT', '1500@6:RETURN']] * 3
NEXT = ['8000@3:RETURN'] + ['3000@3:RETURN'] * 9

def keys(seq, post=()):
    # The first tap at 20 s (the intro movie), then each waits for its screen; in the race, two RETURNs leave PreRaceStats.
    return ','.join([f'20000:{seq[0]}'] + seq[1:] + ['3000@6:RETURN'] * 2 + list(post))

# sweep_<mode>: every track of a mode in one run. After Leave Race the front end comes back on MU_QuickRaceModeSelect
# with the cursor on the mode (runs/sprint.0x1234 2026-10-25, "flow fe" at 15060); each next race takes one more RIGHT
# on the track list (the list keeps its cursor: assumed, the "flow open" TRACKB ids show it).
SWEEP = {'circuit': (0, 8), 'sprint': (1, 8), 'drag': (2, 6), 'drift': (3, 8), 'lapko': (4, 8), 'freerun': (5, 8)}
def sweep(mode, start=0):   # sweep_<mode>-<k>: from the k-th track of the list on (the tracks a short run missed)
    m, n = SWEEP[mode]
    q = lambda scr, k: f'1500@={scr}:{k}'
    race = ['3000@6:RETURN'] * 2 + _LEAVE + ['3000@6:LEFT', '1500@6:RETURN']
    out = keys(menu(m, start)).split(',')[:-2] + race
    for i in range(start + 1, n):
        out += [q('MU_QuickRaceModeSelect', 'RETURN')] + MOVIE * (m in (2, 3)) + [q('MU_QuickRaceCarSelect', 'RETURN'), '1500@!MU_QuickRaceTrackSelect:RETURN',
                q('MU_QuickRaceTrackSelect', 'RIGHT'), q('MU_QuickRaceTrackSelect', 'RETURN'), q('MU_QuickRaceOptions_PC', 'RETURN')] + race
    return ','.join(out)
ROWS.update({f'sweep_{k}': sweep(k) for k in SWEEP})
# Free Run has no finish (Chrome 2026-10-25: 11 min on 1002, no end): learn the pause menu (ESC -> MU_Pause_PC) step by step.
# Free Run has no finish (Chrome 2026-10-25: 11 min on 1002, no end). Pause (ESC -> MU_Pause_PC: Resume, Restart, Options,
# Leave Race; runs/explore_pause shot 2702), Leave Race, then its confirm MU_PauseConfirm (assumed like the post-race one:
# starts on Cancel, LEFT = OK).
FREE_LEAVE = ['60000@6/4:ESCAPE'] + ['1500@=MU_Pause_PC:DOWN'] * 3 + ['1500@=MU_Pause_PC:RETURN', '1500@=MU_PauseConfirm:LEFT', '1500@=MU_PauseConfirm:RETURN']
ROWS['freerun'] = ','.join(keys(menu(5, 3)).split(',') + FREE_LEAVE)

# garage: RN_OPEN (host/input.c) switches MU_Main_PC to MU_MainMenuCarCustomize as the menu does (0x4b3494), then
# Next, Visual, Body, Spoiler into the parts browser and four parts (runs/open_garage shot 5100: kit STRIKE on the car).
_PROFILE = ['RETURN'] + ['3000@!MU_UG_NewOrLoad_PC2:RETURN'] * 4 + ['1500@=MU_UG_NewOrLoad_PC2:RETURN']
ROWS['garage'] = ','.join(['0:RETURN'] + _PROFILE[1:] + [f'1500@={s}:RETURN' for s in ('MU_MainMenuCarCustomize', 'MU_Garage', 'MU_GaragePartsChooseVisual', 'MU_GaragePartsCategoryVisual')] + ['3000@!NONE:RIGHT'] * 4)
# options: RN_OPEN opens MU_OptionsSelector_PC (0x4b3413), Audio, Volume LEFT x3, Back x2; leaving saves nothing
# (0x4d4892), so RN_CALL runs the save 0x41c7a0 (.cfg/.opt, as autosave 0x4c9705) back on MU_Main_PC. reload_options.<seed>
# opens Audio again on that save/ (runs/reload_opt 2026-10-25: Volume one notch, the .opt bytes 62, 65 and checksum moved).
_OPTS = ['0:RETURN'] + _PROFILE[1:] + ['1500@=MU_OptionsSelector_PC:RETURN']
ROWS['options'] = ','.join(_OPTS + ['2000@!NONE:LEFT'] * 3 + ['2000@!NONE:BACK'] * 2)
OPEN = {'garage': 'MU_Main_PC>MU_MainMenuCarCustomize:20', 'options': 'MU_Main_PC>MU_OptionsSelector_PC:10'}
CALL = {'options': 'MU_Main_PC#2:41c7a0'}

# jump_<mode>_<track>+<track>..: RN_JUMP (host/input.c) starts each race from MU_QuickRaceModeSelect with the game's own
# Accept 0x4b5c00 (mode = [0x777cc8] id: 0 circuit, 1 sprint, 2 lap KO, 3 free run, 5 drag, 6 drift); the keys only reach
# that screen, leave each race, and wait for the front end (state 3) before the next race's PreRaceStats RETURNs.
def jump(name):
    m, tracks = int(name.split('_')[1]), name.split('_')[2].split('+')
    q = lambda scr, k: f'1500@={scr}:{k}'
    pre = ['RETURN'] + ['3000@!MU_UG_NewOrLoad_PC2:RETURN'] * 4 + [q('MU_UG_NewOrLoad_PC2', 'RETURN'), q('MU_Main_PC', 'RETURN')]
    leave = FREE_LEAVE if m == 3 else _LEAVE + ['3000@6:LEFT', '1500@6:RETURN']
    out = keys(pre, leave).split(',')
    for _ in tracks[1:]: out += ['1000@3:LSHIFT', '3000@6:RETURN', '3000@6:RETURN'] + leave
    return ','.join(out), ','.join(f'{m}:{t}' for t in tracks), 330 * len(tracks) + 120

# cjump_<n>+<n>..: RN_JUMP "e<n>" (host/input.c) starts career row n (record n of the event table) from MU_UG_MapScreen with
# the map's own path (0x5a0ce0, 0x4dfa10, 0x4b5df0). The OWNER's save (profile asas, first on the list) opens on the map
# after GO UNDERGROUND and RETURN on the hub MU_UG_UndergroundMenu (runs cj1 2026-10-25: e1 at frame 1231, results 6/8 at 4795). Each race leaves as Quick Race does.
def cjump(name):
    evs = name.split('_')[1].split('+')
    q = lambda scr, k: f'1500@={scr}:{k}'
    pre = ['RETURN'] + ['3000@!MU_UG_NewOrLoad_PC2:RETURN'] * 4 + [q('MU_UG_NewOrLoad_PC2', 'RETURN'), q('MU_Main_PC', 'UP'), q('MU_Main_PC', 'RETURN'), q('MU_UG_UndergroundMenu', 'RETURN')]
    leave = _LEAVE + ['3000@6:LEFT', '1500@6:RETURN']
    # Each stage of a tournament ends in its own results. The next stage's keys first anchor on its race (6/4): else
    # their "@6/8" anchors on the stage before's 6/8 and fires on the loading screen (runs/cjump_6+.. taps 22-23).
    # After a stage that is not the last, PostRaceMenu is Next Race, Restart Race, Restart Tournament, Statistics, Quit
    # Tournament (runs/cjump_6 shot 12173): the race leave's DOWN DOWN RETURN restarts the tournament, so RETURN = Next Race.
    # Next Race itself is RN_NEXT (host/input.c): its confirm opens with No focused (runs/cjump_6 taps 18-19).
    # After the last stage the menu is the same and Next Race ends the tournament (runs/cjump_6 shot 4301, 3 stages done).
    # Three taps reach PostRaceMenu from the results (runs/cjump_6 taps 12-14); a fourth is dropped there or lands on the
    # loading screen.
    res = ['3000@6/8:RETURN'] + ['4000@!PostRaceMenu:RETURN'] * 4
    # The next stage loads from the race (RN_NEXT 0x64bf64d2 -> 0x497410, race message 9); its keys anchor on its race.
    nxt = ['3000@6/4:RETURN']
    stages = lambda e: (res + nxt) * (STAGES[f'career.{e}'] - 1) + (res if STAGES[f'career.{e}'] > 1 else leave)
    out = keys(pre, stages(evs[0])).split(',')
    # The next event starts from the hub (RN_JUMP, host/input.c): no key to the map.
    for e in evs[1:]: out += ['3000@6:RETURN', '3000@6:RETURN'] + stages(e)
    # A tournament runs its stages back to back (runs/cjump_5+..: event 6 stage 3 began as RN_SECS ran out): time per stage.
    return ','.join(out), ','.join(f'e{e}' for e in evs), 330 * sum(STAGES[f'career.{e}'] for e in evs) + 120, '+'.join(str(STAGES[f'career.{e}'] if STAGES[f'career.{e}'] > 1 else 0) for e in evs)

# reload_<run dir>: a new process on that run's save/ (a page reload in Chrome), the same route to the career map.
# game.save_reload is OK when its "flow career" count on the map equals the count the source run ended with.
def launch(run):
    if run.startswith('reload_'): return reload(run)
    row, seed = (run.split('.') + [SEEDS[0]])[:2]
    d = f'{R}/runs/{row}.{seed}'
    subprocess.run(['rm', '-rf', d]); os.makedirs(d)
    subprocess.run(['cp', '-al', f'{R}/game', f'{d}/game'], check=True)
    subprocess.run(['cp', '-r', f'{R}/save', f'{d}/save'], check=True)
    jmp = jump(row) if row.startswith('jump_') else cjump(row) if row.startswith('cjump_') else None
    seq = jmp[0] if jmp else ROWS[row] if '-' not in row else sweep(row[6:].split('-')[0], int(row.split('-')[1]))
    # RN_TURBO 4: the guest clocks run 4x (host/win32.c now_us); a sprint race + leave took ~10 min at 1x, ~3.3 min at 4x.
    secs = 330 * (SWEEP[row[6:].split('-')[0]][1] - int((row + '-0').split('-')[1])) + 120 if row.startswith('sweep_') else SECS
    env = dict(os.environ, RN_TURBO='4', RN_SECS=str(secs), RN_SCREEN='640x480', RN_RASTER='1000000', RN_FLOWLOG='1', RN_SEED=seed,
               RN_AUTOPILOT='1', RN_KEYS=seq if isinstance(seq, str) else keys(seq, LEAVE[SEEDS.index(seed) % 3] + NEXT))
    if row.startswith('explore'): env.update(RN_KEEP='120', RN_SECS='600')
    if row in OPEN: env.update(RN_OPEN=OPEN[row], RN_SECS='45', RN_KEEP='500')
    if row in CALL: env.update(RN_CALL=CALL[row])
    if row == 'career_trace': env.update(RN_CAREER='1', RN_FINISH='1', RN_UNLOCK='0', RN_SECS='12000')
    if row == 'prologue': env.update(RN_FINISH='1', RN_SECS='600')
    env.setdefault('RN_WORLD_DIR', f'{R}/build/openworld')   # the WORLD row's merged TRACKB and minimap (host/openworld.c); runs start in runs/<row>/
    if jmp: env.update(RN_JUMP=jmp[1], RN_SECS=str(jmp[2]), **({'RN_NEXT': jmp[3]} if len(jmp) > 3 else {}))
    if os.environ.get('RN_KEEP'): env['RN_KEEP'] = os.environ['RN_KEEP']   # a kept frame every N (look inside a long race)
    with open(f'{d}/log.txt', 'w') as log:
        return subprocess.Popen(['nice', '-n', '5', BIN, f'{R}/pc/Speed.exe', 'game', '--shot', 'shot.png'], cwd=d, env=env,
                         stdout=log, stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL, start_new_session=True)

def reload(run):
    d, src = f'{R}/runs/{run}', f'{R}/runs/{run[7:]}'
    subprocess.run(['rm', '-rf', d]); os.makedirs(d)
    subprocess.run(['cp', '-al', f'{R}/game', f'{d}/game'], check=True)
    subprocess.run(['cp', '-r', f'{src}/save', f'{d}/save'], check=True)
    seq = cjump('cjump_0')[0].split(',')[:-len(_LEAVE) - 4] + ['4000@=MU_UG_MapScreen:RIGHT']
    env = dict(os.environ, RN_TURBO='4', RN_SECS='150', RN_SCREEN='640x480', RN_RASTER='1000000', RN_FLOWLOG='1', RN_KEYS=','.join(seq))
    if run.startswith('reload_options'): env.update(RN_KEYS=','.join(_OPTS), RN_OPEN=OPEN['options'], RN_SECS='30', RN_KEEP='500')
    with open(f'{d}/log.txt', 'w') as log:
        return subprocess.Popen(['nice', '-n', '5', BIN, f'{R}/pc/Speed.exe', 'game', '--shot', 'shot.png'], cwd=d, env=env,
                         stdout=log, stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL, start_new_session=True)

def careers(d):   # the "flow career N status H" of a run, in order (host/d3d9.c flow_log: H hashes the event status bytes)
    p = f'{d}/log.txt' if os.path.exists(f'{d}/log.txt') else f'{d}/flow.txt'
    return [(int(m[1]), m[2]) for m in re.finditer(r'^flow career (\d+) status (\w+)', open(p, errors='replace').read(), re.M)]

# A movie plays when two kept frames while an *FMV.fng screen is up (LS_IntroFMV, MU_UG_NewCareerFMV) show a picture
# (not flat) and differ (runs/explore_new: 01_DAY frame 2160 is a wheel, MU_UG_NewCareerFMV 2101-2282).
def movie(d):
    txt = open(f'{d}/log.txt', errors='replace').read()
    if 'flow open MOVIES' not in txt: return None
    from PIL import Image, ImageStat
    fe = [(int(m[2]), 'FMV.fng' in m[1]) for m in re.finditer(r'^flow fe (.*) \(frame (\d+)\)', txt, re.M)] + [(1 << 30, False)]
    for (a, on), (b, _) in zip(fe, fe[1:]):
        if not on: continue
        pics = []
        for n in sorted(int(f.split('.')[2]) for f in os.listdir(d) if re.fullmatch(r'shot\.png\.\d+\.png', f)):
            if a < n < b:
                im = Image.open(f'{d}/shot.png.{n}.png').convert('L').resize((64, 48))
                if ImageStat.Stat(im).stddev[0] > 20: pics.append((n, im.tobytes()))
        if len({p for _, p in pics}) > 1: return f'movie frames {pics[0][0]}..{pics[-1][0]} between frames {a} and {b}'
    return None

def game_rows():   # the whole-game rows (census/rows.json group game) a run proves
    out, names = {}, lambda f: set(open(f, 'rb').read().split(b'\0')) - {b''} if os.path.exists(f) else set()
    ok = lambda row, why: {'row': row, 'reached': {'back_to_menu': True}, 'why': why}
    for r in sorted(os.listdir(f'{R}/runs')):
        d = f'{R}/runs/{r}'
        if r.startswith('reload_') and os.path.isdir(f'{R}/runs/{r[7:]}'):
            # The source run's race changed the autosave (0x4c96f0 writes <profile>_autosave.ugd, which the profile
            # load reads back: runs/reload_cjump_7) and the reload's status bytes equal the source's last ones.
            a, b, sv = careers(f'{R}/runs/{r[7:]}'), careers(d), lambda x: open(f'{x}/save/asas_autosave.ugd', 'rb').read()
            if a and b and a[-1][0] > 0 and b[-1] == a[-1] and sv(f'{R}/runs/{r[7:]}') != sv(R):
                out[f'{r}#game'] = ok('game.save_reload', f'career {a[-1]} -> reload {b[-1]}')
        src = f'{R}/runs/{r[7:]}'
        if r.startswith('reload_options') and os.path.isdir(src) and os.path.exists(f'{d}/log.txt'):
            opt = lambda x: open(f'{x}/save/asas.opt', 'rb').read() if os.path.exists(f'{x}/save/asas.opt') else b''
            if opt(src) and opt(src) != opt(R) and b'MU_Options_PC.fng' in open(f'{d}/log.txt', 'rb').read():
                out[f'{r}#game'] = ok('game.options', 'asas.opt changed by the save 0x41c7a0, reloaded into Options')
        log = f'{d}/log.txt'
        if os.path.exists(log) and b'MU_GaragePartsBrowser.fng' in open(log, 'rb').read(): out[f'{r}#garage'] = ok('game.garage', 'parts browser reached')
        mv = movie(d) if os.path.exists(log) else None
        if mv: out[f'{r}#movies'] = ok('game.movies', mv)
        new = {n for n in names(f'{d}/save/Profiles.usr') - names(f'{R}/save/Profiles.usr') if n.isalnum()}
        if new and any(os.path.exists(f'{d}/save/{n.decode()}.cfg') for n in new): out[f'{r}#profile'] = ok('game.profile', f'new profile {sorted(new)}')
    return out

ALL_ROWS = {r['id']: r['group'] for r in json.load(open(f'{R}/census/rows.json'))['rows']}
QR_ROWS = {k for k, g in ALL_ROWS.items() if g == 'quick_race'}
STAGES = {r['id']: len(r['stages']) for r in json.load(open(f'{R}/census/rows.json'))['rows'] if r.get('stages')}
STAGE1 = {r['id']: r['stages'][0]['track'] for r in json.load(open(f'{R}/census/rows.json'))['rows'] if r.get('stages')}

def rows_of(d):
    # flow.txt: only the flow lines of a log that was too big to keep (2026-10-24: 5-8 GB each, Pod disk full)
    log = open(f'{d}/log.txt' if os.path.exists(f'{d}/log.txt') else f'{d}/flow.txt', errors='replace').read().splitlines()
    # A run can chain races (menu, race, back to menu, the next race): one row per race. A race's lines run from the
    # front end it starts in to the front end it comes back to (the first "flow state 3/" after a "flow state 7/").
    cut, unl = [0], False
    for i, l in enumerate(log):
        if l.startswith('flow state 7/'): unl = True
        elif unl and l.startswith('flow state 3/'): cut.append(i); unl = False
    return [row_of(d, log[a:b + 1]) for a, b in zip(cut, cut[1:] + [len(log)])]

def row_of(d, log):
    st = [(int(m[1]), int(m[2]), int(m[3])) for m in (re.match(r'flow state (\d+)/(-?\d+) \(frame (\d+)\)', l) for l in log) if m]
    seen = [s for s, _, _ in st]
    raced = 6 in seen
    after = seen[seen.index(6):] if raced else []
    back = 7 in after and 3 in after[after.index(7):]
    again = back and 6 in after[after.index(7):]
    # The row (census/rows.json id): the track is the TRACKB<id>.LZC the game opened (host/win32.c RN_FLOWLOG), the mode is
    # [0x777cc8] at the Accept (host/d3d9.c "flow mode"). A track the mode does not list (rows.json, 0x4ab470) is no row (2026-10-25: sprint/drag/drift taps loaded 1002).
    ids = {0: 'circuit', 1: 'sprint', 2: 'lapko', 3: 'freerun', 5: 'drag', 6: 'drift'}
    modes = [int(m[1]) for m in (re.match(r'flow mode (\d+)', l) for l in log[:next((i for i, l in enumerate(log) if l.startswith('flow state 6/')), len(log))]) if m]
    # No "flow mode" line, no mode: the timed taps of those runs put the mode DOWNs on the profile screen (2026-10-25).
    mode = ids.get(modes[-1], f'mode{modes[-1]}') if modes else None
    trk = [int(m[1]) for m in (re.search(r'flow open .*TRACKB(\d{4})\.LZC', l, re.I) for l in log) if m]
    # The game type [0x777b4c] at the Accept: 1 = career, 2 and 4 = Quick Race (0x4ab670 picks the return screen on it).
    gt = [int(m[1]) for m in (re.match(r'flow mode \d+ gametype (\d+)', l) for l in log[:next((i for i, l in enumerate(log) if l.startswith('flow state 6/')), len(log))]) if m]
    career = bool(gt) and gt[-1] == 1
    row = f'qr.{mode}.{trk[0]}' if trk and not career and f'qr.{mode}.{trk[0]}' in QR_ROWS else None
    # A career run: the event under the cursor at the race start ([0x735dc8], host/d3d9.c "flow event").
    ev = [int(m[1]) for m in (re.match(r'flow event (\d+)', l) for l in log[:next((i for i, l in enumerate(log) if l.startswith('flow state 6/')), len(log))]) if m]
    # [0x735dc8] stayed 0 when the map picked a later event (runs/explore_ug: drift on 1301), so the opened track must be the
    # event's first stage too.
    if career and ev and trk and STAGE1.get(f'career.{ev[-1]}') == trk[0]: row = f'career.{ev[-1]}'
    # A career jump names its row (host/input.c "RN_JUMP: career event N"); the opened track must still be its first stage.
    cj = [int(m[1]) for m in (re.match(r'RN_JUMP: career event (\d+)', l) for l in log) if m]
    if career and cj and trk and STAGE1.get(f'career.{cj[-1]}') == trk[0]: row = f'career.{cj[-1]}'
    # A tournament is done when every stage has its results (runs/cjump_6 2026-10-25: stage 1 back to the hub alone counted).
    if row and STAGES.get(row, 1) > 1:
        n = sum(1 for a, b in zip(st, st[1:]) if (b[0], b[1]) == (6, 8) and (a[0], a[1]) != (6, 8))
        back = back and n >= STAGES[row]

    stop = next((l for l in reversed(log) if re.search(r'STOP|stop:|unimplemented|missing|fault|abort', l, re.I)), '')
    end = next((l for l in reversed(log) if l.startswith('RN_SECS')), 'running or killed')
    return {'row': row, 'mode': mode, 'track': trk[0] if trk else None, 'reached': {'menu': 3 in seen, 'start': raced, 'racing': any(s == 6 and r not in (1, 255) for s, r, _ in st),
                        'results': any(s == 6 and r == 8 for s, r, _ in st),
                        'unload': 7 in after, 'back_to_menu': back, 'second_race': again},
            'states': [f'{s}/{r}@{f}' for s, r, f in st], 'stop': stop, 'end': end,
            'shots': sorted(f for f in os.listdir(d) if f.endswith('.webp'))}

def webp(d):   # the PNG shots -> WebP (only these and completion.json come down to the Mac)
    from PIL import Image
    for f in os.listdir(d):
        if f.startswith('shot.png') and f.endswith('.png') and not os.path.exists(f'{d}/{f[:-4]}.webp'):
            Image.open(f'{d}/{f}').save(f'{d}/{f[:-4]}.webp', quality=80)

CMD = sys.argv[1] if __name__ == '__main__' else None   # imported (tools/savegate.py): routes only
if CMD == 'launch':
    for r in sys.argv[2:]: launch(r)
elif CMD == 'queue':
    def live():   # every native row of this repo, also those another queue started (one game process at a time)
        ps = subprocess.run(['ps', '-axo', 'command='], capture_output=True, text=True).stdout.splitlines()
        return sum(l.startswith(f'{R}/build/speed') for l in ps)
    # A run whose game flow state has not moved for STALL s is stuck (runs/cjump_46+..: PostRaceResults for 1 h): kill it, go on.
    # The longest race leg seen is ~200 s of one flow state at RN_TURBO 4.
    STALL = 420
    GATE = os.path.expanduser('~/.claude/hooks/macgate.sh')
    n, todo, kids = int(sys.argv[2]), sys.argv[3:], {}
    while todo or kids:
        for k, w in list(kids.items()):
            if k.poll() is not None:
                if os.environ.get('RN_SLIM'):   # a batch over the whole canon on a small disk: only the log stays
                    d = os.path.dirname(w[0])
                    shutil.rmtree(f'{d}/game', ignore_errors=True)
                    for f in os.listdir(d):
                        if f.endswith('.png'): os.remove(f'{d}/{f}')
                del kids[k]; continue
            flows = open(w[0], 'rb').read().count(b'flow state')
            if flows != w[1]: kids[k] = [w[0], flows, time.time()]
            elif time.time() - w[2] > STALL:
                print(f'{time.strftime("%T")} {w[0]}: no flow change for {STALL} s, killed', flush=True)
                k.kill()
        free = shutil.disk_usage(R).free >> 30   # never launch under RN_MINFREE GB free (default 5; 4 with tools/shots_gc.py loop purging shots)
        minfree = int(os.environ.get('RN_MINFREE', '5'))
        # N is a ceiling; the machine-wide gate (memory level, launches 30 s apart, every session) decides each launch.
        if todo and live() < n and free >= minfree and subprocess.run([GATE, '--try']).returncode == 0:
            row = todo.pop(0)
            kids[launch(row)] = [f'{R}/runs/{row if "." in row else row + "." + SEEDS[0]}/log.txt', 0, time.time()]
        elif todo and free < minfree: print(f'{time.strftime("%T")} {free} GB free: {todo[0]} waits', flush=True)
        time.sleep(10)
elif CMD == 'table':   # runs/cjump_<n>.0x1234/log.txt (a RN_AILOG=1 batch) -> census/ghost_career.tsv: one row per career event (docs/archive/PLAN.md "Ghost player")
    cols = 'ev kind mode stages results state rivals me_rank rival_wall me_wall polymax movies stop'.split()
    out = []
    for row in json.load(open(f'{R}/census/rows.json'))['rows']:
        p = f"{R}/runs/cjump_{row['id'].split('.')[1]}.0x1234/log.txt"
        if row['group'] != 'career' or not os.path.exists(p): continue
        t = open(p, errors='replace').read()
        st = [(int(a), int(b)) for a, b in re.findall(r'^flow state (\d+)/(-?\d+) ', t, re.M)]
        res = sum(b == (6, 8) and a != (6, 8) for a, b in zip(st, st[1:]))
        seen = [s for s, _ in st]
        stop = re.search(r'^.*(?:\bSTOP\b|unimplemented|SIGSEGV|panic|Assertion).*$', t, re.M)
        # A row the queue killed (no flow change for STALL s) or RN_SECS ended has no results and no way back: NO_RESULTS; the log's tail says which.
        state = 'CRASH' if stop else 'NO_RESULTS' if res < len(row['stages']) else 'OK' if 7 in seen and 3 in seen[seen.index(7):] else 'NO_RETURN'
        recs = [r.rsplit(':', 5) for b in re.findall(r'^AILOG \d+ draft \d+ (.*)$', t, re.M) for r in b.split()]
        recs = [r for r in recs if len(r) == 6]
        me = [r[4] for r in recs if r[1] == '1']
        out.append(dict(ev=row['id'].split('.')[1], kind=row['kind'], mode=row['type'], stages=len(row['stages']), results=res, state=state,
                        rivals=len({r[0] for r in recs if r[1] != '1'}), me_rank=me[-1] if me else '', rival_wall=len(re.findall(r'^AIHIT .*kind 2 .* wall', t, re.M)),
                        me_wall=len(re.findall(r'^AIHIT .*kind 1 .* wall', t, re.M)), polymax=max(map(int, re.findall(r'polymax (\d+)', t)), default=0),
                        movies='+'.join(sorted({m.upper() for m in re.findall(r'MOVIES\\(\w+)\.mad', t)} - {'E3_TITLE'})), stop=stop[0][:100] if stop else ''))
    if not out: sys.exit('table: no runs/cjump_* logs, census/ghost_career.tsv left as it is')
    with open(f'{R}/census/ghost_career.tsv', 'w') as f:
        f.write('\t'.join(cols) + '\n')
        for o in out: f.write('\t'.join(str(o[c]) for c in cols) + '\n')
    for o in out:
        if o['state'] != 'OK': print(o['ev'], o['mode'], o['state'], o['results'], '/', o['stages'], o['stop'])
    print(len(out), 'rows', {s: sum(o['state'] == s for o in out) for s in {o['state'] for o in out}}, 'movies', sorted({m for o in out for m in o['movies'].split('+') if m}))
elif CMD == 'collect':
    runs = [r for r in sorted(os.listdir(f'{R}/runs')) if any(os.path.exists(f'{R}/runs/{r}/{f}') for f in ('log.txt', 'flow.txt'))]
    for r in runs: webp(f'{R}/runs/{r}')
    rows = {f'{r}#{i}' if i else r: v for r in runs for i, v in enumerate(rows_of(f'{R}/runs/{r}')) if not i or v['reached']['start']}
    rows.update(game_rows())
    json.dump(rows, open(f'{R}/census/completion.json', 'w'), indent=1)
    for r, v in rows.items(): print(f'{r:10s}', ' '.join(k for k, x in v['reached'].items() if x) or '-', '|', v.get('end', v.get('why')), '|', v.get('stop', '')[:80])
