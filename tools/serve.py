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
POST /plan/verdict {"detail", "ok", "note"} (web/plan/) writes details[i].owner = {ok, note, time} into web/plan/plan.json (tmp + replace).
--lan also serves HTTPS on 0.0.0.0:5443 for a phone or tablet on the same Wi-Fi (SAB and WebGPU need a secure
context; only localhost is exempt). The certificate comes from a local CA in build/lan-cert/ (made once with openssl;
the Mac keychain is not touched). The phone trusts it once: open https://<mac>.local:5443/lan-ca.crt, install the
profile, then Settings > General > About > Certificate Trust Settings > full trust (iOS); Android: Settings > Security
> Install a certificate > CA. The leaf certificate is remade when the Mac's LAN address changes.
HTTP/1.1 keep-alive on both ports: every response has a Content-Length (204 and 304 have no body), and a request whose body
is not read closes its connection, so one connection carries the many Range reads of the game thread.
--lan also opens a plain-HTTP setup port (5444) that serves only /setup, /setup.json, /lan-ca.crt and /nfsu.mobileconfig: a
device that does not trust the CA yet cannot open the HTTPS page, so it starts here (scan the QR on /setup, install the
profile; iOS: Settings > General > About > Certificate Trust Settings > full trust). /nfsu.mobileconfig = the CA as an iOS
profile (payload com.apple.security.root), made here from build/lan-cert/ca.crt. RN_LAN_PORT / RN_SETUP_PORT change the two ports.
Usage: .venv/bin/python tools/serve.py [port] [--lan]
"""
import email.utils, gzip, hashlib, http.server, json, os, plistlib, shutil, socket, ssl, subprocess, sys, threading, time, urllib.parse, uuid

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ARGS = [a for a in sys.argv[1:] if a != "--lan"]
LAN = "--lan" in sys.argv
PORT = int(ARGS[0]) if ARGS else 5180
LAN_PORT = int(os.environ.get("RN_LAN_PORT") or 5443)
SETUP_PORT = int(os.environ.get("RN_SETUP_PORT") or 5444)
LAN_INFO = {}     # filled when --lan starts: host, ip, ports
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


def mobileconfig():
    """The local CA as an unsigned iOS configuration profile (a root certificate payload), or None before the CA exists."""
    ca = os.path.join(CERT, "ca.crt")
    if not os.path.exists(ca):
        return None
    der = ssl.PEM_cert_to_DER_cert(open(ca).read())
    ns = uuid.uuid5(uuid.NAMESPACE_URL, "https://nfsu.local/lan-ca/" + hashlib.sha256(der).hexdigest())
    cert = {"PayloadType": "com.apple.security.root", "PayloadVersion": 1, "PayloadIdentifier": "com.nfsu.lan.ca.cert",
            "PayloadUUID": str(uuid.uuid5(ns, "cert")).upper(), "PayloadDisplayName": "NFSU local CA", "PayloadContent": der}
    top = {"PayloadType": "Configuration", "PayloadVersion": 1, "PayloadIdentifier": "com.nfsu.lan.ca", "PayloadUUID": str(ns).upper(),
           "PayloadDisplayName": "NFSU local CA", "PayloadDescription": "Lets this device open the NFSU page on your Mac over HTTPS.",
           "PayloadOrganization": "NFSU (this Mac)", "PayloadContent": [cert]}
    return plistlib.dumps(top)


def setup_info():
    host, ip = LAN_INFO.get("host"), LAN_INFO.get("ip")
    return json.dumps({"lan": bool(LAN_INFO), "https": f"https://{host}:{LAN_PORT}/" if host else None,
                       "https_ip": f"https://{ip}:{LAN_PORT}/" if ip else None,
                       "setup": f"http://{host}:{SETUP_PORT}/setup" if host else None,
                       "setup_ip": f"http://{ip}:{SETUP_PORT}/setup" if ip else None,
                       "ca": "/lan-ca.crt", "profile": "/nfsu.mobileconfig"}).encode()


class Handler(http.server.SimpleHTTPRequestHandler):
    protocol_version = "HTTP/1.1"      # keep-alive: every answer below carries its Content-Length
    timeout = 300                      # an idle connection frees its thread

    def reply(self, code, ctype, body, extra=()):
        self.send_response(code)
        self.send_header("Content-Type", ctype)
        self.send_header("Content-Length", str(len(body)))
        for k, v in extra:
            self.send_header(k, v)
        self.end_headers()
        if self.command != "HEAD":
            self.wfile.write(body)

    def refuse(self, code):
        """An error before the request body was read: close, or the body would be parsed as the next request."""
        self.close_connection = True
        self.send_error(code)

    def do_PUT(self):
        p = save_path(self.path, save_root(self.headers)) if self.path.startswith("/save/") else None
        if not p:
            self.refuse(403)
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

    def plan_verdict(self):
        """The OWNER's verdict: details[i].owner in web/plan/plan.json. 204, or 400 for a bad body or unknown detail."""
        n = int(self.headers.get("Content-Length", 0))
        if n > 4096:
            self.refuse(413)
            return
        body = self.rfile.read(n)
        try:
            v = json.loads(body)
            detail, ok, note = v["detail"], v["ok"], v.get("note", "")
            assert isinstance(detail, str) and isinstance(ok, bool) and isinstance(note, str)
        except (ValueError, KeyError, AssertionError, AttributeError, TypeError):
            self.send_error(400, "want {detail: str, ok: bool, note: str}")
            return
        path = os.path.join(ROOT, "web", "plan", "plan.json")
        with PLAN_LOCK:
            with open(path, encoding="utf-8") as f:
                plan = json.load(f)
            hit = [d for d in plan.get("details", []) if d.get("name") == detail]
            if not hit:
                self.send_error(400, "unknown detail")
                return
            hit[0]["owner"] = {"ok": ok, "note": note[:500], "time": time.strftime("%Y-%m-%d %H:%M")}
            with open(path + ".tmp", "w", encoding="utf-8") as f:
                json.dump(plan, f, ensure_ascii=False, indent=1)
            os.replace(path + ".tmp", path)
        self.send_response(204)
        self.end_headers()

    def do_POST(self):
        route = self.path.split("?", 1)[0]
        if route == "/plan/verdict":
            self.plan_verdict()
            return
        if route not in ("/log", "/telemetry"):
            self.refuse(403)
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
            self.reply(200, "text/html; charset=utf-8", becmon.page(), [("Cache-Control", "no-store")])
            return
        if route == "/launcher":             # the pre-game launcher (lane w3, OWNER 2026-11-07); bare / opens the game directly
            self.path = "/launcher.html"
        elif route == "/setup":              # LAN entry page (web/setup.html): QR, CA, iOS profile
            self.path = "/setup.html"
        elif route == "/setup.json":
            self.reply(200, "application/json", setup_info(), [("Cache-Control", "no-store")])
            return
        elif route == "/nfsu.mobileconfig":
            body = mobileconfig()
            if body is None:
                self.send_error(404, "no CA yet: start serve.py with --lan once")
            else:
                self.reply(200, "application/x-apple-aspen-config", body, [("Content-Disposition", 'attachment; filename="nfsu-ca.mobileconfig"')])
            return
        if route in ("/game-files.json", "/save-files.json"):
            top = os.path.join(ROOT, "game") if route == "/game-files.json" else save_root(self.headers)
            self.reply(200, "application/json", listing(top) if os.path.isdir(top) else b"[]")
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
                self.send_header("Content-Length", "0")
                self.end_headers()
                return
            with open(path, "rb") as f:
                f.seek(a)
                body = f.read(b - a + 1)
            self.reply(206, "application/octet-stream", body, [("Content-Range", f"bytes {a}-{b}/{size}")])
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
        if path == "/setup.html":
            return os.path.join(ROOT, "web", "setup.html")
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


