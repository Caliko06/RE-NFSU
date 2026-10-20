#!/usr/bin/env python3
"""Extract SDK DirectSound constants and x86 Windows structure layouts."""
import hashlib
import json
import re
import subprocess
import sys
from pathlib import Path

from dinput_keys import ARCHIVE, LEARN, RAW, SDK, layouts, line_cite, load, struct

GROUPS = {'HRESULT':r'DS_OK|DSERR_\w+', 'DSSCL':r'DSSCL_\w+',
          'DSBCAPS':r'DSBCAPS_\w+', 'DSBPLAY':r'DSBPLAY_\w+',
          'DSBSTATUS':r'DSBSTATUS_\w+', 'DSBLOCK':r'DSBLOCK_\w+',
          'DSBVOLUME':r'DSBVOLUME_\w+', 'DSBPAN':r'DSBPAN_\w+',
          'DSBFREQUENCY':r'DSBFREQUENCY_\w+'}
DOCS = {'HRESULT':('ee416775','directsound-return-values-by-name'),
        'DSSCL':('ee418049','parameters'), 'DSBCAPS':('ee416818','members'),
        'DSBPLAY':('ee418074','parameters'), 'DSBSTATUS':('ee418070','parameters'),
        'DSBLOCK':('ee418073','parameters'), 'DSBVOLUME':('ee418150','remarks'),
        'DSBPAN':('ee418148','remarks'), 'DSBFREQUENCY':('ee418143','remarks')}
STRUCT_DOCS = {'DSBUFFERDESC':'ee416820','DSCAPS':'ee416821','DSBCAPS':'ee416818'}
URLS = {'dsound.h':RAW+'um/dsound.h','mmreg.h':RAW+'shared/mmreg.h',
        'guiddef.h':RAW+'shared/guiddef.h','winerror.h':RAW+'shared/winerror.h',
        'waveformatex.html':LEARN+'api/mmreg/ns-mmreg-waveformatex',
        **{name+'.html':ARCHIVE+name+'(v=vs.85)' for name in set([n for n,_ in DOCS.values()]+list(STRUCT_DOCS.values()))}}


