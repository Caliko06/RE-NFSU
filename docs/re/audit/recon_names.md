# Reconciliación de ledgers de nombres (RE-NFSU)

Script: /private/tmp/claude-501/-Users-angeldamian/79ee5150-e4ff-4a52-9b55-0fd755190ce7/scratchpad/recon_names.py
Solo lectura del repo. Regla de fusión replicada de tools/census/names_merge.py (V > I > U; empate = primer archivo en orden de glob).

## (a) Direcciones con 2+ nombres distintos entre fuentes

Conteo: **12**
- de ellas con conflicto entre archivos distintos: 12
- de ellas solo variante de forma (igual tras normalizar mayúsculas/puntuación): 0

- 0x40a880: camera='NullUpdate_ret'(V); sound='nullsub (shared empty ret, 510 refs)'(V)
- 0x472c60: assets='CarShape_Find'(V); props='CollisionShapes::FindByKey'(V)
- 0x47af20: assets='AnimBank_DynamicLoad'(V); tuning='CAnimBank::Initialize'(V)
- 0x5952a0: assets='Smackable::Loader'(V); props='SmackableChunks::Loader'(V)
- 0x59fb80: assets='LanguageStrings::FindByHash'(V); canon='GetLocalizedStringByHash'(V)
- 0x59fce0: assets='LanguageStrings::Loader'(V); canon='LanguagePack::Loader'(V)
- 0x59fd40: assets='LanguageStrings::Unloader'(V); canon='LanguagePack::Unloader'(V)
- 0x5a0060: assets='CareerEvents::IndexEventDesc'(V); canon='EventDescPack::IndexEvents'(V)
- 0x5a00a0: assets='CareerEvents::Loader'(V); canon='EventDescPack::Loader'(V)
- 0x5a0130: assets='CareerEvents::Unloader'(V); canon='EventDescPack::Unloader'(V)
- 0x5a1550: canon='Career::IsUpgradeUnlocked'(V); tuning='FECareerManager::IsUpgradeUnlocked'(V)
- 0x5a3570: canon='PartStore::HasPart'(V); tuning='FECareerPurchasedParts::HasBoughtPart'(V)

## (b) Filas fuente que no aparecen en names.tsv

Conteo: **19**
- b1, dirección ausente de names.tsv: 0
- b2, dirección presente pero el nombre de la fuente perdió la fusión: 12 (de ellas empate de confianza resuelto por orden de archivo: 12)
- b3, filas descartadas por la fusión (name o addr vacío / addr no parseable): 7
- Ejemplos de b2 (primeros 15):
  - 0x5a00a0 name='EventDescPack::Loader' canon:2 conf=V cv='high' | ganador=assets:'CareerEvents::Loader'
  - 0x5a0130 name='EventDescPack::Unloader' canon:3 conf=V cv='med' | ganador=assets:'CareerEvents::Unloader'
  - 0x5a0060 name='EventDescPack::IndexEvents' canon:4 conf=V cv='high' | ganador=assets:'CareerEvents::IndexEventDesc'
  - 0x59fce0 name='LanguagePack::Loader' canon:12 conf=V cv='high' | ganador=assets:'LanguageStrings::Loader'
  - 0x59fd40 name='LanguagePack::Unloader' canon:13 conf=V cv='med' | ganador=assets:'LanguageStrings::Unloader'
  - 0x59fb80 name='GetLocalizedStringByHash' canon:14 conf=V cv='high' | ganador=assets:'LanguageStrings::FindByHash'
  - 0x5952a0 name='SmackableChunks::Loader' props:2 conf=V cv='high' | ganador=assets:'Smackable::Loader'
  - 0x472c60 name='CollisionShapes::FindByKey' props:24 conf=V cv='high' | ganador=assets:'CarShape_Find'
  - 0x40a880 name='nullsub (shared empty ret, 510 refs)' sound:2 conf=V cv='high' | ganador=camera:'NullUpdate_ret'
  - 0x47af20 name='CAnimBank::Initialize' tuning:13 conf=V cv='high' | ganador=assets:'AnimBank_DynamicLoad'
  - 0x5a1550 name='FECareerManager::IsUpgradeUnlocked' tuning:217 conf=V cv='high' | ganador=canon:'Career::IsUpgradeUnlocked'
  - 0x5a3570 name='FECareerPurchasedParts::HasBoughtPart' tuning:219 conf=V cv='high' | ganador=canon:'PartStore::HasPart'
