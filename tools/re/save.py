"""Read-only reader for the profile files of NFS Underground (docs: scratchpad save_notes.md).

  save.py dump FILE     header, checksum (stored vs recomputed) and decoded fields of a .ugd / .opt / .usr / .cfg
  save.py check         the three real saves (save/a_autosave.ugd, save/asas_autosave.ugd, build/save-headless/
                        a_autosave.ugd) plus every other profile file found beside them: checksum recomputes and
                        the file re-packs byte for byte from parsed fields + raw remainder; exit 0 only if all do

Layouts come from Speed.exe (base 0x400000). One "player block" P lives at 0x7588c4 (size 0xf944; P+0 = name).
  .ugd  writer 0x41d8a0, reader 0x41da40, header-only reader 0x41db70, adler32 0x41dd10, pack 0x4ab120, unpack 0x4ab200
        u32 0x13 | 0x12 caption | 0x19 time stamp | 0xf660 block | u32 adler32(block)
        block = u32 0 | P+0x210 (4) | P+0x364..P+0xeee8 (0xeb84) | P+0xeee8 (4) | P+0xeef4 (0xa50) | P+0x214 (0x80)
        the 0xeb84 run holds: 10 customization records (0x338, base 0x758c30), 20 car records (0x348, 0x75ac60),
        the career object (0x75eef8 = P+0x6634, 0x88b4 bytes; reset 0x5a0a00)
  .opt  writer 0x41e200, reader 0x41e330, serializer 0x4aaad0, deserializer 0x4aac70
        u32 0x13 | 0x2e5 payload (pieces of P below 0x364 and P+0xeec) | u32 adler32(payload)
  .usr  (Profiles.usr) writer inside 0x41d2a0, loader 0x41d140: u32 count | count x 0x20 (name[8] + stack residue),
        most recently used first, no checksum
  .cfg  text "KEY: value" lines, table at 0x700ec0 (key, &variable, type), writer 0x41c7a0, reader 0x41c680
Names: car hashes are bStringHash of the car name (CarTypeInfo+0xd0, tools/re/carinfo.py).
"""
import os, struct, sys

B = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
P_BASE = 0x7588c4
VER = 0x13
CAP, STAMP, BLK = 0x12, 0x19, 0xf660
HDR = 4 + CAP + STAMP                       # 0x2f
# block pieces: (block offset, P offset, length); pack 0x4ab120 writes them in this order
UGD_REG = [(0x4, 0x210, 4), (0x8, 0x364, 0xeb84), (0xeb8c, 0xeee8, 4), (0xeb90, 0xeef4, 0xa50), (0xf5e0, 0x214, 0x80)]
OPT_LEN = 0x2e5
# .opt payload pieces: (payload offset, P offset, length); serializer 0x4aaad0 (payload +0 is a zero dword)
OPT_REG = [(0x04, 0x00, 0xd), (0x11, 0x10, 0x28), (0x39, 0x38, 0x3c), (0x75, 0x74, 0x1c), (0x91, 0x90, 0x1c),
           (0xad, 0xac, 8), (0xb5, 0xb4, 8), (0xbd, 0x294, 0xd0), (0x18d, 0xbc, 0x20), (0x1ad, 0xdc, 0x20),
           (0x1cd, 0xfc, 0x20), (0x1ed, 0x11c, 0x24), (0x211, 0x140, 0x84), (0x295, 0x1c4, 0x2c),
           (0x2c1, 0x1f0, 0x20), (0x2e1, 0xeec, 4)]
