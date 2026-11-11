#!/usr/bin/env python3
"""Top-level chunk census for an NFS Underground 2 .BUN file.

Chunk layout (little-endian, consecutive): u32 id, u32 size, then `size` payload bytes.
Counts how many times each id appears and the total payload bytes of each id.

Usage: python3 -I tools/probe/ug2_chunk_census.py [in.bun] [out.tsv]
"""
import struct
import sys

SRC = "/Users/angeldamian/RE-NFSU-UG2/Need For Speed Underground 2/TRACKS/L4RA.BUN"
OUT = "census/ug2/l4ra_chunks.tsv"


def walk(data):
    """Yield (offset, id, size) for each top-level chunk."""
    pos = 0
    n = len(data)
    while pos + 8 <= n:
        cid, size = struct.unpack_from("<II", data, pos)
        if size > n - pos - 8:
            print("stop: chunk at %#x id=%#010x size=%d overflows file" % (pos, cid, size))
            return
        yield pos, cid, size
        pos += 8 + size


def main():
    src = sys.argv[1] if len(sys.argv) > 1 else SRC
    out = sys.argv[2] if len(sys.argv) > 2 else OUT
    with open(src, "rb") as f:
        data = f.read()

    counts = {}   # id -> [veces, bytes, first_offset]
    total = 0
    for off, cid, size in walk(data):
        rec = counts.setdefault(cid, [0, 0, off])
        rec[0] += 1
        rec[1] += size
        total += 8 + size

    rows = sorted(counts.items(), key=lambda kv: (-kv[1][1], kv[0]))
    with open(out, "w") as f:
        f.write("id_hex\tveces\tbytes\tprimer_offset_hex\n")
        for cid, (veces, nbytes, first) in rows:
            f.write("%08x\t%d\t%d\t%08x\n" % (cid, veces, nbytes, first))

    print("chunks: %d  ids: %d  covered: %d/%d bytes (%.2f%%)"
          % (sum(r[0] for r in counts.values()), len(counts), total, len(data),
             100.0 * total / len(data)))
    print("wrote %s" % out)


if __name__ == "__main__":
    main()
