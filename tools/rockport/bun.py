"""bun.py: chunk tree readers shared by the Rockport tools (MW and NFSU BUN files are the same chunk format).
Chunk = u32 id, u32 size, payload; bit 31 of the id = container. Payloads start with 0x11 filler up to an aligned byte."""
import mmap, os, struct

MW = os.path.expanduser('~/RE-NFSMW')
MW_TRACKS = os.path.join(MW, 'game', 'TRACKS')
NFSU = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..'))


def open_map(path):
    f = open(os.path.expanduser(path), 'rb')
    return mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ)


def tree(d, a=0, b=None, dep=0, out=None, maxdep=99):
    """List of (depth, id, payload_start, size)."""
    out = [] if out is None else out
    b = len(d) if b is None else b
    o = a
    while o + 8 <= b:
        i, n = struct.unpack_from('<II', d, o)
        if i == 0 and n == 0:
            o += 8
            continue
        e = o + 8 + n
        if e > b:
            break
        out.append((dep, i, o + 8, n))
        if i & 0x80000000 and dep < maxdep:
            tree(d, o + 8, e, dep + 1, out, maxdep)
        o = e
    return out


def children(d, b, s):
    return [(i, b2, s2) for dep, i, b2, s2 in tree(d, b, b + s, maxdep=0)]


def skip11(d, b, s):
    q = b
    while q < b + s and d[q] == 0x11:
        q += 1
    return q


def binhash(s):
    h = 0xffffffff
    for c in s.encode('latin1') if isinstance(s, str) else s:
        h = (h * 33 + c) & 0xffffffff
    return h


def mw_section_table():
    """L2RA.BUN chunk 0x34110: 92 B rows. Returns list of dicts."""
    d = open(os.path.join(MW_TRACKS, 'L2RA.BUN'), 'rb').read()
    for dep, i, b, s in tree(d, maxdep=0):
        if i == 0x34110:
            rows = []
            for k in range(s // 92):
                r = d[b + k * 92:b + (k + 1) * 92]
                name = r[:8].split(b'\0')[0].decode()
                sid, = struct.unpack_from('<I', r, 8)
                off, size = struct.unpack_from('<II', r, 0x14)
                x, y, rad = struct.unpack_from('<3f', r, 0x28)
                rows.append(dict(name=name, id=sid, off=off, size=size, x=x, y=y, r=rad, raw=r))
            return rows
