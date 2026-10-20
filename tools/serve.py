#!/usr/bin/env python3
"""Local web server for the browser build on 127.0.0.1:5180 (COOP/COEP for SharedArrayBuffer).

/ -> web/, /pc/Speed.exe -> pc/Speed.exe, /game/... -> game/ (the OWNER's files, never leave this machine).
/game-files.json lists game/ (relative paths and sizes) so the page can load it.
Usage: .venv/bin/python tools/serve.py [port]
"""
import http.server, json, os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PORT = int(sys.argv[1]) if len(sys.argv) > 1 else 5180


class Handler(http.server.SimpleHTTPRequestHandler):
    def do_GET(self):
        if self.path.split("?", 1)[0] == "/game-files.json":
            game = os.path.join(ROOT, "game")
            files = []
            for d, _, names in os.walk(game, followlinks=True):
                for n in names:
                    p = os.path.join(d, n)
                    files.append([os.path.relpath(p, game), os.path.getsize(p)])
            body = json.dumps(sorted(files)).encode()
            self.send_response(200)
            self.send_header("Content-Type", "application/json")
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
