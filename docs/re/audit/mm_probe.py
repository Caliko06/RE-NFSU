import ctypes, os, sys, pefile
sys.path.insert(0, "tools/recomp")
lib = ctypes.CDLL(os.path.abspath("build/difftest.dylib"))
class Ctx(ctypes.Structure):
    _fields_ = [("r", ctypes.c_uint32 * 8), ("mem", ctypes.c_void_p), ("memsz", ctypes.c_uint32), ("ret", ctypes.c_uint32),
                ("halt", ctypes.c_uint32), ("halt_at", ctypes.c_uint32), ("why", ctypes.c_char_p), ("fs", ctypes.c_uint32),
                ("flags", ctypes.c_int32 * 7), ("eflx", ctypes.c_uint32), ("fcw", ctypes.c_uint32), ("fsw", ctypes.c_uint32),
                ("ftop", ctypes.c_uint32), ("ftag", ctypes.c_uint32), ("st", ctypes.c_double * 8),
                ("mb", ctypes.c_uint32), ("mm", ctypes.c_uint64 * 8)]
lib.rn_call.argtypes = [ctypes.POINTER(Ctx), ctypes.c_uint32]
MEMSZ = 0x2000000
mem = ctypes.create_string_buffer(MEMSZ)
img = pefile.PE("pc/Speed.exe").get_memory_mapped_image()[:0x400000]
ctypes.memmove(ctypes.addressof(mem) + 0x400000, img, len(img))
def w32(a, v): ctypes.memmove(ctypes.addressof(mem) + a, v.to_bytes(4, "little"), 4)
SRC = 0x1000100
res = {}
for shift in (1, 2):
  for off in range(4):
    for n in range(1, 40):
        src = SRC + off
        pat = bytes((i * 7 + 1) & 0xff for i in range(64))
        ctypes.memmove(ctypes.addressof(mem) + src, pat, 64)
        esp = 0x1ff0000 - 0x100
        w32(esp, 0x1fffff0); w32(esp + 4, src + shift); w32(esp + 8, src); w32(esp + 12, n)
        c = Ctx(); c.r[4] = esp; c.mem = ctypes.addressof(mem); c.memsz = MEMSZ; c.fcw = 0x27f
        lib.rn_call(ctypes.byref(c), 0x672630)
        got = ctypes.string_at(ctypes.addressof(mem) + src + shift, n)
        ok = (not c.halt) and got == pat[:n]
        res[(shift, off, n)] = "ok" if ok else f"HALT@{c.halt_at:x}" if c.halt else "WRONG"
bad = {k: v for k, v in res.items() if v != "ok"}
print("cases", len(res), "bad", len(bad))
ns = sorted(set(k[2] for k in bad)); print("bad lengths:", ns)
print("all bad n range per (shift,off):", {(s,o): [n for (s2,o2,n) in bad if (s2,o2)==(s,o)] and (min(n for (s2,o2,n) in bad if (s2,o2)==(s,o)), max(n for (s2,o2,n) in bad if (s2,o2)==(s,o))) for s in (1,2) for o in range(4)})
print("targets:", sorted(set(bad.values())))
# forward (non-overlap / dst<src) control
