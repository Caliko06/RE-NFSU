# Speed.exe for the Wine reference, from tools/recomp/patches.py.
# Default: only PATCH 0x4f5891 (no MOVIES\ in game/). --set parity: every active PATCH, as ours has them, for one screen
# size WxH (4:3 or narrower). Wine has no layer to write SCREEN_ADDR 0x13000, so the reads of the size there become
# immediates (same bytes count), the 2D scale PATCHes 0x40bf.. are left out (they are the identity at 4:3), and the seed
# PATCH 0x4470f0 is `mov edi,K; jmp 0x447110` with K from --seed (ours reads K from 0x13010 through the cave 0x408814).
import argparse, os, sys, pefile
sys.path.insert(0, '/Users/angeldamian/RE-NFSU/tools/recomp')
import patches
ap = argparse.ArgumentParser(usage="mkexe.py OUTDIR [--set parity --seed K --screen WxH --autopilot]  (outside the repo: Speed.exe is the OWNER's file)")
ap.add_argument('out'); ap.add_argument('--set', choices=['parity']); ap.add_argument('--seed', type=lambda s: int(s, 0))
ap.add_argument('--screen', default='1280x960')
ap.add_argument('--autopilot', action='store_true', help='PATCH 0x42d4b0 as mov dl,1: the AI drives the player')
a = ap.parse_args()
pe = pefile.PE('/Users/angeldamian/RE-NFSU/pc/Speed.exe')
data = bytearray(open('/Users/angeldamian/RE-NFSU/pc/Speed.exe', 'rb').read())

def screen(p):   # the new bytes hold an address in SCREEN_ADDR .. +0x1f
    n = bytes.fromhex(p['new'])
    return any(0x13000 <= int.from_bytes(n[i:i + 4], 'little') < 0x13020 for i in range(len(n) - 3))

if a.set == 'parity':
    if not a.seed: sys.exit('--set parity needs --seed K (K != 0, the same RN_SEED as ours)')
    img = pe.get_memory_mapped_image()
    bss = [p for p in patches.active() if p['addr'] - 0x400000 >= len(img) or pe.get_offset_from_rva(p['addr'] - 0x400000) >= len(data)]
    W, H = map(int, a.screen.split('x'))
    if 3 * W > 4 * H: sys.exit('--screen must be 4:3 or narrower: the 2D scale PATCHes 0x40bf.. are left out')
    def imm(p):   # mov eax,[0x13000] -> mov eax,W; mov esi,[0x13004] -> mov esi,H; nop; push [0x13000] -> push W; nop
        n = bytes.fromhex(p['new'])
        for o, r in ((b'\xa1\x00\x30\x01\x00', b'\xb8' + W.to_bytes(4, 'little')),
                     (b'\x8b\x35\x04\x30\x01\x00', b'\xbe' + H.to_bytes(4, 'little') + b'\x90'),
                     (b'\xff\x35\x00\x30\x01\x00', b'\x68' + W.to_bytes(4, 'little') + b'\x90')):
            n = n.replace(o, r)
        if p['addr'] == 0x42d4b0: n = bytes.fromhex('b20190909090' if a.autopilot else p['old'])
        return dict(p, new=n.hex())
    ps = [imm(p) for p in patches.active() if p not in bss]
    ps = [p for p in ps if not screen(p) and p["addr"] != 0x4470f0]   # ours jumps to the cave 0x408814 there
    # The seed block replaces the 32 bytes 0x4470f0..0x44710f (QPC path; 0x4470d0 runs once, from the boot 0x4471b0):
    # mov byte [a],b for each .bss PATCH byte (the file cannot hold them), mov edi,K, jmp 0x447110.
    code = b''.join(b'\xc6\x05' + (p['addr'] + i).to_bytes(4, 'little') + bytes([v])
                    for p in bss for i, v in enumerate(bytes.fromhex(p['new'])))
    code += b'\xbf' + a.seed.to_bytes(4, 'little')
    code += b'\xeb' + bytes([0x447110 - (0x4470f0 + len(code) + 2)])
    assert len(code) <= 32
    ps.append(dict(addr=0x4470f0, old=img[0x470f0:0x47110].hex(), new=(code + b'\x90' * (32 - len(code))).hex()))
    print('.bss PATCHes written by the seed block:', ' '.join(f"{p['addr']:#x}" for p in bss))
    print('left out (read 0x13000):', ' '.join(f"{p['addr']:#x}" for p in patches.active() if screen(imm(p))))
else:
    ps = [p for p in patches.PATCHES if p['addr'] == 0x4f5891]
for p in ps:
    off = pe.get_offset_from_rva(p['addr'] - 0x400000)
    old, new = bytes.fromhex(p['old']), bytes.fromhex(p['new'])
    if off >= len(data):   # .bss past the raw data: cannot be patched in the file
        sys.exit(f"PATCH {p['addr']:#x} lies in .bss")
    assert data[off:off + len(old)] == old, hex(p['addr'])
    data[off:off + len(new)] = new
open(os.path.join(a.out, 'Speed.exe'), 'wb').write(data)
open(os.path.join(a.out, 'nfsu.reg'), 'w').write(
    'REGEDIT4\n\n[HKEY_LOCAL_MACHINE\\Software\\EA Games\\Need For Speed Underground]\n'
    '"Install Dir"="C:\\\\NFSU\\\\"\n"CD Drive"="D:\\\\"\n"Language"="English UK"\n"CacheSize"="1296003"\n"SwapSize"="0"\n')
print('patched', len(ps), 'sites:', ' '.join(f"{p['addr']:#x}" for p in ps))
