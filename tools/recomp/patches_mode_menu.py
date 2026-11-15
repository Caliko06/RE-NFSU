"""Seventh MU_Main_PC button; OWNER 2026-11-14 permits this sole menu addition in Original too."""
from patches import PATCHES, _rel

# 0x4b309b is the ctor tail after package setup; preserve its store and all registers while cloning STATISTICS.
PATCHES.append(dict(addr=0x797640, old="00" * 15, new="8815758f740060ff15d430010061c3", entry=True, when=lambda: True))
PATCHES.append(dict(addr=0x4b309b, old="8815758f7400", new="e8" + _rel(0x4b309b, 0x797640) + "90", when=lambda: True))
# 0x4b33db accepts the new object hash before the shipped six-way switch; other hashes keep the original comparison/flags.
PATCHES.append(dict(addr=0x797660, old="00" * 32, new="3d" + "4d4e525f" + "0f84" + _rel(0x797666, 0x797675) + "3da2c336a9e9" + _rel(0x797670, 0x4b33e0) + "ff15d8300100e9" + _rel(0x79767b, 0x4b3769), entry=True, when=lambda: True))
PATCHES.append(dict(addr=0x4b33db, old="3da2c336a9", new="e9" + _rel(0x4b33db, 0x797660), when=lambda: True))
