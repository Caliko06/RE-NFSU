#!/usr/bin/env python3
"""The whole-game rows of the completion matrix (AGENTS.md acceptance): census/rows.json, read from game/ only.
Progress = OK rows / all rows. A row is OK when a census/completion.json run names it ("row") and reached back_to_menu.

Sources (V = read by this script or seen in the Ghidra decompile of pc/Speed.exe, build/pod/census/ghidra):
- Career events: FrontEnd/FrontB.lzc chunk 0x34A02 (in 0x80034A00), records of 0x14c B. Loader 0x5a0060 keeps
  record id < 0x100 in the table 0x733ff8. Word +4 = kind (0x568200, 0x5a2270 list split it), word +8 = race type,
  stages at +0x78 (s16 track, s8 laps, s8 direction), stage count +0x98.
- Tracks: Global/GLOBALB.BUN chunk 0x34201, rows of 0xfc B (0x442010): name +0, region +0x40, id +0x6c.
- Quick Race modes (V): [0x777cc8] ids 0 Circuit, 1 Sprint, 2 Lap Knockout, 3 Free Run, 5 Drag, 6 Drift. The list 0x4b70c0
  adds them in that screen order (ebx before each call 0x4b6fe0; names = Labels.bin hashes QUICKRACE_MODE_LAP_KO, _FREERUN).
  The tracks of mode m are the GLOBALB rows whose flags +0x74 have the bit 0x4ab470 tests for m. Mode 4 (circuit + sprint
  tracks) is not in that list: no row until a run shows a way to it (U).
usage: rows.py   (writes census/rows.json, prints the counts and the progress number)"""
import json, os, struct, sys
from collections import Counter
R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from jdlz import jdlz_decompress

def load(p):
    d = open(os.path.join(R, 'game', p), 'rb').read()
    return jdlz_decompress(d) if d[:4] == b'JDLZ' else d

def chunk(d, cid, o=0, e=None):
    e = len(d) if e is None else e
    while o + 8 <= e:
        i, s = struct.unpack_from('<II', d, o)
        if o + 8 + s > e: break
        if i == cid: return d[o + 8:o + 8 + s]
        if i >> 28 == 8:
            c = chunk(d, cid, o + 8, o + 8 + s)
            if c is not None: return c
        o += 8 + s

def cstr(b): return b.split(b'\0')[0].decode('latin1')

# Race type +8 names: same values as the PS2 switch 0x1e5990 and the track families below (I). 4 and 5: U on PC.
TYPE = {0: 'circuit', 1: 'drag', 2: 'sprint', 3: 'drift', 4: 'type4 (U)', 5: 'type5 (U)'}
# Quick Race: mode -> its [0x777cc8] id and the GLOBALB +0x74 bit 0x4ab470 tests for it (V).
QR = {'circuit': (0, 1), 'sprint': (1, 4), 'drag': (5, 2), 'drift': (6, 8), 'lapko': (2, 0x40), 'freerun': (3, 0x10)}

def main():
    gb = chunk(load('Global/GLOBALB.BUN'), 0x34201)
    tracks = {}
    for k in range(len(gb) // 0xfc):
        r = gb[k * 0xfc:(k + 1) * 0xfc]
        tracks[struct.unpack_from('<h', r, 0x6c)[0]] = dict(name=cstr(r[:0x20]), region=cstr(r[0x40:0x4c]),
                                                             modes=struct.unpack_from('<I', r, 0x74)[0])
    ev = chunk(load('FrontEnd/FrontB.lzc'), 0x34A02)
    rows = []
    for o in range(0, len(ev), 0x14c):
        rec = ev[o:o + 0x14c]
        eid, kind, typ = struct.unpack_from('<III', rec, 0)
        n = struct.unpack_from('<I', rec, 0x98)[0]
        st = [struct.unpack_from('<hbb', rec, 0x78 + 4 * i) for i in range(n)]
        rows.append(dict(id=f'career.{eid}', group='career', kind=kind, type=TYPE.get(typ, typ),
                         stages=[dict(track=t, name=tracks.get(t, {}).get('name', '?'), laps=l, direction=d) for t, l, d in st],
                         src=f'FrontB.lzc 0x34A02 +0x{o:x}'))
    for mode, (mid, bit) in QR.items():
        for t in sorted(tracks):
            if tracks[t]['modes'] & bit:
                rows.append(dict(id=f'qr.{mode}.{t}', group='quick_race', mode=mode, track=t, name=tracks[t]['name'],
                                 src=f'GLOBALB 0x34201 +0x74 & 0x{bit:x} (0x4ab470)'))
    # OWNER scope (AGENTS.md "Scope"), not in a game table: one row each.
    for k, what in [('profile', 'create a profile; the file lands in save/'),
                    ('garage', 'Garage: every part type can be fitted and is seen on the car (everything unlocked)'),
                    ('options', 'options change and persist in save/'),
                    ('save_reload', 'career: save, reload the page, continue at the same event'),
                    ('movies', 'the game movies play (MOVIES\\)')]:
        rows.append(dict(id=f'game.{k}', group='game', check=what, src='AGENTS.md Scope'))

    done = set()
    cpath = os.path.join(R, 'census', 'completion.json')
    if os.path.exists(cpath):
        for run in json.load(open(cpath)).values():
            if run.get('row') and run.get('reached', {}).get('back_to_menu'): done.add(run['row'])
    for r in rows: r['ok'] = r['id'] in done
    ok = sum(r['ok'] for r in rows)
    out = dict(note='Whole-game denominator. Made by tools/census/rows.py from game/; never edit by hand.',
               progress=f'{ok}/{len(rows)}', rows=rows)
    json.dump(out, open(os.path.join(R, 'census', 'rows.json'), 'w'), indent=1)
    print('rows', len(rows), dict(Counter(r['group'] for r in rows)))
    print('career kinds', dict(sorted(Counter(r['kind'] for r in rows if r['group'] == 'career').items())),
          'stages', sum(len(r['stages']) for r in rows if r['group'] == 'career'))
    print('progress', out['progress'])

if __name__ == '__main__': main()
