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
for name, data in [('tex.pack', pack)] + [(n, (root / n).read_bytes()) for n in ('city.bin', 'city_tex.bin', 'bridge.bin', 'bridge_tex.bin')]:
    target = root / (name + '.gz')
    target.write_bytes(gzip.compress(data, compresslevel=6, mtime=0))
    print(f'{target.name}: {len(data):,} -> {target.stat().st_size:,} bytes')
