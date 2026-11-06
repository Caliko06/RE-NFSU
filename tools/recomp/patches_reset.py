"""Patches: the player's reset placement (GOAL 2026-11-05 Block 2). Split out of the collision file; imported last by patches.py."""
import struct
from patches import PATCHES

# PATCH: 0x4317ac + 0x431724, Player::ResetToRoute 0x4314a0, branch with no route path (Free Run / WORLD): it scans every route node (0x14 B rows, xy only),
# tests "has ground" with 0x440a40 at z = 100000 (0x431724: 0x47c34f8d), then calls 0x427c50 with z = 0 (0x4317ac); 0x4273d0 puts the car at the
# mean of 4 wheel queries 0x440a40 at that z. 0x440a40 takes the highest surface below z+1.0 (pass 1); if none, the HIGHEST surface of the column (pass 2).
# At z = 0 pass 1 finds nothing anywhere the world is above 1 m (WORLD z ~ 60), so the car always lands on the TOP layer of the column (deck, tunnel roof,
# fence top), never on the layer it was on, and the walls of its own layer are then not in its z range. Both z now start from the car's own z
# (mov eax,[edi+0x68]; mov [esp+..],eax; nop): pass 1 picks the layer under the car; with none under it pass 2 gives the old answer, so a
# one-layer column is unchanged. Node choice stays nearest in 2D (needs a cave to compare the layer; not done).
PATCHES.append(dict(addr=0x431724, old="c744244c8d4fc347", new="8b4768" "8944244c" "90", when=lambda: True))
PATCHES.append(dict(addr=0x4317ac, old="c744244000000000", new="8b4768" "89442440" "90", when=lambda: True))

# PATCH: 0x474be7 (+ cave 0x797400), WORLD frame cost (Block 3, nfsu-w3). Car::Update 0x474a90 (rivals and traffic; the player has 0x4774a0) runs
# n = int(dt / [0x6fff10] = 0.0084) + 1 physics substeps (0x46aa40 + 0x40bd40) per car per sim step: 2 at dt = 1/60 (Ghidra decomp + objdump 0x474bd0).
# 40 traffic cars + rivals = about 90-170 substeps a frame (spike: lines, site 0x474c24 = top site of every WORLD spike, 1,502 of 1,680 in a 600 s ghost).
# Traffic (driver kind [[car+0x14]+4] == 3) now divides by 0.02: n = 1 at dt <= 0.02. Rivals (kind 2) keep 0.0084. Cave: mov ecx,[edi+0x34]; mov ecx,[ecx+0x14];
# cmp [ecx+4],3; je L; fdiv [0x6fff10]; ret; L: fdiv [0x797420] (float 0.02 stored after the code); edi = this of 0x474a90, ecx is free there.
_CAVE = "8b4f348b4914837904037407d83510ff6f00c3d83520747900c3" + "00" * 6 + "0ad7a33c"
PATCHES.append(dict(addr=0x797400, old="00" * (len(_CAVE) // 2), new=_CAVE, entry=True, when=lambda: True))
PATCHES.append(dict(addr=0x474be7, old="d83510ff6f00", new="e8" + struct.pack('<i', 0x797400 - (0x474be7 + 5)).hex() + "90", when=lambda: True))
