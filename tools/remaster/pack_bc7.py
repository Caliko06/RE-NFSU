#!/usr/bin/env python3
"""The default remaster pack (index.tsv + index_v2.tsv + index_fe_v2.tsv) as BC7 with a full mip chain:
web/remaster/bc/<dir>/<hash>.dds.gz + index_bc.tsv, read by web/gpu.js loadDds.
Why: loadHd uploads every pack texture as rgba8unorm + mips, 528 MB of GPU memory for the 539 textures of the title
screen (12 MB on disk, build/m_title.json 2026-11-05); BC7 is a quarter of that. Same file layout as world_bc7.sh.
Level 0 is at most 1024 a side (as loadHd), mips are a 2x2 box on non-premultiplied RGBA (as mipPipe).
A texture whose size is not a multiple of 4 stays rgba8 (no index_bc line). Resumable. Usage: pack_bc7.py [jobs]"""
import os, sys, gzip, struct
from multiprocessing import Pool
import numpy as np
from PIL import Image
import etcpak

R = os.path.join(os.path.dirname(os.path.abspath(__file__)), '../../web/remaster')

def keymap():
    m = {}
    for n in ('index.tsv', 'index_v2.tsv', 'index_fe_v2.tsv'):   # later wins, as gpu.js
        for l in open(f'{R}/{n}'):
            f = l.rstrip('\n').split('\t')
            if len(f) > 1 and f[1]: m[f[0]] = f[1]
    return m

def src_path(name):   # a bare key is png/<key>.png, a name with a path is under remaster/
    return f'{R}/{name}' if '/' in name else f'{R}/png/{name}.png'

def encode(name):
    out = f"{R}/bc/{name.rsplit('.', 1)[0]}.dds.gz"
    if name.endswith('.dds') or os.path.exists(out): return name, os.path.exists(out)
    im = Image.open(src_path(name)).convert('RGBA')
    f = min(1, 1024 / max(im.size))
    W, H = round(im.width * f), round(im.height * f)
    if W % 4 or H % 4: return name, False
    if f < 1: im = im.resize((W, H), Image.LANCZOS)
    a = np.asarray(im, dtype=np.float32)
    levels = int(np.floor(np.log2(max(W, H)))) + 1
    body = b''
    for l in range(levels):
        h, w = a.shape[:2]
        bw, bh = -(-w // 4) * 4, -(-h // 4) * 4
        p = np.pad(a, ((0, bh - h), (0, bw - w), (0, 0)), mode='edge') if (bw, bh) != (w, h) else a
        body += bytes(etcpak.compress_bc7(np.ascontiguousarray(np.rint(p).astype(np.uint8)).tobytes(), bw, bh))
        if l + 1 < levels:
            h2, w2 = max(1, h // 2), max(1, w // 2)
            q = a[:h2 * 2, :w2 * 2] if h > 1 and w > 1 else a
            if h == 1: q = np.repeat(q, 2, axis=0)[:2]
            if w == 1: q = np.repeat(q, 2, axis=1)[:, :2]
            a = q.reshape(h2, 2, w2, 2, 4).mean(axis=(1, 3))
    hdr = struct.pack('<32I', 0x20534444, 124, 0x000a1007, H, W, -(-W // 4) * -(-H // 4) * 16, 0, levels, *[0] * 11,
                      32, 4, 0x30315844, *[0] * 5, 0x401008, 0, 0, 0, 0)
    hdr += struct.pack('<5I', 98, 3, 0, 1, 0)
    os.makedirs(os.path.dirname(out), exist_ok=True)
    with gzip.open(out + '.part', 'wb', 9) as g: g.write(hdr + body)
    os.replace(out + '.part', out)
    return name, True

if __name__ == '__main__':
    m = keymap()
    names = sorted(set(m.values()))
    with Pool(int(sys.argv[1]) if len(sys.argv) > 1 else 4) as p: ok = dict(p.imap_unordered(encode, names, 8))
    with open(f'{R}/index_bc.tsv', 'w') as o:
        for k, n in m.items():
            if ok.get(n): o.write(f"{k}\tbc/{n.rsplit('.', 1)[0]}.dds\n")
    print(f'bc: {sum(ok.values())} of {len(names)} files encoded, {sum(1 for n in m.values() if ok.get(n))} of {len(m)} keys')
