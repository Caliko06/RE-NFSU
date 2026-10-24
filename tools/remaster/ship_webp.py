"""PNG -> shipped WebP for the remaster packs: level 0 capped at 1024, quality 90, exact=True.
exact matters: without it libwebp zeroes the RGB of alpha-0 texels, and the game uses alpha as a separate channel on some
textures (front-end floor ROAD*: 40% alpha 0, RGB drawn), which came out black (V 2026-10-23: RGB mean under alpha 0
44 in the PNG, 4 in the WebP).
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
        im = im.resize((round(im.width * s), round(im.height * s)), Image.LANCZOS)
    im.save(os.path.join(out, f[:-4] + '.webp'), 'WEBP', quality=90, exact=True)
    n += 1
print(n, 'webp ->', out)
