"""Remaster input from the textures the game really uploads: save/texdump/<key>.bin (host/d3d9.c RN_TEXDUMP=1: w, h, D3DFORMAT,
pitch as 4 u32, then the locked level-0 bytes). Writes OUT/<key>.png (RGBA) for every DXT1/3/5 texture with sides >= 32 that
is not yet in web/remaster/index.tsv or index_world.tsv, and OUT.tsv (key, key, w, h, fmt, DUMP). The key is the one the
layer hashes, so no container parser has to agree with it (859 of 1963 race keys were not found by census_world.py).
usage: texdump.py save/texdump OUT"""
import os, struct, sys
from PIL import Image
here = os.path.dirname(os.path.abspath(__file__))
dsrc = open(os.path.join(here, 'decode_all.py')).read().split("want={}")[0].replace(
    "src=open('/Users/angeldamian/RE-NFSU/tools/remaster/index.py').read().split('game, pngs, out')[0]\nns={}; exec(src,ns)\n", "")
dn = {}; exec(dsrc, dn)
FMT = {0x31545844: 0x22, 0x33545844: 0x24, 0x35545844: 0x26}     # D3DFMT_DXT1/3/5 -> the TPK codes decode() takes
src, out = sys.argv[1], sys.argv[2]
web = os.path.join(os.path.dirname(os.path.dirname(here)), 'web', 'remaster')
have = {l.split('\t')[0] for f in ('index.tsv', 'index_world.tsv') for l in open(os.path.join(web, f)) if l.strip()}
os.makedirs(out, exist_ok=True)
rows = []
for f in sorted(os.listdir(src)):
    key = f[:-4]
    if not f.endswith('.bin') or key in have:
        continue
    d = open(os.path.join(src, f), 'rb').read()
    w, h, fmt, pitch = struct.unpack_from('<4I', d)
    if fmt not in FMT or w < 32 or h < 32:
        continue
    bs = 8 if fmt == 0x31545844 else 16
    row = max(1, w // 4) * bs
    raw = b''.join(d[16 + y * pitch:16 + y * pitch + row] for y in range(max(1, h // 4)))
    Image.fromarray(dn['decode'](raw, w, h, FMT[fmt]), 'RGBA').save(os.path.join(out, key + '.png'))
    rows.append(f'{key}\t{key}\t{w}\t{h}\t{FMT[fmt]:#x}\tDUMP\n')
open(out + '.tsv', 'w').writelines(rows)
print(len(rows), 'new textures ->', out)
