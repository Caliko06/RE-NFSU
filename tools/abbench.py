#!/usr/bin/env python3
# A/B bench: the same race frame with N variants of URL switches, in one labelled strip, with the GPU time of each.
# One run per variant: same seed, the game's autopilot, RN_JUMP to one Quick Race, RN_FIXEDCLOCK (host/win32.c: frame time and RNG fixed
# from the first race HUD), ?hold=N stops at race frame N (web/gpu.js). Measured noise of two identical runs: --frame 300 (the
# default: the grid before GO) is the same frame, only the crowd moves (7 % of pixels, mean delta 1.5/255). --frame 900 (racing) is the same
# road and speed but not the same pixels: race clock 7.02 vs 7.28 s, the rivals elsewhere. Compare looks at 300; at 900 only coarse things.
# Times: ?gpuprof=1, race frames 120..N. Trust "by pass" and "sum" (ms per pass kind, stable to about 0.05 ms per post pass; the draws move more,
# the crowd is in them). p50/p90 are first pass start to last pass end and jump between identical runs on the pod's 4090 (0.5 vs 1.9 ms).
# usage: tools/abbench.py NAME [--frame 300] [--jump 0:1003] [--view 1920x1080@1] [--repeat] [--crop X,Y,W,H] label=query ...
#   e.g. tools/abbench.py grade off=grade=0 on=
#        tools/abbench.py cam base= far='chasecam=2&grade=0'
# --repeat runs the first variant twice: the pixels that change are the noise floor of "same frame".
# Output: build/ab/NAME/<label>.png, strip.jpg, results.json. Needs save/ (the "asas" profile; `cp -r /root/src/save save` on the pod).
# Pod: DISPLAY=:91 RN_X11=1 RN_CHROME=/usr/bin/google-chrome; the Mac needs neither. Uses its own server on this worktree's files.
import argparse, fcntl, json, os, re, socket, subprocess, sys
from completion import _PROFILE
import numpy as np
from PIL import Image, ImageDraw, ImageFont

ap = argparse.ArgumentParser()
ap.add_argument('name'); ap.add_argument('variants', nargs='+', help='label=query')
ap.add_argument('--frame', type=int, default=300); ap.add_argument('--jump', default='0:1003')
ap.add_argument('--view', default='1920x1080@1'); ap.add_argument('--repeat', action='store_true')
ap.add_argument('--crop', help='X,Y,W,H of the frame for the strip'); ap.add_argument('--secs', type=int, default=150)
a = ap.parse_args()
if not os.path.isdir('save'): sys.exit('no save/: the route needs the profile (pod: cp -r /root/src/save save)')
out = f'build/ab/{a.name}'
os.makedirs(out, exist_ok=True)
variants = [v.split('=', 1) for v in a.variants]
if any(len(v) != 2 for v in variants): sys.exit('each variant is label=query')
if a.repeat: variants.insert(1, [variants[0][0] + '_again', variants[0][1]])

# One bench at a time on this machine: another run's GPU work would count in these times.
lock = open(os.path.join(os.environ.get('TMPDIR', '/tmp'), 'abbench.lock'), 'w')
fcntl.flock(lock, fcntl.LOCK_EX)
with socket.socket() as s:
    s.bind(('127.0.0.1', 0)); port = s.getsockname()[1]
serve = subprocess.Popen([sys.executable, 'tools/serve.py', str(port)], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
nav = ','.join(['20000:RETURN'] + _PROFILE[1:] + ['1500@=MU_Main_PC:RETURN'])

def run(label, query):
    url = (f'http://127.0.0.1:{port}/?env=RN_SEED=0x1234,RN_AUTOPILOT=1,RN_FIXEDCLOCK=1&jump={a.jump}&keys={nav}&hold={a.frame}&gpuprof=1'
           + (f'&{query}' if query else ''))
    env = dict(os.environ, RN_VIEW=a.view, RN_UNTIL=r'held at race frame.*gpu ts@1', RN_CDP_PORT=os.environ.get('RN_CDP_PORT', '9481'))
    png = f'{out}/{label}.png'
    subprocess.run(['node', 'tools/webcheck.mjs', url, str(a.secs), png], env=env, stdout=subprocess.DEVNULL, stderr=subprocess.STDOUT)
    log = open('build/webcheck.log', errors='replace').read()
    if 'STOP' in log: sys.exit(f'{label}: the game stopped: ' + ''.join(l for l in log.splitlines(True) if 'STOP' in l))
    m = re.search(r'held at race frame (\d+).*?gpu ts p50 ([\d.]+) p90 ([\d.]+) max ([\d.]+) ms(?:; per frame: ([^;]*))?', log)
    if not m: sys.exit(f'{label}: no held frame in {a.secs} s (see build/webcheck.log)')
    passes = {p.rsplit(' ', 1)[0]: float(p.rsplit(' ', 1)[1].split(' ')[0]) for p in re.findall(r'[^,]+? [\d.]+(?= ms/)', m[5] or '')}
    return dict(label=label, query=query, frame=int(m[1]), p50=float(m[2]), p90=float(m[3]), max=float(m[4]),
                passes={k.strip(): v for k, v in passes.items()}, png=png)

try:
    res = [run(*v) for v in variants]
finally:
    serve.terminate()

imgs = [Image.open(r['png']).convert('RGB') for r in res]
base = np.asarray(imgs[0]).astype(int)
for r, im in zip(res, imgs):
    d = np.abs(np.asarray(im).astype(int) - base).max(2) if im.size == imgs[0].size else None
    r['changed_pct'] = None if d is None else round(100 * float((d > 2).mean()), 2)
    r['mean_delta'] = None if d is None else round(float(d.mean()), 2)
json.dump(res, open(f'{out}/results.json', 'w'), indent=1)

if a.crop:
    x, y, w, h = map(int, a.crop.split(','))
    imgs = [im.crop((x, y, x + w, y + h)) for im in imgs]
W = min(1920 // len(imgs) * 2, imgs[0].width); H = imgs[0].height * W // imgs[0].width
strip = Image.new('RGB', (W * len(imgs), H + 34), (12, 12, 14))
draw = ImageDraw.Draw(strip)
try: font = ImageFont.load_default(size=22)
except TypeError: font = ImageFont.load_default()
for i, (r, im) in enumerate(zip(res, imgs)):
    strip.paste(im.resize((W, H), Image.LANCZOS), (W * i, 34))
    draw.text((W * i + 8, 5), f"{r['label']}  gpu p50 {r['p50']} p90 {r['p90']} ms", fill=(255, 212, 121), font=font)
strip.save(f'{out}/strip.jpg', quality=92)

print(f'{"variant":16} {"frame":>5} {"p50":>6} {"p90":>6} {"max":>6} {"sum":>6} {"px>2 %":>7} {"mean":>6}  query')
for r in res:
    print(f'{r["label"]:16} {r["frame"]:5} {r["p50"]:6.1f} {r["p90"]:6.1f} {r["max"]:6.1f} {sum(r["passes"].values()):6.2f} {r["changed_pct"]!s:>7} {r["mean_delta"]!s:>6}  {r["query"]}')
for r in res[1:]:
    keys = sorted(set(r['passes']) | set(res[0]['passes']), key=lambda k: -abs(r['passes'].get(k, 0) - res[0]['passes'].get(k, 0)))[:5]
    print(f'{r["label"]} vs {res[0]["label"]}, ms per frame by pass: ' + ', '.join(f'{k} {r["passes"].get(k, 0) - res[0]["passes"].get(k, 0):+.2f}' for k in keys))
print(f'{out}/strip.jpg')
