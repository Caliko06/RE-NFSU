#!/usr/bin/env python3
"""worldmap.py: the HUD minimap picture of the "WORLD" Free Run entry (track id 1010), docs/openworld/world_entry.md.

The race minimap (constructor 0x58e540) looks up the texture "TRACK<id>_MAP" in the loaded TPKs; the track's TPK is
game/Tracks/TEX<id>TRACK.BIN. This copies TEX1001TRACK.BIN, renames its TRACK1001_MAP texture to TRACK1010_MAP (name string,
the hash in the record and the hash in the index chunk 0x33310002) and repaints the 256 x 256 BGRA pixels with the street
network of the whole city: every road section (chunk 0x34121: nodes of 0x88 bytes, x y @+0, half widths @+36 and @+40) of the 16
street tracks, dark teal ground and lighter teal roads, the colours of the shipped maps.

The picture covers X0..X0+S in world x and Y0-S..Y0 in world y (u = (x-X0)/S, v = (Y0-y)/S, re_trackmap.md section 2). The
same three numbers are WORLD_X0/Y0/S in host/openworld.c (row 1010 +0x8c, +0x90, +0x94).

usage: python3 tools/openworld/worldmap.py   -> build/openworld/TEX1010TRACK.BIN, build/openworld/world_map.png
"""
import os, struct, sys
import numpy as np
from PIL import Image, ImageDraw

REPO = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
os.environ.setdefault('NFSU1_MAIN', REPO)
sys.path.insert(0, os.path.join(REPO, 'ref', 'tools', 'ug1-tracks'))
import lib  # noqa: E402

X0, Y0, S = -750.0, 1000.0, 3200.0      # host/openworld.c WORLD_X0, WORLD_Y0, WORLD_S
N = 256
SS = 4                                  # supersampling for the anti-aliasing
IDS = list(range(1001, 1009)) + list(range(1102, 1110))
GROUND, ROAD = (11, 37, 44), (74, 124, 138)
SRC = os.path.join(REPO, 'game', 'Tracks', 'TEX1001TRACK.BIN')
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


def paint():
    big = Image.new('RGB', (N * SS, N * SS), GROUND)
    dr = ImageDraw.Draw(big)
    k = N * SS / S
    secs = sections()
    allx = [p[0] for sec in secs for p in sec]
    ally = [p[1] for sec in secs for p in sec]
    print('%d sections, x %.0f..%.0f y %.0f..%.0f' % (len(secs), min(allx), max(allx), min(ally), max(ally)))
    assert min(allx) > X0 and max(allx) < X0 + S and max(ally) < Y0 and min(ally) > Y0 - S, 'the road network leaves the picture'
    for sec in secs:
        for a, b in zip(sec, sec[1:]):
            w = max((a[2] + b[2]) / 2, 12) * 1.2 * k            # the roads read at 12 world units per pixel: never thinner than 1 px
            p, q = ((a[0] - X0) * k, (Y0 - a[1]) * k), ((b[0] - X0) * k, (Y0 - b[1]) * k)
            dr.line([p, q], fill=ROAD, width=max(1, round(w)))
            r = w / 2
            dr.ellipse([q[0] - r, q[1] - r, q[0] + r, q[1] + r], fill=ROAD)
    return big.resize((N, N), Image.LANCZOS)


def main():
    img = paint()
    os.makedirs(OUT, exist_ok=True)
    img.save(os.path.join(OUT, 'world_map.png'))
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
