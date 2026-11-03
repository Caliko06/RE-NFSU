#!/usr/bin/env python3
"""Pool liveries: web/remaster/liv/<CAR>/<n>.webp, RGBA in skin UV (1024), blended over the HD skin by web/gpu.js livery().
Each side is drawn in car metres (L along the car, front +; H up), viewed with the front on the right, and mapped with its affine from
build/art/skinmap.json (tools/art/skinmap.py). So a graphic points at the front on both sides and text is flipped on the left side's canvas to read right.
The base is the game's own vinyl art (Cars/<CAR>/VINYLS.BIN: tribals, dragons, sponsor wordmarks, already in skin UV), recoloured and layered more than a stock build, so it reads as Underground 2003.
Paola's sheets in build/art/raw (tools/art/paola.py) add new graphics and invented stickers when they exist. n: 0..3 clean, 4..7 show, 8..11 street (host/rivals.c livery_of)."""
import json, os, random, re, sys
import numpy as np
sys.path[:0] = ["tools/re"]
import tpk
from PIL import Image, ImageDraw, ImageFont, ImageChops
FONTS = "/System/Library/Fonts/Supplemental/"
PX = 220                                      # canvas px per metre
LMIN, LMAX, HMIN, HMAX = -2.4, 2.4, 0.0, 0.9
W, H = int((LMAX - LMIN) * PX), int((HMAX - HMIN) * PX)
def cx(L): return (L - LMIN) * PX
def cy(Hh): return (HMAX - Hh) * PX
PAL = [[(240,240,235),(20,20,24)], [(230,40,30),(250,250,250)], [(15,110,235),(250,250,250)], [(255,190,0),(15,15,15)],
       [(0,220,210),(90,20,170)], [(255,60,160),(30,220,255)], [(130,240,20),(10,10,10)], [(255,110,0),(40,40,48)],
       [(245,245,245),(230,30,60)], [(30,30,34),(255,200,0)], [(120,60,255),(0,240,180)], [(240,240,240),(0,130,255)]]

def key(im):
    im = im.convert("RGBA")
    if im.getextrema()[3][0] == 255:          # no alpha came back: key out the magenta
        r, g, b, _ = im.split()
        d = ImageChops.add(ImageChops.add(ImageChops.difference(r, Image.new("L", r.size, 255)), g), ImageChops.difference(b, Image.new("L", r.size, 255)))
        im.putalpha(d.point(lambda v: 0 if v < 60 else min(255, (v - 60) * 4)))
    return im
