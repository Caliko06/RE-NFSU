# Per-vertex AO with Blender Cycles (OptiX) for the meshes of geo2mesh.py. Runs inside Blender:
#   blender -b -t 1 --python bake.py -- cars|world OUT.npz SHARD/N SAMPLES DIST IN.npz   (IN = geo2mesh.py output)
# cars: every distinct car (one set of part hashes, in its own space) is one object, OUT.npz[vh] = float16[nvert] per part
# (cars split over N processes by SHARD). world: the whole track is one object, OUT.npz['ao'] per w.pos vertex.
# D3D is left-handed with clockwise front faces; read as right-handed (a mirror) they are counter-clockwise, Blender's front.
import sys, time, numpy as np, bpy
mode, out, shard, samples, dist, ins = *sys.argv[sys.argv.index('--') + 1:][:5], sys.argv[sys.argv.index('--') + 6:]
si, sn = map(int, shard.split('/'))
bpy.ops.wm.read_factory_settings(use_empty=True)
p = bpy.context.preferences.addons['cycles'].preferences; p.compute_device_type = 'OPTIX'; p.get_devices()
for d in p.devices: d.use = d.type == 'OPTIX'
s = bpy.context.scene; s.render.engine = 'CYCLES'; s.cycles.device = 'GPU'; s.cycles.samples = int(samples)
s.world = bpy.data.worlds.new('w'); s.world.light_settings.distance = float(dist); s.render.bake.target = 'VERTEX_COLORS'
mat = bpy.data.materials.new('m')

def bake(name, P, T):
    """P float32[n,3], T int[m,3] (D3D order: counter-clockwise when read right-handed, checked on the cars by signed
    volume) -> AO float32[n]. Vertices no tri uses keep AO 1."""
    m = bpy.data.meshes.new(name); m.vertices.add(len(P)); m.vertices.foreach_set('co', P.ravel())
    m.loops.add(T.size); m.loops.foreach_set('vertex_index', T.ravel().astype(np.int32))
    m.polygons.add(len(T)); m.polygons.foreach_set('loop_start', np.arange(0, T.size, 3, dtype=np.int32))
    m.update(); m.shade_smooth()
    m.color_attributes.new('AO', 'FLOAT_COLOR', 'POINT'); m.color_attributes.active_color_name = 'AO'; m.materials.append(mat)
    o = bpy.data.objects.new(name, m); s.collection.objects.link(o)
    for x in s.objects: x.select_set(x is o)
    bpy.context.view_layer.objects.active = o
    bpy.ops.object.bake(type='AO')
    ao = np.empty(len(P) * 4, np.float32); m.color_attributes['AO'].data.foreach_get('color', ao)
    bpy.data.objects.remove(o); bpy.data.meshes.remove(m)
    ao = ao[0::4]; used = np.zeros(len(P), bool); used[T.ravel()] = True; ao[~used] = 1
    return ao

def car(name, parts):
    """parts = [(vh, pos[n,3], tri[m,3])] -> {vh: ao[n]}. Draws that index the same vb (one vb, several index ranges) share
    its vertices: one vertex block per distinct vb, the union of their tris (not coplanar copies that occlude each other)."""
    vbs, which = {}, []
    for q in parts:
        b = vbs.setdefault(q[1].astype(np.float32).tobytes(), (len(vbs), q[1].astype(np.float32), [])); b[2].append(q[2]); which.append(b[0])
    blocks = sorted(vbs.values(), key=lambda b: b[0])
    off = np.cumsum([0] + [len(b[1]) for b in blocks])
    ao = bake(name, np.concatenate([b[1] for b in blocks]),
              np.unique(np.concatenate([np.concatenate(b[2]).astype(np.int64) + off[b[0]] for b in blocks]), axis=0))
    return {q[0]: ao[off[w]:off[w + 1]].astype(np.float16) for q, w in zip(parts, which)}

res, t0 = {}, time.time()
if mode == 'cars':
    z = np.load(ins[0]); keys = [k[:-3] for k in z.files if k[0] == 'c' and k.endswith('.vh')]
    keys = sorted(keys, key=lambda c: int(c[1:]))[si::sn]
    for k, key in enumerate(keys):
        parts = [(v, z[f'{key}.{j}.p'], z[f'{key}.{j}.t']) for j, v in enumerate(z[f'{key}.vh'])]; t = time.time()
        res.update(car(f'car{k}', parts))
        print(f'car {k + 1}/{len(keys)} parts {len(parts)} tris {sum(len(q[2]) for q in parts)} {time.time() - t:.1f} s', flush=True)
elif mode == 'world':   # the whole track is one mesh; OUT.npz['ao'] is aligned with IN.npz['w.pos']
    z = np.load(ins[0]); res['ao'] = bake('world', z['w.pos'], z['w.tri'].astype(np.int64)).astype(np.float16)
np.savez_compressed(out, **res); print(f'{out}: {len(res)} entries, {time.time() - t0:.0f} s, DONE', flush=True)
