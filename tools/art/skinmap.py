"""Where the car body skin texture (<CAR>_SKIN1) lands on each racer car -> build/art/skinmap.json + debug PNGs.

  .venv/bin/python tools/art/skinmap.py [CAR ...]     (default: the 20 racer cars)

Source: game/Cars/<CAR>/GEOMETRY.BIN, solids <CAR>_KIT00_*_A (LOD A stock parts); reader = tools/art/carmesh.py.
Mesh format (docs/re/car_assets.md, checked on bytes): vertex 36 B = float3 pos, float3 normal, u32 colour, float2 uv;
index buffer = u16 triangle list; group record 0x3c B (+0xc index count, +0x1c texture index, +0x20 material index).
Car space (measured, not assumed, see "axes" in the JSON): +x = front (HEADLIGHT x > BRAKELIGHT x), +z = up,
+y = LEFT (the *_LEFT_SIDE_MIRROR solid sits at +y). Left/right below always mean the car's own left/right.
UV: u right, v down in the texture image (D3D, v = 0 is the top row). Pixels are for a 1024 texture (u*1024, v*1024).

Fit per side: u = au*L + bu*H + cu, v = av*L + bv*H + cv with L = metres along the car (front positive), H = metres up.
Fit set = CARSKIN-material triangles of the BODY solid, normal mostly lateral (|n.lat| > 0.7, outward), trimmed at
max(3*median abs residual, 6 px) a few times. Bbox / inlier count are then taken over every SKIN1 CARSKIN side
triangle of every KIT00 A solid that the fit predicts within 12 px.
Text rule: the viewer stands outside the side, car front on the viewer's left (left side) or right (right side).
Viewer right = (-n) x up: left side -> -L, right side -> +L. M maps viewer (X right, Y down) to texture (u, v):
M = [[au*sr, -bu], [av*sr, -bv]] with sr = viewer-right sign along L. "pil_op" is the PIL transpose to apply to an
upright text image before pasting it into the texture (None = paste as is).
"""
import json, math, os, sys
import numpy as np
from PIL import Image, ImageDraw, ImageFont

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import carmesh

B = carmesh.B
CARS = "GOLF FOCUS MIATA NEON CIVIC PEUGOT CELICA ECLIPSE RX7 SUPRA S2000 RSX IMPREZA LANCER INTEGRA TIBURON 350Z SENTRA 240SX SKYLINE".split()
OUT = os.path.join(B, "build", "art")
PNG = os.path.join(OUT, "skinmap")
T = 1024.0


def part(name, car):
    """'SKYLINE_KIT00_FRONT_BUMPER_A' -> 'FRONT_BUMPER' (None if not a KIT00 A solid)."""
    p = name[len(car) + 1:]
    if not p.startswith("KIT00_") or not p.endswith("_A"):
        return None
    return p[6:-2]


