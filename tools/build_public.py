#!/usr/bin/env python3
"""Public static build: dist/ = what a plain static host serves (Range + COOP/COEP/CORP headers, nothing else).
Copies the web files the game needs, links the big ones (web/out, game/, pc/Speed.exe, ug2/, gps/, launcher/): an upload
follows the links (rsync -L). No /plan/, no dev tools, no setup page. game-files.json is written here (host/files.c reads
it); window.RN_PUBLIC=1 is injected into the pages so web/boot.js and web/telemetry.js send no /log or /telemetry.
Usage: python3 tools/build_public.py   then   python3 tools/static_server.py [port] [dist]"""
import json, os, shutil, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
W, D = os.path.join(ROOT, "web"), os.path.join(ROOT, "dist")
LINK_DIRS = ["ug2", "gps", "launcher", "remaster"]
PAGES = ["index.html", "launcher.html"]
FLAG = "<script>window.RN_PUBLIC=1</script>\n"

shutil.rmtree(D, ignore_errors=True)
os.makedirs(os.path.join(D, "out"))
os.makedirs(os.path.join(D, "pc"))
for n in sorted(os.listdir(W)):
    p = os.path.join(W, n)
    if os.path.isfile(p) and n != "setup.html" and not n.startswith("."):
        if n in PAGES:
            s = open(p, encoding="utf-8").read()
            s = s.replace("<head>", "<head>\n" + FLAG, 1)
            open(os.path.join(D, n), "w", encoding="utf-8").write(s)
        else:
            shutil.copy2(p, os.path.join(D, n))
for n in LINK_DIRS:
    if os.path.isdir(os.path.join(W, n)):
        os.symlink(os.path.join(W, n), os.path.join(D, n))
for n in ("speed.js", "speed.wasm"):
    os.symlink(os.path.join(W, "out", n), os.path.join(D, "out", n))
os.symlink(os.path.join(ROOT, "pc", "Speed.exe"), os.path.join(D, "pc", "Speed.exe"))
os.symlink(os.path.join(ROOT, "build", "openworld"), os.path.join(D, "world"))   # WORLD's merged track files (tools/serve.py /world/)
game = os.path.join(ROOT, "game")
os.symlink(game, os.path.join(D, "game"))
files = sorted([os.path.relpath(os.path.join(d, n), game), os.path.getsize(os.path.join(d, n))]
               for d, _, ns in os.walk(game, followlinks=True) for n in ns)
json.dump(files, open(os.path.join(D, "game-files.json"), "w"), separators=(",", ":"))
print(f"dist/ ready: {len(files)} game files indexed")
