#!/bin/bash
# Pod B (step 3, baked AO): Blender LTS headless + one OptiX smoke bake (vertex AO of ~1M triangles), 2 threads (our 2 cores;
# Max Payne owns the rest). Answers: does Cycles+OptiX run on this GPU, and how long is 1M triangles. usage: nohup setup_b.sh
set -euo pipefail
W=/root/ao; mkdir -p $W; cd $W
B=blender-4.2.3-linux-x64
[ -x $B/blender ] || { curl -sSL https://download.blender.org/release/Blender4.2/$B.tar.xz | tar xJ; }
cat > smoke.py <<'PY'
import bpy, time
bpy.ops.wm.read_factory_settings(use_empty=True)
p = bpy.context.preferences.addons['cycles'].preferences; p.compute_device_type = 'OPTIX'; p.get_devices()
for d in p.devices: d.use = d.type == 'OPTIX'
print('devices', [(d.name, d.type, d.use) for d in p.devices])
s = bpy.context.scene; s.render.engine = 'CYCLES'; s.cycles.device = 'GPU'; s.cycles.samples = 64
bpy.ops.mesh.primitive_grid_add(x_subdivisions=700, y_subdivisions=700, size=100)
for i in range(40): bpy.ops.mesh.primitive_uv_sphere_add(segments=64, ring_count=32, location=(i % 8 * 10 - 35, i // 8 * 10 - 20, 2), radius=3)
bpy.ops.object.select_all(action='SELECT'); bpy.ops.object.join(); o = bpy.context.active_object
o.data.color_attributes.new('AO', 'BYTE_COLOR', 'CORNER'); o.data.color_attributes.active_color_name = 'AO'
o.data.materials.append(bpy.data.materials.new('m'))
print('tris', sum(len(p.vertices) - 2 for p in o.data.polygons))
s.render.bake.target = 'VERTEX_COLORS'; t = time.time()
bpy.ops.object.bake(type='AO'); print('bake s', round(time.time() - t, 1))
PY
nvidia-smi --query-gpu=name,driver_version --format=csv,noheader
taskset -c 0,1 $B/blender -b -t 2 --python smoke.py 2>&1 | grep -E 'devices|tris|bake s|Error|error' ; echo AO-SMOKE-DONE
