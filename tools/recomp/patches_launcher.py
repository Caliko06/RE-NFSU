"""Patches: fast boot for the launcher (?fast=1 -> RN_FAST, host/win32.c). Split from patches.py; imported last in patches.py."""
from patches import PATCHES, _rel

# PATCH: 0x4de395 (+ cave 0x797540 in CODE_AREA), fast boot (OWNER 2026-11-09: skip the intro movies and the splash). The boot screen
# sequence ctor 0x4de1e0 builds a list of fng nodes (SKU 0: DiscErrorPC, LS_EAlogo, LS_PSAMovie, LS_IntroFMV, LS_Splash_PC,
# MU_UG_NEwOrLoad_PC2; list tail = [this+8], node = link - 4), the current node is [this+0xc] and 0x4de4a0 advances it as each
# screen ends. The cave replaces "mov ecx,[ebx+0xc]; mov edx,[ecx+0xc]" (the node's name, then stored to [0x735790]): with
# [SCREEN_ADDR+0xc4] = 1 (RN_FAST) the current node first becomes the last one, the profile screen, so the movies and the
# splash never load. 0: the original two instructions. The profile screen is left to the game (its Accept loads a profile).
PATCHES.append(dict(addr=0x797540, old="00" * 25, new="833dc430010000" "7409" "8b4b08" "83e904" "894b0c" "8b4b0c" "8b510c" "c3",
                    entry=True, when=lambda: True))
PATCHES.append(dict(addr=0x4de395, old="8b4b0c8b510c", new="e8" + _rel(0x4de395, 0x797540) + "90", when=lambda: True))
