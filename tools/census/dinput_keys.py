#!/usr/bin/env python3
"""Census SDK DirectInput keys and mouse layouts. Usage: python ... [cache-dir]."""
import hashlib
import json
import re
import subprocess
import sys
import urllib.request
from pathlib import Path

from d3d9_sm1 import clean

SDK = 'https://github.com/microsoft/win32metadata/blob/main/generation/WinSDK/RecompiledIdlHeaders/'
RAW = SDK.replace('github.com', 'raw.githubusercontent.com').replace('/blob/', '/')
LEARN = 'https://learn.microsoft.com/en-us/windows/win32/'
ARCHIVE = 'https://learn.microsoft.com/en-us/previous-versions/windows/desktop/'
W3C = 'https://www.w3.org/TR/uievents-code/'
URLS = {'dinput.h':RAW+'um/dinput.h', 'WinUser.h':RAW+'um/WinUser.h',
        'uievents-code.html':W3C,
        'virtual-key-codes.md':'https://raw.githubusercontent.com/MicrosoftDocs/win32/docs/desktop-src/inputdev/virtual-key-codes.md',
        'about-keyboard-input.md':'https://raw.githubusercontent.com/MicrosoftDocs/win32/docs/desktop-src/inputdev/about-keyboard-input.md',
        **{n+'.html':ARCHIVE+n+'(v=vs.85)' for n in ('ee418271','ee416630','ee416631')}}


def load(cache, name, url):
    file = cache/name
    if not file.exists():file.write_bytes(urllib.request.urlopen(url, timeout=40).read())
    return file.read_text(encoding='utf-8-sig')


def line_cite(text, pattern, url):
    match = re.search(pattern, text, re.M)
    if not match:raise ValueError('Missing source: '+pattern)
    return url+'#L'+str(text[:match.start()].count('\n')+1)


def struct(text, name):
    match = re.search(r'typedef struct (\w+)\s*\{([^}]+)\}\s*'+name+r'\b[^;]*;', text, re.S)
    if not match:raise ValueError('Missing struct '+name)
    return match[0], match[2]


def layouts(definitions, prelude):
    # Evaluate the SDK declarations with the x86 Windows ABI, not the host ABI.
    code = prelude+'\n'
    fields = {}
    for name, (declaration, body, pack) in definitions.items():
        code += f'\n#pragma pack(push, {pack})\n'+declaration+'\n#pragma pack(pop)\n'
        body = re.sub(r'/\*.*?\*/|//[^\n]*', '', body, flags=re.S)
        fields[name] = []
        for decl in body.split(';'):
            decl = decl.strip()
            if not decl:continue
            match = re.fullmatch(r'(\w+)\s+(\w+)\s*(\[\s*\d+\s*\])?', decl)
            if not match:raise ValueError(decl)
            fields[name].append((match[2],match[1]+(match[3] or '')))
        code += f'enum {{SIZE_{name}=sizeof({name}), ALIGN_{name}=__alignof({name})}};\n'
        for field, _ in fields[name]:
            code += f'enum {{OFFSET_{name}_{field}=__builtin_offsetof({name},{field}), SIZE_{name}_{field}=sizeof((({name}*)0)->{field})}};\n'
    command = ['clang','-target','i686-pc-windows-msvc','-x','c','-fsyntax-only','-Xclang','-ast-dump=json','-']
    result = subprocess.run(command, input=code, text=True, capture_output=True, check=True)
    ast = json.loads(result.stdout)
    values = {}
    def walk(node):
        if node.get('kind') == 'EnumConstantDecl':
            def value(item):
                if item.get('kind') == 'ConstantExpr':return int(item['value'])
                for child in item.get('inner',[]):
                    found = value(child)
                    if found is not None:return found
            values[node['name']] = value(node)
        for child in node.get('inner',[]):walk(child)
    walk(ast)
    return {name:{'size':values['SIZE_'+name], 'alignment':values['ALIGN_'+name],
            'fields':[{'name':field,'type':typ,'offset':values[f'OFFSET_{name}_{field}'],'size':values[f'SIZE_{name}_{field}']} for field,typ in members]}
            for name,members in fields.items()}