- Ejemplos de b3 (primeros 15):
  - camera:114 raw='chunk:0x34600' name='CarTypeInfo chunk id (GLOBALB.BUN)'
  - camera:122 raw='info+0xb50' name='CarCamRowTable'
  - camera:123 raw='row+0x0' name='CamRow_POVId'
  - camera:124 raw='row+0x2' name='CamRow_AuxAngle'
  - camera:125 raw='row+0x4' name='CamRow_Distance'
  - camera:126 raw='row+0x8' name='CamRow_Height'
  - camera:127 raw='row+0xc' name='CamRow_Lateral'

- (ninguno)
- ... (19 en total; se muestran 15)

## (c) Filas de names.tsv cuyo nombre no coincide con ninguna fuente

Conteo: **0**
- de ellas sin ninguna fila fuente en esa dirección: 0

- (ninguno)

## (d) V en names.tsv sin V en ninguna fuente

Conteo: **0**

- (ninguno)

## (e) Direcciones mal formadas o duplicadas

Conteo: **7**
- mal formadas en fuentes (no matchean ^0x[0-9a-f]{6}$): 7
- mal formadas en names.tsv: 0
- direcciones repetidas dentro de un mismo archivo fuente: 0
- direcciones repetidas en names.tsv: 0

- MAL-FUENTE camera:114 raw='chunk:0x34600' name='CarTypeInfo chunk id (GLOBALB.BUN)'
- MAL-FUENTE camera:122 raw='info+0xb50' name='CarCamRowTable'
- MAL-FUENTE camera:123 raw='row+0x0' name='CamRow_POVId'
- MAL-FUENTE camera:124 raw='row+0x2' name='CamRow_AuxAngle'
- MAL-FUENTE camera:125 raw='row+0x4' name='CamRow_Distance'
- MAL-FUENTE camera:126 raw='row+0x8' name='CamRow_Height'
- MAL-FUENTE camera:127 raw='row+0xc' name='CamRow_Lateral'

## (f) Direcciones nombradas que NO están en lifted ni en funcs.tsv

Conteo: **143**
- lifted (build/gen/f*.c, patrón scoreboard): 13739 funciones
- funcs.tsv: 14333 entradas válidas, 0 entradas no parseables
- names.tsv con dirección en lifted: 886 de 1039

- 0x40b3f0 name='RenderSetupBlurFlags' conf=V from=blur ln=15
- 0x42c3c0 name='Player::CreateRearViewMirror_call' conf=V from=camera ln=59
- 0x42d2f4 name='ChangeCameraMover_JumpTable' conf=V from=camera ln=63
- 0x42d330 name='ChangeCameraMover_IndexTable' conf=V from=camera ln=64
- 0x431a2e name='JoyEvent_CAMERA_POV_CHANGE_case' conf=V from=camera ln=73
- 0x532ad7 name='(not a function: mid-instruction inside EAXSND8Wrapper::Initialize 0x532a20)' conf=V from=sound ln=560
- 0x656040 name='SNDMEMI_usage_percent (map: SNDMEMI_restore)' conf=V from=sound ln=886
- 0x6b5a30 name='TeleportInterval_Free' conf=V from=traffic ln=905
- 0x6b5a34 name='TeleportInterval_Route' conf=V from=traffic ln=906
- 0x6b5a38 name='TeleportFirstStep' conf=V from=traffic ln=907
- 0x6b5a3c name='TeleportRouteLimit' conf=V from=traffic ln=908
- 0x6b5a50 name='TeleportSlowPlayerSpeed' conf=V from=traffic ln=909
- 0x6b5a5c name='TeleportSpawnObjSpeed' conf=V from=traffic ln=910
- 0x6b5a68 name='SpawnRecordWindow' conf=V from=traffic ln=911
- 0x6b6c5c name='CamBlend_Dist_A' conf=I from=camera ln=912
- ... (143 en total; se muestran 15)

