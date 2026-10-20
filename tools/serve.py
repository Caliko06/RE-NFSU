#!/usr/bin/env python3
"""Local web server for the browser build on 127.0.0.1:5180 (COOP/COEP for SharedArrayBuffer).

/ -> web/, /pc/Speed.exe -> pc/Speed.exe, /game/... -> game/ (the OWNER's files, never leave this machine).
/game-files.json lists game/ (relative paths and sizes); /game/ answers Range requests (host/files.c reads them).
/save/... = save/ of this repo (gitignored): what the game writes. GET reads, PUT writes a whole file, DELETE
removes one; /save-files.json lists save/. Writes never reach game/.
Usage: .venv/bin/python tools/serve.py [port]
"""
import http.server, json, os, sys, urllib.parse

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PORT = int(sys.argv[1]) if len(sys.argv) > 1 else 5180


SAVE = os.path.join(ROOT, "save")


def save_path(url):
    """save/<rel> for /save/<rel>, or None when it would leave save/."""
    rel = os.path.normpath(urllib.parse.unquote(url.split("?", 1)[0][len("/save/"):]))
    if rel.startswith("..") or os.path.isabs(rel) or rel == ".":
        return None
    return os.path.join(SAVE, rel)


def listing(top):
    files = []
    for d, _, names in os.walk(top, followlinks=True):
        for n in names:
            p = os.path.join(d, n)
            files.append([os.path.relpath(p, top), os.path.getsize(p)])
    return json.dumps(sorted(files)).encode()


class Handler(http.server.SimpleHTTPRequestHandler):
    def do_PUT(self):
        p = save_path(self.path) if self.path.startswith("/save/") else None
        if not p:
            self.send_error(403)
            return
        body = self.rfile.read(int(self.headers.get("Content-Length", 0)))
        os.makedirs(os.path.dirname(p), exist_ok=True)
        with open(p + ".tmp", "wb") as f:
            f.write(body)
        os.replace(p + ".tmp", p)
        self.send_response(204)
        self.end_headers()

    def do_DELETE(self):
        p = save_path(self.path) if self.path.startswith("/save/") else None
        if not p or not os.path.isfile(p):
            self.send_error(404)
            return
        os.remove(p)
        self.send_response(204)
        self.end_headers()

    def do_GET(self):
        route = self.path.split("?", 1)[0]
        if route in ("/game-files.json", "/save-files.json"):
            top = os.path.join(ROOT, "game") if route == "/game-files.json" else SAVE
            body = listing(top) if os.path.isdir(top) else b"[]"
            self.send_response(200)
            self.send_header("Content-Type", "application/json")
            self.send_header("Content-Length", str(len(body)))
            self.end_headers()
            self.wfile.write(body)
            return
        rng = self.headers.get("Range")
        path = self.translate_path(self.path)
        if rng and rng.startswith("bytes=") and os.path.isfile(path):    # the game thread reads byte ranges
            size = os.path.getsize(path)
            a, b = rng[6:].split("-")
            a, b = int(a), min(int(b) if b else size - 1, size - 1)
            if a >= size or b < a:
                self.send_response(416)
                self.send_header("Content-Range", f"bytes */{size}")
                self.end_headers()
                return
            with open(path, "rb") as f:
                f.seek(a)
                body = f.read(b - a + 1)
            self.send_response(206)
            self.send_header("Content-Type", "application/octet-stream")
            self.send_header("Content-Range", f"bytes {a}-{b}/{size}")
            self.send_header("Content-Length", str(len(body)))
            self.end_headers()
            self.wfile.write(body)
            return
        super().do_GET()

    def translate_path(self, path):
        path = path.split("?", 1)[0].split("#", 1)[0]
        if path == "/pc/Speed.exe":
            return os.path.join(ROOT, "pc", "Speed.exe")
        if path.startswith("/game/"):
            return os.path.join(ROOT, "game", os.path.normpath(path[6:]).lstrip("/."))
        if path.startswith("/save/"):
            return save_path(path) or os.path.join(SAVE, "..refused")
        return os.path.join(ROOT, "web", os.path.normpath(path).lstrip("/."))

    def end_headers(self):
        self.send_header("Cross-Origin-Opener-Policy", "same-origin")
        self.send_header("Cross-Origin-Embedder-Policy", "require-corp")
        self.send_header("Cache-Control", "no-store")
        super().end_headers()

    def log_message(self, *a):
        pass


Handler.extensions_map = {**Handler.extensions_map, ".wasm": "application/wasm", ".js": "text/javascript"}
http.server.ThreadingHTTPServer(("127.0.0.1", PORT), Handler).serve_forever()
