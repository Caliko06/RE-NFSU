#!/usr/bin/env python3
"""selectpic.py: the two SELECT LOCATION pictures of the WORLD row (docs/openworld/re_select_picture.md 3b), 512 x 512 RGBA:
TRACK_1010_SPLINE (the route outline: white line with a soft halo on transparent, as TRACK_1001_SPLINE) and TRACK_1010 (the photo
behind it). The shipped photos TRACK_<id> (game/Global/DYNTEX.BIN, DXT1 512 x 512) are crops of ONE city map at one scale, KX px/m
across and KY px/m down (north up), each placed so its TRACK_<id>_SPLINE covers the track's TrackPath: the WORLD photo is their
mosaic (OWNER 2026-11-01: the flat street drawing looked "wonky"). Each crop's offset is fitted here from its spline and TrackPath;
crops blend by distance to their own edges and track. Both pictures use one transform: the city's bounding box (every road section
of the 16 street tracks) fitted to the square with the shipped KY/KX aspect, so WORLD reads at the scale of the other rows. The
outline is the closed tour of TRACKB1010 (its TrackPath 0x34149: nodes of 20 bytes, x y first).
usage: python3 tools/openworld/selectpic.py  -> build/openworld/select_spline.png, select_photo.png"""
import io, os, struct, sys
import numpy as np
from PIL import Image, ImageDraw, ImageFilter
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import worldmap as W  # noqa: E402  (puts ref/tools/ug1-tracks on the path, loads lib)
lib = W.lib
N, SS, MARGIN = 512, 4, 24
KX, KY = 0.192, 0.2395                  # px per metre of the shipped photos (fitted on 1001..1004: 86..97 % of the TrackPath on the spline)
CROPS = list(range(1001, 1009)) + [1207]  # the circuits and the one drag whose spline fits; the other drags are straight lines (no fix)


