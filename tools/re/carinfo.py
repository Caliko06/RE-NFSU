"""Read-only reader for the car tables in game/Global/GLOBALB.BUN (docs/re/tuning.md).

  carinfo.py cars [CAR]        CarTypeInfo (chunk 0x34600): names, base physics, upgrade tables per level
  carinfo.py parts [TYPE]      car part database (chunk 0x80034602): name, car, type, level, attributes
  carinfo.py check             parse both chunks and re-pack them; must equal the file bytes (round trip)

Layouts come from the loader 0x57c8b0 (chunk ids, 35 x 0xc90 records, 0x30-byte parts, 8-byte attributes) and the
physics builders 0x575960..0x576360 (which offset each upgrade level reads). Names are bStringHash (h*33+c from
0xffffffff), checked against the strings in Speed.exe and GLOBALB.BUN.
"""
import json, os, re, struct, sys

B = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
BUN = os.path.join(B, "game", "Global", "GLOBALB.BUN")
CARINFO, PARTDB = 0x34600, 0x80034602
NCARS, CARSZ, PHYS = 0x23, 0xc90, 0x110          # loader 0x57c8b0 loops 0x23 records of 0xc90; physics at +0x110

# Upgrade tables, offsets from CarTypeInfo+0x110 (the CarPhysicsInfo the builder copies 0x2b0 bytes of).
# Level n (1..3) lives at base + (n-1)*size. Path = index into PhysicsUpgradeSpecification (RideInfo+8).
UPGRADES = [  # (path, name, base, size, builder)
    (0, "weight", 0x2b0, 0x10, "0x576250"),        # {mass factor, add to [0], [0x58]}
    (6, "transmission", 0x2e0, 0x40, "0x576360"),  # whole gear set: final drive, reverse, gears 1..6
    (2, "engine", 0x3a0, 0x40, "0x575bc0"),        # adds to torque curve +0x1f0..0x220 and +0x248..0x250
    (5, "ecu", 0x460, 0x40, "0x575bc0"),           # same shape as engine; first floats raise rpm limits
    (3, "turbo", 0x520, 0x30, "0x575bc0"),         # 9 floats: turbo torque curve, also added to the torque curve
    (7, "tires", 0x5b0, 0x40, "0x575a90"),         # 8 floats front grip block, 8 rear
    (4, "nitrous", 0x670, 0x10, "0x575bc0"),       # {seconds, shots (int), ?, strength}
    (9, "spoiler", 0x6a0, 0x10, "0x575b30"),       # 3 floats added to aero +0x264..0x26c
    (10, "ground_effects", 0x6d0, 0x10, "0x575b30"),
    (8, "brakes", 0x700, 0x10, "0x575960"),        # 3 floats to +0x274..0x27c
    (1, "suspension", 0x730, 0x50, "0x575a10"),    # 8+8 floats springs/dampers, ride height deltas
]
JUNKMAN = [  # one-off Junkman part per path: float(s) added on top (spec+0x2c.. flags)
    (0, "weight", 0x820, 1), (6, "transmission", 0x824, 1), (4, "nitrous", 0x828, 1), (8, "brakes", 0x82c, 1),
    (7, "tires", 0x830, 4), (2, "engine", 0x840, 9), (5, "ecu", 0x864, 9), (3, "turbo", 0x888, 9),
]
BASE = {  # named fields of the base CarPhysicsInfo (offsets from +0x110), V = read by a builder or a consumer
    "mass": 0x110, "nitrous_seconds": 0x2a0, "nitrous_shots": 0x2a4, "nitrous_strength": 0x2ac,
}
PART_TYPES = {  # CarPart type byte (+0x10); names from the garage category strings and the attributes each type has
    0: "base", 1: "body_kit", 2: "body_kit2", 7: "rim_brand", 8: "decal", 17: "rim", 30: "paint", 31: "vinyl",
    115: "window_tint", 116: "neon",
}


def bh(s):
    h = 0xFFFFFFFF
    for c in s:
        h = (h * 33 + c) & 0xFFFFFFFF
    return h


def chunks(d, off=0, end=None):
    end = len(d) if end is None else end
    while off + 8 <= end:
        cid, size = struct.unpack_from("<II", d, off)
        yield cid, off, size
        off += 8 + size


def find(d, cid):
    for c, off, size in chunks(d):
        if c == cid:
            return off, size
    raise SystemExit(f"chunk {cid:#x} not found")


def names(d):
    exe = open(os.path.join(B, "pc", "Speed.exe"), "rb").read()
    rev = {}
    for b in (exe, d):
        for m in re.finditer(rb"[\x20-\x7e]{1,48}", b):
            rev.setdefault(bh(m.group()), m.group().decode())
    return rev


