#!/usr/bin/env python3
"""Canon database of Speed.exe (docs/re/canon_db.md).

  canon.py seed            build/canon/seed.tsv: every lifted start + merged names/systems
  canon.py apply           clone build/ghidra/proj -> build/ghidra/canon once, create missing functions, apply names
  canon.py export [-j N]   named pseudocode + index -> census/canon/{c/*.c,funcs.jsonl}, data.jsonl
  canon.py queue           census/canon/queue.tsv: unnamed functions bottom-up (callees named first) + coverage
  canon.py batch <system> <n> [skip]   next n ready rows of one system -> build/canon/batch_<system>.txt (addrs)
  canon.py show <addr|@file>...        named pseudocode of just those functions, with a one-line index each
"""
import csv, glob, json, os, re, shutil, subprocess, sys, tempfile
from collections import Counter
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)
JAVA = "/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home"
HEADLESS = "/opt/homebrew/Cellar/ghidra/12.1.4/libexec/support/analyzeHeadless"
PROJ, CANON, OUT = "build/ghidra/proj", "build/ghidra/canon", "census/canon"
SYSTEMS = ("render", "canon", "runtime", "audio", "rivals", "car", "track", "online", "hud", "camera",
           "traffic", "props", "assets", "input")
TOP = {"blur": "render", "fe": None, "other": None, "system": None}


def a(s):
    return int(s.replace("0x", ""), 16)


def lifted():
    out = set()
    for fn in glob.glob("build/gen/f*.c"):
        out.update(int(m, 16) for m in re.findall(r"^[a-z_0-9 ]+ f_([0-9a-f]{6})\(", open(fn, errors="replace").read(), re.M))
    return out


def tsv(p):
    return csv.DictReader((l for l in open(p) if not l.startswith("#")), delimiter="\t")


def merged():
    """addr -> dict(name, system, conf, tool, doc); same precedence as tools/census/scoreboard.py."""
    system = {}
    for r in tsv("census/systems.tsv"):
        try:
            system.setdefault(a(r["addr"]), (r["system"], r["confidence"]))
        except (ValueError, KeyError, TypeError):
            pass
    for line in open("census/systems_override.tsv"):
        f = line.rstrip("\n").split("\t")
        if len(f) >= 2 and f[1] in SYSTEMS and not line.startswith(("#", "addr")):
            system[a(f[0])] = (f[1], "high")
    rows = {}
    for p in sorted(glob.glob("census/names_*.tsv")):
        if p.endswith("names_seed.tsv"):
            continue
        for r in tsv(p):
            try:
                x = a(r["addr"])
            except (ValueError, KeyError, TypeError, AttributeError):
                continue
            if not r.get("name") or x in rows:
                continue
            c = (r.get("confidence") or "").strip()
            t = (r.get("system") or "").strip().split(".")[0]
            t = TOP.get(t, t)
            rows[x] = dict(name=r["name"].strip(), system=t if t in SYSTEMS and c != "U" else None, conf=c,
                           tool=(r.get("tool") or "").strip(), doc=(r.get("doc") or "").strip())
    return system, rows


def seed():
    L = lifted()
    system, rows = merged()
    os.makedirs("build/canon", exist_ok=True)
    with open("build/canon/seed.tsv", "w") as o:
        o.write("# addr kind name system conf tool doc (tools/canon/canon.py seed)\n")
        for x in sorted(L | set(rows)):
            r = rows.get(x, {})
            s = r.get("system") or system.get(x, ("unknown", "low"))[0]
            o.write("\t".join([hex(x), "func", r.get("name", ""), s, r.get("conf", ""), r.get("tool", ""), r.get("doc", "")]) + "\n")
    print(f"seed: {len(L)} lifted, {len(rows)} named rows -> build/canon/seed.tsv")


def headless(proj, *script_args, log):
    env = dict(os.environ, JAVA_HOME=JAVA, PATH=JAVA + "/bin:" + os.environ["PATH"])
    ro = [] if script_args[0] == "apply" else ["-readOnly"]
    cmd = [HEADLESS, proj, "nfsu", "-process", "Speed.exe", "-noanalysis", *ro, "-scriptPath", ROOT + "/tools/canon",
           "-postScript", "Canon.java", *script_args]
    with open(log, "w") as f:
        rc = subprocess.run(cmd, env=env, stdout=f, stderr=subprocess.STDOUT).returncode
    txt = open(log).read()
    if rc or "ERROR Abort" in txt or "Unable to lock" in txt or "Script Error" in txt or "Exception" in txt:
        sys.exit(f"ghidra failed, see {log}")


def apply():
    if not os.path.exists(CANON):
        subprocess.run(["cp", "-c", "-R", PROJ, CANON], check=True)
    seed()
    headless(ROOT + "/" + CANON, "apply", ROOT + "/build/canon/seed.tsv", ROOT + "/build/canon/apply.txt",
             log="build/canon/apply.log")
    print(open("build/canon/apply.txt").read().splitlines()[-1])


