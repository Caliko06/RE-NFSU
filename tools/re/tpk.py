"""Read-only reader for texture packs (TPK, chunk 0xb3300000) in BUN/BIN/LZC files — docs/re/assets.md "Textures".

  tpk.py list FILE               packs and textures: name, hash, size, format, mips, data offset
  tpk.py dds FILE NAME OUT.dds   write one texture as a .dds (DXT1/DXT3/A8R8G8B8 as stored; P8 expanded to A8R8G8B8)
  tpk.py check                   every pack in game/: data ranges inside the blob, size = sum of the mip sizes,
                                 hash index = record hashes, JDLZ streams (car packs) unpack to the record's
                                 pixel..palette range

Layout (loader 0x5455c0 -> 0x5453d0 for the header container, 0x545900 binds records, 0x5459f0 maps the pixels):
  0xb3300000 pack
    0xb3310000 header container
      0x33310001 header 0x7c: +0 version 4, +4 name[0x1c], +0x20 path[0x40], +0x60 key
      0x33310002 hash index: {u32 hash, u32 0} per texture, ascending (binary search 0x53e400)
      0x33310003 (car packs only) stream directory: {hash, offset of a JDLZ stream from the pack chunk, packed size,
                 0x100, 0} per texture
      0x33310004 records 0x7c: +0xc name[0x18], +0x24 hash, +0x2c link hash, +0x30 pixel offset, +0x34 palette offset,
                 +0x38 pixel bytes (all mips), +0x3c palette bytes, +0x40 mip-0 bytes, +0x44 s16 w, +0x46 s16 h,
                 +0x4a pixel code, +0x4d palettised, +0x4e mip count
      0x33310005 GPU entries 0x20 (one per record): +0x14 D3DFORMAT (0x29 P8, 'DXT1', 'DXT3', 0x15 A8R8G8B8)
    0xb3320000 data container (may also stand alone at top level)
      0x33320001 node 0x18: +0xc key (= header +0x60, pairs data with its pack, 0x545660)
      0x33320002 pixel blob: 0x11 filler up to a 128-byte boundary, then the data; offsets count from that boundary
"""
import os, struct, sys

B = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(B, "tools", "re"))
sys.path.insert(0, os.path.join(B, "tools", "census"))
import chunks
from jdlz import jdlz_decompress

FMT = {0x29: "P8", 0x31545844: "DXT1", 0x33545844: "DXT3", 0x35545844: "DXT5", 0x15: "A8R8G8B8", 0x16: "X8R8G8B8"}


