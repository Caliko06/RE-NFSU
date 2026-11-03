#!/usr/bin/env python3
"""Pool stickers: web/remaster/liv/<CAR>/<n>.webp, RGBA in skin UV (1024), blended over the HD skin by web/gpu.js livery().
The design itself is the game's own vinyl in the rival's colours (host/rivals.c build). This adds only Paola's invented small stickers
(build/art/raw/stickers*.png, tools/art/paola.py) on the doors and quarters. No sheets: no files, and the game draws nothing extra.
Each side is drawn in car metres (L along the car, front +; H up), viewed with the front on the right, and mapped with its affine from
build/art/skinmap.json (tools/art/skinmap.py). Stickers are flipped on the left side's canvas so they read right."""
import json, os, random, sys
from PIL import Image, ImageDraw, ImageChops
PX = 220                                      # canvas px per metre
LMIN, LMAX, HMIN, HMAX = -2.4, 2.4, 0.0, 0.9
W, H = int((LMAX - LMIN) * PX), int((HMAX - HMIN) * PX)
def cx(L): return (L - LMIN) * PX
def cy(Hh): return (HMAX - Hh) * PX

def key(im):
    im = im.convert("RGBA")
    if im.getextrema()[3][0] == 255:          # no alpha came back: key out the magenta
        r, g, b, _ = im.split()
        d = ImageChops.add(ImageChops.add(ImageChops.difference(r, Image.new("L", r.size, 255)), g), ImageChops.difference(b, Image.new("L", r.size, 255)))
        im.putalpha(d.point(lambda v: 0 if v < 60 else min(255, (v - 60) * 4)))
    return im

def cells():
    out = []
    for name in ("stickers1", "stickers2"):
        p = f"build/art/raw/{name}.png"
        if not os.path.exists(p): continue
        im = key(Image.open(p)); w, h = im.size
        for j in range(4):
            for i in range(4):
                c = im.crop((i * w // 4, j * h // 4, (i + 1) * w // 4, (j + 1) * h // 4))
                b = c.getchannel("A").point(lambda v: 255 if v > 40 else 0).getbbox()
                if b: out.append(c.crop(b))
    return out

def side_to_tex(tex, canvas, s):
    u, v = s["affine"]["u"], s["affine"]["v"]
    # canvas (x, y): L = x/PX + LMIN, H = HMAX - y/PX. Forward: texture = M (x, y) + t. PIL wants the inverse.
    a, b = u[0] / PX, -u[1] / PX; c = u[0] * LMIN + u[1] * HMAX + u[2]
    d, e = v[0] / PX, -v[1] / PX; f = v[0] * LMIN + v[1] * HMAX + v[2]
    det = a * e - b * d
    inv = (e / det, -b / det, (b * f - e * c) / det, -d / det, a / det, (d * c - a * f) / det)
    lay = canvas.transform(tex.size, Image.AFFINE, inv, Image.BICUBIC)
    x0, y0, x1, y1 = s["uv_bbox_px"]
    m = Image.new("L", tex.size, 0); ImageDraw.Draw(m).rectangle((x0 - 6, y0 - 6, x1 + 6, y1 + 6), fill=255)
    lay.putalpha(ImageChops.multiply(lay.getchannel("A"), m))
    tex.alpha_composite(lay)

def stickers(car, m, n, art):
    tex = Image.new("RGBA", (1024, 1024), (0, 0, 0, 0))
    door = m["right"]["door_centre_car"]; rng = random.Random(f"{car}{n}st")
    picks = [(rng.choice(art), L, Hh, h) for L, Hh, h in [(door["L"] + .35, .24, .06), (1.05, .4, .05), (-1.3, .46, .05)]]
    for side in ("left", "right"):
        s = m.get(side)
        if not s: continue
        c = Image.new("RGBA", (W, H), (0, 0, 0, 0))
        for st, L, Hh, h in picks:
            st = st.resize((max(1, st.width * int(h * PX) // st.height), int(h * PX)), Image.LANCZOS)
            if side == "left": st = st.transpose(Image.FLIP_LEFT_RIGHT)
            c.alpha_composite(st, (max(0, int(cx(L) - st.width / 2)), max(0, int(cy(Hh) - st.height / 2))))
        side_to_tex(tex, c, s)
    return tex

if __name__ == "__main__":
    j = json.load(open("build/art/skinmap.json")); total = 0; art = cells()
    if not art: sys.exit("no sticker sheets in build/art/raw")
    cars = sys.argv[1:] or [k for k in j if k != "_meta"]
    for car in cars:
        os.makedirs(f"web/remaster/liv/{car}", exist_ok=True)
        for n in range(12):
            p = f"web/remaster/liv/{car}/{n}.webp"
            stickers(car, j[car], n, art).save(p, "WEBP", quality=85, method=4, exact=False)
            total += os.path.getsize(p)
    print(len(cars), "cars,", total // 1024, "KB")
