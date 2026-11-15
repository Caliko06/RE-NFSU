#!/usr/bin/env python3
"""Public package: dist/ = everything a plain static host serves, as real files (APFS clones, no links, no disk cost).
Engine (out/speed.js, out/speed.wasm, pc/Speed.exe, the web/*.js host), game data (game/ whole, songs included; ug2/, gps/,
launcher/, remaster/; world/ = only the names host/openworld.c:226-290 asks for), and three manifests:
game-files.json (host/files.c reads it), manifest.json (every file: path, bytes, sha256), _headers (COOP/COEP/CORP, the
Cloudflare Pages / Netlify syntax; SharedArrayBuffer needs them, tools/static_server.py sends the same three).
No /plan/, no dev tools, no setup page. window.RN_PUBLIC=1 is injected so web/boot.js and web/telemetry.js send nothing.
Usage: python3 tools/build_public.py   then   python3 tools/static_server.py [port] [dist]"""
import hashlib, json, os, re, shutil, subprocess

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
W, D = os.path.join(ROOT, "web"), os.path.join(ROOT, "dist")
LINK_DIRS = ["gps", "launcher"]
PAGES = ["index.html", "launcher.html"]
FLAG = "<script>window.RN_PUBLIC=1;window.RN_V='%s'</script>\n"


def version():
    """One stamp per build: the page's scripts, speed.wasm and Speed.exe are asked as <name>?v=<stamp>, so a browser or an
    edge holding an older copy (2026-11-15: a broken speed.wasm went out with a 1-day max-age) asks for the new one."""
    h = hashlib.sha256()
    for p in sorted(os.path.join(W, n) for n in os.listdir(W) if n.endswith((".js", ".html"))) + [
            os.path.join(W, "gps", n) for n in ("map.js", "tp.js", "route.js")] + [
            os.path.join(W, "ug2", "ug2world.js"), os.path.join(W, "out", "speed.js"), os.path.join(W, "out", "speed.wasm"), os.path.join(ROOT, "pc", "Speed.exe")]:
        h.update(open(p, "rb").read())
    return h.hexdigest()[:10]


V = version()

shutil.rmtree(D, ignore_errors=True)
os.makedirs(os.path.join(D, "out"))
os.makedirs(os.path.join(D, "pc"))
for n in sorted(os.listdir(W)):
    p = os.path.join(W, n)
    if os.path.isfile(p) and n != "setup.html" and not n.startswith("."):
        if n in PAGES:
            s = open(p, encoding="utf-8").read()
            s = s.replace("<head>", "<head>\n" + FLAG % V, 1)
            s = re.sub(r'(<script src="[^"?]+)"', r'\1?v=%s"' % V, s)
            open(os.path.join(D, n), "w", encoding="utf-8").write(s)
        else:
            shutil.copy2(p, os.path.join(D, n))
def clone(src, dst):
    subprocess.run(["cp", "-cRL", src, dst], check=True)   # -c = clonefile: a real file that shares the blocks


for n in LINK_DIRS:
    if os.path.isdir(os.path.join(W, n)):
        clone(os.path.join(W, n), os.path.join(D, n))
# ug2/: only what web/ug2/ug2world.js:68,102 fetches (the .gz packs of tools/pack_loadfast.py, tex.json, the script).
os.makedirs(os.path.join(D, "ug2"))
for n in sorted(os.listdir(os.path.join(W, "ug2"))):
    if n.endswith(".gz") or n in ("tex.json", "ug2world.js"):
        clone(os.path.join(W, "ug2", n), os.path.join(D, "ug2", n))
# remaster/ (opt-in): the index lists web/gpu.js:165-168 reads by default and every file they name; the world pack
# (index_world*.tsv, ?worldhd=1 only, no launcher toggle) stays out: 680 MB.
R = os.path.join(W, "remaster")
os.makedirs(os.path.join(D, "remaster"))
for t in ("index.tsv", "index_v2.tsv", "index_fe_v2.tsv", "index_bc.tsv", "index_glow.tsv"):
    clone(os.path.join(R, t), os.path.join(D, "remaster", t))
    for line in open(os.path.join(R, t)):
        f = line.rstrip("\n").split("\t")
        if len(f) < 2 or not f[1]:
            continue
        rel = f[1] if "/" in f[1] else "png/" + f[1] + ".png"
        if rel.endswith(".dds") and os.path.exists(os.path.join(R, rel + ".gz")):
            rel += ".gz"   # web/gpu.js:230 tries <name>.gz first
        dst = os.path.join(D, "remaster", rel)
        if not os.path.exists(dst):
            os.makedirs(os.path.dirname(dst), exist_ok=True)
            clone(os.path.join(R, rel), dst)
for n in ("speed.js", "speed.wasm"):
    clone(os.path.join(W, "out", n), os.path.join(D, "out", n))
clone(os.path.join(ROOT, "pc", "Speed.exe"), os.path.join(D, "pc", "Speed.exe"))
os.makedirs(os.path.join(D, "world"))
WORLD = re.compile(r"TRACKB\d+(_park|_bridge)?\.lzc|TEX1010TRACK\.BIN|CARS_TEXTURES\.BIN|DYNTEX\.BIN")   # host/openworld.c rn_world_open
for n in sorted(os.listdir(os.path.join(ROOT, "build", "openworld"))):
    if WORLD.fullmatch(n):
        clone(os.path.join(ROOT, "build", "openworld", n), os.path.join(D, "world", n))
game = os.path.join(D, "game")
clone(os.path.join(ROOT, "game"), game)
# Installer leftovers: never opened by Speed.exe (census/public_pack.tsv opened=no, docs/re/public_pack.md), 28.6 MB.
for line in open(os.path.join(ROOT, "census", "public_pack.tsv")):
    f = line.split("\t")
    if len(f) > 2 and f[2] == "no" and f[0].startswith("game/") and os.path.exists(os.path.join(D, f[0])):
        os.remove(os.path.join(D, f[0]))
for d in ("3DSetup", "AutoRun", "Support"):
    if os.path.isdir(os.path.join(game, d)) and not os.listdir(os.path.join(game, d)):
        os.rmdir(os.path.join(game, d))
for d, _, ns in os.walk(D):
    for n in ns:
        if n == ".DS_Store":
            os.remove(os.path.join(d, n))
files = sorted([os.path.relpath(os.path.join(d, n), game), os.path.getsize(os.path.join(d, n))]
               for d, _, ns in os.walk(game) for n in ns)
json.dump(files, open(os.path.join(D, "game-files.json"), "w"), separators=(",", ":"))
open(os.path.join(D, "_headers"), "w").write(
    "/*\n  Cross-Origin-Opener-Policy: same-origin\n  Cross-Origin-Embedder-Policy: require-corp\n  Cross-Origin-Resource-Policy: same-origin\n")


def sha(p):
    h = hashlib.sha256()
    with open(p, "rb") as f:
        while b := f.read(1 << 22):
            h.update(b)
    return h.hexdigest()


man = sorted([os.path.relpath(os.path.join(d, n), D), os.path.getsize(os.path.join(d, n)), sha(os.path.join(d, n))]
             for d, _, ns in os.walk(D) for n in ns)
json.dump({"files": man, "bytes": sum(m[1] for m in man)}, open(os.path.join(D, "manifest.json"), "w"), separators=(",", ":"))
print(f"dist/ ready: {len(man)} files, {sum(m[1] for m in man) / 1e9:.2f} GB, {len(files)} game files indexed")
