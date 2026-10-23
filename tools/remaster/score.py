# Score upscaled PNGs against the decoded originals (the acceptance gate of the remaster plan).
# usage: score.py ORIG_DIR VARIANT_DIR [VARIANT_DIR ...]   (same file names in each dir)
# psnr   = box-downscale the 4x output back to the original size, PSNR vs the original (RGB): faithfulness.
# FLOOR=28 writes <variant>.below: files under that PSNR (the exception list the OWNER approves).
# detail = mean gradient energy of the output / that of a bicubic 4x of the original: > 1 means detail beyond interpolation.
import sys, os, numpy as np
from PIL import Image

def grad(a):
    g = a.mean(2)
    return np.hypot(np.diff(g, axis=1)[:-1, :], np.diff(g, axis=0)[:, :-1]).mean()

def score(orig_dir, var_dir):
    ps, ds, names = [], [], []
    for f in sorted(os.listdir(var_dir)):
        o = Image.open(os.path.join(orig_dir, f)).convert('RGB'); v = Image.open(os.path.join(var_dir, f)).convert('RGB')
        s = v.width // o.width
        if s < 2: continue
        back = np.asarray(v.resize(o.size, Image.BOX), np.float32); ref = np.asarray(o, np.float32)
        mse = ((back - ref) ** 2).mean()
        ps.append(99.0 if mse == 0 else 10 * np.log10(255 ** 2 / mse)); names.append(f)
        bic = np.asarray(o.resize(v.size, Image.BICUBIC), np.float32)
        ds.append(grad(np.asarray(v, np.float32)) / max(grad(bic), 1e-6))
    return np.array(ps), np.array(ds), names

if __name__ == '__main__':
    orig = sys.argv[1]
    print(f'{"variant":34s} {"n":>3s} {"psnr med":>9s} {"psnr min":>9s} {"detail med":>11s}')
    for d in sys.argv[2:]:
        p, q, names = score(orig, d)
        floor = float(os.environ.get('FLOOR', 0))
        if floor: open(os.path.basename(d.rstrip('/')) + '.below', 'w').write(''.join(f'{n}\t{x:.2f}\n' for n, x in zip(names, p) if x < floor))
        if len(p): print(f'{os.path.basename(d.rstrip("/")):34s} {len(p):3d} {np.median(p):9.2f} {p.min():9.2f} {np.median(q):11.2f}')
