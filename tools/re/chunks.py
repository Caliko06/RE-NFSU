"""Read-only walker for the bChunk files of Speed.exe (BUN, BIN, LZC) — docs/re/assets.md.

  chunks.py tree FILE [depth]   print the chunk tree of one file (LZC/JDLZ is decompressed first)
  chunks.py census [out.json]   walk every BUN/BIN/LZC under game/, count each chunk id and where it sits
  chunks.py check               every chunk file tiles exactly (children fill their parent to the byte)

Format (V, loader 0x447c00 and dispatcher 0x447ac0): a chunk is u32 id, u32 size, then `size` bytes. Bit 31 of the id
marks a container whose payload is more chunks. Id 0 is padding. The game hands every top-level chunk to the 47
loaders in the table at 0x7007e0 (unloaders at 0x7008a0) until one returns non-zero; LOADERS below lists them.
"""
import json, os, struct, sys

B = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
GAME = os.path.join(B, "game")
sys.path.insert(0, os.path.join(B, "tools", "census"))

# Table 0x7007e0 index -> (load fn, unload fn, top-level ids it accepts). Ids read from the cmp/sub in each loader
# (capstone over Speed.exe; thunks followed one level). Owner names are I unless docs/re/assets.md marks V.
LOADERS = [
    (0, 0x447ab0, 0x447ab0, [0x0], "padding (accepts id 0)"),
    (1, 0x575940, 0x575940, [], "stub, never accepts"),
    (2, 0x441ed0, 0x441f40, [0x34146, 0x34130, 0x34131, 0x34132, 0x34133, 0x34134], "track markers; collision via 0x441380"),
    (3, 0x442040, 0x442080, [0x34201], "track list (TrackInfo rows 0xfc)"),
    (4, 0x5455c0, 0x545770, [0xb3300000, 0xb3320000, 0xb0300100], "texture pack, anim pack; 0xb3310000 only as child (0x5453d0)"),
    (5, 0x4f4420, 0x4f4470, [0x30201], "FEng font"),
    (6, 0x540420, 0x540440, [0x80134001], "solid list (models)"),
    (7, 0x540460, 0x5404e0, [0x80134000, 0x80134010], "solid pack (models)"),
    (8, 0x540f10, 0x5410b0, [0x80135000, 0x80135100, 0x135200], "light pack"),
    (9, 0x402820, 0x4028f0, [0x80035000, 0x80035010, 0x35020, 0x35021], ""),
    (10, 0x58dde0, 0x58deb0, [0x80036000], "scenery"),
    (11, 0x472b00, 0x472c00, [0x80034020], "car geometry (car hull, 0x39200)"),
    (12, 0x4457c0, 0x445b60, [0x80034100, 0x34101, 0x34102, 0x34103, 0x34104], "track streamer sections"),
    (13, 0x446aa0, 0x446ab0, [0x80034150], "via 0x446db0"),
    (14, 0x47ce50, 0x47ced0, [0xe34010], ""),
    (15, 0x5a4de0, 0x5a4e90, [0xe34009], "EAGL animation (CAnimSkeleton)"),
    (16, 0x47b890, 0x47b8d0, [0x34035], ""),
    (17, 0x47b7b0, 0x47b7f0, [0x34036], ""),
    (18, 0x47e230, 0x47e250, [0x34492, 0x80034405, 0x80034410, 0x80034415, 0x80034420, 0x80034425], "camera shake 0x34492; containers unused; via 0x47dcd0"),
    (19, 0x5462d0, 0x546570, [0x34202], "track info (sun/sky)"),
    (20, 0x57c8b0, 0x57cb70, [0x34600, 0x34601, 0x80034602], "car type info, colours, car part database"),
    (21, 0x436000, 0x436020, [0x34a07], ""),
    (22, 0x58d4c0, 0x58d500, [0x34030], ""),
    (23, 0x442dd0, 0x442e60, [0x34121, 0x34122, 0x34123, 0x34124], "road network (traffic roads)"),
    (24, 0x4441f0, 0x444200, [0x80034147], "via 0x4434d0, street-net container"),
    (25, 0x58d140, 0x58d140, [0x37010], ""),
    (26, 0x592a50, 0x592ab0, [0x34300, 0x34301], ""),
    (27, 0x462070, 0x4620a0, [0x34b00], ""),
    (28, 0x59fce0, 0x59fd40, [0x39000], "language strings"),
    (29, 0x5952a0, 0x5954c0, [0x34026, 0x34027], "props / smackables"),
    (30, 0x588d10, 0x588d70, [0x34250], "trigger volumes"),
    (31, 0x573150, 0x573160, [0x39100, 0x39101, 0x39102], "via 0x573080"),
    (32, 0x59e620, 0x59e660, [0x3a000], ""),
    (33, 0x4f4290, 0x4f42c0, [0x30203, 0x30210], "FEng package"),
    (34, 0x59dd90, 0x59de20, [0x8003b000], ""),
    (35, 0x4442a0, 0x4442f0, [0x34107, 0x34108], "street-net rows"),
    (36, 0x483080, 0x4830b0, [0x3b200], ""),
    (37, 0x5a00a0, 0x5a0130, [0x80034a00], "career events (EventDesc 0x34a02)"),
    (38, 0x5787e0, 0x578800, [0x3b300], ""),
    (39, 0x4b25b0, 0x4b2600, [0x30220], ""),
    (40, 0x51c180, 0x51c340, [0x30230], ""),
    (41, 0x51bd70, 0x51bdc0, [0x30240], ""),
    (42, 0x5a01d0, 0x5a0200, [0x34a08], "career"),
    (43, 0x5a36a0, 0x5a36d0, [0x34a03], "career"),
    (44, 0x5a0270, 0x5a0290, [0x34a09], "career"),
    (45, 0x5a02c0, 0x5a02f0, [0x34a0a], "career"),
    (46, 0x5ab640, 0x5ab700, [0x39010], ""),
]
OWNER = {i: k for k, _, _, ids, _ in LOADERS for i in ids}


