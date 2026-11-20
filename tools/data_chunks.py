"""Independent gzip representations of known boot/race reads. Raw files remain untouched."""
import gzip
import hashlib
import json
from pathlib import Path


def build(root, dist):
    root, dist = Path(root), Path(dist)
    pieces = set()
    for line in (dist / 'entry_hint.tsv').read_text().splitlines():
        phase, path, off, size = line.split('\t')
        pieces.add((path, int(off), int(size)))
        # Cars selected at runtime are fetched whole by gf_prefetch/gf_read (host/files.c).
        total = (dist / path).stat().st_size
        if total <= 8 << 20:
            pieces.add((path, 0, total))
    # Every car folder in game/Cars/ can be picked at runtime by host/rivals.c; gf_prefetch/gf_read fetches
    # files <= 8 MB whole (GEOMETRY.BIN, TEXTURES.BIN, small VINYLS.BIN) and the first 256 KB of larger VINYLS.BIN.
    for p in (dist / 'game/Cars').rglob('*.BIN'):
        rel = p.relative_to(dist).as_posix()
        total = p.stat().st_size
        pieces.add((rel, 0, total if total <= 8 << 20 else 256 << 10))
    # Actual cold boot -> HUD reads outside the hints (logs/loadzip/before.json).
    # Keep the measured recipe in source so ordinary build_public.py reproduces the pack.
    for line in (root / 'census/data_chunks.tsv').read_text().splitlines()[1:]:
        path, off, size = line.split('\t')
        pieces.add((path, int(off), int(size)))
    out = dist / 'data-chunks'
    out.mkdir()
    index, raw_bytes, encoded_bytes = {}, 0, 0
    for path, off, size in sorted(pieces):
        with (dist / path).open('rb') as f:
            f.seek(off)
            raw = f.read(size)
        if len(raw) != size:
            raise ValueError(f'short piece: {path}:{off}:{size}')
        body = gzip.compress(raw, compresslevel=6, mtime=0)
        if len(body) >= size * .95:
            continue
        name = hashlib.sha256(body).hexdigest()
        index[f'{path}:{off}:{size}'] = name
        target = out / (name + '.gz')
        if not target.exists():
            target.write_bytes(body)
            encoded_bytes += len(body)
        raw_bytes += size
    (dist / 'data-chunks.json').write_text(json.dumps(index, separators=(',', ':')))
    print(f'data-chunks: {len(index)} read pieces, {raw_bytes} source bytes, {encoded_bytes} extra bucket bytes')
