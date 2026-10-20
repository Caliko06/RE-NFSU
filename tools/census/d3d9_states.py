#!/usr/bin/env python3
"""Extract all three D3D9 state enums and the defaults stated in SDK docs."""
import hashlib
import json
import re
import sys
import tempfile
from pathlib import Path

from d3d9_sm1 import HEADER_URL, LEARN, clean, fetch, header_cite, parse_enum

ENUMS = {'D3DRENDERSTATETYPE':'d3drenderstatetype.md',
         'D3DSAMPLERSTATETYPE':'d3dsamplerstatetype.md',
         'D3DTEXTURESTAGESTATETYPE':'d3dtexturestagestatetype.md'}
TOKEN = r'(?:D3D[A-Z0-9_]+|TRUE|FALSE|0x[0-9a-fA-F]+|[0-9]+(?:\.[0-9]+)?f?|zero)'


def documented_default(name, body):
    # These three definitions are conditional in the documentation. Keep the
    # condition rather than turning it into one guessed initialization value.
    if name.endswith('_FORCE_DWORD'):
        return {'kind':'sentinel','value':'not_applicable; not a state'}
    if name=='D3DRS_ZENABLE':
        return {'kind':'conditional','value':{'EnableAutoDepthStencil=TRUE':'D3DZB_TRUE','otherwise':'D3DZB_FALSE'}}
    if name=='D3DRS_POINTSIZE':
        return {'kind':'device_dependent','value':'driver return value; 64 if driver returns 0 or 1','numeric_value':'unknown'}
    if name in ('D3DTSS_COLOROP','D3DTSS_ALPHAOP'):
        tokens=re.findall(r'D3DTOP_[A-Z0-9_]+',body)
        return {'kind':'stage_dependent','value':{'stage_0':tokens[0],'other_stages':tokens[1]}}
    if name=='D3DTSS_ALPHAARG1':
        tokens=re.findall(r'default argument is ('+TOKEN+r')',body)
        return {'kind':'conditional','value':{'texture_bound':tokens[0],'no_texture':tokens[1]}}
    if name=='D3DTSS_TEXCOORDINDEX':
        return {'kind':'stage_dependent','value':'stage index'}
    # Look only at the default clause, not other register defaults in the same
    # description. The first clause describes the state itself.
    match=re.search(r'\bdefault(?: value| argument| color| mask)?(?: of this parameter| for this render state)? (?:is|to) ('+TOKEN+r')\b',body,re.I)
    if not match:match=re.search(r'\bdefaults to ('+TOKEN+r')\b',body,re.I)
    if not match:match=re.search(r'\b('+TOKEN+r') \((?:the )?default(?: value)?\)',body,re.I)
    if not match:
        match=re.search(r'default value is [^.]*\((0x[0-9a-fA-F]+)\)',body,re.I)
    if not match:
        return {'kind':'unknown','value':'unknown; not stated in this enumerator section'}
    literal=match[1]
    if literal=='zero':return {'kind':'numeric','value':0,'documented_literal':'zero'}
    if literal in ('TRUE','FALSE'):return {'kind':'boolean','value':literal}
    if literal.startswith('D3D'):return {'kind':'enum_or_flag','value':literal}
    if literal.lower().startswith('0x'):return {'kind':'numeric','value':int(literal,16),'documented_literal':literal}
    return {'kind':'numeric','value':float(literal.rstrip('f')) if '.' in literal else int(literal),'documented_literal':literal}


def main():
    cache=Path(sys.argv[1] if len(sys.argv)>1 else Path(tempfile.gettempdir())/'nfsu-c1-sdk')
    cache.mkdir(parents=True,exist_ok=True)
    header=fetch(cache,'d3d9types.h')
    rows=[];sources=[]
    for enum,file in ENUMS.items():
        text=fetch(cache,'direct3d9/'+file)
        definitions=parse_enum(text,enum)
        sdk_definitions=parse_enum(header,enum)
        assert definitions==sdk_definitions, f'{enum}: SDK header and documentation enum differ'
        bodies={m[1]:clean(m[2]) for m in re.finditer(r'<span id="((?:D3DRS|D3DSAMP|D3DTSS)_[A-Z0-9_]+)"[^>]*>.*?</dt>\s*<dd>(.*?)</dd>',text,re.S)}
        assert definitions.keys()==bodies.keys(),f'{enum}: missing enumerator sections'
        for name,value in definitions.items():
            default=documented_default(name,bodies[name])
            inherited=None
            if default['kind']=='unknown':
                # WRAP1..15 explicitly refer to WRAP0; follow that link only.
                inherited_match=re.fullmatch(r'See (D3DRS_WRAP0)\.',bodies[name])
                if inherited_match:
                    inherited=inherited_match[1]
                    default=documented_default(inherited,bodies[inherited])
            source=LEARN+'direct3d9/'+file.removesuffix('.md')+'#'+name.lower()
            row={'enum':enum,'name':name,'id':value,'id_hex':f'0x{value:08x}',
                 'documented_default':default,'sources':{'id':LEARN+'direct3d9/'+file.removesuffix('.md')+'#syntax','default':source,'sdk_id':header_cite(header,name)}}
            if inherited:row['sources']['inherited_default']=LEARN+'direct3d9/'+file.removesuffix('.md')+'#'+inherited.lower()
            rows.append(row)
        sources.append({'url':LEARN+'direct3d9/'+file.removesuffix('.md'),'sha256_text_utf8':hashlib.sha256(text.encode('utf-8')).hexdigest()})
    sources.append({'url':HEADER_URL,'sha256_text_utf8':hashlib.sha256(header.encode('utf-8')).hexdigest()})
    out={'_header':'Made by tools/census/d3d9_states.py; SDK enum syntax and per-enumerator default clauses, cross-checked against Microsoft d3d9types.h.',
         'limits':['All IDs and literal defaults are FACT from cited sections. Conditional and driver-dependent defaults remain conditional.',
                   'No runtime state was measured. Unknown defaults are not initialized to zero by assumption.',
                   'FORCE_DWORD entries are included for enum completeness and are not settable states.'],
         'counts':{'enum_entries':len(rows),'states':sum(r['documented_default']['kind']!='sentinel' for r in rows),
                   'by_enum':{enum:sum(r['enum']==enum for r in rows) for enum in ENUMS},
                   'unknown_defaults':sum(r['documented_default']['kind']=='unknown' for r in rows)},
         'states':rows,'source_documents':sources}
    Path('census/d3d9_states.json').write_text(json.dumps(out,indent=2)+'\n')
    print('census/d3d9_states.json:',json.dumps(out['counts']))
    print('unknown defaults:',[r['name'] for r in rows if r['documented_default']['kind']=='unknown'])


if __name__=='__main__':main()