def load(path):
    d = open(path, "rb").read()
    if d[:4] == b"JDLZ":
        from jdlz import jdlz_decompress
        d = jdlz_decompress(d)
    return d


def walk(d, off, end, depth, out, parent, errs):
    """Append (depth, off, id, size, parent) for each chunk in d[off:end]; container = bit 31."""
    while off < end:
        if end - off < 8:
            errs.append(("tail", off, end - off))
            return
        cid, size = struct.unpack_from("<II", d, off)
        if off + 8 + size > end:
            errs.append(("overrun", off, cid, size, end))
            return
        out.append((depth, off, cid, size, parent))
        if cid & 0x80000000 and size:
            walk(d, off + 8, off + 8 + size, depth + 1, out, cid, errs)
        off += 8 + size


def chunk_files():
    for r, _, fs in sorted(os.walk(GAME)):
        for f in sorted(fs):
            if f.rsplit(".", 1)[-1].upper() in ("BUN", "BIN", "LZC"):
                p = os.path.join(r, f)
                if os.path.getsize(p):
                    yield p


def is_chunk_file(d):
    """True if the file tiles as top-level chunks (some .BIN are other formats: Racer.bin, EReg.bin, languages)."""
    out, errs = [], []
    walk(d, 0, len(d), 0, out, None, errs)
    return not errs and out


def main():
    a = sys.argv[1:]
    if not a or a[0] == "help":
        print(__doc__)
    elif a[0] == "tree":
        d = load(a[1])
        lim = int(a[2]) if len(a) > 2 else 99
        out, errs = [], []
        walk(d, 0, len(d), 0, out, None, errs)
        for depth, off, cid, size, _ in out:
            if depth <= lim:
                k = OWNER.get(cid)
                own = f"  loader#{k} {LOADERS[k][4]}" if k is not None and depth == 0 else ""
                print(f"{'  ' * depth}{cid:#010x} @{off:#x} size {size:#x}{own}")
        for e in errs:
            print("ERROR", e)
    elif a[0] in ("census", "check"):
        ids, bad, other = {}, [], []
        for p in chunk_files():
            rel = os.path.relpath(p, GAME)
            d = load(p)
            out, errs = [], []
            walk(d, 0, len(d), 0, out, None, errs)
            if errs:
                (other if not out or len(out) < 2 else bad).append((rel, errs[:2]))
                if not out or len(out) < 2:
                    continue
            for depth, off, cid, size, parent in out:
                r = ids.setdefault(f"{cid:#010x}", {"n": 0, "files": 0, "depths": [], "parents": [], "min": size,
                                                     "max": size, "loader": OWNER.get(cid), "_f": set()})
                r["n"] += 1
                r["_f"].add(rel)
                r["min"], r["max"] = min(r["min"], size), max(r["max"], size)
                if depth not in r["depths"]:
                    r["depths"].append(depth)
                pp = f"{parent:#010x}" if parent is not None else "top"
                if pp not in r["parents"]:
                    r["parents"].append(pp)
        for r in ids.values():
            r["files"] = len(r["_f"])
            r["example"] = sorted(r.pop("_f"))[0]
        if a[0] == "check":
            top = [k for k, r in ids.items() if "top" in r["parents"]]
            orphan = [k for k in top if ids[k]["loader"] is None]
            print(f"chunk files that tile: {len(list(chunk_files())) - len(bad) - len(other)}, broken: {len(bad)}, "
                  f"not chunk files: {len(other)}")
            for x in bad:
                print("  BROKEN", x)
            for x in other:
                print("  other format", x[0])
            print(f"ids: {len(ids)}, top-level: {len(top)}, top-level without a loader: {orphan}")
            sys.exit(1 if bad else 0)
        json.dump(dict(sorted(ids.items())), open(a[1] if len(a) > 1 else "/dev/stdout", "w"), indent=1)


if __name__ == "__main__":
    main()