def load(car):
    """Axes + triangle table of the SKIN1 groups of the KIT00 A solids. Triangles are in car frame (L front, S left, H up)."""
    s1 = carmesh.bh(car + "_SKIN1")
    sol = list(carmesh.solids(car))
    cen = {}
    for s in sol:
        n = s["name"]
        for key in ("HEADLIGHT", "BRAKELIGHT"):
            if n.endswith("KIT00_%s_A" % key):
                cen[key] = s["V"]["p"].mean(0)
    left = [s["V"]["p"].mean(0)[1] for s in sol if "KIT00_LEFT_SIDE_MIR" in s["name"]]   # solid names are cut at 27 characters
    dl = [s["V"]["p"].mean(0)[1] for s in sol if "_DECAL_LEFT_" in s["name"]]
    dr_ = [s["V"]["p"].mean(0)[1] for s in sol if "_DECAL_RIGHT_" in s["name"]]
    fsign = 1.0 if cen["HEADLIGHT"][0] > cen["BRAKELIGHT"][0] else -1.0
    lsign = (1.0 if np.mean(left) > 0 else -1.0) if left else 1.0   # no mirror solid (SKYLINE, SENTRA...): +y, as in every car that has one
    axes = dict(front="+x" if fsign > 0 else "-x", left="+y" if lsign > 0 else "-y", up="+z",
                headlight_x=round(float(cen["HEADLIGHT"][0]), 3), brakelight_x=round(float(cen["BRAKELIGHT"][0]), 3),
                left_mirror_y=round(float(np.mean(left)), 3) if left else None,
                decal_left_y=round(float(np.mean(dl)), 3) if dl else None, decal_right_y=round(float(np.mean(dr_)), 3) if dr_ else None,
                left_source="LEFT_SIDE_MIRROR solid" if left else "assumed +y (no mirror solid in this file)")
    rows = []   # per triangle: solid index, cs, centroid L,S,H ; normal L,S,H ; uv(3x2) ; area
    names = []
    for s in sol:
        pn = part(s["name"], car)
        if pn is None or s1 not in s["tex"]:
            continue
        names.append(pn)
        V = s["V"]
        for gt, gm, first, cnt in s["groups"]:
            if s["tex"][gt] != s1:
                continue
            cs = gm < len(s["mat"]) and s["mat"][gm] == carmesh.CARSKIN
            I = s["idx"][first:first + cnt].reshape(-1, 3)
            P = V["p"][I].astype(np.float64)
            N = V["n"][I].astype(np.float64).mean(1)
            UV = V["uv"][I].astype(np.float64)
            f = np.array([fsign, lsign, 1.0])
            P = P * f
            N = N * f
            for k in range(len(I)):
                rows.append((len(names) - 1, cs, P[k].mean(0), N[k], UV[k], P[k]))
    return axes, names, rows


def fit(L, H, uv):
    A = np.c_[L, H, np.ones(len(L))]
    cu = np.linalg.lstsq(A, uv[:, 0], rcond=None)[0]
    cv = np.linalg.lstsq(A, uv[:, 1], rcond=None)[0]
    return cu, cv


def trimmed(x, y, uv, passes=4):
    """RANSAC start (3-point affines, 400 draws, inlier < 6 px), then least squares on the inliers, refit a few times."""
    n = len(x)
    A = np.c_[x, y, np.ones(n)]
    rng = np.random.default_rng(1)
    best, keep = -1, np.ones(n, bool)
    for _ in range(400 if n > 12 else 0):
        i = rng.choice(n, 3, replace=False)
        try:
            cu = np.linalg.solve(A[i], uv[i, 0]); cv = np.linalg.solve(A[i], uv[i, 1])
        except np.linalg.LinAlgError:
            continue
        r = np.hypot(A @ cu - uv[:, 0], A @ cv - uv[:, 1])
        k = r < 6
        if k.sum() > best:
            best, keep = int(k.sum()), k
    for _ in range(passes):
        if keep.sum() < 4:
            break
        cu, cv = fit(x[keep], y[keep], uv[keep])
        r = np.hypot(A @ cu - uv[:, 0], A @ cv - uv[:, 1])
        keep = r < max(3 * np.median(r[keep]), 6.0)
    cu, cv = fit(x[keep], y[keep], uv[keep])
    r = np.hypot(A @ cu - uv[:, 0], A @ cv - uv[:, 1])
    return cu, cv, r, keep


def pil_op(M):
    """Which PIL transpose turns an upright image into texture orientation, for sign matrix M (viewer->texture)."""
    ops = [(None, None), ("FLIP_LEFT_RIGHT", Image.Transpose.FLIP_LEFT_RIGHT), ("FLIP_TOP_BOTTOM", Image.Transpose.FLIP_TOP_BOTTOM),
           ("ROTATE_180", Image.Transpose.ROTATE_180), ("ROTATE_90", Image.Transpose.ROTATE_90),
           ("ROTATE_270", Image.Transpose.ROTATE_270), ("TRANSPOSE", Image.Transpose.TRANSPOSE),
           ("TRANSVERSE", Image.Transpose.TRANSVERSE)]
    want = np.sign(np.round(M)).astype(int)
    for nm, op in ops:
        # probe: 5x5 image, marker at centre+X, marker at centre+Y; find where each goes
        cols = []
        for dx, dy in ((1, 0), (0, 1)):
            im = Image.new("L", (5, 5), 0)
            im.putpixel((2 + dx, 2 + dy), 255)
            if op is not None:
                im = im.transpose(op)
            a = np.array(im)
            yy, xx = np.argwhere(a == 255)[0]
            cols.append((xx - 2, yy - 2))          # texture (u, v) offset of a unit step right / down
        if (np.array(cols).T == want).all():
            return nm
    return "?"