class SetupHandler(Handler):
    """The plain-HTTP LAN port: only the page that gets a new device to trust the CA, nothing of the game or the saves."""
    def do_GET(self):
        if self.path.split("?", 1)[0] in ("/setup", "/setup.json", "/lan-ca.crt", "/nfsu.mobileconfig"):
            super().do_GET()
        else:
            self.send_error(404)

    def do_PUT(self):
        self.refuse(405)

    do_POST = do_DELETE = do_HEAD = do_PUT


PACK_LOCK = threading.Lock()
PLAN_LOCK = threading.Lock()
Handler.extensions_map = {**Handler.extensions_map, ".wasm": "application/wasm", ".js": "text/javascript", ".crt": "application/x-x509-ca-cert"}
if LAN:
    ip, host = lan_names()
    ctx = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
    ctx.load_cert_chain(*lan_cert(ip, host))
    LAN_INFO.update(host=host, ip=ip)
    lan = http.server.ThreadingHTTPServer(("0.0.0.0", LAN_PORT), Handler)
    lan.socket = ctx.wrap_socket(lan.socket, server_side=True, do_handshake_on_connect=False)   # handshake in each request thread
    threading.Thread(target=lan.serve_forever, daemon=True).start()
    threading.Thread(target=http.server.ThreadingHTTPServer(("0.0.0.0", SETUP_PORT), SetupHandler).serve_forever, daemon=True).start()
    print(f"LAN: https://{host}:{LAN_PORT}/  (https://{ip}:{LAN_PORT}/)  setup page + CA for a new device: http://{host}:{SETUP_PORT}/setup", flush=True)
http.server.ThreadingHTTPServer(("127.0.0.1", PORT), Handler).serve_forever()
