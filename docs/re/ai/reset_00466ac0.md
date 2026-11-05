# 00466ac0 · sub_466ac0

- Dirección: `0x00466ac0` (VA), nombre Hopper `sub_466ac0`.
- Fuente: `census/hopper/decomp.c`, línea 171651, bloque de 70 líneas de cuerpo. Conteos en `census/hopper/funcs.tsv`: 73 líneas, 0 callers, 2 callees. **F**
- Bug que motivó la extracción: reset/fall-through del auto (pasa paredes o se cae después de un reset). Ver `docs/re/coll_reset.md` y `docs/openworld/re_coll_pool.md`.

## Por qué está en la lista (citas de los docs)

| Doc | Línea | Texto |
| --- | --- | --- |
| `docs/re/coll_reset.md` | 30 | - Pool A (0x736184) cannot produce a silent fall-through: it halts. The id table (0x466b01, ids 0xde -> 0x840) |

## Pseudocódigo (tal cual, sin editar) **F**

```c
    if (!CPU_FLAGS & B) {
            eax = sub_566dc0(saved_fp, arg_0, arg_4);
            esp = esp + 0xc;
            if (eax != 0x0 && *dword_73d814 == esi) {
                    ecx = *dword_73d81c;
                    *ecx = eax;
                    *dword_73d81c = eax;
                    eax[0x1] = ecx;
                    *eax = dword_73d818;
            }
            *dword_72cc08 = eax;
            esi = sub_67121a(0xc);
            esp = (esp - 0x4) + 0x4;
            bool_7 = true;
            bool_6 = true;
            bool_5 = true;
            bool_4 = true;
            bool_3 = true;
            bool_2 = true;
            if (esi != 0x0) {
                    esi[0x1] = 0x0;
                    esi[0x2] = 0x0;
                    *esi = 0xde;
                    edi = sub_67121a(0x1b);
                    esp = (esp - 0x4) + 0x4;
                    esi[0x1] = edi;
                    eax = 0x0;
                    asm { rep stosd  dword [edi], eax };
                    asm { stosw      word [edi], ax };
                    asm { stosb      byte [edi], al };
                    esi[0x2] = 0x0;
            }
            else {
                    esi = 0x0;
            }
            esp = esp - 0x4;
            *dword_736070 = esi;
            edi = sub_67121a(0x378);
            eax = 0x0;
            *dword_736050 = edi;
            asm { rep stosd  dword [edi], eax };
            esp = esp - 0x4;
            arg_0 = 0x1810;
            *dword_779bf0 = 0x3f800000;
            *dword_779bf4 = eax;
            *dword_779bf8 = eax;
            *dword_779bfc = eax;
            *dword_779c00 = eax;
            *dword_779c04 = 0x3f800000;
            *dword_779c08 = eax;
            *dword_779c0c = eax;
            *dword_779c10 = eax;
            *dword_779c14 = eax;
            *dword_779c18 = 0x3f800000;
            *dword_779c1c = eax;
            *dword_779c20 = eax;
            *dword_779c24 = eax;
            *dword_779c28 = eax;
            *dword_779c2c = 0x3f800000;
            asm { rep stosd  dword [edi], eax };
            edi = sub_67121a(arg_0);
            *dword_72cbfc = edi;
            eax = 0x0;
            asm { rep stosd  dword [edi], eax };
    }
    else {
            eax = (null)();
    }
    return eax;

```

## Callers (0) **F**

_Ninguno registrado en el censo._

## Callees (2) **F**

| Dirección | Nombre |
| --- | --- |
| `00566dc0` | `sub_566dc0` |
| `0067121a` | `sub_67121a` |

## Globals

Identificadores tomados del pseudocódigo tal cual. Que el nombre aparezca es **F**; la separación lectura/escritura es **I** (se deduce de si el nombre cae a la izquierda del `=` de su línea). Las direcciones `0x...` van como las imprime Hopper.

### Escritos (21) **I**

- `dword_73d81c`
- `dword_72cc08`
- `dword_736070`
- `dword_736050`
- `dword_779bf0`
- `dword_779bf4`
- `dword_779bf8`
- `dword_779bfc`
- `dword_779c00`
- `dword_779c04`
- `dword_779c08`
- `dword_779c0c`
- `dword_779c10`
- `dword_779c14`
- `dword_779c18`
- `dword_779c1c`
- `dword_779c20`
- `dword_779c24`
- `dword_779c28`
- `dword_779c2c`
- `dword_72cbfc`

### Leídos (3) **I**

- `dword_73d814`
- `dword_73d81c`
- `dword_73d818`

## Notas

- El pseudocódigo es el de Hopper sin tocar: los nombres `sub_*`, `var_*` y `arg_*` son suyos, no de esta extracción. **F**
- Callers/callees son las líneas `// callers:` y `// callees:` del bloque en `decomp.c`; un call indirecto no aparece ahí. **F** el listado, **I** que sea completo.
- No se corrió el juego para este documento: nada de lo de arriba está verificado en ejecución. **NV**
