// Gamepad (standard mapping) -> the keyboard path of web/input.js: the pad presses the same DIK keys, through the same
// ring and held set (startInput returns { key }), so the game sees a keyboard and its own action map applies.
// Keys are the game's defaults: arrows steer / gas / brake, Left Shift handbrake, Space nitrous (the table at 0x702c98), C camera, R respot, Enter accept, Escape back / pause.
// Default buttons (web/binds.js, remappable and saved; Select opens that overlay):
//   menu : d-pad and left stick = arrows, A = Enter, B = Escape, Start = Escape
//   drive: left stick X = left / right (analog stick, digital past a dead zone: the game's keyboard path is on/off and its own steering ramp smooths it),
//          RT = gas, LT = brake, A = nitrous, B = handbrake, Y = camera, RB = reset car, Start = pause
// The page cannot read the game's race state, so the pad is in menu mode until a trigger is pulled (a race needs the gas),
// and back in menu mode on a d-pad press, Start, or 4 s with triggers and buttons released (the post-race screens).
// Polled in requestAnimationFrame, only while a pad is connected; only changes reach the ring.
'use strict';
const PAD_DIK = { esc: 0x01, enter: 0x1c, lshift: 0x2a, space: 0x39, up: 0xc8, left: 0xcb, right: 0xcd, down: 0xd0, camera: 0x2e, respot: 0x13,
  gup: 0x1e, gdn: 0x2c };   // Shift Up A / Shift Down Z: action table 0x702c98 rows app 7 and 8 (semantic 0x8100041e, 0x8100042c; their other keys are Insert, Delete)
const PAD_STICK = 0.4, PAD_TRIGGER = 0.3, PAD_IDLE_MS = 4000;

// The menu/drive layout heuristic (web/touch.js reads the game's screens instead). st = { mode, last }; sig = { drive: gas pulled, menu: navigation
// asked (d-pad, Start), active: any control held }; drive after the gas, menu on navigation or after idleMs without activity.
function inputNextMode(st, now, sig, idleMs = PAD_IDLE_MS) {
  if (sig.drive) { st.mode = 'drive'; st.last = now; }
  else if (sig.active) st.last = now;
  if (sig.menu || (st.mode === 'drive' && now - (st.last ?? now) > idleMs)) st.mode = 'menu';
  return st.mode;
}

// Which DIKs a pad state asks for. s = { ax, ay, lt, rt, b: buttons[], mode }; pb = action -> button (BINDS.pad); returns { keys: Set, mode }.
function padKeys(s, now, pb = BINDS.pad) {
  const D = PAD_DIK, k = new Set(), b = s.b;
  const dpad = b[12] || b[13] || b[14] || b[15], face = b[0] || b[1] || b[2] || b[3] || b[4] || b[5], trig = s.lt > PAD_TRIGGER || s.rt > PAD_TRIGGER;
  const mode = inputNextMode(s, now, { drive: trig, menu: dpad || b[pb.pause], active: face || b[pb.pause] });
  if (s.ax < -PAD_STICK || b[14]) k.add(D.left);
  if (s.ax > PAD_STICK || b[15]) k.add(D.right);
  if (b[12] || (mode === 'menu' && s.ay < -PAD_STICK)) k.add(D.up);
  if (b[13] || (mode === 'menu' && s.ay > PAD_STICK)) k.add(D.down);
  if (s.rt > PAD_TRIGGER) k.add(D.up);
  if (s.lt > PAD_TRIGGER) k.add(D.down);
  if (b[pb.pause]) k.add(D.esc);
  if (mode === 'menu') { if (b[pb.accept]) k.add(D.enter); if (b[pb.back]) k.add(D.esc); }
  else {
    if (b[pb.nitro]) k.add(D.space); if (b[pb.handbrake]) k.add(D.lshift);
    if (b[pb.camera]) k.add(D.camera); if (b[pb.respot]) k.add(D.respot);
  }
  return { keys: k, mode };
}

function startPad(input) {
  if (!input || !navigator.getGamepads) return;
  let prev = new Set(), selPrev = false, state = { mode: 'menu', last: undefined }, running = false;
  const release = () => { for (const d of prev) input.key(d, false); prev = new Set(); };
  function frame(now) {
    const pad = [...navigator.getGamepads()].find(p => p && p.connected);
    if (!pad) { running = false; release(); return; }          // unplugged: free the keys, stop polling
    const ax = pad.axes[0] || 0, ay = pad.axes[1] || 0, v = i => pad.buttons[i] ? (pad.buttons[i].value || (pad.buttons[i].pressed ? 1 : 0)) : 0;
    state.ax = ax; state.ay = ay; state.lt = v(6); state.rt = v(7);
    state.b = Array.from({ length: 16 }, (_, i) => v(i) > 0.5);
    const sel = state.b[8];
    if (sel && !selPrev) BINDS.toggle();                        // Select: the bindings overlay (web/binds.js)
    selPrev = sel;
    if (BINDS.open) { release(); requestAnimationFrame(frame); return; }   // the overlay owns the pad while it is open
    const r = padKeys(state, now);
    state.mode = r.mode;
    for (const d of prev) if (!r.keys.has(d)) input.key(d, false);
    for (const d of r.keys) if (!prev.has(d)) input.key(d, true);
    prev = r.keys;
    requestAnimationFrame(frame);
  }
  const go = () => { if (!running) { running = true; requestAnimationFrame(frame); } };
  addEventListener('gamepadconnected', go);
  addEventListener('gamepaddisconnected', () => { release(); });
  addEventListener('blur', release);                           // a held button must not stay down in the game
  if ([...navigator.getGamepads()].some(p => p && p.connected)) go();
}
