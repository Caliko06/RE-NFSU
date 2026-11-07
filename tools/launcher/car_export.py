"""Export an NFSU1 car (game/Cars/<CAR>/GEOMETRY.BIN + TEXTURES.BIN, shared game/Cars/TEXTURES.BIN,
WHEELS/, BRAKES/) to one self-contained glTF binary + a small meta JSON for the three.js launcher.

Reads (bChunk family, little endian; layout verified on SKYLINE bytes, ported from ref/_ext/PryHUB gizmo-nfs):
  GEOMETRY.BIN  0x80134000 > 0x80134010 solids: 0x134011 header (name, 4x4 matrix @+64),
                0x134012 hash list, 0x80134100 > 0x134900 counts, 0x134B01 vertices (36 B: pos, normal, BGRA, uv),
                0x134B02 material ranges (60 B), 0x134B03 u16 triangle list. Padding = 0x11 bytes.
  TEXTURES.BIN  0xB3300000 TPK: 0x33310002 hashes, 0x33310003 20 B (hash, offset, size), 0x33310004 124 B info
                (name, hash, w/h, DXT1/3/5 or 32-bit), blobs are JDLZ-compressed.
Run: .venv/bin/python -I tools/launcher/car_export.py SKYLINE web/launcher/v3
"""
import json, re, struct, sys

import numpy as np
from io import BytesIO
from PIL import Image

# ---------------------------------------------------------------- chunks
def kids(d, o, e):
    """Yield (id, payload_start, size) of the chunks in d[o:e]; id 0 = padding."""
    while o + 8 <= e:
        t, s = struct.unpack_from('<II', d, o)
        if t:
            yield t, o + 8, s
        o += 8 + s

# ---------------------------------------------------------------- JDLZ (port of gizmo-nfs compression/jdlz.rs)
def jdlz(buf):
    assert buf[:4] == b'JDLZ', 'not JDLZ: %r' % bytes(buf[:4])
    n = struct.unpack_from('<I', buf, 8)[0]
    out = bytearray()
    p, f1, f2, L = 16, 1, 1, len(buf)
    while p < L and len(out) < n:
        if f1 == 1:
            f1 = buf[p] | 0x100; p += 1
        if f2 == 1:
            f2 = buf[p] | 0x100; p += 1
        if f1 & 1:
            b0, b1 = buf[p], buf[p + 1]; p += 2
            if f2 & 1:
                ln, dist = ((b0 & 0xF0) << 4 | b1) + 3, (b0 & 0x0F) + 1
            else:
                ln, dist = (b0 & 0x1F) + 3, (b1 | (b0 & 0xE0) << 3) + 17
            s = len(out) - dist
            for i in range(min(ln, n - len(out))):
                out.append(out[s + i])
            f2 >>= 1
        else:
            out.append(buf[p]); p += 1
        f1 >>= 1
    return bytes(out)

# ---------------------------------------------------------------- TPK (NFSU1 layout)
class Tex:
    def __init__(self, name, hash_, w, h, comp, off, size, isz):
        self.name, self.hash, self.w, self.h, self.comp = name, hash_, w, h, comp
        self.off, self.size, self.isz = off, size, isz

