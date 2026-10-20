#!/usr/bin/env python3
"""Extract SDK instruction facts. Usage: python tools/census/d3d9_sm1.py [cache-dir]."""
import concurrent.futures
import hashlib
import html
import json
import re
import sys
import tempfile
import urllib.request
from pathlib import Path

DOCS = 'https://raw.githubusercontent.com/MicrosoftDocs/win32/docs/desktop-src/'
LEARN = 'https://learn.microsoft.com/en-us/windows/win32/'
HEADER_PATH = 'generation/WinSDK/RecompiledIdlHeaders/shared/d3d9types.h'
HEADER_RAW = 'https://raw.githubusercontent.com/microsoft/win32metadata/main/' + HEADER_PATH
HEADER_URL = 'https://github.com/microsoft/win32metadata/blob/main/' + HEADER_PATH
VS_INDEX = 'dx9-graphics-reference-asm-vs-instructions-vs-1-1.md'
PS_INDEX = 'dx9-graphics-reference-asm-ps-instructions-ps-1-x.md'
VS_MASK = 'dx9-graphics-reference-asm-vs-registers-modifiers-masking.md'
PS_MASK = 'dx9-graphics-reference-asm-ps-registers-modifiers-write-mask.md'
VS_SOURCE = 'dx9-graphics-reference-asm-vs-registers-modifiers-source.md'
PS_SOURCE = 'dx9-graphics-reference-asm-ps-registers-modifiers-source.md'
PS_SWIZZLE = 'dx9-graphics-reference-asm-ps-registers-modifiers-source-register-swizzling.md'
VS_SWIZZLE = 'dx9-graphics-reference-asm-vs-registers-modifiers-source-swizzling.md'


def fetch(cache, path):
    file = cache / Path(path).name
    if not file.exists():
        url = HEADER_RAW if path == 'd3d9types.h' else DOCS + path
        data = urllib.request.urlopen(url, timeout=40).read()
        file.write_bytes(data)
    return file.read_text(encoding='utf-8-sig')


def clean(text):
    text = re.sub(r'\[([^\]]*)\]\([^)]*\)', r'\1', text)
    text = re.sub(r'<[^>]*>', '', text)
    text = re.sub(r'\\([_#|\[\]-])', r'\1', text)
    return ' '.join(html.unescape(text).replace('**', '').replace('`', '').split())


def parse_enum(text, name):
    match = re.search(r'typedef\s+enum\s+(?:\w+\s*)?\{([^}]*)\}\s*'+re.escape(name)+r'\b',text,re.S)
    if not match:
        raise ValueError('Missing enum '+name)
    body = re.sub(r'/\*.*?\*/|//[^\n]*','',match[1],flags=re.S)
    result={};value=-1
    for item in body.split(','):
        item=item.strip()
        if not item:continue
        parts=item.split('=',1);key=parts[0].strip()
        if len(parts)==2:
            expression=parts[1].strip().replace('D3DSP_SRCMOD_SHIFT','24')
            if not re.fullmatch(r'[0-9a-fA-FxX()<>|+\s-]+',expression):raise ValueError(expression)
            value=eval(expression,{'__builtins__':{}},{})
        else:value+=1
        result[key]=value
    return result


def cite(file, section):
    return LEARN+'direct3dhlsl/'+file.removesuffix('.md')+'#'+section


def header_cite(header, identifier):
    line=header[:header.index(identifier)].count('\n')+1
    return HEADER_URL+f'#L{line}'


def table_rows(text):
    for line in text.splitlines():
        if not line.startswith('| ['):continue
        link=re.search(r'^\| \[([^\]]+)\]\(([^)]+\.md)\)',line)
        if link:
            # Split only unescaped pipes; descriptions contain no literal pipe.
            cells=re.split(r'(?<!\\)\|',line)[1:-1]
            yield clean(link[1]),link[2],[clean(c) for c in cells]


def syntax(text, mnemonic):
    section=text.split('## Syntax\n',1)[1].split('\n## ',1)[0] if '## Syntax\n' in text else text.split('## Registers',1)[0]
    for line in section.splitlines():
        if re.match(r'^\|\s*[a-z]',line):return clean(line.strip().strip('|'))
    code=re.search(r'```[^\n]*\n([^\n]+)',section)
    if code:return clean(code[1])
    if mnemonic=='dcl_usage':return 'dcl_usage[usage_index] v#'
    return 'unknown'


