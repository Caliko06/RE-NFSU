#!/usr/bin/env python3
"""Names from the GameCube prototype (docs/re/canon_db.md): dbalatoni13/nfsug config/GNDP8P/symbols.txt + splits.txt
(fetched to build/prior/nfsug) are the same Speed source two months before our PC build, linked in nearly the same
order (369 anchors, 321 monotone). Align our functions to theirs between anchors.

  gcalign.py [--holdout K]   -> census/canon/prior_gc.tsv (addr, gc_name, demangled, tu, score, grade)

Anchors: our names (census/names.tsv) whose demangled GC name is unique, kept on the longest increasing run.
Between two anchors, a global alignment (Needleman-Wunsch) of PC sizes vs GC sizes, ratio fitted on the anchors.
Grade A: interval with equal counts and every pair inside the size band; B: matched by DP inside the band; C: weak.
--holdout K hides every K-th anchor and reports how many come back on the right GC symbol.
"""
import bisect, csv, json, math, os, re, statistics, sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)
GC_LO, GC_HI = 0x80003100, 0x80240000   # .text


def demangle(n):
    """CodeWarrior/GCC2 names to Class::method (enough to compare with ours; args dropped).
    method__<len>Class..., method__Q<k><len>A<len>B..., __<class> = ctor, _._<class> = dtor, func__F... = free."""

    def scope(t):
        if t[:1] == "Q" and t[1:2].isdigit():
            k, t, parts = int(t[1]), t[2:], []
            for _ in range(k):
                m = re.match(r"(\d+)", t)
                if not m:
                    return None
                L = int(m.group(1))
                parts.append(t[len(m.group(1)):len(m.group(1)) + L])
                t = t[len(m.group(1)) + L:]
            return parts
        m = re.match(r"(\d+)", t)
        if not m:
            return None
        L = int(m.group(1))
        return [t[len(m.group(1)):len(m.group(1)) + L]]

    for pre, dtor in (("_._", True), ("__", False)):
        if n.startswith(pre):
            p = scope(n[len(pre):])
            if p:
                return "::".join(p + [("~" if dtor else "") + p[-1]])
    m = re.match(r"^(\w+?)__(?=[Q\d])", n)
    if m:
        p = scope(n[len(m.group(0)):])
        if p:
            return "::".join(p + [m.group(1)])
    m = re.match(r"^(\w+?)__F", n)
    return m.group(1) if m else n


def gc_funcs():
    tu, ranges = None, []
    for line in open("build/prior/nfsug/splits.txt"):
        if re.match(r"^\S.*:$", line) and line.strip() != "Sections:":
            tu = line.strip()[:-1]
        m = re.match(r"\s+\.text\s+start:(0x\w+) end:(0x\w+)", line)
        if m and tu:
            ranges.append((int(m.group(1), 16), int(m.group(2), 16), tu))
    ranges.sort()
    starts = [r[0] for r in ranges]
    out = []
    for line in open("build/prior/nfsug/symbols.txt"):
        if "type:function" not in line or ".text:" not in line:
            continue
        n = line.split(" = ")[0]
        a = int(re.search(r"\.text:(0x\w+)", line).group(1), 16)
        s = int(re.search(r"size:(0x\w+)", line).group(1), 16)
        i = bisect.bisect_right(starts, a) - 1
        t = ranges[i][2] if i >= 0 and a < ranges[i][1] else ""
        out.append(dict(addr=a, size=s, name=n, dm=demangle(n), tu=t))
    out.sort(key=lambda f: f["addr"])
    return out


def lis(an):
    tails, idx, prev = [], [], [None] * len(an)
    for i, (_, g, _) in enumerate(an):
        k = bisect.bisect_left(tails, g)
        if k == len(tails):
            tails.append(g), idx.append(i)
        else:
            tails[k], idx[k] = g, i
        prev[i] = idx[k - 1] if k else None
    keep, i = [], idx[-1] if idx else None
    while i is not None:
        keep.append(an[i])
        i = prev[i]
    return keep[::-1]


