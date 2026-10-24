#!/bin/bash
# Pod side of remaster pack v2 (OWNER 2026-10-24): every unique world texture (STREAML1R*.BUN) and the car pack
# (web/remaster/index.tsv), 1x-BCGone-Smooth deblock then 4x-UltraSharpV2 in fp32; score.py FLOOR=28 sends a file under
# 28 dB to the soft fallback (deblock + Lanczos x4). Ships WebP (ship_webp.py) and deletes the PNGs of each stage.
# Models: /root/rm2/m (4x-UltraSharpV2.safetensors from RE-NFSMW, 1x-BCGone-Smooth.pth). venv: RE-NFSMW upvenv.
# Output /root/rm2/out/{world2,cars2}/<hash>.webp + index_world_v2.tsv, index_v2.tsv. usage: pack_v2.sh [SHARDS]
set -euo pipefail
R=/root/RE-NFSU; W=/root/rm2; PY=/root/RE-NFSMW/build/upvenv/bin/python; T=$R/tools/remaster; N=${1:-3}
export OMP_NUM_THREADS=${OMP_NUM_THREADS:-2}
cd $W
[ -f world.tsv ] || $PY $T/decode_world.py $W/world $R/game/Tracks/STREAML1R*.BUN
[ -d cars ] || { mkdir -p cars; $PY $T/decode_all.py $W/cars; }
for set in world cars; do
  [ -f $set.lst ] || $PY - $set <<'PY'
import os, sys
from PIL import Image
s = sys.argv[1]; keep = []
for f in sorted(os.listdir(s)):
    w, h = Image.open(f'{s}/{f}').size
    if min(w, h) >= 32 and max(w, h) < 1024: keep.append(f)
open(f'{s}.lst', 'w').write('\n'.join(keep) + '\n'); print(s, len(keep), 'of', len(os.listdir(s)))
PY
  for pass in us db; do
    mkdir -p $set.$pass; ls $set.$pass > done.$pass; grep -vxFf done.$pass $set.lst > todo.$pass || true
    split -n l/$N todo.$pass shard.$pass.
    for s in shard.$pass.*; do
      if [ $pass = us ]; then $PY $T/sr.py $s $set $set.us m/4x-UltraSharpV2.safetensors m/1x-BCGone-Smooth.pth > $s.$set.log 2>&1 &
      else $PY $T/sr.py $s $set $set.db m/1x-BCGone-Smooth.pth - > $s.$set.log 2>&1 & fi
    done; wait; rm -f shard.$pass.* todo.$pass done.$pass
  done
  FLOOR=28 $PY $T/score.py $set $set.us | tee $set.score
  $PY - $set <<'PY'
import os, sys, shutil
from PIL import Image
s = sys.argv[1]; os.makedirs(f'{s}.fin', exist_ok=True)
below = {l.split('\t')[0] for l in open(f'{s}.us.below')}
for f in open(f'{s}.lst').read().split():
    if f in below:   # RGB and alpha apart (Pillow resizes RGBA premultiplied: see ship_webp.py)
        d = Image.open(f'{s}.db/{f}'); o = Image.open(f'{s}/{f}'); size = (o.width * 4, o.height * 4)
        Image.merge('RGBA', (*d.convert('RGB').resize(size, Image.LANCZOS).split(), o.getchannel('A').resize(size, Image.LANCZOS))).save(f'{s}.fin/{f}')
    else: shutil.move(f'{s}.us/{f}', f'{s}.fin/{f}')
print(s, 'fin', len(os.listdir(f'{s}.fin')), 'soft', len(below))
PY
  rm -rf $set.us $set.db
  $PY $T/ship_webp.py $set.fin out/$set.webp && rm -rf $set.fin
done
# Index: world by content hash; cars <CAR>_<key>.png -> the hash of index.tsv (same lookup as png/<key>.png today).
$PY - <<'PY'
import os
o = '/root/rm2/out'
os.rename(f'{o}/world.webp', f'{o}/world2'); os.rename(f'{o}/cars.webp', f'{o}/cars2')
open(f'{o}/index_world_v2.tsv', 'w').write(''.join(f'{f[:-5]}\tworld2/{f}\n' for f in sorted(os.listdir(f'{o}/world2'))))
h = {(l.split('\t')[5].strip(), l.split('\t')[1]): l.split('\t')[0] for l in open('/root/RE-NFSU/web/remaster/index.tsv')}
rows = []
for f in sorted(os.listdir(f'{o}/cars2')):
    car, key = f[:-5].rsplit('_', 1); hh = h[(car, key)]
    os.rename(f'{o}/cars2/{f}', f'{o}/cars2/{hh}.webp'); rows.append(f'{hh}\tcars2/{hh}.webp\n')
open(f'{o}/index_v2.tsv', 'w').write(''.join(rows)); print('index', len(rows), 'cars,', len(os.listdir(f'{o}/world2')), 'world')
PY
echo PACK-V2-DONE
