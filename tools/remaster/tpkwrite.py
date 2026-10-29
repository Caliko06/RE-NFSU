"""Write NFSU TPK files: clone texture entries (new name, optional new pixels) into a copy of a TPK container.
Layout (game/Cars/TEXTURES.BIN, game/Global/DYNTEX.BIN; same walk as ref/tools/ug1-hud/dump.py, docs/openworld/re_*.md):
  0xb3300000 { 0 (empty), 0xb3310000 { 33310001 header 0x7c, 33310002 hash list (key, 0) x n, 33310003 stream rows
  (key, file offset, packed size, 0x100, 0) x n, 33310004 TextureInfo 0x7c x n (name +0xc, key +0x24, offsets +0x30/+0x34,
  size +0x38, level-0 size +0x40, w/h u16 +0x44, format byte +0x4a), 33310005 32 bytes x n }, filler 0, 0xb3320000 {
  33320001, filler, 33320002 pixel pool } } then a 0x1000 zero chunk. The loader 0x5453d0 needs the TextureInfo and the 33310005
  counts equal; 0x53e400 binary-searches the lists, so all four arrays stay sorted by key (hash h*33+c from -1, 0x4f42f0).
  The stream rows hold absolute file offsets, so the pixel pool (chunk 0xb3320000) is kept 128-aligned by the filler before it
  and every row is moved by the same multiple of 128. Pixel bytes of a new entry are JDLZ-packed (jdlz_pack)
  appended to the pool; an entry without pixels shares its source's row (same stream data, e.g. a blank render target).
usage: tpkwrite.py IN OUT NEW=SRC [NEW=SRC ...]     (clone SRC as NEW, own virtual pool offset)
API:   t = Tpk(path); t.clone('NEW', 'SRC', pixels=raw|None, fields={off: bytes}); t.save(path); nfs_hash(name)"""
import struct, sys


def nfs_hash(s):
    h = 0xffffffff
    for c in s.encode():
        h = (h * 33 + c) & 0xffffffff
    return h


def jdlz_pack(raw):
    """JDLZ (ref/tools/jdlz.py is the decoder): greedy LZ77. Control bits as the decoder reads them: flags1 (1 = reference, 8 items per
    byte), flags2 (one bit per reference, 1 = short: distance 1..16, length 3..4098; 0 = long: distance 17..2064, length 3..34), both
    bytes fetched at the top of the iteration that finds them empty, flags1 first."""
    n = len(raw)
    out = bytearray(b'JDLZ' + struct.pack('<III', 0x1002, n, 0))
    f1 = f2 = i1 = i2 = b1 = b2 = 0                       # items / references left in the current control byte, its slot, its bits
    heads = {}
    pos = 0

    def insert(p):
        if p + 3 <= n:
            heads.setdefault(raw[p:p + 3], []).append(p)

    while pos < n:
        if f1 == 0:
            i1, f1, b1 = len(out), 8, 0
            out.append(0)
        if f2 == 0:
            i2, f2, b2 = len(out), 8, 0
            out.append(0)
        best, bd = 0, 0
        for q in reversed(heads.get(raw[pos:pos + 3], ())[-48:]):
            d = pos - q
            if d > 2064:
                break
            lim = 4098 if d <= 16 else 34
            m = 3
            while m < lim and pos + m < n and raw[q + m] == raw[pos + m]:
                m += 1
            if m > best:
                best, bd = m, d
                if m == lim:
                    break
        k = 8 - f1
        if best >= 3:
            b1 |= 1 << k
            if bd <= 16:
                b2 |= 1 << (8 - f2)
                out += bytes(((((best - 3) >> 8) << 4) | (bd - 1), (best - 3) & 0xff))
            else:
                e = bd - 17
                out += bytes((((e >> 3) & 0xe0) | (best - 3), e & 0xff))
            f2 -= 1
            step = best
        else:
            out.append(raw[pos])
            step = 1
        f1 -= 1
        out[i1], out[i2] = b1, b2
        for p in range(pos, pos + step):
            insert(p)
        pos += step
    struct.pack_into('<I', out, 12, len(out))
    return bytes(out)


def _chunks(d, b, e):
    o = b
    while o + 8 <= e:
        m, s = struct.unpack_from('<II', d, o)
        if o + 8 + s > e:
            break
        yield m, o, s
        o += 8 + s


def _pack(m, body):
    return struct.pack('<II', m, len(body)) + bytes(body)


