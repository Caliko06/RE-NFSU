"""Remaster index: content hash of each TPK texture's level 0 -> its upscaled PNG.

The layer (host/d3d9.c) hashes level 0 at UnlockRect the same way (FNV-1a 64 of the locked bytes) and asks
web/gpu.js to show the PNG instead. TPK layout and JDLZ as in the PS2 build RE (its cartex/jdlz tools are not kept).
CARS/TEXTURES.BIN is the shared pack (traffic skins, sponsor decals); DUMMY_* are the game's own composited skins and
wheels, so they keep their original. Format 0x20 is 32-bit (w*h*4 bytes), hashed like DXT by the layer.
Usage: index.py game web/remaster/png web/remaster/index.tsv  (png = a folder of <key>.png upscales; web/remaster/index.tsv now lists dump/ webp paths, so no png/ is needed)
"""
import os, struct, sys

def jdlz(data):
    usize = struct.unpack_from('<I', data, 8)[0]
    out = bytearray(); f1 = f2 = 1; ip = 16
    while ip < len(data) and len(out) < usize:
        if f1 == 1: f1 = data[ip] | 0x100; ip += 1
        if f2 == 1: f2 = data[ip] | 0x100; ip += 1
        if f1 & 1:
            if f2 & 1: n = (data[ip + 1] | ((data[ip] & 0xF0) << 4)) + 3; d = (data[ip] & 0x0F) + 1
            else: d = (data[ip + 1] | ((data[ip] & 0xE0) << 3)) + 17; n = (data[ip] & 0x1F) + 3
            ip += 2
            for _ in range(n): out.append(out[-d])
            f2 >>= 1
        else:
            out.append(data[ip]); ip += 1
        f1 >>= 1
    return bytes(out)

def fnv64(b):
    h = 0xcbf29ce484222325
    for x in b: h = ((h ^ x) * 0x100000001b3) & 0xffffffffffffffff
    return h

def chunks(d, o, e):
    while o + 8 <= e:
        m, s = struct.unpack_from('<II', d, o); yield m, o + 8, s; o += 8 + s

def textures(fn):
    d = open(fn, 'rb').read(); slots = {}; recs = []
    for m, b, s in chunks(d, 0, len(d)):
        if m != 0xb3300000: continue
        for m2, b2, s2 in chunks(d, b, b + s):
            for m3, b3, s3 in chunks(d, b2, b2 + s2):
                if m3 == 0x33310003:
                    for k in range(0, s3, 20):
                        key, ao, es = struct.unpack_from('<3I', d, b3 + k); slots[key] = (ao, es)
                if m3 == 0x33310004: recs += [d[b3 + k:b3 + k + 0x7c] for k in range(0, s3, 0x7c)]
    for r in recs:
        key, = struct.unpack_from('<I', r, 0x24); w, h = struct.unpack_from('<HH', r, 0x44); comp = r[0x4A]
        if key not in slots or comp not in (0x20, 0x22, 0x24, 0x26) or r[0xc:0x12] == b'DUMMY_': continue
        ao, es = slots[key]; raw = d[ao:ao + es]
        if raw[:4] == b'JDLZ': raw = jdlz(raw)
        n = w * h * 4 if comp == 0x20 else max(1, w // 4) * max(1, h // 4) * (8 if comp == 0x22 else 16)
        yield key, w, h, comp, raw[:n]

game, pngs, out = sys.argv[1:4]
have = {f[:8] for f in os.listdir(pngs) if f.endswith('.png')}
rows = n = 0
with open(out, 'w') as o:
    for car in [''] + sorted(os.listdir(os.path.join(game, 'CARS'))):
        fn = os.path.join(game, 'CARS', car, 'TEXTURES.BIN')
        if not os.path.isfile(fn): continue
        for key, w, h, comp, lvl0 in textures(fn):
            n += 1
            if f'{key:08x}' in have:
                o.write(f'{fnv64(lvl0):016x}\t{key:08x}\t{w}\t{h}\t{comp:#x}\t{car or 'SHARED'}\n'); rows += 1
print(f'{n} textures, {rows} with a PNG -> {out}')
