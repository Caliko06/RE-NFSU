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

# PATCH: 0x4f2f13 (+ caves 0x689391, 0x688b61: CC padding after a jmp, no call, jump or pointer reaches them), widescreen race
# screens: the FEng render 0x4f2eb0 walks its draw lists (0x746910..) and draws each object with 0x4f2cb0 (eax = FEObject,
# edi = the render; type 1 image 0x4f2000, 2 string 0x4f25f0, 9 multi-image 0x4f2280, cached nodes 0x514b90), whose quads
# reach DrawPrimitiveUP (0x40bef0) before it returns. That call now goes through cave A, which leaves the object in
# SCREEN_ADDR+0x40 while it draws and clears it after (cave B), so host/d3d9.c moves each race screen package as a whole, not single quads.
#   A: mov [0x13040],eax; call 0x4f2cb0; jmp B        B: and dword [0x13040],0; ret
def _rel(src, dst): return struct.pack('<i', dst - (src + 5)).hex()
PATCHES.append(dict(addr=0x4f2f13, old="e898fdffff", new="e8" + _rel(0x4f2f13, 0x689391), when=lambda: True))
PATCHES.append(dict(addr=0x689391, old="cc" * 15, entry=True, when=lambda: True,
                    new="a340300100" + "e8" + _rel(0x689396, 0x4f2cb0) + "e9" + _rel(0x68939b, 0x688b61)))
PATCHES.append(dict(addr=0x688b61, old="cc" * 8, new="832540300100" + "00" + "c3", when=lambda: True))

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
# The 16:9 cap is for races only ([0x77a920] == 6): the front end keeps H' = H, so its 3D (the car on a magazine cover,
# full-screen viewport) keeps the scale of the 2D layout, which stays 4:3 and centred (PATCH 0x40bf09); with the cap the
# cover car was 1440/1116 = 1.29x too big at 2560x1116 and ran past the cover (runs/magn_wide, 2026-10-26). The focal
# keeps the cap (no room). The fallback (types 8, 9) puts back eax = ebp, the angle 0x40dec3 passes to sin 0x564b10.
PATCHES.append(dict(addr=0x707fc0, old="00000000", new="2549923f", when=lambda: True))
PATCHES.append(dict(addr=0x408799, old="909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090",
                    new="d83dbcc76c008b4c241c8a410424fe3c08742e8b4958d80dc07f7000803d20a97700068b4118750f6b411409c1e8043b41187f038b411850db042458da7114dec9d91f89e8e9e056000090a1341070008d04c0c1e8058b0d38107000d1f939c87f0289c8890424da3c24d80dc07f700059c3", when=lambda: True))
PATCHES.append(dict(addr=0x5f4a04, old="cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc",
                    new="8b44241c83780408741c8378040974168b4058ddd8d907db4014dec9da7018d9e0d95e54eb0bd83dbcc76c00d9e0d95e54e9bd94e1ff", when=lambda: True))
PATCHES.append(dict(addr=0x40debb, old="d83dbcc76c00d91f",
                    new="e9d9a8ffff909090", when=lambda: True))
PATCHES.append(dict(addr=0x40deec, old="d83dbcc76c00d9e0d95e54",
                    new="e9136b1e00909090909090", when=lambda: True))
PATCHES.append(dict(addr=0x40dcdb, old="a134107000d1f889442400da7c240059c3",
                    new="e904abffff909090909090909090909090", when=lambda: True))

# PATCH: 0x56e0d2, OWNER 2026-10-22 (remastered cars: rivals and traffic looked odd): the car draw 0x56dc30 picks the model
# LOD from its screen size, ftol(focal view+0xc * 3 / (dist - 3)) (0x545180), stepping up while size < [0x6b5dec + 4*lod] =
# 120, 45, 20, 0 px. With the focal of 0x40dcdb (~857 at 1080 lines) a rival is the full model only within ~24 m and model B
# out to ~60 m. The jp that enters the step loop is now a jmp: every car keeps the minimum LOD its caller asks for (0 = full;
# the reflection views pass 1, 0x6f1b38). The table stays: 0x56e77e fades by (size - 20) / (45 - 20).
PATCHES.append(dict(addr=0x56e0d2, old="7a1f", new="eb1f", when=lambda: True))

