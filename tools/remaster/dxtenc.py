"""Small DXT1 / DXT3 encoder (numpy): bounding-box endpoints, nearest of the four palette colours. Enough for flat map art.
mips(rgba, n) -> n box-filtered levels; encode(rgba, kind) -> level bytes (kind 1 = DXT1 = TPK format 0x22, 3 = DXT3 = 0x24);
chain(rgba, kind, levels) -> all levels concatenated, the pixel layout of a TextureInfo (level 0 first, no padding)."""
import numpy as np


def _565(c):
    return ((c[..., 0] >> 3).astype(np.uint16) << 11) | ((c[..., 1] >> 2).astype(np.uint16) << 5) | (c[..., 2] >> 3).astype(np.uint16)


def _888(v):
    r, g, b = (v >> 11) & 31, (v >> 5) & 63, v & 31
    return np.stack([r * 255 // 31, g * 255 // 63, b * 255 // 31], -1).astype(np.int32)


def encode(rgba, kind):
    h, w = rgba.shape[:2]
    bl = rgba.reshape(h // 4, 4, w // 4, 4, 4).transpose(0, 2, 1, 3, 4).reshape(-1, 16, 4)
    rgb = bl[..., :3].astype(np.int32)
    c0, c1 = _565(rgb.max(1).astype(np.uint8)), _565(rgb.min(1).astype(np.uint8))
    hi, lo = np.maximum(c0, c1), np.minimum(c0, c1)               # c0 > c1: the four-colour mode (DXT1 needs it)
    p0, p1 = _888(hi), _888(lo)
    pal = np.stack([p0, p1, (2 * p0 + p1) // 3, (p0 + 2 * p1) // 3], 1)          # (n, 4, 3)
    d = ((rgb[:, :, None, :] - pal[:, None, :, :]) ** 2).sum(-1)                 # (n, 16, 4)
    idx = d.argmin(-1).astype(np.uint32)
    bits = (idx << (2 * np.arange(16, dtype=np.uint32))).sum(1).astype(np.uint32)
    col = np.zeros((len(bl), 8), np.uint8)
    col[:, 0:2] = hi.astype('<u2').view(np.uint8).reshape(-1, 2)
    col[:, 2:4] = lo.astype('<u2').view(np.uint8).reshape(-1, 2)
    col[:, 4:8] = bits.astype('<u4').view(np.uint8).reshape(-1, 4)
    if kind == 1:
        return col.tobytes()
    a4 = ((bl[..., 3].astype(np.uint32) * 15 + 127) // 255)
    abits = (a4.astype(np.uint64) << (4 * np.arange(16, dtype=np.uint64))).sum(1)
    al = abits.astype('<u8').view(np.uint8).reshape(-1, 8)
    return np.concatenate([al, col], 1).tobytes()


def mips(rgba, n):
    from PIL import Image
    out, im = [rgba], Image.fromarray(rgba, 'RGBA')
    for _ in range(n - 1):
        im = im.resize((max(4, im.width // 2), max(4, im.height // 2)), Image.BOX)
        out.append(np.array(im))
    return out


def chain(rgba, kind, levels):
    return b''.join(encode(m, kind) for m in mips(rgba, levels))
