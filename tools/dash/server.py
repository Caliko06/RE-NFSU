#!/usr/bin/env python3
"""Progress dashboard for the NFSU Open World + cars block. Read-only, 127.0.0.1 only.
usage: python3 tools/dash/server.py [port]   (default 8780)
Windows: sessions (Claude transcripts), openworld (handling A/B + traffic lines), shots (A/B captures), re (REA/Hopper/Ghidra calls), git."""
import glob, hashlib, json, math, os, re, subprocess, sys, threading, time
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from urllib.parse import parse_qs, urlparse

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
PROJ = os.path.expanduser("~/.claude/projects/-Users-angeldamian-RE-NFSU")
SESS = glob.glob(os.path.expanduser("~/.claude-profiles/*/sessions/*.json"))
CACHE = f"{ROOT}/build/dash_cache"
WINDOW = 12 * 3600
READ_ONLY = {"grep", "ls", "du", "head", "tail", "sed", "cat", "ps", "wc", "rg", "echo", "cd", "find", "git"}
RE_CMDS = ("hpar.sh", "ghidra", "DecompAt", "XrefsAt", "ExportRange", "mkq.py", "difftest.py", "export.sh")

_files, _lock = {}, threading.Lock()   # path -> incremental parse state


def short(s, n=140):
    return " ".join(str(s).split())[:n]


def parse_file(path):
    """Incremental: read only the bytes added since last call."""
    st = _files.setdefault(path, {"off": 0, "tools": 0, "last_text": "", "last_tool": "", "last_ts": "", "title": "", "re": []})
    size = os.path.getsize(path)
    if size < st["off"]:
        st.update(off=0, tools=0, re=[])
    with open(path, "rb") as f:
        f.seek(st["off"])
        data = f.read()
    cut = data.rfind(b"\n") + 1          # only whole lines; a half-written line waits for the next call
    st["off"] += cut
    for line in data[:cut].split(b"\n"):
        try:
            d = json.loads(line)
        except Exception:
            continue
        msg, ts = d.get("message") or {}, d.get("timestamp", "")
        c = msg.get("content")
        if d.get("type") == "user" and not st["title"] and isinstance(c, str) and not c.startswith("<"):
            st["title"] = short(c, 90)
        if d.get("type") != "assistant" or not isinstance(c, list):
            continue
        for b in c:
            if b.get("type") == "text" and b["text"].strip():
                st["last_text"], st["last_ts"] = short(b["text"], 260), ts
            elif b.get("type") == "tool_use":
                st["tools"] += 1
                inp = b.get("input") or {}
                arg = inp.get("command") or inp.get("description") or inp.get("file_path") or json.dumps(inp)
                st["last_tool"], st["last_ts"] = f'{b["name"]}  {short(arg, 110)}', ts
                cmd = inp.get("command", "").split("\n")[0] if b["name"] == "Bash" else ""   # first line: a heredoc that only mentions a tool is not a call
                if b["name"].startswith("mcp__rea__") or runs_re(cmd):
                    st["re"].append({"ts": ts, "tool": b["name"], "arg": short(arg, 150)})
                    del st["re"][:-300]
    return st


def runs_re(cmd):
    """True when a shell segment of the command runs an RE tool (not a grep/ls/sed that only mentions its name)."""
    cmd = re.sub(r"'[^']*'|\"[^\"]*\"", "''", cmd)
    for seg in re.split(r"&&|\|\||[;|]", cmd):
        w = seg.split()
        w = [x for x in w if "=" not in x or x.startswith("-")]      # drop VAR=value prefixes
        if w and w[0] not in READ_ONLY and any(k in seg for k in RE_CMDS):
            return True
    return False


def names():
    out = {}
    for f in SESS:
        try:
            d = json.load(open(f))
            out[d["sessionId"]] = {"name": d.get("name", ""), "status": d.get("status", ""), "pid": d["pid"]}
        except Exception:
            pass
    return out


