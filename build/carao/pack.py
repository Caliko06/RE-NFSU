# out/final/*.npz,tsv -> carao.bin, the file the host reads. Little endian:
#   "CAO1", u32 n; n x { u64 key, u32 nv, u32 offset }  (sorted by key); blob of u8 AO (255 = open, 0 = closed), offset from the blob start.
# key = FNV-1a 64 over the 12 position bytes of vertices 0..nv-1 of a solid (the runtime draws are whole solids: slices.py, 5067/5067).
# Lens parts (HEADLIGHT / BRAKELIGHT) are written as 255: their AO is the housing, not shadow on paint.
# OWNER 2026-10-29: the look must not get darker overall, only gain depth in creases. Occlusion d = 1 - ao below CUT (open paint, flat panels)
# is dropped, the rest is stretched to 0..1: mean AO of the exterior stays ~0.97. BASE_* (interior, underside) and lenses are 255.
import glob, os, re, struct, numpy as np
CUT = 0.15
ent = {}; coll = 0
for f in sorted(glob.glob('out/final/*.npz')):
    car = os.path.basename(f)[:-4]; z = np.load(f)
    for line in open(f'out/final/{car}.tsv'):
        n, nv, h = line.rstrip('\n').split('\t'); a = z[n]
        if re.search(r'HEADLIGHT|BRAKELIGHT|^BASE_', n): a = np.full_like(a, 255)
        else: a = np.round(255 * (1 - np.clip(((255 - a.astype(np.float32)) / 255 - CUT) / (1 - CUT), 0, 1))).astype(np.uint8)
        k = int(h, 16)
        if k in ent and not np.array_equal(ent[k], a): coll += 1
        ent[k] = a
keys = sorted(ent); off = 0; tab = b''; blob = b''
for k in keys: tab += struct.pack('<QII', k, len(ent[k]), off); blob += ent[k].tobytes(); off += len(ent[k])
open('carao.bin', 'wb').write(b'CAO1' + struct.pack('<I', len(keys)) + tab + blob)
print(len(keys), 'solids', off, 'verts', os.path.getsize('carao.bin') // 1024, 'KB; key clashes with different AO:', coll)
