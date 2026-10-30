// Ghidra headless post-script: give every function the name that census/names.tsv records (addr<TAB>name<TAB>...; first line is the header).
// The project is SAVED (do not pass -readOnly): run it on a copy. Names get "::" and other non-identifier characters replaced by "_".
// usage: analyzeHeadless DIR PROJ -process Speed.exe -noanalysis -scriptPath tools/ghidra -postScript ApplyNames.java names.tsv
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.io.*;
import java.nio.file.*;

public class ApplyNames extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        int renamed = 0, missing = 0, same = 0;
        boolean first = true;
        for (String line : Files.readAllLines(Paths.get(a[0]))) {
            if (first) { first = false; continue; }
            String[] c = line.split("\t", -1);
            if (c.length < 2 || !c[0].startsWith("0x") || c[1].isEmpty()) continue;
            Function f = getFunctionAt(toAddr(Long.parseLong(c[0].substring(2), 16)));
            if (f == null) { missing++; continue; }
            String n = c[1].replaceAll("[^A-Za-z0-9_]", "_");
            if (f.getName().equals(n)) { same++; continue; }
            try { f.setName(n, SourceType.USER_DEFINED); renamed++; } catch (Exception e) { missing++; }
        }
        println("ApplyNames: renamed " + renamed + ", already " + same + ", no function or refused " + missing);
    }
}
