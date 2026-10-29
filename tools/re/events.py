"""Read-only reader for the career event table (EventDesc, chunk 0x34a02 in FrontEnd/FrontB.lzc) — docs/re/canon.md.

  events.py dump [ID]     one line per event: kind, mode, stages, prerequisites, rivals, rewards, movies
  events.py fields        which byte ranges of the 0x14c record are named, and the value spread of the unnamed ones
  events.py check         every record re-packs byte-for-byte from the named fields + the raw unnamed ranges

Field map: tools/census/career.py (code addresses per field) and docs/re/canon.md; FIELDS below marks each range.
Container 0x80034a00 (loader 0x5a00a0): 0x34a01 = 0x20-byte rows indexed by id into [0x733f78 + 4*id], 0x34a02 =
EventDesc rows indexed by id into [0x733ff8 + 4*id] (0x5a0060 returns the row).
"""
import os, struct, sys
from collections import Counter

B = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(B, "tools", "census"))
from jdlz import jdlz_decompress

REC = 0x14c
# (offset, struct format, name); ranges not listed are kept raw. V/I per field in docs/re/canon.md.
FIELDS = [
    (0x00, "<I", "id"), (0x04, "<I", "kind"), (0x08, "<I", "mode"), (0x10, "<f", "fee"),
    (0x28, "<3f", "cash"),
    (0x38, "<15I", "rewards"), (0x74, "<I", "nrewards"),     # 5 x (type, value, arg)
    (0x78, "<32B", "stages"), (0x98, "<I", "nstages"),        # 8 x (u16 track, u8 laps, u8 direction)
    (0x9c, "<6h", "prereq"), (0xa8, "<h", "prereq_rule"), (0xaa, "<h", "nprereq"),
    (0xac, "12s", "movie_before"), (0xb8, "12s", "movie_lose"), (0xc4, "12s", "movie_win"),
    (0xd4, "<84B", "opponents"),                              # 3 x 0x1c: name[8], ?, u32 car preset hash, ?
]


def records(path=os.path.join(B, "game", "FrontEnd", "FrontB.lzc")):
    d = jdlz_decompress(open(path, "rb").read())
    i = d.find(struct.pack("<I", 0x34a02))
    n = struct.unpack_from("<I", d, i + 4)[0]
    return [d[i + 8 + k * REC:i + 8 + (k + 1) * REC] for k in range(n // REC)]


def parse(r):
    f, raw, cur = {}, {}, 0
    for off, fmt, name in FIELDS:
        if off > cur:
            raw[cur] = r[cur:off]
        v = struct.unpack_from(fmt, r, off)
        f[name] = v[0] if len(v) == 1 else v
        cur = off + struct.calcsize(fmt)
    if cur < REC:
        raw[cur] = r[cur:]
    return f, raw


def pack(f, raw):
    out = bytearray(REC)
    for off, fmt, name in FIELDS:
        v = f[name]
        struct.pack_into(fmt, out, off, *(v if isinstance(v, tuple) else (v,)))
    for off, b in raw.items():
        out[off:off + len(b)] = b
    return bytes(out)


def s(b):
    return b.split(b"\0")[0].decode("latin1")


def line(f):
    st = f["stages"]
    stages = [f"{st[4*k] | st[4*k+1] << 8}x{st[4*k+2]}{'r' if st[4*k+3] else ''}" for k in range(f["nstages"])]
    op = bytes(f["opponents"])
    riv = [f"{s(op[0x1c*k:0x1c*k+8])}:{struct.unpack_from('<I', op, 0x1c*k+12)[0]:08x}" for k in range(3) if op[0x1c*k]]
    rw = f["rewards"]
    rew = [f"{rw[3*k]}/{rw[3*k+1]:x}/{rw[3*k+2]}" for k in range(f["nrewards"])]
    pre = ("any" if f["prereq_rule"] == 1 else "all") + str(list(f["prereq"][:f["nprereq"]]))
    mv = "/".join(s(f[m]) for m in ("movie_before", "movie_lose", "movie_win"))
    return (f"{f['id']:3} kind {f['kind']} mode {f['mode']:2} fee {f['fee']:g} cash {'/'.join('%g' % c for c in f['cash'])} "
            f"stages {' '.join(stages)} pre {pre} rivals {' '.join(riv)} rewards {' '.join(rew)} movies {mv}")


def main():
    a = sys.argv[1:]
    if not a or a[0] == "help":
        print(__doc__)
    elif a[0] == "dump":
        for r in records():
            f, _ = parse(r)
            if len(a) < 2 or f["id"] == int(a[1]):
                print(line(f))
    elif a[0] == "fields":
        R = [parse(r) for r in records()]
        for off in sorted(R[0][1]):
            n = len(R[0][1][off])
            for o in range(off, off + n, 4):
                c = Counter(struct.unpack_from("<I", r, o)[0] for r in records())
                print(f"+{o:#05x} raw  {len(c)} values, top {[(hex(k), v) for k, v in c.most_common(4)]}")
    elif a[0] == "check":
        R = records()
        ok = sum(pack(*parse(r)) == r for r in R)
        ids = [parse(r)[0]["id"] for r in R]
        print(f"{ok}/{len(R)} records re-pack byte-for-byte; ids {min(ids)}..{max(ids)}, unique {len(set(ids)) == len(ids)}")
        sys.exit(0 if ok == len(R) else 1)


if __name__ == "__main__":
    main()