def main():
    cache=Path(sys.argv[1] if len(sys.argv)>1 else Path(tempfile.gettempdir())/'nfsu-c1-sdk')
    cache.mkdir(parents=True,exist_ok=True)
    files={name:fetch(cache,'direct3dhlsl/'+name) for name in (VS_INDEX,PS_INDEX,VS_MASK,PS_MASK,VS_SOURCE,PS_SOURCE,PS_SWIZZLE,VS_SWIZZLE)}
    entries=[]
    for stage,index in (('vs',VS_INDEX),('ps',PS_INDEX)):
        category='setup'
        for line in files[index].splitlines():
            if 'Arithmetic instructions' in line:category='arithmetic'
            if 'Texture instructions' in line:category='texture'
            for label,file,cells in table_rows(line):
                name='dcl_usage' if label.startswith('dcl_') else label.split(' ')[0]
                entries.append((stage,index,name,file,cells,category))
    names=sorted({e[3] for e in entries})
    with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
        for name,data in zip(names,pool.map(lambda n:fetch(cache,'direct3dhlsl/'+n),names)):files[name]=data
    header=fetch(cache,'d3d9types.h')
    opcodes=parse_enum(header,'D3DSHADER_INSTRUCTION_OPCODE_TYPE')
    by_lower={k.lower():k for k in opcodes}
    instructions=[]
    for stage,index,name,file,cells,category in entries:
        text=files[file]
        supported=['vs_1_1'] if stage=='vs' else ['ps_1_'+str(i+1) for i,value in enumerate(cells[3:7]) if value.lower()=='x']
        signature=syntax(text,name)
        operands=signature.partition(' ')[2]
        operand_count=0 if not operands else len(operands.split(','))
        if signature=='unknown':operand_count='unknown'
        if name=='dcl_usage':operand_count=1
        if name in ('vs','ps','phase'):operand_count=0
        if stage=='vs' and name not in ('vs','dcl_usage','def'):category='arithmetic'
        sdk_name={'texld':'D3DSIO_TEX','texcrd':'D3DSIO_TEXCOORD','dcl_usage':'D3DSIO_DCL'}.get(name)
        if sdk_name is None:sdk_name=by_lower.get('d3dsio_'+name)
        token=opcodes.get(sdk_name,'unknown')
        if name in ('vs','ps'):token='not_applicable; version token'
        masks={};source_rules={}
        for profile in supported:
            if name in ('vs','ps','nop','phase','dcl_usage'):
                masks[profile]='not_applicable'
            elif name=='def':masks[profile]='unknown; constant definition, not an ALU write'
            elif stage=='vs':
                masks[profile]='ordered xyzw subset; output-register constraints apply'
                if name in ('exp','expp','log','logp','rcp','rsq'):masks[profile]='single component per generic mask reference; see documented conflicts'
                if name=='frc':masks[profile]=['.y','.xy']
                if name=='m3x2':masks[profile]=['.xy']
                if name in ('m3x3','m4x3'):masks[profile]=['.xyz']
                if name in ('m3x4','m4x4'):masks[profile]=['.xyzw']
            elif category=='texture':
                masks[profile]='no explicit destination mask'
                if name=='texcrd':masks[profile]='.rgb for xyz/xyw; .rg for xyw_dw; other channels undefined'
                if name=='texld':masks[profile]='none explicitly shown in the complete syntax list; generic mask page differs'
            else:
                masks[profile]=['.rgba','.rgb','.a'] if profile!='ps_1_4' else 'any nonempty ordered rgba subset'
                if name=='dp3' and profile!='ps_1_4':masks[profile]=['.rgb','.rgba']
                if name=='bem':masks[profile]=['.rg']
            source_rules[profile]='vs_source' if stage=='vs' else ('ps_texture_source' if category=='texture' else 'ps_arithmetic_source')
        if name in ('vs','ps','nop','phase','def','dcl_usage'):source_rules={p:'not_applicable' for p in supported}
        slots={p:cells[2] for p in supported}
        if name in ('cmp','dp4') and stage=='ps':slots={p:(1 if p=='ps_1_4' else 2) for p in supported}
        if name=='texbeml':slots={p:{'arithmetic':1,'texture':1} for p in supported}
        record={'stage':stage,'mnemonic':name,'category':category,'sdk_opcode_name':sdk_name or 'not_applicable',
                'opcode_token':token,'opcode_hex':f'0x{token:04x}' if isinstance(token,int) else 'unknown',
                'syntax':signature,'operand_count':operand_count,
                'operand_count_scope':'assembly operands including destination/immediates; excludes opcode and implicit operands',
                'supported_profiles':supported,'ps_1_0_support':'unknown; not in SDK index' if stage=='ps' else 'not_applicable',
                'instruction_slots':slots,'destination_write_masks':masks,'source_modifiers':source_rules,
                'sources':{'syntax':cite(file,'syntax'),'version_limits':cite(index,'instruction-set'),
                           'masks':cite(VS_MASK if stage=='vs' else PS_MASK,'remarks' if stage=='ps' else 'destination-register-masking'),
                           'instruction_specific_rules':cite(file,'remarks')}}
        if sdk_name:record['sources']['opcode_token']=header_cite(header,sdk_name)
        if name=='texm3x2pad':record['documentation_note']='Syntax cell spells tex3x2pad; index and title spell texm3x2pad. Operand count comes from that cell.'
        if name in ('texld','texcrd'):record['opcode_alias_source']='https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/d3d9types/ne-d3d9types-_d3dshader_instruction_opcode_type#constants'
        if name.startswith('m') and re.fullmatch(r'm[34]x[234]',name):
            record['source_operand_restrictions']={'src1':'no negate or swizzle','source':cite(file,'remarks')}
        if re.search(r'replicate swizzle',text,re.I):record['source_swizzle_requirement']={'rule':'explicit single-component replicate','source':cite(file,'syntax')}
        if name=='dcl_usage':record['bytecode_encoding']='unknown for vs_1_1; assembly input declaration is not evidence of a shader-stream DCL token'
        if stage=='vs' and name in ('exp','log','frc','m3x2','m3x3','m3x4','m4x3','m4x4'):
            record['assembly_note']='SDK index charges multiple instruction slots; enum opcode does not prove the assembler emits one token. Expansion was not executed.'
        if name=='bem':record['version_restrictions']={'ps_1_4':{'phase':1,'maximum_uses':1,'coissue':False},'source':cite(file,'remarks')}
        if name=='texdepth':record['version_restrictions']={'ps_1_4':{'register':'r5','after_phase':True,'r5_afterward':'unavailable'},'source':cite(file,'remarks')}
        if name=='texld':record['version_restrictions']={'ps_1_4':{'dz_source':'r# in phase 2','maximum_dz_uses':2,'t_reads':'same xyz or xyw selection per register'},'source':cite(file,'remarks')}
        instructions.append(record)
    modifiers=[]
    for name,value in parse_enum(header,'D3DSHADER_PARAM_SRCMOD_TYPE').items():
        short=name.removeprefix('D3DSPSM_')
        if short not in ('NONE','NEG','BIAS','BIASNEG','SIGN','SIGNNEG','COMP','X2','X2NEG','DZ','DW'):continue
        profiles=['ps_1_1','ps_1_2','ps_1_3','ps_1_4']
        if short in ('X2','X2NEG','DZ','DW'):profiles=['ps_1_4']
        if short in ('NONE','NEG'):profiles=['vs_1_1']+profiles
        modifiers.append({'name':name,'encoded_bits':value,'encoded_hex':f'0x{value:08x}','field_value':value>>24,
                          'supported_profiles':profiles,'sources':[header_cite(header,name),cite(PS_SOURCE,'ps_1_1---ps_1_4'),cite(VS_SOURCE,'negate')]})
    writebits=[]
    for key in ['D3DSP_WRITEMASK_'+str(i) for i in range(4)]+['D3DSP_WRITEMASK_ALL']:
        match=re.search(r'#define\s+'+key+r'\s+(0x[0-9a-fA-F]+)',header)
        writebits.append({'name':key,'value':int(match[1],16),'source':header_cite(header,key)})
    out={'_header':'Made by tools/census/d3d9_sm1.py; mechanical SDK Markdown tables and syntax, plus Microsoft SDK d3d9types.h.',
         'limits':['FACT: enum numbers, literal syntax and support-table cells. Rules are scoped to the cited sections.',
                   'No compiler or game was executed. Assembler expansion and undocumented behavior remain unknown.',
                   'ps_1_0 is requested but absent from the DX9 SDK profile index; its instruction support is unknown.'],
         'profile_version_tokens':{'vs_1_1':0xfffe0101,**{'ps_1_'+str(i):0xffff0100+i for i in range(1,5)},'ps_1_0':0xffff0100},
         'version_token_source':header_cite(header,'D3DPS_VERSION'),
         'rules':{
             'vs_source':{'modifiers':['NONE','NEG'],'matrix_src1':'no negate/swizzle','sources':[cite(VS_SOURCE,'negate'),cite(VS_SWIZZLE,'source-register-swizzling')]},
             'ps_arithmetic_source':{'base':['NONE','NEG','BIAS','BIASNEG','SIGN','SIGNNEG','COMP'],'ps_1_4_adds':['X2','X2NEG'],
                  'constants':'modifiers undefined in 1_1..1_3; validation failure in 1_4','combinations':'NEG after BIAS/SIGN/X2; COMP excludes other arithmetic modifiers',
                  'source':cite(PS_SOURCE,'ps_1_1---ps_1_4')},
             'ps_texture_source':{'general':'no arithmetic modifiers','ps_1_1_exception':'SIGN on texm* source','ps_1_2_1_3_exception':'SIGN on texture-address source',
                  'ps_1_4':'texcrd t#_dw.xyw; texld t#_dw.xyw or r#_dz.xyz; see instruction-specific limits',
                  'sources':[cite(PS_SOURCE,'ps_1_1---ps_1_4'),cite('texcrd---ps.md','examples'),cite('texld---ps-1-4.md','examples')]},
             'ps_swizzle':{'ps_1_1_1_2_1_3':['identity','replicate .w','replicate .z subject to the SDK table footnote (unknown exact restriction)'],
                  'ps_1_4':['identity','single-channel .x/.y/.z/.w replicate'],'source':cite(PS_SWIZZLE,'remarks')},
             'vs_output_masks':{'a0':'.x; mov only','oT#':'aggregate prefix .x/.xy/.xyz/.xyzw; preceding oT registers also written',
                  'oFog_oPts':'generic VS and PS mask pages differ on explicit scalar masks; unknown resolution',
                  'sources':[cite(VS_MASK,'texture-register-masks'),cite(PS_MASK,'remarks')]},
         },'write_mask_bits':writebits,'source_modifier_tokens':modifiers,'instructions':instructions,
         'stream_tokens':[{'name':n,'opcode_token':opcodes['D3DSIO_'+n.upper()],'operand_count':('variable; size encoded in comment token' if n=='comment' else 0),
                           'source':header_cite(header,'D3DSIO_'+n.upper())} for n in ('end','comment')],
         'documentation_conflicts':[
             {'topic':'m4x4 src0 modifiers','status':'unknown','sources':[cite('m4x4---vs.md','remarks')],'detail':'Consecutive sentences both allow and forbid src0 negate/swizzle.'},
             {'topic':'m3x4/m4x4 masks','status':'unknown','sources':[cite(VS_MASK,'destination-register-masking'),cite('m4x4---vs.md','remarks'),cite('m3x4---vs.md','remarks')],'detail':'Generic page allows xyz or xyzw; individual instruction pages require xyzw. Records retain the specific rule.'},
             {'topic':'expp/logp scalar masks','status':'unknown','sources':[cite(VS_MASK,'destination-register-masking'),cite('expp---vs.md','remarks'),cite('logp---vs.md','remarks')],'detail':'Generic page says single component; vs_1_1 instruction pages describe four distinct results.'},
             {'topic':'ps_1_4 texld destination mask','status':'unknown','sources':[cite(PS_MASK,'remarks'),cite('texld---ps-1-4.md','examples')],'detail':'Generic exception permits masking; the instruction complete-syntax list shows no explicit destination masks.'}],
         'source_documents':[{'url':LEARN+'direct3dhlsl/'+n.removesuffix('.md'),'sha256_text_utf8':hashlib.sha256(t.encode('utf-8')).hexdigest()} for n,t in sorted(files.items())]+[{'url':HEADER_URL,'sha256_text_utf8':hashlib.sha256(header.encode('utf-8')).hexdigest()}],
         'counts':{'instructions':len(instructions),'vs_index_rows':sum(r['stage']=='vs' for r in instructions),'ps_index_rows':sum(r['stage']=='ps' for r in instructions),'source_modifiers':len(modifiers)}}
    Path('census/d3d9_sm1.json').write_text(json.dumps(out,indent=2)+'\n')
    print('census/d3d9_sm1.json:',out['counts'])


if __name__=='__main__':main()
