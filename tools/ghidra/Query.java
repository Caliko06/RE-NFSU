// Ghidra headless script: answers a batch of questions on an analyzed program (the pod keeps the project).
// analyzeHeadless <dir> proj -process Speed.exe -noanalysis -readOnly -postScript Query.java <plan.txt> <out.txt>
// Plan lines: "decomp <addr>" (the function holding it), "xref <addr>" (who reads, writes or calls it, with the
// function), "scalar <hex>" (instructions with that immediate or displacement), "callers <addr>" (calls into it),
// "make <addr>" (create the function if analysis missed it, then decompile).
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;

public class Query extends GhidraScript {
    private String fn(Address a) {
        Function f = getFunctionContaining(a);
        return f == null ? "?" : f.getEntryPoint() + " " + f.getName();
    }
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        DecompInterface d = new DecompInterface();
        d.openProgram(currentProgram);
        Listing l = currentProgram.getListing();
        try (PrintWriter o = new PrintWriter(new BufferedWriter(new FileWriter(args[1])))) {
            for (String line : Files.readAllLines(Paths.get(args[0]))) {
                String[] p = line.trim().split("\\s+");
                if (p.length < 2) continue;
                o.println("=== " + line.trim());
                if (p[0].equals("decomp")) {
                    Function f = getFunctionContaining(toAddr(p[1]));
                    if (f == null) { o.println("no function"); continue; }
                    DecompileResults r = d.decompileFunction(f, 120, monitor);
                    o.println(r.decompileCompleted() ? r.getDecompiledFunction().getC() : "failed: " + r.getErrorMessage());
                } else if (p[0].equals("make")) {
                    // A lifter entry Ghidra's analysis missed (vtable or callback targets): create it, then decompile
                    // in the decomp.c block format. An entry inside another function is reported, not split.
                    Address a = toAddr(p[1]);
                    Function f = getFunctionAt(a);
                    if (f == null && getFunctionContaining(a) != null) { o.println("inside " + fn(a)); continue; }
                    if (f == null) { disassemble(a); f = createFunction(a, null); }
                    if (f == null) { o.println("create failed"); continue; }
                    o.printf("// FUN %s %s %d%n", f.getEntryPoint(), f.getName(), f.getBody().getNumAddresses());
                    DecompileResults r = d.decompileFunction(f, 60, monitor);
                    o.println(r.decompileCompleted() ? r.getDecompiledFunction().getC() : "// decompile failed: " + r.getErrorMessage());
                } else if (p[0].equals("xref") || p[0].equals("callers")) {
                    for (Reference r : getReferencesTo(toAddr(p[1])))
                        if (p[0].equals("xref") || r.getReferenceType().isCall())
                            o.println(r.getFromAddress() + " " + r.getReferenceType() + " in " + fn(r.getFromAddress()));
                } else if (p[0].equals("scalar")) {
                    long v = Long.parseUnsignedLong(p[1].replace("0x", ""), 16);
                    int n = 0;
                    for (Instruction i : l.getInstructions(true)) {
                        for (int k = 0; k < i.getNumOperands(); k++)
                            for (Object x : i.getOpObjects(k))
                                if (x instanceof Scalar && (((Scalar) x).getUnsignedValue() & 0xffffffffL) == v) {
                                    o.println(i.getAddress() + " " + i + " in " + fn(i.getAddress()));
                                    n++;
                                }
                        if (n > 400) break;
                    }
                }
            }
        }
        d.dispose();
    }
}
