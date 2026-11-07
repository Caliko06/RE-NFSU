#!/usr/bin/env python3
"""The /goal tracker, from maxpayne-re: out/goal/goal.json is the truth (blocks -> phases -> steps -> evidence), out/goal/goal.html is rendered from it.

  tools/goal.py                       render only
  tools/goal.py set F1.2 status=done evidence="out/goal/p0/native.log: ctl 1 at 212 s" commit=abc123 calls=8
  tools/goal.py add F1 F1.4 "Cables break -> End_Credits"
  tools/goal.py note "free text milestone"
  tools/goal.py check                 reconcile: commits on HEAD, evidence files exist, every docs/GOAL.md gap row has a step

status: todo | doing | done | blocked | cut.  proof: ruta (injected run) | jugado (the OWNER played it) | - .
The page embeds the JSON (Agencia serves files in a sandbox, so it cannot fetch) and reloads itself every 20 s.
"""
import html, json, os, re, subprocess, sys, time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
J = os.path.join(ROOT, "out/goal/goal.json")
H = os.path.join(ROOT, "out/goal/goal.html")
now = lambda: time.strftime("%Y-%m-%d %H:%M")


def find(g, sid):
    for d in g.get("decisions", []):
        if d["id"] == sid: return d
    for p in g["phases"]:
        if p["id"] == sid: return p
        for s in p["steps"]:
            if s["id"] == sid: return s
    sys.exit(f"goal.py: no id {sid}")


def phase_status(p):
    st = [s["status"] for s in p["steps"] if s["status"] != "cut"]
    if not st: return "cut" if p["steps"] else "todo"
    if all(x == "done" for x in st): return "done"
    if "blocked" in st: return "blocked"
    return "doing" if any(x in ("doing", "done") for x in st) else "todo"


def check(g):
    """Written into the JSON; the page shows it. A done step needs evidence that resolves."""
    bad, git = [], lambda *a: subprocess.run(["git", "-C", ROOT, *a], capture_output=True, text=True)
    steps = [s for p in g["phases"] for s in p["steps"]]
    for s in steps:
        if not s.get("done_when"): bad.append(f'{s["id"]}: sin criterio')
        if s["status"] != "done": continue
        if not s.get("evidence") and not s.get("commit"): bad.append(f'{s["id"]}: hecho sin evidencia')
        for c in str(s.get("commit") or "").split():
            if git("merge-base", "--is-ancestor", c, "HEAD").returncode: bad.append(f'{s["id"]}: commit {c} no esta en HEAD')
        f = str(s.get("evidence") or "").split(":")[0]
        if "/" in f and " " not in f and not os.path.exists(os.path.join(ROOT, f)): bad.append(f'{s["id"]}: no existe {f}')
    table = open(ROOT + "/docs/GOAL.md").read().split("## Original gap list")[1].split("\n## ")[0]
    for n, state in re.findall(r"^\| (\d+) \|[^|]*\| (\w+)", table, re.M):
        mine = [s for s in steps if str(s.get("gap")) == n]
        if not mine: bad.append(f"GOAL fila {n} ({state}) sin paso")
        elif (state == "FIXED") != all(s["status"] == "done" for s in mine): bad.append(f"GOAL fila {n} dice {state} y sus pasos no coinciden")
    for b in g.get("blocks", []):
        used = sum(s.get("calls", 0) for p in g["phases"] if p.get("block") == b["id"] for s in p["steps"])
        if used > b.get("cap", 0): bad.append(f'{b["id"]}: {used} llamadas sobre el tope {b["cap"]}: parar y reportar')
    g["check"] = {"at": now(), "head": git("rev-parse", "--short", "HEAD").stdout.strip(), "problems": bad}
    return bad