def side_info(ctx, side):
    """side = +1 left (S>0) or -1 right. Returns dict (or None)."""
    rows, names = ctx
    sel = []
    for ri, r in enumerate(rows):
        pn = names[r[0]]
        if not r[1] or side * r[2][1] < 0.15 or side * r[3][1] < 0.7:
            continue
        uv = r[4]
        if uv.min() < -0.002 or uv.max() > 1.002:
            continue
        sel.append(ri)
    body = [ri for ri in sel if names[rows[ri][0]] == "BODY"]
    if len(body) < 20:
        return None
    def arr(ids):
        return (np.array([rows[i][2][0] for i in ids]), np.array([rows[i][2][2] for i in ids]),
                np.array([rows[i][4].mean(0) * T for i in ids]))
    x, y, uv = arr(body)
    cu, cv, r, keep = trimmed(x, y, uv)
    # apply to every side triangle (all solids) with the vertex-level uv
    x2, y2, uv2 = arr(sel)
    A = np.c_[x2, y2, np.ones(len(x2))]
    r2 = np.hypot(A @ cu - uv2[:, 0], A @ cv - uv2[:, 1])
    inl = r2 < 12
    ids = [sel[i] for i in range(len(sel)) if inl[i]]
    pts = np.concatenate([rows[i][4] for i in ids]) * T
    bbox = [round(float(pts[:, 0].min()), 1), round(float(pts[:, 1].min()), 1), round(float(pts[:, 0].max()), 1), round(float(pts[:, 1].max()), 1)]
    # residual over the fit inliers (the BODY panels)
    res_rms = float(np.sqrt((r[keep] ** 2).mean()))
    sr = -1.0 if side > 0 else 1.0          # viewer right along L
    M = np.array([[cu[0] * sr, -cu[1]], [cv[0] * sr, -cv[1]]])
    # normalise by the larger entry per column? classify by dominant structure
    diag = abs(M[0, 0]) * abs(M[1, 1]) >= abs(M[0, 1]) * abs(M[1, 0])
    Ms = M.copy()
    if diag:
        Ms[0, 1] = Ms[1, 0] = 0
    else:
        Ms[0, 0] = Ms[1, 1] = 0
    clean = abs(Ms - M).max() < 0.15 * np.abs(M).max()    # cross terms under 15 % of the main terms
    op = pil_op(Ms)
    desc = {"None": "normal", "FLIP_LEFT_RIGHT": "flipped (mirror left-right)", "FLIP_TOP_BOTTOM": "flipped (mirror top-bottom)",
            "ROTATE_180": "rotated 180"}.get(str(op), "rotated 90 / transposed (%s)" % op)
    L = np.array([rows[i][2][0] for i in ids]); H = np.array([rows[i][2][2] for i in ids])
    return dict(
        n_fit_tris=int(keep.sum()), n_body_side_tris=len(body), n_inlier_tris_all_solids=len(ids), n_side_tris_all_solids=len(sel),
        inlier_solids=sorted({names[rows[i][0]] for i in ids}),
        uv_bbox_px=bbox, uv_bbox_size_px=[round(bbox[2] - bbox[0], 1), round(bbox[3] - bbox[1], 1)],
        affine=dict(u=[round(float(c), 3) for c in cu], v=[round(float(c), 3) for c in cv],
                    form="u=c[0]*L+c[1]*H+c[2], v=...; L m along car (front +), H m up; pixels of 1024"),
        residual_rms_px=round(res_rms, 2), residual_max_px=round(float(r[keep].max()), 2),
        du_dL=round(float(cu[0]), 2), du_dH=round(float(cu[1]), 2), dv_dL=round(float(cv[0]), 2), dv_dH=round(float(cv[1]), 2),
        L_range_m=[round(float(L.min()), 3), round(float(L.max()), 3)], H_range_m=[round(float(H.min()), 3), round(float(H.max()), 3)],
        clean_affine=bool(clean and res_rms <= 8),
        front_goes="u" + ("+" if cu[0] > 0 else "-") if diag else "v" + ("+" if cv[0] > 0 else "-"),
        text=dict(viewer_right_along_L=int(sr), M_viewer_to_texture=[[round(float(v), 1) for v in row] for row in M],
                  transform=desc, pil_op=None if op in (None, "None") else op,
                  sign_du_dL=int(np.sign(cu[0])), sign_dv_dH=int(np.sign(cv[1]))),
        px_per_m=[round(abs(float(cu[0])) if diag else abs(float(cv[0])), 1), round(abs(float(cv[1])) if diag else abs(float(cu[1])), 1)],
        door_centre_uv=None,
    ), (cu, cv, ids)


