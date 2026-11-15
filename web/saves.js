// Saves live in this browser (IndexedDB 'rn_saves'), not on a server. Loaded by the game page and the launcher.
// Game page: before the game starts, every saved file is written into the in-memory /save folder that host/files.c uses;
// a 1 s scan copies changed or deleted files back to IndexedDB (and once more when the tab hides or closes).
// Launcher: RN_SAVES.backup() downloads all saves as one JSON file, RN_SAVES.restore(file) puts them back.
(() => {
  const DB = 'rn_saves', ST = 'files';
  const open = () => new Promise((ok, no) => {
    const r = indexedDB.open(DB, 1);
    r.onupgradeneeded = () => r.result.createObjectStore(ST);
    r.onsuccess = () => ok(r.result); r.onerror = () => no(r.error);
  });
  const run = async (mode, f) => {
    const db = await open();
    return new Promise((ok, no) => {
      const t = db.transaction(ST, mode), s = t.objectStore(ST); let out;
      out = f(s); t.oncomplete = () => { db.close(); ok(out && out.result !== undefined ? out.result : out); }; t.onerror = t.onabort = () => no(t.error);
    });
  };
  const all = async () => {          // Map name -> Uint8Array
    const db = await open();
    return new Promise((ok, no) => {
      const m = new Map(), c = db.transaction(ST).objectStore(ST).openCursor();
      c.onsuccess = () => { const k = c.result; if (k) { m.set(k.key, k.value); k.continue(); } else { db.close(); ok(m); } };
      c.onerror = () => no(c.error);
    });
  };
  const b64 = u => { let s = ''; for (let i = 0; i < u.length; i += 0x8000) s += String.fromCharCode.apply(null, u.subarray(i, i + 0x8000)); return btoa(s); };
  const unb64 = t => Uint8Array.from(atob(t), c => c.charCodeAt(0));

  async function backup() {
    const files = {};
    for (const [k, v] of await all()) files[k] = b64(v);
    const blob = new Blob([JSON.stringify({ rn_saves: 1, files })], { type: 'application/json' });
    const a = document.createElement('a');
    a.href = URL.createObjectURL(blob); a.download = 'nfsu-saves-' + new Date().toISOString().slice(0, 10) + '.json';
    document.body.appendChild(a); a.click(); a.remove(); setTimeout(() => URL.revokeObjectURL(a.href), 1000);
    return Object.keys(files).length;
  }
  async function restore(file) {
    const j = JSON.parse(await file.text());
    if (!j || j.rn_saves !== 1 || typeof j.files !== 'object') throw new Error('No es una copia de partidas');
    const names = Object.keys(j.files), data = names.map(k => unb64(j.files[k]));
    await run('readwrite', s => { s.clear(); names.forEach((k, i) => s.put(data[i], k)); });
    return names.length;
  }

  // Game page: wraps Speed (out/speed.js) so its preRun fills /save first. Must load after out/speed.js.
  function hook() {
    if (typeof Speed !== 'function') return;
    const orig = Speed;
    window.Speed = cfg => orig({ ...cfg, preRun: [...(cfg.preRun || []), m => {
      const FS = m.FS, seen = new Map();            // name -> "size@mtime" last stored
      FS.mkdir('/save');
      m.addRunDependency('rn_saves');
      const walk = (dir, pre, out) => {
        for (const n of FS.readdir(dir)) {
          if (n === '.' || n === '..') continue;
          const st = FS.stat(dir + '/' + n);
          if (FS.isDir(st.mode)) walk(dir + '/' + n, pre + n + '/', out);
          else out.set(pre + n, { sig: st.size + '@' + +st.mtime, path: dir + '/' + n });
        }
        return out;
      };
      const scan = async () => {
        const now = walk('/save', '', new Map()), puts = [], dels = [];
        for (const [n, f] of now) if (seen.get(n) !== f.sig) puts.push([n, f, FS.readFile(f.path)]);
        for (const n of seen.keys()) if (!now.has(n)) dels.push(n);
        if (!puts.length && !dels.length) return;
        await run('readwrite', s => { for (const [n, , d] of puts) s.put(d, n); for (const n of dels) s.delete(n); });
        for (const [n, f] of puts) seen.set(n, f.sig);
        for (const n of dels) seen.delete(n);
      };
      all().then(async files => {
        const stored = new Set(files.keys());
        // An empty browser store starts from a save: on the dev server (tools/serve.py) the OWNER's save/ folder, so :5180 keeps
        // his profiles; on the public build web/seed_save.json, the profile FULL the game made itself (tools/webcheck.mjs typed
        // the name), so a phone with no keyboard skips the name screen (everything is unlocked for every profile: patches_unlock.py).
        // A visit that stopped at the name screen already stored the game's "DirectInput user maps.txt": no Profiles.usr is the test.
        if (window.RN_PUBLIC ? !files.has('Profiles.usr') : !files.size) {
          const j = await fetch(window.RN_PUBLIC ? 'seed_save.json' : '/save-backup.json').then(r => r.ok ? r.json() : null).catch(() => null);
          if (j && j.files) for (const k of Object.keys(j.files)) { files.set(k, unb64(j.files[k])); stored.delete(k); }
        }
        for (const [k, d] of files) {
          const parts = k.split('/'); let p = '/save';
          for (const x of parts.slice(0, -1)) { p += '/' + x; try { FS.mkdir(p); } catch {} }
          FS.writeFile('/save/' + k, d);
        }
        walk('/save', '', new Map()).forEach((f, n) => { if (stored.has(n)) seen.set(n, f.sig); });
      }).catch(e => console.warn('saves:', e)).finally(() => {
        m.removeRunDependency('rn_saves');
        let busy = false;
        const tick = () => { if (busy) return; busy = true; scan().catch(e => console.warn('saves:', e)).finally(() => { busy = false; }); };
        setInterval(tick, 1000);
        addEventListener('pagehide', tick);
        document.addEventListener('visibilitychange', () => { if (document.hidden) tick(); });
      });
    }] });
  }

  window.RN_SAVES = { backup, restore, list: async () => [...(await all()).keys()] };
  hook();
})();
