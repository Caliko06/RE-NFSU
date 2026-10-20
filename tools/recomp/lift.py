#!/usr/bin/env python3
"""Lift x86-32 functions of pc/Speed.exe to C (integer subset, first slice).

A function is lifted only if every instruction is in the supported set and it makes
no calls (leaf). Anything else is reported with the reason, never guessed.
Each lifted function is `int f_<addr>(Ctx *c)`: 0 = returned, 1 = fault.
"""
import struct
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32, CS_GRP_JUMP, CS_GRP_CALL, CS_GRP_RET
from capstone import x86

REG32 = ["eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi"]
LO8 = {"al": "eax", "cl": "ecx", "dl": "edx", "bl": "ebx"}
HI8 = {"ah": "eax", "ch": "ecx", "dh": "edx", "bh": "ebx"}
R16 = {"ax": "eax", "cx": "ecx", "dx": "edx", "bx": "ebx", "sp": "esp", "bp": "ebp", "si": "esi", "di": "edi"}

COND = {"o": "of", "no": "!of", "b": "cf", "ae": "!cf", "e": "zf", "ne": "!zf", "be": "(cf||zf)",
        "a": "(!cf&&!zf)", "s": "sf", "ns": "!sf", "l": "(sf!=of)", "ge": "(sf==of)",
        "le": "(zf||sf!=of)", "g": "(!zf&&sf==of)"}
ALU = {"mov", "movzx", "movsx", "lea", "add", "sub", "adc", "sbb", "and", "or", "xor", "not", "neg",
       "inc", "dec", "cmp", "test", "shl", "sal", "shr", "sar", "rol", "ror", "imul", "mul", "div", "idiv",
       "push", "pop", "xchg", "cdq", "cwde", "nop", "leave", "ret", "jmp",
       "movsd", "movsb", "movsw", "stosd", "stosb", "stosw"}
ALU |= {"j" + k for k in COND} | {"set" + k for k in COND}

PROLOGUE = """#include <stdint.h>
#include <string.h>
typedef struct { uint32_t r[8]; uint8_t *mem; uint32_t memsz; uint32_t ret; } Ctx;
#define CHK(a,n) do { if ((uint32_t)(a) > c->memsz - (n)) goto fault; } while (0)
static inline uint32_t ld(Ctx *c, uint32_t a, int n) { uint32_t v = 0; memcpy(&v, c->mem + a, n); return v; }
static inline void st(Ctx *c, uint32_t a, uint32_t v, int n) { memcpy(c->mem + a, &v, n); }
"""


class Unsupported(Exception):
    pass