def top_info(ctx, name, axes):
    rows, names = ctx
    sel = [ri for ri, r in enumerate(rows) if r[1] and names[r[0]] == name and r[3][2] > 0.7
           and r[4].min() >= -0.002 and r[4].max() <= 1.002]
    return sel


def top_fit(rows, ids, ref=None):
    """Affine (L, S) -> (u, v) of top-facing triangles. If the L range is under 0.4 m the fit is ill-conditioned: reuse the
    linear terms of `ref` (another top region of the same car) and fit only the offsets."""
    if len(ids) < 8:
        return None
    L = np.array([rows[i][2][0] for i in ids]); S = np.array([rows[i][2][1] for i in ids])
    uv = np.array([rows[i][4].mean(0) * T for i in ids])
    cu, cv, r, keep = trimmed(L, S, uv)
    note = None
    if np.ptp(L[keep]) < 0.4 and ref is not None:
        cu = np.array([ref["affine"]["u"][0], ref["affine"]["u"][1], 0.0]); cv = np.array([ref["affine"]["v"][0], ref["affine"]["v"][1], 0.0])
        cu[2] = np.median(uv[:, 0] - cu[0] * L - cu[1] * S); cv[2] = np.median(uv[:, 1] - cv[0] * L - cv[1] * S)
        A = np.c_[L, S, np.ones(len(L))]
        r = np.hypot(A @ cu - uv[:, 0], A @ cv - uv[:, 1])
        keep = r < max(3 * np.median(r), 6.0)
        note = "L range under 0.4 m: linear terms copied from the roof fit, offsets fitted"
    pts = np.concatenate([rows[ids[i]][4] for i in range(len(ids)) if keep[i]]) * T
    bbox = [round(float(pts[:, 0].min()), 1), round(float(pts[:, 1].min()), 1), round(float(pts[:, 0].max()), 1), round(float(pts[:, 1].max()), 1)]
    # text with the car front at the top of the screen, viewed from above: X right = -S, Y down = -L
    M = np.array([[-cu[1], -cu[0]], [-cv[1], -cv[0]]])
    diag = abs(M[0, 0]) * abs(M[1, 1]) >= abs(M[0, 1]) * abs(M[1, 0])
    Ms = M.copy()
    if diag:
        Ms[0, 1] = Ms[1, 0] = 0
    else:
        Ms[0, 0] = Ms[1, 1] = 0
    op = pil_op(Ms)
    out = dict(n_tris=int(keep.sum()), n_candidates=len(ids), uv_bbox_px=bbox,
               affine=dict(u=[round(float(c), 3) for c in cu], v=[round(float(c), 3) for c in cv],
                           form="u=c[0]*L+c[1]*S+c[2], v=...; L m along car (front +), S m to the left; pixels of 1024"),
               residual_rms_px=round(float(np.sqrt((r[keep] ** 2).mean())), 2), residual_max_px=round(float(r[keep].max()), 2),
               L_range_m=[round(float(L[keep].min()), 3), round(float(L[keep].max()), 3)],
               du_dL=round(float(cu[0]), 1), du_dS=round(float(cu[1]), 1), dv_dL=round(float(cv[0]), 1), dv_dS=round(float(cv[1]), 1),
               text_front_up=dict(M_viewer_to_texture=[[round(float(v), 1) for v in row] for row in M],
                                  pil_op=None if op in (None, "None") else op,
                                  note="viewer above the car, car front at the top of the screen (X right = car right)"))
    rel = out["residual_rms_px"] <= 8
    out["reliable"] = bool(rel)
    if not rel:
        note = (note + "; " if note else "") + "residual over 8 px: the region is its own island, affine NOT usable (bbox is of the kept triangles)"
    if note:
        out["note"] = note
    return out


