#!/usr/bin/env python3
"""Summarize loadfast CDP logs at exact page-log markers, including in-flight bytes.

Usage: python3 tools/loadfast_report.py build/loadfast/baseline build/loadfast/after
The first /log request timestamps boot.js's clock origin to within request dispatch.
"""
import json
import pathlib
import re
import sys

print('| Run | Link -> menu MB / requests / s | Link -> HUD MB / requests / s | WORLD fully drawn MB / requests / s |')
print('|---|---:|---:|---:|')
for directory in sys.argv[1:]:
    for case in ('local', '50mbit'):
        base = pathlib.Path(directory) / case
        data = json.loads(base.with_suffix('.json').read_text())
        log = base.with_suffix('.timed.log').read_text()
        rows = data['rows']
        offset = next(r['start'] for r in rows if r['path'] == '/log')
        def marker(pattern):
            m = re.search(r'^([0-9.]+) ' + pattern, log, re.M)
            return float(m[1]) + offset if m else None
        menu = marker('flow state 3/255')
        hud = marker('d3d9 race HUD')
        city = marker('ug2: textured:')
        def phase(end):
            if end is None:
                return None
            started = [r for r in rows if r['start'] <= end]
            size = sum(r['bytes'] if r.get('end', float('inf')) <= end else
                       sum(n for t, n in r.get('chunks', []) if t <= end) for r in started)
            return {'bytes': size, 'requests': len(started), 'seconds': round(end, 3)}
        phases = dict(menu=phase(menu), hud=phase(hud), world=phase(max(hud, city)) if hud and city else None)
        base.with_suffix('.summary.json').write_text(json.dumps(phases, indent=2) + '\n')
        def fmt(p):
            return f"{p['bytes']/1e6:.1f} / {p['requests']} / {p['seconds']:.2f}" if p else 'UNKNOWN'
        print(f"| {pathlib.Path(directory).name} {case} | " + ' | '.join(fmt(p) for p in phases.values()) + ' |')
