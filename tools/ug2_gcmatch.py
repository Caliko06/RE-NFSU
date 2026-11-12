#!/usr/bin/env python3
"""Cross-build evidence extractor, not a name verifier. Requires capstone + pefile.
Build index: python tools/ug2_gcmatch.py index --pc PATH --gc PATH
Inspect: ... show pc|gc ADDRESS; candidates: ... candidates REGEX
Match hypotheses: ... match REGEX --seeds census/ug2/names_gcsweep.tsv
PC intervals come from census/ug2/speed2_functions.tsv: some entries are interior
loop labels, and some intervals contain multiple functions. Use show --end HEX
to inspect actual boundaries. No candidate is automatically V. PPC register
tracking is deliberately local; branches clear it. Indirect calls remain unknown.
"""
import argparse, collections, csv, hashlib, json, pathlib, pickle, re, struct, sys
import capstone as cs
import pefile
ROOT = pathlib.Path(__file__).resolve().parents[1]
CACHE = ROOT / 'scratch/gcmatch/index.pkl'

def elf(path):
    b = pathlib.Path(path).read_bytes()
    h = struct.unpack_from('>16sHHIIIIIHHHHHH', b)
    sh = [struct.unpack_from('>IIIIIIIIII', b, h[6]+i*h[11]) for i in range(h[12])]
    return b, [(s[3], b[s[4]:s[4]+s[5]]) for s in sh if s[2]&2 and s[1]!=8]

def strings(sections):
    out = {}
    for a,b in sections:
        for m in re.finditer(rb'[ -~]{5,}\x00', b):
            out[a+m.start()] = m[0][:-1].decode('ascii')
    return out

def index(pc, gc):
    pe = pefile.PE(pc); pb = pathlib.Path(pc).read_bytes()
    ps = [(pe.OPTIONAL_HEADER.ImageBase+s.VirtualAddress, s.get_data()) for s in pe.sections]
    gb,gs = elf(gc)
    syms = json.loads(pathlib.Path(gc).with_name('symbols.json').read_text())
    funcs = {'pc': [(int(l.split()[0],16),'') for l in (ROOT/'census/ug2/speed2_functions.tsv').read_text().splitlines()],
             'gc': [(s['address'],s['name'],s['size']) for s in syms if s['type']==2 and s['size'] and s['address']]}
    allout = {'paths': {'pc': str(pathlib.Path(pc).resolve()), 'gc': str(pathlib.Path(gc).resolve())},
              'hashes': {'pc': hashlib.md5(pb).hexdigest(), 'gc':hashlib.md5(gb).hexdigest()}}
    for arch,sects in [('pc',ps),('gc',gs)]:
        st = strings(sects); ff = sorted(set(funcs[arch])); out={}
        md = cs.Cs(cs.CS_ARCH_X86,cs.CS_MODE_32) if arch=='pc' else cs.Cs(cs.CS_ARCH_PPC,cs.CS_MODE_32|cs.CS_MODE_BIG_ENDIAN)
        md.detail=True
        for n,ft in enumerate(ff):
            a,name=ft[:2]; end= a+ft[2] if arch=='gc' else (ff[n+1][0] if n+1<len(ff) else a+1)
            sec=next(((s,b) for s,b in sects if s<=a<s+len(b)),None)
            if not sec: continue
            s,b=sec; end=min(end,s+len(b)); ins=[]; refs=[]; calls=[]; constants=[]; regs={}
            for i in md.disasm(b[a-s:end-s],a):
                ins.append((i.address,i.mnemonic,i.op_str))
                if arch=='pc':
                    for op in i.operands:
                        v=op.imm&0xffffffff if op.type==cs.x86.X86_OP_IMM else (op.mem.disp&0xffffffff if op.type==cs.x86.X86_OP_MEM else None)
                        if v is not None:
                            constants.append((i.address,v))
                            if v in st: refs.append((i.address,v,st[v]))
                    if i.mnemonic in ('call','jmp') and i.operands and i.operands[0].type==cs.x86.X86_OP_IMM: calls.append((i.address,i.operands[0].imm&0xffffffff))
                else:
                    ops=i.operands; v=None
                    if i.mnemonic=='lis' and len(ops)==2:
                        v=(ops[1].imm<<16)&0xffffffff; regs[ops[0].reg]=v
                    elif i.mnemonic in ('addi','ori') and len(ops)==3:
                        old=regs.get(ops[1].reg)
                        if old is not None:
                            v=((old+ops[2].imm) if i.mnemonic=='addi' else old|ops[2].imm)&0xffffffff
                            regs[ops[0].reg]=v
                        else: regs.pop(ops[0].reg,None)
                    elif ops and ops[0].type==cs.ppc.PPC_OP_REG and i.mnemonic not in ('cmpw','cmplw','cmpwi','cmplwi','stw','stwu','stb','sth','mtlr','mtctr'):
                        regs.pop(ops[0].reg,None)
                    if v in st: refs.append((i.address,v,st[v]))
                    for op in ops:
                        if op.type==cs.ppc.PPC_OP_IMM: constants.append((i.address,op.imm&0xffffffff))
                    if i.mnemonic in ('bl','b') and ops and ops[0].type==cs.ppc.PPC_OP_IMM: calls.append((i.address,ops[0].imm&0xffffffff))
                    if i.mnemonic.startswith('b'): regs.clear()
            out[a]={'name':name,'end':end,'ins':ins,'strings':refs,'calls':calls,'constants':constants}
        allout[arch]=out
        print(arch,len(out),'functions, string refs',sum(len(f['strings']) for f in out.values()))
    CACHE.parent.mkdir(parents=True,exist_ok=True); CACHE.write_bytes(pickle.dumps(allout))

