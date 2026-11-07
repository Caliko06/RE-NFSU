#!/usr/bin/env python3
# Marble (World Labs) client for the launcher world. Key lives in ~/.config/worldlabs/key (chmod 600), sent only as WLT-Api-Key.
# Usage: marble.py gen <image> <out_dir> [text]          one image
#        marble.py pano <equirect> <out_dir> [text]       a 360 panorama (is_pano)
#        marble.py multi <out_dir> <az>:<image> ...       several views with their azimuth in degrees
# Each uploads, generates with marble-1.1, polls, downloads SPZ + collider + pano and prints the credits spent.
import json, os, sys, time, urllib.request

API = 'https://api.worldlabs.ai/marble/v1'
KEY = open(os.path.expanduser('~/.config/worldlabs/key')).read().strip()


def call(method, path, body=None):
    req = urllib.request.Request(API + path, method=method, data=json.dumps(body).encode() if body is not None else None,
                                 headers={'WLT-Api-Key': KEY, 'Content-Type': 'application/json'})
    with urllib.request.urlopen(req, timeout=120) as r: return json.load(r)


def fetch(url, dst):
    with urllib.request.urlopen(url, timeout=600) as r, open(dst, 'wb') as f:
        while chunk := r.read(1 << 20): f.write(chunk)
    print('saved', dst, os.path.getsize(dst), flush=True)


def upload(image):
    ext = image.rsplit('.', 1)[1].lower()
    prep = call('POST', '/media-assets:prepare_upload', {'file_name': os.path.basename(image), 'extension': ext, 'kind': 'image'})
    up = prep['upload_info']
    req = urllib.request.Request(up['upload_url'], method='PUT', data=open(image, 'rb').read(),
                                 headers={'Content-Type': 'image/' + ('jpeg' if ext == 'jpg' else ext), **(up.get('required_headers') or {})})
    urllib.request.urlopen(req, timeout=300).read()
    return {'source': 'media_asset', 'media_asset_id': prep['media_asset']['media_asset_id']}


def gen(image, out, text=''): run(out, {'type': 'image', 'image_prompt': upload(image)}, text)
def pano(image, out, text=''): run(out, {'type': 'image', 'image_prompt': upload(image), 'is_pano': True}, text)
def multi(out, *views):
    run(out, {'type': 'multi-image', 'multi_image_prompt': [{'azimuth': float(v.split(':', 1)[0]), 'content': upload(v.split(':', 1)[1])} for v in views]})


def run(out, prompt, text=''):
    os.makedirs(out, exist_ok=True)
    if text: prompt['text_prompt'] = text
    op = call('POST', '/worlds:generate', {'display_name': os.path.basename(out), 'model': 'marble-1.1', 'world_prompt': prompt})
    json.dump(op, open(os.path.join(out, 'op_start.json'), 'w'), indent=1)
    oid = op.get('operation_id') or op.get('name') or op.get('id')
    print('operation', oid, flush=True)
    for _ in range(120):  # 30 min cap
        time.sleep(15)
        st = call('GET', f'/operations/{oid}')
        if st.get('done') or st.get('error'): break
    json.dump(st, open(os.path.join(out, 'op_done.json'), 'w'), indent=1)
    if st.get('error') or not st.get('done'): sys.exit(f"failed: {json.dumps(st)[:800]}")
    world = st.get('response') or st
    a = world.get('assets', {})
    for k, url in (a.get('splats', {}).get('spz_urls') or {}).items():
        if k in ('500k', 'full_res', 'full'): fetch(url, os.path.join(out, f'world_{k}.spz'))
    if url := a.get('mesh', {}).get('collider_mesh_url'): fetch(url, os.path.join(out, 'collider.glb'))
    if url := (a.get('imagery') or {}).get('pano_url'): fetch(url, os.path.join(out, 'pano' + os.path.splitext(url.split('?')[0])[1]))
    json.dump(a.get('splats', {}).get('semantics_metadata', {}), open(os.path.join(out, 'meta.json'), 'w'))
    print('credits', (st.get('cost') or {}).get('total_credits'), flush=True)


if __name__ == '__main__': {'gen': gen, 'pano': pano, 'multi': multi}[sys.argv[1]](*sys.argv[2:])
