// ==== 0x5b100b FUN_005b100b

void FUN_005b100b(void)

{
  FUN_005b0f1d(&stack0x00000004,&stack0x00000008,&stack0x0000000c);
  return;
}


// ==== 0x5b1022 FUN_005b1022

int FUN_005b1022(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  
  piVar2 = param_1;
  piVar1 = (int *)*param_1;
  iVar6 = piVar1[1];
  iVar4 = *piVar1;
  iVar8 = piVar1[4];
  iVar3 = 0;
  if (iVar8 == 0) {
    iVar8 = 1;
  }
  if (-1 < iVar6) {
    if (iVar6 < 4) {
      uVar5 = piVar1[6] * piVar1[5] * iVar8;
      if (((iVar4 == 1) || (iVar4 == 2)) || (iVar4 == 3)) {
        iVar6 = uVar5 * 4;
        puVar7 = (undefined4 *)*param_3;
        puVar9 = (undefined4 *)*param_2;
        for (uVar5 = uVar5 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar9 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar9 = puVar9 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
        *param_2 = *param_2 + iVar6;
        *param_3 = *param_3 + iVar6;
        *param_1 = *param_1 + 0x1c;
        return 0;
      }
    }
    else if (iVar6 == 4) {
      switch(iVar4) {
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 0xf:
      case 0x10:
        *param_2 = *param_2 + iVar8 * 4;
        *param_3 = *param_3 + iVar8 * 4;
      case 10:
      case 0xb:
      case 0xc:
      case 0xd:
      case 0xe:
      case 0x11:
      case 0x12:
        *param_1 = *param_1 + 0x14;
        return 0;
      }
    }
    else if (iVar6 == 5) {
      uVar5 = piVar1[5];
      *param_1 = (int)(piVar1 + 6);
      do {
        if (iVar8 == 0) {
          return iVar3;
        }
        param_1 = (int *)0x0;
        *piVar2 = (int)(piVar1 + 6);
        if (uVar5 != 0) {
          do {
            iVar3 = FUN_005b1022(piVar2,param_2,param_3);
            if (iVar3 < 0) {
              return iVar3;
            }
            param_1 = (int *)((int)param_1 + 1);
          } while (param_1 < uVar5);
        }
        iVar8 = iVar8 + -1;
      } while( true );
    }
  }
  return -0x7fffbffb;
}


// ==== 0x5b1130 FUN_005b1130

void FUN_005b1130(void)

{
  FUN_005b1022(&stack0x00000004,&stack0x00000008,&stack0x0000000c);
  return;
}


// ==== 0x5b1147 FUN_005b1147

int FUN_005b1147(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  uint local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  piVar1 = (int *)*param_1;
  local_8 = piVar1[4];
  iVar4 = piVar1[1];
  iVar5 = *piVar1;
  if (local_8 == 0) {
    local_8 = 1;
  }
  if (-1 < iVar4) {
    if (iVar4 < 4) {
      if (((iVar5 != 1) && (iVar5 != 2)) && (iVar5 != 3)) {
        return -0x7fffbffb;
      }
      *param_2 = *param_2 + piVar1[6] * piVar1[5] * local_8 * 4;
      *param_1 = *param_1 + 0x1c;
      return 0;
    }
    if (iVar4 != 4) {
      if (iVar4 != 5) {
        return -0x7fffbffb;
      }
      uVar2 = piVar1[5];
      *param_1 = (int)(piVar1 + 6);
      do {
        if (local_8 == 0) {
          return local_c;
        }
        local_10 = 0;
        *param_1 = (int)(piVar1 + 6);
        if (uVar2 != 0) {
          do {
            local_c = FUN_005b1147(param_1,param_2,param_3,param_4);
            if (local_c < 0) {
              return local_c;
            }
            local_10 = local_10 + 1;
          } while (local_10 < uVar2);
        }
        local_8 = local_8 + -1;
      } while( true );
    }
    if (iVar5 < 0x10) {
      if (iVar5 == 0xf) {
        for (; local_8 != 0; local_8 = local_8 + -1) {
          iVar4 = *(int *)(*(int *)*param_2 * 4 + param_4[2]) * 0x1c + *(int *)(*param_4 + 0x24);
          iVar5 = *(int *)(*(int *)*param_2 * 4 + param_3[2]) * 0x1c + *(int *)(*param_3 + 0x24);
          piVar1 = *(int **)(iVar5 + 4);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 4))(piVar1);
          }
          piVar1 = *(int **)(iVar5 + 0x10);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 4))(piVar1);
          }
          piVar1 = *(int **)(iVar4 + 4);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
            *(undefined4 *)(iVar4 + 4) = 0;
          }
          piVar1 = *(int **)(iVar4 + 0x10);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
            *(undefined4 *)(iVar4 + 0x10) = 0;
          }
          *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar5 + 4);
          *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(iVar5 + 0x10);
          *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar5 + 0xc);
          uVar3 = *(undefined4 *)(iVar5 + 0x14);
          *(undefined4 *)(iVar4 + 0x14) = uVar3;
          local_c = FUN_005ccec4(*(undefined4 *)(iVar4 + 0x18),uVar3,0);
          if (local_c < 0) {
            return local_c;
          }
          *param_2 = *param_2 + 4;
        }
        goto LAB_005b145e;
      }
      if (iVar5 == 4) {
        for (; local_8 != 0; local_8 = local_8 + -1) {
          iVar4 = *(int *)(*(int *)*param_2 * 4 + param_4[2]) * 0x1c + *(int *)(*param_4 + 0x24);
          iVar5 = *(int *)(*(int *)*param_2 * 4 + param_3[2]) * 0x1c + *(int *)(*param_3 + 0x24);
          piVar1 = *(int **)(iVar5 + 4);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 4))(piVar1);
          }
          piVar1 = *(int **)(iVar4 + 4);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
            *(undefined4 *)(iVar4 + 4) = 0;
          }
          *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar5 + 4);
          *param_2 = *param_2 + 4;
        }
        goto LAB_005b145e;
      }
      if (iVar5 < 5) {
        return -0x7fffbffb;
      }
      if (iVar5 < 10) {
        for (; local_8 != 0; local_8 = local_8 + -1) {
          iVar4 = *(int *)(*(int *)*param_2 * 4 + param_4[2]) * 0x1c + *(int *)(*param_4 + 0x24);
          iVar5 = *(int *)(*(int *)*param_2 * 4 + param_3[2]) * 0x1c + *(int *)(*param_3 + 0x24);
          piVar1 = *(int **)(iVar5 + 4);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 4))(piVar1);
          }
          piVar1 = *(int **)(iVar4 + 4);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
            *(undefined4 *)(iVar4 + 4) = 0;
          }
          *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar5 + 4);
          *param_2 = *param_2 + 4;
        }
        goto LAB_005b145e;
      }
      bVar7 = SBORROW4(iVar5,0xe);
      iVar4 = -0xe;
      bVar6 = iVar5 == 0xe;
    }
    else {
      if (iVar5 == 0x10) {
        for (; local_8 != 0; local_8 = local_8 + -1) {
          iVar4 = *(int *)(*(int *)*param_2 * 4 + param_4[2]) * 0x1c + *(int *)(*param_4 + 0x24);
          iVar5 = *(int *)(*(int *)*param_2 * 4 + param_3[2]) * 0x1c + *(int *)(*param_3 + 0x24);
          piVar1 = *(int **)(iVar5 + 4);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 4))(piVar1);
          }
          piVar1 = *(int **)(iVar5 + 0x10);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 4))(piVar1);
          }
          piVar1 = *(int **)(iVar4 + 4);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
            *(undefined4 *)(iVar4 + 4) = 0;
          }
          piVar1 = *(int **)(iVar4 + 0x10);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
            *(undefined4 *)(iVar4 + 0x10) = 0;
          }
          *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar5 + 4);
          *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(iVar5 + 0x10);
          *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar5 + 0xc);
          uVar3 = *(undefined4 *)(iVar5 + 0x14);
          *(undefined4 *)(iVar4 + 0x14) = uVar3;
          local_c = FUN_005ccec4(*(undefined4 *)(iVar4 + 0x18),uVar3,0);
          if (local_c < 0) {
            return local_c;
          }
          *param_2 = *param_2 + 4;
        }
        goto LAB_005b145e;
      }
      if (iVar5 < 0x11) {
        return -0x7fffbffb;
      }
      bVar7 = SBORROW4(iVar5,0x12);
      iVar4 = -0x12;
      bVar6 = iVar5 == 0x12;
    }
    if (bVar6 || bVar7 != iVar5 + iVar4 < 0) {
LAB_005b145e:
      *param_1 = *param_1 + 0x14;
      return local_c;
    }
  }
  return -0x7fffbffb;
}


// ==== 0x5b148d FUN_005b148d

undefined4 FUN_005b148d(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  undefined4 uVar1;
  
  if ((param_3 == param_4) || (*param_3 == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_005b1147(&param_1,&param_2,param_4,param_3);
  }
  return uVar1;
}


// ==== 0x5b14b6 FUN_005b14b6

int __thiscall FUN_005b14b6(int param_1,int param_2,int param_3)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *_Size;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  int local_20;
  undefined4 *local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar8 = *(int *)(param_3 + 0x24) + *(int *)(param_2 + 0x2c);
  local_14 = *(int *)(param_3 + 0x28) + *(int *)(param_2 + 0x2c);
  local_18 = iVar8;
  for (piVar3 = *(int **)(param_1 + 0x10); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[8]) {
    iVar1 = FUN_005b09cb(*(undefined4 *)(param_2 + 0x2c),iVar8,*(int *)(param_1 + 8),
                         *piVar3 + *(int *)(param_1 + 8),&local_10);
    if (-1 < iVar1) {
      if (((local_10 != 0) && (*(int *)piVar3[7] != 0)) &&
         (*(int *)(param_2 + 8) != *(int *)(*(int *)piVar3[7] + 8))) {
        return -0x7fffbffb;
      }
      if ((piVar3 + 3 == (int *)piVar3[7]) &&
         (local_8 = FUN_005b1130(iVar8,piVar3[1] + *(int *)(param_1 + 8),local_14), local_8 < 0)) {
        return local_8;
      }
      goto LAB_005b1667;
    }
  }
  local_8 = iVar8;
  local_8 = FUN_005b0a97(*(undefined4 *)(param_2 + 0x2c),&local_8,&local_10,&local_1c,&local_c);
  if (local_8 < 0) {
    return local_8;
  }
  _Size = (undefined1 *)((int)local_1c + local_c + *(int *)(param_1 + 0xc) + local_10);
  local_1c = _malloc((size_t)_Size);
  if (local_1c == (undefined4 *)0x0) {
    return -0x7ff8fff2;
  }
  puVar7 = local_1c;
  for (uVar5 = (uint)_Size >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  for (uVar5 = (uint)_Size & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined1 *)puVar7 = 0;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  uVar5 = *(uint *)(param_1 + 0xc);
  if (uVar5 != 0) {
    puVar7 = *(undefined4 **)(param_1 + 8);
    puVar9 = local_1c;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
  }
  if (*(void **)(param_1 + 8) != (void *)0x0) {
    _free(*(void **)(param_1 + 8));
    *(undefined4 *)(param_1 + 8) = 0;
  }
  *(undefined4 **)(param_1 + 8) = local_1c;
  local_8 = FUN_005b0eda(*(undefined4 *)(param_2 + 0x2c),local_18,local_14,local_1c,
                         *(undefined4 *)(param_1 + 0xc),local_c,local_10,&local_20);
  if (local_8 < 0) {
    return local_8;
  }
  pvVar2 = _malloc(0x24);
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_005b079c();
  }
  if (piVar3 == (int *)0x0) {
    return -0x7ff8fff2;
  }
  *piVar3 = *(int *)(param_1 + 0xc) + local_c;
  piVar3[1] = *(int *)(param_1 + 0xc) + local_10 + local_c;
  piVar3[2] = local_20;
  piVar3[8] = *(int *)(param_1 + 0x10);
  *(int **)(param_1 + 0x10) = piVar3;
  *(undefined1 **)(param_1 + 0xc) = _Size;
LAB_005b1667:
  piVar4 = _malloc(0x14);
  piVar10 = (int *)0x0;
  if (piVar4 != (int *)0x0) {
    piVar4[2] = 0;
    *piVar4 = 0;
    piVar4[4] = (int)piVar4;
    piVar4[3] = (int)piVar4;
    piVar10 = piVar4;
  }
  if (piVar10 == (int *)0x0) {
    return -0x7ff8fff2;
  }
  if (piVar3[2] != 0) {
    pvVar2 = _malloc(piVar3[2] << 2);
    piVar10[2] = (int)pvVar2;
    if (pvVar2 == (void *)0x0) {
      local_8 = -0x7ff8fff2;
      goto LAB_005b1708;
    }
    local_8 = FUN_005b100b(local_18,local_14,pvVar2);
    if (local_8 < 0) goto LAB_005b1708;
  }
  *piVar10 = param_2;
  piVar10[1] = param_3;
  *(int **)(piVar3[7] + 0xc) = piVar10;
  piVar10[3] = (int)(piVar3 + 3);
  piVar10[4] = piVar3[7];
  piVar3[7] = (int)piVar10;
  *(int **)(param_3 + 0x38) = piVar10;
  *(int *)(param_3 + 0x24) = *piVar3;
  iVar8 = piVar3[1];
  *(int *)(param_3 + 0x28) = iVar8;
  piVar10 = (int *)0x0;
  local_8 = FUN_005b148d(*(int *)(param_3 + 0x24) + *(int *)(param_1 + 8),
                         iVar8 + *(int *)(param_1 + 8),*(undefined4 *)(param_3 + 0x38),piVar3[6]);
LAB_005b1708:
  if (piVar10 != (int *)0x0) {
    FUN_005b09ec(1);
    return local_8;
  }
  return local_8;
}


// ==== 0x5b171f FUN_005b171f

void __fastcall FUN_005b171f(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006994e8;
  param_1[1] = 1;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  return;
}


// ==== 0x5b173a FUN_005b173a

undefined4 FUN_005b173a(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(param_1 + 4);
  *piVar1 = *piVar1 + -1;
  uVar2 = *(undefined4 *)(param_1 + 4);
  if (*piVar1 == 0) {
    FUN_005b0a37(1);
    uVar2 = 0;
  }
  return uVar2;
}


// ==== 0x5b1752 FUN_005b1752

void __fastcall FUN_005b1752(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}


// ==== 0x5b1758 FUN_005b1758

void __fastcall FUN_005b1758(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  while (iVar1 != 0) {
    iVar1 = *(int *)*param_1;
    _free((int *)*param_1);
    *param_1 = iVar1;
  }
  return;
}


// ==== 0x5b1775 FUN_005b1775

undefined4 * __thiscall FUN_005b1775(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = _malloc(param_2 + 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_1;
    *param_1 = puVar1;
    puVar1 = puVar1 + 1;
  }
  return puVar1;
}


// ==== 0x5b1797 FUN_005b1797

void __fastcall FUN_005b1797(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 1;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  return;
}


// ==== 0x5b17b7 FUN_005b17b7

void __fastcall FUN_005b17b7(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  while (iVar1 != 0) {
    iVar1 = *(int *)*param_1;
    _free((int *)*param_1);
    *param_1 = iVar1;
  }
  _free((void *)param_1[6]);
  _free((void *)param_1[7]);
  return;
}


// ==== 0x5b17e6 FUN_005b17e6

undefined4 __thiscall FUN_005b17e6(int param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 local_10;
  uint local_8;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  uVar8 = 0;
  local_8 = uVar1 >> 1;
  local_10 = 0;
  uVar4 = uVar1;
  if (uVar1 == 0) {
LAB_005b182e:
    if (uVar1 == (~uVar1 + 1 & uVar1)) {
      if (uVar1 == 0) {
        iVar6 = 1;
      }
      else {
        iVar6 = uVar1 * 2;
      }
      puVar3 = _malloc(iVar6 << 2);
      if (puVar3 != (undefined4 *)0x0) {
        puVar7 = *(undefined4 **)(param_1 + 0x1c);
        puVar9 = puVar3;
        for (uVar8 = *(uint *)(param_1 + 0x14) & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar9 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar9 = puVar9 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
        _free(*(void **)(param_1 + 0x1c));
        *(undefined4 **)(param_1 + 0x1c) = puVar3;
        if (*(int *)(param_1 + 0x14) == 0) {
          iVar6 = 1;
        }
        else {
          iVar6 = *(int *)(param_1 + 0x14) * 2;
        }
        puVar3 = _malloc(iVar6 << 2);
        if (puVar3 != (undefined4 *)0x0) {
          puVar7 = *(undefined4 **)(param_1 + 0x18);
          puVar9 = puVar3;
          for (uVar8 = *(uint *)(param_1 + 0x14) & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
            *puVar9 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar9 = puVar9 + 1;
          }
          for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
            *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
            puVar7 = (undefined4 *)((int)puVar7 + 1);
            puVar9 = (undefined4 *)((int)puVar9 + 1);
          }
          _free(*(void **)(param_1 + 0x18));
          *(undefined4 **)(param_1 + 0x18) = puVar3;
          goto LAB_005b18d9;
        }
      }
      local_10 = 0x8007000e;
      goto LAB_005b1915;
    }
LAB_005b18d9:
    for (uVar8 = *(uint *)(param_1 + 0x14); local_8 < uVar8; uVar8 = uVar8 - 1) {
      puVar3 = (undefined4 *)(*(int *)(param_1 + 0x18) + uVar8 * 4);
      *puVar3 = puVar3[-1];
      puVar3 = (undefined4 *)(*(int *)(param_1 + 0x1c) + uVar8 * 4);
      *puVar3 = puVar3[-1];
    }
    *(uint *)(*(int *)(param_1 + 0x18) + local_8 * 4) = param_2;
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + local_8 * 4) = 1;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  else {
    do {
      uVar2 = *(uint *)(*(int *)(param_1 + 0x18) + local_8 * 4);
      if (uVar2 < param_2) {
        uVar8 = local_8 + 1;
        uVar5 = uVar4;
      }
      else {
        uVar5 = local_8;
        if (uVar2 <= param_2) break;
      }
      local_8 = uVar5 + uVar8 >> 1;
      uVar4 = uVar5;
    } while (uVar8 < uVar5);
    if (uVar4 <= uVar8) goto LAB_005b182e;
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = local_8;
  }
LAB_005b1915:
  _free((void *)0x0);
  return local_10;
}


// ==== 0x5b1927 FUN_005b1927

undefined4 __thiscall FUN_005b1927(undefined4 *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  
  pcVar1 = param_2 + 1;
  pcVar3 = param_2;
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  pcVar4 = _malloc((size_t)(pcVar3 + (5 - (int)pcVar1)));
  if (pcVar4 == (char *)0x0) {
    uVar5 = 0x8007000e;
  }
  else {
    *(undefined4 *)pcVar4 = *param_1;
    param_1[1] = pcVar3 + (param_1[1] - (int)pcVar1);
    *param_1 = pcVar4;
    for (uVar6 = (uint)(pcVar3 + (1 - (int)pcVar1)) >> 2; pcVar4 = pcVar4 + 4, uVar6 != 0;
        uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar4 = *(undefined4 *)param_2;
      param_2 = param_2 + 4;
    }
    for (uVar6 = (uint)(pcVar3 + (1 - (int)pcVar1)) & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar4 = *param_2;
      param_2 = param_2 + 1;
      pcVar4 = pcVar4 + 1;
    }
    uVar5 = 0;
  }
  return uVar5;
}


// ==== 0x5b197d FUN_005b197d

int __thiscall FUN_005b197d(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_1[1] == 0) {
      *param_2 = 0;
    }
    else {
      iVar2 = FUN_005d65b0(param_1[1] + 1,param_2);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = (**(code **)(*(int *)*param_2 + 0xc))((int *)*param_2);
      pcVar3 = (char *)(iVar2 + param_1[1]);
      *pcVar3 = '\0';
      for (param_1 = (undefined4 *)*param_1; param_1 != (undefined4 *)0x0;
          param_1 = (undefined4 *)*param_1) {
        pcVar4 = (char *)(param_1 + 1);
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        uVar5 = (int)pcVar4 - ((int)param_1 + 5);
        pcVar3 = pcVar3 + -uVar5;
        pcVar4 = (char *)(param_1 + 1);
        pcVar7 = pcVar3;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar4;
          pcVar4 = pcVar4 + 4;
          pcVar7 = pcVar7 + 4;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar7 = *pcVar4;
          pcVar4 = pcVar4 + 1;
          pcVar7 = pcVar7 + 1;
        }
      }
    }
  }
  return 0;
}


// ==== 0x5b19e6 FUN_005b19e6

undefined4 __fastcall FUN_005b19e6(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}


// ==== 0x5b19ea FUN_005b19ea

void __fastcall FUN_005b19ea(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[6] = 0;
  param_1[7] = 1;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  return;
}


// ==== 0x5b1a04 FUN_005b1a04

undefined4 __thiscall
FUN_005b1a04(undefined4 *param_1,char *param_2,int param_3,undefined4 param_4,undefined4 param_5,
            int param_6,int param_7)

{
  char cVar1;
  char *pcVar2;
  
  if ((param_6 != 0) && (param_7 != 0)) {
    if (param_3 == -1) {
      if (param_2 == (char *)0x0) {
        param_3 = 0;
      }
      else {
        pcVar2 = param_2;
        do {
          cVar1 = *pcVar2;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        param_3 = (int)pcVar2 - (int)(param_2 + 1);
      }
    }
    if ((param_2 != (char *)0x0) || (param_3 == 0)) {
      *param_1 = param_2;
      param_1[6] = param_4;
      param_1[7] = param_5;
      param_1[0xb] = param_6;
      param_1[1] = param_2 + param_3;
      param_1[0xc] = param_7;
      return 0;
    }
  }
  return 0x80004005;
}


// ==== 0x5b1a6c FUN_005b1a6c

undefined4 __fastcall FUN_005b1a6c(undefined4 *param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = (char *)param_1[1];
  if ((char *)*param_1 < pcVar1) {
    do {
      pcVar2 = (char *)*param_1;
      if (*pcVar2 == '\n') {
        return 1;
      }
      if (*pcVar2 == '\\') {
        if ((pcVar2 + 1 < pcVar1) && (pcVar2[1] == '\n')) {
          pcVar2 = pcVar2 + 2;
        }
        else {
          if ((pcVar1 <= pcVar2 + 2) || ((pcVar2[1] != '\r' || (pcVar2[2] != '\n'))))
          goto LAB_005b1ab3;
          pcVar2 = pcVar2 + 3;
        }
        param_1[7] = param_1[7] + 1;
      }
      else {
LAB_005b1ab3:
        pcVar2 = pcVar2 + 1;
      }
      *param_1 = pcVar2;
    } while (pcVar2 < (char *)param_1[1]);
  }
  return 0;
}


// ==== 0x5b1ac5 FUN_005b1ac5

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

int __thiscall FUN_005b1ac5(int param_1,char *param_2,double *param_3)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  double dVar7;
  undefined4 uStackY_1c;
  
  if (param_2 < *(char **)(param_1 + 4)) {
    uStackY_1c = 0x5b1adf;
    iVar1 = _isdigit((int)*param_2);
    pcVar4 = param_2;
    if (iVar1 == 0) goto LAB_005b1ae4;
    do {
      pcVar3 = pcVar4;
      pcVar4 = pcVar3 + 1;
      if (*(char **)(param_1 + 4) <= pcVar4) break;
      uStackY_1c = 0x5b1b19;
      iVar1 = _isdigit((int)*pcVar4);
    } while (iVar1 != 0);
    if (*(char **)(param_1 + 4) <= pcVar4) {
      return 0;
    }
    if (*pcVar4 != '.') {
      return 0;
    }
    pcVar3 = pcVar3 + 2;
    if (pcVar3 < *(char **)(param_1 + 4)) {
      do {
        uStackY_1c = 0x5b1b46;
        iVar1 = _isdigit((int)*pcVar3);
        if (iVar1 == 0) break;
        pcVar3 = pcVar3 + 1;
      } while (pcVar3 < *(char **)(param_1 + 4));
    }
  }
  else {
LAB_005b1ae4:
    if ((*(char **)(param_1 + 4) <= param_2 + 1) || (*param_2 != '.')) {
      return 0;
    }
    uStackY_1c = 0x5b1b02;
    iVar1 = _isdigit((int)param_2[1]);
    if (iVar1 == 0) {
      return 0;
    }
    for (pcVar3 = param_2 + 2; pcVar3 < *(char **)(param_1 + 4); pcVar3 = pcVar3 + 1) {
      uStackY_1c = 0x5b1b5c;
      iVar1 = _isdigit((int)*pcVar3);
      if (iVar1 == 0) break;
    }
  }
  pcVar4 = pcVar3 + 1;
  if (pcVar4 < *(char **)(param_1 + 4)) {
    uStackY_1c = 0x5b1b78;
    iVar1 = _tolower((int)*pcVar3);
    if (iVar1 == 0x65) {
      uStackY_1c = 0x5b1b87;
      iVar1 = _isdigit((int)*pcVar4);
      if (iVar1 != 0) {
        for (pcVar3 = pcVar3 + 2; pcVar3 < *(char **)(param_1 + 4); pcVar3 = pcVar3 + 1) {
          uStackY_1c = 0x5b1b99;
          iVar1 = _isdigit((int)*pcVar3);
          if (iVar1 == 0) break;
        }
        goto LAB_005b1bea;
      }
    }
  }
  if (pcVar3 + 2 < *(char **)(param_1 + 4)) {
    uStackY_1c = 0x5b1bb7;
    iVar1 = _tolower((int)*pcVar3);
    if ((iVar1 == 0x65) && (*pcVar4 == '-')) {
      uStackY_1c = 0x5b1bcc;
      iVar1 = _isdigit((int)pcVar3[2]);
      if (iVar1 != 0) {
        for (pcVar3 = pcVar3 + 3; pcVar3 < *(char **)(param_1 + 4); pcVar3 = pcVar3 + 1) {
          uStackY_1c = 0x5b1bdf;
          iVar1 = _isdigit((int)*pcVar3);
          if (iVar1 == 0) break;
        }
      }
    }
  }
LAB_005b1bea:
  if (param_3 != (double *)0x0) {
    uVar5 = (int)pcVar3 - (int)param_2;
    iVar1 = -(uVar5 + 4 & 0xfffffffc);
    pcVar4 = param_2;
    pcVar6 = &stack0xffffffec + iVar1;
    for (uVar2 = uVar5 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar2 = uVar5 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar6 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    }
    (&stack0xffffffec)[uVar5 + iVar1] = 0;
    *(undefined1 **)(&stack0xffffffe8 + iVar1) = &stack0xffffffec + iVar1;
    *(undefined4 *)((int)&uStackY_1c + iVar1) = 0x5b1c28;
    dVar7 = _atof(*(char **)(&stack0xffffffe8 + iVar1));
    *param_3 = dVar7;
  }
  return (int)pcVar3 - (int)param_2;
}


// ==== 0x5b1c41 FUN_005b1c41

uint __thiscall FUN_005b1c41(int param_1,char *param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  
  if ((param_2 < *(char **)(param_1 + 4)) &&
     ((iVar1 = _isalpha((int)*param_2), pcVar3 = param_2, iVar1 != 0 || (*param_2 == '_')))) {
    do {
      pcVar3 = pcVar3 + 1;
      if (*(char **)(param_1 + 4) <= pcVar3) break;
      iVar1 = _isalnum((int)*pcVar3);
    } while ((iVar1 != 0) || (*pcVar3 == '_'));
    uVar4 = (int)pcVar3 - (int)param_2;
    pcVar3 = (char *)FUN_005b1775(uVar4 + 1);
    if (pcVar3 != (char *)0x0) {
      pcVar5 = pcVar3;
      for (uVar2 = uVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)param_2;
        param_2 = param_2 + 4;
        pcVar5 = pcVar5 + 4;
      }
      for (uVar2 = uVar4 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *pcVar5 = *param_2;
        param_2 = param_2 + 1;
        pcVar5 = pcVar5 + 1;
      }
      pcVar3[uVar4] = '\0';
      *param_3 = pcVar3;
      return uVar4;
    }
  }
  return 0;
}


// ==== 0x5b1cc0 FUN_005b1cc0

undefined4 __thiscall FUN_005b1cc0(int param_1,char *param_2,char *param_3)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  
  param_3[0] = '\0';
  param_3[1] = '\0';
  param_3[2] = '\0';
  param_3[3] = '\0';
  *param_3 = *param_2;
  pcVar1 = param_2 + 1;
  if (*(char **)(param_1 + 4) <= pcVar1) {
    return 1;
  }
  cVar2 = *param_2;
  if ((cVar2 == '#') && ((cVar3 = *pcVar1, cVar3 == '#' || (cVar3 == '@')))) {
    param_3[1] = cVar3;
    return 2;
  }
  cVar3 = *pcVar1;
  if (cVar2 != cVar3) {
    if (cVar3 == '=') {
      if (cVar2 < '0') {
        if (((cVar2 != '/') && (cVar2 != '!')) &&
           ((cVar2 < '%' || (('&' < cVar2 && ((cVar2 < '*' || (('+' < cVar2 && (cVar2 != '-'))))))))
           )) {
          return 1;
        }
      }
      else if ((((cVar2 != '<') && (cVar2 != '>')) && (cVar2 != '^')) && (cVar2 != '|')) {
        return 1;
      }
      param_3[1] = '=';
      return 2;
    }
    if (cVar2 != '-') {
      return 1;
    }
    if (cVar3 == '>') {
      param_3[1] = '>';
      return 2;
    }
    return 1;
  }
  if (cVar2 < ';') {
    if ((((cVar2 != ':') && (cVar2 != '&')) && (cVar2 != '+')) && (cVar2 != '-')) {
      if (cVar2 != '.') {
        return 1;
      }
      param_2 = param_2 + 2;
      if (param_2 < *(char **)(param_1 + 4)) {
        if (*param_2 == '.') {
          param_3[1] = cVar3;
          param_3[2] = *param_2;
          return 3;
        }
        return 1;
      }
      return 1;
    }
  }
  else {
    if (cVar2 == '<') {
LAB_005b1d4f:
      param_3[1] = cVar3;
      if (*(char **)(param_1 + 4) <= param_2 + 2) {
        return 2;
      }
      if (param_2[2] != '=') {
        return 2;
      }
      param_3[2] = '=';
      return 3;
    }
    if (cVar2 != '=') {
      if (cVar2 == '>') goto LAB_005b1d4f;
      if (cVar2 != '|') {
        return 1;
      }
    }
  }
  param_3[1] = cVar3;
  return 2;
}


// ==== 0x5b1dcc FUN_005b1dcc

int __thiscall FUN_005b1dcc(int param_1,char *param_2,undefined4 *param_3)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  uVar3 = 5;
  if (*(char **)(param_1 + 4) <= param_2) {
    return 0;
  }
  iVar1 = _tolower((int)*param_2);
  if (iVar1 == 0x66) {
    uVar3 = 7;
  }
  else {
    pcVar2 = param_2;
    if (iVar1 != 0x68) goto LAB_005b1dfe;
    uVar3 = 6;
  }
  pcVar2 = param_2 + 1;
LAB_005b1dfe:
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = uVar3;
  }
  return (int)pcVar2 - (int)param_2;
}


// ==== 0x5b1e12 FUN_005b1e12

int __thiscall FUN_005b1e12(int param_1,char *param_2,undefined4 *param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  
  bVar2 = false;
  bVar1 = false;
  pcVar4 = param_2;
  if (param_2 < *(char **)(param_1 + 4)) {
    do {
      if (bVar1) {
LAB_005b1e4b:
        if (bVar2) break;
        iVar3 = _tolower((int)*pcVar4);
        if (iVar3 != 0x6c) break;
        bVar2 = true;
      }
      else {
        iVar3 = _tolower((int)*pcVar4);
        if (iVar3 != 0x75) goto LAB_005b1e4b;
        bVar1 = true;
      }
      pcVar4 = pcVar4 + 1;
    } while (pcVar4 < *(char **)(param_1 + 4));
  }
  if (param_3 != (undefined4 *)0x0) {
    if (bVar1) {
      *param_3 = 4;
    }
    else if (bVar2) {
      *param_3 = 3;
    }
  }
  return (int)pcVar4 - (int)param_2;
}


// ==== 0x5b1e99 FUN_005b1e99

void __thiscall FUN_005b1e99(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = FUN_005b17e6(param_2,&param_2);
  if (-1 < iVar1) {
    if (param_3 == 0xff) {
      puVar2 = (uint *)(*(int *)(param_1 + 0x1c) + param_2 * 4);
      *puVar2 = *puVar2 & 0x20;
      puVar2 = (uint *)(param_2 * 4 + *(int *)(param_1 + 0x1c));
      *puVar2 = *puVar2 | 1;
    }
    else if (param_3 == 0x10) {
      puVar2 = (uint *)(*(int *)(param_1 + 0x1c) + param_2 * 4);
      *puVar2 = *puVar2 | 0x10;
    }
    else {
      puVar2 = (uint *)(*(int *)(param_1 + 0x1c) + param_2 * 4);
      *puVar2 = *puVar2 & 0xfffffff0;
      puVar2 = (uint *)(param_2 * 4 + *(int *)(param_1 + 0x1c));
      *puVar2 = *puVar2 | param_3 & 0xf;
    }
  }
  return;
}


// ==== 0x5b1f01 FUN_005b1f01

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_005b1f01(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 local_1004 [4092];
  undefined4 uStack_8;
  
  uStack_8 = 0x5b1f0e;
  puVar2 = local_1004;
  iVar3 = 0xffe;
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x10) != 0) {
      iVar3 = _snprintf(local_1004,0xffe,&DAT_006cc568,*(int *)(param_2 + 0x10));
      if (iVar3 < 0) {
        iVar3 = 0xffe;
      }
      puVar2 = local_1004 + iVar3;
      iVar3 = 0xffe - iVar3;
    }
    iVar1 = *(int *)(param_2 + 0x14);
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    iVar1 = _snprintf(puVar2,iVar3,"(%u): ",iVar1);
    if (iVar1 < 0) {
      iVar1 = iVar3;
    }
    puVar2 = puVar2 + iVar1;
    iVar3 = iVar3 - iVar1;
  }
  if (param_3 != 0) {
    iVar1 = _snprintf(puVar2,iVar3,"error X%u: ",param_3);
    if (iVar1 < 0) {
      iVar1 = iVar3;
    }
    puVar2 = puVar2 + iVar1;
    iVar3 = iVar3 - iVar1;
  }
  iVar1 = _vsnprintf(puVar2,iVar3,param_4,&stack0x00000014);
  if (iVar1 < 0) {
    iVar1 = iVar3;
  }
  (puVar2 + iVar1)[1] = 0;
  puVar2[iVar1] = 10;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  FUN_005b1927(local_1004);
  return;
}


// ==== 0x5b1fca FUN_005b1fca

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

int FUN_005b1fca(int param_1,int param_2,int param_3,undefined4 param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 local_1010 [4096];
  int local_10;
  char *local_c;
  int *local_8;
  
  local_8 = (int *)0x5b1fd7;
  puVar6 = local_1010;
  local_10 = 0xffe;
  iVar3 = FUN_005b17e6(param_3,&local_8);
  if (-1 < iVar3) {
    puVar1 = (uint *)(*(int *)(param_1 + 0x1c) + (int)local_8 * 4);
    uVar2 = *puVar1;
    uVar4 = uVar2 & 0xf;
    if (uVar4 == 0xf) {
      local_8 = (int *)(param_1 + 8);
      local_c = "error";
      iVar3 = 0xffe;
    }
    else {
      local_8 = (int *)(param_1 + 0xc);
      local_c = "warning";
      if ((((*(uint *)(param_1 + 0x10) == 0) || (uVar4 == 0)) || (*(uint *)(param_1 + 0x10) < uVar4)
          ) || (((uVar2 & 0x10) != 0 && ((uVar2 & 0x20) != 0)))) {
        return 0;
      }
      *puVar1 = uVar2 | 0x20;
      iVar3 = local_10;
    }
    if (param_2 != 0) {
      if (*(int *)(param_2 + 0x10) != 0) {
        iVar3 = _snprintf(local_1010,0xffe,&DAT_006cc568,*(int *)(param_2 + 0x10));
        if (iVar3 < 0) {
          iVar3 = 0xffe;
        }
        puVar6 = local_1010 + iVar3;
        iVar3 = 0xffe - iVar3;
      }
      iVar5 = *(int *)(param_2 + 0x14);
      if (iVar5 == 0) {
        iVar5 = 1;
      }
      iVar5 = _snprintf(puVar6,iVar3,"(%u): ",iVar5);
      if (iVar5 < 0) {
        iVar5 = iVar3;
      }
      puVar6 = puVar6 + iVar5;
      iVar3 = iVar3 - iVar5;
    }
    if (param_3 != 0) {
      iVar5 = _snprintf(puVar6,iVar3,"%s X%u: ",local_c,param_3);
      if (iVar5 < 0) {
        iVar5 = iVar3;
      }
      puVar6 = puVar6 + iVar5;
      iVar3 = iVar3 - iVar5;
    }
    iVar5 = _vsnprintf(puVar6,iVar3,param_4,&stack0x00000014);
    if (iVar5 < 0) {
      iVar5 = iVar3;
    }
    (puVar6 + iVar5)[1] = 0;
    puVar6[iVar5] = 10;
    *local_8 = *local_8 + 1;
    iVar3 = FUN_005b1927(local_1010);
  }
  return iVar3;
}


// ==== 0x5b212b FUN_005b212b

void __thiscall FUN_005b212b(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  char *pcVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  undefined1 local_104 [256];
  
  switch(*param_3) {
  case 0:
    break;
  case 1:
    puVar3 = param_3 + 2;
    goto LAB_005b21ce;
  case 2:
    uVar2 = CONCAT44(param_3[2],"integer \'%u\'");
    goto LAB_005b21d3;
  case 3:
    uVar2 = CONCAT44(param_3[2],"integer \'%dl\'");
    goto LAB_005b21d3;
  case 4:
    uVar2 = CONCAT44(param_3[2],"integer \'%uul\'");
    goto LAB_005b21d3;
  case 5:
    uVar2 = *(undefined8 *)(param_3 + 2);
    pcVar1 = "float \'%g\'";
    goto LAB_005b21b5;
  case 6:
    uVar2 = *(undefined8 *)(param_3 + 2);
    pcVar1 = "float \'%gh\'";
    goto LAB_005b21b5;
  case 7:
    uVar2 = *(undefined8 *)(param_3 + 2);
    pcVar1 = "float \'%gf\'";
    goto LAB_005b21b5;
  case 8:
    uVar2 = *(undefined8 *)(param_3 + 2);
    pcVar1 = "float \'%gl\'";
LAB_005b21b5:
    _snprintf(local_104,0x100,pcVar1,uVar2);
    goto LAB_005b2217;
  case 9:
    puVar3 = (undefined4 *)param_3[2];
LAB_005b21ce:
    uVar2 = CONCAT44(puVar3,"token \'%s\'");
LAB_005b21d3:
    _snprintf(local_104,0x100,uVar2);
    goto LAB_005b2217;
  case 10:
    break;
  default:
    break;
  case 0xc:
    break;
  case 0xd:
  }
  _snprintf(local_104,0x100);
LAB_005b2217:
  FUN_005b1f01(param_1,param_3,param_2,"syntax error : unexpected %s",local_104);
  return;
}


// ==== 0x5b226e FUN_005b226e

undefined4 __fastcall FUN_005b226e(uint *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_1[1] <= *param_1) {
    return 0;
  }
  do {
    pcVar3 = (char *)*param_1;
    cVar1 = *pcVar3;
    if (cVar1 == '\n') {
      param_1[7] = param_1[7] + 1;
      *param_1 = (uint)(pcVar3 + 1);
      local_8 = 1;
    }
    else if (cVar1 == '\\') {
      if ((pcVar3 + 1 < (char *)param_1[1]) && (pcVar3[1] == '\n')) {
        pcVar3 = pcVar3 + 2;
      }
      else {
        if (((char *)param_1[1] <= pcVar3 + 2) || ((pcVar3[1] != '\r' || (pcVar3[2] != '\n'))))
        goto LAB_005b22dc;
        pcVar3 = pcVar3 + 3;
      }
      param_1[7] = param_1[7] + 1;
      *param_1 = (uint)pcVar3;
    }
    else {
LAB_005b22dc:
      iVar4 = _isspace((int)cVar1);
      if (iVar4 == 0) {
        pcVar3 = (char *)*param_1;
        cVar1 = *pcVar3;
        if (cVar1 != '\r') {
          if ((((cVar1 == '/') && (pcVar3 + 1 < (char *)param_1[1])) && (pcVar3[1] == '/')) ||
             (((param_1[10] & 2) != 0 && (cVar1 == ';')))) {
            FUN_005b1a6c();
          }
          else {
            if (cVar1 != '/') {
              return local_8;
            }
            pcVar2 = (char *)param_1[1];
            if (pcVar2 <= pcVar3 + 1) {
              return local_8;
            }
            if (pcVar3[1] != '*') {
              return local_8;
            }
            *param_1 = (uint)(pcVar3 + 2);
            if (pcVar3 + 2 < pcVar2) {
              do {
                pcVar3 = (char *)*param_1;
                if (((*pcVar3 == '*') && (pcVar3 + 1 < pcVar2)) && (pcVar3[1] == '/')) break;
                if (*pcVar3 == '\n') {
                  param_1[7] = param_1[7] + 1;
                }
                *param_1 = (uint)(pcVar3 + 1);
              } while (pcVar3 + 1 < (char *)param_1[1]);
            }
            if ((char *)*param_1 < pcVar2) {
              *param_1 = (uint)((char *)*param_1 + 2);
            }
            else {
              FUN_005b1f01(param_1[0xc],param_1 + 2,0x3e9,"comment continues past end of file");
            }
          }
          goto LAB_005b238c;
        }
      }
      *param_1 = *param_1 + 1;
    }
LAB_005b238c:
    if (param_1[1] <= *param_1) {
      return local_8;
    }
  } while( true );
}


// ==== 0x5b239e FUN_005b239e

int __thiscall FUN_005b239e(int param_1,char *param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  pcVar4 = param_2 + 2;
  if ((((pcVar4 < *(char **)(param_1 + 4)) && (*param_2 == '0')) && (param_2[1] == 'x')) &&
     (iVar2 = _isxdigit((int)*pcVar4), iVar2 != 0)) {
    iVar2 = 0;
    while ((pcVar4 < *(char **)(param_1 + 4) && (iVar3 = _isxdigit((int)*pcVar4), iVar3 != 0))) {
      cVar1 = *pcVar4;
      iVar2 = iVar2 * 0x10;
      if (cVar1 < 'a') {
        if (cVar1 < 'A') {
          iVar2 = iVar2 + -0x30 + (int)cVar1;
        }
        else {
          iVar2 = iVar2 + -0x37 + (int)cVar1;
        }
      }
      else {
        iVar2 = iVar2 + -0x57 + (int)cVar1;
      }
      pcVar4 = pcVar4 + 1;
    }
    if (param_3 != (int *)0x0) {
      *param_3 = iVar2;
    }
    iVar2 = (int)pcVar4 - (int)param_2;
    if (10 < iVar2) {
      FUN_005b1f01(*(undefined4 *)(param_1 + 0x30),param_1 + 8,0x3ea,"hex value truncated to 32bits"
                  );
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ==== 0x5b2443 FUN_005b2443

int __thiscall FUN_005b2443(int param_1,char *param_2,uint *param_3)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  
  if ((param_2 < *(char **)(param_1 + 4)) && (*param_2 == '0')) {
    uVar3 = 0;
    bVar2 = false;
    pcVar5 = param_2;
    while (((pcVar5 = pcVar5 + 1, pcVar5 < *(char **)(param_1 + 4) && (cVar1 = *pcVar5, '/' < cVar1)
            ) && (cVar1 < '8'))) {
      if ((uVar3 & 0xe0000000) != 0) {
        bVar2 = true;
      }
      uVar3 = cVar1 + -0x30 + uVar3 * 8;
    }
    if (param_3 != (uint *)0x0) {
      *param_3 = uVar3;
    }
    if (bVar2) {
      FUN_005b1f01(*(undefined4 *)(param_1 + 0x30),param_1 + 8,0x3eb,
                   "octal value truncated to 32bits");
    }
    iVar4 = (int)pcVar5 - (int)param_2;
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}


// ==== 0x5b24bf FUN_005b24bf

int __thiscall FUN_005b24bf(int param_1,char *param_2,uint *param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  
  if ((*(char **)(param_1 + 4) <= param_2) || (iVar2 = _isdigit((int)*param_2), iVar2 == 0)) {
    return 0;
  }
  uVar5 = 0;
  bVar1 = false;
  pcVar4 = param_2;
  if (param_2 < *(char **)(param_1 + 4)) {
    do {
      iVar2 = _isdigit((int)*pcVar4);
      if (iVar2 == 0) break;
      if (0x19999999 < uVar5) {
        bVar1 = true;
      }
      uVar3 = uVar5 * 10;
      uVar5 = *pcVar4 + -0x30 + uVar3;
      if (uVar5 < uVar3) {
        bVar1 = true;
      }
      pcVar4 = pcVar4 + 1;
    } while (pcVar4 < *(char **)(param_1 + 4));
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = uVar5;
  }
  if (bVar1) {
    FUN_005b1f01(*(undefined4 *)(param_1 + 0x30),param_1 + 8,0x3ec,
                 "decimal value truncated to 32bits");
  }
  return (int)pcVar4 - (int)param_2;
}


// ==== 0x5b2560 FUN_005b2560

int __thiscall FUN_005b2560(int param_1,char *param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (*(char **)(param_1 + 4) <= param_2) {
    return 0;
  }
  cVar1 = *param_2;
  if ((cVar1 == '\\') && ((*(byte *)(param_1 + 0x28) & 4) == 0)) {
    pcVar4 = param_2 + 1;
    if (*(char **)(param_1 + 4) <= pcVar4) {
      FUN_005b1f01(*(undefined4 *)(param_1 + 0x30),param_1 + 8,0x3ef,
                   "character continues past end of file");
    }
    cVar1 = *pcVar4;
    if (cVar1 == 'a') {
      *param_3 = 7;
      goto LAB_005b26eb;
    }
    if (cVar1 == 'b') {
      *param_3 = 8;
      goto LAB_005b26eb;
    }
    if (cVar1 == 'f') {
      *param_3 = 0xc;
      goto LAB_005b26eb;
    }
    if (cVar1 == 'n') {
      *param_3 = 10;
      goto LAB_005b26eb;
    }
    if (cVar1 == 'r') {
      *param_3 = 0xd;
      goto LAB_005b26eb;
    }
    if (cVar1 == 't') {
      *param_3 = 9;
      goto LAB_005b26eb;
    }
    if (cVar1 == 'v') {
      *param_3 = 0xb;
      goto LAB_005b26eb;
    }
    if (('/' < cVar1) && (cVar1 < '8')) {
      pcVar5 = *(char **)(param_1 + 4);
      if (param_2 + 4 < *(char **)(param_1 + 4)) {
        pcVar5 = param_2 + 4;
      }
      iVar3 = 0;
      for (; ((pcVar4 < pcVar5 && (cVar1 = *pcVar4, '/' < cVar1)) && (cVar1 < '8'));
          pcVar4 = pcVar4 + 1) {
        iVar3 = cVar1 + -0x30 + iVar3 * 8;
      }
      *param_3 = iVar3;
      goto LAB_005b26eb;
    }
    if ((cVar1 == 'x') &&
       ((pcVar5 = param_2 + 2, pcVar5 < *(char **)(param_1 + 4) &&
        (iVar3 = _isxdigit((int)*pcVar5), iVar3 != 0)))) {
      iVar3 = 0;
      while ((pcVar5 < *(char **)(param_1 + 4) && (iVar2 = _isxdigit((int)*pcVar5), iVar2 != 0))) {
        cVar1 = *pcVar5;
        iVar3 = iVar3 * 0x10;
        if (cVar1 < 'a') {
          if (cVar1 < 'A') {
            iVar3 = iVar3 + -0x30 + (int)cVar1;
          }
          else {
            iVar3 = iVar3 + -0x37 + (int)cVar1;
          }
        }
        else {
          iVar3 = iVar3 + -0x57 + (int)cVar1;
        }
        pcVar5 = pcVar5 + 1;
      }
      *param_3 = iVar3;
      pcVar4 = pcVar5;
      goto LAB_005b26eb;
    }
    cVar1 = *pcVar4;
    pcVar4 = param_2 + 2;
  }
  else {
    pcVar4 = param_2 + 1;
  }
  *param_3 = (int)cVar1;
LAB_005b26eb:
  return (int)pcVar4 - (int)param_2;
}


// ==== 0x5b26f6 FUN_005b26f6

char * __thiscall FUN_005b26f6(int param_1,char *param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char local_30 [4];
  char acStack_2c [28];
  undefined1 local_10 [4];
  undefined4 local_c;
  
  pcVar3 = param_2;
  if ((*(byte *)(param_1 + 0x28) & 2) == 0) {
    return (char *)0x0;
  }
  pcVar4 = param_2 + 1;
  if ((((pcVar4 < *(char **)(param_1 + 4)) && (iVar1 = _isalpha((int)*param_2), iVar1 != 0)) &&
      (iVar1 = _isalpha((int)*pcVar4), iVar1 != 0)) &&
     ((pcVar3 + 2 < *(char **)(param_1 + 4) && (pcVar3[2] == '.')))) {
    iVar1 = FUN_005b24bf(pcVar3 + 3,&param_2);
    if (((iVar1 != 0) &&
        ((param_2 < (char *)0x100 && (pcVar4 = pcVar3 + 3 + iVar1, pcVar4 < *(char **)(param_1 + 4))
         ))) && (*pcVar4 == '.')) {
      pcVar4 = pcVar4 + 1;
      iVar1 = FUN_005b24bf(pcVar4,&param_2);
      if (iVar1 == 0) {
        iVar1 = FUN_005b1c41(pcVar4,&param_2);
        if (iVar1 == 0) {
          return (char *)0x0;
        }
        param_2 = (char *)0x0;
      }
      if ((param_2 < (char *)0x100) &&
         (pcVar4 = pcVar4 + (iVar1 - (int)pcVar3), pcVar4 < (char *)0x20)) {
        pcVar5 = local_30;
        for (uVar2 = (uint)pcVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined4 *)pcVar5 = *(undefined4 *)pcVar3;
          pcVar3 = pcVar3 + 4;
          pcVar5 = pcVar5 + 4;
        }
        for (uVar2 = (uint)pcVar4 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *pcVar5 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          pcVar5 = pcVar5 + 1;
        }
        acStack_2c[(int)(pcVar4 + -4)] = '\0';
        iVar1 = FUN_005d7700(local_30,1,local_10);
        if (-1 < iVar1) {
          *param_3 = local_c;
          return pcVar4;
        }
      }
    }
  }
  return (char *)0x0;
}


// ==== 0x5b27f9 FUN_005b27f9

char * __thiscall FUN_005b27f9(int param_1,char *param_2,undefined4 param_3)

{
  int iVar1;
  char *pcVar2;
  
  if ((param_2 < *(char **)(param_1 + 4)) && (*param_2 == '\'')) {
    iVar1 = FUN_005b2560(param_2 + 1,param_3);
    if ((iVar1 != 0) &&
       ((pcVar2 = param_2 + 1 + iVar1, pcVar2 < *(char **)(param_1 + 4) && (*pcVar2 == '\'')))) {
      return pcVar2 + (1 - (int)param_2);
    }
  }
  return (char *)0x0;
}


// ==== 0x5b2838 FUN_005b2838

int __thiscall FUN_005b2838(int param_1,char *param_2,undefined4 *param_3)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  undefined1 *puVar4;
  int iVar5;
  char cVar6;
  char *pcVar7;
  undefined4 uVar8;
  char *pcVar9;
  
  pcVar3 = *(char **)(param_1 + 4);
  if (pcVar3 <= param_2) {
    return 0;
  }
  if (*param_2 == '\"') {
    cVar6 = '\"';
  }
  else {
    if (*param_2 != '<') {
      return 0;
    }
    if ((*(byte *)(param_1 + 0x28) & 8) == 0) {
      return 0;
    }
    cVar6 = '>';
  }
  pcVar1 = param_2 + 1;
  for (pcVar7 = pcVar1; ((pcVar7 < pcVar3 && (cVar2 = *pcVar7, cVar6 != cVar2)) && (cVar2 != '\n'));
      pcVar7 = pcVar7 + 1) {
    if ((cVar2 == '\\') && ((*(byte *)(param_1 + 0x28) & 4) == 0)) {
      pcVar7 = pcVar7 + 1;
    }
  }
  if (pcVar7 < pcVar3) {
    if (*pcVar7 != '\n') goto LAB_005b28c1;
    pcVar9 = "string continues past end of line";
    uVar8 = 0x3ed;
  }
  else {
    pcVar9 = "string continues past end of file";
    uVar8 = 0x3ee;
    pcVar7 = pcVar3;
  }
  FUN_005b1f01(*(undefined4 *)(param_1 + 0x30),param_1 + 8,uVar8,pcVar9);
LAB_005b28c1:
  puVar4 = (undefined1 *)FUN_005b1775((int)pcVar7 - (int)param_2);
  if (puVar4 == (undefined1 *)0x0) {
    return 0;
  }
  *param_3 = puVar4;
  for (; pcVar1 < pcVar7; pcVar1 = pcVar1 + iVar5) {
    iVar5 = FUN_005b2560(pcVar1,&param_3);
    *puVar4 = param_3._0_1_;
    puVar4 = puVar4 + 1;
  }
  *puVar4 = 0;
  return ((int)pcVar7 - (int)param_2) + 1;
}


// ==== 0x5b291b FUN_005b291b

undefined4 __thiscall FUN_005b291b(uint *param_1,uint param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  
  param_1[10] = param_2;
  param_3[4] = param_1[6];
  iVar2 = 0;
  param_3[5] = param_1[7];
  iVar1 = FUN_005b226e();
  if (iVar1 == 0) {
    param_3[4] = param_1[6];
    param_3[5] = param_1[7];
    if (*param_1 < param_1[1]) {
      iVar2 = FUN_005b1ac5(*param_1,param_3 + 2);
      if (iVar2 == 0) {
        iVar2 = FUN_005b27f9(*param_1,param_3 + 2);
        if (iVar2 != 0) {
          *param_3 = 2;
          goto LAB_005b2a75;
        }
        iVar2 = FUN_005b239e(*param_1,param_3 + 2);
        if (iVar2 == 0) {
          iVar2 = FUN_005b2443(*param_1,param_3 + 2);
          if (iVar2 == 0) {
            iVar2 = FUN_005b24bf(*param_1,param_3 + 2);
            if (iVar2 == 0) {
              iVar2 = FUN_005b2838(*param_1,param_3 + 2);
              if (iVar2 == 0) {
                iVar2 = FUN_005b26f6(*param_1,param_3 + 2);
                if (iVar2 == 0) {
                  iVar2 = FUN_005b1c41(*param_1,param_3 + 2);
                  if (iVar2 == 0) {
                    iVar2 = FUN_005b1cc0(*param_1,param_3 + 2);
                    *param_3 = 1;
                  }
                  else {
                    *param_3 = 9;
                  }
                }
                else {
                  *param_3 = 0;
                }
              }
              else {
                *param_3 = (*(char *)*param_1 != '\"') + 10;
              }
              goto LAB_005b2a75;
            }
          }
        }
        *param_3 = 2;
        iVar1 = FUN_005b1e12(*param_1 + iVar2,param_3);
      }
      else {
        *param_3 = 5;
        iVar1 = FUN_005b1dcc(*param_1 + iVar2,param_3);
      }
      iVar2 = iVar2 + iVar1;
    }
    else {
      *param_3 = 0xd;
    }
  }
  else {
    *param_3 = 0xc;
  }
LAB_005b2a75:
  param_3[6] = *param_1;
  param_3[7] = iVar2;
  *param_1 = *param_1 + iVar2;
  return 0;
}


// ==== 0x5b2a87 FUN_005b2a87

void __fastcall FUN_005b2a87(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}


// ==== 0x5b2a99 FUN_005b2a99

void * __thiscall FUN_005b2a99(void *param_1,byte param_2)

{
  FUN_005b5e96();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5b2ab5 FUN_005b2ab5

void __fastcall FUN_005b2ab5(int param_1)

{
  int iVar1;
  void *_Memory;
  
  iVar1 = *(int *)(param_1 + 0x14);
  while (iVar1 != 0) {
    _Memory = *(void **)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)((int)_Memory + 0x14);
    *(undefined4 *)((int)_Memory + 0x14) = 0;
    FUN_005b2ab5();
    _free(_Memory);
    iVar1 = *(int *)(param_1 + 0x14);
  }
  return;
}


// ==== 0x5b2ae3 FUN_005b2ae3

void * __thiscall FUN_005b2ae3(void *param_1,byte param_2)

{
  FUN_005b2ab5();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5b2aff FUN_005b2aff

void __fastcall FUN_005b2aff(undefined4 *param_1)

{
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[4] = param_1;
  param_1[5] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  param_1[6] = 0;
  return;
}


// ==== 0x5b2b18 FUN_005b2b18

void __fastcall FUN_005b2b18(int param_1)

{
  int iVar1;
  void *_Memory;
  
  if (*(void **)(param_1 + 4) != (void *)0x0) {
    _free(*(void **)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  iVar1 = *(int *)(param_1 + 8);
  while (iVar1 != 0) {
    _Memory = *(void **)(param_1 + 8);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)((int)_Memory + 8);
    *(undefined4 *)((int)_Memory + 8) = 0;
    FUN_005b2b18();
    _free(_Memory);
    iVar1 = *(int *)(param_1 + 8);
  }
  return;
}


// ==== 0x5b2b58 FUN_005b2b58

void * __thiscall FUN_005b2b58(void *param_1,byte param_2)

{
  FUN_005b2b18();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5b2b74 FUN_005b2b74

undefined4 __thiscall FUN_005b2b74(int param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 local_8;
  
  local_8 = 0;
  pvVar1 = _malloc(0x1c);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_005b2aff();
  }
  if (piVar2 == (int *)0x0) {
    return 0x8007000e;
  }
  if (param_3 != 0) {
    iVar3 = (uint)((param_3 & 3) != 0) + (param_3 >> 2);
    *piVar2 = iVar3;
    puVar4 = _malloc(iVar3 * 4);
    piVar2[1] = (int)puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      local_8 = 0x8007000e;
      goto LAB_005b2c12;
    }
    for (uVar5 = param_3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar4 = *param_2;
      param_2 = param_2 + 1;
      puVar4 = puVar4 + 1;
    }
    for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
      *(undefined1 *)puVar4 = *(undefined1 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
  }
  piVar2[3] = *(int *)(param_1 + 0x10);
  *(int **)(*(int *)(param_1 + 0x10) + 8) = piVar2;
  *(int **)(param_1 + 0x10) = piVar2;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = piVar2;
  }
  piVar2 = (int *)0x0;
LAB_005b2c12:
  if (piVar2 != (int *)0x0) {
    FUN_005b2b58(1);
  }
  return local_8;
}


// ==== 0x5b2c29 FUN_005b2c29

void FUN_005b2c29(char *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  char *local_8;
  
  local_8 = (char *)0x0;
  if (param_1 != (char *)0x0) {
    local_8 = param_1;
    do {
      cVar1 = *local_8;
      local_8 = local_8 + 1;
    } while (cVar1 != '\0');
    local_8 = local_8 + (1 - (int)(param_1 + 1));
  }
  iVar2 = FUN_005b2b74(&local_8,4,param_2);
  if ((-1 < iVar2) && (param_1 != (char *)0x0)) {
    FUN_005b2b74(param_1,local_8,0);
  }
  return;
}


// ==== 0x5b2c79 FUN_005b2c79

undefined4 __thiscall FUN_005b2c79(int param_1,undefined4 param_2,undefined4 *param_3)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_8;
  
  local_8 = 0;
  pvVar1 = _malloc(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005b2aff();
  }
  if (puVar2 == (undefined4 *)0x0) {
    local_8 = 0x8007000e;
  }
  else {
    *puVar2 = 1;
    puVar3 = _malloc(4);
    puVar2[1] = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      local_8 = 0x8007000e;
    }
    else {
      *puVar3 = 0xffffffff;
      puVar2[5] = param_2;
      puVar2[3] = *(undefined4 *)(param_1 + 0x10);
      *(undefined4 **)(*(int *)(param_1 + 0x10) + 8) = puVar2;
      *(undefined4 **)(param_1 + 0x10) = puVar2;
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = puVar2;
      }
      puVar2 = (undefined4 *)0x0;
    }
    if (puVar2 != (undefined4 *)0x0) {
      FUN_005b2b58(1);
    }
  }
  return local_8;
}


// ==== 0x5b2d02 FUN_005b2d02

undefined4 __thiscall FUN_005b2d02(int param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0x10);
  *(int *)(*(int *)(param_1 + 0x10) + 8) = param_2;
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  return 0;
}


// ==== 0x5b2d1d FUN_005b2d1d

undefined4 __thiscall FUN_005b2d1d(uint *param_1,int param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  for (; param_1 != (uint *)0x0; param_1 = (uint *)param_1[2]) {
    if (param_3 != (uint *)0x0) {
      param_1[6] = *param_3;
      *param_3 = *param_3 + *param_1 * 4;
    }
    if (param_2 != 0) {
      if (param_1[5] == 0) {
        puVar3 = (undefined4 *)param_1[1];
      }
      else {
        puVar3 = (undefined4 *)(param_1[5] + 0x18);
      }
      puVar4 = (undefined4 *)(param_1[6] + param_2);
      for (uVar1 = *param_1 & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined1 *)puVar4 = *(undefined1 *)puVar3;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
    }
  }
  return 0;
}


// ==== 0x5b2d7a FUN_005b2d7a

int __thiscall
FUN_005b2d7a(int param_1,int param_2,undefined4 *param_3,int *param_4,int *param_5,int *param_6,
            int *param_7,int *param_8)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  int local_c;
  int local_8;
  
  piVar2 = param_8;
  piVar1 = param_7;
  local_8 = 0;
  if (param_2 == 0) {
    return -0x7fffbffb;
  }
  iVar3 = *(int *)(param_2 + 4);
  local_c = param_1;
  if (iVar3 == 1) {
    *param_7 = 0;
    *param_8 = 0;
    while( true ) {
      if (*(int *)(param_2 + 4) != 1) {
        return -0x7fffbffb;
      }
      iVar3 = *(int *)(param_2 + 8);
      if (iVar3 == 0) {
        return -0x7fffbffb;
      }
      if (*(int *)(iVar3 + 4) != 5) {
        return -0x7fffbffb;
      }
      if (*(int *)(iVar3 + 0x10) != 1) {
        return -0x7fffbffb;
      }
      iVar3 = *(int *)(iVar3 + 0x18);
      if (iVar3 == 0) {
        return -0x7fffbffb;
      }
      if (*(int *)(iVar3 + 4) != 10) {
        return -0x7fffbffb;
      }
      if (*(int *)(iVar3 + 0x20) == 0) {
        return -0x7fffbffb;
      }
      local_8 = FUN_005b2d7a(*(int *)(iVar3 + 0x20),local_20,local_1c,local_18,local_14,local_10,
                             &param_7);
      if (local_8 < 0) break;
      *param_8 = *param_8 + (int)param_7;
      param_2 = *(int *)(param_2 + 0xc);
      *piVar1 = *piVar1 + 1;
      if (param_2 == 0) {
        *param_3 = 0;
        *param_4 = 0;
        *param_5 = 0;
        *param_6 = 0;
        return local_8;
      }
    }
    return local_8;
  }
  if (iVar3 == 7) {
    if (*(int *)(param_2 + 0x10) == 0) {
      return -0x7fffbffb;
    }
    iVar3 = FUN_005b2d7a(*(int *)(param_2 + 0x10),param_3,param_4,param_5,param_6,param_7,param_8);
    if (-1 < iVar3) {
      if (*param_6 == 0) {
        *param_6 = 1;
      }
      *param_6 = *(int *)(param_2 + 0x14) * *param_6;
      *piVar2 = *(int *)(param_2 + 0x14) * *piVar2;
      return iVar3;
    }
    return iVar3;
  }
  if (iVar3 != 8) {
    pcVar4 = "ID3DXEffectCompiler: Unexpected node encountered when trying to determine type";
    goto LAB_005b2dbb;
  }
  *param_6 = 0;
  *param_7 = 0;
  iVar3 = *(int *)(param_2 + 0x10);
  if (iVar3 == 0) {
LAB_005b2e10:
    iVar3 = 1;
    *param_4 = 1;
  }
  else if (iVar3 == 1) {
    *param_4 = *(int *)(param_2 + 0x1c);
    iVar3 = *(int *)(param_2 + 0x18);
  }
  else {
    if (iVar3 != 2) {
      if (iVar3 != 3) {
        pcVar4 = "ID3DXEffectCompiler: Unexpected template type";
        goto LAB_005b2dbb;
      }
      goto LAB_005b2e10;
    }
    *param_4 = *(int *)(param_2 + 0x18);
    iVar3 = *(int *)(param_2 + 0x1c);
  }
  *param_5 = iVar3;
  switch(*(undefined4 *)(param_2 + 0x14)) {
  case 0:
    *param_3 = 1;
    break;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 0xd:
    *param_3 = 2;
    break;
  case 9:
  case 10:
  case 0xb:
  case 0xc:
    *param_3 = 3;
    break;
  case 0xe:
    *param_3 = 4;
    *param_8 = 4;
    goto LAB_005b2f18;
  case 0xf:
    *param_3 = 5;
    break;
  case 0x10:
    *param_3 = 6;
    break;
  case 0x11:
    *param_3 = 7;
    break;
  case 0x12:
    *param_3 = 8;
    break;
  case 0x13:
    *param_3 = 9;
    break;
  case 0x14:
    *param_3 = 10;
    goto LAB_005b2ede;
  case 0x15:
    *param_3 = 0xb;
    goto LAB_005b2ede;
  case 0x16:
    *param_3 = 0xc;
    goto LAB_005b2ede;
  case 0x17:
    *param_3 = 0xd;
    goto LAB_005b2ede;
  case 0x18:
    *param_3 = 0xe;
LAB_005b2ede:
    *param_8 = 0;
    goto LAB_005b2f18;
  case 0x19:
    *param_3 = 0xf;
    break;
  case 0x1a:
    *param_3 = 0x10;
    break;
  case 0x1b:
    *param_3 = 0x11;
    break;
  case 0x1c:
    *param_3 = 0x12;
    break;
  default:
    pcVar4 = "ID3DXEffectCompiler: Unexpected component type";
LAB_005b2dbb:
    FUN_005b1f01(param_1 + 0xc,0,0,pcVar4);
    return -0x7fffbffb;
  }
  *param_8 = 4;
LAB_005b2f18:
  *param_8 = *param_4 * *param_5 * *param_8;
  return 0;
}


// ==== 0x5b30af FUN_005b30af

int FUN_005b30af(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_8;
  
  piVar3 = param_3;
  iVar5 = *param_2;
  piVar4 = (int *)(param_1 + iVar5);
  iVar7 = piVar4[4];
  iVar1 = piVar4[1];
  if (iVar7 == 0) {
    iVar7 = 1;
  }
  if (iVar1 < 0) {
LAB_005b317e:
    iVar6 = 0;
  }
  else {
    if (iVar1 < 4) {
      iVar1 = piVar4[6];
      iVar2 = piVar4[5];
      iVar6 = *piVar4;
      if (((iVar6 == 1) || (iVar6 == 2)) || (iVar6 == 3)) {
        iVar6 = 4;
      }
      else {
        iVar6 = 0;
        iVar7 = 0;
      }
      *param_2 = iVar5 + 0x1c;
      iVar6 = iVar1 * iVar2 * iVar6;
      *param_3 = iVar1 * iVar2 * iVar7;
    }
    else if (iVar1 == 4) {
      if ((*piVar4 < 10) || (0xe < *piVar4)) {
        iVar6 = 4;
      }
      else {
        iVar6 = 0;
      }
      *param_2 = iVar5 + 0x14;
      *param_3 = iVar7;
    }
    else {
      if (iVar1 != 5) goto LAB_005b317e;
      iVar1 = piVar4[5];
      param_3 = (int *)0x0;
      *param_2 = iVar5 + 0x18;
      *piVar3 = 0;
      iVar6 = (int)param_3;
      for (; iVar1 != 0; iVar1 = iVar1 + -1) {
        iVar5 = FUN_005b30af(param_1,param_2,&local_8);
        iVar6 = iVar6 + iVar5;
        *piVar3 = *piVar3 + local_8;
      }
      *piVar3 = *piVar3 * iVar7;
    }
    iVar6 = iVar6 * iVar7;
  }
  return iVar6;
}


// ==== 0x5b3187 FUN_005b3187

undefined4 FUN_005b3187(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}


// ==== 0x5b3194 FUN_005b3194

undefined4 FUN_005b3194(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  
  iVar1 = 4;
  bVar4 = true;
  piVar2 = param_2;
  piVar3 = &DAT_006a08a8;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *piVar2 == *piVar3;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (bVar4);
  if (!bVar4) {
    iVar1 = 4;
    bVar4 = true;
    piVar2 = &DAT_006abe14;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *param_2 == *piVar2;
      param_2 = param_2 + 1;
      piVar2 = piVar2 + 1;
    } while (bVar4);
    if (!bVar4) {
      return 0x80004002;
    }
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}


// ==== 0x5b31d8 FUN_005b31d8

int FUN_005b31d8(int *param_1,uint param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int local_8;
  
  piVar4 = param_4;
  piVar3 = param_3;
  iVar2 = param_2;
  iVar5 = *(int *)(param_2 + 4);
  local_8 = 0;
  if (iVar5 == 1) {
    *param_3 = 1;
    *param_4 = 0;
    while (((((*(int *)(param_2 + 4) == 1 && (iVar5 = *(int *)(param_2 + 8), iVar5 != 0)) &&
             (*(int *)(iVar5 + 4) == 5)) &&
            ((*(int *)(iVar5 + 0x10) == 1 && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)))) &&
           ((*(int *)(iVar5 + 4) == 10 && (*(int *)(iVar5 + 0x20) != 0))))) {
      iVar5 = FUN_005b31d8(param_1,*(int *)(iVar5 + 0x20),&param_3,&param_4);
      if (iVar5 < 0) {
        return iVar5;
      }
      *piVar4 = *piVar4 + (int)param_3 * (int)param_4;
      param_2 = *(int *)(param_2 + 0xc);
      if (param_2 == 0) {
        return iVar5;
      }
    }
  }
  else {
    if (iVar5 == 7) {
      piVar1 = (int *)(param_2 + 0x14);
      param_2 = 0;
      if (*piVar1 != 0) {
        do {
          local_8 = FUN_005b31d8(param_1,*(undefined4 *)(iVar2 + 0x10),piVar3,piVar4);
          if (local_8 < 0) {
            return local_8;
          }
          param_2 = param_2 + 1;
        } while (param_2 < *(uint *)(iVar2 + 0x14));
      }
      *piVar4 = *(int *)(iVar2 + 0x14) * *piVar3 * *piVar4;
      *piVar3 = 1;
      return local_8;
    }
    if ((iVar5 == 8) && (iVar5 = *(int *)(param_2 + 0x10), -1 < iVar5)) {
      if (iVar5 < 3) {
        *param_3 = *(int *)(param_2 + 0x18);
        iVar5 = *(int *)(param_2 + 0x1c);
      }
      else {
        if (iVar5 != 3) {
          return -0x7fffbffb;
        }
        iVar5 = 1;
        *param_3 = 1;
      }
      *param_4 = iVar5;
      iVar5 = *param_3;
      param_3 = (int *)0x0;
      if (iVar5 * *param_4 == 0) {
        return 0;
      }
      do {
        iVar5 = *(int *)(*param_1 + 8);
        *(undefined4 *)(iVar5 + 0x10) = 0;
        *(undefined4 *)(iVar5 + 0x14) = 0;
        *(undefined4 *)(iVar5 + 0x18) = 0;
        *(undefined4 *)(iVar5 + 0x1c) = 0;
        switch(*(undefined4 *)(param_2 + 0x14)) {
        case 0:
          *(undefined4 *)(*(int *)(*param_1 + 8) + 0x10) = 0;
          break;
        case 1:
        case 2:
        case 3:
        case 4:
          *(undefined4 *)(*(int *)(*param_1 + 8) + 0x10) = 1;
          break;
        case 5:
        case 6:
        case 7:
        case 8:
          *(undefined4 *)(*(int *)(*param_1 + 8) + 0x10) = 2;
          break;
        case 9:
        case 10:
        case 0xb:
        case 0xc:
          *(undefined4 *)(*(int *)(*param_1 + 8) + 0x10) = 3;
          break;
        case 0xd:
        case 0xe:
        case 0xf:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x19:
        case 0x1a:
        case 0x1b:
        case 0x1c:
          *(undefined4 *)(*(int *)(*param_1 + 8) + 0x10) = 5;
          break;
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
          *(undefined4 *)(*(int *)(*param_1 + 8) + 0x10) = 4;
          break;
        default:
          goto LAB_005b338c;
        }
        param_3 = (int *)((int)param_3 + 1);
        *param_1 = *(int *)(*param_1 + 0xc);
        if ((uint)(*piVar3 * *param_4) <= param_3) {
          return 0;
        }
      } while( true );
    }
  }
LAB_005b338c:
  return -0x7fffbffb;
}


// ==== 0x5b33cb FUN_005b33cb

int FUN_005b33cb(uint param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  int local_8;
  
  local_18 = *(undefined4 *)(param_2 + 0x40);
  local_8 = 0;
  local_c = (undefined4 *)0x0;
  local_10 = (undefined4 *)0x0;
  uVar1 = FUN_005b30af(param_1,&local_18,&local_14);
  *(undefined4 *)(param_2 + 0x14) = uVar1;
  if (*(int *)(*(int *)(param_2 + 0x2c) + 0x28) == 0) {
    pvVar2 = _malloc(0x50);
    if (pvVar2 == (void *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = (undefined4 *)FUN_005d87f4();
    }
    if (puVar3 != (undefined4 *)0x0) {
      iVar4 = (**(code **)(**(int **)(*(int *)(param_2 + 0x2c) + 0x20) + 8))();
      puVar3[4] = iVar4;
      if (iVar4 != 0) {
        puVar6 = *(undefined4 **)(param_2 + 0x38);
        puVar7 = puVar3 + 0xc;
        for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        param_1 = 0;
        if (local_14 != 0) {
          do {
            pvVar2 = _malloc(0x14);
            if (pvVar2 == (void *)0x0) {
              local_c = (undefined4 *)0x0;
            }
            else {
              local_c = (undefined4 *)FUN_005d78c0();
            }
            puVar6 = local_c;
            if (local_c == (undefined4 *)0x0) {
LAB_005b3503:
              local_8 = -0x7ff8fff2;
              goto LAB_005b3558;
            }
            pvVar2 = _malloc(0x40);
            if (pvVar2 == (void *)0x0) {
              local_10 = (undefined4 *)0x0;
            }
            else {
              local_10 = (undefined4 *)FUN_005d89c9();
            }
            if (local_10 == (undefined4 *)0x0) goto LAB_005b3503;
            param_1 = param_1 + 1;
            puVar6[2] = local_10;
            puVar6[3] = puVar3[8];
            local_10 = (undefined4 *)0x0;
            puVar3[8] = puVar6;
            local_c = (undefined4 *)0x0;
          } while (param_1 < local_14);
        }
        local_1c = puVar3[8];
        local_8 = FUN_005b31d8(&local_1c,*(undefined4 *)(*(int *)(param_2 + 0x2c) + 0x20),puVar3 + 5
                               ,puVar3 + 6);
        if (local_8 < 0) goto LAB_005b3572;
        *(undefined4 **)(*(int *)(param_2 + 0x2c) + 0x28) = puVar3;
        goto LAB_005b34ee;
      }
    }
    local_8 = -0x7ff8fff2;
  }
  else {
LAB_005b34ee:
    puVar3 = (undefined4 *)0x0;
    iVar4 = *(int *)(*(int *)(param_2 + 0x2c) + 0x28);
    if (*(int *)(iVar4 + 4) != 0xc) {
      return -0x7fffbffb;
    }
    while (((iVar5 = iVar4, *(int *)(iVar5 + 0x1c) == 0 &&
            (iVar4 = *(int *)(iVar5 + 0x20), iVar4 != 0)) && (*(int *)(iVar4 + 4) == 1))) {
      iVar4 = *(int *)(iVar4 + 8);
      if ((iVar4 == 0) || (*(int *)(iVar4 + 4) != 0xc)) break;
    }
    if ((*(int *)(iVar5 + 0x1c) == 0) &&
       ((iVar4 = *(int *)(iVar5 + 0x20), iVar4 != 0 && (*(int *)(iVar4 + 4) == 1)))) {
      *(int *)(param_2 + 0x1c) = iVar4;
      return local_8;
    }
    local_8 = -0x7fffbffb;
LAB_005b3558:
    if (local_c != (undefined4 *)0x0) {
      (**(code **)*local_c)(1);
    }
    if (local_10 != (undefined4 *)0x0) {
      (**(code **)*local_10)(1);
    }
  }
LAB_005b3572:
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  return local_8;
}


// ==== 0x5b3588 FUN_005b3588

int __thiscall FUN_005b3588(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = *(int *)(param_2 + 4);
  if (iVar4 == 1) {
    do {
      iVar4 = FUN_005b3588(*(undefined4 *)(*(int *)(*(int *)(param_2 + 8) + 0x18) + 0x20),param_3);
      if (iVar4 < 0) {
        return iVar4;
      }
      param_2 = *(int *)(param_2 + 0xc);
    } while (param_2 != 0);
    return iVar4;
  }
  if (iVar4 == 7) {
    uVar5 = 0;
    if (*(int *)(param_2 + 0x14) == 0) {
      return 0;
    }
    do {
      iVar4 = FUN_005b3588(*(undefined4 *)(param_2 + 0x10),param_3);
      if (iVar4 < 0) {
        return iVar4;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_2 + 0x14));
    return iVar4;
  }
  if ((iVar4 == 8) && (iVar4 = *(int *)(param_2 + 0x10), -1 < iVar4)) {
    if (iVar4 < 3) {
      iVar4 = *(int *)(param_2 + 0x1c) * *(int *)(param_2 + 0x18);
    }
    else {
      if (iVar4 != 3) goto switchD_005b35da_default;
      iVar4 = 1;
    }
    switch(*(undefined4 *)(param_2 + 0x14)) {
    case 0xe:
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x19:
    case 0x1a:
      piVar1 = (int *)(param_1 + 0x108);
      *(int *)*param_3 = *piVar1;
      *piVar1 = *piVar1 + 1;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0x1b:
    case 0x1c:
      iVar3 = 4;
      break;
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
      iVar3 = 0;
      break;
    default:
      goto switchD_005b35da_default;
    }
    iVar2 = 0;
    *param_3 = *param_3 + iVar3 * iVar4;
  }
  else {
switchD_005b35da_default:
    iVar2 = -0x7fffbffb;
  }
  return iVar2;
}


// ==== 0x5b3675 FUN_005b3675

int __thiscall
FUN_005b3675(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            int param_7,int param_8,int param_9)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar4 = param_2;
  iVar3 = *(int *)(param_2 + 4);
  local_c = 0;
  local_8 = 5;
  local_10 = 0;
  if (iVar3 == 1) {
    iVar3 = FUN_005b2b74(&local_c,4,param_8);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = FUN_005b2b74(&local_8,4,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    param_8 = 0;
    iVar3 = iVar4;
    do {
      iVar3 = *(int *)(iVar3 + 0xc);
      param_8 = param_8 + 1;
    } while (iVar3 != 0);
    param_2 = iVar4;
    if ((param_3 == 0) || (param_7 == 0)) {
      iVar3 = FUN_005b2b74(&local_10,4,0);
    }
    else {
      iVar3 = FUN_005b2c29(*(undefined4 *)(param_3 + 8),&param_3);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar3 = FUN_005b2c79(param_3,0);
    }
    if (iVar3 < 0) {
      return iVar3;
    }
    if ((param_4 == 0) || (param_7 == 0)) {
      iVar3 = FUN_005b2b74(&local_10,4,0);
    }
    else {
      iVar3 = FUN_005b2c29(param_4,&param_3);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar3 = FUN_005b2c79(param_3,0);
    }
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = FUN_005b2b74(&param_5,4,0);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar4 = FUN_005b2b74(&param_8,4,0);
    iVar3 = param_2;
    if (iVar4 < 0) {
      return iVar4;
    }
    do {
      if (iVar3 == 0) {
        return iVar4;
      }
      if ((((((*(int *)(iVar3 + 4) != 1) || (iVar4 = *(int *)(iVar3 + 8), iVar4 == 0)) ||
            (*(int *)(iVar4 + 4) != 5)) ||
           (((iVar1 = *(int *)(iVar4 + 0x14), iVar1 == 0 || (*(int *)(iVar1 + 4) != 2)) ||
            ((*(int *)(iVar1 + 0x10) != 9 ||
             ((*(int *)(iVar1 + 0x18) == 0 || (*(int *)(iVar4 + 0x10) != 1)))))))) ||
          (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) ||
         ((*(int *)(iVar4 + 4) != 10 || (*(int *)(iVar4 + 0x20) == 0))))
      goto switchD_005b371b_default;
      iVar2 = *(int *)(iVar4 + 0x2c);
      uVar5 = 0;
      if (iVar2 != 0) {
        if ((*(int *)(iVar2 + 4) != 2) || (*(int *)(iVar2 + 0x10) != 9))
        goto switchD_005b371b_default;
        uVar5 = *(undefined4 *)(iVar2 + 0x18);
      }
      iVar4 = FUN_005b3675(*(int *)(iVar4 + 0x20),(int *)(iVar1 + 0x10),uVar5,0,param_6,param_7,0,1)
      ;
      if (iVar4 < 0) {
        return iVar4;
      }
      iVar3 = *(int *)(iVar3 + 0xc);
    } while( true );
  }
  if (iVar3 == 7) {
    iVar3 = param_5;
    if (param_5 == 0) {
      iVar3 = 1;
    }
    iVar3 = FUN_005b3675(*(undefined4 *)(param_2 + 0x10),param_3,param_4,
                         *(int *)(param_2 + 0x14) * iVar3,param_6,param_7,param_8,0);
    return iVar3;
  }
  if (iVar3 != 8) goto switchD_005b371b_default;
  iVar3 = *(int *)(param_2 + 0x10);
  if (iVar3 != 0) {
    if (iVar3 == 1) {
      local_8 = *(undefined4 *)(param_2 + 0x1c);
      local_c = *(undefined4 *)(param_2 + 0x18);
      param_9 = 1;
      goto LAB_005b370f;
    }
    if (iVar3 == 2) {
      local_8 = *(undefined4 *)(param_2 + 0x18);
      local_c = *(undefined4 *)(param_2 + 0x1c);
      param_9 = 2;
      goto LAB_005b370f;
    }
    if (iVar3 != 3) goto switchD_005b371b_default;
    if (param_9 == 0) {
      param_9 = 4;
      local_8 = 0;
      local_c = 0;
      goto LAB_005b370f;
    }
    pcVar6 = "ID3DXEffectCompiler: Only numeric types are allowed inside structures";
    goto LAB_005b38d1;
  }
  param_9 = 0;
  local_8 = 1;
  local_c = 1;
LAB_005b370f:
  switch(*(undefined4 *)(param_2 + 0x14)) {
  case 0:
    param_2 = 1;
    goto LAB_005b3725;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 0xd:
    param_2 = 2;
    goto LAB_005b3725;
  case 9:
  case 10:
  case 0xb:
  case 0xc:
    param_2 = 3;
    goto LAB_005b3725;
  case 0xe:
    param_2 = 4;
    goto LAB_005b3725;
  case 0xf:
    param_2 = 5;
    break;
  case 0x10:
    param_2 = 6;
    break;
  case 0x11:
    param_2 = 7;
    break;
  case 0x12:
    param_2 = 8;
    break;
  case 0x13:
    param_2 = 9;
    break;
  case 0x14:
    param_2 = 10;
    break;
  case 0x15:
    param_2 = 0xb;
    break;
  case 0x16:
    param_2 = 0xc;
    break;
  case 0x17:
    param_2 = 0xd;
    break;
  case 0x18:
    param_2 = 0xe;
    break;
  case 0x19:
    param_2 = 0xf;
    goto LAB_005b3725;
  case 0x1a:
    param_2 = 0x10;
    goto LAB_005b3725;
  case 0x1b:
    param_2 = 0x11;
    break;
  case 0x1c:
    param_2 = 0x12;
    break;
  default:
    goto switchD_005b371b_default;
  }
  if (param_5 == 0) {
LAB_005b3725:
    iVar3 = FUN_005b2b74(&param_2,4,param_8);
    if ((-1 < iVar3) && (iVar3 = FUN_005b2b74(&param_9,4,0), iVar4 = param_7, -1 < iVar3)) {
      if ((param_3 == 0) || (param_7 == 0)) {
        iVar3 = FUN_005b2b74(&local_10,4,0);
      }
      else {
        iVar3 = FUN_005b2c29(*(undefined4 *)(param_3 + 8),&param_3);
        if (iVar3 < 0) {
          return iVar3;
        }
        iVar3 = FUN_005b2c79(param_3,0);
      }
      if (-1 < iVar3) {
        if ((param_4 == 0) || (iVar4 == 0)) {
          iVar3 = FUN_005b2b74(&local_10,4,0);
        }
        else {
          iVar3 = FUN_005b2c29(param_4,&param_3);
          if (iVar3 < 0) {
            return iVar3;
          }
          iVar3 = FUN_005b2c79(param_3,0);
        }
        if ((((-1 < iVar3) && (iVar3 = FUN_005b2b74(&param_5,4,0), -1 < iVar3)) && (0 < param_2)) &&
           ((param_2 < 4 && (iVar3 = FUN_005b2b74(&local_8,4,0), -1 < iVar3)))) {
          iVar3 = FUN_005b2b74(&local_c,4,0);
        }
      }
    }
  }
  else {
    pcVar6 = "ID3DXEffectCompiler: Arrays must be either numeric, structure, string or shader";
LAB_005b38d1:
    FUN_005b1f01(param_1 + 0xc,param_3,0,pcVar6);
switchD_005b371b_default:
    iVar3 = -0x7fffbffb;
  }
  return iVar3;
}


// ==== 0x5b3b78 FUN_005b3b78

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
FUN_005b3b78(int param_1,int param_2,int param_3,int param_4,int *param_5,undefined4 param_6,
            undefined4 param_7,undefined *param_8)

{
  int iVar1;
  float fVar2;
  bool bVar3;
  int iVar4;
  undefined **ppuVar5;
  int iVar6;
  undefined *puVar7;
  float fVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  float *pfVar14;
  uint uVar15;
  bool bVar16;
  float10 fVar17;
  float10 fVar18;
  float10 fVar19;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar20;
  float10 extraout_ST0_01;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  char *pcVar21;
  undefined *puVar22;
  undefined **local_4c;
  int *local_44;
  undefined *local_40;
  int local_3c;
  int local_38;
  undefined **local_34;
  float *local_30;
  int local_2c;
  int local_28;
  size_t local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined *local_c;
  int local_8;
  
  iVar13 = 0;
  local_3c = 0;
  local_30 = (float *)0x0;
  local_44 = (int *)0x0;
  local_2c = 0;
  bVar3 = false;
  ppuVar5 = &PTR_s_ZENABLE_006d5660;
  if (param_8 != (undefined *)0xffffffff) {
    ppuVar5 = &PTR_s_TEXTURE_006d4da8;
  }
  puVar22 = *ppuVar5;
  iVar10 = *(int *)(param_2 + 8);
  iVar9 = *(int *)(iVar10 + 0x10);
  local_18 = 0;
  local_1c = iVar9;
  local_34 = ppuVar5;
  local_8 = param_1;
  while ((puVar22 != (undefined *)0x0 &&
         (iVar6 = lstrcmpiA(*ppuVar5,*(LPCSTR *)(iVar9 + 0x18)), iVar6 != 0))) {
    local_18 = local_18 + 1;
    ppuVar5 = ppuVar5 + 7;
    puVar22 = *ppuVar5;
  }
  ppuVar5 = local_34 + local_18 * 7;
  puVar22 = *ppuVar5;
  if (puVar22 == (undefined *)0x0) {
    pcVar21 = "ID3DXEffectCompiler: Unrecognized state \'%s\'";
    puVar22 = *(undefined **)(iVar9 + 0x18);
    goto LAB_005b4bec;
  }
  local_40 = (undefined *)0x0;
  if (*(int *)(iVar10 + 0x14) == 0) {
    if (ppuVar5[4] != (undefined *)0x1) {
      pcVar21 = "ID3DXEffectCompiler: Index is required for state \'%s\'";
      goto LAB_005b4bec;
    }
  }
  else {
    puVar7 = ppuVar5[4];
    if (puVar7 == (undefined *)0x1) {
      pcVar21 = "ID3DXEffectCompiler: State \'%s\' is not indexed";
      goto LAB_005b4bec;
    }
    local_40 = *(undefined **)(*(int *)(iVar10 + 0x14) + 0x18);
    if ((puVar7 != (undefined *)0x0) && (puVar7 <= local_40)) {
      puVar7 = puVar7 + -1;
      pcVar21 = "ID3DXEffectCompiler: Max index for effect state \'%s\' is %d";
LAB_005b3c43:
      FUN_005b1f01(local_8 + 0xc,iVar9 + 0x10,0,pcVar21,puVar22,puVar7);
      return -0x7fffbffb;
    }
  }
  if (param_8 != (undefined *)0xffffffff) {
    local_18 = 0;
    local_34 = &PTR_s_ZENABLE_006d5660;
    if (PTR_s_ZENABLE_006d5660 != (undefined *)0x0) {
      local_4c = &PTR_s_ZENABLE_006d5660;
      do {
        iVar6 = lstrcmpiA(*local_4c,*(LPCSTR *)(iVar9 + 0x18));
        if (iVar6 == 0) break;
        local_18 = local_18 + 1;
        local_4c = local_4c + 7;
      } while (*local_4c != (undefined *)0x0);
    }
    local_40 = param_8;
  }
  iVar6 = local_8;
  iVar4 = local_18;
  if (*(int *)(&DAT_006d5670 + local_18 * 0x1c) == 0x105) {
    if ((((local_40 < (undefined *)0x10) || (local_40 == (undefined *)0x101)) ||
        (local_40 == (undefined *)0x102)) ||
       ((local_40 == (undefined *)0x103 || (local_40 == (undefined *)0x104)))) {
      if ((&DAT_006d5674)[local_18 * 7] == 0x800000d) {
        pcVar21 = 
        "ID3DXEffectCompiler: DMAPOFFSET sampler state can only be used with D3DDMAPSAMPLER (i.e. sampler index 256)"
        ;
        goto LAB_005b3d19;
      }
    }
    else if (local_40 != (undefined *)0x100) {
      pcVar21 = "ID3DXEffectCompiler: Invalid sampler index %d";
      puVar22 = local_40;
      goto LAB_005b4bec;
    }
  }
  iVar1 = *(int *)(iVar10 + 0x18);
  if (*(int *)(iVar1 + 4) == 1) {
    iVar6 = *(int *)(iVar1 + 8);
    if (iVar6 == 0) {
      return -0x7fffbffb;
    }
    if (*(int *)(iVar6 + 4) == 2) {
      if ((*(int *)(iVar6 + 0x10) < 5) || (local_c = (undefined *)0x3, 8 < *(int *)(iVar6 + 0x10)))
      {
        local_c = (undefined *)0x2;
      }
      local_10 = 1;
      local_24 = 4;
    }
    else {
      if (*(int *)(iVar6 + 4) != 0xc) goto LAB_005b3d34;
      iVar6 = 0;
      for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
        if (*(int *)(iVar1 + 4) != 1) {
          return -0x7fffbffb;
        }
        iVar13 = *(int *)(iVar1 + 8);
        if (iVar13 == 0) {
          return -0x7fffbffb;
        }
        if (*(int *)(iVar13 + 4) != 0xc) {
          return -0x7fffbffb;
        }
        if (*(int *)(iVar13 + 0x10) == 0) {
          return -0x7fffbffb;
        }
        local_3c = FUN_005b2d7a(*(int *)(iVar13 + 0x10),&local_c,&local_10,&local_14,&local_28,
                                &local_20,&local_24);
        if (local_3c < 0) {
          return local_3c;
        }
        if ((((local_c != (undefined *)0x3) && (local_c != (undefined *)0x2)) &&
            (local_c != (undefined *)0x1)) ||
           (((local_14 != 1 || (local_10 != 1)) || ((local_28 != 0 || (local_20 != 0)))))) {
          pcVar21 = "ID3DXEffectCompiler: Initializers must be numeric scalars";
          iVar6 = local_8;
          goto LAB_005b3d19;
        }
        iVar6 = iVar6 + 1;
        iVar13 = local_3c;
      }
      if ((local_34[iVar4 * 7 + 1] == (undefined *)0x3) ||
         (local_c = (undefined *)0x2, local_34[iVar4 * 7 + 1] == (undefined *)0xf20000)) {
        local_c = (undefined *)0x3;
      }
      local_24 = iVar6 << 2;
      local_10 = iVar6;
    }
    local_14 = 1;
    local_20 = 0;
    local_28 = 0;
  }
  else {
    if (*(int *)(iVar1 + 4) != 0xc) {
LAB_005b3d34:
      puVar22 = local_34[local_18 * 7];
      pcVar21 = "ID3DXEffectCompiler: State \'%s\' was assigned an unsupported value";
      goto LAB_005b4bec;
    }
    iVar13 = FUN_005b2d7a(*(undefined4 *)(iVar1 + 0x10),&local_c,&local_10,&local_14,&local_28,
                          &local_20,&local_24);
    if (iVar13 < 0) {
      return iVar13;
    }
    local_3c = iVar13;
    if (local_c == (undefined *)0x0) {
      pcVar21 = "ID3DXEffectCompiler: Assignment cannot be a structure";
      goto LAB_005b3d19;
    }
  }
  ppuVar5 = local_34 + iVar4 * 7;
  puVar22 = ppuVar5[1];
  if ((int)puVar22 < 0xb) {
    if (puVar22 == (undefined *)0xa) {
      if ((local_28 != 0) || (local_20 != 0)) {
LAB_005b4bdf:
        puVar22 = *ppuVar5;
        pcVar21 = "ID3DXEffectCompiler: State \'%s\' cannot be assigned an array or structure";
        goto LAB_005b4bec;
      }
      if (((local_10 != 1) || (local_14 != 1)) ||
         ((local_c != (undefined *)0xa &&
          ((((local_c != (undefined *)0xb && (local_c != (undefined *)0xc)) &&
            (local_c != (undefined *)0xd)) &&
           ((local_c != (undefined *)0xe && (local_c != (undefined *)0x2)))))))) {
        puVar22 = *ppuVar5;
        pcVar21 = "ID3DXEffectCompiler: State \'%s\' was not assigned a sampler type";
        goto LAB_005b4bec;
      }
    }
    else {
      if ((int)puVar22 < 1) goto LAB_005b4c02;
      if ((int)puVar22 < 3) goto LAB_005b403d;
      if (puVar22 != (undefined *)0x3) {
        if (puVar22 == (undefined *)0x5) {
          if ((local_28 != 0) || (local_20 != 0)) goto LAB_005b4bdf;
          if (((local_10 != 1) || (local_14 != 1)) ||
             (((((local_c != (undefined *)0x5 && (local_c != (undefined *)0x6)) &&
                (local_c != (undefined *)0x7)) &&
               ((local_c != (undefined *)0x8 && (local_c != (undefined *)0x9)))) &&
              (local_c != (undefined *)0x2)))) {
            puVar22 = *ppuVar5;
            pcVar21 = "ID3DXEffectCompiler: State \'%s\' was not assigned a texture type";
            goto LAB_005b4bec;
          }
          goto LAB_005b415d;
        }
        goto LAB_005b4c02;
      }
      puVar22 = ppuVar5[5];
      if (puVar22 < (undefined *)0x6000206) {
        if (puVar22 != (undefined *)0x6000205) {
          if (puVar22 < (undefined *)0x6000002) goto LAB_005b3fcb;
          if ((((undefined *)0x6000007 < puVar22) && (puVar22 != (undefined *)0x6000102)) &&
             (puVar22 != (undefined *)0x6000105)) {
            bVar16 = puVar22 == (undefined *)0x6000202;
            goto LAB_005b3fc9;
          }
        }
LAB_005b403d:
        if (local_20 != 0) goto LAB_005b415d;
      }
      else {
        if (((puVar22 == (undefined *)0x6000302) || (puVar22 == (undefined *)0x6000305)) ||
           (puVar22 == (undefined *)0x6000402)) goto LAB_005b403d;
        bVar16 = puVar22 == (undefined *)0x6000405;
LAB_005b3fc9:
        if (bVar16) goto LAB_005b403d;
LAB_005b3fcb:
        if (ppuVar5[2] != (undefined *)0x1) goto LAB_005b403d;
        puVar22 = ppuVar5[3];
        if (puVar22 != (undefined *)0x1) {
          if (((undefined *)0x2 < puVar22) && (puVar22 < (undefined *)0x5)) {
            if (((local_14 == 1) && ((local_10 == 3 || (local_10 == 4)))) &&
               ((local_28 == 0 && (local_20 == 0)))) goto LAB_005b404a;
            if (((local_c != (undefined *)0x2) || (local_10 != 1)) || (local_14 != 1)) {
              puVar22 = *ppuVar5;
              pcVar21 = 
              "ID3DXEffectCompiler: State \'%s\' must be assigned a 3-vector or a 4-vector or a uint scalar"
              ;
              goto LAB_005b4bec;
            }
          }
          goto LAB_005b403d;
        }
        if (((local_10 != 1) || (local_14 != 1)) || ((local_28 != 0 || (local_20 != 0)))) {
          puVar22 = *ppuVar5;
          pcVar21 = "ID3DXEffectCompiler: State \'%s\' must be assigned a scalar";
          goto LAB_005b4bec;
        }
      }
LAB_005b404a:
      if (((local_c != (undefined *)0x3) && (local_c != (undefined *)0x2)) &&
         (local_c != (undefined *)0x1)) {
        puVar22 = *ppuVar5;
        pcVar21 = "ID3DXEffectCompiler: State \'%s\' must be assigned a numeric value";
        goto LAB_005b4bec;
      }
    }
LAB_005b415d:
    if (iVar13 < 0) {
      FUN_005b1f01(local_8 + 0xc,iVar9 + 0x10,0,
                   "ID3DXEffectCompiler: State \'%s\' was assigned an expression of incompatible type"
                   ,*ppuVar5);
      return iVar13;
    }
    while (param_2 = *(int *)(param_2 + 0xc), param_2 != 0) {
      iVar9 = *(int *)(param_2 + 8);
      iVar6 = lstrcmpiA(*ppuVar5,*(LPCSTR *)(*(int *)(iVar9 + 0x10) + 0x18));
      if (iVar6 == 0) {
        if (param_8 != (undefined *)0xffffffff) {
          return iVar13;
        }
        iVar9 = *(int *)(iVar9 + 0x14);
        if (iVar9 == 0) {
          return iVar13;
        }
        if (local_40 == *(undefined **)(iVar9 + 0x18)) {
          return iVar13;
        }
      }
    }
    iVar9 = *(int *)(iVar10 + 0x18);
    if (*(int *)(iVar9 + 4) == 1) {
      iVar6 = *(int *)(iVar9 + 8);
      if (iVar6 == 0) {
        return -0x7fffbffb;
      }
      if (*(int *)(iVar6 + 4) == 2) {
        if ((*(int *)(iVar6 + 0x10) < 5) || (8 < *(int *)(iVar6 + 0x10))) {
          param_8 = (undefined *)0x0;
          for (param_2 = iVar9; iVar9 = local_1c, param_2 != 0; param_2 = *(int *)(param_2 + 0xc)) {
            if (*(int *)(param_2 + 4) != 1) {
              return -0x7fffbffb;
            }
            iVar13 = *(int *)(param_2 + 8);
            if (iVar13 == 0) {
              return -0x7fffbffb;
            }
            if (*(int *)(iVar13 + 4) != 2) {
              return -0x7fffbffb;
            }
            iVar6 = *(int *)(iVar13 + 0x10);
            if (iVar6 < 2) {
LAB_005b4a60:
              pcVar21 = "ID3DXEffectCompiler: State \'%s\' accepts only dwords and ids";
              puVar22 = *ppuVar5;
              goto LAB_005b4bec;
            }
            if (iVar6 < 5) {
              uVar11 = *(uint *)(iVar13 + 0x18);
            }
            else {
              if (iVar6 != 9) goto LAB_005b4a60;
              if (*(int *)(iVar13 + 0x18) == 0) {
                return -0x7fffbffb;
              }
              piVar12 = (int *)ppuVar5[6];
              if (piVar12 == (int *)0x0) {
                puVar7 = *(undefined **)(iVar13 + 0x18);
                puVar22 = *ppuVar5;
                pcVar21 = "ID3DXEffectCompiler: State \'%s\' does not accept \'%s\' as a value";
                goto LAB_005b3c43;
              }
              iVar6 = 0;
              iVar9 = *piVar12;
              while ((iVar9 != 0 &&
                     (iVar9 = lstrcmpiA((LPCSTR)piVar12[iVar6 * 2],*(LPCSTR *)(iVar13 + 0x18)),
                     iVar9 != 0))) {
                piVar12 = (int *)ppuVar5[6];
                iVar6 = iVar6 + 1;
                iVar9 = piVar12[iVar6 * 2];
              }
              if (*(int *)(ppuVar5[6] + iVar6 * 8) == 0) {
                FUN_005b1f01(local_8 + 0xc,local_1c + 0x10,0,
                             "ID3DXEffectCompiler: State \'%s\' does not accept \'%s\' as a value",
                             *ppuVar5,*(undefined4 *)(iVar13 + 0x18));
                return -0x7fffbffb;
              }
              uVar11 = *(uint *)((int)(ppuVar5[6] + iVar6 * 8) + 4);
            }
            param_8 = (undefined *)((uint)param_8 | uVar11);
            iVar13 = local_3c;
          }
          puVar22 = ppuVar5[5];
          if (puVar22 == (undefined *)0x5000000) {
LAB_005b4abb:
            if (param_8 != (undefined *)0x0) {
              pcVar21 = 
              "ID3DXEffectCompiler: Dword expressions for state \'%s\' must be evaluate to NULL";
              puVar22 = *ppuVar5;
LAB_005b4bec:
              FUN_005b1f01(local_8 + 0xc,iVar9 + 0x10,0,pcVar21,puVar22);
              return -0x7fffbffb;
            }
          }
          else if (puVar22 == (undefined *)0x6000000) {
            if (param_8 != (undefined *)0x0) {
              puVar22 = *local_34;
              local_18 = 0;
              ppuVar5 = local_34;
              while ((puVar22 != (undefined *)0x0 && (ppuVar5[5] != (undefined *)0x6000008))) {
                local_18 = local_18 + 1;
                ppuVar5 = ppuVar5 + 7;
                puVar22 = *ppuVar5;
              }
              bVar3 = true;
            }
          }
          else {
            if (puVar22 == (undefined *)0x6000001) goto LAB_005b4abb;
            if (puVar22 == (undefined *)0x6000008) {
              if (param_8 == (undefined *)0x0) {
                pcVar21 = "ID3DXEffectCompiler: FVFs must not evaluate to NULL";
                param_2 = 0;
                param_8 = (undefined *)0x0;
                iVar6 = local_8;
LAB_005b3d19:
                FUN_005b1f01(iVar6 + 0xc,iVar9 + 0x10,0,pcVar21);
                return -0x7fffbffb;
              }
            }
            else if (puVar22 == (undefined *)0x9000000) {
              return iVar13;
            }
          }
          iVar13 = FUN_005b2b74(&param_8,4,&param_2);
          if (iVar13 < 0) {
            return iVar13;
          }
        }
        else {
          param_8 = (undefined *)(float)*(double *)(iVar6 + 0x18);
          iVar13 = FUN_005b2b74(&param_8,4,&param_2);
          if (iVar13 < 0) {
            return iVar13;
          }
        }
      }
      else if (*(int *)(iVar6 + 4) == 0xc) {
        local_30 = _malloc(local_24);
        if (local_30 == (float *)0x0) {
LAB_005b459f:
          iVar13 = -0x7ff8fff2;
          goto LAB_005b4c33;
        }
        pfVar14 = local_30;
        for (uVar11 = local_24 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
          *pfVar14 = 0.0;
          pfVar14 = pfVar14 + 1;
        }
        for (uVar11 = local_24 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
          *(undefined1 *)pfVar14 = 0;
          pfVar14 = (float *)((int)pfVar14 + 1);
        }
        pfVar14 = local_30;
        for (param_2 = *(int *)(iVar10 + 0x18); param_2 != 0; param_2 = *(int *)(param_2 + 0xc)) {
          if (((*(int *)(param_2 + 4) != 1) || (iVar13 = *(int *)(param_2 + 8), iVar13 == 0)) ||
             (*(int *)(iVar13 + 4) != 0xc)) goto LAB_005b4798;
          param_8 = (undefined *)0x0;
          if (((*(int *)(iVar13 + 0x1c) == 5) && (iVar9 = *(int *)(iVar13 + 0x20), iVar9 != 0)) &&
             (*(int *)(iVar9 + 4) == 0xc)) {
            param_8 = (undefined *)0x1;
            while ((iVar13 = iVar9, *(int *)(iVar13 + 0x1c) == 0 &&
                   (iVar9 = *(int *)(iVar13 + 0x20), iVar9 != 0))) {
              if ((*(int *)(iVar9 + 4) != 1) ||
                 ((iVar9 = *(int *)(iVar9 + 8), iVar9 == 0 || (*(int *)(iVar9 + 4) != 0xc)))) break;
            }
          }
          if ((*(int *)(iVar13 + 0x1c) != 0) ||
             ((((iVar13 = *(int *)(iVar13 + 0x20), iVar13 == 0 || (*(int *)(iVar13 + 4) != 1)) ||
               (iVar13 = *(int *)(iVar13 + 8), iVar13 == 0)) ||
              ((*(int *)(iVar13 + 4) != 0xd || (*(int *)(iVar13 + 0x10) == 6)))))) {
            pcVar21 = 
            "ID3DXEffectCompiler: Initializer list elements cannot be complex expressions or variables"
            ;
LAB_005b4781:
            FUN_005b1f01(local_8 + 0xc,local_1c + 0x10,0,pcVar21);
            goto LAB_005b4798;
          }
          puVar22 = ppuVar5[1];
          if ((int)puVar22 < 1) {
LAB_005b4775:
            pcVar21 = "ID3DXEffectCompiler: Error in type checking";
            goto LAB_005b4781;
          }
          if ((int)puVar22 < 3) {
            iVar9 = *(int *)(iVar13 + 0x10);
            if (iVar9 == 0) {
              *pfVar14 = (float)(uint)(*(int *)(iVar13 + 0x18) != 0);
            }
            else if ((iVar9 == 1) || (iVar9 == 2)) {
              *pfVar14 = *(float *)(iVar13 + 0x18);
            }
            else {
              if (iVar9 != 3) {
LAB_005b476e:
                pcVar21 = "ID3DXEffectCompiler: Unexpected error";
                goto LAB_005b4781;
              }
              fVar8 = (float)__ftol();
              *pfVar14 = fVar8;
            }
            if (param_8 != (undefined *)0x0) {
              *pfVar14 = (float)-(int)*pfVar14;
            }
          }
          else {
            if ((puVar22 != (undefined *)0x3) && (puVar22 != (undefined *)0xf20000))
            goto LAB_005b4775;
            iVar9 = *(int *)(iVar13 + 0x10);
            if (iVar9 == 0) {
              fVar8 = (float)(*(int *)(iVar13 + 0x18) != 0);
            }
            else if (iVar9 == 1) {
              fVar8 = (float)*(int *)(iVar13 + 0x18);
            }
            else if (iVar9 == 2) {
              fVar8 = (float)*(int *)(iVar13 + 0x18);
              if (*(int *)(iVar13 + 0x18) < 0) {
                fVar8 = fVar8 + 4.2949673e+09;
              }
            }
            else {
              if (iVar9 != 3) goto LAB_005b476e;
              fVar8 = (float)*(double *)(iVar13 + 0x18);
            }
            *pfVar14 = fVar8;
            if (param_8 != (undefined *)0x0) {
              *pfVar14 = -*pfVar14;
            }
          }
          pfVar14 = pfVar14 + 1;
        }
        if (ppuVar5[1] == (undefined *)0xf20000) {
          fVar17 = (float10)local_30[3];
          fVar18 = (float10)_K_ONE;
          fVar8 = local_30[1];
          fVar2 = local_30[2];
          fVar19 = (float10)0.0;
          if ((float10)*local_30 < fVar18) {
            fVar20 = (float10)*local_30;
            if (fVar20 < fVar19 == (fVar20 == fVar19)) {
              fVar17 = fVar18;
              param_8 = (undefined *)__ftol();
              fVar19 = extraout_ST0;
              fVar18 = extraout_ST1;
            }
            else {
              param_8 = (undefined *)0x0;
            }
          }
          else {
            param_8 = (undefined *)0xff;
          }
          if ((float10)fVar8 < fVar18) {
            fVar20 = (float10)fVar8;
            if (fVar20 < fVar19 == (fVar20 == fVar19)) {
              fVar17 = fVar18;
              uVar11 = __ftol();
              fVar19 = extraout_ST0_00;
              fVar18 = extraout_ST1_00;
            }
            else {
              uVar11 = 0;
            }
          }
          else {
            uVar11 = 0xff;
          }
          if ((float10)fVar2 < fVar18) {
            fVar20 = (float10)fVar2;
            if (fVar20 < fVar19 == (fVar20 == fVar19)) {
              uVar15 = __ftol();
              fVar18 = extraout_ST0_01;
              fVar17 = extraout_ST1_01;
            }
            else {
              uVar15 = 0;
            }
          }
          else {
            uVar15 = 0xff;
          }
          if (fVar17 < fVar18) {
            if (fVar17 < (float10)0.0 == (fVar17 == (float10)0.0)) {
              iVar13 = __ftol();
            }
            else {
              iVar13 = 0;
            }
          }
          else {
            iVar13 = 0xff;
          }
          param_8 = (undefined *)(((iVar13 << 8 | (uint)param_8) << 8 | uVar11) << 8 | uVar15);
          local_10 = 1;
          local_14 = 1;
          local_24 = 4;
          local_c = (undefined *)0x2;
          iVar13 = FUN_005b2b74(&param_8,4,&param_2);
        }
        else {
          iVar13 = FUN_005b2b74(local_30,local_24,&param_2);
        }
        if (iVar13 < 0) goto LAB_005b4c33;
        _free(local_30);
        local_30 = (float *)0x0;
      }
    }
    else {
      if (*(int *)(iVar9 + 4) != 0xc) {
        pcVar21 = "ID3DXEffectCompiler: State \'%s\' was assigned an unsupported value";
        param_2 = 0;
        puVar22 = *ppuVar5;
        iVar9 = local_1c;
        goto LAB_005b4bec;
      }
      if ((int)local_c < 5) {
LAB_005b4211:
        local_30 = _malloc(local_24);
        if (local_30 == (float *)0x0) goto LAB_005b459f;
        pfVar14 = local_30;
        for (uVar11 = local_24 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
          *pfVar14 = 0.0;
          pfVar14 = pfVar14 + 1;
        }
        for (uVar11 = local_24 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
          *(undefined1 *)pfVar14 = 0;
          pfVar14 = (float *)((int)pfVar14 + 1);
        }
        iVar13 = FUN_005b2b74(local_30,local_24,&param_2);
        if (iVar13 < 0) goto LAB_005b4c33;
      }
      else {
        if (9 < (int)local_c) {
          if ((int)local_c < 0xf) {
            iVar6 = *(int *)(*(int *)(iVar9 + 0x20) + 8);
            if (*(int *)(iVar6 + 0x10) != 6) {
              iVar10 = *(int *)(iVar6 + 0x18);
              param_2 = 0;
              while( true ) {
                if (iVar10 == 0) {
                  return iVar13;
                }
                iVar13 = FUN_005b3b78(iVar10,param_3,param_4,param_5,param_6,param_7,local_40);
                if (iVar13 < 0) break;
                iVar10 = *(int *)(iVar10 + 0xc);
              }
              return iVar13;
            }
            iVar13 = FUN_005b2b74(&local_2c,4,&param_2);
            if (iVar13 < 0) {
              return iVar13;
            }
            goto LAB_005b4256;
          }
          if (0x10 < (int)local_c) goto LAB_005b4211;
        }
        piVar12 = (int *)(local_8 + 0x108);
        iVar13 = FUN_005b2b74(piVar12,4,&param_2);
        if (iVar13 < 0) {
          return iVar13;
        }
        *piVar12 = *piVar12 + 1;
      }
LAB_005b4256:
      local_44 = _malloc(0x20);
      if (local_44 == (int *)0x0) {
        local_44 = (int *)0x0;
      }
      else {
        local_44[5] = 0;
      }
      if (local_44 == (int *)0x0) {
LAB_005b4798:
        iVar13 = -0x7fffbffb;
        goto LAB_005b4c33;
      }
      *local_44 = local_18;
      local_44[1] = param_3;
      local_44[2] = param_4;
      local_44[3] = *param_5;
      local_44[4] = iVar9;
    }
    if (local_c == (undefined *)0x0) {
      iVar10 = FUN_005b3675(*(undefined4 *)(*(int *)(iVar10 + 0x18) + 0x10),0,0,0,param_7,0,
                            &local_38,0);
      if (iVar10 < 0) {
        FUN_005b1f01(local_8 + 0xc,local_1c + 0x10,0,
                     "ID3DXEffectCompiler: Error initializing assignment type");
        goto LAB_005b4c25;
      }
LAB_005b43cf:
      iVar13 = FUN_005b2b74(&local_18,4,0);
      if (((-1 < iVar13) && (iVar13 = FUN_005b2b74(&local_40,4,0), -1 < iVar13)) &&
         ((iVar13 = FUN_005b2c79(local_38,0), -1 < iVar13 &&
          (iVar13 = FUN_005b2c79(param_2,0), -1 < iVar13)))) {
        if (local_44 != (int *)0x0) {
          local_44[7] = local_38;
          local_44[6] = param_2;
          local_44[5] = *(int *)(local_8 + 0x128);
          *(int *)(local_8 + 0x128) = (int)local_44;
          local_44 = (int *)0x0;
        }
        *param_5 = *param_5 + 1;
        if (bVar3) {
          local_c = (undefined *)0x10;
          param_8 = (undefined *)0x4;
          iVar13 = FUN_005b2b74(&local_c,4,&local_38);
          if (((-1 < iVar13) && (iVar13 = FUN_005b2b74(&param_8,4,0), -1 < iVar13)) &&
             ((iVar13 = FUN_005b2b74(&local_2c,4,0), -1 < iVar13 &&
              ((iVar13 = FUN_005b2b74(&local_2c,4,0), -1 < iVar13 &&
               (iVar13 = FUN_005b2b74(&local_2c,4,0), -1 < iVar13)))))) {
            puVar22 = *local_34;
            local_18 = 0;
            ppuVar5 = local_34;
            while ((puVar22 != (undefined *)0x0 && (ppuVar5[5] != (undefined *)0x6000000))) {
              local_18 = local_18 + 1;
              ppuVar5 = ppuVar5 + 7;
              puVar22 = *ppuVar5;
            }
            iVar13 = FUN_005b2b74(&local_18,4,0);
            if ((((-1 < iVar13) && (iVar13 = FUN_005b2b74(&local_2c,4,0), -1 < iVar13)) &&
                (iVar13 = FUN_005b2c79(local_38,0), -1 < iVar13)) &&
               (iVar13 = FUN_005b2b74(&local_2c,4,0), -1 < iVar13)) {
              *param_5 = *param_5 + 1;
            }
          }
        }
      }
    }
    else {
      if ((int)local_c < 1) {
LAB_005b4b72:
        FUN_005b1f01(local_8 + 0xc,local_1c + 0x10,0,"ID3DXEffectCompiler: Internal error");
        goto LAB_005b4c20;
      }
      if ((int)local_c < 4) {
        param_8 = (undefined *)0x2;
        iVar13 = FUN_005b2b74(&local_c,4,&local_38);
        if (((((-1 < iVar13) && (iVar13 = FUN_005b2b74(&param_8,4,0), -1 < iVar13)) &&
             (iVar13 = FUN_005b2b74(&local_2c,4,0), -1 < iVar13)) &&
            ((iVar13 = FUN_005b2b74(&local_2c,4,0), -1 < iVar13 &&
             (iVar13 = FUN_005b2b74(&local_28,4,0), -1 < iVar13)))) &&
           (iVar13 = FUN_005b2b74(&local_10,4,0), -1 < iVar13)) {
          piVar12 = &local_14;
LAB_005b43ba:
          iVar13 = FUN_005b2b74(piVar12,4,0);
          if (-1 < iVar13) goto LAB_005b43cf;
        }
      }
      else {
        if (((int)local_c < 5) || (0x10 < (int)local_c)) goto LAB_005b4b72;
        param_8 = (undefined *)0x4;
        iVar13 = FUN_005b2b74(&local_c,4,&local_38);
        if ((((-1 < iVar13) && (iVar13 = FUN_005b2b74(&param_8,4,0), -1 < iVar13)) &&
            (iVar13 = FUN_005b2b74(&local_2c,4,0), -1 < iVar13)) &&
           (iVar13 = FUN_005b2b74(&local_2c,4,0), -1 < iVar13)) {
          piVar12 = &local_2c;
          goto LAB_005b43ba;
        }
      }
    }
  }
  else {
    if (0xe < (int)puVar22) {
      if ((int)puVar22 < 0x11) {
        if ((local_28 != 0) || (local_20 != 0)) goto LAB_005b4bdf;
        if (((puVar22 != local_c) || ((local_10 != 1 || (local_14 != 1)))) &&
           ((local_c != (undefined *)0x2 || ((local_10 != 1 || (local_14 != 1)))))) {
          puVar22 = *ppuVar5;
          pcVar21 = "ID3DXEffectCompiler: State \'%s\' was assigned an incompatible type";
          goto LAB_005b4bec;
        }
        goto LAB_005b415d;
      }
      if (puVar22 == (undefined *)0xf20000) {
        if (local_c == (undefined *)0x3) {
          if (local_10 != 4) {
LAB_005b4104:
            if (local_10 != 1) goto LAB_005b4110;
          }
          if (local_14 == 1) goto LAB_005b415d;
        }
        else if ((local_c == (undefined *)0x2) || (local_c == (undefined *)0x1)) goto LAB_005b4104;
LAB_005b4110:
        puVar22 = *ppuVar5;
        pcVar21 = 
        "ID3DXEffectCompiler: State \'%s\' must be assigned a numeric scalar or a 4-float vector";
        goto LAB_005b4bec;
      }
    }
LAB_005b4c02:
    FUN_005b1f01(local_8 + 0xc,iVar9 + 0x10,0,
                 "ID3DXEffectCompiler: Unexpected value type of state \'%s\' (internal error)",
                 *ppuVar5);
LAB_005b4c20:
    iVar13 = -0x7fffbffb;
  }
LAB_005b4c25:
  if (local_44 != (int *)0x0) {
    FUN_005b2ae3(1);
  }
LAB_005b4c33:
  if (local_30 != (float *)0x0) {
    _free(local_30);
    return iVar13;
  }
  return iVar13;
}


// ==== 0x5b4c4b FUN_005b4c4b

uint __thiscall FUN_005b4c4b(int param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  int *piVar5;
  byte *pbVar6;
  bool bVar7;
  
  if ((byte *)((uint)param_2 & 0x7fffffff) == param_2) {
    for (uVar2 = *(uint *)(param_1 + 0x120); uVar2 != 0; uVar2 = *(uint *)(uVar2 + 0x34)) {
      if (param_2 == (byte *)0x0) {
        iVar4 = *(int *)(uVar2 + 0x20);
LAB_005b4cc7:
        if (iVar4 == 0) {
          return uVar2;
        }
      }
      else {
        pbVar6 = *(byte **)(uVar2 + 0x20);
        pbVar3 = param_2;
        if (pbVar6 != (byte *)0x0) {
          do {
            bVar1 = *pbVar3;
            bVar7 = bVar1 < *pbVar6;
            if (bVar1 != *pbVar6) {
LAB_005b4cc0:
              iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
              goto LAB_005b4cc7;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar3[1];
            bVar7 = bVar1 < pbVar6[1];
            if (bVar1 != pbVar6[1]) goto LAB_005b4cc0;
            pbVar6 = pbVar6 + 2;
            pbVar3 = pbVar3 + 2;
          } while (bVar1 != 0);
          iVar4 = 0;
          goto LAB_005b4cc7;
        }
      }
    }
    uVar2 = 0;
  }
  else {
    piVar5 = (int *)~(uint)param_2;
    if (((*piVar5 == 3) && (piVar5[6] == 0)) && (piVar5[4] == -1)) {
      uVar2 = -(uint)(*(int *)(piVar5[1] + 0x44) != 0) & (uint)piVar5;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


// ==== 0x5b4cdc FUN_005b4cdc

int __thiscall FUN_005b4cdc(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  
  if ((byte *)((uint)param_2 & 0x7fffffff) == param_2) {
    for (iVar2 = *(int *)(param_1 + 0x124); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x28)) {
      if (param_2 == (byte *)0x0) {
        iVar3 = *(int *)(iVar2 + 0x20);
LAB_005b4d43:
        if (iVar3 == 0) {
          return iVar2;
        }
      }
      else {
        pbVar5 = *(byte **)(iVar2 + 0x20);
        pbVar4 = param_2;
        if (pbVar5 != (byte *)0x0) {
          do {
            bVar1 = *pbVar4;
            bVar6 = bVar1 < *pbVar5;
            if (bVar1 != *pbVar5) {
LAB_005b4d3c:
              iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
              goto LAB_005b4d43;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar4[1];
            bVar6 = bVar1 < pbVar5[1];
            if (bVar1 != pbVar5[1]) goto LAB_005b4d3c;
            pbVar5 = pbVar5 + 2;
            pbVar4 = pbVar4 + 2;
          } while (bVar1 != 0);
          iVar3 = 0;
          goto LAB_005b4d43;
        }
      }
    }
    iVar2 = 0;
  }
  else if (*(int *)~(uint)param_2 == 2) {
    iVar2 = ((int *)~(uint)param_2)[1];
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ==== 0x5b4d58 FUN_005b4d58

int __thiscall FUN_005b4d58(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  
  if ((byte *)((uint)param_2 & 0x7fffffff) == param_2) {
    for (iVar2 = *(int *)(param_1 + 0x11c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x34)) {
      if (param_2 == (byte *)0x0) {
        iVar3 = *(int *)(iVar2 + 0x20);
LAB_005b4dbf:
        if (iVar3 == 0) {
          return iVar2;
        }
      }
      else {
        pbVar5 = *(byte **)(iVar2 + 0x20);
        pbVar4 = param_2;
        if (pbVar5 != (byte *)0x0) {
          do {
            bVar1 = *pbVar4;
            bVar6 = bVar1 < *pbVar5;
            if (bVar1 != *pbVar5) {
LAB_005b4db8:
              iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
              goto LAB_005b4dbf;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar4[1];
            bVar6 = bVar1 < pbVar5[1];
            if (bVar1 != pbVar5[1]) goto LAB_005b4db8;
            pbVar5 = pbVar5 + 2;
            pbVar4 = pbVar4 + 2;
          } while (bVar1 != 0);
          iVar3 = 0;
          goto LAB_005b4dbf;
        }
      }
    }
    iVar2 = 0;
  }
  else if (*(int *)~(uint)param_2 == 0) {
    iVar2 = ((int *)~(uint)param_2)[1];
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ==== 0x5b4dd4 FUN_005b4dd4

int FUN_005b4dd4(uint param_1)

{
  int iVar1;
  
  if (((param_1 & 0x7fffffff) == param_1) || (*(int *)~param_1 != 1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = ((int *)~param_1)[1];
  }
  return iVar1;
}


// ==== 0x5b4df5 FUN_005b4df5

int FUN_005b4df5(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 *param_5,int param_6,undefined4 *param_7)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int **ppiVar4;
  int *local_c;
  int *local_8;
  
  puVar1 = param_5;
  local_8 = (int *)0x0;
  local_c = (int *)0x0;
  FUN_005d9188();
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = 0;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  iVar2 = FUN_005b4cdc(param_2);
  if (iVar2 == 0) {
    param_5 = (undefined4 *)0x8876086c;
  }
  else {
    param_5 = (undefined4 *)
              FUN_005e4fdd(param_1 + 8,*(undefined4 *)(param_1 + 0xf8),*(undefined4 *)(iVar2 + 0x20)
                           ,0,param_3,param_4,&local_8,0);
    if (-1 < (int)param_5) {
      iVar2 = FUN_005b19e6();
      if (iVar2 != 0) {
        param_5 = (undefined4 *)0x88760b59;
      }
      if (-1 < (int)param_5) {
        ppiVar4 = &local_c;
        uVar3 = (**(code **)(*local_8 + 0xc))(local_8,ppiVar4);
        param_5 = (undefined4 *)FUN_005d7665(uVar3,ppiVar4);
        if (-1 < (int)param_5) {
          if (puVar1 != (undefined4 *)0x0) {
            *puVar1 = local_8;
            local_8 = (int *)0x0;
          }
          if (param_7 != (undefined4 *)0x0) {
            *param_7 = local_c;
            local_c = (int *)0x0;
          }
        }
      }
    }
  }
  if (param_6 != 0) {
    FUN_005b197d(param_6);
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
    local_8 = (int *)0x0;
  }
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
    local_c = (int *)0x0;
  }
  FUN_005d91a1();
  return (int)param_5;
}


// ==== 0x5b4ef1 FUN_005b4ef1

float __thiscall
FUN_005b4ef1(int param_1,int param_2,undefined4 param_3,int *param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  float *pfVar5;
  undefined4 local_18;
  int local_14;
  int local_10;
  int *local_c;
  float local_8;
  
  local_8 = 0.0;
  local_c = (int *)0x0;
  FUN_005d9188();
  local_10 = *(int *)(*(int *)(param_2 + 0x2c) + 0x28);
  if (local_10 != 0) {
    if ((*(int *)(local_10 + 4) == 0xc) && (*(int *)(local_10 + 0x1c) == 0)) {
      while (iVar1 = *(int *)(local_10 + 0x20), iVar1 != 0) {
        if ((((*(int *)(iVar1 + 4) != 1) || (iVar1 = *(int *)(iVar1 + 8), iVar1 == 0)) ||
            (*(int *)(iVar1 + 4) != 0xc)) || (local_10 = iVar1, *(int *)(iVar1 + 0x1c) != 0)) break;
      }
      if (((*(int *)(local_10 + 0x1c) == 0) && (local_14 = *(int *)(local_10 + 0x20), local_14 != 0)
          ) && ((*(int *)(local_14 + 4) == 1 &&
                ((*(int *)(local_14 + 8) != 0 && (*(int *)(*(int *)(local_14 + 8) + 4) == 0xd))))))
      {
        pfVar5 = (float *)(*(int *)(param_1 + 0x118) + *(int *)(param_2 + 0x3c));
        do {
          if (((*(int *)(local_14 + 4) != 1) || (iVar1 = *(int *)(local_14 + 8), iVar1 == 0)) ||
             (*(int *)(iVar1 + 4) != 0xd)) goto LAB_005b5163;
          iVar2 = *(int *)(iVar1 + 0x10);
          if (iVar2 == 0) {
            fVar4 = (float)(uint)(*(int *)(iVar1 + 0x18) != 0);
LAB_005b5132:
            *pfVar5 = fVar4;
LAB_005b5134:
            pfVar5 = pfVar5 + 1;
          }
          else {
            if ((iVar2 == 1) || (iVar2 == 2)) {
              fVar4 = *(float *)(iVar1 + 0x18);
              goto LAB_005b5132;
            }
            if (iVar2 == 3) {
              *pfVar5 = (float)*(double *)(iVar1 + 0x18);
              goto LAB_005b5134;
            }
            if (iVar2 != 4) {
              if (iVar2 != 5) {
                FUN_005b1f01(param_1 + 0xc,local_10 + 0x30,0,
                             "ID3DXEffectCompiler::CompileEffect: Unrecognized value type");
                goto LAB_005b5163;
              }
              piVar3 = *(int **)(iVar1 + 0x18);
              if (piVar3 == (int *)0x0) {
                local_18 = 0;
                param_2 = 0;
              }
              else {
                local_18 = (**(code **)(*piVar3 + 0xc))(piVar3);
                param_2 = (**(code **)(**(int **)(iVar1 + 0x18) + 0x10))(*(int **)(iVar1 + 0x18));
              }
              local_8 = *pfVar5;
              local_8 = (float)FUN_005b2b74(&local_8,4,0);
              if (-1 < (int)local_8) {
                local_8 = (float)FUN_005b2b74(&param_2,4,0);
joined_r0x005b503e:
                if ((-1 < (int)local_8) &&
                   (local_8 = (float)FUN_005b2b74(local_18,param_2,0), -1 < (int)local_8)) {
                  *param_4 = *param_4 + 1;
                  goto LAB_005b5134;
                }
              }
              break;
            }
            iVar1 = *(int *)(iVar1 + 0x18);
            if (((iVar1 != 0) && (*(int *)(iVar1 + 4) == 0xc)) && (*(int *)(iVar1 + 0x1c) == 0x1b))
            {
              if (local_c != (int *)0x0) {
                (**(code **)(*local_c + 8))(local_c);
                local_c = (int *)0x0;
              }
              local_8 = (float)FUN_005e505d(param_1 + 8,*(undefined4 *)(param_1 + 0xf8),iVar1,0,
                                            param_5,&local_c,0);
              if ((int)local_8 < 0) {
                FUN_005b1f01(param_1 + 0xc,local_10 + 0x30,0,
                             "ID3DXEffectCompiler::CompileEffect: There was an error compiling HLL shader parameter"
                            );
              }
              else {
                if (local_c == (int *)0x0) {
                  local_18 = 0;
                  param_2 = 0;
                }
                else {
                  local_18 = (**(code **)(*local_c + 0xc))(local_c);
                  param_2 = (**(code **)(*local_c + 0x10))(local_c);
                }
                local_8 = *pfVar5;
                local_8 = (float)FUN_005b2b74(&local_8,4,0);
                if (-1 < (int)local_8) {
                  local_8 = (float)FUN_005b2b74(&param_2,4,0);
                  goto joined_r0x005b503e;
                }
              }
              break;
            }
          }
          local_14 = *(int *)(local_14 + 0xc);
        } while (local_14 != 0);
        goto LAB_005b516a;
      }
    }
LAB_005b5163:
    local_8 = -2.29659e-41;
  }
LAB_005b516a:
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
    local_c = (int *)0x0;
  }
  FUN_005d91a1();
  return local_8;
}


// ==== 0x5b51a7 FUN_005b51a7

int FUN_005b51a7(int param_1,size_t param_2,undefined4 *param_3,int param_4)

{
  char cVar1;
  char cVar2;
  size_t sVar3;
  void *pvVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *puVar15;
  int iVar16;
  undefined4 *puVar17;
  char *pcVar18;
  char acStack_a4 [116];
  int iStack_30;
  int *piStack_2c;
  undefined4 *puStack_28;
  int iStack_24;
  int *piStack_20;
  undefined4 uStack_1c;
  int *piStack_18;
  int *piStack_14;
  uint uStack_10;
  int *piStack_c;
  int iStack_8;
  
  iStack_8 = 0;
  piStack_c = (int *)0x0;
  piStack_20 = (int *)0x0;
  piStack_18 = (int *)0x0;
  puStack_28 = (undefined4 *)0x0;
  if (*(int *)(param_1 + 0xfc) == 0) {
    FUN_005b1f01(param_1 + 0xc,0,0,"ID3DXEffectCompiler: There were no techniques");
    iVar16 = -0x7fffbffb;
  }
  else {
    pvVar4 = _malloc(0x1c);
    if (pvVar4 == (void *)0x0) {
      iStack_8 = 0;
    }
    else {
      iStack_8 = FUN_005b2aff();
    }
    if (iStack_8 == 0) {
      iVar16 = -0x7ff8fff2;
    }
    else {
      iVar12 = *(int *)(param_1 + 0x120);
      uStack_1c = 0;
      for (; iVar12 != 0; iVar12 = *(int *)(iVar12 + 0x34)) {
        iVar16 = FUN_005b4ef1(iVar12,iStack_8,&uStack_1c,param_2);
        if (iVar16 < 0) goto LAB_005b57b9;
        for (iVar6 = *(int *)(iVar12 + 0x30); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x34)) {
          iVar16 = FUN_005b4ef1(iVar6,iStack_8,&uStack_1c,param_2);
          if (iVar16 < 0) goto LAB_005b57b9;
        }
      }
      for (piVar5 = *(int **)(param_1 + 0x11c); piVar5 != (int *)0x0; piVar5 = (int *)piVar5[0xd]) {
        for (iVar12 = piVar5[0xc]; piVar9 = piVar5, iVar12 != 0; iVar12 = *(int *)(iVar12 + 0x34)) {
          iVar16 = FUN_005b4ef1(iVar12,iStack_8,&uStack_1c,param_2);
          if (iVar16 < 0) goto LAB_005b57b9;
        }
        while (piStack_14 = (int *)piVar9[0xb], piStack_14 != (int *)0x0) {
          for (iVar12 = piStack_14[10]; piVar9 = piStack_14, iVar12 != 0;
              iVar12 = *(int *)(iVar12 + 0x34)) {
            iVar16 = FUN_005b4ef1(iVar12,iStack_8,&uStack_1c,param_2);
            if (iVar16 < 0) goto LAB_005b57b9;
          }
        }
      }
      iStack_30 = 0;
      piStack_2c = *(int **)(param_1 + 0x128);
      while (piStack_2c != (int *)0x0) {
        FUN_005d9188();
        iVar12 = piStack_2c[4];
        if (((*(int *)(iVar12 + 0x1c) == 0x17) || (*(int *)(iVar12 + 0x1c) == 0x16)) &&
           (((&DAT_006d5674)[*piStack_2c * 7] == 0x6000000 ||
            ((&DAT_006d5674)[*piStack_2c * 7] == 0x6000001)))) {
          for (iVar16 = *(int *)(iVar12 + 0x20);
              (*(int *)(iVar16 + 4) == 0xc && (*(int *)(iVar16 + 0x1c) == 0));
              iVar16 = *(int *)(iVar16 + 0x20)) {
          }
          if (*(int *)(iVar16 + 4) == 1) {
            uVar14 = *(uint *)(iVar16 + 8);
            uStack_10 = uVar14;
            if (*(int *)(uVar14 + 0x10) == 6) {
              iVar16 = *(int *)(iVar12 + 0x24);
              for (iVar6 = iVar16; (*(int *)(iVar6 + 4) == 0xc && (*(int *)(iVar6 + 0x1c) == 0));
                  iVar6 = *(int *)(iVar6 + 0x20)) {
              }
              if (*(int *)(iVar6 + 4) == 0xd) {
                iVar12 = *(int *)(iVar6 + 0x20);
                if (1 < iVar12) {
                  if (iVar12 < 5) {
                    uVar10 = *(undefined4 *)(iVar6 + 0x28);
                  }
                  else {
                    if (8 < iVar12) goto LAB_005b584a;
                    uVar10 = __ftol();
                  }
                  _sprintf(acStack_a4,&DAT_006ca778,uVar10);
                  pcVar7 = *(char **)(uVar14 + 0x28);
                  pcVar18 = pcVar7 + 1;
                  do {
                    cVar1 = *pcVar7;
                    pcVar7 = pcVar7 + 1;
                  } while (cVar1 != '\0');
                  pcVar8 = acStack_a4;
                  do {
                    cVar1 = *pcVar8;
                    pcVar8 = pcVar8 + 1;
                  } while (cVar1 != '\0');
                  iVar16 = thunk_FUN_005d65b0(pcVar7 + (int)(pcVar8 + ((3 - (int)(acStack_a4 + 1)) -
                                                                      (int)pcVar18)),&piStack_c);
                  if (-1 < iVar16) {
                    uVar10 = (**(code **)(*piStack_c + 0xc))
                                       (piStack_c,"%s[%s]",*(undefined4 *)(uStack_10 + 0x28),
                                        acStack_a4);
                    _sprintf(uVar10);
                    uStack_10 = 1;
                    goto LAB_005b55b9;
                  }
                  goto LAB_005b5868;
                }
LAB_005b584a:
                pcVar18 = 
                "ID3DXEffectCompiler::CompileEffect: Shader arrays index was not float or int";
              }
              else {
                if (*(int *)(iVar16 + 4) == 0xc) {
                  iVar16 = FUN_005e505d(param_1 + 8,*(undefined4 *)(param_1 + 0xf8),iVar16,0,param_2
                                        ,&piStack_c,&piStack_14);
                  if (iVar16 < 0) goto LAB_005b5851;
                  pcVar7 = *(char **)(uStack_10 + 0x28);
                  pcVar18 = pcVar7 + 1;
                  pcVar8 = pcVar7;
                  do {
                    cVar1 = *pcVar8;
                    pcVar8 = pcVar8 + 1;
                  } while (cVar1 != '\0');
                  cVar1 = (char)pcVar7;
                  do {
                    cVar2 = *pcVar7;
                    pcVar7 = pcVar7 + 1;
                  } while (cVar2 != '\0');
                  iVar12 = ((uint)((((char)pcVar7 - (cVar1 + '\x01')) + 1U & 3) != 0) +
                           ((uint)(pcVar8 + (1 - (int)pcVar18)) >> 2)) * 4;
                  iStack_24 = iVar12;
                  iVar16 = (**(code **)(*piStack_c + 0x10))(piStack_c);
                  uVar14 = iVar16 + 4 + iVar12;
                  iVar16 = thunk_FUN_005d65b0(uVar14,&piStack_20);
                  if (-1 < iVar16) {
                    piVar9 = (int *)(**(code **)(*piStack_20 + 0xc))(piStack_20);
                    piVar5 = piVar9;
                    for (uVar13 = uVar14 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
                      *piVar5 = 0;
                      piVar5 = piVar5 + 1;
                    }
                    for (uVar13 = uVar14 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
                      *(undefined1 *)piVar5 = 0;
                      piVar5 = (int *)((int)piVar5 + 1);
                    }
                    *piVar9 = iStack_24;
                    _strncpy((char *)(piVar9 + 1),*(char **)(uStack_10 + 0x28),uVar14 - 4);
                    uStack_10 = (**(code **)(*piStack_c + 0x10))(piStack_c);
                    pcVar18 = (char *)(**(code **)(*piStack_c + 0xc))(piStack_c);
                    pcVar7 = (char *)((int)(piVar9 + 1) + iStack_24);
                    for (uVar14 = uStack_10 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
                      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar18;
                      pcVar18 = pcVar18 + 4;
                      pcVar7 = pcVar7 + 4;
                    }
                    for (uVar14 = uStack_10 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
                      *pcVar7 = *pcVar18;
                      pcVar18 = pcVar18 + 1;
                      pcVar7 = pcVar7 + 1;
                    }
                    if (piStack_14 != (int *)0x0) {
                      (**(code **)(*piStack_14 + 8))(piStack_14);
                      piStack_14 = (int *)0x0;
                    }
                    if (piStack_c != (int *)0x0) {
                      (**(code **)(*piStack_c + 8))(piStack_c);
                    }
                    piStack_c = piStack_20;
                    piStack_20 = (int *)0x0;
                    uStack_10 = 2;
                    goto LAB_005b55b9;
                  }
                  goto LAB_005b5868;
                }
                pcVar18 = 
                "ID3DXEffectCompiler::CompileEffect: Could not compile expression containing shader array"
                ;
              }
            }
            else {
              pcVar18 = 
              "ID3DXEffectCompiler::CompileEffect: Shader arrays must be a previously defined parameter"
              ;
            }
            iVar12 = uVar14 + 0x20;
          }
          else {
            pcVar18 = "ID3DXEffectCompiler::CompileEffect: Only 1-d shader arrays allowed";
            iVar12 = iVar12 + 0x30;
          }
          FUN_005b1f01(param_1 + 0xc,iVar12,0,pcVar18);
          iVar16 = -0x7fffbffb;
          FUN_005d91a1();
          goto LAB_005b57b9;
        }
        iVar16 = FUN_005e505d(param_1 + 8,*(undefined4 *)(param_1 + 0xf8),iVar12,0,param_2,
                              &piStack_c,&piStack_14);
        if (iVar16 < 0) {
LAB_005b5851:
          FUN_005b1f01(param_1 + 0xc,iVar12 + 0x30,0,
                       "ID3DXEffectCompiler::CompileEffect: There was an error compiling expression"
                      );
LAB_005b5868:
          FUN_005d91a1();
          goto LAB_005b579e;
        }
        uStack_10 = (uint)(piStack_14 == (int *)0x1);
        if ((piStack_14 != (int *)0x1) && (piStack_14 != (int *)0x0)) {
          (**(code **)(*piStack_14 + 8))(piStack_14);
          piStack_14 = (int *)0x0;
        }
LAB_005b55b9:
        uVar10 = (**(code **)(*piStack_c + 0xc))(piStack_c);
        iStack_24 = (**(code **)(*piStack_c + 0x10))(piStack_c);
        piVar5 = piStack_2c;
        iVar16 = FUN_005b2b74(piStack_2c + 1,4,0);
        if (((((iVar16 < 0) || (iVar16 = FUN_005b2b74(piVar5 + 2,4,0), iVar16 < 0)) ||
             (iVar16 = FUN_005b2b74(piVar5 + 3,4,0), iVar16 < 0)) ||
            ((iVar16 = FUN_005b2b74(&uStack_10,4,0), iVar16 < 0 ||
             (iVar16 = FUN_005b2b74(&iStack_24,4,0), iVar16 < 0)))) ||
           (iVar16 = FUN_005b2b74(uVar10,iStack_24,0), iVar16 < 0)) goto LAB_005b5868;
        iStack_30 = iStack_30 + 1;
        if (piStack_c != (int *)0x0) {
          (**(code **)(*piStack_c + 8))(piStack_c);
          piStack_c = (int *)0x0;
        }
        FUN_005d91a1();
        piStack_2c = (int *)piVar5[5];
      }
      param_2 = 0;
      iVar16 = FUN_005b2d1d(0,&param_2);
      sVar3 = param_2;
      if (-1 < iVar16) {
        puStack_28 = _malloc(param_2);
        if (puStack_28 != (undefined4 *)0x0) {
          iVar16 = FUN_005b2d1d(puStack_28,0);
          if ((iVar16 < 0) ||
             (iVar16 = thunk_FUN_005d65b0(*(int *)(param_1 + 0x10c) + *(int *)(param_1 + 0x114) +
                                          0x10 + sVar3,&piStack_18), iVar16 < 0)) goto LAB_005b57b9;
          puVar11 = (undefined4 *)(**(code **)(*piStack_18 + 0xc))(piStack_18);
          *puVar11 = 0xffffffff;
          puVar11[1] = *(undefined4 *)(param_1 + 0x114);
          uVar14 = *(uint *)(param_1 + 0x114);
          puVar15 = *(undefined4 **)(param_1 + 0x118);
          puVar17 = puVar11 + 2;
          for (uVar13 = uVar14 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
            *puVar17 = *puVar15;
            puVar15 = puVar15 + 1;
            puVar17 = puVar17 + 1;
          }
          for (uVar14 = uVar14 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
            *(undefined1 *)puVar17 = *(undefined1 *)puVar15;
            puVar15 = (undefined4 *)((int)puVar15 + 1);
            puVar17 = (undefined4 *)((int)puVar17 + 1);
          }
          puVar11 = (undefined4 *)((int)(puVar11 + 2) + *(int *)(param_1 + 0x114));
          uVar14 = *(uint *)(param_1 + 0x10c);
          puVar15 = *(undefined4 **)(param_1 + 0x110);
          puVar17 = puVar11;
          for (uVar13 = uVar14 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
            *puVar17 = *puVar15;
            puVar15 = puVar15 + 1;
            puVar17 = puVar17 + 1;
          }
          for (uVar14 = uVar14 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
            *(undefined1 *)puVar17 = *(undefined1 *)puVar15;
            puVar15 = (undefined4 *)((int)puVar15 + 1);
            puVar17 = (undefined4 *)((int)puVar17 + 1);
          }
          puVar11 = (undefined4 *)((int)puVar11 + *(int *)(param_1 + 0x10c));
          *puVar11 = uStack_1c;
          puVar11[1] = iStack_30;
          puVar15 = puStack_28;
          puVar17 = puVar11 + 2;
          for (uVar14 = param_2 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
            *puVar17 = *puVar15;
            puVar15 = puVar15 + 1;
            puVar17 = puVar17 + 1;
          }
          for (uVar14 = param_2 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
            *(undefined1 *)puVar17 = *(undefined1 *)puVar15;
            puVar15 = (undefined4 *)((int)puVar15 + 1);
            puVar17 = (undefined4 *)((int)puVar17 + 1);
          }
          if (param_3 != (undefined4 *)0x0) {
            *param_3 = piStack_18;
            (**(code **)(*piStack_18 + 4))(piStack_18);
          }
        }
LAB_005b579e:
        if (-1 < iVar16) {
          iVar12 = FUN_005b19e6();
          if (iVar12 != 0) {
            iVar16 = -0x7789f4a7;
          }
          if (-1 < iVar16) goto LAB_005b57ce;
        }
      }
    }
  }
LAB_005b57b9:
  FUN_005b1f01(param_1 + 0xc,0,0,"ID3DXEffectCompiler: Compilation failed");
LAB_005b57ce:
  if (param_4 != 0) {
    FUN_005b197d(param_4);
  }
  if (puStack_28 != (undefined4 *)0x0) {
    _free(puStack_28);
  }
  if (iStack_8 != 0) {
    FUN_005b2b58(1);
  }
  if (piStack_18 != (int *)0x0) {
    (**(code **)(*piStack_18 + 8))(piStack_18);
    piStack_18 = (int *)0x0;
  }
  if (piStack_c != (int *)0x0) {
    (**(code **)(*piStack_c + 8))(piStack_c);
    piStack_c = (int *)0x0;
  }
  if (piStack_20 != (int *)0x0) {
    (**(code **)(*piStack_20 + 8))(piStack_20);
  }
  return iVar16;
}


// ==== 0x5b58a1 FUN_005b58a1

undefined4 FUN_005b58a1(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x8876086c;
  }
  else {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[1] = *(undefined4 *)(param_1 + 0x100);
    param_2[2] = *(undefined4 *)(param_1 + 0xfc);
    param_2[3] = *(undefined4 *)(param_1 + 0x104);
  }
  return uVar1;
}


// ==== 0x5b58e2 FUN_005b58e2

undefined4 FUN_005b58e2(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  if ((param_3 != (undefined4 *)0x0) && (iVar1 = FUN_005b4cdc(param_2), iVar1 != 0)) {
    *param_3 = 0;
    param_3[1] = 0;
    *param_3 = *(undefined4 *)(iVar1 + 0x20);
    param_3[1] = 0;
    return 0;
  }
  return 0x8876086c;
}


// ==== 0x5b591f FUN_005b591f

undefined4 FUN_005b591f(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  if ((param_3 != (undefined4 *)0x0) && (iVar1 = FUN_005b4d58(param_2), iVar1 != 0)) {
    *param_3 = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    *param_3 = *(undefined4 *)(iVar1 + 0x20);
    param_3[1] = *(undefined4 *)(iVar1 + 0x28);
    param_3[2] = *(undefined4 *)(iVar1 + 0x24);
    return 0;
  }
  return 0x8876086c;
}


// ==== 0x5b5966 FUN_005b5966

undefined4 FUN_005b5966(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_3 == 0) {
    local_8 = 0x8876086c;
  }
  else {
    uVar5 = FUN_005b4dd4(param_2);
    puVar3 = (undefined4 *)((ulonglong)uVar5 >> 0x20);
    iVar1 = (int)uVar5;
    if (iVar1 == 0) {
      local_8 = 0x8876086c;
    }
    else {
      puVar4 = puVar3;
      for (iVar2 = 0x117; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      *puVar3 = *(undefined4 *)(iVar1 + 0x20);
      puVar3[1] = *(undefined4 *)(iVar1 + 0x24);
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[4] = 0;
      puVar3[0x85] = 0;
      puVar3[0x106] = 0;
    }
  }
  return local_8;
}


// ==== 0x5b59d1 FUN_005b59d1

uint __thiscall FUN_005b59d1(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int local_8;
  
  uVar5 = (uint)param_3;
  if (param_2 == 0) {
    return 0;
  }
  local_8 = param_1;
  iVar2 = FUN_005b7369(param_2,param_4);
  if ((((iVar2 == 0) ||
       (uVar1 = *(uint *)(*(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x118) + 0x10 +
                         *(int *)(iVar2 + 0x18)), *(int *)(iVar2 + 0x10) != -1)) || (uVar1 == 0)) ||
     (uVar1 <= param_3)) {
LAB_005b5b16:
    uVar5 = 0;
  }
  else {
    param_3 = (undefined4 *)0x0;
    puVar3 = *(undefined4 **)(iVar2 + 0xc);
    if (*(undefined4 **)(iVar2 + 0xc) == (undefined4 *)0x0) {
LAB_005b5a5c:
      puVar3 = _malloc(0x20);
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3[4] = 0xffffffff;
        puVar3[7] = 0;
        puVar3[2] = 0;
        puVar3[3] = 0;
      }
      if (puVar3 == (undefined4 *)0x0) goto LAB_005b5b16;
      local_8 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(iVar2 + 0x18);
      uVar4 = FUN_005b30af(*(undefined4 *)(param_1 + 0x118),&local_8,&param_4);
      *puVar3 = 3;
      puVar3[1] = *(undefined4 *)(iVar2 + 4);
      puVar3[6] = *(undefined4 *)(iVar2 + 0x18);
      puVar3[4] = uVar5;
      uVar6 = 0;
      puVar3[5] = uVar4 / uVar1;
      puVar3[7] = *(undefined4 *)(iVar2 + 0x1c);
      if ((param_4 * uVar5) / uVar1 != 0) {
        do {
          puVar3[7] = *(undefined4 *)(puVar3[7] + 0xc);
          uVar6 = uVar6 + 1;
        } while (uVar6 < (uint)(puVar3[4] * param_4) / uVar1);
      }
      if (param_3 == (undefined4 *)0x0) {
        puVar3[3] = *(undefined4 *)(iVar2 + 0xc);
        *(undefined4 **)(iVar2 + 0xc) = puVar3;
      }
      else {
        puVar3[3] = param_3[3];
        param_3[3] = puVar3;
      }
    }
    else {
      do {
        puVar7 = puVar3;
        puVar3 = puVar7;
        if (uVar5 <= (uint)puVar7[4]) break;
        puVar3 = (undefined4 *)puVar7[3];
        param_3 = puVar7;
      } while (puVar3 != (undefined4 *)0x0);
      if ((puVar3 == (undefined4 *)0x0) || (uVar5 < (uint)puVar3[4])) goto LAB_005b5a5c;
    }
    uVar5 = ~(uint)puVar3;
  }
  return uVar5;
}


// ==== 0x5b5b1f FUN_005b5b1f

uint FUN_005b5b1f(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = FUN_005b4c4b(param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_005b4d58(param_2);
    if (iVar1 == 0) {
      iVar1 = FUN_005b4dd4(param_2);
      if (iVar1 == 0) {
        return 0;
      }
      uVar3 = *(uint *)(iVar1 + 0x24);
      uVar2 = *(uint *)(iVar1 + 0x28);
      goto LAB_005b5b65;
    }
    uVar3 = *(uint *)(iVar1 + 0x24);
  }
  else {
    iVar1 = *(int *)(iVar1 + 4);
    uVar3 = *(uint *)(iVar1 + 0x28);
  }
  uVar2 = *(uint *)(iVar1 + 0x30);
LAB_005b5b65:
  if (uVar3 <= param_3) {
    return 0;
  }
  while (param_3 = param_3 + 1, param_3 < uVar3) {
    uVar2 = *(uint *)(uVar2 + 0x34);
  }
  return ~uVar2;
}


// ==== 0x5b5b7e FUN_005b5b7e

uint __thiscall FUN_005b5b7e(int param_1,undefined4 param_2,char *param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  char *pcVar7;
  
  if (param_3 == (char *)0x0) {
    return 0;
  }
  if (*param_3 == '\0') {
    return 0;
  }
  iVar2 = FUN_005b4c4b(param_2);
  if (iVar2 == 0) {
    iVar2 = FUN_005b4d58(param_2);
    if (iVar2 == 0) {
      iVar2 = FUN_005b4dd4(param_2);
      if (iVar2 == 0) {
        return 0;
      }
      uVar5 = *(uint *)(iVar2 + 0x28);
      goto LAB_005b5bd1;
    }
  }
  else {
    iVar2 = *(int *)(iVar2 + 4);
  }
  uVar5 = *(uint *)(iVar2 + 0x30);
LAB_005b5bd1:
  if (uVar5 != 0) {
    do {
      iVar2 = *(int *)(*(int *)(uVar5 + 4) + 0x40) + *(int *)(uVar5 + 0x18) +
              *(int *)(param_1 + 0x118);
      piVar3 = (int *)(*(int *)(param_1 + 0x118) + *(int *)(iVar2 + 8));
      piVar6 = (int *)0x0;
      if (*piVar3 != 0) {
        piVar6 = piVar3 + 1;
      }
      cVar1 = *param_3;
      pcVar7 = param_3;
      while ((cVar1 == (char)*piVar6 && (cVar1 != '\0'))) {
        pcVar7 = pcVar7 + 1;
        piVar6 = (int *)((int)piVar6 + 1);
        cVar1 = *pcVar7;
      }
      cVar1 = *pcVar7;
      if (cVar1 == (char)*piVar6) {
        return ~uVar5;
      }
      if ((char)*piVar6 == '\0') {
        if (cVar1 == '.') {
          pcVar7 = pcVar7 + 1;
          uVar5 = ~uVar5;
          goto LAB_005b5c8b;
        }
        if (cVar1 == '[') {
          pcVar7 = pcVar7 + 1;
          if (*pcVar7 < '0') {
            return 0;
          }
          if ('9' < *pcVar7) {
            return 0;
          }
          uVar4 = _atoi(pcVar7);
          if (*(uint *)(iVar2 + 0x10) <= uVar4) {
            return 0;
          }
          for (; ('/' < *pcVar7 && (*pcVar7 < ':')); pcVar7 = pcVar7 + 1) {
          }
          if (*pcVar7 != ']') {
            return 0;
          }
          uVar5 = FUN_005b59d1(~uVar5,uVar4,param_4);
          if (uVar5 == 0) {
            return 0;
          }
          if (pcVar7[1] == '\0') {
            return uVar5;
          }
          if (pcVar7[1] != '.') {
            return 0;
          }
          pcVar7 = pcVar7 + 2;
LAB_005b5c8b:
          uVar5 = FUN_005b626c(uVar5,pcVar7,param_4);
          return uVar5;
        }
      }
      uVar5 = *(uint *)(uVar5 + 0x34);
    } while (uVar5 != 0);
  }
  return 0;
}


// ==== 0x5b5c9f FUN_005b5c9f

uint FUN_005b5c9f(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 < *(uint *)(param_1 + 0xfc)) {
    uVar1 = *(uint *)(param_1 + 0x11c);
    while (param_2 = param_2 + 1, param_2 < *(uint *)(param_1 + 0xfc)) {
      uVar1 = *(uint *)(uVar1 + 0x34);
    }
    uVar1 = ~uVar1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x5b5cca FUN_005b5cca

uint FUN_005b5cca(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_005b4d58(param_2);
  uVar2 = 0;
  if (uVar1 != 0) {
    uVar2 = ~uVar1;
  }
  return uVar2;
}


// ==== 0x5b5ce0 FUN_005b5ce0

uint FUN_005b5ce0(undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = FUN_005b4d58(param_2);
  if ((uVar2 != 0) && (puVar1 = (uint *)(uVar2 + 0x28), param_3 < *puVar1)) {
    do {
      uVar2 = *(uint *)(uVar2 + 0x2c);
      param_3 = param_3 + 1;
    } while (param_3 < *puVar1);
    return ~uVar2;
  }
  return 0;
}


// ==== 0x5b5d0d FUN_005b5d0d

uint FUN_005b5d0d(undefined4 param_1,undefined4 param_2,byte *param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  bool bVar6;
  
  iVar2 = FUN_005b4d58(param_2);
  if (iVar2 != 0) {
    for (uVar5 = *(uint *)(iVar2 + 0x2c); uVar5 != 0; uVar5 = *(uint *)(uVar5 + 0x2c)) {
      if (param_3 == (byte *)0x0) {
        iVar2 = *(int *)(uVar5 + 0x20);
LAB_005b5d66:
        if (iVar2 == 0) {
          return ~uVar5;
        }
      }
      else {
        pbVar4 = *(byte **)(uVar5 + 0x20);
        pbVar3 = param_3;
        if (pbVar4 != (byte *)0x0) {
          do {
            bVar1 = *pbVar3;
            bVar6 = bVar1 < *pbVar4;
            if (bVar1 != *pbVar4) {
LAB_005b5d5f:
              iVar2 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
              goto LAB_005b5d66;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar3[1];
            bVar6 = bVar1 < pbVar4[1];
            if (bVar1 != pbVar4[1]) goto LAB_005b5d5f;
            pbVar4 = pbVar4 + 2;
            pbVar3 = pbVar3 + 2;
          } while (bVar1 != 0);
          iVar2 = 0;
          goto LAB_005b5d66;
        }
      }
    }
  }
  return 0;
}


// ==== 0x5b5d7c FUN_005b5d7c

uint FUN_005b5d7c(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 < *(uint *)(param_1 + 0x104)) {
    uVar1 = *(uint *)(param_1 + 0x124);
    while (param_2 = param_2 + 1, param_2 < *(uint *)(param_1 + 0x104)) {
      uVar1 = *(uint *)(uVar1 + 0x28);
    }
    uVar1 = ~uVar1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x5b5da7 FUN_005b5da7

uint FUN_005b5da7(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_005b4cdc(param_2);
  uVar2 = 0;
  if (uVar1 != 0) {
    uVar2 = ~uVar1;
  }
  return uVar2;
}


// ==== 0x5b5dbd FUN_005b5dbd

undefined4 FUN_005b5dbd(int param_1,float param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar3 = *(int *)(iVar1 + 0x10);
  if (iVar3 == 0) {
    iVar3 = __ftol();
    uVar2 = (uint)(iVar3 != 0);
  }
  else {
    if ((iVar3 != 1) && (iVar3 != 2)) {
      if (iVar3 != 3) {
        return 0x8876086c;
      }
      *(double *)(iVar1 + 0x18) = (double)param_2;
      return 0;
    }
    uVar2 = __ftol();
  }
  *(uint *)(iVar1 + 0x18) = uVar2;
  return 0;
}


// ==== 0x5b5e0c FUN_005b5e0c

undefined4 FUN_005b5e0c(int param_1,float *param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(iVar1 + 0x10);
  if (iVar2 == 0) {
    fVar3 = (float)(*(int *)(iVar1 + 0x18) != 0);
  }
  else if (iVar2 == 1) {
    fVar3 = (float)*(int *)(iVar1 + 0x18);
  }
  else if (iVar2 == 2) {
    fVar3 = (float)*(int *)(iVar1 + 0x18);
    if (*(int *)(iVar1 + 0x18) < 0) {
      fVar3 = fVar3 + 4.2949673e+09;
    }
  }
  else {
    if (iVar2 != 3) {
      return 0x8876086c;
    }
    fVar3 = (float)*(double *)(iVar1 + 0x18);
  }
  *param_2 = fVar3;
  return 0;
}


// ==== 0x5b5e64 FUN_005b5e64

undefined4 FUN_005b5e64(void)

{
  return 0x8876086c;
}


// ==== 0x5b5e6c FUN_005b5e6c

void FUN_005b5e6c(undefined4 param_1,undefined4 param_2,int param_3,code *param_4)

{
  if (-1 < param_3 + -1) {
    do {
      (*param_4)();
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}


// ==== 0x5b5e96 FUN_005b5e96

void __fastcall FUN_005b5e96(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005b5ec9(3);
    *(undefined4 *)(param_1 + 8) = 0;
  }
  while (*(int *)(param_1 + 0xc) != 0) {
    iVar1 = *(int *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar1 + 0xc) = 0;
    FUN_005b2a99(1);
  }
  return;
}


// ==== 0x5b5ec9 FUN_005b5ec9

undefined4 * __thiscall FUN_005b5ec9(undefined4 *param_1,byte param_2)

{
  undefined4 *_Memory;
  
  if ((param_2 & 2) == 0) {
    FUN_005b5e96();
    _Memory = param_1;
    if ((param_2 & 1) != 0) {
      _free(param_1);
    }
  }
  else {
    _Memory = param_1 + -1;
    FUN_005b5e6c(param_1,0x20,*_Memory,FUN_005b5e96);
    if ((param_2 & 1) != 0) {
      _free(_Memory);
    }
  }
  return _Memory;
}


// ==== 0x5b5f14 FUN_005b5f14

void __fastcall FUN_005b5f14(undefined4 *param_1)

{
  param_1[4] = 0xffffffff;
  param_1[7] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[1] = param_1;
  *param_1 = 0;
  param_1[0xc] = 0;
  param_1[0xb] = 0;
  param_1[0xd] = 0;
  return;
}


// ==== 0x5b5f34 FUN_005b5f34

void __fastcall FUN_005b5f34(undefined4 *param_1)

{
  param_1[4] = 0xffffffff;
  param_1[7] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[1] = param_1;
  *param_1 = 1;
  param_1[10] = 0;
  param_1[0xb] = 0;
  return;
}


// ==== 0x5b5f55 FUN_005b5f55

void __fastcall FUN_005b5f55(undefined4 *param_1)

{
  param_1[4] = 0xffffffff;
  param_1[7] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[1] = param_1;
  *param_1 = 2;
  param_1[10] = 0;
  return;
}


// ==== 0x5b5f73 FUN_005b5f73

void __fastcall FUN_005b5f73(int param_1)

{
  int iVar1;
  void *_Memory;
  
  iVar1 = *(int *)(param_1 + 0x28);
  while (iVar1 != 0) {
    _Memory = *(void **)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)((int)_Memory + 0x28);
    *(undefined4 *)((int)_Memory + 0x28) = 0;
    FUN_005b5f73();
    _free(_Memory);
    iVar1 = *(int *)(param_1 + 0x28);
  }
  FUN_005b5e96();
  return;
}


// ==== 0x5b5fa7 FUN_005b5fa7

void * __thiscall FUN_005b5fa7(void *param_1,byte param_2)

{
  FUN_005b5f73();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5b5fc3 FUN_005b5fc3

void __fastcall FUN_005b5fc3(undefined4 *param_1)

{
  param_1[4] = 0xffffffff;
  param_1[7] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[1] = param_1;
  *param_1 = 3;
  param_1[6] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  return;
}


// ==== 0x5b5fe7 FUN_005b5fe7

void __fastcall FUN_005b5fe7(int param_1)

{
  void *pvVar1;
  
  while (*(int *)(param_1 + 0x30) != 0) {
    pvVar1 = *(void **)(param_1 + 0x30);
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)((int)pvVar1 + 0x30);
    *(undefined4 *)((int)pvVar1 + 0x30) = 0;
    FUN_005b5fe7();
    _free(pvVar1);
  }
  while (*(int *)(param_1 + 0x34) != 0) {
    pvVar1 = *(void **)(param_1 + 0x34);
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)((int)pvVar1 + 0x34);
    *(undefined4 *)((int)pvVar1 + 0x34) = 0;
    FUN_005b5fe7();
    _free(pvVar1);
  }
  FUN_005b5e96();
  return;
}


// ==== 0x5b603a FUN_005b603a

undefined4 FUN_005b603a(int param_1,undefined4 param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  iVar4 = FUN_005b4c4b(param_2);
  if (iVar4 == 0) {
    uVar6 = 0x8876086c;
  }
  else {
    iVar2 = *(int *)(iVar4 + 4);
    uVar3 = *(uint *)(*(int *)(iVar2 + 0x2c) + 0x1c);
    if (param_3 == 0) {
      if ((uVar3 & 8) != 0) {
        puVar5 = (uint *)(*(int *)(iVar2 + 0x44) + *(int *)(param_1 + 0x110));
        *puVar5 = *puVar5 | 1;
      }
      pbVar1 = (byte *)(*(int *)(*(int *)(iVar4 + 4) + 0x2c) + 0x1c);
      *pbVar1 = *pbVar1 & 0x7f;
      puVar5 = (uint *)(*(int *)(*(int *)(iVar4 + 4) + 0x44) + *(int *)(param_1 + 0x110));
      *puVar5 = *puVar5 & 0xfffffffd;
    }
    else {
      if ((uVar3 & 8) != 0) {
        puVar5 = (uint *)(*(int *)(iVar2 + 0x44) + *(int *)(param_1 + 0x110));
        *puVar5 = *puVar5 & 0xfffffffe;
      }
      pbVar1 = (byte *)(*(int *)(*(int *)(iVar4 + 4) + 0x2c) + 0x1c);
      *pbVar1 = *pbVar1 | 0x80;
      puVar5 = (uint *)(*(int *)(*(int *)(iVar4 + 4) + 0x44) + *(int *)(param_1 + 0x110));
      *puVar5 = *puVar5 | 2;
    }
  }
  return uVar6;
}


// ==== 0x5b60cd FUN_005b60cd

undefined4 FUN_005b60cd(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  
  if ((param_3 != (uint *)0x0) && (iVar1 = FUN_005b4c4b(param_2), iVar1 != 0)) {
    *param_3 = *(uint *)(*(int *)(*(int *)(iVar1 + 4) + 0x2c) + 0x1c) >> 7 & 1;
    return 0;
  }
  return 0x80004005;
}


// ==== 0x5b6109 FUN_005b6109

undefined4 __thiscall FUN_005b6109(int param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  pvVar2 = _malloc(0x2c);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_005b5f55();
  }
  if (iVar3 == 0) {
    uVar4 = 0x8007000e;
  }
  else if ((((*(int *)(param_2 + 0x18) == 0) || (*(int *)(*(int *)(param_2 + 0x18) + 4) != 9)) ||
           (iVar1 = *(int *)(param_2 + 0x14), iVar1 == 0)) ||
          (((*(int *)(iVar1 + 4) != 2 || (*(int *)(iVar1 + 0x10) != 9)) ||
           (*(int *)(iVar1 + 0x18) == 0)))) {
    uVar4 = 0x80004005;
    FUN_005b5fa7(1);
  }
  else {
    *(int *)(iVar3 + 0x20) = *(int *)(iVar1 + 0x18);
    *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(param_2 + 0x18);
    *(int *)(iVar3 + 0x28) = *(int *)(param_1 + 0x124);
    *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 1;
    *(int *)(param_1 + 0x124) = iVar3;
  }
  return uVar4;
}


// ==== 0x5b618f FUN_005b618f

undefined4 FUN_005b618f(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int local_c;
  int local_8;
  
  iVar1 = param_1;
  piVar5 = (int *)0x0;
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005b5ec9(3);
    *(undefined4 *)(iVar1 + 8) = 0;
  }
  iVar7 = param_2;
  piVar2 = _malloc(param_2 * 0x20 + 4);
  if (piVar2 != (int *)0x0) {
    piVar5 = piVar2 + 1;
    *piVar2 = iVar7;
    CallNTimes(piVar5,0x20,iVar7,FUN_005b2a87);
  }
  *(int **)(iVar1 + 8) = piVar5;
  if (piVar5 == (int *)0x0) {
    uVar3 = 0x8007000e;
  }
  else {
    iVar6 = *(int *)(iVar1 + 0x1c);
    param_1 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + 0x18 + *(int *)(iVar1 + 0x18);
    if (iVar7 != 0) {
      iVar7 = 0;
      do {
        *(undefined4 *)(iVar7 + *(int *)(iVar1 + 8)) = 3;
        *(undefined4 *)(iVar7 + 4 + *(int *)(iVar1 + 8)) = *(undefined4 *)(iVar1 + 4);
        *(int *)(iVar7 + 0x18 + *(int *)(iVar1 + 8)) =
             param_1 - *(int *)(*(int *)(iVar1 + 4) + 0x40);
        uVar3 = FUN_005b30af(*(undefined4 *)(local_8 + 0x118),&param_1,&local_c);
        *(undefined4 *)(iVar7 + 0x14 + *(int *)(iVar1 + 8)) = uVar3;
        *(int *)(iVar7 + 0x1c + *(int *)(iVar1 + 8)) = iVar6;
        for (iVar4 = local_c; iVar4 != 0; iVar4 = iVar4 + -1) {
          iVar6 = *(int *)(iVar6 + 0xc);
        }
        iVar7 = iVar7 + 0x20;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
    uVar3 = 0;
  }
  return uVar3;
}


// ==== 0x5b626c FUN_005b626c

uint __thiscall FUN_005b626c(int param_1,uint param_2,char *param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  char *pcVar7;
  uint uVar8;
  int local_c;
  
LAB_005b63d1:
  if (param_2 != 0) {
    uVar5 = FUN_005b7369(param_2,param_4 + 1);
    if (uVar5 != 0) {
      if (param_3 != (char *)0x0) {
        iVar2 = *(int *)(*(int *)(uVar5 + 4) + 0x40) + *(int *)(uVar5 + 0x18) +
                *(int *)(param_1 + 0x118);
        if (((*(int *)(iVar2 + 4) == 5) &&
            ((*(int *)(uVar5 + 0x10) != -1 || (*(int *)(iVar2 + 0x10) == 0)))) &&
           ((uVar4 = *(uint *)(iVar2 + 0x14), *(int *)(uVar5 + 8) != 0 ||
            (iVar2 = FUN_005b618f(uVar5,uVar4), -1 < iVar2)))) {
          uVar8 = 0;
          local_c = 0;
          do {
            if (uVar4 <= uVar8) break;
            iVar2 = *(int *)(uVar5 + 8) + local_c;
            iVar2 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(iVar2 + 0x18) +
                    *(int *)(param_1 + 0x118);
            piVar3 = (int *)(*(int *)(iVar2 + 8) + *(int *)(param_1 + 0x118));
            piVar6 = (int *)0x0;
            if (*piVar3 != 0) {
              piVar6 = piVar3 + 1;
            }
            cVar1 = *param_3;
            pcVar7 = param_3;
            while ((cVar1 == (char)*piVar6 && (cVar1 != '\0'))) {
              pcVar7 = pcVar7 + 1;
              piVar6 = (int *)((int)piVar6 + 1);
              cVar1 = *pcVar7;
            }
            cVar1 = *pcVar7;
            if (cVar1 == (char)*piVar6) {
              uVar5 = uVar8 * 0x20 + *(int *)(uVar5 + 8);
              goto LAB_005b63f2;
            }
            if ((char)*piVar6 == '\0') {
              if (cVar1 == '.') {
                param_3 = pcVar7 + 1;
                param_2 = ~(uVar8 * 0x20 + *(int *)(uVar5 + 8));
                goto LAB_005b63d1;
              }
              if (cVar1 == '@') {
                uVar5 = FUN_005b5b7e(~(uVar8 * 0x20 + *(int *)(uVar5 + 8)),pcVar7 + 1,param_4);
                return uVar5;
              }
              if (cVar1 == '[') goto LAB_005b6363;
            }
            uVar8 = uVar8 + 1;
            local_c = local_c + 0x20;
          } while( true );
        }
        goto LAB_005b637a;
      }
      goto LAB_005b63f2;
    }
    goto LAB_005b637a;
  }
  if ((param_3 == (char *)0x0) || (uVar5 = FUN_005b7369(param_3,param_4 + 1), uVar5 == 0)) {
LAB_005b637a:
    uVar5 = 0;
  }
  else {
LAB_005b63f2:
    uVar5 = ~uVar5;
  }
  return uVar5;
LAB_005b6363:
  pcVar7 = pcVar7 + 1;
  if (((*pcVar7 < '0') || ('9' < *pcVar7)) ||
     (uVar4 = _atoi(pcVar7), *(uint *)(iVar2 + 0x10) <= uVar4)) goto LAB_005b637a;
  for (; ('/' < *pcVar7 && (*pcVar7 < ':')); pcVar7 = pcVar7 + 1) {
  }
  if (*pcVar7 != ']') goto LAB_005b637a;
  param_2 = FUN_005b59d1(~(uVar8 * 0x20 + *(int *)(uVar5 + 8)),uVar4,param_4);
  if (param_2 == 0) goto LAB_005b637a;
  if (pcVar7[1] == '\0') {
    return param_2;
  }
  if (pcVar7[1] != '.') goto LAB_005b637a;
  param_3 = pcVar7 + 2;
  goto LAB_005b63d1;
}


// ==== 0x5b6425 FUN_005b6425

void FUN_005b6425(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005b59d1(param_2,param_3,0);
  return;
}


// ==== 0x5b643b FUN_005b643b

void FUN_005b643b(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005b5b7e(param_2,param_3,0);
  return;
}


// ==== 0x5b6451 FUN_005b6451

int FUN_005b6451(uint param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_10 = 0;
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x14);
    uVar2 = *(uint *)(param_1 + 0x18);
    local_c = 4;
    if (uVar1 < 5) {
      local_c = uVar1;
    }
    local_8 = 4;
    iVar5 = (int)param_2;
    if (uVar2 < 5) {
      local_8 = uVar2;
    }
    do {
      param_1 = 0;
      if (local_c != 0) {
        param_2 = param_3;
        do {
          uVar4 = 0;
          puVar6 = param_2;
          if (local_8 != 0) {
            do {
              local_10 = FUN_005b5dbd(iVar5,*puVar6);
              if (local_10 < 0) {
                return local_10;
              }
              iVar5 = *(int *)(iVar5 + 0xc);
              uVar4 = uVar4 + 1;
              puVar6 = puVar6 + 1;
            } while (uVar4 < local_8);
          }
          if (uVar4 < uVar2) {
            iVar3 = uVar2 - uVar4;
            do {
              iVar3 = iVar3 + -1;
              iVar5 = *(int *)(iVar5 + 0xc);
            } while (iVar3 != 0);
          }
          param_1 = param_1 + 1;
          param_2 = param_2 + 4;
        } while (param_1 < local_c);
      }
      if (param_1 < uVar1) {
        iVar3 = uVar1 - param_1;
        uVar4 = uVar2;
        do {
          for (; uVar4 != 0; uVar4 = uVar4 - 1) {
            iVar5 = *(int *)(iVar5 + 0xc);
          }
          iVar3 = iVar3 + -1;
          uVar4 = uVar2;
        } while (iVar3 != 0);
      }
      param_4 = param_4 + -1;
      param_3 = param_3 + 0x10;
    } while (param_4 != 0);
  }
  return local_10;
}


// ==== 0x5b6520 FUN_005b6520

int FUN_005b6520(uint param_1,undefined4 *param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_10 = 0;
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x14);
    uVar2 = *(uint *)(param_1 + 0x18);
    local_c = 4;
    if (uVar1 < 5) {
      local_c = uVar1;
    }
    local_8 = 4;
    if (uVar2 < 5) {
      local_8 = uVar2;
    }
    puVar4 = param_3;
    for (iVar3 = (param_4 & 0x3ffffff) << 4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar3 = 0; iVar5 = (int)param_2, iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    do {
      param_1 = 0;
      if (local_c != 0) {
        param_2 = param_3;
        do {
          uVar6 = 0;
          puVar4 = param_2;
          if (local_8 != 0) {
            do {
              local_10 = FUN_005b5e0c(iVar5,puVar4);
              if (local_10 < 0) {
                return local_10;
              }
              iVar5 = *(int *)(iVar5 + 0xc);
              uVar6 = uVar6 + 1;
              puVar4 = puVar4 + 1;
            } while (uVar6 < local_8);
          }
          if (uVar6 < uVar2) {
            iVar3 = uVar2 - uVar6;
            do {
              iVar3 = iVar3 + -1;
              iVar5 = *(int *)(iVar5 + 0xc);
            } while (iVar3 != 0);
          }
          param_1 = param_1 + 1;
          param_2 = param_2 + 4;
        } while (param_1 < local_c);
      }
      if (param_1 < uVar1) {
        iVar3 = uVar1 - param_1;
        uVar6 = uVar2;
        do {
          for (; uVar6 != 0; uVar6 = uVar6 - 1) {
            iVar5 = *(int *)(iVar5 + 0xc);
          }
          iVar3 = iVar3 + -1;
          uVar6 = uVar2;
        } while (iVar3 != 0);
      }
      param_4 = param_4 - 1;
      param_3 = param_3 + 0x10;
    } while (param_4 != 0);
  }
  return local_10;
}


// ==== 0x5b65fe FUN_005b65fe

int FUN_005b65fe(uint param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_10 = 0;
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x14);
    uVar2 = *(uint *)(param_1 + 0x18);
    local_c = 4;
    if (uVar1 < 5) {
      local_c = uVar1;
    }
    local_8 = 4;
    iVar5 = (int)param_2;
    if (uVar2 < 5) {
      local_8 = uVar2;
    }
    do {
      param_1 = 0;
      if (local_c != 0) {
        param_2 = param_3;
        do {
          uVar4 = 0;
          puVar6 = param_2;
          if (local_8 != 0) {
            do {
              local_10 = FUN_005b5dbd(iVar5,*puVar6);
              if (local_10 < 0) {
                return local_10;
              }
              iVar5 = *(int *)(iVar5 + 0xc);
              uVar4 = uVar4 + 1;
              puVar6 = puVar6 + 4;
            } while (uVar4 < local_8);
          }
          if (uVar4 < uVar2) {
            iVar3 = uVar2 - uVar4;
            do {
              iVar3 = iVar3 + -1;
              iVar5 = *(int *)(iVar5 + 0xc);
            } while (iVar3 != 0);
          }
          param_1 = param_1 + 1;
          param_2 = param_2 + 1;
        } while (param_1 < local_c);
      }
      if (param_1 < uVar1) {
        iVar3 = uVar1 - param_1;
        uVar4 = uVar2;
        do {
          for (; uVar4 != 0; uVar4 = uVar4 - 1) {
            iVar5 = *(int *)(iVar5 + 0xc);
          }
          iVar3 = iVar3 + -1;
          uVar4 = uVar2;
        } while (iVar3 != 0);
      }
      param_4 = param_4 + -1;
      param_3 = param_3 + 0x10;
    } while (param_4 != 0);
  }
  return local_10;
}


// ==== 0x5b66cd FUN_005b66cd

int FUN_005b66cd(uint param_1,undefined4 *param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_10 = 0;
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x14);
    uVar2 = *(uint *)(param_1 + 0x18);
    local_c = 4;
    if (uVar1 < 5) {
      local_c = uVar1;
    }
    local_8 = 4;
    if (uVar2 < 5) {
      local_8 = uVar2;
    }
    puVar4 = param_3;
    for (iVar3 = (param_4 & 0x3ffffff) << 4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar3 = 0; iVar5 = (int)param_2, iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    do {
      param_1 = 0;
      if (local_c != 0) {
        param_2 = param_3;
        do {
          uVar6 = 0;
          puVar4 = param_2;
          if (local_8 != 0) {
            do {
              local_10 = FUN_005b5e0c(iVar5,puVar4);
              if (local_10 < 0) {
                return local_10;
              }
              iVar5 = *(int *)(iVar5 + 0xc);
              uVar6 = uVar6 + 1;
              puVar4 = puVar4 + 4;
            } while (uVar6 < local_8);
          }
          if (uVar6 < uVar2) {
            iVar3 = uVar2 - uVar6;
            do {
              iVar3 = iVar3 + -1;
              iVar5 = *(int *)(iVar5 + 0xc);
            } while (iVar3 != 0);
          }
          param_1 = param_1 + 1;
          param_2 = param_2 + 1;
        } while (param_1 < local_c);
      }
      if (param_1 < uVar1) {
        iVar3 = uVar1 - param_1;
        uVar6 = uVar2;
        do {
          for (; uVar6 != 0; uVar6 = uVar6 - 1) {
            iVar5 = *(int *)(iVar5 + 0xc);
          }
          iVar3 = iVar3 + -1;
          uVar6 = uVar2;
        } while (iVar3 != 0);
      }
      param_4 = param_4 - 1;
      param_3 = param_3 + 0x10;
    } while (param_4 != 0);
  }
  return local_10;
}


// ==== 0x5b67ab FUN_005b67ab

int FUN_005b67ab(uint param_1,uint param_2,int *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int local_c;
  uint local_8;
  
  local_c = 0;
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x14);
    uVar2 = *(uint *)(param_1 + 0x18);
    local_8 = 4;
    if (uVar1 < 5) {
      local_8 = uVar1;
    }
    param_1 = 4;
    iVar6 = param_2;
    if (uVar2 < 5) {
      param_1 = uVar2;
    }
    do {
      uVar4 = uVar1;
      if (*param_3 == 0) {
        for (; uVar3 = uVar2, uVar4 != 0; uVar4 = uVar4 - 1) {
          for (; uVar3 != 0; uVar3 = uVar3 - 1) {
            iVar6 = *(int *)(iVar6 + 0xc);
          }
        }
      }
      else {
        uVar4 = 0;
        param_2 = 0;
        if (local_8 != 0) {
          do {
            uVar4 = 0;
            if (param_1 != 0) {
              iVar5 = param_2 << 4;
              do {
                local_c = FUN_005b5dbd(iVar6,*(undefined4 *)(iVar5 + *param_3));
                if (local_c < 0) {
                  return local_c;
                }
                iVar6 = *(int *)(iVar6 + 0xc);
                uVar4 = uVar4 + 1;
                iVar5 = iVar5 + 4;
              } while (uVar4 < param_1);
            }
            if (uVar4 < uVar2) {
              iVar5 = uVar2 - uVar4;
              do {
                iVar5 = iVar5 + -1;
                iVar6 = *(int *)(iVar6 + 0xc);
              } while (iVar5 != 0);
            }
            uVar4 = param_2 + 1;
            param_2 = uVar4;
          } while (uVar4 < local_8);
        }
        if (uVar4 < uVar1) {
          iVar5 = uVar1 - uVar4;
          uVar4 = uVar2;
          do {
            for (; uVar4 != 0; uVar4 = uVar4 - 1) {
              iVar6 = *(int *)(iVar6 + 0xc);
            }
            iVar5 = iVar5 + -1;
            uVar4 = uVar2;
          } while (iVar5 != 0);
        }
      }
      param_4 = param_4 + -1;
      param_3 = param_3 + 1;
    } while (param_4 != 0);
  }
  return local_c;
}


// ==== 0x5b6897 FUN_005b6897

int FUN_005b6897(uint param_1,uint param_2,int *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int local_c;
  uint local_8;
  
  local_c = 0;
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x18);
    uVar2 = *(uint *)(param_1 + 0x14);
    local_8 = 4;
    if (uVar2 < 5) {
      local_8 = uVar2;
    }
    param_1 = 4;
    iVar5 = param_2;
    if (uVar1 < 5) {
      param_1 = uVar1;
    }
    do {
      uVar7 = uVar2;
      if ((undefined4 *)*param_3 == (undefined4 *)0x0) {
        for (; uVar3 = uVar1, uVar7 != 0; uVar7 = uVar7 - 1) {
          for (; uVar3 != 0; uVar3 = uVar3 - 1) {
            iVar5 = *(int *)(iVar5 + 0xc);
          }
        }
      }
      else {
        puVar6 = (undefined4 *)*param_3;
        for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        uVar7 = 0;
        param_2 = 0;
        if (local_8 != 0) {
          do {
            uVar7 = 0;
            if (param_1 != 0) {
              iVar4 = param_2 << 4;
              do {
                local_c = FUN_005b5e0c(iVar5,*param_3 + iVar4);
                if (local_c < 0) {
                  return local_c;
                }
                iVar5 = *(int *)(iVar5 + 0xc);
                uVar7 = uVar7 + 1;
                iVar4 = iVar4 + 4;
              } while (uVar7 < param_1);
            }
            if (uVar7 < uVar1) {
              iVar4 = uVar1 - uVar7;
              do {
                iVar4 = iVar4 + -1;
                iVar5 = *(int *)(iVar5 + 0xc);
              } while (iVar4 != 0);
            }
            uVar7 = param_2 + 1;
            param_2 = uVar7;
          } while (uVar7 < local_8);
        }
        if (uVar7 < uVar2) {
          iVar4 = uVar2 - uVar7;
          uVar7 = uVar1;
          do {
            for (; uVar7 != 0; uVar7 = uVar7 - 1) {
              iVar5 = *(int *)(iVar5 + 0xc);
            }
            iVar4 = iVar4 + -1;
            uVar7 = uVar1;
          } while (iVar4 != 0);
        }
      }
      param_4 = param_4 + -1;
      param_3 = param_3 + 1;
    } while (param_4 != 0);
  }
  return local_c;
}


// ==== 0x5b6985 FUN_005b6985

int FUN_005b6985(uint param_1,uint param_2,int *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int local_c;
  uint local_8;
  
  local_c = 0;
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x14);
    uVar2 = *(uint *)(param_1 + 0x18);
    local_8 = 4;
    if (uVar1 < 5) {
      local_8 = uVar1;
    }
    param_1 = 4;
    iVar5 = param_2;
    if (uVar2 < 5) {
      param_1 = uVar2;
    }
    do {
      uVar4 = uVar1;
      if (*param_3 == 0) {
        for (; uVar3 = uVar2, uVar4 != 0; uVar4 = uVar4 - 1) {
          for (; uVar3 != 0; uVar3 = uVar3 - 1) {
            iVar5 = *(int *)(iVar5 + 0xc);
          }
        }
      }
      else {
        uVar4 = 0;
        param_2 = 0;
        if (local_8 != 0) {
          do {
            uVar4 = 0;
            if (param_1 != 0) {
              iVar6 = param_2 << 2;
              do {
                local_c = FUN_005b5dbd(iVar5,*(undefined4 *)(iVar6 + *param_3));
                if (local_c < 0) {
                  return local_c;
                }
                iVar5 = *(int *)(iVar5 + 0xc);
                uVar4 = uVar4 + 1;
                iVar6 = iVar6 + 0x10;
              } while (uVar4 < param_1);
            }
            if (uVar4 < uVar2) {
              iVar6 = uVar2 - uVar4;
              do {
                iVar6 = iVar6 + -1;
                iVar5 = *(int *)(iVar5 + 0xc);
              } while (iVar6 != 0);
            }
            uVar4 = param_2 + 1;
            param_2 = uVar4;
          } while (uVar4 < local_8);
        }
        if (uVar4 < uVar1) {
          iVar6 = uVar1 - uVar4;
          uVar4 = uVar2;
          do {
            for (; uVar4 != 0; uVar4 = uVar4 - 1) {
              iVar5 = *(int *)(iVar5 + 0xc);
            }
            iVar6 = iVar6 + -1;
            uVar4 = uVar2;
          } while (iVar6 != 0);
        }
      }
      param_4 = param_4 + -1;
      param_3 = param_3 + 1;
    } while (param_4 != 0);
  }
  return local_c;
}


// ==== 0x5b6a71 FUN_005b6a71

int FUN_005b6a71(uint param_1,uint param_2,int *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int local_c;
  uint local_8;
  
  local_c = 0;
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x18);
    uVar2 = *(uint *)(param_1 + 0x14);
    local_8 = 4;
    if (uVar2 < 5) {
      local_8 = uVar2;
    }
    param_1 = 4;
    iVar6 = param_2;
    if (uVar1 < 5) {
      param_1 = uVar1;
    }
    do {
      uVar5 = uVar2;
      if ((undefined4 *)*param_3 == (undefined4 *)0x0) {
        for (; uVar3 = uVar1, uVar5 != 0; uVar5 = uVar5 - 1) {
          for (; uVar3 != 0; uVar3 = uVar3 - 1) {
            iVar6 = *(int *)(iVar6 + 0xc);
          }
        }
      }
      else {
        puVar7 = (undefined4 *)*param_3;
        for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
        uVar5 = 0;
        param_2 = 0;
        if (local_8 != 0) {
          do {
            uVar5 = 0;
            if (param_1 != 0) {
              iVar4 = param_2 << 2;
              do {
                local_c = FUN_005b5e0c(iVar6,*param_3 + iVar4);
                if (local_c < 0) {
                  return local_c;
                }
                iVar6 = *(int *)(iVar6 + 0xc);
                uVar5 = uVar5 + 1;
                iVar4 = iVar4 + 0x10;
              } while (uVar5 < param_1);
            }
            if (uVar5 < uVar1) {
              iVar4 = uVar1 - uVar5;
              do {
                iVar4 = iVar4 + -1;
                iVar6 = *(int *)(iVar6 + 0xc);
              } while (iVar4 != 0);
            }
            uVar5 = param_2 + 1;
            param_2 = uVar5;
          } while (uVar5 < local_8);
        }
        if (uVar5 < uVar2) {
          iVar4 = uVar2 - uVar5;
          uVar5 = uVar1;
          do {
            for (; uVar5 != 0; uVar5 = uVar5 - 1) {
              iVar6 = *(int *)(iVar6 + 0xc);
            }
            iVar4 = iVar4 + -1;
            uVar5 = uVar1;
          } while (iVar4 != 0);
        }
      }
      param_4 = param_4 + -1;
      param_3 = param_3 + 1;
    } while (param_4 != 0);
  }
  return local_c;
}


// ==== 0x5b6b61 FUN_005b6b61

void FUN_005b6b61(uint param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x14);
    param_1 = 4;
    if (uVar1 < 5) {
      param_1 = uVar1;
    }
    do {
      uVar3 = 0;
      if (param_1 != 0) {
        do {
          iVar2 = FUN_005b5dbd(param_2,*(undefined4 *)(param_3 + uVar3 * 4));
          if (iVar2 < 0) {
            return;
          }
          param_2 = *(int *)(param_2 + 0xc);
          uVar3 = uVar3 + 1;
        } while (uVar3 < param_1);
      }
      if (uVar3 < uVar1) {
        iVar2 = uVar1 - uVar3;
        do {
          iVar2 = iVar2 + -1;
          param_2 = *(int *)(param_2 + 0xc);
        } while (iVar2 != 0);
      }
      param_4 = param_4 + -1;
      param_3 = param_3 + 0x10;
    } while (param_4 != 0);
  }
  return;
}


// ==== 0x5b6bd0 FUN_005b6bd0

int FUN_005b6bd0(uint param_1,int param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  iVar3 = 0;
  if (param_4 != 0) {
    uVar1 = *(uint *)(param_1 + 0x14);
    param_1 = 4;
    if (uVar1 < 5) {
      param_1 = uVar1;
    }
    puVar4 = param_3;
    for (iVar2 = (param_4 & 0xfffffff) << 2; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    do {
      uVar5 = 0;
      puVar4 = param_3;
      if (param_1 != 0) {
        do {
          iVar3 = FUN_005b5e0c(param_2,puVar4);
          if (iVar3 < 0) {
            return iVar3;
          }
          param_2 = *(int *)(param_2 + 0xc);
          uVar5 = uVar5 + 1;
          puVar4 = puVar4 + 1;
        } while (uVar5 < param_1);
      }
      if (uVar5 < uVar1) {
        iVar2 = uVar1 - uVar5;
        do {
          iVar2 = iVar2 + -1;
          param_2 = *(int *)(param_2 + 0xc);
        } while (iVar2 != 0);
      }
      param_4 = param_4 - 1;
      param_3 = param_3 + 4;
    } while (param_4 != 0);
  }
  return iVar3;
}


// ==== 0x5b6c59 FUN_005b6c59

int FUN_005b6c59(int *param_1,int *param_2,int *param_3,uint param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  int local_10;
  int *local_c;
  int local_8;
  
  piVar2 = (int *)*param_1;
  uVar9 = 0;
  local_c = (int *)0x0;
  local_8 = piVar2[4];
  iVar7 = piVar2[1];
  iVar3 = *piVar2;
  local_10 = 0;
  if ((param_4 != 0) || (local_8 == 0)) {
    local_8 = 1;
  }
  if (-1 < iVar7) {
    if (iVar7 < 4) {
      uVar6 = piVar2[6] * piVar2[5] * local_8;
      if (iVar3 == 1) {
        if (uVar6 != 0) {
          do {
            if (*param_2 == 0) break;
            iVar7 = uVar9 * 4;
            uVar9 = uVar9 + 1;
            *(uint *)(*(int *)(*param_2 + 8) + 0x18) = (uint)(*(int *)(*param_3 + iVar7) != 0);
            *param_2 = *(int *)(*param_2 + 0xc);
          } while (uVar9 < uVar6);
        }
        *param_3 = *param_3 + uVar6 * 4;
      }
      else if (iVar3 == 2) {
        uVar9 = 0;
        if (uVar6 != 0) {
          do {
            if (*param_2 == 0) break;
            *(undefined4 *)(*(int *)(*param_2 + 8) + 0x18) = *(undefined4 *)(*param_3 + uVar9 * 4);
            uVar9 = uVar9 + 1;
            *param_2 = *(int *)(*param_2 + 0xc);
          } while (uVar9 < uVar6);
        }
        *param_3 = *param_3 + uVar6 * 4;
      }
      else {
        if (iVar3 != 3) {
          return -0x7fffbffb;
        }
        if (uVar6 != 0) {
          do {
            if (*param_2 == 0) break;
            *(double *)(*(int *)(*param_2 + 8) + 0x18) = (double)*(float *)(*param_3 + uVar9 * 4);
            uVar9 = uVar9 + 1;
            *param_2 = *(int *)(*param_2 + 0xc);
          } while (uVar9 < uVar6);
        }
        *param_3 = *param_3 + uVar6 * 4;
      }
      *param_1 = *param_1 + 0x1c;
      goto LAB_005b6e9c;
    }
    if (iVar7 == 4) {
      if (iVar3 == 4) {
        while ((local_8 != 0 && (local_c = (int *)0x0, *param_2 != 0))) {
          pcVar8 = *(char **)*param_3;
          if (pcVar8 != (char *)0x0) {
            pcVar4 = pcVar8;
            do {
              cVar1 = *pcVar4;
              pcVar4 = pcVar4 + 1;
            } while (cVar1 != '\0');
            pcVar4 = pcVar4 + (1 - (int)(pcVar8 + 1));
            local_10 = thunk_FUN_005d65b0(pcVar4,&local_c);
            if (local_10 < 0) goto LAB_005b6e9c;
            pcVar5 = (char *)(**(code **)(*local_c + 0xc))(local_c);
            for (uVar9 = (uint)pcVar4 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
              *(undefined4 *)pcVar5 = *(undefined4 *)pcVar8;
              pcVar8 = pcVar8 + 4;
              pcVar5 = pcVar5 + 4;
            }
            for (uVar9 = (uint)pcVar4 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
              *pcVar5 = *pcVar8;
              pcVar8 = pcVar8 + 1;
              pcVar5 = pcVar5 + 1;
            }
          }
          piVar2 = *(int **)(*(int *)(*param_2 + 8) + 0x18);
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 8))(piVar2);
            *(undefined4 *)(*(int *)(*param_2 + 8) + 0x18) = 0;
          }
          *(int **)(*(int *)(*param_2 + 8) + 0x18) = local_c;
          *param_3 = *param_3 + 4;
          local_8 = local_8 + -1;
          *param_2 = *(int *)(*param_2 + 0xc);
        }
      }
      else {
        while ((local_8 != 0 && (*param_2 != 0))) {
          *param_3 = *param_3 + 4;
          local_8 = local_8 + -1;
          *param_2 = *(int *)(*param_2 + 0xc);
        }
      }
      *param_1 = *param_1 + 0x14;
      return local_10;
    }
    if (iVar7 == 5) {
      uVar9 = piVar2[5];
      *param_1 = (int)(piVar2 + 6);
      iVar7 = local_8;
      if (local_8 == 0) {
        return 0;
      }
      do {
        param_4 = 0;
        *param_1 = (int)(piVar2 + 6);
        if (uVar9 != 0) {
          do {
            local_10 = FUN_005b6c59(param_1,param_2,param_3,0);
            if (local_10 < 0) goto LAB_005b6e9c;
            param_4 = param_4 + 1;
          } while (param_4 < uVar9);
        }
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      goto LAB_005b6e9c;
    }
  }
  local_10 = -0x7fffbffb;
LAB_005b6e9c:
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  return local_10;
}


// ==== 0x5b6eb3 FUN_005b6eb3

void FUN_005b6eb3(void)

{
  undefined4 in_stack_00000010;
  
  FUN_005b6c59(&stack0x00000004,&stack0x00000008,&stack0x0000000c,in_stack_00000010);
  return;
}


// ==== 0x5b6ece FUN_005b6ece

int FUN_005b6ece(int *param_1,int *param_2,int *param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int local_8;
  
  piVar1 = (int *)*param_1;
  iVar2 = piVar1[1];
  iVar3 = *piVar1;
  iVar6 = piVar1[4];
  uVar7 = 0;
  local_8 = 0;
  if ((param_4 != 0) || (iVar6 == 0)) {
    iVar6 = 1;
  }
  if (iVar2 < 0) {
    return -0x7fffbffb;
  }
  if (3 < iVar2) {
    if (iVar2 == 4) {
      if (iVar3 == 4) {
        while ((iVar6 != 0 && (*param_2 != 0))) {
          piVar1 = *(int **)(*(int *)(*param_2 + 8) + 0x18);
          if (piVar1 == (int *)0x0) {
            *(undefined4 *)*param_3 = 0;
          }
          else {
            uVar4 = (**(code **)(*piVar1 + 0xc))(piVar1);
            *(undefined4 *)*param_3 = uVar4;
          }
          *param_3 = *param_3 + 4;
          iVar6 = iVar6 + -1;
          *param_2 = *(int *)(*param_2 + 0xc);
        }
      }
      else {
        while ((iVar6 != 0 && (*param_2 != 0))) {
          *(undefined4 *)*param_3 = 0;
          *param_3 = *param_3 + 4;
          iVar6 = iVar6 + -1;
          *param_2 = *(int *)(*param_2 + 0xc);
        }
      }
      *param_1 = *param_1 + 0x14;
      return 0;
    }
    if (iVar2 != 5) {
      return -0x7fffbffb;
    }
    uVar7 = piVar1[5];
    *param_1 = (int)(piVar1 + 6);
    do {
      if (iVar6 == 0) {
        return local_8;
      }
      param_4 = 0;
      *param_1 = (int)(piVar1 + 6);
      if (uVar7 != 0) {
        do {
          local_8 = FUN_005b6ece(param_1,param_2,param_3,0);
          if (local_8 < 0) {
            return local_8;
          }
          param_4 = param_4 + 1;
        } while (param_4 < uVar7);
      }
      iVar6 = iVar6 + -1;
    } while( true );
  }
  uVar5 = piVar1[6] * piVar1[5] * iVar6;
  if (iVar3 == 1) {
    if (uVar5 != 0) {
      do {
        if (*param_2 == 0) break;
        *(uint *)(*param_3 + uVar7 * 4) = (uint)(*(int *)(*(int *)(*param_2 + 8) + 0x18) != 0);
        uVar7 = uVar7 + 1;
        *param_2 = *(int *)(*param_2 + 0xc);
      } while (uVar7 < uVar5);
    }
  }
  else {
    if (iVar3 == 2) {
      uVar7 = 0;
      if (uVar5 != 0) {
        do {
          if (*param_2 == 0) break;
          *(undefined4 *)(*param_3 + uVar7 * 4) = *(undefined4 *)(*(int *)(*param_2 + 8) + 0x18);
          uVar7 = uVar7 + 1;
          *param_2 = *(int *)(*param_2 + 0xc);
        } while (uVar7 < uVar5);
      }
      *param_3 = *param_3 + uVar5 * 4;
      goto LAB_005b7078;
    }
    if (iVar3 != 3) {
      return -0x7fffbffb;
    }
    if (uVar5 != 0) {
      do {
        if (*param_2 == 0) break;
        *(float *)(*param_3 + uVar7 * 4) = (float)*(double *)(*(int *)(*param_2 + 8) + 0x18);
        uVar7 = uVar7 + 1;
        *param_2 = *(int *)(*param_2 + 0xc);
      } while (uVar7 < uVar5);
    }
  }
  *param_3 = *param_3 + uVar5 * 4;
LAB_005b7078:
  *param_1 = *param_1 + 0x1c;
  return 0;
}


// ==== 0x5b7091 FUN_005b7091

void FUN_005b7091(void)

{
  undefined4 in_stack_00000010;
  
  FUN_005b6ece(&stack0x00000004,&stack0x00000008,&stack0x0000000c,in_stack_00000010);
  return;
}


// ==== 0x5b70ac FUN_005b70ac

void * __thiscall FUN_005b70ac(void *param_1,byte param_2)

{
  FUN_005b5fe7();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5b70c8 FUN_005b70c8

void __fastcall FUN_005b70c8(int param_1)

{
  int iVar1;
  void *_Memory;
  
  if (*(int *)(param_1 + 0x28) != 0) {
    FUN_005b70ac(1);
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x2c);
  while (iVar1 != 0) {
    _Memory = *(void **)(param_1 + 0x2c);
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)((int)_Memory + 0x2c);
    *(undefined4 *)((int)_Memory + 0x2c) = 0;
    FUN_005b70c8();
    _free(_Memory);
    iVar1 = *(int *)(param_1 + 0x2c);
  }
  FUN_005b5e96();
  return;
}


// ==== 0x5b710e FUN_005b710e

int FUN_005b710e(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined1 local_3c [4];
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  int local_2c;
  undefined4 *local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  size_t local_18;
  int *local_14;
  undefined4 *local_10;
  int local_c;
  int local_8;
  
  iVar5 = 0;
  local_10 = (undefined4 *)0x0;
  pvVar2 = _malloc(0x1c);
  if (pvVar2 == (void *)0x0) {
    local_c = 0;
  }
  else {
    local_c = FUN_005b2aff();
  }
  if (local_c == 0) {
    return -0x7ff8fff2;
  }
  iVar1 = *(int *)(param_1 + 0x18);
  if ((((iVar1 == 0) || (*(int *)(iVar1 + 4) != 10)) ||
      (iVar3 = *(int *)(param_1 + 0x14), iVar3 == 0)) || (*(int *)(iVar3 + 4) != 2)) {
LAB_005b721a:
    iVar5 = -0x7fffbffb;
  }
  else if ((*(uint *)(iVar1 + 0x1c) & 2) == 0) {
    local_14 = (int *)(iVar3 + 0x10);
    if (((*local_14 != 9) || (local_2c = *(int *)(iVar3 + 0x18), local_2c == 0)) ||
       (*(int *)(iVar1 + 0x20) == 0)) goto LAB_005b721a;
    iVar5 = FUN_005b2d7a(*(int *)(iVar1 + 0x20),&local_24,local_3c,local_38,local_34,local_30,
                         &local_18);
    if (iVar5 < 0) {
      pcVar7 = "ID3DXEffectCompiler: There was a problem getting variable type";
LAB_005b71d2:
      FUN_005b1f01(local_8 + 0xc,local_14,0,pcVar7);
    }
    else {
      if (((local_24 != 0) && (local_24 != 4)) &&
         ((local_24 != 3 && ((local_24 != 1 && (local_24 != 2)))))) {
        FUN_005b1f01(local_8 + 0xc,local_14,0,
                     "ID3DXEffectCompiler: Only numeric types and strings are allowed as annotations"
                    );
        goto LAB_005b721a;
      }
      local_10 = _malloc(local_18);
      if (local_10 == (undefined4 *)0x0) {
        iVar5 = -0x7ff8fff2;
      }
      else {
        puVar6 = local_10;
        for (uVar4 = local_18 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        for (uVar4 = local_18 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar6 = 0;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
        local_28 = local_10;
        iVar5 = FUN_005b3588(*(undefined4 *)(iVar1 + 0x20),&local_28);
        if ((-1 < iVar5) && (iVar5 = FUN_005b2b74(local_10,local_18,&local_20), -1 < iVar5)) {
          iVar5 = FUN_005b3675(*(undefined4 *)(iVar1 + 0x20),local_14,0,0,param_3,local_c,&local_1c,
                               0);
          if (iVar5 < 0) {
            pcVar7 = "ID3DXEffectCompiler: Error initializing annotation type";
            goto LAB_005b71d2;
          }
          iVar5 = FUN_005b2d02(local_c);
          if (-1 < iVar5) {
            iVar5 = FUN_005b2c79(local_1c,0);
            if ((-1 < iVar5) && (iVar5 = FUN_005b2c79(local_20,0), -1 < iVar5)) {
              pvVar2 = _malloc(0x48);
              if (pvVar2 == (void *)0x0) {
                iVar3 = 0;
              }
              else {
                iVar3 = FUN_005b5fc3();
              }
              if (iVar3 == 0) {
                iVar5 = -0x7ff8fff2;
              }
              else {
                *(int *)(iVar3 + 0x20) = local_2c;
                *(undefined4 *)(iVar3 + 0x24) = 0;
                *(undefined4 *)(iVar3 + 0x28) = 0;
                *(undefined4 *)(iVar3 + 0x40) = local_1c;
                *(undefined4 *)(iVar3 + 0x3c) = local_20;
                *(undefined4 *)(iVar3 + 0x44) = 0;
                *(int *)(iVar3 + 0x2c) = iVar1;
                *(int *)(iVar3 + 0x34) = *param_4;
                *(int *)(iVar3 + 0x38) = *(int *)(param_1 + 0x14) + 0x10;
                *param_4 = iVar3;
              }
            }
            goto LAB_005b7229;
          }
        }
      }
    }
  }
  FUN_005b2b58(1);
LAB_005b7229:
  if (local_10 != (undefined4 *)0x0) {
    _free(local_10);
  }
  return iVar5;
}


// ==== 0x5b7369 FUN_005b7369

uint __thiscall FUN_005b7369(int param_1,char *param_2,undefined4 param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  char *pcVar6;
  
  if ((char *)((uint)param_2 & 0xffff) == param_2) {
    return 0;
  }
  if ((char *)((uint)param_2 & 0x7fffffff) != param_2) {
    return ~-(uint)(*(int *)~(uint)param_2 != 3) & ~(uint)param_2;
  }
  uVar3 = *(uint *)(param_1 + 0x120);
  if (uVar3 != 0) {
    do {
      iVar5 = *(int *)(*(int *)(uVar3 + 4) + 0x40) + *(int *)(uVar3 + 0x18) +
              *(int *)(param_1 + 0x118);
      piVar1 = (int *)(*(int *)(param_1 + 0x118) + *(int *)(iVar5 + 8));
      if (*piVar1 == 0) {
        piVar1 = (int *)0x0;
      }
      else {
        piVar1 = piVar1 + 1;
      }
      pcVar6 = param_2;
      cVar4 = *param_2;
      if (*param_2 == (char)*piVar1) {
        do {
          if (cVar4 == '\0') break;
          pcVar6 = pcVar6 + 1;
          piVar1 = (int *)((int)piVar1 + 1);
          cVar4 = *pcVar6;
        } while (*pcVar6 == *(char *)piVar1);
      }
      cVar4 = *pcVar6;
      if (cVar4 == (char)*piVar1) {
        return uVar3;
      }
      if ((char)*piVar1 == '\0') {
        if (cVar4 == '.') {
          pcVar6 = pcVar6 + 1;
          uVar3 = ~uVar3;
          goto LAB_005b7492;
        }
        if (cVar4 == '@') {
          uVar3 = FUN_005b5b7e(~uVar3,pcVar6 + 1,param_3);
          goto LAB_005b749a;
        }
        if (cVar4 == '[') {
          pcVar6 = pcVar6 + 1;
          if (*pcVar6 < '0') {
            return 0;
          }
          if ('9' < *pcVar6) {
            return 0;
          }
          uVar2 = _atoi(pcVar6);
          if (*(uint *)(iVar5 + 0x10) <= uVar2) {
            return 0;
          }
          for (; ('/' < *pcVar6 && (*pcVar6 < ':')); pcVar6 = pcVar6 + 1) {
          }
          if (*pcVar6 != ']') {
            return 0;
          }
          uVar3 = FUN_005b59d1(~uVar3,uVar2,param_3);
          if (uVar3 == 0) {
            return 0;
          }
          if (pcVar6[1] != '\0') {
            if (pcVar6[1] != '.') {
              return 0;
            }
            pcVar6 = pcVar6 + 2;
LAB_005b7492:
            uVar3 = FUN_005b626c(uVar3,pcVar6,param_3);
LAB_005b749a:
            if (uVar3 == 0) {
              return 0;
            }
          }
          return ~uVar3;
        }
      }
      uVar3 = *(uint *)(uVar3 + 0x34);
    } while (uVar3 != 0);
  }
  return 0;
}


// ==== 0x5b74a7 FUN_005b74a7

undefined4 FUN_005b74a7(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_3 == (undefined4 *)0x0) {
    return 0x8876086c;
  }
  iVar1 = FUN_005b7369(param_2,1);
  if (iVar1 == 0) {
    return 0x8876086c;
  }
  puVar5 = (undefined4 *)
           (*(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
           *(int *)(iVar1 + 0x18));
  puVar6 = param_3;
  for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  piVar2 = (int *)(puVar5[2] + *(int *)(param_1 + 0x118));
  if (*piVar2 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = piVar2 + 1;
  }
  *param_3 = piVar2;
  piVar2 = (int *)(puVar5[3] + *(int *)(param_1 + 0x118));
  if (*piVar2 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = piVar2 + 1;
  }
  param_3[1] = piVar2;
  param_3[10] = *(undefined4 *)(iVar1 + 0x14);
  iVar4 = *(int *)(*(int *)(iVar1 + 4) + 0x44);
  if (iVar4 == 0) {
    uVar3 = 4;
  }
  else {
    uVar3 = *(undefined4 *)(iVar4 + *(int *)(param_1 + 0x110));
  }
  param_3[9] = uVar3;
  param_3[3] = *puVar5;
  param_3[2] = puVar5[1];
  if (*(int *)(iVar1 + 0x10) == -1) {
    uVar3 = puVar5[4];
  }
  else {
    uVar3 = 0;
  }
  param_3[6] = uVar3;
  param_3[7] = 0;
  if ((*(int *)(iVar1 + 0x18) == 0) && (*(int *)(iVar1 + 0x10) == -1)) {
    param_3[7] = *(undefined4 *)(*(int *)(iVar1 + 4) + 0x28);
  }
  iVar1 = param_3[2];
  if (iVar1 == 1) {
    param_3[8] = 0;
    param_3[4] = 1;
    uVar3 = puVar5[5];
LAB_005b75c4:
    param_3[5] = uVar3;
  }
  else {
    if (iVar1 == 4) {
      param_3[8] = 0;
    }
    else {
      if (iVar1 != 5) {
        param_3[8] = 0;
        param_3[4] = puVar5[5];
        uVar3 = puVar5[6];
        goto LAB_005b75c4;
      }
      param_3[8] = puVar5[5];
    }
    param_3[4] = 0;
    param_3[5] = 0;
  }
  return 0;
}


// ==== 0x5b75d1 FUN_005b75d1

uint FUN_005b75d1(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 0) {
    if (param_3 < *(uint *)(param_1 + 0x100)) {
      uVar1 = *(uint *)(param_1 + 0x120);
      while (param_3 = param_3 + 1, param_3 < *(uint *)(param_1 + 0x100)) {
        uVar1 = *(uint *)(uVar1 + 0x34);
      }
      uVar1 = ~uVar1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    iVar2 = FUN_005b7369(param_2,1);
    if (((((iVar2 == 0) ||
          (iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
                   *(int *)(iVar2 + 0x18), *(int *)(iVar3 + 4) != 5)) ||
         ((*(int *)(iVar2 + 0x10) == -1 && (*(int *)(iVar3 + 0x10) != 0)))) ||
        (*(uint *)(iVar3 + 0x14) <= param_3)) ||
       ((*(int *)(iVar2 + 8) == 0 &&
        (iVar3 = FUN_005b618f(iVar2,*(uint *)(iVar3 + 0x14)), iVar3 < 0)))) {
      uVar1 = 0;
    }
    else {
      uVar1 = ~(param_3 * 0x20 + *(int *)(iVar2 + 8));
    }
  }
  return uVar1;
}


// ==== 0x5b766a FUN_005b766a

uint FUN_005b766a(int param_1,uint param_2,byte *param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int *piVar6;
  int *piVar7;
  byte *pbVar8;
  bool bVar9;
  
  if (param_2 == 0) {
    uVar4 = *(uint *)(param_1 + 0x120);
    if (uVar4 != 0) {
      do {
        piVar7 = (int *)(*(int *)(*(int *)(*(int *)(uVar4 + 4) + 0x40) + *(int *)(uVar4 + 0x18) +
                                  *(int *)(param_1 + 0x118) + 0xc) + *(int *)(param_1 + 0x118));
        pbVar8 = param_3;
        if ((*piVar7 == 0) || (pbVar5 = (byte *)(piVar7 + 1), pbVar5 == (byte *)0x0)) {
LAB_005b76e5:
          if (pbVar8 == (byte *)0x0) break;
        }
        else if (param_3 != (byte *)0x0) {
          do {
            bVar1 = *pbVar5;
            bVar9 = bVar1 < *pbVar8;
            if (bVar1 != *pbVar8) {
LAB_005b76d8:
              pbVar8 = (byte *)((1 - (uint)bVar9) - (uint)(bVar9 != 0));
              goto LAB_005b76e5;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar5[1];
            bVar9 = bVar1 < pbVar8[1];
            if (bVar1 != pbVar8[1]) goto LAB_005b76d8;
            pbVar5 = pbVar5 + 2;
            pbVar8 = pbVar8 + 2;
          } while (bVar1 != 0);
          pbVar8 = (byte *)0x0;
          goto LAB_005b76e5;
        }
        uVar4 = *(uint *)(uVar4 + 0x34);
      } while (uVar4 != 0);
      if (uVar4 != 0) {
LAB_005b77ed:
        return ~uVar4;
      }
    }
  }
  else {
    iVar2 = FUN_005b7369(param_2,1);
    if ((((iVar2 != 0) &&
         (iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(iVar2 + 0x18) +
                  *(int *)(param_1 + 0x118), *(int *)(iVar3 + 4) == 5)) &&
        ((*(int *)(iVar2 + 0x10) != -1 || (*(int *)(iVar3 + 0x10) == 0)))) &&
       ((uVar4 = *(uint *)(iVar3 + 0x14), *(int *)(iVar2 + 8) != 0 ||
        (iVar3 = FUN_005b618f(iVar2,uVar4), -1 < iVar3)))) {
      param_2 = 0;
      if (uVar4 != 0) {
        piVar7 = (int *)(*(int *)(iVar2 + 8) + 0x18);
        do {
          piVar6 = (int *)(*(int *)(*(int *)(piVar7[-5] + 0x40) + *(int *)(param_1 + 0x118) +
                                    *piVar7 + 0xc) + *(int *)(param_1 + 0x118));
          pbVar8 = param_3;
          if ((*piVar6 == 0) || (pbVar5 = (byte *)(piVar6 + 1), pbVar5 == (byte *)0x0)) {
joined_r0x005b77cb:
            if (pbVar8 == (byte *)0x0) break;
          }
          else if (param_3 != (byte *)0x0) {
            do {
              bVar1 = *pbVar5;
              bVar9 = bVar1 < *pbVar8;
              if (bVar1 != *pbVar8) {
LAB_005b77b9:
                pbVar8 = (byte *)((1 - (uint)bVar9) - (uint)(bVar9 != 0));
                goto joined_r0x005b77cb;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar5[1];
              bVar9 = bVar1 < pbVar8[1];
              if (bVar1 != pbVar8[1]) goto LAB_005b77b9;
              pbVar5 = pbVar5 + 2;
              pbVar8 = pbVar8 + 2;
            } while (bVar1 != 0);
            pbVar8 = (byte *)0x0;
            goto joined_r0x005b77cb;
          }
          param_2 = param_2 + 1;
          piVar7 = piVar7 + 8;
        } while (param_2 < uVar4);
      }
      if (param_2 != uVar4) {
        uVar4 = param_2 * 0x20 + *(int *)(iVar2 + 8);
        goto LAB_005b77ed;
      }
    }
  }
  return 0;
}


// ==== 0x5b77f6 FUN_005b77f6

void FUN_005b77f6(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005b626c(param_2,param_3,0);
  return;
}


// ==== 0x5b780c FUN_005b780c

undefined4 FUN_005b780c(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_4 == 0) || (param_3 != 0)) {
    iVar2 = FUN_005b7369(param_2,1);
    if ((iVar2 == 0) || ((param_4 != 0xffffffff && (param_4 < *(uint *)(iVar2 + 0x14))))) {
      uVar1 = 0x8876086c;
    }
    else {
      uVar1 = FUN_005b6eb3(*(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
                           *(int *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x1c),param_3,
                           *(int *)(iVar2 + 0x10) != -1);
    }
  }
  else {
    uVar1 = 0x8876086c;
  }
  return uVar1;
}


// ==== 0x5b7874 FUN_005b7874

undefined4 FUN_005b7874(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_4 == 0) || (param_3 != 0)) {
    iVar2 = FUN_005b7369(param_2,1);
    if ((iVar2 == 0) || ((param_4 != 0xffffffff && (param_4 < *(uint *)(iVar2 + 0x14))))) {
      uVar1 = 0x8876086c;
    }
    else {
      uVar1 = FUN_005b7091(*(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
                           *(int *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x1c),param_3,
                           *(int *)(iVar2 + 0x10) != -1);
    }
  }
  else {
    uVar1 = 0x8876086c;
  }
  return uVar1;
}


// ==== 0x5b78dc FUN_005b78dc

int FUN_005b78dc(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint local_10;
  undefined4 *local_c;
  uint local_8;
  
  if (param_3 == (undefined4 *)0x0) {
    return -0x7789f794;
  }
  iVar3 = FUN_005b7369(param_2,1);
  if ((iVar3 != 0) &&
     ((iVar4 = *(int *)(*(int *)(iVar3 + 4) + 0x40) + *(int *)((int)param_1 + 0x118) +
               *(int *)(iVar3 + 0x18), *(int *)(iVar4 + 0x10) == 0 || (*(int *)(iVar3 + 0x10) != -1)
      ))) {
    if (*(int *)(iVar4 + 4) == 2) {
      uVar1 = *(uint *)(iVar4 + 0x14);
      iVar3 = *(int *)(iVar3 + 0x1c);
      local_c = param_3;
      uVar2 = *(uint *)(iVar4 + 0x18);
      iVar4 = 0;
      local_8 = 1;
      local_10 = 4;
      if (uVar1 < 5) {
        local_10 = uVar1;
      }
      param_2 = 4;
      if (uVar2 < 5) {
        param_2 = uVar2;
      }
      do {
        param_3 = (undefined4 *)0x0;
        if (local_10 != 0) {
          param_1 = local_c;
          do {
            uVar6 = 0;
            puVar7 = param_1;
            if (param_2 != 0) {
              do {
                iVar4 = FUN_005b5dbd(iVar3,*puVar7);
                if (iVar4 < 0) {
                  return iVar4;
                }
                iVar3 = *(int *)(iVar3 + 0xc);
                uVar6 = uVar6 + 1;
                puVar7 = puVar7 + 1;
              } while (uVar6 < param_2);
            }
            if (uVar6 < uVar2) {
              iVar5 = uVar2 - uVar6;
              do {
                iVar5 = iVar5 + -1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (iVar5 != 0);
            }
            param_3 = (undefined4 *)((int)param_3 + 1);
            param_1 = param_1 + 4;
          } while (param_3 < local_10);
        }
        if (param_3 < uVar1) {
          iVar5 = uVar1 - (int)param_3;
          uVar6 = uVar2;
          do {
            for (; uVar6 != 0; uVar6 = uVar6 - 1) {
              iVar3 = *(int *)(iVar3 + 0xc);
            }
            iVar5 = iVar5 + -1;
            uVar6 = uVar2;
          } while (iVar5 != 0);
        }
        local_8 = local_8 + -1;
        local_c = local_c + 0x10;
      } while (local_8 != 0);
      return iVar4;
    }
    if (*(int *)(iVar4 + 4) == 3) {
      uVar1 = *(uint *)(iVar4 + 0x14);
      iVar3 = *(int *)(iVar3 + 0x1c);
      local_c = param_3;
      uVar2 = *(uint *)(iVar4 + 0x18);
      iVar4 = 0;
      local_10 = 1;
      local_8 = 4;
      if (uVar1 < 5) {
        local_8 = uVar1;
      }
      param_2 = 4;
      if (uVar2 < 5) {
        param_2 = uVar2;
      }
      do {
        param_3 = (undefined4 *)0x0;
        if (local_8 != 0) {
          param_1 = local_c;
          do {
            uVar6 = 0;
            puVar7 = param_1;
            if (param_2 != 0) {
              do {
                iVar4 = FUN_005b5dbd(iVar3,*puVar7);
                if (iVar4 < 0) {
                  return iVar4;
                }
                iVar3 = *(int *)(iVar3 + 0xc);
                uVar6 = uVar6 + 1;
                puVar7 = puVar7 + 4;
              } while (uVar6 < param_2);
            }
            if (uVar6 < uVar2) {
              iVar5 = uVar2 - uVar6;
              do {
                iVar5 = iVar5 + -1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (iVar5 != 0);
            }
            param_3 = (undefined4 *)((int)param_3 + 1);
            param_1 = param_1 + 1;
          } while (param_3 < local_8);
        }
        if (param_3 < uVar1) {
          iVar5 = uVar1 - (int)param_3;
          uVar6 = uVar2;
          do {
            for (; uVar6 != 0; uVar6 = uVar6 - 1) {
              iVar3 = *(int *)(iVar3 + 0xc);
            }
            iVar5 = iVar5 + -1;
            uVar6 = uVar2;
          } while (iVar5 != 0);
        }
        local_10 = local_10 + -1;
        local_c = local_c + 0x10;
      } while (local_10 != 0);
      return iVar4;
    }
  }
  return -0x7789f794;
}


// ==== 0x5b7aac FUN_005b7aac

int FUN_005b7aac(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int local_14;
  uint local_10;
  undefined4 *local_c;
  uint local_8;
  
  if (param_3 == (undefined4 *)0x0) {
    return -0x7789f794;
  }
  iVar3 = FUN_005b7369(param_2,1);
  if ((iVar3 != 0) &&
     ((iVar4 = *(int *)(*(int *)(iVar3 + 4) + 0x40) + *(int *)((int)param_1 + 0x118) +
               *(int *)(iVar3 + 0x18), *(int *)(iVar4 + 0x10) == 0 || (*(int *)(iVar3 + 0x10) != -1)
      ))) {
    if (*(int *)(iVar4 + 4) == 2) {
      iVar3 = *(int *)(iVar3 + 0x1c);
      uVar1 = *(uint *)(iVar4 + 0x18);
      local_14 = 0;
      uVar2 = *(uint *)(iVar4 + 0x14);
      local_8 = 1;
      local_c = param_3;
      local_10 = 4;
      if (uVar2 < 5) {
        local_10 = uVar2;
      }
      param_2 = 4;
      if (uVar1 < 5) {
        param_2 = uVar1;
      }
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *param_3 = 0;
        param_3 = param_3 + 1;
      }
      do {
        param_3 = (undefined4 *)0x0;
        if (local_10 != 0) {
          param_1 = local_c;
          do {
            uVar6 = 0;
            puVar5 = param_1;
            if (param_2 != 0) {
              do {
                local_14 = FUN_005b5e0c(iVar3,puVar5);
                if (local_14 < 0) {
                  return local_14;
                }
                iVar3 = *(int *)(iVar3 + 0xc);
                uVar6 = uVar6 + 1;
                puVar5 = puVar5 + 1;
              } while (uVar6 < param_2);
            }
            if (uVar6 < uVar1) {
              iVar4 = uVar1 - uVar6;
              do {
                iVar4 = iVar4 + -1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (iVar4 != 0);
            }
            param_3 = (undefined4 *)((int)param_3 + 1);
            param_1 = param_1 + 4;
          } while (param_3 < local_10);
        }
        if (param_3 < uVar2) {
          iVar4 = uVar2 - (int)param_3;
          uVar6 = uVar1;
          do {
            for (; uVar6 != 0; uVar6 = uVar6 - 1) {
              iVar3 = *(int *)(iVar3 + 0xc);
            }
            iVar4 = iVar4 + -1;
            uVar6 = uVar1;
          } while (iVar4 != 0);
        }
        local_8 = local_8 + -1;
        local_c = local_c + 0x10;
      } while (local_8 != 0);
      return local_14;
    }
    if (*(int *)(iVar4 + 4) == 3) {
      iVar3 = *(int *)(iVar3 + 0x1c);
      uVar1 = *(uint *)(iVar4 + 0x18);
      local_14 = 0;
      uVar2 = *(uint *)(iVar4 + 0x14);
      local_10 = 1;
      local_c = param_3;
      local_8 = 4;
      if (uVar2 < 5) {
        local_8 = uVar2;
      }
      param_2 = 4;
      if (uVar1 < 5) {
        param_2 = uVar1;
      }
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *param_3 = 0;
        param_3 = param_3 + 1;
      }
      do {
        param_3 = (undefined4 *)0x0;
        if (local_8 != 0) {
          param_1 = local_c;
          do {
            uVar6 = 0;
            puVar5 = param_1;
            if (param_2 != 0) {
              do {
                local_14 = FUN_005b5e0c(iVar3,puVar5);
                if (local_14 < 0) {
                  return local_14;
                }
                iVar3 = *(int *)(iVar3 + 0xc);
                uVar6 = uVar6 + 1;
                puVar5 = puVar5 + 4;
              } while (uVar6 < param_2);
            }
            if (uVar6 < uVar1) {
              iVar4 = uVar1 - uVar6;
              do {
                iVar4 = iVar4 + -1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (iVar4 != 0);
            }
            param_3 = (undefined4 *)((int)param_3 + 1);
            param_1 = param_1 + 1;
          } while (param_3 < local_8);
        }
        if (param_3 < uVar2) {
          iVar4 = uVar2 - (int)param_3;
          uVar6 = uVar1;
          do {
            for (; uVar6 != 0; uVar6 = uVar6 - 1) {
              iVar3 = *(int *)(iVar3 + 0xc);
            }
            iVar4 = iVar4 + -1;
            uVar6 = uVar1;
          } while (iVar4 != 0);
        }
        local_10 = local_10 + -1;
        local_c = local_c + 0x10;
      } while (local_10 != 0);
      return local_14;
    }
  }
  return -0x7789f794;
}


// ==== 0x5b7c92 FUN_005b7c92

int FUN_005b7c92(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint local_10;
  undefined4 *local_c;
  uint local_8;
  
  if (param_3 == (undefined4 *)0x0) {
    return -0x7789f794;
  }
  iVar3 = FUN_005b7369(param_2,1);
  if ((iVar3 != 0) &&
     ((iVar4 = *(int *)(*(int *)(iVar3 + 4) + 0x40) + *(int *)((int)param_1 + 0x118) +
               *(int *)(iVar3 + 0x18), *(int *)(iVar4 + 0x10) == 0 || (*(int *)(iVar3 + 0x10) != -1)
      ))) {
    if (*(int *)(iVar4 + 4) == 2) {
      uVar1 = *(uint *)(iVar4 + 0x14);
      iVar3 = *(int *)(iVar3 + 0x1c);
      local_c = param_3;
      uVar2 = *(uint *)(iVar4 + 0x18);
      iVar4 = 0;
      local_8 = 1;
      local_10 = 4;
      if (uVar1 < 5) {
        local_10 = uVar1;
      }
      param_2 = 4;
      if (uVar2 < 5) {
        param_2 = uVar2;
      }
      do {
        param_3 = (undefined4 *)0x0;
        if (local_10 != 0) {
          param_1 = local_c;
          do {
            uVar6 = 0;
            puVar7 = param_1;
            if (param_2 != 0) {
              do {
                iVar4 = FUN_005b5dbd(iVar3,*puVar7);
                if (iVar4 < 0) {
                  return iVar4;
                }
                iVar3 = *(int *)(iVar3 + 0xc);
                uVar6 = uVar6 + 1;
                puVar7 = puVar7 + 4;
              } while (uVar6 < param_2);
            }
            if (uVar6 < uVar2) {
              iVar5 = uVar2 - uVar6;
              do {
                iVar5 = iVar5 + -1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (iVar5 != 0);
            }
            param_3 = (undefined4 *)((int)param_3 + 1);
            param_1 = param_1 + 1;
          } while (param_3 < local_10);
        }
        if (param_3 < uVar1) {
          iVar5 = uVar1 - (int)param_3;
          uVar6 = uVar2;
          do {
            for (; uVar6 != 0; uVar6 = uVar6 - 1) {
              iVar3 = *(int *)(iVar3 + 0xc);
            }
            iVar5 = iVar5 + -1;
            uVar6 = uVar2;
          } while (iVar5 != 0);
        }
        local_8 = local_8 + -1;
        local_c = local_c + 0x10;
      } while (local_8 != 0);
      return iVar4;
    }
    if (*(int *)(iVar4 + 4) == 3) {
      uVar1 = *(uint *)(iVar4 + 0x14);
      iVar3 = *(int *)(iVar3 + 0x1c);
      local_c = param_3;
      uVar2 = *(uint *)(iVar4 + 0x18);
      iVar4 = 0;
      local_10 = 1;
      local_8 = 4;
      if (uVar1 < 5) {
        local_8 = uVar1;
      }
      param_2 = 4;
      if (uVar2 < 5) {
        param_2 = uVar2;
      }
      do {
        param_3 = (undefined4 *)0x0;
        if (local_8 != 0) {
          param_1 = local_c;
          do {
            uVar6 = 0;
            puVar7 = param_1;
            if (param_2 != 0) {
              do {
                iVar4 = FUN_005b5dbd(iVar3,*puVar7);
                if (iVar4 < 0) {
                  return iVar4;
                }
                iVar3 = *(int *)(iVar3 + 0xc);
                uVar6 = uVar6 + 1;
                puVar7 = puVar7 + 1;
              } while (uVar6 < param_2);
            }
            if (uVar6 < uVar2) {
              iVar5 = uVar2 - uVar6;
              do {
                iVar5 = iVar5 + -1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (iVar5 != 0);
            }
            param_3 = (undefined4 *)((int)param_3 + 1);
            param_1 = param_1 + 4;
          } while (param_3 < local_8);
        }
        if (param_3 < uVar1) {
          iVar5 = uVar1 - (int)param_3;
          uVar6 = uVar2;
          do {
            for (; uVar6 != 0; uVar6 = uVar6 - 1) {
              iVar3 = *(int *)(iVar3 + 0xc);
            }
            iVar5 = iVar5 + -1;
            uVar6 = uVar2;
          } while (iVar5 != 0);
        }
        local_10 = local_10 + -1;
        local_c = local_c + 0x10;
      } while (local_10 != 0);
      return iVar4;
    }
  }
  return -0x7789f794;
}


// ==== 0x5b7e62 FUN_005b7e62

int FUN_005b7e62(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int local_14;
  uint local_10;
  undefined4 *local_c;
  uint local_8;
  
  if (param_3 == (undefined4 *)0x0) {
    return -0x7789f794;
  }
  iVar3 = FUN_005b7369(param_2,1);
  if ((iVar3 != 0) &&
     ((iVar4 = *(int *)(*(int *)(iVar3 + 4) + 0x40) + *(int *)((int)param_1 + 0x118) +
               *(int *)(iVar3 + 0x18), *(int *)(iVar4 + 0x10) == 0 || (*(int *)(iVar3 + 0x10) != -1)
      ))) {
    if (*(int *)(iVar4 + 4) == 2) {
      iVar3 = *(int *)(iVar3 + 0x1c);
      uVar1 = *(uint *)(iVar4 + 0x18);
      local_14 = 0;
      uVar2 = *(uint *)(iVar4 + 0x14);
      local_8 = 1;
      local_c = param_3;
      local_10 = 4;
      if (uVar2 < 5) {
        local_10 = uVar2;
      }
      param_2 = 4;
      if (uVar1 < 5) {
        param_2 = uVar1;
      }
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *param_3 = 0;
        param_3 = param_3 + 1;
      }
      do {
        param_3 = (undefined4 *)0x0;
        if (local_10 != 0) {
          param_1 = local_c;
          do {
            uVar6 = 0;
            puVar5 = param_1;
            if (param_2 != 0) {
              do {
                local_14 = FUN_005b5e0c(iVar3,puVar5);
                if (local_14 < 0) {
                  return local_14;
                }
                iVar3 = *(int *)(iVar3 + 0xc);
                uVar6 = uVar6 + 1;
                puVar5 = puVar5 + 4;
              } while (uVar6 < param_2);
            }
            if (uVar6 < uVar1) {
              iVar4 = uVar1 - uVar6;
              do {
                iVar4 = iVar4 + -1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (iVar4 != 0);
            }
            param_3 = (undefined4 *)((int)param_3 + 1);
            param_1 = param_1 + 1;
          } while (param_3 < local_10);
        }
        if (param_3 < uVar2) {
          iVar4 = uVar2 - (int)param_3;
          uVar6 = uVar1;
          do {
            for (; uVar6 != 0; uVar6 = uVar6 - 1) {
              iVar3 = *(int *)(iVar3 + 0xc);
            }
            iVar4 = iVar4 + -1;
            uVar6 = uVar1;
          } while (iVar4 != 0);
        }
        local_8 = local_8 + -1;
        local_c = local_c + 0x10;
      } while (local_8 != 0);
      return local_14;
    }
    if (*(int *)(iVar4 + 4) == 3) {
      iVar3 = *(int *)(iVar3 + 0x1c);
      uVar1 = *(uint *)(iVar4 + 0x18);
      local_14 = 0;
      uVar2 = *(uint *)(iVar4 + 0x14);
      local_10 = 1;
      local_c = param_3;
      local_8 = 4;
      if (uVar2 < 5) {
        local_8 = uVar2;
      }
      param_2 = 4;
      if (uVar1 < 5) {
        param_2 = uVar1;
      }
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *param_3 = 0;
        param_3 = param_3 + 1;
      }
      do {
        param_3 = (undefined4 *)0x0;
        if (local_8 != 0) {
          param_1 = local_c;
          do {
            uVar6 = 0;
            puVar5 = param_1;
            if (param_2 != 0) {
              do {
                local_14 = FUN_005b5e0c(iVar3,puVar5);
                if (local_14 < 0) {
                  return local_14;
                }
                iVar3 = *(int *)(iVar3 + 0xc);
                uVar6 = uVar6 + 1;
                puVar5 = puVar5 + 1;
              } while (uVar6 < param_2);
            }
            if (uVar6 < uVar1) {
              iVar4 = uVar1 - uVar6;
              do {
                iVar4 = iVar4 + -1;
                iVar3 = *(int *)(iVar3 + 0xc);
              } while (iVar4 != 0);
            }
            param_3 = (undefined4 *)((int)param_3 + 1);
            param_1 = param_1 + 4;
          } while (param_3 < local_8);
        }
        if (param_3 < uVar2) {
          iVar4 = uVar2 - (int)param_3;
          uVar6 = uVar1;
          do {
            for (; uVar6 != 0; uVar6 = uVar6 - 1) {
              iVar3 = *(int *)(iVar3 + 0xc);
            }
            iVar4 = iVar4 + -1;
            uVar6 = uVar1;
          } while (iVar4 != 0);
        }
        local_10 = local_10 + -1;
        local_c = local_c + 0x10;
      } while (local_10 != 0);
      return local_14;
    }
  }
  return -0x7789f794;
}


// ==== 0x5b8048 FUN_005b8048

undefined4 FUN_005b8048(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_4 != 0) && (param_3 == 0)) {
    return 0x8876086c;
  }
  iVar1 = FUN_005b7369(param_2,1);
  if (iVar1 != 0) {
    iVar3 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
            *(int *)(iVar1 + 0x18);
    if (((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
       (*(int *)(iVar1 + 0x10) == -1)) {
      if (*(int *)(iVar3 + 4) == 2) {
        uVar2 = FUN_005b6451(iVar3,*(undefined4 *)(iVar1 + 0x1c),param_3,param_4);
        return uVar2;
      }
      if (*(int *)(iVar3 + 4) == 3) {
        uVar2 = FUN_005b65fe(iVar3,*(undefined4 *)(iVar1 + 0x1c),param_3,param_4);
        return uVar2;
      }
    }
  }
  return 0x8876086c;
}


// ==== 0x5b80c7 FUN_005b80c7

undefined4 FUN_005b80c7(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_4 != 0) && (param_3 == 0)) {
    return 0x8876086c;
  }
  iVar1 = FUN_005b7369(param_2,1);
  if (iVar1 != 0) {
    iVar3 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
            *(int *)(iVar1 + 0x18);
    if (((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
       (*(int *)(iVar1 + 0x10) == -1)) {
      if (*(int *)(iVar3 + 4) == 2) {
        uVar2 = FUN_005b65fe(iVar3,*(undefined4 *)(iVar1 + 0x1c),param_3,param_4);
        return uVar2;
      }
      if (*(int *)(iVar3 + 4) == 3) {
        uVar2 = FUN_005b6451(iVar3,*(undefined4 *)(iVar1 + 0x1c),param_3,param_4);
        return uVar2;
      }
    }
  }
  return 0x8876086c;
}


// ==== 0x5b8146 FUN_005b8146

undefined4 FUN_005b8146(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  if (param_4 != 0) {
    if (param_3 == 0) {
      uVar1 = 0x8876086c;
    }
    else {
      iVar2 = FUN_005b7369(param_2,1);
      if (iVar2 != 0) {
        iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
                *(int *)(iVar2 + 0x18);
        if (((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
           (*(int *)(iVar2 + 0x10) == -1)) {
          if (*(int *)(iVar3 + 4) == 2) {
            uVar1 = FUN_005b6520(iVar3,*(undefined4 *)(iVar2 + 0x1c),param_3,param_4);
            return uVar1;
          }
          if (*(int *)(iVar3 + 4) == 3) {
            uVar1 = FUN_005b66cd(iVar3,*(undefined4 *)(iVar2 + 0x1c),param_3,param_4);
            return uVar1;
          }
        }
      }
      uVar1 = 0x8876086c;
    }
  }
  return uVar1;
}


// ==== 0x5b81c6 FUN_005b81c6

undefined4 FUN_005b81c6(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  if (param_4 != 0) {
    if (param_3 == 0) {
      uVar1 = 0x8876086c;
    }
    else {
      iVar2 = FUN_005b7369(param_2,1);
      if (iVar2 != 0) {
        iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
                *(int *)(iVar2 + 0x18);
        if (((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
           (*(int *)(iVar2 + 0x10) == -1)) {
          if (*(int *)(iVar3 + 4) == 2) {
            uVar1 = FUN_005b66cd(iVar3,*(undefined4 *)(iVar2 + 0x1c),param_3,param_4);
            return uVar1;
          }
          if (*(int *)(iVar3 + 4) == 3) {
            uVar1 = FUN_005b6520(iVar3,*(undefined4 *)(iVar2 + 0x1c),param_3,param_4);
            return uVar1;
          }
        }
      }
      uVar1 = 0x8876086c;
    }
  }
  return uVar1;
}


// ==== 0x5b8246 FUN_005b8246

undefined4 FUN_005b8246(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_4 != 0) && (param_3 == 0)) {
    return 0x8876086c;
  }
  iVar1 = FUN_005b7369(param_2,1);
  if (iVar1 != 0) {
    iVar3 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
            *(int *)(iVar1 + 0x18);
    if (((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
       (*(int *)(iVar1 + 0x10) == -1)) {
      if (*(int *)(iVar3 + 4) == 2) {
        uVar2 = FUN_005b67ab(iVar3,*(undefined4 *)(iVar1 + 0x1c),param_3,param_4);
        return uVar2;
      }
      if (*(int *)(iVar3 + 4) == 3) {
        uVar2 = FUN_005b6985(iVar3,*(undefined4 *)(iVar1 + 0x1c),param_3,param_4);
        return uVar2;
      }
    }
  }
  return 0x8876086c;
}


// ==== 0x5b82c5 FUN_005b82c5

undefined4 FUN_005b82c5(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_4 != 0) && (param_3 == 0)) {
    return 0x8876086c;
  }
  iVar1 = FUN_005b7369(param_2,1);
  if (iVar1 != 0) {
    iVar3 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
            *(int *)(iVar1 + 0x18);
    if (((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
       (*(int *)(iVar1 + 0x10) == -1)) {
      if (*(int *)(iVar3 + 4) == 2) {
        uVar2 = FUN_005b6985(iVar3,*(undefined4 *)(iVar1 + 0x1c),param_3,param_4);
        return uVar2;
      }
      if (*(int *)(iVar3 + 4) == 3) {
        uVar2 = FUN_005b67ab(iVar3,*(undefined4 *)(iVar1 + 0x1c),param_3,param_4);
        return uVar2;
      }
    }
  }
  return 0x8876086c;
}


// ==== 0x5b8344 FUN_005b8344

undefined4 FUN_005b8344(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  if (param_4 != 0) {
    if (param_3 == 0) {
      uVar1 = 0x8876086c;
    }
    else {
      iVar2 = FUN_005b7369(param_2,1);
      if (iVar2 != 0) {
        iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
                *(int *)(iVar2 + 0x18);
        if (((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
           (*(int *)(iVar2 + 0x10) == -1)) {
          if (*(int *)(iVar3 + 4) == 2) {
            uVar1 = FUN_005b6897(iVar3,*(undefined4 *)(iVar2 + 0x1c),param_3,param_4);
            return uVar1;
          }
          if (*(int *)(iVar3 + 4) == 3) {
            uVar1 = FUN_005b6a71(iVar3,*(undefined4 *)(iVar2 + 0x1c),param_3,param_4);
            return uVar1;
          }
        }
      }
      uVar1 = 0x8876086c;
    }
  }
  return uVar1;
}


// ==== 0x5b83c4 FUN_005b83c4

undefined4 FUN_005b83c4(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  if (param_4 != 0) {
    if (param_3 == 0) {
      uVar1 = 0x8876086c;
    }
    else {
      iVar2 = FUN_005b7369(param_2,1);
      if (iVar2 != 0) {
        iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
                *(int *)(iVar2 + 0x18);
        if (((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
           (*(int *)(iVar2 + 0x10) == -1)) {
          if (*(int *)(iVar3 + 4) == 2) {
            uVar1 = FUN_005b6a71(iVar3,*(undefined4 *)(iVar2 + 0x1c),param_3,param_4);
            return uVar1;
          }
          if (*(int *)(iVar3 + 4) == 3) {
            uVar1 = FUN_005b6897(iVar3,*(undefined4 *)(iVar2 + 0x1c),param_3,param_4);
            return uVar1;
          }
        }
      }
      uVar1 = 0x8876086c;
    }
  }
  return uVar1;
}


// ==== 0x5b8444 FUN_005b8444

undefined4 FUN_005b8444(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (((param_4 == 0) || (param_3 != 0)) && (iVar1 = FUN_005b7369(param_2,1), iVar1 != 0)) {
    iVar3 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
            *(int *)(iVar1 + 0x18);
    if (((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
       ((*(int *)(iVar1 + 0x10) == -1 && (*(int *)(iVar3 + 4) == 1)))) {
      uVar2 = FUN_005b6b61(iVar3,*(undefined4 *)(iVar1 + 0x1c),param_3,param_4);
      return uVar2;
    }
  }
  return 0x8876086c;
}


// ==== 0x5b84b0 FUN_005b84b0

undefined4 FUN_005b84b0(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  if (param_4 != 0) {
    if (param_3 == 0) {
      uVar1 = 0x8876086c;
    }
    else {
      iVar2 = FUN_005b7369(param_2,1);
      if (iVar2 != 0) {
        iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
                *(int *)(iVar2 + 0x18);
        if ((((param_4 <= *(uint *)(iVar3 + 0x10)) && (*(uint *)(iVar3 + 0x10) != 0)) &&
            (*(int *)(iVar2 + 0x10) == -1)) && (*(int *)(iVar3 + 4) == 1)) {
          uVar1 = FUN_005b6bd0(iVar3,*(undefined4 *)(iVar2 + 0x1c),param_3,param_4);
          return uVar1;
        }
      }
      uVar1 = 0x8876086c;
    }
  }
  return uVar1;
}


// ==== 0x5b851c FUN_005b851c

int FUN_005b851c(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if (param_3 == 0) {
    iVar2 = -0x7789f794;
  }
  else {
    iVar2 = FUN_005b7369(param_2,1);
    if ((iVar2 == 0) ||
       (((iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
                  *(int *)(iVar2 + 0x18), *(int *)(iVar3 + 0x10) != 0 &&
         (*(int *)(iVar2 + 0x10) == -1)) || (*(int *)(iVar3 + 4) != 1)))) {
      iVar2 = -0x7789f794;
    }
    else {
      iVar5 = *(int *)(iVar2 + 0x1c);
      param_2 = param_3;
      uVar1 = *(uint *)(iVar3 + 0x14);
      iVar2 = 0;
      param_1 = 1;
      param_3 = 4;
      if (uVar1 < 5) {
        param_3 = uVar1;
      }
      do {
        uVar4 = 0;
        if (param_3 != 0) {
          do {
            iVar2 = FUN_005b5dbd(iVar5,*(undefined4 *)(param_2 + uVar4 * 4));
            if (iVar2 < 0) {
              return iVar2;
            }
            iVar5 = *(int *)(iVar5 + 0xc);
            uVar4 = uVar4 + 1;
          } while (uVar4 < param_3);
        }
        if (uVar4 < uVar1) {
          iVar3 = uVar1 - uVar4;
          do {
            iVar3 = iVar3 + -1;
            iVar5 = *(int *)(iVar5 + 0xc);
          } while (iVar3 != 0);
        }
        param_1 = param_1 + -1;
        param_2 = param_2 + 0x10;
      } while (param_1 != 0);
    }
  }
  return iVar2;
}


// ==== 0x5b85d0 FUN_005b85d0

int FUN_005b85d0(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int local_8;
  
  if (param_3 == (undefined4 *)0x0) {
    iVar2 = -0x7789f794;
  }
  else {
    iVar3 = FUN_005b7369(param_2,1);
    iVar2 = 0;
    if ((iVar3 == 0) ||
       (((iVar4 = *(int *)(*(int *)(iVar3 + 4) + 0x40) + *(int *)((int)param_1 + 0x118) +
                  *(int *)(iVar3 + 0x18), *(int *)(iVar4 + 0x10) != 0 &&
         (*(int *)(iVar3 + 0x10) == -1)) || (*(int *)(iVar4 + 4) != 1)))) {
      iVar2 = -0x7789f794;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x1c);
      local_8 = 1;
      uVar1 = *(uint *)(iVar4 + 0x14);
      param_1 = param_3;
      param_2 = 4;
      if (uVar1 < 5) {
        param_2 = uVar1;
      }
      *param_3 = 0;
      param_3[1] = 0;
      param_3[2] = 0;
      param_3[3] = 0;
      do {
        uVar5 = 0;
        if (param_2 != 0) {
          param_3 = param_1;
          do {
            iVar2 = FUN_005b5e0c(iVar3,param_3);
            if (iVar2 < 0) {
              return iVar2;
            }
            param_3 = param_3 + 1;
            iVar3 = *(int *)(iVar3 + 0xc);
            uVar5 = uVar5 + 1;
          } while (uVar5 < param_2);
        }
        if (uVar5 < uVar1) {
          iVar4 = uVar1 - uVar5;
          do {
            iVar4 = iVar4 + -1;
            iVar3 = *(int *)(iVar3 + 0xc);
          } while (iVar4 != 0);
        }
        local_8 = local_8 + -1;
        param_1 = param_1 + 4;
      } while (local_8 != 0);
    }
  }
  return iVar2;
}


// ==== 0x5b8694 FUN_005b8694

int FUN_005b8694(int param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int *piVar5;
  uint uVar6;
  int *local_c;
  int local_8;
  
  local_8 = 0;
  local_c = (int *)0x0;
  iVar2 = FUN_005b7369(param_2,1);
  if (((iVar2 == 0) ||
      (((piVar5 = (int *)(*(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
                         *(int *)(iVar2 + 0x18)), piVar5[4] != 0 && (*(int *)(iVar2 + 0x10) == -1))
       || (piVar5[1] != 4)))) || (*piVar5 != 4)) {
    local_8 = -0x7789f794;
LAB_005b8753:
    if (local_c != (int *)0x0) {
      (**(code **)(*local_c + 8))(local_c);
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(iVar2 + 0x1c) + 8);
    if (param_3 != (char *)0x0) {
      pcVar3 = param_3;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      pcVar3 = pcVar3 + (1 - (int)(param_3 + 1));
      local_8 = thunk_FUN_005d65b0(pcVar3,&local_c);
      if (local_8 < 0) goto LAB_005b8753;
      pcVar4 = (char *)(**(code **)(*local_c + 0xc))(local_c);
      for (uVar6 = (uint)pcVar3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar4 = *(undefined4 *)param_3;
        param_3 = param_3 + 4;
        pcVar4 = pcVar4 + 4;
      }
      for (uVar6 = (uint)pcVar3 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar4 = *param_3;
        param_3 = param_3 + 1;
        pcVar4 = pcVar4 + 1;
      }
    }
    piVar5 = *(int **)(iVar2 + 0x18);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 8))(piVar5);
      *(undefined4 *)(iVar2 + 0x18) = 0;
    }
    *(int **)(iVar2 + 0x18) = local_c;
  }
  return local_8;
}


// ==== 0x5b876a FUN_005b876a

undefined4 FUN_005b876a(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if (param_3 == (undefined4 *)0x0) {
    uVar4 = 0x8876086c;
  }
  else {
    iVar1 = FUN_005b7369(param_2,1);
    if (((iVar1 == 0) ||
        (((piVar3 = (int *)(*(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
                           *(int *)(iVar1 + 0x18)), piVar3[4] != 0 && (*(int *)(iVar1 + 0x10) == -1)
          ) || (piVar3[1] != 4)))) || (*piVar3 != 4)) {
      uVar4 = 0x8876086c;
    }
    else {
      iVar1 = *(int *)(*(int *)(iVar1 + 0x1c) + 8);
      *param_3 = 0;
      piVar3 = *(int **)(iVar1 + 0x18);
      if (piVar3 != (int *)0x0) {
        uVar2 = (**(code **)(*piVar3 + 0xc))(piVar3);
        *param_3 = uVar2;
      }
    }
  }
  return uVar4;
}


// ==== 0x5b87e0 FUN_005b87e0

undefined4 FUN_005b87e0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_005b7369(param_2,1);
  if ((iVar1 != 0) &&
     ((iVar2 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
               *(int *)(iVar1 + 0x18), *(int *)(iVar2 + 0x10) == 0 || (*(int *)(iVar1 + 0x10) != -1)
      ))) {
    if ((-1 < *(int *)(iVar2 + 4)) &&
       (((*(int *)(iVar2 + 4) < 4 && (*(int *)(iVar2 + 0x14) == 1)) && (*(int *)(iVar2 + 0x18) == 1)
        ))) {
      iVar1 = *(int *)(*(int *)(iVar1 + 0x1c) + 8);
      iVar2 = *(int *)(iVar1 + 0x10);
      if (((iVar2 == 0) || (iVar2 == 1)) || (iVar2 == 2)) {
        *(uint *)(iVar1 + 0x18) = (uint)(param_3 != 0);
        return 0;
      }
      if (iVar2 == 3) {
        *(double *)(iVar1 + 0x18) = (double)(param_3 != 0);
        return 0;
      }
    }
  }
  return 0x8876086c;
}


// ==== 0x5b8869 FUN_005b8869

undefined4 FUN_005b8869(int param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_3 == (uint *)0x0) {
    return 0x8876086c;
  }
  iVar1 = FUN_005b7369(param_2,1);
  if (((iVar1 != 0) &&
      ((((iVar2 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
                  *(int *)(iVar1 + 0x18), *(int *)(iVar2 + 0x10) == 0 ||
         (*(int *)(iVar1 + 0x10) != -1)) && (-1 < *(int *)(iVar2 + 4))) &&
       ((*(int *)(iVar2 + 4) < 4 && (*(int *)(iVar2 + 0x14) == 1)))))) &&
     (*(int *)(iVar2 + 0x18) == 1)) {
    iVar1 = *(int *)(*(int *)(iVar1 + 0x1c) + 8);
    iVar2 = *(int *)(iVar1 + 0x10);
    if (((iVar2 == 0) || (iVar2 == 1)) || (iVar2 == 2)) {
      *param_3 = (uint)(*(int *)(iVar1 + 0x18) != 0);
      return 0;
    }
    if (iVar2 == 3) {
      iVar1 = __ftol();
      *param_3 = (uint)(iVar1 != 0);
      return 0;
    }
  }
  return 0x8876086c;
}


// ==== 0x5b8912 FUN_005b8912

undefined4 FUN_005b8912(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar1 = FUN_005b7369(param_2,1);
  if (((iVar1 == 0) ||
      ((((iVar2 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
                  *(int *)(iVar1 + 0x18), *(int *)(iVar2 + 0x10) != 0 &&
         (*(int *)(iVar1 + 0x10) == -1)) || (*(int *)(iVar2 + 4) < 0)) ||
       ((3 < *(int *)(iVar2 + 4) || (*(int *)(iVar2 + 0x14) != 1)))))) ||
     (*(int *)(iVar2 + 0x18) != 1)) {
LAB_005b898e:
    uVar3 = 0x8876086c;
  }
  else {
    iVar1 = *(int *)(*(int *)(iVar1 + 0x1c) + 8);
    iVar2 = *(int *)(iVar1 + 0x10);
    if (iVar2 == 0) {
      param_3 = (uint)(param_3 != 0);
    }
    else if ((iVar2 != 1) && (iVar2 != 2)) {
      if (iVar2 == 3) {
        *(double *)(iVar1 + 0x18) = (double)(int)param_3;
        return 0;
      }
      goto LAB_005b898e;
    }
    *(uint *)(iVar1 + 0x18) = param_3;
  }
  return uVar3;
}


// ==== 0x5b899b FUN_005b899b

undefined4 FUN_005b899b(int param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_3 == (uint *)0x0) {
    return 0x8876086c;
  }
  iVar1 = FUN_005b7369(param_2,1);
  if (((iVar1 == 0) ||
      ((((iVar3 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
                  *(int *)(iVar1 + 0x18), *(int *)(iVar3 + 0x10) != 0 &&
         (*(int *)(iVar1 + 0x10) == -1)) || (*(int *)(iVar3 + 4) < 0)) ||
       ((3 < *(int *)(iVar3 + 4) || (*(int *)(iVar3 + 0x14) != 1)))))) ||
     (*(int *)(iVar3 + 0x18) != 1)) {
LAB_005b8a32:
    local_8 = 0x8876086c;
  }
  else {
    iVar1 = *(int *)(*(int *)(iVar1 + 0x1c) + 8);
    iVar3 = *(int *)(iVar1 + 0x10);
    if (iVar3 == 0) {
      *param_3 = (uint)(*(int *)(iVar1 + 0x18) != 0);
      return 0;
    }
    if ((iVar3 == 1) || (iVar3 == 2)) {
      uVar2 = *(uint *)(iVar1 + 0x18);
    }
    else {
      if (iVar3 != 3) goto LAB_005b8a32;
      uVar2 = __ftol();
    }
    *param_3 = uVar2;
  }
  return local_8;
}


// ==== 0x5b8a42 FUN_005b8a42

undefined4 FUN_005b8a42(int param_1,undefined4 param_2,float param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  iVar1 = FUN_005b7369(param_2,1);
  if (((iVar1 == 0) ||
      ((((iVar3 = *(int *)(*(int *)(iVar1 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
                  *(int *)(iVar1 + 0x18), *(int *)(iVar3 + 0x10) != 0 &&
         (*(int *)(iVar1 + 0x10) == -1)) || (*(int *)(iVar3 + 4) < 0)) ||
       ((3 < *(int *)(iVar3 + 4) || (*(int *)(iVar3 + 0x14) != 1)))))) ||
     (*(int *)(iVar3 + 0x18) != 1)) {
LAB_005b8ac9:
    uVar4 = 0x8876086c;
  }
  else {
    iVar1 = *(int *)(*(int *)(iVar1 + 0x1c) + 8);
    iVar3 = *(int *)(iVar1 + 0x10);
    if (iVar3 == 0) {
      iVar3 = __ftol();
      uVar2 = (uint)(iVar3 != 0);
    }
    else {
      if ((iVar3 != 1) && (iVar3 != 2)) {
        if (iVar3 == 3) {
          *(double *)(iVar1 + 0x18) = (double)param_3;
          return 0;
        }
        goto LAB_005b8ac9;
      }
      uVar2 = __ftol();
    }
    *(uint *)(iVar1 + 0x18) = uVar2;
  }
  return uVar4;
}


// ==== 0x5b8ad6 FUN_005b8ad6

undefined4 FUN_005b8ad6(int param_1,undefined4 param_2,float *param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_3 == (float *)0x0) {
    return 0x8876086c;
  }
  iVar2 = FUN_005b7369(param_2,1);
  if (((iVar2 == 0) ||
      (((iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
                 *(int *)(iVar2 + 0x18), *(int *)(iVar3 + 0x10) != 0 &&
        (*(int *)(iVar2 + 0x10) == -1)) || (*(int *)(iVar3 + 4) < 0)))) ||
     (((3 < *(int *)(iVar3 + 4) || (*(int *)(iVar3 + 0x14) != 1)) || (*(int *)(iVar3 + 0x18) != 1)))
     ) {
LAB_005b8b81:
    local_8 = 0x8876086c;
  }
  else {
    iVar2 = *(int *)(*(int *)(iVar2 + 0x1c) + 8);
    iVar3 = *(int *)(iVar2 + 0x10);
    if (iVar3 == 0) {
      fVar1 = (float)(*(int *)(iVar2 + 0x18) != 0);
    }
    else if (iVar3 == 1) {
      fVar1 = (float)*(int *)(iVar2 + 0x18);
    }
    else if (iVar3 == 2) {
      fVar1 = (float)*(int *)(iVar2 + 0x18);
      if (*(int *)(iVar2 + 0x18) < 0) {
        fVar1 = fVar1 + 4.2949673e+09;
      }
    }
    else {
      if (iVar3 != 3) goto LAB_005b8b81;
      fVar1 = (float)*(double *)(iVar2 + 0x18);
    }
    *param_3 = fVar1;
  }
  return local_8;
}


// ==== 0x5b8b91 FUN_005b8b91

undefined4 FUN_005b8b91(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = 0;
  if (((param_4 == 0) || (param_3 != 0)) && (iVar2 = FUN_005b7369(param_2,1), iVar2 != 0)) {
    iVar5 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
            *(int *)(iVar2 + 0x18);
    uVar1 = *(uint *)(iVar5 + 0x10);
    if (((((uVar1 != 0) && (*(int *)(iVar2 + 0x10) == -1)) &&
         ((param_4 <= uVar1 && ((-1 < *(int *)(iVar5 + 4) && (*(int *)(iVar5 + 4) < 4)))))) &&
        (*(int *)(iVar5 + 0x14) == 1)) && (*(int *)(iVar5 + 0x18) == 1)) {
      iVar2 = *(int *)(iVar2 + 0x1c);
      if (uVar1 == 0) {
        return 0;
      }
      do {
        if (iVar2 == 0) {
          return 0;
        }
        iVar5 = *(int *)(iVar2 + 8);
        iVar4 = *(int *)(iVar5 + 0x10);
        if (iVar4 == 0) {
          iVar4 = __ftol();
          uVar3 = (uint)(iVar4 != 0);
LAB_005b8c4e:
          *(uint *)(iVar5 + 0x18) = uVar3;
        }
        else {
          if ((iVar4 == 1) || (iVar4 == 2)) {
            uVar3 = __ftol();
            goto LAB_005b8c4e;
          }
          if (iVar4 != 3) {
            return 0x8876086c;
          }
          *(double *)(iVar5 + 0x18) = (double)*(float *)(param_3 + uVar6 * 4);
        }
        iVar2 = *(int *)(iVar2 + 0xc);
        uVar6 = uVar6 + 1;
        if (uVar1 <= uVar6) {
          return 0;
        }
      } while( true );
    }
  }
  return 0x8876086c;
}


// ==== 0x5b8c6d FUN_005b8c6d

undefined4 FUN_005b8c6d(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_4 != 0) {
    if ((param_3 != 0) && (iVar4 = FUN_005b7369(param_2,1), iVar4 != 0)) {
      iVar5 = *(int *)(*(int *)(iVar4 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
              *(int *)(iVar4 + 0x18);
      uVar1 = *(uint *)(iVar5 + 0x10);
      if (((uVar1 != 0) &&
          (((*(int *)(iVar4 + 0x10) == -1 && (param_4 <= uVar1)) && (-1 < *(int *)(iVar5 + 4))))) &&
         (((*(int *)(iVar5 + 4) < 4 && (*(int *)(iVar5 + 0x14) == 1)) &&
          (*(int *)(iVar5 + 0x18) == 1)))) {
        iVar4 = *(int *)(iVar4 + 0x1c);
        uVar6 = 0;
        if (uVar1 == 0) {
          return 0;
        }
        do {
          if (iVar4 == 0) {
            return 0;
          }
          iVar5 = *(int *)(iVar4 + 8);
          iVar2 = *(int *)(iVar5 + 0x10);
          if (iVar2 == 0) {
            fVar3 = (float)(*(int *)(iVar5 + 0x18) != 0);
          }
          else if (iVar2 == 1) {
            fVar3 = (float)*(int *)(iVar5 + 0x18);
          }
          else if (iVar2 == 2) {
            fVar3 = (float)*(int *)(iVar5 + 0x18);
            if (*(int *)(iVar5 + 0x18) < 0) {
              fVar3 = fVar3 + 4.2949673e+09;
            }
          }
          else {
            if (iVar2 != 3) break;
            fVar3 = (float)*(double *)(iVar5 + 0x18);
          }
          *(float *)(param_3 + uVar6 * 4) = fVar3;
          iVar4 = *(int *)(iVar4 + 0xc);
          uVar6 = uVar6 + 1;
          if (uVar1 <= uVar6) {
            return 0;
          }
        } while( true );
      }
    }
    local_8 = 0x8876086c;
  }
  return local_8;
}


// ==== 0x5b8d49 FUN_005b8d49

undefined4 FUN_005b8d49(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (((param_4 == 0) || (param_3 != 0)) && (iVar3 = FUN_005b7369(param_2,1), iVar3 != 0)) {
    iVar4 = *(int *)(*(int *)(iVar3 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
            *(int *)(iVar3 + 0x18);
    uVar1 = *(uint *)(iVar4 + 0x10);
    if (((((uVar1 != 0) && (*(int *)(iVar3 + 0x10) == -1)) &&
         ((param_4 <= uVar1 && ((-1 < *(int *)(iVar4 + 4) && (*(int *)(iVar4 + 4) < 4)))))) &&
        (*(int *)(iVar4 + 0x14) == 1)) && (*(int *)(iVar4 + 0x18) == 1)) {
      iVar3 = *(int *)(iVar3 + 0x1c);
      uVar5 = 0;
      if (uVar1 != 0) {
        do {
          if (iVar3 == 0) {
            return 0;
          }
          iVar4 = *(int *)(iVar3 + 8);
          iVar2 = *(int *)(iVar4 + 0x10);
          if (((iVar2 == 0) || (iVar2 == 1)) || (iVar2 == 2)) {
            *(uint *)(iVar4 + 0x18) = (uint)(*(int *)(param_3 + uVar5 * 4) != 0);
          }
          else {
            if (iVar2 != 3) {
              return 0x8876086c;
            }
            *(double *)(iVar4 + 0x18) = (double)(*(int *)(param_3 + uVar5 * 4) != 0);
          }
          iVar3 = *(int *)(iVar3 + 0xc);
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar1);
      }
      return 0;
    }
  }
  return 0x8876086c;
}


// ==== 0x5b8e16 FUN_005b8e16

undefined4 FUN_005b8e16(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_4 != 0) {
    if ((param_3 != 0) && (iVar2 = FUN_005b7369(param_2,1), iVar2 != 0)) {
      iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
              *(int *)(iVar2 + 0x18);
      uVar1 = *(uint *)(iVar3 + 0x10);
      if (((uVar1 != 0) &&
          ((((*(int *)(iVar2 + 0x10) == -1 && (param_4 <= uVar1)) && (-1 < *(int *)(iVar3 + 4))) &&
           ((*(int *)(iVar3 + 4) < 4 && (*(int *)(iVar3 + 0x14) == 1)))))) &&
         (*(int *)(iVar3 + 0x18) == 1)) {
        iVar2 = *(int *)(iVar2 + 0x1c);
        uVar4 = 0;
        if (uVar1 == 0) {
          return 0;
        }
        do {
          if (iVar2 == 0) {
            return 0;
          }
          iVar3 = *(int *)(*(int *)(iVar2 + 8) + 0x10);
          if (((iVar3 == 0) || (iVar3 == 1)) || (iVar3 == 2)) {
            *(uint *)(param_3 + uVar4 * 4) = (uint)(*(int *)(*(int *)(iVar2 + 8) + 0x18) != 0);
          }
          else {
            if (iVar3 != 3) break;
            iVar3 = __ftol();
            *(uint *)(param_3 + uVar4 * 4) = (uint)(iVar3 != 0);
          }
          iVar2 = *(int *)(iVar2 + 0xc);
          uVar4 = uVar4 + 1;
          if (uVar1 <= uVar4) {
            return 0;
          }
        } while( true );
      }
    }
    local_8 = 0x8876086c;
  }
  return local_8;
}


// ==== 0x5b8ee8 FUN_005b8ee8

undefined4 FUN_005b8ee8(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (((param_4 == 0) || (param_3 != 0)) && (iVar3 = FUN_005b7369(param_2,1), iVar3 != 0)) {
    iVar4 = *(int *)(*(int *)(iVar3 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
            *(int *)(iVar3 + 0x18);
    uVar1 = *(uint *)(iVar4 + 0x10);
    if (((((uVar1 != 0) && (*(int *)(iVar3 + 0x10) == -1)) &&
         ((param_4 <= uVar1 && ((-1 < *(int *)(iVar4 + 4) && (*(int *)(iVar4 + 4) < 4)))))) &&
        (*(int *)(iVar4 + 0x14) == 1)) && (*(int *)(iVar4 + 0x18) == 1)) {
      iVar3 = *(int *)(iVar3 + 0x1c);
      uVar5 = 0;
      if (uVar1 == 0) {
        return 0;
      }
      do {
        if (iVar3 == 0) {
          return 0;
        }
        iVar4 = *(int *)(iVar3 + 8);
        iVar2 = *(int *)(iVar4 + 0x10);
        if (iVar2 == 0) {
          uVar6 = (uint)(*(int *)(param_3 + uVar5 * 4) != 0);
LAB_005b8f8e:
          *(uint *)(iVar4 + 0x18) = uVar6;
        }
        else {
          if ((iVar2 == 1) || (iVar2 == 2)) {
            uVar6 = *(uint *)(param_3 + uVar5 * 4);
            goto LAB_005b8f8e;
          }
          if (iVar2 != 3) {
            return 0x8876086c;
          }
          *(double *)(iVar4 + 0x18) = (double)*(int *)(param_3 + uVar5 * 4);
        }
        iVar3 = *(int *)(iVar3 + 0xc);
        uVar5 = uVar5 + 1;
        if (uVar1 <= uVar5) {
          return 0;
        }
      } while( true );
    }
  }
  return 0x8876086c;
}


// ==== 0x5b8fac FUN_005b8fac

undefined4 FUN_005b8fac(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_4 != 0) {
    if ((param_3 != 0) && (iVar3 = FUN_005b7369(param_2,1), iVar3 != 0)) {
      iVar5 = *(int *)(*(int *)(iVar3 + 4) + 0x40) + *(int *)(param_1 + 0x118) +
              *(int *)(iVar3 + 0x18);
      uVar1 = *(uint *)(iVar5 + 0x10);
      if (((uVar1 != 0) &&
          ((((*(int *)(iVar3 + 0x10) == -1 && (param_4 <= uVar1)) && (-1 < *(int *)(iVar5 + 4))) &&
           ((*(int *)(iVar5 + 4) < 4 && (*(int *)(iVar5 + 0x14) == 1)))))) &&
         (*(int *)(iVar5 + 0x18) == 1)) {
        iVar3 = *(int *)(iVar3 + 0x1c);
        uVar6 = 0;
        if (uVar1 == 0) {
          return 0;
        }
        do {
          if (iVar3 == 0) {
            return 0;
          }
          iVar5 = *(int *)(iVar3 + 8);
          iVar2 = *(int *)(iVar5 + 0x10);
          if (iVar2 == 0) {
            *(uint *)(param_3 + uVar6 * 4) = (uint)(*(int *)(iVar5 + 0x18) != 0);
          }
          else {
            if ((iVar2 == 1) || (iVar2 == 2)) {
              uVar4 = *(undefined4 *)(iVar5 + 0x18);
            }
            else {
              if (iVar2 != 3) break;
              uVar4 = __ftol();
            }
            *(undefined4 *)(param_3 + uVar6 * 4) = uVar4;
          }
          iVar3 = *(int *)(iVar3 + 0xc);
          uVar6 = uVar6 + 1;
          if (uVar1 <= uVar6) {
            return 0;
          }
        } while( true );
      }
    }
    local_8 = 0x8876086c;
  }
  return local_8;
}


// ==== 0x5b907a FUN_005b907a

void * __thiscall FUN_005b907a(void *param_1,byte param_2)

{
  FUN_005b70c8();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5b9096 FUN_005b9096

undefined4 * __fastcall FUN_005b9096(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0069b5a8;
  FUN_005c5508();
  FUN_005ba06e();
  param_1[0x3e] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x44] = 0;
  param_1[0x46] = 0;
  param_1[1] = 1;
  return param_1;
}


// ==== 0x5b90e9 FUN_005b90e9

int __thiscall FUN_005b90e9(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  char *pcVar7;
  undefined1 local_54 [4];
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  undefined1 local_48 [4];
  int local_44;
  uint local_40;
  undefined4 *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  size_t local_28;
  int local_24;
  int *local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar4 = 0;
  local_2c = 0;
  local_18 = (undefined4 *)0x0;
  local_c = 0;
  local_8 = 0;
  pvVar1 = _malloc(0x1c);
  if (pvVar1 == (void *)0x0) {
    local_10 = 0;
  }
  else {
    local_10 = FUN_005b2aff();
  }
  if (local_10 != 0) {
    pvVar1 = _malloc(0x1c);
    if (pvVar1 == (void *)0x0) {
      local_c = 0;
    }
    else {
      local_c = FUN_005b2aff();
    }
    if (local_c != 0) {
      pvVar1 = _malloc(0x1c);
      if (pvVar1 == (void *)0x0) {
        local_8 = 0;
      }
      else {
        local_8 = FUN_005b2aff();
      }
      if (local_8 != 0) {
        pvVar1 = _malloc(0x48);
        if (pvVar1 == (void *)0x0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_005b5fc3();
        }
        if (iVar4 != 0) {
          local_14 = *(int *)(param_2 + 0x18);
          if ((((local_14 != 0) && (*(int *)(local_14 + 4) == 10)) &&
              (iVar6 = *(int *)(param_2 + 0x14), iVar6 != 0)) && (*(int *)(iVar6 + 4) == 2)) {
            uVar3 = *(uint *)(local_14 + 0x1c);
            iVar2 = 0;
            if ((uVar3 & 2) != 0) goto LAB_005b9549;
            local_20 = (int *)(iVar6 + 0x10);
            if ((*local_20 == 9) && (local_44 = *(int *)(iVar6 + 0x18), local_44 != 0)) {
              local_30 = 0;
              local_40 = (uVar3 >> 3 & 0x10 | uVar3 & 8) >> 3;
              iVar6 = *(int *)(local_14 + 0x2c);
              if (iVar6 != 0) {
                if ((*(int *)(iVar6 + 4) != 2) || (*(int *)(iVar6 + 0x10) != 9)) goto LAB_005b953d;
                local_30 = *(undefined4 *)(iVar6 + 0x18);
              }
              iVar2 = FUN_005b2d7a(*(undefined4 *)(local_14 + 0x20),&local_1c,local_54,local_50,
                                   local_4c,local_48,&local_28);
              if (iVar2 < 0) {
                pcVar7 = "ID3DXEffectCompiler: There was a problem getting variable type";
              }
              else {
                if ((local_1c == 0x12) || (local_1c == 0x11)) goto LAB_005b9549;
                iVar2 = FUN_005b3675(*(undefined4 *)(local_14 + 0x20),local_20,local_30,0,param_4,
                                     local_c,&local_38,0);
                if (-1 < iVar2) {
                  if ((local_1c < 10) || (0xe < local_1c)) {
                    local_18 = _malloc(local_28);
                    if (local_18 == (undefined4 *)0x0) goto LAB_005b9544;
                    puVar5 = local_18;
                    for (uVar3 = local_28 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
                      *puVar5 = 0;
                      puVar5 = puVar5 + 1;
                    }
                    for (uVar3 = local_28 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
                      *(undefined1 *)puVar5 = 0;
                      puVar5 = (undefined4 *)((int)puVar5 + 1);
                    }
                    local_3c = local_18;
                    iVar2 = FUN_005b3588(*(undefined4 *)(local_14 + 0x20),&local_3c);
                    if (iVar2 < 0) goto LAB_005b9549;
                    iVar2 = FUN_005b2b74(local_18,local_28,&local_24);
                    if (iVar2 < 0) goto LAB_005b9549;
                  }
                  else {
                    iVar6 = *(int *)(local_14 + 0x28);
                    local_34 = 0;
                    if (iVar6 != 0) {
                      if ((((*(int *)(iVar6 + 0x1c) != 0) ||
                           (iVar6 = *(int *)(iVar6 + 0x20), iVar6 == 0)) ||
                          (*(int *)(iVar6 + 4) != 1)) ||
                         ((iVar6 = *(int *)(iVar6 + 8), iVar6 == 0 || (*(int *)(iVar6 + 4) != 0xd)))
                         ) goto LAB_005b953d;
                      for (local_24 = *(int *)(iVar6 + 0x18); local_24 != 0;
                          local_24 = *(int *)(local_24 + 0xc)) {
                        iVar2 = FUN_005b3b78(local_24,0xffffffff,*(undefined4 *)(param_1 + 0x100),
                                             &local_34,local_8,param_4,0x100);
                        if (iVar2 < 0) goto LAB_005b9549;
                      }
                    }
                    iVar2 = FUN_005b2b74(&local_34,4,&local_24);
                    if (iVar2 < 0) goto LAB_005b9549;
                    iVar2 = FUN_005b2d02(local_8);
                    if (iVar2 < 0) goto LAB_005b9549;
                    local_8 = 0;
                  }
                  *(undefined4 *)(iVar4 + 0x28) = 0;
                  iVar6 = *(int *)(param_2 + 0x1c);
                  if (iVar6 != 0) {
                    do {
                      if (((*(int *)(iVar6 + 4) != 1) || (iVar2 = *(int *)(iVar6 + 8), iVar2 == 0))
                         || (*(int *)(iVar2 + 4) != 5)) goto LAB_005b953d;
                      if (*(int *)(iVar2 + 0x10) != 1) {
                        FUN_005b1f01(param_1 + 0xc,local_20,0,
                                     "ID3DXEffectCompiler: There was a problem getting annotations")
                        ;
                        goto LAB_005b953d;
                      }
                      iVar2 = FUN_005b710e(iVar2,local_10,param_4,iVar4 + 0x30);
                      if ((iVar2 < 0) && (-1 < local_2c)) {
                        local_2c = iVar2;
                      }
                      *(int *)(iVar4 + 0x28) = *(int *)(iVar4 + 0x28) + 1;
                      iVar6 = *(int *)(iVar6 + 0xc);
                    } while (iVar6 != 0);
                    iVar2 = local_2c;
                    if (local_2c < 0) goto LAB_005b9549;
                  }
                  iVar2 = FUN_005b2d02(local_c);
                  if (-1 < iVar2) {
                    local_c = 0;
                    iVar2 = FUN_005b2c79(local_38,0);
                    if (-1 < iVar2) {
                      iVar2 = FUN_005b2c79(local_24,0);
                      if (-1 < iVar2) {
                        iVar2 = FUN_005b2b74(&local_40,4,&param_4);
                        if (-1 < iVar2) {
                          iVar2 = FUN_005b2b74(iVar4 + 0x28,4,0);
                          if (-1 < iVar2) {
                            iVar2 = FUN_005b2d02(local_10);
                            if (-1 < iVar2) {
                              *(int *)(iVar4 + 0x20) = local_44;
                              *(undefined4 *)(iVar4 + 0x24) = local_30;
                              local_10 = 0;
                              *(undefined4 *)(iVar4 + 0x40) = local_38;
                              *(int *)(iVar4 + 0x3c) = local_24;
                              *(undefined4 *)(iVar4 + 0x44) = param_4;
                              *(int *)(iVar4 + 0x2c) = local_14;
                              *(int *)(iVar4 + 0x34) = *(int *)(param_1 + 0x120);
                              *(int *)(iVar4 + 0x38) = *(int *)(param_2 + 0x14) + 0x10;
                              *(int *)(param_1 + 0x120) = iVar4;
                              iVar4 = 0;
                              *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) + 1;
                            }
                          }
                        }
                      }
                    }
                  }
                  goto LAB_005b9549;
                }
                pcVar7 = "ID3DXEffectCompiler: Error initializing variable type";
              }
              FUN_005b1f01(param_1 + 0xc,local_20,0,pcVar7);
              goto LAB_005b9549;
            }
          }
LAB_005b953d:
          iVar2 = -0x7fffbffb;
          goto LAB_005b9549;
        }
      }
    }
  }
LAB_005b9544:
  iVar2 = -0x7ff8fff2;
LAB_005b9549:
  if (local_8 != 0) {
    FUN_005b2b58(1);
  }
  if (local_10 != 0) {
    FUN_005b2b58(1);
  }
  if (local_c != 0) {
    FUN_005b2b58(1);
  }
  if (iVar4 != 0) {
    FUN_005b70ac(1);
  }
  if (local_18 != (undefined4 *)0x0) {
    _free(local_18);
  }
  return iVar2;
}


// ==== 0x5b9598 FUN_005b9598

int FUN_005b9598(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = 0;
  local_8 = 0;
  local_c = 0;
  pvVar2 = _malloc(0x1c);
  if (pvVar2 == (void *)0x0) {
    local_14 = 0;
  }
  else {
    local_14 = FUN_005b2aff();
  }
  if (local_14 != 0) {
    pvVar2 = _malloc(0x1c);
    if (pvVar2 == (void *)0x0) {
      local_8 = 0;
    }
    else {
      local_8 = FUN_005b2aff();
    }
    if (local_8 != 0) {
      pvVar2 = _malloc(0x30);
      if (pvVar2 == (void *)0x0) {
        local_c = 0;
      }
      else {
        local_c = FUN_005b5f34();
      }
      iVar5 = local_c;
      if (local_c != 0) {
        iVar4 = *(int *)(param_1 + 0x14);
        local_1c = 0;
        if (iVar4 != 0) {
          if ((*(int *)(iVar4 + 4) != 2) || (*(int *)(iVar4 + 0x10) != 9)) {
LAB_005b96b4:
            iVar5 = -0x7fffbffb;
            goto LAB_005b9788;
          }
          local_1c = *(undefined4 *)(iVar4 + 0x18);
        }
        piVar1 = (int *)(local_c + 0x24);
        *piVar1 = 0;
        for (iVar4 = *(int *)(param_1 + 0x1c); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xc)) {
          if (((*(int *)(iVar4 + 4) != 1) || (iVar3 = *(int *)(iVar4 + 8), iVar3 == 0)) ||
             (*(int *)(iVar3 + 4) != 5)) goto LAB_005b96b4;
          if (*(int *)(iVar3 + 0x10) != 1) {
            FUN_005b1f01(local_18 + 0xc,0,0,
                         "ID3DXEffectCompiler: There was a problem getting annotations");
            goto LAB_005b96b4;
          }
          iVar3 = FUN_005b710e(iVar3,local_8,param_4,iVar5 + 0x28);
          if ((iVar3 < 0) && (-1 < local_10)) {
            local_10 = iVar3;
          }
          *piVar1 = *piVar1 + 1;
        }
        local_20 = 0;
        for (iVar5 = *(int *)(param_1 + 0x18); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0xc)) {
          iVar4 = FUN_005b3b78(iVar5,*(undefined4 *)(local_18 + 0xfc),param_2,&local_20,local_14,
                               param_4,0xffffffff);
          if ((iVar4 < 0) && (-1 < local_10)) {
            local_10 = iVar4;
          }
        }
        iVar5 = local_10;
        if (((((-1 < local_10) && (iVar5 = FUN_005b2c29(local_1c,&param_4), -1 < iVar5)) &&
             (iVar5 = FUN_005b2c79(param_4,0), -1 < iVar5)) &&
            ((iVar5 = FUN_005b2b74(piVar1,4,0), -1 < iVar5 &&
             (iVar5 = FUN_005b2b74(&local_20,4,0), -1 < iVar5)))) &&
           (iVar5 = FUN_005b2d02(local_8), -1 < iVar5)) {
          local_8 = 0;
          iVar5 = FUN_005b2d02(local_14);
          if (-1 < iVar5) {
            *(undefined4 *)(local_c + 0x20) = local_1c;
            *(int *)(local_c + 0x2c) = *param_5;
            *param_5 = local_c;
            return iVar5;
          }
        }
        goto LAB_005b9788;
      }
    }
  }
  iVar5 = -0x7ff8fff2;
LAB_005b9788:
  if (local_c != 0) {
    FUN_005b907a(1);
  }
  if (local_14 != 0) {
    FUN_005b2b58(1);
  }
  if (local_8 != 0) {
    FUN_005b2b58(1);
  }
  return iVar5;
}


// ==== 0x5b97bb FUN_005b97bb

void __fastcall FUN_005b97bb(int param_1)

{
  int iVar1;
  void *_Memory;
  
  if (*(int *)(param_1 + 0x30) != 0) {
    FUN_005b70ac(1);
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_005b907a(1);
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x34);
  while (iVar1 != 0) {
    _Memory = *(void **)(param_1 + 0x34);
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)((int)_Memory + 0x34);
    *(undefined4 *)((int)_Memory + 0x34) = 0;
    FUN_005b97bb();
    _free(_Memory);
    iVar1 = *(int *)(param_1 + 0x34);
  }
  FUN_005b5e96();
  return;
}


// ==== 0x5b9812 FUN_005b9812

void * __thiscall FUN_005b9812(void *param_1,byte param_2)

{
  FUN_005b97bb();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5b982e FUN_005b982e

void __fastcall FUN_005b982e(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  
  puVar1 = (undefined4 *)param_1[0x3e];
  *param_1 = &PTR_FUN_0069b5a8;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
    param_1[0x3e] = 0;
  }
  if (param_1[0x47] != 0) {
    FUN_005b9812(1);
    param_1[0x47] = 0;
  }
  if (param_1[0x48] != 0) {
    FUN_005b70ac(1);
    param_1[0x48] = 0;
  }
  if (param_1[0x49] != 0) {
    FUN_005b5fa7(1);
    param_1[0x49] = 0;
  }
  if (param_1[0x4a] != 0) {
    FUN_005b2ae3(1);
    param_1[0x4a] = 0;
  }
  pvVar2 = (void *)param_1[0x44];
  if (pvVar2 != (void *)0x0) {
    _free(pvVar2);
    param_1[0x44] = 0;
  }
  pvVar2 = (void *)param_1[0x46];
  if (pvVar2 != (void *)0x0) {
    _free(pvVar2);
    param_1[0x46] = 0;
  }
  FUN_005ba07f();
  FUN_005c55ad();
  return;
}


// ==== 0x5b98e3 FUN_005b98e3

void * __thiscall FUN_005b98e3(void *param_1,byte param_2)

{
  FUN_005b982e();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5b98ff FUN_005b98ff

int __thiscall FUN_005b98ff(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 local_18;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = 0;
  local_c = 0;
  iVar4 = 0;
  pvVar2 = _malloc(0x1c);
  if (pvVar2 == (void *)0x0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_005b2aff();
  }
  if (local_8 != 0) {
    pvVar2 = _malloc(0x1c);
    if (pvVar2 == (void *)0x0) {
      local_c = 0;
    }
    else {
      local_c = FUN_005b2aff();
    }
    if (local_c != 0) {
      pvVar2 = _malloc(0x38);
      if (pvVar2 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_005b5f14();
      }
      if (iVar4 != 0) {
        iVar5 = *(int *)(param_2 + 0x14);
        local_18 = 0;
        if (iVar5 != 0) {
          if ((*(int *)(iVar5 + 4) != 2) || (*(int *)(iVar5 + 0x10) != 9)) {
LAB_005b9b22:
            local_10 = -0x7fffbffb;
            goto LAB_005b9b2e;
          }
          local_18 = *(undefined4 *)(iVar5 + 0x18);
        }
        *(undefined4 *)(iVar4 + 0x24) = 0;
        for (iVar5 = *(int *)(param_2 + 0x1c); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0xc)) {
          if (((*(int *)(iVar5 + 4) != 1) || (iVar3 = *(int *)(iVar5 + 8), iVar3 == 0)) ||
             (*(int *)(iVar3 + 4) != 5)) goto LAB_005b9b22;
          if (*(int *)(iVar3 + 0x10) != 1) {
            pcVar6 = "ID3DXEffectCompiler: There was a problem getting annotations";
            goto LAB_005b9b0f;
          }
          iVar3 = FUN_005b710e(iVar3,local_8,param_4,iVar4 + 0x30);
          if ((iVar3 < 0) && (-1 < local_10)) {
            local_10 = iVar3;
          }
          *(int *)(iVar4 + 0x24) = *(int *)(iVar4 + 0x24) + 1;
        }
        piVar1 = (int *)(iVar4 + 0x28);
        *piVar1 = 0;
        iVar5 = *(int *)(param_2 + 0x18);
LAB_005b9a61:
        if (iVar5 != 0) {
          if (((*(int *)(iVar5 + 4) == 1) && (iVar3 = *(int *)(iVar5 + 8), iVar3 != 0)) &&
             (*(int *)(iVar3 + 4) == 5)) {
            if (*(int *)(iVar3 + 0x10) == 4) goto code_r0x005b9a3a;
            pcVar6 = "ID3DXEffectCompiler: Only pass allowed within a technique";
LAB_005b9b0f:
            FUN_005b1f01(param_1 + 0xc,0,0,pcVar6);
          }
          goto LAB_005b9b22;
        }
        if (((((-1 < local_10) && (local_10 = FUN_005b2c29(local_18,&param_4), -1 < local_10)) &&
             (local_10 = FUN_005b2c79(param_4,0), -1 < local_10)) &&
            ((local_10 = FUN_005b2b74(iVar4 + 0x24,4,0), -1 < local_10 &&
             (local_10 = FUN_005b2b74(piVar1,4,0), -1 < local_10)))) &&
           (local_10 = FUN_005b2d02(local_8), -1 < local_10)) {
          local_8 = 0;
          local_10 = FUN_005b2d02(local_c);
          if (-1 < local_10) {
            *(undefined4 *)(iVar4 + 0x20) = local_18;
            *(int *)(iVar4 + 0x34) = *(int *)(param_1 + 0x11c);
            *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
            *(int *)(param_1 + 0x11c) = iVar4;
            return local_10;
          }
        }
        goto LAB_005b9b2e;
      }
    }
  }
  local_10 = -0x7ff8fff2;
LAB_005b9b2e:
  if (iVar4 != 0) {
    FUN_005b9812(1);
  }
  if (local_8 != 0) {
    FUN_005b2b58(1);
  }
  if (local_c != 0) {
    FUN_005b2b58(1);
  }
  return local_10;
code_r0x005b9a3a:
  iVar3 = FUN_005b9598(iVar3,*piVar1,local_c,param_4,iVar4 + 0x2c);
  if ((iVar3 < 0) && (-1 < local_10)) {
    local_10 = iVar3;
  }
  *piVar1 = *piVar1 + 1;
  iVar5 = *(int *)(iVar5 + 0xc);
  goto LAB_005b9a61;
}


// ==== 0x5b9b60 FUN_005b9b60

undefined4 FUN_005b9b60(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(param_1 + 4);
  *piVar1 = *piVar1 + -1;
  uVar2 = *(undefined4 *)(param_1 + 4);
  if (*piVar1 == 0) {
    FUN_005b98e3(1);
    uVar2 = 0;
  }
  return uVar2;
}


// ==== 0x5b9b78 FUN_005b9b78

int __thiscall FUN_005b9b78(int param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  local_c = 0;
  local_1c = 0;
  pvVar1 = _malloc(0x1c);
  if (pvVar1 == (void *)0x0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_005b2aff();
  }
  if (local_8 == 0) {
LAB_005ba00d:
    iVar2 = -0x7ff8fff2;
LAB_005ba012:
    if (-1 < iVar2) goto LAB_005ba029;
  }
  else {
    pvVar1 = _malloc(0x1c);
    if (pvVar1 == (void *)0x0) {
      local_c = 0;
    }
    else {
      local_c = FUN_005b2aff();
    }
    if (local_c == 0) goto LAB_005ba00d;
    pvVar1 = _malloc(0x1c);
    if (pvVar1 == (void *)0x0) {
      local_14 = 0;
    }
    else {
      local_14 = FUN_005b2aff();
    }
    if (local_14 == 0) goto LAB_005ba00d;
    pvVar1 = _malloc(0x1c);
    if (pvVar1 == (void *)0x0) {
      local_18 = 0;
    }
    else {
      local_18 = FUN_005b2aff();
    }
    if (local_18 == 0) goto LAB_005ba00d;
    iVar2 = FUN_005b2b74(&local_1c,4,0);
    if (-1 < iVar2) {
      if ((param_2 == 0) || (*(int *)(param_2 + 4) != 3)) {
LAB_005b9d00:
        iVar2 = -0x7fffbffb;
        goto LAB_005ba016;
      }
      *(undefined4 *)(param_1 + 0x100) = 0;
      *(undefined4 *)(param_1 + 0xfc) = 0;
      *(undefined4 *)(param_1 + 0x104) = 0;
      *(undefined4 *)(param_1 + 0x108) = 1;
      iVar2 = *(int *)(param_2 + 0x1c);
      if (iVar2 == 0) {
LAB_005b9d0a:
        iVar2 = FUN_005b2b74(param_1 + 0x100,4,0);
        if ((((-1 < iVar2) && (iVar2 = FUN_005b2b74(param_1 + 0xfc,4,0), -1 < iVar2)) &&
            (iVar2 = FUN_005b2b74(param_1 + 0x108,4,0), -1 < iVar2)) &&
           (iVar2 = FUN_005b2d02(local_14), -1 < iVar2)) {
          local_14 = 0;
          iVar2 = FUN_005b2d02(local_18);
          if (-1 < iVar2) {
            local_18 = 0;
            *(undefined4 *)(param_1 + 0x10c) = 0;
            *(undefined4 *)(param_1 + 0x114) = 0;
            iVar2 = FUN_005b2d1d(0,(undefined4 *)(param_1 + 0x10c));
            if ((-1 < iVar2) && (iVar2 = FUN_005b2d1d(0,param_1 + 0x114), -1 < iVar2)) {
              for (iVar2 = *(int *)(param_1 + 0x120); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x34)) {
                *(undefined4 *)(iVar2 + 0x40) = *(undefined4 *)(*(int *)(iVar2 + 0x40) + 0x18);
                *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(*(int *)(iVar2 + 0x3c) + 0x18);
                *(undefined4 *)(iVar2 + 0x44) = *(undefined4 *)(*(int *)(iVar2 + 0x44) + 0x18);
                for (iVar3 = *(int *)(iVar2 + 0x30); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x34)) {
                  *(undefined4 *)(iVar3 + 0x40) = *(undefined4 *)(*(int *)(iVar3 + 0x40) + 0x18);
                  *(undefined4 *)(iVar3 + 0x3c) = *(undefined4 *)(*(int *)(iVar3 + 0x3c) + 0x18);
                  *(undefined4 *)(iVar3 + 0x44) = 0;
                }
              }
              for (iVar2 = *(int *)(param_1 + 0x11c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x34)) {
                for (iVar3 = *(int *)(iVar2 + 0x30); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x34)) {
                  *(undefined4 *)(iVar3 + 0x40) = *(undefined4 *)(*(int *)(iVar3 + 0x40) + 0x18);
                  *(undefined4 *)(iVar3 + 0x3c) = *(undefined4 *)(*(int *)(iVar3 + 0x3c) + 0x18);
                  *(undefined4 *)(iVar3 + 0x44) = 0;
                }
                for (iVar3 = *(int *)(iVar2 + 0x2c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x2c)) {
                  for (iVar4 = *(int *)(iVar3 + 0x28); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x34)) {
                    *(undefined4 *)(iVar4 + 0x40) = *(undefined4 *)(*(int *)(iVar4 + 0x40) + 0x18);
                    *(undefined4 *)(iVar4 + 0x3c) = *(undefined4 *)(*(int *)(iVar4 + 0x3c) + 0x18);
                    *(undefined4 *)(iVar4 + 0x44) = 0;
                  }
                }
              }
              for (iVar2 = *(int *)(param_1 + 0x128); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x14)) {
                *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(*(int *)(iVar2 + 0x1c) + 0x18);
                *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(*(int *)(iVar2 + 0x18) + 0x18);
              }
              pvVar1 = _malloc(*(size_t *)(param_1 + 0x10c));
              *(void **)(param_1 + 0x110) = pvVar1;
              if (pvVar1 != (void *)0x0) {
                pvVar1 = _malloc(*(size_t *)(param_1 + 0x114));
                *(void **)(param_1 + 0x118) = pvVar1;
                if (pvVar1 != (void *)0x0) {
                  iVar2 = FUN_005b2d1d(*(undefined4 *)(param_1 + 0x110),0);
                  if ((-1 < iVar2) &&
                     (iVar2 = FUN_005b2d1d(*(undefined4 *)(param_1 + 0x118),0), -1 < iVar2)) {
                    iVar3 = *(int *)(param_1 + 0x120);
LAB_005b9f3e:
                    if (iVar3 == 0) {
                      local_10 = *(int *)(param_1 + 0x11c);
                      while (local_10 != 0) {
                        iVar4 = local_10;
                        for (iVar3 = *(int *)(local_10 + 0x30); local_10 = iVar4, iVar3 != 0;
                            iVar3 = *(int *)(iVar3 + 0x34)) {
                          iVar2 = FUN_005b33cb(*(undefined4 *)(param_1 + 0x118),iVar3);
                          if (iVar2 < 0) {
                            pcVar5 = 
                            "ID3DXEffectCompiler: There was an error initializing technique annotation handles"
                            ;
                            goto LAB_005b9f55;
                          }
                          iVar4 = local_10;
                        }
                        for (local_1c = *(int *)(iVar4 + 0x2c); local_1c != 0;
                            local_1c = *(int *)(local_1c + 0x2c)) {
                          for (iVar3 = *(int *)(local_1c + 0x28); iVar3 != 0;
                              iVar3 = *(int *)(iVar3 + 0x34)) {
                            iVar2 = FUN_005b33cb(*(undefined4 *)(param_1 + 0x118),iVar3);
                            if (iVar2 < 0) {
                              pcVar5 = 
                              "ID3DXEffectCompiler: There was an error initializing pass annotation handles"
                              ;
                              goto LAB_005b9f55;
                            }
                            iVar4 = local_10;
                          }
                        }
                        local_10 = *(int *)(iVar4 + 0x34);
                      }
                      *(int *)(param_1 + 0xf8) = param_2;
                    }
                    else {
                      iVar2 = FUN_005b33cb(*(undefined4 *)(param_1 + 0x118),iVar3);
                      if (-1 < iVar2) goto code_r0x005b9f0f;
                      pcVar5 = 
                      "ID3DXEffectCompiler: There was an error initializing parameter handles";
LAB_005b9f55:
                      FUN_005b1f01(param_1 + 0xc,0,0,pcVar5);
                    }
                    goto LAB_005ba012;
                  }
                  goto LAB_005ba016;
                }
              }
              iVar2 = -0x7ff8fff2;
            }
          }
        }
        goto LAB_005ba016;
      }
      do {
        if ((*(int *)(iVar2 + 4) != 1) || (iVar3 = *(int *)(iVar2 + 8), iVar3 == 0)) {
LAB_005b9ced:
          FUN_005b1f01(param_1 + 0xc,0,0,
                       "ID3DXEffectCompiler: There was an unexpected error in the parse tree");
          goto LAB_005b9d00;
        }
        if (*(int *)(iVar3 + 4) != 0xb) {
          if (*(int *)(iVar3 + 4) != 5) goto LAB_005b9ced;
          iVar4 = *(int *)(iVar3 + 0x10);
          if (iVar4 != 0) {
            if (iVar4 == 1) {
              iVar3 = FUN_005b90e9(iVar3,local_14,local_c);
            }
            else if (iVar4 == 2) {
              iVar3 = FUN_005b6109(iVar3);
            }
            else {
              if (iVar4 != 3) goto LAB_005b9d00;
              iVar3 = FUN_005b98ff(iVar3,local_18,local_c);
            }
            if ((iVar3 < 0) && (-1 < local_10)) {
              local_10 = iVar3;
            }
          }
        }
        iVar2 = *(int *)(iVar2 + 0xc);
      } while (iVar2 != 0);
      iVar2 = local_10;
      if (-1 < local_10) goto LAB_005b9d0a;
      goto LAB_005ba012;
    }
  }
LAB_005ba016:
  FUN_005b1f01(param_1 + 0xc,0,0,"ID3DXEffectCompiler: There was an error initializing the compiler"
              );
LAB_005ba029:
  if (local_14 != 0) {
    FUN_005b2b58(1);
  }
  if (local_18 != 0) {
    FUN_005b2b58(1);
  }
  if (local_8 != 0) {
    FUN_005b2b58(1);
  }
  if (local_c != 0) {
    FUN_005b2b58(1);
  }
  return iVar2;
code_r0x005b9f0f:
  for (local_10 = *(int *)(iVar3 + 0x30); local_10 != 0; local_10 = *(int *)(local_10 + 0x34)) {
    iVar2 = FUN_005b33cb(*(undefined4 *)(param_1 + 0x118),local_10);
    if (iVar2 < 0) {
      pcVar5 = "ID3DXEffectCompiler: There was an error initializing parameter annotation handles";
      goto LAB_005b9f55;
    }
  }
  iVar3 = *(int *)(iVar3 + 0x34);
  goto LAB_005b9f3e;
}


// ==== 0x5ba06e FUN_005ba06e

void __fastcall FUN_005ba06e(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


// ==== 0x5ba07f FUN_005ba07f

void __fastcall FUN_005ba07f(int param_1)

{
  if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 8))(1);
  }
  if (*(undefined4 **)(param_1 + 0xc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0xc))(1);
  }
  if (*(undefined4 **)(param_1 + 0x10) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x10))(1);
  }
  return;
}


// ==== 0x5ba0ab FUN_005ba0ab

void FUN_005ba0ab(int param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  bool bVar3;
  char *pcVar4;
  undefined1 local_104 [255];
  undefined1 local_5;
  
  iVar1 = 0xd;
  bVar3 = true;
  pcVar4 = param_2;
  pcVar2 = "syntax error";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar3 = *pcVar4 == *pcVar2;
    pcVar4 = pcVar4 + 1;
    pcVar2 = pcVar2 + 1;
  } while (bVar3);
  if (!bVar3) {
    _vsnprintf(local_104,0x100,param_2,&stack0x0000000c);
    local_5 = 0;
    FUN_005b1f01(*(int *)(param_1 + 4) + 4,param_1 + 0x20,0,&DAT_006cc568,local_104);
    goto LAB_005ba1ce;
  }
  if (*(int *)(param_1 + 0x40) != 0) goto LAB_005ba1ce;
  iVar1 = *(int *)(param_1 + 0x20);
  if (iVar1 < 10) {
    if (iVar1 != 9) {
      if (iVar1 == 0) {
        pcVar4 = "version token";
      }
      else {
        if (iVar1 == 1) {
          iVar1 = param_1 + 0x28;
          goto LAB_005ba158;
        }
        if (iVar1 < 2) {
LAB_005ba17f:
          pcVar4 = "token";
        }
        else if (iVar1 < 5) {
          pcVar4 = "integer constant";
        }
        else {
          if (8 < iVar1) goto LAB_005ba17f;
          pcVar4 = "float constant";
        }
      }
      goto LAB_005ba199;
    }
    iVar1 = *(int *)(param_1 + 0x28);
LAB_005ba158:
    _snprintf(local_104,0x100,"token \'%s\'",iVar1);
  }
  else {
    if (iVar1 == 10) {
      pcVar4 = "string constant";
    }
    else if (iVar1 == 0xc) {
      pcVar4 = "end of line";
    }
    else {
      if (iVar1 != 0xd) goto LAB_005ba17f;
      pcVar4 = "end of file";
    }
LAB_005ba199:
    _snprintf(local_104,0x100,pcVar4);
  }
  FUN_005b1f01(*(int *)(param_1 + 4) + 4,(int *)(param_1 + 0x20),3000,"syntax error: unexpected %s",
               local_104);
LAB_005ba1ce:
  *(undefined4 *)(param_1 + 0x40) = 1;
  return;
}


// ==== 0x5ba1d9 FUN_005ba1d9

void FUN_005ba1d9(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_104 [255];
  undefined1 local_5;
  
  _vsnprintf(local_104,0x100,param_4,&stack0x00000014);
  local_5 = 0;
  FUN_005b1f01(*(int *)(param_1 + 4) + 4,param_2,param_3,&DAT_006cc568,local_104);
  *(undefined4 *)(param_1 + 0x40) = 1;
  return;
}


// ==== 0x5ba22d FUN_005ba22d

void FUN_005ba22d(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_104 [255];
  undefined1 local_5;
  
  _vsnprintf(local_104,0x100,param_4,&stack0x00000014);
  local_5 = 0;
  FUN_005b1fca(*(int *)(param_1 + 4) + 4,param_2,param_3,&DAT_006cc568,local_104);
  return;
}


// ==== 0x5ba278 FUN_005ba278

void FUN_005ba278(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_104 [255];
  undefined1 local_5;
  
  _vsnprintf(local_104,0x100,param_4,&stack0x00000014);
  local_5 = 0;
  FUN_005b1f01(*(int *)(param_1 + 4) + 4,param_2,param_3,&DAT_006cc568,local_104);
  *(undefined4 *)(param_1 + 0x40) = 1;
  *(undefined4 *)(param_1 + 0x44) = 1;
  return;
}


// ==== 0x5ba2ce FUN_005ba2ce

int __thiscall FUN_005ba2ce(int param_1,int param_2)

{
  if (param_2 == 0) {
    if (*(int *)(param_1 + 0x40) == 0) {
      FUN_005ba278(param_1,0,0,"internal error: production failed!");
    }
    *(undefined4 *)(param_1 + 0x40) = 1;
    *(undefined4 *)(param_1 + 0x44) = 1;
  }
  return param_2;
}


// ==== 0x5ba2ff FUN_005ba2ff

undefined4 __thiscall FUN_005ba2ff(int param_1,undefined4 param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((*(int *)(param_1 + 0xc) != 0) && (param_3 == 0)) {
    param_3 = *(int *)(*(int *)(param_1 + 0xc) + 0x14);
  }
  pvVar1 = _malloc(0x20);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_005d7c6e(param_2,param_3,0,*(undefined4 *)(param_1 + 0xc));
  }
  if (iVar2 == 0) {
    FUN_005ba278(param_1,0,0,"internal error: out of memory");
    uVar3 = 0x8007000e;
  }
  else {
    *(int *)(param_1 + 0xc) = iVar2;
    uVar3 = 0;
  }
  return uVar3;
}


// ==== 0x5ba35f FUN_005ba35f

undefined4 __fastcall FUN_005ba35f(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    FUN_005ba278(param_1,0,0,"internal error: scope underflow");
    return 0x80004005;
  }
  if (((*(int *)(iVar1 + 0x10) == 4) && (*(int *)(iVar1 + 0x1c) != 0)) &&
     (*(int *)(*(int *)(iVar1 + 0x1c) + 0x10) != 4)) {
    for (piVar3 = (int *)(iVar1 + 0x18); *piVar3 != 0; piVar3 = (int *)(*piVar3 + 0xc)) {
      *(undefined4 *)(*(int *)(*piVar3 + 8) + 0x2c) = 1;
    }
    *piVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x1c) + 0x18);
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 0x1c) + 0x18) =
         *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x18);
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x18) = 0;
  }
  puVar2 = *(undefined4 **)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0xc) = puVar2[7];
  puVar2[7] = 0;
  (**(code **)*puVar2)(1);
  return 0;
}


// ==== 0x5ba3df FUN_005ba3df

undefined4 __thiscall FUN_005ba3df(int param_1,int param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  int *piVar3;
  void *pvVar4;
  undefined4 *puVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  bool bVar11;
  undefined4 uVar12;
  char *pcVar13;
  byte *local_c;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    FUN_005ba278(param_1,0,0,"internal error: scope missing");
    uVar2 = 0x80004005;
  }
  else {
    iVar9 = *(int *)(param_2 + 0x14);
    piVar3 = (int *)(*(int *)(param_1 + 0xc) + 0x18);
    while (iVar6 = *piVar3, iVar6 != 0) {
      iVar8 = *(int *)(iVar6 + 8);
      if ((*(int *)(iVar8 + 0x2c) == 0) &&
         ((*(int *)(param_2 + 0x10) != 2 || (*(int *)(iVar8 + 0x10) != 2)))) {
        local_c = *(byte **)(*(int *)(iVar8 + 0x14) + 0x18);
        pbVar7 = *(byte **)(iVar9 + 0x18);
        do {
          bVar1 = *pbVar7;
          bVar11 = bVar1 < *local_c;
          if (bVar1 != *local_c) {
LAB_005ba469:
            iVar8 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
            goto LAB_005ba46e;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar7[1];
          bVar11 = bVar1 < local_c[1];
          if (bVar1 != local_c[1]) goto LAB_005ba469;
          local_c = local_c + 2;
          pbVar7 = pbVar7 + 2;
        } while (bVar1 != 0);
        iVar8 = 0;
LAB_005ba46e:
        if (iVar8 == 0) {
          if ((param_3 != 0) &&
             (iVar6 = FUN_005d7866(param_2,*(undefined4 *)(*piVar3 + 8)), iVar6 != 0)) {
            return 0;
          }
          uVar2 = *(undefined4 *)(iVar9 + 0x18);
          pcVar13 = "redefinition of \'%s\'";
          uVar12 = 0xbbb;
          goto LAB_005ba4f1;
        }
      }
      piVar3 = (int *)(iVar6 + 0xc);
    }
    iVar6 = *(int *)(*(int *)(param_1 + 0xc) + 0x1c);
    if (((iVar6 != 0) && (*(int *)(*(int *)(param_1 + 0xc) + 0x10) == 3)) &&
       (*(int *)(iVar6 + 0x10) == 2)) {
      for (iVar6 = *(int *)(iVar6 + 0x18); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0xc)) {
        pbVar7 = *(byte **)(*(int *)(*(int *)(iVar6 + 8) + 0x14) + 0x18);
        pbVar10 = *(byte **)(iVar9 + 0x18);
        do {
          bVar1 = *pbVar10;
          bVar11 = bVar1 < *pbVar7;
          if (bVar1 != *pbVar7) {
LAB_005ba534:
            iVar8 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
            goto LAB_005ba539;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar10[1];
          bVar11 = bVar1 < pbVar7[1];
          if (bVar1 != pbVar7[1]) goto LAB_005ba534;
          pbVar10 = pbVar10 + 2;
          pbVar7 = pbVar7 + 2;
        } while (bVar1 != 0);
        iVar8 = 0;
LAB_005ba539:
        if (iVar8 == 0) {
          uVar2 = *(undefined4 *)(iVar9 + 0x18);
          pcVar13 = "redefinition of formal parameter \'%s\'";
          uVar12 = 0xbdc;
LAB_005ba4f1:
          FUN_005ba1d9(param_1,iVar9 + 0x10,uVar12,pcVar13,uVar2);
          return 0x80004005;
        }
      }
    }
    pvVar4 = _malloc(0x14);
    if (pvVar4 == (void *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5 = (undefined4 *)FUN_005d78db(0,0,"Stmts");
    }
    if (puVar5 != (undefined4 *)0x0) {
      iVar9 = FUN_005d7885(param_2);
      puVar5[2] = iVar9;
      if (iVar9 != 0) {
        *(undefined4 *)(iVar9 + 0x20) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14);
        *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(puVar5[2] + 0x20);
        *(undefined4 *)(puVar5[2] + 0x24) = *(undefined4 *)(param_1 + 0x4c);
        *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(puVar5[2] + 0x24);
        *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
        puVar5[3] = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x18);
        *(undefined4 **)(*(int *)(param_1 + 0xc) + 0x18) = puVar5;
        return 0;
      }
      (**(code **)*puVar5)(1);
    }
    uVar2 = 0x8007000e;
  }
  return uVar2;
}


// ==== 0x5ba5c6 FUN_005ba5c6

undefined4 __fastcall FUN_005ba5c6(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x10) = puVar1[3];
    puVar1[3] = 0;
    (**(code **)*puVar1)(1);
  }
  return 0;
}


// ==== 0x5ba5e2 FUN_005ba5e2

undefined4 __fastcall FUN_005ba5e2(int param_1)

{
  if (*(int *)(param_1 + 0x10) == 0) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x10) + 8);
}


// ==== 0x5ba5ee FUN_005ba5ee

undefined4 __thiscall FUN_005ba5ee(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 == 1) {
    do {
      if (*(int *)(param_2 + 4) != 1) break;
      FUN_005ba5ee(*(undefined4 *)(param_2 + 8),param_3);
      param_2 = *(int *)(param_2 + 0xc);
    } while (param_2 != 0);
    if (param_2 == 0) {
      return 0;
    }
  }
  else if (iVar1 == 5) {
    param_2 = *(int *)(param_2 + 0x18);
  }
  else if (iVar1 == 7) {
    param_2 = *(int *)(param_2 + 0x10);
  }
  else {
    if (iVar1 == 8) {
      if (param_3 != 0) {
        *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) | 2;
        return 0;
      }
      *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) & 0xfd;
      return 0;
    }
    if (iVar1 != 10) {
      FUN_005ba278(param_1,0,0,"internal error: unknown node");
      return 0;
    }
    param_2 = *(int *)(param_2 + 0x20);
  }
  FUN_005ba5ee(param_2,param_3);
  return 0;
}


// ==== 0x5ba681 FUN_005ba681

undefined4 __thiscall FUN_005ba681(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((*(uint *)(param_2 + 0x10) & *(uint *)(param_3 + 0x10)) != 0) {
    FUN_005ba1d9(param_1,param_1 + 0x20,0xbe8,"duplicate usages specified");
  }
  if ((*(int *)(param_2 + 0x14) != 0) && (*(int *)(param_3 + 0x14) != 0)) {
    puVar2 = (undefined4 *)(*(int *)(param_3 + 0x14) + 0x10);
    puVar3 = (undefined4 *)(param_1 + 0x20);
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_005ba0ab(param_1,"syntax error");
  }
  *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | *(uint *)(param_3 + 0x10);
  if ((*(int *)(param_2 + 0x14) == 0) && (*(int *)(param_3 + 0x14) != 0)) {
    iVar1 = FUN_005d7885(*(int *)(param_3 + 0x14));
    *(int *)(param_2 + 0x14) = iVar1;
    if (iVar1 == 0) {
      return 0x8007000e;
    }
  }
  return 0;
}


// ==== 0x5ba70c FUN_005ba70c

uint __thiscall FUN_005ba70c(undefined4 param_1,int param_2)

{
  int iVar1;
  
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          if (param_2 == 0) {
            return 0;
          }
          iVar1 = *(int *)(param_2 + 4);
          if (iVar1 != 1) break;
          iVar1 = FUN_005ba70c(*(undefined4 *)(param_2 + 8));
          if (iVar1 != 0) {
            return 1;
          }
          param_2 = *(int *)(param_2 + 0xc);
        }
        if (iVar1 != 5) break;
        param_2 = *(int *)(param_2 + 0x18);
      }
      if (iVar1 != 7) break;
      param_2 = *(int *)(param_2 + 0x10);
    }
    if (iVar1 == 8) {
      return *(uint *)(param_2 + 0x20) & 0x200;
    }
    if (iVar1 != 10) break;
    param_2 = *(int *)(param_2 + 0x20);
  }
  FUN_005ba278(param_1,0,0,"internal error: unknown node");
  return 0;
}


// ==== 0x5ba77a FUN_005ba77a

bool FUN_005ba77a(int param_1)

{
  bool bVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 4) != 8)) {
    bVar1 = false;
  }
  else {
    bVar1 = *(int *)(param_1 + 0x10) == 0;
  }
  return bVar1;
}


// ==== 0x5ba799 FUN_005ba799

undefined4 __thiscall FUN_005ba799(undefined4 param_1,int param_2)

{
  int iVar1;
  
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          if (param_2 == 0) {
            return 1;
          }
          iVar1 = *(int *)(param_2 + 4);
          if (iVar1 != 1) break;
          iVar1 = FUN_005ba799(*(undefined4 *)(param_2 + 8));
          if (iVar1 == 0) {
            return 0;
          }
          param_2 = *(int *)(param_2 + 0xc);
        }
        if (iVar1 != 5) break;
        param_2 = *(int *)(param_2 + 0x18);
      }
      if (iVar1 != 7) break;
      param_2 = *(int *)(param_2 + 0x10);
    }
    if (iVar1 == 8) break;
    if (iVar1 != 10) {
      FUN_005ba278(param_1,0,0,"internal error: unknown node");
      return 0;
    }
    param_2 = *(int *)(param_2 + 0x20);
  }
  if (*(int *)(param_2 + 0x10) < 0) {
    return 0;
  }
  if (2 < *(int *)(param_2 + 0x10)) {
    return 0;
  }
  return 1;
}


// ==== 0x5ba80b FUN_005ba80b

int __thiscall FUN_005ba80b(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = 0;
  if (param_2 == 0) {
    return 0;
  }
  do {
    if (*(int *)(param_2 + 4) != 1) break;
    iVar1 = FUN_005ba80b(*(undefined4 *)(param_2 + 8));
    param_2 = *(int *)(param_2 + 0xc);
    iVar2 = iVar2 + iVar1;
  } while (param_2 != 0);
  if (param_2 == 0) {
    return iVar2;
  }
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 == 5) {
    uVar3 = *(undefined4 *)(param_2 + 0x18);
  }
  else {
    if (iVar1 == 7) {
      iVar1 = FUN_005ba80b(*(undefined4 *)(param_2 + 0x10));
      iVar1 = iVar1 * *(int *)(param_2 + 0x14);
      goto LAB_005ba88c;
    }
    if (iVar1 == 8) {
      iVar1 = *(int *)(param_2 + 0x1c) * *(int *)(param_2 + 0x18);
      goto LAB_005ba88c;
    }
    if (iVar1 != 10) {
      FUN_005ba278(param_1,0,0,"internal error: unknown node");
      return 0;
    }
    uVar3 = *(undefined4 *)(param_2 + 0x20);
  }
  iVar1 = FUN_005ba80b(uVar3);
LAB_005ba88c:
  return iVar1 + iVar2;
}


// ==== 0x5ba894 FUN_005ba894

bool FUN_005ba894(int param_1,int param_2)

{
  int iVar1;
  
LAB_005ba8a1:
  while( true ) {
    if (param_1 == 0) {
      return param_2 == 0;
    }
    iVar1 = *(int *)(param_1 + 4);
    if (iVar1 != 1) break;
    if (param_2 == 0) {
      return false;
    }
    if (*(int *)(param_2 + 4) != 1) break;
    iVar1 = FUN_005ba894(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_2 + 8));
    if (iVar1 == 0) {
      return false;
    }
    param_1 = *(int *)(param_1 + 0xc);
    param_2 = *(int *)(param_2 + 0xc);
  }
  if ((param_2 != 0) && (iVar1 == *(int *)(param_2 + 4))) {
    if (iVar1 == 5) {
      param_2 = *(int *)(param_2 + 0x18);
      param_1 = *(int *)(param_1 + 0x18);
      goto LAB_005ba8a1;
    }
    if (iVar1 == 7) {
      if (*(int *)(param_1 + 0x14) == *(int *)(param_2 + 0x14)) {
        param_2 = *(int *)(param_2 + 0x10);
        param_1 = *(int *)(param_1 + 0x10);
        goto LAB_005ba8a1;
      }
    }
    else {
      if (iVar1 == 8) {
        if (*(int *)(param_1 + 0x10) != *(int *)(param_2 + 0x10)) {
          return false;
        }
        if (*(int *)(param_1 + 0x14) != *(int *)(param_2 + 0x14)) {
          return false;
        }
        if (*(int *)(param_1 + 0x18) != *(int *)(param_2 + 0x18)) {
          return false;
        }
        if (*(int *)(param_1 + 0x1c) != *(int *)(param_2 + 0x1c)) {
          return false;
        }
        return true;
      }
      if (iVar1 == 10) {
        param_2 = *(int *)(param_2 + 0x20);
        param_1 = *(int *)(param_1 + 0x20);
        goto LAB_005ba8a1;
      }
    }
  }
  return false;
}


// ==== 0x5ba942 FUN_005ba942

void FUN_005ba942(char *param_1,uint param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char local_108 [255];
  undefined1 local_9;
  char *local_8;
  
  local_8 = local_108;
  if (param_3 == 0) {
    local_8 = "void";
    goto LAB_005bab58;
  }
  iVar4 = *(int *)(param_3 + 4);
  if (iVar4 == 1) {
    iVar4 = FUN_005ba70c(param_3);
    pcVar5 = "const ";
    if (iVar4 == 0) {
      pcVar5 = "";
    }
    pcVar3 = (char *)FUN_005ba80b(param_3);
    pcVar8 = "%sstruct{%u}";
  }
  else {
    if (iVar4 == 7) {
      iVar4 = *(int *)(param_3 + 4);
      iVar2 = param_3;
      while (iVar4 == 7) {
        iVar2 = *(int *)(iVar2 + 0x10);
        iVar4 = *(int *)(iVar2 + 4);
      }
      iVar4 = FUN_005ba942(local_108,0xff,iVar2);
      for (; *(int *)(param_3 + 4) == 7; param_3 = *(int *)(param_3 + 0x10)) {
        _snprintf(local_108 + iVar4,0xff - iVar4,&DAT_0069efe8,*(undefined4 *)(param_3 + 0x14));
        pcVar5 = local_108 + iVar4;
        local_9 = 0;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        iVar4 = (int)pcVar5 - (int)(local_108 + 1);
      }
      goto LAB_005bab58;
    }
    if (iVar4 != 8) {
      local_8 = "unknown";
      goto LAB_005bab58;
    }
    pcVar5 = "const ";
    if ((*(byte *)(param_3 + 0x21) & 2) == 0) {
      pcVar5 = "";
    }
    switch(*(undefined4 *)(param_3 + 0x14)) {
    case 0:
      pcVar3 = "bool";
      break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
      pcVar3 = "int";
      break;
    case 9:
    case 0xb:
      pcVar3 = "float";
      break;
    case 10:
      pcVar3 = "half";
      break;
    case 0xc:
      pcVar3 = "double";
      break;
    case 0xd:
      pcVar3 = "NULL";
      break;
    case 0xe:
      pcVar3 = "string";
      break;
    case 0xf:
      pcVar3 = "texture";
      break;
    case 0x10:
      pcVar3 = "texture1D";
      break;
    case 0x11:
      pcVar3 = "texture2D";
      break;
    case 0x12:
      pcVar3 = "texture3D";
      break;
    case 0x13:
      pcVar3 = "textureCUBE";
      break;
    case 0x14:
      pcVar3 = "sampler";
      break;
    case 0x15:
      pcVar3 = "sampler1D";
      break;
    case 0x16:
      pcVar3 = "sampler2D";
      break;
    case 0x17:
      pcVar3 = "sampler3D";
      break;
    case 0x18:
      pcVar3 = "samplerCUBE";
      break;
    case 0x19:
      pcVar3 = "pixelshader";
      break;
    case 0x1a:
      pcVar3 = "vertexshader";
      break;
    case 0x1b:
      pcVar3 = "pixelfragment";
      break;
    case 0x1c:
      pcVar3 = "vertexfragment";
      break;
    default:
      pcVar3 = "unknown";
    }
    if (*(int *)(param_3 + 0x10) == 1) {
      _snprintf(local_108,0xff,"%s%s%u",pcVar5,pcVar3,*(undefined4 *)(param_3 + 0x1c));
      goto LAB_005bab58;
    }
    if (*(int *)(param_3 + 0x10) == 2) {
      _snprintf(local_108,0xff,"%s%s%ux%u",pcVar5,pcVar3,*(undefined4 *)(param_3 + 0x18),
                *(undefined4 *)(param_3 + 0x1c));
      goto LAB_005bab58;
    }
    pcVar8 = "%s%s";
  }
  _snprintf(local_108,0xff,pcVar8,pcVar5,pcVar3);
LAB_005bab58:
  pcVar5 = local_8;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar6 = (int)pcVar5 - (int)(local_8 + 1);
  if (param_2 < (uint)((int)pcVar5 - (int)(local_8 + 1))) {
    uVar6 = param_2;
  }
  pcVar5 = param_1;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)local_8;
    local_8 = local_8 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pcVar5 = *local_8;
    local_8 = local_8 + 1;
    pcVar5 = pcVar5 + 1;
  }
  param_1[uVar6] = '\0';
  return;
}


// ==== 0x5bac05 FUN_005bac05

undefined4 __thiscall FUN_005bac05(undefined4 param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          if (param_2 == 0) {
            return 0x80004005;
          }
          iVar1 = *(int *)(param_2 + 4);
          if (iVar1 != 1) break;
          uVar2 = FUN_005ba80b(*(undefined4 *)(param_2 + 8));
          if (param_3 < uVar2) {
            param_2 = *(int *)(param_2 + 8);
          }
          else {
            param_2 = *(int *)(param_2 + 0xc);
            param_3 = param_3 - uVar2;
          }
        }
        if (iVar1 != 5) break;
        param_2 = *(int *)(param_2 + 0x18);
      }
      if (iVar1 != 7) break;
      param_2 = *(int *)(param_2 + 0x10);
      uVar2 = FUN_005ba80b(param_2);
      if (uVar2 == 0) {
        return 0x80004005;
      }
      param_3 = param_3 % uVar2;
    }
    if (iVar1 == 8) {
      iVar1 = *(int *)(param_2 + 0x10);
      if (((iVar1 == 0) || (iVar1 == 1)) || (iVar1 == 2)) {
        *(undefined4 *)(param_4 + 0x10) = 0;
      }
      else if (iVar1 == 3) {
        *(undefined4 *)(param_4 + 0x10) = 3;
      }
      *(undefined4 *)(param_4 + 0x14) = *(undefined4 *)(param_2 + 0x14);
      *(undefined4 *)(param_4 + 0x18) = 1;
      *(undefined4 *)(param_4 + 0x1c) = 1;
      *(uint *)(param_4 + 0x20) = *(uint *)(param_2 + 0x20) & 0x200;
      return 0;
    }
    if (iVar1 != 10) break;
    param_2 = *(int *)(param_2 + 0x20);
  }
  FUN_005ba278(param_1,0,0,"internal error: unknown node");
  return 0;
}


// ==== 0x5baccd FUN_005baccd

undefined4 FUN_005baccd(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  bool bVar9;
  
  if ((((param_1 == 0) || (*(int *)(param_1 + 4) != 8)) || (param_2 == 0)) ||
     (*(int *)(param_2 + 4) != 8)) {
LAB_005bae6e:
    uVar5 = 0x80004005;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x14);
    iVar2 = *(int *)(param_2 + 0x14);
    if (iVar1 == iVar2) {
      *param_3 = iVar1;
    }
    else {
      uVar7 = *(uint *)(&DAT_0069f0f0 + iVar2 * 8);
      if (*(uint *)(&DAT_0069f0f0 + iVar2 * 8) < *(uint *)(&DAT_0069f0f0 + iVar1 * 8)) {
        uVar7 = *(uint *)(&DAT_0069f0f0 + iVar1 * 8);
      }
      uVar3 = *(uint *)(&DAT_0069f0f4 + iVar1 * 8) & *(uint *)(&DAT_0069f0f4 + iVar2 * 8);
      if ((uVar3 & 1) == 0) {
        if ((uVar3 & 4) == 0) {
          if ((uVar3 & 2) == 0) {
            if ((uVar3 & 8) == 0) {
              if ((uVar3 & 0x10) != 0) {
                uVar7 = 0;
                do {
                  iVar4 = iVar2;
                  iVar6 = iVar1;
                  if (uVar7 == 0) {
                    iVar4 = iVar1;
                    iVar6 = iVar2;
                  }
                  if (iVar6 == 0xd) {
LAB_005bae79:
                    *param_3 = iVar4;
                    goto LAB_005bae7e;
                  }
                  if (iVar6 == 0xf) {
                    if (0xe < iVar4) {
                      bVar9 = SBORROW4(iVar4,0x13);
                      iVar6 = -0x13;
                      bVar8 = iVar4 == 0x13;
LAB_005bae66:
                      if (bVar8 || bVar9 != iVar4 + iVar6 < 0) goto LAB_005bae79;
                    }
                  }
                  else if ((iVar6 == 0x14) && (0x13 < iVar4)) {
                    bVar9 = SBORROW4(iVar4,0x18);
                    iVar6 = -0x18;
                    bVar8 = iVar4 == 0x18;
                    goto LAB_005bae66;
                  }
                  uVar7 = uVar7 + 1;
                } while (uVar7 < 2);
              }
              goto LAB_005bae6e;
            }
            if (uVar7 == 0) {
              *param_3 = 9;
            }
            else if ((uVar7 == 8) || (uVar7 == 0x10)) {
              *param_3 = 10;
            }
            else if (uVar7 == 0x20) {
              *param_3 = 0xb;
            }
            else if (uVar7 == 0x40) {
              *param_3 = 0xc;
            }
          }
          else if (uVar7 == 0) {
            *param_3 = 1;
          }
          else if (uVar7 == 8) {
            *param_3 = 2;
          }
          else if (uVar7 == 0x10) {
            *param_3 = 3;
          }
          else if ((uVar7 == 0x20) || (uVar7 == 0x40)) {
            *param_3 = 4;
          }
        }
        else if (uVar7 == 0) {
          *param_3 = 5;
        }
        else if (uVar7 == 8) {
          *param_3 = 6;
        }
        else if (uVar7 == 0x10) {
          *param_3 = 7;
        }
        else if ((uVar7 == 0x20) || (uVar7 == 0x40)) {
          *param_3 = 8;
        }
      }
      else {
        *param_3 = 0;
      }
    }
LAB_005bae7e:
    uVar5 = 0;
  }
  return uVar5;
}


// ==== 0x5bae82 FUN_005bae82

undefined4 __thiscall FUN_005bae82(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  while( true ) {
    if (iVar2 == 0) {
      return param_2;
    }
    iVar1 = *(int *)(iVar2 + 0x10);
    if (((iVar1 == 2) || (iVar1 == 3)) || (iVar1 == 4)) break;
    iVar2 = *(int *)(iVar2 + 0x1c);
  }
  FUN_005ba1d9(param_1,param_1 + 0x20,0xbf8,"object literals are not allowed inside functions");
  return 0;
}


// ==== 0x5baec2 FUN_005baec2

int FUN_005baec2(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 0;
  if (param_1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 4);
    if (iVar1 == 1) {
      do {
        if (*(int *)(param_1 + 4) != 1) break;
        iVar1 = FUN_005baec2(*(undefined4 *)(param_1 + 8),param_2 + iVar3 * 4);
        param_1 = *(int *)(param_1 + 0xc);
        iVar3 = iVar3 + iVar1;
      } while (param_1 != 0);
      if (param_1 != 0) {
        iVar1 = FUN_005baec2(param_1,param_2 + iVar3 * 4);
        iVar3 = iVar3 + iVar1;
      }
    }
    else {
      if (iVar1 == 5) {
        uVar4 = *(undefined4 *)(param_1 + 0x18);
      }
      else {
        if (iVar1 == 7) {
          uVar2 = 0;
          if (*(int *)(param_1 + 0x14) == 0) {
            return 0;
          }
          do {
            iVar1 = FUN_005baec2(*(undefined4 *)(param_1 + 0x10),param_2 + iVar3 * 4);
            iVar3 = iVar3 + iVar1;
            uVar2 = uVar2 + 1;
          } while (uVar2 < *(uint *)(param_1 + 0x14));
          return iVar3;
        }
        if (iVar1 == 8) {
          iVar3 = *(int *)(param_1 + 0x1c) * *(int *)(param_1 + 0x18);
          uVar4 = 3;
          switch(*(undefined4 *)(param_1 + 0x14)) {
          case 0:
            uVar4 = 0;
            break;
          case 1:
          case 2:
          case 3:
          case 4:
            uVar4 = 1;
            break;
          case 5:
          case 6:
          case 7:
          case 8:
            uVar4 = 2;
            break;
          case 0xd:
          case 0xe:
          case 0xf:
          case 0x10:
          case 0x11:
          case 0x12:
          case 0x13:
          case 0x19:
          case 0x1a:
          case 0x1b:
          case 0x1c:
            uVar4 = 5;
            break;
          case 0x14:
          case 0x15:
          case 0x16:
          case 0x17:
          case 0x18:
            uVar4 = 4;
          }
          for (iVar1 = iVar3; iVar1 != 0; iVar1 = iVar1 + -1) {
            *param_2 = uVar4;
            param_2 = param_2 + 4;
          }
          return iVar3;
        }
        if (iVar1 != 10) {
          return 0;
        }
        uVar4 = *(undefined4 *)(param_1 + 0x20);
      }
      iVar3 = FUN_005baec2(uVar4,param_2);
    }
  }
  return iVar3;
}


// ==== 0x5bb002 FUN_005bb002

undefined4 FUN_005bb002(double *param_1,int *param_2)

{
  double dVar1;
  int iVar2;
  
  iVar2 = *param_2;
  if (iVar2 == 0) {
    if (param_2[2] == 0) {
      dVar1 = 0.0;
    }
    else {
      dVar1 = 1.0;
    }
    *param_1 = dVar1;
  }
  else {
    if (iVar2 == 1) {
      dVar1 = (double)param_2[2];
    }
    else if (iVar2 == 2) {
      dVar1 = (double)param_2[2];
      if (param_2[2] < 0) {
        dVar1 = dVar1 + 4294967296.0;
      }
    }
    else {
      if (iVar2 != 3) {
        return 0x80004005;
      }
      dVar1 = *(double *)(param_2 + 2);
    }
    *param_1 = dVar1;
  }
  return 0;
}


// ==== 0x5bb05e FUN_005bb05e

bool FUN_005bb05e(int param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  
  while( true ) {
    while( true ) {
      if (param_1 == 0) {
        return false;
      }
      iVar2 = *(int *)(param_1 + 4);
      if (iVar2 != 1) break;
      iVar2 = FUN_005bb05e(*(undefined4 *)(param_1 + 8));
      if (iVar2 != 0) {
        return true;
      }
      param_1 = *(int *)(param_1 + 0xc);
    }
    if (iVar2 == 0xd) {
      return *(int *)(param_1 + 0x10) != 6;
    }
    if (iVar2 != 0xc) {
      return false;
    }
    iVar2 = *(int *)(param_1 + 0x1c);
    if (0x17 < iVar2) break;
    if (iVar2 < 0x16) {
      if (iVar2 < 0) {
        return true;
      }
      if (1 < iVar2) {
        if (iVar2 < 0x14) {
          return true;
        }
        bVar4 = SBORROW4(iVar2,0x15);
        iVar1 = -0x15;
        bVar3 = iVar2 == 0x15;
        goto LAB_005bb0c7;
      }
    }
    param_1 = *(int *)(param_1 + 0x20);
  }
  if (iVar2 < 0x19) {
    return true;
  }
  bVar4 = SBORROW4(iVar2,0x1a);
  iVar1 = -0x1a;
  bVar3 = iVar2 == 0x1a;
LAB_005bb0c7:
  if (bVar3 || bVar4 != iVar2 + iVar1 < 0) {
    return false;
  }
  return true;
}


// ==== 0x5bb0d5 FUN_005bb0d5

bool FUN_005bb0d5(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  while( true ) {
    while( true ) {
      if (param_1 == 0) {
        return true;
      }
      iVar1 = *(int *)(param_1 + 4);
      if (iVar1 != 1) break;
      iVar1 = FUN_005bb0d5(*(undefined4 *)(param_1 + 8));
      if (iVar1 == 0) {
        return false;
      }
      param_1 = *(int *)(param_1 + 0xc);
    }
    if (iVar1 == 0xd) {
      return *(int *)(param_1 + 0x10) != 6;
    }
    if (iVar1 != 0xc) {
      return true;
    }
    iVar1 = *(int *)(param_1 + 0x1c);
    if (iVar1 < 0x14) break;
    if (iVar1 < 0x16) {
      return false;
    }
    if (iVar1 == 0x19) {
      return false;
    }
    if (iVar1 == 0x1a) {
      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0x18);
      if (iVar1 < 0x47) {
        if (0x43 < iVar1) {
          return false;
        }
        if (iVar1 == 9) {
          return false;
        }
        if (iVar1 == 0x1a) {
          return false;
        }
        if (iVar1 == 0x28) {
          return false;
        }
        if (iVar1 == 0x3d) {
          return false;
        }
      }
      else if (0x47 < iVar1) {
        if (iVar1 < 0x4b) {
          return false;
        }
        if (0x4b < iVar1) {
          if (iVar1 < 0x4f) {
            return false;
          }
          if ((0x4f < iVar1) && (iVar1 < 0x53)) {
            return false;
          }
        }
      }
      iVar1 = *(int *)(param_1 + 0x24);
      iVar2 = FUN_005bb0d5(*(undefined4 *)(iVar1 + 8));
      if (iVar2 == 0) {
        return false;
      }
      uVar3 = *(undefined4 *)(iVar1 + 0xc);
      goto LAB_005bb1d4;
    }
    if (iVar1 != 0x1b) break;
    iVar1 = *(int *)(param_1 + 0x24);
    if (iVar1 == 0) {
      return false;
    }
    if (*(int *)(iVar1 + 4) != 0xc) {
      return false;
    }
    param_1 = *(int *)(iVar1 + 0x24);
  }
  iVar1 = FUN_005bb0d5(*(undefined4 *)(param_1 + 0x20));
  if (iVar1 == 0) {
    return false;
  }
  uVar3 = *(undefined4 *)(param_1 + 0x24);
LAB_005bb1d4:
  iVar1 = FUN_005bb0d5(uVar3);
  if (iVar1 != 0) {
    return true;
  }
  return false;
}


// ==== 0x5bb1eb FUN_005bb1eb

void FUN_005bb1eb(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 4) == 0xc)) {
    iVar1 = *(int *)(param_1 + 0x10);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    else {
      if (*(int *)(iVar1 + 4) == 8) {
        *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar1 + 0x18);
        uVar2 = *(undefined4 *)(iVar1 + 0x1c);
      }
      else {
        *(undefined4 *)(param_1 + 0x14) = 1;
        uVar2 = FUN_005ba80b(iVar1);
      }
      *(undefined4 *)(param_1 + 0x18) = uVar2;
    }
  }
  return;
}


// ==== 0x5bb22e FUN_005bb22e

int FUN_005bb22e(int *param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x28);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d8670();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  puVar2[4] = 0;
  if (param_1 != (int *)0x0) {
    iVar3 = (**(code **)(*param_1 + 8))();
    puVar2[5] = iVar3;
    if (iVar3 == 0) goto LAB_005bb287;
  }
  pvVar1 = _malloc(0x14);
  if (pvVar1 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_005d78db(puVar2,0,"Stmts");
  }
  if (iVar3 != 0) {
    return iVar3;
  }
LAB_005bb287:
  (**(code **)*puVar2)(1);
  return 0;
}


// ==== 0x5bb295 FUN_005bb295

int __thiscall FUN_005bb295(undefined4 param_1,int *param_2,int *param_3,int param_4,int *param_5)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  
  if ((param_3 != (int *)0x0) &&
     ((param_3[6] * param_3[5] != 1 || (iVar1 = FUN_005ba799(param_3[4]), iVar1 == 0)))) {
    FUN_005ba1d9(param_1,param_3 + 0xc,0xbcb,"float expected");
    return 0;
  }
  pvVar2 = _malloc(0x28);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_005d8670();
  }
  if (puVar3 == (undefined4 *)0x0) {
    return 0;
  }
  puVar3[4] = 3;
  if (param_2 != (int *)0x0) {
    iVar1 = (**(code **)(*param_2 + 8))();
    puVar3[5] = iVar1;
    if (iVar1 == 0) goto LAB_005bb374;
  }
  if (param_3 != (int *)0x0) {
    iVar1 = (**(code **)(*param_3 + 8))();
    puVar3[6] = iVar1;
    if (iVar1 == 0) goto LAB_005bb374;
  }
  if (param_4 != 0) {
    iVar1 = FUN_005bb22e(param_4);
    puVar3[7] = iVar1;
    if (iVar1 == 0) goto LAB_005bb374;
  }
  if (param_5 != (int *)0x0) {
    iVar1 = (**(code **)(*param_5 + 8))();
    puVar3[8] = iVar1;
    if (iVar1 == 0) goto LAB_005bb374;
  }
  pvVar2 = _malloc(0x14);
  if (pvVar2 == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_005d78db(puVar3,0,"Stmts");
  }
  if (iVar1 != 0) {
    return iVar1;
  }
LAB_005bb374:
  (**(code **)*puVar3)(1);
  return 0;
}


// ==== 0x5bb385 FUN_005bb385

undefined4 FUN_005bb385(void)

{
  FUN_005c564d(1);
  FUN_005c7ed5();
  return 0;
}


// ==== 0x5bb39e FUN_005bb39e

undefined4 * __thiscall FUN_005bb39e(uint *param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)0x0;
  FUN_005e554f();
  pvVar3 = (void *)0x0;
  if (param_2 != 0) {
    pvVar3 = _malloc(8);
    if (pvVar3 == (void *)0x0) {
      pvVar3 = (void *)0x0;
    }
    else {
      pvVar3 = (void *)FUN_005e8a52(param_1,param_1[3]);
    }
    if (pvVar3 == (void *)0x0) goto LAB_005bb427;
  }
  pvVar1 = _malloc(0x38);
  puVar4 = (undefined4 *)0x0;
  if (pvVar1 != (void *)0x0) {
    puVar4 = (undefined4 *)FUN_005d8db3(param_1 + 8,0);
  }
  if (puVar4 != (undefined4 *)0x0) {
    iVar2 = FUN_005e85e1(param_1[1],*param_1 & 5,pvVar3,puVar4 + 0xc);
    if (iVar2 < 0) {
      param_1[0x10] = 1;
      (**(code **)*puVar4)(1);
      puVar4 = (undefined4 *)0x0;
    }
  }
LAB_005bb427:
  _free(pvVar3);
  FUN_005e7993();
  return puVar4;
}


// ==== 0x5bb43f FUN_005bb43f

undefined4 * FUN_005bb43f(undefined4 *param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  void *pvVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  char local_18 [15];
  undefined1 local_9;
  
  iVar6 = (int)param_1;
  if ((((param_1 != (undefined4 *)0x0) && (*(int *)((int)param_1 + 4) == 2)) &&
      (*(int *)((int)param_1 + 0x10) == 2)) &&
     (((param_2 != 0 && (*(int *)(param_2 + 4) == 2)) && (*(int *)(param_2 + 0x10) == 9)))) {
    pvVar4 = _malloc(0x30);
    if (pvVar4 == (void *)0x0) {
      param_1 = (undefined4 *)0x0;
    }
    else {
      param_1 = (undefined4 *)FUN_005d7ac2((int *)(param_2 + 0x10));
    }
    if (param_1 != (undefined4 *)0x0) {
      uVar2 = *(undefined4 *)(iVar6 + 0x18);
      pcVar3 = *(char **)(param_2 + 0x18);
      _snprintf(local_18,0x10,&DAT_0069f230,uVar2);
      pcVar5 = local_18;
      local_9 = 0;
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      pcVar7 = pcVar3;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      pcVar5 = pcVar5 + (int)(pcVar7 + ((1 - (int)(pcVar3 + 1)) - (int)(local_18 + 1)));
      iVar6 = FUN_005b1775(pcVar5);
      if (iVar6 != 0) {
        _snprintf(iVar6,pcVar5,&DAT_0069f228,uVar2,pcVar3);
        pcVar5[iVar6 + -1] = '\0';
        param_1[6] = iVar6;
        return param_1;
      }
      (**(code **)*param_1)(1);
    }
  }
  return (undefined4 *)0x0;
}


// ==== 0x5bb534 FUN_005bb534

undefined4 __thiscall FUN_005bb534(int param_1,int param_2,int *param_3,int *param_4,int *param_5)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  void *pvVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  byte *pbVar12;
  uint uVar13;
  bool bVar14;
  undefined1 local_168 [16];
  int local_158;
  uint local_150;
  int local_14c;
  int local_12c [30];
  int aiStack_b4 [5];
  undefined1 local_a0 [20];
  undefined4 local_8c;
  undefined1 local_7c [20];
  uint local_68;
  uint local_58 [16];
  int local_18;
  undefined **local_14;
  undefined **local_10;
  int *local_c;
  uint local_8;
  
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
  }
  if (param_5 != (int *)0x0) {
    *param_5 = 0;
  }
  uVar9 = 0;
  uVar13 = (uint)param_3;
  if (param_3 != (int *)0x0) {
    do {
      iVar3 = *(int *)(uVar13 + 8);
      if ((((iVar3 == 0) || (*(int *)(iVar3 + 4) != 0xc)) || (*(int *)(iVar3 + 0x10) == 0)) ||
         (*(int *)(*(int *)(iVar3 + 0x10) + 4) != 8)) break;
      uVar13 = *(uint *)(uVar13 + 0xc);
      uVar9 = uVar9 + 1;
    } while (uVar13 != 0);
    if ((uVar13 != 0) || (4 < uVar9)) {
      return 1;
    }
  }
  local_18 = 0;
  local_c = &DAT_0069ba3c;
  local_10 = (undefined **)0x0;
  local_58[0xf] = param_1;
  do {
    pbVar12 = (byte *)local_c[-10];
    pbVar2 = *(byte **)(param_2 + 8);
    do {
      bVar1 = *pbVar2;
      bVar14 = bVar1 < *pbVar12;
      if (bVar1 != *pbVar12) {
LAB_005bb5d0:
        iVar3 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
        goto LAB_005bb5d5;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar14 = bVar1 < pbVar12[1];
      if (bVar1 != pbVar12[1]) goto LAB_005bb5d0;
      pbVar2 = pbVar2 + 2;
      pbVar12 = pbVar12 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_005bb5d5:
    if (iVar3 == 0) {
      local_58[5] = 0xffffffff;
      local_58[6] = 0xffffffff;
      local_58[7] = 0xffffffff;
      local_58[8] = 0xffffffff;
      local_58[9] = 0xffffffff;
      local_58[10] = 0x1d;
      local_58[0xb] = 0x1d;
      local_58[0xc] = 0x1d;
      local_58[0xd] = 0x1d;
      local_58[0xe] = 0x1d;
      local_58[0] = 5;
      local_58[1] = 5;
      local_58[2] = 5;
      local_58[3] = 5;
      local_58[4] = 5;
      FUN_005d8121();
      FUN_005d8121();
      local_14 = (undefined **)0x1;
      local_8 = (uint)param_3;
      piVar11 = local_c;
      if (param_3 == (int *)0x0) {
LAB_005bb6a8:
        piVar11 = local_c;
        if (local_c[-9] != 0) {
          if (local_58[local_c[-8]] == 5) {
            local_58[local_c[-8]] = *(uint *)local_c[-7];
          }
          if (local_58[piVar11[-6] + 10] == 0x1d) {
            local_58[piVar11[-6] + 10] = *(uint *)piVar11[-5];
          }
        }
        local_8 = 0;
        piVar11 = local_c + -5;
        do {
          puVar4 = (uint *)piVar11[-2];
          puVar5 = local_58 + local_8;
          uVar13 = *puVar5;
          if (uVar13 == 5) {
            if (puVar4 != (uint *)0x0) {
              *puVar5 = *puVar4;
            }
          }
          else {
            if ((uVar13 == 0) && ((uVar9 = *puVar4, uVar9 == 1 || (uVar9 == 2)))) {
              *puVar5 = uVar9;
            }
            else {
              for (; (*puVar4 != 5 && (uVar13 != *puVar4)); puVar4 = puVar4 + 1) {
              }
            }
            if (*puVar4 == 5) break;
          }
          puVar5 = (uint *)*piVar11;
          uVar13 = local_58[local_8 + 10];
          puVar4 = puVar5;
          if (uVar13 == 0x1d) {
            if (puVar5 != (uint *)0x0) {
              uVar13 = *puVar5;
LAB_005bb81e:
              local_58[local_8 + 10] = uVar13;
            }
          }
          else {
            for (; (*puVar4 != 0x1d && (uVar13 != *puVar4)); puVar4 = puVar4 + 1) {
            }
            if (*puVar4 == 0x1d) {
              uVar13 = *puVar5;
              goto LAB_005bb81e;
            }
          }
          if (local_58[local_8 + 5] == 0xffffffff) {
            local_58[local_8 + 5] = 1;
          }
          local_8 = local_8 + 1;
          piVar11 = piVar11 + 8;
        } while (local_8 < 5);
        if (local_8 == 5) {
          FUN_005d8188();
          FUN_005d8188();
          break;
        }
      }
      else {
        do {
          if (piVar11[-2] == 0) break;
          iVar3 = *(int *)(*(int *)(local_8 + 8) + 0x10);
          iVar8 = *piVar11;
          uVar13 = local_58[iVar8];
          if ((uVar13 == 5) ||
             ((uVar13 == 0 && ((*(int *)(iVar3 + 0x10) == 1 || (*(int *)(iVar3 + 0x10) == 2)))))) {
            local_58[iVar8] = *(uint *)(iVar3 + 0x10);
            aiStack_b4[iVar8] = piVar11[1];
          }
          else {
            if (*(uint *)(iVar3 + 0x10) == 0) {
              if ((uVar13 == 0) || (uVar13 == 1)) goto LAB_005bb723;
              bVar14 = uVar13 == 2;
            }
            else {
              bVar14 = *(uint *)(iVar3 + 0x10) == uVar13;
            }
            if (!bVar14) break;
          }
LAB_005bb723:
          iVar8 = piVar11[2];
          uVar13 = local_58[iVar8 + 10];
          if (uVar13 == 0x1d) {
            local_58[iVar8 + 10] = *(uint *)(iVar3 + 0x14);
            aiStack_b4[iVar8] = piVar11[3];
          }
          else {
            local_8c = *(undefined4 *)(iVar3 + 0x14);
            local_68 = uVar13;
            iVar8 = FUN_005baccd(local_7c,local_a0,local_58 + piVar11[2] + 10);
            if (iVar8 < 0) break;
          }
          iVar8 = *(int *)(iVar3 + 0x10);
          if (iVar8 != 0) {
            uVar13 = piVar11[4];
            if ((int)uVar13 < 0) {
              if (*(uint *)(iVar3 + 0x18) < local_58[~uVar13 + 5]) {
                local_58[~uVar13 + 5] = *(uint *)(iVar3 + 0x18);
              }
            }
            else if (*(uint *)(iVar3 + 0x18) < uVar13) break;
            if (iVar8 != 0) {
              uVar13 = piVar11[5];
              if ((int)uVar13 < 0) {
                if (*(uint *)(iVar3 + 0x1c) < local_58[~uVar13 + 5]) {
                  local_58[~uVar13 + 5] = *(uint *)(iVar3 + 0x1c);
                }
              }
              else if (*(uint *)(iVar3 + 0x1c) < uVar13) break;
            }
          }
          if (((*(byte *)(piVar11 + -1) & 0x20) != 0) && (iVar3 = FUN_005ba70c(iVar3), iVar3 != 0))
          break;
          local_8 = *(uint *)(local_8 + 0xc);
          local_14 = (undefined **)((int)local_14 + 1);
          piVar11 = piVar11 + 8;
        } while (local_8 != 0);
        if ((local_8 == 0) &&
           (((undefined **)0x4 < local_14 || (local_c[(int)local_14 * 8 + -10] == 0))))
        goto LAB_005bb6a8;
      }
      FUN_005d8188();
      FUN_005d8188();
    }
    local_18 = local_18 + 1;
    local_10 = local_10 + 0x29;
    local_c = local_c + 0x29;
  } while (local_10 < (undefined **)0x31f8);
  if (local_18 == 0x4e) {
    return 1;
  }
  if (param_4 != (int *)0x0) {
    iVar3 = 5;
    do {
      FUN_005d8121();
      iVar8 = local_18;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    uVar13 = 0;
    puVar5 = &local_150;
    puVar4 = (uint *)(&DAT_0069ba2c + local_18 * 0xa4);
    do {
      if (puVar4[-6] == 0) break;
      uVar9 = puVar4[-5];
      if (uVar9 != 0) {
        puVar5[-2] = local_58[puVar4[-4]];
        puVar5[-1] = local_58[puVar4[-2] + 10];
        uVar10 = *puVar4;
        if ((int)uVar10 < 0) {
          uVar10 = local_58[~uVar10 + 5];
        }
        *puVar5 = uVar10;
        uVar10 = puVar4[1];
        if ((int)uVar10 < 0) {
          uVar10 = local_58[~uVar10 + 5];
        }
        puVar5[1] = uVar10;
        puVar5[2] = uVar9 & 0xc00;
        if ((uVar13 == 0) || ((uVar9 & 0x20) == 0)) {
          puVar5[2] = uVar9 & 0xc00 | 0x200;
        }
      }
      uVar13 = uVar13 + 1;
      puVar4 = puVar4 + 8;
      puVar5 = puVar5 + 9;
    } while (uVar13 < 5);
    if ((((local_158 == 1) || (local_158 == 2)) && (local_14c == 1)) && (local_150 == 1)) {
      local_158 = 0;
    }
    pvVar6 = _malloc(0x40);
    if (pvVar6 == (void *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      puVar7 = (undefined4 *)FUN_005d8213();
    }
    if (puVar7 == (undefined4 *)0x0) {
LAB_005bb998:
      FUN_005b5e6c(local_168,0x24,5,FUN_005d8188);
      return 0x8007000e;
    }
    if ((&DAT_0069ba18)[iVar8 * 0x29] != 0) {
      iVar3 = FUN_005d81d3();
      puVar7[8] = iVar3;
      if (iVar3 == 0) {
LAB_005bbb6a:
        (**(code **)*puVar7)(1);
        goto LAB_005bb998;
      }
    }
    param_3 = puVar7 + 9;
    if ((&PTR_DAT_0069ba34)[iVar8 * 0x29] != (undefined *)0x0) {
      piVar11 = local_12c;
      local_10 = &PTR_DAT_0069ba34 + iVar8 * 0x29;
      do {
        local_14 = local_10;
        pvVar6 = _malloc(0x14);
        if (pvVar6 == (void *)0x0) {
          iVar3 = 0;
        }
        else {
          iVar3 = FUN_005d78db(0,0,"Decls");
        }
        *param_3 = iVar3;
        if (iVar3 == 0) goto LAB_005bbb6a;
        pvVar6 = _malloc(0x30);
        if (pvVar6 == (void *)0x0) {
          iVar3 = 0;
        }
        else {
          iVar3 = FUN_005d7db0(1,0,0,0);
        }
        local_58[0xf] = iVar3;
        if (iVar3 == 0) goto LAB_005bbb6a;
        *(int *)(*param_3 + 8) = iVar3;
        pvVar6 = _malloc(0x30);
        if (pvVar6 == (void *)0x0) {
          iVar8 = 0;
        }
        else {
          iVar8 = FUN_005d7ac2(param_2);
        }
        *(int *)(iVar3 + 0x14) = iVar8;
        if (iVar8 == 0) goto LAB_005bbb6a;
        *(undefined **)(iVar8 + 0x18) = *local_10;
        pvVar6 = _malloc(0x3c);
        if (pvVar6 == (void *)0x0) {
          iVar3 = 0;
        }
        else {
          iVar3 = FUN_005d844d();
        }
        if (iVar3 == 0) goto LAB_005bbb6a;
        *(int *)(local_58[0xf] + 0x18) = iVar3;
        *(undefined4 *)(iVar3 + 0x10) = 0xffffffff;
        *(int *)(iVar3 + 0x14) = piVar11[1] * *piVar11;
        *(undefined4 *)(iVar3 + 0x18) = 2;
        *(undefined **)(iVar3 + 0x1c) = local_10[1];
        iVar8 = FUN_005d81d3();
        *(int *)(iVar3 + 0x20) = iVar8;
        if (iVar8 == 0) goto LAB_005bbb6a;
        param_3 = (int *)(*param_3 + 0xc);
        local_14 = local_14 + 8;
        piVar11 = piVar11 + 9;
        local_10 = local_14;
      } while (*local_14 != (undefined *)0x0);
    }
    *param_4 = (int)puVar7;
    FUN_005b5e6c(local_168,0x24,5,FUN_005d8188);
  }
  iVar3 = local_18;
  iVar8 = 0;
  if (param_5 == (int *)0x0) {
    return 0;
  }
  pvVar6 = _malloc(0x14);
  if (pvVar6 != (void *)0x0) {
    iVar8 = FUN_005d78db(0,0,"Values");
  }
  if (iVar8 != 0) {
    pvVar6 = _malloc(0x40);
    if (pvVar6 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_005d8a65(2,*(undefined4 *)(&DAT_0069ba10 + iVar3 * 0xa4),param_2);
    }
    *(int *)(iVar8 + 8) = iVar3;
    if (iVar3 != 0) {
      *param_5 = iVar8;
      return 0;
    }
  }
  if ((param_4 != (int *)0x0) && ((undefined4 *)*param_4 != (undefined4 *)0x0)) {
    (*(code *)**(undefined4 **)*param_4)(1);
  }
  return 0x8007000e;
}


// ==== 0x5bbbae FUN_005bbbae

undefined4 __thiscall FUN_005bbbae(undefined4 param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  undefined8 uVar7;
  undefined1 local_20 [4];
  int local_1c;
  undefined1 local_14 [4];
  int local_10;
  undefined4 local_8;
  
  if ((param_3 == 0) != (*(int *)(param_2 + 0x1c) == 0)) {
    return 0xffffffff;
  }
  local_8 = param_1;
  if (param_3 != 0) {
    iVar3 = FUN_005d7700(*(undefined4 *)(*(int *)(param_2 + 0x1c) + 0x18),0,local_14);
    if ((iVar3 < 0) || (iVar3 = FUN_005d7700(*(undefined4 *)(param_3 + 0x18),0,local_20), iVar3 < 0)
       ) {
      pbVar5 = *(byte **)(*(int *)(param_2 + 0x1c) + 0x18);
      pbVar4 = *(byte **)(param_3 + 0x18);
      do {
        bVar1 = *pbVar4;
        bVar6 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_005bbc3f:
          iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_005bbc44;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar4[1];
        bVar6 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_005bbc3f;
        pbVar4 = pbVar4 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_005bbc44:
      if (iVar3 != 0) {
        return 0xffffffff;
      }
    }
    else if (local_10 != local_1c) {
      return 0xffffffff;
    }
  }
  iVar3 = *(int *)(param_2 + 0x24);
  do {
    if (iVar3 == 0) {
LAB_005bbcac:
      if (param_4 != 0) {
        return 0xffffffff;
      }
      return 0;
    }
    if (param_4 == 0) {
      if (iVar3 != 0) {
        return 0xffffffff;
      }
      goto LAB_005bbcac;
    }
    iVar3 = *(int *)(*(int *)(iVar3 + 8) + 0x18);
    iVar2 = *(int *)(*(int *)(param_4 + 8) + 0x18);
    if (*(int *)(iVar3 + 0x1c) != *(int *)(iVar2 + 0x1c)) {
      return 0xffffffff;
    }
    uVar7 = FUN_005ba894(*(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar2 + 0x20));
    iVar3 = (int)((ulonglong)uVar7 >> 0x20);
    if ((int)uVar7 == 0) {
      return 0xffffffff;
    }
    do {
      iVar3 = *(int *)(iVar3 + 0xc);
      if (iVar3 == 0) break;
    } while (*(int *)(*(int *)(iVar3 + 8) + 4) != 5);
    do {
      param_4 = *(int *)(param_4 + 0xc);
      if (param_4 == 0) break;
    } while (*(int *)(*(int *)(param_4 + 8) + 4) != 5);
  } while( true );
}


// ==== 0x5bbcbb FUN_005bbcbb

int FUN_005bbcbb(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_60 [20];
  int local_4c;
  undefined1 local_3c [20];
  int local_28;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  uVar3 = 0;
  local_18 = 0;
  local_c = FUN_005ba80b(param_1);
  local_10 = FUN_005ba80b(param_2);
  iVar2 = FUN_005ba894(param_1,param_2);
  if (iVar2 == 0) {
    bVar1 = false;
    local_8 = 0;
    FUN_005d8121();
    FUN_005d8121();
    if (local_c != 0) {
      while (uVar3 < local_10) {
        iVar2 = FUN_005bac05(param_1,uVar3,local_60);
        if (((iVar2 < 0) || (iVar2 = FUN_005bac05(param_2,uVar3,local_3c), iVar2 < 0)) ||
           (iVar2 = FUN_005baccd(local_60,local_3c,&local_14), iVar2 < 0)) {
          bVar1 = true;
          local_8 = 1;
        }
        else {
          if (local_14 != local_4c) {
            bVar1 = true;
          }
          if (local_14 != local_28) {
            local_8 = 1;
          }
        }
        if (((bVar1) && (local_8 != 0)) || (uVar3 = uVar3 + 1, local_c <= uVar3)) break;
      }
    }
    iVar2 = local_18;
    if (local_10 < local_c) {
      iVar2 = 4;
    }
    if (bVar1) {
      iVar2 = iVar2 + 0x200;
    }
    if (local_8 != 0) {
      iVar2 = iVar2 + 0x10000;
    }
    if (local_c < local_10) {
      iVar2 = iVar2 + 0x800000;
    }
    FUN_005d8188();
    FUN_005d8188();
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ==== 0x5bbdd0 FUN_005bbdd0

undefined4 __thiscall FUN_005bbdd0(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x10);
  if ((uVar1 & 0x200) != 0) {
    FUN_005ba5ee(param_3,1);
  }
  if (((param_3 == 0) || (*(int *)(param_3 + 4) != 8)) || (*(int *)(param_3 + 0x10) != 2)) {
    if ((uVar1 & 0xc00) != 0) {
      FUN_005ba1d9(param_1,param_1 + 8,0xc05,
                   "non-matrix types cannot be declared \'row_major\' or \'column_major\'");
      return 0x80004005;
    }
  }
  else {
    if ((uVar1 & 0xc00) == 0) {
      uVar1 = uVar1 | *(uint *)(param_1[1] + 0x24);
    }
    if ((uVar1 & 0xc00) == 0) {
      if ((*param_1 & 0x10) == 0) {
        if ((*param_1 & 0x20) != 0) {
          uVar1 = uVar1 | 0x800;
        }
      }
      else {
        uVar1 = uVar1 | 0x400;
      }
    }
    if ((uVar1 & 0x400) != 0) {
      *(uint *)(param_3 + 0x20) = *(uint *)(param_3 + 0x20) & 0xfffff7ff | 0x400;
    }
    if ((uVar1 & 0x800) != 0) {
      *(uint *)(param_3 + 0x20) = *(uint *)(param_3 + 0x20) & 0xfffffbff | 0x800;
    }
  }
  return 0;
}


// ==== 0x5bbe7f FUN_005bbe7f

undefined4 FUN_005bbe7f(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  bool bVar8;
  undefined1 local_50 [16];
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_2c [16];
  undefined4 local_1c;
  undefined4 local_14;
  undefined4 local_10;
  
  if (param_3 == 0) {
    if (param_1 == (undefined1 *)0x0) {
      if (param_2 != (undefined1 *)0x0) {
        return 0;
      }
      return 1;
    }
  }
  else if (param_1 == (undefined1 *)0x0) {
    return 1;
  }
  if (param_2 == (undefined1 *)0x0) {
    return 0;
  }
  FUN_005d8121();
  FUN_005d8121();
  puVar7 = param_1;
  if (*(int *)(param_1 + 4) != 8) {
    local_40 = 4;
    local_38 = 1;
    local_34 = FUN_005ba80b(param_1);
    puVar7 = local_50;
    if ((param_3 != 0) && (iVar3 = FUN_005ba799(param_1), iVar3 != 0)) {
      local_40 = 1;
    }
  }
  puVar5 = param_2;
  if (*(int *)(param_2 + 4) != 8) {
    local_1c = 4;
    local_14 = 1;
    local_10 = FUN_005ba80b(param_2);
    puVar5 = local_2c;
    if ((param_3 != 0) && (iVar3 = FUN_005ba799(param_2), iVar3 != 0)) {
      local_1c = 1;
    }
  }
  iVar3 = *(int *)(puVar7 + 0x10);
  if ((iVar3 != 4) && (iVar1 = *(int *)(puVar5 + 0x10), iVar1 != 4)) {
    if (iVar3 == 0) {
joined_r0x005bc04c:
      if (iVar1 == 3) goto LAB_005bc0f7;
    }
    else if (iVar3 == 1) {
      if (iVar1 != 0) {
        if (iVar1 == 1) {
LAB_005bc038:
          if (*(uint *)(puVar7 + 0x1c) <= *(uint *)(puVar5 + 0x1c)) goto LAB_005bbf6f;
        }
        else {
          if (iVar1 != 2) goto joined_r0x005bc04c;
          uVar2 = *(uint *)(puVar5 + 0x18);
          if (((uVar2 != 1) || (*(uint *)(puVar7 + 0x1c) <= *(uint *)(puVar5 + 0x1c))) &&
             ((iVar3 = *(int *)(puVar5 + 0x1c), iVar3 != 1 || (*(uint *)(puVar7 + 0x1c) <= uVar2))))
          {
            if ((uVar2 != 1) && (iVar3 != 1)) {
              bVar8 = uVar2 * iVar3 - *(int *)(puVar7 + 0x1c) == 0;
              goto LAB_005bc0d7;
            }
            goto LAB_005bbf6f;
          }
        }
        goto LAB_005bc0f7;
      }
    }
    else if (iVar3 == 2) {
      if (iVar1 != 0) {
        if (iVar1 == 1) {
          uVar2 = *(uint *)(puVar7 + 0x18);
          if (((uVar2 != 1) || (*(uint *)(puVar7 + 0x1c) <= *(uint *)(puVar5 + 0x1c))) &&
             ((iVar3 = *(int *)(puVar7 + 0x1c), iVar3 != 1 || (uVar2 <= *(uint *)(puVar5 + 0x1c)))))
          {
            if ((uVar2 != 1) && (iVar3 != 1)) {
              bVar8 = uVar2 * iVar3 - *(int *)(puVar5 + 0x1c) == 0;
              goto LAB_005bc0d7;
            }
            goto LAB_005bbf6f;
          }
        }
        else {
          if (iVar1 != 2) goto joined_r0x005bc04c;
          if (*(uint *)(puVar7 + 0x18) <= *(uint *)(puVar5 + 0x18)) goto LAB_005bc038;
        }
        goto LAB_005bc0f7;
      }
    }
    else if (iVar3 == 3) {
      if (iVar1 != 3) goto LAB_005bc0f7;
      iVar3 = *(int *)(puVar5 + 0x14);
      if (iVar3 != 0xd) {
        if (iVar3 == 0xf) {
          iVar3 = *(int *)(puVar7 + 0x14);
          if (((iVar3 == 0xf) || (iVar3 == 0x10)) || ((iVar3 == 0x11 || (iVar3 == 0x12))))
          goto LAB_005bbf6f;
          bVar8 = iVar3 == 0x13;
        }
        else if (iVar3 == 0x14) {
          iVar3 = *(int *)(puVar7 + 0x14);
          if ((((iVar3 == 0x14) || (iVar3 == 0x15)) || (iVar3 == 0x16)) || (iVar3 == 0x17))
          goto LAB_005bbf6f;
          bVar8 = iVar3 == 0x18;
        }
        else {
          bVar8 = *(int *)(puVar7 + 0x14) == iVar3;
        }
LAB_005bc0d7:
        if (!bVar8) goto LAB_005bc0f7;
      }
    }
LAB_005bbf6f:
    uVar6 = 1;
    goto LAB_005bbf71;
  }
  uVar4 = *(int *)(puVar7 + 0x1c) * *(int *)(puVar7 + 0x18);
  uVar2 = *(int *)(puVar5 + 0x1c) * *(int *)(puVar5 + 0x18);
  if (param_3 == 0) {
    if ((iVar3 == *(int *)(puVar5 + 0x10)) && (uVar4 - uVar2 == 0)) {
      uVar2 = 0;
      if (uVar4 != 0) {
        do {
          iVar3 = FUN_005bac05(param_1,uVar2,local_50);
          if (((iVar3 < 0) || (iVar3 = FUN_005bac05(param_2,uVar2,local_2c), iVar3 < 0)) ||
             (iVar3 = FUN_005ba894(local_50,local_2c), iVar3 == 0)) goto LAB_005bc0f7;
          uVar2 = uVar2 + 1;
        } while (uVar2 < uVar4);
      }
      goto LAB_005bc1a5;
    }
  }
  else if (uVar4 < uVar2 || uVar4 - uVar2 == 0) {
    uVar2 = 0;
    if (uVar4 != 0) {
      do {
        iVar3 = FUN_005bac05(param_1,uVar2,local_50);
        if (((iVar3 < 0) || (iVar3 = FUN_005bac05(param_2,uVar2,local_2c), iVar3 < 0)) ||
           (iVar3 = FUN_005bbe7f(local_50,local_2c,1), iVar3 == 0)) goto LAB_005bc0f7;
        uVar2 = uVar2 + 1;
      } while (uVar2 < uVar4);
    }
LAB_005bc1a5:
    uVar6 = 1;
    goto LAB_005bbf71;
  }
LAB_005bc0f7:
  uVar6 = 0;
LAB_005bbf71:
  FUN_005d8188();
  FUN_005d8188();
  return uVar6;
}


// ==== 0x5bc1ad FUN_005bc1ad

void __thiscall
FUN_005bc1ad(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            ,int param_6)

{
  int iVar1;
  char *pcVar2;
  undefined1 local_204 [256];
  undefined1 local_104 [256];
  
  if (param_6 == 0) {
    iVar1 = FUN_005bbe7f(param_4,param_5,1);
    if (iVar1 == 0) {
      pcVar2 = "implicitly ";
      goto LAB_005bc1dd;
    }
  }
  pcVar2 = "";
LAB_005bc1dd:
  FUN_005ba942(local_104,0xff,param_4);
  FUN_005ba942(local_204,0xff,param_5);
  if (param_3 == 0) {
    FUN_005ba1d9(param_1,param_2,0xbc9,"cannot %sconvert from \'%s\' to \'%s\'");
  }
  else {
    FUN_005ba1d9(param_1,param_2,0xbc9,"\'%s\': cannot %sconvert from \'%s\' to \'%s\'",param_3,
                 pcVar2,local_204,local_104);
  }
  return;
}


// ==== 0x5bc254 FUN_005bc254

int FUN_005bc254(int *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,int *param_5)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  piVar1 = param_2;
  if ((param_3 != (undefined4 *)0x0) && (param_4 != (undefined4 *)0x0)) {
    *param_3 = 0;
    *param_4 = 0;
    if (param_5 != (int *)0x0) {
      *param_5 = 0;
    }
    if (param_1 == (int *)0x0) {
      if (param_2 == (int *)0x0) {
        return 0;
      }
    }
    else if (param_2 != (int *)0x0) {
      uVar2 = FUN_005ba80b(param_1);
      uVar3 = FUN_005ba80b(piVar1);
      if ((((uVar3 <= uVar2) &&
           (iVar4 = FUN_005bbe7f(param_1,piVar1,0), piVar5 = param_1, iVar4 != 0)) ||
          (iVar4 = FUN_005bbe7f(piVar1,param_1,0), piVar5 = piVar1, iVar4 != 0)) ||
         (iVar4 = FUN_005bbe7f(param_1,piVar1,0), piVar5 = param_1, iVar4 != 0)) {
        iVar4 = FUN_005baccd(param_1,piVar1,&param_2);
        piVar1 = param_2;
        if (iVar4 < 0) {
          return iVar4;
        }
        if ((int *)piVar5[5] != param_2) {
          piVar5 = (int *)(**(code **)(*piVar5 + 8))();
          if (piVar5 == (int *)0x0) {
            return -0x7ff8fff2;
          }
          piVar5[5] = (int)piVar1;
        }
        piVar1 = param_5;
        if (param_5 != (int *)0x0) {
          iVar4 = (**(code **)(*piVar5 + 8))();
          *piVar1 = iVar4;
          if (iVar4 == 0) {
            (**(code **)*piVar5)();
            return -0x7ff8fff2;
          }
          FUN_005ba5ee(iVar4,1);
        }
        *param_3 = piVar5;
        *param_4 = piVar5;
        return 0;
      }
    }
  }
  return -0x7fffbffb;
}


// ==== 0x5bc356 FUN_005bc356

undefined4 * FUN_005bc356(int param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  int local_8;
  
  local_8 = 2;
  if (param_1 == 0) {
    local_8 = 0;
  }
  else if (0 < param_1) {
    if (param_1 < 5) {
      local_8 = 1;
    }
    else if (param_1 < 9) {
      local_8 = 2;
    }
    else if (param_1 < 0xd) {
      local_8 = 3;
    }
  }
  pvVar1 = _malloc(0x50);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d8831(0,0,0,0,1,param_4);
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  pvVar1 = _malloc(0x24);
  if (pvVar1 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_005d814c(0,param_1,1,1,0x200);
  }
  puVar2[4] = iVar3;
  if (iVar3 == 0) goto LAB_005bc459;
  pvVar1 = _malloc(0x40);
  if (local_8 == 3) {
    if (pvVar1 == (void *)0x0) {
LAB_005bc42c:
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_005d8a9d(3,param_3,param_4);
    }
  }
  else {
    if (pvVar1 == (void *)0x0) goto LAB_005bc42c;
    iVar3 = FUN_005d8a65(local_8,param_2,param_4);
  }
  puVar2[8] = iVar3;
  if (iVar3 != 0) {
    pvVar1 = _malloc(0x14);
    if (pvVar1 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_005d78db(puVar2[8],0,"Value");
    }
    if (iVar3 != 0) {
      puVar2[8] = iVar3;
      FUN_005bb1eb(puVar2);
      return puVar2;
    }
  }
LAB_005bc459:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// ==== 0x5bc47a FUN_005bc47a

void __thiscall FUN_005bc47a(int param_1,int param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = 0;
  uVar5 = 0;
  piVar4 = (int *)(param_1 + 0x20);
  uVar6 = 5;
  uVar2 = 0;
  if ((param_2 != 0) && (*(int *)(param_2 + 4) == 2)) {
    piVar4 = (int *)(param_2 + 0x10);
    iVar1 = *piVar4;
    uVar2 = uVar3;
    if (iVar1 == 2) {
      uVar5 = *(uint *)(param_2 + 0x18);
      uVar6 = (uVar5 & 0xbfffffff | 0x20000000) >> 0x1d;
    }
    else {
      if (iVar1 == 3) {
        uVar6 = 4;
      }
      else {
        if (iVar1 != 4) {
          if (iVar1 == 5) {
            uVar6 = 9;
          }
          else if (iVar1 == 6) {
            uVar6 = 10;
          }
          else if (iVar1 == 7) {
            uVar6 = 0xb;
          }
          else {
            if (iVar1 != 8) goto LAB_005bc4e7;
            uVar6 = 0xc;
          }
          uVar2 = *(undefined8 *)(param_2 + 0x18);
          goto LAB_005bc4e7;
        }
        uVar6 = 8;
      }
      uVar5 = *(uint *)(param_2 + 0x18);
    }
  }
LAB_005bc4e7:
  FUN_005bc356(uVar6,uVar5,uVar2,piVar4);
  return;
}


// ==== 0x5bc4f9 FUN_005bc4f9

undefined4 * __thiscall FUN_005bc4f9(int param_1,int *param_2)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  void *pvVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  
  if (param_2 != (int *)0x0) {
    iVar7 = (int)param_2 + 0x10;
    pcVar3 = *(char **)(param_1 + 0x28);
    param_2 = (int *)0x0;
    pcVar1 = pcVar3 + 1;
    do {
      cVar2 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
    pcVar3 = pcVar3 + (1 - (int)pcVar1);
    pvVar4 = _malloc(0x50);
    if (pvVar4 == (void *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5 = (undefined4 *)FUN_005d8831(0,0,0,0,1,iVar7);
    }
    if (puVar5 != (undefined4 *)0x0) {
      pvVar4 = _malloc(0x24);
      if (pvVar4 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005d814c(3,0xe,1,1,0x200);
      }
      puVar5[4] = iVar6;
      if ((iVar6 != 0) && (iVar6 = FUN_005d65b0(pcVar3,&param_2), -1 < iVar6)) {
        pvVar4 = _malloc(0x40);
        if (pvVar4 == (void *)0x0) {
          iVar7 = 0;
        }
        else {
          iVar7 = FUN_005d8ad5(5,param_2,iVar7);
        }
        puVar5[8] = iVar7;
        if (iVar7 != 0) {
          puVar10 = *(undefined4 **)(param_1 + 0x28);
          puVar8 = (undefined4 *)(**(code **)(*param_2 + 0xc))(param_2);
          for (uVar9 = (uint)pcVar3 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
            *puVar8 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar8 = puVar8 + 1;
          }
          for (uVar9 = (uint)pcVar3 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
            *(undefined1 *)puVar8 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar8 = (undefined4 *)((int)puVar8 + 1);
          }
          pvVar4 = _malloc(0x14);
          if (pvVar4 == (void *)0x0) {
            iVar7 = 0;
          }
          else {
            iVar7 = FUN_005d78db(puVar5[8],0,"Value");
          }
          if (iVar7 != 0) {
            puVar5[8] = iVar7;
            FUN_005bb1eb(puVar5);
            if (param_2 != (int *)0x0) {
              (**(code **)(*param_2 + 8))(param_2);
              return puVar5;
            }
            return puVar5;
          }
        }
      }
    }
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 8))(param_2);
      param_2 = (int *)0x0;
    }
    if (puVar5 != (undefined4 *)0x0) {
      (**(code **)*puVar5)(1);
    }
  }
  return (undefined4 *)0x0;
}


// ==== 0x5bc645 FUN_005bc645

undefined4 * FUN_005bc645(int param_1,int *param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  
  iVar4 = param_1;
  if (*(int *)(param_1 + 4) == 1) {
    while (param_1 = *(int *)(iVar4 + 8), *(int *)(param_1 + 4) != 2) {
      iVar4 = *(int *)(iVar4 + 0xc);
    }
  }
  pvVar2 = _malloc(0x50);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_005d8831(0,0,0,0,1,param_1 + 0x10);
  }
  if (puVar3 == (undefined4 *)0x0) {
LAB_005bc738:
    puVar3 = (undefined4 *)0x0;
  }
  else {
    if (param_2 != (int *)0x0) {
      iVar4 = (**(code **)(*param_2 + 8))();
      puVar3[8] = iVar4;
      if (iVar4 == 0) {
LAB_005bc730:
        (**(code **)*puVar3)(1);
        goto LAB_005bc738;
      }
    }
    piVar7 = puVar3 + 4;
    for (iVar4 = puVar3[8]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xc)) {
      iVar1 = *(int *)(iVar4 + 8);
      if (((iVar1 != 0) && (*(int *)(iVar1 + 4) == 0xc)) && (*(int *)(iVar1 + 0x10) != 0)) {
        pvVar2 = _malloc(0x14);
        if (pvVar2 == (void *)0x0) {
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_005d78db(0,0,"Types");
        }
        *piVar7 = iVar5;
        if (iVar5 == 0) goto LAB_005bc730;
        uVar6 = FUN_005d7885(*(undefined4 *)(iVar1 + 0x10));
        *(undefined4 *)(*piVar7 + 8) = uVar6;
        if (*(int *)(*piVar7 + 8) == 0) goto LAB_005bc730;
        piVar7 = (int *)(*piVar7 + 0xc);
      }
    }
    FUN_005bb1eb(puVar3);
  }
  return puVar3;
}


// ==== 0x5bc73c FUN_005bc73c

undefined4 * __thiscall FUN_005bc73c(undefined4 param_1,int *param_2,char *param_3)

{
  int iVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  char *pcVar8;
  void *pvVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  int iVar14;
  int iVar15;
  char *pcVar16;
  byte *pbVar17;
  uint uVar18;
  int *piVar19;
  int *piVar20;
  bool bVar21;
  int local_1c;
  int *local_18;
  int local_14;
  uint local_10;
  undefined4 *local_c;
  char *local_8;
  
  iVar7 = (int)param_3;
  if (param_3 == (char *)0x0) {
    return (undefined4 *)0x0;
  }
  if (*(int *)((int)param_3 + 4) != 2) {
    return (undefined4 *)0x0;
  }
  if (param_2 == (int *)0x0) {
    return (undefined4 *)0x0;
  }
  if (param_2[1] != 0xc) {
    return (undefined4 *)0x0;
  }
  iVar12 = param_2[4];
  iVar1 = (int)param_3 + 0x10;
  pvVar9 = _malloc(0x50);
  if (pvVar9 == (void *)0x0) {
    local_c = (undefined4 *)0x0;
  }
  else {
    local_c = (undefined4 *)FUN_005d8831(0,0x17,0,0,1,iVar1);
  }
  if (local_c == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  if (iVar12 != 0) {
    if (*(int *)(iVar12 + 4) == 1) {
      local_1c = 0;
      param_3 = (char *)iVar12;
      do {
        iVar12 = *(int *)((int)param_3 + 8);
        if ((iVar12 != 0) && (*(int *)(iVar12 + 4) == 5)) {
          pbVar17 = *(byte **)(*(int *)(iVar12 + 0x14) + 0x18);
          pbVar10 = *(byte **)(iVar7 + 0x18);
          do {
            bVar2 = *pbVar10;
            bVar21 = bVar2 < *pbVar17;
            if (bVar2 != *pbVar17) {
LAB_005bc800:
              iVar11 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
              goto LAB_005bc805;
            }
            if (bVar2 == 0) break;
            bVar2 = pbVar10[1];
            bVar21 = bVar2 < pbVar17[1];
            if (bVar2 != pbVar17[1]) goto LAB_005bc800;
            pbVar10 = pbVar10 + 2;
            pbVar17 = pbVar17 + 2;
          } while (bVar2 != 0);
          iVar11 = 0;
LAB_005bc805:
          if (iVar11 == 0) {
            piVar5 = *(int **)(*(int *)(iVar12 + 0x18) + 0x20);
            if (piVar5 != (int *)0x0) {
              iVar12 = (**(code **)(*piVar5 + 8))();
              local_c[4] = iVar12;
              if (iVar12 == 0) goto LAB_005bc842;
            }
            pvVar9 = _malloc(0x40);
            if (pvVar9 == (void *)0x0) {
              iVar12 = 0;
            }
            else {
              iVar12 = FUN_005d8a65(2,local_1c,iVar1);
            }
            local_c[9] = iVar12;
            goto LAB_005bcbaf;
          }
          iVar12 = FUN_005ba80b(*(undefined4 *)(*(int *)(iVar12 + 0x18) + 0x20));
          local_1c = local_1c + iVar12;
        }
        param_3 = *(char **)((int)param_3 + 0xc);
      } while (param_3 != (char *)0x0);
    }
    else if (*(int *)(iVar12 + 4) == 8) {
      piVar5 = *(int **)(iVar12 + 0x18);
      pcVar16 = *(char **)((int)param_3 + 0x18);
      piVar6 = *(int **)(iVar12 + 0x1c);
      uVar18 = *(uint *)(iVar12 + 0x20) & 0x200;
      pcVar8 = pcVar16;
      do {
        pcVar13 = pcVar8;
        pcVar8 = pcVar13 + 1;
      } while (*pcVar13 != '\0');
      cVar3 = *pcVar16;
      if (cVar3 == '_') {
        if (*(int *)(iVar12 + 0x10) == 2) {
          if ((pcVar13 <= pcVar16 + 1) || (local_14 = 3, pcVar16[1] != 'm')) {
            local_14 = 2;
          }
          goto LAB_005bc941;
        }
      }
      else if ('`' < cVar3) {
        if (((cVar3 < 'c') || (cVar3 == 'g')) || (cVar3 == 'r')) {
          if ((*(int *)(iVar12 + 0x10) == 0) || (*(int *)(iVar12 + 0x10) == 1)) {
            local_14 = 1;
            goto LAB_005bc941;
          }
        }
        else if ((('v' < cVar3) && (cVar3 < '{')) &&
                ((*(int *)(iVar12 + 0x10) == 0 || (*(int *)(iVar12 + 0x10) == 1)))) {
          local_14 = 0;
LAB_005bc941:
          local_10 = 0;
          local_18 = local_c + 9;
          if (pcVar13 <= pcVar16) {
LAB_005bcb3e:
            iVar11 = local_c[9];
            do {
              iVar14 = iVar11;
              if ((iVar14 == 0) || (uVar18 != 0)) goto LAB_005bcb75;
              iVar11 = *(int *)(iVar14 + 0xc);
              if (iVar11 != 0) {
                iVar15 = iVar11;
                do {
                  if (*(int *)(*(int *)(iVar14 + 8) + 0x18) == *(int *)(*(int *)(iVar15 + 8) + 0x18)
                     ) {
                    uVar18 = 1;
                    break;
                  }
                  iVar15 = *(int *)(iVar15 + 0xc);
                } while (iVar15 != 0);
              }
            } while( true );
          }
          param_3 = pcVar16 + 2;
          local_8 = pcVar16 + 3;
          piVar19 = param_2;
          piVar20 = param_2;
          do {
            if (3 < local_10) break;
            if (local_14 == 0) {
              cVar3 = *pcVar16;
              if (cVar3 == 'w') {
LAB_005bca89:
                piVar20 = (int *)0x3;
              }
              else if (cVar3 == 'x') {
LAB_005bca67:
                piVar20 = (int *)0x0;
              }
              else {
                if (cVar3 != 'y') {
                  if (cVar3 == 'z') goto LAB_005bca85;
                  goto LAB_005bc826;
                }
LAB_005bca6b:
                piVar20 = (int *)0x1;
              }
LAB_005bca8c:
              piVar19 = (int *)0x0;
              pcVar16 = pcVar16 + 1;
              local_8 = local_8 + 1;
              param_3 = param_3 + 1;
            }
            else {
              if (local_14 == 1) {
                cVar3 = *pcVar16;
                if (cVar3 == 'a') goto LAB_005bca89;
                if (cVar3 == 'b') {
LAB_005bca85:
                  piVar20 = (int *)0x2;
                  goto LAB_005bca8c;
                }
                if (cVar3 == 'g') goto LAB_005bca6b;
                if (cVar3 == 'r') goto LAB_005bca67;
                goto LAB_005bc826;
              }
              if (local_14 == 2) {
                if (((((pcVar13 <= param_3) || (*pcVar16 != '_')) ||
                     (cVar3 = pcVar16[1], cVar3 < '1')) ||
                    (('9' < cVar3 || (cVar4 = *param_3, cVar4 < '1')))) || ('9' < cVar4))
                goto LAB_005bc826;
                local_8 = local_8 + 3;
                piVar19 = (int *)(cVar3 + -0x31);
                piVar20 = (int *)(cVar4 + -0x31);
                pcVar16 = pcVar16 + 3;
                param_3 = param_3 + 3;
              }
              else if (local_14 == 3) {
                if ((((pcVar13 <= local_8) || (*pcVar16 != '_')) ||
                    ((pcVar16[1] != 'm' ||
                     (((cVar3 = *param_3, cVar3 < '0' || ('9' < cVar3)) ||
                      (cVar4 = *local_8, cVar4 < '0')))))) || ('9' < cVar4)) goto LAB_005bc826;
                local_8 = local_8 + 4;
                piVar19 = (int *)(cVar3 + -0x30);
                piVar20 = (int *)(cVar4 + -0x30);
                pcVar16 = pcVar16 + 4;
                param_3 = param_3 + 4;
              }
            }
            if ((piVar5 <= piVar19) || (piVar6 <= piVar20)) goto LAB_005bc826;
            pvVar9 = _malloc(0x14);
            if (pvVar9 == (void *)0x0) {
              iVar11 = 0;
            }
            else {
              iVar11 = FUN_005d78db(0,0,"Swizzle");
            }
            *local_18 = iVar11;
            if (iVar11 == 0) goto LAB_005bc842;
            pvVar9 = _malloc(0x40);
            if (pvVar9 == (void *)0x0) {
              iVar11 = 0;
            }
            else {
              iVar11 = FUN_005d8a65(2,(int *)((int)piVar19 * (int)piVar6 + (int)piVar20),iVar1);
            }
            *(int *)(*local_18 + 8) = iVar11;
            if (iVar11 == 0) goto LAB_005bc842;
            local_18 = (int *)(*local_18 + 0xc);
            local_10 = local_10 + 1;
          } while (pcVar16 < pcVar13);
          if ((pcVar13 <= pcVar16) && (local_10 < 5)) goto LAB_005bcb3e;
        }
      }
    }
  }
  goto LAB_005bc826;
LAB_005bcb75:
  pvVar9 = _malloc(0x24);
  if (pvVar9 == (void *)0x0) {
    iVar12 = 0;
  }
  else {
    iVar12 = FUN_005d814c(local_10 != 1,*(undefined4 *)(iVar12 + 0x14),1,local_10,
                          -(uint)(uVar18 != 0) & 0x200);
  }
  local_c[4] = iVar12;
LAB_005bcbaf:
  if (iVar12 == 0) goto LAB_005bc842;
  iVar12 = (**(code **)(*param_2 + 8))();
  local_c[8] = iVar12;
  if (iVar12 != 0) {
    FUN_005bb1eb(local_c);
    return local_c;
  }
LAB_005bc826:
  FUN_005ba1d9(param_1,iVar1,0xbca,"invalid subscript \'%s\'",*(undefined4 *)(iVar7 + 0x18));
LAB_005bc842:
  (**(code **)*local_c)(1);
  return (undefined4 *)0x0;
}


// ==== 0x5bcbdd FUN_005bcbdd

undefined4 * FUN_005bcbdd(int param_1)

{
  int *piVar1;
  uint uVar2;
  uint *puVar3;
  void *pvVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  
  if ((((param_1 != 0) && (*(int *)(param_1 + 4) == 0xe)) &&
      (piVar1 = *(int **)(param_1 + 0x30), piVar1 != (int *)0x0)) &&
     (uVar2 = (**(code **)(*piVar1 + 0x10))(piVar1), 3 < uVar2)) {
    puVar3 = (uint *)(**(code **)(**(int **)(param_1 + 0x30) + 0xc))(*(int **)(param_1 + 0x30));
    uVar2 = *puVar3 & 0xffff0000;
    if (uVar2 == 0x7ffe0000) {
      uVar7 = 0x1c;
    }
    else if (uVar2 == 0x7fff0000) {
      uVar7 = 0x1b;
    }
    else if (uVar2 == 0xfffe0000) {
      uVar7 = 0x1a;
    }
    else {
      if (uVar2 != 0xffff0000) {
        return (undefined4 *)0x0;
      }
      uVar7 = 0x19;
    }
    pvVar4 = _malloc(0x50);
    if (pvVar4 == (void *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5 = (undefined4 *)FUN_005d8831(0,0,0,0,1,param_1 + 0x10);
    }
    if (puVar5 != (undefined4 *)0x0) {
      pvVar4 = _malloc(0x24);
      if (pvVar4 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005d814c(3,uVar7,1,1,0x200);
      }
      puVar5[4] = iVar6;
      if (iVar6 != 0) {
        pvVar4 = _malloc(0x40);
        if (pvVar4 == (void *)0x0) {
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_005d8ad5(5,*(undefined4 *)(param_1 + 0x30),param_1 + 0x10);
        }
        puVar5[8] = iVar6;
        if (iVar6 != 0) {
          pvVar4 = _malloc(0x14);
          if (pvVar4 == (void *)0x0) {
            iVar6 = 0;
          }
          else {
            iVar6 = FUN_005d78db(puVar5[8],0,"Value");
          }
          if (iVar6 != 0) {
            puVar5[8] = iVar6;
            FUN_005bb1eb(puVar5);
            return puVar5;
          }
        }
      }
      (**(code **)*puVar5)(1);
    }
  }
  return (undefined4 *)0x0;
}


// ==== 0x5bcd15 FUN_005bcd15

undefined4 * __thiscall FUN_005bcd15(int param_1,int param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  pvVar1 = _malloc(0x50);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d8831(0,0,0,0,1,param_1 + 0x20);
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  pvVar1 = _malloc(0x24);
  if (pvVar1 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_005d814c(3,0x14,1,1,0x200);
  }
  puVar2[4] = iVar3;
  if (iVar3 != 0) {
    pvVar1 = _malloc(0x40);
    if (pvVar1 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_005d8a65(4,0,param_1 + 0x20);
    }
    if (iVar3 != 0) {
      puVar2[8] = iVar3;
      if (param_2 != 0) {
        iVar4 = FUN_005d7885(param_2);
        *(int *)(iVar3 + 0x18) = iVar4;
        if (iVar4 == 0) goto LAB_005bcdd7;
      }
      pvVar1 = _malloc(0x14);
      if (pvVar1 == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_005d78db(puVar2[8],0,"Value");
      }
      if (iVar3 != 0) {
        puVar2[8] = iVar3;
        FUN_005bb1eb(puVar2);
        return puVar2;
      }
    }
  }
LAB_005bcdd7:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// ==== 0x5bcdf7 FUN_005bcdf7

undefined4 FUN_005bcdf7(int *param_1,int *param_2)

{
  double dVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *param_1;
  if (iVar2 == 0) {
    iVar2 = *param_2;
    if (((iVar2 != 0) && (iVar2 != 1)) && (iVar2 != 2)) {
      if (iVar2 != 3) {
        return 0x80004005;
      }
      param_1[2] = (uint)(*(double *)(param_2 + 2) != 0.0);
      return 0;
    }
    param_1[2] = (uint)(param_2[2] != 0);
    return 0;
  }
  if ((iVar2 == 1) || (iVar2 == 2)) {
    iVar2 = *param_2;
    if (iVar2 == 0) {
      uVar3 = (uint)(param_2[2] != 0);
    }
    else if ((iVar2 == 1) || (iVar2 == 2)) {
      uVar3 = param_2[2];
    }
    else {
      if (iVar2 != 3) {
        return 0x80004005;
      }
      uVar3 = __ftol();
    }
    goto LAB_005bced8;
  }
  if (iVar2 == 3) {
    iVar2 = *param_2;
    if (iVar2 == 0) {
      dVar1 = (double)(param_2[2] != 0);
    }
    else if (iVar2 == 1) {
      dVar1 = (double)param_2[2];
    }
    else if (iVar2 == 2) {
      dVar1 = (double)param_2[2];
      if (param_2[2] < 0) {
        dVar1 = dVar1 + 4294967296.0;
      }
    }
    else {
      if (iVar2 != 3) {
        return 0x80004005;
      }
      dVar1 = *(double *)(param_2 + 2);
    }
    *(double *)(param_1 + 2) = dVar1;
    return 0;
  }
  if (iVar2 == 4) {
    if (*param_2 != 4) goto LAB_005bce30;
  }
  else {
    if (iVar2 != 5) {
      return 0x80004005;
    }
LAB_005bce30:
    if (*param_2 == 4) {
      *param_1 = 4;
    }
    else if (*param_2 != 5) {
      return 0x80004005;
    }
  }
  uVar3 = param_2[2];
LAB_005bced8:
  param_1[2] = uVar3;
  return 0;
}


// ==== 0x5bcf1c FUN_005bcf1c

undefined4 FUN_005bcf1c(uint *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *param_2;
  if (iVar1 == 0) {
    uVar2 = (uint)(param_2[2] != 0);
  }
  else if ((iVar1 == 1) || (iVar1 == 2)) {
    uVar2 = param_2[2];
  }
  else {
    if (iVar1 != 3) {
      return 0x80004005;
    }
    uVar2 = __ftol();
  }
  *param_1 = uVar2;
  return 0;
}


// ==== 0x5bcf79 FUN_005bcf79

undefined4 FUN_005bcf79(int *param_1,double param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    if (param_2 == 0.0) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  else {
    if ((iVar1 != 1) && (iVar1 != 2)) {
      if (iVar1 == 3) {
        *(double *)(param_1 + 2) = param_2;
        return 0;
      }
      return 0x80004005;
    }
    iVar1 = __ftol();
  }
  param_1[2] = iVar1;
  return 0;
}


// ==== 0x5bcfe4 FUN_005bcfe4

int __thiscall FUN_005bcfe4(undefined4 param_1,int param_2,int param_3,int param_4,uint param_5)

{
  int *piVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  bool bVar9;
  undefined1 local_24 [4];
  uint local_20;
  undefined1 local_18 [4];
  uint local_14;
  undefined4 local_c;
  int local_8;
  
  local_8 = 0;
  local_c = param_1;
  if ((param_3 == 0) || (*(int *)(param_2 + 0x1c) == 0)) {
    if ((param_3 == 0) != (*(int *)(param_2 + 0x1c) == 0)) {
      local_8 = 2;
    }
  }
  else {
    iVar4 = FUN_005d7700(*(undefined4 *)(*(int *)(param_2 + 0x1c) + 0x18),0,local_18);
    if ((iVar4 < 0) || (iVar4 = FUN_005d7700(*(undefined4 *)(param_3 + 0x18),0,local_24), iVar4 < 0)
       ) {
      pbVar8 = *(byte **)(*(int *)(param_2 + 0x1c) + 0x18);
      pbVar5 = *(byte **)(param_3 + 0x18);
      do {
        bVar2 = *pbVar5;
        bVar9 = bVar2 < *pbVar8;
        if (bVar2 != *pbVar8) {
LAB_005bd097:
          iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_005bd09c;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar5[1];
        bVar9 = bVar2 < pbVar8[1];
        if (bVar2 != pbVar8[1]) goto LAB_005bd097;
        pbVar5 = pbVar5 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar2 != 0);
      iVar4 = 0;
LAB_005bd09c:
      if (iVar4 != 0) {
        return -1;
      }
    }
    else if (local_14 != local_20) {
      if (((local_20 ^ local_14) & 0xffff0000) != 0) {
        return -1;
      }
      if (((local_14 & 0xffff) != 0) && ((local_20 & 0xffff) != 0)) {
        return -1;
      }
      local_8 = 2 - (uint)((local_20 & 0xffff) != 0);
    }
  }
  iVar4 = *(int *)(param_2 + 0x24);
  param_2 = param_4;
  if (iVar4 != 0) {
    do {
      piVar1 = (int *)(iVar4 + 8);
      iVar4 = *(int *)(iVar4 + 0xc);
      bVar9 = false;
      if ((iVar4 != 0) && (*(int *)(*(int *)(iVar4 + 8) + 4) == 0xb)) {
        iVar4 = *(int *)(iVar4 + 0xc);
        bVar9 = true;
      }
      if (((param_5 & 0x10) == 0) || ((*(byte *)(*(int *)(*piVar1 + 0x18) + 0x1c) & 0x40) != 0)) {
        if (param_2 == 0) {
          if (!bVar9) {
            return -1;
          }
        }
        else {
          iVar7 = *(int *)(*piVar1 + 0x18);
          uVar3 = *(undefined4 *)(iVar7 + 0x20);
          if (*(int *)(param_2 + 8) == 0) {
            param_3 = 0;
          }
          else {
            param_3 = *(undefined4 *)(*(int *)(param_2 + 8) + 0x10);
          }
          if ((*(byte *)(iVar7 + 0x1c) & 0x10) != 0) {
            iVar6 = FUN_005bbe7f(uVar3,param_3,0);
            if (iVar6 == 0) {
              return -1;
            }
            iVar6 = FUN_005bbcbb(uVar3,param_3);
            local_8 = local_8 + iVar6;
          }
          if ((*(byte *)(iVar7 + 0x1c) & 0x20) != 0) {
            iVar7 = FUN_005ba70c(param_3);
            if (iVar7 != 0) {
              return -1;
            }
            iVar7 = FUN_005bbe7f(param_3,uVar3,0);
            if (iVar7 == 0) {
              return -1;
            }
            iVar7 = FUN_005bbcbb(param_3,uVar3);
            local_8 = local_8 + iVar7;
          }
          param_2 = *(int *)(param_2 + 0xc);
        }
      }
    } while (iVar4 != 0);
  }
  if (param_2 != 0) {
    return -1;
  }
  return local_8;
}


// ==== 0x5bd1b1 FUN_005bd1b1

int __thiscall FUN_005bd1b1(int param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x14);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_005d78db(0,*(undefined4 *)(param_1 + 0x10),"UsageType");
  }
  if (iVar2 == 0) {
    FUN_005ba2ce(0);
    iVar2 = -0x7ff8fff2;
  }
  else {
    *(int *)(param_1 + 0x10) = iVar2;
    if (param_2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar3 = FUN_005d7885(param_2);
      *(int *)(iVar2 + 8) = iVar3;
      if (iVar3 == 0) {
        FUN_005ba2ce(0);
        iVar2 = -0x7ff8fff2;
      }
      else {
        iVar2 = FUN_005bbdd0(iVar3,*(undefined4 *)(iVar3 + 0x18));
        if (-1 < iVar2) {
          *(byte *)(iVar3 + 0x11) = *(byte *)(iVar3 + 0x11) & 0xf1;
          iVar2 = 0;
        }
      }
    }
  }
  return iVar2;
}


// ==== 0x5bd234 FUN_005bd234

int __thiscall FUN_005bd234(undefined4 param_1,int param_2,double *param_3)

{
  double *pdVar1;
  uint *puVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  uint uVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  undefined8 *puVar12;
  uint uVar13;
  undefined4 *puVar14;
  double *pdVar15;
  int iVar16;
  double *pdVar17;
  double *pdVar18;
  int iVar19;
  float10 fVar20;
  undefined8 uVar21;
  uint local_68 [13];
  undefined8 local_34;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  double *local_1c;
  double *local_18;
  double *local_14;
  double *local_10;
  undefined4 local_c;
  double *local_8;
  
  iVar19 = (int)param_3;
  local_c = param_1;
  if (param_2 == 0) {
    if (param_3 != (double *)0x0) {
      return -0x7fffbffb;
    }
    return 0;
  }
  if (*(int *)(param_2 + 4) != 0xc) {
    return -0x7fffbffb;
  }
  local_8 = (double *)(*(int *)(param_2 + 0x14) * *(int *)(param_2 + 0x18));
  if (*(int *)(param_2 + 0x1c) != 0x1a) {
    return -0x7fffbffb;
  }
  local_68[4] = 0;
  local_68[5] = 0;
  local_68[6] = 0;
  local_68[7] = 0;
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_68[8] = 0;
  local_68[9] = 0;
  local_68[0xc] = *(int *)(param_2 + 0x24);
  local_18 = *(double **)(*(int *)(param_2 + 0x24) + 8);
  local_68[10] = 0;
  local_68[0xb] = 0;
  if (local_18 != (double *)0x0) {
    local_10 = (double *)0x0;
    do {
      pdVar15 = local_10;
      iVar10 = *(int *)(local_18 + 1);
      if ((iVar10 != 0) && (*(int *)(iVar10 + 4) == 0xc)) {
        uVar8 = *(int *)(iVar10 + 0x18) * *(int *)(iVar10 + 0x14);
        puVar2 = (uint *)((int)local_68 + (int)local_10);
        *puVar2 = uVar8;
        *(int *)((int)(local_68 + 4) + (int)pdVar15) = iVar10;
        puVar9 = _malloc(uVar8 * 0x10);
        *(undefined4 **)((int)(local_68 + 8) + (int)local_10) = puVar9;
        if (puVar9 == (undefined4 *)0x0) {
          iVar10 = -0x7ff8fff2;
          goto LAB_005be4c0;
        }
        iVar10 = FUN_005bf509(*(int *)((int)(local_68 + 4) + (int)pdVar15),puVar9);
        if (iVar10 < 0) goto LAB_005be4c0;
        local_14 = (double *)0x0;
        if (*puVar2 != 0) {
          local_34 = (double)CONCAT44(param_2 + 0x30,(undefined4)local_34);
          puVar14 = puVar9 + 2;
          do {
            uVar21 = FUN_005bb002(puVar14,puVar9,local_34._4_4_);
            iVar10 = (int)uVar21;
            if (iVar10 < 0) goto LAB_005be4c0;
            local_14 = (double *)((int)local_14 + 1);
            *puVar9 = 3;
            puVar9 = puVar9 + 4;
            puVar14 = (undefined4 *)((int)((ulonglong)uVar21 >> 0x20) + 0x10);
          } while (local_14 < (double *)*puVar2);
        }
      }
      puVar9 = (undefined4 *)((int)local_18 + 0xc);
      local_10 = (double *)((int)local_10 + 4);
      local_18 = (double *)*puVar9;
    } while ((double *)*puVar9 != (double *)0x0);
  }
  uVar8 = local_68[0xc];
  pdVar15 = local_8;
  switch(*(undefined4 *)(*(int *)(*(int *)(param_2 + 0x20) + 8) + 0x18)) {
  case 0:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)((int)param_3 + 8);
      pdVar18 = local_8;
      do {
        *pdVar17 = ABS(*(double *)((local_68[8] - (int)param_3) + (int)pdVar17));
        pdVar17 = pdVar17 + 2;
        pdVar18 = (double *)((int)pdVar18 + -1);
      } while (pdVar18 != (double *)0x0);
    }
    break;
  case 1:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)(local_68[8] + 8);
      iVar10 = (int)param_3 - local_68[8];
      param_3 = local_8;
      do {
        if ((*pdVar17 < -1.0) || (1.0 < *pdVar17)) {
          FUN_005ba1d9(local_c,param_2 + 0x30,0xbfe,"indefinite acos");
        }
        fVar20 = (float10)FUN_00672e20();
        *(double *)(iVar10 + (int)pdVar17) = (double)fVar20;
        pdVar17 = pdVar17 + 2;
        param_3 = (double *)((int)param_3 + -1);
        uVar8 = local_68[0xc];
        pdVar15 = local_8;
      } while (param_3 != (double *)0x0);
    }
    break;
  case 2:
    pdVar17 = (double *)0x0;
    *(undefined8 *)((int)param_3 + 8) = 0x3ff0000000000000;
    if (local_8 != (double *)0x0) {
      pdVar18 = (double *)(local_68[8] + 8);
      do {
        if (*pdVar18 == 0.0) {
          dVar4 = 0.0;
          goto LAB_005bd84a;
        }
        pdVar17 = (double *)((int)pdVar17 + 1);
        pdVar18 = pdVar18 + 2;
      } while (pdVar17 < local_8);
    }
    break;
  case 3:
    pdVar17 = (double *)0x0;
    *(undefined8 *)((int)param_3 + 8) = 0;
    if (local_8 != (double *)0x0) {
      pdVar18 = (double *)(local_68[8] + 8);
      do {
        if (*pdVar18 != 0.0) {
          dVar4 = 1.0;
          goto LAB_005bd84a;
        }
        pdVar17 = (double *)((int)pdVar17 + 1);
        pdVar18 = pdVar18 + 2;
      } while (pdVar17 < local_8);
    }
    break;
  case 4:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)(local_68[8] + 8);
      iVar10 = (int)param_3 - local_68[8];
      param_3 = local_8;
      do {
        if ((*pdVar17 < -1.0) || (1.0 < *pdVar17)) {
          FUN_005ba1d9(local_c,param_2 + 0x30,0xbff,"indefinite asin");
        }
        fVar20 = (float10)FUN_00673b70();
        *(double *)((int)pdVar17 + iVar10) = (double)fVar20;
        pdVar17 = pdVar17 + 2;
        param_3 = (double *)((int)param_3 + -1);
        uVar8 = local_68[0xc];
        pdVar15 = local_8;
      } while (param_3 != (double *)0x0);
    }
    break;
  case 5:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)((int)param_3 + 8);
      pdVar18 = local_8;
      do {
        fVar20 = (float10)fpatan((float10)*(double *)((int)pdVar17 + (local_68[8] - (int)param_3)),
                                 (float10)1);
        *pdVar17 = (double)fVar20;
        pdVar17 = pdVar17 + 2;
        pdVar18 = (double *)((int)pdVar18 + -1);
      } while (pdVar18 != (double *)0x0);
    }
    break;
  case 6:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)(local_68[9] + 8);
      pdVar18 = local_8;
      do {
        fVar20 = (float10)fpatan((float10)*(double *)((local_68[8] - local_68[9]) + (int)pdVar17),
                                 (float10)*pdVar17);
        *(double *)(((int)param_3 - local_68[9]) + (int)pdVar17) = (double)fVar20;
        pdVar17 = pdVar17 + 2;
        pdVar18 = (double *)((int)pdVar18 + -1);
      } while (pdVar18 != (double *)0x0);
    }
    break;
  case 7:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)((int)param_3 + 8);
      iVar10 = local_68[8] - (int)param_3;
      param_3 = local_8;
      do {
        uVar21 = *(undefined8 *)((int)pdVar17 + iVar10);
        fVar20 = (float10)FUN_006736c0((int)uVar21,(int)((ulonglong)uVar21 >> 0x20));
        *pdVar17 = (double)fVar20;
        pdVar17 = pdVar17 + 2;
        param_3 = (double *)((int)param_3 + -1);
        uVar8 = local_68[0xc];
        pdVar15 = local_8;
      } while (param_3 != (double *)0x0);
    }
    break;
  case 8:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)(local_68[10] + 8);
      local_10 = (double *)(local_68[8] - local_68[10]);
      local_1c = local_8;
      do {
        pdVar18 = (double *)((int)(local_68[8] - local_68[10]) + (int)pdVar17);
        if (*(double *)((local_68[9] - local_68[10]) + (int)pdVar17) <= *pdVar18) {
          if (*pdVar18 <= *pdVar17) {
            dVar4 = *pdVar18;
          }
          else {
            dVar4 = *pdVar17;
          }
        }
        else {
          dVar4 = *(double *)((local_68[9] - local_68[10]) + (int)pdVar17);
        }
        *(double *)(((int)param_3 - local_68[10]) + (int)pdVar17) = dVar4;
        pdVar17 = pdVar17 + 2;
        local_1c = (double *)((int)local_1c + -1);
      } while (local_1c != (double *)0x0);
    }
    break;
  default:
    goto switchD_005bd37f_caseD_9;
  case 10:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)((int)param_3 + 8);
      pdVar18 = local_8;
      do {
        fVar20 = (float10)fcos((float10)*(double *)((int)pdVar17 + (local_68[8] - (int)param_3)));
        *pdVar17 = (double)fVar20;
        pdVar17 = pdVar17 + 2;
        pdVar18 = (double *)((int)pdVar18 + -1);
      } while (pdVar18 != (double *)0x0);
    }
    break;
  case 0xb:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)((int)param_3 + 8);
      param_3 = local_8;
      do {
        fVar20 = (float10)FUN_00673802();
        *pdVar17 = (double)fVar20;
        pdVar17 = pdVar17 + 2;
        param_3 = (double *)((int)param_3 + -1);
        uVar8 = local_68[0xc];
        pdVar15 = local_8;
      } while (param_3 != (double *)0x0);
    }
    break;
  case 0xc:
    *(double *)((int)param_3 + 8) =
         *(double *)(local_68[8] + 0x18) * *(double *)(local_68[9] + 0x28) -
         *(double *)(local_68[8] + 0x28) * *(double *)(local_68[9] + 0x18);
    *(double *)((int)param_3 + 0x18) =
         *(double *)(local_68[8] + 0x28) * *(double *)(local_68[9] + 8) -
         *(double *)(local_68[9] + 0x28) * *(double *)(local_68[8] + 8);
    *(double *)((int)param_3 + 0x28) =
         *(double *)(local_68[9] + 0x18) * *(double *)(local_68[8] + 8) -
         *(double *)(local_68[8] + 0x18) * *(double *)(local_68[9] + 8);
    break;
  case 0xd:
    if (local_8 != (double *)0x0) {
      puVar12 = (undefined8 *)((int)param_3 + 8);
      pdVar17 = local_8;
      do {
        *puVar12 = 0;
        puVar12 = puVar12 + 2;
        pdVar17 = (double *)((int)pdVar17 + -1);
      } while (pdVar17 != (double *)0x0);
    }
    break;
  case 0xe:
    if (local_8 != (double *)0x0) {
      puVar12 = (undefined8 *)((int)param_3 + 8);
      pdVar17 = local_8;
      do {
        *puVar12 = 0;
        puVar12 = puVar12 + 2;
        pdVar17 = (double *)((int)pdVar17 + -1);
      } while (pdVar17 != (double *)0x0);
    }
    break;
  case 0xf:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)((int)param_3 + 8);
      pdVar18 = local_8;
      do {
        *pdVar17 = *(double *)((int)pdVar17 + (local_68[8] - (int)param_3)) * 57.29577791868205;
        pdVar17 = pdVar17 + 2;
        pdVar18 = (double *)((int)pdVar18 + -1);
      } while (pdVar18 != (double *)0x0);
    }
    break;
  case 0x10:
    iVar10 = *(int *)(local_68[4] + 0x14);
    if (iVar10 == 1) {
      dVar4 = *(double *)(local_68[8] + 8);
    }
    else if (iVar10 == 2) {
      dVar4 = *(double *)(local_68[8] + 0x38) * *(double *)(local_68[8] + 8) -
              *(double *)(local_68[8] + 0x28) * *(double *)(local_68[8] + 0x18);
    }
    else {
      if (iVar10 != 3) {
        if (iVar10 == 4) {
          dVar4 = *(double *)(local_68[8] + 0xa8) * *(double *)(local_68[8] + 0xf8) -
                  *(double *)(local_68[8] + 0xb8) * *(double *)(local_68[8] + 0xe8);
          dVar6 = *(double *)(local_68[8] + 0xf8) * *(double *)(local_68[8] + 0x98) -
                  *(double *)(local_68[8] + 0xd8) * *(double *)(local_68[8] + 0xb8);
          dVar7 = *(double *)(local_68[8] + 0x98) * *(double *)(local_68[8] + 0xe8) -
                  *(double *)(local_68[8] + 0xa8) * *(double *)(local_68[8] + 0xd8);
          dVar5 = *(double *)(local_68[8] + 0xf8) * *(double *)(local_68[8] + 0x88) -
                  *(double *)(local_68[8] + 0xb8) * *(double *)(local_68[8] + 200);
          dVar3 = *(double *)(local_68[8] + 0xe8) * *(double *)(local_68[8] + 0x88) -
                  *(double *)(local_68[8] + 0xa8) * *(double *)(local_68[8] + 200);
          local_34 = *(double *)(local_68[8] + 0xd8) * *(double *)(local_68[8] + 0x88) -
                     *(double *)(local_68[8] + 0x98) * *(double *)(local_68[8] + 200);
          *(double *)((int)param_3 + 8) =
               ((local_34 * *(double *)(local_68[8] + 0x78) +
                (dVar6 * *(double *)(local_68[8] + 0x48) - dVar5 * *(double *)(local_68[8] + 0x58)))
                * *(double *)(local_68[8] + 0x28) +
               ((dVar7 * *(double *)(local_68[8] + 0x78) +
                (dVar4 * *(double *)(local_68[8] + 0x58) - dVar6 * *(double *)(local_68[8] + 0x68)))
                * *(double *)(local_68[8] + 8) -
               (dVar3 * *(double *)(local_68[8] + 0x78) +
               (dVar4 * *(double *)(local_68[8] + 0x48) - dVar5 * *(double *)(local_68[8] + 0x68)))
               * *(double *)(local_68[8] + 0x18))) -
               (local_34 * *(double *)(local_68[8] + 0x68) +
               (dVar7 * *(double *)(local_68[8] + 0x48) - dVar3 * *(double *)(local_68[8] + 0x58)))
               * *(double *)(local_68[8] + 0x38);
          break;
        }
        goto switchD_005bd37f_caseD_9;
      }
      dVar4 = (*(double *)(local_68[8] + 0x38) * *(double *)(local_68[8] + 0x78) -
              *(double *)(local_68[8] + 0x48) * *(double *)(local_68[8] + 0x68)) *
              *(double *)(local_68[8] + 0x28) +
              ((*(double *)(local_68[8] + 0x88) * *(double *)(local_68[8] + 0x48) -
               *(double *)(local_68[8] + 0x58) * *(double *)(local_68[8] + 0x78)) *
               *(double *)(local_68[8] + 8) -
              (*(double *)(local_68[8] + 0x38) * *(double *)(local_68[8] + 0x88) -
              *(double *)(local_68[8] + 0x58) * *(double *)(local_68[8] + 0x68)) *
              *(double *)(local_68[8] + 0x18));
    }
    goto LAB_005bd84a;
  case 0x11:
    dVar4 = 0.0;
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)(local_68[9] + 8);
      pdVar18 = local_8;
      dVar4 = 0.0;
      do {
        dVar3 = *(double *)((int)pdVar17 + (local_68[8] - local_68[9])) - *pdVar17;
        pdVar17 = pdVar17 + 2;
        pdVar18 = (double *)((int)pdVar18 + -1);
        dVar4 = dVar3 * dVar3 + dVar4;
      } while (pdVar18 != (double *)0x0);
    }
    goto LAB_005bd87d;
  case 0x12:
    *(undefined8 *)((int)param_3 + 8) = 0;
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)(local_68[8] + 8);
      pdVar18 = local_8;
      do {
        pdVar1 = (double *)((local_68[9] - local_68[8]) + (int)pdVar17);
        dVar4 = *pdVar17;
        pdVar17 = pdVar17 + 2;
        pdVar18 = (double *)((int)pdVar18 + -1);
        *(double *)((int)param_3 + 8) = *pdVar1 * dVar4 + *(double *)((int)param_3 + 8);
      } while (pdVar18 != (double *)0x0);
    }
    break;
  case 0x13:
    *(undefined8 *)((int)param_3 + 8) = 0x3ff0000000000000;
    *(double *)((int)param_3 + 0x18) =
         *(double *)(local_68[9] + 0x18) * *(double *)(local_68[8] + 0x18);
    *(undefined8 *)((int)param_3 + 0x28) = *(undefined8 *)(local_68[8] + 0x28);
    *(undefined8 *)((int)param_3 + 0x38) = *(undefined8 *)(local_68[9] + 0x38);
    break;
  case 0x14:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)((int)param_3 + 8);
      param_3 = local_8;
      do {
        fVar20 = (float10)FUN_00673b1c();
        *pdVar17 = (double)fVar20;
        pdVar17 = pdVar17 + 2;
        param_3 = (double *)((int)param_3 + -1);
        uVar8 = local_68[0xc];
        pdVar15 = local_8;
      } while (param_3 != (double *)0x0);
    }
    break;
  case 0x15:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)((int)param_3 + 8);
      param_3 = local_8;
      do {
        fVar20 = (float10)FUN_00673890();
        *pdVar17 = (double)fVar20;
        pdVar17 = pdVar17 + 2;
        param_3 = (double *)((int)param_3 + -1);
        uVar8 = local_68[0xc];
        pdVar15 = local_8;
      } while (param_3 != (double *)0x0);
    }
    break;
  case 0x16:
    dVar4 = 0.0;
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)(local_68[9] + 8);
      pdVar18 = local_8;
      do {
        pdVar1 = (double *)((local_68[10] - local_68[9]) + (int)pdVar17);
        dVar3 = *pdVar17;
        pdVar17 = pdVar17 + 2;
        pdVar18 = (double *)((int)pdVar18 + -1);
        dVar4 = *pdVar1 * dVar3 + dVar4;
      } while (pdVar18 != (double *)0x0);
      if (local_8 != (double *)0x0) {
        pdVar17 = (double *)(local_68[8] + 8);
        pdVar18 = local_8;
        do {
          dVar3 = *pdVar17;
          if (0.0 <= dVar4) {
            dVar3 = -dVar3;
          }
          *(double *)((int)pdVar17 + ((int)param_3 - local_68[8])) = dVar3;
          pdVar17 = pdVar17 + 2;
          pdVar18 = (double *)((int)pdVar18 + -1);
        } while (pdVar18 != (double *)0x0);
      }
    }
    break;
  case 0x17:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)((int)param_3 + 8);
      iVar10 = local_68[8] - (int)param_3;
      param_3 = local_8;
      do {
        uVar21 = *(undefined8 *)((int)pdVar17 + iVar10);
        fVar20 = (float10)FUN_00673590((int)uVar21,(int)((ulonglong)uVar21 >> 0x20));
        *pdVar17 = (double)fVar20;
        pdVar17 = pdVar17 + 2;
        param_3 = (double *)((int)param_3 + -1);
        uVar8 = local_68[0xc];
        pdVar15 = local_8;
      } while (param_3 != (double *)0x0);
    }
    break;
  case 0x18:
    if (local_8 != (double *)0x0) {
      iVar10 = (int)param_3 - local_68[9];
      pdVar17 = (double *)(local_68[9] + 8);
      local_1c = local_8;
      do {
        if (*pdVar17 == 0.0) {
          FUN_005ba1d9(local_c,param_2 + 0x30,0xbd9,"division by zero");
        }
        fVar20 = (float10)FUN_0067381a();
        *(double *)(iVar10 + (int)pdVar17) = (double)fVar20;
        pdVar17 = pdVar17 + 2;
        local_1c = (double *)((int)local_1c + -1);
        uVar8 = local_68[0xc];
        pdVar15 = local_8;
      } while (local_1c != (double *)0x0);
    }
    break;
  case 0x19:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)(local_68[8] + 8);
      iVar10 = (int)param_3 - local_68[8];
      param_3 = local_8;
      do {
        iVar16 = _finite(SUB84(*pdVar17,0),(int)((ulonglong)*pdVar17 >> 0x20));
        if (iVar16 == 0) {
          fVar20 = (float10)0;
        }
        else {
          fVar20 = (float10)FUN_00673590(SUB84(*pdVar17,0),(int)((ulonglong)*pdVar17 >> 0x20));
          fVar20 = (float10)*pdVar17 - fVar20;
        }
        *(double *)((int)pdVar17 + iVar10) = (double)fVar20;
        pdVar17 = pdVar17 + 2;
        param_3 = (double *)((int)param_3 + -1);
        uVar8 = local_68[0xc];
        pdVar15 = local_8;
      } while (param_3 != (double *)0x0);
    }
    break;
  case 0x1b:
    if (local_8 != (double *)0x0) {
      puVar12 = (undefined8 *)((int)param_3 + 8);
      pdVar17 = local_8;
      do {
        *puVar12 = 0;
        puVar12 = puVar12 + 2;
        pdVar17 = (double *)((int)pdVar17 + -1);
      } while (pdVar17 != (double *)0x0);
    }
    break;
  case 0x1c:
    if (local_8 != (double *)0x0) {
      puVar12 = (undefined8 *)((int)param_3 + 8);
      iVar10 = local_68[8] - (int)param_3;
      param_3 = local_8;
      do {
        uVar21 = *(undefined8 *)((int)puVar12 + iVar10);
        iVar16 = _finite((int)uVar21,(int)((ulonglong)uVar21 >> 0x20));
        if (iVar16 == 0) {
          uVar21 = 0;
        }
        else {
          uVar21 = 0x3ff0000000000000;
        }
        *puVar12 = uVar21;
        puVar12 = puVar12 + 2;
        param_3 = (double *)((int)param_3 + -1);
        uVar8 = local_68[0xc];
        pdVar15 = local_8;
      } while (param_3 != (double *)0x0);
    }
    break;
  case 0x1d:
    if (local_8 != (double *)0x0) {
      puVar12 = (undefined8 *)((int)param_3 + 8);
      iVar10 = local_68[8] - (int)param_3;
      param_3 = local_8;
      do {
        uVar21 = *(undefined8 *)((int)puVar12 + iVar10);
        iVar16 = _finite((int)uVar21,(int)((ulonglong)uVar21 >> 0x20));
        if (iVar16 == 0) {
          uVar21 = 0x3ff0000000000000;
        }
        else {
          uVar21 = 0;
        }
        *puVar12 = uVar21;
        puVar12 = puVar12 + 2;
        param_3 = (double *)((int)param_3 + -1);
        uVar8 = local_68[0xc];
        pdVar15 = local_8;
      } while (param_3 != (double *)0x0);
    }
    break;
  case 0x1e:
    if (local_8 != (double *)0x0) {
      puVar12 = (undefined8 *)((int)param_3 + 8);
      iVar10 = local_68[8] - (int)param_3;
      param_3 = local_8;
      do {
        iVar16 = __isnan(*(double *)((int)puVar12 + iVar10));
        if (iVar16 == 0) {
          uVar21 = 0;
        }
        else {
          uVar21 = 0x3ff0000000000000;
        }
        *puVar12 = uVar21;
        puVar12 = puVar12 + 2;
        param_3 = (double *)((int)param_3 + -1);
        uVar8 = local_68[0xc];
        pdVar15 = local_8;
      } while (param_3 != (double *)0x0);
    }
    break;
  case 0x1f:
    if (local_8 != (double *)0x0) {
      iVar10 = (int)param_3 - local_68[8];
      pdVar17 = (double *)(local_68[8] + 8);
      local_1c = local_8;
      do {
        fVar20 = (float10)FUN_00673890();
        *(double *)((int)pdVar17 + iVar10) = (double)(fVar20 * (float10)*pdVar17);
        pdVar17 = pdVar17 + 2;
        local_1c = (double *)((int)local_1c + -1);
        uVar8 = local_68[0xc];
        pdVar15 = local_8;
      } while (local_1c != (double *)0x0);
    }
    break;
  case 0x20:
    dVar4 = 0.0;
    if (local_8 != (double *)0x0) {
      pdVar18 = (double *)(local_68[8] + 8);
      pdVar17 = local_8;
      do {
        dVar3 = *pdVar18;
        pdVar18 = pdVar18 + 2;
        pdVar17 = (double *)((int)pdVar17 + -1);
        dVar4 = dVar3 * dVar3 + dVar4;
      } while (pdVar17 != (double *)0x0);
    }
LAB_005bd87d:
    dVar4 = SQRT(dVar4);
LAB_005bd84a:
    *(double *)((int)param_3 + 8) = dVar4;
    break;
  case 0x21:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)(local_68[8] + 8);
      iVar10 = (int)param_3 - local_68[8];
      param_3 = local_8;
      do {
        pdVar18 = (double *)((local_68[10] - local_68[8]) + (int)pdVar17);
        *(double *)((int)pdVar17 + iVar10) =
             (*(double *)((int)pdVar18 + (local_68[9] - local_68[10])) - *pdVar17) * *pdVar18 +
             *pdVar17;
        pdVar17 = pdVar17 + 2;
        param_3 = (double *)((int)param_3 + -1);
      } while (param_3 != (double *)0x0);
    }
    break;
  case 0x22:
    *(undefined8 *)((int)param_3 + 8) = 0x3ff0000000000000;
    *(undefined8 *)((int)param_3 + 0x18) = 0;
    *(undefined8 *)((int)param_3 + 0x28) = 0;
    *(undefined8 *)((int)param_3 + 0x38) = 0x3ff0000000000000;
    if ((0.0 < *(double *)(local_68[8] + 8)) &&
       (*(undefined8 *)((int)param_3 + 0x18) = *(undefined8 *)(local_68[8] + 8),
       0.0 < *(double *)(local_68[9] + 8))) {
      fVar20 = (float10)FUN_00673890();
      *(double *)((int)param_3 + 0x28) = (double)fVar20;
      uVar8 = local_68[0xc];
      pdVar15 = local_8;
    }
    break;
  case 0x23:
    if (local_8 != (double *)0x0) {
      iVar10 = (int)param_3 - local_68[8];
      pdVar17 = (double *)(local_68[8] + 8);
      local_1c = local_8;
      do {
        if (*pdVar17 < 0.0 != (*pdVar17 == 0.0)) {
          FUN_005ba1d9(local_c,param_2 + 0x30,0xbd8,"infinite/indefinite log");
          pdVar15 = local_8;
        }
        fVar20 = (float10)log2((float10)*pdVar17);
        *(double *)((int)pdVar17 + iVar10) = (double)((float10)0.6931471805599453 * fVar20);
        pdVar17 = pdVar17 + 2;
        local_1c = (double *)((int)local_1c + -1);
        uVar8 = local_68[0xc];
      } while (local_1c != (double *)0x0);
    }
    break;
  case 0x24:
    if (local_8 != (double *)0x0) {
      iVar10 = (int)param_3 - local_68[8];
      pdVar17 = (double *)(local_68[8] + 8);
      fVar20 = (float10)log2((float10)10.0);
      local_34 = (double)((float10)0.6931471805599453 * fVar20);
      local_1c = local_8;
      do {
        if (*pdVar17 < 0.0 != (*pdVar17 == 0.0)) {
          FUN_005ba1d9(local_c,param_2 + 0x30,0xbd8,"infinite/indefinite log");
          pdVar15 = local_8;
        }
        fVar20 = (float10)log2((float10)*pdVar17);
        *(double *)(iVar10 + (int)pdVar17) =
             (double)(((float10)0.6931471805599453 * fVar20) / (float10)local_34);
        pdVar17 = pdVar17 + 2;
        local_1c = (double *)((int)local_1c + -1);
        uVar8 = local_68[0xc];
      } while (local_1c != (double *)0x0);
    }
    break;
  case 0x25:
    if (local_8 != (double *)0x0) {
      iVar10 = (int)param_3 - local_68[8];
      pdVar17 = (double *)(local_68[8] + 8);
      fVar20 = (float10)log2((float10)2.0);
      local_34 = (double)((float10)0.6931471805599453 * fVar20);
      local_1c = local_8;
      do {
        if (*pdVar17 < 0.0 != (*pdVar17 == 0.0)) {
          FUN_005ba1d9(local_c,param_2 + 0x30,0xbd8,"infinite/indefinite log");
          pdVar15 = local_8;
        }
        fVar20 = (float10)log2((float10)*pdVar17);
        *(double *)(iVar10 + (int)pdVar17) =
             (double)(((float10)0.6931471805599453 * fVar20) / (float10)local_34);
        pdVar17 = pdVar17 + 2;
        local_1c = (double *)((int)local_1c + -1);
        uVar8 = local_68[0xc];
      } while (local_1c != (double *)0x0);
    }
    break;
  case 0x26:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)(local_68[9] + 8);
      iVar10 = (int)param_3 - local_68[9];
      param_3 = local_8;
      do {
        if (*(double *)((local_68[8] - local_68[9]) + (int)pdVar17) <= *pdVar17) {
          dVar4 = *pdVar17;
        }
        else {
          dVar4 = *(double *)((local_68[8] - local_68[9]) + (int)pdVar17);
        }
        *(double *)(iVar10 + (int)pdVar17) = dVar4;
        pdVar17 = pdVar17 + 2;
        param_3 = (double *)((int)param_3 + -1);
      } while (param_3 != (double *)0x0);
    }
    break;
  case 0x27:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)(local_68[9] + 8);
      iVar10 = (int)param_3 - local_68[9];
      param_3 = local_8;
      do {
        if (*pdVar17 <= *(double *)((local_68[8] - local_68[9]) + (int)pdVar17)) {
          dVar4 = *pdVar17;
        }
        else {
          dVar4 = *(double *)((local_68[8] - local_68[9]) + (int)pdVar17);
        }
        *(double *)(iVar10 + (int)pdVar17) = dVar4;
        pdVar17 = pdVar17 + 2;
        param_3 = (double *)((int)param_3 + -1);
      } while (param_3 != (double *)0x0);
    }
    break;
  case 0x29:
  case 0x2a:
  case 0x2b:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)((int)param_3 + 8);
      pdVar18 = local_8;
      do {
        *pdVar17 = *(double *)((local_68[9] - (int)param_3) + (int)pdVar17) *
                   *(double *)(local_68[8] + 8);
        pdVar17 = pdVar17 + 2;
        pdVar18 = (double *)((int)pdVar18 + -1);
      } while (pdVar18 != (double *)0x0);
    }
    break;
  case 0x2c:
  case 0x2f:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)((int)param_3 + 8);
      pdVar18 = local_8;
      do {
        *pdVar17 = *(double *)((int)pdVar17 + (local_68[8] - (int)param_3)) *
                   *(double *)(local_68[9] + 8);
        pdVar17 = pdVar17 + 2;
        pdVar18 = (double *)((int)pdVar18 + -1);
      } while (pdVar18 != (double *)0x0);
    }
    break;
  case 0x2d:
  case 0x2e:
  case 0x30:
  case 0x31:
    iVar10 = *(int *)(local_68[4] + 0x14);
    local_24 = *(int *)(local_68[4] + 0x18);
    if (*(int *)(*(int *)(local_68[5] + 0x10) + 0x10) == 1) {
      iVar16 = *(int *)(local_68[5] + 0x18);
      local_20 = *(int *)(local_68[5] + 0x14);
    }
    else {
      iVar16 = *(int *)(local_68[5] + 0x14);
      local_20 = *(int *)(local_68[5] + 0x18);
    }
    if ((local_24 == iVar16) && (local_20 * iVar10 - (int)local_8 == 0)) {
      if (iVar10 != 0) {
        local_1c = (double *)(local_68[8] + 8);
        local_10 = (double *)((int)param_3 + 8);
        local_34 = (double)CONCAT44(iVar10,(undefined4)local_34);
        do {
          if (local_20 != 0) {
            local_18 = (double *)(local_68[9] + 8);
            local_14 = local_10;
            local_2c = local_20;
            do {
              dVar4 = 0.0;
              if (local_24 != 0) {
                param_3 = local_18;
                pdVar17 = local_1c;
                local_28 = local_24;
                do {
                  dVar3 = *param_3;
                  param_3 = param_3 + local_20 * 2;
                  dVar5 = *pdVar17;
                  pdVar17 = pdVar17 + 2;
                  local_28 = local_28 + -1;
                  dVar4 = dVar3 * dVar5 + dVar4;
                } while (local_28 != 0);
              }
              local_18 = local_18 + 2;
              *local_14 = dVar4;
              local_14 = local_14 + 2;
              local_2c = local_2c + -1;
            } while (local_2c != 0);
          }
          local_10 = local_10 + local_20 * 2;
          local_1c = local_1c + local_24 * 2;
          iVar10 = local_34._4_4_ + -1;
          local_34 = (double)CONCAT44(iVar10,(undefined4)local_34);
        } while (iVar10 != 0);
      }
      break;
    }
    goto switchD_005bd37f_caseD_9;
  case 0x33:
    dVar4 = 0.0;
    if (local_8 == (double *)0x0) {
LAB_005bdf24:
      dVar4 = 0.0;
    }
    else {
      pdVar17 = (double *)(local_68[8] + 8);
      pdVar18 = local_8;
      do {
        dVar3 = *pdVar17;
        pdVar17 = pdVar17 + 2;
        pdVar18 = (double *)((int)pdVar18 + -1);
        dVar4 = dVar3 * dVar3 + dVar4;
      } while (pdVar18 != (double *)0x0);
      if (dVar4 == 0.0) goto LAB_005bdf24;
      dVar4 = 1.0 / SQRT(dVar4);
    }
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)((int)param_3 + 8);
      pdVar18 = local_8;
      do {
        *pdVar17 = dVar4 * *(double *)((int)pdVar17 + (local_68[8] - (int)param_3));
        pdVar17 = pdVar17 + 2;
        pdVar18 = (double *)((int)pdVar18 + -1);
      } while (pdVar18 != (double *)0x0);
    }
    break;
  case 0x34:
    if (local_8 != (double *)0x0) {
      iVar16 = (int)param_3 - local_68[9];
      iVar10 = local_68[9] + 8;
      local_34 = (double)CONCAT44(local_8,(undefined4)local_34);
      do {
        fVar20 = (float10)FUN_00673890();
        *(double *)(iVar10 + iVar16) = (double)fVar20;
        iVar11 = FUN_00672f2e((double)fVar20);
        if ((0 < iVar11) && (iVar11 < 3)) {
          FUN_005ba1d9(local_c,param_2 + 0x30,0xbd8,"indefinite power");
        }
        iVar10 = iVar10 + 0x10;
        iVar11 = local_34._4_4_ + -1;
        local_34 = (double)CONCAT44(iVar11,(undefined4)local_34);
        uVar8 = local_68[0xc];
        pdVar15 = local_8;
      } while (iVar11 != 0);
    }
    break;
  case 0x35:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)((int)param_3 + 8);
      pdVar18 = local_8;
      do {
        *pdVar17 = *(double *)((int)pdVar17 + (local_68[8] - (int)param_3)) * 0.017453293005625408;
        pdVar17 = pdVar17 + 2;
        pdVar18 = (double *)((int)pdVar18 + -1);
      } while (pdVar18 != (double *)0x0);
    }
    break;
  case 0x36:
    dVar4 = 0.0;
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)(local_68[8] + 8);
      local_34 = (double)CONCAT44(local_8,(undefined4)local_34);
      do {
        pdVar18 = (double *)((int)pdVar17 + (local_68[9] - local_68[8]));
        dVar3 = *pdVar17;
        pdVar17 = pdVar17 + 2;
        iVar10 = local_34._4_4_ + -1;
        local_34 = (double)CONCAT44(iVar10,(undefined4)local_34);
        dVar4 = *pdVar18 * dVar3 + dVar4;
      } while (iVar10 != 0);
      if (local_8 != (double *)0x0) {
        pdVar17 = (double *)(local_68[9] + 8);
        pdVar18 = local_8;
        do {
          *(double *)(((int)param_3 - local_68[9]) + (int)pdVar17) =
               *(double *)((local_68[8] - local_68[9]) + (int)pdVar17) -
               (dVar4 * *pdVar17 + dVar4 * *pdVar17);
          pdVar17 = pdVar17 + 2;
          pdVar18 = (double *)((int)pdVar18 + -1);
        } while (pdVar18 != (double *)0x0);
      }
    }
    break;
  case 0x37:
    dVar4 = *(double *)(local_68[10] + 8);
    dVar3 = 0.0;
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)(local_68[8] + 8);
      local_34 = (double)CONCAT44(local_8,(undefined4)local_34);
      do {
        pdVar18 = (double *)((int)pdVar17 + (local_68[9] - local_68[8]));
        dVar5 = *pdVar17;
        pdVar17 = pdVar17 + 2;
        iVar10 = local_34._4_4_ + -1;
        local_34 = (double)CONCAT44(iVar10,(undefined4)local_34);
        dVar3 = *pdVar18 * dVar5 + dVar3;
      } while (iVar10 != 0);
    }
    dVar5 = (1.0 - dVar3 * dVar3) * dVar4 * dVar4;
    if (0.0 <= dVar5) {
      if (local_8 != (double *)0x0) {
        pdVar17 = (double *)(local_68[9] + 8);
        pdVar18 = local_8;
        do {
          *(double *)(((int)param_3 - local_68[9]) + (int)pdVar17) =
               dVar4 * *(double *)((local_68[8] - local_68[9]) + (int)pdVar17) -
               (dVar3 * dVar4 + SQRT(dVar5)) * *pdVar17;
          pdVar17 = pdVar17 + 2;
          pdVar18 = (double *)((int)pdVar18 + -1);
        } while (pdVar18 != (double *)0x0);
      }
    }
    else if (local_8 != (double *)0x0) {
      puVar12 = (undefined8 *)((int)param_3 + 8);
      pdVar17 = local_8;
      do {
        *puVar12 = 0;
        puVar12 = puVar12 + 2;
        pdVar17 = (double *)((int)pdVar17 + -1);
      } while (pdVar17 != (double *)0x0);
    }
    break;
  case 0x38:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)((int)param_3 + 8);
      param_3 = local_8;
      do {
        iVar10 = __ftol();
        local_34 = (double)CONCAT44(iVar10,(undefined4)local_34);
        *pdVar17 = (double)iVar10;
        pdVar17 = pdVar17 + 2;
        param_3 = (double *)((int)param_3 + -1);
        uVar8 = local_68[0xc];
        pdVar15 = local_8;
      } while (param_3 != (double *)0x0);
    }
    break;
  case 0x39:
    if (local_8 != (double *)0x0) {
      iVar10 = (int)param_3 - local_68[8];
      pdVar17 = (double *)(local_68[8] + 8);
      local_34 = (double)CONCAT44(local_8,(undefined4)local_34);
      do {
        if (*pdVar17 < 0.0) {
          FUN_005ba1d9(local_c,param_2 + 0x30,0xbd7,"imaginary square root");
          pdVar15 = local_8;
        }
        if (*pdVar17 == 0.0) {
          FUN_005ba1d9(local_c,param_2 + 0x30,0xbd9,"division by zero");
          pdVar15 = local_8;
        }
        *(double *)((int)pdVar17 + iVar10) = 1.0 / SQRT(*pdVar17);
        pdVar17 = pdVar17 + 2;
        iVar16 = local_34._4_4_ + -1;
        local_34 = (double)CONCAT44(iVar16,(undefined4)local_34);
        uVar8 = local_68[0xc];
      } while (iVar16 != 0);
    }
    break;
  case 0x3a:
    if (local_8 != (double *)0x0) {
      puVar12 = (undefined8 *)((int)param_3 + 8);
      iVar10 = local_68[8] - (int)param_3;
      pdVar17 = local_8;
      do {
        if (0.0 <= *(double *)((int)puVar12 + iVar10)) {
          if (*(double *)((int)puVar12 + iVar10) <= 1.0) {
            uVar21 = *(undefined8 *)((int)puVar12 + iVar10);
          }
          else {
            uVar21 = 0x3ff0000000000000;
          }
        }
        else {
          uVar21 = 0;
        }
        *puVar12 = uVar21;
        puVar12 = puVar12 + 2;
        pdVar17 = (double *)((int)pdVar17 + -1);
      } while (pdVar17 != (double *)0x0);
    }
    break;
  case 0x3b:
    if (local_8 != (double *)0x0) {
      puVar12 = (undefined8 *)((int)param_3 + 8);
      pdVar17 = local_8;
      do {
        if (0.0 <= *(double *)((int)puVar12 + (local_68[8] - (int)param_3))) {
          if (*(double *)((int)puVar12 + (local_68[8] - (int)param_3)) <= 0.0) {
            uVar21 = 0;
          }
          else {
            uVar21 = 0x3ff0000000000000;
          }
        }
        else {
          uVar21 = 0xbff0000000000000;
        }
        *puVar12 = uVar21;
        puVar12 = puVar12 + 2;
        pdVar17 = (double *)((int)pdVar17 + -1);
      } while (pdVar17 != (double *)0x0);
    }
    break;
  case 0x3c:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)((int)param_3 + 8);
      pdVar18 = local_8;
      do {
        fVar20 = (float10)fsin((float10)*(double *)((int)pdVar17 + (local_68[8] - (int)param_3)));
        *pdVar17 = (double)fVar20;
        pdVar17 = pdVar17 + 2;
        pdVar18 = (double *)((int)pdVar18 + -1);
      } while (pdVar18 != (double *)0x0);
    }
    break;
  case 0x3e:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)((int)param_3 + 8);
      param_3 = local_8;
      do {
        fVar20 = (float10)FUN_006737f8();
        *pdVar17 = (double)fVar20;
        pdVar17 = pdVar17 + 2;
        param_3 = (double *)((int)param_3 + -1);
        uVar8 = local_68[0xc];
        pdVar15 = local_8;
      } while (param_3 != (double *)0x0);
    }
    break;
  case 0x3f:
    if (local_8 != (double *)0x0) {
      local_10 = (double *)(local_68[8] - local_68[10]);
      pdVar17 = (double *)(local_68[10] + 8);
      iVar10 = (int)param_3 - local_68[10];
      param_3 = local_8;
      do {
        if (*(double *)((int)pdVar17 + (int)local_10) <= *pdVar17) {
          if (*(double *)((int)pdVar17 + (local_68[9] - local_68[10])) <= *pdVar17) {
            uVar21 = 0x3ff0000000000000;
            goto LAB_005be2b3;
          }
          dVar4 = (*pdVar17 - *(double *)((int)pdVar17 + (int)local_10)) /
                  (*(double *)((int)pdVar17 + (local_68[9] - local_68[10])) -
                  *(double *)((int)pdVar17 + (int)local_10));
          dVar3 = dVar4 * dVar4 * dVar4;
          *(double *)((int)pdVar17 + iVar10) = dVar4 * dVar4 * 3.0 - (dVar3 + dVar3);
        }
        else {
          uVar21 = 0;
LAB_005be2b3:
          *(undefined8 *)((int)pdVar17 + iVar10) = uVar21;
        }
        pdVar17 = pdVar17 + 2;
        param_3 = (double *)((int)param_3 + -1);
      } while (param_3 != (double *)0x0);
    }
    break;
  case 0x40:
    if (local_8 != (double *)0x0) {
      iVar10 = (int)param_3 - local_68[8];
      pdVar17 = (double *)(local_68[8] + 8);
      local_34 = (double)CONCAT44(local_8,(undefined4)local_34);
      do {
        if (*pdVar17 < 0.0) {
          FUN_005ba1d9(local_c,param_2 + 0x30,0xbd7,"imaginary square root");
          pdVar15 = local_8;
        }
        *(double *)(iVar10 + (int)pdVar17) = SQRT(*pdVar17);
        pdVar17 = pdVar17 + 2;
        iVar16 = local_34._4_4_ + -1;
        local_34 = (double)CONCAT44(iVar16,(undefined4)local_34);
        uVar8 = local_68[0xc];
      } while (iVar16 != 0);
    }
    break;
  case 0x41:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)(local_68[8] + 8);
      iVar10 = (int)param_3 - local_68[8];
      param_3 = local_8;
      do {
        if (*(double *)((int)pdVar17 + (local_68[9] - local_68[8])) < *pdVar17) {
          uVar21 = 0;
        }
        else {
          uVar21 = 0x3ff0000000000000;
        }
        *(undefined8 *)(iVar10 + (int)pdVar17) = uVar21;
        pdVar17 = pdVar17 + 2;
        param_3 = (double *)((int)param_3 + -1);
      } while (param_3 != (double *)0x0);
    }
    break;
  case 0x42:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)((int)param_3 + 8);
      pdVar18 = local_8;
      do {
        fVar20 = (float10)fptan((float10)*(double *)((int)pdVar17 + (local_68[8] - (int)param_3)));
        *pdVar17 = (double)fVar20;
        pdVar17 = pdVar17 + 2;
        pdVar18 = (double *)((int)pdVar18 + -1);
      } while (pdVar18 != (double *)0x0);
    }
    break;
  case 0x43:
    if (local_8 != (double *)0x0) {
      pdVar17 = (double *)((int)param_3 + 8);
      param_3 = local_8;
      do {
        fVar20 = (float10)FUN_00673809();
        *pdVar17 = (double)fVar20;
        pdVar17 = pdVar17 + 2;
        param_3 = (double *)((int)param_3 + -1);
        uVar8 = local_68[0xc];
        pdVar15 = local_8;
      } while (param_3 != (double *)0x0);
    }
    break;
  case 0x54:
    local_10 = (double *)0x0;
    if (*(int *)(local_68[4] + 0x18) != 0) {
      uVar13 = *(uint *)(local_68[4] + 0x14);
      do {
        param_3 = (double *)0x0;
        if (uVar13 != 0) {
          do {
            iVar10 = *(int *)(local_68[4] + 0x18) * (int)param_3;
            iVar16 = *(int *)(param_2 + 0x18) * (int)local_10 + (int)param_3;
            param_3 = (double *)((int)param_3 + 1);
            *(undefined8 *)(iVar16 * 0x10 + 8 + iVar19) =
                 *(undefined8 *)((int)(iVar10 + (int)local_10) * 0x10 + 8 + local_68[8]);
            uVar13 = *(uint *)(local_68[4] + 0x14);
          } while (param_3 < uVar13);
        }
        local_10 = (double *)((int)local_10 + 1);
      } while (local_10 < *(double **)(local_68[4] + 0x18));
    }
    break;
  case 0x55:
    *(double *)((int)param_3 + 8) = *(double *)(local_68[8] + 0x28) * 255.001953125;
    *(double *)((int)param_3 + 0x18) = *(double *)(local_68[8] + 0x18) * 255.001953125;
    *(double *)((int)param_3 + 0x28) = *(double *)(local_68[8] + 8) * 255.001953125;
    *(double *)((int)param_3 + 0x38) = *(double *)(local_68[8] + 0x38) * 255.001953125;
  }
  do {
    uVar8 = *(int *)(uVar8 + 0xc);
    if (uVar8 == 0) {
      param_3 = (double *)0x0;
      if (pdVar15 == (double *)0x0) goto LAB_005be4b7;
      goto LAB_005be491;
    }
  } while (*(int *)(uVar8 + 8) == 0);
switchD_005bd37f_caseD_9:
  iVar10 = -0x7fffbffb;
LAB_005be4c0:
  uVar8 = 0;
  do {
    _free((void *)local_68[uVar8 + 8]);
    uVar8 = uVar8 + 1;
  } while (uVar8 < 4);
  return iVar10;
  while( true ) {
    param_3 = (double *)((int)param_3 + 1);
    iVar19 = iVar19 + 0x10;
    if (local_8 <= param_3) break;
LAB_005be491:
    iVar10 = FUN_005bcf79(iVar19,(int)*(undefined8 *)(iVar19 + 8),
                          (int)((ulonglong)*(undefined8 *)(iVar19 + 8) >> 0x20),param_2 + 0x30);
    if (iVar10 < 0) goto LAB_005be4c0;
  }
LAB_005be4b7:
  iVar10 = 0;
  goto LAB_005be4c0;
}


// ==== 0x5be628 FUN_005be628

undefined4 __thiscall
FUN_005be628(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            int param_6,uint param_7,int *param_8,undefined4 *param_9)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  undefined4 uVar9;
  int *piVar10;
  byte *pbVar11;
  int *piVar12;
  char *pcVar13;
  uint uVar14;
  short *psVar15;
  char *pcVar16;
  bool bVar17;
  undefined8 uVar18;
  undefined4 uVar19;
  int local_114 [64];
  int local_14;
  uint local_10;
  undefined4 local_c;
  uint local_8;
  
  local_c = param_1;
  if (param_8 != (int *)0x0) {
    *param_8 = 0;
  }
  if (param_9 != (undefined4 *)0x0) {
    *param_9 = 0;
  }
  local_10 = 0xffffffff;
  local_8 = 0;
  if (param_6 != 0) {
    do {
      if (local_10 == 0) break;
      local_14 = *(int *)(param_6 + 0x18);
      while ((local_14 != 0 && (local_10 != 0))) {
        iVar8 = *(int *)(local_14 + 8);
        pbVar11 = *(byte **)(*(int *)(iVar8 + 0x14) + 0x18);
        pbVar4 = *(byte **)(param_3 + 8);
        do {
          bVar1 = *pbVar4;
          bVar17 = bVar1 < *pbVar11;
          if (bVar1 != *pbVar11) {
LAB_005be6a8:
            iVar6 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
            goto LAB_005be6ad;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar17 = bVar1 < pbVar11[1];
          if (bVar1 != pbVar11[1]) goto LAB_005be6a8;
          pbVar4 = pbVar4 + 2;
          pbVar11 = pbVar11 + 2;
        } while (bVar1 != 0);
        iVar6 = 0;
LAB_005be6ad:
        if (iVar6 == 0) {
          if (param_2 != *(int *)(iVar8 + 0x10)) {
            if ((param_7 & 5) != 0) {
              FUN_005ba1d9(local_c,param_3,0xbbd,"\'%s\': identifier represents a %s, not a %s",
                           *(undefined4 *)(param_3 + 8),(&PTR_DAT_0069f464)[*(int *)(iVar8 + 0x10)],
                           (&PTR_DAT_0069f464)[param_2]);
            }
            if (param_8 != (int *)0x0) {
              *param_8 = 0;
            }
            return 0x80004005;
          }
          uVar14 = 0;
          if ((param_7 & 4) != 0) {
            uVar14 = FUN_005bcfe4(*(undefined4 *)(iVar8 + 0x18),param_4,param_5,param_7);
          }
          if ((param_7 & 8) != 0) {
            iVar6 = FUN_005bbbae(*(undefined4 *)(iVar8 + 0x18),param_4,param_5,param_7);
            uVar14 = uVar14 + iVar6;
          }
          if (uVar14 != 0xffffffff) {
            if (uVar14 < local_10) {
              local_8 = 0;
              local_10 = uVar14;
            }
            uVar3 = local_8;
            if ((uVar14 == local_10) && (local_8 < 0x40)) {
              local_8 = local_8 + 1;
              local_114[uVar3] = iVar8;
            }
            if (((local_10 == 0) && (*(int *)(iVar8 + 0x2c) != 0)) && (*(int *)(iVar8 + 0x28) == 0))
            {
              iVar6 = *(int *)(param_6 + 0x1c);
              if ((iVar6 != 0) && (*(int *)(iVar6 + 0x10) == 4)) {
                for (iVar6 = *(int *)(iVar6 + 0x18); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0xc)) {
                  if (*(int *)(*(int *)(iVar6 + 8) + 0x2c) == 0) {
                    pbVar11 = *(byte **)(*(int *)(*(int *)(iVar6 + 8) + 0x14) + 0x18);
                    pbVar4 = *(byte **)(param_3 + 8);
                    do {
                      bVar1 = *pbVar4;
                      bVar17 = bVar1 < *pbVar11;
                      if (bVar1 != *pbVar11) {
LAB_005be78e:
                        iVar5 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
                        goto LAB_005be793;
                      }
                      if (bVar1 == 0) break;
                      bVar1 = pbVar4[1];
                      bVar17 = bVar1 < pbVar11[1];
                      if (bVar1 != pbVar11[1]) goto LAB_005be78e;
                      pbVar4 = pbVar4 + 2;
                      pbVar11 = pbVar11 + 2;
                    } while (bVar1 != 0);
                    iVar5 = 0;
LAB_005be793:
                    if (iVar5 == 0) {
                      FUN_005ba22d(local_c,param_3,0xc06,
                                   "\'%s\': loop control variable used outside for-loop scope conflicts with a previous declaration in the outer scope; most recent definition used"
                                   ,*(undefined4 *)(param_3 + 8));
                      *(undefined4 *)(iVar8 + 0x28) = 1;
                      break;
                    }
                  }
                }
              }
              for (iVar6 = *(int *)(local_14 + 0xc); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0xc)) {
                if (*(int *)(*(int *)(iVar6 + 8) + 0x2c) == 0) {
                  pbVar11 = *(byte **)(*(int *)(*(int *)(iVar6 + 8) + 0x14) + 0x18);
                  pbVar4 = *(byte **)(param_3 + 8);
                  do {
                    bVar1 = *pbVar4;
                    bVar17 = bVar1 < *pbVar11;
                    if (bVar1 != *pbVar11) {
LAB_005be802:
                      iVar5 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
                      goto LAB_005be807;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar4[1];
                    bVar17 = bVar1 < pbVar11[1];
                    if (bVar1 != pbVar11[1]) goto LAB_005be802;
                    pbVar4 = pbVar4 + 2;
                    pbVar11 = pbVar11 + 2;
                  } while (bVar1 != 0);
                  iVar5 = 0;
LAB_005be807:
                  if (iVar5 == 0) {
                    FUN_005ba22d(local_c,param_3,0xc06,
                                 "\'%s\': loop control variable used outside for-loop scope conflicts with a previous declaration in the outer scope; most recent definition used"
                                 ,*(undefined4 *)(param_3 + 8));
                    *(undefined4 *)(iVar8 + 0x28) = 1;
                    break;
                  }
                }
              }
            }
          }
        }
        local_14 = *(int *)(local_14 + 0xc);
      }
      param_6 = *(int *)(param_6 + 0x1c);
    } while (param_6 != 0);
    if (local_10 == 0xffffffff) goto LAB_005be9ff;
    if ((param_7 & 4) != 0) {
      iVar8 = *(int *)(local_114[0] + 0x18);
      uVar14 = 1;
      if (1 < local_8) {
        do {
          uVar18 = FUN_005ba894(*(undefined4 *)(iVar8 + 0x20),
                                *(undefined4 *)(*(int *)(local_114[uVar14] + 0x18) + 0x20));
          if (((int)uVar18 == 0) ||
             (iVar6 = FUN_005bbbae(iVar8,*(undefined4 *)(iVar8 + 0x1c),
                                   *(undefined4 *)((int)((ulonglong)uVar18 >> 0x20) + 0x24),0),
             iVar6 == -1)) break;
          uVar14 = uVar14 + 1;
        } while (uVar14 < local_8);
        if (uVar14 < local_8) {
          FUN_005ba1d9(local_c,param_3,0xbfb,"\'%s\': ambiguous function call",
                       *(undefined4 *)(param_3 + 8));
        }
      }
    }
    piVar10 = param_8;
    if (param_8 != (int *)0x0) {
      iVar8 = *(int *)(local_114[0] + 0x18);
      if ((param_7 & 2) != 0) {
        *param_8 = iVar8;
        goto LAB_005be947;
      }
      if (iVar8 == 0) goto LAB_005be947;
      iVar8 = FUN_005d7885(iVar8);
      *piVar10 = iVar8;
      if (iVar8 != 0) goto LAB_005be947;
      goto LAB_005bed8e;
    }
LAB_005be947:
    if (param_9 != (undefined4 *)0x0) {
      uVar14 = 0;
      param_8 = (undefined4 *)0x0;
      piVar12 = (int *)&param_8;
      if (local_8 != 0) {
        do {
          pvVar7 = _malloc(0x14);
          if (pvVar7 == (void *)0x0) {
            iVar8 = 0;
          }
          else {
            iVar8 = FUN_005d78db(0,0,"Values");
          }
          *piVar12 = iVar8;
          if (iVar8 == 0) {
LAB_005be9cb:
            if (param_8 != (undefined4 *)0x0) {
              (**(code **)*param_8)(1);
            }
            if (((piVar10 != (int *)0x0) && ((param_7 & 2) == 0)) &&
               ((undefined4 *)*piVar10 != (undefined4 *)0x0)) {
              (*(code *)**(undefined4 **)*piVar10)(1);
            }
            goto LAB_005bed8e;
          }
          pvVar7 = _malloc(0x40);
          if (pvVar7 == (void *)0x0) {
            iVar8 = 0;
          }
          else {
            iVar8 = FUN_005d8a65(2,*(undefined4 *)(local_114[uVar14] + 0x24),param_3);
          }
          *(int *)(*piVar12 + 8) = iVar8;
          if (iVar8 == 0) goto LAB_005be9cb;
          piVar12 = (int *)(*piVar12 + 0xc);
          uVar14 = uVar14 + 1;
        } while (uVar14 < local_8);
      }
      *param_9 = param_8;
    }
    goto LAB_005bed97;
  }
LAB_005be9ff:
  piVar10 = param_8;
  if (((param_7 & 2) != 0) || (param_9 != (undefined4 *)0x0)) goto LAB_005bed9b;
  if (param_2 == 0) {
    iVar8 = __stricmp(*(char **)(param_3 + 8),"dword");
    if (iVar8 == 0) {
      uVar9 = 4;
LAB_005bea4a:
      piVar10 = param_8;
      if (param_8 != (int *)0x0) {
        pvVar7 = _malloc(0x24);
        if (pvVar7 == (void *)0x0) {
LAB_005bea70:
          iVar8 = 0;
        }
        else {
          uVar19 = 0;
LAB_005beb7c:
          iVar8 = FUN_005d814c(uVar19,uVar9,1,1,0);
        }
        *piVar10 = iVar8;
LAB_005bea74:
        if (iVar8 == 0) goto LAB_005bed8e;
      }
    }
    else {
      iVar8 = __stricmp(*(char **)(param_3 + 8),"float");
      if (iVar8 == 0) {
        uVar9 = 0xb;
        goto LAB_005bea4a;
      }
      iVar8 = __stricmp(*(char **)(param_3 + 8),"vector");
      piVar10 = param_8;
      if (iVar8 == 0) {
        if (param_8 == (int *)0x0) goto LAB_005bed97;
        pvVar7 = _malloc(0x24);
        if (pvVar7 != (void *)0x0) {
          uVar19 = 1;
          uVar9 = 1;
          goto LAB_005beab5;
        }
LAB_005beaf4:
        iVar8 = 0;
LAB_005beaf6:
        *piVar10 = iVar8;
        goto LAB_005bea74;
      }
      iVar8 = __stricmp(*(char **)(param_3 + 8),"matrix");
      piVar10 = param_8;
      if (iVar8 != 0) {
        iVar8 = __stricmp(*(char **)(param_3 + 8),"string");
        if (iVar8 == 0) {
          uVar9 = 0xe;
        }
        else {
          iVar8 = __stricmp(*(char **)(param_3 + 8),"texture");
          if (iVar8 == 0) {
            uVar9 = 0xf;
          }
          else {
            iVar8 = __stricmp(*(char **)(param_3 + 8),"pixelshader");
            if (iVar8 == 0) {
              uVar9 = 0x19;
            }
            else {
              iVar8 = __stricmp(*(char **)(param_3 + 8),"vertexshader");
              if (iVar8 != 0) {
                piVar10 = *(int **)(param_3 + 8);
                piVar12 = piVar10;
                do {
                  iVar8 = *piVar12;
                  piVar12 = (int *)((int)piVar12 + 1);
                } while ((char)iVar8 != '\0');
                uVar14 = (int)piVar12 - (int)((int)piVar10 + 1);
                iVar8 = 3;
                if ((uVar14 < 4) || (*piVar10 != 0x6c6f6f62)) {
                  if (2 < uVar14) {
                    bVar17 = true;
                    piVar12 = piVar10;
                    pcVar13 = "int";
                    do {
                      if (iVar8 == 0) break;
                      iVar8 = iVar8 + -1;
                      bVar17 = (char)*piVar12 == *pcVar13;
                      piVar12 = (int *)((int)piVar12 + 1);
                      pcVar13 = pcVar13 + 1;
                    } while (bVar17);
                    if (bVar17) {
                      piVar10 = (int *)((int)piVar10 + 3);
                      uVar9 = 4;
                      iVar8 = uVar14 - 3;
                      goto LAB_005bec31;
                    }
                  }
                  if ((uVar14 < 4) || (*piVar10 != 0x666c6168)) {
                    if (4 < uVar14) {
                      iVar8 = 5;
                      bVar17 = true;
                      piVar12 = piVar10;
                      pcVar13 = "float";
                      do {
                        if (iVar8 == 0) break;
                        iVar8 = iVar8 + -1;
                        bVar17 = (char)*piVar12 == *pcVar13;
                        piVar12 = (int *)((int)piVar12 + 1);
                        pcVar13 = pcVar13 + 1;
                      } while (bVar17);
                      if (bVar17) {
                        piVar10 = (int *)((int)piVar10 + 5);
                        uVar9 = 0xb;
                        iVar8 = uVar14 - 5;
                        goto LAB_005bec31;
                      }
                    }
                    if (uVar14 < 6) goto LAB_005bed9b;
                    iVar8 = 3;
                    bVar17 = true;
                    piVar12 = piVar10;
                    psVar15 = (short *)"double";
                    do {
                      if (iVar8 == 0) break;
                      iVar8 = iVar8 + -1;
                      bVar17 = (short)*piVar12 == *psVar15;
                      piVar12 = (int *)((int)piVar12 + 2);
                      psVar15 = psVar15 + 1;
                    } while (bVar17);
                    if (!bVar17) goto LAB_005bed9b;
                    piVar10 = (int *)((int)piVar10 + 6);
                    uVar9 = 0xc;
                    iVar8 = uVar14 - 6;
                  }
                  else {
                    piVar10 = piVar10 + 1;
                    uVar9 = 10;
                    iVar8 = uVar14 - 4;
                  }
                }
                else {
                  uVar9 = 0;
                  piVar10 = piVar10 + 1;
                  iVar8 = uVar14 - 4;
                }
LAB_005bec31:
                if (iVar8 == 1) {
                  if (((char)*piVar10 < '1') || ('4' < (char)*piVar10)) {
LAB_005bed9b:
                    if ((param_7 & 1) != 0) {
                      FUN_005ba1d9(local_c,param_3,0xbbc,"undeclared identifier \'%s\'",
                                   *(undefined4 *)(param_3 + 8));
                    }
                    return 1;
                  }
                  if (param_8 != (int *)0x0) {
                    pvVar7 = _malloc(0x24);
                    if (pvVar7 != (void *)0x0) {
                      cVar2 = (char)*piVar10;
                      iVar8 = 1;
                      uVar19 = 1;
                      goto LAB_005bec6c;
                    }
LAB_005becd9:
                    iVar8 = 0;
LAB_005becdb:
                    *param_8 = iVar8;
                    goto LAB_005bea74;
                  }
                }
                else {
                  if (((((iVar8 != 3) || ((char)*piVar10 < '1')) || ('4' < (char)*piVar10)) ||
                      ((*(char *)((int)piVar10 + 1) != 'x' || (*(char *)((int)piVar10 + 2) < '1'))))
                     || ('4' < *(char *)((int)piVar10 + 2))) goto LAB_005bed9b;
                  if (param_8 != (int *)0x0) {
                    pvVar7 = _malloc(0x24);
                    if (pvVar7 == (void *)0x0) goto LAB_005becd9;
                    cVar2 = *(char *)((int)piVar10 + 2);
                    iVar8 = (char)*piVar10 + -0x30;
                    uVar19 = 2;
LAB_005bec6c:
                    iVar8 = FUN_005d814c(uVar19,uVar9,iVar8,cVar2 + -0x30,0);
                    goto LAB_005becdb;
                  }
                }
                goto LAB_005bed97;
              }
              uVar9 = 0x1a;
            }
          }
        }
        piVar10 = param_8;
        if (param_8 == (int *)0x0) goto LAB_005bed97;
        pvVar7 = _malloc(0x24);
        if (pvVar7 == (void *)0x0) goto LAB_005bea70;
        uVar19 = 3;
        goto LAB_005beb7c;
      }
      if (param_8 != (int *)0x0) {
        pvVar7 = _malloc(0x24);
        if (pvVar7 == (void *)0x0) goto LAB_005beaf4;
        uVar19 = 4;
        uVar9 = 2;
LAB_005beab5:
        iVar8 = FUN_005d814c(uVar9,0xb,uVar19,4,0);
        goto LAB_005beaf6;
      }
    }
LAB_005bed97:
    uVar9 = 0;
  }
  else {
    if (param_2 != 1) goto LAB_005bed9b;
    iVar8 = 5;
    bVar17 = true;
    pcVar13 = *(char **)(param_3 + 8);
    pcVar16 = "NULL";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar17 = *pcVar13 == *pcVar16;
      pcVar13 = pcVar13 + 1;
      pcVar16 = pcVar16 + 1;
    } while (bVar17);
    if (!bVar17) goto LAB_005bed9b;
    if (param_8 == (int *)0x0) goto LAB_005bed97;
    pvVar7 = _malloc(0x3c);
    if (pvVar7 == (void *)0x0) {
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_005d844d();
    }
    if (iVar8 != 0) {
      *(undefined4 *)(iVar8 + 0x18) = 0;
      *(undefined4 *)(iVar8 + 0x14) = 1;
      *(undefined4 *)(iVar8 + 0x1c) = 0x202;
      pvVar7 = _malloc(0x24);
      if (pvVar7 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005d814c(3,0xd,1,1,0x200);
      }
      *(int *)(iVar8 + 0x20) = iVar6;
      if (iVar6 != 0) {
        pvVar7 = _malloc(0x40);
        if (pvVar7 == (void *)0x0) {
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_005d8ad5(5,0,param_3);
        }
        *(int *)(iVar8 + 0x24) = iVar6;
        if (iVar6 != 0) {
          *piVar10 = iVar8;
          goto LAB_005bed97;
        }
      }
    }
LAB_005bed8e:
    uVar9 = 0x8007000e;
  }
  return uVar9;
}


// ==== 0x5bedc7 FUN_005bedc7

undefined4 * __thiscall FUN_005bedc7(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  if ((param_2 == 0) || (*(int *)(param_2 + 4) != 2)) {
    return (undefined4 *)0x0;
  }
  param_2 = param_2 + 0x10;
  puVar5 = param_3;
  if ((param_3 != (undefined4 *)0x0) ||
     (iVar1 = FUN_005be628(1,param_2,0,0,*(undefined4 *)(param_1 + 0xc),1,&local_8,0),
     puVar5 = local_8, iVar1 == 0)) {
    pvVar2 = _malloc(0x50);
    if (pvVar2 == (void *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = (undefined4 *)FUN_005d8831(0,0,0,0,1,param_2);
    }
    if (puVar3 != (undefined4 *)0x0) {
      if ((int *)puVar5[9] == (int *)0x0) {
        pvVar2 = _malloc(0x40);
        if (pvVar2 == (void *)0x0) {
          iVar1 = 0;
        }
        else {
          iVar1 = FUN_005d8b1b(6,puVar5[4],puVar5[5],param_2);
        }
      }
      else {
        iVar1 = (**(code **)(*(int *)puVar5[9] + 8))();
      }
      puVar3[8] = iVar1;
      if (iVar1 != 0) {
        uVar4 = FUN_005d7885(puVar5[8]);
        puVar3[4] = uVar4;
        if (param_3 != (undefined4 *)0x0) {
          FUN_005ba5ee(uVar4,0);
        }
        pvVar2 = _malloc(0x14);
        if (pvVar2 == (void *)0x0) {
          iVar1 = 0;
        }
        else {
          iVar1 = FUN_005d78db(puVar3[8],0,"Value");
        }
        if (iVar1 != 0) {
          puVar3[8] = iVar1;
          FUN_005bb1eb(puVar3);
          goto LAB_005beec9;
        }
      }
      (**(code **)*puVar3)(1);
    }
  }
  puVar3 = (undefined4 *)0x0;
LAB_005beec9:
  if ((param_3 == (undefined4 *)0x0) && (puVar5 != (undefined4 *)0x0)) {
    (**(code **)*puVar5)(1);
  }
  return puVar3;
}


// ==== 0x5beee7 FUN_005beee7

undefined4 * __thiscall
FUN_005beee7(int param_1,int *param_2,int *param_3,int param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  int *local_10;
  int local_c;
  int local_8;
  
  piVar1 = param_3;
  local_10 = (int *)0x0;
  piVar8 = param_2;
  local_8 = param_1;
  if ((param_2 != (int *)0x0) && (param_2[1] == 2)) {
    FUN_005be628(0,param_2 + 4,0,0,*(undefined4 *)(param_1 + 0xc),1,&local_10,0);
    piVar8 = local_10;
  }
  param_2 = (int *)(param_1 + 0x20);
  if (param_4 == 0) {
    local_c = 0;
    if (param_3 == (int *)0x0) {
LAB_005bef9d:
      iVar2 = FUN_005bbe7f(piVar8,local_c,param_5);
      if (iVar2 != 0) {
        iVar2 = FUN_005ba70c(piVar8);
        if (iVar2 == 0) {
          iVar2 = FUN_005ba70c(local_c);
          if (iVar2 == 0) {
            param_3 = (int *)0x0;
            goto LAB_005befea;
          }
        }
        param_3 = (int *)0x1;
        goto LAB_005befea;
      }
      FUN_005bc1ad(param_2,0,piVar8,local_c,param_5);
    }
    else if (param_3[1] == 0xc) {
      local_c = param_3[4];
      param_2 = param_3 + 0xc;
      goto LAB_005bef9d;
    }
  }
  else {
    if ((piVar8 != (int *)0x0) && (piVar8[1] == 8)) {
      iVar2 = FUN_005ba799(piVar8);
      if (iVar2 != 0) {
        if ((param_3 != (int *)0x0) && (param_3[1] != 1)) goto LAB_005bf0ca;
        param_3 = (int *)FUN_005ba70c(piVar8);
LAB_005befea:
        uVar3 = FUN_005bb05e(piVar1);
        param_3 = (int *)((uint)param_3 | uVar3);
        pvVar4 = _malloc(0x50);
        puVar7 = (undefined4 *)0x0;
        if (pvVar4 != (void *)0x0) {
          puVar7 = (undefined4 *)FUN_005d8831(0,0,0,0,1,param_2);
        }
        if (puVar7 == (undefined4 *)0x0) goto LAB_005bf0ca;
        if (piVar8 == (int *)0x0) {
LAB_005bf033:
          if (piVar1 != (int *)0x0) {
            iVar2 = (**(code **)(*piVar1 + 8))();
            puVar7[8] = iVar2;
            if (iVar2 == 0) goto LAB_005bf0c2;
          }
          if (param_4 != 0) {
            for (iVar2 = puVar7[8]; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
              iVar6 = *(int *)(iVar2 + 8);
              if ((iVar6 != 0) && (*(int *)(iVar6 + 4) == 0xc)) {
                iVar6 = FUN_005ba799(*(undefined4 *)(iVar6 + 0x10));
                if (iVar6 == 0) {
                  FUN_005ba1d9(local_8,param_2,0xbc9,
                               "cannot convert from \'object type\' to \'numeric type\'");
                  goto LAB_005bf0c2;
                }
                if (param_3 == (int *)0x0) {
                  param_3 = (int *)FUN_005ba70c(*(undefined4 *)(*(int *)(iVar2 + 8) + 0x10));
                }
              }
            }
          }
          if (param_3 != (int *)0x0) {
            FUN_005ba5ee(puVar7[4],1);
          }
          if (param_4 != 0) {
            iVar6 = 0;
            for (iVar2 = puVar7[8]; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
              iVar5 = *(int *)(iVar2 + 8);
              if ((iVar5 != 0) && (*(int *)(iVar5 + 4) == 0xc)) {
                iVar5 = FUN_005ba80b(*(undefined4 *)(iVar5 + 0x10));
                iVar6 = iVar6 + iVar5;
              }
            }
            iVar2 = FUN_005ba80b(puVar7[4]);
            if (iVar6 != iVar2) {
              FUN_005ba1d9(local_8,param_2,0xbc6,
                           "incorrect number of arguments to numeric-type constructor");
            }
          }
          FUN_005bb1eb(puVar7);
          goto LAB_005bf11f;
        }
        iVar2 = (**(code **)(*piVar8 + 8))();
        puVar7[4] = iVar2;
        if (iVar2 != 0) goto LAB_005bf033;
LAB_005bf0c2:
        (**(code **)*puVar7)(1);
        goto LAB_005bf0ca;
      }
    }
    FUN_005ba1d9(param_1,param_2,0xbdd,"constructors only defined for numeric base types");
  }
LAB_005bf0ca:
  puVar7 = (undefined4 *)0x0;
LAB_005bf11f:
  if (local_10 != (int *)0x0) {
    (**(code **)*local_10)(1);
  }
  return puVar7;
}


// ==== 0x5bf135 FUN_005bf135

undefined4 * __thiscall FUN_005bf135(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined8 uVar7;
  char *pcVar8;
  undefined4 uVar9;
  undefined4 local_28;
  int *local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  int local_8;
  
  if ((((param_2 != 0) && (*(int *)(param_2 + 4) != 0xc)) ||
      ((param_3 != 0 && (*(int *)(param_3 + 4) != 0xc)))) ||
     ((param_4 != 0 && (*(int *)(param_4 + 4) != 0xc)))) {
    return (undefined4 *)0x0;
  }
  local_1c = param_2 + 0x30;
  if (param_2 == 0) {
    local_1c = param_1 + 0x20;
    local_28 = 0;
  }
  else {
    local_28 = *(undefined4 *)(param_2 + 0x10);
  }
  if (param_3 == 0) {
    local_14 = (int *)0x0;
  }
  else {
    local_14 = *(int **)(param_3 + 0x10);
  }
  if (param_4 == 0) {
    local_18 = (int *)0x0;
  }
  else {
    local_18 = *(int **)(param_4 + 0x10);
  }
  local_20 = local_14;
  local_24 = local_18;
  local_c = (undefined4 *)0x0;
  local_8 = param_1;
  pvVar2 = _malloc(0x50);
  if (pvVar2 == (void *)0x0) {
    local_10 = (undefined4 *)0x0;
  }
  else {
    local_10 = (undefined4 *)FUN_005d8831(0,0x18,0,0,1,local_1c);
  }
  puVar1 = local_10;
  if (local_10 != (undefined4 *)0x0) {
    iVar3 = FUN_005ba799(local_28);
    if (iVar3 == 0) {
      pcVar8 = "conditional must be numeric";
LAB_005bf1fb:
      FUN_005ba1d9(param_1,local_1c,0xbcc,pcVar8);
    }
    else {
      piVar6 = puVar1 + 4;
      iVar3 = FUN_005bc254(local_14,local_18,&local_20,&local_24,piVar6);
      if (iVar3 < 0) {
        pcVar8 = "type mismatch between conditional values";
        goto LAB_005bf1fb;
      }
      if (*piVar6 != 0) {
        if (*(int *)(*piVar6 + 4) == 8) {
          pvVar2 = _malloc(0x24);
          if (pvVar2 == (void *)0x0) {
LAB_005bf2a8:
            local_c = (undefined4 *)0x0;
          }
          else {
            local_c = (undefined4 *)
                      FUN_005d814c(2,0,*(undefined4 *)(*piVar6 + 0x18),
                                   *(undefined4 *)(*piVar6 + 0x1c),0x200);
          }
        }
        else {
          pvVar2 = _malloc(0x24);
          param_1 = local_8;
          if (pvVar2 == (void *)0x0) goto LAB_005bf2a8;
          uVar9 = 0x200;
          uVar5 = FUN_005ba80b(*piVar6);
          local_c = (undefined4 *)FUN_005d814c(2,0,1,uVar5,uVar9);
          param_1 = local_8;
        }
        if (local_c != (undefined4 *)0x0) goto LAB_005bf2b4;
        goto LAB_005bf20c;
      }
LAB_005bf2b4:
      iVar3 = FUN_005bbe7f(local_c,local_28,0);
      if (iVar3 == 0) {
        pcVar8 = "dimension of conditional does not match value";
        goto LAB_005bf1fb;
      }
      if (param_2 != 0) {
        iVar3 = FUN_005beee7(local_c,param_2,0,0);
        local_10[8] = iVar3;
        if (iVar3 == 0) goto LAB_005bf20c;
      }
      pvVar2 = _malloc(0x50);
      if (pvVar2 == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_005d8831(0,0,0,0,1,local_1c);
      }
      local_10[9] = iVar3;
      if (iVar3 != 0) {
        pvVar2 = _malloc(0x14);
        if (pvVar2 == (void *)0x0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_005d78db(0,0,"Types");
        }
        *(int *)(iVar3 + 0x10) = iVar4;
        if (iVar4 != 0) {
          if (local_20 != (int *)0x0) {
            uVar5 = (**(code **)(*local_20 + 8))();
            *(undefined4 *)(*(int *)(iVar3 + 0x10) + 8) = uVar5;
            if (*(int *)(*(int *)(iVar3 + 0x10) + 8) == 0) goto LAB_005bf20c;
          }
          pvVar2 = _malloc(0x14);
          if (pvVar2 == (void *)0x0) {
            iVar4 = 0;
          }
          else {
            iVar4 = FUN_005d78db(0,0,"Value");
          }
          *(int *)(iVar3 + 0x20) = iVar4;
          if (iVar4 != 0) {
            if (param_3 != 0) {
              if (local_14 == local_20) {
LAB_005bf3c0:
                uVar5 = FUN_005d7885(param_3);
              }
              else {
                uVar7 = FUN_005ba894(local_14,local_20);
                if ((int)uVar7 != 0) goto LAB_005bf3c0;
                uVar5 = FUN_005beee7((int)((ulonglong)uVar7 >> 0x20),param_3,0,0);
              }
              *(undefined4 *)(*(int *)(iVar3 + 0x20) + 8) = uVar5;
              if (*(int *)(*(int *)(iVar3 + 0x20) + 8) == 0) goto LAB_005bf20c;
            }
            pvVar2 = _malloc(0x14);
            if (pvVar2 == (void *)0x0) {
              iVar4 = 0;
            }
            else {
              iVar4 = FUN_005d78db(0,0,"Types");
            }
            *(int *)(*(int *)(iVar3 + 0x10) + 0xc) = iVar4;
            if (iVar4 != 0) {
              if (local_24 != (int *)0x0) {
                uVar5 = (**(code **)(*local_24 + 8))();
                *(undefined4 *)(*(int *)(*(int *)(iVar3 + 0x10) + 0xc) + 8) = uVar5;
                if (*(int *)(*(int *)(*(int *)(iVar3 + 0x10) + 0xc) + 8) == 0) goto LAB_005bf20c;
              }
              pvVar2 = _malloc(0x14);
              if (pvVar2 == (void *)0x0) {
                iVar4 = 0;
              }
              else {
                iVar4 = FUN_005d78db(0,0,"Value");
              }
              *(int *)(*(int *)(iVar3 + 0x20) + 0xc) = iVar4;
              if (iVar4 != 0) {
                if (param_4 != 0) {
                  if (local_18 == local_24) {
LAB_005bf4fc:
                    uVar5 = FUN_005d7885(param_4);
                  }
                  else {
                    uVar7 = FUN_005ba894(local_18,local_24);
                    if ((int)uVar7 != 0) goto LAB_005bf4fc;
                    uVar5 = FUN_005beee7((int)((ulonglong)uVar7 >> 0x20),param_4,0,0);
                  }
                  *(undefined4 *)(*(int *)(*(int *)(iVar3 + 0x20) + 0xc) + 8) = uVar5;
                  if (*(int *)(*(int *)(*(int *)(iVar3 + 0x20) + 0xc) + 8) == 0) goto LAB_005bf20c;
                }
                FUN_005bb1eb(iVar3);
                FUN_005bb1eb(local_10);
                goto LAB_005bf4b1;
              }
            }
          }
        }
      }
    }
LAB_005bf20c:
    (**(code **)*local_10)(1);
  }
  local_10 = (undefined4 *)0x0;
LAB_005bf4b1:
  if (local_c != (undefined4 *)0x0) {
    (**(code **)*local_c)(1);
  }
  piVar6 = local_20;
  if (((local_20 != local_14) && (local_20 != local_18)) && (local_20 != (int *)0x0)) {
    (**(code **)*local_20)(1);
  }
  if (((local_24 != local_14) && (local_24 != local_18)) &&
     ((local_24 != piVar6 && (local_24 != (int *)0x0)))) {
    (**(code **)*local_24)(1);
  }
  return local_10;
}


// ==== 0x5bf509 FUN_005bf509

int FUN_005bf509(undefined4 *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  double *pdVar9;
  int iVar10;
  bool bVar11;
  byte bVar12;
  float10 fVar13;
  undefined8 uVar14;
  uint local_2c;
  uint local_28;
  uint local_24;
  undefined8 local_20;
  undefined8 local_18;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined4 local_8;
  
  iVar10 = (int)param_1;
  if ((param_1 == (undefined4 *)0x0) || (*(int *)((int)param_1 + 4) != 0xc)) {
    return -0x7fffbffb;
  }
  uVar7 = *(int *)((int)param_1 + 0x14) * *(int *)((int)param_1 + 0x18);
  iVar2 = FUN_005baec2(*(undefined4 *)((int)param_1 + 0x10),param_2);
  uVar4 = (uint)local_18;
  if (uVar7 - iVar2 != 0) {
    return -0x7fffbffb;
  }
  iVar2 = *(int *)((int)param_1 + 0x1c);
  if (1 < iVar2) {
    if (iVar2 < 4) {
      return -0x7fffbffb;
    }
    if (0x13 < iVar2) {
      if (iVar2 < 0x16) {
        return -0x7fffbffb;
      }
      if (iVar2 == 0x19) {
        return -0x7fffbffb;
      }
      if (iVar2 == 0x1a) {
        iVar10 = FUN_005bd234(param_1,param_2);
        return iVar10;
      }
      if (iVar2 == 0x1b) {
        return -0x7fffbffb;
      }
    }
  }
  uVar8 = *(uint *)((int)param_1 + 0x20);
  local_2c = 0;
  local_20 = (double)(ulonglong)(uint)local_20;
  local_c = (undefined4 *)0x0;
  local_10 = (undefined4 *)0x0;
  local_18 = (double)(ulonglong)(uint)local_18;
  local_24 = 0;
  uVar6 = 0;
  if ((uVar8 != 0) && (*(int *)(uVar8 + 4) == 0xc)) {
    iVar2 = *(int *)(uVar8 + 0x18) * *(int *)(uVar8 + 0x14);
    local_18 = (double)CONCAT44(iVar2,uVar4);
    local_2c = uVar8;
    local_c = _malloc(iVar2 * 0x10);
    uVar6 = uVar8;
    if (local_c != (undefined4 *)0x0) goto LAB_005bf5c4;
LAB_005bf5f1:
    iVar2 = -0x7ff8fff2;
    goto LAB_005bfcc8;
  }
LAB_005bf5c4:
  uVar4 = *(uint *)((int)param_1 + 0x24);
  uVar8 = 0;
  if ((uVar4 != 0) && (*(int *)(uVar4 + 4) == 0xc)) {
    local_24 = *(int *)(uVar4 + 0x18) * *(int *)(uVar4 + 0x14);
    local_20 = (double)CONCAT44(uVar4,(uint)local_20);
    local_10 = _malloc(local_24 * 0x10);
    uVar8 = uVar4;
    if (local_10 == (undefined4 *)0x0) goto LAB_005bf5f1;
  }
  if (*(int *)((int)param_1 + 0x28) == 0) {
    uVar4 = uVar6;
    if ((uVar8 != 0) && (iVar2 = FUN_005bf509(), iVar2 < 0)) goto LAB_005bfcc8;
  }
  else {
    uVar4 = uVar8;
    if (uVar6 != 0) {
      iVar2 = FUN_005bf509();
      if (iVar2 < 0) goto LAB_005bfcc8;
      uVar4 = local_20._4_4_;
    }
  }
  if ((uVar4 != 0) && (iVar2 = FUN_005bf509(), iVar2 < 0)) goto LAB_005bfcc8;
  puVar5 = local_c;
  iVar2 = *(int *)((int)param_1 + 0x1c);
  if (iVar2 < 0) {
LAB_005bfa79:
    local_28 = 0;
    if (local_18._4_4_ != 0) {
      do {
        uVar14 = FUN_005bb002(puVar5 + 2,puVar5,(int)param_1 + 0x30);
        puVar5 = (undefined4 *)((ulonglong)uVar14 >> 0x20);
        iVar2 = (int)uVar14;
        if (iVar2 < 0) goto LAB_005bfcc8;
        local_28 = local_28 + 1;
        *puVar5 = 3;
        puVar5 = puVar5 + 4;
      } while (local_28 < local_18._4_4_);
    }
    local_28 = 0;
    if (local_24 != 0) {
      puVar5 = local_10;
      do {
        uVar14 = FUN_005bb002(puVar5 + 2,puVar5,(int)param_1 + 0x30);
        puVar5 = (undefined4 *)((ulonglong)uVar14 >> 0x20);
        iVar2 = (int)uVar14;
        if (iVar2 < 0) goto LAB_005bfcc8;
        local_28 = local_28 + 1;
        *puVar5 = 3;
        puVar5 = puVar5 + 4;
        uVar6 = local_2c;
      } while (local_28 < local_24);
    }
    if (((uVar6 != 0) && (local_18._4_4_ != uVar7)) ||
       ((local_20._4_4_ != 0 && (local_24 != uVar7)))) goto switchD_005bfb69_default;
    local_24 = 0;
    if (uVar7 != 0) {
      local_2c = (int)local_c - (int)local_10;
      local_28 = param_2 - (int)local_10;
      pdVar9 = (double *)(local_10 + 2);
      do {
        if (local_c == (undefined4 *)0x0) {
          fVar13 = (float10)0;
        }
        else {
          fVar13 = (float10)*(double *)((int)pdVar9 + local_2c);
        }
        local_18 = (double)fVar13;
        if (local_10 == (undefined4 *)0x0) {
          local_20 = 0.0;
        }
        else {
          local_20 = *pdVar9;
        }
        switch(*(undefined4 *)((int)param_1 + 0x1c)) {
        case 4:
          bVar12 = (byte)((ushort)((ushort)(NAN(fVar13) || NAN((float10)0.0)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar13 == (float10)0.0) << 0xe) >> 8);
          goto LAB_005bfb76;
        case 5:
          fVar13 = -fVar13;
          break;
        case 6:
          break;
        case 7:
          fVar13 = fVar13 * (float10)local_20;
          break;
        case 8:
          if (local_20 == 0.0) {
            FUN_005ba1d9(local_8,(int)param_1 + 0x30,0xbd9,"division by zero");
            fVar13 = (float10)local_18;
          }
          fVar13 = fVar13 / (float10)local_20;
          break;
        case 9:
          if (local_20 == 0.0) {
            FUN_005ba1d9(local_8,(int)param_1 + 0x30,0xbd9,"division by zero");
          }
          fVar13 = (float10)FUN_0067381a();
          break;
        case 10:
          fVar13 = fVar13 + (float10)local_20;
          break;
        case 0xb:
          fVar13 = fVar13 - (float10)local_20;
          break;
        case 0xc:
          bVar11 = (float10)local_20 <= fVar13;
          goto LAB_005bfb7b;
        case 0xd:
          bVar11 = (float10)local_20 < fVar13;
          goto LAB_005bfc2e;
        case 0xe:
          bVar11 = fVar13 < (float10)local_20 == (fVar13 == (float10)local_20);
          goto LAB_005bfb7b;
        case 0xf:
          bVar11 = (float10)local_20 <= fVar13;
LAB_005bfc2e:
          if (!bVar11) goto LAB_005bfb81;
          goto LAB_005bfc76;
        case 0x10:
          bVar12 = (byte)((ushort)((ushort)(NAN(fVar13) || NAN((float10)local_20)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar13 == (float10)local_20) << 0xe) >> 8);
LAB_005bfb76:
          bVar11 = (POPCOUNT(bVar12) & 1U) == 0;
LAB_005bfb7b:
          if (bVar11) {
LAB_005bfb81:
            fVar13 = (float10)0;
          }
          else {
LAB_005bfc76:
            fVar13 = (float10)1;
          }
          break;
        case 0x11:
          bVar12 = (byte)((ushort)((ushort)(NAN(fVar13) || NAN((float10)local_20)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar13 == (float10)local_20) << 0xe) >> 8);
LAB_005bfc6b:
          if ((POPCOUNT(bVar12) & 1U) == 0) goto LAB_005bfc76;
          goto LAB_005bfb81;
        case 0x12:
          if (fVar13 != (float10)0.0) {
LAB_005bfc62:
            bVar12 = (byte)((ushort)((ushort)NAN(local_20) << 10) >> 8) |
                     (byte)((ushort)((ushort)(local_20 == 0.0) << 0xe) >> 8);
            goto LAB_005bfc6b;
          }
          goto LAB_005bfb81;
        case 0x13:
          if (fVar13 == (float10)0.0) goto LAB_005bfc62;
          goto LAB_005bfc76;
        default:
          goto switchD_005bfb69_default;
        }
        local_24 = local_24 + 1;
        *(double *)((int)pdVar9 + local_28) = (double)fVar13;
        pdVar9 = pdVar9 + 2;
      } while (local_24 < uVar7);
    }
    local_2c = 0;
    if (uVar7 != 0) {
      do {
        iVar2 = FUN_005bcf79(param_2,*(undefined8 *)(param_2 + 8),(int)param_1 + 0x30);
        if (iVar2 < 0) goto LAB_005bfcc8;
        local_2c = local_2c + 1;
        param_2 = param_2 + 0x10;
      } while (local_2c < uVar7);
    }
  }
  else if (iVar2 < 2) {
    if (uVar6 == 0) {
      iVar10 = *(int *)((int)param_1 + 0x20);
      if (iVar10 == 0) {
switchD_005bfb69_default:
        iVar2 = -0x7fffbffb;
        goto LAB_005bfcc8;
      }
      if (*(int *)(iVar10 + 4) == 0xd) {
        if (*(int *)(iVar10 + 0x10) == 6) goto switchD_005bfb69_default;
        iVar2 = FUN_005bcdf7(param_2,(int *)(iVar10 + 0x10),(int)param_1 + 0x30);
        if (iVar2 < 0) goto LAB_005bfcc8;
      }
      else {
        if ((iVar10 == 0) || (*(int *)(iVar10 + 4) != 1)) goto switchD_005bfb69_default;
        do {
          iVar2 = *(int *)(iVar10 + 8);
          if (iVar2 != 0) {
            if (*(int *)(iVar2 + 4) == 0xd) {
              if (*(int *)(iVar2 + 0x10) == 6) goto switchD_005bfb69_default;
              iVar2 = FUN_005bcdf7(param_2,(int *)(iVar2 + 0x10),(int)param_1 + 0x30);
              if (iVar2 < 0) goto LAB_005bfcc8;
              param_2 = param_2 + 0x10;
            }
            else if ((iVar2 != 0) && (*(int *)(iVar2 + 4) == 0xc)) {
              iVar2 = FUN_005bf509();
              if (iVar2 < 0) goto LAB_005bfcc8;
              param_2 = param_2 + *(int *)(*(int *)(iVar10 + 8) + 0x18) *
                                  *(int *)(*(int *)(iVar10 + 8) + 0x14) * 0x10;
            }
          }
          iVar10 = *(int *)(iVar10 + 0xc);
        } while (iVar10 != 0);
      }
    }
    else if (local_18._4_4_ == 1) {
      local_24 = 0;
      if (uVar7 != 0) {
        do {
          iVar2 = FUN_005bcdf7(param_2,local_c,(int)param_1 + 0x30);
          if (iVar2 < 0) goto LAB_005bfcc8;
          local_24 = local_24 + 1;
          param_2 = param_2 + 0x10;
        } while (local_24 < uVar7);
      }
    }
    else if (((uVar7 == local_18._4_4_) ||
             (puVar1 = (uint *)((int)param_1 + 0x14), *(uint *)(uVar6 + 0x14) < *puVar1)) ||
            (uVar4 = *(uint *)((int)param_1 + 0x18), *(uint *)(uVar6 + 0x18) < uVar4)) {
      local_24 = 0;
      if (uVar7 != 0) {
        local_20 = (double)CONCAT44((int)param_1 + 0x30,(uint)local_20);
        iVar10 = param_2;
        do {
          iVar2 = FUN_005bcdf7(iVar10,(int)puVar5 + (iVar10 - param_2),local_20._4_4_);
          if (iVar2 < 0) goto LAB_005bfcc8;
          local_24 = local_24 + 1;
          iVar10 = iVar10 + 0x10;
        } while (local_24 < uVar7);
      }
    }
    else {
      param_1 = (undefined4 *)0x0;
      if (*puVar1 != 0) {
        do {
          uVar7 = 0;
          if (uVar4 != 0) {
            do {
              iVar2 = FUN_005bcdf7((uVar4 * (int)param_1 + uVar7) * 0x10 + param_2,
                                   local_c + (*(int *)(local_2c + 0x18) * (int)param_1 + uVar7) * 4,
                                   iVar10 + 0x30);
              if (iVar2 < 0) goto LAB_005bfcc8;
              uVar4 = *(uint *)(iVar10 + 0x18);
              uVar7 = uVar7 + 1;
            } while (uVar7 < uVar4);
          }
          param_1 = (undefined4 *)((int)param_1 + 1);
        } while (param_1 < *(uint *)(iVar10 + 0x14));
      }
    }
  }
  else if (iVar2 == 0x16) {
    iVar10 = (int)param_1 + 0x30;
    local_20 = (double)CONCAT44(iVar10,(uint)local_20);
    iVar2 = FUN_005bcf1c(&local_2c,local_10,iVar10);
    if (iVar2 < 0) goto LAB_005bfcc8;
    if (local_18._4_4_ <= local_2c * uVar7) {
      FUN_005ba1d9(local_8,iVar10,0xbd6,"array index out of bounds");
      goto switchD_005bfb69_default;
    }
    local_24 = 0;
    if (uVar7 != 0) {
      puVar5 = local_c + local_2c * uVar7 * 4;
      do {
        iVar2 = FUN_005bcdf7(param_2,puVar5,local_20._4_4_);
        if (iVar2 < 0) goto LAB_005bfcc8;
        local_24 = local_24 + 1;
        puVar5 = puVar5 + 4;
        param_2 = param_2 + 0x10;
      } while (local_24 < uVar7);
    }
  }
  else if (iVar2 == 0x17) {
    iVar10 = *(int *)((int)param_1 + 0x24);
    if (*(int *)(iVar10 + 4) == 0xd) {
      iVar2 = FUN_005bcf1c(&local_2c,iVar10 + 0x10,(int)param_1 + 0x30);
      if (iVar2 < 0) goto LAB_005bfcc8;
      local_24 = 0;
      if (uVar7 != 0) {
        puVar5 = local_c + local_2c * 4;
        do {
          iVar2 = FUN_005bcdf7(param_2,puVar5,(int)param_1 + 0x30);
          if (iVar2 < 0) goto LAB_005bfcc8;
          local_24 = local_24 + 1;
          param_2 = param_2 + 0x10;
          puVar5 = puVar5 + 4;
        } while (local_24 < uVar7);
      }
    }
    else {
      if (*(int *)(iVar10 + 4) != 1) goto switchD_005bfb69_default;
      local_24 = 0;
      if (uVar7 != 0) {
        do {
          iVar2 = FUN_005bcf1c(&local_2c,*(int *)(iVar10 + 8) + 0x10,(int)param_1 + 0x30);
          if ((iVar2 < 0) ||
             (iVar2 = FUN_005bcdf7(param_2,local_c + local_2c * 4,(int)param_1 + 0x30), iVar2 < 0))
          goto LAB_005bfcc8;
          local_24 = local_24 + 1;
          param_2 = param_2 + 0x10;
          iVar10 = *(int *)(iVar10 + 0xc);
        } while (local_24 < uVar7);
      }
    }
  }
  else {
    if (iVar2 != 0x18) goto LAB_005bfa79;
    local_24 = 0;
    if (local_18._4_4_ != 0) {
      iVar10 = (int)param_1 + 0x30;
      param_1 = local_10 + uVar7 * 4;
      local_2c = (int)local_c - (int)local_10;
      local_28 = param_2 - (int)local_10;
      puVar5 = local_10;
      do {
        iVar2 = FUN_005bb002(&local_20,local_2c + (int)puVar5,iVar10);
        if (iVar2 < 0) goto LAB_005bfcc8;
        puVar3 = puVar5;
        if (local_20 == 0.0) {
          puVar3 = param_1;
        }
        iVar2 = FUN_005bcdf7(local_28 + (int)puVar5,puVar3,iVar10);
        if (iVar2 < 0) goto LAB_005bfcc8;
        local_24 = local_24 + 1;
        param_1 = param_1 + 4;
        puVar5 = puVar5 + 4;
      } while (local_24 < local_18._4_4_);
    }
  }
  iVar2 = 0;
LAB_005bfcc8:
  _free(local_10);
  _free(local_c);
  return iVar2;
}


// ==== 0x5bfd33 FUN_005bfd33

int __thiscall FUN_005bfd33(undefined4 param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  undefined1 local_1c [16];
  double local_c;
  
  if (param_2 == (int *)0x0) {
    return 0;
  }
  if ((param_2[6] * param_2[5] != 1) || (iVar1 = FUN_005ba799(param_2[4]), iVar1 == 0)) {
    FUN_005ba1d9(param_1,param_2 + 0xc,0xbcb,"float expected");
    return 0;
  }
  iVar1 = FUN_005bb0d5(param_2);
  if (((iVar1 != 0) && (iVar1 = FUN_005bf509(param_2,local_1c), -1 < iVar1)) &&
     (iVar1 = FUN_005bb002(&local_c,local_1c,param_2 + 0xc), -1 < iVar1)) {
    if (local_c == 0.0) {
      param_3 = param_4;
    }
    iVar1 = FUN_005d7885(param_3);
    return iVar1;
  }
  pvVar2 = _malloc(0x28);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_005d8670();
  }
  if (puVar3 == (undefined4 *)0x0) {
    return 0;
  }
  puVar3[4] = 2;
  iVar1 = (**(code **)(*param_2 + 8))();
  puVar3[6] = iVar1;
  if (iVar1 != 0) {
    if (param_3 != (int *)0x0) {
      iVar1 = (**(code **)(*param_3 + 8))();
      puVar3[8] = iVar1;
      if (iVar1 == 0) goto LAB_005bfe33;
    }
    if (param_4 != (int *)0x0) {
      iVar1 = (**(code **)(*param_4 + 8))();
      puVar3[9] = iVar1;
      if (iVar1 == 0) goto LAB_005bfe33;
    }
    pvVar2 = _malloc(0x14);
    if (pvVar2 == (void *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_005d78db(puVar3,0,"Stmts");
    }
    if (iVar1 != 0) {
      return iVar1;
    }
  }
LAB_005bfe33:
  (**(code **)*puVar3)(1);
  return 0;
}


// ==== 0x5bfe5c FUN_005bfe5c

int __fastcall FUN_005bfe5c(int param_1)

{
  undefined4 *puVar1;
  char cVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  
  puVar1 = (undefined4 *)(param_1 + 0x20);
  iVar5 = FUN_005c7bd2(puVar1);
  if (-1 < iVar5) {
    iVar5 = 0xd;
    do {
      switch(*puVar1) {
      case 0:
        goto LAB_005bfe9a;
      case 1:
        cVar2 = *(char *)(param_1 + 0x29);
        if (cVar2 == '\0') {
          return (int)*(char *)(param_1 + 0x28);
        }
        if (*(char *)(param_1 + 0x2a) != '\0') {
          return 0x14e;
        }
        if (cVar2 != '=') {
          cVar3 = *(char *)(param_1 + 0x28);
          if (cVar3 != cVar2) {
            return 0x14e;
          }
          if (cVar3 == '&') {
            return 0x13d;
          }
          if (cVar3 == '+') {
            return 0x137;
          }
          if (cVar3 != '-') {
            if (cVar3 != '|') {
              return 0x14e;
            }
            return 0x13e;
          }
          return 0x138;
        }
        cVar2 = *(char *)(param_1 + 0x28);
        if (cVar2 < '.') {
          if (cVar2 == '-') {
            return 0x143;
          }
          if (cVar2 == '!') {
            return 0x13c;
          }
          if (cVar2 == '%') {
            return 0x141;
          }
          if (cVar2 != '*') {
            if (cVar2 != '+') {
              return 0x14e;
            }
            return 0x142;
          }
          return 0x13f;
        }
        if (cVar2 == '/') {
          return 0x140;
        }
        if (cVar2 == '<') {
          return 0x139;
        }
        if (cVar2 == '=') {
          return 0x13b;
        }
        if (cVar2 != '>') {
          return 0x14e;
        }
        return 0x13a;
      case 2:
        return 0x144;
      case 3:
        return 0x145;
      case 4:
        return 0x146;
      case 5:
        return 0x147;
      case 6:
        return 0x148;
      case 7:
        return 0x149;
      case 8:
        return 0x14a;
      case 9:
        pcVar4 = *(char **)(param_1 + 0x28);
        switch((int)*pcVar4) {
        case 0x61:
          iVar6 = 5;
          bVar9 = true;
          pcVar8 = pcVar4;
          pcVar7 = "auto";
          goto code_r0x005bffef;
        case 0x62:
          iVar5 = 5;
          bVar9 = true;
          pcVar8 = pcVar4;
          pcVar7 = "bool";
          goto code_r0x005c001c;
        case 99:
          iVar6 = 5;
          bVar9 = true;
          pcVar8 = pcVar4;
          pcVar7 = "case";
          goto code_r0x005c0099;
        case 100:
          iVar5 = 8;
          bVar9 = true;
          pcVar8 = pcVar4;
          pcVar7 = "default";
          goto code_r0x005c016e;
        case 0x65:
          iVar5 = 5;
          bVar9 = true;
          pcVar8 = pcVar4;
          pcVar7 = "else";
          goto code_r0x005c01d7;
        case 0x66:
          iVar5 = 6;
          bVar9 = true;
          pcVar8 = pcVar4;
          pcVar7 = "false";
          goto code_r0x005c0237;
        case 0x67:
          pcVar8 = &DAT_0069f7cc;
          break;
        case 0x68:
          iVar5 = 5;
          bVar9 = true;
          pcVar8 = pcVar4;
          pcVar7 = "half";
          goto code_r0x005c029b;
        case 0x69:
          iVar5 = 3;
          bVar9 = true;
          pcVar8 = pcVar4;
          pcVar7 = "if";
          goto code_r0x005c02b9;
        default:
          goto switchD_005bffdc_caseD_6a;
        case 0x6c:
          pcVar8 = &DAT_0069f7ac;
          break;
        case 0x6d:
          iVar5 = 7;
          bVar9 = true;
          pcVar8 = pcVar4;
          pcVar7 = "matrix";
          goto code_r0x005c034b;
        case 0x6e:
          iVar5 = 10;
          bVar9 = true;
          pcVar8 = pcVar4;
          pcVar7 = "namespace";
          goto code_r0x005c0371;
        case 0x6f:
          iVar5 = 4;
          bVar9 = true;
          pcVar8 = pcVar4;
          pcVar7 = "out";
          goto code_r0x005c0391;
        case 0x70:
          iVar5 = 0xe;
          bVar9 = true;
          pcVar8 = pcVar4;
          pcVar7 = "pixelfragment";
          goto code_r0x005c03b7;
        case 0x72:
          iVar5 = 9;
          bVar9 = true;
          pcVar8 = pcVar4;
          pcVar7 = "register";
          goto code_r0x005c0434;
        case 0x73:
          iVar5 = 10;
          bVar9 = true;
          pcVar8 = pcVar4;
          pcVar7 = "sampler1D";
          goto code_r0x005c049a;
        case 0x74:
          iVar5 = 9;
          bVar9 = true;
          pcVar8 = pcVar4;
          pcVar7 = "template";
          goto code_r0x005c060b;
        case 0x75:
          iVar5 = 8;
          bVar9 = true;
          pcVar8 = pcVar4;
          pcVar7 = "uniform";
          goto code_r0x005c0732;
        case 0x76:
          iVar6 = 7;
          bVar9 = true;
          pcVar8 = pcVar4;
          pcVar7 = "vector";
          goto code_r0x005c0776;
        case 0x77:
          iVar5 = 6;
          bVar9 = true;
          pcVar8 = pcVar4;
          pcVar7 = "while";
          goto code_r0x005c081f;
        }
        iVar5 = 5;
        goto LAB_005c0031;
      case 10:
        return 0x14b;
      case 0xd:
        goto LAB_005bfe9a;
      }
      iVar6 = FUN_005c7bd2(puVar1);
    } while (-1 < iVar6);
  }
  *(undefined4 *)(param_1 + 0x40) = 1;
LAB_005bfe9a:
  return -1;
  while( true ) {
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    if (!bVar9) break;
code_r0x005c081f:
    if (iVar5 == 0) break;
  }
  if (bVar9) {
    return 0x136;
  }
  goto switchD_005bffdc_caseD_6a;
  while( true ) {
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    if (!bVar9) break;
code_r0x005c0776:
    if (iVar6 == 0) break;
  }
  if (bVar9) {
    return 0x131;
  }
  iVar6 = 0xf;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "vertexfragment";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x132;
  }
  iVar6 = 8;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "virtual";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  iVar6 = 5;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "void";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x134;
  }
  iVar6 = 9;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "volatile";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x135;
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    bVar9 = true;
    pcVar8 = pcVar4;
    pcVar7 = "vertexshader";
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar9 = *pcVar8 == *pcVar7;
      pcVar8 = pcVar8 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar9);
    if (bVar9) {
      return 0x133;
    }
  }
  goto switchD_005bffdc_caseD_6a;
  while( true ) {
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    if (!bVar9) break;
code_r0x005c0732:
    if (iVar5 == 0) break;
  }
  if (bVar9) {
    return 0x130;
  }
  iVar5 = 6;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "union";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  iVar5 = 9;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "unsigned";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  pcVar8 = "using";
  goto LAB_005c002f;
  while( true ) {
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    if (!bVar9) break;
code_r0x005c060b:
    if (iVar5 == 0) break;
  }
  if (bVar9) {
    return 0x14e;
  }
  iVar5 = 10;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "texture1D";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x12a;
  }
  iVar5 = 10;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "texture2D";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 299;
  }
  iVar5 = 10;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "texture3D";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 300;
  }
  iVar5 = 0xc;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "textureCUBE";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x12d;
  }
  iVar5 = 5;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "this";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  iVar5 = 6;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "throw";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  iVar5 = 5;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "true";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x12e;
  }
  iVar5 = 4;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "try";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  iVar5 = 8;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "typedef";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x12f;
  }
  iVar5 = 9;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "typename";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    iVar5 = 8;
    bVar9 = true;
    pcVar8 = pcVar4;
    pcVar7 = "texture";
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar9 = *pcVar8 == *pcVar7;
      pcVar8 = pcVar8 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar9);
    if (bVar9) {
      return 0x129;
    }
  }
  goto switchD_005bffdc_caseD_6a;
  while( true ) {
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    if (!bVar9) break;
code_r0x005c049a:
    if (iVar5 == 0) break;
  }
  if (bVar9) {
    return 0x11f;
  }
  iVar5 = 10;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "sampler2D";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x120;
  }
  iVar5 = 10;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "sampler3D";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x121;
  }
  iVar5 = 0xc;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "samplerCUBE";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x122;
  }
  iVar5 = 0xe;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "sampler_state";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x123;
  }
  iVar5 = 7;
  bVar9 = true;
  iVar6 = iVar5;
  pcVar8 = pcVar4;
  pcVar7 = "shared";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x124;
  }
  iVar6 = 6;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "short";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  bVar9 = true;
  iVar6 = iVar5;
  pcVar8 = pcVar4;
  pcVar7 = "signed";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  bVar9 = true;
  iVar6 = iVar5;
  pcVar8 = pcVar4;
  pcVar7 = "sizeof";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  bVar9 = true;
  iVar6 = iVar5;
  pcVar8 = pcVar4;
  pcVar7 = "static";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x125;
  }
  iVar6 = 0xc;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "static_cast";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  bVar9 = true;
  iVar6 = iVar5;
  pcVar8 = pcVar4;
  pcVar7 = "string";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x126;
  }
  bVar9 = true;
  iVar6 = iVar5;
  pcVar8 = pcVar4;
  pcVar7 = "struct";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x127;
  }
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "switch";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    iVar5 = 8;
    bVar9 = true;
    pcVar8 = pcVar4;
    pcVar7 = "sampler";
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar9 = *pcVar8 == *pcVar7;
      pcVar8 = pcVar8 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar9);
    if (bVar9) {
      return 0x11e;
    }
  }
  goto switchD_005bffdc_caseD_6a;
  while( true ) {
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    if (!bVar9) break;
code_r0x005c0434:
    if (iVar5 == 0) break;
  }
  if (bVar9) {
    return 0x11b;
  }
  iVar5 = 0x11;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "reinterpret_cast";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  iVar5 = 10;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "row_major";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x11d;
  }
  iVar5 = 7;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "return";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x11c;
  }
  goto switchD_005bffdc_caseD_6a;
  while( true ) {
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    if (!bVar9) break;
code_r0x005c03b7:
    if (iVar5 == 0) break;
  }
  if (bVar9) {
    return 0x119;
  }
  iVar5 = 8;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "private";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  iVar5 = 10;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "protected";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  iVar5 = 7;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "public";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    iVar5 = 0xc;
    bVar9 = true;
    pcVar8 = pcVar4;
    pcVar7 = "pixelshader";
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar9 = *pcVar8 == *pcVar7;
      pcVar8 = pcVar8 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar9);
    if (bVar9) {
      return 0x11a;
    }
  }
  goto switchD_005bffdc_caseD_6a;
  while( true ) {
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    if (!bVar9) break;
code_r0x005c0391:
    if (iVar5 == 0) break;
  }
  if (bVar9) {
    return 0x117;
  }
  pcVar8 = "operator";
  goto LAB_005c03a4;
  while( true ) {
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    if (!bVar9) break;
code_r0x005c0371:
    if (iVar5 == 0) break;
  }
  if (bVar9) {
    return 0x14e;
  }
  iVar5 = 4;
  pcVar8 = (char *)&PTR_DAT_0069f794;
  goto LAB_005c0031;
  while( true ) {
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    if (!bVar9) break;
code_r0x005c034b:
    if (iVar5 == 0) break;
  }
  if (bVar9) {
    return 0x116;
  }
  pcVar8 = "mutable";
  iVar5 = 8;
  goto LAB_005c0031;
  while( true ) {
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    if (!bVar9) break;
code_r0x005c02b9:
    if (iVar5 == 0) break;
  }
  if (bVar9) {
    return 0x111;
  }
  iVar5 = 3;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "in";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x112;
  }
  iVar5 = 7;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "inline";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x113;
  }
  iVar5 = 6;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "inout";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x114;
  }
  iVar5 = 4;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "int";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x115;
  }
  goto switchD_005bffdc_caseD_6a;
  while( true ) {
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    if (!bVar9) break;
code_r0x005c029b:
    if (iVar5 == 0) break;
  }
  if (bVar9) {
    return 0x110;
  }
  goto switchD_005bffdc_caseD_6a;
  while( true ) {
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    if (!bVar9) break;
code_r0x005c0237:
    if (iVar5 == 0) break;
  }
  if (bVar9) {
    return 0x10d;
  }
  iVar5 = 6;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "float";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x10e;
  }
  iVar5 = 4;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "for";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x10f;
  }
  pcVar8 = "friend";
  iVar5 = 7;
  goto LAB_005c0031;
  while( true ) {
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    if (!bVar9) break;
code_r0x005c01d7:
    if (iVar5 == 0) break;
  }
  if (bVar9) {
    return 0x10b;
  }
  iVar5 = 5;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "enum";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  iVar5 = 9;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "explicit";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  iVar5 = 7;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "extern";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x10c;
  }
  goto switchD_005bffdc_caseD_6a;
  while( true ) {
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    if (!bVar9) break;
code_r0x005c016e:
    if (iVar5 == 0) break;
  }
  if (bVar9) {
    return 0x14e;
  }
  iVar5 = 7;
  bVar9 = true;
  iVar6 = iVar5;
  pcVar8 = pcVar4;
  pcVar7 = "delete";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  iVar6 = 3;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "do";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x10a;
  }
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "double";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x109;
  }
  pcVar8 = "dynamic_cast";
  iVar5 = 0xd;
  goto LAB_005c0031;
  while( true ) {
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    if (!bVar9) break;
code_r0x005c0099:
    if (iVar6 == 0) break;
  }
  if (bVar9) {
    return 0x14e;
  }
  iVar6 = 6;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "catch";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  iVar6 = 5;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "char";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  iVar6 = 6;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "class";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "column_major";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x104;
  }
  iVar5 = 8;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "compile";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x105;
  }
  iVar5 = 0x11;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "compile_fragment";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x106;
  }
  iVar5 = 6;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "const";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x107;
  }
  iVar5 = 0xb;
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "const_cast";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  pcVar8 = "continue";
LAB_005c03a4:
  iVar5 = 9;
  goto LAB_005c0031;
  while( true ) {
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    if (!bVar9) break;
code_r0x005c001c:
    if (iVar5 == 0) break;
  }
  if (bVar9) {
    return 0x103;
  }
  pcVar8 = "break";
LAB_005c002f:
  iVar5 = 6;
LAB_005c0031:
  bVar9 = true;
  pcVar7 = pcVar4;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar7 == *pcVar8;
    pcVar7 = pcVar7 + 1;
    pcVar8 = (char *)((int)pcVar8 + 1);
  } while (bVar9);
  if (bVar9) {
    return 0x14e;
  }
  goto switchD_005bffdc_caseD_6a;
  while( true ) {
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    if (!bVar9) break;
code_r0x005bffef:
    if (iVar6 == 0) break;
  }
  if (bVar9) {
LAB_005bfe9a:
    return 0x14e;
  }
  bVar9 = true;
  pcVar8 = pcVar4;
  pcVar7 = "asm_fragment";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar8 == *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar9);
  if (bVar9) {
    return 0x102;
  }
switchD_005bffdc_caseD_6a:
  iVar5 = _tolower((int)*pcVar4);
  if (iVar5 == 0x61) {
    iVar5 = __stricmp(*(char **)(param_1 + 0x28),(char *)&PTR_DAT_0069f660);
    if (iVar5 == 0) {
      return 0x101;
    }
  }
  else if (iVar5 == 100) {
    iVar5 = __stricmp(*(char **)(param_1 + 0x28),"decl");
    if (iVar5 == 0) {
      return 0x108;
    }
  }
  else if (iVar5 == 0x70) {
    iVar5 = __stricmp(*(char **)(param_1 + 0x28),"pass");
    if (iVar5 == 0) {
      return 0x118;
    }
  }
  else if ((iVar5 == 0x74) &&
          (iVar5 = __stricmp(*(char **)(param_1 + 0x28),"technique"), iVar5 == 0)) {
    return 0x128;
  }
  iVar5 = FUN_005be628(0,param_1 + 0x20,0,0,*(undefined4 *)(param_1 + 0xc),0,0,0);
  return (iVar5 != 0) + 0x14c;
}


// ==== 0x5c094c FUN_005c094c

undefined4 * __thiscall FUN_005c094c(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  char *pcVar9;
  undefined1 local_58 [16];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_2c;
  int local_1c;
  int local_18;
  undefined4 *local_14;
  int local_10;
  int local_c;
  undefined4 *local_8;
  
  local_14 = (undefined4 *)0x0;
  iVar1 = FUN_005ba5e2();
  local_1c = iVar1;
  FUN_005d844d();
  if ((iVar1 != 0) && (param_2 != 0)) {
    local_18 = *(int *)(iVar1 + 0x18);
    iVar6 = param_2 + 0x10;
    local_10 = iVar6;
    if ((*(byte *)(iVar1 + 0x10) & 0x40) != 0) {
      FUN_005ba1d9(param_1,iVar6,0xbe7,"\'%s\': functions cannot be declared \'uniform\'",
                   *(undefined4 *)(param_2 + 0x18));
    }
    if ((*(byte *)(iVar1 + 0x10) & 1) != 0) {
      FUN_005ba1d9(param_1,iVar6,0xbbe,"\'%s\': functions cannot be declared \'extern\'",
                   *(undefined4 *)(param_2 + 0x18));
    }
    iVar1 = FUN_005ba799(local_18);
    if (iVar1 == 0) {
      FUN_005ba1d9(param_1,iVar6,0xbde,"\'%s\': function return value must be numeric",
                   *(undefined4 *)(param_2 + 0x18));
    }
    local_c = 0;
    for (iVar1 = param_3; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
      iVar3 = *(int *)(iVar1 + 8);
      if ((iVar3 != 0) && (*(int *)(iVar3 + 4) == 5)) {
        iVar4 = *(int *)(iVar1 + 0xc);
        if ((iVar4 == 0) || (*(int *)(*(int *)(iVar4 + 8) + 4) != 0xb)) {
          if (local_c != 0) {
            FUN_005ba1d9(param_1,iVar6,0xbe4,"\'%s\': missing default value for parameter \'%s\'",
                         *(undefined4 *)(param_2 + 0x18),
                         *(undefined4 *)(*(int *)(iVar3 + 0x14) + 0x18));
          }
        }
        else {
          local_c = 1;
          iVar1 = iVar4;
        }
      }
    }
    pvVar2 = _malloc(0x14);
    if (pvVar2 == (void *)0x0) {
      local_8 = (undefined4 *)0x0;
    }
    else {
      local_8 = (undefined4 *)FUN_005d78db(0,0,"Stmts");
    }
    if (local_8 != (undefined4 *)0x0) {
      pvVar2 = _malloc(0x30);
      iVar1 = 0;
      if (pvVar2 == (void *)0x0) {
        local_c = 0;
      }
      else {
        local_c = FUN_005d7db0(2,0,0,0);
      }
      iVar6 = local_c;
      if (local_c != 0) {
        local_8[2] = local_c;
        iVar3 = FUN_005d7885(param_2);
        *(int *)(iVar6 + 0x14) = iVar3;
        if (iVar3 != 0) {
          pvVar2 = _malloc(0x40);
          if (pvVar2 != (void *)0x0) {
            iVar1 = FUN_005d8213();
          }
          if (iVar1 != 0) {
            *(int *)(iVar6 + 0x18) = iVar1;
            *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(local_1c + 0x10);
            if (*(int *)(local_1c + 0x14) != 0) {
              iVar6 = FUN_005d7885(*(int *)(local_1c + 0x14));
              *(int *)(iVar1 + 0x1c) = iVar6;
              if (iVar6 == 0) goto LAB_005c0c0d;
            }
            if (local_18 != 0) {
              iVar6 = FUN_005d7885(local_18);
              *(int *)(iVar1 + 0x20) = iVar6;
              if (iVar6 == 0) goto LAB_005c0c0d;
            }
            FUN_005ba5ee(*(undefined4 *)(iVar1 + 0x20),1);
            if (param_4 != 0) {
              if (*(int *)(iVar1 + 0x20) == 0) {
                FUN_005ba1d9(param_1,local_10,0xc04,"\'%s\': void function cannot have a semantic",
                             *(undefined4 *)(local_10 + 8));
                param_4 = 0;
              }
              if (param_4 != 0) {
                iVar6 = FUN_005d7885(param_4);
                *(int *)(iVar1 + 0x34) = iVar6;
                if (iVar6 == 0) goto LAB_005c0c0d;
                do {
                  iVar3 = param_4;
                  iVar6 = *(int *)(param_4 + 8);
                  if ((iVar6 != 0) && (*(int *)(iVar6 + 4) == 2)) {
                    iVar6 = FUN_005d7885(iVar6);
                    *(int *)(iVar1 + 0x30) = iVar6;
                    if (iVar6 == 0) goto LAB_005c0c0d;
                  }
                  param_4 = *(int *)(iVar3 + 0xc);
                } while (param_4 != 0);
              }
            }
            if ((param_3 != 0) && (*(int *)(param_3 + 8) != 0)) {
              iVar6 = FUN_005d7885(param_3);
              *(int *)(iVar1 + 0x24) = iVar6;
              if (iVar6 == 0) goto LAB_005c0c0d;
            }
            iVar3 = local_10;
            iVar4 = FUN_005be628(2,local_10,*(undefined4 *)(iVar1 + 0x1c),
                                 *(undefined4 *)(iVar1 + 0x24),
                                 *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x1c),10,&param_3,
                                 &local_14);
            iVar6 = param_3;
            if (-1 < iVar4) {
              if (iVar4 == 0) {
                iVar3 = FUN_005ba894(*(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(param_3 + 0x20));
                if (iVar3 == 0) {
                  uVar5 = *(undefined4 *)(local_10 + 8);
                  pcVar9 = "\'%s\': function return value differs from prototype";
                  uVar8 = 0xbfc;
                  iVar3 = local_10;
                  goto LAB_005c0c04;
                }
                *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar6 + 0x10);
                *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar6 + 0x14);
                *(undefined4 *)(local_c + 0x24) = *(undefined4 *)(local_14[2] + 0x18);
              }
              else {
                *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(param_1 + 0x58);
                iVar3 = FUN_005ba80b(*(undefined4 *)(iVar1 + 0x20));
                *(int *)(iVar1 + 0x14) = iVar3;
                *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + iVar3;
              }
              local_48 = *(undefined4 *)(iVar1 + 0x10);
              local_44 = *(undefined4 *)(iVar1 + 0x14);
              local_3c = 0;
              local_40 = 3;
              local_38 = FUN_005d7885(*(undefined4 *)(iVar1 + 0x20));
              local_2c = FUN_005d7885(param_4);
              FUN_005ba5ee(local_38,0);
              uVar5 = FUN_005bedc7(param_2,local_58);
              *(undefined4 *)(iVar1 + 0x2c) = uVar5;
              if (iVar6 == 0) {
                iVar6 = *(int *)(param_1 + 0xc);
                *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar6 + 0x1c);
                iVar3 = FUN_005ba3df(local_c,0);
                *(int *)(param_1 + 0xc) = iVar6;
                if (iVar3 < 0) goto LAB_005c0c0d;
                *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
              }
              *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14) = *(undefined4 *)(local_10 + 8);
              *(int *)(param_1 + 0x14) = iVar1;
              puVar7 = local_8;
              if (local_14 != (undefined4 *)0x0) {
                (**(code **)*local_14)(1);
                puVar7 = local_8;
              }
              goto LAB_005c0c25;
            }
            uVar5 = *(undefined4 *)(iVar3 + 8);
            pcVar9 = "redefinition of \'%s\'";
            uVar8 = 0xbbb;
LAB_005c0c04:
            FUN_005ba1d9(param_1,iVar3,uVar8,pcVar9,uVar5);
          }
        }
      }
LAB_005c0c0d:
      (**(code **)*local_8)(1);
      if (local_14 != (undefined4 *)0x0) {
        (**(code **)*local_14)(1);
      }
    }
  }
  puVar7 = (undefined4 *)0x0;
LAB_005c0c25:
  FUN_005d8486();
  return puVar7;
}


// ==== 0x5c0cfc FUN_005c0cfc

undefined4 * FUN_005c0cfc(void *param_1)

{
  int iVar1;
  uint uVar2;
  void *_Memory;
  int iVar3;
  void *pvVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint local_8;
  
  iVar1 = (int)param_1;
  if ((param_1 == (void *)0x0) || (*(int *)((int)param_1 + 4) != 0xc)) {
    return (undefined4 *)0x0;
  }
  uVar2 = *(int *)((int)param_1 + 0x18) * *(int *)((int)param_1 + 0x14);
  _Memory = _malloc(uVar2 * 0x10);
  if ((_Memory != (void *)0x0) && (iVar3 = FUN_005bf509(param_1,_Memory), -1 < iVar3)) {
    pvVar4 = _malloc(0x50);
    if (pvVar4 == (void *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5 = (undefined4 *)FUN_005d8831(0,0,0,0,1,(int)param_1 + 0x30);
    }
    if (puVar5 != (undefined4 *)0x0) {
      if (*(int **)((int)param_1 + 0x10) != (int *)0x0) {
        iVar3 = (**(code **)(**(int **)((int)param_1 + 0x10) + 8))();
        puVar5[4] = iVar3;
        if (iVar3 == 0) {
LAB_005c0e0d:
          (**(code **)*puVar5)(1);
          goto LAB_005c0e15;
        }
      }
      local_8 = 0;
      piVar6 = puVar5 + 8;
      param_1 = _Memory;
      if (uVar2 != 0) {
        do {
          pvVar4 = _malloc(0x14);
          if (pvVar4 == (void *)0x0) {
            iVar3 = 0;
          }
          else {
            iVar3 = FUN_005d78db(0,0,"Value");
          }
          *piVar6 = iVar3;
          if (iVar3 == 0) goto LAB_005c0e0d;
          pvVar4 = _malloc(0x40);
          if (pvVar4 == (void *)0x0) {
            iVar3 = 0;
          }
          else {
            iVar3 = FUN_005d8a02(param_1,iVar1 + 0x30);
          }
          *(int *)(*piVar6 + 8) = iVar3;
          if (iVar3 == 0) goto LAB_005c0e0d;
          piVar6 = (int *)(*piVar6 + 0xc);
          local_8 = local_8 + 1;
          param_1 = (void *)((int)param_1 + 0x10);
        } while (local_8 < uVar2);
      }
      FUN_005bb1eb(puVar5);
      goto LAB_005c0e17;
    }
  }
LAB_005c0e15:
  puVar5 = (undefined4 *)0x0;
LAB_005c0e17:
  _free(_Memory);
  return puVar5;
}


// ==== 0x5c0e2d FUN_005c0e2d

int FUN_005c0e2d(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_005c0cfc(param_1);
  if (((puVar1 != (undefined4 *)0x0) && (iVar2 = puVar1[4], iVar2 != 0)) &&
     (*(int *)(iVar2 + 4) == 8)) {
    iVar2 = FUN_005ba77a(iVar2);
    if (iVar2 != 0) {
      iVar2 = FUN_005bcf1c(param_2,*(int *)(puVar1[8] + 8) + 0x10,puVar1 + 0xc);
      if (-1 < iVar2) {
        iVar2 = 0;
      }
      goto LAB_005c0e81;
    }
  }
  iVar2 = -0x7fffbffb;
LAB_005c0e81:
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
  }
  return iVar2;
}


// ==== 0x5c0e94 FUN_005c0e94

undefined4 * __thiscall FUN_005c0e94(undefined4 param_1,int param_2,int param_3)

{
  int *piVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 **ppuVar7;
  undefined4 uVar8;
  char *pcVar9;
  undefined4 uVar10;
  undefined4 *local_14;
  int local_10;
  uint local_c;
  undefined4 local_8;
  
  local_14 = (undefined4 *)0x0;
  ppuVar7 = &local_14;
  local_8 = param_1;
  if (param_3 == 0) {
LAB_005c104e:
    local_14 = (undefined4 *)0x0;
  }
  else {
    do {
      if (*(int *)(param_3 + 8) == 0) {
LAB_005c1041:
        if (local_14 != (undefined4 *)0x0) {
          (**(code **)*local_14)(1);
        }
        goto LAB_005c104e;
      }
      pvVar2 = _malloc(0x14);
      if (pvVar2 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = (undefined4 *)FUN_005d78db(0,0,"Stmts");
      }
      *ppuVar7 = puVar3;
      if (puVar3 == (undefined4 *)0x0) goto LAB_005c1041;
      pvVar2 = _malloc(0x30);
      if (pvVar2 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_005d7db0(0,0,0,0);
      }
      if (iVar4 == 0) goto LAB_005c1041;
      (*ppuVar7)[2] = iVar4;
      ppuVar7 = (undefined4 **)(*ppuVar7 + 3);
      local_c = 1;
      local_10 = 0;
      if (param_2 != 0) {
        iVar5 = FUN_005d7885(param_2);
        *(int *)(iVar4 + 0x18) = iVar5;
        if (iVar5 == 0) goto LAB_005c1041;
      }
      for (iVar5 = *(int *)(param_3 + 8); *(int *)(iVar5 + 4) != 2; iVar5 = *(int *)(iVar5 + 8)) {
        pvVar2 = _malloc(0x18);
        if (pvVar2 == (void *)0x0) {
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_005d8044();
        }
        if (iVar6 == 0) goto LAB_005c1041;
        *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar4 + 0x18);
        *(int *)(iVar4 + 0x18) = iVar6;
        piVar1 = (int *)(iVar6 + 0x14);
        if (*(int *)(iVar5 + 0xc) == 0) {
          local_10 = 0xc00;
LAB_005c0f96:
          *piVar1 = 1;
        }
        else {
          iVar6 = FUN_005c0e2d(*(int *)(iVar5 + 0xc),piVar1);
          if (iVar6 < 0) {
            local_10 = 0xbf2;
            goto LAB_005c0f96;
          }
        }
        local_c = *piVar1 * local_c;
      }
      iVar6 = FUN_005d7885(iVar5);
      *(int *)(iVar4 + 0x14) = iVar6;
      if (iVar6 == 0) goto LAB_005c1041;
      if (local_10 == 0xbf2) {
        uVar10 = *(undefined4 *)(iVar5 + 0x18);
        pcVar9 = "\'%s\': array dimensions must be literal scalar expressions";
        uVar8 = 0xbf2;
LAB_005c1035:
        FUN_005ba1d9(local_8,iVar5 + 0x10,uVar8,pcVar9,uVar10);
        goto LAB_005c1041;
      }
      if (local_10 == 0xc00) {
        uVar10 = *(undefined4 *)(iVar5 + 0x18);
        pcVar9 = "\'%s\': array dimensions of type must be explicit";
        uVar8 = 0xc00;
        goto LAB_005c1035;
      }
      if ((local_c == 0) || (0x10000 < local_c)) {
        uVar10 = *(undefined4 *)(iVar5 + 0x18);
        pcVar9 = "\'%s\': array dimension must be between 1 and 65536";
        uVar8 = 0xbf3;
        goto LAB_005c1035;
      }
      iVar4 = FUN_005ba3df(iVar4,1);
      if (iVar4 < 0) goto LAB_005c1041;
      param_3 = *(int *)(param_3 + 0xc);
    } while (param_3 != 0);
  }
  return local_14;
}


