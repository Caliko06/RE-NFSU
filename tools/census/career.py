"""Underground career oracle, read from Speed.exe's own data and rules -> census/career_oracle.json.

Data: FrontB.lzc (JDLZ) chunk 0x80034A00, loaded by 0x5a00a0: child 0x34A02 = event records of 0x14c bytes, indexed by
id into [0x733ff8 + 4*id] (0x5a0060); child 0x34A01 = 0x20-byte tables into [0x733f78 + 4*id] (0x5a0100).
Record fields (each read by the code named):
  +0x00 id. +0x04 kind: 1 tournament (stages), 2 / 3 Junkman / Samantha events (0x4ab670 picks MU_UG_JunkmanGiveth /
        SamanthaGiveth on race +0x58a4), 8 never opens (0x5a0fc0). +0x08 race mode. +0x10 entry fee (0x5a0d43).
  +0x28 + 4*d cash for a win at difficulty d (0x5a0e3b, d = career +0x348 = [0x75f240], set by the briefing 0x4c5df0).
  +0x38 rewards: [+0x74] triples (type, value, arg), given by 0x5a0dc0 / 0x5a3f00.
  +0x78 stages: [+0x98] x (u16 track, u8 laps, u8 direction); 0x4b5df0 copies the race stage to 0x78a2f0 / 0x78a2fc / 0x78a31c.
  +0x9c prerequisites: [+0xaa] i16 ids, rule [+0xa8] 0 = all, 1 = any (0x5a0fc0).
  +0xac, +0xb8, +0xc4 movie names (12 bytes each), see MOVIES below.
  +0xd4 opponents: 3 x 0x1c (name, 8 bytes; +0xc car hash).
Career status: byte [0x75eef8 + 0x34c + id]: 0 locked, 1 open, 2 won, 3 racing (0x5a0ce0), 5 quit (0x5a0f60). 0x5a1100
opens every event that is not won (2 / 4), not kind 8, and whose prerequisites are done (0x5a0fc0): done = won, or
4 / 5 for a prerequisite of kind 2 or 3. Event 0x71 = 113 won sets the career-beaten flag [0x7677ac] (0x5a0dc0).
usage: career.py [out.json]
"""
import json, os, struct, sys
sys.path.insert(0, os.path.dirname(__file__))
from jdlz import jdlz_decompress

R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
REC = 0x14c

# Movies (0x4c5df0, 0x4e8180, 0x4e86d0, 0x4c4ee0): slot 1 (+0xac) plays before the race. For events 7, 15 and 92 the
# event list (0x4c4ee0 -> 0x4c4f00, [0x735dc8] = id) plays it before the briefing; for the others the map start
# 0x4c5df0 swaps the map for MU_UG_NewCareerFMV, whose end starts the race (0x4e862f -> 0x4b5df0). Event 0 plays it
# from the new-career path (0x4b37d0). After the race 0x4c72d0 / 0x4ab670 open MU_UG_NewCareerExtroFMV when slot 2 or 3
# is set; 0x4e86d0 plays slot 3 when the event is won (0x5a2f10), else slot 2. Event 0 (the prologue) shows that screen
# twice: slot 3 + "_S" while no car is owned ([0x76027c] == 0, 0x4e880a), whose end opens MU_UG_ChooseCareerCar
# (0x4e8a06); the purchase (0x4c37de: cash [0x76026c] -= price, spent [0x760274] += price) then shows it again with
# "_E", whose end opens MU_UG_MapScreen. 04_GUM_s is the first garage visit (0x4eb06e sets [0x735dc4], 0x4e82ab).
BRIEFING_FIRST = (7, 15, 92)