# PATCH: 0x409bdb (+ weight 0x707fcc), OWNER 2026-10-22 (light flares blind the view) and 2026-10-26 (now the trails are
# gone; wants the aura around moving lights back): with LIGHTSTREAKS (0x700e9c) the flares 0x544f30 go only into a half-size
# buffer 0x71abb0 (0x409b70). Each frame that buffer is multiplied by BLENDFACTOR k = 0x008296b4 (ZERO / BLENDFACTOR quad,
# filter.efx p0, mode 0xe) and then added to the screen (ONE / ONE, mode 2) modulated by the colour at [esp+8], 0x1fffffff
# (both 0x40d6e0 calls point at that slot; the decay quad ignores it, source factor ZERO). A still light builds to
# w/(1 - k): R 2.0x, G 2.4x, B 3.4x (the blinding, blue-white lamps); a moving one leaves a trail of 4.4 / 5.6 / 8.6 frames
# at 60 fps (73 / 93 / 143 ms). That decay stays as shipped: it is the PS2 trail in time (SLUS_208.11 glow buffer loses
# (90,79,53) per 30 fps frame: 94 / 107 / 160 ms; ~/NFSU1-RE docs/re/postfx-elf.md). The 2026-10-22 patch (k / 4, w 0.55)
# cut the trail to 1.7 frames and a still lamp to 0.65x, so the aura vanished. Now the colour comes from [0x707fcc] (free
# .data, no reference in the exe), set per channel to s (1 - k): a still light is s times its own flare in R, G and B alike,
# and the trail keeps the game's length. Default s = 1.5 (0x1fbc9e71); web/tune.js sets s per blur preset (F6/F7).
# The block 0x409bdb..0x409bfe is rewritten in place: same args to 0x40d6e0, same ecx / edx / eax as before the call.
PATCHES.append(dict(addr=0x707fcc, old="00000000", new="719ebc1f", when=lambda: True))
PATCHES.append(dict(addr=0x409bdb, old="8b46186a0e6a016a018d4c2414518d54241c52894424206a0133c0c7442420ffffff1f",
                    new="8b46188d4c2408894104a1cc7f700089018d51046a0e6a016a0151526a0131c0909090", when=lambda: True))

# PATCH: 0x40fbb7..0x40fc38, OWNER 2026-10-22 (less car reflection): 0x40fae0 sets the car material constants of car.efx.
# EnvmapMin = mat+0x84 * mat+0x80 * 0.5 and EnvmapMin + EnvmapRange = mat+0x94 * mat+0x90 * 0.5, both with the shared 0.5
# at [0x6cc7dc]; the shader adds 4 * diffuse.w * cube * (EnvmapMin + f * EnvmapRange). These six fmul now read 0.35 at
# [0x707fc4] (free .data, next to 0x707fc0): the cube reflection is 70% of the original. Specular and diffuse keep 0.5.
PATCHES.append(dict(addr=0x707fc4, old="00000000", new="3333b33e", when=lambda: True))
for a in (0x40fbb7, 0x40fbcd, 0x40fbe3, 0x40fbf9, 0x40fc1e, 0x40fc38):
    PATCHES.append(dict(addr=a, old="d80ddcc76c00", new="d80dc47f7000", when=lambda: True))

# PATCH: 0x4470f0 (+ cave 0x408814), TEST-ONLY seed for the A/B against the original (off unless RN_SEED is set): 0x4470d0,
# called once from the boot 0x4471b0, seeds the game RNG [0x6f227c] from (QPC >> [0x7349c8]) + 0x12345678. The step is
# inlined at ~60 sites (e.g. 0x41f81d). Cave (the jump table 0x408814 that PATCH 0x40877e left unused, no other reference):
# mov edi,[0x13010]; test edi,edi; jnz 0x447110 (edi = K, then + 0x12345678 as before); else the original lea/push and
# back to the QPC call. The layer writes RN_SEED to SCREEN_ADDR+0x10 (0 = the original clock seed). The Wine exe gets
# `mov edi,K; jmp 0x447110` at 0x4470f0 instead (tools/wine/mkexe.py --set parity).
PATCHES.append(dict(addr=0x408814, old="95874000ae874000c7874000e0874000f987400090909090",
                    new="8b3d1030010085ff0f85eee803008d44240450e9c9e80300", when=lambda: True))
PATCHES.append(dict(addr=0x4470f0, old="8d44240450", new="e91f17fcff", when=lambda: True))

