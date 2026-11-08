#!/bin/bash
# Pod side of the world texture remaster (same method as the cars, HANDOFF block 2):
#   us = 4x-UltraSharp after 1x-BCGone-Smooth deblock; db = deblock only.
#   score.py gate FLOOR=28: a file under 28 dB takes the soft fallback (db + Lanczos x4), the GAN draws lines there.
# Input /root/remaster/{world/, world.lst}, models in /root/remaster/m. Output /root/remaster/world_out.
# Fresh pod (disposable; the old pod setup script is not kept; install as below):
#   python3 -m venv /root/remaster/venv && venv/bin/pip install torch torchvision --index-url https://download.pytorch.org/whl/cu128
#   venv/bin/pip install spandrel pillow numpy
#   m/4x-UltraSharp.pth   https://huggingface.co/lokCX/4x-Ultrasharp/resolve/main/4x-UltraSharp.pth
#   m/1x-BCGone-Smooth.pth https://drive.google.com/uc?export=download&confirm=1&id=1EYAoxC1tE2EhEgI4tiKujHUKjhq68gY- (openmodeldb)
# Mac side: decode_world.py -> world/ + world.tsv; world.lst = sides >= 32 and < 1024. Ship: cap 1024, WebP q90 into
# web/remaster/world/, index_world.tsv (<key>\tworld/<key>.webp). ?worldhd=1 turns it on. Road textures (RD*) are in since
# 2026-10-23: the earlier "RD_ARROYOCONC_* lose the car reflection" A/B was capture timing (the reflection depends on the
# camera); those 7 are never uploaded in the Olympic Square race (RN_TEXHASH), 24 of the 41 RD* are.
set -euo pipefail
cd /root/remaster; PY=/root/remaster/venv/bin/python; M=/root/remaster/m
# sr.py is CPU-bound per file (PNG io, small tiles): 6 shards per pass keep the GPU busy. Files already in us/ or db/ are skipped.
for pass in us db; do
  ls $pass 2>/dev/null > done.$pass || true
  grep -vxFf done.$pass world.lst > todo.$pass || true
  split -n l/6 todo.$pass shard.$pass.
  for s in shard.$pass.*; do
    if [ $pass = us ]; then $PY sr.py $s world us m/4x-UltraSharp.pth m/1x-BCGone-Smooth.pth > $s.log 2>&1 &
    else $PY sr.py $s world db m/1x-BCGone-Smooth.pth - > $s.log 2>&1 & fi
  done; wait; rm -f shard.$pass.* todo.$pass done.$pass
done
FLOOR=28 $PY score.py world us
$PY - <<'EOF'
import os, shutil
from PIL import Image
os.makedirs('world_out', exist_ok=True)
below = {l.split('\t')[0] for l in open('us.below')} if os.path.exists('us.below') else set()
for f in open('world.lst').read().split():
    if f in below:
        d = Image.open(f'db/{f}').convert('RGBA'); o = Image.open(f'world/{f}')
        d.resize((o.width * 4, o.height * 4), Image.LANCZOS).save(f'world_out/{f}')
    else: shutil.copy(f'us/{f}', f'world_out/{f}')
print('world_out', len(os.listdir('world_out')), 'soft', len(below))
EOF
echo WORLD-DONE
