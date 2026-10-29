// ==== 0x601cfe FUN_00601cfe

int __fastcall FUN_00601cfe(int param_1)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 local_18;
  undefined4 *local_14;
  void *local_10;
  void *local_c;
  uint local_8;
  
  local_c = (void *)0x0;
  local_10 = (void *)0x0;
  local_14 = (undefined4 *)0x0;
  if ((*(byte *)(param_1 + 0x34) & 8) == 0) {
    iVar1 = FUN_005f8440();
    if ((-1 < iVar1) && (iVar1 = FUN_005fbbf5(), -1 < iVar1)) {
      if ((*(byte *)(param_1 + 0x93) & 2) != 0) {
        uVar2 = 0;
        if (*(int *)(param_1 + 0xc) != 0) {
          do {
            iVar1 = uVar2 * 4;
            uVar2 = uVar2 + 1;
            *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x18) + iVar1) + 0x28) = 0;
          } while (uVar2 < *(uint *)(param_1 + 0xc));
        }
        pvVar3 = *(void **)(param_1 + 0xc);
        while (pvVar3 != (void *)0x0) {
          local_c = (void *)((int)pvVar3 + -1);
          iVar1 = *(int *)(*(int *)(param_1 + 0x18) + (int)local_c * 4);
          iVar4 = FUN_005f7a96();
          pvVar3 = local_c;
          if (iVar4 == 0) {
            uVar2 = *(uint *)(iVar1 + 0x28);
            iVar4 = FUN_005f7b45();
            if (iVar4 != 0) {
              *(int *)(iVar1 + 0x28) = *(int *)(iVar1 + 0x28) + 1;
              uVar2 = uVar2 + 2;
            }
            uVar6 = 0;
            pvVar3 = local_c;
            if (*(int *)(iVar1 + 0x14) != 0) {
              do {
                iVar4 = *(int *)(*(int *)(param_1 + 0x18) +
                                *(int *)(*(int *)(iVar1 + 0x18) + uVar6 * 4) * 4);
                if (*(uint *)(iVar4 + 0x28) < uVar2) {
                  *(uint *)(iVar4 + 0x28) = uVar2;
                }
                uVar6 = uVar6 + 1;
              } while (uVar6 < *(uint *)(iVar1 + 0x14));
            }
          }
        }
      }
      uVar2 = 0;
      local_8 = 0;
      local_c = _malloc(*(int *)(param_1 + 0xc) << 2);
      if (((local_c == (void *)0x0) ||
          (local_10 = _malloc(*(int *)(param_1 + 0xc) << 2), local_10 == (void *)0x0)) ||
         (local_14 = _malloc(*(int *)(param_1 + 0xc) << 2), local_14 == (undefined4 *)0x0)) {
        iVar1 = -0x7ff8fff2;
      }
      else {
        if (*(int *)(param_1 + 0xc) != 0) {
          do {
            iVar1 = *(int *)(*(int *)(param_1 + 0x18) + uVar2 * 4);
            *(undefined4 *)(iVar1 + 0x24) = 0;
            *(undefined4 *)(iVar1 + 0x30) = 0xffffffff;
            iVar4 = FUN_005f7a96();
            if ((iVar4 == 0) && (*(int *)(iVar1 + 0x1c) == 0)) {
              *(uint *)((int)local_c + local_8 * 4) = uVar2;
              local_8 = local_8 + 1;
            }
            uVar2 = uVar2 + 1;
          } while (uVar2 < *(uint *)(param_1 + 0xc));
        }
        uVar2 = 0;
        local_18 = 0;
        if (local_8 != 0) {
          do {
            iVar1 = FUN_005fada7(*(undefined4 *)((int)local_c + uVar2 * 4),local_10,&local_18);
            if (iVar1 < 0) goto LAB_00601eaa;
            uVar2 = uVar2 + 1;
          } while (uVar2 < local_8);
        }
        uVar2 = 0;
        if (*(int *)(param_1 + 0xc) != 0) {
          puVar5 = local_14;
          do {
            *puVar5 = *(undefined4 *)
                       (*(int *)(param_1 + 0x18) +
                       *(int *)(((int)local_10 - (int)local_14) + (int)puVar5) * 4);
            uVar2 = uVar2 + 1;
            puVar5 = puVar5 + 1;
          } while (uVar2 < *(uint *)(param_1 + 0xc));
        }
        puVar5 = local_14;
        puVar7 = *(undefined4 **)(param_1 + 0x18);
        for (uVar2 = *(uint *)(param_1 + 0xc) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar7 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar7 = puVar7 + 1;
        }
        for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
          *(undefined1 *)puVar7 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        iVar1 = 0;
      }
    }
LAB_00601eaa:
    _free(local_c);
    _free(local_10);
    _free(local_14);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


// ==== 0x601ecc FUN_00601ecc

undefined4 __fastcall FUN_00601ecc(int param_1)

{
  int *piVar1;
  uint *puVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined1 local_34 [16];
  uint *local_24;
  uint *local_20;
  int *local_1c;
  uint local_18;
  int *local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  local_c = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      puVar2 = *(uint **)(*(int *)(param_1 + 0x18) + local_c * 4);
      iVar6 = FUN_005f7a96();
      if (iVar6 == 0) {
        uVar8 = *puVar2 & 0xffffff;
        iVar6 = FUN_005f7ad9();
        if (iVar6 == 0) {
          iVar6 = FUN_005f7aeb();
          if (iVar6 != 0) {
            uVar9 = 1;
LAB_00601f7b:
            uVar7 = puVar2[2];
            goto LAB_0060201d;
          }
          iVar6 = FUN_005f7ac7();
          if (iVar6 != 0) {
            FUN_005fb7cf(puVar2[2] + uVar8 * 4,local_34,uVar8,1);
            uVar9 = 0;
            uVar7 = puVar2[2];
            goto LAB_0060201d;
          }
          iVar6 = FUN_005f7b0f();
          if (iVar6 != 0) {
            FUN_005fb7cf(puVar2[4],local_34,uVar8,1);
            uVar9 = 0;
            goto LAB_00601f7b;
          }
          iVar6 = FUN_005f7b21();
          if (iVar6 != 0) {
            FUN_005fb7cf(puVar2[4],local_34,uVar8,1);
            FUN_005fb7cf(puVar2[2],local_34,uVar8,0);
            uVar7 = puVar2[2] + puVar2[3] * 4;
LAB_0060201c:
            uVar9 = 0;
            goto LAB_0060201d;
          }
          iVar6 = FUN_005f7b33();
          if (iVar6 != 0) {
            FUN_005fb7cf(puVar2[4],local_34,uVar8,1);
            FUN_005fb7cf(puVar2[2],local_34,uVar8,0);
            FUN_005fb7cf(puVar2[2] + puVar2[3] * 4,local_34,uVar8,0);
            uVar7 = puVar2[2] + puVar2[3] * 8;
            goto LAB_0060201c;
          }
        }
        else {
          uVar9 = 1;
          uVar7 = puVar2[4];
LAB_0060201d:
          FUN_005fb7cf(uVar7,local_34,uVar8,uVar9);
        }
        iVar6 = FUN_005f7b21();
        if ((iVar6 != 0) && (iVar6 = FUN_005f7b67(), iVar6 != 0)) {
          piVar3 = (int *)puVar2[2];
          iVar6 = *(int *)(param_1 + 0x14);
          local_20 = *(uint **)(iVar6 + *piVar3 * 4);
          local_18 = 0xffffffff;
          local_8 = 0xffffffff;
          piVar1 = piVar3 + uVar8;
          local_24 = *(uint **)(iVar6 + *piVar1 * 4);
          local_1c = (int *)uVar8;
          if (uVar8 == 0) {
LAB_006020b3:
            local_1c = piVar1;
            uVar7 = *local_24;
            uVar4 = *(uint *)(*(int *)(*(int *)(param_1 + 0x10) + *local_20 * 4) + 4);
            uVar5 = *(uint *)(*(int *)(*(int *)(param_1 + 0x10) + uVar7 * 4) + 4);
            if ((uVar5 <= uVar4) &&
               ((uVar4 != uVar5 ||
                ((uVar7 <= *local_20 && ((*local_20 != uVar7 || (local_24[2] <= local_20[2]))))))))
            {
LAB_006020e8:
              local_8 = 0;
              if (uVar8 != 0) {
                local_24 = (uint *)(uVar8 << 2);
                do {
                  uVar7 = local_8 + 1;
                  piVar1 = (int *)(puVar2[2] + local_8 * 4);
                  local_20 = (uint *)*piVar1;
                  *piVar1 = *(int *)((int)local_24 + puVar2[2]);
                  *(uint **)((int)local_24 + puVar2[2]) = local_20;
                  local_24 = local_24 + 1;
                  local_8 = uVar7;
                } while (uVar7 < uVar8);
              }
            }
          }
          else {
            do {
              local_10 = piVar3;
              local_14 = piVar1;
              uVar7 = *(uint *)(*(int *)(iVar6 + *local_10 * 4) + 0x2c);
              if (uVar7 < local_18) {
                local_18 = uVar7;
              }
              uVar7 = *(uint *)(*(int *)(iVar6 + *local_14 * 4) + 0x2c);
              if (uVar7 < local_8) {
                local_8 = uVar7;
              }
              local_10 = local_10 + 1;
              local_14 = local_14 + 1;
              local_1c = (int *)((int)local_1c - 1);
              piVar1 = local_14;
              piVar3 = local_10;
            } while (local_1c != (int *)0x0);
            local_1c = (int *)0x0;
            if (local_8 <= local_18) {
              piVar1 = local_1c;
              if (local_18 == local_8) goto LAB_006020b3;
              goto LAB_006020e8;
            }
          }
        }
      }
      local_c = local_c + 1;
    } while (local_c < *(uint *)(param_1 + 0xc));
  }
  return 0;
}


// ==== 0x60213b FUN_0060213b

undefined4 __thiscall FUN_0060213b(int param_1,int *param_2,int *param_3,uint *param_4)

{
  uint *puVar1;
  uint *puVar2;
  int *piVar3;
  int *piVar4;
  uint *puVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int local_30 [4];
  int *local_20;
  int *local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  puVar2 = param_4;
  piVar3 = param_3;
  local_10 = 0;
  local_8 = param_1;
  local_c = 1;
  local_1c = (int *)0x4;
  piVar6 = param_3;
  do {
    if ((*piVar6 != -1) && (local_c < 4)) {
      iVar8 = 4 - local_c;
      local_20 = (int *)((int)param_4 - (int)param_3);
      piVar4 = piVar6;
      do {
        piVar4 = piVar4 + 1;
        if ((*piVar4 != -1) &&
           (*(double *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar6 * 4) + 0x10) ==
            *(double *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar4 * 4) + 0x10))) {
          *piVar4 = -1;
          *(uint *)(local_10 + (int)param_4) =
               *(uint *)(local_10 + (int)param_4) |
               *(uint *)(((int)param_4 - (int)param_3) + (int)piVar4);
        }
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    local_c = local_c + 1;
    local_10 = local_10 + 4;
    piVar6 = piVar6 + 1;
    local_1c = (int *)((int)local_1c + -1);
  } while (local_1c != (int *)0x0);
  uVar10 = 0;
  local_c = (int)param_3 - (int)param_4;
  param_4 = (uint *)0x0;
  local_10 = 0;
  puVar1 = puVar2;
  puVar5 = puVar2;
  do {
    if (*(int *)(local_c + (int)puVar1) != -1) {
      *(int *)(local_c + (int)puVar5) = *(int *)(local_c + (int)puVar1);
      *puVar5 = *puVar1;
      if (((*(byte *)(param_1 + 0x90) & 6) != 0) && ((*puVar1 & uVar10) != 0)) {
        return 0x80004005;
      }
      uVar10 = uVar10 | *puVar1;
      param_4 = (uint *)((int)param_4 + 1);
      puVar5 = puVar5 + 1;
    }
    local_10 = local_10 + 1;
    puVar1 = puVar1 + 1;
  } while (local_10 < 4);
  if (param_4 != (uint *)0x0) {
    if ((param_4 == (uint *)0x1) && (piVar6 = param_2, (*(byte *)(param_1 + 0x90) & 4) == 0)) {
      while( true ) {
        uVar10 = 0;
        param_3 = (int *)0x0;
        do {
          if (piVar6[uVar10] != -1) {
            if (*(double *)(*(int *)(*(int *)(param_1 + 0x14) + piVar6[uVar10] * 4) + 0x10) ==
                *(double *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar3 * 4) + 0x10)) {
              iVar8 = piVar6[uVar10];
              goto LAB_006022dd;
            }
            param_3 = (int *)((int)param_3 + 1);
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < 4);
        if (param_3 == (int *)0x0) break;
        piVar6 = piVar6 + 4;
      }
      iVar8 = 0;
      piVar6 = param_2;
      while( true ) {
        iVar9 = 0;
        uVar10 = 0;
        do {
          if (piVar6[uVar10] != -1) {
            iVar9 = iVar9 + 1;
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < 4);
        if (iVar9 == 0) {
          iVar8 = 0;
          piVar6 = param_2;
          do {
            uVar10 = 0;
            do {
              if (piVar6[uVar10] == -1) {
                iVar9 = *piVar3;
                goto LAB_006022d4;
              }
              uVar10 = uVar10 + 1;
            } while (uVar10 < 4);
            iVar8 = iVar8 + 1;
            piVar6 = piVar6 + 4;
          } while( true );
        }
        if (piVar6[3] == -1) break;
        iVar8 = iVar8 + 1;
        piVar6 = piVar6 + 4;
      }
      iVar9 = *piVar3;
      uVar10 = 3;
LAB_006022d4:
      iVar8 = FUN_005faf39(param_2,iVar8,uVar10,iVar9);
LAB_006022dd:
      *piVar3 = iVar8;
    }
    else {
      if ((*(byte *)(param_1 + 0x90) & 6) == 0) {
        local_20 = (int *)0xffffffff;
        param_3 = (int *)0x0;
        local_18 = 0;
        local_1c = param_2;
        do {
          local_14 = 0;
          local_10 = 0;
          local_c = 0;
          uVar10 = 0;
          do {
            if (local_1c[uVar10] != -1) {
              local_14 = local_14 + 1;
              uVar7 = 0;
              if (param_4 != (uint *)0x0) {
                do {
                  if (*(double *)(*(int *)(*(int *)(param_1 + 0x14) + local_1c[uVar10] * 4) + 0x10)
                      == *(double *)(*(int *)(*(int *)(param_1 + 0x14) + piVar3[uVar7] * 4) + 0x10))
                  {
                    uVar7 = 1 << ((byte)uVar7 & 0x1f);
                    if ((local_10 & uVar7) == 0) {
                      local_10 = local_10 | uVar7;
                      local_c = local_c + 1;
                    }
                    break;
                  }
                  uVar7 = uVar7 + 1;
                } while (uVar7 < param_4);
              }
            }
            uVar10 = uVar10 + 1;
          } while (uVar10 < 4);
          uVar10 = (int)param_4 - local_c;
          if ((local_14 + uVar10 < 5) && (uVar10 < local_20)) {
            param_3 = (int *)local_18;
            local_20 = (int *)uVar10;
          }
          if (local_14 == 0) {
            uVar10 = 0;
            if (param_4 == (uint *)0x0) {
              return 0;
            }
            local_20 = param_2 + (int)param_3 * 4;
            do {
              local_1c = (int *)0xffffffff;
              uVar7 = 0;
              do {
                if (local_20[uVar7] == -1) {
                  if (local_1c == (int *)0xffffffff) {
                    local_1c = (int *)uVar7;
                  }
                }
                else if (*(double *)
                          (*(int *)(*(int *)(local_8 + 0x14) + local_20[uVar7] * 4) + 0x10) ==
                         *(double *)(*(int *)(*(int *)(local_8 + 0x14) + piVar3[uVar10] * 4) + 0x10)
                        ) {
                  iVar8 = FUN_005faf39(param_2,param_3,uVar7,piVar3[uVar10]);
                  piVar3[uVar10] = iVar8;
                  break;
                }
                uVar7 = uVar7 + 1;
              } while (uVar7 < 4);
              if (uVar7 == 4) {
                iVar8 = FUN_005faf39(param_2,param_3,local_1c,piVar3[uVar10]);
                piVar3[uVar10] = iVar8;
              }
              uVar10 = uVar10 + 1;
              if (param_4 <= uVar10) {
                return 0;
              }
            } while( true );
          }
          local_18 = local_18 + 1;
          local_1c = local_1c + 4;
        } while( true );
      }
      iVar8 = 4;
      do {
        iVar9 = *piVar3;
        *piVar3 = -1;
        *(int *)(((int)local_30 - (int)param_3) + (int)piVar3) = iVar9;
        piVar3 = piVar3 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      uVar10 = 0;
      if (param_4 != (uint *)0x0) {
        do {
          uVar7 = 0;
          do {
            if ((puVar2[uVar10] & 1 << ((byte)uVar7 & 0x1f)) != 0) {
              param_3[uVar7] = local_30[uVar10];
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < 4);
          uVar10 = uVar10 + 1;
        } while (uVar10 < param_4);
      }
      param_4 = (uint *)0x0;
      uVar10 = 0;
      do {
        if (*(int *)((int)puVar2 + local_c) == -1) {
          *puVar2 = 0;
        }
        else {
          param_4 = (uint *)((int)param_4 + 1);
          *puVar2 = 1 << ((byte)uVar10 & 0x1f);
        }
        uVar10 = uVar10 + 1;
        puVar2 = puVar2 + 1;
      } while (uVar10 < 4);
      local_10 = 0xffffffff;
      local_c = 0;
      local_14 = 0;
      iVar8 = (int)param_3 - (int)param_2;
      piVar3 = param_2;
      while( true ) {
        uVar10 = 0;
        local_18 = 0;
        local_1c = (int *)0x0;
        local_20 = (int *)0x4;
        do {
          iVar9 = *piVar3;
          if (iVar9 != -1) {
            local_18 = local_18 + 1;
          }
          if (*(int *)(iVar8 + (int)piVar3) != -1) {
            if (iVar9 == -1) {
              uVar10 = uVar10 + 1;
            }
            else if (*(double *)(*(int *)(*(int *)(local_8 + 0x14) + iVar9 * 4) + 0x10) ==
                     *(double *)
                      (*(int *)(*(int *)(local_8 + 0x14) + *(int *)(iVar8 + (int)piVar3) * 4) + 0x10
                      )) {
              local_1c = (int *)((int)local_1c + 1);
            }
          }
          piVar3 = piVar3 + 1;
          local_20 = (int *)((int)local_20 + -1);
        } while (local_20 != (int *)0x0);
        if (((uint *)((int)local_1c + uVar10) == param_4) && (uVar10 < local_10)) {
          local_c = local_14;
          local_10 = uVar10;
        }
        uVar10 = 0;
        local_20 = (int *)0x0;
        if (local_18 == 0) break;
        local_14 = local_14 + 1;
        iVar8 = iVar8 + -0x10;
      }
      do {
        iVar8 = param_3[uVar10];
        if (iVar8 != -1) {
          iVar8 = FUN_005faf39(param_2,local_c,uVar10,iVar8);
          param_3[uVar10] = iVar8;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < 4);
    }
  }
  return 0;
}


// ==== 0x60254c FUN_0060254c

undefined4 __thiscall FUN_0060254c(int param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  int *piVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  uint uVar13;
  int *piVar14;
  int local_68 [4];
  int local_58 [4];
  undefined4 *local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  int *local_34;
  int *local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  int local_1c;
  uint local_18;
  uint *local_14;
  uint local_10;
  int *local_c;
  uint local_8;
  
  if (param_3 == 0) {
    return 0;
  }
  iVar5 = *(int *)(*(int *)(param_1 + 0x10) + param_2 * 4);
  local_18 = *(uint *)(iVar5 + 0xc);
  iVar3 = *(int *)(param_1 + 8);
  local_14 = (uint *)0x0;
  local_c = (int *)0x0;
  local_34 = (int *)0x0;
  if (iVar3 != 0) {
    puVar12 = *(undefined4 **)(param_1 + 0x14);
    do {
      if ((param_2 == *(int *)*puVar12) && (uVar4 = ((int *)*puVar12)[2], local_34 <= uVar4)) {
        local_34 = (int *)(uVar4 + 1);
      }
      puVar12 = puVar12 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  piVar10 = local_34;
  if (param_4 != 0) {
    *(uint *)(iVar5 + 8) = param_3;
  }
  local_1c = param_1;
  local_48 = _malloc((int)local_34 << 2);
  if (local_48 != (undefined4 *)0x0) {
    puVar12 = local_48;
    for (uVar4 = (uint)piVar10 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
    uVar4 = 0;
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar12 = 0;
      puVar12 = (undefined4 *)((int)puVar12 + 1);
    }
    if (*(int *)(param_1 + 8) != 0) {
      do {
        piVar10 = *(int **)(*(int *)(param_1 + 0x14) + uVar4 * 4);
        if (param_2 == *piVar10) {
          if ((uint)local_48[piVar10[2]] <= (uint)piVar10[3]) {
            local_48[piVar10[2]] = piVar10[3] + 1;
          }
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(param_1 + 8));
    }
    local_14 = _malloc(param_3 << 4);
    if ((local_14 != (uint *)0x0) && (local_c = _malloc(param_3 << 2), local_c != (int *)0x0)) {
      puVar9 = local_14;
      for (iVar5 = (param_3 & 0xfffffff) << 2; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined1 *)puVar9 = 0;
        puVar9 = (uint *)((int)puVar9 + 1);
      }
      uVar4 = 0;
      if (param_3 != 0) {
        uVar13 = 0;
        do {
          uVar6 = uVar13 % param_3;
          uVar13 = uVar13 + 7;
          local_c[uVar4] = uVar6;
          uVar4 = uVar4 + 1;
        } while (uVar4 < param_3);
      }
      FUN_005fb8ae();
      uVar4 = 0;
      if (*(int *)(param_1 + 8) != 0) {
        do {
          *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + uVar4 * 4) + 0x1c) = 0xffffffff;
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint *)(param_1 + 8));
      }
      local_8 = 0;
      if (*(int *)(param_1 + 0xc) != 0) {
        do {
          iVar5 = *(int *)(*(int *)(param_1 + 0x18) + local_8 * 4);
          if (param_4 == 0) {
            local_34 = (int *)0x0;
            if ((local_8 != 0) && (param_3 != 0)) {
              local_3c = param_3;
              puVar9 = local_14;
              do {
                uVar4 = 0;
                puVar2 = puVar9;
                do {
                  if (local_8 <= *puVar2) {
                    local_34 = (int *)((int)local_34 + 1);
                    break;
                  }
                  uVar4 = uVar4 + 1;
                  puVar2 = puVar2 + 1;
                } while (uVar4 < 4);
                puVar9 = puVar9 + 4;
                local_3c = local_3c - 1;
              } while (local_3c != 0);
            }
            *(int **)(iVar5 + 0x24) = local_34;
            *(int **)(iVar5 + 0x2c) = local_34;
          }
          local_20 = iVar5;
          iVar3 = FUN_005f7a96();
          if (iVar3 == 0) {
            FUN_005f7b45();
            local_2c = 0;
            iVar3 = FUN_005f7aa3();
            if (iVar3 != 0) {
              if ((*(byte *)(param_1 + 0x90) & 6) != 0) {
                local_30 = (int *)0x0;
                local_2c = 0;
                if (*(int *)(iVar5 + 0xc) != 0) {
                  local_34 = *(int **)(iVar5 + 8);
                  iVar3 = *(int *)(param_1 + 0x14);
                  local_44 = *(uint *)(*(int *)(iVar3 + *local_34 * 4) + 0xc);
                  iVar7 = *(int *)(iVar5 + 0x10) - (int)local_34;
                  local_3c = *(uint *)(iVar5 + 0xc);
                  do {
                    uVar4 = *(uint *)(*(int *)(iVar3 + *local_34 * 4) + 0xc);
                    if (*(uint *)(*(int *)(iVar3 + *(int *)(iVar7 + (int)local_34) * 4) + 0xc) ==
                        uVar4) {
                      local_30 = (int *)((int)local_30 + 1);
                    }
                    if (local_44 == uVar4) {
                      local_2c = local_2c + 1;
                    }
                    local_34 = local_34 + 1;
                    local_3c = local_3c - 1;
                  } while (local_3c != 0);
                }
                if ((local_30 < (int *)(*(int *)(iVar5 + 0xc) - 1U)) &&
                   (local_2c != *(int *)(iVar5 + 0xc))) {
                  local_2c = 0;
                  goto LAB_006027bb;
                }
              }
              local_2c = 1;
            }
LAB_006027bb:
            local_34 = (int *)0x0;
            if (*(int *)(iVar5 + 0xc) != 0) {
              do {
                local_30 = *(int **)(*(int *)(param_1 + 0x14) +
                                    *(int *)((int)local_34 * 4 + *(int *)(iVar5 + 0x10)) * 4);
                if (param_2 == *local_30) {
                  if (local_30[7] == -1) {
                    if (((local_2c != 0) &&
                        (piVar10 = *(int **)(*(int *)(param_1 + 0x14) +
                                            *(int *)((int)local_34 * 4 + *(int *)(local_20 + 8)) * 4
                                            ), param_2 == *piVar10)) && (piVar10[7] != -1)) {
                      uVar4 = 0;
                      if (param_3 != 0) {
                        do {
                          if (local_c[uVar4] == piVar10[7]) break;
                          uVar4 = uVar4 + 1;
                        } while (uVar4 < param_3);
                      }
                      for (; uVar4 != 0; uVar4 = uVar4 - 1) {
                        local_c[uVar4] = local_c[uVar4 - 1];
                      }
                      *local_c = piVar10[7];
                    }
                    local_40 = local_48[local_30[2]];
                    uVar4 = ~-(uint)(1 < local_40) & local_18 - 1;
                    local_44 = local_30[0xf];
                    local_38 = 0xffffffff;
                    iVar5 = (-(uint)(1 < local_40) & 2) - 1;
                    local_3c = 0;
                    if (local_44 <= (uint)local_30[0xb]) {
                      local_44 = local_30[0xb] + 1;
                    }
                    local_28 = 0;
                    if (param_3 != 0) {
                      do {
                        iVar3 = local_c[local_28];
                        uVar13 = 0;
                        local_10 = 0;
                        local_24 = 0;
                        if (local_18 != 0) {
                          do {
                            uVar6 = local_24;
                            if (local_40 <= local_24) goto LAB_0060293a;
                            if (local_18 <= uVar13) break;
                            puVar9 = local_14 + uVar4 + uVar13 * iVar5 + iVar3 * 4;
                            do {
                              if (*puVar9 <= local_8) break;
                              uVar13 = uVar13 + 1;
                              puVar9 = puVar9 + iVar5;
                            } while (uVar13 < local_18);
                            if (local_18 <= uVar13) break;
                            local_58[local_24] = uVar13 * iVar5 + uVar4;
                            local_10 = local_10 + (uVar13 - uVar6) * 0x1000000;
                            uVar13 = uVar13 + 1;
                            local_24 = local_24 + 1;
                          } while (uVar13 < local_18);
                        }
                        if (local_40 <= local_24) {
LAB_0060293a:
                          if (local_18 != 0) {
                            puVar9 = local_14 + iVar3 * 4;
                            uVar13 = local_18;
                            do {
                              if (local_8 < *puVar9) {
                                uVar6 = *puVar9 - local_44;
                                uVar8 = (int)uVar6 >> 0x1f;
                                local_10 = local_10 + ((uVar6 ^ uVar8) - uVar8);
                              }
                              else {
                                local_10 = local_10 + 0x10000;
                              }
                              puVar9 = puVar9 + 1;
                              uVar13 = uVar13 - 1;
                            } while (uVar13 != 0);
                          }
                          if (local_10 < local_38) {
                            local_68[0] = local_58[0];
                            local_68[1] = local_58[1];
                            local_68[2] = local_58[2];
                            local_3c = local_28;
                            local_38 = local_10;
                            local_68[3] = local_58[3];
                            if (local_10 == 0) break;
                          }
                        }
                        local_28 = local_28 + 1;
                      } while (local_28 < param_3);
                      if (local_38 != 0xffffffff) {
                        piVar10 = local_c + local_3c;
                        iVar5 = *piVar10;
                        if (local_3c < param_3 - 1) {
                          piVar14 = piVar10;
                          for (iVar3 = (param_3 - 1) - local_3c; piVar10 = piVar10 + 1, iVar3 != 0;
                              iVar3 = iVar3 + -1) {
                            *piVar14 = *piVar10;
                            piVar14 = piVar14 + 1;
                          }
                        }
                        local_c[param_3 - 1] = iVar5;
                        uVar4 = 0;
                        if (*(int *)(local_1c + 8) != 0) {
                          do {
                            iVar3 = uVar4 * 4;
                            piVar10 = *(int **)(iVar3 + *(int *)(local_1c + 0x14));
                            if (((param_2 == *piVar10) && (piVar10[2] == local_30[2])) &&
                               ((iVar7 = FUN_005f7b57(), iVar7 != 0 ||
                                (local_8 <=
                                 *(uint *)(*(int *)(iVar3 + *(int *)(local_1c + 0x14)) + 0x3c))))) {
                              iVar7 = *(int *)(iVar3 + *(int *)(local_1c + 0x14));
                              iVar1 = local_68[*(int *)(iVar7 + 0xc)];
                              *(int *)(iVar7 + 0x1c) = iVar5;
                              if (param_4 != 0) {
                                *(int *)(*(int *)(iVar3 + *(int *)(local_1c + 0x14)) + 0xc) = iVar1;
                              }
                              iVar3 = *(int *)(iVar3 + *(int *)(local_1c + 0x14));
                              uVar13 = *(uint *)(iVar3 + 0x3c);
                              uVar6 = *(int *)(iVar3 + 0x2c) + 1;
                              if (uVar6 < uVar13) {
                                uVar6 = uVar13;
                              }
                              local_14[iVar1 + iVar5 * 4] = uVar6;
                            }
                            uVar4 = uVar4 + 1;
                          } while (uVar4 < *(uint *)(local_1c + 8));
                        }
                        goto LAB_00602a5c;
                      }
                    }
                    FUN_005fbec8(local_1c,*(undefined4 *)(local_20 + 0x34),0xfa4,
                                 "expression too complex");
                    uVar11 = 0x80004005;
                    goto LAB_00602b01;
                  }
                  uVar4 = 0;
                  if (param_3 != 0) {
                    do {
                      if (local_c[uVar4] == local_30[7]) break;
                      uVar4 = uVar4 + 1;
                    } while (uVar4 < param_3);
                  }
                  if (uVar4 < param_3 - 1) {
                    piVar10 = local_c + uVar4;
                    piVar14 = piVar10;
                    for (iVar5 = (param_3 - 1) - uVar4; piVar10 = piVar10 + 1, iVar5 != 0;
                        iVar5 = iVar5 + -1) {
                      *piVar14 = *piVar10;
                      piVar14 = piVar14 + 1;
                    }
                  }
                  local_c[param_3 - 1] = local_30[7];
                }
LAB_00602a5c:
                local_34 = (int *)((int)local_34 + 1);
                param_1 = local_1c;
                iVar5 = local_20;
              } while (local_34 < *(uint *)(local_20 + 0xc));
            }
            if (param_4 == 0) {
              local_3c = 0;
              if (param_3 != 0) {
                local_44 = param_3;
                puVar9 = local_14;
                do {
                  uVar4 = 0;
                  puVar2 = puVar9;
                  do {
                    if (local_8 < *puVar2) {
                      local_3c = local_3c + 1;
                      break;
                    }
                    uVar4 = uVar4 + 1;
                    puVar2 = puVar2 + 1;
                  } while (uVar4 < 4);
                  puVar9 = puVar9 + 4;
                  local_44 = local_44 - 1;
                } while (local_44 != 0);
              }
              *(uint *)(iVar5 + 0x2c) = local_3c;
            }
          }
          local_8 = local_8 + 1;
        } while (local_8 < *(uint *)(param_1 + 0xc));
      }
      if ((param_4 != 0) && (uVar4 = 0, *(int *)(param_1 + 8) != 0)) {
        do {
          piVar10 = *(int **)(*(int *)(param_1 + 0x14) + uVar4 * 4);
          if (param_2 == *piVar10) {
            if (piVar10[7] == -1) {
              *piVar10 = *(int *)(param_1 + 0x4c);
            }
            else {
              piVar10[2] = piVar10[7];
            }
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint *)(param_1 + 8));
      }
      uVar11 = 0;
      goto LAB_00602b01;
    }
  }
  uVar11 = 0x8007000e;
LAB_00602b01:
  _free(local_48);
  _free(local_14);
  _free(local_c);
  return uVar11;
}


// ==== 0x602b25 FUN_00602b25

int __thiscall FUN_00602b25(int *param_1,undefined4 *param_2)

{
  int iVar1;
  
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  iVar1 = (**(code **)(*param_1 + 0x14))();
  if ((((-1 < iVar1) && (iVar1 = FUN_005f8040(), -1 < iVar1)) &&
      (iVar1 = FUN_005fc5a6(), -1 < iVar1)) && (iVar1 = FUN_005fede4(), -1 < iVar1)) {
    if (((*(byte *)(param_1 + 0xd) & 8) == 0) &&
       (iVar1 = (**(code **)(*param_1 + 0x18))(), iVar1 < 0)) {
      return iVar1;
    }
    param_1[0xf] = 1;
    iVar1 = (**(code **)(*param_1 + 0x1c))();
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ==== 0x602b94 FUN_00602b94

int __fastcall FUN_00602b94(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  int local_48 [5];
  uint local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int local_20;
  uint local_1c;
  int *local_18;
  int *local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_8 = 0;
  FUN_005fbe17();
  FUN_005fb8ae();
  local_20 = -1;
  local_10 = -1;
  local_1c = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + local_1c * 4);
      iVar2 = FUN_005f7a96();
      if (iVar2 == 0) {
        local_18 = *(int **)(param_1 + 8);
        iVar2 = FUN_005f7b0f();
        if (iVar2 == 0) {
          iVar2 = FUN_005f7b21();
          if (iVar2 == 0) {
            iVar2 = FUN_005f7b33();
            if (iVar2 == 0) {
              iVar2 = FUN_005f7ac7();
              if (iVar2 == 0) {
                if (*puVar1 == 0x33000004) {
                  iVar2 = *(int *)(param_1 + 0x14);
                  local_48[2] = -1;
                  local_48[1] = -1;
                  local_48[3] = 1;
                  local_48[0] = 1;
                  piVar10 = (int *)puVar1[2];
                  piVar9 = *(int **)(iVar2 + *piVar10 * 4);
                  local_14 = *(int **)(iVar2 + piVar10[3] * 4);
                  local_18 = *(int **)(iVar2 + piVar10[1] * 4);
                  iVar7 = *(int *)(param_1 + 0x10);
                  if (((*(byte *)(*(int *)(iVar7 + *piVar9 * 4) + 4) & 0x80) == 0) ||
                     (piVar9[1] != -1)) {
                    if (*(int *)(*(int *)(iVar2 + *(int *)(puVar1[4] + 4) * 4) + 0x40) == 0) {
                      local_48[1] = 0;
                    }
LAB_0060342f:
                    if (*(int *)(*(int *)(iVar2 + *(int *)(puVar1[4] + 8) * 4) + 0x40) == 0) {
                      local_48[2] = 0;
                    }
                    if ((local_48[1] == -1) || (local_48[2] == -1)) goto LAB_00603550;
                  }
                  else if (*(double *)(piVar9 + 4) <= 0.0) {
                    local_48[1] = 0;
LAB_00603416:
                    local_48[2] = 0;
                  }
                  else {
                    local_48[1] = 2;
                    if (((*(byte *)(*(int *)(iVar7 + *local_18 * 4) + 4) & 0x80) == 0) ||
                       (local_18[1] != -1)) goto LAB_0060342f;
                    if (*(double *)(local_18 + 4) <= 0.0) goto LAB_00603416;
                    if (((*(byte *)(*(int *)(iVar7 + *local_14 * 4) + 4) & 0x80) == 0) ||
                       (local_14[1] != -1)) goto LAB_0060342f;
                    if (*(double *)(local_14 + 4) == 0.0) {
                      local_48[2] = 1;
                    }
                    else {
                      if (*(double *)(local_14 + 4) != 1.0) goto LAB_0060342f;
                      local_48[2] = 3;
                    }
                  }
                  uVar5 = 0;
                  do {
                    iVar2 = *(int *)((int)local_48 + uVar5);
                    if (iVar2 == 0) {
                      if (local_10 == -1) {
                        local_10 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x50),0,0,0);
                        *(int *)(*(int *)(*(int *)(param_1 + 0x14) + local_10 * 4) + 0x1c) =
                             local_10;
                      }
                      iVar2 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)(uVar5 + puVar1[4]) * 4);
                      iVar7 = local_10;
LAB_006034fa:
                      *(int *)(iVar2 + 0x1c) = iVar7;
                    }
                    else {
                      if (iVar2 == 1) {
                        if (local_20 == -1) {
                          local_20 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x50),0,0,
                                                  0x3ff0000000000000);
                          *(int *)(*(int *)(*(int *)(param_1 + 0x14) + local_20 * 4) + 0x1c) =
                               local_20;
                        }
                        iVar2 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)(uVar5 + puVar1[4]) * 4)
                        ;
                        iVar7 = local_20;
                        goto LAB_006034fa;
                      }
                      if (iVar2 == 2) {
                        uVar6 = *(undefined4 *)puVar1[2];
LAB_00603474:
                        *(undefined4 *)
                         (*(int *)(*(int *)(param_1 + 0x14) + *(int *)(uVar5 + puVar1[4]) * 4) +
                         0x1c) = uVar6;
                      }
                      else if (iVar2 == 3) {
                        uVar6 = *(undefined4 *)(puVar1[2] + 4);
                        goto LAB_00603474;
                      }
                    }
                    iVar2 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)(uVar5 + puVar1[4]) * 4);
                    iVar7 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar2 + 0x1c) * 4);
                    if (*(int *)(iVar7 + 0x44) == 0) {
                      *(undefined4 *)(iVar7 + 0x44) = *(undefined4 *)(iVar2 + 0x44);
                      iVar2 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)(uVar5 + puVar1[4]) * 4);
                      *(undefined4 *)
                       (*(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar2 + 0x1c) * 4) + 0x48) =
                           *(undefined4 *)(iVar2 + 0x48);
                    }
                    uVar5 = uVar5 + 4;
                  } while (uVar5 < 0x10);
                  goto LAB_0060353f;
                }
              }
              else {
                iVar2 = FUN_005f974c(puVar1,1);
                if (iVar2 < 0) {
                  return iVar2;
                }
                if (iVar2 != 1) {
                  local_8 = 1;
                }
                iVar2 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)puVar1[4] * 4);
                iVar7 = *(int *)(iVar2 + 0x1c);
                if (iVar7 != *(int *)puVar1[4]) {
                  iVar7 = *(int *)(*(int *)(param_1 + 0x14) + iVar7 * 4);
                  if (*(int *)(iVar7 + 0x44) == 0) {
                    *(undefined4 *)(iVar7 + 0x44) = *(undefined4 *)(iVar2 + 0x44);
                    iVar2 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)puVar1[4] * 4);
                    *(undefined4 *)
                     (*(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar2 + 0x1c) * 4) + 0x48) =
                         *(undefined4 *)(iVar2 + 0x48);
                  }
                  *puVar1 = 0;
                  puVar1[1] = 0;
                  puVar1[3] = 0;
                }
              }
            }
            else {
              local_14 = (int *)0x0;
              local_c = 0;
              if (puVar1[3] != 0) {
                do {
                  uVar5 = *(uint *)(puVar1[4] + local_c * 4);
                  uVar3 = puVar1[2];
                  iVar2 = *(int *)(param_1 + 0x14);
                  local_48[4] = *(int *)(*(int *)(iVar2 + *(int *)(uVar3 + local_c * 4) * 4) + 0x1c)
                  ;
                  local_24 = *(int **)(*(int *)(iVar2 + *(int *)(uVar3 + (local_c + puVar1[3]) * 4)
                                                        * 4) + 0x1c);
                  local_28 = *(int **)(*(int *)(iVar2 + *(int *)(uVar3 + (local_c + puVar1[3] * 2) *
                                                                         4) * 4) + 0x1c);
                  if ((*puVar1 & 0xff000000) == 0x50000000) {
                    local_30 = *(int **)(iVar2 + (int)local_24 * 4);
                    local_2c = *(int **)(iVar2 + (int)local_28 * 4);
                    uVar3 = local_30[6];
                    uVar4 = local_2c[6] | uVar3;
                    uVar8 = uVar4 & 0xe000000;
                    if ((uVar4 & 0x8000000) == 0) {
                      if ((uVar4 & 0x4000000) == 0) {
                        if ((uVar4 & 0x2000000) != 0) {
                          uVar8 = 0x2000000;
                        }
                      }
                      else {
                        uVar8 = 0x4000000;
                      }
                    }
                    else {
                      uVar8 = 0x8000000;
                    }
                    uVar8 = uVar8 | *(uint *)(*(int *)(iVar2 + uVar5 * 4) + 0x18) & 0xe000000;
                    uVar4 = 0x2000000;
                    if ((((uVar8 & 0x2000000) == 0) && (uVar4 = 0x4000000, (uVar8 & 0x4000000) == 0)
                        ) && (uVar4 = uVar8, (uVar8 & 0x8000000) != 0)) {
                      uVar4 = 0x8000000;
                    }
                    if (((uVar4 != (uVar3 & 0xe000000)) &&
                        ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *local_30 * 4) + 4) & 2) !=
                         0)) && (local_30[0x10] == 1)) {
                      local_30[6] = uVar3 & 0xf1ffffff | uVar4;
                      local_8 = 1;
                    }
                    if (((uVar4 != (local_2c[6] & 0xe000000U)) &&
                        ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *local_2c * 4) + 4) & 2) !=
                         0)) && (local_2c[0x10] == 1)) {
                      local_2c[6] = local_2c[6] & 0xf1ffffffU | uVar4;
                      local_8 = 1;
                    }
                  }
                  local_34 = uVar5;
                  iVar2 = FUN_005f91a4(puVar1,uVar5,local_48[4],local_24,local_28);
                  if (iVar2 < 0) {
                    return iVar2;
                  }
                  uVar3 = *(uint *)(*(int *)(*(int *)(param_1 + 0x14) + uVar5 * 4) + 0x1c);
                  if (uVar3 == uVar5) {
                    local_14 = (int *)((int)local_14 + 1);
                  }
                  else {
                    iVar2 = *(int *)(*(int *)(param_1 + 0x14) + uVar3 * 4);
                    if (*(int *)(iVar2 + 0x1c) == -1) {
                      *(uint *)(iVar2 + 0x1c) = uVar3;
                    }
                  }
                  local_c = local_c + 1;
                } while (local_c < puVar1[3]);
              }
              piVar10 = (int *)puVar1[3];
              if (local_14 != piVar10) {
                uVar5 = 0;
                if (local_14 == (int *)0x0) {
                  if (piVar10 != (int *)0x0) {
                    do {
                      iVar2 = *(int *)(*(int *)(param_1 + 0x14) +
                                      *(int *)(puVar1[4] + uVar5 * 4) * 4);
                      iVar7 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar2 + 0x1c) * 4);
                      if (*(int *)(iVar7 + 0x44) == 0) {
                        *(undefined4 *)(iVar7 + 0x44) = *(undefined4 *)(iVar2 + 0x44);
                        iVar2 = *(int *)(*(int *)(param_1 + 0x14) +
                                        *(int *)(puVar1[4] + uVar5 * 4) * 4);
                        *(undefined4 *)
                         (*(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar2 + 0x1c) * 4) + 0x48) =
                             *(undefined4 *)(iVar2 + 0x48);
                      }
                      uVar5 = uVar5 + 1;
                    } while (uVar5 < puVar1[3]);
                  }
                  goto LAB_0060353f;
                }
                local_14 = (int *)0x0;
                if (piVar10 != (int *)0x0) {
                  do {
                    local_34 = *(uint *)(puVar1[4] + (int)local_14 * 4);
                    local_48[4] = local_34 * 4;
                    iVar2 = *(int *)(*(int *)(param_1 + 0x14) + local_48[4]);
                    if (*(uint *)(iVar2 + 0x1c) != local_34) {
                      uVar5 = *(uint *)(*(int *)(*(int *)(param_1 + 0x14) +
                                                *(uint *)(iVar2 + 0x1c) * 4) + 0x18) & 0xf1ffffff |
                              *(uint *)(iVar2 + 0x18);
                      if (*(uint *)(iVar2 + 0x18) != uVar5) {
                        *(uint *)(iVar2 + 0x18) = uVar5;
                        local_8 = 1;
                      }
                      *(uint *)(*(int *)(*(int *)(param_1 + 0x14) + local_48[4]) + 0x1c) = local_34;
                    }
                    local_14 = (int *)((int)local_14 + 1);
                  } while (local_14 < (int *)puVar1[3]);
                }
                piVar10 = local_18;
                if (local_18 < *(int **)(param_1 + 8)) {
                  do {
                    if (*(int *)(*(int *)(param_1 + 0x14) + (int)piVar10 * 4) != 0) {
                      FUN_005f716a();
                    }
                    piVar10 = (int *)((int)piVar10 + 1);
                  } while (piVar10 < *(int **)(param_1 + 8));
                }
                *(int **)(param_1 + 8) = local_18;
              }
            }
          }
          else {
            local_14 = (int *)0x0;
            local_c = 0;
            if (puVar1[3] != 0) {
              do {
                uVar5 = *(uint *)(local_c * 4 + puVar1[4]);
                iVar2 = *(int *)(param_1 + 0x14);
                local_30 = *(int **)(*(int *)(iVar2 + *(int *)(local_c * 4 + puVar1[2]) * 4) + 0x1c)
                ;
                local_2c = *(int **)(*(int *)(iVar2 + *(int *)(puVar1[2] + (puVar1[3] + local_c) * 4
                                                              ) * 4) + 0x1c);
                if (((*puVar1 & 0xff000000) == 0x20000000) || ((*puVar1 & 0xff000000) == 0x21000000)
                   ) {
                  local_24 = *(int **)(iVar2 + (int)local_30 * 4);
                  local_28 = *(int **)(iVar2 + (int)local_2c * 4);
                  uVar3 = local_24[6];
                  uVar4 = local_28[6] | uVar3;
                  uVar8 = uVar4 & 0xe000000;
                  if ((uVar4 & 0x8000000) == 0) {
                    if ((uVar4 & 0x4000000) == 0) {
                      if ((uVar4 & 0x2000000) != 0) {
                        uVar8 = 0x2000000;
                      }
                    }
                    else {
                      uVar8 = 0x4000000;
                    }
                  }
                  else {
                    uVar8 = 0x8000000;
                  }
                  uVar8 = uVar8 | *(uint *)(*(int *)(iVar2 + uVar5 * 4) + 0x18) & 0xe000000;
                  uVar4 = 0x2000000;
                  if ((((uVar8 & 0x2000000) == 0) && (uVar4 = 0x4000000, (uVar8 & 0x4000000) == 0))
                     && (uVar4 = uVar8, (uVar8 & 0x8000000) != 0)) {
                    uVar4 = 0x8000000;
                  }
                  if (((uVar4 != (uVar3 & 0xe000000)) &&
                      ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *local_24 * 4) + 4) & 2) != 0)
                      ) && (local_24[0x10] == 1)) {
                    local_24[6] = uVar3 & 0xf1ffffff | uVar4;
                    local_8 = 1;
                  }
                  if (((uVar4 != (local_28[6] & 0xe000000U)) &&
                      ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *local_28 * 4) + 4) & 2) != 0)
                      ) && (local_28[0x10] == 1)) {
                    local_28[6] = local_28[6] & 0xf1ffffffU | uVar4;
                    local_8 = 1;
                  }
                }
                local_34 = uVar5;
                iVar2 = FUN_005f84ab(puVar1,uVar5,local_30,local_2c);
                if (iVar2 < 0) {
                  return iVar2;
                }
                uVar3 = *(uint *)(*(int *)(*(int *)(param_1 + 0x14) + uVar5 * 4) + 0x1c);
                if (uVar3 == uVar5) {
                  local_14 = (int *)((int)local_14 + 1);
                }
                else {
                  iVar2 = *(int *)(*(int *)(param_1 + 0x14) + uVar3 * 4);
                  if (*(int *)(iVar2 + 0x1c) == -1) {
                    *(uint *)(iVar2 + 0x1c) = uVar3;
                  }
                }
                local_c = local_c + 1;
              } while (local_c < puVar1[3]);
            }
            piVar10 = (int *)puVar1[3];
            if (local_14 != piVar10) {
              uVar5 = 0;
              if (local_14 == (int *)0x0) {
                if (piVar10 != (int *)0x0) {
                  do {
                    iVar2 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)(puVar1[4] + uVar5 * 4) * 4)
                    ;
                    iVar7 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar2 + 0x1c) * 4);
                    if (*(int *)(iVar7 + 0x44) == 0) {
                      *(undefined4 *)(iVar7 + 0x44) = *(undefined4 *)(iVar2 + 0x44);
                      iVar2 = *(int *)(*(int *)(param_1 + 0x14) +
                                      *(int *)(puVar1[4] + uVar5 * 4) * 4);
                      *(undefined4 *)
                       (*(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar2 + 0x1c) * 4) + 0x48) =
                           *(undefined4 *)(iVar2 + 0x48);
                    }
                    uVar5 = uVar5 + 1;
                  } while (uVar5 < puVar1[3]);
                }
LAB_0060353f:
                uVar5 = 0;
                puVar1[1] = 0;
                puVar1[3] = 0;
                goto LAB_00603547;
              }
              local_14 = (int *)0x0;
              if (piVar10 != (int *)0x0) {
                do {
                  local_30 = *(int **)(puVar1[4] + (int)local_14 * 4);
                  local_34 = (int)local_30 * 4;
                  iVar2 = *(int *)(local_34 + *(int *)(param_1 + 0x14));
                  if (*(int **)(iVar2 + 0x1c) != local_30) {
                    uVar5 = *(uint *)(*(int *)(*(int *)(param_1 + 0x14) +
                                              (int)*(int **)(iVar2 + 0x1c) * 4) + 0x18) & 0xf1ffffff
                            | *(uint *)(iVar2 + 0x18);
                    if (*(uint *)(iVar2 + 0x18) != uVar5) {
                      *(uint *)(iVar2 + 0x18) = uVar5;
                      local_8 = 1;
                    }
                    *(int **)(*(int *)(local_34 + *(int *)(param_1 + 0x14)) + 0x1c) = local_30;
                  }
                  local_14 = (int *)((int)local_14 + 1);
                } while (local_14 < (int *)puVar1[3]);
              }
              piVar10 = local_18;
              piVar9 = local_18;
              if (local_18 < *(int **)(param_1 + 8)) {
                do {
                  if (*(int *)(*(int *)(param_1 + 0x14) + (int)piVar9 * 4) != 0) {
                    FUN_005f716a();
                    piVar10 = local_18;
                  }
                  piVar9 = (int *)((int)piVar9 + 1);
                } while (piVar9 < *(int **)(param_1 + 8));
              }
              *(int **)(param_1 + 8) = piVar10;
            }
          }
        }
        else {
          local_c = 0;
          local_14 = (int *)0x0;
          if (puVar1[3] != 0) {
            do {
              piVar10 = *(int **)((int)local_14 * 4 + puVar1[4]);
              local_18 = *(int **)(*(int *)(*(int *)(param_1 + 0x14) +
                                           *(int *)((int)local_14 * 4 + puVar1[2]) * 4) + 0x1c);
              local_30 = piVar10;
              iVar2 = FUN_005f7aa3();
              if ((iVar2 != 0) || (iVar2 = FUN_005f7ab5(), iVar2 != 0)) {
                iVar2 = *(int *)(*(int *)(param_1 + 0x14) + (int)piVar10 * 4);
                piVar10 = *(int **)(*(int *)(param_1 + 0x14) + (int)local_18 * 4);
                uVar5 = *(uint *)(iVar2 + 0x18);
                uVar3 = piVar10[6] | uVar5;
                uVar4 = uVar3 & 0xe000000;
                if ((uVar3 & 0x2000000) == 0) {
                  uVar8 = 0x4000000;
                  if (((uVar3 & 0x4000000) != 0) || (uVar8 = 0x8000000, (uVar3 & 0x8000000) != 0)) {
                    uVar4 = uVar8;
                  }
                }
                else {
                  uVar4 = 0x2000000;
                }
                if (uVar4 != (uVar5 & 0xe000000)) {
                  *(uint *)(iVar2 + 0x18) = uVar5 & 0xf1ffffff | uVar4;
                  local_8 = 1;
                }
                local_34 = piVar10[6];
                if (((uVar4 != (local_34 & 0xe000000)) &&
                    ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar10 * 4) + 4) & 2) != 0))
                   && (piVar10[0x10] == 1)) {
                  piVar10[6] = local_34 & 0xf1ffffff | uVar4;
                  local_8 = 1;
                }
              }
              piVar10 = local_30;
              iVar2 = FUN_005fefac(puVar1,local_30,local_18);
              if (iVar2 < 0) {
                return iVar2;
              }
              piVar9 = *(int **)(*(int *)(*(int *)(param_1 + 0x14) + (int)piVar10 * 4) + 0x1c);
              if (piVar9 == piVar10) {
                local_c = local_c + 1;
              }
              else {
                iVar2 = *(int *)(*(int *)(param_1 + 0x14) + (int)piVar9 * 4);
                if (*(int *)(iVar2 + 0x1c) == -1) {
                  *(int **)(iVar2 + 0x1c) = piVar9;
                }
              }
              local_14 = (int *)((int)local_14 + 1);
            } while (local_14 < (int *)puVar1[3]);
          }
          if (local_c == puVar1[3]) goto LAB_00603550;
          local_8 = 0;
          local_c = 0;
          if (puVar1[3] == 0) {
LAB_00602daa:
            uVar5 = 0;
          }
          else {
            do {
              iVar2 = *(int *)(puVar1[4] + local_8 * 4);
              iVar7 = *(int *)(param_1 + 0x14);
              if (*(int *)(*(int *)(iVar7 + iVar2 * 4) + 0x1c) == iVar2) {
                iVar7 = local_c * 4;
                local_c = local_c + 1;
                *(int *)(iVar7 + puVar1[4]) = iVar2;
                *(undefined4 *)(iVar7 + puVar1[2]) = *(undefined4 *)(puVar1[2] + local_8 * 4);
              }
              else {
                iVar2 = *(int *)(iVar7 + iVar2 * 4);
                iVar7 = *(int *)(iVar7 + *(int *)(iVar2 + 0x1c) * 4);
                if (*(int *)(iVar7 + 0x44) == 0) {
                  *(undefined4 *)(iVar7 + 0x44) = *(undefined4 *)(iVar2 + 0x44);
                  iVar2 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)(puVar1[4] + local_8 * 4) * 4)
                  ;
                  *(undefined4 *)
                   (*(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar2 + 0x1c) * 4) + 0x48) =
                       *(undefined4 *)(iVar2 + 0x48);
                }
              }
              local_8 = local_8 + 1;
            } while (local_8 < puVar1[3]);
            if (local_c == 0) goto LAB_00602daa;
            uVar5 = (*puVar1 ^ local_c) & 0xffffff ^ *puVar1;
          }
          puVar1[1] = local_c;
          puVar1[3] = local_c;
LAB_00603547:
          *puVar1 = uVar5;
          local_8 = 1;
        }
LAB_00603550:
        if (puVar1[3] != 0) {
          local_18 = (int *)0x0;
          if (puVar1[3] != 0) {
            piVar10 = (int *)puVar1[4];
            do {
              piVar9 = *(int **)(*(int *)(param_1 + 0x14) + *piVar10 * 4);
              uVar5 = piVar9[6];
              if ((((uVar5 & 0x40) != 0) ||
                  ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar9 * 4) + 4) & 0x10) != 0))
                 || (((uVar5 & 4) == 0 || ((uVar5 & 8) == 0)))) break;
              local_18 = (int *)((int)local_18 + 1);
              piVar10 = piVar10 + 1;
            } while (local_18 < (int *)puVar1[3]);
          }
          if (local_18 == (int *)puVar1[3]) {
            if (local_10 == -1) {
              local_10 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x50),0,0,0);
              *(int *)(*(int *)(*(int *)(param_1 + 0x14) + local_10 * 4) + 0x1c) = local_10;
            }
            uVar5 = 0;
            if (puVar1[3] != 0) {
              do {
                iVar2 = uVar5 * 4;
                uVar5 = uVar5 + 1;
                *(int *)(*(int *)(*(int *)(param_1 + 0x14) + *(int *)(puVar1[4] + iVar2) * 4) + 0x1c
                        ) = local_10;
              } while (uVar5 < puVar1[3]);
            }
            *puVar1 = 0;
            puVar1[1] = 0;
            puVar1[3] = 0;
            local_8 = 1;
          }
        }
      }
      local_1c = local_1c + 1;
    } while (local_1c < *(uint *)(param_1 + 0xc));
    if (local_8 != 0) {
      FUN_005fbe30();
      return 0;
    }
  }
  return 1;
}


// ==== 0x603622 FUN_00603622

undefined4 __fastcall FUN_00603622(int param_1)

{
  byte *pbVar1;
  uint *puVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  uint local_54 [8];
  uint *local_34;
  int local_30;
  uint *local_2c;
  int local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  uint *local_18;
  uint local_14;
  uint *local_10;
  undefined4 *local_c;
  uint local_8;
  
  iVar6 = *(int *)(param_1 + 4);
  puVar7 = (uint *)0x0;
  local_18 = (uint *)0x0;
  if (iVar6 != 0) {
    piVar4 = *(int **)(param_1 + 0x10);
    do {
      uVar9 = *(uint *)(*piVar4 + 4);
      if (((char)uVar9 < '\0') && ((uVar9 & 0x200) != 0)) {
        puVar7 = (uint *)((int)puVar7 + *(int *)(*piVar4 + 8));
      }
      piVar4 = piVar4 + 1;
      iVar6 = iVar6 + -1;
      local_18 = puVar7;
    } while (iVar6 != 0);
  }
  uVar9 = (int)local_18 + *(int *)(param_1 + 0xc) * 2;
  local_c = _malloc(uVar9 * 0x10);
  if (local_c == (undefined4 *)0x0) {
    uVar3 = 0x8007000e;
  }
  else {
    puVar8 = local_c;
    for (iVar6 = (uVar9 & 0xfffffff) << 2; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar8 = 0xffffffff;
      puVar8 = puVar8 + 1;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined1 *)puVar8 = 0xff;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    local_24 = 0;
    local_20 = 0;
    FUN_005fbe17();
    local_14 = 0;
    if (*(int *)(param_1 + 4) != 0) {
      do {
        uVar9 = *(uint *)(*(int *)(*(int *)(param_1 + 0x10) + local_14 * 4) + 4);
        if (((char)uVar9 < '\0') && ((uVar9 & 0x200) != 0)) {
          local_10 = (uint *)0x0;
          if (local_18 != (uint *)0x0) {
            uVar9 = *(uint *)(param_1 + 8);
            do {
              local_8 = 0;
              if (uVar9 != 0) {
                do {
                  puVar7 = *(uint **)(*(int *)(param_1 + 0x14) + local_8 * 4);
                  if ((((*puVar7 == local_14) && (puVar7[1] == 0xffffffff)) &&
                      (local_c[puVar7[3] + (puVar7[2] + (int)local_10) * 4] != -1)) &&
                     (*(double *)(puVar7 + 4) !=
                      *(double *)
                       (*(int *)(*(int *)(param_1 + 0x14) +
                                local_c[puVar7[3] + (puVar7[2] + (int)local_10) * 4] * 4) + 0x10)))
                  break;
                  local_8 = local_8 + 1;
                } while (local_8 < *(uint *)(param_1 + 8));
              }
              uVar9 = *(uint *)(param_1 + 8);
            } while ((local_8 != uVar9) &&
                    (local_10 = (uint *)((int)local_10 + 1), local_10 < local_18));
          }
          uVar9 = 0;
          if (*(int *)(param_1 + 8) != 0) {
            do {
              puVar7 = *(uint **)(*(int *)(param_1 + 0x14) + uVar9 * 4);
              if (*puVar7 == local_14) {
                puVar7[2] = puVar7[2] + (int)local_10;
                uVar5 = puVar7[2];
                if (puVar7[1] == 0xffffffff) {
                  puVar2 = local_c + puVar7[3] + uVar5 * 4;
                  if (*puVar2 == 0xffffffff) {
                    if (local_20 <= uVar5) {
                      local_20 = uVar5 + 1;
                    }
                    *puVar2 = uVar9;
                  }
                  else {
                    *puVar7 = *(uint *)(param_1 + 0x4c);
                    puVar7[7] = *puVar2;
                    local_24 = 1;
                  }
                }
              }
              uVar9 = uVar9 + 1;
            } while (uVar9 < *(uint *)(param_1 + 8));
          }
        }
        local_14 = local_14 + 1;
      } while (local_14 < *(uint *)(param_1 + 4));
      if (local_24 != 0) {
        FUN_005fbe30();
      }
    }
    uVar9 = 0;
    if (*(int *)(param_1 + 8) != 0) {
      do {
        piVar4 = *(int **)(*(int *)(param_1 + 0x14) + uVar9 * 4);
        uVar5 = *(uint *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar4 * 4) + 4);
        if (((char)uVar5 < '\0') && ((uVar5 & 0x200) == 0)) {
          piVar4[2] = -1;
          *piVar4 = *(int *)(param_1 + 0x50);
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(uint *)(param_1 + 8));
    }
    local_18 = (uint *)0x0;
    if (*(int *)(param_1 + 0xc) != 0) {
      do {
        local_14 = *(uint *)(*(int *)(param_1 + 0x18) + (int)local_18 * 4);
        iVar6 = FUN_005f7a96();
        if (iVar6 == 0) {
          local_54[0] = 0xffffffff;
          local_54[1] = 0xffffffff;
          local_54[2] = 0xffffffff;
          local_54[3] = 0xffffffff;
          local_54[4] = 0;
          local_54[5] = 0;
          local_54[6] = 0;
          local_54[7] = 0;
          local_8 = 0;
          local_1c = 0;
          while( true ) {
            local_2c = (uint *)FUN_005f7a5c(local_1c,&local_28);
            if (local_2c == (uint *)0x0) break;
            local_10 = (uint *)0x0;
            if (local_2c != (uint *)0x0) {
              iVar6 = *(int *)(param_1 + 0x14);
              do {
                uVar5 = local_8;
                uVar9 = *(uint *)(local_28 + (int)local_10 * 4);
                piVar4 = *(int **)(iVar6 + uVar9 * 4);
                if ((*(int *)(param_1 + 0x50) == *piVar4) && (piVar4[1] == -1)) {
                  uVar10 = 0;
                  if (local_8 != 0) {
                    do {
                      if (*(double *)(*(int *)(iVar6 + local_54[uVar10] * 4) + 0x10) ==
                          *(double *)(piVar4 + 4)) break;
                      uVar10 = uVar10 + 1;
                    } while (uVar10 < local_8);
                    if (uVar10 == 4) goto LAB_0060397d;
                  }
                  if (uVar10 == local_8) {
                    local_8 = local_8 + 1;
                    local_54[uVar5] = uVar9;
                  }
                  local_54[uVar10 + 4] = local_54[uVar10 + 4] | 1 << ((byte)local_10 & 0x1f);
                }
                local_10 = (uint *)((int)local_10 + 1);
              } while (local_10 < local_2c);
            }
            local_1c = local_1c + 1;
          }
          iVar6 = FUN_0060213b(local_c,local_54,local_54 + 4);
          if (iVar6 < 0) {
LAB_0060397d:
            local_1c = 0;
            while (local_10 = (uint *)FUN_005f7a5c(local_1c,&local_20), local_10 != (uint *)0x0) {
              puVar7 = (uint *)0x0;
              if (local_10 != (uint *)0x0) {
                iVar6 = *(int *)(param_1 + 0x50);
                uVar9 = 0;
                do {
                  uVar5 = *(uint *)(local_20 + (int)puVar7 * 4);
                  piVar4 = *(int **)(*(int *)(param_1 + 0x14) + uVar5 * 4);
                  uVar10 = uVar9;
                  if ((iVar6 == *piVar4) && (piVar4[1] == -1)) {
                    local_54[uVar9] = uVar5;
                    uVar10 = uVar9 + 1;
                    local_54[uVar9 + 4] = 1 << ((byte)puVar7 & 0x1f);
                  }
                  puVar7 = (uint *)((int)puVar7 + 1);
                  uVar9 = uVar10;
                } while (puVar7 < local_10);
                if (uVar10 != 0) {
                  if (uVar10 < 4) {
                    local_34 = local_54 + uVar10;
                    puVar7 = local_54 + uVar10 + 4;
                    for (uVar9 = 4 - uVar10 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
                      *puVar7 = 0;
                      puVar7 = puVar7 + 1;
                    }
                    puVar7 = local_34;
                    for (uVar9 = 4 - uVar10 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
                      *puVar7 = 0xffffffff;
                      puVar7 = puVar7 + 1;
                    }
                  }
                  FUN_0060213b(local_c,local_54,local_54 + 4);
                  puVar7 = (uint *)0x0;
                  do {
                    uVar5 = 0;
                    uVar9 = 1 << ((byte)puVar7 & 0x1f);
                    do {
                      if ((local_54[uVar5 + 4] & uVar9) != 0) {
                        local_54[uVar5 + 4] = local_54[uVar5 + 4] & ~uVar9;
                        *(uint *)(local_20 + (int)puVar7 * 4) = local_54[uVar5];
                        break;
                      }
                      uVar5 = uVar5 + 1;
                    } while (uVar5 < 4);
                    puVar7 = (uint *)((int)puVar7 + 1);
                  } while (puVar7 < local_10);
                }
              }
              local_1c = local_1c + 1;
            }
          }
          else {
            local_8 = 0;
            while( true ) {
              local_34 = (uint *)FUN_005f7a5c(local_8,&local_30);
              if (local_34 == (uint *)0x0) break;
              local_2c = (uint *)0x0;
              if (local_34 != (uint *)0x0) {
                do {
                  puVar7 = (uint *)(local_30 + (int)local_2c * 4);
                  piVar4 = *(int **)(*(int *)(param_1 + 0x14) + *puVar7 * 4);
                  if ((*(int *)(param_1 + 0x50) == *piVar4) && (piVar4[1] == -1)) {
                    local_10 = (uint *)0x0;
                    local_1c = 1 << ((byte)local_2c & 0x1f);
                    do {
                      if (((local_54[(int)(local_10 + 1)] & local_1c) != 0) &&
                         (*(double *)(piVar4 + 4) ==
                          *(double *)
                           (*(int *)(*(int *)(param_1 + 0x14) + local_54[(int)local_10] * 4) + 0x10)
                         )) {
                        *puVar7 = local_54[(int)local_10];
                        break;
                      }
                      local_10 = (uint *)((int)local_10 + 1);
                    } while (local_10 < (uint *)0x4);
                  }
                  local_2c = (uint *)((int)local_2c + 1);
                } while (local_2c < local_34);
              }
              local_8 = local_8 + 1;
            }
          }
        }
        local_18 = (uint *)((int)local_18 + 1);
      } while (local_18 < *(uint *)(param_1 + 0xc));
    }
    uVar9 = 0;
    local_34 = (uint *)0x0;
    if (*(int *)(param_1 + 8) != 0) {
      do {
        piVar4 = *(int **)(*(int *)(param_1 + 0x14) + uVar9 * 4);
        if ((*(int *)(param_1 + 0x50) == *piVar4) && (piVar4[2] == -1)) {
          *piVar4 = *(int *)(param_1 + 0x4c);
        }
        else {
          uVar5 = *(uint *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar4 * 4) + 4);
          if (((char)uVar5 < '\0') &&
             (((uVar5 & 0x20) != 0 && (*piVar4 = *(int *)(param_1 + 0x50), piVar4[1] != -1)))) {
            local_34 = (uint *)0x1;
          }
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(uint *)(param_1 + 8));
    }
    puVar7 = (uint *)(*(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x50) * 4) + 4);
    *puVar7 = *puVar7 | 0x20;
    uVar9 = 0;
    if (local_34 != (uint *)0x0) {
      pbVar1 = (byte *)(*(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x50) * 4) + 5);
      *pbVar1 = *pbVar1 | 2;
    }
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x50) * 4) + 8) = 0;
    if (*(int *)(param_1 + 8) != 0) {
      do {
        piVar4 = *(int **)(*(int *)(param_1 + 0x14) + uVar9 * 4);
        if ((*(int *)(param_1 + 0x50) == *piVar4) && (piVar4[1] == -1)) {
          iVar6 = *(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x50) * 4);
          if (*(uint *)(iVar6 + 8) <= (uint)piVar4[2]) {
            *(uint *)(iVar6 + 8) = piVar4[2] + 1;
          }
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(uint *)(param_1 + 8));
    }
    if (local_24 != 0) {
      FUN_005fc5a6();
    }
    _free(local_c);
    uVar3 = 0;
  }
  return uVar3;
}


// ==== 0x603b2e FUN_00603b2e

int __fastcall FUN_00603b2e(int param_1)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint local_20;
  int *local_18;
  uint local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  if (((*(byte *)(param_1 + 0x34) & 8) == 0) && ((*(byte *)(param_1 + 0x93) & 2) != 0)) {
    iVar4 = FUN_005f8440();
    if (iVar4 < 0) {
      return iVar4;
    }
    local_20 = 0;
    do {
      bVar3 = false;
      iVar4 = FUN_0060254c(*(undefined4 *)(param_1 + 0x60),*(undefined4 *)(param_1 + 0x70),0);
      if (iVar4 < 0) {
        return iVar4;
      }
      local_8 = 0;
      if (*(int *)(param_1 + 0xc) != 0) {
        do {
          iVar4 = *(int *)(*(int *)(param_1 + 0x18) + local_8 * 4);
          local_18 = *(int **)(iVar4 + 0x2c);
          local_14 = *(uint *)(iVar4 + 0x24);
          uVar11 = -(uint)(local_14 < local_18) & (int)local_18 - local_14;
          iVar5 = FUN_005f7b45();
          iVar5 = (-(uint)(iVar5 != 0) & 0xfffffffe) + 2;
          local_c = local_8;
          if (local_8 != 0) {
            local_10 = (int *)(*(int *)(param_1 + 0x18) + -4 + local_8 * 4);
            do {
              iVar1 = *local_10;
              if (*(uint *)(iVar4 + 0x28) <= *(uint *)(iVar1 + 0x28)) break;
              uVar8 = *(uint *)(iVar1 + 0x24);
              uVar12 = *(uint *)(iVar1 + 0x2c);
              uVar6 = -(uint)(uVar12 < uVar8) & uVar8 - uVar12;
              uVar7 = *(int *)(param_1 + 0x70) - iVar5;
              if ((uVar7 < uVar8 + uVar11) || (uVar7 < uVar12 + uVar11)) {
                local_c = local_8;
                break;
              }
              local_14 = local_14 + uVar6;
              local_18 = (int *)((int)local_18 + uVar6);
              local_c = local_c - 1;
              local_10 = local_10 + -1;
            } while (local_c != 0);
            if (((local_8 != local_c) &&
                (uVar8 = *(int *)(param_1 + 0x70) - iVar5, local_14 <= uVar8)) &&
               (uVar12 = local_8, local_18 <= uVar8)) {
              for (; local_c < uVar12; uVar12 = uVar12 - 1) {
                iVar5 = *(int *)(uVar12 * 4 + -4 + *(int *)(param_1 + 0x18));
                *(int *)(iVar5 + 0x24) = *(int *)(iVar5 + 0x24) + uVar11;
                *(int *)(iVar5 + 0x2c) = *(int *)(iVar5 + 0x2c) + uVar11;
                *(int *)(uVar12 * 4 + *(int *)(param_1 + 0x18)) = iVar5;
              }
              *(uint *)(iVar4 + 0x24) = local_14;
              *(int **)(iVar4 + 0x2c) = local_18;
              *(int *)(*(int *)(param_1 + 0x18) + local_c * 4) = iVar4;
              bVar3 = true;
            }
          }
          local_8 = local_8 + 1;
        } while (local_8 < *(uint *)(param_1 + 0xc));
      }
      iVar4 = FUN_0060254c(*(undefined4 *)(param_1 + 0x60),*(undefined4 *)(param_1 + 0x70),0);
      if (iVar4 < 0) {
        return iVar4;
      }
      uVar11 = *(uint *)(param_1 + 0xc);
      while (uVar11 != 0) {
        uVar11 = uVar11 - 1;
        iVar4 = *(int *)(*(int *)(param_1 + 0x18) + uVar11 * 4);
        local_10 = *(int **)(iVar4 + 0x2c);
        local_14 = *(uint *)(iVar4 + 0x24);
        uVar12 = -(uint)(local_10 < local_14) & local_14 - (int)local_10;
        iVar5 = FUN_005f7b45();
        iVar5 = (-(uint)(iVar5 != 0) & 0xfffffffe) + 2;
        uVar8 = *(int *)(param_1 + 0xc) - 1;
        if (uVar11 < uVar8) {
          local_18 = (int *)(*(int *)(param_1 + 0x18) + 4 + uVar11 * 4);
          local_c = uVar11;
          while (iVar1 = *local_18, uVar6 = local_c,
                *(uint *)(iVar4 + 0x28) < *(uint *)(iVar1 + 0x28)) {
            uVar7 = *(uint *)(iVar1 + 0x24);
            uVar2 = *(uint *)(iVar1 + 0x2c);
            uVar9 = -(uint)(uVar7 < uVar2) & uVar2 - uVar7;
            uVar10 = *(int *)(param_1 + 0x70) - iVar5;
            uVar6 = uVar11;
            if ((uVar10 < uVar7 + uVar12) || (uVar10 < uVar2 + uVar12)) break;
            local_14 = local_14 + uVar9;
            local_10 = (int *)((int)local_10 + uVar9);
            local_c = local_c + 1;
            local_18 = local_18 + 1;
            uVar6 = local_c;
            if (uVar8 <= local_c) break;
          }
          local_c = uVar6;
          if (((uVar11 != local_c) && (uVar8 = *(int *)(param_1 + 0x70) - iVar5, local_14 <= uVar8))
             && (uVar6 = uVar11, local_10 <= uVar8)) {
            for (; uVar6 < local_c; uVar6 = uVar6 + 1) {
              iVar5 = *(int *)(uVar6 * 4 + 4 + *(int *)(param_1 + 0x18));
              *(int *)(iVar5 + 0x24) = *(int *)(iVar5 + 0x24) + uVar12;
              *(int *)(iVar5 + 0x2c) = *(int *)(iVar5 + 0x2c) + uVar12;
              *(int *)(uVar6 * 4 + *(int *)(param_1 + 0x18)) = iVar5;
            }
            *(uint *)(iVar4 + 0x24) = local_14;
            *(int **)(iVar4 + 0x2c) = local_10;
            *(int *)(*(int *)(param_1 + 0x18) + local_c * 4) = iVar4;
            bVar3 = true;
          }
        }
      }
    } while ((bVar3) && (local_20 = local_20 + 1, local_20 < 0x20));
  }
  return 0;
}


// ==== 0x603df3 FUN_00603df3

int __fastcall FUN_00603df3(int param_1)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  int iVar5;
  bool bVar6;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar5 = FUN_005fb6af(*(undefined4 *)(param_1 + 0x60),3,0x200);
  if (((((-1 < iVar5) && (iVar5 = FUN_005fb6af(*(undefined4 *)(param_1 + 100),6,0x201), -1 < iVar5))
       && (iVar5 = FUN_0060254c(*(undefined4 *)(param_1 + 0x60),*(undefined4 *)(param_1 + 0x70),1),
          -1 < iVar5)) &&
      ((iVar5 = FUN_0060254c(*(undefined4 *)(param_1 + 100),*(undefined4 *)(param_1 + 0x74),1),
       -1 < iVar5 &&
       (((*(uint *)(param_1 + 0x30) & 0xffff0000) != 0x46580000 ||
        (iVar5 = FUN_005fb6af(*(undefined4 *)(param_1 + 0x54),0x100,0xc0), -1 < iVar5)))))) &&
     ((((*(uint *)(param_1 + 0x30) & 0xffff0000) == 0xfffe0000 ||
       (iVar5 = FUN_005fb6af(*(undefined4 *)(param_1 + 0x58),8,0x100), -1 < iVar5)) &&
      (((iVar5 = FUN_005fb6af(*(undefined4 *)(param_1 + 0x5c),0x10,0), -1 < iVar5 &&
        (iVar5 = FUN_005fb6af(*(undefined4 *)(param_1 + 0x60),3,0), -1 < iVar5)) &&
       ((iVar5 = FUN_005fb6af(*(undefined4 *)(param_1 + 100),6,1), -1 < iVar5 &&
        (((*(uint *)(param_1 + 0x30) & 0xffff0000) == 0xffff0000 ||
         (iVar5 = FUN_005fb6af(*(undefined4 *)(param_1 + 0x68),0x40,0), -1 < iVar5)))))))))) {
    if ((*(byte *)(param_1 + 0x34) & 8) == 0) {
      bVar4 = false;
      FUN_005fbe17();
      local_c = 0;
      if (*(int *)(param_1 + 0xc) != 0) {
        do {
          puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + local_c * 4);
          iVar5 = FUN_005f7aa3();
          if (iVar5 != 0) {
            bVar6 = puVar1[3] == 0;
            local_10 = 0;
            local_8 = 0;
            if (puVar1[3] != 0) {
              do {
                iVar5 = local_8 * 4;
                piVar2 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)(puVar1[4] + iVar5) * 4);
                piVar3 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)(iVar5 + puVar1[2]) * 4);
                if ((((*piVar2 == *piVar3) && (piVar2[1] == piVar3[1])) && (piVar2[2] == piVar3[2]))
                   && (piVar2[3] == piVar3[3])) {
                  piVar2[7] = *(int *)(iVar5 + puVar1[2]);
                }
                else {
                  *(int *)(puVar1[4] + local_10 * 4) = *(int *)(puVar1[4] + iVar5);
                  *(undefined4 *)(puVar1[2] + local_10 * 4) = *(undefined4 *)(puVar1[2] + iVar5);
                  local_10 = local_10 + 1;
                }
                local_8 = local_8 + 1;
              } while (local_8 < puVar1[3]);
              bVar6 = local_10 == puVar1[3];
            }
            if (!bVar6) {
              *puVar1 = -(uint)(local_10 != 0) & (local_10 & 0xffffff | 0x10000000);
              puVar1[1] = local_10;
              puVar1[3] = local_10;
              bVar4 = true;
            }
          }
          local_c = local_c + 1;
        } while (local_c < *(uint *)(param_1 + 0xc));
        if (bVar4) {
          iVar5 = FUN_005fbe30();
          if (iVar5 < 0) {
            return iVar5;
          }
          iVar5 = FUN_005fede4();
          if (iVar5 < 0) {
            return iVar5;
          }
          iVar5 = FUN_005f8440();
          if (iVar5 < 0) {
            return iVar5;
          }
        }
      }
    }
    iVar5 = 0;
  }
  return iVar5;
}


// ==== 0x604024 FUN_00604024

int __fastcall FUN_00604024(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint local_8;
  
  if ((*(byte *)(param_1 + 0x34) & 8) == 0) {
    iVar3 = FUN_005fc336();
    if (-1 < iVar3) {
      local_8 = 0;
      do {
        iVar3 = FUN_00602b94();
        if (iVar3 < 0) {
          return iVar3;
        }
        iVar4 = FUN_005f8040();
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar5 = FUN_005fc5a6();
        if (iVar5 < 0) {
          return iVar5;
        }
        iVar6 = FUN_005fc7c0();
        if (iVar6 < 0) {
          return iVar6;
        }
        iVar7 = FUN_005fca3e();
        if (iVar7 < 0) {
          return iVar7;
        }
        iVar8 = FUN_005fd5b7();
        if (iVar8 < 0) {
          return iVar8;
        }
        iVar9 = FUN_005fe888();
        if (iVar9 < 0) {
          return iVar9;
        }
      } while ((iVar9 == 0 ||
                (((((iVar3 == 0 || iVar4 == 0) || iVar5 == 0) || iVar6 == 0) || iVar7 == 0) ||
                iVar8 == 0)) && (local_8 = local_8 + 1, local_8 < 0x100));
      if (local_8 == 0x100) {
        FUN_005fbf37(param_1,0,0,"internal warning: optimization did not converge");
      }
      *(undefined4 *)(param_1 + 0x3c) = 1;
      iVar3 = FUN_005feb84();
      if (((-1 < iVar3) && (iVar3 = FUN_005f8440(), -1 < iVar3)) &&
         (iVar3 = FUN_005fede4(), -1 < iVar3)) {
        uVar10 = 0;
        if (*(int *)(param_1 + 8) != 0) {
          do {
            piVar1 = *(int **)(*(int *)(param_1 + 0x14) + uVar10 * 4);
            uVar2 = *(uint *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar1 * 4) + 4);
            if (((char)uVar2 < '\0') && ((uVar2 & 0x200) == 0)) {
              *piVar1 = *(int *)(param_1 + 0x50);
            }
            uVar10 = uVar10 + 1;
          } while (uVar10 < *(uint *)(param_1 + 8));
        }
        iVar3 = 0;
      }
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}


// ==== 0x60417a FUN_0060417a

int __fastcall FUN_0060417a(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 0x14) + uVar3 * 4);
      if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar1 * 4) + 4) & 0x20) == 0) {
        piVar1[2] = -1;
        piVar1[3] = -1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 8));
  }
  iVar2 = FUN_005f8440();
  if ((((((-1 < iVar2) && (iVar2 = FUN_005fede4(), -1 < iVar2)) &&
        (iVar2 = FUN_005f9ec4(), -1 < iVar2)) &&
       (((iVar2 = FUN_005ff66c(), -1 < iVar2 && (iVar2 = FUN_005f8440(), -1 < iVar2)) &&
        ((iVar2 = FUN_005ffbd5(), -1 < iVar2 &&
         ((iVar2 = FUN_00600fa7(), -1 < iVar2 && (iVar2 = FUN_00603622(), -1 < iVar2)))))))) &&
      (((*(undefined4 *)(param_1 + 0x40) = 1, (*(byte *)(param_1 + 0x34) & 8) != 0 ||
        ((iVar2 = FUN_00601cfe(), -1 < iVar2 &&
         (((*(byte *)(param_1 + 0x34) & 8) != 0 || (iVar2 = FUN_00603b2e(), -1 < iVar2)))))) &&
       (iVar2 = FUN_005f8440(), -1 < iVar2)))) &&
     (((iVar2 = FUN_005fede4(), -1 < iVar2 && (iVar2 = FUN_00603df3(), -1 < iVar2)) &&
      (iVar2 = FUN_00601ecc(), -1 < iVar2)))) {
    iVar2 = 0;
  }
  return iVar2;
}


// ==== 0x604269 FUN_00604269

undefined4 * __fastcall FUN_00604269(undefined4 *param_1)

{
  FUN_006137a9();
  param_1[0x7e] = 0xffffffff;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x81] = 0;
  *param_1 = &PTR_FUN_006a4cb8;
  return param_1;
}


// ==== 0x604296 FUN_00604296

void __thiscall FUN_00604296(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x10c);
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  _free(*(void **)(param_1 + 0x140));
  _free(*(void **)(param_1 + 0x144));
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(undefined4 *)(param_1 + 0x144) = 0;
  FUN_00619954(param_2,param_3);
  return;
}


// ==== 0x6042f5 FUN_006042f5

undefined4 __fastcall FUN_006042f5(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x90);
  *(undefined4 *)(param_1 + 0x74) = 0;
  uVar2 = *(uint *)(param_1 + 0x30) & 0xffff;
  *(undefined4 *)(param_1 + 0x6c) = 2;
  *(undefined4 *)(param_1 + 0x70) = 0x18;
  *(undefined4 *)(param_1 + 0x78) = 8;
  *(undefined4 *)(param_1 + 0x84) = 1;
  *(uint *)(param_1 + 0x90) = uVar1 & 0xffffffde | 0x738968a;
  if (uVar2 == 0x104) {
    *(undefined4 *)(param_1 + 0x8c) = 0;
    *(undefined4 *)(param_1 + 0x7c) = 6;
    *(undefined4 *)(param_1 + 0x80) = 8;
    *(undefined4 *)(param_1 + 0x88) = 6;
    *(uint *)(param_1 + 0x90) = uVar1 & 0xffb8ffda | 0x738fe9a;
  }
  else {
    *(undefined4 *)(param_1 + 0x8c) = 2;
    *(undefined4 *)(param_1 + 0x7c) = 4;
    *(undefined4 *)(param_1 + 0x80) = 6;
    *(undefined4 *)(param_1 + 0x88) = 4;
    *(uint *)(param_1 + 0x90) =
         (uint)(uVar2 == 0x101) << 0x10 | uVar1 & 0xfffe97de | 0x738968a | 0x8460014;
  }
  return 0;
}


// ==== 0x6043ad FUN_006043ad

undefined4 __fastcall FUN_006043ad(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint local_10;
  int *local_c;
  uint local_8;
  
  local_10 = *(uint *)(param_1 + 0x88);
  if (local_10 < *(uint *)(param_1 + 0x138)) {
    local_c = (int *)(*(int *)(param_1 + 0x144) + local_10 * 4);
    do {
      puVar2 = (uint *)*local_c;
      if ((((puVar2 != (uint *)0x0) && (*puVar2 != 0)) &&
          ((iVar3 = *(int *)(param_1 + 0x14),
           **(int **)(iVar3 + *(int *)puVar2[4] * 4) != *(int *)(param_1 + 0x5c) ||
           ((*puVar2 & 0xff000000) != 0x10000000)))) && (local_8 = 0, puVar2[1] != 0)) {
        piVar5 = (int *)puVar2[2];
        do {
          iVar4 = *(int *)(iVar3 + *piVar5 * 4);
          puVar1 = (uint *)(iVar4 + 0x20);
          for (; *(int *)(iVar4 + 0x24) != -1; iVar4 = *(int *)(iVar3 + *(int *)(iVar4 + 0x24) * 4))
          {
          }
          if ((*(char *)(iVar4 + 0x50) == '\x03') &&
             (((*(uint *)(iVar4 + 0x20) | *puVar1) & 0x200) == 0)) {
            FUN_005fbf37(param_1,puVar2[0xd],0x1263,
                         "texcoord inputs used directly (that is, other than sampling from textures) in shader body in ps_1_%i are always clamped from 0 to 1"
                         ,*(uint *)(param_1 + 0x30) & 0xff);
            return 0;
          }
          local_8 = local_8 + 1;
          piVar5 = piVar5 + 1;
        } while (local_8 < puVar2[1]);
      }
      local_10 = local_10 + 1;
      local_c = local_c + 1;
    } while (local_10 < *(uint *)(param_1 + 0x138));
  }
  return 0;
}


// ==== 0x604486 FUN_00604486

undefined4 __fastcall FUN_00604486(int param_1)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  bool bVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int local_2c;
  uint local_24;
  int *local_18;
  int *local_14;
  uint local_8;
  
  bVar5 = false;
  puVar1 = *(uint **)(param_1 + 0x98);
  if (((*puVar1 & 0xffffff) != 4) || (puVar1[1] != 4)) {
    FUN_005fbec8(param_1,puVar1[0xd],0x12d4,"internal error: malformed clip found");
    return 0x80004005;
  }
  piVar2 = (int *)puVar1[2];
  iVar10 = *(int *)(*(int *)(param_1 + 0x14) + piVar2[3] * 4);
  iVar3 = *(int *)(iVar10 + 0x2c);
  if (iVar3 == -1) {
    uVar9 = *(uint *)(param_1 + 0x30);
    uVar7 = puVar1[0xd];
    goto LAB_00604682;
  }
  puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + iVar3 * 4);
  uVar7 = 0;
  do {
    if (*(uint *)(iVar10 + 0xc) == uVar7) {
      bVar5 = true;
    }
    uVar7 = uVar7 + 1;
  } while (uVar7 < 3);
  uVar7 = *puVar1;
  uVar9 = uVar7 & 0xffffff;
  if (puVar1[3] == 1) {
    bVar5 = true;
    if (uVar7 == 0x10000001) {
      iVar10 = 3;
      piVar8 = piVar2;
      do {
        if (*(int *)puVar1[2] == *piVar8) {
          bVar5 = false;
        }
        piVar8 = piVar8 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      goto LAB_006045e4;
    }
  }
  else {
    if ((uVar7 & 0xff000000) != 0x30000000) {
      local_8 = 0;
      if (uVar9 != 1) {
        while (bVar6 = false, puVar1[1] / uVar9 != 0) {
          local_14 = (int *)(puVar1[2] + local_8 * 4);
          local_18 = (int *)(uVar9 * 4 + -4 + puVar1[2]);
          local_24 = puVar1[1] / uVar9;
          do {
            piVar8 = *(int **)(*(int *)(param_1 + 0x14) + *local_14 * 4);
            piVar4 = *(int **)(*(int *)(param_1 + 0x14) + *local_18 * 4);
            if (((piVar8[3] != piVar4[3]) || (*piVar8 != *piVar4)) || (piVar8[2] != piVar4[2])) {
              bVar6 = true;
            }
            local_14 = local_14 + uVar9;
            local_18 = local_18 + uVar9;
            local_24 = local_24 - 1;
          } while (local_24 != 0);
          if ((!bVar6) || (local_8 = local_8 + 1, uVar9 - 1 <= local_8)) break;
        }
      }
      if (local_8 == uVar9 - 1) {
        bVar5 = true;
      }
    }
LAB_006045e4:
    if (!bVar5) {
      if (*puVar1 == 0x10000004) {
        bVar5 = true;
        local_2c = 4;
        piVar8 = piVar2;
        do {
          iVar10 = *(int *)(*(int *)(param_1 + 0x14) + *piVar8 * 4);
          iVar3 = *(int *)(iVar10 + 0x38);
          if ((iVar3 != *(int *)(iVar10 + 0x3c)) || (iVar3 != *(int *)(param_1 + 0x94))) {
            bVar5 = false;
          }
          piVar8 = piVar8 + 1;
          local_2c = local_2c + -1;
        } while (local_2c != 0);
        piVar8 = (int *)puVar1[2];
        *piVar2 = *piVar8;
        piVar2[1] = piVar8[1];
        piVar2[2] = piVar8[2];
        if (bVar5) {
          *puVar1 = 0;
        }
      }
      *(undefined4 *)(*(int *)(param_1 + 0x98) + 4) = 3;
      **(undefined4 **)(param_1 + 0x98) = 0x34000003;
      return 0;
    }
  }
  uVar9 = *(uint *)(param_1 + 0x30);
  uVar7 = *(uint *)(*(int *)(param_1 + 0x98) + 0x34);
LAB_00604682:
  FUN_005fbec8(param_1,uVar7,0x11c0,"Clip must be from a 3 vector in ps_1_%i",uVar9 & 0xff);
  return 0x80004005;
}


// ==== 0x6046ad FUN_006046ad

undefined4 __fastcall FUN_006046ad(int param_1)

{
  byte *pbVar1;
  uint *puVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint local_c;
  uint local_8;
  
  puVar2 = *(uint **)(param_1 + 0x98);
  if (((*puVar2 & 0xff000000) == 0x10000000) && ((*(uint *)(param_1 + 0x30) & 0xffff) < 0x104)) {
    uVar5 = *puVar2 & 0xffffff;
    iVar6 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)puVar2[2] * 4);
    piVar3 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)puVar2[4] * 4);
    if ((*(int *)(iVar6 + 0x20) == 0) &&
       ((((*(byte *)((int)piVar3 + 0x21) & 2) != 0 && (*(char *)(iVar6 + 0x50) == '\x03')) &&
        (*piVar3 == *(int *)(param_1 + 0x60))))) {
      local_c = 0;
      if (uVar5 != 0) {
        do {
          iVar6 = local_c * 4;
          pbVar1 = (byte *)(*(int *)(*(int *)(param_1 + 0x14) +
                                    *(int *)(iVar6 + *(int *)(*(int *)(param_1 + 0x98) + 8)) * 4) +
                           0x21);
          *pbVar1 = *pbVar1 | 2;
          for (uVar7 = *(uint *)(param_1 + 0x94); uVar7 < *(uint *)(param_1 + 0xc);
              uVar7 = uVar7 + 1) {
            iVar4 = *(int *)(*(int *)(param_1 + 0x18) + uVar7 * 4);
            local_8 = 0;
            if (*(int *)(iVar4 + 4) != 0) {
              do {
                piVar3 = (int *)(*(int *)(iVar4 + 8) + local_8 * 4);
                if (*piVar3 == *(int *)(iVar6 + *(int *)(*(int *)(param_1 + 0x98) + 0x10))) {
                  *piVar3 = *(int *)(iVar6 + *(int *)(*(int *)(param_1 + 0x98) + 8));
                }
                local_8 = local_8 + 1;
              } while (local_8 < *(uint *)(iVar4 + 4));
            }
          }
          local_c = local_c + 1;
        } while (local_c < uVar5);
      }
      **(undefined4 **)(param_1 + 0x98) = 0;
    }
  }
  return 0;
}


// ==== 0x6047ce FUN_006047ce

int __fastcall FUN_006047ce(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  bool bVar11;
  int local_8;
  
  uVar3 = **(uint **)(param_1 + 0x98);
  if ((uVar3 & 0xff000000) == 0x11000000) {
    uVar3 = uVar3 & 0xffffff;
    piVar1 = (int *)(*(uint **)(param_1 + 0x98))[2];
    iVar2 = *(int *)(param_1 + 0x14);
    bVar11 = (*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + **(int **)(iVar2 + *piVar1 * 4) * 4) + 5
                       ) & 1) != 0;
    uVar6 = uVar3;
    if ((*(byte *)(param_1 + 0x92) & 1) != 0) {
      for (; uVar6 != 0; uVar6 = uVar6 - 1) {
        iVar8 = *(int *)(iVar2 + *piVar1 * 4);
        if ((*(uint *)(iVar8 + 0x20) & 0x200) != 0) {
          bVar11 = true;
        }
        if (*(int *)(iVar8 + 0x24) != -1) {
          iVar8 = *(int *)(iVar2 + *(int *)(iVar8 + 0x24) * 4);
        }
        if ((*(uint *)(iVar8 + 0x20) & 0x200) != 0) {
          bVar11 = true;
        }
        piVar1 = piVar1 + 1;
      }
    }
    if (bVar11) {
      pvVar4 = _malloc(0x38);
      if (pvVar4 == (void *)0x0) {
        local_8 = 0;
      }
      else {
        local_8 = FUN_005f7709();
      }
      iVar8 = local_8;
      if (local_8 == 0) {
        iVar2 = -0x7ff8fff2;
      }
      else {
        iVar2 = FUN_005f7760(uVar3 | 0x25000000,uVar3 * 2,uVar3,0);
        if ((-1 < iVar2) && (iVar2 = FUN_005f7a42(), -1 < iVar2)) {
          iVar2 = FUN_005f7478(&DAT_0069ecd8,0x189,1,4);
          if ((iVar2 == -1) || (iVar2 = FUN_005f74cf(iVar2,0,0,0xbff0000000000000), iVar2 == -1)) {
            iVar2 = -0x7ff8fff2;
          }
          else {
            iVar5 = uVar3 << 2;
            puVar9 = *(undefined4 **)(*(int *)(param_1 + 0x98) + 8);
            puVar10 = *(undefined4 **)(local_8 + 8);
            for (uVar6 = uVar3; uVar6 != 0; uVar6 = uVar6 - 1) {
              *puVar10 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar10 = puVar10 + 1;
            }
            for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
              *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
              puVar9 = (undefined4 *)((int)puVar9 + 1);
              puVar10 = (undefined4 *)((int)puVar10 + 1);
            }
            puVar9 = *(undefined4 **)(*(int *)(param_1 + 0x98) + 0x10);
            puVar10 = *(undefined4 **)(local_8 + 0x10);
            for (uVar6 = uVar3; uVar6 != 0; uVar6 = uVar6 - 1) {
              *puVar10 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar10 = puVar10 + 1;
            }
            for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
              *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
              puVar9 = (undefined4 *)((int)puVar9 + 1);
              puVar10 = (undefined4 *)((int)puVar10 + 1);
            }
            for (; uVar3 != 0; uVar3 = uVar3 - 1) {
              *(int *)(iVar5 + *(int *)(local_8 + 8)) = iVar2;
              iVar5 = iVar5 + 4;
            }
            if (*(int *)(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x94) * 4) != 0) {
              FUN_005f7186();
            }
            local_8 = 0;
            *(int *)(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x94) * 4) = iVar8;
            iVar2 = 0;
          }
        }
        if (local_8 != 0) {
          FUN_005f7186();
        }
      }
    }
    else {
      iVar2 = 0;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ==== 0x6049c5 FUN_006049c5

undefined4 __fastcall FUN_006049c5(int param_1)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  int local_20;
  int *local_1c;
  int *local_18;
  uint local_10;
  uint local_c;
  uint local_8;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x144) + -4 + *(int *)(param_1 + 0x138) * 4);
  if (*piVar1 == 0x10000004) {
    local_10 = 0;
    piVar6 = (int *)piVar1[4];
    do {
      if (**(int **)(*(int *)(param_1 + 0x14) + *piVar6 * 4) != *(int *)(param_1 + 0x5c)) {
        return 0;
      }
      local_10 = local_10 + 1;
      piVar6 = piVar6 + 1;
    } while (local_10 < 4);
    uVar5 = *(int *)(param_1 + 0x138) - 1;
    bVar4 = true;
    local_8 = 0;
    do {
      uVar9 = 0;
      bVar3 = false;
      if (uVar5 != 0) {
        local_18 = *(int **)(param_1 + 0x144);
        do {
          piVar6 = (int *)*local_18;
          if ((piVar6 != (int *)0x0) && (*piVar6 != 0)) {
            iVar7 = piVar6[3];
            if (iVar7 != 0) {
              piVar6 = (int *)piVar6[4];
              do {
                if (*piVar6 == *(int *)(piVar1[2] + local_8 * 4)) {
                  bVar3 = true;
                }
                piVar6 = piVar6 + 1;
                iVar7 = iVar7 + -1;
              } while (iVar7 != 0);
            }
            if (bVar3) break;
          }
          local_18 = local_18 + 1;
          uVar9 = uVar9 + 1;
        } while (uVar9 < uVar5);
      }
      if ((*(uint *)(param_1 + 0x30) & 0xffff) == 0x104) {
        if ((uVar9 < *(uint *)(param_1 + 0x88)) && (uVar9 != 0)) {
LAB_00604aa6:
          bVar4 = false;
        }
      }
      else if (uVar9 < *(uint *)(param_1 + 0x88)) goto LAB_00604aa6;
      if (!bVar3) {
        return 0;
      }
      uVar9 = uVar9 + 1;
      if (uVar9 < uVar5) {
        local_1c = (int *)(*(int *)(param_1 + 0x144) + uVar9 * 4);
        local_20 = uVar5 - uVar9;
        do {
          piVar6 = (int *)*local_1c;
          if ((piVar6 != (int *)0x0) && (*piVar6 != 0)) {
            local_18 = (int *)piVar6[3];
            if (local_18 != (int *)0x0) {
              piVar8 = (int *)piVar6[4];
              do {
                piVar2 = *(int **)(*(int *)(param_1 + 0x14) + *piVar8 * 4);
                if (((*piVar2 == *(int *)(param_1 + 0x60)) && (piVar2[3] == local_8)) &&
                   (piVar2[2] == 0)) {
                  bVar4 = false;
                }
                piVar8 = piVar8 + 1;
                local_18 = (int *)((int)local_18 + -1);
              } while (local_18 != (int *)0x0);
            }
            iVar7 = piVar6[1];
            if (iVar7 != 0) {
              piVar6 = (int *)piVar6[2];
              do {
                piVar8 = *(int **)(*(int *)(param_1 + 0x14) + *piVar6 * 4);
                if (((*piVar8 == *(int *)(param_1 + 0x60)) && (piVar8[3] == local_8)) &&
                   (piVar8[2] == 0)) {
                  bVar4 = false;
                }
                piVar6 = piVar6 + 1;
                iVar7 = iVar7 + -1;
              } while (iVar7 != 0);
            }
          }
          local_1c = local_1c + 1;
          local_20 = local_20 + -1;
        } while (local_20 != 0);
      }
      local_8 = local_8 + 1;
    } while (local_8 < 4);
    if (bVar4) {
      uVar9 = 0;
      do {
        local_c = 0;
        if (uVar5 != 0) {
          do {
            piVar6 = *(int **)(*(int *)(param_1 + 0x144) + local_c * 4);
            if (((piVar6 != (int *)0x0) && (*piVar6 != 0)) && (local_10 = 0, piVar6[3] != 0)) {
              do {
                piVar8 = (int *)(piVar6[4] + local_10 * 4);
                if (*piVar8 == *(int *)(uVar9 + piVar1[2])) {
                  *piVar8 = *(int *)(uVar9 + piVar1[4]);
                }
                local_10 = local_10 + 1;
              } while (local_10 < (uint)piVar6[3]);
            }
            local_c = local_c + 1;
            uVar5 = *(int *)(param_1 + 0x138) - 1;
          } while (local_c < uVar5);
        }
        uVar9 = uVar9 + 4;
      } while (uVar9 < 0x10);
      *piVar1 = 0;
    }
  }
  return 0;
}


// ==== 0x604be6 FUN_00604be6

int __fastcall FUN_00604be6(int param_1)

{
  uint *puVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint local_14;
  int local_10;
  uint local_8;
  
  local_8 = 0;
  if (*(int *)(param_1 + 0x88) != 0) {
    do {
      puVar1 = *(uint **)(*(int *)(param_1 + 0x144) + local_8 * 4);
      if (puVar1 != (uint *)0x0) {
        uVar2 = *puVar1 & 0xff000000;
        if ((uVar2 != 0xe1000000) && (uVar2 != 0)) {
          uVar6 = *puVar1 & 0xffffff;
          local_10 = (-(uint)(uVar2 != 0x34000000) & uVar6) * 4;
          if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) +
                                 **(int **)(*(int *)(param_1 + 0x14) +
                                           *(int *)(local_10 + puVar1[2]) * 4) * 4) + 5) & 1) != 0)
          {
            pvVar3 = _malloc(0x38);
            if (pvVar3 == (void *)0x0) {
              iVar4 = 0;
            }
            else {
              iVar4 = FUN_005f7709();
            }
            if (iVar4 == 0) {
              return -0x7ff8fff2;
            }
            iVar5 = FUN_005f7760(uVar6 | 0x10000000,uVar6,uVar6,0);
            if ((iVar5 < 0) || (iVar5 = FUN_005f7a42(), iVar5 < 0)) {
LAB_00604d81:
              FUN_005f7186();
              return iVar5;
            }
            local_14 = 0;
            if (uVar6 != 0) {
              do {
                iVar5 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),0,local_14,0);
                *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + iVar5 * 4) + 0x20) = 0;
                *(int *)(*(int *)(iVar4 + 0x10) + local_14 * 4) = iVar5;
                *(undefined4 *)(*(int *)(iVar4 + 8) + local_14 * 4) =
                     *(undefined4 *)
                      (local_10 + *(int *)(*(int *)(*(int *)(param_1 + 0x144) + local_8 * 4) + 8));
                local_14 = local_14 + 1;
                *(int *)(local_10 + *(int *)(*(int *)(*(int *)(param_1 + 0x144) + local_8 * 4) + 8))
                     = iVar5;
                local_10 = local_10 + 4;
              } while (local_14 < uVar6);
            }
            puVar1 = (uint *)(param_1 + 0x134);
            if (0x1ff < *puVar1) {
              iVar5 = -0x7ff8fff2;
              goto LAB_00604d81;
            }
            *(int *)(*(int *)(param_1 + 0x140) + *puVar1 * 4) = iVar4;
            *puVar1 = *puVar1 + 1;
          }
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(param_1 + 0x88));
  }
  return 0;
}


// ==== 0x604d8e FUN_00604d8e

int __fastcall FUN_00604d8e(int param_1)

{
  uint uVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint local_10;
  uint local_8;
  
  uVar1 = *(uint *)(param_1 + 0xc);
  pvVar3 = _malloc(0x38);
  uVar8 = 0;
  if (pvVar3 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_005f7709();
  }
  if (iVar4 == 0) {
    iVar5 = -0x7ff8fff2;
  }
  else {
    iVar5 = FUN_005f7760(0x10000004,4,4,0);
    if (-1 < iVar5) {
      do {
        uVar6 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),0,uVar8,0);
        *(undefined4 *)(*(int *)(iVar4 + 8) + uVar8 * 4) = uVar6;
        iVar5 = *(int *)(*(int *)(iVar4 + 8) + uVar8 * 4);
        if (iVar5 == -1) {
          iVar5 = -0x7ff8fff2;
          goto LAB_00604e43;
        }
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + iVar5 * 4) + 0x20) = 0;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 4);
      uVar8 = 0;
      if (*(int *)(param_1 + 8) != 0) {
        do {
          piVar2 = *(int **)(*(int *)(param_1 + 0x14) + uVar8 * 4);
          if (*piVar2 == *(int *)(param_1 + 0x5c)) {
            *(uint *)(*(int *)(iVar4 + 0x10) + piVar2[3] * 4) = uVar8;
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < *(uint *)(param_1 + 8));
      }
      iVar5 = FUN_005f73c0();
      if (-1 < iVar5) {
        local_10 = 0;
        if (uVar1 != 0) {
          do {
            iVar5 = *(int *)(*(int *)(param_1 + 0x18) + local_10 * 4);
            if ((((iVar5 != 0) && (uVar8 = *(uint *)(iVar5 + 0xc), uVar8 != 0)) &&
                (**(int **)(*(int *)(param_1 + 0x14) + **(int **)(iVar5 + 0x10) * 4) ==
                 *(int *)(param_1 + 0x5c))) && (local_8 = 0, uVar8 != 0)) {
              do {
                uVar7 = 0;
                do {
                  piVar2 = (int *)(*(int *)(iVar5 + 0x10) + local_8 * 4);
                  if (*piVar2 == *(int *)(uVar7 + *(int *)(iVar4 + 0x10))) {
                    *piVar2 = *(int *)(uVar7 + *(int *)(iVar4 + 8));
                  }
                  uVar7 = uVar7 + 4;
                } while (uVar7 < 0x10);
                local_8 = local_8 + 1;
              } while (local_8 < uVar8);
            }
            local_10 = local_10 + 1;
          } while (local_10 < uVar1);
        }
        return 0;
      }
    }
LAB_00604e43:
    FUN_005f7186();
  }
  return iVar5;
}


// ==== 0x604ee2 FUN_00604ee2

undefined4 FUN_00604ee2(int param_1,int *param_2,uint param_3)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint local_8;
  
  local_8 = 0;
  if (param_3 != 0) {
    piVar3 = &DAT_006df548;
    do {
      bVar1 = true;
      iVar4 = 4;
      piVar2 = param_2;
      do {
        if ((*(int *)((param_1 - (int)param_2) + (int)piVar2) != *piVar3) && (*piVar2 != -1)) {
          bVar1 = false;
        }
        piVar3 = piVar3 + 1;
        piVar2 = piVar2 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      if (bVar1) {
        return 1;
      }
      local_8 = local_8 + 1;
    } while (local_8 < param_3);
  }
  return 0;
}


// ==== 0x604f3b FUN_00604f3b

undefined4 __thiscall FUN_00604f3b(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  int local_18 [4];
  undefined4 local_8;
  
  local_8 = 0;
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  uVar7 = *(uint *)(param_2 + 0xc);
  uVar8 = 0;
  if (uVar7 != 0) {
    iVar1 = *(int *)(param_1 + 0x14);
    piVar6 = *(int **)(param_2 + 0x10);
    do {
      uVar2 = *(uint *)(*(int *)(iVar1 + *piVar6 * 4) + 0xc);
      if (3 < uVar2) {
        return 0;
      }
      uVar8 = uVar8 + 1;
      piVar6 = piVar6 + 1;
      local_18[uVar2] = 1;
    } while (uVar8 < uVar7);
  }
  uVar7 = 0;
  bVar4 = true;
  bVar5 = false;
  do {
    bVar3 = true;
    if (local_18[uVar7] != 0) {
      bVar4 = false;
      bVar3 = bVar5;
    }
    uVar7 = uVar7 + 1;
    bVar5 = bVar3;
  } while (uVar7 < 3);
  if ((bVar3) && (!bVar4)) {
    local_8 = 1;
  }
  return local_8;
}


// ==== 0x604fb1 FUN_00604fb1

int __fastcall FUN_00604fb1(int param_1)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint *puVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  void *pvVar8;
  uint *puVar9;
  undefined4 uVar10;
  uint *puVar11;
  int iVar12;
  bool bVar13;
  int local_ec [20];
  uint local_9c [12];
  int local_6c [4];
  undefined4 local_5c [4];
  int local_4c;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint *local_30;
  uint local_2c;
  int local_28;
  int *local_24;
  uint local_20;
  uint *local_1c;
  int local_18;
  int local_14;
  uint local_10;
  int *local_c;
  int local_8;
  
  local_8 = 0;
  local_14 = 0;
  local_34 = *(uint *)(param_1 + 0x88);
  local_38 = *(uint *)(param_1 + 0x138);
  bVar13 = local_34 < *(uint *)(param_1 + 0x138);
  do {
    local_14 = 0;
    if (!bVar13) {
      iVar12 = 0;
LAB_0060531d:
      if (local_8 != 0) {
        FUN_005f7186();
      }
LAB_0060532b:
      if (local_14 != 0) {
        FUN_005f7186();
      }
      return iVar12;
    }
    puVar11 = *(uint **)(*(int *)(param_1 + 0x144) + local_34 * 4);
    local_30 = puVar11;
    if ((puVar11 != (uint *)0x0) && (*puVar11 != 0)) {
      local_10 = *puVar11 & 0xffffff;
      local_3c = puVar11[1] / local_10;
      local_20 = 0;
      if (local_3c != 0) {
        local_18 = 0;
        local_1c = local_9c;
        do {
          puVar4 = local_1c;
          puVar9 = local_1c + 1;
          *local_1c = 0xffffffff;
          *puVar9 = 0xffffffff;
          puVar4[2] = 0xffffffff;
          puVar4[3] = 0xffffffff;
          local_ec[0] = -1;
          local_ec[1] = 0xffffffff;
          local_ec[2] = 0xffffffff;
          local_ec[3] = 0xffffffff;
          local_28 = 0;
          local_2c = 0;
          if (local_10 == 0) {
LAB_00605111:
            iVar12 = FUN_00604ee2(local_1c,local_ec,2);
            if (iVar12 == 0) {
              local_4c = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),0,3,0);
              if (local_4c == -1) goto LAB_00605343;
              *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + local_4c * 4) + 0x20) = 0;
              pvVar8 = _malloc(0x38);
              if (pvVar8 == (void *)0x0) {
                local_8 = 0;
              }
              else {
                local_8 = FUN_005f7709();
              }
              if (local_8 == 0) goto LAB_00605343;
              iVar12 = FUN_005f7760(0x30000003,6,1,0);
              if ((iVar12 < 0) || (iVar12 = FUN_005f7a42(), iVar12 < 0)) goto LAB_0060531d;
              puVar2 = *(undefined4 **)
                        (*(int *)(param_1 + 0x14) + *(int *)(local_18 + puVar11[2]) * 4);
              local_24 = (int *)puVar2[3];
              local_c = (int *)0x0;
              do {
                if (local_c == local_24) {
                  uVar10 = *(undefined4 *)(param_1 + 0x200);
                }
                else {
                  uVar10 = *(undefined4 *)(param_1 + 0x1fc);
                }
                uVar1 = *(undefined8 *)(puVar2 + 4);
                uVar3 = *puVar2;
                local_5c[(int)local_c] = uVar10;
                iVar12 = FUN_005f74cf(uVar3,0,local_c,uVar1);
                local_6c[(int)local_c] = iVar12;
                if (iVar12 == -1) goto LAB_00605343;
                local_28 = *(int *)(*(int *)(param_1 + 0x14) + iVar12 * 4);
                FUN_005f7c63();
                local_c = (int *)((int)local_c + 1);
                *(undefined4 *)(local_28 + 0x24) = *(undefined4 *)(local_18 + puVar11[2]);
              } while (local_c < (int *)0x3);
              puVar2 = *(undefined4 **)(local_8 + 8);
              *puVar2 = local_5c[0];
              puVar2[1] = local_5c[1];
              puVar2[2] = local_5c[2];
              iVar12 = *(int *)(local_8 + 8);
              *(int *)(iVar12 + 0xc) = local_6c[0];
              *(int *)(iVar12 + 0x10) = local_6c[1];
              *(int *)(iVar12 + 0x14) = local_6c[2];
              **(int **)(local_8 + 0x10) = local_4c;
              iVar12 = local_18;
              for (uVar7 = local_10; uVar7 != 0; uVar7 = uVar7 - 1) {
                *(int *)(iVar12 + local_30[2]) = local_4c;
                iVar12 = iVar12 + 4;
              }
              if (0x1ff < *(uint *)(param_1 + 0x138)) goto LAB_00605343;
              *(int *)(*(int *)(param_1 + 0x144) + *(uint *)(param_1 + 0x138) * 4) = local_8;
              *(int *)(param_1 + 0x138) = *(int *)(param_1 + 0x138) + 1;
              local_8 = 0;
              puVar11 = local_30;
            }
          }
          else {
            local_24 = (int *)(*puVar11 & 0xff000000);
            piVar6 = (int *)(puVar11[2] + local_18);
            do {
              local_c = *(int **)(*(int *)(param_1 + 0x14) + *piVar6 * 4);
              uVar7 = local_2c;
              if ((local_24 != (int *)0x30000000) && (local_10 == puVar11[3])) {
                uVar7 = *(uint *)(*(int *)(*(int *)(param_1 + 0x14) +
                                          *(int *)(puVar11[4] + local_2c * 4) * 4) + 0xc);
              }
              iVar12 = uVar7 + local_20 * 4;
              if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *local_c * 4) + 4) & 0x80) == 0) {
                local_9c[iVar12] = local_c[3];
              }
              else {
                local_9c[iVar12] = uVar7;
              }
              if (uVar7 == 3) {
                local_28 = 1;
              }
              local_ec[uVar7] = 0;
              local_2c = local_2c + 1;
              piVar6 = piVar6 + 1;
            } while (local_2c < local_10);
            if (((local_28 == 0) || (bVar13 = true, local_10 != 1)) ||
               ((local_24 == (int *)0x30000000 && (puVar11[3] == 1)))) goto LAB_00605111;
            uVar7 = 0;
            puVar9 = local_1c;
            do {
              if ((*puVar9 != *(uint *)((int)&DAT_006df588 + uVar7)) &&
                 (*(int *)((int)local_ec + uVar7) != -1)) {
                bVar13 = false;
              }
              uVar7 = uVar7 + 4;
              puVar9 = puVar9 + 1;
            } while (uVar7 < 0x10);
            if (!bVar13) goto LAB_00605111;
          }
          local_20 = local_20 + 1;
          local_1c = local_1c + 4;
          local_18 = local_18 + local_10 * 4;
        } while (local_20 < local_3c);
      }
      pvVar8 = _malloc(0x38);
      if (pvVar8 == (void *)0x0) {
        local_14 = 0;
      }
      else {
        local_14 = FUN_005f7709();
      }
      if (local_14 != 0) {
        iVar12 = FUN_005f799b();
        iVar5 = local_14;
        if (iVar12 < 0) goto LAB_0060532b;
        if (*(uint *)(param_1 + 0x138) < 0x200) {
          local_14 = 0;
          *(int *)(*(int *)(param_1 + 0x144) + *(uint *)(param_1 + 0x138) * 4) = iVar5;
          *(int *)(param_1 + 0x138) = *(int *)(param_1 + 0x138) + 1;
          *puVar11 = 0;
          goto LAB_0060530b;
        }
      }
LAB_00605343:
      iVar12 = -0x7ff8fff2;
      goto LAB_0060531d;
    }
LAB_0060530b:
    local_34 = local_34 + 1;
    bVar13 = local_34 < local_38;
  } while( true );
}


// ==== 0x60534a FUN_0060534a

/* WARNING: Type propagation algorithm not settling */

int __fastcall FUN_0060534a(int *param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  undefined4 uVar10;
  int local_b0 [12];
  int local_80;
  int local_7c [9];
  int iStack_58;
  int iStack_54;
  int iStack_50;
  int local_4c [9];
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  puVar1 = *(uint **)((int)param_1 + 0x98);
  uVar7 = *puVar1;
  local_1c = (int *)(uVar7 & 0xffffff);
  if ((puVar1 == (uint *)0x0) || (uVar7 == 0)) {
    return 0;
  }
  local_c = (int *)(puVar1[1] / (uint)local_1c);
  local_18 = (int *)0x0;
  local_20 = param_1;
  if (((uVar7 & 0xff000000) == 0x30000000) || ((int *)puVar1[3] != local_1c)) {
    iVar6 = FUN_005f75cb(puVar1);
    if (-1 < iVar6) {
      **(undefined4 **)((int)param_1 + 0x98) = 0;
      return 0;
    }
    return iVar6;
  }
  local_4c[8] = 0;
  if (((*(uint *)((int)param_1 + 0x30) & 0xffff) != 0x104) &&
     (iVar6 = FUN_00604f3b(puVar1), iVar6 != 0)) {
    iVar6 = *(int *)(*(int *)((int)param_1 + 0x98) + 0xc);
    if (iVar6 != 0) {
      piVar8 = *(int **)(*(int *)((int)param_1 + 0x98) + 0x10);
      do {
        if (*(int *)(*(int *)(*(int *)((int)param_1 + 0x14) + *piVar8 * 4) + 0xc) == 3) {
          local_18 = (int *)0x1;
          local_4c[8] = 1;
        }
        piVar8 = piVar8 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  local_14 = (int *)0x0;
  if (local_c != (int *)0x0) {
    local_28 = (int *)0x0;
    local_8 = local_b0;
    do {
      piVar9 = local_8;
      piVar8 = local_8 + 1;
      *local_8 = -1;
      local_10 = (int *)0x0;
      *piVar8 = -1;
      piVar9[2] = -1;
      piVar9[3] = -1;
      local_7c[0] = -1;
      local_7c[1] = -1;
      local_7c[2] = -1;
      local_7c[3] = -1;
      if (local_1c != (int *)0x0) {
        iVar6 = *(int *)((int)param_1 + 0x98);
        iVar2 = *(int *)((int)param_1 + 0x14);
        iVar3 = *(int *)((int)param_1 + 0x10);
        local_24 = local_28;
        do {
          piVar8 = *(int **)(iVar2 + *(int *)((int)local_24 + *(int *)(iVar6 + 8)) * 4);
          iVar4 = *(int *)(*(int *)(iVar2 + *(int *)(*(int *)(iVar6 + 0x10) + (int)local_10 * 4) * 4
                                   ) + 0xc);
          if ((*(byte *)(*(int *)(iVar3 + *piVar8 * 4) + 4) & 0x80) == 0) {
            local_b0[iVar4 + (int)local_14 * 4] = piVar8[3];
          }
          else {
            local_b0[iVar4 + (int)local_14 * 4] = iVar4;
          }
          local_7c[iVar4] = 0;
          local_10 = (int *)((int)local_10 + 1);
          local_24 = local_24 + 1;
          param_1 = local_20;
        } while (local_10 < local_1c);
      }
      iVar6 = FUN_00604ee2(local_8,local_7c,5);
      if (iVar6 == 0) {
        local_18 = (int *)0x1;
      }
      local_14 = (int *)((int)local_14 + 1);
      local_8 = local_8 + 4;
      local_28 = local_28 + (int)local_1c;
    } while (local_14 < local_c);
  }
  uVar7 = 0;
  if (local_18 == (int *)0x0) {
    iVar6 = FUN_005f75cb(*(undefined4 *)((int)param_1 + 0x98));
LAB_006058c7:
    if (iVar6 < 0) {
      return iVar6;
    }
    goto LAB_006058cb;
  }
  local_14 = (int *)0x0;
  local_20 = (int *)0x0;
  if (local_1c == (int *)0x4) {
    local_8 = (int *)0x1;
    do {
      if (local_8 == (int *)0x0) break;
      local_7c[0] = 0;
      local_7c[1] = 0;
      local_7c[2] = 0;
      local_7c[3] = 0;
      local_7c[4] = 0xffffffff;
      local_7c[5] = 0xffffffff;
      local_7c[6] = 0xffffffff;
      local_7c[7] = 0xffffffff;
      local_7c[uVar7] = -1;
      local_7c[uVar7 + 4] = 0;
      local_8 = (int *)0x0;
      if (local_c != (int *)0x0) {
        piVar8 = local_b0;
        local_18 = local_c;
        do {
          iVar6 = FUN_00604ee2(piVar8,local_7c,5);
          if ((iVar6 == 0) || (iVar6 = FUN_00604ee2(piVar8,local_7c,5), iVar6 == 0)) {
            local_8 = (int *)0x1;
          }
          piVar8 = piVar8 + 4;
          local_18 = (int *)((int)local_18 - 1);
        } while (local_18 != (int *)0x0);
      }
      if ((local_4c[8] != 0) && (uVar7 != 3)) {
        local_8 = (int *)0x1;
      }
      if (local_8 == (int *)0x0) {
        iVar6 = FUN_00615991(local_7c,local_c,4);
        if (iVar6 < 0) {
          return iVar6;
        }
        iVar6 = FUN_00615991(local_7c + 4,local_c,4);
        goto LAB_006058c7;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 4);
    local_8 = (int *)0x1;
    local_10 = (int *)0x0;
    do {
      if (local_8 == (int *)0x0) break;
      local_18 = (int *)0x0;
      do {
        piVar9 = local_10;
        piVar8 = local_18;
        if (local_18 != local_10) {
          local_7c[0] = 0;
          local_7c[1] = 0;
          local_7c[2] = 0;
          local_7c[3] = 0;
          local_7c[4] = 0xffffffff;
          local_7c[5] = 0xffffffff;
          local_7c[6] = 0xffffffff;
          local_7c[7] = 0xffffffff;
          local_7c[(int)local_10] = -1;
          piVar5 = local_c;
          local_7c[(int)piVar8] = -1;
          local_7c[(int)(piVar9 + 1)] = 0;
          local_7c[(int)(piVar8 + 1)] = 0;
          local_8 = (int *)0x0;
          local_24 = (int *)0x0;
          if (piVar5 != (int *)0x0) {
            piVar9 = local_b0;
            local_28 = local_c;
            do {
              local_80 = FUN_00604ee2(piVar9,local_7c,5);
              iVar6 = FUN_00604ee2(piVar9,local_7c + 4,5);
              if (local_80 == 0) {
                local_24 = (int *)0x1;
LAB_00605634:
                local_8 = (int *)0x1;
              }
              else if (iVar6 == 0) goto LAB_00605634;
              piVar9 = piVar9 + 4;
              local_28 = (int *)((int)local_28 - 1);
            } while (local_28 != (int *)0x0);
          }
          if (local_4c[8] != 0) {
            local_8 = (int *)0x1;
          }
          if (local_8 == (int *)0x0) {
            local_14 = (int *)0x1;
            break;
          }
          if ((local_24 == (int *)0x0) && ((local_4c[8] == 0 || (local_7c[3] != 0)))) {
            local_7c[8] = local_7c[0];
            iStack_58 = local_7c[1];
            iStack_54 = local_7c[2];
            iStack_50 = local_7c[3];
            local_4c[0] = -1;
            local_4c[1] = 0xffffffff;
            local_4c[2] = 0xffffffff;
            local_4c[3] = 0xffffffff;
            local_4c[4] = 0xffffffff;
            local_4c[5] = 0xffffffff;
            local_4c[6] = 0xffffffff;
            local_4c[7] = 0xffffffff;
            local_4c[(int)local_10] = 0;
            local_4c[(int)(local_18 + 1)] = 0;
            local_20 = (int *)0x1;
            piVar8 = local_18;
          }
        }
        local_18 = (int *)((int)piVar8 + 1);
      } while (local_18 < (int *)0x4);
      local_10 = (int *)((int)local_10 + 1);
    } while (local_10 < (int *)0x4);
    if (local_14 == (int *)0x0) {
      if (local_20 == (int *)0x0) goto LAB_00605872;
      local_14 = (int *)0x1;
      iVar6 = FUN_00615991(local_7c + 8,local_c,4);
      if (iVar6 < 0) {
        return iVar6;
      }
      iVar6 = FUN_00615991(local_4c,local_c,4);
      if (iVar6 < 0) {
        return iVar6;
      }
      uVar10 = 4;
      piVar8 = local_4c;
    }
    else {
      iVar6 = FUN_00615991(local_7c,local_c,4);
      if (iVar6 < 0) {
        return iVar6;
      }
      uVar10 = 4;
LAB_00605856:
      piVar8 = local_7c;
    }
    iVar6 = FUN_00615991(piVar8 + 4,local_c,uVar10);
    if (iVar6 < 0) {
      return iVar6;
    }
    if (local_14 != (int *)0x0) goto LAB_006058cb;
  }
  else if (local_1c == (int *)0x3) {
    local_20 = (int *)0xffffffff;
    piVar8 = (int *)0x0;
    do {
      if (local_b0[(int)piVar8] == -1) {
        local_20 = piVar8;
      }
      piVar8 = (int *)((int)piVar8 + 1);
    } while (piVar8 < (int *)0x4);
    local_10 = (int *)0x0;
    do {
      if (local_14 != (int *)0x0) goto LAB_0060583c;
      piVar8 = (int *)0x0;
      do {
        piVar5 = local_10;
        piVar9 = local_20;
        if (local_14 != (int *)0x0) break;
        if (((piVar8 != local_10) && (piVar8 != local_20)) && (local_10 != local_20)) {
          local_7c[0] = -1;
          local_7c[1] = -1;
          local_7c[2] = -1;
          local_7c[3] = -1;
          local_7c[4] = 0;
          local_7c[5] = 0;
          local_7c[6] = 0;
          local_7c[7] = 0;
          local_7c[(int)local_10] = 0;
          local_7c[(int)piVar8] = 0;
          local_7c[(int)(piVar5 + 1)] = -1;
          local_7c[(int)(piVar8 + 1)] = -1;
          local_7c[(int)(piVar9 + 1)] = -1;
          piVar9 = (int *)0x0;
          local_8 = (int *)0x0;
          if (local_c != (int *)0x0) {
            local_18 = local_b0;
            do {
              if (local_8 != (int *)0x0) break;
              iVar6 = FUN_00604ee2(local_18,local_7c,5);
              if (iVar6 == 0) {
                local_8 = (int *)0x1;
              }
              local_18 = local_18 + 4;
              piVar9 = (int *)((int)piVar9 + 1);
            } while (piVar9 < local_c);
          }
          if ((local_7c[3] == 0) &&
             ((((local_7c[0] == 0 || (local_7c[1] == 0)) || (local_7c[2] == 0)) &&
              (local_4c[8] != 0)))) {
            local_8 = (int *)0x1;
          }
          if (local_8 == (int *)0x0) {
            local_14 = (int *)0x1;
          }
        }
        piVar8 = (int *)((int)piVar8 + 1);
      } while (piVar8 < (int *)0x4);
      local_10 = (int *)((int)local_10 + 1);
    } while (local_10 < (int *)0x4);
    if (local_14 != (int *)0x0) {
LAB_0060583c:
      iVar6 = FUN_00615991(local_7c,local_c,3);
      if (iVar6 < 0) {
        return iVar6;
      }
      uVar10 = 3;
      goto LAB_00605856;
    }
  }
LAB_00605872:
  piVar8 = (int *)0x0;
  if (local_1c != (int *)0x0) {
    do {
      piVar5 = local_c;
      piVar9 = local_1c;
      local_7c[0] = -1;
      local_7c[1] = 0xffffffff;
      local_7c[2] = 0xffffffff;
      local_7c[3] = 0xffffffff;
      local_7c[*(int *)(*(int *)(*(int *)((int)param_1 + 0x14) +
                                *(int *)(*(int *)(*(int *)((int)param_1 + 0x98) + 0x10) +
                                        (int)piVar8 * 4) * 4) + 0xc)] = 0;
      iVar6 = FUN_00615991(local_7c,piVar5,piVar9);
      if (iVar6 < 0) {
        return iVar6;
      }
      piVar8 = (int *)((int)piVar8 + 1);
    } while (piVar8 < local_1c);
  }
LAB_006058cb:
  **(undefined4 **)((int)param_1 + 0x98) = 0;
  return 0;
}


// ==== 0x6058f6 FUN_006058f6

/* WARNING: Type propagation algorithm not settling */

int __thiscall FUN_006058f6(int param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  bool bVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 local_128 [16];
  undefined1 local_e8 [16];
  int aiStack_d8 [4];
  int aiStack_c8 [4];
  int aiStack_b8 [4];
  int aiStack_a8 [4];
  int aiStack_98 [4];
  int aiStack_88 [4];
  int local_78 [12];
  undefined4 local_48;
  int local_44 [9];
  int local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  int *local_c;
  int local_8;
  
  if (0x103 < (*(uint *)(param_1 + 0x30) & 0xffff)) {
    return 1;
  }
  uVar7 = 0;
  local_1c = 0;
  local_48 = 0;
  local_44[0] = 1;
  local_44[1] = 2;
  local_44[2] = 3;
  local_8 = param_1;
  if ((**(uint **)(param_1 + 0x98) & 0xffffff) == 3) {
    do {
      iVar1 = FUN_006139d8(*(undefined4 *)(param_1 + 0x98),(&PTR_DAT_006df4c8)[uVar7],local_128,
                           &local_1c,local_e8,&local_48,3);
      if (iVar1 == 0) break;
      uVar7 = uVar7 + 1;
    } while (uVar7 < 9);
    local_14 = 0;
    local_18 = 0;
    if (4 < uVar7) {
      local_18 = 1;
    }
    local_18 = (uint)(4 < uVar7);
    if (iVar1 != 0) {
      uVar7 = 0;
      do {
        iVar1 = FUN_006139d8(*(undefined4 *)(param_1 + 0x98),(&PTR_DAT_006df4ec)[uVar7],local_128,
                             &local_1c,local_e8,&local_48,3);
        if (iVar1 == 0) break;
        uVar7 = uVar7 + 1;
      } while (uVar7 < 3);
      local_18 = 0;
      if (1 < uVar7) {
        local_18 = 1;
      }
      local_18 = (uint)(1 < uVar7);
      local_14 = 1;
      if (iVar1 != 0) goto LAB_0060594c;
    }
    local_10 = 0;
    iVar1 = *(int *)(param_1 + 0x14);
    local_20 = 0xc - (int)(local_44 + 3);
    do {
      iVar4 = aiStack_d8[local_10];
      piVar5 = *(int **)(iVar1 + iVar4 * 4);
      if (piVar5[3] != local_10) {
        return 1;
      }
      if (param_2 == 0) {
        if (local_18 == 0) {
          if (piVar5[0xb] == -1) {
            return 1;
          }
          piVar5 = *(int **)(*(int *)(local_8 + 0x18) + piVar5[0xb] * 4);
          if (*piVar5 != 0x25000003) {
            return 1;
          }
          iVar4 = piVar5[2];
          local_c = *(int **)(local_10 * 4 + iVar4);
          piVar5 = *(int **)(iVar1 + (int)local_c * 4);
          if ((*(byte *)(*(int *)(*(int *)(local_8 + 0x10) + *piVar5 * 4) + 5) & 1) == 0) {
            return 1;
          }
          if (piVar5[3] != local_10) {
            return 1;
          }
          piVar5 = local_44 + local_10 + 3;
          piVar6 = *(int **)(iVar1 + *(int *)((0xc - (int)(local_44 + 3)) + iVar4 + (int)piVar5) * 4
                            );
          if ((*(byte *)(*(int *)(*(int *)(local_8 + 0x10) + *piVar6 * 4) + 4) & 0x80) == 0) {
            return 1;
          }
          if (*(double *)(piVar6 + 4) != -1.0) {
            return 1;
          }
          *piVar5 = (int)local_c;
        }
        else {
          if ((*(byte *)(*(int *)(*(int *)(local_8 + 0x10) + *piVar5 * 4) + 5) & 1) == 0) {
            return 1;
          }
          piVar5 = local_44 + local_10 + 3;
          *piVar5 = iVar4;
        }
        piVar6 = aiStack_b8 + local_10;
        local_c = (int *)*piVar5;
        if ((*piVar6 != *piVar5) || (iVar4 = aiStack_c8[local_10], aiStack_a8[local_10] != iVar4)) {
LAB_00605bb6:
          bVar10 = (int *)aiStack_a8[local_10] == local_c;
          goto LAB_00605bba;
        }
        piVar5 = aiStack_98 + local_10;
        iVar1 = *piVar5;
        if ((iVar1 != aiStack_88[local_10]) || (aiStack_a8[local_10] != iVar1)) goto LAB_00605bb6;
      }
      else {
        if (piVar5[0xb] != -1) {
          return 1;
        }
        if (*piVar5 != *(int *)(local_8 + 0x58)) {
          return 1;
        }
        if ((uint)*(byte *)((int)piVar5 + 0x51) != local_10 + 1) {
          return 1;
        }
        if ((char)piVar5[0x14] != '\x05') {
          return 1;
        }
        local_44[local_10 + 3] = iVar4;
        if (local_18 == 0) {
          if (piVar5[8] != 0x80000) {
            return 1;
          }
          piVar6 = aiStack_b8 + local_10;
          local_c = (int *)piVar5[9];
          if ((*piVar6 == piVar5[9]) &&
             (iVar4 = aiStack_c8[local_10], aiStack_a8[local_10] == iVar4)) {
            piVar5 = aiStack_98 + local_10;
            iVar1 = *piVar5;
            if ((iVar1 == aiStack_88[local_10]) && (aiStack_a8[local_10] == iVar1))
            goto LAB_00605bd4;
          }
          goto LAB_00605bb6;
        }
        if (piVar5[8] != 0) {
          return 1;
        }
        piVar6 = aiStack_b8 + local_10;
        if (*piVar6 == iVar4) {
          iVar4 = aiStack_c8[local_10];
          if (aiStack_a8[local_10] == iVar4) {
            piVar5 = aiStack_98 + local_10;
            iVar1 = *piVar5;
            if ((iVar1 == aiStack_88[local_10]) && (aiStack_a8[local_10] == iVar1))
            goto LAB_00605bd4;
          }
        }
        bVar10 = aiStack_a8[local_10] == aiStack_d8[local_10];
LAB_00605bba:
        if (!bVar10) {
          return 1;
        }
        iVar4 = piVar6[-4];
        if (*piVar6 != iVar4) {
          return 1;
        }
        piVar5 = aiStack_98 + local_10;
        iVar1 = *piVar5;
        if (iVar1 != piVar6[0xc]) {
          return 1;
        }
        if (*piVar6 != iVar1) {
          return 1;
        }
      }
LAB_00605bd4:
      local_44[local_10 + 6] = iVar4;
      if (((local_14 != 0) && (iVar1 != piVar5[8])) ||
         (iVar1 = *(int *)(local_8 + 0x14), *(uint *)(*(int *)(iVar1 + iVar4 * 4) + 0xc) != local_10
         )) {
        return 1;
      }
      local_10 = local_10 + 1;
    } while (local_10 < 3);
    uVar7 = 0;
    if (local_1c != 0) {
      do {
        puVar8 = local_128 + uVar7;
        uVar7 = uVar7 + 1;
        *(undefined4 *)*puVar8 = 0;
      } while (uVar7 < local_1c);
    }
    pvVar2 = _malloc(0x38);
    if (pvVar2 == (void *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_005f7709();
    }
    iVar4 = local_8;
    if (iVar1 == 0) {
      local_14 = -0x7ff8fff2;
    }
    else {
      if (param_2 == 0) {
        uVar12 = 9;
        uVar11 = 0xef000003;
      }
      else {
        uVar12 = 6;
        uVar11 = 0xee000003;
      }
      iVar3 = FUN_005f7760(uVar11,uVar12,*(undefined4 *)(*(int *)(local_8 + 0x98) + 0xc),0);
      if (iVar3 < 0) {
        FUN_005f7186(1);
        local_14 = iVar3;
      }
      else {
        local_14 = FUN_005f7a42(*(undefined4 *)(iVar4 + 0x98));
        if (local_14 < 0) {
          FUN_005f7186(1);
        }
        else {
          puVar8 = *(undefined4 **)(*(int *)(local_8 + 0x98) + 0x10);
          puVar9 = *(undefined4 **)(iVar1 + 0x10);
          for (uVar7 = *(uint *)(*(int *)(local_8 + 0x98) + 0xc) & 0x3fffffff; uVar7 != 0;
              uVar7 = uVar7 - 1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
          for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
            *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar9 = (undefined4 *)((int)puVar9 + 1);
          }
          uVar7 = 0xc;
          local_c = local_44;
          do {
            *(undefined4 *)((uVar7 - 0xc) + *(int *)(iVar1 + 8)) =
                 **(undefined4 **)(*(int *)(local_8 + 0x98) + 8);
            *(undefined4 *)(uVar7 + *(int *)(iVar1 + 8)) =
                 *(undefined4 *)((int)local_44 + uVar7 + 0xc);
            if (param_2 == 0) {
              *(undefined4 *)(uVar7 + 0xc + *(int *)(iVar1 + 8)) =
                   *(undefined4 *)((int)local_44 + uVar7);
            }
            uVar7 = uVar7 + 4;
          } while (uVar7 < 0x18);
          piVar5 = (int *)(local_8 + 0x94);
          if (*(int *)(*(int *)(local_8 + 0x18) + *piVar5 * 4) != 0) {
            FUN_005f7186(1);
          }
          *(int *)(*(int *)(local_8 + 0x18) + *piVar5 * 4) = iVar1;
        }
      }
    }
  }
  else {
LAB_0060594c:
    local_14 = 1;
  }
  return local_14;
}


// ==== 0x605d41 FUN_00605d41

undefined4 __fastcall FUN_00605d41(int param_1)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int *local_10;
  uint local_c;
  uint local_8;
  
  uVar5 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    piVar8 = *(int **)(param_1 + 0x18);
    do {
      *(uint *)(param_1 + 0x94) = uVar5;
      puVar1 = (uint *)*piVar8;
      *(uint **)(param_1 + 0x98) = puVar1;
      if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
        uVar3 = *puVar1 & 0xff000000;
        if (uVar3 < 0x4a000001) {
          if (uVar3 == 0x4a000000) {
            iVar4 = 2;
          }
          else {
            if (uVar3 != 0x42000000) {
              if (uVar3 == 0x43000000) {
                iVar4 = 0;
              }
              else {
                if (uVar3 == 0x46000000) {
                  iVar4 = 1;
                  iVar7 = iVar4;
                  goto LAB_00605e7e;
                }
                if (uVar3 != 0x47000000) goto LAB_00605dd5;
                iVar4 = 1;
              }
              goto LAB_00605e7c;
            }
            iVar4 = 0;
          }
LAB_00605e74:
          iVar7 = 1;
        }
        else {
          if (uVar3 == 0x4b000000) {
            iVar4 = 2;
          }
          else {
            if (uVar3 == 0x4e000000) {
              iVar4 = 3;
              goto LAB_00605e74;
            }
            if (uVar3 != 0x4f000000) goto LAB_00605dd5;
            iVar4 = 3;
          }
LAB_00605e7c:
          iVar7 = 0;
        }
LAB_00605e7e:
        FUN_005fbec8(param_1,puVar1[0xd],0x11b4,"%s%s is not supported on ps_1_%i",
                     (&PTR_s_tex1D_006df598)[iVar4],(&PTR_DAT_006df5a8)[iVar7],
                     *(uint *)(param_1 + 0x30) & 0xff);
        return 0x80004005;
      }
LAB_00605dd5:
      uVar5 = uVar5 + 1;
      piVar8 = piVar8 + 1;
    } while (uVar5 < *(uint *)(param_1 + 0xc));
  }
  local_8 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    local_10 = *(int **)(param_1 + 0x18);
    do {
      *(uint *)(param_1 + 0x94) = local_8;
      piVar8 = (int *)*local_10;
      *(int **)(param_1 + 0x98) = piVar8;
      if (((piVar8 != (int *)0x0) && (*piVar8 != 0)) && (local_c = 0, piVar8[1] != 0)) {
        piVar6 = (int *)piVar8[2];
        do {
          piVar2 = *(int **)(*(int *)(param_1 + 0x14) + *piVar6 * 4);
          if ((*piVar2 == *(int *)(param_1 + 0x58)) && ((char)piVar2[0x14] == '\x05')) {
            FUN_005fbec8(param_1,piVar8[0xd],0x11a0,
                         "cannot access w component from texcoord in general expression");
            return 0x80004005;
          }
          local_c = local_c + 1;
          piVar6 = piVar6 + 1;
        } while (local_c < *(uint *)(*(int *)(param_1 + 0x98) + 4));
      }
      local_8 = local_8 + 1;
      local_10 = local_10 + 1;
    } while (local_8 < *(uint *)(param_1 + 0xc));
  }
  return 0;
}


// ==== 0x605ecb FUN_00605ecb

int * __fastcall FUN_00605ecb(int *param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int local_10c [4];
  int local_fc [4];
  undefined4 auStack_ec [32];
  undefined4 local_6c [16];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  int local_10;
  uint local_c;
  int *local_8;
  
  local_14 = 0;
  local_2c = 0;
  local_28 = 1;
  local_24 = 2;
  local_20 = 3;
  uVar7 = *(uint *)param_1[0x26] & 0xffffff;
  local_c = 0;
  iVar2 = FUN_006139d8((uint *)param_1[0x26],&DAT_006a4048,local_6c,&local_14,local_10c,&local_2c,
                       uVar7);
  if (iVar2 == 0) {
LAB_00605f61:
    local_1c = 0;
    if (local_c != 0) {
      uVar4 = *(uint *)(*(int *)(param_1[4] + **(int **)(param_1[5] + local_fc[0] * 4) * 4) + 4);
      local_1c = (uint)((uVar4 & 0x100) != 0);
      if (((*(uint *)(*(int *)(param_1[4] + **(int **)(param_1[5] + local_10c[0] * 4) * 4) + 4) &
           0x180) != 0) && ((uVar4 & 0x180) != 0)) {
        return (int *)0x1;
      }
    }
    pvVar3 = _malloc(0x38);
    if (pvVar3 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_005f7709();
    }
    if (iVar2 == 0) {
      return (int *)0x8007000e;
    }
    if (local_c == 0) {
      uVar4 = uVar7 | 0xf5000000;
    }
    else {
      uVar4 = uVar7 | 0xf6000000;
    }
    local_8 = (int *)FUN_005f7760(uVar4,uVar7 * 3,uVar7,0);
    if (((int)local_8 < 0) || (local_8 = (int *)FUN_005f7a42(param_1[0x26]), (int)local_8 < 0))
    goto LAB_006060fb;
    local_c = 0;
    if (uVar7 != 0) {
      local_18 = uVar7 << 3;
      local_10 = uVar7 << 2;
      do {
        uVar4 = local_c;
        iVar1 = local_10;
        iVar6 = local_18;
        iVar5 = local_c * 4;
        *(undefined4 *)(iVar5 + *(int *)(iVar2 + 0x10)) =
             *(undefined4 *)(iVar5 + *(int *)(param_1[0x26] + 0x10));
        local_8 = local_fc + local_c;
        if (local_1c == 0) {
          *(int *)(iVar5 + *(int *)(iVar2 + 8)) = local_10c[local_c];
          iVar5 = *local_8;
        }
        else {
          *(int *)(iVar5 + *(int *)(iVar2 + 8)) = *local_8;
          iVar5 = local_10c[local_c];
        }
        local_c = local_c + 1;
        local_10 = local_10 + 4;
        *(int *)(iVar1 + *(int *)(iVar2 + 8)) = iVar5;
        local_18 = local_18 + 4;
        *(undefined4 *)(iVar6 + *(int *)(iVar2 + 8)) = auStack_ec[uVar4];
      } while (local_c < uVar7);
    }
    iVar6 = (**(code **)(*param_1 + 0x24))(iVar2,0);
    if (iVar6 != 0) {
      local_8 = (int *)0x1;
      goto LAB_006060fb;
    }
    uVar7 = 0;
    if (local_14 != 0) {
      do {
        *(undefined4 *)local_6c[uVar7] = 0;
        uVar7 = uVar7 + 1;
      } while (uVar7 < local_14);
    }
    if (param_1[0x26] != 0) {
      FUN_005f7186(1);
    }
    *(int *)(param_1[6] + param_1[0x25] * 4) = iVar2;
  }
  else {
    iVar2 = FUN_006139d8(param_1[0x26],&DAT_006a40a8,local_6c,&local_14,local_10c,&local_2c,uVar7);
    local_c = 1;
    if (iVar2 == 0) goto LAB_00605f61;
  }
  iVar2 = 0;
  local_8 = (int *)0x0;
LAB_006060fb:
  if (iVar2 != 0) {
    FUN_005f7186(1);
  }
  return local_8;
}


// ==== 0x606110 FUN_00606110

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * __fastcall FUN_00606110(int param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  float fVar4;
  uint uVar5;
  void *pvVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  int iVar10;
  undefined4 *puVar11;
  uint uVar12;
  undefined4 *puVar13;
  uint local_90 [16];
  uint local_50 [8];
  uint *local_30;
  uint *local_2c;
  int *local_28;
  uint *local_24;
  float local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint *local_10;
  undefined4 local_c;
  uint *local_8;
  
  local_1c = 0;
  local_c = 0;
  uVar5 = **(uint **)(param_1 + 0x98);
  puVar7 = (uint *)(*(uint **)(param_1 + 0x98))[2];
  local_18 = uVar5 & 0xffffff;
  puVar8 = puVar7 + local_18;
  local_28 = *(int **)(*(int *)(param_1 + 0x14) + *puVar7 * 4);
  piVar2 = *(int **)(*(int *)(param_1 + 0x14) + *puVar8 * 4);
  iVar10 = *local_28;
  local_8 = *(uint **)(*(int *)(param_1 + 0x10) + iVar10 * 4);
  if (((iVar10 == *(int *)(param_1 + 0x60)) &&
      ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4) + 4) & 0x80) != 0)) &&
     ((uVar5 & 0xff000000) == 0x25000000)) {
    local_10 = puVar7;
    puVar7 = puVar8;
LAB_00606189:
    local_20 = (float)*(double *)(*(int *)(*(int *)(param_1 + 0x14) + *puVar7 * 4) + 0x10);
LAB_00606194:
    local_14 = 0;
    if (local_18 != 0) {
      iVar10 = (int)local_10 - (int)puVar7;
      do {
        uVar5 = local_1c;
        iVar3 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar10 + (int)puVar7) * 4);
        if (local_c == 0) {
          local_8 = *(uint **)(*(int *)(param_1 + 0x14) + *puVar7 * 4);
        }
        else {
          local_8 = (uint *)0x0;
        }
        if (((*(int *)(iVar3 + 0x3c) != *(int *)(param_1 + 0x94)) ||
            (*(int *)(iVar3 + 0x38) != *(int *)(param_1 + 0x94))) ||
           ((*(uint *)(iVar3 + 0x20) & 0xffe00) != 0)) goto LAB_00606266;
        uVar12 = 0;
        if (local_1c != 0) {
          do {
            if (*(uint *)(iVar3 + 0x2c) == local_50[uVar12 + 4]) break;
            uVar12 = uVar12 + 1;
          } while (uVar12 < local_1c);
        }
        if (uVar12 == local_1c) {
          local_1c = local_1c + 1;
          local_50[uVar5 + 4] = *(uint *)(iVar3 + 0x2c);
        }
        if ((local_c == 0) && ((double)local_20 != *(double *)(local_8 + 4))) goto LAB_00606266;
        local_14 = local_14 + 1;
        puVar7 = puVar7 + 1;
      } while (local_14 < local_18);
    }
    fVar4 = ABS(local_20);
    if ((ABS(fVar4) == 2.0) && ((*(byte *)(param_1 + 0x91) & 2) != 0)) {
      local_c = 0x400;
    }
    else if ((fVar4 == (float)_K_BLUR_PASS2_MUL) && ((*(byte *)(param_1 + 0x91) & 4) != 0)) {
      local_c = 0x800;
    }
    else if ((fVar4 == 8.0) && ((*(byte *)(param_1 + 0x91) & 8) != 0)) {
      local_c = 0x1000;
    }
    else if ((fVar4 == 0.5) && ((*(byte *)(param_1 + 0x91) & 0x10) != 0)) {
      local_c = 0x2000;
    }
    else if ((fVar4 == 0.25) && ((*(byte *)(param_1 + 0x91) & 0x20) != 0)) {
      local_c = 0x4000;
    }
    else {
      if ((fVar4 != 0.125) || ((*(byte *)(param_1 + 0x91) & 0x40) == 0)) goto LAB_00606266;
      local_c = 0x8000;
    }
    if (local_20 < 0.0) {
      local_c = (uint)CONCAT12(8,(undefined2)local_c);
    }
    local_50[0] = 0;
    local_50[1] = 0;
    local_50[2] = 0;
    local_50[3] = 0;
    local_14 = 0;
    if (local_1c != 0) {
      local_24 = local_90;
      local_8 = (uint *)0x0;
      do {
        puVar7 = local_24;
        puVar8 = *(uint **)(*(int *)(param_1 + 0x18) + local_50[local_14 + 4] * 4);
        uVar5 = *puVar8 & 0xff000000;
        if ((((uVar5 == 0x40000000) || (uVar5 == 0x48000000)) || (uVar5 == 0x44000000)) ||
           (uVar5 == 0x4c000000)) goto LAB_00606266;
        uVar5 = puVar8[3];
        puVar9 = local_24 + 1;
        *local_24 = 0xffffffff;
        *puVar9 = 0xffffffff;
        puVar7[2] = 0xffffffff;
        puVar7[3] = 0xffffffff;
        uVar12 = 0;
        local_28 = (int *)0x0;
        if (local_18 != 0) {
          do {
            local_2c = (uint *)0x0;
            if (uVar5 != 0) {
              local_30 = (uint *)puVar8[4];
              puVar7 = (uint *)((int)local_90 + (int)local_8);
              do {
                if (*local_30 == local_10[uVar12]) {
                  local_50[local_14] = local_50[local_14] + 1;
                  bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x14) +
                                            *(int *)(*(int *)(*(int *)(param_1 + 0x98) + 0x10) +
                                                    uVar12 * 4) * 4) + 0x21);
                  *puVar7 = uVar12;
                  if (((bVar1 & 2) != 0) && (local_20 < 0.0)) goto LAB_00606266;
                  local_28 = (int *)((int)local_28 + 1);
                }
                local_2c = (uint *)((int)local_2c + 1);
                uVar5 = puVar8[3];
                local_30 = local_30 + 1;
                puVar7 = puVar7 + 1;
              } while (local_2c < uVar5);
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 < local_18);
        }
        if (local_28 != (int *)uVar5) goto LAB_00606266;
        local_14 = local_14 + 1;
        local_24 = local_24 + 4;
        local_8 = local_8 + 4;
      } while (local_14 < local_1c);
    }
    local_18 = 0;
    if (local_1c != 0) {
      local_2c = local_90;
      do {
        puVar8 = *(uint **)(local_50[local_18 + 4] * 4 + *(int *)(param_1 + 0x18));
        local_30 = (uint *)(local_50[local_18 + 4] * 4);
        local_24 = puVar8;
        local_28 = (int *)local_50[local_18];
        if (local_50[local_18] != puVar8[3]) {
          pvVar6 = _malloc(0x38);
          if (pvVar6 == (void *)0x0) {
            puVar7 = (uint *)0x0;
          }
          else {
            puVar7 = (uint *)FUN_005f7709();
          }
          if (puVar7 == (uint *)0x0) {
            return (uint *)0x8007000e;
          }
          local_8 = puVar7;
          local_10 = (uint *)FUN_005f7760(*puVar8,puVar8[1],local_28,0);
          if ((int)local_10 < 0) {
            FUN_005f7186(1);
            return local_10;
          }
          puVar8 = (uint *)FUN_005f7a42(puVar8);
          if ((int)puVar8 < 0) {
            FUN_005f7186(1);
            return puVar8;
          }
          puVar11 = (undefined4 *)local_24[2];
          puVar13 = (undefined4 *)puVar7[2];
          for (uVar5 = local_24[1] & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar13 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar13 = puVar13 + 1;
          }
          for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
            *(undefined1 *)puVar13 = *(undefined1 *)puVar11;
            puVar11 = (undefined4 *)((int)puVar11 + 1);
            puVar13 = (undefined4 *)((int)puVar13 + 1);
          }
          FUN_005f7186(1);
          *(uint **)((int)local_30 + *(int *)(param_1 + 0x18)) = local_8;
          local_24 = local_8;
          puVar8 = local_8;
        }
        local_14 = 0;
        if (local_28 != (int *)0x0) {
          local_8 = local_2c;
          uVar5 = local_14;
          puVar7 = local_2c;
          do {
            for (; (uVar5 < 4 && (*puVar7 == 0xffffffff)); puVar7 = puVar7 + 1) {
              uVar5 = uVar5 + 1;
            }
            local_10 = (uint *)0x0;
            iVar10 = uVar5 * 4;
            *(undefined4 *)(puVar8[4] + local_14 * 4) =
                 *(undefined4 *)(iVar10 + *(int *)(*(int *)(param_1 + 0x98) + 0x10));
            puVar7 = (uint *)(*(int *)(*(int *)(param_1 + 0x14) +
                                      *(int *)(iVar10 + *(int *)(*(int *)(param_1 + 0x98) + 0x10)) *
                                      4) + 0x20);
            *puVar7 = *puVar7 | local_c;
            if (*(int *)(param_1 + 8) != 0) {
              do {
                iVar3 = *(int *)(*(int *)(param_1 + 0x14) + (int)local_10 * 4);
                if (*(int *)(iVar3 + 0x24) ==
                    *(int *)(iVar10 + *(int *)(*(int *)(param_1 + 0x98) + 0x10))) {
                  *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) | local_c & 0xfff7ffff;
                  uVar5 = *(uint *)(iVar3 + 0x20);
                  if (local_20 < 0.0) {
                    if ((uVar5 & 0x80000) == 0) {
                      uVar5 = uVar5 | 0x80000;
                    }
                    else {
                      uVar5 = uVar5 & 0xfff7ffff;
                    }
                    *(uint *)(iVar3 + 0x20) = uVar5;
                  }
                }
                local_10 = (uint *)((int)local_10 + 1);
              } while (local_10 < *(uint **)(param_1 + 8));
            }
            local_14 = local_14 + 1;
            local_8 = local_8 + 1;
            uVar5 = local_14;
            puVar7 = local_8;
          } while (local_14 < local_28);
        }
        local_18 = local_18 + 1;
        local_2c = local_2c + 4;
      } while (local_18 < local_1c);
    }
    **(undefined4 **)(param_1 + 0x98) = 0;
    puVar8 = (uint *)0x0;
  }
  else {
    local_24 = (uint *)*piVar2;
    if (((local_24 == (uint *)*(int *)(param_1 + 0x60)) && ((local_8[1] & 0x80) != 0)) &&
       ((uVar5 & 0xff000000) == 0x25000000)) {
      local_10 = puVar8;
      goto LAB_00606189;
    }
    if (((iVar10 == *(int *)(param_1 + 0x60)) && (local_24 == (uint *)*(int *)(param_1 + 0x60))) &&
       ((uVar5 & 0xff000000) == 0x24000000)) {
      local_c = 1;
      if (local_18 != 0) {
        puVar9 = puVar7;
        uVar5 = local_18;
        do {
          if (*puVar9 != *(uint *)(((int)puVar8 - (int)puVar7) + (int)puVar9)) {
            local_c = 0;
          }
          puVar9 = puVar9 + 1;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
      uVar5 = local_28[8];
      if (uVar5 != piVar2[8]) goto LAB_00606266;
      if (uVar5 == 0x80000) {
        local_20 = -1.0;
      }
      else {
        if ((uVar5 & 0x80000) != 0) goto LAB_00606266;
        local_20 = 1.0;
      }
      local_10 = puVar7;
      if (local_c == 0) goto LAB_00606266;
      local_20 = local_20 + local_20;
      puVar7 = local_8;
      goto LAB_00606194;
    }
LAB_00606266:
    puVar8 = (uint *)0x1;
  }
  return puVar8;
}


// ==== 0x6066d1 FUN_006066d1

undefined4 __thiscall
FUN_006066d1(int param_1,int param_2,uint param_3,uint param_4,uint param_5,uint param_6,int param_7
            )

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_10 = 0;
  if (param_3 != 0) {
    do {
      piVar1 = *(int **)(param_2 + local_10 * 4);
      if (((piVar1 != (int *)0x0) && (*piVar1 != 0)) && (local_c = 0, piVar1[1] != 0)) {
        do {
          piVar2 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)(piVar1[2] + local_c * 4) * 4);
          if (((*piVar2 == *(int *)(param_1 + 0x58)) && ((piVar2[0x14] & 0xffU) == param_4)) &&
             (param_5 == *(byte *)((int)piVar2 + 0x51))) {
            local_8 = 0;
            if (param_6 != 0) {
              do {
                if (piVar2[3] ==
                    *(int *)(*(int *)(*(int *)(param_1 + 0x14) + *(int *)(param_7 + local_8 * 4) * 4
                                     ) + 0xc)) {
                  iVar4 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),0,piVar2[3],0);
                  if (iVar4 == -1) {
                    return 0x8007000e;
                  }
                  iVar3 = *(int *)(*(int *)(param_1 + 0x14) + iVar4 * 4);
                  *(int *)(iVar3 + 0x20) = piVar2[8];
                  *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(param_7 + local_8 * 4);
                  *(int *)(piVar1[2] + local_c * 4) = iVar4;
                  break;
                }
                local_8 = local_8 + 1;
              } while (local_8 < param_6);
            }
            if (local_8 == param_6) {
              FUN_005fbec8(param_1,0,0x12c1,"internal error: InputRemap component matchup failed");
              return 0x80004005;
            }
          }
          local_c = local_c + 1;
        } while (local_c < (uint)piVar1[1]);
      }
      local_10 = local_10 + 1;
    } while (local_10 < param_3);
  }
  return 0;
}


// ==== 0x6067f6 FUN_006067f6

undefined4 __thiscall
FUN_006067f6(int param_1,int param_2,uint param_3,uint param_4,uint param_5,uint param_6,int param_7
            )

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_10 = 0;
  if (param_3 != 0) {
    do {
      iVar1 = *(int *)(param_2 + local_10 * 4);
      if ((iVar1 != 0) && (local_c = 0, *(int *)(iVar1 + 4) != 0)) {
        do {
          piVar2 = *(int **)(*(int *)(param_1 + 0x14) +
                            *(int *)(*(int *)(iVar1 + 8) + local_c * 4) * 4);
          if ((*piVar2 == *(int *)(param_1 + 0x58)) &&
             (((piVar2[8] != 0 && ((piVar2[0x14] & 0xffU) == param_4)) &&
              (param_5 == *(byte *)((int)piVar2 + 0x51))))) {
            local_8 = 0;
            if (param_6 != 0) {
              do {
                if (piVar2[3] ==
                    *(int *)(*(int *)(*(int *)(param_1 + 0x14) + *(int *)(param_7 + local_8 * 4) * 4
                                     ) + 0xc)) {
                  iVar4 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),0,piVar2[3],0);
                  if (iVar4 == -1) {
                    return 0x8007000e;
                  }
                  iVar3 = *(int *)(*(int *)(param_1 + 0x14) + iVar4 * 4);
                  *(int *)(iVar3 + 0x20) = piVar2[8];
                  *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(param_7 + local_8 * 4);
                  *(int *)(*(int *)(iVar1 + 8) + local_c * 4) = iVar4;
                  break;
                }
                local_8 = local_8 + 1;
              } while (local_8 < param_6);
            }
            if (local_8 == param_6) {
              FUN_005fbec8(param_1,0,0x12c2,"internal error: InputRemap component matchup failed");
              return 0x80004005;
            }
          }
          local_c = local_c + 1;
        } while (local_c < *(uint *)(iVar1 + 4));
      }
      local_10 = local_10 + 1;
    } while (local_10 < param_3);
  }
  return 0;
}


// ==== 0x60691c FUN_0060691c

int __thiscall FUN_0060691c(int param_1,int param_2,uint param_3,int param_4,int *param_5)

{
  uint *puVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  undefined4 uVar8;
  char *pcVar9;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_8 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + local_8 * 4);
      if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
        bVar3 = false;
        local_10 = 0;
        if (puVar1[3] != 0) {
          do {
            local_c = 0;
            if (param_3 != 0) {
              do {
                iVar4 = *(int *)(param_2 + local_c * 4);
                piVar6 = *(int **)(*(int *)(param_1 + 0x14) + iVar4 * 4);
                if ((*piVar6 == *(int *)(param_1 + 0x58)) && ((char)piVar6[0x14] != '\x03')) {
                  pcVar9 = 
                  "cannot perform dependent texture read which in any way is based on color inputs";
                  uVar8 = 0x11a1;
                  goto LAB_00606ace;
                }
                iVar2 = *(int *)(puVar1[4] + local_10 * 4);
                if ((iVar2 == iVar4) || (iVar2 == piVar6[9])) {
                  uVar5 = puVar1[1];
                  uVar7 = *puVar1 & 0xffffff;
                  local_18 = 0;
                  if (uVar5 / uVar7 != 0) {
                    local_14 = 0;
                    do {
                      iVar4 = FUN_0060691c(puVar1[2] + local_14,uVar7,param_4,param_5);
                      if (iVar4 < 0) {
                        return iVar4;
                      }
                      local_18 = local_18 + 1;
                      local_14 = local_14 + uVar7 * 4;
                      bVar3 = true;
                    } while (local_18 < uVar5 / uVar7);
                  }
                }
                local_c = local_c + 1;
              } while (local_c < param_3);
            }
            local_10 = local_10 + 1;
          } while (local_10 < puVar1[3]);
          if (bVar3) {
            uVar5 = *puVar1 & 0xff000000;
            if ((((uVar5 == 0x40000000) || (uVar5 == 0x44000000)) || (uVar5 == 0x48000000)) ||
               (((uVar5 == 0x4c000000 || (uVar5 == 0xee000000)) ||
                ((uVar5 == 0xef000000 || (uVar5 == 0x34000000)))))) {
              uVar7 = *puVar1 & 0xffffff;
              uVar5 = uVar7 * 2;
              if (uVar7 < uVar5) {
                piVar6 = (int *)(puVar1[2] + uVar7 * 4);
                do {
                  if (**(int **)(*(int *)(param_1 + 0x14) + *piVar6 * 4) == *(int *)(param_1 + 0x60)
                     ) {
                    pcVar9 = "cannot perform double dependent texture read in ps_1_x";
                    uVar8 = 0x11b6;
LAB_00606ace:
                    FUN_005fbec8(param_1,puVar1[0xd],uVar8,pcVar9);
                    return -0x7fffbffb;
                  }
                  uVar7 = uVar7 + 1;
                  piVar6 = piVar6 + 1;
                } while (uVar7 < uVar5);
              }
            }
            *(uint **)(param_4 + *param_5 * 4) = puVar1;
            *(undefined4 *)(*(int *)(param_1 + 0x18) + local_8 * 4) = 0;
            *param_5 = *param_5 + 1;
          }
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(param_1 + 0xc));
  }
  return 0;
}


// ==== 0x606ae1 FUN_00606ae1

int __thiscall
FUN_00606ae1(int param_1,int param_2,int *param_3,int param_4,undefined4 *param_5,int param_6,
            int param_7)

{
  int iVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  uint *puVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  void *pvVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  bool bVar13;
  undefined4 uVar14;
  undefined8 uVar15;
  char *pcVar16;
  uint local_5c [6];
  int aiStack_44 [4];
  int local_34 [4];
  int *local_24;
  int local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  uint *local_14;
  int *local_10;
  uint *local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  puVar4 = local_5c;
  for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  if ((undefined4 *)((int)param_5 + param_7) != (undefined4 *)0x0) {
    local_18 = (undefined4 *)(param_6 + (int)param_5 * -4);
    do {
      if (local_8 < param_5) {
        puVar4 = *(uint **)(param_4 + (int)local_8 * 4);
      }
      else {
        puVar4 = (uint *)*local_18;
      }
      if (((puVar4 != (uint *)0x0) && (uVar11 = *puVar4 & 0xff000000, uVar11 != 0)) &&
         (((uVar11 != 0x40000000 &&
           (((((uVar11 != 0x44000000 && (uVar11 != 0x48000000)) && (uVar11 != 0x4c000000)) &&
             ((uVar11 != 0x34000000 && (uVar11 != 0xee000000)))) && (uVar11 != 0xef000000)))) ||
          (param_5 <= local_8)))) {
        local_1c = (undefined4 *)puVar4[1];
        local_14 = (undefined4 *)0x0;
        if (local_1c != (undefined4 *)0x0) {
          piVar12 = (int *)puVar4[2];
          do {
            piVar6 = *(int **)(*(int *)(param_1 + 0x14) + *piVar12 * 4);
            if (*piVar6 == *(int *)(param_1 + 0x58)) {
              if (5 < *(byte *)((int)piVar6 + 0x51)) break;
              if ((char)piVar6[0x14] == '\x03') {
                puVar4 = local_5c + *(byte *)((int)piVar6 + 0x51);
                if (local_8 < param_5) {
                  if (*puVar4 < piVar6[3] + 1U) {
                    *puVar4 = piVar6[3] + 1U;
                  }
                }
                else if ((*puVar4 < piVar6[3] + 1U) && (piVar6[8] != 0)) {
                  *puVar4 = piVar6[3] + 1U;
                }
              }
            }
            local_14 = (uint *)((int)local_14 + 1);
            piVar12 = piVar12 + 1;
          } while (local_14 < local_1c);
        }
      }
      local_8 = (undefined4 *)((int)local_8 + 1);
      local_18 = local_18 + 1;
    } while (local_8 < (undefined4 *)((int)param_5 + param_7));
  }
  local_14 = (uint *)0x0;
  do {
    local_c = local_14;
    if ((*(uint *)(param_1 + 0x30) & 0xffff) != 0x104) {
      local_c = (uint *)(2 - (int)local_14);
    }
    if (((local_c == (uint *)0x1) || (local_c == (uint *)0x0)) &&
       (local_8 = (undefined4 *)0x0, param_5 != (undefined4 *)0x0)) {
      local_1c = (undefined4 *)(param_4 + (int)param_5 * -4);
      do {
        if ((undefined4 *)0x1ff < local_8) {
          uVar15 = 0x6a50f8000011a2;
          goto LAB_00606fd1;
        }
        if (local_8 < param_5) {
          puVar4 = *(uint **)(param_4 + (int)local_8 * 4);
        }
        else {
          puVar4 = (uint *)*local_1c;
        }
        if (puVar4 != (uint *)0x0) {
          uVar11 = *puVar4 & 0xff000000;
          if ((((uVar11 == 0x40000000) || (uVar11 == 0x44000000)) ||
              ((uVar11 == 0x48000000 || ((uVar11 == 0x4c000000 || (uVar11 == 0x34000000)))))) ||
             ((uVar11 == 0xee000000 || (uVar11 == 0xef000000)))) {
            uVar5 = *puVar4 & 0xffffff;
            if (uVar11 == 0x34000000) {
              uVar5 = 0;
            }
            puVar7 = *(undefined4 **)(*(int *)(param_1 + 0x14) + ((int *)puVar4[2])[uVar5] * 4);
            piVar12 = (int *)0x0;
            if (uVar5 != 0) {
              piVar12 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)puVar4[2] * 4);
            }
            local_24 = (int *)*puVar7;
            if (((local_24 == *(int **)(param_1 + 0x58)) &&
                ((*(uint *)(param_1 + 0x30) & 0xffff) != 0x104)) && (local_c == (uint *)0x1)) {
              local_10 = (int *)(uint)*(byte *)((int)puVar7 + 0x51);
              if (local_10 < (int *)0x6) {
                if (piVar12 == (int *)0x0) {
LAB_00606d48:
                  piVar6 = (int *)(param_1 + 0x1e0 + (int)local_10 * 4);
                  if ((*piVar6 == -1) &&
                     (local_24 = (int *)(param_2 + (int)local_10 * 4), *local_24 == 0)) {
                    if (piVar12 != (int *)0x0) {
                      *(int *)(param_1 + 0x1c8 + (int)local_10 * 4) = *piVar12;
                      *piVar6 = *(int *)puVar4[2];
                      iVar10 = FUN_005f74cf(*piVar12,piVar12[2],piVar12[3],
                                            *(undefined8 *)(piVar12 + 4));
                      uVar11 = 0;
                      if ((*puVar4 & 0xffffff) != 0) {
                        do {
                          *(int *)(puVar4[2] + uVar11 * 4) = iVar10;
                          uVar11 = uVar11 + 1;
                        } while (uVar11 < (*puVar4 & 0xffffff));
                      }
                      local_20 = *(int *)(*(int *)(param_1 + 0x14) + iVar10 * 4);
                      FUN_005f7c63();
                      *(int **)(local_20 + 8) = local_10;
                      piVar12[10] = 1;
                      *(undefined4 *)(local_20 + 0x28) = 0;
                    }
                    *local_24 = (int)puVar4;
                    goto LAB_00606f53;
                  }
                  uVar2 = CONCAT44(*(undefined4 *)(param_1 + 0x30),
                                   "cannot read from same texcoord. In ps_1_%i, each sampler must have a unique TEXCOORD"
                                  );
                  uVar14 = 0x11a4;
                }
                else {
                  iVar10 = *(int *)(*(int *)(param_1 + 0x10) + *piVar12 * 4);
                  if ((*(ushort *)(iVar10 + 4) & 0x420) == 0) {
                    piVar12[2] = (int)local_10;
                    goto LAB_00606d48;
                  }
                  if (local_10 == (int *)piVar12[2]) goto LAB_00606d48;
                  if ((*(byte *)(iVar10 + 5) & 4) == 0) {
                    pcVar16 = 
                    "cannot bind sampler to sampler array. In ps_1_%i, samplers must be bound to the same stage as their TEXCOORD"
                    ;
                  }
                  else {
                    pcVar16 = 
                    "cannot bind sampler to user specified stage. In ps_1_%i, samplers must be bound to the same stage as their TEXCOORD"
                    ;
                  }
                  uVar2 = CONCAT44(*(undefined4 *)(param_1 + 0x30),pcVar16);
                  uVar14 = 0x11a3;
                }
                uVar11 = puVar4[0xd];
LAB_006071ab:
                FUN_005fbec8(param_1,uVar11,uVar14,uVar2 & 0xffffffffff);
                return -0x7fffbffb;
              }
              goto LAB_0060713e;
            }
            if (local_c != (uint *)0x0) goto LAB_00606f5d;
            if (piVar12 == (int *)0x0) {
LAB_00606e75:
              piVar6 = (int *)0x0;
              bVar13 = *(int *)(param_1 + 0x88) == 0;
              if (*(int *)(param_1 + 0x88) != 0) {
                local_10 = (int *)(param_1 + 0x1e0);
                do {
                  if ((*(int *)(param_2 + (int)piVar6 * 4) == 0) &&
                     ((*local_10 == *(int *)puVar4[2] || (*local_10 == -1)))) break;
                  local_10 = local_10 + 1;
                  piVar6 = (int *)((int)piVar6 + 1);
                } while (piVar6 < *(int **)(param_1 + 0x88));
                bVar13 = piVar6 == *(int **)(param_1 + 0x88);
              }
              if (bVar13) goto LAB_00606fc7;
              local_10 = piVar6;
              if (piVar12 != (int *)0x0) {
                if (((*(uint *)(param_1 + 0x30) & 0xffff) == 0x104) ||
                   (local_24 == *(int **)(param_1 + 0x58))) {
                  *(int *)(param_1 + 0x1c8 + (int)piVar6 * 4) = *piVar12;
                  *(undefined4 *)(param_1 + 0x1e0 + (int)piVar6 * 4) = *(undefined4 *)puVar4[2];
                }
                iVar10 = FUN_005f74cf(*piVar12,piVar12[2],piVar12[3],*(undefined8 *)(piVar12 + 4));
                uVar11 = 0;
                if ((*puVar4 & 0xffffff) != 0) {
                  do {
                    *(int *)(puVar4[2] + uVar11 * 4) = iVar10;
                    uVar11 = uVar11 + 1;
                  } while (uVar11 < (*puVar4 & 0xffffff));
                }
                local_24 = *(int **)(*(int *)(param_1 + 0x14) + iVar10 * 4);
                FUN_005f7c63();
                local_24[2] = (int)local_10;
                piVar12[10] = 1;
                local_24[10] = 0;
                piVar6 = local_10;
              }
            }
            else {
              local_20 = *(int *)(*(int *)(param_1 + 0x10) + *piVar12 * 4);
              piVar6 = (int *)piVar12[2];
              if ((int *)0x5 < piVar6) goto LAB_0060713e;
              if ((*(ushort *)(local_20 + 4) & 0x420) == 0) goto LAB_00606e75;
              puVar7 = (undefined4 *)(param_1 + 0x1e0 + (int)piVar6 * 4);
              local_24 = (int *)*puVar7;
              if ((local_24 == (int *)0xffffffff) && (*(int *)(param_2 + (int)piVar6 * 4) == 0)) {
                *(int *)(param_1 + 0x1c8 + (int)piVar6 * 4) = *piVar12;
                *puVar7 = *(undefined4 *)puVar4[2];
              }
              else {
                if (local_24 != *(int **)puVar4[2]) {
                  if ((*(byte *)(local_20 + 5) & 4) == 0) {
                    pcVar16 = "conflicting sampler array bindings";
                  }
                  else {
                    pcVar16 = 
                    "conflicting user defined sampler bindings. If two samplers have the same user binding, they cannot both be used in the same shader"
                    ;
                  }
                  uVar15 = CONCAT44(pcVar16,0x11a5);
                  goto LAB_00606fd1;
                }
                if (*(int *)(param_2 + (int)piVar6 * 4) != 0) {
                  uVar2 = CONCAT44(*(undefined4 *)(param_1 + 0x30),
                                   "cannot perform texture lookup twice from a user bound or similar array access sampler in ps_1_%i"
                                  );
                  uVar14 = 0x11a6;
                  uVar11 = 0;
                  goto LAB_006071ab;
                }
              }
            }
            *(uint **)(param_2 + (int)piVar6 * 4) = puVar4;
LAB_00606f53:
            *(undefined4 *)(param_4 + (int)local_8 * 4) = 0;
          }
        }
LAB_00606f5d:
        local_8 = (undefined4 *)((int)local_8 + 1);
        local_1c = local_1c + 1;
      } while (local_8 < param_5);
    }
    if ((local_c == (uint *)0x2) && (local_8 = (undefined4 *)0x0, *(int *)(param_1 + 0x7c) != 0)) {
      puVar4 = local_5c;
      local_c = puVar4;
      do {
        local_c = puVar4;
        if (*puVar4 != 0) {
          if ((*(uint *)(param_1 + 0x30) & 0xffff) == 0x104) {
            puVar7 = (undefined4 *)0x0;
            do {
              puVar3 = puVar7;
              if (*(int *)(param_2 + (int)puVar7 * 4) == 0) break;
              puVar7 = (undefined4 *)((int)puVar7 + 1);
              puVar3 = local_18;
            } while (puVar7 < (undefined4 *)0x6);
            local_18 = puVar3;
            if (puVar7 == (undefined4 *)0x6) {
LAB_00606fc7:
              uVar15 = 0x6a5108000011a7;
LAB_00606fd1:
              FUN_005fbec8(param_1,0,uVar15);
              return -0x7fffbffb;
            }
          }
          else {
            local_18 = local_8;
          }
          pvVar8 = _malloc(0x38);
          if (pvVar8 == (void *)0x0) {
            iVar10 = 0;
          }
          else {
            iVar10 = FUN_005f7709();
          }
          if (iVar10 == 0) {
            return -0x7ff8fff2;
          }
          uVar11 = *puVar4;
          iVar9 = FUN_005f7760(uVar11 & 0xffffff | 0xe1000000,uVar11,uVar11,0);
          if (iVar9 < 0) goto LAB_0060721b;
          uVar11 = 0;
          if (*local_c != 0) {
            do {
              iVar9 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),local_18,uVar11,0);
              local_34[uVar11] = iVar9;
              if (iVar9 == -1) goto LAB_006071f1;
              *(int *)(*(int *)(iVar10 + 0x10) + uVar11 * 4) = iVar9;
              iVar9 = *(int *)(*(int *)(param_1 + 0x14) + iVar9 * 4);
              *(undefined4 *)(iVar9 + 0x20) = 0;
              *(undefined4 *)(iVar9 + 0x24) = 0xffffffff;
              *(uint *)(iVar9 + 0x50) = (int)local_8 << 8 | 3;
              uVar11 = uVar11 + 1;
            } while (uVar11 < *local_c);
          }
          uVar11 = *local_c;
          iVar9 = FUN_006066d1(param_4,param_5,3,local_8,uVar11,local_34);
          if ((iVar9 < 0) ||
             (iVar9 = FUN_006067f6(param_6,param_7,3,local_8,uVar11,local_34), iVar9 < 0))
          goto LAB_0060721b;
          uVar11 = 0;
          if (*local_c != 0) {
            do {
              iVar9 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x58),local_8,uVar11,0);
              aiStack_44[uVar11] = iVar9;
              if (iVar9 == -1) goto LAB_006071f1;
              iVar1 = *(int *)(*(int *)(param_1 + 0x14) + iVar9 * 4);
              *(undefined4 *)(iVar1 + 0x20) = 0;
              *(uint *)(iVar1 + 0x50) = (int)local_8 << 8 | 3;
              *(int *)(*(int *)(iVar10 + 8) + uVar11 * 4) = iVar9;
              uVar11 = uVar11 + 1;
            } while (uVar11 < *local_c);
          }
          piVar12 = (int *)(param_2 + (int)local_18 * 4);
          if (*piVar12 != 0) {
            FUN_005fbec8(param_1,0,0x11a4,
                         "cannot read from a texcoord which was used as input in a sampler",
                         *(uint *)(param_1 + 0x30) & 0xff);
            iVar9 = -0x7fffbffb;
            goto LAB_0060721b;
          }
          *piVar12 = iVar10;
        }
        local_8 = (undefined4 *)((int)local_8 + 1);
        puVar4 = local_c + 1;
        local_c = puVar4;
      } while (local_8 < *(undefined4 **)(param_1 + 0x7c));
    }
LAB_0060713e:
    local_14 = (uint *)((int)local_14 + 1);
    if ((uint *)0x2 < local_14) {
      local_8 = (undefined4 *)0x0;
      if (*(int *)(param_1 + 0x7c) != 0) {
        do {
          piVar12 = (int *)(param_2 + (int)local_8 * 4);
          if (*piVar12 == 0) {
            pvVar8 = _malloc(0x38);
            if (pvVar8 == (void *)0x0) {
              iVar10 = 0;
            }
            else {
              iVar10 = FUN_005f7709();
            }
            *piVar12 = iVar10;
            if (iVar10 == 0) {
              return -0x7ff8fff2;
            }
            FUN_005f7760(0,0,0,0);
          }
          local_8 = (undefined4 *)((int)local_8 + 1);
        } while (local_8 < *(uint *)(param_1 + 0x7c));
      }
      puVar7 = (undefined4 *)0x0;
      *param_3 = *(int *)(param_1 + 0x7c);
      if (param_5 != (undefined4 *)0x0) {
        do {
          piVar12 = (int *)(param_4 + (int)puVar7 * 4);
          piVar6 = (int *)*piVar12;
          if ((piVar6 != (int *)0x0) && (*piVar6 != 0)) {
            *(int **)(param_2 + *param_3 * 4) = piVar6;
            *param_3 = *param_3 + 1;
            *piVar12 = 0;
          }
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        } while (puVar7 < param_5);
      }
      return 0;
    }
  } while( true );
LAB_006071f1:
  iVar9 = -0x7ff8fff2;
LAB_0060721b:
  FUN_005f7186();
  return iVar9;
}


// ==== 0x60728d FUN_0060728d

int __fastcall FUN_0060728d(int param_1)

{
  uint uVar1;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  void *pvVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  uint *puVar12;
  undefined4 uVar13;
  char *pcVar14;
  int local_78 [6];
  int local_60 [6];
  uint local_48 [6];
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int *local_20;
  int *local_1c;
  int local_18;
  uint local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  uint local_8;
  
  local_c = (undefined4 *)0x0;
  local_10 = (undefined4 *)0x0;
  iVar9 = 6;
  piVar11 = local_60;
  for (iVar8 = iVar9; iVar8 != 0; iVar8 = iVar8 + -1) {
    *piVar11 = 0;
    piVar11 = piVar11 + 1;
  }
  piVar11 = local_78;
  for (iVar8 = iVar9; iVar8 != 0; iVar8 = iVar8 + -1) {
    *piVar11 = 0;
    piVar11 = piVar11 + 1;
  }
  puVar12 = local_48;
  for (iVar8 = iVar9; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  puVar6 = (undefined4 *)(param_1 + 0x1c8);
  for (iVar8 = iVar9; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar6 = 0xffffffff;
    puVar6 = puVar6 + 1;
  }
  puVar6 = (undefined4 *)(param_1 + 0x1e0);
  for (; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar6 = 0xffffffff;
    puVar6 = puVar6 + 1;
  }
  local_18 = 1;
  local_24 = 0;
  local_8 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    local_20 = *(int **)(param_1 + 0x18);
    do {
      puVar12 = (uint *)*local_20;
      uVar5 = *puVar12;
      uVar10 = uVar5 & 0xff000000;
      if ((((uVar10 == 0x40000000) || (uVar10 == 0x44000000)) || (uVar10 == 0x48000000)) ||
         (uVar10 == 0x4c000000)) {
LAB_00607427:
        if (uVar10 == 0x34000000) {
LAB_0060742f:
          iVar9 = *(int *)puVar12[2];
        }
        else {
          iVar9 = *(int *)(puVar12[2] + (uVar5 & 0xffffff) * 4);
        }
        piVar11 = *(int **)(*(int *)(param_1 + 0x14) + iVar9 * 4);
        if ((*piVar11 == *(int *)(param_1 + 0x58)) && (piVar11[8] == 0)) {
          if ((char)piVar11[0x14] != '\x03') {
            pcVar14 = "texture loads or clips cannot be from inputs not marked TEXCOORD";
            uVar13 = 0x11a1;
            iVar9 = piVar11[0x11];
            goto LAB_00607794;
          }
          if ((local_60[*(byte *)((int)piVar11 + 0x51)] != 0) &&
             ((*(uint *)(param_1 + 0x30) & 0xffff) != 0x104)) {
            local_18 = 0;
          }
          local_60[*(byte *)((int)piVar11 + 0x51)] = 1;
        }
        else {
          local_18 = 0;
        }
      }
      else {
        if (uVar10 == 0x34000000) goto LAB_0060742f;
        if ((uVar10 == 0xee000000) || (uVar10 == 0xef000000)) goto LAB_00607427;
        uVar10 = uVar5 & 0xffffff;
        local_2c = uVar10;
        if ((uVar10 != 0) && (uVar5 != 0)) {
          local_14 = 0;
          local_30 = puVar12[1];
          if (puVar12[1] != 0) {
            local_1c = (int *)puVar12[2];
            do {
              uVar5 = local_14;
              piVar11 = *(int **)(*(int *)(param_1 + 0x14) + *local_1c * 4);
              if ((*piVar11 == *(int *)(param_1 + 0x58)) &&
                 (bVar2 = *(byte *)((int)piVar11 + 0x51), (char)piVar11[0x14] == '\x03')) {
                if ((local_60[bVar2] != 0) &&
                   (((*(uint *)(param_1 + 0x30) & 0xffff) != 0x104 && (local_48[bVar2] == 0)))) {
                  local_18 = 0;
                }
                local_60[bVar2] = 1;
                uVar1 = uVar5 + uVar10;
                local_78[bVar2] = 1;
                uVar4 = local_2c;
                if (uVar5 < uVar1) {
                  local_28 = uVar1 - local_14;
                  uVar5 = local_48[bVar2];
                  piVar11 = local_1c;
                  do {
                    uVar10 = *(int *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar11 * 4) + 0xc) + 1;
                    if (uVar5 < uVar10) {
                      uVar5 = uVar10;
                    }
                    piVar11 = piVar11 + 1;
                    local_28 = local_28 - 1;
                  } while (local_28 != 0);
                  local_48[bVar2] = uVar5;
                  uVar10 = uVar4;
                }
              }
              local_14 = local_14 + uVar10;
              local_1c = local_1c + uVar10;
            } while (local_14 < local_30);
          }
          local_24 = local_24 + 1;
        }
      }
      local_8 = local_8 + 1;
      local_20 = local_20 + 1;
    } while (local_8 < *(uint *)(param_1 + 0xc));
    if (0x10 < local_24) {
      local_18 = 0;
    }
  }
  uVar5 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      iVar9 = uVar5 * 4;
      uVar5 = uVar5 + 1;
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + iVar9) + 0x28) = 0;
    } while (uVar5 < *(uint *)(param_1 + 8));
  }
  if (local_18 == 0) {
    pvVar7 = _malloc(0x800);
    *(void **)(param_1 + 0x140) = pvVar7;
    if (pvVar7 == (void *)0x0) {
      return -0x7ff8fff2;
    }
    pvVar7 = _malloc(0x800);
    *(void **)(param_1 + 0x144) = pvVar7;
    if (pvVar7 == (void *)0x0) {
      return -0x7ff8fff2;
    }
    local_c = _malloc(0x800);
    if (local_c == (undefined4 *)0x0) {
      return -0x7ff8fff2;
    }
    local_10 = _malloc(0x800);
    puVar6 = *(undefined4 **)(param_1 + 0x140);
    for (iVar9 = 0x200; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    puVar6 = *(undefined4 **)(param_1 + 0x144);
    for (iVar9 = 0x200; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    puVar6 = local_c;
    for (iVar9 = 0x200; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    puVar6 = local_10;
    for (iVar9 = 0x200; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    *(undefined4 *)(param_1 + 0x134) = 0;
    *(undefined4 *)(param_1 + 0x138) = 0;
    local_1c = (int *)0x0;
    local_8 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      do {
        if (0x1ff < local_8) {
          pcVar14 = "program too big";
          uVar13 = 0x11a2;
          iVar9 = 0;
LAB_00607794:
          FUN_005fbec8(param_1,iVar9,uVar13,pcVar14);
          return -0x7fffbffb;
        }
        puVar12 = *(uint **)(*(int *)(param_1 + 0x18) + local_8 * 4);
        uVar5 = *puVar12 & 0xff000000;
        if ((((uVar5 == 0x40000000) || (uVar5 == 0x44000000)) || (uVar5 == 0x48000000)) ||
           (((uVar5 == 0x4c000000 || (uVar5 == 0x34000000)) ||
            ((uVar5 == 0xef000000 || (uVar5 == 0xee000000)))))) {
          local_28 = *puVar12 & 0xffffff;
          if (uVar5 == 0x34000000) {
            local_28 = 0;
          }
          piVar11 = (int *)(puVar12[2] + local_28 * 4);
          piVar3 = *(int **)(*(int *)(param_1 + 0x14) + *piVar11 * 4);
          if ((*piVar3 == *(int *)(param_1 + 0x60)) || (piVar3[8] != 0)) {
            iVar9 = FUN_0060691c(piVar11,puVar12[1] - local_28,local_c,&local_1c);
            if (iVar9 < 0) goto LAB_0060772c;
          }
          else if (*piVar3 == *(int *)(param_1 + 0x58)) {
            if ((char)piVar3[0x14] == '\x03') {
              if ((local_78[*(byte *)((int)piVar3 + 0x51)] == 0) ||
                 ((*(uint *)(param_1 + 0x30) & 0xffff) == 0x104)) goto LAB_0060768d;
              pcVar14 = "can read from texcoord and use it for texlookup only in ps_1_4 and higher";
              uVar13 = 0x11a8;
            }
            else {
              pcVar14 = 
              "cannot perform dependent texture read which in any way is based on color inputs";
              uVar13 = 0x11a1;
            }
            FUN_005fbec8(param_1,0,uVar13,pcVar14);
            iVar9 = -0x7fffbffb;
            goto LAB_0060772c;
          }
        }
LAB_0060768d:
        local_8 = local_8 + 1;
      } while (local_8 < *(uint *)(param_1 + 0xc));
    }
    piVar11 = (int *)0x0;
    if (local_1c != (int *)0x0) {
      puVar6 = local_c;
      do {
        *(undefined4 *)(((int)local_10 - (int)local_c) + (int)puVar6) = *puVar6;
        *puVar6 = 0;
        piVar11 = (int *)((int)piVar11 + 1);
        puVar6 = puVar6 + 1;
      } while (piVar11 < local_1c);
    }
    iVar9 = FUN_00606ae1(*(undefined4 *)(param_1 + 0x144),param_1 + 0x138,
                         *(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0xc),0,0);
    if ((iVar9 < 0) ||
       (iVar9 = FUN_00606ae1(*(undefined4 *)(param_1 + 0x140),param_1 + 0x134,local_10,local_1c,
                             *(undefined4 *)(param_1 + 0x144),*(undefined4 *)(param_1 + 0x88)),
       iVar9 < 0)) goto LAB_0060772c;
  }
  else {
    *(undefined4 *)(param_1 + 0x140) = 0;
    puVar6 = _malloc(0x800);
    *(undefined4 **)(param_1 + 0x144) = puVar6;
    if (puVar6 == (undefined4 *)0x0) {
      return -0x7ff8fff2;
    }
    for (iVar9 = 0x200; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    iVar9 = FUN_00606ae1(*(undefined4 *)(param_1 + 0x144),param_1 + 0x138,
                         *(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0xc),0,0);
    if (iVar9 < 0) {
      return iVar9;
    }
  }
  iVar9 = 0;
  uVar5 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      puVar6 = *(undefined4 **)(*(int *)(param_1 + 0x14) + uVar5 * 4);
      if (puVar6[10] == 1) {
        *puVar6 = *(undefined4 *)(param_1 + 0x4c);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 8));
  }
LAB_0060772c:
  uVar5 = 0;
  if (local_c != (undefined4 *)0x0) {
    if (iVar9 < 0) {
      do {
        if (local_c[uVar5] != 0) {
          FUN_005f7186(1);
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < 0x200);
    }
    _free(local_c);
  }
  if (local_10 != (undefined4 *)0x0) {
    if (iVar9 < 0) {
      uVar5 = 0;
      do {
        if (local_10[uVar5] != 0) {
          FUN_005f7186(1);
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < 0x200);
    }
    _free(local_10);
    return iVar9;
  }
  return iVar9;
}


// ==== 0x6077c3 FUN_006077c3

uint __thiscall
FUN_006077c3(int param_1,int param_2,uint param_3,uint param_4,int param_5,int param_6,
            undefined4 *param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint local_8;
  
  local_8 = 0;
  *param_7 = 0;
  for (; param_3 < param_4; param_3 = param_3 + 1) {
    iVar1 = *(int *)(param_2 + param_3 * 4);
    uVar4 = 0;
    if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
      do {
        iVar2 = *(int *)(*(int *)(iVar1 + 8) + uVar4 * 4);
        iVar3 = *(int *)(*(int *)(param_1 + 0x14) + iVar2 * 4);
        if ((iVar2 == param_5) || (*(int *)(iVar3 + 0x24) == param_5)) {
          *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(param_6 + 8);
          *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(param_6 + 0xc);
          *param_7 = 1;
          local_8 = param_3;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(iVar1 + 4));
    }
  }
  return local_8;
}


// ==== 0x60783e FUN_0060783e

undefined4 __thiscall
FUN_0060783e(int param_1,int param_2,uint param_3,uint param_4,int param_5,uint param_6,int param_7,
            uint *param_8)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  uint local_10;
  uint local_c;
  int local_8;
  
  for (uVar6 = param_3; uVar6 < param_4; uVar6 = uVar6 + 1) {
    puVar1 = *(uint **)(param_2 + uVar6 * 4);
    if ((puVar1 != (uint *)0x0) && (uVar8 = *puVar1 & 0xffffff, *puVar1 != 0)) {
      uVar2 = puVar1[1];
      local_10 = 0;
      if (uVar2 / uVar8 != 0) {
        param_3 = 0;
        do {
          bVar4 = false;
          if (uVar8 != 0) {
            piVar7 = (int *)(puVar1[2] + param_3);
            local_c = uVar8;
            do {
              iVar9 = *(int *)(*(int *)(param_1 + 0x14) + *piVar7 * 4);
              uVar5 = 0;
              if (param_6 != 0) {
                do {
                  iVar3 = *(int *)(param_5 + uVar5 * 4);
                  if (((*piVar7 == iVar3) || (*(int *)(iVar9 + 0x24) == iVar3)) &&
                     (*(int *)(iVar9 + 8) == -1)) {
                    bVar4 = true;
                  }
                  uVar5 = uVar5 + 1;
                } while (uVar5 < param_6);
              }
              piVar7 = piVar7 + 1;
              local_c = local_c - 1;
            } while (local_c != 0);
            if (bVar4) {
              local_c = 0;
              local_8 = param_3;
              do {
                iVar9 = *(int *)(*(int *)(*(int *)(param_1 + 0x14) +
                                         *(int *)(local_8 + puVar1[2]) * 4) + 0x24);
                if (iVar9 == -1) {
                  iVar9 = *(int *)(local_8 + puVar1[2]);
                }
                uVar5 = *param_8;
                uVar10 = 0;
                if (uVar5 != 0) {
                  do {
                    if (*(int *)(param_7 + uVar10 * 4) == iVar9) break;
                    uVar10 = uVar10 + 1;
                  } while (uVar10 < *param_8);
                }
                if (uVar10 == uVar5) {
                  if (uVar10 == 0x20) {
                    uVar11 = 0x12c3;
                    goto LAB_00607a0f;
                  }
                  *(int *)(param_7 + uVar5 * 4) = iVar9;
                  *param_8 = *param_8 + 1;
                }
                local_c = local_c + 1;
                local_8 = local_8 + 4;
              } while (local_c < uVar8);
            }
          }
          local_10 = local_10 + 1;
          param_3 = param_3 + uVar8 * 4;
        } while (local_10 < uVar2 / uVar8);
      }
    }
  }
  param_4 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      iVar9 = *(int *)(*(int *)(param_1 + 0x14) + param_4 * 4);
      param_3 = 0;
      if (param_6 != 0) {
        do {
          iVar3 = *(int *)(param_5 + param_3 * 4);
          if (*(int *)(iVar9 + 0x24) == iVar3) {
            uVar6 = *param_8;
            uVar8 = 0;
            if (uVar6 != 0) {
              do {
                if (*(int *)(param_7 + uVar8 * 4) == iVar3) break;
                uVar8 = uVar8 + 1;
              } while (uVar8 < *param_8);
            }
            if (uVar8 == uVar6) {
              if (uVar8 == 0x20) {
                uVar11 = 0x12c5;
LAB_00607a0f:
                FUN_005fbec8(param_1,0,uVar11,"internal error: arguments not vectorized");
                return 0x80004005;
              }
              *(int *)(param_7 + uVar6 * 4) = iVar3;
              *param_8 = *param_8 + 1;
            }
          }
          param_3 = param_3 + 1;
        } while (param_3 < param_6);
      }
      param_4 = param_4 + 1;
    } while (param_4 < *(uint *)(param_1 + 8));
  }
  return 0;
}


// ==== 0x607a1e FUN_00607a1e

undefined4 __fastcall FUN_00607a1e(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x14) + uVar3 * 4);
      if (*(int *)(iVar1 + 0x24) != -1) {
        iVar2 = *(int *)(iVar1 + 0x24) * 4;
        *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(*(int *)(iVar2 + *(int *)(param_1 + 0x14)) + 8)
        ;
        *(undefined4 *)(iVar1 + 0xc) =
             *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + iVar2) + 0xc);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 8));
  }
  return 0;
}


// ==== 0x607a58 FUN_00607a58

undefined4 __thiscall
FUN_00607a58(int param_1,int param_2,uint param_3,uint param_4,int *param_5,int param_6,
            uint *param_7,undefined4 *param_8,undefined4 *param_9)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int local_28;
  uint local_24;
  uint local_20;
  uint local_18;
  uint local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  *param_8 = 0;
  *param_9 = 0;
  local_14 = 0;
  for (uVar4 = param_3; uVar4 < param_4; uVar4 = uVar4 + 1) {
    puVar1 = *(uint **)(param_2 + uVar4 * 4);
    if (puVar1 != (uint *)0x0) {
      uVar2 = puVar1[1];
      uVar5 = *puVar1 & 0xffffff;
      local_18 = 0;
      if (param_6 != 0) {
        local_10 = param_5;
        local_28 = param_6;
        do {
          if (uVar2 / uVar5 != 0) {
            local_c = 0;
            local_24 = uVar2 / uVar5;
            do {
              param_3 = 0;
              if (uVar5 != 0) {
                local_8 = local_c;
                local_20 = uVar5;
                do {
                  if ((*(int *)(*(int *)(*(int *)(param_1 + 0x14) +
                                        *(int *)(local_8 + puVar1[2]) * 4) + 0x24) == *local_10) ||
                     (*(int *)(local_8 + puVar1[2]) == *local_10)) {
                    param_3 = param_3 + 1;
                    local_18 = local_18 + 1;
                    if (local_14 < local_18) {
                      local_14 = local_18;
                    }
                    if ((puVar1[3] == 1) &&
                       (*(int *)(*(int *)(*(int *)(param_1 + 0x14) + *(int *)puVar1[4] * 4) + 0xc)
                        == 3)) {
                      *param_8 = 1;
                    }
                    if (((*puVar1 & 0xff000000) != 0x30000000) && (uVar3 = 0, puVar1[3] != 0)) {
                      do {
                        if (*(int *)(*(int *)(*(int *)(param_1 + 0x14) +
                                             *(int *)(puVar1[4] + uVar3 * 4) * 4) + 0xc) == 3) {
                          *param_8 = 1;
                        }
                        uVar3 = uVar3 + 1;
                      } while (uVar3 < puVar1[3]);
                    }
                  }
                  local_8 = local_8 + 4;
                  local_20 = local_20 - 1;
                } while (local_20 != 0);
              }
              if ((param_3 != uVar5) && (param_3 != 0)) {
                *param_9 = 1;
              }
              local_c = local_c + uVar5 * 4;
              local_24 = local_24 - 1;
            } while (local_24 != 0);
          }
          local_10 = local_10 + 1;
          local_28 = local_28 + -1;
        } while (local_28 != 0);
      }
    }
  }
  *param_7 = local_14;
  return 0;
}


// ==== 0x607bc1 FUN_00607bc1

undefined4 __fastcall FUN_00607bc1(int param_1)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  uint *puVar9;
  float *pfVar10;
  int *piVar11;
  char *pcVar12;
  float local_170 [32];
  int local_f0 [32];
  int local_70 [8];
  float local_50 [4];
  int local_40 [5];
  undefined4 local_2c;
  uint local_28;
  uint *local_24;
  int *local_20;
  uint local_1c;
  int *local_18;
  int local_14;
  uint local_10;
  uint local_c;
  int *local_8;
  
  piVar7 = *(int **)(param_1 + 8);
  pfVar10 = local_170;
  for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar10 = 0.0;
    pfVar10 = pfVar10 + 1;
  }
  piVar11 = local_f0;
  for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar11 = 0;
    piVar11 = piVar11 + 1;
  }
  piVar11 = local_70;
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar11 = 0;
    piVar11 = piVar11 + 1;
  }
  local_20 = piVar7;
  local_2c = FUN_005f7478(&DAT_0069ecd8,0x189,0x400000008);
  local_18 = (int *)0x0;
  if (piVar7 != (int *)0x0) {
    iVar4 = *(int *)(param_1 + 0x10);
    piVar7 = *(int **)(param_1 + 0x14);
    do {
      uVar8 = *(uint *)(*(int *)(iVar4 + *(int *)*piVar7 * 4) + 4);
      if (((uVar8 & 0x100) != 0) && ((uVar8 & 0xc0) == 0)) {
        uVar8 = ((int *)*piVar7)[2];
        if (*(uint *)(param_1 + 0x78) < uVar8) {
          pcVar12 = "exceeded maximum constant registers";
LAB_00608068:
          FUN_005fbec8(param_1,0,0x119b,pcVar12);
          return 0x80004005;
        }
        local_f0[uVar8 * 4] = 1;
        local_f0[uVar8 * 4 + 1] = 1;
        local_f0[uVar8 * 4 + 2] = 1;
        local_f0[uVar8 * 4 + 3] = 1;
        local_70[uVar8] = 1;
      }
      local_18 = (int *)((int)local_18 + 1);
      piVar7 = piVar7 + 1;
    } while (local_18 < local_20);
  }
  uVar8 = *(uint *)(param_1 + 0x138);
  uVar6 = *(uint *)(param_1 + 0x134);
  local_c = 0;
  if (uVar6 + uVar8 != 0) {
    do {
      if (local_c < uVar6) {
        local_24 = *(uint **)(*(int *)(param_1 + 0x140) + local_c * 4);
      }
      else {
        local_24 = *(uint **)(*(int *)(param_1 + 0x144) + (local_c - uVar6) * 4);
      }
      local_14 = 0;
      if ((((local_24 != (uint *)0x0) && (local_24[3] != 0)) && (*(int *)local_24[4] != -1)) &&
         ((*local_24 & 0xff000000) != 0)) {
        if (((*(int *)(*(int *)(*(int *)(param_1 + 0x14) + *(int *)local_24[4] * 4) + 0xc) != 3) &&
            (local_24[3] != 4)) && (uVar6 <= local_c)) {
          iVar4 = 1;
          if ((local_c - uVar6) + 1 < uVar8) {
            uVar5 = (local_c - uVar6) + 1;
            uVar8 = (local_c - uVar6) + 1;
            do {
              iVar1 = *(int *)(*(int *)(param_1 + 0x144) + uVar8 * 4);
              if ((iVar1 != 0) && (*(char *)(iVar1 + 3) != '\0')) break;
              iVar4 = iVar4 + 1;
              uVar5 = uVar5 + 1;
              uVar8 = uVar5;
            } while (uVar5 < *(uint *)(param_1 + 0x138));
          }
          uVar8 = (iVar4 - uVar6) + local_c;
          if (uVar8 < *(uint *)(param_1 + 0x138)) {
            local_14 = *(int *)(*(int *)(param_1 + 0x144) + uVar8 * 4);
            if ((*(int *)(local_14 + 0xc) != 1) ||
               (*(int *)(*(int *)(*(int *)(param_1 + 0x14) + **(int **)(local_14 + 0x10) * 4) + 0xc)
                != 3)) {
              local_14 = 0;
            }
          }
        }
        local_1c = *local_24 & 0xffffff;
        local_40[4] = local_24[1] / local_1c;
        local_28 = 0;
        if (local_40[4] != 0) {
          local_18 = (int *)0x0;
          puVar9 = local_24;
          do {
            puVar2 = local_24;
            local_40[0] = 0;
            local_40[1] = 0;
            local_40[2] = 0;
            local_40[3] = 0;
            puVar9 = (uint *)((int)local_18 + puVar9[2]);
            iVar4 = *(int *)(param_1 + 0x14);
            if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) +
                                    **(int **)(iVar4 + (int)*puVar9 * 4) * 4) + 4) & 0x80) != 0) &&
               ((int *)*puVar9 < local_20)) {
              local_10 = 0;
              if (local_1c != 0) {
                local_8 = (int *)(*local_24 & 0xff000000);
                do {
                  uVar8 = local_10;
                  if (local_8 != (int *)0x30000000) {
                    uVar8 = *(uint *)(*(int *)(iVar4 + *(int *)(puVar2[4] + local_10 * 4) * 4) + 0xc
                                     );
                  }
                  local_50[uVar8] = (float)*(double *)(*(int *)(iVar4 + *puVar9 * 4) + 0x10);
                  local_40[uVar8] = 1;
                  local_10 = local_10 + 1;
                  puVar9 = puVar9 + 1;
                } while (local_10 < local_1c);
              }
              if ((local_14 != 0) && (local_10 = *(int *)(local_14 + 4), local_10 != 0)) {
                local_8 = *(int **)(local_14 + 8);
                do {
                  piVar7 = *(int **)(iVar4 + *local_8 * 4);
                  if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar7 * 4) + 4) & 0x80) != 0
                      ) && ((int *)*local_8 < local_20)) {
                    local_40[3] = 1;
                    local_50[3] = (float)*(double *)(piVar7 + 4);
                  }
                  local_8 = local_8 + 1;
                  local_10 = local_10 + -1;
                } while (local_10 != 0);
              }
              local_10 = 0;
              uVar8 = 0;
              do {
                uVar6 = 0;
                if (local_70[local_10] == 0) {
                  local_8 = (int *)0x1;
                  do {
                    if (((*(int *)((int)local_40 + uVar6) != 0) &&
                        (*(float *)((int)local_50 + uVar6) !=
                         *(float *)((int)local_170 + uVar8 + uVar6))) &&
                       (*(int *)((int)local_f0 + uVar8 + uVar6) != 0)) {
                      local_8 = (int *)0x0;
                    }
                    uVar6 = uVar6 + 4;
                  } while (uVar6 < 0x10);
                  if (local_8 != (int *)0x0) break;
                }
                uVar8 = uVar8 + 0x10;
                local_10 = local_10 + 1;
              } while (uVar8 < 0x80);
              uVar8 = local_10;
              if (local_10 == 8) {
                pcVar12 = "program too complex: exceeded available constant registers.";
                goto LAB_00608068;
              }
              local_8 = (int *)0x0;
              uVar6 = 0;
              do {
                if (local_40[uVar6] != 0) {
                  pfVar10 = local_50 + uVar6;
                  iVar4 = uVar6 + uVar8 * 4;
                  local_170[iVar4] = *pfVar10;
                  local_f0[iVar4] = 1;
                  if ((1.0 < *pfVar10) || (*pfVar10 < -1.0)) {
                    local_8 = (int *)0x1;
                  }
                }
                uVar6 = uVar6 + 1;
              } while (uVar6 < 4);
              if (local_8 != (int *)0x0) {
                FUN_005fbf37(param_1,puVar2[0xd]);
              }
              uVar8 = 0;
              piVar7 = local_18;
              if (local_1c != 0) {
                do {
                  uVar6 = uVar8;
                  if ((*puVar2 & 0xff000000) != 0x30000000) {
                    uVar6 = *(uint *)(*(int *)(*(int *)(param_1 + 0x14) +
                                              *(int *)(puVar2[4] + uVar8 * 4) * 4) + 0xc);
                  }
                  local_8 = piVar7;
                  uVar3 = FUN_005f74cf(local_2c,local_10,uVar6,
                                       *(undefined8 *)
                                        (*(int *)(*(int *)(param_1 + 0x14) +
                                                 *(int *)((int)piVar7 + puVar2[2]) * 4) + 0x10));
                  *(undefined4 *)((int)local_8 + puVar2[2]) = uVar3;
                  uVar8 = uVar8 + 1;
                  local_8 = local_8 + 1;
                  piVar7 = local_8;
                } while (uVar8 < local_1c);
              }
              if ((local_14 != 0) && (local_8 = (int *)0x0, *(int *)(local_14 + 4) != 0)) {
                do {
                  piVar7 = *(int **)(*(int *)(local_14 + 8) + (int)local_8 * 4);
                  piVar11 = *(int **)(*(int *)(param_1 + 0x14) + (int)piVar7 * 4);
                  if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar11 * 4) + 4) & 0x80) !=
                       0) && (piVar7 < local_20)) {
                    uVar3 = FUN_005f74cf(local_2c,local_10,3,*(undefined8 *)(piVar11 + 4));
                    *(undefined4 *)(*(int *)(local_14 + 8) + (int)local_8 * 4) = uVar3;
                  }
                  local_8 = (int *)((int)local_8 + 1);
                } while (local_8 < *(int **)(local_14 + 4));
              }
            }
            local_28 = local_28 + 1;
            local_18 = local_18 + local_1c;
            puVar9 = puVar2;
          } while (local_28 < (uint)local_40[4]);
        }
      }
      uVar8 = *(uint *)(param_1 + 0x138);
      uVar6 = *(uint *)(param_1 + 0x134);
      local_c = local_c + 1;
    } while (local_c < uVar6 + uVar8);
  }
  piVar7 = (int *)0x0;
  if (local_20 != (int *)0x0) {
    do {
      piVar11 = *(int **)(*(int *)(param_1 + 0x14) + (int)piVar7 * 4);
      if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar11 * 4) + 4) & 0x80) != 0) {
        *piVar11 = *(int *)(param_1 + 0x4c);
      }
      piVar7 = (int *)((int)piVar7 + 1);
    } while (piVar7 < local_20);
  }
  return 0;
}


// ==== 0x60807f FUN_0060807f

undefined4 __thiscall
FUN_0060807f(int param_1,uint param_2,int param_3,uint param_4,int param_5,uint param_6)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  uint local_c;
  uint local_8;
  
  uVar4 = param_2;
  uVar7 = 0;
  if (param_4 != 0) {
    do {
      puVar1 = *(uint **)(param_3 + uVar7 * 4);
      if ((puVar1 != (uint *)0x0) && (local_8 = *puVar1, local_8 != 0)) {
        uVar5 = local_8 & 0xff000000;
        local_8 = local_8 & 0xffffff;
        if ((uVar5 == 0x40000000) ||
           (((uVar5 == 0x44000000 || (uVar5 == 0x48000000)) || (uVar5 == 0x4c000000)))) {
          if (uVar5 == 0xe1000000) goto LAB_00608149;
        }
        else {
          if (uVar5 != 0xe1000000) {
            local_8 = 0;
            if (param_6 != 0) {
              uVar5 = puVar1[1];
              do {
                param_2 = 0;
                if (uVar5 != 0) {
                  piVar6 = (int *)puVar1[2];
                  do {
                    if (((*piVar6 == *(int *)(param_5 + local_8 * 4)) &&
                        (piVar2 = *(int **)(param_3 + uVar4 * 4), piVar2 != (int *)0x0)) &&
                       ((uVar4 < uVar7 && (*piVar2 != 0)))) {
                      return 1;
                    }
                    param_2 = param_2 + 1;
                    uVar5 = puVar1[1];
                    piVar6 = piVar6 + 1;
                  } while (param_2 < uVar5);
                }
                local_8 = local_8 + 1;
              } while (local_8 < param_6);
            }
            goto LAB_006081c0;
          }
LAB_00608149:
          local_8 = 0;
        }
        local_c = 0;
        if (param_6 != 0) {
          uVar5 = puVar1[1];
          do {
            param_2 = local_8;
            if (local_8 < uVar5) {
              piVar6 = (int *)(puVar1[2] + local_8 * 4);
              do {
                if (((*piVar6 == *(int *)(param_5 + local_c * 4)) &&
                    (piVar2 = *(int **)(param_3 + uVar4 * 4), piVar2 != (int *)0x0)) &&
                   ((uVar4 < uVar7 && (*piVar2 != 0)))) {
                  return 1;
                }
                iVar3 = *(int *)(*(int *)(param_1 + 0x14) + *piVar6 * 4);
                if (((*(byte *)(iVar3 + 0x22) & 0xf) != 0) || (*(int *)(iVar3 + 0x24) != -1)) {
                  FUN_005fbec8(param_1,0,0x12c6,"internal error: texld alias found");
                  return 0x80004005;
                }
                param_2 = param_2 + 1;
                uVar5 = puVar1[1];
                piVar6 = piVar6 + 1;
              } while (param_2 < uVar5);
            }
            local_c = local_c + 1;
          } while (local_c < param_6);
        }
      }
LAB_006081c0:
      uVar7 = uVar7 + 1;
    } while (uVar7 < param_4);
  }
  return 0;
}


// ==== 0x6081f6 FUN_006081f6

undefined4 __thiscall FUN_006081f6(int param_1,int param_2,int param_3,int param_4)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int local_58 [18];
  int local_10;
  int *local_c;
  int *local_8;
  
  piVar6 = local_58;
  for (iVar4 = 0x12; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar6 = 0x1010101;
    piVar6 = piVar6 + 1;
  }
  if (*(int *)(param_1 + 0x88) != 0) {
    local_c = local_58;
    local_8 = *(int **)(param_1 + 0x144);
    local_10 = *(int *)(param_1 + 0x88);
    do {
      puVar1 = (uint *)*local_8;
      if ((puVar1 != (uint *)0x0) && (uVar5 = *puVar1, uVar5 != 0)) {
        if ((uVar5 & 0xff000000) == 0xe1000000) {
          uVar5 = 0;
        }
        else {
          uVar5 = uVar5 & 0xffffff;
        }
        if (uVar5 < puVar1[1]) {
          iVar4 = *(int *)(param_1 + 0x14);
          piVar6 = (int *)(puVar1[2] + uVar5 * 4);
          iVar3 = puVar1[1] - uVar5;
          do {
            piVar2 = *(int **)(iVar4 + *piVar6 * 4);
            if ((*piVar2 == *(int *)(param_1 + 0x60)) && ((uint)piVar2[3] < 3)) {
              local_58[piVar2[2] + piVar2[3] + piVar2[2] * 2] = 0;
            }
            piVar6 = piVar6 + 1;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        piVar2 = local_c;
        piVar6 = local_c + 1;
        *local_c = 0;
        *piVar6 = 0;
        piVar2[2] = 0;
      }
      local_8 = local_8 + 1;
      local_c = local_c + 3;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
  }
  iVar4 = 0;
  uVar5 = 0;
  do {
    if (local_58[uVar5] != 0) {
      if (*(int *)(param_3 + (uVar5 / 3) * 4) == 0) {
        iVar3 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),uVar5 / 3,uVar5 % 3,0);
        *(int *)(param_2 + iVar4 * 4) = iVar3;
        if (iVar3 == -1) {
          return 0x8007000e;
        }
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + iVar3 * 4) + 0x20) = 0;
        iVar4 = iVar4 + 1;
        if (iVar4 == param_4) {
          return 0;
        }
      }
    }
    uVar5 = uVar5 + 1;
    if (0x11 < uVar5) {
      FUN_005fbec8(param_1,0,0x11a9,"program too complex: out of temporary registers");
      return 0x80004005;
    }
  } while( true );
}


// ==== 0x608320 FUN_00608320

int __thiscall FUN_00608320(int param_1,int param_2,uint param_3,int param_4)

{
  uint *puVar1;
  bool bVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  uint uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  int local_24;
  uint local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  
  puVar11 = (uint *)0x0;
  local_14 = 0;
  if (param_3 == 0) {
LAB_006083b1:
    FUN_005fbec8(param_1,0,0x12d7,"internal error: uppropagation failed");
    return -0x7fffbffb;
  }
  do {
    puVar1 = *(uint **)(param_2 + local_14 * 4);
    if ((((puVar1 != (uint *)0x0) && ((*puVar1 & 0xff000000) != 0)) && ((*puVar1 & 0xffffff) != 0))
       && (uVar12 = puVar1[3], uVar12 != 0)) {
      piVar7 = (int *)puVar1[4];
      piVar6 = *(int **)(*(int *)(param_1 + 0x14) + *piVar7 * 4);
      if ((piVar6[2] == param_4) && (*piVar6 == *(int *)(param_1 + 0x60))) {
        local_18 = local_14;
        uVar3 = 0;
        puVar11 = puVar1;
        if (uVar12 != 0) {
          do {
            if (*(int *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar7 * 4) + 0xc) == 2) {
              return 0;
            }
            uVar3 = uVar3 + 1;
            piVar7 = piVar7 + 1;
          } while (uVar3 < uVar12);
        }
      }
    }
    local_14 = local_14 + 1;
  } while (local_14 < param_3);
  if (puVar11 == (uint *)0x0) goto LAB_006083b1;
  uVar12 = *puVar11 & 0xffffff;
  if ((*puVar11 & 0xff000000) == 0x30000000) {
    pvVar4 = _malloc(0x38);
    if (pvVar4 == (void *)0x0) {
      param_3 = 0;
    }
    else {
      param_3 = FUN_005f7709();
    }
    if (param_3 == 0) {
      return -0x7ff8fff2;
    }
    iVar5 = FUN_005f7760(*puVar11,puVar11[1],puVar11[3] + 1,0);
    if (iVar5 < 0) goto LAB_006086e9;
    piVar7 = (int *)(param_2 + local_18 * 4);
    iVar5 = FUN_005f7a42();
    if (iVar5 < 0) goto LAB_006086e9;
    iVar5 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),param_4,2,0);
    if (iVar5 == -1) {
LAB_00608479:
      iVar5 = -0x7ff8fff2;
      goto LAB_006086e9;
    }
    puVar13 = (undefined4 *)puVar11[2];
    puVar14 = *(undefined4 **)(param_3 + 8);
    for (uVar12 = *(uint *)(param_3 + 4) & 0x3fffffff; uVar12 != 0; uVar12 = uVar12 - 1) {
      *puVar14 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar14 = puVar14 + 1;
    }
    for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(undefined1 *)puVar14 = *(undefined1 *)puVar13;
      puVar13 = (undefined4 *)((int)puVar13 + 1);
      puVar14 = (undefined4 *)((int)puVar14 + 1);
    }
    puVar13 = (undefined4 *)puVar11[4];
    puVar14 = *(undefined4 **)(param_3 + 0x10);
    for (uVar12 = puVar11[3] & 0x3fffffff; uVar12 != 0; uVar12 = uVar12 - 1) {
      *puVar14 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar14 = puVar14 + 1;
    }
    for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(undefined1 *)puVar14 = *(undefined1 *)puVar13;
      puVar13 = (undefined4 *)((int)puVar13 + 1);
      puVar14 = (undefined4 *)((int)puVar14 + 1);
    }
    *(int *)(*(int *)(param_3 + 0x10) + puVar11[3] * 4) = iVar5;
    if (*piVar7 != 0) {
      FUN_005f7186();
    }
    *piVar7 = param_3;
  }
  else {
    pvVar4 = _malloc(0x38);
    if (pvVar4 == (void *)0x0) {
      param_3 = 0;
    }
    else {
      param_3 = FUN_005f7709();
    }
    if (param_3 == 0) {
      return -0x7ff8fff2;
    }
    uVar3 = puVar11[1] / uVar12;
    iVar5 = FUN_005f7760((uVar12 + 1 ^ *puVar11) & 0xffffff ^ *puVar11,puVar11[1] + uVar3,
                         puVar11[3] + 1,0);
    if (iVar5 < 0) goto LAB_006086e9;
    piVar7 = (int *)(param_2 + local_18 * 4);
    iVar5 = FUN_005f7a42();
    if (iVar5 < 0) goto LAB_006086e9;
    local_1c = 0;
    if (uVar3 != 0) {
      local_14 = uVar12 * 4;
      local_10 = 0;
      local_c = 0;
      iVar8 = local_14 + 4;
      do {
        bVar2 = true;
        if (1 < uVar12) {
          piVar6 = (int *)(puVar11[2] + local_c);
          iVar5 = *piVar6;
          local_24 = uVar12 - 1;
          do {
            piVar6 = piVar6 + 1;
            if (*(int *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar6 * 4) + 0xc) !=
                *(int *)(*(int *)(*(int *)(param_1 + 0x14) + iVar5 * 4) + 0xc)) {
              bVar2 = false;
            }
            local_24 = local_24 + -1;
          } while (local_24 != 0);
        }
        puVar13 = (undefined4 *)(puVar11[2] + local_c);
        puVar14 = (undefined4 *)(*(int *)(param_3 + 8) + local_10);
        for (uVar9 = uVar12; uVar9 != 0; uVar9 = uVar9 - 1) {
          *puVar14 = *puVar13;
          puVar13 = puVar13 + 1;
          puVar14 = puVar14 + 1;
        }
        for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
          *(undefined1 *)puVar14 = *(undefined1 *)puVar13;
          puVar13 = (undefined4 *)((int)puVar13 + 1);
          puVar14 = (undefined4 *)((int)puVar14 + 1);
        }
        if (bVar2) {
          *(undefined4 *)(local_14 + *(int *)(param_3 + 8)) = *(undefined4 *)(local_c + puVar11[2]);
        }
        else {
          piVar6 = *(int **)(*(int *)(param_1 + 0x14) +
                            *(int *)(local_10 + *(int *)(param_3 + 8)) * 4);
          iVar5 = piVar6[2];
          iVar10 = FUN_005f74cf(*piVar6,iVar5,2,0);
          if (iVar10 == -1) goto LAB_00608479;
          *(int *)(local_14 + *(int *)(param_3 + 8)) = iVar10;
          if ((*piVar6 == *(int *)(param_1 + 0x60)) &&
             (iVar5 = FUN_00608320(param_2,local_18,iVar5), iVar5 < 0)) goto LAB_006086e9;
        }
        iVar5 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),param_4,2,0);
        if (iVar5 == -1) goto LAB_00608479;
        puVar13 = (undefined4 *)puVar11[4];
        puVar14 = *(undefined4 **)(param_3 + 0x10);
        for (uVar9 = puVar11[3] & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
          *puVar14 = *puVar13;
          puVar13 = puVar13 + 1;
          puVar14 = puVar14 + 1;
        }
        local_1c = local_1c + 1;
        for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
          *(undefined1 *)puVar14 = *(undefined1 *)puVar13;
          puVar13 = (undefined4 *)((int)puVar13 + 1);
          puVar14 = (undefined4 *)((int)puVar14 + 1);
        }
        *(int *)(*(int *)(param_3 + 0x10) + puVar11[3] * 4) = iVar5;
        local_c = local_c + uVar12 * 4;
        local_10 = local_10 + iVar8;
        local_14 = local_14 + iVar8;
      } while (local_1c < uVar3);
    }
    if (*piVar7 != 0) {
      FUN_005f7186();
    }
    *piVar7 = param_3;
  }
  param_3 = 0;
  iVar5 = 0;
LAB_006086e9:
  if (param_3 != 0) {
    FUN_005f7186();
    return iVar5;
  }
  return iVar5;
}


// ==== 0x608700 FUN_00608700

int __fastcall FUN_00608700(int param_1)

{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = 0;
  if (*(int *)(param_1 + 0x88) != 0) {
    do {
      puVar1 = *(uint **)(*(int *)(param_1 + 0x144) + uVar6 * 4);
      uVar2 = *puVar1;
      uVar5 = uVar2 & 0xff000000;
      if ((((uVar5 == 0x44000000) || (uVar5 == 0x40000000)) &&
          (piVar3 = *(int **)(*(int *)(param_1 + 0x14) +
                             *(int *)(puVar1[2] + (uVar2 & 0xffffff) * 4) * 4),
          *piVar3 == *(int *)(param_1 + 0x60))) &&
         (iVar4 = FUN_00608320(*(undefined4 *)(param_1 + 0x140),*(undefined4 *)(param_1 + 0x134),
                               piVar3[2]), iVar4 < 0)) {
        return iVar4;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_1 + 0x88));
  }
  return 0;
}


// ==== 0x608771 FUN_00608771

int * __fastcall FUN_00608771(int param_1)

{
  int *piVar1;
  uint *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  int *piVar10;
  undefined4 *puVar11;
  uint *puVar12;
  uint uVar13;
  int *piVar14;
  uint *puVar15;
  undefined4 *puVar16;
  bool bVar17;
  undefined8 uVar18;
  undefined4 auStack_1f4 [24];
  int local_194 [32];
  undefined4 local_114 [24];
  undefined4 local_b4 [6];
  int local_9c [6];
  uint local_84 [6];
  uint local_6c [6];
  int *local_54;
  uint local_50;
  uint *local_4c;
  int *local_48;
  uint *local_44;
  uint *local_40;
  int *local_3c;
  uint *local_38;
  int *local_34;
  int local_30;
  int *local_2c;
  int *local_28;
  uint *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  uint *local_14;
  int *local_10;
  uint *local_c;
  int *local_8;
  
  iVar7 = 6;
  puVar12 = local_84;
  for (iVar6 = iVar7; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  puVar11 = local_114;
  for (iVar6 = 0x18; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar11 = 0;
    puVar11 = puVar11 + 1;
  }
  puVar12 = local_6c;
  for (iVar6 = iVar7; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  piVar10 = local_9c;
  for (iVar6 = iVar7; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar10 = 0;
    piVar10 = piVar10 + 1;
  }
  puVar11 = local_b4;
  for (; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar11 = 0;
    puVar11 = puVar11 + 1;
  }
  uVar8 = 0;
  local_30 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      piVar10 = *(int **)(*(int *)(param_1 + 0x14) + uVar8 * 4);
      if (*piVar10 == *(int *)(param_1 + 0x60)) {
        piVar10[2] = -1;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(param_1 + 8));
  }
  local_14 = (uint *)0x0;
  if (*(int *)(param_1 + 0x88) != 0) {
    do {
      local_30 = 0;
      if (*(int *)(param_1 + 0x140) == 0) goto LAB_00608fb0;
      puVar12 = *(uint **)(*(int *)(param_1 + 0x144) + (int)local_14 * 4);
      if ((((puVar12 != (uint *)0x0) && (uVar8 = *puVar12, uVar8 != 0)) &&
          ((uVar8 & 0xff000000) != 0xe1000000)) && ((uVar8 & 0xff000000) != 0x34000000)) {
        piVar14 = (int *)(uVar8 & 0xffffff);
        piVar10 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)(puVar12[2] + (int)piVar14 * 4) * 4);
        local_20 = piVar14;
        if (((*(byte *)((int)piVar10 + 0x22) & 0xf) != 0) && (*piVar10 == *(int *)(param_1 + 0x60)))
        {
          pvVar3 = _malloc(0x38);
          if (pvVar3 == (void *)0x0) {
            local_30 = 0;
          }
          else {
            local_30 = FUN_005f7709();
          }
          if (local_30 == 0) {
            return (int *)0x8007000e;
          }
          local_8 = (int *)FUN_005f7760((uint)piVar14 | 0x10000000,piVar14,piVar14,0);
          if ((int)local_8 < 0) goto LAB_006099bc;
          local_10 = (int *)0x0;
          if (piVar14 != (int *)0x0) {
            iVar6 = (*puVar12 & 0xffffff) << 2;
            do {
              local_1c = *(int **)(*(int *)(param_1 + 0x14) + *(int *)(iVar6 + puVar12[2]) * 4);
              *(int *)(*(int *)(local_30 + 8) + (int)local_10 * 4) = *(int *)(iVar6 + puVar12[2]);
              uVar4 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),0xffffffff,local_1c[3],0);
              *(undefined4 *)(*(int *)(local_30 + 0x10) + (int)local_10 * 4) = uVar4;
              *(undefined4 *)(iVar6 + puVar12[2]) =
                   *(undefined4 *)(*(int *)(local_30 + 0x10) + (int)local_10 * 4);
              *(undefined4 *)
               (*(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar6 + puVar12[2]) * 4) + 0x20) = 0;
              local_10 = (int *)((int)local_10 + 1);
              iVar6 = iVar6 + 4;
            } while (local_10 < local_20);
          }
          iVar6 = local_30;
          local_30 = 0;
          piVar10 = (int *)(param_1 + 0x134);
          *(int *)(*(int *)(param_1 + 0x140) + *piVar10 * 4) = iVar6;
          *piVar10 = *piVar10 + 1;
        }
      }
      local_14 = (uint *)((int)local_14 + 1);
    } while (local_14 < *(uint **)(param_1 + 0x88));
  }
  local_30 = 0;
  if ((*(int *)(param_1 + 0x140) != 0) && (local_18 = (int *)0x0, *(int *)(param_1 + 0x134) != 0)) {
    local_28 = (int *)0x0;
    do {
      piVar10 = local_28;
      puVar12 = *(uint **)((int)local_28 + *(int *)(param_1 + 0x140));
      local_38 = puVar12;
      if (((puVar12 != (uint *)0x0) && (uVar8 = *puVar12 & 0xff000000, uVar8 != 0)) &&
         (uVar8 != 0x34000000)) {
        if (((uVar8 == 0x40000000) || (uVar8 == 0x44000000)) ||
           ((uVar8 == 0x48000000 || ((uVar8 == 0x4c000000 || (uVar8 == 0xe1000000)))))) {
          local_2c = (int *)0x0;
          local_1c = (int *)0x0;
          local_10 = (int *)0x0;
          if (*(int *)(param_1 + 0x138) != 0) {
LAB_00608c07:
            local_14 = (uint *)0x0;
            puVar12 = *(uint **)(*(int *)(param_1 + 0x144) + (int)local_10 * 4);
            puVar15 = (uint *)(*puVar12 & 0xffffff);
            local_34 = (int *)(uint)(local_10 < *(int **)(param_1 + 0x88));
            local_4c = puVar15;
            if (puVar15 == (uint *)0x0) goto LAB_00608d48;
            local_c = (uint *)0x0;
            local_54 = (int *)(puVar12[1] / (uint)puVar15);
            if (local_38[3] != 0) {
              local_44 = *(uint **)(*(int *)(*(int *)(param_1 + 0x140) + (int)local_28) + 0xc);
              do {
                if (local_34 < local_54) {
                  local_8 = (int *)((int)puVar15 * (int)local_34 * 4);
                  local_20 = (int *)((int)local_54 - (int)local_34);
                  do {
                    if (puVar15 != (uint *)0x0) {
                      local_50 = *(uint *)(local_38[4] + (int)local_c * 4);
                      puVar9 = (uint *)(puVar12[2] + (int)local_8);
                      local_40 = puVar15;
                      do {
                        local_24 = *(uint **)(*(int *)(param_1 + 0x14) + *puVar9 * 4);
                        if ((*puVar9 == local_50) || (local_24[9] == local_50)) {
                          *(undefined4 *)((int)local_b4 + (int)local_28) = 1;
                          puVar2 = local_4c;
                          if ((local_18 < local_10) &&
                             (**(int **)((int)local_28 + *(int *)(param_1 + 0x144)) != 0)) {
                            local_1c = (int *)0x1;
                            local_14 = local_38;
                          }
                          else if ((*(int **)(param_1 + 0x88) <= local_10) && (local_24[3] == 3)) {
                            local_9c[(uint)local_18 % 6] = 1;
                            puVar15 = puVar2;
                          }
                        }
                        puVar9 = puVar9 + 1;
                        local_40 = (uint *)((int)local_40 + -1);
                      } while (local_40 != (uint *)0x0);
                    }
                    local_8 = local_8 + (int)puVar15;
                    local_20 = (int *)((int)local_20 - 1);
                  } while (local_20 != (int *)0x0);
                }
                local_c = (uint *)((int)local_c + 1);
              } while (local_c < local_44);
            }
            if (local_1c == (int *)0x0) goto LAB_00608d48;
            piVar10 = (int *)(*puVar12 & 0xffffff);
            local_1c = piVar10;
            pvVar3 = _malloc(0x38);
            if (pvVar3 == (void *)0x0) {
              local_30 = 0;
            }
            else {
              local_30 = FUN_005f7709();
            }
            if (local_30 == 0) {
              return (int *)0x8007000e;
            }
            local_8 = (int *)FUN_005f7760((uint)piVar10 | 0x10000000,piVar10,piVar10,0);
            if (-1 < (int)local_8) {
              puVar11 = *(undefined4 **)(local_30 + 0x10);
              for (piVar10 = local_1c; piVar10 != (int *)0x0; piVar10 = (int *)((int)piVar10 - 1)) {
                *puVar11 = 0xffffffff;
                puVar11 = puVar11 + 1;
              }
              local_10 = (int *)0x0;
              puVar15 = local_14;
              if (puVar12[1] != 0) {
                do {
                  local_8 = (int *)0x0;
                  if (puVar15[3] != 0) {
                    do {
                      iVar6 = *(int *)(puVar15[4] + (int)local_8 * 4);
                      if (iVar6 == *(int *)(puVar12[2] + (int)local_10 * 4)) {
                        iVar7 = ((uint)local_10 % (uint)local_1c) * 4;
                        piVar10 = *(int **)(iVar7 + *(int *)(local_30 + 0x10));
                        if (piVar10 == (int *)0xffffffff) {
                          piVar10 = (int *)FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),0xffffffff,
                                                        *(undefined4 *)
                                                         (*(int *)(*(int *)(param_1 + 0x14) +
                                                                  iVar6 * 4) + 0xc),0);
                        }
                        local_20 = piVar10;
                        if (piVar10 == (int *)0xffffffff) {
                          return (int *)0x8007000e;
                        }
                        *(int **)(puVar12[2] + (int)local_10 * 4) = piVar10;
                        *(undefined4 *)(iVar7 + *(int *)(local_30 + 8)) =
                             *(undefined4 *)(local_14[4] + (int)local_8 * 4);
                        *(int **)(iVar7 + *(int *)(local_30 + 0x10)) = piVar10;
                        *(undefined4 *)
                         (*(int *)(*(int *)(param_1 + 0x14) + (int)piVar10 * 4) + 0x20) = 0;
                        puVar15 = local_14;
                      }
                      local_8 = (int *)((int)local_8 + 1);
                    } while (local_8 < (int *)puVar15[3]);
                  }
                  local_10 = (int *)((int)local_10 + 1);
                } while (local_10 < puVar12[1]);
              }
              *(int *)(*(int *)(param_1 + 0x140) + *(int *)(param_1 + 0x134) * 4) = local_30;
              *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + 1;
              local_30 = 0;
              goto LAB_00608ea2;
            }
            goto LAB_006099bc;
          }
LAB_00608ea2:
          piVar10 = local_28;
          local_10 = (int *)0x0;
          local_c = (uint *)0x0;
          if (*(int *)(*(int *)(*(int *)(param_1 + 0x140) + (int)local_28) + 0xc) != 0) {
            local_48 = local_18;
            do {
              iVar6 = *(int *)(*(int *)(param_1 + 0x14) +
                              *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x140) + (int)piVar10) +
                                               0x10) + (int)local_c * 4) * 4);
              *(int **)(iVar6 + 8) = local_18;
              local_8 = (int *)FUN_006077c3(*(int *)(param_1 + 0x140),(int)local_18 + 1,
                                            *(undefined4 *)(param_1 + 0x134),
                                            *(undefined4 *)
                                             (*(int *)(*(int *)((int)piVar10 +
                                                               *(int *)(param_1 + 0x140)) + 0x10) +
                                             (int)local_c * 4),iVar6,&local_3c);
              piVar14 = (int *)FUN_006077c3(*(undefined4 *)(param_1 + 0x144),0,
                                            *(undefined4 *)(param_1 + 0x138),
                                            *(undefined4 *)
                                             (*(int *)(*(int *)(*(int *)(param_1 + 0x140) +
                                                               (int)piVar10) + 0x10) +
                                             (int)local_c * 4),iVar6,&local_3c);
              if (local_10 < piVar14) {
                local_10 = piVar14;
              }
              piVar5 = local_8;
              if (local_3c != (int *)0x0) {
                piVar5 = (int *)0xffffffff;
              }
              if (local_2c < piVar5) {
                local_2c = piVar5;
              }
              iVar7 = *(int *)(iVar6 + 0xc) + (int)piVar10;
              local_c = (uint *)((int)local_c + 1);
              local_114[iVar7] = piVar14;
              iVar6 = *(int *)(*(int *)(param_1 + 0x140) + (int)piVar10);
              auStack_1f4[iVar7] = piVar5;
            } while (local_c < *(uint **)(iVar6 + 0xc));
          }
          piVar14 = local_48;
          local_84[(int)local_48] = (uint)local_2c;
          local_6c[(int)piVar14] = (uint)local_10;
        }
        else {
          local_38 = (uint *)0x0;
          local_34 = (int *)0x0;
          if (puVar12[3] != 0) {
            local_24 = *(uint **)(*(int *)(*(int *)(param_1 + 0x140) + (int)local_28) + 0xc);
            piVar14 = (int *)puVar12[4];
            do {
              if (*(int *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar14 * 4) + 8) == -1) {
                local_38 = (uint *)0x1;
              }
              else {
                local_34 = (int *)0x1;
              }
              piVar14 = piVar14 + 1;
              local_24 = (uint *)((int)local_24 + -1);
            } while (local_24 != (uint *)0x0);
            if (local_34 != (int *)0x0) {
              if (local_38 == (uint *)0x0) goto LAB_00608f96;
              uVar18 = 0x6a5408000012c8;
              uVar4 = 0;
              goto LAB_006098ec;
            }
          }
          local_14 = (uint *)0x0;
          FUN_0060783e(*(undefined4 *)(param_1 + 0x140),(int)local_18 + 1,
                       *(undefined4 *)(param_1 + 0x134),puVar12[4],puVar12[3],local_194,&local_14);
          iVar6 = *(int *)((int)piVar10 + *(int *)(param_1 + 0x140));
          FUN_0060783e(*(undefined4 *)(param_1 + 0x144),0,*(undefined4 *)(param_1 + 0x138),
                       *(undefined4 *)(iVar6 + 0x10),*(undefined4 *)(iVar6 + 0xc),local_194,
                       &local_14);
          local_28 = (int *)0x0;
          do {
            piVar14 = local_28;
            iVar6 = *(int *)((int)piVar10 + *(int *)(param_1 + 0x140));
            local_8 = (int *)FUN_0060807f(local_28,*(undefined4 *)(param_1 + 0x144),
                                          *(undefined4 *)(param_1 + 0x138),
                                          *(undefined4 *)(iVar6 + 0x10),*(undefined4 *)(iVar6 + 0xc)
                                         );
            if ((int)local_8 < 0) {
              return local_8;
            }
            if (((int *)local_84[(int)piVar14] <= local_18) && (local_8 == (int *)0x0)) break;
            piVar14 = (int *)((int)piVar14 + 1);
            local_28 = piVar14;
          } while (piVar14 < (int *)0x6);
          if (piVar14 == (int *)0x6) {
            iVar6 = *(int *)(param_1 + 0x140);
            goto LAB_006098ce;
          }
          local_2c = (int *)0x0;
          local_c = (uint *)0x0;
          if (local_14 != (uint *)0x0) {
            local_48 = piVar14;
            do {
              iVar6 = local_194[(int)local_c];
              iVar7 = *(int *)(*(int *)(param_1 + 0x14) + iVar6 * 4);
              *(int **)(iVar7 + 8) = local_28;
              local_8 = (int *)FUN_006077c3(*(undefined4 *)(param_1 + 0x140),(int)local_18 + 1,
                                            *(undefined4 *)(param_1 + 0x134),iVar6,iVar7,&local_3c);
              piVar5 = (int *)FUN_006077c3(*(undefined4 *)(param_1 + 0x144),0,
                                           *(undefined4 *)(param_1 + 0x138),local_194[(int)local_c],
                                           iVar7,&local_3c);
              piVar14 = local_28;
              if (local_10 < piVar5) {
                local_10 = piVar5;
              }
              if ((*(int **)(param_1 + 0x88) <= piVar5) && (*(int *)(iVar7 + 0xc) == 3)) {
                local_9c[(int)local_28] = 1;
              }
              if (local_3c != (int *)0x0) {
                local_b4[(int)piVar14] = 1;
              }
              if ((local_10 != (int *)0x0) || (local_3c != (int *)0x0)) {
                local_8 = (int *)0xffffffff;
              }
              piVar1 = local_8;
              if (local_2c < local_8) {
                local_2c = local_8;
              }
              iVar6 = *(int *)(iVar7 + 0xc) + (int)piVar14 * 4;
              local_c = (uint *)((int)local_c + 1);
              local_114[iVar6] = piVar5;
              bVar17 = local_c < local_14;
              auStack_1f4[iVar6] = piVar1;
              piVar14 = local_28;
            } while (bVar17);
          }
          local_84[(int)piVar14] = (uint)local_2c;
          local_6c[(int)piVar14] = (uint)local_10;
          FUN_00607a1e();
        }
      }
LAB_00608f96:
      local_18 = (int *)((int)local_18 + 1);
      local_28 = piVar10 + 1;
    } while (local_18 < *(int **)(param_1 + 0x134));
  }
LAB_00608fb0:
  if ((*(int *)(param_1 + 0x144) != 0) && (local_18 = (int *)0x0, *(int *)(param_1 + 0x138) != 0)) {
    do {
      piVar10 = local_18;
      iVar6 = (int)local_18 * 4;
      puVar12 = *(uint **)(iVar6 + *(int *)(param_1 + 0x144));
      if (puVar12 != (uint *)0x0) {
        uVar8 = *puVar12 & 0xff000000;
        if ((uVar8 != 0) && (uVar8 != 0x34000000)) {
          if ((((uVar8 == 0x40000000) ||
               (((((uVar8 == 0x44000000 || (uVar8 == 0x48000000)) || (uVar8 == 0x4c000000)) ||
                 ((uVar8 == 0xe3000000 || (uVar8 == 0xe5000000)))) || (uVar8 == 0xe1000000)))) ||
              (((uVar8 == 0xe6000000 || (uVar8 == 0xe7000000)) || (uVar8 == 0xe8000000)))) ||
             (((uVar8 == 0xea000000 || (uVar8 == 0xe9000000)) || (uVar8 == 0xeb000000)))) {
            local_8 = (int *)0x0;
            local_c = (uint *)0x0;
            if (puVar12[3] != 0) {
              do {
                iVar7 = *(int *)(*(int *)(param_1 + 0x14) +
                                *(int *)((int)local_c * 4 +
                                        *(int *)(*(int *)(*(int *)(param_1 + 0x144) + iVar6) + 0x10)
                                        ) * 4);
                local_48 = local_18;
                if ((*(uint *)(param_1 + 0x30) & 0xffff) != 0x104) {
                  local_48 = (int *)((int)local_18 + 2);
                }
                *(int **)(iVar7 + 8) = local_48;
                piVar10 = (int *)FUN_006077c3(*(int *)(param_1 + 0x144),(int)local_18 + 1,
                                              *(undefined4 *)(param_1 + 0x138),
                                              *(undefined4 *)
                                               (*(int *)(*(int *)(iVar6 + *(int *)(param_1 + 0x144))
                                                        + 0x10) + (int)local_c * 4),iVar7,&local_3c)
                ;
                if (local_8 < piVar10) {
                  local_8 = piVar10;
                }
                local_c = (uint *)((int)local_c + 1);
                local_114[*(int *)(iVar7 + 0xc) + (int)local_48 * 4] = piVar10;
              } while (local_c < *(uint **)(*(int *)(*(int *)(param_1 + 0x144) + iVar6) + 0xc));
            }
            local_6c[(int)local_48] = (uint)local_8;
          }
          else if ((uVar8 != 0xe2000000) && (uVar8 != 0xe4000000)) {
            if ((*(uint *)(param_1 + 0x30) & 0xffff) == 0x101) {
              uVar8 = *puVar12 & 0xffffff;
              local_44 = (uint *)(puVar12[1] / uVar8);
              local_40 = (uint *)0x0;
              local_38 = (uint *)0x0;
              if (local_44 != (uint *)0x0) {
                local_20 = (int *)puVar12[2];
                local_1c = (int *)(uVar8 * 4);
                do {
                  local_14 = (uint *)0x0;
                  piVar14 = *(int **)(*(int *)(param_1 + 0x14) + *local_20 * 4);
                  if (local_38 != (uint *)0x0) {
                    local_34 = (int *)puVar12[2];
                    do {
                      piVar5 = *(int **)(*(int *)(param_1 + 0x14) + *local_34 * 4);
                      if (((*piVar14 == *piVar5) && (piVar14[1] == piVar5[1])) &&
                         (piVar14[2] == piVar5[2])) break;
                      local_14 = (uint *)((int)local_14 + 1);
                      local_34 = local_34 + uVar8;
                    } while (local_14 < local_38);
                  }
                  if (((local_38 == local_14) && (*piVar14 == *(int *)(param_1 + 0x60))) &&
                     (1 < (uint)piVar14[2])) {
                    local_40 = (uint *)((int)local_40 + 1);
                  }
                  local_20 = local_20 + uVar8;
                  local_38 = (uint *)((int)local_38 + 1);
                } while (local_38 < local_44);
                if ((uint *)0x2 < local_40) {
                  iVar6 = *(int *)(param_1 + 0x144);
LAB_006098ce:
                  iVar6 = *(int *)(iVar6 + (int)local_18 * 4);
LAB_006098df:
                  uVar18 = 0x6a53b0000011a9;
                  uVar4 = *(undefined4 *)(iVar6 + 0x34);
LAB_006098ec:
                  FUN_005fbec8(param_1,uVar4,uVar18);
                  return (int *)0x80004005;
                }
              }
            }
            local_24 = (uint *)0x0;
            local_20 = (int *)0x0;
            if (puVar12[3] != 0) {
              local_1c = *(int **)(*(int *)(*(int *)(param_1 + 0x144) + (int)local_18 * 4) + 0xc);
              piVar14 = (int *)puVar12[4];
              do {
                if (*(int *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar14 * 4) + 8) == -1) {
                  local_24 = (uint *)0x1;
                }
                else {
                  local_20 = (int *)0x1;
                }
                piVar14 = piVar14 + 1;
                local_1c = (int *)((int)local_1c - 1);
              } while (local_1c != (int *)0x0);
              if (local_20 != (int *)0x0) {
                if (local_24 != (uint *)0x0) {
                  FUN_005fbec8(param_1,0,0x12c9,"internal error: unvectorized register found");
                  return (int *)0x80004005;
                }
                goto LAB_00609794;
              }
            }
            local_14 = (uint *)0x0;
            FUN_0060783e(*(undefined4 *)(param_1 + 0x144),(int)local_18 + 1,
                         *(undefined4 *)(param_1 + 0x138),puVar12[4],puVar12[3],local_194,&local_14)
            ;
            piVar14 = local_18;
            local_1c = (int *)0xffffffff;
            local_20 = (int *)0xffffffff;
            local_44 = (uint *)(*(uint *)(param_1 + 0x30) & 0xffff);
            if (((local_44 == (uint *)0x102) || (local_44 == (uint *)0x103)) &&
               (piVar5 = *(int **)(*(int *)(param_1 + 0x144) + (int)piVar10 * 4),
               *piVar5 == 0x30000004)) {
              piVar5 = (int *)piVar5[2];
              piVar1 = *(int **)(*(int *)(param_1 + 0x14) + *piVar5 * 4);
              if (*piVar1 == *(int *)(param_1 + 0x60)) {
                local_1c = (int *)piVar1[2];
              }
              piVar5 = *(int **)(*(int *)(param_1 + 0x14) + piVar5[4] * 4);
              if (*piVar5 == *(int *)(param_1 + 0x60)) {
                local_20 = (int *)piVar5[2];
              }
            }
            puVar12 = *(uint **)(*(int *)(param_1 + 0x144) + (int)piVar10 * 4);
            uVar8 = *puVar12;
            if ((((uVar8 & 0xffffff) == 1) && ((uVar8 & 0xff000000) != 0x30000000)) &&
               ((local_14 == (uint *)0x1 &&
                (*(int *)(*(int *)(*(int *)(param_1 + 0x14) + local_194[0] * 4) + 0xc) == 3)))) {
              local_28 = (int *)0x0;
              puVar11 = local_114 + 3;
              do {
                if ((piVar10 < (int *)local_6c[(int)local_28]) && ((int *)*puVar11 <= piVar10))
                break;
                local_28 = (int *)((int)local_28 + 1);
                puVar11 = puVar11 + 4;
              } while (local_28 < (int *)0x6);
              if (local_28 == (int *)0x6) goto LAB_006092c9;
            }
            else {
LAB_006092c9:
              local_28 = (int *)0x0;
              do {
                if ((((int *)local_6c[(int)local_28] <= piVar10) && (local_28 != local_1c)) &&
                   (local_28 != local_20)) break;
                local_28 = (int *)((int)local_28 + 1);
              } while (local_28 < (int *)0x6);
              if (local_28 == (int *)0x6) {
                iVar6 = *(int *)(*(int *)(param_1 + 0x144) + (int)piVar10 * 4);
                goto LAB_006098df;
              }
            }
            local_20 = (int *)0x0;
            if ((((uVar8 & 0xff000000) == 0x30000000) && (local_44 < (uint *)0x104)) &&
               (puVar12[3] == 1)) {
              FUN_00607a58(*(undefined4 *)(param_1 + 0x144),(int)local_18 + 1,
                           *(undefined4 *)(param_1 + 0x138),puVar12[4],1,&local_2c,&local_4c,
                           &local_44);
              if (local_4c != (uint *)0x0) {
                local_2c = (int *)0x4;
              }
              bVar17 = local_2c < (int *)0x4;
              if (bVar17) {
                local_2c = (int *)0x3;
              }
              if (!bVar17 && local_2c != (int *)0x4) {
                local_2c = (int *)0x4;
              }
              pvVar3 = _malloc(0x38);
              if (pvVar3 == (void *)0x0) {
                local_c = (uint *)0x0;
              }
              else {
                local_c = (uint *)FUN_005f7709();
              }
              if (local_c == (uint *)0x0) {
                return (int *)0x8007000e;
              }
              puVar11 = *(undefined4 **)((int)piVar14 * 4 + *(int *)(param_1 + 0x144));
              local_8 = (int *)FUN_005f7760(*puVar11,puVar11[1],local_2c,0);
              if ((int)local_8 < 0) {
                return local_8;
              }
              local_8 = (int *)FUN_005f7a42();
              puVar12 = local_c;
              if ((int)local_8 < 0) {
                return local_8;
              }
              puVar11 = *(undefined4 **)
                         (*(int *)(*(int *)(param_1 + 0x144) + (int)local_18 * 4) + 8);
              puVar16 = (undefined4 *)local_c[2];
              for (uVar8 = local_c[1] & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
                *puVar16 = *puVar11;
                puVar11 = puVar11 + 1;
                puVar16 = puVar16 + 1;
              }
              for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
                *(undefined1 *)puVar16 = *(undefined1 *)puVar11;
                puVar11 = (undefined4 *)((int)puVar11 + 1);
                puVar16 = (undefined4 *)((int)puVar16 + 1);
              }
              iVar6 = *(int *)(*(int *)(param_1 + 0x144) + (int)local_18 * 4);
              piVar10 = *(int **)(iVar6 + 0xc);
              local_1c = piVar10;
              puVar15 = *(uint **)(iVar6 + 0x10);
              puVar9 = local_84 + 2;
              for (; piVar10 != (int *)0x0; piVar10 = (int *)((int)piVar10 - 1)) {
                *puVar9 = *puVar15;
                puVar15 = puVar15 + 1;
                puVar9 = puVar9 + 1;
              }
              if (iVar6 != 0) {
                FUN_005f7186();
                puVar12 = local_c;
              }
              *(uint **)((int)local_18 * 4 + *(int *)(param_1 + 0x144)) = puVar12;
              piVar10 = (int *)0x0;
              local_8 = (int *)0x0;
              local_34 = (int *)0x0;
              if (local_1c != (int *)0x0) {
                do {
                  local_10 = (int *)0x0;
                  if (*(int *)(param_1 + 8) != 0) {
                    do {
                      iVar6 = *(int *)(*(int *)(param_1 + 0x14) + (int)local_10 * 4);
                      piVar14 = (int *)(local_84 + 2)[(int)local_34];
                      if ((local_10 == piVar14) || (*(int **)(iVar6 + 0x24) == piVar14)) {
                        piVar14 = (int *)0x0;
                        piVar10 = local_18;
                        if (local_2c != (int *)0x0) {
                          do {
                            uVar4 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),local_28,piVar14,0)
                            ;
                            *(undefined4 *)(local_c[4] + (int)piVar14 * 4) = uVar4;
                            iVar7 = *(int *)(local_c[4] + (int)piVar14 * 4);
                            if (iVar7 == -1) {
                              return (int *)0x8007000e;
                            }
                            iVar7 = *(int *)(*(int *)(param_1 + 0x14) + iVar7 * 4);
                            *(undefined4 *)(iVar7 + 0x2c) = *(undefined4 *)(iVar6 + 0x2c);
                            *(undefined4 *)(iVar7 + 0x38) = *(undefined4 *)(iVar6 + 0x38);
                            *(undefined4 *)(iVar7 + 0x3c) = *(undefined4 *)(iVar6 + 0x3c);
                            piVar14 = (int *)((int)piVar14 + 1);
                            *(undefined4 *)(iVar7 + 0x20) = *(undefined4 *)(iVar6 + 0x20);
                            piVar10 = local_18;
                          } while (piVar14 < local_2c);
                        }
                        while( true ) {
                          piVar10 = (int *)((int)piVar10 + 1);
                          local_3c = piVar10;
                          if (*(int **)(param_1 + 0x138) <= piVar10) break;
                          puVar12 = *(uint **)(*(int *)(param_1 + 0x144) + (int)piVar10 * 4);
                          uVar8 = *puVar12 & 0xffffff;
                          local_44 = (uint *)(puVar12[1] / uVar8);
                          local_38 = (uint *)0x0;
                          if (local_44 != (uint *)0x0) {
                            local_40 = (uint *)0x0;
                            do {
                              if (uVar8 < 3) {
                                if (uVar8 == 1) {
                                  puVar15 = (uint *)(puVar12[2] + (int)local_38 * 4);
                                  if ((int *)*puVar15 == local_10) {
                                    if (local_2c == (int *)0x4) {
                                      uVar13 = ((uint *)local_c[4])[3];
                                    }
                                    else {
                                      uVar13 = *(uint *)local_c[4];
                                    }
                                    *puVar15 = uVar13;
                                    if (local_8 < piVar10) {
                                      local_8 = piVar10;
                                    }
                                  }
                                }
                                else {
                                  uVar13 = 0;
                                  if (uVar8 != 0) {
                                    local_24 = local_40;
                                    do {
                                      if ((*(int **)(puVar12[2] + (int)local_24) == local_10) &&
                                         (*(uint *)(puVar12[2] + (int)local_24) =
                                               *(uint *)(local_c[4] + uVar13 * 4), local_8 < piVar10
                                         )) {
                                        local_8 = piVar10;
                                      }
                                      local_24 = local_24 + 1;
                                      uVar13 = uVar13 + 1;
                                    } while (uVar13 < uVar8);
                                  }
                                }
                              }
                              else {
                                uVar13 = 0;
                                if (uVar8 != 0) {
                                  local_24 = local_40;
                                  do {
                                    if ((*(int **)(puVar12[2] + (int)local_24) == local_10) &&
                                       (*(uint *)(puVar12[2] + (int)local_24) =
                                             *(uint *)(local_c[4] + uVar13 * 4), local_8 < piVar10))
                                    {
                                      local_8 = piVar10;
                                    }
                                    local_24 = local_24 + 1;
                                    uVar13 = uVar13 + 1;
                                  } while (uVar13 < uVar8);
                                }
                              }
                              local_38 = (uint *)((int)local_38 + 1);
                              local_40 = local_40 + uVar8;
                            } while (local_38 < local_44);
                          }
                        }
                        local_20 = (int *)0x1;
                        piVar10 = local_8;
                      }
                      local_10 = (int *)((int)local_10 + 1);
                    } while (local_10 < *(int **)(param_1 + 8));
                  }
                  local_34 = (int *)((int)local_34 + 1);
                } while (local_34 < local_1c);
              }
              piVar14 = local_28;
              if ((int *)local_6c[(int)local_28] < piVar10) {
                local_6c[(int)local_28] = (uint)piVar10;
              }
              if ((int *)local_114[(int)piVar14 * 4] < piVar10) {
                local_114[(int)piVar14 * 4] = piVar10;
              }
              if ((int *)local_114[(int)piVar14 * 4 + 1] < piVar10) {
                local_114[(int)piVar14 * 4 + 1] = piVar10;
              }
              if ((int *)local_114[(int)piVar14 * 4 + 2] < piVar10) {
                local_114[(int)piVar14 * 4 + 2] = piVar10;
              }
              if ((int *)local_114[(int)piVar14 * 4 + 3] < piVar10) {
                local_114[(int)piVar14 * 4 + 3] = piVar10;
              }
              if (local_20 != (int *)0x0) goto LAB_00609794;
            }
            piVar10 = local_28;
            local_8 = (int *)0x0;
            if (local_14 == (uint *)0x0) {
              **(undefined4 **)((int)local_18 * 4 + *(int *)(param_1 + 0x144)) = 0;
            }
            else {
              local_c = (uint *)0x0;
              if (local_14 != (uint *)0x0) {
                do {
                  iVar6 = local_194[(int)local_c];
                  iVar7 = *(int *)(*(int *)(param_1 + 0x14) + iVar6 * 4);
                  *(int **)(iVar7 + 8) = piVar10;
                  piVar14 = (int *)FUN_006077c3(*(undefined4 *)(param_1 + 0x144),(int)local_18 + 1,
                                                *(undefined4 *)(param_1 + 0x138),iVar6,iVar7,
                                                &local_3c);
                  if (local_8 < piVar14) {
                    local_8 = piVar14;
                  }
                  local_c = (uint *)((int)local_c + 1);
                  local_114[*(int *)(iVar7 + 0xc) + (int)piVar10 * 4] = piVar14;
                } while (local_c < local_14);
              }
              if ((int *)local_6c[(int)piVar10] < local_8) {
                local_6c[(int)piVar10] = (uint)local_8;
              }
              FUN_00607a1e();
            }
          }
        }
      }
LAB_00609794:
      local_18 = (int *)((int)local_18 + 1);
    } while (local_18 < *(int **)(param_1 + 0x138));
  }
  iVar6 = 0;
  uVar8 = 0;
  do {
    if (local_9c[uVar8] != 0) {
      iVar6 = iVar6 + 1;
    }
    uVar8 = uVar8 + 1;
  } while (uVar8 < 6);
  if ((*(int *)(param_1 + 0x140) != 0) && (iVar6 != 0)) {
    local_8 = (int *)FUN_006081f6(local_6c,local_b4,iVar6);
    if ((int)local_8 < 0) {
      return local_8;
    }
    local_14 = (uint *)0x0;
    local_20 = *(int **)(param_1 + 0x138);
    local_24 = local_6c;
    do {
      iVar6 = 0;
      if (local_9c[(int)local_14] != 0) {
        if (0x1ff < *(uint *)(param_1 + 0x134)) {
          return (int *)0x8007000e;
        }
        if (0x1ff < *(uint *)(param_1 + 0x138)) {
          return (int *)0x8007000e;
        }
        local_1c = (int *)FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),local_14,3,0);
        if (local_1c == (int *)0xffffffff) {
          return (int *)0x8007000e;
        }
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + (int)local_1c * 4) + 0x20) = 0;
        pvVar3 = _malloc(0x38);
        if (pvVar3 != (void *)0x0) {
          iVar6 = FUN_005f7709();
        }
        if (iVar6 == 0) {
          return (int *)0x8007000e;
        }
        local_8 = (int *)FUN_005f7760(0x10000001,1,1,0);
        if ((int)local_8 < 0) {
          return local_8;
        }
        uVar8 = *local_24;
        **(uint **)(iVar6 + 0x10) = uVar8;
        **(uint **)(iVar6 + 8) = (uint)local_1c;
        *(int *)(*(int *)(param_1 + 0x140) + *(int *)(param_1 + 0x134) * 4) = iVar6;
        *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + 1;
        pvVar3 = _malloc(0x38);
        if (pvVar3 == (void *)0x0) {
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_005f7709();
        }
        if (iVar6 == 0) {
          return (int *)0x8007000e;
        }
        local_8 = (int *)FUN_005f7760(0x10000001,1,1,0);
        if ((int)local_8 < 0) {
          return local_8;
        }
        **(uint **)(iVar6 + 0x10) = (uint)local_1c;
        **(uint **)(iVar6 + 8) = uVar8;
        *(int *)(*(int *)(param_1 + 0x144) + *(int *)(param_1 + 0x138) * 4) = iVar6;
        *(int *)(param_1 + 0x138) = *(int *)(param_1 + 0x138) + 1;
        local_24 = local_24 + 1;
      }
      local_14 = (uint *)((int)local_14 + 1);
    } while (local_14 < (uint *)0x6);
    for (piVar10 = *(int **)(param_1 + 0x88); piVar10 < local_20;
        piVar10 = (int *)((int)piVar10 + 1)) {
      if (0x1ff < *(uint *)(param_1 + 0x138)) {
        return (int *)0x8007000e;
      }
      *(undefined4 *)(*(int *)(param_1 + 0x144) + *(uint *)(param_1 + 0x138) * 4) =
           *(undefined4 *)(*(int *)(param_1 + 0x144) + (int)piVar10 * 4);
      *(int *)(param_1 + 0x138) = *(int *)(param_1 + 0x138) + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x144) + (int)piVar10 * 4) = 0;
    }
  }
  if (((*(int *)(param_1 + 0x140) == 0) || ((*(uint *)(param_1 + 0x30) & 0xffff) != 0x104)) ||
     (local_8 = (int *)FUN_00608700(), -1 < (int)local_8)) {
    local_8 = (int *)0x0;
LAB_006099bc:
    if (local_30 != 0) {
      FUN_005f7186();
    }
  }
  return local_8;
LAB_00608d48:
  local_10 = (int *)((int)local_10 + 1);
  if (*(int **)(param_1 + 0x138) <= local_10) goto LAB_00608ea2;
  goto LAB_00608c07;
}


// ==== 0x6099dc FUN_006099dc

undefined4 __thiscall
FUN_006099dc(int param_1,int param_2,uint param_3,int param_4,uint param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  uint uVar6;
  int *piVar7;
  bool bVar8;
  uint local_18;
  uint local_c;
  
  local_c = 0;
  if (param_3 != 0) {
    do {
      iVar1 = *(int *)(param_2 + local_c * 4);
      if ((iVar1 != 0) && (param_5 <= *(uint *)(iVar1 + 0xc))) {
        bVar5 = true;
        local_18 = 0;
        if (param_5 == 0) {
LAB_00609ac7:
          return *(undefined4 *)(param_2 + local_c * 4);
        }
        do {
          iVar2 = *(int *)(param_4 + local_18 * 4);
          iVar3 = *(int *)(*(int *)(param_1 + 0x14) + iVar2 * 4);
          uVar6 = 0;
          if (param_6 == 0) {
            bVar8 = *(int *)(iVar1 + 0xc) == 0;
            if (*(int *)(iVar1 + 0xc) != 0) {
              piVar7 = *(int **)(iVar1 + 0x10);
              do {
                iVar4 = *piVar7;
                if (((iVar4 == iVar2) && (*(int *)(iVar3 + 0x20) == 0)) ||
                   ((iVar4 == *(int *)(iVar3 + 0x24) &&
                    (*(int *)(*(int *)(*(int *)(param_1 + 0x14) + iVar4 * 4) + 0x20) == 0)))) break;
                uVar6 = uVar6 + 1;
                piVar7 = piVar7 + 1;
              } while (uVar6 < *(uint *)(iVar1 + 0xc));
              goto LAB_00609a93;
            }
          }
          else {
            bVar8 = *(int *)(iVar1 + 0xc) == 0;
            if (*(int *)(iVar1 + 0xc) != 0) {
              piVar7 = *(int **)(iVar1 + 0x10);
              do {
                if ((*piVar7 == iVar2) || (*piVar7 == *(int *)(iVar3 + 0x24))) break;
                uVar6 = uVar6 + 1;
                piVar7 = piVar7 + 1;
              } while (uVar6 < *(uint *)(iVar1 + 0xc));
LAB_00609a93:
              bVar8 = uVar6 == *(uint *)(iVar1 + 0xc);
            }
          }
          if (bVar8) {
            bVar5 = false;
          }
          local_18 = local_18 + 1;
        } while (local_18 < param_5);
        if (bVar5) goto LAB_00609ac7;
      }
      local_c = local_c + 1;
    } while (local_c < param_3);
  }
  return 0;
}


// ==== 0x609ad2 FUN_00609ad2

undefined4 __thiscall
FUN_00609ad2(int param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5,
            int *param_6,undefined4 *param_7,int param_8,uint param_9)

{
  bool bVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  puVar2 = param_4;
  uVar9 = *param_4 & 0xffffff;
  *param_7 = 0;
  *param_6 = 0;
  *param_5 = 0;
  if (uVar9 == 0) {
    uVar3 = 0x80004005;
  }
  else {
    uVar4 = param_4[1] / uVar9;
    if ((param_9 == 0) && (param_9 = 0, uVar4 != 0)) {
      param_4 = (uint *)0x0;
      do {
        uVar8 = 0;
        if (uVar9 != 0) {
          piVar5 = (int *)(puVar2[2] + (int)param_4);
          do {
            if (*(uint *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar5 * 4) + 0xc) != uVar8) {
              return 1;
            }
            uVar8 = uVar8 + 1;
            piVar5 = piVar5 + 1;
          } while (uVar8 < uVar9);
        }
        param_9 = param_9 + 1;
        param_4 = (uint *)((int)param_4 + uVar9 * 4);
      } while (param_9 < uVar4);
    }
    iVar10 = 0;
    bVar1 = false;
    param_4 = (uint *)0x0;
    if (uVar4 != 0) {
      do {
        puVar6 = (uint *)FUN_006099dc(param_2,param_3,puVar2[2] + iVar10 * 4,uVar9,param_8);
        if (puVar6 != (uint *)0x0) {
          uVar8 = *puVar6 & 0xff000000;
          if (param_8 == 0) {
            if (uVar8 == 0xe1000000) goto LAB_00609bbf;
          }
          else if ((((uVar8 == 0x40000000) || (uVar8 == 0x44000000)) || (uVar8 == 0x48000000)) ||
                  (uVar8 == 0x4c000000)) {
LAB_00609bbf:
            if (bVar1) {
              *param_6 = 0;
              *param_5 = 0;
              *param_7 = 0;
              return 1;
            }
            *param_7 = puVar6;
            bVar1 = true;
            *param_6 = iVar10;
            if (param_8 == 0) {
              iVar7 = *(int *)puVar6[2];
            }
            else {
              iVar7 = *(int *)(puVar6[2] + (*puVar6 & 0xffffff) * 4);
            }
            *param_5 = (uint)*(byte *)(*(int *)(*(int *)(param_1 + 0x14) + iVar7 * 4) + 0x51);
          }
        }
        param_4 = (uint *)((int)param_4 + 1);
        iVar10 = iVar10 + uVar9;
      } while (param_4 < uVar4);
    }
    uVar3 = 0;
  }
  return uVar3;
}


// ==== 0x609c31 FUN_00609c31

int __thiscall FUN_00609c31(int param_1,int *param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  bool bVar4;
  char *pcVar5;
  int *piVar6;
  void *pvVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int local_50 [5];
  int local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  int *local_c;
  int local_8;
  
  local_8 = 0;
  local_10 = 0;
  if (param_3 != 0) {
    local_c = param_2;
    do {
      puVar2 = (uint *)*local_c;
      if (puVar2 != (uint *)0x0) {
        local_24 = *puVar2;
        uVar10 = local_24 & 0xffffff;
        local_1c = uVar10;
        FUN_00609ad2(param_4,4,puVar2,&local_18,&local_28,&local_14,1,1);
        if (local_14 == 0) {
          if (uVar10 == 2) {
            uVar10 = puVar2[2];
            local_20 = FUN_006099dc(*(undefined4 *)(param_1 + 0x140),
                                    *(undefined4 *)(param_1 + 0x134),uVar10 + 8,1,0);
            local_30 = FUN_006099dc(*(undefined4 *)(param_1 + 0x140),
                                    *(undefined4 *)(param_1 + 0x134),uVar10 + 0xc,1,0);
            if ((((local_20 != 0) && (local_30 != 0)) &&
                (FUN_00609ad2(param_4,4,local_20,&local_18,&local_28,&local_2c,1,1), local_2c != 0))
               && (FUN_00609ad2(param_4,4,local_30,&local_18,&local_28,&local_14,1,1),
                  uVar10 = local_1c, local_2c == local_14)) goto LAB_00609d52;
          }
        }
        else if (uVar10 != 2) {
LAB_00609d52:
          if (local_14 != 0) {
            uVar9 = 0;
            local_8 = 0;
            if (uVar10 == 3) {
              if (((local_24 & 0xff000000) == 0x4c000000) || ((local_24 & 0xff000000) == 0x48000000)
                 ) {
                local_28 = 1;
                piVar6 = (int *)(puVar2[2] + 0xc);
                do {
                  iVar8 = *(int *)(*(int *)(param_1 + 0x14) + *piVar6 * 4);
                  if (*(uint *)(iVar8 + 0xc) != uVar9) {
                    local_28 = 0;
                  }
                  iVar8 = *(int *)(iVar8 + 0x20);
                  if ((iVar8 != 0) && (iVar8 != 0x60000)) {
                    pcVar5 = 
                    "cannot match to texreg2rgb instruction because can only have input modifier _bx2"
                    ;
                    goto LAB_0060a0cb;
                  }
                  uVar9 = uVar9 + 1;
                  piVar6 = piVar6 + 1;
                } while (uVar9 < 3);
                if (local_28 != 0) {
                  if ((*(uint *)(param_1 + 0x30) & 0xffff) < 0x102) {
                    FUN_005fbec8(param_1,*(undefined4 *)(param_2[local_10] + 0x34),0x11b8,
                                 "expression can only be map to texreg2rgb, but this instruction is not supported on 1_%i"
                                 ,*(uint *)(param_1 + 0x30) & 0xff);
                    return -0x7fffbffb;
                  }
                  pvVar7 = _malloc(0x38);
                  if (pvVar7 == (void *)0x0) {
                    local_8 = 0;
                  }
                  else {
                    local_8 = FUN_005f7709();
                  }
                  if (local_8 == 0) {
LAB_0060a0ec:
                    iVar8 = -0x7ff8fff2;
                  }
                  else {
                    iVar8 = FUN_005f7760(0xe6000003,6,4,0);
                    if (-1 < iVar8) goto LAB_00609ef0;
                  }
                  goto LAB_0060a07e;
                }
              }
            }
            else if ((uVar10 == 2) && ((local_24 & 0xff000000) == 0x44000000)) {
              uVar10 = 0;
              bVar4 = true;
              local_50[2] = 3;
              local_50[3] = 0;
              local_50[0] = 1;
              local_50[1] = 2;
              local_28 = 1;
              do {
                iVar8 = local_20;
                if (uVar10 != 0) {
                  iVar8 = local_30;
                }
                iVar8 = *(int *)(*(int *)(param_1 + 0x14) + **(int **)(iVar8 + 8) * 4);
                iVar3 = *(int *)(iVar8 + 0xc);
                if (iVar3 != local_50[uVar10 + 2]) {
                  local_28 = 0;
                }
                if (iVar3 != local_50[uVar10]) {
                  bVar4 = false;
                }
                if (*(int *)(iVar8 + 0x20) != 0) {
                  pcVar5 = 
                  "cannot match to texreg2ar or texreg2gb instruction because cannot have input modifiers"
                  ;
LAB_0060a0cb:
                  FUN_005fbec8(param_1,*(undefined4 *)(param_2[local_10] + 0x34),0x11b7,pcVar5);
                  return -0x7fffbffb;
                }
                uVar10 = uVar10 + 1;
              } while (uVar10 < 2);
              if ((local_28 != 0) || (bVar4)) {
                pvVar7 = _malloc(0x38);
                if (pvVar7 == (void *)0x0) {
                  local_8 = 0;
                }
                else {
                  local_8 = FUN_005f7709();
                }
                if (local_8 == 0) goto LAB_0060a0ec;
                iVar8 = FUN_005f7760((-(uint)bVar4 & 0x1000000) + 0xe7000002,4,4,0);
                if (iVar8 < 0) goto LAB_0060a07e;
LAB_00609ef0:
                uVar10 = 0;
                do {
                  *(undefined4 *)(uVar10 + *(int *)(local_8 + 0x10)) =
                       *(undefined4 *)(uVar10 + *(int *)(*local_c + 0x10));
                  uVar10 = uVar10 + 4;
                } while (uVar10 < 0x10);
                piVar6 = *(int **)(*(int *)(param_1 + 0x14) + **(int **)(*local_c + 8) * 4);
                local_34 = *(undefined4 *)
                            (*(int *)(param_1 + 0x14) + *(int *)(*(int *)(local_14 + 8) + 0xc) * 4);
                uVar10 = local_18;
                if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar6 * 4) + 5) & 4) == 0) {
                  for (; (uVar10 < 4 && (*(int *)(param_4 + uVar10 * 4) != 0)); uVar10 = uVar10 + 1)
                  {
                  }
                  if (uVar10 == 4) goto LAB_00609f4e;
                  piVar6[2] = uVar10;
                }
                else {
                  uVar10 = piVar6[2];
                  local_28 = uVar10;
                  if ((3 < uVar10) || (*(int *)(param_4 + uVar10 * 4) != 0)) {
LAB_00609f4e:
                    iVar8 = -0x7fffbffb;
                    goto LAB_0060a07e;
                  }
                }
                local_28 = uVar10;
                local_3c = FUN_005f74cf(*(undefined4 *)(param_1 + 0x58),uVar10,0,0);
                if (local_3c == -1) goto LAB_0060a0ec;
                iVar8 = *(int *)(*(int *)(param_1 + 0x14) + local_3c * 4);
                FUN_005f7c63();
                *(uint *)(iVar8 + 0x50) = uVar10 << 8 | 3;
                *(uint *)(iVar8 + 8) = uVar10;
                uVar9 = 0;
                if (local_1c != 0) {
                  local_24 = local_1c << 2;
                  do {
                    local_50[4] = FUN_005f74cf(*(undefined4 *)(param_1 + 0x58),local_18,uVar9,0);
                    if (local_50[4] == -1) goto LAB_0060a0ec;
                    iVar8 = *(int *)(*(int *)(param_1 + 0x14) + local_50[4] * 4);
                    local_38 = *(int *)(*(int *)(param_1 + 0x14) +
                                       *(int *)(local_1c * 4 + *(int *)(*local_c + 8)) * 4);
                    FUN_005f7c63();
                    *(uint *)(iVar8 + 8) = local_18;
                    *(uint *)(iVar8 + 0xc) = uVar9;
                    *(undefined4 *)(iVar8 + 0x20) = *(undefined4 *)(local_38 + 0x20);
                    *(int *)(*(int *)(local_8 + 8) + uVar9 * 4) = local_3c;
                    uVar1 = local_24 + 4;
                    uVar9 = uVar9 + 1;
                    *(int *)(local_24 + *(int *)(local_8 + 8)) = local_50[4];
                    uVar10 = local_28;
                    local_24 = uVar1;
                  } while (uVar9 < local_1c);
                }
                piVar6 = local_c;
                *(int *)(param_4 + uVar10 * 4) = local_8;
                if (*local_c != 0) {
                  FUN_005f7186();
                }
                *piVar6 = 0;
                local_8 = 0;
              }
            }
          }
        }
      }
      local_10 = local_10 + 1;
      local_c = local_c + 1;
    } while (local_10 < param_3);
  }
  iVar8 = 0;
LAB_0060a07e:
  if (local_8 != 0) {
    FUN_005f7186();
  }
  return iVar8;
}


// ==== 0x60a0f3 FUN_0060a0f3

/* WARNING: Type propagation algorithm not settling */

int __thiscall FUN_0060a0f3(int param_1,int *param_2,uint param_3,int param_4,uint param_5)

{
  uint *puVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  void *pvVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  uint auStack_88 [6];
  uint auStack_70 [6];
  uint local_58;
  uint local_4c [4];
  uint auStack_3c [4];
  int local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  int *local_1c;
  uint *local_18;
  int *local_14;
  uint local_10;
  int *local_c;
  uint local_8;
  
  local_28 = 0;
  local_4c[0] = 0;
  local_4c[1] = 0;
  local_4c[2] = 0;
  if (param_3 != 0) {
    local_1c = param_2;
    do {
      puVar1 = (uint *)*local_1c;
      if (puVar1 != (uint *)0x0) {
        uVar3 = *puVar1 & 0xffffff;
        uVar7 = *puVar1 & 0xff000000;
        uVar4 = uVar3;
        if (uVar7 == 0x40000000) {
          uVar4 = 1;
        }
        if ((uVar4 == param_5) && (uVar7 != 0x34000000)) {
          local_10 = 0;
          local_8 = 0;
          if (param_5 != 0) {
            local_c = (int *)(puVar1[2] + uVar3 * 4);
            do {
              piVar5 = (int *)FUN_006099dc(*(undefined4 *)(param_1 + 0x140),
                                           *(undefined4 *)(param_1 + 0x134),local_c,1,0);
              uVar4 = local_8;
              local_14 = piVar5;
              auStack_88[local_8 + 3] = (uint)piVar5;
              if ((piVar5 == (int *)0x0) || (*piVar5 != 0x30000003)) {
                local_10 = 1;
              }
              else {
                FUN_00609ad2(*(undefined4 *)(param_1 + 0x140),*(undefined4 *)(param_1 + 0x134),
                             local_14,auStack_70 + uVar4 + 0xd,auStack_70 + uVar4,auStack_88 + uVar4
                             ,0,0);
                local_18 = auStack_70 + uVar4 + 6;
                FUN_00609ad2(param_4,4,local_14,local_18,auStack_70 + uVar4 + 3,auStack_3c + 3,1,0);
                if (((auStack_88[uVar4] == 0) || (*local_18 != local_58)) || (auStack_3c[3] == 0)) {
                  local_10 = 1;
                }
              }
              local_8 = local_8 + 1;
              local_c = local_c + 1;
            } while (local_8 < param_5);
            if (local_10 != 0) goto LAB_0060a64c;
          }
          local_8 = 0;
          if (param_5 != 0) {
            do {
              uVar4 = local_8;
              local_18 = *(uint **)(param_1 + 0x88);
              if (local_18 < *(uint **)(param_1 + 0x138)) {
                local_14 = (int *)(*(int *)(param_1 + 0x144) + (int)local_18 * 4);
                do {
                  local_c = (int *)*local_14;
                  if (((local_c != (int *)0x0) &&
                      (puVar1 = (uint *)*local_1c, puVar1 != (uint *)0x0)) && (*local_c != 0)) {
                    local_10 = *puVar1 & 0xffffff;
                    local_20 = puVar1[1];
                    if (*puVar1 == 0xef000003) {
                      local_20 = 6;
                    }
                    if (local_10 < local_20) {
                      uVar3 = local_c[1];
                      do {
                        local_24 = 0;
                        if (uVar3 != 0) {
                          iVar9 = *(int *)(puVar1[2] + local_10 * 4);
                          piVar5 = (int *)local_c[2];
                          piVar8 = local_c;
                          do {
                            if ((*piVar5 == iVar9) ||
                               (piVar8 = local_c,
                               *(int *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar5 * 4) + 0x24) ==
                               iVar9)) {
                              uVar12 = 0x6a56e8000011ac;
                              iVar9 = piVar8[0xd];
                              goto LAB_0060a691;
                            }
                            local_24 = local_24 + 1;
                            uVar3 = local_c[1];
                            piVar5 = piVar5 + 1;
                            piVar8 = local_c;
                          } while (local_24 < uVar3);
                        }
                        local_10 = local_10 + 1;
                      } while (local_10 < local_20);
                    }
                  }
                  local_14 = local_14 + 1;
                  local_18 = (uint *)((int)local_18 + 1);
                } while (local_18 < *(uint **)(param_1 + 0x138));
              }
              if ((local_8 != 0) &&
                 ((auStack_70[local_8 + 0xc] <= local_58 ||
                  (auStack_70[local_8 + 0xd] != auStack_70[local_8 + 0xc] + 1)))) {
                uVar13 = CONCAT44(*(undefined4 *)(param_1 + 0x30),
                                  "unable to match texm* because source inputs are not in appropriate texture coordinates. See ps_1_% assembly reference for more information"
                                 ) & 0xffffffffff;
                uVar11 = 0x11ad;
                uVar10 = 0;
                goto LAB_0060a6f7;
              }
              if (*(int *)(*(int *)(*(int *)(param_1 + 0x14) +
                                   *(int *)(*(int *)(auStack_88[local_8 + 3] + 8) +
                                           auStack_70[local_8] * 4) * 4) + 0x20) != 0) {
                uVar12 = 0x6a5600000011ae;
LAB_0060a6cd:
                iVar9 = 0;
                goto LAB_0060a691;
              }
              iVar9 = *(int *)(*(int *)(*(int *)(param_1 + 0x14) +
                                       *(int *)(*(int *)(auStack_88[local_8 + 3] + 8) +
                                               auStack_70[local_8 + 3] * 4) * 4) + 0x20);
              if ((iVar9 != 0) && (iVar9 != 0x60000)) {
                uVar12 = 0x6a55b0000011af;
                goto LAB_0060a6cd;
              }
              pvVar6 = _malloc(0x38);
              if (pvVar6 == (void *)0x0) {
                uVar3 = 0;
              }
              else {
                uVar3 = FUN_005f7709();
              }
              auStack_70[uVar4 + 9] = uVar3;
              if (uVar3 == 0) {
                iVar9 = -0x7ff8fff2;
                goto LAB_0060a661;
              }
              if (local_8 == param_5 - 1) {
                if (*(int *)*local_1c == -0x10fffffd) {
                  if (param_5 != 3) {
LAB_0060a6d7:
                    iVar9 = 1;
                    goto LAB_0060a661;
                  }
                  uVar12 = 4;
                  uVar10 = 9;
                  iVar9 = -0x15fffffd;
                }
                else if (*(int *)*local_1c == -0x11fffffd) {
                  if (param_5 != 3) goto LAB_0060a6d7;
                  uVar12 = 4;
                  uVar10 = 6;
                  iVar9 = -0x16fffffd;
                }
                else {
                  uVar12 = 4;
                  uVar10 = 6;
                  if (param_5 != 1) {
                    iVar9 = ((param_5 != 3) - 1 & 0x2000000) + 0xe3000003;
                    goto LAB_0060a41b;
                  }
                  iVar9 = -0x14fffffd;
                }
              }
              else {
                uVar12 = 0;
                iVar9 = ((param_5 != 3) - 1 & 0x2000000) + 0xe2000003;
LAB_0060a41b:
                uVar10 = 6;
              }
              iVar9 = FUN_005f7760(iVar9,uVar10,uVar12);
              if (iVar9 < 0) goto LAB_0060a661;
              local_8 = local_8 + 1;
            } while (local_8 < param_5);
          }
          local_8 = 0;
          if (param_5 != 0) {
            do {
              local_14 = (int *)0x0;
              uVar4 = auStack_70[local_8 + 9];
              local_24 = auStack_88[local_8 + 3];
              local_10 = auStack_88[local_8];
              local_20 = auStack_70[local_8 + 3] << 2;
              local_18 = (uint *)(auStack_70[local_8] << 2);
              uVar3 = 0xc;
              do {
                *(undefined4 *)((uVar3 - 0xc) + *(int *)(uVar4 + 8)) =
                     *(undefined4 *)((int)local_18 + *(int *)(local_24 + 8));
                *(undefined4 *)(uVar3 + *(int *)(uVar4 + 8)) =
                     *(undefined4 *)(local_20 + *(int *)(local_24 + 8));
                local_4c[3] = *(undefined4 *)
                               (*(int *)(param_1 + 0x14) +
                               *(int *)((uVar3 - 0xc) + *(int *)(uVar4 + 8)) * 4);
                local_2c = *(int *)(*(int *)(param_1 + 0x14) +
                                   *(int *)(uVar3 + *(int *)(uVar4 + 8)) * 4);
                iVar9 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x58),0,0,0);
                local_c = *(int **)(*(int *)(param_1 + 0x14) + iVar9 * 4);
                *(int *)(uVar3 + *(int *)(uVar4 + 8)) = iVar9;
                FUN_005f7c63();
                local_2c = *(int *)(local_2c + 0x20);
                FUN_005f7c63();
                local_c[3] = (int)local_14;
                local_c[8] = local_2c;
                if ((*(int *)*local_1c == -0x10fffffd) && (local_8 == param_5 - 1)) {
                  *(undefined4 *)(uVar3 + 0xc + *(int *)(uVar4 + 8)) =
                       *(undefined4 *)(uVar3 + 0xc + ((int *)*local_1c)[2]);
                }
                local_14 = (int *)((int)local_14 + 1);
                local_18 = local_18 + 1;
                local_20 = local_20 + 4;
                uVar3 = uVar3 + 4;
              } while (uVar3 < 0x18);
              local_8 = local_8 + 1;
            } while (local_8 < param_5);
          }
          uVar4 = auStack_70[param_5 + 8];
          uVar3 = 0;
          do {
            *(undefined4 *)(uVar3 + *(int *)(uVar4 + 0x10)) =
                 *(undefined4 *)(uVar3 + *(int *)(*local_1c + 0x10));
            uVar3 = uVar3 + 4;
          } while (uVar3 < 0x10);
          uVar4 = 0;
          if (param_5 != 0) {
            do {
              if (*(int *)(param_4 + auStack_70[uVar4 + 0xd] * 4) != 0) goto LAB_0060a69a;
              uVar4 = uVar4 + 1;
            } while (uVar4 < param_5);
          }
          piVar5 = *(int **)(*(int *)(param_1 + 0x14) + **(int **)(*local_1c + 8) * 4);
          iVar9 = *(int *)(*(int *)(param_1 + 0x10) + *piVar5 * 4);
          uVar4 = *(uint *)(iVar9 + 4);
          if ((uVar4 & 0x40) == 0) {
            uVar12 = 0x6a5584000012cc;
            iVar9 = 0;
LAB_0060a691:
            FUN_005fbec8(param_1,iVar9,uVar12);
LAB_0060a69a:
            iVar9 = -0x7fffbffb;
            goto LAB_0060a661;
          }
          if ((uVar4 & 0x420) == 0) {
            piVar5[2] = auStack_70[param_5 + 0xc];
          }
          else if (auStack_70[param_5 + 0xc] != piVar5[2]) {
            if ((*(byte *)(iVar9 + 5) & 4) == 0) {
              pcVar2 = "cannot bind sampler to sampler array, sampler must be bound to %i";
            }
            else {
              pcVar2 = "cannot bind sampler to user specified stage, sampler must be bound to %i";
            }
            uVar13 = CONCAT44(auStack_70[param_5 + 0xc],pcVar2);
            uVar11 = 0x11a3;
            uVar10 = *(undefined4 *)(param_2[local_28] + 0x34);
LAB_0060a6f7:
            FUN_005fbec8(param_1,uVar10,uVar11,uVar13);
            goto LAB_0060a69a;
          }
          local_8 = 0;
          piVar5 = local_1c;
          if (param_5 != 0) {
            do {
              iVar9 = local_8 + 0xd;
              uVar4 = auStack_70[local_8 + 9];
              auStack_70[local_8 + 9] = 0;
              *(uint *)(param_4 + auStack_70[iVar9] * 4) = uVar4;
              if (*piVar5 != 0) {
                FUN_005f7186();
                piVar5 = local_1c;
              }
              *piVar5 = 0;
              local_8 = local_8 + 1;
            } while (local_8 < param_5);
          }
        }
      }
LAB_0060a64c:
      local_28 = local_28 + 1;
      local_1c = local_1c + 1;
    } while (local_28 < param_3);
  }
  iVar9 = 0;
LAB_0060a661:
  uVar4 = 0;
  do {
    if (auStack_70[uVar4 + 9] != 0) {
      FUN_005f7186();
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 3);
  return iVar9;
}


// ==== 0x60a702 FUN_0060a702

uint __fastcall FUN_0060a702(int param_1)

{
  byte bVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_28 [9];
  
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  puVar6 = (undefined4 *)(param_1 + 0x10c);
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  local_28[8] = 0;
  local_28[6] = 0;
  local_28[5] = 0;
  local_28[4] = 0;
  local_28[7] = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      piVar2 = *(int **)(*(int *)(param_1 + 0x14) + local_28[7] * 4);
      iVar5 = *(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4);
      if ((piVar2[1] != -1) && (local_28[6] == 0)) {
        FUN_005fbec8(param_1,piVar2[0x11],0x119f,"relative addressing not supported in ps_1_x");
        local_28[6] = 1;
        local_28[8] = 1;
      }
      uVar4 = *(uint *)(iVar5 + 4);
      if ((uVar4 & 0x10) == 0) {
        if (((uVar4 & 8) != 0) && ((uVar4 & 0x100) == 0)) {
          uVar4 = (uint)*(byte *)((int)piVar2 + 0x51);
          if ((piVar2[0x14] & 0xffU) == 1) {
            if (uVar4 < 2) {
              puVar3 = (uint *)(param_1 + 300 + uVar4 * 4);
              goto LAB_0060a82b;
            }
          }
          else if (((piVar2[0x14] & 0xffU) == 3) && (uVar4 < 8)) {
            puVar3 = (uint *)(param_1 + 0x10c + uVar4 * 4);
LAB_0060a82b:
            if (*puVar3 < piVar2[3] + 1U) {
              *puVar3 = piVar2[3] + 1U;
            }
          }
        }
      }
      else {
        bVar1 = *(byte *)((int)piVar2 + 0x51);
        if (3 < bVar1) break;
        if ((piVar2[0x14] & 0xffU) == 1) {
          if (bVar1 == 0) {
            local_28[piVar2[3]] = 1;
            local_28[4] = piVar2[0x11];
          }
        }
        else if (((((piVar2[0x14] & 0xffU) == 2) && (bVar1 == 0)) && (piVar2[3] != 0)) &&
                (local_28[5] == 0)) {
          FUN_005fbec8(param_1,piVar2[0x11],0x11b0,"DEPTH must be a scalar");
          local_28[5] = 1;
          local_28[8] = 1;
        }
      }
      local_28[7] = local_28[7] + 1;
    } while ((uint)local_28[7] < *(uint *)(param_1 + 8));
  }
  iVar5 = 0;
  uVar4 = 0;
  do {
    iVar5 = iVar5 + (uint)(local_28[uVar4] != 0);
    uVar4 = uVar4 + 1;
  } while (uVar4 < 4);
  if (iVar5 != 4) {
    FUN_005fbec8(param_1,local_28[4],0x11b2,
                 "pixel shader must minimally write all four components of COLOR0");
    local_28[8] = 1;
  }
  uVar4 = 0;
  puVar3 = (uint *)(param_1 + 0x10c);
  do {
    if (3 < *puVar3) {
      if ((*(uint *)(param_1 + 0x30) & 0xffff) == 0x104) {
        FUN_005fbec8(param_1,0,0x11a0,
                     "accessing texture coordinate w-component not yet implemented in ps_1_4");
      }
      else {
        FUN_005fbec8(param_1,0,0x11a0,"cannot access texture coordinate w-component in ps_1_%d",
                     *(uint *)(param_1 + 0x30) & 0xff);
      }
      local_28[8] = 1;
      break;
    }
    uVar4 = uVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (uVar4 < 8);
  return -(uint)(local_28[8] != 0) & 0x80004005;
}


// ==== 0x60a8f2 FUN_0060a8f2

int __fastcall FUN_0060a8f2(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_28 [4];
  undefined4 local_18 [4];
  int local_8;
  
  iVar4 = *(int *)(param_1 + 0x98);
  local_8 = *(int *)(iVar4 + 0xc);
  piVar1 = *(int **)(iVar4 + 0x10);
  uVar5 = 0;
  do {
    *(undefined4 *)((int)local_28 + uVar5) = *(undefined4 *)(*(int *)(iVar4 + 8) + 0xc);
    *(undefined4 *)((int)local_18 + uVar5) = *(undefined4 *)(*(int *)(iVar4 + 8) + 0x1c);
    uVar5 = uVar5 + 4;
  } while (uVar5 < 0x10);
  piVar2 = *(int **)(*(int *)(param_1 + 0x14) + *piVar1 * 4);
  if (*piVar2 == *(int *)(param_1 + 0x5c)) {
    iVar3 = local_8;
    if (piVar2[0x14] != 1) {
      FUN_005fbec8(param_1,*(undefined4 *)(iVar4 + 0x34),0x12cd,
                   "internal error: unexpected output register");
      return -0x7fffbffb;
    }
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar1 * 4) + 8) = 0;
      **(undefined4 **)(*(int *)(param_1 + 0x14) + *piVar1 * 4) = *(undefined4 *)(param_1 + 0x60);
    }
  }
  iVar4 = *(int *)(*(int *)(param_1 + 0x98) + 8);
  iVar4 = FUN_0061a3fb(8,piVar1,local_8,iVar4,iVar4 + 0x10,0,2,0,0,0);
  if (-1 < iVar4) {
    iVar4 = FUN_0061a3fb(4,piVar1,local_8,local_28,local_18,piVar1,local_8,0,0,0);
  }
  return iVar4;
}


// ==== 0x60a9c6 FUN_0060a9c6

int __thiscall FUN_0060a9c6(int *param_1,uint param_2)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 local_c;
  uint local_8;
  
  puVar1 = (uint *)param_1[0x26];
  piVar2 = (int *)puVar1[2];
  uVar6 = *puVar1 & 0xffffff;
  piVar5 = (int *)(-(uint)(uVar6 != puVar1[1]) & (uint)(piVar2 + uVar6));
  piVar3 = (int *)(-(uint)(uVar6 * 2 < puVar1[1]) & (uint)(piVar2 + uVar6 * 2));
  iVar4 = FUN_0061a26f(param_2);
  if (-1 < iVar4) {
    param_2 = (uint)*(byte *)(*(int *)(param_1[5] + *piVar2 * 4) + 0x51);
    local_8 = param_2 | 0xb0000000;
    iVar4 = (**(code **)(*param_1 + 0x54))(local_8,0xf0000);
    if (-1 < iVar4) {
      if (piVar5 != (int *)0x0) {
        iVar4 = (**(code **)(*param_1 + 100))
                          (*(undefined4 *)(param_1[5] + *piVar5 * 4),&local_8,&param_2);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = (**(code **)(*param_1 + 0x68))(piVar5,uVar6,0xf0000,&local_c);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = (**(code **)(*param_1 + 0x58))(local_8,local_c,param_2);
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      if (piVar3 != (int *)0x0) {
        iVar4 = (**(code **)(*param_1 + 100))
                          (*(undefined4 *)(param_1[5] + *piVar3 * 4),&local_8,&param_2);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = (**(code **)(*param_1 + 0x68))(piVar3,uVar6,0xf0000,&local_c);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = (**(code **)(*param_1 + 0x58))(local_8,local_c,param_2);
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      iVar4 = (**(code **)(*param_1 + 0x50))();
      if ((-1 < iVar4) && (iVar4 = FUN_0061663f(), -1 < iVar4)) {
        iVar4 = 0;
      }
    }
  }
  return iVar4;
}


// ==== 0x60ab02 FUN_0060ab02

int __fastcall FUN_0060ab02(int *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  undefined4 local_8;
  
  uVar3 = *(uint *)param_1[0x26] & 0xffffff;
  local_c = uVar3;
  if ((param_1[0xc] & 0xffffU) == 0x104) {
    iVar2 = FUN_0061a26f(0x42);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*param_1 + 0x5c))
                      (*(undefined4 *)(param_1[5] + **(int **)(param_1[0x26] + 0x10) * 4),&local_8,0
                      );
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*param_1 + 0x54))(local_8,0xf0000);
    if (iVar2 < 0) {
      return iVar2;
    }
    piVar1 = (int *)(*(int *)(param_1[0x26] + 8) + uVar3 * 4);
    iVar2 = (**(code **)(*param_1 + 100))
                      (*(undefined4 *)(param_1[5] + *piVar1 * 4),&local_8,&local_10);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*param_1 + 0x68))(piVar1,local_c,0xf0000,&local_14);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*param_1 + 0x58))(local_8,local_14,local_10);
  }
  else {
    iVar2 = FUN_0061a26f(0x42);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*param_1 + 0x5c))
                      (*(undefined4 *)(param_1[5] + **(int **)(param_1[0x26] + 0x10) * 4),&local_8,0
                      );
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*param_1 + 0x54))(local_8,0xf0000);
  }
  if (((-1 < iVar2) && (iVar2 = (**(code **)(*param_1 + 0x50))(), -1 < iVar2)) &&
     (iVar2 = FUN_0061663f(), -1 < iVar2)) {
    iVar2 = 0;
  }
  return iVar2;
}


// ==== 0x60ac1e FUN_0060ac1e

int __fastcall FUN_0060ac1e(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined1 local_18 [4];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = *(undefined4 *)(param_1[5] + *(int *)((uint *)param_1[0x26])[4] * 4);
  uVar4 = *(uint *)param_1[0x26] & 0xffffff;
  if ((param_1[0xc] & 0xffffU) == 0x104) {
    iVar3 = FUN_0061a26f(0x40);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(*param_1 + 0x5c))(uVar1,&local_8,&local_c);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(*param_1 + 0x60))
                      (*(undefined4 *)(param_1[0x26] + 0x10),uVar4,&local_10,local_c);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(*param_1 + 0x54))(local_8,0x70000);
    if (iVar3 < 0) {
      return iVar3;
    }
    piVar2 = *(int **)(param_1[0x26] + 8);
    iVar3 = (**(code **)(*param_1 + 100))
                      (*(undefined4 *)(param_1[5] + *piVar2 * 4),&local_8,&local_14);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(*param_1 + 0x68))(piVar2,uVar4,local_10,local_18);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(*param_1 + 0x58))(local_8,0xe40000,local_14);
  }
  else {
    iVar3 = FUN_0061a26f(0x40);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(*param_1 + 0x5c))(uVar1,&local_8,&local_c);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(*param_1 + 0x60))
                      (*(undefined4 *)(param_1[0x26] + 0x10),uVar4,&local_10,local_c);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(*param_1 + 0x54))(local_8,0xf0000);
  }
  if (((-1 < iVar3) && (iVar3 = (**(code **)(*param_1 + 0x50))(), -1 < iVar3)) &&
     (iVar3 = FUN_0061663f(), -1 < iVar3)) {
    iVar3 = 0;
  }
  return iVar3;
}


// ==== 0x60ad62 FUN_0060ad62

uint __thiscall FUN_0060ad62(int param_1,uint param_2)

{
  if (*(int *)(*(int *)(param_1 + 0x98) + 0x24) == 1) {
    param_2 = param_2 | 0x40000000;
  }
  return param_2;
}


// ==== 0x60ad7a FUN_0060ad7a

undefined4 __thiscall FUN_0060ad7a(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)(param_2 + 0x51);
  uVar1 = *(uint *)(param_2 + 0x50) & 0xff;
  if (uVar1 == 1) {
    if (*(uint *)(param_1 + 0x6c) <= uVar2) {
      return 0x80004005;
    }
  }
  else {
    if (uVar1 != 3) {
      if (uVar1 == 5) {
        *param_3 = 0xc;
        return 0;
      }
      return 0x80004005;
    }
    if (*(uint *)(param_1 + 0x7c) <= uVar2) {
      return 0x80004005;
    }
    uVar2 = uVar2 + 2;
  }
  *param_3 = uVar2;
  return 0;
}


// ==== 0x60adc6 FUN_0060adc6

undefined4 __thiscall FUN_0060adc6(int param_1,int param_2,uint *param_3,undefined4 *param_4)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = *(uint *)(param_2 + 0x50);
  bVar1 = *(byte *)(param_2 + 0x51);
  *param_3 = (uint)bVar1;
  uVar2 = uVar2 & 0xff;
  uVar3 = 1;
  if (uVar2 == 1) {
    uVar2 = *(uint *)(param_1 + 0x6c);
  }
  else {
    uVar3 = 3;
    if (uVar2 != 3) {
      return 0x80004005;
    }
    uVar2 = *(uint *)(param_1 + 0x7c);
  }
  if (uVar2 <= bVar1) {
    return 0x80004005;
  }
  *param_4 = uVar3;
  return 0;
}


// ==== 0x60ae08 FUN_0060ae08

uint FUN_0060ae08(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  bool bVar8;
  char local_30 [31];
  undefined1 local_11;
  int local_10;
  int local_c;
  uint local_8;
  
  piVar2 = param_1;
  uVar7 = 0;
  local_10 = 0;
  local_8 = 0;
  _strncpy(local_30,*(char **)(param_1[0x13] + 0x18),0x1f);
  local_11 = 0;
  pcVar6 = local_30;
  if (local_30[0] == '\0') {
LAB_0060ae65:
    param_1 = (int *)0x0;
  }
  else {
    do {
      iVar4 = _isalpha((int)*pcVar6);
      if (iVar4 == 0) break;
      pcVar6 = pcVar6 + 1;
    } while (*pcVar6 != '\0');
    if (*pcVar6 == '\0') goto LAB_0060ae65;
    param_1 = (int *)_atoi(pcVar6);
  }
  if (*pcVar6 != '\0') {
    *pcVar6 = '\0';
    pcVar6 = pcVar6 + 1;
  }
  cVar3 = *pcVar6;
  if (cVar3 == '\0') {
LAB_0060ae98:
    param_1 = (int *)((int)param_1 + ((uint)piVar2[0x15] >> 2));
  }
  else {
    do {
      iVar4 = _isdigit((int)cVar3);
      if (iVar4 == 0) break;
      pcVar6 = pcVar6 + 1;
      cVar3 = *pcVar6;
    } while (cVar3 != '\0');
    if (*pcVar6 == '\0') goto LAB_0060ae98;
    param_1 = (int *)0xffffffff;
  }
  iVar4 = local_c;
  if (piVar2[0x14] == 0xffffffff) {
    uVar7 = *(uint *)(*(int *)(*(int *)(local_c + 0x10) + *piVar2 * 4) + 4);
    if (((uVar7 & 8) != 0) && ((uVar7 & 0x100) == 0)) {
      iVar5 = __stricmp(local_30,"color");
      if (iVar5 == 0) {
        local_8 = 1;
        if (param_2 == 0) {
          uVar7 = *(uint *)(iVar4 + 0x6c);
        }
        else {
          uVar7 = 2;
        }
LAB_0060af43:
        bVar8 = param_1 < uVar7;
LAB_0060afb9:
        uVar7 = 1 - bVar8;
      }
      else {
        iVar5 = __stricmp(local_30,"texcoord");
        if (iVar5 == 0) {
          local_8 = 3;
          if (param_2 == 0) {
            uVar7 = *(uint *)(iVar4 + 0x7c);
          }
          else {
            uVar7 = 8;
          }
          goto LAB_0060af43;
        }
        iVar4 = __stricmp(local_30,"position");
        if (((iVar4 == 0) || (iVar4 = __stricmp(local_30,"fog"), iVar4 == 0)) ||
           (iVar4 = __stricmp(local_30,"psize"), iVar4 == 0)) {
          bVar8 = param_1 == (int *)0x0;
          local_8 = 4;
          goto LAB_0060afb9;
        }
        iVar4 = __stricmp(local_30,"diffuse");
        if (iVar4 == 0) {
          local_8 = 1;
          uVar7 = (uint)(param_1 != (int *)0x0);
          local_10 = 1;
          if (uVar7 == 0) {
            param_1 = (int *)0x0;
          }
        }
        else {
          iVar4 = __stricmp(local_30,"specular");
          if (iVar4 == 0) {
            local_8 = 1;
            uVar7 = (uint)(param_1 != (int *)0x0);
            local_10 = 1;
            if (uVar7 == 0) {
              param_1 = (int *)0x1;
            }
          }
          else {
            local_8 = 0;
            uVar7 = 1;
          }
        }
      }
      if ((param_2 == 0) || (piVar2[3] == 0)) {
        if (uVar7 == 0) {
          if (local_10 != 0) {
            FUN_005fbf37(local_c,piVar2[0x13],0x1261,
                         "input semantic \'%s\' has been deprecated; use \'%s%d\' instead",local_30,
                         *(undefined4 *)(local_8 * 4 + 0x6df4b0),param_1);
          }
        }
        else {
          FUN_005fbec8(local_c,piVar2[0x13],0x1196,"invalid input semantic \'%s%d\'",local_30,
                       param_1);
        }
      }
      if (((local_8 == 4) || (uVar7 != 0)) && ((*(int *)(local_c + 0x204) == 0 && (param_2 == 0))))
      {
        *(int *)(local_c + 0x204) = 1;
        FUN_005fbec8(local_c,piVar2[0x13],0x1196,"invalid reference to input semantic \'%s%d\'",
                     local_30,param_1);
        uVar7 = 1;
      }
      goto LAB_0060b16f;
    }
    if ((uVar7 & 0x10) != 0) {
      iVar5 = __stricmp(local_30,"color");
      if (iVar5 == 0) {
        local_8 = 1;
        uVar7 = (uint)(*(uint *)(iVar4 + 0x84) <= param_1);
LAB_0060b119:
        if (uVar7 != 0) goto LAB_0060b11d;
      }
      else {
        iVar4 = __stricmp(local_30,"depth");
        if (iVar4 != 0) {
          local_8 = 0;
          uVar7 = 1;
          goto LAB_0060b119;
        }
        local_8 = 4;
        uVar7 = 1;
LAB_0060b11d:
        if ((param_2 == 0) || (piVar2[3] == 0)) {
          FUN_005fbec8(local_c,piVar2[0x13],0x1196,"invalid output semantic \'%s%d\'",local_30,
                       param_1);
        }
      }
      if (local_8 == 4) {
        if (param_2 != 0) goto LAB_0060b21d;
        pcVar6 = "output semantic \'%s%d\' not yet implemented in ps_1_x";
        iVar4 = piVar2[0x13];
        goto LAB_0060b167;
      }
      goto LAB_0060b16f;
    }
  }
  else {
    param_1 = (int *)(uint)*(byte *)((int)piVar2 + 0x51);
    local_8 = piVar2[0x14] & 0xff;
    if (local_8 == 4) {
      if ((*(int *)(local_c + 0x204) != 0) || (param_2 != 0)) goto LAB_0060b21d;
      uVar7 = 1;
      *(int *)(local_c + 0x204) = 1;
      pcVar6 = "invalid reference to input semantic \'%s%d\'";
      iVar4 = piVar2[0x13];
LAB_0060b167:
      FUN_005fbec8(local_c,iVar4,0x1196,pcVar6,local_30,param_1);
    }
LAB_0060b16f:
    if (local_8 == 3) {
      if ((((param_1 != (int *)0x0) && (param_1 < 4)) && (piVar2[3] == 3)) &&
         ((*(uint *)(local_c + 0x30) & 0xffff) < 0x104)) {
        piVar1 = (int *)(local_c + 0x1f8);
        if (*piVar1 == -1) {
          iVar4 = FUN_005f7478(&DAT_006a58fc,0x29,0xffffffff,4);
          *piVar1 = iVar4;
        }
        iVar4 = *piVar1;
        if (iVar4 == -1) {
          return 0x8007000e;
        }
        piVar2[2] = 0;
        local_8 = 5;
        *piVar2 = iVar4;
        piVar2[3] = (int)param_1 - 1;
        goto LAB_0060b21d;
      }
      if (((param_1 < *(uint *)(local_c + 0x7c)) || (param_2 != 0)) ||
         (*(int *)(local_c + 0x204) != 0)) goto LAB_0060b21d;
      uVar7 = 1;
      *(int *)(local_c + 0x204) = 1;
      FUN_005fbec8(local_c,piVar2[0x13],0x1196,
                   "\'texcoord\' reference exceeds valid range for this shader model (max: %i)",
                   *(uint *)(local_c + 0x7c));
    }
    if (local_8 != 0) goto LAB_0060b21d;
  }
  uVar7 = 1;
LAB_0060b21d:
  if (0xffff < param_1) {
    uVar7 = 1;
  }
  piVar2[0x14] = local_8 & 0xff | (int)param_1 << 8;
  return -(uint)(uVar7 != 0) & 0x80004005;
}


// ==== 0x60b24d FUN_0060b24d

undefined4 FUN_0060b24d(int param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x50);
  uVar2 = (uint)*(byte *)(param_1 + 0x51);
  *param_2 = uVar2;
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 1) {
    if (uVar2 != 0) {
      return 0x80004005;
    }
    *param_3 = 0;
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0;
    }
  }
  else {
    if (uVar1 != 2) {
      return 0x80004005;
    }
    if (uVar2 != 0) {
      return 0x80004005;
    }
    *param_3 = 9;
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 1;
    }
  }
  return 0;
}


// ==== 0x60b2a9 FUN_0060b2a9

undefined4 __thiscall FUN_0060b2a9(int param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint auStack_64 [8];
  uint auStack_44 [9];
  uint local_20;
  int local_1c;
  int local_18;
  uint local_c;
  uint local_8;
  
  puVar5 = param_2;
  if (param_2 == (uint *)0x0) {
    uVar8 = 1;
  }
  else {
    iVar9 = FUN_005f7a96();
    if (iVar9 == 0) {
      uVar14 = *param_2 & 0xffffff;
      local_20 = param_2[1] / uVar14;
      if (1 < local_20) {
        iVar9 = *(int *)(param_1 + 0x58);
        param_2 = (uint *)0x0;
        iVar1 = *(int *)(param_1 + 0x60);
        iVar2 = *(int *)(param_1 + 0x54);
        auStack_44[iVar9] = 0;
        auStack_44[iVar1] = 0;
        auStack_44[iVar2] = 0;
        iVar3 = *(int *)(param_1 + 0x68);
        local_1c = iVar2 * 4;
        auStack_44[iVar3] = 0;
        local_18 = iVar3 * 4;
        auStack_64[iVar9] = 2;
        auStack_64[iVar1] = 3;
        *(undefined4 *)((int)auStack_64 + local_1c) = 2;
        uVar12 = local_20;
        *(undefined4 *)((int)auStack_64 + local_18) = 1;
        local_c = 0;
        if (uVar12 != 0) {
          piVar4 = (int *)puVar5[2];
          piVar10 = piVar4;
          do {
            puVar5 = *(uint **)(*(int *)(param_1 + 0x14) + *piVar10 * 4);
            uVar12 = *puVar5;
            iVar9 = *(int *)(*(int *)(param_1 + 0x10) + uVar12 * 4);
            local_8 = 0;
            piVar11 = piVar4;
            if (local_c != 0) {
              do {
                puVar6 = *(uint **)(*(int *)(param_1 + 0x14) + *piVar11 * 4);
                if ((((uVar12 == *puVar6) && (puVar5[1] == puVar6[1])) && (puVar5[2] == puVar6[2]))
                   && ((((*(byte *)(iVar9 + 4) & 0x80) == 0 ||
                        ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *puVar6 * 4) + 4) & 0x80) ==
                         0)) || (*(double *)(puVar5 + 4) == *(double *)(puVar6 + 4))))) break;
                local_8 = local_8 + 1;
                piVar11 = piVar11 + uVar14;
              } while (local_8 < local_c);
            }
            if (local_8 == local_c) {
              if (uVar12 == *(uint *)(param_1 + 0x58)) {
                uVar13 = *(uint *)(param_1 + 0x58);
                if ((char)puVar5[0x14] == '\x03') {
                  if ((((*(uint *)(param_1 + 0x30) & 0xffff) == 0x101) &&
                      (param_2 = (uint *)((int)param_2 + 1), 2 < param_2)) &&
                     (param_3 == (uint *)0x0)) {
                    return 1;
                  }
                  uVar13 = *(uint *)(param_1 + 0x60);
                }
              }
              else {
                uVar7 = *(uint *)(iVar9 + 4);
                if ((uVar7 & 0x100) == 0) {
                  uVar13 = uVar12;
                  if ((uVar7 & 0x40) != 0) goto LAB_0060b435;
                }
                else if ((uVar7 & 0x40) == 0) {
                  uVar13 = *(uint *)(param_1 + 0x54);
                }
                else {
LAB_0060b435:
                  uVar13 = *(uint *)(param_1 + 0x68);
                }
              }
              if ((((((puVar5[0xb] != 0xffffffff) &&
                     (uVar7 = *(uint *)(param_1 + 0x60), uVar12 == uVar7)) &&
                    ((*(uint *)(param_1 + 0x30) & 0xffff) == 0x101)) &&
                   (puVar5 = *(uint **)(*(int *)(param_1 + 0x18) + puVar5[0xb] * 4), uVar13 = uVar7,
                   puVar5 != (uint *)0x0)) &&
                  (((uVar12 = *puVar5 & 0xff000000, uVar12 == 0x4c000000 || (uVar12 == 0x44000000))
                   || ((uVar12 == 0x48000000 || (uVar12 == 0x40000000)))))) &&
                 ((param_2 = (uint *)((int)param_2 + 1), 2 < param_2 && (param_3 == (uint *)0x0))))
              {
                return 1;
              }
              if (uVar13 < 8) {
                puVar5 = auStack_44 + uVar13;
                *puVar5 = *puVar5 + 1;
                if (auStack_64[uVar13] < *puVar5) {
                  if (param_3 == (uint *)0x0) {
                    return 1;
                  }
                  *param_3 = local_c;
                  return 1;
                }
              }
            }
            piVar10 = piVar10 + uVar14;
            local_c = local_c + 1;
          } while (local_c < local_20);
        }
      }
      uVar8 = 0;
    }
    else {
      uVar8 = 0;
    }
  }
  return uVar8;
}


// ==== 0x60b4e1 FUN_0060b4e1

undefined4 __thiscall FUN_0060b4e1(int *param_1,int param_2,uint param_3,int *param_4)

{
  int *piVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  uint *puVar9;
  uint *puVar10;
  uint local_18;
  uint local_14;
  int *local_c;
  
  uVar5 = (int)param_4 - 1;
  do {
    if (uVar5 <= param_3) {
      return 0;
    }
    bVar3 = false;
    piVar8 = (int *)(param_3 * 4 + param_2);
    puVar9 = (uint *)*piVar8;
    piVar1 = (int *)(param_3 * 4 + 4 + param_2);
    puVar10 = (uint *)*piVar1;
    if ((puVar9 != (uint *)0x0) && (puVar10 != (uint *)0x0)) {
      puVar9[9] = 0;
      puVar10[9] = 0;
      bVar4 = false;
      if (((*puVar9 & 0xffffff) == 1) && ((*puVar10 & 0xffffff) < 4)) {
        puVar9 = (uint *)*piVar1;
        puVar10 = (uint *)*piVar8;
        bVar4 = true;
      }
      else if (((*puVar9 & 0xffffff) == 4) || ((*puVar10 & 0xffffff) != 1)) goto LAB_0060b6de;
      if ((((((param_1[0xc] & 0xffffU) == 0x104) ||
            (iVar6 = (**(code **)(*param_1 + 0x84))(puVar9,puVar10), iVar6 == 0)) &&
           (uVar7 = *puVar9 & 0xff000000, uVar7 != 0xe1000000)) &&
          (((uVar7 != 0xe0000000 && (uVar7 != 0x44000000)) &&
           ((uVar7 != 0x48000000 && ((uVar7 != 0x40000000 && (uVar7 != 0x4c000000)))))))) &&
         (uVar7 != 0)) {
        bVar2 = false;
        if (puVar9[3] != 0) {
          local_c = (int *)puVar9[4];
          local_18 = puVar9[3];
          do {
            iVar6 = *local_c;
            if (*(int *)(*(int *)(param_1[5] + iVar6 * 4) + 0xc) == 3) {
              bVar3 = true;
            }
            if (puVar10[1] != 0) {
              param_4 = (int *)puVar10[2];
              local_14 = puVar10[1];
              do {
                if ((*(int *)(*(int *)(param_1[5] + *param_4 * 4) + 0x24) == iVar6) ||
                   (*param_4 == iVar6)) {
                  bVar2 = true;
                }
                param_4 = param_4 + 1;
                local_14 = local_14 - 1;
              } while (local_14 != 0);
            }
            local_c = local_c + 1;
            local_18 = local_18 - 1;
          } while (local_18 != 0);
        }
        param_4 = (int *)0x0;
        if (puVar10[3] != 0) {
          do {
            if (puVar9[1] != 0) {
              local_18 = puVar9[1];
              iVar6 = *(int *)(puVar10[4] + (int)param_4 * 4);
              piVar8 = (int *)puVar9[2];
              do {
                if ((*(int *)(*(int *)(param_1[5] + *piVar8 * 4) + 0x24) == iVar6) ||
                   (*piVar8 == iVar6)) {
                  bVar2 = true;
                }
                piVar8 = piVar8 + 1;
                local_18 = local_18 - 1;
              } while (local_18 != 0);
            }
            param_4 = (int *)((int)param_4 + 1);
          } while (param_4 < puVar10[3]);
        }
        if (((!bVar2) && (!bVar3)) &&
           (*(int *)(*(int *)(param_1[5] + *(int *)puVar10[4] * 4) + 0xc) == 3)) {
          if (bVar4) {
            puVar9[9] = 1;
          }
          else {
            puVar10[9] = 1;
          }
          param_3 = param_3 + 1;
        }
      }
    }
LAB_0060b6de:
    param_3 = param_3 + 1;
  } while( true );
}


// ==== 0x60b6f6 FUN_0060b6f6

undefined4 __thiscall FUN_0060b6f6(int param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  bool bVar10;
  bool bVar11;
  uint auStack_80 [8];
  uint auStack_60 [8];
  uint local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  int local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  if (param_2 == (uint *)0x0) {
    uVar5 = 1;
  }
  else {
    iVar6 = FUN_005f7a96();
    if (iVar6 == 0) {
      uVar1 = *param_2;
      local_14 = param_2[1] / (uVar1 & 0xffffff);
      uVar2 = param_3[1];
      uVar7 = *param_3 & 0xffffff;
      iVar6 = *(int *)(param_1 + 0x58);
      auStack_60[iVar6] = 0;
      iVar9 = *(int *)(param_1 + 0x60);
      local_34 = iVar6 * 4;
      auStack_60[iVar9] = 0;
      iVar6 = *(int *)(param_1 + 0x54);
      local_30 = iVar9 * 4;
      auStack_60[iVar6] = 0;
      local_c = 0;
      local_20 = 0;
      *(undefined4 *)((int)auStack_80 + local_34) = 2;
      *(undefined4 *)((int)auStack_80 + local_30) = 5;
      auStack_80[iVar6] = 3;
      local_8 = 0;
      local_40 = uVar2 / uVar7 + local_14;
      if (local_40 != 0) {
        local_30 = (uVar1 & 0xffffff) << 2;
        local_2c = uVar7 * local_14 * -4;
        local_28 = uVar7 << 2;
        local_34 = 0;
        local_38 = local_2c;
        do {
          if (local_8 < local_14) {
            iVar6 = *(int *)(local_34 + param_2[2]);
          }
          else {
            iVar6 = *(int *)(local_2c + param_3[2]);
          }
          piVar3 = *(int **)(*(int *)(param_1 + 0x14) + iVar6 * 4);
          iVar6 = *piVar3;
          local_10 = 0;
          local_3c = *(int *)(*(int *)(param_1 + 0x10) + iVar6 * 4);
          local_24 = iVar6 * 4;
          if (local_8 != 0) {
            local_1c = 0;
            local_18 = local_38;
            do {
              puVar8 = param_3;
              iVar9 = local_18;
              if (local_10 < local_14) {
                puVar8 = param_2;
                iVar9 = local_1c;
              }
              piVar4 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)(iVar9 + puVar8[2]) * 4);
              if (((iVar6 == *piVar4) && (piVar3[1] == piVar4[1])) && (piVar3[2] == piVar4[2]))
              break;
              local_18 = local_18 + local_28;
              local_10 = local_10 + 1;
              local_1c = local_1c + local_30;
            } while (local_10 < local_8);
          }
          if (local_10 == local_8) {
            iVar9 = *(int *)(param_1 + 0x60);
            if (((iVar6 == iVar9) && (1 < (uint)piVar3[2])) && (local_c = local_c + 1, 3 < local_c))
            {
              return 1;
            }
            if (iVar6 == *(int *)(param_1 + 0x58)) {
              iVar6 = *(int *)(param_1 + 0x58);
              if ((((char)piVar3[0x14] == '\x03') &&
                  (iVar6 = iVar9, (*(uint *)(param_1 + 0x30) & 0xffff) == 0x101)) &&
                 (local_c = local_c + 1, 3 < local_c)) {
                return 1;
              }
              puVar8 = auStack_60 + iVar6;
              *puVar8 = *puVar8 + 1;
              bVar10 = *puVar8 < auStack_80[iVar6];
              bVar11 = *puVar8 == auStack_80[iVar6];
            }
            else {
              uVar1 = *(uint *)(local_3c + 4);
              if ((uVar1 & 0x40) != 0) break;
              if ((uVar1 & 0x100) == 0) {
                puVar8 = auStack_60 + iVar6;
                *puVar8 = *puVar8 + 1;
                bVar10 = *puVar8 < auStack_80[iVar6];
                bVar11 = *puVar8 == auStack_80[iVar6];
              }
              else {
                local_20 = local_20 + 1;
                bVar10 = local_20 < 3;
                bVar11 = local_20 == 3;
              }
            }
            if (!bVar10 && !bVar11) {
              return 1;
            }
          }
          local_8 = local_8 + 1;
          local_2c = local_2c + local_28;
          local_34 = local_34 + local_30;
        } while (local_8 < local_40);
      }
      uVar5 = 0;
    }
    else {
      uVar5 = 0;
    }
  }
  return uVar5;
}


// ==== 0x60b913 FUN_0060b913

undefined4 __thiscall FUN_0060b913(int param_1,int param_2,uint param_3,uint param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int *piVar8;
  bool bVar9;
  int local_28 [8];
  int local_8;
  
  bVar9 = (param_4 & 0x10000) != 0;
  local_8 = param_1;
  if (bVar9) {
    local_28[4] = 0;
  }
  uVar3 = (uint)bVar9;
  if ((param_4 & 0x20000) != 0) {
    local_28[uVar3 + 4] = 1;
    uVar3 = uVar3 + 1;
  }
  if ((param_4 & 0x40000) != 0) {
    local_28[uVar3 + 4] = 2;
    uVar3 = uVar3 + 1;
  }
  if ((param_4 & 0x80000) != 0) {
    local_28[uVar3 + 4] = 3;
    uVar3 = uVar3 + 1;
  }
  if (uVar3 < param_3) {
    param_3 = uVar3;
  }
  local_28[0] = -1;
  local_28[1] = 0xffffffff;
  local_28[2] = 0xffffffff;
  uVar3 = 0;
  local_28[3] = 0xffffffff;
  if (param_3 != 0) {
    iVar4 = *(int *)(param_1 + 0x14);
    do {
      iVar2 = uVar3 + 4;
      iVar1 = uVar3 * 4;
      uVar3 = uVar3 + 1;
      local_28[local_28[iVar2]] = *(int *)(*(int *)(iVar4 + *(int *)(param_2 + iVar1) * 4) + 0xc);
    } while (uVar3 < param_3);
  }
  if ((*(uint *)(local_8 + 0x30) & 0xffff) == 0x104) {
    uVar3 = 0;
    puVar7 = &DAT_006df4f8;
    do {
      iVar4 = FUN_0060dde6(local_28,puVar7);
      if (iVar4 != 0) {
        piVar8 = &DAT_006df4f8 + uVar3 * 4;
        if (piVar8 != (int *)0x0) goto LAB_0060ba57;
        break;
      }
      uVar3 = uVar3 + 1;
      puVar7 = puVar7 + 4;
    } while (uVar3 < 5);
    FUN_005fbec8(local_8,*(undefined4 *)(*(int *)(local_8 + 0x98) + 0x34),0x11b5,
                 "cannot map swizzle to ps_1_4");
    uVar5 = 0x80004005;
  }
  else {
    piVar8 = &DAT_006df528;
    iVar4 = FUN_0060dde6(local_28,&DAT_006df528);
    if (iVar4 == 0) {
      piVar8 = &DAT_006df538;
      iVar4 = FUN_0060dde6(local_28,&DAT_006df538);
      if (((iVar4 == 0) && (iVar4 = FUN_0060dde6(local_28,&DAT_006df518), iVar4 != 0)) &&
         ((param_4 & 0xf0000) == 0x80000)) {
        piVar8 = &DAT_006df518;
      }
    }
LAB_0060ba57:
    uVar6 = 0;
    uVar3 = 0x10;
    do {
      iVar4 = *piVar8;
      piVar8 = piVar8 + 1;
      uVar6 = uVar6 | iVar4 << ((byte)uVar3 & 0x1f);
      uVar3 = uVar3 + 2;
    } while (uVar3 < 0x18);
    *param_5 = uVar6;
    uVar5 = 0;
  }
  return uVar5;
}


// ==== 0x60ba7c FUN_0060ba7c

void __fastcall FUN_0060ba7c(undefined4 *param_1)

{
  uint uVar1;
  
  *param_1 = &PTR_FUN_006a4cb8;
  if (param_1[0x50] != 0) {
    uVar1 = 0;
    do {
      if (*(int *)(uVar1 + param_1[0x50]) != 0) {
        FUN_005f7186(1);
      }
      uVar1 = uVar1 + 4;
    } while (uVar1 < 0x800);
  }
  if (param_1[0x51] != 0) {
    uVar1 = 0;
    do {
      if (*(int *)(uVar1 + param_1[0x51]) != 0) {
        FUN_005f7186(1);
      }
      uVar1 = uVar1 + 4;
    } while (uVar1 < 0x800);
  }
  _free((void *)param_1[0x50]);
  _free((void *)param_1[0x51]);
  FUN_00613825();
  return;
}


// ==== 0x60bafa FUN_0060bafa

uint __fastcall FUN_0060bafa(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  uint *puVar10;
  uint uVar11;
  bool bVar12;
  int local_e4 [32];
  int local_64 [9];
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  uint local_28;
  int local_24;
  uint *local_20;
  int local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  uVar8 = 0;
  local_1c = 0;
  local_24 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      piVar9 = *(int **)(*(int *)(param_1 + 0x14) + uVar8 * 4);
      piVar9[7] = 0;
      if (*piVar9 == *(int *)(param_1 + 0x60)) {
        piVar9[2] = -1;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(param_1 + 8));
  }
  for (uVar8 = *(uint *)(param_1 + 0x88); uVar8 < *(uint *)(param_1 + 0x138); uVar8 = uVar8 + 1) {
    piVar9 = *(int **)(*(int *)(param_1 + 0x144) + uVar8 * 4);
    if (((piVar9 != (int *)0x0) && (*piVar9 != 0)) && (uVar11 = 0, piVar9[3] != 0)) {
      do {
        iVar5 = uVar11 * 4;
        uVar11 = uVar11 + 1;
        *(uint *)(*(int *)(*(int *)(param_1 + 0x14) + *(int *)(piVar9[4] + iVar5) * 4) + 0x2c) =
             uVar8;
      } while (uVar11 < (uint)piVar9[3]);
    }
  }
  local_34 = *(uint *)(param_1 + 0x138);
  local_30 = *(uint *)(param_1 + 0x88);
  bVar12 = local_30 < local_34;
LAB_0060c1cb:
  if (!bVar12) {
    local_c = 0;
LAB_0060c1d7:
    if (local_1c != 0) {
LAB_0060c1de:
      FUN_005f7186();
    }
LAB_0060c1e5:
    if (local_24 != 0) {
      FUN_005f7186();
    }
    return local_c;
  }
  local_20 = *(uint **)(*(int *)(param_1 + 0x144) + local_30 * 4);
  if ((local_20 == (uint *)0x0) || (*local_20 == 0)) {
LAB_0060c1c4:
    local_30 = local_30 + 1;
    bVar12 = local_30 < local_34;
    goto LAB_0060c1cb;
  }
  pvVar4 = _malloc(0x38);
  if (pvVar4 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    local_24 = FUN_005f7709();
  }
  if (local_24 != 0) {
    local_c = FUN_005f799b();
    puVar10 = local_20;
    if ((int)local_c < 0) goto LAB_0060c1e5;
    local_10 = *(uint *)(param_1 + 0x138);
    if (local_10 < 0x200) {
      if (((*local_20 & 0xff000000) == 0x30000000) && (local_20[3] == 1)) {
        local_2c = *(int *)(*(int *)(param_1 + 0x14) + *(int *)local_20[4] * 4);
        if (*(int *)(local_2c + 0xc) != 3) goto LAB_0060bd47;
        iVar5 = *(int *)(param_1 + 0x144);
        FUN_00607a58(iVar5,local_30,local_34,(int *)local_20[4],1,&local_28,&local_3c,local_64 + 8);
        if (local_64[8] != 0) {
          iVar5 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),0,3,0);
          if (iVar5 == -1) goto LAB_0060c251;
          puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x14) + iVar5 * 4);
          FUN_005f7c63();
          uVar2 = *(undefined4 *)(param_1 + 0x60);
          puVar1[8] = 0;
          *puVar1 = uVar2;
          puVar1[3] = 3;
          pvVar4 = _malloc(0x38);
          if (pvVar4 == (void *)0x0) {
            iVar6 = 0;
          }
          else {
            iVar6 = FUN_005f7709();
          }
          if (iVar6 != 0) {
            local_c = FUN_005f7760(0x10000001,1,1,0);
            if (((int)local_c < 0) || (local_c = FUN_005f7a42(), (int)local_c < 0))
            goto LAB_0060c1de;
            **(undefined4 **)(iVar6 + 0x10) = *(undefined4 *)local_20[4];
            **(int **)(iVar6 + 8) = iVar5;
            **(int **)(local_24 + 0x10) = iVar5;
            *(int *)(*(int *)(param_1 + 0x144) + *(int *)(param_1 + 0x138) * 4) = local_24;
            *(int *)(param_1 + 0x138) = *(int *)(param_1 + 0x138) + 1;
            local_2c = local_24;
            if (*(uint *)(param_1 + 0x138) < 0x200) {
              *(int *)(*(int *)(param_1 + 0x144) + *(uint *)(param_1 + 0x138) * 4) = iVar6;
              puVar10 = local_20;
              goto LAB_0060bd56;
            }
          }
          goto LAB_0060c251;
        }
        *(int *)(iVar5 + local_10 * 4) = local_24;
        local_2c = local_24;
      }
      else {
LAB_0060bd47:
        *(int *)(*(int *)(param_1 + 0x144) + local_10 * 4) = local_24;
        local_2c = local_24;
      }
LAB_0060bd56:
      *(int *)(param_1 + 0x138) = *(int *)(param_1 + 0x138) + 1;
      local_24 = 0;
      iVar5 = FUN_00604f3b();
      if (iVar5 != 0) {
        local_28 = 0;
        local_64[4] = 0xffffffff;
        local_64[5] = 0xffffffff;
        local_64[6] = 0xffffffff;
        local_64[7] = 0xffffffff;
        if (puVar10[3] != 0) {
          local_10 = puVar10[3];
          iVar5 = *(int *)(param_1 + 0x14);
          piVar9 = (int *)puVar10[4];
          do {
            iVar6 = *(int *)(iVar5 + *piVar9 * 4);
            if (*(int *)(iVar6 + 0x1c) != 0) {
              local_64[*(int *)(iVar6 + 0xc) + 4] = *piVar9;
              local_28 = 1;
            }
            piVar9 = piVar9 + 1;
            local_10 = local_10 - 1;
          } while (local_10 != 0);
        }
        uVar8 = 0;
        local_18 = 0;
        FUN_0060783e(*(undefined4 *)(param_1 + 0x144),local_30,local_34,puVar10[4],puVar10[3],
                     local_e4,&local_18);
        if (local_28 == 0) {
          if (local_18 != 0) {
            do {
              iVar5 = *(int *)(*(int *)(param_1 + 0x14) + local_e4[uVar8] * 4);
              if (*(int *)(iVar5 + 0x24) != -1) {
                iVar5 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar5 + 0x24) * 4);
              }
              uVar8 = uVar8 + 1;
              *(undefined4 *)(iVar5 + 0x1c) = 1;
            } while (uVar8 < local_18);
          }
        }
        else {
          local_8 = 0;
          local_64[0] = -1;
          local_64[1] = 0xffffffff;
          local_64[2] = 0xffffffff;
          local_64[3] = 0xffffffff;
          if (local_18 != 0) {
            do {
              iVar5 = *(int *)(*(int *)(param_1 + 0x14) + local_e4[local_8] * 4);
              iVar6 = *(int *)(iVar5 + 0x24);
              iVar7 = local_e4[local_8];
              if (iVar6 != -1) {
                iVar5 = *(int *)(*(int *)(param_1 + 0x14) + iVar6 * 4);
                iVar7 = iVar6;
              }
              uVar8 = *(uint *)(iVar5 + 0x2c);
              if ((((local_34 <= uVar8) || (uVar8 < local_30)) && (uVar8 != 0xffffffff)) &&
                 (iVar6 = FUN_00604f3b(), iVar6 != 0)) {
                iVar6 = local_64[*(int *)(iVar5 + 0xc)];
                if (iVar6 == -1) {
                  local_64[*(int *)(iVar5 + 0xc)] = iVar7;
                }
                else if (iVar6 != iVar7) goto LAB_0060c202;
              }
              local_8 = local_8 + 1;
            } while (local_8 < local_18);
          }
          uVar11 = 0;
          uVar8 = 0;
          local_18 = 0;
          do {
            if (*(int *)((int)local_64 + uVar8) == -1) {
LAB_0060be79:
              if (*(int *)((int)local_64 + uVar8 + 0x10) != -1) goto LAB_0060be7f;
            }
            else {
              if (*(int *)((int)local_64 + uVar8 + 0x10) != -1) {
LAB_0060c202:
                FUN_005fbec8(param_1,local_20[0xd],0x11b9,
                             "unable to emmulate write masks for ps_1_%i shader model",
                             *(uint *)(param_1 + 0x30) & 0xff);
                return 0x80004005;
              }
              if (*(int *)((int)local_64 + uVar8) == -1) goto LAB_0060be79;
LAB_0060be7f:
              uVar11 = uVar11 + 1;
              local_18 = uVar11;
            }
            uVar8 = uVar8 + 4;
          } while (uVar8 < 0x10);
          pvVar4 = _malloc(0x38);
          if (pvVar4 == (void *)0x0) {
            local_1c = 0;
          }
          else {
            local_1c = FUN_005f7709();
          }
          if (local_1c == 0) {
            return 0x8007000e;
          }
          local_c = FUN_005f7760(uVar11 & 0xffffff | 0xf1000000,uVar11 * 3,uVar11,0);
          if ((int)local_c < 0) goto LAB_0060c1d7;
          local_c = FUN_005f7a42();
          if ((int)local_c < 0) goto LAB_0060c1d7;
          local_14 = 0;
          local_10 = 0;
          local_8 = local_18 << 2;
          do {
            iVar5 = *(int *)((int)local_64 + local_10 + 0x10);
            if (iVar5 == -1) {
              local_3c = *(int *)((int)local_64 + local_10);
              if (local_3c != -1) {
                iVar7 = local_14 * 4;
                *(int *)(iVar7 + *(int *)(local_1c + 0x10)) = local_3c;
                iVar5 = *(int *)(*(int *)(param_1 + 0x14) + local_3c * 4);
                iVar6 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),0,*(undefined4 *)(iVar5 + 0xc),
                                     0);
                if (iVar6 == -1) goto LAB_0060c251;
                *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + iVar6 * 4) + 0x20) =
                     *(undefined4 *)(iVar5 + 0x20);
                iVar3 = *(int *)(iVar5 + 0x2c);
                *(undefined4 *)(iVar5 + 0x20) = 0;
                if ((iVar3 != -1) && (iVar3 != *(int *)(param_1 + 0x138))) {
                  iVar3 = *(int *)(*(int *)(param_1 + 0x144) + iVar3 * 4);
                  local_28 = 0;
                  if (*(int *)(iVar3 + 0xc) != 0) {
                    do {
                      piVar9 = (int *)(*(int *)(iVar3 + 0x10) + local_28 * 4);
                      if (*piVar9 == local_3c) {
                        *piVar9 = iVar6;
                      }
                      local_28 = local_28 + 1;
                    } while (local_28 < *(uint *)(iVar3 + 0xc));
                  }
                  *(undefined4 *)(iVar5 + 0x2c) = *(undefined4 *)(param_1 + 0x138);
                  *(undefined4 *)(iVar7 + *(int *)(local_1c + 8)) = *(undefined4 *)(param_1 + 0x1fc)
                  ;
                  local_38 = iVar6;
                  *(int *)(*(int *)(local_1c + 8) + (local_14 + local_18 * 2) * 4) = iVar6;
                  goto LAB_0060c05f;
                }
                FUN_005fbec8(param_1,local_20[0xd],0x12ca,"internal error: illformed write field");
                goto LAB_0060c1d7;
              }
            }
            else {
              *(int *)(*(int *)(local_1c + 0x10) + local_14 * 4) = iVar5;
              iVar6 = *(int *)(*(int *)(param_1 + 0x14) + iVar5 * 4);
              iVar7 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),0,*(undefined4 *)(iVar6 + 0xc),0)
              ;
              if (iVar7 == -1) goto LAB_0060c251;
              *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + iVar7 * 4) + 0x20) =
                   *(undefined4 *)(iVar6 + 0x20);
              *(undefined4 *)(iVar6 + 0x20) = 0;
              *(undefined4 *)(iVar6 + 0x2c) = *(undefined4 *)(param_1 + 0x138);
              uVar8 = 0;
              if (*(int *)(local_2c + 0xc) != 0) {
                do {
                  piVar9 = (int *)(*(int *)(local_2c + 0x10) + uVar8 * 4);
                  if (*piVar9 == iVar5) {
                    *piVar9 = iVar7;
                  }
                  uVar8 = uVar8 + 1;
                } while (uVar8 < *(uint *)(local_2c + 0xc));
              }
              *(undefined4 *)(*(int *)(local_1c + 8) + local_14 * 4) =
                   *(undefined4 *)(param_1 + 0x200);
              local_40 = iVar7;
              *(int *)(local_8 + *(int *)(local_1c + 8)) = iVar7;
LAB_0060c05f:
              local_14 = local_14 + 1;
              local_8 = local_8 + 4;
            }
            iVar5 = local_1c;
            local_10 = local_10 + 4;
          } while (local_10 < 0x10);
          local_14 = 0;
          local_c = 0;
          local_8 = local_18 << 2;
          do {
            iVar6 = *(int *)((int)local_64 + local_c + 0x10);
            if (iVar6 == -1) {
              if (*(int *)((int)local_64 + local_c) != -1) {
                iVar6 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)((int)local_64 + local_c) * 4);
                iVar7 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),0,*(undefined4 *)(iVar6 + 0xc),
                                     0);
                if (iVar7 != -1) {
                  iVar3 = *(int *)(*(int *)(param_1 + 0x14) + iVar7 * 4);
                  *(int *)(iVar3 + 0x24) = local_40;
                  *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar6 + 0x20);
                  *(int *)(local_8 + *(int *)(iVar5 + 8)) = iVar7;
                  goto LAB_0060c128;
                }
                goto LAB_0060c251;
              }
            }
            else {
              iVar6 = *(int *)(*(int *)(param_1 + 0x14) + iVar6 * 4);
              iVar7 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),0,*(undefined4 *)(iVar6 + 0xc),0)
              ;
              if (iVar7 == -1) goto LAB_0060c251;
              iVar3 = *(int *)(*(int *)(param_1 + 0x14) + iVar7 * 4);
              *(int *)(iVar3 + 0x24) = local_38;
              *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar6 + 0x20);
              *(int *)(*(int *)(iVar5 + 8) + (local_14 + local_18 * 2) * 4) = iVar7;
LAB_0060c128:
              local_14 = local_14 + 1;
              local_8 = local_8 + 4;
            }
            local_c = local_c + 4;
          } while (local_c < 0x10);
          if (0x1ff < *(uint *)(param_1 + 0x138)) goto LAB_0060c251;
          *(int *)(*(int *)(param_1 + 0x144) + *(uint *)(param_1 + 0x138) * 4) = iVar5;
          *(int *)(param_1 + 0x138) = *(int *)(param_1 + 0x138) + 1;
          local_1c = 0;
          puVar10 = local_20;
        }
      }
      local_10 = 0;
      if (*(int *)(local_2c + 0xc) != 0) {
        do {
          iVar5 = local_10 * 4;
          local_10 = local_10 + 1;
          *(int *)(*(int *)(*(int *)(param_1 + 0x14) +
                           *(int *)(*(int *)(local_2c + 0x10) + iVar5) * 4) + 0x2c) =
               *(int *)(param_1 + 0x138) + -1;
        } while (local_10 < *(uint *)(local_2c + 0xc));
      }
      *puVar10 = 0;
      goto LAB_0060c1c4;
    }
  }
LAB_0060c251:
  local_c = 0x8007000e;
  goto LAB_0060c1d7;
}


// ==== 0x60c25d FUN_0060c25d

int __fastcall FUN_0060c25d(int param_1)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int local_30 [11];
  
  local_30[8] = 0;
  if (*(int *)(param_1 + 0x88) == 4) {
    local_30[4] = 0;
    local_30[5] = 0;
    local_30[6] = 0;
    local_30[7] = 0;
    local_30[0] = 0;
    local_30[1] = 0;
    local_30[2] = 0;
    local_30[10] = 0;
    local_30[3] = 0;
    local_30[9] = 0;
    do {
      iVar3 = local_30[10];
      piVar1 = (int *)(*(int *)(param_1 + 0x144) + local_30[9] * 4);
      puVar2 = (uint *)*piVar1;
      if ((puVar2 != (uint *)0x0) && (uVar5 = *puVar2, uVar5 != 0)) {
        if ((uVar5 & 0xff000000) == 0xe1000000) {
LAB_0060c2f1:
          local_30[local_30[9] + 4] = (int)puVar2;
        }
        else {
          uVar4 = 0;
          if ((uVar5 & 0xff000000) != 0x34000000) {
            uVar4 = uVar5 & 0xffffff;
          }
          if (**(int **)(*(int *)(param_1 + 0x14) + *(int *)(puVar2[2] + uVar4 * 4) * 4) !=
              *(int *)(param_1 + 0x60)) goto LAB_0060c2f1;
          local_30[10] = local_30[10] + 1;
          local_30[iVar3] = (int)puVar2;
        }
        *piVar1 = 0;
      }
      local_30[9] = local_30[9] + 1;
    } while ((uint)local_30[9] < *(uint *)(param_1 + 0x88));
    uVar5 = 0;
    if (*(int *)(param_1 + 0x88) != 0) {
      do {
        piVar1 = (int *)(*(int *)(param_1 + 0x140) + uVar5 * 4);
        puVar2 = (uint *)*piVar1;
        if (((puVar2 != (uint *)0x0) && (*puVar2 != 0)) && ((*puVar2 & 0xff000000) != 0xe1000000)) {
          if (local_30[uVar5 + 4] != 0) {
            iVar3 = -0x7fffbffb;
            goto LAB_0060c4a0;
          }
          *piVar1 = 0;
          local_30[uVar5 + 4] = (int)puVar2;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(param_1 + 0x88));
    }
    if ((((*(uint *)(param_1 + 0x30) & 0xffff) < 0x102) ||
        (iVar3 = FUN_0060a0f3(local_30,local_30[10],local_30 + 4,1), -1 < iVar3)) &&
       ((iVar3 = FUN_0060a0f3(local_30,local_30[10],local_30 + 4,2), -1 < iVar3 &&
        ((iVar3 = FUN_0060a0f3(local_30,local_30[10],local_30 + 4,3), -1 < iVar3 &&
         (iVar3 = FUN_00609c31(local_30,local_30[10],local_30 + 4), -1 < iVar3)))))) {
      local_30[10] = 0;
      if (*(int *)(param_1 + 0x88) != 0) {
        do {
          if (local_30[local_30[10]] != 0) {
            iVar3 = -0x7fffbffb;
            FUN_005fbec8(param_1,*(undefined4 *)(local_30[local_30[10]] + 0x34),0x11ab,
                         "cannot map this dependent texture read to ps_1_%i",
                         *(uint *)(param_1 + 0x30) & 0xff);
            local_30[8] = 1;
          }
          local_30[10] = local_30[10] + 1;
        } while ((uint)local_30[10] < *(uint *)(param_1 + 0x88));
      }
      if (iVar3 != -0x7fffbffb) {
        uVar5 = 0;
        if (*(int *)(param_1 + 0x88) != 0) {
          do {
            if (*(int *)(*(int *)(param_1 + 0x144) + uVar5 * 4) != 0) {
              FUN_005f7186(1);
            }
            *(int *)(*(int *)(param_1 + 0x144) + uVar5 * 4) = local_30[uVar5 + 4];
            uVar5 = uVar5 + 1;
          } while (uVar5 < *(uint *)(param_1 + 0x88));
        }
        uVar5 = 0;
        if (*(int *)(param_1 + 0x134) != 0) {
          do {
            if (*(int *)(*(int *)(param_1 + 0x140) + uVar5 * 4) != 0) {
              FUN_005f7186(1);
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < *(uint *)(param_1 + 0x134));
        }
        _free(*(void **)(param_1 + 0x140));
        iVar3 = 0;
        *(undefined4 *)(param_1 + 0x140) = 0;
        *(undefined4 *)(param_1 + 0x134) = 0;
      }
      if (-1 < iVar3) {
        return iVar3;
      }
    }
LAB_0060c4a0:
    uVar5 = 0;
    if (*(int *)(param_1 + 0x88) != 0) {
      do {
        if (local_30[uVar5 + 4] != 0) {
          FUN_005f7186(1);
        }
        if (local_30[uVar5] != 0) {
          FUN_005f7186(1);
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(param_1 + 0x88));
    }
    if (local_30[8] == 0) {
      FUN_005fbec8(param_1,0,0x11ab,
                   "shader cannot compile to a ps_1_%i shader because this model can\'t match all the dependent texture read(s) this shader requires"
                   ,*(uint *)(param_1 + 0x30) & 0xff);
    }
  }
  else {
    iVar3 = -0x7fffbffb;
  }
  return iVar3;
}


// ==== 0x60c503 FUN_0060c503

int __thiscall FUN_0060c503(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  bool bVar7;
  undefined4 uVar8;
  uint local_10;
  uint local_c;
  int local_8;
  
  local_10 = 0;
  if (param_3 != 0) {
    do {
      *(uint *)(param_1 + 0x94) = local_10;
      iVar1 = *(int *)(param_2 + local_10 * 4);
      *(int *)(param_1 + 0x98) = iVar1;
      if (iVar1 != 0) {
        iVar1 = *(int *)(iVar1 + 0x34);
        if ((iVar1 != 0) && (*(int *)(iVar1 + 4) == 0xc)) {
          *(int *)(param_1 + 0x9c) = iVar1 + 0x30;
        }
        puVar2 = *(uint **)(param_1 + 0x98);
        if (*puVar2 != 0) {
          iVar1 = *(int *)(param_1 + 0x14);
          piVar3 = *(int **)(iVar1 + *(int *)puVar2[2] * 4);
          if (piVar3[1] != -1) {
            FUN_005fbec8(param_1,*(undefined4 *)(*(int *)(param_1 + 0x98) + 0x34),0x119f,
                         "relative addressing not allowed for pixel shaders");
            return -0x7fffbffb;
          }
          uVar6 = *puVar2 & 0xff000000;
          if (uVar6 < 0xe2000001) {
            if (uVar6 == 0xe2000000) {
              uVar8 = 0x47;
              goto LAB_0060c7c3;
            }
            if (uVar6 < 0x34000001) {
              if (uVar6 == 0x34000000) {
                local_8 = FUN_0061a7fa();
              }
              else {
                if (uVar6 == 0) {
                  local_8 = 0;
                  goto LAB_0060c7db;
                }
                if (uVar6 == 0x10000000) {
                  local_8 = FUN_0061b0f2();
                }
                else if (uVar6 == 0x11000000) {
                  local_8 = FUN_0061a926();
                }
                else if (uVar6 == 0x24000000) {
                  local_8 = FUN_0061b2e2();
                }
                else if (uVar6 == 0x25000000) {
                  local_8 = FUN_0061b2ea();
                }
                else {
                  if (uVar6 != 0x30000000) goto LAB_0060c817;
                  local_c = *puVar2 & 0xffffff;
                  if ((local_c == 4) && ((*(uint *)(param_1 + 0x30) & 0xffff) == 0x101)) {
LAB_0060c662:
                    FUN_0060a8f2();
                  }
                  else {
                    uVar6 = *(uint *)(param_1 + 0x30) & 0xffff;
                    if (((uVar6 == 0x102) || (uVar6 == 0x103)) && (local_c == 4)) {
                      piVar4 = *(int **)(iVar1 + *(int *)puVar2[4] * 4);
                      piVar5 = *(int **)(iVar1 + ((int *)puVar2[2])[4] * 4);
                      iVar1 = *piVar4;
                      if (iVar1 == *(int *)(param_1 + 0x5c)) {
                        if (((*piVar3 == *(int *)(param_1 + 0x60)) && (piVar3[2] == 0)) ||
                           ((*piVar5 == *(int *)(param_1 + 0x60) && (piVar5[2] == 0)))) {
                          bVar7 = (piVar4[0x14] & 0xffU) == 1;
LAB_0060c660:
                          if (bVar7) goto LAB_0060c662;
                        }
                      }
                      else {
                        if ((*piVar3 == iVar1) && (piVar3[2] == piVar4[2])) goto LAB_0060c662;
                        if (*piVar5 == iVar1) {
                          bVar7 = piVar5[2] == piVar4[2];
                          goto LAB_0060c660;
                        }
                      }
                    }
                    local_8 = FUN_0061b2fa();
                  }
                }
              }
            }
            else if ((((uVar6 == 0x40000000) || (uVar6 == 0x44000000)) || (uVar6 == 0x48000000)) ||
                    (uVar6 == 0x4c000000)) {
              local_8 = FUN_0060ab02();
            }
            else if (uVar6 == 0x50000000) {
              if ((*(uint *)(param_1 + 0x30) & 0xffff) == 0x104) {
                local_8 = FUN_0061b3a4();
              }
              else {
                local_8 = -0x7fffbfff;
              }
            }
            else {
              if (uVar6 != 0xe1000000) goto LAB_0060c817;
              local_8 = FUN_0060ac1e();
            }
          }
          else {
            if (uVar6 < 0xe9000001) {
              if (uVar6 == 0xe9000000) {
                uVar8 = 0x4d;
              }
              else if (uVar6 == 0xe3000000) {
                uVar8 = 0x48;
              }
              else if (uVar6 == 0xe4000000) {
                uVar8 = 0x49;
              }
              else if (uVar6 == 0xe5000000) {
                uVar8 = 0x4a;
              }
              else if (uVar6 == 0xe6000000) {
                uVar8 = 0x52;
              }
              else if (uVar6 == 0xe7000000) {
                uVar8 = 0x45;
              }
              else {
                if (uVar6 != 0xe8000000) goto LAB_0060c817;
                uVar8 = 0x46;
              }
            }
            else if (uVar6 == 0xea000000) {
              uVar8 = 0x4c;
            }
            else {
              if (uVar6 != 0xeb000000) {
                if (uVar6 == 0xf1000000) {
                  local_8 = FUN_0061aa11();
                }
                else {
                  if ((uVar6 != 0xf5000000) && (uVar6 != 0xf6000000)) goto LAB_0060c817;
                  local_8 = FUN_0061abc1();
                }
                goto LAB_0060c7cd;
              }
              uVar8 = 0x53;
            }
LAB_0060c7c3:
            local_8 = FUN_0060a9c6(uVar8);
          }
LAB_0060c7cd:
          if (local_8 == -0x7fffbfff) {
LAB_0060c817:
            FUN_005fbec8(param_1,*(undefined4 *)(*(int *)(param_1 + 0x98) + 0x34),0x11b4,
                         "cannot map expression to pixel shader instruction set");
            return -0x7fffbfff;
          }
          if (local_8 < 0) {
            return local_8;
          }
        }
      }
LAB_0060c7db:
      local_10 = local_10 + 1;
    } while (local_10 < param_3);
  }
  return 0;
}


// ==== 0x60c83a FUN_0060c83a

int __fastcall FUN_0060c83a(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x140) != 0) {
    if ((*(uint *)(param_1 + 0x30) & 0xffff) != 0x104) {
      return -0x7fffbffb;
    }
    FUN_0060c503(*(int *)(param_1 + 0x140),*(undefined4 *)(param_1 + 0x134));
    iVar1 = FUN_0061a26f(0xfffd);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_0061663f();
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  iVar1 = FUN_0060c503(*(undefined4 *)(param_1 + 0x144),*(undefined4 *)(param_1 + 0x138));
  return iVar1;
}


// ==== 0x60c89d FUN_0060c89d

void * __thiscall FUN_0060c89d(void *param_1,byte param_2)

{
  FUN_0060ba7c();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x60c8b9 FUN_0060c8b9

int __fastcall FUN_0060c8b9(int param_1)

{
  int *piVar1;
  uint *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar3 = FUN_005f7478(&DAT_0069ecd8,0x189,1,4);
  uVar4 = FUN_005f74cf(uVar3,0,0,0);
  *(undefined4 *)(param_1 + 0x1fc) = uVar4;
  uVar3 = FUN_005f74cf(uVar3,0,1,0x3ff0000000000000);
  uVar6 = 0;
  *(undefined4 *)(param_1 + 0x200) = uVar3;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + uVar6 * 4) + 0x24) = 0xffffffff;
      piVar1 = *(int **)(*(int *)(param_1 + 0x14) + uVar6 * 4);
      if (*piVar1 == *(int *)(param_1 + 0x58)) {
        if ((char)piVar1[0x14] == '\x01') {
          piVar1[6] = 0x14;
        }
        if (((*(uint *)(param_1 + 0x30) & 0xffff) < 0x104) &&
           (iVar5 = *(int *)(*(int *)(param_1 + 0x14) + uVar6 * 4),
           *(char *)(iVar5 + 0x50) == '\x03')) {
          *(undefined4 *)(iVar5 + 0x18) = 0x14;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_1 + 8));
  }
  uVar6 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar6;
      puVar2 = *(uint **)(*(int *)(param_1 + 0x18) + uVar6 * 4);
      *(uint **)(param_1 + 0x98) = puVar2;
      uVar7 = *puVar2 & 0xff000000;
      if (((((uVar7 == 0x40000000) || (uVar7 == 0x44000000)) || (uVar7 == 0x48000000)) ||
          (uVar7 == 0x4c000000)) && (uVar7 = 0, puVar2[3] != 0)) {
        do {
          *(undefined4 *)
           (*(int *)(*(int *)(param_1 + 0x14) +
                    *(int *)(*(int *)(*(int *)(param_1 + 0x98) + 0x10) + uVar7 * 4) * 4) + 0x18) =
               0x14;
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(uint *)(*(int *)(param_1 + 0x98) + 0xc));
      }
      uVar6 = uVar6 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x24) = 0;
    } while (uVar6 < *(uint *)(param_1 + 0xc));
  }
  uVar6 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar6;
      puVar2 = *(uint **)(*(int *)(param_1 + 0x18) + uVar6 * 4);
      *(uint **)(param_1 + 0x98) = puVar2;
      uVar7 = *puVar2 & 0xff000000;
      if ((uVar7 == 0x20000000) || (uVar7 == 0x21000000)) {
LAB_0060ca09:
        iVar5 = FUN_006169a4();
LAB_0060ca10:
        if (iVar5 < 0) {
          return iVar5;
        }
      }
      else {
        if (uVar7 == 0x34000000) {
          iVar5 = FUN_00604486();
          goto LAB_0060ca10;
        }
        if (uVar7 == 0x50000000) goto LAB_0060ca09;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_1 + 0xc));
  }
  uVar6 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar6;
      puVar2 = *(uint **)(*(int *)(param_1 + 0x18) + uVar6 * 4);
      *(uint **)(param_1 + 0x98) = puVar2;
      uVar7 = *puVar2 & 0xff000000;
      if (uVar7 == 0x10000000) {
        iVar5 = FUN_006046ad();
LAB_0060ca64:
        if (iVar5 < 0) {
          return iVar5;
        }
      }
      else if (uVar7 == 0x11000000) {
        iVar5 = FUN_006047ce();
        goto LAB_0060ca64;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_1 + 0xc));
  }
  FUN_0061674c();
  uVar6 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar6;
      puVar2 = *(uint **)(*(int *)(param_1 + 0x18) + uVar6 * 4);
      *(uint **)(param_1 + 0x98) = puVar2;
      uVar7 = *puVar2 & 0xff000000;
      if (uVar7 == 0x11000000) {
        FUN_006178e1();
LAB_0060cae8:
        iVar5 = FUN_0061820d();
LAB_0060caef:
        if (iVar5 < 0) {
          return iVar5;
        }
      }
      else {
        if (uVar7 == 0x24000000) {
          FUN_006182a2();
          FUN_00617c5c();
          FUN_0061808b();
          iVar5 = FUN_00617f3a();
          goto LAB_0060caef;
        }
        if (uVar7 == 0x25000000) {
          FUN_00617f3a();
          goto LAB_0060cae8;
        }
        if (uVar7 == 0x30000000) {
          iVar5 = FUN_00614682();
          goto LAB_0060caef;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_1 + 0xc));
  }
  FUN_0061674c();
  uVar6 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar6;
      puVar2 = *(uint **)(*(int *)(param_1 + 0x18) + uVar6 * 4);
      *(uint **)(param_1 + 0x98) = puVar2;
      uVar7 = *puVar2 & 0xff000000;
      if (((uVar7 == 0x24000000) || (uVar7 == 0x25000000)) && (iVar5 = FUN_00606110(), iVar5 < 0)) {
        return iVar5;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_1 + 0xc));
  }
  FUN_0061674c();
  uVar6 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar6;
      puVar2 = *(uint **)(*(int *)(param_1 + 0x18) + uVar6 * 4);
      *(uint **)(param_1 + 0x98) = puVar2;
      if ((*puVar2 & 0xff000000) == 0x4c000000) {
        iVar5 = FUN_006058f6();
        if (iVar5 < 0) {
          return iVar5;
        }
        iVar5 = FUN_006058f6();
        if (iVar5 < 0) {
          return iVar5;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_1 + 0xc));
  }
  FUN_0061674c();
  uVar6 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar6;
      puVar2 = *(uint **)(*(int *)(param_1 + 0x18) + uVar6 * 4);
      *(uint **)(param_1 + 0x98) = puVar2;
      uVar7 = *puVar2 & 0xff000000;
      if (uVar7 == 0x16000000) {
        iVar5 = FUN_00618431();
LAB_0060cbf1:
        if (iVar5 < 0) {
          return iVar5;
        }
      }
      else {
        if (uVar7 == 0x24000000) {
          FUN_00618709();
          iVar5 = FUN_00605ecb();
          goto LAB_0060cbf1;
        }
        if (uVar7 == 0x25000000) {
          iVar5 = FUN_00618a35();
          goto LAB_0060cbf1;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_1 + 0xc));
  }
  FUN_0061674c();
  uVar6 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar6;
      puVar2 = *(uint **)(*(int *)(param_1 + 0x18) + uVar6 * 4);
      *(uint **)(param_1 + 0x98) = puVar2;
      if (((*puVar2 & 0xff000000) == 0xf5000000) && (iVar5 = FUN_0061858f(), iVar5 < 0)) {
        return iVar5;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_1 + 0xc));
  }
  uVar6 = *(uint *)(param_1 + 0xc);
  uVar7 = 0;
  if (uVar6 != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar7;
      *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(*(int *)(param_1 + 0x18) + uVar7 * 4);
      iVar5 = FUN_0060534a();
      if (iVar5 < 0) {
        return iVar5;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar6);
  }
  iVar5 = FUN_00605d41();
  if (((((-1 < iVar5) && (iVar5 = FUN_00604d8e(), -1 < iVar5)) &&
       (iVar5 = FUN_0060728d(), -1 < iVar5)) &&
      ((*(int *)(param_1 + 0x140) == 0 ||
       ((iVar5 = FUN_00604be6(), -1 < iVar5 &&
        (((*(int *)(param_1 + 0x140) == 0 || ((*(uint *)(param_1 + 0x30) & 0xffff) == 0x104)) ||
         (iVar5 = FUN_0060c25d(), -1 < iVar5)))))))) &&
     (((((*(int *)(param_1 + 0x144) == 0 || ((*(uint *)(param_1 + 0x30) & 0xffff) == 0x104)) ||
        ((iVar5 = FUN_00604fb1(), -1 < iVar5 && (iVar5 = FUN_0060bafa(), -1 < iVar5)))) &&
       ((((iVar5 = FUN_00608771(), -1 < iVar5 && (iVar5 = FUN_00607bc1(), -1 < iVar5)) &&
         (iVar5 = FUN_0060b4e1(*(undefined4 *)(param_1 + 0x144),0,*(undefined4 *)(param_1 + 0x138)),
         -1 < iVar5)) && (iVar5 = FUN_006049c5(), -1 < iVar5)))) &&
      (((*(int *)(param_1 + 0x144) == 0 || ((*(uint *)(param_1 + 0x30) & 0xffff) == 0x104)) ||
       (iVar5 = FUN_006043ad(), -1 < iVar5)))))) {
    iVar5 = 0;
  }
  return iVar5;
}


// ==== 0x60cd67 FUN_0060cd67

undefined4 * __fastcall FUN_0060cd67(undefined4 *param_1)

{
  FUN_006137a9();
  param_1[0x4f] = 0;
  *param_1 = &PTR_FUN_006a5ba8;
  return param_1;
}


// ==== 0x60cd80 FUN_0060cd80

void __fastcall FUN_0060cd80(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x10c);
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  FUN_00619954();
  return;
}


// ==== 0x60cda0 FUN_0060cda0

undefined4 __fastcall FUN_0060cda0(int param_1)

{
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 2;
  *(undefined4 *)(param_1 + 0x70) = 0xc;
  *(undefined4 *)(param_1 + 0x78) = 0x2000;
  *(undefined4 *)(param_1 + 0x80) = 10;
  *(undefined4 *)(param_1 + 0x84) = 4;
  *(undefined4 *)(param_1 + 0x88) = 0x10;
  *(uint *)(param_1 + 0x90) = *(uint *)(param_1 + 0x90) & 0xfa9fffe3 | 0x21000a3;
  return 0;
}


// ==== 0x60cdf7 FUN_0060cdf7

undefined4 __thiscall FUN_0060cdf7(int param_1,int *param_2,uint param_3,uint *param_4)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint local_8;
  
  uVar4 = 0;
  local_8 = 0;
  if ((param_3 == 0) ||
     (**(int **)(*(int *)(param_1 + 0x14) + *param_2 * 4) != *(int *)(param_1 + 0x5c))) {
    if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x14) + *param_2 * 4) + 0x21) & 2) != 0) {
      local_8 = 0x100000;
    }
    if (param_3 != 0) {
      do {
        iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x14) + param_2[uVar4] * 4) + 0xc);
        uVar3 = 0;
        if (iVar1 == 0) {
          uVar3 = 0x10000;
        }
        else if (iVar1 == 1) {
          uVar3 = 0x20000;
        }
        else if (iVar1 == 2) {
          uVar3 = 0x40000;
        }
        else if (iVar1 == 3) {
          uVar3 = 0x80000;
        }
        if ((local_8 & uVar3) != 0) {
          FUN_005fbec8(param_1,*(undefined4 *)(*(int *)(param_1 + 0x98) + 0x34),0x12d5,
                       "internal error: overlapping output writes");
        }
        local_8 = local_8 | uVar3;
        uVar4 = uVar4 + 1;
      } while (uVar4 < param_3);
    }
  }
  else {
    local_8 = 0xf0000;
  }
  uVar4 = 0;
  bVar5 = param_3 == 0;
  if (param_3 != 0) {
    do {
      piVar2 = *(int **)(*(int *)(param_1 + 0x14) + param_2[uVar4] * 4);
      if (((*(byte *)((int)piVar2 + 0x1b) & 2) == 0) &&
         ((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4) + 4) & 1) == 0 ||
           (piVar2[0xb] == -1)) || (piVar2[0xe] != -1)))) break;
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_3);
    bVar5 = uVar4 == param_3;
  }
  if (bVar5) {
    local_8 = local_8 | 0x200000;
  }
  if ((((*(byte *)(param_1 + 0x34) & 1) != 0) && (uVar4 = 0, *(int *)(param_1 + 0xb8) != 0)) &&
     (param_3 != 0)) {
    do {
      piVar2 = param_2 + uVar4;
      iVar1 = uVar4 + *(int *)(param_1 + 0xbc) * 6;
      uVar4 = uVar4 + 1;
      *(int *)(*(int *)(param_1 + 0xb8) + -0x10 + iVar1 * 4) = *piVar2;
    } while (uVar4 < param_3);
  }
  *param_4 = local_8;
  return 0;
}


// ==== 0x60cf25 FUN_0060cf25

uint __fastcall FUN_0060cf25(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int local_60 [16];
  int local_20 [7];
  
  piVar2 = local_60;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
  }
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  puVar8 = (undefined4 *)(param_1 + 0x10c);
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  uVar7 = 0;
  local_20[6] = 0;
  local_20[5] = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      piVar2 = *(int **)(*(int *)(param_1 + 0x14) + uVar7 * 4);
      uVar6 = *(uint *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4) + 4);
      if ((uVar6 & 0x10) == 0) {
        if (((uVar6 & 8) != 0) && ((uVar6 & 0x100) == 0)) {
          uVar6 = (uint)*(byte *)((int)piVar2 + 0x51);
          if ((piVar2[0x14] & 0xffU) == 1) {
            if (uVar6 < 2) {
              puVar4 = (uint *)(param_1 + 300 + uVar6 * 4);
              goto LAB_0060d021;
            }
          }
          else if (((piVar2[0x14] & 0xffU) == 3) && (uVar6 < 8)) {
            puVar4 = (uint *)(param_1 + 0x10c + uVar6 * 4);
LAB_0060d021:
            if (*puVar4 < piVar2[3] + 1U) {
              *puVar4 = piVar2[3] + 1U;
            }
          }
        }
      }
      else {
        uVar6 = (uint)*(byte *)((int)piVar2 + 0x51);
        if ((piVar2[0x14] & 0xffU) == 1) {
          if (uVar6 < 4) {
            iVar3 = piVar2[0x11];
            local_60[piVar2[3] + uVar6 * 4] = 1;
            local_20[uVar6] = iVar3;
          }
        }
        else if (((((piVar2[0x14] & 0xffU) == 2) && (uVar6 == 0)) && (piVar2[3] != 0)) &&
                (local_20[5] == 0)) {
          FUN_005fbec8(param_1,piVar2[0x11],0x11b0,"DEPTH must be a scalar");
          local_20[5] = 1;
          local_20[6] = 1;
        }
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(param_1 + 8));
  }
  local_20[5] = 0;
  local_20[4] = 1;
  uVar7 = 0;
  do {
    iVar5 = 0;
    piVar2 = local_60 + uVar7 * 4;
    iVar3 = 4;
    do {
      iVar1 = *piVar2;
      piVar2 = piVar2 + 1;
      iVar5 = iVar5 + (uint)(iVar1 != 0);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (iVar5 == 0) {
      if (uVar7 == 0) {
        FUN_005fbec8(param_1,local_20[0],0x11b2,
                     "pixel shader must minimally write all four components of COLOR0");
        local_20[6] = 1;
      }
      local_20[5] = 1;
    }
    else {
      if (iVar5 != 4) {
        FUN_005fbec8(param_1,local_20[uVar7],0x11b1,"COLOR%d must be a four-component vector",uVar7)
        ;
        local_20[6] = 1;
      }
      if (local_20[5] != 0) {
        local_20[4] = 0;
      }
    }
    uVar7 = uVar7 + 1;
  } while (uVar7 < 4);
  if (local_20[4] == 0) {
    FUN_005fbec8(param_1,0,0x11ba,"COLOR outputs must be contiguous from COLOR0 to COLORn");
    local_20[6] = 1;
  }
  return -(uint)(local_20[6] != 0) & 0x80004005;
}


// ==== 0x60d0f0 FUN_0060d0f0

void __fastcall FUN_0060d0f0(int *param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int local_50 [4];
  int local_40 [4];
  undefined4 local_30 [4];
  undefined4 local_20 [4];
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar1 = (uint *)param_1[0x26];
  local_c = puVar1[3];
  uVar2 = puVar1[2];
  local_10 = puVar1[4];
  uVar4 = *puVar1 & 0xffffff;
  iVar3 = (**(code **)(*param_1 + 0x6c))(param_1[0x25],local_30,4,0,0);
  if (-1 < iVar3) {
    local_8 = 0;
    do {
      local_40[local_8] = param_1[0x4d];
      local_50[local_8] = param_1[0x4e];
      if (local_8 < local_c) {
        local_20[local_8] =
             local_30[*(int *)(*(int *)(param_1[5] + *(int *)(local_8 * 4 + local_10) * 4) + 0xc)];
      }
      local_8 = local_8 + 1;
    } while (local_8 < 4);
    FUN_0061a3fb(2,local_20,local_c,uVar2,uVar2 + uVar4 * 4,0,uVar4,0,0x1000000,0);
    FUN_0061a3fb(0x58,local_10,local_c,local_20,local_50,local_40,uVar4,0,0,0);
  }
  return;
}


// ==== 0x60d1c2 FUN_0060d1c2

void __fastcall FUN_0060d1c2(int *param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int local_50 [4];
  int local_40 [4];
  undefined4 local_30 [4];
  undefined4 local_20 [4];
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar1 = (uint *)param_1[0x26];
  local_c = puVar1[3];
  uVar2 = puVar1[2];
  local_10 = puVar1[4];
  uVar4 = *puVar1 & 0xffffff;
  iVar3 = (**(code **)(*param_1 + 0x6c))(param_1[0x25],local_30,4,0,0);
  if (-1 < iVar3) {
    local_8 = 0;
    do {
      local_50[local_8] = param_1[0x4d];
      local_40[local_8] = param_1[0x4e];
      if (local_8 < local_c) {
        local_20[local_8] =
             local_30[*(int *)(*(int *)(param_1[5] + *(int *)(local_8 * 4 + local_10) * 4) + 0xc)];
      }
      local_8 = local_8 + 1;
    } while (local_8 < 4);
    FUN_0061a3fb(2,local_20,local_c,uVar2,uVar2 + uVar4 * 4,0,uVar4,0,0x1000000,0);
    FUN_0061a3fb(0x58,local_10,local_c,local_20,local_50,local_40,uVar4,0,0,0);
  }
  return;
}


// ==== 0x60d294 FUN_0060d294

void __fastcall FUN_0060d294(int *param_1)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int local_38 [4];
  int local_28 [4];
  int *local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  puVar1 = (uint *)param_1[0x26];
  local_8 = (int *)puVar1[3];
  piVar2 = (int *)puVar1[2];
  local_14 = (int *)puVar1[4];
  uVar4 = *puVar1 & 0xffffff;
  piVar7 = piVar2 + uVar4;
  iVar3 = param_1[5];
  local_c = *(int **)(iVar3 + *piVar2 * 4);
  piVar6 = *(int **)(iVar3 + *local_14 * 4);
  local_18 = *(int **)(iVar3 + *piVar7 * 4);
  local_10 = piVar7;
  if (((*piVar6 == *local_c) && (piVar6[2] == local_c[2])) ||
     ((*piVar6 == *local_18 && (piVar6[2] == local_18[2])))) {
    iVar3 = (**(code **)(*param_1 + 0x6c))(param_1[0x25],local_38,4,0,0);
    if (iVar3 < 0) {
      return;
    }
    local_c = (int *)0x0;
    if (local_8 != (int *)0x0) {
      iVar3 = param_1[5];
      local_18 = (int *)((int)local_14 - (int)local_28);
      do {
        piVar7 = local_c;
        piVar6 = local_18 + (int)local_c;
        local_c = (int *)((int)local_c + 1);
        local_28[(int)piVar7] =
             local_38[*(int *)(*(int *)(iVar3 + *(int *)((int)local_28 + (int)piVar6) * 4) + 0xc)];
      } while (local_c < local_8);
    }
    FUN_0061a3fb(2,local_28,local_8,piVar2,local_10,0,uVar4,0,0x1000000,0);
    uVar5 = 0x58;
    piVar6 = local_28;
    piVar7 = piVar2;
    piVar8 = local_10;
  }
  else {
    piVar8 = (int *)0x0;
    uVar5 = 0xb;
    piVar6 = piVar2;
  }
  FUN_0061a3fb(uVar5,local_14,local_8,piVar6,piVar7,piVar8,uVar4,0,0,0);
  return;
}


// ==== 0x60d3be FUN_0060d3be

void __fastcall FUN_0060d3be(int *param_1)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int local_38 [4];
  int local_28 [4];
  int *local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  puVar1 = (uint *)param_1[0x26];
  local_8 = (int *)puVar1[3];
  piVar2 = (int *)puVar1[2];
  local_14 = (int *)puVar1[4];
  uVar4 = *puVar1 & 0xffffff;
  local_10 = piVar2 + uVar4;
  iVar3 = param_1[5];
  local_c = *(int **)(iVar3 + *piVar2 * 4);
  piVar6 = *(int **)(iVar3 + *local_14 * 4);
  local_18 = *(int **)(iVar3 + *local_10 * 4);
  if (((*piVar6 == *local_c) && (piVar6[2] == local_c[2])) ||
     ((*piVar6 == *local_18 && (piVar6[2] == local_18[2])))) {
    iVar3 = (**(code **)(*param_1 + 0x6c))(param_1[0x25],local_38,4,0,0);
    if (iVar3 < 0) {
      return;
    }
    local_c = (int *)0x0;
    if (local_8 != (int *)0x0) {
      iVar3 = param_1[5];
      local_18 = (int *)((int)local_14 - (int)local_28);
      do {
        piVar6 = local_c;
        piVar7 = local_18 + (int)local_c;
        local_c = (int *)((int)local_c + 1);
        local_28[(int)piVar6] =
             local_38[*(int *)(*(int *)(iVar3 + *(int *)((int)local_28 + (int)piVar7) * 4) + 0xc)];
      } while (local_c < local_8);
    }
    FUN_0061a3fb(2,local_28,local_8,piVar2,local_10,0,uVar4,0,0x1000000,0);
    uVar5 = 0x58;
    piVar6 = local_28;
    piVar7 = piVar2;
  }
  else {
    piVar7 = (int *)0x0;
    uVar5 = 10;
    piVar6 = piVar2;
  }
  FUN_0061a3fb(uVar5,local_14,local_8,piVar6,local_10,piVar7,uVar4,0,0,0);
  return;
}


// ==== 0x60d4e8 FUN_0060d4e8

undefined4 __fastcall FUN_0060d4e8(int param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)(*(int *)(param_1 + 0xa0) + *(int *)(param_1 + 0xac) * 4);
  *puVar1 = *puVar1 | ((*(int *)(param_1 + 0xa4) - *(int *)(param_1 + 0xac)) + -1) * 0x1000000;
  return 0;
}


// ==== 0x60d508 FUN_0060d508

int __fastcall FUN_0060d508(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00618c39(*(undefined4 *)(param_1 + 0x30));
  if (-1 < iVar1) {
    iVar1 = FUN_0061663f();
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ==== 0x60d526 FUN_0060d526

int __thiscall FUN_0060d526(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0061a26f(0x200001f);
  if (-1 < iVar1) {
    iVar1 = *(int *)(param_2 + 0x20);
    if (iVar1 == 0x100000) {
      uVar2 = 0x90000000;
    }
    else if (iVar1 == 0x200000) {
      uVar2 = 0xa0000000;
    }
    else {
      if (iVar1 != 0x400000) {
        FUN_005fbec8(param_1,0,0x12ce,"internal error: unexpected Alias on texture declaration");
        return -0x7fffbffb;
      }
      uVar2 = 0x98000000;
    }
    iVar1 = FUN_00618c39(uVar2);
    if (((-1 < iVar1) &&
        (iVar1 = (**(code **)(*param_1 + 0x54))(*(uint *)(param_2 + 8) & 0x7ff | 0xa0000800,0xf0000)
        , -1 < iVar1)) && (iVar1 = FUN_0061663f(), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ==== 0x60d5c4 FUN_0060d5c4

undefined4 __fastcall FUN_0060d5c4(int param_1)

{
  uint *puVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0;
  bVar3 = false;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar5;
      puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + uVar5 * 4);
      *(uint **)(param_1 + 0x98) = puVar1;
      iVar2 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)puVar1[2] * 4);
      uVar4 = *puVar1 & 0xff000000;
      if ((((uVar4 == 0x44000000) || (uVar4 == 0x46000000)) || (uVar4 == 0x47000000)) ||
         (((uVar4 == 0x40000000 || (uVar4 == 0x42000000)) || (uVar4 == 0x43000000)))) {
        if ((*(byte *)(iVar2 + 0x22) & 0x60) != 0) {
          bVar3 = true;
        }
        *(undefined4 *)(iVar2 + 0x20) = 0x100000;
      }
      else if (((uVar4 == 0x48000000) || (uVar4 == 0x4a000000)) || (uVar4 == 0x4b000000)) {
        if ((*(byte *)(iVar2 + 0x22) & 0x50) != 0) {
          bVar3 = true;
        }
        *(undefined4 *)(iVar2 + 0x20) = 0x200000;
      }
      else if (((uVar4 == 0x4c000000) || (uVar4 == 0x4e000000)) || (uVar4 == 0x4f000000)) {
        if ((*(byte *)(iVar2 + 0x22) & 0x30) != 0) {
          bVar3 = true;
        }
        *(undefined4 *)(iVar2 + 0x20) = 0x400000;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 0xc));
    if (bVar3) {
      FUN_005fbec8(param_1,0,0x11bb,"sampler mismatch: sampler used inconsistently");
      return 0x80004005;
    }
  }
  return 0;
}


// ==== 0x60d6b0 FUN_0060d6b0

int __thiscall FUN_0060d6b0(int *param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  uint local_20 [7];
  
  uVar6 = (uint)*(byte *)((int)param_2 + 0x51);
  uVar2 = param_2[0x14] & 0xff;
  if (uVar2 == 1) {
    if ((uint)param_1[0x1b] <= uVar6) {
      return -0x7fffbffb;
    }
    *param_3 = uVar6;
    local_20[5] = 1;
    uVar5 = param_1[uVar6 + 0x4b];
  }
  else {
    if (uVar2 != 3) {
      return -0x7fffbffb;
    }
    if (7 < uVar6) {
      return -0x7fffbffb;
    }
    *param_3 = uVar6 + 2;
    uVar5 = param_1[uVar6 + 0x43];
    local_20[5] = 3;
  }
  param_3 = (uint *)0x0;
  local_20[6] = 0;
  if (uVar5 != 0) {
    do {
      if (local_20[6] == 0) {
        param_3 = (uint *)((uint)param_3 | 0x10000);
      }
      else if (local_20[6] == 1) {
        param_3 = (uint *)((uint)param_3 | 0x20000);
      }
      else if (local_20[6] == 2) {
        param_3 = (uint *)((uint)param_3 | 0x40000);
      }
      else if (local_20[6] == 3) {
        param_3 = (uint *)((uint)param_3 | 0x80000);
      }
      local_20[6] = local_20[6] + 1;
    } while (local_20[6] < uVar5);
  }
  if ((uVar2 == 3) && ((*(byte *)((int)param_2 + 0x1b) & 2) != 0)) {
    param_3 = (uint *)((uint)param_3 | 0x200000);
  }
  iVar3 = FUN_0061a26f(0x200001f);
  if ((-1 < iVar3) && (iVar3 = FUN_00618c39(0x80000000), -1 < iVar3)) {
    if ((*(byte *)(param_1 + 0xd) & 1) != 0) {
      local_20[4] = 0;
      local_20[6] = 0;
      local_20[0] = 0xffffffff;
      local_20[1] = 0xffffffff;
      local_20[2] = 0xffffffff;
      local_20[3] = 0xffffffff;
      uVar2 = param_1[2];
      if (uVar2 != 0) {
        puVar4 = (undefined4 *)param_1[5];
        do {
          piVar1 = (int *)*puVar4;
          if (((*param_2 == *piVar1) && (param_2[1] == piVar1[1])) && (param_2[2] == piVar1[2])) {
            local_20[piVar1[3]] = local_20[6];
          }
          local_20[6] = local_20[6] + 1;
          puVar4 = puVar4 + 1;
        } while (local_20[6] < uVar2);
      }
      uVar5 = 0;
      uVar2 = local_20[4];
      do {
        if (local_20[uVar5] != 0xffffffff) {
          local_20[uVar2] = local_20[uVar5];
          uVar2 = uVar2 + 1;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < 4);
      iVar3 = (**(code **)(*param_1 + 0x60))(local_20,uVar2,&param_2,1);
      if (iVar3 < 0) {
        return iVar3;
      }
    }
    iVar3 = (**(code **)(*param_1 + 0x54))
                      (((local_20[5] | 0xfffffff8) << 0x14 | local_20[5] & 0x18) << 8 | uVar6,
                       param_3);
    if ((-1 < iVar3) && (iVar3 = FUN_0061663f(), -1 < iVar3)) {
      iVar3 = 0;
    }
  }
  return iVar3;
}


// ==== 0x60d851 FUN_0060d851

undefined4 __thiscall FUN_0060d851(int param_1,int param_2,uint *param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_2 + 0x50);
  uVar2 = (uint)*(byte *)(param_2 + 0x51);
  *param_3 = uVar2;
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 1) {
    if (*(uint *)(param_1 + 0x6c) <= uVar2) {
      return 0x80004005;
    }
    *param_4 = 1;
  }
  else {
    if (uVar1 != 3) {
      return 0x80004005;
    }
    if (7 < uVar2) {
      return 0x80004005;
    }
    *param_4 = 3;
  }
  return 0;
}


// ==== 0x60d89b FUN_0060d89b

uint FUN_0060d89b(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  long lVar5;
  uint uVar6;
  bool bVar7;
  char local_30 [31];
  undefined1 local_11;
  int local_10;
  int local_c;
  uint local_8;
  
  lVar5 = 0;
  uVar4 = 0;
  local_10 = 0;
  local_8 = 0;
  _strncpy(local_30,*(char **)(param_1[0x13] + 0x18),0x1f);
  local_11 = 0;
  pcVar3 = local_30;
  if (local_30[0] == '\0') {
LAB_0060d8f7:
    if (*pcVar3 != '\0') {
      *pcVar3 = '\0';
      pcVar3 = pcVar3 + 1;
    }
  }
  else {
    do {
      iVar2 = _isalpha((int)*pcVar3);
      if (iVar2 == 0) break;
      pcVar3 = pcVar3 + 1;
    } while (*pcVar3 != '\0');
    if (*pcVar3 != '\0') {
      lVar5 = _atoi(pcVar3);
      goto LAB_0060d8f7;
    }
  }
  cVar1 = *pcVar3;
  if (cVar1 == '\0') {
LAB_0060d928:
    uVar6 = lVar5 + ((uint)param_1[0x15] >> 2);
  }
  else {
    do {
      iVar2 = _isdigit((int)cVar1);
      if (iVar2 == 0) break;
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
    } while (cVar1 != '\0');
    if (*pcVar3 == '\0') goto LAB_0060d928;
    uVar6 = 0xffffffff;
  }
  if (param_1[0x14] == 0xffffffff) {
    uVar4 = *(uint *)(*(int *)(*(int *)(local_c + 0x10) + *param_1 * 4) + 4);
    if (((uVar4 & 8) != 0) && ((uVar4 & 0x100) == 0)) {
      iVar2 = __stricmp(local_30,"color");
      if (iVar2 == 0) {
        local_8 = 1;
        if (param_2 == 0) {
          uVar4 = *(uint *)(local_c + 0x6c);
        }
        else {
          uVar4 = 2;
        }
        bVar7 = uVar6 < uVar4;
LAB_0060da3d:
        uVar4 = 1 - bVar7;
      }
      else {
        iVar2 = __stricmp(local_30,"texcoord");
        if (iVar2 == 0) {
          local_8 = 3;
          bVar7 = uVar6 < 8;
          goto LAB_0060da3d;
        }
        iVar2 = __stricmp(local_30,"position");
        if (iVar2 == 0) {
LAB_0060da33:
          local_8 = 4;
          bVar7 = uVar6 == 0;
          goto LAB_0060da3d;
        }
        iVar2 = __stricmp(local_30,"fog");
        if (iVar2 == 0) goto LAB_0060da33;
        iVar2 = __stricmp(local_30,"psize");
        if (iVar2 == 0) goto LAB_0060da33;
        iVar2 = __stricmp(local_30,"diffuse");
        if (iVar2 == 0) {
          uVar4 = (uint)(uVar6 != 0);
          local_8 = 1;
          local_10 = 1;
          if (uVar4 == 0) {
            uVar6 = 0;
          }
        }
        else {
          iVar2 = __stricmp(local_30,"specular");
          if (iVar2 == 0) {
            uVar4 = (uint)(uVar6 != 0);
            local_8 = 1;
            local_10 = 1;
            if (uVar4 == 0) {
              uVar6 = 1;
            }
          }
          else {
            local_8 = 0;
            uVar4 = 1;
          }
        }
      }
      if ((param_2 == 0) || (param_1[3] == 0)) {
        if (uVar4 != 0) {
          pcVar3 = "invalid input semantic \'%s%d\'";
          goto LAB_0060db61;
        }
        if (local_10 != 0) {
          FUN_005fbf37(local_c,param_1[0x13],0x1261,
                       "input semantic \'%s\' has been deprecated; use \'%s%d\' instead",local_30,
                       *(undefined4 *)(local_8 * 4 + 0x6df5b0),uVar6);
        }
      }
      goto LAB_0060db74;
    }
    if ((uVar4 & 0x10) != 0) {
      iVar2 = __stricmp(local_30,"color");
      if (iVar2 == 0) {
        bVar7 = uVar6 < *(uint *)(local_c + 0x84);
        local_8 = 1;
LAB_0060db1b:
        uVar4 = 1 - bVar7;
      }
      else {
        iVar2 = __stricmp(local_30,"depth");
        if (iVar2 == 0) {
          local_8 = 2;
          bVar7 = uVar6 == 0;
          goto LAB_0060db1b;
        }
        local_8 = 0;
        uVar4 = 1;
      }
      if ((uVar4 == 0) || ((param_2 != 0 && (param_1[3] != 0)))) goto LAB_0060db74;
      pcVar3 = "invalid output semantic \'%s%d\'";
LAB_0060db61:
      iVar2 = param_1[0x13];
      goto LAB_0060db6c;
    }
  }
  else {
    uVar6 = (uint)*(byte *)((int)param_1 + 0x51);
    local_8 = param_1[0x14] & 0xff;
    if (local_8 == 4) {
      if ((*(int *)(local_c + 0x13c) != 0) || (param_2 != 0)) goto LAB_0060db81;
      uVar4 = 1;
      *(int *)(local_c + 0x13c) = 1;
      pcVar3 = "invalid reference to input semantic \'%s%d\'";
      iVar2 = param_1[0x13];
LAB_0060db6c:
      FUN_005fbec8(local_c,iVar2,0x1196,pcVar3,local_30,uVar6);
    }
LAB_0060db74:
    if (local_8 != 0) goto LAB_0060db81;
  }
  uVar4 = 1;
LAB_0060db81:
  if (0xffff < uVar6) {
    uVar4 = 1;
  }
  param_1[0x14] = (uVar6 | 0xffffff00) << 8 | local_8 & 0xff;
  return -(uint)(uVar4 != 0) & 0x80004005;
}


// ==== 0x60dbb2 FUN_0060dbb2

undefined4 FUN_0060dbb2(int param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x50);
  uVar2 = (uint)*(byte *)(param_1 + 0x51);
  *param_2 = uVar2;
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 1) {
    if (3 < uVar2) {
      return 0x80004005;
    }
    *param_3 = 8;
  }
  else {
    if (uVar1 != 2) {
      return 0x80004005;
    }
    if (uVar2 != 0) {
      return 0x80004005;
    }
    *param_3 = 9;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 1;
  }
  return 0;
}


// ==== 0x60dc08 FUN_0060dc08

undefined4 __thiscall FUN_0060dc08(int param_1,int param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(int *)(param_2 + 4) != 0) {
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)(*(int *)(param_2 + 8) + uVar3 * 4) * 4)
      ;
      if (((*(int *)(param_1 + 0x60) == *piVar1) && ((uint)piVar1[0xd] < param_3)) &&
         (iVar2 = FUN_005f7a96(), iVar2 == 0)) {
        return 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_2 + 4));
  }
  return 0;
}


// ==== 0x60dc56 FUN_0060dc56

undefined4 __thiscall FUN_0060dc56(int param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  uint *puVar5;
  uint *puVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint auStack_74 [8];
  uint auStack_54 [9];
  uint local_30;
  uint local_20;
  uint local_1c;
  uint local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  if (param_2 == (uint *)0x0) {
    uVar7 = 1;
  }
  else {
    iVar8 = FUN_005f7a96();
    if (iVar8 == 0) {
      uVar11 = *param_2 & 0xffffff;
      local_20 = param_2[1] / uVar11;
      if (1 < local_20) {
        iVar8 = *(int *)(param_1 + 0x58);
        iVar1 = *(int *)(param_1 + 0x60);
        uVar2 = *(uint *)(param_1 + 0x54);
        auStack_54[iVar8] = 0;
        auStack_54[iVar1] = 0;
        auStack_54[uVar2] = 0;
        auStack_74[iVar8] = 1;
        uVar3 = *(uint *)(param_1 + 0x68);
        local_c = uVar2;
        auStack_74[iVar1] = 3;
        local_30 = uVar3;
        auStack_54[uVar3] = 0;
        auStack_74[uVar2] = 1;
        uVar2 = local_20;
        auStack_74[uVar3] = 1;
        local_1c = 0;
        local_8 = 0;
        if (uVar2 != 0) {
          iVar8 = *(int *)(param_1 + 0x10);
          iVar1 = *(int *)(param_1 + 0x14);
          piVar4 = (int *)param_2[2];
          piVar9 = piVar4;
          do {
            puVar5 = *(uint **)(iVar1 + *piVar9 * 4);
            uVar2 = *puVar5;
            uVar3 = *(uint *)(*(int *)(iVar8 + uVar2 * 4) + 4);
            uVar10 = local_30;
            if ((uVar3 & 0x100) == 0) {
              local_14 = uVar2;
              if ((uVar3 & 0x40) != 0) goto LAB_0060dd38;
            }
            else {
              if ((uVar3 & 0x40) == 0) {
                uVar10 = local_c;
              }
LAB_0060dd38:
              local_14 = uVar10;
            }
            param_2 = (uint *)0x0;
            local_10 = piVar4;
            if (local_8 != 0) {
              do {
                puVar6 = *(uint **)(iVar1 + *local_10 * 4);
                if (((uVar2 == *puVar6) && (puVar5[1] == puVar6[1])) && (puVar5[2] == puVar6[2]))
                break;
                param_2 = (uint *)((int)param_2 + 1);
                local_10 = local_10 + uVar11;
              } while (param_2 < local_8);
            }
            if ((param_2 == (uint *)local_8) && (local_14 < 8)) {
              puVar5 = auStack_54 + local_14;
              *puVar5 = *puVar5 + 1;
              if (auStack_74[local_14] < *puVar5) goto LAB_0060dddb;
            }
            if (((uVar3 & 0x100) != 0) && (local_1c = local_1c + 1, 2 < local_1c)) {
LAB_0060dddb:
              if (param_3 == (uint *)0x0) {
                return 1;
              }
              *param_3 = local_8;
              return 1;
            }
            piVar9 = piVar9 + uVar11;
            local_8 = local_8 + 1;
          } while (local_8 < local_20);
        }
      }
      uVar7 = 0;
    }
    else {
      uVar7 = 0;
    }
  }
  return uVar7;
}


// ==== 0x60dde6 FUN_0060dde6

undefined4 FUN_0060dde6(int *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  param_2 = param_2 - (int)param_1;
  while ((*param_1 == -1 || (*param_1 == *(int *)(param_2 + (int)param_1)))) {
    uVar1 = uVar1 + 1;
    param_1 = param_1 + 1;
    if (3 < uVar1) {
      return 1;
    }
  }
  return 0;
}


// ==== 0x60de13 FUN_0060de13

undefined4 FUN_0060de13(uint param_1,int *param_2)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_1 - (int)param_2;
  param_1 = 0;
  piVar3 = &DAT_006df5c8;
  while( true ) {
    bVar1 = true;
    iVar5 = 4;
    piVar2 = param_2;
    do {
      if ((*(int *)(iVar4 + (int)piVar2) != *piVar3) && (*piVar2 != -1)) {
        bVar1 = false;
      }
      piVar3 = piVar3 + 1;
      piVar2 = piVar2 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    if (bVar1) break;
    param_1 = param_1 + 0x10;
    if (0x7f < param_1) {
      return 0;
    }
  }
  return 1;
}


// ==== 0x60de67 FUN_0060de67

int __thiscall FUN_0060de67(int *param_1,int *param_2,uint param_3,uint param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  uint uVar7;
  bool bVar8;
  int local_28 [4];
  int local_18 [4];
  int *local_8;
  
  uVar4 = 0;
  bVar8 = param_4 == 0;
  if (param_4 != 0) {
    local_8 = *(int **)(param_1[0x26] + 8);
    piVar2 = *(int **)(param_1[5] + **(int **)(param_1[0x26] + 0x10) * 4);
    do {
      piVar3 = *(int **)(param_1[5] + *local_8 * 4);
      if ((*piVar2 == *piVar3) && (piVar2[2] == piVar3[2])) break;
      uVar4 = uVar4 + 1;
      local_8 = local_8 + param_3;
    } while (uVar4 < param_4);
    bVar8 = uVar4 == param_4;
  }
  if (!bVar8) {
    iVar1 = *(int *)(param_1[0x26] + 8) + uVar4 * param_3 * 4;
    local_18[0] = -1;
    local_18[1] = 0xffffffff;
    local_18[2] = 0xffffffff;
    uVar4 = 0;
    uVar7 = 0;
    local_18[3] = 0xffffffff;
    if (param_3 != 0) {
      do {
        iVar5 = *(int *)(iVar1 + uVar4 * 4);
        uVar4 = uVar4 + 1;
        local_18[*(int *)(*(int *)(param_1[5] + iVar5 * 4) + 0xc)] = iVar5;
      } while (uVar4 < param_3);
    }
    uVar4 = 0;
    do {
      uVar7 = uVar7 + (local_18[uVar4] != -1);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 4);
    iVar5 = (**(code **)(*param_1 + 0x6c))(param_1[0x25],local_28,4,0,0);
    if (iVar5 < 0) {
      return iVar5;
    }
    pvVar6 = _malloc(0x38);
    if (pvVar6 == (void *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_005f7709();
    }
    *param_2 = iVar5;
    if (iVar5 == 0) {
      return -0x7ff8fff2;
    }
    iVar5 = FUN_005f7760(uVar7 & 0xffffff | 0x10000000,uVar7,uVar7,0);
    if (iVar5 < 0) {
      return iVar5;
    }
    iVar5 = FUN_005f7a42(param_1[0x26]);
    if (iVar5 < 0) {
      return iVar5;
    }
    iVar5 = 0;
    uVar4 = 0;
    do {
      if (*(int *)((int)local_18 + uVar4) != -1) {
        *(undefined4 *)(iVar5 + *(int *)(*param_2 + 0x10)) = *(undefined4 *)((int)local_28 + uVar4);
        *(undefined4 *)(iVar5 + *(int *)(*param_2 + 8)) = *(undefined4 *)((int)local_18 + uVar4);
        iVar5 = iVar5 + 4;
      }
      uVar4 = uVar4 + 4;
    } while (uVar4 < 0x10);
    uVar4 = 0;
    if (param_3 != 0) {
      do {
        piVar2 = (int *)(iVar1 + uVar4 * 4);
        uVar4 = uVar4 + 1;
        *piVar2 = local_28[*(int *)(*(int *)(param_1[5] + *piVar2 * 4) + 0xc)];
      } while (uVar4 < param_3);
    }
  }
  return 0;
}


// ==== 0x60dfe1 FUN_0060dfe1

int __thiscall FUN_0060dfe1(int *param_1,int *param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  undefined4 local_14 [4];
  
  piVar1 = param_2;
  iVar2 = (**(code **)(*param_1 + 0x6c))
                    (param_1[0x25],local_14,*(undefined4 *)(param_1[0x26] + 0xc),0,0);
  if (-1 < iVar2) {
    pvVar3 = _malloc(0x38);
    if (pvVar3 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_005f7709();
    }
    *param_2 = iVar2;
    if (iVar2 == 0) {
      iVar2 = -0x7ff8fff2;
    }
    else {
      iVar2 = FUN_005f7760(param_3 & 0xffffff | 0x10000000,param_3,param_3,0);
      iVar4 = *param_2;
      if (-1 < iVar2) {
        iVar2 = FUN_005f7a42(param_1[0x26]);
        if (-1 < iVar2) {
          param_2 = (int *)0x0;
          if (param_3 != 0) {
            do {
              iVar2 = (int)param_2 * 4;
              *(undefined4 *)(iVar2 + *(int *)(*piVar1 + 8)) = local_14[(int)param_2];
              *(undefined4 *)(iVar2 + *(int *)(*piVar1 + 0x10)) =
                   *(undefined4 *)(iVar2 + *(int *)(param_1[0x26] + 0x10));
              *(undefined4 *)(iVar2 + *(int *)(param_1[0x26] + 0x10)) = local_14[(int)param_2];
              param_2 = (int *)((int)param_2 + 1);
            } while (param_2 < param_3);
          }
          return 0;
        }
        iVar4 = *param_2;
      }
      param_2 = (int *)iVar2;
      iVar2 = (int)param_2;
      if (iVar4 != 0) {
        FUN_005f7186(1);
      }
    }
  }
  return iVar2;
}


// ==== 0x60e0d8 FUN_0060e0d8

/* WARNING: Type propagation algorithm not settling */

int __fastcall FUN_0060e0d8(int param_1)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *puVar9;
  uint uVar10;
  int *piVar11;
  bool bVar12;
  undefined4 uVar13;
  int local_b4 [12];
  uint local_84 [9];
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  uint local_54 [9];
  uint local_30;
  int local_2c;
  int local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  local_2c = 0;
  local_28 = 0;
  puVar1 = *(uint **)(param_1 + 0x98);
  piVar7 = (int *)(*puVar1 & 0xff000000);
  if (piVar7 == (int *)0x0) {
    return 0;
  }
  local_18 = (int *)(*puVar1 & 0xffffff);
  local_54[8] = puVar1[1];
  local_10 = (int *)(local_54[8] / (uint)local_18);
  local_30 = local_54[8] % (uint)local_18;
  if (((piVar7 == (int *)0x30000000) || (piVar7 == (int *)0x35000000)) ||
     (piVar7 == (int *)0xfa000000)) {
    bVar12 = true;
  }
  else {
    bVar12 = false;
  }
  local_20 = piVar7;
  if (((piVar7 == (int *)0x44000000) || (piVar7 == (int *)0x48000000)) ||
     ((piVar7 == (int *)0x4c000000 || (piVar7 == (int *)0x34000000)))) {
    iVar4 = FUN_005f75cb(puVar1);
    if (iVar4 < 0) {
      return iVar4;
    }
    **(undefined4 **)(param_1 + 0x98) = 0;
    goto LAB_0060ead6;
  }
  if (bVar12) {
    if ((piVar7 == (int *)0x35000000) || (piVar7 == (int *)0xfa000000)) {
      iVar4 = FUN_005f75cb(puVar1);
      if (-1 < iVar4) {
        **(undefined4 **)(param_1 + 0x98) = 0;
        return iVar4;
      }
      return iVar4;
    }
    if (**(int **)(*(int *)(param_1 + 0x14) + *(int *)puVar1[4] * 4) == *(int *)(param_1 + 0x5c)) {
      uVar13 = 0x12d1;
LAB_0060e822:
      FUN_005fbec8(param_1,puVar1[0xd],uVar13,
                   "internal error: write to output with instruction other than mov");
      return -0x7fffbffb;
    }
    local_8 = (int *)0x0;
    if (local_10 != (int *)0x0) {
      local_c = local_b4;
      local_14 = 0;
      do {
        piVar8 = local_c;
        piVar3 = local_18;
        bVar12 = local_18 != (int *)0x0;
        piVar7 = local_c + 1;
        *local_c = -1;
        *piVar7 = -1;
        piVar8[2] = -1;
        piVar8[3] = -1;
        if (bVar12) {
          piVar7 = (int *)(puVar1[2] + local_14);
          local_20 = piVar3;
          do {
            *piVar8 = *(int *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar7 * 4) + 0xc);
            piVar7 = piVar7 + 1;
            piVar8 = piVar8 + 1;
            local_20 = (int *)((int)local_20 + -1);
          } while (local_20 != (int *)0x0);
        }
        local_1c = (int *)0x0;
        puVar9 = &DAT_006df5c8;
        while (iVar4 = FUN_0060dde6(local_c,puVar9), iVar4 == 0) {
          local_1c = local_1c + 4;
          puVar9 = puVar9 + 4;
          if ((int *)0x7f < local_1c) {
            iVar4 = FUN_0060de67(&local_28,local_18,local_10);
            if (iVar4 < 0) goto LAB_0060eae6;
            if (local_28 != 0) {
              iVar4 = FUN_005f73c0(local_28);
              if (iVar4 < 0) goto LAB_0060eae6;
              local_28 = 0;
            }
            pvVar6 = _malloc(0x38);
            if (pvVar6 == (void *)0x0) {
              iVar5 = 0;
            }
            else {
              iVar5 = FUN_005f7709();
            }
            if (iVar5 == 0) goto LAB_0060ea9f;
            iVar4 = FUN_005f7760(0x25000001,2,1,0);
            if ((iVar4 < 0) || (iVar4 = FUN_005f7a42(*(undefined4 *)(param_1 + 0x98)), iVar4 < 0))
            goto LAB_0060eae6;
            **(undefined4 **)(iVar5 + 0x10) = **(undefined4 **)(*(int *)(param_1 + 0x98) + 0x10);
            **(undefined4 **)(iVar5 + 8) = **(undefined4 **)(*(int *)(param_1 + 0x98) + 8);
            local_54[8] = (int)local_18 * 4;
            *(undefined4 *)(*(int *)(iVar5 + 8) + 4) =
                 *(undefined4 *)(local_54[8] + *(int *)(*(int *)(param_1 + 0x98) + 8));
            iVar4 = FUN_005f73c0(iVar5);
            if (iVar4 < 0) goto LAB_0060eae6;
            local_8 = (int *)0x1;
            if (local_18 < (int *)0x2) goto LAB_0060e929;
            local_c = (int *)(local_54[8] + 4);
            goto LAB_0060e9db;
          }
        }
        local_8 = (int *)((int)local_8 + 1);
        local_c = local_c + 4;
        local_14 = local_14 + (int)local_18 * 4;
      } while (local_8 < local_10);
    }
    iVar4 = FUN_005f75cb(puVar1);
    if (iVar4 < 0) {
      return iVar4;
    }
LAB_0060e929:
    **(undefined4 **)(param_1 + 0x98) = 0;
LAB_0060e932:
    iVar4 = 0;
  }
  else {
    local_8 = (int *)0x0;
    if (local_10 != (int *)0x0) {
      local_14 = 0;
      local_1c = local_b4;
      local_30 = (int)local_18 << 2;
      do {
        piVar2 = local_18;
        piVar8 = local_1c;
        bVar12 = local_18 != (int *)0x0;
        piVar3 = local_1c + 1;
        *local_1c = -1;
        *piVar3 = -1;
        piVar8[2] = -1;
        piVar8[3] = -1;
        if (bVar12) {
          local_c = (int *)puVar1[4];
          piVar3 = (int *)(puVar1[2] + local_14);
          local_24 = piVar2;
          do {
            iVar4 = *piVar3;
            iVar5 = *local_c;
            local_c = local_c + 1;
            piVar3 = piVar3 + 1;
            local_24 = (int *)((int)local_24 + -1);
            bVar12 = local_24 != (int *)0x0;
            local_b4[*(int *)(*(int *)(*(int *)(param_1 + 0x14) + iVar5 * 4) + 0xc) +
                     (int)local_8 * 4] =
                 *(int *)(*(int *)(*(int *)(param_1 + 0x14) + iVar4 * 4) + 0xc);
            piVar7 = local_20;
          } while (bVar12);
        }
        local_8 = (int *)((int)local_8 + 1);
        local_14 = local_14 + local_30;
        local_1c = local_1c + 4;
      } while (local_8 < local_10);
    }
    piVar3 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)puVar1[4] * 4);
    if (*piVar3 != *(int *)(param_1 + 0x5c)) {
      local_8 = (int *)0x0;
      if (local_10 != (int *)0x0) {
        local_c = local_b4;
        do {
          puVar9 = &DAT_006df5c8;
          uVar10 = 0;
          while (iVar4 = FUN_0060dde6(local_c,puVar9), iVar4 == 0) {
            uVar10 = uVar10 + 0x10;
            puVar9 = puVar9 + 4;
            if (0x7f < uVar10) {
              local_c = (int *)0x1;
              goto LAB_0060e39f;
            }
          }
          local_8 = (int *)((int)local_8 + 1);
          local_c = local_c + 4;
        } while (local_8 < local_10);
      }
LAB_0060e50d:
      iVar4 = FUN_005f75cb(*(undefined4 *)(param_1 + 0x98));
      if (iVar4 < 0) goto LAB_0060ead6;
      goto LAB_0060e929;
    }
    if (piVar7 != (int *)0x10000000) {
      uVar13 = 0x12cf;
      goto LAB_0060e822;
    }
    local_20 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)puVar1[2] * 4);
    local_30 = piVar3[0x14] & 0xff;
    if (local_30 == 1) {
      if (local_54[8] != 4) {
        FUN_005fbec8(param_1,0,0x12d0,
                     "internal error: compiler emittimg multiple movs to output registers");
        return -0x7fffbffb;
      }
      piVar7 = (int *)FUN_0060dde6(local_b4,&DAT_006df608);
    }
    else {
      if (local_30 != 2) {
        return -0x7fffbffb;
      }
      uVar10 = 0;
      local_24 = (int *)0x0;
      puVar9 = &DAT_006df5c8;
      do {
        iVar4 = FUN_0060dde6(local_b4,puVar9);
        if (iVar4 != 0) {
          local_24 = (int *)0x1;
          piVar7 = local_24;
          break;
        }
        uVar10 = uVar10 + 0x10;
        puVar9 = puVar9 + 4;
        piVar7 = local_24;
      } while (uVar10 < 0x40);
    }
    local_c = (int *)(uint)(piVar7 == (int *)0x0);
    if (((local_c == (int *)0x0) && ((*(byte *)((int)local_20 + 0x22) & 0xf) == 0)) ||
       (iVar4 = FUN_0060dfe1(&local_2c,local_18), -1 < iVar4)) {
      local_84[0] = 0;
      local_84[1] = 0;
      local_84[2] = 0;
      local_84[3] = 0;
      iVar4 = FUN_0060de13(local_b4,local_84);
      if ((iVar4 != 0) || ((local_30 == 2 && (local_b4[0] == 0)))) {
        iVar4 = FUN_00615991(local_84,local_10,local_18);
        if (-1 < iVar4) {
          **(undefined4 **)(param_1 + 0x98) = 0;
          if (local_2c == 0) {
            return iVar4;
          }
          iVar4 = FUN_005f73c0(local_2c);
          if (-1 < iVar4) {
            return iVar4;
          }
        }
        goto LAB_0060ead6;
      }
LAB_0060e39f:
      if (local_c == (int *)0x0) goto LAB_0060e50d;
      iVar4 = FUN_0060de67(&local_28,local_18,local_10);
      if (iVar4 < 0) goto LAB_0060ead6;
      if (local_28 != 0) {
        iVar4 = FUN_005f73c0(local_28);
        if (iVar4 < 0) goto LAB_0060ead6;
        local_28 = 0;
      }
      local_1c = (int *)0x0;
      local_20 = (int *)0x0;
      if (local_18 == (int *)0x4) {
        local_14 = 1;
        uVar10 = 0;
        do {
          if (local_14 == 0) break;
          local_14 = 0;
          local_84[0] = 0;
          local_84[1] = 0;
          local_84[2] = 0;
          local_84[3] = 0;
          local_84[4] = 0xffffffff;
          local_84[5] = 0xffffffff;
          local_84[6] = 0xffffffff;
          local_84[7] = 0xffffffff;
          local_84[uVar10] = 0xffffffff;
          local_84[uVar10 + 4] = 0;
          if (local_10 == (int *)0x0) {
LAB_0060e529:
            iVar4 = FUN_00615991(local_84,local_10,4);
            if ((iVar4 < 0) || (iVar4 = FUN_00615991(local_84 + 4,local_10,4), iVar4 < 0))
            goto LAB_0060ead6;
            goto LAB_0060e7cb;
          }
          piVar7 = local_b4;
          local_24 = local_10;
          do {
            iVar4 = FUN_0060de13(piVar7,local_84);
            if ((iVar4 == 0) || (iVar4 = FUN_0060de13(piVar7,local_84), iVar4 == 0)) {
              local_14 = 1;
            }
            piVar7 = piVar7 + 4;
            local_24 = (int *)((int)local_24 + -1);
          } while (local_24 != (int *)0x0);
          local_24 = (int *)0x0;
          if (local_14 == 0) goto LAB_0060e529;
          uVar10 = uVar10 + 1;
        } while (uVar10 < 4);
        local_14 = 1;
        local_8 = (int *)0x0;
        do {
          if (local_14 == 0) break;
          local_c = (int *)0x0;
          do {
            piVar3 = local_8;
            piVar7 = local_c;
            if (local_c != local_8) {
              local_84[0] = 0;
              local_84[1] = 0;
              local_84[2] = 0;
              local_84[3] = 0;
              local_84[4] = 0xffffffff;
              local_84[5] = 0xffffffff;
              local_84[6] = 0xffffffff;
              local_84[7] = 0xffffffff;
              local_84[(int)local_8] = 0xffffffff;
              local_84[(int)piVar7] = 0xffffffff;
              local_84[(int)(piVar3 + 1)] = 0;
              local_84[(int)(piVar7 + 1)] = 0;
              local_14 = 0;
              local_30 = 0;
              if (local_10 != (int *)0x0) {
                piVar7 = local_b4;
                local_24 = local_10;
                do {
                  iVar4 = FUN_0060de13(piVar7,local_84);
                  iVar5 = FUN_0060de13(piVar7,local_84 + 4);
                  if (iVar4 == 0) {
                    local_30 = 1;
LAB_0060e566:
                    local_14 = 1;
                  }
                  else if (iVar5 == 0) goto LAB_0060e566;
                  piVar7 = piVar7 + 4;
                  local_24 = (int *)((int)local_24 + -1);
                } while (local_24 != (int *)0x0);
                if (local_14 != 0) {
                  if (local_30 == 0) {
                    local_84[8] = local_84[0];
                    uStack_60 = local_84[1];
                    uStack_5c = local_84[2];
                    uStack_58 = local_84[3];
                    local_54[0] = 0xffffffff;
                    local_54[1] = 0xffffffff;
                    local_54[2] = 0xffffffff;
                    local_54[3] = 0xffffffff;
                    local_54[4] = 0xffffffff;
                    local_54[5] = 0xffffffff;
                    local_54[6] = 0xffffffff;
                    local_54[7] = 0xffffffff;
                    local_54[(int)local_8] = 0;
                    local_54[(int)(local_c + 1)] = 0;
                    local_20 = (int *)0x1;
                  }
                  goto LAB_0060e5ba;
                }
              }
              local_1c = (int *)0x1;
              break;
            }
LAB_0060e5ba:
            local_c = (int *)((int)local_c + 1);
          } while (local_c < (int *)0x4);
          local_8 = (int *)((int)local_8 + 1);
        } while (local_8 < (int *)0x4);
        if (local_1c == (int *)0x0) {
          if (local_20 == (int *)0x0) goto LAB_0060e776;
          local_1c = (int *)0x1;
          iVar4 = FUN_00615991(local_84 + 8,local_10,4);
          if ((-1 < iVar4) && (iVar4 = FUN_00615991(local_54,local_10,4), -1 < iVar4)) {
            uVar13 = 4;
            puVar1 = local_54;
            goto LAB_0060e75c;
          }
        }
        else {
          iVar4 = FUN_00615991(local_84,local_10,4);
          if (-1 < iVar4) {
            uVar13 = 4;
LAB_0060e759:
            puVar1 = local_84;
LAB_0060e75c:
            iVar4 = FUN_00615991(puVar1 + 4,local_10,uVar13);
            if (-1 < iVar4) {
              if (local_1c == (int *)0x0) goto LAB_0060e776;
              goto LAB_0060e7cb;
            }
          }
        }
        goto LAB_0060ead6;
      }
      if (local_18 == (int *)0x3) {
        local_20 = (int *)0xffffffff;
        piVar7 = (int *)0x0;
        do {
          if (local_b4[(int)piVar7] == -1) {
            local_20 = piVar7;
          }
          piVar7 = (int *)((int)piVar7 + 1);
        } while (piVar7 < (int *)0x4);
        local_8 = (int *)0x0;
        do {
          if (local_1c != (int *)0x0) goto LAB_0060e73d;
          piVar7 = (int *)0x0;
          do {
            piVar8 = local_8;
            piVar3 = local_20;
            if (local_1c != (int *)0x0) break;
            if (((piVar7 != local_8) && (piVar7 != local_20)) && (local_8 != local_20)) {
              local_84[0] = 0xffffffff;
              local_84[1] = 0xffffffff;
              local_84[2] = 0xffffffff;
              local_84[3] = 0xffffffff;
              local_84[4] = 0;
              local_84[5] = 0;
              local_84[6] = 0;
              local_84[7] = 0;
              uVar10 = (int)local_8 * 4;
              local_84[(int)local_8] = 0;
              piVar2 = local_10;
              piVar11 = (int *)0x0;
              local_84[(int)piVar7] = 0;
              local_54[8] = uVar10;
              local_84[(int)(piVar8 + 1)] = 0xffffffff;
              local_84[(int)(piVar7 + 1)] = 0xffffffff;
              local_84[(int)(piVar3 + 1)] = 0xffffffff;
              local_14 = 0;
              if (piVar2 != (int *)0x0) {
                local_c = local_b4;
                do {
                  if (local_14 != 0) goto LAB_0060e71f;
                  iVar4 = FUN_0060de13(local_c,local_84);
                  if (iVar4 == 0) {
                    local_14 = 1;
                  }
                  local_c = local_c + 4;
                  piVar11 = (int *)((int)piVar11 + 1);
                } while (piVar11 < local_10);
                if (local_14 != 0) goto LAB_0060e71f;
              }
              local_1c = (int *)0x1;
            }
LAB_0060e71f:
            piVar7 = (int *)((int)piVar7 + 1);
          } while (piVar7 < (int *)0x4);
          local_8 = (int *)((int)local_8 + 1);
        } while (local_8 < (int *)0x4);
        if (local_1c != (int *)0x0) {
LAB_0060e73d:
          iVar4 = FUN_00615991(local_84,local_10,3);
          if (-1 < iVar4) {
            uVar13 = 3;
            goto LAB_0060e759;
          }
          goto LAB_0060ead6;
        }
      }
LAB_0060e776:
      local_8 = (int *)0x0;
      if (local_18 != (int *)0x0) {
        do {
          piVar3 = local_10;
          piVar7 = local_18;
          local_84[0] = 0xffffffff;
          local_84[1] = 0xffffffff;
          local_84[2] = 0xffffffff;
          local_84[3] = 0xffffffff;
          local_84[*(int *)(*(int *)(*(int *)(param_1 + 0x14) +
                                    *(int *)(*(int *)(*(int *)(param_1 + 0x98) + 0x10) +
                                            (int)local_8 * 4) * 4) + 0xc)] = 0;
          iVar4 = FUN_00615991(local_84,piVar3,piVar7);
          if (iVar4 < 0) goto LAB_0060ead6;
          local_8 = (int *)((int)local_8 + 1);
        } while (local_8 < local_18);
      }
LAB_0060e7cb:
      if (local_2c != 0) {
        iVar4 = FUN_005f73c0(local_2c);
        if (iVar4 < 0) goto LAB_0060ead6;
        local_2c = 0;
      }
      **(undefined4 **)(param_1 + 0x98) = 0;
      goto LAB_0060e932;
    }
  }
LAB_0060ead6:
  if (local_2c != 0) {
    FUN_005f7186(1);
  }
LAB_0060eae6:
  if (local_28 != 0) {
    FUN_005f7186(1);
  }
  return iVar4;
  while( true ) {
    iVar4 = FUN_005f7760(0xf5000001,3,1,0);
    if ((iVar4 < 0) || (iVar4 = FUN_005f7a42(*(undefined4 *)(param_1 + 0x98)), iVar4 < 0))
    goto LAB_0060eae6;
    **(undefined4 **)(iVar5 + 0x10) = **(undefined4 **)(*(int *)(param_1 + 0x98) + 0x10);
    **(undefined4 **)(iVar5 + 8) =
         *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x98) + 8) + (int)local_8 * 4);
    *(undefined4 *)(*(int *)(iVar5 + 8) + 4) =
         *(undefined4 *)((int)local_c + *(int *)(*(int *)(param_1 + 0x98) + 8));
    *(undefined4 *)(*(int *)(iVar5 + 8) + 8) = **(undefined4 **)(*(int *)(param_1 + 0x98) + 0x10);
    iVar4 = FUN_005f73c0(iVar5);
    if (iVar4 < 0) goto LAB_0060eae6;
    local_8 = (int *)((int)local_8 + 1);
    local_c = local_c + 1;
    if (local_18 <= local_8) break;
LAB_0060e9db:
    pvVar6 = _malloc(0x38);
    if (pvVar6 == (void *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_005f7709();
    }
    if (iVar5 == 0) goto LAB_0060ea9f;
  }
  goto LAB_0060e929;
LAB_0060ea9f:
  iVar4 = -0x7ff8fff2;
  goto LAB_0060eae6;
}


// ==== 0x60eafe FUN_0060eafe

undefined4 __thiscall FUN_0060eafe(int param_1,int *param_2,uint param_3,uint param_4,uint *param_5)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  bool bVar10;
  uint local_28 [4];
  int local_18 [4];
  int local_8;
  
  iVar5 = *(int *)(param_1 + 0x14);
  piVar2 = *(int **)(iVar5 + *param_2 * 4);
  local_8 = param_1;
  if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4) + 4) & 0x40) != 0) {
    *param_5 = 0xe40000;
    return 0;
  }
  bVar10 = (param_4 & 0x10000) != 0;
  if (bVar10) {
    local_18[0] = 0;
  }
  uVar4 = (uint)bVar10;
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
  iVar8 = *(int *)(param_1 + 0x90) << 0x1e;
  if (iVar8 < 0) {
    local_28[0] = 0xffffffff;
  }
  else {
    uVar4 = 0;
    if (param_3 != 0) {
      do {
        if (piVar2[3] != *(int *)(*(int *)(iVar5 + param_2[uVar4] * 4) + 0xc)) break;
        uVar4 = uVar4 + 1;
      } while (uVar4 < param_3);
      if (uVar4 < param_3) {
        uVar4 = 0;
        do {
          local_28[uVar4] = uVar4;
          uVar4 = uVar4 + 1;
        } while (uVar4 < 4);
        goto LAB_0060ebce;
      }
    }
    local_28[0] = piVar2[3];
  }
  local_28[1] = local_28[0];
  local_28[2] = local_28[0];
  local_28[3] = local_28[0];
LAB_0060ebce:
  uVar4 = 0;
  if (param_3 != 0) {
    do {
      piVar1 = local_18 + uVar4;
      piVar2 = param_2 + uVar4;
      uVar4 = uVar4 + 1;
      local_28[*piVar1] = *(uint *)(*(int *)(iVar5 + *piVar2 * 4) + 0xc);
    } while (uVar4 < param_3);
  }
  if (-1 < iVar8) {
    puVar6 = local_28;
LAB_0060ec53:
    uVar7 = 0;
    uVar4 = 0x10;
    do {
      uVar3 = *puVar6;
      puVar6 = puVar6 + 1;
      uVar7 = uVar7 | uVar3 << ((byte)uVar4 & 0x1f);
      uVar4 = uVar4 + 2;
    } while (uVar4 < 0x18);
    *param_5 = uVar7;
    return 0;
  }
  uVar4 = 0;
  puVar9 = &DAT_006df5c8;
  do {
    iVar5 = FUN_0060dde6(local_28,puVar9);
    if (iVar5 != 0) {
      puVar6 = &DAT_006df5c8 + uVar4 * 4;
      if (puVar6 != (uint *)0x0) goto LAB_0060ec53;
      break;
    }
    uVar4 = uVar4 + 1;
    puVar9 = puVar9 + 4;
  } while (uVar4 < 8);
  FUN_005fbec8(local_8,*(undefined4 *)(*(int *)(local_8 + 0x98) + 0x34),0x12d2,
               "internal error: invalid swizzle found");
  return 0x80004005;
}


// ==== 0x60ec76 FUN_0060ec76

undefined4 * __thiscall FUN_0060ec76(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a5ba8;
  FUN_00613825();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x60ec98 FUN_0060ec98

undefined4 __thiscall FUN_0060ec98(int param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint local_28 [5];
  int local_14;
  uint local_10;
  int local_c;
  undefined4 *local_8;
  
  uVar6 = *param_2 & 0xffffff;
  if (uVar6 == 0) {
    uVar2 = 1;
  }
  else {
    local_28[4] = param_2[1] / uVar6;
    local_10 = 0;
    if (local_28[4] != 0) {
      iVar1 = *(int *)(param_1 + 0x90);
      local_c = 0;
      local_14 = param_1;
      do {
        local_28[0] = 0xffffffff;
        local_28[1] = 0xffffffff;
        local_28[2] = 0xffffffff;
        uVar5 = 0;
        local_28[3] = 0xffffffff;
        if (uVar6 != 0) {
          iVar4 = *(int *)(local_14 + 0x14);
          piVar3 = (int *)(param_2[2] + local_c);
          do {
            local_28[uVar5] = *(uint *)(*(int *)(iVar4 + *piVar3 * 4) + 0xc);
            uVar5 = uVar5 + 1;
            piVar3 = piVar3 + 1;
          } while (uVar5 < uVar6);
        }
        if (iVar1 << 0x1e < 0) {
          uVar5 = 0;
          local_8 = &DAT_006df5c8;
          do {
            iVar4 = FUN_0060dde6(local_28,local_8);
            if (iVar4 != 0) break;
            local_8 = local_8 + 4;
            uVar5 = uVar5 + 1;
          } while (uVar5 < 8);
          if (uVar5 == 8) {
            return 1;
          }
        }
        local_10 = local_10 + 1;
        local_c = local_c + uVar6 * 4;
      } while (local_10 < local_28[4]);
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ==== 0x60ed62 FUN_0060ed62

int __fastcall FUN_0060ed62(int *param_1)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  void *pvVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int local_7c [4];
  int local_6c [4];
  int local_5c [4];
  int local_4c [4];
  int local_3c [5];
  uint local_28;
  uint local_24;
  uint *local_20;
  int *local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  if (*(int *)param_1[0x26] != 0x30000002) {
    return 1;
  }
  local_3c[4] = *(int *)((int *)param_1[0x26])[4];
  iVar7 = *(int *)(param_1[5] + local_3c[4] * 4);
  local_8 = 0;
  local_14 = 0;
  uVar3 = *(uint *)(iVar7 + 0x38);
  local_20 = *(uint **)(param_1[6] + uVar3 * 4);
  if (((*local_20 & 0xff000000) == 0x24000000) &&
     (((*(uint *)(iVar7 + 0x34) <= (uint)param_1[0x25] || (uVar3 <= *(uint *)(iVar7 + 0x34))) &&
      (uVar3 == *(uint *)(iVar7 + 0x3c))))) {
    local_28 = *local_20 & 0xffffff;
    local_1c = (int *)0x0;
    if (local_20[1] != 0) {
      piVar6 = (int *)local_20[2];
      do {
        piVar2 = *(int **)(param_1[5] + *piVar6 * 4);
        if (param_1[0x18] == *piVar2) {
          if ((((uint)param_1[0x25] < (uint)piVar2[0xd]) && ((uint)piVar2[0xd] < (uint)piVar2[0xe]))
             || ((uint)param_1[0x25] < (uint)piVar2[0xb])) goto LAB_0060f0db;
        }
        local_1c = (int *)((int)local_1c + 1);
        piVar6 = piVar6 + 1;
      } while (local_1c < (int *)local_20[1]);
    }
    local_c = 0;
    local_10 = 0;
    local_18 = 0;
    if (local_28 != 0) {
      piVar2 = (int *)local_20[2];
      local_1c = piVar2 + local_28;
      piVar6 = local_7c + local_28 + 3;
      iVar7 = local_20[4] - (int)piVar2;
      local_24 = local_28;
      do {
        uVar1 = local_c;
        uVar3 = local_18;
        if (*piVar2 == local_3c[4]) {
          iVar8 = *local_1c;
LAB_0060ee8c:
          local_c = local_c + 1;
          local_3c[uVar1] = iVar8;
          uVar3 = local_10;
          local_10 = local_10 + 1;
          local_4c[uVar3] = *(int *)(iVar7 + (int)piVar2);
        }
        else {
          if (*local_1c == local_3c[4]) {
            iVar8 = *piVar2;
            goto LAB_0060ee8c;
          }
          local_18 = local_18 + 1;
          local_7c[uVar3] = *(int *)(iVar7 + (int)piVar2);
          local_5c[uVar3] = *piVar2;
          *piVar6 = *local_1c;
          piVar6 = piVar6 + 1;
        }
        local_1c = local_1c + 1;
        piVar2 = piVar2 + 1;
        local_24 = local_24 - 1;
      } while (local_24 != 0);
    }
    uVar3 = 1;
    if (1 < local_c) {
      do {
        if (local_3c[uVar3] != local_3c[0]) goto LAB_0060f0db;
        uVar3 = uVar3 + 1;
      } while (uVar3 < local_c);
    }
    local_24 = *(uint *)(param_1[5] + local_3c[0] * 4);
    if (*(uint *)(local_24 + 0x2c) < (uint)param_1[0x25]) goto LAB_0060f0db;
    uVar3 = 0;
    if (local_10 != 0) {
      do {
        local_24 = *(uint *)(param_1[5] + local_4c[uVar3] * 4);
        if ((uint)param_1[0x25] < *(uint *)(local_24 + 0x30)) goto LAB_0060f0db;
        uVar3 = uVar3 + 1;
      } while (uVar3 < local_10);
    }
    if (local_18 == local_28) goto LAB_0060f0db;
    if (local_18 != 0) {
      pvVar4 = _malloc(0x38);
      if (pvVar4 == (void *)0x0) {
        local_14 = 0;
      }
      else {
        local_14 = FUN_005f7709();
      }
      if (local_14 == 0) {
        return -0x7ff8fff2;
      }
      iVar7 = FUN_005f7760(local_18 & 0xffffff | 0x24000000,local_18 * 2,local_18,0);
      if ((iVar7 < 0) || (iVar7 = FUN_005f7a42(), iVar7 < 0)) goto LAB_0060f225;
      local_28 = local_18 * 4;
      piVar6 = local_5c;
      piVar2 = *(int **)(local_14 + 8);
      for (uVar3 = local_18 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *piVar2 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar2 = piVar2 + 1;
      }
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(char *)piVar2 = (char)*piVar6;
        piVar6 = (int *)((int)piVar6 + 1);
        piVar2 = (int *)((int)piVar2 + 1);
      }
      piVar6 = local_7c + 4;
      piVar2 = (int *)(*(int *)(local_14 + 8) + local_18 * 4);
      for (uVar3 = local_18 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *piVar2 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar2 = piVar2 + 1;
      }
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(char *)piVar2 = (char)*piVar6;
        piVar6 = (int *)((int)piVar6 + 1);
        piVar2 = (int *)((int)piVar2 + 1);
      }
      piVar6 = local_7c;
      piVar2 = *(int **)(local_14 + 0x10);
      for (uVar3 = local_18 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *piVar2 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar2 = piVar2 + 1;
      }
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(char *)piVar2 = (char)*piVar6;
        piVar6 = (int *)((int)piVar6 + 1);
        piVar2 = (int *)((int)piVar2 + 1);
      }
    }
    pvVar4 = _malloc(0x38);
    if (pvVar4 == (void *)0x0) {
      local_8 = 0;
    }
    else {
      local_8 = FUN_005f7709();
    }
    iVar8 = local_8;
    if (local_8 != 0) {
      iVar7 = FUN_005f7760(0xfa000002,6,local_10,0);
      if ((-1 < iVar7) && (iVar7 = FUN_005f7a42(), -1 < iVar7)) {
        piVar6 = local_4c;
        piVar2 = *(int **)(iVar8 + 0x10);
        for (uVar3 = local_10; uVar3 != 0; uVar3 = uVar3 - 1) {
          *piVar2 = *piVar6;
          piVar6 = piVar6 + 1;
          piVar2 = piVar2 + 1;
        }
        uVar3 = 0;
        do {
          *(undefined4 *)(uVar3 + *(int *)(local_8 + 8)) =
               *(undefined4 *)(uVar3 + *(int *)(param_1[0x26] + 8));
          uVar3 = uVar3 + 4;
        } while (uVar3 < 0x10);
        *(int *)(*(int *)(local_8 + 8) + 0x10) = local_3c[0];
        *(int *)(*(int *)(local_8 + 8) + 0x14) = local_3c[0];
        iVar7 = (**(code **)(*param_1 + 0x24))(local_8);
        if ((iVar7 == 0) && (iVar7 = FUN_0060ec98(), iVar7 == 0)) {
          if (*(int *)(param_1[6] + param_1[0x25] * 4) != 0) {
            FUN_005f7186();
          }
          iVar7 = local_14;
          uVar3 = local_24;
          *(int *)(param_1[6] + param_1[0x25] * 4) = local_8;
          if (local_14 == 0) {
            *local_20 = 0;
          }
          else {
            if (*(int *)(param_1[6] + *(int *)(local_24 + 0x38) * 4) != 0) {
              FUN_005f7186();
            }
            *(int *)(param_1[6] + *(int *)(uVar3 + 0x38) * 4) = iVar7;
          }
          return 0;
        }
        goto LAB_0060f0db;
      }
      goto LAB_0060f21b;
    }
  }
  else {
LAB_0060f0db:
    if (param_1[0x4d] == -1) {
      uVar5 = FUN_005f7478(&DAT_0069ecd8,0x189,1,4);
      iVar7 = FUN_005f74cf(uVar5,0,0,0);
      param_1[0x4d] = iVar7;
      iVar7 = FUN_005f74cf(uVar5,0,1,0x3ff0000000000000);
      param_1[0x4e] = iVar7;
    }
    if (local_8 != 0) {
      FUN_005f7186();
    }
    pvVar4 = _malloc(0x38);
    if (pvVar4 == (void *)0x0) {
      local_8 = 0;
    }
    else {
      local_8 = FUN_005f7709();
    }
    if (local_8 != 0) {
      iVar7 = FUN_005f7760(0xfa000002,6,1,0);
      if ((-1 < iVar7) && (iVar7 = FUN_005f7a42(), iVar8 = local_8, -1 < iVar7)) {
        **(int **)(local_8 + 0x10) = local_3c[4];
        uVar3 = 0;
        do {
          *(undefined4 *)(uVar3 + *(int *)(local_8 + 8)) =
               *(undefined4 *)(uVar3 + *(int *)(param_1[0x26] + 8));
          uVar3 = uVar3 + 4;
        } while (uVar3 < 0x10);
        *(int *)(*(int *)(local_8 + 8) + 0x10) = param_1[0x4d];
        *(int *)(*(int *)(local_8 + 8) + 0x14) = param_1[0x4d];
        iVar7 = (**(code **)(*param_1 + 0x24))(local_8,0);
        if ((iVar7 == 0) && (iVar7 = FUN_0060ec98(), iVar7 == 0)) {
          if (*(int *)(param_1[6] + param_1[0x25] * 4) != 0) {
            FUN_005f7186();
          }
          *(int *)(param_1[6] + param_1[0x25] * 4) = iVar8;
          iVar7 = 0;
          goto LAB_0060f225;
        }
        iVar7 = 1;
      }
LAB_0060f21b:
      FUN_005f7186();
      goto LAB_0060f225;
    }
  }
  iVar7 = -0x7ff8fff2;
LAB_0060f225:
  if (local_14 != 0) {
    FUN_005f7186();
  }
  return iVar7;
}


// ==== 0x60f23a FUN_0060f23a

undefined4 __fastcall FUN_0060f23a(int *param_1)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  bool bVar11;
  uint *puVar12;
  int local_34;
  uint local_30;
  uint local_2c;
  uint local_28 [6];
  undefined4 local_10 [4];
  
  uVar1 = param_1[3];
  iVar8 = 0;
  local_2c = 0;
  if (uVar1 != 0) {
    do {
      param_1[0x25] = local_2c;
      puVar12 = *(uint **)(param_1[6] + local_2c * 4);
      param_1[0x26] = (int)puVar12;
      uVar3 = *puVar12 & 0xff000000;
      if ((((((uVar3 == 0x44000000) || (uVar3 == 0x4c000000)) || (uVar3 == 0x48000000)) ||
           (((uVar3 == 0x42000000 || (uVar3 == 0x46000000)) ||
            ((uVar3 == 0x4a000000 || ((uVar3 == 0x4e000000 || (uVar3 == 0x43000000)))))))) ||
          (uVar3 == 0x47000000)) ||
         ((((uVar3 == 0x4b000000 || (uVar3 == 0x4f000000)) || (uVar3 == 0x40000000)) ||
          (uVar3 == 0x34000000)))) {
        uVar6 = *puVar12 & 0xffffff;
        local_28[0] = uVar6;
        if (uVar3 == 0x34000000) {
          local_28[0] = 0;
        }
        local_30 = 0;
        if (uVar6 != 0) {
          piVar7 = (int *)(puVar12[2] + local_28[0] * 4);
          do {
            piVar2 = *(int **)(param_1[5] + *piVar7 * 4);
            if ((piVar2[3] != local_30) || ((*(byte *)((int)piVar2 + 0x22) & 0xf) != 0)) break;
            if (*piVar2 == param_1[0x16]) {
              bVar11 = (char)piVar2[0x14] == '\x03';
            }
            else {
              bVar11 = *piVar2 == param_1[0x18];
            }
            if (!bVar11) break;
            local_30 = local_30 + 1;
            piVar7 = piVar7 + 1;
          } while (local_30 < uVar6);
        }
        if (((*puVar12 & 0xff000000) == 0x40000000) && (uVar6 == 1)) {
          iVar8 = (**(code **)(*param_1 + 0x6c))(local_2c,local_28 + 2,4,0,0);
          if (iVar8 < 0) {
            return 0;
          }
          pvVar4 = _malloc(0x38);
          if (pvVar4 == (void *)0x0) {
            local_34 = 0;
          }
          else {
            local_34 = FUN_005f7709();
          }
          if (local_34 == 0) {
            return 0x8007000e;
          }
          iVar8 = FUN_005f7760(0x10000002,2,2,0);
          if ((iVar8 < 0) || (iVar8 = FUN_005f7a42(param_1[0x26]), iVar8 < 0)) goto LAB_0060f8b7;
          **(undefined4 **)(local_34 + 8) = *(undefined4 *)(*(int *)(param_1[0x26] + 8) + 4);
          *(undefined4 *)(*(int *)(local_34 + 8) + 4) =
               *(undefined4 *)(*(int *)(param_1[0x26] + 8) + 4);
          **(undefined4 **)(local_34 + 0x10) = local_28[2];
          *(uint *)(*(int *)(local_34 + 0x10) + 4) = local_28[3];
          iVar8 = FUN_005f73c0(local_34);
          if (iVar8 < 0) goto LAB_0060f8b7;
          pvVar4 = _malloc(0x38);
          if (pvVar4 == (void *)0x0) {
            iVar8 = 0;
          }
          else {
            iVar8 = FUN_005f7709();
          }
          if (iVar8 == 0) {
            return 0;
          }
          iVar5 = FUN_005f7760(0x44000002,4,*(undefined4 *)(param_1[0x26] + 0xc),0);
          if ((iVar5 < 0) || (iVar5 = FUN_005f7a42(param_1[0x26]), iVar5 < 0)) goto LAB_0060f8bf;
          uVar3 = 8;
          do {
            *(undefined4 *)(*(int *)(iVar8 + 8) + -8 + uVar3) = **(undefined4 **)(param_1[0x26] + 8)
            ;
            *(undefined4 *)(uVar3 + *(int *)(iVar8 + 8)) = *(undefined4 *)((int)local_28 + uVar3);
            uVar3 = uVar3 + 4;
          } while (uVar3 < 0x10);
          puVar9 = *(undefined4 **)(param_1[0x26] + 0x10);
          puVar10 = *(undefined4 **)(iVar8 + 0x10);
          for (uVar3 = *(uint *)(param_1[0x26] + 0xc) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
            puVar9 = (undefined4 *)((int)puVar9 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
          if (param_1[0x26] != 0) {
            FUN_005f7186(1);
          }
          *(int *)(param_1[6] + local_2c * 4) = iVar8;
          param_1[0x26] = iVar8;
        }
        else if (local_30 != uVar6) {
          iVar8 = (**(code **)(*param_1 + 0x6c))(local_2c,local_10,4,0,0);
          if (iVar8 < 0) {
            return 0;
          }
          pvVar4 = _malloc(0x38);
          if (pvVar4 == (void *)0x0) {
            local_34 = 0;
          }
          else {
            local_34 = FUN_005f7709();
          }
          if (local_34 == 0) {
            return 0x8007000e;
          }
          iVar8 = FUN_005f7760(uVar6 | 0x10000000,uVar6,uVar6,0);
          if ((iVar8 < 0) || (iVar8 = FUN_005f7a42(param_1[0x26]), iVar8 < 0)) goto LAB_0060f8b7;
          uVar3 = 0;
          if (uVar6 != 0) {
            iVar8 = local_28[0] << 2;
            do {
              iVar5 = uVar3 * 4;
              *(undefined4 *)(iVar5 + *(int *)(local_34 + 8)) =
                   *(undefined4 *)(iVar8 + *(int *)(param_1[0x26] + 8));
              *(undefined4 *)(iVar5 + *(int *)(local_34 + 0x10)) = local_10[uVar3];
              *(undefined4 *)(iVar8 + *(int *)(param_1[0x26] + 8)) =
                   *(undefined4 *)(iVar5 + *(int *)(local_34 + 0x10));
              uVar3 = uVar3 + 1;
              iVar8 = iVar8 + 4;
            } while (uVar3 < uVar6);
          }
          iVar8 = FUN_005f73c0(local_34);
          if (iVar8 < 0) goto LAB_0060f8b7;
        }
        puVar12 = (uint *)param_1[0x26];
      }
      iVar8 = FUN_005f75cb(puVar12);
      if (iVar8 < 0) {
        return 0;
      }
      *(undefined4 *)param_1[0x26] = 0;
      local_2c = local_2c + 1;
    } while (local_2c < uVar1);
  }
  local_34 = 0;
  uVar1 = param_1[3];
  if ((*(byte *)(param_1 + 0x24) & 2) != 0) {
    FUN_0061674c();
    uVar3 = 0;
    if (uVar1 != 0) {
      do {
        iVar5 = *(int *)(param_1[6] + uVar3 * 4);
        param_1[0x26] = iVar5;
        param_1[0x25] = uVar3;
        if ((*(char *)(iVar5 + 3) != '\0') && (iVar8 = FUN_0060e0d8(), iVar8 < 0)) {
          return 0;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar1);
    }
  }
  FUN_0061674c();
  uVar1 = param_1[3];
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      param_1[0x25] = uVar3;
      iVar5 = *(int *)(param_1[6] + uVar3 * 4);
      param_1[0x26] = iVar5;
      iVar5 = *(int *)(iVar5 + 0x34);
      if ((iVar5 != 0) && (*(int *)(iVar5 + 4) == 0xc)) {
        param_1[0x27] = iVar5 + 0x30;
      }
      iVar5 = FUN_005f7a96();
      if (((iVar5 == 0) && (*(int *)(param_1[0x26] + 4) != 0)) &&
         (*(int *)(*(int *)(param_1[5] + **(int **)(param_1[0x26] + 8) * 4) + 4) != -1)) {
        FUN_005fbec8(param_1,*(undefined4 *)(param_1[0x26] + 0x34),0x119f,
                     "relative addressing not allowed for pixel shaders");
        return 0;
      }
      uVar6 = *(uint *)param_1[0x26] & 0xff000000;
      if (uVar6 < 0x43000001) {
        if (uVar6 == 0x43000000) goto LAB_0060f8d0;
        if (uVar6 < 0x21000001) {
          if (uVar6 == 0x21000000) {
            iVar8 = FUN_0060d294();
          }
          else if (uVar6 < 0x13000001) {
            if (uVar6 == 0x13000000) {
              iVar8 = FUN_0061b204();
            }
            else if (uVar6 != 0) {
              if (uVar6 == 0x10000000) {
                iVar8 = FUN_0061b0f2();
              }
              else if (uVar6 == 0x11000000) {
                iVar8 = FUN_0061a926();
              }
              else {
                if (uVar6 != 0x12000000) goto LAB_0060f89b;
                iVar8 = FUN_0061b1e6();
              }
            }
          }
          else if (uVar6 == 0x14000000) {
            iVar8 = FUN_0061b20c();
          }
          else if (uVar6 == 0x15000000) {
            iVar8 = FUN_0061b22a();
          }
          else if (uVar6 == 0x16000000) {
            iVar8 = FUN_0061b248();
          }
          else {
            if (uVar6 != 0x20000000) goto LAB_0060f89b;
            iVar8 = FUN_0060d3be();
          }
        }
        else if (uVar6 < 0x30000001) {
          if (uVar6 == 0x30000000) {
            iVar8 = FUN_0061b2fa();
          }
          else if (uVar6 == 0x22000000) {
            iVar8 = FUN_0060d1c2();
          }
          else if (uVar6 == 0x23000000) {
            iVar8 = FUN_0060d0f0();
          }
          else if (uVar6 == 0x24000000) {
            iVar8 = FUN_0061b2e2();
          }
          else {
            if (uVar6 != 0x25000000) goto LAB_0060f89b;
            iVar8 = FUN_0061b2ea();
          }
        }
        else {
          if (uVar6 != 0x34000000) {
            if (uVar6 == 0x40000000) goto LAB_0060f873;
            if (uVar6 != 0x42000000) goto LAB_0060f89b;
            goto LAB_0060f821;
          }
          iVar8 = FUN_0061a7fa();
        }
      }
      else if (uVar6 < 0x50000001) {
        if (uVar6 == 0x50000000) {
          iVar8 = FUN_0061b3a4();
        }
        else if (uVar6 < 0x4a000001) {
          if (uVar6 == 0x4a000000) {
LAB_0060f821:
            iVar8 = FUN_0061a6fd();
          }
          else {
            if (uVar6 != 0x44000000) {
              if (uVar6 == 0x46000000) goto LAB_0060f821;
              if (uVar6 == 0x47000000) goto LAB_0060f8d0;
              if (uVar6 != 0x48000000) goto LAB_0060f89b;
            }
LAB_0060f873:
            iVar8 = FUN_0061a69c();
          }
        }
        else {
          if (uVar6 != 0x4b000000) {
            if (uVar6 == 0x4c000000) goto LAB_0060f873;
            if (uVar6 == 0x4e000000) goto LAB_0060f821;
            if (uVar6 != 0x4f000000) goto LAB_0060f89b;
          }
LAB_0060f8d0:
          iVar8 = FUN_0061a761();
        }
      }
      else if (uVar6 < 0xf4000001) {
        if (uVar6 == 0xf4000000) {
LAB_0060f909:
          iVar8 = FUN_0061b3b4();
        }
        else if (uVar6 == 0xf0000000) {
          iVar8 = FUN_0061b3ac();
        }
        else if (uVar6 == 0xf1000000) {
          iVar8 = FUN_0061aa11();
        }
        else {
          if (uVar6 != 0xf2000000) {
            if (uVar6 != 0xf3000000) goto LAB_0060f89b;
            goto LAB_0060f909;
          }
          iVar8 = FUN_0061ab23();
        }
      }
      else if ((uVar6 == 0xf5000000) || (uVar6 == 0xf6000000)) {
        iVar8 = FUN_0061abc1();
      }
      else {
        if (uVar6 != 0xfa000000) goto LAB_0060f89b;
        iVar8 = FUN_0061a7c5();
      }
      if (iVar8 == -0x7fffbfff) {
LAB_0060f89b:
        FUN_005fbec8(param_1,*(undefined4 *)(param_1[0x26] + 0x34),0x11b4,
                     "cannot map expression to pixel shader instruction set");
LAB_0060f8b7:
        if (local_34 == 0) {
          return 0;
        }
LAB_0060f8bf:
        FUN_005f7186(1);
        return 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return 0;
}


// ==== 0x60f995 FUN_0060f995

int __fastcall FUN_0060f995(int param_1)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  
  *(undefined4 *)(param_1 + 0x134) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x138) = 0xffffffff;
  uVar8 = 0;
  iVar4 = param_1;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      *(uint *)(param_1 + 0x94) = uVar8;
      puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + uVar8 * 4);
      *(uint **)(param_1 + 0x98) = puVar1;
      if ((*(byte *)(param_1 + 0x34) & 8) == 0) {
        uVar3 = *puVar1 & 0xff000000;
        if (uVar3 < 0x24000001) {
          if (uVar3 == 0x24000000) {
            iVar4 = FUN_00618709();
          }
          else if (uVar3 == 0x11000000) {
            iVar4 = FUN_006178e1();
          }
          else if (uVar3 == 0x16000000) {
            iVar4 = FUN_00618431();
          }
          else {
            if ((uVar3 != 0x20000000) && (uVar3 != 0x21000000)) goto LAB_0060fa3c;
            iVar4 = FUN_006169a4();
          }
        }
        else if (uVar3 == 0x25000000) {
          iVar4 = FUN_00618a35();
        }
        else if (uVar3 == 0x30000000) {
          iVar4 = FUN_0060ed62();
        }
        else {
          if (uVar3 != 0x50000000) {
LAB_0060fa3c:
            iVar4 = 1;
            goto LAB_0060fa72;
          }
          iVar4 = FUN_006169a4();
          if (iVar4 == 1) {
            iVar4 = FUN_00614ca2();
          }
        }
        if (iVar4 < 0) {
          return iVar4;
        }
      }
LAB_0060fa72:
      *(uint *)(param_1 + 0x94) = uVar8;
      puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + uVar8 * 4);
      *(uint **)(param_1 + 0x98) = puVar1;
      uVar3 = *puVar1 & 0xff000000;
      if (((uVar3 == 0x23000000) || (uVar3 == 0x22000000)) && (*(int *)(param_1 + 0x134) == -1)) {
        uVar5 = FUN_005f7478(&DAT_0069ecd8,0x189,1,4);
        uVar6 = FUN_005f74cf(uVar5,0,0,0);
        *(undefined4 *)(param_1 + 0x134) = uVar6;
        uVar5 = FUN_005f74cf(uVar5,0,1,0x3ff0000000000000);
        *(undefined4 *)(param_1 + 0x138) = uVar5;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(param_1 + 0xc));
  }
  FUN_0061674c();
  if ((*(byte *)(param_1 + 0x34) & 8) == 0) {
    uVar8 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      do {
        *(uint *)(param_1 + 0x94) = uVar8;
        puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + uVar8 * 4);
        *(uint **)(param_1 + 0x98) = puVar1;
        uVar3 = *puVar1 & 0xff000000;
        if (uVar3 == 0x24000000) {
          iVar4 = FUN_00617905();
LAB_0060fb49:
          if (iVar4 < 0) {
            return iVar4;
          }
        }
        else {
          if (uVar3 == 0x50000000) {
            iVar4 = FUN_006142b6();
            goto LAB_0060fb49;
          }
          iVar4 = 1;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(uint *)(param_1 + 0xc));
    }
    uVar8 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      do {
        *(uint *)(param_1 + 0x94) = uVar8;
        puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + uVar8 * 4);
        *(uint **)(param_1 + 0x98) = puVar1;
        uVar3 = *puVar1;
        uVar7 = uVar3 & 0xff000000;
        if (((uVar7 == 0x12000000) || (uVar7 == 0x14000000)) || (uVar7 == 0x15000000)) {
LAB_0060fbcc:
          iVar4 = FUN_00614682();
LAB_0060fbd5:
          if (iVar4 < 0) {
            return iVar4;
          }
        }
        else {
          if (uVar7 == 0x30000000) {
            if (2 < (uVar3 & 0xffffff)) goto LAB_0060fbcc;
            goto LAB_0060fbd5;
          }
          if ((uVar7 == 0xf3000000) || (uVar7 == 0xf4000000)) goto LAB_0060fbcc;
          if (uVar7 == 0xf5000000) {
            FUN_0061858f();
            iVar4 = FUN_006151a7();
            goto LAB_0060fbd5;
          }
          iVar4 = 1;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(uint *)(param_1 + 0xc));
    }
  }
  FUN_0061674c();
  uVar8 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      piVar2 = *(int **)(*(int *)(param_1 + 0x14) + uVar8 * 4);
      if ((((piVar2[0xe] == -1) &&
           ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4) + 4) & 0x80) != 0)) &&
          (*(uint *)(param_1 + 0x138) != uVar8)) && (*(uint *)(param_1 + 0x134) != uVar8)) {
        *piVar2 = *(int *)(param_1 + 0x4c);
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(param_1 + 8));
  }
  return 0;
}


// ==== 0x60fc2c FUN_0060fc2c

undefined4 __fastcall FUN_0060fc2c(int param_1)

{
  uint uVar1;
  
  *(undefined4 *)(param_1 + 0x6c) = 0x10;
  *(undefined4 *)(param_1 + 0x80) = 0x10;
  uVar1 = *(uint *)(param_1 + 0x30) & 0xffff;
  if (uVar1 < 0x201) {
    *(undefined4 *)(param_1 + 0x70) = 0xc;
  }
  else {
    *(undefined4 *)(param_1 + 0x70) = 0x20;
  }
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  if (uVar1 < 0x200) {
    *(byte *)(param_1 + 0x92) = *(byte *)(param_1 + 0x92) | 0x80;
    *(undefined4 *)(param_1 + 0x74) = 0;
  }
  else {
    *(byte *)(param_1 + 0x92) = *(byte *)(param_1 + 0x92) & 0x7f;
    *(undefined4 *)(param_1 + 0x74) = 1;
  }
  *(undefined4 *)(param_1 + 0x78) = 0x2000;
  *(uint *)(param_1 + 0x90) = *(uint *)(param_1 + 0x90) & 0xfaaeffc0 | 0x40;
  return 0;
}


// ==== 0x60fcaa FUN_0060fcaa

uint __fastcall FUN_0060fcaa(int param_1)

{
  short sVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int local_28 [9];
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0xec) == 0) {
    local_28[0] = 0;
    local_28[1] = 0;
    local_28[2] = 0;
    local_28[6] = 0;
    local_28[5] = 0;
    local_28[7] = 0;
    local_28[4] = 0;
    local_28[3] = 0;
    local_28[8] = 0;
    if (*(int *)(param_1 + 8) != 0) {
      do {
        piVar2 = *(int **)(*(int *)(param_1 + 0x14) + local_28[8] * 4);
        if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4) + 4) & 0x10) != 0) {
          sVar1 = *(short *)((int)piVar2 + 0x52);
          uVar3 = piVar2[0x14] & 0xffff;
          if (uVar3 == 1) {
            if (sVar1 == 0) {
              iVar4 = piVar2[0x11];
              local_28[piVar2[3]] = 1;
              local_28[4] = iVar4;
            }
          }
          else if (uVar3 == 5) {
            if (((sVar1 == 0) && (piVar2[3] != 0)) && (local_28[5] == 0)) {
              FUN_005fbec8(param_1,piVar2[0x11],0x11bc,"PSIZE must be a scalar");
              local_28[5] = 1;
              goto LAB_0060fd3d;
            }
          }
          else if (((uVar3 == 0xc) && (sVar1 == 0)) && ((piVar2[3] != 0 && (local_28[6] == 0)))) {
            FUN_005fbec8(param_1,piVar2[0x11],0x11bc,"FOG must be a scalar");
            local_28[6] = 1;
LAB_0060fd3d:
            local_28[7] = 1;
          }
        }
        local_28[8] = local_28[8] + 1;
      } while ((uint)local_28[8] < *(uint *)(param_1 + 8));
    }
    iVar4 = 0;
    uVar3 = 0;
    do {
      if (local_28[uVar3] != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 4);
    if (iVar4 != 4) {
      FUN_005fbec8(param_1,local_28[4],0x11bd,
                   "vertex shader must minimally write all four components of POSITION");
      local_28[7] = 1;
    }
    uVar3 = -(uint)(local_28[7] != 0) & 0x80004005;
  }
  return uVar3;
}


// ==== 0x60fdc9 FUN_0060fdc9

undefined4 FUN_0060fdc9(int param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x50);
  *param_2 = (uint)*(ushort *)(param_1 + 0x52);
  uVar1 = uVar1 & 0xffff;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (uVar1 == 1) {
    if (*param_2 != 0) {
      return 0x80004005;
    }
    *param_3 = 4;
    *param_2 = 0;
    return 0;
  }
  if (uVar1 == 5) {
    if (*param_2 != 0) {
      return 0x80004005;
    }
    *param_3 = 4;
    *param_2 = 2;
  }
  else {
    if (uVar1 != 0xc) {
      if (uVar1 == 0xb) {
        if (1 < *param_2) {
          return 0x80004005;
        }
        *param_3 = 5;
        return 0;
      }
      if (uVar1 == 6) {
        if (*param_2 < 8) {
          *param_3 = 6;
          return 0;
        }
        return 0x80004005;
      }
      if (uVar1 != 0xffff) {
        return 0x80004005;
      }
      *param_3 = 0;
      return 0;
    }
    if (*param_2 != 0) {
      return 0x80004005;
    }
    *param_3 = 4;
    *param_2 = 1;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 1;
  }
  return 0;
}


// ==== 0x60fe81 FUN_0060fe81

undefined4 FUN_0060fe81(int param_1,uint *param_2,undefined4 *param_3)

{
  uint uVar1;
  
  if ((*(uint *)(param_1 + 0x50) & 0xffff) == 0xffff) {
    *param_3 = 0;
    uVar1 = (uint)*(ushort *)(param_1 + 0x52);
  }
  else {
    *param_3 = 1;
    uVar1 = *(uint *)(param_1 + 8);
  }
  *param_2 = uVar1;
  return 0;
}


// ==== 0x60feb5 FUN_0060feb5

void __fastcall FUN_0060feb5(int param_1)

{
  *(uint *)(param_1 + 0xe8) = (uint)(0x100 < (*(uint *)(param_1 + 0x30) & 0xffff));
  FUN_00619954();
  return;
}


// ==== 0x60fed3 FUN_0060fed3

undefined4 __fastcall FUN_0060fed3(int param_1)

{
  uint *puVar1;
  
  if (0x1ff < (*(uint *)(param_1 + 0x30) & 0xffff)) {
    puVar1 = (uint *)(*(int *)(param_1 + 0xa0) + *(int *)(param_1 + 0xac) * 4);
    *puVar1 = *puVar1 | ((*(int *)(param_1 + 0xa4) - *(int *)(param_1 + 0xac)) + -1) * 0x1000000;
  }
  return 0;
}


// ==== 0x60ff02 FUN_0060ff02

int __fastcall FUN_0060ff02(int *param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  undefined4 *puVar11;
  int *piVar12;
  int iVar13;
  undefined4 *puVar14;
  bool bVar15;
  int local_78 [8];
  undefined1 local_58 [4];
  int *local_54;
  int *local_50;
  uint local_4c;
  uint local_48;
  undefined4 *local_44;
  undefined4 *local_40;
  uint local_3c;
  undefined4 *local_38;
  int *local_34;
  uint local_30;
  uint local_2c;
  int local_28;
  uint *local_24;
  uint local_20;
  uint *local_1c;
  uint *local_18;
  int *local_14;
  uint local_10;
  uint local_c;
  int *local_8;
  
  puVar1 = (uint *)param_1[0x26];
  uVar8 = *puVar1 & 0xffffff;
  local_18 = puVar1;
  local_c = uVar8;
  if (2 < uVar8) {
    local_1c = (uint *)FUN_0061556b(0x10000002,puVar1,0,2,1);
    if ((((local_1c != (uint *)0x0) ||
         (local_1c = (uint *)FUN_0061556b(0x10000003,puVar1,0,2,1), local_1c != (uint *)0x0)) ||
        (local_1c = (uint *)FUN_0061556b(0x10000004,puVar1,0,2,1), local_1c != (uint *)0x0)) &&
       (**(int **)(param_1[5] + *(int *)local_1c[4] * 4) == param_1[0x17])) {
      local_38 = (undefined4 *)0x1;
      uVar10 = local_3c;
      if ((*local_1c & 0xffffff) == 0) {
LAB_0060ffdb:
        local_3c = uVar10;
        pvVar4 = _malloc(0x38);
        if (pvVar4 == (void *)0x0) {
          local_10 = 0;
        }
        else {
          local_10 = FUN_005f7709();
        }
        if (local_10 != 0) {
          iVar5 = FUN_005f7760(uVar8 | 0x30000000,puVar1[1],local_1c[3],0);
          if ((-1 < iVar5) && (iVar5 = FUN_005f7a42(puVar1), -1 < iVar5)) {
            puVar7 = (undefined4 *)local_1c[4];
            puVar11 = *(undefined4 **)(local_10 + 0x10);
            for (uVar8 = *(uint *)(local_10 + 0xc) & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
              *puVar11 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar11 = puVar11 + 1;
            }
            for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
              *(undefined1 *)puVar11 = *(undefined1 *)puVar7;
              puVar7 = (undefined4 *)((int)puVar7 + 1);
              puVar11 = (undefined4 *)((int)puVar11 + 1);
            }
            puVar7 = (undefined4 *)local_18[2];
            puVar11 = *(undefined4 **)(local_10 + 8);
            for (uVar8 = *(uint *)(local_10 + 4) & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
              *puVar11 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar11 = puVar11 + 1;
            }
            for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
              *(undefined1 *)puVar11 = *(undefined1 *)puVar7;
              puVar7 = (undefined4 *)((int)puVar7 + 1);
              puVar11 = (undefined4 *)((int)puVar11 + 1);
            }
            *local_1c = 0;
            if (param_1[0x26] != 0) {
              FUN_005f7186(1);
            }
            *(uint *)(param_1[6] + param_1[0x25] * 4) = local_10;
            param_1[0x26] = local_10;
            return 0;
          }
          FUN_005f7186(1);
          return iVar5;
        }
        return -0x7ff8fff2;
      }
      local_50 = *(int **)puVar1[4];
      puVar7 = (undefined4 *)local_1c[2];
      local_3c = *local_1c & 0xffffff;
      do {
        if (((int *)*puVar7 != local_50) ||
           ((*(uint *)(*(int *)(param_1[5] + (int)*puVar7 * 4) + 0x20) & 0xffe00) != 0)) {
          local_38 = (undefined4 *)0x0;
        }
        puVar7 = puVar7 + 1;
        local_3c = local_3c - 1;
      } while (local_3c != 0);
      local_3c = 0;
      uVar10 = 0;
      if (local_38 != (undefined4 *)0x0) goto LAB_0060ffdb;
    }
    if ((uVar8 == 3) && (0x1ff < (param_1[0xc] & 0xffffU))) {
      local_18 = (uint *)param_1[0x26];
      iVar5 = 3;
      bVar15 = true;
      piVar6 = (int *)local_18[2];
      piVar9 = (int *)local_18[2] + 3;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar15 = *piVar6 == *piVar9;
        piVar6 = piVar6 + 1;
        piVar9 = piVar9 + 1;
      } while (bVar15);
      if ((((bVar15) &&
           (local_34 = (int *)FUN_0061556b(0x16000001,local_18,0,2,1), local_34 != (undefined4 *)0x0
           )) && (local_38 = (undefined4 *)FUN_0061556b(0x12000001,local_34,0,2,1),
                 local_38 != (undefined4 *)0x0)) &&
         ((local_1c = (uint *)FUN_0061556b(0x25000003,local_38,&local_24,2,1),
          local_1c != (uint *)0x0 ||
          (local_1c = (uint *)FUN_0061556b(0x25000004,local_38,&local_24,2,1),
          local_1c != (uint *)0x0)))) {
        piVar6 = *(int **)(param_1[5] + *(int *)local_18[2] * 4);
        local_50 = *(int **)(param_1[5] + *(int *)local_1c[4] * 4);
        local_3c = *local_1c & 0xffffff;
        local_30 = local_3c * 4;
        iVar5 = 3;
        bVar15 = true;
        piVar9 = (int *)(local_1c[2] + local_30);
        piVar12 = (int *)local_18[2];
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar15 = *piVar9 == *piVar12;
          piVar9 = piVar9 + 1;
          piVar12 = piVar12 + 1;
        } while (bVar15);
        if ((bVar15) && ((*piVar6 != *local_50 || (piVar6[2] != local_50[2])))) {
          pvVar4 = _malloc(0x38);
          if (pvVar4 == (void *)0x0) {
            local_10 = 0;
          }
          else {
            local_10 = FUN_005f7709();
          }
          if (local_10 == 0) {
            return -0x7ff8fff2;
          }
          local_50 = (int *)(local_3c & 0xffffff);
          iVar5 = FUN_005f7760((uint)local_50 | 0xf2000000,local_3c,local_3c,0);
          if (iVar5 < 0) {
            return iVar5;
          }
          iVar5 = FUN_005f7a42(local_1c);
          if (iVar5 < 0) {
            return iVar5;
          }
          puVar7 = (undefined4 *)local_1c[4];
          puVar11 = *(undefined4 **)(local_10 + 0x10);
          for (uVar8 = local_30 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *puVar11 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar11 = puVar11 + 1;
          }
          for (uVar8 = local_30 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar7;
            puVar7 = (undefined4 *)((int)puVar7 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          puVar7 = (undefined4 *)(local_1c[2] + local_30);
          puVar11 = *(undefined4 **)(local_10 + 8);
          for (uVar8 = local_30 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *puVar11 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar11 = puVar11 + 1;
          }
          for (uVar8 = local_30 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar7;
            puVar7 = (undefined4 *)((int)puVar7 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          iVar5 = (**(code **)(*param_1 + 0x24))(local_10,0);
          puVar1 = local_1c;
          puVar7 = local_38;
          if (iVar5 == 0) {
            *local_18 = 0;
            *local_34 = 0;
            *local_38 = 0;
            *local_1c = 0;
            iVar5 = (**(code **)(*param_1 + 0x34))(local_10,local_24);
            if (iVar5 == 0) {
              if (*(int *)(param_1[6] + (int)local_24 * 4) != 0) {
                FUN_005f7186(1);
              }
              *(uint *)(param_1[6] + (int)local_24 * 4) = local_10;
              return 0;
            }
            *local_18 = 0x30000003;
            *local_34 = 0x16000001;
            *puVar7 = 0x12000001;
            *puVar1 = (uint)local_50 | 0x25000000;
          }
          FUN_005f7186(1);
        }
      }
    }
  }
  iVar5 = param_1[0x26];
  iVar13 = param_1[5];
  piVar6 = *(int **)(iVar13 + **(int **)(iVar5 + 0x10) * 4);
  piVar9 = *(int **)(iVar5 + 8);
  local_34 = *(int **)(iVar13 + *piVar9 * 4);
  local_1c = (uint *)(local_c * 4);
  local_24 = *(uint **)(iVar13 + piVar9[local_c] * 4);
  local_78[0] = 0;
  local_78[1] = 0;
  local_78[2] = 0;
  local_78[3] = 0;
  local_78[4] = 0;
  local_78[5] = 0;
  local_78[6] = 0;
  local_78[7] = 0;
  iVar13 = piVar6[3];
  local_78[iVar13] = iVar5;
  local_78[iVar13 + 4] = iVar5;
  local_28 = ((local_c != 3) - 1 & 0xfff80000) + 0xf0000;
  local_54 = piVar6;
  (**(code **)(*param_1 + 0x68))(piVar9,local_c,local_28,&local_40);
  (**(code **)(*param_1 + 0x68))
            (*(int *)(param_1[0x26] + 8) + (int)local_1c,local_c,local_28,local_58);
  local_2c = 0;
  if (param_1[0x18] == *piVar6) {
    local_8 = (int *)piVar6[0xe];
  }
  else {
    local_8 = (int *)param_1[3];
  }
  iVar5 = param_1[0x26];
  if (*(int *)(iVar5 + 4) != 0) {
    piVar6 = *(int **)(iVar5 + 8);
    local_3c = *(int *)(iVar5 + 4);
    do {
      piVar9 = *(int **)(param_1[5] + *piVar6 * 4);
      if (param_1[0x18] == *piVar9) {
        if ((uint)piVar9[0xd] < local_8) {
          local_8 = (int *)piVar9[0xd];
        }
        if (local_2c <= (uint)piVar9[0xb]) {
          local_2c = piVar9[0xb] + 1;
        }
      }
      piVar6 = piVar6 + 1;
      local_3c = local_3c + -1;
    } while (local_3c != 0);
  }
  local_50 = (int *)param_1[0x25];
  local_4c = (uint)local_50;
  local_10 = (int)local_50 + 1;
  local_30 = (uint)local_8;
  local_38 = (undefined4 *)local_2c;
  local_3c = (uint)local_8;
  while (local_10 < (uint)param_1[3]) {
    piVar6 = *(int **)(param_1[6] + local_10 * 4);
    if ((*piVar6 == *(int *)param_1[0x26]) && (piVar6[3] == 1)) {
      iVar5 = param_1[5];
      piVar9 = *(int **)(iVar5 + *(int *)piVar6[4] * 4);
      if (((*piVar9 == *local_54) && ((piVar9[1] == local_54[1] && (piVar9[2] == local_54[2])))) &&
         ((local_78[piVar9[3]] == 0 || (local_78[piVar9[3] + 4] == 0)))) {
        local_20 = 0;
        if (param_1[0x18] == *piVar9) {
          local_8 = (int *)piVar9[0xe];
        }
        else {
          local_8 = (int *)param_1[3];
        }
        local_14 = (int *)piVar6[1];
        if (local_14 != (int *)0x0) {
          local_18 = (uint *)piVar6[2];
          do {
            piVar12 = *(int **)(iVar5 + *local_18 * 4);
            if (param_1[0x18] == *piVar12) {
              if ((uint)piVar12[0xd] < local_8) {
                local_8 = (int *)piVar12[0xd];
              }
              if (local_20 <= (uint)piVar12[0xb]) {
                local_20 = piVar12[0xb] + 1;
              }
            }
            local_18 = local_18 + 1;
            local_14 = (int *)((int)local_14 + -1);
          } while (local_14 != (int *)0x0);
        }
        piVar12 = (int *)piVar6[2];
        local_14 = *(int **)(iVar5 + *piVar12 * 4);
        local_18 = *(uint **)(iVar5 + *(int *)((int)piVar12 + (int)local_1c) * 4);
        (**(code **)(*param_1 + 0x68))(piVar12,local_c,local_28,&local_44);
        (**(code **)(*param_1 + 0x68))(piVar6[2] + (int)local_1c,local_c,local_28,&local_48);
        iVar5 = piVar9[3];
        if ((((local_78[iVar5] == 0) && (local_20 < local_30)) && (local_2c < local_8)) &&
           (((((local_44 == local_40 && (*local_14 == *local_34)) &&
              ((local_14[8] == local_34[8] &&
               ((local_14[1] == local_34[1] && (local_14[2] == local_34[2])))))) &&
             (local_48 == 0xe40000)) &&
            (((*local_18 == *local_24 && (local_18[8] == local_24[8])) &&
             (local_18[1] == local_24[1])))))) {
          local_78[iVar5] = (int)piVar6;
          if (local_2c < local_20) {
            local_2c = local_20;
          }
          if (local_8 < local_30) {
            local_30 = (uint)local_8;
          }
          if ((local_2c <= local_10) && (local_10 < local_30)) {
            local_50 = (int *)local_10;
          }
        }
        if ((((local_78[iVar5 + 4] == 0) && (local_20 < local_3c)) &&
            ((local_38 < local_8 &&
             (((((local_44 == local_40 && (*local_14 == *local_34)) && (local_14[8] == local_34[8]))
               && ((local_14[1] == local_34[1] && (local_48 == 0xe40000)))) &&
              (*local_18 == *local_24)))))) &&
           (((local_18[8] == local_24[8] && (local_18[1] == local_24[1])) &&
            (local_18[2] == local_24[2])))) {
          local_78[iVar5 + 4] = (int)piVar6;
          if (local_38 < local_20) {
            local_38 = (undefined4 *)local_20;
          }
          if (local_8 < local_3c) {
            local_3c = (uint)local_8;
          }
          if ((local_38 <= local_10) && (local_10 < local_3c)) {
            local_4c = local_10;
          }
        }
      }
    }
    local_10 = local_10 + 1;
  }
  uVar10 = 0;
  uVar8 = 0;
  do {
    if (local_78[uVar10] == 0) break;
    uVar10 = uVar10 + 1;
  } while (uVar10 < 4);
  do {
    if (local_78[uVar8 + 4] == 0) break;
    uVar8 = uVar8 + 1;
  } while (uVar8 < 4);
  uVar3 = (uint)(uVar10 < uVar8);
  local_8 = local_78 + 4;
  if (uVar3 == 0) {
    local_8 = local_78;
    uVar8 = uVar10;
  }
  local_38 = (undefined4 *)uVar8;
  local_30 = uVar3;
  if (uVar8 < 4) {
    piVar6 = local_8 + uVar8;
    for (iVar5 = 4 - uVar8; iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar6 = 0;
      piVar6 = piVar6 + 1;
    }
  }
  if (local_c == 3) {
    if (uVar8 == 2) {
      local_20 = 0xf7000003;
    }
    else if (uVar8 == 3) {
      local_20 = 0xf8000003;
    }
    else {
      if (uVar8 != 4) {
        return 1;
      }
      local_20 = 0xf9000003;
    }
  }
  else {
    if (local_c != 4) {
      return 1;
    }
    if (uVar8 == 3) {
      local_20 = 0xf8000004;
    }
    else {
      if (uVar8 != 4) {
        return 1;
      }
      local_20 = 0xf9000004;
    }
  }
  local_54 = (int *)(-(uint)(uVar3 != 0) & local_c);
  iVar13 = (~-(uint)(uVar3 != 0) & local_c) * 4;
  piVar6 = (int *)(*(int *)(param_1[0x26] + 8) + iVar13);
  iVar5 = param_1[5];
  local_44 = *(undefined4 **)(iVar5 + *piVar6 * 4);
  uVar8 = 0;
  if (local_c != 0) {
    do {
      local_44 = *(undefined4 **)(iVar5 + *piVar6 * 4);
      if (local_44[3] != uVar8) {
        return 1;
      }
      uVar8 = uVar8 + 1;
      piVar6 = piVar6 + 1;
    } while (uVar8 < local_c);
  }
  uVar8 = 0;
  if (param_1[0x3b] != 0) {
    do {
      if ((local_8[uVar8] != 0) &&
         ((*(byte *)(*(int *)(param_1[4] +
                             **(int **)(iVar5 + *(int *)(iVar13 + *(int *)(local_8[uVar8] + 8)) * 4)
                             * 4) + 5) & 1) == 0)) {
        return 1;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < 4);
  }
  local_48 = 0xffffffff;
  local_24 = (uint *)0xffffffff;
  local_3c = 0xffffffff;
  uVar8 = 0;
  do {
    if (local_8[uVar8] != 0) {
      uVar10 = *(uint *)(*(int *)(iVar5 + *(int *)(iVar13 + *(int *)(local_8[uVar8] + 8)) * 4) + 8);
      if (uVar8 < local_3c) {
        local_3c = uVar8;
      }
      if (uVar10 < local_48) {
        local_48 = uVar10;
      }
    }
    uVar8 = uVar8 + 1;
  } while (uVar8 < 4);
  uVar8 = 0;
  do {
    if (local_8[uVar8] != 0) {
      iVar2 = *(int *)(*(int *)(iVar5 + *(int *)(iVar13 + *(int *)(local_8[uVar8] + 8)) * 4) + 8);
      if (local_24 == (uint *)0xffffffff) {
        local_24 = (uint *)(iVar2 - uVar8);
      }
      else if ((int)local_24 + uVar8 != iVar2) break;
    }
    uVar8 = uVar8 + 1;
  } while (uVar8 < 4);
  local_34 = (int *)iVar13;
  if (uVar8 < 4) {
    local_24 = (uint *)(local_48 - local_3c);
    uVar8 = 0;
    do {
      if (((local_8[uVar8] != 0) &&
          (iVar2 = *(int *)(iVar5 + *(int *)(iVar13 + *(int *)(local_8[uVar8] + 8)) * 4),
          *(int *)(iVar2 + 8) != (int)local_24 + uVar8)) && (*(int *)(iVar2 + 0x1c) != 0)) {
        return 1;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < 4);
    uVar8 = 0;
    do {
      if ((local_8[uVar8] != 0) &&
         (iVar5 = FUN_006154dc(*local_44,
                               *(undefined4 *)
                                (*(int *)(param_1[5] +
                                         *(int *)(iVar13 + *(int *)(local_8[uVar8] + 8)) * 4) + 8),
                               (int)local_24 + uVar8), iVar5 < 0)) {
        return 1;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < 4);
  }
  local_10 = 0;
  do {
    if (local_8[local_10] != 0) {
      piVar6 = *(int **)(param_1[5] + *(int *)(iVar13 + *(int *)(local_8[local_10] + 8)) * 4);
      iVar5 = *piVar6;
      iVar2 = piVar6[2];
      uVar8 = 0;
      if (param_1[2] != 0) {
        do {
          piVar6 = *(int **)(param_1[5] + uVar8 * 4);
          if ((iVar5 == *piVar6) && (iVar2 == piVar6[2])) {
            piVar6[7] = 1;
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < (uint)param_1[2]);
      }
    }
    local_10 = local_10 + 1;
  } while (local_10 < 4);
  pvVar4 = _malloc(0x38);
  if (pvVar4 == (void *)0x0) {
    local_18 = (uint *)0x0;
  }
  else {
    local_18 = (uint *)FUN_005f7709();
  }
  if (local_18 != (uint *)0x0) {
    iVar5 = FUN_005f7760(local_20,((int)local_38 + 1U) * local_c,local_38,0);
    if (iVar5 < 0) {
      return iVar5;
    }
    iVar5 = FUN_005f7a42(param_1[0x26]);
    if (-1 < iVar5) {
      local_10 = 0;
      puVar7 = (undefined4 *)(*(int *)(param_1[0x26] + 8) + (int)local_54 * 4);
      puVar11 = *(undefined4 **)((int)local_18 + 8);
      for (uVar8 = (uint)local_1c >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar11 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar11 = puVar11 + 1;
      }
      local_3c = 0;
      for (uVar8 = (uint)local_1c & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)puVar11 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      local_38 = local_1c;
      do {
        puVar7 = (undefined4 *)local_8[local_10];
        if (puVar7 != (undefined4 *)0x0) {
          *(undefined4 *)(local_3c + *(int *)((int)local_18 + 0x10)) = *(undefined4 *)puVar7[4];
          local_3c = local_3c + 4;
          puVar11 = (undefined4 *)(puVar7[2] + (int)local_34);
          puVar14 = (undefined4 *)(*(int *)((int)local_18 + 8) + (int)local_38);
          for (uVar8 = (uint)local_1c >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *puVar14 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar14 = puVar14 + 1;
          }
          for (uVar8 = (uint)local_1c & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined1 *)puVar14 = *(undefined1 *)puVar11;
            puVar11 = (undefined4 *)((int)puVar11 + 1);
            puVar14 = (undefined4 *)((int)puVar14 + 1);
          }
          *puVar7 = 0;
          local_38 = (undefined4 *)((int)local_38 + (int)local_1c);
        }
        local_10 = local_10 + 1;
      } while (local_10 < 4);
      piVar6 = (int *)local_4c;
      if (local_30 == 0) {
        piVar6 = local_50;
      }
      if (*(int *)((int)piVar6 * 4 + param_1[6]) != 0) {
        FUN_005f7186(1);
      }
      *(uint **)((int)piVar6 * 4 + param_1[6]) = local_18;
      FUN_0061674c();
      return 0;
    }
    return iVar5;
  }
  return -0x7ff8fff2;
}


// ==== 0x6109ea FUN_006109ea

undefined4 __thiscall FUN_006109ea(int param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  uint auStack_64 [8];
  uint auStack_44 [9];
  int local_20;
  uint local_18;
  int *local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  if (param_2 == (uint *)0x0) {
    uVar7 = 1;
  }
  else {
    iVar8 = FUN_005f7a96();
    if (iVar8 == 0) {
      uVar11 = *param_2 & 0xffffff;
      local_10 = param_2[1] / uVar11;
      uVar9 = *param_2 & 0xff000000;
      if (((uVar9 == 0xf7000000) || (uVar9 == 0xf8000000)) || (uVar9 == 0xf9000000)) {
        local_10 = 2;
      }
      if (1 < local_10) {
        iVar8 = *(int *)(param_1 + 0x58);
        iVar1 = *(int *)(param_1 + 0x54);
        auStack_44[iVar8] = 0;
        iVar2 = *(int *)(param_1 + 0x60);
        auStack_44[iVar2] = 0;
        auStack_44[iVar1] = 0;
        local_20 = iVar1 * 4;
        auStack_64[iVar8] = 1;
        auStack_64[iVar2] = 3;
        *(undefined4 *)((int)auStack_64 + local_20) = 1;
        local_18 = 0;
        local_c = 0;
        if (local_10 != 0) {
          piVar3 = (int *)param_2[2];
          iVar8 = *(int *)(param_1 + 0x14);
          piVar10 = piVar3;
          do {
            puVar4 = *(uint **)(iVar8 + *piVar10 * 4);
            uVar9 = *puVar4;
            uVar5 = *(uint *)(*(int *)(*(int *)(param_1 + 0x10) + uVar9 * 4) + 4);
            if (((uVar5 & 0x100) == 0) || ((uVar5 & 0x40) != 0)) {
              local_8 = uVar9;
              if (((uVar5 & 8) != 0) && ((uVar5 & 0x100) == 0)) {
                local_8 = *(uint *)(param_1 + 0x58);
              }
            }
            else {
              local_8 = *(uint *)(param_1 + 0x54);
            }
            param_2 = (uint *)0x0;
            local_14 = piVar3;
            if (local_c != 0) {
              do {
                puVar6 = *(uint **)(iVar8 + *local_14 * 4);
                if (((uVar9 == *puVar6) && (puVar4[1] == puVar6[1])) && (puVar4[2] == puVar6[2]))
                break;
                param_2 = (uint *)((int)param_2 + 1);
                local_14 = local_14 + uVar11;
              } while (param_2 < local_c);
            }
            if ((param_2 == (uint *)local_c) && (local_8 < 8)) {
              puVar4 = auStack_44 + local_8;
              *puVar4 = *puVar4 + 1;
              if (auStack_64[local_8] < *puVar4) goto LAB_00610b98;
            }
            if (((0x1ff < (*(uint *)(param_1 + 0x30) & 0xffff)) &&
                (*(uint *)(param_1 + 0x54) == local_8)) && (local_18 = local_18 + 1, 2 < local_18))
            {
LAB_00610b98:
              if (param_3 != (uint *)0x0) {
                *param_3 = local_c;
              }
              return 1;
            }
            piVar10 = piVar10 + uVar11;
            local_c = local_c + 1;
          } while (local_c < local_10);
        }
      }
      uVar7 = 0;
    }
    else {
      uVar7 = 0;
    }
  }
  return uVar7;
}


// ==== 0x610ba6 FUN_00610ba6

int __fastcall FUN_00610ba6(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0xec) == 0) {
    uVar1 = *(uint *)(param_1 + 0x30);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x30) & 0x7fffffff;
  }
  iVar2 = FUN_00618c39(uVar1);
  if (-1 < iVar2) {
    iVar2 = FUN_0061663f();
    if (-1 < iVar2) {
      iVar2 = 0;
    }
  }
  return iVar2;
}


// ==== 0x610bd8 FUN_00610bd8

uint __thiscall FUN_00610bd8(int param_1,int *param_2,int param_3)

{
  short sVar1;
  char cVar2;
  short *psVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  undefined4 uVar11;
  undefined *puVar12;
  char local_34 [32];
  char *local_14;
  short *local_10;
  int local_c;
  int local_8;
  
  uVar6 = 0;
  local_8 = 0;
  if (param_2[0x14] != -1) {
    return 0;
  }
  iVar4 = param_2[0x13];
  if (iVar4 == 0) {
    param_2[0x14] = 0;
    return 0;
  }
  local_10 = *(short **)(iVar4 + 0x18);
  local_c = param_1;
  if (*(int *)(param_1 + 0xec) != 0) {
    local_14 = (char *)((int)local_10 + 1);
    psVar3 = local_10;
    do {
      sVar1 = *psVar3;
      psVar3 = (short *)((int)psVar3 + 1);
    } while ((char)sVar1 != '\0');
    if ((2 < (uint)((int)psVar3 - (int)local_14)) && (*local_10 == 0x5f72)) {
      uVar6 = param_2[0x15];
      if (4 < uVar6) {
        FUN_005fbec8(param_1,iVar4,0x11bf,
                     "multi-register semantics are not allowed in fragments \'%s\'",local_10);
      }
      uVar8 = (uint)(4 < uVar6);
      iVar4 = FUN_005e54f8(local_10);
      if (iVar4 == 0) {
        uVar6 = FUN_005e7078(local_10,*(undefined4 *)(param_1 + 0x128),1);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
        uVar9 = *(uint *)(local_c + 0x128);
        *(uint *)(local_c + 0x128) = uVar9 + 1;
      }
      else {
        uVar9 = *(uint *)(iVar4 + 4);
      }
      uVar6 = 0xffff;
      goto LAB_006110af;
    }
  }
  _strncpy(local_34,*(char **)(iVar4 + 0x18),0x20);
  pcVar7 = local_34;
  if (local_34[0] == '\0') {
LAB_00610cf0:
    lVar5 = 0;
  }
  else {
    do {
      iVar4 = _isalpha((int)*pcVar7);
      if (iVar4 == 0) break;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar7 != '\0');
    if (*pcVar7 == '\0') goto LAB_00610cf0;
    lVar5 = _atoi(pcVar7);
  }
  if (*pcVar7 != '\0') {
    *pcVar7 = '\0';
    pcVar7 = pcVar7 + 1;
  }
  cVar2 = *pcVar7;
  if (cVar2 == '\0') {
LAB_00610d20:
    uVar9 = lVar5 + ((uint)param_2[0x15] >> 2);
  }
  else {
    do {
      iVar4 = _isdigit((int)cVar2);
      if (iVar4 == 0) break;
      pcVar7 = pcVar7 + 1;
      cVar2 = *pcVar7;
    } while (cVar2 != '\0');
    if (*pcVar7 == '\0') goto LAB_00610d20;
    uVar9 = 0xffffffff;
  }
  uVar8 = *(uint *)(*(int *)(*(int *)(local_c + 0x10) + *param_2 * 4) + 4);
  if (((uVar8 & 8) == 0) || ((uVar8 & 0x100) != 0)) {
    if ((uVar8 & 0x10) != 0) {
      iVar4 = __stricmp(local_34,"position");
      if (iVar4 == 0) {
        uVar6 = 1;
        bVar10 = uVar9 == 0;
LAB_00610f95:
        uVar8 = 1 - bVar10;
      }
      else {
        iVar4 = __stricmp(local_34,"psize");
        if (iVar4 == 0) {
          uVar6 = 5;
LAB_00611003:
          bVar10 = uVar9 == 0;
          goto LAB_00610f95;
        }
        iVar4 = __stricmp(local_34,"texcoord");
        if (iVar4 == 0) {
          uVar6 = 6;
          bVar10 = uVar9 < 8;
          goto LAB_00610f95;
        }
        iVar4 = __stricmp(local_34,"color");
        if (iVar4 == 0) {
          uVar6 = 0xb;
          bVar10 = uVar9 < 2;
          goto LAB_00610f95;
        }
        iVar4 = __stricmp(local_34,"fog");
        if (iVar4 == 0) {
          uVar6 = 0xc;
          goto LAB_00611003;
        }
        iVar4 = __stricmp(local_34,"diffuse");
        if (iVar4 == 0) {
          uVar8 = (uint)(uVar9 != 0);
          uVar6 = 0xb;
          local_8 = 1;
          if (uVar8 == 0) {
            uVar9 = 0;
          }
        }
        else {
          iVar4 = __stricmp(local_34,"specular");
          if (iVar4 == 0) {
            uVar8 = (uint)(uVar9 != 0);
            uVar6 = 0xb;
            local_8 = 1;
            if (uVar8 == 0) {
              uVar9 = 1;
            }
          }
          else {
            uVar6 = 0;
            uVar8 = 1;
          }
        }
      }
      if ((param_3 == 0) || (param_2[3] == 0)) {
        if (uVar8 == 0) {
          if (local_8 == 0) goto LAB_006110a8;
          puVar12 = (&PTR_s_UNKNOWN_006df648)[uVar6];
          pcVar7 = "output semantic \'%s\' has been deprecated; use \'%s%d\' instead";
          uVar11 = 0x1262;
          goto LAB_00611097;
        }
        pcVar7 = "invalid output semantic \'%s%d\'";
        goto LAB_00610f31;
      }
      goto LAB_006110a8;
    }
  }
  else {
    iVar4 = __stricmp(local_34,"position");
    if (iVar4 == 0) {
      uVar6 = 1;
LAB_00610d64:
      uVar8 = (uint)(0xf < uVar9);
    }
    else {
      iVar4 = __stricmp(local_34,"blendweight");
      if (iVar4 == 0) {
        uVar6 = 2;
        goto LAB_00610d64;
      }
      iVar4 = __stricmp(local_34,"blendindices");
      if (iVar4 == 0) {
        uVar6 = 3;
        goto LAB_00610d64;
      }
      iVar4 = __stricmp(local_34,"normal");
      if (iVar4 == 0) {
        uVar6 = 4;
        goto LAB_00610d64;
      }
      iVar4 = __stricmp(local_34,"psize");
      if (iVar4 == 0) {
        uVar6 = 5;
        goto LAB_00610d64;
      }
      iVar4 = __stricmp(local_34,"texcoord");
      if (iVar4 == 0) {
        uVar6 = 6;
        goto LAB_00610d64;
      }
      iVar4 = __stricmp(local_34,"tangent");
      if (iVar4 == 0) {
        uVar6 = 7;
        goto LAB_00610d64;
      }
      iVar4 = __stricmp(local_34,"binormal");
      if (iVar4 == 0) {
        uVar6 = 8;
        goto LAB_00610d64;
      }
      iVar4 = __stricmp(local_34,"positiont");
      if (iVar4 != 0) {
        iVar4 = __stricmp(local_34,"color");
        if (iVar4 == 0) {
          uVar6 = 0xb;
        }
        else {
          iVar4 = __stricmp(local_34,"fog");
          if (iVar4 == 0) {
            uVar6 = 0xc;
          }
          else {
            iVar4 = __stricmp(local_34,"depth");
            if (iVar4 == 0) {
              uVar6 = 0xd;
            }
            else {
              iVar4 = __stricmp(local_34,"sample");
              if (iVar4 != 0) {
                iVar4 = __stricmp(local_34,"diffuse");
                if (iVar4 == 0) {
                  uVar8 = (uint)(uVar9 != 0);
                  uVar6 = 0xb;
                  local_8 = 1;
                  if (uVar8 == 0) {
                    uVar9 = 0;
                  }
                }
                else {
                  iVar4 = __stricmp(local_34,"specular");
                  if (iVar4 != 0) {
                    uVar6 = 0;
                    goto LAB_00610f0d;
                  }
                  uVar8 = (uint)(uVar9 != 0);
                  uVar6 = 0xb;
                  local_8 = 1;
                  if (uVar8 == 0) {
                    uVar9 = 1;
                  }
                }
                goto LAB_00610f10;
              }
              uVar6 = 0xe;
            }
          }
        }
        goto LAB_00610d64;
      }
      uVar6 = 10;
      if ((uVar9 < 0x10) && (uVar9 != 0)) {
        uVar8 = 0;
      }
      else {
LAB_00610f0d:
        uVar8 = 1;
      }
    }
LAB_00610f10:
    if ((param_3 == 0) || (param_2[3] == 0)) {
      if (uVar8 == 0) {
        if (local_8 != 0) {
          puVar12 = (&PTR_s_UNKNOWN_006df648)[uVar6];
          pcVar7 = "input semantic \'%s\' has been deprecated; use \'%s%d\' instead";
          uVar11 = 0x1261;
LAB_00611097:
          FUN_005fbf37(local_c,param_2[0x13],uVar11,pcVar7,local_34,puVar12,uVar9);
        }
      }
      else {
        pcVar7 = "invalid input semantic \'%s%d\'";
LAB_00610f31:
        FUN_005fbec8(local_c,param_2[0x13],0x1196,pcVar7,local_34,uVar9);
        uVar8 = 1;
      }
    }
LAB_006110a8:
    if (uVar6 != 0) goto LAB_006110af;
  }
  uVar8 = 1;
LAB_006110af:
  if (0xffff < uVar9) {
    uVar8 = 1;
  }
  param_2[0x14] = uVar9 << 0x10 | uVar6;
  return -(uint)(uVar8 != 0) & 0x80004005;
}


