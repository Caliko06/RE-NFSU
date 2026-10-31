// Ghidra headless post-script: every cross-reference whose target lies in a data range, with the function that
// makes it. Answers "who reads or writes 0x733f78" for the whole binary in one pass, which is the base for
// understanding data structures (census has no such table today; imports_sites.tsv covers imports only).
// usage: analyzeHeadless DIR PROJ -process Speed.exe -noanalysis -readOnly -scriptPath tools/ghidra \
//          -postScript DataXrefs.java OUT 0x697000 0x795000
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import java.io.FileWriter;
import java.io.PrintWriter;

public class DataXrefs extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        long lo = Long.parseLong(a[1].replace("0x", ""), 16);
        long hi = Long.parseLong(a[2].replace("0x", ""), 16);
        PrintWriter w = new PrintWriter(new FileWriter(a[0]));
        w.println("data\tfrom\tfunc\tname\tkind");
        ReferenceIterator it = currentProgram.getReferenceManager().getReferenceIterator(toAddr(lo));
        long n = 0, kept = 0;
        while (it.hasNext()) {
            Reference r = it.next();
            Address to = r.getToAddress();
            if (to == null) continue;
            long t = to.getOffset();
            if (t > hi) break;
            n++;
            if (t < lo) continue;
            Address from = r.getFromAddress();
            Function f = getFunctionContaining(from);
            if (f == null) continue;   // data -> data pointer tables carry no reader; only code-originated refs count
            w.println(String.format("%06x\t%06x\t%06x\t%s\t%s", t, from.getOffset(),
                    f.getEntryPoint().getOffset(), f.getName().replace('\t', ' '),
                    r.getReferenceType().toString()));
            kept++;
        }
        w.close();
        println("DataXrefs: " + kept + " kept of " + n + " references in " + a[1] + ".." + a[2]);
    }
}