def analyse(car):
    axes, names, rows = load(car)
    ctx = (rows, names)
    out = dict(axes=axes, skin1_solids=sorted(set(names)))
    fits = {}
    for nm, side in (("left", 1), ("right", -1)):
        r = side_info(ctx, side)
        if r is None:
            out[nm] = None
            continue
        out[nm], fits[nm] = r
    # door centre: roof centre along L, mid height of the body side range
    roof = [r[5] for r in rows if names[r[0]] == "ROOF"]
    if roof and fits:
        P = np.concatenate(roof)
        Lc = float((P[:, 0].min() + P[:, 0].max()) / 2)
        for nm in fits:
            cu, cv, ids = fits[nm]
            Hc = float(np.mean(out[nm]["H_range_m"]))
            u = cu[0] * Lc + cu[1] * Hc + cu[2]; v = cv[0] * Lc + cv[1] * Hc + cv[2]
            out[nm]["door_centre_uv"] = [round(float(u), 1), round(float(v), 1)]
            out[nm]["door_centre_car"] = dict(L=round(Lc, 3), H=round(Hc, 3), note="inference: ROOF solid L centre, mid of side height range")
    # top regions
    tops = {}
    for key, nm in (("roof", "ROOF"), ("hood", "HOOD"), ("trunk", "TRUNK")):
        ids = top_info(ctx, nm, axes)
        tops[key] = top_fit(rows, ids, tops.get("roof")) if ids else None
    if tops["trunk"] is None:
        # no top-facing TRUNK triangles: rear deck = BODY top-facing triangles behind the roof
        rp = [r[5] for r in rows if names[r[0]] == "ROOF"]
        if rp:
            Lmin = float(np.concatenate(rp)[:, 0].min())
            ids = [ri for ri in top_info(ctx, "BODY", axes) if rows[ri][2][0] < Lmin]
            tops["trunk"] = top_fit(rows, ids, tops.get("roof"))
            if tops["trunk"]:
                tops["trunk"]["note"] = "no top-facing TRUNK triangles: BODY top-facing triangles behind the roof"
    out["top"] = tops
    return out, ctx, fits


