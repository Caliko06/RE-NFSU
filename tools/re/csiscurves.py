"""Read-only dump of the engine/exhaust sound patches: node graph and curve tables (docs/re/sound.md §5).

An ENG/EXH ABK module has one patch function (seed). It is straight-line code over node blocks in the patch
instance P: `push esi; call node; mov [esi+k],eax; add esi,size`. The instance is a copy of a template inside the
header. The template sits at T = hdr offset where every curve node (0x64cdd0) block starts with a relocated
("based") pointer to its curve record. Curve record (read by 0x64cdd0): u8 type (1 int8, 2 int16), i32 min +4,
i32 max +8, f32 scale +0xc, table +0x10 with (max-min)*scale+1 points.
The mapping of patch inputs P+0x2c.. to the Csis params written by 0x52bf70 is open (U); inputs are named in<k>.

usage: csiscurves.py [check | summary | json OUT]
"""
import sys
sys.path = [p for p in sys.path if not p.endswith('tools/re')]   # tools/re/ast.py shadows the stdlib ast
import bisect, json, os, struct  # noqa: E402
R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(R, 'tools', 'recomp'))
import abk  # noqa: E402
from capstone import Cs, CS_ARCH_X86, CS_MODE_32  # noqa: E402

NODES = {0x64cdd0: 'curve', 0x64d0b0: 'product', 0x64db50: 'copy3', 0x64cb90: 'gate', 0x64cf90: 'select',
         0x64da70: 'ramp', 0x64d960: 'osc', 0x64d860: 'voice', 0x64cc60: 'trigger', 0x64d120: 'get1',
         0x64c650: 'flag', 0x64c660: 'param', 0x64c690: 'end'}
IN0 = 0x2c          # first patch input slot read by the fan-out


def exe_u32():
    pe = open(os.path.join(R, 'pc', 'Speed.exe'), 'rb').read()
    e = struct.unpack_from('<I', pe, 0x3c)[0]
    n, opt = struct.unpack_from('<H', pe, e + 6)[0], struct.unpack_from('<H', pe, e + 20)[0]
    secs = [struct.unpack_from('<IIII', pe, e + 24 + opt + 40 * i + 8) for i in range(n)]

    def rd(v):
        for vs, va, rs, ro in secs:
            if 0x400000 + va <= v < 0x400000 + va + rs:
                return struct.unpack_from('<I', pe, ro + v - 0x400000 - va)[0]
        return 0
    return rd


def patch(m, rd):
    cb = 0xa0000000
    blob = bytes(abk.relocate(m, cb, rd))
    seed = m['seeds'][0]
    esi, nodes, edges, cur = 0, [], [], None
    for i in Cs(CS_ARCH_X86, CS_MODE_32).disasm(blob[seed:], cb + seed):
        mn, op = i.mnemonic, i.op_str
        if mn == 'ret':
            break
        if mn == 'mov' and op.startswith('esi, dword ptr [esp'):
            esi = 0
        elif mn == 'add' and op.startswith('esi,'):
            esi += int(op.split(',')[1], 0)
        elif mn == 'call':
            f = int(op, 0)
            nodes.append((esi, NODES.get(f, hex(f))))
            cur = ('N%x' % esi,)
        elif mn == 'mov' and op.startswith('eax, dword ptr [esi'):
            k = esi + (int(op.split('+')[1].strip(' ]'), 0) if '+' in op else 0)
            cur = ('in%d' % ((k - IN0) // 4),)
        elif mn == 'add' and op.startswith('eax, dword ptr [esi'):
            cur = cur + ('S%x' % (esi + int(op.split('+')[1].strip(' ]'), 0)),)
        elif mn == 'mov' and op.startswith('dword ptr [esi') and op.endswith('eax'):
            edges.append(('+'.join(cur), esi + int(op.split('+')[1].split(']')[0], 0)))
    hdr, based = m['hdr'], set(m['based'])
    curves = [o for o, t in nodes if t == 'curve']
    T = next(b - curves[0] for b in sorted(based) if all(b - curves[0] + c in based for c in curves))
    out = {'files': m['files'], 'template': T, 'nodes': [], 'curves': {}}
    starts = [o for o, _ in nodes]
    for src, dst in edges:
        o = starts[bisect.bisect_right(starts, dst) - 1]
        out['nodes'].append({'from': src, 'to': 'N%x+%x' % (o, dst - o)})
    for o, t in nodes:
        if t != 'curve':
            continue
        d = struct.unpack_from('<I', hdr, T + o)[0]
        typ, lo, hi, sc = hdr[d], *struct.unpack_from('<iif', hdr, d + 4)
        if typ in (1, 2):
            n = int((hi - lo) * sc) + 1
            tab = list(struct.unpack_from('<%d%s' % (n, 'bh'[typ - 1]), hdr, d + 0x10))
        else:
            n, tab = 0, []
        out['curves']['N%x' % o] = {'rec': d, 'type': typ, 'min': lo, 'max': hi, 'scale': sc, 'points': tab}
    return out


def eng_modules():
    return [m for m in abk.modules(os.path.join(R, 'game'))
            if any(k in m['files'][0].upper() for k in ('_ENG_', '_EXH_'))]


def main(a):
    rd = exe_u32()
    ps = [patch(m, rd) for m in eng_modules()]
    if a[:1] == ['check']:
        bad = [p['files'][0] for p in ps if not p['curves'] or any(
            c['type'] in (1, 2) and len(c['points']) != int((c['max'] - c['min']) * c['scale']) + 1
            for c in p['curves'].values())]
        print(f'{len(ps)} ENG/EXH patches, {sum(len(p["curves"]) for p in ps)} curves; bad: {bad or "none"}')
        return 1 if bad or len(ps) != 32 else 0
    if a[:1] == ['json']:
        json.dump(ps, open(a[1], 'w'))
        return 0
    for p in ps:      # summary: the 0..1024 input curves sampled at 8 points
        print(os.path.basename(p['files'][0]), 'T=%#x' % p['template'])
        for k, c in p['curves'].items():
            if c['max'] == 1024:
                pts = c['points']
                print('  %-6s' % k, ' '.join('%6d' % pts[i * (len(pts) - 1) // 7] for i in range(8)))
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