# P offsets inside the .ugd block
CUST_P, NCUST, CUST_SZ = 0x36c, 10, 0x338        # 0x758c30, bound check 0x4e7c47
CARS_P, NCARS, CAR_SZ = 0x239c, 20, 0x348        # 0x75ac60 .. count dword at 0x75ee00 (0x4bc170)
CAREER_P, CAREER_SZ = 0x6634, 0x88b4             # 0x75eef8
STATUS = {0: "locked", 1: "open", 2: "won", 3: "racing", 4: "4", 5: "quit"}
# career fields: (name, offset in career, struct fmt or byte length). Each one is read by the code named in the notes.
CAREER = [("car_hash", 0x08, "<I"), ("difficulty", 0x348, "<I"), ("status", 0x34c, 0x100), ("parts_vtable", 0x44c, "<I"),
          ("cash", 0x1374, "<i"), ("earned", 0x1378, "<i"), ("spent", 0x137c, "<i"), ("owns_car", 0x1384, "<H"),
          ("last_event", 0x1388, "<i"), ("last_flags", 0x138c, "<I"), ("seen_mask", 0x13a4, "<I"),
          ("tasks", 0x2e0, 0x2c), ("slot_done", 0x8884, 27), ("magazine_done", 0x88a0, 16)]


def adler32(d):
    """0x41dd10: a = 1, b = 0; a = (a + byte) % 0xfff1; b = (b + a) % 0xfff1; return b << 16 | a (same as zlib)."""
    a, b = 1, 0
    for x in d:
        a = (a + x) % 0xFFF1
        b = (b + a) % 0xFFF1
    return (b << 16) | a


def cstr(b):
    return b.split(b"\0")[0].decode("latin1")


def hash_names():
    """car-type hash -> name, from GLOBALB.BUN through carinfo.py (empty when the game files are absent)."""
    try:
        sys.path.insert(0, os.path.join(B, "tools", "re"))
        import carinfo
        d = open(carinfo.BUN, "rb").read()
        return {carinfo.bh(c["name"].encode()): c["name"] for c in carinfo.cars(d)[0]}
    except Exception:
        return {}


class Ugd:
    """version, caption, stamp, rest (block with the decoded fields zeroed) and the decoded career fields."""

    def __init__(self, data):
        if len(data) != HDR + BLK + 4:
            raise ValueError(f"size {len(data):#x}, expected {HDR + BLK + 4:#x}")
        self.version = struct.unpack_from("<I", data)[0]
        self.caption = data[4:4 + CAP]
        self.stamp = data[4 + CAP:HDR]
        self.stored = struct.unpack_from("<I", data, HDR + BLK)[0]
        block = bytearray(data[HDR:HDR + BLK])
        self.sum = adler32(block)
        self.career_at = 8 + CAREER_P - 0x364            # career inside the block (0x62d8)
        self.fields = {}
        for name, off, fmt in CAREER:
            o = self.career_at + off
            if isinstance(fmt, int):
                self.fields[name] = bytes(block[o:o + fmt]); block[o:o + fmt] = bytes(fmt)
            else:
                n = struct.calcsize(fmt)
                self.fields[name] = struct.unpack_from(fmt, block, o)[0]; block[o:o + n] = bytes(n)
        self.rest = bytes(block)

    def block(self):
        b = bytearray(self.rest)
        for name, off, fmt in CAREER:
            o = self.career_at + off
            if isinstance(fmt, int):
                b[o:o + fmt] = self.fields[name]
            else:
                struct.pack_into(fmt, b, o, self.fields[name])
        return bytes(b)

    def pack(self):
        b = self.block()
        return struct.pack("<I", self.version) + self.caption + self.stamp + b + struct.pack("<I", adler32(b))

    # P-space view: bytes of P[p:p+n] if the file carries all of them
    def p(self, p, n):
        b = self.block()
        for bo, po, ln in UGD_REG:
            if po <= p and p + n <= po + ln:
                return b[bo + p - po:bo + p - po + n]
        return None


