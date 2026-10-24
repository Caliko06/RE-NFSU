# BRIDGE (remaster step 1, OWNER 2026-10-24, ?remaster=pbr): a normal + roughness map for each pack v2 texture, same key
# (FNV-1a 64 of the DXT level 0). One RGB WebP per texture: R,G = normal x,y (0.5 = flat; z is rebuilt in the shader),
# B = roughness. Two normal candidates, chosen with `sheet` on 10 textures:
#   sobel    height = luminance (blurred 1 px), normal from its wrapped gradient (tiles like the texture)
#   deepbump DeepBump 256 (H. Tini, GPL-3; its own tiles_split/tiles_merge), the ONNX run as torch on CUDA (onnx2torch)
# Roughness: a base per material class (world texture names, world.tsv) moved by the local variance of the luminance.
# Car textures: one base; their alpha (the reflection mask, census/car_draw_census.txt) still rules in the shader.
# Pod A, GPU shared with Most Wanted: torch memory fraction 0.45 (<= 14 GB).
# usage: nr_gen.py gen SET METHOD     SET = world|cars, METHOD = sobel|deepbump -> /root/rm2/out/nr_<METHOD>/<hash>.webp
#        nr_gen.py sheet HASH ...    side by side + measures -> /root/rm2/out/nr_sheet.webp, nr_sheet.json
import json, os, re, sys
import numpy as np, torch, torch.nn.functional as F
from PIL import Image
W = '/root/rm2'; OUT = f'{W}/out'
sys.path[:0] = [f'{W}/pylib', f'{W}/DeepBump']
torch.cuda.set_per_process_memory_fraction(0.45)
dev = torch.device('cuda')

def index(s):
    return dict(l.split('\t')[:2] for l in open(f'{OUT}/index{"_world" if s == "world" else ""}_v2.tsv').read().split('\n') if l)

NAMES = {}   # world content hash -> texture name (world.tsv col 7)
for l in open(f'{W}/world.tsv').read().split('\n'):
    f = l.split('\t')
    if len(f) >= 7: NAMES[f[0]] = f[6]
# (pattern, base roughness): first match wins. Remaster look values (not game data): the game has no roughness.
CLASSES = [(r'GLASS|WINDOW|WNDW', .12), (r'WATER|PUDDLE|WET', .15), (r'CHROME|MIRROR', .1),
           (r'METAL|RAIL|POLE|PIPE|WIRE|SIGN|FENCE|GRATE|STEEL', .4),
           (r'ROAD|ASPH|TRN_|STREET|LANE|CROSSWALK|TARMAC', .7), (r'BRICK|WALL|CONC|STONE|ROCK|CURB|SIDEWALK|BLDG|BUILDING', .85),
           (r'GRASS|TREE|LEAF|DIRT|GRAVEL|SAND|BUSH', .95)]
def base_rough(h, s):
    if s == 'cars': return .45
    n = NAMES.get(h, '')
    return next((r for p, r in CLASSES if re.search(p, n)), .75)

def load(path):
    a = np.asarray(Image.open(f'{OUT}/{path}').convert('RGB'), np.float32) / 255
    return torch.from_numpy(a).permute(2, 0, 1).to(dev)            # 3,H,W

def gray(rgb): return rgb.mean(0, keepdim=True)                    # DeepBump's own input (mean of RGB)

def blur(x, r):   # wrapped box blur (the textures tile)
    k = 2 * r + 1
    x = F.pad(x[None], (r, r, r, r), mode='circular')
    return F.avg_pool2d(x, k, 1)[0]

def sobel_normal(rgb, strength=4.0):
    h = blur(gray(rgb), 1)
    p = F.pad(h[None], (1, 1, 1, 1), mode='circular')[0, 0]
    dx = (p[1:-1, 2:] - p[1:-1, :-2]) * .5; dy = (p[2:, 1:-1] - p[:-2, 1:-1]) * .5
    n = torch.stack([-dx * strength, dy * strength, torch.ones_like(dx)])   # y up (DeepBump / OpenGL convention)
    return n / n.norm(dim=0, keepdim=True)

_db = None
class _Session:   # the ort.InferenceSession calls tiles_infer makes, on torch
    def __init__(self, m): self.m = m
    def get_inputs(self): return [type('I', (), {'name': 'input'})()]
    def run(self, _, feed):
        with torch.no_grad(): return [self.m(torch.from_numpy(np.asarray(next(iter(feed.values())), np.float32)).to(dev)).cpu().numpy()]   # a list of 1 tile