def match(d, seed_file, regex, rounds):
    """Emit hypotheses only. Inlining and bad census boundaries can fool graphs."""
    sys.path.insert(0, str(ROOT/'ref/_ext/bin/multi-demangle'))
    from multi_demangle import demangle_symbol
    names = collections.defaultdict(list)
    for g, f in d['gc'].items(): names[demangle_symbol(f['name'])].append(g)
    mapped = {}; reasons = {}
    # Only an unambiguous single shared string in each build seeds a match.
    inv = {}
    for arch in ('pc', 'gc'):
        x = collections.defaultdict(set)
        for va, f in d[arch].items():
            for _, _, s in f['strings']: x[s].add(va)
        inv[arch] = x
    votes = collections.defaultdict(set)
    for s, gg in inv['gc'].items():
        pp = inv['pc'].get(s, set())
        if len(gg) == len(pp) == 1: votes[next(iter(gg))].update(pp)
    for g, pp in votes.items():
        if len(pp) == 1:
            mapped[g] = next(iter(pp)); reasons[g] = 'unique shared string'
    if seed_file:
        for row in csv.DictReader(open(seed_file), delimiter='\t'):
            if row['confidence'] != 'V' or len(names[row['name']]) != 1: continue
            g = names[row['name']][0]; mapped[g] = int(row['addr'], 16)
            reasons[g] = 'reviewed seed TSV'
    calls = {}; callers = {}
    for arch in ('pc', 'gc'):
        calls[arch] = {a: {t for _, t in f['calls'] if t in d[arch]} for a, f in d[arch].items()}
        callers[arch] = collections.defaultdict(set)
        for a, tt in calls[arch].items():
            for t in tt: callers[arch][t].add(a)
    for _ in range(rounds):
        proposed = []
        for g in d['gc'].keys() - mapped.keys():
            cc = {mapped[t] for t in calls['gc'][g] if t in mapped}
            rr = {mapped[t] for t in callers['gc'][g] if t in mapped}
            candidates = set()
            for t in cc: candidates.update(callers['pc'][t])
            for t in rr: candidates.update(calls['pc'].get(t, set()))
            scores = sorted(((len(cc & calls['pc'][p]) + len(rr & callers['pc'][p]), p)
                             for p in candidates - set(mapped.values())), reverse=True)
            if scores and scores[0][0] >= 2 and (len(scores) == 1 or scores[0][0] >= scores[1][0]+2):
                proposed.append((g, scores[0][1]))
        count = collections.Counter(p for g, p in proposed)
        for g, p in proposed:
            if count[p] == 1: mapped[g] = p; reasons[g] = 'graph hypothesis; inspect bodies'
    for g, p in sorted(mapped.items()):
        if not re.search(regex, d['gc'][g]['name'], re.I): continue
        print(json.dumps({'gc': hex(g), 'symbol': d['gc'][g]['name'], 'pc': hex(p),
                          'confidence': 'I', 'reason': reasons[g],
                          'pc_calls': [(hex(s), hex(t)) for s,t in d['pc'].get(p, {}).get('calls', [])]}))

def main():
    p=argparse.ArgumentParser(description=__doc__); sub=p.add_subparsers(dest='cmd',required=True)
    q=sub.add_parser('index'); q.add_argument('--pc',required=True);q.add_argument('--gc',required=True)
    q=sub.add_parser('show');q.add_argument('arch',choices=['pc','gc']);q.add_argument('addr',type=lambda x:int(x,16));q.add_argument('--end',type=lambda x:int(x,16))
    q=sub.add_parser('candidates');q.add_argument('regex')
    q=sub.add_parser('match');q.add_argument('regex');q.add_argument('--seeds');q.add_argument('--rounds',type=int,default=1)
    a=p.parse_args()
    if a.cmd=='index': index(a.pc,a.gc);return
    d=pickle.loads(CACHE.read_bytes())
    if a.cmd=='match': match(d,a.seeds,a.regex,a.rounds);return
    if a.cmd=='show':
        if a.end:
            if a.arch=='pc':
                pe=pefile.PE(d['paths']['pc']);sects=[(pe.OPTIONAL_HEADER.ImageBase+s.VirtualAddress,s.get_data()) for s in pe.sections]
                md=cs.Cs(cs.CS_ARCH_X86,cs.CS_MODE_32)
            else:
                _,sects=elf(d['paths']['gc']);md=cs.Cs(cs.CS_ARCH_PPC,cs.CS_MODE_32|cs.CS_MODE_BIG_ENDIAN)
            s,b=next((s,b) for s,b in sects if s<=a.addr<a.end<=s+len(b))
            for i in md.disasm(b[a.addr-s:a.end-s],a.addr):print(f'{i.address:08x} {i.mnemonic:10} {i.op_str}')
            return
        f=d[a.arch][a.addr];print(f['name']);print('STRINGS',f['strings']);print('CALLS',[(hex(s),hex(t),d[a.arch].get(t,{}).get('name','')) for s,t in f['calls']])
        for va,m,o in f['ins']: print(f'{va:08x} {m:10} {o}')
    else:
        inv=collections.defaultdict(set)
        for va,f in d['pc'].items():
            for _,_,s in f['strings']: inv[s].add(va)
        for va,f in d['gc'].items():
            if not re.search(a.regex,f['name'],re.I):continue
            hits=collections.defaultdict(list)
            for site,sa,s in f['strings']:
                for pa in inv[s]:hits[pa].append((hex(site),s))
            print(hex(va),f['name'],json.dumps({hex(k):v for k,v in hits.items()}))
if __name__=='__main__': main()
