# 0046a6e0 · sub_46a6e0

- Dirección: `0x0046a6e0` (VA), nombre Hopper `sub_46a6e0`.
- Fuente: `census/hopper/decomp.c`, línea 179090, bloque de 114 líneas de cuerpo. Conteos en `census/hopper/funcs.tsv`: 117 líneas, 1 callers, 5 callees. **F**
- Bug que motivó la extracción: reset/fall-through del auto (pasa paredes o se cae después de un reset). Ver `docs/re/coll_reset.md` y `docs/openworld/re_coll_pool.md`.

## Por qué está en la lista (citas de los docs)

| Doc | Línea | Texto |
| --- | --- | --- |
| `docs/re/coll_reset.md` | 35 | destroys nothing (only 0x46a580 and 0x46a6e0 free a slot). That car then has no wall and no ground bodies -> both |
| `docs/openworld/re_coll_pool.md` | 24 | pool (0x441ba7); 0x566dc0 builds the free list from edi; save 0x46a6e0 writes row indices, not slot indices; |
| `docs/openworld/re_coll_pool.md` | 42 | - 0x46a440 / 0x46a6e0: only for save and restore ("TrackPolygon%d", row index u16). |

## Pseudocódigo (tal cual, sin editar) **F**

```c
    var_C = *0x0;
    *0x0 = &var_C;
    decomp_var_20 = ebx;
    ebx = arg_0;
    esp = esp - 0x28;
    sub_571ea0(0x0, "AllTrackPolygonCollisionBodies");
    if (ebx[0x3e] != 0x0 || ebx[0x3f] != 0x0) {
            esp = esp - 0x14;
            sub_571c20(ebx, dword_736014, 0x4, 0x4, 0x1);
    }
    decomp_var_24 = esi;
    esp = esp - 0x8;
    var_28 = edi;
    if (ebx[0x3d] == 0x0) goto loc_46a815;
    goto loc_46a739;

loc_46a815:
    if (*dword_779c70 != 0x0) {
            esi = *dword_779c70;
            esi = esi - 0x4;
    }
    else {
            esi = 0x0;
    }
    edi = sub_40cb70();
    if (esi != edi) {
            do {
                    if (esi[0x15] == 0x3) {
                            var_18 = SAR(*(esi[0x18] + 0xc) - *dword_77b140, 0x5);
                            sub_571c20(ebx, &var_18, 0x2, 0x2, 0x0);
                            var_14 = esi[0xc];
                            sub_571c20(ebx, &var_14, 0x2, 0x2, 0x0);
                            esp = esp - 0x2c;
                            (*(*esi + 0x4))(ebx);
                    }
                    esi = esi[0x1];
                    if (esi != 0x0) {
                            esi = esi - 0x4;
                    }
                    else {
                            esi = 0x0;
                    }
            } while (esi != edi);
    }
    esp = esp - 0x14;
    var_1C = 0xffff;
    sub_571c20(ebx, &var_1C, 0x2, 0x2, 0x0);
    goto loc_46a8a9;

loc_46a739:
    &var_28 = &var_28;
    goto loc_46a740;

loc_46a8a9:
    ecx = sign_extend_32(ebx[0x40]);
    *((ecx << 0x4) + ebx + 0x58) = ebx[0x54] - *((ecx << 0x4) + ebx + 0x58);
    edx = ebx[0x40];
    ecx = ebx[0x11];
    eax = sign_extend_32(edx - 0x1);
    ebx[0x40] = edx - 0x1;
    esp = esp + 0x8;
    if (eax < ecx) {
            ebx[0x11] = 0xffffffff;
    }
    *0x0 = var_C;
    &var_1C = ebp;
    return eax;

loc_46a740:
    esp = esp - 0x14;
    eax = sub_571c20(ebx, &arg_2, 0x2, 0x2, 0x0);
    eax = arg_2;
    if (eax != 0xffff) {
            esp = esp - 0x14;
            var_18 = ((eax & 0xffff) << 0x5) + *dword_77b140;
            eax = sub_571c20(ebx, &var_10, 0x2, 0x2, 0x0);
            esi = *dword_72cbf4;
            ecx = esi + 0x10;
            edi = esi;
            var_14 = ecx;
            if (esi[0x4] == 0x0 && (*(int8_t *)(*dword_72cbf4 + 0x14) & 0x1) != 0x0) {
                    sub_566e60();
                    ecx = var_14;
            }
            eax = edi[0x6];
            edx = *ecx;
            eax = eax + 0x1;
            if (edx != 0x0) {
                    var_14 = *edx;
                    if (eax > edi[0x7]) {
                            edi[0x7] = eax;
                    }
                    edi[0x6] = eax;
                    *ecx = var_14;
                    if ((edi[0x14] & 0x2) != 0x0) {
                            edi = edi[0xa];
                            edi = SAR(edi, 0x2);
                            bool_9 = true;
                            if (edi > 0x0) {
                                    asm { rep stosd  dword [edi], eax };
                            }
                    }
            }
            eax = 0x0;
            if (edx != 0x0) {
                    esp = esp - 0xc;
                    eax = sub_46a440();
            }
            esp = esp - 0x4;
            (*(*eax + 0x4))(ebx);
            continue;
    }
    break;

```

## Callers (1) **F**

| Dirección | Nombre |
| --- | --- |
| `0041fc00` | `sub_41fc00` |

## Callees (5) **F**

| Dirección | Nombre |
| --- | --- |
| `0040cb70` | `sub_40cb70` |
| `0046a440` | `sub_46a440` |
| `00566e60` | `sub_566e60` |
| `00571c20` | `sub_571c20` |
| `00571ea0` | `sub_571ea0` |

## Globals

Identificadores tomados del pseudocódigo tal cual. Que el nombre aparezca es **F**; la separación lectura/escritura es **I** (se deduce de si el nombre cae a la izquierda del `=` de su línea). Las direcciones `0x...` van como las imprime Hopper.

### Escritos (1) **I**

- `dword_779c70`

### Leídos (4) **I**

- `dword_736014`
- `dword_779c70`
- `dword_77b140`
- `dword_72cbf4`

## Notas

- El pseudocódigo es el de Hopper sin tocar: los nombres `sub_*`, `var_*` y `arg_*` son suyos, no de esta extracción. **F**
- Callers/callees son las líneas `// callers:` y `// callees:` del bloque en `decomp.c`; un call indirecto no aparece ahí. **F** el listado, **I** que sea completo.
- No se corrió el juego para este documento: nada de lo de arriba está verificado en ejecución. **NV**
