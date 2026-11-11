#!/usr/bin/env python3
"""q_owcoll2_write.py: write a TRACKB<id>.lzc whose collision chunks 0x34130..0x34134 come from a wsrc row list
(the union of the 16 street tracks, or any list), everything else copied from a base TRACKB.
Layout rules (all from Speed.exe, see build/openworld/re_coll.md):
  0x34130 wmap, 0x34131 wcell, 0x34134 bbox: loader aligns the DATA start to 16 in memory ((hdr + 0x17) & ~0xf, 0x441380),
     so the chunk starts with 0x11 filler up to the next multiple of 16 of the file offset (buffer base is 16-aligned).
  0x34132 wsrc and 0x34133 widx: data right after the header, no pad; widx is padded with one u16 0 to a multiple of 4 B.
  the id-0 pad chunks after the block that precede a chunk whose header sat at a multiple of 128 are re-sized
     to size = (-(hdr + 8)) mod 128, as the original packer did.
usage: q_owcoll2_write.py selftest            rebuild all 16 tracks from their own wsrc, compare byte for byte
       q_owcoll2_write.py merged <base id> <out.lzc|out.raw> [--raw|--stored]   union of the 16 tracks into <base id>'s file
"""
import os, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
os.environ.setdefault('NFSU1_MAIN', REPO)
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(REPO, 'ref', 'tools', 'ug1-tracks'))
from lib import load, trackb_path, PC  # noqa: E402
import q_owcoll2_gen as gen  # noqa: E402
import q_owcoll2_lzc as lzc  # noqa: E402

TRACKS = list(range(1001, 1009)) + list(range(1102, 1110))
COLL = (0x34130, 0x34131, 0x34132, 0x34133, 0x34134)


def top_chunks(d):
    out, o = [], 0
    while o < len(d):
        cid, size = struct.unpack_from('<II', d, o)
        assert o + 8 + size <= len(d)
        out.append([cid, o, size])
        o += 8 + size
    return out


def chunk(cid, pos, payload, align16):
    """one chunk at file offset pos: header + 0x11 pad up to 16-aligned data (if align16) + payload"""
    pad = (-(pos + 8)) % 16 if align16 else 0
    return struct.pack('<II', cid, pad + len(payload)) + b'\x11' * pad + payload


def row_key(r):
    return r[:6] + b'\xff\xff' + r[8:]


def bbox_payload(rows):
    xs = [x / 8 for r in rows for x, _ in gen.row_xy8(r)]
    ys = [y / 8 for r in rows for _, y in gen.row_xy8(r)]
    return struct.pack('<8f', min(xs), min(ys), -127.0, 0.0, max(xs), max(ys), 127.0, 0.0)


WIDE = b'\xff\xff\xff\xff'   # first dword of a u32 widx chunk (PATCH 0x441423: the loader tells it from the shipped u16 files; no row index is 0xffff)


