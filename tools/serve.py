#!/usr/bin/env python3
"""Local web server for the browser build on 127.0.0.1:5180 (COOP/COEP for SharedArrayBuffer).

/ -> web/, /pc/Speed.exe -> pc/Speed.exe, /game/... -> game/ (the OWNER's files, never leave this machine).
/game-files.json lists game/ (relative paths and sizes); /game/ answers Range requests (host/files.c reads them).
/save/... = save/ of this repo (gitignored): what the game writes. GET reads, PUT writes a whole file, DELETE
removes one; /save-files.json lists save/. Writes never reach game/. Headless Chrome (tests) gets build/save-headless
instead, a copy of save/ made when it is missing (webcheck deletes it at start), so a test never changes the OWNER's save.
POST /log appends the page's log to build/web.log (POST /log?new starts it again; the last one is kept as
build/web.prev.log), so a Chrome session can be read after it stops. Headless Chrome (tools/webcheck.mjs) writes
build/webcheck.log instead, so a test never replaces the OWNER's session.
POST /telemetry does the same for web/telemetry.js: build/telemetry.ndjson (build/webcheck.telemetry.ndjson).
--lan also serves HTTPS on 0.0.0.0:5443 for a phone or tablet on the same Wi-Fi (SAB and WebGPU need a secure
context; only localhost is exempt). The certificate comes from a local CA in build/lan-cert/ (made once with openssl;
the Mac keychain is not touched). The phone trusts it once: open https://<mac>.local:5443/lan-ca.crt, install the
profile, then Settings > General > About > Certificate Trust Settings > full trust (iOS); Android: Settings > Security
> Install a certificate > CA. The leaf certificate is remade when the Mac's LAN address changes.
Usage: .venv/bin/python tools/serve.py [port] [--lan]
"""
import email.utils, gzip, http.server, json, os, shutil, socket, ssl, subprocess, sys, threading, urllib.parse

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ARGS = [a for a in sys.argv[1:] if a != "--lan"]
LAN = "--lan" in sys.argv
PORT = int(ARGS[0]) if ARGS else 5180
LAN_PORT = 5443
CERT = os.path.join(ROOT, "build", "lan-cert")
WORLD_DIR = os.path.join(ROOT, os.environ.get("RN_WORLD_DIR") or "build/openworld")


SAVE = os.path.join(ROOT, "save")
SAVE_HEADLESS = os.path.join(ROOT, "build", "save-headless")


def save_root(headers):
    if "HeadlessChrome" not in headers.get("User-Agent", ""):
        return SAVE
    if not os.path.isdir(SAVE_HEADLESS):
        shutil.copytree(SAVE, SAVE_HEADLESS) if os.path.isdir(SAVE) else os.makedirs(SAVE_HEADLESS)
    return SAVE_HEADLESS


def save_path(url, root):
    """<root>/<rel> for /save/<rel>, or None when it would leave the save root."""
    rel = os.path.normpath(urllib.parse.unquote(url.split("?", 1)[0][len("/save/"):]))
    if rel.startswith("..") or os.path.isabs(rel) or rel == ".":
        return None
    return os.path.join(root, rel)


def listing(top):
    files = []
    for d, _, names in os.walk(top, followlinks=True):
        for n in names:
            p = os.path.join(d, n)
            files.append([os.path.relpath(p, top), os.path.getsize(p)])
    return json.dumps(sorted(files)).encode()