SHEETS = {}
def sheet(name, cols, rows):
    if name not in SHEETS:
        p = f"build/art/raw/{name}.png"; cells = []
        if os.path.exists(p):
            im = key(Image.open(p)); w, h = im.size
            for j in range(rows):
                for i in range(cols):
                    c = im.crop((i * w // cols, j * h // rows, (i + 1) * w // cols, (j + 1) * h // rows))
                    b = c.getchannel("A").point(lambda v: 255 if v > 40 else 0).getbbox()
                    if b: cells.append(c.crop(b))
        SHEETS[name] = cells
    return SHEETS[name]

def sticker(rng, h_m):
    cells = sheet("stickers1", 4, 4) + sheet("stickers2", 4, 4)
    if not cells: return None
    h = int(h_m * PX); c = rng.choice(cells)
    return c.resize((max(1, c.width * h // c.height), h), Image.LANCZOS)

def paola_graphic(n):
    """A side graphic from her sheets, in the canvas (front right), or None."""
    src = {0: "sides_stripes", 1: "sides_tribal", 2: "sides_slash"}[n // 4]
    rows = (sheet("sides_kanji", 1, 4) if n // 4 == 1 and n % 2 else []) or sheet(src, 1, 4)
    if not rows: return None
    g = Image.new("RGBA", (W, H), (0, 0, 0, 0))
    c = rows[n % len(rows)].transpose(Image.FLIP_LEFT_RIGHT).resize((int(3.9 * PX), int(0.5 * PX)), Image.LANCZOS)   # sheets point left, the canvas front is right
    g.alpha_composite(c, (int(cx(-1.95)), int(cy(0.68))))
    return g

class Vinyls:
    """The car's vinyl pack: name -> record; art() = RGBA at 1024 with its mask as alpha."""
    def __init__(self, car):
        self.d = open(f"game/Cars/{car}/VINYLS.BIN", "rb").read()
        self.pk = [p for p in tpk.packs(self.d) if p["recs"]][0]
        self.recs = {r["name"]: r for r in self.pk["recs"]}
        self.car = car
    def raw(self, r):
        pix, pal = tpk.pixels(self.d, self.pk, r); n = r["w"] * r["h"]
        p = np.frombuffer(pal, np.uint8).reshape(-1, 4)
        return p[np.frombuffer(pix[:n], np.uint8)].reshape(r["h"], r["w"], 4)
    def names(self):
        pre = self.car + "_"
        return [k for k in self.recs if k.startswith(pre) and "_MAS" not in k and not k.endswith("_MASK")]
    def mask(self, name):
        for m in ((name + "_MASK")[:23], name + "_MASK"):
            if m in self.recs: return self.raw(self.recs[m])[..., 2]
        return None
    def info(self, name):
        l = self.raw(self.recs[name])[..., :3]; m = self.mask(name)
        if m is None: return None
        on = m > 40
        if not on.any(): return None
        ys, xs = np.nonzero(on)
        px = l[on].astype(int); grey = float((abs(px[:, 0] - px[:, 2]) < 12).mean())
        return dict(name=name, cover=float(on.mean()), box=[int(xs.min()), int(ys.min()), int(xs.max()), int(ys.max())], grey=grey,
                    word=not re.fullmatch(self.car + r"_\d+", name) and "HOOD" not in name and "SPOILER" not in name, hood="HOOD" in name)
    def art(self, name, cols, ink):
        """Layer rule of the game (web/gpu.js skin): weight of R, G, B picks up to three colours; mask up to 128 fades, past it solid."""
        l = self.raw(self.recs[name])[..., :3].astype(float) / 255; m = self.mask(name).astype(float)
        grey = abs(l[..., 0] - l[..., 2]) < .05
        rgb = sum(l[..., k, None] * np.array(cols[k], float) for k in range(3))
        rgb = np.where(grey[..., None], l[..., 0, None] * np.array(ink, float), rgb)
        out = np.dstack([np.clip(rgb, 0, 255), np.clip(m / 128, 0, 1) * 255]).astype(np.uint8)
        return Image.fromarray(out, "RGBA").resize((1024, 1024), Image.LANCZOS)

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

def overlap(a, b):
    return not (a[2] < b[0] or b[2] < a[0] or a[3] < b[1] or b[3] < a[1])

def stats(car, v):
    p = f"build/art/vin_{car}.json"
    if os.path.exists(p): return json.load(open(p))
    rng = random.Random(car); names = v.names()
    nums = [k for k in names if re.fullmatch(car + r"_\d+", k)]
    pick = rng.sample(nums, min(160, len(nums))) + [k for k in names if k not in nums]
    rows = [i for i in map(v.info, pick) if i]
    json.dump(rows, open(p, "w")); return rows

def livery(car, m, n, v, rows):
    rng = random.Random(f"{car}{n}"); a, b = PAL[(n + hash_car(car)) % len(PAL)]; c3 = PAL[(n * 5 + 3 + hash_car(car)) % len(PAL)][0]
    tex = Image.new("RGBA", (1024, 1024), (0, 0, 0, 0))
    gfx = [r for r in rows if not r["word"] and not r["hood"]]; words = [r for r in rows if r["word"] and r["cover"] < .06]; hoods = [r for r in rows if r["hood"]]
    gfx.sort(key=lambda r: r["cover"]); q = len(gfx)
    # Underground's look: a tribal or slash that covers the side, more layers on show cars, a cluster of sponsors on the doors and quarters.
    if n // 4 == 0: layers = rng.sample(gfx[q // 4:q // 2], 1); nw = 2; hood = False
    elif n // 4 == 1: layers = [rng.choice(gfx[-q // 5:])] + rng.sample(gfx[q // 2:], 2); nw = 4; hood = True
    else: layers = rng.sample(gfx[q // 2:], 2); nw = 4; hood = n % 2 == 0
    for i, r in enumerate(layers): tex.alpha_composite(v.art(r["name"], [a, b, c3] if i % 2 == 0 else [b, c3, a], a))
    if hood and hoods: tex.alpha_composite(v.art(rng.choice(hoods)["name"], [a, b, c3], a))
    pg = paola_graphic(n)
    if pg:
        for side in ("left", "right"):
            if m.get(side): side_to_tex(tex, pg, m[side])
    used = []
    for r in rng.sample(words, len(words)):
        if nw and not any(overlap(r["box"], u) for u in used):
            tex.alpha_composite(v.art(r["name"], [b, a, c3], rng.choice([(245, 245, 245), (15, 15, 18), b]))); used.append(r["box"]); nw -= 1
    door = m["right"]["door_centre_car"]; r2 = random.Random(f"{car}{n}st")
    for side in ("left", "right"):
        s = m.get(side); c = Image.new("RGBA", (W, H), (0, 0, 0, 0)); any_st = False
        for L, Hh, h in [(door["L"] + .35, .24, .06), (1.05, .4, .05), (-1.3, .46, .05)]:
            st = sticker(r2, h)
            if st and s:
                if side == "left": st = st.transpose(Image.FLIP_LEFT_RIGHT)
                c.alpha_composite(st, (max(0, int(cx(L) - st.width / 2)), max(0, int(cy(Hh) - st.height / 2)))); any_st = True
        if any_st: side_to_tex(tex, c, s)
    return tex
def hash_car(car): return sum(car.encode())

if __name__ == "__main__":
    j = json.load(open("build/art/skinmap.json")); total = 0
    cars = sys.argv[1:] or [k for k in j if k != "_meta"]
    for car in cars:
        os.makedirs(f"web/remaster/liv/{car}", exist_ok=True)
        v = Vinyls(car); rows = stats(car, v)
        for n in range(12):
            p = f"web/remaster/liv/{car}/{n}.webp"
            livery(car, j[car], n, v, rows).save(p, "WEBP", quality=85, method=4, exact=False)
            total += os.path.getsize(p)
    print(len(cars), "cars,", total // 1024, "KB")
