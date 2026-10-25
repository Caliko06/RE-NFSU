// Ghidra headless post-script: every function whose entry is in [LO, HI) -> names and types (TSV) and the decompiled C.
// usage: analyzeHeadless DIR PROJ -process Speed.exe -noanalysis -readOnly -scriptPath tools/ghidra -postScript ExportRange.java LO HI OUTDIR
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import java.io.*;

public class ExportRange extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address lo = toAddr(a[0]), hi = toAddr(a[1]);
        new File(a[2]).mkdirs();
        String tag = a[0] + "_" + a[1];
        PrintWriter tsv = new PrintWriter(new FileWriter(a[2] + "/funcs_" + tag + ".tsv"));
        PrintWriter c = new PrintWriter(new FileWriter(a[2] + "/decomp_" + tag + ".c"));
        tsv.println("entry\tname\tsignature\tcalling\tparams\tlocals\tbytes");
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        int n = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(lo, true)) {
            if (f.getEntryPoint().compareTo(hi) >= 0 || monitor.isCancelled()) break;
            StringBuilder ps = new StringBuilder(), ls = new StringBuilder();
            for (Parameter p : f.getParameters()) ps.append(p.getDataType().getName()).append(' ').append(p.getName()).append(';');
            for (Variable v : f.getLocalVariables()) ls.append(v.getDataType().getName()).append(' ').append(v.getName()).append(';');
            tsv.println(f.getEntryPoint() + "\t" + f.getName() + "\t" + f.getPrototypeString(false, false) + "\t" + f.getCallingConventionName()
                        + "\t" + ps + "\t" + ls + "\t" + f.getBody().getNumAddresses());
            DecompileResults r = di.decompileFunction(f, 60, monitor);
            c.println("// " + f.getEntryPoint() + " " + f.getName());
            c.println(r.decompileCompleted() ? r.getDecompiledFunction().getC() : "// decompile failed: " + r.getErrorMessage());
            if (++n % 200 == 0) { tsv.flush(); c.flush(); println(tag + ": " + n); }
        }
        tsv.close(); c.close(); di.dispose();
        println(tag + ": DONE " + n + " functions");
    }
}
