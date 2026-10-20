#!/usr/bin/env python3
"""Static registry census. No installer or game is executed."""
import collections
import csv
import hashlib
import json
import re
import struct
from pathlib import Path

import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32, CS_GRP_CALL, CS_GRP_JUMP, CS_GRP_RET
from capstone import x86

SIGNATURES = {'RegOpenKeyA': 3, 'RegOpenKeyExA': 5, 'RegQueryValueA': 4, 'RegQueryValueExA': 6,
              'RegSetValueA': 5, 'RegSetValueExA': 6, 'RegCreateKeyA': 3, 'RegCreateKeyExA': 9,
              'RegDeleteKeyA': 2, 'RegDeleteValueA': 2, 'RegCloseKey': 1,
              'RegEnumKeyA': 4, 'RegEnumKeyExA': 8, 'RegEnumValueA': 8}
MUTATIONS = {n for n in SIGNATURES if n.startswith(('RegSet', 'RegCreate', 'RegDelete'))}
ROOTS = {0x80000000: 'HKEY_CLASSES_ROOT', 0x80000001: 'HKEY_CURRENT_USER', 0x80000002: 'HKEY_LOCAL_MACHINE',
         0x80000003: 'HKEY_USERS', 0x80000005: 'HKEY_CURRENT_CONFIG'}
TYPES = {0:'REG_NONE',1:'REG_SZ',2:'REG_EXPAND_SZ',3:'REG_BINARY',4:'REG_DWORD',7:'REG_MULTI_SZ'}


def strings(data):
    for m in re.finditer(rb'[\x20-\x7e]{2,}\x00', data):
        yield m.start(), m.group()[:-1].decode('ascii'), 'ascii'
    for m in re.finditer(rb'(?:[\x20-\x7e]\x00){2,}\x00\x00', data):
        yield m.start(), m.group()[:-2].decode('utf-16le'), 'utf-16le'


def analyze(path):
    data = path.read_bytes()
    pe = pefile.PE(data=data)
    base = pe.OPTIONAL_HEADER.ImageBase
    iat = {i.address: i.name.decode() for e in getattr(pe, 'DIRECTORY_ENTRY_IMPORT', [])
           for i in e.imports if i.name}
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.detail = True
    md.skipdata = True
    sections = [s for s in pe.sections if s.Characteristics & 0x20000000]
    # Streaming decode avoids keeping Capstone objects for the whole binary.
    thunks = {}
    for sec in sections:
        for ins in md.disasm(sec.get_data(), base + sec.VirtualAddress):
            if ins.id and ins.mnemonic == 'jmp' and ins.operands[0].type == x86.X86_OP_MEM:
                m = ins.operands[0].mem
                if not m.base and not m.index and m.disp in iat:
                    thunks[ins.address] = iat[m.disp]
    calls, refs = [], collections.defaultdict(list)
    for sec in sections:
        regs, stack = {}, []
        for ins in md.disasm(sec.get_data(), base + sec.VirtualAddress):
            if not ins.id:
                regs, stack = {}, []
                continue
            ops = ins.operands
            def val(op):
                if op.type == x86.X86_OP_IMM:
                    return op.imm & 0xffffffff
                if op.type == x86.X86_OP_REG:
                    return regs.get(op.reg, 'unknown')
                if op.type == x86.X86_OP_MEM and not op.mem.base and not op.mem.index and op.mem.disp in iat:
                    return ('iat', iat[op.mem.disp])
                return 'unknown'
            for op in ops:
                if op.type == x86.X86_OP_IMM:
                    refs[op.imm & 0xffffffff].append(ins.address)
            if ins.group(CS_GRP_CALL):
                op = ops[0]
                target = val(op)
                name = target[1] if isinstance(target, tuple) else thunks.get(target)
                if name in SIGNATURES:
                    count = SIGNATURES[name]
                    args = [stack[-1-i] if len(stack)>i else 'unknown' for i in range(count)]
                    calls.append({'site':ins.address,'api':name,'args':args,'bytes':ins.bytes.hex()})
                    del stack[max(0,len(stack)-count):]
                else:
                    stack = []
                if name:
                    for r in (x86.X86_REG_EAX,x86.X86_REG_ECX,x86.X86_REG_EDX):regs.pop(r,None)
                else:
                    regs = {}
                continue
            old = dict(regs)
            _, writes = ins.regs_access()
            for r in writes:regs.pop(r,None)
            if ins.mnemonic == 'push':
                regs = old
                stack.append(val(ops[0]))
            elif ins.mnemonic == 'pop':
                if ops[0].type == x86.X86_OP_REG:regs[ops[0].reg] = stack.pop() if stack else 'unknown'
            elif ins.mnemonic == 'mov' and len(ops)==2 and ops[0].type == x86.X86_OP_REG:
                regs = old
                regs[ops[0].reg] = val(ops[1])
            elif ins.mnemonic == 'xor' and len(ops)==2 and ops[0].type == ops[1].type == x86.X86_OP_REG and ops[0].reg==ops[1].reg:
                regs[ops[0].reg] = 0
            elif ins.mnemonic in ('add','sub','and') and ops[0].type == x86.X86_OP_REG and ops[0].reg == x86.X86_REG_ESP:
                stack=[]
            if ins.group(CS_GRP_JUMP) or ins.group(CS_GRP_RET):
                regs,stack = {},[]
    return pe, data, iat, calls, refs


