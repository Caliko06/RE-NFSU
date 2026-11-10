"""Patches: Minecraft lane, front F-Speed (docs/re/mc_speed_exit.md). Leaving the car in Free Run; host/mc.c does the work, gated on RN_MC (0 in original mode)."""
from patches import PATCHES, _rel

# PATCH 0x4479be (+ cave 0x797600, CODE_AREA): the main loop 0x447600 updates every view's camera mover (0x48e8b0, no args, plain ret; each mover
# ends in Camera::SetCameraMatrix 0x47d070) before RenderFrame 0x40a580 at 0x447a10. The call goes to host/mc.c mc_views: the original call, then,
# while the player walks, 0x47d070 again on the player camera [0x740500] with the third-person matrix, so render and culling follow the pedestrian.
PATCHES.append(dict(addr=0x4479be, old="e8ed6e0400", new="e8" + _rel(0x4479be, 0x797600), when=lambda: True))
PATCHES.append(dict(addr=0x797600, old="00" * 6, new="ff25c8300100", entry=True, when=lambda: True))