def sessions():
    nm, out, now = names(), [], time.time()
    seen = set()
    for f in sorted(glob.glob(PROJ + "/*.jsonl"), key=os.path.getmtime, reverse=True):
        rp = os.path.realpath(f)
        if rp in seen or now - os.path.getmtime(f) > WINDOW:
            continue
        seen.add(rp)
        sid = os.path.basename(f)[:-6]
        st = parse_file(f)
        subs = glob.glob(f"{PROJ}/{sid}/subagents/agent-*.jsonl")
        sub_age = min([now - os.path.getmtime(x) for x in subs] or [1e9])
        out.append({"id": sid[:8], "name": nm.get(sid, {}).get("name", ""), "title": st["title"], "age": int(now - os.path.getmtime(f)),
                    "tools": st["tools"], "subs": len(subs), "subs_live": sub_age < 300, "text": st["last_text"], "tool": st["last_tool"]})
    # a session with only a work directory (no main transcript yet, e.g. nfsu-c4): show it from its subagents
    for d in glob.glob(PROJ + "/*/subagents"):
        sid = os.path.basename(os.path.dirname(d))
        if not os.path.exists(f"{PROJ}/{sid}.jsonl"):
            subs = glob.glob(d + "/agent-*.jsonl")
            age = min([now - os.path.getmtime(x) for x in subs] or [1e9])
            if age < WINDOW:
                out.append({"id": sid[:8], "name": nm.get(sid, {}).get("name", ""), "title": "(sin transcript principal; solo subagentes)",
                            "age": int(age), "tools": 0, "subs": len(subs), "subs_live": age < 300, "text": "", "tool": ""})
    for sid, n in nm.items():     # a live peer with no transcript on disk (e.g. nfsu-c4): show it from its session file
        if not any(r["id"] == sid[:8] for r in out) and n["name"] and subprocess.run(["kill", "-0", str(n["pid"])], capture_output=True).returncode == 0:
            out.append({"id": sid[:8], "name": n["name"], "title": "(sin transcript en disco; vivo por su archivo de sesión)", "age": 0, "tools": 0,
                        "subs": 0, "subs_live": False, "text": "", "tool": ""})
    return out


def re_calls():
    rows = []
    for f in glob.glob(PROJ + "/*.jsonl"):
        if time.time() - os.path.getmtime(f) < WINDOW:
            sid = os.path.basename(f)[:8]
            rows += [dict(r, sid=sid) for r in parse_file(f)["re"]]
    rows.sort(key=lambda r: r["ts"], reverse=True)
    kinds = {}
    for r in rows:
        a = r["arg"]
        k = "REA" if r["tool"].startswith("mcp__rea__") else "Hopper" if "hpar" in a or "q_" in a else "Ghidra" if "hidra" in a or "DecompAt" in a else "difftest" if "difftest" in a else "otro"
        r["kind"] = k
        kinds[k] = kinds.get(k, 0) + 1
    return {"counts": kinds, "rows": rows[:60]}


def pct(v, p):
    return round(sorted(v)[min(len(v) - 1, int(len(v) * p))], 3) if v else 0


def handling():
    out = []
    for lg in sorted(glob.glob(f"{ROOT}/build/openworld/handling_ab/run_*/log.txt")):
        rows = []
        for ln in open(lg, errors="ignore"):
            if ln.startswith("BODY "):
                p = ln.split()
                try:
                    rows.append((int(p[1]), float(p[2]), float(p[3]), float(p[4])))
                except (ValueError, IndexError):
                    pass
        v = [math.hypot(rows[i][1] - rows[i - 1][1], rows[i][2] - rows[i - 1][2]) * 60 for i in range(1, len(rows))]
        jz = [abs(rows[i][3] - 2 * rows[i - 1][3] + rows[i - 2][3]) for i in range(2, len(rows)) if rows[i][0] - rows[i - 2][0] == 2 and 8 < v[i - 1] < 150]
        out.append({"run": lg.split("/")[-2][4:], "frames": len(rows), "dist": round(sum(v) / 60), "z_jitter_p50": pct(jz, .5), "z_jitter_p95": pct(jz, .95),
                    "mtime": int(os.path.getmtime(lg))})
    return out


