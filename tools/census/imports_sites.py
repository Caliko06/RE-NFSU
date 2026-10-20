#!/usr/bin/env python3
"""List statically resolved import transfers. Run from the repository root."""
import collections
import hashlib
import json
import sys
from pathlib import Path

from capstone import CS_GRP_CALL, CS_GRP_JUMP, CS_GRP_RET
from capstone import x86


def main():
    # Reuse the frontend's reached instruction set without running its output stage.
    frontend = Path('tools/recomp/frontend.py').read_text()
    scope = {'__name__': 'census_frontend'}
    old_argv = sys.argv
    sys.argv = ['frontend.py', 'pc/Speed.exe']
    try:
        exec(compile(frontend.split('\nres = {', 1)[0], 'tools/recomp/frontend.py', 'exec'), scope)
    finally:
        sys.argv = old_argv
    md, img, base = (scope[k] for k in ('md', 'img', 'base'))
    insns = {a: next(md.disasm(bytes(img[a-base:a-base+16]), a)) for a in scope['insn_at']}
    iat = scope['iat']
    entries = sorted(int(line.split('\t')[0], 16) for line in Path('census/speed_exe_functions.tsv').read_text().splitlines())
    assert entries == sorted(scope['funcs']), 'Function census differs from this frontend; regenerate upstream first.'
    entry_set = set(entries)

    def iat_operand(ins):
        if not ins.operands:
            return None
        op = ins.operands[0]
        if op.type == x86.X86_OP_MEM and op.mem.base == 0 and op.mem.index == 0:
            return op.mem.disp & 0xffffffff
        return None

    thunks = {a: iat_operand(i) for a, i in insns.items() if i.mnemonic == 'jmp' and iat_operand(i) in iat}
    # Chained unconditional jumps to an import thunk are also static targets.
    changed = True
    while changed:
        changed = False
        for a, ins in insns.items():
            if a not in thunks and ins.mnemonic == 'jmp' and ins.operands[0].type == x86.X86_OP_IMM:
                target = ins.operands[0].imm & 0xffffffff
                if target in thunks:
                    thunks[a] = thunks[target]
                    changed = True

    def successors(ins):
        nxt = ins.address + ins.size
        if ins.group(CS_GRP_RET) or ins.mnemonic in ('hlt', 'ud2', 'int3'):
            return []
        if ins.group(CS_GRP_JUMP):
            op = ins.operands[0]
            target = [op.imm & 0xffffffff] if op.type == x86.X86_OP_IMM else scope['jump_tables'].get(ins.address, [])
            return target + ([] if ins.mnemonic == 'jmp' else [nxt])
        if ins.group(CS_GRP_CALL) and iat.get(iat_operand(ins), '').endswith(('!ExitProcess', '!_exit', '!exit')):
            return []
        return [nxt]

    # Follow intraprocedural edges. A shared tail can have multiple owners.
    owners = collections.defaultdict(set)
    for entry in entries:
        pending, visited = [entry], set()
        while pending:
            a = pending.pop()
            if a in visited or a not in insns or (a in entry_set and a != entry):
                continue
            visited.add(a)
            owners[a].add(entry)
            pending.extend(successors(insns[a]))

    predecessors = collections.defaultdict(list)
    for a, ins in insns.items():
        for target in successors(ins):
            predecessors[target].append(a)

    # Reaching IAT definitions with intersection at CFG joins. Calls through a
    # known Windows import preserve EBX/ESI/EDI/EBP under the x86 Windows ABI.
    preserved = {x86.X86_REG_EBX, x86.X86_REG_ESI, x86.X86_REG_EDI, x86.X86_REG_EBP}
    aliases = {}
    for parent, children in ((x86.X86_REG_EAX, ('AX','AH','AL')), (x86.X86_REG_EBX, ('BX','BH','BL')),
                             (x86.X86_REG_ECX, ('CX','CH','CL')), (x86.X86_REG_EDX, ('DX','DH','DL')),
                             (x86.X86_REG_ESI, ('SI',)), (x86.X86_REG_EDI, ('DI',)),
                             (x86.X86_REG_EBP, ('BP',)), (x86.X86_REG_ESP, ('SP',))):
        for child in children:
            aliases[getattr(x86, 'X86_REG_' + child)] = parent
    states = {}
    queue = collections.deque(entries)
    queued = set(entries)
    while queue:
        a = queue.popleft()
        queued.discard(a)
        if a not in insns:
            continue
        # Entry paths have unknown incoming registers. Unvisited predecessors
        # are incorporated when reached; joins can only remove known facts.
        incoming = [states[p] for p in predecessors[a] if p in states]
        if a in entry_set or not incoming:
            before = {}
        else:
            before = {r: v for r, v in incoming[0].items() if all(x.get(r) == v for x in incoming[1:])}
        after = dict(before)
        ins = insns[a]
        _, written = ins.regs_access()
        for reg in written:
            after.pop(aliases.get(reg, reg), None)
        if ins.mnemonic == 'mov' and len(ins.operands) == 2 and ins.operands[0].type == x86.X86_OP_REG:
            dest, src = ins.operands
            if dest.size == 4:
                if src.type == x86.X86_OP_MEM and src.mem.base == 0 and src.mem.index == 0 and src.mem.disp in iat:
                    after[dest.reg] = src.mem.disp
                elif src.type == x86.X86_OP_REG and src.reg in before:
                    after[dest.reg] = before[src.reg]
        if ins.group(CS_GRP_CALL):
            op = ins.operands[0]
            known = iat_operand(ins) in iat or (op.type == x86.X86_OP_IMM and op.imm in thunks) or (op.type == x86.X86_OP_REG and op.reg in before)
            after = {r: v for r, v in after.items() if known and r in preserved}
        if states.get(a) != after:
            states[a] = after
            for target in successors(ins):
                if target not in queued:
                    queue.append(target)
                    queued.add(target)

    def register_import(site, reg):
        if site in entry_set:
            return None
        incoming = [states[p].get(reg) for p in predecessors[site] if p in states]
        if incoming and incoming[0] is not None and all(v == incoming[0] for v in incoming):
            return incoming[0]
        return None

    rows, unresolved = [], []
    for a, ins in sorted(insns.items()):
        if not (ins.group(CS_GRP_CALL) or ins.mnemonic == 'jmp'):
            continue
        op = ins.operands[0]
        slot, resolution = iat_operand(ins), 'iat'
        if slot not in iat:
            slot = None
            if op.type == x86.X86_OP_IMM:
                slot = thunks.get(op.imm & 0xffffffff)
                resolution = 'import_thunk'
            elif op.type == x86.X86_OP_REG:
                slot = register_import(a, op.reg)
                resolution = 'register_iat_load'
            if slot is None:
                if op.type != x86.X86_OP_IMM:
                    unresolved.append((a, ins.mnemonic, ins.op_str))
                continue
        function = ';'.join(f'0x{f:08x}' for f in sorted(owners[a])) or 'unknown'
        rows.append((f'0x{a:08x}', function, iat[slot], ins.mnemonic, resolution,
                     f'0x{slot:08x}', f'pc/Speed.exe+0x{scope["pe"].get_offset_from_rva(a-base):x}', ins.bytes.hex()))
    called = {r[2] for r in rows}
    out = Path('census/imports_sites.tsv')
    with out.open('w') as f:
        f.write('# Made by tools/census/imports_sites.py; Capstone on frontend-reached instructions; PE IAT from pefile.\n')
        f.write('# Source: pc/Speed.exe sha256=' + hashlib.sha256(Path('pc/Speed.exe').read_bytes()).hexdigest() + '\n')
        f.write('# Function roots: census/speed_exe_functions.tsv; CFG ownership stops at another root; shared tails list all owners.\n')
        f.write('# Static coverage only. Register/memory targets outside the CFG reaching-definition analysis remain unknown.\n')
        f.write(f'# imports={len(iat)}; resolved_transfers={len(rows)}; imports_with_sites={len(called)}; unresolved_indirect_transfers={len(unresolved)}\n')
        f.write('# Imports without a resolved site: ' + json.dumps(sorted(set(iat.values())-called)) + '\n')
        f.write('site_address\tcontaining_function\timport\ttransfer\tresolution\tiat_address\tsource\tbytes\n')
        for row in rows:
            f.write('\t'.join(row) + '\n')
        for a, mnemonic, operands in unresolved:
            f.write(f'# unknown_target\t0x{a:08x}\t{mnemonic}\t{operands}\tpc/Speed.exe+0x{scope["pe"].get_offset_from_rva(a-base):x}\n')
    print(f'{out}: {len(rows)} resolved sites, {len(called)}/{len(iat)} imports; {len(unresolved)} unknown indirect targets')


if __name__ == '__main__':
    main()
