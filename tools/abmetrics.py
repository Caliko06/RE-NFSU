# Pod GPU: per-frame A/B of one track, the Wine reference (A) against ours (B), both 60 fps recordings from the last menu key.
# usage: abmetrics.py A.mp4 B.mp4 OUT_PREFIX   -> OUT_PREFIX.csv (one row per compared frame) + OUT_PREFIX.png (worst 10)
# Alignment: the offset (frames) that minimises the mean L1 of 40x30 grey thumbnails over the overlap (the race intro
# camera is the same path on both sides). Then every 3rd frame at 640x480: LPIPS (alex), DISTS and SSIM (piq).
# Rivals and traffic diverge after the start (the RNG draws per frame depend on frame time), so late frames differ there too.
import subprocess, sys
import numpy as np, torch, lpips, piq
from PIL import Image, ImageDraw

a_mp4, b_mp4, out = sys.argv[1:4]
dev = 'cuda'

def frames(path, w, h, grey=False):
    raw = subprocess.run(['ffmpeg', '-loglevel', 'error', '-threads', '2', '-i', path, '-vf', f'fps=60,scale={w}:{h}:flags=area',
                          '-f', 'rawvideo', '-pix_fmt', 'gray' if grey else 'rgb24', '-'], capture_output=True, check=True).stdout
    return np.frombuffer(raw, np.uint8).reshape(-1, h, w) if grey else np.frombuffer(raw, np.uint8).reshape(-1, h, w, 3)

ta = torch.tensor(frames(a_mp4, 40, 30, True), dtype=torch.float32, device=dev).flatten(1)
tb = torch.tensor(frames(b_mp4, 40, 30, True), dtype=torch.float32, device=dev).flatten(1)
na, nb, need = len(ta), len(tb), 600   # at least 10 s of overlap
best = (1e9, 0)
for off in range(-(na - need), nb - need):   # B index = A index + off
    i0, i1 = max(0, -off), min(na, nb - off)
    if i1 - i0 < need: continue
    d = (ta[i0:i1] - tb[i0 + off:i1 + off]).abs().mean().item()
    best = min(best, (d, off))
l1, off = best
# The loading screens last a different time on each side: start where the aligned frames agree (the intro), the first
# second whose mean thumbnail L1 is within 2x the overall one.
i0, i1 = max(0, -off), min(na, nb - off)
per = (ta[i0:i1] - tb[i0 + off:i1 + off]).abs().mean(1)
start = i0 + next((k for k in range(len(per) - 60) if per[k:k + 60].mean().item() <= 2 * l1), 0)
fa, fb = frames(a_mp4, 640, 480), frames(b_mp4, 640, 480)
idx = [i for i in range(start, min(len(fa), len(fb) - off)) if i % 3 == 0]
lp = lpips.LPIPS(net='alex', verbose=False).to(dev)
dists = piq.DISTS().to(dev)
rows = []
with torch.no_grad():
    for k in range(0, len(idx), 16):
        ii = idx[k:k + 16]
        A = torch.tensor(fa[ii], device=dev).permute(0, 3, 1, 2).float() / 255
        B = torch.tensor(fb[[i + off for i in ii]], device=dev).permute(0, 3, 1, 2).float() / 255
        L = lp(A * 2 - 1, B * 2 - 1).flatten()
        D = torch.stack([dists(A[j:j + 1], B[j:j + 1]) for j in range(len(ii))])
        S = piq.ssim(A, B, data_range=1.0, reduction='none')
        rows += [(i, i + off, L[j].item(), D[j].item(), S[j].item()) for j, i in enumerate(ii)]
with open(out + '.csv', 'w') as f:
    f.write(f'# offset {off} frames (B = A + offset), thumb L1 {l1:.2f}, from Wine frame {start}\nframe_a,frame_b,t_a,lpips,dists,ssim\n')
    for i, j, L, D, S in rows: f.write(f'{i},{j},{i / 60:.3f},{L:.4f},{D:.4f},{S:.4f}\n')
worst = []
for r in sorted(rows, key=lambda r: -r[2]):   # by LPIPS, at least 1 s apart
    if all(abs(r[0] - w[0]) >= 60 for w in worst): worst.append(r)
    if len(worst) == 10: break
sheet = Image.new('RGB', (960, 360 * len(worst)))
for k, (i, j, L, D, S) in enumerate(worst):
    for x, im in ((0, fa[i]), (480, fb[j])):
        sheet.paste(Image.fromarray(im).resize((480, 360), Image.BILINEAR), (x, 360 * k))
    ImageDraw.Draw(sheet).text((6, 360 * k + 4), f'Wine f{i} ({i / 60:.1f} s) | ours f{j}  LPIPS {L:.3f} DISTS {D:.3f} SSIM {S:.3f}', fill=(255, 255, 0))
sheet.save(out + '.png')
m = np.array([r[2:] for r in rows])
print(f'{out}: offset {off} ({off / 60:+.2f} s), from {start / 60:.1f} s, L1 {l1:.1f}, {len(rows)} frames, LPIPS {m[:, 0].mean():.3f} DISTS {m[:, 1].mean():.3f} SSIM {m[:, 2].mean():.3f}')