# PATCH: 0x42d4b0, TEST-ONLY autopilot for the A/B and the lap runs (off unless RN_AUTOPILOT is set): Player::UpdateInputMode
# 0x42d470 picks the racing input mode as (Player+0x4ae != 0) ? 4 (PLAYER_MODE_AUTO_PILOT, name table 0x700b00) : 2
# (CAR_RACING); SetInputMode 0x42d520 then runs AutoPilotOn 0x42e230 (the car drives itself with the game's AI) and camera
# 0x12. Only joy event 0xa3 (0x431960) toggles +0x4ae and no code registers 0xa3 (FUN_00574020), so the byte is always 0
# in play. It now reads SCREEN_ADDR+0x14 (the layer writes RN_AUTOPILOT there). Wine: mkexe.py --autopilot (mov dl,1).
PATCHES.append(dict(addr=0x42d4b0, old="8a90ae040000", new="8a1514300100", when=lambda: True))
# PATCH: 0x42d4a9 (+ cave 0x6436e3, CC padding before 0x6436f0), TEST-ONLY autopilot in Drag: in 0x42d470 race state 3
# (case 0x42d49f) takes Player+0x4af != 0 (a drag race) as mode 3 PLAYER_MODE_DRAG_RACING (names 0x700af0: 0 NONE,
# 1 PAUSEMENU, 2 CAR_RACING, 3 DRAG_RACING, 4 AUTO_PILOT) before the autopilot read at 0x42d4b0, so the drag car never
# drove itself (runs 2026-10-24: drag 6/4, no finish). `mov ecx,3; jmp 0x42d4c1` now goes through the cave:
# mov ecx,[0x13018]; jmp 0x42d4c1. The layer writes SCREEN_ADDR+0x18 = 4 with RN_AUTOPILOT, else 3 (the original).
PATCHES.append(dict(addr=0x42d4a9, old="b903000000eb11", new="e9356221009090", when=lambda: True))
# PATCH: 0x4609e3/0x460a80/0x460b4f/0x460c02, OWNER choice 2026-10-26 (?steer=pad, "the car responds late, I can't hold the angle"):
# the steering model 0x460a80 reads [0x736514], 0 = keyboard (0x4070a0 clears it on the steer actions 3/4), 1 = gamepad
# (0x40664a, with a joystick axis; the layer has no joystick, so it is always 0 here). With 0 the angle cap grows with the
# time the key is held (S+0x14, 0.55 s to full) and 0x460de0 (called by 0x460970 on the same byte, 0x4609e3) limits the rate; with 1
# the angle is the speed cap at once. The four reads take SCREEN_ADDR+0x20 instead: the layer writes 1 with RN_STEER=pad,
# else 0 (the keyboard model, as before).
PATCHES.append(dict(addr=0x4609e3, old="a014657300", new="a020300100", when=lambda: True))
PATCHES.append(dict(addr=0x460a80, old="a014657300", new="a020300100", when=lambda: True))
PATCHES.append(dict(addr=0x460b4f, old="8a1d14657300", new="8a1d20300100", when=lambda: True))
PATCHES.append(dict(addr=0x460c02, old="8a1d14657300", new="8a1d20300100", when=lambda: True))
PATCHES.append(dict(addr=0x6436e3, old="cc" * 11, new="8b0d18300100e9d39ddeff", when=lambda: True))


# PATCH: 0x585b94 (+ mask 0x707fc8), OWNER 2026-10-24 (faster loads): the frame limiter 0x585b40 (main loop 0x447600) spins on
# QPC until a frame lasts 1/60 s ([0x6f0890], never written). The loads are synchronous job loops paced one job per frame
# (UnloadingFrontEnd 0x448d10, the track load, 0x4493a0), so menu->race was ~400 limited frames (7.4 s). The limiter now
# skips its wait while the game-flow state [0x77a920] (writes 0x448b11 .. 0x449a15) is a load: 1, 2, 4, 5, 7, 8 (bit mask
# 0x1b6 at [0x707fc8], free .data), or 6 while the race state [[0x7361f0]] is still 1 (loading screen up to the race HUD).
# Front end (3), boot (0) and the race keep the 1:1 limit. Room: the second test (wait < 1/30 s) is dead since the target
# is 1/60 and the frame time is >= 0; the > 0 test is now an integer compare of the stored float (same result, no NaN here).
PATCHES.append(dict(addr=0x707fc8, old="00000000", new="b6010000", when=lambda: True))
PATCHES.append(dict(addr=0x585b94,
                    old="d9542404d81da4c76c00dfe0568bfa8b542428c1e70481c7d80a7300f6c44189170f8595000000d9442408d81deccd6c00dfe0f6c4050f8a80000000",
                    new="d95c2404" "56" "c1e204" "8dbad80a7300" "8b542428" "8917" "837c240800" "7e1c" "a120a97700"
                        "0fa305c87f7000" "720e" "3c06" "750f" "a1f0617300" "833801" "7505" "e980000000",
                    when=lambda: True))

