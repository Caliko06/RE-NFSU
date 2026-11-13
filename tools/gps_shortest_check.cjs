// Actual WORLD graph: compare A* with independent queue-based edge relaxation.
// Run from the repository root: node tools/gps_shortest_check.cjs
const assert=require('node:assert/strict');
const fs=require('node:fs'), vm=require('node:vm');
const roads=JSON.parse(fs.readFileSync('web/gps/roads.json','utf8'));
const events={}, buttons={}, gps={roads,pose:()=>({x:roads.nodes[0][0],y:roads.nodes[0][1],z:roads.nodes[0][2]})};
const controls={setAttribute(){},querySelector:s=>buttons[s]??=( {})};
const sandbox={window:{RN_GPS:gps},document:{getElementById:()=>({append(){}}),createElement:()=>controls},addEventListener:(n,fn)=>events[n]=fn,setInterval(){},Atomics,Float64Array,Int32Array,Math};
vm.runInNewContext(fs.readFileSync('web/gps/route.js','utf8'),sandbox);
events['rn-gps-mapclick']({detail:{x:-1053.7,y:993.1}});
const actual=gps.route;
const graph=roads.nodes.map(()=>[]),dist=(a,b)=>Math.hypot(...a.map((x,i)=>x-b[i]));
for(const[a,b]of roads.edges){const w=dist(roads.nodes[a],roads.nodes[b]);graph[a].push([b,w]);graph[b].push([a,w]);}
const d=new Float64Array(roads.nodes.length).fill(Infinity),inq=new Uint8Array(d.length),q=[0];d[0]=0;inq[0]=1;
for(let i=0;i<q.length;i++){const u=q[i];inq[u]=0;for(const[v,w]of graph[u])if(d[u]+w<d[v]){d[v]=d[u]+w;if(!inq[v]){q.push(v);inq[v]=1;}}}
const invalid=actual.ids.slice(1).filter((v,i)=>!graph[actual.ids[i]].some(([n])=>n===v));
const sections=roads.sections.filter(s=>s.nodes.some(n=>actual.ids.includes(n))).map(s=>s.id);
assert.ok(Math.abs(actual.metres-d[actual.destination])<1e-8, 'A* must equal the independent shortest-path distance');
assert.equal(invalid.length,0,'Every route segment must be a real street edge');
assert.ok(sections.includes(78) && sections.some(s=>s<78) && sections.some(s=>s>=79),'Route must join both cities through the bridge');
console.log(JSON.stringify({metres:actual.metres,dijkstraEquivalent:d[actual.destination],difference:actual.metres-d[actual.destination],nodes:actual.ids.length,destination:actual.destination,invalidEdges:invalid.length,bridge:sections.includes(78),bayview:sections.some(s=>s>=79),olympic:sections.some(s=>s<78)}));
