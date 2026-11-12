"""PATCH table (AGENTS.md contract 3): every change to Speed.exe code or data, in one place.

The lifter, the difftest and the loader (build/gen/table.c -> host/main.c) all see the patched image.
Each entry checks the original bytes first; a mismatch stops the build.
"""
import struct

PATCHES = [
    # PATCH: 0x4f5891 (+ caves 0x43a001, 0x438eb1, 0x438b41: CC padding, no reference), a missing movie file: the movie
    # message handler (0x4f5860, msg type 7) builds MOVIES\<name>.mad (0x4f57a0), checks it (0x63c4a0) and starts the
    # player only if it exists. On a miss it posts nothing, so the screen waits forever for "movie done". The boot screen
    # 0x4deaa0 always asks for "na_boot" (SKU [0x734998] is .bss with no writer, so 0), and game/Movies (23 files) has no
    # na_boot.mad. The check now goes through the caves: on a miss they post "movie done" (0xc3960eb9, the way the player
    # does at 0x5a4c31: push msg, edx = 0x746104, call 0x4f3dc0, ret 4) and return 0. Movies that exist play as before.
    dict(addr=0x4f5891, old="e80a6c1400", new="e86b47f4ff", when=lambda: True),
    dict(addr=0x43a001, old="cc" * 15, new="ff742404e89624200059e9a1eeffff", when=lambda: True, entry=True),
    dict(addr=0x438eb1, old="cc" * 15, new="84c07401c368b90e96c3e981fcffff", when=lambda: True),
    dict(addr=0x438b41, old="cc" * 13, new="ba04617400e875b20b0030c0c3", when=lambda: True),
    # PATCH: 0x4deae1, boot EA logo: region [0x734998] has only readers, so the screen asks "na_boot", absent from game/Movies; ask the shipped "logo_eng" (0x6b8840).
    dict(addr=0x4deae1, old="b8103b6c00", new="b840886b00", when=lambda: True),
    # PATCH: 0x4dec18, boot THX logo: the region 0 list has LS_PSAMovie, whose "PSA" is absent; this screen now plays the shipped "thx_logo" (0x6c1d64), else never asked.
    dict(addr=0x4dec18, old="68fc3a6c00", new="68641d6c00", when=lambda: True),
    # PATCH: 0x40877e, widescreen: 0x408760 applies the resolution option [0x700e70] through a table of five fixed
    # 4:3 sizes (640x480 ... 1280x1024). Every size now comes from the screen size the layer keeps at
    # SCREEN_ADDR 0x13000 (width, height; host.h): the page passes its window size as RN_SCREEN. The guards at
    # 0x408760-0x40877d stay. The jump table at 0x408814 is now unused.
    #   push esi; mov eax,[0x13000]; mov esi,[0x13004]; push eax; call 0x4086b0; add esp,4; pop esi; jmp 0x40a4e0
    dict(addr=0x40877e,
         old="83f90456b820030000be580200007775ff248d14884000b880020000bee001000050e80bffffff83c4045ee9321d0000b820030000be5802000050e8f2feffff83c4045ee9191d0000b800040000be0003000050e8d9feffff83c4045ee9001d0000b800050000bec003000050e8c0feffff83c4045ee9e71c0000be00040000b80005000050e8a7feffff83c4045ee9ce1c0000",
         new="56a1003001008b350430010050e820ffffff83c4045ee9471d000090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090",
         when=lambda: True),
]

def _rel(src, dst): return struct.pack('<i', dst - (src + 5)).hex()
def _imm(v): return struct.pack('<I', v).hex()
def _j32(src, dst, op="e9"): return op + struct.pack('<i', dst - (src + 5)).hex()
def _jcc32(src, dst): return "0f8d" + struct.pack('<i', dst - (src + 6)).hex()
# Guest addresses shared by the topic files (patches_road.py explains them).
ROAD_ADDR, EBASE_ADDR = 0x796000, 0x796410
ROAD_RB, CODE_AREA = 0x796810, (0x797000, 0x797800)

# The topic files append to PATCHES in this order (an entry that patches on top of another stays after it).
import patches_render, patches_unlock, patches_test, patches_input, patches_boot, patches_race, patches_road, patches_collision, patches_lights, patches_audio, patches_feel, patches_reset, patches_perf, patches_launcher, patches_mc, patches_world   # noqa: E402,F401

def active():
    return [p for p in PATCHES if p["when"]()]

def apply(img, base):
    """Patch a bytearray image mapped at base."""
    for p in active():
        o, old, new = p["addr"] - base, bytes.fromhex(p["old"]), bytes.fromhex(p["new"])
        if o >= len(img):   # .bss past the raw data: zero by the PE format; the loader writes it in guest memory
            if old.strip(b"\0"): raise SystemExit(f"PATCH {p['addr']:#x}: .bss starts as zero")
            continue
        if len(old) != len(new) or bytes(img[o:o + len(old)]) != old:
            raise SystemExit(f"PATCH {p['addr']:#x}: original bytes do not match")
        img[o:o + len(new)] = new


def c_table():
    """C arrays the loader applies to guest memory after it maps the sections."""
    ps = active()   # a trailing 0 keeps the arrays non-empty
    return (f"const uint32_t rn_patch_count = {len(ps)};\n"
            "const uint32_t rn_patch_addr[] = {" + "".join(f"0x{p['addr']:x}," for p in ps) + "0};\n"
            "const char *const rn_patch_hex[] = {" + "".join(f'"{p["new"]}",' for p in ps) + "0};\n")
