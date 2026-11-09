#!/usr/bin/env python3
"""Run shots live 10 min (OWNER 2026-11-09, as mafia-wasm tools/shots_gc.py): no bloat, keepers stored apart.
Kept in place: every shot of a run whose log.txt moved in the last 30 min, and anything git tracks (web/plan/shots).
Kept apart: each finished run's last shot -> census/shots/<run>__last.webp (small) before its PNGs go.
usage: shots_gc.py [loop]   (loop = every 10 min, for a batch)"""
import glob, os, sys, time
R = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
mt = lambda p: os.path.getmtime(p) if os.path.exists(p) else 0
def gc():
    from PIL import Image
    os.makedirs(f'{R}/census/shots', exist_ok=True)
    n = k = 0
    # Slice worktrees clone build/ (APFS copy-on-write), so their copies of runs/ hold the same blocks: purge those too.
    for d in glob.glob(f'{R}/runs/*/') + glob.glob(f'{R}-wt/*/build/pod/runs/*/'):
        pngs = sorted(glob.glob(d + 'shot.png*.png'), key=mt)
        # career0/prologue frames are the game.movies proof (completion.py movie() reads the kept FMV frames): never purged.
        if not pngs or time.time() - mt(d + 'log.txt') < 1800 or os.path.basename(d.rstrip('/')).startswith(('career0', 'prologue')): continue
        dst = f"{R}/census/shots/{os.path.basename(d.rstrip('/'))}__last.webp"
        if mt(dst) < mt(pngs[-1]): Image.open(pngs[-1]).save(dst, quality=70); k += 1
        for p in pngs + [d + 'shot.png']:
            if os.path.exists(p) and time.time() - mt(p) > 600: os.remove(p); n += 1
    print(f'{time.strftime("%T")} shots_gc: {n} shots deleted, {k} keepers in census/shots/', flush=True)
gc()
while sys.argv[1:] == ['loop']: time.sleep(600); gc()
