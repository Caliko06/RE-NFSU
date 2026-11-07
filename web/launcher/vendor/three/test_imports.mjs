// Test de vendorizado: todo import relativo del arbol three/ debe resolver a un archivo existente.
// Uso: node web/launcher/vendor/three/test_imports.mjs
import { readFileSync, existsSync, readdirSync, statSync } from "node:fs";
import { join, dirname, resolve, relative, sep } from "node:path";
import { fileURLToPath } from "node:url";

const ROOT = dirname(fileURLToPath(import.meta.url));
const WEB = resolve(ROOT, "../../.."); // web/

const REQUIRED = [
  "build/three.module.min.js",
  "examples/jsm/loaders/GLTFLoader.js",
  "examples/jsm/postprocessing/EffectComposer.js",
  "examples/jsm/postprocessing/RenderPass.js",
  "examples/jsm/postprocessing/UnrealBloomPass.js",
  "examples/jsm/postprocessing/OutputPass.js",
  "examples/jsm/postprocessing/ShaderPass.js",
  "examples/jsm/postprocessing/Pass.js",
  "examples/jsm/postprocessing/MaskPass.js",
  "examples/jsm/objects/Reflector.js",
  "examples/jsm/shaders/CopyShader.js",
  "examples/jsm/shaders/LuminosityHighPassShader.js",
  "examples/jsm/shaders/OutputShader.js",
  "examples/jsm/utils/BufferGeometryUtils.js",
  "LICENSE",
  "importmap.json",
];

const SPEC_RE =
  /\b(?:import|export)\s+(?:[^'"`;]*?\s+from\s*)?['"]([^'"]+)['"]|\bimport\s*\(\s*['"]([^'"]+)['"]\s*\)/g;

function walk(dir, out = []) {
  for (const name of readdirSync(dir)) {
    const p = join(dir, name);
    if (statSync(p).isDirectory()) walk(p, out);
    else if (name.endsWith(".js") || name.endsWith(".mjs")) out.push(p);
  }
  return out;
}

const errors = [];

for (const rel of REQUIRED) {
  if (!existsSync(join(ROOT, rel))) errors.push(`falta archivo requerido: ${rel}`);
}

const jsFiles = walk(ROOT).filter((p) => !p.endsWith("test_imports.mjs"));
let checked = 0;

for (const file of jsFiles) {
  const src = readFileSync(file, "utf8");
  for (const m of src.matchAll(SPEC_RE)) {
    const spec = m[1] ?? m[2];
    if (!spec || !spec.startsWith(".")) continue;
    checked++;
    const target = resolve(dirname(file), spec.split(/[?#]/)[0]);
    if (!existsSync(target)) {
      errors.push(`${relative(ROOT, file)} -> ${spec} (resuelve a ${relative(ROOT, target)})`);
    }
  }
}

// El importmap debe apuntar a archivos reales (rutas relativas a web/).
const mapPath = join(ROOT, "importmap.json");
const map = JSON.parse(readFileSync(mapPath, "utf8"));
const expected = {
  three: "./launcher/vendor/three/build/three.module.min.js",
  "three/addons/": "./launcher/vendor/three/examples/jsm/",
};
for (const [key, want] of Object.entries(expected)) {
  if (map.imports?.[key] !== want) {
    errors.push(`importmap: "${key}" = ${JSON.stringify(map.imports?.[key])} (esperado ${JSON.stringify(want)})`);
    continue;
  }
  const target = resolve(WEB, want);
  if (!existsSync(target)) errors.push(`importmap: "${key}" apunta a ${want}, que no existe`);
}

console.log(`archivos js revisados: ${jsFiles.length}, imports relativos: ${checked}`);

if (errors.length) {
  console.error(`FALLÓ (${errors.length}):`);
  for (const e of errors) console.error("  " + e);
  process.exit(1);
}

console.log("OK: todos los imports relativos e importmap resuelven a archivos existentes");
