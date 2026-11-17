#!/usr/bin/env python3
"""Plain static server for dist/: files, Range, COOP/COEP/CORP headers, nothing else (no /log, /save, /plan). Test stand-in for a real host.
Usage: python3 tools/static_server.py [port=5181] [dir=dist]
RN_RTT_MS=80: every answer waits that long first, the round trip of a real visit (live 2026-11-16: 75 ms a request; localhost hides it)."""
import functools, http.server, os, re, sys, time

RTT = float(os.environ.get("RN_RTT_MS", 0)) / 1000

PORT = int(sys.argv[1]) if len(sys.argv) > 1 else 5181
DIR = os.path.abspath(sys.argv[2] if len(sys.argv) > 2 else os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "dist"))


class H(http.server.SimpleHTTPRequestHandler):
    protocol_version = "HTTP/1.1"
    extensions_map = {**http.server.SimpleHTTPRequestHandler.extensions_map, ".wasm": "application/wasm", ".js": "text/javascript"}

    def end_headers(self):
        self.send_header("Cross-Origin-Opener-Policy", "same-origin")
        self.send_header("Cross-Origin-Embedder-Policy", "require-corp")
        self.send_header("Cross-Origin-Resource-Policy", "same-origin")
        super().end_headers()

    def do_GET(self):
        path = self.translate_path(self.path)
        if RTT:
            time.sleep(RTT)
        m = re.fullmatch(r"bytes=(\d+)-(\d*)", self.headers.get("Range", ""))
        if m and os.path.isfile(path):
            size = os.path.getsize(path)
            a, b = int(m[1]), min(int(m[2]) if m[2] else size - 1, size - 1)
            if a >= size or b < a:
                self.send_response(416); self.send_header("Content-Range", f"bytes */{size}"); self.send_header("Content-Length", "0"); self.end_headers()
                return
            with open(path, "rb") as f:
                f.seek(a); body = f.read(b - a + 1)
            self.send_response(206)
            self.send_header("Content-Type", "application/octet-stream")
            self.send_header("Content-Range", f"bytes {a}-{b}/{size}")
            self.send_header("Content-Length", str(len(body)))
            self.end_headers(); self.wfile.write(body)
            return
        super().do_GET()

    def log_message(self, *a):
        pass


http.server.ThreadingHTTPServer(("127.0.0.1", PORT), functools.partial(H, directory=DIR)).serve_forever()
