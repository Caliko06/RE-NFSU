"""PNG -> shipped WebP for the remaster packs: level 0 capped at 1024, quality 90, exact=True.
The RGB under alpha 0 must survive: the game uses alpha as a separate channel on some textures (front-end floor ROAD*:
40% alpha 0, RGB drawn), which came out black (V 2026-10-23: RGB mean under alpha 0 44 in the PNG, 0.2 shipped). Two
steps zeroed it: Pillow's RGBA resize (premultiplied) and libwebp without exact=True. RGB and alpha are resized apart.
usage: ship_webp.py SRC_PNG_DIR OUT_DIR [KEYS.lst]   (KEYS.lst: <key>.png lines; default: every PNG in SRC)"""
import os, sys
from PIL import Image
src, out = sys.argv[1], sys.argv[2]
names = [l.strip() for l in open(sys.argv[3]) if l.strip()] if len(sys.argv) > 3 else sorted(os.listdir(src))
os.makedirs(out, exist_ok=True)
n = 0
for f in names:
    if not f.endswith('.png') or not os.path.exists(os.path.join(src, f)):
        continue
    im = Image.open(os.path.join(src, f)).convert('RGBA')
    s = min(1, 1024 / max(im.size))
    if s < 1:
        # RGB and alpha apart: Pillow resizes RGBA premultiplied, which zeroes the RGB under alpha 0 (see ship_webp.py)
        size = (round(im.width * s), round(im.height * s))
        im = Image.merge('RGBA', (*im.convert('RGB').resize(size, Image.LANCZOS).split(), im.getchannel('A').resize(size, Image.LANCZOS)))
    im.save(os.path.join(out, f[:-4] + '.webp'), 'WEBP', quality=90, exact=True)
    n += 1
print(n, 'webp ->', out)
