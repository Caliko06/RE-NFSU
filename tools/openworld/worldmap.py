#!/usr/bin/env python3
"""worldmap.py: the HUD minimap picture of the "WORLD" Free Run entry (track id 1010), docs/openworld/world_entry.md.

The race minimap (constructor 0x58e540) looks up the texture "TRACK<id>_MAP" in the loaded TPKs; the track's TPK is
game/Tracks/TEX<id>TRACK.BIN. This copies TEX1001TRACK.BIN, renames its TRACK1001_MAP texture to TRACK1010_MAP (name string,
the hash in the record and the hash in the index chunk 0x33310002) and repaints the 256 x 256 BGRA pixels with the street
network of the whole city: every road section (chunk 0x34121: nodes of 0x88 bytes, x y @+0, half widths @+36 and @+40) of the 16
street tracks, dark teal ground and lighter teal roads, the colours of the shipped maps.

The picture covers X0..X0+S in world x and Y0-S..Y0 in world y (u = (x-X0)/S, v = (Y0-y)/S, re_trackmap.md section 2). The
same three numbers are WORLD_X0/Y0/S in host/openworld.c (row 1010 +0x8c, +0x90, +0x94).

The second city: the picture of UG2's own free-roam map is pasted in. Facts and addresses in census/ug2/map.md: texture
TRACKMAP4000 (hash f7600936), 2048 x 2048 DXT5 in UG2 TRACKS/TRACKMAP4000.BIN, bounds of its track row (id 4000, region L4RA)
X0 -3425.43, Y0 3287.26, S 5633.16 in raw UG2 units with the same u = (x-X0)/S, v = (Y0-y)/S. It is placed in the NFSU1 world by the
decided R270 + t transform (docs/re/ug2_bridge.md: (x, y) -> (y + TX, -x + TY), tools/ug2_roads.py), which turns the picture a quarter
turn clockwise. The bridge road (x 114.8..128.8, y 394..589.2 with the NFSU1 stub, docs/re/ug2_bridge.md) is drawn in the NFSU1 road colour.

usage: python3 tools/openworld/worldmap.py   -> build/openworld/TEX1010TRACK.BIN, build/openworld/world_map.png (the 256 x 256 picture),
       build/openworld/world_map_1024.png (preview of the same drawing at 1024 x 1024)
"""
import os, re, struct, sys
import numpy as np
from PIL import Image, ImageDraw

REPO = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
os.environ.setdefault('NFSU1_MAIN', REPO)
sys.path.insert(0, os.path.join(REPO, 'ref', 'tools', 'ug1-tracks'))
sys.path.insert(0, os.path.join(REPO, 'tools'))
import lib  # noqa: E402
import ug2_roads as UR  # noqa: E402  TX, TY: the UG2 -> NFSU1 placement
import ug2_tex as UT  # noqa: E402  TPK reader and DXT decoder

# host/openworld.c WORLD_X0, WORLD_Y0, WORLD_S. Both cities and the bridge must fit one square (u and v share S):
#   NFSU1 road nodes x -691..2393, y -1920..734 (printed by sections());
#   UG2 picture square placed by R270 + t: x' = y + TX, y' = -x + TY -> x' -3633.4..1999.7, y' -1395.5..4237.7 (UG2_* below).
# X0 -3650 / Y0 4260 / S 6240 = x -3650..2590, y -1980..4260: every one of those inside, 12..157 units of margin, 24.4 units per pixel.
X0, Y0, S = -3650.0, 4260.0, 6240.0
N = 256
SS = 4                                  # supersampling for the anti-aliasing
IDS = list(range(1001, 1009)) + list(range(1102, 1110))
GROUND, ROAD = (11, 37, 44), (74, 124, 138)
SRC = os.path.join(REPO, 'game', 'Tracks', 'TEX1001TRACK.BIN')
UG2_MAP = '/Users/angeldamian/RE-NFSU-UG2/Need For Speed Underground 2/TRACKS/TRACKMAP4000.BIN'
UG2_X0, UG2_Y0, UG2_S = -3425.429931640625, 3287.260009765625, 5633.16015625    # row id 4000 of the UG2 track table, f32 at +0xac, +0xb0, +0xb4 (census/ug2/map.md)
BRIDGE = ((121.8, 394.0), (120.0, 589.2), 14.0)          # centre line: the NFSU1 stub axis (60 ground rows from y 394, dead end y 507.9) to the UG2 south ground edge (y 588.8..589.6), width 14 (x 114.8..128.8), docs/re/ug2_bridge.md
HALO = 45.0                                              # world units of NFSU1 ground kept around the NFSU1 roads (instead of UG2 terrain)
OUT = os.path.join(REPO, 'build', 'openworld')


