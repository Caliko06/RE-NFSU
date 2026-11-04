"""Overlays of two shipped TPK files for the WORLD / Free Run layer (the game/ folder is read-only; the layer serves these from
build/openworld, host/openworld.c rn_world_open). Built with tools/remaster/tpkwrite.py; no pixels need cutting for the cars.
  build/openworld/CARS_TEXTURES.BIN  Cars/TEXTURES.BIN + DUMMY_SKIN5..28 and DUMMY_WHEEL5..28 (clones of 1 / 1): the render
                                     targets the rivals' (5..10) and traffic racers' (13..28) bodies and rims are baked into (docs/openworld/re_traffic_racers.md).
  build/openworld/DYNTEX.BIN         Global/DYNTEX.BIN + TRACK_1010_SPLINE and TRACK_1010 (SELECT LOCATION page, re_select_picture.md 3b),
                                     drawn by tools/openworld/worldmap.py's tour when its picture exists.
usage: python3 tools/remaster/world_overlays.py cars | select   (select needs build/openworld/TRACKB1010.lzc: tools/openworld/tour.py)"""
import os, struct, sys
here = os.path.dirname(os.path.abspath(__file__))
root = os.path.dirname(os.path.dirname(here))
sys.path.insert(0, here)
from tpkwrite import Tpk
OUT = os.path.join(root, 'build', 'openworld')


def cars():
    t = Tpk(os.path.join(root, 'game', 'Cars', 'TEXTURES.BIN'))
    end = t.pool_end()                                 # the new targets get virtual pool offsets past every shipped one
    for fam, src, size in (('DUMMY_SKIN', 'DUMMY_SKIN1', 0x100000), ('DUMMY_WHEEL', 'DUMMY_WHEEL1', 0x10000)):
        for k in range(5, 29):
            off = (end + 0xffff) & ~0xffff
            end = off + size
            t.clone(f'{fam}{k}', src, fields={0x30: struct.pack('<II', off, off + size)})
    os.makedirs(OUT, exist_ok=True)
    n = t.save(os.path.join(OUT, 'CARS_TEXTURES.BIN'))
    print('CARS_TEXTURES.BIN', n, 'bytes,', len(t.recs), 'entries')


def select():
    sys.path.insert(0, os.path.join(root, 'tools', 'openworld'))
    import dxtenc, selectpic
    spl, photo = selectpic.render()
    t = Tpk(os.path.join(root, 'game', 'Global', 'DYNTEX.BIN'))
    end = t.pool_end()
    for name, src, img, kind, size in (('TRACK_1010_SPLINE', 'TRACK_1001_SPLINE', spl, 3, 0x55540), ('TRACK_1010', 'TRACK_1001', photo, 1, 0x2aaa0)):
        raw = dxtenc.chain(img, kind, 7)                   # 7 levels, 512 down to 8: the shipped records' size 0x55540 / 0x2aaa0
        assert len(raw) == size, (name, len(raw))
        off = (end + 127) & ~127
        end = off + size
        t.clone(name, src, pixels=raw, fields={0x30: struct.pack('<II', off, (off + size + 63) & ~63)})
    os.makedirs(OUT, exist_ok=True)
    n = t.save(os.path.join(OUT, 'DYNTEX.BIN'))
    print('DYNTEX.BIN', n, 'bytes,', len(t.recs), 'entries')


if __name__ == '__main__':
    {'cars': cars, 'select': select}[sys.argv[1]]()