def tails(pattern, n=6):
    out = []
    for f in sorted(glob.glob(f"{ROOT}/{pattern}"), key=os.path.getmtime, reverse=True)[:n]:
        out.append({"file": os.path.relpath(f, ROOT), "age": int(time.time() - os.path.getmtime(f)),
                    "tail": short(subprocess.run(["tail", "-c", "300", f], capture_output=True, text=True).stdout, 300)})
    return out


def shots():
    exts = (".png", ".webp", ".jpg")
    fs = []
    for pat in ("build/carlook/carvol/*", "build/carlook/baseline_*/*", "build/shots_cars/*", "build/carao/*", "build/openworld/*"):
        fs += [f for f in glob.glob(f"{ROOT}/{pat}") if f.lower().endswith(exts)]
    fs.sort(key=os.path.getmtime, reverse=True)
    return [{"p": os.path.relpath(f, ROOT), "age": int(time.time() - os.path.getmtime(f)), "ab": "_vs_" in f or "strip" in f or "sheet" in f}
            for f in fs[:60]]


def git():
    r = subprocess.run(["git", "-C", ROOT, "log", "-12", "--format=%h|%cr|%s"], capture_output=True, text=True).stdout
    dirty = subprocess.run(["git", "-C", ROOT, "status", "--short"], capture_output=True, text=True).stdout.count("\n")
    return {"commits": [dict(zip("h t s".split(), ln.split("|", 2))) for ln in r.splitlines()], "dirty": dirty}


def state():
    with _lock:
        return {"now": int(time.time()), "sessions": sessions(), "re": re_calls(), "handling": handling(), "git": git(), "shots": shots(),
                "webcheck": tails("build/webcheck.log", 1), "handoff": open(f"{ROOT}/HANDOFF.md", errors="ignore").read()[:2600], "logs": tails("build/openworld/*.md", 4)}


def thumb(rel, w):
    src = os.path.realpath(f"{ROOT}/{rel}")
    if not src.startswith(ROOT + "/build/") or not src.lower().endswith((".png", ".jpg", ".webp")):
        return None
    os.makedirs(CACHE, exist_ok=True)
    dst = f"{CACHE}/{hashlib.md5(f'{src}{w}{os.path.getmtime(src)}'.encode()).hexdigest()}.png"
    if not os.path.exists(dst):
        subprocess.run(["sips", "-Z", str(w), "-s", "format", "png", src, "--out", dst], capture_output=True)
    return dst if os.path.exists(dst) else None


class H(BaseHTTPRequestHandler):
    def log_message(self, *a):
        pass

    def send(self, code, body, ctype):
        self.send_response(code)
        self.send_header("Content-Type", ctype)
        self.send_header("Cache-Control", "no-store")
        self.end_headers()
        self.wfile.write(body)

    def do_GET(self):
        u = urlparse(self.path)
        q = parse_qs(u.query)
        if u.path == "/":
            return self.send(200, open(f"{HERE}/index.html", "rb").read(), "text/html; charset=utf-8")
        if u.path == "/api/state":
            return self.send(200, json.dumps(state()).encode(), "application/json")
        if u.path == "/thumb":
            f = thumb(q.get("p", [""])[0], int(q.get("w", ["900"])[0]))
            return self.send(200, open(f, "rb").read(), "image/png") if f else self.send(404, b"", "text/plain")
        self.send(404, b"", "text/plain")


if __name__ == "__main__":
    port = int(sys.argv[1]) if len(sys.argv) > 1 else 8780
    print(f"dash http://127.0.0.1:{port}/", flush=True)
    ThreadingHTTPServer(("127.0.0.1", port), H).serve_forever()
