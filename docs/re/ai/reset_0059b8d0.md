# 0059b8d0 · sub_59b8d0

- Dirección: `0x0059b8d0` (VA), nombre Hopper `sub_59b8d0`.
- Fuente: `census/hopper/decomp.c`, línea 846161, bloque de 55 líneas de cuerpo. Conteos en `census/hopper/funcs.tsv`: 58 líneas, 1 callers, 8 callees. **F**
- Bug que motivó la extracción: reset/fall-through del auto (pasa paredes o se cae después de un reset). Ver `docs/re/coll_reset.md` y `docs/openworld/re_coll_pool.md`.

## Por qué está en la lista (citas de los docs)

| Doc | Línea | Texto |
| --- | --- | --- |
| `docs/openworld/re_coll_pool.md` | 52 | Thread c, int3 0x441b82 in 0x441b20, stack AcquireBody 0x441b90 <- QueryBox <- RefillCache <- traffic teleport (0x59b8d0 / 0x458bd0): a ground query for a traffic car found no body of count 0. |

## Pseudocódigo (tal cual, sin editar) **F**

```c
    var_4 = 0x0;
    var_8 = 0x0;
    while (true) {
            if (var_8 >= sub_41f680()) {
                    eax = 0x0;
                    break;
            }
            var_C = sub_41f690();
            eax = sub_424e10();
            asm { fcomp      dword [dword_value_1140457472+48] };
            asm { fnstsw     ax };
            if (PARITY(HIBYTE(eax) & 0x5)) {
                    var_8 = var_8 + 0x1;
                    continue;
            }
            var_D = 0x0;
            if ((sub_424da0() & 0xff) != 0x0) {
                    var_D = *(int8_t *)(sub_41f5d0() + 0x4d1);
            }
            ecx = var_D & 0xff;
            if (ecx != 0x0) {
                    var_8 = var_8 + 0x1;
                    continue;
            }
            sub_41f5f0();
            esp = esp - 0x4;
            var_18 = ecx;
            asm { fstp       dword [esp+0x18+var_18] };
            sub_41f5f0();
            esp = esp - 0x4;
            var_1C = ecx;
            asm { fstp       dword [esp+0x1c+var_1C] };
            sub_443d60(var_1C, var_18);
            esp = esp - 0x4;
            var_18 = ecx;
            asm { fstp       dword [esp+0x18+var_18] };
            eax = sub_405600(var_18);
            esp = esp + 0x4;
            asm { fcomp      dword [dword_value_1056964608+64] };
            asm { fnstsw     ax };
            if (PARITY(HIBYTE(eax) & 0x5)) {
                    var_8 = var_8 + 0x1;
                    continue;
            }
            var_4 = var_4 + 0x1;
            if (var_4 < 0x1) {
                    var_8 = var_8 + 0x1;
                    continue;
            }
            eax = 0x1;
            break;
    }
    &decomp_var_10 = ebp;
    return eax;

```

## Callers (1) **F**

| Dirección | Nombre |
| --- | --- |
| `0059b3e0` | `sub_59b3e0` |

## Callees (8) **F**

| Dirección | Nombre |
| --- | --- |
| `00405600` | `sub_405600` |
| `0041f5d0` | `sub_41f5d0` |
| `0041f5f0` | `sub_41f5f0` |
| `0041f680` | `sub_41f680` |
| `0041f690` | `sub_41f690` |
| `00424da0` | `sub_424da0` |
| `00424e10` | `sub_424e10` |
| `00443d60` | `sub_443d60` |

## Globals

Identificadores tomados del pseudocódigo tal cual. Que el nombre aparezca es **F**; la separación lectura/escritura es **I** (se deduce de si el nombre cae a la izquierda del `=` de su línea). Las direcciones `0x...` van como las imprime Hopper.

### Escritos (0) **I**

_Ninguno._

### Leídos (0) **I**

_Ninguno._

### Constantes del binario (`*_value_*`, solo lectura) **F**

- `dword_value_1140457472` (0x43fa0000)
- `dword_value_1056964608` (0x3f000000)

## Notas

- El pseudocódigo es el de Hopper sin tocar: los nombres `sub_*`, `var_*` y `arg_*` son suyos, no de esta extracción. **F**
- Callers/callees son las líneas `// callers:` y `// callees:` del bloque en `decomp.c`; un call indirecto no aparece ahí. **F** el listado, **I** que sea completo.
- No se corrió el juego para este documento: nada de lo de arriba está verificado en ejecución. **NV**