class Handler(http.server.SimpleHTTPRequestHandler):
    def do_PUT(self):
        p = save_path(self.path, save_root(self.headers)) if self.path.startswith("/save/") else None
        if not p:
            self.send_error(403)
            return
        body = self.rfile.read(int(self.headers.get("Content-Length", 0)))
        if self.path.endswith("/"):         # PUT /save/dir/ makes a directory (CreateDirectoryA)
            os.makedirs(p, exist_ok=True)
            self.send_response(204)
            self.end_headers()
            return
        os.makedirs(os.path.dirname(p), exist_ok=True)
        with open(p + ".tmp", "wb") as f:
            f.write(body)
        os.replace(p + ".tmp", p)
        self.send_response(204)
        self.end_headers()

    def do_POST(self):
        route = self.path.split("?", 1)[0]
        if route not in ("/log", "/telemetry"):
            self.send_error(403)
            return
        body = self.rfile.read(int(self.headers.get("Content-Length", 0)))
        name = "webcheck" if "HeadlessChrome" in self.headers.get("User-Agent", "") else "web"
        # (session file, previous one) for each route and browser
        files = {("/log", "web"): ("web.log", "web.prev.log"), ("/log", "webcheck"): ("webcheck.log", "webcheck.prev.log"),
                 ("/telemetry", "web"): ("telemetry.ndjson", "telemetry.prev.ndjson"),
                 ("/telemetry", "webcheck"): ("webcheck.telemetry.ndjson", "webcheck.telemetry.prev.ndjson")}
        log, prev = (os.path.join(ROOT, "build", f) for f in files[(route, name)])
        if self.path.endswith("?new") and os.path.exists(log):
            os.replace(log, prev)
        with open(log, "ab") as f:
            f.write(body)
        self.send_response(204)
        self.end_headers()

    def do_DELETE(self):
        p = save_path(self.path, save_root(self.headers)) if self.path.startswith("/save/") else None
        if not p or not os.path.isfile(p):
            self.send_error(404)
            return
        os.remove(p)
        self.send_response(204)
        self.end_headers()

    def do_GET(self):
        route = self.path.split("?", 1)[0]
        if route == "/becarios":             # the OWNER's Becario monitor (tools/becmon.py)
            import becmon
            body = becmon.page()
            self.send_response(200)
            self.send_header("Content-Type", "text/html; charset=utf-8")
            self.send_header("Content-Length", str(len(body)))
            self.send_header("Cache-Control", "no-store")
            self.end_headers()
            self.wfile.write(body)
            return
        if route in ("/game-files.json", "/save-files.json"):
            top = os.path.join(ROOT, "game") if route == "/game-files.json" else save_root(self.headers)
            body = listing(top) if os.path.isdir(top) else b"[]"
            self.send_response(200)
            self.send_header("Content-Type", "application/json")
            self.send_header("Content-Length", str(len(body)))
            self.end_headers()
            self.wfile.write(body)
            return
        if route == "/out/speed.wasm" and self.wasm_packed():
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

    def wasm_packed(self):
        """speed.wasm compressed once per build (70 MB -> 12 MB br over HTTPS, 16 MB gzip), revalidated by ETag so a
        reload downloads nothing until the next build. True when it answered."""
        src = os.path.join(ROOT, "web", "out", "speed.wasm")
        acc = self.headers.get("Accept-Encoding", "")
        enc = "br" if "br" in acc and isinstance(self.connection, ssl.SSLSocket) and shutil.which("brotli") else "gzip" if "gzip" in acc else None
        if not enc or not os.path.isfile(src):
            return False
        st = os.stat(src)
        tag = f'"{st.st_mtime_ns:x}-{st.st_size:x}-{enc}"'
        if self.headers.get("If-None-Match") == tag:
            self.send_response(304)
            self.send_header("ETag", tag)
            self.end_headers()
            return True
        out = src + (".br" if enc == "br" else ".gz")
        with PACK_LOCK:
            if not os.path.exists(out) or os.path.getmtime(out) < st.st_mtime:
                if enc == "br":
                    subprocess.run(["brotli", "-q", "9", "-f", "-o", out + ".tmp", src], check=True)
                else:
                    with open(src, "rb") as f, gzip.open(out + ".tmp", "wb", 6) as g:
                        shutil.copyfileobj(f, g, 1 << 20)
                os.replace(out + ".tmp", out)
        self.send_response(200)
        self.send_header("Content-Type", "application/wasm")
        self.send_header("Content-Encoding", enc)
        self.send_header("Content-Length", str(os.path.getsize(out)))
        self.send_header("ETag", tag)
        self.send_header("Vary", "Accept-Encoding")
        self.end_headers()
        with open(out, "rb") as f:
            shutil.copyfileobj(f, self.wfile, 1 << 20)
        return True

    def translate_path(self, path):
        path = path.split("?", 1)[0].split("#", 1)[0]
        if path == "/lan-ca.crt":
            return os.path.join(CERT, "ca.crt")
        if path == "/pc/Speed.exe":
            return os.path.join(ROOT, "pc", "Speed.exe")
        if path.startswith("/game/"):
            return os.path.join(ROOT, "game", os.path.normpath(path[6:]).lstrip("/."))
        if path.startswith("/world/"):    # the open world's merged TRACKB files (tools/openworld/build.py, ?world=1); RN_WORLD_DIR as native
            return os.path.join(WORLD_DIR, os.path.normpath(path[7:]).lstrip("/."))
        if path.startswith("/save/"):
            root = save_root(self.headers)
            return save_path(path, root) or os.path.join(root, "..refused")
        return os.path.join(ROOT, "web", os.path.normpath(path).lstrip("/."))

    def end_headers(self):
        self.send_header("Cross-Origin-Opener-Policy", "same-origin")
        self.send_header("Cross-Origin-Embedder-Policy", "require-corp")
        # Saves and logs change within a second (Last-Modified's grain): never stored. The rest revalidates on each load (304 = no download).
        self.send_header("Cache-Control", "no-store" if self.path.startswith(("/save", "/log", "/telemetry")) else "no-cache")
        super().end_headers()

    def log_message(self, *a):
        pass


