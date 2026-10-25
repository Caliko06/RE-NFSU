# Per-vertex AO with Blender Cycles (OptiX) for the meshes of geo2mesh.py. Runs inside Blender:
#   blender -b -t 1 --python bake.py -- cars|world OUT.npz SHARD/N SAMPLES DIST IN.npz   (IN = geo2mesh.py output)
# cars: every distinct car (one set of part hashes, in its own space) is one object, OUT.npz[vh] = float16[nvert] per part
# (cars split over N processes by SHARD). world: the whole track is one object, OUT.npz['ao'] per w.pos vertex.
# gi|probes: per-vertex GI passes and HDR reflection probes of the world (see those branches below; inputs from scene.py).
# D3D is left-handed with clockwise front faces; read as right-handed (a mirror) they are counter-clockwise, Blender's front.
import os, sys, time, numpy as np, bpy
mode, out, shard, samples, dist, ins = *sys.argv[sys.argv.index('--') + 1:][:5], sys.argv[sys.argv.index('--') + 6:]
si, sn = map(int, shard.split('/'))
bpy.ops.wm.read_factory_settings(use_empty=True)
p = bpy.context.preferences.addons['cycles'].preferences; p.compute_device_type = 'OPTIX'; p.get_devices()
for d in p.devices: d.use = d.type == 'OPTIX'
s = bpy.context.scene; s.render.engine = 'CYCLES'; s.cycles.device = 'GPU'; s.cycles.samples = int(samples)
s.world = bpy.data.worlds.new('w'); s.world.light_settings.distance = float(dist) if mode in ('cars', 'world') else 1.0; s.render.bake.target = 'VERTEX_COLORS'
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

def world_mesh(z, alb):
    """The track as one object with the game's light: corner attributes alb (mean linear colour of the draw's texture,
    build/gi/albedo.tsv) and col (the vertex colour = the game's baked light, sRGB -> linear). Material: diffuse alb plus
    emission alb * col * EMIT (EMIT = 0 turns the game's light off), so its bounce is the first bounce of the game's own light."""
    P, T, C, K = z['w.pos'], z['w.tri'].astype(np.int64), z['w.col'], z['w.ttk']
    m = bpy.data.meshes.new('world'); m.vertices.add(len(P)); m.vertices.foreach_set('co', P.ravel())
    m.loops.add(T.size); m.loops.foreach_set('vertex_index', T.ravel().astype(np.int32))
    m.polygons.add(len(T)); m.polygons.foreach_set('loop_start', np.arange(0, T.size, 3, dtype=np.int32))
    m.update(); m.shade_smooth()
    known = np.array([k in alb for k in K]); mean = np.mean(list(alb.values()), 0)
    A = np.array([alb.get(k, mean) for k in K], np.float32)            # unknown texture: the mean albedo (counted in the log)
    lin = (C[:, :3] / 255.0) ** 2.2
    for name, v in (('alb', np.repeat(A, 3, 0)), ('col', lin[T.ravel()])):
        a = m.color_attributes.new(name, 'FLOAT_COLOR', 'CORNER')
        a.data.foreach_set('color', np.hstack([v, np.ones((len(v), 1))]).astype(np.float32).ravel())
    g = m.color_attributes.new('GI', 'FLOAT_COLOR', 'POINT'); m.color_attributes.active_color_name = 'GI'
    mt = bpy.data.materials.new('gi'); mt.use_nodes = True; n = mt.node_tree.nodes; L = mt.node_tree.links; n.clear()
    ab, co, mul, dif, emi, add, out = (n.new(t) for t in ('ShaderNodeAttribute', 'ShaderNodeAttribute', 'ShaderNodeVectorMath',
        'ShaderNodeBsdfDiffuse', 'ShaderNodeEmission', 'ShaderNodeAddShader', 'ShaderNodeOutputMaterial'))
    ab.attribute_name, co.attribute_name, mul.operation, emi.name = 'alb', 'col', 'MULTIPLY', 'EMIT'
    L.new(ab.outputs['Color'], dif.inputs['Color']); L.new(ab.outputs['Color'], mul.inputs[0]); L.new(co.outputs['Color'], mul.inputs[1])
    L.new(mul.outputs[0], emi.inputs['Color']); L.new(dif.outputs[0], add.inputs[0]); L.new(emi.outputs[0], add.inputs[1])
    L.new(add.outputs[0], out.inputs['Surface']); m.materials.append(mt)
    o = bpy.data.objects.new('world', m); s.collection.objects.link(o)
    print(f'world {len(P)} verts {len(T)} tris, albedo known for {known.mean() * 100:.1f} % of tris', flush=True)
    return o, emi

def lights(sc):
    """World background = the track-wide fog colour (scene.py); sun = a SUN light toward sun_pos from the mesh centre, colour
    255,200,100, irradiance 1 (the game gives no strength: the runtime weights each GI pass)."""
    s.world.use_nodes = True; bg = s.world.node_tree.nodes['Background']
    bg.inputs['Color'].default_value = [*((np.array(sc['fog']['rgb']) / 255.0) ** 2.2), 1]
    d = np.array(sc['sun_pos']) - np.array(sc['centre']); d /= np.linalg.norm(d)
    l = bpy.data.lights.new('sun', 'SUN'); l.color = (np.array(sc['sun_rgb']) / 255.0) ** 2.2
    o = bpy.data.objects.new('sun', l); s.collection.objects.link(o)
    import mathutils; o.rotation_mode = 'QUATERNION'; o.rotation_quaternion = mathutils.Vector(d).to_track_quat('Z', 'Y')
    return bg, l

