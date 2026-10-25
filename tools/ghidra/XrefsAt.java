// Ghidra headless post-script: for each address, the references to it (from, type, instruction, containing function)
// and, when it is a function, its signature with types and its callees. Pairs with DecompAt.java (-readOnly).
// usage: analyzeHeadless DIR PROJ -process Speed.exe -noanalysis -readOnly -scriptPath tools/ghidra -postScript XrefsAt.java OUT ADDR...
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class XrefsAt extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        PrintWriter c = new PrintWriter(new FileWriter(a[0]));
        Listing l = currentProgram.getListing();
        for (int i = 1; i < a.length; i++) {
            Address at = toAddr(a[i]);
            Function f = getFunctionAt(at);
            c.println("## " + at + (f != null ? " function " + f.getSignature().getPrototypeString() : " data"));
            if (f != null) {
                for (Parameter p : f.getParameters()) c.println("  param " + p.getOrdinal() + " " + p.getDataType().getName() + " " + p.getName() + " @" + p.getVariableStorage());
                for (Function g : f.getCalledFunctions(monitor)) c.println("  calls " + g.getEntryPoint() + " " + g.getName());
            } else {
                Data d = l.getDataContaining(at);
                if (d != null) c.println("  type " + d.getDataType().getName() + " len " + d.getLength());
            }
            for (Reference r : getReferencesTo(at)) {
                Address from = r.getFromAddress();
                Function g = getFunctionContaining(from);
                Instruction ins = l.getInstructionAt(from);
                c.println("  ref " + from + " " + r.getReferenceType() + " in " + (g == null ? "?" : g.getEntryPoint() + " " + g.getName())
                          + (ins == null ? "" : " : " + ins));
            }
            c.flush();
        }
        c.close();
        println("XrefsAt: DONE " + (a.length - 1));
    }
}
