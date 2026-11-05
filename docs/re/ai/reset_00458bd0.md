# 00458bd0 · sub_458bd0

- Dirección: `0x00458bd0` (VA), nombre Hopper `sub_458bd0`.
- Fuente: `census/hopper/decomp.c`, línea 148274, bloque de 104 líneas de cuerpo. Conteos en `census/hopper/funcs.tsv`: 107 líneas, 1 callers, 0 callees. **F**
- Bug que motivó la extracción: reset/fall-through del auto (pasa paredes o se cae después de un reset). Ver `docs/re/coll_reset.md` y `docs/openworld/re_coll_pool.md`.

## Por qué está en la lista (citas de los docs)

| Doc | Línea | Texto |
| --- | --- | --- |
| `docs/openworld/re_coll_pool.md` | 52 | Thread c, int3 0x441b82 in 0x441b20, stack AcquireBody 0x441b90 <- QueryBox <- RefillCache <- traffic teleport (0x59b8d0 / 0x458bd0): a ground query for a traffic car found no body of count 0. |

## Pseudocódigo (tal cual, sin editar) **F**

```c
    edx = *edi;
    decomp_var_4 = ebx;
    decomp_var_8 = ebp;
    ebp = arg_0;
    esp = esp - 0xc;
    decomp_var_c = esi;
    esi = SAR(ebp - *dword_736150, 0x5) & 0xff;
    (edx[0x10])(decomp_var_c, decomp_var_8, decomp_var_4);
    if (arg_9 == 0x1) {
            if (arg_7 == 0x3) {
                    eax = 0x0;
            }
            else {
                    ecx = 0x0;
                    edx = edi + 0xc;
                    while (true) {
                            eax = *edx;
                            if ((eax & 0x1) == 0x0) {
                                    ecx = ecx + 0x1;
                                    edx = edx + 0x4;
                                    if (ecx < 0x8) {
                                            continue;
                                    }
                                    eax = *edi;
                                    esp = esp - 0x4;
                                    eax = (eax[0x11])(ebp);
                                    ebx = eax;
                                    if (ebx != 0x0) {
                                            esp = esp - 0x4;
                                            eax = (*(*edi + 0x48))(ebp);
                                            temp_0 = 0x1;
                                    }
                                    else {
                                            temp_0 = 0x1;
                                    }
                                    break;
                            }
                            if (esi == (eax >> 0x2 & 0xff)) {
                                    eax = *(edi + ecx * 0x4 + 0xc);
                                    esi = decomp_var_c;
                                    ebp = decomp_var_8;
                                    eax = eax >> 0x1 & 0x1;
                                    ebx = decomp_var_4;
                                    esp = esp + 0xc;
                                    temp_0 = 0x0;
                                    break;
                            }
                            ecx = ecx + 0x1;
                            edx = edx + 0x4;
                            if (ecx < 0x8) {
                                    continue;
                            }
                            eax = *edi;
                            esp = esp - 0x4;
                            eax = (eax[0x11])(ebp);
                            ebx = eax;
                            if (ebx != 0x0) {
                                    esp = esp - 0x4;
                                    eax = (*(*edi + 0x48))(ebp);
                                    temp_0 = 0x1;
                            }
                            else {
                                    temp_0 = 0x1;
                            }
                            break;
                    }
                    if (temp_0 != 0x0) {
                            if (arg_7 != 0x9) {
                                    ebp = ebp | 0xffffffff;
                                    eax = 0x0;
                                    ecx = edi + 0xc;
                                    while (true) {
                                            if ((*(int8_t *)ecx & 0x1) == 0x0) {
                                                    ebp = eax;
                                                    if (eax == 0xffffffff) {
                                                            temp_1 = 0x0;
                                                    }
                                                    else {
                                                            temp_1 = 0x1;
                                                    }
                                                    break;
                                            }
                                            eax = eax + 0x1;
                                            ecx = ecx + 0x4;
                                            if (eax < 0x8) {
                                                    continue;
                                            }
                                            temp_1 = 0x0;
                                            break;
                                    }
                                    if (temp_1 == 0x0) {
                                            (*(*edi + 0x40))();
                                    }
                                    *(edi + ebp * 0x4 + 0xc) = ((esi & 0xff) << 0x1 | ebx & 0x1) << 0x1 | *(edi + ebp * 0x4 + 0xc) & 0xfffffc01 | 0x1;
                            }
                            eax = ebx;
                    }
            }
    }
    else {
            eax = 0x0;
    }
    return eax;

```

## Callers (1) **F**

| Dirección | Nombre |
| --- | --- |
| `005a53c0` | `sub_5a53c0` |

## Callees (0) **F**

_Ninguno registrado en el censo._

## Globals

Identificadores tomados del pseudocódigo tal cual. Que el nombre aparezca es **F**; la separación lectura/escritura es **I** (se deduce de si el nombre cae a la izquierda del `=` de su línea). Las direcciones `0x...` van como las imprime Hopper.

### Escritos (0) **I**

_Ninguno._

### Leídos (1) **I**

- `dword_736150`

## Notas

- El pseudocódigo es el de Hopper sin tocar: los nombres `sub_*`, `var_*` y `arg_*` son suyos, no de esta extracción. **F**
- Callers/callees son las líneas `// callers:` y `// callees:` del bloque en `decomp.c`; un call indirecto no aparece ahí. **F** el listado, **I** que sea completo.
- No se corrió el juego para este documento: nada de lo de arriba está verificado en ejecución. **NV**