def albedo(path):
    return {int(l.split()[0], 16): np.array(l.split()[1:4], np.float32) for l in open(path)}

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
elif mode == 'gi':   # bake.py -- gi OUT.npz 0/1 SAMPLES PASS MESH.npz ALBEDO.tsv SCENE.json RUN
    # PASS b: the game's own light, bounced (emission on, sky and sun off); s: sky only; u: sun only. Irradiance per w.pos
    # vertex (DIFFUSE direct + indirect, no colour), linear RGB, float16.
    import json
    z = np.load(ins[0]); sc = json.load(open(ins[2]))[ins[3]]; ps = dist
    o, emi = world_mesh(z, albedo(ins[1])); bg, sun = lights(sc)
    s.cycles.max_bounces, s.cycles.diffuse_bounces = 4, 3
    emi.inputs['Strength'].default_value = 1.0 if ps == 'b' else 0.0
    bg.inputs['Strength'].default_value = 1.0 if ps == 's' else 0.0
    sun.energy = 1.0 if ps == 'u' else 0.0
    for x in s.objects: x.select_set(x is o)
    bpy.context.view_layer.objects.active = o
    bpy.ops.object.bake(type='DIFFUSE', pass_filter={'DIRECT', 'INDIRECT'})
    g = np.empty(len(z['w.pos']) * 4, np.float32); o.data.color_attributes['GI'].data.foreach_get('color', g)
    res[ps] = g.reshape(-1, 4)[:, :3].astype(np.float16)
elif mode == 'probes':   # bake.py -- probes OUT.npz 0/1 SAMPLES WIDTH MESH.npz ALBEDO.tsv SCENE.json RUN
    # HDR reflection probes of the lit track (the game's light as emission + fog sky + sun) every 10 m along the route
    # (scene.py), 1.0 above the road (a downward ray from 5 above the last probe). One equirectangular render per probe
    # (one render keeps the GPU busy; six small cube faces were CPU bound). Cycles panorama: camera-space direction
    # (sin t cos p, sin t sin p, cos t), p = pi (1 - 2u), t = pi v from the top row; the camera is turned pi about X, so
    # world = (x, -y, z) of that: the centre column looks along world +X, the top row is world +Z, u < 0.5 is world -Y.
    # OUT: pos[n,3], pano[n,H,W,3] f16 (rows top to bottom), H = WIDTH / 2.
    import json, math
    z = np.load(ins[0]); sc = json.load(open(ins[2]))[ins[3]]; W = int(dist)
    o, emi = world_mesh(z, albedo(ins[1])); bg, sun = lights(sc)
    emi.inputs['Strength'].default_value = bg.inputs['Strength'].default_value = sun.energy = 1.0
    cam = bpy.data.objects.new('cam', bpy.data.cameras.new('cam')); s.collection.objects.link(cam); s.camera = cam
    cam.data.type = 'PANO'; cam.data.panorama_type = 'EQUIRECTANGULAR'; cam.data.clip_start = 0.05; cam.data.clip_end = 20000
    cam.rotation_euler = (math.pi, 0, 0)
    s.render.resolution_x, s.render.resolution_y, s.render.resolution_percentage = W, W // 2, 100
    s.render.use_persistent_data = True; s.cycles.use_denoising = True; s.cycles.denoiser = 'OPTIX'
    s.render.image_settings.file_format = 'OPEN_EXR'; s.render.image_settings.color_depth = '16'
    s.view_settings.view_transform = 'Standard'
    R = np.array([r[:2] for r in sc['route']]); L = np.r_[0, np.cumsum(np.linalg.norm(np.diff(R, axis=0), axis=1))]
    pts = [(np.interp(a, L, R[:, 0]), np.interp(a, L, R[:, 1])) for a in np.arange(0, L[-1], 10.0)]
    dg = bpy.context.evaluated_depsgraph_get(); top = float(z['w.pos'][:, 2].max()) + 10; zl = None; pos = []
    for x, y in pts:
        hit = s.ray_cast(dg, (x, y, zl + 5 if zl is not None else top), (0, 0, -1))
        if not hit[0] and zl is not None: hit = s.ray_cast(dg, (x, y, top), (0, 0, -1))
        if hit[0]: zl = hit[1][2]; pos.append((x, y, zl + 1.0))
    pano = np.zeros((len(pos), W // 2, W, 3), np.float16); f = f'/tmp/probe.{os.getpid()}.exr'
    for i, p in enumerate(pos):
        cam.location = p; s.render.filepath = f; bpy.ops.render.render(write_still=True)
        im = bpy.data.images.load(f); px = np.empty(W * W // 2 * 4, np.float32); im.pixels.foreach_get(px); bpy.data.images.remove(im)
        pano[i] = px.reshape(W // 2, W, 4)[::-1, :, :3]
        if i % 20 == 0: print(f'probe {i + 1}/{len(pos)} {time.time() - t0:.0f} s', flush=True)
    res['pos'] = np.array(pos, np.float32); res['pano'] = pano
np.savez_compressed(out, **res); print(f'{out}: {len(res)} entries, {time.time() - t0:.0f} s, DONE', flush=True)