def interval_pass(an, pa, ga, psize, gc, ratio, sd):
    res = {}
    for (p0, g0, _), (p1, g1, _) in zip(an, an[1:]):
        i0, i1 = bisect.bisect_right(pa, p0), bisect.bisect_left(pa, p1)
        j0, j1 = bisect.bisect_right(ga, g0), bisect.bisect_left(ga, g1)
        P = [(pa[i], psize[pa[i]]) for i in range(i0, i1)]
        G = [(ga[j], gc[j]["size"]) for j in range(j0, j1)]
        if not P or not G:
            continue
        pairs = align(P, G, ratio, sd)
        same = len(P) == len(G) and all(z < 2 for _, _, z in pairs) and len(pairs) == len(P)
        runs = diag_runs([(pi, gi) for pi, gi, _ in pairs])
        for pi, gi, z in pairs:
            r = runs[pi]
            grade = "A" if same else "R" if r >= 4 and z < 1.5 else "B" if z < 1.5 else "C"
            res[P[pi][0]] = (gc[j0 + gi], z, grade, len(P), len(G))
    return res


def anchors(pc, gc, hide=0):
    by = {}
    for g in gc:
        by.setdefault(g["dm"], []).append(g["addr"])
    pcset = {f["addr"] for f in pc}
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import canon   # same merge of census/names_*.tsv as the queue, so wave names become anchors
    _, rows = canon.merged()
    an = sorted((x, by[r["name"]][0], r["name"]) for x, r in rows.items()
                if r["name"] in by and len(by[r["name"]]) == 1 and x in pcset)
    keep = lis(an)
    hidden = keep[hide - 1::hide] if hide else []
    return [a for a in keep if a not in hidden], hidden