# ---------------------------------------------------------------- debug images
def debug_png(car, info, ctx, fits):
    rows, names = ctx
    im = Image.new("RGB", (1024, 1024), (16, 16, 16))
    ov = Image.new("RGBA", (1024, 1024), (0, 0, 0, 0))
    do = ImageDraw.Draw(ov)
    for nm, col in (("left", (255, 70, 70, 70)), ("right", (70, 130, 255, 70))):
        if info.get(nm):
            b = info[nm]["uv_bbox_px"]
            do.rectangle(b, fill=col)
    for key, col in (("hood", (255, 220, 60, 50)), ("roof", (80, 220, 120, 50)), ("trunk", (220, 120, 255, 50))):
        t = info["top"].get(key)
        if t and t.get("reliable"):
            do.rectangle(t["uv_bbox_px"], fill=col)
    im = Image.alpha_composite(im.convert("RGBA"), ov)
    dr = ImageDraw.Draw(im)
    for r in rows:
        uv = r[4]
        if uv.min() < -0.002 or uv.max() > 1.002:
            continue
        n = r[3]
        e = np.ptp(uv * T, axis=0)
        if e.min() > 300:                      # long diagonal slivers (unwrapped strips); they only clutter the image
            continue
        col = (255, 110, 110) if n[1] > 0.7 else (110, 160, 255) if n[1] < -0.7 else (210, 210, 80) if n[2] > 0.7 else (110, 110, 110)
        if not r[1]:
            col = tuple(c // 2 for c in col)
        dr.polygon([tuple(p) for p in uv * T], outline=col + (255,))
    try:
        font = ImageFont.truetype("/System/Library/Fonts/Helvetica.ttc", 28)
    except Exception:
        font = ImageFont.load_default()
    for nm in ("left", "right"):
        s = info.get(nm)
        if not s:
            continue
        cu, cv, _ = fits[nm]
        # FRONT arrow along the +L direction in texture space, from the door centre
        d = np.array([cu[0], cv[0]]); d = d / np.linalg.norm(d)
        cx, cy = s["door_centre_uv"] if s.get("door_centre_uv") else ((s["uv_bbox_px"][0] + s["uv_bbox_px"][2]) / 2, (s["uv_bbox_px"][1] + s["uv_bbox_px"][3]) / 2)
        b = s["uv_bbox_px"]
        ay = (b[1] + b[3]) / 2
        a0 = np.array([cx - d[0] * 90, ay - d[1] * 90]); a1 = np.array([cx + d[0] * 90, ay + d[1] * 90])
        dr.line([tuple(a0), tuple(a1)], fill=(0, 255, 0, 255), width=5)
        p = np.array([-d[1], d[0]])
        dr.polygon([tuple(a1 + d * 22), tuple(a1 + p * 14), tuple(a1 - p * 14)], fill=(0, 255, 0, 255))
        dr.text((a1[0] + d[0] * 26 - 8, a1[1] + d[1] * 26 - 14), "FRONT", fill=(0, 255, 0, 255), font=font)
        if s.get("door_centre_uv"):
            dr.ellipse([cx - 9, cy - 9, cx + 9, cy + 9], outline=(255, 255, 255, 255), width=3)
            dr.line([cx - 14, cy, cx + 14, cy], fill=(255, 255, 255, 255), width=2)
            dr.line([cx, cy - 14, cx, cy + 14], fill=(255, 255, 255, 255), width=2)
        dr.text((b[0] + 4, b[1] + 2), nm.upper() + " " + s["text"]["transform"], fill=(255, 255, 255, 255), font=font)
    dr.text((8, 990), car, fill=(255, 255, 255, 255), font=font)
    im.convert("RGB").save(os.path.join(PNG, car + ".png"))


def sheet(cars):
    cols, w = 5, 200
    rows_n = math.ceil(len(cars) / cols)
    sh = Image.new("RGB", (cols * w, rows_n * (w + 14)), (0, 0, 0))
    d = ImageDraw.Draw(sh)
    for i, car in enumerate(cars):
        p = os.path.join(PNG, car + ".png")
        if not os.path.exists(p):
            continue
        t = Image.open(p).resize((w, w), Image.LANCZOS)
        x, y = (i % cols) * w, (i // cols) * (w + 14)
        sh.paste(t, (x, y + 14))
        d.text((x + 3, y + 1), car, fill=(255, 255, 0))
    sh.save(os.path.join(PNG, "all.png"))


def main():
    cars = sys.argv[1:] or CARS
    os.makedirs(PNG, exist_ok=True)
    res = {}
    jp = os.path.join(OUT, "skinmap.json")
    if len(sys.argv) > 1 and os.path.exists(jp):
        res = json.load(open(jp))
    for car in cars:
        info, ctx, fits = analyse(car)
        res[car] = info
        debug_png(car, info, ctx, fits)
        L, R = info.get("left"), info.get("right")
        print(car, info["axes"]["front"], info["axes"]["left"],
              *[("%s rms %.1f n %d/%d %s" % (n, s["residual_rms_px"], s["n_inlier_tris_all_solids"], s["n_side_tris_all_solids"], s["text"]["transform"])) if s else n + " MISSING"
                for n, s in (("L", L), ("R", R))])
    res["_meta"] = dict(doc="see tools/art/skinmap.py docstring; pixels are for a 1024 texture; L front+, S left+, H up in metres of car space",
                        text_rule="viewer outside the side with the car front on the viewer's left (left side) / right (right side); apply pil_op to an upright text image, then paste at the region")
    json.dump(res, open(jp, "w"), indent=1)
    sheet([c for c in CARS if os.path.exists(os.path.join(PNG, c + ".png"))])


if __name__ == "__main__":
    main()