def lan_names():
    """(LAN IPv4 or None, mDNS host name such as Angels-Mac-mini.local)."""
    ip = subprocess.run(["ipconfig", "getifaddr", "en0"], capture_output=True, text=True).stdout.strip() or \
        subprocess.run(["ipconfig", "getifaddr", "en1"], capture_output=True, text=True).stdout.strip() or None
    host = subprocess.run(["scutil", "--get", "LocalHostName"], capture_output=True, text=True).stdout.strip() or socket.gethostname()
    return ip, host.removesuffix(".local") + ".local"


def lan_cert(ip, host):
    """build/lan-cert/{ca.crt,ca.key,leaf.crt,leaf.key}; the leaf names host, the IP and localhost."""
    os.makedirs(CERT, exist_ok=True)
    f = lambda n: os.path.join(CERT, n)
    ossl = lambda *a: subprocess.run(["openssl", *a], check=True, capture_output=True)
    if not os.path.exists(f("ca.crt")):
        ossl("req", "-x509", "-newkey", "rsa:2048", "-nodes", "-days", "3650", "-keyout", f("ca.key"), "-out", f("ca.crt"),
             "-subj", "/CN=NFSU local CA", "-addext", "basicConstraints=critical,CA:TRUE", "-addext", "keyUsage=critical,keyCertSign,cRLSign")
    san = f"DNS:{host},DNS:localhost" + (f",IP:{ip}" if ip else "") + ",IP:127.0.0.1"
    old = open(f("leaf.san")).read() if os.path.exists(f("leaf.san")) else None
    if old != san:
        ossl("req", "-newkey", "rsa:2048", "-nodes", "-keyout", f("leaf.key"), "-out", f("leaf.csr"), "-subj", f"/CN={host}")
        with open(f("leaf.ext"), "w") as e:     # iOS wants serverAuth, a SAN and at most 825 days
            e.write(f"subjectAltName={san}\nextendedKeyUsage=serverAuth\nbasicConstraints=CA:FALSE\nkeyUsage=digitalSignature,keyEncipherment\n")
        ossl("x509", "-req", "-in", f("leaf.csr"), "-CA", f("ca.crt"), "-CAkey", f("ca.key"), "-CAcreateserial", "-days", "800",
             "-sha256", "-extfile", f("leaf.ext"), "-out", f("leaf.crt"))
        open(f("leaf.san"), "w").write(san)
    return f("leaf.crt"), f("leaf.key")


PACK_LOCK = threading.Lock()
Handler.extensions_map = {**Handler.extensions_map, ".wasm": "application/wasm", ".js": "text/javascript", ".crt": "application/x-x509-ca-cert"}
if LAN:
    ip, host = lan_names()
    ctx = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
    ctx.load_cert_chain(*lan_cert(ip, host))
    lan = http.server.ThreadingHTTPServer(("0.0.0.0", LAN_PORT), Handler)
    lan.socket = ctx.wrap_socket(lan.socket, server_side=True, do_handshake_on_connect=False)   # handshake in each request thread
    threading.Thread(target=lan.serve_forever, daemon=True).start()
    print(f"LAN: https://{host}:{LAN_PORT}/  (https://{ip}:{LAN_PORT}/)  CA for the phone: https://{host}:{LAN_PORT}/lan-ca.crt", flush=True)
http.server.ThreadingHTTPServer(("127.0.0.1", PORT), Handler).serve_forever()
