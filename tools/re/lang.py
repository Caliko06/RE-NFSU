"""Read-only reader for the language string tables (chunk 0x39000) — docs/re/canon.md "Text".

  lang.py dump [LANG] [filter]   label, hash and text of every string (LANG = English, Korean, ...; default English)
  lang.py get HASH|LABEL [LANG]  one string
  lang.py check                  every 0x39000 file under game/Languages re-packs byte-for-byte; labels hash right

Chunk 0x39000 (loader 0x59fce0 stores four globals):
  +0x00 u32 charset offset   -> [0x734438]  charset = u32 n, u16[n]: index -> Unicode code point
  +0x04 u32 count            -> [0x73442c]
  +0x08 u32 table offset     -> [0x734434]  count x {u32 hash, u32 string offset}, sorted by hash (binary search 0x59fb80)
  +0x0c u32 strings offset   -> [0x734430]  NUL-terminated byte strings; the loader adds this base to every offset
Offsets are from the chunk payload. hash = bStringHash(label) (h*33+c from 0xffffffff); the labels are the strings of
Labels.bin (3843 of 3846 keys re-hash; 3 keys have no label). Bytes < 0x80 are ASCII. In Korean, a byte >= 0x86 is
charset[byte], and a lead byte 0x80..0x85 with trail t is charset[t + (0x86 - lead) * 0x80]: every Korean string decodes
with no hole. Western files use charset[b] = b (Latin-1). Each language file also carries its FEng fonts (0x30201).
The game opens LANGUAGES\\<NAME>.BIN (strings in Speed.exe); LANGUAGE_*.BIN (3845 strings) are not named in Speed.exe.
"""
import os, struct, sys

B = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
LANG = os.path.join(B, "game", "Languages")


def bh(s):
    h = 0xFFFFFFFF
    for c in s:
        h = (h * 33 + c) & 0xFFFFFFFF
    return h


def parse(d):
    """-> dict with the header fields, charset, entries [(hash, offset)], strings {offset: bytes}, end of chunk."""
    cid, size = struct.unpack_from("<II", d, 0)
    assert cid == 0x39000, hex(cid)
    p = 8
    co, n, to, so = struct.unpack_from("<4I", d, p)
    nchar = struct.unpack_from("<I", d, p + co)[0]
    charset = struct.unpack_from("<%dH" % nchar, d, p + co + 4)
    ent = [struct.unpack_from("<II", d, p + to + 8 * k) for k in range(n)]
    strs = {}
    for _, o in ent:
        a = p + so + o
        strs[o] = d[a:d.index(b"\0", a)]
    return dict(co=co, to=to, so=so, charset=charset, ent=ent, strs=strs, size=size, end=8 + size)


def text(t, b):
    cs, out, i = t["charset"], [], 0
    while i < len(b):
        c = b[i]
        if c < 0x80 or len(cs) <= 0x100:
            out.append(chr(c))
            i += 1
        elif c >= 0x86:
            out.append(chr(cs[c]))
            i += 1
        else:
            out.append(chr(cs[b[i + 1] + (0x86 - c) * 0x80]))
            i += 2
    return "".join(out)


def repack(t, d):
    """Rebuild the chunk from the parsed parts; padding between parts is copied from the gaps (all zero, checked)."""
    p = 8
    out = bytearray(d[:p])
    out += struct.pack("<4I", t["co"], len(t["ent"]), t["to"], t["so"])
    gap = d[p + 16:p + t["co"]]
    assert not any(gap)
    out += gap + struct.pack("<I", len(t["charset"])) + struct.pack("<%dH" % len(t["charset"]), *t["charset"])
    out += bytes(p + t["to"] - len(out))
    for h, o in t["ent"]:
        out += struct.pack("<II", h, o)
    out += bytes(p + t["so"] - len(out))
    for o in sorted(t["strs"]):
        assert len(out) == p + t["so"] + o, "strings are packed in offset order"
        out += t["strs"][o] + b"\0"
    out += bytes(t["end"] - len(out))
    return bytes(out)


def load(name):
    return open(os.path.join(LANG, name + ".bin"), "rb").read()


def labels():
    t = parse(load("Labels"))
    return {h: t["strs"][o].decode() for h, o in t["ent"]}


def main():
    a = sys.argv[1:]
    if not a or a[0] == "help":
        print(__doc__)
    elif a[0] == "dump":
        t = parse(load(a[1] if len(a) > 1 else "English"))
        lab, f = labels(), (a[2].lower() if len(a) > 2 else "")
        for h, o in t["ent"]:
            s = text(t, t["strs"][o])
            if f in s.lower() or f in lab.get(h, "").lower():
                print(f"{h:08x}\t{lab.get(h, '?')}\t{s}")
    elif a[0] == "get":
        t, lab = parse(load(a[2] if len(a) > 2 else "English")), labels()
        h = int(a[1], 16) if all(c in "0123456789abcdefABCDEFx" for c in a[1]) else bh(a[1].encode())
        print(f"{h:08x}\t{lab.get(h, '?')}\t" + next((text(t, t["strs"][o]) for k, o in t["ent"] if k == h), "<none>"))
    elif a[0] == "check":
        bad = 0
        for f in sorted(os.listdir(LANG)):
            d = open(os.path.join(LANG, f), "rb").read()
            if not f.lower().endswith(".bin") or d[:4] != b"\x00\x90\x03\x00":
                continue
            t = parse(d)
            ok = repack(t, d) == d[:t["end"]]
            srt = [h for h, _ in t["ent"]] == sorted(h for h, _ in t["ent"])
            holes = sum(text(t, s).count("\0") for s in t["strs"].values())
            bad += not (ok and srt and not holes)
            print(f"{f:24} {len(t['ent'])} strings, charset {len(t['charset'])}, repack {'OK' if ok else 'FAIL'}, "
                  f"sorted {srt}, undecodable {holes}")
        lab = labels()
        n = sum(bh(v.encode()) == h for h, v in lab.items())
        print(f"labels: {n}/{len(lab)} keys = bStringHash(label)")
        sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
