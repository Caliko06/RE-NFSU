#!/usr/bin/env python3
"""Lift every function of pc/Speed.exe to C in build/gen, then compile.

build/gen/fNNN.c   lifted functions, in chunks
build/gen/funcs.h  prototypes
build/gen/table.c  sorted guest address -> function table for rn_call
census/lift_report.json  counts: functions, traps by reason
Usage: .venv/bin/python tools/recomp/build.py [native|web|lift]   (default: native)
"""
import collections, json, multiprocessing as mp, os, struct, subprocess, sys
import pefile
sys.path.insert(0, os.path.dirname(__file__))
from lift import Lifter, Unsupported
import abk, patches

CHUNKS = 160
GEN = "build/gen"
FUNCS = {int(l.split()[0], 16): l.split()[1] for l in open("census/speed_exe_functions.tsv")}
L = None
# RN_JOBS caps both pools: a pod quota is smaller than os.cpu_count() and freezes the container when exceeded.
JOBS = int(os.environ.get("RN_JOBS") or os.cpu_count())


def init():
    global L
    L = Lifter("pc/Speed.exe", FUNCS)


def work(e):
    try:
        src = L.lift(e, set(FUNCS))
        cover = [(a, i.size) for a, i in L.body(e)[0].items()] if FUNCS[e] != "data" else []
        return e, src, L.info, cover, None
    except Unsupported as x:
        return e, None, None, [], str(x)


def write_if_changed(path, text):
    if os.path.exists(path) and open(path).read() == text:
        return
    open(path, "w").write(text)


def lift_all():
    os.makedirs(GEN, exist_ok=True)
    with mp.Pool(JOBS, initializer=init) as pool:
        res = pool.map(work, sorted(FUNCS), chunksize=64)
    # A data pointer that lands inside an instruction of real code is not a code start.
    inside = set()
    for e, src, info, cover, err in res:
        for a, n in cover:
            inside.update(range(a + 1, a + n))
    traps, failed, dropped, out = collections.Counter(), {}, 0, []
    for e, src, info, cover, err in res:
        if err:
            failed[hex(e)] = err
            continue
        if FUNCS[e] == "data" and e in inside:
            dropped += 1
            continue
        out.append((e, src))
        for t in info["traps"]:
            traps[t.split(" 0x")[0]] += 1
    protos = "".join(f"void f_{e:x}(Ctx *c);\n" for e, _ in out)
    write_if_changed(f"{GEN}/funcs.h", '#pragma once\n#include "rt.h"\n' + protos)
    per = (len(out) + CHUNKS - 1) // CHUNKS
    for k in range(CHUNKS):
        part = out[k * per:(k + 1) * per]
        write_if_changed(f"{GEN}/f{k:03d}.c", '#include "funcs.h"\n' + "\n".join(s for _, s in part))
    write_if_changed(f"{GEN}/table.c", '#include "funcs.h"\n'
                     f"const uint32_t rn_fn_count = {len(out)};\n"
                     "const uint32_t rn_fn_addr[] = {" + ",".join(f"0x{e:x}" for e, _ in out) + "};\n"
                     "void (*const rn_fn_ptr[])(Ctx *) = {" + ",".join(f"f_{e:x}" for e, _ in out) + "};\n"
                     + patches.c_table())
    pe = pefile.PE("pc/Speed.exe")
    img, base = pe.get_memory_mapped_image(), pe.OPTIONAL_HEADER.ImageBase
    src, _, mods = abk.c_source(FUNCS, {e for e, _ in out}, lambda a: struct.unpack_from("<I", img, a - base)[0])
    write_if_changed(f"{GEN}/abk.c", src)
    rep = {"functions": len(out), **mods, "patches": [f"{p['addr']:#x}" for p in patches.active()], "data_seeds_inside_instructions": dropped, "failed": failed,
           "trap_sites_by_reason": dict(traps.most_common())}
    json.dump(rep, open("census/lift_report.json", "w"), indent=1)
    print(f"patches active: {len(patches.active())}")
    print(f"lifted {len(out)} functions, dropped {dropped} false data seeds, failed {len(failed)}, "
          f"trap sites {sum(traps.values())}")
    print(f"ABK code modules: {mods}")
    print("top trap reasons:", dict(traps.most_common(15)))


