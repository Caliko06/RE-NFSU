"""Clean round lamp glow for the remaster (OWNER 2026-11-04, "faros con astigmatismo"; docs/re/flare_clean.md).
The shipped flares are HEADLIGHTFLAREINNER (a star with long rays), HEADLIGHTFLAREOUTER (a rainbow ring, 2:1 on a square quad)
and HEADLIGHTGLOW (core + thin spikes). Same keys as host/d3d9.c (FNV-1a 64 of level 0, checked with RN_TEXHASH on runs/w_b1).
White, because the flare descriptors colour them (a tail lamp stays red). Original mode has no pack. usage: flare_glow.py"""
import os
import numpy as np
from PIL import Image
OUT = os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'web', 'remaster')
KEYS = {'d6114cf1cf5a75b9': ('inner', 0.13, 1.0), 'ec62624ef246c8e4': ('outer', 0, 0), '1587c2105d4f0d26': ('glow', 0.24, 0.75)}
os.makedirs(os.path.join(OUT, 'glow'), exist_ok=True)
y, x = np.mgrid[-1:1:256j, -1:1:256j]
r = np.hypot(x, y)
rows = []
for key, (name, sigma, gain) in KEYS.items():
    v = gain * np.exp(-(r / sigma) ** 2 / 2) * np.clip((1 - r) / 0.25, 0, 1) if sigma else 0 * r   # reaches 0 before the quad's edge
    rgba = np.zeros((256, 256, 4), np.uint8)
    rgba[..., :3] = (255 * v + 0.5).astype(np.uint8)[..., None]
    rgba[..., 3] = 254 if sigma else 0
    Image.fromarray(rgba, 'RGBA').save(os.path.join(OUT, 'glow', name + '.png'))
    rows.append(f'{key}\tglow/{name}.png\t256\t256\t0x20\tFLARE\n')
open(os.path.join(OUT, 'index_glow.tsv'), 'w').writelines(rows)