class Lifter:
    def __init__(self, exe):
        self.pe = pefile.PE(exe)
        self.base = self.pe.OPTIONAL_HEADER.ImageBase
        self.img = self.pe.get_memory_mapped_image()
        t = next(s for s in self.pe.sections if s.Name.rstrip(b"\0") == b".text")
        self.t0, self.t1 = self.base + t.VirtualAddress, self.base + t.VirtualAddress + t.Misc_VirtualSize
        self.md = Cs(CS_ARCH_X86, CS_MODE_32)
        self.md.detail = True

    def insn(self, a):
        o = a - self.base
        i = next(self.md.disasm(bytes(self.img[o:o + 16]), a), None)
        if i is None:
            raise Unsupported(f"decode {a:#x}")
        return i

    def body(self, entry, limit=4000):
        """Instructions of one function, by local recursive descent."""
        seen, todo = {}, [entry]
        while todo:
            a = todo.pop()
            while a not in seen:
                if not (self.t0 <= a < self.t1) or len(seen) > limit:
                    raise Unsupported("outside .text or too big")
                i = self.insn(a)
                seen[a] = i
                m = i.mnemonic
                if i.group(CS_GRP_RET):
                    break
                if i.group(CS_GRP_CALL):
                    raise Unsupported("call")
                if i.group(CS_GRP_JUMP):
                    op = i.operands[0]
                    if op.type != x86.X86_OP_IMM:
                        raise Unsupported("indirect jmp")
                    todo.append(op.imm)
                    if m == "jmp":
                        break
                a = i.address + i.size
        return seen

    # --- operand helpers --------------------------------------------------
    def ea(self, mem):
        if mem.segment != 0:
            raise Unsupported("segment")
        parts = []
        if mem.base:
            parts.append(self.r32(mem.base))
        if mem.index:
            parts.append(f"{self.r32(mem.index)}*{mem.scale}u")
        parts.append(f"0x{mem.disp & 0xffffffff:x}u")
        return "(uint32_t)(" + "+".join(parts) + ")"

    def r32(self, reg):
        n = self.i.reg_name(reg)
        if n not in REG32:
            raise Unsupported(f"reg {n}")
        return n

    def read(self, op):
        if op.type == x86.X86_OP_IMM:
            return f"0x{op.imm & ((1 << (8 * op.size)) - 1):x}u"
        if op.type == x86.X86_OP_REG:
            n = self.i.reg_name(op.reg)
            if n in REG32:
                return n
            if n in R16:
                return f"({R16[n]}&0xffffu)"
            if n in LO8:
                return f"({LO8[n]}&0xffu)"
            if n in HI8:
                return f"(({HI8[n]}>>8)&0xffu)"
            raise Unsupported(f"reg {n}")
        self.out.append(f"ea={self.ea(op.mem)}; CHK(ea,{op.size});")
        return f"ld(c,ea,{op.size})"

    def write(self, op, v):
        if op.type == x86.X86_OP_REG:
            n = self.i.reg_name(op.reg)
            if n in REG32:
                return f"{n}=(uint32_t)({v});"
            if n in R16:
                r = R16[n]
                return f"{r}=({r}&0xffff0000u)|(({v})&0xffffu);"
            if n in LO8:
                r = LO8[n]
                return f"{r}=({r}&0xffffff00u)|(({v})&0xffu);"
            if n in HI8:
                r = HI8[n]
                return f"{r}=({r}&0xffff00ffu)|((({v})&0xffu)<<8);"
            raise Unsupported(f"reg {n}")
        # ea was computed by the matching read() or by addr()
        return f"st(c,ea,(uint32_t)({v}),{op.size});"

    def addr(self, op):
        if op.type == x86.X86_OP_MEM:
            self.out.append(f"ea={self.ea(op.mem)}; CHK(ea,{op.size});")

    # --- one instruction --------------------------------------------------
    def emit(self, i, fn_entry):
        self.i = i
        m = i.mnemonic
        ops = i.operands
        o = self.out
        if m not in ALU:
            raise Unsupported(f"mnemonic {m}")
        if i.prefix[0] in (0xf2, 0xf3) and m not in ("movsd", "movsb", "movsw", "stosd", "stosb", "stosw"):
            raise Unsupported(f"rep {m}")
        sz = ops[0].size if ops else 4
        M = (1 << (8 * sz)) - 1
        S = 1 << (8 * sz - 1)
        ZS = f"zf=(res&0x{M:x}u)==0; sf=(res&0x{S:x}u)!=0;"

        if m == "nop":
            return
        if m in ("mov", "movzx"):
            v = self.read(ops[1])
            if ops[0].type == x86.X86_OP_MEM:
                self.addr(ops[0])
            o.append(self.write(ops[0], v))
            return
        if m == "movsx":
            s2 = ops[1].size
            v = self.read(ops[1])
            o.append(self.write(ops[0], f"(uint32_t)(int{8*s2}_t)({v})"))
            return
        if m == "lea":
            o.append(self.write(ops[0], self.ea(ops[1].mem)))
            return
        if m in ("add", "sub", "adc", "sbb", "and", "or", "xor", "cmp", "test"):
            b = self.read(ops[1])
            o.append(f"t2={b};")
            a = self.read(ops[0])
            o.append(f"t1={a};")
            if m == "add":
                o.append(f"res=(t1+t2)&0x{M:x}u; cf=((uint64_t)t1+t2)>0x{M:x}u; of=((~(t1^t2))&(t1^res)&0x{S:x}u)!=0;")
            elif m == "adc":
                o.append(f"res=(t1+t2+cf)&0x{M:x}u; cf=((uint64_t)t1+t2+cf)>0x{M:x}u; of=((~(t1^t2))&(t1^res)&0x{S:x}u)!=0;")
            elif m in ("sub", "cmp"):
                o.append(f"res=(t1-t2)&0x{M:x}u; cf=t1<t2; of=((t1^t2)&(t1^res)&0x{S:x}u)!=0;")
            elif m == "sbb":
                o.append(f"res=(t1-t2-cf)&0x{M:x}u; cf=(uint64_t)t1<(uint64_t)t2+cf; of=((t1^t2)&(t1^res)&0x{S:x}u)!=0;")
            else:
                opc = {"and": "&", "test": "&", "or": "|", "xor": "^"}[m]
                o.append(f"res=(t1{opc}t2)&0x{M:x}u; cf=0; of=0;")
            o.append(ZS)
            if m not in ("cmp", "test"):
                o.append(self.write(ops[0], "res"))
            return
        if m in ("inc", "dec", "neg", "not"):
            a = self.read(ops[0])
            o.append(f"t1={a};")
            if m == "inc":
                o.append(f"res=(t1+1)&0x{M:x}u; of=res==0x{S:x}u; {ZS}")
            elif m == "dec":
                o.append(f"res=(t1-1)&0x{M:x}u; of=t1==0x{S:x}u; {ZS}")
            elif m == "neg":
                o.append(f"res=(0u-t1)&0x{M:x}u; cf=t1!=0; of=t1==0x{S:x}u; {ZS}")
            else:
                o.append(f"res=(~t1)&0x{M:x}u;")
            o.append(self.write(ops[0], "res"))
            return
        if m in ("shl", "sal", "shr", "sar", "rol", "ror"):
            n = self.read(ops[1]) if len(ops) > 1 else "1u"
            o.append(f"n=({n})&31u;")
            a = self.read(ops[0])
            o.append(f"t1={a};")
            bits = 8 * sz
            o.append("if (n) {")
            if m in ("shl", "sal"):
                o.append(f"res=(uint32_t)(((uint64_t)t1<<n)&0x{M:x}u); cf=n<={bits}?((uint64_t)t1>>({bits}-n))&1:0; of=((res&0x{S:x}u)!=0)^cf; {ZS}")
            elif m == "shr":
                o.append(f"res=(uint32_t)((uint64_t)t1>>n); cf=(t1>>(n-1))&1; of=(t1&0x{S:x}u)!=0; {ZS}")
            elif m == "sar":
                o.append(f"res=(uint32_t)(((int64_t)(int{bits}_t)t1)>>n)&0x{M:x}u; cf=(uint32_t)((((int64_t)(int{bits}_t)t1)>>(n-1))&1); of=0; {ZS}")
            elif m == "rol":
                o.append(f"k=n%{bits}; res=k?((t1<<k)|(t1>>({bits}-k)))&0x{M:x}u:t1; cf=res&1; of=((res&0x{S:x}u)!=0)^cf;")
            else:
                o.append(f"k=n%{bits}; res=k?((t1>>k)|(t1<<({bits}-k)))&0x{M:x}u:t1; cf=(res&0x{S:x}u)!=0; of=((res^(res<<1))&0x{S:x}u)!=0;")
            o.append(self.write(ops[0], "res"))
            o.append("}")
            return
        if m == "imul" and len(ops) >= 2:
            if sz != 4:
                raise Unsupported("imul16")
            b = self.read(ops[2]) if len(ops) == 3 else self.read(ops[0])
            o.append(f"t2={b};")
            a = self.read(ops[1])
            o.append(f"w=(int64_t)(int32_t)({a})*(int64_t)(int32_t)t2; cf=of=(w!=(int64_t)(int32_t)w);")
            o.append(self.write(ops[0], "(uint32_t)w"))
            return
        if m in ("mul", "imul", "div", "idiv"):
            if sz != 4:
                raise Unsupported(f"{m}{8*sz}")
            v = self.read(ops[0])
            o.append(f"t1={v};")
            if m == "mul":
                o.append("u=(uint64_t)eax*t1; eax=(uint32_t)u; edx=(uint32_t)(u>>32); cf=of=edx!=0;")
            elif m == "imul":
                o.append("w=(int64_t)(int32_t)eax*(int32_t)t1; eax=(uint32_t)w; edx=(uint32_t)((uint64_t)w>>32); cf=of=(w!=(int64_t)(int32_t)w);")
            elif m == "div":
                o.append("u=((uint64_t)edx<<32)|eax; if (!t1 || u/t1>0xffffffffu) goto fault; eax=(uint32_t)(u/t1); edx=(uint32_t)(u%t1);")
            else:
                o.append("w=(int64_t)(((uint64_t)edx<<32)|eax); if (!t1) goto fault; { int64_t q=w/(int32_t)t1; if (q!=(int32_t)q) goto fault; eax=(uint32_t)q; edx=(uint32_t)(w%(int32_t)t1); }")
            return
        if m == "push":
            v = self.read(ops[0])
            o.append(f"t1={v}; esp-=4; CHK(esp,4); st(c,esp,t1,4);")
            return
        if m == "pop":
            o.append("CHK(esp,4); t1=ld(c,esp,4); esp+=4;")
            if ops[0].type == x86.X86_OP_MEM:
                self.addr(ops[0])
            o.append(self.write(ops[0], "t1"))
            return
        if m == "leave":
            o.append("esp=ebp; CHK(esp,4); ebp=ld(c,esp,4); esp+=4;")
            return
        if m == "xchg":
            a = self.read(ops[0])
            o.append(f"t1={a};")
            b = self.read(ops[1])
            o.append(f"t2={b};")
            o.append(self.write(ops[1], "t1"))
            if ops[0].type == x86.X86_OP_MEM:
                self.addr(ops[0])
            o.append(self.write(ops[0], "t2"))
            return
        if m == "cdq":
            o.append("edx=(uint32_t)((int32_t)eax>>31);")
            return
        if m == "cwde":
            o.append("eax=(uint32_t)(int16_t)(eax&0xffffu);")
            return
        if m.startswith("set"):
            if ops[0].type == x86.X86_OP_MEM:
                self.addr(ops[0])
            o.append(self.write(ops[0], f"({COND[m[3:]]})?1u:0u"))
            return
        if m in ("movsd", "movsb", "movsw", "stosd", "stosb", "stosw"):
            n = {"d": 4, "w": 2, "b": 1}[m[-1]]
            rep = i.prefix[0] in (0xf2, 0xf3)
            step = (f"CHK(esi,{n}); CHK(edi,{n}); st(c,edi,ld(c,esi,{n}),{n}); esi+={n}; edi+={n};" if m.startswith("movs")
                    else f"CHK(edi,{n}); st(c,edi,eax,{n}); edi+={n};")
            o.append(f"while (ecx) {{ {step} ecx--; }}" if rep else step)
            return
        if m == "ret":
            imm = ops[0].imm if ops else 0
            o.append(f"CHK(esp,4); c->ret=ld(c,esp,4); esp+=4+{imm}; goto done;")
            return
        if m == "jmp":
            o.append(f"goto L{ops[0].imm:x};")
            return
        if m.startswith("j"):
            o.append(f"if ({COND[m[1:]]}) goto L{ops[0].imm:x};")
            return
        raise Unsupported(f"mnemonic {m}")

    def lift(self, entry):
        body = self.body(entry)
        self.out = []
        addrs = sorted(body)
        for a in addrs:
            self.out.append(f"L{a:x}:;")
            self.emit(body[a], entry)
            nxt = a + body[a].size
            if nxt not in body and not (body[a].group(CS_GRP_RET) or body[a].mnemonic == "jmp"):
                self.out.append(f"goto L{nxt:x};")   # fall into code not decoded: cannot happen
        regs = " ".join(f"uint32_t {r}=c->r[{k}];" for k, r in enumerate(REG32))
        back = " ".join(f"c->r[{k}]={r};" for k, r in enumerate(REG32))
        return (f"int f_{entry:x}(Ctx *c) {{\n{regs}\n"
                "uint32_t ea=0,t1=0,t2=0,res=0,n=0,k=0; uint64_t u=0; int64_t w=0; int cf=0,zf=0,sf=0,of=0;\n"
                "(void)ea;(void)t1;(void)t2;(void)res;(void)n;(void)k;(void)u;(void)w;(void)cf;(void)zf;(void)sf;(void)of;\n"
                f"goto L{entry:x};\n" + "\n".join(self.out) +
                f"\ndone: {back} return 0;\nfault: {back} return 1;\n}}\n")
