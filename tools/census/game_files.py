#!/usr/bin/env python3
"""Inventory game files and literal file/extension references in Speed.exe."""
import collections
import hashlib
import json
import re
from pathlib import Path

import pefile


def main():
    root=Path('game')
    inventory=[]
    for p in sorted((p for p in root.rglob('*') if p.is_file()),key=lambda p:p.relative_to(root).as_posix()):
        with p.open('rb') as f:head=f.read(16)
        inventory.append({'path':p.relative_to(root).as_posix(),'size':p.stat().st_size,
                          'first_16_bytes_hex':head.hex(),'extension':p.suffix.lower(),
                          'source':p.as_posix(),'header_source':p.as_posix()+'+0x0'})
    exe=Path('pc/Speed.exe');raw=exe.read_bytes();pe=pefile.PE(data=raw)
    names=collections.defaultdict(list);extensions=collections.defaultdict(list)
    for f in inventory:
        names[Path(f['path']).name.lower()].append(f['path'])
        if f['extension']:extensions[f['extension']].append(f['path'])
    scans=[]
    for m in re.finditer(rb'[\x20-\x7e]{2,}\x00',raw):scans.append((m.start(),m.group()[:-1].decode('ascii'),'ascii',1))
    for m in re.finditer(rb'(?:[\x20-\x7e]\x00){2,}\x00\x00',raw):scans.append((m.start(),m.group()[:-2].decode('utf-16le'),'utf-16le',2))
    refs=[]
    # Keep the containing string as evidence. Syntax matches are candidates,
    # not proof the game opens that path. Format placeholders are not expanded.
    file_pattern=re.compile(r'(?i)(?<![a-z0-9_])(?:[a-z0-9_%*?~.-]+[\\/])*[a-z0-9_%*?~.-]+\.[a-z][a-z0-9]{0,7}(?![a-z0-9_])')
    extension_pattern=re.compile(r'(?i)^\*?(\.[a-z][a-z0-9]{0,7})$')
    for off,text,encoding,width in sorted(scans):
        found={}
        for m in file_pattern.finditer(text):found[(m.start(),m.group())]='filename_syntax_candidate'
        ext=extension_pattern.fullmatch(text)
        if ext:found[(0,text)]='extension_literal'
        for name in names:
            for m in re.finditer(r'(?i)(?<![a-z0-9_.-])'+re.escape(name)+r'(?![a-z0-9_.-])',text):
                found[(m.start(),m.group())]='inventory_basename_match'
        if not found:continue
        candidates=[]
        for (start,literal),kind in sorted(found.items()):
            address=pe.OPTIONAL_HEADER.ImageBase+pe.get_rva_from_offset(off+start*width)
            normalized=literal.replace('\\','/').lower()
            exact=[f['path'] for f in inventory if f['path'].lower()==normalized]
            basename=names.get(normalized.rsplit('/',1)[-1],[])
            candidates.append({'literal':literal,'kind':kind,'address':f'0x{address:08x}',
                               'source':f'pc/Speed.exe+0x{off+start*width:x}',
                               'exact_path_matches':exact,'basename_matches':basename,
                               'extension_matches':extensions.get(literal.lstrip('*').lower(),[]) if kind=='extension_literal' else [],
                               'use_at_runtime':'unknown'})
        refs.append({'text':text,'encoding':encoding,
                     'address':f'0x{pe.OPTIONAL_HEADER.ImageBase+pe.get_rva_from_offset(off):08x}',
                     'source':f'pc/Speed.exe+0x{off:x}','references':candidates})
    out={'_header':'Made by tools/census/game_files.py; stat/read(16) on game/; ASCII and UTF-16LE NUL-terminated Speed.exe strings.',
         'sources':{'inventory_root':'game/','string_source':'pc/Speed.exe','exe_sha256':hashlib.sha256(raw).hexdigest()},
         'limits':['File metadata is FACT. String bytes and addresses are FACT. Filename syntax and file associations are INFERENCE.',
                   'Literal scan includes source paths/debug strings. Dynamic paths, string encodings outside printable ASCII and runtime use are unknown.',
                   'Case-insensitive matching normalizes backslashes. All files are included, including hidden files. No file bodies are copied.'],
         'counts':{'files':len(inventory),'total_bytes':sum(f['size'] for f in inventory),'reference_strings':len(refs),
                   'references':sum(len(r['references']) for r in refs),'extensions':dict(sorted(collections.Counter(f['extension'] for f in inventory).items()))},
         'files':inventory,'speed_exe_references':refs}
    Path('census/game_files.json').write_text(json.dumps(out,indent=2)+'\n')
    print('census/game_files.json:',json.dumps(out['counts'],sort_keys=True))


if __name__=='__main__':main()
