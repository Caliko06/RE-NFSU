#!/usr/bin/env python3
"""Bridge to ChatGPT Paola: one image per prompt through Codex's built-in image_gen, on her account (CODEX_HOME=~/.codex-paola).
  paola.py [name ...]    generate the named sheets of SHEETS (default all missing) into build/art/raw/<name>.png; 2 at a time; a 429 stops the batch.
"""
import os, subprocess, sys, concurrent.futures as cf
HEAD = ("Use your built-in image_gen tool exactly once (no scripts, no API key). One 1024x1024 image with a transparent background if the tool allows it, "
        "otherwise a pure flat #FF00FF magenta background. No car, no scene, no shadows, no mockup, no gradients on the background. ")
STYLE = "Era: 2003 street import tuner scene, die-cut vinyl graphics, flat 2-3 colors, high contrast, crisp vector-like edges, readable when small. "
def stickers(names): return ("A clean sticker sheet in a 4x4 grid, one die-cut decal per cell, generous empty margin, no overlap. " + STYLE +
    "Bold italic wordmarks and small emblems. Invented brands only, exactly these words: " + ", ".join(names) + ". No real brand logos, no other text.")
def sides(what): return ("Four long horizontal car-side vinyl graphics stacked in four equal rows, each spanning the full width, nose of the graphic pointing LEFT and tail fading to the right, no text. " + STYLE +
    "Match the attached references, the vinyl art of Need for Speed Underground (2003): aggressive, loud, thick shapes that cover most of the car side, 2-3 saturated colors. Not motorsport or Gran Turismo style. " + what)
SHEETS = {
 "stickers1": stickers("VOLTEC RACING, KAIZEN WORKS, NITRO JUNKIES, ZENKAI, MIDNIGHT GARAGE, APEX CLUB, TURBO KAI, RISING SUN AUTO, HYPERFLOW, DRIFT UNION, NEON ALLEY, STREETLAB, RYU SPEED, COLDSTART, OCTANE 77, BLACKTOP CREW".split(", ")),
 "stickers2": stickers("TOKYO LINE, SLIPSTREAM, REDLINE CARTEL, GHOST PIPE, KATSU TUNING, BOOST ADDICT, NIGHT SHIFT, VTEC-LESS, SIDEWAYS CO, PLASMA KIT, 2-STEP, LOW RIDE HI REV, CHROME DOME, EASTSIDE IMPORTS, OVERBORE, WET NITROUS".split(", ")),
 "sides_tribal": sides("Sharp tribal flames and blades, 2003 show car style."),
 "sides_slash": sides("Angular speed slashes, shards and torn-edge splits, street racer style."),
 "sides_stripes": sides("Clean thin pinstripes, twin racing bands and subtle fades, time-attack style."),
 "sides_kanji": sides("Bold abstract brush strokes and rising sun rays, bosozoku style, no characters."),
}
def run(name):
    out = f"build/art/raw/{name}.png"
    if os.path.exists(out): return name, "exists"
    p = subprocess.run(["codex", "exec", "-C", os.getcwd(), "-s", "workspace-write", "--skip-git-repo-check", "-c", "model_reasoning_effort=low", "-i", "build/art/ref/sheet.png", "--",
        HEAD + SHEETS[name] + f" After generating, copy the PNG to {out} and reply with just that path."], env={**os.environ, "CODEX_HOME": os.path.expanduser("~/.codex-paola")},
        capture_output=True, text=True, timeout=600)
    open(f"build/art/raw/{name}.log", "w").write(p.stdout + p.stderr)
    return name, "ok" if os.path.exists(out) else "429" if "usage_limit_reached" in p.stdout + p.stderr else "failed"
if __name__ == "__main__":
    os.makedirs("build/art/raw", exist_ok=True)
    names = sys.argv[1:] or list(SHEETS)
    with cf.ThreadPoolExecutor(2) as x:
        for n, r in x.map(run, names): print(n, r, flush=True)
