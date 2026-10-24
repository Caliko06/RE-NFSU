# Speed.exe for the Wine reference: only PATCH 0x4f5891 (no MOVIES\ in game/), applied from tools/recomp/patches.py.
import sys, os, pefile
sys.path.insert(0, '/Users/angeldamian/RE-NFSU/tools/recomp')
import patches
if len(sys.argv) != 2: sys.exit('usage: mkexe.py OUTDIR  (outside the repo: Speed.exe is the OWNER\'s file)')
out = sys.argv[1]
pe = pefile.PE('/Users/angeldamian/RE-NFSU/pc/Speed.exe')
data = bytearray(open('/Users/angeldamian/RE-NFSU/pc/Speed.exe', 'rb').read())
p = [x for x in patches.PATCHES if x['addr'] == 0x4f5891][0]
off = pe.get_offset_from_rva(p['addr'] - 0x400000)
old, new = bytes.fromhex(p['old']), bytes.fromhex(p['new'])
assert data[off:off + len(old)] == old
data[off:off + len(new)] = new
open(os.path.join(out, 'Speed.exe'), 'wb').write(data)
open(os.path.join(out, 'nfsu.reg'), 'w').write(
    'REGEDIT4\n\n[HKEY_LOCAL_MACHINE\\Software\\EA Games\\Need For Speed Underground]\n'
    '"Install Dir"="C:\\\\NFSU\\\\"\n"CD Drive"="D:\\\\"\n"Language"="English UK"\n"CacheSize"="1296003"\n"SwapSize"="0"\n')
print('patched at file offset', hex(off))