def build_trackb(base, rows, wide=False):
    """base: decompressed TRACKB bytes; rows: list of 32 B wsrc rows -> new decompressed TRACKB bytes.
    wide: u32 widx entries behind WIDE (more than 65,534 rows; the exe needs the PATCHES of patches_collision.py)"""
    assert wide or len(rows) <= 0xfffe, 'more than 65534 polygons: u16 indices (widx, save/restore 0xffff terminator) overflow'
    ch = top_chunks(base)
    ids = [c[0] for c in ch]
    i0 = ids.index(0x34130)
    assert ids[i0:i0 + 5] == list(COLL)
    g = gen.derive(rows, wide=wide)
    widx = WIDE + g['widx'] if wide else g['widx'] + (b'\0\0' if (len(g['widx']) // 2) % 2 else b'')
    assert g['nodes'] <= 0xffff and g['cells'] <= 0xffff
    out = bytearray(base[:ch[i0][1]])
    for cid, payload, al in ((0x34130, g['wmap'], True), (0x34131, g['wcell'], True), (0x34132, b''.join(rows), False),
                             (0x34133, widx, False), (0x34134, bbox_payload(rows), True)):
        out += chunk(cid, len(out), payload, al)
    tail = ch[i0 + 5:]
    k = 0
    while k < len(tail):
        # group = consecutive id-0 pad chunks + the chunk after them
        j = k
        while j < len(tail) and tail[j][0] == 0:
            j += 1
        pads, c = tail[k:j], (tail[j] if j < len(tail) else None)
        if c is not None and pads and c[1] % 128 == 0:
            # the original packer put this chunk's header at a multiple of 128: keep its pads when the phase still
            # fits, else keep the fixed 1024 B pad and add one pad chunk of size (-(hdr + 8)) mod 128 (none if aligned)
            probe = len(out) + sum(8 + p[2] for p in pads)
            if probe % 128 != 0:
                for p in pads:
                    if p[2] == 1024:
                        out += base[p[1]:p[1] + 8 + p[2]]
                need = (-len(out)) % 128
                if need:
                    assert need >= 8
                    out += struct.pack('<II', 0, need - 8) + b'\0' * (need - 8)
            else:
                for p in pads:
                    out += base[p[1]:p[1] + 8 + p[2]]
        else:
            for p in pads:
                out += base[p[1]:p[1] + 8 + p[2]]
        if c is not None:
            out += base[c[1]:c[1] + 8 + c[2]]
        k = j + 1
    return bytes(out)


def check_alignment(orig, new):
    """invariants after the collision block: every non-pad chunk header stays at a multiple of 16, and the three
    chunks 0x8003b000 / 0x3b200 / 0x3b300 stay at a multiple of 128 (buffer base is 128-aligned: 0x2000 -> align 0x80)"""
    a = [c for c in top_chunks(orig) if c[0] != 0]
    b = [c for c in top_chunks(new) if c[0] != 0]
    assert [c[0] for c in a] == [c[0] for c in b]
    first = [c[0] for c in a].index(0x34134)
    bad = []
    for (cid, o, _), (_, n, _) in list(zip(a, b))[first + 1:]:
        if n % 16 or (cid in (0x8003b000, 0x3b200, 0x3b300) and n % 128):
            bad.append((hex(cid), o, n))
    return bad


def selftest():
    tot = ok = 0
    for t in TRACKS:
        d = load(trackb_path(PC, t))
        c = top_chunks(d)
        ids = [x[0] for x in c]
        i0 = ids.index(0x34132)
        ws = d[c[i0][1] + 8:c[i0][1] + 8 + c[i0][2]]
        rows = [ws[o:o + 32] for o in range(0, len(ws), 32)]
        new = build_trackb(d, rows)
        same = new == d
        # compare ignoring the runtime field +6 of the wsrc rows (the loader overwrites it)
        n = sum(1 for a, b in zip(new, d) if a == b) if len(new) == len(d) else 0
        print(t, 'rebuilt decompressed file identical:', same, '(%d/%d B, len %d vs %d)' % (n, len(d), len(new), len(d)), flush=True)
        tot += len(d)
        ok += n
    print('byte match %.4f%%' % (100.0 * ok / tot))


def merged(base_id, out, mode):
    base = load(trackb_path(PC, base_id))
    seen, rows = {}, []
    for t in TRACKS:
        d = load(trackb_path(PC, t))
        c = top_chunks(d)
        i0 = [x[0] for x in c].index(0x34132)
        ws = d[c[i0][1] + 8:c[i0][1] + 8 + c[i0][2]]
        for o in range(0, len(ws), 32):
            r = ws[o:o + 32]
            k = row_key(r)
            if k not in seen:
                seen[k] = len(rows)
                rows.append(k)
    new = build_trackb(base, rows)
    open(out, 'wb').write(new if mode == '--raw' else lzc.encode(new, window=(mode != '--stored')))
    print('wrote', out, 'rows', len(rows), 'decompressed', len(new), 'file', os.path.getsize(out))


if __name__ == '__main__':
    if len(sys.argv) > 1 and sys.argv[1] == 'selftest':
        selftest()
    elif len(sys.argv) > 3 and sys.argv[1] == 'merged':
        merged(int(sys.argv[2]), sys.argv[3], sys.argv[4] if len(sys.argv) > 4 else '')
    else:
        print(__doc__)