# These pairs join the physical-key descriptions in the cited SDK, Win32 and
# W3C tables. This is not a conversion of a typed character or active layout.
CODES = dict(item.split(':') for item in '''ESCAPE:Escape MINUS:Minus EQUALS:Equal BACK:Backspace TAB:Tab LBRACKET:BracketLeft RBRACKET:BracketRight RETURN:Enter LCONTROL:ControlLeft SEMICOLON:Semicolon APOSTROPHE:Quote GRAVE:Backquote LSHIFT:ShiftLeft BACKSLASH:Backslash COMMA:Comma PERIOD:Period SLASH:Slash RSHIFT:ShiftRight MULTIPLY:NumpadMultiply LMENU:AltLeft SPACE:Space CAPITAL:CapsLock NUMLOCK:NumLock SCROLL:ScrollLock SUBTRACT:NumpadSubtract ADD:NumpadAdd DECIMAL:NumpadDecimal OEM_102:IntlBackslash KANA:KanaMode CONVERT:Convert NOCONVERT:NonConvert YEN:IntlYen NUMPADEQUALS:NumpadEqual PREVTRACK:MediaTrackPrevious NEXTTRACK:MediaTrackNext NUMPADENTER:NumpadEnter RCONTROL:ControlRight MUTE:AudioVolumeMute CALCULATOR:LaunchApp2 PLAYPAUSE:MediaPlayPause MEDIASTOP:MediaStop VOLUMEDOWN:AudioVolumeDown VOLUMEUP:AudioVolumeUp WEBHOME:BrowserHome NUMPADCOMMA:NumpadComma DIVIDE:NumpadDivide SYSRQ:PrintScreen RMENU:AltRight PAUSE:Pause HOME:Home UP:ArrowUp PRIOR:PageUp LEFT:ArrowLeft RIGHT:ArrowRight END:End DOWN:ArrowDown NEXT:PageDown INSERT:Insert DELETE:Delete LWIN:MetaLeft RWIN:MetaRight APPS:ContextMenu POWER:Power SLEEP:Sleep WAKE:WakeUp WEBSEARCH:BrowserSearch WEBFAVORITES:BrowserFavorites WEBREFRESH:BrowserRefresh WEBSTOP:BrowserStop WEBFORWARD:BrowserForward WEBBACK:BrowserBack MYCOMPUTER:LaunchApp1 MAIL:LaunchMail MEDIASELECT:MediaSelect ABNT_C2:NumpadComma'''.split())
# Only rename a key to a VK whose documentation describes that key. OEM
# punctuation is scoped to the US layout. No VK_A/VK_1 identifiers are invented.
VKS = dict(item.split(':') for item in '''BACK:BACK NOCONVERT:NONCONVERT SYSRQ:SNAPSHOT NUMPADENTER:RETURN PREVTRACK:MEDIA_PREV_TRACK NEXTTRACK:MEDIA_NEXT_TRACK MUTE:VOLUME_MUTE CALCULATOR:LAUNCH_APP2 PLAYPAUSE:MEDIA_PLAY_PAUSE MEDIASTOP:MEDIA_STOP VOLUMEDOWN:VOLUME_DOWN VOLUMEUP:VOLUME_UP WEBHOME:BROWSER_HOME WEBSEARCH:BROWSER_SEARCH WEBFAVORITES:BROWSER_FAVORITES WEBREFRESH:BROWSER_REFRESH WEBSTOP:BROWSER_STOP WEBFORWARD:BROWSER_FORWARD WEBBACK:BROWSER_BACK MYCOMPUTER:LAUNCH_APP1 MAIL:LAUNCH_MAIL MEDIASELECT:LAUNCH_MEDIA_SELECT MINUS:OEM_MINUS EQUALS:OEM_PLUS LBRACKET:OEM_4 RBRACKET:OEM_6 SEMICOLON:OEM_1 APOSTROPHE:OEM_7 GRAVE:OEM_3 BACKSLASH:OEM_5 COMMA:OEM_COMMA PERIOD:OEM_PERIOD SLASH:OEM_2'''.split())