def align(P, G, ratio, sd):
    """Needleman-Wunsch on log sizes. P, G: lists of (addr, size). Returns [(pi, gi, z)]."""
    n, m = len(P), len(G)
    if n * m > 25_000_000:
        return []
    GAP = -0.6

    def sc(p, g):
        z = abs(math.log(max(p, 1) / (ratio * max(g, 1)))) / sd
        return 1.5 - z, z

    D = [[0.0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        D[i][0] = i * GAP
    for j in range(1, m + 1):
        D[0][j] = j * GAP
    for i in range(1, n + 1):
        Di, Dp, pi = D[i], D[i - 1], P[i - 1][1]
        for j in range(1, m + 1):
            Di[j] = max(Dp[j - 1] + sc(pi, G[j - 1][1])[0], Dp[j] + GAP, Di[j - 1] + GAP)
    out, i, j = [], n, m
    while i and j:
        s, z = sc(P[i - 1][1], G[j - 1][1])
        if abs(D[i][j] - (D[i - 1][j - 1] + s)) < 1e-9:
            out.append((i - 1, j - 1, z))
            i, j = i - 1, j - 1
        elif abs(D[i][j] - (D[i - 1][j] + GAP)) < 1e-9:
            i -= 1
        else:
            j -= 1
    return out[::-1]


def diag_runs(pairs):
    """Length of the diagonal run (consecutive on both sides) each pair sits in."""
    run, out, k = [], {}, 0
    for t in pairs + [None]:
        if run and (t is None or t[0] != run[-1][0] + 1 or t[1] != run[-1][1] + 1):
            for x in run:
                out[x[0]] = len(run)
            run = []
        if t is not None:
            run.append(t)
    return out


def run(hide=0, rounds=4):
    pc = sorted((json.loads(l) for l in open("census/canon/funcs.jsonl")), key=lambda j: int(j["addr"], 16))
    pc = [dict(addr=int(j["addr"], 16), size=j["size"]) for j in pc]
    gc = gc_funcs()
    an, hidden = anchors(pc, gc, hide)
    gsize = {g["addr"]: g["size"] for g in gc}
    psize = {f["addr"]: f["size"] for f in pc}
    logs = [math.log(psize[p] / gsize[g]) for p, g, _ in an if psize[p] > 8 and gsize[g] > 8]
    ratio, sd = math.exp(statistics.median(logs)), statistics.pstdev(logs) or 0.3
    pa = [f["addr"] for f in pc]
    ga = [g["addr"] for g in gc]
    promoted = {}   # pairs promoted to anchors keep the grade they earned
    for rnd in range(rounds):
        res = {**promoted, **interval_pass(an, pa, ga, psize, gc, ratio, sd)}
        promoted.update({p: v for p, v in res.items() if v[2] in ("A", "R")})
        strong = sorted((p, v[0]["addr"], "") for p, v in res.items() if v[2] in ("A", "R"))
        merged = sorted(set(an) | set(strong))
        keep = lis(merged)
        if len(keep) <= len(an):
            break
        an = keep
    for p, g, _ in an:
        res.setdefault(p, (gc[bisect.bisect_left(ga, g)], 0.0, "anchor", 0, 0))
    an_out = an
    if hide:
        res = {p: v for p, v in res.items()}
        ok = sum(res.get(p, ({"addr": 0},))[0]["addr"] == g for p, g, _ in hidden)
        by_grade = {}
        for p, g, _ in hidden:
            r = res.get(p)
            k = r[2] if r else "none"
            by_grade.setdefault(k, [0, 0])
            by_grade[k][0] += r is not None and r[0]["addr"] == g
            by_grade[k][1] += 1
        tu = {g["addr"]: g["tu"] for g in gc}
        tu_ok = sum(p in res and res[p][0]["tu"] == tu[g] for p, g, _ in hidden)
        print(f"holdout 1/{hide}: same TU {tu_ok}/{sum(p in res for p, _, _ in hidden)};", end=" ")
        print(f"holdout 1/{hide}: {ok}/{len(hidden)} right; by grade {by_grade}; ratio {ratio:.2f} sd {sd:.2f}")
        return
    # String check: a PC function that references a string equal to its GC class (or a method's class) -> grade S;
    # a string naming a different GC class -> X. GameCube-only translation units (platform, SDK, MSL) -> P.
    strs = {}
    for l in open("census/canon/data.jsonl"):
        d = json.loads(l)
        if d.get("str"):
            strs[d["addr"]] = d["str"].strip()
    classes = {g["dm"].split("::")[0] for g in gc if "::" in g["dm"]}
    fstr = {int(j["addr"], 16): [strs.get(x, "") for x in j["strings"]] for j in map(json.loads, open("census/canon/funcs.jsonl"))}
    for p, (g, z, grade, a, b) in list(res.items()):
        if grade == "anchor":
            continue
        cls = g["dm"].split("::")[0] if "::" in g["dm"] else None
        named = {x for x in fstr.get(p, []) if x in classes}
        if cls and cls in named:
            grade = "S"
        elif named and cls and cls not in named and len(named) == 1:
            grade = "X"
        if "GameCube" in g["tu"] or g["tu"].startswith(("libc", "PowerPC", "TRK", "dolphin")) or not g["tu"]:
            grade = "P"
        res[p] = (g, z, grade, a, b)
    with open("census/canon/prior_gc.tsv", "w") as o:
        o.write("addr\tgc_addr\tgc_name\tdemangled\ttu\tz\tgrade\n")
        for p in sorted(res):
            g, z, grade, _, _ = res[p]
            o.write(f"{p:#x}\t{g['addr']:#x}\t{g['name']}\t{g['dm']}\t{g['tu']}\t{z:.2f}\t{grade}\n")
    c = {}
    for v in res.values():
        c[v[2]] = c.get(v[2], 0) + 1
    print(f"gc: {len(an_out)} anchors, {len(res)} rows {c}; ratio {ratio:.2f} sd {sd:.2f} -> census/canon/prior_gc.tsv")


if __name__ == "__main__":
    run(int(sys.argv[2]) if len(sys.argv) > 2 and sys.argv[1] == "--holdout" else 0)
