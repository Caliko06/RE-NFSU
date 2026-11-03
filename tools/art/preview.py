#!/usr/bin/env python3
"""Offline look at pool liveries on the real car meshes (LOD A stock solids), no game: preview.py OUT.png CAR:n:RRGGBB ...  Left and right 3/4 view per car."""
import sys, numpy as np
from PIL import Image, ImageDraw
sys.path.insert(0, "tools/art")
import carmesh
def tris(car):
    s1 = carmesh.bh(car + "_SKIN1"); out = []
    for s in carmesh.solids(car):
        if "_KIT00_" not in s["name"] or not s["name"].endswith("_A"): continue
        for gt, gm, first, cnt in s["groups"]:
            I = s["idx"][first:first + cnt].reshape(-1, 3); V = s["V"]
            sk = s["tex"][gt] == s1 if gt < len(s["tex"]) else False
            out.append((V["p"][I].astype(float), V["uv"][I].astype(float), sk))
    return out
def render(T, skin, side, W=480, H=270):
    eye = np.array([3.2, 5.0 * side, 1.6]); tgt = np.array([0, 0, .45]); f = tgt - eye; f /= np.linalg.norm(f)
    r = np.cross(f, [0, 0, 1.]); r /= np.linalg.norm(r); u = np.cross(r, f)
    col = np.full((H, W, 3), (70, 72, 84), np.uint8); zb = np.full((H, W), 1e9); L = np.array([.3, .3 * side, .9]); L /= np.linalg.norm(L)
    for P, UV, sk in T:
        rel = P - eye; x = rel @ r; y = rel @ u; z = rel @ f
        sx = W / 2 + x / z * 700; sy = H / 2 - y / z * 700
        for k in range(len(P)):
            a, b, c = np.c_[sx[k], sy[k]]; x0, x1 = int(max(0, min(a[0], b[0], c[0]))), int(min(W - 1, max(a[0], b[0], c[0]) + 1)); y0, y1 = int(max(0, min(a[1], b[1], c[1]))), int(min(H - 1, max(a[1], b[1], c[1]) + 1))
            if x1 < x0 or y1 < y0: continue
            d = (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0])
            if abs(d) < 1e-6: continue
            X, Y = np.meshgrid(np.arange(x0, x1 + 1), np.arange(y0, y1 + 1))
            w1 = ((X - a[0]) * (c[1] - a[1]) - (Y - a[1]) * (c[0] - a[0])) / d; w2 = ((b[0] - a[0]) * (Y - a[1]) - (b[1] - a[1]) * (X - a[0])) / d; w0 = 1 - w1 - w2
            m = (w0 >= 0) & (w1 >= 0) & (w2 >= 0)
            if not m.any(): continue
            zz = w0 * z[k, 0] + w1 * z[k, 1] + w2 * z[k, 2]; m &= zz < zb[y0:y1 + 1, x0:x1 + 1]
            n = np.cross(P[k, 1] - P[k, 0], P[k, 2] - P[k, 0]); n /= np.linalg.norm(n) + 1e-9; sh = .45 + .55 * abs(n @ L)
            if sk:
                uu = np.clip((w0 * UV[k, 0, 0] + w1 * UV[k, 1, 0] + w2 * UV[k, 2, 0]) * 1023, 0, 1023).astype(int); vv = np.clip((w0 * UV[k, 0, 1] + w1 * UV[k, 1, 1] + w2 * UV[k, 2, 1]) * 1023, 0, 1023).astype(int)
                px = skin[vv, uu] * sh
            else: px = np.full(X.shape + (3,), 45.) * sh
            col[y0:y1 + 1, x0:x1 + 1][m] = px[m].astype(np.uint8); zb[y0:y1 + 1, x0:x1 + 1][m] = zz[m]
    return Image.fromarray(col)
if __name__ == "__main__":
    out, items = sys.argv[1], sys.argv[2:]
    sheet = Image.new("RGB", (960, 270 * len(items))); d = ImageDraw.Draw(sheet)
    for i, it in enumerate(items):
        car, n, rgb = it.split(":")
        paint = Image.new("RGBA", (1024, 1024), tuple(bytes.fromhex(rgb)) + (255,)); paint.alpha_composite(Image.open(f"web/remaster/liv/{car}/{n}.webp").convert("RGBA"))
        skin = np.asarray(paint.convert("RGB"), float); T = tris(car)
        for j, side in enumerate((1, -1)): sheet.paste(render(T, skin, side), (j * 480, i * 270))
        d.text((6, i * 270 + 4), f"{car} #{n}", fill=(255, 255, 255))
    sheet.save(out)