# PATCH: 0x4b4321 (+ cave 0x6736b1, CC padding after the ret of 0x673690, no reference), OWNER 2026-10-27 (rivals with a
# soul): the race setup 0x4b4040 registers each opponent with 0x5809c0(id, 2, ride, record, skill, ?, index), esi = the
# ride slot (stdcall, ret 0x1c). That call now goes to the cave, jmp [SCREEN_ADDR+0x60] = host/rivals.c rival_ride, which
# rebuilds the ride from a procedural persona through the game's preset code (0x4b26f0, 0x57f700) and then makes the
# original call with the same arguments and esi. RN_RIVALS=0: the host makes only the original call.
PATCHES.append(dict(addr=0x4b4321, old="e89ac60c00", new="e8" + _rel(0x4b4321, 0x6736b1), when=lambda: True))
PATCHES.append(dict(addr=0x6736b1, old="cc" * 6, new="ff2560300100", entry=True, when=lambda: True))

# PATCH: 0x57119a (+ cave 0x43a7e4, CC padding after the jump table at 0x43a7d8, no reference), OWNER 2026-10-27 (rivals as
# well made as the player's car): the race list draw 0x571050 calls the car draw 0x56dc30 (stdcall, 12 arguments, ret 0x30,
# no register input). That call now goes to the cave, jmp [SCREEN_ADDR+0x64] = host/rivals.c car_draw, which forces LOD A
# for every car that is not traffic through the game's debug words 0x6f1b30 / 0x6f1b34 and makes the original call.
PATCHES.append(dict(addr=0x57119a, old="e891caffff", new="e8" + _rel(0x57119a, 0x43a7e4), when=lambda: True))
PATCHES.append(dict(addr=0x43a7e4, old="cc" * 6, new="ff2564300100", entry=True, when=lambda: True))