## (g) Nombres que contradicen un nombre real ya presente en funcs.tsv

Conteo: **0**
- names.tsv que coinciden con funcs.tsv (nombre real): 0
- filas fuente que contradicen funcs.tsv (nombre real): 0


- (ninguno)

## (h) Filas con nombre vacío

Conteo: **0**
- nombre vacío en fuentes: 0
- nombre solo espacios en fuentes: 0
- addr vacío en fuentes: 0
- nombre vacío o de espacios en names.tsv: 0

- (ninguno)

## (i) Conteo por archivo

| archivo | filas crudas | validas (fusionables) | V | I | U | descartadas | mal formadas addr |
|---|---|---|---|---|---|---|---|
| assets | 187 | 187 | 173 | 14 | 0 | 0 | 0 |
| blur | 62 | 62 | 52 | 9 | 1 | 0 | 0 |
| camera | 130 | 123 | 42 | 65 | 16 | 7 | 7 |
| canon | 69 | 69 | 66 | 3 | 0 | 0 | 0 |
| props | 28 | 28 | 18 | 10 | 0 | 0 | 0 |
| rivals | 28 | 28 | 20 | 8 | 0 | 0 | 0 |
| sound | 212 | 212 | 200 | 12 | 0 | 0 | 0 |
| traffic | 120 | 120 | 67 | 49 | 4 | 0 | 0 |
| tuning | 244 | 244 | 205 | 38 | 1 | 0 | 0 |

names.tsv por columna `from` (ganadores):

| from | filas | V | I | U |
|---|---|---|---|---|
| assets | 187 | 173 | 14 | 0 |
| blur | 62 | 52 | 9 | 1 |
| camera | 122 | 41 | 65 | 16 |
| canon | 63 | 60 | 3 | 0 |
| props | 26 | 16 | 10 | 0 |
| rivals | 27 | 20 | 7 | 0 |
| sound | 211 | 199 | 12 | 0 |
| traffic | 111 | 61 | 46 | 4 |
| tuning | 230 | 197 | 32 | 1 |

- total único en names.tsv: **1039** (V=819, I=198, U=22)
- total único replicado desde fuentes: **1039** direcciones
- direcciones distintas entre todas las fuentes válidas: 1039

## (j) Cosas raras

- filas con número de campos distinto del encabezado: fuentes=0, names.tsv=0
- valores de confidence fuera de V/I/U (archivo, valor: filas), y cómo los mapea conf():
  - assets 'high': 171
  - assets 'low': 1
  - assets 'med': 15
  - canon 'high': 45
  - canon 'low': 4
  - canon 'med': 20
  - props 'high': 18
  - props 'low': 1
  - props 'med': 9
  - sound 'high': 128
  - sound 'low': 7
  - sound 'med': 77
  - traffic 'high': 67
  - traffic 'low': 4
  - traffic 'med': 49
  - tuning 'high': 141
  - tuning 'low': 12
  - tuning 'med': 91
- names.tsv vs fusion replicada: solo en fuentes=0, solo en names.tsv=0, campo distinto=0
- nombres usados en 2+ direcciones de names.tsv: 0
- nombres en names.tsv con caracteres no ASCII, '?', TODO, unknown o guess: 1
  - 0x4c40a0 name='(unknown garage screen)::NotificationMessage' conf=I from=tuning ln=270
- funcs.tsv: entradas sub_ = 14250, sub_<hex> que no coincide con su dirección: 0
- names_raw/names_sound_agent.tsv (212 filas) vs census/names_sound.tsv (212 filas): solo en raw=0, solo en census=0
- names_raw/names_tuning_agent.tsv (244 filas) vs census/names_tuning.tsv (244 filas): solo en raw=0, solo en census=0
- names_raw/assets_loadersA.tsv: 191 filas, esquema kind/addr_or_id (no se fusiona); con dirección tipo 0xNNNNNN: 111, de ellas en names.tsv: 88
- names_raw/assets_loadersB.tsv: 136 filas, esquema kind/addr_or_id (no se fusiona); con dirección tipo 0xNNNNNN: 84, de ellas en names.tsv: 84
- names_seed.tsv excluido (menciones): 2923 filas