def deepbump_normal(rgb):
    global _db
    import utils_inference
    if _db is None:
        import onnx, onnx2torch
        _db = _Session(onnx2torch.convert(onnx.load(f'{W}/DeepBump/deepbump256.onnx')).to(dev).eval())
    img = gray(rgb).cpu().numpy()
    tile, stride = 256, 256 - 256 // 4     # DeepBump 'MEDIUM' overlap
    # Wrap-pad half a tile on each side, crop after: DeepBump pads by reflection, which broke the tiling (seam 2-5x Sobel's)
    m = tile // 2
    big = np.pad(img, ((0, 0), (m, m), (m, m)), mode='wrap')
    tiles, pads = utils_inference.tiles_split(big, (tile, tile), (stride, stride))
    pred = utils_inference.tiles_infer(tiles, _db)
    out = utils_inference.tiles_merge(pred, (stride, stride), (3, big.shape[1], big.shape[2]), pads)
    n = torch.from_numpy(out[:, m:m + img.shape[1], m:m + img.shape[2]].copy()).to(dev) * 2 - 1
    return n / n.norm(dim=0, keepdim=True).clamp_min(1e-6)

def roughness(rgb, base):
    g = gray(rgb)
    sd = (blur(g * g, 4) - blur(g, 4) ** 2).clamp_min(0).sqrt()       # local variance, 9x9 wrapped
    return (base + 1.5 * (sd - sd.mean())).clamp(.05, 1)              # busier detail = rougher, around the class base

def encode(n, r):
    a = torch.cat([n[:2] * .5 + .5, r]).clamp(0, 1).permute(1, 2, 0).mul(255).round().byte().cpu().numpy()
    return Image.fromarray(a, 'RGB')

def gen(s, method):
    d = f'{OUT}/nr_{method}'; os.makedirs(d, exist_ok=True)
    idx = index(s); done = 0
    for h, path in sorted(idx.items()):
        o = f'{d}/{h}.webp'
        if os.path.exists(o): continue
        rgb = load(path)
        n = sobel_normal(rgb) if method == 'sobel' else deepbump_normal(rgb)
        encode(n, roughness(rgb, base_rough(h, s))).save(o, quality=92)
        done += 1
        if done % 200 == 0: print(s, method, done, 'of', len(idx), torch.cuda.max_memory_allocated() >> 20, 'MB', flush=True)
    print('NR-DONE', s, method, len(idx), flush=True)

# The measures of a candidate (no ground truth: what makes a normal map wrong in play):
#   seam   |n(left col) - n(right col)| (+ top/bottom) over the mean step between inner neighbours: 1 = tiles seamlessly
#   block  energy of the normal on the 16 px grid (DXT 4x4 blocks after the x4) over the energy off it: >1 = block artifacts
#   relief mean angle from flat, degrees (how strong it is at the stored strength)
def measures(n):
    edge = (n[:, :, 0] - n[:, :, -1]).abs().mean() + (n[:, 0] - n[:, -1]).abs().mean()
    inner = (n[:, :, 1:] - n[:, :, :-1]).abs().mean() + (n[:, 1:] - n[:, :-1]).abs().mean()
    seam = (edge / inner).item()
    gx = (n[:, :, 1:] - n[:, :, :-1]).abs().sum(0).mean(0)
    on = gx[15::16].mean(); off = torch.cat([gx[k::16] for k in range(16) if k != 15]).mean()
    relief = torch.rad2deg(torch.acos(n[2].clamp(-1, 1))).mean().item()
    return dict(seam=round(seam, 2), block=round((on / off).item(), 3), relief=round(relief, 2))

def lit(rgb, n):   # albedo x (ambient + N.L), light from the upper left: how the map reads on screen
    l = torch.tensor([-.5, .5, .7], device=dev); l = l / l.norm()
    return rgb * (.35 + .65 * (n * l[:, None, None]).sum(0, keepdim=True).clamp_min(0))

def sheet(hashes):
    idx = {**index('world'), **index('cars')}; rows, res = [], {}
    for h in hashes:
        rgb = load(idx[h]); ns = sobel_normal(rgb); nd = deepbump_normal(rgb)
        res[h] = dict(name=NAMES.get(h, 'car'), sobel=measures(ns), deepbump=measures(nd))
        cells = [rgb, ns * .5 + .5, lit(rgb, ns), nd * .5 + .5, lit(rgb, nd)]
        cells = [F.interpolate(c[None], size=(256, 256), mode='area')[0] for c in cells]   # one size per cell
        rows.append(torch.cat(cells, 2))
    img = torch.cat(rows, 1).clamp(0, 1).permute(1, 2, 0).mul(255).byte().cpu().numpy()
    Image.fromarray(img).save(f'{OUT}/nr_sheet.webp', quality=90)
    json.dump(res, open(f'{OUT}/nr_sheet.json', 'w'), indent=1)
    for h, v in res.items(): print(h, v)

if __name__ == '__main__':
    if sys.argv[1] == 'gen': gen(sys.argv[2], sys.argv[3])
    else: sheet(sys.argv[2:])
