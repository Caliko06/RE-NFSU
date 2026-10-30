# GEOMETRY.BIN of a car (EA BIN chunks) -> solids. Solid = chunk 80134010: 00134011 header (+0x94 name), 80134100 holding
# 00134900 (+0x24 ntri, +0x34 nvert), 00134b01 (0x38 pad, nvert * 36-byte vertices: pos f32x3 first), 00134b02 (3 floats bbox min, u32 index count,
# 3 floats bbox max ... records of 0x3c: count@+0xc, material@+0x20, first index@+0x34), 00134b03 (4 pad bytes, u16 triangle list).
# The vertex bytes are the ones the game's D3D vertex buffer holds (checked: runtime draw vertices found in the file at stride 36).
import struct, numpy as np
def chunks(b, o, e):
    while o + 8 <= e:
        t, s = struct.unpack_from('<II', b, o)
        yield t, o + 8, s
        o += 8 + s
def solids(path):
    b = open(path, 'rb').read(); out = []
    for t, o, s in chunks(b, 0, len(b)):
        if t != 0x80134000: continue
        for t2, o2, s2 in chunks(b, o, o + s):
            if t2 != 0x80134010: continue
            ch = {t3: (o3, s3) for t3, o3, s3 in chunks(b, o2, o2 + s2)}
            h = ch.get(0x00134011); m = ch.get(0x80134100)
            if not h or not m: continue
            name = b[h[0] + 0x94: h[0] + 0x94 + 64].split(b'\0')[0].decode('latin1')
            sub = {t3: (o3, s3) for t3, o3, s3 in chunks(b, m[0], m[0] + m[1])}
            if 0x00134b01 not in sub: continue
            hw = struct.unpack_from('<%dI' % (sub[0x134900][1] // 4), b, sub[0x134900][0]); k = next(i for i, w in enumerate(hw) if w != 0x11111111)   # header after its 0x11 pad: ntri word 9, nvert word 13
            nt, nv = hw[k + 9], hw[k + 13]
            o1, s1 = sub[0x134b01]; v = np.frombuffer(b, np.uint8, nv * 36, o1 + s1 - nv * 36).reshape(nv, 36)
            pos = v[:, :12].copy().view('<f4').reshape(nv, 3)
            o3_, s3_ = sub[0x134b03]; idx = np.frombuffer(b, '<u2', 3 * nt, o3_ + s3_ - 6 * nt)
            o2_, s2_ = sub[0x134b02]
            while s2_ >= 4 and struct.unpack_from('<I', b, o2_)[0] == 0x11111111: o2_ += 4; s2_ -= 4   # pad words
            rec = [struct.unpack_from('<IIII', b, o2_ + 0x3c * k + 0xc)[0] for k in range(s2_ // 0x3c)]
            mats = [(struct.unpack_from('<I', b, o2_ + 0x3c * k + 0x20)[0], struct.unpack_from('<I', b, o2_ + 0x3c * k + 0x34)[0], rec[k]) for k in range(s2_ // 0x3c)]
            out.append(dict(name=name, nt=nt, nv=nv, pos=pos, vb=v, idx=idx, mats=mats, tag=t2))
    return out
if __name__ == '__main__':
    import sys
    for s in solids(sys.argv[1]): print(s['name'], s['nv'], s['nt'], len(s['idx']) // 3, s['mats'], s['pos'].min(0).round(2), s['pos'].max(0).round(2))
