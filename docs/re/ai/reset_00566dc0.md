# 00566dc0 · sub_566dc0

- Dirección: `0x00566dc0` (VA), nombre Hopper `sub_566dc0`.
- Fuente: `census/hopper/decomp.c`, línea 713255, bloque de 23 líneas de cuerpo. Conteos en `census/hopper/funcs.tsv`: 26 líneas, 33 callers, 2 callees. **F**
- Bug que motivó la extracción: reset/fall-through del auto (pasa paredes o se cae después de un reset). Ver `docs/re/coll_reset.md` y `docs/openworld/re_coll_pool.md`.

## Por qué está en la lista (citas de los docs)

| Doc | Línea | Texto |
| --- | --- | --- |
| `docs/openworld/re_coll_pool.md` | 24 | pool (0x441ba7); 0x566dc0 builds the free list from edi; save 0x46a6e0 writes row indices, not slot indices; |

## Pseudocódigo (tal cual, sin editar) **F**

```c
    decomp_var_4 = ebx;
    ebx = arg_8;
    decomp_var_8 = ebp;
    ebp = arg_0;
    decomp_var_c = esi;
    esi = sub_565b60(ebp * edi + 0x30, 0x0, 0x0, ebx);
    esp = (esp - 0x1c) + 0x10;
    if (esi != 0x0) {
            esi[0x9] = edi;
            esi[0xa] = ebp;
            esi[0x5] = 0xb;
            esi[0x4] = 0x0;
            esi[0x2] = 0x0;
            esi[0x8] = ebx;
            esi[0x3] = arg_4;
            esi[0xb] = edi;
            esi[0x6] = 0x0;
            esi[0x7] = 0x0;
            sub_566e20();
    }
    eax = esi;
    return eax;

```

## Callers (33) **F**

| Dirección | Nombre |
| --- | --- |
| `00402720` | `sub_402720` |
| `00408830` | `sub_408830` |
| `0040c600` | `sub_40c600` |
| `0040f2e0` | `sub_40f2e0` |
| `00410780` | `sub_410780` |
| `00421c70` | `sub_421c70` |
| `004412b0` | `sub_4412b0` |
| `00447f40` | `sub_447f40` |
| `00455530` | `sub_455530` |
| `004655f0` | `sub_4655f0` |
| `00466970` | `sub_466970` |
| `00466ac0` | `sub_466ac0` |
| `0046ac40` | `sub_46ac40` |
| `004764e0` | `sub_4764e0` |
| `004a5ca0` | `sub_4a5ca0` |
| `004ad2d0` | `sub_4ad2d0` |
| `00514480` | `sub_514480` |
| `00532a20` | `sub_532a20` |
| `0053e020` | `sub_53e020` |
| `0053f690` | `sub_53f690` |
| `005649f0` | `sub_5649f0` |
| `00566e60` | `sub_566e60` |
| `005697b0` | `sub_5697b0` |
| `00576f80` | `sub_576f80` |
| `00579430` | `sub_579430` |
| `00589ba0` | `sub_589ba0` |
| `0058a000` | `sub_58a000` |
| `0058ab50` | `sub_58ab50` |
| `0058b110` | `sub_58b110` |
| `0058dd50` | `sub_58dd50` |
| `00591d90` | `sub_591d90` |
| `00593880` | `sub_593880` |
| `00594b70` | `sub_594b70` |

## Callees (2) **F**

| Dirección | Nombre |
| --- | --- |
| `00565b60` | `sub_565b60` |
| `00566e20` | `sub_566e20` |

## Globals

Identificadores tomados del pseudocódigo tal cual. Que el nombre aparezca es **F**; la separación lectura/escritura es **I** (se deduce de si el nombre cae a la izquierda del `=` de su línea). Las direcciones `0x...` van como las imprime Hopper.

### Escritos (0) **I**

_Ninguno._

### Leídos (0) **I**

_Ninguno._

## Notas

- El pseudocódigo es el de Hopper sin tocar: los nombres `sub_*`, `var_*` y `arg_*` son suyos, no de esta extracción. **F**
- Callers/callees son las líneas `// callers:` y `// callees:` del bloque en `decomp.c`; un call indirecto no aparece ahí. **F** el listado, **I** que sea completo.
- No se corrió el juego para este documento: nada de lo de arriba está verificado en ejecución. **NV**
