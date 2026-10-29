// ==== 0x5e1f75 FUN_005e1f75

int __thiscall
FUN_005e1f75(int param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 *param_5,
            int param_6,int param_7)

{
  char *pcVar1;
  void *pvVar2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  char *pcVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  int iVar14;
  int local_30;
  undefined4 *local_2c;
  undefined4 *local_28;
  void *local_24;
  void *local_20;
  uint local_1c;
  int *local_18;
  int local_14;
  uint local_c;
  uint local_8;
  
  local_20 = (void *)0x0;
  local_24 = (void *)0x0;
  local_28 = (undefined4 *)0x0;
  local_18 = (int *)0x0;
  local_c = 0;
  if ((param_3 == 0) || (*(int *)(param_3 + 4) != 9)) {
    return -0x7fffbffb;
  }
  if (*(int *)(param_3 + 0x38) != 0) {
    FUN_005d9de1(param_1,param_3,0xdac,"\'%s\': recursive functions not yet implemented",param_2);
    return -0x7fffbfff;
  }
  if ((param_6 != 0) && (local_8 = FUN_005f7f90(), (int)local_8 < 0)) goto LAB_005e26ba;
  if (param_4 == 0) {
    local_1c = 0;
    local_30 = 0;
  }
  else {
    local_1c = *(int *)(param_4 + 8);
    local_30 = *(int *)(param_4 + 0xc);
  }
  iVar8 = *(int *)(param_3 + 0x24);
  iVar11 = 0;
  while (iVar8 != 0) {
    piVar9 = (int *)(iVar8 + 8);
    iVar8 = *(int *)(iVar8 + 0xc);
    if (((iVar8 != 0) && (*(int *)(iVar8 + 8) != 0)) && (*(int *)(*(int *)(iVar8 + 8) + 4) == 0xb))
    {
      iVar8 = *(int *)(iVar8 + 0xc);
    }
    iVar11 = iVar11 + *(int *)(*(int *)(*piVar9 + 0x18) + 0x14);
  }
  local_20 = _malloc(iVar11 << 2);
  if ((local_20 == (void *)0x0) ||
     ((param_6 != 0 && (local_18 = _malloc(iVar11 << 2), local_18 == (int *)0x0)))) {
LAB_005e2926:
    local_8 = -0x7ff8fff2;
    goto LAB_005e26ba;
  }
  iVar8 = *(int *)(param_3 + 0x24);
  param_4 = local_1c;
  while (iVar8 != 0) {
    piVar9 = (int *)(iVar8 + 8);
    iVar8 = *(int *)(iVar8 + 0xc);
    if (((iVar8 != 0) && (*(int *)(iVar8 + 8) != 0)) && (*(int *)(*(int *)(iVar8 + 8) + 4) == 0xb))
    {
      iVar8 = *(int *)(iVar8 + 0xc);
    }
    if (((param_6 == 0) ||
        ((param_7 != 0 && ((*(byte *)(*(int *)(*piVar9 + 0x18) + 0x1c) & 0x40) != 0)))) &&
       (param_4 != 0)) {
      if ((*(int *)(param_4 + 8) != 0) &&
         (local_8 = FUN_005e2a38(*(int *)(param_4 + 8)), (int)local_8 < 0)) goto LAB_005e26ba;
      param_4 = *(int *)(param_4 + 0xc);
    }
  }
  uVar12 = *(int *)(param_3 + 0x24);
  pvVar2 = local_20;
  param_4 = local_1c;
  while (uVar12 != 0) {
    iVar8 = *(int *)(uVar12 + 8);
    local_1c = *(int *)(uVar12 + 0xc);
    if (((local_1c != 0) && (*(int *)(local_1c + 8) != 0)) &&
       (*(int *)(*(int *)(local_1c + 8) + 4) == 0xb)) {
      local_1c = *(int *)(local_1c + 0xc);
    }
    iVar11 = *(int *)(iVar8 + 0x18);
    if ((param_6 == 0) || ((param_7 != 0 && ((*(byte *)(iVar11 + 0x1c) & 0x40) != 0)))) {
      local_8 = FUN_005dc760();
      if ((int)local_8 < 0) goto LAB_005e26ba;
      if (param_4 == 0) {
        local_8 = FUN_005dc760();
        goto LAB_005e232b;
      }
      if (((*(byte *)(iVar11 + 0x1c) & 0x10) != 0) &&
         (local_8 = FUN_005d9fa1(*(undefined4 *)(param_4 + 8),
                                 *(uint *)(iVar11 + 0x14) & 0xffffff | 0x10000000,
                                 *(int *)(param_1 + 0x18) + *(int *)(iVar11 + 0x10) * 4,pvVar2,0,0),
         (int)local_8 < 0)) goto LAB_005e26ba;
      param_4 = *(int *)(param_4 + 0xc);
    }
    else {
      iVar7 = *(int *)(param_1 + 8);
      local_14 = *(int *)(iVar7 + 0x4c);
      if ((*(uint *)(iVar11 + 0x1c) & 0x40) == 0) {
        if ((*(uint *)(iVar11 + 0x1c) & 0x10) != 0) {
          local_14 = *(int *)(iVar7 + 0x58);
        }
      }
      else {
        local_14 = *(int *)(iVar7 + 0x54);
      }
      local_8 = 0;
      if (*(int *)(iVar11 + 0x14) != 0) {
        do {
          iVar14 = *(int *)(iVar11 + 0x10) + local_8;
          uVar6 = FUN_005f74cf(local_14,0,0,0);
          iVar7 = FUN_005f762c();
          if (iVar7 != 0) {
            *(int *)(iVar7 + 0x44) = iVar8;
            *(int *)(iVar7 + 0x1c) = iVar14;
            *(uint *)(iVar7 + 0x48) = local_8;
          }
          local_8 = local_8 + 1;
          *(undefined4 *)(*(int *)(param_1 + 0x18) + iVar14 * 4) = uVar6;
        } while (local_8 < *(uint *)(iVar11 + 0x14));
      }
      if ((*(int *)(*(int *)(param_1 + 8) + 0x4c) != local_14) &&
         (local_8 = FUN_005dbe7e(*(undefined4 *)(iVar11 + 0x20),
                                 *(int *)(param_1 + 0x18) + *(int *)(iVar11 + 0x10) * 4,
                                 *(undefined4 *)(iVar11 + 0x14)), (int)local_8 < 0))
      goto LAB_005e26ba;
      if (*(int *)(*(int *)(param_1 + 8) + 0x54) == local_14) {
        local_8 = FUN_005dc613(*(undefined4 *)(iVar11 + 0x20),
                               *(int *)(param_1 + 0x18) + *(int *)(iVar11 + 0x10) * 4,local_14,1,0,0
                               ,*(undefined4 *)(iVar11 + 0x30));
        if ((int)local_8 < 0) goto LAB_005e26ba;
        local_8 = FUN_005d932c();
LAB_005e232b:
        if ((int)local_8 < 0) goto LAB_005e26ba;
      }
      else if (*(int *)(*(int *)(param_1 + 8) + 0x58) == local_14) {
        local_8 = FUN_005dc613(*(undefined4 *)(iVar11 + 0x20),
                               *(int *)(param_1 + 0x18) + *(int *)(iVar11 + 0x10) * 4,local_14,0,0,
                               *(undefined4 *)(iVar11 + 0x2c),*(undefined4 *)(iVar11 + 0x30));
        if ((int)local_8 < 0) goto LAB_005e26ba;
        iVar8 = FUN_005d99a5(*(int *)(param_1 + 0x18) + *(int *)(iVar11 + 0x10) * 4,
                             *(undefined4 *)(iVar11 + 0x14));
        if (iVar8 == 0) {
          FUN_005d9de1(param_1,iVar11,0xdae,"\'%s\': input parameter \'%s\' missing semantics");
        }
        else {
          uVar12 = 0;
          if (*(int *)(iVar11 + 0x14) != 0) {
            do {
              iVar8 = *(int *)(iVar11 + 0x10) + uVar12;
              uVar3 = local_c + 1;
              uVar12 = uVar12 + 1;
              local_18[local_c] = iVar8;
              local_c = uVar3;
            } while (uVar12 < *(uint *)(iVar11 + 0x14));
          }
        }
      }
    }
    pvVar2 = (void *)((int)pvVar2 + *(int *)(iVar11 + 0x14) * 4);
    uVar12 = local_1c;
  }
  if (param_6 == 0) {
LAB_005e251e:
    piVar9 = (int *)(param_1 + 0x38);
    iVar8 = *piVar9;
    *piVar9 = 0;
    *(undefined4 *)(param_3 + 0x38) = 1;
    local_8 = FUN_005dc760();
    iVar11 = *piVar9;
    *piVar9 = iVar8;
    *(undefined4 *)(param_3 + 0x38) = 0;
    if ((int)local_8 < 0) goto LAB_005e26ba;
    if ((iVar11 != 0) || (*(int *)(param_3 + 0x14) == 0)) {
      if (param_6 == 0) {
        if (param_5 != (undefined4 *)0x0) {
          puVar13 = (undefined4 *)(*(int *)(param_1 + 0x18) + *(int *)(param_3 + 0x10) * 4);
          for (uVar12 = *(uint *)(param_3 + 0x14) & 0x3fffffff; uVar12 != 0; uVar12 = uVar12 - 1) {
            *param_5 = *puVar13;
            puVar13 = puVar13 + 1;
            param_5 = param_5 + 1;
          }
          for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
            *(undefined1 *)param_5 = *(undefined1 *)puVar13;
            puVar13 = (undefined4 *)((int)puVar13 + 1);
            param_5 = (undefined4 *)((int)param_5 + 1);
          }
        }
      }
      else if (*(uint *)(param_3 + 0x14) != 0) {
        iVar8 = *(int *)(param_1 + 0x18) + *(int *)(param_3 + 0x10) * 4;
        local_8 = FUN_005d9fa1(param_3,*(uint *)(param_3 + 0x14) & 0xffffff | 0x10000000,iVar8,iVar8
                               ,0,0);
        if ((((int)local_8 < 0) ||
            (local_8 = FUN_005dbe7e(*(undefined4 *)(param_3 + 0x20),
                                    *(int *)(param_1 + 0x18) + *(int *)(param_3 + 0x10) * 4,
                                    *(undefined4 *)(param_3 + 0x14)), (int)local_8 < 0)) ||
           (local_8 = FUN_005dc613(*(undefined4 *)(param_3 + 0x20),
                                   *(int *)(param_1 + 0x18) + *(int *)(param_3 + 0x10) * 4,
                                   *(undefined4 *)(*(int *)(param_1 + 8) + 0x5c),0,1,
                                   *(undefined4 *)(param_3 + 0x30),0), (int)local_8 < 0))
        goto LAB_005e26ba;
        iVar8 = FUN_005d99a5(*(int *)(param_1 + 0x18) + *(int *)(param_3 + 0x10) * 4,
                             *(undefined4 *)(param_3 + 0x14));
        if (iVar8 == 0) {
          FUN_005d9de1(param_1,param_3,0xdaf,"\'%s\': function return value missing semantics");
        }
        else {
          uVar12 = 0;
          if (*(int *)(param_3 + 0x14) != 0) {
            do {
              uVar6 = FUN_005f762c();
              iVar8 = (**(code **)(**(int **)(param_1 + 8) + 8))(uVar6);
              if (iVar8 < 0) {
                *(undefined4 *)(param_1 + 0x34) = 1;
              }
              uVar12 = uVar12 + 1;
            } while (uVar12 < *(uint *)(param_3 + 0x14));
          }
        }
      }
      local_1c = *(int *)(param_3 + 0x24);
joined_r0x005e26b4:
      if (local_1c == 0) {
        local_8 = 0;
      }
      else {
        iVar8 = *(int *)(local_1c + 8);
        local_1c = *(int *)(local_1c + 0xc);
        if (((local_1c != 0) && (*(int *)(local_1c + 8) != 0)) &&
           (*(int *)(*(int *)(local_1c + 8) + 4) == 0xb)) {
          local_1c = *(int *)(local_1c + 0xc);
        }
        iVar11 = *(int *)(iVar8 + 0x18);
        if ((*(byte *)(iVar11 + 0x1c) & 0x20) == 0) goto LAB_005e287b;
        param_3 = 0;
        if (*(int *)(iVar11 + 0x14) != 0) {
          do {
            piVar9 = (int *)FUN_005f762c();
            if ((piVar9 != (int *)0x0) && (*(int *)(*(int *)(param_1 + 8) + 0x4c) == *piVar9)) {
              FUN_005d9de1(param_1,piVar9[0x11],0xdb4,
                           "\'%s\': output parameter \'%s\' never assigned a value",param_2);
              goto LAB_005e26ba;
            }
            param_3 = param_3 + 1;
          } while (param_3 < *(uint *)(iVar11 + 0x14));
        }
        if (param_6 == 0) goto LAB_005e2852;
        iVar7 = *(int *)(param_1 + 0x18) + *(int *)(iVar11 + 0x10) * 4;
        local_8 = FUN_005d9fa1(iVar11,*(uint *)(iVar11 + 0x14) & 0xffffff | 0x10000000,iVar7,iVar7,0
                               ,0);
        if (((-1 < (int)local_8) &&
            (local_8 = FUN_005dbe7e(*(undefined4 *)(iVar11 + 0x20),
                                    *(int *)(param_1 + 0x18) + *(int *)(iVar11 + 0x10) * 4,
                                    *(undefined4 *)(iVar11 + 0x14)), -1 < (int)local_8)) &&
           (local_8 = FUN_005dc613(*(undefined4 *)(iVar11 + 0x20),
                                   *(int *)(param_1 + 0x18) + *(int *)(iVar11 + 0x10) * 4,
                                   *(undefined4 *)(*(int *)(param_1 + 8) + 0x5c),0,1,
                                   *(undefined4 *)(iVar11 + 0x2c),0), -1 < (int)local_8)) {
          iVar7 = FUN_005d99a5(*(int *)(param_1 + 0x18) + *(int *)(iVar11 + 0x10) * 4,
                               *(undefined4 *)(iVar11 + 0x14));
          if (iVar7 == 0) {
            FUN_005d9de1(param_1,iVar11,0xdaf,"\'%s\': output parameter \'%s\' missing semantics");
          }
          else {
            uVar12 = 0;
            if (*(int *)(iVar11 + 0x14) != 0) {
              do {
                FUN_005f762c();
                iVar7 = (**(code **)(**(int **)(param_1 + 8) + 8))();
                if (iVar7 < 0) {
                  *(undefined4 *)(param_1 + 0x34) = 1;
                }
                uVar12 = uVar12 + 1;
              } while (uVar12 < *(uint *)(iVar11 + 0x14));
            }
          }
          goto LAB_005e287b;
        }
      }
      goto LAB_005e26ba;
    }
    FUN_005d9de1(param_1,param_3,0xdb3,"\'%s\': function must return a value");
  }
  else {
    bVar5 = false;
    param_4 = 0;
    if (local_c == 0) {
LAB_005e23a8:
      FUN_005f7e20(FUN_005d9eb5,local_18,local_c,param_1);
      param_4 = 0;
      if (local_c != 0) {
        local_14 = FUN_005f762c();
        local_1c = 1;
        if (1 < local_c) {
          do {
            iVar8 = FUN_005f762c();
            if ((*(int *)(local_14 + 0x50) == *(int *)(iVar8 + 0x50)) &&
               (*(int *)(local_14 + 0xc) == *(int *)(iVar8 + 0xc))) {
              param_4 = param_4 + 1;
              iVar8 = local_14;
            }
            local_14 = iVar8;
            local_1c = local_1c + 1;
          } while (local_1c < local_c);
          if (param_4 != 0) {
            local_24 = _malloc(param_4 << 2);
            if ((local_24 == (void *)0x0) ||
               (local_28 = _malloc(param_4 << 2), local_28 == (undefined4 *)0x0)) goto LAB_005e2926;
            iVar8 = *local_18;
            param_4 = 0;
            local_14 = FUN_005f762c();
            local_1c = 1;
            local_2c = local_28;
            do {
              iVar11 = local_18[local_1c];
              iVar7 = FUN_005f762c();
              if ((*(int *)(local_14 + 0x50) == *(int *)(iVar7 + 0x50)) &&
                 (*(int *)(local_14 + 0xc) == *(int *)(iVar7 + 0xc))) {
                param_4 = param_4 + 1;
                *(undefined4 *)(((int)local_24 - (int)local_28) + (int)local_2c) =
                     *(undefined4 *)(iVar11 * 4 + *(int *)(param_1 + 0x18));
                *local_2c = *(undefined4 *)(*(int *)(param_1 + 0x18) + iVar8 * 4);
                local_2c = local_2c + 1;
                iVar11 = iVar8;
                iVar7 = local_14;
              }
              local_14 = iVar7;
              local_1c = local_1c + 1;
              iVar8 = iVar11;
            } while (local_1c < local_c);
            local_8 = FUN_005d9fa1(param_3,param_4 & 0xffffff | 0x10000000,local_24,local_28,0,0);
            if ((int)local_8 < 0) goto LAB_005e26ba;
          }
        }
      }
      goto LAB_005e251e;
    }
    do {
      uVar6 = FUN_005f762c();
      iVar8 = (**(code **)(**(int **)(param_1 + 8) + 8))(uVar6);
      if (iVar8 < 0) {
        bVar5 = true;
      }
      param_4 = param_4 + 1;
    } while (param_4 < local_c);
    if (!bVar5) goto LAB_005e23a8;
  }
  local_8 = -0x7fffbffb;
LAB_005e26ba:
  _free(local_20);
  _free(local_18);
  _free(local_24);
  _free(local_28);
  return local_8;
LAB_005e2852:
  if (local_30 != 0) {
    if (*(int *)(local_30 + 8) != 0) {
      local_8 = FUN_005e2a38(*(int *)(local_30 + 8));
      if ((int)local_8 < 0) goto LAB_005e26ba;
LAB_005e287b:
      if ((param_6 != 0) && ((param_7 == 0 || ((*(byte *)(iVar11 + 0x1c) & 0x40) == 0)))) {
        if ((*(byte *)(iVar11 + 0x1c) & 0x40) != 0) {
          pcVar10 = *(char **)(*(int *)(iVar8 + 0x14) + 0x18);
          pcVar1 = pcVar10 + 1;
          do {
            cVar4 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar4 != '\0');
          iVar11 = FUN_005b1775();
          if (iVar11 == 0) goto LAB_005e2926;
          _snprintf(iVar11,pcVar10 + (2 - (int)pcVar1));
          *(int *)(*(int *)(iVar8 + 0x14) + 0x18) = iVar11;
        }
        goto joined_r0x005e26b4;
      }
    }
    if (local_30 != 0) {
      local_30 = *(int *)(local_30 + 0xc);
    }
  }
  goto joined_r0x005e26b4;
}


// ==== 0x5e293e FUN_005e293e

uint __fastcall FUN_005e293e(int *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = param_1[1];
  if ((iVar3 == 0) || (*(int *)(iVar3 + 4) != 3)) {
    uVar1 = 0;
  }
  else if (param_1[2] == 0) {
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = FUN_005fbfb9(iVar3,*param_1 + 4,param_1[4],param_1[5]);
    if (-1 < (int)uVar1) {
      _free((void *)param_1[6]);
      puVar2 = _malloc(*(int *)(iVar3 + 0x18) << 2);
      param_1[6] = (int)puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        uVar1 = 0x8007000e;
      }
      else {
        for (uVar1 = *(uint *)(iVar3 + 0x18) & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar2 = 0xffffffff;
          puVar2 = puVar2 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(undefined1 *)puVar2 = 0xff;
          puVar2 = (undefined4 *)((int)puVar2 + 1);
        }
        iVar3 = FUN_005f74cf(*(undefined4 *)(param_1[2] + 0x50),0,0,0x3ff0000000000000);
        param_1[8] = iVar3;
        iVar3 = FUN_005f74cf(*(undefined4 *)(param_1[2] + 0x50),0,0,0);
        param_1[9] = iVar3;
        iVar3 = FUN_005f74cf(*(undefined4 *)(param_1[2] + 0x50),0,0,0xbff0000000000000);
        param_1[10] = iVar3;
        param_1[0xb] = param_1[8];
        uVar1 = FUN_005dc760();
        if (-1 < (int)uVar1) {
          uVar1 = -(uint)(param_1[0xd] != 0) & 0x80004005;
        }
      }
    }
  }
  return uVar1;
}


// ==== 0x5e2a38 FUN_005e2a38

/* WARNING: Type propagation algorithm not settling */

int __thiscall FUN_005e2a38(int param_1,uint *param_2,uint *param_3)

{
  byte *pbVar1;
  double dVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  size_t _Size;
  int iVar15;
  bool bVar16;
  undefined8 uVar17;
  ulonglong uVar18;
  longlong lVar19;
  char *pcVar20;
  uint *local_a4;
  uint *local_a0;
  undefined4 local_9c;
  uint uStack_98;
  uint local_94;
  uint *local_90;
  uint *local_8c;
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  uint local_7c;
  uint *local_78;
  int local_74;
  uint *local_70 [10];
  uint local_48 [2];
  uint *local_40;
  uint *local_3c;
  uint *local_38;
  uint *local_34;
  uint *local_30;
  uint *local_2c;
  uint *local_28;
  uint *local_24;
  uint *local_20;
  uint *local_1c;
  uint *local_18;
  uint *local_14;
  uint *local_10;
  uint *local_c;
  uint *local_8;
  
  if (param_2 == (uint *)0x0) {
    if (param_3 != (uint *)0x0) {
      return -0x7fffbffb;
    }
    return 0;
  }
  if (*(int *)((int)param_2 + 4) != 0xc) {
    return -0x7fffbffb;
  }
  local_8 = (uint *)(*(int *)((int)param_2 + 0x14) * *(int *)((int)param_2 + 0x18));
  puVar12 = *(uint **)((int)param_2 + 0x20);
  local_c = (uint *)0x0;
  local_2c = (uint *)0x0;
  local_14 = (uint *)0x0;
  local_28 = (uint *)0x0;
  local_30 = (uint *)0x0;
  local_10 = (uint *)0x0;
  local_20 = (uint *)0x0;
  local_8c = (uint *)0x0;
  local_90 = (uint *)0x0;
  if ((puVar12 != (uint *)0x0) && (puVar12[1] == 0xc)) {
    local_c = (uint *)(puVar12[6] * puVar12[5]);
    local_10 = puVar12;
  }
  puVar12 = *(uint **)((int)param_2 + 0x24);
  if ((puVar12 != (uint *)0x0) && (puVar12[1] == 0xc)) {
    local_2c = (uint *)(puVar12[6] * puVar12[5]);
    local_20 = puVar12;
  }
  if (((local_10 != (uint *)0x0) && (local_14 = _malloc((int)local_c << 2), local_14 == (uint *)0x0)
      ) || ((local_20 != (uint *)0x0 &&
            (local_28 = _malloc((int)local_2c << 2), local_28 == (uint *)0x0)))) {
LAB_005e4661:
    FUN_005d9de1(param_1,param_2,0);
    iVar3 = -0x7ff8fff2;
    goto LAB_005e4925;
  }
  if (*(int *)((int)param_2 + 0x28) == 0) {
    if ((local_20 != (uint *)0x0) && (iVar3 = FUN_005e2a38(local_20), iVar3 < 0)) goto LAB_005e4925;
    if (local_10 != (uint *)0x0) {
      uVar17 = CONCAT44(local_14,local_10);
LAB_005e2b5e:
      iVar3 = FUN_005e2a38(uVar17);
      if (iVar3 < 0) goto LAB_005e4925;
    }
  }
  else {
    if ((local_10 != (uint *)0x0) && (iVar3 = FUN_005e2a38(local_10), iVar3 < 0)) goto LAB_005e4925;
    if (local_20 != (uint *)0x0) {
      uVar17 = CONCAT44(local_28,local_20);
      goto LAB_005e2b5e;
    }
  }
  puVar12 = local_8;
  puVar5 = param_3;
  switch(*(undefined4 *)((int)param_2 + 0x1c)) {
  case 0:
  case 1:
    if (local_10 == (uint *)0x0) {
      iVar3 = FUN_005e49cf(*(undefined4 *)((int)param_2 + 0x20),param_3,local_8);
      goto LAB_005e2f88;
    }
    if (param_3 != (uint *)0x0) {
      if (local_c == (uint *)0x1) {
        puVar12 = (uint *)0x0;
        if (local_8 != (uint *)0x0) {
          do {
            param_3[(int)puVar12] = *local_14;
            puVar12 = (uint *)((int)puVar12 + 1);
          } while (puVar12 < local_8);
        }
      }
      else {
        puVar9 = local_8;
        puVar12 = local_14;
        if ((local_8 == local_c) ||
           ((uVar10 = *(uint *)((int)param_2 + 0x14), uVar10 == 1 && (local_8 < local_c))))
        goto code_r0x005e41b9;
        if ((local_10[5] < uVar10) || (local_10[6] < *(uint *)((int)param_2 + 0x18))) break;
        uVar13 = 0;
        if (uVar10 != 0) {
          do {
            iVar15 = local_10[6] * uVar13;
            iVar3 = *(int *)((int)param_2 + 0x18);
            iVar8 = iVar3 * uVar13;
            uVar13 = uVar13 + 1;
            puVar12 = local_14 + iVar15;
            puVar5 = param_3 + iVar8;
            for (; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar5 = *puVar12;
              puVar12 = puVar12 + 1;
              puVar5 = puVar5 + 1;
            }
          } while (uVar13 < *(uint *)((int)param_2 + 0x14));
        }
      }
      goto LAB_005e2bc0;
    }
    goto LAB_005e490c;
  case 2:
    if (local_10 != (uint *)0x0) {
      local_c = (uint *)((int)local_8 << 2);
      local_28 = _malloc((size_t)local_c);
      if (local_28 == (uint *)0x0) goto LAB_005e4661;
      puVar5 = (uint *)0x0;
      if (puVar12 != (uint *)0x0) {
        do {
          local_28[(int)puVar5] = *(uint *)(param_1 + 0x20);
          puVar5 = (uint *)((int)puVar5 + 1);
        } while (puVar5 < puVar12);
      }
LAB_005e2dc6:
      iVar3 = FUN_005d9fa1(param_2,(uint)local_8 & 0xffffff | 0x24000000,local_14,local_14,local_28,
                           0);
      if (iVar3 < 0) goto LAB_005e4925;
      if (param_3 != (uint *)0x0) {
        puVar12 = local_14;
        puVar5 = param_3;
        for (uVar10 = (uint)local_c >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *puVar5 = *puVar12;
          puVar12 = puVar12 + 1;
          puVar5 = puVar5 + 1;
        }
        for (uVar10 = (uint)local_c & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
          *(char *)puVar5 = (char)*puVar12;
          puVar12 = (uint *)((int)puVar12 + 1);
          puVar5 = (uint *)((int)puVar5 + 1);
        }
        goto LAB_005e2bc0;
      }
      goto LAB_005e490c;
    }
    break;
  case 3:
    if (local_10 != (uint *)0x0) {
      local_c = (uint *)((int)local_8 << 2);
      local_28 = _malloc((size_t)local_c);
      if (local_28 != (uint *)0x0) {
        puVar5 = (uint *)0x0;
        if (puVar12 != (uint *)0x0) {
          do {
            local_28[(int)puVar5] = *(uint *)(param_1 + 0x28);
            puVar5 = (uint *)((int)puVar5 + 1);
          } while (puVar5 < puVar12);
        }
        goto LAB_005e2dc6;
      }
      goto LAB_005e4661;
    }
    break;
  case 4:
    if (local_10 != (uint *)0x0) {
      if (param_3 == (uint *)0x0) goto LAB_005e490c;
      local_30 = _malloc((int)local_8 * 0xc);
      if (local_30 == (uint *)0x0) goto LAB_005e4661;
      uVar10 = 0;
      puVar5 = local_30;
      do {
        local_70[uVar10] = puVar5;
        uVar10 = uVar10 + 1;
        puVar5 = puVar5 + (int)puVar12;
      } while (uVar10 < 3);
      iVar3 = FUN_005d91c9(local_70[0],local_8);
      if ((((iVar3 < 0) || (iVar3 = FUN_005d91c9(local_70[1],local_8), iVar3 < 0)) ||
          (iVar3 = FUN_005d91c9(local_70[2],local_8), iVar3 < 0)) ||
         (iVar3 = FUN_005d91c9(param_3,local_8), iVar3 < 0)) goto LAB_005e4925;
      local_c = (uint *)((uint)local_8 & 0xffffff);
      local_10 = (uint *)((uint)local_c | 0x11000000);
      iVar3 = FUN_005d9fa1(param_2,local_10,local_70[0],local_14,0,0);
      if ((iVar3 < 0) ||
         (iVar3 = FUN_005d9fa1(param_2,(uint)local_c | 0x21000000,local_70[1],local_14,local_70[0],4
                              ), iVar3 < 0)) goto LAB_005e4925;
      iVar3 = FUN_005d9fa1(param_2,local_10,local_70[2],local_70[1],0,8);
      puVar12 = local_70[2];
      puVar9 = local_c;
joined_r0x005e3326:
      local_c = puVar9;
      if (iVar3 < 0) goto LAB_005e4925;
LAB_005e2f75:
      uVar18 = CONCAT44(0x2000017,local_70[1]);
      puVar9 = (uint *)((uint)puVar9 | 0x23000000);
LAB_005e2f7e:
      iVar3 = FUN_005d9fa1(param_2,puVar9,param_3,puVar12,uVar18);
      goto LAB_005e2f88;
    }
    break;
  case 5:
    if (local_10 != (uint *)0x0) {
      if (param_3 != (uint *)0x0) {
        iVar3 = FUN_005d91c9(param_3,local_8);
        if (iVar3 < 0) goto LAB_005e4925;
        uVar18 = 0;
        puVar9 = (uint *)((uint)local_8 & 0xffffff | 0x11000000);
        puVar12 = local_14;
        goto LAB_005e2f7e;
      }
      goto LAB_005e490c;
    }
    break;
  case 6:
    if (local_10 != (uint *)0x0) {
      if (param_3 != (uint *)0x0) {
        iVar3 = FUN_005d91c9(param_3,local_8);
        puVar12 = local_14;
joined_r0x005e42c1:
        if (iVar3 < 0) goto LAB_005e4925;
        uVar18 = 0;
        puVar9 = (uint *)((uint)local_8 & 0xffffff | 0x10000000);
        goto LAB_005e2f7e;
      }
      goto LAB_005e490c;
    }
    break;
  case 7:
    if ((local_10 != (uint *)0x0) && (local_20 != (uint *)0x0)) {
      if (param_3 != (uint *)0x0) {
        iVar3 = FUN_005d91c9(param_3,local_8);
        if (iVar3 < 0) goto LAB_005e4925;
        puVar9 = (uint *)((uint)local_8 & 0xffffff);
        puVar12 = local_28;
LAB_005e3762:
        uVar18 = ZEXT48(puVar12);
        puVar9 = (uint *)((uint)puVar9 | 0x25000000);
        puVar12 = local_14;
        goto LAB_005e2f7e;
      }
      goto LAB_005e490c;
    }
    break;
  case 8:
    if ((local_10 != (uint *)0x0) && (local_20 != (uint *)0x0)) {
      if (param_3 != (uint *)0x0) {
        local_30 = _malloc((int)local_8 << 2);
        if (local_30 != (uint *)0x0) {
          iVar3 = FUN_005d91c9(local_30,local_8);
          if ((iVar3 < 0) || (iVar3 = FUN_005d91c9(param_3,local_8), iVar3 < 0)) goto LAB_005e4925;
          local_c = (uint *)((uint)local_8 & 0xffffff);
          iVar3 = FUN_005d9fa1(param_2,(uint)local_c | 0x12000000,local_30,local_28,0,0);
          puVar9 = local_c;
          puVar12 = local_30;
          if (iVar3 < 0) goto LAB_005e4925;
          goto LAB_005e3762;
        }
        goto LAB_005e4661;
      }
      goto LAB_005e490c;
    }
    break;
  case 9:
    if ((local_10 != (uint *)0x0) && (local_20 != (uint *)0x0)) {
      if (param_3 != (uint *)0x0) {
        puVar5 = _malloc((int)local_8 * 0xc);
        local_30 = puVar5;
        if (puVar5 != (uint *)0x0) {
          uVar10 = 0;
          do {
            local_70[uVar10] = puVar5;
            uVar10 = uVar10 + 1;
            puVar5 = puVar5 + (int)puVar12;
          } while (uVar10 < 3);
          uVar10 = 0;
          do {
            uVar17 = FUN_005d91c9(local_70[uVar10],local_8);
            iVar3 = (int)uVar17;
            if (iVar3 < 0) goto LAB_005e4925;
            uVar10 = (int)((ulonglong)uVar17 >> 0x20) + 1;
          } while (uVar10 < 3);
          iVar3 = FUN_005d91c9(param_3,local_8);
          if (iVar3 < 0) goto LAB_005e4925;
          local_c = (uint *)((uint)local_8 & 0xffffff);
          iVar3 = FUN_005d9fa1(param_2,(uint)local_c | 0x12000000,local_70[0],local_28,0,0);
          if (iVar3 < 0) goto LAB_005e4925;
          local_1c = (uint *)((uint)local_c | 0x25000000);
          iVar3 = FUN_005d9fa1(param_2,local_1c,local_70[1],local_14,local_70[0],0);
          if ((iVar3 < 0) ||
             (iVar3 = FUN_005d9fa1(param_2,(uint)local_c | 0x13000000,local_70[2],local_70[1],0,4),
             iVar3 < 0)) goto LAB_005e4925;
          uVar18 = ZEXT48(local_70[2]);
          puVar9 = local_1c;
          puVar12 = local_28;
          goto LAB_005e2f7e;
        }
        goto LAB_005e4661;
      }
      goto LAB_005e490c;
    }
    break;
  case 10:
    if ((local_10 != (uint *)0x0) && (local_20 != (uint *)0x0)) {
      if (param_3 != (uint *)0x0) {
        iVar3 = FUN_005d91c9(param_3,local_8);
        if (iVar3 < 0) goto LAB_005e4925;
        puVar9 = (uint *)((uint)local_8 & 0xffffff);
        puVar12 = local_28;
LAB_005e3041:
        uVar18 = ZEXT48(puVar12);
        puVar9 = (uint *)((uint)puVar9 | 0x24000000);
        puVar12 = local_14;
        goto LAB_005e2f7e;
      }
      goto LAB_005e490c;
    }
    break;
  case 0xb:
    if ((local_10 != (uint *)0x0) && (local_20 != (uint *)0x0)) {
      if (param_3 != (uint *)0x0) {
        local_30 = _malloc((int)local_8 << 2);
        if (local_30 != (uint *)0x0) {
          iVar3 = FUN_005d91c9(local_30,local_8);
          if ((iVar3 < 0) || (iVar3 = FUN_005d91c9(param_3,local_8), iVar3 < 0)) goto LAB_005e4925;
          local_c = (uint *)((uint)local_8 & 0xffffff);
          iVar3 = FUN_005d9fa1(param_2,(uint)local_c | 0x11000000,local_30,local_28,0,0);
          puVar9 = local_c;
          puVar12 = local_30;
          if (iVar3 < 0) goto LAB_005e4925;
          goto LAB_005e3041;
        }
        goto LAB_005e4661;
      }
      goto LAB_005e490c;
    }
    break;
  case 0xc:
    if ((local_10 != (uint *)0x0) && (local_20 != (uint *)0x0)) {
      if (param_3 != (uint *)0x0) {
        iVar3 = FUN_005d91c9(param_3,local_8);
        puVar12 = local_14;
        puVar5 = local_28;
joined_r0x005e314b:
        if (iVar3 < 0) goto LAB_005e4925;
        puVar9 = (uint *)((uint)local_8 & 0xffffff);
LAB_005e3164:
        uVar18 = CONCAT44(0x2000017,puVar5);
        puVar9 = (uint *)((uint)puVar9 | 0x22000000);
        goto LAB_005e2f7e;
      }
      goto LAB_005e490c;
    }
    break;
  case 0xd:
    if ((local_10 != (uint *)0x0) && (local_20 != (uint *)0x0)) {
      if (param_3 != (uint *)0x0) {
        iVar3 = FUN_005d91c9(param_3,local_8);
        puVar12 = local_28;
        puVar5 = local_14;
        goto joined_r0x005e314b;
      }
      goto LAB_005e490c;
    }
    break;
  case 0xe:
    if ((local_10 != (uint *)0x0) && (local_20 != (uint *)0x0)) {
      if (param_3 != (uint *)0x0) {
        iVar3 = FUN_005d91c9(param_3,local_8);
        local_70[1] = local_14;
        puVar12 = local_28;
joined_r0x005e31d5:
        if (iVar3 < 0) goto LAB_005e4925;
        puVar9 = (uint *)((uint)local_8 & 0xffffff);
        goto LAB_005e2f75;
      }
      goto LAB_005e490c;
    }
    break;
  case 0xf:
    if ((local_10 != (uint *)0x0) && (local_20 != (uint *)0x0)) {
      if (param_3 != (uint *)0x0) {
        iVar3 = FUN_005d91c9(param_3,local_8);
        local_70[1] = local_28;
        puVar12 = local_14;
        goto joined_r0x005e31d5;
      }
      goto LAB_005e490c;
    }
    break;
  case 0x10:
    if ((local_10 != (uint *)0x0) && (local_20 != (uint *)0x0)) {
      if (param_3 != (uint *)0x0) {
        local_30 = _malloc((int)local_8 * 0x14);
        if (local_30 != (uint *)0x0) {
          uVar10 = 0;
          puVar5 = local_30;
          do {
            local_48[uVar10 - 1] = (uint)puVar5;
            uVar10 = uVar10 + 1;
            puVar5 = puVar5 + (int)puVar12;
          } while (uVar10 < 5);
          iVar3 = FUN_005d91c9(local_30,(int)local_8 * 5);
          if ((iVar3 < 0) || (iVar3 = FUN_005d91c9(param_3,local_8), iVar3 < 0)) goto LAB_005e4925;
          local_c = (uint *)((uint)local_8 & 0xffffff);
          local_10 = (uint *)((uint)local_c | 0x11000000);
          iVar3 = FUN_005d9fa1(param_2,local_10,local_70[9],local_28,0,0);
          if ((iVar3 < 0) ||
             (((iVar3 = FUN_005d9fa1(param_2,(uint)local_c | 0x24000000,local_48[0],local_14,
                                     local_70[9],0), iVar3 < 0 ||
               (iVar3 = FUN_005d9fa1(param_2,local_10,local_48[1],local_48[0],0,0), iVar3 < 0)) ||
              (iVar3 = FUN_005d9fa1(param_2,(uint)local_c | 0x21000000,local_40,local_48[0],
                                    local_48[1],4), iVar3 < 0)))) goto LAB_005e4925;
          iVar3 = FUN_005d9fa1(param_2,local_10,local_3c,local_40,0,8);
          local_70[1] = local_40;
          puVar12 = local_3c;
          puVar9 = local_c;
          goto joined_r0x005e3326;
        }
        goto LAB_005e4661;
      }
      goto LAB_005e490c;
    }
    break;
  case 0x11:
    if ((local_10 != (uint *)0x0) && (local_20 != (uint *)0x0)) {
      if (param_3 != (uint *)0x0) {
        local_30 = _malloc((int)local_8 * 0x14);
        if (local_30 == (uint *)0x0) goto LAB_005e4661;
        uVar10 = 0;
        puVar5 = local_30;
        do {
          local_48[uVar10 - 1] = (uint)puVar5;
          uVar10 = uVar10 + 1;
          puVar5 = puVar5 + (int)puVar12;
        } while (uVar10 < 5);
        iVar3 = FUN_005d91c9(local_30,(int)local_8 * 5);
        if ((iVar3 < 0) || (iVar3 = FUN_005d91c9(param_3,local_8), iVar3 < 0)) goto LAB_005e4925;
        local_c = (uint *)((uint)local_8 & 0xffffff);
        local_10 = (uint *)((uint)local_c | 0x11000000);
        iVar3 = FUN_005d9fa1(param_2,local_10,local_70[9],local_28,0,0);
        if ((iVar3 < 0) ||
           (iVar3 = FUN_005d9fa1(param_2,(uint)local_c | 0x24000000,local_48[0],local_14,local_70[9]
                                 ,0), iVar3 < 0)) goto LAB_005e4925;
LAB_005e351c:
        iVar3 = FUN_005d9fa1(param_2,local_10,local_48[1],local_48[0],0);
        if (iVar3 < 0) goto LAB_005e4925;
        uVar10 = (uint)local_c | 0x21000000;
        puVar12 = (uint *)local_48[0];
LAB_005e36db:
        iVar3 = FUN_005d9fa1(param_2,uVar10,local_40,puVar12,CONCAT44(4,local_48[1]));
        if ((iVar3 < 0) ||
           (iVar3 = FUN_005d9fa1(param_2,local_10,local_3c,local_40,0,8), puVar9 = local_c,
           puVar12 = local_3c, puVar5 = local_40, iVar3 < 0)) goto LAB_005e4925;
        goto LAB_005e3164;
      }
      goto LAB_005e490c;
    }
    break;
  case 0x12:
    if ((local_10 != (uint *)0x0) && (local_20 != (uint *)0x0)) {
      if (param_3 != (uint *)0x0) {
        local_30 = _malloc((int)local_8 << 4);
        if (local_30 != (uint *)0x0) {
          uVar10 = 0;
          puVar5 = local_30;
          do {
            local_48[uVar10] = (uint)puVar5;
            uVar10 = uVar10 + 1;
            puVar5 = puVar5 + (int)puVar12;
          } while (uVar10 < 4);
          iVar3 = FUN_005d91c9(local_48[0],local_8);
          if ((((iVar3 < 0) || (iVar3 = FUN_005d91c9(local_48[1],local_8), iVar3 < 0)) ||
              (iVar3 = FUN_005d91c9(local_40,local_8), iVar3 < 0)) ||
             ((iVar3 = FUN_005d91c9(local_3c,local_8), iVar3 < 0 ||
              (iVar3 = FUN_005d91c9(param_3,local_8), iVar3 < 0)))) goto LAB_005e4925;
          local_c = (uint *)((uint)local_8 & 0xffffff);
          iVar3 = FUN_005d9fa1(param_2,(uint)local_c | 0x25000000,local_48[0],local_14,local_28,0);
          if (iVar3 < 0) goto LAB_005e4925;
          local_10 = (uint *)((uint)local_c | 0x11000000);
          goto LAB_005e351c;
        }
        goto LAB_005e4661;
      }
      goto LAB_005e490c;
    }
    break;
  case 0x13:
    if ((local_10 != (uint *)0x0) && (local_20 != (uint *)0x0)) {
      if (param_3 != (uint *)0x0) {
        local_30 = _malloc((int)local_8 * 0x18);
        if (local_30 != (uint *)0x0) {
          uVar10 = 0;
          puVar5 = local_30;
          do {
            local_70[uVar10 + 8] = puVar5;
            uVar10 = uVar10 + 1;
            puVar5 = puVar5 + (int)puVar12;
          } while (uVar10 < 6);
          iVar3 = FUN_005d91c9(local_70[8],local_8);
          if ((((iVar3 < 0) || (iVar3 = FUN_005d91c9(local_70[9],local_8), iVar3 < 0)) ||
              (iVar3 = FUN_005d91c9(local_48[0],local_8), iVar3 < 0)) ||
             (((iVar3 = FUN_005d91c9(local_48[1],local_8), iVar3 < 0 ||
               (iVar3 = FUN_005d91c9(local_40,local_8), iVar3 < 0)) ||
              ((iVar3 = FUN_005d91c9(local_3c,local_8), iVar3 < 0 ||
               (iVar3 = FUN_005d91c9(param_3,local_8), iVar3 < 0)))))) goto LAB_005e4925;
          local_c = (uint *)((uint)local_8 & 0xffffff);
          local_10 = (uint *)((uint)local_c | 0x11000000);
          iVar3 = FUN_005d9fa1(param_2,local_10,local_70[8],local_14,0,0);
          if (iVar3 < 0) goto LAB_005e4925;
          local_1c = (uint *)((uint)local_c | 0x21000000);
          iVar3 = FUN_005d9fa1(param_2,local_1c,local_70[9],local_14,local_70[8],4);
          if (((iVar3 < 0) ||
              (iVar3 = FUN_005d9fa1(param_2,local_10,local_48[0],local_28,0,0), iVar3 < 0)) ||
             (iVar3 = FUN_005d9fa1(param_2,local_1c,local_48[1],local_28,local_48[0],4), iVar3 < 0))
          goto LAB_005e4925;
          uVar10 = (uint)local_c | 0x24000000;
          puVar12 = local_70[9];
          goto LAB_005e36db;
        }
        goto LAB_005e4661;
      }
      goto LAB_005e490c;
    }
    break;
  case 0x14:
    if ((local_10 != (uint *)0x0) && (local_20 != (uint *)0x0)) {
      if (local_8 != (uint *)0x0) {
        piVar4 = (int *)FUN_005f762c();
        if ((piVar4 != (int *)0x0) && (*(int *)(*(int *)(param_1 + 8) + 0x4c) == *piVar4))
        goto LAB_005e2d3a;
LAB_005e2d64:
        puVar9 = local_8;
        puVar12 = local_14;
        if (param_3 == (uint *)0x0) goto LAB_005e490c;
code_r0x005e41b9:
        for (; puVar9 != (uint *)0x0; puVar9 = (uint *)((int)puVar9 + -1)) {
          *puVar5 = *puVar12;
          puVar12 = puVar12 + 1;
          puVar5 = puVar5 + 1;
        }
      }
      goto LAB_005e2bc0;
    }
    break;
  case 0x15:
    if ((local_10 != (uint *)0x0) && (local_20 != (uint *)0x0)) {
      if (local_8 != (uint *)0x0) {
LAB_005e2d3a:
        iVar3 = FUN_005d9fa1(param_2,(uint)local_8 & 0xffffff | 0x10000000,local_14,local_28,0,0);
        if (iVar3 < 0) goto LAB_005e4925;
        goto LAB_005e2d64;
      }
      goto LAB_005e2bc0;
    }
    break;
  case 0x16:
    if (local_20 != (uint *)0x0) {
      if (local_c != (uint *)0x0) {
        iVar3 = FUN_005d9413(*local_28,local_70 + 1);
        if (iVar3 < 0) {
          if (local_8 == local_c) goto LAB_005e2d64;
          iVar3 = FUN_005dc68d(local_10[4],local_14,local_c);
          puVar12 = local_14;
          if (iVar3 < 0) goto LAB_005e4925;
          local_88 = 1;
          local_18 = (uint *)0x0;
          if (local_c != (uint *)0x0) {
            do {
              FUN_005f762c();
              iVar3 = FUN_005f7616();
              if ((*(byte *)(iVar3 + 4) & 0x20) == 0) {
                local_88 = 0;
                break;
              }
              local_18 = (uint *)((int)local_18 + 1);
            } while (local_18 < local_c);
          }
          local_34 = (uint *)0x1;
          local_74 = 1;
          if (local_88 == 0) {
            local_34 = (uint *)0x1;
            local_74 = 0;
LAB_005e3a4f:
            if ((local_34 == (uint *)0x0) && (local_74 == 0)) {
LAB_005e3bc1:
              FUN_005d9de1(param_1,param_2,0xdac);
              iVar3 = -0x7fffbfff;
              goto LAB_005e4925;
            }
          }
          else {
            local_38 = local_8;
            if (local_8 < local_c) {
              local_24 = puVar12;
              do {
                local_18 = (uint *)FUN_005f762c();
                puVar5 = (uint *)FUN_005f762c();
                if (((*local_18 != *puVar5) || (local_18[2] != puVar5[2])) ||
                   (local_18[1] != puVar5[1])) {
                  local_34 = (uint *)0x0;
                }
                if ((*local_18 != *puVar5) || (local_18[3] != puVar5[3])) {
                  local_74 = 0;
                }
                local_38 = (uint *)((int)local_38 + 1);
                local_24 = local_24 + 1;
              } while (local_38 < local_c);
              goto LAB_005e3a4f;
            }
          }
          local_7c = 0xffffffff;
          local_20 = (uint *)0x1;
          if (local_34 == (uint *)0x0) {
            local_1c = (uint *)FUN_005f762c();
            iVar3 = FUN_005f762c();
            local_7c = local_1c[1];
            local_20 = (uint *)(*(int *)(iVar3 + 8) - local_1c[2]);
            local_18 = (uint *)0x0;
            if (local_c != (uint *)0x0) {
              do {
                piVar4 = (int *)FUN_005f762c();
                if ((piVar4[1] != local_7c) ||
                   ((*(byte *)(*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x10) + *piVar4 * 4) + 5) &
                    2) == 0)) goto LAB_005e3bc1;
                local_18 = (uint *)((int)local_18 + 1);
              } while (local_18 < local_c);
            }
            local_18 = (uint *)((int)local_8 * 2);
            if (local_18 < local_c) {
              local_38 = puVar12 + (int)local_8;
              local_24 = puVar12;
              do {
                uStack_98 = FUN_005f762c();
                local_1c = (uint *)FUN_005f762c();
                local_94 = FUN_005f762c();
                if (local_1c[2] - *(int *)(uStack_98 + 8) != *(int *)(local_94 + 8) - local_1c[2])
                goto LAB_005e3bc1;
                local_18 = (uint *)((int)local_18 + 1);
                local_24 = local_24 + 1;
                local_38 = local_38 + 1;
              } while (local_18 < local_c);
            }
            local_18 = (uint *)0x1;
            if ((uint *)0x1 < local_8) {
              local_24 = puVar12 + (int)local_8 + 1;
              do {
                local_1c = (uint *)FUN_005f762c();
                iVar3 = FUN_005f762c();
                if (local_20 != (uint *)(*(int *)(iVar3 + 8) - local_1c[2])) goto LAB_005e3bc1;
                local_18 = (uint *)((int)local_18 + 1);
                local_24 = local_24 + 1;
              } while (local_18 < local_8);
            }
          }
          else if (local_88 == 0) {
            local_20 = (uint *)((uint)local_c / (uint)local_8 + 3 >> 2);
          }
          if (param_3 != (uint *)0x0) {
            if ((local_20 == (uint *)0x1) && ((*(byte *)(*(int *)(param_1 + 8) + 0x92) & 0x80) != 0)
               ) {
              local_70[3] = (uint *)*local_28;
            }
            else {
              dVar2 = (double)(int)local_20;
              if ((int)local_20 < 0) {
                dVar2 = dVar2 + 4294967296.0;
              }
              local_1c = (uint *)FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,
                                              dVar2);
              local_84 = 0xffffffff;
              local_80 = 0xffffffff;
              local_74 = -1;
              local_70[3] = (uint *)0xffffffff;
              iVar3 = FUN_005d9fa1(param_2,0x13000001,&local_84,local_28,0,4);
              if ((((iVar3 < 0) ||
                   (iVar3 = FUN_005d9fa1(param_2,0x11000001,&local_80,&local_84,0,8), iVar3 < 0)) ||
                  (iVar3 = FUN_005d9fa1(param_2,0x24000001,&local_74,&local_80,local_28,2),
                  iVar3 < 0)) ||
                 (iVar3 = FUN_005d9fa1(param_2,0x25000001,local_70 + 3,&local_74,&local_1c,2),
                 iVar3 < 0)) goto LAB_005e4925;
            }
            if (local_7c != 0xffffffff) {
              puVar6 = (undefined4 *)FUN_005f762c();
              *puVar6 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x60);
              local_84 = 0xffffffff;
              local_80 = 0xffffffff;
              local_74 = -1;
              local_a4 = (uint *)0xffffffff;
              iVar3 = FUN_005d9fa1(param_2,0x13000001,&local_84,&local_7c,0,4);
              if (((iVar3 < 0) ||
                  (iVar3 = FUN_005d9fa1(param_2,0x11000001,&local_80,&local_84,0,8), iVar3 < 0)) ||
                 ((iVar3 = FUN_005d9fa1(param_2,0x24000001,&local_74,&local_80,&local_7c,2),
                  iVar3 < 0 ||
                  (iVar3 = FUN_005d9fa1(param_2,0x24000001,&local_a4,&local_74,local_70 + 3,0),
                  iVar3 < 0)))) goto LAB_005e4925;
              local_70[3] = local_a4;
            }
            if (*(int *)(*(int *)(param_1 + 8) + 0x74) == 0) {
              local_38 = local_70[3];
            }
            else {
              local_38 = (uint *)0xffffffff;
              iVar3 = FUN_005d9fa1(param_2,0x10000001,&local_38,local_70 + 3,0,
                                   -((uint *)0x1 < local_20) & 2);
              if (iVar3 < 0) goto LAB_005e4925;
              puVar6 = (undefined4 *)FUN_005f762c();
              *puVar6 = *(undefined4 *)(*(int *)(param_1 + 8) + 100);
            }
            local_20 = (uint *)((uint)local_c / (uint)local_8);
            if (local_34 == (uint *)0x0) {
              local_18 = (uint *)0x0;
              if (local_8 != (uint *)0x0) {
                local_78 = (uint *)((int)param_3 - (int)local_14);
                local_34 = local_14;
                do {
                  puVar6 = (undefined4 *)((int)local_78 + (int)local_34);
                  uVar7 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x60),0,0,0);
                  *puVar6 = uVar7;
                  local_1c = (uint *)FUN_005f762c();
                  iVar3 = FUN_005f762c();
                  if (iVar3 == 0) goto LAB_005e4661;
                  FUN_005f7c63();
                  *(undefined4 *)(iVar3 + 0x20) = 0xffffffff;
                  *(uint **)(iVar3 + 4) = local_38;
                  *(undefined4 *)(iVar3 + 0x18) = 0x1f;
                  if (local_20 != (uint *)0x0) {
                    local_24 = local_34;
                    local_2c = local_20;
                    do {
                      iVar8 = FUN_005f762c();
                      *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) & *(uint *)(iVar8 + 0x18);
                      local_24 = local_24 + (int)local_8;
                      local_2c = (uint *)((int)local_2c + -1);
                    } while (local_2c != (uint *)0x0);
                  }
                  local_18 = (uint *)((int)local_18 + 1);
                  local_34 = local_34 + 1;
                } while (local_18 < local_8);
              }
            }
            else {
              iVar3 = FUN_005d91c9(param_3,local_8);
              puVar12 = local_20;
              if (iVar3 < 0) goto LAB_005e4925;
              local_30 = _malloc((int)local_20 << 3);
              if (local_30 == (uint *)0x0) goto LAB_005e4661;
              local_1c = local_30 + (int)puVar12;
              local_2c = (uint *)0x0;
              if (local_8 != (uint *)0x0) {
                local_78 = (uint *)((int)param_3 - (int)local_14);
                local_34 = local_14;
                do {
                  puVar12 = local_20;
                  local_18 = (uint *)0x1f;
                  if (local_88 == 0) {
                    local_70[4] = (uint *)0x0;
                    if (local_20 != (uint *)0x0) {
                      local_10 = local_34;
                      do {
                        iVar3 = FUN_005f762c();
                        local_18 = (uint *)((uint)local_18 & *(uint *)(iVar3 + 0x18));
                        local_30[(int)local_70[4]] = *local_10;
                        local_10 = local_10 + (int)local_8;
                        local_70[4] = (uint *)((int)local_70[4] + 1);
                      } while (local_70[4] < local_20);
                    }
                  }
                  else {
                    local_48[0] = 0;
                    local_48[1] = 0;
                    local_40 = (uint *)0x0;
                    local_3c = (uint *)0x0;
                    if (local_20 != (uint *)0x0) {
                      local_c = (uint *)((int)local_8 << 2);
                      local_70[4] = local_20;
                      puVar12 = local_34;
                      do {
                        iVar3 = FUN_005f762c();
                        local_18 = (uint *)((uint)local_18 & *(uint *)(iVar3 + 0x18));
                        uVar10 = *puVar12;
                        puVar12 = (uint *)((int)puVar12 + (int)local_c);
                        local_70[4] = (uint *)((int)local_70[4] + -1);
                        local_30[*(int *)(iVar3 + 0xc)] = uVar10;
                        local_48[*(int *)(iVar3 + 0xc)] = 1;
                      } while (local_70[4] != (uint *)0x0);
                    }
                    puVar12 = (uint *)0x0;
                    iVar3 = (int)local_48 - (int)local_30;
                    local_24 = (uint *)((int)local_30 - (int)local_48);
                    local_10 = (uint *)0x0;
                    puVar5 = local_30;
                    do {
                      if (*(int *)(iVar3 + (int)puVar5) != 0) {
                        *(uint *)((int)local_48 + (int)(local_24 + (int)puVar12)) = *puVar5;
                        local_48[(int)puVar12] = (uint)local_10;
                        puVar12 = (uint *)((int)puVar12 + 1);
                      }
                      local_10 = (uint *)((int)local_10 + 1);
                      puVar5 = puVar5 + 1;
                    } while (local_10 < (uint *)0x4);
                  }
                  local_94 = (int)puVar12 + 3U >> 2;
                  puVar5 = (uint *)0x4;
                  if (puVar12 < (uint *)0x4) {
                    puVar5 = puVar12;
                  }
                  uStack_98 = FUN_005f7478(&DAT_0069ed74,0x3a9,local_94 * (int)local_20,puVar5);
                  if (uStack_98 == 0xffffffff) goto LAB_005e4661;
                  local_24 = (uint *)0x0;
                  if (local_20 != (uint *)0x0) {
                    local_c = (uint *)((int)local_8 << 2);
                    local_70[4] = (uint *)0x0;
                    local_a0 = local_34;
                    do {
                      local_70[2] = (uint *)FUN_005f762c();
                      local_10 = (uint *)0x0;
                      if (puVar12 != (uint *)0x0) {
                        do {
                          if (local_88 == 0) {
                            bVar16 = local_24 == local_10;
                          }
                          else {
                            bVar16 = local_48[(int)local_10] == local_70[2][3];
                          }
                          if (bVar16) {
                            uVar17 = 0x3ff0000000000000;
                          }
                          else {
                            uVar17 = 0;
                          }
                          iVar3 = FUN_005f74cf(uStack_98,((uint)local_10 >> 2) + (int)local_70[4],
                                               (uint)local_10 & 3,uVar17);
                          if (iVar3 == -1) goto LAB_005e4661;
                          local_10 = (uint *)((int)local_10 + 1);
                        } while (local_10 < puVar12);
                      }
                      local_a0 = (uint *)((int)local_a0 + (int)local_c);
                      local_24 = (uint *)((int)local_24 + 1);
                      local_70[4] = (uint *)((int)local_70[4] + local_94);
                    } while (local_24 < local_20);
                  }
                  local_10 = (uint *)0x0;
                  if (puVar12 != (uint *)0x0) {
                    do {
                      uVar10 = FUN_005f74cf(uStack_98,(uint)local_10 >> 2,(uint)local_10 & 3,0);
                      local_1c[(int)local_10] = uVar10;
                      iVar3 = FUN_005f762c();
                      if (iVar3 == 0) goto LAB_005e4661;
                      local_10 = (uint *)((int)local_10 + 1);
                      *(uint **)(iVar3 + 4) = local_38;
                      *(undefined4 *)(iVar3 + 0x18) = 0x2000017;
                    } while (local_10 < puVar12);
                  }
                  iVar3 = FUN_005d9fa1(param_2,(uint)puVar12 & 0xffffff | 0x30000000,
                                       (int)local_78 + (int)local_34,local_30,local_1c,local_18);
                  if (iVar3 < 0) goto LAB_005e4925;
                  local_2c = (uint *)((int)local_2c + 1);
                  local_34 = local_34 + 1;
                } while (local_2c < local_8);
              }
            }
            goto LAB_005e2bc0;
          }
          goto LAB_005e490c;
        }
        iVar3 = __ftol();
        puVar12 = (uint *)(iVar3 * (int)local_8);
        if (puVar12 < local_c) {
          if (param_3 != (uint *)0x0) goto LAB_005e41ad;
          goto LAB_005e490c;
        }
      }
      lVar19 = 0x69f64400000db0;
      goto LAB_005e4917;
    }
    break;
  case 0x17:
    if ((local_10 != (uint *)0x0) && (iVar3 = *(int *)((int)param_2 + 0x24), iVar3 != 0)) {
      if (*(int *)(iVar3 + 4) == 0xd) {
        if (*(int *)(iVar3 + 0x10) != 2) break;
        if (param_3 != (uint *)0x0) {
          puVar12 = *(uint **)(iVar3 + 0x18);
LAB_005e41ad:
          puVar9 = local_8;
          puVar12 = local_14 + (int)puVar12;
          goto code_r0x005e41b9;
        }
      }
      else {
        if (*(int *)(iVar3 + 4) != 1) break;
        if (param_3 != (uint *)0x0) {
          puVar12 = (uint *)0x0;
          if (local_8 != (uint *)0x0) {
            do {
              param_3[(int)puVar12] = local_14[*(int *)(*(int *)(iVar3 + 8) + 0x18)];
              iVar3 = *(int *)(iVar3 + 0xc);
              puVar12 = (uint *)((int)puVar12 + 1);
            } while (puVar12 < local_8);
          }
          goto LAB_005e2bc0;
        }
      }
      goto LAB_005e490c;
    }
    break;
  case 0x18:
    if ((local_10 != (uint *)0x0) && (local_20 != (uint *)0x0)) {
      if (param_3 == (uint *)0x0) goto LAB_005e490c;
      local_30 = _malloc((int)local_8 << 4);
      if (local_30 == (uint *)0x0) goto LAB_005e4661;
      uVar10 = 0;
      puVar5 = local_30;
      do {
        local_48[uVar10] = (uint)puVar5;
        uVar10 = uVar10 + 1;
        puVar5 = puVar5 + (int)puVar12;
      } while (uVar10 < 4);
      local_24 = (uint *)0x0;
      if (puVar12 != (uint *)0x0) {
        local_2c = local_28 + (int)puVar12;
        local_70[2] = (uint *)((int)local_14 - (int)local_28);
        local_1c = (uint *)(local_48[0] - (int)local_28);
        puVar12 = local_28;
        do {
          iVar3 = FUN_005d9413(*(undefined4 *)((int)local_70[2] + (int)puVar12),&local_9c);
          if (iVar3 < 0) break;
          if ((double)CONCAT44(uStack_98,local_9c) == 0.0) {
            uVar10 = *local_2c;
          }
          else {
            uVar10 = *puVar12;
          }
          local_24 = (uint *)((int)local_24 + 1);
          local_2c = local_2c + 1;
          *(uint *)((int)local_1c + (int)puVar12) = uVar10;
          puVar12 = puVar12 + 1;
        } while (local_24 < local_8);
      }
      if (local_24 == local_8) {
        iVar3 = FUN_005d91c9(param_3,local_8);
        puVar12 = (uint *)local_48[0];
        goto joined_r0x005e42c1;
      }
      iVar3 = FUN_005d91c9(local_48[0],local_8);
      if ((((iVar3 < 0) || (iVar3 = FUN_005d91c9(local_48[1],local_8), iVar3 < 0)) ||
          (iVar3 = FUN_005d91c9(local_40,local_8), iVar3 < 0)) ||
         (iVar3 = FUN_005d91c9(local_3c,local_8), iVar3 < 0)) goto LAB_005e4925;
      local_c = (uint *)((uint)local_8 & 0xffffff);
      local_10 = (uint *)((uint)local_c | 0x11000000);
      iVar3 = FUN_005d9fa1(param_2,local_10,local_48[0],local_14,0,0);
      if (((iVar3 < 0) ||
          (iVar3 = FUN_005d9fa1(param_2,(uint)local_c | 0x21000000,local_48[1],local_14,local_48[0],
                                4), iVar3 < 0)) ||
         ((iVar3 = FUN_005d9fa1(param_2,local_10,local_40,local_48[1],0,8), iVar3 < 0 ||
          (iVar3 = FUN_005d9fa1(param_2,(uint)local_c | 0x22000000,local_3c,local_40,local_48[1],
                                0x2000017), iVar3 < 0)))) goto LAB_005e4925;
      iVar3 = FUN_005dbae8(param_2,param_3,local_28 + (int)local_8,local_28,local_3c,local_8);
      goto LAB_005e2f88;
    }
    break;
  case 0x19:
    iVar3 = FUN_005d9cc7(*(undefined4 *)((int)param_2 + 0x20),local_70 + 2);
    if (iVar3 != 0) {
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
      iVar3 = FUN_005e1f75(local_70[2],iVar3,*(undefined4 *)((int)param_2 + 0x24),param_3,0,0);
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
      goto LAB_005e2f88;
    }
    FUN_005d9de1(param_1,param_2,0xdb6,"function \'%s\' missing implementation");
    break;
  case 0x1a:
    iVar3 = FUN_005dca6a(param_2);
LAB_005e2f88:
    if (iVar3 < 0) goto LAB_005e4925;
LAB_005e2bc0:
    if (param_3 != (uint *)0x0) {
      _Size = (int)local_8 << 2;
      local_8c = _malloc(_Size);
      if ((local_8c == (uint *)0x0) || (local_90 = _malloc(_Size), local_90 == (uint *)0x0))
      goto LAB_005e4661;
      FUN_005da405(*(undefined4 *)((int)param_2 + 0x10),local_8c);
      local_20 = (uint *)0x0;
      local_70[3] = (uint *)0x0;
      local_78 = (uint *)0x0;
      if (local_8 != (uint *)0x0) {
        local_70[4] = (uint *)((int)param_3 - (int)local_8c);
        local_2c = (uint *)((int)local_8c - (int)local_90);
        local_34 = local_90;
        do {
          pbVar1 = (byte *)((int)local_2c + (int)local_34);
          piVar4 = (int *)FUN_005f762c();
          if (piVar4 == (int *)0x0) {
            pcVar20 = "internal error: result register invalid";
            goto LAB_005e4915;
          }
          iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x4c);
          if (iVar3 == *piVar4) {
LAB_005e4479:
            *local_34 = 0;
          }
          else if (((*pbVar1 & 1) == 0) || ((*(byte *)(piVar4 + 6) & 1) != 0)) {
            if ((iVar3 == *piVar4) || (((*pbVar1 & 2) == 0 || ((*(byte *)(piVar4 + 6) & 2) != 0))))
            goto LAB_005e4479;
            local_70[3] = (uint *)((int)local_70[3] + 1);
            *local_34 = 2;
          }
          else {
            local_20 = (uint *)((int)local_20 + 1);
            *local_34 = 1;
          }
          local_78 = (uint *)((int)local_78 + 1);
          local_34 = local_34 + 1;
        } while (local_78 < local_8);
        if (local_20 != (uint *)0x0) {
          if (local_30 != (uint *)0x0) {
            _free(local_30);
          }
          puVar12 = local_20;
          local_30 = _malloc((int)local_20 << 4);
          if (local_30 == (uint *)0x0) goto LAB_005e4661;
          uVar10 = 0;
          puVar5 = local_30;
          do {
            local_48[uVar10] = (uint)puVar5;
            uVar10 = uVar10 + 1;
            puVar5 = puVar5 + (int)puVar12;
          } while (uVar10 < 4);
          iVar3 = FUN_005d91c9(local_48[1],local_20);
          if (((iVar3 < 0) || (iVar3 = FUN_005d91c9(local_40,local_20), iVar3 < 0)) ||
             (iVar3 = FUN_005d91c9(local_3c,local_20), iVar3 < 0)) goto LAB_005e4925;
          local_2c = (uint *)local_48[0];
          local_18 = (uint *)((int)local_90 - (int)param_3);
          local_1c = local_8;
          puVar12 = param_3;
          do {
            FUN_005f762c();
            if (*(int *)((int)local_18 + (int)puVar12) == 1) {
              *local_2c = *puVar12;
              local_2c = local_2c + 1;
            }
            puVar12 = puVar12 + 1;
            local_1c = (uint *)((int)local_1c + -1);
          } while (local_1c != (uint *)0x0);
          local_1c = (uint *)((uint)local_20 & 0xffffff);
          local_70[2] = (uint *)((uint)local_1c | 0x11000000);
          iVar3 = FUN_005d9fa1(param_2,local_70[2],local_48[1],local_48[0],0,0);
          if (((iVar3 < 0) ||
              (iVar3 = FUN_005d9fa1(param_2,(uint)local_1c | 0x21000000,local_40,local_48[0],
                                    local_48[1],4), iVar3 < 0)) ||
             ((iVar3 = FUN_005d9fa1(param_2,local_70[2],local_3c,local_40,0,8), iVar3 < 0 ||
              (iVar3 = FUN_005d9fa1(param_2,(uint)local_1c | 0x22000000,local_48[0],local_3c,
                                    local_40,0x2000017), iVar3 < 0)))) goto LAB_005e4925;
          local_2c = (uint *)local_48[0];
          local_1c = local_8;
          puVar12 = param_3;
          do {
            FUN_005f762c();
            if (*(int *)((int)puVar12 + (int)local_18) == 1) {
              uVar10 = *local_2c;
              local_2c = local_2c + 1;
              *puVar12 = uVar10;
            }
            puVar12 = puVar12 + 1;
            local_1c = (uint *)((int)local_1c + -1);
          } while (local_1c != (uint *)0x0);
        }
        if (local_70[3] != (uint *)0x0) {
          if (local_30 != (uint *)0x0) {
            _free(local_30);
          }
          puVar12 = local_70[3];
          local_30 = _malloc((int)local_70[3] * 0x24);
          if (local_30 == (uint *)0x0) goto LAB_005e4661;
          uVar10 = 0;
          puVar5 = local_30;
          do {
            local_70[uVar10 + 5] = puVar5;
            uVar10 = uVar10 + 1;
            puVar5 = puVar5 + (int)puVar12;
          } while (uVar10 < 9);
          local_2c = local_70[5];
          local_18 = (uint *)((int)local_90 - (int)param_3);
          local_1c = local_8;
          puVar12 = param_3;
          do {
            FUN_005f762c();
            puVar5 = local_2c;
            if (*(int *)((int)puVar12 + (int)local_18) == 2) {
              local_2c = local_2c + 1;
              *puVar5 = *puVar12;
            }
            puVar12 = puVar12 + 1;
            local_1c = (uint *)((int)local_1c + -1);
          } while (local_1c != (uint *)0x0);
          uVar10 = 1;
          do {
            uVar17 = FUN_005d91c9(local_70[uVar10 + 5],local_70[3]);
            iVar3 = (int)uVar17;
            if (iVar3 < 0) goto LAB_005e4925;
            uVar10 = (int)((ulonglong)uVar17 >> 0x20) + 1;
          } while (uVar10 < 9);
          local_24 = (uint *)((uint)local_70[3] & 0xffffff);
          iVar3 = FUN_005d9fa1(param_2,(uint)local_24 | 0x13000000,local_70[6],local_70[5],0,0x14);
          if (iVar3 < 0) goto LAB_005e4925;
          local_1c = (uint *)((uint)local_24 | 0x11000000);
          iVar3 = FUN_005d9fa1(param_2,local_1c,local_70[7],local_70[6],0,0x18);
          if (iVar3 < 0) goto LAB_005e4925;
          uStack_98 = (uint)local_24 | 0x24000000;
          iVar3 = FUN_005d9fa1(param_2,uStack_98,local_70[8],local_70[7],local_70[5],2);
          if ((iVar3 < 0) ||
             (iVar3 = FUN_005d9fa1(param_2,local_1c,local_70[9],local_70[5],0,0), iVar3 < 0))
          goto LAB_005e4925;
          local_70[2] = (uint *)((uint)local_24 | 0x22000000);
          iVar3 = FUN_005d9fa1(param_2,local_70[2],local_48[0],local_70[5],local_70[9],0x2000017);
          if (((iVar3 < 0) ||
              (((iVar3 = FUN_005d9fa1(param_2,local_1c,local_48[1],local_70[6],0,0), iVar3 < 0 ||
                (iVar3 = FUN_005d9fa1(param_2,local_70[2],local_40,local_48[1],local_70[6],0x2000017
                                     ), iVar3 < 0)) ||
               (iVar3 = FUN_005d9fa1(param_2,(uint)local_24 | 0x25000000,local_3c,local_48[0],
                                     local_40,0x2000017), iVar3 < 0)))) ||
             (iVar3 = FUN_005d9fa1(param_2,uStack_98,local_70[5],local_70[8],local_3c,2), iVar3 < 0)
             ) goto LAB_005e4925;
          param_2 = local_70[5];
          local_1c = local_8;
          puVar12 = param_3;
          do {
            FUN_005f762c();
            if (*(int *)((int)puVar12 + (int)local_18) == 2) {
              uVar10 = *param_2;
              param_2 = param_2 + 1;
              *puVar12 = uVar10;
            }
            puVar12 = puVar12 + 1;
            local_1c = (uint *)((int)local_1c + -1);
          } while (local_1c != (uint *)0x0);
        }
        if (local_8 != (uint *)0x0) {
          local_70[4] = (uint *)((int)param_3 - (int)local_8c);
          param_3 = local_8;
          puVar12 = local_8c;
          do {
            local_1c = puVar12;
            iVar3 = FUN_005f762c();
            uVar10 = *puVar12;
            uVar13 = *(uint *)(iVar3 + 0x18);
            *(uint *)(iVar3 + 0x18) = uVar10 & 0xf1ffffff | uVar13;
            uVar14 = *puVar12 & 0xe000000;
            uVar11 = uVar13 & 0xe000000;
            if ((uVar13 & 0xe000000) == 0) {
              uVar11 = uVar14;
            }
            if (*(int *)(iVar3 + 0x40) == 0) {
              if (uVar14 <= uVar11) {
LAB_005e48ee:
                uVar11 = uVar14;
              }
            }
            else if (uVar11 <= uVar14) goto LAB_005e48ee;
            puVar12 = local_1c + 1;
            param_3 = (uint *)((int)param_3 + -1);
            *(uint *)(iVar3 + 0x18) = uVar10 & 0xf1ffffff | uVar13 & 0xf1ffffff | uVar11;
            local_1c = puVar12;
          } while (param_3 != (uint *)0x0);
        }
      }
    }
LAB_005e490c:
    iVar3 = 0;
    goto LAB_005e4925;
  default:
    pcVar20 = "internal error: unrecognized expression";
LAB_005e4915:
    lVar19 = ZEXT48(pcVar20) << 0x20;
    param_2 = (uint *)0x0;
LAB_005e4917:
    FUN_005d9de1(param_1,param_2,lVar19);
  }
  iVar3 = -0x7fffbffb;
LAB_005e4925:
  _free(local_14);
  _free(local_28);
  _free(local_30);
  _free(local_8c);
  _free(local_90);
  return iVar3;
}


// ==== 0x5e49cf FUN_005e49cf

int __thiscall FUN_005e49cf(int param_1,int param_2,undefined4 *param_3,uint param_4)

{
  double dVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  puVar2 = param_3;
  if (param_2 == 0) {
    if (param_3 == (undefined4 *)0x0) {
      return 0;
    }
    uVar5 = 0;
    if (param_4 == 0) {
      return 0;
    }
    do {
      uVar3 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x60),0,0,0);
      param_3[uVar5] = uVar3;
      iVar4 = FUN_005f762c();
      if (iVar4 != 0) {
        *(undefined4 *)(iVar4 + 0x1c) = 0xffffffff;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < param_4);
    return 0;
  }
  iVar4 = *(int *)(param_2 + 4);
  if (iVar4 != 0xd) {
    if (iVar4 == 0xc) {
      iVar4 = FUN_005e2a38(param_2,param_3);
      return iVar4;
    }
    if (iVar4 == 1) {
      while (iVar4 = *(int *)(param_2 + 8), iVar4 != 0) {
        if (*(int *)(iVar4 + 4) == 0xd) {
          iVar6 = 1;
          if (*(int *)(iVar4 + 0x10) == 6) {
            iVar6 = *(int *)(iVar4 + 0x1c);
          }
          iVar4 = FUN_005e49cf(iVar4,param_3,iVar6);
        }
        else {
          if ((iVar4 == 0) || (*(int *)(iVar4 + 4) != 0xc)) break;
          iVar6 = *(int *)(iVar4 + 0x18) * *(int *)(iVar4 + 0x14);
          iVar4 = FUN_005e2a38(iVar4,param_3);
        }
        if (iVar4 < 0) {
          return iVar4;
        }
        if (param_3 != (undefined4 *)0x0) {
          param_3 = param_3 + iVar6;
        }
        param_2 = *(int *)(param_2 + 0xc);
        if (param_2 == 0) {
          return 0;
        }
      }
    }
    FUN_005d9de1(param_1,0,0,"internal error: unrecognized value");
    return -0x7fffbffb;
  }
  if (param_3 == (undefined4 *)0x0) {
    return 0;
  }
  iVar4 = *(int *)(param_2 + 0x10);
  if (iVar4 == 6) {
    uVar5 = 0;
    if (*(int *)(param_2 + 0x18) != -1) {
      if (param_4 == 0) {
        return 0;
      }
      do {
        param_3[uVar5] =
             *(undefined4 *)(*(int *)(param_1 + 0x18) + (*(int *)(param_2 + 0x18) + uVar5) * 4);
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_4);
      return 0;
    }
    if (param_4 == 0) {
      return 0;
    }
    do {
      param_3[uVar5] = *(undefined4 *)(*(int *)(param_1 + 0x1c) + uVar5 * 4);
      uVar5 = uVar5 + 1;
    } while (uVar5 < param_4);
    return 0;
  }
  dVar1 = 0.0;
  param_3 = (undefined4 *)0x0;
  if (iVar4 == 0) {
    if (*(int *)(param_2 + 0x18) == 0) {
      dVar1 = 0.0;
    }
    else {
      dVar1 = 1.0;
    }
    param_3 = (undefined4 *)0x2000017;
  }
  else {
    if (iVar4 == 1) {
      dVar1 = (double)*(int *)(param_2 + 0x18);
    }
    else {
      if (iVar4 != 2) {
        if (iVar4 == 3) {
          dVar1 = *(double *)(param_2 + 0x18);
        }
        goto LAB_005e4ae2;
      }
      dVar1 = (double)*(int *)(param_2 + 0x18);
      if (*(int *)(param_2 + 0x18) < 0) {
        dVar1 = dVar1 + 4294967296.0;
      }
    }
    param_3 = (undefined4 *)0x2;
  }
LAB_005e4ae2:
  uVar3 = FUN_005f74cf(*(undefined4 *)(*(int *)(param_1 + 8) + 0x50),0,0,dVar1);
  *puVar2 = uVar3;
  iVar4 = FUN_005f762c();
  if (iVar4 != 0) {
    *(uint *)(iVar4 + 0x18) = *(uint *)(iVar4 + 0x18) | (uint)param_3;
    *(undefined4 *)(iVar4 + 0x1c) = 0xffffffff;
  }
  return 0;
}


// ==== 0x5e4bb7 FUN_005e4bb7

uint __thiscall FUN_005e4bb7(int param_1,int param_2)

{
  void *_Memory;
  undefined4 *puVar1;
  uint uVar2;
  uint local_8;
  
  if (*(int *)(param_2 + 4) == 0xc) {
    uVar2 = *(int *)(param_2 + 0x18) * *(int *)(param_2 + 0x14);
    _Memory = _malloc(uVar2 * 4);
    if (_Memory == (void *)0x0) {
      local_8 = -0x7ff8fff2;
    }
    else {
      local_8 = FUN_005d91c9(_Memory,uVar2);
      if (((-1 < (int)local_8) && (local_8 = FUN_005e2a38(param_2,_Memory), -1 < (int)local_8)) &&
         (local_8 = FUN_005d9fa1(param_2,uVar2 & 0xffffff | 0x10000000,_Memory,_Memory,0,0),
         -1 < (int)local_8)) {
        local_8 = 0;
        if (uVar2 != 0) {
          do {
            puVar1 = (undefined4 *)FUN_005f762c(*(undefined4 *)((int)_Memory + local_8 * 4));
            if (puVar1 != (undefined4 *)0x0) {
              *puVar1 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x5c);
            }
            local_8 = local_8 + 1;
          } while (local_8 < uVar2);
        }
        local_8 = FUN_005dc613(*(undefined4 *)(param_2 + 0x10),_Memory,
                               *(undefined4 *)(*(int *)(param_1 + 8) + 0x5c),1,1,0,0);
      }
    }
    _free(_Memory);
    if (*(int *)(param_1 + 0x34) != 0) {
      local_8 = -0x7fffbffb;
    }
  }
  else {
    local_8 = 0;
  }
  return local_8;
}


// ==== 0x5e4ca2 FUN_005e4ca2

int __thiscall
FUN_005e4ca2(undefined4 *param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
            int param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,uint param_10,
            undefined4 *param_11,int param_12)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined1 local_18 [4];
  int local_14;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  if (((param_10 & 0xffffffc2) != 0) || (param_11 == (undefined4 *)0x0)) {
    return -0x7789f794;
  }
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1])(1);
  }
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[2])(1);
  }
  _free((void *)param_1[6]);
  *param_1 = param_2;
  param_1[5] = param_10;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[3] = param_9;
  param_1[0xc] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = param_8;
  if (param_6 == 0) {
    iVar4 = FUN_005d7700(param_9,2,local_18);
    if (iVar4 < 0) {
      FUN_005d9de1(param_1,0,0xdb2,"unrecognized compiler target \'%s\'",param_1[3]);
      return -0x7789f794;
    }
    param_1[4] = local_14;
    if (local_14 == -0x1ff00) {
      param_1[4] = 0xfffe0101;
      local_8 = 1;
    }
    if (param_1[4] == -0xff00) {
      param_1[4] = 0xffff0101;
      local_c = 1;
    }
    uVar1 = param_1[4];
    if (uVar1 < 0xfffe0300) {
      if (uVar1 != 0xfffe02ff) {
        if (uVar1 == 0x54580100) goto LAB_005e4d38;
        if ((uVar1 != 0xfffe0101) && (uVar1 != 0xfffe0200)) goto LAB_005e4ddd;
      }
      pvVar2 = _malloc(0x150);
      if (pvVar2 == (void *)0x0) goto LAB_005e4d50;
      uVar3 = FUN_00611e41(param_8);
      goto LAB_005e4d52;
    }
    if (0xffff0100 < uVar1) {
      if (uVar1 < 0xffff0105) {
        param_1[5] = param_1[5] & 0xfffffff7;
        pvVar2 = _malloc(0x208);
        if (pvVar2 == (void *)0x0) goto LAB_005e4d50;
        uVar3 = FUN_00604269();
      }
      else {
        if ((uVar1 != 0xffff0200) && (uVar1 != 0xffff02ff)) goto LAB_005e4ddd;
        pvVar2 = _malloc(0x140);
        if (pvVar2 == (void *)0x0) goto LAB_005e4d50;
        uVar3 = FUN_0060cd67();
      }
      goto LAB_005e4d52;
    }
LAB_005e4ddd:
    param_1[2] = 0;
  }
  else {
    param_1[4] = 0x46580200;
LAB_005e4d38:
    pvVar2 = _malloc(0x110);
    if (pvVar2 == (void *)0x0) {
LAB_005e4d50:
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_00612900();
    }
LAB_005e4d52:
    param_1[2] = uVar3;
  }
  if (param_1[2] == 0) {
    return -0x7ff8fff2;
  }
  if (param_3 == 0) {
    puVar6 = param_1 + 1;
    uVar3 = param_1[5];
    uVar5 = *param_1;
    FUN_005ba06e(uVar5,uVar3,puVar6);
    iVar4 = FUN_005c50ee(uVar5,uVar3,puVar6);
    FUN_005ba07f();
    if (-1 < iVar4) goto LAB_005e4ea6;
  }
  else {
    param_1[1] = param_3;
LAB_005e4ea6:
    if (local_8 != 0) {
      FUN_005d9e57(param_1,0,0xdb1,"vs_1_0 is no longer supported; using vs_1_1");
    }
    if (local_c != 0) {
      FUN_005d9e57(param_1,0,0xdb1,"ps_1_0 is no longer supported; using ps_1_1");
    }
    iVar4 = FUN_005e293e();
    if (-1 < iVar4) {
      if (param_6 == 0) {
        if (param_4 == 0) {
          iVar4 = FUN_005d9cc7(param_5,&param_4);
          if (iVar4 != 0) {
            uVar3 = 1;
            goto LAB_005e4f53;
          }
          FUN_005d9de1(param_1,0,0xdad,"overloaded function not found");
        }
        else {
          iVar4 = FUN_005d9bb3(param_4);
          if (iVar4 != 0) {
            uVar3 = 0;
LAB_005e4f53:
            iVar4 = FUN_005e1f75(param_4,iVar4,param_7,0,1,uVar3);
            goto LAB_005e4f65;
          }
          FUN_005d9de1(param_1,0,0xdad,"\'%s\': entrypoint not found",param_4);
        }
LAB_005e4f49:
        iVar4 = -0x7fffbffb;
      }
      else {
        iVar4 = FUN_005e4bb7(param_6);
LAB_005e4f65:
        if (-1 < iVar4) {
          if (param_1[0xd] != 0) goto LAB_005e4f49;
          iVar4 = (**(code **)(*(int *)param_1[2] + 0xc))(param_11,0);
          if (-1 < iVar4) {
            if (param_12 != 0) {
              iVar4 = param_12;
              uVar3 = (**(code **)(*(int *)*param_11 + 0xc))((int *)*param_11,param_12);
              iVar4 = FUN_005d7665(uVar3,iVar4);
              if (iVar4 < 0) goto LAB_005e4fa3;
            }
            iVar4 = 0;
          }
        }
      }
    }
LAB_005e4fa3:
    if (param_3 != 0) goto LAB_005e4fb5;
  }
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1])(1);
  }
LAB_005e4fb5:
  param_1[1] = 0;
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[2])(1);
  }
  param_1[2] = 0;
  _free((void *)param_1[6]);
  param_1[6] = 0;
  return iVar4;
}


// ==== 0x5e4fdd FUN_005e4fdd

undefined4
FUN_005e4fdd(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 *param_7,undefined4 *param_8)

{
  undefined4 uVar1;
  
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = 0;
  }
  if (param_8 != (undefined4 *)0x0) {
    *param_8 = 0;
  }
  if (param_3 == 0) {
    uVar1 = 0x8876086c;
  }
  else {
    uVar1 = FUN_005e4ca2(param_1,param_2,param_3,0,0,0,param_4,param_5,param_6,param_7,param_8);
  }
  return uVar1;
}


// ==== 0x5e5022 FUN_005e5022

void FUN_005e5022(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 *param_8,
                 undefined4 *param_9)

{
  if (param_8 != (undefined4 *)0x0) {
    *param_8 = 0;
  }
  if (param_9 != (undefined4 *)0x0) {
    *param_9 = 0;
  }
  FUN_005e4ca2(param_1,param_2,0,param_3,0,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}


// ==== 0x5e505d FUN_005e505d

int __thiscall
FUN_005e505d(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 *param_7,undefined4 *param_8)

{
  char *pcVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  
  do {
    iVar6 = param_4;
    if (param_7 != (undefined4 *)0x0) {
      *param_7 = 0;
    }
    if (param_8 != (undefined4 *)0x0) {
      *param_8 = 0;
    }
    iVar4 = FUN_005da768(iVar6);
    if (iVar4 != 0) {
      iVar6 = FUN_005e4ca2(param_2,param_3,0,0,iVar6,0,0,param_5,param_6,param_7,param_8);
      return iVar6;
    }
    if (*(int *)(iVar6 + 4) != 0xc) {
      FUN_005d9de1(param_1,iVar6,0,"internal error: expression expected");
      return -0x7fffbffb;
    }
    iVar4 = iVar6;
    if (1 < (uint)(*(int *)(iVar6 + 0x18) * *(int *)(iVar6 + 0x14))) {
      pcVar5 = "expressions returning objects in an array or struct not yet implemented";
      goto LAB_005e520a;
    }
    do {
      if (*(int *)(iVar4 + 0x1c) != 0) break;
      iVar4 = *(int *)(iVar4 + 0x20);
    } while (*(int *)(iVar4 + 4) == 0xc);
    do {
      if (*(int *)(iVar4 + 4) != 1) break;
      iVar4 = *(int *)(iVar4 + 8);
    } while (iVar4 != 0);
    if (iVar4 == 0) goto LAB_005e51ff;
    if ((*(int *)(iVar4 + 4) == 0xc) && (*(int *)(iVar4 + 0x1c) == 0x1b)) {
      iVar6 = FUN_005e5022(param_2,param_3,*(undefined4 *)(*(int *)(iVar4 + 0x24) + 0x20),
                           *(undefined4 *)(*(int *)(iVar4 + 0x24) + 0x24),0,
                           *(undefined4 *)(*(int *)(iVar4 + 0x20) + 0x18),param_6,param_7,param_8);
      return iVar6;
    }
    if (*(int *)(iVar4 + 4) != 0xd) goto LAB_005e51ff;
  } while ((*(int *)(iVar4 + 0x10) == 4) &&
          (param_4 = *(int *)(iVar4 + 0x18), *(int *)(*(int *)(iVar4 + 0x18) + 4) == 0xc));
  if (*(int *)(iVar4 + 0x10) == 5) {
    if (param_7 != (undefined4 *)0x0) {
      piVar3 = *(int **)(iVar4 + 0x18);
      *param_7 = piVar3;
      (**(code **)(*piVar3 + 4))(piVar3);
    }
    if (param_8 != (undefined4 *)0x0) {
      *param_8 = 0;
    }
  }
  else {
    if (((*(int *)(iVar4 + 0x10) != 6) || (*(int *)(iVar4 + 0x20) != 9)) ||
       (pcVar5 = *(char **)(iVar4 + 0x28), pcVar5 == (char *)0x0)) {
LAB_005e51ff:
      pcVar5 = "non-trivial object expressions not yet implemented";
LAB_005e520a:
      FUN_005d9de1(param_1,iVar6,0xdac,pcVar5);
      return -0x7fffbfff;
    }
    if (param_7 != (undefined4 *)0x0) {
      pcVar1 = pcVar5 + 1;
      do {
        cVar2 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar2 != '\0');
      iVar6 = thunk_FUN_005d65b0(pcVar5 + (1 - (int)pcVar1),param_7);
      if (iVar6 < 0) {
        return iVar6;
      }
      piVar3 = (int *)*param_7;
      uVar7 = (**(code **)(*piVar3 + 0x10))(piVar3);
      puVar10 = *(undefined4 **)(iVar4 + 0x28);
      puVar8 = (undefined4 *)(**(code **)(*piVar3 + 0xc))(piVar3);
      for (uVar9 = uVar7 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar8 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar8 = puVar8 + 1;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
    }
    if (param_8 != (undefined4 *)0x0) {
      *param_8 = 1;
    }
  }
  return 0;
}


// ==== 0x5e5221 FUN_005e5221

undefined4 FUN_005e5221(char *param_1,undefined1 *param_2,byte *param_3)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  char *_Str;
  uint _MaxCount;
  char local_20 [27];
  byte local_5;
  
  cVar1 = *param_1;
  _Str = param_1;
  while ((cVar1 != '\0' && (iVar3 = _isalpha((int)*_Str), iVar3 != 0))) {
    _Str = _Str + 1;
    cVar1 = *_Str;
  }
  if (*_Str == '\0') {
    local_5 = 0;
  }
  else {
    lVar4 = _atoi(_Str);
    local_5 = (byte)lVar4;
  }
  if (0xf < local_5) {
    *param_2 = 0;
    *param_3 = 0xff;
    return 0x80004005;
  }
  _MaxCount = (int)_Str - (int)param_1;
  if ((_MaxCount == 0) || (0x14 < _MaxCount)) {
    return 0x80004005;
  }
  cVar1 = *_Str;
  if (cVar1 != '\0') {
    do {
      iVar3 = _isdigit((int)cVar1);
      if (iVar3 == 0) break;
      _Str = _Str + 1;
      cVar1 = *_Str;
    } while (cVar1 != '\0');
    if (*_Str != '\0') {
      return 0x80004005;
    }
  }
  if (*param_1 != '\0') {
    iVar3 = -(int)param_1;
    do {
      iVar5 = _isalpha((int)*param_1);
      if (iVar5 == 0) break;
      cVar1 = FUN_00671b76((int)*param_1);
      param_1[(int)(local_20 + iVar3)] = cVar1;
      param_1 = param_1 + 1;
    } while (*param_1 != '\0');
  }
  iVar3 = _strncmp(local_20,"POSITION",_MaxCount);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    iVar3 = _strncmp(local_20,"BLENDWEIGHT",_MaxCount);
    if (iVar3 == 0) {
      uVar2 = 1;
    }
    else {
      iVar3 = _strncmp(local_20,"BLENDINDICES",_MaxCount);
      if (iVar3 == 0) {
        uVar2 = 2;
      }
      else {
        iVar3 = _strncmp(local_20,"NORMAL",_MaxCount);
        if (iVar3 == 0) {
          uVar2 = 3;
        }
        else {
          iVar3 = _strncmp(local_20,"PSIZE",_MaxCount);
          if (iVar3 == 0) {
            uVar2 = 4;
          }
          else {
            iVar3 = _strncmp(local_20,"TEXCOORD",_MaxCount);
            if (iVar3 == 0) {
              uVar2 = 5;
            }
            else {
              iVar3 = _strncmp(local_20,"TANGENT",_MaxCount);
              if (iVar3 == 0) {
                uVar2 = 6;
              }
              else {
                iVar3 = _strncmp(local_20,"BINORMAL",_MaxCount);
                if (iVar3 == 0) {
                  uVar2 = 7;
                }
                else {
                  iVar3 = _strncmp(local_20,"TESSFACTOR",_MaxCount);
                  if (iVar3 == 0) {
                    uVar2 = 8;
                  }
                  else {
                    iVar3 = _strncmp(local_20,"POSITIONT ",_MaxCount);
                    if (iVar3 == 0) {
                      uVar2 = 9;
                    }
                    else {
                      iVar3 = _strncmp(local_20,"COLOR",_MaxCount);
                      if (iVar3 != 0) {
                        iVar3 = _strncmp(local_20,"FOG",_MaxCount);
                        if (iVar3 == 0) {
                          uVar2 = 0xb;
                          goto LAB_005e549f;
                        }
                        iVar3 = _strncmp(local_20,"DEPTH",_MaxCount);
                        if (iVar3 == 0) {
                          uVar2 = 0xc;
                          goto LAB_005e549f;
                        }
                        iVar3 = _strncmp(local_20,"SAMPLE",_MaxCount);
                        if (iVar3 == 0) {
                          uVar2 = 0xd;
                          goto LAB_005e549f;
                        }
                        iVar3 = _strncmp(local_20,"DIFFUSE",_MaxCount);
                        if (iVar3 == 0) {
                          local_5 = 0;
                        }
                        else {
                          iVar3 = _strncmp(local_20,"SPECULAR",_MaxCount);
                          if (iVar3 != 0) {
                            return 0x80004005;
                          }
                          local_5 = 1;
                        }
                      }
                      uVar2 = 10;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_005e549f:
  *param_2 = uVar2;
  *param_3 = local_5;
  return 0;
}


// ==== 0x5e54bc FUN_005e54bc

uint FUN_005e54bc(char *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if ((param_1 == (char *)0x0) || (cVar1 = *param_1, cVar1 == '\0')) {
    uVar3 = 0;
  }
  else {
    do {
      iVar2 = FUN_00671b76((int)cVar1);
      uVar3 = uVar3 * 0x13 + iVar2;
      param_1 = param_1 + 1;
      cVar1 = *param_1;
    } while (cVar1 != '\0');
    uVar3 = uVar3 % 7;
  }
  return uVar3;
}


// ==== 0x5e54f8 FUN_005e54f8

undefined4 * __thiscall FUN_005e54f8(int param_1,LPCSTR param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_005e54bc(param_2);
  puVar2 = *(undefined4 **)(param_1 + iVar1 * 4);
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    iVar1 = lstrcmpiA((LPCSTR)*puVar2,param_2);
    if (iVar1 == 0) break;
    puVar2 = (undefined4 *)puVar2[8];
  }
  return puVar2;
}


// ==== 0x5e552a FUN_005e552a

void __thiscall FUN_005e552a(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  uVar3 = 0;
  do {
    for (iVar1 = *(int *)(param_1 + uVar3 * 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x20)) {
      *(int *)(param_2 + iVar2 * 4) = iVar1;
      iVar2 = iVar2 + 1;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 7);
  return;
}


// ==== 0x5e554f FUN_005e554f

void __fastcall FUN_005e554f(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0xd] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x1e] = 0;
  return;
}


// ==== 0x5e556b FUN_005e556b

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_005e556b(undefined4 *param_1,char *param_2)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  undefined1 local_1004 [255];
  undefined1 local_f05;
  undefined4 uStack_8;
  
  uStack_8 = 0x5e5578;
  iVar2 = 0xd;
  bVar5 = true;
  param_1[0x13] = 1;
  pcVar3 = param_2;
  pcVar4 = "syntax error";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    piVar1 = param_1 + 4;
    FUN_005b212b(2000,piVar1);
    if (*piVar1 == 9) {
      if (param_1[0x15] == 0x7e7) {
        FUN_005b1f01(*param_1,piVar1,0x7e7,
                     "\'%s\' is not a valid instruction in this shader version",param_1[6]);
      }
      if (param_1[0x15] == 0x7e8) {
        FUN_005b1f01(*param_1,piVar1,0x7e8,"invalid instruction modifiers \'%s\'",param_1[6]);
      }
    }
  }
  else {
    _vsnprintf(local_1004,0x1000,param_2,&stack0x0000000c);
    local_f05 = 0;
    FUN_005b1f01(*param_1,param_1 + 4,0,&DAT_006cc568,local_1004);
  }
  return;
}


// ==== 0x5e5629 FUN_005e5629

undefined4
FUN_005e5629(undefined4 param_1,undefined4 param_2,short param_3,int param_4,undefined4 param_5,
            undefined4 *param_6)

{
  if (param_3 == 1) {
LAB_005e566e:
    FUN_005b1fca(*param_6,param_6[0xc],param_4 + 5000,&DAT_006cc568,param_5);
  }
  else {
    if (param_3 != 2) {
      if (param_3 == 5) goto LAB_005e566e;
      if (param_3 != 6) {
        return 0;
      }
    }
    FUN_005b1f01(*param_6,param_6[0xc],param_4 + 5000,&DAT_006cc568,param_5);
    param_6[0x13] = 1;
  }
  return 0;
}


// ==== 0x5e5695 FUN_005e5695

int __thiscall FUN_005e5695(undefined4 *param_1,int param_2)

{
  if (param_2 == 0) {
    if (param_1[0x13] == 0) {
      FUN_005b1f01(*param_1,param_1 + 4,0,"internal error: production failed");
      param_1[0x13] = 1;
    }
    param_1[0x14] = 1;
    param_2 = 0;
  }
  return param_2;
}


// ==== 0x5e56ca FUN_005e56ca

uint __thiscall FUN_005e56ca(int param_1,byte *param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  int iVar14;
  byte *pbVar15;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  uint local_50;
  uint local_4c;
  uint local_48;
  int local_44;
  byte *local_20;
  byte local_10 [16];
  
  local_20 = *(byte **)((int)param_2 + 8);
  *(undefined4 *)(param_1 + 0x54) = 0;
  local_50 = 0x10d;
  local_44 = 0;
  local_4c = 0;
  local_48 = 0;
  bVar16 = true;
  bVar18 = false;
  bVar1 = false;
  bVar2 = false;
  bVar19 = false;
  bVar4 = false;
  bVar5 = false;
  bVar20 = false;
  bVar3 = false;
  if (*local_20 == 0) {
LAB_005e6037:
    *(undefined4 *)(param_1 + 0x54) = 0;
    *(int *)(param_1 + 0x40) = local_44;
    *(uint *)(param_1 + 0x44) = local_4c;
    *(uint *)(param_1 + 0x48) = local_48;
  }
  else {
    do {
      for (param_2 = local_20; (*param_2 != 0 && (*param_2 != 0x5f)); param_2 = param_2 + 1) {
      }
      uVar8 = (int)param_2 - (int)local_20;
      if (0xf < uVar8) goto LAB_005e6030;
      pbVar9 = local_10;
      for (uVar11 = uVar8 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined4 *)pbVar9 = *(undefined4 *)local_20;
        local_20 = local_20 + 4;
        pbVar9 = pbVar9 + 4;
      }
      iVar14 = 3;
      for (uVar11 = uVar8 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
        *pbVar9 = *local_20;
        local_20 = local_20 + 1;
        pbVar9 = pbVar9 + 1;
      }
      local_10[uVar8] = 0;
      if (*param_2 != 0) {
        param_2 = param_2 + 1;
      }
      if (bVar16) {
        iVar14 = 0;
        uVar8 = 0;
        do {
          pbVar13 = *(byte **)((int)&PTR_DAT_006a1270 + uVar8);
          pbVar9 = local_10;
          do {
            bVar7 = *pbVar9;
            bVar16 = bVar7 < *pbVar13;
            if (bVar7 != *pbVar13) {
LAB_005e57ba:
              iVar10 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
              goto LAB_005e57bf;
            }
            if (bVar7 == 0) break;
            bVar7 = pbVar9[1];
            bVar16 = bVar7 < pbVar13[1];
            if (bVar7 != pbVar13[1]) goto LAB_005e57ba;
            pbVar9 = pbVar9 + 2;
            pbVar13 = pbVar13 + 2;
          } while (bVar7 != 0);
          iVar10 = 0;
LAB_005e57bf:
          if (iVar10 == 0) break;
          uVar8 = uVar8 + 0x44;
          iVar14 = iVar14 + 1;
        } while (uVar8 < 0x1650);
        if (iVar14 == 0x54) goto LAB_005e6030;
        iVar10 = *(int *)(param_1 + 0x38);
        uVar8 = *(uint *)(&DAT_006a1278 + (iVar14 * 0x11 + iVar10) * 4);
        if (uVar8 < 0xfffffffb) {
          if (uVar8 == 0xfffffffa) {
            local_50 = 0x10c;
          }
          else if (uVar8 == 0) {
            local_50 = 0x102;
          }
          else if (uVar8 == 1) {
            local_50 = 0x103;
          }
          else if (uVar8 == 2) {
            local_50 = 0x104;
          }
          else if (uVar8 == 3) {
            local_50 = 0x105;
          }
          else if (uVar8 == 4) {
            local_50 = 0x106;
          }
          else if (uVar8 == 5) {
            local_50 = 0x107;
          }
        }
        else if (uVar8 == 0xfffffffb) {
          local_50 = 0x10b;
        }
        else if (uVar8 == 0xfffffffc) {
          local_50 = 0x10a;
        }
        else if (uVar8 == 0xfffffffd) {
          local_50 = 0x108;
        }
        else if (uVar8 == 0xfffffffe) {
          local_50 = 0x109;
        }
        else if (uVar8 == 0xffffffff) {
          *(undefined4 *)(param_1 + 0x54) = 0x7e7;
          goto LAB_005e6030;
        }
        bVar16 = false;
        local_44 = (&DAT_006a1274)[iVar14 * 0x11];
        if ((((5 < iVar10) && (iVar10 < 10)) && (0x102 < local_50)) && (local_50 < 0x108)) {
          bVar18 = true;
        }
        if ((((3 < iVar10) && (iVar10 < 6)) || ((5 < iVar10 && (iVar10 < 0xf)))) &&
           ((0x102 < local_50 && (local_50 < 0x108)))) {
          bVar1 = true;
        }
        if (((0xc < iVar10) && (iVar10 < 0xf)) &&
           ((local_44 == 0x5b || (((local_44 == 0x5c || (local_44 == 0x1f)) || (local_44 == 0x42))))
           )) {
          bVar2 = true;
        }
        if (((9 < iVar10) && (iVar10 < 0xf)) && ((0x102 < local_50 && (local_50 < 0x108)))) {
          bVar3 = true;
        }
        if ((((3 < iVar10) && (iVar10 < 6)) || ((9 < iVar10 && (iVar10 < 0xf)))) &&
           (local_44 == 0x1f)) {
          bVar19 = true;
        }
        if (((0xc < iVar10) && (iVar10 < 0xf)) && (local_44 == 0x1f)) {
          bVar4 = true;
        }
        if (((-1 < iVar10) && (iVar10 < 6)) && (local_44 == 0x1f)) {
          bVar5 = true;
        }
        if (((local_44 == 0x28) || (local_44 == 0x2c)) || (local_44 == 0x5e)) {
          bVar20 = true;
        }
        *(undefined4 *)(param_1 + 0x54) = 0x7e8;
      }
      else {
        if (bVar1) {
          iVar10 = 4;
          bVar17 = true;
          pbVar9 = local_10;
          pbVar13 = &DAT_006a3350;
          do {
            if (iVar10 == 0) break;
            iVar10 = iVar10 + -1;
            bVar17 = *pbVar9 == *pbVar13;
            pbVar9 = pbVar9 + 1;
            pbVar13 = pbVar13 + 1;
          } while (bVar17);
          if (bVar17) {
            local_4c = local_4c | 0x100000;
            bVar18 = false;
            bVar1 = false;
            goto LAB_005e5fb8;
          }
        }
        if (bVar2) {
          iVar10 = 9;
          bVar17 = true;
          pbVar9 = local_10;
          pbVar13 = (byte *)"centroid";
          do {
            if (iVar10 == 0) break;
            iVar10 = iVar10 + -1;
            bVar17 = *pbVar9 == *pbVar13;
            pbVar9 = pbVar9 + 1;
            pbVar13 = pbVar13 + 1;
          } while (bVar17);
          if (bVar17) {
            local_4c = local_4c | 0x400000;
            bVar2 = false;
            goto LAB_005e5fb8;
          }
        }
        if (bVar18) {
          bVar18 = true;
          iVar10 = iVar14;
          pbVar9 = local_10;
          pbVar13 = &DAT_006a3340;
          do {
            if (iVar10 == 0) break;
            iVar10 = iVar10 + -1;
            bVar18 = *pbVar9 == *pbVar13;
            pbVar9 = pbVar9 + 1;
            pbVar13 = pbVar13 + 1;
          } while (bVar18);
          if (bVar18) {
            local_4c = 0x3000000;
          }
          else {
            bVar18 = true;
            iVar10 = iVar14;
            pbVar9 = local_10;
            pbVar13 = &DAT_006a333c;
            do {
              if (iVar10 == 0) break;
              iVar10 = iVar10 + -1;
              bVar18 = *pbVar9 == *pbVar13;
              pbVar9 = pbVar9 + 1;
              pbVar13 = pbVar13 + 1;
            } while (bVar18);
            if (bVar18) {
              local_4c = 0x2000000;
            }
            else {
              bVar18 = true;
              iVar10 = iVar14;
              pbVar9 = local_10;
              pbVar13 = &DAT_006a3338;
              do {
                if (iVar10 == 0) break;
                iVar10 = iVar10 + -1;
                bVar18 = *pbVar9 == *pbVar13;
                pbVar9 = pbVar9 + 1;
                pbVar13 = pbVar13 + 1;
              } while (bVar18);
              if (bVar18) {
                local_4c = 0x1000000;
              }
              else {
                bVar18 = true;
                iVar10 = iVar14;
                pbVar9 = local_10;
                pbVar13 = &DAT_006a3334;
                do {
                  if (iVar10 == 0) break;
                  iVar10 = iVar10 + -1;
                  bVar18 = *pbVar9 == *pbVar13;
                  pbVar9 = pbVar9 + 1;
                  pbVar13 = pbVar13 + 1;
                } while (bVar18);
                if (bVar18) {
                  local_4c = 0xf000000;
                }
                else {
                  bVar18 = true;
                  iVar10 = iVar14;
                  pbVar9 = local_10;
                  pbVar13 = &DAT_006a3330;
                  do {
                    if (iVar10 == 0) break;
                    iVar10 = iVar10 + -1;
                    bVar18 = *pbVar9 == *pbVar13;
                    pbVar9 = pbVar9 + 1;
                    pbVar13 = pbVar13 + 1;
                  } while (bVar18);
                  if (bVar18) {
                    local_4c = 0xe000000;
                  }
                  else {
                    bVar18 = true;
                    pbVar9 = local_10;
                    pbVar13 = &DAT_006a332c;
                    do {
                      if (iVar14 == 0) break;
                      iVar14 = iVar14 + -1;
                      bVar18 = *pbVar9 == *pbVar13;
                      pbVar9 = pbVar9 + 1;
                      pbVar13 = pbVar13 + 1;
                    } while (bVar18);
                    if (!bVar18) goto LAB_005e6030;
                    local_4c = 0xd000000;
                  }
                }
              }
            }
          }
          bVar18 = false;
        }
        else {
          if (bVar19) {
            uVar8 = 0;
            bVar19 = true;
            iVar10 = iVar14;
            pbVar9 = local_10;
            pbVar13 = &DAT_006c7acc;
            do {
              if (iVar10 == 0) break;
              iVar10 = iVar10 + -1;
              bVar19 = *pbVar9 == *pbVar13;
              pbVar9 = pbVar9 + 1;
              pbVar13 = pbVar13 + 1;
            } while (bVar19);
            if (bVar19) {
              uVar8 = 0x10000000;
            }
            else {
              iVar10 = 5;
              bVar19 = true;
              pbVar9 = local_10;
              pbVar13 = &DAT_006a3324;
              do {
                if (iVar10 == 0) break;
                iVar10 = iVar10 + -1;
                bVar19 = *pbVar9 == *pbVar13;
                pbVar9 = pbVar9 + 1;
                pbVar13 = pbVar13 + 1;
              } while (bVar19);
              if (bVar19) {
                uVar8 = 0x18000000;
              }
              else {
                iVar10 = 7;
                bVar19 = true;
                pbVar9 = local_10;
                pbVar13 = (byte *)"volume";
                do {
                  if (iVar10 == 0) break;
                  iVar10 = iVar10 + -1;
                  bVar19 = *pbVar9 == *pbVar13;
                  pbVar9 = pbVar9 + 1;
                  pbVar13 = pbVar13 + 1;
                } while (bVar19);
                if (bVar19) {
                  uVar8 = 0x20000000;
                }
              }
            }
            local_48 = local_48 | uVar8;
            bVar19 = false;
            if (uVar8 != 0) {
              bVar4 = false;
              bVar5 = false;
              goto LAB_005e5fb8;
            }
          }
          if (bVar3) {
            bVar17 = true;
            pbVar9 = local_10;
            pbVar13 = &DAT_006a3318;
            do {
              if (iVar14 == 0) break;
              iVar14 = iVar14 + -1;
              bVar17 = *pbVar9 == *pbVar13;
              pbVar9 = pbVar9 + 1;
              pbVar13 = pbVar13 + 1;
            } while (bVar17);
            if (bVar17) {
              local_4c = local_4c | 0x200000;
              bVar3 = false;
              goto LAB_005e5fb8;
            }
          }
          if (bVar4) {
            pbVar9 = local_10;
            if (local_10[0] == 0) {
LAB_005e5b74:
              uVar8 = 0;
            }
            else {
              do {
                iVar14 = _isalpha((int)(char)*pbVar9);
                if (iVar14 == 0) break;
                pbVar9 = pbVar9 + 1;
              } while (*pbVar9 != 0);
              if (*pbVar9 == 0) goto LAB_005e5b74;
              uVar8 = _atoi((char *)pbVar9);
            }
            if (uVar8 < 0x10) {
              bVar7 = *pbVar9;
              pbVar13 = pbVar9;
              if (bVar7 != 0) {
                *pbVar9 = 0;
                pbVar13 = pbVar9 + 1;
              }
              bVar6 = *pbVar13;
              if (bVar6 == 0) {
LAB_005e5bb1:
                iVar14 = 9;
                uVar11 = 0;
                bVar17 = true;
                pbVar13 = local_10;
                pbVar15 = (byte *)"position";
                do {
                  if (iVar14 == 0) break;
                  iVar14 = iVar14 + -1;
                  bVar17 = *pbVar13 == *pbVar15;
                  pbVar13 = pbVar13 + 1;
                  pbVar15 = pbVar15 + 1;
                } while (bVar17);
                if (bVar17) {
                  if (uVar8 == 0) goto LAB_005e5d21;
                }
                else {
                  iVar14 = 0xc;
                  bVar17 = true;
                  pbVar13 = local_10;
                  pbVar15 = (byte *)"blendweight";
                  do {
                    if (iVar14 == 0) break;
                    iVar14 = iVar14 + -1;
                    bVar17 = *pbVar13 == *pbVar15;
                    pbVar13 = pbVar13 + 1;
                    pbVar15 = pbVar15 + 1;
                  } while (bVar17);
                  if (bVar17) {
                    uVar11 = 1;
                  }
                  else {
                    iVar14 = 0xd;
                    bVar17 = true;
                    pbVar13 = local_10;
                    pbVar15 = (byte *)"blendindices";
                    do {
                      if (iVar14 == 0) break;
                      iVar14 = iVar14 + -1;
                      bVar17 = *pbVar13 == *pbVar15;
                      pbVar13 = pbVar13 + 1;
                      pbVar15 = pbVar15 + 1;
                    } while (bVar17);
                    if (bVar17) {
                      uVar11 = 2;
                    }
                    else {
                      iVar14 = 7;
                      bVar17 = true;
                      pbVar13 = local_10;
                      pbVar15 = (byte *)"normal";
                      do {
                        if (iVar14 == 0) break;
                        iVar14 = iVar14 + -1;
                        bVar17 = *pbVar13 == *pbVar15;
                        pbVar13 = pbVar13 + 1;
                        pbVar15 = pbVar15 + 1;
                      } while (bVar17);
                      if (bVar17) {
                        uVar11 = 3;
                      }
                      else {
                        uVar11 = 6;
                        bVar17 = true;
                        uVar12 = uVar11;
                        pbVar13 = local_10;
                        pbVar15 = (byte *)"psize";
                        do {
                          if (uVar12 == 0) break;
                          uVar12 = uVar12 - 1;
                          bVar17 = *pbVar13 == *pbVar15;
                          pbVar13 = pbVar13 + 1;
                          pbVar15 = pbVar15 + 1;
                        } while (bVar17);
                        if (bVar17) {
                          uVar11 = 4;
                        }
                        else {
                          iVar14 = 9;
                          bVar17 = true;
                          pbVar13 = local_10;
                          pbVar15 = (byte *)"texcoord";
                          do {
                            if (iVar14 == 0) break;
                            iVar14 = iVar14 + -1;
                            bVar17 = *pbVar13 == *pbVar15;
                            pbVar13 = pbVar13 + 1;
                            pbVar15 = pbVar15 + 1;
                          } while (bVar17);
                          if (bVar17) {
                            uVar11 = 5;
                          }
                          else {
                            iVar14 = 8;
                            bVar17 = true;
                            pbVar13 = local_10;
                            pbVar15 = (byte *)"tangent";
                            do {
                              if (iVar14 == 0) break;
                              iVar14 = iVar14 + -1;
                              bVar17 = *pbVar13 == *pbVar15;
                              pbVar13 = pbVar13 + 1;
                              pbVar15 = pbVar15 + 1;
                            } while (bVar17);
                            if (!bVar17) {
                              iVar14 = 9;
                              bVar17 = true;
                              pbVar13 = local_10;
                              pbVar15 = (byte *)"binormal";
                              do {
                                if (iVar14 == 0) break;
                                iVar14 = iVar14 + -1;
                                bVar17 = *pbVar13 == *pbVar15;
                                pbVar13 = pbVar13 + 1;
                                pbVar15 = pbVar15 + 1;
                              } while (bVar17);
                              if (bVar17) {
                                uVar11 = 7;
                              }
                              else {
                                iVar14 = 0xb;
                                bVar17 = true;
                                pbVar13 = local_10;
                                pbVar15 = (byte *)"tessfactor";
                                do {
                                  if (iVar14 == 0) break;
                                  iVar14 = iVar14 + -1;
                                  bVar17 = *pbVar13 == *pbVar15;
                                  pbVar13 = pbVar13 + 1;
                                  pbVar15 = pbVar15 + 1;
                                } while (bVar17);
                                if (bVar17) {
                                  uVar11 = 8;
                                }
                                else {
                                  uVar11 = 10;
                                  bVar17 = true;
                                  uVar12 = uVar11;
                                  pbVar13 = local_10;
                                  pbVar15 = (byte *)"positiont";
                                  do {
                                    if (uVar12 == 0) break;
                                    uVar12 = uVar12 - 1;
                                    bVar17 = *pbVar13 == *pbVar15;
                                    pbVar13 = pbVar13 + 1;
                                    pbVar15 = pbVar15 + 1;
                                  } while (bVar17);
                                  if (bVar17) {
                                    uVar11 = 9;
                                  }
                                  else {
                                    iVar14 = 6;
                                    bVar17 = true;
                                    pbVar13 = local_10;
                                    pbVar15 = (byte *)"color";
                                    do {
                                      if (iVar14 == 0) break;
                                      iVar14 = iVar14 + -1;
                                      bVar17 = *pbVar13 == *pbVar15;
                                      pbVar13 = pbVar13 + 1;
                                      pbVar15 = pbVar15 + 1;
                                    } while (bVar17);
                                    if (!bVar17) {
                                      iVar14 = 4;
                                      bVar17 = true;
                                      pbVar13 = local_10;
                                      pbVar15 = &DAT_006a32a8;
                                      do {
                                        if (iVar14 == 0) break;
                                        iVar14 = iVar14 + -1;
                                        bVar17 = *pbVar13 == *pbVar15;
                                        pbVar13 = pbVar13 + 1;
                                        pbVar15 = pbVar15 + 1;
                                      } while (bVar17);
                                      if (bVar17) {
                                        uVar11 = 0xb;
                                      }
                                      else {
                                        iVar14 = 6;
                                        bVar17 = true;
                                        pbVar13 = local_10;
                                        pbVar15 = (byte *)"depth";
                                        do {
                                          if (iVar14 == 0) break;
                                          iVar14 = iVar14 + -1;
                                          bVar17 = *pbVar13 == *pbVar15;
                                          pbVar13 = pbVar13 + 1;
                                          pbVar15 = pbVar15 + 1;
                                        } while (bVar17);
                                        if (bVar17) {
                                          uVar11 = 0xc;
                                        }
                                        else {
                                          iVar14 = 7;
                                          bVar17 = true;
                                          pbVar13 = local_10;
                                          pbVar15 = (byte *)"sample";
                                          do {
                                            if (iVar14 == 0) break;
                                            iVar14 = iVar14 + -1;
                                            bVar17 = *pbVar13 == *pbVar15;
                                            pbVar13 = pbVar13 + 1;
                                            pbVar15 = pbVar15 + 1;
                                          } while (bVar17);
                                          if (!bVar17) goto LAB_005e5d21;
                                          uVar11 = 0xd;
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                bVar4 = false;
                local_48 = local_48 | (uVar8 & 0xf) << 0x10 | uVar11;
                bVar19 = false;
                goto LAB_005e5fb8;
              }
              do {
                iVar14 = _isdigit((int)(char)bVar6);
                if (iVar14 == 0) break;
                pbVar13 = pbVar13 + 1;
                bVar6 = *pbVar13;
              } while (bVar6 != 0);
              if (*pbVar13 == 0) goto LAB_005e5bb1;
LAB_005e5d21:
              *pbVar9 = bVar7;
            }
          }
          iVar14 = 3;
          if (bVar5) {
            pbVar9 = local_10;
            if (local_10[0] == 0) {
LAB_005e5d69:
              uVar8 = 0;
            }
            else {
              do {
                iVar14 = _isalpha((int)(char)*pbVar9);
                if (iVar14 == 0) break;
                pbVar9 = pbVar9 + 1;
              } while (*pbVar9 != 0);
              if (*pbVar9 == 0) goto LAB_005e5d69;
              uVar8 = _atoi((char *)pbVar9);
            }
            if (0xf < uVar8) goto LAB_005e6030;
            if (*pbVar9 != 0) {
              *pbVar9 = 0;
              pbVar9 = pbVar9 + 1;
            }
            bVar7 = *pbVar9;
            if (bVar7 != 0) {
              do {
                iVar14 = _isdigit((int)(char)bVar7);
                if (iVar14 == 0) break;
                pbVar9 = pbVar9 + 1;
                bVar7 = *pbVar9;
              } while (bVar7 != 0);
              if (*pbVar9 != 0) goto LAB_005e6030;
            }
            iVar14 = 9;
            local_48 = 0;
            bVar19 = true;
            pbVar9 = local_10;
            pbVar13 = (byte *)"position";
            do {
              if (iVar14 == 0) break;
              iVar14 = iVar14 + -1;
              bVar19 = *pbVar9 == *pbVar13;
              pbVar9 = pbVar9 + 1;
              pbVar13 = pbVar13 + 1;
            } while (bVar19);
            if (!bVar19) {
              iVar14 = 0xc;
              bVar19 = true;
              pbVar9 = local_10;
              pbVar13 = (byte *)"blendweight";
              do {
                if (iVar14 == 0) break;
                iVar14 = iVar14 + -1;
                bVar19 = *pbVar9 == *pbVar13;
                pbVar9 = pbVar9 + 1;
                pbVar13 = pbVar13 + 1;
              } while (bVar19);
              if (bVar19) {
                local_48 = 1;
              }
              else {
                iVar14 = 0xd;
                bVar19 = true;
                pbVar9 = local_10;
                pbVar13 = (byte *)"blendindices";
                do {
                  if (iVar14 == 0) break;
                  iVar14 = iVar14 + -1;
                  bVar19 = *pbVar9 == *pbVar13;
                  pbVar9 = pbVar9 + 1;
                  pbVar13 = pbVar13 + 1;
                } while (bVar19);
                if (bVar19) {
                  local_48 = 2;
                }
                else {
                  iVar14 = 7;
                  bVar19 = true;
                  pbVar9 = local_10;
                  pbVar13 = (byte *)"normal";
                  do {
                    if (iVar14 == 0) break;
                    iVar14 = iVar14 + -1;
                    bVar19 = *pbVar9 == *pbVar13;
                    pbVar9 = pbVar9 + 1;
                    pbVar13 = pbVar13 + 1;
                  } while (bVar19);
                  if (bVar19) {
                    local_48 = 3;
                  }
                  else {
                    local_48 = 6;
                    bVar19 = true;
                    uVar11 = local_48;
                    pbVar9 = local_10;
                    pbVar13 = (byte *)"psize";
                    do {
                      if (uVar11 == 0) break;
                      uVar11 = uVar11 - 1;
                      bVar19 = *pbVar9 == *pbVar13;
                      pbVar9 = pbVar9 + 1;
                      pbVar13 = pbVar13 + 1;
                    } while (bVar19);
                    if (bVar19) {
                      local_48 = 4;
                    }
                    else {
                      iVar14 = 9;
                      bVar19 = true;
                      pbVar9 = local_10;
                      pbVar13 = (byte *)"texcoord";
                      do {
                        if (iVar14 == 0) break;
                        iVar14 = iVar14 + -1;
                        bVar19 = *pbVar9 == *pbVar13;
                        pbVar9 = pbVar9 + 1;
                        pbVar13 = pbVar13 + 1;
                      } while (bVar19);
                      if (bVar19) {
                        local_48 = 5;
                      }
                      else {
                        iVar14 = 8;
                        bVar19 = true;
                        pbVar9 = local_10;
                        pbVar13 = (byte *)"tangent";
                        do {
                          if (iVar14 == 0) break;
                          iVar14 = iVar14 + -1;
                          bVar19 = *pbVar9 == *pbVar13;
                          pbVar9 = pbVar9 + 1;
                          pbVar13 = pbVar13 + 1;
                        } while (bVar19);
                        if (!bVar19) {
                          iVar14 = 9;
                          bVar19 = true;
                          pbVar9 = local_10;
                          pbVar13 = (byte *)"binormal";
                          do {
                            if (iVar14 == 0) break;
                            iVar14 = iVar14 + -1;
                            bVar19 = *pbVar9 == *pbVar13;
                            pbVar9 = pbVar9 + 1;
                            pbVar13 = pbVar13 + 1;
                          } while (bVar19);
                          if (bVar19) {
                            local_48 = 7;
                          }
                          else {
                            iVar14 = 0xb;
                            bVar19 = true;
                            pbVar9 = local_10;
                            pbVar13 = (byte *)"tessfactor";
                            do {
                              if (iVar14 == 0) break;
                              iVar14 = iVar14 + -1;
                              bVar19 = *pbVar9 == *pbVar13;
                              pbVar9 = pbVar9 + 1;
                              pbVar13 = pbVar13 + 1;
                            } while (bVar19);
                            if (bVar19) {
                              local_48 = 8;
                            }
                            else {
                              local_48 = 10;
                              bVar19 = true;
                              uVar11 = local_48;
                              pbVar9 = local_10;
                              pbVar13 = (byte *)"positiont";
                              do {
                                if (uVar11 == 0) break;
                                uVar11 = uVar11 - 1;
                                bVar19 = *pbVar9 == *pbVar13;
                                pbVar9 = pbVar9 + 1;
                                pbVar13 = pbVar13 + 1;
                              } while (bVar19);
                              if (bVar19) {
                                local_48 = 9;
                              }
                              else {
                                iVar14 = 6;
                                bVar19 = true;
                                pbVar9 = local_10;
                                pbVar13 = (byte *)"color";
                                do {
                                  if (iVar14 == 0) break;
                                  iVar14 = iVar14 + -1;
                                  bVar19 = *pbVar9 == *pbVar13;
                                  pbVar9 = pbVar9 + 1;
                                  pbVar13 = pbVar13 + 1;
                                } while (bVar19);
                                if (!bVar19) {
                                  iVar14 = 4;
                                  bVar19 = true;
                                  pbVar9 = local_10;
                                  pbVar13 = &DAT_006a32a8;
                                  do {
                                    if (iVar14 == 0) break;
                                    iVar14 = iVar14 + -1;
                                    bVar19 = *pbVar9 == *pbVar13;
                                    pbVar9 = pbVar9 + 1;
                                    pbVar13 = pbVar13 + 1;
                                  } while (bVar19);
                                  if (bVar19) {
                                    local_48 = 0xb;
                                  }
                                  else {
                                    iVar14 = 6;
                                    bVar19 = true;
                                    pbVar9 = local_10;
                                    pbVar13 = (byte *)"depth";
                                    do {
                                      if (iVar14 == 0) break;
                                      iVar14 = iVar14 + -1;
                                      bVar19 = *pbVar9 == *pbVar13;
                                      pbVar9 = pbVar9 + 1;
                                      pbVar13 = pbVar13 + 1;
                                    } while (bVar19);
                                    if (bVar19) {
                                      local_48 = 0xc;
                                    }
                                    else {
                                      iVar14 = 7;
                                      bVar19 = true;
                                      pbVar9 = local_10;
                                      pbVar13 = (byte *)"sample";
                                      do {
                                        if (iVar14 == 0) break;
                                        iVar14 = iVar14 + -1;
                                        bVar19 = *pbVar9 == *pbVar13;
                                        pbVar9 = pbVar9 + 1;
                                        pbVar13 = pbVar13 + 1;
                                      } while (bVar19);
                                      if (!bVar19) goto LAB_005e6030;
                                      local_48 = 0xd;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            bVar5 = false;
            local_48 = (uVar8 & 0xf) << 0x10 | local_48;
            bVar19 = false;
          }
          else {
            if (!bVar20) goto LAB_005e6030;
            bVar20 = true;
            iVar10 = iVar14;
            pbVar9 = local_10;
            pbVar13 = &DAT_006a3294;
            do {
              if (iVar10 == 0) break;
              iVar10 = iVar10 + -1;
              bVar20 = *pbVar9 == *pbVar13;
              pbVar9 = pbVar9 + 1;
              pbVar13 = pbVar13 + 1;
            } while (bVar20);
            if (bVar20) {
              local_48 = 1;
            }
            else {
              bVar20 = true;
              iVar10 = iVar14;
              pbVar9 = local_10;
              pbVar13 = &DAT_006a3290;
              do {
                if (iVar10 == 0) break;
                iVar10 = iVar10 + -1;
                bVar20 = *pbVar9 == *pbVar13;
                pbVar9 = pbVar9 + 1;
                pbVar13 = pbVar13 + 1;
              } while (bVar20);
              if (bVar20) {
                local_48 = 2;
              }
              else {
                bVar20 = true;
                iVar10 = iVar14;
                pbVar9 = local_10;
                pbVar13 = &DAT_006a328c;
                do {
                  if (iVar10 == 0) break;
                  iVar10 = iVar10 + -1;
                  bVar20 = *pbVar9 == *pbVar13;
                  pbVar9 = pbVar9 + 1;
                  pbVar13 = pbVar13 + 1;
                } while (bVar20);
                if (bVar20) {
                  local_48 = 3;
                }
                else {
                  bVar20 = true;
                  iVar10 = iVar14;
                  pbVar9 = local_10;
                  pbVar13 = &DAT_006a3288;
                  do {
                    if (iVar10 == 0) break;
                    iVar10 = iVar10 + -1;
                    bVar20 = *pbVar9 == *pbVar13;
                    pbVar9 = pbVar9 + 1;
                    pbVar13 = pbVar13 + 1;
                  } while (bVar20);
                  if (bVar20) {
                    local_48 = 4;
                  }
                  else {
                    bVar20 = true;
                    iVar10 = iVar14;
                    pbVar9 = local_10;
                    pbVar13 = &DAT_006a3284;
                    do {
                      if (iVar10 == 0) break;
                      iVar10 = iVar10 + -1;
                      bVar20 = *pbVar9 == *pbVar13;
                      pbVar9 = pbVar9 + 1;
                      pbVar13 = pbVar13 + 1;
                    } while (bVar20);
                    if (bVar20) {
                      local_48 = 5;
                    }
                    else {
                      bVar20 = true;
                      pbVar9 = local_10;
                      pbVar13 = &DAT_006a3280;
                      do {
                        if (iVar14 == 0) break;
                        iVar14 = iVar14 + -1;
                        bVar20 = *pbVar9 == *pbVar13;
                        pbVar9 = pbVar9 + 1;
                        pbVar13 = pbVar13 + 1;
                      } while (bVar20);
                      if (!bVar20) goto LAB_005e6030;
                      local_48 = 6;
                    }
                  }
                }
              }
            }
            bVar20 = false;
          }
        }
      }
LAB_005e5fb8:
      local_20 = param_2;
    } while (*param_2 != 0);
    if (local_44 == 0x28) {
      if (bVar20) goto LAB_005e6029;
      if (*(int *)(&DAT_006a28c8 + *(int *)(param_1 + 0x38) * 4) != -1) {
        local_44 = 0x29;
        local_50 = 0x10c;
        goto LAB_005e5ff0;
      }
    }
    else {
LAB_005e5ff0:
      if (local_44 == 0x2c) {
        if (bVar20) goto LAB_005e6029;
        if (*(int *)(&DAT_006a2910 + *(int *)(param_1 + 0x38) * 4) == -1) goto LAB_005e6030;
        local_44 = 0x2d;
        local_50 = 0x10c;
      }
      if ((local_44 != 0x5e) || (!bVar20)) {
LAB_005e6029:
        if (!bVar5) goto LAB_005e6037;
      }
    }
LAB_005e6030:
    local_50 = 0x10d;
  }
  return local_50;
}


// ==== 0x5e605e FUN_005e605e

uint __thiscall FUN_005e605e(undefined4 *param_1,int param_2)

{
  char *pcVar1;
  uint uVar2;
  char cVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 *local_8;
  
  pcVar1 = *(char **)(param_2 + 8);
  uVar2 = 0;
  if ((pcVar1 == (char *)0x0) ||
     (cVar3 = *pcVar1, pcVar5 = pcVar1, local_8 = param_1, cVar3 == '\0')) {
    uVar2 = 0xf0000;
  }
  else {
    do {
      if (cVar3 < 'x') {
        if ((cVar3 == 'w') || (cVar3 == 'a')) {
          puVar4 = (undefined4 *)0x3;
          uVar2 = uVar2 | 0x80000;
        }
        else {
          if (cVar3 != 'b') {
            if (cVar3 == 'g') goto LAB_005e60d9;
            if (cVar3 != 'r') goto LAB_005e60e3;
            goto LAB_005e609e;
          }
LAB_005e60cf:
          puVar4 = (undefined4 *)0x2;
          uVar2 = uVar2 | 0x40000;
        }
      }
      else if (cVar3 == 'x') {
LAB_005e609e:
        puVar4 = (undefined4 *)0x0;
        uVar2 = uVar2 | 0x10000;
      }
      else {
        if (cVar3 != 'y') {
          if (cVar3 != 'z') goto LAB_005e60e3;
          goto LAB_005e60cf;
        }
LAB_005e60d9:
        puVar4 = (undefined4 *)0x1;
        uVar2 = uVar2 | 0x20000;
      }
      if ((pcVar5 != pcVar1) && (puVar4 <= local_8)) {
LAB_005e60e3:
        FUN_005b1f01(*param_1,param_2,0x7d3,"invalid mask \'%s\'",pcVar1);
        param_1[0x13] = 1;
        return 0;
      }
      cVar3 = pcVar5[1];
      pcVar5 = pcVar5 + 1;
      local_8 = puVar4;
    } while (cVar3 != '\0');
  }
  return uVar2;
}


// ==== 0x5e6111 FUN_005e6111

uint __thiscall FUN_005e6111(undefined4 *param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  uint local_c;
  uint local_8;
  
  pcVar3 = *(char **)(param_2 + 8);
  iVar5 = 0;
  local_c = 0;
  if ((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) {
    local_c = 0xe40000;
  }
  else {
    local_8 = 0x10;
    pcVar4 = pcVar3;
    do {
      cVar2 = *pcVar4;
      if (cVar2 != '\0') {
        if (cVar2 < 'x') {
          if ((cVar2 == 'w') || (cVar2 == 'a')) {
            iVar5 = 3;
          }
          else {
            if (cVar2 != 'b') {
              if (cVar2 == 'g') goto LAB_005e61b5;
              if (cVar2 == 'r') goto LAB_005e6162;
              goto LAB_005e617e;
            }
LAB_005e61b1:
            iVar5 = 2;
          }
        }
        else if (cVar2 == 'x') {
LAB_005e6162:
          iVar5 = 0;
        }
        else {
          if (cVar2 != 'y') {
            if (cVar2 == 'z') goto LAB_005e61b1;
            goto LAB_005e617e;
          }
LAB_005e61b5:
          iVar5 = 1;
        }
        pcVar4 = pcVar4 + 1;
      }
      uVar1 = local_8 + 2;
      local_c = local_c | iVar5 << ((byte)local_8 & 0x1f);
      local_8 = uVar1;
    } while (uVar1 < 0x18);
    if (*pcVar4 != '\0') {
LAB_005e617e:
      FUN_005b1f01(*param_1,param_2,0x7d4,"invalid swizzle \'%s\'",pcVar3);
      param_1[0x13] = 1;
      local_c = 0;
    }
  }
  return local_c;
}


// ==== 0x5e61cb FUN_005e61cb

int __thiscall FUN_005e61cb(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    uVar2 = *(uint *)(param_1 + 100);
    if (uVar2 < *(uint *)(param_1 + 0x5c)) {
      *(int *)(param_1 + 0x30) = param_2;
      iVar3 = (**(code **)(*piVar1 + 0x10))
                        (piVar1,*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),
                         *(int *)(param_1 + 0x58) + uVar2 * 4,*(uint *)(param_1 + 0x5c) - uVar2);
      if (iVar3 < 0) {
        *(undefined4 *)(param_1 + 0x4c) = 1;
        *(undefined4 *)(param_1 + 0x50) = 1;
      }
      *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x5c);
      return iVar3;
    }
  }
  return 0;
}


// ==== 0x5e621b FUN_005e621b

undefined4 __thiscall FUN_005e621b(int param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  uVar4 = *(uint *)(param_1 + 0x60);
  uVar1 = *(int *)(param_1 + 0x5c) + param_2;
  if (uVar4 < uVar1) {
    if (uVar4 == 0) {
      uVar4 = 0x100;
    }
    if (uVar4 < uVar1) {
      do {
        uVar4 = uVar4 * 2;
      } while (uVar4 < (uint)(*(int *)(param_1 + 0x5c) + param_2));
    }
    puVar2 = _malloc(uVar4 << 2);
    if (puVar2 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
    puVar5 = *(undefined4 **)(param_1 + 0x58);
    puVar6 = puVar2;
    for (uVar1 = *(uint *)(param_1 + 0x5c) & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    _free(*(void **)(param_1 + 0x58));
    *(undefined4 **)(param_1 + 0x58) = puVar2;
    *(uint *)(param_1 + 0x60) = uVar4;
  }
  return 0;
}


// ==== 0x5e6299 FUN_005e6299

int __thiscall FUN_005e6299(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_005e621b(1);
  if (-1 < iVar1) {
    *(undefined4 *)(*(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x5c) * 4) = param_2;
    *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
    iVar1 = 0;
  }
  return iVar1;
}


// ==== 0x5e62bd FUN_005e62bd

int __thiscall FUN_005e62bd(undefined4 *param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  bool bVar9;
  bool bVar10;
  undefined4 uVar11;
  char *pcVar12;
  int *local_8;
  
  iVar4 = param_2;
  *(undefined4 *)(param_2 + 0x58) = param_1[0x17] << 2;
  iVar5 = *(int *)(param_2 + 0x30);
  local_8 = (int *)0x1;
  bVar9 = false;
  if (iVar5 == 0x1f) {
    local_8 = (int *)0x2;
  }
  if (param_1[0x1e] != 0) {
    if ((((iVar5 == 0x1a) || (iVar5 == 0x19)) || (iVar5 == 0x1c)) || (iVar5 == 0x1e)) {
      pcVar12 = "call, callnz, label, and ret instructions are not allowed in assembly fragments";
      uVar11 = 0x7e9;
LAB_005e6335:
      FUN_005b1f01(*param_1,param_2 + 0x10,uVar11,pcVar12);
      return -0x7fffbffb;
    }
    if (((((iVar5 == 0x14) || (iVar5 == 0x15)) ||
         ((iVar5 == 0x16 || ((iVar5 == 0x17 || (iVar5 == 0x18)))))) &&
        (*(int *)(param_2 + 0x48) != 0)) && (*(int *)(*(int *)(param_2 + 0x48) + 0x10) == 0)) {
      pcVar12 = "Matrices cannot be specified in temp registers with the fragment linker";
      uVar11 = 0x7ea;
      goto LAB_005e6335;
    }
  }
  iVar5 = *(int *)(param_2 + 0x3c);
  piVar8 = local_8;
  if ((iVar5 != 0) && (*(int *)(iVar5 + 4) == 0x12)) {
    bVar9 = *(int *)(iVar5 + 0x10) == -1;
    if (*(int *)(iVar5 + 0x14) != 0) {
      FUN_005b1f01(*param_1,param_2 + 0x10,0x7de,
                   "source modifiers are not allowed on destination parameters");
      param_1[0x13] = 1;
    }
    iVar5 = *(int *)(iVar5 + 0x28);
    piVar8 = (int *)((int)local_8 + 1);
    if (iVar5 != 0) {
      if (((int)param_1[0xe] < 4) || (5 < (int)param_1[0xe])) {
        FUN_005b1f01(*param_1,param_2 + 0x10,0x7d8,
                     "relative addressing of destination parameters is not supported in this shader version"
                    );
        param_1[0x13] = 1;
      }
      else {
        bVar9 = *(int *)(iVar5 + 0x10) == -1 || bVar9;
        if (*(int *)(iVar5 + 0x28) != 0) {
          FUN_005b1f01(*param_1,param_2 + 0x10,0x7d9,
                       "only one address register reference is allowed in a relative address expression"
                      );
          param_1[0x13] = 1;
        }
        piVar8 = (int *)((int)local_8 + 2);
      }
    }
  }
  local_8 = piVar8;
  if ((*(int *)(param_2 + 0x40) != 0) && (*(int *)(*(int *)(param_2 + 0x40) + 4) == 0x12)) {
    iVar5 = param_1[0xe];
    if (((-1 < iVar5) && (iVar5 < 2)) || ((5 < iVar5 && (iVar5 < 0xb)))) {
      FUN_005b1f01(*param_1,param_2 + 0x10,0x7e5,
                   "predicates are not supported in this shader version");
      param_1[0x13] = 1;
    }
    iVar5 = *(int *)(param_2 + 0x40);
    local_8 = (int *)((int)local_8 + 1);
    if (*(int *)(iVar5 + 0x10) == -1) {
      bVar9 = true;
    }
    if ((*(int *)(iVar5 + 0x14) != 0) && (*(int *)(iVar5 + 0x14) != 0xd000000)) {
      FUN_005b1f01(*param_1,param_2 + 0x10,0x7e3,"source modifiers are not allowed on predicates");
      param_1[0x13] = 1;
    }
    if (*(int *)(iVar5 + 0x28) != 0) {
      FUN_005b1f01(*param_1,param_2 + 0x10,0x7e4,
                   "relative addressing of predicates is not supported in this shader version");
      param_1[0x13] = 1;
    }
  }
  param_2 = 0;
  piVar8 = (int *)(iVar4 + 0x44);
  do {
    iVar5 = *piVar8;
    if (iVar5 == 0) break;
    iVar6 = *(int *)(iVar4 + 0x30);
    piVar1 = (int *)((int)local_8 + 1);
    if (((iVar6 != 0x51) && (iVar6 != 0x30)) && (iVar6 != 0x2f)) {
      if (*(int *)(iVar5 + 0x10) == -1) {
        bVar9 = true;
      }
      iVar5 = *(int *)(iVar5 + 0x28);
      if (iVar5 != 0) {
        if (*(int *)(iVar5 + 0x10) == -1) {
          bVar9 = true;
        }
        if (*(int *)(iVar5 + 0x28) != 0) {
          FUN_005b1f01(*param_1,iVar4 + 0x10,0x7d9,
                       "only one address register reference is allowed in a relative address expression"
                      );
          param_1[0x13] = 1;
        }
        if (param_1[0xe] != 0) {
          piVar1 = (int *)((int)local_8 + 2);
        }
      }
    }
    local_8 = piVar1;
    param_2 = param_2 + 1;
    piVar8 = piVar8 + 1;
  } while (param_2 < 4);
  iVar5 = FUN_005e621b(local_8);
  if (iVar5 < 0) {
    return iVar5;
  }
  iVar5 = param_1[0x17] + (int)local_8;
  uVar7 = *(uint *)(iVar4 + 0x30);
  if ((uVar7 != 3) ||
     (((iVar6 = param_1[0xe], iVar6 < 0 || (5 < iVar6)) && ((iVar6 < 10 || (0xe < iVar6))))))
  goto LAB_005e6665;
  iVar6 = *(int *)(iVar4 + 0x48);
  uVar2 = *(uint *)(iVar6 + 0x14);
  uVar11 = 0x7000000;
  uVar7 = 2;
  if (uVar2 < 0x7000001) {
    if (uVar2 == 0x7000000) {
      *(undefined4 *)(iVar6 + 0x14) = 0x8000000;
      goto LAB_005e6665;
    }
    if (uVar2 == 0) {
      *(undefined4 *)(iVar6 + 0x14) = 0x1000000;
      goto LAB_005e6665;
    }
    if (uVar2 == 0x1000000) {
      *(undefined4 *)(iVar6 + 0x14) = 0;
      goto LAB_005e6665;
    }
    uVar11 = 0x2000000;
    if (uVar2 == 0x2000000) {
      *(undefined4 *)(iVar6 + 0x14) = 0x3000000;
      goto LAB_005e6665;
    }
    if (uVar2 != 0x3000000) {
      uVar11 = 0x4000000;
      if (uVar2 == 0x4000000) {
        *(undefined4 *)(iVar6 + 0x14) = 0x5000000;
        goto LAB_005e6665;
      }
      if (uVar2 != 0x5000000) {
        bVar10 = uVar2 == 0x6000000;
        goto LAB_005e65d4;
      }
    }
  }
  else if (uVar2 != 0x8000000) {
    if ((uVar2 != 0x9000000) && (uVar2 != 0xa000000)) {
      uVar11 = 0xb000000;
      if (uVar2 == 0xb000000) {
        *(undefined4 *)(iVar6 + 0x14) = 0xc000000;
        goto LAB_005e6665;
      }
      if (uVar2 == 0xc000000) goto LAB_005e6662;
      bVar10 = uVar2 == 0xd000000;
LAB_005e65d4:
      if (!bVar10) goto LAB_005e6665;
    }
    FUN_005b1f01(*param_1,iVar4 + 0x10,0x7dd,"source modifiers incompatible with SUB instruction");
    param_1[0x13] = 1;
    goto LAB_005e6665;
  }
LAB_005e6662:
  *(undefined4 *)(iVar6 + 0x14) = uVar11;
LAB_005e6665:
  if (*(int *)(iVar4 + 0x54) != 0) {
    uVar7 = uVar7 | 0x40000000;
  }
  if (*(int *)(iVar4 + 0x40) != 0) {
    uVar7 = uVar7 | 0x10000000;
  }
  iVar6 = param_1[0xe];
  if (((0 < iVar6) && (iVar6 < 6)) || ((9 < iVar6 && (iVar6 < 0xf)))) {
    uVar7 = uVar7 | ((int)local_8 + -1) * 0x1000000;
  }
  iVar6 = *(int *)(iVar4 + 0x30);
  if (((iVar6 == 0x29) || (iVar6 == 0x2d)) || (iVar6 == 0x5e)) {
    uVar7 = uVar7 | (*(uint *)(iVar4 + 0x38) & 7) << 0x10;
  }
  *(uint *)(param_1[0x16] + param_1[0x17] * 4) = uVar7;
  param_1[0x17] = param_1[0x17] + 1;
  iVar6 = param_1[0x17];
  if (*(int *)(iVar4 + 0x30) == 0x1f) {
    *(uint *)(param_1[0x16] + iVar6 * 4) = *(uint *)(iVar4 + 0x38) | 0x80000000;
    param_1[0x17] = param_1[0x17] + 1;
    iVar6 = param_1[0x17];
  }
  iVar3 = *(int *)(iVar4 + 0x3c);
  if ((iVar3 != 0) && (*(int *)(iVar3 + 4) == 0x12)) {
    if ((param_1[0xe] == 0) && (*(int *)(iVar3 + 0x20) == 0xf0000)) {
      iVar6 = *(int *)(iVar4 + 0x30);
      if ((iVar6 == 0x15) || (iVar6 == 0x17)) {
        *(undefined4 *)(iVar3 + 0x20) = 0x70000;
      }
      else if (iVar6 == 0x18) {
        *(undefined4 *)(iVar3 + 0x20) = 0x30000;
      }
    }
    uVar7 = ((*(uint *)(iVar3 + 0x10) | 0xfffffff8) << 0x14 | *(uint *)(iVar3 + 0x10) & 0x18) << 8 |
            *(uint *)(iVar4 + 0x34) & 0xff00000 | *(uint *)(iVar3 + 0x18) & 0x7ff |
            *(uint *)(iVar3 + 0x20) & 0xf0000;
    if (*(int *)(iVar3 + 0x28) != 0) {
      uVar7 = uVar7 | 0x2000;
    }
    *(uint *)(param_1[0x16] + param_1[0x17] * 4) = uVar7;
    param_1[0x17] = param_1[0x17] + 1;
    iVar3 = *(int *)(iVar3 + 0x28);
    iVar6 = param_1[0x17];
    if (iVar3 != 0) {
      *(uint *)(param_1[0x16] + iVar6 * 4) =
           ((*(uint *)(iVar3 + 0x10) | 0xfffffff8) << 0x14 | *(uint *)(iVar3 + 0x10) & 0x18) << 8 |
           *(uint *)(iVar3 + 0x14) & 0xf000000 | *(uint *)(iVar3 + 0x18) & 0x7ff |
           *(uint *)(iVar3 + 0x24) & 0xff0000;
      param_1[0x17] = param_1[0x17] + 1;
      iVar6 = param_1[0x17];
    }
  }
  iVar3 = *(int *)(iVar4 + 0x40);
  if ((iVar3 != 0) && (*(int *)(iVar3 + 4) == 0x12)) {
    *(uint *)(param_1[0x16] + iVar6 * 4) =
         ((*(uint *)(iVar3 + 0x10) | 0xfffffff8) << 0x14 | *(uint *)(iVar3 + 0x10) & 0x18) << 8 |
         *(uint *)(iVar3 + 0x14) & 0xf000000 | *(uint *)(iVar3 + 0x18) & 0x7ff |
         *(uint *)(iVar3 + 0x24) & 0xff0000;
    param_1[0x17] = param_1[0x17] + 1;
    iVar6 = param_1[0x17];
  }
  iVar3 = *(int *)(iVar4 + 0x30);
  if (iVar3 == 0x51) {
    param_2 = 0;
    piVar8 = (int *)(iVar4 + 0x44);
    do {
      iVar3 = *piVar8;
      if (iVar3 == 0) break;
      if ((4 < *(int *)(iVar3 + 0x10)) && (*(int *)(iVar3 + 0x10) < 9)) {
        *(float *)(param_1[0x16] + iVar6 * 4) = (float)*(double *)(iVar3 + 0x18);
      }
      param_1[0x17] = param_1[0x17] + 1;
      param_2 = param_2 + 1;
      iVar6 = param_1[0x17];
      piVar8 = piVar8 + 1;
    } while (param_2 < 4);
  }
  else if (iVar3 == 0x30) {
    param_2 = 0;
    piVar8 = (int *)(iVar4 + 0x44);
    do {
      iVar3 = *piVar8;
      if (iVar3 == 0) break;
      if ((*(int *)(iVar3 + 0x10) == 2) || (*(int *)(iVar3 + 0x10) == 4)) {
        *(undefined4 *)(param_1[0x16] + iVar6 * 4) = *(undefined4 *)(iVar3 + 0x18);
      }
      param_1[0x17] = param_1[0x17] + 1;
      param_2 = param_2 + 1;
      iVar6 = param_1[0x17];
      piVar8 = piVar8 + 1;
    } while (param_2 < 4);
  }
  else if (iVar3 == 0x2f) {
    *(uint *)(param_1[0x16] + iVar6 * 4) = (uint)(*(int *)(*(int *)(iVar4 + 0x44) + 0x18) != 0);
    param_1[0x17] = param_1[0x17] + 1;
  }
  else {
    param_2 = 0;
    local_8 = (int *)(iVar4 + 0x44);
    do {
      iVar6 = *local_8;
      if (iVar6 == 0) break;
      if (((param_1[0xe] == 0) && (*(int *)(iVar6 + 0x24) == 0xe40000)) &&
         ((iVar3 = *(int *)(iVar4 + 0x30), iVar3 == 6 ||
          ((((iVar3 == 7 || (iVar3 == 0xe)) || (iVar3 == 0x4e)) ||
           ((iVar3 == 0xf || (iVar3 == 0x4f)))))))) {
        *(undefined4 *)(iVar6 + 0x24) = 0xff0000;
      }
      uVar7 = ((*(uint *)(iVar6 + 0x10) | 0xfffffff8) << 0x14 | *(uint *)(iVar6 + 0x10) & 0x18) << 8
              | *(uint *)(iVar6 + 0x14) & 0xf000000 | *(uint *)(iVar6 + 0x18) & 0x7ff |
              *(uint *)(iVar6 + 0x24) & 0xff0000;
      if (*(int *)(iVar6 + 0x28) != 0) {
        uVar7 = uVar7 | 0x2000;
      }
      *(uint *)(param_1[0x16] + param_1[0x17] * 4) = uVar7;
      param_1[0x17] = param_1[0x17] + 1;
      iVar6 = *(int *)(iVar6 + 0x28);
      if (iVar6 != 0) {
        if (param_1[0xe] == 0) {
          if (((*(int *)(iVar6 + 0x10) != 3) || (*(int *)(iVar6 + 0x14) != 0)) ||
             ((*(int *)(iVar6 + 0x18) != 0 || (*(int *)(iVar6 + 0x24) != 0)))) {
            FUN_005b1f01(*param_1,iVar4 + 0x10,0x7d7,
                         "only a0.x is allowed as a relative address register in vs_1_1");
            param_1[0x13] = 1;
          }
        }
        else {
          *(uint *)(param_1[0x16] + param_1[0x17] * 4) =
               ((*(uint *)(iVar6 + 0x10) | 0xfffffff8) << 0x14 | *(uint *)(iVar6 + 0x10) & 0x18) <<
               8 | *(uint *)(iVar6 + 0x14) & 0xf000000 | *(uint *)(iVar6 + 0x18) & 0x7ff |
               *(uint *)(iVar6 + 0x24) & 0xff0000;
          param_1[0x17] = param_1[0x17] + 1;
        }
      }
      param_2 = param_2 + 1;
      local_8 = local_8 + 1;
    } while (param_2 < 4);
  }
  if (param_1[0x17] != iVar5) {
    FUN_005b1f01(*param_1,iVar4 + 0x10,0,"internal error: instruction size mismatch");
    param_1[0x13] = 1;
  }
  if (bVar9) {
    param_1[0x19] = param_1[0x17];
  }
  else {
    iVar5 = FUN_005e61cb(iVar4 + 0x10);
    if (iVar5 < 0) {
      param_1[0x14] = 1;
    }
  }
  return 0;
}


// ==== 0x5e6a37 FUN_005e6a37

int FUN_005e6a37(undefined4 *param_1,undefined4 *param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  
  pbVar8 = *(byte **)*param_1;
  if ((((*(short *)pbVar8 == 0x5f76) || (*(short *)pbVar8 == 0x5f72)) ||
      (pbVar6 = *(byte **)*param_2, *(short *)pbVar6 == 0x5f76)) ||
     (pbVar3 = pbVar8, pbVar4 = pbVar6, *(short *)pbVar6 == 0x5f72)) {
    pbVar6 = *(byte **)*param_2;
    do {
      bVar1 = *pbVar8;
      bVar9 = bVar1 < *pbVar6;
      if (bVar1 != *pbVar6) goto LAB_005e6ab5;
      if (bVar1 == 0) break;
      bVar1 = pbVar8[1];
      bVar9 = bVar1 < pbVar6[1];
      if (bVar1 != pbVar6[1]) goto LAB_005e6ab5;
      pbVar8 = pbVar8 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
  }
  else {
    do {
      bVar1 = pbVar3[2];
      bVar2 = pbVar4[2];
      bVar9 = bVar1 < bVar2;
      if (bVar1 != bVar2) {
LAB_005e6aa0:
        iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_005e6aa5;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[3];
      bVar9 = bVar1 < pbVar4[3];
      if (bVar1 != pbVar4[3]) goto LAB_005e6aa0;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_005e6aa5:
    if (iVar5 == 0) {
      iVar7 = 2;
      bVar9 = false;
      iVar5 = 0;
      bVar10 = true;
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar9 = *pbVar8 < *pbVar6;
        bVar10 = *pbVar8 == *pbVar6;
        pbVar8 = pbVar8 + 1;
        pbVar6 = pbVar6 + 1;
      } while (bVar10);
      if (!bVar10) {
LAB_005e6ab5:
        iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
      }
    }
  }
  return iVar5;
}


// ==== 0x5e6ae3 FUN_005e6ae3

int __fastcall FUN_005e6ae3(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  uint local_2c;
  undefined4 local_28;
  undefined1 local_24 [16];
  void *local_14;
  undefined4 *local_10;
  uint local_c;
  undefined4 *local_8;
  
  iVar5 = 0;
  FUN_0061314d(0x464e4946);
  iVar1 = param_1[0x1e];
  local_14 = (void *)0x0;
  local_8 = (undefined4 *)0x0;
  iVar1 = *(int *)(iVar1 + 0x60) + *(int *)(iVar1 + 0x5c) + *(int *)(iVar1 + 0x58);
  if (iVar1 != 0) {
    pvVar2 = _malloc(iVar1 * 4);
    local_14 = pvVar2;
    if (pvVar2 == (void *)0x0) {
      iVar5 = -0x7ff8fff2;
    }
    else {
      FUN_005e552a(pvVar2);
      iVar1 = *(int *)(param_1[0x1e] + 0x60);
      FUN_005e552a((void *)((int)pvVar2 + iVar1 * 4));
      iVar1 = iVar1 + *(int *)(param_1[0x1e] + 0x58);
      FUN_005e552a((void *)((int)pvVar2 + iVar1 * 4));
      uVar4 = iVar1 + *(int *)(param_1[0x1e] + 0x5c);
      _qsort(pvVar2,uVar4,4,FUN_005e6a37);
      local_10 = (undefined4 *)(uVar4 * 0x14);
      local_8 = _malloc((size_t)local_10);
      if (local_8 == (undefined4 *)0x0) {
        iVar5 = -0x7ff8fff2;
      }
      else {
        local_34 = 0;
        local_28 = 0;
        local_30 = 0;
        local_38 = 0x14;
        local_2c = uVar4;
        iVar5 = FUN_0061319b(&local_38,0x14,1,0);
        if (-1 < iVar5) {
          puVar6 = local_8;
          for (uVar3 = (uint)local_10 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar6 = 0;
            puVar6 = puVar6 + 1;
          }
          for (uVar3 = (uint)local_10 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar6 = 0;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
          }
          iVar5 = FUN_0061319b(local_8,local_10,1,&local_28);
          if (-1 < iVar5) {
            local_c = 0;
            if (uVar4 != 0) {
              local_10 = local_8;
              do {
                puVar6 = *(undefined4 **)((int)local_14 + local_c * 4);
                iVar5 = FUN_005e8cd0(local_24,local_10,*puVar6,puVar6[1],
                                     *(undefined4 *)param_1[0x16]);
                if (iVar5 < 0) goto LAB_005e6ce3;
                local_c = local_c + 1;
                local_10 = local_10 + 5;
              } while (local_c < uVar4);
            }
            iVar5 = FUN_0061319b(PTR_s_D3DX9_Shader_Assembler_006def50,0xffffffff,5,&local_34);
            if (-1 < iVar5) {
              uVar4 = FUN_006132d2();
              if (uVar4 < 0x8001) {
                iVar5 = FUN_005e621b(uVar4);
                if (-1 < iVar5) {
                  _memmove((void *)(param_1[0x16] + 4 + uVar4 * 4),(void *)(param_1[0x16] + 4),
                           param_1[0x17] * 4 - 4);
                  iVar5 = FUN_006132de(param_1[0x16] + 4,uVar4);
                  if (-1 < iVar5) {
                    param_1[0x17] = param_1[0x17] + uVar4;
                    param_1[0x1a] = param_1[0x1a] + uVar4;
                    param_1[0x19] = param_1[0x17];
                    iVar5 = 0;
                  }
                }
              }
              else {
                FUN_005b1f01(*param_1,param_1 + 4,0x7ef,"fragment info exceeds maximum comment size"
                            );
                iVar5 = -0x7fffbffb;
              }
            }
          }
        }
      }
    }
  }
LAB_005e6ce3:
  _free(local_14);
  _free(local_8);
  FUN_00613165();
  return iVar5;
}


// ==== 0x5e6d03 FUN_005e6d03

int __fastcall FUN_005e6d03(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined2 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 local_54;
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  uint local_48;
  undefined1 local_44 [4];
  uint local_40;
  undefined1 local_3c [12];
  undefined1 local_30 [20];
  int local_1c;
  int local_18;
  uint local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  int local_8;
  
  FUN_0061314d(0x47554244);
  puVar7 = &local_54;
  for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  iVar4 = 0;
  local_54 = 0x28;
  local_10 = (undefined4 *)0x0;
  local_c = (undefined4 *)0x0;
  local_8 = FUN_0061319b(&local_54,0x28,1,0);
  if (local_8 < 0) goto LAB_005e6fc6;
  for (iVar1 = param_1[0xd]; iVar8 = iVar4, iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
    if ((*(int *)(iVar1 + 8) != 0) && (*(int *)(*(int *)(iVar1 + 8) + 4) == 0x11)) {
      iVar4 = *(int *)(iVar1 + 8);
      iVar8 = iVar4;
      break;
    }
  }
  for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xc)) {
    local_40 = local_40 + 1;
  }
  if (local_40 == 0) {
LAB_005e6ea4:
    if ((((param_1[0x1d] == 0) ||
         (local_8 = FUN_0061319b(param_1[0x1d],0xffffffff,7,local_30), -1 < local_8)) &&
        ((param_1[0x1b] == 0 ||
         ((iVar4 = FUN_0061319b(param_1[0x1b],param_1[0x1c],5,local_4c), -1 < iVar4 &&
          (iVar4 = FUN_0061319b(&DAT_006b9172,1,5,0), -1 < iVar4)))))) &&
       (iVar4 = FUN_0061319b(PTR_s_D3DX9_Shader_Assembler_006def50,0xffffffff,5,local_50),
       -1 < iVar4)) {
      uVar2 = FUN_006132d2();
      if (uVar2 < 0x8001) {
        local_8 = FUN_005e621b(uVar2);
        if (local_8 < 0) goto LAB_005e6fc6;
        _memmove((void *)(param_1[0x16] + 4 + uVar2 * 4),(void *)(param_1[0x16] + 4),
                 param_1[0x17] * 4 - 4);
        uVar5 = 0;
        if (local_40 != 0) {
          piVar3 = local_c + 1;
          do {
            *piVar3 = *piVar3 + (param_1[0x1a] + uVar2) * 4;
            uVar5 = uVar5 + 1;
            piVar3 = piVar3 + 2;
          } while (uVar5 < local_40);
        }
        local_8 = FUN_006132de(param_1[0x16] + 4,uVar2);
        if (local_8 < 0) goto LAB_005e6fc6;
        param_1[0x17] = param_1[0x17] + uVar2;
        param_1[0x1a] = param_1[0x1a] + uVar2;
        param_1[0x19] = param_1[0x17];
      }
      else {
        FUN_005b1fca(*param_1,param_1 + 4,0x7ee,
                     "debug info exceeds maximum comment size; no debug info emitted");
      }
      local_8 = 0;
    }
  }
  else {
    local_10 = _malloc(local_40 << 2);
    uVar2 = local_40;
    puVar7 = local_10;
    if (local_10 != (undefined4 *)0x0) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      local_c = _malloc(local_40 << 3);
      if (local_c != (undefined4 *)0x0) {
        local_1c = local_40 << 3;
        puVar7 = local_c;
        for (iVar4 = (local_40 & 0x1fffffff) << 1; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined1 *)puVar7 = 0;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        if (iVar8 != 0) {
          puVar6 = (undefined2 *)((int)local_c + local_40 * 8 + -6);
          do {
            *puVar6 = 0xffff;
            puVar6[-1] = *(undefined2 *)(iVar8 + 0x24);
            *(undefined4 *)(puVar6 + 1) = *(undefined4 *)(iVar8 + 0x58);
            if (*(int *)(iVar8 + 0x20) != 0) {
              iVar4 = FUN_0061319b(*(int *)(iVar8 + 0x20),0xffffffff,7,&local_18);
              if (iVar4 < 0) goto LAB_005e6fc6;
              local_14 = 0;
              if (local_48 != 0) {
                do {
                  if (local_10[local_14] == local_18) break;
                  local_14 = local_14 + 1;
                } while (local_14 < local_48);
              }
              if (local_14 == local_48) {
                local_10[local_48] = local_18;
                local_48 = local_48 + 1;
              }
              *puVar6 = (short)local_14;
            }
            iVar8 = *(int *)(iVar8 + 0xc);
            puVar6 = puVar6 + -4;
          } while (iVar8 != 0);
        }
        if (((local_48 != 0) &&
            (local_8 = FUN_0061319b(local_10,local_48 << 2,1,local_44), local_8 < 0)) ||
           (local_8 = FUN_0061319b(local_c,local_1c,1,local_3c), local_8 < 0)) goto LAB_005e6fc6;
        goto LAB_005e6ea4;
      }
    }
    local_8 = -0x7ff8fff2;
  }
LAB_005e6fc6:
  _free(local_10);
  _free(local_c);
  FUN_00613165();
  return local_8;
}


// ==== 0x5e6fe8 FUN_005e6fe8

void * __thiscall FUN_005e6fe8(void *param_1,byte param_2)

{
  FUN_005e7978();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5e7004 FUN_005e7004

void __fastcall FUN_005e7004(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (*(int *)(param_1 + uVar1 * 4) != 0) {
      FUN_005e6fe8(1);
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 7);
  return;
}


// ==== 0x5e7021 FUN_005e7021

int __thiscall FUN_005e7021(int *param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  int *local_8;
  
  local_8 = param_1;
  iVar1 = FUN_005d65b0(param_1[0x17] << 2,&local_8);
  if (-1 < iVar1) {
    uVar2 = (**(code **)(*local_8 + 0x10))(local_8);
    puVar5 = (undefined4 *)param_1[0x16];
    puVar3 = (undefined4 *)(**(code **)(*local_8 + 0xc))(local_8);
    for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar3 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar3 = puVar3 + 1;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar3 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
    *param_2 = local_8;
    iVar1 = 0;
  }
  return iVar1;
}


// ==== 0x5e7078 FUN_005e7078

undefined4 __thiscall FUN_005e7078(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 *puVar6;
  uint uVar7;
  char *pcVar8;
  
  iVar3 = FUN_005e54bc(param_2);
  pcVar4 = param_2;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  pcVar4 = pcVar4 + (1 - (int)(param_2 + 1));
  pcVar5 = _malloc((size_t)pcVar4);
  if (pcVar5 != (char *)0x0) {
    pcVar8 = pcVar5;
    for (uVar7 = (uint)pcVar4 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)param_2;
      param_2 = param_2 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar7 = (uint)pcVar4 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar8 = *param_2;
      param_2 = param_2 + 1;
      pcVar8 = pcVar8 + 1;
    }
    puVar6 = _malloc(0x24);
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + iVar3 * 4);
      puVar6[3] = 0;
      puVar6[1] = param_3;
      *puVar6 = pcVar5;
      puVar6[2] = param_4;
      puVar6[8] = uVar2;
    }
    if (puVar6 != (undefined4 *)0x0) {
      *(undefined4 **)(param_1 + iVar3 * 4) = puVar6;
      return 0;
    }
  }
  return 0x8007000e;
}


// ==== 0x5e710d FUN_005e710d

undefined4 * __fastcall FUN_005e710d(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = param_1 + 7;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = param_1 + 0xe;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x15] = 0;
  param_1[0x18] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  return param_1;
}


// ==== 0x5e7139 FUN_005e7139

void FUN_005e7139(void)

{
  FUN_005e7004();
  FUN_005e7004();
  FUN_005e7004();
  return;
}


// ==== 0x5e7154 FUN_005e7154

int __thiscall
FUN_005e7154(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,short *param_5,
            int param_6,int *param_7,undefined4 *param_8,int *param_9)

{
  undefined4 *puVar1;
  short sVar2;
  short *psVar3;
  int *piVar4;
  short *psVar5;
  int iVar6;
  char *pcVar7;
  
  piVar4 = param_9;
  psVar3 = param_5;
  psVar5 = param_5;
  do {
    sVar2 = *psVar5;
    psVar5 = (short *)((int)psVar5 + 1);
  } while ((char)sVar2 != '\0');
  if ((uint)((int)psVar5 - (int)((int)param_5 + 1)) < 3) {
    FUN_005b1f01(param_2,param_4,0x7d5,"invalid register, input, or constant name \'%s\'",param_5);
    return -0x7fffbffb;
  }
  *param_7 = 0;
  *param_8 = 0;
  *param_9 = 0;
  if (*param_5 == 0x5f76) {
    *param_7 = 1;
    iVar6 = FUN_005e54f8(param_5);
    if (iVar6 == 0) {
      iVar6 = FUN_005e5221(psVar3 + 1,(int)&param_7 + 3,(int)&param_5 + 3);
      if (iVar6 < 0) {
        pcVar7 = "Invalid input register \'%s\' specified";
        goto LAB_005e71e8;
      }
      *piVar4 = *(int *)(param_1 + 0x58);
      FUN_005e7078(psVar3,*(undefined4 *)(param_1 + 0x58),1);
      *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
    }
    else {
      *piVar4 = *(int *)(iVar6 + 4);
    }
    if (param_6 == 0) {
      return 0;
    }
    pcVar7 = "addressing operations are not allowed on input registers \'%s\'";
  }
  else if (*param_5 == 0x5f72) {
    *param_7 = 0;
    iVar6 = FUN_005e54f8(param_5);
    if (iVar6 == 0) {
      *piVar4 = *(int *)(param_1 + 0x5c);
      FUN_005e7078(psVar3,*(undefined4 *)(param_1 + 0x5c),1);
      *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
    }
    else {
      *piVar4 = *(int *)(iVar6 + 4);
    }
    if (param_6 == 0) {
      return 0;
    }
    pcVar7 = "addressing operations not allowed on temporary registers \'%s\'";
  }
  else {
    sVar2 = *param_5;
    if (((sVar2 == 0x5f63) || (sVar2 == 0x5f62)) || (sVar2 == 0x5f69)) {
      if (*param_5 == 0x5f62) {
        *param_7 = 0xe;
      }
      else {
        *param_7 = (-(uint)(*param_5 != 0x5f69) & 0xfffffffb) + 7;
      }
      iVar6 = FUN_005e54f8(param_5);
      if (iVar6 == 0) {
        iVar6 = FUN_005e8b19(param_4,psVar3,&param_8);
        if (iVar6 < 0) {
          return iVar6;
        }
        if (param_8 == (undefined4 *)0x0) {
          FUN_005b1f01(param_2,param_4,0x7d5,
                       "constant register \'%s\' must be defined as a variable \'%s\'",psVar3,
                       psVar3 + 1);
          return -0x7fffbffb;
        }
        *piVar4 = *(int *)(param_1 + 0x54);
        FUN_005e7078(psVar3,*(undefined4 *)(param_1 + 0x54),param_8);
        *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + (int)param_8;
        *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
      }
      else {
        *piVar4 = *(int *)(iVar6 + 4);
        param_8 = *(undefined4 **)(iVar6 + 8);
      }
      if (param_6 == 0) {
        return 0;
      }
      puVar1 = *(undefined4 **)(param_6 + 0x18);
      if (param_8 < puVar1) {
        FUN_005b1f01(param_2,param_4,0x7d5,
                     "constant register address out of bounds on constant \'%s\', size %d, offset %d"
                     ,psVar3,param_8,puVar1);
        return -0x7fffbffb;
      }
      *piVar4 = *piVar4 + (int)puVar1;
      return 0;
    }
    pcVar7 = 
    "\'%s\' is not a valid register name.  Registers must start with v_, r_, c_, b_, or i_ depending on the register type."
    ;
  }
LAB_005e71e8:
  FUN_005b1f01(param_2,param_4,0x7d5,pcVar7,psVar3);
  return -0x7fffbffb;
}


// ==== 0x5e737f FUN_005e737f

void * __thiscall FUN_005e737f(void *param_1,byte param_2)

{
  FUN_005e7139();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5e739b FUN_005e739b

int __fastcall FUN_005e739b(int param_1)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  piVar1 = (int *)(param_1 + 0x10);
  while( true ) {
    iVar2 = FUN_005c7bd2(piVar1);
    if (iVar2 < 0) {
      *(undefined4 *)(param_1 + 0x4c) = 1;
      *(undefined4 *)(param_1 + 0x50) = 1;
      return -1;
    }
    iVar2 = *piVar1;
    if (iVar2 < 10) break;
    if (iVar2 == 10) {
      return 0x110;
    }
    if (iVar2 != 0xc) {
      if (iVar2 != 0xd) {
        return 0x110;
      }
      return -1;
    }
  }
  if (iVar2 != 9) {
    if (iVar2 == 0) {
      return 0x110;
    }
    if (iVar2 == 1) {
      if (*(char *)(param_1 + 0x19) != '\0') {
        return 0x110;
      }
      return (int)*(char *)(param_1 + 0x18);
    }
    if (iVar2 < 2) {
      return 0x110;
    }
    if (4 < iVar2) {
      if (8 < iVar2) {
        return 0x110;
      }
      return 0x10f;
    }
    return 0x10e;
  }
  pcVar4 = *(char **)(param_1 + 0x18);
  iVar2 = 0xb;
  bVar6 = true;
  pcVar3 = pcVar4;
  pcVar5 = "entrypoint";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar3 == *pcVar5;
    pcVar3 = pcVar3 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    iVar2 = 0x101;
  }
  else {
    iVar2 = 5;
    bVar6 = true;
    pcVar3 = pcVar4;
    pcVar5 = "true";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar3 == *pcVar5;
      pcVar3 = pcVar3 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      iVar2 = 0x111;
    }
    else {
      iVar2 = 6;
      bVar6 = true;
      pcVar3 = "false";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar4 == *pcVar3;
        pcVar4 = pcVar4 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar6);
      if (bVar6) {
        iVar2 = 0x112;
      }
      else if (*(int *)(param_1 + 0x38) == -1) {
        iVar2 = 0x10d;
      }
      else {
        iVar2 = FUN_005e56ca(piVar1);
      }
    }
  }
  return iVar2;
}


// ==== 0x5e7477 FUN_005e7477

int __thiscall FUN_005e7477(undefined4 *param_1,int param_2,int param_3)

{
  byte bVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  bool bVar10;
  char *pcVar11;
  byte local_40 [16];
  int local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  byte *local_20;
  byte *local_1c;
  byte *local_18;
  undefined4 local_14;
  undefined4 *local_10;
  int local_c;
  uint local_8;
  
  pbVar7 = *(byte **)(param_2 + 8);
  bVar1 = *pbVar7;
  local_10 = param_1;
  local_c = 0;
  local_8 = 0;
  local_14 = 0;
  local_2c = 0;
  local_30 = 1;
  local_24 = 0;
  local_28 = 0;
  local_1c = pbVar7;
  local_18 = pbVar7;
  local_20 = pbVar7;
  do {
    local_10 = param_1;
    if (bVar1 == 0) {
      if (((((((param_1[0x1e] == 0) || (local_c == 3)) || (local_c == 5)) ||
            ((local_c == 6 || (local_c == 8)))) ||
           ((local_c == 9 || ((local_c == 4 || (local_c == 0xf)))))) || (local_c == 0x12)) ||
         (local_c == 0x13)) {
LAB_005e78d5:
        pvVar2 = _malloc(0x2c);
        if (pvVar2 == (void *)0x0) {
          iVar3 = 0;
        }
        else {
          iVar3 = FUN_00613593(local_c,local_14,local_8,local_2c,0);
        }
        if (iVar3 != 0) {
          if (param_3 == 0) {
            return iVar3;
          }
          *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(param_3 + 0x28);
          *(undefined4 *)(param_3 + 0x28) = 0;
          return iVar3;
        }
      }
      else {
        FUN_005b1f01(*param_1,param_2,0x7d5,
                     "temporary and constant registers are not allowed in assembly fragments");
LAB_005e752d:
        param_1[0x13] = 1;
        pvVar2 = _malloc(0x2c);
        if (pvVar2 != (void *)0x0) {
          iVar3 = FUN_00613593(0xffffffff,0,0,0,0);
          return iVar3;
        }
      }
      return 0;
    }
    while ((*pbVar7 != 0 && (*pbVar7 != 0x5f))) {
      pbVar7 = pbVar7 + 1;
      local_18 = pbVar7;
    }
    uVar4 = (int)pbVar7 - (int)local_20;
    if (0xf < uVar4) goto LAB_005e78a6;
    pbVar8 = local_20;
    pbVar9 = local_40;
    for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pbVar9 = *(undefined4 *)pbVar8;
      pbVar8 = pbVar8 + 4;
      pbVar9 = pbVar9 + 4;
    }
    bVar1 = *pbVar7;
    for (uVar6 = uVar4 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pbVar9 = *pbVar8;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    }
    local_40[uVar4] = 0;
    if (bVar1 != 0) {
      pbVar7 = pbVar7 + 1;
      local_18 = pbVar7;
    }
    local_20 = pbVar7;
    if (local_30 != 0) {
      pbVar7 = local_40;
      if (local_40[0] == 0) {
LAB_005e75cd:
        local_8 = 0xffffffff;
      }
      else {
        do {
          iVar3 = _isalpha((int)(char)*pbVar7);
          if (iVar3 == 0) break;
          pbVar7 = pbVar7 + 1;
        } while (*pbVar7 != 0);
        if (*pbVar7 == 0) goto LAB_005e75cd;
        local_8 = _atoi((char *)pbVar7);
      }
      if (*pbVar7 != 0) {
        *pbVar7 = 0;
        pbVar7 = pbVar7 + 1;
      }
      bVar1 = *pbVar7;
      if (bVar1 != 0) {
        do {
          iVar3 = _isdigit((int)(char)bVar1);
          if (iVar3 == 0) break;
          pbVar7 = pbVar7 + 1;
          bVar1 = *pbVar7;
        } while (bVar1 != 0);
        if (*pbVar7 != 0) goto LAB_005e78a6;
      }
      iVar3 = 0;
      uVar4 = 0;
      do {
        pbVar8 = *(byte **)((int)&PTR_DAT_006a2950 + uVar4);
        pbVar7 = local_40;
        do {
          bVar1 = *pbVar7;
          bVar10 = bVar1 < *pbVar8;
          if (bVar1 != *pbVar8) {
LAB_005e762e:
            iVar5 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
            goto LAB_005e7635;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar7[1];
          bVar10 = bVar1 < pbVar8[1];
          if (bVar1 != pbVar8[1]) goto LAB_005e762e;
          pbVar7 = pbVar7 + 2;
          pbVar8 = pbVar8 + 2;
        } while (bVar1 != 0);
        iVar5 = 0;
LAB_005e7635:
        if (iVar5 == 0) break;
        uVar4 = uVar4 + 0x48;
        iVar3 = iVar3 + 1;
      } while (uVar4 < 0x5e8);
      if (iVar3 != 0x15) {
        iVar5 = local_10[0xe];
        uVar4 = *(uint *)(&DAT_006a2958 + (iVar5 + iVar3 * 0x12) * 4);
        if (uVar4 != 0xffffffff) {
          if ((int)uVar4 < 0) {
            if (local_8 == 0xffffffff) {
              if (param_3 == 0) goto LAB_005e78a6;
              local_8 = *(uint *)(param_3 + 0x18);
            }
            else if (param_3 != 0) {
              local_8 = local_8 + *(int *)(param_3 + 0x18);
            }
            uVar4 = -uVar4;
          }
          else if (param_3 != 0) goto LAB_005e78a6;
          if (local_8 == 0xffffffff) {
            if (uVar4 == 0) {
              local_8 = 0;
LAB_005e76c8:
              local_c = (&DAT_006a2954)[iVar3 * 0x12];
              local_2c = (&DAT_006a2994)[iVar3 * 0x12];
              if (local_c == 2) {
                uVar4 = local_8 & 0x1fff;
                if (uVar4 < 0x800) {
                  local_c = 2;
                }
                else if (uVar4 < 0x1000) {
                  local_c = 0xb;
                }
                else if (uVar4 < 0x1800) {
                  local_c = 0xc;
                }
                else if (uVar4 < 0x2000) {
                  local_c = 0xd;
                }
                local_8 = local_8 & 0x7ff;
              }
              else if (local_c == -3) {
                local_c = 4;
LAB_005e7745:
                local_8 = 0;
              }
              else if (local_c == -4) {
                local_c = 4;
                local_8 = 2;
              }
              else {
                if (local_c == -5) {
                  local_c = 4;
                }
                else {
                  if (local_c == -6) {
                    local_c = 0x11;
                    goto LAB_005e7745;
                  }
                  if (local_c != -7) goto LAB_005e778a;
                  local_c = 0x11;
                }
                local_8 = 1;
              }
LAB_005e778a:
              local_30 = 0;
              if ((5 < iVar5) && (iVar5 < 10)) {
                local_24 = 1;
              }
              pbVar7 = local_18;
              if (((3 < iVar5) && (iVar5 < 6)) || ((0xc < iVar5 && (iVar5 < 0xf)))) {
                local_28 = 1;
              }
              goto LAB_005e77bc;
            }
          }
          else if (((param_3 != 0) && (*(int *)(param_3 + 0x28) != 0)) || (local_8 < uVar4))
          goto LAB_005e76c8;
        }
      }
LAB_005e78a6:
      param_1 = local_10;
      if (local_10[0x1e] != 0) {
        iVar3 = FUN_005e7154(*local_10,local_10[0x1f],param_2,local_1c,param_3,&local_c,&local_14,
                             &local_8);
        if (iVar3 < 0) goto LAB_005e752d;
        goto LAB_005e78d5;
      }
      if (param_3 == 0) {
        pcVar11 = "invalid register \'%s\'";
      }
      else {
        if (*(int *)(param_3 + 0x28) == 0) {
          FUN_005b1f01(*local_10,param_2,0x7d5,"invalid register \'%s[%u]\'",local_1c,
                       *(undefined4 *)(param_3 + 0x18));
          goto LAB_005e752d;
        }
        if (*(int *)(*(int *)(param_3 + 0x28) + 0x10) == -1) goto LAB_005e752d;
        pcVar11 = "invalid register \'%s[...]\'";
      }
      FUN_005b1f01(*local_10,param_2,0x7d5,pcVar11,local_1c);
      goto LAB_005e752d;
    }
    if (local_24 == 0) {
LAB_005e787b:
      if (local_28 != 0) {
        iVar3 = 4;
        bVar10 = true;
        pbVar8 = local_40;
        pbVar9 = &DAT_0069ee7c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar10 = *pbVar8 == *pbVar9;
          pbVar8 = pbVar8 + 1;
          pbVar9 = pbVar9 + 1;
        } while (bVar10);
        if (bVar10) {
          local_14 = 0xb000000;
          local_28 = 0;
          goto LAB_005e77bc;
        }
      }
      goto LAB_005e78a6;
    }
    iVar3 = 5;
    bVar10 = true;
    pbVar8 = local_40;
    pbVar9 = &DAT_006a3920;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar10 = *pbVar8 == *pbVar9;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    } while (bVar10);
    if (bVar10) {
      local_14 = 0x2000000;
    }
    else {
      iVar3 = 4;
      bVar10 = true;
      pbVar8 = local_40;
      pbVar9 = &DAT_006a391c;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar10 = *pbVar8 == *pbVar9;
        pbVar8 = pbVar8 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar10);
      if (bVar10) {
        local_14 = 0x4000000;
      }
      else {
        iVar3 = 3;
        bVar10 = true;
        pbVar8 = local_40;
        pbVar9 = &DAT_006a3338;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar10 = *pbVar8 == *pbVar9;
          pbVar8 = pbVar8 + 1;
          pbVar9 = pbVar9 + 1;
        } while (bVar10);
        if (bVar10) {
          local_14 = 0x7000000;
        }
        else {
          iVar3 = 3;
          bVar10 = true;
          pbVar8 = local_40;
          pbVar9 = &DAT_006a3918;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar10 = *pbVar8 == *pbVar9;
            pbVar8 = pbVar8 + 1;
            pbVar9 = pbVar9 + 1;
          } while (bVar10);
          if (!bVar10) {
            iVar3 = 3;
            bVar10 = true;
            pbVar8 = local_40;
            pbVar9 = &DAT_006a3914;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar10 = *pbVar8 == *pbVar9;
              pbVar8 = pbVar8 + 1;
              pbVar9 = pbVar9 + 1;
            } while (bVar10);
            if (!bVar10) {
              iVar3 = 3;
              bVar10 = true;
              pbVar8 = local_40;
              pbVar9 = &DAT_006a3910;
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar10 = *pbVar8 == *pbVar9;
                pbVar8 = pbVar8 + 1;
                pbVar9 = pbVar9 + 1;
              } while (bVar10);
              if (!bVar10) {
                iVar3 = 3;
                bVar10 = true;
                pbVar8 = local_40;
                pbVar9 = &DAT_006a390c;
                do {
                  if (iVar3 == 0) break;
                  iVar3 = iVar3 + -1;
                  bVar10 = *pbVar8 == *pbVar9;
                  pbVar8 = pbVar8 + 1;
                  pbVar9 = pbVar9 + 1;
                } while (bVar10);
                if (!bVar10) goto LAB_005e787b;
              }
              local_14 = 0xa000000;
              goto LAB_005e7873;
            }
          }
          local_14 = 0x9000000;
        }
      }
    }
LAB_005e7873:
    local_24 = 0;
LAB_005e77bc:
    bVar1 = *pbVar7;
    param_1 = local_10;
  } while( true );
}


// ==== 0x5e7978 FUN_005e7978

void __fastcall FUN_005e7978(undefined4 *param_1)

{
  _free((void *)*param_1);
  if (param_1[8] != 0) {
    FUN_005e6fe8(1);
  }
  return;
}


// ==== 0x5e7993 FUN_005e7993

void __fastcall FUN_005e7993(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 8) = 0;
  }
  if (*(undefined4 **)(param_1 + 0x34) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x34))(1);
  }
  _free(*(void **)(param_1 + 0x58));
  if (*(int *)(param_1 + 0x78) != 0) {
    FUN_005e737f(1);
  }
  return;
}


// ==== 0x5e79cd FUN_005e79cd

void __thiscall FUN_005e79cd(undefined4 *param_1,uint param_2,uint param_3)

{
  double dVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  void *pvVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  char *pcVar10;
  undefined4 *local_48 [16];
  uint local_8;
  
  if (param_1[0x14] != 0) {
    return;
  }
  local_8 = param_3;
  puVar9 = local_48[1];
  puVar4 = local_48[0];
  while (local_48[0] = puVar4, local_48[1] = puVar9, local_8 != 0) {
    puVar9 = (undefined4 *)param_1[0xd];
    local_8 = local_8 - 1;
    if (puVar9 == (undefined4 *)0x0) {
      FUN_005b1f01(*param_1,param_1 + 4,0,"internal error: stack underflow");
      param_1[0x13] = 1;
      return;
    }
    local_48[local_8] = (undefined4 *)puVar9[2];
    param_1[0xd] = puVar9[3];
    puVar9[2] = 0;
    puVar9[3] = 0;
    (**(code **)*puVar9)(1);
    puVar9 = local_48[1];
    puVar4 = local_48[0];
  }
  puVar5 = (undefined4 *)0x0;
  puVar2 = param_1;
  switch(param_2) {
  case 0:
  case 6:
    goto switchD_005e7a2d_caseD_0;
  case 1:
  case 2:
  case 4:
  case 5:
  case 10:
  case 0x17:
  case 0x19:
  case 0x1d:
  case 0x23:
  case 0x29:
  case 0x2a:
  case 0x2f:
  case 0x30:
    goto LAB_005e7aed;
  case 3:
    puVar5 = (undefined4 *)FUN_005d7899(puVar9,puVar4);
    local_48[0] = (undefined4 *)0x0;
    local_48[1] = (undefined4 *)0x0;
    break;
  case 7:
    if (param_1[0x1d] == 0) {
      param_1[0x1d] = puVar4[6];
    }
    goto switchD_005e7a2d_caseD_0;
  case 8:
    goto LAB_005e7aab;
  case 9:
    local_48[0] = (undefined4 *)0x0;
    if (((int)param_1[0xe] < 6) || (9 < (int)param_1[0xe])) {
      pcVar10 = "instruction coissue is not supported in this shader version";
      uVar8 = 0x7eb;
      puVar5 = puVar4;
      puVar2 = puVar4;
      goto LAB_005e7caf;
    }
    puVar4[0x15] = 1;
LAB_005e7aab:
    local_48[0] = (undefined4 *)0x0;
    FUN_005e62bd(puVar4);
    puVar5 = puVar4;
    break;
  case 0xb:
    iVar7 = param_1[0xe];
    local_48[1] = (undefined4 *)0x0;
    if (((iVar7 < 2) || (5 < iVar7)) && ((iVar7 < 0xb || (0xe < iVar7)))) {
      pcVar10 = "instruction predication is not supported in this shader version";
      uVar8 = 0x7ec;
      puVar5 = puVar9;
      puVar2 = puVar9;
      goto LAB_005e7caf;
    }
    puVar9[0x10] = puVar4;
    puVar4 = puVar9;
    goto LAB_005e7aed;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
    local_48[0] = (undefined4 *)0x0;
    if (1 < param_3) {
      puVar4[0xf] = puVar9;
      local_48[1] = (undefined4 *)0x0;
    }
    local_8 = 2;
    puVar5 = puVar4;
    if (2 < param_3) {
      puVar9 = puVar4 + 0x11;
      do {
        uVar3 = local_8;
        local_8 = local_8 + 1;
        puVar2 = local_48[uVar3];
        local_48[uVar3] = (undefined4 *)0x0;
        *puVar9 = puVar2;
        puVar9 = puVar9 + 1;
      } while (local_8 < param_3);
    }
    break;
  case 0x15:
  case 0x16:
    local_48[0] = (undefined4 *)0x0;
    local_8 = 1;
    puVar5 = puVar4;
    if (1 < param_3) {
      puVar9 = puVar4 + 0x11;
      do {
        uVar3 = local_8;
        local_8 = local_8 + 1;
        puVar2 = local_48[uVar3];
        local_48[uVar3] = (undefined4 *)0x0;
        *puVar9 = puVar2;
        puVar9 = puVar9 + 1;
      } while (local_8 < param_3);
    }
    break;
  case 0x18:
    local_48[0] = (undefined4 *)0x0;
    if (puVar4[7] == 0) {
      uVar8 = FUN_005e605e(puVar9 + 4);
      puVar4[8] = uVar8;
      puVar5 = puVar4;
    }
    else {
      FUN_005b1f01(*param_1,param_1 + 4,0x7e6,"scalar registers cannot be masked");
      param_1[0x13] = 1;
      puVar4[8] = 0xf0000;
      puVar5 = puVar4;
    }
    break;
  case 0x1a:
    local_48[0] = (undefined4 *)0x0;
    if (puVar4[5] == 0) {
      puVar4[5] = 0xd000000;
      puVar5 = puVar4;
      break;
    }
    pcVar10 = "not cannot be used with other modifiers";
    uVar8 = 0x7e2;
    puVar5 = puVar4;
    goto LAB_005e7caf;
  case 0x1b:
    iVar7 = puVar4[5];
    local_48[0] = (undefined4 *)0x0;
    if (iVar7 == 0) {
      puVar4[5] = 0x1000000;
      puVar5 = puVar4;
      break;
    }
    if (iVar7 == 0x2000000) {
      puVar4[5] = 0x3000000;
      puVar5 = puVar4;
      break;
    }
    if (iVar7 == 0x4000000) {
      puVar4[5] = 0x5000000;
      puVar5 = puVar4;
      break;
    }
    if (iVar7 == 0x7000000) {
      puVar4[5] = 0x8000000;
      puVar5 = puVar4;
      break;
    }
    if ((iVar7 != 0x9000000) && (iVar7 != 0xa000000)) {
      puVar5 = puVar4;
      if (iVar7 == 0xb000000) {
        puVar4[5] = 0xc000000;
      }
      break;
    }
    pcVar10 = "negate and divide modifiers cannot be combined";
    uVar8 = 0x7db;
    puVar5 = puVar4;
    goto LAB_005e7caf;
  case 0x1c:
    local_48[1] = (undefined4 *)0x0;
    if (puVar4[6] == 1) {
      if (((int)param_1[0xe] < 6) || (9 < (int)param_1[0xe])) {
        pcVar10 = "complement is not supported in this shader version";
        uVar8 = 0x7ed;
        puVar5 = puVar9;
      }
      else {
        if (puVar9[5] == 0) {
          puVar9[5] = 0x6000000;
          puVar5 = puVar9;
          break;
        }
        pcVar10 = "complement cannot be used with other modifiers";
        uVar8 = 0x7dc;
        puVar5 = puVar9;
      }
    }
    else {
      pcVar10 = "invalid complement expression";
      uVar8 = 0x7da;
      puVar5 = puVar9;
    }
    goto LAB_005e7caf;
  case 0x1e:
    local_48[0] = (undefined4 *)0x0;
    if (puVar4[7] == 0) {
      uVar8 = FUN_005e6111(puVar9 + 4);
      puVar4[9] = uVar8;
      puVar5 = puVar4;
    }
    else {
      FUN_005b1f01(*param_1,param_1 + 4,0x7e6,"scalar registers cannot be swizzled");
      param_1[0x13] = 1;
      puVar4[9] = 0xe40000;
      puVar5 = puVar4;
    }
    break;
  case 0x21:
    puVar9 = (undefined4 *)0x0;
    goto LAB_005e7d2b;
  case 0x22:
LAB_005e7d2b:
    puVar5 = (undefined4 *)FUN_005e7477(puVar4 + 4,puVar9);
    goto LAB_005e7ed7;
  case 0x24:
    puVar4[6] = puVar4[6] + puVar9[6];
    local_48[0] = (undefined4 *)0x0;
    if (puVar4[10] == 0) {
      puVar4[10] = puVar9[10];
      puVar9[10] = 0;
      puVar5 = puVar4;
      break;
    }
    puVar5 = puVar4;
    if (puVar9[10] == 0) break;
    pcVar10 = "only one address register reference allowed in a relative address expression";
    uVar8 = 0x7d9;
LAB_005e7caf:
    FUN_005b1f01(*param_1,puVar2 + 4,uVar8,pcVar10);
    param_1[0x13] = 1;
    break;
  case 0x25:
    pvVar6 = _malloc(0x2c);
    if (pvVar6 == (void *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = (undefined4 *)FUN_00613593(0,0,0,0,local_48[0]);
    }
    FUN_005e5695(puVar4);
LAB_005e7aed:
    local_48[0] = (undefined4 *)0x0;
    puVar5 = puVar4;
    break;
  case 0x26:
    pvVar6 = _malloc(0x2c);
    if (pvVar6 == (void *)0x0) {
LAB_005e7ed5:
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5 = (undefined4 *)FUN_00613593(0,0,local_48[0][6],0,0);
    }
    goto LAB_005e7ed7;
  case 0x27:
    pvVar6 = _malloc(0x30);
    if (pvVar6 == (void *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5 = (undefined4 *)FUN_005d7ac2(param_1 + 4);
    }
    FUN_005e5695(puVar5);
    puVar5[4] = 2;
    puVar5[6] = 1;
    break;
  case 0x28:
    pvVar6 = _malloc(0x30);
    if (pvVar6 == (void *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5 = (undefined4 *)FUN_005d7ac2(param_1 + 4);
    }
    FUN_005e5695(puVar5);
    puVar5[4] = 2;
    puVar5[6] = 0;
    break;
  case 0x2b:
    puVar4[6] = -puVar4[6];
    local_48[0] = (undefined4 *)0x0;
    puVar5 = puVar4;
    break;
  case 0x2c:
  case 0x2d:
    dVar1 = (double)(int)puVar4[6];
    local_48[0] = (undefined4 *)0x0;
    puVar4[4] = 5;
    if ((int)puVar4[6] < 0) {
      dVar1 = dVar1 + 4294967296.0;
    }
    goto LAB_005e7e93;
  case 0x2e:
    dVar1 = (double)(int)puVar4[6];
    local_48[0] = (undefined4 *)0x0;
    puVar4[4] = 5;
    if ((int)puVar4[6] < 0) {
      dVar1 = dVar1 + 4294967296.0;
    }
    goto LAB_005e7e91;
  case 0x31:
    dVar1 = *(double *)(puVar4 + 6);
    local_48[0] = (undefined4 *)0x0;
LAB_005e7e91:
    dVar1 = -dVar1;
LAB_005e7e93:
    local_48[0] = (undefined4 *)0x0;
    *(double *)(puVar4 + 6) = dVar1;
    puVar5 = puVar4;
    break;
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
    pvVar6 = _malloc(0x60);
    if (pvVar6 == (void *)0x0) goto LAB_005e7ed5;
    puVar5 = (undefined4 *)FUN_00613405(param_1 + 4,param_1[0x10],param_1[0x11],param_1[0x12]);
    goto LAB_005e7ed7;
  case 0x3d:
  case 0x3e:
  case 0x3f:
    pvVar6 = _malloc(0x30);
    if (pvVar6 == (void *)0x0) goto LAB_005e7ed5;
    puVar5 = (undefined4 *)FUN_005d7ac2(param_1 + 4);
LAB_005e7ed7:
    FUN_005e5695(puVar5);
  }
switchD_005e7a2d_caseD_1f:
  param_2 = 0;
  if (param_3 != 0) {
    do {
      if (local_48[param_2] != (undefined4 *)0x0) {
        (**(code **)*local_48[param_2])(1);
      }
      param_2 = param_2 + 1;
    } while (param_2 < param_3);
  }
  if (param_1[0x14] == 0) {
    pvVar6 = _malloc(0x14);
    if (pvVar6 == (void *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_005d78db(puVar5,param_1[0xd],"Stack");
    }
    if (iVar7 == 0) {
      FUN_005b1f01(*param_1,param_1 + 4,0,"internal error: out of memory");
      param_1[0x14] = 1;
      param_1[0x13] = 1;
    }
    else {
      param_1[0xd] = iVar7;
    }
  }
  else if (puVar5 != (undefined4 *)0x0) {
    (**(code **)*puVar5)(1);
  }
  return;
switchD_005e7a2d_caseD_0:
  puVar5 = (undefined4 *)0x0;
  goto switchD_005e7a2d_caseD_1f;
}


// ==== 0x5e8013 FUN_005e8013

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005e8013(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  _DAT_00709470 = 0;
  DAT_0070946c = 0;
  DAT_00709464 = (short *)&DAT_00709070;
  DAT_00709460 = (undefined4 *)&DAT_007088a0;
  iVar4 = 0;
  _DAT_00709070 = 0;
LAB_005e8045:
  DAT_00709468 = -1;
LAB_005e804a:
  iVar2 = (int)(short)(&DAT_006de718)[iVar4];
  if (iVar2 == 0) {
    if ((DAT_00709468 < 0) && (DAT_00709468 = FUN_005e739b(), DAT_00709468 < 0)) {
      DAT_00709468 = 0;
    }
    if (((((short)(&DAT_006de860)[iVar4] != 0) &&
         (iVar2 = (short)(&DAT_006de860)[iVar4] + DAT_00709468, -1 < iVar2)) && (iVar2 < 0x128)) &&
       (*(short *)(&DAT_006ded00 + iVar2 * 2) == DAT_00709468)) {
      if (&DAT_00709456 <= DAT_00709464) goto LAB_005e84cf;
      iVar4 = (int)*(short *)(&DAT_006deab0 + iVar2 * 2);
      DAT_00709464 = DAT_00709464 + 1;
      *DAT_00709464 = *(short *)(&DAT_006deab0 + iVar2 * 2);
      DAT_00709460 = DAT_00709460 + 1;
      *DAT_00709460 = DAT_00709458;
      DAT_00709468 = -1;
      if (0 < DAT_0070946c) {
        DAT_0070946c = DAT_0070946c + -1;
      }
      goto LAB_005e804a;
    }
    if ((((short)(&DAT_006de968)[iVar4] != 0) &&
        (iVar2 = (short)(&DAT_006de968)[iVar4] + DAT_00709468, -1 < iVar2)) &&
       ((iVar2 < 0x128 && (*(short *)(&DAT_006ded00 + iVar2 * 2) == DAT_00709468)))) {
      iVar2 = (int)*(short *)(&DAT_006deab0 + iVar2 * 2);
      goto LAB_005e8130;
    }
    if (DAT_0070946c == 0) {
      FUN_005e556b(DAT_00709478,"syntax error");
      _DAT_00709470 = _DAT_00709470 + 1;
    }
    if (2 < DAT_0070946c) goto LAB_005e84c3;
    DAT_0070946c = 3;
    while ((((short)(&DAT_006de860)[*DAT_00709464] == 0 ||
            (iVar4 = (short)(&DAT_006de860)[*DAT_00709464] + 0x100, iVar4 < 0)) ||
           ((0x127 < iVar4 || (*(short *)(&DAT_006ded00 + iVar4 * 2) != 0x100))))) {
      if (DAT_00709464 < (short *)0x709071) {
        DAT_0070946c = 3;
        return 1;
      }
      DAT_00709464 = DAT_00709464 + -1;
      DAT_00709460 = DAT_00709460 + -1;
    }
    if ((short *)0x709455 < DAT_00709464) goto LAB_005e84cf;
    sVar1 = *(short *)(&DAT_006deab0 + iVar4 * 2);
    DAT_00709464 = DAT_00709464 + 1;
    *DAT_00709464 = sVar1;
    uVar6 = DAT_00709458;
  }
  else {
LAB_005e8130:
    iVar4 = (int)*(short *)(&DAT_006de698 + iVar2 * 2);
    DAT_0070945c = DAT_00709460[1 - iVar4];
    switch(iVar2) {
    case 1:
      uVar7 = 0;
      uVar6 = 0;
      break;
    case 2:
      uVar7 = 1;
      uVar6 = 1;
      break;
    case 3:
      uVar7 = 1;
      uVar6 = 2;
      break;
    case 4:
      uVar7 = 2;
      uVar6 = 3;
      break;
    case 5:
      uVar7 = 1;
      uVar6 = 4;
      break;
    case 6:
      uVar7 = 1;
      uVar6 = 5;
      break;
    case 7:
      uVar7 = 0;
      uVar6 = 6;
      break;
    case 8:
      uVar7 = 1;
      uVar6 = 7;
      break;
    case 9:
      uVar7 = 1;
      uVar6 = 8;
      break;
    case 10:
      uVar7 = 1;
      uVar6 = 9;
      break;
    case 0xb:
      uVar7 = 1;
      uVar6 = 10;
      break;
    case 0xc:
      uVar7 = 2;
      uVar6 = 0xb;
      break;
    case 0xd:
      uVar7 = 1;
      uVar6 = 0xc;
      break;
    case 0xe:
      uVar7 = 2;
      uVar6 = 0xd;
      break;
    case 0xf:
      uVar7 = 3;
      uVar6 = 0xe;
      break;
    case 0x10:
      uVar7 = 4;
      uVar6 = 0xf;
      break;
    case 0x11:
      uVar7 = 5;
      uVar6 = 0x10;
      break;
    case 0x12:
      uVar7 = 6;
      uVar6 = 0x11;
      break;
    case 0x13:
      uVar7 = 6;
      uVar6 = 0x12;
      break;
    case 0x14:
      uVar7 = 6;
      uVar6 = 0x13;
      break;
    case 0x15:
      uVar7 = 3;
      uVar6 = 0x14;
      break;
    case 0x16:
      uVar7 = 2;
      uVar6 = 0x15;
      break;
    case 0x17:
      uVar7 = 3;
      uVar6 = 0x16;
      break;
    case 0x18:
      uVar7 = 1;
      uVar6 = 0x17;
      break;
    case 0x19:
      uVar7 = 2;
      uVar6 = 0x18;
      break;
    case 0x1a:
      uVar7 = 1;
      uVar6 = 0x19;
      break;
    case 0x1b:
      uVar7 = 1;
      uVar6 = 0x1a;
      break;
    case 0x1c:
      uVar7 = 1;
      uVar6 = 0x1b;
      break;
    case 0x1d:
      uVar7 = 2;
      uVar6 = 0x1c;
      break;
    case 0x1e:
      uVar7 = 1;
      uVar6 = 0x1d;
      break;
    case 0x1f:
      uVar7 = 2;
      uVar6 = 0x1e;
      break;
    case 0x20:
      uVar7 = 1;
      uVar6 = 0x21;
      break;
    case 0x21:
      uVar7 = 2;
      uVar6 = 0x22;
      break;
    case 0x22:
      uVar7 = 1;
      uVar6 = 0x23;
      break;
    case 0x23:
      uVar7 = 2;
      uVar6 = 0x24;
      break;
    case 0x24:
      uVar7 = 1;
      uVar6 = 0x25;
      break;
    case 0x25:
      uVar7 = 1;
      uVar6 = 0x26;
      break;
    case 0x26:
      uVar7 = 0;
      uVar6 = 0x27;
      break;
    case 0x27:
      uVar7 = 0;
      uVar6 = 0x28;
      break;
    case 0x28:
      uVar7 = 1;
      uVar6 = 0x29;
      break;
    case 0x29:
      uVar7 = 1;
      uVar6 = 0x2a;
      break;
    case 0x2a:
      uVar7 = 1;
      uVar6 = 0x2b;
      break;
    case 0x2b:
      uVar7 = 1;
      uVar6 = 0x2c;
      break;
    case 0x2c:
      uVar7 = 1;
      uVar6 = 0x2d;
      break;
    case 0x2d:
      uVar7 = 1;
      uVar6 = 0x2e;
      break;
    case 0x2e:
      uVar7 = 1;
      uVar6 = 0x2f;
      break;
    case 0x2f:
      uVar7 = 1;
      uVar6 = 0x30;
      break;
    case 0x30:
      uVar7 = 1;
      uVar6 = 0x31;
      break;
    case 0x31:
      uVar7 = 0;
      uVar6 = 0x32;
      break;
    case 0x32:
      uVar7 = 0;
      uVar6 = 0x33;
      break;
    case 0x33:
      uVar7 = 0;
      uVar6 = 0x34;
      break;
    case 0x34:
      uVar7 = 0;
      uVar6 = 0x35;
      break;
    case 0x35:
      uVar7 = 0;
      uVar6 = 0x36;
      break;
    case 0x36:
      uVar7 = 0;
      uVar6 = 0x37;
      break;
    case 0x37:
      uVar7 = 0;
      uVar6 = 0x38;
      break;
    case 0x38:
      uVar7 = 0;
      uVar6 = 0x39;
      break;
    case 0x39:
      uVar7 = 0;
      uVar6 = 0x3a;
      break;
    case 0x3a:
      uVar7 = 0;
      uVar6 = 0x3b;
      break;
    case 0x3b:
      uVar7 = 0;
      uVar6 = 0x3c;
      break;
    case 0x3c:
      uVar7 = 0;
      uVar6 = 0x3d;
      break;
    case 0x3d:
      uVar7 = 0;
      uVar6 = 0x3e;
      break;
    case 0x3e:
      uVar7 = 0;
      uVar6 = 0x3f;
      break;
    default:
      goto switchD_005e815a_default;
    }
    FUN_005e79cd(uVar6,uVar7);
switchD_005e815a_default:
    DAT_00709464 = DAT_00709464 + -iVar4;
    iVar3 = (int)*DAT_00709464;
    DAT_00709460 = DAT_00709460 + -iVar4;
    if ((iVar3 == 0) && (*(short *)(&DAT_006de618 + iVar2 * 2) == 0)) {
      DAT_00709464 = DAT_00709464 + 1;
      iVar4 = 0x10;
      *DAT_00709464 = 0x10;
      DAT_00709460 = DAT_00709460 + 1;
      *DAT_00709460 = DAT_0070945c;
      bVar5 = DAT_00709468 == 0;
      if (DAT_00709468 < 0) {
        DAT_00709468 = FUN_005e739b();
        bVar5 = DAT_00709468 == 0;
        if (DAT_00709468 < 0) {
          DAT_00709468 = 0;
          bVar5 = true;
        }
      }
      if (bVar5) {
        return 0;
      }
      goto LAB_005e804a;
    }
    iVar4 = *(short *)(&DAT_006de618 + iVar2 * 2) * 2;
    if ((((*(short *)(&DAT_006dea70 + iVar4) == 0) ||
         (iVar2 = *(short *)(&DAT_006dea70 + iVar4) + iVar3, iVar2 < 0)) || (0x127 < iVar2)) ||
       (*(short *)(&DAT_006ded00 + iVar2 * 2) != iVar3)) {
      sVar1 = *(short *)(&DAT_006de820 + iVar4);
    }
    else {
      sVar1 = *(short *)(&DAT_006deab0 + iVar2 * 2);
    }
    if ((short *)0x709455 < DAT_00709464) {
LAB_005e84cf:
      FUN_005e556b(DAT_00709478,"yacc stack overflow");
      return 1;
    }
    DAT_00709464 = DAT_00709464 + 1;
    *DAT_00709464 = sVar1;
    uVar6 = DAT_0070945c;
  }
  iVar4 = (int)sVar1;
  DAT_00709460 = DAT_00709460 + 1;
  *DAT_00709460 = uVar6;
  goto LAB_005e804a;
LAB_005e84c3:
  if (DAT_00709468 == 0) {
    return 1;
  }
  goto LAB_005e8045;
}


// ==== 0x5e85e1 FUN_005e85e1

int __thiscall FUN_005e85e1(int *param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  HMODULE hModule;
  FARPROC pFVar4;
  int *piVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined1 local_10 [4];
  int local_c;
  
  uVar1 = param_3;
  if ((param_3 & 0xfffffffa) != 0) {
    return -0x7789f794;
  }
  if (param_5 == (undefined4 *)0x0) {
    return -0x7789f794;
  }
  *param_5 = 0;
  if ((undefined4 *)param_1[0xd] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xd])(1);
  }
  _free((void *)param_1[0x16]);
  if (param_1[0x1e] != 0) {
    FUN_005e737f(1);
  }
  DAT_00709478 = param_1;
  param_1[0xe] = -1;
  param_1[1] = param_2;
  *param_1 = param_2 + 4;
  param_1[2] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0xf] = uVar1;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  if (param_4 != 0) {
    param_1[0xf] = uVar1 | 4;
    param_1[0x1f] = param_4;
    pvVar2 = _malloc(100);
    if (pvVar2 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_005e710d();
    }
    param_1[0x1e] = iVar3;
    if (iVar3 == 0) {
      return -0x7ff8fff2;
    }
  }
  FUN_005c5691(&param_3,0);
  if (param_3 == 0) {
    FUN_005c56b6(param_1 + 0x1b,param_1 + 0x1c);
  }
  iVar3 = FUN_005c564d(2);
  if (iVar3 < 0) {
    return iVar3;
  }
  FUN_005e739b();
  if ((param_1[4] == 9) && (iVar3 = FUN_005d7700(param_1[6],1,local_10), -1 < iVar3)) {
    param_1[4] = 0;
    param_1[6] = local_c;
  }
  if (param_1[4] != 0) {
    pcVar7 = "shader version expected";
    uVar6 = 0x7d1;
LAB_005e871f:
    FUN_005b1f01(*param_1,param_1 + 4,uVar6,pcVar7);
    goto LAB_005e872d;
  }
  if (param_1[6] == -0x1ff00) {
    FUN_005b1fca(*param_1,param_1 + 4,0x7df,"vs_1_0 is no longer supported; using vs_1_1");
    param_1[6] = -0x1feff;
  }
  if (param_1[6] == -0xff00) {
    FUN_005b1fca(*param_1,param_1 + 4,0x7df,"ps_1_0 is no longer supported; using ps_1_1");
    param_1[6] = -0xfeff;
  }
  uVar1 = param_1[6];
  if (uVar1 < 0xffff0103) {
    if (uVar1 == 0xffff0102) {
      param_1[0xe] = 7;
    }
    else if (uVar1 == 0xfffe0101) {
      param_1[0xe] = 0;
    }
    else if (uVar1 == 0xfffe0200) {
      param_1[0xe] = 1;
    }
    else if (uVar1 == 0xfffe0201) {
      param_1[0xe] = 2;
    }
    else if (uVar1 == 0xfffe02ff) {
      param_1[0xe] = 3;
    }
    else if (uVar1 == 0xfffe0300) {
      param_1[0xe] = 4;
    }
    else if (uVar1 == 0xfffe03ff) {
      param_1[0xe] = 5;
    }
    else {
      if (uVar1 != 0xffff0101) goto LAB_005e8858;
      param_1[0xe] = 6;
    }
  }
  else if (uVar1 == 0xffff0103) {
    param_1[0xe] = 8;
  }
  else if (uVar1 == 0xffff0104) {
    param_1[0xe] = 9;
  }
  else if (uVar1 == 0xffff0200) {
    param_1[0xe] = 10;
  }
  else if (uVar1 == 0xffff0201) {
    param_1[0xe] = 0xb;
  }
  else if (uVar1 == 0xffff02ff) {
    param_1[0xe] = 0xc;
  }
  else if (uVar1 == 0xffff0300) {
    param_1[0xe] = 0xd;
  }
  else {
    if (uVar1 != 0xffff03ff) {
LAB_005e8858:
      pcVar7 = "unrecognized shader version";
      uVar6 = 0x7d2;
      goto LAB_005e871f;
    }
    param_1[0xe] = 0xe;
  }
  if (param_1[0x1e] != 0) {
    if ((param_1[0xe] < 0) || (3 < param_1[0xe])) {
      FUN_005b1f01(*param_1,param_1 + 4,0x7d1,
                   "only vs_1_1, vs_2_0, vs_2_x, and vs_2_sw are supported for assembly fragments");
    }
    param_1[6] = (*(byte *)((int)param_1 + 0x19) | 0x7ffe00) << 8 | param_1[6] & 0xffU;
  }
  if (((*(byte *)(param_1 + 0xf) & 4) == 0) &&
     (((hModule = GetModuleHandleA("d3d9.dll"), hModule != (HMODULE)0x0 ||
       (hModule = LoadLibraryA("d3d9.dll"), hModule != (HMODULE)0x0)) &&
      (pFVar4 = GetProcAddress(hModule,"Direct3DShaderValidatorCreate9"), pFVar4 != (FARPROC)0x0))))
  {
    piVar5 = (int *)(*pFVar4)();
    param_1[2] = (int)piVar5;
    if ((piVar5 == (int *)0x0) ||
       (iVar3 = (**(code **)(*piVar5 + 0xc))(piVar5,FUN_005e5629,param_1,0), -1 < iVar3))
    goto LAB_005e8937;
  }
  else {
LAB_005e8937:
    iVar3 = FUN_005e6299(param_1[6]);
    if ((-1 < iVar3) && (iVar3 = FUN_005e61cb(param_1 + 4), -1 < iVar3)) {
      if (param_1[0x13] == 0) {
        iVar3 = FUN_005e8013();
        if (iVar3 != 0) {
          param_1[0x13] = 1;
        }
        if (param_1[0x13] == 0) {
          if (param_1[0x1b] != 0) {
            FUN_005c56b6(&param_2,0);
            uVar1 = param_1[0x1b];
            if ((uVar1 < param_2) && (param_2 < param_1[0x1c] + uVar1)) {
              param_1[0x1c] = param_2 - uVar1;
            }
          }
          if (((((param_1[0x1e] == 0) || (iVar3 = FUN_005e6ae3(), -1 < iVar3)) &&
               (((*(byte *)(param_1 + 0xf) & 1) == 0 || (iVar3 = FUN_005e6d03(), -1 < iVar3)))) &&
              ((iVar3 = FUN_005e6299(0xffff), -1 < iVar3 &&
               (iVar3 = FUN_005e61cb(param_1 + 4), -1 < iVar3)))) &&
             ((piVar5 = (int *)param_1[2], piVar5 == (int *)0x0 ||
              (iVar3 = (**(code **)(*piVar5 + 0x14))(piVar5), -1 < iVar3)))) {
            iVar3 = FUN_005b19e6();
            if (iVar3 != 0) goto LAB_005e872d;
            iVar3 = FUN_005e7021(param_5);
            if (-1 < iVar3) {
              iVar3 = 0;
              goto LAB_005e8a31;
            }
          }
          goto LAB_005e8a26;
        }
      }
LAB_005e872d:
      iVar3 = -0x7789f4a7;
    }
  }
LAB_005e8a26:
  param_1[0x13] = 1;
LAB_005e8a31:
  piVar5 = (int *)param_1[2];
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 8))(piVar5);
    param_1[2] = 0;
  }
  FUN_005c7ed5();
  return iVar3;
}


// ==== 0x5e8a52 FUN_005e8a52

void __thiscall FUN_005e8a52(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}


// ==== 0x5e8a64 FUN_005e8a64

int FUN_005e8a64(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = param_2;
  iVar2 = param_1;
  piVar4 = param_3;
  if (param_3 == (int *)0x0) {
    piVar4 = &param_1;
  }
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == 8) {
    iVar2 = *(int *)(param_1 + 0x10);
    piVar5 = piVar4;
    if ((iVar2 == 1) || (iVar2 == 0)) {
      *param_2 = 1;
      iVar2 = *(int *)(param_1 + 0x1c);
    }
    else {
      if (iVar2 != 2) {
        return -0x7fffbffb;
      }
      *param_2 = *(int *)(param_1 + 0x1c);
      iVar2 = *(int *)(param_1 + 0x18);
    }
  }
  else {
    if (iVar1 != 7) {
      if (iVar1 != 1) {
        return -0x7fffbffb;
      }
      *param_2 = 0;
      *piVar4 = 0;
      do {
        iVar1 = FUN_005e8a64(*(undefined4 *)(*(int *)(*(int *)(iVar2 + 8) + 0x18) + 0x20),&param_3,
                             &param_2);
        if (iVar1 < 0) {
          return iVar1;
        }
        *piVar5 = *piVar5 + (int)param_3;
        piVar3 = (int *)*piVar4;
        if ((int *)*piVar4 < param_2) {
          piVar3 = param_2;
        }
        *piVar4 = (int)piVar3;
        iVar2 = *(int *)(iVar2 + 0xc);
      } while (iVar2 != 0);
      return 0;
    }
    iVar1 = FUN_005e8a64(*(undefined4 *)(param_1 + 0x10),param_2,piVar4);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar2 = *(int *)(iVar2 + 0x14) * *piVar5;
  }
  *piVar5 = iVar2;
  return 0;
}


// ==== 0x5e8b19 FUN_005e8b19

int __thiscall FUN_005e8b19(int *param_1,undefined4 *param_2,short *param_3,undefined4 *param_4)

{
  short *psVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  short **ppsVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  char *pcVar8;
  short *local_24 [8];
  
  psVar1 = param_3;
  puVar4 = param_2;
  ppsVar5 = local_24;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppsVar5 = (short *)*puVar4;
    puVar4 = puVar4 + 1;
    ppsVar5 = ppsVar5 + 1;
  }
  local_24[2] = param_3 + 1;
  local_24[0] = (short *)0xa;
  iVar2 = FUN_005be628(1,local_24,0,0,param_1[1],2,&param_3,0);
  if (iVar2 == 0) {
    uVar6 = FUN_005e8a64(*(undefined4 *)(param_3 + 0x10),param_4,0);
    piVar3 = (int *)((ulonglong)uVar6 >> 0x20);
    if ((int)uVar6 < 0) {
      return (int)uVar6;
    }
    if (*psVar1 == 0x5f62) {
      if (((*piVar3 != 1) || (iVar2 = *(int *)(param_3 + 0x10), *(int *)(iVar2 + 4) != 8)) ||
         ((*(int *)(iVar2 + 0x10) != 0 || (*(int *)(iVar2 + 0x14) != 0)))) {
        pcVar8 = "boolean constant register \'%s\' must be defined as a variable of type bool only";
        uVar7 = 0xb54;
LAB_005e8bf4:
        FUN_005b1f01(*(int *)(*param_1 + 4) + 4,param_2,uVar7,pcVar8,psVar1);
        return -0x7fffbffb;
      }
    }
    else if ((*psVar1 == 0x5f69) &&
            ((((*piVar3 != 1 || (iVar2 = *(int *)(param_3 + 0x10), *(int *)(iVar2 + 4) != 8)) ||
              (*(int *)(iVar2 + 0x10) != 1)) ||
             ((*(int *)(iVar2 + 0x14) != 4 || (*(uint *)(iVar2 + 0x1c) < 3)))))) {
      pcVar8 = 
      "integer constant register \'%s\' must be defined as a variable of type int3 or int4 only";
      uVar7 = 0xb55;
      goto LAB_005e8bf4;
    }
  }
  else {
    *param_4 = 0;
  }
  return 0;
}


// ==== 0x5e8c12 FUN_005e8c12

undefined4
FUN_005e8c12(undefined4 param_1,float *param_2,int param_3,uint param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  size_t _Size;
  uint uVar3;
  undefined4 uVar4;
  float *pfVar5;
  float *local_8;
  
  uVar4 = 0;
  local_8 = (float *)0x0;
  uVar3 = (uint)param_2;
  if (*(int *)(param_4 + 4) == 0xc) {
    uVar3 = *(uint *)(param_4 + 0x20);
  }
  if (*(int *)(uVar3 + 4) == 1) {
    _Size = (int)param_2 << 4;
    local_8 = _malloc(_Size);
    if (local_8 == (float *)0x0) {
      uVar4 = 0x8007000e;
    }
    else {
      pfVar5 = local_8;
      for (iVar2 = ((uint)param_2 & 0xfffffff) << 2; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pfVar5 = 0.0;
        pfVar5 = pfVar5 + 1;
      }
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined1 *)pfVar5 = 0;
        pfVar5 = (float *)((int)pfVar5 + 1);
      }
      if (param_2 != (float *)0x0) {
        param_4 = (uint)param_2;
        pfVar5 = local_8;
        iVar2 = param_3;
        param_2 = local_8;
        do {
          for (; iVar2 != 0; iVar2 = iVar2 + -1) {
            iVar1 = *(int *)(uVar3 + 8);
            if (*(int *)(iVar1 + 0x10) == 3) {
              *pfVar5 = (float)*(double *)(iVar1 + 0x18);
            }
            else {
              *pfVar5 = *(float *)(iVar1 + 0x18);
            }
            uVar3 = *(uint *)(uVar3 + 0xc);
            pfVar5 = pfVar5 + 1;
          }
          pfVar5 = param_2 + 4;
          param_4 = param_4 - 1;
          iVar2 = param_3;
          param_2 = pfVar5;
        } while (param_4 != 0);
      }
      uVar4 = FUN_0061319b(local_8,_Size,6,param_5);
    }
  }
  _free(local_8);
  return uVar4;
}


// ==== 0x5e8cd0 FUN_005e8cd0

int __thiscall
FUN_005e8cd0(int *param_1,undefined4 param_2,char *param_3,short *param_4,undefined2 param_5,
            uint param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 local_60 [2];
  short *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined2 local_38;
  undefined2 local_36;
  undefined4 local_34;
  undefined1 local_30 [4];
  uint local_2c;
  undefined4 local_24;
  int *local_20;
  short *local_1c;
  char *local_18;
  char *local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  iVar1 = (int)param_3;
  param_6 = param_6 | 0x80000000;
  local_8 = 0;
  local_20 = param_1;
  if (((*param_4 != 0x5f63) && (*param_4 != 0x5f62)) && (*param_4 != 0x5f69)) {
    local_40 = 1;
    local_3e = 3;
    local_3c = 1;
    local_3a = 4;
    local_38 = 1;
    local_36 = 0;
    local_34 = 0;
    iVar2 = FUN_0061319b(&local_40,0x10,6,(int)param_3 + 0xc);
    if (iVar2 < 0) {
      return iVar2;
    }
    local_10 = 1;
    goto LAB_005e8f5d;
  }
  local_58 = param_4 + 1;
  local_60[0] = 10;
  local_50 = 0;
  local_4c = 0;
  local_1c = local_58;
  FUN_005be628(1,local_60,0,0,param_1[1],2,&local_8,0);
  iVar2 = FUN_005e8a64(*(undefined4 *)(local_8 + 0x20),&local_10,&local_24);
  if (iVar2 < 0) {
    return iVar2;
  }
  if (*(int *)(local_8 + 0x30) != 0) {
    local_c = *(int *)(local_8 + 0x30);
    param_3 = (char *)0x0;
    local_14 = (char *)0x0;
    local_18 = (char *)0x0;
    if (local_c == 0) {
LAB_005e8e6c:
      param_3 = local_14;
      if ((local_14 == (char *)0x0) && (param_3 = local_18, local_18 == (char *)0x0))
      goto LAB_005e8f0e;
    }
    else {
      do {
        iVar2 = *(int *)(local_c + 8);
        pcVar6 = param_3;
        if (*(int *)(iVar2 + 4) == 0x10) {
          if (*(int *)(iVar2 + 0x10) == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = *(int *)(*(int *)(iVar2 + 0x10) + 0x18);
          }
          if (*(int *)(iVar2 + 0x14) == 0) {
            pcVar5 = (char *)0x0;
          }
          else {
            pcVar5 = *(char **)(*(int *)(iVar2 + 0x14) + 0x18);
          }
          if (iVar4 == 0) {
            iVar2 = _tolower((int)*pcVar5);
            if (iVar2 == (char)*param_4) {
              local_18 = pcVar5;
            }
          }
          else {
            iVar2 = FUN_005d7700(iVar4,0,local_30);
            if (((-1 < iVar2) && (iVar2 = _tolower((int)*pcVar5), iVar2 == (char)*param_4)) &&
               ((pcVar6 = pcVar5, param_6 != local_2c &&
                ((pcVar6 = param_3, ((local_2c ^ param_6) & 0xffff0000) == 0 &&
                 ((short)local_2c == 0)))))) {
              local_14 = pcVar5;
            }
          }
        }
        param_3 = pcVar6;
        local_c = *(int *)(local_c + 0xc);
      } while (local_c != 0);
      local_c = 0;
      if (param_3 == (char *)0x0) goto LAB_005e8e6c;
    }
    iVar2 = _tolower((int)*param_3);
    if ((char)*param_4 == iVar2) {
      iVar2 = _isdigit((int)param_3[1]);
      if (iVar2 != 0) {
        pcVar6 = param_3 + 2;
        while (iVar2 = _isdigit((int)*pcVar6), iVar2 != 0) {
          pcVar6 = pcVar6 + 1;
        }
        if (*pcVar6 == '\0') {
          uVar3 = _atoi(param_3 + 1);
          if (0x1fff < uVar3) {
            FUN_005b1f01(*(int *)(*local_20 + 4) + 4,0,0xb56,
                         "Constant variable \'%s\' bound to register greater than 8191 (%d requested)"
                         ,local_1c,uVar3);
            return -0x7fffbffb;
          }
          *(ushort *)(iVar1 + 10) = *(ushort *)(iVar1 + 10) | (ushort)(uVar3 << 2) | 2;
        }
      }
    }
  }
LAB_005e8f0e:
  if ((*(byte *)(local_8 + 0x1c) & 2) != 0) {
    *(byte *)(iVar1 + 10) = *(byte *)(iVar1 + 10) | 1;
  }
  iVar2 = *(int *)(local_8 + 0x28);
  if (iVar2 == 0) {
    if (*(int *)(local_8 + 0x24) != 0) {
      iVar2 = *(int *)(local_8 + 0x24);
      goto LAB_005e8f2e;
    }
  }
  else {
LAB_005e8f2e:
    iVar2 = FUN_005e8c12(param_2,local_10,local_24,iVar2,iVar1 + 0x10);
    if (iVar2 < 0) {
      return iVar2;
    }
  }
  iVar2 = FUN_00615b5d(param_2,*(undefined4 *)(local_8 + 0x20),1,iVar1 + 0xc);
  if (iVar2 < 0) {
    return iVar2;
  }
LAB_005e8f5d:
  iVar2 = FUN_0061319b(param_4,0xffffffff,7,iVar1);
  if (-1 < iVar2) {
    if (*param_4 == 0x5f62) {
      *(undefined2 *)(iVar1 + 4) = 0;
    }
    else {
      *(ushort *)(iVar1 + 4) = (*param_4 != 0x5f69) + 1;
    }
    *(undefined2 *)(iVar1 + 6) = param_5;
    *(undefined2 *)(iVar1 + 8) = (undefined2)local_10;
  }
  return iVar2;
}


// ==== 0x5e8fb1 FUN_005e8fb1

void FUN_005e8fb1(undefined4 param_1)

{
  HMODULE pHVar1;
  int iVar2;
  
  if ((DAT_00709480 == (FARPROC)0x0) && (DAT_0070947c == (FARPROC)0x0)) {
    pHVar1 = GetModuleHandleA("d3d9.dll");
    if ((pHVar1 != (HMODULE)0x0) && (pHVar1 = LoadLibraryA("d3d9.dll"), pHVar1 != (HMODULE)0x0)) {
      DAT_00709480 = GetProcAddress(pHVar1,"DebugSetMute");
    }
    pHVar1 = GetModuleHandleA("d3d9d.dll");
    if ((pHVar1 != (HMODULE)0x0) && (pHVar1 = LoadLibraryA("d3d9d.dll"), pHVar1 != (HMODULE)0x0)) {
      DAT_0070947c = GetProcAddress(pHVar1,"DebugSetMute");
    }
  }
  if (DAT_006def54 == -1) {
    iVar2 = FUN_005b0484(4,"D3DXDoNotMute",&DAT_006def54,4);
    if (iVar2 == 0) {
      DAT_006def54 = 0;
    }
    if (DAT_006def54 == 0) goto LAB_005e905e;
    DAT_006def54 = 1;
  }
  if (DAT_006def54 != 0) {
    return;
  }
LAB_005e905e:
  if (DAT_00709480 != (FARPROC)0x0) {
    (*DAT_00709480)(param_1);
  }
  if (DAT_0070947c != (FARPROC)0x0) {
    (*DAT_0070947c)(param_1);
  }
  return;
}


// ==== 0x5e9081 FUN_005e9081

undefined4
FUN_005e9081(uint param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int *param_8,int param_9,uint param_10,uint param_11,uint param_12,uint param_13,
            uint param_14,uint param_15,int param_16)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint local_8;
  
  local_8 = 0;
  if (param_1 != 0) {
    do {
      iVar1 = *(int *)*param_8;
      *param_8 = (int)((int *)*param_8 + 1);
      iVar4 = 0;
      for (; iVar1 != 0; iVar1 = iVar1 + -1) {
        piVar2 = (int *)*param_8;
        iVar3 = *piVar2;
        *param_8 = (int)(piVar2 + 1);
        iVar4 = piVar2[1] + iVar4 * 4;
        *param_8 = (int)(piVar2 + 2);
        if ((((iVar3 == 1) || (iVar3 == 2)) || (iVar3 == 3)) || ((iVar3 == 4 || (iVar3 == 5)))) {
          iVar4 = __ftol();
        }
      }
      piVar2 = (int *)*param_8;
      iVar1 = *piVar2;
      *param_8 = (int)(piVar2 + 1);
      uVar5 = piVar2[1] + iVar4 * 4;
      *param_8 = (int)(piVar2 + 2);
      if (iVar1 == 1) {
        if (param_16 == 0) {
          iVar4 = param_2 + (uVar5 % param_14) * 8;
          goto LAB_005e9182;
        }
      }
      else {
        if (iVar1 == 2) {
          uVar5 = uVar5 & param_11;
          iVar4 = param_3;
        }
        else if (iVar1 == 3) {
          uVar5 = uVar5 & param_10;
          iVar4 = param_5;
        }
        else if (iVar1 == 4) {
          uVar5 = uVar5 & param_13;
          iVar4 = param_6;
        }
        else {
          if (iVar1 != 5) {
            if (iVar1 == 7) {
              iVar4 = param_4 + (uVar5 & param_12) * 4;
              goto LAB_005e9182;
            }
            goto LAB_005e9188;
          }
          uVar5 = uVar5 & param_15;
          iVar4 = param_7;
        }
        iVar4 = iVar4 + uVar5 * 8;
LAB_005e9182:
        *(int *)(param_9 + local_8 * 4) = iVar4;
      }
LAB_005e9188:
      local_8 = local_8 + 1;
    } while (local_8 < param_1);
  }
  return 0;
}


// ==== 0x5e91a0 FUN_005e91a0

int FUN_005e91a0(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if ((*param_1 == 0x46580200) || (*param_1 == 0x54580100)) {
    iVar1 = FUN_005d7113(param_1,0x434c5846,param_2,0);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (iVar1 == 1) {
      return 1;
    }
    iVar1 = FUN_005d7113(param_1,0x54494c43,param_3,0);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (iVar1 == 1) {
      return 1;
    }
    if ((*param_2 != 0) && (*param_3 != 0)) {
      return 0;
    }
  }
  return -0x7fffbffb;
}


// ==== 0x5e9207 FUN_005e9207

void __thiscall FUN_005e9207(int param_1,uint param_2,undefined4 param_3,double *param_4)

{
  uint uVar1;
  int iVar2;
  float *pfVar3;
  float10 fVar4;
  float local_10 [3];
  
  uVar1 = 0;
  if (param_2 != 0) {
    do {
      if (2 < uVar1) goto LAB_005e9245;
      iVar2 = uVar1 * 4;
      uVar1 = uVar1 + 1;
      *(float *)(&stack0xffffffec + uVar1 * 4) = (float)**(double **)(param_1 + iVar2);
    } while (uVar1 < param_2);
    if (2 < uVar1) goto LAB_005e9245;
  }
  pfVar3 = local_10 + uVar1;
  for (iVar2 = 3 - uVar1; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar3 = 0.0;
    pfVar3 = pfVar3 + 1;
  }
LAB_005e9245:
  fVar4 = (float10)FUN_005ae18b();
  *param_4 = (double)fVar4;
  return;
}


// ==== 0x5e9257 FUN_005e9257

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined4
FUN_005e9257(uint *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10)

{
  undefined4 *puVar1;
  double dVar2;
  double *pdVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  float10 fVar11;
  undefined1 local_1814 [2048];
  undefined4 local_1014 [254];
  double dStack_c1c;
  undefined8 local_c14;
  int local_414 [256];
  uint local_14;
  undefined4 *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_c = *param_2;
  local_8 = 0;
  local_10 = param_2 + 1;
  local_14 = *param_1;
  param_1 = param_1 + 1;
  if (local_14 != 0) {
    do {
      uVar10 = *param_1;
      uVar9 = param_1[1];
      param_2 = (undefined4 *)param_1[2];
      param_1 = param_1 + 3;
      FUN_005e9081(uVar9,local_10,param_4,param_5,param_3,param_6,local_1814,&param_1,local_414,
                   param_7,param_8,param_9,param_10,local_c,0xff,0);
      FUN_005e9081(param_2,local_10,param_4,param_5,param_3,param_6,local_1814,&param_1,local_1014,
                   param_7,param_8,param_9,param_10,local_c,0xff,1);
      uVar10 = uVar10 & 0xff000000;
      if (uVar10 < 0x1a000001) {
        if (uVar10 == 0x1a000000) {
          uVar10 = 0;
          if (uVar9 != 0) {
            do {
              fVar11 = (float10)FUN_00672e20();
              (&local_c14)[uVar10] = (double)fVar11;
              uVar10 = uVar10 + 1;
            } while (uVar10 < uVar9);
          }
        }
        else if (uVar10 < 0x15000001) {
          if (uVar10 == 0x15000000) {
            uVar10 = 0;
            if (uVar9 != 0) {
              do {
                if (*(double *)local_414[uVar10] < 0.0) {
                  fVar11 = (float10)0;
                }
                else {
                  fVar11 = (float10)log2((float10)*(double *)local_414[uVar10]);
                  fVar11 = (float10)0.6931471805599453 * fVar11 * (float10)1.4426950408889634;
                }
                (&local_c14)[uVar10] = (double)fVar11;
                uVar10 = uVar10 + 1;
              } while (uVar10 < uVar9);
            }
          }
          else if (uVar10 == 0x10000000) {
            uVar10 = 0;
            if (uVar9 != 0) {
              puVar6 = &local_c14;
              do {
                uVar4 = ((undefined4 *)local_414[uVar10])[1];
                *(undefined4 *)puVar6 = *(undefined4 *)local_414[uVar10];
                *(undefined4 *)((int)puVar6 + 4) = uVar4;
                uVar10 = uVar10 + 1;
                puVar6 = puVar6 + 1;
              } while (uVar10 < uVar9);
            }
          }
          else if (uVar10 == 0x11000000) {
            uVar10 = 0;
            if (uVar9 != 0) {
              do {
                piVar7 = local_414 + uVar10;
                uVar10 = uVar10 + 1;
                (&dStack_c1c)[uVar10] = -*(double *)*piVar7;
              } while (uVar10 < uVar9);
            }
          }
          else if (uVar10 == 0x12000000) {
            uVar10 = 0;
            if (uVar9 != 0) {
              do {
                piVar7 = local_414 + uVar10;
                uVar10 = uVar10 + 1;
                (&dStack_c1c)[uVar10] = 1.0 / *(double *)*piVar7;
              } while (uVar10 < uVar9);
            }
          }
          else if (uVar10 == 0x13000000) {
            uVar10 = 0;
            if (uVar9 != 0) {
              do {
                pdVar3 = (double *)local_414[uVar10];
                fVar11 = (float10)FUN_00673590();
                uVar10 = uVar10 + 1;
                (&dStack_c1c)[uVar10] = (double)((float10)*pdVar3 - fVar11);
              } while (uVar10 < uVar9);
            }
          }
          else {
            if (uVar10 != 0x14000000) goto LAB_005e978d;
            uVar10 = 0;
            if (uVar9 != 0) {
              do {
                fVar11 = (float10)FUN_00673890();
                (&local_c14)[uVar10] = (double)fVar11;
                uVar10 = uVar10 + 1;
              } while (uVar10 < uVar9);
            }
          }
        }
        else if (uVar10 == 0x16000000) {
          uVar10 = 0;
          if (uVar9 != 0) {
            do {
              piVar7 = local_414 + uVar10;
              uVar10 = uVar10 + 1;
              (&dStack_c1c)[uVar10] = SQRT(ABS(*(double *)*piVar7));
            } while (uVar10 < uVar9);
          }
        }
        else if (uVar10 == 0x17000000) {
          uVar10 = 0;
          if (uVar9 != 0) {
            do {
              piVar7 = local_414 + uVar10;
              uVar10 = uVar10 + 1;
              fVar11 = (float10)fsin((float10)*(double *)*piVar7);
              (&dStack_c1c)[uVar10] = (double)fVar11;
            } while (uVar10 < uVar9);
          }
        }
        else if (uVar10 == 0x18000000) {
          uVar10 = 0;
          if (uVar9 != 0) {
            do {
              piVar7 = local_414 + uVar10;
              uVar10 = uVar10 + 1;
              fVar11 = (float10)fcos((float10)*(double *)*piVar7);
              (&dStack_c1c)[uVar10] = (double)fVar11;
            } while (uVar10 < uVar9);
          }
        }
        else {
          if (uVar10 != 0x19000000) goto LAB_005e978d;
          uVar10 = 0;
          if (uVar9 != 0) {
            do {
              fVar11 = (float10)FUN_00673b70();
              (&local_c14)[uVar10] = (double)fVar11;
              uVar10 = uVar10 + 1;
            } while (uVar10 < uVar9);
          }
        }
      }
      else if (uVar10 < 0x24000001) {
        if (uVar10 == 0x24000000) {
          uVar10 = 0;
          if (param_2 != (undefined4 *)0x0) {
            do {
              iVar8 = uVar10 + (uVar9 >> 1);
              piVar7 = local_414 + uVar10;
              uVar10 = uVar10 + 1;
              (&dStack_c1c)[uVar10] = *(double *)*piVar7 + *(double *)local_414[iVar8];
            } while (uVar10 < param_2);
          }
        }
        else if (uVar10 == 0x1b000000) {
          uVar10 = 0;
          if (uVar9 != 0) {
            do {
              piVar7 = local_414 + uVar10;
              uVar10 = uVar10 + 1;
              fVar11 = (float10)fpatan((float10)*(double *)*piVar7,(float10)1);
              (&dStack_c1c)[uVar10] = (double)fVar11;
            } while (uVar10 < uVar9);
          }
        }
        else if (uVar10 == 0x20000000) {
          uVar10 = 0;
          piVar7 = local_414 + (uVar9 >> 1);
          if (param_2 != (undefined4 *)0x0) {
            iVar8 = (int)local_414 - (int)piVar7;
            do {
              pdVar3 = *(double **)(iVar8 + (int)piVar7);
              if (*(double *)*piVar7 <= *pdVar3) {
                dVar2 = *(double *)*piVar7;
              }
              else {
                dVar2 = *pdVar3;
              }
              (&local_c14)[uVar10] = dVar2;
              uVar10 = uVar10 + 1;
              piVar7 = piVar7 + 1;
            } while (uVar10 < param_2);
          }
        }
        else if (uVar10 == 0x21000000) {
          uVar10 = 0;
          piVar7 = local_414 + (uVar9 >> 1);
          if (param_2 != (undefined4 *)0x0) {
            iVar8 = (int)local_414 - (int)piVar7;
            do {
              pdVar3 = *(double **)(iVar8 + (int)piVar7);
              if (*pdVar3 <= *(double *)*piVar7) {
                dVar2 = *(double *)*piVar7;
              }
              else {
                dVar2 = *pdVar3;
              }
              (&local_c14)[uVar10] = dVar2;
              uVar10 = uVar10 + 1;
              piVar7 = piVar7 + 1;
            } while (uVar10 < param_2);
          }
        }
        else if (uVar10 == 0x22000000) {
          uVar10 = 0;
          piVar7 = local_414 + (uVar9 >> 1);
          if (param_2 != (undefined4 *)0x0) {
            iVar8 = (int)local_414 - (int)piVar7;
            do {
              if (*(double *)*piVar7 <= **(double **)(iVar8 + (int)piVar7)) {
                uVar5 = 0;
              }
              else {
                uVar5 = 0x3ff0000000000000;
              }
              (&local_c14)[uVar10] = uVar5;
              uVar10 = uVar10 + 1;
              piVar7 = piVar7 + 1;
            } while (uVar10 < param_2);
          }
        }
        else {
          if (uVar10 != 0x23000000) goto LAB_005e978d;
          uVar10 = 0;
          piVar7 = local_414 + (uVar9 >> 1);
          if (param_2 != (undefined4 *)0x0) {
            iVar8 = (int)local_414 - (int)piVar7;
            do {
              if (**(double **)(iVar8 + (int)piVar7) < *(double *)*piVar7) {
                uVar5 = 0;
              }
              else {
                uVar5 = 0x3ff0000000000000;
              }
              (&local_c14)[uVar10] = uVar5;
              uVar10 = uVar10 + 1;
              piVar7 = piVar7 + 1;
            } while (uVar10 < param_2);
          }
        }
      }
      else if (uVar10 == 0x25000000) {
        uVar10 = 0;
        if (param_2 != (undefined4 *)0x0) {
          do {
            iVar8 = uVar10 + (uVar9 >> 1);
            piVar7 = local_414 + uVar10;
            uVar10 = uVar10 + 1;
            (&dStack_c1c)[uVar10] = *(double *)*piVar7 * *(double *)local_414[iVar8];
          } while (uVar10 < param_2);
        }
      }
      else if (uVar10 == 0x26000000) {
        uVar10 = 0;
        piVar7 = local_414 + (uVar9 >> 1);
        if (param_2 != (undefined4 *)0x0) {
          iVar8 = (int)local_414 - (int)piVar7;
          do {
            uVar10 = uVar10 + 1;
            fVar11 = (float10)fpatan((float10)**(double **)(iVar8 + (int)piVar7),
                                     (float10)*(double *)*piVar7);
            piVar7 = piVar7 + 1;
            (&dStack_c1c)[uVar10] = (double)fVar11;
          } while (uVar10 < param_2);
        }
      }
      else if (uVar10 == 0x30000000) {
        uVar9 = uVar9 >> 1;
        local_c14 = 0.0;
        uVar10 = 0;
        if (uVar9 != 0) {
          do {
            iVar8 = uVar10 + uVar9;
            piVar7 = local_414 + uVar10;
            uVar10 = uVar10 + 1;
            local_c14 = *(double *)*piVar7 * *(double *)local_414[iVar8] + local_c14;
          } while (uVar10 < uVar9);
        }
      }
      else if (uVar10 == 0x35000000) {
        FUN_005e9207(uVar9,param_2,&local_c14);
      }
      else {
LAB_005e978d:
        puVar6 = &local_c14;
        for (iVar8 = (int)param_2 * 2; iVar8 != 0; iVar8 = iVar8 + -1) {
          *(undefined4 *)puVar6 = 0;
          puVar6 = (undefined8 *)((int)puVar6 + 4);
        }
      }
      uVar10 = 0;
      if (param_2 != (undefined4 *)0x0) {
        do {
          puVar1 = local_1014 + uVar10;
          puVar6 = &local_c14 + uVar10;
          uVar10 = uVar10 + 1;
          *(undefined8 *)*puVar1 = *puVar6;
        } while (uVar10 < param_2);
      }
      local_8 = local_8 + 1;
    } while (local_8 < local_14);
  }
  return 0;
}


// ==== 0x5e98b0 FUN_005e98b0

void FUN_005e98b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  int iVar1;
  undefined4 local_8;
  
  iVar1 = FUN_005e91a0(param_1,&local_8,&param_1);
  if (-1 < iVar1) {
    FUN_005e9257(local_8,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}


// ==== 0x5e98ef FUN_005e98ef

undefined8 * FUN_005e98ef(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar5 = (float)*param_3;
  fVar6 = (float)((ulonglong)*param_3 >> 0x20);
  fVar7 = (float)param_3[1];
  fVar8 = (float)((ulonglong)param_3[1] >> 0x20);
  fVar1 = (float)*param_2;
  fVar2 = (float)((ulonglong)*param_2 >> 0x20);
  fVar3 = (float)param_2[1];
  fVar4 = (float)((ulonglong)param_2[1] >> 0x20);
  *param_1 = CONCAT44(fVar8 * fVar2 + -fVar5 * fVar3 + fVar6 * fVar4 + fVar7 * fVar1,
                      fVar8 * fVar1 + fVar5 * fVar4 + fVar6 * fVar3 + -fVar7 * fVar2);
  param_1[1] = CONCAT44(fVar8 * fVar4 + -fVar5 * fVar1 + -fVar6 * fVar2 + -fVar7 * fVar3,
                        fVar8 * fVar3 + fVar5 * fVar2 + -fVar6 * fVar1 + fVar7 * fVar4);
  return param_1;
}


// ==== 0x5e9968 FUN_005e9968

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_005e9968(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined1 in_register_00001304 [12];
  float fVar6;
  undefined1 in_XMM5 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = param_2[3];
  auVar7._4_12_ = in_XMM5._4_12_;
  auVar7._0_4_ = fVar2 * fVar2;
  fVar5 = fVar1 * fVar1 + auVar7._0_4_ + fVar3 * fVar3 + fVar4 * fVar4;
  auVar8._4_12_ = in_register_00001304;
  auVar8._0_4_ = fVar5;
  auVar8 = rsqrtss(auVar7,auVar8);
  fVar6 = auVar8._0_4_;
  fVar6 = (DAT_006def70 - fVar5 * fVar6 * fVar6) * _DAT_006def60 * fVar6;
  *param_1 = fVar1 * fVar6;
  param_1[1] = fVar2 * fVar6;
  param_1[2] = fVar3 * fVar6;
  param_1[3] = fVar4 * fVar6;
  return param_1;
}


// ==== 0x5e9a02 FUN_005e9a02

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e9a02(float *param_1,undefined8 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  
  fVar5 = (float)*param_2;
  fVar6 = (float)((ulonglong)*param_2 >> 0x20);
  fVar7 = (float)param_2[1];
  fVar8 = (float)((ulonglong)param_2[1] >> 0x20);
  fVar3 = fVar7 * fVar7;
  fVar4 = fVar8 * fVar8;
  fVar2 = fVar6 * fVar6 + fVar4;
  auVar9._4_4_ = fVar2;
  auVar9._0_4_ = fVar2;
  auVar9._8_4_ = fVar2;
  auVar9._12_4_ = fVar2;
  fVar1 = fVar5 * fVar5 + fVar3 + fVar2;
  auVar10._4_4_ = fVar2;
  auVar10._0_4_ = fVar1;
  auVar10._8_4_ = fVar3 + fVar3;
  auVar10._12_4_ = fVar4 + fVar4;
  auVar10 = rcpss(auVar9,auVar10);
  fVar2 = auVar10._0_4_;
  fVar1 = (fVar2 + fVar2) - fVar2 * fVar1 * fVar2;
  fVar6 = fVar6 * fRam006def84;
  fVar7 = fVar7 * fRam006def88;
  fVar8 = fVar8 * fRam006def8c;
  *param_1 = fVar5 * _DAT_006def80 * fVar1;
  param_1[1] = fVar6 * fVar1;
  param_1[2] = fVar7 * fVar1;
  param_1[3] = fVar8 * fVar1;
  return;
}


// ==== 0x5e9a80 FUN_005e9a80

void FUN_005e9a80(float *param_1,float param_2,float param_3,float param_4)

{
  float local_30;
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  float local_20;
  float fStack_1c;
  float fStack_18;
  
  local_30 = param_4 * 0.5;
  fStack_2c = param_3 * 0.5;
  fStack_28 = param_2 * 0.5;
  uStack_24 = 0;
  FUN_0061b3ea(&local_30,&local_30,&local_20);
  *param_1 = local_20 * fStack_18 * fStack_2c + local_30 * fStack_28 * fStack_1c;
  param_1[1] = local_20 * fStack_28 * fStack_1c + -(local_30 * fStack_18 * fStack_2c);
  param_1[2] = local_30 * fStack_18 * fStack_1c + -(local_20 * fStack_28 * fStack_2c);
  param_1[3] = local_20 * fStack_18 * fStack_1c + local_30 * fStack_28 * fStack_2c;
  return;
}


// ==== 0x5e9b42 FUN_005e9b42

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e9b42(float *param_1,float *param_2)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  float local_18 [4];
  int local_8;
  
  pfVar4 = param_2;
  fVar3 = param_2[5] + *param_2 + param_2[10];
  if (fVar3 <= 0.0) {
    local_18[1] = param_2[5];
    pfVar1 = param_2 + 10;
    local_18[0] = *param_2;
    local_18[2] = *pfVar1;
    param_2 = (float *)(uint)(*param_2 < param_2[5]);
    if (local_18[(int)param_2] < *pfVar1) {
      param_2 = (float *)0x2;
    }
    iVar5 = (int)param_2 * 4;
    iVar2 = *(int *)(&DAT_006a3d90 + iVar5);
    iVar6 = iVar2 * 4;
    local_8 = *(int *)(&DAT_006a3d90 + iVar6);
    fVar3 = SQRT(((local_18[(int)param_2] - local_18[iVar2]) - local_18[local_8]) + _K_ONE) *
            _K_HALF;
    param_1[(int)param_2] = fVar3;
    fVar3 = 0.25 / fVar3;
    param_1[iVar2] = (pfVar4[(int)param_2 + iVar6] + pfVar4[iVar2 + iVar5]) * fVar3;
    param_1[local_8] = (pfVar4[(int)param_2 + local_8 * 4] + pfVar4[iVar5 + local_8]) * fVar3;
    param_1[3] = (pfVar4[iVar6 + local_8] - pfVar4[local_8 * 4 + iVar2]) * fVar3;
  }
  else {
    fVar3 = SQRT(fVar3 + _K_ONE) * _K_HALF;
    param_1[3] = fVar3;
    fVar3 = 0.25 / fVar3;
    *param_1 = (param_2[6] - param_2[9]) * fVar3;
    param_1[1] = (param_2[8] - param_2[2]) * fVar3;
    param_1[2] = (param_2[1] - param_2[4]) * fVar3;
  }
  return;
}


// ==== 0x5e9c6c FUN_005e9c6c

void __thiscall FUN_005e9c6c(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *param_2;
  *param_1 = uVar1;
  param_1[1] = uVar1;
  param_1[2] = uVar1;
  param_1[3] = uVar1;
  uVar1 = param_2[4];
  param_1[0x10] = uVar1;
  param_1[0x11] = uVar1;
  param_1[0x12] = uVar1;
  param_1[0x13] = uVar1;
  uVar1 = param_2[8];
  param_1[0x20] = uVar1;
  param_1[0x21] = uVar1;
  param_1[0x22] = uVar1;
  param_1[0x23] = uVar1;
  uVar1 = param_2[0xc];
  param_1[0x30] = uVar1;
  param_1[0x31] = uVar1;
  param_1[0x32] = uVar1;
  param_1[0x33] = uVar1;
  uVar1 = param_2[1];
  param_1[4] = uVar1;
  param_1[5] = uVar1;
  param_1[6] = uVar1;
  param_1[7] = uVar1;
  uVar1 = param_2[5];
  param_1[0x14] = uVar1;
  param_1[0x15] = uVar1;
  param_1[0x16] = uVar1;
  param_1[0x17] = uVar1;
  uVar1 = param_2[9];
  param_1[0x24] = uVar1;
  param_1[0x25] = uVar1;
  param_1[0x26] = uVar1;
  param_1[0x27] = uVar1;
  uVar1 = param_2[0xd];
  param_1[0x34] = uVar1;
  param_1[0x35] = uVar1;
  param_1[0x36] = uVar1;
  param_1[0x37] = uVar1;
  uVar1 = param_2[2];
  param_1[8] = uVar1;
  param_1[9] = uVar1;
  param_1[10] = uVar1;
  param_1[0xb] = uVar1;
  uVar1 = param_2[6];
  param_1[0x18] = uVar1;
  param_1[0x19] = uVar1;
  param_1[0x1a] = uVar1;
  param_1[0x1b] = uVar1;
  uVar1 = param_2[10];
  param_1[0x28] = uVar1;
  param_1[0x29] = uVar1;
  param_1[0x2a] = uVar1;
  param_1[0x2b] = uVar1;
  uVar1 = param_2[0xe];
  param_1[0x38] = uVar1;
  param_1[0x39] = uVar1;
  param_1[0x3a] = uVar1;
  param_1[0x3b] = uVar1;
  uVar1 = param_2[3];
  param_1[0xc] = uVar1;
  param_1[0xd] = uVar1;
  param_1[0xe] = uVar1;
  param_1[0xf] = uVar1;
  uVar1 = param_2[7];
  param_1[0x1c] = uVar1;
  param_1[0x1d] = uVar1;
  param_1[0x1e] = uVar1;
  param_1[0x1f] = uVar1;
  uVar1 = param_2[0xb];
  param_1[0x2c] = uVar1;
  param_1[0x2d] = uVar1;
  param_1[0x2e] = uVar1;
  param_1[0x2f] = uVar1;
  uVar1 = param_2[0xf];
  param_1[0x3c] = uVar1;
  param_1[0x3d] = uVar1;
  param_1[0x3e] = uVar1;
  param_1[0x3f] = uVar1;
  return;
}


// ==== 0x5e9de6 FUN_005e9de6

undefined8 *
FUN_005e9de6(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,undefined4 param_5,
            uint param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined8 uVar5;
  float fVar6;
  int iVar7;
  uint uVar8;
  undefined8 *puVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float local_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float local_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float local_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float local_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float local_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float local_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float local_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float local_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float local_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float local_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float local_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float local_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float local_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float local_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float local_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  uVar8 = -(uint)(0xc < param_6) & param_6 & 0xfffffffc;
  iVar7 = param_6 - uVar8;
  uVar8 = uVar8 >> 2;
  puVar9 = param_1;
  if (uVar8 != 0) {
    FUN_005e9c6c(param_5);
    for (; uVar8 != 0; uVar8 = uVar8 - 1) {
      fVar12 = (float)*param_3;
      fVar13 = (float)((ulonglong)*param_3 >> 0x20);
      fVar10 = (float)*(undefined8 *)((int)param_3 + param_4);
      fVar11 = (float)((ulonglong)*(undefined8 *)((int)param_3 + param_4) >> 0x20);
      uVar5 = *(undefined8 *)((int)param_3 + param_4 * 2);
      fVar6 = (float)uVar5;
      fVar16 = (float)((ulonglong)uVar5 >> 0x20);
      uVar5 = *(undefined8 *)(param_4 * 3 + (int)param_3);
      fVar14 = (float)uVar5;
      fVar15 = (float)((ulonglong)uVar5 >> 0x20);
      fVar1 = *(float *)(param_4 * 3 + 8 + (int)param_3);
      fVar2 = *(float *)((int)param_3 + param_4 * 2 + 8);
      fVar3 = *(float *)(param_4 + 8 + (int)param_3);
      fVar4 = *(float *)(param_3 + 0xc);
      *puVar9 = CONCAT44(fVar12 * local_100 + fVar13 * local_c0 + fVar4 * local_80 + local_40,
                         fVar12 * local_110 + fVar13 * local_d0 + fVar4 * local_90 + local_50);
      puVar9[0x10] = CONCAT44(fVar12 * local_e0 + fVar13 * local_a0 + fVar4 * local_60 + local_20,
                              fVar12 * local_f0 + fVar13 * local_b0 + fVar4 * local_70 + local_30);
      *(ulonglong *)((int)puVar9 + param_2) =
           CONCAT44(fVar10 * fStack_fc + fVar11 * fStack_bc + fVar3 * fStack_7c + fStack_3c,
                    fVar10 * fStack_10c + fVar11 * fStack_cc + fVar3 * fStack_8c + fStack_4c);
      *(ulonglong *)(param_2 + 8 + (int)puVar9) =
           CONCAT44(fVar10 * fStack_dc + fVar11 * fStack_9c + fVar3 * fStack_5c + fStack_1c,
                    fVar10 * fStack_ec + fVar11 * fStack_ac + fVar3 * fStack_6c + fStack_2c);
      *(ulonglong *)((int)puVar9 + param_2 * 2) =
           CONCAT44(fVar6 * fStack_f8 + fVar16 * fStack_b8 + fVar2 * fStack_78 + fStack_38,
                    fVar6 * fStack_108 + fVar16 * fStack_c8 + fVar2 * fStack_88 + fStack_48);
      *(ulonglong *)((int)puVar9 + param_2 * 2 + 8) =
           CONCAT44(fVar6 * fStack_d8 + fVar16 * fStack_98 + fVar2 * fStack_58 + fStack_18,
                    fVar6 * fStack_e8 + fVar16 * fStack_a8 + fVar2 * fStack_68 + fStack_28);
      *(ulonglong *)(param_2 * 3 + (int)puVar9) =
           CONCAT44(fVar14 * fStack_f4 + fVar15 * fStack_b4 + fVar1 * fStack_74 + fStack_34,
                    fVar14 * fStack_104 + fVar15 * fStack_c4 + fVar1 * fStack_84 + fStack_44);
      *(ulonglong *)(param_2 * 3 + 8 + (int)puVar9) =
           CONCAT44(fVar14 * fStack_d4 + fVar15 * fStack_94 + fVar1 * fStack_54 + fStack_14,
                    fVar14 * fStack_e4 + fVar15 * fStack_a4 + fVar1 * fStack_64 + fStack_24);
      param_3 = (undefined8 *)((int)param_3 + param_4 * 4);
      puVar9 = (undefined8 *)((int)puVar9 + param_2 * 4);
    }
  }
  for (; iVar7 != 0; iVar7 = iVar7 + -1) {
    FUN_005ebce3(puVar9,param_3,param_5);
    param_3 = (undefined8 *)((int)param_3 + param_4);
    puVar9 = (undefined8 *)((int)puVar9 + param_2);
  }
  return param_1;
}


// ==== 0x5e9fec FUN_005e9fec

undefined8 *
FUN_005e9fec(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,undefined4 param_5,
            uint param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float local_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float local_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float local_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float local_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float local_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float local_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float local_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float local_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float local_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float local_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float local_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  uVar4 = -(uint)(0xc < param_6) & param_6 & 0xfffffffc;
  iVar3 = param_6 - uVar4;
  uVar4 = uVar4 >> 2;
  puVar5 = param_1;
  if (uVar4 != 0) {
    FUN_005e9c6c(param_5);
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      uVar1 = *(undefined8 *)((int)param_3 + param_4 * 2);
      fVar6 = (float)*param_3;
      fVar7 = (float)((ulonglong)*param_3 >> 0x20);
      fVar8 = (float)*(undefined8 *)((int)param_3 + param_4);
      fVar9 = (float)((ulonglong)*(undefined8 *)((int)param_3 + param_4) >> 0x20);
      uVar2 = *(undefined8 *)(param_4 * 3 + (int)param_3);
      fVar10 = (float)uVar1;
      fVar11 = (float)((ulonglong)uVar1 >> 0x20);
      fVar12 = (float)uVar2;
      fVar13 = (float)((ulonglong)uVar2 >> 0x20);
      *puVar5 = CONCAT44(fVar6 * local_100 + fVar7 * local_c0 + local_40,
                         fVar6 * local_110 + fVar7 * local_d0 + local_50);
      puVar5[0x10] = CONCAT44(fVar6 * local_e0 + fVar7 * local_a0 + local_20,
                              fVar6 * local_f0 + fVar7 * local_b0 + local_30);
      *(ulonglong *)((int)puVar5 + param_2) =
           CONCAT44(fVar8 * fStack_fc + fVar9 * fStack_bc + fStack_3c,
                    fVar8 * fStack_10c + fVar9 * fStack_cc + fStack_4c);
      *(ulonglong *)(param_2 + 8 + (int)puVar5) =
           CONCAT44(fVar8 * fStack_dc + fVar9 * fStack_9c + fStack_1c,
                    fVar8 * fStack_ec + fVar9 * fStack_ac + fStack_2c);
      *(ulonglong *)((int)puVar5 + param_2 * 2) =
           CONCAT44(fVar10 * fStack_f8 + fVar11 * fStack_b8 + fStack_38,
                    fVar10 * fStack_108 + fVar11 * fStack_c8 + fStack_48);
      *(ulonglong *)((int)puVar5 + param_2 * 2 + 8) =
           CONCAT44(fVar10 * fStack_d8 + fVar11 * fStack_98 + fStack_18,
                    fVar10 * fStack_e8 + fVar11 * fStack_a8 + fStack_28);
      *(ulonglong *)(param_2 * 3 + (int)puVar5) =
           CONCAT44(fVar12 * fStack_f4 + fVar13 * fStack_b4 + fStack_34,
                    fVar12 * fStack_104 + fVar13 * fStack_c4 + fStack_44);
      *(ulonglong *)(param_2 * 3 + 8 + (int)puVar5) =
           CONCAT44(fVar12 * fStack_d4 + fVar13 * fStack_94 + fStack_14,
                    fVar12 * fStack_e4 + fVar13 * fStack_a4 + fStack_24);
      param_3 = (undefined8 *)((int)param_3 + param_4 * 4);
      puVar5 = (undefined8 *)((int)puVar5 + param_2 * 4);
    }
  }
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    thunk_FUN_005abac4(puVar5,param_3,param_5);
    param_3 = (undefined8 *)((int)param_3 + param_4);
    puVar5 = (undefined8 *)((int)puVar5 + param_2);
  }
  return param_1;
}


// ==== 0x5ea17a FUN_005ea17a

undefined8 *
FUN_005ea17a(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,undefined4 param_5,
            uint param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar13;
  float fVar14;
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float local_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float local_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float local_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float local_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float local_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float local_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float local_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float local_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  uVar4 = -(uint)(0xc < param_6) & param_6 & 0xfffffffc;
  iVar3 = param_6 - uVar4;
  uVar4 = uVar4 >> 2;
  puVar5 = param_1;
  if (uVar4 != 0) {
    FUN_005e9c6c(param_5);
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      fVar6 = (float)*param_3;
      fVar7 = (float)((ulonglong)*param_3 >> 0x20);
      fVar8 = (float)*(undefined8 *)((int)param_3 + param_4);
      fVar9 = (float)((ulonglong)*(undefined8 *)((int)param_3 + param_4) >> 0x20);
      uVar1 = *(undefined8 *)((int)param_3 + param_4 * 2);
      uVar2 = *(undefined8 *)(param_4 * 3 + (int)param_3);
      fVar16 = (float)uVar1;
      fVar17 = (float)((ulonglong)uVar1 >> 0x20);
      fVar18 = (float)uVar2;
      fVar19 = (float)((ulonglong)uVar2 >> 0x20);
      auVar11._0_4_ = fVar6 * local_e0 + fVar7 * local_a0;
      auVar11._4_4_ = fVar8 * fStack_dc + fVar9 * fStack_9c;
      auVar11._8_4_ = fVar16 * fStack_d8 + fVar17 * fStack_98;
      auVar11._12_4_ = fVar18 * fStack_d4 + fVar19 * fStack_94;
      auVar12._4_4_ = auVar11._4_4_ + fStack_1c;
      auVar12._0_4_ = auVar11._0_4_ + local_20;
      auVar12._8_4_ = auVar11._8_4_ + fStack_18;
      auVar12._12_4_ = auVar11._12_4_ + fStack_14;
      auVar12 = rcpps(auVar11,auVar12);
      fVar10 = auVar12._0_4_;
      fVar13 = auVar12._4_4_;
      fVar14 = auVar12._8_4_;
      fVar15 = auVar12._12_4_;
      fVar10 = (fVar10 + fVar10) - fVar10 * (auVar11._0_4_ + local_20) * fVar10;
      fVar13 = (fVar13 + fVar13) - fVar13 * (auVar11._4_4_ + fStack_1c) * fVar13;
      fVar14 = (fVar14 + fVar14) - fVar14 * (auVar11._8_4_ + fStack_18) * fVar14;
      fVar15 = (fVar15 + fVar15) - fVar15 * (auVar11._12_4_ + fStack_14) * fVar15;
      *puVar5 = CONCAT44((fVar6 * local_100 + fVar7 * local_c0 + local_40) * fVar10,
                         (fVar6 * local_110 + fVar7 * local_d0 + local_50) * fVar10);
      *(ulonglong *)((int)puVar5 + param_2) =
           CONCAT44((fVar8 * fStack_fc + fVar9 * fStack_bc + fStack_3c) * fVar13,
                    (fVar8 * fStack_10c + fVar9 * fStack_cc + fStack_4c) * fVar13);
      *(ulonglong *)((int)puVar5 + param_2 * 2) =
           CONCAT44((fVar16 * fStack_f8 + fVar17 * fStack_b8 + fStack_38) * fVar14,
                    (fVar16 * fStack_108 + fVar17 * fStack_c8 + fStack_48) * fVar14);
      *(ulonglong *)(param_2 * 3 + (int)puVar5) =
           CONCAT44((fVar18 * fStack_f4 + fVar19 * fStack_b4 + fStack_34) * fVar15,
                    (fVar18 * fStack_104 + fVar19 * fStack_c4 + fStack_44) * fVar15);
      param_3 = (undefined8 *)((int)param_3 + param_4 * 4);
      puVar5 = (undefined8 *)((int)puVar5 + param_2 * 4);
    }
  }
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    thunk_FUN_005abae8(puVar5,param_3,param_5);
    param_3 = (undefined8 *)((int)param_3 + param_4);
    puVar5 = (undefined8 *)((int)puVar5 + param_2);
  }
  return param_1;
}


// ==== 0x5ea2e0 FUN_005ea2e0

undefined8 *
FUN_005ea2e0(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,undefined4 param_5,
            uint param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float local_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float local_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float local_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float local_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  
  uVar4 = -(uint)(0xc < param_6) & param_6 & 0xfffffffc;
  iVar3 = param_6 - uVar4;
  uVar4 = uVar4 >> 2;
  puVar5 = param_1;
  if (uVar4 != 0) {
    FUN_005e9c6c(param_5);
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      fVar6 = (float)*param_3;
      fVar7 = (float)((ulonglong)*param_3 >> 0x20);
      fVar8 = (float)*(undefined8 *)((int)param_3 + param_4);
      fVar9 = (float)((ulonglong)*(undefined8 *)((int)param_3 + param_4) >> 0x20);
      uVar1 = *(undefined8 *)((int)param_3 + param_4 * 2);
      uVar2 = *(undefined8 *)(param_4 * 3 + (int)param_3);
      fVar10 = (float)uVar1;
      fVar11 = (float)((ulonglong)uVar1 >> 0x20);
      fVar12 = (float)uVar2;
      fVar13 = (float)((ulonglong)uVar2 >> 0x20);
      *puVar5 = CONCAT44(fVar6 * local_100 + fVar7 * local_c0,fVar6 * local_110 + fVar7 * local_d0);
      *(ulonglong *)((int)puVar5 + param_2) =
           CONCAT44(fVar8 * fStack_fc + fVar9 * fStack_bc,fVar8 * fStack_10c + fVar9 * fStack_cc);
      *(ulonglong *)((int)puVar5 + param_2 * 2) =
           CONCAT44(fVar10 * fStack_f8 + fVar11 * fStack_b8,fVar10 * fStack_108 + fVar11 * fStack_c8
                   );
      *(ulonglong *)(param_2 * 3 + (int)puVar5) =
           CONCAT44(fVar12 * fStack_f4 + fVar13 * fStack_b4,fVar12 * fStack_104 + fVar13 * fStack_c4
                   );
      param_3 = (undefined8 *)((int)param_3 + param_4 * 4);
      puVar5 = (undefined8 *)((int)puVar5 + param_2 * 4);
    }
  }
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    thunk_FUN_005abb0c(puVar5,param_3,param_5);
    param_3 = (undefined8 *)((int)param_3 + param_4);
    puVar5 = (undefined8 *)((int)puVar5 + param_2);
  }
  return param_1;
}


// ==== 0x5ea3f0 FUN_005ea3f0

undefined8 *
FUN_005ea3f0(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,undefined4 param_5,
            uint param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  undefined8 *puVar8;
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
  float local_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float local_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float local_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float local_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float local_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float local_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float local_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float local_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float local_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float local_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float local_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float local_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float local_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float local_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float local_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  uVar7 = -(uint)(0xc < param_6) & param_6 & 0xfffffffc;
  iVar6 = param_6 - uVar7;
  uVar7 = uVar7 >> 2;
  puVar8 = param_1;
  if (uVar7 != 0) {
    FUN_005e9c6c(param_5);
    for (; uVar7 != 0; uVar7 = uVar7 - 1) {
      fVar13 = (float)*param_3;
      fVar14 = (float)((ulonglong)*param_3 >> 0x20);
      fVar16 = (float)*(undefined8 *)((int)param_3 + param_4);
      fVar17 = (float)((ulonglong)*(undefined8 *)((int)param_3 + param_4) >> 0x20);
      uVar1 = *(undefined8 *)((int)param_3 + param_4 * 2);
      fVar19 = (float)((ulonglong)uVar1 >> 0x20);
      fVar3 = (float)uVar1;
      uVar1 = *(undefined8 *)(param_4 * 3 + (int)param_3);
      fVar11 = (float)uVar1;
      fVar12 = (float)((ulonglong)uVar1 >> 0x20);
      fVar15 = (float)((ulonglong)param_3[0x10] >> 0x20);
      uVar1 = *(undefined8 *)(param_4 + 8 + (int)param_3);
      fVar18 = (float)((ulonglong)uVar1 >> 0x20);
      uVar2 = *(undefined8 *)((int)param_3 + param_4 * 2 + 8);
      fVar9 = (float)uVar2;
      fVar10 = (float)((ulonglong)uVar2 >> 0x20);
      fVar4 = (float)param_3[0x10];
      fVar5 = (float)uVar1;
      uVar1 = *(undefined8 *)(param_4 * 3 + 8 + (int)param_3);
      fVar20 = (float)uVar1;
      fVar21 = (float)((ulonglong)uVar1 >> 0x20);
      *puVar8 = CONCAT44(fVar13 * local_100 + fVar14 * local_c0 + fVar4 * local_80 +
                         fVar15 * local_40,
                         fVar13 * local_110 + fVar14 * local_d0 + fVar4 * local_90 +
                         fVar15 * local_50);
      puVar8[0x10] = CONCAT44(fVar13 * local_e0 + fVar14 * local_a0 + fVar4 * local_60 +
                              fVar15 * local_20,
                              fVar13 * local_f0 + fVar14 * local_b0 + fVar4 * local_70 +
                              fVar15 * local_30);
      *(ulonglong *)((int)puVar8 + param_2) =
           CONCAT44(fVar16 * fStack_fc + fVar17 * fStack_bc + fVar5 * fStack_7c + fVar18 * fStack_3c
                    ,fVar16 * fStack_10c + fVar17 * fStack_cc + fVar5 * fStack_8c +
                     fVar18 * fStack_4c);
      *(ulonglong *)(param_2 + 8 + (int)puVar8) =
           CONCAT44(fVar16 * fStack_dc + fVar17 * fStack_9c + fVar5 * fStack_5c + fVar18 * fStack_1c
                    ,fVar16 * fStack_ec + fVar17 * fStack_ac + fVar5 * fStack_6c +
                     fVar18 * fStack_2c);
      *(ulonglong *)((int)puVar8 + param_2 * 2) =
           CONCAT44(fVar3 * fStack_f8 + fVar19 * fStack_b8 + fVar9 * fStack_78 + fVar10 * fStack_38,
                    fVar3 * fStack_108 + fVar19 * fStack_c8 + fVar9 * fStack_88 + fVar10 * fStack_48
                   );
      *(ulonglong *)((int)puVar8 + param_2 * 2 + 8) =
           CONCAT44(fVar3 * fStack_d8 + fVar19 * fStack_98 + fVar9 * fStack_58 + fVar10 * fStack_18,
                    fVar3 * fStack_e8 + fVar19 * fStack_a8 + fVar9 * fStack_68 + fVar10 * fStack_28)
      ;
      *(ulonglong *)(param_2 * 3 + (int)puVar8) =
           CONCAT44(fVar11 * fStack_f4 + fVar12 * fStack_b4 + fVar20 * fStack_74 +
                    fVar21 * fStack_34,
                    fVar11 * fStack_104 + fVar12 * fStack_c4 + fVar20 * fStack_84 +
                    fVar21 * fStack_44);
      *(ulonglong *)(param_2 * 3 + 8 + (int)puVar8) =
           CONCAT44(fVar11 * fStack_d4 + fVar12 * fStack_94 + fVar20 * fStack_54 +
                    fVar21 * fStack_14,
                    fVar11 * fStack_e4 + fVar12 * fStack_a4 + fVar20 * fStack_64 +
                    fVar21 * fStack_24);
      param_3 = (undefined8 *)((int)param_3 + param_4 * 4);
      puVar8 = (undefined8 *)((int)puVar8 + param_2 * 4);
    }
  }
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    FUN_005eb251(puVar8,param_3,param_5);
    param_3 = (undefined8 *)((int)param_3 + param_4);
    puVar8 = (undefined8 *)((int)puVar8 + param_2);
  }
  return param_1;
}


// ==== 0x5ea62e FUN_005ea62e

undefined8 *
FUN_005ea62e(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,undefined4 param_5,
            uint param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined8 uVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  uint uVar9;
  undefined8 *puVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float local_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float local_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float local_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float local_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float local_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float local_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float local_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float local_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float local_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  
  uVar9 = -(uint)(0xc < param_6) & param_6 & 0xfffffffc;
  iVar8 = param_6 - uVar9;
  uVar9 = uVar9 >> 2;
  puVar10 = param_1;
  if (uVar9 != 0) {
    FUN_005e9c6c(param_5);
    for (; uVar9 != 0; uVar9 = uVar9 - 1) {
      fVar6 = (float)*param_3;
      fVar14 = (float)((ulonglong)*param_3 >> 0x20);
      uVar5 = *(undefined8 *)((int)param_3 + param_4 * 2);
      fVar7 = (float)uVar5;
      fVar11 = (float)((ulonglong)uVar5 >> 0x20);
      fVar12 = (float)*(undefined8 *)((int)param_3 + param_4);
      fVar13 = (float)((ulonglong)*(undefined8 *)((int)param_3 + param_4) >> 0x20);
      uVar5 = *(undefined8 *)(param_4 * 3 + (int)param_3);
      fVar15 = (float)uVar5;
      fVar16 = (float)((ulonglong)uVar5 >> 0x20);
      fVar1 = *(float *)(param_4 * 3 + 8 + (int)param_3);
      fVar2 = *(float *)((int)param_3 + param_4 * 2 + 8);
      fVar3 = *(float *)(param_4 + 8 + (int)param_3);
      fVar4 = *(float *)(param_3 + 0xc);
      *puVar10 = CONCAT44(fVar6 * local_100 + fVar14 * local_c0 + fVar4 * local_80,
                          fVar6 * local_110 + fVar14 * local_d0 + fVar4 * local_90);
      *(ulonglong *)((int)puVar10 + param_2) =
           CONCAT44(fVar12 * fStack_fc + fVar13 * fStack_bc + fVar3 * fStack_7c,
                    fVar12 * fStack_10c + fVar13 * fStack_cc + fVar3 * fStack_8c);
      *(float *)(puVar10 + 0xc) = fVar6 * local_f0 + fVar14 * local_b0 + fVar4 * local_70;
      *(float *)(param_2 + 8 + (int)puVar10) =
           fVar12 * fStack_ec + fVar13 * fStack_ac + fVar3 * fStack_6c;
      *(ulonglong *)((int)puVar10 + param_2 * 2) =
           CONCAT44(fVar7 * fStack_f8 + fVar11 * fStack_b8 + fVar2 * fStack_78,
                    fVar7 * fStack_108 + fVar11 * fStack_c8 + fVar2 * fStack_88);
      *(ulonglong *)(param_2 * 3 + (int)puVar10) =
           CONCAT44(fVar15 * fStack_f4 + fVar16 * fStack_b4 + fVar1 * fStack_74,
                    fVar15 * fStack_104 + fVar16 * fStack_c4 + fVar1 * fStack_84);
      *(float *)((int)puVar10 + param_2 * 2 + 8) =
           fVar7 * fStack_e8 + fVar11 * fStack_a8 + fVar2 * fStack_68;
      *(float *)(param_2 * 3 + 8 + (int)puVar10) =
           fVar15 * fStack_e4 + fVar16 * fStack_a4 + fVar1 * fStack_64;
      param_3 = (undefined8 *)((int)param_3 + param_4 * 4);
      puVar10 = (undefined8 *)((int)puVar10 + param_2 * 4);
    }
  }
  for (; iVar8 != 0; iVar8 = iVar8 + -1) {
    FUN_005ed576(puVar10,param_3,param_5);
    param_3 = (undefined8 *)((int)param_3 + param_4);
    puVar10 = (undefined8 *)((int)puVar10 + param_2);
  }
  return param_1;
}


// ==== 0x5ea7fe FUN_005ea7fe

undefined8 *
FUN_005ea7fe(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,undefined4 param_5,
            uint param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined8 uVar5;
  float fVar6;
  int iVar7;
  uint uVar8;
  undefined8 *puVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar20;
  float fVar21;
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  float fVar22;
  float local_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float local_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float local_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float local_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float local_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float local_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float local_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float local_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float local_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float local_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float local_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float local_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float local_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float local_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float local_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  uVar8 = -(uint)(0xc < param_6) & param_6 & 0xfffffffc;
  iVar7 = param_6 - uVar8;
  uVar8 = uVar8 >> 2;
  puVar9 = param_1;
  if (uVar8 != 0) {
    FUN_005e9c6c(param_5);
    for (; uVar8 != 0; uVar8 = uVar8 - 1) {
      fVar14 = (float)((ulonglong)*param_3 >> 0x20);
      fVar6 = (float)*param_3;
      uVar5 = *(undefined8 *)((int)param_3 + param_4 * 2);
      fVar10 = (float)uVar5;
      fVar11 = (float)((ulonglong)uVar5 >> 0x20);
      fVar12 = (float)*(undefined8 *)((int)param_3 + param_4);
      fVar13 = (float)((ulonglong)*(undefined8 *)((int)param_3 + param_4) >> 0x20);
      uVar5 = *(undefined8 *)(param_4 * 3 + (int)param_3);
      fVar15 = (float)uVar5;
      fVar16 = (float)((ulonglong)uVar5 >> 0x20);
      fVar1 = *(float *)(param_4 * 3 + 8 + (int)param_3);
      fVar2 = *(float *)((int)param_3 + param_4 * 2 + 8);
      fVar3 = *(float *)(param_4 + 8 + (int)param_3);
      fVar4 = *(float *)(param_3 + 0xc);
      auVar18._0_4_ = fVar6 * local_e0 + fVar14 * local_a0 + fVar4 * local_60;
      auVar18._4_4_ = fVar12 * fStack_dc + fVar13 * fStack_9c + fVar3 * fStack_5c;
      auVar18._8_4_ = fVar10 * fStack_d8 + fVar11 * fStack_98 + fVar2 * fStack_58;
      auVar18._12_4_ = fVar15 * fStack_d4 + fVar16 * fStack_94 + fVar1 * fStack_54;
      auVar19._4_4_ = auVar18._4_4_ + fStack_1c;
      auVar19._0_4_ = auVar18._0_4_ + local_20;
      auVar19._8_4_ = auVar18._8_4_ + fStack_18;
      auVar19._12_4_ = auVar18._12_4_ + fStack_14;
      auVar19 = rcpps(auVar18,auVar19);
      fVar17 = auVar19._0_4_;
      fVar20 = auVar19._4_4_;
      fVar21 = auVar19._8_4_;
      fVar22 = auVar19._12_4_;
      fVar17 = (fVar17 + fVar17) - fVar17 * (auVar18._0_4_ + local_20) * fVar17;
      fVar20 = (fVar20 + fVar20) - fVar20 * (auVar18._4_4_ + fStack_1c) * fVar20;
      fVar21 = (fVar21 + fVar21) - fVar21 * (auVar18._8_4_ + fStack_18) * fVar21;
      fVar22 = (fVar22 + fVar22) - fVar22 * (auVar18._12_4_ + fStack_14) * fVar22;
      *puVar9 = CONCAT44((fVar6 * local_100 + fVar14 * local_c0 + fVar4 * local_80 + local_40) *
                         fVar17,(fVar6 * local_110 + fVar14 * local_d0 + fVar4 * local_90 + local_50
                                ) * fVar17);
      *(ulonglong *)((int)puVar9 + param_2) =
           CONCAT44((fVar12 * fStack_fc + fVar13 * fStack_bc + fVar3 * fStack_7c + fStack_3c) *
                    fVar20,(fVar12 * fStack_10c + fVar13 * fStack_cc + fVar3 * fStack_8c + fStack_4c
                           ) * fVar20);
      *(float *)(puVar9 + 0xc) =
           (fVar6 * local_f0 + fVar14 * local_b0 + fVar4 * local_70 + local_30) * fVar17;
      *(float *)(param_2 + 8 + (int)puVar9) =
           (fVar12 * fStack_ec + fVar13 * fStack_ac + fVar3 * fStack_6c + fStack_2c) * fVar20;
      *(ulonglong *)((int)puVar9 + param_2 * 2) =
           CONCAT44((fVar10 * fStack_f8 + fVar11 * fStack_b8 + fVar2 * fStack_78 + fStack_38) *
                    fVar21,(fVar10 * fStack_108 + fVar11 * fStack_c8 + fVar2 * fStack_88 + fStack_48
                           ) * fVar21);
      *(ulonglong *)(param_2 * 3 + (int)puVar9) =
           CONCAT44((fVar15 * fStack_f4 + fVar16 * fStack_b4 + fVar1 * fStack_74 + fStack_34) *
                    fVar22,(fVar15 * fStack_104 + fVar16 * fStack_c4 + fVar1 * fStack_84 + fStack_44
                           ) * fVar22);
      *(float *)((int)puVar9 + param_2 * 2 + 8) =
           (fVar10 * fStack_e8 + fVar11 * fStack_a8 + fVar2 * fStack_68 + fStack_28) * fVar21;
      *(float *)(param_2 * 3 + 8 + (int)puVar9) =
           (fVar15 * fStack_e4 + fVar16 * fStack_a4 + fVar1 * fStack_64 + fStack_24) * fVar22;
      param_3 = (undefined8 *)((int)param_3 + param_4 * 4);
      puVar9 = (undefined8 *)((int)puVar9 + param_2 * 4);
    }
  }
  for (; iVar7 != 0; iVar7 = iVar7 + -1) {
    FUN_005ed64b(puVar9,param_3,param_5);
    param_3 = (undefined8 *)((int)param_3 + param_4);
    puVar9 = (undefined8 *)((int)puVar9 + param_2);
  }
  return param_1;
}


// ==== 0x5eaa2f FUN_005eaa2f

void FUN_005eaa2f(int param_1,int param_2,float *param_3,undefined8 *param_4,int param_5,int param_6
                 ,int *param_7,int *param_8,uint param_9,int param_10,float *param_11,int param_12)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined8 *puVar5;
  undefined1 auVar6 [16];
  int iVar7;
  undefined1 (*pauVar8) [16];
  int *piVar9;
  float *pfVar10;
  uint uVar11;
  uint uVar12;
  undefined4 *puVar13;
  float *pfVar14;
  undefined4 *puVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float *local_4b0;
  undefined4 *local_4ac;
  undefined4 *local_4a8;
  int local_4a4;
  float local_470;
  float fStack_46c;
  float fStack_468;
  float local_420 [263];
  
  local_4a8 = (undefined4 *)((int)param_3 + param_10);
  local_4ac = (undefined4 *)((int)param_4 + param_10);
  uVar12 = param_6 - param_10;
  if (param_2 == 0) {
    param_2 = param_1;
  }
  if (param_9 == 1) {
    if (param_5 != 0) {
      local_4b0 = (float *)(param_4 + 1);
      local_4a4 = param_5;
      do {
        fVar2 = *param_3;
        fVar29 = 0.0;
        fVar31 = 0.0;
        fVar33 = 0.0;
        fVar3 = param_3[1];
        fVar4 = param_3[2];
        pfVar10 = (float *)*param_7;
        fVar19 = *pfVar10;
        fVar30 = pfVar10[1];
        fVar32 = pfVar10[2];
        fVar16 = *param_11;
        fVar18 = fVar29;
        fVar21 = fVar31;
        fVar23 = fVar33;
        while (-1 < (int)fVar16) {
          iVar7 = (int)*param_11 >> 1;
          fVar16 = *param_11 - (float)(iVar7 * 2);
          iVar7 = iVar7 * 0x40;
          pfVar10 = (float *)(param_1 + iVar7);
          auVar26._0_4_ = pfVar10[8] * fVar4 + pfVar10[0xc];
          auVar26._4_4_ = pfVar10[9] * fVar4 + pfVar10[0xd];
          auVar26._8_4_ = pfVar10[10] * fVar4 + pfVar10[0xe];
          auVar26._12_4_ = pfVar10[0xb] * fVar4 + pfVar10[0xf];
          fVar17 = *pfVar10 * fVar2 + pfVar10[4] * fVar3 + auVar26._0_4_;
          fVar20 = pfVar10[1] * fVar2 + pfVar10[5] * fVar3 + auVar26._4_4_;
          fVar22 = pfVar10[2] * fVar2 + pfVar10[6] * fVar3 + auVar26._8_4_;
          fVar24 = pfVar10[3] * fVar2 + pfVar10[7] * fVar3 + auVar26._12_4_;
          auVar6._4_4_ = fVar20;
          auVar6._0_4_ = fVar17;
          auVar6._8_4_ = fVar22;
          auVar6._12_4_ = fVar24;
          auVar27 = rcpps(auVar26,auVar6);
          fVar28 = auVar27._12_4_;
          fVar24 = (fVar28 + fVar28) - fVar28 * fVar24 * fVar28;
          fVar29 = fVar29 + fVar17 * fVar16 * fVar24;
          fVar31 = fVar31 + fVar20 * fVar16 * fVar24;
          fVar33 = fVar33 + fVar22 * fVar16 * fVar24;
          pfVar10 = (float *)(iVar7 + param_2);
          param_11 = param_11 + 1;
          fVar18 = fVar18 + (fVar19 * *pfVar10 + fVar30 * pfVar10[4] + fVar32 * pfVar10[8]) * fVar16
          ;
          fVar21 = fVar21 + (fVar19 * pfVar10[1] + fVar30 * pfVar10[5] + fVar32 * pfVar10[9]) *
                            fVar16;
          fVar23 = fVar23 + (fVar19 * pfVar10[2] + fVar30 * pfVar10[6] + fVar32 * pfVar10[10]) *
                            fVar16;
          fVar16 = *param_11;
        }
        if (param_12 == 0) {
          *param_4 = CONCAT44(fVar31,fVar29);
          *local_4b0 = fVar33;
          puVar5 = (undefined8 *)*param_8;
          *puVar5 = CONCAT44(fVar21,fVar18);
          *(float *)(puVar5 + 1) = fVar23;
          puVar13 = local_4a8;
          puVar15 = local_4ac;
          for (uVar11 = uVar12 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
            *puVar15 = *puVar13;
            puVar13 = puVar13 + 1;
            puVar15 = puVar15 + 1;
          }
          for (uVar11 = uVar12 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
            *(undefined1 *)puVar15 = *(undefined1 *)puVar13;
            puVar13 = (undefined4 *)((int)puVar13 + 1);
            puVar15 = (undefined4 *)((int)puVar15 + 1);
          }
        }
        else {
          puVar13 = local_4a8;
          puVar15 = local_4ac;
          for (uVar11 = uVar12 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
            *puVar15 = *puVar13;
            puVar13 = puVar13 + 1;
            puVar15 = puVar15 + 1;
          }
          for (uVar11 = uVar12 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
            *(undefined1 *)puVar15 = *(undefined1 *)puVar13;
            puVar13 = (undefined4 *)((int)puVar13 + 1);
            puVar15 = (undefined4 *)((int)puVar15 + 1);
          }
          *param_4 = CONCAT44(fVar31,fVar29);
          *local_4b0 = fVar33;
          puVar5 = (undefined8 *)*param_8;
          *puVar5 = CONCAT44(fVar21,fVar18);
          *(float *)(puVar5 + 1) = fVar23;
        }
        *param_8 = *param_8 + param_6;
        local_4ac = (undefined4 *)((int)local_4ac + param_6);
        local_4a8 = (undefined4 *)((int)local_4a8 + param_6);
        param_4 = (undefined8 *)((int)param_4 + param_6);
        local_4b0 = (float *)((int)local_4b0 + param_6);
        param_3 = (float *)((int)param_3 + param_6);
        *param_7 = *param_7 + param_6;
        param_11 = param_11 + 1;
        local_4a4 = local_4a4 + -1;
      } while (local_4a4 != 0);
    }
  }
  else if (param_5 != 0) {
    local_4b0 = (float *)(param_4 + 1);
    local_470 = 0.0;
    fStack_46c = 0.0;
    fStack_468 = 0.0;
    local_4a4 = param_5;
    do {
      fVar2 = *param_3;
      fVar3 = param_3[1];
      fVar4 = param_3[2];
      if (param_9 != 0) {
        local_420[0] = 0.0;
        local_420[1] = 0.0;
        local_420[2] = 0.0;
        local_420[3] = 0.0;
        pfVar10 = local_420;
        pfVar14 = local_420 + 4;
        for (uVar11 = param_9 * 0x10 - 0xd >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
          *pfVar14 = *pfVar10;
          pfVar10 = pfVar10 + 1;
          pfVar14 = pfVar14 + 1;
        }
      }
      fVar19 = *param_11;
      fVar30 = local_470;
      fVar32 = fStack_46c;
      fVar16 = fStack_468;
      while (-1 < (int)fVar19) {
        iVar7 = (int)*param_11 >> 1;
        fVar19 = *param_11 - (float)(iVar7 * 2);
        iVar7 = iVar7 * 0x40;
        pfVar10 = (float *)(param_1 + iVar7);
        auVar25._0_4_ = pfVar10[8] * fVar4 + pfVar10[0xc];
        auVar25._4_4_ = pfVar10[9] * fVar4 + pfVar10[0xd];
        auVar25._8_4_ = pfVar10[10] * fVar4 + pfVar10[0xe];
        auVar25._12_4_ = pfVar10[0xb] * fVar4 + pfVar10[0xf];
        fVar29 = *pfVar10 * fVar2 + pfVar10[4] * fVar3 + auVar25._0_4_;
        fVar31 = pfVar10[1] * fVar2 + pfVar10[5] * fVar3 + auVar25._4_4_;
        fVar33 = pfVar10[2] * fVar2 + pfVar10[6] * fVar3 + auVar25._8_4_;
        fVar18 = pfVar10[3] * fVar2 + pfVar10[7] * fVar3 + auVar25._12_4_;
        auVar27._4_4_ = fVar31;
        auVar27._0_4_ = fVar29;
        auVar27._8_4_ = fVar33;
        auVar27._12_4_ = fVar18;
        auVar27 = rcpps(auVar25,auVar27);
        fVar21 = auVar27._12_4_;
        fVar18 = (fVar21 + fVar21) - fVar21 * fVar18 * fVar21;
        pauVar8 = (undefined1 (*) [16])(iVar7 + param_2);
        uVar11 = 0;
        fVar30 = fVar30 + fVar29 * fVar19 * fVar18;
        fVar32 = fVar32 + fVar31 * fVar19 * fVar18;
        fVar16 = fVar16 + fVar33 * fVar19 * fVar18;
        if (param_9 != 0) {
          fVar29 = *(float *)pauVar8[2];
          fVar31 = *(float *)(pauVar8[2] + 4);
          fVar33 = *(float *)(pauVar8[2] + 8);
          fVar18 = *(float *)(pauVar8[2] + 0xc);
          auVar27 = *pauVar8;
          fVar21 = *(float *)pauVar8[1];
          fVar23 = *(float *)(pauVar8[1] + 4);
          fVar17 = *(float *)(pauVar8[1] + 8);
          fVar20 = *(float *)(pauVar8[1] + 0xc);
          pfVar10 = local_420;
          do {
            pfVar14 = (float *)param_7[uVar11];
            fVar22 = pfVar14[2];
            fVar24 = pfVar14[1];
            fVar28 = *pfVar14;
            *pfVar10 = *pfVar10 +
                       (fVar28 * auVar27._0_4_ + fVar24 * fVar21 + fVar22 * fVar29) * fVar19;
            pfVar10[1] = pfVar10[1] +
                         (fVar28 * auVar27._4_4_ + fVar24 * fVar23 + fVar22 * fVar31) * fVar19;
            pfVar10[2] = pfVar10[2] +
                         (fVar28 * auVar27._8_4_ + fVar24 * fVar17 + fVar22 * fVar33) * fVar19;
            pfVar10[3] = pfVar10[3] +
                         (fVar28 * auVar27._12_4_ + fVar24 * fVar20 + fVar22 * fVar18) * fVar19;
            uVar11 = uVar11 + 1;
            pfVar10 = pfVar10 + 4;
          } while (uVar11 < param_9);
        }
        param_11 = param_11 + 1;
        fVar19 = *param_11;
      }
      if (param_12 == 0) {
        *param_4 = CONCAT44(fVar32,fVar30);
        *local_4b0 = fVar16;
        if (param_9 != 0) {
          pauVar8 = (undefined1 (*) [16])local_420;
          piVar9 = param_8;
          uVar11 = param_9;
          do {
            puVar5 = (undefined8 *)*piVar9;
            auVar27 = *pauVar8;
            *puVar5 = auVar27._0_8_;
            *(int *)(puVar5 + 1) = auVar27._8_4_;
            *piVar9 = *piVar9 + param_6;
            piVar1 = (int *)((int)piVar9 + ((int)param_7 - (int)param_8));
            *piVar1 = *piVar1 + param_6;
            pauVar8 = pauVar8 + 1;
            piVar9 = piVar9 + 1;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        puVar13 = local_4a8;
        puVar15 = local_4ac;
        for (uVar11 = uVar12 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
          *puVar15 = *puVar13;
          puVar13 = puVar13 + 1;
          puVar15 = puVar15 + 1;
        }
        for (uVar11 = uVar12 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
          *(undefined1 *)puVar15 = *(undefined1 *)puVar13;
          puVar13 = (undefined4 *)((int)puVar13 + 1);
          puVar15 = (undefined4 *)((int)puVar15 + 1);
        }
      }
      else {
        puVar13 = local_4a8;
        puVar15 = local_4ac;
        for (uVar11 = uVar12 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
          *puVar15 = *puVar13;
          puVar13 = puVar13 + 1;
          puVar15 = puVar15 + 1;
        }
        for (uVar11 = uVar12 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
          *(undefined1 *)puVar15 = *(undefined1 *)puVar13;
          puVar13 = (undefined4 *)((int)puVar13 + 1);
          puVar15 = (undefined4 *)((int)puVar15 + 1);
        }
        *param_4 = CONCAT44(fVar32,fVar30);
        *local_4b0 = fVar16;
        if (param_9 != 0) {
          pauVar8 = (undefined1 (*) [16])local_420;
          piVar9 = param_8;
          uVar11 = param_9;
          do {
            puVar5 = (undefined8 *)*piVar9;
            auVar27 = *pauVar8;
            *puVar5 = auVar27._0_8_;
            *(int *)(puVar5 + 1) = auVar27._8_4_;
            *piVar9 = *piVar9 + param_6;
            piVar1 = (int *)(((int)param_7 - (int)param_8) + (int)piVar9);
            *piVar1 = *piVar1 + param_6;
            pauVar8 = pauVar8 + 1;
            piVar9 = piVar9 + 1;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
      }
      local_4ac = (undefined4 *)((int)local_4ac + param_6);
      local_4a8 = (undefined4 *)((int)local_4a8 + param_6);
      param_4 = (undefined8 *)((int)param_4 + param_6);
      local_4b0 = (float *)((int)local_4b0 + param_6);
      param_11 = param_11 + 1;
      param_3 = (float *)((int)param_3 + param_6);
      local_4a4 = local_4a4 + -1;
    } while (local_4a4 != 0);
  }
  return;
}


// ==== 0x5eaf87 FUN_005eaf87

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005eaf87(void)

{
  return;
}


// ==== 0x5eb0b1 FUN_005eb0b1

/* WARNING: Removing unreachable block (ram,0x005eb166) */

int FUN_005eb0b1(int param_1,int param_2,uint param_3)

{
  ushort uVar1;
  int iVar2;
  undefined8 *extraout_ECX;
  uint uVar3;
  int extraout_EDX;
  uint uVar4;
  uint uVar5;
  undefined8 in_XMM0_Qa;
  undefined8 in_XMM0_Qb;
  undefined8 in_XMM3_Qa;
  undefined8 in_XMM3_Qb;
  
  iVar2 = param_1;
  if (7 < param_3) {
    uVar5 = param_3 & 0xfffffff8;
    do {
      FUN_005eaf87();
      *extraout_ECX = in_XMM0_Qa;
      extraout_ECX[1] = in_XMM0_Qb;
      extraout_ECX[2] = in_XMM3_Qa;
      extraout_ECX[3] = in_XMM3_Qb;
    } while (extraout_EDX != 8);
    param_3 = param_3 - uVar5;
    param_2 = param_2 + uVar5 * 2;
    param_1 = param_1 + uVar5 * 4;
  }
  uVar5 = 0;
  if (param_3 != 0) {
    do {
      uVar1 = *(ushort *)(param_2 + uVar5 * 2);
      uVar3 = (uint)uVar1;
      uVar4 = uVar3 & 0x7c00;
      if (uVar4 < 0x401) {
        uVar4 = 0x400;
      }
      *(float *)(param_1 + uVar5 * 4) =
           (float)(-(uint)((uVar1 & 0x7c00) != 0) & 0x400 | uVar3 & 0x3ff) *
           (float)((uVar4 + 0x19800) * 0x2000 | (uVar3 & 0xffff8000) << 0x10);
      uVar5 = uVar5 + 1;
    } while (uVar5 < param_3);
  }
  return iVar2;
}


// ==== 0x5eb185 FUN_005eb185

float * FUN_005eb185(float *param_1,float *param_2,float *param_3)

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
  
  fVar3 = param_3[1];
  fVar4 = param_3[2];
  fVar5 = param_3[3];
  fVar1 = *param_2;
  fVar6 = param_3[5];
  fVar7 = param_3[6];
  fVar8 = param_3[7];
  fVar2 = param_2[1];
  fVar9 = param_3[0xd];
  fVar10 = param_3[0xe];
  fVar11 = param_3[0xf];
  *param_1 = fVar1 * *param_3 + param_3[0xc] + fVar2 * param_3[4];
  param_1[1] = fVar1 * fVar3 + fVar9 + fVar2 * fVar6;
  param_1[2] = fVar1 * fVar4 + fVar10 + fVar2 * fVar7;
  param_1[3] = fVar1 * fVar5 + fVar11 + fVar2 * fVar8;
  return param_1;
}


// ==== 0x5eb1c3 FUN_005eb1c3

undefined8 * FUN_005eb1c3(undefined8 *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  undefined1 in_XMM0 [16];
  undefined1 auVar3 [16];
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar4 = fVar1 * *param_3 + param_3[0xc] + fVar2 * param_3[4];
  fVar5 = fVar1 * param_3[1] + param_3[0xd] + fVar2 * param_3[5];
  fVar6 = fVar1 * param_3[3] + param_3[0xf] + fVar2 * param_3[7];
  auVar3._4_4_ = fVar5;
  auVar3._0_4_ = fVar4;
  auVar3._8_4_ = fVar1 * param_3[2] + param_3[0xe] + fVar2 * param_3[6];
  auVar3._12_4_ = fVar6;
  auVar3 = rcpps(in_XMM0,auVar3);
  fVar6 = auVar3._12_4_ * auVar3._12_4_ * fVar6;
  *param_1 = CONCAT44(fVar5 * fVar6,fVar4 * fVar6);
  return param_1;
}


// ==== 0x5eb21a FUN_005eb21a

undefined8 * FUN_005eb21a(undefined8 *param_1,float *param_2,float *param_3)

{
  *param_1 = CONCAT44(*param_2 * param_3[1] + param_2[1] * param_3[5],
                      *param_2 * *param_3 + param_2[1] * param_3[4]);
  return param_1;
}


// ==== 0x5eb251 FUN_005eb251

void FUN_005eb251(float *param_1,float *param_2,float *param_3)

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
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar7 = param_2[2];
  fVar8 = param_2[3];
  if (((uint)param_3 & 0xf) == 0) {
    fVar11 = param_3[8] * fVar7 + param_3[0xc] * fVar8;
    fVar12 = param_3[9] * fVar7 + param_3[0xd] * fVar8;
    fVar13 = param_3[10] * fVar7 + param_3[0xe] * fVar8;
    fVar14 = param_3[0xb] * fVar7 + param_3[0xf] * fVar8;
    fVar7 = param_3[4];
    fVar8 = param_3[5];
    fVar9 = param_3[6];
    fVar10 = param_3[7];
    fVar3 = *param_3;
    fVar4 = param_3[1];
    fVar5 = param_3[2];
    fVar6 = param_3[3];
  }
  else {
    fVar11 = (float)*(undefined8 *)(param_3 + 8) * fVar7 +
             (float)*(undefined8 *)(param_3 + 0xc) * fVar8;
    fVar12 = (float)((ulonglong)*(undefined8 *)(param_3 + 8) >> 0x20) * fVar7 +
             (float)((ulonglong)*(undefined8 *)(param_3 + 0xc) >> 0x20) * fVar8;
    fVar13 = (float)*(undefined8 *)(param_3 + 10) * fVar7 +
             (float)*(undefined8 *)(param_3 + 0xe) * fVar8;
    fVar14 = (float)((ulonglong)*(undefined8 *)(param_3 + 10) >> 0x20) * fVar7 +
             (float)((ulonglong)*(undefined8 *)(param_3 + 0xe) >> 0x20) * fVar8;
    fVar7 = (float)*(undefined8 *)(param_3 + 4);
    fVar8 = (float)((ulonglong)*(undefined8 *)(param_3 + 4) >> 0x20);
    fVar9 = (float)*(undefined8 *)(param_3 + 6);
    fVar10 = (float)((ulonglong)*(undefined8 *)(param_3 + 6) >> 0x20);
    fVar3 = (float)*(undefined8 *)param_3;
    fVar4 = (float)((ulonglong)*(undefined8 *)param_3 >> 0x20);
    fVar5 = (float)*(undefined8 *)(param_3 + 2);
    fVar6 = (float)((ulonglong)*(undefined8 *)(param_3 + 2) >> 0x20);
  }
  *param_1 = fVar3 * fVar1 + fVar7 * fVar2 + fVar11;
  param_1[1] = fVar4 * fVar1 + fVar8 * fVar2 + fVar12;
  param_1[2] = fVar5 * fVar1 + fVar9 * fVar2 + fVar13;
  param_1[3] = fVar6 * fVar1 + fVar10 * fVar2 + fVar14;
  return;
}


// ==== 0x5eb31d FUN_005eb31d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005eb31d(uint *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  uint uVar5;
  float fVar6;
  uint uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  
  fVar1 = (float)*param_3;
  fVar2 = (float)((ulonglong)*param_3 >> 0x20);
  fVar4 = (float)param_3[1];
  fVar6 = (float)((ulonglong)param_3[1] >> 0x20);
  fVar8 = (float)*param_4;
  fVar9 = (float)((ulonglong)*param_4 >> 0x20);
  fVar10 = (float)param_4[1];
  fVar11 = (float)((ulonglong)param_4[1] >> 0x20);
  fVar12 = (float)*param_2;
  fVar13 = (float)((ulonglong)*param_2 >> 0x20);
  fVar14 = (float)param_2[1];
  fVar15 = (float)((ulonglong)param_2[1] >> 0x20);
  uVar3 = (uint)(fVar14 * (fVar6 * fVar8 - fVar1 * fVar11) +
                 fVar15 * (fVar1 * fVar10 - fVar4 * fVar8) +
                fVar12 * (fVar4 * fVar11 - fVar6 * fVar10)) ^ uRam006df084;
  uVar5 = (uint)(fVar15 * (fVar1 * fVar9 - fVar2 * fVar8) +
                 fVar12 * (fVar2 * fVar11 - fVar6 * fVar9) +
                fVar13 * (fVar6 * fVar8 - fVar1 * fVar11)) ^ uRam006df088;
  uVar7 = (uint)(fVar12 * (fVar2 * fVar10 - fVar4 * fVar9) +
                 fVar13 * (fVar4 * fVar8 - fVar1 * fVar10) +
                fVar14 * (fVar1 * fVar9 - fVar2 * fVar8)) ^ uRam006df08c;
  *param_1 = (uint)(fVar13 * (fVar4 * fVar11 - fVar6 * fVar10) +
                    fVar14 * (fVar6 * fVar9 - fVar2 * fVar11) +
                   fVar15 * (fVar2 * fVar10 - fVar4 * fVar9)) ^ _DAT_006df080;
  param_1[1] = uVar3;
  param_1[2] = uVar5;
  param_1[3] = uVar7;
  return;
}


// ==== 0x5eb3dd FUN_005eb3dd

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_005eb3dd(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined1 in_register_00001304 [12];
  float fVar6;
  undefined1 in_XMM5 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = param_2[3];
  auVar7._4_12_ = in_XMM5._4_12_;
  auVar7._0_4_ = fVar2 * fVar2;
  fVar5 = fVar1 * fVar1 + auVar7._0_4_ + fVar3 * fVar3 + fVar4 * fVar4;
  auVar8._4_12_ = in_register_00001304;
  auVar8._0_4_ = fVar5;
  auVar8 = rsqrtss(auVar7,auVar8);
  fVar6 = auVar8._0_4_;
  fVar6 = (DAT_006df0a0 - fVar5 * fVar6 * fVar6) * _DAT_006df090 * fVar6;
  *param_1 = fVar1 * fVar6;
  param_1[1] = fVar2 * fVar6;
  param_1[2] = fVar3 * fVar6;
  param_1[3] = fVar4 * fVar6;
  return param_1;
}


// ==== 0x5eb477 FUN_005eb477

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_005eb477(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
            undefined8 *param_5,float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar7 = param_6 * param_6;
  fVar8 = param_6 * fVar7;
  fVar3 = param_6 * _DAT_006df060 + _DAT_006df070 + fVar7 * _DAT_006df050 + fVar8 * _DAT_006df040;
  fVar4 = param_6 * fRam006df064 + fRam006df074 + fVar7 * fRam006df054 + fVar8 * fRam006df044;
  fVar5 = param_6 * fRam006df068 + fRam006df078 + fVar7 * fRam006df058 + fVar8 * fRam006df048;
  fVar6 = param_6 * fRam006df06c + fRam006df07c + fVar7 * fRam006df05c + fVar8 * fRam006df04c;
  fVar7 = *(float *)(param_2 + 1);
  fVar8 = *(float *)(param_3 + 1);
  fVar1 = *(float *)(param_4 + 1);
  fVar2 = *(float *)(param_5 + 1);
  *param_1 = CONCAT44((float)((ulonglong)*param_2 >> 0x20) * fVar3 +
                      (float)((ulonglong)*param_3 >> 0x20) * fVar4 +
                      (float)((ulonglong)*param_4 >> 0x20) * fVar5 +
                      (float)((ulonglong)*param_5 >> 0x20) * fVar6,
                      (float)*param_2 * fVar3 + (float)*param_3 * fVar4 + (float)*param_4 * fVar5 +
                      (float)*param_5 * fVar6);
  *(float *)(param_1 + 1) = fVar7 * fVar3 + fVar8 * fVar4 + fVar1 * fVar5 + fVar2 * fVar6;
  return param_1;
}


// ==== 0x5eb529 FUN_005eb529

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_005eb529(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
            undefined8 *param_5,float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar4 = param_6 * param_6;
  fVar5 = param_6 * fVar4;
  fVar1 = param_6 * _DAT_006df060 + _DAT_006df070 + fVar4 * _DAT_006df050 + fVar5 * _DAT_006df040;
  fVar2 = param_6 * fRam006df064 + fRam006df074 + fVar4 * fRam006df054 + fVar5 * fRam006df044;
  fVar3 = param_6 * fRam006df068 + fRam006df078 + fVar4 * fRam006df058 + fVar5 * fRam006df048;
  fVar4 = param_6 * fRam006df06c + fRam006df07c + fVar4 * fRam006df05c + fVar5 * fRam006df04c;
  *param_1 = CONCAT44((float)((ulonglong)*param_2 >> 0x20) * fVar1 +
                      (float)((ulonglong)*param_4 >> 0x20) * fVar3 +
                      (float)((ulonglong)*param_3 >> 0x20) * fVar2 +
                      (float)((ulonglong)*param_5 >> 0x20) * fVar4,
                      (float)*param_2 * fVar1 + (float)*param_4 * fVar3 +
                      (float)*param_3 * fVar2 + (float)*param_5 * fVar4);
  return param_1;
}


// ==== 0x5eb5ae FUN_005eb5ae

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_005eb5ae(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                    float param_6)

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
  
  fVar15 = param_6 * param_6;
  fVar16 = param_6 * fVar15;
  fVar11 = param_6 * _DAT_006df060 + _DAT_006df070 + fVar15 * _DAT_006df050 + fVar16 * _DAT_006df040
  ;
  fVar12 = param_6 * fRam006df064 + fRam006df074 + fVar15 * fRam006df054 + fVar16 * fRam006df044;
  fVar13 = param_6 * fRam006df068 + fRam006df078 + fVar15 * fRam006df058 + fVar16 * fRam006df048;
  fVar14 = param_6 * fRam006df06c + fRam006df07c + fVar15 * fRam006df05c + fVar16 * fRam006df04c;
  fVar15 = param_2[1];
  fVar16 = param_2[2];
  fVar1 = param_2[3];
  fVar2 = param_3[1];
  fVar3 = param_3[2];
  fVar4 = param_3[3];
  fVar5 = param_4[1];
  fVar6 = param_4[2];
  fVar7 = param_4[3];
  fVar8 = param_5[1];
  fVar9 = param_5[2];
  fVar10 = param_5[3];
  *param_1 = *param_2 * fVar11 + *param_3 * fVar12 + *param_4 * fVar13 + *param_5 * fVar14;
  param_1[1] = fVar15 * fVar11 + fVar2 * fVar12 + fVar5 * fVar13 + fVar8 * fVar14;
  param_1[2] = fVar16 * fVar11 + fVar3 * fVar12 + fVar6 * fVar13 + fVar9 * fVar14;
  param_1[3] = fVar1 * fVar11 + fVar4 * fVar12 + fVar7 * fVar13 + fVar10 * fVar14;
  return param_1;
}


// ==== 0x5eb653 FUN_005eb653

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_005eb653(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
            undefined8 *param_5,float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar7 = param_6 * param_6;
  fVar8 = param_6 * fVar7;
  fVar3 = param_6 * _DAT_006df020 + _DAT_006df030 + fVar7 * _DAT_006df010 + fVar8 * _DAT_006df000;
  fVar4 = param_6 * fRam006df024 + fVar7 * fRam006df014 + fVar8 * fRam006df004;
  fVar5 = param_6 * fRam006df028 + fVar7 * fRam006df018 + fVar8 * fRam006df008;
  fVar6 = param_6 * fRam006df02c + fVar7 * fRam006df01c + fVar8 * fRam006df00c;
  fVar7 = *(float *)(param_2 + 1);
  fVar8 = *(float *)(param_3 + 1);
  fVar1 = *(float *)(param_4 + 1);
  fVar2 = *(float *)(param_5 + 1);
  *param_1 = CONCAT44((float)((ulonglong)*param_2 >> 0x20) * fVar3 +
                      (float)((ulonglong)*param_3 >> 0x20) * fVar4 +
                      (float)((ulonglong)*param_4 >> 0x20) * fVar5 +
                      (float)((ulonglong)*param_5 >> 0x20) * fVar6,
                      (float)*param_2 * fVar3 + (float)*param_3 * fVar4 + (float)*param_4 * fVar5 +
                      (float)*param_5 * fVar6);
  *(float *)(param_1 + 1) = fVar7 * fVar3 + fVar8 * fVar4 + fVar1 * fVar5 + fVar2 * fVar6;
  return param_1;
}


// ==== 0x5eb706 FUN_005eb706

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_005eb706(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                    float param_6)

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
  
  fVar15 = param_6 * param_6;
  fVar16 = param_6 * fVar15;
  fVar11 = param_6 * _DAT_006df020 + _DAT_006df030 + fVar15 * _DAT_006df010 + fVar16 * _DAT_006df000
  ;
  fVar12 = param_6 * fRam006df024 + fVar15 * fRam006df014 + fVar16 * fRam006df004;
  fVar13 = param_6 * fRam006df028 + fVar15 * fRam006df018 + fVar16 * fRam006df008;
  fVar14 = param_6 * fRam006df02c + fVar15 * fRam006df01c + fVar16 * fRam006df00c;
  fVar15 = param_2[1];
  fVar16 = param_2[2];
  fVar1 = param_2[3];
  fVar2 = param_3[1];
  fVar3 = param_3[2];
  fVar4 = param_3[3];
  fVar5 = param_4[1];
  fVar6 = param_4[2];
  fVar7 = param_4[3];
  fVar8 = param_5[1];
  fVar9 = param_5[2];
  fVar10 = param_5[3];
  *param_1 = *param_2 * fVar11 + *param_3 * fVar12 + *param_4 * fVar13 + *param_5 * fVar14;
  param_1[1] = fVar15 * fVar11 + fVar2 * fVar12 + fVar5 * fVar13 + fVar8 * fVar14;
  param_1[2] = fVar16 * fVar11 + fVar3 * fVar12 + fVar6 * fVar13 + fVar9 * fVar14;
  param_1[3] = fVar1 * fVar11 + fVar4 * fVar12 + fVar7 * fVar13 + fVar10 * fVar14;
  return param_1;
}


// ==== 0x5eb7a0 FUN_005eb7a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_005eb7a0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
            undefined8 *param_5,float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar4 = param_6 * param_6;
  fVar5 = param_6 * fVar4;
  fVar1 = param_6 * _DAT_006df020 + _DAT_006df030 + fVar4 * _DAT_006df010 + fVar5 * _DAT_006df000;
  fVar2 = param_6 * fRam006df024 + fVar4 * fRam006df014 + fVar5 * fRam006df004;
  fVar3 = param_6 * fRam006df028 + fVar4 * fRam006df018 + fVar5 * fRam006df008;
  fVar4 = param_6 * fRam006df02c + fVar4 * fRam006df01c + fVar5 * fRam006df00c;
  *param_1 = CONCAT44((float)((ulonglong)*param_2 >> 0x20) * fVar1 +
                      (float)((ulonglong)*param_4 >> 0x20) * fVar3 +
                      (float)((ulonglong)*param_3 >> 0x20) * fVar2 +
                      (float)((ulonglong)*param_5 >> 0x20) * fVar4,
                      (float)*param_2 * fVar1 + (float)*param_4 * fVar3 +
                      (float)*param_3 * fVar2 + (float)*param_5 * fVar4);
  return param_1;
}


// ==== 0x5eb826 FUN_005eb826

undefined8 *
FUN_005eb826(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
            float param_5,float param_6)

{
  float fVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  float fVar4;
  float fVar5;
  
  fVar1 = *(float *)(param_2 + 1);
  uVar2 = *param_3;
  fVar4 = (float)*param_2;
  fVar5 = (float)((ulonglong)*param_2 >> 0x20);
  uVar3 = *param_4;
  *(float *)(param_1 + 1) =
       (*(float *)(param_3 + 1) - fVar1) * param_5 + fVar1 +
       (*(float *)(param_4 + 1) - fVar1) * param_6;
  *param_1 = CONCAT44(((float)((ulonglong)uVar2 >> 0x20) - fVar5) * param_5 + fVar5 +
                      ((float)((ulonglong)uVar3 >> 0x20) - fVar5) * param_6,
                      ((float)uVar2 - fVar4) * param_5 + fVar4 + ((float)uVar3 - fVar4) * param_6);
  return param_1;
}


// ==== 0x5eb883 FUN_005eb883

float * FUN_005eb883(float *param_1,float *param_2,float *param_3,float *param_4,float param_5,
                    float param_6)

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
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = param_2[3];
  fVar5 = param_3[1];
  fVar6 = param_3[2];
  fVar7 = param_3[3];
  fVar8 = param_4[1];
  fVar9 = param_4[2];
  fVar10 = param_4[3];
  *param_1 = (*param_3 - fVar1) * param_5 + fVar1 + (*param_4 - fVar1) * param_6;
  param_1[1] = (fVar5 - fVar2) * param_5 + fVar2 + (fVar8 - fVar2) * param_6;
  param_1[2] = (fVar6 - fVar3) * param_5 + fVar3 + (fVar9 - fVar3) * param_6;
  param_1[3] = (fVar7 - fVar4) * param_5 + fVar4 + (fVar10 - fVar4) * param_6;
  return param_1;
}


// ==== 0x5eb8cc FUN_005eb8cc

undefined8 *
FUN_005eb8cc(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
            float param_5,float param_6)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)*param_2;
  fVar2 = (float)((ulonglong)*param_2 >> 0x20);
  *param_1 = CONCAT44(((float)((ulonglong)*param_3 >> 0x20) - fVar2) * param_5 + fVar2 +
                      ((float)((ulonglong)*param_4 >> 0x20) - fVar2) * param_6,
                      ((float)*param_3 - fVar1) * param_5 + fVar1 +
                      ((float)*param_4 - fVar1) * param_6);
  return param_1;
}


// ==== 0x5eb91e FUN_005eb91e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_005eb91e(undefined8 *param_1,float *param_2,undefined8 *param_3,undefined8 *param_4)

{
  float fVar1;
  float fVar2;
  undefined1 auVar3 [16];
  float fVar6;
  float fVar7;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float in_XMM6_Dc;
  float in_XMM6_Dd;
  
  fVar12 = param_2[3];
  fVar1 = *(float *)(param_3 + 1);
  fVar2 = *(float *)(param_4 + 1);
  fVar8 = (float)*param_3;
  fVar9 = (float)((ulonglong)*param_3 >> 0x20);
  fVar14 = fVar9 * param_2[1];
  fVar10 = (float)*param_4;
  fVar6 = *param_2 * fVar10;
  fVar11 = (float)((ulonglong)*param_4 >> 0x20);
  fVar7 = param_2[1] * fVar11;
  fVar13 = fVar12 * 0.0 + fVar14;
  auVar5._0_4_ = param_2[2] * fVar2 + fVar6;
  auVar5._4_4_ = fVar12 * 0.0 + fVar7;
  auVar5._8_4_ = fVar6 + in_XMM6_Dc;
  auVar5._12_4_ = fVar7 + in_XMM6_Dd;
  fVar6 = fVar1 * param_2[2] + fVar8 * *param_2 + fVar14;
  auVar4._4_12_ = auVar5._4_12_;
  auVar4._0_4_ = auVar5._0_4_ + fVar7;
  fVar7 = fVar6 - auVar4._0_4_;
  if (fVar7 == _DAT_00709484) {
    param_1 = (undefined8 *)0x0;
  }
  else {
    auVar3._4_4_ = fVar14;
    auVar3._0_4_ = fVar7;
    auVar3._8_4_ = fVar13;
    auVar3._12_4_ = fVar13;
    auVar5 = rcpss(auVar4,auVar3);
    fVar13 = auVar5._0_4_;
    fVar12 = (fVar6 + fVar12) * ((fVar13 + fVar13) - fVar7 * fVar13 * fVar13);
    *param_1 = CONCAT44(fVar9 + fVar12 * (fVar11 - fVar9),fVar8 + fVar12 * (fVar10 - fVar8));
    *(float *)(param_1 + 1) = fVar1 + fVar12 * (fVar2 - fVar1);
  }
  return param_1;
}


// ==== 0x5eb9cc FUN_005eb9cc

float10 FUN_005eb9cc(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined8 uVar6;
  float fVar7;
  float fVar8;
  undefined8 uVar9;
  float fVar10;
  float fVar11;
  undefined8 uVar12;
  float fVar13;
  float fVar14;
  undefined8 uVar15;
  float fVar16;
  float local_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  
  if (((uint)param_1 & 0xf) == 0) {
    local_30 = *param_1;
    fStack_2c = param_1[1];
    fStack_28 = param_1[2];
    fStack_24 = param_1[3];
    uVar12 = *(undefined8 *)(param_1 + 4);
    uVar15 = *(undefined8 *)(param_1 + 6);
    uVar6 = *(undefined8 *)(param_1 + 0xc);
    uVar9 = *(undefined8 *)(param_1 + 0xe);
    fVar1 = param_1[8];
    fVar2 = param_1[9];
    fVar3 = param_1[10];
    fVar4 = param_1[0xb];
  }
  else {
    local_30 = *param_1;
    fStack_2c = param_1[1];
    fStack_28 = param_1[2];
    fStack_24 = (float)((ulonglong)*(undefined8 *)(param_1 + 2) >> 0x20);
    uVar12 = *(undefined8 *)(param_1 + 4);
    uVar15 = *(undefined8 *)(param_1 + 6);
    fVar1 = (float)*(undefined8 *)(param_1 + 8);
    fVar2 = (float)((ulonglong)*(undefined8 *)(param_1 + 8) >> 0x20);
    fVar3 = (float)*(undefined8 *)(param_1 + 10);
    fVar4 = (float)((ulonglong)*(undefined8 *)(param_1 + 10) >> 0x20);
    uVar6 = *(undefined8 *)(param_1 + 0xc);
    uVar9 = *(undefined8 *)(param_1 + 0xe);
  }
  fVar5 = (float)uVar6;
  fVar7 = (float)((ulonglong)uVar6 >> 0x20);
  fVar8 = (float)uVar9;
  fVar10 = (float)((ulonglong)uVar9 >> 0x20);
  fVar11 = (float)uVar12;
  fVar13 = (float)((ulonglong)uVar12 >> 0x20);
  fVar14 = (float)uVar15;
  fVar16 = (float)((ulonglong)uVar15 >> 0x20);
  return (float10)(((fVar13 * (fVar3 * fVar10 - fVar4 * fVar8) +
                     fVar14 * (fVar4 * fVar7 - fVar2 * fVar10) +
                    fVar16 * (fVar2 * fVar8 - fVar3 * fVar7)) * local_30 +
                   (fVar16 * (fVar1 * fVar7 - fVar2 * fVar5) +
                    fVar11 * (fVar2 * fVar10 - fVar4 * fVar7) +
                   fVar13 * (fVar4 * fVar5 - fVar1 * fVar10)) * fStack_28) -
                  ((fVar14 * (fVar4 * fVar5 - fVar1 * fVar10) +
                    fVar16 * (fVar1 * fVar8 - fVar3 * fVar5) +
                   fVar11 * (fVar3 * fVar10 - fVar4 * fVar8)) * fStack_2c +
                  (fVar11 * (fVar2 * fVar8 - fVar3 * fVar7) +
                   fVar13 * (fVar3 * fVar5 - fVar1 * fVar8) +
                  fVar14 * (fVar1 * fVar7 - fVar2 * fVar5)) * fStack_24));
}


// ==== 0x5ebad7 FUN_005ebad7

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ebad7(float *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

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
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  
  fVar1 = *(float *)(param_2 + 1);
  fVar8 = (float)*param_2;
  fVar9 = (float)((ulonglong)*param_2 >> 0x20);
  fVar4 = fVar8 - (float)*param_3;
  fVar5 = fVar9 - (float)((ulonglong)*param_3 >> 0x20);
  fVar6 = fVar8 - (float)*param_4;
  fVar7 = fVar9 - (float)((ulonglong)*param_4 >> 0x20);
  fVar2 = (fVar1 - *(float *)(param_4 + 1)) * fVar5 - (fVar1 - *(float *)(param_3 + 1)) * fVar7;
  fVar3 = fVar6 * (fVar1 - *(float *)(param_3 + 1)) - fVar4 * (fVar1 - *(float *)(param_4 + 1));
  fVar4 = fVar7 * fVar4 - fVar5 * fVar6;
  fVar7 = fVar4 * fVar4;
  fVar5 = fVar2 * fVar2 + fVar7;
  fVar6 = fVar3 * fVar3 + 0.0;
  auVar10._4_4_ = fVar5;
  auVar10._0_4_ = fVar6;
  auVar10._8_4_ = fVar5;
  auVar10._12_4_ = fVar5;
  auVar11._4_4_ = fVar6;
  auVar11._0_4_ = fVar5 + fVar6;
  auVar11._8_4_ = fVar7 + fVar7;
  auVar11._12_4_ = 0;
  auVar11 = rsqrtss(auVar10,auVar11);
  fVar7 = auVar11._0_4_;
  fVar5 = _DAT_006df0c0 * fVar7 * (_DAT_006df0d0 - (fVar5 + fVar6) * fVar7 * fVar7);
  *param_1 = fVar2 * fVar5;
  param_1[1] = fVar3 * fVar5;
  param_1[2] = fVar4 * fVar5;
  param_1[3] = fVar5 * 0.0;
  param_1[3] = (float)((uint)(fVar2 * fVar5 * fVar8 + fVar4 * fVar5 * fVar1 + fVar3 * fVar5 * fVar9)
                      ^ _DAT_006df0b0);
  return;
}


// ==== 0x5ebbd7 FUN_005ebbd7

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ebbd7(float *param_1,undefined8 *param_2)

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
  float fVar12;
  float fVar13;
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  
  fVar5 = (float)*param_2;
  fVar6 = (float)((ulonglong)*param_2 >> 0x20);
  fVar7 = (float)param_2[1];
  fVar8 = (float)((ulonglong)param_2[1] >> 0x20);
  fVar1 = (float)((uint)fVar5 & _DAT_006df150);
  fVar2 = (float)((uint)fVar6 & uRam006df154);
  fVar3 = (float)((uint)fVar7 & uRam006df158);
  fVar4 = (float)((uint)fVar8 & uRam006df15c);
  fVar3 = fVar3 * fVar3;
  fVar4 = fVar4 * fVar4;
  fVar1 = fVar1 * fVar1 + fVar3;
  fVar2 = fVar2 * fVar2 + fVar4;
  auVar10._4_4_ = fVar1;
  auVar10._0_4_ = fVar2;
  auVar10._8_4_ = fVar1;
  auVar10._12_4_ = fVar1;
  auVar11._4_4_ = fVar2;
  auVar11._0_4_ = fVar1 + fVar2;
  auVar11._8_4_ = fVar3 + fVar3;
  auVar11._12_4_ = fVar4 + fVar4;
  auVar11 = rsqrtss(auVar10,auVar11);
  fVar3 = auVar11._0_4_;
  fVar1 = DAT_006df130 * fVar3 * (DAT_006df140 - (fVar1 + fVar2) * fVar3 * fVar3);
  fVar5 = fVar5 * fVar1;
  fVar6 = fVar6 * fVar1;
  fVar7 = fVar7 * fVar1;
  fVar8 = fVar8 * fVar1;
  fVar1 = _DAT_006df110 * fVar5;
  fVar2 = fRam006df114 * fVar6;
  fVar3 = fRam006df118 * fVar7;
  fVar4 = fRam006df11c * fVar8;
  fVar9 = fVar1 * fVar6 + _DAT_006df120;
  fVar12 = fVar2 * fVar6 + fRam006df124;
  fVar13 = fVar3 * fVar6 + fRam006df128;
  fVar6 = fVar4 * fVar6 + fRam006df12c;
  fVar14 = fVar1 * fVar7 + _DAT_006df100;
  fVar15 = fVar2 * fVar7 + fRam006df104;
  fVar16 = fVar3 * fVar7 + fRam006df108;
  fVar7 = fVar4 * fVar7 + fRam006df10c;
  fVar17 = fVar1 * fVar8 + _DAT_006df0f0;
  fVar18 = fVar2 * fVar8 + fRam006df0f4;
  fVar19 = fVar3 * fVar8 + fRam006df0f8;
  fVar8 = fVar4 * fVar8 + fRam006df0fc;
  fVar2 = fVar2 * fVar5 + fRam006df0e4;
  fVar3 = fVar3 * fVar5 + fRam006df0e8;
  fVar4 = fVar4 * fVar5 + fRam006df0ec;
  *param_1 = fVar1 * fVar5 + _DAT_006df0e0;
  param_1[1] = fVar2;
  param_1[2] = fVar3;
  param_1[3] = fVar4;
  param_1[4] = fVar9;
  param_1[5] = fVar12;
  param_1[6] = fVar13;
  param_1[7] = fVar6;
  param_1[8] = fVar14;
  param_1[9] = fVar15;
  param_1[10] = fVar16;
  param_1[0xb] = fVar7;
  param_1[0xc] = fVar17;
  param_1[0xd] = fVar18;
  param_1[0xe] = fVar19;
  param_1[0xf] = fVar8;
  return;
}


// ==== 0x5ebce3 FUN_005ebce3

void FUN_005ebce3(float *param_1,undefined8 *param_2,float *param_3)

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
  
  fVar1 = (float)*param_2;
  fVar3 = (float)((ulonglong)*param_2 >> 0x20);
  fVar7 = *(float *)(param_2 + 1);
  if (((uint)param_3 & 0xf) == 0) {
    fVar11 = param_3[8] * fVar7 + param_3[0xc];
    fVar12 = param_3[9] * fVar7 + param_3[0xd];
    fVar13 = param_3[10] * fVar7 + param_3[0xe];
    fVar14 = param_3[0xb] * fVar7 + param_3[0xf];
    fVar7 = param_3[4];
    fVar8 = param_3[5];
    fVar9 = param_3[6];
    fVar10 = param_3[7];
    fVar2 = *param_3;
    fVar4 = param_3[1];
    fVar5 = param_3[2];
    fVar6 = param_3[3];
  }
  else {
    fVar11 = (float)*(undefined8 *)(param_3 + 8) * fVar7 + (float)*(undefined8 *)(param_3 + 0xc);
    fVar12 = (float)((ulonglong)*(undefined8 *)(param_3 + 8) >> 0x20) * fVar7 +
             (float)((ulonglong)*(undefined8 *)(param_3 + 0xc) >> 0x20);
    fVar13 = (float)*(undefined8 *)(param_3 + 10) * fVar7 + (float)*(undefined8 *)(param_3 + 0xe);
    fVar14 = (float)((ulonglong)*(undefined8 *)(param_3 + 10) >> 0x20) * fVar7 +
             (float)((ulonglong)*(undefined8 *)(param_3 + 0xe) >> 0x20);
    fVar7 = (float)*(undefined8 *)(param_3 + 4);
    fVar8 = (float)((ulonglong)*(undefined8 *)(param_3 + 4) >> 0x20);
    fVar9 = (float)*(undefined8 *)(param_3 + 6);
    fVar10 = (float)((ulonglong)*(undefined8 *)(param_3 + 6) >> 0x20);
    fVar2 = (float)*(undefined8 *)param_3;
    fVar4 = (float)((ulonglong)*(undefined8 *)param_3 >> 0x20);
    fVar5 = (float)*(undefined8 *)(param_3 + 2);
    fVar6 = (float)((ulonglong)*(undefined8 *)(param_3 + 2) >> 0x20);
  }
  *param_1 = fVar2 * fVar1 + fVar7 * fVar3 + fVar11;
  param_1[1] = fVar4 * fVar1 + fVar8 * fVar3 + fVar12;
  param_1[2] = fVar5 * fVar1 + fVar9 * fVar3 + fVar13;
  param_1[3] = fVar6 * fVar1 + fVar10 * fVar3 + fVar14;
  return;
}


// ==== 0x5ebdb7 FUN_005ebdb7

void FUN_005ebdb7(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined1 auVar6 [16];
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  if (fVar4 < 1.4210855e-14) {
    fVar4 = 0.0;
    *param_1 = 0.0;
    param_1[1] = 0.0;
  }
  else {
    auVar6 = rsqrtss(ZEXT416(0x28800000),ZEXT416((uint)fVar4));
    fVar5 = auVar6._0_4_;
    fVar4 = fVar5 * 0.5 * (3.0 - fVar4 * fVar5 * fVar5);
    *param_1 = fVar4 * fVar1;
    param_1[1] = fVar4 * fVar2;
    fVar4 = fVar4 * fVar3;
  }
  param_1[2] = fVar4;
  return;
}


// ==== 0x5ebea7 FUN_005ebea7

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ebea7(float *param_1,float *param_2,float *param_3)

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
  float fVar17;
  float fVar18;
  undefined1 in_XMM5 [16];
  undefined1 auVar16 [16];
  float fVar19;
  
  fVar5 = (float)((uint)*param_3 & _DAT_006df1a0);
  fVar8 = (float)((uint)param_3[1] & uRam006df1a4);
  fVar9 = (float)((uint)param_3[2] & uRam006df1a8);
  fVar10 = (float)((uint)param_3[3] & uRam006df1ac);
  fVar6 = fVar5 * fVar5 + fVar9 * fVar9;
  fVar9 = fVar8 * fVar8 + fVar10 * fVar10 + fVar6;
  fVar5 = fVar6;
  fVar8 = fVar6;
  if (fVar9 != 0.0) {
    if ((_DAT_007094b0 & 1) == 0) {
      _DAT_007094b0 = _DAT_007094b0 | 1;
      _DAT_007094a0 = 0.5;
      uRam007094a4 = 0;
      uRam007094a8 = 0;
      uRam007094ac = 0;
    }
    if ((_DAT_007094b0 & 2) == 0) {
      _DAT_007094b0 = _DAT_007094b0 | 2;
      _DAT_00709490 = 3.0;
      uRam00709494 = 0;
      uRam00709498 = 0;
      uRam0070949c = 0;
    }
    auVar16._4_4_ = fVar6;
    auVar16._0_4_ = fVar9;
    auVar16._8_4_ = fVar6;
    auVar16._12_4_ = fVar6;
    auVar16 = rsqrtss(in_XMM5,auVar16);
    fVar5 = auVar16._0_4_;
    fVar8 = _DAT_007094a0 * fVar5 * (_DAT_00709490 - fVar9 * fVar5 * fVar5);
    fVar9 = *param_3 * fVar8;
    fVar6 = param_3[1] * fVar8;
    fVar5 = param_3[2] * fVar8;
    fVar8 = param_3[3] * fVar8;
  }
  fVar10 = *param_2;
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  fVar3 = param_2[3];
  fVar4 = fVar9 * fVar10 + fVar5 * fVar2 + fVar6 * fVar1 + fVar8 * fVar3;
  fVar9 = (float)((uint)fVar9 ^ _DAT_006df160);
  fVar6 = (float)((uint)fVar6 ^ uRam006df164);
  fVar5 = (float)((uint)fVar5 ^ uRam006df168);
  fVar8 = (float)((uint)fVar8 ^ uRam006df16c);
  fVar11 = fVar10 * fVar6 + (float)((uint)fVar4 & _DAT_006df170);
  fVar12 = fVar1 * fVar6 + (float)((uint)fVar4 & uRam006df174);
  fVar13 = fVar2 * fVar6 + (float)((uint)fVar4 & uRam006df178);
  fVar14 = fVar3 * fVar6 + (float)((uint)fVar4 & uRam006df17c);
  fVar15 = fVar10 * fVar5 + (float)((uint)fVar4 & _DAT_006df180);
  fVar17 = fVar1 * fVar5 + (float)((uint)fVar4 & uRam006df184);
  fVar18 = fVar2 * fVar5 + (float)((uint)fVar4 & uRam006df188);
  fVar19 = fVar3 * fVar5 + (float)((uint)fVar4 & uRam006df18c);
  fVar7 = fVar10 * fVar9 + fVar4;
  fVar5 = fVar10 * fVar8 + (float)((uint)fVar4 & _DAT_006df190);
  fVar6 = fVar1 * fVar8 + (float)((uint)fVar4 & uRam006df194);
  fVar10 = fVar2 * fVar8 + (float)((uint)fVar4 & uRam006df198);
  fVar8 = fVar3 * fVar8 + (float)((uint)fVar4 & uRam006df19c);
  if (((uint)param_1 & 0xf) == 0) {
    *param_1 = fVar7;
    param_1[1] = fVar1 * fVar9;
    param_1[2] = fVar2 * fVar9;
    param_1[3] = fVar3 * fVar9;
    param_1[4] = fVar11;
    param_1[5] = fVar12;
    param_1[6] = fVar13;
    param_1[7] = fVar14;
    param_1[8] = fVar15;
    param_1[9] = fVar17;
    param_1[10] = fVar18;
    param_1[0xb] = fVar19;
    param_1[0xc] = fVar5;
    param_1[0xd] = fVar6;
    param_1[0xe] = fVar10;
    param_1[0xf] = fVar8;
  }
  else {
    *(ulonglong *)param_1 = CONCAT44(fVar1 * fVar9,fVar7);
    *(ulonglong *)(param_1 + 2) = CONCAT44(fVar3 * fVar9,fVar2 * fVar9);
    *(ulonglong *)(param_1 + 4) = CONCAT44(fVar12,fVar11);
    *(ulonglong *)(param_1 + 6) = CONCAT44(fVar14,fVar13);
    param_1[8] = fVar15;
    param_1[9] = fVar17;
    param_1[10] = fVar18;
    param_1[0xb] = fVar19;
    *(ulonglong *)(param_1 + 0xc) = CONCAT44(fVar6,fVar5);
    *(ulonglong *)(param_1 + 0xe) = CONCAT44(fVar8,fVar10);
  }
  return;
}


// ==== 0x5ec06e FUN_005ec06e

undefined8 *
FUN_005ec06e(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,undefined4 param_5,
            uint param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined8 uVar5;
  float fVar6;
  int iVar7;
  uint uVar8;
  undefined8 *puVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float local_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float local_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float local_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float local_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float local_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float local_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float local_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float local_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float local_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float local_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float local_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float local_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float local_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float local_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float local_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  uVar8 = -(uint)(10 < param_6) & param_6 & 0xfffffffc;
  iVar7 = param_6 - uVar8;
  uVar8 = uVar8 >> 2;
  puVar9 = param_1;
  if (uVar8 != 0) {
    FUN_005e9c6c(param_5);
    for (; uVar8 != 0; uVar8 = uVar8 - 1) {
      fVar12 = (float)*param_3;
      fVar13 = (float)((ulonglong)*param_3 >> 0x20);
      fVar10 = (float)*(undefined8 *)((int)param_3 + param_4);
      fVar11 = (float)((ulonglong)*(undefined8 *)((int)param_3 + param_4) >> 0x20);
      uVar5 = *(undefined8 *)((int)param_3 + param_4 * 2);
      fVar6 = (float)uVar5;
      fVar16 = (float)((ulonglong)uVar5 >> 0x20);
      uVar5 = *(undefined8 *)(param_4 * 3 + (int)param_3);
      fVar14 = (float)uVar5;
      fVar15 = (float)((ulonglong)uVar5 >> 0x20);
      fVar1 = *(float *)(param_4 * 3 + 8 + (int)param_3);
      fVar2 = *(float *)((int)param_3 + param_4 * 2 + 8);
      fVar3 = *(float *)(param_4 + 8 + (int)param_3);
      fVar4 = *(float *)(param_3 + 0xc);
      *puVar9 = CONCAT44(fVar12 * local_100 + fVar13 * local_c0 + fVar4 * local_80 + local_40,
                         fVar12 * local_110 + fVar13 * local_d0 + fVar4 * local_90 + local_50);
      puVar9[0x10] = CONCAT44(fVar12 * local_e0 + fVar13 * local_a0 + fVar4 * local_60 + local_20,
                              fVar12 * local_f0 + fVar13 * local_b0 + fVar4 * local_70 + local_30);
      *(ulonglong *)((int)puVar9 + param_2) =
           CONCAT44(fVar10 * fStack_fc + fVar11 * fStack_bc + fVar3 * fStack_7c + fStack_3c,
                    fVar10 * fStack_10c + fVar11 * fStack_cc + fVar3 * fStack_8c + fStack_4c);
      *(ulonglong *)(param_2 + 8 + (int)puVar9) =
           CONCAT44(fVar10 * fStack_dc + fVar11 * fStack_9c + fVar3 * fStack_5c + fStack_1c,
                    fVar10 * fStack_ec + fVar11 * fStack_ac + fVar3 * fStack_6c + fStack_2c);
      *(ulonglong *)((int)puVar9 + param_2 * 2) =
           CONCAT44(fVar6 * fStack_f8 + fVar16 * fStack_b8 + fVar2 * fStack_78 + fStack_38,
                    fVar6 * fStack_108 + fVar16 * fStack_c8 + fVar2 * fStack_88 + fStack_48);
      *(ulonglong *)((int)puVar9 + param_2 * 2 + 8) =
           CONCAT44(fVar6 * fStack_d8 + fVar16 * fStack_98 + fVar2 * fStack_58 + fStack_18,
                    fVar6 * fStack_e8 + fVar16 * fStack_a8 + fVar2 * fStack_68 + fStack_28);
      *(ulonglong *)(param_2 * 3 + (int)puVar9) =
           CONCAT44(fVar14 * fStack_f4 + fVar15 * fStack_b4 + fVar1 * fStack_74 + fStack_34,
                    fVar14 * fStack_104 + fVar15 * fStack_c4 + fVar1 * fStack_84 + fStack_44);
      *(ulonglong *)(param_2 * 3 + 8 + (int)puVar9) =
           CONCAT44(fVar14 * fStack_d4 + fVar15 * fStack_94 + fVar1 * fStack_54 + fStack_14,
                    fVar14 * fStack_e4 + fVar15 * fStack_a4 + fVar1 * fStack_64 + fStack_24);
      param_3 = (undefined8 *)((int)param_3 + param_4 * 4);
      puVar9 = (undefined8 *)((int)puVar9 + param_2 * 4);
    }
  }
  for (; iVar7 != 0; iVar7 = iVar7 + -1) {
    FUN_005ebce3(puVar9,param_3,param_5);
    param_3 = (undefined8 *)((int)param_3 + param_4);
    puVar9 = (undefined8 *)((int)puVar9 + param_2);
  }
  return param_1;
}


// ==== 0x5ec274 FUN_005ec274

undefined8 *
FUN_005ec274(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,undefined4 param_5,
            uint param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float local_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float local_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float local_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float local_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float local_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float local_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float local_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float local_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float local_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float local_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float local_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  uVar4 = -(uint)(10 < param_6) & param_6 & 0xfffffffc;
  iVar3 = param_6 - uVar4;
  uVar4 = uVar4 >> 2;
  puVar5 = param_1;
  if (uVar4 != 0) {
    FUN_005e9c6c(param_5);
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      uVar1 = *(undefined8 *)((int)param_3 + param_4 * 2);
      fVar6 = (float)*param_3;
      fVar7 = (float)((ulonglong)*param_3 >> 0x20);
      fVar8 = (float)*(undefined8 *)((int)param_3 + param_4);
      fVar9 = (float)((ulonglong)*(undefined8 *)((int)param_3 + param_4) >> 0x20);
      uVar2 = *(undefined8 *)(param_4 * 3 + (int)param_3);
      fVar10 = (float)uVar1;
      fVar11 = (float)((ulonglong)uVar1 >> 0x20);
      fVar12 = (float)uVar2;
      fVar13 = (float)((ulonglong)uVar2 >> 0x20);
      *puVar5 = CONCAT44(fVar6 * local_100 + fVar7 * local_c0 + local_40,
                         fVar6 * local_110 + fVar7 * local_d0 + local_50);
      puVar5[0x10] = CONCAT44(fVar6 * local_e0 + fVar7 * local_a0 + local_20,
                              fVar6 * local_f0 + fVar7 * local_b0 + local_30);
      *(ulonglong *)((int)puVar5 + param_2) =
           CONCAT44(fVar8 * fStack_fc + fVar9 * fStack_bc + fStack_3c,
                    fVar8 * fStack_10c + fVar9 * fStack_cc + fStack_4c);
      *(ulonglong *)(param_2 + 8 + (int)puVar5) =
           CONCAT44(fVar8 * fStack_dc + fVar9 * fStack_9c + fStack_1c,
                    fVar8 * fStack_ec + fVar9 * fStack_ac + fStack_2c);
      *(ulonglong *)((int)puVar5 + param_2 * 2) =
           CONCAT44(fVar10 * fStack_f8 + fVar11 * fStack_b8 + fStack_38,
                    fVar10 * fStack_108 + fVar11 * fStack_c8 + fStack_48);
      *(ulonglong *)((int)puVar5 + param_2 * 2 + 8) =
           CONCAT44(fVar10 * fStack_d8 + fVar11 * fStack_98 + fStack_18,
                    fVar10 * fStack_e8 + fVar11 * fStack_a8 + fStack_28);
      *(ulonglong *)(param_2 * 3 + (int)puVar5) =
           CONCAT44(fVar12 * fStack_f4 + fVar13 * fStack_b4 + fStack_34,
                    fVar12 * fStack_104 + fVar13 * fStack_c4 + fStack_44);
      *(ulonglong *)(param_2 * 3 + 8 + (int)puVar5) =
           CONCAT44(fVar12 * fStack_d4 + fVar13 * fStack_94 + fStack_14,
                    fVar12 * fStack_e4 + fVar13 * fStack_a4 + fStack_24);
      param_3 = (undefined8 *)((int)param_3 + param_4 * 4);
      puVar5 = (undefined8 *)((int)puVar5 + param_2 * 4);
    }
  }
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    thunk_FUN_005abac4(puVar5,param_3,param_5);
    param_3 = (undefined8 *)((int)param_3 + param_4);
    puVar5 = (undefined8 *)((int)puVar5 + param_2);
  }
  return param_1;
}


// ==== 0x5ec402 FUN_005ec402

undefined8 *
FUN_005ec402(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,undefined4 param_5,
            uint param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar13;
  float fVar14;
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float local_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float local_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float local_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float local_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float local_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float local_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float local_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float local_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  uVar4 = -(uint)(10 < param_6) & param_6 & 0xfffffffc;
  iVar3 = param_6 - uVar4;
  uVar4 = uVar4 >> 2;
  puVar5 = param_1;
  if (uVar4 != 0) {
    FUN_005e9c6c(param_5);
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      fVar6 = (float)*param_3;
      fVar7 = (float)((ulonglong)*param_3 >> 0x20);
      fVar8 = (float)*(undefined8 *)((int)param_3 + param_4);
      fVar9 = (float)((ulonglong)*(undefined8 *)((int)param_3 + param_4) >> 0x20);
      uVar1 = *(undefined8 *)((int)param_3 + param_4 * 2);
      uVar2 = *(undefined8 *)(param_4 * 3 + (int)param_3);
      fVar16 = (float)uVar1;
      fVar17 = (float)((ulonglong)uVar1 >> 0x20);
      fVar18 = (float)uVar2;
      fVar19 = (float)((ulonglong)uVar2 >> 0x20);
      auVar11._0_4_ = fVar6 * local_e0 + fVar7 * local_a0;
      auVar11._4_4_ = fVar8 * fStack_dc + fVar9 * fStack_9c;
      auVar11._8_4_ = fVar16 * fStack_d8 + fVar17 * fStack_98;
      auVar11._12_4_ = fVar18 * fStack_d4 + fVar19 * fStack_94;
      auVar12._4_4_ = auVar11._4_4_ + fStack_1c;
      auVar12._0_4_ = auVar11._0_4_ + local_20;
      auVar12._8_4_ = auVar11._8_4_ + fStack_18;
      auVar12._12_4_ = auVar11._12_4_ + fStack_14;
      auVar12 = rcpps(auVar11,auVar12);
      fVar10 = auVar12._0_4_;
      fVar13 = auVar12._4_4_;
      fVar14 = auVar12._8_4_;
      fVar15 = auVar12._12_4_;
      fVar10 = (fVar10 + fVar10) - fVar10 * (auVar11._0_4_ + local_20) * fVar10;
      fVar13 = (fVar13 + fVar13) - fVar13 * (auVar11._4_4_ + fStack_1c) * fVar13;
      fVar14 = (fVar14 + fVar14) - fVar14 * (auVar11._8_4_ + fStack_18) * fVar14;
      fVar15 = (fVar15 + fVar15) - fVar15 * (auVar11._12_4_ + fStack_14) * fVar15;
      *puVar5 = CONCAT44((fVar6 * local_100 + fVar7 * local_c0 + local_40) * fVar10,
                         (fVar6 * local_110 + fVar7 * local_d0 + local_50) * fVar10);
      *(ulonglong *)((int)puVar5 + param_2) =
           CONCAT44((fVar8 * fStack_fc + fVar9 * fStack_bc + fStack_3c) * fVar13,
                    (fVar8 * fStack_10c + fVar9 * fStack_cc + fStack_4c) * fVar13);
      *(ulonglong *)((int)puVar5 + param_2 * 2) =
           CONCAT44((fVar16 * fStack_f8 + fVar17 * fStack_b8 + fStack_38) * fVar14,
                    (fVar16 * fStack_108 + fVar17 * fStack_c8 + fStack_48) * fVar14);
      *(ulonglong *)(param_2 * 3 + (int)puVar5) =
           CONCAT44((fVar18 * fStack_f4 + fVar19 * fStack_b4 + fStack_34) * fVar15,
                    (fVar18 * fStack_104 + fVar19 * fStack_c4 + fStack_44) * fVar15);
      param_3 = (undefined8 *)((int)param_3 + param_4 * 4);
      puVar5 = (undefined8 *)((int)puVar5 + param_2 * 4);
    }
  }
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    thunk_FUN_005abae8(puVar5,param_3,param_5);
    param_3 = (undefined8 *)((int)param_3 + param_4);
    puVar5 = (undefined8 *)((int)puVar5 + param_2);
  }
  return param_1;
}


// ==== 0x5ec568 FUN_005ec568

undefined8 *
FUN_005ec568(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,undefined4 param_5,
            uint param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float local_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float local_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float local_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float local_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  
  uVar4 = -(uint)(10 < param_6) & param_6 & 0xfffffffc;
  iVar3 = param_6 - uVar4;
  uVar4 = uVar4 >> 2;
  puVar5 = param_1;
  if (uVar4 != 0) {
    FUN_005e9c6c(param_5);
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      fVar6 = (float)*param_3;
      fVar7 = (float)((ulonglong)*param_3 >> 0x20);
      fVar8 = (float)*(undefined8 *)((int)param_3 + param_4);
      fVar9 = (float)((ulonglong)*(undefined8 *)((int)param_3 + param_4) >> 0x20);
      uVar1 = *(undefined8 *)((int)param_3 + param_4 * 2);
      uVar2 = *(undefined8 *)(param_4 * 3 + (int)param_3);
      fVar10 = (float)uVar1;
      fVar11 = (float)((ulonglong)uVar1 >> 0x20);
      fVar12 = (float)uVar2;
      fVar13 = (float)((ulonglong)uVar2 >> 0x20);
      *puVar5 = CONCAT44(fVar6 * local_100 + fVar7 * local_c0,fVar6 * local_110 + fVar7 * local_d0);
      *(ulonglong *)((int)puVar5 + param_2) =
           CONCAT44(fVar8 * fStack_fc + fVar9 * fStack_bc,fVar8 * fStack_10c + fVar9 * fStack_cc);
      *(ulonglong *)((int)puVar5 + param_2 * 2) =
           CONCAT44(fVar10 * fStack_f8 + fVar11 * fStack_b8,fVar10 * fStack_108 + fVar11 * fStack_c8
                   );
      *(ulonglong *)(param_2 * 3 + (int)puVar5) =
           CONCAT44(fVar12 * fStack_f4 + fVar13 * fStack_b4,fVar12 * fStack_104 + fVar13 * fStack_c4
                   );
      param_3 = (undefined8 *)((int)param_3 + param_4 * 4);
      puVar5 = (undefined8 *)((int)puVar5 + param_2 * 4);
    }
  }
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    thunk_FUN_005abb0c(puVar5,param_3,param_5);
    param_3 = (undefined8 *)((int)param_3 + param_4);
    puVar5 = (undefined8 *)((int)puVar5 + param_2);
  }
  return param_1;
}


// ==== 0x5ec678 FUN_005ec678

undefined8 *
FUN_005ec678(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,undefined4 param_5,
            uint param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  undefined8 *puVar8;
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
  float local_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float local_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float local_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float local_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float local_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float local_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float local_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float local_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float local_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float local_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float local_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float local_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float local_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float local_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float local_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  uVar7 = -(uint)(10 < param_6) & param_6 & 0xfffffffc;
  iVar6 = param_6 - uVar7;
  uVar7 = uVar7 >> 2;
  puVar8 = param_1;
  if (uVar7 != 0) {
    FUN_005e9c6c(param_5);
    for (; uVar7 != 0; uVar7 = uVar7 - 1) {
      fVar13 = (float)*param_3;
      fVar14 = (float)((ulonglong)*param_3 >> 0x20);
      fVar16 = (float)*(undefined8 *)((int)param_3 + param_4);
      fVar17 = (float)((ulonglong)*(undefined8 *)((int)param_3 + param_4) >> 0x20);
      uVar1 = *(undefined8 *)((int)param_3 + param_4 * 2);
      fVar19 = (float)((ulonglong)uVar1 >> 0x20);
      fVar3 = (float)uVar1;
      uVar1 = *(undefined8 *)(param_4 * 3 + (int)param_3);
      fVar11 = (float)uVar1;
      fVar12 = (float)((ulonglong)uVar1 >> 0x20);
      fVar15 = (float)((ulonglong)param_3[0x10] >> 0x20);
      uVar1 = *(undefined8 *)(param_4 + 8 + (int)param_3);
      fVar18 = (float)((ulonglong)uVar1 >> 0x20);
      uVar2 = *(undefined8 *)((int)param_3 + param_4 * 2 + 8);
      fVar9 = (float)uVar2;
      fVar10 = (float)((ulonglong)uVar2 >> 0x20);
      fVar4 = (float)param_3[0x10];
      fVar5 = (float)uVar1;
      uVar1 = *(undefined8 *)(param_4 * 3 + 8 + (int)param_3);
      fVar20 = (float)uVar1;
      fVar21 = (float)((ulonglong)uVar1 >> 0x20);
      *puVar8 = CONCAT44(fVar13 * local_100 + fVar14 * local_c0 + fVar4 * local_80 +
                         fVar15 * local_40,
                         fVar13 * local_110 + fVar14 * local_d0 + fVar4 * local_90 +
                         fVar15 * local_50);
      puVar8[0x10] = CONCAT44(fVar13 * local_e0 + fVar14 * local_a0 + fVar4 * local_60 +
                              fVar15 * local_20,
                              fVar13 * local_f0 + fVar14 * local_b0 + fVar4 * local_70 +
                              fVar15 * local_30);
      *(ulonglong *)((int)puVar8 + param_2) =
           CONCAT44(fVar16 * fStack_fc + fVar17 * fStack_bc + fVar5 * fStack_7c + fVar18 * fStack_3c
                    ,fVar16 * fStack_10c + fVar17 * fStack_cc + fVar5 * fStack_8c +
                     fVar18 * fStack_4c);
      *(ulonglong *)(param_2 + 8 + (int)puVar8) =
           CONCAT44(fVar16 * fStack_dc + fVar17 * fStack_9c + fVar5 * fStack_5c + fVar18 * fStack_1c
                    ,fVar16 * fStack_ec + fVar17 * fStack_ac + fVar5 * fStack_6c +
                     fVar18 * fStack_2c);
      *(ulonglong *)((int)puVar8 + param_2 * 2) =
           CONCAT44(fVar3 * fStack_f8 + fVar19 * fStack_b8 + fVar9 * fStack_78 + fVar10 * fStack_38,
                    fVar3 * fStack_108 + fVar19 * fStack_c8 + fVar9 * fStack_88 + fVar10 * fStack_48
                   );
      *(ulonglong *)((int)puVar8 + param_2 * 2 + 8) =
           CONCAT44(fVar3 * fStack_d8 + fVar19 * fStack_98 + fVar9 * fStack_58 + fVar10 * fStack_18,
                    fVar3 * fStack_e8 + fVar19 * fStack_a8 + fVar9 * fStack_68 + fVar10 * fStack_28)
      ;
      *(ulonglong *)(param_2 * 3 + (int)puVar8) =
           CONCAT44(fVar11 * fStack_f4 + fVar12 * fStack_b4 + fVar20 * fStack_74 +
                    fVar21 * fStack_34,
                    fVar11 * fStack_104 + fVar12 * fStack_c4 + fVar20 * fStack_84 +
                    fVar21 * fStack_44);
      *(ulonglong *)(param_2 * 3 + 8 + (int)puVar8) =
           CONCAT44(fVar11 * fStack_d4 + fVar12 * fStack_94 + fVar20 * fStack_54 +
                    fVar21 * fStack_14,
                    fVar11 * fStack_e4 + fVar12 * fStack_a4 + fVar20 * fStack_64 +
                    fVar21 * fStack_24);
      param_3 = (undefined8 *)((int)param_3 + param_4 * 4);
      puVar8 = (undefined8 *)((int)puVar8 + param_2 * 4);
    }
  }
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    FUN_005eb251(puVar8,param_3,param_5);
    param_3 = (undefined8 *)((int)param_3 + param_4);
    puVar8 = (undefined8 *)((int)puVar8 + param_2);
  }
  return param_1;
}


// ==== 0x5ec8b6 FUN_005ec8b6

undefined8 *
FUN_005ec8b6(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,undefined4 param_5,
            uint param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined8 uVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  uint uVar9;
  undefined8 *puVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float local_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float local_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float local_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float local_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float local_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float local_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float local_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float local_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float local_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  
  uVar9 = -(uint)(10 < param_6) & param_6 & 0xfffffffc;
  iVar8 = param_6 - uVar9;
  uVar9 = uVar9 >> 2;
  puVar10 = param_1;
  if (uVar9 != 0) {
    FUN_005e9c6c(param_5);
    for (; uVar9 != 0; uVar9 = uVar9 - 1) {
      fVar6 = (float)*param_3;
      fVar14 = (float)((ulonglong)*param_3 >> 0x20);
      uVar5 = *(undefined8 *)((int)param_3 + param_4 * 2);
      fVar7 = (float)uVar5;
      fVar11 = (float)((ulonglong)uVar5 >> 0x20);
      fVar12 = (float)*(undefined8 *)((int)param_3 + param_4);
      fVar13 = (float)((ulonglong)*(undefined8 *)((int)param_3 + param_4) >> 0x20);
      uVar5 = *(undefined8 *)(param_4 * 3 + (int)param_3);
      fVar15 = (float)uVar5;
      fVar16 = (float)((ulonglong)uVar5 >> 0x20);
      fVar1 = *(float *)(param_4 * 3 + 8 + (int)param_3);
      fVar2 = *(float *)((int)param_3 + param_4 * 2 + 8);
      fVar3 = *(float *)(param_4 + 8 + (int)param_3);
      fVar4 = *(float *)(param_3 + 0xc);
      *puVar10 = CONCAT44(fVar6 * local_100 + fVar14 * local_c0 + fVar4 * local_80,
                          fVar6 * local_110 + fVar14 * local_d0 + fVar4 * local_90);
      *(ulonglong *)((int)puVar10 + param_2) =
           CONCAT44(fVar12 * fStack_fc + fVar13 * fStack_bc + fVar3 * fStack_7c,
                    fVar12 * fStack_10c + fVar13 * fStack_cc + fVar3 * fStack_8c);
      *(float *)(puVar10 + 0xc) = fVar6 * local_f0 + fVar14 * local_b0 + fVar4 * local_70;
      *(float *)(param_2 + 8 + (int)puVar10) =
           fVar12 * fStack_ec + fVar13 * fStack_ac + fVar3 * fStack_6c;
      *(ulonglong *)((int)puVar10 + param_2 * 2) =
           CONCAT44(fVar7 * fStack_f8 + fVar11 * fStack_b8 + fVar2 * fStack_78,
                    fVar7 * fStack_108 + fVar11 * fStack_c8 + fVar2 * fStack_88);
      *(ulonglong *)(param_2 * 3 + (int)puVar10) =
           CONCAT44(fVar15 * fStack_f4 + fVar16 * fStack_b4 + fVar1 * fStack_74,
                    fVar15 * fStack_104 + fVar16 * fStack_c4 + fVar1 * fStack_84);
      *(float *)((int)puVar10 + param_2 * 2 + 8) =
           fVar7 * fStack_e8 + fVar11 * fStack_a8 + fVar2 * fStack_68;
      *(float *)(param_2 * 3 + 8 + (int)puVar10) =
           fVar15 * fStack_e4 + fVar16 * fStack_a4 + fVar1 * fStack_64;
      param_3 = (undefined8 *)((int)param_3 + param_4 * 4);
      puVar10 = (undefined8 *)((int)puVar10 + param_2 * 4);
    }
  }
  for (; iVar8 != 0; iVar8 = iVar8 + -1) {
    FUN_005ed576(puVar10,param_3,param_5);
    param_3 = (undefined8 *)((int)param_3 + param_4);
    puVar10 = (undefined8 *)((int)puVar10 + param_2);
  }
  return param_1;
}


// ==== 0x5eca86 FUN_005eca86

undefined8 *
FUN_005eca86(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,undefined4 param_5,
            uint param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined8 uVar5;
  float fVar6;
  int iVar7;
  uint uVar8;
  undefined8 *puVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar20;
  float fVar21;
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  float fVar22;
  float local_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float local_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float local_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float local_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float local_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float local_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float local_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float local_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float local_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float local_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float local_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float local_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float local_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float local_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float local_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  uVar8 = -(uint)(10 < param_6) & param_6 & 0xfffffffc;
  iVar7 = param_6 - uVar8;
  uVar8 = uVar8 >> 2;
  puVar9 = param_1;
  if (uVar8 != 0) {
    FUN_005e9c6c(param_5);
    for (; uVar8 != 0; uVar8 = uVar8 - 1) {
      fVar14 = (float)((ulonglong)*param_3 >> 0x20);
      fVar6 = (float)*param_3;
      uVar5 = *(undefined8 *)((int)param_3 + param_4 * 2);
      fVar10 = (float)uVar5;
      fVar11 = (float)((ulonglong)uVar5 >> 0x20);
      fVar12 = (float)*(undefined8 *)((int)param_3 + param_4);
      fVar13 = (float)((ulonglong)*(undefined8 *)((int)param_3 + param_4) >> 0x20);
      uVar5 = *(undefined8 *)(param_4 * 3 + (int)param_3);
      fVar15 = (float)uVar5;
      fVar16 = (float)((ulonglong)uVar5 >> 0x20);
      fVar1 = *(float *)(param_4 * 3 + 8 + (int)param_3);
      fVar2 = *(float *)((int)param_3 + param_4 * 2 + 8);
      fVar3 = *(float *)(param_4 + 8 + (int)param_3);
      fVar4 = *(float *)(param_3 + 0xc);
      auVar18._0_4_ = fVar6 * local_e0 + fVar14 * local_a0 + fVar4 * local_60;
      auVar18._4_4_ = fVar12 * fStack_dc + fVar13 * fStack_9c + fVar3 * fStack_5c;
      auVar18._8_4_ = fVar10 * fStack_d8 + fVar11 * fStack_98 + fVar2 * fStack_58;
      auVar18._12_4_ = fVar15 * fStack_d4 + fVar16 * fStack_94 + fVar1 * fStack_54;
      auVar19._4_4_ = auVar18._4_4_ + fStack_1c;
      auVar19._0_4_ = auVar18._0_4_ + local_20;
      auVar19._8_4_ = auVar18._8_4_ + fStack_18;
      auVar19._12_4_ = auVar18._12_4_ + fStack_14;
      auVar19 = rcpps(auVar18,auVar19);
      fVar17 = auVar19._0_4_;
      fVar20 = auVar19._4_4_;
      fVar21 = auVar19._8_4_;
      fVar22 = auVar19._12_4_;
      fVar17 = (fVar17 + fVar17) - fVar17 * (auVar18._0_4_ + local_20) * fVar17;
      fVar20 = (fVar20 + fVar20) - fVar20 * (auVar18._4_4_ + fStack_1c) * fVar20;
      fVar21 = (fVar21 + fVar21) - fVar21 * (auVar18._8_4_ + fStack_18) * fVar21;
      fVar22 = (fVar22 + fVar22) - fVar22 * (auVar18._12_4_ + fStack_14) * fVar22;
      *puVar9 = CONCAT44((fVar6 * local_100 + fVar14 * local_c0 + fVar4 * local_80 + local_40) *
                         fVar17,(fVar6 * local_110 + fVar14 * local_d0 + fVar4 * local_90 + local_50
                                ) * fVar17);
      *(ulonglong *)((int)puVar9 + param_2) =
           CONCAT44((fVar12 * fStack_fc + fVar13 * fStack_bc + fVar3 * fStack_7c + fStack_3c) *
                    fVar20,(fVar12 * fStack_10c + fVar13 * fStack_cc + fVar3 * fStack_8c + fStack_4c
                           ) * fVar20);
      *(float *)(puVar9 + 0xc) =
           (fVar6 * local_f0 + fVar14 * local_b0 + fVar4 * local_70 + local_30) * fVar17;
      *(float *)(param_2 + 8 + (int)puVar9) =
           (fVar12 * fStack_ec + fVar13 * fStack_ac + fVar3 * fStack_6c + fStack_2c) * fVar20;
      *(ulonglong *)((int)puVar9 + param_2 * 2) =
           CONCAT44((fVar10 * fStack_f8 + fVar11 * fStack_b8 + fVar2 * fStack_78 + fStack_38) *
                    fVar21,(fVar10 * fStack_108 + fVar11 * fStack_c8 + fVar2 * fStack_88 + fStack_48
                           ) * fVar21);
      *(ulonglong *)(param_2 * 3 + (int)puVar9) =
           CONCAT44((fVar15 * fStack_f4 + fVar16 * fStack_b4 + fVar1 * fStack_74 + fStack_34) *
                    fVar22,(fVar15 * fStack_104 + fVar16 * fStack_c4 + fVar1 * fStack_84 + fStack_44
                           ) * fVar22);
      *(float *)((int)puVar9 + param_2 * 2 + 8) =
           (fVar10 * fStack_e8 + fVar11 * fStack_a8 + fVar2 * fStack_68 + fStack_28) * fVar21;
      *(float *)(param_2 * 3 + 8 + (int)puVar9) =
           (fVar15 * fStack_e4 + fVar16 * fStack_a4 + fVar1 * fStack_64 + fStack_24) * fVar22;
      param_3 = (undefined8 *)((int)param_3 + param_4 * 4);
      puVar9 = (undefined8 *)((int)puVar9 + param_2 * 4);
    }
  }
  for (; iVar7 != 0; iVar7 = iVar7 + -1) {
    FUN_005ed64b(puVar9,param_3,param_5);
    param_3 = (undefined8 *)((int)param_3 + param_4);
    puVar9 = (undefined8 *)((int)puVar9 + param_2);
  }
  return param_1;
}


// ==== 0x5eccb7 FUN_005eccb7

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005eccb7(void)

{
  ushort in_XMM0_Wa;
  ushort in_XMM0_Wb;
  ushort in_XMM0_Wc;
  ushort in_XMM0_Wd;
  ushort in_XMM0_We;
  ushort in_XMM0_Wf;
  ushort in_XMM0_Wg;
  ushort in_XMM0_Wh;
  undefined1 auVar1 [16];
  
  auVar1._0_2_ = -(ushort)((_DAT_006df1d0 & in_XMM0_Wa) == 0);
  auVar1._2_2_ = -(ushort)((uRam006df1d2 & in_XMM0_Wb) == 0);
  auVar1._4_2_ = -(ushort)((uRam006df1d4 & in_XMM0_Wc) == 0);
  auVar1._6_2_ = -(ushort)((uRam006df1d6 & in_XMM0_Wd) == 0);
  auVar1._8_2_ = -(ushort)((uRam006df1d8 & in_XMM0_We) == 0);
  auVar1._10_2_ = -(ushort)((uRam006df1da & in_XMM0_Wf) == 0);
  auVar1._12_2_ = -(ushort)((uRam006df1dc & in_XMM0_Wg) == 0);
  auVar1._14_2_ = -(ushort)((uRam006df1de & in_XMM0_Wh) == 0);
  if ((((((((((((((((SUB161(auVar1 >> 7,0) & 1) != 0 || (SUB161(auVar1 >> 0xf,0) & 1) != 0) ||
                  (SUB161(auVar1 >> 0x17,0) & 1) != 0) || (SUB161(auVar1 >> 0x1f,0) & 1) != 0) ||
                (SUB161(auVar1 >> 0x27,0) & 1) != 0) || (SUB161(auVar1 >> 0x2f,0) & 1) != 0) ||
              (SUB161(auVar1 >> 0x37,0) & 1) != 0) || (SUB161(auVar1 >> 0x3f,0) & 1) != 0) ||
            (SUB161(auVar1 >> 0x47,0) & 1) != 0) || (SUB161(auVar1 >> 0x4f,0) & 1) != 0) ||
          (SUB161(auVar1 >> 0x57,0) & 1) != 0) || (SUB161(auVar1 >> 0x5f,0) & 1) != 0) ||
        (SUB161(auVar1 >> 0x67,0) & 1) != 0) || (SUB161(auVar1 >> 0x6f,0) & 1) != 0) ||
      (auVar1._14_2_ >> 7 & 1) != 0) || (auVar1._14_2_ & 0x8000) != 0) {
    return;
  }
  return;
}


// ==== 0x5ecda8 FUN_005ecda8

/* WARNING: Removing unreachable block (ram,0x005ece5b) */

int FUN_005ecda8(int param_1,undefined8 *param_2,uint param_3)

{
  ushort uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *extraout_ECX;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 in_XMM3_Qa;
  undefined8 in_XMM3_Qb;
  undefined8 uVar9;
  
  iVar2 = param_1;
  if (7 < param_3) {
    uVar6 = param_3 & 0xfffffff8;
    puVar3 = param_2;
    do {
      uVar7 = *puVar3;
      uVar8 = puVar3[1];
      uVar9 = FUN_005eccb7();
      puVar3 = (undefined8 *)uVar9;
      *extraout_ECX = uVar7;
      extraout_ECX[1] = uVar8;
      extraout_ECX[2] = in_XMM3_Qa;
      extraout_ECX[3] = in_XMM3_Qb;
    } while ((int)((ulonglong)uVar9 >> 0x20) != 8);
    param_3 = param_3 - uVar6;
    param_2 = (undefined8 *)((int)param_2 + uVar6 * 2);
    param_1 = param_1 + uVar6 * 4;
  }
  uVar6 = 0;
  if (param_3 != 0) {
    do {
      uVar1 = *(ushort *)((int)param_2 + uVar6 * 2);
      uVar4 = (uint)uVar1;
      uVar5 = uVar4 & 0x7c00;
      if (uVar5 < 0x401) {
        uVar5 = 0x400;
      }
      *(float *)(param_1 + uVar6 * 4) =
           (float)(-(uint)((uVar1 & 0x7c00) != 0) & 0x400 | uVar4 & 0x3ff) *
           (float)((uVar5 + 0x19800) * 0x2000 | (uVar4 & 0xffff8000) << 0x10);
      uVar6 = uVar6 + 1;
    } while (uVar6 < param_3);
  }
  return iVar2;
}


// ==== 0x5ece7a FUN_005ece7a

undefined8 * FUN_005ece7a(undefined8 *param_1,float *param_2,undefined8 *param_3)

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
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = param_2[3];
  fVar17 = (float)*param_3;
  fVar18 = (float)((ulonglong)*param_3 >> 0x20);
  fVar19 = (float)param_3[1];
  fVar20 = (float)((ulonglong)param_3[1] >> 0x20);
  fVar21 = (float)param_3[2];
  fVar22 = (float)((ulonglong)param_3[2] >> 0x20);
  fVar23 = (float)param_3[3];
  fVar24 = (float)((ulonglong)param_3[3] >> 0x20);
  fVar25 = (float)param_3[4];
  fVar26 = (float)((ulonglong)param_3[4] >> 0x20);
  fVar27 = (float)param_3[5];
  fVar28 = (float)((ulonglong)param_3[5] >> 0x20);
  fVar29 = (float)param_3[6];
  fVar30 = (float)((ulonglong)param_3[6] >> 0x20);
  fVar31 = (float)param_3[7];
  fVar32 = (float)((ulonglong)param_3[7] >> 0x20);
  fVar5 = param_2[4];
  fVar6 = param_2[5];
  fVar7 = param_2[6];
  fVar8 = param_2[7];
  fVar9 = param_2[8];
  fVar10 = param_2[9];
  fVar11 = param_2[10];
  fVar12 = param_2[0xb];
  fVar13 = param_2[0xc];
  fVar14 = param_2[0xd];
  fVar15 = param_2[0xe];
  fVar16 = param_2[0xf];
  *param_1 = CONCAT44(fVar1 * fVar18 + fVar2 * fVar22 + fVar3 * fVar26 + fVar4 * fVar30,
                      fVar1 * fVar17 + fVar2 * fVar21 + fVar3 * fVar25 + fVar4 * fVar29);
  param_1[1] = CONCAT44(fVar1 * fVar20 + fVar2 * fVar24 + fVar3 * fVar28 + fVar4 * fVar32,
                        fVar1 * fVar19 + fVar2 * fVar23 + fVar3 * fVar27 + fVar4 * fVar31);
  param_1[2] = CONCAT44(fVar5 * fVar18 + fVar6 * fVar22 + fVar7 * fVar26 + fVar8 * fVar30,
                        fVar5 * fVar17 + fVar6 * fVar21 + fVar7 * fVar25 + fVar8 * fVar29);
  param_1[3] = CONCAT44(fVar5 * fVar20 + fVar6 * fVar24 + fVar7 * fVar28 + fVar8 * fVar32,
                        fVar5 * fVar19 + fVar6 * fVar23 + fVar7 * fVar27 + fVar8 * fVar31);
  param_1[4] = CONCAT44(fVar9 * fVar18 + fVar10 * fVar22 + fVar11 * fVar26 + fVar12 * fVar30,
                        fVar9 * fVar17 + fVar10 * fVar21 + fVar11 * fVar25 + fVar12 * fVar29);
  param_1[5] = CONCAT44(fVar9 * fVar20 + fVar10 * fVar24 + fVar11 * fVar28 + fVar12 * fVar32,
                        fVar9 * fVar19 + fVar10 * fVar23 + fVar11 * fVar27 + fVar12 * fVar31);
  param_1[6] = CONCAT44(fVar18 * fVar13 + fVar22 * fVar14 + fVar26 * fVar15 + fVar30 * fVar16,
                        fVar17 * fVar13 + fVar21 * fVar14 + fVar25 * fVar15 + fVar29 * fVar16);
  param_1[7] = CONCAT44(fVar20 * fVar13 + fVar24 * fVar14 + fVar28 * fVar15 + fVar32 * fVar16,
                        fVar19 * fVar13 + fVar23 * fVar14 + fVar27 * fVar15 + fVar31 * fVar16);
  return param_1;
}


// ==== 0x5ecfae FUN_005ecfae

float * FUN_005ecfae(float *param_1,float *param_2,undefined8 *param_3)

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
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  undefined1 auVar14 [16];
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  float fVar42;
  float fVar43;
  float fVar44;
  float fVar45;
  float fVar46;
  float fVar47;
  float fVar48;
  float fVar49;
  float fVar50;
  float fVar51;
  
  fVar10 = (float)*param_3;
  fVar15 = (float)((ulonglong)*param_3 >> 0x20);
  fVar18 = (float)param_3[2];
  fVar20 = (float)((ulonglong)param_3[2] >> 0x20);
  fVar6 = (float)param_3[4];
  fVar7 = (float)((ulonglong)param_3[4] >> 0x20);
  fVar8 = (float)param_3[6];
  fVar9 = (float)((ulonglong)param_3[6] >> 0x20);
  fVar11 = (float)param_3[1];
  fVar16 = (float)((ulonglong)param_3[1] >> 0x20);
  fVar28 = (float)param_3[3];
  fVar32 = (float)((ulonglong)param_3[3] >> 0x20);
  fVar12 = (float)param_3[5];
  fVar17 = (float)((ulonglong)param_3[5] >> 0x20);
  fVar19 = (float)param_3[7];
  fVar21 = (float)((ulonglong)param_3[7] >> 0x20);
  fVar22 = fVar11 * fVar17;
  fVar25 = fVar28 * fVar21;
  fVar29 = fVar12 * fVar16;
  fVar33 = fVar19 * fVar32;
  fVar36 = fVar7 * fVar11;
  fVar40 = fVar9 * fVar28;
  fVar44 = fVar15 * fVar12;
  fVar48 = fVar20 * fVar19;
  fVar37 = fVar15 * fVar17;
  fVar41 = fVar20 * fVar21;
  fVar45 = fVar7 * fVar16;
  fVar49 = fVar9 * fVar32;
  fVar23 = (fVar12 * fVar41 +
           ((fVar17 * fVar40 + (fVar7 * fVar33 - fVar7 * fVar25)) - fVar17 * fVar48)) -
           fVar12 * fVar49;
  fVar26 = (fVar19 * fVar37 +
           ((fVar21 * fVar36 + (fVar9 * fVar29 - fVar9 * fVar22)) - fVar21 * fVar44)) -
           fVar19 * fVar45;
  fVar30 = (fVar11 * fVar49 +
           ((fVar16 * fVar48 + (fVar15 * fVar25 - fVar15 * fVar33)) - fVar16 * fVar40)) -
           fVar11 * fVar41;
  fVar34 = (fVar28 * fVar45 +
           ((fVar32 * fVar44 + (fVar20 * fVar22 - fVar20 * fVar29)) - fVar32 * fVar36)) -
           fVar28 * fVar37;
  fVar38 = fVar10 * fVar7;
  fVar42 = fVar18 * fVar9;
  fVar46 = fVar6 * fVar15;
  fVar50 = fVar8 * fVar20;
  fVar39 = fVar10 * fVar17;
  fVar43 = fVar18 * fVar21;
  fVar47 = fVar6 * fVar16;
  fVar51 = fVar8 * fVar32;
  fVar1 = fVar10 * fVar23;
  fVar3 = fVar18 * fVar26;
  fVar4 = fVar6 * fVar30;
  fVar5 = fVar8 * fVar34;
  fVar24 = fVar10 * fVar12;
  fVar27 = fVar18 * fVar19;
  fVar31 = fVar6 * fVar11;
  fVar35 = fVar8 * fVar28;
  fVar13 = fVar4 + fVar1;
  fVar2 = fVar5 + fVar3 + fVar13;
  if (fVar2 == 0.0) {
    param_1 = (float *)0x0;
  }
  else {
    if (param_2 != (float *)0x0) {
      *param_2 = fVar2;
    }
    auVar14._4_4_ = fVar13;
    auVar14._0_4_ = fVar2;
    auVar14._8_4_ = fVar3 + fVar5;
    auVar14._12_4_ = fVar1 + fVar4;
    auVar14 = rcpss(ZEXT816(0),auVar14);
    fVar1 = auVar14._0_4_;
    fVar1 = (fVar1 + fVar1) - fVar2 * fVar1 * fVar1;
    *param_1 = fVar1 * fVar23;
    param_1[1] = fVar1 * fVar26;
    param_1[2] = fVar1 * fVar30;
    param_1[3] = fVar1 * fVar34;
    param_1[4] = fVar1 * ((fVar17 * fVar27 +
                          fVar12 * fVar51 + ((fVar6 * fVar25 - fVar6 * fVar33) - fVar12 * fVar43)) -
                         fVar17 * fVar35);
    param_1[5] = fVar1 * ((fVar21 * fVar24 +
                          fVar19 * fVar47 + ((fVar8 * fVar22 - fVar8 * fVar29) - fVar19 * fVar39)) -
                         fVar21 * fVar31);
    param_1[6] = fVar1 * ((fVar16 * fVar35 +
                          fVar11 * fVar43 + ((fVar10 * fVar33 - fVar10 * fVar25) - fVar11 * fVar51))
                         - fVar16 * fVar27);
    param_1[7] = fVar1 * ((fVar32 * fVar31 +
                          fVar28 * fVar39 + ((fVar18 * fVar29 - fVar18 * fVar22) - fVar28 * fVar47))
                         - fVar32 * fVar24);
    param_1[8] = fVar1 * ((fVar7 * fVar43 +
                          (fVar17 * fVar50 - (fVar17 * fVar42 + (fVar6 * fVar41 - fVar6 * fVar49))))
                         - fVar7 * fVar51);
    param_1[9] = fVar1 * ((fVar9 * fVar39 +
                          (fVar21 * fVar46 - (fVar21 * fVar38 + (fVar8 * fVar37 - fVar8 * fVar45))))
                         - fVar9 * fVar47);
    param_1[10] = fVar1 * ((fVar15 * fVar51 +
                           (fVar16 * fVar42 -
                           (fVar16 * fVar50 + (fVar10 * fVar49 - fVar10 * fVar41)))) -
                          fVar15 * fVar43);
    param_1[0xb] = fVar1 * ((fVar20 * fVar47 +
                            (fVar32 * fVar38 -
                            (fVar32 * fVar46 + (fVar18 * fVar45 - fVar18 * fVar37)))) -
                           fVar20 * fVar39);
    *(ulonglong *)(param_1 + 0xc) =
         CONCAT44(fVar1 * (fVar9 * fVar31 +
                          (((fVar19 * fVar38 - (fVar8 * fVar36 - fVar8 * fVar44)) - fVar19 * fVar46)
                          - fVar9 * fVar24)),
                  fVar1 * (fVar7 * fVar35 +
                          (((fVar12 * fVar42 - (fVar6 * fVar40 - fVar6 * fVar48)) - fVar12 * fVar50)
                          - fVar7 * fVar27)));
    *(ulonglong *)(param_1 + 0xe) =
         CONCAT44(fVar1 * (fVar20 * fVar24 +
                          (((fVar28 * fVar46 - (fVar18 * fVar44 - fVar18 * fVar36)) -
                           fVar28 * fVar38) - fVar20 * fVar31)),
                  fVar1 * (fVar15 * fVar27 +
                          (((fVar11 * fVar50 - (fVar10 * fVar48 - fVar10 * fVar40)) -
                           fVar11 * fVar42) - fVar15 * fVar35)));
  }
  return param_1;
}


// ==== 0x5ed2aa FUN_005ed2aa

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ed2aa(uint *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  uint uVar5;
  float fVar6;
  uint uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  
  fVar1 = (float)*param_3;
  fVar2 = (float)((ulonglong)*param_3 >> 0x20);
  fVar4 = (float)param_3[1];
  fVar6 = (float)((ulonglong)param_3[1] >> 0x20);
  fVar8 = (float)*param_4;
  fVar9 = (float)((ulonglong)*param_4 >> 0x20);
  fVar10 = (float)param_4[1];
  fVar11 = (float)((ulonglong)param_4[1] >> 0x20);
  fVar12 = (float)*param_2;
  fVar13 = (float)((ulonglong)*param_2 >> 0x20);
  fVar14 = (float)param_2[1];
  fVar15 = (float)((ulonglong)param_2[1] >> 0x20);
  uVar3 = (uint)(fVar14 * (fVar6 * fVar8 - fVar1 * fVar11) +
                 fVar15 * (fVar1 * fVar10 - fVar4 * fVar8) +
                fVar12 * (fVar4 * fVar11 - fVar6 * fVar10)) ^ uRam006df224;
  uVar5 = (uint)(fVar15 * (fVar1 * fVar9 - fVar2 * fVar8) +
                 fVar12 * (fVar2 * fVar11 - fVar6 * fVar9) +
                fVar13 * (fVar6 * fVar8 - fVar1 * fVar11)) ^ uRam006df228;
  uVar7 = (uint)(fVar12 * (fVar2 * fVar10 - fVar4 * fVar9) +
                 fVar13 * (fVar4 * fVar8 - fVar1 * fVar10) +
                fVar14 * (fVar1 * fVar9 - fVar2 * fVar8)) ^ uRam006df22c;
  *param_1 = (uint)(fVar13 * (fVar4 * fVar11 - fVar6 * fVar10) +
                    fVar14 * (fVar6 * fVar9 - fVar2 * fVar11) +
                   fVar15 * (fVar2 * fVar10 - fVar4 * fVar9)) ^ _DAT_006df220;
  param_1[1] = uVar3;
  param_1[2] = uVar5;
  param_1[3] = uVar7;
  return;
}


// ==== 0x5ed36a FUN_005ed36a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ed36a(float *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

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
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  
  fVar1 = *(float *)(param_2 + 1);
  fVar8 = (float)*param_2;
  fVar9 = (float)((ulonglong)*param_2 >> 0x20);
  fVar4 = fVar8 - (float)*param_3;
  fVar5 = fVar9 - (float)((ulonglong)*param_3 >> 0x20);
  fVar6 = fVar8 - (float)*param_4;
  fVar7 = fVar9 - (float)((ulonglong)*param_4 >> 0x20);
  fVar2 = (fVar1 - *(float *)(param_4 + 1)) * fVar5 - (fVar1 - *(float *)(param_3 + 1)) * fVar7;
  fVar3 = fVar6 * (fVar1 - *(float *)(param_3 + 1)) - fVar4 * (fVar1 - *(float *)(param_4 + 1));
  fVar4 = fVar7 * fVar4 - fVar5 * fVar6;
  fVar7 = fVar4 * fVar4;
  fVar5 = fVar2 * fVar2 + fVar7;
  fVar6 = fVar3 * fVar3 + 0.0;
  auVar10._4_4_ = fVar5;
  auVar10._0_4_ = fVar6;
  auVar10._8_4_ = fVar5;
  auVar10._12_4_ = fVar5;
  auVar11._4_4_ = fVar6;
  auVar11._0_4_ = fVar5 + fVar6;
  auVar11._8_4_ = fVar7 + fVar7;
  auVar11._12_4_ = 0;
  auVar11 = rsqrtss(auVar10,auVar11);
  fVar7 = auVar11._0_4_;
  fVar5 = _DAT_006df240 * fVar7 * (_DAT_006df250 - (fVar5 + fVar6) * fVar7 * fVar7);
  *param_1 = fVar2 * fVar5;
  param_1[1] = fVar3 * fVar5;
  param_1[2] = fVar4 * fVar5;
  param_1[3] = fVar5 * 0.0;
  param_1[3] = (float)((uint)(fVar2 * fVar5 * fVar8 + fVar4 * fVar5 * fVar1 + fVar3 * fVar5 * fVar9)
                      ^ _DAT_006df230);
  return;
}


// ==== 0x5ed46a FUN_005ed46a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ed46a(float *param_1,undefined8 *param_2)

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
  float fVar12;
  float fVar13;
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  
  fVar5 = (float)*param_2;
  fVar6 = (float)((ulonglong)*param_2 >> 0x20);
  fVar7 = (float)param_2[1];
  fVar8 = (float)((ulonglong)param_2[1] >> 0x20);
  fVar1 = (float)((uint)fVar5 & _DAT_006df2d0);
  fVar2 = (float)((uint)fVar6 & uRam006df2d4);
  fVar3 = (float)((uint)fVar7 & uRam006df2d8);
  fVar4 = (float)((uint)fVar8 & uRam006df2dc);
  fVar3 = fVar3 * fVar3;
  fVar4 = fVar4 * fVar4;
  fVar1 = fVar1 * fVar1 + fVar3;
  fVar2 = fVar2 * fVar2 + fVar4;
  auVar10._4_4_ = fVar1;
  auVar10._0_4_ = fVar2;
  auVar10._8_4_ = fVar1;
  auVar10._12_4_ = fVar1;
  auVar11._4_4_ = fVar2;
  auVar11._0_4_ = fVar1 + fVar2;
  auVar11._8_4_ = fVar3 + fVar3;
  auVar11._12_4_ = fVar4 + fVar4;
  auVar11 = rsqrtss(auVar10,auVar11);
  fVar3 = auVar11._0_4_;
  fVar1 = DAT_006df2b0 * fVar3 * (DAT_006df2c0 - (fVar1 + fVar2) * fVar3 * fVar3);
  fVar5 = fVar5 * fVar1;
  fVar6 = fVar6 * fVar1;
  fVar7 = fVar7 * fVar1;
  fVar8 = fVar8 * fVar1;
  fVar1 = _DAT_006df290 * fVar5;
  fVar2 = fRam006df294 * fVar6;
  fVar3 = fRam006df298 * fVar7;
  fVar4 = fRam006df29c * fVar8;
  fVar9 = fVar1 * fVar6 + _DAT_006df2a0;
  fVar12 = fVar2 * fVar6 + fRam006df2a4;
  fVar13 = fVar3 * fVar6 + fRam006df2a8;
  fVar6 = fVar4 * fVar6 + fRam006df2ac;
  fVar14 = fVar1 * fVar7 + _DAT_006df280;
  fVar15 = fVar2 * fVar7 + fRam006df284;
  fVar16 = fVar3 * fVar7 + fRam006df288;
  fVar7 = fVar4 * fVar7 + fRam006df28c;
  fVar17 = fVar1 * fVar8 + _DAT_006df270;
  fVar18 = fVar2 * fVar8 + fRam006df274;
  fVar19 = fVar3 * fVar8 + fRam006df278;
  fVar8 = fVar4 * fVar8 + fRam006df27c;
  fVar2 = fVar2 * fVar5 + fRam006df264;
  fVar3 = fVar3 * fVar5 + fRam006df268;
  fVar4 = fVar4 * fVar5 + fRam006df26c;
  *param_1 = fVar1 * fVar5 + _DAT_006df260;
  param_1[1] = fVar2;
  param_1[2] = fVar3;
  param_1[3] = fVar4;
  param_1[4] = fVar9;
  param_1[5] = fVar12;
  param_1[6] = fVar13;
  param_1[7] = fVar6;
  param_1[8] = fVar14;
  param_1[9] = fVar15;
  param_1[10] = fVar16;
  param_1[0xb] = fVar7;
  param_1[0xc] = fVar17;
  param_1[0xd] = fVar18;
  param_1[0xe] = fVar19;
  param_1[0xf] = fVar8;
  return;
}


// ==== 0x5ed576 FUN_005ed576

void FUN_005ed576(undefined8 *param_1,undefined8 *param_2,float *param_3)

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
  
  if (((uint)param_3 & 0xf) == 0) {
    fVar3 = *(float *)(param_2 + 1);
    fVar1 = fVar3 * param_3[8];
    fVar2 = fVar3 * param_3[9];
    fVar3 = fVar3 * param_3[10];
    fVar6 = (float)((ulonglong)*param_2 >> 0x20);
    fVar4 = fVar6 * param_3[4];
    fVar5 = fVar6 * param_3[5];
    fVar6 = fVar6 * param_3[6];
    fVar9 = (float)*param_2;
    fVar7 = fVar9 * *param_3;
    fVar8 = fVar9 * param_3[1];
    fVar9 = fVar9 * param_3[2];
  }
  else {
    fVar3 = *(float *)(param_2 + 1);
    fVar1 = (float)*(undefined8 *)(param_3 + 8) * fVar3;
    fVar2 = (float)((ulonglong)*(undefined8 *)(param_3 + 8) >> 0x20) * fVar3;
    fVar3 = (float)*(undefined8 *)(param_3 + 10) * fVar3;
    fVar6 = (float)((ulonglong)*param_2 >> 0x20);
    fVar4 = (float)*(undefined8 *)(param_3 + 4) * fVar6;
    fVar5 = (float)((ulonglong)*(undefined8 *)(param_3 + 4) >> 0x20) * fVar6;
    fVar6 = (float)*(undefined8 *)(param_3 + 6) * fVar6;
    fVar9 = (float)*param_2;
    fVar7 = (float)*(undefined8 *)param_3 * fVar9;
    fVar8 = (float)((ulonglong)*(undefined8 *)param_3 >> 0x20) * fVar9;
    fVar9 = (float)*(undefined8 *)(param_3 + 2) * fVar9;
  }
  *param_1 = CONCAT44(fVar8 + fVar5 + fVar2,fVar7 + fVar4 + fVar1);
  *(float *)(param_1 + 1) = fVar9 + fVar6 + fVar3;
  return;
}


// ==== 0x5ed64b FUN_005ed64b

void FUN_005ed64b(undefined8 *param_1,undefined8 *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  
  fVar1 = (float)*param_2;
  fVar3 = (float)((ulonglong)*param_2 >> 0x20);
  fVar9 = *(float *)(param_2 + 1);
  if (((uint)param_3 & 0xf) == 0) {
    fVar13 = param_3[8] * fVar9 + param_3[0xc];
    fVar14 = param_3[9] * fVar9 + param_3[0xd];
    fVar15 = param_3[10] * fVar9 + param_3[0xe];
    fVar16 = param_3[0xb] * fVar9 + param_3[0xf];
    fVar10 = param_3[4];
    fVar11 = param_3[5];
    fVar9 = param_3[6];
    fVar12 = param_3[7];
    fVar2 = *param_3;
    fVar4 = param_3[1];
    fVar5 = param_3[2];
    fVar6 = param_3[3];
  }
  else {
    fVar13 = (float)*(undefined8 *)(param_3 + 8) * fVar9 + (float)*(undefined8 *)(param_3 + 0xc);
    fVar14 = (float)((ulonglong)*(undefined8 *)(param_3 + 8) >> 0x20) * fVar9 +
             (float)((ulonglong)*(undefined8 *)(param_3 + 0xc) >> 0x20);
    fVar15 = (float)*(undefined8 *)(param_3 + 10) * fVar9 + (float)*(undefined8 *)(param_3 + 0xe);
    fVar16 = (float)((ulonglong)*(undefined8 *)(param_3 + 10) >> 0x20) * fVar9 +
             (float)((ulonglong)*(undefined8 *)(param_3 + 0xe) >> 0x20);
    fVar10 = (float)*(undefined8 *)(param_3 + 4);
    fVar11 = (float)((ulonglong)*(undefined8 *)(param_3 + 4) >> 0x20);
    fVar9 = (float)*(undefined8 *)(param_3 + 6);
    fVar12 = (float)((ulonglong)*(undefined8 *)(param_3 + 6) >> 0x20);
    fVar2 = (float)*(undefined8 *)param_3;
    fVar4 = (float)((ulonglong)*(undefined8 *)param_3 >> 0x20);
    fVar5 = (float)*(undefined8 *)(param_3 + 2);
    fVar6 = (float)((ulonglong)*(undefined8 *)(param_3 + 2) >> 0x20);
  }
  auVar7._4_4_ = fVar1;
  auVar7._0_4_ = fVar1;
  auVar7._8_4_ = fVar1;
  auVar7._12_4_ = fVar1;
  fVar13 = fVar2 * fVar1 + fVar10 * fVar3 + fVar13;
  fVar14 = fVar4 * fVar1 + fVar11 * fVar3 + fVar14;
  fVar15 = fVar5 * fVar1 + fVar9 * fVar3 + fVar15;
  fVar16 = fVar6 * fVar1 + fVar12 * fVar3 + fVar16;
  auVar8._4_4_ = fVar14;
  auVar8._0_4_ = fVar13;
  auVar8._8_4_ = fVar15;
  auVar8._12_4_ = fVar16;
  auVar8 = rcpps(auVar7,auVar8);
  fVar9 = auVar8._12_4_;
  fVar9 = (fVar9 + fVar9) - fVar9 * fVar16 * fVar9;
  *param_1 = CONCAT44(fVar14 * fVar9,fVar13 * fVar9);
  *(float *)(param_1 + 1) = fVar15 * fVar9;
  return;
}


// ==== 0x5ed74e FUN_005ed74e

void FUN_005ed74e(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined1 auVar6 [16];
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  if (fVar4 < 1.4210855e-14) {
    fVar4 = 0.0;
    *param_1 = 0.0;
    param_1[1] = 0.0;
    param_1[2] = 0.0;
  }
  else {
    auVar6 = rsqrtss(ZEXT416(0x28800000),ZEXT416((uint)fVar4));
    fVar5 = auVar6._0_4_;
    fVar4 = fVar5 * 0.5 * (3.0 - fVar4 * fVar5 * fVar5);
    *param_1 = fVar4 * fVar1;
    param_1[1] = fVar4 * fVar2;
    param_1[2] = fVar4 * fVar3;
    fVar4 = fVar4 * param_2[3];
  }
  param_1[3] = fVar4;
  return;
}


// ==== 0x5ed863 FUN_005ed863

void FUN_005ed863(undefined8 *param_1,float *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
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
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  
  uVar1 = param_3[6];
  fVar21 = (float)uVar1;
  fVar22 = (float)((ulonglong)uVar1 >> 0x20);
  fVar18 = *(float *)(param_3 + 6);
  fVar19 = *(float *)((int)param_3 + 0x34);
  fVar20 = *(float *)(param_3 + 7);
  fVar23 = (float)param_3[7];
  fVar24 = (float)((ulonglong)param_3[7] >> 0x20);
  fVar2 = param_2[3];
  fVar3 = param_2[2];
  fVar4 = param_2[1];
  fVar33 = (float)param_3[4];
  fVar34 = (float)((ulonglong)param_3[4] >> 0x20);
  fVar35 = (float)param_3[5];
  fVar36 = (float)((ulonglong)param_3[5] >> 0x20);
  fVar5 = *param_2;
  fVar29 = (float)param_3[2];
  fVar30 = (float)((ulonglong)param_3[2] >> 0x20);
  fVar31 = (float)param_3[3];
  fVar32 = (float)((ulonglong)param_3[3] >> 0x20);
  fVar6 = param_2[7];
  fVar7 = param_2[6];
  fVar25 = (float)*param_3;
  fVar26 = (float)((ulonglong)*param_3 >> 0x20);
  fVar27 = (float)param_3[1];
  fVar28 = (float)((ulonglong)param_3[1] >> 0x20);
  fVar8 = param_2[5];
  fVar9 = param_2[4];
  fVar10 = param_2[0xb];
  fVar11 = param_2[10];
  fVar12 = param_2[9];
  fVar13 = param_2[8];
  fVar14 = param_2[0xf];
  fVar15 = param_2[0xe];
  fVar16 = param_2[0xd];
  fVar17 = param_2[0xc];
  *param_1 = CONCAT44(fVar9 * fVar25 + fVar8 * fVar29 + fVar7 * fVar33 + fVar6 * fVar21,
                      fVar5 * fVar25 + fVar4 * fVar29 + fVar3 * fVar33 + fVar2 * fVar21);
  param_1[1] = CONCAT44(fVar17 * fVar25 + fVar16 * fVar29 + fVar15 * fVar33 + fVar14 * fVar18,
                        fVar13 * fVar25 + fVar12 * fVar29 + fVar11 * fVar33 + fVar10 * fVar18);
  param_1[2] = CONCAT44(fVar9 * fVar26 + fVar8 * fVar30 + fVar7 * fVar34 + fVar6 * fVar22,
                        fVar5 * fVar26 + fVar4 * fVar30 + fVar3 * fVar34 + fVar2 * fVar22);
  param_1[3] = CONCAT44(fVar17 * fVar26 + fVar16 * fVar30 + fVar15 * fVar34 + fVar14 * fVar19,
                        fVar13 * fVar26 + fVar12 * fVar30 + fVar11 * fVar34 + fVar10 * fVar19);
  param_1[4] = CONCAT44(fVar9 * fVar27 + fVar8 * fVar31 + fVar7 * fVar35 + fVar6 * fVar23,
                        fVar5 * fVar27 + fVar4 * fVar31 + fVar3 * fVar35 + fVar2 * fVar23);
  param_1[5] = CONCAT44(fVar17 * fVar27 + fVar16 * fVar31 + fVar15 * fVar35 + fVar14 * fVar20,
                        fVar13 * fVar27 + fVar12 * fVar31 + fVar11 * fVar35 + fVar10 * fVar20);
  param_1[6] = CONCAT44(fVar9 * fVar28 + fVar8 * fVar32 + fVar7 * fVar36 + fVar6 * fVar24,
                        fVar5 * fVar28 + fVar4 * fVar32 + fVar3 * fVar36 + fVar2 * fVar24);
  param_1[7] = CONCAT44(fVar17 * fVar28 + fVar16 * fVar32 + fVar15 * fVar36 + fVar14 * fVar24,
                        fVar13 * fVar28 + fVar12 * fVar32 + fVar11 * fVar36 + fVar10 * fVar24);
  return;
}


// ==== 0x5eda97 FUN_005eda97

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005eda97(float *param_1,float *param_2,float *param_3)

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
  float fVar17;
  float fVar18;
  undefined1 in_XMM5 [16];
  undefined1 auVar16 [16];
  float fVar19;
  
  fVar5 = (float)((uint)*param_3 & _DAT_006df320);
  fVar8 = (float)((uint)param_3[1] & uRam006df324);
  fVar9 = (float)((uint)param_3[2] & uRam006df328);
  fVar10 = (float)((uint)param_3[3] & uRam006df32c);
  fVar6 = fVar5 * fVar5 + fVar9 * fVar9;
  fVar9 = fVar8 * fVar8 + fVar10 * fVar10 + fVar6;
  fVar5 = fVar6;
  fVar8 = fVar6;
  if (fVar9 != 0.0) {
    if ((_DAT_007094b0 & 1) == 0) {
      _DAT_007094b0 = _DAT_007094b0 | 1;
      _DAT_007094a0 = 0.5;
      uRam007094a4 = 0;
      uRam007094a8 = 0;
      uRam007094ac = 0;
    }
    if ((_DAT_007094b0 & 2) == 0) {
      _DAT_007094b0 = _DAT_007094b0 | 2;
      _DAT_00709490 = 3.0;
      uRam00709494 = 0;
      uRam00709498 = 0;
      uRam0070949c = 0;
    }
    auVar16._4_4_ = fVar6;
    auVar16._0_4_ = fVar9;
    auVar16._8_4_ = fVar6;
    auVar16._12_4_ = fVar6;
    auVar16 = rsqrtss(in_XMM5,auVar16);
    fVar5 = auVar16._0_4_;
    fVar8 = _DAT_007094a0 * fVar5 * (_DAT_00709490 - fVar9 * fVar5 * fVar5);
    fVar9 = *param_3 * fVar8;
    fVar6 = param_3[1] * fVar8;
    fVar5 = param_3[2] * fVar8;
    fVar8 = param_3[3] * fVar8;
  }
  fVar10 = *param_2;
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  fVar3 = param_2[3];
  fVar4 = fVar9 * fVar10 + fVar5 * fVar2 + fVar6 * fVar1 + fVar8 * fVar3;
  fVar9 = (float)((uint)fVar9 ^ _DAT_006df2e0);
  fVar6 = (float)((uint)fVar6 ^ uRam006df2e4);
  fVar5 = (float)((uint)fVar5 ^ uRam006df2e8);
  fVar8 = (float)((uint)fVar8 ^ uRam006df2ec);
  fVar11 = fVar10 * fVar6 + (float)((uint)fVar4 & _DAT_006df2f0);
  fVar12 = fVar1 * fVar6 + (float)((uint)fVar4 & uRam006df2f4);
  fVar13 = fVar2 * fVar6 + (float)((uint)fVar4 & uRam006df2f8);
  fVar14 = fVar3 * fVar6 + (float)((uint)fVar4 & uRam006df2fc);
  fVar15 = fVar10 * fVar5 + (float)((uint)fVar4 & _DAT_006df300);
  fVar17 = fVar1 * fVar5 + (float)((uint)fVar4 & uRam006df304);
  fVar18 = fVar2 * fVar5 + (float)((uint)fVar4 & uRam006df308);
  fVar19 = fVar3 * fVar5 + (float)((uint)fVar4 & uRam006df30c);
  fVar7 = fVar10 * fVar9 + fVar4;
  fVar5 = fVar10 * fVar8 + (float)((uint)fVar4 & _DAT_006df310);
  fVar6 = fVar1 * fVar8 + (float)((uint)fVar4 & uRam006df314);
  fVar10 = fVar2 * fVar8 + (float)((uint)fVar4 & uRam006df318);
  fVar8 = fVar3 * fVar8 + (float)((uint)fVar4 & uRam006df31c);
  if (((uint)param_1 & 0xf) == 0) {
    *param_1 = fVar7;
    param_1[1] = fVar1 * fVar9;
    param_1[2] = fVar2 * fVar9;
    param_1[3] = fVar3 * fVar9;
    param_1[4] = fVar11;
    param_1[5] = fVar12;
    param_1[6] = fVar13;
    param_1[7] = fVar14;
    param_1[8] = fVar15;
    param_1[9] = fVar17;
    param_1[10] = fVar18;
    param_1[0xb] = fVar19;
    param_1[0xc] = fVar5;
    param_1[0xd] = fVar6;
    param_1[0xe] = fVar10;
    param_1[0xf] = fVar8;
  }
  else {
    *(ulonglong *)param_1 = CONCAT44(fVar1 * fVar9,fVar7);
    *(ulonglong *)(param_1 + 2) = CONCAT44(fVar3 * fVar9,fVar2 * fVar9);
    *(ulonglong *)(param_1 + 4) = CONCAT44(fVar12,fVar11);
    *(ulonglong *)(param_1 + 6) = CONCAT44(fVar14,fVar13);
    param_1[8] = fVar15;
    param_1[9] = fVar17;
    param_1[10] = fVar18;
    param_1[0xb] = fVar19;
    *(ulonglong *)(param_1 + 0xc) = CONCAT44(fVar6,fVar5);
    *(ulonglong *)(param_1 + 0xe) = CONCAT44(fVar8,fVar10);
  }
  return;
}


// ==== 0x5edc5e FUN_005edc5e

void FUN_005edc5e(float *param_1,float param_2,float param_3,float param_4)

{
  float local_30;
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  float local_20;
  float fStack_1c;
  float fStack_18;
  
  local_30 = param_4 * 0.5;
  fStack_2c = param_3 * 0.5;
  fStack_28 = param_2 * 0.5;
  uStack_24 = 0;
  FUN_0061b5d3(&local_30,&local_30,&local_20);
  *param_1 = local_20 * fStack_18 * fStack_2c + local_30 * fStack_28 * fStack_1c;
  param_1[1] = local_20 * fStack_28 * fStack_1c + -(local_30 * fStack_18 * fStack_2c);
  param_1[2] = local_30 * fStack_18 * fStack_1c + -(local_20 * fStack_28 * fStack_2c);
  param_1[3] = local_20 * fStack_18 * fStack_1c + local_30 * fStack_28 * fStack_2c;
  return;
}


// ==== 0x5edd20 FUN_005edd20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005edd20(float *param_1,float *param_2)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  float local_18 [4];
  int local_8;
  
  pfVar4 = param_2;
  fVar3 = param_2[5] + *param_2 + param_2[10];
  if (fVar3 <= 0.0) {
    local_18[1] = param_2[5];
    pfVar1 = param_2 + 10;
    local_18[0] = *param_2;
    local_18[2] = *pfVar1;
    param_2 = (float *)(uint)(*param_2 < param_2[5]);
    if (local_18[(int)param_2] < *pfVar1) {
      param_2 = (float *)0x2;
    }
    iVar5 = (int)param_2 * 4;
    iVar2 = *(int *)(&DAT_006a3d90 + iVar5);
    iVar6 = iVar2 * 4;
    local_8 = *(int *)(&DAT_006a3d90 + iVar6);
    fVar3 = SQRT(((local_18[(int)param_2] - local_18[iVar2]) - local_18[local_8]) + _K_ONE) *
            _K_HALF;
    param_1[(int)param_2] = fVar3;
    fVar3 = 0.25 / fVar3;
    param_1[iVar2] = (pfVar4[(int)param_2 + iVar6] + pfVar4[iVar2 + iVar5]) * fVar3;
    param_1[local_8] = (pfVar4[(int)param_2 + local_8 * 4] + pfVar4[iVar5 + local_8]) * fVar3;
    param_1[3] = (pfVar4[iVar6 + local_8] - pfVar4[local_8 * 4 + iVar2]) * fVar3;
  }
  else {
    fVar3 = SQRT(fVar3 + _K_ONE) * _K_HALF;
    param_1[3] = fVar3;
    fVar3 = 0.25 / fVar3;
    *param_1 = (param_2[6] - param_2[9]) * fVar3;
    param_1[1] = (param_2[8] - param_2[2]) * fVar3;
    param_1[2] = (param_2[1] - param_2[4]) * fVar3;
  }
  return;
}


// ==== 0x5ede80 FUN_005ede80

float * FUN_005ede80(float *param_1,int param_2,float *param_3,int param_4,float *param_5,
                    int param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
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
  float *pfVar22;
  int iVar23;
  
  if (0 < param_6) {
    fVar6 = *param_5;
    fVar7 = param_5[1];
    fVar8 = param_5[2];
    fVar9 = param_5[3];
    fVar10 = param_5[4];
    fVar11 = param_5[5];
    fVar12 = param_5[6];
    fVar13 = param_5[7];
    fVar14 = param_5[8];
    fVar15 = param_5[9];
    fVar16 = param_5[10];
    fVar17 = param_5[0xb];
    fVar18 = param_5[0xc];
    fVar19 = param_5[0xd];
    fVar20 = param_5[0xe];
    fVar21 = param_5[0xf];
    pfVar22 = param_1;
    do {
      fVar1 = *param_3;
      fVar2 = param_3[1];
      fVar3 = param_3[2];
      fVar4 = param_3[3];
      param_3 = (float *)(param_4 + (int)param_3);
      *pfVar22 = fVar1 * fVar6 + fVar2 * fVar10 + fVar3 * fVar14 + fVar4 * fVar18;
      pfVar22[1] = fVar1 * fVar7 + fVar2 * fVar11 + fVar3 * fVar15 + fVar4 * fVar19;
      pfVar22[2] = fVar1 * fVar8 + fVar2 * fVar12 + fVar3 * fVar16 + fVar4 * fVar20;
      pfVar22[3] = fVar1 * fVar9 + fVar2 * fVar13 + fVar3 * fVar17 + fVar4 * fVar21;
      pfVar22 = (float *)(param_2 + (int)pfVar22);
      iVar23 = param_6 + -1;
      bVar5 = 0 < param_6;
      param_6 = iVar23;
    } while (iVar23 != 0 && bVar5);
  }
  return param_1;
}


// ==== 0x5edf40 FUN_005edf40

float * FUN_005edf40(float *param_1,int param_2,float *param_3,int param_4,float *param_5,
                    int param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
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
  float *pfVar22;
  int iVar23;
  
  if (0 < param_6) {
    fVar6 = *param_5;
    fVar7 = param_5[1];
    fVar8 = param_5[2];
    fVar9 = param_5[3];
    fVar10 = param_5[4];
    fVar11 = param_5[5];
    fVar12 = param_5[6];
    fVar13 = param_5[7];
    fVar14 = param_5[8];
    fVar15 = param_5[9];
    fVar16 = param_5[10];
    fVar17 = param_5[0xb];
    fVar18 = param_5[0xc];
    fVar19 = param_5[0xd];
    fVar20 = param_5[0xe];
    fVar21 = param_5[0xf];
    pfVar22 = param_1;
    do {
      fVar1 = *param_3;
      fVar2 = param_3[1];
      fVar3 = param_3[2];
      fVar4 = param_3[3];
      param_3 = (float *)(param_4 + (int)param_3);
      *pfVar22 = fVar1 * fVar6 + fVar2 * fVar10 + fVar3 * fVar14 + fVar4 * fVar18;
      pfVar22[1] = fVar1 * fVar7 + fVar2 * fVar11 + fVar3 * fVar15 + fVar4 * fVar19;
      pfVar22[2] = fVar1 * fVar8 + fVar2 * fVar12 + fVar3 * fVar16 + fVar4 * fVar20;
      pfVar22[3] = fVar1 * fVar9 + fVar2 * fVar13 + fVar3 * fVar17 + fVar4 * fVar21;
      pfVar22 = (float *)(param_2 + (int)pfVar22);
      iVar23 = param_6 + -1;
      bVar5 = 0 < param_6;
      param_6 = iVar23;
    } while (iVar23 != 0 && bVar5);
  }
  return param_1;
}


// ==== 0x5ee000 FUN_005ee000

float * FUN_005ee000(float *param_1,int param_2,undefined8 *param_3,int param_4,float *param_5,
                    int param_6)

{
  float *pfVar1;
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
  float *pfVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  undefined8 uVar23;
  
  pfVar14 = param_1;
  if (param_6 < 4) {
    for (; param_6 != 0; param_6 = param_6 + -1) {
      uVar23 = FUN_005f4cfb(pfVar14,param_3,param_5);
      param_5 = (float *)((ulonglong)uVar23 >> 0x20);
      param_3 = (undefined8 *)((int)param_3 + param_4);
      pfVar14 = (float *)((int)uVar23 + param_2);
    }
  }
  else {
    fVar2 = *param_5;
    fVar3 = param_5[1];
    fVar4 = param_5[2];
    fVar5 = param_5[3];
    fVar6 = param_5[4];
    fVar7 = param_5[5];
    fVar8 = param_5[6];
    fVar9 = param_5[7];
    fVar10 = param_5[0xc];
    fVar11 = param_5[0xd];
    fVar12 = param_5[0xe];
    fVar13 = param_5[0xf];
    while( true ) {
      for (; 3 < param_6; param_6 = param_6 + -4) {
        fVar15 = (float)*param_3;
        fVar16 = (float)((ulonglong)*param_3 >> 0x20);
        fVar17 = (float)*(undefined8 *)(param_4 + (int)param_3);
        fVar18 = (float)((ulonglong)*(undefined8 *)(param_4 + (int)param_3) >> 0x20);
        param_3 = (undefined8 *)((int)param_3 + param_4 * 2);
        fVar19 = (float)*param_3;
        fVar20 = (float)((ulonglong)*param_3 >> 0x20);
        fVar21 = (float)*(undefined8 *)(param_4 + (int)param_3);
        fVar22 = (float)((ulonglong)*(undefined8 *)(param_4 + (int)param_3) >> 0x20);
        param_3 = (undefined8 *)((int)param_3 + param_4 * 2);
        *pfVar14 = fVar15 * fVar2 + fVar16 * fVar6 + fVar10;
        pfVar14[1] = fVar15 * fVar3 + fVar16 * fVar7 + fVar11;
        pfVar14[2] = fVar15 * fVar4 + fVar16 * fVar8 + fVar12;
        pfVar14[3] = fVar15 * fVar5 + fVar16 * fVar9 + fVar13;
        pfVar1 = (float *)(param_2 + (int)pfVar14);
        *pfVar1 = fVar17 * fVar2 + fVar18 * fVar6 + fVar10;
        pfVar1[1] = fVar17 * fVar3 + fVar18 * fVar7 + fVar11;
        pfVar1[2] = fVar17 * fVar4 + fVar18 * fVar8 + fVar12;
        pfVar1[3] = fVar17 * fVar5 + fVar18 * fVar9 + fVar13;
        pfVar14 = (float *)((int)pfVar14 + param_2 * 2);
        *pfVar14 = fVar19 * fVar2 + fVar20 * fVar6 + fVar10;
        pfVar14[1] = fVar19 * fVar3 + fVar20 * fVar7 + fVar11;
        pfVar14[2] = fVar19 * fVar4 + fVar20 * fVar8 + fVar12;
        pfVar14[3] = fVar19 * fVar5 + fVar20 * fVar9 + fVar13;
        pfVar1 = (float *)(param_2 + (int)pfVar14);
        *pfVar1 = fVar21 * fVar2 + fVar22 * fVar6 + fVar10;
        pfVar1[1] = fVar21 * fVar3 + fVar22 * fVar7 + fVar11;
        pfVar1[2] = fVar21 * fVar4 + fVar22 * fVar8 + fVar12;
        pfVar1[3] = fVar21 * fVar5 + fVar22 * fVar9 + fVar13;
        pfVar14 = (float *)((int)pfVar14 + param_2 * 2);
      }
      if (param_6 == 0) break;
      param_3 = (undefined8 *)((int)param_3 + param_4 * (param_6 + -4));
      pfVar14 = (float *)((int)pfVar14 + param_2 * (param_6 + -4));
      param_6 = 4;
    }
  }
  return param_1;
}


// ==== 0x5ee260 FUN_005ee260

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_005ee260(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,float *param_5,
            int param_6)

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
  undefined8 *puVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar18;
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  undefined8 uVar25;
  
  puVar10 = param_1;
  if (param_6 < 4) {
    for (; param_6 != 0; param_6 = param_6 + -1) {
      uVar25 = FUN_005f4d89(puVar10,param_3,param_5);
      param_5 = (float *)((ulonglong)uVar25 >> 0x20);
      param_3 = (undefined8 *)((int)param_3 + param_4);
      puVar10 = (undefined8 *)((int)uVar25 + param_2);
    }
  }
  else {
    fVar1 = *param_5;
    fVar2 = param_5[1];
    fVar3 = param_5[3];
    fVar4 = param_5[4];
    fVar5 = param_5[5];
    fVar6 = param_5[7];
    fVar7 = param_5[0xc];
    fVar8 = param_5[0xd];
    fVar9 = param_5[0xf];
    while( true ) {
      for (; 3 < param_6; param_6 = param_6 + -4) {
        fVar11 = (float)*param_3;
        fVar12 = (float)((ulonglong)*param_3 >> 0x20);
        fVar13 = (float)*(undefined8 *)(param_4 + (int)param_3);
        fVar14 = (float)((ulonglong)*(undefined8 *)(param_4 + (int)param_3) >> 0x20);
        param_3 = (undefined8 *)((int)param_3 + param_4 * 2);
        fVar19 = (float)*(undefined8 *)(param_4 + (int)param_3);
        fVar21 = (float)((ulonglong)*(undefined8 *)(param_4 + (int)param_3) >> 0x20);
        fVar18 = (float)((ulonglong)*param_3 >> 0x20);
        fVar15 = (float)*param_3;
        param_3 = (undefined8 *)((int)param_3 + param_4 * 2);
        auVar16._0_4_ = fVar12 * fVar4;
        auVar16._4_4_ = fVar14 * fVar4;
        auVar16._8_4_ = fVar18 * fVar4;
        auVar16._12_4_ = fVar21 * fVar4;
        fVar20 = fVar11 * fVar3 + fVar12 * fVar6 + fVar9;
        fVar22 = fVar13 * fVar3 + fVar14 * fVar6 + fVar9;
        fVar23 = fVar15 * fVar3 + fVar18 * fVar6 + fVar9;
        fVar24 = fVar19 * fVar3 + fVar21 * fVar6 + fVar9;
        auVar17._4_4_ = fVar22;
        auVar17._0_4_ = fVar20;
        auVar17._8_4_ = fVar23;
        auVar17._12_4_ = fVar24;
        auVar17 = rcpps(auVar16,auVar17);
        fVar20 = auVar17._0_4_ * (_DAT_006df340 - fVar20 * auVar17._0_4_);
        fVar22 = auVar17._4_4_ * (fRam006df344 - fVar22 * auVar17._4_4_);
        fVar23 = auVar17._8_4_ * (fRam006df348 - fVar23 * auVar17._8_4_);
        fVar24 = auVar17._12_4_ * (fRam006df34c - fVar24 * auVar17._12_4_);
        *puVar10 = CONCAT44((fVar11 * fVar2 + fVar12 * fVar5 + fVar8) * fVar20,
                            (fVar11 * fVar1 + auVar16._0_4_ + fVar7) * fVar20);
        *(ulonglong *)(param_2 + (int)puVar10) =
             CONCAT44((fVar13 * fVar2 + fVar14 * fVar5 + fVar8) * fVar22,
                      (fVar13 * fVar1 + auVar16._4_4_ + fVar7) * fVar22);
        puVar10 = (undefined8 *)((int)puVar10 + param_2 * 2);
        *puVar10 = CONCAT44((fVar15 * fVar2 + fVar18 * fVar5 + fVar8) * fVar23,
                            (fVar15 * fVar1 + auVar16._8_4_ + fVar7) * fVar23);
        *(ulonglong *)(param_2 + (int)puVar10) =
             CONCAT44((fVar19 * fVar2 + fVar21 * fVar5 + fVar8) * fVar24,
                      (fVar19 * fVar1 + auVar16._12_4_ + fVar7) * fVar24);
        puVar10 = (undefined8 *)((int)puVar10 + param_2 * 2);
      }
      if (param_6 == 0) break;
      param_3 = (undefined8 *)((int)param_3 + param_4 * (param_6 + -4));
      puVar10 = (undefined8 *)((int)puVar10 + param_2 * (param_6 + -4));
      param_6 = 4;
    }
  }
  return param_1;
}


// ==== 0x5ee4c0 FUN_005ee4c0

undefined8 *
FUN_005ee4c0(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,float *param_5,
            int param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined8 *puVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  undefined8 uVar14;
  
  puVar5 = param_1;
  if (param_6 < 4) {
    for (; param_6 != 0; param_6 = param_6 + -1) {
      uVar14 = FUN_005f4d50(puVar5,param_3,param_5);
      param_5 = (float *)((ulonglong)uVar14 >> 0x20);
      param_3 = (undefined8 *)((int)param_3 + param_4);
      puVar5 = (undefined8 *)((int)uVar14 + param_2);
    }
  }
  else {
    fVar1 = *param_5;
    fVar2 = param_5[1];
    fVar3 = param_5[4];
    fVar4 = param_5[5];
    while( true ) {
      for (; 3 < param_6; param_6 = param_6 + -4) {
        fVar6 = (float)*param_3;
        fVar7 = (float)((ulonglong)*param_3 >> 0x20);
        fVar8 = (float)*(undefined8 *)(param_4 + (int)param_3);
        fVar9 = (float)((ulonglong)*(undefined8 *)(param_4 + (int)param_3) >> 0x20);
        param_3 = (undefined8 *)((int)param_3 + param_4 * 2);
        fVar10 = (float)*param_3;
        fVar11 = (float)((ulonglong)*param_3 >> 0x20);
        fVar12 = (float)*(undefined8 *)(param_4 + (int)param_3);
        fVar13 = (float)((ulonglong)*(undefined8 *)(param_4 + (int)param_3) >> 0x20);
        param_3 = (undefined8 *)((int)param_3 + param_4 * 2);
        *puVar5 = CONCAT44(fVar6 * fVar2 + fVar7 * fVar4,fVar6 * fVar1 + fVar7 * fVar3);
        *(ulonglong *)(param_2 + (int)puVar5) =
             CONCAT44(fVar8 * fVar2 + fVar9 * fVar4,fVar8 * fVar1 + fVar9 * fVar3);
        puVar5 = (undefined8 *)((int)puVar5 + param_2 * 2);
        *puVar5 = CONCAT44(fVar10 * fVar2 + fVar11 * fVar4,fVar10 * fVar1 + fVar11 * fVar3);
        *(ulonglong *)(param_2 + (int)puVar5) =
             CONCAT44(fVar12 * fVar2 + fVar13 * fVar4,fVar12 * fVar1 + fVar13 * fVar3);
        puVar5 = (undefined8 *)((int)puVar5 + param_2 * 2);
      }
      if (param_6 == 0) break;
      param_3 = (undefined8 *)((int)param_3 + param_4 * (param_6 + -4));
      puVar5 = (undefined8 *)((int)puVar5 + param_2 * (param_6 + -4));
      param_6 = 4;
    }
  }
  return param_1;
}


// ==== 0x5ee680 FUN_005ee680

float * FUN_005ee680(float *param_1,int param_2,float *param_3,int param_4,float *param_5,
                    int param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
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
  float *pfVar21;
  int iVar22;
  
  if (0 < param_6) {
    fVar5 = *param_5;
    fVar6 = param_5[1];
    fVar7 = param_5[2];
    fVar8 = param_5[3];
    fVar9 = param_5[4];
    fVar10 = param_5[5];
    fVar11 = param_5[6];
    fVar12 = param_5[7];
    fVar13 = param_5[8];
    fVar14 = param_5[9];
    fVar15 = param_5[10];
    fVar16 = param_5[0xb];
    fVar17 = param_5[0xc];
    fVar18 = param_5[0xd];
    fVar19 = param_5[0xe];
    fVar20 = param_5[0xf];
    pfVar21 = param_1;
    do {
      fVar1 = *param_3;
      fVar2 = param_3[1];
      fVar3 = param_3[2];
      param_3 = (float *)(param_4 + (int)param_3);
      *pfVar21 = fVar1 * fVar5 + fVar2 * fVar9 + fVar3 * fVar13 + fVar17;
      pfVar21[1] = fVar1 * fVar6 + fVar2 * fVar10 + fVar3 * fVar14 + fVar18;
      pfVar21[2] = fVar1 * fVar7 + fVar2 * fVar11 + fVar3 * fVar15 + fVar19;
      pfVar21[3] = fVar1 * fVar8 + fVar2 * fVar12 + fVar3 * fVar16 + fVar20;
      pfVar21 = (float *)(param_2 + (int)pfVar21);
      iVar22 = param_6 + -1;
      bVar4 = 0 < param_6;
      param_6 = iVar22;
    } while (iVar22 != 0 && bVar4);
  }
  return param_1;
}


// ==== 0x5ee720 FUN_005ee720

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_005ee720(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,float *param_5,
            int param_6)

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
  undefined8 *puVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar29;
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  undefined8 uVar36;
  
  puVar21 = param_1;
  if (param_6 < 4) {
    for (; param_6 != 0; param_6 = param_6 + -1) {
      uVar36 = thunk_FUN_005f42ad(puVar21,param_3,param_5);
      param_5 = (float *)((ulonglong)uVar36 >> 0x20);
      param_3 = (undefined8 *)((int)param_3 + param_4);
      puVar21 = (undefined8 *)((int)uVar36 + param_2);
    }
  }
  else {
    fVar1 = *param_5;
    fVar2 = param_5[1];
    fVar3 = param_5[2];
    fVar4 = param_5[3];
    fVar5 = param_5[4];
    fVar6 = param_5[5];
    fVar7 = param_5[6];
    fVar8 = param_5[7];
    fVar9 = param_5[8];
    fVar10 = param_5[9];
    fVar11 = param_5[10];
    fVar12 = param_5[0xb];
    fVar13 = param_5[0xc];
    fVar14 = param_5[0xd];
    fVar15 = param_5[0xe];
    fVar16 = param_5[0xf];
    while( true ) {
      for (; 3 < param_6; param_6 = param_6 + -4) {
        fVar22 = (float)*param_3;
        fVar23 = (float)((ulonglong)*param_3 >> 0x20);
        fVar24 = (float)*(undefined8 *)(param_4 + (int)param_3);
        fVar25 = (float)((ulonglong)*(undefined8 *)(param_4 + (int)param_3) >> 0x20);
        fVar17 = *(float *)(param_3 + 1);
        fVar18 = *(float *)(param_4 + 8 + (int)param_3);
        param_3 = (undefined8 *)((int)param_3 + param_4 * 2);
        fVar30 = (float)*(undefined8 *)(param_4 + (int)param_3);
        fVar32 = (float)((ulonglong)*(undefined8 *)(param_4 + (int)param_3) >> 0x20);
        fVar19 = *(float *)(param_3 + 1);
        fVar20 = *(float *)(param_4 + 8 + (int)param_3);
        fVar29 = (float)((ulonglong)*param_3 >> 0x20);
        fVar26 = (float)*param_3;
        param_3 = (undefined8 *)((int)param_3 + param_4 * 2);
        auVar27._0_4_ = fVar17 * fVar10;
        auVar27._4_4_ = fVar18 * fVar10;
        auVar27._8_4_ = fVar19 * fVar10;
        auVar27._12_4_ = fVar20 * fVar10;
        fVar31 = fVar22 * fVar4 + fVar23 * fVar8 + fVar17 * fVar12 + fVar16;
        fVar33 = fVar24 * fVar4 + fVar25 * fVar8 + fVar18 * fVar12 + fVar16;
        fVar34 = fVar26 * fVar4 + fVar29 * fVar8 + fVar19 * fVar12 + fVar16;
        fVar35 = fVar30 * fVar4 + fVar32 * fVar8 + fVar20 * fVar12 + fVar16;
        auVar28._4_4_ = fVar33;
        auVar28._0_4_ = fVar31;
        auVar28._8_4_ = fVar34;
        auVar28._12_4_ = fVar35;
        auVar28 = rcpps(auVar27,auVar28);
        fVar31 = auVar28._0_4_ * (_DAT_006df380 - fVar31 * auVar28._0_4_);
        fVar33 = auVar28._4_4_ * (fRam006df384 - fVar33 * auVar28._4_4_);
        fVar34 = auVar28._8_4_ * (fRam006df388 - fVar34 * auVar28._8_4_);
        fVar35 = auVar28._12_4_ * (fRam006df38c - fVar35 * auVar28._12_4_);
        *puVar21 = CONCAT44((fVar22 * fVar2 + fVar23 * fVar6 + auVar27._0_4_ + fVar14) * fVar31,
                            (fVar22 * fVar1 + fVar23 * fVar5 + fVar17 * fVar9 + fVar13) * fVar31);
        *(float *)(puVar21 + 1) =
             (fVar22 * fVar3 + fVar23 * fVar7 + fVar17 * fVar11 + fVar15) * fVar31;
        *(ulonglong *)(param_2 + (int)puVar21) =
             CONCAT44((fVar24 * fVar2 + fVar25 * fVar6 + auVar27._4_4_ + fVar14) * fVar33,
                      (fVar24 * fVar1 + fVar25 * fVar5 + fVar18 * fVar9 + fVar13) * fVar33);
        *(float *)(param_2 + 8 + (int)puVar21) =
             (fVar24 * fVar3 + fVar25 * fVar7 + fVar18 * fVar11 + fVar15) * fVar33;
        puVar21 = (undefined8 *)((int)puVar21 + param_2 * 2);
        *puVar21 = CONCAT44((fVar26 * fVar2 + fVar29 * fVar6 + auVar27._8_4_ + fVar14) * fVar34,
                            (fVar26 * fVar1 + fVar29 * fVar5 + fVar19 * fVar9 + fVar13) * fVar34);
        *(float *)(puVar21 + 1) =
             (fVar26 * fVar3 + fVar29 * fVar7 + fVar19 * fVar11 + fVar15) * fVar34;
        *(ulonglong *)(param_2 + (int)puVar21) =
             CONCAT44((fVar30 * fVar2 + fVar32 * fVar6 + auVar27._12_4_ + fVar14) * fVar35,
                      (fVar30 * fVar1 + fVar32 * fVar5 + fVar20 * fVar9 + fVar13) * fVar35);
        *(float *)(param_2 + 8 + (int)puVar21) =
             (fVar30 * fVar3 + fVar32 * fVar7 + fVar20 * fVar11 + fVar15) * fVar35;
        puVar21 = (undefined8 *)((int)puVar21 + param_2 * 2);
      }
      if (param_6 == 0) break;
      param_3 = (undefined8 *)((int)param_3 + param_4 * (param_6 + -4));
      puVar21 = (undefined8 *)((int)puVar21 + param_2 * (param_6 + -4));
      param_6 = 4;
    }
  }
  return param_1;
}


// ==== 0x5eea40 FUN_005eea40

undefined8 *
FUN_005eea40(undefined8 *param_1,int param_2,undefined8 *param_3,int param_4,float *param_5,
            int param_6)

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
  undefined8 *puVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  undefined8 uVar23;
  
  puVar14 = param_1;
  if (param_6 < 4) {
    for (; param_6 != 0; param_6 = param_6 + -1) {
      uVar23 = FUN_005f3fb8(puVar14,param_3,param_5);
      param_5 = (float *)((ulonglong)uVar23 >> 0x20);
      param_3 = (undefined8 *)((int)param_3 + param_4);
      puVar14 = (undefined8 *)((int)uVar23 + param_2);
    }
  }
  else {
    fVar1 = *param_5;
    fVar2 = param_5[1];
    fVar3 = param_5[2];
    fVar4 = param_5[4];
    fVar5 = param_5[5];
    fVar6 = param_5[6];
    fVar7 = param_5[8];
    fVar8 = param_5[9];
    fVar9 = param_5[10];
    while( true ) {
      for (; 3 < param_6; param_6 = param_6 + -4) {
        fVar15 = (float)*param_3;
        fVar16 = (float)((ulonglong)*param_3 >> 0x20);
        fVar17 = (float)*(undefined8 *)(param_4 + (int)param_3);
        fVar18 = (float)((ulonglong)*(undefined8 *)(param_4 + (int)param_3) >> 0x20);
        fVar10 = *(float *)(param_3 + 1);
        fVar11 = *(float *)(param_4 + 8 + (int)param_3);
        param_3 = (undefined8 *)((int)param_3 + param_4 * 2);
        fVar19 = (float)*param_3;
        fVar20 = (float)((ulonglong)*param_3 >> 0x20);
        fVar21 = (float)*(undefined8 *)(param_4 + (int)param_3);
        fVar22 = (float)((ulonglong)*(undefined8 *)(param_4 + (int)param_3) >> 0x20);
        fVar12 = *(float *)(param_3 + 1);
        fVar13 = *(float *)(param_4 + 8 + (int)param_3);
        param_3 = (undefined8 *)((int)param_3 + param_4 * 2);
        *puVar14 = CONCAT44(fVar15 * fVar2 + fVar16 * fVar5 + fVar10 * fVar8,
                            fVar15 * fVar1 + fVar16 * fVar4 + fVar10 * fVar7);
        *(float *)(puVar14 + 1) = fVar15 * fVar3 + fVar16 * fVar6 + fVar10 * fVar9;
        *(ulonglong *)(param_2 + (int)puVar14) =
             CONCAT44(fVar17 * fVar2 + fVar18 * fVar5 + fVar11 * fVar8,
                      fVar17 * fVar1 + fVar18 * fVar4 + fVar11 * fVar7);
        *(float *)(param_2 + 8 + (int)puVar14) = fVar17 * fVar3 + fVar18 * fVar6 + fVar11 * fVar9;
        puVar14 = (undefined8 *)((int)puVar14 + param_2 * 2);
        *puVar14 = CONCAT44(fVar19 * fVar2 + fVar20 * fVar5 + fVar12 * fVar8,
                            fVar19 * fVar1 + fVar20 * fVar4 + fVar12 * fVar7);
        *(float *)(puVar14 + 1) = fVar19 * fVar3 + fVar20 * fVar6 + fVar12 * fVar9;
        *(ulonglong *)(param_2 + (int)puVar14) =
             CONCAT44(fVar21 * fVar2 + fVar22 * fVar5 + fVar13 * fVar8,
                      fVar21 * fVar1 + fVar22 * fVar4 + fVar13 * fVar7);
        *(float *)(param_2 + 8 + (int)puVar14) = fVar21 * fVar3 + fVar22 * fVar6 + fVar13 * fVar9;
        puVar14 = (undefined8 *)((int)puVar14 + param_2 * 2);
      }
      if (param_6 == 0) break;
      param_3 = (undefined8 *)((int)param_3 + param_4 * (param_6 + -4));
      puVar14 = (undefined8 *)((int)puVar14 + param_2 * (param_6 + -4));
      param_6 = 4;
    }
  }
  return param_1;
}


// ==== 0x5eecbc FUN_005eecbc

void FUN_005eecbc(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  uVar3 = *param_3;
  uVar5 = param_3[1];
  uVar8 = *param_2;
  uVar1 = param_2[1];
  uVar4 = CONCAT44((int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
  uVar6 = CONCAT44((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
  uVar2 = PackedFloatingMUL(uVar3,uVar1);
  uVar3 = PackedFloatingMUL(uVar5,uVar8);
  uVar7 = PackedFloatingMUL(uVar6 ^ 0x80000000,uVar8);
  uVar5 = PackedFloatingMUL(uVar4,uVar1);
  uVar3 = PackedFloatingADD(uVar2 ^ 0x80000000,uVar3);
  uVar5 = PackedFloatingSUB(uVar5,uVar7);
  uVar2 = param_3[1];
  uVar9 = PackedFloatingMUL(uVar6,uVar1);
  uVar5 = PackedFloatingAccumulate(uVar5,uVar3);
  uVar7 = PackedFloatingMUL(uVar4 ^ 0x80000000,uVar8);
  uVar3 = PackedFloatingMUL(*param_3,uVar8);
  *param_1 = uVar5;
  uVar5 = PackedFloatingMUL(uVar2 ^ 0x80000000,uVar1);
  uVar8 = PackedFloatingADD(uVar7,uVar9);
  uVar3 = PackedFloatingSUB(uVar5,uVar3);
  uVar3 = PackedFloatingAccumulate(uVar8,uVar3);
  param_1[1] = uVar3;
  FastExitMediaState();
  return;
}


// ==== 0x5eed55 FUN_005eed55

void FUN_005eed55(undefined8 *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 in_MM4;
  undefined8 uVar5;
  ulonglong uVar6;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  uVar3 = PackedFloatingMUL(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar2,uVar2);
  uVar3 = PackedFloatingADD(uVar3,uVar4);
  uVar3 = PackedFloatingAccumulate(uVar3,uVar3);
  uVar5 = PackedFloatingReciprocalSQRAprox(in_MM4,uVar3);
  uVar6 = PackedFloatingCompareGT(uVar3,0x80000000800000);
  uVar4 = PackedFloatingMUL(uVar5,uVar5);
  uVar3 = PackedFloatingReciprocalSQRIter1(uVar3,uVar4);
  uVar3 = PackedFloatingReciprocalIter2(uVar3,uVar5);
  uVar4 = PackedFloatingMUL(uVar1 & uVar6,uVar3);
  uVar3 = PackedFloatingMUL(uVar2 & uVar6,uVar3);
  *param_1 = uVar4;
  param_1[1] = uVar3;
  FastExitMediaState();
  return;
}


// ==== 0x5eedb2 FUN_005eedb2

void FUN_005eedb2(undefined8 *param_1,undefined8 *param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  
  uVar1 = param_1[1];
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = *param_1;
    *(int *)(param_2 + 1) = (int)uVar1;
  }
  if (param_3 != (undefined4 *)0x0) {
    uVar1 = FUN_0061b900();
    uVar1 = PackedFloatingMUL(uVar1,0x4000000040000000);
    *param_3 = (int)uVar1;
  }
  FastExitMediaState();
  return;
}


// ==== 0x5eedf6 FUN_005eedf6

void FUN_005eedf6(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined4 uVar9;
  ulonglong uVar10;
  undefined4 uVar11;
  
  uVar2 = *param_2;
  uVar8 = (ulonglong)*(uint *)((int)param_2 + 0x14);
  uVar1 = PackedFloatingADD(uVar2,uVar8);
  uVar10 = (ulonglong)*(uint *)(param_2 + 5);
  uVar3 = PackedFloatingSUB(uVar2,uVar8);
  uVar5 = PackedFloatingSUBR(uVar2,uVar8);
  uVar7 = PackedFloatingSUBR(uVar2,uVar10);
  uVar2 = PackedFloatingADD(uVar1,uVar10);
  lVar4 = PackedFloatingSUB(uVar3,uVar10);
  uVar1 = PackedFloatingSUB(uVar5,uVar10);
  uVar3 = PackedFloatingSUB(uVar7,uVar8);
  uVar2 = CONCAT44((int)uVar1,(int)uVar2);
  uVar3 = CONCAT44((int)uVar3,(int)uVar3);
  uVar5 = PackedFloatingCompareGE(lVar4 << 0x20,uVar2);
  uVar7 = PackedFloatingCompareGE(CONCAT44((int)lVar4,(int)uVar1),uVar3);
  uVar5 = packssdw(uVar5,uVar7);
  uVar10 = packsswb(uVar5,uVar5);
  uVar9 = (undefined4)param_2[4];
  uVar6 = (undefined4)((ulonglong)lVar4 >> 0x20);
  uVar11 = (undefined4)((ulonglong)param_2[4] >> 0x20);
  if ((uVar10 & 1) == 0) {
    uVar2 = PackedFloatingADD(uVar2,0xbf8000003f800000);
    uVar1 = PackedFloatingReciprocalSQRAprox(uVar8,uVar2);
    uVar2 = CONCAT44((int)uVar2,(int)uVar2);
    uVar3 = PackedFloatingMUL(uVar1,uVar1);
    uVar5 = PackedFloatingReciprocalSQRIter1(uVar3,uVar2);
    uVar3 = PackedFloatingSUB(CONCAT44(uVar9,*(undefined4 *)(param_2 + 3)),
                              CONCAT44(*(undefined4 *)(param_2 + 1),uVar11));
    uVar5 = PackedFloatingReciprocalIter2(uVar5,uVar1);
    uVar1 = PackedFloatingSUB(CONCAT44(uVar6,uVar6),(ulonglong)*(uint *)(param_2 + 2));
    uVar5 = PackedFloatingMUL(uVar5,0x3f0000003f000000);
    uVar2 = PackedFloatingMUL(uVar2,uVar5);
    uVar1 = PackedFloatingMUL(uVar1,uVar5);
    uVar3 = PackedFloatingMUL(uVar3,uVar5);
    *param_1 = uVar3;
    param_1[1] = CONCAT44((int)uVar2,(int)uVar1);
    FastExitMediaState();
    return;
  }
  if (((uint)uVar10 & 0xff00ff00) == 0xff00ff00) {
    uVar2 = PackedFloatingADD(lVar4,0xbf8000003f800000);
    uVar6 = (undefined4)((ulonglong)uVar1 >> 0x20);
    uVar3 = PackedFloatingReciprocalSQRAprox(uVar8,uVar2);
    uVar5 = PackedFloatingMUL(uVar3,uVar3);
    uVar2 = CONCAT44((int)uVar2,(int)uVar2);
    uVar1 = PackedFloatingSUB((ulonglong)*(uint *)(param_2 + 2),CONCAT44(uVar6,uVar6));
    uVar5 = PackedFloatingReciprocalSQRIter1(uVar5,uVar2);
    uVar3 = PackedFloatingReciprocalIter2(uVar5,uVar3);
    uVar3 = PackedFloatingMUL(uVar3,0x3f0000003f000000);
    uVar2 = PackedFloatingMUL(uVar2,uVar3);
    uVar5 = PackedFloatingADD(CONCAT44(*(undefined4 *)(param_2 + 3),uVar9),
                              CONCAT44(uVar11,*(undefined4 *)(param_2 + 1)) ^ 0x8000000000000000);
    uVar1 = PackedFloatingMUL(uVar1,uVar3);
    uVar3 = PackedFloatingMUL(uVar5,uVar3);
    param_1[1] = uVar3;
    *param_1 = CONCAT44((int)uVar1,(int)uVar2);
    FastExitMediaState();
    return;
  }
  if ((uVar10 & 0x10000) != 0) {
    uVar2 = PackedFloatingADD(uVar1,0xbf8000003f800000);
    uVar3 = PackedFloatingReciprocalSQRAprox(uVar8,uVar2);
    uVar5 = PackedFloatingMUL(uVar3,uVar3);
    uVar1 = CONCAT44((int)uVar2,(int)uVar2);
    uVar2 = PackedFloatingReciprocalSQRIter1(uVar5,uVar1);
    uVar3 = PackedFloatingReciprocalIter2(uVar2,uVar3);
    uVar2 = PackedFloatingADD(CONCAT44(uVar6,uVar6),(ulonglong)*(uint *)(param_2 + 2));
    uVar5 = PackedFloatingMUL(uVar3,0x3f0000003f000000);
    uVar3 = PackedFloatingADD(CONCAT44(uVar9,*(undefined4 *)(param_2 + 3)),
                              CONCAT44(*(undefined4 *)(param_2 + 1),uVar11) ^ 0x8000000000000000);
    uVar2 = PackedFloatingMUL(uVar2,uVar5);
    uVar1 = PackedFloatingMUL(uVar1,uVar5);
    uVar3 = PackedFloatingMUL(uVar3,uVar5);
    param_1[1] = uVar3;
    *param_1 = CONCAT44((int)uVar1,(int)uVar2);
    FastExitMediaState();
    return;
  }
  uVar3 = PackedFloatingADD(uVar3,0xbf8000003f800000);
  uVar2 = PackedFloatingReciprocalSQRAprox(uVar1,uVar3);
  uVar1 = PackedFloatingMUL(uVar2,uVar2);
  uVar3 = CONCAT44((int)uVar3,(int)uVar3);
  uVar1 = PackedFloatingReciprocalSQRIter1(uVar1,uVar3);
  uVar1 = PackedFloatingReciprocalIter2(uVar1,uVar2);
  uVar2 = PackedFloatingSUB(CONCAT44(uVar6,uVar6),(ulonglong)*(uint *)(param_2 + 2));
  uVar5 = PackedFloatingADD(CONCAT44(*(undefined4 *)(param_2 + 3),uVar9),
                            CONCAT44(uVar11,*(undefined4 *)(param_2 + 1)));
  uVar1 = PackedFloatingMUL(uVar1,0x3f0000003f000000);
  uVar3 = PackedFloatingMUL(uVar3,uVar1);
  uVar2 = PackedFloatingMUL(uVar2,uVar1);
  uVar1 = PackedFloatingMUL(uVar5,uVar1);
  *param_1 = uVar1;
  param_1[1] = CONCAT44((int)uVar2,(int)uVar3);
  FastExitMediaState();
  return;
}


// ==== 0x5ef012 FUN_005ef012

void FUN_005ef012(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined4 uVar9;
  ulonglong uVar10;
  undefined4 uVar11;
  
  uVar2 = *param_2;
  uVar8 = (ulonglong)*(uint *)((int)param_2 + 0x14);
  uVar1 = PackedFloatingADD(uVar2,uVar8);
  uVar10 = (ulonglong)*(uint *)(param_2 + 5);
  uVar3 = PackedFloatingSUB(uVar2,uVar8);
  uVar5 = PackedFloatingSUBR(uVar2,uVar8);
  uVar7 = PackedFloatingSUBR(uVar2,uVar10);
  uVar2 = PackedFloatingADD(uVar1,uVar10);
  lVar4 = PackedFloatingSUB(uVar3,uVar10);
  uVar1 = PackedFloatingSUB(uVar5,uVar10);
  uVar3 = PackedFloatingSUB(uVar7,uVar8);
  uVar2 = CONCAT44((int)uVar1,(int)uVar2);
  uVar3 = CONCAT44((int)uVar3,(int)uVar3);
  uVar5 = PackedFloatingCompareGE(lVar4 << 0x20,uVar2);
  uVar7 = PackedFloatingCompareGE(CONCAT44((int)lVar4,(int)uVar1),uVar3);
  uVar10 = packssdw(uVar5,uVar7);
  uVar9 = (undefined4)param_2[4];
  uVar6 = (undefined4)((ulonglong)lVar4 >> 0x20);
  uVar11 = (undefined4)((ulonglong)param_2[4] >> 0x20);
  if ((uVar10 >> 7 & 1) == 0) {
    uVar2 = PackedFloatingADD(uVar2,0xbf8000003f800000);
    uVar1 = PackedFloatingReciprocalSQRAprox(uVar8,uVar2);
    uVar2 = CONCAT44((int)uVar2,(int)uVar2);
    uVar3 = PackedFloatingMUL(uVar1,uVar1);
    uVar5 = PackedFloatingReciprocalSQRIter1(uVar3,uVar2);
    uVar3 = PackedFloatingSUB(CONCAT44(uVar9,*(undefined4 *)(param_2 + 3)),
                              CONCAT44(*(undefined4 *)(param_2 + 1),uVar11));
    uVar5 = PackedFloatingReciprocalIter2(uVar5,uVar1);
    uVar1 = PackedFloatingSUB(CONCAT44(uVar6,uVar6),(ulonglong)*(uint *)(param_2 + 2));
    uVar5 = PackedFloatingMUL(uVar5,0x3f0000003f000000);
    uVar2 = PackedFloatingMUL(uVar2,uVar5);
    uVar1 = PackedFloatingMUL(uVar1,uVar5);
    uVar3 = PackedFloatingMUL(uVar3,uVar5);
    *param_1 = uVar3;
    param_1[1] = CONCAT44((int)uVar2,(int)uVar1);
    FastExitMediaState();
    return;
  }
  if ((byte)(((byte)(uVar10 >> 0x17) & 1) << 2 | ((byte)(uVar10 >> 0x1f) & 1) << 3 |
             ((byte)(uVar10 >> 0x37) & 1) << 6 | (byte)(uVar10 >> 0x38) & 0x80) == 0xcc) {
    uVar2 = PackedFloatingADD(lVar4,0xbf8000003f800000);
    uVar6 = (undefined4)((ulonglong)uVar1 >> 0x20);
    uVar3 = PackedFloatingReciprocalSQRAprox(uVar8,uVar2);
    uVar5 = PackedFloatingMUL(uVar3,uVar3);
    uVar2 = CONCAT44((int)uVar2,(int)uVar2);
    uVar1 = PackedFloatingSUB((ulonglong)*(uint *)(param_2 + 2),CONCAT44(uVar6,uVar6));
    uVar5 = PackedFloatingReciprocalSQRIter1(uVar5,uVar2);
    uVar3 = PackedFloatingReciprocalIter2(uVar5,uVar3);
    uVar3 = PackedFloatingMUL(uVar3,0x3f0000003f000000);
    uVar2 = PackedFloatingMUL(uVar2,uVar3);
    uVar5 = PackedFloatingADD(CONCAT44(*(undefined4 *)(param_2 + 3),uVar9),
                              CONCAT44(uVar11,*(undefined4 *)(param_2 + 1)) ^ 0x8000000000000000);
    uVar1 = PackedFloatingMUL(uVar1,uVar3);
    uVar3 = PackedFloatingMUL(uVar5,uVar3);
    param_1[1] = uVar3;
    *param_1 = CONCAT44((int)uVar1,(int)uVar2);
    FastExitMediaState();
    return;
  }
  if ((uVar10 >> 0x27 & 1) != 0) {
    uVar2 = PackedFloatingADD(uVar1,0xbf8000003f800000);
    uVar3 = PackedFloatingReciprocalSQRAprox(uVar8,uVar2);
    uVar5 = PackedFloatingMUL(uVar3,uVar3);
    uVar1 = CONCAT44((int)uVar2,(int)uVar2);
    uVar2 = PackedFloatingReciprocalSQRIter1(uVar5,uVar1);
    uVar3 = PackedFloatingReciprocalIter2(uVar2,uVar3);
    uVar2 = PackedFloatingADD(CONCAT44(uVar6,uVar6),(ulonglong)*(uint *)(param_2 + 2));
    uVar5 = PackedFloatingMUL(uVar3,0x3f0000003f000000);
    uVar3 = PackedFloatingADD(CONCAT44(uVar9,*(undefined4 *)(param_2 + 3)),
                              CONCAT44(*(undefined4 *)(param_2 + 1),uVar11) ^ 0x8000000000000000);
    uVar2 = PackedFloatingMUL(uVar2,uVar5);
    uVar1 = PackedFloatingMUL(uVar1,uVar5);
    uVar3 = PackedFloatingMUL(uVar3,uVar5);
    param_1[1] = uVar3;
    *param_1 = CONCAT44((int)uVar1,(int)uVar2);
    FastExitMediaState();
    return;
  }
  uVar3 = PackedFloatingADD(uVar3,0xbf8000003f800000);
  uVar2 = PackedFloatingReciprocalSQRAprox(uVar1,uVar3);
  uVar1 = PackedFloatingMUL(uVar2,uVar2);
  uVar3 = CONCAT44((int)uVar3,(int)uVar3);
  uVar1 = PackedFloatingReciprocalSQRIter1(uVar1,uVar3);
  uVar1 = PackedFloatingReciprocalIter2(uVar1,uVar2);
  uVar2 = PackedFloatingSUB(CONCAT44(uVar6,uVar6),(ulonglong)*(uint *)(param_2 + 2));
  uVar5 = PackedFloatingADD(CONCAT44(*(undefined4 *)(param_2 + 3),uVar9),
                            CONCAT44(uVar11,*(undefined4 *)(param_2 + 1)));
  uVar1 = PackedFloatingMUL(uVar1,0x3f0000003f000000);
  uVar3 = PackedFloatingMUL(uVar3,uVar1);
  uVar2 = PackedFloatingMUL(uVar2,uVar1);
  uVar1 = PackedFloatingMUL(uVar5,uVar1);
  *param_1 = uVar1;
  param_1[1] = CONCAT44((int)uVar2,(int)uVar3);
  FastExitMediaState();
  return;
}


// ==== 0x5ef227 FUN_005ef227

void FUN_005ef227(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 uVar7;
  undefined8 uVar6;
  undefined8 uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  
  FastExitMediaState();
  PackedFloatingMUL(0x3f0000003f000000,param_3);
  PackedFloatingMUL(0x3f0000003f000000,param_2);
  uVar2 = FUN_0061bee0();
  uVar3 = FUN_0061bee0();
  uVar4 = FUN_0061bee0();
  uVar1 = (undefined4)uVar4;
  uVar7 = (undefined4)((ulonglong)uVar4 >> 0x20);
  uVar4 = CONCAT44((int)uVar3,(int)uVar3);
  uVar9 = (undefined4)((ulonglong)uVar3 >> 0x20);
  uVar8 = CONCAT44(uVar9,uVar9);
  uVar3 = PackedFloatingMUL(CONCAT44(uVar1,uVar1) ^ 0x8000000000000000,uVar8);
  uVar5 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),uVar4);
  uVar6 = PackedFloatingMUL(CONCAT44(uVar7,uVar7),uVar4);
  uVar8 = PackedFloatingMUL(CONCAT44(uVar7,uVar7) ^ 0x80000000,uVar8);
  uVar10 = CONCAT44((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  uVar3 = PackedFloatingMUL(uVar3,uVar2);
  uVar4 = PackedFloatingMUL(uVar5,uVar10);
  uVar5 = PackedFloatingMUL(uVar6,uVar10);
  uVar6 = PackedFloatingMUL(uVar8,uVar2);
  uVar2 = PackedFloatingADD(uVar3,uVar5);
  uVar3 = PackedFloatingADD(uVar4,uVar6);
  *param_1 = uVar2;
  param_1[1] = uVar3;
  FastExitMediaState();
  return;
}


// ==== 0x5ef2ec FUN_005ef2ec

void FUN_005ef2ec(undefined8 *param_1,undefined4 param_2,uint param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined8 local_18;
  uint local_10;
  
  FastExitMediaState();
  FUN_005f401f(&local_18,param_2);
  PackedFloatingMUL((ulonglong)param_3,0x3f0000003f000000);
  uVar1 = FUN_0061bee0();
  uVar4 = (undefined4)((ulonglong)uVar1 >> 0x20);
  uVar3 = CONCAT44(uVar4,uVar4);
  uVar2 = PackedFloatingMUL(local_18,uVar3);
  uVar3 = PackedFloatingMUL((ulonglong)local_10,uVar3);
  *param_1 = uVar2;
  param_1[1] = CONCAT44((int)uVar1,(int)uVar3);
  FastExitMediaState();
  return;
}


// ==== 0x5ef358 FUN_005ef358

void FUN_005ef358(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  uint uVar10;
  uint uVar11;
  
  FastExitMediaState();
  uVar3 = PackedFloatingMUL(*param_2,*param_3);
  uVar5 = PackedFloatingMUL(param_2[1],param_3[1]);
  uVar5 = PackedFloatingADD(uVar3,uVar5);
  uVar3 = PackedFloatingSUB(0x3f800000,(ulonglong)param_4);
  uVar1 = (uint)uVar3;
  uVar4 = PackedFloatingAccumulate(uVar5,uVar5);
  uVar8 = PackedFloatingCompareGE(0,uVar4);
  uVar9 = uVar8 & 0x8000000080000000;
  uVar4 = uVar4 ^ uVar9;
  uVar5 = PackedFloatingCompareGE(0x3f7fff583f7fff58,uVar4);
  uVar3 = PackedFloatingMUL(uVar4,uVar4);
  uVar3 = PackedFloatingSUBR(uVar3,0x3f8000003f800000);
  if ((int)uVar5 != 0) {
    uVar6 = PackedFloatingReciprocalSQRAprox((ulonglong)param_4,uVar3);
    uVar5 = PackedFloatingMUL(uVar6,uVar6);
    uVar3 = PackedFloatingReciprocalSQRIter1(uVar3,uVar5);
    uVar6 = PackedFloatingReciprocalIter2(uVar3,uVar6);
    uVar3 = FloatingReciprocalAprox(uVar5,uVar6);
    uVar5 = PackedFloatingReciprocalIter1(uVar6,uVar3);
    PackedFloatingReciprocalIter2(uVar5,uVar3);
    uVar10 = (uint)uVar6;
    uVar3 = FUN_0061b800();
    uVar11 = (uint)uVar3;
    PackedFloatingMUL(uVar3,(ulonglong)param_4);
    uVar2 = FUN_0061bfe0(uVar1,uVar10,uVar11);
    PackedFloatingMUL((ulonglong)uVar11,(ulonglong)uVar1);
    uVar3 = FUN_0061bfe0();
    uVar9 = uVar8 & 0x80000000;
    uVar3 = PackedFloatingMUL(uVar3,(ulonglong)uVar10);
    uVar1 = (uint)uVar3;
    uVar3 = PackedFloatingMUL((ulonglong)uVar2,(ulonglong)uVar10);
    param_4 = (uint)uVar3;
  }
  param_4 = param_4 ^ (uint)uVar9;
  uVar5 = CONCAT44(param_4,param_4);
  uVar3 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),*param_2);
  uVar6 = PackedFloatingMUL(uVar5,*param_3);
  uVar7 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),param_2[1]);
  uVar5 = PackedFloatingMUL(uVar5,param_3[1]);
  uVar3 = PackedFloatingADD(uVar3,uVar6);
  uVar5 = PackedFloatingADD(uVar7,uVar5);
  *param_1 = uVar3;
  param_1[1] = uVar5;
  FastExitMediaState();
  return;
}


// ==== 0x5ef48f FUN_005ef48f

undefined4
FUN_005ef48f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            uint param_5,uint param_6)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined8 in_MM2;
  undefined8 uVar3;
  undefined1 local_28 [16];
  undefined1 local_18 [20];
  
  FastExitMediaState();
  uVar1 = PackedFloatingADD((ulonglong)param_5,(ulonglong)param_6);
  FUN_005ef358(local_28,param_2,param_3,(int)uVar1);
  FUN_005ef358(local_18,param_2,param_4,(int)uVar1);
  uVar3 = FloatingReciprocalAprox(in_MM2,uVar1 & 0xffffffff);
  uVar2 = PackedFloatingReciprocalIter1(uVar1 & 0xffffffff,uVar3);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar3);
  uVar2 = PackedFloatingMUL(uVar2,(ulonglong)param_6);
  FUN_005ef358(param_1,local_28,local_18,(int)uVar2);
  FastExitMediaState();
  return param_1;
}


// ==== 0x5ef51c FUN_005ef51c

void FUN_005ef51c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,uint param_6)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  FUN_005ef358(local_20,param_2,param_5,param_6);
  FUN_005ef358(local_10,param_3,param_4,param_6);
  uVar1 = (ulonglong)param_6;
  uVar2 = PackedFloatingMUL(uVar1,uVar1);
  uVar2 = PackedFloatingSUB(uVar1,uVar2);
  uVar2 = PackedFloatingMUL(uVar2,0x4000000040000000);
  FUN_005ef358(param_1,local_20,local_10,(int)uVar2);
  FastExitMediaState();
  return;
}


// ==== 0x5ef5ae FUN_005ef5ae

void FUN_005ef5ae(undefined8 *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 in_MM4;
  ulonglong uVar5;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  uVar3 = PackedFloatingMUL(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar2,uVar2);
  uVar3 = PackedFloatingADD(uVar3,uVar4);
  uVar3 = PackedFloatingAccumulate(uVar3,uVar3);
  uVar4 = FloatingReciprocalAprox(in_MM4,uVar3);
  uVar5 = PackedFloatingCompareGT(uVar3,0x80000000800000);
  uVar3 = PackedFloatingReciprocalIter1(uVar3,uVar4);
  uVar3 = PackedFloatingReciprocalIter2(uVar3,uVar4);
  uVar4 = PackedFloatingMUL((uVar1 ^ 0x8000000080000000) & uVar5,uVar3);
  uVar3 = PackedFloatingMUL((uVar2 ^ 0x80000000) & uVar5,uVar3);
  *param_1 = uVar4;
  param_1[1] = uVar3;
  FastExitMediaState();
  return;
}


// ==== 0x5ef612 FUN_005ef612

void FUN_005ef612(undefined8 *param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 in_MM4;
  undefined8 uVar6;
  
  FastExitMediaState();
  uVar3 = *param_2;
  uVar4 = param_2[1];
  uVar1 = (undefined4)(uVar4 >> 0x20);
  uVar5 = PackedFloatingCompareGE(CONCAT44(uVar1,uVar1),0x3f8000003f800000);
  if ((int)uVar5 == 0) {
    uVar1 = FUN_0061b900();
    uVar2 = FUN_0061bfe0();
    uVar5 = PackedFloatingCompareGE(uVar2 & 0x7fffffff7fffffff,0x3400000034000000);
    uVar3 = *param_2;
    uVar4 = param_2[1];
    if ((int)uVar5 != 0) {
      uVar6 = FloatingReciprocalAprox(in_MM4,uVar2);
      uVar5 = PackedFloatingReciprocalIter1(uVar2,uVar6);
      uVar5 = PackedFloatingReciprocalIter2(uVar5,uVar6);
      uVar5 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),uVar5);
      uVar3 = PackedFloatingMUL(uVar3,uVar5);
      uVar4 = PackedFloatingMUL(uVar4,uVar5);
    }
  }
  *param_1 = uVar3;
  param_1[1] = uVar4 & 0xffffffff;
  FastExitMediaState();
  return;
}


// ==== 0x5ef6b9 FUN_005ef6b9

void FUN_005ef6b9(undefined8 *param_1,undefined8 *param_2)

{
  undefined4 unaff_ESI;
  undefined8 uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  uint uVar7;
  
  uVar1 = PackedFloatingMUL(*param_2,*param_2);
  uVar4 = PackedFloatingMUL((ulonglong)*(uint *)(param_2 + 1),(ulonglong)*(uint *)(param_2 + 1));
  uVar1 = PackedFloatingADD(uVar1,uVar4);
  uVar1 = PackedFloatingAccumulate(uVar1,uVar1);
  uVar4 = PackedFloatingReciprocalSQRAprox(uVar4,uVar1);
  uVar5 = PackedFloatingMUL(uVar4,uVar4);
  uVar5 = PackedFloatingReciprocalSQRIter1(uVar5,uVar1);
  uVar4 = PackedFloatingReciprocalIter2(uVar5,uVar4);
  PackedFloatingMUL(uVar1,uVar4);
  uVar2 = FUN_0061bee0();
  uVar3 = PackedFloatingCompareGE(uVar2 & 0x7fffffffffffffff,0x3400000034000000);
  uVar1 = *param_2;
  uVar6 = (undefined4)(uVar2 >> 0x20);
  uVar4 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),CONCAT44(unaff_ESI,(int)uVar4));
  uVar7 = *(uint *)(param_2 + 1);
  if ((uVar3 & 0x100000000) != 0) {
    uVar4 = CONCAT44((int)uVar4,(int)uVar4);
    uVar5 = PackedFloatingMUL((ulonglong)uVar7,uVar4);
    uVar7 = (uint)uVar5;
    uVar1 = PackedFloatingMUL(uVar1,uVar4);
  }
  *param_1 = uVar1;
  param_1[1] = CONCAT44((int)uVar2,uVar7);
  FastExitMediaState();
  return;
}


// ==== 0x5ef75e FUN_005ef75e

void FUN_005ef75e(undefined8 *param_1,undefined8 *param_2,ulonglong *param_3,ulonglong *param_4,
                 ulonglong *param_5,ulonglong *param_6,ulonglong *param_7)

{
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  undefined8 uVar15;
  ulonglong local_a8;
  ulonglong local_a0;
  ulonglong local_88;
  ulonglong local_80;
  ulonglong local_78;
  ulonglong local_70;
  undefined4 local_20;
  
  local_a8 = *param_4;
  local_a0 = param_4[1];
  uVar8 = *param_5;
  uVar14 = param_5[1];
  uVar2 = PackedFloatingADD(local_a8,uVar8);
  uVar4 = PackedFloatingADD(local_a0,uVar14);
  uVar6 = PackedFloatingSUB(local_a8,uVar8);
  uVar2 = PackedFloatingMUL(uVar2,uVar2);
  uVar9 = PackedFloatingSUB(local_a0,uVar14);
  uVar4 = PackedFloatingMUL(uVar4,uVar4);
  uVar6 = PackedFloatingMUL(uVar6,uVar6);
  uVar9 = PackedFloatingMUL(uVar9,uVar9);
  uVar2 = PackedFloatingADD(uVar2,uVar4);
  uVar6 = PackedFloatingADD(uVar6,uVar9);
  local_88 = *param_6;
  local_80 = param_6[1];
  uVar11 = PackedFloatingADD(uVar8,local_88);
  uVar12 = PackedFloatingADD(uVar14,local_80);
  uVar4 = PackedFloatingSUB(uVar8,local_88);
  uVar9 = PackedFloatingSUB(uVar14,local_80);
  uVar11 = PackedFloatingMUL(uVar11,uVar11);
  uVar12 = PackedFloatingMUL(uVar12,uVar12);
  uVar4 = PackedFloatingMUL(uVar4,uVar4);
  uVar9 = PackedFloatingMUL(uVar9,uVar9);
  uVar11 = PackedFloatingADD(uVar11,uVar12);
  uVar4 = PackedFloatingADD(uVar4,uVar9);
  uVar2 = PackedFloatingAccumulate(uVar2,uVar11);
  uVar4 = PackedFloatingAccumulate(uVar6,uVar4);
  uVar2 = PackedFloatingCompareGT(uVar4,uVar2);
  uVar7 = packsswb(uVar2,uVar2);
  if ((uVar7 & 1) != 0) {
    local_a8 = *param_4 ^ 0x8000000080000000;
    local_a0 = param_4[1] ^ 0x8000000080000000;
  }
  if ((uVar7 & 0x10000) != 0) {
    local_88 = *param_6 ^ 0x8000000080000000;
    local_80 = param_6[1] ^ 0x8000000080000000;
  }
  local_78 = *param_7;
  uVar7 = param_7[1];
  uVar6 = PackedFloatingADD(local_88,local_78);
  uVar9 = PackedFloatingADD(local_80,uVar7);
  uVar2 = PackedFloatingSUB(local_88,local_78);
  uVar4 = PackedFloatingSUB(local_80,uVar7);
  uVar6 = PackedFloatingMUL(uVar6,uVar6);
  uVar9 = PackedFloatingMUL(uVar9,uVar9);
  uVar2 = PackedFloatingMUL(uVar2,uVar2);
  uVar4 = PackedFloatingMUL(uVar4,uVar4);
  uVar6 = PackedFloatingADD(uVar6,uVar9);
  uVar2 = PackedFloatingADD(uVar2,uVar4);
  uVar4 = PackedFloatingAccumulate(uVar6,uVar6);
  uVar2 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar10 = PackedFloatingCompareGT(uVar2,uVar4);
  local_70 = uVar7;
  if ((uVar10 & 1) != 0) {
    local_78 = *param_7 ^ 0x8000000080000000;
    local_70 = param_7[1] ^ 0x8000000080000000;
  }
  uVar2 = PackedFloatingMUL(uVar8,uVar8);
  uVar4 = PackedFloatingMUL(uVar14,uVar14);
  uVar2 = PackedFloatingADD(uVar2,uVar4);
  uVar2 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar4 = FloatingReciprocalAprox(uVar7,uVar2);
  uVar7 = PackedFloatingCompareGT(uVar2,0x80000000800000);
  uVar2 = PackedFloatingReciprocalIter1(uVar2,uVar4);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar4);
  uVar4 = PackedFloatingMUL((uVar8 ^ 0x8000000080000000) & uVar7,uVar2);
  uVar11 = PackedFloatingMUL((uVar14 ^ 0x80000000) & uVar7,uVar2);
  uVar10 = CONCAT44((int)local_a8,(int)(local_a8 >> 0x20));
  uVar3 = CONCAT44((int)local_a0,(int)(local_a0 >> 0x20));
  uVar7 = PackedFloatingMUL(local_a8,uVar11);
  uVar2 = PackedFloatingMUL(local_a0,uVar4);
  uVar9 = PackedFloatingMUL(uVar3 ^ 0x80000000,uVar4);
  uVar6 = PackedFloatingMUL(uVar10,uVar11);
  uVar2 = PackedFloatingADD(uVar7 ^ 0x80000000,uVar2);
  uVar6 = PackedFloatingSUB(uVar6,uVar9);
  uVar15 = PackedFloatingMUL(uVar3,uVar11);
  uVar6 = PackedFloatingAccumulate(uVar6,uVar2);
  uVar12 = PackedFloatingMUL(uVar10 ^ 0x80000000,uVar4);
  uVar2 = PackedFloatingMUL(local_a8,uVar4);
  uVar9 = PackedFloatingMUL(local_a0 ^ 0x80000000,uVar11);
  uVar12 = PackedFloatingADD(uVar12,uVar15);
  uVar2 = PackedFloatingSUB(uVar9,uVar2);
  uVar10 = PackedFloatingAccumulate(uVar12,uVar2);
  uVar3 = CONCAT44((int)local_88,(int)(local_88 >> 0x20));
  uVar13 = CONCAT44((int)local_80,(int)(local_80 >> 0x20));
  uVar7 = PackedFloatingMUL(local_88,uVar11);
  uVar2 = PackedFloatingMUL(local_80,uVar4);
  uVar12 = PackedFloatingMUL(uVar13 ^ 0x80000000,uVar4);
  uVar9 = PackedFloatingMUL(uVar3,uVar11);
  uVar2 = PackedFloatingADD(uVar7 ^ 0x80000000,uVar2);
  uVar9 = PackedFloatingSUB(uVar9,uVar12);
  uVar15 = PackedFloatingMUL(uVar13,uVar11);
  uVar9 = PackedFloatingAccumulate(uVar9,uVar2);
  uVar12 = PackedFloatingMUL(uVar3 ^ 0x80000000,uVar4);
  uVar2 = PackedFloatingMUL(local_88,uVar4);
  uVar4 = PackedFloatingMUL(local_80 ^ 0x80000000,uVar11);
  uVar11 = PackedFloatingADD(uVar12,uVar15);
  uVar2 = PackedFloatingSUB(uVar4,uVar2);
  uVar7 = PackedFloatingAccumulate(uVar11,uVar2);
  uVar1 = (undefined4)(uVar10 >> 0x20);
  uVar4 = PackedFloatingCompareGE(CONCAT44(uVar1,uVar1),0x3f8000003f800000);
  uVar2 = uVar9;
  if ((int)uVar4 == 0) {
    uVar1 = FUN_0061b900();
    uVar3 = FUN_0061bfe0();
    uVar4 = PackedFloatingCompareGE(uVar3 & 0x7fffffff7fffffff,0x3400000034000000);
    if ((int)uVar4 != 0) {
      uVar2 = FloatingReciprocalAprox(uVar2,uVar3);
      uVar4 = PackedFloatingReciprocalIter1(uVar3,uVar2);
      uVar4 = PackedFloatingReciprocalIter2(uVar4,uVar2);
      uVar4 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),uVar4);
      uVar6 = PackedFloatingMUL(uVar6,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,uVar4);
    }
  }
  uVar1 = (undefined4)(uVar7 >> 0x20);
  uVar4 = PackedFloatingCompareGE(CONCAT44(uVar1,uVar1),0x3f8000003f800000);
  if ((int)uVar4 == 0) {
    uVar1 = FUN_0061b900();
    uVar3 = FUN_0061bfe0(uVar1,unaff_ESI,unaff_EBX);
    uVar4 = PackedFloatingCompareGE(uVar3 & 0x7fffffff7fffffff,0x3400000034000000);
    if ((int)uVar4 != 0) {
      uVar4 = FloatingReciprocalAprox(uVar2,uVar3);
      uVar2 = PackedFloatingReciprocalIter1(uVar3,uVar4);
      uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar4);
      uVar2 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),uVar2);
      uVar9 = PackedFloatingMUL(uVar9,uVar2);
      uVar7 = PackedFloatingMUL(uVar7,uVar2);
    }
  }
  uVar2 = PackedFloatingADD(uVar6,uVar9);
  uVar4 = PackedFloatingADD(uVar10 & 0xffffffff,uVar7 & 0xffffffff);
  uVar2 = PackedFloatingMUL(uVar2,0xbe800000be800000);
  uVar3 = PackedFloatingMUL(uVar4,0xbe800000be800000);
  uVar4 = PackedFloatingMUL(uVar2,uVar2);
  uVar6 = PackedFloatingMUL(uVar3 & 0xffffffff,uVar3 & 0xffffffff);
  uVar4 = PackedFloatingADD(uVar4,uVar6);
  uVar4 = PackedFloatingAccumulate(uVar4,uVar4);
  uVar6 = PackedFloatingReciprocalSQRAprox(uVar6,uVar4);
  uVar9 = PackedFloatingMUL(uVar6,uVar6);
  uVar9 = PackedFloatingReciprocalSQRIter1(uVar9,uVar4);
  uVar6 = PackedFloatingReciprocalIter2(uVar9,uVar6);
  uVar1 = (undefined4)uVar6;
  PackedFloatingMUL(uVar4,uVar6);
  uVar7 = FUN_0061bee0(uVar1,unaff_ESI,unaff_EBX);
  uVar10 = PackedFloatingCompareGE(uVar7 & 0x7fffffffffffffff,0x3400000034000000);
  uVar5 = (undefined4)(uVar7 >> 0x20);
  uVar4 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),CONCAT44(unaff_ESI,uVar1));
  local_20 = (undefined4)uVar3;
  if ((uVar10 & 0x100000000) != 0) {
    uVar4 = CONCAT44((int)uVar4,(int)uVar4);
    uVar6 = PackedFloatingMUL(uVar3 & 0xffffffff,uVar4);
    local_20 = (undefined4)uVar6;
    uVar2 = PackedFloatingMUL(uVar2,uVar4);
  }
  uVar10 = CONCAT44((int)uVar7,local_20);
  uVar3 = CONCAT44((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  uVar13 = CONCAT44(local_20,(int)uVar7);
  uVar7 = PackedFloatingMUL(uVar2,uVar14);
  uVar4 = PackedFloatingMUL(uVar10,uVar8);
  uVar9 = PackedFloatingMUL(uVar13 ^ 0x80000000,uVar8);
  uVar6 = PackedFloatingMUL(uVar3,uVar14);
  uVar4 = PackedFloatingADD(uVar7 ^ 0x80000000,uVar4);
  uVar6 = PackedFloatingSUB(uVar6,uVar9);
  uVar11 = PackedFloatingMUL(uVar13,uVar14);
  uVar6 = PackedFloatingAccumulate(uVar6,uVar4);
  uVar9 = PackedFloatingMUL(uVar3 ^ 0x80000000,uVar8);
  uVar2 = PackedFloatingMUL(uVar2,uVar8);
  *param_1 = uVar6;
  uVar4 = PackedFloatingMUL(uVar10 ^ 0x80000000,uVar14);
  uVar9 = PackedFloatingADD(uVar9,uVar11);
  uVar2 = PackedFloatingSUB(uVar4,uVar2);
  uVar2 = PackedFloatingAccumulate(uVar9,uVar2);
  param_1[1] = uVar2;
  uVar2 = PackedFloatingMUL(local_88,local_88);
  uVar4 = PackedFloatingMUL(local_80,local_80);
  uVar2 = PackedFloatingADD(uVar2,uVar4);
  uVar2 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar4 = FloatingReciprocalAprox(uVar6,uVar2);
  uVar7 = PackedFloatingCompareGT(uVar2,0x80000000800000);
  uVar2 = PackedFloatingReciprocalIter1(uVar2,uVar4);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar4);
  uVar4 = PackedFloatingMUL((local_88 ^ 0x8000000080000000) & uVar7,uVar2);
  uVar11 = PackedFloatingMUL((local_80 ^ 0x80000000) & uVar7,uVar2);
  uVar10 = CONCAT44((int)uVar8,(int)(uVar8 >> 0x20));
  uVar3 = CONCAT44((int)uVar14,(int)(uVar14 >> 0x20));
  uVar7 = PackedFloatingMUL(uVar8,uVar11);
  uVar2 = PackedFloatingMUL(uVar14,uVar4);
  uVar9 = PackedFloatingMUL(uVar3 ^ 0x80000000,uVar4);
  uVar6 = PackedFloatingMUL(uVar10,uVar11);
  uVar2 = PackedFloatingADD(uVar7 ^ 0x80000000,uVar2);
  uVar6 = PackedFloatingSUB(uVar6,uVar9);
  uVar15 = PackedFloatingMUL(uVar3,uVar11);
  uVar6 = PackedFloatingAccumulate(uVar6,uVar2);
  uVar12 = PackedFloatingMUL(uVar10 ^ 0x80000000,uVar4);
  uVar2 = PackedFloatingMUL(uVar8,uVar4);
  uVar9 = PackedFloatingMUL(uVar14 ^ 0x80000000,uVar11);
  uVar12 = PackedFloatingADD(uVar12,uVar15);
  uVar2 = PackedFloatingSUB(uVar9,uVar2);
  uVar14 = PackedFloatingAccumulate(uVar12,uVar2);
  uVar7 = CONCAT44((int)local_78,(int)(local_78 >> 0x20));
  uVar10 = CONCAT44((int)local_70,(int)(local_70 >> 0x20));
  uVar8 = PackedFloatingMUL(local_78,uVar11);
  uVar2 = PackedFloatingMUL(local_70,uVar4);
  uVar12 = PackedFloatingMUL(uVar10 ^ 0x80000000,uVar4);
  uVar9 = PackedFloatingMUL(uVar7,uVar11);
  uVar2 = PackedFloatingADD(uVar8 ^ 0x80000000,uVar2);
  uVar9 = PackedFloatingSUB(uVar9,uVar12);
  uVar15 = PackedFloatingMUL(uVar10,uVar11);
  uVar9 = PackedFloatingAccumulate(uVar9,uVar2);
  uVar12 = PackedFloatingMUL(uVar7 ^ 0x80000000,uVar4);
  uVar2 = PackedFloatingMUL(local_78,uVar4);
  uVar4 = PackedFloatingMUL(local_70 ^ 0x80000000,uVar11);
  uVar11 = PackedFloatingADD(uVar12,uVar15);
  uVar2 = PackedFloatingSUB(uVar4,uVar2);
  uVar8 = PackedFloatingAccumulate(uVar11,uVar2);
  uVar1 = (undefined4)(uVar14 >> 0x20);
  uVar4 = PackedFloatingCompareGE(CONCAT44(uVar1,uVar1),0x3f8000003f800000);
  uVar2 = uVar9;
  if ((int)uVar4 == 0) {
    uVar1 = FUN_0061b900();
    uVar7 = FUN_0061bfe0(uVar1,unaff_ESI,unaff_EBX);
    uVar4 = PackedFloatingCompareGE(uVar7 & 0x7fffffff7fffffff,0x3400000034000000);
    if ((int)uVar4 != 0) {
      uVar2 = FloatingReciprocalAprox(uVar2,uVar7);
      uVar4 = PackedFloatingReciprocalIter1(uVar7,uVar2);
      uVar4 = PackedFloatingReciprocalIter2(uVar4,uVar2);
      uVar4 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),uVar4);
      uVar6 = PackedFloatingMUL(uVar6,uVar4);
      uVar14 = PackedFloatingMUL(uVar14,uVar4);
    }
  }
  uVar1 = (undefined4)(uVar8 >> 0x20);
  uVar4 = PackedFloatingCompareGE(CONCAT44(uVar1,uVar1),0x3f8000003f800000);
  if ((int)uVar4 == 0) {
    uVar1 = FUN_0061b900();
    uVar7 = FUN_0061bfe0(uVar1,unaff_ESI,unaff_EBX);
    uVar4 = PackedFloatingCompareGE(uVar7 & 0x7fffffff7fffffff,0x3400000034000000);
    if ((int)uVar4 != 0) {
      uVar4 = FloatingReciprocalAprox(uVar2,uVar7);
      uVar2 = PackedFloatingReciprocalIter1(uVar7,uVar4);
      uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar4);
      uVar2 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),uVar2);
      uVar9 = PackedFloatingMUL(uVar9,uVar2);
      uVar8 = PackedFloatingMUL(uVar8,uVar2);
    }
  }
  uVar2 = PackedFloatingADD(uVar6,uVar9);
  uVar4 = PackedFloatingADD(uVar14 & 0xffffffff,uVar8 & 0xffffffff);
  uVar2 = PackedFloatingMUL(uVar2,0xbe800000be800000);
  uVar7 = PackedFloatingMUL(uVar4,0xbe800000be800000);
  uVar4 = PackedFloatingMUL(uVar2,uVar2);
  uVar6 = PackedFloatingMUL(uVar7 & 0xffffffff,uVar7 & 0xffffffff);
  uVar4 = PackedFloatingADD(uVar4,uVar6);
  uVar4 = PackedFloatingAccumulate(uVar4,uVar4);
  uVar6 = PackedFloatingReciprocalSQRAprox(uVar6,uVar4);
  uVar9 = PackedFloatingMUL(uVar6,uVar6);
  uVar9 = PackedFloatingReciprocalSQRIter1(uVar9,uVar4);
  uVar6 = PackedFloatingReciprocalIter2(uVar9,uVar6);
  uVar1 = (undefined4)uVar6;
  PackedFloatingMUL(uVar4,uVar6);
  uVar8 = FUN_0061bee0(uVar1,unaff_ESI,unaff_EBX);
  uVar14 = PackedFloatingCompareGE(uVar8 & 0x7fffffffffffffff,0x3400000034000000);
  uVar5 = (undefined4)(uVar8 >> 0x20);
  uVar4 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),CONCAT44(unaff_ESI,uVar1));
  local_20 = (undefined4)uVar7;
  if ((uVar14 & 0x100000000) != 0) {
    uVar4 = CONCAT44((int)uVar4,(int)uVar4);
    uVar6 = PackedFloatingMUL(uVar7 & 0xffffffff,uVar4);
    local_20 = (undefined4)uVar6;
    uVar2 = PackedFloatingMUL(uVar2,uVar4);
  }
  uVar14 = CONCAT44((int)uVar8,local_20);
  uVar7 = CONCAT44((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  uVar10 = CONCAT44(local_20,(int)uVar8);
  uVar8 = PackedFloatingMUL(uVar2,local_80);
  uVar4 = PackedFloatingMUL(uVar14,local_88);
  uVar9 = PackedFloatingMUL(uVar10 ^ 0x80000000,local_88);
  uVar6 = PackedFloatingMUL(uVar7,local_80);
  uVar4 = PackedFloatingADD(uVar8 ^ 0x80000000,uVar4);
  uVar6 = PackedFloatingSUB(uVar6,uVar9);
  uVar9 = PackedFloatingMUL(uVar10,local_80);
  uVar4 = PackedFloatingAccumulate(uVar6,uVar4);
  uVar6 = PackedFloatingMUL(uVar7 ^ 0x80000000,local_88);
  uVar2 = PackedFloatingMUL(uVar2,local_88);
  *param_2 = uVar4;
  uVar4 = PackedFloatingMUL(uVar14 ^ 0x80000000,local_80);
  uVar6 = PackedFloatingADD(uVar6,uVar9);
  uVar2 = PackedFloatingSUB(uVar4,uVar2);
  uVar2 = PackedFloatingAccumulate(uVar6,uVar2);
  param_2[1] = uVar2;
  *param_3 = local_88;
  param_3[1] = local_80;
  FastExitMediaState();
  return;
}


// ==== 0x5f0197 FUN_005f0197

void FUN_005f0197(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  
  FastExitMediaState();
  uVar3 = CONCAT44((int)param_3[2],(int)*param_3);
  uVar11 = CONCAT44((int)((ulonglong)param_3[2] >> 0x20),(int)((ulonglong)*param_3 >> 0x20));
  uVar7 = CONCAT44((int)param_3[7],(int)param_3[5]);
  uVar12 = CONCAT44((int)((ulonglong)param_3[7] >> 0x20),(int)((ulonglong)param_3[5] >> 0x20));
  uVar15 = CONCAT44((int)param_3[3],(int)param_3[1]);
  uVar17 = CONCAT44((int)((ulonglong)param_3[3] >> 0x20),(int)((ulonglong)param_3[1] >> 0x20));
  uVar9 = CONCAT44((int)((ulonglong)param_3[6] >> 0x20),(int)((ulonglong)param_3[4] >> 0x20));
  uVar14 = CONCAT44((int)param_3[6],(int)param_3[4]);
  uVar2 = *param_2;
  uVar5 = param_2[1];
  uVar1 = PackedFloatingMUL(uVar2,uVar3);
  uVar4 = PackedFloatingMUL(uVar5,uVar14);
  uVar6 = PackedFloatingMUL(uVar2,uVar11);
  uVar8 = PackedFloatingMUL(uVar5,uVar9);
  uVar10 = PackedFloatingMUL(uVar2,uVar15);
  uVar13 = PackedFloatingMUL(uVar5,uVar7);
  uVar16 = PackedFloatingMUL(uVar2,uVar17);
  uVar18 = PackedFloatingMUL(uVar5,uVar12);
  uVar2 = PackedFloatingAccumulate(uVar1,uVar6);
  uVar5 = PackedFloatingAccumulate(uVar4,uVar8);
  uVar1 = PackedFloatingAccumulate(uVar10,uVar16);
  uVar4 = PackedFloatingAccumulate(uVar13,uVar18);
  uVar2 = PackedFloatingADD(uVar2,uVar5);
  uVar5 = PackedFloatingADD(uVar1,uVar4);
  *param_1 = uVar2;
  param_1[1] = uVar5;
  uVar2 = param_2[2];
  uVar5 = param_2[3];
  uVar1 = PackedFloatingMUL(uVar2,uVar3);
  uVar4 = PackedFloatingMUL(uVar5,uVar14);
  uVar6 = PackedFloatingMUL(uVar2,uVar11);
  uVar8 = PackedFloatingMUL(uVar5,uVar9);
  uVar10 = PackedFloatingMUL(uVar2,uVar15);
  uVar13 = PackedFloatingMUL(uVar5,uVar7);
  uVar16 = PackedFloatingMUL(uVar2,uVar17);
  uVar18 = PackedFloatingMUL(uVar5,uVar12);
  uVar2 = PackedFloatingAccumulate(uVar1,uVar6);
  uVar5 = PackedFloatingAccumulate(uVar4,uVar8);
  uVar1 = PackedFloatingAccumulate(uVar10,uVar16);
  uVar4 = PackedFloatingAccumulate(uVar13,uVar18);
  uVar2 = PackedFloatingADD(uVar2,uVar5);
  uVar5 = PackedFloatingADD(uVar1,uVar4);
  param_1[2] = uVar2;
  param_1[3] = uVar5;
  uVar2 = param_2[4];
  uVar5 = param_2[5];
  uVar1 = PackedFloatingMUL(uVar2,uVar3);
  uVar4 = PackedFloatingMUL(uVar5,uVar14);
  uVar6 = PackedFloatingMUL(uVar2,uVar11);
  uVar8 = PackedFloatingMUL(uVar5,uVar9);
  uVar10 = PackedFloatingMUL(uVar2,uVar15);
  uVar13 = PackedFloatingMUL(uVar5,uVar7);
  uVar16 = PackedFloatingMUL(uVar2,uVar17);
  uVar18 = PackedFloatingMUL(uVar5,uVar12);
  uVar2 = PackedFloatingAccumulate(uVar1,uVar6);
  uVar5 = PackedFloatingAccumulate(uVar4,uVar8);
  uVar1 = PackedFloatingAccumulate(uVar10,uVar16);
  uVar4 = PackedFloatingAccumulate(uVar13,uVar18);
  uVar2 = PackedFloatingADD(uVar2,uVar5);
  uVar5 = PackedFloatingADD(uVar1,uVar4);
  param_1[4] = uVar2;
  param_1[5] = uVar5;
  uVar2 = param_2[6];
  uVar5 = param_2[7];
  uVar3 = PackedFloatingMUL(uVar2,uVar3);
  uVar1 = PackedFloatingMUL(uVar5,uVar14);
  uVar4 = PackedFloatingMUL(uVar2,uVar11);
  uVar9 = PackedFloatingMUL(uVar5,uVar9);
  uVar11 = PackedFloatingMUL(uVar2,uVar15);
  uVar14 = PackedFloatingMUL(uVar5,uVar7);
  uVar17 = PackedFloatingMUL(uVar2,uVar17);
  uVar6 = PackedFloatingMUL(uVar5,uVar12);
  uVar2 = PackedFloatingAccumulate(uVar3,uVar4);
  uVar5 = PackedFloatingAccumulate(uVar1,uVar9);
  uVar3 = PackedFloatingAccumulate(uVar11,uVar17);
  uVar9 = PackedFloatingAccumulate(uVar14,uVar6);
  uVar2 = PackedFloatingADD(uVar2,uVar5);
  uVar5 = PackedFloatingADD(uVar3,uVar9);
  param_1[6] = uVar2;
  param_1[7] = uVar5;
  FastExitMediaState();
  return;
}


// ==== 0x5f01b8 FUN_005f01b8

void __fastcall FUN_005f01b8(undefined4 param_1,int param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int unaff_EBP;
  undefined8 in_MM0;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 in_MM1;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 in_MM3;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 in_MM4;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  
  uVar5 = CONCAT44((int)in_MM1,(int)in_MM0);
  uVar13 = CONCAT44((int)((ulonglong)in_MM1 >> 0x20),(int)((ulonglong)in_MM0 >> 0x20));
  uVar9 = CONCAT44((int)in_MM4,(int)in_MM3);
  uVar14 = CONCAT44((int)((ulonglong)in_MM4 >> 0x20),(int)((ulonglong)in_MM3 >> 0x20));
  puVar1 = *(undefined8 **)(unaff_EBP + 0x4c);
  uVar17 = CONCAT44((int)*(undefined8 *)(param_2 + 0x18),(int)*(undefined8 *)(param_2 + 8));
  uVar19 = CONCAT44((int)((ulonglong)*(undefined8 *)(param_2 + 0x18) >> 0x20),
                    (int)((ulonglong)*(undefined8 *)(param_2 + 8) >> 0x20));
  uVar11 = CONCAT44((int)((ulonglong)*(undefined8 *)(param_2 + 0x30) >> 0x20),
                    (int)((ulonglong)*(undefined8 *)(param_2 + 0x20) >> 0x20));
  uVar16 = CONCAT44((int)*(undefined8 *)(param_2 + 0x30),(int)*(undefined8 *)(param_2 + 0x20));
  puVar2 = *(undefined8 **)(unaff_EBP + 0x48);
  uVar4 = *puVar1;
  uVar7 = puVar1[1];
  uVar3 = PackedFloatingMUL(uVar4,uVar5);
  uVar6 = PackedFloatingMUL(uVar7,uVar16);
  uVar8 = PackedFloatingMUL(uVar4,uVar13);
  uVar10 = PackedFloatingMUL(uVar7,uVar11);
  uVar12 = PackedFloatingMUL(uVar4,uVar17);
  uVar15 = PackedFloatingMUL(uVar7,uVar9);
  uVar18 = PackedFloatingMUL(uVar4,uVar19);
  uVar20 = PackedFloatingMUL(uVar7,uVar14);
  uVar4 = PackedFloatingAccumulate(uVar3,uVar8);
  uVar7 = PackedFloatingAccumulate(uVar6,uVar10);
  uVar3 = PackedFloatingAccumulate(uVar12,uVar18);
  uVar6 = PackedFloatingAccumulate(uVar15,uVar20);
  uVar4 = PackedFloatingADD(uVar4,uVar7);
  uVar7 = PackedFloatingADD(uVar3,uVar6);
  *puVar2 = uVar4;
  puVar2[1] = uVar7;
  uVar4 = puVar1[2];
  uVar7 = puVar1[3];
  uVar3 = PackedFloatingMUL(uVar4,uVar5);
  uVar6 = PackedFloatingMUL(uVar7,uVar16);
  uVar8 = PackedFloatingMUL(uVar4,uVar13);
  uVar10 = PackedFloatingMUL(uVar7,uVar11);
  uVar12 = PackedFloatingMUL(uVar4,uVar17);
  uVar15 = PackedFloatingMUL(uVar7,uVar9);
  uVar18 = PackedFloatingMUL(uVar4,uVar19);
  uVar20 = PackedFloatingMUL(uVar7,uVar14);
  uVar4 = PackedFloatingAccumulate(uVar3,uVar8);
  uVar7 = PackedFloatingAccumulate(uVar6,uVar10);
  uVar3 = PackedFloatingAccumulate(uVar12,uVar18);
  uVar6 = PackedFloatingAccumulate(uVar15,uVar20);
  uVar4 = PackedFloatingADD(uVar4,uVar7);
  uVar7 = PackedFloatingADD(uVar3,uVar6);
  puVar2[2] = uVar4;
  puVar2[3] = uVar7;
  uVar4 = puVar1[4];
  uVar7 = puVar1[5];
  uVar3 = PackedFloatingMUL(uVar4,uVar5);
  uVar6 = PackedFloatingMUL(uVar7,uVar16);
  uVar8 = PackedFloatingMUL(uVar4,uVar13);
  uVar10 = PackedFloatingMUL(uVar7,uVar11);
  uVar12 = PackedFloatingMUL(uVar4,uVar17);
  uVar15 = PackedFloatingMUL(uVar7,uVar9);
  uVar18 = PackedFloatingMUL(uVar4,uVar19);
  uVar20 = PackedFloatingMUL(uVar7,uVar14);
  uVar4 = PackedFloatingAccumulate(uVar3,uVar8);
  uVar7 = PackedFloatingAccumulate(uVar6,uVar10);
  uVar3 = PackedFloatingAccumulate(uVar12,uVar18);
  uVar6 = PackedFloatingAccumulate(uVar15,uVar20);
  uVar4 = PackedFloatingADD(uVar4,uVar7);
  uVar7 = PackedFloatingADD(uVar3,uVar6);
  puVar2[4] = uVar4;
  puVar2[5] = uVar7;
  uVar4 = puVar1[6];
  uVar7 = puVar1[7];
  uVar5 = PackedFloatingMUL(uVar4,uVar5);
  uVar3 = PackedFloatingMUL(uVar7,uVar16);
  uVar6 = PackedFloatingMUL(uVar4,uVar13);
  uVar11 = PackedFloatingMUL(uVar7,uVar11);
  uVar13 = PackedFloatingMUL(uVar4,uVar17);
  uVar16 = PackedFloatingMUL(uVar7,uVar9);
  uVar19 = PackedFloatingMUL(uVar4,uVar19);
  uVar8 = PackedFloatingMUL(uVar7,uVar14);
  uVar4 = PackedFloatingAccumulate(uVar5,uVar6);
  uVar7 = PackedFloatingAccumulate(uVar3,uVar11);
  uVar5 = PackedFloatingAccumulate(uVar13,uVar19);
  uVar11 = PackedFloatingAccumulate(uVar16,uVar8);
  uVar4 = PackedFloatingADD(uVar4,uVar7);
  uVar7 = PackedFloatingADD(uVar5,uVar11);
  puVar2[6] = uVar4;
  puVar2[7] = uVar7;
  FastExitMediaState();
  return;
}


// ==== 0x5f03c9 FUN_005f03c9

float10 FUN_005f03c9(undefined4 *param_1)

{
  undefined4 uVar2;
  undefined8 uVar1;
  undefined8 uVar3;
  undefined4 uVar7;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar8;
  
  uVar2 = (undefined4)((ulonglong)*(undefined8 *)(param_1 + 10) >> 0x20);
  uVar7 = (undefined4)((ulonglong)*(undefined8 *)(param_1 + 0xe) >> 0x20);
  uVar4 = PackedFloatingMUL(CONCAT44(uVar7,uVar7),*(undefined8 *)(param_1 + 9));
  uVar1 = PackedFloatingMUL(CONCAT44(uVar2,uVar2),*(undefined8 *)(param_1 + 0xd));
  uVar5 = PackedFloatingSUB(uVar4,uVar1);
  uVar1 = PackedFloatingMUL(CONCAT44((int)*(undefined8 *)(param_1 + 8),
                                     (int)*(undefined8 *)(param_1 + 8)),
                            *(undefined8 *)(param_1 + 0xe));
  uVar4 = PackedFloatingMUL(CONCAT44((int)*(undefined8 *)(param_1 + 0xc),
                                     (int)*(undefined8 *)(param_1 + 0xc)),
                            *(undefined8 *)(param_1 + 10));
  uVar4 = PackedFloatingSUB(uVar1,uVar4);
  uVar3 = PackedFloatingMUL(*(undefined8 *)(param_1 + 0xd),*(undefined8 *)(param_1 + 8));
  uVar1 = PackedFloatingMUL(*(undefined8 *)(param_1 + 9),*(undefined8 *)(param_1 + 0xc));
  uVar3 = PackedFloatingSUB(uVar3,uVar1);
  uVar2 = (undefined4)((ulonglong)*(undefined8 *)(param_1 + 6) >> 0x20);
  uVar6 = PackedFloatingMUL(uVar5,*(undefined8 *)(param_1 + 4));
  uVar1 = PackedFloatingMUL(uVar3,CONCAT44(uVar2,uVar2));
  uVar6 = PackedFloatingADD(uVar6,uVar1);
  uVar1 = PackedFloatingMUL(CONCAT44((int)uVar5,(int)((ulonglong)uVar4 >> 0x20)),
                            *(undefined8 *)(param_1 + 5));
  uVar1 = PackedFloatingSUB(uVar6,uVar1);
  uVar6 = PackedFloatingMUL(uVar1,CONCAT44(*param_1,(int)*(undefined8 *)(param_1 + 2)));
  uVar8 = PackedFloatingMUL(CONCAT44((int)uVar4,(int)uVar3),*(undefined8 *)(param_1 + 6));
  uVar4 = PackedFloatingMUL(uVar4,*(undefined8 *)(param_1 + 5));
  uVar1 = PackedFloatingMUL(CONCAT44((int)((ulonglong)uVar5 >> 0x20),(int)((ulonglong)uVar3 >> 0x20)
                                    ),
                            CONCAT44((int)*(undefined8 *)(param_1 + 4),
                                     (int)*(undefined8 *)(param_1 + 4)));
  uVar1 = PackedFloatingADD(uVar1,uVar8);
  uVar1 = PackedFloatingSUB(uVar1,uVar4);
  uVar1 = PackedFloatingMUL(uVar1,CONCAT44(param_1[1],
                                           (int)((ulonglong)*(undefined8 *)(param_1 + 2) >> 0x20)));
  uVar1 = PackedFloatingSUB(uVar6,uVar1);
  uVar1 = PackedFloatingAccumulate(uVar1,uVar1);
  FastExitMediaState();
  return (float10)(float)uVar1;
}


// ==== 0x5f0498 FUN_005f0498

void FUN_005f0498(undefined8 *param_1,undefined8 param_2,undefined4 param_3)

{
  FastExitMediaState();
  *param_1 = 0x3f800000;
  param_1[1] = 0;
  param_1[2] = 0x3f80000000000000;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0x3f800000;
  param_1[6] = param_2;
  param_1[7] = CONCAT44(0x3f800000,param_3);
  FastExitMediaState();
  return;
}


// ==== 0x5f04e8 FUN_005f04e8

void FUN_005f04e8(undefined8 *param_1,undefined8 *param_2,undefined4 param_3)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulonglong uStack_18;
  ulonglong uStack_10;
  
  FastExitMediaState();
  FUN_005f55cb(&uStack_18,param_3);
  uVar5 = *param_2;
  uVar1 = PackedFloatingMUL(uVar5,uStack_18);
  uVar6 = param_2[1];
  uVar3 = PackedFloatingMUL(uVar6,uStack_10);
  uVar1 = PackedFloatingADD(uVar1,uVar3);
  uVar2 = PackedFloatingAccumulate(uVar1,uVar1);
  uVar4 = (undefined4)(uStack_18 ^ 0x8000000080000000);
  uVar1 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar5);
  uVar3 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar6);
  uVar1 = PackedFloatingADD(uVar1,uVar2 & 0xffffffff);
  *param_1 = uVar1;
  param_1[1] = uVar3;
  uVar4 = (undefined4)((uStack_18 ^ 0x8000000080000000) >> 0x20);
  uVar1 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar5);
  uVar3 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar6);
  uVar1 = PackedFloatingADD(uVar1,uVar2 << 0x20);
  param_1[2] = uVar1;
  param_1[3] = uVar3;
  uVar4 = (undefined4)(uStack_10 ^ 0x8000000080000000);
  uVar1 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar5);
  uVar3 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar6);
  uVar3 = PackedFloatingADD(uVar3,uVar2 & 0xffffffff);
  param_1[4] = uVar1;
  param_1[5] = uVar3;
  uVar4 = (undefined4)((uStack_10 ^ 0x8000000080000000) >> 0x20);
  uVar5 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar5);
  uVar6 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar6);
  uVar6 = PackedFloatingADD(uVar6,uVar2 << 0x20);
  param_1[6] = uVar5;
  param_1[7] = uVar6;
  FastExitMediaState();
  return;
}


// ==== 0x5f05d3 FUN_005f05d3

void FUN_005f05d3(undefined8 *param_1,undefined4 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint uVar6;
  undefined8 uVar5;
  undefined8 uVar7;
  ulonglong uStack_18;
  ulonglong uStack_10;
  
  FastExitMediaState();
  FUN_005f55cb(&uStack_18,param_2);
  uVar1 = PackedFloatingMUL(uStack_18,0xc0000000c0000000);
  uVar2 = PackedFloatingMUL(uStack_10,0x3f800000c0000000);
  uVar6 = (uint)(uStack_18 >> 0x20);
  uVar3 = PackedFloatingMUL(CONCAT44((int)uStack_18,(int)uStack_18),uVar1);
  uVar4 = PackedFloatingMUL(uStack_18 & 0xffffffff,uVar2);
  uVar5 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),uVar1);
  uVar7 = PackedFloatingMUL((ulonglong)uVar6,uVar2);
  uVar3 = PackedFloatingADD(uVar3,0x3f800000);
  uVar5 = PackedFloatingADD(uVar5,0x3f80000000000000);
  *param_1 = uVar3;
  param_1[1] = uVar4;
  param_1[2] = uVar5;
  param_1[3] = uVar7;
  uVar6 = (uint)(uStack_10 >> 0x20);
  uVar3 = PackedFloatingMUL(CONCAT44((int)uStack_10,(int)uStack_10),uVar1);
  uVar4 = PackedFloatingMUL(uStack_10 & 0xffffffff,uVar2);
  uVar5 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),uVar1);
  uVar2 = PackedFloatingMUL((ulonglong)uVar6,uVar2);
  uVar1 = PackedFloatingADD(uVar4,0x3f800000);
  uVar2 = PackedFloatingADD(uVar2,0x3f80000000000000);
  param_1[4] = uVar3;
  param_1[5] = uVar1;
  param_1[6] = uVar5;
  param_1[7] = uVar2;
  FastExitMediaState();
  return;
}


// ==== 0x5f06af FUN_005f06af

void FUN_005f06af(undefined8 *param_1)

{
  ulonglong uVar1;
  
  FastExitMediaState();
  uVar1 = FUN_0061bee0();
  *param_1 = 0x3f800000;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = 0;
  *(int *)((int)param_1 + 0x14) = (int)uVar1;
  param_1[3] = uVar1 >> 0x20;
  param_1[6] = 0;
  param_1[7] = 0x3f80000000000000;
  *(undefined4 *)(param_1 + 4) = 0;
  *(uint *)((int)param_1 + 0x24) = (uint)(uVar1 >> 0x20) ^ 0x80000000;
  *(int *)(param_1 + 5) = (int)uVar1;
  *(undefined4 *)((int)param_1 + 0x2c) = 0;
  FastExitMediaState();
  return;
}


// ==== 0x5f0712 FUN_005f0712

void FUN_005f0712(ulonglong *param_1)

{
  ulonglong uVar1;
  
  FastExitMediaState();
  uVar1 = FUN_0061bee0();
  param_1[2] = 0x3f80000000000000;
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[7] = 0x3f80000000000000;
  param_1[4] = uVar1 >> 0x20;
  *param_1 = uVar1 & 0xffffffff;
  param_1[5] = uVar1 & 0xffffffff;
  param_1[1] = uVar1 >> 0x20 ^ 0x80000000;
  FastExitMediaState();
  return;
}


// ==== 0x5f0770 FUN_005f0770

void FUN_005f0770(undefined8 *param_1)

{
  undefined8 uVar1;
  
  FastExitMediaState();
  uVar1 = FUN_0061bee0();
  *param_1 = uVar1;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0x3f800000;
  param_1[6] = 0;
  param_1[7] = 0x3f80000000000000;
  param_1[2] = CONCAT44((int)uVar1,(int)((ulonglong)uVar1 >> 0x20)) ^ 0x80000000;
  FastExitMediaState();
  return;
}


// ==== 0x5f07c9 FUN_005f07c9

void FUN_005f07c9(ulonglong *param_1,uint param_2,uint param_3,uint param_4)

{
  FastExitMediaState();
  *param_1 = (ulonglong)param_2;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[2] = (ulonglong)param_3 << 0x20;
  param_1[5] = (ulonglong)param_4;
  param_1[7] = 0x3f80000000000000;
  FastExitMediaState();
  return;
}


// ==== 0x5f0810 FUN_005f0810

void FUN_005f0810(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  uVar1 = *param_2;
  uVar2 = param_2[2];
  uVar3 = param_2[5];
  uVar4 = param_2[7];
  *param_1 = CONCAT44((int)uVar2,(int)uVar1);
  param_1[2] = CONCAT44((int)((ulonglong)uVar2 >> 0x20),(int)((ulonglong)uVar1 >> 0x20));
  uVar1 = param_2[1];
  uVar2 = param_2[3];
  uVar5 = param_2[4];
  param_1[5] = CONCAT44((int)uVar4,(int)uVar3);
  param_1[7] = CONCAT44((int)((ulonglong)uVar4 >> 0x20),(int)((ulonglong)uVar3 >> 0x20));
  uVar3 = param_2[6];
  param_1[4] = CONCAT44((int)uVar2,(int)uVar1);
  param_1[6] = CONCAT44((int)((ulonglong)uVar2 >> 0x20),(int)((ulonglong)uVar1 >> 0x20));
  param_1[3] = CONCAT44((int)((ulonglong)uVar3 >> 0x20),(int)((ulonglong)uVar5 >> 0x20));
  param_1[1] = CONCAT44((int)uVar3,(int)uVar5);
  FastExitMediaState();
  return;
}


// ==== 0x5f087f FUN_005f087f

void FUN_005f087f(undefined8 *param_1)

{
  *param_1 = 0x3f800000;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0x3f800000;
  param_1[6] = 0;
  param_1[2] = 0x3f80000000000000;
  param_1[7] = 0x3f80000000000000;
  FastExitMediaState();
  return;
}


// ==== 0x5f08b8 FUN_005f08b8

void FUN_005f08b8(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined4 uVar8;
  ulonglong uVar7;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  
  uVar10 = *param_2;
  uVar3 = param_2[1];
  uVar1 = PackedFloatingADD(uVar10,uVar10);
  uVar2 = PackedFloatingADD(uVar3,uVar3);
  uVar4 = (undefined4)((ulonglong)uVar10 >> 0x20);
  uVar8 = (undefined4)((ulonglong)uVar3 >> 0x20);
  uVar11 = CONCAT44(uVar8,uVar8);
  uVar5 = PackedFloatingMUL(uVar10,uVar1);
  uVar10 = CONCAT44((int)uVar1,(int)uVar2);
  uVar9 = PackedFloatingMUL(uVar1,uVar11);
  uVar2 = PackedFloatingMUL(CONCAT44((int)uVar3,(int)uVar3),uVar10);
  uVar3 = PackedFloatingMUL(uVar10,CONCAT44(uVar4,uVar4));
  uVar10 = PackedFloatingMUL(uVar10,uVar11);
  uVar1 = CONCAT44((int)((ulonglong)uVar2 >> 0x20),(int)((ulonglong)uVar3 >> 0x20));
  param_1[6] = 0;
  uVar11 = PackedFloatingADD(CONCAT44((int)uVar2,(int)uVar2),uVar5);
  uVar2 = PackedFloatingAccumulate(uVar5,uVar5);
  uVar10 = CONCAT44((int)((ulonglong)uVar9 >> 0x20),(int)uVar10);
  uVar6 = PackedFloatingSUBR(uVar2,0x3f8000003f800000);
  uVar5 = PackedFloatingSUBR(uVar11,0x3f8000003f800000);
  uVar2 = PackedFloatingADD(uVar1,uVar10);
  param_1[5] = uVar6 & 0xffffffff;
  uVar7 = PackedFloatingSUB(uVar1,uVar10);
  uVar6 = PackedFloatingADD(uVar3,uVar9);
  uVar10 = PackedFloatingSUB(uVar3,uVar9);
  param_1[3] = uVar6 & 0xffffffff;
  param_1[1] = uVar7 >> 0x20;
  param_1[2] = CONCAT44((int)uVar5,(int)uVar7);
  *param_1 = CONCAT44((int)uVar2,(int)((ulonglong)uVar5 >> 0x20));
  param_1[4] = CONCAT44((int)uVar10,(int)((ulonglong)uVar2 >> 0x20));
  param_1[7] = 0x3f80000000000000;
  FastExitMediaState();
  return;
}


// ==== 0x5f098a FUN_005f098a

void FUN_005f098a(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined8 in_MM3;
  undefined8 uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  
  uVar3 = *param_2;
  uVar10 = param_2[1];
  uVar7 = PackedSwapDWords(in_MM3,uVar3);
  uVar1 = PackedFloatingADD(uVar3,uVar3);
  uVar4 = PackedFloatingADD(uVar10,uVar10);
  uVar2 = PackedFloatingMUL(uVar1,uVar3);
  uVar5 = PackedFloatingMUL(uVar3,uVar4);
  uVar8 = PackedFloatingMUL(uVar7,uVar4);
  uVar7 = PackedFloatingMUL(uVar4,uVar10);
  uVar1 = PackedFloatingMUL(CONCAT44((int)((ulonglong)uVar10 >> 0x20),
                                     (int)((ulonglong)uVar3 >> 0x20)),
                            CONCAT44((int)uVar4,(int)uVar1));
  uVar3 = PackedFloatingSUBR(uVar2,0x3f8000003f800000);
  uVar9 = PackedFloatingPosNegAccumulate(uVar8,uVar8);
  uVar10 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar2 = PackedFloatingPosNegAccumulate(uVar1,uVar1);
  uVar6 = PackedFloatingPosNegAccumulate(uVar5,uVar5);
  uVar3 = PackedFloatingSUB(uVar3,CONCAT44((int)uVar7,(int)uVar7));
  uVar1 = PackedSwapDWords(uVar7,uVar6);
  uVar11 = PackedFloatingSUBR(uVar10,0x3f8000003f800000);
  param_1[6] = 0;
  param_1[4] = CONCAT44((int)uVar9,(int)uVar1);
  param_1[1] = uVar6 & 0xffffffff;
  param_1[5] = uVar11 >> 0x20;
  *param_1 = CONCAT44((int)((ulonglong)uVar2 >> 0x20),(int)((ulonglong)uVar3 >> 0x20));
  param_1[2] = CONCAT44((int)uVar3,(int)uVar2);
  param_1[3] = uVar9 >> 0x20;
  param_1[7] = 0x3f80000000000000;
  FastExitMediaState();
  return;
}


// ==== 0x5f0a3f FUN_005f0a3f

void FUN_005f0a3f(ulonglong *param_1,undefined8 *param_2,undefined8 *param_3,ulonglong *param_4,
                 undefined8 *param_5,undefined8 *param_6,undefined8 *param_7)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar7;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  undefined4 uVar16;
  ulonglong uVar14;
  undefined8 uVar15;
  ulonglong uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  uint uVar24;
  undefined8 uVar22;
  undefined8 uVar23;
  undefined4 uVar25;
  undefined8 uVar26;
  undefined4 uVar29;
  ulonglong uVar27;
  ulonglong uVar28;
  
  if (param_4 == (ulonglong *)0x0) {
    *param_1 = 0x3f800000;
    param_1[1] = 0;
    param_1[2] = 0x3f80000000000000;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0x3f800000;
    param_1[6] = 0;
    param_1[7] = 0x3f80000000000000;
  }
  else if (param_3 == (undefined8 *)0x0) {
    uVar12 = *param_4;
    uVar11 = param_4[1];
    *param_1 = uVar12 & 0xffffffff;
    param_1[1] = 0;
    param_1[2] = uVar12 & 0xffffffff00000000;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = (ulonglong)(uint)uVar11;
    param_1[6] = 0;
    param_1[7] = 0x3f80000000000000;
  }
  else {
    uVar13 = (ulonglong)(uint)param_4[1];
    uVar27 = *param_4 & 0xffffffff;
    uVar17 = *param_4 & 0xffffffff00000000;
    uVar21 = *param_3;
    uVar4 = param_3[1];
    uVar2 = PackedFloatingADD(uVar21,uVar21);
    uVar3 = PackedFloatingADD(uVar4,uVar4);
    uVar7 = (undefined4)((ulonglong)uVar21 >> 0x20);
    uVar16 = (undefined4)((ulonglong)uVar4 >> 0x20);
    uVar26 = CONCAT44(uVar16,uVar16);
    uVar8 = PackedFloatingMUL(uVar21,uVar2);
    uVar21 = CONCAT44((int)uVar2,(int)uVar3);
    uVar18 = PackedFloatingMUL(uVar2,uVar26);
    uVar3 = PackedFloatingMUL(CONCAT44((int)uVar4,(int)uVar4),uVar21);
    uVar4 = PackedFloatingMUL(uVar21,CONCAT44(uVar7,uVar7));
    uVar21 = PackedFloatingMUL(uVar21,uVar26);
    uVar2 = CONCAT44((int)((ulonglong)uVar3 >> 0x20),(int)((ulonglong)uVar4 >> 0x20));
    uVar26 = PackedFloatingADD(CONCAT44((int)uVar3,(int)uVar3),uVar8);
    uVar3 = PackedFloatingAccumulate(uVar8,uVar8);
    uVar21 = CONCAT44((int)((ulonglong)uVar18 >> 0x20),(int)uVar21);
    uVar9 = PackedFloatingSUBR(uVar3,0x3f8000003f800000);
    uVar8 = PackedFloatingSUBR(uVar26,0x3f8000003f800000);
    uVar10 = uVar9 & 0xffffffff;
    uVar3 = PackedFloatingADD(uVar2,uVar21);
    uVar14 = PackedFloatingSUB(uVar2,uVar21);
    uVar5 = PackedFloatingADD(uVar4,uVar18);
    uVar11 = PackedFloatingSUB(uVar4,uVar18);
    uVar28 = uVar5 & 0xffffffff;
    uVar16 = (undefined4)uVar14;
    uVar25 = (undefined4)uVar8;
    uVar4 = CONCAT44(uVar25,uVar16);
    uVar7 = (undefined4)uVar3;
    uVar12 = uVar14 >> 0x20;
    uVar24 = (uint)((ulonglong)uVar3 >> 0x20);
    uVar29 = (undefined4)((ulonglong)uVar8 >> 0x20);
    uVar21 = CONCAT44(uVar7,uVar29);
    uVar2 = CONCAT44((int)uVar11,uVar24);
    uVar1 = (undefined4)(uVar14 >> 0x20);
    if (param_2 == (undefined8 *)0x0) {
      *param_1 = CONCAT44(uVar16,uVar29);
      param_1[2] = CONCAT44(uVar25,uVar7);
      param_1[5] = uVar9 & 0xffffffff;
      param_1[7] = 0x3f80000000000000;
      param_1[4] = CONCAT44((int)uVar5,uVar1);
      param_1[6] = 0;
      param_1[3] = uVar11 & 0xffffffff;
      param_1[1] = (ulonglong)uVar24;
      uVar7 = (undefined4)(*param_1 >> 0x20);
      uVar16 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar27,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,0);
      uVar20 = PackedFloatingMUL(uVar17,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(0,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar13);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar5 = PackedFloatingADD(uVar23,uVar18);
      uVar11 = PackedFloatingADD(uVar8,uVar3);
      *param_1 = uVar5;
      param_1[1] = uVar11;
      uVar7 = (undefined4)(param_1[2] >> 0x20);
      uVar16 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar27,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,0);
      uVar20 = PackedFloatingMUL(uVar17,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(0,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar13);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar5 = PackedFloatingADD(uVar23,uVar18);
      uVar11 = PackedFloatingADD(uVar8,uVar3);
      param_1[2] = uVar5;
      param_1[3] = uVar11;
      uVar7 = (undefined4)(param_1[4] >> 0x20);
      uVar16 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar27,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,0);
      uVar20 = PackedFloatingMUL(uVar17,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(0,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar13);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar5 = PackedFloatingADD(uVar23,uVar18);
      uVar11 = PackedFloatingADD(uVar8,uVar3);
      param_1[4] = uVar5;
      param_1[5] = uVar11;
      uVar7 = (undefined4)(param_1[6] >> 0x20);
      uVar16 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar27,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,0);
      uVar20 = PackedFloatingMUL(uVar17,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(0,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar13);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar27 = PackedFloatingADD(uVar23,uVar18);
      uVar11 = PackedFloatingADD(uVar8,uVar3);
      param_1[6] = uVar27;
      param_1[7] = uVar11;
      uVar7 = (undefined4)(*param_1 >> 0x20);
      uVar16 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar21,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,uVar12);
      uVar20 = PackedFloatingMUL(uVar4,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,uVar28);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(uVar2,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar10);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar27 = PackedFloatingADD(uVar23,uVar18);
      uVar11 = PackedFloatingADD(uVar8,uVar3);
      *param_1 = uVar27;
      param_1[1] = uVar11;
      uVar7 = (undefined4)(param_1[2] >> 0x20);
      uVar16 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar21,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,uVar12);
      uVar20 = PackedFloatingMUL(uVar4,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,uVar28);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(uVar2,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar10);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar27 = PackedFloatingADD(uVar23,uVar18);
      uVar11 = PackedFloatingADD(uVar8,uVar3);
      param_1[2] = uVar27;
      param_1[3] = uVar11;
      uVar7 = (undefined4)(param_1[4] >> 0x20);
      uVar16 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar21,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,uVar12);
      uVar20 = PackedFloatingMUL(uVar4,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,uVar28);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(uVar2,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar10);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar27 = PackedFloatingADD(uVar23,uVar18);
      uVar11 = PackedFloatingADD(uVar8,uVar3);
      param_1[4] = uVar27;
      param_1[5] = uVar11;
      uVar7 = (undefined4)(param_1[6] >> 0x20);
      uVar16 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar3 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar21,uVar3);
      uVar21 = CONCAT44(uVar7,uVar7);
      uVar3 = PackedFloatingMUL(uVar3,uVar12);
      uVar18 = PackedFloatingMUL(uVar4,uVar21);
      uVar4 = CONCAT44(uVar16,uVar16);
      uVar21 = PackedFloatingMUL(uVar21,uVar28);
      uVar26 = PackedFloatingADD(uVar18,uVar26);
      uVar18 = PackedFloatingMUL(uVar2,uVar8);
      uVar2 = PackedFloatingADD(uVar21,uVar3);
      uVar21 = PackedFloatingMUL(uVar8,uVar10);
      uVar3 = PackedFloatingADD(uVar18,uVar26);
      uVar8 = PackedFloatingMUL(0,uVar4);
      uVar21 = PackedFloatingADD(uVar2,uVar21);
      uVar4 = PackedFloatingMUL(uVar4,0x3f80000000000000);
      uVar11 = PackedFloatingADD(uVar8,uVar3);
      uVar12 = PackedFloatingADD(uVar4,uVar21);
      param_1[6] = uVar11;
      param_1[7] = uVar12;
    }
    else {
      uVar26 = CONCAT44(uVar16,uVar29);
      uVar20 = CONCAT44(uVar25,uVar7);
      uVar9 = uVar9 & 0xffffffff;
      uVar22 = CONCAT44((int)uVar5,uVar1);
      uVar11 = uVar11 & 0xffffffff;
      uVar14 = (ulonglong)uVar24;
      uVar3 = *param_2;
      uVar24 = *(uint *)(param_2 + 1);
      *param_1 = 0x3f800000;
      param_1[1] = 0;
      param_1[2] = 0x3f80000000000000;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0x3f800000;
      uVar6 = PackedFloatingSUB(0x3f80000000000000,(ulonglong)uVar24);
      uVar5 = PackedFloatingSUB(0,uVar3);
      param_1[7] = uVar6;
      param_1[6] = uVar5;
      uVar7 = (undefined4)(*param_1 >> 0x20);
      uVar16 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar23 = CONCAT44(uVar1,uVar1);
      uVar15 = PackedFloatingMUL(uVar26,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar18 = PackedFloatingMUL(uVar8,uVar14);
      uVar19 = PackedFloatingMUL(uVar20,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,uVar11);
      uVar15 = PackedFloatingADD(uVar19,uVar15);
      uVar19 = PackedFloatingMUL(uVar22,uVar23);
      uVar18 = PackedFloatingADD(uVar3,uVar18);
      uVar3 = PackedFloatingMUL(uVar23,uVar9);
      uVar23 = PackedFloatingADD(uVar19,uVar15);
      uVar15 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar18,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar6 = PackedFloatingADD(uVar15,uVar23);
      uVar5 = PackedFloatingADD(uVar8,uVar3);
      *param_1 = uVar6;
      param_1[1] = uVar5;
      uVar7 = (undefined4)(param_1[2] >> 0x20);
      uVar16 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar23 = CONCAT44(uVar1,uVar1);
      uVar15 = PackedFloatingMUL(uVar26,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar18 = PackedFloatingMUL(uVar8,uVar14);
      uVar19 = PackedFloatingMUL(uVar20,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,uVar11);
      uVar15 = PackedFloatingADD(uVar19,uVar15);
      uVar19 = PackedFloatingMUL(uVar22,uVar23);
      uVar18 = PackedFloatingADD(uVar3,uVar18);
      uVar3 = PackedFloatingMUL(uVar23,uVar9);
      uVar23 = PackedFloatingADD(uVar19,uVar15);
      uVar15 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar18,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar6 = PackedFloatingADD(uVar15,uVar23);
      uVar5 = PackedFloatingADD(uVar8,uVar3);
      param_1[2] = uVar6;
      param_1[3] = uVar5;
      uVar7 = (undefined4)(param_1[4] >> 0x20);
      uVar16 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar23 = CONCAT44(uVar1,uVar1);
      uVar15 = PackedFloatingMUL(uVar26,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar18 = PackedFloatingMUL(uVar8,uVar14);
      uVar19 = PackedFloatingMUL(uVar20,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,uVar11);
      uVar15 = PackedFloatingADD(uVar19,uVar15);
      uVar19 = PackedFloatingMUL(uVar22,uVar23);
      uVar18 = PackedFloatingADD(uVar3,uVar18);
      uVar3 = PackedFloatingMUL(uVar23,uVar9);
      uVar23 = PackedFloatingADD(uVar19,uVar15);
      uVar15 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar18,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar6 = PackedFloatingADD(uVar15,uVar23);
      uVar5 = PackedFloatingADD(uVar8,uVar3);
      param_1[4] = uVar6;
      param_1[5] = uVar5;
      uVar7 = (undefined4)(param_1[6] >> 0x20);
      uVar16 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar26,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,uVar14);
      uVar20 = PackedFloatingMUL(uVar20,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,uVar11);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(uVar22,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar9);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar5 = PackedFloatingADD(uVar23,uVar18);
      uVar11 = PackedFloatingADD(uVar8,uVar3);
      param_1[6] = uVar5;
      param_1[7] = uVar11;
      uVar7 = (undefined4)(*param_1 >> 0x20);
      uVar16 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar27,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,0);
      uVar20 = PackedFloatingMUL(uVar17,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(0,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar13);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar5 = PackedFloatingADD(uVar23,uVar18);
      uVar11 = PackedFloatingADD(uVar8,uVar3);
      *param_1 = uVar5;
      param_1[1] = uVar11;
      uVar7 = (undefined4)(param_1[2] >> 0x20);
      uVar16 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar27,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,0);
      uVar20 = PackedFloatingMUL(uVar17,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(0,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar13);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar5 = PackedFloatingADD(uVar23,uVar18);
      uVar11 = PackedFloatingADD(uVar8,uVar3);
      param_1[2] = uVar5;
      param_1[3] = uVar11;
      uVar7 = (undefined4)(param_1[4] >> 0x20);
      uVar16 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar27,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,0);
      uVar20 = PackedFloatingMUL(uVar17,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(0,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar13);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar5 = PackedFloatingADD(uVar23,uVar18);
      uVar11 = PackedFloatingADD(uVar8,uVar3);
      param_1[4] = uVar5;
      param_1[5] = uVar11;
      uVar7 = (undefined4)(param_1[6] >> 0x20);
      uVar16 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar27,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,0);
      uVar20 = PackedFloatingMUL(uVar17,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(0,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar13);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar27 = PackedFloatingADD(uVar23,uVar18);
      uVar11 = PackedFloatingADD(uVar8,uVar3);
      param_1[6] = uVar27;
      param_1[7] = uVar11;
      uVar7 = (undefined4)(*param_1 >> 0x20);
      uVar16 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar21,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,uVar12);
      uVar20 = PackedFloatingMUL(uVar4,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,uVar28);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(uVar2,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar10);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar27 = PackedFloatingADD(uVar23,uVar18);
      uVar11 = PackedFloatingADD(uVar8,uVar3);
      *param_1 = uVar27;
      param_1[1] = uVar11;
      uVar7 = (undefined4)(param_1[2] >> 0x20);
      uVar16 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar21,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,uVar12);
      uVar20 = PackedFloatingMUL(uVar4,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,uVar28);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(uVar2,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar10);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar27 = PackedFloatingADD(uVar23,uVar18);
      uVar11 = PackedFloatingADD(uVar8,uVar3);
      param_1[2] = uVar27;
      param_1[3] = uVar11;
      uVar7 = (undefined4)(param_1[4] >> 0x20);
      uVar16 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar21,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,uVar12);
      uVar20 = PackedFloatingMUL(uVar4,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,uVar28);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(uVar2,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar10);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar27 = PackedFloatingADD(uVar23,uVar18);
      uVar11 = PackedFloatingADD(uVar8,uVar3);
      param_1[4] = uVar27;
      param_1[5] = uVar11;
      uVar7 = (undefined4)(param_1[6] >> 0x20);
      uVar16 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar3 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar21,uVar3);
      uVar21 = CONCAT44(uVar7,uVar7);
      uVar3 = PackedFloatingMUL(uVar3,uVar12);
      uVar18 = PackedFloatingMUL(uVar4,uVar21);
      uVar4 = CONCAT44(uVar16,uVar16);
      uVar21 = PackedFloatingMUL(uVar21,uVar28);
      uVar26 = PackedFloatingADD(uVar18,uVar26);
      uVar18 = PackedFloatingMUL(uVar2,uVar8);
      uVar2 = PackedFloatingADD(uVar21,uVar3);
      uVar21 = PackedFloatingMUL(uVar8,uVar10);
      uVar3 = PackedFloatingADD(uVar18,uVar26);
      uVar8 = PackedFloatingMUL(0,uVar4);
      uVar21 = PackedFloatingADD(uVar2,uVar21);
      uVar4 = PackedFloatingMUL(uVar4,0x3f80000000000000);
      uVar11 = PackedFloatingADD(uVar8,uVar3);
      uVar12 = PackedFloatingADD(uVar4,uVar21);
      param_1[6] = uVar11;
      param_1[7] = uVar12;
      uVar12 = PackedFloatingADD(*param_2,param_1[6]);
      uVar21 = PackedFloatingADD((ulonglong)*(uint *)(param_2 + 1),(ulonglong)(uint)param_1[7]);
      param_1[6] = uVar12;
      *(int *)(param_1 + 7) = (int)uVar21;
    }
  }
  if (param_6 != (undefined8 *)0x0) {
    uVar21 = *param_6;
    uVar4 = param_6[1];
    uVar2 = PackedFloatingADD(uVar21,uVar21);
    uVar3 = PackedFloatingADD(uVar4,uVar4);
    uVar7 = (undefined4)((ulonglong)uVar21 >> 0x20);
    uVar16 = (undefined4)((ulonglong)uVar4 >> 0x20);
    uVar26 = CONCAT44(uVar16,uVar16);
    uVar8 = PackedFloatingMUL(uVar21,uVar2);
    uVar21 = CONCAT44((int)uVar2,(int)uVar3);
    uVar18 = PackedFloatingMUL(uVar2,uVar26);
    uVar3 = PackedFloatingMUL(CONCAT44((int)uVar4,(int)uVar4),uVar21);
    uVar4 = PackedFloatingMUL(uVar21,CONCAT44(uVar7,uVar7));
    uVar21 = PackedFloatingMUL(uVar21,uVar26);
    uVar2 = CONCAT44((int)((ulonglong)uVar3 >> 0x20),(int)((ulonglong)uVar4 >> 0x20));
    uVar26 = PackedFloatingADD(CONCAT44((int)uVar3,(int)uVar3),uVar8);
    uVar3 = PackedFloatingAccumulate(uVar8,uVar8);
    uVar21 = CONCAT44((int)((ulonglong)uVar18 >> 0x20),(int)uVar21);
    uVar27 = PackedFloatingSUBR(uVar3,0x3f8000003f800000);
    uVar8 = PackedFloatingSUBR(uVar26,0x3f8000003f800000);
    uVar27 = uVar27 & 0xffffffff;
    uVar3 = PackedFloatingADD(uVar2,uVar21);
    uVar12 = PackedFloatingSUB(uVar2,uVar21);
    uVar11 = PackedFloatingADD(uVar4,uVar18);
    uVar4 = PackedFloatingSUB(uVar4,uVar18);
    uVar11 = uVar11 & 0xffffffff;
    uVar2 = CONCAT44((int)uVar8,(int)uVar12);
    uVar12 = uVar12 >> 0x20;
    uVar21 = CONCAT44((int)uVar3,(int)((ulonglong)uVar8 >> 0x20));
    uVar4 = CONCAT44((int)uVar4,(int)((ulonglong)uVar3 >> 0x20));
    if (param_5 == (undefined8 *)0x0) {
      uVar7 = (undefined4)(*param_1 >> 0x20);
      uVar16 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar21,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,uVar12);
      uVar20 = PackedFloatingMUL(uVar2,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,uVar11);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(uVar4,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar27);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar28 = PackedFloatingADD(uVar23,uVar18);
      uVar5 = PackedFloatingADD(uVar8,uVar3);
      *param_1 = uVar28;
      param_1[1] = uVar5;
      uVar7 = (undefined4)(param_1[2] >> 0x20);
      uVar16 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar21,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,uVar12);
      uVar20 = PackedFloatingMUL(uVar2,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,uVar11);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(uVar4,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar27);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar28 = PackedFloatingADD(uVar23,uVar18);
      uVar5 = PackedFloatingADD(uVar8,uVar3);
      param_1[2] = uVar28;
      param_1[3] = uVar5;
      uVar7 = (undefined4)(param_1[4] >> 0x20);
      uVar16 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar21,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,uVar12);
      uVar20 = PackedFloatingMUL(uVar2,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,uVar11);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(uVar4,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar27);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar28 = PackedFloatingADD(uVar23,uVar18);
      uVar5 = PackedFloatingADD(uVar8,uVar3);
      param_1[4] = uVar28;
      param_1[5] = uVar5;
      uVar7 = (undefined4)(param_1[6] >> 0x20);
      uVar16 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar3 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar21,uVar3);
      uVar21 = CONCAT44(uVar7,uVar7);
      uVar3 = PackedFloatingMUL(uVar3,uVar12);
      uVar18 = PackedFloatingMUL(uVar2,uVar21);
      uVar2 = CONCAT44(uVar16,uVar16);
      uVar21 = PackedFloatingMUL(uVar21,uVar11);
      uVar26 = PackedFloatingADD(uVar18,uVar26);
      uVar18 = PackedFloatingMUL(uVar4,uVar8);
      uVar4 = PackedFloatingADD(uVar21,uVar3);
      uVar21 = PackedFloatingMUL(uVar8,uVar27);
      uVar3 = PackedFloatingADD(uVar18,uVar26);
      uVar8 = PackedFloatingMUL(0,uVar2);
      uVar21 = PackedFloatingADD(uVar4,uVar21);
      uVar4 = PackedFloatingMUL(uVar2,0x3f80000000000000);
      uVar11 = PackedFloatingADD(uVar8,uVar3);
      uVar12 = PackedFloatingADD(uVar4,uVar21);
      param_1[6] = uVar11;
      param_1[7] = uVar12;
    }
    else {
      uVar5 = PackedFloatingSUB(param_1[6],*param_5);
      uVar3 = PackedFloatingSUB((ulonglong)(uint)param_1[7],(ulonglong)*(uint *)(param_5 + 1));
      param_1[6] = uVar5;
      *(int *)(param_1 + 7) = (int)uVar3;
      uVar7 = (undefined4)(*param_1 >> 0x20);
      uVar16 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar21,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,uVar12);
      uVar20 = PackedFloatingMUL(uVar2,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,uVar11);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(uVar4,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar27);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar28 = PackedFloatingADD(uVar23,uVar18);
      uVar5 = PackedFloatingADD(uVar8,uVar3);
      *param_1 = uVar28;
      param_1[1] = uVar5;
      uVar7 = (undefined4)(param_1[2] >> 0x20);
      uVar16 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar21,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,uVar12);
      uVar20 = PackedFloatingMUL(uVar2,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,uVar11);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(uVar4,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar27);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar28 = PackedFloatingADD(uVar23,uVar18);
      uVar5 = PackedFloatingADD(uVar8,uVar3);
      param_1[2] = uVar28;
      param_1[3] = uVar5;
      uVar7 = (undefined4)(param_1[4] >> 0x20);
      uVar16 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar18 = CONCAT44(uVar1,uVar1);
      uVar23 = PackedFloatingMUL(uVar21,uVar8);
      uVar3 = CONCAT44(uVar7,uVar7);
      uVar26 = PackedFloatingMUL(uVar8,uVar12);
      uVar20 = PackedFloatingMUL(uVar2,uVar3);
      uVar8 = CONCAT44(uVar16,uVar16);
      uVar3 = PackedFloatingMUL(uVar3,uVar11);
      uVar23 = PackedFloatingADD(uVar20,uVar23);
      uVar20 = PackedFloatingMUL(uVar4,uVar18);
      uVar26 = PackedFloatingADD(uVar3,uVar26);
      uVar3 = PackedFloatingMUL(uVar18,uVar27);
      uVar18 = PackedFloatingADD(uVar20,uVar23);
      uVar23 = PackedFloatingMUL(0,uVar8);
      uVar3 = PackedFloatingADD(uVar26,uVar3);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar28 = PackedFloatingADD(uVar23,uVar18);
      uVar5 = PackedFloatingADD(uVar8,uVar3);
      param_1[4] = uVar28;
      param_1[5] = uVar5;
      uVar7 = (undefined4)(param_1[6] >> 0x20);
      uVar16 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar3 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar21,uVar3);
      uVar21 = CONCAT44(uVar7,uVar7);
      uVar3 = PackedFloatingMUL(uVar3,uVar12);
      uVar18 = PackedFloatingMUL(uVar2,uVar21);
      uVar2 = CONCAT44(uVar16,uVar16);
      uVar21 = PackedFloatingMUL(uVar21,uVar11);
      uVar26 = PackedFloatingADD(uVar18,uVar26);
      uVar18 = PackedFloatingMUL(uVar4,uVar8);
      uVar4 = PackedFloatingADD(uVar21,uVar3);
      uVar21 = PackedFloatingMUL(uVar8,uVar27);
      uVar3 = PackedFloatingADD(uVar18,uVar26);
      uVar8 = PackedFloatingMUL(0,uVar2);
      uVar21 = PackedFloatingADD(uVar4,uVar21);
      uVar4 = PackedFloatingMUL(uVar2,0x3f80000000000000);
      uVar11 = PackedFloatingADD(uVar8,uVar3);
      uVar12 = PackedFloatingADD(uVar4,uVar21);
      param_1[6] = uVar11;
      param_1[7] = uVar12;
      uVar12 = PackedFloatingADD(param_1[6],*param_5);
      uVar21 = PackedFloatingADD((ulonglong)(uint)param_1[7],(ulonglong)*(uint *)(param_5 + 1));
      param_1[6] = uVar12;
      *(int *)(param_1 + 7) = (int)uVar21;
    }
  }
  if (param_7 != (undefined8 *)0x0) {
    uVar12 = PackedFloatingADD(param_1[6],*param_7);
    uVar21 = PackedFloatingADD((ulonglong)(uint)param_1[7],(ulonglong)*(uint *)(param_7 + 1));
    param_1[6] = uVar12;
    *(int *)(param_1 + 7) = (int)uVar21;
  }
  FastExitMediaState();
  return;
}