class Tpk:
    def __init__(self, path):
        d = self.d = open(path, 'rb').read()
        top = next(_chunks(d, 0, len(d)))
        assert top[0] == 0xb3300000, hex(top[0])
        self.tail = d[top[1] + 8 + top[2]:]
        kids = list(_chunks(d, 8, 8 + top[2]))
        self.hdrc = next(c for c in kids if c[0] == 0xb3310000)
        self.datc = next(c for c in kids if c[0] == 0xb3320000)
        ch = {m: d[o + 8:o + 8 + s] for m, o, s in _chunks(d, self.hdrc[1] + 8, self.hdrc[1] + 8 + self.hdrc[2])}
        self.head = ch[0x33310001]
        self.hl = [struct.unpack_from('<II', ch[0x33310002], k) for k in range(0, len(ch[0x33310002]), 8)]
        self.slots = [list(struct.unpack_from('<5I', ch[0x33310003], k)) for k in range(0, len(ch[0x33310003]), 20)]
        self.recs = [bytearray(ch[0x33310004][k:k + 0x7c]) for k in range(0, len(ch[0x33310004]), 0x7c)]
        self.c5 = [ch[0x33310005][k:k + 32] for k in range(0, len(ch[0x33310005]), 32)]
        n = len(self.recs)
        assert len(self.hl) == len(self.slots) == len(self.c5) == n
        self.keys = [struct.unpack_from('<I', r, 0x24)[0] for r in self.recs]
        assert self.keys == sorted(self.keys) == [k for k, _ in self.hl] and [s[0] for s in self.slots] == self.keys
        self.inner = [(m, bytes(d[o + 8:o + 8 + s])) for m, o, s in _chunks(d, self.datc[1] + 8, self.datc[1] + 8 + self.datc[2])]
        self.blobs = []                                # pixels appended to the pool: (stream row, packed bytes)

    def index(self, name):
        return self.keys.index(nfs_hash(name))

    def pool_end(self):
        return max(max(struct.unpack_from('<I', r, 0x30)[0] + struct.unpack_from('<I', r, 0x38)[0],
                       struct.unpack_from('<I', r, 0x34)[0]) for r in self.recs)

    def clone(self, new, src, pixels=None, fields=None):
        """pixels: the raw level 0..n bytes of the new texture (packed here), None = share src's stream row;
        fields: {TextureInfo offset: bytes} patched after the copy (virtual offsets +0x30/+0x34, size, w/h ...)."""
        i = self.index(src)
        key = nfs_hash(new)
        assert key not in self.keys, new
        rec = bytearray(self.recs[i])
        rec[0xc:0x24] = new.encode().ljust(24, b'\0')
        struct.pack_into('<I', rec, 0x24, key)
        for o, v in (fields or {}).items():
            rec[o:o + len(v)] = v
        slot = list(self.slots[i])
        slot[0] = key
        row = None
        if pixels is not None:
            packed = jdlz_pack(pixels)
            slot[2] = len(packed)
            row = slot
            self.blobs.append((slot, packed))
        j = next((p for p, k in enumerate(self.keys) if k > key), len(self.keys))
        self.keys.insert(j, key); self.hl.insert(j, (key, 0)); self.slots.insert(j, slot)
        self.recs.insert(j, rec); self.c5.insert(j, self.c5[i])
        return row

    def save(self, path):
        sizes = [len(self.head), 8 * len(self.hl), 20 * len(self.slots), 0x7c * len(self.recs), 32 * len(self.c5)]
        size1 = sum(8 + s for s in sizes)
        end1 = 16 + 8 + size1
        fill = (-(end1 + 8)) % 128
        new_start = end1 + 8 + fill
        delta = new_start - self.datc[1]
        assert delta % 128 == 0
        # the pixel pool: the old 33320002 body keeps its bytes; new blobs follow it
        pool_at = new_start + 8 + sum(8 + len(b) for m, b in self.inner[:-1]) + 8     # body start of 33320002
        pool = bytearray(self.inner[-1][1])
        assert self.inner[-1][0] == 0x33320002
        base = pool_at + len(pool)
        for slot, packed in self.blobs:
            slot[1] = base
            pool += packed
            base += len(packed)
        moved = set(id(s) for s, _ in self.blobs)
        def row(s):                                    # a shared row follows the moved pool; a new blob has its final offset
            ao = s[1] + delta if id(s) not in moved and s[1] >= self.datc[1] else s[1]
            return struct.pack('<5I', s[0], ao, *s[2:])
        rows = b''.join(row(s) for s in self.slots)
        c1 = [(0x33310001, self.head), (0x33310002, b''.join(struct.pack('<II', *e) for e in self.hl)), (0x33310003, rows),
              (0x33310004, b''.join(bytes(r) for r in self.recs)), (0x33310005, b''.join(self.c5))]
        inner = self.inner[:-1] + [(0x33320002, bytes(pool))]
        top = _pack(0, b'') + _pack(0xb3310000, b''.join(_pack(m, b) for m, b in c1)) + _pack(0, b'\0' * fill) \
            + _pack(0xb3320000, b''.join(_pack(m, b) for m, b in inner))
        out = _pack(0xb3300000, top) + self.tail
        open(path, 'wb').write(out)
        return len(out)


if __name__ == '__main__':
    t = Tpk(sys.argv[1])
    for a in sys.argv[3:]:
        new, src = a.split('=')
        t.clone(new, src)
    print(sys.argv[2], t.save(sys.argv[2]), 'bytes,', len(t.recs), 'entries')