class Opt:
    def __init__(self, data):
        if len(data) != 4 + OPT_LEN + 4:
            raise ValueError(f"size {len(data):#x}, expected {4 + OPT_LEN + 4:#x}")
        self.version = struct.unpack_from("<I", data)[0]
        self.payload = data[4:4 + OPT_LEN]
        self.stored = struct.unpack_from("<I", data, 4 + OPT_LEN)[0]
        self.sum = adler32(self.payload)
        # decoded: profile name (P+0, 13 bytes) and the nine audio floats (P+0x38; docs/re_audio_default.md)
        self.name_raw = self.p(0, 13)
        self.name = cstr(self.name_raw)
        self.audio = list(struct.unpack("<9f", self.p(0x38, 36)))
        self.rest = bytearray(self.payload)
        for bo, po, ln in OPT_REG:                              # zero the decoded slots
            if po == 0: self.rest[bo:bo + 13] = bytes(13)
            if po == 0x38: self.rest[bo:bo + 36] = bytes(36)

    def p(self, p, n):
        for bo, po, ln in OPT_REG:
            if po <= p and p + n <= po + ln:
                return self.payload[bo + p - po:bo + p - po + n]
        return None

    def pack(self):
        b = bytearray(self.rest)
        b[4:4 + 13] = self.name_raw
        b[0x39:0x39 + 36] = struct.pack("<9f", *self.audio)
        return struct.pack("<I", self.version) + bytes(b) + struct.pack("<I", adler32(bytes(b)))


class Usr:
    def __init__(self, data):
        self.count = struct.unpack_from("<I", data)[0]
        if len(data) != 4 + 0x20 * self.count:
            raise ValueError("size does not match count")
        self.recs = [data[4 + 0x20 * i:4 + 0x20 * (i + 1)] for i in range(self.count)]

    def pack(self):
        return struct.pack("<I", self.count) + b"".join(self.recs)


class Cfg:
    """Lines "KEY: value" (value = decimal int for every row of the table at 0x700ec0), then two empty lines (0x41c7a0)."""

    def __init__(self, data):
        text = data.decode("latin1")
        body = text.rstrip("\r\n")
        self.tail = text[len(body):]                           # the closing "\r\n" run, kept raw
        self.rows = [l.split(": ", 1) for l in body.split("\r\n")]

    def pack(self):
        return ("\r\n".join(f"{k}: {v}" for k, v in self.rows) + self.tail).encode("latin1")


def kind(path):
    e = os.path.splitext(path)[1].lower()
    return {".ugd": Ugd, ".opt": Opt, ".usr": Usr, ".cfg": Cfg}[e]


def dump_ugd(u, out):
    names = hash_names()
    nm = lambda h: names.get(h, f"{h:#x}")
    out(f"version  {u.version:#x} ({'ok' if u.version == VER else 'BAD, reader 0x41da40 needs 0x13'})")
    out(f"caption  {cstr(u.caption)!r}  raw {u.caption.hex()}")
    out(f"stamp    {cstr(u.stamp)!r}  (time, space, date; 25-byte stack buffer)")
    out(f"adler32  stored {u.stored:#010x}  recomputed {u.sum:#010x}  {'OK' if u.stored == u.sum else 'MISMATCH'}")
    f = u.fields
    out("career object 0x75eef8 (P+0x6634):")
    out(f"  current car      {nm(f['car_hash'])}  (+0x08)")
    out(f"  difficulty       {f['difficulty']}  (+0x348)")
    out(f"  cash             {f['cash']}  earned {f['earned']}  spent {f['spent']}  (+0x1374/78/7c; cash = earned - spent: "
        f"{'yes' if f['cash'] == f['earned'] - f['spent'] else 'no'})")
    out(f"  owns a car       {f['owns_car']}  (+0x1384)   last won event {f['last_event']}  flags {f['last_flags']:#x}")
    out(f"  seen mask        {f['seen_mask']:#x}  (+0x13a4)")
    st = f["status"]
    cnt = {s: [i for i, v in enumerate(st) if v == s] for s in sorted(set(st)) if s or any(st)}
    for s, ids in cnt.items():
        if s:
            out(f"  status {STATUS.get(s, s)}: {len(ids)} ids  {ids if len(ids) <= 40 else ids[:40] + ['...']}")
    out(f"  task counters   {list(struct.unpack('<11I', f['tasks'][:44]))}  (+0x2e0)")
    out(f"  unlock slots announced (+0x8884): {[i for i, v in enumerate(f['slot_done']) if v]}")
    b = u.block()
    car = lambda i: b[8 + CARS_P - 0x364 + i * CAR_SZ:8 + CARS_P - 0x364 + (i + 1) * CAR_SZ]
    owned = [(i, nm(struct.unpack_from("<I", car(i), 8)[0]), car(i)[0xc]) for i in range(NCARS)]
    out("car records (20 x 0x348 at P+0x239c; +8 type hash, +0xc customization index, 0xff = none): "
        + ", ".join(f"{i}:{n}" + (f"@{c}" if c != 0xff else "") for i, n, c in owned))
    slots = []
    for i in range(27):
        e = b[u.career_at + 0x13a8 + i * 0x454:u.career_at + 0x13a8 + (i + 1) * 0x454]
        if any(e[:2]):
            slots.append((i, e[0], e[1], nm(struct.unpack_from("<I", e, 0xc)[0])))
    out(f"unlock slots in use (27 x 0x454 at +0x13a8) (index, byte0, byte1, car): {slots}")
    rows = []
    for p in range(25):
        row = [x for x in struct.unpack_from("<36I", u.block(), u.career_at + 0x450 + p * 0x90) if x]
        if row:
            rows.append((p, len(row)))
    out(f"bought parts (+0x450, 25 rows x 36 keys) rows with keys: {rows}")


