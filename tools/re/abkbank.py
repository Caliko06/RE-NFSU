"""Read-only reader for the sample banks inside game/Sound/**/*.abk; docs/re/sound.md.

  abkbank.py list FILE     ABKC header fields and every sample of its BNKl bank (slot, rate, samples, seconds, data)
  abkbank.py check         parse all 106 files; every non-empty slot must be a PT header whose data offset (tag 0x88)
                           lies inside the BNKl bank; exit 1 otherwise

ABKC header (the code part is tools/recomp/abk.py): +0x10 module id, +0x14 file size, +0x18 header size (= start of
the bank), +0x20 bank offset, +0x24 bank size, +0x30/+0x34 relocation tables. BNKl: u16 version (5), u16 slot
count, u32 bank size, slots at +0x10 as u32 offsets relative to the slot itself (0 = empty) to a PT tag list
(same tags as tools/re/ast.py).
"""
import glob, os, struct, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ast import pt  # noqa: E402  (tools/re/ast.py, not the stdlib module: this dir is first on sys.path)

B = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def bank(path):
    d = open(path, "rb").read()
    if d[:4] != b"ABKC":
        raise ValueError(f"{path}: not ABKC")
    mod_id, fsize, hsize = struct.unpack_from("<III", d, 0x10)
    boff, bsize = struct.unpack_from("<II", d, 0x20)
    info = {"file": path, "module": mod_id, "size_ok": fsize == len(d), "header": hsize, "bank": boff, "bank_size": bsize,
            "samples": [], "bad": []}
    if not boff:
        return info
    if d[boff:boff + 4] != b"BNKl":
        info["bad"].append(boff)
        return info
    ver, n, size = struct.unpack_from("<HHI", d, boff + 4)
    info["version"] = ver
    for k in range(n):
        p = boff + 0x10 + 4 * k
        o = struct.unpack_from("<I", d, p)[0]
        if not o:
            continue
        q = p + o
        if d[q:q + 2] != b"PT":
            info["bad"].append(q)
            continue
        h = pt(d, q + 4, q + 0x100)
        h["slot"] = k
        if not 0 <= h.get("t88", -1) < bsize:
            info["bad"].append(q)
        info["samples"].append(h)
    return info


def files():
    return sorted(glob.glob(os.path.join(B, "game", "Sound", "**", "*.abk"), recursive=True), key=str.lower)


def main(a):
    if a and a[0] == "list":
        i = bank(a[1])
        print({k: v for k, v in i.items() if k != "samples"})
        for s in i["samples"]:
            r = s.get("rate", 22050)
            print(f"slot {s['slot']:3d} rate={r} samples={s.get('samples', 0)} sec={s.get('samples', 0) / r:.2f} "
                  f"data={s.get('t88')} ch={s.get('channels', 1)}")
        return
    ok, tot, nb, secs = True, 0, 0, 0.0
    for f in files():
        i = bank(f)
        ok &= i["size_ok"] and not i["bad"]
        nb += bool(i["bank"])
        tot += len(i["samples"])
        secs += sum(s.get("samples", 0) / s.get("rate", 22050) for s in i["samples"])
        if i["bad"] or not i["size_ok"]:
            print("BAD", f, i["bad"][:3], i["size_ok"])
    print(f"{len(files())} ABK files, {nb} with a BNKl bank, {tot} samples, {secs / 60:.1f} min; all valid: {ok}")
    sys.exit(0 if ok else 1)


if __name__ == "__main__":
    main(sys.argv[1:])
