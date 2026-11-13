# JSON: nodes[id] = [x,y,z] in the NFSU1 WORLD frame; sections = [{id,nodes:[node ids]}] are polylines.
# JSON: edges = [[a,b],...] are unique undirected node-id pairs, consecutive section nodes plus native links.
# JSON: bounds = [minX,minY,maxX,maxY]; source records the TRACKB file, MD5, chunks and native link count.
"""Export the served WORLD road net for the GPS map and route planner.

Uses ug2_traffic.parse and the existing Speed.exe 0x58d190 JDLZ reader.
Formats verified in tableros/gps-recon.md, section 3: 0x34121 sections
(header 0x27c, count s16 +0x10, node 0x88, xyz float +0/+4/+8),
0x34122 links (32 bytes: dst/src node u16 +4/+6, dst/src section u8 +9/+10).
Lane direction is deliberately ignored for WORLD free roam.
Run: .venv/bin/python tools/gps_roads.py [--input TRACKB.lzc] [--output roads.json]
"""
import argparse
import hashlib
import json
import math
from pathlib import Path
import struct

import ug2_traffic as traffic
from q_owcoll2_lzc import exe_decode


ROOT = Path(__file__).resolve().parent.parent


def export(path):
    packed = path.read_bytes()
    decoded = exe_decode(packed)
    _, native_sections, links = traffic.parse(decoded)
    nodes, sections, ids, edges = [], [], {}, set()
    for sid, start, count in native_sections:
        assert count > 0 and sid not in ids
        ids[sid] = list(range(len(nodes), len(nodes) + count))
        for index in range(count):
            xyz = struct.unpack_from('<3f', decoded, start + 0x27c + index * 0x88)
            assert all(math.isfinite(value) for value in xyz)
            nodes.append(list(xyz))
        sections.append(dict(id=sid, nodes=ids[sid]))
        edges.update(zip(ids[sid], ids[sid][1:]))
    for link in links:
        dst_node, src_node = struct.unpack_from('<HH', link, 4)
        dst_section, src_section = link[9], link[10]
        a, b = ids[src_section][src_node], ids[dst_section][dst_node]
        if a != b:
            edges.add(tuple(sorted((a, b))))

    # Verify all exported nodes are reachable through the exact undirected net.
    adjacent = [[] for _ in nodes]
    for a, b in edges:
        adjacent[a].append(b)
        adjacent[b].append(a)
    seen, todo = {0}, [0]
    while todo:
        for other in adjacent[todo.pop()]:
            if other not in seen:
                seen.add(other)
                todo.append(other)
    assert len(seen) == len(nodes), f'Road net disconnected: {len(seen)}/{len(nodes)}'
    bounds = [min(p[0] for p in nodes), min(p[1] for p in nodes),
              max(p[0] for p in nodes), max(p[1] for p in nodes)]
    return dict(nodes=nodes, sections=sections, edges=sorted(edges), bounds=bounds,
                source=dict(file=path.name, md5=hashlib.md5(packed).hexdigest(),
                            chunks=['0x34121', '0x34122'], links=len(links)))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input', type=Path, default=ROOT / 'build/openworld/TRACKB1010.lzc')
    parser.add_argument('--output', type=Path, default=ROOT / 'web/gps/roads.json')
    args = parser.parse_args()
    roads = export(args.input)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(roads, separators=(',', ':'), allow_nan=False) + '\n')
    print(json.dumps(dict(output=str(args.output), sections=len(roads['sections']),
                          nodes=len(roads['nodes']), edges=len(roads['edges']),
                          components=1, bounds=roads['bounds'], source=roads['source'])))