# PATCH: 0x4b528d (+ cave 0x6736b7, CC padding after the rivals cave, no reference), OWNER 2026-10-27 (free mode: real
# rivals on the track): Free Run's setup 0x4b5090 ends with AddTrafficCars 0x4b3ac0 (no arguments, no register input) and
# never builds opponents. That call now goes to the cave, jmp [SCREEN_ADDR+0x68] = host/free.c free_setup, which builds
# three career rivals with the game's opponent builder 0x4b4040(3, 0) and then makes the original call. RN_FREE=0: only the
# original call.
PATCHES.append(dict(addr=0x4b528d, old="e82ee8ffff", new="e8" + _rel(0x4b528d, 0x6736b7), when=lambda: True))
PATCHES.append(dict(addr=0x6736b7, old="cc" * 6, new="ff2568300100", entry=True, when=lambda: True))
# PATCH: 0x4b3c2f (+ cave 0x43a7ea, CC padding after the car_draw cave, before 0x43a7f0), same OWNER request (tuned traffic):
# AddTrafficCars 0x4b3ac0 registers each traffic ride with 0x5809c0(0x32 + i, 3, ride, "", -1, 0, 0), esi = the ride slot
# (stdcall). That call now goes to the cave, jmp [SCREEN_ADDR+0x6c] = host/free.c free_traffic, which dresses racer rows
# in a career rival's preset while free mode builds its traffic and then makes the original call.
PATCHES.append(dict(addr=0x4b3c2f, old="e88ccd0c00", new="e8" + _rel(0x4b3c2f, 0x43a7ea), when=lambda: True))
PATCHES.append(dict(addr=0x43a7ea, old="cc" * 6, new="ff256c300100", entry=True, when=lambda: True))
# PATCH: 0x422b36 (+ cave 0x673842, CC padding after a ret, no reference): race start 0x422a70 calls the traffic
# placer 0x598bf0 once per kind 3 entrant (ecx = [esi+0x2f0], push entrant); now host/free.c free_place, which runs its three
# steps (0x5991a0 route, 0x598c80 grid, 0x598fb0 last resort) in the original order and logs which one placed the car. In free
# mode it clears 100 m round the start instead of the game's 500 m ([[0x736174]+side*4+0xcc]) and repeats the last resort 4x
# (RN_FREE=0: as shipped). Why: docs/traffic_placement.md (on 1001/1010 13 of 18 fit; now 19 of 19).
PATCHES.append(dict(addr=0x422b36, old="e8b5601700", new="e8" + _rel(0x422b36, 0x673842), when=lambda: True))
PATCHES.append(dict(addr=0x673842, old="cc" * 6, new="ff257c300100", entry=True, when=lambda: True))
# PATCH: 0x598774 (+ cave 0x673848, the CC padding right after the one above): TrafficTeleporter 0x598600 asks 0x59b3e0 for the
# spacing of each Free Run move; now host/free.c free_spacing, which calls it and in free mode turns its 99999 m (no
# TRAFFIC_DENSITY zone under the player, or a stopped car near him) into the track's 31 m. Why: with 99999 every move fails
# and the car is parked (0x5832a0), so all traffic stood still after ~60 s on 1001 and the WORLD.
PATCHES.append(dict(addr=0x598774, old="e8672c0000", new="e8" + _rel(0x598774, 0x673848), when=lambda: True))
PATCHES.append(dict(addr=0x673848, old="cc" * 6, new="ff2580300100", entry=True, when=lambda: True))
# PATCH: 0x5833eb (+ cave 0x6729f6, CC padding after a ret, no reference): TrafficAI update 0x583350 reads the no-path byte
# [ebp+0x410] (mov al, 6 bytes) and, when set, only brakes the car for good: never re-pathed, never parked, so the
# TrafficTeleporter never recycles it. Now call host/free.c free_nopath (+ nop), which returns that byte, or 0 in free mode so
# the car retries 0x44cf30 and is parked (0x5832a0) on failure, as every other car. RN_FREE=0: the original byte.
PATCHES.append(dict(addr=0x5833eb, old="8a8510040000", new="e8" + _rel(0x5833eb, 0x6729f6) + "90", when=lambda: True))
PATCHES.append(dict(addr=0x6729f6, old="cc" * 6, new="ff2584300100", entry=True, when=lambda: True))
# PATCH: 0x59a5cf, 0x59a669 (+ cave 0x439a94, CC padding after a ret, no reference): the Free Run move 0x59a2c0 asks 0x4420b0
# whether traffic may spawn on a road node (bit 25/26 of [node+0x84]); 1001 sets it on 40 % of its route only, so with the
# player in the other stretches every move failed and all cars stood parked. Now host/free.c free_tnode: every node in free
# mode, the node's bit otherwise.
PATCHES.append(dict(addr=0x59a5cf, old="e8dc7aeaff", new="e8" + _rel(0x59a5cf, 0x439a94), when=lambda: True))
PATCHES.append(dict(addr=0x59a669, old="e8427aeaff", new="e8" + _rel(0x59a669, 0x439a94), when=lambda: True))
PATCHES.append(dict(addr=0x439a94, old="cc" * 6, new="ff2588300100", entry=True, when=lambda: True))
# PATCH: 0x5987f6 (+ cave 0x439a9a, the CC padding right after the one above): TrafficTeleporter 0x598600 asks 0x5988c0 whether a car
# needs a move; its rules are all along the race route, so in free roam a car that drove into another street was never moved and
# drove on 1..2.5 km away (17 of 19 cars on the WORLD). Now host/free.c free_recycle: the game's answer, or in free mode also yes
# when the car is farther than 500 m ([0x6b5a3c], the move's route limit) in a straight line from the player.
PATCHES.append(dict(addr=0x5987f6, old="e8c5000000", new="e8" + _rel(0x5987f6, 0x439a9a), when=lambda: True))
PATCHES.append(dict(addr=0x439a9a, old="cc" * 6, new="ff258c300100", entry=True, when=lambda: True))

