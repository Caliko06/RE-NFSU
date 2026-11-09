"""Patches: perf."""
import struct
from patches import PATCHES

# PATCH: 0x474be7 (+ cave 0x797400), WORLD frame cost. Car::Update 0x474a90 (rivals and traffic; the player has 0x4774a0) runs
# n = int(dt / [0x6fff10] = 0.0084) + 1 physics substeps (0x46aa40 + 0x40bd40) per car per sim step: 2 at dt = 1/60 (Ghidra decomp + objdump 0x474bd0).
# 40 traffic cars + rivals are 90-170 substeps a frame; site 0x474c24 is the top site in 1,502 of 1,680 spike: lines of a 600 s WORLD ghost.
# The cave divides by 0.02 (n = 1 at dt <= 0.02) only when the car is traffic (driver kind [[car+0x14]+4] == 3), the track is the WORLD ([0x78a2f0] == 1010)
# and the car is > 100 m from the player (player car [[0x7361bc]+4], xy at +0x60/+0x64, d2 > 10000.0 at 0x797460; 0.02 at 0x797464). Everything else
# (original tracks, rivals, near traffic) keeps 0.0084, so contacts with the player and the original feel are unchanged. Needs eax, ecx free at 0x474be7.
_CAVE = "8b4f348b4914837904037549813df0a27800f2030000753da1bc61730085c074348b400485c0742d8b4f34d94160d86060d9c0dec9d94164d86064d9c0dec9dec1d81d60747900dfe0f6c4417507d83564747900c3d83510ff6f00c3cccccccc00401c460ad7a33c"
PATCHES.append(dict(addr=0x797400, old="00" * (len(_CAVE) // 2), new=_CAVE, entry=True, when=lambda: True))
PATCHES.append(dict(addr=0x474be7, old="d83510ff6f00", new="e8" + struct.pack('<i', 0x797400 - (0x474be7 + 5)).hex() + "90", when=lambda: True))
