# 0043ff30 · sub_43ff30

- Dirección: `0x0043ff30` (VA), nombre Hopper `sub_43ff30`.
- Fuente: `census/hopper/decomp.c`, línea 100417, bloque de 98 líneas de cuerpo. Conteos en `census/hopper/funcs.tsv`: 101 líneas, 1 callers, 3 callees. **F**
- Bug que motivó la extracción: reset/fall-through del auto (pasa paredes o se cae después de un reset). Ver `docs/re/coll_reset.md` y `docs/openworld/re_coll_pool.md`.

## Por qué está en la lista (citas de los docs)

| Doc | Línea | Texto |
| --- | --- | --- |
| `docs/openworld/re_coll_pool.md` | 38 | - 0x4407b0 -> 0x441c10 -> 0x441b90 (once per polygon returned): row +6 < 0 makes a body (0x43ff30, writes the slot |

## Pseudocódigo (tal cual, sin editar) **F**

```c
    &saved_fp = &saved_fp & 0xfffffff0;
    esp = esp - 0x3c;
    esi[0xb] = edi[0x2];
    esi[0xa] = edi[0x3];
    esi[0x8] = 0x0;
    esi[0x4] = 0x0;
    eax = edi[0x1] & 0xff;
    var_2C = sign_extend_32(*(int16_t *)(edi + (eax >> 0x2 & 0x3) * 0x2 + 0x10)) << 0xd;
    var_28 = sign_extend_32(*(int16_t *)(edi + (eax >> 0x4 & 0x3) * 0x2 + 0x8)) << 0xd;
    var_24 = sign_extend_32(*(int16_t *)(edi + (eax >> 0x6) * 0x2 + 0x10)) << 0xd;
    asm { fild       dword [esp+0x3c+var_30] };
    esp = esp - 0x4;
    decomp_var_40 = ebx;
    ebx = esi + 0x30;
    asm { fmul       dword [dword_value_931135488] };
    asm { fstp       dword [esi+0x14] };
    asm { fild       dword [esp+0x40+var_2C] };
    asm { fmul       dword [dword_value_931135488] };
    asm { fstp       dword [esi+0x18] };
    asm { fild       dword [esp+0x40+var_28] };
    asm { fmul       dword [dword_value_931135488] };
    asm { fstp       dword [esi+0x1c] };
    asm { fild       dword [esp+0x40+var_24] };
    asm { fmul       dword [dword_value_931135488] };
    asm { fstp       dword [esi+0x20] };
    sub_43fd20();
    eax = esi[0xa];
    esi[0x9] = 0x4;
    if ((eax & 0x10) == 0x0) {
            esi[0x9] = 0x3;
    }
    if ((eax & 0x4) != 0x0) {
            asm { fld        dword [esi+0x38] };
            asm { fmul       dword [dword_value_1031798784+8] };
            asm { fstp       dword [esi+0x38] };
            asm { fld        dword [esi+0x48] };
            asm { fmul       dword [dword_value_1031798784+8] };
            asm { fstp       dword [esi+0x48] };
            asm { fld        dword [esi+0x58] };
            asm { fmul       dword [dword_value_1031798784+8] };
            asm { fstp       dword [esi+0x58] };
            asm { fld        dword [esi+0x68] };
            asm { fmul       dword [dword_value_1031798784+8] };
            asm { fstp       dword [esi+0x68] };
    }
    asm { fld        dword [esi+0x40] };
    asm { fsub       dword [ebx] };
    asm { fld        dword [esi+0x44] };
    asm { fsub       dword [ebx+4] };
    asm { fld        dword [esi+0x48] };
    asm { fsub       dword [ebx+8] };
    asm { fld        dword [esi+0x50] };
    asm { fsub       dword [ebx] };
    asm { fstp       dword [esp+0x40+var_10] };
    asm { fld        dword [esi+0x54] };
    asm { fsub       dword [ebx+4] };
    asm { fstp       dword [esp+0x40+var_C] };
    asm { fld        dword [esi+0x58] };
    asm { fsub       dword [ebx+8] };
    asm { fld        st0 };
    asm { fmul       st3 };
    asm { fld        dword [esp+0x40+var_C] };
    asm { fmul       st3 };
    asm { fsubp      st1 };
    asm { fstp       dword [esp+0x40+var_20] };
    asm { fxch       st0, st1 };
    asm { fmul       dword [esp+0x40+var_10] };
    asm { fxch       st0, st1 };
    asm { fmul       st3 };
    asm { fsubp      st1 };
    asm { fstp       dword [esp+0x40+var_1C] };
    asm { fld        dword [esp+0x40+var_C] };
    asm { fmul       st2 };
    asm { fxch       st0, st1 };
    asm { fmul       dword [esp+0x40+var_10] };
    asm { fsubp      st1 };
    asm { fstp       dword [esp+0x40+var_18] };
    asm { fstp       st0 };
    sub_567370();
    esi[0x1d] = var_1C;
    esi[0x1c] = var_20;
    esi[0x1e] = var_18;
    asm { fld        dword [ebx+8] };
    asm { fmul       dword [esi+0x78] };
    decomp_var_44 = esi;
    asm { fld        dword [ebx+4] };
    asm { fmul       dword [esi+0x74] };
    asm { faddp      st1 };
    asm { fld        dword [ebx] };
    asm { fmul       dword [esi+0x70] };
    asm { faddp      st1 };
    asm { fstp       dword [esi+0x7c] };
    edi[0x3] = sub_566ed0(decomp_var_44);
    esi[0x3] = edi;
    eax = esi;
    &decomp_var_3c = ebp;
    return eax;

```

## Callers (1) **F**

| Dirección | Nombre |
| --- | --- |
| `00441b90` | `sub_441b90` |

## Callees (3) **F**

| Dirección | Nombre |
| --- | --- |
| `0043fd20` | `sub_43fd20` |
| `00566ed0` | `sub_566ed0` |
| `00567370` | `sub_567370` |

## Globals

Identificadores tomados del pseudocódigo tal cual. Que el nombre aparezca es **F**; la separación lectura/escritura es **I** (se deduce de si el nombre cae a la izquierda del `=` de su línea). Las direcciones `0x...` van como las imprime Hopper.

### Escritos (0) **I**

_Ninguno._

### Leídos (0) **I**

_Ninguno._

### Constantes del binario (`*_value_*`, solo lectura) **F**

- `dword_value_931135488` (0x37800000)
- `dword_value_1031798784` (0x3d800000)

## Notas

- El pseudocódigo es el de Hopper sin tocar: los nombres `sub_*`, `var_*` y `arg_*` son suyos, no de esta extracción. **F**
- Callers/callees son las líneas `// callers:` y `// callees:` del bloque en `decomp.c`; un call indirecto no aparece ahí. **F** el listado, **I** que sea completo.
- No se corrió el juego para este documento: nada de lo de arriba está verificado en ejecución. **NV**
