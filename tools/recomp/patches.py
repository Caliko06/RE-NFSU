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


# PATCH: 0x40bf09.., widescreen 2D: the sprite quad code (0x40beef) turns a position of the 640x480 screen into clip
# space as x/320 - 1 and 1 - y/240 for each of its four corners. The 4:3 layout was stretched over the whole
# back buffer. The x of each corner now uses x*(S/320) - S, with S = (4/3)/(W/H) (at most 1), so the 2D layer keeps
# its 4:3 shape, centred. S/320 and S live at SCREEN_ADDR+8 and +12 (host/win32.c). Operands of fmul [0x6cc914]
# and fsub [0x6cc7bc].
_OLD_MUL, _OLD_SUB = "14c96c00", "bcc76c00"
for _a in (0x40bf09, 0x40bf9a, 0x40bfff, 0x40c053):
    PATCHES.append(dict(addr=_a, old=_OLD_MUL, new="08300100", when=lambda: True))
for _a in (0x40bf17, 0x40bfa0, 0x40c00b, 0x40c064):
    PATCHES.append(dict(addr=_a, old=_OLD_SUB, new="0c300100", when=lambda: True))

# PATCH: 0x408a24, widescreen: the first CreateDevice (0x408830) asked for 800x600 with push 0x320 / mov esi,0x258 and
# [0x702a80] = 0x15 (D3DFMT_A8R8G8B8). It now asks for the screen size at SCREEN_ADDR, so the front end is drawn at the
# size the race is. Same bytes count: push [0x13000]; mov esi,[0x13004]; push 0x15; pop [0x702a80]; the call stays.
PATCHES.append(dict(addr=0x408a24, old="6820030000be58020000c705802a700015000000",
                    new="ff35003001008b35043001006a158f05802a7000", when=lambda: True))

# PATCH: 0x4494c4, widescreen: back to the front end after a race, 0x449497 puts the device back to 800x600 (push 0x320 /
# mov esi,0x258; call 0x4086b0) unless the resolution option [0x700e70] is 1 (800x600 already). It now asks for the screen
# size, as 0x408a24 does at the start. Same 18 bytes: mov esi,[0x13004]; push [0x13000]; call 0x4086b0; pop ecx
# (for add esp,4: ecx is free here, the jmp 0x40a4e0 that follows takes no register).
PATCHES.append(dict(addr=0x4494c4, old="6820030000be58020000e8ddf1fbff83c404",
                    new="8b3504300100ff3500300100e8dbf1fbff59", when=lambda: True))

# PATCH: 0x735ec1, OWNER 2026-10-20 (everything available): a debug byte in .bss that no retail code writes (REA/Ghidra
# xrefs: 61 reads, 0 writes). When it is set, the game itself reports every part, paint, vinyl, rim and performance
# upgrade unlocked and owned (0x507e10, 0x509d70, 0x50aa90, 0x5a1550, 0x5a3570), every Quick Race track won
# (0x5a16f0 -> 0x4b9f40) and money as 1000000000 (0x5a1520). Mode flags of a track (0x4ab470) still apply.
PATCHES.append(dict(addr=0x735ec1, old="00", new="01", when=lambda: True))

# PATCH: 0x702a38, OWNER 2026-10-21 (blur visible, as in ~/NFSU1-RE): the PC motion blur 0x40cd40 weights its half-size
# copy by t = (|camera +0x1e0| - [0x702a38]) / ([0x702a3c] - [0x702a38]) + 1.1 * nitrous, at most 0.65 ([0x702a40]).
# PC ramp 25 -> 125 m/s: no blur under 90 km/h, full at 450 km/h. Now the PS2 ramp 0.1 -> 25 m/s (SLUS_208.11 0x4ff95c,
# 0x4ff960; ~/NFSU1-RE docs/re/postfx-elf.md). The PC algorithm and its 0.65 cap stay. Only 0x40ce70/0x40ce7a read them.
PATCHES.append(dict(addr=0x702a38, old="0000c8410000fa42", new="cdcccc3d0000c841", when=lambda: True))
# PATCH: 0x702a40, OWNER 2026-10-21 (the blur was too strong): the composite weight is min(1.5 * t, 1), so the PC cap 0.65
# put 97% of the blurred copy on screen from ~56 mph. The cap is now 0.26: weight 0.39, the strongest PS2 copy
# (alpha 50/128, SLUS_208.11 0x4485f0). The streak length scales with t too. Only 0x40ced6/0x40cee2 read it.
PATCHES.append(dict(addr=0x702a40, old="6666263f", new="b81e853e", when=lambda: True))

