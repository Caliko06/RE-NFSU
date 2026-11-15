"""Before/after cards of the launcher (web/launcher/ba/): crops of real game captures, one run per option value.
Captures: node tools/webcheck.mjs "http://127.0.0.1:5180/?<flag>&traffic=0&play=1&fast=1&go=1&pool=1&mute=1&mode=remaster" 70 <dir>/<name>.png
with <name>:<flag> = base:x=1 bloom0:bloom=0 rem1:remaster=1 refl:roadrefl=game look:carlook=2003 orig:mode=original (1280x900).
traffic=0: with traffic every run shows other cars, so the two sides of a card did not match.
Usage: .venv/bin/python tools/launcher_ba.py <dir with the captures>"""
import os, sys
from PIL import Image
SRC, OUT = sys.argv[1], os.path.join(os.path.dirname(__file__), "..", "web", "launcher", "ba")
# option id: (capture a, capture b, crop box of the 1280x900 frame where the difference shows)
CARDS = {"bloom": ("bloom0", "base", (380, 0, 1020, 480)), "remaster": ("base", "rem1", (300, 420, 940, 900)),
         "roadrefl": ("base", "refl", (240, 420, 880, 900)),
         "mode": ("orig", "base", (40, 0, 1240, 900)), "carlook": ("base", "look", (400, 480, 880, 840))}
os.makedirs(OUT, exist_ok=True)
for oid, (a, b, box) in CARDS.items():
    for side, name in (("a", a), ("b", b)):
        Image.open(os.path.join(SRC, name + ".png")).convert("RGB").crop(box).resize((500, 375), Image.LANCZOS).save(os.path.join(OUT, f"{oid}_{side}.webp"), quality=84)
print("cards:", ", ".join(CARDS))