def binhash(s):   # the bin-key hash 0x567c70: h = -1, h = h * 33 + c
    h = 0xFFFFFFFF
    for c in s.encode('latin1'):
        h = (h * 33 + c) & 0xFFFFFFFF
    return h


def sections():
    """Every road section of the 16 tracks: [(x, y, width)] per section, deduplicated by the first node."""
    seen, out = set(), []
    for tid in IDS:
        d = lib.load(lib.trackb_path(lib.PC, tid))
        (b, s), = lib.find(d, 0x34121)
        o = b
        while o < b + s:
            n = struct.unpack_from('<h', d, o + 0x10)[0]
            nodes = []
            for j in range(n):
                no = o + 0x27c + j * 0x88
                x, y = struct.unpack_from('<2f', d, no)
                wl, wr = struct.unpack_from('<2f', d, no + 36)
                nodes.append((x, y, wl + wr))
            key = tuple(round(v, 1) for v in nodes[0][:2] + nodes[-1][:2]) if nodes else None
            if nodes and key not in seen:
                seen.add(key)
                out.append(nodes)
            o += 0x27c + n * 0x88
    return out


def ug2_picture():
    """UG2's TRACKMAP4000 (2048 x 2048 DXT5) as RGB, decoded with tools/ug2_tex.py; asserts the hash, size and format of its record"""
    d = open(UG2_MAP, 'rb').read()
    pk, = UT.packs(d)
    r, = pk['recs']
    assert r['name'] == 'TRACKMAP4000' and r['hash'] == binhash('TRACKMAP4000') == 0xf7600936, 'hash 0x43db50: h = -1, h * 33 + c'
    assert (r['w'], r['h'], UT.GPU_FMT[pk['gpu'][0]]) == (2048, 2048, 'DXT5')
    im = UT.decode(d, pk, r, 'DXT5')
    assert (im[..., 3] == 255).all()
    return Image.fromarray(im[..., :3])


def paste_ug2(big, scale):
    """Paste the UG2 picture into the supersampled canvas. A UG2 point (x, y) is at NFSU1 (y + TX, -x + TY); its picture pixel (u, v) =
    ((x - UG2_X0) / UG2_S, (UG2_Y0 - y) / UG2_S), so u grows to -y' and v grows to -x': the picture turns a quarter turn clockwise
    (world[py][px] = ug2[n - 1 - px][py]) and lands with its left edge at x' = UG2_Y0 - UG2_S + TX and its top edge at y' = TY - UG2_X0."""
    rot = ug2_picture().transpose(Image.ROTATE_270)
    m = S / (N * SS)                                   # world units per canvas pixel
    side = round(UG2_S / m)
    left = (UG2_Y0 - UG2_S + UR.TX - X0) / m
    top = (Y0 - (UR.TY - UG2_X0)) / m
    assert left >= -1 and top >= -1 and left + side <= N * SS + 1 and top + side <= N * SS + 1, 'the UG2 picture leaves the canvas'
    rot = rot.resize((side, side), Image.LANCZOS)
    big.paste(rot, (round(left), round(top)))
    print('UG2 picture: x %.1f..%.1f  y %.1f..%.1f  -> canvas px %d..%d, %d..%d' % (
        UG2_Y0 - UG2_S + UR.TX, UG2_Y0 + UR.TX, UR.TY - UG2_X0 - UG2_S, UR.TY - UG2_X0,
        round(left), round(left) + side, round(top), round(top) + side))


