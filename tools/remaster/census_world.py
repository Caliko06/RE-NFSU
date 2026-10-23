"""World texture census. usage: census_world.py game/TRACKS/STREAML1RA.BUN [more files]
Walks the BUN's chunks recursively (a chunk with the high bit set holds chunks) and parses every TPK container (0xb3300000) the way
index.py does for cars. Prints per file and total: textures, formats, max side, unique level-0 contents (FNV-1a 64)."""
import os, struct, sys, collections
src = open(os.path.join(os.path.dirname(__file__), 'index.py')).read().split('game, pngs, out')[0]
ns = {}; exec(src, ns)
jdlz, fnv64, chunks = ns['jdlz'], ns['fnv64'], ns['chunks']

def tpks(d, o, e, depth=0):
    for m, b, s in chunks(d, o, e):
        if s > e - b: return
        if m == 0xb3300000: yield b, b + s
        elif m & 0x80000000 and depth < 8: yield from tpks(d, b, b + s, depth + 1)

def base_size(w, h, comp):
    return w * h * 4 if comp == 0x20 else max(1, w // 4) * max(1, h // 4) * (8 if comp == 0x22 else 16)

def parse(d, b, e):
    slots = {}; recs = []; data = None
    for m2, b2, s2 in chunks(d, b, e):
        for m3, b3, s3 in chunks(d, b2, b2 + s2):
            # world / sky variant: one data chunk, offsets in the records. The chunk body is padded with 0x11 up to a 0x80 file
            # alignment and the offsets count from there (V: all 222 chunks in STREAML1R*.BUN; runtime texhash matches).
            if m3 == 0x33320002: data = (b3 + 0x7f) & ~0x7f
            if m3 == 0x33310003:
                for k in range(0, s3, 20):
                    key, ao, es = struct.unpack_from('<3I', d, b3 + k); slots[key] = (ao, es)
            if m3 == 0x33310004: recs += [d[b3 + k:b3 + k + 0x7c] for k in range(0, s3, 0x7c)]
    for r in recs:
        key, = struct.unpack_from('<I', r, 0x24); w, h = struct.unpack_from('<HH', r, 0x44); comp = r[0x4A]
        if not slots and data is not None and comp in (0x20, 0x22, 0x24, 0x26):
            off, full, base = struct.unpack_from('<I', r, 0x30)[0], struct.unpack_from('<I', r, 0x38)[0], struct.unpack_from('<I', r, 0x40)[0]
            assert base == base_size(w, h, comp), (r[0xc:0x24], w, h, hex(comp), hex(base))   # the field is the level-0 size
            if r[0xc:0x12] != b'DUMMY_':
                yield key, r[0xc:0x24].split(b'\0')[0].decode('latin1'), w, h, comp, d[data + off:data + off + base]
            continue
        if key not in slots or comp not in (0x20, 0x22, 0x24, 0x26) or r[0xc:0x12] == b'DUMMY_': continue
        ao, es = slots[key]; raw = d[ao:ao + es]
        if raw[:4] == b'JDLZ': raw = jdlz(raw)
        n = w * h * 4 if comp == 0x20 else max(1, w // 4) * max(1, h // 4) * (8 if comp == 0x22 else 16)
        yield key, r[0xc:0x24].split(b'\0')[0].decode('latin1'), w, h, comp, raw[:n]

if __name__ == '__main__':
    seen = {}; tot = collections.Counter(); sides = collections.Counter(); npx = 0
    for f in sys.argv[1:]:
        d = open(f, 'rb').read(); n = 0; ntpk = 0
        for b, e in tpks(d, 0, len(d)):
            ntpk += 1
            for key, name, w, h, comp, raw in parse(d, b, e):
                n += 1; tot[hex(comp)] += 1; sides[max(w, h)] += 1
                hh = fnv64(raw)
                if hh not in seen: seen[hh] = (f, name, w, h, comp); npx += w * h
        print(f'{os.path.basename(f)}: {ntpk} TPK containers, {n} textures')
    print('TOTAL', sum(tot.values()), 'textures,', len(seen), 'unique contents; formats', dict(tot)); print('max side', sorted(sides.items())); print('unique Mpx', round(npx / 1e6, 1))