def read_tpk(path):
    d = open(path, 'rb').read()
    ch = {}
    def walk(o, e):
        for t, p, s in kids(d, o, e):
            ch.setdefault(t, (p, s))
            if t & 0x80000000:
                walk(p, p + s)
    walk(0, len(d))
    texs = {}
    if 0x33310003 not in ch:
        return d, texs
    p3, s3 = ch[0x33310003]; p4, _ = ch[0x33310004]
    for i in range(s3 // 20):
        h, off, size = struct.unpack_from('<3I', d, p3 + i * 20)
        r = p4 + i * 124
        name = d[r + 12:r + 36].split(b'\0')[0].decode('latin1')
        hh, = struct.unpack_from('<I', d, r + 0x24)
        isz, = struct.unpack_from('<I', d, r + 0x38)
        w, ht = struct.unpack_from('<HH', d, r + 0x44)
        texs[h] = Tex(name, h, w, ht, d[r + 0x4a], off, size, isz)
        assert hh == h
    return d, texs

def decode_tex(d, t):
    """Top mip of a texture as an RGBA PIL image."""
    blob = d[t.off:t.off + t.size]
    px = jdlz(blob) if blob[:4] == b'JDLZ' else blob
    if t.comp == 0x20:                      # 32-bit, stored B,G,R,A
        a = np.frombuffer(px, np.uint8, t.w * t.h * 4).reshape(t.h, t.w, 4)[..., [2, 1, 0, 3]]
        return Image.fromarray(np.ascontiguousarray(a), 'RGBA')
    fourcc = {0x22: b'DXT1', 0x24: b'DXT3', 0x26: b'DXT5'}[t.comp]
    # wrap as a one-mip DDS so PIL's BCn decoder does the work
    hdr = b'DDS ' + struct.pack('<7I44x', 124, 0x81007, t.h, t.w, 0, 0, 1) \
        + struct.pack('<II4s5I', 32, 4, fourcc, 0, 0, 0, 0, 0) + struct.pack('<5I', 0x1000, 0, 0, 0, 0)
    im = Image.open(BytesIO(hdr + px)); im.load()
    return im.convert('RGBA')

# ---------------------------------------------------------------- GEOMETRY.BIN
class Solid:
    pass

def read_geometry(path):
    d = open(path, 'rb').read()
    out = []
    for t, p, s in kids(d, 0, len(d)):
        if t != 0x80134000:
            continue
        for t2, p2, s2 in kids(d, p, p + s):
            if t2 != 0x80134010:
                continue
            c = {}
            for t3, p3, s3 in kids(d, p2, p2 + s2):
                c[t3] = (p3, s3)
                if t3 == 0x80134100:
                    for t4, p4, s4 in kids(d, p3, p3 + s3):
                        c[t4] = (p4, s4)
            if 0x134b01 not in c or 0x134b03 not in c or 0x134900 not in c:
                continue
            S = Solid()
            hp, hs = c[0x134011]; hdr = d[hp:hp + hs]
            S.name = max(re.findall(rb'[\x21-\x7e]+', hdr[0x40 + 64:]), key=len).decode()
            S.matrix = np.array(struct.unpack_from('<16f', hdr, 64), np.float32).reshape(4, 4)
            S.hashes = [struct.unpack_from('<I', d, c[0x134012][0] + 8 * i)[0] for i in range(c[0x134012][1] // 8)] \
                if 0x134012 in c else []
            mp, ms = c[0x134900]; mh = d[mp:mp + ms]
            k = 0
            while mh[k:k + 4] == b'\x11' * 4:
                k += 4
            nv = struct.unpack_from('<I', mh, k + 13 * 4)[0]
            vp, vs = c[0x134b01]
            vb = d[vp:vp + vs]
            nv = nv or 0
            assert nv * 36 <= len(vb), (S.name, nv, len(vb))
            v = np.frombuffer(vb[len(vb) - nv * 36:], np.uint8).reshape(nv, 36)
            S.pos = v[:, 0:12].copy().view('<f4').reshape(nv, 3)
            S.nrm = v[:, 12:24].copy().view('<f4').reshape(nv, 3)
            S.col = v[:, 24:28].copy()                      # B,G,R,A
            S.uv = v[:, 28:36].copy().view('<f4').reshape(nv, 2)
            rp, rs = c[0x134b02]; rb = d[rp:rp + rs]
            n = rs // 60
            S.ranges = []                                   # (index_count, matidx, shaderidx, index_offset)
            for i in range(n):
                w = struct.unpack_from('<15I', rb, rs - n * 60 + i * 60)
                S.ranges.append((w[3], w[7], w[8], w[13]))
            ip, isz = c[0x134b03]; ib = d[ip:ip + isz]
            k = 0
            while ib[k] == 0x11:
                k += 1
            tot = sum(r[0] for r in S.ranges)
            S.idx = np.frombuffer(ib[k:k + tot * 2], '<u2').astype(np.uint32)
            S.shaders = [struct.unpack_from('<I', d, c[0x134013][0] + 8 * i)[0] for i in range(c[0x134013][1] // 8)] \
                if 0x134013 in c else []
            out.append(S)
    return out

# ---------------------------------------------------------------- materials
def bhash(s):
    h = 0xFFFFFFFF
    for c in s.encode():
        h = (h * 33 + c) & 0xFFFFFFFF
    return h

def read_material_names(path):
    """GLOBALB.BUN holds one 0x135200 record per material: hash at +0xc, name at +0x14 of the payload."""
    d = open(path, 'rb').read()
    names = {0xd6d6080a: 'CARSKIN'}                  # paint slot, patched at draw time, not in GLOBALB
    def walk(o, e, dep=0):
        while o + 8 <= e:
            t, s = struct.unpack_from('<II', d, o)
            if t == 0x135200:
                names[struct.unpack_from('<I', d, o + 8 + 0xc)[0]] = d[o + 8 + 0x14:o + 8 + 0x34].split(b'\0')[0].decode('latin1')
            elif t & 0x80000000 and dep < 8:
                walk(o + 8, o + 8 + s, dep + 1)
            o += 8 + s
    walk(0, len(d))
    return names

# name -> (baseColor rgba, metallic, roughness, mode). The game's real shading is car.efx (env cube + spherical
# harmonics) with GLOBALB constants; these are plain PBR stand-ins chosen by material name.
PAINT = (0.05, 0.16, 0.55)                       # approximate Bayside-blue style paint; the real skin is a runtime composite
MAT_STYLE = {
    'CARSKIN': (PAINT + (1,), 0.55, 0.28, 'OPAQUE'),
    'WINDSHIELD': ((0.02, 0.03, 0.035, 0.45), 0.0, 0.05, 'BLEND'),
    'TRAFFICWINDOWS': ((0.02, 0.03, 0.035, 0.45), 0.0, 0.05, 'BLEND'),
    'WINDOWMASK': ((0.02, 0.03, 0.035, 0.45), 0.0, 0.05, 'BLEND'),
    'HEADLIGHTGLASS': ((0.9, 0.95, 1.0, 0.35), 0.0, 0.05, 'BLEND'),
    'BRAKELIGHTGLASS': ((0.8, 0.05, 0.05, 0.55), 0.0, 0.05, 'BLEND'),
    'CLEARPLASTIC': ((0.85, 0.9, 0.95, 0.3), 0.0, 0.1, 'BLEND'),
    'BRAKELIGHT': ((0.55, 0.03, 0.03, 1), 0.0, 0.3, 'OPAQUE'),
    'HEADLIGHTREFLECTOR': ((0.8, 0.8, 0.8, 1), 1.0, 0.2, 'OPAQUE'),
    'CHROME': ((0.85, 0.86, 0.88, 1), 1.0, 0.12, 'OPAQUE'),
    'MIRROR': ((0.7, 0.75, 0.8, 1), 1.0, 0.05, 'OPAQUE'),
    'ALUMINUM': ((0.75, 0.76, 0.78, 1), 1.0, 0.3, 'OPAQUE'),
    'RUBBER': ((0.04, 0.04, 0.04, 1), 0.0, 0.9, 'OPAQUE'),
    'DECAL': ((1, 1, 1, 1), 0.0, 0.6, 'BLEND'),
    'GRILL': ((0.05, 0.05, 0.055, 1), 0.3, 0.5, 'OPAQUE'),
}
DARK = ((0.07, 0.07, 0.075, 1), 0.1, 0.7, 'OPAQUE')

def style_of(name):
    if name in MAT_STYLE:
        return MAT_STYLE[name]
    if name.startswith('MAG') or name.startswith('RIM') or name.startswith('USER_RIMS'):
        return ((0.72, 0.74, 0.78, 1), 1.0, 0.25, 'OPAQUE')
    return DARK

# ---------------------------------------------------------------- assembly
CARS = 'game/Cars'
UP = (0.0, 0.0, 1.0)

def to_gltf(p):
    """Game space (x forward, y left, z up; metres) -> glTF (x left, y up, z forward). A proper rotation."""
    return np.stack([p[..., 1], p[..., 2], p[..., 0]], -1)

def pick(sols, stem):
    """Highest-LOD solid whose name starts with stem (names are clipped to 27 chars, so the LOD letter may be gone)."""
    c = [s for s in sols if s.name.startswith(stem)]
    return max(c, key=lambda s: len(s.idx)) if c else None

class Prims:
    """Triangle soup grouped by (material, texture hash)."""
    def __init__(self):
        self.g = {}
    def add(self, key, pos, nrm, uv, idx):
        g = self.g.setdefault(key, [[], [], [], [], 0])
        g[0].append(pos); g[1].append(nrm); g[2].append(uv); g[3].append(idx + g[4]); g[4] += len(pos)
    def done(self):
        return {k: (np.concatenate(v[0]), np.concatenate(v[1]), np.concatenate(v[2]), np.concatenate(v[3]).astype(np.uint32))
                for k, v in self.g.items()}

def emit(prims, S, matnames, shift=(0, 0, 0), min_idx=0):
    """Add every material range of solid S (transformed by its own matrix, then shifted) to prims, in glTF space."""
    M = S.matrix
    p = (np.c_[S.pos, np.ones(len(S.pos), np.float32)] @ M)[:, :3] + np.array(shift, np.float32)
    n = S.nrm @ M[:3, :3]
    n = n / np.maximum(np.linalg.norm(n, axis=1, keepdims=True), 1e-9)
    p, n = to_gltf(p), to_gltf(n)
    for cnt, ti, mi, off in S.ranges:
        if cnt <= min_idx:
            continue
        mname = matnames.get(S.shaders[mi], '%08X' % S.shaders[mi]) if mi < len(S.shaders) else 'PLAINNOTHING'
        th = S.hashes[ti] if ti < len(S.hashes) else 0
        tri = S.idx[off:off + cnt].reshape(-1, 3)
        u, inv = np.unique(tri, return_inverse=True)
        prims.add((mname, th), p[u], n[u], S.uv[u], inv.reshape(-1, 3).astype(np.uint32))

# ---------------------------------------------------------------- GLB writer
class Glb:
    def __init__(self):
        self.bin = bytearray(); self.views = []; self.acc = []; self.meshes = []; self.mats = []
        self.imgs = []; self.texs = []; self.nodes = []; self.matkey = {}; self.texkey = {}
    def _view(self, data, target=None):
        while len(self.bin) % 4:
            self.bin += b'\0'
        v = {'buffer': 0, 'byteOffset': len(self.bin), 'byteLength': len(data)}
        if target:
            v['target'] = target
        self.bin += data; self.views.append(v)
        return len(self.views) - 1
    def accessor(self, arr, ctype, typ, target, minmax=False):
        a = {'bufferView': self._view(arr.tobytes(), target), 'componentType': ctype, 'count': len(arr), 'type': typ}
        if minmax:
            a['min'] = [float(x) for x in arr.min(0)]; a['max'] = [float(x) for x in arr.max(0)]
        self.acc.append(a)
        return len(self.acc) - 1
    def texture(self, key, img):
        if key not in self.texkey:
            b = BytesIO(); img.save(b, 'PNG', optimize=True)
            self.imgs.append({'bufferView': self._view(b.getvalue()), 'mimeType': 'image/png'})
            self.texs.append({'source': len(self.imgs) - 1, 'sampler': 0})
            self.texkey[key] = len(self.texs) - 1
        return self.texkey[key]
    def material(self, name, style, tex=None):
        col, met, rough, mode = style
        key = (name, tex, mode)
        if key not in self.matkey:
            pbr = {'baseColorFactor': list(col) if tex is None else [1, 1, 1, col[3]],
                   'metallicFactor': met, 'roughnessFactor': rough}
            if tex is not None:
                pbr['baseColorTexture'] = {'index': tex}
            m = {'name': name if tex is None else '%s+tex%d' % (name, tex), 'pbrMetallicRoughness': pbr, 'doubleSided': True}
            if mode != 'OPAQUE':
                m['alphaMode'] = mode
            self.mats.append(m); self.matkey[key] = len(self.mats) - 1
        return self.matkey[key]
    def mesh(self, name, prims, matfor):
        out = []
        for key, (pos, nrm, uv, idx) in prims.items():
            a = {'POSITION': self.accessor(pos.astype('<f4'), 5126, 'VEC3', 34962, True),
                 'NORMAL': self.accessor(nrm.astype('<f4'), 5126, 'VEC3', 34962),
                 'TEXCOORD_0': self.accessor(uv.astype('<f4'), 5126, 'VEC2', 34962)}
            out.append({'attributes': a, 'indices': self.accessor(idx.reshape(-1).astype('<u4'), 5125, 'SCALAR', 34963),
                        'material': matfor(key)})
        self.meshes.append({'name': name, 'primitives': out})
        return len(self.meshes) - 1
    def node(self, **kw):
        self.nodes.append(kw); return len(self.nodes) - 1
    def write(self, path, root_children):
        js = {'asset': {'version': '2.0', 'generator': 'tools/launcher/car_export.py'},
              'scene': 0, 'scenes': [{'nodes': root_children}], 'nodes': self.nodes, 'meshes': self.meshes,
              'materials': self.mats, 'accessors': self.acc, 'bufferViews': self.views,
              'buffers': [{'byteLength': len(self.bin)}], 'samplers': [{'magFilter': 9729, 'minFilter': 9987, 'wrapS': 10497, 'wrapT': 10497}]}
        if self.texs:
            js['textures'] = self.texs; js['images'] = self.imgs
        j = json.dumps(js, separators=(',', ':')).encode()
        j += b' ' * (-len(j) % 4)
        b = bytes(self.bin) + b'\0' * (-len(self.bin) % 4)
        open(path, 'wb').write(struct.pack('<4sII', b'glTF', 2, 12 + 8 + len(j) + 8 + len(b)) +
                               struct.pack('<I4s', len(j), b'JSON') + j + struct.pack('<I4s', len(b), b'BIN\0') + b)

# ---------------------------------------------------------------- main
STOCK = ['_BASE_', '_KIT00_BODY_', '_KIT00_HOOD_', '_KIT00_ROOF_', '_KIT00_FRONT_BUMPER_', '_KIT00_REAR_BUMPER_',
         '_KIT00_SKIRT_', '_KIT00_SPOILER_', '_KIT00_HEADLIGHT_', '_KIT00_BRAKELIGHT_',
         '_KIT00_LEFT_SIDE_MIR', '_KIT00_RIGHT_SIDE_MI']
WHEEL_HUB_Y = 0.097      # wheel-centre marker of KIT00_WHEEL (hash 0xea8dfb05): the mesh starts at the inner face
# wheel centre (game space, metres): estimated from the body arches, see main()
WHEEL = dict(front_x=1.35, rear_x=-1.33, half_track=0.745, z=0.15, radius=0.34)
GROUND = WHEEL['z'] - WHEEL['radius']      # model z of the road surface (the body floats 0.19 above z=0 data origin)

def main(car, outdir, rim_name=None):
    import os
    G = lambda f: os.path.join(CARS, car, f)
    sols = read_geometry(G('GEOMETRY.BIN'))
    wsols = read_geometry(os.path.join(CARS, 'WHEELS', 'GEOMETRY.BIN'))
    bsols = read_geometry(os.path.join(CARS, 'BRAKES', 'GEOMETRY.BIN'))
    packs = [read_tpk(f) for f in (G('TEXTURES.BIN'), os.path.join(CARS, 'WHEELS', 'TEXTURES.BIN'),
                                   os.path.join(CARS, 'TEXTURES.BIN'), 'game/GLOBAL/GLOBALB.BUN')]
    tex = {}
    for d, t in packs:
        for h, x in t.items():
            tex.setdefault(h, (d, x))
    matnames = read_material_names('game/GLOBAL/GLOBALB.BUN')

    body = Prims(); used = []
    for st in STOCK:
        S = pick(sols, car + st)
        if S:
            emit(body, S, matnames, shift=(0, 0, -GROUND)); used.append(S.name)
    wheel = Prims()
    tire = pick(sols, car + '_KIT00_WHEEL_')
    rim = pick(wsols, rim_name) if rim_name else None
    brake = pick(bsols, 'BRAKE_KIT00')
    # the car's own KIT00_WHEEL is a complete wheel (tire + rim); its 6-index PLAINNOTHING quad is the spin-blur plane
    emit(wheel, rim or tire, matnames, shift=(0, -WHEEL_HUB_Y, 0), min_idx=6)
    emit(wheel, brake, matnames, shift=(0, -WHEEL_HUB_Y, 0))
    g = Glb()
    def matfor(key):
        name, th = key
        style = style_of(name)
        t = None
        if name != 'CARSKIN' and th in tex:
            d, x = tex[th]
            im = decode_tex(d, x)
            if style[3] == 'OPAQUE' or name in ('CHROME', 'MIRROR'):
                im = im.convert('RGB')
            t = g.texture(th, im)
        return g.material(name, style, t)
    bm = g.mesh('body', body.done(), matfor)
    wm = g.mesh('wheel', wheel.done(), matfor)
    kids_ = [g.node(name='body', mesh=bm)]
    cz = WHEEL['z'] - GROUND
    for nm, fx, side in (('FL', WHEEL['front_x'], 1), ('FR', WHEEL['front_x'], -1), ('RL', WHEEL['rear_x'], 1), ('RR', WHEEL['rear_x'], -1)):
        kw = dict(name='wheel_' + nm, mesh=wm, translation=[side * WHEEL['half_track'], cz, fx])
        if side < 0:
            kw['rotation'] = [0, 1, 0, 0]            # 180 deg about up: the wheel mesh is one-sided (outer face +left)
        kids_.append(g.node(**kw))
    return g, kids_, wm, used

MARKERS = {   # solid-marker name hashes (bStringHash of the strings in Speed.exe)
    bhash('LEFT_HEADLIGHT'): 'headlight_L', bhash('RIGHT_HEADLIGHT'): 'headlight_R',
    bhash('LEFT_BRAKELIGHT'): 'taillight_L', bhash('RIGHT_BRAKELIGHT'): 'taillight_R',
    bhash('LEFT_SIDE_MIRROR'): 'mirror_L', bhash('RIGHT_SIDE_MIRROR'): 'mirror_R',
    bhash('REAR_LICENSE_PLATE'): 'plate_rear', bhash('RIGHT_EXHAUST'): 'exhaust',
}

def read_markers(path, stems):
    """0x13401a flare/attachment records (0x50 B: u32 name hash, 4x4 matrix at +0x10) of the given solids."""
    d = open(path, 'rb').read(); out = {}
    for t, p, s in kids(d, 0, len(d)):
        if t != 0x80134000:
            continue
        for t2, p2, s2 in kids(d, p, p + s):
            if t2 != 0x80134010:
                continue
            c = {t3: (p3, s3) for t3, p3, s3 in kids(d, p2, p2 + s2)}
            if 0x13401a not in c:
                continue
            hp, hs = c[0x134011]
            name = max(re.findall(rb'[\x21-\x7e]+', d[hp + 0x40 + 64:hp + hs]), key=len).decode()
            if name not in stems:
                continue
            b = d[c[0x13401a][0]:c[0x13401a][0] + c[0x13401a][1]]
            k = 0
            while b[k:k + 4] == b'\x11' * 4:
                k += 4
            for i in range(len(b[k:]) // 0x50):
                h, = struct.unpack_from('<I', b, k + i * 0x50)
                m = struct.unpack_from('<16f', b, k + i * 0x50 + 0x10)
                if h in MARKERS:
                    out.setdefault(MARKERS[h], [m[12], m[13], m[14]])
    return out

if __name__ == '__main__':
    import os
    car = sys.argv[1] if len(sys.argv) > 1 else 'SKYLINE'
    out = sys.argv[2] if len(sys.argv) > 2 else 'web/launcher/v3'
    g, kids_, wm, used = main(car, out)
    g.write(out + '/car.glb', kids_)
    # meta: everything in glTF space (x left, y up, z forward), metres, ground at y=0
    pts = []
    for n in g.nodes:
        for pr in g.meshes[n['mesh']]['primitives']:
            a = g.acc[pr['attributes']['POSITION']]
            for c in (a['min'], a['max']):
                q = np.array(c)
                for sx in ([1] if 'rotation' not in n else [-1]):
                    pts.append(q * np.array([sx, 1, sx]) + np.array(n.get('translation', [0, 0, 0])))
    pts = np.array(pts)
    lo, hi = pts.min(0), pts.max(0)
    mk = read_markers(os.path.join(CARS, car, 'GEOMETRY.BIN'), set(used))
    mk = {k: [round(float(x), 3) for x in to_gltf(np.array([v[0], v[1], v[2] - GROUND]))] for k, v in mk.items()}
    cz = WHEEL['z'] - GROUND
    meta = {'car': car, 'units': 'metres', 'axes': 'glTF: +x car-left, +y up, +z forward; ground at y=0',
            'bbox': {'min': [round(float(x), 3) for x in lo], 'max': [round(float(x), 3) for x in hi]},
            'wheel_radius': WHEEL['radius'],
            'wheel_centers': {n['name'][6:]: [round(x, 3) for x in n['translation']] for n in g.nodes if n['name'].startswith('wheel_')},
            'wheel_nodes_note': 'nodes wheel_FL/FR/RL/RR share one mesh; spin about local x; steer about local y',
            'headlights': {k[-1]: v for k, v in mk.items() if k.startswith('headlight')},
            'taillights': {k[-1]: v for k, v in mk.items() if k.startswith('taillight')},
            'other_markers': {k: v for k, v in mk.items() if not k.startswith(('headlight', 'taillight'))},
            'materials': [m['name'] for m in g.mats],
            'paint_materials': [m['name'] for m in g.mats if m['name'].startswith('CARSKIN')],
            'parts_used': used,
            'approximate': ['wheel centres/radius estimated from the arch cut-outs in the body mesh (no wheel markers in the stock solids except KIT00_WHEEL hub offset)',
                            'paint colour is a stand-in: the game composes SKIN1 (paint+vinyl+decals) at run time',
                            'materials are plain PBR stand-ins by GLOBALB material name']}
    json.dump(meta, open(out + '/car_meta.json', 'w'), indent=1)
    print(os.path.getsize(out + '/car.glb'), 'bytes;', len(g.texs), 'textures;', len(g.mats), 'materials')
