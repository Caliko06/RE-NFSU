"""PATCH table (AGENTS.md contract 3): every change to Speed.exe code or data, in one place.

The lifter, the difftest and the loader (build/gen/table.c -> host/main.c) all see the patched image.
Each entry checks the original bytes first; a mismatch stops the build.
"""
import os

PATCHES = [
    # PATCH: 0x4f5891, temporary: game/ has no MOVIES\ (disc 2), so the boot screen LS_EAlogo waits forever for
    # "movie done". The movie message handler (0x4f5860, msg type 7) posts that message (0xc3960eb9, the way the
    # player does at 0x5a4c31: push msg, edx = 0x746104, call 0x4f3dc0) instead of checking the file and starting
    # it. Active only while game/MOVIES is missing: adding the folder removes the patch at the next build.
    dict(addr=0x4f5891,
         old="e80a6c140083c40484c07410568d4c24106a0151e8a6f10a0083c40c",
         new="83c404" "68b90e96c3" "ba04617400" "e81de5ffff" + "90" * 10,
         when=lambda: not os.path.isdir("game/MOVIES")),
]


def active():
    return [p for p in PATCHES if p["when"]()]


def apply(img, base):
    """Patch a bytearray image mapped at base."""
    for p in active():
        o, old, new = p["addr"] - base, bytes.fromhex(p["old"]), bytes.fromhex(p["new"])
        if len(old) != len(new) or bytes(img[o:o + len(old)]) != old:
            raise SystemExit(f"PATCH {p['addr']:#x}: original bytes do not match")
        img[o:o + len(new)] = new


def c_table():
    """C arrays the loader applies to guest memory after it maps the sections."""
    ps = active()   # a trailing 0 keeps the arrays non-empty
    return (f"const uint32_t rn_patch_count = {len(ps)};\n"
            "const uint32_t rn_patch_addr[] = {" + "".join(f"0x{p['addr']:x}," for p in ps) + "0};\n"
            "const char *const rn_patch_hex[] = {" + "".join(f'"{p["new"]}",' for p in ps) + "0};\n")
