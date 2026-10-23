"""Decode every unique world texture (STREAML1R*.BUN) to OUT/<fnv64 of level 0>.png (RGBA) and write OUT.tsv:
hash, name(=hash), w, h, comp, source. The hash is the one web/gpu.js looks up at UnlockRect (index.py: FNV-1a 64 of the level-0 bytes).
usage: decode_world.py OUT game/TRACKS/STREAML1R?.BUN game/TRACKS/STREAML1R?_*.BUN"""
import os, sys
sys.path.insert(0, os.path.dirname(__file__))
import census_world as cw
from PIL import Image
dsrc = open(os.path.join(os.path.dirname(__file__), 'decode_all.py')).read().split("want={}")[0].replace("src=open('/Users/angeldamian/RE-NFSU/tools/remaster/index.py').read().split('game, pngs, out')[0]\nns={}; exec(src,ns)\n", "")
dn = {}; exec(dsrc, dn)
out = sys.argv[1]; os.makedirs(out, exist_ok=True)
seen = {}; rows = []
for f in sys.argv[2:]:
    d = open(f, 'rb').read()
    for b, e in cw.tpks(d, 0, len(d)):
        for key, name, w, h, comp, raw in cw.parse(d, b, e):
            if w < 4 or h < 4: continue
            hh = f'{cw.fnv64(raw):016x}'
            if hh in seen: continue
            seen[hh] = 1
            Image.fromarray(dn['decode'](raw, w, h, comp), 'RGBA').save(f'{out}/{hh}.png')
            rows.append(f'{hh}\t{hh}\t{w}\t{h}\t{comp:#x}\tWORLD\t{name}')
open(out + '.tsv', 'w').write('\n'.join(rows) + '\n')
print(len(rows), 'decoded ->', out)
