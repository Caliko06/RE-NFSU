"""survey.py: one row per MW section (L2RA.BUN 0x34110) with its solid names, district codes and heights; top view PNG.
usage: survey.py -> runs/rockport/out/sections.json, runs/rockport/out/topview_all.png"""
import collections, json, os, re, struct, sys
sys.path.insert(0, os.path.dirname(__file__))
from bun import *
OUT = os.path.join(NFSU, 'runs', 'rockport', 'out')


def solid_names(d, a, b):
    out = []
    for dep, i, p, s in tree(d, a, b):
        if i == 0x134011:
            q = skip11(d, p, s)
            h, = struct.unpack_from('<I', d, q + 0x10)
            mn = struct.unpack_from('<3f', d, q + 0x20); mx = struct.unpack_from('<3f', d, q + 0x30)
            name = d[q + 0xa0:p + s].split(b'\0')[0].decode('latin1')
            out.append((name, h, mn, mx))
    return out


def main():
    rows = mw_section_table()
    d = open_map(os.path.join(MW_TRACKS, 'STREAML2RA.BUN'))
    res = []
    for r in rows:
        if not r['size']:
            continue
        sol = solid_names(d, r['off'], r['off'] + r['size'])
        codes = collections.Counter()
        for n, h, mn, mx in sol:
            m = re.match(r'[A-Z0-9]+_([A-Z]{2})_', n)
            if m: codes[m.group(1)] += 1
        tall = max([mx[2] - mn[2] for n, h, mn, mx in sol if n.startswith(('XB', 'BLD', 'BUI'))] or [0])
        zt = max([mx[2] for n, h, mn, mx in sol] or [0])
        res.append(dict(name=r['name'], id=r['id'], x=r['x'], y=r['y'], r=r['r'], size=r['size'], solids=len(sol),
                        codes=codes.most_common(4), zmax=zt, prefixes=collections.Counter(n.split('_')[0] for n, *_ in sol).most_common(5)))
    json.dump(res, open(os.path.join(OUT, 'sections.json'), 'w'), indent=0)
    print(len(res), 'sections')
    from PIL import Image, ImageDraw
    xs = [s for s in res if s['r'] and s['r'] < 2000]
    x0, x1 = min(s['x'] - s['r'] for s in xs), max(s['x'] + s['r'] for s in xs)
    y0, y1 = min(s['y'] - s['r'] for s in xs), max(s['y'] + s['r'] for s in xs)
    k = 1600 / max(x1 - x0, y1 - y0)
    im = Image.new('RGB', (int((x1 - x0) * k) + 20, int((y1 - y0) * k) + 20), 'white'); g = ImageDraw.Draw(im)
    pal = {}
    cols = [(230, 25, 75), (60, 180, 75), (0, 130, 200), (245, 130, 48), (145, 30, 180), (70, 240, 240), (240, 50, 230), (128, 128, 0), (0, 128, 128), (170, 110, 40)]
    for s in xs:
        c = s['codes'][0][0] if s['codes'] else '--'
        col = pal.setdefault(c, cols[len(pal) % len(cols)])
        X, Y = 10 + (s['x'] - x0) * k, 10 + (y1 - s['y']) * k
        R = s['r'] * k
        g.ellipse((X - R, Y - R, X + R, Y + R), outline=col)
        g.text((X - 8, Y - 5), s['name'], fill=col)
    for j, (c, col) in enumerate(pal.items()):
        g.text((10, 10 + 12 * j), c, fill=col)
    im.save(os.path.join(OUT, 'topview_all.png'))
    print('frame x %.0f..%.0f y %.0f..%.0f' % (x0, x1, y0, y1), pal.keys())


if __name__ == '__main__':
    main()
