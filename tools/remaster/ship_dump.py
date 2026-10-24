"""Ship the upscaled runtime-dump textures (texdump.py -> pod world_pod.sh -> world_out): cap 1024, WebP q90 to
web/remaster/dump/<key>.webp. Keys in DEFAULT.lst (found in Global/, FrontEnd/, Languages/: not world art) go to index.tsv
(the default pack); the rest (track textures and those of unknown container) to index_world.tsv (?worldhd=1).
usage: ship_dump.py world_out DUMP.tsv DEFAULT.lst"""
import os, sys
from PIL import Image
src, tsv, deflst = sys.argv[1:4]
web = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))), 'web', 'remaster')
os.makedirs(os.path.join(web, 'dump'), exist_ok=True)
meta = {l.split('\t')[0]: l.rstrip('\n').split('\t') for l in open(tsv)}
default = {l.strip() for l in open(deflst) if l.strip()}
have = {f: {l.split('\t')[0] for l in open(os.path.join(web, f)) if l.strip()} for f in ('index.tsv', 'index_world.tsv')}
add = {'index.tsv': [], 'index_world.tsv': []}
for f in sorted(os.listdir(src)):
    key = f[:-4]
    if not f.endswith('.png') or key not in meta:
        continue
    im = Image.open(os.path.join(src, f)).convert('RGBA')
    s = min(1, 1024 / max(im.size))
    if s < 1:
        # RGB and alpha apart: Pillow resizes RGBA premultiplied, which zeroes the RGB under alpha 0 (see ship_webp.py)
        size = (round(im.width * s), round(im.height * s))
        im = Image.merge('RGBA', (*im.convert('RGB').resize(size, Image.LANCZOS).split(), im.getchannel('A').resize(size, Image.LANCZOS)))
    im.save(os.path.join(web, 'dump', key + '.webp'), 'WEBP', quality=90, exact=True)   # exact: see ship_webp.py
    idx = 'index.tsv' if key in default else 'index_world.tsv'
    if key not in have[idx]:
        m = meta[key]
        add[idx].append(f'{key}\tdump/{key}.webp\t{m[2]}\t{m[3]}\t{m[4]}\tDUMP\n')
for idx, rows in add.items():
    open(os.path.join(web, idx), 'a').writelines(rows)
    print(idx, '+', len(rows))