def export(jobs=4):
    os.makedirs(OUT + "/c", exist_ok=True)
    tmp = os.path.relpath(tempfile.mkdtemp(prefix="canon.", dir="build/canon"))
    edges = list(range(0x401000, 0x697000, 0x10000)) + [0x697000]
    ranges = list(zip(edges, edges[1:]))

    def one(i):
        lo, hi = ranges[i]
        p = f"{tmp}/p{i}"
        subprocess.run(["cp", "-c", "-R", CANON, p], check=True)
        try:
            headless(ROOT + "/" + p, "export", hex(lo), hex(hi), f"{ROOT}/{tmp}/r{lo:x}", log=f"{tmp}/r{lo:x}.log")
        finally:
            shutil.rmtree(p, ignore_errors=True)
        os.replace(f"{tmp}/r{lo:x}.c", f"{OUT}/c/{lo:x}.c")
        return f"{tmp}/r{lo:x}.jsonl"

    with ThreadPoolExecutor(jobs) as ex:
        parts = list(ex.map(one, range(len(ranges))))
    with open(OUT + "/funcs.jsonl", "w") as o:
        for p in parts:
            o.write(open(p).read())
    p = f"{tmp}/pd"
    subprocess.run(["cp", "-c", "-R", CANON, p], check=True)
    headless(ROOT + "/" + p, "data", f"{ROOT}/{OUT}/data.jsonl", log=f"{tmp}/data.log")
    shutil.rmtree(tmp, ignore_errors=True)
    print(f"export: {sum(1 for _ in open(OUT + '/funcs.jsonl'))} functions, {sum(1 for _ in open(OUT + '/data.jsonl'))} data rows")


def queue():
    """Bottom-up worklist: an unnamed function is ready when all its callees are named or trivial."""
    L = lifted()
    system, rows = merged()
    F = {a(j["addr"]): j for j in map(json.loads, open(OUT + "/funcs.jsonl"))}
    named = {x for x, r in rows.items() if r["name"]}
    auto = re.compile(r"^(FUN|thunk_FUN|LAB|SUB)_")
    trivial = {x for x, j in F.items() if j["size"] <= 8 and not j["callees"]}
    done = named | trivial
    hint = {}   # prior art (tools/canon/gcalign.py, prior.py): addr -> "grade name"
    for f, k, g in (("prior_mw.tsv", 2, None), ("prior_gc.tsv", 3, 6)):
        if os.path.exists(f"{OUT}/{f}"):
            for r in list(csv.reader(open(f"{OUT}/{f}"), delimiter="\t"))[1:]:
                hint[a(r[0])] = (r[g] if g else "mw") + " " + r[k]
    out, stat = [], Counter()
    for x in sorted(L):
        s = (rows.get(x) or {}).get("system") or system.get(x, ("unknown", "low"))[0]
        j = F.get(x)
        stat[s, "total"] += 1
        if x in done:
            stat[s, "done"] += 1
            continue
        if s == "online":
            continue
        cal = [a(c) for c in (j or {}).get("callees", [])]
        open_callees = sum(c not in done for c in cal)
        stat[s, "ready" if not open_callees else "blocked"] += 1
        out.append((open_callees, s, x, (j or {}).get("size", 0), len(cal), len((j or {}).get("callers", [])),
                    len((j or {}).get("strings", [])), hint.get(x, "")))
    out.sort(key=lambda t: (t[0], t[1], t[2]))
    with open(OUT + "/queue.tsv", "w") as o:
        o.write("addr\tsystem\topen_callees\tsize\tcallees\tcallers\tstrings\tprior\n")
        for oc, s, x, sz, nc, nr, ns, h in out:
            o.write(f"{x:#x}\t{s}\t{oc}\t{sz}\t{nc}\t{nr}\t{ns}\t{h}\n")
    print("system\ttotal\tdone\tready\tblocked")
    for s in sorted({k[0] for k in stat}, key=lambda s: -stat[s, "total"]):
        print(f"{s}\t{stat[s,'total']}\t{stat[s,'done']}\t{stat[s,'ready']}\t{stat[s,'blocked']}")
    print(f"queue: {len(out)} rows -> {OUT}/queue.tsv; missing from export: {len(L - set(F))}")


def batch(system, n, skip=0):
    rows = [r for r in csv.DictReader(open(OUT + "/queue.tsv"), delimiter="\t")
            if r["system"] == system and r["open_callees"] == "0"]
    pick = [r["addr"] for r in rows[int(skip):int(skip) + int(n)]]
    os.makedirs("build/canon", exist_ok=True)
    open(f"build/canon/batch_{system}.txt", "w").write("\n".join(pick) + "\n")
    print(f"batch {system}: {len(pick)} of {len(rows)} ready -> build/canon/batch_{system}.txt")


def show(args):
    want = []
    for x in args:
        want += [l.split()[0] for l in open(x[1:]) if l.strip()] if x.startswith("@") else [x]
    want = [hex(a(x)) for x in want]
    hint = {r["addr"]: r["prior"] for r in csv.DictReader(open(OUT + "/queue.tsv"), delimiter="\t")}
    idx = {j["addr"]: j for j in map(json.loads, open(OUT + "/funcs.jsonl")) if j["addr"] in set(want)}
    strs = {}
    for l in open(OUT + "/data.jsonl"):
        d = json.loads(l)
        if d.get("str"):
            strs[d["addr"]] = d["str"][:60]
    for x in want:
        lo = 0x401000 + (a(x) - 0x401000) // 0x10000 * 0x10000
        txt = open(f"{OUT}/c/{lo:x}.c").read()
        i = txt.find(f"// ==== {x} ")
        body = txt[i:txt.find("\n// ==== ", i + 1)] if i >= 0 else f"// ==== {x} not exported\n"
        j = idx.get(x, {})
        print(f"// index: size {j.get('size')} callers {len(j.get('callers', []))} prior [{hint.get(x, '')}] "
              f"strings {[strs.get(s, s) for s in j.get('strings', [])][:6]} globals {j.get('globals', [])[:8]}")
        print(body.rstrip() + "\n")


if __name__ == "__main__":
    cmd = sys.argv[1] if len(sys.argv) > 1 else "seed"
    if cmd == "export":
        export(int(sys.argv[3]) if len(sys.argv) > 3 and sys.argv[2] == "-j" else 4)
    elif cmd == "batch":
        batch(*sys.argv[2:5])
    elif cmd == "show":
        show(sys.argv[2:])
    else:
        {"seed": seed, "apply": apply, "queue": queue}[cmd]()