# PATCH: 0x40d615, 0x40d2a2, game bug (EA's 2011 patch notes call it the "NOS black screen effect"): the 4-tap blur passes
# 0x40d370 and 0x40d090 turn blending off with effect->SetInt(BaseAlphaBlendEnable, 0) when an effect is current, but
# filter.efx pass p3 never reads that parameter. The pass then inherits the light-streak decay state (blend on, ZERO /
# BLENDFACTOR 0x8296b4, restored by the D3DX End state block), so the blur copy never receives the scene and fades to
# black; the frame is then mostly that copy. The jne goes: both always take the SetRenderState(ALPHABLENDENABLE, 0)
# branch that is already there for "no effect".
PATCHES.append(dict(addr=0x40d615, old="7512", new="9090", when=lambda: True))
PATCHES.append(dict(addr=0x40d2a2, old="7512", new="9090", when=lambda: True))

# PATCH: 0x702a84, OWNER 2026-10-21 (sharper cars): the car reflection cube (0x40b340, ENVMAP) is 128 px a side; every
# reader (0x40aa20 view table, 0x40b340 cube and its depth surface) takes the size from here. Now 512.
PATCHES.append(dict(addr=0x702a84, old="80000000", new="00020000", when=lambda: True))

# PATCH: 0x40debb, 0x40deec, 0x40dcdb (+ caves 0x408799, 0x5f4a04, constant 0x707fc0), OWNER 2026-10-22: the camera look of
# ~/NFSU1-RE. RE (Speed.exe): 0x40dd00 builds a view's projection from the camera FOV u16 F (0x484b53: 0x32dc = 71.5 deg).
# P[0] (view+0x40) = 1/tan(F/2): the horizontal view is fixed. P[5] (view+0x54) = -1/tan(A*F/2), A = viewport H/W (+0x18 / +0x14,
# view+0x58 struct) times 1.21 for view types 1, 2, 4, 5: the angle (not the tangent) follows the aspect, so 16:9 gives a 48 deg
# vertical view and pixels 12% too tall. 0x40dcb0 returns the focal length into view+0xc. The PS2 (SLUS_208.11 0x10a7f8) keeps the
# VERTICAL view (zoom 256/tan(F/2) over 512 x 448 = 64.4 deg) and widens x with the window. Now (types other than 8, 9), with
# k = 512/448 ([0x707fc0], free .data) and H' = max(H, 9W/16): P[0] = k/tan(F/2) * H'/W, P[5] = -P[0] * W/H. Up to 16:9 this is the
# PS2 look; wider windows stop at the 16:9 horizontal view (96 deg) and crop top and bottom, since the edge stretch of a flat
# projection past that made traffic look squashed wide. Focal (view+0xc) = (H'/2) k / tan(F/2), the same scale. Cave 0x408799 =
# A (P[0]) + fallback + focal; cave 0x5f4a04 (CC padding) = B (P[5]) + fallback. W is [0x701034], H is [0x701038].
PATCHES.append(dict(addr=0x707fc0, old="00000000", new="2549923f", when=lambda: True))
PATCHES.append(dict(addr=0x408799, old="909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090",
                    new="8b4c241c83790408743483790409742e8b4958d83dbcc76c00d80dc07f70008b41148d04c0c1e8043b41187f038b411850db042458da7114dec9d91feb08d83dbcc76c00d91fe9df560000a1341070008d04c0c1e8058b0d38107000d1f939c87f0289c8890424da3c24d80dc07f700059c3", when=lambda: True))
PATCHES.append(dict(addr=0x5f4a04, old="cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc",
                    new="8b44241c83780408741c8378040974168b4058ddd8d907db4014dec9da7018d9e0d95e54eb0bd83dbcc76c00d9e0d95e54e9bd94e1ff", when=lambda: True))
PATCHES.append(dict(addr=0x40debb, old="d83dbcc76c00d91f",
                    new="e9d9a8ffff909090", when=lambda: True))
PATCHES.append(dict(addr=0x40deec, old="d83dbcc76c00d9e0d95e54",
                    new="e9136b1e00909090909090", when=lambda: True))
PATCHES.append(dict(addr=0x40dcdb, old="a134107000d1f889442400da7c240059c3",
                    new="e904abffff909090909090909090909090", when=lambda: True))


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
