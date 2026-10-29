// ==== 0x6110da FUN_006110da

int __thiscall FUN_006110da(int *param_1,int *param_2,uint *param_3)

{
  char *pcVar1;
  char cVar2;
  ushort uVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  void *_Memory;
  undefined4 *puVar9;
  uint uVar10;
  undefined1 local_34 [16];
  uint local_24 [5];
  uint local_10;
  int local_c;
  uint local_8;
  
  piVar5 = param_2;
  uVar3 = *(ushort *)((int)param_2 + 0x52);
  uVar6 = param_2[0x14] & 0xffff;
  if (param_1[0x3b] != 0) {
    if (param_2[0x14] == 0xffffffff) {
      return 0;
    }
    if (uVar6 != 0xffff) {
      _snprintf(local_34,0x20,"v_%s%d",(&PTR_s_UNKNOWN_006df648)[uVar6],uVar3);
      local_24[3] = local_24[3] & 0xffffff;
      iVar7 = FUN_005e7078(local_34,param_2[2],1);
      if (iVar7 < 0) {
        return iVar7;
      }
      param_1[0x52] = param_1[0x52] + 1;
      if ((((*(byte *)(param_1 + 0xd) & 1) != 0) && (iVar7 = param_2[0x11], iVar7 != 0)) &&
         ((*(int *)(iVar7 + 4) == 5 && (iVar7 = *(int *)(iVar7 + 0x14), *(int *)(iVar7 + 4) == 2))))
      {
        pcVar8 = *(char **)(iVar7 + 0x18);
        pcVar1 = pcVar8 + 1;
        do {
          cVar2 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar2 != '\0');
        _Memory = _malloc((size_t)(pcVar8 + (3 - (int)pcVar1)));
        if (_Memory == (void *)0x0) {
          return -0x7ff8fff2;
        }
        _sprintf(_Memory,&DAT_006a5ec0,*(undefined4 *)(iVar7 + 0x18));
        iVar7 = FUN_005e7078(_Memory,param_2[2],1);
        _free(_Memory);
        if (iVar7 < 0) {
          return iVar7;
        }
        param_1[0x52] = param_1[0x52] + 1;
      }
    }
    if (param_3 == (uint *)0x0) {
      return 0;
    }
    uVar6 = param_2[0x14];
    goto LAB_00611335;
  }
  param_2 = (int *)0xd;
  switch(uVar6) {
  case 1:
    param_2 = (int *)0x0;
    break;
  case 2:
    param_2 = (int *)0x1;
    break;
  case 3:
    param_2 = (int *)0x2;
    break;
  case 4:
    param_2 = (int *)0x3;
    break;
  case 5:
    param_2 = (int *)0x4;
    break;
  case 6:
    param_2 = (int *)0x5;
    break;
  case 7:
    param_2 = (int *)0x6;
    break;
  case 8:
    param_2 = (int *)0x7;
    break;
  case 9:
    param_2 = (int *)0x8;
    if (uVar3 != 0) {
      return -0x7fffbffb;
    }
    goto LAB_00611214;
  case 10:
    param_2 = (int *)0x9;
    break;
  case 0xb:
    param_2 = (int *)0xa;
    break;
  case 0xc:
    param_2 = (int *)0xb;
    break;
  case 0xd:
    param_2 = (int *)0xc;
    break;
  case 0xe:
    break;
  default:
    goto LAB_006113a3;
  }
  if (0xf < uVar3) {
LAB_006113a3:
    return -0x7fffbffb;
  }
LAB_00611214:
  uVar6 = (uint)param_2 | (uint)(uVar3 | 0x8000) << 0x10;
  iVar7 = FUN_0061a26f(0x1f);
  if (iVar7 < 0) {
    return iVar7;
  }
  iVar7 = FUN_00618c39(uVar6);
  if (iVar7 < 0) {
    return iVar7;
  }
  if ((*(byte *)(param_1 + 0xd) & 1) != 0) {
    local_c = 0;
    local_8 = 0;
    local_24[0] = 0xffffffff;
    local_24[1] = 0xffffffff;
    local_24[2] = 0xffffffff;
    local_24[3] = 0xffffffff;
    if (param_1[2] != 0) {
      iVar7 = *piVar5;
      puVar9 = (undefined4 *)param_1[5];
      do {
        piVar4 = (int *)*puVar9;
        if (((iVar7 == *piVar4) && (piVar5[1] == piVar4[1])) && (piVar5[2] == piVar4[2])) {
          local_24[piVar4[3]] = local_8;
        }
        local_8 = local_8 + 1;
        puVar9 = puVar9 + 1;
      } while (local_8 < (uint)param_1[2]);
    }
    uVar10 = 0;
    iVar7 = local_c;
    do {
      if (local_24[uVar10] != 0xffffffff) {
        local_24[iVar7] = local_24[uVar10];
        iVar7 = iVar7 + 1;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < 4);
    iVar7 = (**(code **)(*param_1 + 0x60))(local_24,iVar7,&local_c,1);
    if (iVar7 < 0) {
      return iVar7;
    }
  }
  iVar7 = (**(code **)(*param_1 + 0x74))(piVar5,local_24 + 4,&local_10);
  if (iVar7 < 0) {
    return iVar7;
  }
  iVar7 = (**(code **)(*param_1 + 0x54))
                    (((local_10 | 0xfffffff8) << 0x14 | local_10 & 0x18) << 8 | local_24[4] & 0x7ff,
                     0xf0000);
  if (iVar7 < 0) {
    return iVar7;
  }
  iVar7 = (**(code **)(*param_1 + 0x50))();
  if (iVar7 < 0) {
    return iVar7;
  }
  iVar7 = FUN_0061663f();
  if (iVar7 < 0) {
    return iVar7;
  }
  if (param_3 == (uint *)0x0) {
    return 0;
  }
LAB_00611335:
  *param_3 = uVar6;
  return 0;
}


// ==== 0x61141a FUN_0061141a

/* WARNING: Type propagation algorithm not settling */

int __fastcall FUN_0061141a(int *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 local_2c [4];
  int local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  if (0x1ff < (param_1[0xc] & 0xffffU)) {
    iVar1 = FUN_0061aea7(0x13);
    return iVar1;
  }
  iVar1 = param_1[0x26];
  uVar2 = *(uint *)(iVar1 + 0xc);
  local_18 = 0;
  if (*(uint *)(iVar1 + 4) < uVar2) {
    iVar1 = (**(code **)(*param_1 + 0x6c))(param_1[0x25],local_2c,4,0,0);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_0061a3fb(0x4e,local_2c + 1,1,*(undefined4 *)(param_1[0x26] + 8),0,0,1,0,0,0);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = param_1[0x26];
    uVar2 = 0;
    if (*(int *)(iVar1 + 0xc) != 0) {
      do {
        local_2c[uVar2] = local_2c[1];
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(iVar1 + 0xc));
    }
    iVar1 = FUN_0061a3fb(1,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0xc),local_2c,0,0,
                         *(undefined4 *)(iVar1 + 0xc),0,0,0);
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  else {
    local_14 = 0;
    do {
      local_8 = 0;
      if (uVar2 != 0) {
        local_10 = 1;
        local_c = 2;
        do {
          piVar3 = (int *)(local_8 * 4 + *(int *)(iVar1 + 0x10));
          local_1c = *(int *)(*(int *)(param_1[5] + *piVar3 * 4) + 0xc);
          if ((local_1c == 1) && (local_c < *(uint *)(iVar1 + 0xc))) {
            if (local_14 == 1) {
              puVar4 = (undefined4 *)(*(int *)(iVar1 + 8) + local_8 * 4);
              uVar6 = 0x4e;
LAB_006115d3:
              iVar1 = FUN_0061a3fb(uVar6,piVar3,1,puVar4,0,0,1,0,0,0);
              if (iVar1 < 0) {
                return iVar1;
              }
            }
LAB_006115e2:
            local_8 = local_8 + 1;
            local_c = local_c + 1;
            local_10 = local_10 + 1;
          }
          else {
            if (*(uint *)(iVar1 + 0xc) <= local_10) {
              if (local_14 == 0) {
                if (local_18 == 0) {
                  iVar1 = (**(code **)(*param_1 + 0x6c))(param_1[0x25],local_2c,4,0,0);
                  if (iVar1 < 0) {
                    return iVar1;
                  }
                  local_18 = 1;
                }
                iVar1 = FUN_0061a3fb(0x4e,local_2c + 1,1,*(int *)(param_1[0x26] + 8) + local_8 * 4,0
                                     ,0,1,0,0,0);
                if (iVar1 < 0) {
                  return iVar1;
                }
                puVar4 = local_2c + 1;
                piVar3 = (int *)(*(int *)(param_1[0x26] + 0x10) + local_8 * 4);
                uVar6 = 1;
                goto LAB_006115d3;
              }
              goto LAB_006115e2;
            }
            if ((local_1c == 0) && (*(int *)(*(int *)(param_1[5] + piVar3[1] * 4) + 0xc) == 1)) {
              if (local_14 == 1) {
                puVar4 = (undefined4 *)(*(int *)(iVar1 + 8) + local_8 * 4);
                uVar6 = 0x13;
LAB_0061169d:
                iVar1 = FUN_0061a3fb(uVar6,piVar3,2,puVar4,0,0,2,0,0,0);
                if (iVar1 < 0) {
                  return iVar1;
                }
              }
            }
            else if (local_14 == 0) {
              if (local_18 == 0) {
                iVar1 = (**(code **)(*param_1 + 0x6c))(param_1[0x25],local_2c,4,0,0);
                if (iVar1 < 0) {
                  return iVar1;
                }
                local_18 = 1;
              }
              iVar5 = local_8 * 4;
              iVar1 = FUN_0061a3fb(0x13,local_2c,2,*(int *)(param_1[0x26] + 8) + iVar5,0,0,2,0,0,0);
              if (iVar1 < 0) {
                return iVar1;
              }
              puVar4 = local_2c;
              piVar3 = (int *)(*(int *)(param_1[0x26] + 0x10) + iVar5);
              uVar6 = 1;
              goto LAB_0061169d;
            }
            local_c = local_c + 2;
            local_8 = local_8 + 2;
            local_10 = local_10 + 2;
          }
          iVar1 = param_1[0x26];
          uVar2 = *(uint *)(iVar1 + 0xc);
        } while (local_8 < uVar2);
      }
      local_14 = local_14 + 1;
    } while (local_14 < 2);
  }
  return 0;
}


// ==== 0x6116da FUN_006116da

int __fastcall FUN_006116da(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int local_24 [4];
  int *local_14;
  int *local_10;
  int *local_c;
  uint local_8;
  
  iVar2 = param_1[0x26];
  uVar5 = *(uint *)(iVar2 + 0xc);
  local_8 = 0;
  if (uVar5 != 0) {
    local_c = *(int **)(iVar2 + 0x10);
    do {
      if ((*(byte *)(*(int *)(param_1[5] + *local_c * 4) + 0x1b) & 2) == 0) break;
      local_8 = local_8 + 1;
      local_c = local_c + 1;
    } while (local_8 < uVar5);
  }
  if (local_8 < uVar5) {
    uVar7 = *(undefined4 *)(iVar2 + 4);
    uVar10 = *(undefined4 *)(iVar2 + 8);
    uVar9 = *(undefined4 *)(iVar2 + 0x10);
    uVar8 = 0xe;
  }
  else {
    if ((param_1[0xc] & 0xffffU) < 0x200) {
      local_c = (int *)0x0;
      if (*(uint *)(iVar2 + 4) < uVar5) {
        iVar2 = (**(code **)(*param_1 + 0x6c))(param_1[0x25],local_24,4,0,0);
        if (iVar2 < 0) {
          return iVar2;
        }
        iVar2 = FUN_0061a3fb(0x4e,local_24 + 2,1,*(undefined4 *)(param_1[0x26] + 8),0,0,1,0,0,0);
        if (iVar2 < 0) {
          return iVar2;
        }
        iVar2 = param_1[0x26];
        uVar5 = 0;
        if (*(int *)(iVar2 + 0xc) != 0) {
          do {
            local_24[uVar5] = local_24[2];
            uVar5 = uVar5 + 1;
          } while (uVar5 < *(uint *)(iVar2 + 0xc));
        }
        iVar2 = FUN_0061a3fb(1,*(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0xc),local_24,0
                             ,0,*(undefined4 *)(iVar2 + 0xc),0,0,0);
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      else {
        local_8 = 0;
        if (uVar5 != 0) {
          do {
            iVar6 = local_8 * 4;
            piVar4 = (int *)(*(int *)(iVar2 + 0x10) + iVar6);
            iVar1 = *(int *)(*(int *)(param_1[5] + *piVar4 * 4) + 0xc);
            piVar3 = (int *)(*(int *)(iVar2 + 8) + iVar6);
            iVar2 = *(int *)(param_1[5] + *piVar3 * 4);
            local_14 = piVar4;
            local_10 = piVar3;
            if ((((iVar1 == 0) && ((*(byte *)(iVar2 + 0x18) & 2) != 0)) || (iVar1 == 2)) ||
               (((iVar1 == 3 && (uVar5 = *(uint *)(iVar2 + 0x18), (uVar5 & 4) != 0)) &&
                ((uVar5 & 8) != 0)))) {
              uVar7 = 0x4e;
            }
            else {
              if (local_c == (int *)0x0) {
                iVar2 = (**(code **)(*param_1 + 0x6c))(param_1[0x25],local_24,4,0,0);
                if (iVar2 < 0) {
                  return iVar2;
                }
                local_c = (int *)0x1;
              }
              iVar2 = FUN_0061a3fb(0x4e,local_24 + 2,1,*(int *)(param_1[0x26] + 8) + iVar6,0,0,1,0,0
                                   ,0);
              if (iVar2 < 0) {
                return iVar2;
              }
              piVar3 = local_24 + 2;
              piVar4 = (int *)(*(int *)(param_1[0x26] + 0x10) + iVar6);
              uVar7 = 1;
            }
            iVar2 = FUN_0061a3fb(uVar7,piVar4,1,piVar3,0,0,1,0,0,0);
            if (iVar2 < 0) {
              return iVar2;
            }
            local_8 = local_8 + 1;
            iVar2 = param_1[0x26];
          } while (local_8 < *(uint *)(iVar2 + 0xc));
        }
      }
      return 0;
    }
    uVar7 = *(undefined4 *)(iVar2 + 4);
    uVar10 = *(undefined4 *)(iVar2 + 8);
    uVar9 = *(undefined4 *)(iVar2 + 0x10);
    uVar8 = 0x4e;
  }
  iVar2 = FUN_0061af1a(uVar8,uVar9,uVar10,uVar5,uVar7,0,0);
  return iVar2;
}


// ==== 0x6118de FUN_006118de

void __fastcall FUN_006118de(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint local_8;
  
  iVar1 = *(int *)(param_1 + 0x98);
  uVar2 = *(uint *)(iVar1 + 0xc);
  local_8 = 0;
  if (uVar2 != 0) {
    piVar3 = *(int **)(iVar1 + 0x10);
    do {
      if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar3 * 4) + 0x1b) & 2) == 0) break;
      local_8 = local_8 + 1;
      piVar3 = piVar3 + 1;
    } while (local_8 < uVar2);
  }
  FUN_0061af1a(((local_8 != uVar2) - 1U & 0x40) + 0xf,*(undefined4 *)(iVar1 + 0x10),
               *(undefined4 *)(iVar1 + 8),uVar2,*(undefined4 *)(iVar1 + 4),0,0);
  return;
}


// ==== 0x61193a FUN_0061193a

int __thiscall FUN_0061193a(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(param_1[5] + param_2 * 4);
  if ((param_1[0xc] & 0xffffU) < 0x101) {
    FUN_005fbec8(param_1,*(undefined4 *)(param_1[0x26] + 0x34),0x119f,
                 "relative addressing not supported in vs_1_0 instruction set");
    iVar2 = -0x7fffbfff;
  }
  else {
    iVar2 = *(int *)(iVar1 + 4);
    if ((iVar2 == -1) || (iVar2 = FUN_0061193a(iVar2), -1 < iVar2)) {
      if (param_1[0x33] == param_2) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_0061a26f(1);
        if ((((-1 < iVar2) &&
             (iVar2 = (**(code **)(*param_1 + 0x54))(0xb0000000,0x10000), -1 < iVar2)) &&
            (iVar2 = (**(code **)(*param_1 + 100))(iVar1,&local_10,&local_8), -1 < iVar2)) &&
           (((iVar2 = (**(code **)(*param_1 + 0x68))(&param_2,1,0x10000,&local_c), -1 < iVar2 &&
             (iVar2 = (**(code **)(*param_1 + 0x58))(local_10,local_c,local_8), -1 < iVar2)) &&
            ((iVar2 = (**(code **)(*param_1 + 0x50))(), -1 < iVar2 &&
             (iVar2 = FUN_0061663f(), -1 < iVar2)))))) {
          param_1[0x33] = param_2;
          iVar2 = 0;
        }
      }
    }
  }
  return iVar2;
}


// ==== 0x611a36 FUN_00611a36

int __thiscall FUN_00611a36(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = FUN_0061a36a(param_2 | param_3);
  if (-1 < iVar2) {
    if ((((param_2 | param_3) & 0x2000) != 0) && (0x1ff < (*(uint *)(param_1 + 0x30) & 0xffff))) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x14) + param_4 * 4);
      iVar1 = *(int *)(iVar2 + 0xc);
      uVar3 = *(uint *)(iVar2 + 8) & 0x7ff;
      uVar4 = uVar3 | 0xb0000000;
      if (iVar1 != 0) {
        if (iVar1 == 1) {
          uVar4 = uVar3 | 0xb0550000;
        }
        else if (iVar1 == 2) {
          uVar4 = uVar3 | 0xb0aa0000;
        }
        else if (iVar1 == 3) {
          uVar4 = uVar3 | 0xb0ff0000;
        }
      }
      FUN_0061a36a(uVar4);
    }
    iVar2 = 0;
  }
  return iVar2;
}


// ==== 0x611aad FUN_00611aad

int __fastcall FUN_00611aad(int param_1)

{
  if (*(int *)(param_1 + 0xec) == 0) {
    return 0;
  }
  return *(int *)(param_1 + 0x14c) + *(int *)(param_1 + 0x148) + *(int *)(param_1 + 0x128);
}


// ==== 0x611acc FUN_00611acc

int __thiscall FUN_00611acc(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 local_24 [32];
  
  if (*(int *)(param_1 + 0xec) == 0) {
    iVar1 = FUN_0061a5d9(param_2,param_3);
  }
  else {
    _sprintf(local_24,"c_$zz%d",param_2);
    iVar1 = FUN_005e7078(local_24,param_2,1);
    if (-1 < iVar1) {
      iVar1 = FUN_005e54f8(local_24);
      *(undefined4 *)(iVar1 + 0xc) = 1;
      *(undefined4 *)(iVar1 + 0x10) = *param_3;
      *(undefined4 *)(iVar1 + 0x14) = param_3[1];
      *(undefined4 *)(iVar1 + 0x18) = param_3[2];
      *(undefined4 *)(iVar1 + 0x1c) = param_3[3];
      *(int *)(param_1 + 0x14c) = *(int *)(param_1 + 0x14c) + 1;
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ==== 0x611b44 FUN_00611b44

int __thiscall FUN_00611b44(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  undefined1 local_3c [32];
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  undefined4 local_10;
  void *local_c;
  int local_8;
  
  uVar4 = 0;
  local_8 = 0;
  local_c = (void *)0x0;
  if (*(int *)(param_1 + 0xec) == 0) {
    local_8 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x128) + *(int *)(param_1 + 0x148) + *(int *)(param_1 + 0x14c);
    if (iVar2 != 0) {
      local_c = _malloc(iVar2 * 4);
      if (local_c == (void *)0x0) {
        local_8 = -0x7ff8fff2;
      }
      else {
        if (*(int *)(param_1 + 0x70) != 0) {
          do {
            _sprintf(local_3c,"r_$Int%d",uVar4);
            local_8 = FUN_005e7078(local_3c,uVar4,1);
            if (local_8 < 0) goto LAB_00611cea;
            uVar4 = uVar4 + 1;
          } while (uVar4 < *(uint *)(param_1 + 0x70));
        }
        pvVar3 = local_c;
        FUN_005e552a(local_c);
        iVar2 = *(int *)(param_1 + 0x128) + *(int *)(param_1 + 0x14c);
        FUN_005e552a((void *)((int)pvVar3 + iVar2 * 4));
        uVar4 = iVar2 + *(int *)(param_1 + 0x148);
        _qsort(pvVar3,uVar4,4,FUN_005e6a37);
        local_1c = 1;
        local_1a = 3;
        local_18 = 1;
        local_16 = 4;
        local_14 = 1;
        local_12 = 0;
        local_10 = 0;
        param_3 = param_3 + param_4 * 0x14;
        param_4 = 0;
        if (uVar4 != 0) {
          do {
            piVar1 = (int *)((int)pvVar3 + param_4 * 4);
            local_8 = FUN_0061319b(*(undefined4 *)*piVar1,0xffffffff,7,param_3);
            if ((local_8 < 0) ||
               (local_8 = FUN_0061319b(&local_1c,0x10,6,param_3 + 0xc), local_8 < 0))
            goto LAB_00611cea;
            if (*(int *)(*piVar1 + 0xc) != 0) {
              *(byte *)(param_3 + 10) = *(byte *)(param_3 + 10) | 1;
              local_8 = FUN_0061319b(*piVar1 + 0x10,0x10,7,param_3 + 0x10);
              if (local_8 < 0) goto LAB_00611cea;
            }
            param_4 = param_4 + 1;
            *(undefined2 *)(param_3 + 4) = 2;
            *(undefined2 *)(param_3 + 6) = *(undefined2 *)(*piVar1 + 4);
            *(undefined2 *)(param_3 + 8) = 1;
            param_3 = param_3 + 0x14;
            pvVar3 = local_c;
          } while (param_4 < uVar4);
        }
        local_8 = 0;
      }
    }
LAB_00611cea:
    _free(local_c);
  }
  return local_8;
}


// ==== 0x611cfc FUN_00611cfc

undefined4 __thiscall FUN_00611cfc(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 local_1c [4];
  uint local_18;
  int local_10;
  char *local_c;
  char *local_8;
  
  local_8 = (char *)0x0;
  local_c = (char *)0x0;
  if (*(int *)(param_1 + 0xec) == 0) {
    return 0;
  }
  iVar2 = *(int *)(param_2 + 0x30);
  pcVar6 = (char *)0x0;
  local_10 = param_1;
  if (iVar2 != 0) {
    do {
      iVar1 = *(int *)(iVar2 + 8);
      pcVar7 = pcVar6;
      if (*(int *)(iVar1 + 4) == 0x10) {
        iVar4 = 0;
        if (*(int *)(iVar1 + 0x10) != 0) {
          iVar4 = *(int *)(*(int *)(iVar1 + 0x10) + 0x18);
        }
        if (*(int *)(iVar1 + 0x14) == 0) {
          pcVar5 = (char *)0x0;
        }
        else {
          pcVar5 = *(char **)(*(int *)(iVar1 + 0x14) + 0x18);
        }
        if (iVar4 == 0) {
          iVar1 = _tolower((int)*pcVar5);
          if (iVar1 == 99) {
            local_c = pcVar5;
          }
        }
        else {
          iVar1 = FUN_005d7700(iVar4,0,local_1c);
          if ((((-1 < iVar1) && (iVar1 = _tolower((int)*pcVar5), iVar1 == 99)) &&
              (pcVar7 = pcVar5, *(uint *)(local_10 + 0x30) != local_18)) &&
             ((pcVar7 = pcVar6, ((*(uint *)(local_10 + 0x30) ^ local_18) & 0xffff0000) == 0 &&
              ((short)local_18 == 0)))) {
            local_8 = pcVar5;
          }
        }
      }
      iVar2 = *(int *)(iVar2 + 0xc);
      pcVar6 = pcVar7;
    } while (iVar2 != 0);
    if (pcVar7 != (char *)0x0) goto LAB_00611dc6;
  }
  pcVar7 = local_8;
  if ((local_8 == (char *)0x0) && (pcVar7 = local_c, local_c == (char *)0x0)) {
    return 0;
  }
LAB_00611dc6:
  iVar2 = _tolower((int)*pcVar7);
  if (iVar2 == 99) {
    iVar2 = _isdigit((int)pcVar7[1]);
    if (iVar2 != 0) {
      pcVar6 = pcVar7 + 2;
      while (iVar2 = _isdigit((int)*pcVar6), iVar2 != 0) {
        pcVar6 = pcVar6 + 1;
      }
      if (*pcVar6 == '\0') {
        uVar3 = _atoi(pcVar7 + 1);
        if (0x1fff < uVar3) {
          FUN_005fbec8(local_10,0,0,
                       "Constant variable \'%s\' bound to register greater than 8191 (%d requested)"
                       ,pcVar7 + 2,uVar3);
          return 0x80004005;
        }
        *(ushort *)(param_3 + 10) = *(ushort *)(param_3 + 10) | (ushort)(uVar3 << 2) | 2;
      }
    }
  }
  return 0;
}


// ==== 0x611e41 FUN_00611e41

undefined4 * __thiscall FUN_00611e41(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_006137a9();
  *param_1 = &PTR_FUN_006a5f20;
  puVar2 = param_1 + 0x43;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = param_1 + 0x4b;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x3b] = param_2;
  return param_1;
}


// ==== 0x611e87 FUN_00611e87

void __fastcall FUN_00611e87(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a5f20;
  FUN_005e7004();
  FUN_005e7004();
  FUN_00613825();
  return;
}


// ==== 0x611eae FUN_00611eae

int __fastcall FUN_00611eae(int param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  void *pvVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint local_50 [5];
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int *local_2c;
  uint *local_28;
  uint *local_24;
  uint local_20;
  int *local_1c;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  local_10 = **(uint **)(param_1 + 0x98) & 0xffffff;
  local_18 = param_1;
  if (local_10 == 0) {
    return 1;
  }
  local_50[4] = (*(uint **)(param_1 + 0x98))[1] / local_10;
  local_38 = 0;
  if (local_50[4] != 0) {
    local_34 = 0;
    do {
      iVar10 = -1;
      local_50[0] = 0xffffffff;
      local_50[1] = 0xffffffff;
      local_50[2] = 0xffffffff;
      local_8 = 0;
      local_2c = (int *)0x0;
      local_1c = (int *)0x0;
      local_24 = (uint *)0x0;
      local_28 = (uint *)0x0;
      local_50[3] = 0xffffffff;
      local_14 = -1;
      local_c = -1;
      if (local_10 != 0) {
        piVar11 = (int *)(*(int *)(*(int *)(param_1 + 0x98) + 8) + local_34);
        local_30 = local_10;
        do {
          iVar9 = *piVar11;
          iVar1 = *(int *)(*(int *)(param_1 + 0x14) + iVar9 * 4);
          iVar2 = *(int *)(iVar1 + 0xc);
          if (iVar2 == 0) {
            uVar4 = *(uint *)(iVar1 + 0x2c);
            if (uVar4 != 0xffffffff) {
              local_2c = *(int **)(*(int *)(param_1 + 0x18) + uVar4 * 4);
LAB_00612046:
              local_50[local_8] = uVar4;
              goto LAB_0061204d;
            }
          }
          else if (iVar2 == 1) {
            uVar4 = *(uint *)(iVar1 + 0x2c);
            if (uVar4 != 0xffffffff) {
              local_1c = *(int **)(*(int *)(param_1 + 0x18) + uVar4 * 4);
              goto LAB_00612046;
            }
          }
          else {
            if (iVar2 == 2) {
              iVar1 = *(int *)(iVar1 + 0x2c);
              local_50[local_8] = 0xffffffff;
              local_14 = iVar9;
              iVar10 = iVar9;
              if (iVar1 != -1) {
                local_24 = *(uint **)(*(int *)(param_1 + 0x18) + iVar1 * 4);
                if ((*local_24 & 0xff000000) == 0x10000000) {
                  uVar6 = 0;
                  uVar4 = *local_24 & 0xffffff;
                  if (uVar4 != 0) {
                    piVar8 = (int *)local_24[4];
                    do {
                      if (*piVar8 == iVar9) {
                        local_14 = *(int *)(local_24[2] + uVar6 * 4);
                        iVar10 = local_14;
                        break;
                      }
                      uVar6 = uVar6 + 1;
                      piVar8 = piVar8 + 1;
                    } while (uVar6 < uVar4);
                  }
                }
                else {
                  local_24 = (uint *)0x0;
                }
              }
            }
            else {
              if (iVar2 != 3) goto LAB_00612050;
              iVar1 = *(int *)(iVar1 + 0x2c);
              local_c = iVar9;
              local_50[local_8] = 0xffffffff;
              if (iVar1 != -1) {
                local_28 = *(uint **)(*(int *)(param_1 + 0x18) + iVar1 * 4);
                if ((*local_28 & 0xff000000) == 0x10000000) {
                  uVar6 = 0;
                  uVar4 = *local_28 & 0xffffff;
                  if (uVar4 != 0) {
                    piVar8 = (int *)local_28[4];
                    do {
                      iVar10 = local_14;
                      if (*piVar8 == local_c) {
                        local_c = *(int *)(local_28[2] + uVar6 * 4);
                        break;
                      }
                      uVar6 = uVar6 + 1;
                      piVar8 = piVar8 + 1;
                    } while (uVar6 < uVar4);
                  }
                }
                else {
                  local_28 = (uint *)0x0;
                }
              }
            }
LAB_0061204d:
            local_8 = local_8 + 1;
          }
LAB_00612050:
          piVar11 = piVar11 + 1;
          local_30 = local_30 - 1;
        } while (local_30 != 0);
      }
      if ((local_8 == local_10) && (1 < local_8)) {
        bVar3 = false;
        if (local_1c != (int *)0x0) {
          if (*local_1c != 0x25000001) goto LAB_006120ca;
          if (((iVar10 != -1) && (iVar10 != *(int *)local_1c[2])) &&
             (iVar10 != ((int *)local_1c[2])[1])) {
            bVar3 = true;
          }
          if (local_c != -1) {
            piVar11 = (int *)local_1c[2];
            iVar9 = *piVar11;
            if ((local_c != iVar9) && (local_c != piVar11[1])) {
              bVar3 = true;
            }
            if (iVar10 != -1) {
              if (local_c == iVar10) {
                if (iVar9 != piVar11[1]) goto LAB_006120ca;
              }
              else if (iVar9 == piVar11[1]) {
LAB_006120ca:
                bVar3 = true;
              }
            }
          }
        }
        if (local_2c != (int *)0x0) {
          if (*local_2c != 0x10000001) goto LAB_006121ce;
          piVar11 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)local_2c[2] * 4);
          if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar11 * 4) + 4) & 0x80) == 0) ||
             (*(double *)(piVar11 + 4) != 1.0)) {
            bVar3 = true;
          }
        }
        if (!bVar3) {
          local_2c = (int *)0x0;
          local_20 = local_10;
          if (local_8 != 0) {
            do {
              uVar4 = local_50[(int)local_2c];
              if (uVar4 != 0xffffffff) {
                local_30 = 1;
                if (local_10 != 0) {
                  piVar11 = (int *)(*(int *)(*(int *)(param_1 + 0x98) + 8) + local_34);
                  local_3c = local_10;
                  do {
                    iVar10 = *(int *)(*(int *)(param_1 + 0x14) + *piVar11 * 4);
                    if (*(uint *)(iVar10 + 0x34) < *(uint *)(param_1 + 0x94)) {
                      local_30 = 0;
                    }
                    if (uVar4 < *(uint *)(iVar10 + 0x30)) {
                      local_30 = 0;
                    }
                    if (((local_24 == (uint *)0x0) && (*(int *)(iVar10 + 0xc) == 2)) ||
                       ((local_28 == (uint *)0x0 && (*(int *)(iVar10 + 0xc) == 3)))) {
                      local_20 = local_20 - 1;
                    }
                    else if (*(uint *)(iVar10 + 0x38) < uVar4) {
                      local_30 = 0;
                    }
                    piVar11 = piVar11 + 1;
                    local_3c = local_3c - 1;
                  } while (local_3c != 0);
                  param_1 = local_18;
                  if (local_30 == 0) goto LAB_006121a8;
                }
                local_3c = local_50[(int)local_2c];
                if ((local_50[(int)local_2c] != 0xffffffff) && (1 < local_20)) {
                  pvVar5 = _malloc(0x38);
                  if (pvVar5 == (void *)0x0) {
                    uVar4 = 0;
                  }
                  else {
                    uVar4 = FUN_005f7709();
                  }
                  uVar6 = local_20;
                  if (uVar4 == 0) {
                    return -0x7ff8fff2;
                  }
                  local_30 = uVar4;
                  iVar10 = FUN_005f7760(local_20 & 0xffffff | 0xfb000000,local_20 * 2,local_20,0);
                  if ((iVar10 < 0) ||
                     (iVar10 = FUN_005f7a42(*(undefined4 *)(param_1 + 0x98)), iVar10 < 0))
                  goto LAB_00612412;
                  uVar7 = 0;
                  if (uVar6 == 0) goto LAB_006122c6;
                  iVar10 = uVar6 << 2;
                  goto LAB_0061225a;
                }
                break;
              }
LAB_006121a8:
              local_2c = (int *)((int)local_2c + 1);
            } while (local_2c < local_8);
          }
        }
      }
LAB_006121ce:
      local_38 = local_38 + 1;
      local_34 = local_34 + local_10 * 4;
    } while (local_38 < local_50[4]);
  }
  return 1;
LAB_0061225a:
  do {
    if (local_1c == (int *)0x0) {
      if (local_c == -1) {
        iVar9 = local_14;
        if (local_14 != -1) {
LAB_006122b1:
          *(int *)(*(int *)(uVar4 + 8) + uVar7 * 4) = iVar9;
          goto LAB_006122b7;
        }
      }
      else {
        iVar9 = local_c;
        if (local_14 == -1) goto LAB_006122b1;
      }
      uVar13 = 0x12d9;
      uVar12 = *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x34);
      goto LAB_0061229b;
    }
    *(undefined4 *)(*(int *)(uVar4 + 8) + uVar7 * 4) = *(undefined4 *)local_1c[2];
    iVar9 = *(int *)(local_1c[2] + 4);
LAB_006122b7:
    *(int *)(iVar10 + *(int *)(uVar4 + 8)) = iVar9;
    uVar7 = uVar7 + 1;
    iVar10 = iVar10 + 4;
  } while (uVar7 < local_20);
LAB_006122c6:
  uVar6 = 0;
  local_34 = 0;
  if (local_10 != 0) {
    iVar10 = local_38 * local_50[4] * 4;
    do {
      iVar9 = *(int *)(iVar10 + *(int *)(*(int *)(param_1 + 0x98) + 8));
      iVar1 = *(int *)(*(int *)(param_1 + 0x14) + iVar9 * 4);
      if (((local_24 != (uint *)0x0) || (*(int *)(iVar1 + 0xc) != 2)) &&
         ((local_28 != (uint *)0x0 || (*(int *)(iVar1 + 0xc) != 3)))) {
        *(int *)(*(int *)(uVar4 + 0x10) + uVar6 * 4) = iVar9;
        uVar6 = uVar6 + 1;
      }
      if (local_20 < uVar6) {
        uVar13 = 0x12da;
        uVar12 = *(undefined4 *)(*(int *)(local_18 + 0x98) + 0x34);
        param_1 = local_18;
LAB_0061229b:
        FUN_005fbec8(param_1,uVar12,uVar13,"internal error: DST test failure");
        iVar10 = 1;
LAB_00612412:
        FUN_005f7186(1);
        return iVar10;
      }
      local_34 = local_34 + 1;
      iVar10 = iVar10 + 4;
      param_1 = local_18;
    } while (local_34 < local_10);
  }
  uVar6 = *(uint *)(uVar4 + 0xc);
  local_2c = (int *)0x0;
  if (uVar6 != 0) {
    local_34 = 1;
    do {
      local_38 = local_34;
      if (local_34 < uVar6) {
        do {
          iVar10 = *(int *)(*(int *)(uVar4 + 0x10) + (int)local_2c * 4);
          iVar9 = *(int *)(*(int *)(param_1 + 0x14) + iVar10 * 4);
          piVar11 = (int *)(*(int *)(uVar4 + 0x10) + local_38 * 4);
          iVar1 = *piVar11;
          iVar2 = *(int *)(*(int *)(param_1 + 0x14) + iVar1 * 4);
          if (*(uint *)(iVar2 + 0xc) < *(uint *)(iVar9 + 0xc)) {
            *piVar11 = iVar10;
            *(int *)(*(int *)(local_30 + 0x10) + (int)local_2c * 4) = iVar1;
          }
          if (*(int *)(iVar9 + 0xc) == *(int *)(iVar2 + 0xc)) {
            FUN_005fbec8(local_18,*(undefined4 *)(*(int *)(local_18 + 0x98) + 0x34),0x12db,
                         "internal error: multiple write to same output");
            iVar10 = -0x7fffbffb;
            goto LAB_00612412;
          }
          local_38 = local_38 + 1;
          uVar4 = local_30;
          param_1 = local_18;
        } while (local_38 < *(uint *)(local_30 + 0xc));
      }
      local_2c = (int *)((int)local_2c + 1);
      uVar6 = *(uint *)(uVar4 + 0xc);
      local_34 = local_34 + 1;
    } while (local_2c < uVar6);
  }
  uVar6 = 0;
  if (local_8 != 0) {
    do {
      if (local_50[uVar6] != 0xffffffff) {
        **(undefined4 **)(*(int *)(param_1 + 0x18) + local_50[uVar6] * 4) = 0;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < local_8);
  }
  if (local_24 != (uint *)0x0) {
    if (*local_24 == 0x10000001) {
      *local_24 = 0;
    }
    else if (*local_24 == 0x10000002) {
      piVar11 = (int *)local_24[2];
      if ((*piVar11 == local_14) && (piVar11[1] == local_c)) {
        *local_24 = 0;
      }
      if ((piVar11[1] == local_14) && (*piVar11 == local_c)) {
        *local_24 = 0;
      }
    }
  }
  if (local_28 == (uint *)0x0) goto LAB_00612485;
  if (*local_28 != 0x10000001) {
    if (*local_28 != 0x10000002) goto LAB_00612485;
    piVar11 = (int *)local_28[2];
    if ((*piVar11 == local_14) && (piVar11[1] == local_c)) {
      *local_28 = 0;
    }
    if ((piVar11[1] != local_14) || (*piVar11 != local_c)) goto LAB_00612485;
  }
  *local_28 = 0;
LAB_00612485:
  iVar10 = local_3c * 4;
  if (*(int *)(iVar10 + *(int *)(param_1 + 0x18)) != 0) {
    FUN_005f7186(1);
  }
  *(uint *)(iVar10 + *(int *)(param_1 + 0x18)) = uVar4;
  return 0;
}


// ==== 0x6124a9 FUN_006124a9

int __fastcall FUN_006124a9(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar4;
      *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(*(int *)(param_1 + 0x18) + uVar4 * 4);
      iVar2 = FUN_00611eae();
      if (iVar2 == 0) {
        FUN_0061674c();
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 0xc));
  }
  uVar4 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar4;
      puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + uVar4 * 4);
      *(uint **)(param_1 + 0x98) = puVar1;
      uVar3 = *puVar1 & 0xff000000;
      if (uVar3 == 0x11000000) {
        iVar2 = FUN_006178e1();
LAB_00612588:
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      else {
        if (uVar3 == 0x16000000) {
          iVar2 = FUN_00618431();
          goto LAB_00612588;
        }
        if (uVar3 != 0x21000000) {
          if (uVar3 == 0x24000000) {
            if (0x1ff < (*(uint *)(param_1 + 0x30) & 0xffff)) {
              FUN_00618709();
            }
            iVar2 = FUN_00617905();
          }
          else if (uVar3 == 0x25000000) {
            iVar2 = FUN_00618a35();
          }
          else {
            if (uVar3 != 0x30000000) goto LAB_00612590;
            iVar2 = FUN_0060ff02();
          }
          goto LAB_00612588;
        }
        if (0x1ff < (*(uint *)(param_1 + 0x30) & 0xffff)) {
          iVar2 = FUN_00614bc0();
          goto LAB_00612588;
        }
      }
LAB_00612590:
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 0xc));
  }
  FUN_0061674c();
  FUN_00614972();
  uVar4 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar4;
      puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + uVar4 * 4);
      *(uint **)(param_1 + 0x98) = puVar1;
      uVar3 = *puVar1 & 0xff000000;
      if ((((uVar3 == 0x12000000) || (uVar3 == 0x14000000)) || (uVar3 == 0x15000000)) ||
         (((uVar3 == 0x30000000 || (uVar3 == 0xf3000000)) || (uVar3 == 0xf4000000)))) {
        iVar2 = FUN_00614682();
LAB_00612617:
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      else if (uVar3 == 0xf5000000) {
        if ((*(uint *)(param_1 + 0x30) & 0xffff) < 0x200) {
          iVar2 = 1;
        }
        else {
          iVar2 = FUN_0061858f();
        }
        goto LAB_00612617;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 0xc));
  }
  return 0;
}


// ==== 0x612628 FUN_00612628

int __fastcall FUN_00612628(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  if (((*(uint *)(param_1 + 0x30) & 0xffff) < 0x200) &&
     (iVar3 = *(int *)(param_1 + 0x98), *(char *)(iVar3 + 3) != '\0')) {
    uVar4 = 0;
    if (*(uint *)(iVar3 + 4) != 0) {
      piVar2 = *(int **)(iVar3 + 8);
      do {
        iVar1 = *(int *)(*(int *)(param_1 + 0x14) + *piVar2 * 4);
        if (*(int *)(iVar1 + 4) != -1) {
          iVar3 = FUN_0061193a(*(undefined4 *)(iVar1 + 4));
          if (-1 < iVar3) {
            return 0;
          }
          return iVar3;
        }
        uVar4 = uVar4 + 1;
        piVar2 = piVar2 + 1;
      } while (uVar4 < *(uint *)(iVar3 + 4));
    }
    return 0;
  }
  return 0;
}


// ==== 0x612646 FUN_00612646

int __fastcall FUN_00612646(int param_1)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(uint *)(in_EAX + 4) != 0) {
    piVar1 = *(int **)(in_EAX + 8);
    do {
      iVar2 = *(int *)(*(int *)(param_1 + 0x14) + *piVar1 * 4);
      if (*(int *)(iVar2 + 4) != -1) {
        iVar2 = FUN_0061193a(*(undefined4 *)(iVar2 + 4));
        if (-1 < iVar2) {
          return 0;
        }
        return iVar2;
      }
      uVar3 = uVar3 + 1;
      piVar1 = piVar1 + 1;
    } while (uVar3 < *(uint *)(in_EAX + 4));
  }
  return 0;
}


// ==== 0x61267f FUN_0061267f

void * __thiscall FUN_0061267f(void *param_1,byte param_2)

{
  FUN_00611e87();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x61269b FUN_0061269b

int __fastcall FUN_0061269b(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar3;
      iVar1 = *(int *)(*(int *)(param_1 + 0x18) + uVar3 * 4);
      *(int *)(param_1 + 0x98) = iVar1;
      iVar1 = *(int *)(iVar1 + 0x34);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) == 0xc)) {
        *(int *)(param_1 + 0x9c) = iVar1 + 0x30;
      }
      iVar1 = FUN_00612628();
      if (iVar1 < 0) {
        return iVar1;
      }
      uVar2 = **(uint **)(param_1 + 0x98) & 0xff000000;
      if (uVar2 < 0x25000001) {
        if (uVar2 == 0x25000000) {
          iVar1 = FUN_0061b2ea();
        }
        else if (uVar2 < 0x15000001) {
          if (uVar2 == 0x15000000) {
            iVar1 = FUN_006118de();
          }
          else if (uVar2 == 0) {
            iVar1 = FUN_0067ef25();
          }
          else if (uVar2 == 0x10000000) {
            iVar1 = FUN_0061b0f2();
          }
          else if (uVar2 == 0x11000000) {
            iVar1 = FUN_0061a926();
          }
          else if (uVar2 == 0x12000000) {
            iVar1 = FUN_0061b1e6();
          }
          else if (uVar2 == 0x13000000) {
            iVar1 = FUN_0061141a();
          }
          else {
            if (uVar2 != 0x14000000) goto LAB_006128dd;
            iVar1 = FUN_006116da();
          }
        }
        else if (uVar2 == 0x16000000) {
          iVar1 = FUN_0061b248();
        }
        else if (uVar2 == 0x20000000) {
          iVar1 = FUN_0061b2c2();
        }
        else if (uVar2 == 0x21000000) {
          iVar1 = FUN_0061b2ca();
        }
        else if (uVar2 == 0x22000000) {
          iVar1 = FUN_0061b2d2();
        }
        else if (uVar2 == 0x23000000) {
          iVar1 = FUN_0061b2da();
        }
        else {
          if (uVar2 != 0x24000000) goto LAB_006128dd;
          iVar1 = FUN_0061b2e2();
        }
      }
      else if (uVar2 < 0xf4000001) {
        if (uVar2 == 0xf4000000) {
LAB_0061284c:
          iVar1 = FUN_0061b3b4();
        }
        else if (uVar2 == 0x30000000) {
          iVar1 = FUN_0061b2fa();
        }
        else if (uVar2 == 0x33000000) {
          iVar1 = FUN_0061b39c();
        }
        else if (uVar2 == 0xf0000000) {
          iVar1 = FUN_0061b3ac();
        }
        else if (uVar2 == 0xf1000000) {
          iVar1 = FUN_0061aa11();
        }
        else {
          if (uVar2 != 0xf2000000) {
            if (uVar2 != 0xf3000000) goto LAB_006128dd;
            goto LAB_0061284c;
          }
          iVar1 = FUN_0061ab23();
        }
      }
      else if ((uVar2 == 0xf5000000) || (uVar2 == 0xf6000000)) {
        iVar1 = FUN_0061abc1();
      }
      else if (((uVar2 == 0xf7000000) || (uVar2 == 0xf8000000)) || (uVar2 == 0xf9000000)) {
        iVar1 = FUN_0061acf6();
      }
      else {
        if (uVar2 != 0xfb000000) goto LAB_006128dd;
        iVar1 = FUN_0061b2f2();
      }
      if (iVar1 == -0x7fffbfff) {
LAB_006128dd:
        FUN_005fbec8(param_1,*(undefined4 *)(*(int *)(param_1 + 0x98) + 0x34),0x11b4,
                     "cannot map expression to vertex shader instruction set");
        return -0x7fffbfff;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 0xc));
  }
  return 0;
}


// ==== 0x612900 FUN_00612900

undefined4 * __fastcall FUN_00612900(undefined4 *param_1)

{
  FUN_006137a9();
  param_1[0x43] = 0;
  *param_1 = &PTR_FUN_006a6030;
  return param_1;
}


// ==== 0x612919 FUN_00612919

undefined4 __fastcall FUN_00612919(int param_1)

{
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0x40;
  *(undefined4 *)(param_1 + 0x70) = 0x40;
  *(undefined4 *)(param_1 + 0x78) = 0x2000;
  *(uint *)(param_1 + 0x90) = *(uint *)(param_1 + 0x90) & 0xfffffffc | 0x100;
  return 0;
}


// ==== 0x612943 FUN_00612943

undefined4 __thiscall FUN_00612943(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x14) + param_2 * 4);
  if ((((puVar2[1] == -1) || (iVar3 = FUN_00612943(puVar2[1],param_3), -1 < iVar3)) &&
      (iVar3 = FUN_00618c39(*puVar2), -1 < iVar3)) &&
     (iVar3 = FUN_00618c39(puVar2[3] + puVar2[2] * 4), -1 < iVar3)) {
    piVar1 = (int *)(*(int *)(param_1 + 0xa0) + param_3 * 4);
    *piVar1 = *piVar1 + 1;
    return 0;
  }
  return 0x8007000e;
}


// ==== 0x6129a7 FUN_006129a7

undefined4 __thiscall FUN_006129a7(int param_1,int *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *(uint *)(*(int *)(*(int *)(param_1 + 0x10) + *param_2 * 4) + 4);
  if ((uVar1 & 0x80) == 0) {
    if (((uVar1 & 0x100) == 0) || ((uVar1 & 0x40) == 0)) {
      if ((uVar1 & 0x100) == 0) {
        if ((uVar1 & 8) == 0) {
          if ((uVar1 & 0x10) == 0) {
            if (((uVar1 & 1) == 0) || ((uVar1 & 2) == 0)) {
              if (((uVar1 & 2) == 0) || ((uVar1 & 4) == 0)) {
                return 0x80004005;
              }
              uVar2 = 6;
            }
            else {
              uVar2 = 5;
            }
          }
          else {
            uVar2 = 4;
          }
        }
        else {
          uVar2 = 3;
        }
      }
      else {
        uVar2 = 2;
      }
    }
    else {
      uVar2 = 7;
    }
    uVar2 = FUN_00618c39(uVar2);
  }
  else {
    uVar2 = FUN_00618c39(1);
  }
  return uVar2;
}


// ==== 0x612a3c FUN_00612a3c

int __thiscall FUN_00612a3c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = FUN_00615e2f(2);
  if (-1 < iVar3) {
    iVar3 = *(int *)(param_1 + 0xa0);
    piVar1 = (int *)(param_1 + 0xa4);
    iVar2 = *piVar1;
    *(undefined4 *)(iVar3 + iVar2 * 4) = param_2;
    *(undefined4 *)(iVar3 + 4 + iVar2 * 4) = param_3;
    *piVar1 = *piVar1 + 2;
    iVar3 = 0;
  }
  return iVar3;
}


// ==== 0x612a70 FUN_00612a70

uint __thiscall FUN_00612a70(int param_1,int *param_2)

{
  uint uVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  long lVar6;
  uint uVar7;
  bool bVar8;
  bool bVar9;
  char local_2c [32];
  int local_c;
  uint local_8;
  
  lVar6 = 0;
  local_8 = 0;
  if ((*(uint *)(param_1 + 0x30) & 0xffff0000) == 0x46580000) {
    if (param_2[0x14] == -1) {
      piVar3 = (int *)(param_1 + 0x10c);
      param_2[0x14] = *piVar3;
      *piVar3 = *piVar3 + 1;
    }
    return 0;
  }
  if (param_2[0x14] != -1) {
    return 0;
  }
  local_c = param_1;
  _strncpy(local_2c,*(char **)(param_2[0x13] + 0x18),0x20);
  pcVar5 = local_2c;
  if (local_2c[0] == '\0') {
LAB_00612aff:
    if (*pcVar5 != '\0') {
      *pcVar5 = '\0';
      pcVar5 = pcVar5 + 1;
    }
  }
  else {
    do {
      iVar4 = _isalpha((int)*pcVar5);
      if (iVar4 == 0) break;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar5 != '\0');
    if (*pcVar5 != '\0') {
      lVar6 = _atoi(pcVar5);
      goto LAB_00612aff;
    }
  }
  cVar2 = *pcVar5;
  if (cVar2 == '\0') {
LAB_00612b2d:
    uVar7 = lVar6 + ((uint)param_2[0x15] >> 2);
  }
  else {
    do {
      iVar4 = _isdigit((int)cVar2);
      if (iVar4 == 0) break;
      pcVar5 = pcVar5 + 1;
      cVar2 = *pcVar5;
    } while (cVar2 != '\0');
    if (*pcVar5 == '\0') goto LAB_00612b2d;
    uVar7 = 0xffffffff;
  }
  uVar1 = *(uint *)(*(int *)(*(int *)(local_c + 0x10) + *param_2 * 4) + 4);
  if (((uVar1 & 8) == 0) || ((uVar1 & 0x100) != 0)) {
    if ((uVar1 & 0x10) != 0) {
      iVar4 = __stricmp(local_2c,"color");
      bVar9 = iVar4 != 0;
      bVar8 = bVar9 || uVar7 != 0;
      local_8 = (uint)!bVar9;
      if ((bVar9 || uVar7 != 0) && (param_2[3] == 0)) {
        pcVar5 = "invalid reference to output semantic \'%s%d\'";
        goto LAB_00612be7;
      }
      goto LAB_00612bfa;
    }
  }
  else {
    iVar4 = __stricmp(local_2c,"position");
    if (iVar4 == 0) {
      local_8 = 2;
LAB_00612b67:
      bVar8 = uVar7 != 0;
    }
    else {
      iVar4 = __stricmp(local_2c,"psize");
      if (iVar4 == 0) {
        local_8 = 3;
        goto LAB_00612b67;
      }
      local_8 = 0;
      bVar8 = true;
    }
    if ((bVar8) && (param_2[3] == 0)) {
      pcVar5 = "invalid reference to input semantic \'%s%d\'";
LAB_00612be7:
      FUN_005fbec8(local_c,param_2[0x13],0x1196,pcVar5,local_2c,uVar7);
    }
LAB_00612bfa:
    if (local_8 != 0) goto LAB_00612c07;
  }
  bVar8 = true;
LAB_00612c07:
  if (0xffff < uVar7) {
    bVar8 = true;
  }
  param_2[0x14] = (uVar7 | 0xffffff00) << 8 | local_8 & 0xff;
  return -(uint)bVar8 & 0x80004005;
}


// ==== 0x612c37 FUN_00612c37

undefined4 * __thiscall FUN_00612c37(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a6030;
  FUN_00613825();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x612c59 FUN_00612c59

int __thiscall FUN_00612c59(int param_1,uint *param_2,int *param_3)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  uint local_18;
  uint local_10;
  undefined4 *local_c;
  
  local_c = (undefined4 *)0x0;
  iVar6 = FUN_00602b25(param_2,param_3);
  if (-1 < iVar6) {
    local_18 = *(int *)(param_1 + 8);
    param_3 = (int *)0x0;
    local_10 = 0;
    if (local_18 != 0) {
      piVar11 = *(int **)(param_1 + 0x14);
      do {
        piVar2 = (int *)*piVar11;
        if ((((*(int *)(param_1 + 0x50) != *piVar2) ||
             (piVar5 = (int *)(piVar2[2] + 1), (int *)(piVar2[2] + 1) <= param_3)) &&
            (piVar5 = param_3, *(int *)(param_1 + 0x60) == *piVar2)) && (local_10 < piVar2[2] + 1U))
        {
          local_10 = piVar2[2] + 1U;
        }
        param_3 = piVar5;
        piVar11 = piVar11 + 1;
        local_18 = local_18 + -1;
      } while (local_18 != 0);
    }
    piVar11 = param_3;
    local_c = _malloc((int)param_3 << 5);
    if (local_c == (undefined4 *)0x0) {
      iVar6 = -0x7ff8fff2;
    }
    else if (local_10 < 0x41) {
      puVar9 = local_c;
      for (iVar8 = ((uint)piVar11 & 0x7ffffff) << 3; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined1 *)puVar9 = 0;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      uVar10 = 0;
      if (*(int *)(param_1 + 8) != 0) {
        do {
          piVar11 = *(int **)(*(int *)(param_1 + 0x14) + uVar10 * 4);
          if ((*(int *)(param_1 + 0x50) == *piVar11) && (piVar11[1] == -1)) {
            *(undefined8 *)(local_c + (piVar11[3] + piVar11[2] * 4) * 2) =
                 *(undefined8 *)(piVar11 + 4);
          }
          if (*(int *)(param_1 + 0x30) == 0x54580100) {
            if (*(int *)(param_1 + 0x58) == *piVar11) {
              if ((uint)piVar11[2] < 2) {
                if ((piVar11[0x14] & 0xffU) == 2) {
                  piVar11[2] = 0;
                }
                else if ((piVar11[0x14] & 0xffU) == 3) {
                  piVar11[2] = 1;
                }
                goto LAB_00612d64;
              }
            }
            else {
LAB_00612d64:
              if ((*(int *)(param_1 + 0x5c) != *piVar11) || (piVar11[2] == 0)) goto LAB_00612d73;
            }
            FUN_005fbec8(param_1,0,0x1194);
            goto LAB_0061311d;
          }
LAB_00612d73:
          uVar10 = uVar10 + 1;
        } while (uVar10 < *(uint *)(param_1 + 8));
      }
      iVar6 = FUN_00618c39();
      if ((((-1 < iVar6) && (iVar6 = FUN_00618c64(), piVar11 = param_3, -1 < iVar6)) &&
          (iVar6 = FUN_00618c39(), -1 < iVar6)) && (iVar6 = FUN_00618c39(), -1 < iVar6)) {
        param_3 = (int *)((int)piVar11 << 2);
        iVar6 = FUN_00618c39();
        if (-1 < iVar6) {
          piVar11 = (int *)0x0;
          if (param_3 != (int *)0x0) {
            do {
              iVar6 = FUN_00612a3c(*(undefined8 *)(local_c + (int)piVar11 * 2));
              if (iVar6 < 0) goto LAB_0061311d;
              piVar11 = (int *)((int)piVar11 + 1);
            } while (piVar11 < param_3);
          }
          iVar8 = *(int *)(param_1 + 0xa4);
          iVar6 = FUN_00618c39();
          iVar12 = 0;
          if (((-1 < iVar6) && (iVar6 = FUN_00618c39(), -1 < iVar6)) &&
             (iVar6 = FUN_00618c39(), -1 < iVar6)) {
            local_18 = 0;
            if (*(int *)(param_1 + 0xc) != 0) {
              do {
                iVar6 = FUN_00618c39();
                if (((iVar6 < 0) || (iVar6 = FUN_00618c39(), iVar6 < 0)) ||
                   (iVar6 = FUN_00618c39(), iVar6 < 0)) goto LAB_0061311d;
                param_3 = (int *)0x0;
                piVar11 = (int *)(*(int *)(param_1 + 0xa0) + iVar8 * 4);
                *piVar11 = *piVar11 + 3;
                iVar6 = *(int *)(param_1 + 0x18);
                if (*(int *)(*(int *)(iVar12 + iVar6) + 4) != 0) {
                  do {
                    iVar3 = *(int *)(*(int *)(param_1 + 0x14) +
                                    *(int *)(*(int *)(*(int *)(iVar12 + iVar6) + 8) +
                                            (int)param_3 * 4) * 4);
                    iVar4 = *(int *)(param_1 + 0xa4);
                    iVar6 = FUN_00618c39();
                    if (((iVar6 < 0) ||
                        (((iVar6 = *(int *)(iVar3 + 4), iVar6 != -1 &&
                          (iVar6 = FUN_00612943(iVar6,iVar4), iVar6 < 0)) ||
                         (iVar6 = FUN_006129a7(), iVar6 < 0)))) ||
                       (iVar6 = FUN_00618c39(), iVar6 < 0)) goto LAB_0061311d;
                    piVar11 = (int *)(*(int *)(param_1 + 0xa0) + iVar8 * 4);
                    *piVar11 = *piVar11 + *(int *)(*(int *)(param_1 + 0xa0) + iVar4 * 4) * 2 + 3;
                    param_3 = (int *)((int)param_3 + 1);
                    iVar6 = *(int *)(param_1 + 0x18);
                  } while (param_3 < *(int **)(*(int *)(iVar12 + iVar6) + 4));
                }
                iVar6 = *(int *)(param_1 + 0x18);
                param_3 = (int *)0x0;
                if (*(int *)(*(int *)(iVar12 + iVar6) + 0xc) != 0) {
                  do {
                    iVar3 = *(int *)(*(int *)(param_1 + 0x14) +
                                    *(int *)(*(int *)(*(int *)(iVar12 + iVar6) + 0x10) +
                                            (int)param_3 * 4) * 4);
                    iVar4 = *(int *)(param_1 + 0xa4);
                    iVar6 = FUN_00618c39();
                    if ((((iVar6 < 0) ||
                         ((iVar6 = *(int *)(iVar3 + 4), iVar6 != -1 &&
                          (iVar6 = FUN_00612943(iVar6,iVar4), iVar6 < 0)))) ||
                        (iVar6 = FUN_006129a7(), iVar6 < 0)) || (iVar6 = FUN_00618c39(), iVar6 < 0))
                    goto LAB_0061311d;
                    piVar11 = (int *)(*(int *)(param_1 + 0xa0) + iVar8 * 4);
                    *piVar11 = *piVar11 + *(int *)(*(int *)(param_1 + 0xa0) + iVar4 * 4) * 2 + 3;
                    param_3 = (int *)((int)param_3 + 1);
                    iVar6 = *(int *)(param_1 + 0x18);
                  } while (param_3 < *(int **)(*(int *)(iVar12 + iVar6) + 0xc));
                }
                local_18 = local_18 + 1;
                iVar12 = iVar12 + 4;
              } while (local_18 < *(uint *)(param_1 + 0xc));
            }
            iVar6 = FUN_00618c39();
            if ((-1 < iVar6) && (iVar6 = FUN_00618c39(), -1 < iVar6)) {
              puVar1 = (uint *)(*(int *)(param_1 + 0xa0) + iVar8 * 4);
              *puVar1 = (*puVar1 + 4 & 0x7fff) << 0x10 | 0xfffe;
              iVar6 = FUN_00618c39();
              if (-1 < iVar6) {
                if (param_2 != (uint *)0x0) {
                  iVar6 = FUN_005d65b0(*(int *)(param_1 + 0xa4) << 2,&param_3);
                  if (iVar6 < 0) goto LAB_0061311d;
                  uVar10 = *(uint *)(param_1 + 0xa4);
                  puVar9 = *(undefined4 **)(param_1 + 0xa0);
                  puVar7 = (undefined4 *)(**(code **)(*param_3 + 0xc))();
                  for (uVar10 = uVar10 & 0x3fffffff; uVar10 != 0; uVar10 = uVar10 - 1) {
                    *puVar7 = *puVar9;
                    puVar9 = puVar9 + 1;
                    puVar7 = puVar7 + 1;
                  }
                  for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
                    *(undefined1 *)puVar7 = *(undefined1 *)puVar9;
                    puVar9 = (undefined4 *)((int)puVar9 + 1);
                    puVar7 = (undefined4 *)((int)puVar7 + 1);
                  }
                  *param_2 = (uint)param_3;
                }
                iVar6 = 0;
              }
            }
          }
        }
      }
    }
  }
LAB_0061311d:
  _free(local_c);
  return iVar6;
}


// ==== 0x61314d FUN_0061314d

void __thiscall FUN_0061314d(undefined4 *param_1,undefined4 param_2)

{
  param_1[1] = 0;
  *param_1 = param_2;
  param_1[2] = 0;
  param_1[3] = param_1 + 2;
  return;
}


// ==== 0x613165 FUN_00613165

void __fastcall FUN_00613165(int param_1)

{
  int iVar1;
  undefined4 *_Memory;
  
  iVar1 = *(int *)(param_1 + 8);
  while (iVar1 != 0) {
    _Memory = *(undefined4 **)(param_1 + 8);
    *(undefined4 *)(param_1 + 8) = _Memory[4];
    if (((_Memory[2] & 8) != 0) || ((_Memory[2] & 1) == 0)) {
      _free((void *)*_Memory);
    }
    _free(_Memory);
    iVar1 = *(int *)(param_1 + 8);
  }
  return;
}


// ==== 0x61319b FUN_0061319b

undefined4 __thiscall
FUN_0061319b(int param_1,char *param_2,char *param_3,uint param_4,undefined4 *param_5)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  
  if ((param_3 != (char *)0x0) && (param_2 == (char *)0x0)) {
    return 0x80004005;
  }
  if (param_3 == (char *)0xffffffff) {
    param_3 = param_2;
    do {
      cVar1 = *param_3;
      param_3 = param_3 + 1;
    } while (cVar1 != '\0');
    param_3 = param_3 + (1 - (int)(param_2 + 1));
  }
  if ((param_4 & 1) == 0) {
    param_4 = param_4 | 2;
  }
  if ((param_4 & 2) != 0) {
    for (puVar2 = *(undefined4 **)(param_1 + 8); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)puVar2[4]) {
      if (((*(byte *)(puVar2 + 2) & 2) != 0) && (param_3 == (char *)puVar2[1])) {
        bVar8 = true;
        pcVar4 = param_3;
        pcVar6 = param_2;
        pcVar7 = (char *)*puVar2;
        do {
          if (pcVar4 == (char *)0x0) break;
          pcVar4 = pcVar4 + -1;
          bVar8 = *pcVar6 == *pcVar7;
          pcVar6 = pcVar6 + 1;
          pcVar7 = pcVar7 + 1;
        } while (bVar8);
        if (bVar8) {
          if (param_5 != (undefined4 *)0x0) {
            *param_5 = puVar2[3];
          }
          if (((param_4 & 1) != 0) && ((param_4 & 8) != 0)) {
            _free(param_2);
          }
          return 0;
        }
      }
    }
  }
  puVar2 = _malloc(0x14);
  if (puVar2 == (undefined4 *)0x0) {
LAB_00613220:
    uVar3 = 0x8007000e;
  }
  else {
    if ((param_4 & 1) == 0) {
      pcVar4 = _malloc((size_t)param_3);
      *puVar2 = pcVar4;
      if (pcVar4 == (char *)0x0) {
        _free(puVar2);
        goto LAB_00613220;
      }
      for (uVar5 = (uint)param_3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar4 = *(undefined4 *)param_2;
        param_2 = param_2 + 4;
        pcVar4 = pcVar4 + 4;
      }
      for (uVar5 = (uint)param_3 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar4 = *param_2;
        param_2 = param_2 + 1;
        pcVar4 = pcVar4 + 1;
      }
    }
    else {
      *puVar2 = param_2;
    }
    if ((param_4 & 4) == 0) {
      *(uint *)(param_1 + 4) = *(int *)(param_1 + 4) + 3U & 0xfffffffc;
    }
    uVar3 = *(undefined4 *)(param_1 + 4);
    puVar2[2] = param_4;
    puVar2[4] = 0;
    puVar2[3] = uVar3;
    puVar2[1] = param_3;
    *(int *)(param_1 + 4) = (int)(param_3 + *(int *)(param_1 + 4));
    **(undefined4 **)(param_1 + 0xc) = puVar2;
    *(undefined4 **)(param_1 + 0xc) = puVar2 + 4;
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = puVar2[3];
    }
    uVar3 = 0;
  }
  return uVar3;
}


// ==== 0x6132d2 FUN_006132d2

int __fastcall FUN_006132d2(int param_1)

{
  return (*(int *)(param_1 + 4) + 3U >> 2) + 2;
}


// ==== 0x6132de FUN_006132de

undefined4 __thiscall FUN_006132de(uint *param_1,uint *param_2,uint *param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  puVar5 = param_2;
  if (param_3 == (uint *)0xffffffff) {
    uVar4 = (param_1[1] + 3 >> 2) + 2;
  }
  else {
    uVar4 = (uint)param_3;
    if (param_3 < (param_1[1] + 3 >> 2) + 2) {
      return 0x80004005;
    }
  }
  if (0x8000 < uVar4) {
    return 0x80004005;
  }
  param_2 = (uint *)0x0;
  *puVar5 = (uVar4 - 1 & 0x7fff) << 0x10 | 0xfffe;
  puVar5[1] = *param_1;
  param_3 = puVar5 + 2;
  for (puVar1 = (undefined4 *)param_1[2]; puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[4]) {
    if ((*(byte *)(puVar1 + 2) & 4) == 0) {
      uVar2 = ((int)param_2 + 3U & 0xfffffffc) - (int)param_2;
      puVar5 = param_3;
      for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar5 = 0xabababab;
        puVar5 = puVar5 + 1;
      }
      for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar5 = 0xab;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      param_3 = (uint *)((int)param_3 + uVar2);
      param_2 = (uint *)((int)param_2 + uVar2);
    }
    uVar2 = puVar1[1];
    puVar5 = (uint *)*puVar1;
    puVar6 = param_3;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(char *)puVar6 = (char)*puVar5;
      puVar5 = (uint *)((int)puVar5 + 1);
      puVar6 = (uint *)((int)puVar6 + 1);
    }
    param_3 = (uint *)((int)param_3 + puVar1[1]);
    param_2 = (uint *)((int)param_2 + puVar1[1]);
  }
  uVar2 = (uVar4 * 4 + -8) - (int)param_2;
  for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *param_3 = 0xabababab;
    param_3 = param_3 + 1;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)param_3 = 0xab;
    param_3 = (uint *)((int)param_3 + 1);
  }
  return 0;
}


// ==== 0x6133c9 FUN_006133c9

undefined4 * __fastcall FUN_006133c9(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_005d77e9(0x11);
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  *param_1 = &PTR_FUN_006a6120;
  puVar2 = param_1 + 4;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  return param_1;
}


// ==== 0x613405 FUN_00613405

undefined4 * __thiscall
FUN_00613405(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_005d77e9(0x11);
  *param_1 = &PTR_FUN_006a6120;
  puVar2 = param_1 + 4;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  param_1[0xc] = param_3;
  param_1[0xd] = param_4;
  param_1[0xe] = param_5;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  return param_1;
}


// ==== 0x613455 FUN_00613455

void __fastcall FUN_00613455(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_006a6120;
  if ((undefined4 *)param_1[0xf] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xf])(1);
  }
  if ((undefined4 *)param_1[0x10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x10])(1);
  }
  piVar2 = param_1 + 0x11;
  iVar1 = 4;
  do {
    if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_005d7803();
  return;
}


// ==== 0x61349c FUN_0061349c

undefined4 * __fastcall FUN_0061349c(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint local_c;
  
  pvVar1 = _malloc(0x60);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_006133c9();
  }
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar4 = (undefined4 *)(param_1 + 0x10);
  puVar5 = puVar2 + 4;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar2[0xc] = *(undefined4 *)(param_1 + 0x30);
  puVar2[0xd] = *(undefined4 *)(param_1 + 0x34);
  puVar2[0xe] = *(undefined4 *)(param_1 + 0x38);
  puVar2[0x15] = *(undefined4 *)(param_1 + 0x54);
  puVar2[0x16] = *(undefined4 *)(param_1 + 0x58);
  if (*(int **)(param_1 + 0x3c) == (int *)0x0) {
LAB_00613518:
    if (*(int **)(param_1 + 0x40) != (int *)0x0) {
      iVar3 = (**(code **)(**(int **)(param_1 + 0x40) + 8))();
      puVar2[0x10] = iVar3;
      if (iVar3 == 0) goto LAB_0061350c;
    }
    local_c = 0;
    piVar6 = (int *)(param_1 + 0x44);
    do {
      if ((int *)*piVar6 != (int *)0x0) {
        iVar3 = (**(code **)(*(int *)*piVar6 + 8))();
        *(int *)(((int)puVar2 - param_1) + (int)piVar6) = iVar3;
        if (iVar3 == 0) goto LAB_0061350c;
      }
      local_c = local_c + 1;
      piVar6 = piVar6 + 1;
    } while (local_c < 4);
  }
  else {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x3c) + 8))();
    puVar2[0xf] = iVar3;
    if (iVar3 != 0) goto LAB_00613518;
LAB_0061350c:
    (**(code **)*puVar2)(1);
    puVar2 = (undefined4 *)0x0;
  }
  return puVar2;
}


// ==== 0x613560 FUN_00613560

undefined4 * __fastcall FUN_00613560(undefined4 *param_1)

{
  FUN_005d77e9(0x12);
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[10] = 0;
  *param_1 = &PTR_FUN_006a6130;
  param_1[8] = 0xf0000;
  param_1[9] = 0xe40000;
  return param_1;
}


// ==== 0x613593 FUN_00613593

undefined4 * __thiscall
FUN_00613593(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  FUN_005d77e9(0x12);
  param_1[4] = param_2;
  param_1[5] = param_3;
  param_1[6] = param_4;
  param_1[7] = param_5;
  param_1[10] = param_6;
  *param_1 = &PTR_FUN_006a6130;
  param_1[8] = 0xf0000;
  param_1[9] = 0xe40000;
  return param_1;
}


// ==== 0x6135d9 FUN_006135d9

void __fastcall FUN_006135d9(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a6130;
  if ((undefined4 *)param_1[10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[10])(1);
  }
  FUN_005d7803();
  return;
}


// ==== 0x6135f7 FUN_006135f7

undefined4 * __fastcall FUN_006135f7(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  pvVar1 = _malloc(0x2c);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_00613560();
  }
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[4] = *(undefined4 *)(param_1 + 0x10);
    puVar2[5] = *(undefined4 *)(param_1 + 0x14);
    puVar2[6] = *(undefined4 *)(param_1 + 0x18);
    puVar2[7] = *(undefined4 *)(param_1 + 0x1c);
    puVar2[8] = *(undefined4 *)(param_1 + 0x20);
    puVar2[9] = *(undefined4 *)(param_1 + 0x24);
    if (*(int **)(param_1 + 0x28) == (int *)0x0) {
      return puVar2;
    }
    iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 8))();
    puVar2[10] = iVar3;
    if (iVar3 != 0) {
      return puVar2;
    }
    (**(code **)*puVar2)(1);
  }
  return (undefined4 *)0x0;
}


// ==== 0x613660 FUN_00613660

void * __thiscall FUN_00613660(void *param_1,byte param_2)

{
  FUN_00613455();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x61367c FUN_0061367c

void * __thiscall FUN_0061367c(void *param_1,byte param_2)

{
  FUN_006135d9();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x613698 FUN_00613698

int FUN_00613698(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(*(int *)(*(int *)(param_3 + 0x10) + param_1 * 4) + 8);
  uVar2 = *(uint *)(*(int *)(*(int *)(param_3 + 0x10) + param_2 * 4) + 8);
  if (uVar2 <= uVar1) {
    if (uVar2 < uVar1) {
      return -1;
    }
    if (param_1 <= param_2) {
      return -(uint)(param_1 < param_2);
    }
  }
  return 1;
}


// ==== 0x6136ce FUN_006136ce

uint FUN_006136ce(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  
  iVar2 = *(int *)(*(int *)(param_3 + 0x14) + param_1 * 4);
  iVar3 = *(int *)(*(int *)(param_3 + 0x14) + param_2 * 4);
  uVar4 = *(uint *)(iVar2 + 0x44);
  pbVar5 = *(byte **)(uVar4 + 0x20);
  if (pbVar5 == (byte *)0x0) {
    pbVar5 = &DAT_006b9172;
  }
  pbVar7 = *(byte **)(*(int *)(iVar3 + 0x44) + 0x20);
  pbVar8 = &DAT_006b9172;
  if (pbVar7 != (byte *)0x0) {
    pbVar8 = pbVar7;
  }
  do {
    bVar1 = *pbVar5;
    bVar9 = bVar1 < *pbVar8;
    if (bVar1 != *pbVar8) {
LAB_00613728:
      iVar6 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
      goto LAB_0061372d;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar5[1];
    bVar9 = bVar1 < pbVar8[1];
    if (bVar1 != pbVar8[1]) goto LAB_00613728;
    pbVar5 = pbVar5 + 2;
    pbVar8 = pbVar8 + 2;
  } while (bVar1 != 0);
  iVar6 = 0;
LAB_0061372d:
  if (iVar6 < 1) {
    if (-1 < iVar6) {
      pbVar5 = *(byte **)(*(int *)(*(int *)(iVar3 + 0x44) + 0x14) + 0x18);
      pbVar7 = *(byte **)(*(int *)(uVar4 + 0x14) + 0x18);
      do {
        bVar1 = *pbVar7;
        bVar9 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_00613771:
          iVar6 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_00613776;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar7[1];
        bVar9 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_00613771;
        pbVar7 = pbVar7 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar6 = 0;
LAB_00613776:
      if (0 < iVar6) goto LAB_00613731;
      if (-1 < iVar6) {
        if (*(uint *)(iVar3 + 0x44) < uVar4) goto LAB_00613731;
        if ((*(uint *)(iVar3 + 0x44) <= uVar4) &&
           (*(uint *)(iVar3 + 0x58) <= *(uint *)(iVar2 + 0x58))) {
          if (*(uint *)(iVar2 + 0x58) != *(uint *)(iVar3 + 0x58)) goto LAB_00613731;
          if (*(uint *)(iVar3 + 0xc) <= *(uint *)(iVar2 + 0xc)) {
            return (uint)(*(uint *)(iVar3 + 0xc) < *(uint *)(iVar2 + 0xc));
          }
        }
      }
    }
    uVar4 = 0xffffffff;
  }
  else {
LAB_00613731:
    uVar4 = 1;
  }
  return uVar4;
}


// ==== 0x6137a9 FUN_006137a9

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_006137a9(undefined4 *param_1)

{
  FUN_005f7f35();
  *param_1 = &PTR_FUN_006a65f8;
  _DAT_007094b4 = 0;
  param_1[0x3d] = 0xffffffff;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x3e] = 0xffffffff;
  param_1[0x3f] = 0xffffffff;
  param_1[0x40] = 0xffffffff;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x42] = 0;
  param_1[0x3b] = 0;
  return param_1;
}


// ==== 0x613825 FUN_00613825

void __fastcall FUN_00613825(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_006a65f8;
  _free((void *)param_1[0x28]);
  _free((void *)param_1[0x2e]);
  piVar1 = (int *)param_1[0x42];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[0x42] = 0;
  }
  FUN_005f7f76();
  return;
}


// ==== 0x613865 FUN_00613865

undefined4 __thiscall
FUN_00613865(int param_1,uint *param_2,int param_3,uint param_4,int param_5,uint *param_6,
            int param_7)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint auStack_38 [4];
  int local_28 [5];
  int local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = *param_2;
  local_14 = param_1;
  if (((local_28[4] & 0xff000000U) == 0x30000000) || ((local_28[4] & 0xff000000U) == 0xfa000000)) {
    uVar2 = 0;
    uVar4 = uVar2;
    if ((local_28[4] & 0xffffffU) != 0) {
      do {
        param_6[uVar4] = uVar4;
        uVar4 = uVar4 + 1;
      } while (uVar4 < (local_28[4] & 0xffffffU));
    }
    if (param_4 != 0) {
      do {
        iVar5 = *(int *)(param_3 + uVar2 * 4);
        iVar1 = *(int *)(*(int *)(param_1 + 0x14) + iVar5 * 4);
        if ((iVar5 != *(int *)param_2[4]) || (*(int *)(iVar1 + 0x20) != param_7)) {
          if (*(int *)(iVar1 + 0x24) != *(int *)param_2[4]) {
            return 1;
          }
          if (*(int *)(iVar1 + 0x20) != param_7) {
            return 1;
          }
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < param_4);
    }
  }
  else {
    local_8 = 0;
    if (param_4 != 0) {
      uVar2 = param_2[3];
      do {
        local_10 = 0;
        local_c = 0;
        if (uVar2 == 0) {
          return 1;
        }
        iVar5 = *(int *)(param_3 + local_8 * 4);
        piVar3 = (int *)param_2[4];
        iVar1 = *(int *)(*(int *)(local_14 + 0x14) + iVar5 * 4);
        iVar6 = (int)local_28 - (int)piVar3;
        do {
          if (((iVar5 == *piVar3) && (*(int *)(iVar1 + 0x20) == param_7)) ||
             ((*(int *)(iVar1 + 0x24) == *piVar3 && (*(int *)(iVar1 + 0x20) == param_7)))) {
            auStack_38[local_8] = local_c;
            local_10 = 1;
            *(undefined4 *)(iVar6 + (int)piVar3) = 1;
          }
          local_c = local_c + 1;
          uVar2 = param_2[3];
          piVar3 = piVar3 + 1;
        } while (local_c < uVar2);
        if (local_10 == 0) {
          return 1;
        }
        local_8 = local_8 + 1;
      } while (local_8 < param_4);
    }
    uVar2 = 0;
    if ((local_28[4] & 0xffffffU) != 0) {
      do {
        if (local_28[uVar2] == 0) {
          return 1;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < (local_28[4] & 0xffffffU));
    }
    param_5 = param_5 - (int)param_6;
    iVar5 = 4;
    do {
      uVar2 = *(uint *)(param_5 + (int)param_6);
      if (uVar2 < 4) {
        *param_6 = auStack_38[uVar2];
      }
      else {
        *param_6 = 0xff;
      }
      param_6 = param_6 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return 0;
}


// ==== 0x6139d8 FUN_006139d8

int __thiscall
FUN_006139d8(int param_1,uint *param_2,int *param_3,int *param_4,int *param_5,int param_6,
            undefined4 *param_7,uint param_8)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  int *piVar10;
  int local_1b8 [40];
  int local_118 [40];
  int local_78 [16];
  undefined1 local_38 [16];
  uint local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  int *local_c;
  uint local_8;
  
  piVar7 = param_3;
  local_24 = param_1;
  local_1c = *param_2 & 0xffffff;
  if (param_8 < local_1c) {
    local_14 = 1;
  }
  else if ((*param_2 & 0xff000000) == param_3[1]) {
    local_20 = 0;
    if (param_3[7] != -1) {
      do {
        param_3 = (int *)*param_5;
        piVar8 = param_4;
        piVar10 = local_78;
        for (piVar4 = param_3; piVar4 != (int *)0x0; piVar4 = (int *)((int)piVar4 + -1)) {
          *piVar10 = *piVar8;
          piVar8 = piVar8 + 1;
          piVar10 = piVar10 + 1;
        }
        piVar4 = local_118;
        for (iVar5 = 0x28; iVar5 != 0; iVar5 = iVar5 + -1) {
          *piVar4 = -1;
          piVar4 = piVar4 + 1;
        }
        piVar4 = local_1b8;
        for (iVar5 = 0x28; iVar5 != 0; iVar5 = iVar5 + -1) {
          *piVar4 = -1;
          piVar4 = piVar4 + 1;
        }
        local_14 = 0;
        local_8 = 0;
        if (piVar7[2] != 0) {
          local_c = (int *)0x0;
          do {
            iVar5 = local_24;
            uVar9 = local_8;
            if (local_20 != 0) {
              uVar9 = 1 - local_8;
            }
            uVar1 = param_2[2];
            uVar9 = piVar7[uVar9 + 3];
            piVar4 = (int *)(uVar1 + (int)local_c * 4);
            local_10 = *(int *)(*(int *)(local_24 + 0x14) + *piVar4 * 4);
            if (uVar9 < 0x10) {
              iVar3 = *(int *)(local_10 + 0x2c);
              if ((iVar3 == -1) ||
                 (iVar3 = FUN_00613865(*(undefined4 *)(*(int *)(local_24 + 0x18) + iVar3 * 4),piVar4
                                       ,local_1c,param_7,local_38,piVar7[(uVar9 - *piVar7) * 8 + 6])
                 , iVar3 != 0)) {
                local_14 = 1;
                break;
              }
              local_14 = FUN_006139d8(*(undefined4 *)
                                       (*(int *)(iVar5 + 0x18) + *(int *)(local_10 + 0x2c) * 4),
                                      piVar7 + (uVar9 - *piVar7) * 8,local_78,&param_3,local_1b8,
                                      local_38,param_8);
            }
            else {
              uVar6 = 0;
              piVar4 = local_118 + (uVar9 - 0x10) * 4;
              do {
                uVar9 = *(uint *)((int)param_7 + uVar6 * 4);
                if (uVar9 < local_1c) {
                  *piVar4 = *(int *)(uVar1 + ((int)local_c + uVar9) * 4);
                }
                else {
                  *piVar4 = -1;
                }
                uVar6 = uVar6 + 1;
                piVar4 = piVar4 + 1;
              } while (uVar6 < 4);
            }
            if (local_14 == 1) break;
            local_8 = local_8 + 1;
            local_c = (int *)((int)local_c + local_1c);
          } while (local_8 < (uint)piVar7[2]);
        }
        local_8 = 0;
        if (piVar7[2] != 0) {
          local_10 = 0;
          do {
            uVar9 = local_8;
            if (local_20 != 0) {
              uVar9 = 1 - local_8;
            }
            if ((0xf < (uint)piVar7[uVar9 + 3]) && (local_c = (int *)0x0, param_3 != (int *)0x0)) {
              do {
                uVar9 = 0;
                if (local_1c != 0) {
                  local_28 = *(uint *)(local_78[(int)local_c] + 0xc);
                  do {
                    local_18 = 0;
                    if (local_28 != 0) {
                      piVar4 = *(int **)(local_78[(int)local_c] + 0x10);
                      do {
                        if (*(int *)(param_2[2] + (local_10 + uVar9) * 4) == *piVar4) {
                          local_14 = 1;
                          goto LAB_00613be7;
                        }
                        local_18 = local_18 + 1;
                        piVar4 = piVar4 + 1;
                      } while (local_18 < local_28);
                    }
                    uVar9 = uVar9 + 1;
                  } while (uVar9 < local_1c);
                }
LAB_00613be7:
                local_c = (int *)((int)local_c + 1);
              } while (local_c < param_3);
            }
            local_8 = local_8 + 1;
            local_10 = local_10 + local_1c;
          } while (local_8 < (uint)piVar7[2]);
        }
        if (local_14 == 0) goto LAB_00613c28;
        local_20 = local_20 + 1;
      } while (local_20 < piVar7[7] + 1U);
    }
    if (local_14 == 0) {
LAB_00613c28:
      if ((*piVar7 == 0) && (local_c = (int *)0x0, param_3 != (int *)0x0)) {
        do {
          local_28 = *(uint *)(local_78[(int)local_c] + 0xc);
          param_8 = 0;
          if (local_28 != 0) {
            uVar9 = *(uint *)(local_24 + 0xc);
            do {
              local_10 = 0;
              if (uVar9 != 0) {
                param_7 = *(undefined4 **)(local_24 + 0x18);
                do {
                  puVar2 = (uint *)*param_7;
                  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
                    uVar9 = puVar2[1];
                    local_18 = 0;
                    if (uVar9 != 0) {
                      iVar5 = *(int *)(*(int *)(local_78[(int)local_c] + 0x10) + param_8 * 4);
                      piVar7 = (int *)puVar2[2];
                      do {
                        if ((*piVar7 == iVar5) ||
                           (*(int *)(*(int *)(*(int *)(local_24 + 0x14) + *piVar7 * 4) + 0x24) ==
                            iVar5)) {
                          local_18 = 1;
                        }
                        piVar7 = piVar7 + 1;
                        uVar9 = uVar9 - 1;
                      } while (uVar9 != 0);
                    }
                    if (puVar2 == param_2) {
                      local_18 = 0;
                    }
                    if (local_18 != 0) {
                      piVar7 = (int *)0x0;
                      do {
                        if (puVar2 == (uint *)local_78[(int)piVar7]) {
                          local_18 = 0;
                        }
                        piVar7 = (int *)((int)piVar7 + 1);
                      } while (piVar7 < param_3);
                      if (local_18 != 0) {
                        return 1;
                      }
                    }
                  }
                  local_10 = local_10 + 1;
                  uVar9 = *(uint *)(local_24 + 0xc);
                  param_7 = param_7 + 1;
                } while (local_10 < uVar9);
              }
              param_8 = param_8 + 1;
            } while (param_8 < local_28);
          }
          local_c = (int *)((int)local_c + 1);
        } while (local_c < param_3);
      }
      piVar7 = local_78;
      piVar4 = param_4;
      for (uVar9 = (uint)param_3 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
        *piVar4 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar4 = piVar4 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(char *)piVar4 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar4 = (int *)((int)piVar4 + 1);
      }
      param_4[(int)param_3] = (int)param_2;
      *param_5 = (int)param_3 + 1;
      uVar9 = 0;
      do {
        iVar5 = *(int *)((int)local_118 + uVar9);
        if ((iVar5 != -1) || (iVar5 = *(int *)((int)local_1b8 + uVar9), iVar5 != -1)) {
          *(int *)(uVar9 + param_6) = iVar5;
        }
        uVar9 = uVar9 + 4;
      } while (uVar9 < 0xa0);
      local_14 = 0;
    }
  }
  else {
    local_14 = 1;
  }
  return local_14;
}


// ==== 0x613d78 FUN_00613d78

undefined4 __thiscall
FUN_00613d78(int param_1,int param_2,uint param_3,uint param_4,uint param_5,char param_6)

{
  uint *puVar1;
  int *piVar2;
  undefined4 *_Memory;
  long lVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 *puVar13;
  int *local_1c;
  uint local_18;
  uint local_14;
  int *local_10;
  undefined4 *local_c;
  
  uVar8 = 0;
  local_1c = (int *)0x0;
  local_c = (undefined4 *)0x0;
  if (*(int *)(param_1 + 4) != 0) {
    do {
      iVar5 = *(int *)(*(int *)(param_1 + 0x10) + uVar8 * 4);
      uVar12 = *(uint *)(iVar5 + 4);
      *(undefined4 *)(iVar5 + 0x10) = 0;
      if ((uVar12 & 0x200) == 0) {
        uVar11 = 0;
        *(undefined4 *)(iVar5 + 8) = 0;
        if (*(int *)(param_1 + 8) != 0) {
          do {
            puVar1 = *(uint **)(*(int *)(param_1 + 0x14) + uVar11 * 4);
            if ((*puVar1 == uVar8) && (uVar4 = puVar1[2] + 1, *(uint *)(iVar5 + 8) < uVar4)) {
              *(uint *)(iVar5 + 8) = uVar4;
            }
            uVar11 = uVar11 + 1;
          } while (uVar11 < *(uint *)(param_1 + 8));
        }
        if ((char)uVar12 < '\0') {
          *(uint *)(iVar5 + 4) = uVar12 & 0xffffffdf;
        }
        uVar12 = *(uint *)(iVar5 + 4);
        if (((uVar12 & 8) != 0) && ((uVar12 & 0x500) == 0)) {
          *(uint *)(iVar5 + 4) = uVar12 & 0xffffffdf;
        }
        uVar12 = *(uint *)(iVar5 + 4);
        if ((((uVar12 & 0x40) != 0) && ((uVar12 & 0x400) == 0)) && (*(int *)(iVar5 + 8) == 1)) {
          *(uint *)(iVar5 + 4) = uVar12 & 0xffffffdf;
        }
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(param_1 + 4));
  }
  _Memory = _malloc(param_3 << 3);
  if (_Memory != (undefined4 *)0x0) {
    local_10 = (int *)0x0;
    puVar13 = _Memory;
    for (iVar5 = (param_3 & 0x1fffffff) << 1; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar13 = 0;
      puVar13 = puVar13 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar13 = 0;
      puVar13 = (undefined4 *)((int)puVar13 + 1);
    }
    if (*(int *)(param_1 + 4) != 0) {
      do {
        piVar6 = *(int **)(*(int *)(param_1 + 0x10) + (int)local_10 * 4);
        uVar8 = piVar6[1];
        if ((((param_4 & uVar8) != 0) && ((param_5 & uVar8) == 0)) &&
           (((uVar8 & 0x20) != 0 && ((uVar8 & 0x400) != 0)))) {
          pcVar9 = (char *)*piVar6;
          piVar6[4] = -1;
          if (((pcVar9 != (char *)0x0) && (iVar5 = _tolower((int)*pcVar9), param_6 == iVar5)) &&
             (iVar5 = _isdigit((int)pcVar9[1]), iVar5 != 0)) {
            pcVar9 = pcVar9 + 2;
            while (iVar5 = _isdigit((int)*pcVar9), iVar5 != 0) {
              pcVar9 = pcVar9 + 1;
            }
            if (*pcVar9 == '\0') {
              lVar3 = _atoi((char *)(*piVar6 + 1));
              piVar6[4] = lVar3;
            }
          }
          if (param_3 <= (uint)piVar6[4]) {
            FUN_005fbec8(param_1,0,0x119d,"invalid register semantic \'%s\'",*piVar6);
            goto LAB_00614236;
          }
          local_14 = 0;
          if (piVar6[2] != 0) {
            do {
              uVar8 = piVar6[4] + local_14;
              if (param_3 <= uVar8) goto LAB_00614209;
              puVar1 = _Memory + uVar8 * 2;
              if (*puVar1 != 0) {
                FUN_005fbec8(param_1,0,0x1194,
                             "overlapping register semantics not yet implemented \'%c%u\'",
                             (int)param_6,uVar8);
              }
              *puVar1 = (uint)local_10;
              puVar1[1] = local_14;
              local_14 = local_14 + 1;
            } while (local_14 < (uint)piVar6[2]);
          }
        }
        local_10 = (int *)((int)local_10 + 1);
      } while (local_10 < *(uint *)(param_1 + 4));
    }
    iVar5 = *(int *)(param_1 + 4);
    iVar7 = 0;
    if (iVar5 != 0) {
      piVar6 = *(int **)(param_1 + 0x10);
      do {
        uVar8 = *(uint *)(*piVar6 + 4);
        if (((((param_4 & uVar8) != 0) && ((param_5 & uVar8) == 0)) && ((uVar8 & 0x20) != 0)) &&
           ((uVar8 & 0x400) == 0)) {
          iVar7 = iVar7 + 1;
        }
        piVar6 = piVar6 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    local_1c = _malloc(iVar7 << 2);
    if (local_1c != (int *)0x0) {
      uVar8 = 0;
      uVar12 = 0;
      local_18 = 0;
      if (*(int *)(param_1 + 4) != 0) {
        do {
          uVar11 = *(uint *)(*(int *)(*(int *)(param_1 + 0x10) + uVar8 * 4) + 4);
          if ((((param_4 & uVar11) != 0) && ((param_5 & uVar11) == 0)) &&
             (((uVar11 & 0x20) != 0 && ((uVar11 & 0x400) == 0)))) {
            local_1c[uVar12] = uVar8;
            uVar12 = uVar12 + 1;
          }
          uVar8 = uVar8 + 1;
          local_18 = uVar12;
        } while (uVar8 < *(uint *)(param_1 + 4));
      }
      FUN_005f7e20(FUN_00613698,local_1c,local_18,param_1);
      local_14 = 0;
      local_10 = local_1c;
      if (local_18 != 0) {
        do {
          iVar5 = *(int *)(*(int *)(param_1 + 0x10) + *local_10 * 4);
          uVar8 = 0;
          if (param_3 != 0) {
            do {
              for (; (uVar12 = uVar8, uVar8 < param_3 && (_Memory[uVar8 * 2] != 0));
                  uVar8 = uVar8 + 1) {
              }
              for (; (uVar12 < param_3 && (_Memory[uVar12 * 2] == 0)); uVar12 = uVar12 + 1) {
              }
            } while ((uVar12 - uVar8 < *(uint *)(iVar5 + 8)) && (uVar8 = uVar12, uVar12 < param_3));
          }
          if (param_3 < *(int *)(iVar5 + 8) + uVar8) {
            if (param_6 == 'v') goto LAB_0061420f;
            if (param_6 == 'c') goto LAB_00614221;
            if (param_6 != 's') goto LAB_00614236;
            pcVar9 = "maximum sampler register index exceeded";
            uVar10 = 0x11c2;
            goto LAB_0061422b;
          }
          uVar12 = 0;
          if (*(int *)(iVar5 + 8) != 0) {
            piVar6 = _Memory + uVar8 * 2;
            do {
              iVar7 = *local_10;
              piVar6[1] = uVar12;
              *piVar6 = iVar7;
              uVar12 = uVar12 + 1;
              piVar6 = piVar6 + 2;
            } while (uVar12 < *(uint *)(iVar5 + 8));
          }
          local_14 = local_14 + 1;
          local_10 = local_10 + 1;
          *(uint *)(iVar5 + 0x10) = uVar8;
        } while (local_14 < local_18);
      }
      uVar8 = 0;
      if (*(int *)(param_1 + 8) != 0) {
        do {
          piVar2 = *(int **)(*(int *)(param_1 + 0x14) + uVar8 * 4);
          piVar6 = piVar2 + 2;
          *piVar6 = *piVar6 + *(int *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4) + 0x10);
          uVar8 = uVar8 + 1;
        } while (uVar8 < *(uint *)(param_1 + 8));
      }
      uVar8 = 0;
      if (*(int *)(param_1 + 4) != 0) {
        do {
          iVar5 = *(int *)(*(int *)(param_1 + 0x10) + uVar8 * 4);
          *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) + *(int *)(iVar5 + 0x10);
          uVar8 = uVar8 + 1;
          *(undefined4 *)(iVar5 + 0x10) = 0;
        } while (uVar8 < *(uint *)(param_1 + 4));
      }
      uVar8 = 0;
      if (*(int *)(param_1 + 4) != 0) {
        do {
          iVar5 = *(int *)(*(int *)(param_1 + 0x10) + uVar8 * 4);
          uVar12 = *(uint *)(iVar5 + 4);
          if (((((param_4 & uVar12) != 0) && ((param_5 & uVar12) == 0)) && ((uVar12 & 0x20) == 0))
             && ((uVar12 & 0x400) == 0)) {
            local_c = _malloc(*(int *)(iVar5 + 8) << 2);
            if (local_c == (undefined4 *)0x0) goto LAB_00614202;
            local_10 = (int *)0x0;
            puVar13 = local_c;
            for (uVar12 = *(uint *)(iVar5 + 8) & 0x3fffffff; uVar12 != 0; uVar12 = uVar12 - 1) {
              *puVar13 = 0xffffffff;
              puVar13 = puVar13 + 1;
            }
            for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
              *(undefined1 *)puVar13 = 0xff;
              puVar13 = (undefined4 *)((int)puVar13 + 1);
            }
            if (*(int *)(param_1 + 8) != 0) {
              do {
                puVar1 = *(uint **)(*(int *)(param_1 + 0x14) + (int)local_10 * 4);
                if (*puVar1 == uVar8) {
                  if (local_c[puVar1[2]] == -1) {
                    uVar12 = 0;
                    if (param_3 == 0) goto LAB_00614209;
                    do {
                      if (_Memory[uVar12 * 2] == 0) break;
                      uVar12 = uVar12 + 1;
                    } while (uVar12 < param_3);
                    if (param_3 <= uVar12) goto LAB_00614209;
                    _Memory[uVar12 * 2] = uVar8;
                    (_Memory + uVar12 * 2)[1] = puVar1[2];
                    local_c[puVar1[2]] = uVar12;
                  }
                  puVar1[2] = local_c[puVar1[2]];
                }
                local_10 = (int *)((int)local_10 + 1);
              } while (local_10 < *(uint *)(param_1 + 8));
            }
            _free(local_c);
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < *(uint *)(param_1 + 4));
      }
      local_c = (undefined4 *)0x0;
      if (param_2 != -1) {
        uVar8 = 0;
        if (*(int *)(param_1 + 8) != 0) {
          do {
            piVar6 = *(int **)(*(int *)(param_1 + 0x14) + uVar8 * 4);
            uVar12 = *(uint *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar6 * 4) + 4);
            if (((param_4 & uVar12) != 0) && ((param_5 & uVar12) == 0)) {
              if ((char)uVar12 < '\0') {
                *piVar6 = *(int *)(param_1 + 0x50);
              }
              else {
                *piVar6 = param_2;
              }
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < *(uint *)(param_1 + 8));
        }
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x10) + param_2 * 4) + 0x10) = 0;
        *(uint *)(*(int *)(*(int *)(param_1 + 0x10) + param_2 * 4) + 8) = param_3;
        if (param_2 == *(int *)(param_1 + 0x54)) {
          *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x50) * 4) + 0x10)
               = 0;
          *(uint *)(*(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x50) * 4) + 8) = param_3
          ;
        }
      }
      uVar10 = 0;
      goto LAB_0061427f;
    }
  }
LAB_00614202:
  uVar10 = 0x8007000e;
  goto LAB_0061427f;
LAB_00614209:
  if (param_6 == 'v') {
LAB_0061420f:
    pcVar9 = "maximum input register index exceeded";
    uVar10 = 0x119a;
LAB_0061422b:
    FUN_005fbec8(param_1,0,uVar10,pcVar9);
  }
  else if (param_6 == 'c') {
LAB_00614221:
    pcVar9 = "maximum constant register index exceeded";
    uVar10 = 0x119b;
    goto LAB_0061422b;
  }
LAB_00614236:
  uVar10 = 0x80004005;
LAB_0061427f:
  _free(_Memory);
  _free(local_1c);
  _free(local_c);
  return uVar10;
}


// ==== 0x6142a3 FUN_006142a3

undefined4 FUN_006142a3(void)

{
  return 0x80004005;
}


// ==== 0x6142ab FUN_006142ab

undefined4 FUN_006142ab(void)

{
  return 0x80004005;
}


// ==== 0x6142b1 FUN_006142b1

undefined4 FUN_006142b1(void)

{
  return 0;
}


// ==== 0x6142b6 FUN_006142b6

int __fastcall FUN_006142b6(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  void *pvVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  int *piVar10;
  undefined4 *puVar11;
  int *piVar12;
  undefined4 local_140 [16];
  int local_100 [4];
  int local_f0 [4];
  int local_e0 [4];
  int local_d0 [28];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int *local_50;
  int local_4c;
  uint local_48;
  int *local_44;
  int *local_40;
  uint local_3c;
  uint local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  uint local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int local_14;
  int *local_10;
  uint local_c;
  int local_8;
  
  uVar8 = *(uint *)param_1[0x26] & 0xffffff;
  local_8 = 0;
  local_3c = 0;
  local_60 = 0;
  local_5c = 1;
  local_58 = 2;
  local_54 = 3;
  local_24 = uVar8;
  iVar5 = FUN_006139d8((uint *)param_1[0x26],&DAT_006a6598,local_140,&local_3c,local_100,&local_60,
                       uVar8);
  if (iVar5 != 0) {
    return iVar5;
  }
  local_34 = local_100;
  local_2c = local_f0;
  local_14 = 0;
  local_c = 0;
LAB_00614339:
  local_28 = local_e0;
  local_44 = local_d0;
  local_38 = 0;
LAB_0061434e:
  if (uVar8 == 0) goto LAB_0061447c;
  iVar5 = param_1[5];
  local_20 = local_44;
  local_30 = local_28;
  local_10 = local_2c;
  local_1c = local_34;
  local_48 = uVar8;
  do {
    local_40 = *(int **)(iVar5 + *local_20 * 4);
    local_50 = *(int **)(iVar5 + *local_10 * 4);
    iVar1 = *local_30;
    iVar2 = *(int *)(iVar5 + *local_1c * 4);
    local_4c = *(int *)(param_1[4] + *local_50 * 4);
    local_18 = *(int **)(param_1[4] + *local_40 * 4);
    if ((((*(int *)(iVar2 + 0x24) == iVar1) ||
         (iVar3 = *(int *)(*(int *)(iVar5 + iVar1 * 4) + 0x24), iVar3 == *local_1c)) ||
        ((*(int *)(iVar2 + 0x24) != -1 && (*(int *)(iVar2 + 0x24) == iVar3)))) &&
       (((*(uint *)(iVar2 + 0x20) ^ 0x80000) == *(uint *)(*(int *)(iVar5 + iVar1 * 4) + 0x20) &&
        (*local_10 == *local_20)))) {
      bVar4 = true;
      local_14 = 0;
    }
    else if ((*local_1c == iVar1) &&
            (((((local_50[9] == *local_20 || (local_40[9] == *local_10)) ||
               ((local_50[9] != -1 && (local_50[9] == local_40[9])))) &&
              ((local_50[8] ^ 0x80000U) == local_40[8])) ||
             ((((*(byte *)(local_4c + 4) & 0x80) != 0 && ((*(byte *)(local_18 + 1) & 0x80) != 0)) &&
              (-*(double *)(local_50 + 4) == *(double *)(local_40 + 4))))))) {
      bVar4 = true;
      local_14 = 1;
    }
    else {
      bVar4 = false;
    }
    local_1c = local_1c + 1;
    local_10 = local_10 + 1;
    local_30 = local_30 + 1;
    local_20 = local_20 + 1;
    local_48 = local_48 - 1;
  } while (local_48 != 0);
  uVar8 = local_24;
  if (!bVar4) goto LAB_0061447c;
  pvVar6 = _malloc(0x38);
  if (pvVar6 == (void *)0x0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_005f7709();
  }
  uVar8 = local_24;
  if (local_8 == 0) {
    return -0x7ff8fff2;
  }
  if (local_14 == 0) {
    if (local_c == 0) goto LAB_0061463f;
LAB_00614673:
    if (local_c == 1) goto LAB_00614502;
  }
  else {
    if (local_c == 1) {
LAB_0061463f:
      iVar5 = FUN_005f7760(local_24 & 0xffffff | 0x20000000,local_24 * 2,local_24,0);
      if (iVar5 < 0) goto LAB_006144a8;
      if (local_14 == 0) goto LAB_00614673;
    }
    if (local_c == 0) {
LAB_00614502:
      iVar5 = FUN_005f7760(uVar8 & 0xffffff | 0x21000000,uVar8 * 2,uVar8,0);
      if (iVar5 < 0) goto LAB_006144a8;
    }
  }
  iVar5 = FUN_005f7a42(param_1[0x26]);
  iVar1 = local_8;
  if (-1 < iVar5) {
    puVar9 = *(undefined4 **)(param_1[0x26] + 0x10);
    puVar11 = *(undefined4 **)(local_8 + 0x10);
    for (uVar7 = uVar8 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar11 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    local_18 = (int *)(local_c * 0x10);
    piVar10 = local_100 + local_c * 4;
    piVar12 = *(int **)(local_8 + 8);
    for (uVar7 = uVar8 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
      *piVar12 = *piVar10;
      piVar10 = piVar10 + 1;
      piVar12 = piVar12 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(char *)piVar12 = (char)*piVar10;
      piVar10 = (int *)((int)piVar10 + 1);
      piVar12 = (int *)((int)piVar12 + 1);
    }
    piVar10 = local_f0 + local_c * -4;
    piVar12 = (int *)(*(int *)(local_8 + 8) + uVar8 * 4);
    for (uVar7 = uVar8 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
      *piVar12 = *piVar10;
      piVar10 = piVar10 + 1;
      piVar12 = piVar12 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(char *)piVar12 = (char)*piVar10;
      piVar10 = (int *)((int)piVar10 + 1);
      piVar12 = (int *)((int)piVar12 + 1);
    }
    iVar5 = param_1[5];
    local_18 = *(int **)(iVar5 + (*(int **)(local_8 + 8))[uVar8] * 4);
    piVar10 = *(int **)(iVar5 + **(int **)(local_8 + 8) * 4);
    piVar12 = *(int **)(iVar5 + **(int **)(local_8 + 0x10) * 4);
    if (((*piVar12 != *piVar10) || (piVar12[2] != piVar10[2])) &&
       (((*piVar12 != *local_18 || (piVar12[2] != local_18[2])) &&
        (iVar5 = (**(code **)(*param_1 + 0x24))(local_8,0), iVar5 == 0)))) {
      uVar8 = 0;
      if (local_3c != 0) {
        do {
          puVar9 = local_140 + uVar8;
          uVar8 = uVar8 + 1;
          *(undefined4 *)*puVar9 = 0;
        } while (uVar8 < local_3c);
      }
      if (*(int *)(param_1[6] + param_1[0x25] * 4) != 0) {
        FUN_005f7186(1);
      }
      *(int *)(param_1[6] + param_1[0x25] * 4) = iVar1;
      return 0;
    }
    goto LAB_006144a5;
  }
  goto LAB_006144a8;
LAB_0061447c:
  local_38 = local_38 + 1;
  local_44 = local_44 + -4;
  local_28 = local_28 + 4;
  if (1 < local_38) goto code_r0x00614492;
  goto LAB_0061434e;
code_r0x00614492:
  local_c = local_c + 1;
  local_2c = local_2c + -4;
  local_34 = local_34 + 4;
  if (1 < local_c) {
LAB_006144a5:
    iVar5 = 1;
LAB_006144a8:
    if (local_8 == 0) {
      return iVar5;
    }
    FUN_005f7186(1);
    return iVar5;
  }
  goto LAB_00614339;
}


// ==== 0x614682 FUN_00614682

int __fastcall FUN_00614682(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  int *piVar8;
  void *pvVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  uint local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  puVar1 = *(uint **)(param_1 + 0x98);
  uVar11 = *puVar1 & 0xff000000;
  if ((((((uVar11 == 0x30000000) || (uVar11 == 0x14000000)) || (uVar11 == 0x15000000)) ||
       ((uVar11 == 0x12000000 || (uVar11 == 0xf3000000)))) || (uVar11 == 0xf4000000)) &&
     (puVar1[3] == 1)) {
    iVar10 = *(int *)(param_1 + 0x14);
    bVar7 = false;
    piVar8 = *(int **)(iVar10 + *(int *)puVar1[4] * 4);
    iVar2 = piVar8[0xe];
    if (iVar2 != -1) {
      local_c = 0;
      puVar3 = *(uint **)(*(int *)(param_1 + 0x18) + iVar2 * 4);
      if (puVar3[3] != 0) {
        local_10 = (int *)puVar3[4];
        local_14 = puVar3[3];
        do {
          uVar11 = *(uint *)(*(int *)(iVar10 + *local_10 * 4) + 0x30);
          if (local_c < uVar11) {
            local_c = uVar11;
          }
          local_10 = local_10 + 1;
          local_14 = local_14 - 1;
        } while (local_14 != 0);
      }
      piVar4 = *(int **)(iVar10 + *(int *)puVar3[4] * 4);
      if (((*piVar4 == *piVar8) && (piVar4[2] == piVar8[2])) &&
         ((piVar4[1] == piVar8[1] && (iVar2 != piVar8[0xf])))) {
        bVar7 = true;
      }
      if ((((local_c <= *(uint *)(param_1 + 0x94)) && ((bVar7 || (iVar2 == piVar8[0xf])))) &&
          (((*(byte *)(param_1 + 0x90) & 1) == 0 ||
           ((puVar3[3] != 0 &&
            (**(int **)(iVar10 + *(int *)puVar3[4] * 4) != *(int *)(param_1 + 0x5c))))))) &&
         ((*puVar3 & 0xff000000) == 0x10000000)) {
        uVar11 = 0;
        if (puVar3[1] != 0) {
          piVar8 = (int *)puVar3[2];
          do {
            if (*piVar8 != *(int *)puVar1[4]) {
              return 1;
            }
            uVar11 = uVar11 + 1;
            piVar8 = piVar8 + 1;
          } while (uVar11 < puVar3[1]);
        }
        if (*(int *)(*(int *)(iVar10 + *(int *)puVar3[2] * 4) + 0x20) == 0) {
          pvVar9 = _malloc(0x38);
          if (pvVar9 == (void *)0x0) {
            local_c = 0;
          }
          else {
            local_c = FUN_005f7709();
          }
          if (local_c != 0) {
            iVar10 = FUN_005f7760(**(undefined4 **)(param_1 + 0x98),
                                  (*(undefined4 **)(param_1 + 0x98))[1],(uint)bVar7 + puVar3[3],1);
            if (iVar10 < 0) {
              FUN_005f7186(1);
              return iVar10;
            }
            puVar12 = (undefined4 *)puVar3[4];
            puVar13 = *(undefined4 **)(local_c + 0x10);
            for (uVar11 = puVar3[3] & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
              *puVar13 = *puVar12;
              puVar12 = puVar12 + 1;
              puVar13 = puVar13 + 1;
            }
            for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
              *(undefined1 *)puVar13 = *(undefined1 *)puVar12;
              puVar12 = (undefined4 *)((int)puVar12 + 1);
              puVar13 = (undefined4 *)((int)puVar13 + 1);
            }
            if (bVar7) {
              *(undefined4 *)(*(int *)(local_c + 0x10) + puVar3[3] * 4) =
                   **(undefined4 **)(*(int *)(param_1 + 0x98) + 0x10);
            }
            uVar11 = *(uint *)(local_c + 0xc);
            local_8 = 0;
            if (uVar11 != 0) {
              local_14 = 1;
              do {
                local_10 = (int *)local_14;
                if (local_14 < uVar11) {
                  do {
                    iVar10 = *(int *)(*(int *)(local_c + 0x10) + local_8 * 4);
                    iVar2 = *(int *)(*(int *)(param_1 + 0x14) + iVar10 * 4);
                    piVar8 = (int *)(*(int *)(local_c + 0x10) + (int)local_10 * 4);
                    iVar5 = *piVar8;
                    iVar6 = *(int *)(*(int *)(param_1 + 0x14) + iVar5 * 4);
                    if (*(uint *)(iVar6 + 0xc) < *(uint *)(iVar2 + 0xc)) {
                      *piVar8 = iVar10;
                      *(int *)(*(int *)(local_c + 0x10) + local_8 * 4) = iVar5;
                    }
                    if (*(int *)(iVar2 + 0xc) == *(int *)(iVar6 + 0xc)) {
                      FUN_005fbec8(param_1,*(undefined4 *)(*(int *)(param_1 + 0x98) + 0x34),0x12d6,
                                   "internal error: multiple write to same output");
                      FUN_005f7186(1);
                      return -0x7fffbffb;
                    }
                    local_10 = (int *)((int)local_10 + 1);
                  } while (local_10 < *(uint *)(local_c + 0xc));
                }
                local_8 = local_8 + 1;
                uVar11 = *(uint *)(local_c + 0xc);
                local_14 = local_14 + 1;
              } while (local_8 < uVar11);
            }
            puVar12 = *(undefined4 **)(*(int *)(param_1 + 0x98) + 8);
            puVar13 = *(undefined4 **)(local_c + 8);
            for (uVar11 = *(uint *)(*(int *)(param_1 + 0x98) + 4) & 0x3fffffff; uVar11 != 0;
                uVar11 = uVar11 - 1) {
              *puVar13 = *puVar12;
              puVar12 = puVar12 + 1;
              puVar13 = puVar13 + 1;
            }
            for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
              *(undefined1 *)puVar13 = *(undefined1 *)puVar12;
              puVar12 = (undefined4 *)((int)puVar12 + 1);
              puVar13 = (undefined4 *)((int)puVar13 + 1);
            }
            if (*(int *)(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x94) * 4) != 0) {
              FUN_005f7186(1);
            }
            *(uint *)(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x94) * 4) = local_c;
            *puVar3 = 0;
            return 0;
          }
          return -0x7ff8fff2;
        }
      }
      return 1;
    }
  }
  return 1;
}


// ==== 0x614972 FUN_00614972

undefined4 __fastcall FUN_00614972(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x14) + uVar3 * 4);
      if (*(int *)(iVar1 + 0x24) != -1) {
        iVar2 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar1 + 0x24) * 4);
        *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(iVar2 + 0x2c);
        *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar2 + 0x30);
        *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(iVar2 + 0x34);
        uVar4 = *(uint *)(iVar2 + 0x38);
        if (uVar4 == 0xffffffff) {
          *(undefined4 *)(iVar2 + 0x38) = *(undefined4 *)(iVar1 + 0x38);
          *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(iVar1 + 0x3c);
          *(undefined4 *)(iVar2 + 0x40) = *(undefined4 *)(iVar1 + 0x40);
        }
        else {
          if (*(uint *)(iVar1 + 0x38) <= uVar4) {
            uVar4 = *(uint *)(iVar1 + 0x38);
          }
          *(uint *)(iVar1 + 0x38) = uVar4;
          *(uint *)(iVar2 + 0x38) = uVar4;
          uVar4 = *(uint *)(iVar2 + 0x3c);
          if (*(uint *)(iVar2 + 0x3c) <= *(uint *)(iVar1 + 0x3c)) {
            uVar4 = *(uint *)(iVar1 + 0x3c);
          }
          *(uint *)(iVar1 + 0x3c) = uVar4;
          *(uint *)(iVar2 + 0x3c) = uVar4;
          *(int *)(iVar2 + 0x40) = *(int *)(iVar2 + 0x40) + *(int *)(iVar1 + 0x40);
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 8));
  }
  return 0;
}


// ==== 0x6149ee FUN_006149ee

undefined4 __thiscall FUN_006149ee(int *param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int local_18;
  int *local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  iVar1 = param_2;
  iVar2 = (**(code **)(*param_1 + 0x24))(param_2,0);
  if (iVar2 == 0) {
    local_8 = 0;
    local_14 = *(int **)(param_2 + 0xc);
    param_2 = 0xffffffff;
    if (local_14 != (int *)0x0) {
      piVar3 = *(int **)(iVar1 + 0x10);
      do {
        iVar2 = *(int *)(param_1[5] + *piVar3 * 4);
        uVar4 = *(uint *)(iVar2 + 0x30);
        if (local_8 < uVar4) {
          local_8 = uVar4;
        }
        uVar4 = *(uint *)(iVar2 + 0x2c);
        if (uVar4 < param_2) {
          param_2 = uVar4;
        }
        piVar3 = piVar3 + 1;
        local_14 = (int *)((int)local_14 + -1);
      } while (local_14 != (int *)0x0);
    }
    local_18 = *(int *)(iVar1 + 4);
    if (local_18 != 0) {
      local_14 = *(int **)(iVar1 + 8);
      do {
        piVar3 = *(int **)(param_1[5] + *local_14 * 4);
        if (((*(byte *)(*(int *)(param_1[4] + *piVar3 * 4) + 4) & 2) != 0) && (piVar3[0xb] != -1)) {
          uVar4 = piVar3[0xb] + 1;
          if (local_8 < uVar4) {
            local_8 = uVar4;
          }
          while (uVar4 = piVar3[0xd], uVar4 <= param_2) {
            if ((uVar4 == 0xffffffff) || (uVar5 = 0, param_4 == 0)) {
LAB_00614b06:
              param_2 = piVar3[0xd] - 1;
              break;
            }
            do {
              if (*(int *)(param_3 + uVar5 * 4) == *(int *)(param_1[6] + uVar4 * 4)) break;
              uVar5 = uVar5 + 1;
            } while (uVar5 < param_4);
            if (param_4 <= uVar5) goto LAB_00614b06;
            iVar2 = *(int *)(param_3 + uVar5 * 4);
            local_c = 0;
            if (*(int *)(iVar2 + 0xc) != 0) {
              local_10 = *(int **)(iVar2 + 0x10);
              do {
                if (piVar3[3] == *(int *)(*(int *)(param_1[5] + *local_10 * 4) + 0xc)) break;
                local_c = local_c + 1;
                local_10 = local_10 + 1;
              } while (local_c < *(uint *)(iVar2 + 0xc));
            }
            if (*(uint *)(iVar2 + 0xc) <= local_c) goto LAB_00614b06;
            piVar3 = *(int **)(param_1[5] + *(int *)(*(int *)(iVar2 + 0x10) + local_c * 4) * 4);
          }
        }
        local_14 = local_14 + 1;
        local_18 = local_18 + -1;
      } while (local_18 != 0);
    }
    uVar4 = 0;
    if (param_4 == 0) {
      uVar5 = 0;
    }
    else {
      do {
        uVar5 = *(uint *)(*(int *)(param_1[5] + **(int **)(*(int *)(param_3 + uVar4 * 4) + 0x10) * 4
                                  ) + 0x2c);
        if ((local_8 <= uVar5) && (uVar5 <= param_2)) break;
        uVar4 = uVar4 + 1;
      } while (uVar4 < param_4);
    }
    if ((uVar4 != param_4) && (iVar2 = (**(code **)(*param_1 + 0x34))(iVar1,uVar5), iVar2 == 0)) {
      uVar4 = 0;
      if (param_4 != 0) {
        do {
          **(undefined4 **)(param_3 + uVar4 * 4) = 0;
          uVar4 = uVar4 + 1;
        } while (uVar4 < param_4);
      }
      if (*(int *)(param_1[6] + uVar5 * 4) != 0) {
        FUN_005f7186(1);
      }
      *(int *)(param_1[6] + uVar5 * 4) = iVar1;
      uVar4 = 0;
      if (*(int *)(iVar1 + 0xc) != 0) {
        do {
          iVar2 = uVar4 * 4;
          uVar4 = uVar4 + 1;
          *(uint *)(*(int *)(param_1[5] + *(int *)(*(int *)(iVar1 + 0x10) + iVar2) * 4) + 0x2c) =
               uVar5;
        } while (uVar4 < *(uint *)(iVar1 + 0xc));
      }
      return 0;
    }
  }
  if (iVar1 != 0) {
    FUN_005f7186(1);
  }
  return 1;
}


// ==== 0x614bc0 FUN_00614bc0

undefined4 __fastcall FUN_00614bc0(int param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *local_c;
  int *local_8;
  uint local_4;
  
  puVar1 = *(uint **)(param_1 + 0x98);
  uVar2 = *puVar1 & 0xffffff;
  local_4 = 0;
  if (uVar2 != 0) {
    local_c = (int *)puVar1[2];
    local_8 = local_c + uVar2;
    do {
      piVar5 = *(int **)(*(int *)(param_1 + 0x14) + *local_c * 4);
      piVar4 = *(int **)(*(int *)(param_1 + 0x14) + *local_8 * 4);
      if ((((*piVar5 != *piVar4) || (piVar5[1] != piVar4[1])) || (piVar5[2] != piVar4[2])) ||
         ((piVar5[3] != piVar4[3] || ((piVar4[8] ^ piVar5[8]) != 0x80000)))) {
        return 1;
      }
      local_4 = local_4 + 1;
      local_c = local_c + 1;
      local_8 = local_8 + 1;
    } while (local_4 < uVar2);
  }
  *puVar1 = uVar2 | 0xf0000000;
  *(uint *)(*(int *)(param_1 + 0x98) + 4) = uVar2;
  if ((uVar2 != 0) &&
     (piVar5 = *(int **)(*(int *)(param_1 + 0x98) + 8),
     (*(byte *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar5 * 4) + 0x22) & 8) != 0)) {
    piVar4 = piVar5 + uVar2;
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      *piVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar5 = piVar5 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(char *)piVar5 = (char)*piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
      piVar5 = (int *)((int)piVar5 + 1);
    }
  }
  return 0;
}


// ==== 0x614ca2 FUN_00614ca2

undefined4 __fastcall FUN_00614ca2(int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint local_10;
  int *local_c;
  int *local_8;
  
  puVar1 = *(uint **)(param_1 + 0x98);
  uVar6 = *puVar1 & 0xffffff;
  local_10 = 0;
  if (uVar6 != 0) {
    piVar7 = (int *)puVar1[2];
    local_c = piVar7 + uVar6;
    local_8 = piVar7 + uVar6 * 2;
    do {
      iVar2 = *piVar7;
      iVar3 = *(int *)(*(int *)(param_1 + 0x14) + iVar2 * 4);
      iVar4 = *(int *)(*(int *)(param_1 + 0x14) + *local_8 * 4);
      if ((iVar2 != *local_c) ||
         (((iVar5 = *(int *)(iVar4 + 0x24), iVar5 != iVar2 &&
           ((iVar5 == -1 || (iVar5 != *(int *)(iVar3 + 0x24))))) ||
          ((*(uint *)(iVar4 + 0x20) ^ 0x80000) != *(uint *)(iVar3 + 0x20))))) {
        return 1;
      }
      local_10 = local_10 + 1;
      local_8 = local_8 + 1;
      local_c = local_c + 1;
      piVar7 = piVar7 + 1;
    } while (local_10 < uVar6);
  }
  *puVar1 = uVar6 | 0xf0000000;
  *(uint *)(*(int *)(param_1 + 0x98) + 4) = uVar6;
  return 0;
}


// ==== 0x614d56 FUN_00614d56

undefined4 __thiscall FUN_00614d56(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  uint local_8;
  
  iVar1 = *(int *)(param_1 + 0x14);
  iVar2 = *(int *)(iVar1 + param_2 * 4);
  if ((*(int *)(iVar2 + 0x3c) == *(int *)(iVar2 + 0x38)) &&
     (uVar6 = 0xffffffff, *(int *)(iVar2 + 0x2c) != -1)) {
    puVar3 = *(uint **)(*(int *)(param_1 + 0x18) + *(int *)(iVar2 + 0x2c) * 4);
    if ((*puVar3 & 0xff000000) == 0x24000000) {
      local_8 = 0;
      if (puVar3[3] != 0) {
        piVar4 = (int *)puVar3[4];
        do {
          if (*piVar4 == param_2) {
            uVar6 = local_8;
          }
          local_8 = local_8 + 1;
          piVar4 = piVar4 + 1;
        } while (local_8 < puVar3[3]);
        if (uVar6 != 0xffffffff) {
          piVar4 = (int *)(puVar3[2] + uVar6 * 4);
          piVar7 = (int *)(puVar3[2] + (uVar6 + (*puVar3 & 0xffffff)) * 4);
          piVar5 = piVar4;
          if (((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + **(int **)(iVar1 + *piVar7 * 4) * 4)
                           + 4) & 0x80) != 0) ||
               (piVar5 = piVar7, piVar7 = piVar4,
               (*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + **(int **)(iVar1 + *piVar4 * 4) * 4) +
                         4) & 0x80) != 0)) &&
              (*(double *)(*(int *)(iVar1 + *piVar7 * 4) + 0x10) == 1.0)) &&
             ((*(uint *)(*(int *)(iVar1 + *piVar5 * 4) + 0x20) & 0xf0000) == 0x80000)) {
            *param_4 = *piVar5;
            *param_3 = (int)puVar3;
            return 0;
          }
        }
      }
    }
  }
  return 1;
}


// ==== 0x614e5c FUN_00614e5c

int __thiscall
FUN_00614e5c(int *param_1,int param_2,undefined4 *param_3,int *param_4,undefined4 *param_5,
            uint *param_6,int param_7,int param_8)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  void *pvVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 *puVar12;
  int *piVar13;
  int local_34 [4];
  undefined4 *local_24 [4];
  uint local_14;
  int local_10;
  int *local_c;
  uint local_8;
  
  local_24[0] = (undefined4 *)0x0;
  local_24[1] = (undefined4 *)0x0;
  local_24[2] = (undefined4 *)0x0;
  uVar9 = *param_6 & 0xffffff;
  local_c = param_1;
  local_14 = uVar9;
  local_24[3] = (undefined4 *)0x0;
  if ((*(byte *)((int)param_1 + 0x93) & 1) == 0) {
    uVar11 = 0;
    if (uVar9 != 0) {
      do {
        iVar4 = FUN_00614d56(*(undefined4 *)(param_2 + uVar11 * 4),local_24 + uVar11,
                             local_34 + uVar11);
        if (iVar4 != 0) {
          return iVar4;
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar9);
    }
    local_8 = 0;
    if (uVar9 != 0) {
      local_10 = (int)local_24 - (int)param_4;
      piVar5 = param_4;
      do {
        if (((*(int *)(*(int *)(param_1[5] +
                               *(int *)(((int)local_34 - (int)param_4) + (int)piVar5) * 4) + 0x24)
              != *piVar5) || ((*(byte *)(*(int *)(param_1[5] + *piVar5 * 4) + 0x22) & 0xf) != 0)) ||
           (*(undefined4 **)(((int)local_24 - (int)param_4) + (int)piVar5) != local_24[0]))
        goto LAB_0061512d;
        local_8 = local_8 + 1;
        piVar5 = piVar5 + 1;
      } while (local_8 < uVar9);
    }
    uVar11 = 0;
    if (local_24[0][3] != 0) {
      do {
        uVar8 = 0;
        local_8 = 1;
        if (uVar9 == 0) goto LAB_0061512d;
        do {
          if (*(int *)(local_24[0][4] + uVar11 * 4) == *(int *)(param_2 + uVar8 * 4)) {
            local_8 = 0;
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < uVar9);
        if (local_8 != 0) goto LAB_0061512d;
        uVar11 = uVar11 + 1;
      } while (uVar11 < (uint)local_24[0][3]);
    }
  }
  else {
    local_8 = 0;
    if (uVar9 != 0) {
      piVar5 = param_4;
      do {
        iVar4 = *(int *)(param_1[5] + *(int *)((param_2 - (int)param_4) + (int)piVar5) * 4);
        if ((*(int *)(iVar4 + 0x24) != *piVar5) || ((*(uint *)(iVar4 + 0x20) & 0xf0000) != 0x10000))
        goto LAB_0061512d;
        iVar4 = *(int *)(param_1[5] + *piVar5 * 4);
        uVar11 = *(uint *)(iVar4 + 0x20);
        if (((uVar11 & 0xf0000) != 0) ||
           (((uVar11 & 0x200) == 0 &&
            ((uVar11 = *(uint *)(iVar4 + 0x18), (uVar11 & 4) == 0 || ((uVar11 & 0x10) == 0))))))
        goto LAB_0061512d;
        local_8 = local_8 + 1;
        piVar5 = piVar5 + 1;
      } while (local_8 < uVar9);
    }
  }
  pvVar6 = _malloc(0x38);
  if (pvVar6 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_005f7709();
  }
  if (iVar4 == 0) {
    iVar7 = -0x7ff8fff2;
  }
  else {
    iVar7 = FUN_005f7760(uVar9 | 0xf1000000,uVar9 * 3,uVar9,0);
    if ((-1 < iVar7) && (iVar7 = FUN_005f7a42(param_6), piVar5 = local_c, -1 < iVar7)) {
      puVar10 = *(undefined4 **)(param_7 + 0x10);
      puVar12 = *(undefined4 **)(iVar4 + 0x10);
      for (uVar11 = uVar9; uVar11 != 0; uVar11 = uVar11 - 1) {
        *puVar12 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar12 = puVar12 + 1;
      }
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar12 = (undefined4 *)((int)puVar12 + 1);
      }
      piVar13 = *(int **)(iVar4 + 8);
      for (uVar11 = uVar9; uVar11 != 0; uVar11 = uVar11 - 1) {
        *piVar13 = *param_4;
        param_4 = param_4 + 1;
        piVar13 = piVar13 + 1;
      }
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(char *)piVar13 = (char)*param_4;
        param_4 = (int *)((int)param_4 + 1);
        piVar13 = (int *)((int)piVar13 + 1);
      }
      puVar10 = (undefined4 *)(*(int *)(iVar4 + 8) + local_14 * 8);
      for (uVar11 = uVar9; uVar11 != 0; uVar11 = uVar11 - 1) {
        *puVar10 = *param_3;
        param_3 = param_3 + 1;
        puVar10 = puVar10 + 1;
      }
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(undefined1 *)puVar10 = *(undefined1 *)param_3;
        param_3 = (undefined4 *)((int)param_3 + 1);
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      puVar10 = (undefined4 *)(*(int *)(iVar4 + 8) + uVar9 * 4);
      for (; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar10 = *param_5;
        param_5 = param_5 + 1;
        puVar10 = puVar10 + 1;
      }
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(undefined1 *)puVar10 = *(undefined1 *)param_5;
        param_5 = (undefined4 *)((int)param_5 + 1);
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      iVar7 = local_c[5];
      piVar13 = *(int **)(iVar7 + **(int **)(iVar4 + 0x10) * 4);
      piVar1 = *(int **)(iVar7 + **(int **)(iVar4 + 8) * 4);
      piVar2 = *(int **)(iVar7 + (*(int **)(iVar4 + 8))[local_14 * 2] * 4);
      iVar7 = *piVar13;
      bVar3 = false;
      if (((((iVar7 == *piVar1) && (piVar13[2] == piVar1[2])) ||
           ((iVar7 == *piVar2 && (piVar13[2] == piVar2[2])))) || (iVar7 != local_c[0x18])) &&
         ((*(byte *)((int)local_c + 0x93) & 1) == 0)) {
        bVar3 = true;
      }
      iVar7 = (**(code **)(*local_c + 0x24))(iVar4,0);
      if ((iVar7 != 0) || (bVar3)) {
        FUN_005f7186(1);
LAB_0061512d:
        iVar7 = 1;
      }
      else {
        if (*(int *)(param_8 * 4 + piVar5[6]) != 0) {
          FUN_005f7186(1);
        }
        *(int *)(param_8 * 4 + piVar5[6]) = iVar4;
        *param_6 = 0;
        if (local_24[0] != (undefined4 *)0x0) {
          *local_24[0] = 0;
        }
        iVar7 = 0;
      }
    }
  }
  return iVar7;
}


// ==== 0x615137 FUN_00615137

undefined4 __thiscall FUN_00615137(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x14) + param_2 * 4);
  uVar6 = *(uint *)(iVar1 + 0x38);
  if (((uVar6 != 0xffffffff) && ((*(byte *)(param_1 + 0x93) & 8) == 0)) &&
     (uVar6 <= *(uint *)(iVar1 + 0x3c))) {
    do {
      iVar2 = *(int *)(*(int *)(param_1 + 0x18) + uVar6 * 4);
      iVar4 = FUN_005f7b45();
      if (iVar4 != 0) {
        uVar3 = *(uint *)(iVar2 + 4);
        uVar5 = 0;
        if (uVar3 != 0) {
          piVar7 = *(int **)(iVar2 + 8);
          do {
            if (*piVar7 == param_2) {
              return 1;
            }
            uVar5 = uVar5 + 1;
            piVar7 = piVar7 + 1;
          } while (uVar5 < uVar3);
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 <= *(uint *)(iVar1 + 0x3c));
  }
  return 0;
}


// ==== 0x6151a7 FUN_006151a7

int __fastcall FUN_006151a7(int *param_1)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *piVar10;
  int local_114 [4];
  undefined4 local_104 [4];
  undefined4 local_f4 [4];
  int local_e4 [28];
  int *local_74 [16];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int *local_24;
  undefined4 *local_20;
  uint local_1c;
  uint local_18;
  int *local_14;
  uint local_10;
  uint local_c;
  int *local_8;
  
  local_10 = 0;
  local_34 = 0;
  uVar6 = *(uint *)param_1[0x26] & 0xffffff;
  local_30 = 1;
  local_2c = 2;
  local_28 = 3;
  local_24 = param_1;
  local_1c = uVar6;
  iVar2 = FUN_006139d8((uint *)param_1[0x26],&DAT_006a62d8,local_74,&local_10,local_114,&local_34,
                       uVar6);
  if ((iVar2 != 0) &&
     (iVar2 = FUN_006139d8(param_1[0x26],&DAT_006a6338,local_74,&local_10,local_114,&local_34,uVar6)
     , iVar2 != 0)) {
    return 1;
  }
  local_18 = 0;
  local_14 = local_114;
  local_20 = local_104;
  do {
    local_c = 0;
    if (uVar6 != 0) {
      local_8 = local_14;
      do {
        piVar1 = *(int **)(param_1[5] + *local_8 * 4);
        piVar8 = *(int **)(param_1[5] + local_e4[local_c] * 4);
        if ((((*piVar1 != *piVar8) || (piVar1[1] != piVar8[1])) || (piVar1[2] != piVar8[2])) ||
           ((piVar1[3] != piVar8[3] || ((piVar8[8] ^ piVar1[8]) != 0x80000)))) break;
        local_c = local_c + 1;
        local_8 = local_8 + 1;
      } while (local_c < uVar6);
    }
    if (local_c == uVar6) {
      pvVar3 = _malloc(0x38);
      if (pvVar3 == (void *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_005f7709();
      }
      if (iVar2 == 0) {
        return -0x7ff8fff2;
      }
      local_8 = (int *)FUN_005f7760(uVar6 & 0xffffff | 0xf1000000,uVar6 * 3,uVar6,0);
      if ((int)local_8 < 0) {
LAB_0061544b:
        FUN_005f7186(1);
        return (int)local_8;
      }
      local_8 = (int *)FUN_005f7a42(param_1[0x26]);
      piVar1 = local_24;
      if ((int)local_8 < 0) goto LAB_0061544b;
      puVar7 = *(undefined4 **)(param_1[0x26] + 0x10);
      puVar9 = *(undefined4 **)(iVar2 + 0x10);
      for (uVar4 = uVar6 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      puVar7 = local_f4;
      puVar9 = *(undefined4 **)(iVar2 + 8);
      for (uVar4 = uVar6 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      puVar7 = local_20;
      puVar9 = (undefined4 *)(*(int *)(iVar2 + 8) + uVar6 * 4);
      for (uVar4 = uVar6 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      local_c = 0;
      piVar8 = local_e4;
      piVar10 = (int *)(*(int *)(iVar2 + 8) + local_1c * 8);
      for (uVar6 = uVar6 & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
        *piVar10 = *piVar8;
        piVar8 = piVar8 + 1;
        piVar10 = piVar10 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(char *)piVar10 = (char)*piVar8;
        piVar8 = (int *)((int)piVar8 + 1);
        piVar10 = (int *)((int)piVar10 + 1);
      }
      iVar5 = local_24[5];
      local_8 = *(int **)(iVar5 + **(int **)(iVar2 + 0x10) * 4);
      piVar8 = *(int **)(iVar5 + **(int **)(iVar2 + 8) * 4);
      piVar10 = *(int **)(iVar5 + (*(int **)(iVar2 + 8))[local_1c * 2] * 4);
      iVar5 = *local_8;
      if (((((iVar5 == *piVar8) && (local_8[2] == piVar8[2])) ||
           ((iVar5 == *piVar10 && (local_8[2] == piVar10[2])))) || (iVar5 != local_24[0x18])) &&
         ((*(byte *)((int)local_24 + 0x93) & 1) == 0)) {
        local_c = 1;
      }
      iVar5 = (**(code **)(*local_24 + 0x24))(iVar2,0);
      if ((iVar5 == 0) && (local_c == 0)) {
        local_8 = (int *)*local_74[0];
        *local_74[0] = 0;
        iVar5 = (**(code **)(*piVar1 + 0x34))(iVar2,piVar1[0x25]);
        if (iVar5 == 0) {
          if ((((*(byte *)((int)piVar1 + 0x93) & 1) != 0) &&
              ((*(byte *)((int)piVar8 + 0x21) & 2) == 0)) &&
             (((piVar8[6] & 4U) == 0 || ((piVar8[6] & 0x10U) == 0)))) {
            FUN_005f7186(1);
            FUN_005fbf37(piVar1,*(undefined4 *)(piVar1[0x26] + 0x34),0x125f,
                         "cannot match lerp because lerp factor is not _sat\'d");
            *local_74[0] = (int)local_8;
            return 1;
          }
          uVar6 = 0;
          if (local_10 != 0) {
            do {
              *local_74[uVar6] = 0;
              uVar6 = uVar6 + 1;
            } while (uVar6 < local_10);
          }
          if (*(int *)(piVar1[6] + piVar1[0x25] * 4) != 0) {
            FUN_005f7186(1);
          }
          *(int *)(piVar1[6] + piVar1[0x25] * 4) = iVar2;
          return 0;
        }
        *local_74[0] = (int)local_8;
        uVar6 = local_1c;
        param_1 = local_24;
      }
      else {
        FUN_005f7186(1);
        uVar6 = local_1c;
        param_1 = local_24;
      }
    }
    local_18 = local_18 + 1;
    local_14 = local_14 + 4;
    local_20 = local_20 + -4;
    if (1 < local_18) {
      return 1;
    }
  } while( true );
}


// ==== 0x6154dc FUN_006154dc

undefined4 __thiscall FUN_006154dc(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  
  if (param_3 == param_4) {
    uVar3 = 0;
  }
  else if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + param_2 * 4) + 5) & 1) == 0) {
    uVar1 = *(uint *)(param_1 + 8);
    uVar6 = 0;
    if (uVar1 != 0) {
      piVar4 = *(int **)(param_1 + 0x14);
      do {
        piVar2 = (int *)*piVar4;
        if (((*piVar2 == param_2) && (piVar2[7] != 0)) &&
           ((piVar2[2] == param_3 || (piVar2[2] == param_4)))) goto LAB_006154fd;
        uVar6 = uVar6 + 1;
        piVar4 = piVar4 + 1;
      } while (uVar6 < uVar1);
    }
    uVar6 = 0;
    if (uVar1 != 0) {
      do {
        piVar4 = *(int **)(*(int *)(param_1 + 0x14) + uVar6 * 4);
        if ((*piVar4 == param_2) &&
           ((iVar5 = param_4, piVar4[2] == param_3 || (iVar5 = param_3, piVar4[2] == param_4)))) {
          piVar4[2] = iVar5;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(param_1 + 8));
    }
    uVar3 = 0;
  }
  else {
LAB_006154fd:
    uVar3 = 0x80004005;
  }
  return uVar3;
}


// ==== 0x61556b FUN_0061556b

uint * __thiscall
FUN_0061556b(int param_1,uint param_2,int param_3,uint *param_4,int *param_5,uint param_6)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 local_34 [4];
  int *local_24;
  undefined4 *local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  int *local_c;
  uint local_8;
  
  local_24 = (int *)**(int **)(param_3 + 0x10);
  iVar9 = *(int *)(param_1 + 0x14);
  iVar1 = *(int *)(iVar9 + (int)local_24 * 4);
  local_14 = *(uint *)(iVar1 + 0x2c);
  local_18 = *(uint *)(iVar1 + 0x38);
  local_1c = param_1;
  if (local_18 != 0xffffffff) {
    local_8 = 0;
    if (*(int *)(param_3 + 4) != 0) {
      local_c = *(int **)(param_3 + 8);
      do {
        piVar5 = *(int **)(iVar9 + *local_c * 4);
        if (((*(int *)(param_1 + 0x60) == *piVar5) && (uVar6 = piVar5[0xd], local_14 < uVar6)) &&
           (uVar6 < local_18)) {
          return (uint *)0x0;
        }
        local_8 = local_8 + 1;
        local_c = local_c + 1;
      } while (local_8 < *(uint *)(param_3 + 4));
    }
    puVar2 = *(uint **)(*(int *)(param_1 + 0x18) + local_18 * 4);
    local_10 = *puVar2;
    if (param_2 == local_10) {
      uVar6 = *(uint *)(param_3 + 0xc);
      local_8 = 0;
      if (uVar6 != 0) {
        local_c = *(int **)(param_3 + 0x10);
        do {
          iVar1 = *(int *)(iVar9 + *local_c * 4);
          if (*(uint *)(iVar1 + 0x38) != local_18) {
            return (uint *)0x0;
          }
          if (*(uint *)(iVar1 + 0x3c) != local_18) {
            return (uint *)0x0;
          }
          if (uVar6 == 1) {
            if (*(int *)(iVar1 + 0x40) != (param_2 & 0xffffff) * param_6) {
              return (uint *)0x0;
            }
          }
          else if (*(int *)(iVar1 + 0x40) != param_6) {
            return (uint *)0x0;
          }
          local_8 = local_8 + 1;
          uVar6 = *(uint *)(param_3 + 0xc);
          local_c = local_c + 1;
        } while (local_8 < uVar6);
      }
      uVar6 = local_10 & 0xffffff;
      if ((puVar2[3] == uVar6) && (puVar2[1] <= uVar6 * (int)param_5)) {
        local_8 = 0;
        uVar7 = 0;
        if (puVar2[1] != 0) {
          piVar5 = (int *)puVar2[2];
          do {
            piVar3 = *(int **)(iVar9 + *piVar5 * 4);
            if ((*(int *)(param_1 + 0x60) == *piVar3) && (local_14 < (uint)piVar3[0xb])) {
              return (uint *)0x0;
            }
            local_8 = local_8 + 1;
            uVar7 = puVar2[1];
            piVar5 = piVar5 + 1;
          } while (local_8 < uVar7);
        }
        local_8 = 0;
        if (uVar7 != 0) {
          piVar5 = (int *)puVar2[2];
          do {
            if ((int *)*piVar5 == local_24) break;
            local_8 = local_8 + 1;
            piVar5 = piVar5 + 1;
          } while (local_8 < uVar7);
        }
        if (local_8 != uVar7) {
          if ((uVar6 <= local_8) && (uVar7 = 0, uVar6 != 0)) {
            iVar9 = uVar6 << 2;
            do {
              puVar8 = (undefined4 *)(puVar2[2] + uVar7 * 4);
              uVar4 = *puVar8;
              *puVar8 = *(undefined4 *)(iVar9 + puVar2[2]);
              *(undefined4 *)(iVar9 + puVar2[2]) = uVar4;
              uVar7 = uVar7 + 1;
              iVar9 = iVar9 + 4;
            } while (uVar7 < uVar6);
          }
          if (1 < *(uint *)(param_3 + 0xc)) {
            puVar8 = *(undefined4 **)(param_3 + 8);
            local_20 = puVar8 + *(int *)(param_3 + 4);
            if (puVar8 < puVar8 + *(int *)(param_3 + 4)) {
              do {
                if (uVar6 != 0) {
                  local_24 = *(int **)(param_3 + 0x10);
                  uVar7 = puVar2[2];
                  puVar10 = puVar8;
                  local_14 = uVar6;
                  do {
                    param_6 = 0;
                    param_5 = local_24;
                    do {
                      if (*param_5 == *(int *)((uVar7 - (int)puVar8) + (int)puVar10)) {
                        local_34[param_6] = *puVar10;
                        break;
                      }
                      param_6 = param_6 + 1;
                      param_5 = param_5 + 1;
                    } while (param_6 < uVar6);
                    puVar10 = puVar10 + 1;
                    local_14 = local_14 - 1;
                  } while (local_14 != 0);
                }
                puVar10 = local_34;
                puVar11 = puVar8;
                for (uVar7 = uVar6; uVar7 != 0; uVar7 = uVar7 - 1) {
                  *puVar11 = *puVar10;
                  puVar10 = puVar10 + 1;
                  puVar11 = puVar11 + 1;
                }
                for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                  *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
                  puVar10 = (undefined4 *)((int)puVar10 + 1);
                  puVar11 = (undefined4 *)((int)puVar11 + 1);
                }
                puVar8 = puVar8 + uVar6;
              } while (puVar8 < local_20);
            }
          }
          if (param_4 == (uint *)0x0) {
            return puVar2;
          }
          *param_4 = local_18;
          return puVar2;
        }
      }
    }
  }
  return (uint *)0x0;
}


// ==== 0x6157c4 FUN_006157c4

undefined4 __thiscall FUN_006157c4(int param_1,uint param_2,uint *param_3,int *param_4,int param_5)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  uint local_18;
  int local_10;
  
  uVar7 = *param_3 & 0xffffff;
  if (uVar7 != 0) {
    uVar3 = param_3[1] / uVar7;
    if (uVar3 != 0) {
      local_10 = 0;
      piVar9 = param_4;
      local_18 = uVar3;
      do {
        iVar5 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)(local_10 + param_3[2]) * 4);
        uVar4 = *(uint *)(iVar5 + 0x38);
        uVar8 = *(uint *)(iVar5 + 0x2c);
        if (uVar8 == 0xffffffff) {
LAB_00615952:
          *piVar9 = 0;
        }
        else {
          puVar2 = *(uint **)(*(int *)(param_1 + 0x18) + uVar8 * 4);
          *piVar9 = (int)puVar2;
          iVar5 = local_10;
          for (uVar1 = uVar7; uVar1 != 0; uVar1 = uVar1 - 1) {
            piVar6 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)(iVar5 + param_3[2]) * 4);
            if (*(int *)(param_1 + 0x60) != *piVar6) {
              *piVar9 = 0;
            }
            if (piVar6[8] != 0) {
              *piVar9 = 0;
            }
            if ((uVar8 < (uint)piVar6[0xd]) && ((uint)piVar6[0xd] < uVar4)) {
              *piVar9 = 0;
            }
            if (piVar6[0xe] != piVar6[0xf]) {
              *piVar9 = 0;
            }
            iVar5 = iVar5 + 4;
          }
          if (*piVar9 != 0) {
            uVar4 = uVar7;
            iVar5 = local_10;
            if (param_2 == *puVar2) {
              for (; uVar4 != 0; uVar4 = uVar4 - 1) {
                if (*(uint *)(*(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar5 + param_3[2]) * 4)
                             + 0x2c) != uVar8) {
                  *piVar9 = 0;
                }
                iVar5 = iVar5 + 4;
              }
              if (*piVar9 == 0) goto LAB_00615955;
              if ((puVar2[3] == (*puVar2 & 0xffffff)) &&
                 (puVar2[1] <= (*puVar2 & 0xffffff) * param_5)) {
                uVar4 = param_3[1];
                uVar8 = 0;
                if (uVar4 != 0) {
                  piVar6 = (int *)param_3[2];
                  do {
                    if (*piVar6 == *(int *)puVar2[4]) break;
                    uVar8 = uVar8 + 1;
                    piVar6 = piVar6 + 1;
                  } while (uVar8 < uVar4);
                }
                if (uVar8 != uVar4) {
                  if (1 < puVar2[3]) {
                    if ((puVar2[3] != uVar7) || (uVar4 < uVar8 + uVar7)) {
                      *piVar9 = 0;
                    }
                    uVar4 = 0;
                    if (uVar7 != 0) {
                      iVar5 = uVar8 << 2;
                      do {
                        if (*(int *)(puVar2[4] + uVar4 * 4) != *(int *)(iVar5 + param_3[2])) {
                          *piVar9 = 0;
                        }
                        uVar4 = uVar4 + 1;
                        iVar5 = iVar5 + 4;
                      } while (uVar4 < uVar7);
                    }
                  }
                  goto LAB_00615955;
                }
              }
            }
            goto LAB_00615952;
          }
        }
LAB_00615955:
        local_10 = local_10 + uVar7 * 4;
        piVar9 = piVar9 + 1;
        local_18 = local_18 - 1;
      } while (local_18 != 0);
    }
    uVar7 = 0;
    if (uVar3 != 0) {
      do {
        if (param_4[uVar7] != 0) {
          return 0;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar3);
    }
  }
  return 1;
}


// ==== 0x615991 FUN_00615991

int __thiscall FUN_00615991(int param_1,int param_2,uint param_3,uint param_4)

{
  void *pvVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  pvVar1 = _malloc(0x38);
  if (pvVar1 == (void *)0x0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_005f7709();
  }
  if (local_8 == 0) {
    iVar4 = -0x7ff8fff2;
  }
  else {
    local_c = 0;
    if (param_4 != 0) {
      piVar2 = *(int **)(*(int *)(param_1 + 0x98) + 0x10);
      uVar3 = param_4;
      do {
        if (*(int *)(param_2 + *(int *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar2 * 4) + 0xc) * 4)
            != -1) {
          local_c = local_c + 1;
        }
        piVar2 = piVar2 + 1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    iVar4 = FUN_005f7760(**(uint **)(param_1 + 0x98) & 0xff000000 | local_c,local_c * param_3,
                         local_c,0);
    if ((-1 < iVar4) && (iVar4 = FUN_005f7a42(*(undefined4 *)(param_1 + 0x98)), -1 < iVar4)) {
      local_10 = 0;
      if (param_3 != 0) {
        do {
          uVar3 = 0;
          local_14 = 0;
          if (param_4 != 0) {
            do {
              if (*(int *)(param_2 +
                          *(int *)(*(int *)(*(int *)(param_1 + 0x14) +
                                           *(int *)(*(int *)(*(int *)(param_1 + 0x98) + 0x10) +
                                                   uVar3 * 4) * 4) + 0xc) * 4) != -1) {
                *(undefined4 *)(*(int *)(local_8 + 8) + (local_10 * local_c + local_14) * 4) =
                     *(undefined4 *)
                      (*(int *)(*(int *)(param_1 + 0x98) + 8) + (local_10 * param_4 + uVar3) * 4);
                if (local_10 == 0) {
                  *(undefined4 *)(*(int *)(local_8 + 0x10) + local_14 * 4) =
                       *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x98) + 0x10) + uVar3 * 4);
                }
                local_14 = local_14 + 1;
              }
              uVar3 = uVar3 + 1;
            } while (uVar3 < param_4);
          }
          local_10 = local_10 + 1;
        } while (local_10 < param_3);
      }
      iVar4 = FUN_005f73c0(local_8);
      if (-1 < iVar4) {
        local_8 = 0;
        iVar4 = 0;
      }
    }
    if (local_8 != 0) {
      FUN_005f7186(1);
    }
  }
  return iVar4;
}


// ==== 0x615af3 FUN_00615af3

undefined4 FUN_00615af3(undefined4 param_1)

{
  return param_1;
}


// ==== 0x615afa FUN_00615afa

undefined4 FUN_00615afa(void)

{
  return 0;
}


// ==== 0x615aff FUN_00615aff

int FUN_00615aff(int param_1)

{
  int iVar1;
  int iVar2;
  
  while( true ) {
    while( true ) {
      if (param_1 == 0) {
        return 0;
      }
      iVar1 = *(int *)(param_1 + 4);
      if (iVar1 == 1) {
        iVar1 = FUN_00615aff(*(undefined4 *)(param_1 + 0xc));
        iVar2 = FUN_00615aff(*(undefined4 *)(param_1 + 8));
        return iVar2 + iVar1;
      }
      if (iVar1 != 5) break;
      param_1 = *(int *)(param_1 + 0x18);
    }
    if (iVar1 == 7) {
      iVar1 = FUN_00615aff(*(undefined4 *)(param_1 + 0x10));
      return iVar1 * *(int *)(param_1 + 0x14);
    }
    if (iVar1 == 8) break;
    if (iVar1 != 10) {
      return 0;
    }
    param_1 = *(int *)(param_1 + 0x20);
  }
  return *(int *)(param_1 + 0x1c) * *(int *)(param_1 + 0x18);
}


// ==== 0x615b5d FUN_00615b5d

int FUN_00615b5d(undefined4 param_1,int param_2,uint param_3,int param_4)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  void *_Memory;
  int iVar4;
  void *pvVar5;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_4 == 0) {
    iVar3 = 0;
  }
  else {
    for (; iVar3 = *(int *)(param_2 + 4), iVar3 != 1; param_2 = *(int *)(param_2 + 0x10)) {
      if (iVar3 != 7) {
        if (iVar3 != 8) {
          return -0x7fffbffb;
        }
        uVar1 = 0;
        local_8 = 0;
        iVar3 = *(int *)(param_2 + 0x10);
        if (iVar3 == 0) {
          uVar1 = 0;
        }
        else if (iVar3 == 1) {
          uVar1 = 1;
        }
        else if (iVar3 == 2) {
          uVar1 = (byte)~(byte)(*(uint *)(param_2 + 0x20) >> 10) & 1 | 2;
        }
        else if (iVar3 == 3) {
          uVar1 = 4;
        }
        switch(*(undefined4 *)(param_2 + 0x14)) {
        case 0:
          local_14 = CONCAT22(1,uVar1);
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
          local_14 = CONCAT22(2,uVar1);
          break;
        case 9:
        case 10:
        case 0xb:
        case 0xc:
          local_14 = CONCAT22(3,uVar1);
          break;
        case 0xe:
          local_14 = CONCAT22(4,uVar1);
          break;
        case 0xf:
          local_14 = CONCAT22(5,uVar1);
          break;
        case 0x10:
          local_14 = CONCAT22(6,uVar1);
          break;
        case 0x11:
          local_14 = CONCAT22(7,uVar1);
          break;
        case 0x12:
          local_14 = CONCAT22(8,uVar1);
          break;
        case 0x13:
          local_14 = CONCAT22(9,uVar1);
          break;
        case 0x14:
          local_14 = CONCAT22(10,uVar1);
          break;
        case 0x15:
          local_14 = CONCAT22(0xb,uVar1);
          break;
        case 0x16:
          local_14 = CONCAT22(0xc,uVar1);
          break;
        case 0x17:
          local_14 = CONCAT22(0xd,uVar1);
          break;
        case 0x18:
          local_14 = CONCAT22(0xe,uVar1);
          break;
        case 0x19:
          local_14 = CONCAT22(0xf,uVar1);
          break;
        case 0x1a:
          local_14 = CONCAT22(0x10,uVar1);
          break;
        case 0x1b:
          local_14 = CONCAT22(0x11,uVar1);
          break;
        case 0x1c:
          local_14 = CONCAT22(0x12,uVar1);
          break;
        default:
          local_14 = (uint)uVar1;
        }
        local_10 = CONCAT22(*(undefined2 *)(param_2 + 0x1c),*(undefined2 *)(param_2 + 0x18));
        local_c = param_3 & 0xffff;
        iVar3 = FUN_0061319b(&local_14,0x10,2,param_4);
        goto LAB_00615db0;
      }
      param_3 = param_3 * *(int *)(param_2 + 0x14);
    }
    local_c = 0;
    local_8 = 0;
    local_14 = 5;
    local_10 = 1;
    uVar2 = FUN_00615aff(param_2);
    local_10 = CONCAT22(uVar2,(undefined2)local_10);
    iVar3 = param_2;
    do {
      local_c._2_2_ = local_c._2_2_ + 1;
      iVar3 = *(int *)(iVar3 + 0xc);
    } while (iVar3 != 0);
    _Memory = _malloc((uint)local_c._2_2_ << 3);
    pvVar5 = _Memory;
    if (_Memory == (void *)0x0) {
      iVar3 = -0x7ff8fff2;
    }
    else {
      do {
        iVar3 = *(int *)(*(int *)(param_2 + 8) + 0x18);
        iVar4 = FUN_0061319b(*(undefined4 *)(*(int *)(*(int *)(param_2 + 8) + 0x14) + 0x18),
                             0xffffffff,7,pvVar5);
        if (iVar4 < 0) {
          _free(_Memory);
          return iVar4;
        }
        iVar3 = FUN_00615b5d(param_1,*(undefined4 *)(iVar3 + 0x20),1,(int)pvVar5 + 4);
        if (iVar3 < 0) {
          _free(_Memory);
          return iVar3;
        }
        param_2 = *(int *)(param_2 + 0xc);
        pvVar5 = (void *)((int)pvVar5 + 8);
      } while (param_2 != 0);
      iVar3 = FUN_0061319b(_Memory,(uint)local_c._2_2_ << 3,2,&local_8);
      _free(_Memory);
      if (-1 < iVar3) {
        iVar3 = FUN_0061319b(&local_14,0x10,2,param_4);
LAB_00615db0:
        if (-1 < iVar3) {
          iVar3 = 0;
        }
      }
    }
  }
  return iVar3;
}


// ==== 0x615e2f FUN_00615e2f

undefined4 __thiscall FUN_00615e2f(int param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  uVar2 = *(uint *)(param_1 + 0xa8);
  uVar4 = uVar2;
  if (uVar2 == 0) {
    uVar4 = 0x400;
  }
  if (uVar4 < (uint)(*(int *)(param_1 + 0xa4) + param_2)) {
    do {
      uVar4 = uVar4 * 2;
    } while (uVar4 < (uint)(param_2 + *(int *)(param_1 + 0xa4)));
  }
  if (uVar4 != uVar2) {
    puVar1 = _malloc(uVar4 << 2);
    if (puVar1 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
    puVar5 = *(undefined4 **)(param_1 + 0xa0);
    puVar6 = puVar1;
    for (uVar2 = *(uint *)(param_1 + 0xa4) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    _free(*(void **)(param_1 + 0xa0));
    *(undefined4 **)(param_1 + 0xa0) = puVar1;
    *(uint *)(param_1 + 0xa8) = uVar4;
  }
  return 0;
}


// ==== 0x615ec7 FUN_00615ec7

undefined4 __thiscall FUN_00615ec7(int *param_1,int *param_2,uint *param_3,undefined4 *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  char *pcVar5;
  uint local_c;
  uint local_8;
  
  local_8 = 0;
  local_c = 0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  iVar2 = *param_2;
  if (param_1[0x18] == iVar2) {
    local_c = param_2[2];
    local_8 = 0;
    if ((uint)param_1[0x1c] <= local_c) {
      pcVar5 = "maximum temp register index exceeded";
      uVar4 = 0x1199;
LAB_00615f3a:
      FUN_005fbec8(param_1,*(undefined4 *)(param_1[0x26] + 0x34),uVar4,pcVar5);
      return 0x88760b59;
    }
    uVar1 = param_1[0x23];
    uVar3 = 0;
    if ((uVar1 != 0) && (uVar1 <= local_c)) {
      local_c = local_c - uVar1;
      uVar3 = 3;
    }
  }
  else if (param_1[0x19] == iVar2) {
    local_8 = 3;
    local_c = 0;
    uVar3 = 3;
    if (param_2[2] != 0) {
      pcVar5 = "maximum address register index exceeded";
      uVar4 = 0x119c;
      local_c = param_2[2];
      goto LAB_00615f3a;
    }
  }
  else {
    if (param_1[0x17] != iVar2) {
      FUN_005fbec8(param_1,0,0,"internal error: unexpected output register type");
      return 0x80004005;
    }
    iVar2 = (**(code **)(*param_1 + 0x70))(param_2,&local_c,&local_8,param_4);
    uVar3 = local_8;
    if (iVar2 < 0) {
      return 0x80004005;
    }
  }
  *param_3 = ((uVar3 | 0xfffffff8) << 0x14 | uVar3 & 0x18) << 8 | local_c & 0x7ff;
  return 0;
}


// ==== 0x615fb0 FUN_00615fb0

undefined4 FUN_00615fb0(void)

{
  return 0x80004005;
}


// ==== 0x615fb8 FUN_00615fb8

undefined4 __thiscall FUN_00615fb8(int param_1,int *param_2,uint param_3,uint *param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint local_c;
  uint local_8;
  
  uVar3 = *(uint *)(*(int *)(*(int *)(param_1 + 0x14) + *param_2 * 4) + 0x20);
  local_c = 0;
  local_8 = 0;
  if ((uVar3 & 0x400) == 0) {
    if ((uVar3 & 0x800) == 0) {
      if ((uVar3 & 0x1000) == 0) {
        if ((uVar3 & 0x2000) == 0) {
          if ((uVar3 & 0x4000) == 0) {
            if ((char)(uVar3 >> 8) < '\0') {
              local_8 = 0xd000000;
            }
          }
          else {
            local_8 = 0xe000000;
          }
        }
        else {
          local_8 = 0xf000000;
        }
      }
      else {
        local_8 = 0x3000000;
      }
    }
    else {
      local_8 = 0x2000000;
    }
  }
  else {
    local_8 = 0x1000000;
  }
  if ((uVar3 & 0x200) != 0) {
    local_8 = CONCAT13(local_8._3_1_,0x100000);
  }
  if (param_5 == 0) {
    uVar3 = 0;
    if (param_3 != 0) {
      do {
        iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x14) + param_2[uVar3] * 4) + 0xc);
        uVar4 = 0;
        if (iVar2 == 0) {
          uVar4 = 0x10000;
        }
        else if (iVar2 == 1) {
          uVar4 = 0x20000;
        }
        else if (iVar2 == 2) {
          uVar4 = 0x40000;
        }
        else if (iVar2 == 3) {
          uVar4 = 0x80000;
        }
        if ((local_c & uVar4) != 0) {
          FUN_005fbec8(param_1,*(undefined4 *)(*(int *)(param_1 + 0x98) + 0x34),0x12d5,
                       "internal error: overlapping output writes");
        }
        local_c = local_c | uVar4;
        uVar3 = uVar3 + 1;
      } while (uVar3 < param_3);
    }
  }
  else {
    local_c = 0xf0000;
  }
  uVar3 = 0;
  if ((*(byte *)(param_1 + 0x92) & 0x40) != 0) {
    if ((local_c & 0x80000) == 0) {
      local_c = 0x70000;
    }
    else if ((local_c & 0x70000) != 0) {
      local_c = 0xf0000;
    }
  }
  if ((((*(byte *)(param_1 + 0x34) & 1) != 0) && (*(int *)(param_1 + 0xb8) != 0)) && (param_3 != 0))
  {
    do {
      piVar1 = param_2 + uVar3;
      iVar2 = uVar3 + *(int *)(param_1 + 0xbc) * 6;
      uVar3 = uVar3 + 1;
      *(int *)(*(int *)(param_1 + 0xb8) + -0x10 + iVar2 * 4) = *piVar1;
    } while (uVar3 < param_3);
  }
  *param_4 = local_8 | local_c;
  return 0;
}


// ==== 0x616118 FUN_00616118

undefined4 __thiscall FUN_00616118(int param_1,int param_2,uint *param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  *param_4 = 1;
  uVar1 = *(uint *)(param_2 + 8);
  *param_3 = uVar1;
  if (uVar1 < *(uint *)(param_1 + 0x6c)) {
    uVar2 = 0;
  }
  else {
    FUN_005fbec8(param_1,*(undefined4 *)(*(int *)(param_1 + 0x98) + 0x34),0x119a,
                 "maximum input register index exceeded");
    uVar2 = 0x80004005;
  }
  return uVar2;
}


// ==== 0x61615c FUN_0061615c

int __thiscall FUN_0061615c(int *param_1,int *param_2,uint *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char *pcVar8;
  int *local_8;
  
  piVar2 = param_2;
  if (param_1[0x18] == *param_2) {
    local_8 = (int *)param_2[2];
    param_2 = (int *)0x0;
    if (local_8 < (int *)param_1[0x1c]) {
      piVar1 = (int *)param_1[0x23];
      if ((piVar1 != (int *)0x0) && (piVar1 <= local_8)) {
        local_8 = (int *)((int)local_8 - (int)piVar1);
        param_2 = (int *)0x3;
      }
LAB_006161d8:
      uVar4 = piVar2[8] & 0xf0000;
      uVar5 = 0;
      if (uVar4 == 0x80000) {
        uVar5 = 0x1000000;
      }
      else if (uVar4 == 0x20000) {
        uVar5 = 0x2000000;
      }
      else if (uVar4 == 0xa0000) {
        uVar5 = 0x3000000;
      }
      else if (uVar4 == 0x60000) {
        uVar5 = 0x4000000;
      }
      else if (uVar4 == 0xe0000) {
        uVar5 = 0x5000000;
      }
      else if (uVar4 == 0x10000) {
        uVar5 = 0x6000000;
      }
      else if (uVar4 == 0x40000) {
        uVar5 = 0x7000000;
      }
      else if (uVar4 == 0xc0000) {
        uVar5 = 0x8000000;
      }
      *param_3 = (((uint)param_2 | 0xfffffff8) << 0x14 | (uint)param_2 & 0x18) << 8 |
                 (uint)local_8 & 0x7ff | uVar5;
      *param_4 = piVar2[1];
      if (piVar2[1] != -1) {
        if (param_1[0x3a] == 0) {
          pcVar8 = "target does not support relative addressing";
          uVar7 = 0x119f;
          uVar6 = *(undefined4 *)(param_1[0x26] + 0x34);
LAB_0061634f:
          FUN_005fbec8(param_1,uVar6,uVar7,pcVar8);
          return -0x7fffbffb;
        }
        *(byte *)((int)param_3 + 1) = *(byte *)((int)param_3 + 1) | 0x20;
      }
      return 0;
    }
    pcVar8 = "maximum temp register index exceeded";
  }
  else {
    uVar4 = *(uint *)(*(int *)(param_1[4] + *param_2 * 4) + 4);
    local_8 = param_1;
    if ((uVar4 & 8) == 0) {
      if ((uVar4 & 0x100) != 0) goto LAB_006161fe;
      if ((uVar4 & 0x40) == 0) {
        pcVar8 = "internal error: unexpected input register type";
        uVar7 = 0;
        uVar6 = 0;
        goto LAB_0061634f;
      }
    }
    else {
      if ((uVar4 & 0x100) == 0) {
        iVar3 = (**(code **)(*param_1 + 0x74))(param_2,&local_8,&param_2);
        if (iVar3 < 0) {
          return iVar3;
        }
        goto LAB_006161d8;
      }
LAB_006161fe:
      if ((uVar4 & 0x40) == 0) {
        local_8 = (int *)param_2[2];
        if ((int *)param_1[0x1e] <= local_8) {
          pcVar8 = "maximum constant register index exceeded";
          uVar6 = 0x119b;
          goto LAB_00616273;
        }
        if (local_8 < (int *)0x800) {
          param_2 = (int *)0x2;
        }
        else if (local_8 < (int *)0x1000) {
          param_2 = (int *)0xb;
        }
        else {
          param_2 = (int *)(0xd - (uint)(local_8 < (int *)0x1800));
        }
        local_8 = (int *)((uint)local_8 & 0x7ff);
        goto LAB_006161d8;
      }
    }
    local_8 = (int *)param_2[2];
    param_2 = (int *)0xa;
    if (local_8 < (int *)param_1[0x22]) goto LAB_006161d8;
    pcVar8 = "maximum sampler register index exceeded";
  }
  uVar6 = 0x1199;
LAB_00616273:
  FUN_005fbec8(param_1,*(undefined4 *)(param_1[0x26] + 0x34),uVar6,pcVar8);
  return -0x7789f4a7;
}


// ==== 0x616363 FUN_00616363

undefined4 __thiscall FUN_00616363(int param_1,int *param_2,uint param_3,uint param_4,uint *param_5)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  uint local_28 [4];
  int local_18 [4];
  int local_8;
  
  uVar7 = 0;
  bVar8 = (param_4 & 0x10000) != 0;
  local_8 = param_1;
  if (bVar8) {
    local_18[0] = 0;
  }
  uVar4 = (uint)bVar8;
  if ((param_4 & 0x20000) != 0) {
    local_18[uVar4] = 1;
    uVar4 = uVar4 + 1;
  }
  if ((param_4 & 0x40000) != 0) {
    local_18[uVar4] = 2;
    uVar4 = uVar4 + 1;
  }
  if ((param_4 & 0x80000) != 0) {
    local_18[uVar4] = 3;
    uVar4 = uVar4 + 1;
  }
  if (uVar4 < param_3) {
    param_3 = uVar4;
  }
  if (param_3 != 0) {
    iVar6 = *(int *)(param_1 + 0x14);
    do {
      if (*(int *)(*(int *)(iVar6 + *param_2 * 4) + 0xc) !=
          *(int *)(*(int *)(iVar6 + param_2[uVar7] * 4) + 0xc)) break;
      uVar7 = uVar7 + 1;
    } while (uVar7 < param_3);
    if (uVar7 < param_3) {
      uVar7 = 0;
      do {
        local_28[uVar7] = uVar7;
        uVar7 = uVar7 + 1;
      } while (uVar7 < 4);
      goto LAB_00616409;
    }
  }
  iVar6 = *(int *)(param_1 + 0x14);
  local_28[0] = *(uint *)(*(int *)(iVar6 + *param_2 * 4) + 0xc);
  local_28[1] = local_28[0];
  local_28[2] = local_28[0];
  local_28[3] = local_28[0];
LAB_00616409:
  uVar7 = 0;
  if (param_3 != 0) {
    do {
      piVar2 = local_18 + uVar7;
      piVar1 = param_2 + uVar7;
      uVar7 = uVar7 + 1;
      local_28[*piVar2] = *(uint *)(*(int *)(iVar6 + *piVar1 * 4) + 0xc);
    } while (uVar7 < param_3);
  }
  uVar4 = 0;
  uVar7 = 0x10;
  puVar5 = local_28;
  do {
    uVar3 = *puVar5;
    puVar5 = puVar5 + 1;
    uVar4 = uVar4 | uVar3 << ((byte)uVar7 & 0x1f);
    uVar7 = uVar7 + 2;
  } while (uVar7 < 0x18);
  *param_5 = uVar4;
  return 0;
}


// ==== 0x616454 FUN_00616454

undefined4 __thiscall
FUN_00616454(int param_1,uint param_2,int param_3,uint param_4,int param_5,uint param_6)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  uVar2 = 0;
  bVar1 = false;
  if (param_6 != 0) {
    do {
      if (*(int *)(param_1 + 0xe4) == *(int *)(param_5 + uVar2 * 4)) {
        bVar1 = true;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_6);
  }
  if ((*(uint *)(param_1 + 0xe0) <= param_2) || (bVar1)) {
    *(undefined4 *)(param_1 + 0xd0) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xd4) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xd8) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xdc) = 0xffffffff;
    local_8 = _malloc(*(int *)(param_1 + 0x70) << 2);
    if (local_8 == (undefined4 *)0x0) {
LAB_00616638:
      uVar7 = 0x8007000e;
      goto LAB_00616626;
    }
    puVar8 = local_8;
    for (uVar2 = *(uint *)(param_1 + 0x70) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar8 = 0xffffffff;
      puVar8 = puVar8 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar8 = 0xff;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    uVar2 = 0;
    if (*(int *)(param_1 + 8) != 0) {
      do {
        piVar6 = *(int **)(*(int *)(param_1 + 0x14) + uVar2 * 4);
        if (((*(int *)(param_1 + 0x60) == *piVar6) && (piVar6[1] == -1)) &&
           ((uint)piVar6[2] < *(uint *)(param_1 + 0x70))) {
          if (((uint)piVar6[0xb] < param_2) && (param_2 <= (uint)piVar6[0xf])) {
            local_8[piVar6[2]] = 0;
          }
          uVar5 = piVar6[0xb];
          if ((param_2 <= uVar5) && (uVar5 < (uint)local_8[piVar6[2]])) {
            local_8[piVar6[2]] = uVar5;
          }
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(param_1 + 8));
    }
    uVar2 = 0;
    *(undefined4 *)(param_1 + 0xe4) = 0;
    *(undefined4 *)(param_1 + 0xe0) = 0;
    if (*(int *)(param_1 + 0x70) != 0) {
      do {
        uVar5 = 0;
        if (param_6 == 0) {
LAB_0061654f:
          if (*(uint *)(param_1 + 0xe0) < (uint)local_8[uVar2]) {
            *(uint *)(param_1 + 0xe4) = uVar2;
            *(undefined4 *)(param_1 + 0xe0) = local_8[uVar2];
          }
        }
        else {
          do {
            if (uVar2 == *(uint *)(param_5 + uVar5 * 4)) break;
            uVar5 = uVar5 + 1;
          } while (uVar5 < param_6);
          if (param_6 <= uVar5) goto LAB_0061654f;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(param_1 + 0x70));
    }
    if (*(uint *)(param_1 + 0xe0) <= param_2) {
      *(undefined4 *)(param_1 + 0xe0) = 0xffffffff;
      *(int *)(param_1 + 0xe4) = *(int *)(param_1 + 0x70);
    }
  }
  param_6 = 0;
  iVar4 = (-(uint)(param_4 != 1) & 0xfffffffd) + 3;
  if (param_4 != 0) {
    piVar6 = (int *)(param_1 + 0xd0 + iVar4 * 4);
    do {
      if (*piVar6 != -1) {
        *(uint *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar6 * 4) + 0x34) = param_2;
      }
      iVar3 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),*(undefined4 *)(param_1 + 0xe4),iVar4,0);
      *piVar6 = iVar3;
      if (iVar3 == -1) goto LAB_00616638;
      iVar3 = *(int *)(*(int *)(param_1 + 0x14) + iVar3 * 4);
      *(undefined4 *)(iVar3 + 0x20) = 0;
      *(undefined4 *)(iVar3 + 0x1c) = 0;
      *(uint *)(iVar3 + 0x2c) = param_2;
      *(undefined4 *)(iVar3 + 0x34) = *(undefined4 *)(param_1 + 0xe0);
      *(uint *)(iVar3 + 0x38) = param_2;
      *(uint *)(iVar3 + 0x3c) = param_2;
      *(undefined4 *)(iVar3 + 0x40) = 1;
      if (param_3 != 0) {
        *(int *)(param_3 + param_6 * 4) = *piVar6;
      }
      iVar4 = iVar4 + 1;
      piVar6 = piVar6 + 1;
      param_6 = param_6 + 1;
    } while (param_6 < param_4);
  }
  uVar7 = 0;
LAB_00616626:
  _free(local_8);
  return uVar7;
}


// ==== 0x61663f FUN_0061663f

undefined4 __fastcall FUN_0061663f(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  piVar1 = *(int **)(param_1 + 0x108);
  uVar5 = 0;
  if (piVar1 != (int *)0x0) {
    uVar2 = *(uint *)(param_1 + 0xb0);
    if ((uVar2 < *(uint *)(param_1 + 0xa4)) && (*(int *)(param_1 + 0x38) == 0)) {
      uVar4 = 0;
      if ((*(int *)(param_1 + 0x98) != 0) &&
         ((iVar3 = *(int *)(*(int *)(param_1 + 0x98) + 0x34), iVar3 != 0 &&
          (*(int *)(iVar3 + 4) == 0xc)))) {
        uVar4 = *(undefined4 *)(iVar3 + 0x40);
        uVar5 = *(undefined4 *)(iVar3 + 0x44);
      }
      uVar5 = (**(code **)(*piVar1 + 0x10))
                        (piVar1,uVar4,uVar5,*(int *)(param_1 + 0xa0) + uVar2 * 4,
                         *(uint *)(param_1 + 0xa4) - uVar2);
      *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0xa4);
      return uVar5;
    }
  }
  return 0;
}


// ==== 0x6166af FUN_006166af

undefined4
FUN_006166af(undefined4 param_1,int param_2,short param_3,int param_4,undefined4 param_5,int param_6
            )

{
  int iVar1;
  undefined1 local_24 [16];
  undefined4 local_14;
  int local_10;
  
  if (param_2 == -1) {
    if (((*(int *)(param_6 + 0x98) != 0) &&
        (iVar1 = *(int *)(*(int *)(param_6 + 0x98) + 0x34), iVar1 != 0)) &&
       (*(int *)(iVar1 + 4) == 0xc)) {
      param_1 = *(undefined4 *)(iVar1 + 0x40);
      param_2 = *(int *)(iVar1 + 0x44);
      if (param_2 != -1) goto LAB_006166e8;
    }
    param_2 = 0;
  }
LAB_006166e8:
  local_14 = param_1;
  if ((param_3 == 2) || (param_3 == 6)) {
    local_10 = param_2;
    FUN_005b1f01(*(undefined4 *)(param_6 + 0x2c),local_24,param_4 + 5000,&DAT_006cc568,param_5);
    *(undefined4 *)(param_6 + 0x38) = 1;
  }
  return 0;
}


// ==== 0x616730 FUN_00616730

void * __thiscall FUN_00616730(void *param_1,byte param_2)

{
  FUN_00613825();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x61674c FUN_0061674c

int __fastcall FUN_0061674c(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0xcc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xd0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xd4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xd8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xdc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xe0) = 0;
  *(undefined4 *)(param_1 + 0xe4) = 0;
  iVar1 = FUN_005fb8ae();
  if (-1 < iVar1) {
    iVar1 = FUN_00614972();
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ==== 0x61678a FUN_0061678a

int __fastcall FUN_0061678a(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  char *pcVar6;
  int *piVar7;
  char *pcVar8;
  uint *puVar9;
  bool bVar10;
  undefined4 local_58 [4];
  int local_48 [4];
  char local_38 [16];
  uint local_28;
  int local_24;
  int local_20;
  char *local_1c;
  int local_18;
  int local_14;
  uint *local_10;
  uint local_c;
  uint local_8;
  
  iVar1 = FUN_0061674c();
  if (-1 < iVar1) {
    local_8 = 0;
    uVar4 = param_1[3];
    local_28 = uVar4;
    if (uVar4 != 0) {
      do {
        puVar9 = *(uint **)(param_1[6] + local_8 * 4);
        local_10 = puVar9;
        iVar1 = FUN_005f7a96();
        if (iVar1 == 0) {
          local_14 = 0;
          uVar4 = *puVar9 & 0xffffff;
          local_c = uVar4;
          iVar1 = (**(code **)(*param_1 + 0x24))(puVar9,&local_20);
          if (iVar1 != 0) {
            local_18 = ((-(uint)(uVar4 != 1) & 0xfffffffd) + 3) * 4;
            do {
              if ((uint)param_1[0x38] <= local_8) {
                local_48[0] = -1;
                local_48[1] = 0xffffffff;
                local_48[2] = 0xffffffff;
                local_48[3] = 0xffffffff;
                local_38[0] = -1;
                local_38[1] = -1;
                local_38[2] = -1;
                local_38[3] = -1;
                local_38[4] = -1;
                local_38[5] = -1;
                local_38[6] = -1;
                local_38[7] = -1;
                local_38[8] = -1;
                local_38[9] = -1;
                local_38[10] = -1;
                local_38[0xb] = -1;
                local_38[0xc] = -1;
                local_38[0xd] = -1;
                local_38[0xe] = -1;
                local_38[0xf] = -1;
                puVar9 = local_10;
              }
              local_1c = (char *)(puVar9[2] + local_20 * uVar4 * 4);
              iVar1 = uVar4 << 2;
              bVar10 = true;
              pcVar6 = local_1c;
              pcVar8 = local_38 + local_18;
              do {
                if (iVar1 == 0) break;
                iVar1 = iVar1 + -1;
                bVar10 = *pcVar6 == *pcVar8;
                pcVar6 = pcVar6 + 1;
                pcVar8 = pcVar8 + 1;
              } while (bVar10);
              if (!bVar10) {
                iVar1 = FUN_005f752b(local_c & 0xffffff | 0x10000000,0xffffffff,0xffffffff);
                if (iVar1 == -1) {
                  return -0x7ff8fff2;
                }
                iVar1 = *(int *)(param_1[6] + iVar1 * 4);
                local_24 = iVar1;
                iVar2 = FUN_005f7a42(local_10);
                if (iVar2 < 0) {
                  return iVar2;
                }
                piVar5 = (int *)((int)local_48 + local_18);
                iVar2 = (**(code **)(*param_1 + 0x6c))(local_8,piVar5,local_c,local_58,local_14);
                if (iVar2 < 0) {
                  return iVar2;
                }
                local_58[local_14] = *(undefined4 *)(*(int *)(param_1[5] + *piVar5 * 4) + 8);
                piVar7 = *(int **)(iVar1 + 0x10);
                for (uVar4 = local_c & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
                  *piVar7 = *piVar5;
                  piVar5 = piVar5 + 1;
                  piVar7 = piVar7 + 1;
                }
                for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
                  *(char *)piVar7 = (char)*piVar5;
                  piVar5 = (int *)((int)piVar5 + 1);
                  piVar7 = (int *)((int)piVar7 + 1);
                }
                pcVar6 = local_1c;
                pcVar8 = *(char **)(local_24 + 8);
                for (uVar4 = local_c & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
                  *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
                  pcVar6 = pcVar6 + 4;
                  pcVar8 = pcVar8 + 4;
                }
                local_14 = local_14 + 1;
                for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
                  *pcVar8 = *pcVar6;
                  pcVar6 = pcVar6 + 1;
                  pcVar8 = pcVar8 + 1;
                }
                pcVar6 = local_1c;
                pcVar8 = local_38 + local_18;
                for (uVar4 = local_c & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
                  *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
                  pcVar6 = pcVar6 + 4;
                  pcVar8 = pcVar8 + 4;
                }
                for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
                  *pcVar8 = *pcVar6;
                  pcVar6 = pcVar6 + 1;
                  pcVar8 = pcVar8 + 1;
                }
              }
              pcVar6 = (char *)((int)local_48 + local_18);
              pcVar8 = local_1c;
              for (uVar4 = local_c & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
                *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
                pcVar6 = pcVar6 + 4;
                pcVar8 = pcVar8 + 4;
              }
              for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
                *pcVar8 = *pcVar6;
                pcVar6 = pcVar6 + 1;
                pcVar8 = pcVar8 + 1;
              }
              iVar1 = (**(code **)(*param_1 + 0x24))(local_10,&local_20);
              uVar4 = local_c;
              puVar9 = local_10;
            } while (iVar1 != 0);
          }
          iVar1 = FUN_005f75cb(puVar9);
          if (iVar1 == -1) {
            return -0x7ff8fff2;
          }
          FUN_005f7186(1);
          *(undefined4 *)(param_1[6] + local_8 * 4) = 0;
          uVar4 = local_28;
        }
        local_8 = local_8 + 1;
      } while (local_8 < uVar4);
    }
    if (uVar4 < (uint)param_1[3]) {
      iVar1 = 0;
      uVar3 = uVar4;
      do {
        *(undefined4 *)(iVar1 + param_1[6]) = *(undefined4 *)(param_1[6] + uVar3 * 4);
        uVar3 = uVar3 + 1;
        iVar1 = iVar1 + 4;
      } while (uVar3 < (uint)param_1[3]);
    }
    param_1[3] = param_1[3] - uVar4;
    iVar1 = 0;
  }
  return iVar1;
}


// ==== 0x6169a4 FUN_006169a4

int __fastcall FUN_006169a4(int param_1)

{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 local_140 [16];
  int local_100 [4];
  int local_f0 [4];
  int local_e0 [4];
  int local_d0 [4];
  int local_c0 [4];
  int local_b0 [4];
  int local_a0 [4];
  int local_90 [4];
  int local_80 [8];
  int local_60 [5];
  uint local_4c;
  int local_48;
  uint local_44;
  uint *local_40;
  uint *local_3c;
  uint local_38;
  int local_34;
  int *local_30;
  uint local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  uint local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  puVar6 = *(uint **)(param_1 + 0x98);
  local_1c = *(int **)(param_1 + 0x94);
  uVar7 = *puVar6 & 0xffffff;
  local_c = 0;
  local_48 = 0;
  local_44 = 0;
  local_60[0] = 0;
  uVar8 = *puVar6 & 0xff000000;
  local_60[4] = param_1;
  local_14 = uVar7;
  local_60[1] = 1;
  local_60[2] = 2;
  local_60[3] = 3;
  if (uVar8 == 0x21000000) {
    local_40 = puVar6;
    local_3c = (uint *)FUN_0061556b(uVar7 | 0x20000000,puVar6,&local_4c,2,1);
    if (local_3c != (uint *)0x0) {
      local_34 = 0;
      goto LAB_00616a71;
    }
    goto LAB_00617201;
  }
  if (uVar8 == 0x20000000) {
    local_3c = puVar6;
    local_40 = (uint *)FUN_0061556b(uVar7 | 0x21000000,puVar6,&local_4c,2,1);
    if (local_40 == (uint *)0x0) {
      return 1;
    }
    local_34 = 1;
  }
  else {
    local_48 = 1;
  }
LAB_00616a71:
  local_38 = 0;
  local_2c = 0;
  if (local_48 == 0) {
    local_24 = (int *)local_3c[2];
    iVar4 = *(int *)(param_1 + 0x14);
    piVar2 = local_24 + uVar7;
    iVar5 = *(int *)(*(int *)(param_1 + 0x10) + **(int **)(iVar4 + *local_24 * 4) * 4);
    uVar7 = *(uint *)(*(int *)(*(int *)(param_1 + 0x10) + **(int **)(iVar4 + *piVar2 * 4) * 4) + 4)
            & 0x80;
    if (uVar7 == 0) {
      if ((*(byte *)(iVar5 + 4) & 0x80) == 0) goto LAB_00617201;
      local_10 = piVar2;
    }
    else {
      local_10 = local_24;
      local_24 = piVar2;
    }
    piVar2 = (int *)local_40[2];
    local_18 = piVar2 + local_14;
    if (uVar7 == 0) {
      if ((*(byte *)(iVar5 + 4) & 0x80) == 0) goto LAB_00617201;
      local_28 = piVar2;
    }
    else {
      local_28 = local_18;
      local_18 = piVar2;
    }
    iVar5 = *(int *)(param_1 + 0x60);
    piVar2 = *(int **)(iVar4 + *local_18 * 4);
    if (local_34 == 0) {
      if (*piVar2 != iVar5) {
        local_2c = 1;
      }
      local_2c = (uint)(*piVar2 != iVar5);
      if (**(int **)(iVar4 + *local_10 * 4) == iVar5) goto LAB_00616b40;
    }
    else if (*piVar2 == iVar5) {
      piVar2 = *(int **)(iVar4 + *local_10 * 4);
      if (*piVar2 != iVar5) {
        local_2c = 1;
      }
LAB_00616b40:
      local_38 = piVar2[8];
      if ((piVar2[8] & 0xffff03ffU) == 0) {
        local_8 = 0;
        if (local_14 != 0) {
          local_20 = (int *)((int)local_18 - (int)local_24);
          local_30 = (int *)((int)local_10 - (int)local_24);
          local_28 = (int *)((int)local_28 - (int)local_24);
          piVar2 = local_24;
          do {
            uVar7 = local_c;
            iVar5 = *(int *)(iVar4 + *(int *)((int)local_30 + (int)piVar2) * 4);
            local_24 = *(int **)(iVar4 + *piVar2 * 4);
            if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *local_24 * 4) + 4) & 0x80) == 0) ||
               (local_4c < *(uint *)(iVar5 + 0x3c))) goto LAB_00617201;
            uVar8 = 0;
            if (local_34 == 0) {
              if (*(int **)(iVar5 + 0x2c) != local_1c) goto LAB_00617201;
            }
            else {
              if ((*(uint *)(param_1 + 0x94) < *(uint *)(iVar5 + 0x3c)) ||
                 (*(uint *)(iVar5 + 0x20) != local_38)) goto LAB_00617201;
              if (local_c != 0) {
                do {
                  if (*(int *)(iVar5 + 0x2c) == local_60[uVar8]) break;
                  uVar8 = uVar8 + 1;
                } while (uVar8 < local_c);
              }
              if ((uVar8 == local_c) && (local_2c == 0)) {
                local_c = local_c + 1;
                local_60[uVar7] = *(int *)(iVar5 + 0x2c);
              }
            }
            uVar7 = local_c;
            if (*(double *)(local_24 + 4) != 1.0) goto LAB_00617201;
            iVar5 = *(int *)(iVar4 + *(int *)((int)local_20 + (int)piVar2) * 4);
            local_24 = *(int **)(iVar4 + *(int *)((int)local_28 + (int)piVar2) * 4);
            if (((*(uint *)(iVar5 + 0x20) & 0xffff03ff) != 0) ||
               ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *local_24 * 4) + 4) & 0x80) == 0))
            goto LAB_00617201;
            if (local_34 == 0) {
              if ((*(uint *)(param_1 + 0x94) < *(uint *)(iVar5 + 0x3c)) ||
                 (*(uint *)(iVar5 + 0x20) != local_38)) goto LAB_00617201;
              uVar8 = 0;
              if (local_c != 0) {
                do {
                  if (*(int *)(iVar5 + 0x2c) == local_60[uVar8]) break;
                  uVar8 = uVar8 + 1;
                } while (uVar8 < local_c);
              }
              if ((uVar8 == local_c) && (local_2c == 0)) {
                local_c = local_c + 1;
                local_60[uVar7] = *(int *)(iVar5 + 0x2c);
              }
            }
            else if ((*(int **)(iVar5 + 0x2c) != local_1c) || (local_4c < *(uint *)(iVar5 + 0x3c)))
            goto LAB_00617201;
            if (*(double *)(local_24 + 4) != 0.0) goto LAB_00617201;
            local_8 = local_8 + 1;
            piVar2 = piVar2 + 1;
          } while (local_8 < local_14);
        }
        local_20 = local_10;
        if (local_34 != 0) goto LAB_00616ceb;
        local_20 = local_18;
        goto LAB_00617132;
      }
    }
LAB_00617201:
    iVar4 = 1;
  }
  else {
    uVar7 = **(uint **)(param_1 + 0x98) & 0xffffff;
    local_1c = (int *)0x1;
    local_14 = uVar7;
    iVar4 = FUN_006139d8(*(uint **)(param_1 + 0x98),&DAT_006a6398,local_140,&local_44,local_100,
                         local_60,uVar7);
    if (iVar4 == 1) {
      iVar4 = FUN_006139d8(*(undefined4 *)(param_1 + 0x98),&DAT_006a64f8,local_140,&local_44,
                           local_100,local_60,uVar7);
      local_1c = (int *)0x0;
    }
    if (iVar4 == 0) {
      local_8 = 0;
      if (uVar7 != 0) {
        iVar4 = *(int *)(param_1 + 0x14);
        do {
          piVar2 = *(int **)(iVar4 + local_100[local_8] * 4);
          iVar5 = local_e0[local_8];
          local_28 = *(int **)(iVar4 + local_f0[local_8] * 4);
          if (iVar5 != local_b0[local_8]) goto LAB_00617201;
          local_30 = (int *)local_d0[local_8];
          if (((local_30 != (int *)local_a0[local_8]) || (local_c0[local_8] != local_90[local_8]))
             || ((int *)iVar5 != local_30)) goto LAB_00617201;
          local_18 = *(int **)(iVar4 + local_c0[local_8] * 4);
          iVar1 = *(int *)(param_1 + 0x10);
          if ((((((*(byte *)(*(int *)(iVar1 + *piVar2 * 4) + 4) & 0x80) == 0) ||
                ((*(byte *)(*(int *)(iVar1 + *local_28 * 4) + 4) & 0x80) == 0)) ||
               ((*(byte *)(*(int *)(iVar1 + *local_18 * 4) + 4) & 0x80) == 0)) ||
              ((*(double *)(piVar2 + 4) != 1.0 ||
               (local_30 = (int *)((uint)(local_1c == (int *)0x0) * 2 + -1),
               (double)(int)local_30 != *(double *)(local_28 + 4))))) ||
             (*(double *)(local_18 + 4) != 0.0)) goto LAB_00617201;
          piVar2 = *(int **)(iVar4 + iVar5 * 4);
          if (*piVar2 != *(int *)(param_1 + 0x60)) {
            local_2c = 1;
          }
          uVar7 = 0;
          if (local_c != 0) {
            do {
              if (piVar2[0xb] == local_60[uVar7]) break;
              uVar7 = uVar7 + 1;
            } while (uVar7 < local_c);
          }
          if ((uVar7 == local_c) && (local_2c == 0)) {
            local_60[local_c] = piVar2[0xb];
            local_c = local_c + 1;
          }
          local_8 = local_8 + 1;
        } while (local_8 < local_14);
      }
      local_20 = local_e0;
LAB_00616ceb:
    }
    else {
      if (iVar4 != 1) {
        return iVar4;
      }
      iVar4 = FUN_006139d8(*(undefined4 *)(param_1 + 0x98),&DAT_006a6438,local_140,&local_44,
                           local_100,local_60,uVar7);
      if (iVar4 != 0) {
        return iVar4;
      }
      local_4c = 0;
      if (uVar7 != 0) {
        do {
          local_24 = (int *)0x0;
          local_8 = local_f0[local_4c];
          if (local_8 != local_d0[local_4c]) goto LAB_00617201;
          local_18 = (int *)local_e0[local_4c];
          if (local_18 != (int *)local_c0[local_4c]) goto LAB_00617201;
          local_30 = (int *)local_b0[local_4c];
          if ((local_30 != (int *)local_90[local_4c]) ||
             (piVar2 = (int *)local_a0[local_4c], piVar2 != (int *)local_80[local_4c]))
          goto LAB_00617201;
          iVar4 = *(int *)(param_1 + 0x14);
          piVar10 = *(int **)(iVar4 + (int)piVar2 * 4);
          piVar9 = *(int **)(iVar4 + (int)local_30 * 4);
          local_28 = *(int **)(*(int *)(param_1 + 0x10) + *piVar9 * 4);
          local_10 = (int *)0x0;
          local_1c = *(int **)(*(int *)(param_1 + 0x10) + *piVar10 * 4);
          if (((local_30 == local_18) &&
              (((*(byte *)(local_1c + 1) & 0x80) != 0 && (*(double *)(piVar10 + 4) == -1.0)))) ||
             ((piVar2 == local_18 &&
              (((*(byte *)(local_28 + 1) & 0x80) != 0 && (*(double *)(piVar9 + 4) == -1.0)))))) {
            local_10 = (int *)0x1;
          }
          local_20 = local_e0;
          if (local_10 == (int *)0x0) {
            iVar5 = piVar9[9];
            if ((((iVar5 == local_8) ||
                 ((iVar5 != -1 && (*(int *)(*(int *)(iVar4 + local_8 * 4) + 0x24) == iVar5)))) &&
                (piVar9[8] == (*(uint *)(*(int *)(iVar4 + local_8 * 4) + 0x20) ^ 0x80000))) &&
               (((*(byte *)(local_1c + 1) & 0x80) != 0 && (*(double *)(piVar10 + 4) == 1.0)))) {
              local_10 = (int *)0x1;
            }
            iVar5 = piVar10[9];
            if (((iVar5 == local_8) ||
                ((iVar5 != -1 && (*(int *)(*(int *)(iVar4 + local_8 * 4) + 0x24) == iVar5)))) &&
               ((piVar10[8] == (*(uint *)(*(int *)(iVar4 + local_8 * 4) + 0x20) ^ 0x80000) &&
                (((*(byte *)(local_28 + 1) & 0x80) != 0 && (*(double *)(piVar9 + 4) == 1.0)))))) {
              local_10 = (int *)0x1;
            }
            local_24 = (int *)0x1;
            if (local_10 == (int *)0x0) {
              return 1;
            }
            local_20 = local_f0;
          }
          local_30 = *(int **)(iVar4 + local_100[local_4c] * 4);
          if (local_24 == (int *)0x0) {
            piVar2 = *(int **)(iVar4 + local_8 * 4);
          }
          else {
            piVar2 = *(int **)(iVar4 + (int)local_18 * 4);
          }
          if (((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *local_30 * 4) + 4) & 0x80) == 0) ||
               (*(double *)(local_30 + 4) != 0.0)) ||
              ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4) + 4) & 0x80) == 0)) ||
             (*(double *)(piVar2 + 4) != 1.0)) goto LAB_00617201;
          piVar2 = *(int **)(iVar4 + local_20[local_4c] * 4);
          if (*piVar2 != *(int *)(param_1 + 0x60)) {
            local_2c = 1;
          }
          uVar7 = 0;
          if (local_c != 0) {
            do {
              if (piVar2[0xb] == local_60[uVar7]) break;
              uVar7 = uVar7 + 1;
            } while (uVar7 < local_c);
          }
          if ((uVar7 == local_c) && (local_2c == 0)) {
            local_60[local_c] = piVar2[0xb];
            local_c = local_c + 1;
          }
          local_4c = local_4c + 1;
        } while (local_4c < local_14);
      }
    }
LAB_00617132:
    local_38 = local_38 | 0x200;
    local_8 = 0;
    if (local_c != 0) {
      do {
        if (local_60[local_8] == -1) goto LAB_006171e4;
        puVar6 = *(uint **)(*(int *)(param_1 + 0x18) + local_60[local_8] * 4);
        uVar7 = *puVar6 & 0xff000000;
        if ((((uVar7 == 0x40000000) || (uVar7 == 0x44000000)) || (uVar7 == 0x48000000)) ||
           (uVar7 == 0x4c000000)) {
          local_2c = 1;
          break;
        }
        local_28 = (int *)puVar6[3];
        uVar7 = 0;
        local_24 = (int *)0x0;
        if (local_14 != 0) {
          do {
            if (local_28 != (int *)0x0) {
              piVar2 = (int *)puVar6[4];
              local_1c = local_28;
              do {
                if (*piVar2 == local_20[uVar7]) {
                  local_24 = (int *)((int)local_24 + 1);
                }
                piVar2 = piVar2 + 1;
                local_1c = (int *)((int)local_1c + -1);
              } while (local_1c != (int *)0x0);
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < local_14);
        }
        if (local_24 != local_28) goto LAB_006171e4;
        local_8 = local_8 + 1;
      } while (local_8 < local_c);
    }
    if (local_2c == 0) {
      local_1c = (int *)0x0;
      if (local_c != 0) {
        do {
          iVar4 = *(int *)(*(int *)(param_1 + 0x18) + local_60[(int)local_1c] * 4);
          if (local_48 == 0) {
            puVar6 = local_3c;
            if (local_34 != 0) {
              puVar6 = local_40;
            }
          }
          else {
            puVar6 = *(uint **)(param_1 + 0x98);
          }
          local_18 = (int *)puVar6[3];
          local_8 = 0;
          if (local_18 != (int *)0x0) {
            do {
              local_10 = (int *)0x0;
              if (*(int *)(iVar4 + 0xc) != 0) {
                do {
                  piVar2 = (int *)(*(int *)(iVar4 + 0x10) + (int)local_10 * 4);
                  if (*piVar2 == local_20[local_8]) {
                    if (local_48 == 0) {
                      puVar6 = local_3c;
                      if (local_34 != 0) {
                        puVar6 = local_40;
                      }
                    }
                    else {
                      puVar6 = *(uint **)(param_1 + 0x98);
                    }
                    *piVar2 = *(int *)(local_8 * 4 + puVar6[4]);
                    puVar6 = (uint *)(*(int *)(*(int *)(param_1 + 0x14) +
                                              *(int *)(*(int *)(iVar4 + 0x10) + (int)local_10 * 4) *
                                              4) + 0x20);
                    *puVar6 = *puVar6 | local_38;
                  }
                  local_10 = (int *)((int)local_10 + 1);
                } while (local_10 < *(uint *)(iVar4 + 0xc));
              }
              local_8 = local_8 + 1;
            } while (local_8 < local_18);
          }
          local_1c = (int *)((int)local_1c + 1);
        } while (local_1c < local_c);
      }
      if (local_48 == 0) {
        *local_3c = 0;
        *local_40 = 0;
      }
      else {
        uVar7 = 0;
        if (local_44 != 0) {
          do {
            puVar11 = local_140 + uVar7;
            uVar7 = uVar7 + 1;
            *(undefined4 *)*puVar11 = 0;
          } while (uVar7 < local_44);
        }
      }
    }
    else {
LAB_006171e4:
      pvVar3 = _malloc(0x38);
      if (pvVar3 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_005f7709();
      }
      if (iVar4 == 0) goto LAB_00617201;
      iVar5 = FUN_005f7760(local_14 & 0xffffff | 0x10000000,local_14,local_14,0);
      if ((iVar5 < 0) || (iVar5 = FUN_005f7a42(*(undefined4 *)(param_1 + 0x98)), iVar5 < 0)) {
        FUN_005f7186(1);
        return iVar5;
      }
      piVar2 = *(int **)(iVar4 + 8);
      uVar7 = local_14 & 0x3fffffff;
      piVar10 = local_20;
      if (local_48 == 0) {
        piVar10 = local_18;
        piVar9 = local_10;
        if (local_34 == 0) {
          for (; uVar7 != 0; uVar7 = uVar7 - 1) {
            *piVar2 = *piVar10;
            piVar10 = piVar10 + 1;
            piVar2 = piVar2 + 1;
          }
          for (iVar5 = 0; puVar6 = local_3c, iVar5 != 0; iVar5 = iVar5 + -1) {
            *(char *)piVar2 = (char)*piVar10;
            piVar10 = (int *)((int)piVar10 + 1);
            piVar2 = (int *)((int)piVar2 + 1);
          }
        }
        else {
          for (; uVar7 != 0; uVar7 = uVar7 - 1) {
            *piVar2 = *piVar9;
            piVar9 = piVar9 + 1;
            piVar2 = piVar2 + 1;
          }
          for (iVar5 = 0; puVar6 = local_40, iVar5 != 0; iVar5 = iVar5 + -1) {
            *(char *)piVar2 = (char)*piVar9;
            piVar9 = (int *)((int)piVar9 + 1);
            piVar2 = (int *)((int)piVar2 + 1);
          }
        }
      }
      else {
        for (; uVar7 != 0; uVar7 = uVar7 - 1) {
          *piVar2 = *piVar10;
          piVar10 = piVar10 + 1;
          piVar2 = piVar2 + 1;
        }
        for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
          *(char *)piVar2 = (char)*piVar10;
          piVar10 = (int *)((int)piVar10 + 1);
          piVar2 = (int *)((int)piVar2 + 1);
        }
        puVar6 = *(uint **)(local_60[4] + 0x98);
      }
      puVar11 = (undefined4 *)puVar6[4];
      puVar12 = *(undefined4 **)(iVar4 + 0x10);
      for (uVar7 = local_14 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar12 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar12 = puVar12 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined1 *)puVar12 = *(undefined1 *)puVar11;
        puVar11 = (undefined4 *)((int)puVar11 + 1);
        puVar12 = (undefined4 *)((int)puVar12 + 1);
      }
      uVar7 = 0;
      if (local_14 != 0) {
        do {
          puVar6 = (uint *)(*(int *)(*(int *)(local_60[4] + 0x14) +
                                    *(int *)(*(int *)(iVar4 + 0x10) + uVar7 * 4) * 4) + 0x20);
          *puVar6 = *puVar6 | local_38;
          uVar7 = uVar7 + 1;
        } while (uVar7 < local_14);
      }
      if (local_48 == 0) {
        puVar6 = local_3c;
        if (local_34 != 0) {
          puVar6 = local_40;
        }
        *puVar6 = 0;
      }
      else {
        uVar7 = 0;
        if (local_44 != 0) {
          do {
            puVar11 = local_140 + uVar7;
            uVar7 = uVar7 + 1;
            *(undefined4 *)*puVar11 = 0;
          } while (uVar7 < local_44);
        }
      }
      if (*(int *)(*(int *)(local_60[4] + 0x18) + *(int *)(local_60[4] + 0x94) * 4) != 0) {
        FUN_005f7186(1);
      }
      *(int *)(*(int *)(local_60[4] + 0x18) + *(int *)(local_60[4] + 0x94) * 4) = iVar4;
    }
    iVar4 = 0;
  }
  return iVar4;
}


// ==== 0x61742a FUN_0061742a

undefined4 __thiscall
FUN_0061742a(int *param_1,uint param_2,uint param_3,int *param_4,uint param_5,uint param_6)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  int aiStack_80 [4];
  int aiStack_70 [4];
  uint auStack_60 [4];
  int local_50 [4];
  int local_40 [4];
  int local_30 [4];
  int *local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  int *local_10;
  uint *local_c;
  uint local_8;
  
  if (param_6 == 0) {
    param_6 = param_1[0x26];
  }
  iVar5 = param_6;
  puVar1 = *(uint **)(param_6 + 0x10);
  iVar6 = param_1[5];
  if (param_1[0x18] != **(int **)(iVar6 + *puVar1 * 4)) {
    return 1;
  }
  local_1c = *(uint *)param_1[0x26];
  uVar8 = ((uint *)param_1[0x26])[3];
  local_8 = 0;
  if ((local_1c & 0xffffff) != uVar8) {
    return 1;
  }
  local_10 = (int *)0x0;
  if (uVar8 != 0) {
    local_18 = (int)param_4 - (int)puVar1;
    local_c = puVar1;
    do {
      piVar7 = *(int **)(iVar6 + *(int *)(((int)param_4 - (int)puVar1) + (int)local_c) * 4);
      local_14 = *(int *)(param_1[4] + *piVar7 * 4);
      if (((param_1[0x24] << 0xf < 0) && ((*(byte *)((int)piVar7 + 0x21) & 2) != 0)) &&
         (param_2 == 0x80000)) {
        local_8 = 1;
      }
      if (((piVar7[8] & 0xf0000U) != 0) && ((~param_3 & piVar7[8] & 0xf0000) != 0)) {
        if (param_2 != 0x80000) {
          return 1;
        }
        local_8 = 1;
      }
      iVar6 = param_1[5];
      if ((*(byte *)(*(int *)(iVar6 + *local_c * 4) + 0x21) & 0xfe) != 0) {
        if (param_2 != 0x80000) {
          return 1;
        }
        local_8 = 1;
      }
      if (((param_1[0x24] & 0x10U) != 0) && ((*(byte *)(local_14 + 5) & 1) != 0)) {
        if ((local_1c & 0xff000000) != 0x11000000) {
          return 1;
        }
        local_8 = 1;
      }
      local_10 = (int *)((int)local_10 + 1);
      local_c = local_c + 1;
    } while (local_10 < *(int **)(param_1[0x26] + 0xc));
  }
  param_2 = 0;
  if (*(int *)(param_6 + 0xc) != 0) {
    local_1c = (int)param_4 - (int)local_30;
    do {
      bVar12 = local_8 == 0;
      puVar2 = *(undefined4 **)(param_1[5] + *(int *)(param_2 * 4 + *(int *)(param_6 + 0x10)) * 4);
      puVar3 = *(undefined4 **)(param_1[5] + *(int *)((int)(local_30 + param_2) + local_1c) * 4);
      local_30[param_2] = puVar2[1];
      iVar6 = puVar2[0xb];
      local_40[param_2] = puVar2[2];
      local_50[param_2] = puVar2[3];
      uVar8 = puVar2[8];
      aiStack_70[param_2] = iVar6;
      iVar6 = puVar2[0x13];
      auStack_60[param_2] = uVar8;
      aiStack_80[param_2] = iVar6;
      if (bVar12) {
        *puVar2 = *puVar3;
        puVar2[1] = puVar3[1];
        puVar2[2] = puVar3[2];
        puVar2[3] = puVar3[3];
        puVar2[0xb] = puVar3[0xb];
        puVar2[0x13] = puVar3[0x13];
        uVar8 = puVar3[8] ^ param_5 | puVar3[8] & ~param_5 | uVar8;
      }
      else {
        uVar8 = uVar8 ^ param_5 | ~param_5 & uVar8;
      }
      param_2 = param_2 + 1;
      puVar2[8] = uVar8;
    } while (param_2 < *(uint *)(param_6 + 0xc));
  }
  uVar8 = 0;
  if (*(int *)(param_6 + 0xc) != 0) {
    do {
      iVar6 = FUN_00615137(*(undefined4 *)(*(int *)(param_6 + 0x10) + uVar8 * 4));
      if (iVar6 == 1) goto LAB_00617810;
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(param_6 + 0xc));
  }
  puVar2 = (undefined4 *)(param_6 + 0xc);
  param_3 = 0xffffffff;
  param_6 = 0;
  param_2 = 0xffffffff;
  if ((uint *)*puVar2 != (uint *)0x0) {
    local_18 = (int)local_30 - (int)param_4;
    local_14 = (int)local_40 - (int)param_4;
    local_1c = *(int *)(iVar5 + 0x10) - (int)param_4;
    local_20 = (int *)((int)local_50 - (int)param_4);
    piVar7 = param_4;
    local_c = (uint *)*puVar2;
    do {
      local_10 = *(int **)(param_1[5] + *(int *)(local_1c + (int)piVar7) * 4);
      piVar9 = *(int **)(param_1[5] + *piVar7 * 4);
      if ((uint)local_10[0xe] < param_3) {
        param_3 = local_10[0xe];
      }
      if (param_6 < (uint)local_10[0xf]) {
        param_6 = local_10[0xf];
      }
      if ((((param_1[0x18] == *piVar9) &&
           (*(int *)(((int)local_30 - (int)param_4) + (int)piVar7) == piVar9[1])) &&
          (*(int *)(((int)local_40 - (int)param_4) + (int)piVar7) == piVar9[2])) &&
         (*(int *)(((int)local_50 - (int)param_4) + (int)piVar7) == piVar9[3])) {
        piVar9 = local_10;
      }
      if ((uint)piVar9[0xd] < param_2) {
        param_2 = piVar9[0xd];
      }
      piVar7 = piVar7 + 1;
      local_c = (uint *)((int)local_c + -1);
    } while (local_c != (uint *)0x0);
    if ((param_2 < param_6) && ((*(byte *)((int)param_1 + 0x93) & 4) == 0)) goto LAB_00617810;
  }
  if (local_8 != 0) {
    *(undefined1 *)(param_1[0x26] + 3) = 0x10;
    return 0;
  }
  while (local_18 = param_3, param_3 <= param_6) {
    local_c = *(uint **)(param_1[6] + param_3 * 4);
    if (*local_c != 0) {
      uVar8 = local_c[2];
      local_14 = 0;
      local_8 = uVar8 + local_c[1] * 4;
      uVar10 = *local_c & 0xffffff;
      if (uVar8 < local_8) {
        do {
          param_3 = 0;
          param_2 = 0;
          if (uVar10 != 0) {
            do {
              local_10 = (int *)0x0;
              if (*(int *)(iVar5 + 0xc) != 0) {
                piVar7 = *(int **)(iVar5 + 0x10);
                do {
                  if (*piVar7 == *(int *)(uVar8 + param_2 * 4)) {
                    param_3 = param_3 + 1;
                    break;
                  }
                  local_10 = (int *)((int)local_10 + 1);
                  piVar7 = piVar7 + 1;
                  local_20 = piVar7;
                } while (local_10 < *(int **)(iVar5 + 0xc));
              }
              param_2 = param_2 + 1;
            } while (param_2 < uVar10);
            if (param_3 != 0) {
              if (((param_3 != uVar10) || (uVar11 = *local_c & 0xff000000, uVar11 == 0xf7000000)) ||
                 ((uVar11 == 0xf8000000 || (uVar11 == 0xf9000000)))) goto LAB_00617810;
              local_14 = 1;
            }
          }
          uVar8 = uVar8 + uVar10 * 4;
        } while (uVar8 < local_8);
        if ((local_14 != 0) && (iVar6 = (**(code **)(*param_1 + 0x24))(local_c,0), iVar6 != 0))
        goto LAB_00617810;
      }
    }
    param_3 = local_18 + 1;
  }
  if (param_1[0x3c] == 0) {
    param_2 = 0;
    if (*(int *)(iVar5 + 0xc) != 0) {
      do {
        iVar6 = *(int *)(param_1[5] + *(int *)(param_2 * 4 + *(int *)(iVar5 + 0x10)) * 4);
        iVar4 = *(int *)(param_1[5] + param_4[param_2] * 4);
        if (*(int *)(iVar4 + 0x24) == -1) {
          *(int *)(iVar6 + 0x24) = param_4[param_2];
        }
        else {
          *(int *)(iVar6 + 0x24) = *(int *)(iVar4 + 0x24);
        }
        uVar8 = *(uint *)(iVar4 + 0x18);
        *(uint *)(iVar6 + 0x18) = uVar8;
        if ((param_5 == 0x80000) && ((uVar8 & 4) != 0)) {
          *(uint *)(iVar6 + 0x18) = uVar8 * -5 | 8;
        }
        FUN_005f7cfc(iVar4);
        param_2 = param_2 + 1;
      } while (param_2 < *(uint *)(iVar5 + 0xc));
    }
    *(undefined4 *)param_1[0x26] = 0;
    return 0;
  }
  param_1[0x3c] = 2;
LAB_00617810:
  uVar8 = 0;
  if (*(int *)(iVar5 + 0xc) != 0) {
    do {
      piVar9 = *(int **)(param_1[5] + *(int *)(uVar8 * 4 + *(int *)(iVar5 + 0x10)) * 4);
      *piVar9 = param_1[0x18];
      piVar9[1] = local_30[uVar8];
      piVar9[2] = local_40[uVar8];
      piVar9[3] = local_50[uVar8];
      piVar9[8] = auStack_60[uVar8];
      piVar7 = aiStack_70 + uVar8;
      iVar6 = aiStack_80[uVar8];
      uVar8 = uVar8 + 1;
      piVar9[0xb] = *piVar7;
      piVar9[0x13] = iVar6;
    } while (uVar8 < *(uint *)(iVar5 + 0xc));
  }
  return 1;
}


// ==== 0x6178e1 FUN_006178e1

void __fastcall FUN_006178e1(int param_1)

{
  *(undefined4 *)(param_1 + 0xf0) = 0;
  FUN_0061742a(0x80000,0xe0000,*(undefined4 *)(*(int *)(param_1 + 0x98) + 8),0x80000,0);
  return;
}


// ==== 0x617905 FUN_00617905

uint __fastcall FUN_00617905(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  void *pvVar6;
  uint uVar7;
  int *piVar8;
  int local_108 [4];
  int aiStack_f8 [4];
  int local_e8 [32];
  undefined1 local_68 [64];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  int *local_c;
  uint local_8;
  
  uVar7 = **(uint **)(param_1 + 0x98) & 0xffffff;
  piVar8 = (int *)0x0;
  local_14 = 0;
  local_28 = 0;
  local_24 = 1;
  local_20 = 2;
  local_1c = 3;
  local_8 = 0;
  iVar4 = FUN_006139d8(*(uint **)(param_1 + 0x98),&DAT_006a6158,local_68,&local_14,local_108,
                       &local_28,uVar7);
  if (iVar4 != 0) {
    iVar4 = FUN_006139d8(*(undefined4 *)(param_1 + 0x98),&DAT_006a61b8,local_68,&local_14,local_108,
                         &local_28,uVar7);
    local_8 = 1;
    if (iVar4 != 0) {
      local_8 = 0;
      iVar4 = FUN_006139d8(*(undefined4 *)(param_1 + 0x98),&DAT_006a6218,local_68,&local_14,
                           local_108,&local_28,uVar7);
      if (iVar4 != 0) {
        iVar4 = FUN_006139d8(*(undefined4 *)(param_1 + 0x98),&DAT_006a6278,local_68,&local_14,
                             local_108,&local_28,uVar7);
        local_8 = 1;
        if (iVar4 != 0) {
          local_8 = 0;
          goto LAB_00617c47;
        }
      }
      uVar5 = 0;
      if (uVar7 != 0) {
        do {
          if (local_108[uVar5] != aiStack_f8[uVar5]) {
            return 1;
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar7);
      }
      if (*(int *)(param_1 + 0xf4) == -1) {
        iVar4 = FUN_005f7478(&DAT_0069ecd8,0x189,1,4);
        *(int *)(param_1 + 0x104) = iVar4;
        if (iVar4 == -1) {
          return -0x7ff8fff2;
        }
        iVar4 = FUN_005f74cf(iVar4,0,0,0x4000000000000000);
        *(int *)(param_1 + 0xf4) = iVar4;
        if (iVar4 == -1) {
          return -0x7ff8fff2;
        }
      }
      uVar5 = 0;
      local_10 = 1;
      if (uVar7 != 0) {
        iVar4 = *(int *)(param_1 + 0xf4);
        do {
          local_108[uVar5] = iVar4;
          if (local_e8[uVar5] != local_e8[0]) {
            local_10 = 0;
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar7);
      }
      piVar8 = *(int **)(*(int *)(param_1 + 0x14) + local_e8[0] * 4);
      if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar8 * 4) + 4) & 0x80) != 0) &&
         (uVar5 = 0, local_10 != 0)) {
        local_c = (int *)(param_1 + 0xf8);
        do {
          if ((*local_c == -1) ||
             (*(double *)(*(int *)(*(int *)(param_1 + 0x14) + *local_c * 4) + 0x10) ==
              *(double *)(piVar8 + 4))) break;
          local_c = local_c + 1;
          uVar5 = uVar5 + 1;
        } while (uVar5 < 3);
        if (uVar5 != 3) {
          piVar1 = (int *)(param_1 + 0xf8 + uVar5 * 4);
          if (*piVar1 == -1) {
            iVar4 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x104),0,uVar5 + 1,
                                 *(undefined8 *)(piVar8 + 4));
            *piVar1 = iVar4;
            if (iVar4 == -1) {
              return -0x7ff8fff2;
            }
          }
          if (uVar7 != 0) {
            iVar4 = *piVar1;
            piVar8 = local_e8;
            for (uVar5 = uVar7; uVar5 != 0; uVar5 = uVar5 - 1) {
              *piVar8 = iVar4;
              piVar8 = piVar8 + 1;
            }
          }
        }
      }
    }
  }
  pvVar6 = _malloc(0x38);
  if (pvVar6 == (void *)0x0) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8 = (int *)FUN_005f7709();
  }
  if (piVar8 == (int *)0x0) {
    return -0x7ff8fff2;
  }
  if (local_8 == 0) {
    uVar5 = uVar7 | 0xf5000000;
  }
  else {
    uVar5 = uVar7 | 0xf6000000;
  }
  local_c = piVar8;
  local_8 = FUN_005f7760(uVar5,uVar7 * 3,uVar7,0);
  if ((-1 < (int)local_8) && (local_8 = FUN_005f7a42(), -1 < (int)local_8)) {
    local_8 = 0;
    if (uVar7 != 0) {
      local_10 = uVar7 << 3;
      local_18 = uVar7 << 2;
      do {
        uVar5 = local_8;
        iVar3 = local_10;
        iVar2 = local_18;
        iVar4 = local_8 * 4;
        local_8 = local_8 + 1;
        *(undefined4 *)(iVar4 + piVar8[4]) =
             *(undefined4 *)(iVar4 + *(int *)(*(int *)(param_1 + 0x98) + 0x10));
        *(int *)(iVar4 + piVar8[2]) = local_108[uVar5];
        iVar4 = local_e8[uVar5];
        local_18 = local_18 + 4;
        *(int *)(iVar2 + local_c[2]) = aiStack_f8[uVar5];
        local_10 = local_10 + 4;
        *(int *)(iVar3 + local_c[2]) = iVar4;
        piVar8 = local_c;
      } while (local_8 < uVar7);
    }
    iVar4 = FUN_006149ee(piVar8,local_68,local_14);
    return iVar4;
  }
LAB_00617c47:
  if (piVar8 != (int *)0x0) {
    FUN_005f7186();
  }
  return local_8;
}


// ==== 0x617c5c FUN_00617c5c

/* WARNING: Type propagation algorithm not settling */

int __fastcall FUN_00617c5c(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iStack_28;
  int local_24 [7];
  int *local_8;
  
  local_24[6] = **(uint **)(param_1 + 0x98);
  if ((local_24[6] & 0xff000000U) != 0x24000000) {
    return 1;
  }
  local_24[6] = local_24[6] & 0xffffff;
  piVar7 = (int *)(*(uint **)(param_1 + 0x98))[2];
  iVar3 = *(int *)(param_1 + 0x10);
  local_8 = piVar7 + local_24[6];
  iVar5 = *(int *)(param_1 + 0x14);
  if ((*(byte *)(*(int *)(iVar3 + **(int **)(iVar5 + *local_8 * 4) * 4) + 4) & 0x80) == 0) {
    if ((*(byte *)(*(int *)(iVar3 + **(int **)(iVar5 + *piVar7 * 4) * 4) + 4) & 0x80) == 0) {
      return 1;
    }
    local_24[5] = 1;
    piVar2 = piVar7;
  }
  else {
    local_24[5] = 0;
    piVar2 = local_8;
    local_8 = piVar7;
  }
  *(undefined4 *)(param_1 + 0xf0) = 0;
  local_24[4] = 0;
  if (local_24[6] != 0) {
    uVar6 = 0;
    local_24[3] = (int)piVar2 - (int)local_8;
    piVar7 = local_8;
    do {
      if (*(double *)(*(int *)(iVar5 + *(int *)(local_24[3] + (int)piVar7) * 4) + 0x10) != -0.5) {
        return 1;
      }
      iVar4 = *(int *)(iVar5 + *piVar7 * 4);
      if ((((*(byte *)(iVar4 + 0x21) & 2) == 0) && ((*(byte *)(iVar4 + 0x18) & 4) == 0)) &&
         ((*(byte *)(param_1 + 0x92) & 2) != 0)) {
        *(undefined4 *)(param_1 + 0xf0) = 1;
      }
      uVar6 = uVar6 + 1;
      piVar7 = piVar7 + 1;
    } while (uVar6 < (uint)local_24[6]);
  }
  iVar4 = **(int **)(iVar5 + **(int **)(*(int *)(param_1 + 0x98) + 0x10) * 4);
  if (iVar4 == *(int *)(param_1 + 0x60)) {
    iVar3 = FUN_0061742a(0x20000,0,local_8,0x20000,0);
    if (*(int *)(param_1 + 0xf0) == 2) {
      FUN_005fbf37(param_1,*(undefined4 *)(*(int *)(param_1 + 0x98) + 0x34),0x125d,
                   "_bias opportunity missed because source was not clamped 0 to 1");
      return iVar3;
    }
    return iVar3;
  }
  if (iVar4 == *(int *)(param_1 + 0x5c)) {
    iVar4 = FUN_006157c4(local_24[6] | 0x24000000,*(int *)(param_1 + 0x98),local_24,2);
    if (iVar4 != 0) {
      return iVar4;
    }
    local_24[5] = local_24[local_24[5]];
    if (local_24[5] != 0) {
      local_8 = (int *)0x0;
      if (local_24[6] != 0) {
        piVar7 = *(int **)(local_24[5] + 8);
        do {
          piVar2 = *(int **)(iVar5 + *piVar7 * 4);
          if ((((*(byte *)((int)piVar2 + 0x22) & 0xf) != 0) ||
              ((*(byte *)(*(int *)(iVar3 + *piVar2 * 4) + 5) & 1) != 0)) ||
             (((*(byte *)((int)piVar2 + 0x21) & 2) == 0 && ((*(byte *)(piVar2 + 6) & 4) == 0))))
          break;
          local_24[3] = 0;
          local_8 = (int *)((int)local_8 + 1);
          piVar7 = piVar7 + 1;
        } while (local_8 < (uint)local_24[6]);
      }
      uVar6 = local_24[3];
      if (local_8 != (int *)local_24[6]) {
        local_8 = (int *)0x0;
        if (local_24[6] != 0) {
          piVar7 = (int *)(*(int *)(local_24[5] + 8) + local_24[6] * 4);
          do {
            piVar2 = *(int **)(iVar5 + *piVar7 * 4);
            if ((((*(byte *)((int)piVar2 + 0x22) & 0xf) != 0) ||
                ((*(byte *)(*(int *)(iVar3 + *piVar2 * 4) + 5) & 1) != 0)) ||
               (((*(byte *)((int)piVar2 + 0x21) & 2) == 0 && ((*(byte *)(piVar2 + 6) & 4) == 0))))
            break;
            local_8 = (int *)((int)local_8 + 1);
            piVar7 = piVar7 + 1;
          } while (local_8 < (uint)local_24[6]);
        }
        uVar6 = local_24[6];
        if (local_8 == (int *)local_24[6]) {
          return 1;
        }
      }
      local_8 = (int *)0x0;
      if (local_24[6] != 0) {
        iVar3 = uVar6 << 2;
        do {
          puVar1 = *(undefined4 **)
                    (*(int *)(param_1 + 0x14) + *(int *)(iVar3 + *(int *)(local_24[5] + 8)) * 4);
          iVar5 = FUN_005f74cf(*puVar1,puVar1[2],puVar1[3],*(undefined8 *)(puVar1 + 4));
          (&iStack_28)[(int)local_8] = iVar5;
          if (iVar5 == -1) {
            return -0x7ff8fff2;
          }
          iVar4 = *(int *)(*(int *)(param_1 + 0x14) + iVar5 * 4);
          *(undefined4 *)(iVar4 + 0x24) = *(undefined4 *)(iVar3 + *(int *)(local_24[5] + 8));
          *(undefined4 *)(iVar4 + 0x2c) = puVar1[0xb];
          *(undefined4 *)(iVar4 + 0x34) = puVar1[0xd];
          *(undefined4 *)(iVar4 + 0x38) = puVar1[0xe];
          *(undefined4 *)(iVar4 + 0x3c) = puVar1[0xe];
          *(uint *)(iVar4 + 0x20) = puVar1[8] | 0x20000;
          *(int *)(iVar3 + *(int *)(local_24[5] + 8)) = iVar5;
          *(undefined4 *)(*(int *)(local_24[5] + 0x10) + (int)local_8 * 4) =
               *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x98) + 0x10) + (int)local_8 * 4);
          local_8 = (int *)((int)local_8 + 1);
          iVar3 = iVar3 + 4;
        } while (local_8 < (uint)local_24[6]);
      }
      **(undefined4 **)(param_1 + 0x98) = 0;
      return 0;
    }
  }
  return 1;
}


// ==== 0x617f3a FUN_00617f3a

undefined4 __fastcall FUN_00617f3a(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  uint local_c;
  
  *(undefined4 *)(param_1 + 0xf0) = 0;
  puVar1 = *(uint **)(param_1 + 0x98);
  uVar3 = *puVar1;
  if ((uVar3 & 0xff000000) == 0x25000000) {
    uVar3 = uVar3 & 0xffffff;
    piVar6 = (int *)puVar1[2];
    piVar7 = piVar6 + uVar3;
    iVar2 = *(int *)(param_1 + 0x14);
    piVar4 = piVar7;
    if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + **(int **)(iVar2 + *piVar6 * 4) * 4) + 4) &
         0x80) == 0) &&
       (piVar4 = piVar6, piVar6 = piVar7,
       (*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + **(int **)(iVar2 + *piVar7 * 4) * 4) + 4) &
       0x80) == 0)) {
      return 1;
    }
    if (uVar3 != 0) {
      uVar8 = 0;
      piVar7 = piVar6;
      do {
        if (*(double *)
             (*(int *)(iVar2 + *(int *)(((int)piVar4 - (int)piVar6) + (int)piVar7) * 4) + 0x10) !=
            2.0) {
          return 1;
        }
        if (((*(uint *)(*(int *)(iVar2 + *piVar7 * 4) + 0x20) & 0xf0000) != 0x20000) &&
           ((*(uint *)(param_1 + 0x90) & 0x40000) != 0)) {
          return 1;
        }
        uVar8 = uVar8 + 1;
        piVar7 = piVar7 + 1;
      } while (uVar8 < uVar3);
    }
  }
  else {
    if ((uVar3 & 0xff000000) != 0x24000000) {
      return 1;
    }
    piVar6 = (int *)puVar1[2];
    uVar3 = uVar3 & 0xffffff;
    local_c = 0;
    piVar7 = piVar6;
    if (uVar3 != 0) {
      do {
        if (*piVar7 != piVar7[uVar3]) {
          return 1;
        }
        if (((*(uint *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar7 * 4) + 0x20) & 0xf0000) !=
             0x20000) && ((*(uint *)(param_1 + 0x90) & 0x40000) != 0)) {
          return 1;
        }
        local_c = local_c + 1;
        piVar7 = piVar7 + 1;
      } while (local_c < uVar3);
    }
  }
  uVar5 = FUN_0061742a(0x40000,0x20000,piVar6,0x40000,0);
  return uVar5;
}


// ==== 0x61808b FUN_0061808b

undefined4 __thiscall FUN_0061808b(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  undefined4 uVar8;
  bool bVar9;
  undefined4 uVar10;
  int *local_14;
  uint local_10;
  
  uVar8 = 1;
  bVar9 = param_2 == (uint *)0x0;
  if (bVar9) {
    param_2 = *(uint **)(param_1 + 0x98);
  }
  if ((*param_2 & 0xff000000) == 0x24000000) {
    uVar5 = *param_2 & 0xffffff;
    local_14 = (int *)param_2[2];
    piVar7 = local_14 + uVar5;
    iVar2 = *(int *)(param_1 + 0x14);
    piVar6 = piVar7;
    if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + **(int **)(iVar2 + *piVar7 * 4) * 4) + 4) &
         0x80) == 0) &&
       (iVar1 = *local_14, piVar6 = local_14, local_14 = piVar7,
       (*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + **(int **)(iVar2 + iVar1 * 4) * 4) + 4) & 0x80
       ) == 0)) {
LAB_00618203:
      uVar8 = 1;
    }
    else {
      puVar3 = *(uint **)(param_1 + 0x98);
      piVar7 = local_14;
      if (puVar3 != param_2) {
        piVar7 = (int *)puVar3[2];
      }
      *(undefined4 *)(param_1 + 0xf0) = 0;
      local_10 = 0;
      if (uVar5 != 0) {
        iVar1 = (int)piVar6 - (int)piVar7;
        do {
          if ((*(double *)(*(int *)(iVar2 + *(int *)(iVar1 + (int)piVar7) * 4) + 0x10) != 1.0) ||
             ((bVar9 && ((*(uint *)(*(int *)(iVar2 + *piVar7 * 4) + 0x20) & 0xf0000) != 0x80000))))
          goto LAB_00618203;
          iVar4 = *(int *)(iVar2 + *piVar7 * 4);
          if (((*(byte *)(iVar4 + 0x21) & 2) == 0) &&
             ((*(uint *)(iVar4 + 0x18) & (uint)bVar9 * 4 + 0x14) == 0)) {
            *(undefined4 *)(param_1 + 0xf0) = 1;
          }
          local_10 = local_10 + 1;
          piVar7 = piVar7 + 1;
        } while (local_10 < uVar5);
      }
      if (bVar9) {
        param_2 = (uint *)0x0;
        uVar10 = 0x90000;
        uVar8 = 0x80000;
      }
      else {
        uVar10 = 0x10000;
        local_14 = (int *)puVar3[2];
        uVar8 = 0;
      }
      uVar8 = FUN_0061742a(0x10000,uVar8,local_14,uVar10,param_2);
      if (*(int *)(param_1 + 0xf0) == 2) {
        FUN_005fbf37(param_1,*(undefined4 *)(*(int *)(param_1 + 0x98) + 0x34),0x125e,
                     "complement opportunity missed because input result was not clamped from 0 to 1"
                    );
      }
    }
  }
  return uVar8;
}


// ==== 0x61820d FUN_0061820d

int __fastcall FUN_0061820d(int param_1)

{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar1 = *(uint **)(param_1 + 0x98);
  uVar2 = *puVar1;
  if (((uVar2 & 0xff000000) == 0x25000000) &&
     ((piVar3 = *(int **)(*(int *)(param_1 + 0x14) +
                         *(int *)(puVar1[2] + (uVar2 & 0xffffff) * 4) * 4),
      (*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar3 * 4) + 4) & 0x80) == 0 ||
      (*(double *)(piVar3 + 4) != -1.0)))) {
    return 1;
  }
  puVar4 = (undefined4 *)FUN_0061556b(uVar2 & 0xffffff | 0x24000000,puVar1,0,2,1);
  if (puVar4 == (undefined4 *)0x0) {
    iVar5 = 1;
  }
  else {
    iVar5 = FUN_0061808b(puVar4);
    if (iVar5 == 0) {
      *puVar4 = 0;
    }
  }
  return iVar5;
}


// ==== 0x6182a2 FUN_006182a2

int __fastcall FUN_006182a2(int param_1)

{
  int iVar1;
  float fVar2;
  bool bVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  uint *local_14;
  int *local_10;
  uint local_c;
  
  *(undefined4 *)(param_1 + 0xf0) = 0;
  puVar4 = *(uint **)(param_1 + 0x98);
  if ((*puVar4 & 0xff000000) != 0x24000000) {
    return 1;
  }
  uVar6 = *puVar4 & 0xffffff;
  bVar3 = true;
  if (uVar6 != 0) {
    piVar8 = (int *)puVar4[2];
    piVar9 = piVar8 + uVar6;
    local_c = uVar6;
    do {
      if (*piVar8 != *piVar9) {
        bVar3 = false;
      }
      piVar9 = piVar9 + 1;
      piVar8 = piVar8 + 1;
      local_c = local_c - 1;
    } while (local_c != 0);
    if (!bVar3) {
      fVar2 = -0.5;
      goto LAB_00618331;
    }
  }
  puVar4 = (uint *)FUN_0061556b(uVar6 | 0x24000000,puVar4,0,2,1);
  fVar2 = -1.0;
  local_14 = puVar4;
  if (puVar4 == (uint *)0x0) {
    return 1;
  }
LAB_00618331:
  local_10 = (int *)puVar4[2];
  iVar5 = *(int *)(param_1 + 0x14);
  uVar6 = *puVar4 & 0xffffff;
  piVar9 = local_10 + uVar6;
  piVar8 = piVar9;
  if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + **(int **)(iVar5 + *piVar9 * 4) * 4) + 4) &
       0x80) == 0) &&
     (iVar1 = *local_10, piVar8 = local_10, local_10 = piVar9,
     (*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + **(int **)(iVar5 + iVar1 * 4) * 4) + 4) & 0x80)
     == 0)) {
    return 1;
  }
  uVar7 = 0;
  if (uVar6 != 0) {
    do {
      if (fVar2 != (float)*(double *)(*(int *)(iVar5 + piVar8[uVar7] * 4) + 0x10)) {
        return 1;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar6);
  }
  if (bVar3) {
    local_10 = *(int **)(*(int *)(param_1 + 0x98) + 8);
  }
  else {
    local_14 = (uint *)FUN_0061556b(**(uint **)(param_1 + 0x98) & 0xffffff | 0x24000000,
                                    *(uint **)(param_1 + 0x98),0,2,2);
    if (local_14 == (uint *)0x0) {
      return 1;
    }
    bVar3 = true;
    if (uVar6 != 0) {
      piVar8 = (int *)local_14[2];
      piVar9 = piVar8 + uVar6;
      do {
        if (*piVar8 != *piVar9) {
          bVar3 = false;
        }
        piVar9 = piVar9 + 1;
        piVar8 = piVar8 + 1;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
      if (!bVar3) {
        return 1;
      }
    }
  }
  iVar5 = FUN_0061742a(0x60000,0,local_10,0x60000,local_14);
  if (iVar5 == 0) {
    *local_14 = 0;
    return 0;
  }
  return iVar5;
}


// ==== 0x618431 FUN_00618431

int __fastcall FUN_00618431(int param_1)

{
  uint *puVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int local_18;
  undefined4 *local_14;
  uint local_10;
  undefined4 *local_c;
  undefined4 local_8;
  
  local_14 = (undefined4 *)0x0;
  puVar1 = *(uint **)(param_1 + 0x98);
  uVar6 = *puVar1 & 0xffffff;
  local_8 = CONCAT13(0x12,(int3)*puVar1);
  local_10 = uVar6;
  local_c = (undefined4 *)FUN_0061556b(local_8,puVar1,&local_18,2,1);
  if ((local_c != (undefined4 *)0x0) ||
     ((local_14 = (undefined4 *)FUN_0061556b(local_10 | 0x11000000,puVar1,0,2,1),
      local_14 != (undefined4 *)0x0 &&
      (local_c = (undefined4 *)FUN_0061556b(local_8,local_14,&local_18,2,1),
      local_c != (undefined4 *)0x0)))) {
    pvVar2 = _malloc(0x38);
    if (pvVar2 == (void *)0x0) {
      local_8 = 0;
    }
    else {
      local_8 = FUN_005f7709();
    }
    iVar5 = local_8;
    if (local_8 == 0) {
      return -0x7ff8fff2;
    }
    if (local_14 == (undefined4 *)0x0) {
      uVar3 = local_10 | 0xf3000000;
    }
    else {
      uVar3 = local_10 | 0xf4000000;
    }
    iVar4 = FUN_005f7760(uVar3,uVar6,uVar6,0);
    if (iVar4 < 0) {
      return iVar4;
    }
    iVar4 = FUN_005f7a42(local_c);
    if (iVar4 < 0) {
      return iVar4;
    }
    puVar7 = (undefined4 *)local_c[4];
    puVar8 = *(undefined4 **)(iVar5 + 0x10);
    for (uVar3 = uVar6; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    puVar7 = (undefined4 *)puVar1[2];
    puVar8 = *(undefined4 **)(local_8 + 8);
    for (; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    *puVar1 = 0;
    *local_c = 0;
    if (local_14 != (undefined4 *)0x0) {
      *local_14 = 0;
    }
    if (*(int *)(local_18 * 4 + *(int *)(param_1 + 0x18)) != 0) {
      FUN_005f7186(1);
    }
    *(int *)(local_18 * 4 + *(int *)(param_1 + 0x18)) = local_8;
  }
  return 1;
}


// ==== 0x61858f FUN_0061858f

undefined4 __fastcall FUN_0061858f(int param_1)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  uint uVar10;
  undefined1 local_1c [8];
  int local_14;
  uint local_10;
  int local_c;
  undefined4 local_8;
  
  puVar2 = *(uint **)(param_1 + 0x98);
  uVar10 = *puVar2 & 0xffffff;
  if ((*puVar2 & 0xff000000) == 0xf5000000) {
    local_8 = *(undefined4 *)(param_1 + 0x94);
    local_c = param_1;
    FUN_006157c4(uVar10 | 0x25000000,puVar2,local_1c,2);
    if (local_14 != 0) {
      local_10 = 0;
      if (uVar10 != 0) {
        piVar9 = *(int **)(local_14 + 0x10);
        piVar5 = (int *)(puVar2[2] + uVar10 * 8);
        do {
          if (*piVar5 != *piVar9) {
            return 1;
          }
          local_10 = local_10 + 1;
          piVar5 = piVar5 + 1;
          piVar9 = piVar9 + 1;
        } while (local_10 < uVar10);
      }
      uVar3 = puVar2[2];
      iVar4 = *(int *)(local_14 + 8);
      iVar1 = uVar10 * 4 + uVar3;
      iVar6 = uVar10 * 4 + iVar4;
      iVar7 = FUN_00614e5c(uVar3,iVar1,iVar4,iVar6,local_14,puVar2,local_8);
      if ((((iVar7 != 0) &&
           (iVar7 = FUN_00614e5c(iVar1,uVar3,iVar4,iVar6,local_14,puVar2,local_8), iVar7 != 0)) &&
          (iVar7 = FUN_00614e5c(uVar3,iVar1,iVar6,iVar4,local_14,puVar2,local_8), iVar7 != 0)) &&
         (((iVar7 = FUN_00614e5c(iVar1,uVar3,iVar6,iVar4,local_14,puVar2,local_8), iVar7 != 0 &&
           (iVar7 = FUN_00614e5c(iVar4,iVar6,uVar3,iVar1,local_14,puVar2,local_8), iVar7 != 0)) &&
          ((iVar7 = FUN_00614e5c(iVar6,iVar4,uVar3,iVar1,local_14,puVar2,local_8), iVar7 != 0 &&
           (iVar7 = FUN_00614e5c(iVar4,iVar6,iVar1,uVar3,local_14,puVar2,local_8), iVar7 != 0))))))
      {
        uVar8 = FUN_00614e5c(iVar6,iVar4,iVar1,uVar3,local_14,puVar2,local_8);
        return uVar8;
      }
      return 0;
    }
  }
  return 1;
}


// ==== 0x618709 FUN_00618709

int __fastcall FUN_00618709(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  uint *puVar12;
  undefined4 *puVar13;
  int local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_28;
  uint *local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  uint *local_14;
  int *local_10;
  uint local_c;
  int *local_8;
  
  puVar12 = (uint *)param_1[0x26];
  uVar10 = *puVar12 & 0xffffff;
  local_38 = uVar10 | 0x25000000;
  local_1c = uVar10;
  local_14 = puVar12;
  local_10 = param_1;
  local_c = uVar10;
  local_24 = (uint *)FUN_0061556b(local_38,puVar12,0,2,1);
  if (local_24 != (uint *)0x0) {
    local_34 = local_c | 0x24000000;
    local_20 = FUN_0061556b(local_34,local_24,&local_3c,2,1);
    if ((local_20 != 0) &&
       (param_1[0x18] == **(int **)(param_1[5] + **(int **)(local_20 + 0x10) * 4))) {
      local_30 = 0;
      local_28 = 0;
      iVar3 = uVar10 << 2;
      iVar7 = uVar10 * -4;
      local_2c = iVar3;
      do {
        local_18 = 0;
        if (uVar10 != 0) {
          piVar8 = (int *)(*(int *)(local_20 + 8) + iVar3);
          piVar4 = (int *)(puVar12[2] + local_28);
          do {
            local_8 = *(int **)(param_1[5] + *piVar4 * 4);
            piVar1 = *(int **)(param_1[5] + *piVar8 * 4);
            if ((((*local_8 != *piVar1) || (local_8[1] != piVar1[1])) || (local_8[2] != piVar1[2]))
               || ((local_8[3] != piVar1[3] || ((piVar1[8] ^ local_8[8]) != 0x80000)))) break;
            local_18 = local_18 + 1;
            piVar4 = piVar4 + 1;
            piVar8 = piVar8 + 1;
          } while (local_18 < uVar10);
        }
        if (local_18 == uVar10) {
          pvVar5 = _malloc(0x38);
          if (pvVar5 == (void *)0x0) {
            iVar3 = 0;
          }
          else {
            iVar3 = FUN_005f7709();
          }
          if (iVar3 == 0) {
            return -0x7ff8fff2;
          }
          iVar6 = FUN_005f7760(local_c | 0xf1000000,uVar10 * 3,uVar10,0);
          iVar9 = local_20;
          if (iVar6 < 0) {
            return iVar6;
          }
          iVar6 = FUN_005f7a42(local_20);
          piVar4 = local_10;
          if (iVar6 < 0) {
            return iVar6;
          }
          puVar11 = *(undefined4 **)(iVar9 + 0x10);
          puVar13 = *(undefined4 **)(iVar3 + 0x10);
          for (uVar10 = uVar10 & 0x3fffffff; uVar10 != 0; uVar10 = uVar10 - 1) {
            *puVar13 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar13 = puVar13 + 1;
          }
          for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
            *(undefined1 *)puVar13 = *(undefined1 *)puVar11;
            puVar11 = (undefined4 *)((int)puVar11 + 1);
            puVar13 = (undefined4 *)((int)puVar13 + 1);
          }
          iVar9 = local_1c * 4;
          puVar11 = (undefined4 *)(local_24[2] + iVar9);
          puVar13 = *(undefined4 **)(iVar3 + 8);
          for (uVar10 = local_1c & 0x3fffffff; uVar10 != 0; uVar10 = uVar10 - 1) {
            *puVar13 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar13 = puVar13 + 1;
          }
          for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
            *(undefined1 *)puVar13 = *(undefined1 *)puVar11;
            puVar11 = (undefined4 *)((int)puVar11 + 1);
            puVar13 = (undefined4 *)((int)puVar13 + 1);
          }
          puVar11 = (undefined4 *)(local_14[2] + local_2c);
          puVar13 = (undefined4 *)(*(int *)(iVar3 + 8) + iVar9);
          for (uVar10 = local_1c & 0x3fffffff; uVar10 != 0; uVar10 = uVar10 - 1) {
            *puVar13 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar13 = puVar13 + 1;
          }
          for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
            *(undefined1 *)puVar13 = *(undefined1 *)puVar11;
            puVar11 = (undefined4 *)((int)puVar11 + 1);
            puVar13 = (undefined4 *)((int)puVar13 + 1);
          }
          puVar11 = (undefined4 *)(*(int *)(local_20 + 8) + iVar9);
          puVar13 = (undefined4 *)(*(int *)(iVar3 + 8) + local_1c * 8);
          for (uVar10 = local_1c & 0x3fffffff; uVar10 != 0; uVar10 = uVar10 - 1) {
            *puVar13 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar13 = puVar13 + 1;
          }
          local_18 = 0;
          for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
            *(undefined1 *)puVar13 = *(undefined1 *)puVar11;
            puVar11 = (undefined4 *)((int)puVar11 + 1);
            puVar13 = (undefined4 *)((int)puVar13 + 1);
          }
          iVar9 = local_10[5];
          piVar8 = *(int **)(iVar9 + **(int **)(iVar3 + 0x10) * 4);
          piVar1 = *(int **)(iVar9 + **(int **)(iVar3 + 8) * 4);
          piVar2 = *(int **)(iVar9 + (*(int **)(iVar3 + 8))[local_1c * 2] * 4);
          iVar9 = *piVar8;
          if (((((iVar9 == *piVar1) && (piVar8[2] == piVar1[2])) ||
               ((iVar9 == *piVar2 && (piVar8[2] == piVar2[2])))) || (iVar9 != local_10[0x18])) &&
             ((*(byte *)((int)local_10 + 0x93) & 1) == 0)) {
            local_18 = 1;
          }
          iVar9 = (**(code **)(*local_10 + 0x24))(iVar3,0);
          if ((iVar9 == 0) && (local_18 == 0)) {
            *local_14 = 0;
            *local_24 = 0;
            iVar9 = (**(code **)(*piVar4 + 0x34))(iVar3,local_3c);
            if (iVar9 == 0) {
              if ((((*(byte *)((int)piVar4 + 0x93) & 1) != 0) &&
                  ((*(byte *)((int)piVar1 + 0x21) & 2) == 0)) &&
                 (((piVar1[6] & 4U) == 0 || ((piVar1[6] & 0x10U) == 0)))) {
                FUN_005f7186(1);
                FUN_005fbf37(piVar4,*(undefined4 *)(local_20 + 0x34),0x125f,
                             "cannot match lerp because lerp factor is not _sat\'d");
                *local_14 = local_34;
                *local_24 = local_38;
                return 1;
              }
              if (*(int *)(local_3c * 4 + piVar4[6]) != 0) {
                FUN_005f7186(1);
              }
              *(int *)(local_3c * 4 + piVar4[6]) = iVar3;
              return 0;
            }
            *local_14 = local_34;
            *local_24 = local_38;
            param_1 = local_10;
            uVar10 = local_1c;
          }
          else {
            FUN_005f7186(1);
            param_1 = local_10;
            uVar10 = local_1c;
          }
        }
        local_30 = local_30 + 1;
        local_2c = local_2c + iVar7;
        iVar3 = uVar10 * 4;
        local_28 = local_28 + iVar3;
        puVar12 = local_14;
      } while (local_30 < 2);
    }
  }
  return 1;
}


// ==== 0x618a35 FUN_00618a35

int __fastcall FUN_00618a35(int *param_1)

{
  uint *puVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int local_1c;
  int local_18;
  uint *local_14;
  uint local_10;
  undefined4 *local_c;
  undefined4 local_8;
  
  local_14 = (uint *)0x0;
  puVar1 = (uint *)param_1[0x26];
  uVar7 = *puVar1 & 0xffffff;
  local_8 = CONCAT13(0x24,(int3)*puVar1);
  local_10 = uVar7;
  local_c = (undefined4 *)FUN_0061556b(local_8,puVar1,&local_1c,2,1);
  if (((local_c != (undefined4 *)0x0) ||
      ((local_14 = (uint *)FUN_0061556b(local_10 | 0x11000000,puVar1,0,2,1), local_14 != (uint *)0x0
       && (local_c = (undefined4 *)FUN_0061556b(local_8,local_14,&local_1c,2,1),
          local_c != (undefined4 *)0x0)))) &&
     (iVar4 = *(int *)(param_1[5] + **(int **)(param_1[0x26] + 0x10) * 4),
     (*(uint *)(iVar4 + 0x20) & 0xfff7ffff) == 0)) {
    pvVar2 = _malloc(0x38);
    if (pvVar2 == (void *)0x0) {
      local_18 = 0;
    }
    else {
      local_18 = FUN_005f7709();
    }
    iVar6 = local_18;
    if (local_18 == 0) {
      return -0x7ff8fff2;
    }
    if ((local_14 == (uint *)0x0) && ((*(byte *)(iVar4 + 0x22) & 8) == 0)) {
      uVar3 = local_10 | 0xf5000000;
    }
    else {
      uVar3 = local_10 | 0xf6000000;
    }
    iVar4 = FUN_005f7760(uVar3,uVar7 * 3,uVar7,0);
    puVar8 = local_c;
    if (iVar4 < 0) {
      return iVar4;
    }
    iVar5 = FUN_005f7a42(local_c);
    iVar4 = local_18;
    if (iVar5 < 0) {
      return iVar5;
    }
    puVar8 = (undefined4 *)puVar8[4];
    puVar9 = *(undefined4 **)(iVar6 + 0x10);
    for (uVar3 = uVar7; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar9 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    puVar8 = (undefined4 *)puVar1[2];
    puVar9 = *(undefined4 **)(local_18 + 8);
    for (iVar6 = uVar7 << 1; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar9 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    puVar8 = (undefined4 *)(local_c[2] + uVar7 * 4);
    puVar9 = (undefined4 *)(*(int *)(local_18 + 8) + uVar7 * 8);
    for (; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar9 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    iVar6 = (**(code **)(*param_1 + 0x24))(local_18,0);
    puVar8 = local_c;
    if (iVar6 == 0) {
      *puVar1 = 0;
      *local_c = 0;
      if (local_14 != (uint *)0x0) {
        *local_14 = 0;
      }
      iVar6 = (**(code **)(*param_1 + 0x34))(iVar4,local_1c);
      if (iVar6 == 0) {
        if (*(int *)(local_1c * 4 + param_1[6]) != 0) {
          FUN_005f7186(1);
        }
        *(int *)(local_1c * 4 + param_1[6]) = iVar4;
        return 0;
      }
      *puVar1 = local_10 | 0x25000000;
      *puVar8 = local_8;
      if (local_14 != (uint *)0x0) {
        *local_14 = local_10 | 0x11000000;
      }
    }
    FUN_005f7186(1);
  }
  return 1;
}


// ==== 0x618c39 FUN_00618c39

int __thiscall FUN_00618c39(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = FUN_00615e2f(1);
  if (-1 < iVar2) {
    piVar1 = (int *)(param_1 + 0xa4);
    *(undefined4 *)(*(int *)(param_1 + 0xa0) + *piVar1 * 4) = param_2;
    *piVar1 = *piVar1 + 1;
    iVar2 = 0;
  }
  return iVar2;
}


// ==== 0x618c64 FUN_00618c64

int __fastcall FUN_00618c64(int *param_1)

{
  byte bVar1;
  int *piVar2;
  float fVar3;
  int iVar4;
  uint *puVar5;
  int *piVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  size_t _Size;
  short *psVar13;
  undefined4 *puVar14;
  bool bVar15;
  undefined4 uVar16;
  undefined1 local_15c [254];
  undefined1 local_5e;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  uint *local_50;
  undefined4 local_4c;
  undefined1 local_48 [16];
  int *local_38;
  uint *local_34;
  undefined4 *local_30;
  undefined4 *local_2c;
  byte *local_28;
  void *local_24;
  undefined4 *local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint *local_c;
  uint local_8;
  
  FUN_0061314d((-(uint)(param_1[0x3b] != 0) & 0x40cf503) + 0x42415443);
  local_54 = param_1[0xc];
  local_58 = 0;
  local_50 = (uint *)0x0;
  local_4c = 0;
  local_5c = 0x14;
  local_30 = (undefined4 *)0x0;
  local_20 = (undefined4 *)0x0;
  local_2c = (undefined4 *)0x0;
  local_24 = (void *)0x0;
  iVar4 = FUN_0061319b(&local_5c,0x14,1,0);
  if (iVar4 < 0) goto LAB_006192d7;
  local_14 = 0;
  local_8 = 0;
  if (param_1[2] != 0) {
    local_c = (uint *)param_1[2];
    piVar6 = (int *)param_1[5];
    do {
      piVar2 = (int *)*piVar6;
      uVar10 = *(uint *)(*(int *)(param_1[4] + *piVar2 * 4) + 4);
      if (((uVar10 & 0x100) != 0) && (-1 < (char)uVar10)) {
        if (((uVar10 & 0x40) == 0) && (local_14 < piVar2[2] + 1U)) {
          local_14 = piVar2[2] + 1U;
        }
        if (((uVar10 & 0x40) != 0) && (local_8 < piVar2[2] + 1U)) {
          local_8 = piVar2[2] + 1U;
        }
      }
      piVar6 = piVar6 + 1;
      local_c = (uint *)((int)local_c + -1);
    } while (local_c != (uint *)0x0);
  }
  puVar5 = (uint *)(local_8 + local_14);
  local_c = puVar5;
  local_20 = _malloc((int)puVar5 * 4);
  if ((local_20 == (undefined4 *)0x0) ||
     (local_24 = _malloc((int)puVar5 * 4), local_24 == (void *)0x0)) {
LAB_006192b6:
    iVar4 = -0x7ff8fff2;
  }
  else {
    local_10 = 0;
    puVar14 = local_20;
    for (uVar10 = (uint)puVar5 & 0x3fffffff; uVar10 != 0; uVar10 = uVar10 - 1) {
      *puVar14 = 0;
      puVar14 = puVar14 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar14 = 0;
      puVar14 = (undefined4 *)((int)puVar14 + 1);
    }
    if (param_1[2] != 0) {
      do {
        piVar6 = *(int **)(param_1[5] + local_10 * 4);
        if ((((piVar6[0x11] != 0) && (piVar6[1] == -1)) &&
            (uVar10 = *(uint *)(*(int *)(param_1[4] + *piVar6 * 4) + 4), (uVar10 & 0x100) != 0)) &&
           (-1 < (char)uVar10)) {
          iVar4 = piVar6[2];
          if ((uVar10 & 0x40) != 0) {
            iVar4 = iVar4 + local_14;
          }
          uVar10 = piVar6[0x15];
          uVar11 = iVar4 + 1;
          while ((iVar4 - (uVar10 >> 2) < uVar11 && (uVar11 = uVar11 - 1, local_20[uVar11] == 0))) {
            local_20[uVar11] = piVar6;
          }
        }
        local_10 = local_10 + 1;
      } while (local_10 < (uint)param_1[2]);
    }
    puVar5 = (uint *)0x0;
    local_10 = 0;
    if (local_c != (uint *)0x0) {
      do {
        if (local_20[(int)puVar5] != 0) {
          local_20[local_10] = local_20[(int)puVar5];
          local_10 = local_10 + 1;
        }
        puVar5 = (uint *)((int)puVar5 + 1);
      } while (puVar5 < local_c);
    }
    piVar6 = (int *)0x0;
    local_1c = 0;
    local_8 = 0;
    if (local_10 != 0) {
      do {
        if ((((((piVar6 == (int *)0x0) || (piVar2 = (int *)local_20[local_8], *piVar2 != *piVar6))
              || ((piVar2[0x11] != piVar6[0x11] ||
                  (piVar2[2] - ((uint)piVar2[0x15] >> 2) != piVar6[2] - ((uint)piVar6[0x15] >> 2))))
              ) && ((((piVar6 = (int *)local_20[local_8], piVar6 != (int *)0x0 &&
                      (iVar4 = piVar6[0x11], *(int *)(iVar4 + 4) == 5)) &&
                     (iVar9 = *(int *)(iVar4 + 0x14), iVar9 != 0)) &&
                    ((*(int *)(iVar9 + 4) == 2 && (*(int *)(iVar4 + 0x18) != 0)))))) &&
            (*(int *)(*(int *)(iVar4 + 0x18) + 4) == 10)) &&
           ((*(int *)(iVar9 + 0x10) == 9 && (*(int *)(iVar9 + 0x18) != 0)))) {
          *(uint *)((int)local_24 + local_1c * 4) = local_8;
          local_1c = local_1c + 1;
        }
        local_8 = local_8 + 1;
      } while (local_8 < local_10);
    }
    local_18 = 0;
    if (local_1c != 0) {
      do {
        local_8 = *(uint *)((int)local_24 + local_18 * 4);
        local_34 = (uint *)local_20[local_8];
        local_28 = *(byte **)(*(int *)(local_34[0x11] + 0x14) + 0x18);
        uVar10 = 0;
        if (local_18 != 0) {
          do {
            local_c = (uint *)local_20[*(int *)((int)local_24 + uVar10 * 4)];
            pbVar7 = *(byte **)(*(int *)(local_c[0x11] + 0x14) + 0x18);
            pbVar12 = local_28;
            do {
              bVar1 = *pbVar12;
              bVar15 = bVar1 < *pbVar7;
              if (bVar1 != *pbVar7) {
LAB_00618ef7:
                iVar4 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
                goto LAB_00618efc;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar12[1];
              bVar15 = bVar1 < pbVar7[1];
              if (bVar1 != pbVar7[1]) goto LAB_00618ef7;
              pbVar12 = pbVar12 + 2;
              pbVar7 = pbVar7 + 2;
            } while (bVar1 != 0);
            iVar4 = 0;
LAB_00618efc:
          } while ((-1 < iVar4) &&
                  (((0 < iVar4 || (*local_c <= *local_34)) &&
                   (uVar10 = uVar10 + 1, uVar10 < local_18))));
          uVar11 = local_18;
          if (uVar10 < local_18) {
            do {
              *(undefined4 *)((int)local_24 + uVar11 * 4) =
                   *(undefined4 *)((int)local_24 + uVar11 * 4 + -4);
              uVar11 = uVar11 - 1;
            } while (uVar10 < uVar11);
            *(uint *)((int)local_24 + uVar10 * 4) = local_8;
          }
        }
        local_18 = local_18 + 1;
      } while (local_18 < local_1c);
    }
    iVar4 = (**(code **)(*param_1 + 0x78))();
    local_c = (uint *)(iVar4 + local_1c);
    if (local_c != (uint *)0x0) {
      uVar10 = (int)local_c * 5;
      _Size = (int)local_c * 0x14;
      local_30 = _malloc(_Size);
      if (local_30 == (undefined4 *)0x0) goto LAB_006192b6;
      puVar14 = local_30;
      for (uVar10 = uVar10 & 0x3fffffff; uVar10 != 0; uVar10 = uVar10 - 1) {
        *puVar14 = 0;
        puVar14 = puVar14 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar14 = 0;
        puVar14 = (undefined4 *)((int)puVar14 + 1);
      }
      iVar4 = FUN_0061319b(local_30,_Size,1,&local_4c);
      if (iVar4 < 0) goto LAB_006192d7;
      local_18 = 0;
      local_50 = local_c;
      if (local_1c != 0) {
        psVar13 = (short *)((int)local_30 + 6);
        do {
          local_28 = (byte *)((int)local_24 + local_18 * 4);
          local_14 = *(uint *)(*(int *)(local_20[*(int *)local_28] + 0x44) + 0x18);
          puVar8 = *(undefined1 **)
                    (*(int *)(*(int *)(local_20[*(int *)local_28] + 0x44) + 0x14) + 0x18);
          if (param_1[0x3b] == 0) {
            uVar16 = 7;
          }
          else {
            _snprintf(local_15c,0xff,&DAT_006a6934,puVar8);
            local_5e = 0;
            uVar16 = 6;
            puVar8 = local_15c;
          }
          iVar4 = FUN_0061319b(puVar8,0xffffffff,uVar16,psVar13 + -3);
          if (iVar4 < 0) goto LAB_006192d7;
          iVar4 = *(int *)local_28;
          local_c = (uint *)0x1;
          if (iVar4 + 1U < local_10) {
            local_38 = (int *)local_20[iVar4];
            local_34 = local_20 + iVar4 + 1;
            local_8 = iVar4 + 1U;
            do {
              piVar6 = (int *)*local_34;
              if (((*local_38 != *piVar6) || (local_38[0x11] != piVar6[0x11])) ||
                 (local_38[2] - ((uint)local_38[0x15] >> 2) != piVar6[2] - ((uint)piVar6[0x15] >> 2)
                 )) break;
              local_c = (uint *)((int)local_c + 1);
              local_8 = local_8 + 1;
              local_34 = local_34 + 1;
            } while (local_8 < local_10);
          }
          psVar13[-1] = (ushort)(*(uint *)(*(int *)(param_1[4] + *(int *)local_20[iVar4] * 4) + 4)
                                >> 6) & 1 | 2;
          *psVar13 = *(short *)(local_20[*(int *)local_28] + 8) -
                     (short)(*(uint *)(local_20[*(int *)local_28] + 0x54) >> 2);
          psVar13[1] = (short)local_c;
          if (((*(int *)(local_14 + 0x20) != 0) &&
              (iVar4 = FUN_00615b5d(local_48,*(int *)(local_14 + 0x20),1,psVar13 + 3), iVar4 < 0))
             || ((*(int *)(local_14 + 0x30) != 0 &&
                 (iVar4 = (**(code **)(*param_1 + 0x80))(local_14,psVar13 + -3), iVar4 < 0))))
          goto LAB_006192d7;
          if (*(int *)(local_14 + 0x34) != 0) {
            local_28 = (byte *)((*(int *)(local_14 + 0x34) + 3U & 0xfffffffc) << 2);
            local_2c = _malloc((size_t)local_28);
            if (local_2c == (undefined4 *)0x0) goto LAB_006192b6;
            local_8 = 0;
            puVar14 = local_2c;
            for (uVar10 = (uint)local_28 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
              *puVar14 = 0;
              puVar14 = puVar14 + 1;
            }
            for (uVar10 = (uint)local_28 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
              *(undefined1 *)puVar14 = 0;
              puVar14 = (undefined4 *)((int)puVar14 + 1);
            }
            if (*(int *)(local_14 + 0x34) != 0) {
              do {
                piVar6 = *(int **)(local_8 * 4 + *(int *)(local_14 + 0x38));
                if (piVar6 != (int *)0x0) {
                  iVar4 = *piVar6;
                  if (iVar4 == 0) {
                    if (piVar6[2] == 0) {
                      fVar3 = 0.0;
                    }
                    else {
                      fVar3 = 1.0;
                    }
                  }
                  else if (iVar4 == 1) {
                    fVar3 = (float)piVar6[2];
                  }
                  else if (iVar4 == 2) {
                    local_38 = (int *)piVar6[2];
                    fVar3 = (float)(int)local_38;
                    if ((int)local_38 < 0) {
                      fVar3 = fVar3 + 4.2949673e+09;
                    }
                  }
                  else {
                    if (iVar4 != 3) goto LAB_006191c1;
                    fVar3 = (float)*(double *)(piVar6 + 2);
                  }
                  local_2c[local_8] = fVar3;
                }
LAB_006191c1:
                local_8 = local_8 + 1;
              } while (local_8 < *(uint *)(local_14 + 0x34));
            }
            iVar4 = FUN_0061319b(local_2c,local_28,0xb,psVar13 + 5);
            if (iVar4 < 0) goto LAB_006192d7;
            local_2c = (undefined4 *)0x0;
          }
          local_18 = local_18 + 1;
          psVar13 = psVar13 + 10;
        } while (local_18 < local_1c);
      }
    }
    iVar4 = (**(code **)(*param_1 + 0x7c))(local_48,local_30,local_1c);
    if ((-1 < iVar4) &&
       (iVar9 = FUN_0061319b(PTR_s_D3DX9_Shader_Compiler_006df698,0xffffffff,5,&local_58),
       -1 < iVar9)) {
      uVar10 = FUN_006132d2();
      if (uVar10 < 0x8001) {
        iVar4 = FUN_00615e2f(uVar10);
        if (-1 < iVar4) {
          _memmove((void *)(param_1[0x28] + 4 + uVar10 * 4),(void *)(param_1[0x28] + 4),
                   param_1[0x29] * 4 - 4);
          iVar4 = FUN_006132de(param_1[0x28] + 4,uVar10);
          if (-1 < iVar4) {
            param_1[0x29] = param_1[0x29] + uVar10;
            param_1[0x2d] = param_1[0x2d] + uVar10;
            param_1[0x2c] = param_1[0x29];
            iVar4 = 0;
          }
        }
      }
      else {
        FUN_005fbec8(param_1,0,0x11c4,"constant table info exceeds maximum comment size");
        iVar4 = -0x7fffbffb;
      }
    }
  }
LAB_006192d7:
  _free(local_30);
  _free(local_20);
  _free(local_2c);
  _free(local_24);
  FUN_00613165();
  return iVar4;
}


// ==== 0x619309 FUN_00619309

int __fastcall FUN_00619309(int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined4 *puVar7;
  undefined4 local_70;
  undefined1 local_6c [4];
  undefined1 local_68 [4];
  uint local_64;
  undefined1 local_60 [4];
  uint local_5c;
  undefined1 local_58 [4];
  uint local_54;
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  undefined1 local_48 [16];
  int local_38;
  int local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  FUN_0061314d(0x47554244);
  iVar5 = 0;
  puVar7 = &local_70;
  for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  local_70 = 0x28;
  local_20 = (undefined4 *)0x0;
  local_18 = (undefined4 *)0x0;
  local_24 = (undefined4 *)0x0;
  local_1c = (undefined4 *)0x0;
  local_14 = (undefined4 *)0x0;
  local_c = 0;
  local_10 = FUN_0061319b(&local_70,0x28,1,0);
  if (local_10 < 0) goto LAB_00619919;
  local_5c = *(uint *)(param_1 + 0xbc);
  if (local_5c == 0) goto LAB_006197d2;
  local_20 = _malloc(local_5c << 2);
  uVar1 = local_5c;
  puVar7 = local_20;
  if (local_20 != (undefined4 *)0x0) {
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    local_18 = _malloc(local_5c << 3);
    if (local_18 != (undefined4 *)0x0) {
      local_34 = local_5c << 3;
      puVar7 = local_18;
      for (iVar3 = (local_5c & 0x1fffffff) << 1; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar7 = 0;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      local_14 = _malloc(local_5c << 4);
      if (local_14 != (undefined4 *)0x0) {
        puVar7 = local_14;
        for (iVar3 = (local_5c & 0xfffffff) << 2; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(undefined1 *)puVar7 = 0;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        local_8 = 0;
        if (local_5c != 0) {
          puVar6 = (undefined2 *)((int)local_18 + 2);
          do {
            *puVar6 = 0xffff;
            puVar6[-1] = 0;
            local_28 = iVar5 + 8;
            *(undefined4 *)(puVar6 + 1) = *(undefined4 *)(*(int *)(param_1 + 0xb8) + 4 + iVar5);
            local_2c = 4;
            do {
              iVar3 = *(int *)(local_28 + *(int *)(param_1 + 0xb8));
              if ((iVar3 != -1) &&
                 (iVar3 = *(int *)(*(int *)(param_1 + 0x14) + iVar3 * 4),
                 *(uint *)(iVar3 + 0x58) = local_8, *(int *)(iVar3 + 0x44) != 0)) {
                local_14[local_c] = *(undefined4 *)(local_28 + *(int *)(param_1 + 0xb8));
                local_c = local_c + 1;
              }
              local_28 = local_28 + 4;
              local_2c = local_2c - 1;
            } while (local_2c != 0);
            iVar3 = *(int *)(iVar5 + *(int *)(param_1 + 0xb8));
            if (iVar3 != 0) {
              puVar6[-1] = *(undefined2 *)(iVar3 + 0x14);
              iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0xb8) + iVar5) + 0x10);
              if (iVar3 != 0) {
                iVar3 = FUN_0061319b(iVar3,0xffffffff,7,&local_30);
                if (iVar3 < 0) goto LAB_00619919;
                local_2c = 0;
                if (local_64 != 0) {
                  do {
                    if (local_20[local_2c] == local_30) break;
                    local_2c = local_2c + 1;
                  } while (local_2c < local_64);
                }
                if (local_2c == local_64) {
                  local_20[local_64] = local_30;
                  local_64 = local_64 + 1;
                }
                *puVar6 = (short)local_2c;
              }
            }
            local_8 = local_8 + 1;
            iVar5 = iVar5 + 0x18;
            puVar6 = puVar6 + 4;
          } while (local_8 < local_5c);
        }
        if (((local_64 != 0) &&
            (local_10 = FUN_0061319b(local_20,local_64 << 2,1,local_60), local_10 < 0)) ||
           (local_10 = FUN_0061319b(local_18,local_34,1,local_58), puVar7 = local_14, local_10 < 0))
        goto LAB_00619919;
        if (local_c != 0) {
          FUN_005f7e20(FUN_006136ce,local_14,local_c,param_1);
          uVar1 = 1;
          local_54 = 1;
          if (1 < local_c) {
            do {
              if (*(int *)(*(int *)(*(int *)(param_1 + 0x14) + puVar7[uVar1 - 1] * 4) + 0x44) !=
                  *(int *)(*(int *)(*(int *)(param_1 + 0x14) + puVar7[uVar1] * 4) + 0x44)) {
                local_54 = local_54 + 1;
              }
              uVar1 = uVar1 + 1;
            } while (uVar1 < local_c);
          }
          local_24 = _malloc(local_54 * 0x14);
          if (local_24 == (undefined4 *)0x0) goto LAB_006198f9;
          local_38 = local_54 * 0x14;
          puVar7 = local_24;
          for (uVar1 = local_54 * 5 & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
          }
          for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *(undefined1 *)puVar7 = 0;
            puVar7 = (undefined4 *)((int)puVar7 + 1);
          }
          local_8 = 0;
          local_28 = 0;
          if (local_54 != 0) {
            piVar2 = local_24 + 3;
            do {
              uVar1 = *(uint *)(*(int *)(*(int *)(param_1 + 0x14) + local_14[local_8] * 4) + 0x44);
              local_2c = uVar1;
              if ((((*(int *)(uVar1 + 0x20) != 0) &&
                   (local_10 = FUN_0061319b(*(int *)(uVar1 + 0x20),0xffffffff,7,piVar2 + -3),
                   local_10 < 0)) ||
                  ((iVar3 = *(int *)(*(int *)(uVar1 + 0x14) + 0x18), iVar3 != 0 &&
                   (local_10 = FUN_0061319b(iVar3,0xffffffff,7,piVar2 + -2), local_10 < 0)))) ||
                 (((*(int *)(uVar1 + 0x10) == 1 || (*(int *)(uVar1 + 0x10) == 2)) &&
                  (local_10 = FUN_00615b5d(local_48,*(undefined4 *)(*(int *)(uVar1 + 0x18) + 0x20),1
                                           ,piVar2 + -1), local_10 < 0)))) goto LAB_00619919;
              local_30 = local_8;
              while (local_8 < local_c) {
                iVar3 = *(int *)(*(int *)(param_1 + 0x14) + local_14[local_8] * 4);
                if (uVar1 != *(uint *)(iVar3 + 0x44)) break;
                local_34 = *(int *)(iVar3 + 0x58);
                while (((local_8 < local_c &&
                        (iVar3 = *(int *)(*(int *)(param_1 + 0x14) + local_14[local_8] * 4),
                        uVar1 == *(uint *)(iVar3 + 0x44))) && (local_34 == *(int *)(iVar3 + 0x58))))
                {
                  local_8 = local_8 + 1;
                }
                *piVar2 = *piVar2 + 1;
              }
              local_1c = _malloc(*piVar2 * 0xc);
              if (local_1c == (undefined4 *)0x0) goto LAB_006198f9;
              local_10 = *piVar2 * 0xc;
              puVar7 = local_1c;
              for (uVar1 = *piVar2 * 3 & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
                *puVar7 = 0;
                puVar7 = puVar7 + 1;
              }
              for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                *(undefined1 *)puVar7 = 0;
                puVar7 = (undefined4 *)((int)puVar7 + 1);
              }
              *piVar2 = 0;
              local_8 = local_30;
              while ((local_8 < local_c &&
                     (iVar3 = *(int *)(*(int *)(param_1 + 0x14) + local_14[local_8] * 4),
                     local_2c == *(uint *)(iVar3 + 0x44)))) {
                local_34 = *(int *)(iVar3 + 0x58);
                local_1c[*piVar2 * 3] = local_34;
                iVar3 = *piVar2;
                local_1c[iVar3 * 3 + 1] = 0xffffffff;
                (local_1c + iVar3 * 3 + 1)[1] = 0xffffffff;
                while (((local_8 < local_c &&
                        (iVar3 = *(int *)(*(int *)(param_1 + 0x14) + local_14[local_8] * 4),
                        local_2c == *(uint *)(iVar3 + 0x44))) &&
                       (local_34 == *(int *)(iVar3 + 0x58)))) {
                  local_8 = local_8 + 1;
                  *(undefined2 *)((int)local_1c + (*(int *)(iVar3 + 0xc) + *piVar2 * 6) * 2 + 4) =
                       *(undefined2 *)(iVar3 + 0x48);
                }
                *piVar2 = *piVar2 + 1;
              }
              local_10 = FUN_0061319b(local_1c,local_10,0xb,piVar2 + 1);
              if (local_10 < 0) goto LAB_00619919;
              local_1c = (undefined4 *)0x0;
              local_28 = local_28 + 1;
              piVar2 = piVar2 + 5;
            } while (local_28 < local_54);
          }
          local_10 = FUN_0061319b(local_24,local_38,1,local_50);
          if (local_10 < 0) goto LAB_00619919;
        }
LAB_006197d2:
        if (((*(int *)(param_1 + 0x48) != 0) &&
            (local_10 = FUN_0061319b(*(int *)(param_1 + 0x48),0xffffffff,7,local_4c), local_10 < 0))
           || (((*(int *)(param_1 + 0xc4) != 0 &&
                ((iVar3 = FUN_0061319b(*(int *)(param_1 + 0xc4),*(undefined4 *)(param_1 + 200),5,
                                       local_68), iVar3 < 0 ||
                 (iVar3 = FUN_0061319b(&DAT_006b9172,1,5,0), iVar3 < 0)))) ||
               (iVar3 = FUN_0061319b(PTR_s_D3DX9_Shader_Compiler_006df698,0xffffffff,5,local_6c),
               iVar3 < 0)))) goto LAB_00619919;
        uVar1 = FUN_006132d2();
        if (uVar1 < 0x8001) {
          local_10 = FUN_00615e2f(uVar1);
          if (local_10 < 0) goto LAB_00619919;
          _memmove((void *)(*(int *)(param_1 + 0xa0) + 4 + uVar1 * 4),
                   (void *)(*(int *)(param_1 + 0xa0) + 4),*(int *)(param_1 + 0xa4) * 4 - 4);
          uVar4 = 0;
          if (local_5c != 0) {
            piVar2 = local_18 + 1;
            do {
              *piVar2 = *piVar2 + (*(int *)(param_1 + 0xb4) + uVar1) * 4;
              uVar4 = uVar4 + 1;
              piVar2 = piVar2 + 2;
            } while (uVar4 < local_5c);
          }
          local_10 = FUN_006132de(*(int *)(param_1 + 0xa0) + 4,uVar1);
          if (local_10 < 0) goto LAB_00619919;
          *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 0xa4) + uVar1;
          *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + uVar1;
          *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0xa4);
        }
        else {
          FUN_005fbf37(param_1,0,0x11c3,
                       "debug info exceeds maximum comment size; no debug info emitted");
        }
        local_10 = 0;
        goto LAB_00619919;
      }
    }
  }
LAB_006198f9:
  local_10 = -0x7ff8fff2;
LAB_00619919:
  _free(local_20);
  _free(local_18);
  _free(local_24);
  _free(local_1c);
  _free(local_14);
  FUN_00613165();
  return local_10;
}


// ==== 0x619954 FUN_00619954

int __thiscall FUN_00619954(int *param_1,uint *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  HMODULE hModule;
  FARPROC pFVar5;
  int *piVar6;
  void *pvVar7;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  char *pcVar16;
  undefined4 local_40 [3];
  void *local_34;
  int *local_30;
  undefined4 *local_2c;
  undefined4 *local_28;
  int *local_24;
  undefined4 *local_20;
  uint local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  param_1[0x27] = 0;
  local_8 = (int *)0x0;
  local_c = (int *)0x0;
  local_30 = (int *)0x0;
  local_1c = 0;
  local_28 = (undefined4 *)0x0;
  local_10 = (int *)0x0;
  local_14 = (int *)0x0;
  local_24 = (int *)0x0;
  local_34 = (void *)0x0;
  local_18 = (int *)0x0;
  local_20 = (undefined4 *)0x0;
  iVar4 = FUN_00602b25(param_2,param_3);
  if (iVar4 < 0) goto LAB_0061a1ce;
  uVar13 = 0;
  if (param_1[2] != 0) {
    do {
      piVar6 = *(int **)(param_1[5] + uVar13 * 4);
      uVar11 = *(uint *)(*(int *)(param_1[4] + *piVar6 * 4) + 4);
      if (((((uVar11 & 8) != 0) && ((uVar11 & 0x100) == 0)) || ((uVar11 & 0x10) != 0)) &&
         (iVar4 = (**(code **)(*param_1 + 8))(piVar6,0), iVar4 < 0)) goto LAB_0061a09f;
      uVar13 = uVar13 + 1;
    } while (uVar13 < (uint)param_1[2]);
  }
  piVar6 = (int *)param_1[0x42];
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 8))(piVar6);
    param_1[0x42] = 0;
  }
  if ((((*(byte *)(param_1 + 0xd) & 4) == 0) &&
      ((hModule = GetModuleHandleA("d3d9.dll"), hModule != (HMODULE)0x0 ||
       (hModule = LoadLibraryA("d3d9.dll"), hModule != (HMODULE)0x0)))) &&
     (pFVar5 = GetProcAddress(hModule,"Direct3DShaderValidatorCreate9"), pFVar5 != (FARPROC)0x0)) {
    piVar6 = (int *)(*pFVar5)();
    param_1[0x42] = (int)piVar6;
    if ((piVar6 != (int *)0x0) &&
       (iVar4 = (**(code **)(*piVar6 + 0xc))(piVar6,FUN_006166af,param_1,1), iVar4 < 0))
    goto LAB_0061a1ce;
  }
  if ((*(byte *)(param_1 + 0xd) & 1) == 0) {
LAB_00619a99:
    param_1[0x33] = -1;
    uVar13 = 0;
    param_1[0x38] = 0;
    if (param_1[2] != 0) {
      do {
        *(undefined4 *)(*(int *)(param_1[5] + uVar13 * 4) + 0x1c) = 0;
        iVar4 = uVar13 * 4;
        uVar13 = uVar13 + 1;
        *(undefined4 *)(*(int *)(param_1[5] + iVar4) + 0x20) = 0;
      } while (uVar13 < (uint)param_1[2]);
    }
    local_2c = (undefined4 *)0x0;
    param_3 = (int *)0x0;
    if (param_1[2] != 0) {
      do {
        piVar6 = *(int **)(param_1[5] + (int)param_3 * 4);
        iVar4 = *(int *)(param_1[4] + *piVar6 * 4);
        uVar13 = *(uint *)(iVar4 + 4);
        if ((((uVar13 & 8) != 0) && ((uVar13 & 0x100) == 0)) || ((uVar13 & 0x10) != 0)) {
          (**(code **)(*param_1 + 8))(piVar6,0);
        }
        if ((*(byte *)(iVar4 + 4) & 0x40) != 0) {
          local_2c = (undefined4 *)((int)local_2c + 1);
        }
        param_3 = (int *)((int)param_3 + 1);
      } while (param_3 < (int *)param_1[2]);
    }
    if ((undefined4 *)param_1[0x22] < local_2c) {
      iVar4 = FUN_005d779c(param_1[0xc],0,local_40);
      if (-1 < iVar4) {
        if (param_1[0x22] == 0) {
          FUN_005fbec8(param_1,0,0x11c1,"%s target does not support texture lookups",local_40[0]);
        }
        else {
          FUN_005fbec8(param_1,0,0x119e,
                       "maximum number of samplers exceeded. %s target can have a maximum of %i samplers"
                       ,local_40[0],param_1[0x22]);
        }
      }
LAB_0061a09f:
      iVar4 = -0x7fffbffb;
      goto LAB_0061a1ce;
    }
    if ((((param_1[0xc] & 0xffff0000U) == 0xfffe0000) &&
        (iVar4 = FUN_00613d78(param_1[0x16],param_1[0x1b],8,0x100,0x76), iVar4 < 0)) ||
       (((param_1[0xc] & 0xffff0000U) == 0xffff0000 &&
        (iVar4 = FUN_00613d78(0xffffffff,param_1[0x22],0x40,0,0x73), iVar4 < 0))))
    goto LAB_0061a1ce;
    if (param_1[2] != 0) {
      param_3 = (int *)param_1[2];
      piVar6 = (int *)param_1[5];
      do {
        piVar8 = (int *)*piVar6;
        iVar4 = *piVar8;
        piVar2 = local_c;
        if ((((param_1[0x18] != iVar4) ||
             (piVar1 = (int *)(piVar8[2] + 1), piVar3 = local_8, (int *)(piVar8[2] + 1) <= local_30)
             ) && (((piVar1 = local_30, param_1[0x16] != iVar4 ||
                    (piVar3 = (int *)(piVar8[2] + 1), (int *)(piVar8[2] + 1) <= local_8)) &&
                   (((param_1[0x17] != iVar4 ||
                     (piVar2 = (int *)(piVar8[2] + 1), piVar3 = local_8,
                     (int *)(piVar8[2] + 1) <= local_c)) &&
                    (piVar2 = local_c, piVar3 = local_8,
                    (*(byte *)(*(int *)(param_1[4] + iVar4 * 4) + 4) & 0x40) != 0)))))) &&
           (local_1c < piVar8[2] + 1U)) {
          local_1c = piVar8[2] + 1U;
        }
        local_8 = piVar3;
        local_c = piVar2;
        local_30 = piVar1;
        piVar6 = piVar6 + 1;
        param_3 = (int *)((int)param_3 - 1);
      } while (param_3 != (int *)0x0);
    }
    local_2c = (undefined4 *)((int)local_8 << 2);
    local_10 = _malloc((size_t)local_2c);
    if (local_10 != (int *)0x0) {
      piVar6 = (int *)((int)local_c << 2);
      param_3 = piVar6;
      local_14 = _malloc((size_t)piVar6);
      if (local_14 != (int *)0x0) {
        local_30 = (int *)(local_1c << 2);
        local_24 = _malloc((size_t)local_30);
        if (((local_24 != (int *)0x0) &&
            (local_34 = _malloc((size_t)local_2c), local_34 != (void *)0x0)) &&
           (local_18 = _malloc((size_t)piVar6), local_18 != (int *)0x0)) {
          piVar6 = local_10;
          for (uVar13 = (uint)local_2c >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
            *piVar6 = 0;
            piVar6 = piVar6 + 1;
          }
          for (uVar13 = (uint)local_2c & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
            *(undefined1 *)piVar6 = 0;
            piVar6 = (int *)((int)piVar6 + 1);
          }
          piVar6 = local_14;
          for (uVar13 = (uint)param_3 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
            *piVar6 = 0;
            piVar6 = piVar6 + 1;
          }
          for (uVar13 = (uint)param_3 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
            *(undefined1 *)piVar6 = 0;
            piVar6 = (int *)((int)piVar6 + 1);
          }
          piVar6 = local_24;
          for (uVar13 = (uint)local_30 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
            *piVar6 = 0;
            piVar6 = piVar6 + 1;
          }
          for (uVar13 = (uint)local_30 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
            *(undefined1 *)piVar6 = 0;
            piVar6 = (int *)((int)piVar6 + 1);
          }
          uVar13 = 0;
          if (param_1[2] != 0) {
            do {
              piVar6 = *(int **)(param_1[5] + uVar13 * 4);
              iVar4 = *piVar6;
              if (param_1[0x17] == iVar4) {
                piVar8 = local_14;
                if (piVar6[0x14] == -1) {
                  pcVar16 = "internal error: output register missing semantic";
LAB_00619e81:
                  uVar15 = 0;
                  uVar14 = 0;
                  goto LAB_0061a261;
                }
LAB_00619d3d:
                piVar8[piVar6[2]] = (int)piVar6;
              }
              else {
                if (param_1[0x16] == iVar4) {
                  piVar8 = local_10;
                  if (piVar6[0x14] == -1) {
                    pcVar16 = "internal error: input register missing semantic";
                    goto LAB_00619e81;
                  }
                  goto LAB_00619d3d;
                }
                piVar8 = local_24;
                if ((*(byte *)(*(int *)(param_1[4] + iVar4 * 4) + 4) & 0x40) != 0)
                goto LAB_00619d3d;
              }
              uVar13 = uVar13 + 1;
            } while (uVar13 < (uint)param_1[2]);
          }
          param_3 = (int *)0x0;
          if (param_1[2] != 0) {
            do {
              piVar6 = *(int **)(param_1[5] + (int)param_3 * 4);
              if ((param_1[0x16] == *piVar6) && (piVar8 = (int *)0x0, local_8 != (int *)0x0)) {
                do {
                  if ((local_10[(int)piVar8] != 0) &&
                     (piVar6[0x14] == *(int *)(local_10[(int)piVar8] + 0x50))) {
                    piVar6[2] = (int)piVar8;
                  }
                  piVar8 = (int *)((int)piVar8 + 1);
                } while (piVar8 < local_8);
              }
              param_3 = (int *)((int)param_3 + 1);
            } while (param_3 < (int *)param_1[2]);
          }
          piVar6 = local_10;
          for (uVar13 = (uint)local_2c >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
            *piVar6 = 0;
            piVar6 = piVar6 + 1;
          }
          uVar11 = 0;
          for (uVar13 = (uint)local_2c & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
            *(undefined1 *)piVar6 = 0;
            piVar6 = (int *)((int)piVar6 + 1);
          }
          if (param_1[2] != 0) {
            do {
              piVar6 = *(int **)(param_1[5] + uVar11 * 4);
              uVar13 = *(uint *)(*(int *)(param_1[4] + *piVar6 * 4) + 4);
              if (((uVar13 & 8) != 0) && ((uVar13 & 0x100) == 0)) {
                local_10[piVar6[2]] = (int)piVar6;
              }
              uVar11 = uVar11 + 1;
            } while (uVar11 < (uint)param_1[2]);
          }
          piVar6 = (int *)0x0;
          local_30 = (int *)0x0;
          if (local_8 != (int *)0x0) {
            do {
              if (local_10[(int)piVar6] != 0) {
                local_30 = (int *)((int)local_30 + 1);
              }
              piVar6 = (int *)((int)piVar6 + 1);
            } while (piVar6 < local_8);
          }
          iVar4 = FUN_0061678a();
          uVar13 = 0;
          if (((iVar4 < 0) || (iVar4 = (**(code **)(*param_1 + 0x30))(), iVar4 < 0)) ||
             (((((*(byte *)(param_1 + 0xd) & 8) == 0 ||
                ((*(byte *)((int)param_1 + 0x92) & 0x10) != 0)) &&
               ((iVar4 = FUN_0061674c(), iVar4 < 0 ||
                (iVar4 = (**(code **)(*param_1 + 0x2c))(), iVar4 < 0)))) ||
              (iVar4 = FUN_00613d78(param_1[0x15],param_1[0x1e],0x100,0x40,99), iVar4 < 0))))
          goto LAB_0061a1ce;
          param_1[0x27] = 0;
          if (param_1[3] == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = *(int *)param_1[6];
          }
          param_1[0x26] = iVar4;
          param_1[0x25] = 0;
          iVar4 = (**(code **)(*param_1 + 0x38))();
          if (iVar4 < 0) goto LAB_0061a1ce;
          param_3 = (int *)0x0;
          if (param_1[2] != 0) {
            local_2c = (undefined4 *)param_1[2];
            piVar6 = (int *)param_1[5];
            do {
              if (((*(byte *)(*(int *)(param_1[4] + *(int *)*piVar6 * 4) + 4) & 0x80) != 0) &&
                 (((int *)*piVar6)[1] == -1)) {
                uVar13 = uVar13 + 1;
              }
              piVar6 = piVar6 + 1;
              local_2c = (undefined4 *)((int)local_2c + -1);
            } while (local_2c != (undefined4 *)0x0);
          }
          local_20 = _malloc(uVar13 << 4);
          if (local_20 != (undefined4 *)0x0) {
            local_28 = _malloc(uVar13 << 2);
            if (local_28 != (undefined4 *)0x0) {
              puVar12 = local_20;
              for (iVar4 = (uVar13 & 0xfffffff) << 2; iVar4 != 0; iVar4 = iVar4 + -1) {
                *puVar12 = 0;
                puVar12 = puVar12 + 1;
              }
              for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                *(undefined1 *)puVar12 = 0;
                puVar12 = (undefined4 *)((int)puVar12 + 1);
              }
              puVar12 = local_28;
              for (uVar13 = uVar13 & 0x3fffffff; uVar13 != 0; uVar13 = uVar13 - 1) {
                *puVar12 = 0;
                puVar12 = puVar12 + 1;
              }
              for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                *(undefined1 *)puVar12 = 0;
                puVar12 = (undefined4 *)((int)puVar12 + 1);
              }
              uVar13 = 0;
              if (param_1[2] != 0) {
                do {
                  piVar6 = *(int **)(param_1[5] + uVar13 * 4);
                  if ((((*(byte *)(*(int *)(param_1[4] + *piVar6 * 4) + 4) & 0x80) != 0) &&
                      (piVar6[1] == -1)) && (piVar6[9] == -1)) {
                    piVar8 = (int *)0x0;
                    if (param_3 != (int *)0x0) {
                      do {
                        if (local_28[(int)piVar8] == piVar6[2]) break;
                        piVar8 = (int *)((int)piVar8 + 1);
                      } while (piVar8 < param_3);
                    }
                    if (piVar8 == param_3) {
                      param_3 = (int *)((int)param_3 + 1);
                      local_28[(int)piVar8] = piVar6[2];
                    }
                    local_20[piVar6[3] + (int)piVar8 * 4] = (float)*(double *)(piVar6 + 4);
                  }
                  uVar13 = uVar13 + 1;
                } while (uVar13 < (uint)param_1[2]);
              }
              piVar6 = (int *)0x0;
              if (param_3 != (int *)0x0) {
                local_2c = local_20;
                do {
                  iVar4 = (**(code **)(*param_1 + 0x3c))(local_28[(int)piVar6],local_2c);
                  if (iVar4 < 0) goto LAB_0061a1ce;
                  local_2c = local_2c + 4;
                  piVar6 = (int *)((int)piVar6 + 1);
                } while (piVar6 < param_3);
              }
              if ((int *)param_1[0x20] < local_30) {
                pcVar16 = "maximum number of inputs exceeded";
                uVar15 = 0x119a;
                uVar14 = 0;
LAB_0061a261:
                FUN_005fbec8(param_1,uVar14,uVar15,pcVar16);
              }
              else {
                param_3 = (int *)0x0;
                if (local_8 != (int *)0x0) {
                  iVar4 = (int)local_34 - (int)local_10;
                  local_30 = local_8;
                  piVar6 = local_10;
                  do {
                    if ((*piVar6 != 0) &&
                       (iVar9 = (**(code **)(*param_1 + 0x40))
                                          (*piVar6,(undefined1 *)(iVar4 + (int)piVar6)), iVar9 < 0))
                    {
                      param_3 = (int *)0x1;
                    }
                    piVar6 = piVar6 + 1;
                    local_30 = (int *)((int)local_30 + -1);
                  } while (local_30 != (int *)0x0);
                }
                iVar4 = (**(code **)(*param_1 + 0x48))();
                uVar13 = 0;
                if (iVar4 < 0) goto LAB_0061a1ce;
                if (local_1c != 0) {
                  do {
                    if ((local_24[uVar13] != 0) &&
                       (iVar4 = (**(code **)(*param_1 + 0x44))(local_24[uVar13]), iVar4 < 0)) {
                      param_3 = (int *)0x1;
                    }
                    uVar13 = uVar13 + 1;
                  } while (uVar13 < local_1c);
                }
                if (local_c != (int *)0x0) {
                  iVar4 = (int)local_18 - (int)local_14;
                  local_30 = local_c;
                  piVar6 = local_14;
                  do {
                    if ((*piVar6 != 0) &&
                       (iVar9 = (**(code **)(*param_1 + 0x5c))
                                          (*piVar6,(undefined1 *)(iVar4 + (int)piVar6),0), iVar9 < 0
                       )) {
                      param_3 = (int *)0x1;
                    }
                    piVar6 = piVar6 + 1;
                    local_30 = (int *)((int)local_30 + -1);
                  } while (local_30 != (int *)0x0);
                }
                iVar4 = 0;
                if (param_3 == (int *)0x0) {
                  piVar6 = (int *)0x0;
                  if (local_c != (int *)0x0) {
                    do {
                      if ((*(int *)(iVar4 + (int)local_14) != 0) &&
                         (param_3 = (int *)0x0, iVar4 != 0)) {
                        piVar8 = local_18;
                        do {
                          if ((*(int *)(((int)local_14 - (int)local_18) + (int)piVar8) != 0) &&
                             (*(int *)(iVar4 + (int)local_18) == *piVar8)) {
                            pcVar16 = "overlapping output semantics";
                            uVar15 = 0x1198;
                            uVar14 = *(undefined4 *)(local_14[(int)piVar6] + 0x4c);
                            goto LAB_0061a261;
                          }
                          param_3 = (int *)((int)param_3 + 1);
                          piVar8 = piVar8 + 1;
                        } while (param_3 < piVar6);
                      }
                      piVar6 = (int *)((int)piVar6 + 1);
                      iVar4 = iVar4 + 4;
                    } while (piVar6 < local_c);
                  }
                  iVar4 = FUN_0061674c();
                  if ((((((-1 < iVar4) && (iVar4 = (**(code **)(*param_1 + 0x28))(), -1 < iVar4)) &&
                        (iVar4 = FUN_00618c64(), -1 < iVar4)) &&
                       (((*(byte *)(param_1 + 0xd) & 1) == 0 || (iVar4 = FUN_00619309(), -1 < iVar4)
                        ))) && ((iVar4 = FUN_00618c39(0xffff), -1 < iVar4 &&
                                (iVar4 = FUN_0061663f(), -1 < iVar4)))) &&
                     (((piVar6 = (int *)param_1[0x42], piVar6 == (int *)0x0 || (param_1[0xe] != 0))
                      || (iVar4 = (**(code **)(*piVar6 + 0x14))(piVar6), -1 < iVar4)))) {
                    if (param_2 != (uint *)0x0) {
                      iVar4 = FUN_005d65b0(param_1[0x29] << 2,&param_3);
                      if (iVar4 < 0) goto LAB_0061a1ce;
                      puVar12 = (undefined4 *)param_1[0x28];
                      local_30 = (int *)(param_1[0x29] << 2);
                      puVar10 = (undefined4 *)(**(code **)(*param_3 + 0xc))(param_3);
                      for (uVar13 = (uint)local_30 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
                        *puVar10 = *puVar12;
                        puVar12 = puVar12 + 1;
                        puVar10 = puVar10 + 1;
                      }
                      for (uVar13 = (uint)local_30 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
                        *(undefined1 *)puVar10 = *(undefined1 *)puVar12;
                        puVar12 = (undefined4 *)((int)puVar12 + 1);
                        puVar10 = (undefined4 *)((int)puVar10 + 1);
                      }
                      *param_2 = (uint)param_3;
                    }
                    iVar4 = 0;
                  }
                  goto LAB_0061a1ce;
                }
              }
            }
            goto LAB_0061a09f;
          }
        }
      }
    }
  }
  else {
    pvVar7 = _malloc(param_1[3] * 0x30);
    param_1[0x2e] = (int)pvVar7;
    if (pvVar7 != (void *)0x0) {
      param_1[0x2f] = 0;
      param_1[0x30] = param_1[3] << 1;
      goto LAB_00619a99;
    }
  }
  iVar4 = -0x7ff8fff2;
LAB_0061a1ce:
  _free(local_10);
  _free(local_14);
  _free(local_34);
  _free(local_18);
  _free((void *)0x0);
  _free(local_20);
  _free(local_28);
  _free(local_24);
  _free((void *)param_1[0x28]);
  param_1[0x28] = 0;
  _free((void *)param_1[0x2e]);
  param_1[0x2e] = 0;
  piVar6 = (int *)param_1[0x42];
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 8))(piVar6);
    param_1[0x42] = 0;
  }
  return iVar4;
}


// ==== 0x61a26f FUN_0061a26f

undefined4 __thiscall FUN_0061a26f(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (((*(byte *)(param_1 + 0x34) & 1) != 0) && (*(int *)(param_1 + 0xb8) != 0)) {
    if (*(uint *)(param_1 + 0xc0) <= *(uint *)(param_1 + 0xbc)) {
      puVar1 = _malloc(*(uint *)(param_1 + 0xc0) * 0x30);
      if (puVar1 == (undefined4 *)0x0) {
        return 0x8007000e;
      }
      puVar4 = *(undefined4 **)(param_1 + 0xb8);
      puVar5 = puVar1;
      for (iVar2 = (*(int *)(param_1 + 0xbc) * 3 & 0x1fffffffU) << 1; iVar2 != 0; iVar2 = iVar2 + -1
          ) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
      _free(*(void **)(param_1 + 0xb8));
      *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xc0) << 1;
      *(undefined4 **)(param_1 + 0xb8) = puVar1;
    }
    *(undefined4 *)(*(int *)(param_1 + 0xb8) + *(int *)(param_1 + 0xbc) * 0x18) =
         *(undefined4 *)(param_1 + 0x9c);
    *(int *)(*(int *)(param_1 + 0xb8) + 4 + *(int *)(param_1 + 0xbc) * 0x18) =
         *(int *)(param_1 + 0xa4) << 2;
    uVar3 = 0;
    do {
      *(undefined4 *)(*(int *)(param_1 + 0xb8) + 8 + (uVar3 + *(int *)(param_1 + 0xbc) * 6) * 4) =
           0xffffffff;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 4);
    *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + 1;
  }
  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_1 + 0xa4);
  FUN_00618c39(param_2);
  return 0;
}


// ==== 0x61a36a FUN_0061a36a

int FUN_0061a36a(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00618c39(param_1);
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}


// ==== 0x61a37c FUN_0061a37c

int FUN_0061a37c(uint param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = FUN_0061a36a(param_1 | param_2);
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}


// ==== 0x61a393 FUN_0061a393

int __thiscall FUN_0061a393(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = FUN_0061a36a(param_2 | param_3);
  if (-1 < iVar2) {
    if (((param_2 | param_3) & 0x2000) != 0) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x14) + param_4 * 4);
      iVar1 = *(int *)(iVar2 + 0xc);
      uVar3 = *(uint *)(iVar2 + 8) & 0x7ff;
      uVar4 = uVar3 | 0xb0000000;
      if (iVar1 != 0) {
        if (iVar1 == 1) {
          uVar4 = uVar3 | 0xb0550000;
        }
        else if (iVar1 == 2) {
          uVar4 = uVar3 | 0xb0aa0000;
        }
        else if (iVar1 == 3) {
          uVar4 = uVar3 | 0xb0ff0000;
        }
      }
      FUN_0061a36a(uVar4);
    }
    iVar2 = 0;
  }
  return iVar2;
}


// ==== 0x61a3fb FUN_0061a3fb

int __thiscall
FUN_0061a3fb(int *param_1,undefined4 param_2,int *param_3,undefined4 param_4,int *param_5,
            int *param_6,int *param_7,undefined4 param_8,uint param_9,uint param_10,uint param_11)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar2 = (**(code **)(*param_1 + 0x4c))(param_2);
  iVar3 = FUN_0061a26f(iVar2);
  piVar1 = param_3;
  if ((((-1 < iVar3) &&
       (iVar3 = (**(code **)(*param_1 + 0x5c))
                          (*(undefined4 *)(param_1[5] + *param_3 * 4),&local_8,&local_14),
       -1 < iVar3)) &&
      (iVar3 = (**(code **)(*param_1 + 0x60))(piVar1,param_4,&param_2,local_14), -1 < iVar3)) &&
     (iVar3 = (**(code **)(*param_1 + 0x54))(local_8,param_2), piVar1 = param_5, -1 < iVar3)) {
    if (iVar2 == 8) {
      param_2 = 0x70000;
    }
    else if (iVar2 == 9) {
      param_2 = 0xf0000;
    }
    else if (iVar2 == 0x5a) {
      param_2 = 0x30000;
    }
    else if (((iVar2 == 6) || (iVar2 == 0xe)) || ((iVar2 == 0xf || (iVar2 == 7)))) {
      param_2 = 0x10000;
    }
    if (((param_5 == (int *)0x0) ||
        (((iVar3 = (**(code **)(*param_1 + 100))
                             (*(undefined4 *)(param_1[5] + *param_5 * 4),&local_8,&local_c),
          -1 < iVar3 &&
          (iVar3 = (**(code **)(*param_1 + 0x68))(piVar1,param_8,param_2,&local_10), -1 < iVar3)) &&
         (iVar3 = (**(code **)(*param_1 + 0x58))(local_8 ^ param_9,local_10,local_c), -1 < iVar3))))
       && ((((piVar1 = param_6, param_6 == (int *)0x0 ||
             (((iVar3 = (**(code **)(*param_1 + 100))
                                  (*(undefined4 *)(param_1[5] + *param_6 * 4),&local_8,&local_c),
               -1 < iVar3 &&
               (iVar3 = (**(code **)(*param_1 + 0x68))(piVar1,param_8,param_2,&local_10), -1 < iVar3
               )) && (iVar3 = (**(code **)(*param_1 + 0x58))(local_8 ^ param_10,local_10,local_c),
                     -1 < iVar3)))) &&
            ((piVar1 = param_7, param_7 == (int *)0x0 ||
             (((iVar3 = (**(code **)(*param_1 + 100))
                                  (*(undefined4 *)(param_1[5] + *param_7 * 4),&local_8,&local_c),
               -1 < iVar3 &&
               (iVar3 = (**(code **)(*param_1 + 0x68))(piVar1,param_8,param_2,&local_10), -1 < iVar3
               )) && (iVar3 = (**(code **)(*param_1 + 0x58))(local_8 ^ param_11,local_10,local_c),
                     -1 < iVar3)))))) &&
           ((iVar3 = (**(code **)(*param_1 + 0x50))(), -1 < iVar3 &&
            (iVar3 = FUN_0061663f(), -1 < iVar3)))))) {
      iVar3 = 0;
    }
  }
  return iVar3;
}


// ==== 0x61a5d9 FUN_0061a5d9

int __thiscall FUN_0061a5d9(int *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *unaff_retaddr;
  
  if (param_2 < 0x800) {
    uVar1 = param_2 & 0x7ff | 0xa0000000;
  }
  else if (param_2 < 0x1000) {
    uVar1 = param_2 & 0x7ff | 0xb0000800;
  }
  else if (param_2 < 0x1800) {
    uVar1 = param_2 & 0x7ff | 0xc0000800;
  }
  else {
    uVar1 = param_2 & 0x7ff | 0xd0000800;
  }
  iVar2 = FUN_0061a26f(0x51);
  if (-1 < iVar2) {
    iVar2 = (**(code **)(*param_1 + 0x54))(uVar1,0xf0000);
    if (-1 < iVar2) {
      iVar2 = FUN_00618c39(*unaff_retaddr);
      if (-1 < iVar2) {
        iVar2 = FUN_00618c39(unaff_retaddr[1]);
        if (-1 < iVar2) {
          iVar2 = FUN_00618c39(unaff_retaddr[2]);
          if (-1 < iVar2) {
            iVar2 = FUN_00618c39(unaff_retaddr[3]);
            if (-1 < iVar2) {
              iVar2 = (**(code **)(*param_1 + 0x50))();
              if (-1 < iVar2) {
                iVar2 = FUN_0061663f();
                if (-1 < iVar2) {
                  iVar2 = 0;
                }
              }
            }
          }
        }
      }
    }
  }
  return iVar2;
}


// ==== 0x61a69c FUN_0061a69c

void __fastcall FUN_0061a69c(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar1 = *(uint **)(param_1 + 0x98);
  uVar2 = puVar1[3];
  uVar3 = *puVar1;
  uVar4 = puVar1[4];
  FUN_005f7a5c(0,&local_8);
  FUN_005f7a5c(1,&local_c);
  FUN_0061a3fb(0x42,uVar4,uVar2,local_c,local_8,0,uVar3 & 0xffffff,0,0,0);
  return;
}


// ==== 0x61a6fd FUN_0061a6fd

void __fastcall FUN_0061a6fd(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar1 = *(uint **)(param_1 + 0x98);
  uVar2 = puVar1[3];
  uVar3 = *puVar1;
  uVar4 = puVar1[4];
  FUN_005f7a5c(0,&local_8);
  FUN_005f7a5c(1,&local_c);
  FUN_0061a3fb(0x10042,uVar4,uVar2,local_c,local_8,0,uVar3 & 0xffffff,0,0,0);
  return;
}


// ==== 0x61a761 FUN_0061a761

void __fastcall FUN_0061a761(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar1 = *(uint **)(param_1 + 0x98);
  uVar2 = puVar1[3];
  uVar3 = *puVar1;
  uVar4 = puVar1[4];
  FUN_005f7a5c(0,&local_8);
  FUN_005f7a5c(1,&local_c);
  FUN_0061a3fb(0x20042,uVar4,uVar2,local_c,local_8,0,uVar3 & 0xffffff,0,0,0);
  return;
}


// ==== 0x61a7c5 FUN_0061a7c5

void __fastcall FUN_0061a7c5(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = *(uint **)(param_1 + 0x98);
  uVar2 = puVar1[2];
  uVar3 = *puVar1 & 0xffffff;
  FUN_0061a3fb(0x5a,puVar1[4],puVar1[3],uVar2,uVar2 + uVar3 * 4,uVar2 + uVar3 * 8,uVar3,0,0,0);
  return;
}


// ==== 0x61a7fa FUN_0061a7fa

int __fastcall FUN_0061a7fa(int *param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  char *pcVar5;
  int *local_c;
  uint local_8;
  
  local_8 = 0;
  iVar2 = param_1[0x26];
  uVar1 = *(uint *)(iVar2 + 4);
  local_c = param_1;
  if (uVar1 != 0) {
    piVar3 = *(int **)(iVar2 + 8);
    do {
      if ((*(uint *)(*(int *)(param_1[5] + *piVar3 * 4) + 0xc) != local_8) &&
         ((*(byte *)((int)param_1 + 0x92) & 0x20) != 0)) {
        pcVar5 = "cannot clip from a swizzled vector";
        goto LAB_0061a90b;
      }
      local_8 = local_8 + 1;
      piVar3 = piVar3 + 1;
    } while (local_8 < uVar1);
  }
  if ((*(byte *)((int)param_1 + 0x92) & 0x20) == 0) {
    if (uVar1 == 4) goto LAB_0061a86d;
    pcVar5 = "clip must be performed from a float4 vector for ps_2_0 models";
  }
  else if (uVar1 == 3) {
LAB_0061a86d:
    piVar3 = *(int **)(param_1[5] + **(int **)(iVar2 + 8) * 4);
    if (*piVar3 == param_1[0x16]) {
      iVar2 = (**(code **)(*param_1 + 0x74))(piVar3,&local_c,&local_8);
      if (-1 < iVar2) {
LAB_0061a8b0:
        iVar2 = FUN_0061a26f(0x41);
        if (iVar2 < 0) {
          return iVar2;
        }
        iVar2 = (**(code **)(*param_1 + 0x54))
                          (((local_8 | 0xfffffff8) << 0x14 | local_8 & 0x18) << 8 |
                           (uint)local_c & 0x7ff,0xf0000);
        if (iVar2 < 0) {
          return iVar2;
        }
        iVar2 = (**(code **)(*param_1 + 0x50))();
        if (iVar2 < 0) {
          return iVar2;
        }
        iVar2 = FUN_0061663f();
        if (iVar2 < 0) {
          return iVar2;
        }
        return 0;
      }
      pcVar5 = "internal error: unexpected input register type";
      uVar4 = 0;
      goto LAB_0061a913;
    }
    if (*piVar3 == param_1[0x18]) {
      local_8 = 0;
      local_c = (int *)piVar3[2];
      goto LAB_0061a8b0;
    }
    pcVar5 = "clip cannot be performed from a constant or literal";
  }
  else {
    pcVar5 = "clip must be performed from a float3 vector for ps_1_x models";
  }
LAB_0061a90b:
  uVar4 = *(undefined4 *)(iVar2 + 0x34);
LAB_0061a913:
  FUN_005fbec8(param_1,uVar4,0x1194,pcVar5);
  return -0x7fffbffb;
}


// ==== 0x61a926 FUN_0061a926

int __fastcall FUN_0061a926(int *param_1)

{
  int iVar1;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = FUN_0061a26f(1);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*param_1 + 0x5c))
                      (*(undefined4 *)(param_1[5] + **(int **)(param_1[0x26] + 0x10) * 4),&local_8,
                       &local_10);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*param_1 + 0x60))
                        (*(undefined4 *)(param_1[0x26] + 0x10),*(undefined4 *)(param_1[0x26] + 0xc),
                         &local_c,local_10);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*param_1 + 0x54))(local_8,local_c);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*param_1 + 100))
                            (*(undefined4 *)(param_1[5] + **(int **)(param_1[0x26] + 8) * 4),
                             &local_8,&local_14);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*param_1 + 0x68))
                              (*(undefined4 *)(param_1[0x26] + 8),
                               *(undefined4 *)(param_1[0x26] + 0xc),local_c,&local_18);
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*param_1 + 0x58))(local_8,local_18 | 0x1000000,local_14);
              if (-1 < iVar1) {
                iVar1 = (**(code **)(*param_1 + 0x50))();
                if (-1 < iVar1) {
                  iVar1 = FUN_0061663f();
                  if (-1 < iVar1) {
                    iVar1 = 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return iVar1;
}


// ==== 0x61aa11 FUN_0061aa11

int __fastcall FUN_0061aa11(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  int local_c;
  undefined4 local_8;
  
  uVar3 = *(uint *)param_1[0x26] & 0xffffff;
  uVar1 = (**(code **)(*param_1 + 0x4c))(0x12);
  iVar2 = FUN_0061a26f(uVar1);
  if ((((-1 < iVar2) &&
       (iVar2 = (**(code **)(*param_1 + 0x5c))
                          (*(undefined4 *)(param_1[5] + **(int **)(param_1[0x26] + 0x10) * 4),
                           &local_8,&local_18), -1 < iVar2)) &&
      (iVar2 = (**(code **)(*param_1 + 0x60))
                         (*(undefined4 *)(param_1[0x26] + 0x10),uVar3,&local_14,local_18),
      -1 < iVar2)) && (iVar2 = (**(code **)(*param_1 + 0x54))(local_8,local_14), -1 < iVar2)) {
    local_10 = 0;
    local_c = 0;
    do {
      piVar4 = (int *)(*(int *)(param_1[0x26] + 8) + local_c);
      iVar2 = (**(code **)(*param_1 + 100))
                        (*(undefined4 *)(param_1[5] + *piVar4 * 4),&local_8,&local_1c);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = (**(code **)(*param_1 + 0x68))(piVar4,uVar3,local_14,&local_20);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = (**(code **)(*param_1 + 0x58))(local_8,local_20,local_1c);
      if (iVar2 < 0) {
        return iVar2;
      }
      local_10 = local_10 + 1;
      local_c = local_c + uVar3 * 4;
    } while (local_10 < 3);
    iVar2 = (**(code **)(*param_1 + 0x50))();
    if ((-1 < iVar2) && (iVar2 = FUN_0061663f(), -1 < iVar2)) {
      iVar2 = 0;
    }
  }
  return iVar2;
}


// ==== 0x61ab23 FUN_0061ab23

int __fastcall FUN_0061ab23(int *param_1)

{
  int iVar1;
  uint uVar2;
  int local_18 [4];
  int *local_8;
  
  local_8 = (int *)((uint *)param_1[0x26])[4];
  uVar2 = *(uint *)param_1[0x26] & 0xffffff;
  if (param_1[0x18] != **(int **)(param_1[5] + *local_8 * 4)) {
    iVar1 = (**(code **)(*param_1 + 0x6c))(param_1[0x25],local_18,uVar2,0,0);
    if (iVar1 < 0) {
      return iVar1;
    }
    local_8 = local_18;
  }
  iVar1 = FUN_0061a3fb(0x24,local_8,uVar2,*(undefined4 *)(param_1[0x26] + 8),0,0,uVar2,0,0,0);
  if (-1 < iVar1) {
    if ((local_8 == local_18) &&
       (iVar1 = FUN_0061a3fb(1,*(undefined4 *)(param_1[0x26] + 0x10),uVar2,local_18,0,0,uVar2,0,0,0)
       , iVar1 < 0)) {
      return iVar1;
    }
    iVar1 = 0;
  }
  return iVar1;
}


// ==== 0x61abc1 FUN_0061abc1

int __fastcall FUN_0061abc1(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  uint local_c;
  uint local_8;
  
  uVar4 = *(uint *)param_1[0x26] & 0xffffff;
  uVar2 = (**(code **)(*param_1 + 0x4c))(4);
  iVar3 = FUN_0061a26f(uVar2);
  if ((((-1 < iVar3) &&
       (iVar3 = (**(code **)(*param_1 + 0x5c))
                          (*(undefined4 *)(param_1[5] + **(int **)(param_1[0x26] + 0x10) * 4),
                           &local_c,&local_18), -1 < iVar3)) &&
      (iVar3 = (**(code **)(*param_1 + 0x60))
                         (*(undefined4 *)(param_1[0x26] + 0x10),uVar4,&local_10,local_18),
      -1 < iVar3)) && (iVar3 = (**(code **)(*param_1 + 0x54))(local_c,local_10), -1 < iVar3)) {
    local_8 = 0;
    do {
      piVar1 = (int *)(((uint *)param_1[0x26])[2] + local_8 * uVar4 * 4);
      if ((local_8 == 1) && ((*(uint *)param_1[0x26] & 0xff000000) == 0xf6000000)) {
        local_14 = 0x1000000;
      }
      else {
        local_14 = 0;
      }
      iVar3 = (**(code **)(*param_1 + 100))
                        (*(undefined4 *)(param_1[5] + *piVar1 * 4),&local_c,&local_1c);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar3 = (**(code **)(*param_1 + 0x68))(piVar1,uVar4,local_10,&local_20);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar3 = (**(code **)(*param_1 + 0x58))(local_14 ^ local_c,local_20,local_1c);
      if (iVar3 < 0) {
        return iVar3;
      }
      local_8 = local_8 + 1;
    } while (local_8 < 3);
    iVar3 = (**(code **)(*param_1 + 0x50))();
    if ((-1 < iVar3) && (iVar3 = FUN_0061663f(), -1 < iVar3)) {
      iVar3 = 0;
    }
  }
  return iVar3;
}


// ==== 0x61acf6 FUN_0061acf6

int __fastcall FUN_0061acf6(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  uVar1 = *(uint *)param_1[0x26];
  uVar3 = uVar1 & 0xffffff;
  if (uVar1 == 0xf7000003) {
    uVar4 = 0x18;
  }
  else if (uVar1 == 0xf8000003) {
    uVar4 = 0x17;
  }
  else if (uVar1 == 0xf8000004) {
    uVar4 = 0x15;
  }
  else if (uVar1 == 0xf9000003) {
    uVar4 = 0x16;
  }
  else {
    uVar4 = local_18;
    if (uVar1 == 0xf9000004) {
      uVar4 = 0x14;
    }
  }
  iVar2 = FUN_0061a26f(uVar4);
  if ((((-1 < iVar2) &&
       (iVar2 = (**(code **)(*param_1 + 0x5c))
                          (*(undefined4 *)(param_1[5] + **(int **)(param_1[0x26] + 0x10) * 4),
                           &local_8,&local_18), -1 < iVar2)) &&
      (iVar2 = (**(code **)(*param_1 + 0x60))
                         (*(undefined4 *)(param_1[0x26] + 0x10),*(undefined4 *)(param_1[0x26] + 0xc)
                          ,&local_c,local_18), -1 < iVar2)) &&
     (iVar2 = (**(code **)(*param_1 + 0x54))(local_8,local_c), -1 < iVar2)) {
    local_c = ((uVar3 != 3) - 1 & 0xfff80000) + 0xf0000;
    iVar2 = (**(code **)(*param_1 + 100))
                      (*(undefined4 *)(param_1[5] + **(int **)(param_1[0x26] + 8) * 4),&local_8,
                       &local_10);
    if (((-1 < iVar2) &&
        (iVar2 = (**(code **)(*param_1 + 0x68))
                           (*(undefined4 *)(param_1[0x26] + 8),uVar3,local_c,&local_14), -1 < iVar2)
        ) && (iVar2 = (**(code **)(*param_1 + 0x58))(local_8,local_14,local_10), -1 < iVar2)) {
      iVar2 = (**(code **)(*param_1 + 100))
                        (*(undefined4 *)
                          (param_1[5] + *(int *)(uVar3 * 4 + *(int *)(param_1[0x26] + 8)) * 4),
                         &local_8,&local_10);
      if (((-1 < iVar2) &&
          (iVar2 = (**(code **)(*param_1 + 0x68))
                             (*(int *)(param_1[0x26] + 8) + uVar3 * 4,uVar3,local_c,&local_14),
          -1 < iVar2)) &&
         ((iVar2 = (**(code **)(*param_1 + 0x58))(local_8,local_14,local_10), -1 < iVar2 &&
          ((iVar2 = (**(code **)(*param_1 + 0x50))(), -1 < iVar2 &&
           (iVar2 = FUN_0061663f(), -1 < iVar2)))))) {
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}


// ==== 0x61aea7 FUN_0061aea7

void __thiscall FUN_0061aea7(int param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar1 = *(uint **)(param_1 + 0x98);
  uVar2 = puVar1[4];
  uVar3 = puVar1[3];
  uVar4 = *puVar1;
  FUN_005f7a5c(0,&local_10);
  FUN_005f7a5c(1,&local_c);
  FUN_005f7a5c(2,&local_8);
  FUN_0061a3fb(param_2,uVar2,uVar3,local_10,local_c,local_8,uVar4 & 0xffffff,0,0,0);
  return;
}


// ==== 0x61af1a FUN_0061af1a

int __thiscall
FUN_0061af1a(int *param_1,undefined4 param_2,int *param_3,int *param_4,uint param_5,uint param_6,
            undefined4 param_7)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  bool bVar5;
  int local_24 [4];
  int *local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  if (((param_6 < param_5) && (param_6 == 1)) && (**(int **)(param_1[0x26] + 8) == *param_4)) {
    iVar2 = FUN_0061aea7(param_2);
    return iVar2;
  }
  if (param_6 != param_5) {
    FUN_005fbec8(param_1,0,0x12d3,"internal error: size mismatch in scalar instruction");
    return -0x7fffbffb;
  }
  iVar2 = param_1[5];
  piVar3 = *(int **)(iVar2 + *param_3 * 4);
  piVar1 = *(int **)(iVar2 + *param_4 * 4);
  if ((*piVar3 == *piVar1) && (piVar3[2] == piVar1[2])) {
    local_c = 1;
    if ((*(byte *)(param_1 + 0xd) & 8) == 0) {
      local_8 = 0;
      bVar5 = false;
      if (param_5 != 0) {
        piVar3 = param_4;
        do {
          param_6 = 0;
          if (local_8 != 0) {
            local_14 = *(int **)(*(int *)(iVar2 + *piVar3 * 4) + 0xc);
            local_10 = *(int **)(*(int *)(iVar2 + *(int *)(((int)param_3 - (int)param_4) +
                                                          (int)piVar3) * 4) + 0xc);
            do {
              if (local_14 == local_10) break;
              param_6 = param_6 + 1;
            } while (param_6 < local_8);
            if (param_6 < local_8) break;
          }
          local_8 = local_8 + 1;
          piVar3 = piVar3 + 1;
        } while (local_8 < param_5);
        bVar5 = local_8 < param_5;
      }
      local_c = (uint)bVar5;
      if (local_c == 0) goto LAB_0061b042;
    }
    iVar2 = (**(code **)(*param_1 + 0x6c))(param_1[0x25],local_24,param_5,0,0);
    if (iVar2 < 0) {
      return iVar2;
    }
    local_10 = param_3;
    param_3 = local_24;
  }
  else {
    local_c = 0;
  }
LAB_0061b042:
  uVar4 = 0;
  if (param_5 != 0) {
    do {
      param_6 = 1;
      if (uVar4 + 1 < param_5) {
        piVar3 = param_4 + uVar4;
        local_14 = *(int **)(*(int *)(param_1[5] + *piVar3 * 4) + 0xc);
        local_8 = uVar4 + 1;
        do {
          piVar3 = piVar3 + 1;
          if (*(int **)(*(int *)(param_1[5] + *piVar3 * 4) + 0xc) != local_14) break;
          param_6 = param_6 + 1;
          local_8 = local_8 + 1;
        } while (local_8 < param_5);
      }
      iVar2 = FUN_0061a3fb(param_2,param_3 + uVar4,param_6,param_4 + uVar4,0,0,param_6,param_7,
                           param_7,param_7);
      if (iVar2 < 0) {
        return iVar2;
      }
      uVar4 = uVar4 + param_6;
    } while (uVar4 < param_5);
  }
  if ((local_c == 0) ||
     (iVar2 = FUN_0061a3fb(1,local_10,param_5,param_3,0,0,param_5,0,0,0), -1 < iVar2)) {
    iVar2 = 0;
  }
  return iVar2;
}


// ==== 0x61b0f2 FUN_0061b0f2

undefined4 __fastcall FUN_0061b0f2(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *local_c;
  uint local_8;
  
  iVar4 = *(int *)(param_1 + 0x98);
  local_c = *(int **)(iVar4 + 0x10);
  iVar1 = *(int *)(param_1 + 0x14);
  if (*(int *)(param_1 + 100) == **(int **)(iVar1 + *local_c * 4)) {
    uVar6 = 0x2e;
  }
  else {
    if (((*(byte *)(param_1 + 0x34) & 8) == 0) && ((*(byte *)(param_1 + 0x92) & 8) == 0)) {
      local_8 = 0;
      if (*(int *)(iVar4 + 0xc) != 0) {
        iVar5 = *(int *)(iVar4 + 8) - (int)local_c;
        do {
          piVar2 = *(int **)(iVar1 + *local_c * 4);
          piVar3 = *(int **)(iVar1 + *(int *)(iVar5 + (int)local_c) * 4);
          if ((((*piVar2 != *piVar3) || (piVar2[1] != piVar3[1])) || (piVar2[2] != piVar3[2])) ||
             ((piVar2[3] != piVar3[3] || (piVar2[8] != piVar3[8])))) break;
          local_8 = local_8 + 1;
          local_c = local_c + 1;
        } while (local_8 < *(uint *)(iVar4 + 0xc));
      }
      if (local_8 == *(uint *)(iVar4 + 0xc)) {
        return 0;
      }
    }
    local_8 = 0;
    if (*(int *)(iVar4 + 0xc) != 0) {
      do {
        iVar1 = *(int *)(*(int *)(param_1 + 0x14) +
                        *(int *)(*(int *)(iVar4 + 0x10) + local_8 * 4) * 4);
        if ((*(uint *)(iVar1 + 0x18) & 0xe000000) == 0) {
          *(uint *)(iVar1 + 0x18) =
               *(uint *)(*(int *)(*(int *)(param_1 + 0x14) +
                                 *(int *)(*(int *)(iVar4 + 8) + local_8 * 4) * 4) + 0x18) &
               0xe000000 | *(uint *)(iVar1 + 0x18);
        }
        local_8 = local_8 + 1;
        iVar4 = *(int *)(param_1 + 0x98);
      } while (local_8 < *(uint *)(iVar4 + 0xc));
    }
    uVar6 = 1;
  }
  uVar6 = FUN_0061aea7(uVar6);
  return uVar6;
}


// ==== 0x61b1e6 FUN_0061b1e6

void __fastcall FUN_0061b1e6(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x98);
  FUN_0061af1a(6,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 8),
               *(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 4),0,0);
  return;
}


// ==== 0x61b204 FUN_0061b204

void FUN_0061b204(void)

{
  FUN_0061aea7(0x13);
  return;
}


// ==== 0x61b20c FUN_0061b20c

void __fastcall FUN_0061b20c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x98);
  FUN_0061af1a(0xe,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 8),
               *(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 4),0,0);
  return;
}


// ==== 0x61b22a FUN_0061b22a

void __fastcall FUN_0061b22a(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x98);
  FUN_0061af1a(0xf,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 8),
               *(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 4),0,0);
  return;
}


// ==== 0x61b248 FUN_0061b248

int __fastcall FUN_0061b248(int *param_1)

{
  int iVar1;
  undefined1 local_14 [16];
  
  iVar1 = (**(code **)(*param_1 + 0x6c))
                    (param_1[0x25],local_14,*(undefined4 *)(param_1[0x26] + 0xc),0,0);
  if (-1 < iVar1) {
    iVar1 = param_1[0x26];
    iVar1 = FUN_0061af1a(7,local_14,*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc),
                         *(undefined4 *)(iVar1 + 4),0,0);
    if (-1 < iVar1) {
      iVar1 = param_1[0x26];
      iVar1 = FUN_0061a3fb(5,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0xc),local_14,
                           *(undefined4 *)(iVar1 + 8),0,*(undefined4 *)(iVar1 + 0xc),0,0,0);
      if (-1 < iVar1) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


// ==== 0x61b2c2 FUN_0061b2c2

void FUN_0061b2c2(void)

{
  FUN_0061aea7(10);
  return;
}


// ==== 0x61b2ca FUN_0061b2ca

void FUN_0061b2ca(void)

{
  FUN_0061aea7(0xb);
  return;
}


// ==== 0x61b2d2 FUN_0061b2d2

void FUN_0061b2d2(void)

{
  FUN_0061aea7(0xc);
  return;
}


// ==== 0x61b2da FUN_0061b2da

void FUN_0061b2da(void)

{
  FUN_0061aea7(0xd);
  return;
}


// ==== 0x61b2e2 FUN_0061b2e2

void FUN_0061b2e2(void)

{
  FUN_0061aea7(2);
  return;
}


// ==== 0x61b2ea FUN_0061b2ea

void FUN_0061b2ea(void)

{
  FUN_0061aea7(5);
  return;
}


// ==== 0x61b2f2 FUN_0061b2f2

void FUN_0061b2f2(void)

{
  FUN_0061aea7(0x11);
  return;
}


// ==== 0x61b2fa FUN_0061b2fa

int __fastcall FUN_0061b2fa(int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int *local_c;
  int *local_8;
  
  uVar1 = *(uint *)param_1[0x26] & 0xffffff;
  local_c = param_1;
  local_8 = param_1;
  if (uVar1 == 1) {
    uVar3 = 5;
  }
  else if (uVar1 == 3) {
    uVar3 = 8;
  }
  else {
    if (uVar1 != 4) {
      iVar2 = (**(code **)(*param_1 + 0x6c))(param_1[0x25],&local_c,2,0,0);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = FUN_0061a3fb(5,&local_c,2,*(int *)(param_1[0x26] + 8),*(int *)(param_1[0x26] + 8) + 8,
                           0,2,0,0,0);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = FUN_0061a3fb(2,*(undefined4 *)(param_1[0x26] + 0x10),
                           *(undefined4 *)(param_1[0x26] + 0xc),&local_c,&local_8,0,1,0,0,0);
      if (iVar2 < 0) {
        return iVar2;
      }
      return 0;
    }
    uVar3 = 9;
  }
  iVar2 = FUN_0061aea7(uVar3);
  return iVar2;
}


// ==== 0x61b39c FUN_0061b39c

void FUN_0061b39c(void)

{
  FUN_0061aea7(0x10);
  return;
}


// ==== 0x61b3a4 FUN_0061b3a4

void FUN_0061b3a4(void)

{
  FUN_0061aea7(0x58);
  return;
}


// ==== 0x61b3ac FUN_0061b3ac

void FUN_0061b3ac(void)

{
  FUN_0061aea7(0x23);
  return;
}


// ==== 0x61b3b4 FUN_0061b3b4

void __fastcall FUN_0061b3b4(int param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  
  puVar1 = *(uint **)(param_1 + 0x98);
  if ((*puVar1 & 0xff000000) == 0xf4000000) {
    uVar2 = 0x1000000;
  }
  else {
    uVar2 = 0;
  }
  FUN_0061af1a(7,puVar1[4],puVar1[2],puVar1[3],puVar1[1],uVar2,0);
  return;
}


// ==== 0x61b3ea FUN_0061b3ea

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0061b3ea(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  uint uVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  
  fVar6 = (float)(*param_1 & _DAT_006df7e0);
  fVar10 = (float)(param_1[1] & uRam006df7e4);
  fVar14 = (float)(param_1[2] & uRam006df7e8);
  fVar18 = (float)(param_1[3] & uRam006df7ec);
  uVar22 = param_1[1] & uRam006df7d4;
  uVar23 = param_1[2] & uRam006df7d8;
  uVar24 = param_1[3] & uRam006df7dc;
  fVar7 = fVar6 * _DAT_006df7c0 + _DAT_006df770;
  fVar11 = fVar10 * fRam006df7c4 + fRam006df774;
  fVar15 = fVar14 * fRam006df7c8 + fRam006df778;
  fVar19 = fVar18 * fRam006df7cc + fRam006df77c;
  fVar8 = fVar7 - _DAT_006df770;
  fVar12 = fVar11 - fRam006df774;
  fVar16 = fVar15 - fRam006df778;
  fVar20 = fVar19 - fRam006df77c;
  fVar6 = (((fVar6 - _DAT_006df7b0 * fVar8) - _DAT_006df7a0 * fVar8) - _DAT_006df790 * fVar8) -
          _DAT_006df780 * fVar8;
  fVar8 = (((fVar10 - fRam006df7b4 * fVar12) - fRam006df7a4 * fVar12) - fRam006df794 * fVar12) -
          fRam006df784 * fVar12;
  fVar10 = (((fVar14 - fRam006df7b8 * fVar16) - fRam006df7a8 * fVar16) - fRam006df798 * fVar16) -
           fRam006df788 * fVar16;
  fVar12 = (((fVar18 - fRam006df7bc * fVar20) - fRam006df7ac * fVar20) - fRam006df79c * fVar20) -
           fRam006df78c * fVar20;
  fVar14 = fVar6 * fVar6;
  fVar16 = fVar8 * fVar8;
  fVar18 = fVar10 * fVar10;
  fVar20 = fVar12 * fVar12;
  uVar25 = (uint)fVar7 & _DAT_006df740;
  uVar26 = (uint)fVar11 & uRam006df744;
  uVar27 = (uint)fVar15 & uRam006df748;
  uVar28 = (uint)fVar19 & uRam006df74c;
  uVar9 = uVar25 & _DAT_006df730;
  uVar13 = uVar26 & uRam006df734;
  uVar17 = uVar27 & uRam006df738;
  uVar21 = uVar28 & uRam006df73c;
  uVar1 = uVar26 - uVar13 & _DAT_006df720;
  uVar2 = uVar27 - uVar17 & _DAT_006df720;
  uVar3 = uVar28 - uVar21 & _DAT_006df720;
  uVar4 = uVar25 + uVar9 & _DAT_006df720;
  uVar26 = uVar26 + uVar13 & _DAT_006df720;
  uVar27 = uVar27 + uVar17 & _DAT_006df720;
  uVar28 = uVar28 + uVar21 & _DAT_006df720;
  uVar5 = -(uint)((float)(uVar9 << 0x1e) != 0.0);
  uVar13 = -(uint)((float)(uVar13 << 0x1e) != 0.0);
  uVar17 = -(uint)((float)(uVar17 << 0x1e) != 0.0);
  uVar21 = -(uint)((float)(uVar21 << 0x1e) != 0.0);
  fVar6 = (((_DAT_006df760 * fVar14 + _DAT_006df710) * fVar14 + _DAT_006df6f0) * fVar14 +
          _DAT_006df6d0) * fVar6;
  fVar8 = (((fRam006df764 * fVar16 + fRam006df714) * fVar16 + fRam006df6f4) * fVar16 + fRam006df6d4)
          * fVar8;
  fVar10 = (((fRam006df768 * fVar18 + fRam006df718) * fVar18 + fRam006df6f8) * fVar18 + fRam006df6d8
           ) * fVar10;
  fVar12 = (((fRam006df76c * fVar20 + fRam006df71c) * fVar20 + fRam006df6fc) * fVar20 + fRam006df6dc
           ) * fVar12;
  fVar7 = (((_DAT_006df750 * fVar14 + _DAT_006df700) * fVar14 + _DAT_006df6e0) * fVar14 +
          _DAT_006df6c0) * fVar14 + _DAT_006df6b0;
  fVar11 = (((fRam006df754 * fVar16 + fRam006df704) * fVar16 + fRam006df6e4) * fVar16 + fRam006df6c4
           ) * fVar16 + fRam006df6b4;
  fVar14 = (((fRam006df758 * fVar18 + fRam006df708) * fVar18 + fRam006df6e8) * fVar18 + fRam006df6c8
           ) * fVar18 + fRam006df6b8;
  fVar15 = (((fRam006df75c * fVar20 + fRam006df70c) * fVar20 + fRam006df6ec) * fVar20 + fRam006df6cc
           ) * fVar20 + fRam006df6bc;
  *param_2 = (~uVar5 & (uint)fVar6 | uVar5 & (uint)fVar7) ^
             (uVar25 - uVar9 & _DAT_006df720) << 0x1e ^ *param_1 & _DAT_006df7d0;
  param_2[1] = (~uVar13 & (uint)fVar8 | uVar13 & (uint)fVar11) ^ uVar1 << 0x1e ^ uVar22;
  param_2[2] = (~uVar17 & (uint)fVar10 | uVar17 & (uint)fVar14) ^ uVar2 << 0x1e ^ uVar23;
  param_2[3] = (~uVar21 & (uint)fVar12 | uVar21 & (uint)fVar15) ^ uVar3 << 0x1e ^ uVar24;
  *param_3 = (uVar5 & (uint)fVar6 | ~uVar5 & (uint)fVar7) ^ uVar4 << 0x1e;
  param_3[1] = (uVar13 & (uint)fVar8 | ~uVar13 & (uint)fVar11) ^ uVar26 << 0x1e;
  param_3[2] = (uVar17 & (uint)fVar10 | ~uVar17 & (uint)fVar14) ^ uVar27 << 0x1e;
  param_3[3] = (uVar21 & (uint)fVar12 | ~uVar21 & (uint)fVar15) ^ uVar28 << 0x1e;
  return;
}


// ==== 0x61b5d3 FUN_0061b5d3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0061b5d3(uint *param_1,uint *param_2,uint *param_3)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  float fVar10;
  float fVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  float fVar16;
  float fVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  float fVar25;
  float fVar26;
  uint uVar27;
  uint uVar28;
  
  fVar16 = (float)(*param_1 & _DAT_006df920);
  fVar17 = (float)(param_1[1] & uRam006df924);
  fVar25 = (float)(param_1[2] & uRam006df928);
  fVar26 = (float)(param_1[3] & uRam006df92c);
  uVar13 = param_1[1] & uRam006df914;
  uVar14 = param_1[2] & uRam006df918;
  uVar15 = param_1[3] & uRam006df91c;
  fVar1 = fVar16 * _DAT_006df900 + _DAT_006df8b0;
  fVar4 = fVar17 * fRam006df904 + fRam006df8b4;
  fVar7 = fVar25 * fRam006df908 + fRam006df8b8;
  fVar10 = fVar26 * fRam006df90c + fRam006df8bc;
  fVar2 = fVar1 - _DAT_006df8b0;
  fVar5 = fVar4 - fRam006df8b4;
  fVar8 = fVar7 - fRam006df8b8;
  fVar11 = fVar10 - fRam006df8bc;
  fVar16 = (((fVar16 - _DAT_006df8f0 * fVar2) - _DAT_006df8e0 * fVar2) - _DAT_006df8d0 * fVar2) -
           _DAT_006df8c0 * fVar2;
  fVar2 = (((fVar17 - fRam006df8f4 * fVar5) - fRam006df8e4 * fVar5) - fRam006df8d4 * fVar5) -
          fRam006df8c4 * fVar5;
  fVar17 = (((fVar25 - fRam006df8f8 * fVar8) - fRam006df8e8 * fVar8) - fRam006df8d8 * fVar8) -
           fRam006df8c8 * fVar8;
  fVar5 = (((fVar26 - fRam006df8fc * fVar11) - fRam006df8ec * fVar11) - fRam006df8dc * fVar11) -
          fRam006df8cc * fVar11;
  fVar25 = fVar16 * fVar16;
  fVar8 = fVar2 * fVar2;
  fVar26 = fVar17 * fVar17;
  fVar11 = fVar5 * fVar5;
  uVar18 = (uint)fVar1 & _DAT_006df880;
  uVar19 = (uint)fVar4 & uRam006df884;
  uVar21 = (uint)fVar7 & uRam006df888;
  uVar23 = (uint)fVar10 & uRam006df88c;
  uVar3 = uVar18 & _DAT_006df870;
  uVar6 = uVar19 & uRam006df874;
  uVar9 = uVar21 & uRam006df878;
  uVar12 = uVar23 & uRam006df87c;
  uVar20 = uVar19 - uVar6 & uRam006df864;
  uVar22 = uVar21 - uVar9 & uRam006df868;
  uVar24 = uVar23 - uVar12 & uRam006df86c;
  uVar27 = uVar18 + uVar3 & _DAT_006df860;
  uVar28 = uVar19 + uVar6 & uRam006df864;
  uVar21 = uVar21 + uVar9 & uRam006df868;
  uVar23 = uVar23 + uVar12 & uRam006df86c;
  uVar19 = -(uint)((float)(uVar3 << 0x1e) != 0.0);
  uVar6 = -(uint)((float)(uVar6 << 0x1e) != 0.0);
  uVar9 = -(uint)((float)(uVar9 << 0x1e) != 0.0);
  uVar12 = -(uint)((float)(uVar12 << 0x1e) != 0.0);
  fVar16 = (((_DAT_006df8a0 * fVar25 + _DAT_006df850) * fVar25 + _DAT_006df830) * fVar25 +
           _DAT_006df810) * fVar16;
  fVar2 = (((fRam006df8a4 * fVar8 + fRam006df854) * fVar8 + fRam006df834) * fVar8 + fRam006df814) *
          fVar2;
  fVar17 = (((fRam006df8a8 * fVar26 + fRam006df858) * fVar26 + fRam006df838) * fVar26 + fRam006df818
           ) * fVar17;
  fVar5 = (((fRam006df8ac * fVar11 + fRam006df85c) * fVar11 + fRam006df83c) * fVar11 + fRam006df81c)
          * fVar5;
  fVar1 = (((_DAT_006df890 * fVar25 + _DAT_006df840) * fVar25 + _DAT_006df820) * fVar25 +
          _DAT_006df800) * fVar25 + _DAT_006df7f0;
  fVar4 = (((fRam006df894 * fVar8 + fRam006df844) * fVar8 + fRam006df824) * fVar8 + fRam006df804) *
          fVar8 + fRam006df7f4;
  fVar25 = (((fRam006df898 * fVar26 + fRam006df848) * fVar26 + fRam006df828) * fVar26 + fRam006df808
           ) * fVar26 + fRam006df7f8;
  fVar7 = (((fRam006df89c * fVar11 + fRam006df84c) * fVar11 + fRam006df82c) * fVar11 + fRam006df80c)
          * fVar11 + fRam006df7fc;
  *param_2 = (~uVar19 & (uint)fVar16 | uVar19 & (uint)fVar1) ^
             (uVar18 - uVar3 & _DAT_006df860) << 0x1e ^ *param_1 & _DAT_006df910;
  param_2[1] = (~uVar6 & (uint)fVar2 | uVar6 & (uint)fVar4) ^ uVar20 << 0x1e ^ uVar13;
  param_2[2] = (~uVar9 & (uint)fVar17 | uVar9 & (uint)fVar25) ^ uVar22 << 0x1e ^ uVar14;
  param_2[3] = (~uVar12 & (uint)fVar5 | uVar12 & (uint)fVar7) ^ uVar24 << 0x1e ^ uVar15;
  *param_3 = (uVar19 & (uint)fVar16 | ~uVar19 & (uint)fVar1) ^ uVar27 << 0x1e;
  param_3[1] = (uVar6 & (uint)fVar2 | ~uVar6 & (uint)fVar4) ^ uVar28 << 0x1e;
  param_3[2] = (uVar9 & (uint)fVar17 | ~uVar9 & (uint)fVar25) ^ uVar21 << 0x1e;
  param_3[3] = (uVar12 & (uint)fVar5 | ~uVar12 & (uint)fVar7) ^ uVar23 << 0x1e;
  return;
}


// ==== 0x61b800 FUN_0061b800

ulonglong FUN_0061b800(void)

{
  ulonglong in_MM0;
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong in_MM1;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  
  uVar9 = (DAT_006df9d8 & in_MM0) >> 1 | DAT_006df9d8 & in_MM1;
  uVar3 = in_MM1 & DAT_006df9dc;
  uVar1 = in_MM0 & DAT_006df9dc;
  uVar2 = PackedFloatingMAX(uVar1,uVar3);
  uVar7 = (uint)((int)uVar1 < (int)uVar3) * -0x80000000;
  uVar4 = PackedFloatingMIN(uVar3,uVar1);
  uVar5 = FloatingReciprocalAprox(uVar1,uVar2);
  uVar2 = PackedFloatingReciprocalIter1(uVar2,uVar5);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar5);
  uVar2 = PackedFloatingMUL(uVar2,uVar4);
  uVar4 = PackedFloatingMUL(uVar2,uVar2);
  uVar5 = PackedFloatingADD((ulonglong)DAT_006dfa10,uVar4);
  uVar6 = PackedFloatingMUL((ulonglong)DAT_006dfa1c,uVar4);
  uVar5 = PackedFloatingMUL(uVar5,uVar4);
  uVar6 = PackedFloatingADD(uVar6,(ulonglong)DAT_006dfa18);
  uVar5 = PackedFloatingADD(uVar5,(ulonglong)DAT_006dfa0c);
  uVar6 = PackedFloatingMUL(uVar6,uVar4);
  uVar5 = PackedFloatingMUL(uVar5,uVar4);
  uVar6 = PackedFloatingADD(uVar6,(ulonglong)DAT_006dfa14);
  uVar5 = PackedFloatingADD(uVar5,(ulonglong)DAT_006dfa08);
  uVar4 = PackedFloatingMUL(uVar4,uVar6);
  uVar4 = PackedFloatingMUL(uVar4,uVar2);
  uVar6 = FloatingReciprocalAprox((ulonglong)DAT_006dfa14,uVar5);
  uVar8 = (int)uVar9 << 1;
  uVar5 = PackedFloatingReciprocalIter1(uVar5,uVar6);
  uVar5 = PackedFloatingReciprocalIter2(uVar5,uVar6);
  uVar4 = PackedFloatingMUL(uVar4,uVar5);
  uVar1 = PackedFloatingADD(uVar4,uVar2);
  uVar2 = PackedFloatingSUB(~(ulonglong)(uint)((int)uVar7 >> 0x1f) &
                            (ulonglong)(uVar8 ^ DAT_006dfa38),(ulonglong)DAT_006dfa38);
  uVar1 = PackedFloatingADD(uVar1 | uVar8 ^ uVar7,uVar2);
  return uVar1 | DAT_006df9d8 & uVar9;
}


// ==== 0x61b900 FUN_0061b900

ulonglong FUN_0061b900(void)

{
  uint uVar1;
  ulonglong in_MM0;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  ulonglong uVar5;
  
  uVar2 = in_MM0 & DAT_006df9dc;
  uVar6 = -(uint)(DAT_006df9e8 < (int)uVar2);
  uVar3 = PackedFloatingMUL(uVar2,(ulonglong)DAT_006df9ec);
  uVar3 = PackedFloatingSUBR(uVar3,(ulonglong)DAT_006df9ec);
  uVar7 = PackedFloatingReciprocalSQRAprox((ulonglong)DAT_006df9dc,uVar3);
  uVar8 = PackedFloatingMUL(uVar7,uVar7);
  uVar1 = (uint)((int)uVar2 < DAT_006dfa20);
  uVar4 = -uVar1;
  uVar5 = (ulonglong)uVar4;
  uVar8 = PackedFloatingReciprocalSQRIter1(uVar8,uVar3);
  uVar7 = PackedFloatingReciprocalIter2(uVar8,uVar7);
  uVar9 = PackedFloatingMUL(uVar7,uVar3);
  uVar2 = ~uVar5 & uVar9 | uVar2 & uVar4;
  uVar3 = PackedFloatingMUL(uVar2,uVar2);
  uVar8 = PackedFloatingMUL((ulonglong)DAT_006dfa28,uVar3);
  uVar7 = PackedFloatingADD((ulonglong)DAT_006dfa30,uVar3);
  uVar8 = PackedFloatingADD(uVar8,(ulonglong)DAT_006dfa24);
  uVar8 = PackedFloatingMUL(uVar8,uVar3);
  uVar3 = PackedFloatingMUL(uVar3,uVar7);
  uVar3 = PackedFloatingADD(uVar3,(ulonglong)DAT_006dfa2c);
  uVar8 = PackedFloatingMUL(uVar8,uVar2);
  uVar7 = FloatingReciprocalAprox(uVar7,uVar3);
  uVar3 = PackedFloatingReciprocalIter1(uVar3,uVar7);
  uVar3 = PackedFloatingReciprocalIter2(uVar3,uVar7);
  uVar3 = PackedFloatingMUL(uVar3,uVar8);
  uVar2 = PackedFloatingADD(uVar2,uVar3);
  uVar3 = PackedFloatingADD(~uVar5 & (ulonglong)DAT_006dfa38 ^ DAT_006df9d8 & in_MM0,
                            (ulonglong)DAT_006dfa34);
  uVar2 = PackedFloatingADD(uVar2,~uVar5 & uVar2);
  uVar2 = PackedFloatingADD(uVar3,uVar2 | (ulonglong)(uVar1 * -0x80000000) ^ DAT_006df9d8 & in_MM0);
  return (ulonglong)(DAT_006df9f4 & uVar6) | ~(ulonglong)uVar6 & uVar2;
}


// ==== 0x61bee0 FUN_0061bee0

uint FUN_0061bee0(void)

{
  ulonglong in_MM0;
  undefined8 uVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  uVar1 = PackedFloatingMUL(in_MM0 & DAT_006df9dc,(ulonglong)DAT_006dfa90);
  uVar2 = PackedFloatingToIntDwordConv(uVar1,uVar1);
  uVar1 = PackedIntToFloatingDwordConv(uVar2,uVar2);
  uVar1 = PackedFloatingMUL(CONCAT44((int)uVar1,(int)uVar1),DAT_006df9a0);
  uVar4 = PackedFloatingADD(in_MM0 & DAT_006df9dc,uVar1);
  uVar3 = (undefined4)((ulonglong)uVar1 >> 0x20);
  uVar1 = PackedFloatingADD(uVar4,CONCAT44(uVar3,uVar3));
  uVar1 = CONCAT44((int)uVar1,(int)uVar1);
  if ((uVar2 & 1) != 0) {
    uVar1 = PackedFloatingSUBR(uVar1,DAT_006df9b0);
  }
  uVar4 = PackedFloatingMUL(uVar1,uVar1);
  uVar6 = PackedFloatingMUL(DAT_006df9a8,uVar4);
  uVar5 = PackedFloatingMUL(DAT_006df9b8,uVar4);
  uVar7 = PackedFloatingADD(uVar6,DAT_006df958);
  uVar6 = PackedFloatingMUL(DAT_006df9c0,uVar4);
  uVar5 = PackedFloatingMUL(uVar7,uVar5);
  uVar7 = PackedFloatingADD(uVar5,DAT_006df958);
  uVar5 = PackedFloatingMUL(DAT_006df9c8,uVar4);
  uVar4 = PackedFloatingMUL(uVar6,uVar7);
  uVar4 = PackedFloatingADD(uVar4,DAT_006df958);
  uVar4 = PackedFloatingMUL(uVar4,CONCAT44((int)DAT_006df958,(int)uVar5));
  uVar4 = PackedFloatingADD(uVar4,DAT_006df958 >> 0x20);
  PackedFloatingMUL(uVar4,CONCAT44((int)uVar1,(int)DAT_006df958));
  return (uint)in_MM0 ^ (uint)in_MM0 & 0x80000000;
}


// ==== 0x61bfe0 FUN_0061bfe0

uint FUN_0061bfe0(void)

{
  ulonglong in_MM0;
  undefined8 uVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  uVar1 = PackedFloatingMUL(in_MM0 & DAT_006df9dc,(ulonglong)DAT_006dfa90);
  uVar2 = PackedFloatingToIntDwordConv(uVar1,uVar1);
  uVar1 = PackedIntToFloatingDwordConv(uVar2,uVar2);
  uVar1 = PackedFloatingMUL(CONCAT44((int)uVar1,(int)uVar1),DAT_006df9a0);
  uVar4 = PackedFloatingADD(in_MM0 & DAT_006df9dc,uVar1);
  uVar3 = (undefined4)((ulonglong)uVar1 >> 0x20);
  uVar1 = PackedFloatingADD(uVar4,CONCAT44(uVar3,uVar3));
  uVar1 = CONCAT44((int)uVar1,(int)uVar1);
  if ((uVar2 & 1) != 0) {
    uVar1 = PackedFloatingSUBR(uVar1,DAT_006df9b0);
  }
  uVar4 = PackedFloatingMUL(uVar1,uVar1);
  uVar6 = PackedFloatingMUL(DAT_006df9a8,uVar4);
  uVar5 = PackedFloatingMUL(DAT_006df9b8,uVar4);
  uVar7 = PackedFloatingADD(uVar6,DAT_006df958);
  uVar6 = PackedFloatingMUL(DAT_006df9c0,uVar4);
  uVar5 = PackedFloatingMUL(uVar7,uVar5);
  uVar7 = PackedFloatingADD(uVar5,DAT_006df958);
  uVar5 = PackedFloatingMUL(DAT_006df9c8,uVar4);
  uVar4 = PackedFloatingMUL(uVar6,uVar7);
  uVar4 = PackedFloatingADD(uVar4,DAT_006df958);
  uVar4 = PackedFloatingMUL(uVar4,CONCAT44((int)DAT_006df958,(int)uVar5));
  uVar4 = PackedFloatingADD(uVar4,DAT_006df958 >> 0x20);
  PackedFloatingMUL(uVar4,CONCAT44((int)uVar1,(int)DAT_006df958));
  return (uint)in_MM0 ^ (uint)in_MM0 & 0x80000000;
}


// ==== 0x61c398 FUN_0061c398

undefined4 __fastcall FUN_0061c398(undefined4 param_1)

{
  return param_1;
}


// ==== 0x61c39b FUN_0061c39b

void __thiscall
FUN_0061c39b(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            uint param_5)

{
  if (4 < param_5) {
    param_5 = 4;
  }
  param_1[6] = 0xffffffff;
  param_1[9] = 0xffffffff;
  param_1[10] = 0xffffffff;
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[3] = param_5;
  param_1[2] = param_4;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  return;
}


// ==== 0x61c3e1 FUN_0061c3e1

undefined4 __thiscall FUN_0061c3e1(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
    param_1[4] = param_2[4];
    param_1[5] = param_2[5];
    param_1[6] = param_2[6];
    param_1[7] = param_2[7];
    param_1[8] = param_2[8];
    param_1[9] = param_2[9];
    param_1[10] = param_2[10];
    param_1[0xb] = param_2[0xb];
    param_1[0xc] = param_2[0xc];
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x61c450 FUN_0061c450

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0061d4c1) */
/* WARNING: Removing unreachable block (ram,0x0061d502) */
/* WARNING: Removing unreachable block (ram,0x0061d571) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0061c450(char *param_1,char *param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  char cVar5;
  byte bVar11;
  char *in_EAX;
  char *pcVar6;
  char *pcVar7;
  undefined3 uVar12;
  int *piVar8;
  char *pcVar9;
  undefined1 *puVar10;
  char cVar13;
  char cVar14;
  uint extraout_ECX;
  byte bVar15;
  char cVar17;
  int iVar16;
  char cVar18;
  char *unaff_EBX;
  char *unaff_EBP;
  char *unaff_ESI;
  char *unaff_EDI;
  char *pcVar19;
  ushort in_CS;
  bool bVar20;
  ulonglong uVar21;
  
  cVar14 = (char)((uint)param_1 >> 8);
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  cVar4 = (char)in_EAX;
  *in_EAX = *in_EAX + cVar4;
  *in_EAX = *in_EAX + cVar4;
  cVar13 = (char)param_1;
  *(char *)((int)in_EAX * 2) = *(char *)((int)in_EAX * 2) + cVar13;
  *in_EAX = *in_EAX + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar4;
  *in_EAX = *in_EAX + cVar4;
  param_1[(int)in_EAX] = param_1[(int)in_EAX] + cVar13;
  *in_EAX = *in_EAX + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar4;
  *in_EAX = *in_EAX + cVar4;
  param_2[(int)in_EAX] = param_2[(int)in_EAX] + cVar13;
  *in_EAX = *in_EAX + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar4;
  *in_EAX = *in_EAX + cVar4;
  unaff_EBX[(int)in_EAX] = unaff_EBX[(int)in_EAX] + cVar13;
  *in_EAX = *in_EAX + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)in_EAX * 2) = *(char *)((int)in_EAX * 2) + cVar4;
  *in_EAX = *in_EAX + cVar4;
  pcVar6 = (char *)((uint)in_EAX | 4);
  *pcVar6 = *pcVar6 + (char)pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  DAT_0c000000 = DAT_0c000000 + (char)pcVar6;
  pcVar6 = pcVar6 + 0x8000;
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar4;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_ESI[(int)pcVar6] = unaff_ESI[(int)pcVar6] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar4;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[(int)pcVar6] = unaff_EDI[(int)pcVar6] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *pcVar6 = *pcVar6 + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6[(int)param_1] = pcVar6[(int)param_1] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  *(char *)((int)param_1 * 2) = *(char *)((int)param_1 * 2) + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  param_2[(int)param_1] = param_2[(int)param_1] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EBX[(int)param_1] = unaff_EBX[(int)param_1] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar7 = (char *)((uint)pcVar6 | 0xc);
  *pcVar7 = *pcVar7 + (char)pcVar7;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  DAT_0c000000 = DAT_0c000000 + cVar13;
  pcVar7 = (char *)((uint)pcVar6 | 0x800c);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_ESI[(int)param_1] = unaff_ESI[(int)param_1] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[(int)param_1] = unaff_EDI[(int)param_1] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  bVar15 = (byte)param_2;
  *pcVar7 = *pcVar7 + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7[(int)param_2] = pcVar7[(int)param_2] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  param_1[(int)param_2] = param_1[(int)param_2] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  *(char *)((int)param_2 * 2) = *(char *)((int)param_2 * 2) + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EBX[(int)param_2] = unaff_EBX[(int)param_2] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar7 * 2) = *(char *)((int)pcVar7 * 2) + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar6 = (char *)((uint)pcVar6 | 0x801c);
  *pcVar6 = *pcVar6 + (char)pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  bVar20 = CARRY1(DAT_0c000000,bVar15);
  DAT_0c000000 = DAT_0c000000 + bVar15;
  pcVar6 = pcVar6 + bVar20 + 0x8000;
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + bVar15;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_ESI[(int)param_2] = unaff_ESI[(int)param_2] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + bVar15;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[(int)param_2] = unaff_EDI[(int)param_2] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  bVar11 = (byte)unaff_EBX;
  *pcVar6 = *pcVar6 + bVar11;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6[(int)unaff_EBX] = pcVar6[(int)unaff_EBX] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + bVar11;
  *pcVar6 = *pcVar6 + cVar4;
  param_1[(int)unaff_EBX] = param_1[(int)unaff_EBX] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + bVar11;
  *pcVar6 = *pcVar6 + cVar4;
  param_2[(int)unaff_EBX] = param_2[(int)unaff_EBX] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + bVar11;
  *pcVar6 = *pcVar6 + cVar4;
  *(char *)((int)unaff_EBX * 2) = *(char *)((int)unaff_EBX * 2) + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + bVar11;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)((uint)pcVar6 | 0x1c);
  *pcVar6 = *pcVar6 + (char)pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  bVar20 = CARRY1(DAT_0c000000,bVar11);
  DAT_0c000000 = DAT_0c000000 + bVar11;
  pcVar6 = pcVar6 + (-0x8000 - (uint)bVar20);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + bVar11;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_ESI[(int)unaff_EBX] = unaff_ESI[(int)unaff_EBX] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + bVar11;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[(int)unaff_EBX] = unaff_EDI[(int)unaff_EBX] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  cVar5 = (char)((uint)pcVar6 >> 8);
  *pcVar6 = *pcVar6 + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  *pcVar6 = *pcVar6 + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  *param_1 = *param_1 + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  *param_2 = *param_2 + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  *unaff_EBX = *unaff_EBX + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar7 = (char *)((uint)pcVar6 | 0x24);
  *pcVar7 = *pcVar7 + (char)pcVar7;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  DAT_0c000000 = DAT_0c000000 + cVar5;
  pcVar6 = (char *)((uint)pcVar6 & 0x8000);
  *pcVar6 = *pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  cVar4 = (char)((uint)pcVar6 >> 8);
  *unaff_ESI = *unaff_ESI + cVar4;
  *pcVar6 = *pcVar6;
  *unaff_ESI = *unaff_ESI + cVar13;
  *pcVar6 = *pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar4;
  *pcVar6 = *pcVar6;
  *unaff_EDI = *unaff_EDI + cVar13;
  *pcVar6 = *pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *pcVar6 = *pcVar6 + cVar14;
  *pcVar6 = *pcVar6;
  pcVar6[(int)unaff_EBP] = pcVar6[(int)unaff_EBP] + cVar13;
  *pcVar6 = *pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar14;
  *pcVar6 = *pcVar6;
  param_1[(int)unaff_EBP] = param_1[(int)unaff_EBP] + cVar13;
  *pcVar6 = *pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar14;
  *pcVar6 = *pcVar6;
  param_2[(int)unaff_EBP] = param_2[(int)unaff_EBP] + cVar13;
  *pcVar6 = *pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar14;
  *pcVar6 = *pcVar6;
  unaff_EBX[(int)unaff_EBP] = unaff_EBX[(int)unaff_EBP] + cVar13;
  *pcVar6 = *pcVar6;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + cVar14;
  *pcVar6 = *pcVar6;
  pcVar6 = (char *)CONCAT31((int3)((uint)pcVar6 >> 8),0x2c);
  *pcVar6 = *pcVar6 + ',';
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  DAT_0c000000 = DAT_0c000000 + cVar14;
  pcVar6 = pcVar6 + -0x8000;
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar14;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_ESI[(int)unaff_EBP] = unaff_ESI[(int)unaff_EBP] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar14;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[(int)unaff_EBP] = unaff_EDI[(int)unaff_EBP] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  cVar17 = (char)((uint)param_2 >> 8);
  *pcVar6 = *pcVar6 + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6[(int)unaff_ESI] = pcVar6[(int)unaff_ESI] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  param_1[(int)unaff_ESI] = param_1[(int)unaff_ESI] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  param_2[(int)unaff_ESI] = param_2[(int)unaff_ESI] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EBX[(int)unaff_ESI] = unaff_EBX[(int)unaff_ESI] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)((uint)pcVar6 | 0x34);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  DAT_0c000000 = DAT_0c000000 + cVar17;
  pcVar6 = (char *)((uint)pcVar6 ^ 0x8000);
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  *(char *)((int)unaff_ESI * 2) = *(char *)((int)unaff_ESI * 2) + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[(int)unaff_ESI] = unaff_EDI[(int)unaff_ESI] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  cVar18 = (char)((uint)unaff_EBX >> 8);
  *pcVar6 = *pcVar6 + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6[(int)unaff_EDI] = pcVar6[(int)unaff_EDI] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  param_1[(int)unaff_EDI] = param_1[(int)unaff_EDI] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  param_2[(int)unaff_EDI] = param_2[(int)unaff_EDI] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EBX[(int)unaff_EDI] = unaff_EBX[(int)unaff_EDI] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  uVar12 = (undefined3)((uint)pcVar6 >> 8);
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x3c);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  DAT_0c000000 = DAT_0c000000 + cVar18;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar18;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_ESI[(int)unaff_EDI] = unaff_ESI[(int)unaff_EDI] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar18;
  *pcVar7 = *pcVar7 + cVar4;
  *(char *)((int)unaff_EDI * 2) = *(char *)((int)unaff_EDI * 2) + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *pcVar7 = *pcVar7 + cVar4;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x40);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar4;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x41);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar4;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x42);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar4;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x43);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar7 * 2) = *(char *)((int)pcVar7 * 2) + cVar4;
  (&stack0x00000000)[(int)pcVar7 * 2] = (&stack0x00000000)[(int)pcVar7 * 2] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBP = *unaff_EBP + cVar4;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x45);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar4;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x46);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar4;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x47);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *pcVar7 = *pcVar7 + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x48);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x49);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x4a);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x4b);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar7 * 2) = *(char *)((int)pcVar7 * 2) + cVar13;
  (&stack0x00000000)[(int)param_1 * 2] = (&stack0x00000000)[(int)param_1 * 2] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBP = *unaff_EBP + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x4d);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x4e);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x4f);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *pcVar7 = *pcVar7 + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x50);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x51);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x52);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x53);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar7 * 2) = *(char *)((int)pcVar7 * 2) + bVar15;
  (&stack0x00000000)[(int)param_2 * 2] = (&stack0x00000000)[(int)param_2 * 2] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBP = *unaff_EBP + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x55);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x56);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + bVar15;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x57);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *pcVar7 = *pcVar7 + bVar11;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x58);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + bVar11;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x59);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + bVar11;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x5a);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + bVar11;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x5b);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar7 * 2) = *(char *)((int)pcVar7 * 2) + bVar11;
  (&stack0x00000000)[(int)unaff_EBX * 2] = (&stack0x00000000)[(int)unaff_EBX * 2] + cVar13;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBP = *unaff_EBP + bVar11;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x5d);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + bVar11;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x5e);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + bVar11;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar7 = (char *)(CONCAT31(uVar12,cVar4) | 0x5f);
  cVar4 = (char)pcVar7;
  *pcVar7 = *pcVar7 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  cVar5 = (char)((uint)pcVar6 >> 8);
  *pcVar7 = *pcVar7 + cVar5;
  *pcVar7 = *pcVar7 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x60);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x61);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x62);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 99);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBP = *unaff_EBP + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x65);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x66);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar5;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x67);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *pcVar6 = *pcVar6 + cVar14;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x68);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar14;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x69);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar14;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x6a);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar14;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x6b);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + cVar14;
  (&stack0x00000000)[(int)unaff_EBP * 2] = (&stack0x00000000)[(int)unaff_EBP * 2] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBP = *unaff_EBP + cVar14;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x6d);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar14;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x6e);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar14;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x6f);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *pcVar6 = *pcVar6 + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x70);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x71);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x72);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x73);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + cVar17;
  (&stack0x00000000)[(int)unaff_ESI * 2] = (&stack0x00000000)[(int)unaff_ESI * 2] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBP = *unaff_EBP + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x75);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x76);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar17;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x77);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *pcVar6 = *pcVar6 + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x78);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_1 = *param_1 + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x79);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *param_2 = *param_2 + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x7a);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBX = *unaff_EBX + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x7b);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)((int)pcVar6 * 2) = *(char *)((int)pcVar6 * 2) + cVar18;
  (&stack0x00000000)[(int)unaff_EDI * 2] = (&stack0x00000000)[(int)unaff_EDI * 2] + cVar13;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EBP = *unaff_EBP + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x7d);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_ESI = *unaff_ESI + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar6 = (char *)(CONCAT31(uVar12,cVar4) | 0x7e);
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *unaff_EDI = *unaff_EDI + cVar18;
  *pcVar6 = *pcVar6 + cVar4;
  piVar8 = (int *)(CONCAT31(uVar12,cVar4) | 0x7f);
  cVar5 = (char)piVar8;
  *(char *)piVar8 = (char)*piVar8 + cVar5;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  *(char *)(piVar8 + 0x3000000) = (char)piVar8[0x3000000] + cVar5;
  *(char *)piVar8 = (char)*piVar8 + -0x80;
  *(char *)piVar8 = (char)*piVar8 + cVar5;
  *(char *)piVar8 = (char)*piVar8 + cVar5;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  param_1[0xc000000] = param_1[0xc000000] + cVar5;
  *piVar8 = *piVar8 + 0x80;
  *(char *)piVar8 = (char)*piVar8 + cVar5;
  pcVar7 = unaff_ESI + 4;
  out(*(undefined4 *)unaff_ESI,(short)param_2);
  *(char *)piVar8 = (char)*piVar8;
  param_2[(int)piVar8 * 4] = param_2[(int)piVar8 * 4] + cVar13;
  *(char *)piVar8 = (char)*piVar8 + cVar5;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  unaff_EBX[0xc000000] = unaff_EBX[0xc000000] + cVar5;
  *piVar8 = *piVar8 + -0x80;
  *(char *)piVar8 = (char)*piVar8 + cVar5;
  *(char *)piVar8 = (char)*piVar8 + cVar5;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  pcVar6 = (char *)((int)piVar8 * 2 + -0x7bf40000);
  *pcVar6 = *pcVar6 + cVar5;
  *(char *)piVar8 = (char)*piVar8 + cVar5;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  unaff_EBP[0xc000000] = unaff_EBP[0xc000000] + cVar5;
  *(char *)piVar8 = (char)*piVar8;
  *(char *)piVar8 = (char)*piVar8 + cVar5;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  unaff_ESI[0xc000004] = unaff_ESI[0xc000004] + cVar5;
  LOCK();
  cVar4 = (char)*piVar8;
  *(char *)piVar8 = cVar5;
  pcVar9 = (char *)CONCAT31(uVar12,cVar4);
  UNLOCK();
  *pcVar9 = *pcVar9;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  unaff_EDI[0xc000000] = unaff_EDI[0xc000000] + cVar4;
  LOCK();
  pcVar6 = *(char **)pcVar9;
  *(char **)pcVar9 = pcVar9;
  UNLOCK();
  *pcVar6 = *pcVar6;
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  pcVar6[0xc000000] = pcVar6[0xc000000] + cVar13;
  *pcVar6 = cVar4;
  *pcVar6 = *pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  param_1[0xc000000] = param_1[0xc000000] + cVar13;
  *(char **)pcVar6 = pcVar6;
  *pcVar6 = *pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  param_2[0xc000000] = param_2[0xc000000] + cVar13;
  cVar4 = *pcVar6;
  pcVar9 = (char *)CONCAT31((int3)((uint)pcVar6 >> 8),cVar4);
  *pcVar9 = *pcVar9;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  unaff_EBX[0xc000000] = unaff_EBX[0xc000000] + cVar13;
  pcVar9 = *(char **)pcVar9;
  *pcVar9 = *pcVar9;
  cVar4 = (char)pcVar9;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  pcVar6 = (char *)((int)pcVar9 * 2 + -0x73f40000);
  *pcVar6 = *pcVar6 + cVar13;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  unaff_EBP[0xc000000] = unaff_EBP[0xc000000] + cVar13;
  *pcVar9 = *pcVar9;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  unaff_ESI[0xc000004] = unaff_ESI[0xc000004] + cVar13;
  *pcVar9 = *pcVar9;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  unaff_EDI[0xc000000] = unaff_EDI[0xc000000] + cVar13;
  pcVar9[0] = '\0';
  pcVar9[1] = '\0';
  pcVar9[2] = '\0';
  pcVar9[3] = '\0';
  *pcVar9 = *pcVar9;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  pcVar9[0xc000000] = pcVar9[0xc000000] + bVar15;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar14;
  param_1[0xc000000] = param_1[0xc000000] + bVar15;
  *param_1 = *param_1 + cVar13;
  cVar5 = (char)((uint)pcVar9 >> 8);
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar5;
  param_2[0xc000000] = param_2[0xc000000] + bVar15;
  *param_2 = *param_2 + bVar15;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar5;
  unaff_EBX[0xc000000] = unaff_EBX[0xc000000] + cVar13;
  *unaff_EBX = *unaff_EBX + bVar11;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar5;
  pcVar6 = (char *)((int)unaff_EBX * 2 + -0x6bf40000);
  *pcVar6 = *pcVar6 + cVar13;
  *unaff_EBX = *unaff_EBX + bVar11;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar5;
  unaff_EBP[0xc000000] = unaff_EBP[0xc000000] + cVar13;
  *unaff_EBP = *unaff_EBP + (char)unaff_EBP;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar5;
  unaff_ESI[0xc000004] = unaff_ESI[0xc000004] + cVar13;
  *pcVar7 = *pcVar7 + (char)pcVar7;
  unaff_EDI[0x6a] = unaff_EDI[0x6a] + cVar5;
  unaff_EDI[0xc000000] = unaff_EDI[0xc000000] + cVar13;
  cVar4 = (char)unaff_EDI;
  *unaff_EDI = *unaff_EDI + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar5;
  unaff_EDI[0xc000000] = unaff_EDI[0xc000000] + bVar15;
  pcVar6 = (char *)(int)(short)unaff_EDI;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar5;
  pcVar9[0xc000000] = pcVar9[0xc000000] + bVar15;
  *pcVar6 = *pcVar6 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar5;
  pcVar6 = (char *)(((int)pcVar6 >> 0x1f) + 0xc000000);
  *pcVar6 = *pcVar6 + bVar15;
  uVar21 = func_0x00008000();
  iVar16 = (int)(uVar21 >> 0x20);
  pcVar9 = (char *)uVar21;
  cVar13 = (char)(extraout_ECX >> 8);
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  param_2[0xc000000] = param_2[0xc000000] + bVar15;
  cVar4 = (char)uVar21;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  pcVar6 = (char *)((int)pcVar9 * 2 + -0x63f40000);
  *pcVar6 = *pcVar6 + bVar15;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  unaff_EBX[0xc000000] = unaff_EBX[0xc000000] + bVar15;
  bVar20 = (in_CS & 0x400) != 0;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  unaff_EBP[0xc000000] = unaff_EBP[0xc000000] + bVar15;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  pbVar1 = (byte *)(unaff_ESI + 0xc000004);
  bVar11 = *pbVar1;
  *pbVar1 = *pbVar1 + bVar15;
  bVar11 = ((char)*pbVar1 < '\0') << 7 | (*pbVar1 == 0) << 6 |
           ((int)(uVar21 & 0xffff000000001000) != 0) << 4 | ((POPCOUNT(*pbVar1) & 1U) == 0) << 2 |
           2U | CARRY1(bVar11,bVar15);
  pcVar6 = (char *)CONCAT22((short)(uVar21 >> 0x10),CONCAT11(bVar11,cVar4));
  *pcVar6 = *pcVar6 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  pcVar6[0xc000000] = pcVar6[0xc000000] + bVar11;
  pcVar6 = (char *)CONCAT31((int3)((uint)pcVar6 >> 8),SUB_00008000);
  *pcVar6 = *pcVar6 + SUB_00008000;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  *(char *)(extraout_ECX + 0xc000000) = *(char *)(extraout_ECX + 0xc000000) + bVar11;
  pcVar9 = _SUB_00008000;
  cVar4 = (char)_SUB_00008000;
  *_SUB_00008000 = *_SUB_00008000 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  cVar5 = (char)((uint)_SUB_00008000 >> 8);
  *(char *)(iVar16 + 0xc000000) = *(char *)(iVar16 + 0xc000000) + cVar5;
  *_SUB_00008000 = *_SUB_00008000 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  param_2[0xc000000] = param_2[0xc000000] + cVar5;
  *_SUB_00008000 = *_SUB_00008000 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  pcVar6 = (char *)((int)pcVar9 * 2 + -0x5bf40000);
  *pcVar6 = *pcVar6 + cVar5;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_ESI[0x6e] = unaff_ESI[0x6e] + cVar13;
  unaff_EBX[0xc000000] = unaff_EBX[0xc000000] + cVar5;
  *(undefined4 *)pcVar7 = *(undefined4 *)unaff_EBP;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_ESI[(uint)bVar20 * -8 + 0x72] = unaff_ESI[(uint)bVar20 * -8 + 0x72] + cVar13;
  unaff_EBP[(uint)bVar20 * -8 + 0xc000004] = unaff_EBP[(uint)bVar20 * -8 + 0xc000004] + cVar5;
  iVar2 = (uint)bVar20 * -2 + (uint)bVar20 * -8 + 9;
  *pcVar9 = *pcVar9 + cVar4;
  unaff_ESI[iVar2 + 0x6a] = unaff_ESI[iVar2 + 0x6a] + cVar13;
  unaff_ESI[iVar2 + 0xc000000] = unaff_ESI[iVar2 + 0xc000000] + cVar5;
  pcVar6 = unaff_ESI + (uint)bVar20 * -8 + iVar2 + 4;
  pcVar7 = unaff_EBP + (uint)bVar20 * -8 + (uint)bVar20 * -2 + (uint)bVar20 * -8 + 9;
  *pcVar9 = *pcVar9 + cVar4;
  pcVar6[0x6a] = pcVar6[0x6a] + cVar13;
  pcVar9[0xc000000] = pcVar9[0xc000000] + cVar13;
  *pcVar9 = *pcVar9;
  *pcVar9 = *pcVar9 + cVar4;
  pcVar6[0x6a] = pcVar6[0x6a] + cVar13;
  *(char *)(extraout_ECX + 0xc000000) = *(char *)(extraout_ECX + 0xc000000) + cVar13;
  *pcVar9 = *pcVar9 + cVar4;
  pcVar6[0x6a] = pcVar6[0x6a] + cVar13;
  *(char *)(iVar16 + 0xc000000) = *(char *)(iVar16 + 0xc000000) + cVar13;
  pcVar19 = pcVar6 + (uint)bVar20 * -2 + 1;
  *pcVar6 = cVar4;
  *pcVar9 = *pcVar9 + cVar4;
  pcVar19[0x6a] = pcVar19[0x6a] + cVar13;
  param_2[0xc000000] = param_2[0xc000000] + cVar13;
  iVar2 = (uint)bVar20 * -8;
  *(char **)pcVar19 = pcVar9;
  *pcVar9 = *pcVar9 + cVar4;
  pcVar19[iVar2 + 0x6e] = pcVar19[iVar2 + 0x6e] + cVar13;
  pcVar6 = (char *)((int)pcVar9 * 2 + -0x53f40000);
  *pcVar6 = *pcVar6 + cVar13;
  *pcVar9 = *pcVar9 + cVar4;
  pcVar19[iVar2 + 0x6e] = pcVar19[iVar2 + 0x6e] + cVar13;
  unaff_EBX[0xc000000] = unaff_EBX[0xc000000] + cVar13;
  iVar3 = (uint)bVar20 * -8;
  pcVar6 = *(char **)pcVar7;
  cVar4 = (char)pcVar6;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar19[iVar2 + 0x6e] = pcVar19[iVar2 + 0x6e] + cVar13;
  pcVar7[iVar3 + 0xc000004] = pcVar7[iVar3 + 0xc000004] + cVar13;
  iVar2 = (uint)bVar20 * -2 + iVar2 + 5;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + cVar13;
  pcVar19[iVar2 + 0xc000000] = pcVar19[iVar2 + 0xc000000] + cVar13;
  iVar2 = (uint)bVar20 * -8 + iVar2 + 4;
  *pcVar6 = *pcVar6 + cVar4;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + cVar13;
  cVar4 = (char)(uVar21 >> 0x28);
  pcVar6[0xc000000] = pcVar6[0xc000000] + cVar4;
  puVar10 = (undefined1 *)(((uint)pcVar6 >> 8) * 0x100);
  *puVar10 = *puVar10;
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + cVar13;
  *(char *)(extraout_ECX + 0xc000000) = *(char *)(extraout_ECX + 0xc000000) + cVar4;
  *puVar10 = *puVar10;
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + cVar13;
  *(char *)(iVar16 + 0xc000000) = *(char *)(iVar16 + 0xc000000) + cVar4;
  *puVar10 = *puVar10;
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + cVar13;
  param_2[0xc000000] = param_2[0xc000000] + cVar4;
  *puVar10 = *puVar10;
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + cVar13;
  pcVar6 = (char *)(((uint)pcVar6 >> 8) * 0x200 + -0x4bf40000);
  *pcVar6 = *pcVar6 + cVar4;
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + cVar13;
  unaff_EBX[0xc000000] = unaff_EBX[0xc000000] + cVar4;
  *puVar10 = *puVar10;
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a];
  pcVar7[iVar3 + 0xc000004] = pcVar7[iVar3 + 0xc000004] + cVar4;
  *puVar10 = *puVar10;
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a];
  pcVar19[iVar2 + 0xc000000] = pcVar19[iVar2 + 0xc000000];
  *puVar10 = *puVar10;
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a];
  puVar10[0xc000000] = puVar10[0xc000000];
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a];
  puVar10 = (undefined1 *)((extraout_ECX & 0xffff0000) + 0xc000000);
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + -0x80;
  puVar10 = (undefined1 *)((int)((uVar21 & 0xffff000000001000) >> 0x20) + 0xc000000);
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + -0x80;
  puVar10 = (undefined1 *)(((uint)param_2 & 0xffff0000) + 0xc000000);
  *puVar10 = *puVar10;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + -0x80;
  cRambc0d0000 = cRambc0d0000 + -0x80;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + -0x80;
  unaff_EBX[0xc000000] = unaff_EBX[0xc000000] + -0x80;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + -0x80;
  pcVar7[iVar3 + 0xc000004] = pcVar7[iVar3 + 0xc000004] + -0x80;
  pcVar19[iVar2 + 0x6a] = pcVar19[iVar2 + 0x6a] + -0x80;
  pcVar19[iVar2 + 0xc000000] = pcVar19[iVar2 + 0xc000000] + -0x80;
  cRam00040080 = cRam00040080 + -0x80;
  cRam00008080 = cRam00008080 + -0x80;
  cRam00048000 = cRam00048000 + -0x80;
  _SUB_00008000 = (char *)CONCAT31(SUB_00008000_1,SUB_00008000 + -0x80);
  out((int)_SUB_00008000 + 1,0x8000);
  out(*(undefined4 *)((uint)bVar20 * -8 + 0x8004),0x8000);
  _SUB_00008000 = (char *)((int)_SUB_00008000 + 3);
  iVar2 = iRam000080ff + 1;
  iRam000080ff._0_1_ = (char)iVar2;
  iRam000080ff = CONCAT31((int3)((uint)iVar2 >> 8),(char)iRam000080ff + -4);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== 0x61d300 FUN_0061d300

/* WARNING: Control flow encountered bad instruction data */

void __fastcall FUN_0061d300(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  byte bVar4;
  char cVar9;
  char *in_EAX;
  undefined2 uVar11;
  byte *pbVar5;
  int *piVar6;
  char *pcVar7;
  undefined3 uVar10;
  char *pcVar8;
  char cVar12;
  char cVar13;
  byte bVar14;
  undefined2 uVar15;
  char cVar16;
  char cVar17;
  undefined2 uVar18;
  char cVar19;
  char cVar20;
  char cVar21;
  undefined4 unaff_EBX;
  undefined2 uVar22;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  cVar13 = (char)((uint)param_1 >> 8);
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar19 = (char)unaff_EBX + cVar13;
  cVar3 = (char)in_EAX;
  *in_EAX = *in_EAX + cVar3;
  pcVar8 = (char *)(CONCAT31((int3)((uint)unaff_EBX >> 8),cVar19) + unaff_EBP * 8);
  cVar16 = (char)param_1;
  *pcVar8 = *pcVar8 + cVar16;
  *in_EAX = *in_EAX + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  uVar11 = (undefined2)((uint)in_EAX >> 0x10);
  cVar9 = (char)((uint)in_EAX >> 8) + cVar13;
  pcVar7 = (char *)CONCAT22(uVar11,CONCAT11(cVar9,cVar3));
  *pcVar7 = *pcVar7 + cVar3;
  (&stack0x00000000)[unaff_EBP * 8] = (&stack0x00000000)[unaff_EBP * 8] + cVar16;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  uVar15 = (undefined2)((uint)param_1 >> 0x10);
  cVar13 = cVar13 * '\x02';
  *pcVar7 = *pcVar7 + cVar3;
  pcVar8 = (char *)(unaff_EBP * 8 + 0x8000);
  *pcVar8 = *pcVar8 + cVar16;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  uVar18 = (undefined2)((uint)param_2 >> 0x10);
  cVar17 = (char)((uint)param_2 >> 8) + cVar13;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_ESI + unaff_EBP * 2) = *(char *)(unaff_ESI + unaff_EBP * 2) + cVar16;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  uVar22 = (undefined2)((uint)unaff_EBX >> 0x10);
  cVar21 = (char)((uint)unaff_EBX >> 8) + cVar13;
  *pcVar7 = *pcVar7 + cVar3;
  pcVar8 = (char *)(unaff_EDI + unaff_EBP * 8);
  *pcVar8 = *pcVar8 + cVar16;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar3 = cVar3 + cVar17;
  pcVar7 = (char *)CONCAT31((int3)((uint)pcVar7 >> 8),cVar3);
  *pcVar7 = *pcVar7 + cVar3;
  pcVar7[(int)unaff_ESI * 8] = pcVar7[(int)unaff_ESI * 8] + cVar16;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar12 = cVar16 + cVar17;
  *pcVar7 = *pcVar7 + cVar3;
  pcVar8 = (char *)(CONCAT31((int3)(CONCAT22(uVar15,CONCAT11(cVar13,cVar16)) >> 8),cVar12) +
                   (int)unaff_ESI * 8);
  *pcVar8 = *pcVar8 + cVar12;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar16 = (char)param_2 + cVar17;
  *pcVar7 = *pcVar7 + cVar3;
  pcVar8 = (char *)(CONCAT31((int3)(CONCAT22(uVar18,CONCAT11(cVar17,(char)param_2)) >> 8),cVar16) +
                   (int)unaff_ESI * 8);
  *pcVar8 = *pcVar8 + cVar12;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar20 = cVar19 + cVar17;
  *pcVar7 = *pcVar7 + cVar3;
  pcVar8 = (char *)(CONCAT31((int3)(CONCAT22(uVar22,CONCAT11(cVar21,cVar19)) >> 8),cVar20) +
                   (int)unaff_ESI * 8);
  *pcVar8 = *pcVar8 + cVar12;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar9 = cVar9 + cVar17;
  pcVar7 = (char *)CONCAT22(uVar11,CONCAT11(cVar9,cVar3));
  *pcVar7 = *pcVar7 + cVar3;
  (&stack0x00000000)[(int)unaff_ESI * 8] = (&stack0x00000000)[(int)unaff_ESI * 8] + cVar12;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar13 = cVar13 + cVar17;
  *pcVar7 = *pcVar7 + cVar3;
  pcVar8 = (char *)((int)unaff_ESI * 8 + 0x8000);
  *pcVar8 = *pcVar8 + cVar12;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar17 = cVar17 * '\x02';
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)((int)unaff_ESI * 9) = *(char *)((int)unaff_ESI * 9) + cVar12;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar21 = cVar21 + cVar17;
  *pcVar7 = *pcVar7 + cVar3;
  pcVar8 = (char *)(unaff_EDI + (int)unaff_ESI * 8);
  *pcVar8 = *pcVar8 + cVar12;
  *pcVar7 = *pcVar7 + cVar3;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  bVar4 = cVar3 + cVar21;
  pcVar7 = (char *)CONCAT31((int3)((uint)pcVar7 >> 8),bVar4);
  *pcVar7 = *pcVar7 + bVar4;
  pcVar7[unaff_EDI * 8] = pcVar7[unaff_EDI * 8] + cVar12;
  *pcVar7 = *pcVar7 + bVar4;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar3 = cVar12 + cVar21;
  *pcVar7 = *pcVar7 + bVar4;
  pcVar8 = (char *)(CONCAT31((int3)(CONCAT22(uVar15,CONCAT11(cVar13,cVar12)) >> 8),cVar3) +
                   unaff_EDI * 8);
  *pcVar8 = *pcVar8 + cVar3;
  *pcVar7 = *pcVar7 + bVar4;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  cVar12 = cVar16 + cVar21;
  *pcVar7 = *pcVar7 + bVar4;
  pcVar8 = (char *)(CONCAT31((int3)(CONCAT22(uVar18,CONCAT11(cVar17,cVar16)) >> 8),cVar12) +
                   unaff_EDI * 8);
  *pcVar8 = *pcVar8 + cVar3;
  *pcVar7 = *pcVar7 + bVar4;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  *pcVar7 = *pcVar7 + bVar4;
  pcVar8 = (char *)(CONCAT31((int3)(CONCAT22(uVar22,CONCAT11(cVar21,cVar20)) >> 8),cVar20 + cVar21)
                   + unaff_EDI * 8);
  *pcVar8 = *pcVar8 + cVar3;
  *pcVar7 = *pcVar7 + bVar4;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  pbVar5 = (byte *)CONCAT22(uVar11,CONCAT11(cVar9 + cVar21,bVar4));
  *pbVar5 = *pbVar5 + bVar4;
  (&stack0x00000000)[unaff_EDI * 8] = (&stack0x00000000)[unaff_EDI * 8] + cVar3;
  *pbVar5 = *pbVar5 + bVar4;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + cVar13;
  bVar14 = cVar13 + cVar21;
  *pbVar5 = *pbVar5 + bVar4;
  pcVar8 = (char *)(unaff_EDI * 8 + 0x8000);
  *pcVar8 = *pcVar8 + cVar3;
  *pbVar5 = *pbVar5 + bVar4;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + bVar14;
  uVar11 = CONCAT11(cVar17 + cVar21,cVar12);
  *pbVar5 = *pbVar5 + bVar4;
  *(char *)(unaff_ESI + unaff_EDI * 2) = *(char *)(unaff_ESI + unaff_EDI * 2) + cVar3;
  *pbVar5 = *pbVar5 + bVar4;
  *(char *)(unaff_EDI + 0x6a) = *(char *)(unaff_EDI + 0x6a) + bVar14;
  pcVar8 = (char *)CONCAT22(uVar22,CONCAT11(cVar21 * '\x02',cVar20 + cVar21));
  *pbVar5 = *pbVar5 + bVar4;
  *(char *)(unaff_EDI * 9) = *(char *)(unaff_EDI * 9) + cVar3;
  bVar1 = *pbVar5;
  *pbVar5 = *pbVar5 + bVar4;
  uVar10 = (undefined3)((uint)pbVar5 >> 8);
  if (!SCARRY1(bVar1,bVar4)) {
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *(int *)pbVar5 = *(int *)pbVar5 + 1;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    out(*unaff_ESI,uVar11);
    pbVar5 = (byte *)CONCAT31(uVar10,bVar4);
    *pbVar5 = *pbVar5 + bVar4;
    *(int *)pbVar5 = *(int *)pbVar5 + 1;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    out(unaff_ESI[1],uVar11);
    *pbVar5 = *pbVar5 | bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *(int *)pbVar5 = *(int *)pbVar5 + 1;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *(char *)CONCAT31(uVar10,bVar4) = *(char *)CONCAT31(uVar10,bVar4) + bVar4;
    piVar6 = (int *)CONCAT31(uVar10,0xff);
    *piVar6 = *piVar6 + 1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *pbVar5 = *pbVar5 + bVar4;
  *pbVar5 = *pbVar5 + cVar12;
  *pbVar5 = *pbVar5 + bVar4;
  *(char *)(unaff_EDI * 9) = *(char *)(unaff_EDI * 9) + cVar3;
  *(int *)pbVar5 = *(int *)pbVar5 + 1;
  *pbVar5 = *pbVar5 + bVar4;
  bVar1 = *pbVar5;
  *pbVar5 = *pbVar5 + bVar4;
  *(byte **)pbVar5 = pbVar5 + (uint)CARRY1(bVar1,bVar4) + *(int *)pbVar5;
  *pbVar5 = *pbVar5 + bVar4;
  piVar6 = (int *)CONCAT31(uVar10,0xff);
  *piVar6 = *piVar6 + 1;
  *(char *)piVar6 = (char)*piVar6 + -1;
  iVar2 = *piVar6;
  *(char *)piVar6 = (char)*piVar6 + -1;
  cVar13 = (char)*piVar6 + -1 + ((char)iVar2 != '\0');
  pcVar7 = (char *)CONCAT31(uVar10,cVar13);
  *pcVar7 = *pcVar7 + cVar13;
  piVar6 = (int *)CONCAT31(uVar10,0xff);
  *piVar6 = *piVar6 + 1;
  *(char *)piVar6 = (char)*piVar6 + -1;
  iVar2 = *piVar6;
  *(char *)piVar6 = (char)*piVar6 + -1;
  pcVar7 = (char *)((int)piVar6 + (uint)((char)iVar2 != '\0') + *piVar6);
  *pcVar7 = *pcVar7 + (char)pcVar7;
  uVar10 = (undefined3)((uint)pcVar7 >> 8);
  piVar6 = (int *)CONCAT31(uVar10,0xff);
  iVar2 = *piVar6;
  *piVar6 = *piVar6 + 1;
  if (!SCARRY4(iVar2,1)) {
    *(char *)piVar6 = (char)*piVar6 + -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    piVar6[0x40] = piVar6[0x40] + 1;
    out(*unaff_ESI,uVar11);
    *(char *)piVar6 = (char)*piVar6 + -1;
    piVar6[0x40] = piVar6[0x40] + 1;
    out(unaff_ESI[1],uVar11);
    *(char *)piVar6 = -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    piVar6[0x40] = piVar6[0x40] + 1;
    pcVar7 = (char *)((int)piVar6 + 1);
    out(unaff_ESI[2],uVar11);
    cVar13 = (char)pcVar7;
    *pcVar7 = *pcVar7 + cVar13;
    *(int *)((int)piVar6 + 0x101) = *(int *)((int)piVar6 + 0x101) + 1;
    pbVar5 = (byte *)(unaff_EDI * 0x10 + 0x6a);
    *pbVar5 = *pbVar5 ^ bVar14;
    *pcVar7 = *pcVar7 + cVar12;
    *pcVar7 = *pcVar7 + cVar13;
    *pcVar8 = *pcVar8 + cVar13;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  out(*unaff_ESI,uVar11);
  pcVar8 = (char *)CONCAT31(uVar10,0xff);
  *pcVar8 = *pcVar8 + -1;
  *(int *)(pcVar8 + 0x100) = *(int *)(pcVar8 + 0x100) + 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== 0x61d450 FUN_0061d450

/* WARNING: Control flow encountered bad instruction data */

void __fastcall FUN_0061d450(undefined4 param_1,undefined2 param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  char cVar5;
  byte *in_EAX;
  int *piVar6;
  char *pcVar7;
  undefined3 uVar8;
  char *unaff_EBX;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  bool in_OF;
  
  bVar4 = (byte)in_EAX;
  uVar8 = (undefined3)((uint)in_EAX >> 8);
  if (!in_OF) {
    *in_EAX = *in_EAX + bVar4;
    *in_EAX = *in_EAX + bVar4;
    *(int *)in_EAX = *(int *)in_EAX + 1;
    *in_EAX = *in_EAX + bVar4;
    *in_EAX = *in_EAX + bVar4;
    out(*unaff_ESI,param_2);
    *in_EAX = *in_EAX + bVar4;
    *(int *)in_EAX = *(int *)in_EAX + 1;
    *in_EAX = *in_EAX + bVar4;
    *in_EAX = *in_EAX + bVar4;
    out(unaff_ESI[1],param_2);
    *in_EAX = *in_EAX | bVar4;
    *in_EAX = *in_EAX + bVar4;
    *(int *)in_EAX = *(int *)in_EAX + 1;
    *in_EAX = *in_EAX + bVar4;
    *in_EAX = *in_EAX + bVar4;
    *in_EAX = *in_EAX + bVar4;
    piVar6 = (int *)CONCAT31(uVar8,0xff);
    *piVar6 = *piVar6 + 1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *in_EAX = *in_EAX + bVar4;
  *in_EAX = *in_EAX + (char)param_2;
  *in_EAX = *in_EAX + bVar4;
  *(char *)(unaff_EDI * 9) = *(char *)(unaff_EDI * 9) + (char)param_1;
  *(int *)in_EAX = *(int *)in_EAX + 1;
  *in_EAX = *in_EAX + bVar4;
  bVar2 = *in_EAX;
  *in_EAX = *in_EAX + bVar4;
  *(byte **)in_EAX = in_EAX + (uint)CARRY1(bVar2,bVar4) + *(int *)in_EAX;
  *in_EAX = *in_EAX + bVar4;
  piVar6 = (int *)CONCAT31(uVar8,0xff);
  *piVar6 = *piVar6 + 1;
  *(char *)piVar6 = (char)*piVar6 + -1;
  iVar3 = *piVar6;
  *(char *)piVar6 = (char)*piVar6 + -1;
  cVar5 = (char)*piVar6 + -1 + ((char)iVar3 != '\0');
  pcVar7 = (char *)CONCAT31(uVar8,cVar5);
  *pcVar7 = *pcVar7 + cVar5;
  piVar6 = (int *)CONCAT31(uVar8,0xff);
  *piVar6 = *piVar6 + 1;
  *(char *)piVar6 = (char)*piVar6 + -1;
  iVar3 = *piVar6;
  *(char *)piVar6 = (char)*piVar6 + -1;
  pcVar7 = (char *)((int)piVar6 + (uint)((char)iVar3 != '\0') + *piVar6);
  *pcVar7 = *pcVar7 + (char)pcVar7;
  uVar8 = (undefined3)((uint)pcVar7 >> 8);
  piVar6 = (int *)CONCAT31(uVar8,0xff);
  iVar3 = *piVar6;
  *piVar6 = *piVar6 + 1;
  if (!SCARRY4(iVar3,1)) {
    *(char *)piVar6 = (char)*piVar6 + -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    piVar6[0x40] = piVar6[0x40] + 1;
    out(*unaff_ESI,param_2);
    *(char *)piVar6 = (char)*piVar6 + -1;
    piVar6[0x40] = piVar6[0x40] + 1;
    out(unaff_ESI[1],param_2);
    *(char *)piVar6 = -1;
    *(char *)piVar6 = (char)*piVar6 + -1;
    piVar6[0x40] = piVar6[0x40] + 1;
    pcVar7 = (char *)((int)piVar6 + 1);
    out(unaff_ESI[2],param_2);
    cVar5 = (char)pcVar7;
    *pcVar7 = *pcVar7 + cVar5;
    *(int *)((int)piVar6 + 0x101) = *(int *)((int)piVar6 + 0x101) + 1;
    pbVar1 = (byte *)(unaff_EDI * 0x10 + 0x6a);
    *pbVar1 = *pbVar1 ^ (byte)((uint)param_1 >> 8);
    *pcVar7 = *pcVar7 + (char)param_2;
    *pcVar7 = *pcVar7 + cVar5;
    *unaff_EBX = *unaff_EBX + cVar5;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  out(*unaff_ESI,param_2);
  pcVar7 = (char *)CONCAT31(uVar8,0xff);
  *pcVar7 = *pcVar7 + -1;
  *(int *)(pcVar7 + 0x100) = *(int *)(pcVar7 + 0x100) + 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== 0x61d500 FUN_0061d500

/* WARNING: Control flow encountered bad instruction data */

void __fastcall FUN_0061d500(undefined4 param_1,undefined2 param_2)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  byte *in_EAX;
  byte *pbVar4;
  char *pcVar5;
  char *unaff_EBX;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  char in_CF;
  bool in_OF;
  
  bVar2 = (byte)in_EAX;
  if (!in_OF) {
    *in_EAX = *in_EAX + bVar2;
    *in_EAX = *in_EAX + bVar2;
    *(int *)(in_EAX + 0x100) = *(int *)(in_EAX + 0x100) + 1;
    out(*unaff_ESI,param_2);
    *in_EAX = *in_EAX + bVar2;
    *(int *)(in_EAX + 0x100) = *(int *)(in_EAX + 0x100) + 1;
    out(unaff_ESI[1],param_2);
    *in_EAX = *in_EAX | bVar2;
    *in_EAX = *in_EAX + bVar2;
    *(int *)(in_EAX + 0x100) = *(int *)(in_EAX + 0x100) + 1;
    pbVar4 = in_EAX + 1;
    out(unaff_ESI[2],param_2);
    cVar3 = (char)pbVar4;
    *pbVar4 = *pbVar4 + cVar3;
    *(int *)(in_EAX + 0x101) = *(int *)(in_EAX + 0x101) + 1;
    pbVar1 = (byte *)(unaff_EDI * 0x10 + 0x6a);
    *pbVar1 = *pbVar1 ^ (byte)((uint)param_1 >> 8);
    *pbVar4 = *pbVar4 + (char)param_2;
    *pbVar4 = *pbVar4 + cVar3;
    *unaff_EBX = *unaff_EBX + cVar3;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  out(*unaff_ESI,param_2);
  pcVar5 = (char *)CONCAT31((int3)((uint)in_EAX >> 8),bVar2 - in_CF);
  *pcVar5 = *pcVar5 + (bVar2 - in_CF);
  *(int *)(pcVar5 + 0x100) = *(int *)(pcVar5 + 0x100) + 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== 0x61df40 DirectInput8Create

void DirectInput8Create(void)

{
                    /* WARNING: Could not recover jumptable at 0x0061df40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DirectInput8Create();
  return;
}


// ==== 0x61df50 FUN_0061df50

uint __fastcall FUN_0061df50(undefined4 param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  cVar1 = *param_2;
  while (cVar1 != '\0') {
    uVar2 = uVar2 * 0x10 + (int)cVar1;
    param_2 = param_2 + 1;
    uVar3 = uVar2 & 0xf0000000;
    if (uVar3 != 0) {
      uVar2 = uVar2 ^ uVar3 >> 0x18;
    }
    uVar2 = uVar2 & ~uVar3;
    cVar1 = *param_2;
  }
  return uVar2 & 0xff;
}


// ==== 0x61df90 FUN_0061df90

void __fastcall FUN_0061df90(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_1 + 8) != 0) {
    iVar1 = *(int *)(param_1 + 4);
    while (iVar1 = iVar1 + -1, -1 < iVar1) {
      (**(code **)(*(int *)(param_1 + 8) + iVar1 * 8))
                (*(undefined4 *)(*(int *)(param_1 + 8) + 4 + iVar1 * 8));
    }
    (*(code *)PTR_FUN_006dfaa0)(*(undefined4 *)(param_1 + 8),*(int *)(param_1 + 4) << 3);
    *(undefined4 *)(param_1 + 8) = 0;
  }
  puVar3 = *(undefined4 **)(param_1 + 0xc);
  while (puVar3 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)puVar3[3];
    (*(code *)*puVar3)(puVar3[1],puVar3[2]);
    (*(code *)PTR_FUN_006dfaa0)(puVar3,0x10);
    puVar3 = puVar2;
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}


// ==== 0x61e010 EAGL::DynamicLoader::LoadSymbols

/* [canon] render low (hopper+ghidra) docs/re/render.md */

void __thiscall EAGL__DynamicLoader__LoadSymbols(undefined4 *param_1,int param_2)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined1 *puVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  uint uVar10;
  char *pcVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  char *pcVar15;
  bool bVar16;
  int *piStack_a0;
  int iStack_9c;
  int iStack_88;
  char acStack_80 [128];
  
  piStack_a0 = (int *)(*(code *)PTR_FUN_006dfa9c)(0x430,"EAGL::HashPointer new");
  iVar14 = 0;
  if (piStack_a0 == (int *)0x0) {
    piStack_a0 = (int *)0x0;
  }
  else {
    *piStack_a0 = 0;
    piStack_a0[2] = 0;
    *(undefined1 *)(piStack_a0 + 3) = 0;
    piStack_a0[4] = 0;
    piStack_a0[5] = 0;
    piStack_a0[6] = 0;
    piStack_a0[7] = 0;
    piStack_a0[0x108] = 0;
    piStack_a0[0x109] = 0;
    piStack_a0[0x10a] = (int)param_1;
    piStack_a0[0x10b] = 0;
  }
  iVar3 = param_1[4];
  piStack_a0[7] = iVar3;
  uVar7 = *(uint *)(iVar3 + 0x20);
  uVar10 = param_1[5];
  if (uVar7 < uVar10) {
LAB_0061e09d:
    iStack_9c = param_1[4];
  }
  else {
    if (param_1[6] == 0) {
      if (uVar10 < uVar7) {
        iStack_9c = 0;
        goto LAB_0061e0a6;
      }
      goto LAB_0061e09d;
    }
    iStack_9c = param_1[6] - uVar10;
  }
  iStack_9c = iStack_9c + uVar7;
LAB_0061e0a6:
  piStack_a0[6] = iStack_9c;
  piStack_a0[5] = 0;
  if (*(short *)(iVar3 + 0x30) != 0) {
    iVar13 = iStack_9c + 8;
    do {
      uVar7 = *(uint *)(iVar13 + 8);
      uVar10 = param_1[5];
      if (uVar7 < uVar10) {
LAB_0061e0dd:
        iVar4 = param_1[4];
LAB_0061e0e0:
        iVar4 = iVar4 + uVar7;
      }
      else {
        if (param_1[6] != 0) {
          iVar4 = param_1[6] - uVar10;
          goto LAB_0061e0e0;
        }
        if (uVar7 <= uVar10) goto LAB_0061e0dd;
        iVar4 = 0;
      }
      *(int *)(iVar13 + 8) = iVar4;
      iVar14 = iVar14 + 1;
      iVar13 = iVar13 + 0x28;
    } while (iVar14 < (int)(uint)*(ushort *)(iVar3 + 0x30));
  }
  iVar14 = *(int *)(iStack_9c + 0x10 + (uint)*(ushort *)(iVar3 + 0x32) * 0x28);
  iStack_88 = 0;
  if (*(short *)(iVar3 + 0x30) != 0) {
    piVar12 = (int *)(iStack_9c + 0x18);
    do {
      uVar7 = piVar12[-5];
      if (uVar7 < 0x70000006) {
        if (uVar7 != 0x70000005) {
          switch(uVar7) {
          case 0:
          case 1:
            break;
          case 2:
            *piVar12 = *(int *)(iStack_9c + 0x10 + *piVar12 * 0x28);
            iVar13 = 8;
            bVar16 = true;
            pcVar11 = ".symtab";
            pcVar15 = (char *)(piVar12[-6] + iVar14);
            do {
              if (iVar13 == 0) break;
              iVar13 = iVar13 + -1;
              bVar16 = *pcVar11 == *pcVar15;
              pcVar11 = pcVar11 + 1;
              pcVar15 = pcVar15 + 1;
            } while (bVar16);
            if (bVar16) {
              piStack_a0[5] = piVar12[-2];
              piStack_a0[4] = (int)(piVar12[-1] + (piVar12[-1] >> 0x1f & 0xfU)) >> 4;
            }
            break;
          case 3:
            iVar13 = 8;
            bVar16 = true;
            pcVar11 = ".strtab";
            pcVar15 = (char *)(piVar12[-6] + iVar14);
            do {
              if (iVar13 == 0) break;
              iVar13 = iVar13 + -1;
              bVar16 = *pcVar11 == *pcVar15;
              pcVar11 = pcVar11 + 1;
              pcVar15 = pcVar15 + 1;
            } while (bVar16);
            if (bVar16) {
              pcVar11 = (char *)piVar12[-2];
              piStack_a0[2] = (int)pcVar11;
              for (iVar13 = piVar12[-1]; 0 < iVar13;
                  iVar13 = iVar13 + (-1 - ((int)pcVar5 - (int)pcVar15))) {
                pcVar15 = pcVar11 + 1;
                pcVar5 = pcVar11;
                do {
                  cVar1 = *pcVar5;
                  pcVar5 = pcVar5 + 1;
                } while (cVar1 != '\0');
                if ((*pcVar11 == '_') && (pcVar11[1] == '_')) {
                  pcVar8 = pcVar11 + 2;
                  puVar6 = (undefined1 *)FUN_00672970(pcVar8,&DAT_006a7290);
                  if (puVar6 != (undefined1 *)0x0) {
                    *puVar6 = 0;
                    iVar4 = -(int)pcVar8;
                    do {
                      cVar1 = *pcVar8;
                      pcVar8[(int)(acStack_80 + iVar4)] = cVar1;
                      pcVar8 = pcVar8 + 1;
                    } while (cVar1 != '\0');
                    pcVar8 = ":::";
                    do {
                      pcVar9 = pcVar8;
                      pcVar8 = pcVar9 + 1;
                    } while (*pcVar9 != '\0');
                    pcVar9 = pcVar9 + -0x6a7290 + (int)puVar6;
                    pcVar8 = pcVar9;
                    do {
                      cVar1 = *pcVar8;
                      pcVar8 = pcVar8 + 1;
                    } while (cVar1 != '\0');
                    pcVar8 = pcVar8 + (1 - (int)(pcVar9 + 1));
                    _memmove(pcVar11,pcVar9,(size_t)pcVar8);
                    pcVar11[(int)pcVar8] = '\x7f';
                    pcVar9 = acStack_80;
                    do {
                      cVar1 = *pcVar9;
                      pcVar9[(int)(pcVar11 + (int)pcVar8 + (1 - (int)acStack_80))] = cVar1;
                      pcVar9 = pcVar9 + 1;
                    } while (cVar1 != '\0');
                  }
                }
                pcVar11 = pcVar11 + ((int)pcVar5 - (int)pcVar15) + 1;
              }
            }
            break;
          case 4:
            if (piVar12[-1] != 0) {
              FUN_0061f500(0,"dlopen: non empty SHT_RELA section seen. Not supported.\n");
            }
            break;
          case 5:
          case 6:
            FUN_0061f500(0,"dlopen: SHT_HASH section seen. Not supported.\n");
            break;
          default:
            goto switchD_0061e14d_caseD_7;
          case 8:
            if (piVar12[-1] != 0) {
              FUN_0061f500(0,"dlopen: SHT_NOBITS section with data seen. Not supported.\n");
            }
            break;
          case 9:
            piVar12[1] = *(int *)(iStack_9c + 0x10 + piVar12[1] * 0x28);
            *piVar12 = *(int *)(iStack_9c + 0x10 + *piVar12 * 0x28);
            break;
          case 10:
            FUN_0061f500(0,"dlopen: SHT_SHLIB section seen. Not supported.\n");
            break;
          case 0xb:
            FUN_0061f500(0,"dlopen: SHT_DYNSYM section seen. Not supported.\n");
          }
        }
      }
      else if ((uVar7 != 0x70000006) && ((uVar7 < 0x7ffff420 || (0x7ffff421 < uVar7)))) {
switchD_0061e14d_caseD_7:
        FUN_0061f500(0,"Unknown section type %d (section %d). Aborting dynamic loading.\n",uVar7,
                     iStack_88);
      }
      iStack_88 = iStack_88 + 1;
      piVar12 = piVar12 + 10;
    } while (iStack_88 < (int)(uint)*(ushort *)(iVar3 + 0x30));
  }
  if (piStack_a0[5] == 0) {
    FUN_0061f500(0,"dlopen: Failed to find a symbol table. Aborting\n");
  }
  piStack_a0[0x10b] = param_2;
  piVar12 = piStack_a0 + 8;
  for (iVar14 = 0x100; iVar14 != 0; iVar14 = iVar14 + -1) {
    *piVar12 = -1;
    piVar12 = piVar12 + 1;
  }
  iVar14 = (*(code *)PTR_FUN_006dfa9c)(piStack_a0[4] << 2,"EAGL::dynamic symbols");
  piStack_a0[0x108] = iVar14;
  iVar14 = (*(code *)PTR_FUN_006dfa9c)(piStack_a0[4],"EAGL::dynamic symbols 2");
  piStack_a0[0x109] = iVar14;
  iVar14 = 0;
  if (0 < piStack_a0[4]) {
    iVar13 = 0;
    do {
      iVar4 = piStack_a0[5];
      pcVar11 = (char *)(piStack_a0[2] + *(int *)(iVar4 + iVar13));
      uVar7 = 0;
      cVar1 = *pcVar11;
      while (cVar1 != '\0') {
        uVar7 = uVar7 * 0x10 + (int)cVar1;
        pcVar11 = pcVar11 + 1;
        uVar10 = uVar7 & 0xf0000000;
        if (uVar10 != 0) {
          uVar7 = uVar7 ^ uVar10 >> 0x18;
        }
        uVar7 = uVar7 & ~uVar10;
        cVar1 = *pcVar11;
      }
      *(int *)(piStack_a0[0x108] + iVar14 * 4) = piStack_a0[(uVar7 & 0xff) + 8];
      piStack_a0[(uVar7 & 0xff) + 8] = iVar14;
      uVar2 = *(ushort *)(iVar4 + 0xe + iVar13);
      if ((uVar2 == 0) || (*(ushort *)(iVar3 + 0x30) <= uVar2)) {
        *(undefined1 *)(iVar14 + piStack_a0[0x109]) = 0;
      }
      else {
        *(undefined1 *)(iVar14 + piStack_a0[0x109]) = 1;
      }
      iVar14 = iVar14 + 1;
      iVar13 = iVar13 + 0x10;
    } while (iVar14 < piStack_a0[4]);
  }
  *piStack_a0 = (int)DAT_007094b8;
  if (DAT_007094b8 != (int *)0x0) {
    *(int **)((int)DAT_007094b8 + 4) = piStack_a0;
  }
  piStack_a0[1] = 0;
  *param_1 = piStack_a0;
  DAT_007094b8 = piStack_a0;
  return;
}


// ==== 0x61e4d0 FUN_0061e4d0

void __thiscall FUN_0061e4d0(int *param_1,int *param_2,int param_3)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int local_c;
  uint local_4;
  
  iVar3 = *param_1;
  iVar7 = 0;
  if (iVar3 == 0) {
    *param_2 = 0;
    param_2[1] = local_c;
    param_2[2] = 0;
    param_2[3] = local_4;
    return;
  }
  if ((param_3 < 0) || (*(int *)(iVar3 + 0x10) <= param_3)) {
    *param_2 = 0;
    param_2[1] = local_c;
    param_2[2] = 0;
    param_2[3] = local_4;
    return;
  }
  iVar6 = *(int *)(iVar3 + 0x14) + param_3 * 0x10;
  pcVar1 = (char *)(*(int *)(iVar3 + 8) + *(int *)(*(int *)(iVar3 + 0x14) + param_3 * 0x10));
  pcVar4 = pcVar1;
  do {
    pcVar8 = pcVar4;
    pcVar4 = pcVar8 + 1;
  } while (*pcVar8 != '\0');
  if (pcVar8[1] == '\x7f') {
    pcVar8 = pcVar8 + 2;
  }
  cVar2 = *(char *)(iVar6 + 0xd);
  if (((cVar2 != '\x02') && (cVar2 != '\x03')) && (cVar2 != '\x04')) {
    local_4 = CONCAT31(local_4._1_3_,1);
    if (cVar2 != '\x05') goto LAB_0061e567;
  }
  local_4 = local_4 & 0xffffff00;
LAB_0061e567:
  uVar5 = (uint)*(ushort *)(iVar6 + 0xe);
  if (cVar2 != '\x01') {
    if ((uVar5 != 0) && (uVar5 < *(ushort *)(*(int *)(iVar3 + 0x1c) + 0x30))) {
      iVar7 = *(int *)(*(int *)(iVar3 + 0x18) + 0x10 + uVar5 * 0x28) + *(int *)(iVar6 + 4);
    }
    *param_2 = (int)pcVar1;
    param_2[1] = (int)pcVar8;
    param_2[2] = iVar7;
    param_2[3] = local_4;
    return;
  }
  iVar3 = *(int *)(iVar6 + 4);
  *param_2 = (int)pcVar1;
  param_2[1] = (int)pcVar8;
  param_2[2] = iVar3;
  param_2[3] = local_4;
  return;
}


// ==== 0x61e5f0 FUN_0061e5f0

int FUN_0061e5f0(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  byte *pbVar7;
  bool bVar8;
  
  iVar2 = *(int *)(param_1 + 0x14);
  iVar4 = FUN_0061df50();
  uVar3 = *(uint *)(param_1 + 0x20 + iVar4 * 4);
  do {
    if (uVar3 == 0xffffffff) {
      return 0;
    }
    if (*(uint *)(param_1 + 0x10) < uVar3) {
      FUN_0061f500(0,"dlsym: Internal error. Bad j value %d (chain size %d)!\n",uVar3,
                   *(uint *)(param_1 + 0x10));
    }
    if (*(char *)(uVar3 + *(int *)(param_1 + 0x424)) != '\0') {
      pbVar5 = (byte *)(*(int *)(param_1 + 8) + *(int *)(uVar3 * 0x10 + iVar2));
      pbVar7 = param_2;
      do {
        bVar1 = *pbVar7;
        bVar8 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_0061e674:
          iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_0061e679;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar7[1];
        bVar8 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_0061e674;
        pbVar7 = pbVar7 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_0061e679:
      if (((iVar4 == 0) && (uVar6 = (uint)*(ushort *)(uVar3 * 0x10 + iVar2 + 0xe), uVar6 != 0)) &&
         (uVar6 < *(ushort *)(*(int *)(param_1 + 0x1c) + 0x30))) {
        return *(int *)(*(int *)(param_1 + 0x18) + 0x10 + uVar6 * 0x28) +
               *(int *)(uVar3 * 0x10 + 4 + iVar2);
      }
    }
    uVar3 = *(uint *)(*(int *)(param_1 + 0x420) + uVar3 * 4);
  } while( true );
}


// ==== 0x61e6d0 FUN_0061e6d0

undefined4 __thiscall FUN_0061e6d0(int *param_1,byte *param_2,int *param_3,undefined4 *param_4)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  bool bVar6;
  undefined4 local_10;
  byte *local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  do {
    iVar4 = 0;
    if (*param_1 != 0) {
      iVar4 = *(int *)(*param_1 + 0x10);
    }
    iVar2 = *param_3;
    if (iVar4 <= iVar2) {
      return 0;
    }
    FUN_0061e4d0(&local_10,iVar2);
    pbVar3 = param_2;
    pbVar5 = local_c;
    do {
      bVar1 = *pbVar3;
      bVar6 = bVar1 < *pbVar5;
      if (bVar1 != *pbVar5) {
LAB_0061e734:
        iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_0061e739;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar6 = bVar1 < pbVar5[1];
      if (bVar1 != pbVar5[1]) goto LAB_0061e734;
      pbVar3 = pbVar3 + 2;
      pbVar5 = pbVar5 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_0061e739:
    if (iVar4 == 0) {
      *param_4 = local_10;
      param_4[1] = local_c;
      param_4[2] = local_8;
      param_4[3] = local_4;
      *param_3 = *param_3 + 1;
      return 1;
    }
    *param_3 = iVar2 + 1;
  } while( true );
}


// ==== 0x61e790 GetFirstAnimBank

/* [canon] render med (ghidra+hopper) docs/re/tuning.md */

undefined4 GetFirstAnimBank(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  char cVar1;
  undefined1 local_10 [8];
  undefined4 local_8;
  
  local_8 = 0;
  cVar1 = FUN_0061e6d0(param_1,param_2,local_10);
  if (cVar1 != '\0') {
    *param_3 = local_8;
    return 1;
  }
  return 0;
}


// ==== 0x61e7d0 FUN_0061e7d0

void __fastcall FUN_0061e7d0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    if ((int *)piVar1[1] == (int *)0x0) {
      DAT_007094b8 = *piVar1;
    }
    else {
      *(int *)piVar1[1] = *piVar1;
    }
    if (*piVar1 != 0) {
      *(int *)(*piVar1 + 4) = piVar1[1];
    }
    if (piVar1[0x108] != 0) {
      (*(code *)PTR_FUN_006dfaa0)(piVar1[0x108],piVar1[4] << 2);
    }
    if (piVar1[0x109] != 0) {
      (*(code *)PTR_FUN_006dfaa0)(piVar1[0x109],piVar1[4]);
    }
    (*(code *)PTR_FUN_006dfaa0)(piVar1,0x430);
    *param_1 = 0;
  }
  return;
}


// ==== 0x61e850 EAGL::DynamicLoader::RunDestructors

/* [canon] render low (hopper+ghidra) docs/re/render.md */

void __fastcall EAGL__DynamicLoader__RunDestructors(int *param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  bool bVar8;
  int iStack_18;
  int local_14;
  undefined4 local_10;
  char *local_c;
  undefined4 uStack_8;
  char local_4;
  
  if (*param_1 == 0) {
    local_14 = 0;
  }
  else {
    local_14 = *(int *)(*param_1 + 0x10);
  }
  iVar6 = 0;
  iVar4 = 0;
  if (0 < local_14) {
    do {
      FUN_0061e4d0(&local_10,iVar4);
      if ((local_4 != '\0') && (iVar1 = FUN_0061f570(local_c), iVar1 != 0)) {
        iVar6 = iVar6 + 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < local_14);
    if (0 < iVar6) {
      iVar4 = (*(code *)PTR_FUN_006dfa9c)(iVar6 * 8,"EAGL::dynamic destructor list");
      param_1[2] = iVar4;
      iVar4 = 0;
      iStack_18 = 0;
      do {
        FUN_0061e4d0(&local_10,iStack_18);
        if (local_4 != '\0') {
          iVar6 = 0xd;
          bVar8 = true;
          pcVar5 = "RenderMethod";
          pcVar7 = local_c;
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar8 = *pcVar5 == *pcVar7;
            pcVar5 = pcVar5 + 1;
            pcVar7 = pcVar7 + 1;
          } while (bVar8);
          if ((bVar8) && (pcVar2 = (code *)FUN_0061f570(local_c), pcVar2 != (code *)0x0)) {
            uVar3 = FUN_0061f590(local_c);
            (*pcVar2)(uStack_8,param_1,local_10);
            *(undefined4 *)(param_1[2] + iVar4 * 8) = uVar3;
            *(undefined4 *)(param_1[2] + 4 + iVar4 * 8) = uStack_8;
            iVar4 = iVar4 + 1;
          }
        }
        iStack_18 = iStack_18 + 1;
      } while (iStack_18 < local_14);
      iStack_18 = 0;
      do {
        FUN_0061e4d0(&local_10,iStack_18);
        if (local_4 != '\0') {
          iVar6 = 0xd;
          bVar8 = true;
          pcVar5 = "RenderMethod";
          pcVar7 = local_c;
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar8 = *pcVar5 == *pcVar7;
            pcVar5 = pcVar5 + 1;
            pcVar7 = pcVar7 + 1;
          } while (bVar8);
          if ((!bVar8) && (pcVar2 = (code *)FUN_0061f570(local_c), pcVar2 != (code *)0x0)) {
            uVar3 = FUN_0061f590(local_c);
            (*pcVar2)(uStack_8,param_1,local_10);
            *(undefined4 *)(param_1[2] + iVar4 * 8) = uVar3;
            *(undefined4 *)(param_1[2] + 4 + iVar4 * 8) = uStack_8;
            iVar4 = iVar4 + 1;
          }
        }
        iStack_18 = iStack_18 + 1;
        if (local_14 <= iStack_18) {
          param_1[1] = iVar4;
          return;
        }
      } while( true );
    }
  }
  param_1[1] = iVar6;
  return;
}


// ==== 0x61ea00 EAGL::DynamicLoader::DumpRuntimeAllocs

/* [canon] render low (ghidra) docs/re/render.md */

void __fastcall EAGL__DynamicLoader__DumpRuntimeAllocs(int *param_1)

{
  char *_Str2;
  byte bVar1;
  undefined4 *puVar2;
  bool bVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  code *pcVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  char *pcVar12;
  uint uVar13;
  int *piVar14;
  uint *puVar15;
  char cStack_bb;
  char local_ba;
  char cStack_b9;
  int local_b8;
  undefined4 *local_b4;
  uint local_b0;
  int local_ac;
  int *local_a8;
  int *local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int *local_94;
  int local_90;
  undefined4 uStack_8c;
  int local_88;
  char *pcStack_84;
  int aiStack_80 [32];
  
  puVar11 = (undefined4 *)*param_1;
  if (puVar11 == (undefined4 *)0x0) {
    return;
  }
  if (*(char *)(puVar11 + 3) != '\0') {
    return;
  }
  local_b8 = puVar11[6];
  iVar7 = puVar11[7];
  *(undefined1 *)(puVar11 + 3) = 1;
  bVar3 = false;
  local_ac = 0;
  local_9c = 0;
  local_b4 = puVar11;
  local_a4 = param_1;
  local_a0 = iVar7;
  if (*(short *)(iVar7 + 0x30) != 0) {
    local_94 = (int *)(local_b8 + 0x14);
LAB_0061ea60:
    if (local_94[-4] == 9) {
      local_88 = local_94[2];
      local_a8 = (int *)local_94[-1];
      iVar5 = (int)(*local_94 + (*local_94 >> 0x1f & 7U)) >> 3;
      local_90 = local_94[1];
      if (iVar5 != 0) {
LAB_0061eaa0:
        local_98 = iVar5;
        piVar14 = (int *)(((uint)local_a8[1] >> 8) * 0x10 + local_90);
        bVar1 = *(byte *)(piVar14 + 3);
        uVar13 = 0;
        local_b0 = 0;
        while ((bVar1 & 0xf) < 4) {
          uVar6 = (uint)*(ushort *)((int)piVar14 + 0xe);
          puVar2 = DAT_007094b8;
          if ((uVar6 != 0) && (uVar6 < *(ushort *)(local_a0 + 0x30))) {
            local_b0 = *(uint *)(local_b8 + 0x10 + uVar6 * 0x28);
            goto LAB_0061ed8b;
          }
          for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
            if ((puVar2 != puVar11) &&
               (iVar7 = FUN_0061e5f0(puVar2,puVar11[2] + *piVar14), iVar7 != 0)) {
              *(undefined2 *)((int)piVar14 + 0xe) = 1;
              piVar14[1] = iVar7 - *(int *)(local_b8 + 0x38);
              *(undefined1 *)((int)piVar14 + 0xd) = 2;
              goto LAB_0061eca2;
            }
          }
          if (((code *)puVar11[0x10b] == (code *)0x0) ||
             (iVar7 = (*(code *)puVar11[0x10b])(puVar11[2] + *piVar14,&local_ba), local_ba == '\0'))
          {
            iVar7 = FUN_0061f340(*piVar14 + puVar11[2],&cStack_b9);
            if (cStack_b9 == '\0') {
              _Str2 = (char *)(*piVar14 + puVar11[2]);
              pcVar4 = _Str2;
              do {
                pcVar12 = pcVar4;
                pcVar4 = pcVar12 + 1;
              } while (*pcVar12 != '\0');
              if (pcVar12[1] == '\x7f') {
                pcVar12 = pcVar12 + 2;
              }
              pcVar4 = "RUNTIME_ALLOC::";
              do {
                pcVar8 = pcVar4;
                pcVar4 = pcVar8 + 1;
              } while (*pcVar8 != '\0');
              iVar7 = _strncmp("RUNTIME_ALLOC::",_Str2,(size_t)(pcVar8 + -0x6a7074));
              if (iVar7 == 0) {
                pcVar4 = "RUNTIME_ALLOC::";
                do {
                  pcStack_84 = pcVar4;
                  pcVar4 = pcStack_84 + 1;
                } while (*pcStack_84 != '\0');
                pcStack_84 = pcStack_84 + -0x6a7074;
                pcVar9 = (code *)FUN_0061f570(pcVar12);
                if (pcVar9 != (code *)0x0) {
                  uVar10 = FUN_0061f590(pcVar12);
                  cStack_bb = '\0';
                  iVar7 = (*pcVar9)(pcStack_84 + (int)_Str2,local_a4,&uStack_8c,&cStack_bb,_Str2);
                  if ((cStack_bb != '\0') && (iVar7 != 0)) {
                    puVar11 = (undefined4 *)
                              (*(code *)PTR_FUN_006dfa9c)
                                        (0x10,"EAGL::DynamicLoader::RuntimeAllocDestructorEntry new"
                                        );
                    if (puVar11 == (undefined4 *)0x0) {
                      puVar11 = (undefined4 *)0x0;
                    }
                    else {
                      *puVar11 = uVar10;
                      puVar11[1] = iVar7;
                      puVar11[2] = uStack_8c;
                      puVar11[3] = 0;
                    }
                    puVar11[3] = local_a4[3];
                    local_a4[3] = (int)puVar11;
                  }
                  *(undefined2 *)((int)piVar14 + 0xe) = 1;
                  piVar14[1] = iVar7 - *(int *)(local_b8 + 0x38);
                  *(undefined1 *)((int)piVar14 + 0xd) = 5;
                  puVar11 = local_b4;
                  uVar13 = local_b0;
                  goto LAB_0061eca2;
                }
              }
              if (!bVar3) {
                FUN_0061f500(0,"\n------------------------------------\n");
                FUN_0061f500(0,
                             "ERROR: DynamicLoader::Resolve - Failed to resolve the following undefined\nrelocation symbol(s):\n\n"
                            );
                bVar3 = true;
              }
              puVar11 = local_b4;
              if (0x1f < local_ac) goto LAB_0061ed8b;
              iVar7 = 0;
              if (local_ac < 1) goto LAB_0061ed5f;
              goto LAB_0061ed50;
            }
            *(undefined2 *)((int)piVar14 + 0xe) = 1;
            piVar14[1] = iVar7 - *(int *)(local_b8 + 0x38);
            *(undefined1 *)((int)piVar14 + 0xd) = 4;
          }
          else {
            *(undefined2 *)((int)piVar14 + 0xe) = 1;
            piVar14[1] = iVar7 - *(int *)(local_b8 + 0x38);
            *(undefined1 *)((int)piVar14 + 0xd) = 3;
          }
LAB_0061eca2:
          bVar1 = *(byte *)(piVar14 + 3);
        }
        FUN_0061f500(0,
                     "dlopen: Relocation to a symbol type I don\'t understand! (symbol %s type %d)\n"
                     ,puVar11[2] + *piVar14,*(byte *)(piVar14 + 3) & 0xf);
        goto LAB_0061ecd0;
      }
    }
    goto LAB_0061ee53;
  }
LAB_0061ee94:
  EAGL__DynamicLoader__RunDestructors();
  return;
  while (iVar7 = iVar7 + 1, iVar7 < local_ac) {
LAB_0061ed50:
    if (*piVar14 + local_b4[2] == aiStack_80[iVar7]) goto LAB_0061ed8b;
  }
LAB_0061ed5f:
  iVar7 = *piVar14;
  iVar5 = local_b4[2];
  aiStack_80[local_ac] = iVar5 + iVar7;
  local_ac = local_ac + 1;
  FUN_0061f500(0,"   %s\n",iVar5 + iVar7);
  puVar11 = local_b4;
LAB_0061ed8b:
  uVar13 = local_b0 + piVar14[1];
  local_b0 = uVar13;
LAB_0061ecd0:
  uVar6 = *(uint *)(*local_a8 + local_88);
  puVar15 = (uint *)(*local_a8 + local_88);
  switch((char)local_a8[1]) {
  case '\0':
  case '\x01':
  case '\x03':
    break;
  case '\x02':
    *puVar15 = uVar6 + uVar13;
    break;
  case '\x04':
    uVar13 = uVar13 + (uVar6 & 0x3ffffff) * 4;
    if ((((uint)(puVar15 + 1) ^ uVar13) & 0xfc000000) != 0) {
      FUN_0061f500(0,
                   "dlopen: Result of patching jmp instruction is outside of range of possible jump. (%x vs. %x) Aborting.\n"
                   ,puVar15 + 1,uVar13);
    }
    *puVar15 = *puVar15 ^ (uVar13 >> 2 ^ *puVar15) & 0x3ffffff;
    break;
  case '\x05':
    uVar13 = uVar13 >> 0x10;
  case '\x06':
    *(short *)puVar15 = (short)*puVar15 + (short)uVar13;
    break;
  case '\a':
  case '\f':
    FUN_0061f500(0,"dlopen: Cannot deal with GP relative relocations. Aborting\n");
    break;
  case '\b':
    FUN_0061f500(0,"dlopen: Cannot deal with MIPS_LITERAL relocation yet\n");
    break;
  case '\t':
    FUN_0061f500(0,"dlopen: Cannot deal with MIPS_GOT16 relocation yet\n");
    break;
  default:
    FUN_0061f500(0,"dlopen: Cannot deal with relocation type %d yet\n",(char)local_a8[1]);
  }
  local_a8 = local_a8 + 2;
  iVar5 = local_98 + -1;
  if (local_98 + -1 == 0) goto code_r0x0061ee4b;
  goto LAB_0061eaa0;
code_r0x0061ee4b:
  local_98 = 0;
  iVar7 = local_a0;
LAB_0061ee53:
  local_9c = local_9c + 1;
  local_94 = local_94 + 10;
  if ((int)(uint)*(ushort *)(iVar7 + 0x30) <= local_9c) goto code_r0x0061ee6f;
  goto LAB_0061ea60;
code_r0x0061ee6f:
  if (bVar3) {
    FUN_0061f500(0,
                 "\nPossible causes:\n    - You forgot to add the symbol to the global symbol pool before loading\n      this ELF.\n    - You forgot to provide an address if using an address callback function.\n    - You forgot to load another ELF that contains the symbol before loading\n      this ELF.\n      ie. forgot to load eaglrm.o before a model ELF.\n    - There is a problem with the ELF file\n"
                );
    FUN_0061f500(0,"------------------------------------\n\n");
  }
  goto LAB_0061ee94;
}


// ==== 0x61eee0 FUN_0061eee0

undefined4 * __thiscall
FUN_0061eee0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  param_1[4] = param_2;
  param_1[7] = param_4;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = param_3;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  EAGL__DynamicLoader__LoadSymbols(param_4);
  EAGL__DynamicLoader__DumpRuntimeAllocs();
  return param_1;
}


// ==== 0x61ef30 FUN_0061ef30

void __fastcall FUN_0061ef30(int param_1)

{
  FUN_0061e7d0();
  FUN_0061df90();
  if (*(int *)(param_1 + 0x28) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(*(int *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x24));
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  return;
}


// ==== 0x61ef60 FUN_0061ef60

void FUN_0061ef60(size_t param_1)

{
  _malloc(param_1);
  return;
}


// ==== 0x61ef70 FUN_0061ef70

void FUN_0061ef70(void *param_1)

{
  _free(param_1);
  return;
}


// ==== 0x61ef80 FUN_0061ef80

void __thiscall FUN_0061ef80(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  if (param_2 == piVar1) {
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(piVar1[3] + 4);
    (**(code **)(*piVar1 + 0xc))(1);
  }
  else {
    do {
      piVar2 = piVar1;
      if (piVar2 == (int *)0x0) break;
      piVar1 = *(int **)(piVar2[3] + 4);
    } while (*(int **)(piVar2[3] + 4) != param_2);
    piVar1 = *(int **)(piVar2[3] + 4);
    *(undefined4 *)(piVar2[3] + 4) = *(undefined4 *)(piVar1[3] + 4);
    (**(code **)(*piVar1 + 0xc))(1);
  }
  if (DAT_007096ac == param_2) {
    DAT_007096ac = (int *)0x0;
  }
  return;
}


// ==== 0x61efe0 FUN_0061efe0

undefined4 FUN_0061efe0(void)

{
  return DAT_007096a4;
}


// ==== 0x61eff0 FUN_0061eff0

undefined4 FUN_0061eff0(void)

{
  return DAT_007096a8;
}


// ==== 0x61f000 FUN_0061f000

void FUN_0061f000(undefined4 param_1)

{
  DAT_007096a4 = param_1;
  DAT_007096ac = param_1;
  return;
}


// ==== 0x61f020 FUN_0061f020

void FUN_0061f020(undefined *param_1)

{
  PTR_FUN_006dfa9c = param_1;
  return;
}


// ==== 0x61f030 FUN_0061f030

void FUN_0061f030(undefined *param_1)

{
  PTR_FUN_006dfaa0 = param_1;
  return;
}


// ==== 0x61f040 FUN_0061f040

undefined4 FUN_0061f040(void)

{
  return DAT_007096a0;
}


// ==== 0x61f050 EAGL::RenderContext::New

/* [canon] render med (hopper+ghidra) docs/re/render.md */

void __fastcall EAGL__RenderContext__New(int param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_006dfa9c)(0x100,"RenderContext new");
  if (iVar1 == 0) {
    DAT_007096a4 = 0;
  }
  else {
    DAT_007096a4 = EAGL__RenderContext__Ctor(param_1);
  }
  *(undefined4 *)(*(int *)(DAT_007096a4 + 0xc) + 4) = *(undefined4 *)(param_1 + 0x2c);
  *(int *)(param_1 + 0x2c) = DAT_007096a4;
  DAT_007096ac = DAT_007096a4;
  return;
}


// ==== 0x61f090 FUN_0061f090

void __thiscall FUN_0061f090(int param_1,int param_2)

{
  FUN_0061ef80(param_2);
  if (DAT_007096a4 == param_2) {
    for (DAT_007096a4 = *(int *)(param_1 + 0x2c);
        (DAT_007096a4 != 0 && (*(int *)(DAT_007096a4 + 8) != 0));
        DAT_007096a4 = *(int *)(*(int *)(DAT_007096a4 + 0xc) + 4)) {
    }
  }
  return;
}


// ==== 0x61f0d0 FUN_0061f0d0

undefined4 __fastcall FUN_0061f0d0(int param_1)

{
  return *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xc);
}


// ==== 0x61f0e0 FUN_0061f0e0

void __thiscall FUN_0061f0e0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 0x10);
  if (param_2 == iVar2) {
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10) = *(undefined4 *)(iVar2 + 0x168);
  }
  else {
    do {
      iVar1 = iVar2;
      if (iVar1 == 0) break;
      iVar2 = *(int *)(iVar1 + 0x168);
    } while (*(int *)(iVar1 + 0x168) != param_2);
    iVar2 = *(int *)(iVar1 + 0x168);
    *(undefined4 *)(iVar1 + 0x168) = *(undefined4 *)(iVar2 + 0x168);
  }
  NullUpdate_ret();
  (*(code *)PTR_FUN_006dfaa0)(iVar2,0x170);
  if (param_2 == *(int *)(*(int *)(param_1 + 0xc) + 0xc)) {
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xc) = 0;
  }
  return;
}


// ==== 0x61f160 FUN_0061f160

void __fastcall FUN_0061f160(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = DAT_006dfac8;
  param_1[2] = 0;
  param_1[4] = 0;
  return;
}


// ==== 0x61f180 FUN_0061f180

uint __thiscall FUN_0061f180(int param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  
  uVar3 = 0;
  cVar2 = *param_2;
  while (cVar2 != '\0') {
    pcVar1 = param_2 + 1;
    uVar3 = uVar3 ^ uVar3 << 5 ^ (int)cVar2;
    param_2 = param_2 + 1;
    cVar2 = *pcVar1;
  }
  return uVar3 % *(uint *)(param_1 + 4);
}


// ==== 0x61f1b0 EAGL::SymbolPool::Lookup

/* [canon] render low (hopper+ghidra) docs/re/render.md */

void __thiscall EAGL__SymbolPool__Lookup(uint *param_1,char *param_2,undefined4 param_3)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  if (param_1[2] == 0) {
    iVar7 = DAT_006dfac8 << 2;
    param_1[1] = DAT_006dfac8;
    uVar5 = (*(code *)PTR_FUN_006dfa9c)(iVar7,"EAGL::SymbolPool::mpSymbolTable");
    param_1[2] = uVar5;
    uVar5 = 0;
    if (param_1[1] != 0) {
      do {
        *(undefined4 *)(param_1[2] + uVar5 * 4) = 0;
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_1[1]);
    }
  }
  uVar5 = 0;
  cVar2 = *param_2;
  while (cVar2 != '\0') {
    pcVar1 = param_2 + 1;
    uVar5 = uVar5 ^ uVar5 << 5 ^ (int)cVar2;
    param_2 = param_2 + 1;
    cVar2 = *pcVar1;
  }
  uVar5 = uVar5 % param_1[1];
  uVar3 = param_1[2];
  iVar7 = *(int *)(uVar3 + uVar5 * 4);
  while (iVar7 != 0) {
    uVar5 = uVar5 + 1;
    if (param_1[1] <= uVar5) {
      uVar5 = 0;
    }
    iVar7 = *(int *)(uVar3 + uVar5 * 4);
  }
  *(undefined4 *)(uVar3 + uVar5 * 4) = param_3;
  uVar5 = *param_1;
  uVar3 = param_1[1];
  *param_1 = uVar5 + 1;
  if (uVar3 <= uVar5 + 1) {
    uVar5 = param_1[2];
    param_1[1] = uVar3 * 2;
    uVar6 = (*(code *)PTR_FUN_006dfa9c)(uVar3 << 3,"EAGL::SymbolPool::mpSymbolTable");
    param_1[2] = uVar6;
    uVar6 = 0;
    if (param_1[1] != 0) {
      do {
        *(undefined4 *)(param_1[2] + uVar6 * 4) = 0;
        uVar6 = uVar6 + 1;
      } while (uVar6 < param_1[1]);
    }
    *param_1 = 0;
    if (0 < (int)uVar3) {
      iVar7 = 0;
      do {
        iVar4 = *(int *)(uVar5 + iVar7 * 4);
        EAGL__SymbolPool__Lookup(iVar4 + 4,iVar4);
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)uVar3);
    }
    if (uVar5 != 0) {
      (*(code *)PTR_FUN_006dfaa0)(uVar5,uVar3);
    }
  }
  return;
}


// ==== 0x61f2e0 FUN_0061f2e0

undefined4 * FUN_0061f2e0(char *param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 *puVar3;
  
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  puVar3 = (undefined4 *)
           (*(code *)PTR_FUN_006dfa9c)(pcVar2 + (5 - (int)(param_1 + 1)),"EAGL::SymbolEntry");
  *puVar3 = param_2;
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2[(int)(puVar3 + 1) - (int)param_1] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  EAGL__SymbolPool__Lookup(param_1,puVar3);
  return puVar3 + 1;
}


// ==== 0x61f340 FUN_0061f340

int __thiscall FUN_0061f340(int param_1,byte *param_2,undefined1 *param_3)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int extraout_ECX;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  bool bVar10;
  uint local_8;
  
  iVar5 = *(int *)(param_1 + 8);
  if (iVar5 == 0) {
    *param_3 = 0;
    return 0;
  }
  uVar4 = FUN_0061f180(param_2);
  local_8 = 0;
  do {
    iVar2 = *(int *)(iVar5 + uVar4 * 4);
    if (iVar2 != 0) {
      pbVar8 = (byte *)(iVar2 + 4);
      pbVar6 = param_2;
      do {
        bVar1 = *pbVar6;
        bVar10 = bVar1 < *pbVar8;
        if (bVar1 != *pbVar8) {
LAB_0061f3a8:
          iVar7 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_0061f3ad;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar6[1];
        bVar10 = bVar1 < pbVar8[1];
        if (bVar1 != pbVar8[1]) goto LAB_0061f3a8;
        pbVar6 = pbVar6 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar1 != 0);
      iVar7 = 0;
LAB_0061f3ad:
      if ((iVar7 == 0) && (iVar2 != 0)) {
        piVar3 = *(int **)(iVar5 + uVar4 * 4);
        if (piVar3 != (int *)0x0) {
          *param_3 = 1;
          return *piVar3;
        }
        *param_3 = 0;
        puVar9 = *(undefined4 **)(extraout_ECX + 0x10);
        iVar5 = 0;
        if (puVar9 == (undefined4 *)0x0) {
          return 0;
        }
        do {
          if (iVar5 != 0) {
            return iVar5;
          }
          iVar5 = (*(code *)*puVar9)(param_2,param_3);
          puVar9 = (undefined4 *)puVar9[2];
        } while (puVar9 != (undefined4 *)0x0);
        return iVar5;
      }
    }
    if (*(uint *)(extraout_ECX + 4) < local_8) {
      *param_3 = 0;
      return 0;
    }
    uVar4 = uVar4 + 1;
    if (*(uint *)(extraout_ECX + 4) <= uVar4) {
      uVar4 = 0;
    }
    local_8 = local_8 + 1;
  } while( true );
}


// ==== 0x61f440 FUN_0061f440

void __fastcall FUN_0061f440(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  
  if ((param_1[2] != 0) && (uVar4 = 0, param_1[1] != 0)) {
    do {
      iVar2 = *(int *)(param_1[2] + uVar4 * 4);
      if (iVar2 != 0) {
        pcVar3 = (char *)(iVar2 + 4);
        do {
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        (*(code *)PTR_FUN_006dfaa0)(iVar2,pcVar3 + (5 - (iVar2 + 5)));
      }
      *(undefined4 *)(param_1[2] + uVar4 * 4) = 0;
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)param_1[1]);
  }
  iVar2 = param_1[4];
  *param_1 = 0;
  while (iVar2 != 0) {
    iVar2 = param_1[4];
    param_1[4] = *(undefined4 *)(iVar2 + 8);
    (*(code *)PTR_FUN_006dfaa0)(iVar2,0xc);
    iVar2 = param_1[4];
  }
  param_1[4] = 0;
  return;
}


// ==== 0x61f4d0 FUN_0061f4d0

void __fastcall FUN_0061f4d0(int param_1)

{
  FUN_0061f440();
  if (*(int *)(param_1 + 8) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(*(int *)(param_1 + 8),*(int *)(param_1 + 4) << 2);
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}


// ==== 0x61f500 FUN_0061f500

int FUN_0061f500(int param_1,wchar_t *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 <= DAT_006dfacc) {
    if (DAT_007095a8 != (code *)0x0) {
      iVar1 = (*DAT_007095a8)(param_2);
      return iVar1;
    }
    iVar1 = _vfprintf_674839((FILE *)&DAT_006eb1e0,param_2,&stack0x0000000c);
  }
  return iVar1;
}


// ==== 0x61f540 FUN_0061f540

void FUN_0061f540(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0061f2e0(param_1,param_2);
  FUN_0061f2e0(param_1,param_3);
  return;
}


// ==== 0x61f570 FUN_0061f570

uint FUN_0061f570(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = FUN_0061f340(param_1,&param_1);
  return uVar1 & -(uint)((char)param_1 != '\0');
}


// ==== 0x61f590 FUN_0061f590

uint FUN_0061f590(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = FUN_0061f340(param_1,&param_1);
  return uVar1 & -(uint)((char)param_1 != '\0');
}


// ==== 0x61f5b0 FUN_0061f5b0

void FUN_0061f5b0(void)

{
  FUN_0061f4d0();
  FUN_0061f4d0();
  FUN_0061f4d0();
  FUN_0061f4d0();
  return;
}


// ==== 0x61f5e0 FUN_0061f5e0

undefined4 __fastcall FUN_0061f5e0(int *param_1)

{
  return CONCAT31((int3)((uint)*param_1 >> 8),*(undefined1 *)(*param_1 + 0x28));
}


// ==== 0x61f5f0 FUN_0061f5f0

void FUN_0061f5f0(void)

{
  Sleep(1);
  return;
}


// ==== 0x61f600 FUN_0061f600

void FUN_0061f600(void)

{
  PostMessageA(DAT_007096d8,0x10,0,0);
  return;
}


// ==== 0x61f620 FUN_0061f620

void __fastcall FUN_0061f620(undefined4 param_1)

{
  int iVar1;
  
  FUN_0061f040(param_1);
  FUN_0061f000(param_1);
  FUN_0061f040();
  iVar1 = PeekMessageA((LPMSG)&DAT_00709738,(HWND)0x0,0,0,1);
  while (iVar1 != 0) {
    TranslateMessage((MSG *)&DAT_00709738);
    DispatchMessageA((MSG *)&DAT_00709738);
    iVar1 = PeekMessageA((LPMSG)&DAT_00709738,(HWND)0x0,0,0,1);
  }
  return;
}


// ==== 0x61f690 FUN_0061f690

void __thiscall FUN_0061f690(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  fVar1 = (float)*(int *)(param_1 + 0x4c);
  if (*(int *)(param_1 + 0x4c) < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  *param_2 = fVar1;
  fVar1 = (float)*(int *)(param_1 + 0x50);
  if (*(int *)(param_1 + 0x50) < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  *param_3 = fVar1;
  return;
}


// ==== 0x61f6d0 FUN_0061f6d0

LPARAM FUN_0061f6d0(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  char cVar1;
  LPARAM LVar2;
  
  LVar2 = param_4;
  if (DAT_00709d98 != '\0') {
    cVar1 = FUN_00640af0(param_1,param_2,param_3,param_4,&param_4);
    if (cVar1 != '\0') {
      return param_4;
    }
  }
  LVar2 = DefWindowProcA(param_1,param_2,param_3,LVar2);
  return LVar2;
}


// ==== 0x61f720 FUN_0061f720

undefined4 __thiscall FUN_0061f720(int param_1,byte param_2)

{
  uint uVar1;
  
  *(byte *)(param_1 + 0x99) = param_2;
  uVar1 = (uint)param_2;
  if (DAT_006e29b4 != uVar1) {
    DAT_006e29b4 = uVar1;
    if (DAT_00709d80 != (int *)0x0) {
      (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0xe,*(undefined1 *)(param_1 + 0x99));
    }
  }
  return 1;
}


// ==== 0x61f760 FUN_0061f760

undefined1 __thiscall FUN_0061f760(int param_1,undefined1 *param_2)

{
  *param_2 = *(undefined1 *)(param_1 + 0x99);
  return 1;
}


// ==== 0x61f780 FUN_0061f780

undefined4 __thiscall FUN_0061f780(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *param_2 = *(undefined4 *)(iVar1 + 0x44);
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


// ==== 0x61f7a0 FUN_0061f7a0

undefined4 FUN_0061f7a0(int param_1)

{
  if (DAT_006dfb4c != param_1) {
    FUN_006228c0();
    DAT_006dfb4c = param_1;
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x99,param_1);
  }
  return 1;
}


// ==== 0x61f7e0 FUN_0061f7e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0061f7e0(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int local_10;
  int local_8;
  int local_4;
  
  if (*(int *)(*(int *)(param_1 + 0xc) + 0x58) < 0x11) {
    piVar4 = &DAT_006a77c4;
    iVar1 = 5;
    puVar3 = &DAT_006a77c4;
  }
  else {
    piVar4 = (int *)&DAT_006a77dc;
    iVar1 = 2;
    puVar3 = (undefined4 *)&DAT_006a77dc;
  }
  local_10 = 0;
  local_8 = 0;
  local_4 = 0;
  if (iVar1 != 0) {
    do {
      iVar5 = 0;
      do {
        *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd0) = 1;
        iVar2 = (**(code **)(*DAT_00709d7c + 0x24))
                          (DAT_00709d7c,*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xb8),1,*piVar4,
                           puVar3[iVar5],0);
        if (-1 < iVar2) {
          local_10 = *piVar4;
          local_8 = puVar3[iVar5];
          break;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
      if ((local_10 != 0) && (local_8 != 0)) break;
      local_4 = local_4 + 1;
      piVar4 = piVar4 + 1;
    } while (local_4 < iVar1);
  }
  if ((0x10 < *(int *)(*(int *)(param_1 + 0xc) + 0x58)) && (local_10 == 0)) {
    local_4 = 0;
    if (iVar1 == 0) {
      return 0;
    }
    piVar4 = &DAT_006a77c4;
    do {
      iVar5 = 0;
      do {
        *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd0) = 1;
        iVar2 = (**(code **)(*DAT_00709d7c + 0x24))
                          (DAT_00709d7c,*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xb8),1,*piVar4,
                           (&DAT_006a77c4)[iVar5],0);
        if (-1 < iVar2) {
          local_10 = *piVar4;
          local_8 = (&DAT_006a77c4)[iVar5];
          break;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
      if ((local_10 != 0) && (local_8 != 0)) break;
      local_4 = local_4 + 1;
      piVar4 = piVar4 + 1;
    } while (local_4 < iVar1);
    if (local_10 == 0) {
      return 0;
    }
    if (local_8 == 0) {
      return 0;
    }
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x54) = 0x10;
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x58) = 0x10;
  }
  DAT_00709720 = 0;
  *(int *)(*(int *)(param_1 + 0xc) + 0x38) = local_10;
  *(int *)(*(int *)(param_1 + 0xc) + 0x3c) = local_8;
  DAT_0070970c = local_8;
  if (param_2 != '\0') {
    _DAT_00709730 = 0;
    _DAT_00709734 = 1;
    return 1;
  }
  iVar5 = EAGL__PC__GetDirectDraw();
  iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0xc0);
  if (iVar1 == 1) {
    piVar4 = (int *)(iVar5 + 0x304);
    iVar1 = 0x20;
    do {
      if ((((piVar4[-1] == 1) &&
           (iVar5 = *(int *)(param_1 + 0xc), *piVar4 == *(int *)(iVar5 + 0x4c))) &&
          (piVar4[1] == *(int *)(iVar5 + 0x50))) && (piVar4[4] == *(int *)(iVar5 + 0x3c))) {
        _DAT_00709730 = piVar4[3];
      }
      if (((piVar4[5] == 1) &&
          (iVar5 = *(int *)(param_1 + 0xc), piVar4[6] == *(int *)(iVar5 + 0x4c))) &&
         ((piVar4[7] == *(int *)(iVar5 + 0x50) && (piVar4[10] == *(int *)(iVar5 + 0x3c))))) {
        _DAT_00709730 = piVar4[9];
      }
      if (((piVar4[0xb] == 1) &&
          (iVar5 = *(int *)(param_1 + 0xc), piVar4[0xc] == *(int *)(iVar5 + 0x4c))) &&
         ((piVar4[0xd] == *(int *)(iVar5 + 0x50) && (piVar4[0x10] == *(int *)(iVar5 + 0x3c))))) {
        _DAT_00709730 = piVar4[0xf];
      }
      if ((((piVar4[0x11] == 1) &&
           (iVar5 = *(int *)(param_1 + 0xc), piVar4[0x12] == *(int *)(iVar5 + 0x4c))) &&
          (piVar4[0x13] == *(int *)(iVar5 + 0x50))) && (piVar4[0x16] == *(int *)(iVar5 + 0x3c))) {
        _DAT_00709730 = piVar4[0x15];
      }
      if (((piVar4[0x17] == 1) &&
          (iVar5 = *(int *)(param_1 + 0xc), piVar4[0x18] == *(int *)(iVar5 + 0x4c))) &&
         ((piVar4[0x19] == *(int *)(iVar5 + 0x50) && (piVar4[0x1c] == *(int *)(iVar5 + 0x3c))))) {
        _DAT_00709730 = piVar4[0x1b];
      }
      if (((piVar4[0x1d] == 1) &&
          (iVar5 = *(int *)(param_1 + 0xc), piVar4[0x1e] == *(int *)(iVar5 + 0x4c))) &&
         ((piVar4[0x1f] == *(int *)(iVar5 + 0x50) && (piVar4[0x22] == *(int *)(iVar5 + 0x3c))))) {
        _DAT_00709730 = piVar4[0x21];
      }
      if ((((piVar4[0x23] == 1) &&
           (iVar5 = *(int *)(param_1 + 0xc), piVar4[0x24] == *(int *)(iVar5 + 0x4c))) &&
          (piVar4[0x25] == *(int *)(iVar5 + 0x50))) && (piVar4[0x28] == *(int *)(iVar5 + 0x3c))) {
        _DAT_00709730 = piVar4[0x27];
      }
      if (((piVar4[0x29] == 1) &&
          (iVar5 = *(int *)(param_1 + 0xc), piVar4[0x2a] == *(int *)(iVar5 + 0x4c))) &&
         ((piVar4[0x2b] == *(int *)(iVar5 + 0x50) && (piVar4[0x2e] == *(int *)(iVar5 + 0x3c))))) {
        _DAT_00709730 = piVar4[0x2d];
      }
      piVar4 = piVar4 + 0x30;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  else if (iVar1 == 2) {
    piVar4 = (int *)(iVar5 + 0x304);
    iVar1 = 0x20;
    do {
      if (((piVar4[-1] == 1) && (iVar5 = *(int *)(param_1 + 0xc), *piVar4 == *(int *)(iVar5 + 0x4c))
          ) && ((piVar4[1] == *(int *)(iVar5 + 0x50) && (piVar4[4] == *(int *)(iVar5 + 0x3c))))) {
        _DAT_00709730 = piVar4[2];
      }
      if ((((piVar4[5] == 1) &&
           (iVar5 = *(int *)(param_1 + 0xc), piVar4[6] == *(int *)(iVar5 + 0x4c))) &&
          (piVar4[7] == *(int *)(iVar5 + 0x50))) && (piVar4[10] == *(int *)(iVar5 + 0x3c))) {
        _DAT_00709730 = piVar4[8];
      }
      if (((piVar4[0xb] == 1) &&
          (iVar5 = *(int *)(param_1 + 0xc), piVar4[0xc] == *(int *)(iVar5 + 0x4c))) &&
         ((piVar4[0xd] == *(int *)(iVar5 + 0x50) && (piVar4[0x10] == *(int *)(iVar5 + 0x3c))))) {
        _DAT_00709730 = piVar4[0xe];
      }
      if (((piVar4[0x11] == 1) &&
          (iVar5 = *(int *)(param_1 + 0xc), piVar4[0x12] == *(int *)(iVar5 + 0x4c))) &&
         ((piVar4[0x13] == *(int *)(iVar5 + 0x50) && (piVar4[0x16] == *(int *)(iVar5 + 0x3c))))) {
        _DAT_00709730 = piVar4[0x14];
      }
      if ((((piVar4[0x17] == 1) &&
           (iVar5 = *(int *)(param_1 + 0xc), piVar4[0x18] == *(int *)(iVar5 + 0x4c))) &&
          (piVar4[0x19] == *(int *)(iVar5 + 0x50))) && (piVar4[0x1c] == *(int *)(iVar5 + 0x3c))) {
        _DAT_00709730 = piVar4[0x1a];
      }
      if (((piVar4[0x1d] == 1) &&
          (iVar5 = *(int *)(param_1 + 0xc), piVar4[0x1e] == *(int *)(iVar5 + 0x4c))) &&
         ((piVar4[0x1f] == *(int *)(iVar5 + 0x50) && (piVar4[0x22] == *(int *)(iVar5 + 0x3c))))) {
        _DAT_00709730 = piVar4[0x20];
      }
      if (((piVar4[0x23] == 1) &&
          (iVar5 = *(int *)(param_1 + 0xc), piVar4[0x24] == *(int *)(iVar5 + 0x4c))) &&
         ((piVar4[0x25] == *(int *)(iVar5 + 0x50) && (piVar4[0x28] == *(int *)(iVar5 + 0x3c))))) {
        _DAT_00709730 = piVar4[0x26];
      }
      if ((((piVar4[0x29] == 1) &&
           (iVar5 = *(int *)(param_1 + 0xc), piVar4[0x2a] == *(int *)(iVar5 + 0x4c))) &&
          (piVar4[0x2b] == *(int *)(iVar5 + 0x50))) && (piVar4[0x2e] == *(int *)(iVar5 + 0x3c))) {
        _DAT_00709730 = piVar4[0x2c];
      }
      piVar4 = piVar4 + 0x30;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  else {
    _DAT_00709730 = 0;
  }
  iVar1 = EAGL__PC__GetDirectDraw();
  if (iVar1 != 0) {
    if ((*(char *)(*(int *)(param_1 + 0xc) + 0x68) == '\0') && ((int)*(uint *)(iVar1 + 0x238) < 0))
    {
      _DAT_00709734 = 0x80000000;
      return 1;
    }
    if ((*(uint *)(iVar1 + 0x238) & 1) == 0) {
      return 0;
    }
  }
  _DAT_00709734 = 1;
  return 1;
}


// ==== 0x61fd80 FUN_0061fd80

void FUN_0061fd80(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  iVar2 = EAGL__PC__GetDirectDraw();
  uVar1 = *(uint *)(iVar2 + 0x240);
  if ((uVar1 & 0x80000) == 0) {
    return;
  }
  if ((uVar1 & 0x10000) == 0) {
    return;
  }
  if ((uVar1 & 0x100000) == 0) {
    return;
  }
  iVar3 = EAGL__PC__GetDirectDraw();
  uVar1 = *(uint *)(iVar3 + 0x204);
  if (uVar1 < 0x104a0011) {
    if (uVar1 == 0x104a0010) {
      DAT_00709d8c = 0;
      return;
    }
    if (uVar1 == 0x10024c57) {
      DAT_00709d8c = 0;
      return;
    }
    bVar4 = uVar1 == 0x10025157;
  }
  else {
    if (uVar1 == 0x10de0171) {
      DAT_00709d8c = 0;
      return;
    }
    bVar4 = uVar1 == 0x53339102;
  }
  if (bVar4) {
    DAT_00709d8c = 0;
    return;
  }
  DAT_00709d8c = '\x01' - (*(char *)(iVar2 + 0x2e9) == '\0');
  return;
}


// ==== 0x61fdf0 FUN_0061fdf0

void FUN_0061fdf0(void)

{
  int iVar1;
  
  iVar1 = EAGL__PC__GetDirectDraw();
  if (((*(uint *)(iVar1 + 0x240) & 0x80000) == 0) ||
     (DAT_00709d8d = 1, (*(uint *)(iVar1 + 0x240) & 0x10000) == 0)) {
    DAT_00709d8d = 0;
  }
  return;
}


// ==== 0x61fe20 EAGL::PC::CreateCapsWindow

/* [canon] render high (hopper+ghidra) docs/re/render.md */

HWND EAGL__PC__CreateCapsWindow(void)

{
  HWND pHVar1;
  HINSTANCE in_stack_00000018;
  HMENU hMenu;
  LPVOID lpParam;
  tagRECT local_10;
  
  SetRect(&local_10,0,0,100,100);
  lpParam = (LPVOID)0x0;
  hMenu = (HMENU)0x0;
  pHVar1 = GetDesktopWindow();
  pHVar1 = CreateWindowExA(0,"EAGL PC Caps Retrieval","EAGL PC Caps Retrieval",0,-0x80000000,
                           -0x80000000,local_10.right - local_10.left,local_10.bottom - local_10.top
                           ,pHVar1,hMenu,in_stack_00000018,lpParam);
  if (pHVar1 == (HWND)0x0) {
    return (HWND)0x0;
  }
  UpdateWindow(pHVar1);
  return pHVar1;
}


// ==== 0x61fea0 FUN_0061fea0

undefined4 __thiscall
FUN_0061fea0(int param_1,undefined4 param_2,undefined4 *param_3,int *param_4,int *param_5,
            undefined4 *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *unaff_EBX;
  undefined4 *unaff_EBP;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (DAT_00709d7c == (int *)0x0) {
    return 0;
  }
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0xc) + 0x38);
  if ((((*param_4 < 0x11) && (*param_5 == 0)) &&
      (iVar2 = (**(code **)(*DAT_00709d7c + 0x28))(DAT_00709d7c,param_2,param_3,puVar1,2,1,0x50),
      -1 < iVar2)) &&
     (iVar2 = (**(code **)(*DAT_00709d7c + 0x30))(DAT_00709d7c,param_2,param_3,puVar1,puVar1,0x50),
     -1 < iVar2)) {
    *param_6 = 0x50;
    *param_4 = 0x10;
    *param_5 = 0;
    return 1;
  }
  if (((*param_4 < 0x10) && (*param_5 < 2)) &&
     ((iVar2 = (**(code **)(*DAT_00709d7c + 0x28))(DAT_00709d7c,param_2,param_3,puVar1,2,1,0x49),
      -1 < iVar2 &&
      (iVar2 = (**(code **)(*DAT_00709d7c + 0x30))(DAT_00709d7c,param_2,param_3,puVar1,puVar1,0x49),
      -1 < iVar2)))) {
    *param_6 = 0x49;
    *param_4 = 0xf;
    *param_5 = 1;
    return 1;
  }
  if (*param_4 < 0x19) {
    if (((*param_5 == 0) &&
        (iVar2 = (**(code **)(*DAT_00709d7c + 0x28))(DAT_00709d7c,param_2,param_3,puVar1,2,1,0x4d),
        -1 < iVar2)) &&
       (iVar2 = (**(code **)(*DAT_00709d7c + 0x30))(DAT_00709d7c,param_2,param_3,puVar1,puVar1,0x4d)
       , -1 < iVar2)) {
      *param_6 = 0x4d;
      *param_4 = 0x18;
      *param_5 = 0;
      return 1;
    }
    if (*param_4 < 0x19) {
      if (((*param_5 < 9) &&
          (iVar2 = (**(code **)(*DAT_00709d7c + 0x28))(DAT_00709d7c,param_2,param_3,puVar1,2,1,0x4b)
          , -1 < iVar2)) &&
         (iVar2 = (**(code **)(*DAT_00709d7c + 0x30))
                            (DAT_00709d7c,param_2,param_3,puVar1,puVar1,0x4b), -1 < iVar2)) {
        *param_6 = 0x4b;
        *param_4 = 0x18;
        *param_5 = 8;
        return 1;
      }
      if (((*param_4 < 0x19) && (*param_5 < 5)) &&
         (iVar2 = (**(code **)(*DAT_00709d7c + 0x28))(DAT_00709d7c,param_2,param_3,puVar1,2,1,0x4f),
         -1 < iVar2)) {
        iVar2 = (**(code **)(*DAT_00709d7c + 0x30))(DAT_00709d7c,param_2,param_3,puVar1,puVar1,0x4f)
        ;
        if (-1 < iVar2) goto LAB_006201b3;
        iVar2 = (**(code **)(*DAT_00709d7c + 0x28))(DAT_00709d7c,param_2,param_3,puVar1,2,1,0x50);
        if ((-1 < iVar2) &&
           (iVar2 = (**(code **)(*DAT_00709d7c + 0x30))
                              (DAT_00709d7c,param_2,param_3,puVar1,puVar1,0x50), -1 < iVar2)) {
          *param_6 = 0x50;
          *param_4 = 0x10;
          *param_5 = 0;
          return 1;
        }
      }
    }
  }
  if (*param_4 < 0x21) {
    puVar3 = param_3;
    puVar4 = puVar1;
    iVar2 = (**(code **)(*DAT_00709d7c + 0x28))(DAT_00709d7c,param_2,param_3,puVar1,2,1,0x47);
    if (iVar2 < 0) {
      puVar3 = param_3;
      puVar4 = puVar1;
      iVar2 = (**(code **)(*DAT_00709d7c + 0x28))(DAT_00709d7c,param_2,param_3,puVar1,2,1,0x4b);
      if (iVar2 < 0) {
        iVar2 = (**(code **)(*DAT_00709d7c + 0x28))(DAT_00709d7c,param_2,param_3,puVar1,2,1,0x4f);
        if (iVar2 < 0) {
          puVar3 = param_3;
          puVar4 = puVar1;
          iVar2 = (**(code **)(*DAT_00709d7c + 0x28))(DAT_00709d7c,param_2,param_3,puVar1,2,1,0x4d);
          if ((-1 < iVar2) &&
             (iVar2 = (**(code **)(*DAT_00709d7c + 0x30))
                                (DAT_00709d7c,param_2,param_3,puVar1,puVar1,0x4d), -1 < iVar2)) {
            *puVar4 = 0x4d;
            *param_4 = 0x18;
            *puVar3 = 0;
            return 1;
          }
        }
        else {
          iVar2 = (**(code **)(*DAT_00709d7c + 0x30))
                            (DAT_00709d7c,param_2,param_3,puVar1,puVar1,0x4f);
          if (-1 < iVar2) {
LAB_006201b3:
            *unaff_EBX = 0x4f;
            *param_4 = 0x18;
            *unaff_EBP = 4;
            return 1;
          }
        }
      }
      else {
        iVar2 = (**(code **)(*DAT_00709d7c + 0x30))(DAT_00709d7c,param_2,param_3,puVar1,puVar1,0x4b)
        ;
        if (-1 < iVar2) {
          *puVar4 = 0x4b;
          *param_4 = 0x18;
          *puVar3 = 8;
          return 1;
        }
      }
    }
    else {
      iVar2 = (**(code **)(*DAT_00709d7c + 0x30))(DAT_00709d7c,param_2,param_3,puVar1,puVar1,0x47);
      if (-1 < iVar2) {
        *puVar4 = 0x47;
        *param_4 = 0x20;
        *puVar3 = 0;
        return 1;
      }
    }
  }
  return 0;
}


// ==== 0x620230 FUN_00620230

undefined1 FUN_00620230(void)

{
  return DAT_00709d8c;
}


// ==== 0x620240 FUN_00620240

undefined1 FUN_00620240(void)

{
  return DAT_00709d8d;
}


// ==== 0x620250 FUN_00620250

undefined4 FUN_00620250(undefined4 param_1)

{
  switch(param_1) {
  case 0x14:
    return 0x18;
  case 0x15:
  case 0x16:
    return 0x20;
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1d:
  case 0x1e:
    return 0x10;
  case 0x1b:
  case 0x1c:
    return 8;
  default:
    return 0;
  }
}


// ==== 0x6202b0 FUN_006202b0

void __thiscall FUN_006202b0(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xa4);
  return;
}


// ==== 0x6202d0 FUN_006202d0

void __thiscall FUN_006202d0(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xa8);
  return;
}


// ==== 0x6202f0 FUN_006202f0

void __thiscall FUN_006202f0(int param_1,undefined1 *param_2)

{
  *param_2 = *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x9a);
  return;
}


// ==== 0x620310 FUN_00620310

undefined4 __thiscall FUN_00620310(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *param_2 = *(undefined4 *)(iVar1 + 0x9c);
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


// ==== 0x620330 FUN_00620330

undefined4 __thiscall FUN_00620330(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *param_2 = *(undefined4 *)(iVar1 + 0xa0);
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


// ==== 0x620350 FUN_00620350

undefined4 __thiscall FUN_00620350(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *param_2 = *(undefined4 *)(iVar1 + 0xac);
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


// ==== 0x620370 FUN_00620370

undefined4 * __thiscall FUN_00620370(undefined4 *param_1,byte param_2)

{
  int iVar1;
  
  *param_1 = &PTR_FUN_006a77ec;
  iVar1 = *(int *)(param_1[3] + 0x10);
  while (iVar1 != 0) {
    FUN_0061f0e0(*(undefined4 *)(param_1[3] + 0x10));
    iVar1 = *(int *)(param_1[3] + 0x10);
  }
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x6203c0 FUN_006203c0

undefined4 * __thiscall FUN_006203c0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a7818;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x6203e0 FUN_006203e0

void __fastcall FUN_006203e0(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_006a781c;
  for (iVar1 = DAT_00709d84; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
    FUN_00621b00(iVar1);
  }
  piVar2 = (int *)param_1[0x3e];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  piVar2 = (int *)param_1[0x3d];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  FUN_00623350();
  thunk_FUN_00623350();
  if (DAT_00709d80 != (int *)0x0) {
    (**(code **)(*DAT_00709d80 + 8))(DAT_00709d80);
  }
  DAT_00709d80 = (int *)0x0;
  if (DAT_00709d99 != '\0') {
    if (DAT_007096d8 != (HWND)0x0) {
      DestroyWindow(DAT_007096d8);
      DAT_007096d8 = (HWND)0x0;
    }
    UnregisterClassA(DAT_006dfba0,DAT_006dfb8c);
    DAT_00709d99 = '\0';
  }
  (*(code *)PTR_FUN_006dfaa0)(param_1[0x38],param_1[0x37]);
  param_1[0x38] = 0;
  param_1[8] = &PTR_FUN_006a7818;
  param_1[4] = &PTR_FUN_006a7814;
  *param_1 = &PTR_FUN_006a77ec;
  iVar1 = *(int *)(param_1[3] + 0x10);
  while (iVar1 != 0) {
    FUN_0061f0e0(*(undefined4 *)(param_1[3] + 0x10));
    iVar1 = *(int *)(param_1[3] + 0x10);
  }
  return;
}


// ==== 0x6204e0 FUN_006204e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_006204e0(int param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int *piVar4;
  undefined8 uVar5;
  
  (**(code **)(*DAT_00709d7c + 0x20))
            (DAT_00709d7c,*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xb8),&DAT_007096e4);
  DAT_00709720 = 1;
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3c) = DAT_007096f0;
  DAT_0070970c = DAT_007096f0;
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x38) = DAT_007096f0;
  piVar1 = (int *)(*(int *)(param_1 + 0xc) + 0x5c);
  uVar5 = FUN_00620250(DAT_0070970c);
  piVar4 = (int *)((ulonglong)uVar5 >> 0x20);
  if (*piVar1 + *piVar4 == (int)uVar5) {
    cVar2 = FUN_0061fea0(*(undefined4 *)(extraout_ECX + 0xb8),*(undefined4 *)(extraout_ECX + 0xd0),
                         piVar4,piVar1,extraout_ECX + 0x40);
    if (cVar2 != '\0') goto LAB_00620578;
  }
  uVar3 = FUN_00620250(DAT_0070970c);
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x60) = uVar3;
LAB_00620578:
  uVar3 = FUN_00620250(DAT_0070970c);
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x54) = uVar3;
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x58) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x54);
  _DAT_00709730 = 0;
  _DAT_00709734 = 0;
  return 1;
}


// ==== 0x6205b0 FUN_006205b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_006205b0(int param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int **ppiVar6;
  int *apiStack_168 [2];
  
  FUN_00622e90();
  piVar1 = *(int **)(*(int *)(param_1 + 0xc) + 0xf4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))();
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xf4) = 0;
  }
  piVar1 = *(int **)(*(int *)(param_1 + 0xc) + 0xf8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))();
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xf8) = 0;
  }
  FUN_00621ea0();
  FUN_00623590();
  NullUpdate_ret();
  FUN_00622fb0();
  FUN_00623060();
  _DAT_0070972c = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd8);
  if (DAT_00709720 == 0) {
    FUN_0061f7e0();
  }
  else {
    FUN_006204e0();
  }
  if (DAT_00709720 != 0) {
    uVar3 = FUN_00620250();
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x60) = uVar3;
  }
  if (*(int *)(*(int *)(param_1 + 0xc) + 0x60) == 0) {
    DAT_00709724 = 0;
  }
  else {
    apiStack_168[1] = (int *)0x620680;
    cVar2 = FUN_0061fea0();
    if (cVar2 == '\0') {
      return -0x7fffbffb;
    }
    DAT_00709724 = 1;
    _DAT_00709728 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x40);
  }
  iVar4 = (**(code **)(*DAT_00709d80 + 0x38))();
  if (iVar4 < 0) {
    apiStack_168[1] = (int *)0x6206d9;
    ShowWindow(DAT_007096d8,6);
    apiStack_168[1] = (int *)0x6206e4;
    ShowWindow(DAT_007096d8,9);
    SetActiveWindow(DAT_007096d8);
    Sleep(1);
    iVar4 = (**(code **)(*DAT_00709d80 + 0xc))();
    if (iVar4 != -0x7789f797) {
      return iVar4;
    }
    _DAT_0070972c = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd8);
    if (DAT_00709720 == 0) {
      apiStack_168[1] = (int *)0x620734;
      FUN_0061f7e0();
    }
    else {
      apiStack_168[1] = (int *)0x62072d;
      FUN_006204e0();
    }
    if (DAT_00709720 != 0) {
      apiStack_168[1] = (int *)0x620748;
      uVar3 = FUN_00620250();
      *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x60) = uVar3;
    }
    iVar4 = *(int *)(param_1 + 0xc);
    apiStack_168[0] = (int *)(iVar4 + 0x60);
    if (*(int *)(iVar4 + 0x60) == 0) {
      DAT_00709724 = 0;
    }
    else {
      apiStack_168[1] = (int *)(iVar4 + 0x5c);
      cVar2 = FUN_0061fea0(*(undefined4 *)(iVar4 + 0xb8),*(undefined4 *)(iVar4 + 0xd0));
      if (cVar2 == '\0') {
        return -0x7fffbffb;
      }
      DAT_00709724 = 1;
      _DAT_00709728 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x40);
    }
    apiStack_168[1] = DAT_00709d80;
    apiStack_168[0] = (int *)0x6207bd;
    iVar4 = (**(code **)(*DAT_00709d80 + 0x38))();
    if (iVar4 < 0) {
      return iVar4;
    }
  }
  SetFocus(DAT_007096d8);
  apiStack_168[1] = (int *)0x6207dc;
  ShowWindow(DAT_007096d8,9);
  UpdateWindow(DAT_007096d8);
  SetCursor((HCURSOR)0x0);
  switch(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xc4)) {
  case 0:
  case 2:
    apiStack_168[1] = (int *)0x62082e;
    DAT_00709d90 = FUN_006385a0();
    break;
  case 1:
  case 3:
    apiStack_168[1] = (int *)0x620816;
    DAT_00709d94 = FUN_006385a0();
  }
  FUN_0061fd80();
  iVar4 = EAGL__PC__GetDirectDraw();
  if (((*(uint *)(iVar4 + 0x240) & 0x80000) == 0) ||
     (DAT_00709d8d = 1, (*(uint *)(iVar4 + 0x240) & 0x10000) == 0)) {
    DAT_00709d8d = 0;
  }
  FUN_00622f00();
  apiStack_168[1] = (int *)0x0;
  apiStack_168[0] = DAT_00709d80;
  (**(code **)(*DAT_00709d80 + 0x40))();
  if (DAT_00709724 != 0) {
    (**(code **)(*DAT_00709d80 + 0x84))(DAT_00709d80,*(int *)(param_1 + 0xc) + 0xf8);
  }
  FUN_00622ff0();
  FUN_006230a0();
  FUN_00621f00();
  FUN_006235d0();
  FUN_00623650();
  (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x89,DAT_0070a4c8);
  iVar4 = EAGL__PC__GetDirectDraw();
  iVar4 = *(int *)(iVar4 + 0x2c4);
  iVar5 = 0;
  if (0 < iVar4) {
    do {
      if (0xf < iVar5) break;
      if (iVar5 < 3) {
        (**(code **)(*DAT_00709d80 + 0xb8))(DAT_00709d80,iVar5,1);
      }
      else {
        (**(code **)(*DAT_00709d80 + 0xb8))(DAT_00709d80,iVar5,0);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar4);
  }
  ppiVar6 = apiStack_168;
  for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
    *ppiVar6 = (int *)0x0;
    ppiVar6 = ppiVar6 + 1;
  }
  (**(code **)(*DAT_00709d80 + 0xa8))(DAT_00709d80,apiStack_168);
  return 0;
}


// ==== 0x620970 FUN_00620970

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00620970(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_ECX;
  bool bVar3;
  undefined4 *puStack_12c;
  undefined4 *puStack_128;
  int *piStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  int iStack_118;
  int iStack_114;
  undefined4 *puStack_110;
  undefined4 *puStack_10c;
  char cStack_28;
  
  if (DAT_007096d8 == 0) {
    return 0x80004005;
  }
  _DAT_0070972c = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd8);
  bVar3 = *(int *)(*(int *)(param_1 + 0xc) + 0x60) != 0;
  if (bVar3) {
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd0) = 1;
    iVar1 = *(int *)(param_1 + 0xc);
    puStack_10c = (undefined4 *)(iVar1 + 0x40);
    puStack_110 = (undefined4 *)(iVar1 + 0x5c);
    iStack_114 = iVar1 + 0x60;
    uStack_11c = *(undefined4 *)(iVar1 + 0xb8);
    iStack_118 = 1;
    uStack_120 = 0x6209d4;
    FUN_0061fea0();
    _DAT_00709728 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x40);
  }
  DAT_00709724 = (uint)bVar3;
  puStack_10c = &DAT_00709d80;
  puStack_110 = &DAT_00709704;
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd0) = 1;
  iStack_114 = 0x80;
  iStack_118 = DAT_007096d8;
  uStack_120 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xb8);
  uStack_11c = 1;
  piStack_124 = DAT_00709d7c;
  puStack_128 = (undefined4 *)0x620a27;
  iVar1 = (**(code **)(*DAT_00709d7c + 0x3c))();
  *(int *)(param_1 + 8) = iVar1;
  if (iVar1 < 0) {
    bVar3 = *(int *)(*(int *)(param_1 + 0xc) + 0x60) != 0;
    if (bVar3) {
      *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd0) = 1;
      iVar1 = *(int *)(param_1 + 0xc);
      puStack_128 = (undefined4 *)(iVar1 + 0x40);
      puStack_12c = (undefined4 *)(iVar1 + 0x5c);
      FUN_0061fea0(*(undefined4 *)(iVar1 + 0xb8),1,iVar1 + 0x60);
      _DAT_00709728 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x40);
    }
    DAT_00709724 = (uint)bVar3;
    puStack_128 = &DAT_00709d80;
    puStack_12c = &DAT_00709704;
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd0) = 1;
    uVar2 = (**(code **)(*DAT_00709d7c + 0x3c))
                      (DAT_00709d7c,*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xb8),1,DAT_007096d8,
                       0x20);
    *(undefined4 *)(param_1 + 8) = uVar2;
  }
  if (-1 < *(int *)(param_1 + 8)) {
    piStack_124 = (int *)(*(int *)(param_1 + 0xc) + 0xf4);
    puStack_128 = (undefined4 *)0x0;
    puStack_12c = (undefined4 *)0x0;
    (**(code **)(*DAT_00709d80 + 0x40))(DAT_00709d80);
    if (DAT_00709724 != 0) {
      (**(code **)(*DAT_00709d80 + 0x84))(DAT_00709d80,*(int *)(param_1 + 0xc) + 0xf8);
    }
    uVar2 = FUN_00620250(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3c));
    *(undefined4 *)(extraout_ECX + 0x54) = uVar2;
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x58) =
         *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x54);
    switch(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xc4)) {
    case 0:
    case 2:
      DAT_00709d90 = FUN_006385a0(DAT_00709d80,&puStack_12c);
      break;
    case 1:
    case 3:
      DAT_00709d94 = FUN_006385a0(DAT_00709d80,&puStack_12c);
    }
    if (cStack_28 == '\0') {
      FUN_0061fd80();
      FUN_0061fdf0();
    }
    return *(undefined4 *)(param_1 + 8);
  }
  return 0;
}


// ==== 0x620ba0 FUN_00620ba0

undefined4 * __thiscall FUN_00620ba0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a7814;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x620bc0 EAGL::RenderContext::Ctor

/* [canon] render low (ghidra) docs/re/render.md */

undefined4 * __thiscall EAGL__RenderContext__Ctor(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  param_1[2] = 0;
  *param_1 = &PTR_FUN_006a781c;
  param_1[3] = param_1 + 8;
  param_1[1] = param_1 + 4;
  param_1[5] = param_1;
  param_1[4] = &PTR_FUN_006a7814;
  param_1[7] = param_1;
  param_1[9] = 0;
  param_1[10] = param_1;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[8] = &PTR_FUN_006a7818;
  param_1[0xd] = param_1;
  param_1[0x25] = 0xf;
  param_1[0x2c] = 0;
  param_1[0x37] = 0x100;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = param_2;
  param_1[0x2a] = 0x3f800000;
  param_1[0x2b] = 0x3f800000;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x18] = 0;
  param_1[0x17] = 0;
  param_1[0x19] = 1;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  *(undefined1 *)(param_1 + 0x1a) = 1;
  param_1[0x1b] = 3;
  *(undefined1 *)(param_1 + 0x1c) = 0;
  param_1[0x1d] = 1;
  param_1[0x1e] = 1;
  param_1[0x1f] = 1;
  param_1[0x20] = 1;
  param_1[0x21] = 8;
  param_1[0x22] = 0;
  param_1[0x23] = 0xffffffff;
  param_1[0x24] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x26) = 0;
  *(undefined1 *)((int)param_1 + 0x99) = 1;
  *(undefined1 *)((int)param_1 + 0x9a) = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2c] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0xffffffff;
  param_1[0x33] = 0;
  param_1[0x34] = 1;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  *(undefined1 *)(param_1 + 0x35) = 1;
  param_1[0x36] = 0;
  puVar1 = (undefined4 *)(*(code *)PTR_FUN_006dfa9c)(param_1[0x37],"Window Name");
  param_1[0x38] = puVar1;
  *puVar1 = 0x4c474145;
  puVar1[1] = 0x435020;
  *(undefined1 *)(param_1 + 0x39) = 0;
  param_1[0x2d] = 1;
  param_1[0x2e] = 0;
  param_1[0x30] = 0;
  param_1[0x3a] = FUN_0061f5f0;
  param_1[0x3b] = NullUpdate_ret;
  param_1[0x3c] = FUN_0061f600;
  return param_1;
}


// ==== 0x620d60 FUN_00620d60

undefined4 __thiscall FUN_00620d60(undefined4 param_1,byte param_2)

{
  FUN_006203e0();
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x100);
  }
  return param_1;
}


// ==== 0x620d90 FUN_00620d90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00620d90(int param_1,char param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar1 + 0xcc) != 0) {
    if ((((*(int *)(iVar1 + 200) != *(int *)(iVar1 + 0xc4)) &&
         (*(int *)(iVar1 + 200) = *(int *)(iVar1 + 0xc4), DAT_007096d8 != (HWND)0x0)) &&
        (iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 200), iVar1 != 3)) && (iVar1 != 2)) {
      DestroyWindow(DAT_007096d8);
    }
    DAT_007096d8 = (HWND)**(undefined4 **)(*(int *)(param_1 + 0xc) + 0xcc);
    puVar2 = &DAT_00709704;
    for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    if (param_2 == '\0') {
      FUN_0061f7e0(param_3);
    }
    else {
      FUN_006204e0(param_3);
    }
    _DAT_00709710 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 100);
    DAT_00709704 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x4c);
    DAT_00709708 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x50);
    switch(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x48)) {
    case 0:
      _DAT_00709718 = 1;
      break;
    case 1:
      _DAT_00709718 = 2;
      break;
    case 2:
      _DAT_00709718 = 3;
      break;
    case 3:
      _DAT_00709718 = 4;
    }
    _DAT_00709714 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x44);
    if (DAT_00709d80 == 0) {
      iVar1 = FUN_00620970(param_3);
    }
    else {
      iVar1 = FUN_006205b0();
    }
    if ((-1 < iVar1) && (DAT_00709d80 != 0)) {
      return 1;
    }
  }
  return 0;
}


// ==== 0x620ed0 EAGL::PC::InitCaps

/* [canon] render low (hopper+ghidra) docs/re/render.md */

undefined4 EAGL__PC__InitCaps(char param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  WNDCLASSEXA *pWVar4;
  UINT *pUVar5;
  UINT aUStackY_74 [9];
  undefined4 uStackY_50;
  HWND local_34;
  WNDCLASSEXA local_30;
  
  FUN_0061f040();
  iVar2 = EAGL__RenderContext__New();
  *(undefined4 *)(iVar2 + 0x54) = 0x10;
  *(undefined4 *)(iVar2 + 0x58) = 0x10;
  *(undefined4 *)(iVar2 + 0x60) = 0x10;
  local_30.lpfnWndProc = DefWindowProcA_exref;
  *(undefined4 *)(iVar2 + 0x4c) = 0x280;
  *(undefined4 *)(iVar2 + 0x50) = 0x1e0;
  local_30.cbSize = 0x30;
  local_30.style = 0x40;
  local_30.cbClsExtra = 0;
  local_30.cbWndExtra = 0;
  local_30.hInstance = GetModuleHandleA((LPCSTR)0x0);
  local_30.hIcon = (HICON)0x0;
  local_30.hCursor = (HCURSOR)0x0;
  local_30.hbrBackground = (HBRUSH)0x0;
  local_30.lpszMenuName = (LPCSTR)0x0;
  local_30.lpszClassName = "EAGL PC Caps Retrieval";
  local_30.hIconSm = (HICON)0x0;
  RegisterClassExA(&local_30);
  pWVar4 = &local_30;
  pUVar5 = aUStackY_74;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pUVar5 = pWVar4->cbSize;
    pWVar4 = (WNDCLASSEXA *)&pWVar4->style;
    pUVar5 = pUVar5 + 1;
  }
  local_34 = (HWND)EAGL__PC__CreateCapsWindow();
  *(HWND **)(*(int *)(iVar2 + 0x1c) + 0xcc) = &local_34;
  iVar3 = *(int *)(iVar2 + 0x1c);
  iVar1 = *(int *)(iVar3 + 0xc4);
  if (param_1 == '\0') {
    if (iVar1 != 2) {
      *(int *)(iVar3 + 200) = iVar1;
    }
    *(undefined4 *)(*(int *)(iVar2 + 0x1c) + 0xc4) = 2;
  }
  else {
    if (iVar1 != 3) {
      *(int *)(iVar3 + 200) = iVar1;
    }
    *(undefined4 *)(*(int *)(iVar2 + 0x1c) + 0xc4) = 3;
  }
  uStackY_50 = 0x620fd1;
  iVar2 = FUN_00620d90();
  if (iVar2 < 1) {
    return 0;
  }
  FUN_0061f040();
  FUN_0061f090();
  DestroyWindow(local_34);
  uStackY_50 = 0x621007;
  UnregisterClassA(local_30.lpszClassName,local_30.hInstance);
  return 1;
}


