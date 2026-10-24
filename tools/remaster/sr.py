# Upscale a list of RGBA PNGs: optional 1x deblock, then a 4x model on RGB (tiled); alpha by Lanczos.
import sys, os, torch, numpy as np, spandrel
from PIL import Image
lst, src, out, sr, pre = sys.argv[1:6]
dev = 'cuda'
# A shared GPU (Pod B: MaxPayne too): GPU_GB caps this process's CUDA memory.
if os.environ.get('GPU_GB'): torch.cuda.set_per_process_memory_fraction(float(os.environ['GPU_GB']) * 2**30 / torch.cuda.get_device_properties(0).total_memory)
# fp32: MW measured bf16/fp16 below fp32 on 4x-UltraSharpV2 (DAT2).
def load(f): return spandrel.ModelLoader().load_from_file(f).to(dev).eval()
M = load(sr); P = load(pre) if pre != '-' else None
@torch.no_grad()
def run(m, x, tile=256, pad=16):
    _, _, h, w = x.shape; s = m.scale; y = torch.zeros(1, 3, h * s, w * s, device=dev)
    dt = next(m.model.parameters()).dtype
    for ty in range(0, h, tile):
        for tx in range(0, w, tile):
            y0, x0 = max(0, ty - pad), max(0, tx - pad); y1, x1 = min(h, ty + tile + pad), min(w, tx + tile + pad)
            p = x[:, :, y0:y1, x0:x1]
            # reflect-pad tiny inputs so windowed models get >= 16 px
            ph, pw = max(0, 16 - p.shape[2]), max(0, 16 - p.shape[3])
            if ph or pw: p = torch.nn.functional.pad(p, (0, pw, 0, ph), mode='replicate')
            r = m(p.to(dt)).float()[:, :, :(y1 - y0) * s, :(x1 - x0) * s]
            oy, ox = (ty - y0) * s, (tx - x0) * s; th, tw = min(tile, h - ty) * s, min(tile, w - tx) * s
            y[:, :, ty * s:ty * s + th, tx * s:tx * s + tw] = r[:, :, oy:oy + th, ox:ox + tw]
    return y.clamp(0, 1)
os.makedirs(out, exist_ok=True)
for f in open(lst).read().split():
    im = Image.open(os.path.join(src, f)).convert('RGBA'); a = im.getchannel('A')
    x = torch.from_numpy(np.asarray(im.convert('RGB'), np.float32) / 255).permute(2, 0, 1)[None].to(dev)
    if P: x = run(P, x)
    y = run(M, x)
    rgb = Image.fromarray((y[0].permute(1, 2, 0).cpu().numpy() * 255 + .5).astype(np.uint8))
    o = rgb.copy(); o.putalpha(a.resize(rgb.size, Image.LANCZOS)); o.save(os.path.join(out, f))
print('done', out)