# PATCH: 0x7007ec, 0x700850 (+ caves 0x6439f2, 0x6439f8: CC padding between two functions, no reference), 0x4ba207; OWNER 2026-10-28
# (the "WORLD" entry of the Free Run list, docs/openworld/world_entry.md). 0x7007ec / 0x700850 are entries of the chunk handler table
# (0x442040 track-info table chunk 0x34201, 0x59fce0 language chunk 0x39000; cdecl, one argument = the chunk). They now point at caves,
# jmp [SCREEN_ADDR+0x74] = host/openworld.c world_rows (original loader, then a 32nd track row: id 1010, mask 0x90, minimap bounds) and
# jmp [SCREEN_ADDR+0x78] = world_lang (original loader, then the name pair "TRACK_NAME_1010" -> "WORLD" in the sorted language table).
# The list builder 0x4ba100 adds each row twice (forward, then reverse: pass 2 tests `row[0x74] & 8` at 0x4ba207, test al,8): the test now
# reads 0x88, so the new row's mask bit 0x80 means "no reverse entry". The shipped rows never have 0x80. RN_WORLDROW=0: no row, no name.
PATCHES.append(dict(addr=0x6439f2, old="cc" * 6, new="ff2574300100", entry=True, when=lambda: True))
PATCHES.append(dict(addr=0x6439f8, old="cc" * 6, new="ff2578300100", entry=True, when=lambda: True))
PATCHES.append(dict(addr=0x7007ec, old="40204400", new=struct.pack("<I", 0x6439f2).hex(), when=lambda: True))
PATCHES.append(dict(addr=0x700850, old="e0fc5900", new=struct.pack("<I", 0x6439f8).hex(), when=lambda: True))
PATCHES.append(dict(addr=0x4ba207, old="a808", new="a888", when=lambda: True))

def active():
    return [p for p in PATCHES if p["when"]()]

# PATCH: unlock everything (AGENTS Scope), with a switch for the normal Underground (OWNER 2026-10-27). [0x7677ac] is the
# game's "career beaten" flag: 0x5a0dc0 sets it to 1 when the last event (0x71) is won, new profile 0x41cf40 clears it
# (Hopper beatgame.txt). Its 22 readers are lock queries that answer "open" when it is not 0 (0x4d7eb0: "if [0x7677ac]==0
# && [0x735ec1]==0 && ... return locked"), for tracks, cars and parts (0x506210..0x512dd8 next to the garage screen
# 0x505fb0); each one tests the register right after the read (test r,r / setne / jne), so flags from an OR are fine.
# Each read now calls a cave that returns [0x7677ac] | [0x13024] in the same register (call rel32, + nop for the 6-byte
# forms). The layer writes SCREEN_ADDR+0x24 = 1 (everything open, the default) or 0 with RN_UNLOCK=0: the game's own flag,
# as shipped. Caves: 0x63b370.. in the dead CRT routine past the traffic caves (0x63b366..0x63b3bf, no reference).
_UNLOCK_CAVE = {"a1": 0x63b370, "8b3d": 0x63b380, "8b0d": 0x63b390, "8b15": 0x63b3a0}   # eax, edi, ecx, edx
PATCHES.append(dict(addr=0x63b370, entries=tuple(_UNLOCK_CAVE.values()), when=lambda: True,
                    old="680c0100008d56045352e8313e0000566800f47000e8766a000083c4208b44241081c30c01000048894424100f85effeffff5f5e5d5b6854f47000c605",
                    new=("a1ac7776000b0524300100c3" + "cc" * 4 + "8b3dac7776000b3d24300100c3" + "cc" * 3
                         + "8b0dac7776000b0d24300100c3" + "cc" * 3 + "8b15ac7776000b1524300100c3")))
for a, old in [(0x4d7eb9, "8b3d"), (0x4d8077, "a1"), (0x4d8117, "a1"), (0x4d81c7, "8b0d"), (0x4d82b4, "8b0d"),
               (0x4d8334, "8b0d"), (0x4d83b3, "a1"), (0x5062d7, "8b15"), (0x5077f9, "8b15"), (0x507cff, "a1"),
               (0x507e54, "a1"), (0x50823f, "a1"), (0x509d88, "a1"), (0x50a708, "8b0d"), (0x50aac3, "a1"),
               (0x50ab04, "8b0d"), (0x50c1d7, "a1"), (0x50d1f3, "a1"), (0x50d6a4, "8b0d"), (0x50df69, "8b0d"),
               (0x512223, "a1"), (0x512dd8, "8b0d")]:
    new = "e8" + _rel(a, _UNLOCK_CAVE[old]) + ("" if old == "a1" else "90")
    PATCHES.append(dict(addr=a, old=old + "ac777600", new=new, when=lambda: True))


