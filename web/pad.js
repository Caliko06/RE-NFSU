// Gamepad (standard mapping) -> the keyboard path of web/input.js: the pad presses the same DIK keys, through the same
// ring and held set (startInput returns { key }), so the game sees a keyboard and its own action map applies.
// Keys are the game's defaults: arrows steer / gas / brake, Space handbrake, Left Shift nitrous, Enter accept, Escape back / pause.
//   menu : d-pad and left stick = arrows, A = Enter, B = Escape, Start = Escape
//   drive: left stick X = left / right, RT = Up (gas), LT = Down (brake), A or X = nitrous, B = handbrake, Start = Escape
// The page cannot read the game's race state, so the pad is in menu mode until a trigger is pulled (a race needs the gas),
// and back in menu mode on a d-pad press, Start, or 4 s with triggers and buttons released (the post-race screens).
// Polled in requestAnimationFrame, only while a pad is connected; only changes reach the ring.
'use strict';
const PAD_DIK = { esc: 0x01, enter: 0x1c, lshift: 0x2a, space: 0x39, up: 0xc8, left: 0xcb, right: 0xcd, down: 0xd0 };
const PAD_STICK = 0.4, PAD_TRIGGER = 0.3, PAD_IDLE_MS = 4000;

// Which DIKs a pad state asks for. s = { ax, ay, lt, rt, b: buttons[], mode }; returns { keys: Set, mode }.
function padKeys(s, now) {
  const D = PAD_DIK, k = new Set(), b = s.b;
  const dpad = b[12] || b[13] || b[14] || b[15], face = b[0] || b[1] || b[2] || b[3], trig = s.lt > PAD_TRIGGER || s.rt > PAD_TRIGGER;
  let mode = s.mode;
  if (trig) { mode = 'drive'; s.last = now; }
  else if (face || b[9]) s.last = now;
  if (dpad || b[9] || (mode === 'drive' && now - (s.last ?? now) > PAD_IDLE_MS)) mode = 'menu';
  if (s.ax < -PAD_STICK || b[14]) k.add(D.left);
  if (s.ax > PAD_STICK || b[15]) k.add(D.right);
  if (b[12] || (mode === 'menu' && s.ay < -PAD_STICK)) k.add(D.up);
  if (b[13] || (mode === 'menu' && s.ay > PAD_STICK)) k.add(D.down);
  if (s.rt > PAD_TRIGGER) k.add(D.up);
  if (s.lt > PAD_TRIGGER) k.add(D.down);
  if (b[9] || b[8]) k.add(D.esc);
  if (mode === 'menu') { if (b[0]) k.add(D.enter); if (b[1]) k.add(D.esc); }
  else { if (b[0] || b[2]) k.add(D.lshift); if (b[1]) k.add(D.space); }
  return { keys: k, mode };
}

function startPad(input) {
  if (!input || !navigator.getGamepads) return;
  let prev = new Set(), state = { mode: 'menu', last: undefined }, running = false;
  const release = () => { for (const d of prev) input.key(d, false); prev = new Set(); };
  function frame(now) {
    const pad = [...navigator.getGamepads()].find(p => p && p.connected);
    if (!pad) { running = false; release(); return; }          // unplugged: free the keys, stop polling
    const ax = pad.axes[0] || 0, ay = pad.axes[1] || 0, v = i => pad.buttons[i] ? (pad.buttons[i].value || (pad.buttons[i].pressed ? 1 : 0)) : 0;
    state.ax = ax; state.ay = ay; state.lt = v(6); state.rt = v(7);
    state.b = Array.from({ length: 16 }, (_, i) => v(i) > 0.5);
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
