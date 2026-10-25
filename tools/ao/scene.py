# Lighting inputs of each baked run, all read from the game files (no value is made up), -> one JSON for bake.py gi/probes.
# Track: the TRACKB whose route nodes (chunk 0x34149: 20-byte rows x, y, flags, -1, distance; head 0x34148 holds the
# length) fall on the run's world mesh. Sun: GLOBALB 0x34201 track row +0x70 = key of a 0x34202 record (0x110 bytes);
# SetCurrentSunInfo 0x546310 takes words 8..10 as the sun position when word 0 == 2, and sets the sun's first layer
# colour 255,200,100 (0x730078). Fog: the type-1 volumes of the TRACKB chunk 0x34250 (0xe8-byte rows: word 0x13 colour
# R,G,B, 0x16..0x18 position, 0x19 outer radius, 0x1a alpha; CalculateDistantFogInfo 0x588f40); the widest is the
# track-wide haze. usage: scene.py OUT.json MESH.npz...   (uses game/ and ref/tools/jdlz.py)
import glob, json, os, struct, sys, numpy as np
R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, f'{R}/ref/tools'); from jdlz import jdlz_decompress

def load(p):
    d = open(p, 'rb').read(); return jdlz_decompress(d) if d[:4] == b'JDLZ' else d
def chunks(d, o=0, e=None, out=None):
    out = {} if out is None else out; e = len(d) if e is None else e
    while o + 8 <= e:
        i, s = struct.unpack_from('<II', d, o)
        if o + 8 + s > e: break
        out.setdefault(i, []).append((o + 8, s))
        if i >> 28 == 8: chunks(d, o + 8, o + 8 + s, out)
        o += 8 + s
    return out

gb = load(f'{R}/game/Global/GLOBALB.BUN'); c = chunks(gb)
(b, s), = c[0x34201]
key = {struct.unpack_from('<h', gb, b + k * 0xfc + 0x6c)[0]: struct.unpack_from('<I', gb, b + k * 0xfc + 0x70)[0] for k in range(s // 0xfc)}
(b, s), = c[0x34202]; st = (b + 15) & ~15
sun = {}
for k in range((s - (st - b)) // 0x110):
    w = struct.unpack_from('<2I6I3f', gb, st + k * 0x110)
    if w[0] == 2: sun[w[1]] = w[8:11]
tracks = {}
for p in glob.glob(f'{R}/game/Tracks/TRACKB*.lzc'):
    tid = int(os.path.basename(p)[6:-4]); d = load(p); c = chunks(d)
    if 0x34149 not in c: continue
    (b, s), = c[0x34149][:1]
    route = [struct.unpack_from('<2f', d, b + 20 * k) + struct.unpack_from('<f', d, b + 20 * k + 16) for k in range(s // 20)]
    fog = []
    for b, s in c.get(0x34250, []):
        st = (b + 15) & ~15; n = struct.unpack_from('<I', d, st + 12)[0]
        for k in range(n):
            r = st + 0x10 + k * 0xe8; W = lambda i: struct.unpack_from('<f', d, r + 4 * i)[0]
            if struct.unpack_from('<I', d, r + 0x48)[0] == 1: fog.append(dict(rgb=list(d[r + 0x4c:r + 0x4f]), pos=[W(0x16), W(0x17), W(0x18)], r=W(0x19), alpha=W(0x1a)))
    tracks[tid] = dict(route=route, fog=max(fog, key=lambda v: v['r']) if fog else None)

out = {}
for m in sys.argv[2:]:
    P = np.load(m)['w.pos']; cells = set(map(tuple, np.floor(P[:, :2] / 8).astype(int)))
    def hit(t):
        return np.mean([any((int(np.floor(x / 8)) + i, int(np.floor(y / 8)) + j) in cells for i in (-1, 0, 1) for j in (-1, 0, 1))
                        for x, y, _ in tracks[t]['route']])
    score = sorted(((hit(t), t) for t in tracks), reverse=True)
    tid = score[0][1]; k = key.get(tid)
    run = os.path.basename(m)[:-4]
    out[run] = dict(track=tid, match=round(score[0][0], 3), next=[round(score[1][0], 3), score[1][1]], sun_key=k and f'{k:08x}',
                    sun_pos=list(sun[k]) if k in sun else 'UNKNOWN: no 0x34202 record with this key', sun_rgb=[255, 200, 100],
                    fog=tracks[tid]['fog'] or 'UNKNOWN: no type-1 volume in 0x34250', route=tracks[tid]['route'],
                    centre=P.mean(0).tolist())
    print(run, tid, out[run]['match'], out[run]['next'], out[run]['sun_pos'], tracks[tid]['fog']['rgb'] if tracks[tid]['fog'] else None, len(tracks[tid]['route']))
json.dump(out, open(sys.argv[1], 'w'))