# PATCH: 0x410c1b (+ cave 0x63b3ad, the tail of the same dead CRT routine, 19 bytes past the unlock caves, no reference), OWNER 2026-10-27
# (?roadrefl=off, "wet everywhere"): 0x410b70 sets the hardware cap of the options, among them ROADREFLECTION [0x70105c]:
# ecx = (2 < [0x71ad84] ? -1 : 0) & -2, + 2 -> 2 (0 if [0x71ad84] > 2); 0x410a00 then clamps [0x700e90] to it (28292 of decomp.c) and
# 0x409580 draws the mirrored world into the 320x240 RT only while [0x700e90] > 1 (the RT is cleared black at level 1: a dry road).
# The 5 bytes `and ecx,-2; add ecx,eax` become a call to a cave doing the same with a word in SCREEN_ADDR+0x70 for the 2:
#   not ecx; and ecx,[0x13070]; ret      (ecx = 0 or -1 from the sbb; same result with the word = 2)
# host/win32.c writes the word: 1 with RN_ROADREFL=off (the game's level 1), else 2.
PATCHES.append(dict(addr=0x410c1b, old="83e1fe03c8", new="e8" + _rel(0x410c1b, 0x63b3ad), when=lambda: True))
PATCHES.append(dict(addr=0x63b3ad, old="68f4700001e8d9660000" + "81c40c010000c39090", entry=True, when=lambda: True,
                    new="f7d1230d70300100c3" + "cc" * 10))


# PATCH: 0x57d060, 0x57d0c1, (0x57cfc7 off), 0x4b3b01, 0x583a37, 0x583a5b (+ cave 0x63b270, a dead CRT routine: no call, jump or pointer
# reaches 0x63b270..0x63b3bf; source tools/recomp/caves/traffic.s), OWNER 2026-10-25 (traffic alive). AddTrafficCars
# 0x4b3ac0 spawns i8 [trackinfo + side + sel*2 + 0xc0] cars (GLOBALB 0x34201: 12 on most tracks), each of a type from
# 0x57d000: weights f32 [row + 0xc60 + district*4] of the rows the iterator 0x57cfa0 keeps (usage +0xc54 == 2, enable
# +0x40, skins +0xd9 > 0) in the table [0x734588] (GLOBALB 0x34600, 35 rows x 0xc90). District 0 (every Quick Race)
# weights only 6 of the 12 normal traffic types. Now: the 12 types weigh 1.0 in every district (BUS, AMBULANCE and
# FIRETRUCK stay 0), the iterator also lets the traffic pick take racer rows (usage 0) and 8 compact racers weigh 0.375
# (stock skin: d9 = 1, skin 1); +0xc60 has no other reader. The count is x1.5 (12 -> 18), at most 26 (rides cap 30 at
# 0x4322a0); the 100 re-picks at 0x4b3b30 keep every ride a distinct type (run: 6 -> 18 types on track 1001). The
# traffic driver 0x583910 (ctor 0x582f90, vtable 0x6b96b0; racers use 0x5a6ef0 from 0x462b30) asks 0x5a6b00 the lane speed
# (node +0x6a via 0x5a7690) twice a frame; each car now drives at x0.85..1.15 of it, from a hash of its AI object (esi), so
# a car keeps its pace (a spawn speed alone would not last). [0x1301c] (SCREEN_ADDR+28) = 0 (RN_TRAFFIC=0) = original.
PATCHES.append(dict(addr=0x63b270, entries=(0x63b280, 0x63b28a, 0x63b310, 0x63b331), old="8b44240881ec0801000085c00f8424010000538b9c24100100005556578944241053e8b91e000083c40484c00f85eb000000a1f4756e008d5424142bd08d49008a08880c024084c975f68bc38bf38bff8a084084c975f98d7c24142bc64f8bff8a4f014784c975f88bc8c1e9026a00f3a568800000006a036a006a008bc868000000808d44242c83e10350f3a4ff15c07169008bf883ffff745268fc8c6a006a07e84a7b000053e834fdffff8be883c40c85ed750f8b0d18766e0051e81f71000083c4048b3590f470006a005783c610ff15b871690001068356040057c6850401000001ff1528716900eb316a00681001000068f08c",
                    new="7b4002000000c03e9a99593fce339a3a5089c8e80200000058c3833d1c300100007508d984b0600c0000c3528b90540c000085d274248b90600c00000b90640c00000b90680c00000b906c0c00000b90700c00007420d9e85ac38b90500c000083fa1f77110fa31570b263007308d90574b263005ac3d9ee5ac38b88540c000039f17412833d1c30010000740e85c9750a83fe027505e9c61cf4ffe9dd1cf4ff0fbe9479c0000000833d1c30010000740f8d1452d1fa83fa1a7e05ba1a000000c3ff742404e8c6b7f6ff833d1c3001000074205089f069c0b179379ec1e81850db042458d80d7cb26300d80578b26300dec958c20400", when=lambda: True))
