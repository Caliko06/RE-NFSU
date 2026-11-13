// WORLD navigation over the verified undirected 0x34121/0x34122 road graph.
// Host ABI: host/gps.h +48 count, +52 XY, 2048 points; no guest-memory patches.
(() => {
  'use strict';
  const gps = window.RN_GPS;
  const ARRIVAL_METRES = 20, ARRIVAL_HEIGHT = 8, RECALCULATE_METRES = 40;
  const panel = document.getElementById('gps-map');
  const controls = document.createElement('nav');
  controls.setAttribute('aria-label', 'Destino GPS'); controls.className = 'gps-actions';
  controls.innerHTML = `<span class="gps-route-info" role="status">Haz clic en una calle para marcar tu destino</span>
    <button type="button" class="gps-teleport" disabled>Teletransportar</button>
    <button type="button" class="gps-clear" disabled>Borrar destino</button>`;
  panel.append(controls);
  const info = controls.querySelector('.gps-route-info');
  const teleport = controls.querySelector('.gps-teleport'), clearButton = controls.querySelector('.gps-clear');
  let graph, destination = null, route = null, progress = 0, teleportPending = false;
  const distance = (a, b) => Math.hypot(a[0] - b[0], a[1] - b[1], a[2] - b[2]);
  function adjacency() {
    if (graph) return graph;
    graph = gps.roads.nodes.map(() => []);
    for (const [a, b] of gps.roads.edges) {
      const cost = distance(gps.roads.nodes[a], gps.roads.nodes[b]);
      graph[a].push([b, cost]); graph[b].push([a, cost]);
    }
    return graph;
  }
  function nearest(x, y, z) {
    let best = -1, bestDistance = Infinity;
    gps.roads.nodes.forEach((p, id) => {
      const d = (p[0] - x) ** 2 + (p[1] - y) ** 2 + (z === undefined ? 0 : (p[2] - z) ** 2);
      if (d < bestDistance) { best = id; bestDistance = d; }
    });
    return best;
  }
  // A* with an admissible Euclidean heuristic and a binary minimum heap.
  function path(start, goal) {
    const nodes = gps.roads.nodes, adjacent = adjacency(), heap = [];
    const cost = new Float64Array(nodes.length).fill(Infinity), previous = new Int32Array(nodes.length).fill(-1);
    function push(id, score) {
      let i = heap.length; heap.push([id, score]);
      while (i) {
        const parent = (i - 1) >> 1;
        if (heap[parent][1] <= score) break;
        heap[i] = heap[parent]; i = parent;
      }
      heap[i] = [id, score];
    }
    function pop() {
      const result = heap[0], last = heap.pop();
      if (heap.length) {
        let i = 0;
        while (i * 2 + 1 < heap.length) {
          let child = i * 2 + 1;
          if (child + 1 < heap.length && heap[child + 1][1] < heap[child][1]) child++;
          if (heap[child][1] >= last[1]) break;
          heap[i] = heap[child]; i = child;
        }
        heap[i] = last;
      }
      return result;
    }
    cost[start] = 0; push(start, distance(nodes[start], nodes[goal]));
    while (heap.length) {
      const [id, score] = pop();
      if (score > cost[id] + distance(nodes[id], nodes[goal])) continue;
      if (id === goal) {
        const ids = [];
        for (let n = goal; n !== -1; n = previous[n]) ids.push(n);
        return { ids: ids.reverse(), metres: cost[goal], start, destination: goal };
      }
      for (const [other, edge] of adjacent[id]) {
        const next = cost[id] + edge;
        if (next >= cost[other]) continue;
        previous[other] = id; cost[other] = next;
        push(other, next + distance(nodes[other], nodes[goal]));
      }
    }
    return null;
  }
  function publish() {
    const m = window.RN_M;
    if (!m?._rn_gps_addr) return;
    const base = m._rn_gps_addr() >>> 0, words = m.HEAP32, countAt = (base + 48) >>> 2;
    Atomics.store(words, countAt, 0);
    if (!route) return;
    // Only the forward window is needed by the HUD. The full street path stays on the big map.
    const ids = route.ids.slice(progress, progress + 2048);
    const xy = new Float32Array(m.HEAPU8.buffer, base + 52, ids.length * 2);
    ids.forEach((id, i) => { xy[i * 2] = gps.roads.nodes[id][0]; xy[i * 2 + 1] = gps.roads.nodes[id][1]; });
    Atomics.store(words, countAt, ids.length);
  }
  function clear(message = 'Destino borrado · haz clic para marcar otro') {
    destination = null; route = gps.route = null; progress = 0;
    teleport.disabled = clearButton.disabled = true; info.textContent = message; publish();
  }
  function calculate(car) {
    route = gps.route = path(nearest(car.x, car.y, car.z), destination); progress = 0;
    teleport.disabled = !route; clearButton.disabled = false;
    info.textContent = route ? `${Math.round(route.metres).toLocaleString('es-MX')} m · ${route.ids.length.toLocaleString('es-MX')} nodos` : 'No se encontró una ruta. Marca otra calle.';
    publish();
  }
  addEventListener('rn-gps-mapclick', e => {
    const car = gps.pose();
    if (!car || !gps.roads) return;
    destination = nearest(e.detail.x, e.detail.y); calculate(car);
  });
  clearButton.onclick = () => clear();
  teleport.onclick = () => {
    const car = gps.pose();
    if (!car || destination === null || teleportPending) return;
    const p = gps.roads.nodes[destination];
    // Face along the final incoming edge (or a real neighbour for a one-node path).
    const from = route?.ids.length > 1 ? gps.roads.nodes[route.ids.at(-2)] : null;
    const other = from || gps.roads.nodes[adjacency()[destination][0][0]];
    const dx = from ? p[0] - other[0] : other[0] - p[0], dy = from ? p[1] - other[1] : other[1] - p[1];
    const yaw16 = Math.round(Math.atan2(dy, dx) * 65536 / (2 * Math.PI)) & 65535;
    if (window.rnGpsTeleport(p[0], p[1], p[2], yaw16)) {
      teleportPending = true; teleport.disabled = true; info.textContent = 'Teletransportando…';
    } else info.textContent = 'Hay un teletransporte en curso. Espera un momento.';
  };
  // Closest point on a street segment, in XYZ so stacked roads do not count as arrival/progress.
  function segmentDistance(car, a, b) {
    const delta = b.map((v, i) => v - a[i]), p = [car.x, car.y, car.z];
    const length2 = delta.reduce((sum, v) => sum + v * v, 0);
    const t = length2 ? Math.max(0, Math.min(1, delta.reduce((sum, v, i) => sum + (p[i] - a[i]) * v, 0) / length2)) : 0;
    return Math.hypot(...delta.map((v, i) => p[i] - a[i] - t * v));
  }
  setInterval(() => {
    const car = gps.pose();
    if (!car) { if (destination !== null) clear('Haz clic en una calle para marcar tu destino'); return; }
    if (teleportPending) {
      const m = window.RN_M, base = m._rn_gps_addr() >>> 2;
      if (Atomics.load(m.HEAP32, base + 10)) return;
      teleportPending = false; teleport.disabled = destination === null;
      if (Atomics.load(m.HEAP32, base + 11) !== 1) { info.textContent = 'No se pudo teletransportar: no hay suelo disponible en el destino.'; return; }
    }
    if (destination === null || !route) return;
    const target = gps.roads.nodes[destination];
    // Product rule: arrive within 20 m on XY and 8 m vertically. Poll every 250 ms.
    if (Math.hypot(car.x - target[0], car.y - target[1]) < ARRIVAL_METRES && Math.abs(car.z - target[2]) < ARRIVAL_HEIGHT) {
      clear('Llegaste a tu destino'); return;
    }
    let nearestDistance = route.ids.length === 1 ? distance([car.x, car.y, car.z], target) : Infinity, nearestSegment = 0;
    for (let i = 0; i < route.ids.length - 1; i++) {
      const d = segmentDistance(car, gps.roads.nodes[route.ids[i]], gps.roads.nodes[route.ids[i + 1]]);
      if (d < nearestDistance) { nearestDistance = d; nearestSegment = i; }
    }
    // Product rule: recompute beyond 40 m from the polyline, including height at overpasses.
    if (nearestDistance > RECALCULATE_METRES) calculate(car);
    else if (nearestSegment !== progress) { progress = nearestSegment; publish(); }
  }, 250);
  addEventListener('rn-gps-draw', ({ detail: { ctx, project } }) => {
    if (!route || destination === null) return;
    ctx.save(); ctx.beginPath();
    route.ids.slice(progress).forEach((id, i) => {
      const p = gps.roads.nodes[id], xy = project(p[0], p[1]);
      if (i) ctx.lineTo(...xy); else ctx.moveTo(...xy);
    });
    ctx.lineJoin = ctx.lineCap = 'round'; ctx.strokeStyle = '#08111e'; ctx.lineWidth = 7; ctx.stroke();
    ctx.strokeStyle = '#ffc85a'; ctx.lineWidth = 3; ctx.stroke();
    const p = gps.roads.nodes[destination], xy = project(p[0], p[1]);
    ctx.beginPath(); ctx.arc(...xy, 7, 0, Math.PI * 2); ctx.fillStyle = '#ffc85a'; ctx.fill();
    ctx.strokeStyle = '#08111e'; ctx.lineWidth = 2; ctx.stroke(); ctx.restore();
  });
})();