def mip_bytes(fmt, w, h, n):
    t = 0
    for _ in range(max(n, 1)):
        if fmt in ("DXT1", "DXT3", "DXT5"):
            t += max(1, (w + 3) // 4) * max(1, (h + 3) // 4) * (8 if fmt == "DXT1" else 16)
        else:
            t += w * h * (1 if fmt == "P8" else 4)
        w, h = max(1, w // 2), max(1, h // 2)
    return t


def packs(d):
    """Yield dicts per pack: header, records, gpu entries, index, streams, blob base offset (file offsets)."""
    out, errs = [], []
    chunks.walk(d, 0, len(d), 0, out, None, errs)
    cur, datas = None, {}
    for depth, off, cid, size, parent in out:
        p = off + 8
        if cid == 0xb3300000:
            cur = {"off": off, "recs": [], "gpu": [], "index": [], "streams": {}, "blob": None}
            datas.setdefault("packs", []).append(cur)
        elif cid == 0x33310001:
            cur["name"] = d[p + 4:p + 0x20].split(b"\0")[0].decode("latin1")
            cur["path"] = d[p + 0x20:p + 0x60].split(b"\0")[0].decode("latin1")
            cur["key"] = struct.unpack_from("<I", d, p + 0x60)[0]
        elif cid == 0x33310002:
            cur["index"] = [struct.unpack_from("<I", d, p + 8 * k)[0] for k in range(size // 8)]
        elif cid == 0x33310003:
            for k in range(size // 20):
                h, o, n, fl, z = struct.unpack_from("<5I", d, p + 20 * k)
                cur["streams"][h] = (cur["off"] + o, n)
        elif cid == 0x33310004:
            for k in range(size // 0x7c):
                r = p + 0x7c * k
                v = struct.unpack_from("<8I2h", d, r + 0x24)
                cur["recs"].append({"name": d[r + 0xc:r + 0x24].split(b"\0")[0].decode("latin1"), "hash": v[0],
                                    "pix": v[3], "pal": v[4], "npix": v[5], "npal": v[6], "mip0": v[7],
                                    "w": v[8], "h": v[9], "code": d[r + 0x4a], "paletted": d[r + 0x4d],
                                    "mips": d[r + 0x4e]})
        elif cid == 0x33310005:
            cur["gpu"] = [struct.unpack_from("<I", d, p + 0x20 * k + 0x14)[0] for k in range(size // 0x20)]
        elif cid == 0x33320001:
            node_key = struct.unpack_from("<I", d, p + 0xc)[0]
        elif cid == 0x33320002:   # binds to the latest pack with this key, as the loader meets them (0x545660)
            for pk in reversed(datas.get("packs", [])):
                if pk.get("key") == node_key:
                    pk["blob"] = ((p + 0x7f) & ~0x7f, p + size)
                    break
    yield from datas.get("packs", [])


def pixels(d, pk, r):
    """-> (pixel bytes, palette bytes) of record r."""
    if pk["streams"]:
        o, n = pk["streams"][r["hash"]]
        u = jdlz_decompress(d[o:o + n])   # same layout as the blob, starting at the record's pixel offset
        q = r["pal"] - r["pix"]
        return u[:r["npix"]], u[q:q + r["npal"]] if r["npal"] else b""
    base = pk["blob"][0]
    return d[base + r["pix"]:base + r["pix"] + r["npix"]], d[base + r["pal"]:base + r["pal"] + r["npal"]]


def dds(pk, r, pix, pal):
    fmt = FMT.get(pk["gpu"][pk["recs"].index(r)], "?")
    w, h, n = r["w"], r["h"], max(r["mips"], 1)
    if fmt == "P8":   # palette = 256 x 4 bytes, stored as R G B A (I: as the port's host expands it) -> BGRA
        lut = [pal[4 * i:4 * i + 4] for i in range(256)]
        pix = b"".join(bytes((c[2], c[1], c[0], c[3])) for c in (lut[i] for i in pix))
        fmt = "A8R8G8B8"
    flags = 0x1 | 0x2 | 0x4 | 0x1000 | (0x20000 if n > 1 else 0)
    if fmt.startswith("DXT"):
        pf = struct.pack("<II4s5I", 32, 0x4, fmt.encode(), 0, 0, 0, 0, 0)
        flags |= 0x80000
        pitch = r["mip0"]
    else:
        pf = struct.pack("<II4s5I", 32, 0x41, b"\0\0\0\0", 32, 0xff0000, 0xff00, 0xff, 0xff000000)
        flags |= 0x8
        pitch = w * 4
    hdr = struct.pack("<4sI", b"DDS ", 124) + struct.pack("<6I", flags, h, w, pitch, 0, n) + bytes(44) + pf
    hdr += struct.pack("<5I", 0x1000 | (0x400008 if n > 1 else 0), 0, 0, 0, 0)
    return hdr + pix


def main():
    a = sys.argv[1:]
    if not a or a[0] == "help":
        print(__doc__)
    elif a[0] == "list":
        d = chunks.load(a[1])
        for pk in packs(d):
            print(f"pack {pk['name']} ({pk['path']}) key {pk['key']:08x}, {len(pk['recs'])} textures"
                  f"{', JDLZ streams' if pk['streams'] else ''}")
            for r, g in zip(pk["recs"], pk["gpu"]):
                print(f"  {r['name']:24} {r['hash']:08x} {r['w']:4}x{r['h']:<4} {FMT.get(g, hex(g)):9} mips {r['mips']} "
                      f"pix +{r['pix']:#x} {r['npix']:#x}{' pal %#x' % r['npal'] if r['npal'] else ''}")
    elif a[0] == "dds":
        d = chunks.load(a[1])
        for pk in packs(d):
            for r in pk["recs"]:
                if r["name"].lower() == a[2].lower():
                    open(a[3], "wb").write(dds(pk, r, *pixels(d, pk, r)))
                    print(f"wrote {a[3]}: {r['w']}x{r['h']} {FMT.get(pk['gpu'][pk['recs'].index(r)])}")
                    return
        sys.exit("no such texture")
    elif a[0] == "check":
        npk = ntex = bad = 0
        sizes = {}
        for f in chunks.chunk_files():
            d = chunks.load(f)
            for pk in packs(d):
                npk += 1
                if pk["index"] != sorted(r["hash"] for r in pk["recs"]) or len(pk["gpu"]) != len(pk["recs"]):
                    bad += 1
                    print("INDEX", os.path.relpath(f, B), pk["name"])
                for r, g in zip(pk["recs"], pk["gpu"]):
                    ntex += 1
                    fmt = FMT.get(g, "?")
                    want = mip_bytes(fmt, r["w"], r["h"], r["mips"])
                    k = (fmt, want == r["npix"])
                    sizes[k] = sizes.get(k, 0) + 1
                    if not r["npix"]:
                        continue
                    if pk["streams"]:
                        o, n = pk["streams"][r["hash"]]
                        u = jdlz_decompress(d[o:o + n])
                        ok = len(u) == (r["pal"] - r["pix"] + r["npal"] if r["npal"] else r["npix"])
                    else:
                        lo, hi = pk["blob"]
                        ok = lo + r["pix"] + r["npix"] <= hi and lo + r["pal"] + r["npal"] <= hi
                    if not ok:
                        bad += 1
                        print("RANGE", os.path.relpath(f, B), pk["name"], r["name"])
        print(f"{npk} packs, {ntex} textures, bad {bad}")
        for (fmt, ok), n in sorted(sizes.items()):
            print(f"  {fmt:9} pixel size = mip sum: {ok} x {n}")
        sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
