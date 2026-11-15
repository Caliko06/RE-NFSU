#!/usr/bin/env python3
"""Prepare lossless WORLD downloads. Run after the UG2 exporters, before packaging.

Gzip streams decode explicitly in the browser, so a static host needs no encoding rule.
Texture pack: u32 little-endian JSON byte length, JSON {file:[offset,length]}, PNG bytes.
Offsets start at the PNG payload. Keeps every pixel and alpha value unchanged.
"""
import gzip
import json
import pathlib
import struct

root = pathlib.Path(__file__).resolve().parents[1] / 'web' / 'ug2'
info = json.loads((root / 'tex.json').read_text())
index, payload = {}, bytearray()
for name in dict.fromkeys(t['file'] for t in info['textures'] if t.get('file')):
    data = (root / name).read_bytes()
    index[name] = [len(payload), len(data)]
    payload.extend(data)
header = json.dumps(index, separators=(',', ':')).encode()
pack = struct.pack('<I', len(header)) + header + payload


def half_pack():
    """tex_half.pack for phones (web/ug2/ug2world.js HALF): every texture at half width and height (box filter = the mip 1 the
    page builds today) as WebP quality 90, same pack layout and names (the .png names hold WebP bytes). The full pack above stays lossless."""
    import io
    from PIL import Image
    index, payload = {}, bytearray()
    for name in dict.fromkeys(t['file'] for t in info['textures'] if t.get('file')):
        im = Image.open(root / name).convert('RGBA')
        im = im.resize((max(1, im.width // 2), max(1, im.height // 2)), Image.BOX)
        out = io.BytesIO()
        im.save(out, 'WEBP', quality=90, method=6, exact=True)   # 4.6 MB in all; PNG 22.7, lossless WebP 16.1 (2026-11-15)
        index[name] = [len(payload), out.tell()]
        payload.extend(out.getvalue())
    header = json.dumps(index, separators=(',', ':')).encode()
    return struct.pack('<I', len(header)) + header + payload


for name, data in [('tex.pack', pack), ('tex_half.pack', half_pack())] + [(n, (root / n).read_bytes()) for n in ('city.bin', 'city_tex.bin', 'bridge.bin', 'bridge_tex.bin')]:
    target = root / (name + '.gz')
    target.write_bytes(gzip.compress(data, compresslevel=6, mtime=0))
    print(f'{target.name}: {len(data):,} -> {target.stat().st_size:,} bytes')
