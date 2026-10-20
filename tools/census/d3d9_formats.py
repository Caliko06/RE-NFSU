#!/usr/bin/env python3
"""Extract every D3DFORMAT and derive channel fields from SDK format notation."""
import hashlib
import json
import re
import sys
from pathlib import Path

from d3d9_sm1 import HEADER_URL, LEARN, clean, fetch, header_cite

DOC = LEARN + 'direct3d9/d3dformat'
COMP = LEARN + 'direct3d9/compressed-texture-formats'


def enum(text):
    body = re.search(r'typedef enum _D3DFORMAT\s*\{(.*?)\}\s*D3DFORMAT;', text, re.S)[1]
    result = {}
    for name, expression in re.findall(r'(D3DFMT_\w+)\s*=\s*([^\n]+)', body):
        expression = expression.rstrip().rstrip(',')
        if expression.startswith('MAKEFOURCC'):
            chars = re.findall(r"'([^'])'", expression)
            assert len(chars) == 4
            value = sum(ord(ch) << (8*i) for i, ch in enumerate(chars))
        else:
            chars = None
            value = int(expression, 0)
        result[name] = (value, chars)
    return result


def main():
    cache = Path(sys.argv[1] if len(sys.argv) > 1 else '/tmp/nfsu-c1-sdk')
    cache.mkdir(parents=True, exist_ok=True)
    header = fetch(cache, 'd3d9types.h')
    text = fetch(cache, 'direct3d9/d3dformat.md')
    compression = fetch(cache, 'direct3d9/compressed-texture-formats.md')
    definitions = enum(header)
    assert definitions == enum(text), 'SDK and documentation enum differ'
    descriptions = {}
    section = None
    for line in text.splitlines():
        if line.startswith('### '):
            section = line[4:].lower().replace(' ', '-')
        if not line.startswith('| **D3DFMT'):continue
        cells = [clean(c) for c in re.split(r'(?<!\\)\|', line)[1:-1]]
        descriptions[cells[0]] = (section, cells[2])
    rows = []
    ex_only = {'D32_LOCKABLE', 'S8_LOCKABLE', 'A1', 'A2B10G10R10_XR_BIAS', 'BINARYBUFFER'}
    for name, (value, chars) in definitions.items():
        short = name.removeprefix('D3DFMT_')
        section, description = descriptions.get(name, ('syntax', 'unknown'))
        depth = short.startswith('D') and re.match(r'D\d', short) is not None
        stencil = depth and re.search(r'S\d', short) is not None or short == 'S8_LOCKABLE'
        index = short.startswith('INDEX')
        block = short in ('DXT1', 'DXT2', 'DXT3', 'DXT4', 'DXT5')
        compressed = block or short == 'CxV8U8'
        row = {'name': name, 'value': value, 'value_hex': f'0x{value:08x}',
               'fourcc': chars if chars else 'not_applicable', 'd3d9ex_only': short in ex_only,
               'classification': {'depth': depth, 'stencil': bool(stencil), 'index': index,
                   'vertex_data': short == 'VERTEXDATA', 'compressed': compressed},
               'bits_per_pixel': 'unknown', 'bytes_per_4x4_block': 'not_applicable',
               'channel_fields': 'unknown', 'layout': 'unknown',
               'sources': {'id': header_cite(header, name), 'format': DOC+'#'+section,
                           'channel_order': DOC+'#remarks'}}
        # D3DFORMAT explicitly defines most-to-least-significant channel order.
        # Depth/stencil formats explicitly do not promise that order.
        if depth or short == 'S8_LOCKABLE':
            parts = re.findall(r'([DSX])(\d+)', short)
            row['logical_channels'] = [{'channel':ch, 'bits':int(bits)} for ch,bits in parts]
            row['bits_per_pixel'] = sum(int(n) for _, n in parts)
            row['storage_note'] = 'Nominal bit count; driver may use extra depth bits. Stencil bit count is fixed.'
            row['layout'] = 'unknown; no per-pixel bit order guaranteed by this enum'
            if short == 'D16_LOCKABLE':
                row['channel_fields'] = [{'channel':'D', 'bits':16, 'lsb':0, 'mask_hex':'0x0000ffff'}]
                row['layout'] = '16-bit unsigned depth integer'
            if short == 'D24FS8':row['depth_encoding'] = '24-bit float, 20e4'
            if short == 'D32F_LOCKABLE':row['depth_encoding'] = '32-bit IEEE float'
        elif block:
            row['bytes_per_4x4_block'] = 8 if short == 'DXT1' else 16
            row['bits_per_pixel'] = 4 if short == 'DXT1' else 8
            row['bits_per_pixel_scope'] = 'average within a 4x4 block'
            row['layout'] = {'block_texels':[4,4], 'color':'RGB565 endpoints plus 2-bit selectors',
                             'alpha':('opaque or 1-bit' if short=='DXT1' else '4-bit explicit' if short in ('DXT2','DXT3') else 'endpoints plus 3-bit selectors'),
                             'premultiplied_alpha': short in ('DXT2','DXT4')}
            row['sources']['block_size'] = COMP
            row['sources']['color_layout'] = LEARN+'direct3d9/opaque-and-1-bit-alpha-textures'
            row['sources']['alpha_layout'] = LEARN+'direct3d9/textures-with-alpha-channels'
        elif short in ('R8G8_B8G8', 'G8R8_G8B8'):
            row['bits_per_pixel'] = 16
            row['layout'] = {'unit_pixels':2, 'unit_bits':32,
                             'words_msb_to_lsb':(['R0:8 G0:8','B0:8 G1:8'] if short=='R8G8_B8G8' else ['G0:8 R0:8','G1:8 B0:8']),
                             'shared_channels':['R','B']}
        elif short in ('UYVY','YUY2'):
            row['bits_per_pixel'] = 16
            row['layout'] = {'unit_pixels':2, 'bytes_in_memory':(['U0','Y0','V0','Y1'] if short=='UYVY' else ['Y0','U0','Y1','V0']), 'bits_per_component':8}
            row['sources']['packed_yuv'] = LEARN+'medfound/recommended-8-bit-yuv-formats-for-video-rendering#422-formats-16-bits-per-pixel'
        elif index:
            row['bits_per_pixel'] = 'not_applicable'
            row['layout'] = {'element_bits': int(short[5:]), 'encoding':'unsigned index'}
        elif short in ('VERTEXDATA','BINARYBUFFER','UNKNOWN','FORCE_DWORD','MULTI2_ARGB8'):
            row['layout'] = {'VERTEXDATA':'vertex buffer; per-vertex layout is not specified by D3DFORMAT',
                             'BINARYBUFFER':'untyped binary buffer', 'UNKNOWN':'unknown',
                             'FORCE_DWORD':'enum sentinel, not a surface format',
                             'MULTI2_ARGB8':'multiple ARGB8 elements; element count and full layout unknown from this page'}[short]
            if short in ('VERTEXDATA','BINARYBUFFER','FORCE_DWORD'):row['bits_per_pixel'] = 'not_applicable'
        else:
            notation = short.removesuffix('_XR_BIAS').removesuffix('F')
            if short == 'CxV8U8':notation = 'V8U8'
            parts = re.findall(r'([ARGBXPLUVWQ])(\d+)', notation)
            assert ''.join(ch+bits for ch,bits in parts) == notation, short
            width = sum(int(n) for _,n in parts)
            bit = width
            fields = []
            for ch,bits in parts:
                bits = int(bits); bit -= bits
                fields.append({'channel':ch, 'bits':bits, 'lsb':bit,
                               'mask_hex':f'0x{((1<<bits)-1)<<bit:0{(width+3)//4}x}'})
            row['bits_per_pixel'] = width
            row['channel_fields'] = fields
            row['layout'] = 'MSB-to-LSB channel fields; little-endian memory bytes'
            row['field_derivation'] = 'INFERENCE: widths from documented format notation; offsets and masks are arithmetic using the SDK channel-order rule.'
            if short == 'CxV8U8':row['computed_channel'] = 'C = sqrt(1 - U*U - V*V); C is not stored'
            if short.endswith('F'):row['encoding'] = 's10e5 float per channel' if '16' in short else 's23e8 float per channel'
            elif short.endswith('_XR_BIAS'):row['encoding'] = '2.8-biased fixed point color'
            else:row['encoding'] = section.removesuffix('-formats')
        if short == 'FORCE_DWORD':row['sources']['format'] = DOC+'#syntax'
        rows.append(row)
    files = {'d3d9types.h':header, 'd3dformat.md':text, 'compressed-texture-formats.md':compression}
    for file in ('opaque-and-1-bit-alpha-textures.md','textures-with-alpha-channels.md'):
        files[file] = fetch(cache, 'direct3d9/'+file)
    files['recommended-8-bit-yuv-formats-for-video-rendering.md'] = fetch(cache,'medfound/recommended-8-bit-yuv-formats-for-video-rendering.md')
    out = {'_header':'Made by tools/census/d3d9_formats.py; SDK header enum and D3DFORMAT tables; channel masks are arithmetic derivations, not runtime measurements.',
           'limits':['All header entries are included, including D3D9Ex and FORCE_DWORD.',
                     'Depth/stencil masks are unknown unless the documentation guarantees a layout.',
                     'FOURCC does not imply block compression. Packed RGB/YUV and MULTI2 are distinguished.',
                     'Buffer formats report element widths instead of pixels. No device support was measured.'],
           'counts':{'enum_entries':len(rows),'fourcc':sum(isinstance(r['fourcc'],list) for r in rows),'dxt_block_formats':sum(isinstance(r['bytes_per_4x4_block'],int) for r in rows),
                     'unknown_pixel_sizes':sum(r['bits_per_pixel']=='unknown' for r in rows)},
           'formats':rows, 'source_documents':[{'url':HEADER_URL if f=='d3d9types.h' else LEARN+('medfound/' if f.startswith('recommended-') else 'direct3d9/')+f.removesuffix('.md'),
                           'sha256_text_utf8':hashlib.sha256(t.encode()).hexdigest()} for f,t in files.items()]}
    Path('census/d3d9_formats.json').write_text(json.dumps(out,indent=2)+'\n')
    print('census/d3d9_formats.json:',out['counts'])


if __name__ == '__main__':main()