def tour_points():
    d = lib.load(os.path.join(W.OUT, 'TRACKB1010.lzc'))
    (b, s), = lib.find(d, 0x34149)
    return [struct.unpack_from('<2f', d, b + 20 * i) for i in range(s // 20)]


def shipped(tpk, name):
    """level 0 of a shipped DYNTEX texture as RGBA (JDLZ stream row, DXT1 for the photos, DXT3 for the splines)"""
    row = tpk.slots[tpk.index(name)]
    raw = lib.jdlz_decompress(tpk.d[row[1]:row[1] + row[2]])
    four = b'DXT1' if len(raw) == 0x2aaa0 else b'DXT3'
    n = 512 * 512 // (2 if four == b'DXT1' else 1)
    dds = struct.pack('<4sIIIIIII44xII4sIIIIIIIIII', b'DDS ', 124, 0x1007, 512, 512, 0, 0, 1, 32, 4, four, 0, 0, 0, 0, 0, 0x1000, 0, 0, 0, 0)
    return np.array(Image.open(io.BytesIO(dds + bytes(raw[:n]))).convert('RGBA'))


def trackpath(tid):
    d = lib.load(lib.trackb_path(lib.PC, tid))
    (b, s), = lib.find(d, 0x34149)
    return np.array([struct.unpack_from('<2f', d, b + 20 * i) for i in range(s // 20)])


def crop_offset(P, spline):
    """pixel = (x KX + ox, -y KY + oy): the offset that puts most TrackPath nodes on the spline (alpha > 160, grown 1 px)"""
    a = spline[..., 3]
    m = np.array(Image.fromarray(((a > 160) * 255).astype(np.uint8)).filter(ImageFilter.MaxFilter(3))) > 0
    ys, xs = np.nonzero(a > 160)
    ox0 = (xs.min() + xs.max()) / 2 - (P[:, 0].min() + P[:, 0].max()) / 2 * KX
    oy0 = (ys.min() + ys.max()) / 2 + (P[:, 1].min() + P[:, 1].max()) / 2 * KY

    def hit(ox, oy):
        u, v = (P[:, 0] * KX + ox).round().astype(int), (-P[:, 1] * KY + oy).round().astype(int)
        ok = (u >= 0) & (u < 512) & (v >= 0) & (v < 512)
        return m[v[ok], u[ok]].sum()
    return max(((hit(ox0 + dx, oy0 + dy), ox0 + dx, oy0 + dy) for dx in range(-30, 31) for dy in range(-30, 31)))[1:]


def fit(allpts):
    xs, ys = [p[0] for p in allpts], [p[1] for p in allpts]
    x0, x1, y0, y1 = min(xs), max(xs), min(ys), max(ys)
    r = KY / KX
    k = (N - 2 * MARGIN) / max(x1 - x0, (y1 - y0) * r)
    ox, oy = (N - (x1 - x0) * k) / 2, (N - (y1 - y0) * k * r) / 2
    return (lambda x, y: ((x - x0) * k + ox, (y1 - y) * k * r + oy)), (x0, y1, k, r, ox, oy)


def mosaic(inv):
    """the WORLD photo: every crop resampled at the output pixels' world points, weighted by its distance to its own edges
    and to its track (the art is richest around the track it was cut for)"""
    from tpkwrite import Tpk
    x0, y1, k, r, ox, oy = inv
    t = Tpk(os.path.join(W.REPO, 'game', 'Global', 'DYNTEX.BIN'))
    u, v = np.meshgrid(np.arange(N) + 0.5, np.arange(N) + 0.5)
    X, Y = (u - ox) / k + x0, y1 - (v - oy) / (k * r)
    acc, wsum = np.zeros((N, N, 3)), np.zeros((N, N))
    for tid in CROPS:
        P = trackpath(tid)
        cx, cy = crop_offset(P, shipped(t, 'TRACK_%d_SPLINE' % tid))
        img = shipped(t, 'TRACK_%d' % tid)[..., :3].astype(float)
        pu, pv = X * KX + cx, -Y * KY + cy
        ok = (pu >= 0) & (pu < 511) & (pv >= 0) & (pv < 511)
        fu, fv = pu[ok], pv[ok]
        iu, iv = fu.astype(int), fv.astype(int)
        du, dv = (fu - iu)[:, None], (fv - iv)[:, None]
        px = (img[iv, iu] * (1 - du) * (1 - dv) + img[iv, iu + 1] * du * (1 - dv) + img[iv + 1, iu] * (1 - du) * dv + img[iv + 1, iu + 1] * du * dv)
        edge = np.minimum.reduce([fu, 511 - fu, fv, 511 - fv]) / 64.0
        tx, ty = P[:, 0].mean(), P[:, 1].mean()
        near = np.exp(-((X[ok] - tx) ** 2 + (Y[ok] - ty) ** 2) / (900.0 ** 2))
        w = np.minimum(edge, 1.0) ** 2 * (0.05 + near)
        acc[ok] += px * w[:, None]
        wsum[ok] += w
    out = acc / np.maximum(wsum, 1e-9)[..., None]
    fill = np.median(out[wsum > 0], axis=0)
    out[wsum <= 0] = fill
    d = np.minimum.reduce([u, N - u, v, N - v]) / (N * 0.22)          # a soft dark frame hides the plain margins of the crops
    out *= (0.62 + 0.38 * np.minimum(d, 1.0) ** 0.8)[..., None]
    return np.dstack([out.clip(0, 255).astype(np.uint8), np.full((N, N), 255, np.uint8)])


def render():
    sys.path.insert(0, os.path.join(HERE, '..', 'remaster'))
    secs = W.sections()
    tour = tour_points()
    tr, inv = fit([(p[0], p[1]) for s in secs for p in s])
    big = N * SS
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
    return spl, mosaic(inv)


def main():
    spl, photo = render()
    Image.fromarray(spl, 'RGBA').save(os.path.join(W.OUT, 'select_spline.png'))
    Image.fromarray(photo, 'RGBA').save(os.path.join(W.OUT, 'select_photo.png'))
    print('select_spline.png, select_photo.png', N)


if __name__ == '__main__':
    main()
