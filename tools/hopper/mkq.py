#!/usr/bin/env python3
"""Batch spec -> tools/hopper/q_<topic>.py (from q_template.py), for hpar.sh.
Spec JSON: {"<topic>": {"q": "...", "addrs": ["0x4b5c00"], "data": ["0x777cc8"], "strings": ["Player Too Slow"]}}.
A string is found in pc/Speed.exe (exact, NUL-ended) and becomes a DATA address; DEEP=1 then also decompiles every
procedure that references a DATA address (at most 16 per topic), so a topic can start from a name alone.
usage: .venv/bin/python tools/hopper/mkq.py spec.json   (prints the topics, for hpar.sh)"""
import json, os, re, sys
import pefile
R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
pe = pefile.PE(f'{R}/pc/Speed.exe'); img = pe.get_memory_mapped_image()
tpl = open(f'{R}/tools/hopper/q_template.py').read()
DEEP = '''
seen = set(ADDRS)
for a in DATA:
    for x in refs(a):
        p = proc(x)
        if p is None or len(seen) >= len(ADDRS) + 16: continue
        e = p.getEntryPoint()
        if e in seen: continue
        seen.add(e); n += 1
        f.write('\\n==== 0x%x %s (refs data 0x%x)\\n' % (e, doc.getNameAtAddress(e) or '', a))
        try: f.write((p.decompile() or '(no pseudocode)') + '\\n')
        except Exception as x: f.write('(decompile failed: %s)\\n' % x)
        f.write('callers: %s\\n' % '; '.join(where(r) for r in refs(e)))
        f.flush()
'''
out = []
for t, s in json.load(open(sys.argv[1])).items():
    data = [int(a, 16) for a in s.get('data', [])]
    for st in s.get('strings', []):
        for m in re.finditer(re.escape(st.encode()) + b'\0', img):
            if m.start() == 0 or img[m.start() - 1] == 0: data.append(m.start() + 0x400000)
    code = tpl
    code = re.sub(r"^OUT = .*$", f"OUT = '{R}/build/hopper/{t}.txt'", code, flags=re.M)
    code = re.sub(r"^Q = .*$", 'Q = ' + repr(s['q']), code, flags=re.M)
    code = re.sub(r"^ADDRS = .*$", 'ADDRS = [' + ', '.join(s.get('addrs', [])) + ']', code, flags=re.M)
    code = re.sub(r"^DATA = .*$", 'DATA = [' + ', '.join(hex(a) for a in data) + ']', code, flags=re.M)
    code = code.replace("f.write('\\nDONE", DEEP.strip('\n') + "\nf.write('\\nDONE", 1)
    open(f'{R}/tools/hopper/q_{t}.py', 'w').write(code)
    out.append(t)
print(' '.join(out))