HOST = ["host/main.c", "host/dispatch.c", "host/win32.c", "host/user32.c", "host/threads.c", "host/net.c", "host/cpu.c",
        "host/d3d9.c", "host/sm1.c", "host/gpu.c", "host/dinput8.c", "host/dsound.c", "host/files.c", "host/input.c", "host/abk.c", "host/bridge.c", "host/carsmooth.c"]


def compile_native():
    srcs = [f"{GEN}/f{k:03d}.c" for k in range(CHUNKS)] + [f"{GEN}/table.c", f"{GEN}/abk.c"]
    os.makedirs("build/obj", exist_ok=True)
    flags = ["-O1", "-w", "-Ihost", f"-I{GEN}", "-fno-strict-aliasing"]
    jobs = []
    for s in srcs:
        o = "build/obj/" + os.path.basename(s)[:-2] + ".o"
        if not os.path.exists(o) or os.path.getmtime(o) < max(os.path.getmtime(s), os.path.getmtime("host/rt.h")):
            jobs.append(["clang", *flags, "-c", s, "-o", o])
    run_jobs(jobs)
    objs = ["build/obj/" + os.path.basename(s)[:-2] + ".o" for s in srcs]
    subprocess.run(["clang", "-O1", "-g", "-Wall", "-Wno-unused-function", "-Ihost", f"-I{GEN}", *HOST, *objs,
                    "-o", "build/speed"], check=True)
    print("built build/speed")


def compile_web():
    srcs = [f"{GEN}/f{k:03d}.c" for k in range(CHUNKS)] + [f"{GEN}/table.c", f"{GEN}/abk.c"]
    os.makedirs("build/wobj", exist_ok=True)
    flags = ["-O1", "-w", "-Ihost", f"-I{GEN}", "-fno-strict-aliasing", "-pthread"]
    jobs = []
    for s in srcs:
        o = "build/wobj/" + os.path.basename(s)[:-2] + ".o"
        if not os.path.exists(o) or os.path.getmtime(o) < max(os.path.getmtime(s), os.path.getmtime("host/rt.h")):
            jobs.append(["emcc", *flags, "-c", s, "-o", o])
    run_jobs(jobs)
    objs = ["build/wobj/" + os.path.basename(s)[:-2] + ".o" for s in srcs]
    os.makedirs("web/out", exist_ok=True)
    # main() runs in a worker (PROXY_TO_PTHREAD) so guest threads and waits may block.
    subprocess.run(["emcc", "-O1", "-pthread", "-Ihost", f"-I{GEN}", *HOST, *objs, "-o", "web/out/speed.js",
                    "-sINITIAL_MEMORY=2048MB", "-sSTACK_SIZE=16MB", "-sDEFAULT_PTHREAD_STACK_SIZE=16MB",
                    "-sPROXY_TO_PTHREAD=1", "-sPTHREAD_POOL_SIZE=8", "-sEXIT_RUNTIME=1",
                    "-sMODULARIZE=1", "-sEXPORT_NAME=Speed", "-sEXPORTED_RUNTIME_METHODS=FS,ENV,HEAPU8,HEAP32,HEAPU32,HEAPF64",
                    "-sEXPORTED_FUNCTIONS=_main,_rn_gpu_mailbox,_rn_input_ring,_rn_audio_ring,_rn_telem_addr,_rn_tune_addr",
                    "-sFORCE_FILESYSTEM=1", "-sENVIRONMENT=web,worker",
                    # RN_PROF=1: keep function names for a CPU profile (tools/webcheck.mjs RN_PROFILE); same code.
                    *(["--profiling-funcs"] if os.environ.get("RN_PROF") else [])], check=True)
    print("built web/out/speed.js + speed.wasm")


def run_jobs(jobs):
    running, bad = [], 0
    for j in jobs:
        while len(running) >= JOBS:
            bad += running.pop(0).wait() != 0
        running.append(subprocess.Popen(j))
    bad += sum(p.wait() != 0 for p in running)
    if bad:
        sys.exit("compile failed")
    if jobs:
        print(f"compiled {len(jobs)} files")


if __name__ == "__main__":
    what = sys.argv[1] if len(sys.argv) > 1 else "native"
    lift_all()
    if what == "native":
        compile_native()
    elif what == "web":
        compile_web()
