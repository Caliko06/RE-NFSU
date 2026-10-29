// Canon database for Speed.exe (docs/re/canon_db.md). Ghidra headless postScript on the writable project
// build/ghidra/canon (never on build/ghidra/proj, which stays the pristine analysis).
//   apply  <seed.tsv> <report.txt>          seed lines: addr kind name system conf tool doc (tools/canon/canon.py seed)
//   export <lo> <hi> <out_prefix>           functions with entry in [lo,hi): <prefix>.c (named pseudocode) + <prefix>.jsonl
//   data   <out.jsonl>                      globals (data referenced from code) and vtable candidates in .rdata
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
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
    // Vtables: runs of >=2 consecutive dwords in non-executable blocks that point at function entries.
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
                if (!b.isInitialized()) continue;
                Address a = b.getStart().add((4 - b.getStart().getOffset() % 4) % 4);
                while (a.compareTo(b.getEnd().subtract(3)) <= 0) {
                    List<String> slots = new ArrayList<>();
                    Address p = a;
                    while (p.compareTo(b.getEnd().subtract(3)) <= 0) {
                        Address t;
                        try { t = toAddr(mem.getInt(p) & 0xffffffffL); } catch (Exception e) { break; }
                        if (fm.getFunctionAt(t) == null) break;
                        slots.add(hex(t));
                        p = p.add(4);
                    }
                    if (slots.size() >= 2) {
                        Set<String> users = new TreeSet<>();
                        for (Reference r : rm.getReferencesTo(a)) {
                            Function g = getFunctionContaining(r.getFromAddress());
                            if (g != null) users.add(hex(g.getEntryPoint()) + (r.getReferenceType().isWrite() || r.getReferenceType().isData() ? "" : "?"));
                        }
                        o.printf("{\"kind\":\"vtable\",\"addr\":%s,\"slots\":%s,\"users\":%s}%n",
                                 q(hex(a)), q(String.join(",", slots)), arr(users));
                        a = p;
                    } else a = a.add(4);
                }
            }
        }
    }
}
