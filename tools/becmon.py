#!/usr/bin/env python3
"""Becario monitor for the OWNER: http://localhost:5180/becarios (tools/serve.py). Asks and answers come from TokenTok's becarios/cola.db, read only.
What Main did with each answer is in tools/becmon_use.tsv (job id, used|partial|rejected|pending, note), written by Main."""
import glob, html, json, os, sqlite3, time

T = os.path.expanduser("~/Dashboards/tokentok/becarios")
USE = os.path.join(os.path.dirname(os.path.abspath(__file__)), "becmon_use.tsv")
LABEL = {"used": "usado", "partial": "en parte", "rejected": "descartado", "pending": "sin usar aún"}
STATE = {"q": "en cola", "run": "trabajando", "ok": "respondió", "err": "falló"}


def clock(t):
    return time.strftime("%H:%M", time.localtime(t)) if t else ""


def uses():
    out = {}
    if os.path.exists(USE):
        for line in open(USE, encoding="utf8"):
            p = line.rstrip("\n").split("\t")
            if len(p) == 3:
                out[p[0]] = p[1:]
    return out


def workers(c):
    rows = []
    for f in sorted(glob.glob(T + "/*/state.json")):
        n = os.path.basename(os.path.dirname(f))
        try:
            j = json.load(open(f)).get("job")
        except (OSError, ValueError):
            continue
        if j:
            rows.append((n, j.get("repo") or "", j.get("text") or ""))
    return rows


def page():
    c = sqlite3.connect(f"file:{T}/cola.db?mode=ro", uri=True)
    day = time.time() - 12 * 3600
    jobs = c.execute("select id,who,status,ts,started,ended,text,reply from jobs where repo like '%RE-NFSU%' and ts>? order by ts desc", (day,)).fetchall()
    use, e = uses(), html.escape
    done = sum(j[2] == "ok" for j in jobs)
    live = [j for j in jobs if j[2] not in ("ok", "err")]
    used = sum(use.get(j[0], ["pending"])[0] in ("used", "partial") for j in jobs)
    rows = []
    for jid, who, st, ts, started, ended, text, reply in jobs:
        u, note = use.get(jid, ["pending", "Main aún no la revisa" if st == "ok" else ""])
        mins = f"{(ended - started) / 60:.0f} min" if ended and started else ""
        rows.append(f"<tr><td class=n>{e(who or '-')}</td><td>{clock(ts)}</td><td class='s {e(st)}'>{STATE.get(st, e(st))}<small>{clock(ended)} {mins}</small></td>"
                    f"<td><details><summary>{e(text[:110])}</summary><pre>{e(text)}</pre></details></td>"
                    f"<td><details><summary>{e((reply or '').strip()[:110])}</summary><pre>{e(reply or '')}</pre></details></td>"
                    f"<td class='u {u}'>{LABEL.get(u, e(u))}<small>{e(note)}</small></td></tr>")
    other = "".join(f"<li><b>{e(n)}</b> {e(os.path.basename(r.rstrip('/')))}: {e(t[:90])}</li>" for n, r, t in workers(c) if "RE-NFSU" not in r)
    return (f"""<!doctype html><meta charset=utf-8><meta http-equiv=refresh content=15><title>Becarios NFSU</title><style>
body{{font:14px system-ui;margin:24px;background:#111;color:#ddd}}h1{{font-size:20px;margin:0 0 4px}}p{{color:#999;margin:0 0 16px}}
table{{border-collapse:collapse;width:100%}}td,th{{border-bottom:1px solid #333;padding:7px 9px;text-align:left;vertical-align:top}}th{{color:#888;font-weight:500}}
small{{display:block;color:#888;font-weight:400;margin-top:2px}}.n{{font-weight:600}}pre{{white-space:pre-wrap;font:12px ui-monospace,monospace;color:#bbb;max-width:560px}}
summary{{cursor:pointer}}.ok{{color:#6c6}}.err{{color:#e66}}.run,.q{{color:#ec5}}.used{{color:#6c6}}.partial{{color:#8bd}}.rejected{{color:#e88}}.pending{{color:#ec5}}li{{color:#999;margin:2px 0}}
</style><h1>Becarios en NFSU</h1><p>{len(jobs)} pedidos en 12 h · {done} respondidos · {len(live)} activos · {used} aprovechados por Main · se actualiza cada 15 s, {time.strftime('%H:%M:%S')}</p>
<table><tr><th>Becario</th><th>Pedido</th><th>Estado</th><th>Qué le pedí</th><th>Qué respondió</th><th>Qué hice con eso</th></tr>{''.join(rows)}</table>"""
            + (f"<h1 style='margin-top:24px;font-size:15px'>Ocupados en otros repos</h1><ul>{other}</ul>" if other else "")).encode()