def dump_opt(o, out):
    out(f"version  {o.version:#x}\nadler32  stored {o.stored:#010x}  recomputed {o.sum:#010x}  "
        f"{'OK' if o.stored == o.sum else 'MISMATCH'}")
    out(f"profile name (P+0) {o.name!r}")
    out("audio floats P+0x38..: " + " ".join(f"{x:.2f}" for x in o.audio) + "   (b0 master, b1 music, b2.. per docs/re_audio_default.md)")


def dump(path, out=print):
    d = open(path, "rb").read()
    k = kind(path)(d)
    out(f"{path}  {len(d)} bytes")
    if isinstance(k, Ugd):
        dump_ugd(k, out)
    elif isinstance(k, Opt):
        dump_opt(k, out)
    elif isinstance(k, Usr):
        out(f"{k.count} profiles, most recent first: {[cstr(r[:8]) for r in k.recs]}")
    else:
        out("\n".join(f"{a}: {b}" for a, b in k.rows))


def check():
    real = ["save/a_autosave.ugd", "save/asas_autosave.ugd", "build/save-headless/a_autosave.ugd"]
    extra = ["save/asas0.ugd", "save/a.opt", "save/asas.opt", "save/Profiles.usr", "save/a.cfg", "save/asas.cfg"]
    bad = 0
    for rel in real + extra:
        p = os.path.join(B, rel)
        if not os.path.exists(p):
            if rel in real:
                print(f"MISSING {rel}"); bad += 1
            continue
        d = open(p, "rb").read()
        try:
            k = kind(p)(d)
            ok = k.pack() == d
            msg = "repack " + ("equal" if ok else "DIFFERENT")
            if isinstance(k, (Ugd, Opt)):
                ok = ok and k.stored == k.sum and k.version == VER
                msg += f", adler {k.stored:#010x} vs {k.sum:#010x} " + ("OK" if k.stored == k.sum else "MISMATCH")
        except Exception as e:
            ok, msg = False, f"error {e}"
        print(("ok   " if ok else "FAIL ") + rel + "  " + msg)
        bad += not ok
    return 1 if bad else 0


if __name__ == "__main__":
    a = sys.argv[1:]
    if a[:1] == ["dump"] and len(a) == 2:
        dump(a[1])
    elif a[:1] == ["check"]:
        sys.exit(check())
    else:
        print(__doc__); sys.exit(2)
