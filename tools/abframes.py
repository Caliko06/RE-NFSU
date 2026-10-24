"""Frames of two recordings side by side (A/B against the Wine reference, tools/wine/rec.sh + webcheck RN_REC).
usage: abframes.py A.mp4 B.mp4 OUT.png OFFSET T1 T2 ...   (left = A at Tn, right = B at Tn + OFFSET; 400x300 each)
       abframes.py A.mp4 - OUT.png 0 T1 T2 ...            (a grid of A only, 6 per row: find the moment to align on)"""
import subprocess, sys
from PIL import Image, ImageDraw
a, b, out, off = sys.argv[1], sys.argv[2], sys.argv[3], float(sys.argv[4])
ts = [float(t) for t in sys.argv[5:]]
def frame(v, t):
    raw = subprocess.run(['ffmpeg', '-loglevel', 'error', '-ss', str(t), '-i', v, '-frames:v', '1', '-vf', 'scale=400:300',
                          '-f', 'rawvideo', '-pix_fmt', 'rgb24', '-'], capture_output=True).stdout
    im = Image.frombytes('RGB', (400, 300), raw) if len(raw) == 400 * 300 * 3 else Image.new('RGB', (400, 300))
    ImageDraw.Draw(im).text((6, 4), f'{t:.1f}', fill=(255, 255, 0))
    return im
if b == '-':
    cols = 6
    sheet = Image.new('RGB', (400 * cols, 300 * ((len(ts) + cols - 1) // cols)))
    for i, t in enumerate(ts):
        sheet.paste(frame(a, t), (400 * (i % cols), 300 * (i // cols)))
else:
    sheet = Image.new('RGB', (800, 300 * len(ts)))
    for i, t in enumerate(ts):
        sheet.paste(frame(a, t), (0, 300 * i)); sheet.paste(frame(b, t + off), (400, 300 * i))
sheet.save(out)
