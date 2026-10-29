#!/usr/bin/env python3
"""Canon database of Speed.exe (docs/re/canon_db.md).

  canon.py seed            build/canon/seed.tsv: every lifted start + merged names/systems
  canon.py apply           clone build/ghidra/proj -> build/ghidra/canon once, create missing functions (lifted starts, vtable slots), apply names
  canon.py export [-j N]   named pseudocode + index -> census/canon/{c/*.c,funcs.jsonl}, data.jsonl
  canon.py queue           census/canon/queue.tsv: unnamed functions bottom-up (callees named first) + coverage
  canon.py batch <system> <n> [skip]   next n ready rows of one system -> build/canon/batch_<system>.txt (addrs)
  canon.py batchfile <n> [k] [skip,files]  next n unnamed functions grouped by GC source file -> build/canon/batch_file_<k>.txt
  canon.py show <addr|@file>...        named pseudocode of just those functions, with a one-line index each
"""
import csv, glob, json, math, os, re, shutil, subprocess, sys, tempfile
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
                           evidence=(r.get("evidence") or ""),
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
    ro = [] if script_args[0] in ("apply", "vtscan") else ["-readOnly"]
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
    # vtable slots are entries reached only by indirect calls: create the functions the seed lacks
    headless(ROOT + "/" + CANON, "vtscan", ROOT + "/build/canon/vtscan.txt", log="build/canon/vtscan.log")
    print(open("build/canon/vtscan.txt").read().splitlines()[-1])


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
    hint = {}   # prior art (tools/canon/gcalign.py, prior.py, vtables.py): addr -> "grade name"
    # vtable slot names last: they win over GC (vtables.py --check 79/88 agree vs GC R/B 60-80 %)
    for f, k, g in (("prior_mw.tsv", 2, "mw"), ("prior_gc.tsv", 3, 6), ("prior_vt.tsv", 1, "vt")):
        if os.path.exists(f"{OUT}/{f}"):
            for r in list(csv.reader(open(f"{OUT}/{f}"), delimiter="\t"))[1:]:
                hint[a(r[0])] = (r[g] if isinstance(g, int) else g) + " " + r[k]
    # lifter starts that are not Ghidra functions (inside another function, or creation failed): a ledger, not work
    parent = {}
    for l in open("build/canon/apply.txt"):
        f = l.split()
        if f and f[0] in ("inside", "fail"):
            parent[a(f[1])] = f[2] if len(f) > 2 else "?"
    frag = [x for x in sorted(L) if x not in F]
    with open(OUT + "/fragments.tsv", "w") as o:
        o.write("addr\tparent\twhy\n")
        for x in frag:
            o.write(f"{x:#x}\t{parent.get(x, '?')}\t{'inside' if parent.get(x, '?') != '?' else 'not a Ghidra function'}\n")
    out, stat = [], Counter()
    for x in sorted(L):
        if x not in F:
            continue
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
                    len((j or {}).get("strings", [])),
                    # GC hints on < 48-byte functions are noise: MSVC emits header inlines out of line, the GC build
                    # inlines them, so small PC leaves have no GC twin (round 1: 2 A hints on 16-byte getters wrong)
                    hint.get(x, "") if hint.get(x, "").startswith(("mw", "vt")) or (j or {}).get("size", 0) >= 48 else ""))
    out.sort(key=lambda t: (t[0], t[1], t[2]))
    with open(OUT + "/queue.tsv", "w") as o:
        o.write("addr\tsystem\topen_callees\tsize\tcallees\tcallers\tstrings\tprior\n")
        for oc, s, x, sz, nc, nr, ns, h in out:
            o.write(f"{x:#x}\t{s}\t{oc}\t{sz}\t{nc}\t{nr}\t{ns}\t{h}\n")
    print("system\ttotal\tdone\tready\tblocked")
    for s in sorted({k[0] for k in stat}, key=lambda s: -stat[s, "total"]):
        print(f"{s}\t{stat[s,'total']}\t{stat[s,'done']}\t{stat[s,'ready']}\t{stat[s,'blocked']}")
    print(f"queue: {len(out)} rows -> {OUT}/queue.tsv; {len(frag)} lifter-only starts -> {OUT}/fragments.tsv")


def batch(system, n, skip=0):
    rows = [r for r in csv.DictReader(open(OUT + "/queue.tsv"), delimiter="\t")
            if r["system"] == system and r["open_callees"] == "0"]
    pick = [r["addr"] for r in rows[int(skip):int(skip) + int(n)]]
    os.makedirs("build/canon", exist_ok=True)
    open(f"build/canon/batch_{system}.txt", "w").write("\n".join(pick) + "\n")
    print(f"batch {system}: {len(pick)} of {len(rows)} ready -> build/canon/batch_{system}.txt")