def main():
    cache = Path(sys.argv[1] if len(sys.argv)>1 else '/tmp/nfsu-c1-sdk')
    cache.mkdir(parents=True,exist_ok=True)
    files = {name:load(cache,name,url) for name,url in URLS.items()}
    header = files['dsound.h']; errors = files['winerror.h']
    definitions = []
    for group, pattern in GROUPS.items():
        for match in re.finditer(r'^#define\s+('+pattern+r')\s+([^\n]+)',header,re.M):
            name, expression = match.groups()
            expression = re.sub(r'/\*.*?\*/|//.*','',expression).strip()
            condition = 'all versions in this header'
            if name=='DSBFREQUENCY_MAX':
                preceding = header[:match.start()].rstrip().splitlines()[-1]
                assert preceding in ('#if DIRECTSOUND_VERSION >= 0x0900','#else')
                condition = 'DIRECTSOUND_VERSION >= 0x0900' if preceding.startswith('#if') else 'DIRECTSOUND_VERSION < 0x0900'
            definitions.append((group,name,expression,condition,header[:match.start()].count('\n')+1))
    # Preprocess Winerror.h for Windows, selecting its _WIN32 branch. Its sole
    # include supplies annotations, which are irrelevant to macro extraction.
    preprocessed = subprocess.run(['clang','-target','i686-pc-windows-msvc','-x','c','-E','-dM','-'],
            input=re.sub(r'^#include[^\n]*','',errors,flags=re.M),text=True,capture_output=True,check=True).stdout
    aliases = sorted({expr for group,_,expr,_,_ in definitions if group=='HRESULT' and re.fullmatch(r'\w+',expr)})
    win_macros = []
    for name in aliases:
        match = re.search(r'^#define\s+'+name+r'\s+([^\n]+)',preprocessed,re.M)
        assert match,name
        win_macros.append(match[0])
    for name in ('MAKE_HRESULT','_HRESULT_TYPEDEF_'):
        win_macros.append(re.search(r'^#define\s+'+name+r'\([^\n]+',preprocessed,re.M)[0])
    code = 'typedef long HRESULT;\n'+'\n'.join(win_macros)+'\n'
    code += re.search(r'^#define\s+_FACDS\s+[^\n]+',header,re.M)[0]+'\n'
    code += re.search(r'^#define\s+MAKE_DSHRESULT\([^\n]+',header,re.M)[0]+'\n'
    for i,(_,_,expr,_,_) in enumerate(definitions):code += f'const unsigned long C1_{i} = (unsigned long)({expr});\n'
    compiled = subprocess.run(['clang','-target','i686-pc-windows-msvc','-x','c','-S','-emit-llvm','-o','-','-'],
            input=code,text=True,capture_output=True,check=True).stdout
    values = {int(i):int(value)&0xffffffff for i,value in re.findall(r'@C1_(\d+) = [^\n]*?constant i32 (-?\d+)',compiled)}
    assert len(values)==len(definitions)
    rows = []
    for i,(group,name,expression,condition,line) in enumerate(definitions):
        value = values[i]
        if group in ('DSBPAN','DSBVOLUME') and value>=0x80000000:value -= 0x100000000
        doc, section = DOCS[group]
        # Return-value names are list entries, not HTML section anchors.
        doc_url = ARCHIVE+doc+'(v=vs.85)'+('' if group=='HRESULT' else '#'+section)
        row = {'group':group,'name':name,'value':value,'value_hex':f'0x{values[i]:08x}',
               'header_expression':expression,'condition':condition,
               'sources':{'header':SDK+f'um/dsound.h#L{line}','documentation':doc_url},
               'documented_name_present':bool(re.search(r'\b'+name+r'\b',files[doc+'.html']))}
        if group=='HRESULT':
            row['hresult_hex'] = row['value_hex']
            row['signed_hresult'] = value if value<0x80000000 else value-0x100000000
            row['severity'] = value>>31
            row['facility'] = (value>>16)&0x1fff
            row['code'] = value&0xffff
            if expression in aliases:
                macro = next(m for m in win_macros if m.startswith('#define '+expression+' '))
                literal = macro.split(None,2)[2]
                pattern = r'^#define\s+'+expression+r'\s+'+re.escape(literal)+r'\s*$'
                row['sources']['winerror_alias'] = line_cite(errors,pattern,SDK+'shared/winerror.h')
                row['win32_alias_expression'] = literal
            else:
                row['sources']['facility'] = line_cite(header,r'^#define\s+_FACDS\s',SDK+'um/dsound.h')
                row['sources']['make_dshresult'] = line_cite(header,r'^#define\s+MAKE_DSHRESULT\(',SDK+'um/dsound.h')
                row['sources']['make_hresult'] = line_cite(errors,r'^#define\s+MAKE_HRESULT\(',SDK+'shared/winerror.h')
        if group in ('DSBPAN','DSBVOLUME'):row['units'] = 'hundredths of a decibel'
        if group=='DSBFREQUENCY':
            row['units'] = 'Hz' if name!='DSBFREQUENCY_ORIGINAL' else 'special value: reset to buffer format sample rate'
            row['device_limit_note'] = 'Actual supported range comes from DSCAPS dwMinSecondarySampleRate/dwMaxSecondarySampleRate. Some systems do not support over 100000 Hz.'
        rows.append(row)
    # Use exactly the SDK declarations, with the selected DX9 member and the
    # byte packing explicitly set by mmreg.h for WAVEFORMATEX.
    definitions = {}
    wave, body = struct(files['mmreg.h'],'WAVEFORMATEX')
    definitions['WAVEFORMATEX'] = (wave,body,1)
    for name in ('DSBUFFERDESC','DSCAPS','DSBCAPS'):
        declaration,body = struct(header,name)
        declaration = re.sub(r'^#(?:if DIRECTSOUND_VERSION >= 0x0700|endif)\s*$', '',declaration,flags=re.M)
        body = re.sub(r'^#(?:if DIRECTSOUND_VERSION >= 0x0700|endif)\s*$', '',body,flags=re.M)
        definitions[name] = (declaration,body,8)
    guid,_ = struct(files['guiddef.h'],'GUID')
    prelude = 'typedef unsigned short WORD; typedef unsigned long DWORD;\n'+guid+'\ntypedef struct tWAVEFORMATEX *LPWAVEFORMATEX;\n'
    structures = layouts(definitions,prelude)
    for name,row in structures.items():
        file = 'mmreg.h' if name=='WAVEFORMATEX' else 'dsound.h'
        path = 'shared/' if name=='WAVEFORMATEX' else 'um/'
        pattern = r'^typedef struct '+('tWAVEFORMATEX' if name=='WAVEFORMATEX' else '_'+name)+r'\b'
        source = line_cite(files[file],pattern,SDK+path+file)
        row['packing'] = definitions[name][2]
        row['sources'] = {'declaration':source,'windows_types':LEARN+'winprog/windows-data-types',
                          'documentation':URLS['waveformatex.html']+'#syntax' if name=='WAVEFORMATEX' else ARCHIVE+STRUCT_DOCS[name]+'(v=vs.85)#syntax'}
        if name=='WAVEFORMATEX':
            row['sources']['packing'] = line_cite(files[file],r'^#include "pshpack1.h"',SDK+'shared/mmreg.h')
            row['size_note'] = '18-byte fixed header. cbSize counts extra bytes after this header; those bytes are not included here.'
        if name=='DSBUFFERDESC':
            row['version_scope'] = 'DIRECTSOUND_VERSION >= 0x0700, including DX9. guid3DAlgorithm is conditional in dsound.h.'
            row['sources']['guid'] = line_cite(files['guiddef.h'],r'^typedef struct _GUID\b',SDK+'shared/guiddef.h')
        for field in row['fields']:
            field['sources'] = {'header':source,'documentation':row['sources']['documentation']}
    out = {'_header':'Made by tools/census/dsound_consts.py; complete requested dsound.h macro groups; Clang evaluates HRESULT expressions and x86 Windows sizeof/offsetof on extracted SDK structures.',
           'limits':['FACT: SDK names, expressions, conditions and field declarations. INFERENCE: compile-time ABI sizes, offsets and HRESULT bit arithmetic.',
                     'Windows aliases use the _WIN32 branch of winerror.h, not its historical Macintosh HRESULT values.',
                     'Both conditional DSBFREQUENCY_MAX values are retained. Runtime device sample-rate support is unknown.',
                     'Layouts target 32-bit Windows for Speed.exe, not the 64-bit macOS host. DSBUFFERDESC uses the DX9 definition.',
                     'No sound was played and no game or device was executed.'],
           'layout_method':{'target':'i686-pc-windows-msvc','evaluation':'Clang sizeof, __alignof and __builtin_offsetof on extracted declarations',
                            'waveformatex_pack':1,'other_structure_pack':8,'pointer_bytes':4,
                            'primitive_types':{'WORD':'unsigned short (16-bit Windows)','DWORD':'unsigned long (32-bit Windows)','GUID':'extracted from shared/guiddef.h'}},
           'constant_method':{'target':'i686-pc-windows-msvc','command':'clang -target i686-pc-windows-msvc -x c -S -emit-llvm -o - -',
                              'evaluation':'SDK macro expressions compiled as unsigned long constants; low 32 bits are the HRESULT representation'},
           'counts':{'constant_records':len(rows),'distinct_constant_names':len({r['name'] for r in rows}),
                     'by_group':{g:sum(r['group']==g for r in rows) for g in GROUPS},'structures':len(structures),
                     'fields':sum(len(r['fields']) for r in structures.values()),'names_absent_from_doc_section':sum(not r['documented_name_present'] for r in rows)},
           'constants':rows,'structures':structures,
           'source_documents':[{'url':URLS[n],'sha256_text_utf8':hashlib.sha256(t.encode()).hexdigest()} for n,t in sorted(files.items())]}
    Path('census/dsound_consts.json').write_text(json.dumps(out,indent=2)+'\n')
    print('census/dsound_consts.json:',out['counts'])
    print('Structure sizes:',{n:r['size'] for n,r in structures.items()})


if __name__=='__main__':main()
