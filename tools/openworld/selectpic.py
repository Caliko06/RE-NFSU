#!/usr/bin/env python3
"""selectpic.py: the two SELECT LOCATION pictures of the WORLD row (docs/openworld/re_select_picture.md 3b), 512 x 512 RGBA:
TRACK_1010_SPLINE (the route outline: white line with a soft halo on transparent, as TRACK_1001_SPLINE) and TRACK_1010 (the photo
behind it: the city's street network in the dark teal of the shipped maps). Both use one transform, the city's bounding box
fitted to the square, north up (v = Y0 - y as tools/openworld/worldmap.py). The outline is the closed tour of TRACKB1010 (its
TrackPath 0x34149: nodes of 20 bytes, x y first), the photo's streets are every road section of the 16 street tracks.
usage: python3 tools/openworld/selectpic.py  -> build/openworld/select_spline.png, select_photo.png"""
import os, struct, sys
import numpy as np
from PIL import Image, ImageDraw, ImageFilter
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import worldmap as W  # noqa: E402  (puts ref/tools/ug1-tracks on the path, loads lib)
lib = W.lib
N, SS, MARGIN = 512, 4, 40
GROUND, ROAD = W.GROUND, W.ROAD


def tour_points():
    d = lib.load(os.path.join(W.OUT, 'TRACKB1010.lzc'))
    (b, s), = lib.find(d, 0x34149)
    return [struct.unpack_from('<2f', d, b + 20 * i) for i in range(s // 20)]


def fit(allpts):
    xs, ys = [p[0] for p in allpts], [p[1] for p in allpts]
    x0, x1, y0, y1 = min(xs), max(xs), min(ys), max(ys)
    k = (N - 2 * MARGIN) / max(x1 - x0, y1 - y0)
    ox, oy = (N - (x1 - x0) * k) / 2, (N - (y1 - y0) * k) / 2
    return lambda x, y: ((x - x0) * k + ox, (y1 - y) * k + oy), k


def render():
    secs = W.sections()
    tour = tour_points()
    tr, k = fit([(p[0], p[1]) for s in secs for p in s])
    big = N * SS
    photo = Image.new('RGB', (big, big), GROUND)
    dr = ImageDraw.Draw(photo)
    for sec in secs:
        for a, b in zip(sec, sec[1:]):
            w = max((a[2] + b[2]) / 2, 12) * 1.2 * k * SS
            p, q = [v * SS for v in tr(a[0], a[1])], [v * SS for v in tr(b[0], b[1])]
            dr.line([tuple(p), tuple(q)], fill=ROAD, width=max(1, round(w)))
            r = w / 2
            dr.ellipse([q[0] - r, q[1] - r, q[0] + r, q[1] + r], fill=ROAD)
    photo = photo.resize((N, N), Image.LANCZOS)
    line = Image.new('L', (big, big), 0)
    ld = ImageDraw.Draw(line)
    pts = [tuple(v * SS for v in tr(x, y)) for x, y in tour]
    ld.line(pts + pts[:1], fill=255, width=3 * SS, joint='curve')
    core = line.resize((N, N), Image.LANCZOS)
    halo = core.filter(ImageFilter.GaussianBlur(3)).point(lambda v: min(255, v * 2))
    alpha = np.maximum(np.array(core), (np.array(halo) * 0.55).astype(np.uint8))
    spl = np.zeros((N, N, 4), np.uint8)
    spl[..., :3] = 255
    spl[..., 3] = alpha
    return spl, np.array(photo.convert('RGBA'))


def main():
    spl, photo = render()
    Image.fromarray(spl, 'RGBA').save(os.path.join(W.OUT, 'select_spline.png'))
    Image.fromarray(photo, 'RGBA').save(os.path.join(W.OUT, 'select_photo.png'))
    print('select_spline.png, select_photo.png', N)


if __name__ == '__main__':
    main()