PATCHES.append(dict(addr=0x57d060, old="d984b0600c0000", new="e825e20b009090", when=lambda: True))
PATCHES.append(dict(addr=0x57d0c1, old="d984b1600c0000", new="e8bae10b009090", when=lambda: True))
# 0x57cfc7 (cave iter: the traffic pick also took racer rows, usage 0) is off since 2026-10-28: a racer model has no body
# texture of its own. Cars/TEXTURES.BIN holds baked <MODEL>_SKIN1..8 only for traffic models (4DR_SEDAN, PICKUP, TAXI...);
# a racer body is DUMMY_SKIN<n>, whose hash 0x4b4040 puts at ride +0x444 (+0x448 DUMMY_WHEEL<n>) for slots 1..4 only, and
# AddTrafficCars 0x4b3ac0 -> 0x57d160 sets +0x444 = 0. So a GOLF or CIVIC in traffic drew wheels, seat and driver with no
# body (the OWNER's "invisible cars", PLAN 6.2). The cave code stays, unused; racers in traffic need skin slots first.
PATCHES.append(dict(addr=0x57cfc7, old="8b88540c00003bce751c", new="e91ee30b009090909090", when=lambda: False))
PATCHES.append(dict(addr=0x4b3b01, old="0fbe9479c0000000", new="e80a781800909090", when=lambda: True))
PATCHES.append(dict(addr=0x583a37, old="e8c4300200", new="e8f5780b00", when=lambda: True))
PATCHES.append(dict(addr=0x583a5b, old="e8a0300200", new="e8d1780b00", when=lambda: True))

# PATCH: 0x598c4b, OWNER 2026-10-27 (few cars). The traffic placer 0x598bf0 tries 0x5991a0 (along the route, only when
# 0x421a50 = [0x78a344] or [0x7361a8]), then 0x598c80 (a grid slot), then 0x598fb0 (any free spot, 100 tries, 31 m apart via
# 0x59aa60) only when 0x421a50 is false. (Measured later: in Free Run it is false, so the last resort ran anyway; see 0x422b36 above) with 18 entrants (the x1.5 above) 0x598c80 fails 793 of 795
# tries at the start and 7 never get a car (11 cars; vanilla places 10 of 12). With [0x1301c] != 0 (RN_TRAFFIC, the switch above)
# the last resort runs too: ecx = (al == 0 ? -1 : 0) | [0x1301c], then the original test ecx / je 0x598c69. eax is dead there.
PATCHES.append(dict(addr=0x598c4b, old="0fb6c0f7d81bc0400fb6c8", new="3c011bc90b0d1c30010090", when=lambda: True))

# PATCH: 0x4aa21e (+ data 0x6d3440: .rdata slack past its virtual size 0x3c439, zero, no reference), OWNER 2026-10-28:
# the audio volumes of the OWNER's profile asas are the default. The profile/options ctor 0x4aa200 (callers 0x4a9bc0,
# 0x4cadc0, 0x4ccab0: every new profile) set the 9 volume floats at +0x38..+0x58 to 0.9. The .opt file (save 0x41e200,
# load 0x41e330) is dword 0x13, the 0x2e5-byte block of 0x4aaad0 (+0x39 = those floats, so file 0x3d) and its Adler-32
# (0x41dd10). The 9 floats now come from asas.opt file 0x3d..0x60 (0.2 0.7 0.5 0.7 0.8 0.9 0.9 0.9 0.9), same bits:
#   lea edi,[esi+0x38]; push esi; mov esi,0x6d3440; mov ecx,9; rep movsd; pop esi; nop x15
# ecx ends 0 as before (0x4aa20d); edi and eax are set again right after (0x4aa23e, 0x4aa25e).
PATCHES.append(dict(addr=0x4aa21e, old="b86666663f894638" + "89463c894640894644894648" + "89464c894650894654894658",
                    new="8d7e3856be40346d00b909000000f3a55e" + "90" * 15, when=lambda: True))
PATCHES.append(dict(addr=0x6d3440, old="00" * 36, when=lambda: True,
                    new="c8cc4c3e3233333ffdffff3e3233333fcccc4c3f6666663f6666663f6666663f6666663f"))

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
