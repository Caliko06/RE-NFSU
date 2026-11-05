# 0042bb60 · sub_42bb60

- Dirección: `0x0042bb60` (VA), nombre Hopper `sub_42bb60`.
- Fuente: `census/hopper/decomp.c`, línea 66377, bloque de 100 líneas de cuerpo. Conteos en `census/hopper/funcs.tsv`: 103 líneas, 1 callers, 9 callees. **F**
- Bug que motivó la extracción: reset/fall-through del auto (pasa paredes o se cae después de un reset). Ver `docs/re/coll_reset.md` y `docs/openworld/re_coll_pool.md`.

## Por qué está en la lista (citas de los docs)

| Doc | Línea | Texto |
| --- | --- | --- |
| `docs/openworld/re_coll_pool.md` | 10 | and 0x42bb60 (Player, cache +0x5d0). So an owner that stays alive and does not move out of its box pins its |

## Pseudocódigo (tal cual, sin editar) **F**

```c
    var_C = *0x0;
    *0x0 = &var_C;
    decomp_var_14 = esi;
    esi = arg_0;
    esp = esp - 0x1c;
    sub_42ed40(0x0, 0x0);
    ecx = esi[0x257];
    if (ecx != 0x0) {
            esp = esp - 0x4;
            (**ecx)(0x1);
    }
    esp = esp - 0x4;
    decomp_var_18 = edi;
    edi = esi[0x24];
    if (edi != 0x0) {
            if (*edi != 0x0) {
                    loc_565ce0();
            }
            sub_671102();
            esp = (esp - 0x4) + 0x4;
    }
    eax = esi[0x157];
    if (eax != 0x0) {
            sub_671102();
            esp = (esp - 0x4) + 0x4;
    }
    eax = esi[0x170];
    if (eax != 0x0) {
            eax = sub_671102();
            esp = (esp - 0x4) + 0x4;
    }
    ecx = esi[0x171];
    if (ecx != 0x0) {
            esp = esp - 0x4;
            eax = (**ecx)(0x1);
    }
    edi = esi[0xa6];
    esi[0x171] = 0x0;
    esi[0x172] = eax | 0xffffffff;
    esi[0x173] = eax | 0xffffffff;
    if (edi != 0x0) {
            sub_42b040(edi);
            sub_671102();
            esp = (esp - 0x8) + 0x4;
            esi[0xa6] = 0x0;
    }
    edi = esi[0xaa];
    if (edi != 0x0) {
            sub_58d0d0(edi);
            sub_671102();
            esp = (esp - 0x8) + 0x4;
    }
    ecx = esi[0x2a];
    if (ecx != 0x0) {
            esp = esp - 0x4;
            (**ecx)(0x1);
    }
    eax = *dword_7361c4;
    esi[0x151] = 0x0;
    esi[0x152] = 0x0;
    *dword_7361c4 = eax - 0x1;
    *((eax - 0x1) * 0x4 + dword_7361bc) = 0x0;
    *(esi[0x4] * 0x4 + dword_7361b4) = 0x0;
    *(int8_t *)byte_7183b4 = 0x1;
    sub_671102();
    sub_671102();
    edi = esi[0x4c];
    esp = (esp - 0x8) + 0x8;
    if (edi != 0x0) {
            sub_490730();
            eax = edi[0x3];
            if (eax != 0x0) {
                    sub_672188();
                    sub_671102();
                    esp = (esp - 0x14) + 0x4;
            }
            sub_671102();
            esp = (esp - 0x4) + 0x4;
    }
    sub_671102();
    sub_43dd10();
    sub_4368e0();
    sub_671102();
    sub_671102();
    eax = esi[0x21c];
    esp = ((esp - 0x4) + 0x4 - 0x8) + 0xc;
    if (eax > 0x0) {
            ecx = esi + 0x5f0;
            edx = eax;
            do {
                    eax = *ecx;
                    eax[0x8] = eax[0x8] - 0x1;
                    ecx = ecx + 0x4;
                    edx = edx - 0x1;
            } while (edx != 0x0);
    }
    *0x0 = var_C;
    &var_10 = ebp;
    return eax;

```

## Callers (1) **F**

| Dirección | Nombre |
| --- | --- |
| `00422130` | `sub_422130` |

## Callees (9) **F**

| Dirección | Nombre |
| --- | --- |
| `0042b040` | `sub_42b040` |
| `0042ed40` | `sub_42ed40` |
| `004368e0` | `sub_4368e0` |
| `0043dd10` | `sub_43dd10` |
| `00490730` | `sub_490730` |
| `00565ce0` | `sub_565ce0` |
| `0058d0d0` | `sub_58d0d0` |
| `00671102` | `sub_671102` |
| `00672188` | `sub_672188` |

## Globals

Identificadores tomados del pseudocódigo tal cual. Que el nombre aparezca es **F**; la separación lectura/escritura es **I** (se deduce de si el nombre cae a la izquierda del `=` de su línea). Las direcciones `0x...` van como las imprime Hopper.

### Escritos (4) **I**

- `dword_7361c4`
- `dword_7361bc`
- `dword_7361b4`
- `byte_7183b4`

### Leídos (1) **I**

- `dword_7361c4`

## Notas

- El pseudocódigo es el de Hopper sin tocar: los nombres `sub_*`, `var_*` y `arg_*` son suyos, no de esta extracción. **F**
- Callers/callees son las líneas `// callers:` y `// callees:` del bloque en `decomp.c`; un call indirecto no aparece ahí. **F** el listado, **I** que sea completo.
- No se corrió el juego para este documento: nada de lo de arriba está verificado en ejecución. **NV**
