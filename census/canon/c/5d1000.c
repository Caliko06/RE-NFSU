// ==== 0x5d14b1 FUN_005d14b1

void __fastcall FUN_005d14b1(int param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 0x28) != 0) {
    FUN_005d0387(1);
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    FUN_005d03d2(3);
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if (*(void **)(param_1 + 0x38) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x38));
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x80);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(int *)(param_1 + 0x80) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x84);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(int *)(param_1 + 0x84) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x88);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(int *)(param_1 + 0x88) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x8c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(int *)(param_1 + 0x8c) = 0;
  }
  FUN_005cd1d4();
  return;
}


// ==== 0x5d1545 FUN_005d1545

undefined4 * __thiscall FUN_005d1545(undefined4 *param_1,byte param_2)

{
  undefined4 *_Memory;
  
  if ((param_2 & 2) == 0) {
    FUN_005d14b1();
    _Memory = param_1;
    if ((param_2 & 1) != 0) {
      _free(param_1);
    }
  }
  else {
    _Memory = param_1 + -1;
    FUN_005b5e6c(param_1,0xac,*_Memory,FUN_005d14b1);
    if ((param_2 & 1) != 0) {
      _free(_Memory);
    }
  }
  return _Memory;
}


// ==== 0x5d1593 FUN_005d1593

int FUN_005d1593(int param_1,int *param_2,uint *param_3)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  void *pvVar8;
  int *piVar9;
  undefined4 *puVar10;
  uint uVar11;
  int iVar12;
  int local_18;
  uint local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  int local_8;
  
  puVar5 = param_3;
  iVar4 = param_1;
  local_10 = (undefined4 *)0x0;
  local_c = (undefined4 *)0x0;
  if ((param_2 != (int *)0x0) &&
     (uVar6 = (**(code **)(*param_2 + 0x10))(param_2), *param_3 + 1 <= uVar6)) {
    iVar7 = (**(code **)(*param_2 + 0xc))(param_2);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar7 + *param_3 * 4);
  }
  *param_3 = *param_3 + 1;
  if ((param_2 != (int *)0x0) &&
     (uVar6 = (**(code **)(*param_2 + 0x10))(param_2), *param_3 + 1 <= uVar6)) {
    iVar7 = (**(code **)(*param_2 + 0xc))(param_2);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(iVar7 + *param_3 * 4);
  }
  *param_3 = *param_3 + 1;
  if ((param_2 != (int *)0x0) &&
     (uVar6 = (**(code **)(*param_2 + 0x10))(param_2), *param_3 + 1 <= uVar6)) {
    iVar7 = (**(code **)(*param_2 + 0xc))(param_2);
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(iVar7 + *param_3 * 4);
  }
  *param_3 = *param_3 + 1;
  if ((param_2 != (int *)0x0) && (uVar6 = (**(code **)(*param_2 + 0x10))(param_2), uVar6 < *param_3)
     ) {
    return -0x7fffbffb;
  }
  iVar7 = FUN_005c90b3(*(undefined4 *)(param_1 + 0x20));
  if (iVar7 < 0) {
    return iVar7;
  }
  local_18 = 0;
  param_3 = (uint *)0x0;
  if (*(int *)(param_1 + 0x24) != 0) {
    do {
      pvVar8 = _malloc(0x44);
      if (pvVar8 == (void *)0x0) {
        local_8 = 0;
      }
      else {
        local_8 = FUN_005d0177();
      }
      if (local_8 == 0) {
        return -0x7ff8fff2;
      }
      iVar7 = FUN_005c9025(local_8,param_2,puVar5);
      if (iVar7 < 0) goto LAB_005d19b4;
      if (local_18 == 0) {
        *(int *)(param_1 + 0x28) = local_8;
      }
      else {
        *(int *)(local_18 + 0x34) = local_8;
      }
      param_3 = (uint *)((int)param_3 + 1);
      local_18 = local_8;
    } while (param_3 < *(uint *)(param_1 + 0x24));
  }
  param_1 = iVar7;
  local_8 = 0;
  iVar7 = *(int *)(iVar4 + 0x2c);
  if (iVar7 != 0) {
    piVar9 = _malloc(iVar7 * 0x3c + 4);
    if (piVar9 == (int *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      *piVar9 = iVar7;
      piVar9 = piVar9 + 1;
      CallNTimes(piVar9,0x3c,iVar7,FUN_005cd2da);
    }
    *(int **)(iVar4 + 0x30) = piVar9;
    if (piVar9 == (int *)0x0) {
      return -0x7ff8fff2;
    }
  }
  param_3 = (uint *)0x0;
  if (*(int *)(iVar4 + 0x2c) != 0) {
    iVar7 = 0;
    do {
      *(undefined4 *)(iVar7 + 4 + *(int *)(iVar4 + 0x30)) = *(undefined4 *)(iVar4 + 4);
      *(uint **)(iVar7 + 8 + *(int *)(iVar4 + 0x30)) = param_3;
      param_1 = FUN_005d0627(*(int *)(iVar4 + 0x30) + iVar7,param_2,puVar5);
      if (param_1 < 0) {
        return param_1;
      }
      param_3 = (uint *)((int)param_3 + 1);
      iVar7 = iVar7 + 0x3c;
    } while (param_3 < *(uint *)(iVar4 + 0x2c));
  }
  iVar7 = 0;
  param_2 = (int *)0x0;
  if (*(int *)(iVar4 + 0x2c) != 0) {
    param_3 = *(uint **)(iVar4 + 0x2c);
    puVar10 = (undefined4 *)(*(int *)(iVar4 + 0x30) + 0x28);
    do {
      if (puVar10[-1] != 0) {
        piVar9 = (int *)*puVar10;
        iVar12 = *(int *)(iVar7 + 0x24 + *(int *)(iVar4 + 0x30));
        do {
          if (((*(uint *)(&DAT_006dc274 + *piVar9 * 0x1c) & 0xff000000) == 0x3000000) &&
             (param_2 < (uint)piVar9[1])) {
            param_2 = (int *)piVar9[1];
          }
          piVar9 = piVar9 + 0x2b;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
      }
      iVar7 = iVar7 + 0x3c;
      puVar10 = puVar10 + 0xf;
      param_3 = (uint *)((int)param_3 + -1);
    } while (param_3 != (uint *)0x0);
  }
  uVar6 = (int)param_2 * 4 + 4;
  local_10 = _malloc(uVar6);
  if (local_10 == (undefined4 *)0x0) {
LAB_005d187e:
    param_1 = -0x7ff8fff2;
  }
  else {
    puVar10 = local_10;
    for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined1 *)puVar10 = 0;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    *(undefined4 *)(iVar4 + 0x34) = 0;
    param_3 = (uint *)0x0;
    if (*(int *)(iVar4 + 0x2c) != 0) {
      iVar7 = 0;
      do {
        local_14 = 0;
        iVar12 = *(int *)(iVar4 + 0x30) + iVar7;
        if (*(int *)(iVar12 + 0x24) != 0) {
          param_2 = (int *)0x0;
          do {
            piVar9 = (int *)(*(int *)(iVar12 + 0x28) + (int)param_2);
            if (((*(uint *)(&DAT_006dc274 + *piVar9 * 0x1c) & 0xff000000) == 0x3000000) &&
               (local_10[piVar9[1]] == 0)) {
              *(int *)(iVar4 + 0x34) = *(int *)(iVar4 + 0x34) + 1;
              local_10[piVar9[1]] = *(undefined4 *)(iVar4 + 0x34);
            }
            local_14 = local_14 + 1;
            param_2 = (int *)((int)param_2 + 0xac);
          } while (local_14 < *(uint *)(*(int *)(iVar4 + 0x30) + 0x24 + iVar7));
        }
        param_3 = (uint *)((int)param_3 + 1);
        iVar7 = iVar7 + 0x3c;
      } while (param_3 < *(uint *)(iVar4 + 0x2c));
    }
    if (*(int *)(iVar4 + 0x34) != 0) {
      pvVar8 = _malloc(*(int *)(iVar4 + 0x34) * 0x68);
      *(void **)(iVar4 + 0x38) = pvVar8;
      local_c = _malloc(*(int *)(iVar4 + 0x34) << 2);
      if ((*(int *)(iVar4 + 0x38) == 0) || (local_c == (undefined4 *)0x0)) goto LAB_005d187e;
    }
    param_3 = (uint *)0x0;
    if (*(int *)(iVar4 + 0x2c) != 0) {
      local_14 = 0;
      do {
        iVar7 = *(int *)(iVar4 + 0x30) + local_14;
        bVar2 = false;
        puVar10 = local_c;
        for (uVar6 = *(uint *)(iVar4 + 0x34) & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar10 = 0;
          puVar10 = puVar10 + 1;
        }
        for (iVar12 = 0; iVar12 != 0; iVar12 = iVar12 + -1) {
          *(undefined1 *)puVar10 = 0;
          puVar10 = (undefined4 *)((int)puVar10 + 1);
        }
        iVar12 = *(int *)(iVar7 + 0x24);
        *(undefined4 *)(iVar7 + 0x34) = 0xffffffff;
        *(undefined4 *)(iVar7 + 0x38) = 0xffffffff;
        if (iVar12 != 0) {
          param_2 = (int *)(iVar12 * 0xac);
          do {
            param_2 = (int *)((int)param_2 + -0xac);
            piVar9 = (int *)(*(int *)(iVar7 + 0x28) + (int)param_2);
            iVar12 = iVar12 + -1;
            uVar6 = *(uint *)(&DAT_006dc274 + *piVar9 * 0x1c);
            uVar11 = uVar6 >> 0x18;
            if (uVar11 == 3) {
              iVar1 = local_10[piVar9[1]];
              piVar9[0x2a] = iVar1 + -1;
              if (*(uint *)(&DAT_006dc274 + *piVar9 * 0x1c) == 0x300000d) {
                piVar9[10] = piVar9[10] | 2;
              }
              else {
                piVar9[10] = piVar9[10] ^ ((uint)(local_c[iVar1 + -1] == 0) << 1 ^ piVar9[10]) & 2;
                local_c[piVar9[0x2a]] = 1;
              }
            }
            else if (uVar11 == 4) {
              bVar3 = !bVar2;
              bVar2 = true;
              piVar9[10] = piVar9[10] ^ ((uint)bVar3 << 1 ^ piVar9[10]) & 2;
            }
            else if (uVar11 == 6) {
              if ((*(int *)(iVar7 + 0x34) == -1) && (uVar6 == 0x6000000)) {
                *(int *)(iVar7 + 0x34) = iVar12;
              }
              else if ((*(int *)(iVar7 + 0x38) == -1) && (uVar6 == 0x6000001)) {
                *(int *)(iVar7 + 0x38) = iVar12;
              }
            }
          } while (iVar12 != 0);
        }
        param_3 = (uint *)((int)param_3 + 1);
        local_14 = local_14 + 0x3c;
        iVar7 = param_1;
      } while (param_3 < *(uint *)(iVar4 + 0x2c));
LAB_005d19b4:
      param_1 = iVar7;
      if (local_8 != 0) {
        FUN_005d0387(1);
      }
    }
  }
  if (local_10 != (undefined4 *)0x0) {
    _free(local_10);
  }
  if (local_c != (undefined4 *)0x0) {
    _free(local_c);
  }
  return param_1;
}


// ==== 0x5d19ea FUN_005d19ea

uint __thiscall FUN_005d19ea(int param_1,uint param_2,char *param_3,int param_4)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  uint uVar9;
  char *pcVar10;
  int local_c;
  
LAB_005d1bb1:
  if (param_2 != 0) {
    uVar6 = FUN_005d1d40(param_2,param_4 + 1,0);
    uVar9 = 0;
    if (uVar6 != 0) {
      if (param_3 != (char *)0x0) {
        iVar4 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(uVar6 + 4) * 4);
        if (*(int *)(iVar4 + 0x38) == 0) {
          iVar3 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar3 = *(int *)(iVar4 + 0x24) + *(int *)(uVar6 + 8) + iVar3;
        if (((*(int *)(iVar3 + 4) == 5) &&
            ((*(int *)(uVar6 + 0x18) != -1 || (*(int *)(iVar3 + 0x10) == 0)))) &&
           ((uVar5 = *(uint *)(iVar3 + 0x14), *(int *)(uVar6 + 0x10) != 0 ||
            (iVar4 = FUN_005cb568(uVar6,uVar5), -1 < iVar4)))) {
          local_c = 0;
          do {
            if (uVar5 <= uVar9) break;
            iVar3 = *(int *)(uVar6 + 0x10) + local_c;
            iVar4 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
            if (*(int *)(iVar4 + 0x38) == 0) {
              iVar8 = *(int *)(param_1 + 0x2c);
            }
            else {
              iVar8 = *(int *)(*(int *)(param_1 + 0xc) + 8);
            }
            iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x8c) + *(int *)(uVar6 + 4) * 4) + 0x38);
            iVar8 = *(int *)(iVar4 + 0x24) + *(int *)(iVar3 + 8) + iVar8;
            if (iVar1 == 0) {
              iVar4 = *(int *)(param_1 + 0x2c);
            }
            else {
              iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
            }
            iVar3 = *(int *)(iVar8 + 8);
            if (*(int *)(iVar3 + iVar4) == 0) {
              pcVar7 = (char *)0x0;
            }
            else {
              if (iVar1 == 0) {
                iVar4 = *(int *)(param_1 + 0x2c);
              }
              else {
                iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
              }
              pcVar7 = (char *)(iVar3 + 4 + iVar4);
            }
            cVar2 = *param_3;
            pcVar10 = param_3;
            while ((cVar2 == *pcVar7 && (cVar2 != '\0'))) {
              pcVar10 = pcVar10 + 1;
              pcVar7 = pcVar7 + 1;
              cVar2 = *pcVar10;
            }
            cVar2 = *pcVar10;
            if (cVar2 == *pcVar7) {
              uVar6 = uVar9 * 0x20 + *(int *)(uVar6 + 0x10);
              goto LAB_005d1bd2;
            }
            if (*pcVar7 == '\0') {
              if (cVar2 == '.') {
                param_3 = pcVar10 + 1;
                param_2 = ~(uVar9 * 0x20 + *(int *)(uVar6 + 0x10));
                goto LAB_005d1bb1;
              }
              if (cVar2 == '@') {
                uVar6 = FUN_005d07f5(~(uVar9 * 0x20 + *(int *)(uVar6 + 0x10)),pcVar10 + 1,param_4);
                return uVar6;
              }
              if (cVar2 == '[') goto LAB_005d1b40;
            }
            uVar9 = uVar9 + 1;
            local_c = local_c + 0x20;
          } while( true );
        }
        goto LAB_005d1b57;
      }
      goto LAB_005d1bd2;
    }
    goto LAB_005d1b57;
  }
  if ((param_3 == (char *)0x0) || (uVar6 = FUN_005d1d40(param_3,param_4 + 1,0), uVar6 == 0)) {
LAB_005d1b57:
    uVar6 = 0;
  }
  else {
LAB_005d1bd2:
    uVar6 = ~uVar6;
  }
  return uVar6;
LAB_005d1b40:
  pcVar10 = pcVar10 + 1;
  if (((*pcVar10 < '0') || ('9' < *pcVar10)) ||
     (uVar5 = _atoi(pcVar10), *(uint *)(iVar8 + 0x10) <= uVar5)) goto LAB_005d1b57;
  for (; ('/' < *pcVar10 && (*pcVar10 < ':')); pcVar10 = pcVar10 + 1) {
  }
  if (*pcVar10 != ']') goto LAB_005d1b57;
  param_2 = FUN_005ca361(~(uVar9 * 0x20 + *(int *)(uVar6 + 0x10)),uVar5,param_4);
  if (param_2 == 0) goto LAB_005d1b57;
  if (pcVar10[1] == '\0') {
    return param_2;
  }
  if (pcVar10[1] != '.') goto LAB_005d1b57;
  param_3 = pcVar10 + 2;
  goto LAB_005d1bb1;
}


// ==== 0x5d1c05 FUN_005d1c05

void FUN_005d1c05(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005d07f5(param_2,param_3,0);
  return;
}


// ==== 0x5d1c1b FUN_005d1c1b

void __fastcall FUN_005d1c1b(undefined4 *param_1)

{
  void *pvVar1;
  int *piVar2;
  
  pvVar1 = (void *)param_1[0x2a];
  *param_1 = &PTR_FUN_006a0630;
  if (pvVar1 != (void *)0x0) {
    _free(pvVar1);
    param_1[0x2a] = 0;
  }
  pvVar1 = (void *)param_1[0x2b];
  if (pvVar1 != (void *)0x0) {
    _free(pvVar1);
    param_1[0x2b] = 0;
  }
  pvVar1 = (void *)param_1[0x2c];
  if (pvVar1 != (void *)0x0) {
    _free(pvVar1);
    param_1[0x2c] = 0;
  }
  pvVar1 = (void *)param_1[0x24];
  if (pvVar1 != (void *)0x0) {
    _free(pvVar1);
    param_1[0x24] = 0;
  }
  if (param_1[5] != 0) {
    FUN_005d0497(3);
    param_1[5] = 0;
  }
  if (param_1[7] != 0) {
    FUN_005d1545(3);
    param_1[7] = 0;
  }
  if (param_1[9] != 0) {
    FUN_005cb189(3);
    param_1[9] = 0;
  }
  if ((void *)param_1[0xb] != (void *)0x0) {
    _free((void *)param_1[0xb]);
    param_1[0xb] = 0;
  }
  pvVar1 = (void *)param_1[0x23];
  if (pvVar1 != (void *)0x0) {
    _free(pvVar1);
    param_1[0x23] = 0;
  }
  piVar2 = (int *)param_1[0x26];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    param_1[0x26] = 0;
  }
  piVar2 = (int *)param_1[0xe];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    param_1[0xe] = 0;
  }
  piVar2 = (int *)param_1[2];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    param_1[2] = 0;
  }
  piVar2 = (int *)param_1[3];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    param_1[3] = 0;
  }
  FUN_005d031f();
  return;
}


// ==== 0x5d1d24 FUN_005d1d24

void * __thiscall FUN_005d1d24(void *param_1,byte param_2)

{
  FUN_005d1c1b();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d1d40 FUN_005d1d40

int * __thiscall FUN_005d1d40(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  char cVar6;
  int iVar7;
  int *piVar8;
  char *pcVar9;
  uint local_c;
  
  if ((char *)((uint)param_2 & 0xffff) != param_2) {
    if ((char *)((uint)param_2 & 0x7fffffff) == param_2) {
      local_c = 0;
      if (*(int *)(param_1 + 0x10) == 0) {
        return (int *)0x0;
      }
      piVar8 = *(int **)(param_1 + 0x14);
      do {
        iVar7 = *(int *)(*(int *)(param_1 + 0x8c) + piVar8[1] * 4);
        iVar1 = *(int *)(iVar7 + 0x38);
        if (iVar1 == 0) {
          iVar3 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar3 = *(int *)(iVar7 + 0x24) + piVar8[2] + iVar3;
        if (iVar1 == 0) {
          iVar7 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar7 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar2 = *(int *)(iVar3 + 8);
        pcVar9 = param_2;
        cVar6 = *param_2;
        if (*(int *)(iVar2 + iVar7) == 0) {
          pcVar4 = (char *)0x0;
        }
        else {
          if (iVar1 == 0) {
            iVar7 = *(int *)(param_1 + 0x2c);
          }
          else {
            iVar7 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          }
          pcVar4 = (char *)(iVar2 + 4 + iVar7);
        }
        while ((cVar6 == *pcVar4 && (cVar6 != '\0'))) {
          pcVar9 = pcVar9 + 1;
          pcVar4 = pcVar4 + 1;
          cVar6 = *pcVar9;
        }
        cVar6 = *pcVar9;
        if (cVar6 == *pcVar4) {
          return piVar8;
        }
        if (*pcVar4 == '\0') {
          if (cVar6 == '.') {
            pcVar9 = pcVar9 + 1;
            uVar5 = ~(uint)piVar8;
            goto LAB_005d1ed3;
          }
          if (cVar6 == '@') {
            *(undefined4 *)(param_1 + 0x94) = param_4;
            uVar5 = FUN_005d07f5(~(uint)piVar8,pcVar9 + 1,param_3);
            *(undefined4 *)(param_1 + 0x94) = 0;
            goto LAB_005d1eda;
          }
          if (cVar6 == '[') {
            pcVar9 = pcVar9 + 1;
            if (*pcVar9 < '0') {
              return (int *)0x0;
            }
            if ('9' < *pcVar9) {
              return (int *)0x0;
            }
            uVar5 = _atoi(pcVar9);
            if (*(uint *)(iVar3 + 0x10) <= uVar5) {
              return (int *)0x0;
            }
            for (; ('/' < *pcVar9 && (*pcVar9 < ':')); pcVar9 = pcVar9 + 1) {
            }
            if (*pcVar9 == ']') {
              uVar5 = FUN_005ca361(~(uint)piVar8,uVar5,param_3);
              if (uVar5 != 0) {
                if (pcVar9[1] == '\0') {
LAB_005d1e99:
                  return (int *)~uVar5;
                }
                if (pcVar9[1] == '.') {
                  pcVar9 = pcVar9 + 2;
LAB_005d1ed3:
                  uVar5 = FUN_005d19ea(uVar5,pcVar9,param_3);
LAB_005d1eda:
                  if (uVar5 != 0) goto LAB_005d1e99;
                }
              }
            }
            return (int *)0x0;
          }
        }
        local_c = local_c + 1;
        piVar8 = piVar8 + 0x11;
        if (*(uint *)(param_1 + 0x10) <= local_c) {
          return (int *)0x0;
        }
      } while( true );
    }
    piVar8 = (int *)~(uint)param_2;
    if ((*piVar8 == 3) && ((uint)piVar8[1] < *(uint *)(param_1 + 0x88))) {
      return piVar8;
    }
  }
  return (int *)0x0;
}


// ==== 0x5d1ee7 FUN_005d1ee7

uint FUN_005d1ee7(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == 0) {
    if (param_3 < *(uint *)(param_1 + 0x10)) {
      uVar1 = ~(param_3 * 0x44 + *(int *)(param_1 + 0x14));
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    iVar2 = FUN_005d1d40(param_2,1,0);
    if (iVar2 != 0) {
      iVar4 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar2 + 4) * 4);
      if (*(int *)(iVar4 + 0x38) == 0) {
        iVar3 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      }
      iVar3 = *(int *)(iVar4 + 0x24) + *(int *)(iVar2 + 8) + iVar3;
      if (((*(int *)(iVar3 + 4) == 5) &&
          (((*(int *)(iVar2 + 0x18) != -1 || (*(int *)(iVar3 + 0x10) == 0)) &&
           (param_3 < *(uint *)(iVar3 + 0x14))))) &&
         ((*(int *)(iVar2 + 0x10) != 0 ||
          (iVar4 = FUN_005cb568(iVar2,*(uint *)(iVar3 + 0x14)), -1 < iVar4)))) {
        return ~(param_3 * 0x20 + *(int *)(iVar2 + 0x10));
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x5d1f8b FUN_005d1f8b

void FUN_005d1f8b(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005d19ea(param_2,param_3,0);
  return;
}


// ==== 0x5d1fa1 FUN_005d1fa1

uint FUN_005d1fa1(int param_1,uint param_2,byte *param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int *piVar8;
  byte *pbVar9;
  int iVar10;
  bool bVar11;
  
  if (param_2 == 0) {
    param_2 = 0;
    if (*(int *)(param_1 + 0x10) != 0) {
      piVar8 = (int *)(*(int *)(param_1 + 0x14) + 4);
      do {
        iVar3 = *(int *)(*(int *)(param_1 + 0x8c) + *piVar8 * 4);
        iVar5 = *(int *)(iVar3 + 0x38);
        if (iVar5 == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        if (iVar5 == 0) {
          iVar7 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar7 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar3 = *(int *)(*(int *)(iVar3 + 0x24) + piVar8[1] + iVar4 + 0xc);
        pbVar9 = param_3;
        if (*(int *)(iVar3 + iVar7) == 0) {
LAB_005d2053:
          if (pbVar9 == (byte *)0x0) break;
        }
        else {
          if (iVar5 == 0) {
            iVar5 = *(int *)(param_1 + 0x2c);
          }
          else {
            iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          }
          pbVar6 = (byte *)(iVar3 + 4 + iVar5);
          if (pbVar6 == (byte *)0x0) goto LAB_005d2053;
          if (param_3 != (byte *)0x0) {
            do {
              bVar1 = *pbVar6;
              bVar11 = bVar1 < *pbVar9;
              if (bVar1 != *pbVar9) {
LAB_005d2046:
                pbVar9 = (byte *)((1 - (uint)bVar11) - (uint)(bVar11 != 0));
                goto LAB_005d2053;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar6[1];
              bVar11 = bVar1 < pbVar9[1];
              if (bVar1 != pbVar9[1]) goto LAB_005d2046;
              pbVar6 = pbVar6 + 2;
              pbVar9 = pbVar9 + 2;
            } while (bVar1 != 0);
            pbVar9 = (byte *)0x0;
            goto LAB_005d2053;
          }
        }
        param_2 = param_2 + 1;
        piVar8 = piVar8 + 0x11;
      } while (param_2 < *(uint *)(param_1 + 0x10));
    }
    if (param_2 != *(uint *)(param_1 + 0x10)) {
      uVar2 = param_2 * 0x44 + *(int *)(param_1 + 0x14);
LAB_005d21d0:
      return ~uVar2;
    }
  }
  else {
    iVar3 = FUN_005d1d40(param_2,2,0);
    if (iVar3 != 0) {
      iVar5 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
      if (*(int *)(iVar5 + 0x38) == 0) {
        iVar4 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      }
      iVar4 = *(int *)(iVar5 + 0x24) + *(int *)(iVar3 + 8) + iVar4;
      if (((*(int *)(iVar4 + 4) == 5) &&
          ((*(int *)(iVar3 + 0x18) != -1 || (*(int *)(iVar4 + 0x10) == 0)))) &&
         ((uVar2 = *(uint *)(iVar4 + 0x14), *(int *)(iVar3 + 0x10) != 0 ||
          (iVar5 = FUN_005cb568(iVar3,uVar2), -1 < iVar5)))) {
        param_2 = 0;
        if (uVar2 != 0) {
          iVar5 = *(int *)(*(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4) + 0x38);
          piVar8 = (int *)(*(int *)(iVar3 + 0x10) + 4);
          do {
            iVar4 = *(int *)(*(int *)(param_1 + 0x8c) + *piVar8 * 4);
            if (*(int *)(iVar4 + 0x38) == 0) {
              iVar7 = *(int *)(param_1 + 0x2c);
            }
            else {
              iVar7 = *(int *)(*(int *)(param_1 + 0xc) + 8);
            }
            if (iVar5 == 0) {
              iVar10 = *(int *)(param_1 + 0x2c);
            }
            else {
              iVar10 = *(int *)(*(int *)(param_1 + 0xc) + 8);
            }
            iVar4 = *(int *)(*(int *)(iVar4 + 0x24) + piVar8[1] + iVar7 + 0xc);
            pbVar9 = param_3;
            if (*(int *)(iVar4 + iVar10) == 0) {
LAB_005d21aa:
              if (pbVar9 == (byte *)0x0) break;
            }
            else {
              if (iVar5 == 0) {
                iVar7 = *(int *)(param_1 + 0x2c);
              }
              else {
                iVar7 = *(int *)(*(int *)(param_1 + 0xc) + 8);
              }
              pbVar6 = (byte *)(iVar4 + 4 + iVar7);
              if (pbVar6 == (byte *)0x0) goto LAB_005d21aa;
              if (param_3 != (byte *)0x0) {
                do {
                  bVar1 = *pbVar6;
                  bVar11 = bVar1 < *pbVar9;
                  if (bVar1 != *pbVar9) {
LAB_005d219b:
                    pbVar9 = (byte *)((1 - (uint)bVar11) - (uint)(bVar11 != 0));
                    goto LAB_005d21aa;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar6[1];
                  bVar11 = bVar1 < pbVar9[1];
                  if (bVar1 != pbVar9[1]) goto LAB_005d219b;
                  pbVar6 = pbVar6 + 2;
                  pbVar9 = pbVar9 + 2;
                } while (bVar1 != 0);
                pbVar9 = (byte *)0x0;
                goto LAB_005d21aa;
              }
            }
            param_2 = param_2 + 1;
            piVar8 = piVar8 + 8;
          } while (param_2 < uVar2);
        }
        if (param_2 != uVar2) {
          uVar2 = param_2 * 0x20 + *(int *)(iVar3 + 0x10);
          goto LAB_005d21d0;
        }
      }
    }
  }
  return 0;
}


// ==== 0x5d21d9 FUN_005d21d9

undefined4 FUN_005d21d9(int *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = param_1;
  param_1 = (int *)param_1[0xd];
  if (param_3 != 0) {
    iVar2 = FUN_005ca526(param_3,1);
    if (iVar2 == 0) {
      return 0;
    }
    param_1 = *(int **)(iVar2 + 4);
  }
  iVar2 = FUN_005d1d40(param_2,10,0);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = *(int *)(piVar1[0x23] + *(int *)(iVar2 + 4) * 4);
  iVar4 = *(int *)(iVar2 + 0x2c);
  if (iVar4 != 0) {
    do {
      iVar4 = *(int *)(iVar4 + 0x10);
      if ((param_1 == (int *)*(int *)(*(int *)(iVar4 + 8) + 0x54)) ||
         (((iVar3 = *(int *)(*(int *)(iVar4 + 8) + 0x5c), iVar3 != -1 && (iVar3 != 0)) &&
          (iVar3 = (**(code **)(*piVar1 + 0xfc))
                             (piVar1,~*(uint *)(piVar1[0x23] + iVar3 * 4),param_3), iVar3 != 0)))) {
        return 1;
      }
    } while (iVar4 != *(int *)(iVar2 + 0x2c));
  }
  return 0;
}


// ==== 0x5d2276 FUN_005d2276

undefined4 FUN_005d2276(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  if (param_3 == (int *)0x0) {
    return 0x8876086c;
  }
  iVar2 = FUN_005d1d40(param_2,1,0);
  if (iVar2 == 0) {
    return 0x8876086c;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar2 + 4) * 4);
  if (*(int *)(iVar1 + 0x38) == 0) {
    iVar3 = *(int *)(param_1 + 0x2c);
  }
  else {
    iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  piVar4 = (int *)(*(int *)(iVar1 + 0x24) + *(int *)(iVar2 + 8) + iVar3);
  piVar5 = param_3;
  for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  param_3[2] = piVar4[1];
  param_3[3] = *piVar4;
  if (*(int *)(iVar2 + 0x18) == -1) {
    iVar3 = piVar4[4];
  }
  else {
    iVar3 = 0;
  }
  param_3[6] = iVar3;
  iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar2 + 4) * 4) + 0x38);
  if (iVar3 == 0) {
    iVar6 = *(int *)(param_1 + 0x2c);
  }
  else {
    iVar6 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  if (*(int *)(piVar4[2] + iVar6) == 0) {
    iVar3 = 0;
  }
  else {
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    iVar3 = piVar4[2] + 4 + iVar3;
  }
  *param_3 = iVar3;
  iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar2 + 4) * 4) + 0x38);
  if (iVar3 == 0) {
    iVar6 = *(int *)(param_1 + 0x2c);
  }
  else {
    iVar6 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  if (*(int *)(piVar4[3] + iVar6) == 0) {
    iVar3 = 0;
  }
  else {
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    iVar3 = piVar4[3] + 4 + iVar3;
  }
  param_3[1] = iVar3;
  param_3[10] = *(int *)(iVar2 + 0x1c);
  param_3[9] = *(int *)(iVar1 + 0x20);
  if (((*(int *)(iVar2 + 8) == 0) && (*(int *)(iVar2 + 0xc) == 0)) && (*(int *)(iVar2 + 0x18) == -1)
     ) {
    param_3[7] = *(int *)(iVar1 + 0x30);
  }
  else {
    param_3[7] = 0;
  }
  iVar2 = param_3[2];
  if (iVar2 == 1) {
    param_3[8] = 0;
    param_3[4] = piVar4[6];
    iVar2 = piVar4[5];
LAB_005d23f9:
    param_3[5] = iVar2;
  }
  else {
    if (iVar2 == 4) {
      param_3[8] = 0;
    }
    else {
      if (iVar2 != 5) {
        param_3[8] = 0;
        param_3[4] = piVar4[5];
        iVar2 = piVar4[6];
        goto LAB_005d23f9;
      }
      param_3[8] = piVar4[5];
    }
    param_3[4] = 0;
    param_3[5] = 0;
  }
  return 0;
}


// ==== 0x5d2406 FUN_005d2406

undefined4 FUN_005d2406(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(param_1 + 4);
  *piVar1 = *piVar1 + -1;
  uVar2 = *(undefined4 *)(param_1 + 4);
  if (*piVar1 == 0) {
    FUN_005d1d24(1);
    uVar2 = 0;
  }
  return uVar2;
}


// ==== 0x5d241e FUN_005d241e

undefined4 __thiscall FUN_005d241e(uint param_1,int *param_2,int *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 *_Memory;
  int *piVar3;
  void *pvVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *piVar10;
  bool bVar11;
  uint local_8;
  
  iVar2 = *(int *)(&DAT_006dc264 + *param_2 * 0x1c);
  if ((((iVar2 != 0x10) && (iVar2 != 0xf)) && (iVar2 != 5)) && (iVar2 != 10)) {
    return 0x80004005;
  }
  local_8 = param_1;
  if ((param_3 != (int *)0x0) &&
     (uVar1 = (**(code **)(*param_3 + 0x10))(param_3), *param_4 + 1 <= uVar1)) {
    iVar2 = (**(code **)(*param_3 + 0xc))(param_3);
    local_8 = *(uint *)(iVar2 + *param_4 * 4);
  }
  *param_4 = *param_4 + 1;
  if (((param_3 != (int *)0x0) &&
      (uVar1 = (**(code **)(*param_3 + 0x10))(param_3), uVar1 < *param_4)) || (local_8 < 2)) {
    return 0x80004005;
  }
  _Memory = _malloc(local_8);
  if (_Memory != (undefined4 *)0x0) {
    if (local_8 != 0) {
      if ((param_3 != (int *)0x0) &&
         (uVar1 = (**(code **)(*param_3 + 0x10))(param_3),
         (uint)((local_8 & 3) != 0) + (local_8 >> 2) + *param_4 <= uVar1)) {
        iVar2 = (**(code **)(*param_3 + 0xc))(param_3);
        puVar7 = (undefined4 *)(iVar2 + *param_4 * 4);
        puVar9 = _Memory;
        for (uVar1 = local_8 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar9 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar9 = puVar9 + 1;
        }
        for (uVar1 = local_8 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
          *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
      }
      *param_4 = *param_4 + (uint)((local_8 & 3) != 0) + (local_8 >> 2);
    }
    if ((((param_3 != (int *)0x0) &&
         (uVar1 = (**(code **)(*param_3 + 0x10))(param_3), uVar1 < *param_4)) ||
        (*(char *)((local_8 - 1) + (int)_Memory) != '\0')) ||
       (piVar3 = (int *)FUN_005d1d40(_Memory,2,0), piVar3 == (int *)0x0)) {
LAB_005d259c:
      uVar6 = 0x80004005;
      goto LAB_005d25f1;
    }
    iVar2 = *(int *)(*(int *)(param_1 + 0x8c) + piVar3[1] * 4);
    if (*(int *)(iVar2 + 0x38) == 0) {
      iVar5 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    iVar2 = *(int *)(*(int *)(iVar2 + 0x24) + piVar3[2] + iVar5);
    iVar5 = *(int *)(&DAT_006dc264 + *param_2 * 0x1c);
    if (iVar5 == 5) {
      if (((iVar2 != 5) && (iVar2 != 6)) && ((iVar2 != 7 && (iVar2 != 8)))) {
        bVar11 = iVar2 == 9;
        goto LAB_005d259a;
      }
    }
    else {
      if (iVar5 == 10) {
        if (((iVar2 == 10) || (iVar2 == 0xb)) || ((iVar2 == 0xc || (iVar2 == 0xd))))
        goto LAB_005d25bc;
        bVar11 = iVar2 == 0xe;
      }
      else {
        bVar11 = iVar5 == iVar2;
      }
LAB_005d259a:
      if (!bVar11) goto LAB_005d259c;
    }
LAB_005d25bc:
    piVar8 = piVar3;
    piVar10 = param_2 + 2;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar10 = *piVar8;
      piVar8 = piVar8 + 1;
      piVar10 = piVar10 + 1;
    }
    param_2[0xb] = 1;
    pvVar4 = _malloc(4);
    param_2[0xc] = (int)pvVar4;
    if (pvVar4 != (void *)0x0) {
      uVar6 = FUN_005cb49a(piVar3,param_2,0);
      goto LAB_005d25f1;
    }
  }
  uVar6 = 0x8007000e;
LAB_005d25f1:
  if (_Memory != (undefined4 *)0x0) {
    _free(_Memory);
  }
  return uVar6;
}


// ==== 0x5d2609 FUN_005d2609

int FUN_005d2609(int param_1,int *param_2,uint *param_3)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 *_Memory;
  undefined4 *puVar5;
  void *pvVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  uint local_c;
  int local_8;
  
  if ((param_2 != (int *)0x0) &&
     (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), *param_3 + 1 <= uVar3)) {
    iVar4 = (**(code **)(*param_2 + 0xc))(param_2);
    local_8 = *(int *)(iVar4 + *param_3 * 4);
  }
  *param_3 = *param_3 + 1;
  if ((param_2 != (int *)0x0) &&
     (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), *param_3 + 1 <= uVar3)) {
    iVar4 = (**(code **)(*param_2 + 0xc))(param_2);
    local_c = *(uint *)(iVar4 + *param_3 * 4);
  }
  *param_3 = *param_3 + 1;
  if (((param_2 != (int *)0x0) &&
      (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), uVar3 < *param_3)) || (local_c < 2)) {
    return -0x7fffbffb;
  }
  _Memory = _malloc(local_c);
  if (_Memory != (undefined4 *)0x0) {
    if (local_c != 0) {
      if ((param_2 != (int *)0x0) &&
         (uVar3 = (**(code **)(*param_2 + 0x10))(param_2),
         (uint)((local_c & 3) != 0) + (local_c >> 2) + *param_3 <= uVar3)) {
        iVar4 = (**(code **)(*param_2 + 0xc))(param_2);
        puVar5 = (undefined4 *)(iVar4 + *param_3 * 4);
        puVar9 = _Memory;
        for (uVar3 = local_c >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar9 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar9 = puVar9 + 1;
        }
        for (uVar3 = local_c & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined1 *)puVar9 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
      }
      *param_3 = *param_3 + (uint)((local_c & 3) != 0) + (local_c >> 2);
    }
    if (((param_2 != (int *)0x0) &&
        (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), uVar3 < *param_3)) ||
       ((*(char *)((local_c - 1) + (int)_Memory) != '\0' ||
        (puVar5 = (undefined4 *)FUN_005d1d40(_Memory,2,0), puVar5 == (undefined4 *)0x0)))) {
LAB_005d290f:
      iVar4 = -0x7fffbffb;
      goto LAB_005d293e;
    }
    puVar9 = puVar5;
    puVar10 = (undefined4 *)(param_1 + 8);
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    *(undefined4 *)(param_1 + 0x2c) = 1;
    pvVar6 = _malloc(4);
    *(void **)(param_1 + 0x30) = pvVar6;
    if (pvVar6 != (void *)0x0) {
      iVar4 = FUN_005cb49a(puVar5,param_1,0);
      if (iVar4 < 0) goto LAB_005d293e;
      pvVar6 = _malloc(0xac);
      if (pvVar6 == (void *)0x0) {
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_005cd207();
      }
      *(int *)(param_1 + 0x60) = iVar7;
      if (iVar7 != 0) {
        *(undefined4 *)(iVar7 + 0x54) = *(undefined4 *)(param_1 + 0x54);
        *(undefined4 *)(*(int *)(param_1 + 0x60) + 0x58) = *(undefined4 *)(param_1 + 0x58);
        **(undefined4 **)(param_1 + 0x60) = 0xffffffff;
        puVar1 = (uint *)(*(int *)(param_1 + 0x60) + 0x28);
        *puVar1 = *puVar1 | 1;
        *(undefined4 *)(*(int *)(param_1 + 0x60) + 0x2c) = 0;
        *(int *)(*(int *)(param_1 + 0x60) + 100) = param_1;
        *(undefined4 *)(*(int *)(param_1 + 0x60) + 0x38) = 1;
        *(int *)(*(int *)(param_1 + 0x60) + 0x40) = *(int *)(*(int *)(param_1 + 0x60) + 0x38) << 2;
        iVar7 = *(int *)(*(int *)(param_1 + 0x60) + 0x40);
        if (iVar7 != 0) {
          *(int *)(*(int *)(param_1 + 0x60) + 0x40) = iVar7 + -1;
        }
        uVar3 = *(uint *)(*(int *)(param_1 + 0x60) + 0x40);
        *(uint *)(*(int *)(param_1 + 0x60) + 0x40) = uVar3 >> 1 | uVar3;
        uVar3 = *(uint *)(*(int *)(param_1 + 0x60) + 0x40);
        *(uint *)(*(int *)(param_1 + 0x60) + 0x40) = uVar3 >> 2 | uVar3;
        uVar3 = *(uint *)(*(int *)(param_1 + 0x60) + 0x40);
        *(uint *)(*(int *)(param_1 + 0x60) + 0x40) = uVar3 >> 4 | uVar3;
        uVar3 = *(uint *)(*(int *)(param_1 + 0x60) + 0x40);
        *(uint *)(*(int *)(param_1 + 0x60) + 0x40) = uVar3 >> 8 | uVar3;
        uVar3 = *(uint *)(*(int *)(param_1 + 0x60) + 0x40);
        *(uint *)(*(int *)(param_1 + 0x60) + 0x40) = uVar3 >> 0x10 | uVar3;
        uVar3 = *(int *)(*(int *)(param_1 + 0x60) + 0x40) * 8 + 8;
        pvVar6 = _malloc(uVar3);
        *(void **)(*(int *)(param_1 + 0x60) + 0x48) = pvVar6;
        if (pvVar6 != (void *)0x0) {
          puVar5 = *(undefined4 **)(*(int *)(param_1 + 0x60) + 0x48);
          for (uVar3 = uVar3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar5 = 0;
            puVar5 = puVar5 + 1;
          }
          for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
            *(undefined1 *)puVar5 = 0;
            puVar5 = (undefined4 *)((int)puVar5 + 1);
          }
          uVar3 = local_8 + (-4 - local_c);
          if ((uVar3 == 0) ||
             (iVar4 = thunk_FUN_005d65b0(uVar3,*(int *)(param_1 + 0x60) + 0x50), iVar4 < 0))
          goto LAB_005d293e;
          piVar2 = *(int **)(*(int *)(param_1 + 0x60) + 0x50);
          puVar5 = (undefined4 *)(**(code **)(*piVar2 + 0xc))(piVar2);
          if ((param_2 != (int *)0x0) &&
             (uVar8 = (**(code **)(*param_2 + 0x10))(param_2),
             (uint)((uVar3 & 3) != 0) + (uVar3 >> 2) + *param_3 <= uVar8)) {
            iVar4 = (**(code **)(*param_2 + 0xc))(param_2);
            puVar9 = (undefined4 *)(iVar4 + *param_3 * 4);
            puVar10 = puVar5;
            for (uVar8 = uVar3 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
              *puVar10 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar10 = puVar10 + 1;
            }
            for (uVar8 = uVar3 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
              *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
              puVar9 = (undefined4 *)((int)puVar9 + 1);
              puVar10 = (undefined4 *)((int)puVar10 + 1);
            }
          }
          *param_3 = *param_3 + (uint)((uVar3 & 3) != 0) + (uVar3 >> 2);
          if ((param_2 == (int *)0x0) ||
             (uVar3 = (**(code **)(*param_2 + 0x10))(param_2), *param_3 <= uVar3)) {
            iVar4 = FUN_005c8e04(puVar5,*(int *)(param_1 + 0x60) + 0x34);
            if (-1 < iVar4) {
              iVar4 = FUN_005ccec4(*(int *)(param_1 + 0x60),
                                   *(undefined4 *)(*(int *)(param_1 + 0x60) + 0x34),1);
            }
            goto LAB_005d293e;
          }
          goto LAB_005d290f;
        }
      }
    }
  }
  iVar4 = -0x7ff8fff2;
LAB_005d293e:
  if (_Memory != (undefined4 *)0x0) {
    _free(_Memory);
  }
  return iVar4;
}


// ==== 0x5d2956 FUN_005d2956

int FUN_005d2956(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 == 0) {
    iVar2 = -0x7789f794;
  }
  else {
    iVar3 = FUN_005d1d40(param_2,1,0);
    if (((iVar3 == 0) ||
        (iVar2 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4),
        (*(uint *)(iVar2 + 0x20) & 2) != 0)) ||
       ((param_4 != 0xffffffff && (param_4 < *(uint *)(iVar3 + 0x1c))))) {
      iVar2 = -0x7789f794;
    }
    else {
      if (*(int *)(iVar2 + 0x38) == 0) {
        iVar1 = *(int *)(param_1 + 0x2c);
        iVar4 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      }
      iVar2 = FUN_005d02b9(*(int *)(iVar2 + 0x24) + *(int *)(iVar3 + 8) + iVar4,
                           *(int *)(iVar2 + 0x28) + *(int *)(iVar3 + 0xc) + iVar1,param_3,
                           *(undefined4 *)(iVar2 + 0x38),*(int *)(iVar3 + 0x18) != -1);
      if (-1 < iVar2) {
        iVar2 = FUN_005d02d7(iVar3);
      }
    }
  }
  return iVar2;
}


// ==== 0x5d2a0a FUN_005d2a0a

undefined4 FUN_005d2a0a(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if (param_3 == 0) {
    uVar3 = 0x8876086c;
  }
  else {
    iVar4 = FUN_005d1d40(param_2,1,0);
    if ((iVar4 == 0) || ((param_4 != 0xffffffff && (param_4 < *(uint *)(iVar4 + 0x1c))))) {
      uVar3 = 0x8876086c;
    }
    else {
      iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar4 + 4) * 4);
      if (*(int *)(iVar1 + 0x38) == 0) {
        iVar2 = *(int *)(param_1 + 0x2c);
        iVar5 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      }
      uVar3 = FUN_005cf2e6(*(int *)(iVar1 + 0x24) + *(int *)(iVar4 + 8) + iVar5,
                           *(int *)(iVar1 + 0x28) + *(int *)(iVar4 + 0xc) + iVar2,param_3,
                           *(int *)(iVar1 + 0x38),*(int *)(iVar4 + 0x18) != -1);
    }
  }
  return uVar3;
}


// ==== 0x5d2aa8 FUN_005d2aa8

undefined4 FUN_005d2aa8(uint param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  uint local_10;
  uint local_c;
  
  if ((param_4 != 0) && (param_3 == 0)) {
    return 0x8876086c;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 4) = 1;
  **(undefined4 **)(param_1 + 0x90) = 3;
  *(uint *)(*(int *)(param_1 + 0x90) + 0x10) = param_4;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x14) = 4;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x18) = 1;
  iVar2 = FUN_005d1d40(param_2,1,1);
  if ((iVar2 != 0) &&
     (iVar5 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar2 + 4) * 4),
     (*(uint *)(iVar5 + 0x20) & 2) == 0)) {
    if (*(int *)(iVar5 + 0x38) == 0) {
      iVar7 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar7 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar3 = (int *)(*(int *)(iVar5 + 0x24) + *(int *)(iVar2 + 8) + iVar7);
    if ((((piVar3[4] != 0) && (*(int *)(iVar2 + 0x18) == -1)) && (param_4 <= (uint)piVar3[4])) &&
       (piVar3[1] == 1)) {
      iVar7 = *piVar3;
      uVar1 = piVar3[5];
      if (*(int *)(iVar5 + 0x38) == 0) {
        iVar8 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar8 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      }
      puVar10 = (uint *)(*(int *)(iVar5 + 0x28) + *(int *)(iVar2 + 0xc) + iVar8);
      param_1 = 4;
      if (uVar1 < 5) {
        param_1 = uVar1;
      }
      if (iVar7 == 1) {
        if (param_4 != 0) {
          local_c = param_4;
          do {
            if (param_1 != 0) {
              local_10 = param_1;
              puVar4 = puVar10;
              do {
                iVar5 = __ftol();
                *puVar4 = (uint)(iVar5 != 0);
                puVar4 = puVar4 + 1;
                local_10 = local_10 - 1;
              } while (local_10 != 0);
            }
            puVar10 = puVar10 + uVar1;
            local_c = local_c - 1;
          } while (local_c != 0);
        }
      }
      else if (iVar7 == 2) {
        if (param_4 != 0) {
          local_10 = param_4;
          do {
            if (param_1 != 0) {
              local_c = param_1;
              puVar4 = puVar10;
              do {
                uVar9 = __ftol();
                *puVar4 = uVar9;
                puVar4 = puVar4 + 1;
                local_c = local_c - 1;
              } while (local_c != 0);
            }
            puVar10 = puVar10 + uVar1;
            local_10 = local_10 - 1;
          } while (local_10 != 0);
        }
      }
      else {
        if (iVar7 != 3) {
          return 0x8876086c;
        }
        for (; param_4 != 0; param_4 = param_4 - 1) {
          if (param_1 != 0) {
            puVar4 = puVar10;
            uVar9 = param_1;
            do {
              *puVar4 = *(uint *)((param_3 - (int)puVar10) + (int)puVar4);
              puVar4 = puVar4 + 1;
              uVar9 = uVar9 - 1;
            } while (uVar9 != 0);
          }
          param_3 = param_3 + 0x10;
          puVar10 = puVar10 + uVar1;
        }
      }
      uVar6 = FUN_005d02d7(iVar2);
      return uVar6;
    }
  }
  return 0x8876086c;
}


// ==== 0x5d2cae FUN_005d2cae

undefined4 FUN_005d2cae(int param_1,uint param_2,float *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  float *pfVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_4 != 0) {
    if (param_3 == (float *)0x0) {
      local_8 = 0x8876086c;
    }
    else {
      iVar3 = FUN_005d1d40(param_2,1,0);
      if (iVar3 != 0) {
        iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
        if (*(int *)(iVar1 + 0x38) == 0) {
          iVar7 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar7 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        piVar5 = (int *)(*(int *)(iVar1 + 0x24) + *(int *)(iVar3 + 8) + iVar7);
        if ((((piVar5[4] != 0) && (*(int *)(iVar3 + 0x18) == -1)) && (param_4 <= (uint)piVar5[4]))
           && (piVar5[1] == 1)) {
          iVar7 = *piVar5;
          uVar2 = piVar5[5];
          if (*(int *)(iVar1 + 0x38) == 0) {
            iVar6 = *(int *)(param_1 + 0x2c);
          }
          else {
            iVar6 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          }
          iVar6 = *(int *)(iVar1 + 0x28) + *(int *)(iVar3 + 0xc) + iVar6;
          param_2 = 4;
          if (uVar2 < 5) {
            param_2 = uVar2;
          }
          pfVar4 = param_3;
          for (iVar3 = (param_4 & 0xfffffff) << 2; iVar3 != 0; iVar3 = iVar3 + -1) {
            *pfVar4 = 0.0;
            pfVar4 = pfVar4 + 1;
          }
          for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *(undefined1 *)pfVar4 = 0;
            pfVar4 = (float *)((int)pfVar4 + 1);
          }
          if (iVar7 == 1) {
            do {
              if (param_2 != 0) {
                pfVar4 = param_3;
                uVar8 = param_2;
                do {
                  *pfVar4 = (float)(*(int *)((int)pfVar4 + (iVar6 - (int)param_3)) != 0);
                  pfVar4 = pfVar4 + 1;
                  uVar8 = uVar8 - 1;
                } while (uVar8 != 0);
              }
              param_3 = param_3 + 4;
              iVar6 = iVar6 + uVar2 * 4;
              param_4 = param_4 - 1;
            } while (param_4 != 0);
            return 0;
          }
          if (iVar7 == 2) {
            do {
              if (param_2 != 0) {
                pfVar4 = param_3;
                uVar8 = param_2;
                do {
                  *pfVar4 = (float)*(int *)((int)pfVar4 + (iVar6 - (int)param_3));
                  pfVar4 = pfVar4 + 1;
                  uVar8 = uVar8 - 1;
                } while (uVar8 != 0);
              }
              param_3 = param_3 + 4;
              iVar6 = iVar6 + uVar2 * 4;
              param_4 = param_4 - 1;
            } while (param_4 != 0);
            return 0;
          }
          if (iVar7 == 3) {
            do {
              if (param_2 != 0) {
                pfVar4 = param_3;
                uVar8 = param_2;
                do {
                  *pfVar4 = *(float *)((iVar6 - (int)param_3) + (int)pfVar4);
                  pfVar4 = pfVar4 + 1;
                  uVar8 = uVar8 - 1;
                } while (uVar8 != 0);
              }
              param_3 = param_3 + 4;
              iVar6 = iVar6 + uVar2 * 4;
              param_4 = param_4 - 1;
            } while (param_4 != 0);
            return 0;
          }
        }
      }
      local_8 = 0x8876086c;
    }
  }
  return local_8;
}


// ==== 0x5d2e38 FUN_005d2e38

int FUN_005d2e38(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((param_4 != 0) && (param_3 == 0)) {
    return -0x7789f794;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 4) = 2;
  **(undefined4 **)(param_1 + 0x90) = 3;
  *(uint *)(*(int *)(param_1 + 0x90) + 0x10) = param_4;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x14) = 4;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x18) = 4;
  iVar1 = FUN_005d1d40(param_2,1,1);
  if ((iVar1 != 0) &&
     (iVar3 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar1 + 4) * 4),
     (*(uint *)(iVar3 + 0x20) & 2) == 0)) {
    iVar4 = *(int *)(iVar3 + 0x38);
    if (iVar4 == 0) {
      iVar2 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    iVar2 = *(int *)(iVar3 + 0x24) + *(int *)(iVar1 + 8) + iVar2;
    if (((*(uint *)(iVar2 + 0x10) != 0) && (*(int *)(iVar1 + 0x18) == -1)) &&
       (param_4 <= *(uint *)(iVar2 + 0x10))) {
      if (*(int *)(iVar2 + 4) == 2) {
        if (iVar4 == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar3 = FUN_005cbd17(iVar2,*(int *)(iVar3 + 0x28) + *(int *)(iVar1 + 0xc) + iVar4,param_3,
                             param_4);
      }
      else {
        if (*(int *)(iVar2 + 4) != 3) {
          return -0x7789f794;
        }
        if (iVar4 == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar3 = FUN_005cbec7(iVar2,*(int *)(iVar3 + 0x28) + *(int *)(iVar1 + 0xc) + iVar4,param_3,
                             param_4);
      }
      if (-1 < iVar3) {
        iVar1 = FUN_005d02d7(iVar1);
        return iVar1;
      }
      return iVar3;
    }
  }
  return -0x7789f794;
}


// ==== 0x5d2f5d FUN_005d2f5d

undefined4 FUN_005d2f5d(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = 0;
  if (param_4 != 0) {
    if (param_3 == 0) {
      uVar2 = 0x8876086c;
    }
    else {
      iVar3 = FUN_005d1d40(param_2,1,0);
      if (iVar3 != 0) {
        iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
        iVar5 = *(int *)(iVar1 + 0x38);
        if (iVar5 == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar4 = *(int *)(iVar1 + 0x24) + *(int *)(iVar3 + 8) + iVar4;
        if (((*(uint *)(iVar4 + 0x10) != 0) && (*(int *)(iVar3 + 0x18) == -1)) &&
           (param_4 <= *(uint *)(iVar4 + 0x10))) {
          if (*(int *)(iVar4 + 4) == 2) {
            if (iVar5 == 0) {
              iVar5 = *(int *)(param_1 + 0x2c);
            }
            else {
              iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
            }
            uVar2 = FUN_005cc081(iVar4,*(int *)(iVar1 + 0x28) + *(int *)(iVar3 + 0xc) + iVar5,
                                 param_3,param_4);
            return uVar2;
          }
          if (*(int *)(iVar4 + 4) == 3) {
            if (iVar5 == 0) {
              iVar5 = *(int *)(param_1 + 0x2c);
            }
            else {
              iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
            }
            uVar2 = FUN_005cc269(iVar4,*(int *)(iVar1 + 0x28) + *(int *)(iVar3 + 0xc) + iVar5,
                                 param_3,param_4);
            return uVar2;
          }
        }
      }
      uVar2 = 0x8876086c;
    }
  }
  return uVar2;
}


// ==== 0x5d3035 FUN_005d3035

int FUN_005d3035(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((param_4 != 0) && (param_3 == 0)) {
    return -0x7789f794;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 4) = 2;
  **(undefined4 **)(param_1 + 0x90) = 3;
  *(uint *)(*(int *)(param_1 + 0x90) + 0x10) = param_4;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x14) = 4;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x18) = 4;
  iVar1 = FUN_005d1d40(param_2,1,1);
  if ((iVar1 != 0) &&
     (iVar3 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar1 + 4) * 4),
     (*(uint *)(iVar3 + 0x20) & 2) == 0)) {
    iVar4 = *(int *)(iVar3 + 0x38);
    if (iVar4 == 0) {
      iVar2 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    iVar2 = *(int *)(iVar3 + 0x24) + *(int *)(iVar1 + 8) + iVar2;
    if (((*(uint *)(iVar2 + 0x10) != 0) && (*(int *)(iVar1 + 0x18) == -1)) &&
       (param_4 <= *(uint *)(iVar2 + 0x10))) {
      if (*(int *)(iVar2 + 4) == 2) {
        if (iVar4 == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar3 = FUN_005cc44f(iVar2,*(int *)(iVar3 + 0x28) + *(int *)(iVar1 + 0xc) + iVar4,param_3,
                             param_4);
      }
      else {
        if (*(int *)(iVar2 + 4) != 3) {
          return -0x7789f794;
        }
        if (iVar4 == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar3 = FUN_005cc632(iVar2,*(int *)(iVar3 + 0x28) + *(int *)(iVar1 + 0xc) + iVar4,param_3,
                             param_4);
      }
      if (-1 < iVar3) {
        iVar1 = FUN_005d02d7(iVar1);
        return iVar1;
      }
      return iVar3;
    }
  }
  return -0x7789f794;
}


// ==== 0x5d315a FUN_005d315a

undefined4 FUN_005d315a(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = 0;
  if (param_4 != 0) {
    if (param_3 == 0) {
      uVar2 = 0x8876086c;
    }
    else {
      iVar3 = FUN_005d1d40(param_2,1,0);
      if (iVar3 != 0) {
        iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
        iVar5 = *(int *)(iVar1 + 0x38);
        if (iVar5 == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar4 = *(int *)(iVar1 + 0x24) + *(int *)(iVar3 + 8) + iVar4;
        if (((*(uint *)(iVar4 + 0x10) != 0) && (*(int *)(iVar3 + 0x18) == -1)) &&
           (param_4 <= *(uint *)(iVar4 + 0x10))) {
          if (*(int *)(iVar4 + 4) == 2) {
            if (iVar5 == 0) {
              iVar5 = *(int *)(param_1 + 0x2c);
            }
            else {
              iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
            }
            uVar2 = FUN_005cc807(iVar4,*(int *)(iVar1 + 0x28) + *(int *)(iVar3 + 0xc) + iVar5,
                                 param_3,param_4);
            return uVar2;
          }
          if (*(int *)(iVar4 + 4) == 3) {
            if (iVar5 == 0) {
              iVar5 = *(int *)(param_1 + 0x2c);
            }
            else {
              iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
            }
            uVar2 = FUN_005cc9cf(iVar4,*(int *)(iVar1 + 0x28) + *(int *)(iVar3 + 0xc) + iVar5,
                                 param_3,param_4);
            return uVar2;
          }
        }
      }
      uVar2 = 0x8876086c;
    }
  }
  return uVar2;
}


// ==== 0x5d3232 FUN_005d3232

int FUN_005d3232(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((param_4 != 0) && (param_3 == 0)) {
    return -0x7789f794;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 4) = 2;
  **(undefined4 **)(param_1 + 0x90) = 3;
  *(uint *)(*(int *)(param_1 + 0x90) + 0x10) = param_4;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x14) = 4;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x18) = 4;
  iVar1 = FUN_005d1d40(param_2,1,1);
  if ((iVar1 != 0) &&
     (iVar3 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar1 + 4) * 4),
     (*(uint *)(iVar3 + 0x20) & 2) == 0)) {
    iVar4 = *(int *)(iVar3 + 0x38);
    if (iVar4 == 0) {
      iVar2 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    iVar2 = *(int *)(iVar3 + 0x24) + *(int *)(iVar1 + 8) + iVar2;
    if (((*(uint *)(iVar2 + 0x10) != 0) && (*(int *)(iVar1 + 0x18) == -1)) &&
       (param_4 <= *(uint *)(iVar2 + 0x10))) {
      if (*(int *)(iVar2 + 4) == 2) {
        if (iVar4 == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar3 = FUN_005cbec7(iVar2,*(int *)(iVar3 + 0x28) + *(int *)(iVar1 + 0xc) + iVar4,param_3,
                             param_4);
      }
      else {
        if (*(int *)(iVar2 + 4) != 3) {
          return -0x7789f794;
        }
        if (iVar4 == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar3 = FUN_005cbd17(iVar2,*(int *)(iVar3 + 0x28) + *(int *)(iVar1 + 0xc) + iVar4,param_3,
                             param_4);
      }
      if (-1 < iVar3) {
        iVar1 = FUN_005d02d7(iVar1);
        return iVar1;
      }
      return iVar3;
    }
  }
  return -0x7789f794;
}


// ==== 0x5d3357 FUN_005d3357

undefined4 FUN_005d3357(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = 0;
  if (param_4 != 0) {
    if (param_3 == 0) {
      uVar2 = 0x8876086c;
    }
    else {
      iVar3 = FUN_005d1d40(param_2,1,0);
      if (iVar3 != 0) {
        iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
        iVar5 = *(int *)(iVar1 + 0x38);
        if (iVar5 == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar4 = *(int *)(iVar1 + 0x24) + *(int *)(iVar3 + 8) + iVar4;
        if (((*(uint *)(iVar4 + 0x10) != 0) && (*(int *)(iVar3 + 0x18) == -1)) &&
           (param_4 <= *(uint *)(iVar4 + 0x10))) {
          if (*(int *)(iVar4 + 4) == 2) {
            if (iVar5 == 0) {
              iVar5 = *(int *)(param_1 + 0x2c);
            }
            else {
              iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
            }
            uVar2 = FUN_005cc269(iVar4,*(int *)(iVar1 + 0x28) + *(int *)(iVar3 + 0xc) + iVar5,
                                 param_3,param_4);
            return uVar2;
          }
          if (*(int *)(iVar4 + 4) == 3) {
            if (iVar5 == 0) {
              iVar5 = *(int *)(param_1 + 0x2c);
            }
            else {
              iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
            }
            uVar2 = FUN_005cc081(iVar4,*(int *)(iVar1 + 0x28) + *(int *)(iVar3 + 0xc) + iVar5,
                                 param_3,param_4);
            return uVar2;
          }
        }
      }
      uVar2 = 0x8876086c;
    }
  }
  return uVar2;
}


// ==== 0x5d342f FUN_005d342f

int FUN_005d342f(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((param_4 != 0) && (param_3 == 0)) {
    return -0x7789f794;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 4) = 2;
  **(undefined4 **)(param_1 + 0x90) = 3;
  *(uint *)(*(int *)(param_1 + 0x90) + 0x10) = param_4;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x14) = 4;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x18) = 4;
  iVar1 = FUN_005d1d40(param_2,1,1);
  if ((iVar1 != 0) &&
     (iVar3 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar1 + 4) * 4),
     (*(uint *)(iVar3 + 0x20) & 2) == 0)) {
    iVar4 = *(int *)(iVar3 + 0x38);
    if (iVar4 == 0) {
      iVar2 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    iVar2 = *(int *)(iVar3 + 0x24) + *(int *)(iVar1 + 8) + iVar2;
    if (((*(uint *)(iVar2 + 0x10) != 0) && (*(int *)(iVar1 + 0x18) == -1)) &&
       (param_4 <= *(uint *)(iVar2 + 0x10))) {
      if (*(int *)(iVar2 + 4) == 2) {
        if (iVar4 == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar3 = FUN_005cc632(iVar2,*(int *)(iVar3 + 0x28) + *(int *)(iVar1 + 0xc) + iVar4,param_3,
                             param_4);
      }
      else {
        if (*(int *)(iVar2 + 4) != 3) {
          return -0x7789f794;
        }
        if (iVar4 == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar3 = FUN_005cc44f(iVar2,*(int *)(iVar3 + 0x28) + *(int *)(iVar1 + 0xc) + iVar4,param_3,
                             param_4);
      }
      if (-1 < iVar3) {
        iVar1 = FUN_005d02d7(iVar1);
        return iVar1;
      }
      return iVar3;
    }
  }
  return -0x7789f794;
}


// ==== 0x5d3554 FUN_005d3554

undefined4 FUN_005d3554(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = 0;
  if (param_4 != 0) {
    if (param_3 == 0) {
      uVar2 = 0x8876086c;
    }
    else {
      iVar3 = FUN_005d1d40(param_2,1,0);
      if (iVar3 != 0) {
        iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
        iVar5 = *(int *)(iVar1 + 0x38);
        if (iVar5 == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar4 = *(int *)(iVar1 + 0x24) + *(int *)(iVar3 + 8) + iVar4;
        if (((*(uint *)(iVar4 + 0x10) != 0) && (*(int *)(iVar3 + 0x18) == -1)) &&
           (param_4 <= *(uint *)(iVar4 + 0x10))) {
          if (*(int *)(iVar4 + 4) == 2) {
            if (iVar5 == 0) {
              iVar5 = *(int *)(param_1 + 0x2c);
            }
            else {
              iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
            }
            uVar2 = FUN_005cc9cf(iVar4,*(int *)(iVar1 + 0x28) + *(int *)(iVar3 + 0xc) + iVar5,
                                 param_3,param_4);
            return uVar2;
          }
          if (*(int *)(iVar4 + 4) == 3) {
            if (iVar5 == 0) {
              iVar5 = *(int *)(param_1 + 0x2c);
            }
            else {
              iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
            }
            uVar2 = FUN_005cc807(iVar4,*(int *)(iVar1 + 0x28) + *(int *)(iVar3 + 0xc) + iVar5,
                                 param_3,param_4);
            return uVar2;
          }
        }
      }
      uVar2 = 0x8876086c;
    }
  }
  return uVar2;
}


// ==== 0x5d362c FUN_005d362c

int FUN_005d362c(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 == 0) {
    return -0x7789f794;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 4) = 2;
  **(undefined4 **)(param_1 + 0x90) = 3;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x10) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x14) = 4;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x18) = 4;
  iVar1 = FUN_005d1d40(param_2,1,1);
  if ((iVar1 != 0) &&
     (iVar3 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar1 + 4) * 4),
     (*(uint *)(iVar3 + 0x20) & 2) == 0)) {
    if (*(int *)(iVar3 + 0x38) == 0) {
      iVar2 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    iVar2 = *(int *)(iVar3 + 0x24) + *(int *)(iVar1 + 8) + iVar2;
    if ((*(int *)(iVar2 + 0x10) == 0) || (*(int *)(iVar1 + 0x18) != -1)) {
      if (*(int *)(iVar2 + 4) == 2) {
        if (*(int *)(iVar3 + 0x38) == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar3 = FUN_005cbd17(iVar2,*(int *)(iVar3 + 0x28) + *(int *)(iVar1 + 0xc) + iVar4,param_3,1)
        ;
      }
      else {
        if (*(int *)(iVar2 + 4) != 3) {
          return -0x7789f794;
        }
        if (*(int *)(iVar3 + 0x38) == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar3 = FUN_005cbec7(iVar2,*(int *)(iVar3 + 0x28) + *(int *)(iVar1 + 0xc) + iVar4,param_3,1)
        ;
      }
      if (-1 < iVar3) {
        iVar1 = FUN_005d02d7(iVar1);
        return iVar1;
      }
      return iVar3;
    }
  }
  return -0x7789f794;
}


// ==== 0x5d3741 FUN_005d3741

undefined4 FUN_005d3741(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if (param_3 == 0) {
    return 0x8876086c;
  }
  iVar2 = FUN_005d1d40(param_2,1,0);
  if (iVar2 != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar2 + 4) * 4);
    iVar5 = *(int *)(iVar1 + 0x38);
    if (iVar5 == 0) {
      iVar4 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    iVar4 = *(int *)(iVar1 + 0x24) + *(int *)(iVar2 + 8) + iVar4;
    if ((*(int *)(iVar4 + 0x10) == 0) || (*(int *)(iVar2 + 0x18) != -1)) {
      if (*(int *)(iVar4 + 4) == 2) {
        if (iVar5 == 0) {
          iVar5 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        uVar3 = FUN_005cc081(iVar4,*(int *)(iVar1 + 0x28) + *(int *)(iVar2 + 0xc) + iVar5,param_3,1)
        ;
        return uVar3;
      }
      if (*(int *)(iVar4 + 4) == 3) {
        if (iVar5 == 0) {
          iVar5 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        uVar3 = FUN_005cc269(iVar4,*(int *)(iVar1 + 0x28) + *(int *)(iVar2 + 0xc) + iVar5,param_3,1)
        ;
        return uVar3;
      }
    }
  }
  return 0x8876086c;
}


// ==== 0x5d3805 FUN_005d3805

int FUN_005d3805(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 == 0) {
    return -0x7789f794;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 4) = 2;
  **(undefined4 **)(param_1 + 0x90) = 3;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x10) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x14) = 4;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x18) = 4;
  iVar1 = FUN_005d1d40(param_2,1,1);
  if ((iVar1 != 0) &&
     (iVar3 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar1 + 4) * 4),
     (*(uint *)(iVar3 + 0x20) & 2) == 0)) {
    if (*(int *)(iVar3 + 0x38) == 0) {
      iVar2 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    iVar2 = *(int *)(iVar3 + 0x24) + *(int *)(iVar1 + 8) + iVar2;
    if ((*(int *)(iVar2 + 0x10) == 0) || (*(int *)(iVar1 + 0x18) != -1)) {
      if (*(int *)(iVar2 + 4) == 2) {
        if (*(int *)(iVar3 + 0x38) == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar3 = FUN_005cbec7(iVar2,*(int *)(iVar3 + 0x28) + *(int *)(iVar1 + 0xc) + iVar4,param_3,1)
        ;
      }
      else {
        if (*(int *)(iVar2 + 4) != 3) {
          return -0x7789f794;
        }
        if (*(int *)(iVar3 + 0x38) == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar3 = FUN_005cbd17(iVar2,*(int *)(iVar3 + 0x28) + *(int *)(iVar1 + 0xc) + iVar4,param_3,1)
        ;
      }
      if (-1 < iVar3) {
        iVar1 = FUN_005d02d7(iVar1);
        return iVar1;
      }
      return iVar3;
    }
  }
  return -0x7789f794;
}


// ==== 0x5d391a FUN_005d391a

undefined4 FUN_005d391a(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if (param_3 == 0) {
    return 0x8876086c;
  }
  iVar2 = FUN_005d1d40(param_2,1,0);
  if (iVar2 != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar2 + 4) * 4);
    iVar5 = *(int *)(iVar1 + 0x38);
    if (iVar5 == 0) {
      iVar4 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    iVar4 = *(int *)(iVar1 + 0x24) + *(int *)(iVar2 + 8) + iVar4;
    if ((*(int *)(iVar4 + 0x10) == 0) || (*(int *)(iVar2 + 0x18) != -1)) {
      if (*(int *)(iVar4 + 4) == 2) {
        if (iVar5 == 0) {
          iVar5 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        uVar3 = FUN_005cc269(iVar4,*(int *)(iVar1 + 0x28) + *(int *)(iVar2 + 0xc) + iVar5,param_3,1)
        ;
        return uVar3;
      }
      if (*(int *)(iVar4 + 4) == 3) {
        if (iVar5 == 0) {
          iVar5 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        uVar3 = FUN_005cc081(iVar4,*(int *)(iVar1 + 0x28) + *(int *)(iVar2 + 0xc) + iVar5,param_3,1)
        ;
        return uVar3;
      }
    }
  }
  return 0x8876086c;
}


// ==== 0x5d39de FUN_005d39de

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005d39de(uint param_1,undefined4 param_2,float *param_3)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar15;
  float10 extraout_ST0_01;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  uint local_8;
  
  iVar8 = param_1;
  if (param_3 == (float *)0x0) {
    return 0x8876086c;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 4) = 1;
  **(undefined4 **)(param_1 + 0x90) = 3;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x10) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x14) = 4;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x18) = 1;
  iVar5 = FUN_005d1d40(param_2,1,1);
  if ((iVar5 != 0) &&
     (iVar2 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar5 + 4) * 4),
     (*(uint *)(iVar2 + 0x20) & 2) == 0)) {
    if (*(int *)(iVar2 + 0x38) == 0) {
      iVar9 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar9 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar6 = (int *)(*(int *)(iVar2 + 0x24) + *(int *)(iVar5 + 8) + iVar9);
    if ((((piVar6[4] == 0) || (*(int *)(iVar5 + 0x18) != -1)) && (-1 < piVar6[1])) &&
       (piVar6[1] < 2)) {
      local_8 = piVar6[5];
      iVar9 = *piVar6;
      if (piVar6[6] == 1) {
        if (4 < local_8) {
          local_8 = 4;
        }
        if (iVar9 == 1) {
          param_1 = 0;
          if (local_8 != 0) {
            do {
              iVar2 = *(int *)(*(int *)(iVar8 + 0x8c) + *(int *)(iVar5 + 4) * 4);
              if (*(int *)(iVar2 + 0x38) == 0) {
                iVar9 = *(int *)(iVar8 + 0x2c);
              }
              else {
                iVar9 = *(int *)(*(int *)(iVar8 + 0xc) + 8);
              }
              iVar11 = param_1 * 4;
              iVar7 = __ftol();
              param_1 = param_1 + 1;
              *(uint *)(*(int *)(iVar2 + 0x28) + iVar11 + iVar9 + *(int *)(iVar5 + 0xc)) =
                   (uint)(iVar7 != 0);
            } while (param_1 < local_8);
          }
        }
        else if (iVar9 == 2) {
          if (local_8 == 1) {
            if (*(int *)(iVar2 + 0x38) == 0) {
              iVar8 = *(int *)(param_1 + 0x2c);
            }
            else {
              iVar8 = *(int *)(*(int *)(param_1 + 0xc) + 8);
            }
            fVar12 = (float10)param_3[3];
            fVar13 = (float10)_K_ONE;
            fVar3 = param_3[1];
            fVar4 = param_3[2];
            fVar14 = (float10)0.0;
            if ((float10)*param_3 < fVar13) {
              fVar15 = (float10)*param_3;
              if (fVar15 < fVar14 == (fVar15 == fVar14)) {
                fVar12 = fVar13;
                param_3 = (float *)__ftol();
                fVar14 = extraout_ST0;
                fVar13 = extraout_ST1;
              }
              else {
                param_3 = (float *)0x0;
              }
            }
            else {
              param_3 = (float *)0xff;
            }
            if ((float10)fVar3 < fVar13) {
              fVar15 = (float10)fVar3;
              if (fVar15 < fVar14 == (fVar15 == fVar14)) {
                fVar12 = fVar13;
                param_1 = __ftol();
                fVar14 = extraout_ST0_00;
                fVar13 = extraout_ST1_00;
              }
              else {
                param_1 = 0;
              }
            }
            else {
              param_1 = 0xff;
            }
            if ((float10)fVar4 < fVar13) {
              fVar15 = (float10)fVar4;
              if (fVar15 < fVar14 == (fVar15 == fVar14)) {
                local_8 = __ftol();
                fVar13 = extraout_ST0_01;
                fVar12 = extraout_ST1_01;
              }
              else {
                local_8 = 0;
              }
            }
            else {
              local_8 = 0xff;
            }
            if (fVar12 < fVar13) {
              if (fVar12 < (float10)0.0 == (fVar12 == (float10)0.0)) {
                iVar9 = __ftol();
              }
              else {
                iVar9 = 0;
              }
            }
            else {
              iVar9 = 0xff;
            }
            *(uint *)(*(int *)(iVar2 + 0x28) + *(int *)(iVar5 + 0xc) + iVar8) =
                 ((iVar9 << 8 | (uint)param_3) << 8 | param_1) << 8 | local_8;
          }
          else {
            param_1 = 0;
            if (local_8 != 0) {
              do {
                iVar2 = *(int *)(*(int *)(iVar8 + 0x8c) + *(int *)(iVar5 + 4) * 4);
                if (*(int *)(iVar2 + 0x38) == 0) {
                  iVar9 = *(int *)(iVar8 + 0x2c);
                }
                else {
                  iVar9 = *(int *)(*(int *)(iVar8 + 0xc) + 8);
                }
                iVar7 = param_1 * 4;
                uVar10 = __ftol();
                param_1 = param_1 + 1;
                *(undefined4 *)(*(int *)(iVar2 + 0x28) + iVar7 + iVar9 + *(int *)(iVar5 + 0xc)) =
                     uVar10;
              } while (param_1 < local_8);
            }
          }
        }
        else {
          if (iVar9 != 3) {
            return 0x8876086c;
          }
          param_1 = 0;
          if (local_8 != 0) {
            do {
              iVar2 = *(int *)(*(int *)(iVar8 + 0x8c) + *(int *)(iVar5 + 4) * 4);
              if (*(int *)(iVar2 + 0x38) == 0) {
                iVar9 = *(int *)(iVar8 + 0x2c);
              }
              else {
                iVar9 = *(int *)(*(int *)(iVar8 + 0xc) + 8);
              }
              iVar7 = param_1 * 4;
              pfVar1 = param_3 + param_1;
              param_1 = param_1 + 1;
              *(float *)(*(int *)(iVar2 + 0x28) + iVar7 + iVar9 + *(int *)(iVar5 + 0xc)) = *pfVar1;
            } while (param_1 < local_8);
          }
        }
        uVar10 = FUN_005d02d7(iVar5);
        return uVar10;
      }
    }
  }
  return 0x8876086c;
}


// ==== 0x5d3d47 FUN_005d3d47

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005d3d47(uint param_1,uint param_2,float *param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  iVar1 = param_1;
  if (param_3 == (float *)0x0) {
    return 0x8876086c;
  }
  iVar5 = FUN_005d1d40(param_2,1,0);
  if (iVar5 != 0) {
    iVar10 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar5 + 4) * 4);
    if (*(int *)(iVar10 + 0x38) == 0) {
      iVar7 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar7 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar6 = (int *)(*(int *)(iVar10 + 0x24) + *(int *)(iVar5 + 8) + iVar7);
    if ((((piVar6[4] == 0) || (*(int *)(iVar5 + 0x18) != -1)) && (-1 < piVar6[1])) &&
       (piVar6[1] < 2)) {
      param_2 = piVar6[5];
      iVar10 = *piVar6;
      if (piVar6[6] == 1) {
        if (4 < param_2) {
          param_2 = 4;
        }
        *param_3 = 0.0;
        param_3[1] = 0.0;
        param_3[2] = 0.0;
        param_3[3] = 0.0;
        if (iVar10 == 1) {
          param_1 = 0;
          if (param_2 == 0) {
            return 0;
          }
          do {
            iVar10 = *(int *)(*(int *)(iVar1 + 0x8c) + *(int *)(iVar5 + 4) * 4);
            if (*(int *)(iVar10 + 0x38) == 0) {
              iVar7 = *(int *)(iVar1 + 0x2c);
            }
            else {
              iVar7 = *(int *)(*(int *)(iVar1 + 0xc) + 8);
            }
            param_3[param_1] =
                 (float)(*(int *)(*(int *)(iVar10 + 0x28) + *(int *)(iVar5 + 0xc) + param_1 * 4 +
                                 iVar7) != 0);
            param_1 = param_1 + 1;
          } while (param_1 < param_2);
          return 0;
        }
        if (iVar10 == 2) {
          if (param_2 == 1) {
            iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar5 + 4) * 4);
            if (*(int *)(iVar1 + 0x38) == 0) {
              iVar10 = *(int *)(param_1 + 0x2c);
            }
            else {
              iVar10 = *(int *)(*(int *)(param_1 + 0xc) + 8);
            }
            uVar9 = *(uint *)(*(int *)(iVar1 + 0x28) + *(int *)(iVar5 + 0xc) + iVar10);
            fVar2 = (float)(uVar9 >> 8 & 0xff) * _K_BLUR_MIN_T;
            fVar3 = (float)(uVar9 & 0xff) * _K_BLUR_MIN_T;
            fVar4 = (float)(uVar9 >> 0x18) * _K_BLUR_MIN_T;
            *param_3 = (float)(uVar9 >> 0x10 & 0xff) * _K_BLUR_MIN_T;
            param_3[1] = fVar2;
            param_3[2] = fVar3;
            param_3[3] = fVar4;
            return 0;
          }
          uVar9 = 0;
          if (param_2 == 0) {
            return 0;
          }
          do {
            iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar5 + 4) * 4);
            if (*(int *)(iVar1 + 0x38) == 0) {
              iVar10 = *(int *)(param_1 + 0x2c);
            }
            else {
              iVar10 = *(int *)(*(int *)(param_1 + 0xc) + 8);
            }
            uVar8 = uVar9 + 1;
            param_3[uVar9] =
                 (float)*(int *)(*(int *)(iVar1 + 0x28) + *(int *)(iVar5 + 0xc) + uVar9 * 4 + iVar10
                                );
            uVar9 = uVar8;
          } while (uVar8 < param_2);
          return 0;
        }
        if (iVar10 == 3) {
          uVar9 = 0;
          if (param_2 == 0) {
            return 0;
          }
          do {
            iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar5 + 4) * 4);
            if (*(int *)(iVar1 + 0x38) == 0) {
              iVar10 = *(int *)(param_1 + 0x2c);
            }
            else {
              iVar10 = *(int *)(*(int *)(param_1 + 0xc) + 8);
            }
            uVar8 = uVar9 + 1;
            param_3[uVar9] =
                 *(float *)(*(int *)(iVar1 + 0x28) + *(int *)(iVar5 + 0xc) + uVar9 * 4 + iVar10);
            uVar9 = uVar8;
          } while (uVar8 < param_2);
          return 0;
        }
      }
    }
  }
  return 0x8876086c;
}


// ==== 0x5d3f76 FUN_005d3f76

int FUN_005d3f76(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = (int *)(param_1 + 0x90);
  *(undefined4 *)(*piVar2 + 4) = 4;
  *(undefined4 *)*piVar2 = 4;
  *(undefined4 *)(*piVar2 + 0x10) = 0;
  iVar1 = FUN_005d1d40(param_2,1,1);
  if ((iVar1 != 0) &&
     (iVar4 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar1 + 4) * 4),
     (*(uint *)(iVar4 + 0x20) & 2) == 0)) {
    if (*(int *)(iVar4 + 0x38) == 0) {
      iVar3 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar2 = (int *)(*(int *)(iVar4 + 0x24) + *(int *)(iVar1 + 8) + iVar3);
    if ((((piVar2[4] == 0) || (*(int *)(iVar1 + 0x18) != -1)) && (piVar2[1] == 4)) && (*piVar2 == 4)
       ) {
      if (*(int *)(iVar4 + 0x38) == 0) {
        iVar3 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      }
      iVar4 = FUN_005cabd8(param_3,*(undefined4 *)
                                    (*(int *)(iVar4 + 0x28) + *(int *)(iVar1 + 0xc) + iVar3),
                           *(int *)(iVar4 + 0x38));
      if (iVar4 < 0) {
        return iVar4;
      }
      iVar1 = FUN_005d02d7(iVar1);
      return iVar1;
    }
  }
  return -0x7789f794;
}


// ==== 0x5d402e FUN_005d402e

undefined4 FUN_005d402e(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  
  if ((param_3 != (undefined4 *)0x0) && (iVar3 = FUN_005d1d40(param_2,1,0), iVar3 != 0)) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
    iVar2 = *(int *)(iVar1 + 0x38);
    if (iVar2 == 0) {
      iVar6 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar6 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar5 = (int *)(*(int *)(iVar1 + 0x24) + *(int *)(iVar3 + 8) + iVar6);
    if ((((piVar5[4] == 0) || (*(int *)(iVar3 + 0x18) != -1)) && (piVar5[1] == 4)) && (*piVar5 == 4)
       ) {
      iVar3 = *(int *)(iVar1 + 0x28) + *(int *)(iVar3 + 0xc);
      if (iVar2 == 0) {
        iVar3 = *(int *)(iVar3 + *(int *)(param_1 + 0x2c));
      }
      else {
        iVar3 = *(int *)(*(int *)(iVar2 + 8) +
                        *(int *)(iVar3 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
      }
      piVar5 = *(int **)(iVar3 * 0x1c + *(int *)(param_1 + 0x24) + 4);
      if (piVar5 != (int *)0x0) {
        uVar4 = (**(code **)(*piVar5 + 0xc))(piVar5);
        *param_3 = uVar4;
        return 0;
      }
      *param_3 = 0;
      return 0;
    }
  }
  return 0x8876086c;
}


// ==== 0x5d40f4 FUN_005d40f4

int FUN_005d40f4(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = (int *)(param_1 + 0x90);
  *(undefined4 *)(*piVar4 + 4) = 4;
  *(undefined4 *)*piVar4 = 5;
  *(undefined4 *)(*piVar4 + 0x10) = 0;
  iVar2 = FUN_005d1d40(param_2,1,1);
  if ((iVar2 == 0) ||
     (iVar3 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar2 + 4) * 4),
     (*(uint *)(iVar3 + 0x20) & 2) != 0)) {
    iVar3 = -0x7789f794;
  }
  else {
    iVar1 = *(int *)(iVar3 + 0x38);
    if (iVar1 == 0) {
      iVar5 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar4 = (int *)(*(int *)(iVar3 + 0x24) + *(int *)(iVar2 + 8) + iVar5);
    if ((((piVar4[4] == 0) || (*(int *)(iVar2 + 0x18) != -1)) && (iVar5 = *piVar4, piVar4[1] == 4))
       && (((iVar5 == 5 || (iVar5 == 6)) || ((iVar5 == 7 || ((iVar5 == 8 || (iVar5 == 9)))))))) {
      if (iVar1 == 0) {
        iVar5 = *(int *)(iVar3 + 0x28) + *(int *)(iVar2 + 0xc);
        iVar3 = *(int *)(iVar5 + *(int *)(param_1 + 0x2c));
      }
      else {
        iVar5 = *(int *)(iVar3 + 0x28) + *(int *)(iVar2 + 0xc);
        iVar3 = *(int *)(*(int *)(iVar1 + 8) +
                        *(int *)(iVar5 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
      }
      if (param_3 == *(int *)(iVar3 * 0x1c + 4 + *(int *)(param_1 + 0x24))) {
        iVar3 = 0;
      }
      else {
        if (iVar1 == 0) {
          iVar3 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar3 = FUN_005cab3f(param_3,*(undefined4 *)(iVar5 + iVar3),iVar1);
        if (-1 < iVar3) {
          iVar3 = FUN_005d02d7(iVar2);
        }
      }
    }
    else {
      iVar3 = -0x7789f794;
    }
  }
  return iVar3;
}


// ==== 0x5d4218 FUN_005d4218

undefined4 FUN_005d4218(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if ((param_3 != (int *)0x0) && (iVar3 = FUN_005d1d40(param_2,1,0), iVar3 != 0)) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
    iVar2 = *(int *)(iVar1 + 0x38);
    if (iVar2 == 0) {
      iVar5 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar4 = (int *)(*(int *)(iVar1 + 0x24) + *(int *)(iVar3 + 8) + iVar5);
    if ((((piVar4[4] == 0) || (*(int *)(iVar3 + 0x18) != -1)) && (iVar5 = *piVar4, piVar4[1] == 4))
       && (((iVar5 == 5 || (iVar5 == 6)) || ((iVar5 == 7 || ((iVar5 == 8 || (iVar5 == 9)))))))) {
      iVar3 = *(int *)(iVar1 + 0x28) + *(int *)(iVar3 + 0xc);
      if (iVar2 == 0) {
        iVar3 = *(int *)(iVar3 + *(int *)(param_1 + 0x2c));
      }
      else {
        iVar3 = *(int *)(*(int *)(iVar2 + 8) +
                        *(int *)(iVar3 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
      }
      piVar4 = *(int **)(iVar3 * 0x1c + 4 + *(int *)(param_1 + 0x24));
      *param_3 = (int)piVar4;
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 4))(piVar4);
        return 0;
      }
      return 0;
    }
  }
  return 0x8876086c;
}


// ==== 0x5d42ed FUN_005d42ed

int FUN_005d42ed(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = (int *)(param_1 + 0x90);
  *(undefined4 *)(*piVar4 + 4) = 4;
  *(undefined4 *)*piVar4 = 0xf;
  *(undefined4 *)(*piVar4 + 0x10) = 0;
  iVar2 = FUN_005d1d40(param_2,1,1);
  if ((iVar2 == 0) ||
     (iVar3 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar2 + 4) * 4),
     (*(uint *)(iVar3 + 0x20) & 2) != 0)) {
    iVar3 = -0x7789f794;
  }
  else {
    iVar1 = *(int *)(iVar3 + 0x38);
    if (iVar1 == 0) {
      iVar5 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar4 = (int *)(*(int *)(iVar3 + 0x24) + *(int *)(iVar2 + 8) + iVar5);
    if ((((piVar4[4] == 0) || (*(int *)(iVar2 + 0x18) != -1)) && (piVar4[1] == 4)) &&
       (*piVar4 == 0xf)) {
      if (iVar1 == 0) {
        iVar5 = *(int *)(iVar3 + 0x28) + *(int *)(iVar2 + 0xc);
        iVar3 = *(int *)(iVar5 + *(int *)(param_1 + 0x2c));
      }
      else {
        iVar5 = *(int *)(iVar3 + 0x28) + *(int *)(iVar2 + 0xc);
        iVar3 = *(int *)(*(int *)(iVar1 + 8) +
                        *(int *)(iVar5 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
      }
      if (param_3 == *(int *)(iVar3 * 0x1c + 4 + *(int *)(param_1 + 0x24))) {
        if (iVar1 == 0) {
          iVar3 = *(int *)(iVar5 + *(int *)(param_1 + 0x2c));
        }
        else {
          iVar3 = *(int *)(*(int *)(iVar1 + 8) +
                          *(int *)(iVar5 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
        }
        if (*(int *)(iVar3 * 0x1c + 0xc + *(int *)(param_1 + 0x24)) != 0) {
          return 0;
        }
      }
      if (iVar1 == 0) {
        iVar3 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      }
      iVar3 = FUN_005ce64f(param_3,*(undefined4 *)(iVar5 + iVar3),iVar1);
      if (-1 < iVar3) {
        iVar3 = FUN_005d02d7(iVar2);
      }
    }
    else {
      iVar3 = -0x7789f794;
    }
  }
  return iVar3;
}


// ==== 0x5d4425 FUN_005d4425

undefined4 FUN_005d4425(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if ((param_3 != (int *)0x0) && (iVar3 = FUN_005d1d40(param_2,1,0), iVar3 != 0)) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
    iVar2 = *(int *)(iVar1 + 0x38);
    if (iVar2 == 0) {
      iVar5 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar4 = (int *)(*(int *)(iVar1 + 0x24) + *(int *)(iVar3 + 8) + iVar5);
    if ((((piVar4[4] == 0) || (*(int *)(iVar3 + 0x18) != -1)) && (piVar4[1] == 4)) &&
       (*piVar4 == 0xf)) {
      iVar3 = *(int *)(iVar1 + 0x28) + *(int *)(iVar3 + 0xc);
      if (iVar2 == 0) {
        iVar3 = *(int *)(iVar3 + *(int *)(param_1 + 0x2c));
      }
      else {
        iVar3 = *(int *)(*(int *)(iVar2 + 8) +
                        *(int *)(iVar3 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
      }
      piVar4 = *(int **)(iVar3 * 0x1c + 4 + *(int *)(param_1 + 0x24));
      *param_3 = (int)piVar4;
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 4))(piVar4);
        return 0;
      }
      return 0;
    }
  }
  return 0x8876086c;
}


// ==== 0x5d44e0 FUN_005d44e0

int FUN_005d44e0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = (int *)(param_1 + 0x90);
  *(undefined4 *)(*piVar4 + 4) = 4;
  *(undefined4 *)*piVar4 = 0x10;
  *(undefined4 *)(*piVar4 + 0x10) = 0;
  iVar2 = FUN_005d1d40(param_2,1,1);
  if ((iVar2 == 0) ||
     (iVar3 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar2 + 4) * 4),
     (*(uint *)(iVar3 + 0x20) & 2) != 0)) {
    iVar3 = -0x7789f794;
  }
  else {
    iVar1 = *(int *)(iVar3 + 0x38);
    if (iVar1 == 0) {
      iVar5 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar4 = (int *)(*(int *)(iVar3 + 0x24) + *(int *)(iVar2 + 8) + iVar5);
    if ((((piVar4[4] == 0) || (*(int *)(iVar2 + 0x18) != -1)) && (piVar4[1] == 4)) &&
       (*piVar4 == 0x10)) {
      if (iVar1 == 0) {
        iVar5 = *(int *)(iVar3 + 0x28) + *(int *)(iVar2 + 0xc);
        iVar3 = *(int *)(iVar5 + *(int *)(param_1 + 0x2c));
      }
      else {
        iVar5 = *(int *)(iVar3 + 0x28) + *(int *)(iVar2 + 0xc);
        iVar3 = *(int *)(*(int *)(iVar1 + 8) +
                        *(int *)(iVar5 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
      }
      if (param_3 == *(int *)(iVar3 * 0x1c + 4 + *(int *)(param_1 + 0x24))) {
        if (iVar1 == 0) {
          iVar3 = *(int *)(iVar5 + *(int *)(param_1 + 0x2c));
        }
        else {
          iVar3 = *(int *)(*(int *)(iVar1 + 8) +
                          *(int *)(iVar5 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
        }
        if (*(int *)(iVar3 * 0x1c + 0xc + *(int *)(param_1 + 0x24)) != 0) {
          return 0;
        }
      }
      if (iVar1 == 0) {
        iVar3 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      }
      iVar3 = FUN_005ce8ec(param_3,*(undefined4 *)(iVar5 + iVar3),iVar1);
      if (-1 < iVar3) {
        iVar3 = FUN_005d02d7(iVar2);
      }
    }
    else {
      iVar3 = -0x7789f794;
    }
  }
  return iVar3;
}


// ==== 0x5d4618 FUN_005d4618

undefined4 FUN_005d4618(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if ((param_3 != (int *)0x0) && (iVar3 = FUN_005d1d40(param_2,1,0), iVar3 != 0)) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
    iVar2 = *(int *)(iVar1 + 0x38);
    if (iVar2 == 0) {
      iVar5 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar4 = (int *)(*(int *)(iVar1 + 0x24) + *(int *)(iVar3 + 8) + iVar5);
    if ((((piVar4[4] == 0) || (*(int *)(iVar3 + 0x18) != -1)) && (piVar4[1] == 4)) &&
       (*piVar4 == 0x10)) {
      iVar3 = *(int *)(iVar1 + 0x28) + *(int *)(iVar3 + 0xc);
      if (iVar2 == 0) {
        iVar3 = *(int *)(iVar3 + *(int *)(param_1 + 0x2c));
      }
      else {
        iVar3 = *(int *)(*(int *)(iVar2 + 8) +
                        *(int *)(iVar3 + *(int *)(*(int *)(param_1 + 0xc) + 8)) * 4);
      }
      piVar4 = *(int **)(iVar3 * 0x1c + 4 + *(int *)(param_1 + 0x24));
      *param_3 = (int)piVar4;
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 4))(piVar4);
        return 0;
      }
      return 0;
    }
  }
  return 0x8876086c;
}


// ==== 0x5d46d3 FUN_005d46d3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005d46d3(int param_1,undefined4 param_2,uint param_3)

{
  float *pfVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  float local_18 [4];
  undefined4 local_8;
  
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 4) = 0;
  **(undefined4 **)(param_1 + 0x90) = 2;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x10) = 0;
  local_8 = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x14) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x18) = 1;
  iVar3 = FUN_005d1d40(param_2,1,1);
  if ((iVar3 != 0) &&
     (iVar7 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4),
     (*(uint *)(iVar7 + 0x20) & 2) == 0)) {
    if (*(int *)(iVar7 + 0x38) == 0) {
      iVar6 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar6 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar4 = (int *)(*(int *)(iVar7 + 0x24) + *(int *)(iVar3 + 8) + iVar6);
    if ((((piVar4[4] == 0) || (*(int *)(iVar3 + 0x18) != -1)) && (-1 < piVar4[1])) &&
       (piVar4[1] < 4)) {
      uVar2 = piVar4[5];
      iVar6 = *piVar4;
      if (((iVar6 == 3) && (piVar4[6] == 1)) && ((uVar2 == 3 || (uVar2 == 4)))) {
        local_18[0] = (float)(param_3 >> 0x10 & 0xff) * _K_BLUR_MIN_T;
        uVar9 = 0;
        local_18[1] = (float)(param_3 >> 8 & 0xff) * _K_BLUR_MIN_T;
        local_18[2] = (float)(param_3 & 0xff) * _K_BLUR_MIN_T;
        local_18[3] = (float)(param_3 >> 0x18) * _K_BLUR_MIN_T;
        if (uVar2 != 0) {
          do {
            iVar7 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
            if (*(int *)(iVar7 + 0x38) == 0) {
              iVar6 = *(int *)(param_1 + 0x2c);
            }
            else {
              iVar6 = *(int *)(*(int *)(param_1 + 0xc) + 8);
            }
            iVar5 = uVar9 * 4;
            pfVar1 = local_18 + uVar9;
            uVar9 = uVar9 + 1;
            *(float *)(*(int *)(iVar7 + 0x28) + iVar5 + iVar6 + *(int *)(iVar3 + 0xc)) = *pfVar1;
          } while (uVar9 < uVar2);
        }
      }
      else {
        if (uVar2 != 1) {
          return 0x8876086c;
        }
        if (piVar4[6] != 1) {
          return 0x8876086c;
        }
        if (iVar6 == 1) {
          if (*(int *)(iVar7 + 0x38) == 0) {
            iVar6 = *(int *)(param_1 + 0x2c);
          }
          else {
            iVar6 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          }
          iVar5 = *(int *)(iVar7 + 0x28) + *(int *)(iVar3 + 0xc);
          if ((*(int *)(iVar5 + iVar6) == 0) == (param_3 == 0)) {
            return local_8;
          }
          if (*(int *)(iVar7 + 0x38) == 0) {
            iVar7 = *(int *)(param_1 + 0x2c);
          }
          else {
            iVar7 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          }
          *(uint *)(iVar5 + iVar7) = (uint)(param_3 != 0);
        }
        else if (iVar6 == 2) {
          if (*(int *)(iVar7 + 0x38) == 0) {
            iVar6 = *(int *)(param_1 + 0x2c);
          }
          else {
            iVar6 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          }
          iVar5 = *(int *)(iVar7 + 0x28) + *(int *)(iVar3 + 0xc);
          if (*(uint *)(iVar5 + iVar6) == param_3) {
            return local_8;
          }
          if (*(int *)(iVar7 + 0x38) == 0) {
            iVar7 = *(int *)(param_1 + 0x2c);
          }
          else {
            iVar7 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          }
          *(uint *)(iVar5 + iVar7) = param_3;
        }
        else {
          if (iVar6 != 3) {
            return 0x8876086c;
          }
          if (*(int *)(iVar7 + 0x38) == 0) {
            iVar6 = *(int *)(param_1 + 0x2c);
          }
          else {
            iVar6 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          }
          iVar5 = *(int *)(iVar7 + 0x28) + *(int *)(iVar3 + 0xc);
          if ((float)(int)param_3 == *(float *)(iVar5 + iVar6)) {
            return local_8;
          }
          if (*(int *)(iVar7 + 0x38) == 0) {
            iVar7 = *(int *)(param_1 + 0x2c);
          }
          else {
            iVar7 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          }
          *(float *)(iVar5 + iVar7) = (float)(int)param_3;
        }
      }
      uVar8 = FUN_005d02d7(iVar3);
      return uVar8;
    }
  }
  return 0x8876086c;
}


// ==== 0x5d494e FUN_005d494e

/* WARNING: Removing unreachable block (ram,0x005d4a67) */
/* WARNING: Removing unreachable block (ram,0x005d4b18) */
/* WARNING: Removing unreachable block (ram,0x005d4aa0) */
/* WARNING: Removing unreachable block (ram,0x005d4adb) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005d494e(int param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 local_18 [5];
  
  if (param_3 == (uint *)0x0) {
    return 0x8876086c;
  }
  iVar1 = FUN_005d1d40(param_2,1,0);
  if (iVar1 == 0) {
    return 0x8876086c;
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar1 + 4) * 4);
  iVar5 = *(int *)(iVar2 + 0x38);
  if (iVar5 == 0) {
    iVar6 = *(int *)(param_1 + 0x2c);
  }
  else {
    iVar6 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  piVar3 = (int *)(*(int *)(iVar2 + 0x24) + *(int *)(iVar1 + 8) + iVar6);
  if ((piVar3[4] != 0) && (*(int *)(iVar1 + 0x18) == -1)) {
    return 0x8876086c;
  }
  if (piVar3[1] < 0) {
    return 0x8876086c;
  }
  if (3 < piVar3[1]) {
    return 0x8876086c;
  }
  uVar4 = piVar3[5];
  iVar6 = *piVar3;
  if (((iVar6 != 3) || (piVar3[6] != 1)) || ((uVar4 != 3 && (uVar4 != 4)))) {
    if (uVar4 != 1) {
      return 0x8876086c;
    }
    if (piVar3[6] != 1) {
      return 0x8876086c;
    }
    if (iVar6 == 1) {
      if (iVar5 == 0) {
        iVar5 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      }
      uVar4 = (uint)(*(int *)(*(int *)(iVar2 + 0x28) + *(int *)(iVar1 + 0xc) + iVar5) != 0);
    }
    else if (iVar6 == 2) {
      if (iVar5 == 0) {
        iVar5 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      }
      uVar4 = *(uint *)(*(int *)(iVar2 + 0x28) + *(int *)(iVar1 + 0xc) + iVar5);
    }
    else {
      if (iVar6 != 3) {
        return 0x8876086c;
      }
      uVar4 = __ftol();
    }
    goto LAB_005d4b3b;
  }
  uVar7 = 0;
  if (uVar4 == 0) {
LAB_005d4a63:
    uVar7 = 0;
  }
  else {
    iVar1 = *(int *)(iVar2 + 0x28) + *(int *)(iVar1 + 0xc);
    do {
      if (iVar5 == 0) {
        iVar2 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      }
      uVar7 = uVar7 + 1;
      *(undefined4 *)(&stack0xffffffe4 + uVar7 * 4) = *(undefined4 *)(iVar1 + iVar2);
      iVar1 = iVar1 + 4;
    } while (uVar7 < uVar4);
    if (0.0 < _K_ONE) goto LAB_005d4a63;
    uVar7 = 0xff;
  }
  if (0.0 < _K_ONE) {
    uVar8 = 0;
    uVar4 = 0;
    iVar1 = 0;
  }
  else {
    uVar8 = 0xff;
    uVar4 = 0xff;
    iVar1 = 0xff;
  }
  uVar4 = ((iVar1 << 8 | uVar7) << 8 | uVar8) << 8 | uVar4;
LAB_005d4b3b:
  *param_3 = uVar4;
  return 0;
}


// ==== 0x5d4bc3 FUN_005d4bc3

undefined4 FUN_005d4bc3(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  
  piVar2 = (int *)(param_1 + 0x90);
  *(undefined4 *)(*piVar2 + 4) = 0;
  *(undefined4 *)*piVar2 = 1;
  *(undefined4 *)(*piVar2 + 0x10) = 0;
  *(undefined4 *)(*piVar2 + 0x14) = 1;
  *(undefined4 *)(*piVar2 + 0x18) = 1;
  iVar1 = FUN_005d1d40(param_2,1,1);
  if ((iVar1 != 0) &&
     (iVar6 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar1 + 4) * 4),
     (*(uint *)(iVar6 + 0x20) & 2) == 0)) {
    iVar4 = *(int *)(iVar6 + 0x38);
    if (iVar4 == 0) {
      iVar3 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar2 = (int *)(*(int *)(iVar6 + 0x24) + *(int *)(iVar1 + 8) + iVar3);
    if ((piVar2[4] == 0) || (*(int *)(iVar1 + 0x18) != -1)) {
      uVar7 = (uint)(param_3 != 0);
      if ((-1 < piVar2[1]) && (((piVar2[1] < 4 && (piVar2[5] == 1)) && (piVar2[6] == 1)))) {
        iVar3 = *piVar2;
        if (iVar3 == 1) {
          if (iVar4 == 0) {
            iVar3 = *(int *)(param_1 + 0x2c);
          }
          else {
            iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          }
          iVar6 = *(int *)(iVar6 + 0x28) + *(int *)(iVar1 + 0xc);
          if ((*(int *)(iVar6 + iVar3) == 0) == (uVar7 == 0)) {
            return 0;
          }
          if (iVar4 == 0) {
            iVar4 = *(int *)(param_1 + 0x2c);
          }
          else {
            iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          }
          *(uint *)(iVar6 + iVar4) = uVar7;
        }
        else if (iVar3 == 2) {
          if (iVar4 == 0) {
            iVar3 = *(int *)(param_1 + 0x2c);
          }
          else {
            iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          }
          iVar6 = *(int *)(iVar6 + 0x28) + *(int *)(iVar1 + 0xc);
          if (*(uint *)(iVar6 + iVar3) == uVar7) {
            return 0;
          }
          if (iVar4 == 0) {
            iVar4 = *(int *)(param_1 + 0x2c);
          }
          else {
            iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          }
          *(uint *)(iVar6 + iVar4) = uVar7;
        }
        else {
          if (iVar3 != 3) {
            return 0x8876086c;
          }
          if (iVar4 == 0) {
            iVar3 = *(int *)(param_1 + 0x2c);
          }
          else {
            iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          }
          iVar6 = *(int *)(iVar6 + 0x28) + *(int *)(iVar1 + 0xc);
          if ((float)uVar7 == *(float *)(iVar6 + iVar3)) {
            return 0;
          }
          if (iVar4 == 0) {
            iVar4 = *(int *)(param_1 + 0x2c);
          }
          else {
            iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          }
          *(float *)(iVar6 + iVar4) = (float)uVar7;
        }
        uVar5 = FUN_005d02d7(iVar1);
        return uVar5;
      }
    }
  }
  return 0x8876086c;
}


// ==== 0x5d4d71 FUN_005d4d71

undefined4 FUN_005d4d71(int param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (param_3 == (uint *)0x0) {
    return 0x8876086c;
  }
  iVar2 = FUN_005d1d40(param_2,1,0);
  if (iVar2 != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar2 + 4) * 4);
    if (*(int *)(iVar1 + 0x38) == 0) {
      iVar4 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar3 = (int *)(*(int *)(iVar1 + 0x24) + *(int *)(iVar2 + 8) + iVar4);
    if (((((piVar3[4] == 0) || (*(int *)(iVar2 + 0x18) != -1)) && (-1 < piVar3[1])) &&
        ((piVar3[1] < 4 && (piVar3[5] == 1)))) && (piVar3[6] == 1)) {
      iVar4 = *piVar3;
      if ((iVar4 == 1) || (iVar4 == 2)) {
        if (*(int *)(iVar1 + 0x38) == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar2 = *(int *)(*(int *)(iVar1 + 0x28) + *(int *)(iVar2 + 0xc) + iVar4);
      }
      else {
        if (iVar4 != 3) {
          return 0x8876086c;
        }
        iVar2 = __ftol();
      }
      *param_3 = (uint)(iVar2 != 0);
      return 0;
    }
  }
  return 0x8876086c;
}


// ==== 0x5d4e55 FUN_005d4e55

undefined4 FUN_005d4e55(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  float *pfVar7;
  
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 4) = 0;
  **(undefined4 **)(param_1 + 0x90) = 1;
  *(uint *)(*(int *)(param_1 + 0x90) + 0x10) = param_4;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x14) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x18) = 1;
  if ((((param_4 == 0) || (param_3 != 0)) && (iVar3 = FUN_005d1d40(param_2,1,1), iVar3 != 0)) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4),
     (*(uint *)(iVar1 + 0x20) & 2) == 0)) {
    if (*(int *)(iVar1 + 0x38) == 0) {
      iVar4 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar6 = (int *)(*(int *)(iVar1 + 0x24) + *(int *)(iVar3 + 8) + iVar4);
    if (((((piVar6[4] != 0) && (*(int *)(iVar3 + 0x18) == -1)) &&
         ((param_4 <= (uint)piVar6[4] && ((-1 < piVar6[1] && (piVar6[1] < 4)))))) &&
        (piVar6[5] == 1)) && (piVar6[6] == 1)) {
      if (*(int *)(iVar1 + 0x38) == 0) {
        iVar4 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      }
      iVar2 = *piVar6;
      pfVar7 = (float *)(*(int *)(iVar1 + 0x28) + *(int *)(iVar3 + 0xc) + iVar4);
      if (iVar2 == 1) {
        if (param_4 != 0) {
          param_3 = param_3 - (int)pfVar7;
          do {
            *pfVar7 = (float)(uint)(*(int *)((int)pfVar7 + param_3) != 0);
            pfVar7 = pfVar7 + 1;
            param_4 = param_4 - 1;
          } while (param_4 != 0);
        }
      }
      else if (iVar2 == 2) {
        if (param_4 != 0) {
          param_3 = param_3 - (int)pfVar7;
          do {
            *pfVar7 = (float)(uint)(*(int *)((int)pfVar7 + param_3) != 0);
            pfVar7 = pfVar7 + 1;
            param_4 = param_4 - 1;
          } while (param_4 != 0);
        }
      }
      else {
        if (iVar2 != 3) {
          return 0x8876086c;
        }
        if (param_4 != 0) {
          param_3 = param_3 - (int)pfVar7;
          do {
            *pfVar7 = (float)(*(int *)(param_3 + (int)pfVar7) != 0);
            pfVar7 = pfVar7 + 1;
            param_4 = param_4 - 1;
          } while (param_4 != 0);
        }
      }
      uVar5 = FUN_005d02d7(iVar3);
      return uVar5;
    }
  }
  return 0x8876086c;
}


// ==== 0x5d4fcd FUN_005d4fcd

undefined4 FUN_005d4fcd(int param_1,undefined4 param_2,uint *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_4 != 0) {
    if (param_3 == (uint *)0x0) {
      local_8 = 0x8876086c;
    }
    else {
      iVar3 = FUN_005d1d40(param_2,1,0);
      if (iVar3 != 0) {
        iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
        if (*(int *)(iVar1 + 0x38) == 0) {
          iVar5 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        piVar4 = (int *)(*(int *)(iVar1 + 0x24) + *(int *)(iVar3 + 8) + iVar5);
        if ((((piVar4[4] != 0) && (*(int *)(iVar3 + 0x18) == -1)) && (param_4 <= (uint)piVar4[4]))
           && (((-1 < piVar4[1] && (piVar4[1] < 4)) && ((piVar4[5] == 1 && (piVar4[6] == 1)))))) {
          if (*(int *)(iVar1 + 0x38) == 0) {
            iVar5 = *(int *)(param_1 + 0x2c);
          }
          else {
            iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          }
          iVar2 = *piVar4;
          iVar5 = *(int *)(iVar1 + 0x28) + *(int *)(iVar3 + 0xc) + iVar5;
          if (iVar2 == 1) {
            if (param_4 == 0) {
              return 0;
            }
            iVar5 = iVar5 - (int)param_3;
            do {
              *param_3 = (uint)(*(int *)((int)param_3 + iVar5) != 0);
              param_3 = param_3 + 1;
              param_4 = param_4 - 1;
            } while (param_4 != 0);
            return 0;
          }
          if (iVar2 == 2) {
            if (param_4 == 0) {
              return 0;
            }
            iVar5 = iVar5 - (int)param_3;
            do {
              *param_3 = (uint)(*(int *)((int)param_3 + iVar5) != 0);
              param_3 = param_3 + 1;
              param_4 = param_4 - 1;
            } while (param_4 != 0);
            return 0;
          }
          if (iVar2 == 3) {
            for (; param_4 != 0; param_4 = param_4 - 1) {
              iVar3 = __ftol();
              *param_3 = (uint)(iVar3 != 0);
              param_3 = param_3 + 1;
            }
            return 0;
          }
        }
      }
      local_8 = 0x8876086c;
    }
  }
  return local_8;
}


// ==== 0x5d510c FUN_005d510c

undefined4 FUN_005d510c(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  float *pfVar7;
  
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 4) = 0;
  **(undefined4 **)(param_1 + 0x90) = 2;
  *(uint *)(*(int *)(param_1 + 0x90) + 0x10) = param_4;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x14) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x18) = 1;
  if ((param_4 != 0) && (param_3 == 0)) {
    return 0x8876086c;
  }
  iVar3 = FUN_005d1d40(param_2,1,1);
  if ((iVar3 != 0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4),
     (*(uint *)(iVar1 + 0x20) & 2) == 0)) {
    if (*(int *)(iVar1 + 0x38) == 0) {
      iVar4 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar6 = (int *)(*(int *)(iVar1 + 0x24) + *(int *)(iVar3 + 8) + iVar4);
    if ((((piVar6[4] != 0) && (*(int *)(iVar3 + 0x18) == -1)) && (param_4 <= (uint)piVar6[4])) &&
       (((-1 < piVar6[1] && (piVar6[1] < 4)) && ((piVar6[5] == 1 && (piVar6[6] == 1)))))) {
      if (*(int *)(iVar1 + 0x38) == 0) {
        iVar4 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      }
      iVar2 = *piVar6;
      pfVar7 = (float *)(*(int *)(iVar1 + 0x28) + *(int *)(iVar3 + 0xc) + iVar4);
      if (iVar2 == 1) {
        if (param_4 != 0) {
          param_3 = param_3 - (int)pfVar7;
          do {
            *pfVar7 = (float)(uint)(*(int *)((int)pfVar7 + param_3) != 0);
            pfVar7 = pfVar7 + 1;
            param_4 = param_4 - 1;
          } while (param_4 != 0);
        }
      }
      else if (iVar2 == 2) {
        if (param_4 != 0) {
          param_3 = param_3 - (int)pfVar7;
          do {
            *pfVar7 = *(float *)((int)pfVar7 + param_3);
            pfVar7 = pfVar7 + 1;
            param_4 = param_4 - 1;
          } while (param_4 != 0);
        }
      }
      else {
        if (iVar2 != 3) {
          return 0x8876086c;
        }
        if (param_4 != 0) {
          param_3 = param_3 - (int)pfVar7;
          do {
            *pfVar7 = (float)*(int *)(param_3 + (int)pfVar7);
            pfVar7 = pfVar7 + 1;
            param_4 = param_4 - 1;
          } while (param_4 != 0);
        }
      }
      uVar5 = FUN_005d02d7(iVar3);
      return uVar5;
    }
  }
  return 0x8876086c;
}


// ==== 0x5d5282 FUN_005d5282

undefined4 FUN_005d5282(int param_1,undefined4 param_2,uint *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_4 != 0) {
    if (param_3 == (uint *)0x0) {
      local_8 = 0x8876086c;
    }
    else {
      iVar3 = FUN_005d1d40(param_2,1,0);
      if (iVar3 != 0) {
        iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
        if (*(int *)(iVar1 + 0x38) == 0) {
          iVar6 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar6 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        piVar5 = (int *)(*(int *)(iVar1 + 0x24) + *(int *)(iVar3 + 8) + iVar6);
        if ((((piVar5[4] != 0) && (*(int *)(iVar3 + 0x18) == -1)) && (param_4 <= (uint)piVar5[4]))
           && (((-1 < piVar5[1] && (piVar5[1] < 4)) && ((piVar5[5] == 1 && (piVar5[6] == 1)))))) {
          if (*(int *)(iVar1 + 0x38) == 0) {
            iVar6 = *(int *)(param_1 + 0x2c);
          }
          else {
            iVar6 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          }
          iVar2 = *piVar5;
          iVar6 = *(int *)(iVar1 + 0x28) + *(int *)(iVar3 + 0xc) + iVar6;
          if (iVar2 == 1) {
            if (param_4 == 0) {
              return 0;
            }
            iVar6 = iVar6 - (int)param_3;
            do {
              *param_3 = (uint)(*(int *)((int)param_3 + iVar6) != 0);
              param_3 = param_3 + 1;
              param_4 = param_4 - 1;
            } while (param_4 != 0);
            return 0;
          }
          if (iVar2 == 2) {
            if (param_4 == 0) {
              return 0;
            }
            iVar6 = iVar6 - (int)param_3;
            do {
              *param_3 = *(uint *)((int)param_3 + iVar6);
              param_3 = param_3 + 1;
              param_4 = param_4 - 1;
            } while (param_4 != 0);
            return 0;
          }
          if (iVar2 == 3) {
            for (; param_4 != 0; param_4 = param_4 - 1) {
              uVar4 = __ftol();
              *param_3 = uVar4;
              param_3 = param_3 + 1;
            }
            return 0;
          }
        }
      }
      local_8 = 0x8876086c;
    }
  }
  return local_8;
}


// ==== 0x5d53ae FUN_005d53ae

undefined4 FUN_005d53ae(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 4) = 0;
  **(undefined4 **)(param_1 + 0x90) = 3;
  *(uint *)(*(int *)(param_1 + 0x90) + 0x10) = param_4;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x14) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x18) = 1;
  if ((param_4 != 0) && (param_3 == 0)) {
    return 0x8876086c;
  }
  iVar2 = FUN_005d1d40(param_2,1,1);
  if ((iVar2 != 0) &&
     (iVar8 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar2 + 4) * 4),
     (*(uint *)(iVar8 + 0x20) & 2) == 0)) {
    if (*(int *)(iVar8 + 0x38) == 0) {
      iVar7 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar7 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar3 = (int *)(*(int *)(iVar8 + 0x24) + *(int *)(iVar2 + 8) + iVar7);
    if ((((piVar3[4] != 0) && (*(int *)(iVar2 + 0x18) == -1)) && (param_4 <= (uint)piVar3[4])) &&
       (((-1 < piVar3[1] && (piVar3[1] < 4)) && ((piVar3[5] == 1 && (piVar3[6] == 1)))))) {
      if (*(int *)(iVar8 + 0x38) == 0) {
        iVar7 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar7 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      }
      iVar1 = *piVar3;
      puVar6 = (uint *)(*(int *)(iVar8 + 0x28) + *(int *)(iVar2 + 0xc) + iVar7);
      if (iVar1 == 1) {
        if (param_4 != 0) {
          param_3 = param_4;
          do {
            iVar8 = __ftol();
            *puVar6 = (uint)(iVar8 != 0);
            puVar6 = puVar6 + 1;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
      }
      else if (iVar1 == 2) {
        if (param_4 != 0) {
          param_3 = param_4;
          do {
            uVar4 = __ftol();
            *puVar6 = uVar4;
            puVar6 = puVar6 + 1;
            param_3 = param_3 - 1;
          } while (param_3 != 0);
        }
      }
      else {
        if (iVar1 != 3) {
          return 0x8876086c;
        }
        if (param_4 != 0) {
          iVar8 = param_3 - (int)puVar6;
          do {
            *puVar6 = *(uint *)(iVar8 + (int)puVar6);
            puVar6 = puVar6 + 1;
            param_4 = param_4 - 1;
          } while (param_4 != 0);
        }
      }
      uVar5 = FUN_005d02d7(iVar2);
      return uVar5;
    }
  }
  return 0x8876086c;
}


// ==== 0x5d553b FUN_005d553b

undefined4 FUN_005d553b(int param_1,undefined4 param_2,float *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 local_8;
  
  local_8 = 0;
  if (param_4 != 0) {
    if (param_3 == (float *)0x0) {
      local_8 = 0x8876086c;
    }
    else {
      iVar3 = FUN_005d1d40(param_2,1,0);
      if (iVar3 != 0) {
        iVar1 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
        if (*(int *)(iVar1 + 0x38) == 0) {
          iVar5 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        piVar4 = (int *)(*(int *)(iVar1 + 0x24) + *(int *)(iVar3 + 8) + iVar5);
        if ((((piVar4[4] != 0) && (*(int *)(iVar3 + 0x18) == -1)) && (param_4 <= (uint)piVar4[4]))
           && (((-1 < piVar4[1] && (piVar4[1] < 4)) && ((piVar4[5] == 1 && (piVar4[6] == 1)))))) {
          if (*(int *)(iVar1 + 0x38) == 0) {
            iVar5 = *(int *)(param_1 + 0x2c);
          }
          else {
            iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          }
          iVar2 = *piVar4;
          iVar5 = *(int *)(iVar1 + 0x28) + *(int *)(iVar3 + 0xc) + iVar5;
          if (iVar2 == 1) {
            if (param_4 == 0) {
              return 0;
            }
            iVar5 = iVar5 - (int)param_3;
            do {
              *param_3 = (float)(*(int *)((int)param_3 + iVar5) != 0);
              param_3 = param_3 + 1;
              param_4 = param_4 - 1;
            } while (param_4 != 0);
            return 0;
          }
          if (iVar2 == 2) {
            if (param_4 == 0) {
              return 0;
            }
            iVar5 = iVar5 - (int)param_3;
            do {
              *param_3 = (float)*(int *)((int)param_3 + iVar5);
              param_3 = param_3 + 1;
              param_4 = param_4 - 1;
            } while (param_4 != 0);
            return 0;
          }
          if (iVar2 == 3) {
            if (param_4 == 0) {
              return 0;
            }
            iVar5 = iVar5 - (int)param_3;
            do {
              *param_3 = *(float *)(iVar5 + (int)param_3);
              param_3 = param_3 + 1;
              param_4 = param_4 - 1;
            } while (param_4 != 0);
            return 0;
          }
        }
      }
      local_8 = 0x8876086c;
    }
  }
  return local_8;
}


// ==== 0x5d5666 FUN_005d5666

undefined4 FUN_005d5666(int param_1,undefined4 param_2,float param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 4) = 0;
  **(undefined4 **)(param_1 + 0x90) = 3;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x10) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x14) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x90) + 0x18) = 1;
  iVar1 = FUN_005d1d40(param_2,1,1);
  if ((iVar1 != 0) &&
     (iVar7 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar1 + 4) * 4),
     (*(uint *)(iVar7 + 0x20) & 2) == 0)) {
    iVar4 = *(int *)(iVar7 + 0x38);
    if (iVar4 == 0) {
      iVar3 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar2 = (int *)(*(int *)(iVar7 + 0x24) + *(int *)(iVar1 + 8) + iVar3);
    if ((((piVar2[4] == 0) || (*(int *)(iVar1 + 0x18) != -1)) && (-1 < piVar2[1])) &&
       (((piVar2[1] < 4 && (piVar2[5] == 1)) && (piVar2[6] == 1)))) {
      iVar3 = *piVar2;
      if (iVar3 == 1) {
        if (iVar4 == 0) {
          iVar3 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar7 = *(int *)(iVar7 + 0x28) + *(int *)(iVar1 + 0xc);
        iVar5 = __ftol();
        if ((*(int *)(iVar7 + iVar3) == 0) == (iVar5 == 0)) {
          return 0;
        }
        if (iVar4 == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        *(uint *)(iVar7 + iVar4) = (uint)(iVar5 != 0);
      }
      else if (iVar3 == 2) {
        if (iVar4 == 0) {
          iVar3 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar7 = *(int *)(iVar7 + 0x28) + *(int *)(iVar1 + 0xc);
        iVar5 = __ftol();
        if (*(int *)(iVar7 + iVar3) == iVar5) {
          return 0;
        }
        if (iVar4 == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        *(int *)(iVar7 + iVar4) = iVar5;
      }
      else {
        if (iVar3 != 3) {
          return 0x8876086c;
        }
        if (iVar4 == 0) {
          iVar3 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        iVar7 = *(int *)(iVar7 + 0x28) + *(int *)(iVar1 + 0xc);
        if (*(float *)(iVar7 + iVar3) == param_3) {
          return 0;
        }
        if (iVar4 == 0) {
          iVar4 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        *(float *)(iVar7 + iVar4) = param_3;
      }
      uVar6 = FUN_005d02d7(iVar1);
      return uVar6;
    }
  }
  return 0x8876086c;
}


// ==== 0x5d5835 FUN_005d5835

undefined4 FUN_005d5835(int param_1,undefined4 param_2,float *param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  if (param_3 == (float *)0x0) {
    return 0x8876086c;
  }
  iVar3 = FUN_005d1d40(param_2,1,0);
  if (iVar3 != 0) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
    iVar5 = *(int *)(iVar2 + 0x38);
    if (iVar5 == 0) {
      iVar6 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar6 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    }
    piVar4 = (int *)(*(int *)(iVar2 + 0x24) + *(int *)(iVar3 + 8) + iVar6);
    if ((((piVar4[4] == 0) || (*(int *)(iVar3 + 0x18) != -1)) && (-1 < piVar4[1])) &&
       (((piVar4[1] < 4 && (piVar4[5] == 1)) && (piVar4[6] == 1)))) {
      iVar6 = *piVar4;
      if (iVar6 == 1) {
        if (iVar5 == 0) {
          iVar5 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        fVar1 = (float)(*(int *)(*(int *)(iVar2 + 0x28) + *(int *)(iVar3 + 0xc) + iVar5) != 0);
      }
      else if (iVar6 == 2) {
        if (iVar5 == 0) {
          iVar5 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        fVar1 = (float)*(int *)(*(int *)(iVar2 + 0x28) + *(int *)(iVar3 + 0xc) + iVar5);
      }
      else {
        if (iVar6 != 3) {
          return 0x8876086c;
        }
        if (iVar5 == 0) {
          iVar5 = *(int *)(param_1 + 0x2c);
        }
        else {
          iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 8);
        }
        fVar1 = *(float *)(*(int *)(iVar2 + 0x28) + *(int *)(iVar3 + 0xc) + iVar5);
      }
      *param_3 = fVar1;
      return 0;
    }
  }
  return 0x8876086c;
}


// ==== 0x5d5932 FUN_005d5932

int __thiscall FUN_005d5932(int param_1,int *param_2,int *param_3,int *param_4,uint *param_5)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  uint uVar6;
  int *piVar7;
  undefined4 uVar8;
  int *piVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar1 = param_5;
  piVar9 = param_4;
  if ((param_2 == (int *)0x0) || (param_4 == (int *)0x0)) {
    return -0x7789f794;
  }
  puVar2 = _malloc(0x1c);
  *(undefined4 **)(param_1 + 0x90) = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
LAB_005d5966:
    iVar3 = -0x7ff8fff2;
  }
  else {
    for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    *(int **)(param_1 + 0xc) = param_3;
    if (param_3 != (int *)0x0) {
      (**(code **)(*param_3 + 4))(param_3);
    }
    *(int **)(param_1 + 8) = param_2;
    (**(code **)(*param_2 + 4))(param_2);
    *(int **)(param_1 + 0x38) = param_4;
    (**(code **)(*param_4 + 4))(param_4);
    param_2 = (int *)*param_5;
    uVar4 = (**(code **)(*param_4 + 0x10))(param_4);
    if ((int)param_2 + 1U <= uVar4) {
      param_2 = (int *)*param_5;
      iVar3 = (**(code **)(*param_4 + 0xc))(param_4);
      param_3 = *(int **)(iVar3 + (int)param_2 * 4);
    }
    *param_5 = (int)param_2 + 1;
    uVar4 = (**(code **)(*param_4 + 0x10))(param_4);
    if (*param_5 + 1 <= uVar4) {
      iVar3 = (**(code **)(*param_4 + 0xc))(param_4);
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(iVar3 + *param_5 * 4);
    }
    *param_5 = *param_5 + 1;
    if ((param_3 == (int *)0xffffffff) &&
       (uVar4 = (**(code **)(*param_4 + 0x10))(param_4), *param_5 <= uVar4)) {
      if (*(void **)(param_1 + 0x2c) != (void *)0x0) {
        _free(*(void **)(param_1 + 0x2c));
        *(undefined4 *)(param_1 + 0x2c) = 0;
      }
      pvVar5 = _malloc(*(size_t *)(param_1 + 0x28));
      *(void **)(param_1 + 0x2c) = pvVar5;
      if (pvVar5 == (void *)0x0) goto LAB_005d5966;
      if (*(int *)(param_1 + 0x28) != 0) {
        uVar4 = *(uint *)(param_1 + 0x28);
        uVar6 = (**(code **)(*param_4 + 0x10))(param_4);
        if ((uint)((uVar4 & 3) != 0) + (uVar4 >> 2) + *param_5 <= uVar6) {
          iVar3 = (**(code **)(*param_4 + 0xc))(param_4);
          puVar2 = (undefined4 *)(iVar3 + *param_5 * 4);
          puVar11 = *(undefined4 **)(param_1 + 0x2c);
          for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar11 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar11 = puVar11 + 1;
          }
          for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar2;
            puVar2 = (undefined4 *)((int)puVar2 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
        }
        *param_5 = *param_5 +
                   (uint)((*(uint *)(param_1 + 0x28) & 3) != 0) + (*(uint *)(param_1 + 0x28) >> 2);
      }
      uVar4 = (**(code **)(*param_4 + 0x10))(param_4);
      if (*param_5 + 1 <= uVar4) {
        iVar3 = (**(code **)(*param_4 + 0xc))(param_4);
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar3 + *param_5 * 4);
      }
      *param_5 = *param_5 + 1;
      uVar4 = (**(code **)(*param_4 + 0x10))(param_4);
      if (*param_5 + 1 <= uVar4) {
        iVar3 = (**(code **)(*param_4 + 0xc))(param_4);
        *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(iVar3 + *param_5 * 4);
      }
      *param_5 = *param_5 + 1;
      uVar4 = (**(code **)(*param_4 + 0x10))(param_4);
      if (*param_5 + 1 <= uVar4) {
        iVar3 = (**(code **)(*param_4 + 0xc))(param_4);
        *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar3 + *param_5 * 4);
      }
      *param_5 = *param_5 + 1;
      uVar4 = (**(code **)(*param_4 + 0x10))(param_4);
      if (((*param_5 <= uVar4) && (3 < *(uint *)(param_1 + 0x28))) &&
         (**(int **)(param_1 + 0x2c) == 0)) {
        iVar3 = *(int *)(param_1 + 0x10);
        if (iVar3 != 0) {
          piVar7 = _malloc(iVar3 * 0x44 + 4);
          if (piVar7 == (int *)0x0) {
            piVar7 = (int *)0x0;
          }
          else {
            *piVar7 = iVar3;
            piVar7 = piVar7 + 1;
            CallNTimes(piVar7,0x44,iVar3,FUN_005d0177);
          }
          *(int **)(param_1 + 0x14) = piVar7;
          if (piVar7 == (int *)0x0) goto LAB_005d5966;
        }
        iVar3 = *(int *)(param_1 + 0x18);
        if (iVar3 != 0) {
          piVar7 = _malloc(iVar3 * 0xac + 4);
          if (piVar7 == (int *)0x0) {
            piVar7 = (int *)0x0;
          }
          else {
            *piVar7 = iVar3;
            piVar7 = piVar7 + 1;
            CallNTimes(piVar7,0xac,iVar3,FUN_005cd2f5);
          }
          *(int **)(param_1 + 0x1c) = piVar7;
          if (piVar7 == (int *)0x0) goto LAB_005d5966;
          iVar3 = *(int *)(param_1 + 0x20);
          if (iVar3 != 0) {
            piVar7 = _malloc(iVar3 * 0x1c + 4);
            if (piVar7 == (int *)0x0) {
              piVar7 = (int *)0x0;
            }
            else {
              *piVar7 = iVar3;
              piVar7 = piVar7 + 1;
              CallNTimes(piVar7,0x1c,iVar3,FUN_005c8f5e);
            }
            *(int **)(param_1 + 0x24) = piVar7;
            if (piVar7 == (int *)0x0) goto LAB_005d5966;
            param_3 = (int *)0x0;
            if (*(int *)(param_1 + 0x20) != 0) {
              param_2 = (int *)0x0;
              do {
                pvVar5 = _malloc(0xac);
                if (pvVar5 == (void *)0x0) {
                  iVar3 = 0;
                }
                else {
                  iVar3 = FUN_005cd207();
                }
                *(int *)((int)param_2 + 0x18 + *(int *)(param_1 + 0x24)) = iVar3;
                if (iVar3 == 0) goto LAB_005d5966;
                param_3 = (int *)((int)param_3 + 1);
                param_2 = (int *)((int)param_2 + 0x1c);
              } while (param_3 < *(int **)(param_1 + 0x20));
            }
          }
          uVar4 = (**(code **)(*param_4 + 0x10))(param_4);
          if (*param_5 <= uVar4) {
            *(undefined4 *)(param_1 + 0x88) = 1;
            param_2 = (int *)0x0;
            if (*(int *)(param_1 + 0x10) != 0) {
              param_3 = (int *)0x0;
              do {
                iVar3 = FUN_005d04e2(*(int *)(param_1 + 0x14) + (int)param_3,param_4,param_5);
                if (iVar3 < 0) {
                  return iVar3;
                }
                param_2 = (int *)((int)param_2 + 1);
                param_3 = param_3 + 0x11;
              } while (param_2 < *(uint *)(param_1 + 0x10));
            }
            param_2 = (int *)0x0;
            if (*(int *)(param_1 + 0x18) != 0) {
              param_3 = (int *)0x0;
              do {
                *(int **)((int)param_3 + *(int *)(param_1 + 0x1c) + 4) = param_2;
                iVar3 = FUN_005d1593(*(int *)(param_1 + 0x1c) + (int)param_3,param_4,param_5);
                if (iVar3 < 0) {
                  return iVar3;
                }
                param_2 = (int *)((int)param_2 + 1);
                param_3 = param_3 + 0x2b;
              } while (param_2 < *(uint *)(param_1 + 0x18));
            }
            piVar7 = _malloc(*(int *)(param_1 + 0x88) << 2);
            *(int **)(param_1 + 0x8c) = piVar7;
            if (piVar7 == (int *)0x0) goto LAB_005d5966;
            *piVar7 = param_1 + 0x40;
            uVar4 = 1;
            param_2 = (int *)0x0;
            if (*(int *)(param_1 + 0x10) != 0) {
              param_3 = (int *)0x0;
              do {
                if (*(uint *)(param_1 + 0x88) <= uVar4) break;
                iVar12 = *(int *)(param_1 + 0x14) + (int)param_3;
                *(int *)(*(int *)(param_1 + 0x8c) + uVar4 * 4) = iVar12;
                *(uint *)(iVar12 + 4) = uVar4;
                iVar3 = *(int *)(*(int *)(param_1 + 0x8c) + uVar4 * 4);
                if (*(int *)(iVar3 + 0x38) == 0) {
                  local_c = *(int *)(param_1 + 0x2c);
                }
                else {
                  local_c = *(int *)(*(int *)(param_1 + 0xc) + 8);
                }
                local_c = *(int *)(iVar3 + 0x24) + *(int *)(iVar12 + 8) + local_c;
                iVar3 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar12 + 4) * 4);
                if (*(int *)(iVar3 + 0x38) == 0) {
                  local_8 = *(int *)(param_1 + 0x2c);
                }
                else {
                  local_8 = *(int *)(*(int *)(param_1 + 0xc) + 8);
                }
                local_8 = *(int *)(iVar3 + 0x28) + *(int *)(iVar12 + 0xc) + local_8;
                local_14 = *(int *)(iVar12 + 0x24);
                local_10 = *(int *)(iVar12 + 0x28);
                iVar3 = FUN_005cd973(&local_c,&local_8,uVar4);
                if (iVar3 < 0) {
                  return iVar3;
                }
                if (*(int *)(*(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar12 + 4) * 4) + 0x38)
                    == 0) {
                  uVar8 = *(undefined4 *)(param_1 + 0x2c);
                }
                else {
                  uVar8 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 8);
                }
                uVar8 = FUN_005ca273(uVar8,&local_14,&local_10);
                *(undefined4 *)(iVar12 + 0x1c) = uVar8;
                iVar3 = *(int *)((int)param_3 + *(int *)(param_1 + 0x14) + 0x34);
                while ((uVar4 = uVar4 + 1, iVar3 != 0 && (uVar4 < *(uint *)(param_1 + 0x88)))) {
                  *(int *)(*(int *)(param_1 + 0x8c) + uVar4 * 4) = iVar3;
                  *(uint *)(iVar3 + 4) = uVar4;
                  iVar12 = *(int *)(*(int *)(param_1 + 0x8c) + uVar4 * 4);
                  if (*(int *)(iVar12 + 0x38) == 0) {
                    local_c = *(int *)(param_1 + 0x2c);
                  }
                  else {
                    local_c = *(int *)(*(int *)(param_1 + 0xc) + 8);
                  }
                  local_c = *(int *)(iVar12 + 0x24) + *(int *)(iVar3 + 8) + local_c;
                  iVar12 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
                  if (*(int *)(iVar12 + 0x38) == 0) {
                    local_8 = *(int *)(param_1 + 0x2c);
                  }
                  else {
                    local_8 = *(int *)(*(int *)(param_1 + 0xc) + 8);
                  }
                  local_8 = *(int *)(iVar12 + 0x28) + *(int *)(iVar3 + 0xc) + local_8;
                  local_14 = *(int *)(iVar3 + 0x24);
                  local_10 = *(int *)(iVar3 + 0x28);
                  iVar12 = FUN_005cd973(&local_c,&local_8,uVar4);
                  if (iVar12 < 0) {
                    return iVar12;
                  }
                  if (*(int *)(*(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4) + 0x38)
                      == 0) {
                    uVar8 = *(undefined4 *)(param_1 + 0x2c);
                  }
                  else {
                    uVar8 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 8);
                  }
                  uVar8 = FUN_005ca273(uVar8,&local_14,&local_10);
                  *(undefined4 *)(iVar3 + 0x1c) = uVar8;
                  iVar3 = *(int *)(iVar3 + 0x34);
                }
                param_2 = (int *)((int)param_2 + 1);
                param_3 = param_3 + 0x11;
              } while (param_2 < *(uint *)(param_1 + 0x10));
            }
            param_2 = (int *)0x0;
            if (*(int *)(param_1 + 0x18) != 0) {
              local_20 = 0;
              do {
                param_3 = (int *)(*(int *)(param_1 + 0x1c) + local_20);
                iVar3 = param_3[10];
                for (; (iVar3 != 0 && (uVar4 < *(uint *)(param_1 + 0x88))); uVar4 = uVar4 + 1) {
                  *(int *)(*(int *)(param_1 + 0x8c) + uVar4 * 4) = iVar3;
                  *(uint *)(iVar3 + 4) = uVar4;
                  iVar12 = *(int *)(*(int *)(param_1 + 0x8c) + uVar4 * 4);
                  if (*(int *)(iVar12 + 0x38) == 0) {
                    local_10 = *(int *)(param_1 + 0x2c);
                  }
                  else {
                    local_10 = *(int *)(*(int *)(param_1 + 0xc) + 8);
                  }
                  local_10 = *(int *)(iVar12 + 0x24) + *(int *)(iVar3 + 8) + local_10;
                  iVar12 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
                  if (*(int *)(iVar12 + 0x38) == 0) {
                    local_14 = *(int *)(param_1 + 0x2c);
                  }
                  else {
                    local_14 = *(int *)(*(int *)(param_1 + 0xc) + 8);
                  }
                  local_14 = *(int *)(iVar12 + 0x28) + *(int *)(iVar3 + 0xc) + local_14;
                  local_8 = *(int *)(iVar3 + 0x24);
                  local_c = *(int *)(iVar3 + 0x28);
                  iVar12 = FUN_005cd973(&local_10,&local_14,uVar4);
                  if (iVar12 < 0) {
                    return iVar12;
                  }
                  if (*(int *)(*(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4) + 0x38)
                      == 0) {
                    uVar8 = *(undefined4 *)(param_1 + 0x2c);
                  }
                  else {
                    uVar8 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 8);
                  }
                  uVar8 = FUN_005ca273(uVar8,&local_8,&local_c);
                  *(undefined4 *)(iVar3 + 0x1c) = uVar8;
                  iVar3 = *(int *)(iVar3 + 0x34);
                }
                local_1c = 0;
                if (param_3[0xb] != 0) {
                  local_18 = 0;
                  do {
                    iVar3 = *(int *)(local_18 + 0x30 + param_3[0xc]);
                    for (; (iVar3 != 0 && (uVar4 < *(uint *)(param_1 + 0x88))); uVar4 = uVar4 + 1) {
                      *(int *)(*(int *)(param_1 + 0x8c) + uVar4 * 4) = iVar3;
                      *(uint *)(iVar3 + 4) = uVar4;
                      iVar12 = *(int *)(*(int *)(param_1 + 0x8c) + uVar4 * 4);
                      if (*(int *)(iVar12 + 0x38) == 0) {
                        local_10 = *(int *)(param_1 + 0x2c);
                      }
                      else {
                        local_10 = *(int *)(*(int *)(param_1 + 0xc) + 8);
                      }
                      local_10 = *(int *)(iVar12 + 0x24) + *(int *)(iVar3 + 8) + local_10;
                      iVar12 = *(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4);
                      if (*(int *)(iVar12 + 0x38) == 0) {
                        local_14 = *(int *)(param_1 + 0x2c);
                      }
                      else {
                        local_14 = *(int *)(*(int *)(param_1 + 0xc) + 8);
                      }
                      local_14 = *(int *)(iVar12 + 0x28) + *(int *)(iVar3 + 0xc) + local_14;
                      local_8 = *(int *)(iVar3 + 0x24);
                      local_c = *(int *)(iVar3 + 0x28);
                      iVar12 = FUN_005cd973(&local_10,&local_14,uVar4);
                      if (iVar12 < 0) {
                        return iVar12;
                      }
                      if (*(int *)(*(int *)(*(int *)(param_1 + 0x8c) + *(int *)(iVar3 + 4) * 4) +
                                  0x38) == 0) {
                        uVar8 = *(undefined4 *)(param_1 + 0x2c);
                      }
                      else {
                        uVar8 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 8);
                      }
                      uVar8 = FUN_005ca273(uVar8,&local_8,&local_c);
                      *(undefined4 *)(iVar3 + 0x1c) = uVar8;
                      iVar3 = *(int *)(iVar3 + 0x34);
                    }
                    local_1c = local_1c + 1;
                    local_18 = local_18 + 0x3c;
                  } while (local_1c < (uint)param_3[0xb]);
                }
                param_2 = (int *)((int)param_2 + 1);
                local_20 = local_20 + 0xac;
              } while (param_2 < *(uint *)(param_1 + 0x18));
            }
            if (uVar4 == *(uint *)(param_1 + 0x88)) {
              param_2 = (int *)*param_5;
              uVar4 = (**(code **)(*param_4 + 0x10))(param_4);
              if ((int)param_2 + 1U <= uVar4) {
                param_2 = (int *)*param_5;
                iVar3 = (**(code **)(*param_4 + 0xc))(param_4);
                param_4 = *(int **)(iVar3 + (int)param_2 * 4);
              }
              *param_5 = (int)param_2 + 1U;
              uVar4 = (**(code **)(*piVar9 + 0x10))(piVar9);
              uVar6 = (int)param_2 + 2;
              param_2 = (int *)((int)param_2 + 1U);
              if (uVar6 <= uVar4) {
                param_2 = (int *)*param_5;
                iVar3 = (**(code **)(*piVar9 + 0xc))(piVar9);
                local_1c = *(uint *)(iVar3 + (int)param_2 * 4);
              }
              *param_5 = (int)param_2 + 1;
              uVar4 = (**(code **)(*piVar9 + 0x10))(piVar9);
              if (*param_5 <= uVar4) {
                iVar3 = 0;
                param_5 = (uint *)0x0;
                if (param_4 != (int *)0x0) {
                  do {
                    iVar3 = FUN_005cd327(piVar9,puVar1);
                    if (iVar3 < 0) {
                      return iVar3;
                    }
                    param_5 = (uint *)((int)param_5 + 1);
                  } while (param_5 < param_4);
                }
                if ((*(int *)(param_1 + 0xc) != 0) &&
                   (param_2 = (int *)0x0, *(int *)(param_1 + 0x10) != 0)) {
                  param_5 = (uint *)0x0;
                  do {
                    param_4 = (int *)(*(int *)(param_1 + 0x14) + (int)param_5);
                    if (((*(uint *)(*(int *)(*(int *)(param_1 + 0x8c) + param_4[1] * 4) + 0x20) & 1)
                         != 0) && (iVar3 = FUN_005b14b6(param_1,param_4), iVar3 < 0)) {
                      return iVar3;
                    }
                    param_2 = (int *)((int)param_2 + 1);
                    param_5 = (uint *)((int)param_5 + 0x44);
                  } while (param_2 < *(uint *)(param_1 + 0x10));
                }
                param_5 = (uint *)0x0;
                if (local_1c != 0) {
                  do {
                    param_2 = (int *)*puVar1;
                    uVar4 = (**(code **)(*piVar9 + 0x10))(piVar9);
                    if ((int)param_2 + 1U <= uVar4) {
                      param_2 = (int *)*puVar1;
                      iVar3 = (**(code **)(*piVar9 + 0xc))(piVar9);
                      local_18 = *(uint *)(iVar3 + (int)param_2 * 4);
                    }
                    *puVar1 = (int)param_2 + 1U;
                    uVar4 = (**(code **)(*piVar9 + 0x10))(piVar9);
                    uVar6 = (int)param_2 + 2;
                    param_2 = (int *)((int)param_2 + 1U);
                    if (uVar6 <= uVar4) {
                      param_2 = (int *)*puVar1;
                      iVar3 = (**(code **)(*piVar9 + 0xc))(piVar9);
                      param_3 = *(int **)(iVar3 + (int)param_2 * 4);
                    }
                    *puVar1 = (int)param_2 + 1U;
                    uVar4 = (**(code **)(*piVar9 + 0x10))(piVar9);
                    uVar6 = (int)param_2 + 2;
                    param_2 = (int *)((int)param_2 + 1U);
                    if (uVar6 <= uVar4) {
                      param_2 = (int *)*puVar1;
                      iVar3 = (**(code **)(*piVar9 + 0xc))(piVar9);
                      local_20 = *(uint *)(iVar3 + (int)param_2 * 4);
                    }
                    *puVar1 = (int)param_2 + 1U;
                    uVar4 = (**(code **)(*piVar9 + 0x10))(piVar9);
                    uVar6 = (int)param_2 + 2;
                    param_2 = (int *)((int)param_2 + 1U);
                    if (uVar6 <= uVar4) {
                      param_2 = (int *)*puVar1;
                      iVar3 = (**(code **)(*piVar9 + 0xc))(piVar9);
                      param_4 = *(int **)(iVar3 + (int)param_2 * 4);
                    }
                    *puVar1 = (int)param_2 + 1;
                    uVar4 = (**(code **)(*piVar9 + 0x10))(piVar9);
                    if (uVar4 < *puVar1) goto LAB_005d63aa;
                    if (local_18 == 0xffffffff) {
                      if ((*(int **)(param_1 + 0x10) <= param_3) ||
                         (iVar3 = *(int *)(param_1 + 0x14) + (int)param_3 * 0x44,
                         *(uint *)(iVar3 + 0x3c) <= local_20)) goto LAB_005d63aa;
                      piVar7 = (int *)(local_20 * 0xac + *(int *)(iVar3 + 0x40));
                    }
                    else {
                      if (((*(uint *)(param_1 + 0x18) <= local_18) ||
                          (iVar3 = local_18 * 0xac + *(int *)(param_1 + 0x1c),
                          *(int **)(iVar3 + 0x2c) <= param_3)) ||
                         (iVar3 = (int)param_3 * 0x3c + *(int *)(iVar3 + 0x30),
                         *(uint *)(iVar3 + 0x24) <= local_20)) goto LAB_005d63aa;
                      piVar7 = (int *)(local_20 * 0xac + *(int *)(iVar3 + 0x28));
                    }
                    piVar7[10] = piVar7[10] | 1;
                    iVar3 = *(int *)(&DAT_006dc264 + *piVar7 * 0x1c);
                    if ((iVar3 == 5) || (iVar3 == 10)) {
                      if (param_4 == (int *)0x1) {
LAB_005d62ee:
                        iVar3 = FUN_005d241e(piVar7,piVar9,puVar1);
                      }
                      else {
                        iVar3 = -0x7fffbffb;
                      }
                    }
                    else if ((iVar3 < 0xf) || (0x10 < iVar3)) {
                      iVar3 = FUN_005cd7bf(piVar7,piVar9,puVar1);
                    }
                    else if (param_4 == (int *)0x0) {
                      iVar3 = FUN_005cd5bf(piVar7,piVar9,puVar1);
                    }
                    else {
                      if (param_4 == (int *)0x1) goto LAB_005d62ee;
                      iVar3 = FUN_005d2609(piVar7,piVar9,puVar1);
                    }
                    if (iVar3 < 0) {
                      return iVar3;
                    }
                    param_5 = (uint *)((int)param_5 + 1);
                  } while (param_5 < local_1c);
                }
                *(undefined4 *)(param_1 + 0x9c) = 0;
                *(undefined4 *)(param_1 + 0xa0) = 0;
                *(undefined4 *)(param_1 + 0xa4) = 0;
                local_20 = 0;
                if (*(int *)(param_1 + 0x18) != 0) {
                  param_3 = (int *)0x0;
                  do {
                    iVar12 = *(int *)(param_1 + 0x1c) + (int)param_3;
                    param_2 = (int *)0x0;
                    *(undefined4 *)(iVar12 + 0x90) = 0;
                    *(undefined4 *)(iVar12 + 0x94) = 0;
                    *(undefined4 *)(iVar12 + 0x98) = 0;
                    *(undefined4 *)(iVar12 + 0x9c) = 0;
                    *(undefined4 *)(iVar12 + 0xa0) = 0;
                    *(undefined4 *)(iVar12 + 0xa4) = 0;
                    *(undefined4 *)(iVar12 + 0xa8) = 0;
                    if (*(int *)(iVar12 + 0x2c) != 0) {
                      local_1c = 0;
                      do {
                        param_4 = (int *)0x0;
                        if (*(int *)(*(int *)(iVar12 + 0x30) + 0x24 + local_1c) != 0) {
                          param_5 = (uint *)0x0;
                          do {
                            piVar9 = (int *)(*(int *)(*(int *)(iVar12 + 0x30) + 0x28 + local_1c) +
                                            (int)param_5);
                            iVar14 = *(int *)(&DAT_006dc274 + *piVar9 * 0x1c);
                            if ((iVar14 == 0x6000000) || (iVar14 == 0x6000001)) {
                              iVar3 = *(int *)(*(int *)(param_1 + 0x8c) + piVar9[3] * 4);
                              iVar13 = *(int *)(iVar3 + 0x38);
                              iVar3 = *(int *)(iVar3 + 0x28) + piVar9[5];
                              if (iVar13 == 0) {
                                iVar3 = *(int *)(iVar3 + *(int *)(param_1 + 0x2c));
                              }
                              else {
                                iVar3 = *(int *)(*(int *)(iVar13 + 8) +
                                                *(int *)(iVar3 + *(int *)(*(int *)(param_1 + 0xc) +
                                                                         8)) * 4);
                              }
                              if (iVar14 == 0x6000000) {
                                iVar14 = iVar12 + 0x98;
                                iVar13 = iVar12 + 0x94;
                                iVar10 = iVar12 + 0x90;
                              }
                              else {
                                iVar14 = iVar12 + 0xa4;
                                iVar13 = iVar12 + 0xa0;
                                iVar10 = iVar12 + 0x9c;
                              }
                              iVar3 = FUN_005c80ae(*(undefined4 *)
                                                    (iVar3 * 0x1c + 0x14 + *(int *)(param_1 + 0x24))
                                                   ,iVar10,iVar13,iVar14,iVar12 + 0xa8,0);
                              if (iVar3 < 0) {
                                return iVar3;
                              }
                            }
                            param_4 = (int *)((int)param_4 + 1);
                            param_5 = (uint *)((int)param_5 + 0xac);
                          } while (param_4 < *(uint *)(*(int *)(iVar12 + 0x30) + 0x24 + local_1c));
                        }
                        param_2 = (int *)((int)param_2 + 1);
                        local_1c = local_1c + 0x3c;
                      } while (param_2 < *(uint *)(iVar12 + 0x2c));
                    }
                    local_20 = local_20 + 1;
                    param_3 = (int *)((int)param_3 + 0xac);
                  } while (local_20 < *(uint *)(param_1 + 0x18));
                }
                *(undefined4 *)(param_1 + 0x30) = 0xffffffff;
                *(undefined4 *)(param_1 + 0x34) = 0;
                *(undefined4 *)(param_1 + 0x84) = 0;
                return iVar3;
              }
            }
          }
        }
      }
    }
LAB_005d63aa:
    iVar3 = -0x7fffbffb;
  }
  return iVar3;
}


// ==== 0x5d64ca FUN_005d64ca

void __fastcall FUN_005d64ca(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a074c;
  _free((void *)param_1[3]);
  return;
}


// ==== 0x5d64da FUN_005d64da

undefined4 __thiscall FUN_005d64da(int param_1,size_t param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = _malloc(param_2);
  *(void **)(param_1 + 0xc) = pvVar1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    *(size_t *)(param_1 + 8) = param_2;
    uVar2 = 0;
  }
  return uVar2;
}


// ==== 0x5d6501 FUN_005d6501

int FUN_005d6501(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[1];
  iVar1 = iVar2 + -1;
  param_1[1] = iVar1;
  if (iVar2 == 1) {
    (**(code **)(*param_1 + 0x14))(1);
  }
  return iVar1;
}


// ==== 0x5d6521 FUN_005d6521

undefined4 FUN_005d6521(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}


// ==== 0x5d652b FUN_005d652b

undefined4 FUN_005d652b(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}


// ==== 0x5d6535 FUN_005d6535

void * __thiscall FUN_005d6535(void *param_1,byte param_2)

{
  FUN_005d64ca();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d6551 FUN_005d6551

undefined4 FUN_005d6551(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  
  *param_3 = 0;
  iVar1 = 4;
  bVar4 = true;
  piVar2 = param_2;
  piVar3 = &DAT_006abe14;
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
    piVar2 = &DAT_006a08e8;
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


// ==== 0x5d6598 FUN_005d6598

void __fastcall FUN_005d6598(undefined4 *param_1)

{
  param_1[3] = 0;
  param_1[2] = 0;
  *param_1 = &PTR_FUN_006a074c;
  param_1[1] = 1;
  return;
}


// ==== 0x5d65b0 FUN_005d65b0

int FUN_005d65b0(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    iVar1 = -0x7789f794;
  }
  else {
    pvVar2 = _malloc(0x10);
    if (pvVar2 == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_005d6598();
    }
    if (piVar3 == (int *)0x0) {
      iVar1 = -0x7ff8fff2;
    }
    else {
      iVar1 = (**(code **)(*piVar3 + 0x18))(param_1);
      if (iVar1 < 0) {
        (**(code **)(*piVar3 + 0x14))(1);
      }
      else {
        *param_2 = piVar3;
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


// ==== 0x5d660e thunk_FUN_005d65b0

int thunk_FUN_005d65b0(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    iVar1 = -0x7789f794;
  }
  else {
    pvVar2 = _malloc(0x10);
    if (pvVar2 == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_005d6598();
    }
    if (piVar3 == (int *)0x0) {
      iVar1 = -0x7ff8fff2;
    }
    else {
      iVar1 = (**(code **)(*piVar3 + 0x18))(param_1);
      if (iVar1 < 0) {
        (**(code **)(*piVar3 + 0x14))(1);
      }
      else {
        *param_2 = piVar3;
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


// ==== 0x5d6613 FUN_005d6613

void __fastcall FUN_005d6613(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ==== 0x5d6620 FUN_005d6620

void __fastcall FUN_005d6620(undefined4 *param_1)

{
  if ((HGDIOBJ)*param_1 != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)*param_1);
  }
  return;
}


// ==== 0x5d662e FUN_005d662e

void FUN_005d662e(undefined4 *param_1)

{
  param_1[2] = FUN_005eb251;
  param_1[0x22] = FUN_005eb251;
  *param_1 = FUN_005eb185;
  param_1[1] = FUN_005ebce3;
  param_1[3] = FUN_005ece7a;
  param_1[4] = FUN_005ed863;
  param_1[5] = FUN_005eb21a;
  param_1[6] = FUN_005ed576;
  param_1[9] = FUN_005eb1c3;
  param_1[10] = FUN_005ed64b;
  param_1[7] = FUN_005ebdb7;
  param_1[8] = FUN_005eb3dd;
  param_1[0x15] = FUN_005ed74e;
  param_1[0x10] = FUN_005eb31d;
  param_1[0x14] = FUN_005e9968;
  param_1[0x13] = FUN_005e98ef;
  param_1[0x18] = FUN_005e9b42;
  param_1[0x19] = FUN_005e9a80;
  param_1[0x16] = FUN_005eb91e;
  param_1[0x12] = FUN_005ecfae;
  param_1[0x31] = FUN_005eb653;
  param_1[0x32] = FUN_005eb477;
  param_1[0x33] = FUN_005eb826;
  param_1[0x34] = FUN_005eb706;
  param_1[0x35] = FUN_005eb5ae;
  param_1[0x36] = FUN_005eb883;
  param_1[0x11] = FUN_005eb7a0;
  param_1[0x2f] = FUN_005eb529;
  param_1[0x30] = FUN_005eb8cc;
  param_1[0xb] = FUN_005eb9cc;
  param_1[0x1b] = FUN_005ebea7;
  param_1[0xd] = FUN_005ebad7;
  param_1[0x1c] = FUN_005ebbd7;
  param_1[0x3a] = FUN_005eb0b1;
  param_1[0x45] = FUN_005eaa2f;
  param_1[0x3b] = FUN_005e9fec;
  param_1[0x3c] = FUN_005ea17a;
  param_1[0x3d] = FUN_005ea2e0;
  param_1[0x3e] = FUN_005e9de6;
  param_1[0x3f] = FUN_005ea7fe;
  param_1[0x40] = FUN_005ea62e;
  param_1[0x41] = FUN_005ea3f0;
  param_1[0x44] = FUN_005ea3f0;
  param_1[0x2c] = FUN_005e9a02;
  return;
}


// ==== 0x5d679c FUN_005d679c

void FUN_005d679c(undefined4 *param_1)

{
  param_1[2] = FUN_005eb251;
  param_1[0x22] = FUN_005eb251;
  *param_1 = FUN_005eb185;
  param_1[1] = FUN_005ebce3;
  param_1[3] = FUN_005ece7a;
  param_1[4] = FUN_005ed863;
  param_1[5] = FUN_005eb21a;
  param_1[6] = FUN_005ed576;
  param_1[9] = FUN_005eb1c3;
  param_1[10] = FUN_005ed64b;
  param_1[7] = FUN_005ebdb7;
  param_1[8] = FUN_005eb3dd;
  param_1[0x15] = FUN_005ed74e;
  param_1[0x10] = FUN_005ed2aa;
  param_1[0x14] = FUN_005e9968;
  param_1[0x13] = FUN_005e98ef;
  param_1[0x18] = FUN_005edd20;
  param_1[0x19] = FUN_005edc5e;
  param_1[0x16] = FUN_005eb91e;
  param_1[0x12] = FUN_005ecfae;
  param_1[0x31] = FUN_005eb653;
  param_1[0x32] = FUN_005eb477;
  param_1[0x33] = FUN_005eb826;
  param_1[0x34] = FUN_005eb706;
  param_1[0x35] = FUN_005eb5ae;
  param_1[0x36] = FUN_005eb883;
  param_1[0x11] = FUN_005eb7a0;
  param_1[0x2f] = FUN_005eb529;
  param_1[0x30] = FUN_005eb8cc;
  param_1[0xb] = FUN_005eb9cc;
  param_1[0x1b] = FUN_005eda97;
  param_1[0xd] = FUN_005ed36a;
  param_1[0x1c] = FUN_005ed46a;
  param_1[0x3a] = FUN_005ecda8;
  param_1[0x45] = FUN_005eaa2f;
  param_1[0x3b] = FUN_005ec274;
  param_1[0x3c] = FUN_005ec402;
  param_1[0x3d] = FUN_005ec568;
  param_1[0x3e] = FUN_005ec06e;
  param_1[0x3f] = FUN_005eca86;
  param_1[0x40] = FUN_005ec8b6;
  param_1[0x41] = FUN_005ec678;
  param_1[0x44] = FUN_005ec678;
  return;
}


// ==== 0x5d6900 FUN_005d6900

/* WARNING: Removing unreachable block (ram,0x005d698e) */
/* WARNING: Removing unreachable block (ram,0x005d697c) */
/* WARNING: Removing unreachable block (ram,0x005d6950) */
/* WARNING: Removing unreachable block (ram,0x005d6934) */
/* WARNING: Removing unreachable block (ram,0x005d6929) */

undefined8 FUN_005d6900(void)

{
  char cVar1;
  undefined4 *puVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int *piVar7;
  char local_2c [16];
  int local_1c;
  uint local_18;
  int local_14;
  char cStack_10;
  undefined4 local_c;
  uint local_8;
  
  cStack_10 = '\0';
  builtin_strncpy(local_2c,"AuthenticAMD",0xd);
  cpuid_basic_info(0);
  local_8 = 1;
  piVar7 = (int *)cpuid_basic_info(0);
  local_18 = piVar7[2];
  local_1c = piVar7[1];
  local_14 = piVar7[3];
  if (*piVar7 != 0) {
    puVar2 = (undefined4 *)cpuid_Version_info(1);
    local_c = *puVar2;
    local_8 = -(uint)((puVar2[2] & 0x800000) != 0) & 0x20 | 3 |
              -(uint)((puVar2[2] & 0x2000000) != 0) & 0x40;
    puVar3 = (uint *)cpuid(0x80000000);
    local_18 = puVar3[2];
    if (0x80000000 < *puVar3) {
      iVar5 = cpuid(0x80000001);
      local_18 = *(uint *)(iVar5 + 8);
      local_8 = local_8 | 4 | -(uint)((local_18 & 0x80000000) != 0) & 0x80;
      iVar5 = 0xc;
      pcVar6 = local_2c;
      piVar7 = &local_1c;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        iVar4 = *piVar7;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        piVar7 = (int *)((int)piVar7 + 1);
      } while (cVar1 == (char)iVar4);
      local_8 = local_8 | -(uint)((local_18 & 0x40000000) != 0) & 0x100 |
                -(uint)((local_18 & 0x400000) != 0) & 0x200;
    }
  }
  return CONCAT44(local_18,local_8);
}


// ==== 0x5d69e4 FUN_005d69e4

void FUN_005d69e4(undefined4 *param_1)

{
  byte bVar1;
  byte extraout_AH;
  
  bVar1 = FUN_005d6900();
  if (((bVar1 & 0x20) != 0) && ((char)bVar1 < '\0')) {
    *param_1 = FUN_005f4cfb;
    param_1[1] = FUN_005f3f47;
    param_1[2] = FUN_005f4fbc;
    param_1[3] = FUN_005f0197;
    param_1[5] = FUN_005f4d50;
    param_1[6] = FUN_005f3fb8;
    param_1[7] = FUN_005f401f;
    param_1[8] = FUN_005f503e;
    param_1[9] = FUN_005f4d89;
    param_1[10] = thunk_FUN_005f42ad;
    param_1[0xb] = FUN_005f03c9;
    param_1[0xc] = FUN_005f53e6;
    param_1[0xd] = FUN_005f5429;
    param_1[0xe] = FUN_005f4504;
    param_1[0xf] = FUN_005f468c;
    param_1[0x10] = FUN_005f509d;
    param_1[0x11] = FUN_005f4ded;
    param_1[0x12] = FUN_005f3f2b;
    param_1[0x13] = FUN_005eecbc;
    param_1[0x14] = FUN_005eed55;
    param_1[0x15] = FUN_005f55cb;
    param_1[0x16] = FUN_005f550d;
    param_1[0x17] = FUN_005eedb2;
    param_1[0x18] = FUN_005eedf6;
    param_1[0x19] = FUN_005ef227;
    param_1[0x1a] = FUN_005f0498;
    param_1[0x1b] = FUN_005f04e8;
    param_1[0x1c] = FUN_005f05d3;
    param_1[0x1d] = FUN_005ef2ec;
    param_1[0x1e] = FUN_005f06af;
    param_1[0x1f] = FUN_005f0712;
    param_1[0x20] = FUN_005f0770;
    param_1[0x21] = FUN_005f07c9;
    param_1[0x22] = FUN_005f562f;
    param_1[0x23] = FUN_005ef358;
    param_1[0x24] = FUN_005ef48f;
    param_1[0x25] = FUN_005f0810;
    param_1[0x26] = FUN_005f08b8;
    param_1[0x27] = FUN_005f0a3f;
    param_1[0x28] = FUN_005f1bd7;
    param_1[0x29] = FUN_005f1d7c;
    param_1[0x2a] = FUN_005f22b0;
    param_1[0x2b] = FUN_005ef51c;
    param_1[0x2c] = FUN_005ef5ae;
    param_1[0x36] = FUN_005f51cf;
    param_1[0x33] = FUN_005f407e;
    param_1[0x30] = FUN_005f4e85;
    param_1[0x2e] = FUN_005f4ece;
    param_1[0x34] = FUN_005f5240;
    param_1[0x31] = FUN_005f40ef;
    param_1[0x37] = FUN_005ef612;
    param_1[0x38] = FUN_005ef6b9;
    param_1[0x35] = FUN_005f5308;
    param_1[0x2f] = FUN_005f4f11;
    param_1[0x32] = FUN_005f41c3;
    param_1[4] = FUN_005f37ff;
    param_1[0x2d] = FUN_005ef75e;
    param_1[0x3a] = FUN_005f4a40;
    param_1[0x39] = FUN_005f4b80;
    if (((extraout_AH & 1) != 0) && ((extraout_AH & 2) != 0)) {
      param_1[0xf] = FUN_005f48b2;
      param_1[0x12] = FUN_005f351d;
      param_1[0x26] = FUN_005f098a;
      param_1[0x27] = FUN_005f23c9;
      param_1[0x18] = FUN_005ef012;
    }
  }
  if ((bVar1 & 0x40) != 0) {
    param_1[0x3e] = FUN_005ee680;
    param_1[0x3f] = FUN_005ee720;
    param_1[0x40] = FUN_005eea40;
    param_1[0x3b] = FUN_005ee000;
    param_1[0x3c] = FUN_005ee260;
    param_1[0x3d] = FUN_005ee4c0;
    param_1[0x41] = FUN_005edf40;
    param_1[0x44] = FUN_005ede80;
  }
  return;
}


// ==== 0x5d6c72 FUN_005d6c72

float * FUN_005d6c72(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  
  fVar1 = *param_2;
  fVar2 = param_3[2];
  fVar3 = *param_2;
  fVar4 = param_3[1];
  fVar5 = *param_2;
  fVar6 = param_3[3];
  fVar7 = param_2[1];
  fVar8 = param_3[6];
  fVar9 = param_2[1];
  fVar10 = param_3[5];
  fVar11 = param_2[1];
  fVar12 = param_3[7];
  fVar13 = param_3[0xd];
  fVar14 = param_3[0xe];
  fVar15 = param_3[0xf];
  *param_1 = param_3[0xc] + param_2[1] * param_3[4] + *param_2 * *param_3;
  param_1[1] = fVar13 + fVar9 * fVar10 + fVar3 * fVar4;
  param_1[2] = fVar14 + fVar7 * fVar8 + fVar1 * fVar2;
  param_1[3] = fVar15 + fVar11 * fVar12 + fVar5 * fVar6;
  return param_1;
}


// ==== 0x5d6cdb FUN_005d6cdb

float * FUN_005d6cdb(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *param_2;
  fVar2 = param_3[1];
  fVar3 = param_2[1];
  fVar4 = param_3[5];
  *param_1 = param_2[1] * param_3[4] + *param_2 * *param_3;
  param_1[1] = fVar3 * fVar4 + fVar1 * fVar2;
  return param_1;
}


// ==== 0x5d6d10 FUN_005d6d10

float * FUN_005d6d10(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  
  fVar1 = *param_2;
  fVar2 = param_3[2];
  fVar3 = *param_2;
  fVar4 = param_3[1];
  fVar5 = *param_2;
  fVar6 = param_3[3];
  fVar7 = param_2[1];
  fVar8 = param_3[6];
  fVar9 = param_2[1];
  fVar10 = param_3[5];
  fVar11 = param_2[1];
  fVar12 = param_3[7];
  fVar13 = param_2[2];
  fVar14 = param_3[10];
  fVar15 = param_2[2];
  fVar16 = param_3[9];
  fVar17 = param_2[2];
  fVar18 = param_3[0xb];
  fVar19 = param_3[0xd];
  fVar20 = param_3[0xe];
  fVar21 = param_3[0xf];
  *param_1 = param_3[0xc] + param_2[2] * param_3[8] + param_2[1] * param_3[4] + *param_2 * *param_3;
  param_1[1] = fVar19 + fVar15 * fVar16 + fVar9 * fVar10 + fVar3 * fVar4;
  param_1[2] = fVar20 + fVar13 * fVar14 + fVar7 * fVar8 + fVar1 * fVar2;
  param_1[3] = fVar21 + fVar17 * fVar18 + fVar11 * fVar12 + fVar5 * fVar6;
  return param_1;
}


// ==== 0x5d6d9b FUN_005d6d9b

float * FUN_005d6d9b(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  fVar1 = *param_2;
  fVar2 = param_3[1];
  fVar3 = *param_2;
  fVar4 = param_3[2];
  fVar5 = param_2[1];
  fVar6 = param_3[5];
  fVar7 = param_2[1];
  fVar8 = param_3[6];
  fVar9 = param_2[2];
  fVar10 = param_3[9];
  fVar11 = param_2[2];
  fVar12 = param_3[10];
  *param_1 = param_2[2] * param_3[8] + param_2[1] * param_3[4] + *param_2 * *param_3;
  param_1[1] = fVar9 * fVar10 + fVar5 * fVar6 + fVar1 * fVar2;
  param_1[2] = fVar11 * fVar12 + fVar7 * fVar8 + fVar3 * fVar4;
  return param_1;
}


// ==== 0x5d6dfa FUN_005d6dfa

float * FUN_005d6dfa(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  
  fVar1 = *param_2;
  fVar2 = param_3[2];
  fVar3 = *param_2;
  fVar4 = param_3[1];
  fVar5 = *param_2;
  fVar6 = param_3[3];
  fVar7 = param_2[1];
  fVar8 = param_3[6];
  fVar9 = param_2[1];
  fVar10 = param_3[5];
  fVar11 = param_2[1];
  fVar12 = param_3[7];
  fVar13 = param_2[2];
  fVar14 = param_3[10];
  fVar15 = param_2[2];
  fVar16 = param_3[9];
  fVar17 = param_2[2];
  fVar18 = param_3[0xb];
  fVar19 = param_2[3];
  fVar20 = param_3[0xe];
  fVar21 = param_2[3];
  fVar22 = param_3[0xd];
  fVar23 = param_2[3];
  fVar24 = param_3[0xf];
  *param_1 = param_2[3] * param_3[0xc] +
             param_2[2] * param_3[8] + param_2[1] * param_3[4] + *param_2 * *param_3;
  param_1[1] = fVar21 * fVar22 + fVar15 * fVar16 + fVar9 * fVar10 + fVar3 * fVar4;
  param_1[2] = fVar19 * fVar20 + fVar13 * fVar14 + fVar7 * fVar8 + fVar1 * fVar2;
  param_1[3] = fVar23 * fVar24 + fVar17 * fVar18 + fVar11 * fVar12 + fVar5 * fVar6;
  return param_1;
}


// ==== 0x5d6e93 FUN_005d6e93

float * FUN_005d6e93(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  float10 fVar5;
  
  fVar5 = (float10)*param_2 * (float10)*param_2 + (float10)param_2[1] * (float10)param_2[1] +
          (float10)param_2[2] * (float10)param_2[2];
  fVar1 = (float)fVar5;
  if (fVar1 == 0.0) {
    ffree(fVar5);
    *param_1 = 0.0;
    param_1[1] = 0.0;
    param_1[2] = 0.0;
  }
  else if ((uint)ABS((float)(fVar5 - (float10)1)) < 0x3727c5ad) {
    if (param_1 != param_2) {
      *param_1 = *param_2;
      param_1[1] = param_2[1];
      param_1[2] = param_2[2];
    }
  }
  else {
    uVar4 = (uint)fVar1 >> 0xc & 0xff8;
    fVar3 = ((float)((uint)fVar1 & 0xffffff | 0x3f000000) * *(float *)(&DAT_006dd610 + uVar4) +
            *(float *)(&DAT_006dd614 + uVar4)) * (float)(0xbeffffffU - (int)fVar1 >> 1 & 0xff800000)
    ;
    fVar1 = param_2[1];
    fVar2 = param_2[2];
    *param_1 = *param_2 * fVar3;
    param_1[1] = fVar1 * fVar3;
    param_1[2] = fVar2 * fVar3;
  }
  return param_1;
}


// ==== 0x5d6f5d FUN_005d6f5d

void FUN_005d6f5d(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  float local_44 [16];
  
  if (param_3 == param_1) {
    if (param_2 != param_1) {
      iVar6 = -4;
      do {
        iVar5 = -0x10;
        fVar1 = param_3[iVar6 + 4];
        fVar2 = param_3[iVar6 + 8];
        fVar3 = param_3[iVar6 + 0xc];
        fVar4 = param_3[iVar6 + 0x10];
        do {
          param_1[iVar5 + 0x10] =
               (float)((float10)fVar4 * (float10)param_2[iVar5 + 0x13] +
                       (float10)fVar2 * (float10)param_2[iVar5 + 0x11] +
                      (float10)fVar1 * (float10)param_2[iVar5 + 0x10] +
                      (float10)fVar3 * (float10)param_2[iVar5 + 0x12]);
          iVar5 = iVar5 + 4;
        } while (iVar5 != 0);
        ffree((float10)fVar1);
        ffree((float10)fVar2);
        ffree((float10)fVar3);
        ffree((float10)fVar4);
        param_1 = param_1 + 1;
        iVar6 = iVar6 + 1;
      } while (iVar6 != 0);
      return;
    }
    pfVar7 = local_44;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *pfVar7 = *param_3;
      param_3 = param_3 + 1;
      pfVar7 = pfVar7 + 1;
    }
    param_3 = local_44;
  }
  iVar6 = -4;
  do {
    iVar5 = -4;
    fVar1 = *param_2;
    fVar2 = param_2[1];
    fVar3 = param_2[2];
    fVar4 = param_2[3];
    do {
      param_1[iVar5 + 4] =
           (float)((float10)fVar4 * (float10)param_3[iVar5 + 0x10] +
                   (float10)fVar2 * (float10)param_3[iVar5 + 8] +
                  (float10)fVar1 * (float10)param_3[iVar5 + 4] +
                  (float10)fVar3 * (float10)param_3[iVar5 + 0xc]);
      iVar5 = iVar5 + 1;
    } while (iVar5 != 0);
    ffree((float10)fVar1);
    ffree((float10)fVar2);
    ffree((float10)fVar3);
    ffree((float10)fVar4);
    param_2 = param_2 + 4;
    param_1 = param_1 + 4;
    iVar6 = iVar6 + 1;
  } while (iVar6 != 0);
  return;
}


// ==== 0x5d7040 FUN_005d7040

void FUN_005d7040(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  float local_48 [17];
  
  if ((param_1 == param_2) || (pfVar5 = param_1, param_1 == param_3)) {
    pfVar5 = local_48;
  }
  iVar8 = -4;
  do {
    iVar7 = -4;
    pfVar6 = pfVar5 + iVar8 + 4;
    fVar1 = *param_2;
    fVar2 = param_2[1];
    fVar3 = param_2[2];
    fVar4 = param_2[3];
    do {
      *pfVar6 = (float)((float10)fVar4 * (float10)param_3[iVar7 + 0x10] +
                        (float10)fVar2 * (float10)param_3[iVar7 + 8] +
                       (float10)fVar1 * (float10)param_3[iVar7 + 4] +
                       (float10)fVar3 * (float10)param_3[iVar7 + 0xc]);
      pfVar6 = pfVar6 + 4;
      iVar7 = iVar7 + 1;
    } while (iVar7 != 0);
    ffree((float10)fVar1);
    ffree((float10)fVar2);
    ffree((float10)fVar3);
    ffree((float10)fVar4);
    param_2 = param_2 + 4;
    iVar8 = iVar8 + 1;
  } while (iVar8 != 0);
  if (pfVar5 != param_1) {
    for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *param_1 = *pfVar5;
      pfVar5 = pfVar5 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}


// ==== 0x5d70ce FUN_005d70ce

void FUN_005d70ce(undefined4 *param_1)

{
  *param_1 = FUN_005d6c72;
  param_1[1] = FUN_005d6d10;
  param_1[2] = FUN_005d6dfa;
  param_1[3] = FUN_005d6f5d;
  param_1[4] = FUN_005d7040;
  param_1[5] = FUN_005d6cdb;
  param_1[6] = FUN_005d6d9b;
  param_1[7] = FUN_005d6e93;
  param_1[0x22] = FUN_005d6dfa;
  return;
}


// ==== 0x5d7113 FUN_005d7113

undefined4 FUN_005d7113(uint *param_1,uint param_2,undefined4 *param_3,int *param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
  }
  if (param_1 == (uint *)0x0) {
    uVar2 = 0x8876086c;
  }
  else {
    uVar3 = *param_1 & 0xffff0000;
    puVar4 = param_1;
    if (((((uVar3 == 0x46580000) || (uVar3 == 0x54580000)) || (uVar3 == 0x7ffe0000)) ||
        ((uVar3 == 0x7fff0000 || (uVar3 == 0xfffe0000)))) || (uVar3 == 0xffff0000)) {
      do {
        while( true ) {
          do {
            puVar1 = puVar4;
            puVar4 = puVar1 + 1;
            uVar3 = *puVar4;
          } while ((int)uVar3 < 0);
          uVar5 = uVar3 & 0xffff;
          if (uVar5 == 0xffff) {
            return 1;
          }
          if (uVar5 != 0xfffe) break;
          uVar3 = uVar3 >> 0x10 & 0x7fff;
          if ((1 < uVar3) && (param_2 == puVar1[2])) {
            if (param_3 != (undefined4 *)0x0) {
              *param_3 = puVar1 + 3;
            }
            if (param_4 != (int *)0x0) {
              *param_4 = uVar3 * 4 + -4;
            }
            return 0;
          }
LAB_005d71de:
          puVar4 = puVar4 + uVar3;
        }
        if (0x1ff < (*param_1 & 0xffff)) {
          uVar3 = uVar3 >> 0x18 & 0xf;
          goto LAB_005d71de;
        }
        if (uVar5 == 0x51) {
          puVar4 = puVar1 + 6;
        }
      } while( true );
    }
    uVar2 = 0x88760b59;
  }
  return uVar2;
}


// ==== 0x5d71f8 FUN_005d71f8

undefined4 FUN_005d71f8(uint *param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  char local_1c [8];
  uint local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  puVar7 = param_1;
  if (param_1 == (uint *)0x0) {
    return 0x8876086c;
  }
  param_1 = (uint *)0x0;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  local_14 = *puVar7;
  uVar4 = local_14 & 0xffff0000;
  if (uVar4 != 0x46580000) {
    if (uVar4 == 0xfffe0000) {
      bVar3 = *(byte *)((int)puVar7 + 1);
      while( true ) {
        do {
          puVar5 = puVar7;
          puVar7 = puVar5 + 1;
        } while ((int)*puVar7 < 0);
        if (((*puVar7 & 0xffff) == 0x1f) &&
           ((puVar5[3] >> 0x14 & 0x700 | puVar5[3] & 0x1800) == 0x100)) {
          if (param_2 != 0) {
            *(uint *)((int)param_1 * 8 + param_2) = puVar5[2] & 0xffff;
            *(uint *)((int)param_1 * 8 + 4 + param_2) = *(ushort *)((int)puVar5 + 10) & 0x7fff;
          }
          param_1 = (uint *)((int)param_1 + 1);
        }
        uVar4 = *puVar7;
        uVar6 = uVar4 & 0xffff;
        if (uVar6 == 0xffff) break;
        if (uVar6 == 0xfffe) {
          uVar4 = uVar4 >> 0x10 & 0x7fff;
LAB_005d759b:
          puVar7 = puVar7 + uVar4;
        }
        else {
          if (1 < bVar3) {
            uVar4 = uVar4 >> 0x18 & 0xf;
            goto LAB_005d759b;
          }
          if (uVar6 == 0x51) {
            puVar7 = puVar5 + 6;
          }
        }
      }
    }
    else {
      if (uVar4 != 0xffff0000) {
        return 0x88760b59;
      }
      cVar2 = *(char *)((int)puVar7 + 1);
      if (cVar2 == '\x03') {
        while( true ) {
          puVar5 = puVar7 + 1;
          if (((*puVar5 & 0xffff) == 0x1f) &&
             ((puVar7[3] >> 0x14 & 0x700 | puVar7[3] & 0x1800) == 0x100)) {
            if (param_2 != 0) {
              *(uint *)((int)param_1 * 8 + param_2) = puVar7[2] & 0xffff;
              *(uint *)((int)param_1 * 8 + 4 + param_2) = *(ushort *)((int)puVar7 + 10) & 0x7fff;
            }
            param_1 = (uint *)((int)param_1 + 1);
          }
          uVar4 = *puVar5;
          if ((uVar4 & 0xffff) == 0xffff) break;
          if ((uVar4 & 0xffff) == 0xfffe) {
            uVar4 = uVar4 >> 0x10 & 0x7fff;
          }
          else {
            uVar4 = uVar4 >> 0x18 & 0xf;
          }
          puVar7 = puVar5 + uVar4;
        }
      }
      else {
        if (cVar2 == '\x02') {
          do {
            puVar5 = puVar7 + 1;
            if ((*puVar5 & 0xffff) == 0x1f) {
              uVar6 = puVar7[3] & 0x7ff;
              uVar4 = puVar7[3] & 0xf0001800;
              if (param_2 == 0) {
LAB_005d7350:
                if (uVar4 == 0xa0000800) goto LAB_005d735a;
              }
              else if (uVar4 == 0xb0000000) {
                *(undefined4 *)((int)param_1 * 8 + param_2) = 5;
                *(uint *)((int)param_1 * 8 + 4 + param_2) = uVar6;
              }
              else {
                if (uVar4 != 0x90000000) {
                  if (uVar4 != 0xa0000800) {
                    return 0x80004005;
                  }
                  goto LAB_005d7350;
                }
                if (1 < uVar6) {
                  return 0x80004005;
                }
                *(undefined4 *)((int)param_1 * 8 + 4 + param_2) = 0;
                *(undefined4 *)((int)param_1 * 8 + param_2) = 10;
              }
              param_1 = (uint *)((int)param_1 + 1);
            }
LAB_005d735a:
            uVar4 = *puVar5;
            if ((uVar4 & 0xffff) == 0xffff) goto LAB_005d74f4;
            if ((uVar4 & 0xffff) == 0xfffe) {
              uVar4 = uVar4 >> 0x10 & 0x7fff;
            }
            else {
              uVar4 = uVar4 >> 0x18 & 0xf;
            }
            puVar7 = puVar5 + uVar4;
          } while( true );
        }
        if (cVar2 != '\x01') {
          return 0x80004005;
        }
        local_1c[0] = '\0';
        local_1c[1] = '\0';
        local_1c[2] = '\0';
        local_1c[3] = '\0';
        local_1c[4] = '\0';
        local_1c[5] = '\0';
        local_c = 0;
        local_10 = 0;
        local_8 = (uint)((char)local_14 == '\x04');
        while( true ) {
          while( true ) {
            puVar5 = puVar7;
            puVar7 = puVar5 + 1;
            uVar4 = *puVar7;
            if (-1 < (int)uVar4) break;
            if ((uVar4 & 0xf0001800) == 0x90000000) {
              if ((uVar4 & 0x7ff) == 0) {
                local_c = 1;
              }
              else if ((uVar4 & 0x7ff) == 1) {
                local_10 = 1;
              }
            }
            if ((local_8 != 0) && ((uVar4 & 0xf0001800) == 0xb0000000)) {
              local_1c[uVar4 & 0x7ff] = '\x01';
            }
          }
          uVar6 = uVar4 & 0xffff;
          if (uVar6 == 0xffff) break;
          if (uVar6 == 0xfffe) {
            uVar4 = uVar4 >> 0x10 & 0x7fff;
LAB_005d747e:
            puVar7 = puVar7 + uVar4;
          }
          else {
            if ((((local_8 == 0) && (0x3f < uVar6)) &&
                ((uVar6 < 0x4b ||
                 ((0x4b < uVar6 && ((uVar6 < 0x4e || ((0x51 < uVar6 && (uVar6 < 0x58)))))))))) &&
               ((puVar5[2] & 0xf0001800) == 0xb0000000)) {
              local_1c[puVar5[2] & 0x7ff] = '\x01';
            }
            if (0x1ff < (local_14 & 0xffff)) {
              uVar4 = uVar4 >> 0x18 & 0xf;
              goto LAB_005d747e;
            }
            if (uVar6 == 0x51) {
              puVar7 = puVar5 + 6;
            }
          }
        }
        uVar4 = 0;
        do {
          if (local_1c[uVar4] != '\0') {
            if (param_2 != 0) {
              *(undefined4 *)((int)param_1 * 8 + param_2) = 5;
              *(uint *)((int)param_1 * 8 + 4 + param_2) = uVar4;
            }
            param_1 = (uint *)((int)param_1 + 1);
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < 6);
        if (local_c != 0) {
          if (param_2 != 0) {
            puVar1 = (undefined4 *)(param_2 + (int)param_1 * 8);
            *puVar1 = 10;
            puVar1[1] = 0;
          }
          param_1 = (uint *)((int)param_1 + 1);
        }
        if (local_10 != 0) {
          if (param_2 != 0) {
            puVar1 = (undefined4 *)(param_2 + (int)param_1 * 8);
            *puVar1 = 10;
            puVar1[1] = 1;
          }
          param_1 = (uint *)((int)param_1 + 1);
        }
      }
    }
LAB_005d74f4:
    if (param_3 != (int *)0x0) {
      *param_3 = (int)param_1;
    }
  }
  return 0;
}


// ==== 0x5d75b0 FUN_005d75b0

int FUN_005d75b0(uint *param_1,int param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int local_8;
  
  piVar4 = param_3;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  uVar1 = *param_1 & 0xffff0000;
  if ((uVar1 == 0x46580000) || (uVar1 == 0xfffe0000)) {
LAB_005d765c:
    iVar2 = 0;
  }
  else {
    if (uVar1 == 0xffff0000) {
      local_8 = 0;
      iVar2 = FUN_005d7113(param_1,0x42415443,&local_8,&param_1);
      if (iVar2 < 0) {
        return iVar2;
      }
      if (local_8 == 0) goto LAB_005d765c;
      if ((uint *)0x13 < param_1) {
        puVar3 = (undefined4 *)(*(int *)(local_8 + 0x10) + local_8);
        if ((uint *)((*(int *)(local_8 + 0xc) * 5 + 5) * 4) <= param_1) {
          iVar2 = 0;
          uVar1 = 0;
          if (*(int *)(local_8 + 0xc) != 0) {
            do {
              if (*(short *)(puVar3 + 1) == 3) {
                if ((param_1 <= (uint *)*puVar3) || (iVar2 == 0x10)) goto LAB_005d75e3;
                *(int *)(param_2 + iVar2 * 4) = (int)*puVar3 + local_8;
                iVar2 = iVar2 + 1;
                piVar4 = param_3;
              }
              uVar1 = uVar1 + 1;
              puVar3 = puVar3 + 5;
            } while (uVar1 < *(uint *)(local_8 + 0xc));
          }
          if (piVar4 != (int *)0x0) {
            *piVar4 = iVar2;
          }
          goto LAB_005d765c;
        }
      }
    }
LAB_005d75e3:
    iVar2 = -0x7789f4a7;
  }
  return iVar2;
}


// ==== 0x5d7665 FUN_005d7665

int FUN_005d7665(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 local_1c;
  undefined4 uStack_18;
  int local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 *local_8;
  
  puVar2 = param_2;
  piVar1 = param_1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  if ((param_1 == (int *)0x0) || (param_2 == (undefined4 *)0x0)) {
    iVar3 = -0x7789f794;
  }
  else {
    iVar3 = FUN_005d7113(param_1,0x42415443,&local_8,&param_2);
    if (-1 < iVar3) {
      puVar6 = local_8;
      if (iVar3 == 1) {
        local_14 = *piVar1;
        uStack_18 = 0;
        uStack_10 = 0;
        uStack_c = 0;
        local_1c = 0x14;
        param_2 = (undefined4 *)0x14;
        puVar6 = &local_1c;
      }
      iVar3 = FUN_005f70e0(param_2,&param_1);
      if (-1 < iVar3) {
        puVar4 = (undefined4 *)(**(code **)(*param_1 + 0xc))(param_1);
        for (uVar5 = (uint)param_2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar4 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar4 = puVar4 + 1;
        }
        for (uVar5 = (uint)param_2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined1 *)puVar4 = *(undefined1 *)puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
        *puVar2 = param_1;
        iVar3 = 0;
      }
    }
  }
  return iVar3;
}


// ==== 0x5d7700 FUN_005d7700

undefined4 FUN_005d7700(byte *param_1,uint param_2,undefined4 *param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  uint local_8;
  
  uVar5 = 0;
  if (param_1 == (byte *)0x0) {
    uVar2 = 0x8876086c;
  }
  else {
    local_8 = 0x26;
    do {
      uVar3 = local_8 + uVar5 >> 1;
      pbVar6 = *(byte **)(&UNK_006a08f8 + uVar3 * 0xc);
      pbVar7 = param_1;
      do {
        bVar1 = *pbVar6;
        bVar8 = bVar1 < *pbVar7;
        if (bVar1 != *pbVar7) {
LAB_005d774e:
          iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_005d7753;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar6[1];
        bVar8 = bVar1 < pbVar7[1];
        if (bVar1 != pbVar7[1]) goto LAB_005d774e;
        pbVar6 = pbVar6 + 2;
        pbVar7 = pbVar7 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_005d7753:
      if (iVar4 == 0) {
        iVar4 = uVar3 * 0xc;
        if ((*(uint *)(&DAT_006a0900 + iVar4) & param_2) == param_2) {
          if (param_3 != (undefined4 *)0x0) {
            *param_3 = *(undefined4 *)(&UNK_006a08f8 + iVar4);
            param_3[1] = *(undefined4 *)(&UNK_006a08fc + iVar4);
            param_3[2] = *(undefined4 *)(&DAT_006a0900 + iVar4);
          }
          return 0;
        }
        break;
      }
      if (iVar4 < 0) {
        uVar5 = uVar3 + 1;
        uVar3 = local_8;
      }
      local_8 = uVar3;
    } while (uVar5 < local_8);
    uVar2 = 0x80004005;
  }
  return uVar2;
}


// ==== 0x5d779c FUN_005d779c

undefined4 FUN_005d779c(uint param_1,uint param_2,undefined4 *param_3)

{
  uint *puVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = 0x26;
  pcVar2 = "vs_3_0";
  while( true ) {
    puVar1 = (uint *)((int)pcVar2 + -0x10);
    pcVar2 = (char *)((int)pcVar2 + -0xc);
    iVar3 = iVar3 + -1;
    if ((*puVar1 == param_1) && ((*(uint *)pcVar2 & param_2) == param_2)) break;
    if (pcVar2 < &UNK_006a0901) {
      return 0x80004005;
    }
  }
  if (param_3 != (undefined4 *)0x0) {
    iVar3 = iVar3 * 0xc;
    *param_3 = *(undefined4 *)(&UNK_006a08f8 + iVar3);
    param_3[1] = *(undefined4 *)(&UNK_006a08fc + iVar3);
    param_3[2] = *(undefined4 *)(&DAT_006a0900 + iVar3);
  }
  return 0;
}


// ==== 0x5d77e9 FUN_005d77e9

void __thiscall FUN_005d77e9(undefined4 *param_1,undefined4 param_2)

{
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_006a0be4;
  param_1[1] = param_2;
  return;
}


// ==== 0x5d7803 FUN_005d7803

void __fastcall FUN_005d7803(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[2];
  *param_1 = &PTR_FUN_006a0be4;
  if (puVar1 == (undefined4 *)0x0) goto LAB_005d7828;
  while( true ) {
    (**(code **)*puVar1)(1);
LAB_005d7828:
    if (param_1[3] == 0) break;
    puVar1 = (undefined4 *)param_1[3];
    param_1[3] = puVar1[3];
    puVar1[3] = 0;
  }
  return;
}


// ==== 0x5d7830 FUN_005d7830

bool __thiscall FUN_005d7830(int param_1,int param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if (param_2 != 0) {
    bVar1 = *(int *)(param_2 + 4) == *(int *)(param_1 + 4);
  }
  return bVar1;
}


// ==== 0x5d7846 FUN_005d7846

undefined4 __fastcall FUN_005d7846(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = _malloc(0x10);
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_005d77e9(*(undefined4 *)(param_1 + 4));
    return uVar2;
  }
  return 0;
}


// ==== 0x5d7865 FUN_005d7865

void FUN_005d7865(void)

{
  return;
}


// ==== 0x5d7866 FUN_005d7866

uint FUN_005d7866(int *param_1,int param_2)

{
  uint uVar1;
  
  if (param_1 == (int *)0x0) {
    uVar1 = (uint)(param_2 == 0);
  }
  else {
    uVar1 = (**(code **)(*param_1 + 4))(param_2);
  }
  return uVar1;
}


// ==== 0x5d7885 FUN_005d7885

undefined4 FUN_005d7885(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*param_1 + 8))();
  }
  return uVar1;
}


// ==== 0x5d7899 FUN_005d7899

int FUN_005d7899(int param_1,int param_2)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = &param_1;
    do {
      piVar1 = (int *)(*piVar1 + 0xc);
    } while (*piVar1 != 0);
    *piVar1 = param_2;
    param_2 = param_1;
  }
  return param_2;
}


// ==== 0x5d78c0 FUN_005d78c0

void __fastcall FUN_005d78c0(undefined4 *param_1)

{
  param_1[1] = 1;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_006a0bf4;
  param_1[4] = 0;
  return;
}


// ==== 0x5d78db FUN_005d78db

void __thiscall
FUN_005d78db(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  param_1[2] = param_2;
  param_1[3] = param_3;
  param_1[1] = 1;
  *param_1 = &PTR_FUN_006a0bf4;
  param_1[4] = param_4;
  return;
}


// ==== 0x5d7902 FUN_005d7902

undefined4 FUN_005d7902(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  
  iVar1 = FUN_005d7830(param_1);
  uVar3 = 0;
  iVar2 = extraout_ECX;
  if (iVar1 != 0) {
    for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
      if (*(int *)(iVar2 + 4) != 1) {
        iVar2 = FUN_005d7866(iVar2,param_1);
        if (iVar2 == 0) {
          return 0;
        }
        break;
      }
      if (param_1 == 0) {
        return 0;
      }
      if (*(int *)(param_1 + 4) != 1) {
        return 0;
      }
      iVar1 = FUN_005d7866(*(undefined4 *)(iVar2 + 8),*(undefined4 *)(param_1 + 8));
      if (iVar1 == 0) {
        return 0;
      }
      param_1 = *(int *)(param_1 + 0xc);
    }
    uVar3 = 1;
  }
  return uVar3;
}


// ==== 0x5d795a FUN_005d795a

int __fastcall FUN_005d795a(int *param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int local_8;
  
  local_8 = 0;
  piVar4 = &local_8;
  while( true ) {
    if (param_1 == (int *)0x0) {
      return local_8;
    }
    if (param_1[1] != 1) break;
    pvVar1 = _malloc(0x14);
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_005d78c0();
    }
    *piVar4 = iVar2;
    if (iVar2 == 0) {
      return local_8;
    }
    *(int *)(iVar2 + 0x10) = param_1[4];
    if ((int *)param_1[2] != (int *)0x0) {
      uVar3 = (**(code **)(*(int *)param_1[2] + 8))();
      *(undefined4 *)(*piVar4 + 8) = uVar3;
      if (*(int *)(*piVar4 + 8) == 0) {
        if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)*piVar4)(1);
        }
        *piVar4 = 0;
        return local_8;
      }
    }
    param_1 = (int *)param_1[3];
    piVar4 = (int *)(*piVar4 + 0xc);
  }
  iVar2 = (**(code **)(*param_1 + 8))();
  *piVar4 = iVar2;
  return local_8;
}


// ==== 0x5d79dc FUN_005d79dc

undefined4 __fastcall FUN_005d79dc(int *param_1)

{
  byte bVar1;
  int *in_EAX;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  
  iVar3 = *param_1;
  if (iVar3 != *in_EAX) {
    return 0;
  }
  if (iVar3 < 9) {
    if (4 < iVar3) {
      if (*(double *)(param_1 + 2) != *(double *)(in_EAX + 2)) {
        return 0;
      }
      return 1;
    }
    if (iVar3 != 0) {
      if (iVar3 == 1) {
        pbVar4 = (byte *)(in_EAX + 2);
        pbVar2 = (byte *)(param_1 + 2);
        do {
          bVar1 = *pbVar2;
          bVar5 = bVar1 < *pbVar4;
          if (bVar1 != *pbVar4) goto LAB_005d7a9e;
          if (bVar1 == 0) break;
          bVar1 = pbVar2[1];
          bVar5 = bVar1 < pbVar4[1];
          if (bVar1 != pbVar4[1]) goto LAB_005d7a9e;
          pbVar2 = pbVar2 + 2;
          pbVar4 = pbVar4 + 2;
        } while (bVar1 != 0);
        goto LAB_005d7a34;
      }
      if (iVar3 < 2) {
        return 1;
      }
      if (4 < iVar3) {
        return 1;
      }
    }
    bVar5 = param_1[2] == in_EAX[2];
    goto LAB_005d7a06;
  }
  if (iVar3 == 9) {
    pbVar4 = (byte *)in_EAX[2];
    pbVar2 = (byte *)param_1[2];
    do {
      bVar1 = *pbVar2;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) goto LAB_005d7a9e;
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_005d7a9e;
      pbVar2 = pbVar2 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
  }
  else {
    if (iVar3 != 10) {
      return 1;
    }
    pbVar4 = (byte *)in_EAX[2];
    pbVar2 = (byte *)param_1[2];
    do {
      bVar1 = *pbVar2;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) goto LAB_005d7a9e;
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_005d7a9e;
      pbVar2 = pbVar2 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
  }
LAB_005d7a34:
  iVar3 = 0;
LAB_005d7aa3:
  bVar5 = iVar3 == 0;
LAB_005d7a06:
  if (!bVar5) {
    return 0;
  }
  return 1;
LAB_005d7a9e:
  iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
  goto LAB_005d7aa3;
}


// ==== 0x5d7aaa FUN_005d7aaa

void __fastcall FUN_005d7aaa(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[1] = 2;
  *param_1 = &PTR_FUN_006a0c04;
  return;
}


// ==== 0x5d7ac2 FUN_005d7ac2

void __thiscall FUN_005d7ac2(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[1] = 2;
  *param_1 = &PTR_FUN_006a0c04;
  puVar2 = param_1 + 4;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== 0x5d7aec FUN_005d7aec

bool FUN_005d7aec(undefined4 param_1)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_005d7830(param_1);
  bVar2 = false;
  if (iVar1 != 0) {
    iVar1 = FUN_005d79dc();
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}


// ==== 0x5d7b0e FUN_005d7b0e

void __fastcall FUN_005d7b0e(int param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  pvVar1 = _malloc(0x30);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_005d7aaa();
  }
  if (iVar2 == 0) {
    return;
  }
  puVar4 = (undefined4 *)(param_1 + 0x10);
  puVar5 = (undefined4 *)(iVar2 + 0x10);
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  return;
}


// ==== 0x5d7b3d FUN_005d7b3d

void __fastcall FUN_005d7b3d(undefined4 *param_1)

{
  param_1[1] = 3;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_006a0c14;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  return;
}


// ==== 0x5d7b61 FUN_005d7b61

void __thiscall
FUN_005d7b61(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = param_3;
  param_1[6] = param_4;
  param_1[1] = 3;
  *param_1 = &PTR_FUN_006a0c14;
  param_1[7] = param_5;
  return;
}


// ==== 0x5d7b97 FUN_005d7b97

void __fastcall FUN_005d7b97(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a0c14;
  if ((undefined4 *)param_1[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[7])(1);
  }
  FUN_005d7803();
  return;
}


// ==== 0x5d7bb5 FUN_005d7bb5

bool FUN_005d7bb5(undefined4 param_1)

{
  int iVar1;
  int extraout_ECX;
  bool bVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_005d7830(param_1);
  iVar1 = (int)((ulonglong)uVar3 >> 0x20);
  if (((((int)uVar3 == 0) || (*(int *)(extraout_ECX + 0x10) != *(int *)(iVar1 + 0x10))) ||
      (*(int *)(extraout_ECX + 0x14) != *(int *)(iVar1 + 0x14))) ||
     (*(int *)(extraout_ECX + 0x18) != *(int *)(iVar1 + 0x18))) {
    bVar2 = false;
  }
  else {
    iVar1 = FUN_005d7866(*(undefined4 *)(extraout_ECX + 0x1c),*(undefined4 *)(iVar1 + 0x1c));
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}


// ==== 0x5d7bf3 FUN_005d7bf3

undefined4 * __fastcall FUN_005d7bf3(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x20);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d7b3d();
  }
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[4] = *(undefined4 *)(param_1 + 0x10);
    puVar2[5] = *(undefined4 *)(param_1 + 0x14);
    puVar2[6] = *(undefined4 *)(param_1 + 0x18);
    if (*(int **)(param_1 + 0x1c) == (int *)0x0) {
      return puVar2;
    }
    iVar3 = (**(code **)(**(int **)(param_1 + 0x1c) + 8))();
    puVar2[7] = iVar3;
    if (iVar3 != 0) {
      return puVar2;
    }
    (**(code **)*puVar2)(1);
  }
  return (undefined4 *)0x0;
}


// ==== 0x5d7c4a FUN_005d7c4a

void __fastcall FUN_005d7c4a(undefined4 *param_1)

{
  param_1[1] = 4;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_006a0c24;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  return;
}


// ==== 0x5d7c6e FUN_005d7c6e

void __thiscall
FUN_005d7c6e(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = param_3;
  param_1[6] = param_4;
  param_1[1] = 4;
  *param_1 = &PTR_FUN_006a0c24;
  param_1[7] = param_5;
  return;
}


// ==== 0x5d7ca4 FUN_005d7ca4

void __fastcall FUN_005d7ca4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a0c24;
  if ((undefined4 *)param_1[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[6])(1);
  }
  if ((undefined4 *)param_1[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[7])(1);
  }
  FUN_005d7803();
  return;
}


// ==== 0x5d7ccf FUN_005d7ccf

undefined4 __thiscall FUN_005d7ccf(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_005d7830(param_2);
  if ((((iVar1 != 0) && (*(int *)(param_1 + 0x10) == *(int *)(param_2 + 0x10))) &&
      (*(int *)(param_1 + 0x14) == *(int *)(param_2 + 0x14))) &&
     ((iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_2 + 0x18)),
      iVar1 != 0 &&
      (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_2 + 0x1c)),
      iVar1 != 0)))) {
    return 1;
  }
  return 0;
}


// ==== 0x5d7d1b FUN_005d7d1b

undefined4 * __fastcall FUN_005d7d1b(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x20);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d7c4a();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2[4] = *(undefined4 *)(param_1 + 0x10);
  puVar2[5] = *(undefined4 *)(param_1 + 0x14);
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 8))();
    puVar2[6] = iVar3;
    if (iVar3 == 0) goto LAB_005d7d6e;
  }
  if (*(int **)(param_1 + 0x1c) == (int *)0x0) {
    return puVar2;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x1c) + 8))();
  puVar2[7] = iVar3;
  if (iVar3 != 0) {
    return puVar2;
  }
LAB_005d7d6e:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// ==== 0x5d7d7f FUN_005d7d7f

void __fastcall FUN_005d7d7f(undefined4 *param_1)

{
  param_1[9] = 0xffffffff;
  param_1[1] = 5;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_006a0c34;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  return;
}


// ==== 0x5d7db0 FUN_005d7db0

void __thiscall
FUN_005d7db0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  param_1[9] = 0xffffffff;
  param_1[4] = param_2;
  param_1[5] = param_3;
  param_1[6] = param_4;
  param_1[1] = 5;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_006a0c34;
  param_1[7] = param_5;
  param_1[8] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  return;
}


// ==== 0x5d7df3 FUN_005d7df3

void __fastcall FUN_005d7df3(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a0c34;
  if ((undefined4 *)param_1[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[5])(1);
  }
  if ((undefined4 *)param_1[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[6])(1);
  }
  if ((undefined4 *)param_1[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[7])(1);
  }
  FUN_005d7803();
  return;
}


// ==== 0x5d7e2b FUN_005d7e2b

undefined4 __thiscall FUN_005d7e2b(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_005d7830(param_2);
  if ((((((iVar1 != 0) && (*(int *)(param_1 + 0x10) == *(int *)(param_2 + 0x10))) &&
        (*(int *)(param_1 + 0x20) == *(int *)(param_2 + 0x20))) &&
       ((*(int *)(param_1 + 0x24) == *(int *)(param_2 + 0x24) &&
        (*(int *)(param_1 + 0x28) == *(int *)(param_2 + 0x28))))) &&
      ((*(int *)(param_1 + 0x2c) == *(int *)(param_2 + 0x2c) &&
       ((iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_2 + 0x14)),
        iVar1 != 0 &&
        (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_2 + 0x18)),
        iVar1 != 0)))))) &&
     (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_2 + 0x1c)),
     iVar1 != 0)) {
    return 1;
  }
  return 0;
}


// ==== 0x5d7e9e FUN_005d7e9e

undefined4 * __fastcall FUN_005d7e9e(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x30);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d7d7f();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2[4] = *(undefined4 *)(param_1 + 0x10);
  puVar2[8] = *(undefined4 *)(param_1 + 0x20);
  puVar2[9] = *(undefined4 *)(param_1 + 0x24);
  puVar2[10] = *(undefined4 *)(param_1 + 0x28);
  puVar2[0xb] = *(undefined4 *)(param_1 + 0x2c);
  if (*(int **)(param_1 + 0x14) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x14) + 8))();
    puVar2[5] = iVar3;
    if (iVar3 == 0) goto LAB_005d7f16;
  }
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 8))();
    puVar2[6] = iVar3;
    if (iVar3 == 0) goto LAB_005d7f16;
  }
  if (*(int **)(param_1 + 0x1c) == (int *)0x0) {
    return puVar2;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x1c) + 8))();
  puVar2[7] = iVar3;
  if (iVar3 != 0) {
    return puVar2;
  }
LAB_005d7f16:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// ==== 0x5d7f27 FUN_005d7f27

void __fastcall FUN_005d7f27(undefined4 *param_1)

{
  param_1[1] = 6;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_006a0c44;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  return;
}


// ==== 0x5d7f48 FUN_005d7f48

void __thiscall
FUN_005d7f48(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = param_3;
  param_1[1] = 6;
  *param_1 = &PTR_FUN_006a0c44;
  param_1[6] = param_4;
  return;
}


// ==== 0x5d7f77 FUN_005d7f77

void __fastcall FUN_005d7f77(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a0c44;
  if ((undefined4 *)param_1[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[5])(1);
  }
  if ((undefined4 *)param_1[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[6])(1);
  }
  FUN_005d7803();
  return;
}


// ==== 0x5d7fa2 FUN_005d7fa2

undefined4 __thiscall FUN_005d7fa2(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_005d7830(param_2);
  if ((((iVar1 != 0) && (*(int *)(param_1 + 0x10) == *(int *)(param_2 + 0x10))) &&
      (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_2 + 0x14)),
      iVar1 != 0)) &&
     (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_2 + 0x18)),
     iVar1 != 0)) {
    return 1;
  }
  return 0;
}


// ==== 0x5d7fe6 FUN_005d7fe6

undefined4 * __fastcall FUN_005d7fe6(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d7f27();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2[4] = *(undefined4 *)(param_1 + 0x10);
  if (*(int **)(param_1 + 0x14) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x14) + 8))();
    puVar2[5] = iVar3;
    if (iVar3 == 0) goto LAB_005d8033;
  }
  if (*(int **)(param_1 + 0x18) == (int *)0x0) {
    return puVar2;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 8))();
  puVar2[6] = iVar3;
  if (iVar3 != 0) {
    return puVar2;
  }
LAB_005d8033:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// ==== 0x5d8044 FUN_005d8044

void __fastcall FUN_005d8044(undefined4 *param_1)

{
  param_1[1] = 7;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_006a0c54;
  param_1[4] = 0;
  param_1[5] = 0;
  return;
}


// ==== 0x5d8062 FUN_005d8062

void __thiscall FUN_005d8062(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[1] = 7;
  *param_1 = &PTR_FUN_006a0c54;
  param_1[5] = param_3;
  return;
}


// ==== 0x5d808a FUN_005d808a

void __fastcall FUN_005d808a(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a0c54;
  if ((undefined4 *)param_1[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[4])(1);
  }
  FUN_005d7803();
  return;
}


// ==== 0x5d80a8 FUN_005d80a8

bool FUN_005d80a8(undefined4 param_1)

{
  int iVar1;
  int extraout_ECX;
  bool bVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_005d7830(param_1);
  iVar1 = (int)((ulonglong)uVar3 >> 0x20);
  if (((int)uVar3 == 0) || (*(int *)(extraout_ECX + 0x14) != *(int *)(iVar1 + 0x14))) {
    bVar2 = false;
  }
  else {
    iVar1 = FUN_005d7866(*(undefined4 *)(extraout_ECX + 0x10),*(undefined4 *)(iVar1 + 0x10));
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}


// ==== 0x5d80d6 FUN_005d80d6

undefined4 * __fastcall FUN_005d80d6(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x18);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d8044();
  }
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[5] = *(undefined4 *)(param_1 + 0x14);
    if (*(int **)(param_1 + 0x10) == (int *)0x0) {
      return puVar2;
    }
    iVar3 = (**(code **)(**(int **)(param_1 + 0x10) + 8))();
    puVar2[4] = iVar3;
    if (iVar3 != 0) {
      return puVar2;
    }
    (**(code **)*puVar2)(1);
  }
  return (undefined4 *)0x0;
}


// ==== 0x5d8121 FUN_005d8121

void __fastcall FUN_005d8121(undefined4 *param_1)

{
  param_1[1] = 8;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_006a0c64;
  param_1[4] = 0;
  param_1[5] = 9;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  return;
}


// ==== 0x5d814c FUN_005d814c

void __thiscall
FUN_005d814c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = param_3;
  param_1[6] = param_4;
  param_1[7] = param_5;
  param_1[1] = 8;
  *param_1 = &PTR_FUN_006a0c64;
  param_1[8] = param_6;
  return;
}


// ==== 0x5d8188 FUN_005d8188

void __fastcall FUN_005d8188(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a0c64;
  FUN_005d7803();
  return;
}


// ==== 0x5d8193 FUN_005d8193

undefined4 FUN_005d8193(undefined4 param_1)

{
  undefined4 uVar1;
  int extraout_ECX;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_005d7830(param_1);
  iVar2 = (int)((ulonglong)uVar3 >> 0x20);
  if (((((int)uVar3 == 0) || (*(int *)(extraout_ECX + 0x10) != *(int *)(iVar2 + 0x10))) ||
      (*(int *)(extraout_ECX + 0x14) != *(int *)(iVar2 + 0x14))) ||
     (((*(int *)(extraout_ECX + 0x18) != *(int *)(iVar2 + 0x18) ||
       (*(int *)(extraout_ECX + 0x1c) != *(int *)(iVar2 + 0x1c))) ||
      (*(int *)(extraout_ECX + 0x20) != *(int *)(iVar2 + 0x20))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ==== 0x5d81d3 FUN_005d81d3

void __fastcall FUN_005d81d3(int param_1)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = _malloc(0x24);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_005d8121();
  }
  if (iVar2 == 0) {
    return;
  }
  *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(param_1 + 0x20);
  return;
}


// ==== 0x5d8213 FUN_005d8213

void __fastcall FUN_005d8213(undefined4 *param_1)

{
  param_1[1] = 9;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_006a0c74;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  return;
}


// ==== 0x5d824f FUN_005d824f

void __fastcall FUN_005d824f(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a0c74;
  if ((undefined4 *)param_1[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[7])(1);
  }
  if ((undefined4 *)param_1[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[8])(1);
  }
  if ((undefined4 *)param_1[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[9])(1);
  }
  if ((undefined4 *)param_1[10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[10])(1);
  }
  if ((undefined4 *)param_1[0xb] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb])(1);
  }
  if ((undefined4 *)param_1[0xc] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xc])(1);
  }
  if ((undefined4 *)param_1[0xd] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xd])(1);
  }
  FUN_005d7803();
  return;
}


// ==== 0x5d82b9 FUN_005d82b9

undefined4 __thiscall FUN_005d82b9(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_005d7830(param_2);
  if (((((iVar1 != 0) && (*(int *)(param_1 + 0x10) == *(int *)(param_2 + 0x10))) &&
       (*(int *)(param_1 + 0x14) == *(int *)(param_2 + 0x14))) &&
      (((*(int *)(param_1 + 0x18) == *(int *)(param_2 + 0x18) &&
        (*(int *)(param_1 + 0x38) == *(int *)(param_2 + 0x38))) &&
       ((*(int *)(param_1 + 0x3c) == *(int *)(param_2 + 0x3c) &&
        ((iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_2 + 0x1c)),
         iVar1 != 0 &&
         (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_2 + 0x20)),
         iVar1 != 0)))))))) &&
     ((iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_2 + 0x24)),
      iVar1 != 0 &&
      ((((iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_2 + 0x28)),
         iVar1 != 0 &&
         (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_2 + 0x2c)),
         iVar1 != 0)) &&
        (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_2 + 0x30)),
        iVar1 != 0)) &&
       (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_2 + 0x34)),
       iVar1 != 0)))))) {
    return 1;
  }
  return 0;
}


// ==== 0x5d8374 FUN_005d8374

undefined4 * __fastcall FUN_005d8374(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x40);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d8213();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2[4] = *(undefined4 *)(param_1 + 0x10);
  puVar2[5] = *(undefined4 *)(param_1 + 0x14);
  puVar2[6] = *(undefined4 *)(param_1 + 0x18);
  puVar2[0xe] = *(undefined4 *)(param_1 + 0x38);
  puVar2[0xf] = *(undefined4 *)(param_1 + 0x3c);
  if (*(int **)(param_1 + 0x1c) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x1c) + 8))();
    puVar2[7] = iVar3;
    if (iVar3 == 0) goto LAB_005d843c;
  }
  if (*(int **)(param_1 + 0x20) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x20) + 8))();
    puVar2[8] = iVar3;
    if (iVar3 == 0) goto LAB_005d843c;
  }
  if (*(int **)(param_1 + 0x24) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x24) + 8))();
    puVar2[9] = iVar3;
    if (iVar3 == 0) goto LAB_005d843c;
  }
  if (*(int **)(param_1 + 0x28) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 8))();
    puVar2[10] = iVar3;
    if (iVar3 == 0) goto LAB_005d843c;
  }
  if (*(int **)(param_1 + 0x2c) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x2c) + 8))();
    puVar2[0xb] = iVar3;
    if (iVar3 == 0) goto LAB_005d843c;
  }
  if (*(int **)(param_1 + 0x30) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x30) + 8))();
    puVar2[0xc] = iVar3;
    if (iVar3 == 0) goto LAB_005d843c;
  }
  if (*(int **)(param_1 + 0x34) == (int *)0x0) {
    return puVar2;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x34) + 8))();
  puVar2[0xd] = iVar3;
  if (iVar3 != 0) {
    return puVar2;
  }
LAB_005d843c:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// ==== 0x5d844d FUN_005d844d

void __fastcall FUN_005d844d(undefined4 *param_1)

{
  param_1[1] = 10;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_006a0c84;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  return;
}


// ==== 0x5d8486 FUN_005d8486

void __fastcall FUN_005d8486(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a0c84;
  if ((undefined4 *)param_1[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[8])(1);
  }
  if ((undefined4 *)param_1[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[9])(1);
  }
  if ((undefined4 *)param_1[10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[10])(1);
  }
  if ((undefined4 *)param_1[0xb] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xb])(1);
  }
  if ((undefined4 *)param_1[0xc] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xc])(1);
  }
  _free((void *)param_1[0xe]);
  FUN_005d7803();
  return;
}


// ==== 0x5d84e1 FUN_005d84e1

undefined1 __thiscall FUN_005d84e1(int param_1,int param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  
  iVar3 = FUN_005d7830(param_2);
  if ((((((iVar3 != 0) && (*(int *)(param_1 + 0x10) == *(int *)(param_2 + 0x10))) &&
        (*(int *)(param_1 + 0x14) == *(int *)(param_2 + 0x14))) &&
       ((*(int *)(param_1 + 0x18) == *(int *)(param_2 + 0x18) &&
        (*(int *)(param_1 + 0x1c) == *(int *)(param_2 + 0x1c))))) &&
      ((*(int *)(param_1 + 0x34) == *(int *)(param_2 + 0x34) &&
       ((iVar3 = FUN_005d7866(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_2 + 0x20)),
        iVar3 != 0 &&
        (iVar3 = FUN_005d7866(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_2 + 0x24)),
        iVar3 != 0)))))) &&
     ((iVar3 = FUN_005d7866(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_2 + 0x28)),
      iVar3 != 0 &&
      ((iVar3 = FUN_005d7866(*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_2 + 0x2c)),
       iVar3 != 0 &&
       (iVar3 = FUN_005d7866(*(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_2 + 0x30)),
       iVar3 != 0)))))) {
    iVar3 = *(int *)(param_1 + 0x34) << 2;
    pcVar4 = *(char **)(param_1 + 0x38);
    pcVar5 = *(char **)(param_2 + 0x38);
    do {
      if (iVar3 == 0) {
        return 1;
      }
      iVar3 = iVar3 + -1;
      cVar2 = *pcVar5;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 == cVar2);
  }
  return 0;
}


// ==== 0x5d858a FUN_005d858a

undefined4 * __fastcall FUN_005d858a(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  pvVar1 = _malloc(0x3c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d844d();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2[4] = *(undefined4 *)(param_1 + 0x10);
  puVar2[5] = *(undefined4 *)(param_1 + 0x14);
  puVar2[6] = *(undefined4 *)(param_1 + 0x18);
  puVar2[7] = *(undefined4 *)(param_1 + 0x1c);
  puVar2[0xd] = *(undefined4 *)(param_1 + 0x34);
  if (*(int **)(param_1 + 0x20) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x20) + 8))();
    puVar2[8] = iVar3;
    if (iVar3 == 0) goto LAB_005d8644;
  }
  if (*(int **)(param_1 + 0x24) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x24) + 8))();
    puVar2[9] = iVar3;
    if (iVar3 == 0) goto LAB_005d8644;
  }
  if (*(int **)(param_1 + 0x28) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 8))();
    puVar2[10] = iVar3;
    if (iVar3 == 0) goto LAB_005d8644;
  }
  if (*(int **)(param_1 + 0x2c) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x2c) + 8))();
    puVar2[0xb] = iVar3;
    if (iVar3 == 0) goto LAB_005d8644;
  }
  if (*(int **)(param_1 + 0x30) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x30) + 8))();
    puVar2[0xc] = iVar3;
    if (iVar3 == 0) goto LAB_005d8644;
  }
  if (*(int *)(param_1 + 0x34) == 0) {
    return puVar2;
  }
  puVar4 = _malloc(*(int *)(param_1 + 0x34) << 2);
  puVar2[0xe] = puVar4;
  if (puVar4 != (undefined4 *)0x0) {
    puVar6 = *(undefined4 **)(param_1 + 0x38);
    for (uVar5 = *(uint *)(param_1 + 0x34) & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar4 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar4 = puVar4 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar4 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    return puVar2;
  }
LAB_005d8644:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// ==== 0x5d8670 FUN_005d8670

void __fastcall FUN_005d8670(undefined4 *param_1)

{
  param_1[1] = 0xb;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_006a0c94;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  return;
}


// ==== 0x5d869a FUN_005d869a

void __fastcall FUN_005d869a(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a0c94;
  if ((undefined4 *)param_1[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[5])(1);
  }
  if ((undefined4 *)param_1[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[6])(1);
  }
  if ((undefined4 *)param_1[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[7])(1);
  }
  if ((undefined4 *)param_1[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[8])(1);
  }
  if ((undefined4 *)param_1[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[9])(1);
  }
  FUN_005d7803();
  return;
}


// ==== 0x5d86ec FUN_005d86ec

undefined4 __thiscall FUN_005d86ec(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_005d7830(param_2);
  if ((((iVar1 != 0) && (*(int *)(param_1 + 0x10) == *(int *)(param_2 + 0x10))) &&
      (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_2 + 0x14)),
      iVar1 != 0)) &&
     (((iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_2 + 0x18)),
       iVar1 != 0 &&
       (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_2 + 0x1c)),
       iVar1 != 0)) &&
      ((iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_2 + 0x20)),
       iVar1 != 0 &&
       (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_2 + 0x24)),
       iVar1 != 0)))))) {
    return 1;
  }
  return 0;
}


// ==== 0x5d875d FUN_005d875d

undefined4 * __fastcall FUN_005d875d(int param_1)

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
    return (undefined4 *)0x0;
  }
  puVar2[4] = *(undefined4 *)(param_1 + 0x10);
  if (*(int **)(param_1 + 0x14) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x14) + 8))();
    puVar2[5] = iVar3;
    if (iVar3 == 0) goto LAB_005d87e3;
  }
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 8))();
    puVar2[6] = iVar3;
    if (iVar3 == 0) goto LAB_005d87e3;
  }
  if (*(int **)(param_1 + 0x1c) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x1c) + 8))();
    puVar2[7] = iVar3;
    if (iVar3 == 0) goto LAB_005d87e3;
  }
  if (*(int **)(param_1 + 0x20) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x20) + 8))();
    puVar2[8] = iVar3;
    if (iVar3 == 0) goto LAB_005d87e3;
  }
  if (*(int **)(param_1 + 0x24) == (int *)0x0) {
    return puVar2;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x24) + 8))();
  puVar2[9] = iVar3;
  if (iVar3 != 0) {
    return puVar2;
  }
LAB_005d87e3:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// ==== 0x5d87f4 FUN_005d87f4

undefined4 * __fastcall FUN_005d87f4(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[1] = 0xc;
  *param_1 = &PTR_FUN_006a0ca4;
  param_1[10] = 1;
  puVar2 = param_1 + 0xc;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}


// ==== 0x5d8831 FUN_005d8831

void __thiscall
FUN_005d8831(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 *param_7)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = param_3;
  param_1[8] = param_4;
  param_1[9] = param_5;
  param_1[10] = param_6;
  param_1[1] = 0xc;
  *param_1 = &PTR_FUN_006a0ca4;
  param_1[4] = param_2;
  puVar2 = param_1 + 0xc;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_7;
    param_7 = param_7 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== 0x5d8882 FUN_005d8882

void __fastcall FUN_005d8882(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a0ca4;
  if ((undefined4 *)param_1[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[4])(1);
  }
  if ((undefined4 *)param_1[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[8])(1);
  }
  if ((undefined4 *)param_1[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[9])(1);
  }
  FUN_005d7803();
  return;
}


// ==== 0x5d88ba FUN_005d88ba

undefined4 __thiscall FUN_005d88ba(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_005d7830(param_2);
  if ((((((iVar1 != 0) && (*(int *)(param_1 + 0x14) == *(int *)(param_2 + 0x14))) &&
        (*(int *)(param_1 + 0x18) == *(int *)(param_2 + 0x18))) &&
       ((*(int *)(param_1 + 0x1c) == *(int *)(param_2 + 0x1c) &&
        (*(int *)(param_1 + 0x28) == *(int *)(param_2 + 0x28))))) &&
      ((iVar1 = FUN_005d79dc(), iVar1 != 0 &&
       ((iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_2 + 0x10)),
        iVar1 != 0 &&
        (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_2 + 0x20)),
        iVar1 != 0)))))) &&
     (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_2 + 0x24)),
     iVar1 != 0)) {
    return 1;
  }
  return 0;
}


// ==== 0x5d8934 FUN_005d8934

undefined4 * __fastcall FUN_005d8934(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  pvVar1 = _malloc(0x50);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d87f4();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2[5] = *(undefined4 *)(param_1 + 0x14);
  puVar2[6] = *(undefined4 *)(param_1 + 0x18);
  puVar2[7] = *(undefined4 *)(param_1 + 0x1c);
  puVar2[10] = *(undefined4 *)(param_1 + 0x28);
  puVar4 = (undefined4 *)(param_1 + 0x30);
  puVar5 = puVar2 + 0xc;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  if (*(int **)(param_1 + 0x10) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x10) + 8))();
    puVar2[4] = iVar3;
    if (iVar3 == 0) goto LAB_005d89b8;
  }
  if (*(int **)(param_1 + 0x20) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x20) + 8))();
    puVar2[8] = iVar3;
    if (iVar3 == 0) goto LAB_005d89b8;
  }
  if (*(int **)(param_1 + 0x24) == (int *)0x0) {
    return puVar2;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x24) + 8))();
  puVar2[9] = iVar3;
  if (iVar3 != 0) {
    return puVar2;
  }
LAB_005d89b8:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// ==== 0x5d89c9 FUN_005d89c9

undefined4 * __fastcall FUN_005d89c9(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[1] = 0xd;
  *param_1 = &PTR_FUN_006a0cb4;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  puVar2 = param_1 + 8;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[4] = 3;
  return param_1;
}


// ==== 0x5d8a02 FUN_005d8a02

undefined4 * __thiscall FUN_005d8a02(undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[1] = 0xd;
  *param_1 = &PTR_FUN_006a0cb4;
  param_1[4] = *param_2;
  param_1[5] = param_2[1];
  param_1[6] = param_2[2];
  param_1[7] = param_2[3];
  iVar1 = param_1[4];
  puVar5 = param_1 + 8;
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *param_3;
    param_3 = param_3 + 1;
    puVar5 = puVar5 + 1;
  }
  if ((iVar1 == 5) && (piVar2 = (int *)param_1[6], piVar2 != (int *)0x0)) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  if ((param_1[4] == 4) && (param_1[6] != 0)) {
    uVar3 = FUN_005d7885(param_1[6]);
    param_1[6] = uVar3;
  }
  return param_1;
}


// ==== 0x5d8a65 FUN_005d8a65

void __thiscall
FUN_005d8a65(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[6] = param_3;
  param_1[1] = 0xd;
  *param_1 = &PTR_FUN_006a0cb4;
  puVar2 = param_1 + 8;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_4;
    param_4 = param_4 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== 0x5d8a9d FUN_005d8a9d

void __thiscall
FUN_005d8a9d(undefined4 *param_1,undefined4 param_2,undefined8 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined8 *)(param_1 + 6) = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[1] = 0xd;
  *param_1 = &PTR_FUN_006a0cb4;
  puVar2 = param_1 + 8;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_4;
    param_4 = param_4 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== 0x5d8ad5 FUN_005d8ad5

undefined4 * __thiscall
FUN_005d8ad5(undefined4 *param_1,undefined4 param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[1] = 0xd;
  *param_1 = &PTR_FUN_006a0cb4;
  param_1[6] = param_3;
  puVar2 = param_1 + 8;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_4;
    param_4 = param_4 + 1;
    puVar2 = puVar2 + 1;
  }
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 4))(param_3);
  }
  return param_1;
}


// ==== 0x5d8b1b FUN_005d8b1b

void __thiscall
FUN_005d8b1b(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[6] = param_3;
  param_1[7] = param_4;
  param_1[1] = 0xd;
  *param_1 = &PTR_FUN_006a0cb4;
  puVar2 = param_1 + 8;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_5;
    param_5 = param_5 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== 0x5d8b5a FUN_005d8b5a

void __fastcall FUN_005d8b5a(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_006a0cb4;
  if ((param_1[4] == 5) && (piVar1 = (int *)param_1[6], piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[6] = 0;
  }
  if ((param_1[4] == 4) && ((undefined4 *)param_1[6] != (undefined4 *)0x0)) {
    (*(code *)**(undefined4 **)param_1[6])(1);
  }
  FUN_005d7803();
  return;
}


// ==== 0x5d8b95 FUN_005d8b95

undefined4 FUN_005d8b95(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  bool bVar6;
  undefined8 uVar7;
  
  uVar7 = FUN_005d7830(param_1);
  iVar2 = (int)((ulonglong)uVar7 >> 0x20);
  if ((int)uVar7 != 0) {
    piVar4 = (int *)(iVar2 + 0x10);
    iVar1 = *piVar4;
    if (iVar1 == *(int *)(param_1 + 0x10)) {
      iVar3 = 4;
      bVar6 = true;
      piVar5 = (int *)(param_1 + 0x10);
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *piVar4 == *piVar5;
        piVar4 = piVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (bVar6);
      if ((bVar6) ||
         ((iVar1 == 4 &&
          (iVar2 = FUN_005d7866(*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(param_1 + 0x18)),
          iVar2 != 0)))) {
        return 1;
      }
    }
  }
  return 0;
}


// ==== 0x5d8be0 FUN_005d8be0

undefined4 * __fastcall FUN_005d8be0(int param_1)

{
  int *piVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  pvVar2 = _malloc(0x40);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_005d89c9();
  }
  if (puVar3 == (undefined4 *)0x0) {
LAB_005d8c3e:
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[4] = *(int *)(param_1 + 0x10);
    puVar3[5] = *(undefined4 *)(param_1 + 0x14);
    puVar3[6] = *(undefined4 *)(param_1 + 0x18);
    puVar3[7] = *(undefined4 *)(param_1 + 0x1c);
    puVar5 = (undefined4 *)(param_1 + 0x20);
    puVar6 = puVar3 + 8;
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    if ((*(int *)(param_1 + 0x10) == 4) && (*(int *)(param_1 + 0x18) != 0)) {
      iVar4 = FUN_005d7885(*(int *)(param_1 + 0x18));
      *(int *)(param_1 + 0x18) = iVar4;
      if (iVar4 == 0) {
        (**(code **)*puVar3)(1);
        goto LAB_005d8c3e;
      }
    }
    if ((*(int *)(param_1 + 0x10) == 5) &&
       (piVar1 = *(int **)(param_1 + 0x18), piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
  }
  return puVar3;
}


// ==== 0x5d8c5a FUN_005d8c5a

void __fastcall FUN_005d8c5a(undefined4 *param_1)

{
  param_1[1] = 0xf;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_006a0cc4;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  return;
}


// ==== 0x5d8c7b FUN_005d8c7b

void __thiscall
FUN_005d8c7b(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = param_3;
  param_1[1] = 0xf;
  *param_1 = &PTR_FUN_006a0cc4;
  param_1[6] = param_4;
  return;
}


// ==== 0x5d8caa FUN_005d8caa

void __fastcall FUN_005d8caa(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a0cc4;
  if ((undefined4 *)param_1[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[4])(1);
  }
  if ((undefined4 *)param_1[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[5])(1);
  }
  if ((undefined4 *)param_1[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[6])(1);
  }
  FUN_005d7803();
  return;
}


// ==== 0x5d8ce2 FUN_005d8ce2

undefined4 __thiscall FUN_005d8ce2(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_005d7830(param_2);
  if ((((iVar1 != 0) &&
       (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_2 + 0x10)),
       iVar1 != 0)) &&
      (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_2 + 0x14)),
      iVar1 != 0)) &&
     (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_2 + 0x18)),
     iVar1 != 0)) {
    return 1;
  }
  return 0;
}


// ==== 0x5d8d2d FUN_005d8d2d

undefined4 * __fastcall FUN_005d8d2d(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x1c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d8c5a();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  if (*(int **)(param_1 + 0x10) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x10) + 8))();
    puVar2[4] = iVar3;
    if (iVar3 == 0) goto LAB_005d8d87;
  }
  if (*(int **)(param_1 + 0x14) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x14) + 8))();
    puVar2[5] = iVar3;
    if (iVar3 == 0) goto LAB_005d8d87;
  }
  if (*(int **)(param_1 + 0x18) == (int *)0x0) {
    return puVar2;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 8))();
  puVar2[6] = iVar3;
  if (iVar3 != 0) {
    return puVar2;
  }
LAB_005d8d87:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// ==== 0x5d8d98 FUN_005d8d98

void __fastcall FUN_005d8d98(undefined4 *param_1)

{
  param_1[1] = 0xe;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_006a0cd4;
  param_1[0xc] = 0;
  return;
}


// ==== 0x5d8db3 FUN_005d8db3

undefined4 * __thiscall FUN_005d8db3(undefined4 *param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[1] = 0xe;
  *param_1 = &PTR_FUN_006a0cd4;
  puVar2 = param_1 + 4;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  param_1[0xc] = param_3;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 4))(param_3);
  }
  return param_1;
}


// ==== 0x5d8df2 FUN_005d8df2

void __fastcall FUN_005d8df2(undefined4 *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[0xc];
  *param_1 = &PTR_FUN_006a0cd4;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[0xc] = 0;
  }
  FUN_005d7803();
  return;
}


// ==== 0x5d8e14 FUN_005d8e14

bool __thiscall FUN_005d8e14(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_005d7830(param_2);
  if ((iVar1 != 0) && (iVar1 = FUN_005d79dc(), iVar1 != 0)) {
    return *(int *)(param_2 + 0x30) == *(int *)(param_1 + 0x30);
  }
  return false;
}


// ==== 0x5d8e49 FUN_005d8e49

int __fastcall FUN_005d8e49(int param_1)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  pvVar2 = _malloc(0x38);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_005d8d98();
  }
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    puVar5 = (undefined4 *)(param_1 + 0x10);
    puVar6 = (undefined4 *)(iVar3 + 0x10);
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(param_1 + 0x30);
    piVar1 = *(int **)(param_1 + 0x30);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
  }
  return iVar3;
}


// ==== 0x5d8e95 FUN_005d8e95

void __fastcall FUN_005d8e95(undefined4 *param_1)

{
  param_1[1] = 0x10;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_006a0ce4;
  param_1[4] = 0;
  param_1[5] = 0;
  return;
}


// ==== 0x5d8eb3 FUN_005d8eb3

void __thiscall FUN_005d8eb3(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[1] = 0x10;
  *param_1 = &PTR_FUN_006a0ce4;
  param_1[5] = param_3;
  return;
}


// ==== 0x5d8edb FUN_005d8edb

void __fastcall FUN_005d8edb(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a0ce4;
  if ((undefined4 *)param_1[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[4])(1);
  }
  if ((undefined4 *)param_1[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[5])(1);
  }
  FUN_005d7803();
  return;
}


// ==== 0x5d8f06 FUN_005d8f06

undefined4 __thiscall FUN_005d8f06(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_005d7830(param_2);
  if (((iVar1 != 0) &&
      (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_2 + 0x10)),
      iVar1 != 0)) &&
     (iVar1 = FUN_005d7866(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_2 + 0x14)),
     iVar1 != 0)) {
    return 1;
  }
  return 0;
}


// ==== 0x5d8f42 FUN_005d8f42

undefined4 * __fastcall FUN_005d8f42(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x18);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_005d8e95();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  if (*(int **)(param_1 + 0x10) != (int *)0x0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x10) + 8))();
    puVar2[4] = iVar3;
    if (iVar3 == 0) goto LAB_005d8f89;
  }
  if (*(int **)(param_1 + 0x14) == (int *)0x0) {
    return puVar2;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x14) + 8))();
  puVar2[5] = iVar3;
  if (iVar3 != 0) {
    return puVar2;
  }
LAB_005d8f89:
  (**(code **)*puVar2)(1);
  return (undefined4 *)0x0;
}


// ==== 0x5d8f9a FUN_005d8f9a

void * __thiscall FUN_005d8f9a(void *param_1,byte param_2)

{
  FUN_005d7803();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d8fb6 FUN_005d8fb6

undefined4 * __thiscall FUN_005d8fb6(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a0bf4;
  FUN_005d7803();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d8fd8 FUN_005d8fd8

undefined4 * __thiscall FUN_005d8fd8(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a0c04;
  FUN_005d7803();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d8ffa FUN_005d8ffa

void * __thiscall FUN_005d8ffa(void *param_1,byte param_2)

{
  FUN_005d7b97();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d9016 FUN_005d9016

void * __thiscall FUN_005d9016(void *param_1,byte param_2)

{
  FUN_005d7ca4();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d9032 FUN_005d9032

void * __thiscall FUN_005d9032(void *param_1,byte param_2)

{
  FUN_005d7df3();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d904e FUN_005d904e

void * __thiscall FUN_005d904e(void *param_1,byte param_2)

{
  FUN_005d7f77();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d906a FUN_005d906a

void * __thiscall FUN_005d906a(void *param_1,byte param_2)

{
  FUN_005d808a();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d9086 FUN_005d9086

undefined4 * __thiscall FUN_005d9086(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a0c64;
  FUN_005d7803();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d90a8 FUN_005d90a8

void * __thiscall FUN_005d90a8(void *param_1,byte param_2)

{
  FUN_005d824f();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d90c4 FUN_005d90c4

void * __thiscall FUN_005d90c4(void *param_1,byte param_2)

{
  FUN_005d8486();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d90e0 FUN_005d90e0

void * __thiscall FUN_005d90e0(void *param_1,byte param_2)

{
  FUN_005d869a();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d90fc FUN_005d90fc

void * __thiscall FUN_005d90fc(void *param_1,byte param_2)

{
  FUN_005d8882();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d9118 FUN_005d9118

void * __thiscall FUN_005d9118(void *param_1,byte param_2)

{
  FUN_005d8b5a();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d9134 FUN_005d9134

void * __thiscall FUN_005d9134(void *param_1,byte param_2)

{
  FUN_005d8caa();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d9150 FUN_005d9150

void * __thiscall FUN_005d9150(void *param_1,byte param_2)

{
  FUN_005d8df2();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d916c FUN_005d916c

void * __thiscall FUN_005d916c(void *param_1,byte param_2)

{
  FUN_005d8edb();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5d9188 FUN_005d9188

void __fastcall FUN_005d9188(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[6] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0x14] = 0;
  return;
}


// ==== 0x5d91a1 FUN_005d91a1

void __fastcall FUN_005d91a1(int param_1)

{
  if (*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 4))(1);
  }
  if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 8))(1);
  }
  _free(*(void **)(param_1 + 0x18));
  return;
}


// ==== 0x5d91c9 FUN_005d91c9

undefined4 FUN_005d91c9(undefined4 *param_1,int param_2)

{
  if (param_2 != 0) {
    for (; param_2 != 0; param_2 = param_2 + -1) {
      *param_1 = 0xffffffff;
      param_1 = param_1 + 1;
    }
  }
  return 0;
}


// ==== 0x5d91e1 FUN_005d91e1

undefined4
FUN_005d91e1(undefined4 *param_1,uint param_2,uint param_3,undefined4 *param_4,undefined4 *param_5,
            undefined4 param_6,int *param_7,undefined4 param_8,int *param_9)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  uint local_1c;
  int local_c;
  int local_8;
  
  uVar7 = param_2;
  iVar4 = param_2 * param_3;
  if (iVar4 != 0) {
    if ((param_1 == (undefined4 *)0x2) && (((uint)param_4 & 0x400) == 0)) {
      param_2 = param_3;
      bVar3 = true;
      param_3 = uVar7;
    }
    else {
      bVar3 = false;
    }
    uVar7 = param_3 + 3 >> 2;
    iVar8 = uVar7 * param_2;
    iVar5 = FUN_005f7616(param_6);
    if (iVar5 == 0) {
      return 0x80004005;
    }
    iVar2 = *(int *)(iVar5 + 0x10);
    iVar1 = iVar2 + iVar8;
    *(int *)(iVar5 + 0x10) = iVar1;
    if ((*(byte *)(iVar5 + 4) & 0x20) != 0) {
      *(int *)(iVar5 + 8) = iVar1;
    }
    if (param_2 != 0) {
      local_c = 0;
      local_8 = 0;
      param_4 = param_5;
      local_1c = param_2;
      do {
        uVar9 = 0;
        if (param_3 != 0) {
          param_1 = param_4;
          do {
            if (bVar3) {
              uVar10 = *param_1;
            }
            else {
              uVar10 = param_5[local_8 + uVar9];
            }
            puVar6 = (undefined4 *)FUN_005f762c(uVar10);
            if (puVar6 != (undefined4 *)0x0) {
              *puVar6 = param_6;
              iVar5 = (uVar9 >> 2) + local_c + iVar2;
              puVar6[2] = iVar5;
              puVar6[0x13] = param_8;
              puVar6[3] = uVar9 & 3;
              puVar6[0x15] = *param_7 + (iVar5 - iVar2) * 4 + (uVar9 & 3);
            }
            param_1 = param_1 + param_2;
            uVar9 = uVar9 + 1;
          } while (uVar9 < param_3);
        }
        param_4 = param_4 + 1;
        local_8 = local_8 + param_3;
        local_c = local_c + uVar7;
        local_1c = local_1c - 1;
      } while (local_1c != 0);
    }
    *param_7 = *param_7 + iVar8 * 4;
  }
  if (param_9 != (int *)0x0) {
    *param_9 = iVar4;
  }
  return 0;
}


// ==== 0x5d932c FUN_005d932c

undefined4 __thiscall FUN_005d932c(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  
  iVar2 = param_2;
  if ((*(int *)(param_2 + 0x28) != 0) && (*(int *)(param_2 + 0x38) == 0)) {
    uVar7 = 0;
    *(undefined4 *)(param_2 + 0x34) = 0;
    if (*(int *)(param_2 + 0x14) != 0) {
      do {
        iVar3 = FUN_005f762c(*(undefined4 *)
                              (*(int *)(param_1 + 0x18) + (*(int *)(param_2 + 0x10) + uVar7) * 4));
        uVar4 = *(int *)(iVar3 + 0x54) + 1;
        if (*(uint *)(param_2 + 0x34) < uVar4) {
          *(uint *)(param_2 + 0x34) = uVar4;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(uint *)(param_2 + 0x14));
    }
    puVar5 = _malloc(*(int *)(param_2 + 0x34) << 2);
    *(undefined4 **)(param_2 + 0x38) = puVar5;
    if (puVar5 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
    for (uVar7 = *(uint *)(param_2 + 0x34) & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar5 = 0;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    piVar1 = (int *)(param_2 + 0x14);
    iVar3 = *(int *)(*(int *)(param_2 + 0x28) + 0x20);
    param_2 = 0;
    if (*piVar1 != 0) {
      do {
        if (iVar3 == 0) {
          return 0;
        }
        puVar5 = (undefined4 *)
                 FUN_005f762c(*(undefined4 *)
                               (*(int *)(param_1 + 0x18) + (*(int *)(iVar2 + 0x10) + param_2) * 4));
        iVar6 = FUN_005f7616(*puVar5);
        if ((*(byte *)(iVar6 + 4) & 0x40) == 0) {
          *(int *)(*(int *)(iVar2 + 0x38) + puVar5[0x15] * 4) = *(int *)(iVar3 + 8) + 0x10;
        }
        param_2 = param_2 + 1;
        iVar3 = *(int *)(iVar3 + 0xc);
      } while (param_2 < *(uint *)(iVar2 + 0x14));
    }
  }
  return 0;
}


// ==== 0x5d9413 FUN_005d9413

int __thiscall FUN_005d9413(int param_1,uint param_2,double *param_3)

{
  double dVar1;
  int *piVar2;
  uint *puVar3;
  float10 fVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  float10 fVar11;
  double local_40;
  double local_38;
  undefined1 local_30 [8];
  double local_28;
  double local_20;
  double local_18;
  int *local_10;
  undefined4 local_c;
  uint uStack_8;
  
  iVar5 = *(int *)(param_1 + 8);
  piVar7 = *(int **)(*(int *)(iVar5 + 0x14) + param_2 * 4);
  local_10 = piVar7;
  if (piVar7[1] != -1) {
    iVar5 = FUN_005d9413(piVar7[1],&local_28);
    if (iVar5 < 0) {
      return iVar5;
    }
    iVar6 = __ftol();
    iVar5 = piVar7[2];
    uStack_8 = FUN_005b19e6();
    param_2 = 0;
    if (uStack_8 == 0) {
      return -0x7fffbffb;
    }
    puVar8 = *(undefined4 **)(*(int *)(param_1 + 8) + 0x14);
    while ((((piVar2 = (int *)*puVar8, *piVar7 != *piVar2 || (piVar2[1] != -1)) ||
            (iVar6 + iVar5 != piVar2[2])) || (piVar7[3] != piVar2[3]))) {
      param_2 = param_2 + 1;
      puVar8 = puVar8 + 1;
      if (uStack_8 <= param_2) {
        return -0x7fffbffb;
      }
    }
    iVar5 = FUN_005d9413(param_2,&local_18);
    if (iVar5 < 0) {
      return iVar5;
    }
    goto LAB_005d9983;
  }
  uVar9 = *(uint *)(*(int *)(*(int *)(iVar5 + 0x10) + *piVar7 * 4) + 4);
  if (((char)uVar9 < '\0') || ((*(byte *)(piVar7 + 6) & 0x80) != 0)) {
    fVar11 = (float10)*(double *)(piVar7 + 4);
  }
  else {
    if (((uVar9 & 2) == 0) || (piVar7[0xb] == -1)) {
      return -0x7fffbffb;
    }
    puVar3 = *(uint **)(*(int *)(iVar5 + 0x18) + piVar7[0xb] * 4);
    uVar9 = puVar3[3];
    uVar10 = 0;
    if (uVar9 != 0) {
      piVar7 = (int *)puVar3[4];
      do {
        if (param_2 == *piVar7) break;
        uVar10 = uVar10 + 1;
        piVar7 = piVar7 + 1;
      } while (uVar10 < uVar9);
    }
    if (uVar10 == uVar9) {
      return -0x7fffbffb;
    }
    iVar5 = FUN_005f7b0f();
    if (iVar5 == 0) {
      iVar5 = FUN_005f7b21();
      if (iVar5 == 0) {
        iVar5 = FUN_005f7b33();
        if (iVar5 == 0) {
          iVar5 = FUN_005f7b57();
          if (iVar5 == 0) {
            return -0x7fffbffb;
          }
          uStack_8 = *puVar3 & 0xffffff;
          uVar9 = *puVar3 & 0xff000000;
          if (uVar9 == 0x30000000) {
            param_2 = 0;
            local_18 = 0.0;
            if (uStack_8 != 0) {
              iVar5 = uStack_8 << 2;
              do {
                iVar6 = FUN_005d9413(*(undefined4 *)(puVar3[2] + param_2 * 4),&local_40);
                if (iVar6 < 0) {
                  return iVar6;
                }
                iVar6 = FUN_005d9413(*(undefined4 *)(iVar5 + puVar3[2]),&local_38);
                if (iVar6 < 0) {
                  return iVar6;
                }
                param_2 = param_2 + 1;
                iVar5 = iVar5 + 4;
                local_18 = local_38 * local_40 + local_18;
              } while (param_2 < uStack_8);
            }
            goto LAB_005d9983;
          }
          if (uVar9 != 0x33000000) {
            return -0x7fffbffb;
          }
          local_18 = 0.0;
          if (uVar10 != 0) {
            if (uVar10 == 1) {
              iVar5 = FUN_005d9413(*(undefined4 *)puVar3[2],&local_20);
              if (iVar5 < 0) {
                return iVar5;
              }
              if (local_20 <= 0.0) goto LAB_005d9983;
              goto LAB_005d991c;
            }
            if (uVar10 == 2) {
              iVar5 = FUN_005d9413(*(undefined4 *)puVar3[2],&local_20);
              if (iVar5 < 0) {
                return iVar5;
              }
              if (local_20 <= 0.0) goto LAB_005d9983;
              iVar5 = FUN_005d9413(*(undefined4 *)(puVar3[2] + 4),&local_28);
              if (iVar5 < 0) {
                return iVar5;
              }
              if (local_28 <= 0.0) goto LAB_005d9983;
              iVar5 = FUN_005d9413(*(undefined4 *)(puVar3[2] + 0xc),local_30);
              if (iVar5 < 0) {
                return iVar5;
              }
LAB_005d98ea:
              fVar11 = (float10)FUN_00673890();
              goto LAB_005d9980;
            }
            if (uVar10 != 3) goto LAB_005d9983;
          }
          goto LAB_005d973d;
        }
        iVar5 = FUN_005d9413(*(undefined4 *)(puVar3[2] + uVar10 * 4),&local_28);
        if (iVar5 < 0) {
          return iVar5;
        }
        iVar5 = FUN_005d9413(*(undefined4 *)(puVar3[2] + (puVar3[3] + uVar10) * 4),&local_20);
        if (iVar5 < 0) {
          return iVar5;
        }
        iVar5 = FUN_005d9413(*(undefined4 *)(puVar3[2] + (uVar10 + puVar3[3] * 2) * 4),&local_c);
        if (iVar5 < 0) {
          return iVar5;
        }
        if ((*puVar3 & 0xff000000) != 0x50000000) {
          return -0x7fffbffb;
        }
        if (0.0 <= local_28) goto LAB_005d991c;
LAB_005d980f:
        fVar11 = (float10)(double)CONCAT44(uStack_8,local_c);
      }
      else {
        iVar5 = FUN_005d9413(*(undefined4 *)(puVar3[2] + uVar10 * 4),&local_c);
        if (iVar5 < 0) {
          return iVar5;
        }
        iVar5 = FUN_005d9413(*(undefined4 *)(puVar3[2] + (puVar3[3] + uVar10) * 4),&local_20);
        if (iVar5 < 0) {
          return iVar5;
        }
        uVar9 = *puVar3 & 0xff000000;
        if (uVar9 == 0x20000000) {
          if ((double)CONCAT44(uStack_8,local_c) < local_20) goto LAB_005d980f;
LAB_005d991c:
          fVar11 = (float10)local_20;
        }
        else {
          if (uVar9 == 0x21000000) {
            if ((double)CONCAT44(uStack_8,local_c) <= local_20) goto LAB_005d991c;
            goto LAB_005d980f;
          }
          if (uVar9 == 0x22000000) {
            if (local_20 <= (double)CONCAT44(uStack_8,local_c)) {
LAB_005d9751:
              fVar11 = (float10)0;
              goto LAB_005d9980;
            }
          }
          else {
            if (uVar9 != 0x23000000) {
              if (uVar9 == 0x24000000) {
                fVar11 = (float10)local_20 + (float10)(double)CONCAT44(uStack_8,local_c);
              }
              else {
                if (uVar9 != 0x25000000) {
                  if (uVar9 != 0x26000000) {
                    return -0x7fffbffb;
                  }
                  dVar1 = (double)CONCAT44(uStack_8,local_c);
                  fVar11 = (float10)local_20;
                  goto LAB_005d9713;
                }
                fVar11 = (float10)local_20 * (float10)(double)CONCAT44(uStack_8,local_c);
              }
              goto LAB_005d9980;
            }
            if ((double)CONCAT44(uStack_8,local_c) < local_20) goto LAB_005d9751;
          }
LAB_005d973d:
          fVar11 = (float10)1;
        }
      }
    }
    else {
      iVar5 = FUN_005d9413(*(undefined4 *)(puVar3[2] + uVar10 * 4),&local_c);
      if (iVar5 < 0) {
        return iVar5;
      }
      uVar9 = *puVar3 & 0xff000000;
      if (uVar9 < 0x17000001) {
        if (uVar9 == 0x17000000) {
          fVar11 = (float10)fsin((float10)(double)CONCAT44(uStack_8,local_c));
        }
        else {
          if (uVar9 == 0x10000000) goto LAB_005d980f;
          if (uVar9 == 0x11000000) {
            fVar11 = -(float10)(double)CONCAT44(uStack_8,local_c);
          }
          else if (uVar9 == 0x12000000) {
            fVar11 = (float10)1 / (float10)(double)CONCAT44(uStack_8,local_c);
          }
          else if (uVar9 == 0x13000000) {
            iVar5 = _finite(CONCAT44(uStack_8,local_c));
            if (iVar5 == 0) goto LAB_005d9751;
            fVar11 = (float10)FUN_00673590(CONCAT44(uStack_8,local_c));
            fVar11 = (float10)(double)CONCAT44(uStack_8,local_c) - fVar11;
          }
          else {
            if (uVar9 == 0x14000000) goto LAB_005d98ea;
            if (uVar9 == 0x15000000) {
              fVar11 = (float10)log2((float10)(double)CONCAT44(uStack_8,local_c));
              fVar4 = (float10)log2((float10)2.0);
              fVar11 = ((float10)0.6931471805599453 * fVar11) /
                       ((float10)0.6931471805599453 * fVar4);
            }
            else {
              if (uVar9 != 0x16000000) {
                return -0x7fffbffb;
              }
              fVar11 = SQRT((float10)(double)CONCAT44(uStack_8,local_c));
            }
          }
        }
      }
      else if (uVar9 == 0x18000000) {
        fVar11 = (float10)fcos((float10)(double)CONCAT44(uStack_8,local_c));
      }
      else if (uVar9 == 0x19000000) {
        fVar11 = (float10)FUN_00673b70();
      }
      else if (uVar9 == 0x1a000000) {
        fVar11 = (float10)FUN_00672e20();
      }
      else {
        if (uVar9 != 0x1b000000) {
          if ((uVar9 != 0x1c000000) && (uVar9 != 0x1d000000)) {
            return -0x7fffbffb;
          }
          goto LAB_005d9751;
        }
        dVar1 = (double)CONCAT44(uStack_8,local_c);
        fVar11 = (float10)1;
LAB_005d9713:
        fVar11 = (float10)fpatan((float10)dVar1,fVar11);
      }
    }
  }
LAB_005d9980:
  local_18 = (double)fVar11;
LAB_005d9983:
  *(byte *)(local_10 + 6) = *(byte *)(local_10 + 6) | 0x80;
  *(double *)(local_10 + 4) = local_18;
  if (param_3 != (double *)0x0) {
    *param_3 = local_18;
  }
  return 0;
}


// ==== 0x5d99a5 FUN_005d99a5

undefined4 FUN_005d99a5(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      iVar1 = FUN_005f762c(*(undefined4 *)(param_1 + uVar2 * 4));
      if ((iVar1 == 0) || (*(int *)(iVar1 + 0x4c) == 0)) {
        return 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  return 1;
}


// ==== 0x5d99dd FUN_005d99dd

bool FUN_005d99dd(undefined4 *param_1,uint param_2,uint param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  bool bVar5;
  undefined4 *local_c;
  uint local_8;
  
  if (param_2 == 2) {
    bVar5 = false;
    if (param_3 * param_4 != 0) {
      piVar1 = (int *)FUN_005f762c(*param_1);
      if (((piVar1 == (int *)0x0) || (iVar2 = FUN_005f7616(*piVar1), iVar2 == 0)) ||
         ((*(byte *)(iVar2 + 4) & 0x20) == 0)) {
LAB_005d9a21:
        bVar5 = true;
      }
      else {
        param_2 = 0;
        if (param_3 != 0) {
          local_c = param_1;
          do {
            local_8 = 0;
            if (param_4 != 0) {
              param_1 = (undefined4 *)0x0;
              puVar4 = local_c;
              do {
                piVar3 = (int *)FUN_005f762c(*puVar4);
                if (((piVar3 == (int *)0x0) || (*piVar1 != *piVar3)) ||
                   (((param_2 >> 2) + piVar1[2] + (int)param_1 != piVar3[2] ||
                    ((param_2 & 3) + piVar1[3] != piVar3[3])))) goto LAB_005d9a21;
                local_8 = local_8 + 1;
                param_1 = (undefined4 *)((int)param_1 + (param_3 + 3 >> 2));
                puVar4 = puVar4 + 1;
              } while (local_8 < param_4);
            }
            param_2 = param_2 + 1;
            local_c = local_c + param_4;
          } while (param_2 < param_3);
        }
        bVar5 = false;
      }
    }
  }
  else {
    bVar5 = param_3 == 1;
  }
  return bVar5;
}


// ==== 0x5d9ac5 FUN_005d9ac5

bool FUN_005d9ac5(undefined4 *param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  bool bVar6;
  uint local_c;
  int local_8;
  
  uVar2 = (uint)param_4;
  if (param_2 == (undefined4 *)0x2) {
    if (param_3 * (int)param_4 != 0) {
      piVar3 = (int *)FUN_005f762c(*param_1);
      if (((piVar3 == (int *)0x0) || (iVar4 = FUN_005f7616(*piVar3), iVar4 == 0)) ||
         ((*(byte *)(iVar4 + 4) & 0x20) == 0)) {
        return true;
      }
      uVar1 = (int)param_4 + 3;
      local_c = 0;
      if (param_3 != 0) {
        local_8 = 0;
        param_4 = param_1;
        do {
          param_1 = (undefined4 *)0x0;
          if (uVar2 != 0) {
            param_2 = param_4;
            do {
              piVar5 = (int *)FUN_005f762c(*param_2);
              if (piVar5 == (int *)0x0) {
                return true;
              }
              if (*piVar3 != *piVar5) {
                return true;
              }
              if (((uint)param_1 >> 2) + piVar3[2] + local_8 != piVar5[2]) {
                return true;
              }
              if (((uint)param_1 & 3) + piVar3[3] != piVar5[3]) {
                return true;
              }
              param_1 = (undefined4 *)((int)param_1 + 1);
              param_2 = param_2 + 1;
            } while (param_1 < uVar2);
          }
          local_c = local_c + 1;
          local_8 = local_8 + (uVar1 >> 2);
          param_4 = param_4 + uVar2;
        } while (local_c < param_3);
      }
    }
    bVar6 = false;
  }
  else {
    bVar6 = 1 < param_3;
  }
  return bVar6;
}


// ==== 0x5d9bb3 FUN_005d9bb3

int __thiscall FUN_005d9bb3(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  bool bVar7;
  undefined1 local_1c [4];
  uint local_18;
  int local_10;
  int local_c;
  uint local_8;
  
  local_10 = 0;
  local_8 = 0xffffffff;
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || (*(int *)(iVar2 + 4) != 3)) {
    local_10 = 0;
  }
  else {
    for (local_c = *(int *)(iVar2 + 0x1c); local_c != 0; local_c = *(int *)(local_c + 0xc)) {
      iVar2 = *(int *)(local_c + 8);
      if (((iVar2 != 0) && (*(int *)(iVar2 + 4) == 5)) && (*(int *)(iVar2 + 0x10) == 2)) {
        pbVar3 = *(byte **)(*(int *)(iVar2 + 0x14) + 0x18);
        pbVar6 = param_2;
        do {
          bVar1 = *pbVar3;
          bVar7 = bVar1 < *pbVar6;
          if (bVar1 != *pbVar6) {
LAB_005d9c36:
            iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
            goto LAB_005d9c3b;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar3[1];
          bVar7 = bVar1 < pbVar6[1];
          if (bVar1 != pbVar6[1]) goto LAB_005d9c36;
          pbVar3 = pbVar3 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar1 != 0);
        iVar4 = 0;
LAB_005d9c3b:
        if (((iVar4 == 0) && (iVar2 = *(int *)(iVar2 + 0x18), *(int *)(iVar2 + 0x3c) != 0)) &&
           ((*(byte *)(iVar2 + 0x18) & 2) == 0)) {
          uVar5 = 0;
          if ((*(int *)(iVar2 + 0x1c) != 0) &&
             (iVar4 = FUN_005d7700(*(undefined4 *)(*(int *)(iVar2 + 0x1c) + 0x18),0,local_1c),
             uVar5 = local_18, iVar4 < 0)) {
            uVar5 = 0xffffffff;
          }
          if ((((uVar5 & 0xffff0000) == 0) ||
              ((uVar5 & 0xffff0000) == (*(uint *)(param_1 + 0x10) & 0xffff0000))) &&
             ((((uVar5 & 0xffff) == 0 || ((uVar5 & 0xffff) == (*(uint *)(param_1 + 0x10) & 0xffff)))
              && ((local_8 == 0xffffffff || (local_8 < uVar5)))))) {
            local_10 = iVar2;
            local_8 = uVar5;
          }
        }
      }
    }
  }
  return local_10;
}


// ==== 0x5d9cc7 FUN_005d9cc7

int __thiscall FUN_005d9cc7(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 local_20 [4];
  uint local_1c;
  int local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  local_14 = 0;
  local_8 = 0xffffffff;
  local_10 = 0;
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 4) != 3)) {
    local_14 = 0;
  }
  else {
    for (local_c = *(int *)(iVar1 + 0x1c); local_c != 0; local_c = *(int *)(local_c + 0xc)) {
      iVar1 = *(int *)(local_c + 8);
      if ((((iVar1 != 0) && (*(int *)(iVar1 + 4) == 5)) && (*(int *)(iVar1 + 0x10) == 2)) &&
         (param_2 != 0)) {
        iVar2 = param_2;
        do {
          if (*(int *)(iVar1 + 0x24) == *(int *)(*(int *)(iVar2 + 8) + 0x18)) break;
          iVar2 = *(int *)(iVar2 + 0xc);
        } while (iVar2 != 0);
        if ((iVar2 != 0) && (iVar2 = *(int *)(iVar1 + 0x18), *(int *)(iVar2 + 0x3c) != 0)) {
          uVar4 = 0;
          if ((*(int *)(iVar2 + 0x1c) != 0) &&
             (iVar3 = FUN_005d7700(*(undefined4 *)(*(int *)(iVar2 + 0x1c) + 0x18),0,local_20),
             uVar4 = local_1c, iVar3 < 0)) {
            uVar4 = 0xffffffff;
          }
          if (((((uVar4 & 0xffff0000) == 0) ||
               ((uVar4 & 0xffff0000) == (*(uint *)(param_1 + 0x10) & 0xffff0000))) &&
              (((uVar4 & 0xffff) == 0 || ((uVar4 & 0xffff) == (*(uint *)(param_1 + 0x10) & 0xffff)))
              )) && ((local_8 == 0xffffffff || (local_8 < uVar4)))) {
            local_10 = *(undefined4 *)(*(int *)(iVar1 + 0x14) + 0x18);
            local_14 = iVar2;
            local_8 = uVar4;
          }
        }
      }
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = local_10;
    }
  }
  return local_14;
}


// ==== 0x5d9de1 FUN_005d9de1

undefined4 FUN_005d9de1(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 local_104 [255];
  undefined1 local_5;
  
  _vsnprintf(local_104,0x100,param_4,&stack0x00000014);
  iVar1 = 0;
  local_5 = 0;
  if (param_2 != 0) {
    if (*(int *)(param_2 + 4) == 5) {
      iVar1 = *(int *)(param_2 + 0x14) + 0x10;
    }
    else if (*(int *)(param_2 + 4) == 0xc) {
      iVar1 = param_2 + 0x30;
    }
  }
  FUN_005b1f01(*param_1 + 4,iVar1,param_3,&DAT_006cc568,local_104);
  param_1[0xd] = 1;
  return 0;
}


// ==== 0x5d9e57 FUN_005d9e57

undefined4 FUN_005d9e57(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 local_104 [255];
  undefined1 local_5;
  
  _vsnprintf(local_104,0x100,param_4,&stack0x00000014);
  iVar1 = 0;
  local_5 = 0;
  if ((param_2 != 0) && (*(int *)(param_2 + 4) == 0xc)) {
    iVar1 = param_2 + 0x30;
  }
  FUN_005b1fca(*param_1 + 4,iVar1,param_3,&DAT_006cc568,local_104);
  return 0;
}


// ==== 0x5d9eb5 FUN_005d9eb5

uint FUN_005d9eb5(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_005f762c(*(undefined4 *)(*(int *)(param_3 + 0x18) + param_1 * 4));
  iVar2 = FUN_005f762c(*(undefined4 *)(*(int *)(param_3 + 0x18) + param_2 * 4));
  if (*(uint *)(iVar2 + 0x50) <= *(uint *)(iVar1 + 0x50)) {
    if (*(uint *)(iVar2 + 0x50) < *(uint *)(iVar1 + 0x50)) {
      return 1;
    }
    if (*(uint *)(iVar2 + 0xc) <= *(uint *)(iVar1 + 0xc)) {
      if (*(uint *)(iVar1 + 0xc) != *(uint *)(iVar2 + 0xc)) {
        return 1;
      }
      if (param_2 <= param_1) {
        return (uint)(param_2 < param_1);
      }
    }
  }
  return 0xffffffff;
}


// ==== 0x5d9f14 FUN_005d9f14

int __thiscall
FUN_005d9f14(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  int local_c;
  int iStack_8;
  
  local_c = param_1;
  iStack_8 = param_1;
  iVar1 = FUN_005dc760(param_2);
  if (-1 < iVar1) {
    if (param_3 != 0) {
      uVar2 = 0;
      do {
        iVar1 = FUN_005e2a38(param_3,&param_2);
        if (iVar1 < 0) {
          return iVar1;
        }
        iVar1 = FUN_005d9413(param_2,&local_c);
        if (iVar1 < 0) break;
        if ((double)CONCAT44(iStack_8,local_c) == 0.0) {
          return 0;
        }
        iVar1 = FUN_005dc760(param_5);
        if (iVar1 < 0) {
          return iVar1;
        }
        if (*(int *)(param_1 + 0x38) != 0) {
          return 0;
        }
        iVar1 = FUN_005dc760(param_4);
        if (iVar1 < 0) {
          return iVar1;
        }
        if (*(int *)(param_1 + 0x38) != 0) {
          return 0;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < 0x400);
    }
    iVar1 = -0x7fffbfff;
  }
  return iVar1;
}


// ==== 0x5d9fa1 FUN_005d9fa1

int __thiscall
FUN_005d9fa1(int param_1,undefined4 param_2,uint param_3,int *param_4,undefined4 *param_5,
            int *param_6,uint param_7)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *local_20 [3];
  int local_14;
  uint local_10;
  undefined4 *local_c;
  uint local_8;
  
  local_c = (undefined4 *)param_1;
  if (param_3 == 0x30000001) {
    iVar1 = FUN_005d9fa1(param_2,0x25000001,param_4,param_5,param_6,param_7);
    if (iVar1 < 0) {
      return iVar1;
    }
    return 0;
  }
  if ((param_3 == 0x30000002) && ((*(byte *)(*(int *)(param_1 + 8) + 0x90) & 0x20) == 0)) {
    local_20[2] = (undefined4 *)0xffffffff;
    local_14 = -1;
    iVar1 = FUN_005d9fa1(param_2,0x25000001,local_20 + 2,param_5,param_6,param_7 & 0x40);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_005d9fa1(param_2,0x25000001,&local_14,param_5 + 1,param_6 + 1,param_7 & 0x40);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_005d9fa1(param_2,0x24000001,param_4,local_20 + 2,&local_14,param_7);
    if (iVar1 < 0) {
      return iVar1;
    }
LAB_005da3e3:
    iVar1 = 0;
  }
  else {
    if (((*(byte *)(*(int *)(param_1 + 8) + 0x90) & 0x80) == 0) ||
       ((((local_10 = param_3 & 0xff000000, local_10 != 0x20000000 && (local_10 != 0x21000000)) &&
         (local_10 != 0x22000000)) && (local_10 != 0x23000000)))) {
      local_10 = FUN_005f752b(param_3,0xffffffff,0xffffffff);
      iVar1 = FUN_005f7642();
      if (iVar1 != 0) {
        local_8 = FUN_005f7b98(0,0);
        uVar2 = FUN_005f7a5c(0,0);
        iVar7 = *(int *)(iVar1 + 4) - uVar2;
        puVar4 = param_5;
        puVar3 = *(undefined4 **)(iVar1 + 8);
        for (uVar5 = uVar2 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar3 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar3 = puVar3 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined1 *)puVar3 = *(undefined1 *)puVar4;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + 1);
        }
        puVar4 = (undefined4 *)(*(int *)(iVar1 + 8) + uVar2 * 4);
        for (; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar4 = *param_6;
          param_6 = param_6 + 1;
          puVar4 = puVar4 + 1;
        }
        uVar2 = 0;
        puVar4 = local_c;
        if (*(int *)(iVar1 + 4) != 0) {
          do {
            puVar4 = local_c;
            iVar7 = FUN_005f762c();
            if (iVar7 != 0) {
              *(int *)(iVar7 + 0x40) = *(int *)(iVar7 + 0x40) + 1;
            }
            uVar2 = uVar2 + 1;
          } while (uVar2 < *(uint *)(iVar1 + 4));
        }
        param_3 = 0;
        if (local_8 != 0) {
          local_14 = (int)param_5 - (int)param_4;
          param_6 = param_4;
          do {
            param_5 = (undefined4 *)0x0;
            if (((param_4 != (int *)0x0) && (*param_6 != -1)) &&
               (param_5 = (undefined4 *)FUN_005f762c(), param_5 == (undefined4 *)0x0)) {
              FUN_005d9de1(puVar4,0,0,"internal error: result register invalid");
              return -0x7fffbffb;
            }
            local_c = (undefined4 *)
                      FUN_005f74cf(*(undefined4 *)(*(int *)((int)puVar4 + 8) + 0x60),0,0,0);
            if ((local_c == (undefined4 *)0xffffffff) || (iVar7 = FUN_005f762c(), iVar7 == 0))
            goto LAB_005da0d4;
            *(uint *)(iVar7 + 0x18) = param_7;
            *(uint *)(iVar7 + 0x2c) = local_10;
            *(undefined4 **)(param_3 * 4 + *(int *)(iVar1 + 0x10)) = local_c;
            if (param_4 != (int *)0x0) {
              *param_6 = (int)local_c;
            }
            if (param_5 != (undefined4 *)0x0) {
              *(undefined4 *)(iVar7 + 0x1c) = *(undefined4 *)((int)param_5 + 0x1c);
              *(undefined4 *)(iVar7 + 0x44) = *(undefined4 *)((int)param_5 + 0x44);
              *(undefined4 *)(iVar7 + 0x48) = *(undefined4 *)((int)param_5 + 0x48);
            }
            if ((*(int *)(iVar7 + 0x1c) != -1) &&
               (*(undefined4 *)(*(int *)((int)puVar4 + 0x18) + *(int *)(iVar7 + 0x1c) * 4) =
                     *(undefined4 *)(param_3 * 4 + *(int *)(iVar1 + 0x10)),
               *(int *)(iVar7 + 0x44) == 0)) {
              FUN_005d9de1(puVar4,0,0,"internal error: argument missing context (A%u)");
            }
            iVar6 = FUN_005f7aa3();
            if (iVar6 != 0) {
              puVar3 = (undefined4 *)(local_14 + (int)param_6);
              iVar6 = FUN_005f762c();
              *(undefined4 *)(iVar7 + 0x20) = *puVar3;
              *(uint *)(iVar7 + 0x18) = *(uint *)(iVar7 + 0x18) | *(uint *)(iVar6 + 0x18);
              *(undefined8 *)(iVar7 + 0x10) = *(undefined8 *)(iVar6 + 0x10);
            }
            param_3 = param_3 + 1;
            param_6 = param_6 + 1;
          } while (param_3 < local_8);
        }
        *(undefined4 *)(iVar1 + 0x34) = param_2;
        *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)((int)puVar4 + 0x30);
        goto LAB_005da3e3;
      }
    }
    else {
      param_3 = param_3 & 0xffffff;
      local_c = _malloc(param_3 << 4);
      if (local_c != (undefined4 *)0x0) {
        uVar2 = 0;
        puVar4 = local_c;
        do {
          local_20[uVar2] = puVar4;
          uVar2 = uVar2 + 1;
          puVar4 = puVar4 + param_3;
        } while (uVar2 < 4);
        if (param_3 != 0) {
          iVar1 = (int)param_5 - (int)local_20[2];
          iVar7 = (int)param_6 - (int)local_20[2];
          local_14 = local_14 - (int)local_20[2];
          local_8 = param_3;
          do {
            if (local_10 == 0x20000000) {
              *local_20[2] = *(undefined4 *)(iVar7 + (int)local_20[2]);
              uVar8 = *(undefined4 *)(iVar1 + (int)local_20[2]);
LAB_005da15c:
              *(undefined4 *)(local_14 + (int)local_20[2]) = uVar8;
            }
            else {
              if (local_10 == 0x21000000) {
                *local_20[2] = *(undefined4 *)(iVar1 + (int)local_20[2]);
                uVar8 = *(undefined4 *)(iVar7 + (int)local_20[2]);
                goto LAB_005da15c;
              }
              if (local_10 == 0x22000000) {
                *local_20[2] = *(undefined4 *)(param_1 + 0x24);
                uVar8 = *(undefined4 *)(param_1 + 0x20);
                goto LAB_005da15c;
              }
              if (local_10 == 0x23000000) {
                *local_20[2] = *(undefined4 *)(param_1 + 0x20);
                uVar8 = *(undefined4 *)(param_1 + 0x24);
                goto LAB_005da15c;
              }
            }
            local_20[2] = local_20[2] + 1;
            local_8 = local_8 - 1;
          } while (local_8 != 0);
        }
        iVar1 = FUN_005d91c9(local_20[0],param_3);
        if ((-1 < iVar1) && (iVar1 = FUN_005d91c9(local_20[1],param_3), -1 < iVar1)) {
          iVar1 = FUN_005d9fa1(param_2,param_3 | 0x11000000,local_20[0],param_6,0,param_7 & 0x40);
          if ((-1 < iVar1) &&
             ((iVar1 = FUN_005d9fa1(param_2,param_3 | 0x24000000,local_20[1],param_5,local_20[0],
                                    param_7 & 0x40), -1 < iVar1 &&
              (iVar1 = FUN_005d9fa1(param_2,param_3 | 0x50000000,param_4,local_20[1],
                                    local_c + param_3 * 2,param_7), -1 < iVar1)))) {
            iVar1 = 0;
          }
        }
        _free(local_c);
        return iVar1;
      }
    }
LAB_005da0d4:
    iVar1 = -0x7ff8fff2;
  }
  return iVar1;
}


// ==== 0x5da405 FUN_005da405

int __thiscall FUN_005da405(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar3 = *(int *)(param_2 + 4);
    iVar1 = 0;
    if (iVar3 == 1) {
      do {
        if (*(int *)(param_2 + 4) != 1) break;
        iVar3 = FUN_005da405(*(undefined4 *)(param_2 + 8),param_3 + iVar1);
        param_2 = *(int *)(param_2 + 0xc);
        iVar1 = iVar1 + iVar3;
      } while (param_2 != 0);
      if (param_2 != 0) {
        iVar3 = FUN_005da405(param_2,param_3 + iVar1);
        iVar1 = iVar1 + iVar3;
      }
    }
    else {
      if (iVar3 == 5) {
        uVar2 = *(undefined4 *)(param_2 + 0x18);
      }
      else {
        if (iVar3 == 7) {
          if (*(int *)(param_2 + 0x14) == 0) {
            return 0;
          }
          do {
            iVar3 = FUN_005da405(*(undefined4 *)(param_2 + 0x10),param_3 + iVar1);
            iVar1 = iVar1 + iVar3;
            uVar4 = uVar4 + 1;
          } while (uVar4 < *(uint *)(param_2 + 0x14));
          return iVar1;
        }
        if (iVar3 == 8) {
          iVar1 = *(int *)(param_2 + 0x1c) * *(int *)(param_2 + 0x18);
          uVar2 = 0;
          switch(*(undefined4 *)(param_2 + 0x14)) {
          case 0:
            uVar2 = 0x2000017;
            break;
          case 1:
          case 5:
            uVar2 = 2;
            break;
          case 2:
          case 6:
            uVar2 = 0x2000002;
            break;
          case 3:
          case 7:
            uVar2 = 0x4000002;
            break;
          case 4:
          case 8:
            uVar2 = 0x8000002;
            break;
          case 10:
            uVar2 = 0x2000000;
            break;
          case 0xb:
            uVar2 = 0x4000000;
            break;
          case 0xc:
            uVar2 = 0x8000000;
          }
          iVar3 = iVar1;
          if (iVar1 == 0) {
            return 0;
          }
          for (; iVar3 != 0; iVar3 = iVar3 + -1) {
            *param_3 = uVar2;
            param_3 = param_3 + 1;
          }
          return iVar1;
        }
        if (iVar3 != 10) {
          FUN_005d9de1(param_1,0,0,"internal error: unknown node");
          return 0;
        }
        uVar2 = *(undefined4 *)(param_2 + 0x20);
      }
      iVar1 = FUN_005da405(uVar2,param_3);
    }
  }
  return iVar1;
}


// ==== 0x5da560 FUN_005da560

int __thiscall
FUN_005da560(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            int param_6,undefined4 param_7,undefined4 *param_8,int *param_9)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_c;
  int local_8;
  
  iVar2 = param_3;
  iVar1 = param_2;
  uVar4 = 0;
  local_8 = 0;
  local_c = 0;
  if (param_8 == (undefined4 *)0x0) {
    param_8 = &local_c;
  }
  if (param_2 != 0) {
    iVar3 = *(int *)(param_2 + 4);
    if (iVar3 == 1) {
      iVar3 = FUN_005da560(*(undefined4 *)(param_2 + 8),param_3,param_4,param_5,param_6,param_7,
                           param_8,&param_3);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar1 = FUN_005da560(*(undefined4 *)(iVar1 + 0xc),iVar2 + param_3 * 4,param_4,param_5,param_6,
                           param_7,param_8,&param_2);
      if (iVar1 < 0) {
        return iVar1;
      }
      local_8 = param_2 + param_3;
    }
    else {
      if (iVar3 == 5) {
        iVar1 = FUN_005da560(*(undefined4 *)(param_2 + 0x18),param_3,param_4,param_5,param_6,param_7
                             ,param_8,&local_8);
      }
      else {
        if (iVar3 == 7) {
          iVar2 = param_2;
          if (param_6 == 0) {
            do {
              if (*(int *)(iVar2 + 4) != 7) break;
              iVar2 = *(int *)(iVar2 + 0x10);
            } while (iVar2 != 0);
            if (((iVar2 != 0) && (*(int *)(iVar2 + 4) == 8)) && (*(int *)(iVar2 + 0x10) == 3)) {
              param_4 = FUN_005f7478(&DAT_0069ed7c,0x169,0xffffffff,4);
              param_6 = 1;
            }
          }
          if (*(int *)(iVar1 + 0x14) != 0) {
            do {
              iVar2 = FUN_005da560(*(undefined4 *)(iVar1 + 0x10),param_3 + local_8 * 4,param_4,
                                   param_5,param_6,param_7,param_8,&param_2);
              if (iVar2 < 0) {
                return iVar2;
              }
              local_8 = local_8 + param_2;
              uVar4 = uVar4 + 1;
            } while (uVar4 < *(uint *)(iVar1 + 0x14));
          }
          goto LAB_005da753;
        }
        if (iVar3 == 8) {
          if (*(int *)(param_2 + 0x10) == 3) {
            if (param_6 == 0) {
              param_4 = FUN_005f7478(&DAT_0069ed7c,0x169,0xffffffff,4);
            }
            else {
              iVar2 = FUN_005f7616(param_4);
              *(uint *)(iVar2 + 4) = *(uint *)(iVar2 + 4) | 0x40;
            }
          }
          iVar1 = FUN_005d91e1(*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x18),
                               *(undefined4 *)(iVar1 + 0x1c),*(undefined4 *)(iVar1 + 0x20),param_3,
                               param_4,param_8,param_7,&local_8);
        }
        else {
          if (iVar3 != 10) {
            FUN_005d9de1(param_1,0,0,"internal error: unknown node");
            goto LAB_005da753;
          }
          iVar1 = FUN_005dbee8(*(undefined4 *)(param_2 + 0x20),param_3,param_4,param_5,param_6,
                               param_7,param_8,*(undefined4 *)(param_2 + 0x2c),
                               *(undefined4 *)(param_2 + 0x30),&local_8);
        }
      }
      if (iVar1 < 0) {
        return iVar1;
      }
    }
  }
LAB_005da753:
  if (param_9 != (int *)0x0) {
    *param_9 = local_8;
  }
  return 0;
}


// ==== 0x5da768 FUN_005da768

undefined4 __thiscall FUN_005da768(undefined4 param_1,int param_2)

{
  int iVar1;
  
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          if (param_2 == 0) {
            return 1;
          }
          iVar1 = *(int *)(param_2 + 4);
          if (iVar1 != 1) break;
          iVar1 = FUN_005da768(*(undefined4 *)(param_2 + 8));
          if (iVar1 == 0) {
            return 0;
          }
          param_2 = *(int *)(param_2 + 0xc);
        }
        if (iVar1 != 5) break;
        param_2 = *(int *)(param_2 + 0x18);
      }
      if (iVar1 != 7) break;
LAB_005da7a3:
      param_2 = *(int *)(param_2 + 0x10);
    }
    if (iVar1 == 8) {
      if ((-1 < *(int *)(param_2 + 0x10)) && (*(int *)(param_2 + 0x10) < 3)) {
        return 1;
      }
      return 0;
    }
    if (iVar1 != 10) {
      if (iVar1 != 0xc) {
        FUN_005d9de1(param_1,0,0,"internal error: unknown node");
        return 0;
      }
      goto LAB_005da7a3;
    }
    param_2 = *(int *)(param_2 + 0x20);
  } while( true );
}


// ==== 0x5da7de FUN_005da7de

int __thiscall
FUN_005da7de(int param_1,undefined4 param_2,int param_3,undefined4 *param_4,undefined4 *param_5,
            uint param_6)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  uint uVar14;
  undefined4 uVar15;
  uint uVar16;
  undefined8 uVar17;
  undefined4 *local_7c [16];
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  uint local_8;
  
  local_10 = (undefined4 *)0x0;
  if ((*(byte *)(*(int *)(param_1 + 8) + 0x91) & 1) == 0) {
    uVar16 = -(uint)(param_4 != (undefined4 *)0x0) & param_6;
    uVar2 = -(uint)(param_5 != (undefined4 *)0x0) & param_6;
    local_8 = uVar2 + uVar16;
    uVar3 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0x3fc45f306446f9b4);
    uVar4 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0x3fd0000000000000);
    uVar5 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0x3fe0000000000000);
    uVar6 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0x401921fb60000000);
    uVar7 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0xc00921fb60000000);
    uVar8 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0xbe90f02c6b8de73b);
    uVar9 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0x3ef9f6b4176d5bad);
    uVar10 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0xbf56c13745d11568);
    uVar11 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0x3fa555547fbaf47e);
    uVar12 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0xbfdffffffc06f3a6);
    local_10 = _malloc(local_8 * 0x6c);
    if (local_10 == (undefined4 *)0x0) {
      param_6 = -0x7ff8fff2;
      iVar1 = param_6;
      goto LAB_005dad83;
    }
    uVar14 = 0;
    puVar13 = local_10;
    do {
      local_7c[uVar14] = puVar13;
      uVar14 = uVar14 + 1;
      puVar13 = puVar13 + local_8;
    } while (uVar14 < 0x1b);
    uVar14 = 0;
    do {
      uVar17 = FUN_005d91c9(local_7c[uVar14],local_8);
      iVar1 = (int)uVar17;
      if ((int)uVar17 < 0) goto LAB_005dad83;
      uVar14 = (int)((ulonglong)uVar17 >> 0x20) + 1;
    } while (uVar14 < 0xf);
    param_6 = 0;
    if (local_8 != 0) {
      local_c = (undefined4 *)(param_3 + uVar16 * -4);
      puVar13 = local_7c[0xf];
      do {
        if (param_6 < uVar16) {
          uVar15 = *(undefined4 *)((int)puVar13 + ((int)param_4 - (int)local_7c[0xf]));
        }
        else {
          uVar15 = *(undefined4 *)(((int)param_5 - param_3) + (int)local_c);
        }
        *puVar13 = uVar15;
        *(undefined4 *)((int)puVar13 + (local_3c - (int)local_7c[0xf])) = uVar3;
        uVar15 = uVar4;
        if (uVar16 <= param_6) {
          uVar15 = uVar5;
        }
        *(undefined4 *)((int)puVar13 + (local_38 - (int)local_7c[0xf])) = uVar15;
        *(undefined4 *)((int)puVar13 + (local_34 - (int)local_7c[0xf])) = uVar6;
        *(undefined4 *)((int)puVar13 + (local_30 - (int)local_7c[0xf])) = uVar7;
        *(undefined4 *)((int)puVar13 + (local_2c - (int)local_7c[0xf])) = uVar8;
        *(undefined4 *)((int)puVar13 + (local_28 - (int)local_7c[0xf])) = uVar9;
        *(undefined4 *)((int)puVar13 + (local_24 - (int)local_7c[0xf])) = uVar10;
        *(undefined4 *)((int)puVar13 + (local_20 - (int)local_7c[0xf])) = uVar11;
        *(undefined4 *)((int)puVar13 + (local_1c - (int)local_7c[0xf])) = uVar12;
        *(undefined4 *)((int)puVar13 + (local_18 - (int)local_7c[0xf])) =
             *(undefined4 *)(param_1 + 0x20);
        if (param_6 < uVar16) {
          uVar15 = *(undefined4 *)((int)puVar13 + (param_3 - (int)local_7c[0xf]));
        }
        else {
          uVar15 = *local_c;
        }
        param_6 = param_6 + 1;
        local_c = local_c + 1;
        *(undefined4 *)((int)puVar13 + (local_14 - (int)local_7c[0xf])) = uVar15;
        puVar13 = puVar13 + 1;
      } while (param_6 < local_8);
    }
    local_c = (undefined4 *)(local_8 & 0xffffff);
    param_3 = CONCAT13(0x25,(int3)local_8);
    iVar1 = FUN_005d9fa1(param_2,param_3,local_7c[0],local_14,local_3c,0);
    if (iVar1 < 0) goto LAB_005dad83;
    local_8 = (uint)local_c | 0x24000000;
    iVar1 = FUN_005d9fa1(param_2,local_8,local_7c[1],local_7c[0],local_38,0);
    if ((((((((iVar1 < 0) ||
             (iVar1 = FUN_005d9fa1(param_2,(uint)local_c | 0x13000000,local_7c[2],local_7c[1],0,0x14
                                  ), iVar1 < 0)) ||
            (iVar1 = FUN_005d9fa1(param_2,param_3,local_7c[3],local_7c[2],local_34,4), iVar1 < 0))
           || ((iVar1 = FUN_005d9fa1(param_2,local_8,local_7c[4],local_7c[3],local_30,0), iVar1 < 0
               || (iVar1 = FUN_005d9fa1(param_2,param_3,local_7c[5],local_7c[4],local_7c[4],4),
                  iVar1 < 0)))) ||
          ((iVar1 = FUN_005d9fa1(param_2,param_3,local_7c[6],local_7c[5],local_2c,0), iVar1 < 0 ||
           ((iVar1 = FUN_005d9fa1(param_2,local_8,local_7c[7],local_7c[6],local_28,0), iVar1 < 0 ||
            (iVar1 = FUN_005d9fa1(param_2,param_3,local_7c[8],local_7c[5],local_7c[7],0), iVar1 < 0)
            ))))) ||
         (iVar1 = FUN_005d9fa1(param_2,local_8,local_7c[9],local_7c[8],local_24,0), iVar1 < 0)) ||
        (((iVar1 = FUN_005d9fa1(param_2,param_3,local_7c[10],local_7c[5],local_7c[9],0), iVar1 < 0
          || (iVar1 = FUN_005d9fa1(param_2,local_8,local_7c[0xb],local_7c[10],local_20,0), iVar1 < 0
             )) || (iVar1 = FUN_005d9fa1(param_2,param_3,local_7c[0xc],local_7c[5],local_7c[0xb],0),
                   iVar1 < 0)))) ||
       (((iVar1 = FUN_005d9fa1(param_2,local_8,local_7c[0xd],local_7c[0xc],local_1c,0), iVar1 < 0 ||
         (iVar1 = FUN_005d9fa1(param_2,param_3,local_7c[0xe],local_7c[5],local_7c[0xd],0), iVar1 < 0
         )) || (iVar1 = FUN_005d9fa1(param_2,local_8,local_7c[0xf],local_7c[0xe],local_18,0x10),
               iVar1 < 0)))) goto LAB_005dad83;
    puVar13 = local_7c[0xf];
    for (uVar14 = uVar16 & 0x3fffffff; uVar14 != 0; uVar14 = uVar14 - 1) {
      *param_4 = *puVar13;
      puVar13 = puVar13 + 1;
      param_4 = param_4 + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined1 *)param_4 = *(undefined1 *)puVar13;
      puVar13 = (undefined4 *)((int)puVar13 + 1);
      param_4 = (undefined4 *)((int)param_4 + 1);
    }
    puVar13 = local_7c[0xf] + uVar16;
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      *param_5 = *puVar13;
      puVar13 = puVar13 + 1;
      param_5 = param_5 + 1;
    }
  }
  else if (((param_4 != (undefined4 *)0x0) &&
           (iVar1 = FUN_005d9fa1(param_2,param_6 & 0xffffff | 0x17000000,param_4,param_3,0,0x10),
           iVar1 < 0)) ||
          ((param_5 != (undefined4 *)0x0 &&
           (iVar1 = FUN_005d9fa1(param_2,param_6 & 0xffffff | 0x18000000,param_5,param_3,0,0x10),
           iVar1 < 0)))) goto LAB_005dad83;
  param_6 = 0;
  iVar1 = param_6;
LAB_005dad83:
  param_6 = iVar1;
  _free(local_10);
  return param_6;
}


// ==== 0x5dad99 FUN_005dad99

int __thiscall
FUN_005dad99(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,uint param_6)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  void *pvVar8;
  uint *puVar9;
  undefined8 uVar10;
  int local_80 [20];
  uint *local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  void *local_14;
  uint local_10;
  uint local_c;
  undefined4 local_8;
  
  local_14 = (void *)0x0;
  if ((*(byte *)(*(int *)(param_1 + 8) + 0x91) & 1) == 0) {
    local_10 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0xbf932dc60be86b8f);
    local_c = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0x3fb302c4d65e4606);
    uVar3 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0xbfcb26908d815d63);
    uVar4 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0x3ff921b485ae2a4a);
    uVar5 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0xc000000000000000);
    uVar6 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0x400921fb60000000);
    uVar7 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0x3ff921fb60000000);
    local_14 = _malloc(param_6 * 0x6c);
    if (local_14 == (void *)0x0) {
      iVar1 = -0x7ff8fff2;
      goto LAB_005dae13;
    }
    uVar2 = 0;
    pvVar8 = local_14;
    do {
      local_80[uVar2] = (int)pvVar8;
      uVar2 = uVar2 + 1;
      pvVar8 = (void *)((int)pvVar8 + param_6 * 4);
    } while (uVar2 < 0x1b);
    uVar2 = 0;
    do {
      uVar10 = FUN_005d91c9(local_80[uVar2],param_6);
      iVar1 = (int)uVar10;
      if (iVar1 < 0) goto LAB_005dae13;
      uVar2 = (int)((ulonglong)uVar10 >> 0x20) + 1;
    } while (uVar2 < 0x13);
    if (param_6 != 0) {
      local_8 = param_6;
      puVar9 = local_30;
      do {
        *(undefined4 *)((local_80[0x13] - (int)local_30) + (int)puVar9) =
             *(undefined4 *)(param_1 + 0x20);
        *puVar9 = local_10;
        *(uint *)((local_2c - (int)local_30) + (int)puVar9) = local_c;
        *(undefined4 *)((local_28 - (int)local_30) + (int)puVar9) = uVar3;
        *(undefined4 *)((local_24 - (int)local_30) + (int)puVar9) = uVar4;
        *(undefined4 *)((local_20 - (int)local_30) + (int)puVar9) = uVar5;
        *(undefined4 *)((local_1c - (int)local_30) + (int)puVar9) = uVar6;
        *(undefined4 *)((local_18 - (int)local_30) + (int)puVar9) = uVar7;
        puVar9 = puVar9 + 1;
        local_8 = local_8 - 1;
      } while (local_8 != 0);
    }
    uVar2 = param_6 & 0xffffff;
    local_8 = CONCAT13(0x11,(int3)param_6);
    iVar1 = FUN_005d9fa1(param_2,local_8,local_80[0],param_3,0,0);
    if (iVar1 < 0) goto LAB_005dae13;
    iVar1 = FUN_005d9fa1(param_2,uVar2 | 0x21000000,local_80[1],param_3,local_80[0],4);
    if (iVar1 < 0) goto LAB_005dae13;
    iVar1 = FUN_005d9fa1(param_2,local_8,local_80[2],local_80[1],0,8);
    if (iVar1 < 0) goto LAB_005dae13;
    local_c = uVar2 | 0x24000000;
    iVar1 = FUN_005d9fa1(param_2,local_c,local_80[3],local_80[2],local_80[0x13],0);
    if (iVar1 < 0) goto LAB_005dae13;
    iVar1 = FUN_005d9fa1(param_2,uVar2 | 0x16000000,local_80[4],local_80[3],0,4);
    if (iVar1 < 0) goto LAB_005dae13;
    local_10 = uVar2 | 0x25000000;
    iVar1 = FUN_005d9fa1(param_2,local_10,local_80[5],local_30,local_80[1],0);
    if (iVar1 < 0) goto LAB_005dae13;
    iVar1 = FUN_005d9fa1(param_2,local_c,local_80[6],local_80[5],local_2c,0);
    if (iVar1 < 0) goto LAB_005dae13;
    iVar1 = FUN_005d9fa1(param_2,local_10,local_80[7],local_80[6],local_80[1],0);
    if (iVar1 < 0) goto LAB_005dae13;
    iVar1 = FUN_005d9fa1(param_2,local_c,local_80[8],local_80[7],local_28,0);
    if (iVar1 < 0) goto LAB_005dae13;
    iVar1 = FUN_005d9fa1(param_2,local_10,local_80[9],local_80[8],local_80[1],0);
    if (iVar1 < 0) goto LAB_005dae13;
    iVar1 = FUN_005d9fa1(param_2,local_c,local_80[10],local_80[9],local_24,0);
    if (iVar1 < 0) goto LAB_005dae13;
    iVar1 = FUN_005d9fa1(param_2,local_10,local_80[0xb],local_80[10],local_80[4],0);
    if (iVar1 < 0) goto LAB_005dae13;
    iVar1 = FUN_005d9fa1(param_2,local_10,local_80[0xc],local_80[0xb],local_20,0);
    if (iVar1 < 0) goto LAB_005dae13;
    iVar1 = FUN_005d9fa1(param_2,local_c,local_80[0xd],local_80[0xc],local_1c,0);
    if (iVar1 < 0) goto LAB_005dae13;
    iVar1 = FUN_005d9fa1(param_2,uVar2 | 0x22000000,local_80[0xe],param_3,local_80[0],0x2000017);
    if (iVar1 < 0) goto LAB_005dae13;
    iVar1 = FUN_005d9fa1(param_2,local_10,local_80[0xf],local_80[0xd],local_80[0xe],0);
    if (iVar1 < 0) goto LAB_005dae13;
    iVar1 = FUN_005d9fa1(param_2,local_c,local_80[0x10],local_80[0xb],local_80[0xf],4);
    if (iVar1 < 0) goto LAB_005dae13;
    iVar1 = FUN_005d9fa1(param_2,local_8,local_80[0x11],local_80[0x10],0,8);
    if (iVar1 < 0) goto LAB_005dae13;
    iVar1 = FUN_005d9fa1(param_2,local_c,local_80[0x12],local_80[0x11],local_18,0);
    if (iVar1 < 0) goto LAB_005dae13;
    if (param_4 != 0) {
      iVar1 = FUN_005d9fa1(param_2,uVar2 | 0x10000000,param_4,local_80[0x12],0,0);
      if (iVar1 < 0) goto LAB_005dae13;
    }
    if (param_5 != 0) {
      uVar2 = uVar2 | 0x10000000;
      param_3 = local_80[0x10];
      goto LAB_005dadfd;
    }
  }
  else {
    if (param_4 != 0) {
      iVar1 = FUN_005d9fa1(param_2,param_6 & 0xffffff | 0x19000000,param_4,param_3,0,0);
      if (iVar1 < 0) goto LAB_005dae13;
    }
    if (param_5 != 0) {
      uVar2 = param_6 & 0xffffff | 0x1a000000;
LAB_005dadfd:
      iVar1 = FUN_005d9fa1(param_2,uVar2,param_5,param_3,0x400000000);
      if (iVar1 < 0) goto LAB_005dae13;
    }
  }
  iVar1 = 0;
LAB_005dae13:
  _free(local_14);
  return iVar1;
}


// ==== 0x5db2b5 FUN_005db2b5

int __thiscall
FUN_005db2b5(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
            uint param_6)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint *puVar7;
  int iVar8;
  void *pvVar9;
  undefined8 uVar10;
  int local_e0 [40];
  uint *local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  void *local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  undefined4 local_10;
  uint local_c;
  uint local_8;
  
  local_20 = (void *)0x0;
  if ((*(byte *)(*(int *)(param_1 + 8) + 0x91) & 1) == 0) {
    local_10 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0x3f9555cbe46f80c1);
    local_c = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0xbfb5cb46bacf7447);
    local_8 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0x3fc70edc3bd59924);
    uVar2 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0xbfd523a08398a655);
    uVar3 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0x3feffee6fb4c3c19);
    uVar4 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0xc000000000000000);
    uVar5 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0x3ff921fb60000000);
    uVar6 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0xc00921fb60000000);
    local_20 = _malloc(param_6 * 0xc0);
    if (local_20 == (void *)0x0) {
      iVar8 = -0x7ff8fff2;
      goto LAB_005dbad6;
    }
    uVar1 = 0;
    pvVar9 = local_20;
    do {
      local_e0[uVar1] = (int)pvVar9;
      uVar1 = uVar1 + 1;
      pvVar9 = (void *)((int)pvVar9 + param_6 * 4);
    } while (uVar1 < 0x30);
    uVar1 = 0;
    do {
      uVar10 = FUN_005d91c9(local_e0[uVar1],param_6);
      iVar8 = (int)uVar10;
      if (iVar8 < 0) goto LAB_005dbad6;
      uVar1 = (int)((ulonglong)uVar10 >> 0x20) + 1;
    } while (uVar1 < 0x27);
    if (param_6 != 0) {
      local_18 = local_3c - (int)local_40;
      local_1c = local_24 - (int)local_40;
      local_14 = param_6;
      puVar7 = local_40;
      do {
        *(undefined4 *)((local_e0[0x27] - (int)local_40) + (int)puVar7) = local_10;
        *puVar7 = local_c;
        *(uint *)(local_18 + (int)puVar7) = local_8;
        *(undefined4 *)((local_38 - (int)local_40) + (int)puVar7) = uVar2;
        *(undefined4 *)((local_34 - (int)local_40) + (int)puVar7) = uVar3;
        *(undefined4 *)((local_30 - (int)local_40) + (int)puVar7) = uVar4;
        *(undefined4 *)((local_2c - (int)local_40) + (int)puVar7) = uVar5;
        *(undefined4 *)((local_28 - (int)local_40) + (int)puVar7) = uVar6;
        *(undefined4 *)(local_1c + (int)puVar7) = *(undefined4 *)(param_1 + 0x20);
        puVar7 = puVar7 + 1;
        local_14 = local_14 - 1;
      } while (local_14 != 0);
    }
    if (param_4 == 0) {
      param_4 = local_24;
    }
    local_c = param_6 & 0xffffff;
    local_10 = CONCAT13(0x11,(int3)param_6);
    iVar8 = FUN_005d9fa1(param_2,local_10,local_e0[0],param_3,0,0);
    if (iVar8 < 0) goto LAB_005dbad6;
    local_14 = local_c | 0x21000000;
    iVar8 = FUN_005d9fa1(param_2,local_14,local_e0[1],param_3,local_e0[0],4);
    if (((iVar8 < 0) || (iVar8 = FUN_005d9fa1(param_2,local_10,local_e0[2],param_4,0,0), iVar8 < 0))
       || (iVar8 = FUN_005d9fa1(param_2,local_14,local_e0[3],param_4,local_e0[2],4), iVar8 < 0))
    goto LAB_005dbad6;
    local_1c = local_c | 0x20000000;
    iVar8 = FUN_005d9fa1(param_2,local_1c,local_e0[4],local_e0[1],local_e0[3],4);
    if (((iVar8 < 0) ||
        (iVar8 = FUN_005d9fa1(param_2,local_14,local_e0[5],local_e0[1],local_e0[3],4), iVar8 < 0))
       || (iVar8 = FUN_005d9fa1(param_2,local_c | 0x12000000,local_e0[6],local_e0[5],0,4), iVar8 < 0
          )) goto LAB_005dbad6;
    uVar1 = local_c | 0x25000000;
    iVar8 = FUN_005d9fa1(param_2,uVar1,local_e0[7],local_e0[4],local_e0[6],0x14);
    if (((iVar8 < 0) ||
        (iVar8 = FUN_005d9fa1(param_2,uVar1,local_e0[8],local_e0[7],local_e0[7],0x14), iVar8 < 0))
       || (iVar8 = FUN_005d9fa1(param_2,uVar1,local_e0[9],local_e0[8],local_e0[0x27],0), iVar8 < 0))
    goto LAB_005dbad6;
    local_8 = local_c | 0x24000000;
    iVar8 = FUN_005d9fa1(param_2,local_8,local_e0[10],local_e0[9],local_40,0);
    if ((((((iVar8 < 0) ||
           (iVar8 = FUN_005d9fa1(param_2,uVar1,local_e0[0xb],local_e0[8],local_e0[10],0), iVar8 < 0)
           ) || (iVar8 = FUN_005d9fa1(param_2,local_8,local_e0[0xc],local_e0[0xb],local_3c,0),
                iVar8 < 0)) ||
         ((iVar8 = FUN_005d9fa1(param_2,uVar1,local_e0[0xd],local_e0[8],local_e0[0xc],0), iVar8 < 0
          || (iVar8 = FUN_005d9fa1(param_2,local_8,local_e0[0xe],local_e0[0xd],local_38,0),
             iVar8 < 0)))) ||
        (iVar8 = FUN_005d9fa1(param_2,uVar1,local_e0[0xf],local_e0[8],local_e0[0xe],0), iVar8 < 0))
       || ((iVar8 = FUN_005d9fa1(param_2,local_8,local_e0[0x10],local_e0[0xf],local_34,0), iVar8 < 0
           || (iVar8 = FUN_005d9fa1(param_2,uVar1,local_e0[0x11],local_e0[7],local_e0[0x10],0),
              iVar8 < 0)))) goto LAB_005dbad6;
    local_18 = local_c | 0x22000000;
    iVar8 = FUN_005d9fa1(param_2,local_18,local_e0[0x12],local_e0[3],local_e0[1],0x2000017);
    if (((((iVar8 < 0) ||
          (((iVar8 = FUN_005d9fa1(param_2,uVar1,local_e0[0x13],local_e0[0x11],local_30,0), iVar8 < 0
            || (iVar8 = FUN_005d9fa1(param_2,local_8,local_e0[0x14],local_e0[0x13],local_2c,0),
               iVar8 < 0)) ||
           (iVar8 = FUN_005d9fa1(param_2,uVar1,local_e0[0x15],local_e0[0x14],local_e0[0x12],0),
           iVar8 < 0)))) ||
         ((((iVar8 = FUN_005d9fa1(param_2,local_8,local_e0[0x16],local_e0[0x15],local_e0[0x11],0),
            iVar8 < 0 ||
            (iVar8 = FUN_005d9fa1(param_2,local_18,local_e0[0x1a],param_4,local_e0[2],0x2000017),
            iVar8 < 0)) ||
           (iVar8 = FUN_005d9fa1(param_2,uVar1,local_e0[0x1b],local_e0[0x1a],local_28,0), iVar8 < 0)
           ) || ((iVar8 = FUN_005d9fa1(param_2,local_8,local_e0[0x1c],local_e0[0x16],local_e0[0x1b],
                                       0), iVar8 < 0 ||
                 (iVar8 = FUN_005d9fa1(param_2,local_1c,local_e0[0x1d],param_3,param_4,0), iVar8 < 0
                 )))))) ||
        ((iVar8 = FUN_005d9fa1(param_2,local_14,local_e0[0x1e],param_3,param_4,0), iVar8 < 0 ||
         (((iVar8 = FUN_005d9fa1(param_2,local_10,local_e0[0x1f],local_e0[0x1d],0,0), iVar8 < 0 ||
           (iVar8 = FUN_005d9fa1(param_2,local_18,local_e0[0x20],local_e0[0x1d],local_e0[0x1f],
                                 0x2000017), iVar8 < 0)) ||
          (iVar8 = FUN_005d9fa1(param_2,local_10,local_e0[0x21],local_e0[0x1e],0,0), iVar8 < 0))))))
       || (((iVar8 = FUN_005d9fa1(param_2,local_c | 0x23000000,local_e0[0x22],local_e0[0x1e],
                                  local_e0[0x21],0x2000017), iVar8 < 0 ||
            (iVar8 = FUN_005d9fa1(param_2,uVar1,local_e0[0x23],local_e0[0x20],local_e0[0x22],
                                  0x2000017), iVar8 < 0)) ||
           ((iVar8 = FUN_005d9fa1(param_2,local_8,local_e0[0x24],local_e0[0x1c],local_e0[0x1c],0),
            iVar8 < 0 ||
            ((iVar8 = FUN_005d9fa1(param_2,local_10,local_e0[0x25],local_e0[0x24],0,0), iVar8 < 0 ||
             (iVar8 = FUN_005d9fa1(param_2,uVar1,local_e0[0x26],local_e0[0x23],local_e0[0x25],0),
             uVar1 = local_8, iVar8 < 0)))))))) goto LAB_005dbad6;
  }
  else {
    local_e0[0x1c] = param_3;
    if (param_4 == 0) {
      local_e0[0x26] = 0;
      uVar1 = param_6 & 0xffffff | 0x1b000000;
    }
    else {
      uVar1 = param_6 & 0xffffff | 0x26000000;
      local_e0[0x26] = param_4;
    }
  }
  iVar8 = FUN_005d9fa1(param_2,uVar1,param_5,local_e0[0x1c],local_e0[0x26]);
  if (-1 < iVar8) {
    iVar8 = 0;
  }
LAB_005dbad6:
  _free(local_20);
  return iVar8;
}


// ==== 0x5dbae8 FUN_005dbae8

int __thiscall
FUN_005dbae8(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5,int param_6,
            uint param_7)

{
  uint uVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int local_1c [3];
  undefined4 *local_10;
  undefined4 *local_c;
  void *local_8;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 8) + 0x90);
  if ((char)uVar1 < '\0') {
    uVar2 = 0;
    if (param_7 != 0) {
      do {
        if ((*(byte *)(*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x14) +
                               *(int *)(param_6 + uVar2 * 4) * 4) + 0x18) & 1) == 0) break;
        uVar2 = uVar2 + 1;
      } while (uVar2 < param_7);
    }
    if (uVar2 != param_7) goto LAB_005dbc01;
    local_8 = _malloc(param_7 * 0xc);
    if (local_8 == (void *)0x0) goto LAB_005dbd44;
    uVar1 = 0;
    pvVar3 = local_8;
    do {
      local_1c[uVar1 + 2] = (int)pvVar3;
      uVar1 = uVar1 + 1;
      pvVar3 = (void *)((int)pvVar3 + param_7 * 4);
    } while (uVar1 < 3);
    if (param_7 != 0) {
      param_5 = param_5 - (int)local_10;
      iVar4 = param_4 - (int)local_10;
      iVar5 = (int)local_c - (int)local_10;
      param_4 = param_7;
      do {
        *local_10 = *(undefined4 *)(iVar4 + (int)local_10);
        *(undefined4 *)(iVar5 + (int)local_10) = *(undefined4 *)(param_5 + (int)local_10);
        local_10 = local_10 + 1;
        param_4 = param_4 - 1;
      } while (param_4 != 0);
    }
    iVar4 = FUN_005d91c9(local_1c[2],param_7);
    if ((iVar4 < 0) || (iVar4 = FUN_005d91c9(param_3,param_7), iVar4 < 0)) goto LAB_005dbd1e;
    iVar4 = FUN_005d9fa1(param_2,param_7 & 0xffffff | 0x11000000,local_1c[2],param_6,0,0x1a);
    if (iVar4 < 0) goto LAB_005dbd1e;
    local_10 = (undefined4 *)(param_7 * 4 + (int)local_8);
    param_7 = param_7 & 0xffffff | 0x50000000;
LAB_005dbd0c:
    iVar4 = FUN_005d9fa1(param_2,param_7,param_3,local_1c[2],local_10,0);
    if (-1 < iVar4) {
      iVar4 = 0;
    }
  }
  else {
LAB_005dbc01:
    if ((uVar1 & 0x1000000) == 0) {
      local_8 = _malloc(param_7 * 0xc);
      if (local_8 != (void *)0x0) {
        uVar1 = 0;
        pvVar3 = local_8;
        do {
          local_1c[uVar1 + 2] = (int)pvVar3;
          uVar1 = uVar1 + 1;
          pvVar3 = (void *)((int)pvVar3 + param_7 * 4);
        } while (uVar1 < 3);
        iVar4 = FUN_005d91c9(local_1c[2],param_7);
        if (((iVar4 < 0) || (iVar4 = FUN_005d91c9(local_10,param_7), iVar4 < 0)) ||
           ((iVar4 = FUN_005d91c9(local_c,param_7), iVar4 < 0 ||
            (iVar4 = FUN_005d91c9(param_3,param_7), iVar4 < 0)))) goto LAB_005dbd1e;
        uVar1 = param_7 & 0xffffff;
        iVar4 = FUN_005d9fa1(param_2,uVar1 | 0x11000000,local_1c[2],param_4,0,0);
        if (iVar4 < 0) goto LAB_005dbd1e;
        param_7 = CONCAT13(0x24,(undefined3)param_7);
        iVar4 = FUN_005d9fa1(param_2,param_7,local_10,param_5,local_1c[2],0);
        if (iVar4 < 0) goto LAB_005dbd1e;
        iVar4 = FUN_005d9fa1(param_2,uVar1 | 0x25000000,local_c,param_6,local_10,0);
        local_1c[2] = param_4;
        local_10 = local_c;
joined_r0x005dbe6b:
        if (iVar4 < 0) goto LAB_005dbd1e;
        param_7 = CONCAT13(0x24,(undefined3)param_7);
        goto LAB_005dbd0c;
      }
    }
    else {
      local_8 = _malloc(param_7 * 0x14);
      if (local_8 != (void *)0x0) {
        uVar1 = 0;
        pvVar3 = local_8;
        do {
          local_1c[uVar1] = (int)pvVar3;
          uVar1 = uVar1 + 1;
          pvVar3 = (void *)((int)pvVar3 + param_7 * 4);
        } while (uVar1 < 5);
        uVar1 = 0;
        if (param_7 != 0) {
          do {
            local_c[uVar1] = *(undefined4 *)(param_1 + 0x20);
            uVar1 = uVar1 + 1;
          } while (uVar1 < param_7);
        }
        iVar4 = FUN_005d91c9(local_1c[0],param_7);
        if ((((iVar4 < 0) || (iVar4 = FUN_005d91c9(local_1c[1],param_7), iVar4 < 0)) ||
            (iVar4 = FUN_005d91c9(local_1c[2],param_7), iVar4 < 0)) ||
           ((iVar4 = FUN_005d91c9(local_10,param_7), iVar4 < 0 ||
            (iVar4 = FUN_005d91c9(param_3,param_7), iVar4 < 0)))) goto LAB_005dbd1e;
        uVar1 = param_7 & 0xffffff;
        iVar4 = FUN_005d9fa1(param_2,uVar1 | 0x11000000,local_1c[0],param_6,0,0);
        if (iVar4 < 0) goto LAB_005dbd1e;
        param_7 = CONCAT13(0x24,(undefined3)param_7);
        iVar4 = FUN_005d9fa1(param_2,param_7,local_1c[1],local_1c[0],local_c,0);
        if (iVar4 < 0) goto LAB_005dbd1e;
        uVar1 = uVar1 | 0x25000000;
        iVar4 = FUN_005d9fa1(param_2,uVar1,local_1c[2],local_1c[1],param_4,0);
        if (iVar4 < 0) goto LAB_005dbd1e;
        iVar4 = FUN_005d9fa1(param_2,uVar1,local_10,param_6,param_5,0);
        goto joined_r0x005dbe6b;
      }
    }
LAB_005dbd44:
    iVar4 = -0x7ff8fff2;
  }
LAB_005dbd1e:
  _free(local_8);
  return iVar4;
}


// ==== 0x5dbe7e FUN_005dbe7e

undefined4 FUN_005dbe7e(undefined4 param_1,int param_2,int param_3)

{
  uint *_Memory;
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  
  _Memory = _malloc(param_3 << 2);
  if (_Memory == (uint *)0x0) {
    uVar1 = 0x8007000e;
  }
  else {
    FUN_005da405(param_1,_Memory);
    if (param_3 != 0) {
      puVar3 = _Memory;
      do {
        iVar2 = FUN_005f762c(*(undefined4 *)((param_2 - (int)_Memory) + (int)puVar3));
        *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) | *puVar3;
        puVar3 = puVar3 + 1;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
    _free(_Memory);
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x5dbee8 FUN_005dbee8

int __thiscall
FUN_005dbee8(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6,
            int param_7,undefined4 *param_8,int param_9,int param_10,undefined4 *param_11)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined1 local_1c [4];
  uint local_18;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  local_10 = 0;
  if (param_2 != 0) {
    if ((param_5 == 0) && (param_9 != 0)) {
      param_7 = param_9;
      param_8 = &local_10;
      param_5 = 1;
    }
    if (((param_6 == 0) && (param_10 != 0)) && (*(int *)(param_1 + 0x50) == 0)) {
      param_9 = 0;
      local_8 = 0;
      iVar4 = 0;
      do {
        iVar3 = *(int *)(param_10 + 8);
        iVar6 = iVar4;
        iVar2 = local_8;
        if (*(int *)(iVar3 + 4) == 0x10) {
          iVar1 = *(int *)(*(int *)(iVar3 + 0x14) + 0x18);
          iVar2 = iVar1;
          if (((*(int *)(iVar3 + 0x10) != 0) &&
              (iVar3 = FUN_005d7700(*(undefined4 *)(*(int *)(iVar3 + 0x10) + 0x18),0,local_1c),
              iVar2 = local_8, -1 < iVar3)) &&
             ((iVar6 = iVar1, *(uint *)(param_1 + 0x10) != local_18 &&
              (iVar6 = iVar4, (*(uint *)(param_1 + 0x10) & 0xffff0000) == local_18)))) {
            param_9 = iVar1;
          }
        }
        local_8 = iVar2;
        param_10 = *(int *)(param_10 + 0xc);
        iVar4 = iVar6;
      } while (param_10 != 0);
      if (((iVar6 != 0) || (iVar6 = param_9, param_9 != 0)) || (iVar6 = local_8, local_8 != 0)) {
        iVar4 = FUN_005f7616(param_4);
        if (iVar4 == 0) {
          return -0x7fffbffb;
        }
        param_4 = FUN_005f7580(iVar4);
        piVar5 = (int *)FUN_005f7616(param_4);
        if (piVar5 == (int *)0x0) {
          return -0x7ff8fff2;
        }
        *(ushort *)(piVar5 + 1) = *(ushort *)(piVar5 + 1) | 0x620;
        *piVar5 = iVar6;
        param_6 = 1;
      }
    }
    iVar4 = FUN_005da560(param_2,param_3,param_4,param_5,param_6,param_7,param_8,&local_c);
    if (iVar4 < 0) {
      return iVar4;
    }
  }
  if (param_11 != (undefined4 *)0x0) {
    *param_11 = local_c;
  }
  return 0;
}


// ==== 0x5dc02b FUN_005dc02b

int __thiscall
FUN_005dc02b(int param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 *param_5)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  void *pvVar4;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint uVar8;
  size_t _Size;
  int *piVar9;
  int local_64 [3];
  undefined4 *local_58;
  undefined4 local_54;
  int iStack_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 *local_40;
  void *local_3c;
  int local_38;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  local_18 = (int *)0x0;
  local_10 = (int *)0x0;
  local_14 = (int *)0x0;
  local_3c = (void *)0x0;
  local_40 = (undefined4 *)0x0;
  local_1c = (undefined4 *)0x0;
  local_20 = (undefined4 *)0x0;
  local_4c = 0;
  local_38 = 0;
  local_c = 0;
  if ((param_3 != 0) && (*(int *)(param_3 + 4) == 0xc)) {
    uVar8 = *(int *)(param_3 + 0x18) * *(int *)(param_3 + 0x14);
    local_c = uVar8;
    local_40 = _malloc(uVar8 * 8);
    if (local_40 != (undefined4 *)0x0) {
      local_20 = local_40 + uVar8;
      local_1c = local_40;
      goto LAB_005dc08d;
    }
    goto LAB_005dc5da;
  }
LAB_005dc08d:
  local_40 = local_1c;
  iVar1 = FUN_005e2a38(param_2,&local_2c);
  if (iVar1 < 0) goto LAB_005dc5df;
  iVar1 = FUN_005d9413(local_2c,&local_54);
  if (-1 < iVar1) {
    puVar6 = local_20;
    if ((double)CONCAT44(iStack_50,local_54) != 0.0) {
      puVar6 = local_1c;
      param_4 = param_3;
    }
    if (local_c == 0) {
      iVar1 = FUN_005dc760(param_4);
    }
    else {
      iVar1 = FUN_005e2a38(param_4,puVar6);
    }
    goto LAB_005dc5df;
  }
  local_44 = 0xffffffff;
  local_24 = 0xffffffff;
  local_30 = 0xffffffff;
  local_28 = 0xffffffff;
  local_48 = 0xffffffff;
  iVar1 = FUN_005d9fa1(param_2,0x11000001,&local_44,&local_2c,0,0);
  if ((((iVar1 < 0) ||
       (iVar1 = FUN_005d9fa1(param_2,0x21000001,&local_24,&local_2c,&local_44,4), iVar1 < 0)) ||
      (iVar1 = FUN_005d9fa1(param_2,0x11000001,&local_30,&local_24,0,8), iVar1 < 0)) ||
     ((iVar1 = FUN_005d9fa1(param_2,0x22000001,&local_28,&local_30,&local_24,0x2000017), iVar1 < 0
      || (iVar1 = FUN_005d9fa1(param_2,0x23000001,&local_48,&local_30,&local_24,0x2000017),
         iVar1 < 0)))) goto LAB_005dc5df;
  uVar8 = *(uint *)(*(int *)(param_1 + 4) + 0x18);
  _Size = uVar8 << 2;
  local_8 = uVar8;
  local_18 = _malloc(_Size);
  if ((local_18 == (int *)0x0) ||
     ((local_10 = _malloc(_Size), local_10 == (int *)0x0 ||
      (local_14 = _malloc(_Size), local_14 == (int *)0x0)))) {
LAB_005dc5da:
    iVar1 = -0x7ff8fff2;
  }
  else {
    piVar7 = *(int **)(param_1 + 0x18);
    piVar9 = local_18;
    for (uVar8 = uVar8 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
      *piVar9 = *piVar7;
      piVar7 = piVar7 + 1;
      piVar9 = piVar9 + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(char *)piVar9 = (char)*piVar7;
      piVar7 = (int *)((int)piVar7 + 1);
      piVar9 = (int *)((int)piVar9 + 1);
    }
    if (param_3 == 0) {
      local_1c = local_20;
      piVar7 = local_18;
      piVar9 = local_10;
      for (uVar8 = local_8 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
        *piVar9 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar9 = piVar9 + 1;
      }
      for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(char *)piVar9 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar9 = (int *)((int)piVar9 + 1);
      }
    }
    else {
      piVar7 = (int *)(param_1 + 0x2c);
      local_4c = *piVar7;
      iVar1 = FUN_005d9fa1(param_2,0x25000001,piVar7,piVar7,&local_28,0x2000017);
      if (iVar1 < 0) goto LAB_005dc5df;
      if (local_c == 0) {
        iVar1 = FUN_005dc760(param_3);
      }
      else {
        iVar1 = FUN_005e2a38(param_3,local_1c);
      }
      if (iVar1 < 0) goto LAB_005dc5df;
      *piVar7 = local_4c;
      piVar7 = *(int **)(param_1 + 0x18);
      piVar9 = local_10;
      for (uVar8 = local_8 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
        *piVar9 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar9 = piVar9 + 1;
      }
      for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(char *)piVar9 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar9 = (int *)((int)piVar9 + 1);
      }
      piVar7 = local_18;
      piVar9 = *(int **)(param_1 + 0x18);
      for (uVar8 = local_8 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
        *piVar9 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar9 = piVar9 + 1;
      }
      for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(char *)piVar9 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar9 = (int *)((int)piVar9 + 1);
      }
      local_4c = *(int *)(param_1 + 0x38);
      *(undefined4 *)(param_1 + 0x38) = 0;
    }
    if (param_4 == 0) {
      local_20 = local_1c;
      piVar7 = local_18;
      piVar9 = local_14;
      for (uVar8 = local_8 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
        *piVar9 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar9 = piVar9 + 1;
      }
      for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(char *)piVar9 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar9 = (int *)((int)piVar9 + 1);
      }
    }
    else {
      puVar6 = (undefined4 *)(param_1 + 0x2c);
      uVar3 = *puVar6;
      iVar1 = FUN_005d9fa1(param_2,0x25000001,puVar6,puVar6,&local_48,0x2000017);
      if (iVar1 < 0) goto LAB_005dc5df;
      if (local_c == 0) {
        iVar1 = FUN_005dc760(param_4);
      }
      else {
        iVar1 = FUN_005e2a38(param_4,local_20);
      }
      if (iVar1 < 0) goto LAB_005dc5df;
      *puVar6 = uVar3;
      piVar7 = *(int **)(param_1 + 0x18);
      piVar9 = local_14;
      for (uVar8 = local_8 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
        *piVar9 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar9 = piVar9 + 1;
      }
      for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(char *)piVar9 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar9 = (int *)((int)piVar9 + 1);
      }
      piVar7 = local_18;
      piVar9 = *(int **)(param_1 + 0x18);
      for (uVar8 = local_8 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
        *piVar9 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar9 = piVar9 + 1;
      }
      for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(char *)piVar9 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar9 = (int *)((int)piVar9 + 1);
      }
      local_38 = *(int *)(param_1 + 0x38);
      *(undefined4 *)(param_1 + 0x38) = 0;
    }
    param_4 = 0;
    param_3 = local_c;
    if (local_8 != 0) {
      local_34 = (int)local_14 - (int)local_10;
      piVar7 = local_10;
      do {
        iVar1 = *piVar7;
        piVar9 = (int *)(local_34 + (int)piVar7);
        if (iVar1 != *piVar9) {
          if ((iVar1 == -1) ||
             (piVar2 = (int *)FUN_005f762c(iVar1), *(int *)(*(int *)(param_1 + 8) + 0x4c) == *piVar2
             )) {
            iVar1 = *piVar9;
            *piVar7 = iVar1;
            *(int *)(*(int *)(param_1 + 0x18) + param_4 * 4) = iVar1;
          }
          else if ((*piVar9 == -1) ||
                  (piVar2 = (int *)FUN_005f762c(*piVar9),
                  *(int *)(*(int *)(param_1 + 8) + 0x4c) == *piVar2)) {
            iVar1 = *piVar7;
            *piVar9 = iVar1;
            *(int *)(*(int *)(param_1 + 0x18) + param_4 * 4) = iVar1;
          }
          else {
            param_3 = param_3 + 1;
          }
        }
        param_4 = param_4 + 1;
        piVar7 = piVar7 + 1;
      } while (param_4 < local_8);
    }
    if (param_3 != 0) {
      local_3c = _malloc(param_3 << 4);
      if (local_3c == (void *)0x0) goto LAB_005dc5da;
      uVar8 = 0;
      pvVar4 = local_3c;
      do {
        local_64[uVar8] = (int)pvVar4;
        uVar8 = uVar8 + 1;
        pvVar4 = (void *)((int)pvVar4 + param_3 * 4);
      } while (uVar8 < 4);
      uVar8 = 0;
      puVar6 = local_1c;
      if (local_c != 0) {
        puVar6 = (undefined4 *)(local_64[0] - (int)local_1c);
        local_20 = (undefined4 *)((int)local_20 - (int)local_1c);
        iVar1 = local_64[1] - (int)local_1c;
        iStack_50 = local_64[2] - (int)local_1c;
        local_34 = local_c;
        do {
          *(undefined4 *)((int)puVar6 + (int)local_1c) = local_28;
          *(undefined4 *)(iVar1 + (int)local_1c) = *local_1c;
          *(undefined4 *)(iStack_50 + (int)local_1c) =
               *(undefined4 *)((int)local_20 + (int)local_1c);
          local_1c = local_1c + 1;
          local_34 = local_34 - 1;
          uVar8 = local_c;
        } while (local_34 != 0);
      }
      local_1c = puVar6;
      if (local_8 != 0) {
        puVar6 = (undefined4 *)(local_64[1] + uVar8 * 4);
        iStack_50 = local_64[0] - local_64[1];
        local_20 = (undefined4 *)(local_64[2] - local_64[1]);
        local_34 = local_8;
        piVar7 = local_14;
        do {
          if (*(int *)(((int)local_10 - (int)local_14) + (int)piVar7) != *piVar7) {
            *(undefined4 *)(iStack_50 + (int)puVar6) = local_28;
            *puVar6 = *(undefined4 *)(((int)local_10 - (int)local_14) + (int)piVar7);
            *(int *)((int)local_20 + (int)puVar6) = *piVar7;
            puVar6 = puVar6 + 1;
          }
          piVar7 = piVar7 + 1;
          local_34 = local_34 - 1;
        } while (local_34 != 0);
      }
      iVar1 = FUN_005dbae8(param_2,local_58,local_64[2],local_64[1],local_64[0],param_3);
      if (iVar1 < 0) goto LAB_005dc5df;
      uVar8 = local_c;
      puVar6 = local_58;
      if (param_5 != (undefined4 *)0x0) {
        for (; uVar8 != 0; uVar8 = uVar8 - 1) {
          *param_5 = *puVar6;
          puVar6 = puVar6 + 1;
          param_5 = param_5 + 1;
        }
      }
      uVar8 = 0;
      if (local_8 != 0) {
        puVar6 = local_58 + local_c;
        uVar5 = (int)local_14 - (int)local_10;
        local_34 = uVar5;
        do {
          if (local_10[uVar8] != *(int *)(uVar5 + (int)(local_10 + uVar8))) {
            uVar3 = FUN_005f762c(*(undefined4 *)(*(int *)(param_1 + 0x18) + uVar8 * 4));
            iVar1 = FUN_005f762c(*puVar6);
            FUN_005f7cfc(uVar3);
            *(undefined4 *)(*(int *)(param_1 + 0x18) + uVar8 * 4) = *puVar6;
            *(uint *)(iVar1 + 0x1c) = uVar8;
            puVar6 = puVar6 + 1;
            uVar5 = local_34;
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < local_8);
      }
    }
    iVar1 = 0;
    if ((local_4c == 0) || (local_38 == 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
    *(undefined4 *)(param_1 + 0x38) = uVar3;
    if (local_4c != local_38) {
      FUN_005d9de1(param_1,param_2,0xdac,"asymetric returns from if statements not yet implemented")
      ;
      iVar1 = -0x7fffbfff;
    }
  }
LAB_005dc5df:
  _free(local_18);
  _free(local_10);
  _free(local_14);
  _free(local_3c);
  _free(local_40);
  return iVar1;
}


// ==== 0x5dc613 FUN_005dc613

undefined4
FUN_005dc613(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_8;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    local_8 = 0;
    iVar2 = FUN_005f7616(param_3);
    if (iVar2 == 0) {
      uVar1 = 0x80004005;
    }
    else {
      uVar1 = FUN_005f7580(iVar2);
      iVar2 = FUN_005f7616(uVar1);
      if (iVar2 == 0) {
        uVar1 = 0x8007000e;
      }
      else {
        *(ushort *)(iVar2 + 4) = *(ushort *)(iVar2 + 4) | 0x220;
        uVar1 = FUN_005dbee8(param_1,param_2,uVar1,param_4,param_5,param_6,&local_8,param_6,param_7,
                             0);
      }
    }
  }
  return uVar1;
}


// ==== 0x5dc68d FUN_005dc68d

int __thiscall FUN_005dc68d(int param_1,int param_2,int *param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint local_8;
  
  bVar1 = true;
  if (param_4 != 0) {
    local_8 = param_4;
    piVar4 = param_3;
    do {
      while( true ) {
        iVar2 = FUN_005f762c();
        if ((*(int *)(iVar2 + 0x20) == -1) || (*(int *)(iVar2 + 4) != -1)) break;
        *piVar4 = *(int *)(iVar2 + 0x20);
      }
      iVar3 = FUN_005f7616();
      if (((*(byte *)(iVar3 + 4) & 0x80) == 0) || (*(int *)(iVar2 + 4) != -1)) {
        bVar1 = false;
      }
      piVar4 = piVar4 + 1;
      local_8 = local_8 - 1;
    } while (local_8 != 0);
  }
  uVar5 = 0;
  if ((param_2 != 0) && (bVar1)) {
    if (param_4 != 0) {
      do {
        iVar2 = FUN_005f762c();
        iVar2 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,
                             *(undefined8 *)(iVar2 + 0x10));
        param_3[uVar5] = iVar2;
        if (iVar2 == -1) {
          return -0x7ff8fff2;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_4);
    }
    iVar2 = FUN_005dc613(param_2,param_3,*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),1,1,0,0);
    if (iVar2 < 0) {
      return iVar2;
    }
  }
  return 0;
}


// ==== 0x5dc760 FUN_005dc760

int __thiscall FUN_005dc760(int param_1,int *param_2)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  uint local_1c;
  int local_18;
  uint local_10;
  uint local_8;
  
  iVar6 = (int)param_2;
  uVar8 = 0;
  if ((param_2 == (int *)0x0) || (*(int *)(param_1 + 0x38) != 0)) {
    return 0;
  }
  iVar7 = *(int *)((int)param_2 + 4);
  if (iVar7 == 5) {
    if (*(int *)((int)param_2 + 0x10) == 1) {
      iVar5 = *(int *)((int)param_2 + 0x18);
      iVar7 = *(int *)(iVar5 + 0x10);
      local_10 = *(uint *)(iVar5 + 0x14);
      if ((*(int *)(iVar5 + 0x18) != 0) || (bVar3 = true, (*(byte *)(iVar5 + 0x1c) & 0x40) == 0)) {
        bVar3 = false;
      }
      if ((*(int *)(iVar5 + 0x18) == 0) || (bVar2 = true, (*(byte *)(iVar5 + 0x1c) & 2) == 0)) {
        bVar2 = false;
      }
      local_18 = *(undefined4 *)(iVar5 + 0x20);
      local_1c = *(undefined4 *)(iVar5 + 0x30);
      uVar8 = *(uint *)(iVar5 + 0x1c) & 0x80;
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffff3ff;
    }
    else {
      if (*(int *)((int)param_2 + 0x10) != 2) {
        return 0;
      }
      iVar5 = *(int *)((int)param_2 + 0x18);
      local_10 = *(uint *)(iVar5 + 0x14);
      iVar7 = *(int *)(iVar5 + 0x10);
      *(byte *)(iVar5 + 0x19) = *(byte *)(iVar5 + 0x19) & 0xf3;
      local_18 = *(undefined4 *)(iVar5 + 0x20);
      local_1c = *(undefined4 *)(iVar5 + 0x34);
      bVar3 = false;
      bVar2 = false;
    }
    if (uVar8 != 0) {
      FUN_005e2a38(*(undefined4 *)(*(int *)((int)param_2 + 0x18) + 0x28),
                   *(int *)(param_1 + 0x18) + iVar7 * 4);
      return 0;
    }
    local_8 = 0;
    if (local_10 != 0) {
      param_2 = (int *)(iVar7 << 2);
      do {
        if ((!bVar2) || (*(int *)((int)param_2 + *(int *)(param_1 + 0x18)) == -1)) {
          if (bVar3) {
            uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x54);
          }
          else {
            uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x4c);
          }
          uVar4 = FUN_005f74cf(uVar4,0,0,0);
          iVar5 = FUN_005f762c();
          if (iVar5 != 0) {
            *(uint *)(iVar5 + 0x1c) = local_8 + iVar7;
            *(int *)(iVar5 + 0x44) = iVar6;
            *(uint *)(iVar5 + 0x48) = local_8;
          }
          *(undefined4 *)((int)param_2 + *(int *)(param_1 + 0x18)) = uVar4;
        }
        local_8 = local_8 + 1;
        param_2 = (int *)((int)param_2 + 4);
      } while (local_8 < local_10);
    }
    if (!bVar3) {
      return 0;
    }
    iVar6 = FUN_005dbe7e(local_18,*(int *)(param_1 + 0x18) + iVar7 * 4,local_10);
    if (iVar6 < 0) {
      return iVar6;
    }
    iVar6 = FUN_005dc613(local_18,*(int *)(param_1 + 0x18) + iVar7 * 4,
                         *(undefined4 *)(*(int *)(param_1 + 8) + 0x54),1,0,0,local_1c);
    if (iVar6 < 0) {
      return iVar6;
    }
    iVar6 = FUN_005d932c();
LAB_005dc907:
    if (-1 < iVar6) {
      return 0;
    }
    return iVar6;
  }
  if (iVar7 == 0xb) {
    iVar7 = *(int *)((int)param_2 + 0x10);
    if (iVar7 < 0) {
      return 0;
    }
    if (iVar7 < 2) {
      uVar8 = *(uint *)(*(int *)(param_1 + 8) + 0xc);
      iVar7 = FUN_005e2a38(*(undefined4 *)((int)param_2 + 0x14),0);
      if (-1 < iVar7) {
        uVar1 = *(uint *)(*(int *)(param_1 + 8) + 0xc);
        local_18 = 0;
        local_1c = 0;
        if (uVar8 < uVar1) {
          param_2 = (int *)(*(int *)(*(int *)(param_1 + 8) + 0x18) + uVar8 * 4);
          iVar7 = *(int *)(*(int *)(param_1 + 8) + 0xc) - uVar8;
          do {
            if ((((*(int *)(*param_2 + 0x30) == *(int *)(param_1 + 0x30)) &&
                 (iVar5 = *(int *)(*param_2 + 0x34), iVar5 != 0)) && (*(int *)(iVar5 + 4) == 0xc))
               && (local_1c <= *(uint *)(iVar5 + 0x44))) {
              local_1c = *(uint *)(iVar5 + 0x44);
              local_18 = iVar5;
            }
            param_2 = param_2 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
        if (uVar8 < uVar1) {
          do {
            iVar7 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x18) + uVar8 * 4);
            if (*(int *)(iVar7 + 0x30) == *(int *)(param_1 + 0x30)) {
              *(int *)(iVar7 + 0x34) = local_18;
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < *(uint *)(*(int *)(param_1 + 8) + 0xc));
        }
        *(uint *)(param_1 + 0x38) = (uint)(*(int *)(iVar6 + 0x10) == 1);
        return 0;
      }
      return iVar7;
    }
    if (iVar7 == 2) {
      iVar6 = FUN_005dc02b(*(undefined4 *)((int)param_2 + 0x18),*(undefined4 *)((int)param_2 + 0x20)
                           ,*(undefined4 *)((int)param_2 + 0x24),0);
      goto LAB_005dc907;
    }
    if (iVar7 != 3) {
      return 0;
    }
    iVar6 = FUN_005d9f14(*(undefined4 *)((int)param_2 + 0x14),*(undefined4 *)((int)param_2 + 0x18),
                         *(undefined4 *)((int)param_2 + 0x1c),*(undefined4 *)((int)param_2 + 0x20));
    if (-1 < iVar6) {
      return 0;
    }
    if (iVar6 != -0x7fffbfff) {
      return iVar6;
    }
    uVar9 = 0x6a0e5c00000dac;
  }
  else {
    if (iVar7 == 1) {
      while( true ) {
        if (*(int *)(param_1 + 0x38) != 0) {
          return 0;
        }
        iVar6 = FUN_005dc760();
        if (iVar6 < 0) break;
        param_2 = *(int **)((int)param_2 + 0xc);
        if (param_2 == (int *)0x0) {
          return 0;
        }
      }
      return iVar6;
    }
    uVar9 = 0x6a0e3400000000;
    param_2 = (int *)0x0;
  }
  FUN_005d9de1(param_1,param_2,uVar9);
  return -0x7fffbffb;
}


// ==== 0x5dca6a FUN_005dca6a

/* WARNING: Type propagation algorithm not settling */

int __thiscall FUN_005dca6a(int param_1,int *******param_2,int *******param_3)

{
  int *****pppppiVar1;
  float10 fVar2;
  float10 fVar3;
  undefined3 uVar4;
  void *pvVar5;
  int iVar6;
  int *****pppppiVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int ******ppppppiVar10;
  int *******pppppppiVar11;
  uint uVar12;
  int ******ppppppiVar13;
  size_t _Size;
  int *******pppppppiVar14;
  int iVar15;
  int *piVar16;
  int *******pppppppiVar17;
  uint uVar18;
  undefined8 uVar19;
  ulonglong uVar20;
  longlong lVar21;
  undefined4 local_1e8 [3];
  undefined1 local_1dc [12];
  undefined1 local_1d0 [12];
  undefined1 local_1c4 [12];
  undefined4 local_1b8 [3];
  undefined1 local_1ac [12];
  undefined1 local_1a0 [12];
  undefined1 local_194 [12];
  undefined4 local_188 [3];
  undefined1 local_17c [12];
  undefined1 local_170 [12];
  undefined1 local_164 [12];
  undefined4 local_158;
  int local_154;
  undefined4 local_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  int ******local_144;
  int ******local_140;
  int ******local_13c;
  int ******local_138;
  int ******local_134;
  int ******local_130;
  int ******local_12c;
  int ******local_128;
  int ******local_124;
  int ******local_120;
  int ******local_11c;
  int ******local_118;
  int ******local_114;
  int ******local_110;
  int ******local_10c;
  undefined1 local_108 [4];
  undefined1 local_104 [4];
  int local_100 [2];
  int ******local_f8 [3];
  int local_ec [3];
  int *******local_e0;
  uint local_dc;
  int local_d8;
  undefined4 *local_d4;
  int local_d0;
  int local_cc;
  int ******local_c8;
  int *******local_c4;
  int ******local_c0;
  int ******local_bc;
  int *local_b8;
  int ******local_b4;
  int ******local_b0;
  int ******local_ac;
  int ******local_a8;
  int ******local_a4 [9];
  int *******local_80;
  int ******local_7c;
  int ******local_78;
  int ******local_74;
  int local_70;
  int *******local_6c;
  int *******local_68;
  int *******local_64;
  int *******local_60;
  int ******local_5c;
  int *******local_58;
  int *******local_54 [4];
  undefined3 local_44;
  undefined1 uStack_41;
  undefined4 local_40;
  undefined4 local_3c;
  int *******local_38;
  int *local_34;
  int *******local_30;
  int ******local_2c [2];
  int *******local_24;
  int ******local_20;
  int *******local_1c;
  int *******local_18;
  int **local_14;
  undefined4 local_10;
  int *******local_c;
  undefined4 local_8;
  
  if (param_2 == (int *******)0x0) {
    if (param_3 != (int *******)0x0) {
      return -0x7fffbffb;
    }
    return 0;
  }
  if (*(int *)((int)param_2 + 4) != 0xc) {
    return -0x7fffbffb;
  }
  local_154 = *(int *)((int)param_2 + 0x24);
  local_8 = (int *******)(*(int *)((int)param_2 + 0x14) * *(int *)((int)param_2 + 0x18));
  if (*(int *)((int)param_2 + 0x1c) != 0x1a) {
    return -0x7fffbffb;
  }
  local_158 = *(undefined4 *)(param_1 + 0x1c);
  local_20 = (int ******)0x0;
  local_1c = (int *******)0x0;
  local_18 = (int *******)0x0;
  local_14 = (int **)0x0;
  local_bc = (int ******)0x0;
  local_b8 = (int *)0x0;
  local_b4 = (int ******)0x0;
  local_b0 = (int ******)0x0;
  local_54[0] = (int *******)0x0;
  local_54[1] = (int *******)0x0;
  local_54[2] = (int *******)0x0;
  local_54[3] = (int *******)0x0;
  local_40 = *(int ********)(local_154 + 8);
  local_c = (int *******)0x0;
  if (local_40 != (int *******)0x0) {
    iVar15 = 0;
    do {
      ppppppiVar10 = local_40[2];
      if (ppppppiVar10 != (int ******)0x0) {
        pppppiVar7 = ppppppiVar10[6];
        pppppiVar1 = ppppppiVar10[5];
        *(int *)((int)&local_bc + iVar15) = (int)pppppiVar7 * (int)pppppiVar1;
        *(int *******)((int)&local_20 + iVar15) = ppppppiVar10;
        pvVar5 = _malloc((int)pppppiVar7 * (int)pppppiVar1 * 4);
        *(void **)((int)local_54 + iVar15) = pvVar5;
        if (pvVar5 == (void *)0x0) goto LAB_005e12dc;
        iVar6 = FUN_005e2a38();
        if (iVar6 < 0) goto LAB_005e1de6;
      }
      local_40 = (int *******)local_40[3];
      iVar15 = iVar15 + 4;
    } while (local_40 != (int *******)0x0);
  }
  pppppppiVar14 = local_8;
  ppppppiVar10 = local_bc;
  pppppppiVar11 = param_3;
  uVar4 = (undefined3)local_8;
  switch(*(undefined4 *)(*(int *)(*(int *)((int)param_2 + 0x20) + 8) + 0x18)) {
  case 0:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        local_c = _malloc((int)local_8 << 2);
        pppppppiVar11 = local_8;
        if (local_c != (int *******)0x0) {
          iVar6 = FUN_005d91c9(local_c,local_8);
          if ((iVar6 < 0) || (iVar6 = FUN_005d91c9(param_3,pppppppiVar11), iVar6 < 0))
          goto LAB_005e1de6;
          uVar18 = (uint)pppppppiVar11 & 0xffffff;
          iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x11000000,local_c,local_54[0],0,0);
          if (iVar6 < 0) goto LAB_005e1de6;
          uVar20 = CONCAT44(4,local_c);
          pppppppiVar17 = (int *******)(uVar18 | 0x21000000);
          pppppppiVar11 = param_3;
          pppppppiVar14 = local_54[0];
          goto LAB_005e151b;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 1:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        lVar21 = CONCAT44(local_8,param_3);
        pppppppiVar11 = (int *******)0x0;
LAB_005dcfd5:
        iVar6 = FUN_005dad99(param_2,local_54[0],pppppppiVar11,lVar21);
LAB_005e1525:
        if (iVar6 < 0) goto LAB_005e1de6;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 2:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        if (local_bc == (int ******)0x1) {
          *param_3 = (int ******)0xffffffff;
          local_40 = (int *******)0xffffffff;
          local_38 = (int *******)0xffffffff;
          iVar6 = FUN_005d9fa1(param_2,0x11000001,&local_40,local_54[0],0,0);
          if ((iVar6 < 0) ||
             (iVar6 = FUN_005d9fa1(param_2,0x21000001,&local_38,local_54[0],&local_40,4), iVar6 < 0)
             ) goto LAB_005e1de6;
          pppppppiVar17 = (int *******)&local_38;
          pppppppiVar14 = (int *******)&local_40;
          pppppppiVar11 = param_3;
        }
        else {
          if (local_bc != (int ******)0x2) {
            pppppppiVar11 = _malloc((int)local_bc << 4);
            local_c = pppppppiVar11;
            if (pppppppiVar11 != (int *******)0x0) {
              uVar18 = 0;
              do {
                (&local_20)[uVar18] = (int ******)pppppppiVar11;
                uVar18 = uVar18 + 1;
                pppppppiVar11 = pppppppiVar11 + (int)ppppppiVar10;
              } while (uVar18 < 4);
              iVar6 = FUN_005d91c9(local_20,ppppppiVar10);
              if ((((iVar6 < 0) || (iVar6 = FUN_005d91c9(local_1c,ppppppiVar10), iVar6 < 0)) ||
                  (iVar6 = FUN_005d91c9(local_18,ppppppiVar10), iVar6 < 0)) ||
                 (iVar6 = FUN_005d91c9(local_14,ppppppiVar10), iVar6 < 0)) goto LAB_005e1de6;
              local_40 = (int *******)CONCAT13(0x11,(int3)ppppppiVar10);
              local_3c = (int *******)0xffffffff;
              local_64 = (int *******)0xffffffff;
              *param_3 = (int ******)0xffffffff;
              local_38 = (int *******)((uint)ppppppiVar10 & 0xffffff);
              iVar6 = FUN_005d9fa1(param_2,local_40,local_20,local_54[0],0,0);
              if ((((iVar6 < 0) ||
                   (iVar6 = FUN_005d9fa1(param_2,(uint)ppppppiVar10 & 0xffffff | 0x21000000,local_1c
                                         ,local_54[0],local_20,4), iVar6 < 0)) ||
                  ((iVar6 = FUN_005d9fa1(param_2,local_40,local_18,local_1c,0,8), iVar6 < 0 ||
                   ((iVar6 = FUN_005d9fa1(param_2,(uint)local_38 | 0x23000000,local_14,local_18,
                                          local_1c,0x2000017), iVar6 < 0 ||
                    (iVar6 = FUN_005d9fa1(param_2,(uint)local_38 | 0x30000000,&local_3c,local_14,
                                          local_14,6), iVar6 < 0)))))) ||
                 (iVar6 = FUN_005d9fa1(param_2,0x11000001,&local_64,&local_3c,0,10), iVar6 < 0))
              goto LAB_005e1de6;
              uVar20 = CONCAT44(0x2000017,&local_3c);
              pppppppiVar17 = (int *******)0x23000001;
              pppppppiVar11 = param_3;
              pppppppiVar14 = (int *******)&local_64;
              goto LAB_005e151b;
            }
            goto LAB_005e12dc;
          }
          local_78 = (int ******)0xffffffff;
          local_74 = (int ******)0xffffffff;
          local_5c = (int ******)0xffffffff;
          local_58 = (int *******)0xffffffff;
          *param_3 = (int ******)0xffffffff;
          local_40 = (int *******)0xffffffff;
          local_38 = (int *******)0xffffffff;
          iVar6 = FUN_005d9fa1(param_2,0x11000002,&local_78,local_54[0],0,0);
          if ((((iVar6 < 0) ||
               (iVar6 = FUN_005d9fa1(param_2,0x21000002,&local_5c,local_54[0],&local_78,4),
               iVar6 < 0)) ||
              (iVar6 = FUN_005d9fa1(param_2,0x25000001,&local_40,&local_5c,&local_58,4), iVar6 < 0))
             || (iVar6 = FUN_005d9fa1(param_2,0x11000001,&local_38,&local_40,0,8), iVar6 < 0))
          goto LAB_005e1de6;
          pppppppiVar17 = (int *******)&local_40;
          pppppppiVar14 = (int *******)&local_38;
          pppppppiVar11 = param_3;
        }
LAB_005dcf99:
        uVar20 = CONCAT44(0x2000017,pppppppiVar17);
        pppppppiVar17 = (int *******)0x22000001;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 3:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        param_3 = (int *******)0xffffffff;
        local_38 = (int *******)0xffffffff;
        *pppppppiVar11 = (int ******)0xffffffff;
        iVar6 = FUN_005d9fa1(param_2,(uint)local_bc & 0xffffff | 0x30000000,&param_3,local_54[0],
                             local_54[0],4);
        if ((iVar6 < 0) ||
           (iVar6 = FUN_005d9fa1(param_2,0x11000001,&local_38,&param_3,0,8), iVar6 < 0))
        goto LAB_005e1de6;
        pppppppiVar17 = (int *******)&param_3;
        pppppppiVar14 = (int *******)&local_38;
        goto LAB_005dcf99;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 4:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        lVar21 = ZEXT48(local_8) << 0x20;
        pppppppiVar11 = param_3;
        goto LAB_005dcfd5;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 5:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar19 = CONCAT44(local_8,param_3);
        pppppppiVar11 = (int *******)0x0;
LAB_005dd058:
        iVar6 = FUN_005db2b5(param_2,local_54[0],pppppppiVar11,uVar19);
        goto LAB_005e1525;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 6:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar19 = CONCAT44(local_8,param_3);
        pppppppiVar11 = local_54[1];
        goto LAB_005dd058;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 7:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        local_c = _malloc((int)local_8 << 3);
        if (local_c != (int *******)0x0) {
          local_38 = local_c + (int)local_8;
          uVar19 = FUN_005d91c9(local_c,local_8);
          iVar6 = (int)uVar19;
          if (((iVar6 < 0) ||
              (iVar6 = FUN_005d91c9((int)((ulonglong)uVar19 >> 0x20),local_8), iVar6 < 0)) ||
             (iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0)) goto LAB_005e1de6;
          pppppppiVar17 = (int *******)((uint)local_8 & 0xffffff);
          iVar6 = FUN_005d9fa1(param_2,(uint)pppppppiVar17 | 0x11000000,local_c,local_54[0],0,0);
          if (iVar6 < 0) goto LAB_005e1de6;
          uVar8 = 0x14;
          uVar18 = (uint)pppppppiVar17 | 0x13000000;
LAB_005dd115:
          iVar6 = FUN_005d9fa1(param_2,uVar18,local_38,local_c,0,uVar8);
          if (iVar6 < 0) goto LAB_005e1de6;
          uVar20 = CONCAT44(2,local_38);
          pppppppiVar14 = local_54[0];
          goto LAB_005e0738;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 8:
    if ((((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) &&
       (local_18 != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        local_c = _malloc((int)local_8 << 2);
        if (local_c != (int *******)0x0) {
          iVar6 = FUN_005d91c9(local_c,local_8);
          if ((iVar6 < 0) || (iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0)) goto LAB_005e1de6;
          uVar18 = (uint)local_8 & 0xffffff;
          iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x21000000,local_c,local_54[0],local_54[1],0);
          if (iVar6 < 0) goto LAB_005e1de6;
          uVar20 = ZEXT48(local_54[2]);
          pppppppiVar14 = local_c;
LAB_005e09fb:
          pppppppiVar17 = (int *******)(uVar18 | 0x20000000);
          pppppppiVar11 = param_3;
          goto LAB_005e151b;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 9:
    if ((int *******)local_20 != (int *******)0x0) {
      pppppppiVar11 = _malloc((int)local_bc << 3);
      local_c = pppppppiVar11;
      if (pppppppiVar11 != (int *******)0x0) {
        uVar18 = 0;
        do {
          (&local_5c)[uVar18] = (int ******)pppppppiVar11;
          uVar18 = uVar18 + 1;
          pppppppiVar11 = pppppppiVar11 + (int)ppppppiVar10;
        } while (uVar18 < 2);
        ppppppiVar13 = (int ******)0x0;
        if (ppppppiVar10 != (int ******)0x0) {
          do {
            local_58[(int)ppppppiVar13] = *(int *******)(param_1 + 0x2c);
            ppppppiVar13 = (int ******)((int)ppppppiVar13 + 1);
          } while (ppppppiVar13 < ppppppiVar10);
        }
        uVar19 = FUN_005d91c9(local_5c,ppppppiVar10);
        iVar6 = (int)uVar19;
        if (iVar6 < 0) goto LAB_005e1de6;
        iVar6 = FUN_005d9fa1(param_2,(uint)ppppppiVar10 & 0xffffff | 0x25000000,local_5c,local_54[0]
                             ,(int)((ulonglong)uVar19 >> 0x20),0);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = 0;
        pppppppiVar17 = (int *******)((uint)ppppppiVar10 & 0xffffff | 0x34000000);
        pppppppiVar11 = (int *******)0x0;
        pppppppiVar14 = (int *******)local_5c;
        goto LAB_005e151b;
      }
      goto LAB_005e12dc;
    }
    break;
  case 10:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        lVar21 = CONCAT44(local_8,param_3);
        pppppppiVar11 = (int *******)0x0;
LAB_005e0c0f:
        iVar6 = FUN_005da7de(param_2,local_54[0],pppppppiVar11,lVar21);
        goto LAB_005e1525;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0xb:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        fVar3 = (float10)log2((float10)2.0);
        uVar8 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,
                             (double)((float10)1.0 / ((float10)0.6931471805599453 * fVar3)));
        local_58 = (int *******)
                   FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0x3fe0000000000000
                               );
        pppppppiVar11 = _malloc((int)local_8 * 0x1c);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            local_2c[uVar18] = (int ******)pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)local_8;
          } while (uVar18 < 7);
          if (local_8 != (int *******)0x0) {
            pppppppiVar11 = (int *******)local_14;
            pppppppiVar14 = local_8;
            do {
              *(undefined4 *)(((int)local_18 - (int)local_14) + (int)pppppppiVar11) = uVar8;
              *pppppppiVar11 = (int ******)local_58;
              pppppppiVar11 = pppppppiVar11 + 1;
              pppppppiVar14 = (int *******)((int)pppppppiVar14 + -1);
            } while (pppppppiVar14 != (int *******)0x0);
          }
          iVar6 = FUN_005d91c9(local_2c[0],local_8);
          if ((((iVar6 < 0) || (iVar6 = FUN_005d91c9(local_2c[1],local_8), iVar6 < 0)) ||
              ((iVar6 = FUN_005d91c9(local_24,local_8), iVar6 < 0 ||
               ((iVar6 = FUN_005d91c9(local_20,local_8), iVar6 < 0 ||
                (iVar6 = FUN_005d91c9(local_1c,local_8), iVar6 < 0)))))) ||
             (iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0)) goto LAB_005e1de6;
          uVar18 = (uint)local_8 & 0xffffff;
          uVar4 = (undefined3)local_8;
          local_8 = (int *******)CONCAT13(0x25,(undefined3)local_8);
          iVar6 = FUN_005d9fa1(param_2,local_8,local_2c[0],local_54[0],local_18,0);
          if (iVar6 < 0) goto LAB_005e1de6;
          local_3c = (int *******)CONCAT13(0x14,uVar4);
          iVar6 = FUN_005d9fa1(param_2,local_3c,local_2c[1],local_2c[0],0,4);
          if ((((iVar6 < 0) ||
               (iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x11000000,local_24,local_2c[0],0,0),
               iVar6 < 0)) ||
              (iVar6 = FUN_005d9fa1(param_2,local_3c,local_20,local_24,0,4), iVar6 < 0)) ||
             (iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x24000000,local_1c,local_2c[1],local_20,4),
             iVar6 < 0)) goto LAB_005e1de6;
          uVar8 = 4;
LAB_005e0e4c:
          uVar20 = CONCAT44(uVar8,local_14);
          pppppppiVar17 = local_8;
          pppppppiVar11 = param_3;
          pppppppiVar14 = local_1c;
          goto LAB_005e151b;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0xc:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        local_60 = (int *******)local_54[0][1];
        local_5c = local_54[0][2];
        local_58 = (int *******)*local_54[0];
        local_c8 = local_54[1][2];
        local_c4 = (int *******)*local_54[1];
        local_c0 = local_54[1][1];
        local_144 = local_54[0][2];
        local_140 = *local_54[0];
        local_13c = local_54[0][1];
        local_7c = local_54[1][1];
        local_78 = local_54[1][2];
        local_74 = *local_54[1];
        local_1c = (int *******)0xffffffff;
        local_18 = (int *******)0xffffffff;
        local_14 = (int **)0xffffffff;
        local_150 = 0xffffffff;
        uStack_14c = 0xffffffff;
        uStack_148 = 0xffffffff;
        local_b8 = (int *)0xffffffff;
        local_b4 = (int ******)0xffffffff;
        local_b0 = (int ******)0xffffffff;
        *param_3 = (int ******)0xffffffff;
        param_3[1] = (int ******)0xffffffff;
        param_3[2] = (int ******)0xffffffff;
        pppppppiVar17 = (int *******)((uint)local_8 & 0xffffff);
        local_8 = (int *******)CONCAT13(0x25,(undefined3)local_8);
        iVar6 = FUN_005d9fa1(param_2,local_8,&local_1c,&local_60,&local_c8,0);
        if (((iVar6 < 0) ||
            (iVar6 = FUN_005d9fa1(param_2,local_8,&local_150,&local_144,&local_7c,0), iVar6 < 0)) ||
           (iVar6 = FUN_005d9fa1(param_2,(uint)pppppppiVar17 | 0x11000000,&local_b8,&local_150,0,0),
           iVar6 < 0)) goto LAB_005e1de6;
        uVar20 = ZEXT48(&local_b8);
        pppppppiVar14 = (int *******)&local_1c;
LAB_005e0738:
        pppppppiVar17 = (int *******)((uint)pppppppiVar17 | 0x24000000);
        pppppppiVar11 = param_3;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0xd:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = 0;
        pppppppiVar17 = (int *******)((uint)local_8 & 0xffffff | 0x1c000000);
        pppppppiVar11 = param_3;
        pppppppiVar14 = local_54[0];
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0xe:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = 0;
        pppppppiVar17 = (int *******)((uint)local_8 & 0xffffff | 0x1d000000);
        pppppppiVar11 = param_3;
        pppppppiVar14 = local_54[0];
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0xf:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        uVar19 = 0x404ca5dc0d03cf26;
LAB_005e0162:
        ppppppiVar10 = (int ******)
                       FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,uVar19);
        pppppppiVar11 = _malloc((int)local_8 << 2);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          pppppppiVar14 = local_8;
          if (local_8 != (int *******)0x0) {
            for (; pppppppiVar14 != (int *******)0x0;
                pppppppiVar14 = (int *******)((int)pppppppiVar14 + -1)) {
              *pppppppiVar11 = ppppppiVar10;
              pppppppiVar11 = pppppppiVar11 + 1;
            }
          }
          goto LAB_005e019c;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x10:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        if (local_bc != (int ******)0x1) {
          ppppppiVar10 = (int ******)local_20[5];
          if (ppppppiVar10 == (int ******)0x2) {
            local_c8 = (int ******)0xffffffff;
            local_c4 = (int *******)0xffffffff;
            local_c0 = (int ******)0xffffffff;
            iVar6 = FUN_005d91c9(param_3,local_8);
            if (iVar6 < 0) goto LAB_005e1de6;
            local_78 = *local_54[0];
            local_5c = local_54[0][3];
            local_74 = local_54[0][1];
            local_58 = (int *******)local_54[0][2];
            iVar6 = FUN_005d9fa1(param_2,0x25000002,&local_c8,&local_78,&local_5c,0);
            if ((iVar6 < 0) ||
               (iVar6 = FUN_005d9fa1(param_2,0x11000001,&local_c0,&local_c4,0,0), iVar6 < 0))
            goto LAB_005e1de6;
            uVar20 = ZEXT48(&local_c0);
            pppppppiVar14 = &local_c8;
LAB_005dff6c:
            pppppppiVar17 = (int *******)0x24000001;
            pppppppiVar11 = param_3;
          }
          else if (ppppppiVar10 == (int ******)0x3) {
            local_150 = 0xffffffff;
            uStack_14c = 0xffffffff;
            uStack_148 = 0xffffffff;
            local_1c = (int *******)0xffffffff;
            local_18 = (int *******)0xffffffff;
            local_14 = (int **)0xffffffff;
            local_b8 = (int *)0xffffffff;
            local_b4 = (int ******)0xffffffff;
            local_b0 = (int ******)0xffffffff;
            local_144 = (int ******)0xffffffff;
            local_140 = (int ******)0xffffffff;
            local_13c = (int ******)0xffffffff;
            iVar6 = FUN_005d91c9(param_3,local_8);
            pppppppiVar11 = local_54[0];
            if (iVar6 < 0) goto LAB_005e1de6;
            local_60 = (int *******)local_54[0][4];
            local_5c = local_54[0][7];
            local_58 = (int *******)local_54[0][1];
            local_7c = local_54[0][8];
            local_78 = local_54[0][2];
            local_74 = local_54[0][5];
            iVar6 = FUN_005d9fa1(param_2,0x25000003,&local_150,&local_60,&local_7c,0);
            if (iVar6 < 0) goto LAB_005e1de6;
            local_60 = (int *******)pppppppiVar11[7];
            local_5c = pppppppiVar11[1];
            local_58 = (int *******)pppppppiVar11[4];
            local_7c = pppppppiVar11[5];
            local_78 = pppppppiVar11[8];
            local_74 = pppppppiVar11[2];
            iVar6 = FUN_005d9fa1(param_2,0x25000003,&local_1c,&local_60,&local_7c,0);
            if (((iVar6 < 0) ||
                (iVar6 = FUN_005d9fa1(param_2,0x11000003,&local_b8,&local_1c,0,0), iVar6 < 0)) ||
               (iVar6 = FUN_005d9fa1(param_2,0x24000003,&local_144,&local_150,&local_b8,0),
               iVar6 < 0)) goto LAB_005e1de6;
            local_60 = (int *******)*pppppppiVar11;
            local_5c = pppppppiVar11[3];
            local_58 = (int *******)pppppppiVar11[6];
            uVar20 = ZEXT48(&local_60);
            pppppppiVar17 = (int *******)0x30000003;
            pppppppiVar11 = param_3;
            pppppppiVar14 = &local_144;
          }
          else {
            if (ppppppiVar10 != (int ******)0x4) goto LAB_005dd6a0;
            uVar19 = CONCAT44(local_8,param_3);
            iVar6 = 0xc;
            puVar9 = local_1b8;
            for (iVar15 = iVar6; iVar15 != 0; iVar15 = iVar15 + -1) {
              *puVar9 = 0xffffffff;
              puVar9 = puVar9 + 1;
            }
            puVar9 = local_1e8;
            for (iVar15 = iVar6; iVar15 != 0; iVar15 = iVar15 + -1) {
              *puVar9 = 0xffffffff;
              puVar9 = puVar9 + 1;
            }
            puVar9 = local_188;
            for (iVar15 = iVar6; iVar15 != 0; iVar15 = iVar15 + -1) {
              *puVar9 = 0xffffffff;
              puVar9 = puVar9 + 1;
            }
            piVar16 = local_100 + 2;
            for (; iVar6 != 0; iVar6 = iVar6 + -1) {
              *piVar16 = -1;
              piVar16 = piVar16 + 1;
            }
            local_20 = (int ******)0xffffffff;
            local_1c = (int *******)0xffffffff;
            local_18 = (int *******)0xffffffff;
            local_14 = (int **)0xffffffff;
            iVar6 = FUN_005d91c9(uVar19);
            pppppppiVar11 = local_54[0];
            if (iVar6 < 0) goto LAB_005e1de6;
            local_ac = local_54[0][10];
            local_a8 = local_54[0][0xe];
            local_a4[0] = local_54[0][6];
            local_a4[1] = local_54[0][0xe];
            local_a4[2] = local_54[0][2];
            local_a4[3] = local_54[0][10];
            local_a4[4] = local_54[0][6];
            local_a4[5] = local_54[0][0xe];
            local_a4[6] = local_54[0][2];
            local_a4[7] = local_54[0][10];
            local_a4[8] = local_54[0][2];
            local_80 = (int *******)local_54[0][6];
            local_138 = local_54[0][0xf];
            local_134 = local_54[0][7];
            local_130 = local_54[0][0xb];
            local_12c = local_54[0][0xb];
            local_128 = local_54[0][0xf];
            local_124 = local_54[0][3];
            local_120 = local_54[0][0xf];
            local_11c = local_54[0][3];
            local_118 = local_54[0][7];
            local_114 = local_54[0][7];
            local_110 = local_54[0][0xb];
            local_10c = local_54[0][3];
            iVar6 = FUN_005d9fa1(param_2,0x25000003,local_1b8,&local_ac,&local_138,0);
            if ((((iVar6 < 0) ||
                 (iVar6 = FUN_005d9fa1(param_2,0x25000003,local_1ac,local_a4 + 1,&local_12c,0),
                 iVar6 < 0)) ||
                (iVar6 = FUN_005d9fa1(param_2,0x25000003,local_1a0,local_a4 + 4,&local_120,0),
                iVar6 < 0)) ||
               (iVar6 = FUN_005d9fa1(param_2,0x25000003,local_194,local_a4 + 7,&local_114,0),
               iVar6 < 0)) goto LAB_005e1de6;
            local_ac = pppppppiVar11[0xe];
            local_a8 = pppppppiVar11[6];
            local_a4[0] = pppppppiVar11[10];
            local_a4[1] = pppppppiVar11[10];
            local_a4[2] = pppppppiVar11[0xe];
            local_a4[3] = pppppppiVar11[2];
            local_a4[4] = pppppppiVar11[0xe];
            local_a4[5] = pppppppiVar11[2];
            local_a4[6] = pppppppiVar11[6];
            local_a4[7] = pppppppiVar11[6];
            local_a4[8] = pppppppiVar11[10];
            local_80 = (int *******)pppppppiVar11[2];
            local_138 = pppppppiVar11[0xb];
            local_134 = pppppppiVar11[0xf];
            local_130 = pppppppiVar11[7];
            local_12c = pppppppiVar11[0xf];
            local_128 = pppppppiVar11[3];
            local_124 = pppppppiVar11[0xb];
            local_120 = pppppppiVar11[7];
            local_11c = pppppppiVar11[0xf];
            local_118 = pppppppiVar11[3];
            local_114 = pppppppiVar11[0xb];
            local_110 = pppppppiVar11[3];
            local_10c = pppppppiVar11[7];
            iVar6 = FUN_005d9fa1(param_2,0x25000003,local_1e8,&local_ac,&local_138,0);
            if (((((iVar6 < 0) ||
                  (iVar6 = FUN_005d9fa1(param_2,0x25000003,local_1dc,local_a4 + 1,&local_12c,0),
                  iVar6 < 0)) ||
                 ((iVar6 = FUN_005d9fa1(param_2,0x25000003,local_1d0,local_a4 + 4,&local_120,0),
                  iVar6 < 0 ||
                  ((iVar6 = FUN_005d9fa1(param_2,0x25000003,local_1c4,local_a4 + 7,&local_114,0),
                   iVar6 < 0 ||
                   (iVar6 = FUN_005d9fa1(param_2,0x11000003,local_188,local_1e8,0,0), iVar6 < 0)))))
                 ) || (iVar6 = FUN_005d9fa1(param_2,0x11000003,local_17c,local_1dc,0,0), iVar6 < 0))
               || ((((iVar6 = FUN_005d9fa1(param_2,0x11000003,local_170,local_1d0,0,0), iVar6 < 0 ||
                     (iVar6 = FUN_005d9fa1(param_2,0x11000003,local_164,local_1c4,0,0), iVar6 < 0))
                    || (iVar6 = FUN_005d9fa1(param_2,0x24000003,local_100 + 2,local_1b8,local_188,0)
                       , iVar6 < 0)) ||
                   (((iVar6 = FUN_005d9fa1(param_2,0x24000003,local_100 + 5,local_1ac,local_17c,0),
                     iVar6 < 0 ||
                     (iVar6 = FUN_005d9fa1(param_2,0x24000003,&local_e0,local_1a0,local_170,0),
                     iVar6 < 0)) ||
                    (iVar6 = FUN_005d9fa1(param_2,0x24000003,&local_d4,local_194,local_164,0),
                    iVar6 < 0)))))) goto LAB_005e1de6;
            local_ac = pppppppiVar11[5];
            local_a8 = pppppppiVar11[9];
            local_a4[0] = pppppppiVar11[0xd];
            local_a4[1] = pppppppiVar11[1];
            local_a4[2] = pppppppiVar11[9];
            local_a4[3] = pppppppiVar11[0xd];
            local_a4[4] = pppppppiVar11[1];
            local_a4[5] = pppppppiVar11[5];
            local_a4[6] = pppppppiVar11[0xd];
            local_a4[7] = pppppppiVar11[1];
            local_a4[8] = pppppppiVar11[5];
            local_80 = (int *******)pppppppiVar11[9];
            iVar6 = FUN_005d9fa1(param_2,0x30000003,&local_20,local_100 + 2,&local_ac,0);
            if (((iVar6 < 0) ||
                (iVar6 = FUN_005d9fa1(param_2,0x30000003,&local_1c,local_100 + 5,local_a4 + 1,0),
                iVar6 < 0)) ||
               ((iVar6 = FUN_005d9fa1(param_2,0x30000003,&local_18,&local_e0,local_a4 + 4,0),
                iVar6 < 0 ||
                (iVar6 = FUN_005d9fa1(param_2,0x30000003,&local_14,&local_d4,local_a4 + 7,0),
                iVar6 < 0)))) goto LAB_005e1de6;
            local_ac = *pppppppiVar11;
            local_a8 = pppppppiVar11[4];
            local_a4[0] = pppppppiVar11[8];
            local_a4[1] = pppppppiVar11[0xc];
            uVar20 = ZEXT48(&local_ac);
            pppppppiVar17 = (int *******)0x30000004;
            pppppppiVar11 = param_3;
            pppppppiVar14 = &local_20;
          }
LAB_005e151b:
          iVar6 = FUN_005d9fa1(param_2,pppppppiVar17,pppppppiVar11,pppppppiVar14,uVar20);
          goto LAB_005e1525;
        }
        *param_3 = *local_54[0];
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x11:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        pppppppiVar11 = _malloc((int)local_bc * 8 + 4);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            (&local_60)[uVar18] = pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)ppppppiVar10;
          } while (uVar18 < 3);
          iVar6 = FUN_005d91c9(local_60,ppppppiVar10);
          if ((iVar6 < 0) || (iVar6 = FUN_005d91c9(local_5c,ppppppiVar10), iVar6 < 0))
          goto LAB_005e1de6;
          *local_58 = (int ******)0xffffffff;
          *param_3 = (int ******)0xffffffff;
          uVar18 = (uint)ppppppiVar10 & 0xffffff;
          iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x11000000,local_60,local_54[1],0,0);
          if ((iVar6 < 0) ||
             (iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x24000000,local_5c,local_54[0],local_60,0),
             iVar6 < 0)) goto LAB_005e1de6;
          iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x30000000,local_58,local_5c,local_5c,4);
          pppppppiVar14 = local_58;
          goto joined_r0x005e1120;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x12:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_54[1]);
        pppppppiVar17 = (int *******)((uint)local_bc & 0xffffff | 0x30000000);
        pppppppiVar11 = param_3;
        pppppppiVar14 = local_54[0];
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x13:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        local_30 = *(int ********)(param_1 + 0x20);
        local_2c[0] = local_54[0][1];
        local_2c[1] = local_54[0][2];
        local_1c = (int *******)local_54[1][1];
        local_14 = (int **)local_54[1][3];
        local_24 = local_30;
        local_20 = (int ******)local_30;
        local_18 = local_30;
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(&local_20);
        pppppppiVar14 = (int *******)&local_30;
LAB_005e01bb:
        pppppppiVar17 = (int *******)((uint)local_8 & 0xffffff | 0x25000000);
        pppppppiVar11 = param_3;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x14:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        fVar3 = (float10)log2((float10)2.0);
        pppppiVar7 = (int *****)
                     FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,
                                  (double)((float10)1.0 / ((float10)0.6931471805599453 * fVar3)));
        pppppppiVar11 = _malloc((int)local_8 * 0xc);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            (&local_c8)[uVar18] = (int ******)pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)local_8;
          } while (uVar18 < 3);
          pppppppiVar11 = local_8;
          ppppppiVar10 = local_c8;
          if (local_8 != (int *******)0x0) {
            for (; pppppppiVar11 != (int *******)0x0;
                pppppppiVar11 = (int *******)((int)pppppppiVar11 + -1)) {
              *ppppppiVar10 = pppppiVar7;
              ppppppiVar10 = ppppppiVar10 + 1;
            }
          }
          iVar6 = FUN_005d91c9(local_c4,local_8);
          if ((iVar6 < 0) || (iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0)) goto LAB_005e1de6;
          uVar18 = (uint)local_8 & 0xffffff;
          iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x25000000,local_c4,local_54[0],local_c8,0);
          pppppppiVar14 = local_c4;
joined_r0x005e0130:
          if (iVar6 < 0) goto LAB_005e1de6;
          uVar20 = 0x400000000;
          pppppppiVar17 = (int *******)(uVar18 | 0x14000000);
          pppppppiVar11 = param_3;
          goto LAB_005e151b;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x15:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = 0x400000000;
        pppppppiVar17 = (int *******)((uint)local_8 & 0xffffff | 0x14000000);
        pppppppiVar11 = param_3;
        pppppppiVar14 = local_54[0];
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x16:
    if ((((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) &&
       (local_18 != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        uVar18 = (uint)local_8 & 0xffffff;
        local_38 = (int *******)0xffffffff;
        local_64 = (int *******)0xffffffff;
        iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x30000000,&local_38,local_54[1],local_54[2],0);
        if ((iVar6 < 0) ||
           (iVar6 = FUN_005d9fa1(param_2,0x23000001,&local_64,&local_38,param_1 + 0x24,0x2000017),
           pppppppiVar11 = local_8, iVar6 < 0)) goto LAB_005e1de6;
        pppppppiVar14 = _malloc((int)local_8 << 4);
        local_c = pppppppiVar14;
        if (pppppppiVar14 != (int *******)0x0) {
          uVar12 = 0;
          do {
            (&local_20)[uVar12] = (int ******)pppppppiVar14;
            uVar12 = uVar12 + 1;
            pppppppiVar14 = pppppppiVar14 + (int)pppppppiVar11;
          } while (uVar12 < 4);
          pppppppiVar14 = (int *******)0x0;
          if (pppppppiVar11 != (int *******)0x0) {
            do {
              local_14[(int)pppppppiVar14] = (int *)local_64;
              pppppppiVar14 = (int *******)((int)pppppppiVar14 + 1);
            } while (pppppppiVar14 < pppppppiVar11);
          }
          iVar6 = FUN_005d91c9(local_20,pppppppiVar11);
          if ((((iVar6 < 0) || (iVar6 = FUN_005d91c9(local_1c,local_8), iVar6 < 0)) ||
              (iVar6 = FUN_005d91c9(local_18,local_8), iVar6 < 0)) ||
             ((iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0 ||
              (iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x11000000,local_20,local_54[0],0,0), iVar6 < 0
              )))) goto LAB_005e1de6;
          _local_44 = (int *******)CONCAT13(0x24,uVar4);
          iVar6 = FUN_005d9fa1(param_2,_local_44,local_1c,local_20,local_20,0);
          if ((iVar6 < 0) ||
             (iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x25000000,local_18,local_1c,local_14,0),
             iVar6 < 0)) goto LAB_005e1de6;
          uVar20 = ZEXT48(local_18);
          pppppppiVar17 = _local_44;
          pppppppiVar11 = param_3;
          pppppppiVar14 = local_54[0];
          goto LAB_005e151b;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x17:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        local_c = _malloc((int)local_8 << 3);
        if (local_c != (int *******)0x0) {
          local_38 = local_c + (int)local_8;
          uVar19 = FUN_005d91c9(local_c,local_8);
          iVar6 = (int)uVar19;
          if (((iVar6 < 0) ||
              (iVar6 = FUN_005d91c9((int)((ulonglong)uVar19 >> 0x20),local_8), iVar6 < 0)) ||
             (iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0)) goto LAB_005e1de6;
          pppppppiVar17 = (int *******)((uint)local_8 & 0xffffff);
          iVar6 = FUN_005d9fa1(param_2,(uint)pppppppiVar17 | 0x13000000,local_c,local_54[0],0,0x14);
          if (iVar6 < 0) goto LAB_005e1de6;
          uVar8 = 0x18;
          uVar18 = (uint)pppppppiVar17 | 0x11000000;
          goto LAB_005dd115;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x18:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        pppppppiVar11 = _malloc((int)local_8 * 0xc);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            (&local_60)[uVar18] = pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)local_8;
          } while (uVar18 < 3);
          uVar18 = 0;
          do {
            uVar19 = FUN_005d91c9((&local_60)[uVar18],local_8);
            iVar6 = (int)uVar19;
            if (iVar6 < 0) goto LAB_005e1de6;
            uVar18 = (int)((ulonglong)uVar19 >> 0x20) + 1;
          } while (uVar18 < 3);
          iVar6 = FUN_005d91c9(param_3,local_8);
          pppppppiVar11 = local_8;
          if (iVar6 < 0) goto LAB_005e1de6;
          uVar18 = (uint)local_8 & 0xffffff;
          iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x12000000,local_60,local_54[1],0,0);
          if (iVar6 < 0) goto LAB_005e1de6;
          local_8._0_3_ = SUB43(pppppppiVar11,0);
          local_8 = (int *******)CONCAT13(0x25,(undefined3)local_8);
          iVar6 = FUN_005d9fa1(param_2,local_8,local_5c,local_54[0],local_60,0);
          if ((iVar6 < 0) ||
             (iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x13000000,local_58,local_5c,0,4), iVar6 < 0))
          goto LAB_005e1de6;
          uVar20 = ZEXT48(local_58);
          pppppppiVar17 = local_8;
          pppppppiVar11 = param_3;
          pppppppiVar14 = local_54[1];
          goto LAB_005e151b;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x19:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = 0;
        pppppppiVar17 = (int *******)((uint)local_8 & 0xffffff | 0x13000000);
        pppppppiVar11 = param_3;
        pppppppiVar14 = local_54[0];
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x1a:
    if ((int *******)local_20 != (int *******)0x0) {
      local_54[1] = _malloc((int)local_8 * 4);
      if (local_54[1] != (int *******)0x0) {
        pppppppiVar11 = _malloc((int)local_8 * 0x28);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            local_a4[uVar18] = (int ******)pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)pppppppiVar14;
          } while (uVar18 < 10);
          iVar6 = FUN_005d91c9(local_a4[0],local_8);
          if ((((((iVar6 < 0) || (iVar6 = FUN_005d91c9(local_a4[1],local_8), iVar6 < 0)) ||
                (iVar6 = FUN_005d91c9(local_a4[2],local_8), iVar6 < 0)) ||
               ((iVar6 = FUN_005d91c9(local_a4[3],local_8), iVar6 < 0 ||
                (iVar6 = FUN_005d91c9(local_a4[4],local_8), iVar6 < 0)))) ||
              (iVar6 = FUN_005d91c9(local_a4[5],local_8), iVar6 < 0)) ||
             (((iVar6 = FUN_005d91c9(local_a4[6],local_8), iVar6 < 0 ||
               (iVar6 = FUN_005d91c9(local_a4[7],local_8), iVar6 < 0)) ||
              (iVar6 = FUN_005d91c9(local_54[1],local_8), iVar6 < 0)))) goto LAB_005e1de6;
          uVar18 = (uint)local_8 & 0xffffff;
          local_10._0_3_ = SUB43(local_8,0);
          uVar4 = (undefined3)local_10;
          local_10 = (int *******)CONCAT13(0x11,(undefined3)local_10);
          iVar6 = FUN_005d9fa1(param_2,local_10,local_a4[0],local_54[0],0,0);
          if ((((iVar6 < 0) ||
               (iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x21000000,local_a4[1],local_a4[0],local_54[0]
                                     ,4), iVar6 < 0)) ||
              (iVar6 = FUN_005d9fa1(param_2,local_10,local_a4[2],local_a4[1],0,8), iVar6 < 0)) ||
             (iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x23000000,local_a4[3],local_a4[2],local_a4[1],
                                   0x2000017), iVar6 < 0)) goto LAB_005e1de6;
          _local_44 = (int *******)CONCAT13(0x24,uVar4);
          iVar6 = FUN_005d9fa1(param_2,_local_44,local_a4[4],local_a4[3],local_a4[1],4);
          if (((iVar6 < 0) ||
              (iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x15000000,local_a4[5],local_a4[4],0,0),
              iVar6 < 0)) ||
             ((iVar6 = FUN_005d9fa1(param_2,local_10,local_a4[6],local_a4[5],0,0), iVar6 < 0 ||
              ((iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x13000000,local_a4[7],local_a4[6],0,0x14),
               iVar6 < 0 ||
               (iVar6 = FUN_005d9fa1(param_2,_local_44,local_54[1],local_a4[5],local_a4[7],2),
               iVar6 < 0)))))) goto LAB_005e1de6;
          if (param_3 != (int *******)0x0) {
            iVar6 = FUN_005d91c9(local_a4[8],local_8);
            if ((((iVar6 < 0) || (iVar6 = FUN_005d91c9(local_80,local_8), iVar6 < 0)) ||
                (iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0)) ||
               (iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x14000000,local_a4[8],local_54[1],0,4),
               iVar6 < 0)) goto LAB_005e1de6;
            iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x12000000,local_80,local_a4[8],0,4);
            pppppppiVar14 = local_54[0];
            pppppppiVar11 = local_80;
            goto joined_r0x005e003f;
          }
          goto LAB_005dd6a0;
        }
      }
      goto LAB_005e12dc;
    }
    break;
  case 0x1b:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        pppppppiVar11 = _malloc((int)local_8 * 0x18);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            local_2c[uVar18 + 1] = (int ******)pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)local_8;
          } while (uVar18 < 6);
          iVar6 = FUN_005d91c9(local_2c[1],local_8);
          if ((((iVar6 < 0) || (iVar6 = FUN_005d91c9(local_24,local_8), iVar6 < 0)) ||
              (iVar6 = FUN_005d91c9(local_20,local_8), iVar6 < 0)) ||
             (((iVar6 = FUN_005d91c9(local_1c,local_8), iVar6 < 0 ||
               (iVar6 = FUN_005d91c9(local_18,local_8), iVar6 < 0)) ||
              ((iVar6 = FUN_005d91c9(local_14,local_8), iVar6 < 0 ||
               (iVar6 = FUN_005d91c9(param_3,local_8), pppppppiVar11 = local_8, iVar6 < 0))))))
          goto LAB_005e1de6;
          pppppppiVar17 = (int *******)((uint)local_8 & 0xffffff);
          iVar6 = FUN_005d9fa1(param_2,(uint)pppppppiVar17 | 0x1c000000,local_2c[1],local_54[0],0,0)
          ;
          if (iVar6 < 0) goto LAB_005e1de6;
          local_10._0_3_ = SUB43(pppppppiVar11,0);
          uVar4 = (undefined3)local_10;
          local_10 = (int *******)CONCAT13(0x11,(undefined3)local_10);
          iVar6 = FUN_005d9fa1(param_2,local_10,local_24,local_2c[1],0,0);
          if (iVar6 < 0) goto LAB_005e1de6;
          local_40 = (int *******)CONCAT13(0x21,uVar4);
          iVar6 = FUN_005d9fa1(param_2,local_40,local_20,local_24,local_2c[1],4);
          if (((iVar6 < 0) ||
              (iVar6 = FUN_005d9fa1(param_2,(uint)pppppppiVar17 | 0x1d000000,local_1c,local_54[0],0,
                                    0), iVar6 < 0)) ||
             ((iVar6 = FUN_005d9fa1(param_2,local_10,local_18,local_1c,0,0), iVar6 < 0 ||
              (iVar6 = FUN_005d9fa1(param_2,local_40,local_14,local_18,local_1c,4), iVar6 < 0))))
          goto LAB_005e1de6;
          uVar20 = CONCAT44(4,local_14);
          pppppppiVar14 = (int *******)local_20;
          goto LAB_005e0738;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x1c:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        pppppppiVar11 = _malloc((int)local_8 * 0x14);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            (&local_24)[uVar18] = pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)local_8;
          } while (uVar18 < 5);
          iVar6 = FUN_005d91c9(local_24,local_8);
          if (((iVar6 < 0) || (iVar6 = FUN_005d91c9(local_20,local_8), iVar6 < 0)) ||
             ((iVar6 = FUN_005d91c9(local_1c,local_8), iVar6 < 0 ||
              (((iVar6 = FUN_005d91c9(local_18,local_8), iVar6 < 0 ||
                (iVar6 = FUN_005d91c9(local_14,local_8), iVar6 < 0)) ||
               (iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0)))))) goto LAB_005e1de6;
          local_3c = (int *******)((uint)local_8 & 0xffffff);
          local_10 = (int *******)((uint)local_3c | 0x11000000);
          iVar6 = FUN_005d9fa1(param_2,local_10,local_24,local_54[0],0,0x40);
          if ((iVar6 < 0) ||
             (iVar6 = FUN_005d9fa1(param_2,(uint)local_3c | 0x24000000,local_20,local_54[0],local_24
                                   ,0x40), iVar6 < 0)) goto LAB_005e1de6;
LAB_005dec59:
          iVar6 = FUN_005d9fa1(param_2,local_10,local_1c,local_20,0x4000000000);
          if ((iVar6 < 0) ||
             ((iVar6 = FUN_005d9fa1(param_2,(uint)local_3c | 0x21000000,local_18,local_1c,local_20,
                                    0x40), iVar6 < 0 ||
              (iVar6 = FUN_005d9fa1(param_2,local_10,local_14,local_18,0,0x40),
              pppppppiVar17 = local_3c, pppppppiVar14 = (int *******)local_14,
              pppppppiVar11 = local_18, iVar6 < 0)))) goto LAB_005e1de6;
          goto LAB_005e1186;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x1d:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        pppppppiVar11 = _malloc((int)local_8 << 4);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            (&local_20)[uVar18] = (int ******)pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)local_8;
          } while (uVar18 < 4);
          iVar6 = FUN_005d91c9(local_20,local_8);
          if ((((iVar6 < 0) || (iVar6 = FUN_005d91c9(local_1c,local_8), iVar6 < 0)) ||
              (iVar6 = FUN_005d91c9(local_18,local_8), iVar6 < 0)) ||
             ((iVar6 = FUN_005d91c9(local_14,local_8), iVar6 < 0 ||
              (iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0)))) goto LAB_005e1de6;
          local_3c = (int *******)((uint)local_8 & 0xffffff);
          iVar6 = FUN_005d9fa1(param_2,(uint)local_3c | 0x12000000,local_20,local_54[0],0,0x40);
          if (iVar6 < 0) goto LAB_005e1de6;
          local_10 = (int *******)((uint)local_3c | 0x11000000);
          goto LAB_005dec59;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x1e:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        pppppppiVar11 = _malloc((int)local_8 * 0x14);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            (&local_24)[uVar18] = pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)local_8;
          } while (uVar18 < 5);
          iVar6 = FUN_005d91c9(local_24,local_8);
          if ((((iVar6 < 0) || (iVar6 = FUN_005d91c9(local_20,local_8), iVar6 < 0)) ||
              (iVar6 = FUN_005d91c9(local_1c,local_8), iVar6 < 0)) ||
             (((iVar6 = FUN_005d91c9(local_18,local_8), iVar6 < 0 ||
               (iVar6 = FUN_005d91c9(local_14,local_8), iVar6 < 0)) ||
              (iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0)))) goto LAB_005e1de6;
          local_3c = (int *******)((uint)local_8 & 0xffffff);
          local_10 = (int *******)((uint)local_3c | 0x11000000);
          iVar6 = FUN_005d9fa1(param_2,local_10,local_24,local_54[0],0,0x40);
          if (((iVar6 < 0) ||
              (iVar6 = FUN_005d9fa1(param_2,(uint)local_3c | 0x21000000,local_20,local_54[0],
                                    local_24,0x40), iVar6 < 0)) ||
             (iVar6 = FUN_005d9fa1(param_2,local_10,local_1c,local_20,0,0x40), iVar6 < 0))
          goto LAB_005e1de6;
          local_58 = (int *******)((uint)local_3c | 0x23000000);
          iVar6 = FUN_005d9fa1(param_2,local_58,local_18,local_20,local_1c,0x2000017);
          if ((iVar6 < 0) ||
             (iVar6 = FUN_005d9fa1(param_2,local_10,local_14,local_18,0,0x1a), iVar6 < 0))
          goto LAB_005e1de6;
          uVar20 = CONCAT44(0x2000017,local_18);
          pppppppiVar17 = local_58;
          pppppppiVar11 = param_3;
          pppppppiVar14 = (int *******)local_14;
          goto LAB_005e151b;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x1f:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        local_c = _malloc((int)local_8 << 2);
        if (local_c != (int *******)0x0) {
          iVar6 = FUN_005d91c9(local_c,local_8);
          if ((iVar6 < 0) || (iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0)) goto LAB_005e1de6;
          uVar18 = (uint)local_8 & 0xffffff;
          iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x14000000,local_c,local_54[1],0,4);
          pppppppiVar14 = local_54[0];
          pppppppiVar11 = local_c;
joined_r0x005e003f:
          local_54[0] = pppppppiVar14;
          if (iVar6 < 0) goto LAB_005e1de6;
          uVar20 = ZEXT48(pppppppiVar11);
          goto LAB_005e127e;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x20:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        if (local_bc == (int ******)0x1) {
          param_3 = (int *******)0xffffffff;
          *pppppppiVar11 = (int ******)0xffffffff;
          iVar6 = FUN_005d9fa1(param_2,0x11000001,&param_3,local_54[0],0,0);
          if (iVar6 < 0) goto LAB_005e1de6;
          uVar20 = CONCAT44(4,&param_3);
          pppppppiVar17 = (int *******)0x21000001;
          pppppppiVar14 = local_54[0];
        }
        else {
          param_3 = (int *******)0xffffffff;
          uVar19 = FUN_005d91c9(pppppppiVar11,local_8);
          iVar6 = (int)uVar19;
          if ((iVar6 < 0) ||
             (iVar6 = FUN_005d9fa1(param_2,(uint)((ulonglong)uVar19 >> 0x20) & 0xffffff | 0x30000000
                                   ,&param_3,local_54[0],local_54[0],4), iVar6 < 0))
          goto LAB_005e1de6;
          uVar20 = 0x400000000;
          pppppppiVar17 = (int *******)0x16000001;
          pppppppiVar14 = (int *******)&param_3;
        }
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x21:
    if ((((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) &&
       (local_18 != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        iVar6 = FUN_005dbae8(param_2,param_3,local_54[0],local_54[1],local_54[2],local_8);
        goto LAB_005e1525;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x22:
    if (((((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) &&
        (local_18 != (int *******)0x0)) && (local_8 == (int *******)0x4)) {
      if (param_3 != (int *******)0x0) {
        if ((*(byte *)(*(int *)(param_1 + 8) + 0x90) & 0x40) == 0) {
          local_c = _malloc(0x20);
          if (local_c == (int *******)0x0) goto LAB_005e12dc;
          uVar18 = 0;
          do {
            (&local_30)[uVar18] = local_c + uVar18;
            uVar18 = uVar18 + 1;
          } while (uVar18 < 8);
          pppppppiVar11 = local_c;
          for (iVar15 = 8; iVar15 != 0; iVar15 = iVar15 + -1) {
            *pppppppiVar11 = (int ******)0xffffffff;
            pppppppiVar11 = pppppppiVar11 + 1;
          }
          *param_3 = (int ******)0xffffffff;
          param_3[1] = (int ******)0xffffffff;
          param_3[2] = (int ******)0xffffffff;
          param_3[3] = (int ******)0xffffffff;
          iVar6 = FUN_005d9fa1(param_2,0x11000001,local_30,local_54[0],0,0);
          if ((((((iVar6 < 0) ||
                 (iVar6 = FUN_005d9fa1(param_2,0x22000001,local_2c[0],local_30,local_54[0],0x2000017
                                      ), iVar6 < 0)) ||
                ((iVar6 = FUN_005d9fa1(param_2,0x25000001,param_3 + 1,local_2c[0],local_54[0],0),
                 iVar6 < 0 ||
                 ((iVar6 = FUN_005d9fa1(param_2,0x11000001,local_2c[1],local_54[1],0,0), iVar6 < 0
                  || (iVar6 = FUN_005d9fa1(param_2,0x22000001,local_24,local_2c[1],local_54[1],
                                           0x2000017), iVar6 < 0)))))) ||
               (iVar6 = FUN_005d9fa1(param_2,0x25000001,local_20,local_2c[0],local_24,0x2000017),
               iVar6 < 0)) ||
              (((iVar6 = FUN_005d9fa1(param_2,0x15000001,local_1c,local_54[1],0,0), iVar6 < 0 ||
                (iVar6 = FUN_005d9fa1(param_2,0x25000001,local_18,local_54[2],local_1c,0), iVar6 < 0
                )) || (iVar6 = FUN_005d9fa1(param_2,0x14000001,local_14,local_18,0,4), iVar6 < 0))))
             || ((iVar6 = FUN_005d9fa1(param_2,0x25000001,param_3 + 2,local_20,local_14,4),
                 iVar6 < 0 ||
                 (iVar6 = FUN_005d9fa1(param_2,0x10000001,param_3,param_1 + 0x20,0,0x2000017),
                 iVar6 < 0)))) goto LAB_005e1de6;
          uVar20 = 0x200001700000000;
          pppppppiVar17 = (int *******)0x10000001;
          pppppppiVar11 = param_3 + 3;
          pppppppiVar14 = (int *******)(param_1 + 0x20);
        }
        else {
          local_20 = *local_54[0];
          local_1c = (int *******)*local_54[1];
          local_18 = (int *******)*local_54[2];
          local_14 = (int **)*local_54[2];
          *param_3 = (int ******)0xffffffff;
          param_3[1] = (int ******)0xffffffff;
          param_3[2] = (int ******)0xffffffff;
          uVar20 = 0;
          param_3[3] = (int ******)0xffffffff;
          pppppppiVar17 = (int *******)0x33000004;
          pppppppiVar14 = &local_20;
        }
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x23:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        fVar3 = (float10)log2((float10)2.0);
        ppppppiVar10 = (int ******)
                       FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,
                                    (double)((float10)0.6931471805599453 * fVar3));
        pppppppiVar11 = _malloc((int)local_8 << 3);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            (&local_5c)[uVar18] = (int ******)pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)local_8;
          } while (uVar18 < 2);
LAB_005df2b2:
          pppppppiVar11 = local_8;
          pppppppiVar14 = (int *******)local_5c;
          if (local_8 != (int *******)0x0) {
            for (; pppppppiVar11 != (int *******)0x0;
                pppppppiVar11 = (int *******)((int)pppppppiVar11 + -1)) {
              *pppppppiVar14 = ppppppiVar10;
              pppppppiVar14 = pppppppiVar14 + 1;
            }
          }
          iVar6 = FUN_005d91c9(local_58,local_8);
          if ((iVar6 < 0) || (iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0)) goto LAB_005e1de6;
          uVar18 = (uint)local_8 & 0xffffff;
          iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x15000000,local_58,local_54[0],0,0);
          if (iVar6 < 0) goto LAB_005e1de6;
          uVar20 = ZEXT48(local_58);
          pppppppiVar14 = (int *******)local_5c;
          goto LAB_005e127e;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x24:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        fVar3 = (float10)log2((float10)2.0);
        fVar2 = (float10)log2((float10)10.0);
        ppppppiVar10 = (int ******)
                       FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,
                                    (double)(((float10)0.6931471805599453 * fVar3) /
                                            ((float10)0.6931471805599453 * fVar2)));
        pppppppiVar11 = _malloc((int)local_8 << 3);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            (&local_5c)[uVar18] = (int ******)pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)local_8;
          } while (uVar18 < 2);
          goto LAB_005df2b2;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x25:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = 0;
        pppppppiVar17 = (int *******)((uint)local_8 & 0xffffff | 0x15000000);
        pppppppiVar11 = param_3;
        pppppppiVar14 = local_54[0];
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x26:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_54[1]);
        pppppppiVar17 = (int *******)((uint)local_8 & 0xffffff | 0x21000000);
        pppppppiVar11 = param_3;
        pppppppiVar14 = local_54[0];
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x27:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_54[1]);
        pppppppiVar17 = (int *******)((uint)local_8 & 0xffffff | 0x20000000);
        pppppppiVar11 = param_3;
        pppppppiVar14 = local_54[0];
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x28:
    if ((int *******)local_20 != (int *******)0x0) {
      local_54[1] = _malloc((int)local_8 * 4);
      if (local_54[1] != (int *******)0x0) {
        pppppppiVar11 = _malloc((int)local_8 * 0x24);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            (&local_34)[uVar18] = (int *)pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)pppppppiVar14;
          } while (uVar18 < 9);
          iVar6 = FUN_005d91c9(local_34,local_8);
          if (((((iVar6 < 0) || (iVar6 = FUN_005d91c9(local_30,local_8), iVar6 < 0)) ||
               (iVar6 = FUN_005d91c9(local_2c[0],local_8), iVar6 < 0)) ||
              (((iVar6 = FUN_005d91c9(local_2c[1],local_8), iVar6 < 0 ||
                (iVar6 = FUN_005d91c9(local_24,local_8), iVar6 < 0)) ||
               ((iVar6 = FUN_005d91c9(local_20,local_8), iVar6 < 0 ||
                ((iVar6 = FUN_005d91c9(local_1c,local_8), iVar6 < 0 ||
                 (iVar6 = FUN_005d91c9(local_18,local_8), iVar6 < 0)))))))) ||
             (iVar6 = FUN_005d91c9(local_54[1],local_8), pppppppiVar11 = local_8, iVar6 < 0))
          goto LAB_005e1de6;
          pppppppiVar14 = (int *******)((uint)local_8 & 0xffffff);
          local_3c = pppppppiVar14;
          iVar6 = FUN_005d9fa1(param_2,(uint)pppppppiVar14 | 0x13000000,local_34,local_54[0],0,0x14)
          ;
          if (iVar6 < 0) goto LAB_005e1de6;
          local_10._0_3_ = SUB43(pppppppiVar11,0);
          local_10 = (int *******)CONCAT13(0x11,(undefined3)local_10);
          iVar6 = FUN_005d9fa1(param_2,local_10,local_30,local_34,0,0x18);
          if (iVar6 < 0) goto LAB_005e1de6;
          _local_44 = (int *******)((uint)pppppppiVar14 | 0x24000000);
          iVar6 = FUN_005d9fa1(param_2,_local_44,local_2c[0],local_30,local_54[0],2);
          if ((iVar6 < 0) ||
             (iVar6 = FUN_005d9fa1(param_2,local_10,local_2c[1],local_54[0],0,0), iVar6 < 0))
          goto LAB_005e1de6;
          local_38 = (int *******)((uint)local_3c | 0x22000000);
          iVar6 = FUN_005d9fa1(param_2,local_38,local_24,local_54[0],local_2c[1],0x2000017);
          if (((iVar6 < 0) ||
              (((iVar6 = FUN_005d9fa1(param_2,local_10,local_20,local_34,0,0), iVar6 < 0 ||
                (iVar6 = FUN_005d9fa1(param_2,local_38,local_1c,local_20,local_34,0x2000017),
                iVar6 < 0)) ||
               (iVar6 = FUN_005d9fa1(param_2,(uint)local_3c | 0x25000000,local_18,local_24,local_1c,
                                     0x2000017), iVar6 < 0)))) ||
             (iVar6 = FUN_005d9fa1(param_2,_local_44,local_54[1],local_2c[0],local_18,2), iVar6 < 0)
             ) goto LAB_005e1de6;
          if (param_3 != (int *******)0x0) {
            iVar6 = FUN_005d91c9(local_14,local_8);
            if (((iVar6 < 0) || (iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0)) ||
               (iVar6 = FUN_005d9fa1(param_2,local_10,local_14,local_54[1],0,2), iVar6 < 0))
            goto LAB_005e1de6;
            uVar20 = CONCAT44(0x10,local_14);
            pppppppiVar17 = _local_44;
            pppppppiVar11 = param_3;
            pppppppiVar14 = local_54[0];
            goto LAB_005e151b;
          }
          goto LAB_005dd6a0;
        }
      }
      goto LAB_005e12dc;
    }
    break;
  case 0x29:
  case 0x2a:
  case 0x2b:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        local_c = _malloc((int)local_8 << 2);
        if (local_c != (int *******)0x0) {
          pppppppiVar11 = (int *******)0x0;
          if (local_8 != (int *******)0x0) {
            do {
              local_c[(int)pppppppiVar11] = *local_54[0];
              pppppppiVar11 = (int *******)((int)pppppppiVar11 + 1);
            } while (pppppppiVar11 < local_8);
          }
          iVar6 = FUN_005d91c9(param_3,local_8);
          if (iVar6 < 0) goto LAB_005e1de6;
          uVar20 = ZEXT48(local_54[1]);
          pppppppiVar14 = local_c;
          goto LAB_005e01bb;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x2c:
  case 0x2f:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        local_c = _malloc((int)local_8 << 2);
        if (local_c == (int *******)0x0) goto LAB_005e12dc;
        pppppppiVar11 = (int *******)0x0;
        if (local_8 != (int *******)0x0) {
          do {
            local_c[(int)pppppppiVar11] = *local_54[1];
            pppppppiVar11 = (int *******)((int)pppppppiVar11 + 1);
          } while (pppppppiVar11 < local_8);
        }
LAB_005e019c:
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_c);
        pppppppiVar14 = local_54[0];
        goto LAB_005e01bb;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x2d:
  case 0x2e:
  case 0x30:
  case 0x31:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      if (param_3 == (int *******)0x0) goto LAB_005dd6a0;
      pppppppiVar11 = (int *******)local_20[4];
      local_58 = pppppppiVar11;
      if ((pppppppiVar11 == (int *******)0x0) || (pppppppiVar11[1] != (int ******)0x8)) break;
      if (pppppppiVar11[4] != (int ******)0x1) {
        FUN_005d814c(2,pppppppiVar11[5],pppppppiVar11[6],pppppppiVar11[7],0x400);
        iVar6 = FUN_005dc68d(&local_12c,local_54[0],local_bc);
        if (-1 < iVar6) {
          local_10 = (int *******)pppppppiVar11[6];
          local_3c = (int *******)pppppppiVar11[7];
          FUN_005d8188();
          goto LAB_005df8d1;
        }
LAB_005df947:
        FUN_005d8188();
        goto LAB_005e1de6;
      }
      iVar6 = FUN_005dc68d(pppppppiVar11,local_54[0],local_bc);
      if (iVar6 < 0) goto LAB_005e1de6;
      local_10 = (int *******)pppppppiVar11[6];
      local_3c = (int *******)pppppppiVar11[7];
LAB_005df8d1:
      ppppppiVar10 = local_1c[4];
      if ((ppppppiVar10 == (int ******)0x0) || (ppppppiVar10[1] != (int *****)0x8)) break;
      if (ppppppiVar10[4] == (int *****)0x1) {
        iVar6 = FUN_005dc68d(ppppppiVar10,local_54[1],local_b8);
        if (iVar6 < 0) goto LAB_005e1de6;
        pppppppiVar11 = (int *******)ppppppiVar10[6];
        local_40 = (int *******)ppppppiVar10[7];
        _local_44 = pppppppiVar11;
      }
      else {
        FUN_005d814c(2,ppppppiVar10[5],ppppppiVar10[6],ppppppiVar10[7],0x800);
        iVar6 = FUN_005dc68d(local_a4 + 1,local_54[1],local_b8);
        if (iVar6 < 0) goto LAB_005df947;
        local_40 = (int *******)ppppppiVar10[6];
        pppppppiVar11 = (int *******)ppppppiVar10[7];
        _local_44 = pppppppiVar11;
        FUN_005d8188();
      }
      if ((local_3c != local_40) || (local_8 != (int *******)((int)pppppppiVar11 * (int)local_10)))
      break;
      iVar15 = FUN_005d99dd(local_54[0],local_58[4],local_10,local_3c);
      if (iVar15 == 0) {
        pppppppiVar11 = _malloc((int)local_10 * 0x14);
        local_c = pppppppiVar11;
        if (pppppppiVar11 == (int *******)0x0) goto LAB_005e12dc;
        uVar18 = 0;
        do {
          (&local_24)[uVar18] = pppppppiVar11;
          uVar18 = uVar18 + 1;
          pppppppiVar11 = pppppppiVar11 + (int)local_10;
        } while (uVar18 < 5);
        local_8 = (int *******)0x0;
        if (_local_44 != (int *******)0x0) {
          local_6c = param_3;
          do {
            param_3 = (int *******)0x0;
            if (local_40 != (int *******)0x0) {
              do {
                if (local_10 != (int *******)0x0) {
                  local_58 = (int *******)((int)local_3c * 4);
                  pppppppiVar11 = local_54[0] + (int)param_3;
                  local_38 = local_10;
                  pppppppiVar14 = (int *******)local_20;
                  do {
                    ppppppiVar10 = *pppppppiVar11;
                    pppppppiVar11 = pppppppiVar11 + (int)local_3c;
                    *(int *******)(((int)local_24 - (int)local_20) + (int)pppppppiVar14) =
                         ppppppiVar10;
                    *pppppppiVar14 =
                         local_54[1][(int)((int)param_3 * (int)_local_44 + (int)local_8)];
                    pppppppiVar14 = pppppppiVar14 + 1;
                    local_38 = (int *******)((int)local_38 + -1);
                  } while (local_38 != (int *******)0x0);
                }
                iVar6 = FUN_005d91c9(local_18,local_10);
                if (iVar6 < 0) goto LAB_005e1de6;
                uVar18 = (uint)local_10 & 0xffffff;
                iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x25000000,local_18,local_24,local_20,0);
                if ((iVar6 < 0) ||
                   ((pppppppiVar11 = local_18, param_3 != (int *******)0x0 &&
                    ((iVar6 = FUN_005d91c9(local_14,local_10), iVar6 < 0 ||
                     (iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x24000000,local_14,local_1c,local_18,0)
                     , pppppppiVar11 = (int *******)local_14, iVar6 < 0)))))) goto LAB_005e1de6;
                pppppppiVar14 = local_1c;
                for (uVar18 = (uint)local_10 & 0x3fffffff; uVar18 != 0; uVar18 = uVar18 - 1) {
                  *pppppppiVar14 = *pppppppiVar11;
                  pppppppiVar11 = pppppppiVar11 + 1;
                  pppppppiVar14 = pppppppiVar14 + 1;
                }
                param_3 = (int *******)((int)param_3 + 1);
                for (iVar15 = 0; iVar15 != 0; iVar15 = iVar15 + -1) {
                  *(undefined1 *)pppppppiVar14 = *(undefined1 *)pppppppiVar11;
                  pppppppiVar11 = (int *******)((int)pppppppiVar11 + 1);
                  pppppppiVar14 = (int *******)((int)pppppppiVar14 + 1);
                }
              } while (param_3 < local_40);
            }
            pppppppiVar14 = (int *******)0x0;
            pppppppiVar11 = local_6c;
            if (local_10 != (int *******)0x0) {
              do {
                *pppppppiVar11 = local_1c[(int)pppppppiVar14];
                pppppppiVar14 = (int *******)((int)pppppppiVar14 + 1);
                pppppppiVar11 = pppppppiVar11 + (int)_local_44;
              } while (pppppppiVar14 < local_10);
            }
            local_8 = (int *******)((int)local_8 + 1);
            local_6c = local_6c + 1;
          } while (local_8 < _local_44);
        }
      }
      else {
        iVar15 = FUN_005d9ac5(local_54[1],ppppppiVar10[4],local_40,pppppppiVar11);
        if (iVar15 == 0) {
          pppppppiVar11 = _malloc((int)pppppppiVar11 * 0x14);
          local_c = pppppppiVar11;
          if (pppppppiVar11 == (int *******)0x0) goto LAB_005e12dc;
          uVar18 = 0;
          do {
            (&local_24)[uVar18] = pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)_local_44;
          } while (uVar18 < 5);
          local_68 = (int *******)0x0;
          if (local_10 != (int *******)0x0) {
            local_38 = (int *******)0x0;
            local_64 = param_3;
            do {
              param_3 = (int *******)0x0;
              if (local_3c != (int *******)0x0) {
                do {
                  if (_local_44 != (int *******)0x0) {
                    pppppppiVar11 = local_54[1] + (int)param_3 * (int)_local_44;
                    local_6c = _local_44;
                    pppppppiVar14 = (int *******)local_20;
                    do {
                      *(int *******)(((int)local_24 - (int)local_20) + (int)pppppppiVar14) =
                           local_54[0][(int)local_38 + (int)param_3];
                      *pppppppiVar14 = *pppppppiVar11;
                      pppppppiVar11 = pppppppiVar11 + 1;
                      pppppppiVar14 = pppppppiVar14 + 1;
                      local_6c = (int *******)((int)local_6c + -1);
                    } while (local_6c != (int *******)0x0);
                  }
                  iVar6 = FUN_005d91c9(local_18,_local_44);
                  if (iVar6 < 0) goto LAB_005e1de6;
                  uVar18 = (uint)_local_44 & 0xffffff;
                  iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x25000000,local_18,local_24,local_20,0);
                  if ((iVar6 < 0) ||
                     ((pppppppiVar11 = local_18, param_3 != (int *******)0x0 &&
                      ((iVar6 = FUN_005d91c9(local_14,_local_44), iVar6 < 0 ||
                       (iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x24000000,local_14,local_1c,local_18,
                                             0), pppppppiVar11 = (int *******)local_14, iVar6 < 0)))
                      ))) goto LAB_005e1de6;
                  pppppppiVar14 = local_1c;
                  for (uVar18 = (uint)_local_44 & 0x3fffffff; uVar18 != 0; uVar18 = uVar18 - 1) {
                    *pppppppiVar14 = *pppppppiVar11;
                    pppppppiVar11 = pppppppiVar11 + 1;
                    pppppppiVar14 = pppppppiVar14 + 1;
                  }
                  param_3 = (int *******)((int)param_3 + 1);
                  for (iVar15 = 0; iVar15 != 0; iVar15 = iVar15 + -1) {
                    *(undefined1 *)pppppppiVar14 = *(undefined1 *)pppppppiVar11;
                    pppppppiVar11 = (int *******)((int)pppppppiVar11 + 1);
                    pppppppiVar14 = (int *******)((int)pppppppiVar14 + 1);
                  }
                } while (param_3 < local_3c);
              }
              pppppppiVar14 = (int *******)0x0;
              pppppppiVar11 = local_64;
              if (_local_44 != (int *******)0x0) {
                do {
                  *pppppppiVar11 = local_1c[(int)pppppppiVar14];
                  pppppppiVar14 = (int *******)((int)pppppppiVar14 + 1);
                  pppppppiVar11 = pppppppiVar11 + 1;
                } while (pppppppiVar14 < _local_44);
              }
              local_38 = (int *******)((int)local_38 + (int)local_3c);
              local_68 = (int *******)((int)local_68 + 1);
              local_64 = local_64 + (int)_local_44;
            } while (local_68 < local_10);
          }
        }
        else {
          local_c = _malloc((int)local_b8 << 2);
          if (local_c == (int *******)0x0) {
LAB_005e12dc:
            iVar6 = -0x7ff8fff2;
            goto LAB_005e1de6;
          }
          if (local_40 != (int *******)0x0) {
            local_6c = local_54[1];
            local_64 = local_40;
            local_68 = local_c;
            do {
              if (_local_44 != (int *******)0x0) {
                local_38 = _local_44;
                pppppppiVar11 = local_6c;
                pppppppiVar14 = local_68;
                do {
                  *pppppppiVar14 = *pppppppiVar11;
                  pppppppiVar11 = pppppppiVar11 + 1;
                  pppppppiVar14 = pppppppiVar14 + (int)local_40;
                  local_38 = (int *******)((int)local_38 + -1);
                } while (local_38 != (int *******)0x0);
                local_38 = (int *******)0x0;
              }
              local_68 = local_68 + 1;
              local_6c = local_6c + (int)_local_44;
              local_64 = (int *******)((int)local_64 + -1);
            } while (local_64 != (int *******)0x0);
          }
          uVar19 = FUN_005d91c9(param_3,local_8);
          iVar6 = (int)uVar19;
          if (iVar6 < 0) goto LAB_005e1de6;
          local_38 = (int *******)0x0;
          if (local_10 != (int *******)0x0) {
            local_70 = (int)_local_44 << 2;
            local_74 = (int ******)((int)local_3c << 2);
            local_8 = local_54[0];
            pppppppiVar11 = _local_44;
            local_64 = (int *******)((ulonglong)uVar19 >> 0x20);
            do {
              local_6c = (int *******)0x0;
              if (pppppppiVar11 != (int *******)0x0) {
                uVar18 = (uint)local_3c & 0xffffff;
                local_58 = (int *******)((int)local_40 << 2);
                param_3 = local_64;
                local_68 = local_c;
                do {
                  iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x30000000,param_3,local_8,local_68,0);
                  if (iVar6 < 0) goto LAB_005e1de6;
                  local_68 = (int *******)((int)local_68 + (int)local_58);
                  local_6c = (int *******)((int)local_6c + 1);
                  param_3 = param_3 + 1;
                  pppppppiVar11 = _local_44;
                } while (local_6c < _local_44);
              }
              local_8 = (int *******)((int)local_8 + (int)local_74);
              local_38 = (int *******)((int)local_38 + 1);
              local_64 = (int *******)((int)local_64 + local_70);
            } while (local_38 < local_10);
          }
        }
      }
LAB_005dd6a0:
      iVar15 = *(int *)(local_154 + 0xc);
      if (iVar15 != 0) {
        param_2 = (int *******)local_54;
        do {
          if (*(int *)(iVar15 + 8) != 0) {
            *(int *******)(param_1 + 0x1c) = *param_2;
            iVar6 = FUN_005e2a38(*(undefined4 *)(iVar15 + 8));
            if (iVar6 < 0) goto LAB_005e1de6;
          }
          iVar15 = *(int *)(iVar15 + 0xc);
          param_2 = param_2 + 1;
        } while (iVar15 != 0);
      }
      iVar6 = 0;
      goto LAB_005e1de6;
    }
    break;
  case 0x32:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        *param_3 = (int ******)0xffffffff;
        uVar20 = 0x1000000000;
        pppppppiVar17 = (int *******)((uint)local_bc & 0xffffff | 0x35000000);
        pppppppiVar14 = local_54[0];
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x33:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        if (local_8 == (int *******)0x1) {
          local_c = _malloc(0x10);
          if (local_c != (int *******)0x0) {
            uVar18 = 0;
            do {
              (&local_20)[uVar18] = (int ******)(local_c + uVar18);
              uVar18 = uVar18 + 1;
            } while (uVar18 < 4);
            iVar6 = FUN_005d91c9(local_20,1);
            if ((((iVar6 < 0) || (iVar6 = FUN_005d91c9(local_1c,1), iVar6 < 0)) ||
                ((iVar6 = FUN_005d91c9(local_18,1), iVar6 < 0 ||
                 ((((iVar6 = FUN_005d91c9(local_14,1), iVar6 < 0 ||
                    (iVar6 = FUN_005d91c9(param_3,1), iVar6 < 0)) ||
                   (iVar6 = FUN_005d9fa1(param_2,0x11000001,local_20,local_54[0],0,0), iVar6 < 0))
                  || ((iVar6 = FUN_005d9fa1(param_2,0x22000001,local_1c,local_20,local_54[0],
                                            0x2000017), iVar6 < 0 ||
                      (iVar6 = FUN_005d9fa1(param_2,0x22000001,local_18,local_54[0],local_20,
                                            0x2000017), iVar6 < 0)))))))) ||
               (iVar6 = FUN_005d9fa1(param_2,0x11000001,local_14,local_18,0,0x1a), iVar6 < 0))
            goto LAB_005e1de6;
            uVar20 = CONCAT44(0x12,local_14);
            pppppppiVar14 = local_1c;
            goto LAB_005dff6c;
          }
        }
        else {
          uVar18 = (uint)local_8 & 0xffffff;
          local_38 = (int *******)0xffffffff;
          local_64 = (int *******)0xffffffff;
          local_68 = (int *******)0xffffffff;
          iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x30000000,&local_38,local_54[0],local_54[0],4);
          if (((iVar6 < 0) ||
              (iVar6 = FUN_005d9fa1(param_2,0x16000001,&local_64,&local_38,0,4), iVar6 < 0)) ||
             (iVar6 = FUN_005d9fa1(param_2,0x12000001,&local_68,&local_64,0,4), iVar6 < 0))
          goto LAB_005e1de6;
          local_c = _malloc((int)local_8 << 2);
          if (local_c != (int *******)0x0) {
            pppppppiVar11 = (int *******)0x0;
            if (local_8 != (int *******)0x0) {
              do {
                local_c[(int)pppppppiVar11] = (int ******)local_68;
                pppppppiVar11 = (int *******)((int)pppppppiVar11 + 1);
              } while (pppppppiVar11 < local_8);
            }
            iVar6 = FUN_005d91c9(param_3,local_8);
            pppppppiVar14 = local_54[0];
            pppppppiVar11 = local_c;
            goto joined_r0x005e003f;
          }
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x34:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        pppppppiVar11 = _malloc((int)local_8 << 3);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            (&local_5c)[uVar18] = (int ******)pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)local_8;
          } while (uVar18 < 2);
          iVar6 = FUN_005d91c9(local_5c,local_8);
          if (((iVar6 < 0) || (iVar6 = FUN_005d91c9(local_58,local_8), iVar6 < 0)) ||
             (iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0)) goto LAB_005e1de6;
          uVar18 = (uint)local_8 & 0xffffff;
          iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x15000000,local_5c,local_54[0],0,0);
          if (iVar6 < 0) goto LAB_005e1de6;
          iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x25000000,local_58,local_54[1],local_5c,0);
          pppppppiVar14 = local_58;
          goto joined_r0x005e0130;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x35:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        uVar19 = 0x3f91df46aaaaaaab;
        goto LAB_005e0162;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x36:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        pppppppiVar17 = (int *******)((uint)local_8 & 0xffffff);
        local_38 = (int *******)0xffffffff;
        local_64 = (int *******)0xffffffff;
        local_68 = (int *******)0xffffffff;
        iVar6 = FUN_005d9fa1(param_2,(uint)pppppppiVar17 | 0x30000000,&local_38,local_54[0],
                             local_54[1],0);
        if (((iVar6 < 0) ||
            (iVar6 = FUN_005d9fa1(param_2,0x24000001,&local_64,&local_38,&local_38,0), iVar6 < 0))
           || (iVar6 = FUN_005d9fa1(param_2,0x11000001,&local_68,&local_64,0,0), iVar6 < 0))
        goto LAB_005e1de6;
        pppppppiVar11 = _malloc((int)local_8 << 3);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            (&local_5c)[uVar18] = (int ******)pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)local_8;
          } while (uVar18 < 2);
          pppppppiVar11 = (int *******)0x0;
          if (local_8 != (int *******)0x0) {
            do {
              local_5c[(int)pppppppiVar11] = (int *****)local_68;
              pppppppiVar11 = (int *******)((int)pppppppiVar11 + 1);
            } while (pppppppiVar11 < local_8);
          }
          iVar6 = FUN_005d91c9(local_58,local_8);
          if (iVar6 < 0) goto LAB_005e1de6;
          uVar19 = FUN_005d91c9(param_3,local_8);
          iVar6 = (int)uVar19;
          if ((iVar6 < 0) ||
             (iVar6 = FUN_005d9fa1(param_2,(uint)pppppppiVar17 | 0x25000000,local_58,local_54[1],
                                   (int)((ulonglong)uVar19 >> 0x20),0), iVar6 < 0))
          goto LAB_005e1de6;
          uVar20 = ZEXT48(local_54[0]);
          pppppppiVar14 = local_58;
          goto LAB_005e0738;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x37:
    if ((((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) &&
       (local_18 != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        local_40 = (int *******)0xffffffff;
        uVar19 = FUN_005d91c9(&local_6c,1);
        iVar6 = (int)uVar19;
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar19 = FUN_005d91c9(local_104,(int)((ulonglong)uVar19 >> 0x20));
        iVar6 = (int)uVar19;
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar19 = FUN_005d91c9(&stack0xffffffbc,(int)((ulonglong)uVar19 >> 0x20));
        iVar6 = (int)uVar19;
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar19 = FUN_005d91c9(&local_10,(int)((ulonglong)uVar19 >> 0x20));
        iVar6 = (int)uVar19;
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar19 = FUN_005d91c9(&local_38,(int)((ulonglong)uVar19 >> 0x20));
        iVar6 = (int)uVar19;
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar19 = FUN_005d91c9(&local_64,(int)((ulonglong)uVar19 >> 0x20));
        iVar6 = (int)uVar19;
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar19 = FUN_005d91c9(local_108,(int)((ulonglong)uVar19 >> 0x20));
        iVar6 = (int)uVar19;
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar19 = FUN_005d91c9(&local_68,(int)((ulonglong)uVar19 >> 0x20));
        iVar6 = (int)uVar19;
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar19 = FUN_005d91c9(&local_74,(int)((ulonglong)uVar19 >> 0x20));
        iVar6 = (int)uVar19;
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar19 = FUN_005d91c9(&local_70,(int)((ulonglong)uVar19 >> 0x20));
        iVar6 = (int)uVar19;
        if ((iVar6 < 0) ||
           (iVar6 = FUN_005d91c9(&local_58,(int)((ulonglong)uVar19 >> 0x20)), iVar6 < 0))
        goto LAB_005e1de6;
        local_3c = (int *******)((uint)local_8 & 0xffffff);
        iVar6 = FUN_005d9fa1(param_2,(uint)local_3c | 0x30000000,&local_40,local_54[0],local_54[1],0
                            );
        if ((((iVar6 < 0) ||
             ((((((iVar6 = FUN_005d9fa1(param_2,0x25000001,&local_6c,&local_40,&local_40,4),
                  iVar6 < 0 ||
                  (iVar6 = FUN_005d9fa1(param_2,0x25000001,local_104,local_54[2],local_54[2],4),
                  iVar6 < 0)) ||
                 (iVar6 = FUN_005d9fa1(param_2,0x11000001,&stack0xffffffbc,&local_6c,0,8), iVar6 < 0
                 )) || ((iVar6 = FUN_005d9fa1(param_2,0x24000001,&local_10,param_1 + 0x20,
                                              &stack0xffffffbc,0), iVar6 < 0 ||
                        (iVar6 = FUN_005d9fa1(param_2,0x25000001,&local_38,local_104,&local_10,0),
                        iVar6 < 0)))) ||
               (iVar6 = FUN_005d9fa1(param_2,0x23000001,&local_64,&local_38,param_1 + 0x24,0x2000017
                                    ), iVar6 < 0)) ||
              ((iVar6 = FUN_005d9fa1(param_2,0x25000001,local_108,&local_38,&local_64,4), iVar6 < 0
               || (iVar6 = FUN_005d9fa1(param_2,0x25000001,&local_68,local_54[2],&local_64,0),
                  iVar6 < 0)))))) ||
            (iVar6 = FUN_005d9fa1(param_2,0x25000001,&local_74,&local_68,&local_40,0), iVar6 < 0))
           || ((iVar6 = FUN_005d9fa1(param_2,0x16000001,&local_70,local_108,0,4), iVar6 < 0 ||
               (iVar6 = FUN_005d9fa1(param_2,0x24000001,&local_58,&local_74,&local_70,0), iVar6 < 0)
               ))) goto LAB_005e1de6;
        pppppppiVar11 = _malloc((int)local_8 * 0x14);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            (&local_24)[uVar18] = pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)local_8;
          } while (uVar18 < 5);
          if (local_8 != (int *******)0x0) {
            pppppppiVar11 = (int *******)local_14;
            pppppppiVar14 = local_8;
            do {
              *(int ********)(((int)local_18 - (int)local_14) + (int)pppppppiVar11) = local_68;
              *pppppppiVar11 = (int ******)local_58;
              pppppppiVar11 = pppppppiVar11 + 1;
              pppppppiVar14 = (int *******)((int)pppppppiVar14 + -1);
            } while (pppppppiVar14 != (int *******)0x0);
          }
          iVar6 = FUN_005d91c9(local_24,local_8);
          if ((((iVar6 < 0) || (iVar6 = FUN_005d91c9(local_20,local_8), iVar6 < 0)) ||
              (iVar6 = FUN_005d91c9(local_1c,local_8), iVar6 < 0)) ||
             (iVar6 = FUN_005d91c9(param_3,local_8), pppppppiVar17 = local_3c, iVar6 < 0))
          goto LAB_005e1de6;
          local_8 = (int *******)((uint)local_3c | 0x25000000);
          iVar6 = FUN_005d9fa1(param_2,local_8,local_24,local_18,local_54[0],0);
          if (((iVar6 < 0) ||
              (iVar6 = FUN_005d9fa1(param_2,local_8,local_20,local_14,local_54[1],0), iVar6 < 0)) ||
             (iVar6 = FUN_005d9fa1(param_2,(uint)pppppppiVar17 | 0x11000000,local_1c,local_20,0,0),
             iVar6 < 0)) goto LAB_005e1de6;
          uVar20 = ZEXT48(local_1c);
          pppppppiVar14 = local_24;
          goto LAB_005e0738;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x38:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        ppppppiVar10 = (int ******)
                       FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,
                                    0x3fe0000000000000);
        pppppppiVar11 = _malloc((int)local_8 << 4);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            (&local_20)[uVar18] = (int ******)pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)local_8;
          } while (uVar18 < 4);
          pppppppiVar11 = local_8;
          pppppppiVar14 = (int *******)local_14;
          if (local_8 != (int *******)0x0) {
            for (; pppppppiVar11 != (int *******)0x0;
                pppppppiVar11 = (int *******)((int)pppppppiVar11 + -1)) {
              *pppppppiVar14 = ppppppiVar10;
              pppppppiVar14 = pppppppiVar14 + 1;
            }
          }
          iVar6 = FUN_005d91c9(local_20,local_8);
          if ((((iVar6 < 0) || (iVar6 = FUN_005d91c9(local_1c,local_8), iVar6 < 0)) ||
              (iVar6 = FUN_005d91c9(local_18,local_8), iVar6 < 0)) ||
             (iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0)) goto LAB_005e1de6;
          uVar18 = (uint)local_8 & 0xffffff;
          local_44 = SUB43(local_8,0);
          _local_44 = (int *******)CONCAT13(0x24,local_44);
          iVar6 = FUN_005d9fa1(param_2,_local_44,local_20,local_54[0],local_14,0);
          if (((iVar6 < 0) ||
              (iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x13000000,local_1c,local_20,0,0x14), iVar6 < 0
              )) || (iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x11000000,local_18,local_1c,0,0x18),
                    iVar6 < 0)) goto LAB_005e1de6;
          uVar20 = CONCAT44(2,local_18);
          pppppppiVar17 = _local_44;
          pppppppiVar11 = param_3;
          pppppppiVar14 = (int *******)local_20;
          goto LAB_005e151b;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x39:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        local_c = _malloc((int)local_8 << 2);
        if (local_c != (int *******)0x0) {
          iVar6 = FUN_005d91c9(local_c,local_8);
          if ((iVar6 < 0) || (iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0)) goto LAB_005e1de6;
          uVar18 = (uint)local_8 & 0xffffff;
          iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x16000000,local_c,local_54[0],0,4);
          if (iVar6 < 0) goto LAB_005e1de6;
          uVar20 = 0x400000000;
          pppppppiVar17 = (int *******)(uVar18 | 0x12000000);
          pppppppiVar11 = param_3;
          pppppppiVar14 = local_c;
          goto LAB_005e151b;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x3a:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        pppppppiVar11 = _malloc((int)local_8 * 0xc);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            (&local_60)[uVar18] = pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)local_8;
          } while (uVar18 < 3);
          if (local_8 != (int *******)0x0) {
            pppppppiVar11 = (int *******)local_5c;
            pppppppiVar14 = local_8;
            do {
              *(undefined4 *)(((int)local_60 - (int)local_5c) + (int)pppppppiVar11) =
                   *(undefined4 *)(param_1 + 0x24);
              *pppppppiVar11 = *(int *******)(param_1 + 0x20);
              pppppppiVar11 = pppppppiVar11 + 1;
              pppppppiVar14 = (int *******)((int)pppppppiVar14 + -1);
            } while (pppppppiVar14 != (int *******)0x0);
          }
          iVar6 = FUN_005d91c9(local_58,local_8);
          if ((iVar6 < 0) || (iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0)) goto LAB_005e1de6;
          uVar18 = (uint)local_8 & 0xffffff;
          iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x21000000,local_58,local_54[0],local_60,4);
          if (iVar6 < 0) goto LAB_005e1de6;
          uVar20 = CONCAT44(0x14,local_5c);
          pppppppiVar14 = local_58;
          goto LAB_005e09fb;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x3b:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        pppppppiVar11 = _malloc((int)local_8 << 4);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            (&local_20)[uVar18] = (int ******)pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)local_8;
          } while (uVar18 < 4);
          iVar6 = FUN_005d91c9(local_20,local_8);
          if (((iVar6 < 0) || (iVar6 = FUN_005d91c9(local_1c,local_8), iVar6 < 0)) ||
             ((iVar6 = FUN_005d91c9(local_18,local_8), iVar6 < 0 ||
              ((iVar6 = FUN_005d91c9(local_14,local_8), iVar6 < 0 ||
               (iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0)))))) goto LAB_005e1de6;
          local_3c = (int *******)((uint)local_8 & 0xffffff);
          local_10 = (int *******)((uint)local_3c | 0x11000000);
          iVar6 = FUN_005d9fa1(param_2,local_10,local_20,local_54[0],0,0);
          if (iVar6 < 0) goto LAB_005e1de6;
          local_38 = (int *******)((uint)local_3c | 0x22000000);
          iVar6 = FUN_005d9fa1(param_2,local_38,local_1c,local_20,local_54[0],0x2000017);
          if (((iVar6 < 0) ||
              (iVar6 = FUN_005d9fa1(param_2,local_38,local_18,local_54[0],local_20,0x2000017),
              iVar6 < 0)) ||
             (iVar6 = FUN_005d9fa1(param_2,local_10,local_14,local_18,0,0x1a), iVar6 < 0))
          goto LAB_005e1de6;
          uVar20 = CONCAT44(0x12,local_14);
          pppppppiVar17 = (int *******)((uint)local_3c | 0x24000000);
          pppppppiVar11 = param_3;
          pppppppiVar14 = local_1c;
          goto LAB_005e151b;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x3c:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        lVar21 = ZEXT48(local_8) << 0x20;
        pppppppiVar11 = param_3;
        goto LAB_005e0c0f;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x3d:
    if ((int *******)local_20 != (int *******)0x0) {
      _Size = (int)local_bc << 2;
      local_54[1] = _malloc(_Size);
      if (local_54[1] != (int *******)0x0) {
        local_54[2] = _malloc(_Size);
        if (local_54[2] != (int *******)0x0) {
          uVar19 = FUN_005d91c9(local_54[1],ppppppiVar10);
          iVar6 = (int)uVar19;
          if (iVar6 < 0) goto LAB_005e1de6;
          uVar19 = FUN_005d91c9((int)((ulonglong)uVar19 >> 0x20),ppppppiVar10);
          iVar6 = (int)uVar19;
          if (iVar6 < 0) goto LAB_005e1de6;
          lVar21 = CONCAT44(ppppppiVar10,(int)((ulonglong)uVar19 >> 0x20));
          pppppppiVar11 = local_54[1];
          goto LAB_005e0c0f;
        }
      }
      goto LAB_005e12dc;
    }
    break;
  case 0x3e:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        fVar3 = (float10)log2((float10)2.0);
        uVar8 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,
                             (double)((float10)1.0 / ((float10)0.6931471805599453 * fVar3)));
        local_58 = (int *******)
                   FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0x3fe0000000000000
                               );
        pppppppiVar11 = _malloc((int)local_8 << 5);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            (&local_30)[uVar18] = pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)local_8;
          } while (uVar18 < 8);
          if (local_8 != (int *******)0x0) {
            pppppppiVar11 = (int *******)local_14;
            pppppppiVar14 = local_8;
            do {
              *(undefined4 *)(((int)local_18 - (int)local_14) + (int)pppppppiVar11) = uVar8;
              *pppppppiVar11 = (int ******)local_58;
              pppppppiVar11 = pppppppiVar11 + 1;
              pppppppiVar14 = (int *******)((int)pppppppiVar14 + -1);
            } while (pppppppiVar14 != (int *******)0x0);
          }
          iVar6 = FUN_005d91c9(local_30,local_8);
          if ((((iVar6 < 0) || (iVar6 = FUN_005d91c9(local_2c[0],local_8), iVar6 < 0)) ||
              ((iVar6 = FUN_005d91c9(local_2c[1],local_8), iVar6 < 0 ||
               ((iVar6 = FUN_005d91c9(local_24,local_8), iVar6 < 0 ||
                (iVar6 = FUN_005d91c9(local_20,local_8), iVar6 < 0)))))) ||
             ((iVar6 = FUN_005d91c9(local_1c,local_8), iVar6 < 0 ||
              (iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0)))) goto LAB_005e1de6;
          uVar18 = (uint)local_8 & 0xffffff;
          uVar4 = (undefined3)local_8;
          local_8 = (int *******)CONCAT13(0x25,(undefined3)local_8);
          iVar6 = FUN_005d9fa1(param_2,local_8,local_30,local_54[0],local_18,0);
          if (iVar6 < 0) goto LAB_005e1de6;
          local_3c = (int *******)CONCAT13(0x14,uVar4);
          iVar6 = FUN_005d9fa1(param_2,local_3c,local_2c[0],local_30,0,4);
          if (iVar6 < 0) goto LAB_005e1de6;
          local_10 = (int *******)CONCAT13(0x11,uVar4);
          iVar6 = FUN_005d9fa1(param_2,local_10,local_2c[1],local_30,0,0);
          if ((((iVar6 < 0) ||
               (iVar6 = FUN_005d9fa1(param_2,local_3c,local_24,local_2c[1],0,4), iVar6 < 0)) ||
              (iVar6 = FUN_005d9fa1(param_2,local_10,local_20,local_24,0,8), iVar6 < 0)) ||
             (iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x24000000,local_1c,local_2c[0],local_20,0),
             iVar6 < 0)) goto LAB_005e1de6;
          uVar8 = 0;
          goto LAB_005e0e4c;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x3f:
    if ((((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) &&
       (local_18 != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        local_74 = (int ******)
                   FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0xc000000000000000
                               );
        local_70 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0x4008000000000000
                               );
        pppppppiVar11 = _malloc((int)local_8 * 0x38);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            local_100[uVar18] = (int)pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)local_8;
          } while (uVar18 < 0xe);
          uVar18 = 0;
          do {
            uVar19 = FUN_005d91c9(local_100[uVar18],local_8);
            iVar6 = (int)uVar19;
            if (iVar6 < 0) goto LAB_005e1de6;
            uVar18 = (int)((ulonglong)uVar19 >> 0x20) + 1;
          } while (uVar18 < 10);
          if (local_8 != (int *******)0x0) {
            local_58 = local_8;
            puVar9 = local_d4;
            do {
              *(undefined4 *)((local_d8 - (int)local_d4) + (int)puVar9) =
                   *(undefined4 *)(param_1 + 0x24);
              *puVar9 = *(undefined4 *)(param_1 + 0x20);
              *(int *******)((local_d0 - (int)local_d4) + (int)puVar9) = local_74;
              *(int *)((local_cc - (int)local_d4) + (int)puVar9) = local_70;
              puVar9 = puVar9 + 1;
              local_58 = (int *******)((int)local_58 + -1);
            } while (local_58 != (int *******)0x0);
          }
          iVar6 = FUN_005d91c9(param_3,local_8);
          pppppppiVar11 = local_8;
          if (iVar6 < 0) goto LAB_005e1de6;
          uVar18 = (uint)local_8 & 0xffffff;
          iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x11000000,local_100[0],local_54[0],0,0);
          if (iVar6 < 0) goto LAB_005e1de6;
          local_44 = SUB43(pppppppiVar11,0);
          uVar4 = local_44;
          _local_44 = (int *******)CONCAT13(0x24,local_44);
          iVar6 = FUN_005d9fa1(param_2,_local_44,local_100[1],local_54[1],local_100[0],0);
          if (((iVar6 < 0) ||
              (iVar6 = FUN_005d9fa1(param_2,_local_44,local_f8[0],local_54[2],local_100[0],0),
              iVar6 < 0)) ||
             (iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x12000000,local_f8[1],local_100[1],0,0),
             iVar6 < 0)) goto LAB_005e1de6;
          local_8 = (int *******)CONCAT13(0x25,uVar4);
          iVar6 = FUN_005d9fa1(param_2,local_8,local_f8[2],local_f8[0],local_f8[1],0);
          if (((iVar6 < 0) ||
              (iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x21000000,local_ec[0],local_f8[2],local_d8,4),
              iVar6 < 0)) ||
             ((iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x20000000,local_ec[1],local_ec[0],local_d4,
                                    0x14), iVar6 < 0 ||
              (((iVar6 = FUN_005d9fa1(param_2,local_8,local_ec[2],local_ec[1],local_d0,8), iVar6 < 0
                || (iVar6 = FUN_005d9fa1(param_2,_local_44,local_e0,local_ec[2],local_cc,0),
                   iVar6 < 0)) ||
               (iVar6 = FUN_005d9fa1(param_2,local_8,local_dc,local_ec[1],local_ec[1],0x14),
               iVar6 < 0)))))) goto LAB_005e1de6;
          uVar20 = (ulonglong)local_dc;
          pppppppiVar17 = local_8;
          pppppppiVar11 = param_3;
          pppppppiVar14 = local_e0;
          goto LAB_005e151b;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x40:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        iVar6 = FUN_005d91c9(param_3,local_8);
        pppppppiVar14 = local_54[0];
joined_r0x005e1120:
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = 0x400000000;
        pppppppiVar17 = (int *******)((uint)local_8 & 0xffffff | 0x16000000);
        pppppppiVar11 = param_3;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x41:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        pppppppiVar17 = (int *******)((uint)local_8 & 0xffffff);
        pppppppiVar14 = local_54[1];
        pppppppiVar11 = local_54[0];
LAB_005e1186:
        uVar20 = CONCAT44(0x2000017,pppppppiVar11);
        pppppppiVar17 = (int *******)((uint)pppppppiVar17 | 0x23000000);
        pppppppiVar11 = param_3;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x42:
    if ((int *******)local_20 != (int *******)0x0) {
      pppppppiVar11 = _malloc((int)local_8 * 0xc);
      local_c = pppppppiVar11;
      if (pppppppiVar11 != (int *******)0x0) {
        uVar18 = 0;
        do {
          (&local_60)[uVar18] = pppppppiVar11;
          uVar18 = uVar18 + 1;
          pppppppiVar11 = pppppppiVar11 + (int)local_8;
        } while (uVar18 < 3);
        iVar6 = FUN_005d91c9(local_60,local_8);
        if ((((iVar6 < 0) || (iVar6 = FUN_005d91c9(local_5c,local_8), iVar6 < 0)) ||
            (iVar6 = FUN_005d91c9(local_58,local_8), iVar6 < 0)) ||
           ((iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0 ||
            (iVar6 = FUN_005da7de(param_2,local_54[0],local_60,local_5c,local_8), iVar6 < 0))))
        goto LAB_005e1de6;
        uVar18 = (uint)local_8 & 0xffffff;
        iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x12000000,local_58,local_5c,0,0);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_58);
        pppppppiVar14 = local_60;
LAB_005e127e:
        pppppppiVar17 = (int *******)(uVar18 | 0x25000000);
        pppppppiVar11 = param_3;
        goto LAB_005e151b;
      }
      goto LAB_005e12dc;
    }
    break;
  case 0x43:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        fVar3 = (float10)log2((float10)2.0);
        ppppppiVar10 = (int ******)
                       FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,
                                    (double)((float10)1.0 / ((float10)0.6931471805599453 * fVar3)));
        pppppppiVar11 = _malloc((int)local_8 * 0x24);
        local_c = pppppppiVar11;
        if (pppppppiVar11 != (int *******)0x0) {
          uVar18 = 0;
          do {
            (&local_34)[uVar18] = (int *)pppppppiVar11;
            uVar18 = uVar18 + 1;
            pppppppiVar11 = pppppppiVar11 + (int)local_8;
          } while (uVar18 < 9);
          pppppppiVar11 = local_8;
          pppppppiVar14 = (int *******)local_14;
          if (local_8 != (int *******)0x0) {
            for (; pppppppiVar11 != (int *******)0x0;
                pppppppiVar11 = (int *******)((int)pppppppiVar11 + -1)) {
              *pppppppiVar14 = ppppppiVar10;
              pppppppiVar14 = pppppppiVar14 + 1;
            }
          }
          iVar6 = FUN_005d91c9(local_34,local_8);
          if (((((iVar6 < 0) || (iVar6 = FUN_005d91c9(local_30,local_8), iVar6 < 0)) ||
               ((iVar6 = FUN_005d91c9(local_2c[0],local_8), iVar6 < 0 ||
                ((iVar6 = FUN_005d91c9(local_2c[1],local_8), iVar6 < 0 ||
                 (iVar6 = FUN_005d91c9(local_24,local_8), iVar6 < 0)))))) ||
              (iVar6 = FUN_005d91c9(local_20,local_8), iVar6 < 0)) ||
             (((iVar6 = FUN_005d91c9(local_1c,local_8), iVar6 < 0 ||
               (iVar6 = FUN_005d91c9(local_18,local_8), iVar6 < 0)) ||
              (iVar6 = FUN_005d91c9(param_3,local_8), iVar6 < 0)))) goto LAB_005e1de6;
          uVar18 = (uint)local_8 & 0xffffff;
          uVar4 = (undefined3)local_8;
          local_8 = (int *******)CONCAT13(0x25,(undefined3)local_8);
          iVar6 = FUN_005d9fa1(param_2,local_8,local_34,local_54[0],local_14,0);
          if (iVar6 < 0) goto LAB_005e1de6;
          local_3c = (int *******)CONCAT13(0x14,uVar4);
          iVar6 = FUN_005d9fa1(param_2,local_3c,local_30,local_34,0,4);
          if (iVar6 < 0) goto LAB_005e1de6;
          local_10 = (int *******)CONCAT13(0x11,uVar4);
          iVar6 = FUN_005d9fa1(param_2,local_10,local_2c[0],local_34,0,0);
          if (((iVar6 < 0) ||
              (iVar6 = FUN_005d9fa1(param_2,local_3c,local_2c[1],local_2c[0],0,4), iVar6 < 0)) ||
             (iVar6 = FUN_005d9fa1(param_2,local_10,local_24,local_2c[1],0,8), iVar6 < 0))
          goto LAB_005e1de6;
          _local_44 = (int *******)CONCAT13(0x24,uVar4);
          iVar6 = FUN_005d9fa1(param_2,_local_44,local_20,local_30,local_24,0);
          if (((iVar6 < 0) ||
              (iVar6 = FUN_005d9fa1(param_2,_local_44,local_1c,local_30,local_2c[1],4), iVar6 < 0))
             || (iVar6 = FUN_005d9fa1(param_2,uVar18 | 0x12000000,local_18,local_1c,0,4), iVar6 < 0)
             ) goto LAB_005e1de6;
          uVar20 = ZEXT48(local_18);
          pppppppiVar17 = local_8;
          pppppppiVar11 = param_3;
          pppppppiVar14 = (int *******)local_20;
          goto LAB_005e151b;
        }
        goto LAB_005e12dc;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x44:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        uVar18 = 0;
        do {
          (&local_20)[uVar18] = *local_54[0];
          (&local_18)[uVar18] = (int *******)*local_54[1];
          uVar18 = uVar18 + 1;
        } while (uVar18 < 2);
        local_58 = (int *******)*local_54[1];
        FUN_005dc68d(0,&local_58,1);
        iVar15 = *(int *)(param_1 + 8);
        ppppppiVar10 = (*(int ********)(iVar15 + 0x14))[(int)local_18];
        if (((*(byte *)(*(int *)(*(int *)(iVar15 + 0x10) + (int)*ppppppiVar10 * 4) + 4) & 8) != 0)
           && (ppppppiVar10[3] == (int *****)0x0)) {
          local_40 = (int *******)0x0;
          pppppppiVar11 = *(int ********)(iVar15 + 0x14);
          if (*(int *)(iVar15 + 8) != 0) {
            do {
              local_38 = pppppppiVar11;
              ppppppiVar13 = *local_38;
              if ((((*ppppppiVar10 == *ppppppiVar13) && (ppppppiVar10[1] == ppppppiVar13[1])) &&
                  (ppppppiVar10[2] == ppppppiVar13[2])) && (ppppppiVar13[3] == (int *****)0x1)) {
                local_14 = (int **)local_40;
                break;
              }
              local_40 = (int *******)((int)local_40 + 1);
              local_38 = local_38 + 1;
              pppppppiVar11 = local_38;
            } while (local_40 < *(int ********)(*(int *)(param_1 + 8) + 8));
          }
          if (local_40 == *(int ********)(iVar15 + 8)) {
            FUN_005d9e57(param_1,param_2,0xdb5);
          }
        }
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(&local_18);
        pppppppiVar17 = (int *******)0x40000002;
        pppppppiVar11 = param_3;
        pppppppiVar14 = &local_20;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x45:
    if (((((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) &&
        (local_18 != (int *******)0x0)) && ((int *******)local_14 != (int *******)0x0)) {
      uVar18 = 0;
      if (param_3 != (int *******)0x0) {
        do {
          (&local_30)[uVar18] = (int *******)*local_54[0];
          local_2c[uVar18 + 1] = *local_54[1];
          (&local_20)[uVar18] = *local_54[2];
          uVar12 = uVar18 + 1;
          (&local_18)[uVar18] = (int *******)*local_54[3];
          uVar18 = uVar12;
        } while (uVar12 < 2);
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_2c + 1);
        pppppppiVar17 = (int *******)0x41000002;
        pppppppiVar11 = param_3;
        pppppppiVar14 = (int *******)&local_30;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x46:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      uVar18 = 0;
      if (param_3 != (int *******)0x0) {
        do {
          (&local_20)[uVar18] = *local_54[0];
          uVar18 = uVar18 + 1;
        } while (uVar18 < 4);
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_54[1]);
        pppppppiVar17 = (int *******)0x42000004;
        pppppppiVar11 = param_3;
        pppppppiVar14 = &local_20;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x47:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      uVar18 = 0;
      if (param_3 != (int *******)0x0) {
        do {
          (&local_20)[uVar18] = *local_54[0];
          uVar18 = uVar18 + 1;
        } while (uVar18 < 4);
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_54[1]);
        pppppppiVar17 = (int *******)0x43000004;
        pppppppiVar11 = param_3;
        pppppppiVar14 = &local_20;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x48:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      uVar18 = 0;
      if (param_3 != (int *******)0x0) {
        do {
          (&local_5c)[uVar18] = *local_54[0];
          uVar18 = uVar18 + 1;
        } while (uVar18 < 2);
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_54[1]);
        pppppppiVar17 = (int *******)0x44000002;
        pppppppiVar11 = param_3;
        pppppppiVar14 = &local_5c;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x49:
    if (((((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) &&
        (local_18 != (int *******)0x0)) && ((int *******)local_14 != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        local_40 = (int *******)((int)local_54[2] - (int)local_54[1]);
        local_74 = (int ******)((int)&local_20 - (int)local_54[1]);
        local_3c = (int *******)((int)local_54[3] - (int)local_54[1]);
        local_70 = (int)&local_18 - (int)local_54[1];
        local_58 = (int *******)0x2;
        pppppppiVar11 = local_54[1];
        do {
          *(int *******)(((int)&local_30 - (int)local_54[1]) + (int)pppppppiVar11) = *local_54[0];
          *(int *******)((int)local_2c + (4U - (int)local_54[1]) + (int)pppppppiVar11) =
               *pppppppiVar11;
          *(undefined4 *)((int)local_74 + (int)pppppppiVar11) =
               *(undefined4 *)((int)local_40 + (int)pppppppiVar11);
          *(undefined4 *)(local_70 + (int)pppppppiVar11) =
               *(undefined4 *)((int)local_3c + (int)pppppppiVar11);
          pppppppiVar11 = pppppppiVar11 + 1;
          local_58 = (int *******)((int)local_58 + -1);
        } while (local_58 != (int *******)0x0);
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_2c + 1);
        pppppppiVar17 = (int *******)0x45000002;
        pppppppiVar11 = param_3;
        pppppppiVar14 = (int *******)&local_30;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x4a:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      uVar18 = 0;
      if (param_3 != (int *******)0x0) {
        do {
          (&local_20)[uVar18] = *local_54[0];
          uVar18 = uVar18 + 1;
        } while (uVar18 < 4);
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_54[1]);
        pppppppiVar17 = (int *******)0x46000004;
        pppppppiVar11 = param_3;
        pppppppiVar14 = &local_20;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x4b:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      uVar18 = 0;
      if (param_3 != (int *******)0x0) {
        do {
          (&local_20)[uVar18] = *local_54[0];
          uVar18 = uVar18 + 1;
        } while (uVar18 < 4);
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_54[1]);
        pppppppiVar17 = (int *******)0x47000004;
        pppppppiVar11 = param_3;
        pppppppiVar14 = &local_20;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x4c:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      uVar18 = 0;
      if (param_3 != (int *******)0x0) {
        do {
          (&local_1c)[uVar18] = (int *******)*local_54[0];
          uVar18 = uVar18 + 1;
        } while (uVar18 < 3);
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_54[1]);
        pppppppiVar17 = (int *******)0x48000003;
        pppppppiVar11 = param_3;
        pppppppiVar14 = (int *******)&local_1c;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x4d:
    if (((((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) &&
        (local_18 != (int *******)0x0)) && ((int *******)local_14 != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        local_40 = (int *******)((int)local_54[2] - (int)local_54[1]);
        local_74 = (int ******)((int)&local_e0 - (int)local_54[1]);
        local_3c = (int *******)((int)local_54[3] - (int)local_54[1]);
        iVar15 = 8 - (int)local_54[1];
        iVar6 = 0x14 - (int)local_54[1];
        local_70 = (int)&local_d4 - (int)local_54[1];
        local_58 = (int *******)0x3;
        pppppppiVar11 = local_54[1];
        do {
          ppppppiVar10 = local_74;
          *(int *******)((int)local_100 + iVar15 + (int)pppppppiVar11) = *local_54[0];
          *(int *******)((int)local_100 + iVar6 + (int)pppppppiVar11) = *pppppppiVar11;
          *(undefined4 *)((int)ppppppiVar10 + (int)pppppppiVar11) =
               *(undefined4 *)((int)pppppppiVar11 + (int)local_40);
          *(undefined4 *)(local_70 + (int)pppppppiVar11) =
               *(undefined4 *)((int)pppppppiVar11 + (int)local_3c);
          pppppppiVar11 = pppppppiVar11 + 1;
          local_58 = (int *******)((int)local_58 + -1);
        } while (local_58 != (int *******)0x0);
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_100 + 5);
        pppppppiVar17 = (int *******)0x49000003;
        pppppppiVar11 = param_3;
        pppppppiVar14 = (int *******)(local_100 + 2);
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x4e:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      uVar18 = 0;
      if (param_3 != (int *******)0x0) {
        do {
          (&local_20)[uVar18] = *local_54[0];
          uVar18 = uVar18 + 1;
        } while (uVar18 < 4);
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_54[1]);
        pppppppiVar17 = (int *******)0x4a000004;
        pppppppiVar11 = param_3;
        pppppppiVar14 = &local_20;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x4f:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      uVar18 = 0;
      if (param_3 != (int *******)0x0) {
        do {
          (&local_20)[uVar18] = *local_54[0];
          uVar18 = uVar18 + 1;
        } while (uVar18 < 4);
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_54[1]);
        pppppppiVar17 = (int *******)0x4b000004;
        pppppppiVar11 = param_3;
        pppppppiVar14 = &local_20;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x50:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      uVar18 = 0;
      if (param_3 != (int *******)0x0) {
        do {
          (&local_1c)[uVar18] = (int *******)*local_54[0];
          uVar18 = uVar18 + 1;
        } while (uVar18 < 3);
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_54[1]);
        pppppppiVar17 = (int *******)0x4c000003;
        pppppppiVar11 = param_3;
        pppppppiVar14 = (int *******)&local_1c;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x51:
    if (((((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) &&
        (local_18 != (int *******)0x0)) && ((int *******)local_14 != (int *******)0x0)) {
      if (param_3 != (int *******)0x0) {
        local_40 = (int *******)((int)local_54[2] - (int)local_54[1]);
        local_74 = (int ******)((int)&local_e0 - (int)local_54[1]);
        local_3c = (int *******)((int)local_54[3] - (int)local_54[1]);
        iVar15 = 8 - (int)local_54[1];
        iVar6 = 0x14 - (int)local_54[1];
        local_70 = (int)&local_d4 - (int)local_54[1];
        local_58 = (int *******)0x3;
        pppppppiVar11 = local_54[1];
        do {
          ppppppiVar10 = local_74;
          *(int *******)((int)pppppppiVar11 + (int)local_100 + iVar15) = *local_54[0];
          *(int *******)((int)pppppppiVar11 + (int)local_100 + iVar6) = *pppppppiVar11;
          *(undefined4 *)((int)pppppppiVar11 + (int)ppppppiVar10) =
               *(undefined4 *)((int)pppppppiVar11 + (int)local_40);
          *(undefined4 *)((int)pppppppiVar11 + local_70) =
               *(undefined4 *)((int)pppppppiVar11 + (int)local_3c);
          pppppppiVar11 = pppppppiVar11 + 1;
          local_58 = (int *******)((int)local_58 + -1);
        } while (local_58 != (int *******)0x0);
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_100 + 5);
        pppppppiVar17 = (int *******)0x4d000003;
        pppppppiVar11 = param_3;
        pppppppiVar14 = (int *******)(local_100 + 2);
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x52:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      uVar18 = 0;
      if (param_3 != (int *******)0x0) {
        do {
          (&local_20)[uVar18] = *local_54[0];
          uVar18 = uVar18 + 1;
        } while (uVar18 < 4);
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_54[1]);
        pppppppiVar17 = (int *******)0x4e000004;
        pppppppiVar11 = param_3;
        pppppppiVar14 = &local_20;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x53:
    if (((int *******)local_20 != (int *******)0x0) && (local_1c != (int *******)0x0)) {
      uVar18 = 0;
      if (param_3 != (int *******)0x0) {
        do {
          (&local_20)[uVar18] = *local_54[0];
          uVar18 = uVar18 + 1;
        } while (uVar18 < 4);
        iVar6 = FUN_005d91c9(param_3,local_8);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = ZEXT48(local_54[1]);
        pppppppiVar17 = (int *******)0x4f000004;
        pppppppiVar11 = param_3;
        pppppppiVar14 = &local_20;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x54:
    if ((int *******)local_20 != (int *******)0x0) {
      if ((param_3 != (int *******)0x0) &&
         (local_40 = (int *******)0x0, (int ******)local_20[6] != (int ******)0x0)) {
        ppppppiVar10 = (int ******)local_20[5];
        do {
          ppppppiVar13 = (int ******)0x0;
          if (ppppppiVar10 != (int ******)0x0) {
            do {
              param_3[(int)(*(int *)((int)param_2 + 0x18) * (int)local_40 + (int)ppppppiVar13)] =
                   local_54[0][(int)((int)local_20[6] * (int)ppppppiVar13 + (int)local_40)];
              ppppppiVar10 = (int ******)local_20[5];
              ppppppiVar13 = (int ******)((int)ppppppiVar13 + 1);
            } while (ppppppiVar13 < ppppppiVar10);
          }
          local_40 = (int *******)((int)local_40 + 1);
        } while (local_40 < local_20[6]);
      }
      goto LAB_005dd6a0;
    }
    break;
  case 0x55:
    if ((int *******)local_20 != (int *******)0x0) {
      if (param_3 != (int *******)0x0) {
        local_20 = (int ******)
                   FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,0x406fe01000000000
                               );
        local_bc = local_54[0][2];
        local_b8 = (int *)local_54[0][1];
        local_b4 = *local_54[0];
        local_b0 = local_54[0][3];
        local_1c = (int *******)local_20;
        local_18 = (int *******)local_20;
        local_14 = (int **)local_20;
        iVar6 = FUN_005d91c9(param_3,4);
        if (iVar6 < 0) goto LAB_005e1de6;
        uVar20 = CONCAT44(6,&local_20);
        pppppppiVar17 = (int *******)0x25000004;
        pppppppiVar11 = param_3;
        pppppppiVar14 = &local_bc;
        goto LAB_005e151b;
      }
      goto LAB_005dd6a0;
    }
    break;
  default:
    FUN_005d9de1(param_1,param_2,0xdac,"intrinsic function \'%s\' is not yet implemented");
  }
  iVar6 = -0x7fffbffb;
LAB_005e1de6:
  *(undefined4 *)(param_1 + 0x1c) = local_158;
  uVar18 = 0;
  do {
    _free(local_54[uVar18]);
    uVar18 = uVar18 + 1;
  } while (uVar18 < 4);
  _free(local_c);
  return iVar6;
}


