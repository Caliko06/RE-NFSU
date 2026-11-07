// Scene lifecycle and the original /?play=1 route. The launcher UI lives in launcher_ui.js.
const reduced = matchMedia('(prefers-reduced-motion: reduce)');
const scene = (name, ...args) => window.RN_SCENE?.[name]?.(...args);
window.RN_LAUNCH_GAME = async selection => {
  if (document.body.classList.contains('leaving')) return;
  document.body.classList.add('leaving');
  document.getElementById('status').textContent = 'Iniciando Underground…';
  RN_LAUNCH.save(selection);
  // Fade first, then enter exactly the existing game route with the catalog's query.
  await new Promise(resolve => gsap.to('#fade', {
    opacity: 1, duration: reduced.matches ? 0 : .24, onComplete: resolve,
  }));
  location.href = '/?' + RN_LAUNCH.query(selection);
};
try {
  await scene('start', document.getElementById('scene'), { base: 'launcher/v3/' });
  if (!window.RN_SCENE) document.documentElement.classList.add('static');
  scene('motion', !reduced.matches);
  scene('screen', 'main');
} catch {
  document.documentElement.classList.add('static');
}
reduced.addEventListener('change', () => scene('motion', !reduced.matches));
let pointerFrame = 0, px = 0, py = 0;
addEventListener('pointermove', e => {
  if (reduced.matches || e.pointerType === 'touch') return;
  px = e.clientX / innerWidth * 2 - 1; py = e.clientY / innerHeight * 2 - 1;
  if (!pointerFrame) pointerFrame = requestAnimationFrame(() => { pointerFrame = 0; scene('pointer', px, py); });
});
addEventListener('pageshow', e => {
  if (!e.persisted) return;
  document.body.classList.remove('leaving');
  gsap.set('#fade', { opacity: 0 });
  document.getElementById('status').textContent = '';
  scene('resume');
});
