# Pod GPU: per-frame A/B of one track, the Wine reference (A) against ours (B), both 60 fps recordings from the last menu key.
# usage: abmetrics.py A.mp4 B.mp4 OUT_PREFIX   -> OUT_PREFIX.csv (one row per compared frame), OUT_PREFIX_drift.csv (one row
#   per 1 s window) and OUT_PREFIX.png (worst 10)
# Alignment: first the global offset (frames) that minimises the mean L1 of 40x30 grey thumbnails over the overlap. Then per
# 1 s window of A the local offset within +-90 frames of it: ours runs late against Wine and stalls (race timer 0:04.41 vs
# 0:04.98 at one global offset), so one offset compares frames of different moments. The drift curve = local - global.
# Then every 3rd frame at 640x480 against its window's frame: LPIPS (alex), DISTS and SSIM (piq).
# Rivals and traffic diverge after the start (the RNG draws per frame depend on frame time), so late frames differ there too.
import subprocess, sys
import numpy as np, torch, lpips, piq
from PIL import Image, ImageDraw

a_mp4, b_mp4, out = sys.argv[1:4]
dev = 'cuda'
WIN, LOCAL = 60, 90
# A window is aligned when its best thumbnail L1 is at most this (1004 with autopilot: 0.8-5.8 while both races match,
# 12-49 once the autopilots take different lines). Worst frames come from aligned windows only: past that the A/B
# measures two different races, not the render.
ALIGNED = 8.0

def ffmpeg(path, w, h, pix):
    return subprocess.Popen(['ffmpeg', '-loglevel', 'error', '-threads', '2', '-i', path, '-vf', f'fps=60,scale={w}:{h}:flags=area',
                             '-f', 'rawvideo', '-pix_fmt', pix, '-'], stdout=subprocess.PIPE)

def thumbs(path):
    raw = ffmpeg(path, 40, 30, 'gray').communicate()[0]
    return np.frombuffer(raw, np.uint8).reshape(-1, 30 * 40)

def frames(path, keep):   # only the frames in keep (a full-lap video at 640x480 does not fit in memory)
    p, n, got = ffmpeg(path, 640, 480, 'rgb24'), 640 * 480 * 3, {}
    for i in range(max(keep) + 1):
        b = p.stdout.read(n)
        if len(b) < n: break
        if i in keep: got[i] = np.frombuffer(b, np.uint8).reshape(480, 640, 3)
    p.kill(); p.wait()
    return got

ta = torch.tensor(thumbs(a_mp4), dtype=torch.float32, device=dev)
tb = torch.tensor(thumbs(b_mp4), dtype=torch.float32, device=dev)
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
loc = {}   # window start (A frame) -> (local offset, thumb L1)
for w0 in range(start, i1, WIN):
    w1 = min(w0 + WIN, i1)
    cand = [(((ta[w0:w1] - tb[w0 + o:w1 + o]).abs().mean().item()), o)
            for o in range(off - LOCAL, off + LOCAL + 1) if w0 + o >= 0 and w1 + o <= nb]
    if cand: d, o = min(cand); loc[w0] = (o, d)
wof = lambda i: loc[start + (i - start) // WIN * WIN][0]
idx = [i for i in range(start, i1) if i % 3 == 0 and start + (i - start) // WIN * WIN in loc]
fa, fb = frames(a_mp4, set(idx)), frames(b_mp4, {i + wof(i) for i in idx})
idx = [i for i in idx if i in fa and i + wof(i) in fb]
ok = lambda i: loc[start + (i - start) // WIN * WIN][1] <= ALIGNED
lp = lpips.LPIPS(net='alex', verbose=False).to(dev)
dists = piq.DISTS().to(dev)
rows = []
with torch.no_grad():
    for k in range(0, len(idx), 16):
        ii = idx[k:k + 16]
        A = torch.tensor(np.stack([fa[i] for i in ii]), device=dev).permute(0, 3, 1, 2).float() / 255
        B = torch.tensor(np.stack([fb[i + wof(i)] for i in ii]), device=dev).permute(0, 3, 1, 2).float() / 255
        L = lp(A * 2 - 1, B * 2 - 1).flatten()
        D = torch.stack([dists(A[j:j + 1], B[j:j + 1]) for j in range(len(ii))])
        S = piq.ssim(A, B, data_range=1.0, reduction='none')
        rows += [(i, i + wof(i), L[j].item(), D[j].item(), S[j].item()) for j, i in enumerate(ii)]
with open(out + '.csv', 'w') as f:
    f.write(f'# global offset {off} frames (B = A + offset), thumb L1 {l1:.2f}, from Wine frame {start}; per 1 s window: {out}_drift.csv\nframe_a,frame_b,t_a,aligned,lpips,dists,ssim\n')
    for i, j, L, D, S in rows: f.write(f'{i},{j},{i / 60:.3f},{int(ok(i))},{L:.4f},{D:.4f},{S:.4f}\n')
with open(out + '_drift.csv', 'w') as f:
    f.write('t_a,offset,drift,thumb_l1,aligned\n')
    for w0, (o, d) in sorted(loc.items()): f.write(f'{w0 / 60:.1f},{o},{o - off},{d:.2f},{int(d <= ALIGNED)}\n')
worst = []
for r in sorted((r for r in rows if ok(r[0])), key=lambda r: -r[2]):   # by LPIPS, at least 1 s apart
    if all(abs(r[0] - w[0]) >= 60 for w in worst): worst.append(r)
    if len(worst) == 10: break
sheet = Image.new('RGB', (960, 360 * max(1, len(worst))))
for k, (i, j, L, D, S) in enumerate(worst):
    for x, im in ((0, fa[i]), (480, fb[j])):
        sheet.paste(Image.fromarray(im).resize((480, 360), Image.BILINEAR), (x, 360 * k))
    ImageDraw.Draw(sheet).text((6, 360 * k + 4), f'Wine f{i} ({i / 60:.1f} s) | ours f{j}  LPIPS {L:.3f} DISTS {D:.3f} SSIM {S:.3f}', fill=(255, 255, 0))
sheet.save(out + '.png')
m = np.array([r[2:] for r in rows if ok(r[0])] or [(np.nan,) * 3])
dr = [o - off for o, d in loc.values() if d <= ALIGNED] or [0]
split = next((w0 for w0, (o, d) in sorted(loc.items()) if d > ALIGNED and w0 > start + 600), None)   # past the loading screens
print(f'{out}: offset {off} ({off / 60:+.2f} s), aligned drift {min(dr):+d}..{max(dr):+d} end {dr[-1]:+d} frames, from {start / 60:.1f} s, '
      f'first split {split / 60 if split is not None else -1:.0f} s, aligned {len(m)}/{len(rows)} frames, LPIPS {m[:, 0].mean():.3f} DISTS {m[:, 1].mean():.3f} SSIM {m[:, 2].mean():.3f}')
