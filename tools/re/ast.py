"""Read-only reader for EA .ast stream banks (game/SNDSTREAMS/*.ast, game/SpeechStreams/*.ast); docs/re/sound.md.

  ast.py list FILE        one line per stream: index, offset, channels, rate, samples, seconds, codec
  ast.py check [FILE...]  walk every byte: each stream is SCHl, SCCl, SCDl..., SCEl; the gaps between streams must
                          be zero padding. Exit 1 on any byte that is neither a chunk nor padding.

Chunk = 4-byte tag + u32 little-endian size including the 8-byte head. SCHl carries "PT\0\0" and a tag list
(tag byte, length byte, big-endian value; 0xFD opens the sample block, 0xFF ends the header), the EA layout also
documented by vgmstream (ea_schl). The tag numbers kept here are the ones the files use.
"""
import os, struct, sys

B = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
TAGS = {0x82: "channels", 0x83: "codec", 0x84: "rate", 0x85: "samples", 0x86: "loop_start", 0x87: "loop_end",
        0x80: "version", 0xA0: "codec2"}


def pt(d, o, end):
    """Parse the PT tag list starting at d[o] (after 'PT\\0\\0'); return dict of known tags."""
    out = {}
    while o < end:
        t = d[o]; o += 1
        if t == 0xFF:
            break
        if t in (0xFC, 0xFD, 0xFE):      # sub-block markers carry no length
            continue
        n = d[o]; o += 1
        v = int.from_bytes(d[o:o + n], "big"); o += n
        out[TAGS.get(t, f"t{t:02x}")] = v
    return out


def streams(path):
    d = open(path, "rb").read()
    o, out, pad, bad = 0, [], 0, []
    while o < len(d):
        if d[o:o + 4] != b"SCHl":
            z = o
            while o < len(d) and d[o] == 0:
                o += 1
            if o == z:
                bad.append(o)
                break
            pad += o - z
            continue
        start, blocks, data = o, 0, 0
        hsize = struct.unpack_from("<I", d, o + 4)[0]
        h = pt(d, o + 12, o + hsize) if d[o + 8:o + 10] == b"PT" else {}
        o += hsize
        while o + 8 <= len(d):
            tag, sz = d[o:o + 4], struct.unpack_from("<I", d, o + 4)[0]
            if tag not in (b"SCCl", b"SCDl", b"SCEl") or sz < 8:
                bad.append(o)
                break
            blocks += tag == b"SCDl"
            data += sz if tag == b"SCDl" else 0
            o += sz
            if tag == b"SCEl":
                break
        out.append({"index": len(out), "offset": start, "size": o - start, "blocks": blocks, **h})
        if bad:
            break
    return out, pad, bad, len(d)


def main(a):
    if a and a[0] == "list":
        for s in streams(a[1])[0]:
            ch, rate, n = s.get("channels", 1), s.get("rate", 22050), s.get("samples", 0)
            print(f"{s['index']:4d} {s['offset']:#010x} ch={ch} rate={rate} samples={n} "
                  f"sec={n / rate:.2f} codec={s.get('codec', '-')} blocks={s['blocks']}")
        return
    files = a[1:] if len(a) > 1 else [os.path.join(B, "game", "SNDSTREAMS", f) for f in
                                      sorted(os.listdir(os.path.join(B, "game", "SNDSTREAMS")))] + \
        [os.path.join(B, "game", "SpeechStreams", f) for f in sorted(os.listdir(os.path.join(B, "game", "SpeechStreams")))]
    ok = True
    for f in files:
        ss, pad, bad, n = streams(f)
        cover = sum(s["size"] for s in ss) + pad
        secs = sum(s.get("samples", 0) / s.get("rate", 22050) for s in ss)
        print(f"{os.path.basename(f)}: {len(ss)} streams, {secs / 60:.1f} min, chunks+padding {cover}/{n} bytes,"
              f" rates {sorted(set(s.get('rate') for s in ss))}, channels {sorted(set(s.get('channels', 1) for s in ss))}"
              + (f", BAD at {bad[0]:#x}" if bad else ""))
        ok &= not bad and cover == n
    sys.exit(0 if ok else 1)


if __name__ == "__main__":
    main(sys.argv[1:])