def main():
    lines = ['# Made by tools/census/registry.py; pefile, Capstone and raw NUL-terminated string scans.',
             '# FACT = bytes or direct static API reference. INFERENCE = registry-related string candidate.',
             '# Static evidence only. A string does not prove a write. No install values are invented.',
             '# Call arguments use a straight-line stack slice; joins, dynamic strings/handles/data remain unknown.',
             '# Executable-section linear decoding can include data or miss overlapped code; completeness of dynamic writes is unknown.',
             '# API argument order/type source: https://learn.microsoft.com/en-us/windows/win32/api/winreg/ (each named API).']
    count_strings = count_writes = count_calls = 0
    def emit(kind, **record):lines.append(kind+'\t'+json.dumps(record,ensure_ascii=True,sort_keys=True))
    paths = [Path('pc/Speed.exe')] + sorted((p for p in Path('game').rglob('*') if p.is_file() and p.suffix.lower() in ('.exe','.dll')),key=str)
    for path in paths:
        try:pe,data,iat,calls,refs=analyze(path)
        except pefile.PEFormatError:
            emit('UNKNOWN',source=str(path),reason='Not a parseable PE; registry writes unknown')
            continue
        base=pe.OPTIONAL_HEADER.ImageBase
        def source(a):
            try:return f'{path}+0x{pe.get_offset_from_rva(a-base):x}'
            except pefile.PEFormatError:return 'unknown'
        def text_at(a):
            if not isinstance(a,int) or not a:return 'unknown'
            try:
                off=pe.get_offset_from_rva(a-base)
                if not (0<=off<len(data)):return 'unknown'
                match=re.match(rb'[\x20-\x7e]*\x00',data[off:off+4096])
                return {'text':match.group()[:-1].decode('ascii'),'address':f'0x{a:08x}','source':source(a)} if match else 'unknown'
            except pefile.PEFormatError:return 'unknown'
        if str(path)=='pc/Speed.exe':
            resolved=list(csv.DictReader((line for line in Path('census/imports_sites.tsv').read_text().splitlines() if not line.startswith('#')),delimiter='\t'))
            known={int(row['site_address'],16):row for row in resolved if row['import'].startswith('advapi32.dll!')}
            calls=[c for c in calls if c['site'] in known]
            present={c['site'] for c in calls}
            for a,row in known.items():
                if a not in present:
                    name=row['import'].split('!')[1]
                    calls.append({'site':a,'api':name,'args':['unknown']*SIGNATURES[name],'bytes':row['bytes']})
            calls.sort(key=lambda c:c['site'])
        emit('FILE',source=str(path),size=len(data),sha256=hashlib.sha256(data).hexdigest(),registry_imports=sorted(set(iat.values())&SIGNATURES.keys()),static_registry_calls=len(calls))
        query_funcs=set()
        # All registry calls are retained, including unresolved value-name arguments.
        for call in calls:
            a,name,args=call['site'],call['api'],call['args']
            rec={'address':f'0x{a:08x}','source':source(a),'api':name,'bytes':call['bytes'],'arguments':args}
            if name in ('RegOpenKeyA','RegOpenKeyExA','RegCreateKeyA','RegCreateKeyExA'):
                rec.update(root=ROOTS.get(args[0],'unknown') if isinstance(args[0],int) else 'unknown',key=text_at(args[1]))
            if name in ('RegQueryValueExA','RegSetValueExA','RegDeleteValueA'):
                rec['value_name']=text_at(args[1])
            if name=='RegSetValueExA':
                rec.update(key='unknown',type=TYPES.get(args[3],'unknown') if isinstance(args[3],int) else 'unknown',value='unknown')
                pointer,size=args[4],args[5]
                if isinstance(pointer,int) and isinstance(size,int) and 0<size<=4096:
                    try:
                        off=pe.get_offset_from_rva(pointer-base)
                        if 0<=off and off+size<=len(data):
                            raw=data[off:off+size]
                            rec['value_source']=source(pointer)
                            rec['value']=raw.rstrip(b'\0').decode('ascii') if args[3] in (1,2) and all(b==0 or 32<=b<127 for b in raw) else (struct.unpack('<I',raw)[0] if args[3]==4 and size==4 else {'hex':raw.hex()})
                    except pefile.PEFormatError:pass
            if name=='RegSetValueA':rec.update(key=text_at(args[1]),type=TYPES.get(args[2],'unknown') if isinstance(args[2],int) else 'unknown',value=text_at(args[3]))
            if name in MUTATIONS:
                if name=='RegDeleteKeyA':rec['key']=text_at(args[1])
                rec.setdefault('key','unknown')
                rec.setdefault('value_name','not_applicable' if name.startswith(('RegCreate','RegDeleteKey')) else 'unknown')
                rec.setdefault('type','unknown' if name.startswith('RegSet') else 'not_applicable')
                rec.setdefault('value','unknown' if name.startswith('RegSet') else 'not_applicable')
            emit('WRITE' if name in MUTATIONS else 'API',**rec)
            count_calls+=1
            count_writes+=name in MUTATIONS
        for off,text,encoding in strings(data):
            match=re.search(r'(?i)(?:software\\|hardware\\|HKEY_(?:LOCAL_MACHINE|CURRENT_USER|CLASSES_ROOT|USERS)\\)',text)
            if not match and not re.search(r'(?i)registry|regsetvalue|regcreatekey',text):continue
            if match:
                off+=match.start()*(2 if encoding=='utf-16le' else 1);text=text[match.start():]
            try:a=base+pe.get_rva_from_offset(off)
            except pefile.PEFormatError:a=None
            emit('STRING',source=f'{path}+0x{off:x}',address=f'0x{a:08x}' if a is not None else 'unknown',encoding=encoding,text=text,classification='registry_key_literal' if match else 'registry_context_candidate')
            count_strings+=1
        if str(path)=='pc/Speed.exe':
            # Include all literals referenced from a function containing a registry
            # call, and its direct callers. These are candidates, not invented keys.
            roots=sorted(int(l.split('\t')[0],16) for l in Path('census/speed_exe_functions.tsv').read_text().splitlines())
            import bisect
            owners={roots[bisect.bisect_right(roots,c['site'])-1] for c in calls}
            ranges=[(r, roots[i+1] if i+1<len(roots) else base+pe.OPTIONAL_HEADER.SizeOfImage) for i,r in enumerate(roots) if r in owners]
            wrapper_calls=[]
            for sec in pe.sections:
                if not sec.Characteristics&0x20000000:continue
                raw=sec.get_data();start=base+sec.VirtualAddress
                for m in re.finditer(b'\xe8',raw):
                    o=m.start()
                    if o+5<=len(raw) and (start+o+5+struct.unpack_from('<i',raw,o+1)[0])&0xffffffff in owners:
                        wrapper_calls.append(start+o)
            for off,text,encoding in strings(data):
                a=base+pe.get_rva_from_offset(off)
                sites=[s for s in refs.get(a,[]) if any(lo<=s<hi for lo,hi in ranges) or any(c-32<=s<c for c in wrapper_calls)]
                if sites:
                    emit('SPEED_REGISTRY_CONTEXT',source=f'{path}+0x{off:x}',address=f'0x{a:08x}',text=text,encoding=encoding,reference_sites=[f'0x{s:08x}' for s in sorted(set(sites))],classification='candidate; exact key/value role unknown unless API record proves it')
    for path in sorted(Path('game').rglob('*'),key=str):
        if not path.is_file() or path.suffix.lower() not in ('.inf','.ini','.iss','.reg'):continue
        raw=path.read_bytes()
        emit('INSTALLER_TEXT',source=str(path),size=len(raw),sha256=hashlib.sha256(raw).hexdigest())
        for number,line in enumerate(raw.decode('utf-8-sig',errors='replace').splitlines(),1):
            emit('TEXT_LINE',source=f'{path}:{number}',text=line,registry_write='unknown; configuration text alone does not establish a write')
    lines.insert(6,f'# Counts: registry_strings={count_strings}; registry_api_sites={count_calls}; mutation_sites={count_writes}.')
    lines.append('UNKNOWN\t'+json.dumps({'real_install_values':'unknown; no installer was executed','missing_or_compressed_installer_payload':'unknown','Speed.exe_registry_write_imports':[],'dynamic_or_cross_function_arguments':'unknown'}))
    Path('census/registry.txt').write_text('\n'.join(lines)+'\n')
    print(f'census/registry.txt: {count_strings} registry strings, {count_calls} API sites, {count_writes} mutation sites')


if __name__=='__main__':main()