def records(path=f'{R}/game/FrontEnd/FrontB.lzc'):
    d = jdlz_decompress(open(path, 'rb').read())
    i = d.find(struct.pack('<I', 0x34a02))
    n = struct.unpack_from('<I', d, i + 4)[0]
    return [d[i + 8 + k * REC:i + 8 + (k + 1) * REC] for k in range(n // REC)]


def event(r):
    I = lambda o: struct.unpack_from('<I', r, o)[0]
    h = lambda o: struct.unpack_from('<h', r, o)[0]
    f = lambda o: round(struct.unpack_from('<f', r, o)[0], 3)
    s = lambda o, n: r[o:o + n].split(b'\0')[0].decode('latin1')
    eid, kind = I(0), I(4)
    slots = [s(o, 12) for o in (0xac, 0xb8, 0xc4)]
    before = slots[0] or None
    after_win = [slots[2] + '_S', slots[2] + '_E'] if eid == 0 and slots[2] else [slots[2]] if slots[2] else []
    return {
        'id': eid, 'kind': kind, 'mode': I(8), 'fee': f(0x10),
        'cash': [f(0x28), f(0x2c), f(0x30)],
        'stages': [{'track': struct.unpack_from('<H', r, 0x78 + 4 * k)[0], 'laps': r[0x7a + 4 * k], 'direction': r[0x7b + 4 * k]}
                   for k in range(I(0x98))],
        'prereq': {'rule': 'any' if h(0xa8) == 1 else 'all', 'ids': [h(0x9c + 2 * k) for k in range(h(0xaa))]},
        'opponents': [{'name': s(0xd4 + 0x1c * k, 8), 'car': f'{I(0xd4 + 0x1c * k + 0xc):08x}'} for k in range(3) if r[0xd4 + 0x1c * k]],
        'rewards': [{'type': I(0x38 + 12 * k), 'value': f'{I(0x3c + 12 * k):x}', 'arg': I(0x40 + 12 * k)} for k in range(I(0x74))],
        'movie_slots': slots,
        'movies': {'before': before, 'before_at': 'event list' if eid in BRIEFING_FIRST else 'race start' if before else None,
                   'after_win': after_win, 'after_loss': slots[1] or None},
    }


def opens(ev, st):
    """0x5a0fc0: would event ev open with statuses st (id -> byte)."""
    if st.get(ev['id'], 0) in (2, 4) or ev['kind'] == 8: return False
    done = lambda p: st.get(p, 0) == 2 or (st.get(p, 0) in (4, 5) and EV[p]['kind'] in (2, 3))
    ds = [done(p) for p in ev['prereq']['ids']]
    return all(ds) if ev['prereq']['rule'] == 'all' else any(ds)


def walk(difficulty=1):
    """Win every event, always the lowest open id (the trace's policy). Each step: the open list before, what opened after."""
    st, steps, cash = {0: 1}, [], 0
    while True:
        op = sorted(i for i, v in st.items() if v == 1)
        if not op: break
        e = op[0]
        st[e] = 2
        cash += int(EV[e]['cash'][difficulty]) - int(EV[e]['fee'])
        new = sorted(i for i, ev in EV.items() if st.get(i, 0) != 1 and opens(ev, st))
        for i in new: st[i] = 1
        steps.append({'event': e, 'open_before': op, 'opened': new, 'cash_after': cash})
    return steps, sorted(i for i in EV if st.get(i, 0) != 2)


EV = {}
if __name__ == '__main__':
    for r in records():
        e = event(r)
        EV[e['id']] = e
    steps, never = walk()
    out = {'source': 'game/FrontEnd/FrontB.lzc chunk 0x34A02 (0x14c records), rules from Speed.exe (see tools/census/career.py)',
           'difficulty': 1, 'final_event': 0x71,
           'events': list(EV.values()), 'order': steps, 'never_won': never,
           'story_movies': [m for e in EV.values() for m in e['movie_slots'] if m]}
    p = sys.argv[1] if len(sys.argv) > 1 else f'{R}/census/career_oracle.json'
    json.dump(out, open(p, 'w'), indent=1)
    print(f'{len(EV)} events, {len(steps)} wins in order, never won: {never}, final cash {steps[-1]["cash_after"]}')
