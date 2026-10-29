// Canon database for Speed.exe (docs/re/canon_db.md). Ghidra headless postScript on the writable project
// build/ghidra/canon (never on build/ghidra/proj, which stays the pristine analysis).
//   apply  <seed.tsv> <report.txt>          seed lines: addr kind name system conf tool doc (tools/canon/canon.py seed)
//   export <lo> <hi> <out_prefix>           functions with entry in [lo,hi): <prefix>.c (named pseudocode) + <prefix>.jsonl
//   vtscan <report.txt>                     create functions at vtable slots that lack one (writable project)
//   data   <out.jsonl>                      globals (data referenced from code) and vtables (constructor writes)
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.lang.OperandType;
import ghidra.program.model.lang.Register;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;
import java.util.*;

public class Canon extends GhidraScript {
    private static String q(String s) {
        StringBuilder b = new StringBuilder("\"");
        for (char c : s.toCharArray()) {
            if (c == '"' || c == '\\') b.append('\\').append(c);
            else if (c < 0x20 || c > 0x7e) b.append(String.format("\\u%04x", (int) c));
            else b.append(c);
        }
        return b.append('"').toString();
    }
    private static String hex(Address a) { return "0x" + Long.toHexString(a.getOffset()); }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args[0].equals("apply")) apply(args[1], args[2]);
        else if (args[0].equals("export")) export(toAddr(args[1]), toAddr(args[2]), args[3]);
        else if (args[0].equals("data")) data(args[1]);
        else if (args[0].equals("vtscan")) vtscan(args[1]);
        else throw new IllegalArgumentException("mode " + args[0]);
    }

    // Create every lifted function Ghidra's analysis missed, then name and comment the known ones.
    private void apply(String seed, String report) throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        int made = 0, inside = 0, failed = 0, named = 0, dup = 0;
        List<String[]> rows = new ArrayList<>();
        for (String line : Files.readAllLines(Paths.get(seed))) {
            if (line.startsWith("#") || line.isBlank()) continue;
            rows.add(line.split("\t", -1));
        }
        try (PrintWriter o = new PrintWriter(new FileWriter(report))) {
            // pass 1: function starts, highest address first so a new start does not swallow a later one
            rows.sort((x, y) -> Long.compare(Long.decode(y[0]), Long.decode(x[0])));
            for (String[] r : rows) {
                Address a = toAddr(r[0]);
                if (fm.getFunctionAt(a) != null) continue;
                Function c = fm.getFunctionContaining(a);
                if (c != null) {
                    // a lifter start inside a Ghidra function: split only if it is a call target (real entry)
                    boolean called = false;
                    for (Reference ref : getReferencesTo(a)) called |= ref.getReferenceType().isCall();
                    if (!called) { inside++; o.println("inside " + r[0] + " " + hex(c.getEntryPoint())); continue; }
                }
                if (getInstructionAt(a) == null) disassemble(a);
                Function f = createFunction(a, null);
                if (f == null) { failed++; o.println("fail " + r[0]); } else made++;
            }
            // pass 2: names and plate comments
            for (String[] r : rows) {
                Function f = fm.getFunctionAt(toAddr(r[0]));
                if (f == null || r.length < 3 || r[2].isEmpty()) continue;
                String name = r[2].replaceAll("[^A-Za-z0-9_:]", "_");
                try {
                    f.setName(name, SourceType.USER_DEFINED);
                } catch (Exception e) {
                    f.setName(name + "_" + r[0].substring(2), SourceType.USER_DEFINED);
                    dup++;
                }
                named++;
                String sys = r.length > 3 ? r[3] : "", conf = r.length > 4 ? r[4] : "",
                       tool = r.length > 5 ? r[5] : "", doc = r.length > 6 ? r[6] : "";
                f.setComment("[canon] " + sys + " " + conf + " (" + tool + ") " + doc);
            }
            o.printf("made %d inside %d failed %d named %d dup %d functions_now %d%n",
                     made, inside, failed, named, dup, fm.getFunctionCount());
        }
    }

    private void export(Address lo, Address hi, String prefix) throws Exception {
        DecompInterface d = new DecompInterface();
        DecompileOptions opt = new DecompileOptions();
        opt.grabFromProgram(currentProgram);
        d.setOptions(opt);
        d.openProgram(currentProgram);
        Listing l = currentProgram.getListing();
        ReferenceManager rm = currentProgram.getReferenceManager();
        try (PrintWriter c = new PrintWriter(new BufferedWriter(new FileWriter(prefix + ".c")));
             PrintWriter j = new PrintWriter(new BufferedWriter(new FileWriter(prefix + ".jsonl")))) {
            for (Function f : currentProgram.getFunctionManager().getFunctions(new AddressSet(lo, hi.previous()), true)) {
                if (monitor.isCancelled()) break;
                Set<String> callees = new TreeSet<>(), callers = new TreeSet<>(), globals = new TreeSet<>(), strs = new TreeSet<>();
                for (Function g : f.getCalledFunctions(monitor)) callees.add(hex(g.getEntryPoint()));
                for (Reference r : rm.getReferencesTo(f.getEntryPoint())) {
                    Function g = getFunctionContaining(r.getFromAddress());
                    if (g != null) callers.add(hex(g.getEntryPoint()));
                    else callers.add("d" + hex(r.getFromAddress()));   // from data: vtable or table slot
                }
                for (Instruction i : l.getInstructions(f.getBody(), true))
                    for (Reference r : i.getReferencesFrom()) {
                        Address t = r.getToAddress();
                        if (!t.isMemoryAddress() || r.getReferenceType().isFlow()) continue;
                        Data dd = l.getDataAt(t);
                        if (dd != null && dd.hasStringValue()) strs.add(hex(t));
                        else if (getFunctionAt(t) == null) globals.add(hex(t) + (r.getReferenceType().isWrite() ? "w" : ""));
                    }
                DecompileResults res = d.decompileFunction(f, 90, monitor);
                String code = res.decompileCompleted() ? res.getDecompiledFunction().getC() : null;
                c.printf("// ==== %s %s%n", hex(f.getEntryPoint()), f.getName());
                c.println(code != null ? code : "// decompile failed: " + res.getErrorMessage());
                j.printf("{\"addr\":%s,\"name\":%s,\"size\":%d,\"sig\":%s,\"comment\":%s,\"ok\":%b,\"callees\":%s,\"callers\":%s,\"globals\":%s,\"strings\":%s}%n",
                         q(hex(f.getEntryPoint())), q(f.getName()), f.getBody().getNumAddresses(),
                         q(f.getPrototypeString(false, false)), q(Objects.toString(f.getComment(), "")), code != null,
                         arr(callees), arr(callers), arr(globals), arr(strs));
            }
        }
        d.dispose();
    }

    private static String arr(Set<String> s) {
        StringBuilder b = new StringBuilder("[");
        for (String x : s) b.append(b.length() > 1 ? "," : "").append(q(x));
        return b.append(']').toString();
    }

    // Globals: every non-code address in initialized/uninitialized data that code references, with readers/writers.
    // Vtables: see vtableStarts.
    private void data(String out) throws Exception {
        Memory mem = currentProgram.getMemory();
        FunctionManager fm = currentProgram.getFunctionManager();
        ReferenceManager rm = currentProgram.getReferenceManager();
        try (PrintWriter o = new PrintWriter(new BufferedWriter(new FileWriter(out)))) {
            for (MemoryBlock b : mem.getBlocks()) {
                if (b.isExecute()) continue;
                AddressIterator it = rm.getReferenceDestinationIterator(new AddressSet(b.getStart(), b.getEnd()), true);
                while (it.hasNext()) {
                    Address t = it.next();
                    Set<String> rd = new TreeSet<>(), wr = new TreeSet<>();
                    for (Reference r : rm.getReferencesTo(t)) {
                        Function g = getFunctionContaining(r.getFromAddress());
                        if (g == null) continue;
                        (r.getReferenceType().isWrite() ? wr : rd).add(hex(g.getEntryPoint()));
                    }
                    if (rd.isEmpty() && wr.isEmpty()) continue;
                    Data dd = getDataAt(t);
                    Symbol s = getSymbolAt(t);
                    o.printf("{\"kind\":\"global\",\"addr\":%s,\"block\":%s,\"label\":%s,\"type\":%s,\"str\":%s,\"readers\":%s,\"writers\":%s}%n",
                             q(hex(t)), q(b.getName()), q(s == null ? "" : s.getName()),
                             q(dd == null ? "" : dd.getDataType().getName()),
                             q(dd != null && dd.hasStringValue() ? String.valueOf(dd.getValue()) : ""), arr(rd), arr(wr));
                }
            }
            TreeMap<Address, Set<String>> vt = vtableStarts();
            for (Map.Entry<Address, Set<String>> e : vt.entrySet()) {
                List<String> slots = new ArrayList<>();
                for (Address t : slotsOf(e.getKey(), vt)) slots.add(hex(t));
                o.printf("{\"kind\":\"vtable\",\"addr\":%s,\"slots\":%s,\"users\":%s}%n",
                         q(hex(e.getKey())), q(String.join(",", slots)), arr(e.getValue()));
            }
        }
    }

    // Vtables: a data address that code stores into an object field (mov [reg+off], imm: a constructor or destructor
    // setting the vptr) and whose first dword points into code. Writers are the functions doing the store.
    private TreeMap<Address, Set<String>> vtableStarts() throws Exception {
        TreeMap<Address, Set<String>> m = new TreeMap<>();
        Memory mem = currentProgram.getMemory();
        for (Instruction i : currentProgram.getListing().getInstructions(true)) {
            if (!i.getMnemonicString().equals("MOV") || i.getNumOperands() != 2
                || (i.getOperandType(0) & OperandType.DYNAMIC) == 0) continue;
            Scalar s = i.getScalar(1);
            if (s == null) continue;
            boolean stack = false;
            for (Object x : i.getOpObjects(0))
                if (x instanceof Register r && (r.getName().equals("ESP") || r.getName().equals("EBP"))) stack = true;
            if (stack) continue;
            Address t = toAddr(s.getUnsignedValue());
            MemoryBlock b = mem.getBlock(t);
            if (b == null || b.isExecute() || !b.isInitialized() || t.getOffset() % 4 != 0 || codePtr(t) == null) continue;
            Function g = getFunctionContaining(i.getAddress());
            m.computeIfAbsent(t, k -> new TreeSet<>()).add(g != null ? hex(g.getEntryPoint()) : "i" + hex(i.getAddress()));
        }
        return m;
    }

    private Address codePtr(Address p) {
        try {
            MemoryBlock b = currentProgram.getMemory().getBlock(p);
            if (b == null || p.add(3).compareTo(b.getEnd()) > 0) return null;
            Address t = toAddr(currentProgram.getMemory().getInt(p) & 0xffffffffL);
            MemoryBlock tb = currentProgram.getMemory().getBlock(t);
            return tb != null && tb.isExecute() ? t : null;
        } catch (Exception e) { return null; }
    }

    // Slots run while each dword points into code, up to the next vtable start or the next address code references.
    private List<Address> slotsOf(Address v, TreeMap<Address, Set<String>> vt) {
        List<Address> out = new ArrayList<>();
        ReferenceManager rm = currentProgram.getReferenceManager();
        for (Address p = v; ; p = p.add(4)) {
            if (!p.equals(v) && (vt.containsKey(p) || rm.hasReferencesTo(p))) break;
            Address t = codePtr(p);
            if (t == null) break;
            out.add(t);
        }
        return out;
    }

    // Every vtable slot is an entry point (called indirectly): create the function where Ghidra has none.
    private void vtscan(String report) throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        TreeMap<Address, Set<String>> vt = vtableStarts();
        int slots = 0, made = 0, inside = 0, failed = 0;
        try (PrintWriter o = new PrintWriter(new FileWriter(report))) {
            Set<Address> todo = new TreeSet<>();
            for (Address v : vt.keySet())
                for (Address t : slotsOf(v, vt)) { slots++; if (fm.getFunctionAt(t) == null) todo.add(t); }
            for (Address t : todo) {
                Function c = fm.getFunctionContaining(t);
                if (getInstructionAt(t) == null) disassemble(t);
                Function f = createFunction(t, null);
                if (f == null) { failed++; o.println("fail " + hex(t) + (c != null ? " inside " + hex(c.getEntryPoint()) : "")); }
                else { made++; if (c != null) { inside++; o.println("split " + hex(t) + " from " + hex(c.getEntryPoint())); } }
            }
            o.printf("vtables %d slots %d made %d (split %d) failed %d functions_now %d%n",
                     vt.size(), slots, made, inside, failed, fm.getFunctionCount());
        }
    }
}