def render(g):
    e = lambda s: html.escape(str(s or ""))
    lab = {"todo": "pendiente", "doing": "en curso", "done": "hecho", "blocked": "bloqueado", "cut": "cortado"}
    badge = lambda s: f'<span class="b {s}">{lab.get(s, s)}</span>'
    ph = g["phases"]
    for p in ph: p["status"] = phase_status(p)
    used = sum(s.get("calls", 0) for p in ph for s in p["steps"])
    cap = sum(p.get("cap", 0) for p in ph)
    out = [f"""<!doctype html><html lang="es"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">
<meta http-equiv="refresh" content="20"><title>Goal NFSU</title><style>
:root{{--bg:#fafaf8;--fg:#1d1d1b;--mut:#6b6b66;--line:#ddd9d0;--card:#fff;--ok:#1f7a3a;--run:#1d5fbf;--bad:#b3261e;--cut:#8a8a85}}
@media (prefers-color-scheme:dark){{:root{{--bg:#161615;--fg:#ecebe6;--mut:#a3a29b;--line:#3a3935;--card:#1f1f1d;--ok:#5fc27e;--run:#7aa7f0;--bad:#f28b82;--cut:#77766f}}}}
body{{margin:0;background:var(--bg);color:var(--fg);font:15px/1.45 -apple-system,system-ui,sans-serif}}
main{{max-width:1200px;margin:0 auto;padding:20px 16px 40px}}h1{{font-size:21px;margin:0}}h2{{font-size:16px;margin:24px 0 6px}}
.sub{{color:var(--mut);margin:2px 0 14px}}.wrap{{overflow-x:auto}}
table{{border-collapse:collapse;background:var(--card);font-size:14px;min-width:100%}}
th,td{{border:1px solid var(--line);padding:7px 9px;vertical-align:top;text-align:left;min-width:120px}}
td:first-child{{color:var(--mut);min-width:80px;white-space:nowrap}}code{{font-size:12.5px}}
.b{{font-weight:600}}.done{{color:var(--ok)}}.doing{{color:var(--run)}}.blocked{{color:var(--bad)}}.cut{{color:var(--cut);text-decoration:line-through}}.todo{{color:var(--mut)}}
</style></head><body><main>
<h1>/goal: {e(g['goal'])}</h1><p class="sub">Actualizado {e(g.get('updated'))} · llamadas {used} de {cap} · se recarga cada 20 s · verdad: <code>out/goal/goal.json</code></p>"""]
    c = g.get("check")
    if c: out.append(f'<p class="sub">Reconciliado {e(c["at"])} en <code>{e(c["head"])}</code>: ' + ("sin problemas" if not c["problems"] else f'<b class="blocked">{len(c["problems"])} problemas</b>: ' + e("; ".join(c["problems"]))) + "</p>")
    # Blocks, horizontal: the top of the hierarchy.
    bs = g.get("blocks", [])
    of = lambda b: [p for p in ph if p.get("block") == b["id"]]
    brows = [("Estado", lambda b: badge(phase_status({"steps": [s for p in of(b) for s in p["steps"]]}))),
             ("Pasos", lambda b: f'{sum(s["status"] == "done" for p in of(b) for s in p["steps"])} / {sum(s["status"] != "cut" for p in of(b) for s in p["steps"])}'),
             ("Llamadas", lambda b: f'{sum(s.get("calls", 0) for p in of(b) for s in p["steps"])} / {b.get("cap", "-")}'),
             ("Confianza", lambda b: e(b.get("conf", "-"))), ("Termina cuando", lambda b: e(b.get("done_when")))]
    out.append('<h2>Bloques</h2><div class="wrap"><table><tr><th></th>' + "".join(f'<th>{e(b["id"])} · {e(b["title"])}</th>' for b in bs) + "</tr>")
    for name, f in brows: out.append(f"<tr><td>{name}</td>" + "".join(f"<td>{f(b)}</td>" for b in bs) + "</tr>")
    out.append("</table></div>")
    ds = g.get("decisions", [])
    if ds:
        out.append('<h2>Tus decisiones</h2><div class="wrap"><table><tr><th></th>' + "".join(f'<th>{e(d["id"])} · {e(d["q"])}</th>' for d in ds) + "</tr>")
        for name, k in (("Estado", "state"), ("Recomiendo", "rec"), ("Por qué", "why")): out.append(f"<tr><td>{name}</td>" + "".join(f"<td>{e(d.get(k))}</td>" for d in ds) + "</tr>")
        out.append("</table></div>")
    # Phases, horizontal: one column per phase.
    rows = [("Estado", lambda p: badge(p["status"])),
            ("Pasos", lambda p: f'{sum(s["status"] == "done" for s in p["steps"])} / {sum(s["status"] != "cut" for s in p["steps"])}'),
            ("Llamadas", lambda p: f'{sum(s.get("calls", 0) for s in p["steps"])} / {p.get("cap", "-")}'),
            ("Confianza", lambda p: e(p.get("conf", "-"))), ("Termina cuando", lambda p: e(p.get("done_when")))]
    out.append('<h2>Fases</h2><div class="wrap"><table><tr><th></th>' + "".join(f'<th>{e(p["id"])} · {e(p["title"])}</th>' for p in ph) + "</tr>")
    for name, f in rows: out.append(f"<tr><td>{name}</td>" + "".join(f"<td>{f(p)}</td>" for p in ph) + "</tr>")
    out.append("</table></div>")
    # Milestones: done steps and notes, newest first, horizontal.
    ms = [(s.get("done_at", ""), s["id"], s["title"]) for p in ph for s in p["steps"] if s["status"] == "done"]
    ms += [(n["at"], "nota", n["text"]) for n in g.get("notes", [])]
    ms.sort(reverse=True)
    if ms:
        out.append('<h2>Hitos (lo más nuevo a la izquierda)</h2><div class="wrap"><table><tr><td>Cuándo</td>' + "".join(f"<td>{e(a)}</td>" for a, _, _ in ms[:8]) + "</tr>")
        out.append("<tr><td>Qué</td>" + "".join(f"<td><b>{e(i)}</b> {e(t)}</td>" for _, i, t in ms[:8]) + "</tr></table></div>")
    # Each phase: steps as columns.
    srows = [("Estado", lambda s: badge(s["status"])), ("Quién", lambda s: e(s.get("who"))), ("Pasa si", lambda s: e(s.get("done_when"))), ("Se sabe", lambda s: e(s.get("known"))),
             ("Fila GOAL", lambda s: e(s.get("gap"))), ("Necesita", lambda s: e(s.get("needs"))), ("Prueba", lambda s: e(s.get("proof", "-"))),
             ("Evidencia", lambda s: f'<code>{e(s.get("evidence"))}</code>'), ("Commit", lambda s: f'<code>{e(s.get("commit"))}</code>'),
             ("Llamadas", lambda s: e(s.get("calls", 0)))]
    for p in ph:
        if not p["steps"]: continue
        out.append(f'<h2>{e(p["id"])} · {e(p["title"])} {badge(p["status"])}</h2><div class="wrap"><table><tr><th></th>'
                   + "".join(f'<th>{e(s["id"])} · {e(s["title"])}</th>' for s in p["steps"]) + "</tr>")
        for name, f in srows: out.append(f"<tr><td>{name}</td>" + "".join(f"<td>{f(s)}</td>" for s in p["steps"]) + "</tr>")
        out.append("</table></div>")
    out.append("</main></body></html>")
    open(H, "w").write("\n".join(out))


def main(a):
    g = json.load(open(J))
    if a and a[0] == "set":
        s = find(g, a[1])
        for kv in a[2:]:
            k, v = kv.split("=", 1)
            s[k] = int(v) if k == "calls" else v
        if s.get("status") == "done" and not s.get("evidence") and not s.get("commit"): sys.exit(f"goal.py: {a[1]} no se marca hecho sin evidence= o commit=")
        if s.get("status") == "done" and not s.get("done_at"): s["done_at"] = now()
    elif a and a[0] == "add":
        find(g, a[1])["steps"].append({"id": a[2], "title": a[3], "status": "todo"})
    elif a and a[0] == "note":
        g.setdefault("notes", []).append({"at": now(), "text": a[1]})
    if a and a[0] == "check": print("\n".join(check(g)) or "sin problemas")
    if a: g["updated"] = now(); json.dump(g, open(J, "w"), ensure_ascii=False, indent=1)
    render(g)
    print(H)


if __name__ == "__main__":
    main(sys.argv[1:])
