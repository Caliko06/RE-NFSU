# Per-vertex AO of car assemblies in Blender (Cycles, Metal on the Mac). Copy of tools/ao/bake.py's bake(), without OptiX.
#   Blender -b --python bake_car.py -- IN.npz OUT.npz SAMPLES DIST
# IN.npz: j<k>.names (assembly k's solid names) and p.<name>, t.<name> (positions f32[n,3], triangles u32[m,3], D3D order).
# OUT.npz: <k>|<name> -> float16[n] (vertices no triangle uses keep 1).
import sys, time, numpy as np, bpy
ins, out, samples, dist = sys.argv[sys.argv.index('--') + 1:][:4]
bpy.ops.wm.read_factory_settings(use_empty=True)
cy = bpy.context.preferences.addons['cycles'].preferences; cy.compute_device_type = 'METAL'; cy.get_devices()
for d in cy.devices: d.use = d.type == 'METAL'
s = bpy.context.scene; s.render.engine = 'CYCLES'; s.cycles.device = 'GPU'; s.cycles.samples = int(samples)
s.world = bpy.data.worlds.new('w'); s.world.light_settings.distance = float(dist); s.render.bake.target = 'VERTEX_COLORS'
mat = bpy.data.materials.new('m')
def bake(name, P, T):
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
import os
FLIP = os.environ.get('FLIP') == '1'
z = np.load(ins); res = {}
ks = sorted({f.split('.')[0] for f in z.files if f.endswith('.names')}, key=lambda c: int(c[1:]))
for k in ks:
    t0 = time.time(); names = list(z[k + '.names'])
    P = [z['p.' + n] for n in names]; T = [z['t.' + n].astype(np.int64)[:, ::-1] if FLIP else z['t.' + n].astype(np.int64) for n in names]
    off = np.cumsum([0] + [len(p) for p in P])
    ao = bake(k, np.concatenate(P).astype(np.float32), np.concatenate([t + off[i] for i, t in enumerate(T)]))
    for i, n in enumerate(names): res[f'{k[1:]}|{n}'] = ao[off[i]:off[i + 1]].astype(np.float16)
    print(f'{k} parts {len(names)} verts {off[-1]} tris {sum(len(t) for t in T)} {time.time() - t0:.1f} s', flush=True)
np.savez_compressed(out, **res)