def batchfile(n, k="1", skip_files=""):
    """Next batch by GameCube source file: unnamed functions whose aligned or sandwiched file is the same, whole files
    first (largest open file), address order. A worker then reads one class/file at a time."""
    q = {a(r["addr"]): r for r in csv.DictReader(open(OUT + "/queue.tsv"), delimiter="\t")}
    gcr = {a(r["addr"]): r["tu"] for r in csv.DictReader(open(OUT + "/prior_gc.tsv"), delimiter="\t")}
    ga = sorted(gcr)
    import bisect
    tu = {}
    for x in q:
        if x in gcr:
            tu[x] = gcr[x]
        else:
            i = bisect.bisect_left(ga, x)
            if 0 < i < len(ga) and gcr[ga[i - 1]] == gcr[ga[i]]:
                tu[x] = gcr[ga[i]]
    skip = set(skip_files.split(",")) if skip_files else set()
    files = {}
    for x, t in tu.items():
        if t and "GameCube" not in t and not t.startswith("libc") and t not in skip and q[x]["system"] != "online":
            files.setdefault(t, []).append(x)
    pick, names = [], []
    for t, xs in sorted(files.items(), key=lambda kv: -len(kv[1])):
        if len(pick) >= int(n):
            break
        pick += sorted(xs)[: int(n) - len(pick)]
        names.append(f"{t} ({len(xs)})")
    path = f"build/canon/batch_file_{k}.txt"
    with open(path, "w") as o:
        o.write("# files: " + "; ".join(names) + "\n" + "\n".join(f"{x:#x}" for x in pick) + "\n")
    print(f"batchfile {k}: {len(pick)} functions from {names} -> {path}; {len(files)} files open, "
          f"{sum(map(len, files.values()))} functions with a file")


def show(args):
    want = []
    for x in args:
        want += [l.split()[0] for l in open(x[1:]) if l.strip() and not l.startswith("#")] if x.startswith("@") else [x]
    want = [hex(a(x)) for x in want]
    hint = {r["addr"]: r["prior"] for r in csv.DictReader(open(OUT + "/queue.tsv"), delimiter="\t")}
    idx = {j["addr"]: j for j in map(json.loads, open(OUT + "/funcs.jsonl")) if j["addr"] in set(want)}
    strs = {}
    for l in open(OUT + "/data.jsonl"):
        d = json.loads(l)
        if d.get("str"):
            strs[d["addr"]] = d["str"][:60]
    # GC window: the aligned GC symbol +-3 inside the same source file (alignment is often off by one; the file is
    # right 94 %), with full mangled names, which carry the argument types
    gcrow = {}
    if os.path.exists(OUT + "/prior_gc.tsv"):
        gcrow = {r["addr"]: r for r in csv.DictReader(open(OUT + "/prior_gc.tsv"), delimiter="\t")}
    gsyms = []
    if gcrow:
        for l in open("build/prior/nfsug/symbols.txt"):
            if "type:function" in l and ".text:" in l:
                m = re.search(r"\.text:(0x\w+).*size:(0x\w+)", l)
                gsyms.append((int(m.group(1), 16), int(m.group(2), 16), l.split(" = ")[0]))
        gsyms.sort()
    gaddr = [g[0] for g in gsyms]
    # Free GC methods of the same source file: not yet taken by any PC name, nearest size first (what workers did by
    # grepping symbols.txt by class in round 3)
    taken, by_tu = set(), {}
    if gcrow:
        sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
        from gcalign import demangle
        taken = {r["name"] for r in merged()[1].values()}
        tu_of = {a(r["gc_addr"]): r["tu"] for r in gcrow.values()}
        for ga_, sz, n in gsyms:
            if ga_ in tu_of and demangle(n) not in taken:
                by_tu.setdefault(tu_of[ga_], []).append((sz, n))
    for x in want:
        r = gcrow.get(x)
        j0 = idx.get(x, {})
        if r and r["tu"] in by_tu and j0.get("size", 0) >= 24:
            ps = j0["size"] / 0.88   # PC/GC size ratio (gcalign.py)
            near = sorted(by_tu[r["tu"]], key=lambda t: abs(math.log(max(t[0], 1) / ps)))[:16]
            print(f"// GC free in file ({len(by_tu[r['tu']])}): " + " | ".join(f"{n} ({sz}B)" for sz, n in near))
        r = gcrow.get(x)
        if r and gsyms:
            import bisect
            i = bisect.bisect_left(gaddr, a(r["gc_addr"]))
            win = [f"{'>' if k == i else ' '}{gsyms[k][2]} ({gsyms[k][1]}B)" for k in range(max(0, i - 3), min(len(gsyms), i + 4))]
            print(f"// GC window ({r['grade']}, file {r['tu']}): " + " | ".join(win))
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
    elif cmd == "batchfile":
        batchfile(*sys.argv[2:5])
    elif cmd == "show":
        show(sys.argv[2:])
    else:
        {"seed": seed, "apply": apply, "queue": queue}[cmd]()