def paint():
    big = Image.new('RGB', (N * SS, N * SS), GROUND)
    k = N * SS / S
    secs = sections()
    allx = [p[0] for sec in secs for p in sec]
    ally = [p[1] for sec in secs for p in sec]
    print('%d sections, x %.0f..%.0f y %.0f..%.0f' % (len(secs), min(allx), max(allx), min(ally), max(ally)))
    assert min(allx) > X0 and max(allx) < X0 + S and max(ally) < Y0 and min(ally) > Y0 - S, 'the road network leaves the picture'

    def lines(dr, fill, extra=0.0):
        for sec in secs:
            for a, b in zip(sec, sec[1:]):
                w = (max((a[2] + b[2]) / 2, 12) * 1.2 + extra) * k           # the roads read at 12 world units per pixel: never thinner than 1 px
                p, q = ((a[0] - X0) * k, (Y0 - a[1]) * k), ((b[0] - X0) * k, (Y0 - b[1]) * k)
                dr.line([p, q], fill=fill, width=max(1, round(w)))
                r = w / 2
                dr.ellipse([q[0] - r, q[1] - r, q[0] + r, q[1] + r], fill=fill)

    paste_ug2(big, k)
    halo = Image.new('L', big.size, 0)                 # UG2 terrain is replaced by the NFSU1 ground around the NFSU1 roads
    hd = ImageDraw.Draw(halo)
    lines(hd, 255, 2 * HALO)
    (bx, by), r = BRIDGE[1], 130 * k                    # the UG2 road the bridge lands on is never cut
    hd.ellipse([(bx - X0) * k - r, (Y0 - by) * k - r, (bx - X0) * k + r, (Y0 - by) * k + r], fill=0)
    big.paste(Image.new('RGB', big.size, GROUND), (0, 0), halo)
    dr = ImageDraw.Draw(big)
    lines(dr, ROAD)
    (ax, ay), (bx, by), w = BRIDGE
    dr.line([((ax - X0) * k, (Y0 - ay) * k), ((bx - X0) * k, (Y0 - by) * k)], fill=ROAD, width=max(1, round(w * 1.2 * k)))
    return big


def main():
    c = open(os.path.join(REPO, 'host', 'openworld.c')).read()   # the exe reads these three numbers, the picture must use the same ones
    for name, v in (('WORLD_X0', X0), ('WORLD_Y0', Y0), ('WORLD_S', S)):
        m = re.search(r'#define %s\s+\(?(-?[\d.]+)f\)?' % name, c)
        assert m and float(m.group(1)) == v, 'host/openworld.c %s differs from worldmap.py' % name
    big = paint()
    img = big.resize((N, N), Image.LANCZOS)
    os.makedirs(OUT, exist_ok=True)
    img.save(os.path.join(OUT, 'world_map.png'))
    big.save(os.path.join(OUT, 'world_map_1024.png'))
    d = bytearray(open(SRC, 'rb').read())
    old, new = binhash('TRACK1001_MAP'), binhash('TRACK1010_MAP')
    name = d.find(b'TRACK1001_MAP')
    rec = name - 12                                      # texture record 0x7c B: name @+12, hash @+0x24, data offset @+0x30
    assert struct.unpack_from('<I', d, rec + 0x24)[0] == old
    data = 0x400 + struct.unpack_from('<I', d, rec + 0x30)[0]
    assert d[data + 0x40000:data + 0x40008] == b'\0\0\0\0\0\x10\0\0', 'the pixels end where the trailing pad chunk starts'
    d[name:name + 13] = b'TRACK1010_MAP'
    struct.pack_into('<I', d, rec + 0x24, new)
    idx = d.find(struct.pack('<I', old), 0x20)           # the hash list of chunk 0x33310002 (8 B entries: hash, 0)
    assert idx < rec and struct.unpack_from('<I', d, idx - 8)[0] < new, 'the renamed hash would change the sorted order of the index'
    struct.pack_into('<I', d, idx, new)
    px = np.zeros((N, N, 4), np.uint8)
    px[..., :3] = np.array(img)[..., ::-1]               # BGRA
    px[..., 3] = 255
    d[data:data + 0x40000] = px.tobytes()
    open(os.path.join(OUT, 'TEX1010TRACK.BIN'), 'wb').write(d)
    print('TRACK1001_MAP %08x -> TRACK1010_MAP %08x, pixels at 0x%x, wrote build/openworld/TEX1010TRACK.BIN (%d bytes)' % (old, new, data, len(d)))


main()
