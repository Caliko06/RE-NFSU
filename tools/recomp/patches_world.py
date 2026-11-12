"""Patches: the main menu's Online button becomes WORLD (OWNER 2026-11-11, plan row 8). Split from patches.py; imported last in patches.py."""
from patches import PATCHES, _rel

# PATCH: 0x4b342a (+ cave 0x7977c0 in CODE_AREA), MU_Main_PC accept of the Online button (Screen_MU_Main_PC::NotificationMessage 0x4b3240, object hash
# 0x70fbb1e4): "cmp [0x7346c4],edi; je ignore" and the 0x777b4c = 8 / MU_Online_NetworkLogin path are gone (the first 12 bytes of the case). Now
# call cave (jmp [SCREEN_ADDR+0xd0] = host/input.c world_arm, which only arms world_go), then jmp 0x4b34e9, the QuickRace case (sets [0x777b4c] = 2 and
# switches to MU_QuickRaceModeSelect); world_go then starts Free Run track 1010 once that screen is up, so the game's own ctor has done its one-time init.
# The label "WORLD" comes from host/openworld.c world_lang (string hash 0x36dbec3e). Why not 0x4b5c00 straight from here: docs/re/frontend_menu.md (block copy 0x4b6a32).
PATCHES.append(dict(addr=0x7977c0, old="00" * 6, new="ff25d0300100", entry=True, when=lambda: True))
PATCHES.append(dict(addr=0x4b342a, old="393dc44673000f8433030000",
                    new="e8" + _rel(0x4b342a, 0x7977c0) + "e9" + _rel(0x4b342f, 0x4b34e9)[0:] + "9090", when=lambda: True))
