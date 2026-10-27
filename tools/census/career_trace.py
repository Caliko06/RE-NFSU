"""Native career trace (RN_CAREER, host/input.c input_career) -> census/career_trace.json, and its diff with the oracle.

The run: a new profile, unlock patches off (RN_UNLOCK=0), each next event the lowest id of the game's own open list,
the win from RN_FINISH. Per event: what the race loaded (track, the stage words 0x78a2fc / 0x78a31c, opponents from the
race's copy of the record), the files it opened (TRACKB, MOVIES), the result (status, cash gain, what opened, covers).
usage: career_trace.py <run log> [out.json]     (prints the differences; exit 1 when any is unexplained)
"""
import json, os, re, sys
R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

# Differences the code explains (address -> why). Filled only from Speed.exe reading, never to make a diff go away.
EXPLAINED = {}


def parse(log):
    ev, cur, out = {}, {'id': 0, 'tracks': [], 'movies': []}, []
    for l in open(log, errors='replace'):
        m = re.match(r'career start (\d+) open (\S+) cash (-?\d+)', l)
        if m:
            cur = {'id': int(m[1]), 'open_before': [int(x) for x in m[2].split(',')], 'tracks': [], 'movies': []}
            continue
        m = re.search(r'flow open .*TRACKB(\d{4})\.LZC', l, re.I)
        if m and int(m[1]) not in cur['tracks'][-1:]: cur['tracks'].append(int(m[1]))
        m = re.search(r'flow open .*MOVIES[\\/](\w+)\.mad', l, re.I)
        if m and m[1].upper() not in cur['movies'][-1:]: cur['movies'].append(m[1].upper())   # the player opens each file 3 times
        m = re.match(r'career race (\d+) track (\d+) word1 (\d+) word2 (\d+) mode (\d+) stages (\d+) opp (.*) \(frame', l)
        if m: cur.update(track=int(m[2]), word1=int(m[3]), word2=int(m[4]), stages=int(m[6]), opponents=[o for o in m[7].split(',') if o])
        m = re.match(r'career result (\d+) status (\d+) cash (-?\d+) gain (-?\d+) spent (-?\d+) opened (\S+) covers (\S+) beaten (\d+)', l)
        if m:
            cur.update(status=int(m[2]), cash=int(m[3]), gain=int(m[4]), spent=int(m[5]), opened=[] if m[6] == '-' else [int(x) for x in m[6].split(',')],
                       covers=[] if m[7] == '-' else [int(x) for x in m[7].split(',')], beaten=int(m[8]))
            out.append(cur)
        m = re.match(r'career (done|stop)(.*)', l)
        if m: out.append({'end': m[1] + m[2].strip()})
    return out


def diff(trace, oracle):
    ev = {e['id']: e for e in oracle['events']}
    order = {s['event']: s for s in oracle['order']}
    d = []
    for t in trace:
        if 'id' not in t: continue
        i, e, o = t['id'], ev.get(t['id']), order.get(t['id'])
        if not e: d.append((i, 'event', 'not in the oracle')); continue
        # a file opens only when the track changes: the next stage on the same track stays loaded (PostRaceMenu
        # 0x64bf64d2 -> 0x497410: race message 9, never leaving the race)
        want = [s['track'] for k, s in enumerate(e['stages']) if not k or s['track'] != e['stages'][k - 1]['track']]
        if t['tracks'] and t['tracks'] != want: d.append((i, 'tracks', f'{t["tracks"]} vs {want}'))
        if 'stages' in t and t['stages'] != len(e['stages']): d.append((i, 'stages', f'{t["stages"]} vs {len(e["stages"])}'))
        if 'opponents' in t and t['opponents'] != [x['name'] for x in e['opponents']]:
            d.append((i, 'opponents', f'{t["opponents"]} vs {[x["name"] for x in e["opponents"]]}'))
        mv = [e['movies']['before']] * bool(e['movies']['before']) + e['movies']['after_win']
        got = [m for m in t['movies'] if m not in ('THX_LOGO', 'LOGO_ENG', 'E3_TITLE', 'NA_BOOT')]
        if [m.upper() for m in mv] != got: d.append((i, 'movies', f'{got} vs {mv}'))
        if o and 'opened' in t and t['opened'] != o['opened']: d.append((i, 'opened', f'{t["opened"]} vs {o["opened"]}'))
        if o and 'open_before' in t and t['open_before'] != o['open_before']: d.append((i, 'open_before', f'{t["open_before"]} vs {o["open_before"]}'))
        # the prize: cash delta plus what was spent meanwhile (event 0: the car bought between its two movies, 0x4c37de)
        if 'gain' in t and t['gain'] + t['spent'] != int(e['cash'][oracle['difficulty']]):
            d.append((i, 'cash', f'{t["gain"]} + spent {t["spent"]} vs {e["cash"][oracle["difficulty"]]}'))
        if t.get('status') != 2: d.append((i, 'status', f'{t.get("status")} vs 2'))
    seen = {t['id'] for t in trace if 'id' in t}
    for s in oracle['order']:
        if s['event'] not in seen: d.append((s['event'], 'missing', 'the trace never raced it'))
    return d


if __name__ == '__main__':
    trace = parse(sys.argv[1])
    oracle = json.load(open(f'{R}/census/career_oracle.json'))
    d = diff(trace, oracle)
    out = sys.argv[2] if len(sys.argv) > 2 else f'{R}/census/career_trace.json'
    json.dump({'run': os.path.relpath(sys.argv[1], R), 'events': trace,
               'diff': [{'event': i, 'field': f, 'what': w, 'explained': EXPLAINED.get((i, f))} for i, f, w in d]}, open(out, 'w'), indent=1)
    un = [x for x in d if (x[0], x[1]) not in EXPLAINED]
    print(f'{sum("id" in t for t in trace)} events traced, {len(d)} differences, {len(un)} unexplained')
    for x in un[:40]: print(' ', *x)
    sys.exit(1 if un else 0)