def cars(d):
    off, size = find(d, CARINFO)
    base = (off + 8 + 15) & ~15             # loader: (chunk + 0x17) & ~0xf
    out = []
    for i in range(NCARS):
        r = base + i * CARSZ
        p = r + PHYS
        f = lambda o, n: list(struct.unpack_from(f"<{n}f", d, p + o))
        strs = [s.decode("latin1") for s in re.findall(rb"[\x20-\x7e]{2,}", d[r:r + PHYS])]
        car = {"index": i, "name": strs[0], "geometry": strs[2:4], "maker": strs[4] if len(strs) > 4 else "",
               "usage": struct.unpack_from("<I", d, r + 0xc54)[0],   # 0 = tuner (0x581d30 runs), 2 = traffic
               "mass": f(0x110, 1)[0], "nitrous": f(0x2a0, 4), "upgrades": {}, "junkman": {}}
        for path, name, o, sz, _ in UPGRADES:
            car["upgrades"][name] = [f(o + k * sz, sz // 4) for k in range(3)]
        for path, name, o, n in JUNKMAN:
            car["junkman"][name] = f(o, n)
        out.append(car)
    return out, base


def parts(d, rev=None):
    off, size = find(d, PARTDB)
    sub = {c: (o, s) for c, o, s in chunks(d, off + 8, off + 8 + size)}
    so, ao, po = sub[0x34606][0] + 8, sub[0x34605][0] + 8, sub[0x34604][0] + 8
    hdr = struct.unpack_from("<8I", d, sub[0x34603][0] + 8)
    n, na = hdr[4], hdr[6]
    rev = rev or {}
    out = []
    for i in range(n):
        r = struct.unpack_from("<IIIIBBBBIIHHIIII", d, po + i * 0x30)
        e = d.index(b"\0", so + r[0])
        attrs = [struct.unpack_from("<II", d, ao + (r[8] + k) * 8) for k in range(r[10])]
        out.append({"index": i, "name": d[so + r[0]:e].decode("latin1"), "car": rev.get(r[1], f"{r[1]:#x}"),
                    "hash": r[2], "brand": rev.get(r[3], f"{r[3]:#x}") if r[3] else "", "type": r[4],
                    "level": r[5], "sub": r[6], "attrs": [(rev.get(h, f"{h:#x}"), v) for h, v in attrs],
                    "raw": r})
    return out, hdr, (so, ao, po, na)


def check(d):
    cs, base = cars(d)
    ok = 0
    for c in cs:   # re-pack the decoded upgrade and junkman floats and compare with the file
        p = base + c["index"] * CARSZ + PHYS
        for path, name, o, sz, _ in UPGRADES:
            for k, row in enumerate(c["upgrades"][name]):
                ok += struct.pack(f"<{len(row)}f", *row) == d[p + o + k * sz:p + o + (k + 1) * sz]
        for path, name, o, n in JUNKMAN:
            ok += struct.pack(f"<{n}f", *c["junkman"][name]) == d[p + o:p + o + 4 * n]
    want = NCARS * (len(UPGRADES) * 3 + len(JUNKMAN))
    print(f"cars: {len(cs)} records, {ok}/{want} tables re-pack byte-equal;",
          f"tuners {sum(c['usage'] == 0 for c in cs)}, traffic {sum(c['usage'] == 2 for c in cs)}")
    ps, hdr, (so, ao, po, na) = parts(d)
    same = sum(struct.pack("<IIIIBBBBIIHHIIII", *p["raw"]) == d[po + p["index"] * 0x30:po + p["index"] * 0x30 + 0x30]
               for p in ps)
    used = sum(len(p["attrs"]) for p in ps)
    print(f"parts: {len(ps)} (header {hdr[4]}), {same} re-pack byte-equal; attributes used {used} of {na} (header {hdr[6]})")
    return ok == want and same == len(ps) == hdr[4]


def main(a):
    d = open(BUN, "rb").read()
    if not a or a[0] == "check":
        sys.exit(0 if check(d) else 1)
    if a[0] == "cars":
        cs, _ = cars(d)
        print(json.dumps([c for c in cs if len(a) < 2 or c["name"] == a[1]], indent=1))
    elif a[0] == "parts":
        ps, _, _ = parts(d, names(d))
        for p in ps:
            if len(a) < 2 or str(p["type"]) == a[1]:
                p.pop("raw")
                print(json.dumps(p))


if __name__ == "__main__":
    main(sys.argv[1:])
