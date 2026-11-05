"""Patches: engine audio. Split from patches.py (GOAL 2026-11-05); patches.py imports this file in a fixed order."""
import struct
from patches import PATCHES, _rel, _imm, _j32, _jcc32, ROAD_ADDR, EBASE_ADDR, ROAD_RB, CODE_AREA

# PATCH: 0x52536a (+ cave 0x5256e8, 8 CC bytes of padding after the ret of the EAXTunerCar helpers, no reference), OWNER 2026-11-04
# (lane 3, horns): the honk branch of EAXTrafficCar::Update 0x5251e0 calls StartHorn 0x524f30 here, the only such call in the image
# (edi = the sound object car+0x878, [esp+4] = sample index, callee ret 4). The sound path tests no parked byte, no draw flag and no
# world visibility, so cars the world does not draw still honk. The call now goes to the cave, jmp [SCREEN_ADDR+0xa4] =
# host/horn.c horn_start: HORNL line per honk (RN_HORNLOG=1) and, with RN_HORNFIX=1, no StartHorn for a parked, undrawn or
# just-recycled (<3 s) car. Both flags off: the original call with the same argument.
PATCHES.append(dict(addr=0x52536a, old="e8c1fbffff", new="e8" + _rel(0x52536a, 0x5256e8), when=lambda: True))
PATCHES.append(dict(addr=0x5256e8, old="cc" * 6, new="ff25a4300100", entry=True, when=lambda: True))