def main():
    cache = Path(sys.argv[1] if len(sys.argv)>1 else '/tmp/nfsu-c1-sdk')
    cache.mkdir(parents=True, exist_ok=True)
    files = {name:load(cache,name,url) for name,url in URLS.items()}
    header = files['dinput.h']; vkheader = files['WinUser.h']; doc = files['about-keyboard-input.md']
    defines = re.findall(r'^#define\s+(DIK_\w+)\s+(0x[\dA-Fa-f]+|DIK_\w+)(?:\s*/\*([^\n]*?)\*/)?',header,re.M)
    values = {}; rows = []
    vkvalues = {n:int(v,16) for n,v in re.findall(r'^#define\s+(VK_\w+)\s+(0x[\dA-Fa-f]+)',vkheader,re.M)}
    scans = []
    for line in doc.splitlines():
        if not line.startswith('|') or not re.search(r'\|\s*0x[\da-fA-F]{4}\s*\|',line):continue
        cells = [clean(c.replace('<br>', ' ')) for c in line.strip('|').split('|')]
        if len(cells) != 6:continue
        scans.append({'usage_page':cells[2], 'usage_id':cells[3], 'name':cells[1],
                      'make_codes':re.findall(r'0x[\da-fA-F]+',cells[4]), 'notes':cells[4]})
    w3c = set(re.findall(r'id="code-([A-Za-z0-9]+)"',files['uievents-code.html']))
    for name, expression, comment in defines:
        alias = expression if expression.startswith('DIK_') else None
        value = values[expression] if alias else int(expression,16)
        values[name] = value
        short = (alias or name).removeprefix('DIK_')
        code = CODES.get(short,'unknown')
        if re.fullmatch(r'[A-Z]',short):code = 'Key'+short
        if re.fullmatch(r'\d',short):code = 'Digit'+short
        if re.fullmatch(r'F\d+|NUMPAD\d',short):code = short.title()
        # Circumflex shares a numeric value with PreviousTrack, not a meaning.
        if name == 'DIK_CIRCUMFLEX':short = 'CIRCUMFLEX'; code = 'unknown'
        extra_function = bool(re.fullmatch(r'F(?:1[3-9]|2[0-4])', code))
        assert code == 'unknown' or code in w3c or extra_function, code
        candidate = f'0x{value:04X}' if value<128 else f'0xE0{value&127:02X}'
        matched = [s for s in scans if candidate in s['make_codes']]
        if short == 'PAUSE':matched = [s for s in scans if s['name']=='Keyboard Pause']
        if short == 'NUMLOCK':matched = [s for s in scans if s['name']=='Keypad Num Lock and Clear']
        # These are legacy Japanese/NEC constants; their high bit does not
        # establish a modern E0 scan code. Avoid a value-only collision.
        if short in ('AT','COLON','UNDERLINE','KANJI','STOP','AX','UNLABELED','NUMPADEQUALS','NUMPADCOMMA','CIRCUMFLEX'):
            matched = []
        vkname = 'VK_'+VKS.get(short,short)
        vk = 'unknown'
        if re.fullmatch(r'[A-Z0-9]',short):
            vk = {'name':'not_applicable; literal '+repr(short),'value':ord(short),'hex':f'0x{ord(short):02x}','scope':'US keyboard layout'}
        elif vkname in vkvalues and code!='unknown':
            vk = {'name':vkname,'value':vkvalues[vkname],'hex':f'0x{vkvalues[vkname]:02x}',
                  'scope':'US layout for OEM punctuation; key meaning for other keys'}
        # ABNT codes are in the SDK header, but not in the public VK page.
        if short in ('ABNT_C1','ABNT_C2'):vk = 'unknown'
        sources = {'dik':line_cite(header,r'^#define\s+'+name+r'\s',SDK+'um/dinput.h'),
                   'physical_key_semantics':ARCHIVE+'ee418271(v=vs.85)',
                   'virtual_key':LEARN+'inputdev/virtual-key-codes',
                   'scan_code':LEARN+'inputdev/about-keyboard-input#scan-codes',
                   'keyboard_event_code':W3C+('#code-'+code if code!='unknown' else '#code-value-tables')}
        if extra_function:sources['keyboard_event_code'] = W3C+'#key-function-section'
        if isinstance(vk,dict) and vk['name'].startswith('VK_'):
            sources['vk_header'] = line_cite(vkheader,r'^#define\s+'+vkname+r'\s',SDK+'um/WinUser.h')
        row = {'name':name,'value':value,'value_hex':f'0x{value:02x}',
               'alias_of':alias or 'not_applicable','sdk_key_description':clean(comment or short),
               'virtual_key':vk,'win32_scan_code':matched or 'unknown','keyboard_event_code':code,
               'match_status':'INFERENCE: join of physical-key descriptions; not a runtime layout mapping', 'sources':sources}
        if re.fullmatch(r'NUMPAD\d',short) or short=='DECIMAL':
            row['virtual_key_note'] = 'NumLock-on numeric interpretation. Navigation interpretation depends on NumLock and Shift.'
        if vk=='unknown':row['vk_unknown_reason'] = 'No unambiguous match in the cited VK table for this physical or legacy key.'
        if not matched:row['scan_unknown_reason'] = 'No unambiguous Scan 1 Make entry in the cited Win32 table for this DIK key.'
        rows.append(row)
    # Field order comes from dinput.h. Sizes and offsets come from Clang's x86
    # Windows layout of those declarations, using documented Windows types.
    definitions = {}
    for name in ('DIMOUSESTATE','DIMOUSESTATE2'):
        declaration,body = struct(header,name); definitions[name] = (declaration,body,8)
    mouse = layouts(definitions,'typedef long LONG; typedef unsigned char BYTE;')
    for name,row in mouse.items():
        source = line_cite(header,r'^typedef struct _'+name+r'\b',SDK+'um/dinput.h')
        row['sources'] = {'declaration':source,'types':LEARN+'winprog/windows-data-types','docs':ARCHIVE+('ee416630' if name=='DIMOUSESTATE' else 'ee416631')+'(v=vs.85)#syntax'}
        for field in row['fields']:field['source'] = source
    offsets = []
    for name, expression in re.findall(r'^#define\s+(DIMOFS_\w+)\s+([^\n]+)',header,re.M):
        match = re.search(r'FIELD_OFFSET\((\w+),\s*(\w+)\)(?:\s*\+\s*(\d+))?',expression)
        assert match,name
        typename,field,delta = match.groups()
        offset = next(f['offset'] for f in mouse[typename]['fields'] if f['name']==field)+int(delta or 0)
        offsets.append({'name':name,'value':offset,'expression':expression.strip(),
                        'source':line_cite(header,r'^#define\s+'+name+r'\s',SDK+'um/dinput.h')})
    out = {'_header':'Made by tools/census/dinput_keys.py; all SDK DIK/DIMOFS definitions; joins to Win32 physical-key descriptions and W3C code sections; mouse layouts evaluated by Clang for x86 Windows.',
           'limits':['FACT: SDK constants, aliases and declarations. INFERENCE: cross-document physical-key matches and ABI arithmetic.',
                     'DirectInput scan codes, Win32 Scan 1 Make sequences and VKs are distinct domains. No universal high-bit conversion is asserted.',
                     'VKs depend on keyboard layout and toggle state. Letters/OEM punctuation use the US layout; numeric keypad VKs show NumLock-on meanings.',
                     'Legacy or unmatched keys are unknown. Alias DIK_CIRCUMFLEX is not assigned the media-key meaning of its numeric alias.',
                     'No browser or game input was executed.'],
           'layout_method':{'target':'i686-pc-windows-msvc','packing':8,'compiler':'clang -target i686-pc-windows-msvc -x c -fsyntax-only -Xclang -ast-dump=json -',
                            'evaluation':'sizeof, __alignof and __builtin_offsetof on extracted SDK declarations','primitive_types':{'LONG':'signed long (32-bit Windows)','BYTE':'unsigned char (8-bit)'}},
           'counts':{'dik_names':len(rows),'distinct_dik_values':len(set(values.values())),'aliases':sum(r['alias_of']!='not_applicable' for r in rows),
                     'unknown_vk':sum(r['virtual_key']=='unknown' for r in rows),'unknown_scan':sum(r['win32_scan_code']=='unknown' for r in rows),
                     'unknown_keyboard_event_code':sum(r['keyboard_event_code']=='unknown' for r in rows),'mouse_offsets':len(offsets),'mouse_structures':len(mouse)},
           'keys':rows,'mouse_offsets':offsets,'mouse_structures':mouse,
           'source_documents':[{'url':URLS[n],'sha256_text_utf8':hashlib.sha256(t.encode()).hexdigest()} for n,t in files.items()]}
    Path('census/dinput_keys.json').write_text(json.dumps(out,indent=2)+'\n')
    print('census/dinput_keys.json:',out['counts'])


if __name__=='__main__':main()
