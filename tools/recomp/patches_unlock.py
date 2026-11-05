"""Patches: everything open (RN_UNLOCK). Split from patches.py (GOAL 2026-11-05); patches.py imports this file in a fixed order."""
import struct
from patches import PATCHES, _rel, _imm, _j32, _jcc32, ROAD_ADDR, EBASE_ADDR, ROAD_RB, CODE_AREA

# PATCH: 0x735ec1, OWNER 2026-10-20 (everything available): a debug byte in .bss that no retail code writes (REA/Ghidra
# xrefs: 61 reads, 0 writes). When it is set, the game itself reports every part, paint, vinyl, rim and performance
# upgrade unlocked and owned (0x507e10, 0x509d70, 0x50aa90, 0x5a1550, 0x5a3570), every Quick Race track won
# (0x5a16f0 -> 0x4b9f40) and money as 1000000000 (0x5a1520). Mode flags of a track (0x4ab470) still apply.
PATCHES.append(dict(addr=0x735ec1, old="00", new="01", when=lambda: True))

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
