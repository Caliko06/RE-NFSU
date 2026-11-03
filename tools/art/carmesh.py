"""Read solids (name, textures, materials, groups, vertices, triangles) of a car's GEOMETRY.BIN (docs/re/car_assets.md)."""
import os, struct, sys
import numpy as np
B = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.append(os.path.join(B, "tools", "re"))  # append: tools/re/ast.py would shadow the stdlib
import chunks, carinfo

CARSKIN = 0xD6D6080A


def bh(s):
    return carinfo.bh(s.encode())


def _ch(d, o, e):
    while o + 8 <= e:
        t, s = struct.unpack_from("<II", d, o)
        yield t, o, s
        o += 8 + s


def solids(car):
    """Yield dicts: name, tex (hash list), mat (hash list), groups [(vcount?, tex idx, mat idx, first, count)], V (n,9 array), idx (u16 array)."""
    d = chunks.load(os.path.join(B, "game", "Cars", car, "GEOMETRY.BIN"))
    for t, o, s in _ch(d, 0, len(d)):
        if t != 0x80134000:
            continue
        for t2, o2, s2 in _ch(d, o + 8, o + 8 + s):
            if t2 != 0x80134010:
                continue
            c = {t3: (o3, s3) for t3, o3, s3 in _ch(d, o2 + 8, o2 + 8 + s2)}
            if 0x134011 not in c or 0x80134100 not in c:
                continue
            h = c[0x134011][0] + 8
            name = d[h + 0x94:h + 0x94 + 64].split(b"\0")[0].decode("latin1")
            nh = struct.unpack_from("<I", d, h + 0x10)[0]
            if len(name) >= 27:                   # name field is 28 bytes: the last letter (LOD) may be cut; hash tells
                for L in "ABCD":
                    if bh(name + L) == nh:
                        name += L
            ntex, nmat = d[h + 0x19], d[h + 0x1a]
            tt = c[0x134012][0] + 8 if 0x134012 in c else 0
            mt = c[0x134013][0] + 8 if 0x134013 in c else 0
            tex = [struct.unpack_from("<I", d, tt + 8 * i)[0] for i in range(ntex)]
            mat = [struct.unpack_from("<I", d, mt + 8 * i)[0] for i in range(nmat)]
            m = c[0x80134100]
            sub = {t4: (o4, s4) for t4, o4, s4 in _ch(d, m[0] + 8, m[0] + 8 + m[1])}
            if 0x134b01 not in sub or 0x134b02 not in sub or 0x134b03 not in sub:
                continue
            vb, ga, ib = sub[0x134b01], sub[0x134b02], sub[0x134b03]
            grp = []
            gpad = ga[1] % 60                      # group array is front-padded with 0x11111111 words
            for i in range(ga[1] // 60):
                r = ga[0] + 8 + gpad + 60 * i
                cnt = struct.unpack_from("<I", d, r + 12)[0]
                ti, mi = struct.unpack_from("<II", d, r + 0x1c)
                first = struct.unpack_from("<I", d, r + 0x34)[0]
                grp.append((ti, mi, first, cnt))
            vend = vb[0] + 8 + vb[1]
            vbo = vb[0] + 8                          # payload is front-padded with 0x11111111 words
            while vbo < vend and struct.unpack_from("<I", d, vbo)[0] == 0x11111111:
                vbo += 4
            nv, rem = divmod(vend - vbo, 36)
            if rem:                                  # other vertex layout (seen on some LOD C/D parts): skip, but never a KIT00 A part
                assert not (name.endswith("_A") and "_KIT00_" in name), (car, name, rem)
                continue
            V = np.frombuffer(d, dtype=np.dtype([("p", "<f4", 3), ("n", "<f4", 3), ("c", "<u4"), ("uv", "<f4", 2)]), count=nv, offset=vbo)
            nidx = sum(g[3] for g in grp)
            iend = ib[0] + 8 + ib[1]
            idx = np.frombuffer(d, dtype="<u2", count=nidx, offset=iend - 2 * nidx)
            yield dict(name=name, tex=tex, mat=mat, groups=grp, V=V, idx=idx)
