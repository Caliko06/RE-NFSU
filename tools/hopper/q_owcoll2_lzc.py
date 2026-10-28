#!/usr/bin/env python3
"""q_owcoll2_lzc.py: the .lzc container ("JDLZ" version 2) as Speed.exe reads it, plus a writer.
Reader = FUN_0058d190 (0x58d190) ported exactly, including how it counts the stream (so a writer can end it right).
  header 16 B: 'JDLZ', u8 version = 2, u8 = 0x10, u16 = 0, u32 usize @8, u32 csize @12 (= whole file size)
  @0x10 flag byte A (literal/match bit, LSB first), @0x11 flag byte B (match form bit), tokens from @0x12
  A bit 0 = literal byte; A bit 1 = match (2 bytes, b0 b1) and B's next bit chooses its form:
    B bit 1 (short):  len = (((b0 & 0xf0) << 4) | b1) + 3, dist = (b0 & 0x0f) + 1
    B bit 0 (long):   len = (b0 & 0x1f) + 3,               dist = (((b0 & 0xe0) << 3) | b1) + 0x11
  A is shifted after every token, B only after a match; when a flag register is empty (only the sentinel bit left)
  the next stream byte is its refill, A's refill before B's, immediately after the token (even at the very end).
  The loop runs until csize - 0x12 bytes are consumed (literal 1, match 2, refill 1 each).
usage: q_owcoll2_lzc.py            (self test on all 16 TRACKB files: exe decoder == lib decoder, encoder round trip)
"""
import os, struct, sys, time
HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
os.environ.setdefault('NFSU1_MAIN', REPO)
sys.path.insert(0, os.path.join(REPO, 'ref', 'tools', 'ug1-tracks'))
sys.path.insert(0, os.path.join(REPO, 'ref', 'tools'))
from lib import trackb_path, PC  # noqa: E402
from jdlz import jdlz_decompress  # noqa: E402


def exe_decode(buf):
    """FUN_0058d190 transcribed. returns the output (len = usize)"""
    assert buf[:4] == b'JDLZ' and buf[4] == 2
    usize, csize = struct.unpack_from('<II', buf, 8)
    out = bytearray(usize)
    o = 0
    p = 0x12
    f1 = buf[0x10] | 0x100
    f2 = buf[0x11] | 0x100
    left = csize - 0x12
    while left != 0:
        if (f1 & 1) == 0:
            if o < usize:
                out[o] = buf[p]
                o += 1
            p += 1
            step = -1
        else:
            b1 = buf[p + 1]
            b0 = buf[p]
            if (f2 & 1) == 0:
                n = (b0 & 0x1f) + 3
                dist = (((b0 & 0xe0) << 3) | b1) + 0x11
            else:
                n = (((b0 & 0xf0) << 4) | b1) + 3
                dist = (b0 & 0x0f) + 1
            for k in range(n):
                out[o + k] = out[o + k - dist]
            o += n
            f2 >>= 1
            p += 2
            step = -2
        left += step
        f1 >>= 1
        if f1 == 1:
            f1 = buf[p] | 0x100
            p += 1
            left -= 1
        if f2 == 1:
            f2 = buf[p] | 0x100
            p += 1
            left -= 1
    assert p == csize == len(buf), 'stream not consumed exactly: p=%d csize=%d len=%d' % (p, csize, len(buf))
    return bytes(out)


def encode(data, window=True):
    """greedy LZ writer for the format above. window=False = literal only (a valid 'stored' file, ~1.125x)."""
    n = len(data)
    out = bytearray(b'JDLZ\x02\x10\x00\x00' + struct.pack('<II', n, 0))
    out += b'\0\0'                        # flag bytes A, B (filled below)
    a_slot, a_bits, b_slot, b_bits = 0x10, 0, 0x11, 0
    head = {}
    i = 0

    def emit(is_match, short=False):
        nonlocal a_slot, a_bits, b_slot, b_bits
        if is_match:
            out[a_slot] |= 1 << a_bits
            if short:
                out[b_slot] |= 1 << b_bits
        a_bits += 1
        if is_match:
            b_bits += 1
        if a_bits == 8:                   # exe: refill A right after the token
            out.append(0)
            a_slot, a_bits = len(out) - 1, 0
        if is_match and b_bits == 8:      # then refill B
            out.append(0)
            b_slot, b_bits = len(out) - 1, 0

    while i < n:
        best_len = best_dist = 0
        if window and i + 3 <= n:
            key = data[i:i + 3]
            for j in reversed(head.get(key, [])[-48:]):
                dist = i - j
                if dist > 0x80f:          # long form reaches 17 + 2047
                    break
                m = 3
                lim = min(n - i, 0xfff + 3 if dist <= 16 else 34)   # short form: len <= 4098; long form: len <= 34
                while m < lim and data[i + m - dist] == data[i + m]:
                    m += 1
                if m > best_len:
                    best_len, best_dist = m, dist
                    if m == lim:
                        break
        if best_len >= 3:
            if best_dist <= 16:
                v = best_len - 3
                out += bytes([((v >> 4) & 0xf0) | (best_dist - 1), v & 0xff])
                emit(True, True)
            else:
                d = best_dist - 0x11
                out += bytes([((d >> 3) & 0xe0) | (best_len - 3), d & 0xff])
                emit(True, False)
            step = best_len
        else:
            out.append(data[i])
            emit(False)
            step = 1
        if window:
            for k in range(i, min(i + step, n - 2)):
                head.setdefault(data[k:k + 3], []).append(k)
        i += step
    struct.pack_into('<I', out, 12, len(out))
    return bytes(out)


def main():
    ids = [int(a) for a in sys.argv[1:]] or list(range(1001, 1009)) + list(range(1102, 1110))
    for t in ids:
        raw = open(trackb_path(PC, t), 'rb').read()
        t0 = time.time()
        a = exe_decode(raw)
        b = jdlz_decompress(raw)
        t1 = time.time()
        enc = encode(a)
        t2 = time.time()
        back = exe_decode(enc)
        sto = encode(a[:200000], window=False)
        print(t, 'exe_decode==lib', a == b, '| orig %d -> usize %d | encode %d B (%.2fx of orig) round trip %s (%.1fs) | stored[200000]: %d B ok %s' % (
            len(raw), len(a), len(enc), len(enc) / len(raw), back == a, t2 - t1, len(sto), exe_decode(sto) == a[:200000]), flush=True)


if __name__ == '__main__':
    main()
