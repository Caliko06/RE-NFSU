// ==== 0x4f1040 FUN_004f1040

void FUN_004f1040(int param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  bool bVar9;
  uint uVar10;
  
  iVar4 = param_4;
  uVar3 = *(uint *)(param_2 + 0x10);
  param_4 = 0;
  if (uVar3 != 0) {
    do {
      puVar1 = (uint *)(*(int *)(param_2 + 0x14) + param_4 * 0xc);
      uVar10 = *puVar1;
      if (uVar10 < 0x109) {
        if (uVar10 == 0x108) {
          FUN_004f0a50(0,0xff);
        }
        else if (uVar10 < 0x102) {
          if (uVar10 == 0x101) {
            *(bool *)(param_1 + 1) = puVar1[1] == 1;
          }
          else if (uVar10 < 3) {
            if (uVar10 == 2) {
              uVar10 = 0xffffffff;
LAB_004f1181:
              FUN_004f0700(puVar1[1],param_3,iVar4,uVar10,param_5);
            }
            else if (uVar10 == 0) {
              if ((param_3 != 0) && (iVar6 = FEObject__FindScript(), iVar6 != 0)) {
                *(int *)(param_3 + 0x54) = iVar6;
                FUN_004ff030(param_3);
                *(undefined4 *)(iVar6 + 0x10) = 0;
              }
            }
            else if (uVar10 == 1) {
              uVar10 = puVar1[2];
              if ((uVar10 == 0xfffffffc) || (uVar10 == 0xffffffff)) goto LAB_004f1181;
              uVar5 = FUN_004ffbe0();
              FUN_004f0700(puVar1[1],param_3,iVar4,uVar5,param_5);
            }
          }
          else {
            if (uVar10 == 3) {
              uVar10 = 0xfffffffb;
              goto LAB_004f1181;
            }
            if (uVar10 != 0x100) goto switchD_004f11b4_caseD_104;
            if (puVar1[1] == 0) {
              iVar6 = 0;
LAB_004f1157:
              if (puVar1[1] != 0) goto switchD_004f11b4_caseD_104;
            }
            else {
              iVar6 = FUN_004ffbe0();
              if (iVar6 == 0) goto LAB_004f1157;
            }
            FUN_00500350(iVar6);
          }
        }
        else {
          switch(uVar10) {
          case 0x102:
            if (*(int *)(iVar4 + 0x80) == 0) {
              FUN_004f1620(0);
            }
            else {
              FUN_004f1620(*(undefined4 *)(*(int *)(iVar4 + 0x80) + 0xc));
            }
            break;
          case 0x103:
            iVar6 = FUN_004f1680();
            if (iVar6 == 0) {
              iVar6 = 0;
LAB_004f120f:
              if (((puVar1[1] == 0) || (iVar6 = FUN_004ffbe0(), iVar6 == 0)) && (puVar1[1] != 0))
              break;
            }
            else {
              iVar6 = FUN_004ffbe0();
              if (iVar6 == 0) goto LAB_004f120f;
            }
            FUN_00500350(iVar6);
            break;
          case 0x105:
            FUN_004f0a50(1,param_5);
            break;
          case 0x106:
            FUN_004f0a50(1,0xff);
            break;
          case 0x107:
            FUN_004f0a50(0,param_5);
          }
        }
      }
      else if (uVar10 < 0x2c1) {
        if (uVar10 == 0x2c0) {
          iVar6 = *(int *)(param_1 + 0x4148);
          pcVar8 = *(char **)(iVar4 + 0xc);
          if (iVar6 != 0x10) {
            *(int *)(param_1 + 0x4148) = iVar6 + 1;
            iVar6 = (iVar6 * 0x100 + 0x414c + param_1) - (int)pcVar8;
            do {
              cVar2 = *pcVar8;
              pcVar8[iVar6] = cVar2;
              pcVar8 = pcVar8 + 1;
            } while (cVar2 != '\0');
          }
        }
        else {
          switch(uVar10) {
          case 0x200:
            FUN_004f0800(param_1,iVar4);
            break;
          case 0x201:
            UIListNode_Alloc(param_1,iVar4,*(undefined4 *)(iVar4 + 0x1c));
            break;
          case 0x202:
            uVar10 = 0;
            do {
              uVar7 = 1 << ((byte)uVar10 & 0x1f);
              if ((param_5 & uVar7) != 0) {
                UIListNode_Alloc(param_1,iVar4,uVar7);
              }
              uVar10 = uVar10 + 1;
            } while (uVar10 < 8);
            break;
          case 0x203:
            FUN_004f09b0(iVar4);
            break;
          case 0x204:
            UIListNode_Alloc(param_1,iVar4,0);
          }
        }
      }
      else if (uVar10 < 0x301) {
        if (uVar10 == 0x300) {
          if (*(uint *)(*(int *)(param_3 + 0x54) + 0x30) != puVar1[1]) goto LAB_004f13d7;
        }
        else if (uVar10 == 0x2c1) {
          if ((*(int *)(param_1 + 0x4148) != 0) &&
             (iVar6 = *(int *)(param_1 + 0x4148) + -1, *(int *)(param_1 + 0x4148) = iVar6,
             iVar6 * 0x100 + 0x414c + param_1 != 0)) {
            FUN_004f0800(param_1,iVar4);
          }
        }
        else if (uVar10 == 0x2c2) {
          FUN_004f16a0();
        }
      }
      else {
        if (uVar10 == 0x301) {
          bVar9 = *(uint *)(*(int *)(param_3 + 0x54) + 0x30) == puVar1[1];
        }
        else {
          bVar9 = uVar10 == 0x500;
        }
        if (bVar9) {
LAB_004f13d7:
          param_4 = FEMessageResponse__FindConditionBranchTarget();
        }
      }
switchD_004f11b4_caseD_104:
      param_4 = param_4 + 1;
    } while (param_4 < uVar3);
  }
  return;
}


// ==== 0x4f1430 FUN_004f1430

void FUN_004f1430(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int in_EAX;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 local_8;
  int local_4;
  
  local_4 = 0;
  local_8 = 0;
  do {
    puVar2 = *(undefined4 **)(in_EAX + 0x412c);
    if (puVar2 == (undefined4 *)0x0) {
      return;
    }
    *(undefined4 *)(in_EAX + 0x412c) = puVar2[1];
    if (puVar2 == *(undefined4 **)(in_EAX + 0x4130)) {
      *(undefined4 *)(in_EAX + 0x4130) = puVar2[2];
    }
    if (puVar2[2] != 0) {
      *(undefined4 *)(puVar2[2] + 4) = puVar2[1];
    }
    if (puVar2[1] != 0) {
      *(undefined4 *)(puVar2[1] + 8) = puVar2[2];
    }
    puVar2[1] = 0xabadcafe;
    puVar2[2] = 0xabadcafe;
    *(int *)(in_EAX + 0x4128) = *(int *)(in_EAX + 0x4128) + -1;
    iVar7 = puVar2[7];
    if (iVar7 == 0) {
      iVar9 = -1;
    }
    else {
      iVar9 = *(int *)(iVar7 + 0x18);
    }
    if (((puVar2[5] & 1) != 0) && (-1 < iVar9)) {
      uVar3 = *(undefined4 *)(iVar7 + 0x30);
      uVar5 = uVar3;
      iVar6 = iVar7;
      if ((puVar2[5] & 2) == 0) {
        for (iVar4 = *(int *)(in_EAX + 0xe4); uVar5 = local_8, iVar6 = local_4, iVar4 != 0;
            iVar4 = *(int *)(iVar4 + 4)) {
          if (*(int *)(iVar4 + 0x30) == iVar7) {
            *(undefined4 *)(iVar4 + 0x30) = uVar3;
          }
        }
      }
      local_4 = iVar6;
      local_8 = uVar5;
      if (*(int *)(puVar2[7] + 0x30) != 0) {
        puVar1 = (uint *)(*(int *)(puVar2[7] + 0x30) + 0x1c);
        *puVar1 = *puVar1 | puVar2[6];
      }
      cFEng__PopPackage(in_EAX,puVar2[7]);
      iVar9 = iVar9 + -1;
    }
    if ((*(byte *)(puVar2 + 5) & 2) != 0) {
      iVar7 = cFEng__PushPackage(in_EAX,puVar2[3],(char)iVar9 + '\x01',puVar2[6]);
      if (iVar7 == 0) {
LAB_004f1545:
        if ((*(byte *)(puVar2 + 5) & 1) == 0) goto LAB_004f156f;
      }
      else if ((*(byte *)(puVar2 + 5) & 1) == 0) {
        if (-1 < iVar9) {
          *(undefined4 *)(iVar7 + 0x30) = puVar2[7];
          *(uint *)(puVar2[7] + 0x1c) = *(uint *)(puVar2[7] + 0x1c) & ~puVar2[6];
          goto LAB_004f156f;
        }
        goto LAB_004f1545;
      }
      *(undefined4 *)(iVar7 + 0x30) = local_8;
      for (iVar9 = *(int *)(in_EAX + 0xe4); iVar9 != 0; iVar9 = *(int *)(iVar9 + 4)) {
        if (*(int *)(iVar9 + 0x30) == local_4) {
          *(int *)(iVar9 + 0x30) = iVar7;
        }
      }
    }
LAB_004f156f:
    if ((*(byte *)(puVar2 + 5) & 4) != 0) {
      iVar7 = puVar2[7];
      iVar9 = *(int *)(iVar7 + 0x30);
      if (iVar9 != 0) {
        uVar8 = *(uint *)(iVar7 + 0x1c) & puVar2[6];
        *(uint *)(iVar7 + 0x1c) = ~uVar8 & *(uint *)(iVar7 + 0x1c);
        *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) | uVar8;
        FUN_004f0700(0x334c5493,0,iVar9,0xfffffffc,puVar2[6]);
      }
    }
    if (((*(byte *)(puVar2 + 5) & 8) == 0) || (iVar7 = *(int *)(in_EAX + 0xe4), iVar7 == 0)) {
LAB_004f1602:
      (**(code **)*puVar2)(1);
    }
    else {
      iVar9 = puVar2[7];
      do {
        if (*(int *)(iVar7 + 0x30) == iVar9) {
          uVar8 = *(uint *)(iVar9 + 0x1c) & puVar2[6];
          *(uint *)(iVar9 + 0x1c) = ~uVar8 & *(uint *)(iVar9 + 0x1c);
          *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | uVar8;
          FUN_004f0700(0x334c5493,0,iVar7,0xfffffffc,puVar2[6]);
          goto LAB_004f1602;
        }
        iVar7 = *(int *)(iVar7 + 4);
      } while (iVar7 != 0);
      (**(code **)*puVar2)(1);
    }
  } while( true );
}


// ==== 0x4f1620 FUN_004f1620

void __thiscall FUN_004f1620(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int unaff_ESI;
  
  piVar1 = (int *)(param_1 + 0x5150);
  iVar2 = 0x20;
  do {
    if (*piVar1 == unaff_ESI) {
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(int *)(param_1 + 0x5150 + *(int *)(param_1 + 0x514c) * 8) = unaff_ESI;
  *(undefined4 *)(param_1 + 0x5154 + *(int *)(param_1 + 0x514c) * 8) = param_2;
  uVar3 = *(int *)(param_1 + 0x514c) + 1U & 0x8000001f;
  if ((int)uVar3 < 0) {
    uVar3 = (uVar3 - 1 | 0xffffffe0) + 1;
  }
  *(uint *)(param_1 + 0x514c) = uVar3;
  return;
}


// ==== 0x4f1680 FUN_004f1680

undefined4 __fastcall FUN_004f1680(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  
  iVar1 = 0;
  piVar2 = (int *)(unaff_ESI + 0x5150);
  do {
    if (*piVar2 == param_2) {
      return *(undefined4 *)(unaff_ESI + 0x5154 + iVar1 * 8);
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 2;
  } while (iVar1 < 0x20);
  return 0;
}


// ==== 0x4f16a0 FUN_004f16a0

void __fastcall FUN_004f16a0(undefined4 param_1,int param_2)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)(param_2 + 0x414c);
  iVar2 = 0x10;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 0x100;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(param_2 + 0x4148) = 0;
  return;
}


// ==== 0x4f16d0 FUN_004f16d0

void FUN_004f16d0(int *param_1)

{
  int iVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *local_818;
  int local_814;
  int local_808 [256];
  int local_408 [257];
  
  iVar6 = *param_1;
  iVar1 = iVar6 * 8;
  local_814 = 0;
  piVar3 = param_1 + 0x801;
  local_818 = param_1 + 1;
  do {
    piVar7 = piVar3;
    piVar3 = local_408;
    for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar3 = 0;
      piVar3 = piVar3 + 1;
    }
    iVar4 = 0;
    if (0 < iVar1) {
      do {
        local_408[*(byte *)((int)local_818 + iVar4 + local_814 + 4)] =
             local_408[*(byte *)((int)local_818 + iVar4 + local_814 + 4)] + 1;
        iVar4 = iVar4 + 8;
      } while (iVar4 < iVar1);
    }
    iVar4 = 0;
    local_808[0] = 0;
    do {
      iVar5 = *(int *)((int)local_808 + iVar4) + *(int *)((int)local_408 + iVar4);
      *(int *)((int)local_808 + iVar4 + 4) = iVar5;
      iVar5 = iVar5 + *(int *)((int)local_408 + iVar4 + 4);
      *(int *)((int)local_808 + iVar4 + 8) = iVar5;
      iVar5 = iVar5 + *(int *)((int)local_408 + iVar4 + 8);
      *(int *)((int)local_808 + iVar4 + 0xc) = iVar5;
      iVar5 = iVar5 + *(int *)((int)local_408 + iVar4 + 0xc);
      *(int *)((int)local_808 + iVar4 + 0x10) = iVar5;
      *(int *)((int)local_808 + iVar4 + 0x14) = *(int *)((int)local_408 + iVar4 + 0x10) + iVar5;
      iVar4 = iVar4 + 0x14;
    } while (iVar4 < 0x3fc);
    iVar4 = 0;
    piVar3 = local_818;
    if (0 < iVar6) {
      do {
        bVar2 = *(byte *)(local_814 + 4 + (int)piVar3);
        iVar6 = local_808[bVar2];
        piVar7[iVar6 * 2] = *piVar3;
        piVar7[iVar6 * 2 + 1] = piVar3[1];
        local_808[bVar2] = iVar6 + 1;
        iVar6 = *param_1;
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 2;
      } while (iVar4 < iVar6);
    }
    local_814 = local_814 + 1;
    piVar3 = local_818;
    local_818 = piVar7;
  } while (local_814 < 4);
  return;
}


// ==== 0x4f1810 FUN_004f1810

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_004f1810(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 extraout_EDX;
  int unaff_EBX;
  undefined4 *unaff_ESI;
  int *unaff_EDI;
  
  uVar3 = 0x3f800000;
  if (((((float)unaff_EDI[10] != 0.0) || ((float)unaff_EDI[0xb] != 0.0)) ||
      ((float)unaff_EDI[0xc] != 0.0)) || (bVar2 = false, unaff_EDI[0xd] != 0x3f800000)) {
    bVar2 = true;
  }
  if (bVar2) {
    FUN_00566a20();
    uVar3 = extraout_EDX;
  }
  *unaff_ESI = uVar3;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[4] = 0;
  unaff_ESI[5] = uVar3;
  unaff_ESI[6] = 0;
  unaff_ESI[7] = 0;
  unaff_ESI[8] = 0;
  unaff_ESI[9] = 0;
  unaff_ESI[10] = uVar3;
  unaff_ESI[0xb] = 0;
  unaff_ESI[0xc] = 0;
  unaff_ESI[0xd] = 0;
  unaff_ESI[0xe] = 0;
  unaff_ESI[0xf] = uVar3;
  D3DXMatrixMultiply();
  if (&stack0x00000000 != (undefined1 *)0x90) {
    D3DXMatrixMultiply();
  }
  if (unaff_ESI != (undefined4 *)0x0) {
    D3DXMatrixMultiply();
  }
  if (&stack0x00000000 != (undefined1 *)0x90) {
    D3DXMatrixMultiply();
  }
  if (unaff_EBX != 0) {
    D3DXMatrixMultiply();
  }
  if (param_3 != 0) {
    piVar1 = (int *)(param_3 * 0xd0 + 0x20 + param_1);
    param_2[2] = piVar1[2] * unaff_EDI[2] + 0x80 >> 8;
    param_2[1] = piVar1[1] * unaff_EDI[1] + 0x80 >> 8;
    *param_2 = *unaff_EDI * *piVar1 + 0x80 >> 8;
    param_2[3] = piVar1[3] * unaff_EDI[3] + 0x80 >> 8;
    D3DXMatrixMultiply();
    if (piVar1[0x15] != 0) {
      return piVar1 + 0x18;
    }
    return (int *)0x0;
  }
  param_2[3] = unaff_EDI[3];
  param_2[2] = unaff_EDI[2];
  param_2[1] = unaff_EDI[1];
  *param_2 = *unaff_EDI;
  return (int *)0x0;
}


// ==== 0x4f1d80 FUN_004f1d80

void FUN_004f1d80(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uint uStack_b0;
  uint uStack_ac;
  uint uStack_a8;
  uint local_a4;
  undefined4 uStack_a0;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c [3];
  undefined1 local_50 [76];
  
  if (DAT_00733f74 != 0) {
    if (DAT_00733f6c == 0) {
      puVar9 = DAT_0073551c;
      if (DAT_0073551c == (undefined *)0x0) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
    }
    else {
      puVar9 = &DAT_00737320;
    }
    local_90 = 0x3f800000;
    local_8c = 0;
    local_88 = 0;
    local_84 = 0;
    local_80 = 0;
    local_7c = 0x3f800000;
    local_78 = 0;
    local_74 = 0;
    local_70 = 0;
    local_6c = 0;
    local_68 = 0x3f800000;
    local_64 = 0;
    local_5c[2] = 0x3f800000;
    local_60 = 0x43a00000;
    local_5c[0] = 0x43700000;
    local_5c[1] = 0;
    local_94 = FUN_004f1810(param_1,&local_a4,*(undefined2 *)(param_2 + 0x20),0x3f800000);
    D3DXMatrixMultiply(local_50,local_50,&local_90);
    if (param_3 == 0) {
      param_3 = FUN_004f2db0(param_1,param_2,puVar9);
    }
    else {
      FUN_00514bf0(param_3);
    }
    iVar6 = (int)*(short *)(puVar9 + 0x44);
    iVar8 = (int)*(short *)(puVar9 + 0x46);
    fVar2 = (float)iVar6;
    if (iVar6 < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    fVar4 = (float)iVar8;
    if (iVar8 < 0) {
      fVar4 = fVar4 + 4.2949673e+09;
    }
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      uVar7 = iVar6 - 1;
      iVar6 = 2;
      while (uVar7 = uVar7 >> 1, uVar7 != 0) {
        iVar6 = iVar6 << 1;
      }
    }
    if (iVar8 == 0) {
      iVar8 = 0;
    }
    else {
      uVar7 = iVar8 - 1;
      iVar8 = 2;
      while (uVar7 = uVar7 >> 1, uVar7 != 0) {
        iVar8 = iVar8 << 1;
      }
    }
    fVar3 = (float)iVar6;
    if (iVar6 < 0) {
      fVar3 = fVar3 + 4.2949673e+09;
    }
    fVar5 = (float)iVar8;
    if (iVar8 < 0) {
      fVar5 = fVar5 + 4.2949673e+09;
    }
    uStack_b0 = (((int)local_a4 / 2 << 8 | (int)uStack_b0 / 2) << 8 | (int)uStack_ac / 2) << 8 |
                (int)uStack_a8 / 2;
    puVar10 = local_5c;
    puVar11 = (undefined4 *)(param_3 + 0x20);
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar11 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
    }
    uStack_ac = uStack_b0;
    uStack_a8 = uStack_b0;
    local_a4 = uStack_b0;
    FUN_005146d0(param_3,0xbf000000,0xbf000000,0x3f000000,0x3f000000,0x3f800000,
                 (fVar2 / fVar3) * 0.0,(fVar4 / fVar5) * 0.0,fVar2 / fVar3,fVar4 / fVar5,&uStack_b0,
                 uStack_a0);
    *(undefined **)(param_3 + 0x14) = puVar9;
    FUN_00514b90(param_3);
  }
  return;
}


// ==== 0x4f2000 FUN_004f2000

void FUN_004f2000(undefined4 param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int in_EAX;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  uint uStack_bc;
  uint uStack_b8;
  uint uStack_b4;
  uint local_b0;
  int iStack_ac;
  float fStack_a8;
  undefined4 uStack_a4;
  float fStack_a0;
  undefined4 local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c [3];
  undefined1 local_50 [76];
  
  iVar10 = *(int *)(param_2 + 0x2c);
  local_90 = 0x3f800000;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0x3f800000;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0x3f800000;
  local_64 = 0;
  local_5c[2] = 0x3f800000;
  local_60 = 0x43a00000;
  local_5c[0] = 0x43700000;
  local_5c[1] = 0;
  local_98 = FUN_004f1810(param_1,&local_b0,*(undefined2 *)(param_2 + 0x20),0x3f800000);
  D3DXMatrixMultiply(local_50,local_50,&local_90);
  iVar7 = Texture_FindByHash(*(undefined4 *)(param_2 + 0x24),1,0);
  iStack_ac = iVar7;
  if (in_EAX == 0) {
    in_EAX = FUN_004f2db0(param_1,param_2,iVar7);
  }
  else {
    FUN_00514bf0(in_EAX);
  }
  iVar8 = (int)*(short *)(iVar7 + 0x44);
  iVar7 = (int)*(short *)(iVar7 + 0x46);
  fVar3 = (float)iVar8;
  if (iVar8 < 0) {
    fVar3 = fVar3 + 4.2949673e+09;
  }
  fVar5 = (float)iVar7;
  if (iVar7 < 0) {
    fVar5 = fVar5 + 4.2949673e+09;
  }
  if (iVar8 == 0) {
    iVar8 = 0;
  }
  else {
    uVar9 = iVar8 - 1;
    iVar8 = 2;
    while (uVar9 = uVar9 >> 1, uVar9 != 0) {
      iVar8 = iVar8 << 1;
    }
  }
  if (iVar7 == 0) {
    iVar7 = 0;
  }
  else {
    uVar9 = iVar7 - 1;
    iVar7 = 2;
    while (uVar9 = uVar9 >> 1, uVar9 != 0) {
      iVar7 = iVar7 << 1;
    }
  }
  fVar4 = (float)iVar8;
  if (iVar8 < 0) {
    fVar4 = fVar4 + 4.2949673e+09;
  }
  fVar6 = (float)iVar7;
  if (iVar7 < 0) {
    fVar6 = fVar6 + 4.2949673e+09;
  }
  uStack_bc = (((int)local_b0 / 2 << 8 | (int)uStack_bc / 2) << 8 | (int)uStack_b8 / 2) << 8 |
              (int)uStack_b4 / 2;
  fVar1 = *(float *)(iVar10 + 0x44);
  fStack_a0 = (fVar3 / fVar4) * *(float *)(iVar10 + 0x4c);
  fStack_a8 = (fVar5 / fVar6) * *(float *)(iVar10 + 0x48);
  fVar2 = *(float *)(iVar10 + 0x50);
  puVar11 = local_5c;
  puVar12 = (undefined4 *)(in_EAX + 0x20);
  for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar12 = *puVar11;
    puVar11 = puVar11 + 1;
    puVar12 = puVar12 + 1;
  }
  uStack_b8 = uStack_bc;
  uStack_b4 = uStack_bc;
  local_b0 = uStack_bc;
  FUN_005146d0(in_EAX,0xbf000000,0xbf000000,0x3f000000,0x3f000000,0x3f800000,(fVar3 / fVar4) * fVar1
               ,fStack_a8,fStack_a0,(fVar5 / fVar6) * fVar2,&uStack_bc,uStack_a4);
  *(int *)(in_EAX + 0x14) = iStack_ac;
  FUN_00514b90(in_EAX);
  return;
}


// ==== 0x4f2280 FUN_004f2280

void FUN_004f2280(undefined4 param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int in_EAX;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined4 uStack_c8;
  uint local_bc;
  uint uStack_b8;
  uint uStack_b4;
  uint uStack_b0;
  int iStack_a4;
  undefined1 local_a0 [16];
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c [3];
  undefined1 local_50 [76];
  
  iVar12 = *(int *)(param_2 + 0x2c);
  local_90 = 0x3f800000;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0x3f800000;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0x3f800000;
  local_64 = 0;
  local_5c[2] = 0x3f800000;
  local_60 = 0x43a00000;
  local_5c[0] = 0x43700000;
  local_5c[1] = 0;
  local_bc = FUN_004f1810(param_1,local_a0,*(undefined2 *)(param_2 + 0x20),0x3f800000);
  D3DXMatrixMultiply(local_50,local_50,&local_90);
  iVar9 = Texture_FindByHash(*(undefined4 *)(param_2 + 0x24),1,0);
  if (in_EAX == 0) {
    in_EAX = FUN_004f2db0(param_1,param_2,iVar9);
  }
  else {
    FUN_00514bf0(in_EAX);
  }
  iVar10 = (int)*(short *)(iVar9 + 0x44);
  iVar13 = (int)*(short *)(iVar9 + 0x46);
  fVar5 = (float)iVar10;
  if (iVar10 < 0) {
    fVar5 = fVar5 + 4.2949673e+09;
  }
  fVar7 = (float)iVar13;
  if (iVar13 < 0) {
    fVar7 = fVar7 + 4.2949673e+09;
  }
  if (iVar10 == 0) {
    iVar10 = 0;
  }
  else {
    uVar11 = iVar10 - 1;
    iVar10 = 2;
    while (uVar11 = uVar11 >> 1, uVar11 != 0) {
      iVar10 = iVar10 << 1;
    }
  }
  if (iVar13 == 0) {
    iVar13 = 0;
  }
  else {
    uVar11 = iVar13 - 1;
    iVar13 = 2;
    while (uVar11 = uVar11 >> 1, uVar11 != 0) {
      iVar13 = iVar13 << 1;
    }
  }
  fVar6 = (float)iVar10;
  if (iVar10 < 0) {
    fVar6 = fVar6 + 4.2949673e+09;
  }
  fVar8 = (float)iVar13;
  if (iVar13 < 0) {
    fVar8 = fVar8 + 4.2949673e+09;
  }
  local_bc = ((*(int *)(iVar12 + 0x60) / 2 << 8 | *(int *)(iVar12 + 0x54) / 2) << 8 |
             *(int *)(iVar12 + 0x58) / 2) << 8 | *(int *)(iVar12 + 0x5c) / 2;
  uStack_b8 = ((*(int *)(iVar12 + 0x70) / 2 << 8 | *(int *)(iVar12 + 100) / 2) << 8 |
              *(int *)(iVar12 + 0x68) / 2) << 8 | *(int *)(iVar12 + 0x6c) / 2;
  fVar1 = *(float *)(iVar12 + 0x44);
  fVar2 = *(float *)(iVar12 + 0x4c);
  fVar3 = *(float *)(iVar12 + 0x48);
  uStack_b4 = ((*(int *)(iVar12 + 0x80) / 2 << 8 | *(int *)(iVar12 + 0x74) / 2) << 8 |
              *(int *)(iVar12 + 0x78) / 2) << 8 | *(int *)(iVar12 + 0x7c) / 2;
  fVar4 = *(float *)(iVar12 + 0x50);
  iStack_a4 = *(int *)(iVar12 + 0x8c);
  uStack_b0 = ((*(int *)(iVar12 + 0x90) / 2 << 8 | *(int *)(iVar12 + 0x84) / 2) << 8 |
              *(int *)(iVar12 + 0x88) / 2) << 8 | iStack_a4 / 2;
  puVar14 = local_5c;
  puVar15 = (undefined4 *)(in_EAX + 0x20);
  for (iVar12 = 0x10; iVar12 != 0; iVar12 = iVar12 + -1) {
    *puVar15 = *puVar14;
    puVar14 = puVar14 + 1;
    puVar15 = puVar15 + 1;
  }
  FUN_005146d0(in_EAX,0xbf000000,0xbf000000,0x3f000000,0x3f000000,0x3f800000,(fVar5 / fVar6) * fVar1
               ,(fVar7 / fVar8) * fVar3,(fVar5 / fVar6) * fVar2,(fVar7 / fVar8) * fVar4,&local_bc,
               uStack_c8);
  *(int *)(in_EAX + 0x14) = iVar9;
  FUN_00514b90(in_EAX);
  return;
}


// ==== 0x4f25f0 FUN_004f25f0

void FUN_004f25f0(int param_1)

{
  undefined4 in_EAX;
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int unaff_EBX;
  undefined4 unaff_EDI;
  undefined4 local_8a8;
  undefined4 local_8a0;
  undefined4 local_89c;
  undefined4 local_898;
  undefined4 local_894;
  undefined4 local_890;
  undefined4 local_88c;
  undefined4 local_888;
  undefined4 local_884;
  undefined4 local_880;
  undefined4 local_87c;
  undefined4 local_878;
  undefined4 local_874;
  undefined4 local_870;
  undefined4 local_86c;
  undefined4 local_868;
  undefined4 local_864;
  undefined1 local_860 [4];
  undefined1 auStack_85c [12];
  undefined1 local_850 [52];
  undefined1 auStack_81c [2072];
  
  iVar1 = FEPackageList__FindByKeyWithAlias();
  if (iVar1 == 0) {
    return;
  }
  if (*(int *)(iVar1 + 8) != 0) {
    if (param_1 == 0) {
      param_1 = FUN_004f2db0(in_EAX,unaff_EBX,*(int *)(iVar1 + 8));
    }
    else {
      FUN_00514bf0(param_1);
    }
    local_8a8 = 0x3f800000;
    if (((DAT_006ee6f0 == 7) || (DAT_006ee6f0 == 8)) && (*(int *)(unaff_EBX + 0x24) == -0x6a7c55e6))
    {
      local_8a8 = 0x40000000;
    }
    local_8a0 = 0x3f800000;
    local_89c = 0;
    local_898 = 0;
    local_894 = 0;
    local_890 = 0;
    local_88c = 0x3f800000;
    local_888 = 0;
    local_884 = 0;
    local_880 = 0;
    local_87c = 0;
    local_878 = 0x3f800000;
    local_874 = 0;
    local_864 = 0x3f800000;
    local_870 = 0x43a00000;
    local_86c = 0x43700000;
    local_868 = 0;
    FUN_004f1810(in_EAX,local_860,*(undefined2 *)(unaff_EBX + 0x20),local_8a8);
    D3DXMatrixMultiply(local_850,local_850,&local_8a0);
    iVar1 = *(int *)(unaff_EBX + 0x5c);
    if (((*(byte *)(unaff_EBX + 0x1c) & 2) == 0) &&
       (iVar2 = LanguageStrings__FindByHash(), iVar2 != 0)) {
      FUN_0059ff40(auStack_81c,0x800);
      puVar3 = auStack_81c;
    }
    else {
      puVar3 = *(undefined1 **)(unaff_EBX + 0x60);
    }
    if (((((iVar1 != 0x169268) && (iVar1 != 0x4f876b6f)) &&
         ((iVar1 != 0x5d6a55a6 &&
          ((((iVar1 != 0x3825db8f && (iVar1 != 0x15417b53)) && (iVar1 != 0x2e8dfc7)) &&
           ((iVar1 != -0x57885dcc && (iVar1 != 0x1335f0)))))))) && (iVar1 != 0x2616b630)) &&
       (((iVar1 != -0x6c4af7c6 && (iVar1 != -0x3ae6c855)) && (iVar1 != 0x1cb516e6)))) {
      FUN_004f48b0(unaff_EDI,puVar3,auStack_85c,param_1);
    }
    return;
  }
  return;
}


// ==== 0x4f27d0 FEQuad::SortCorners

/* [canon] hud med (ghidra-canon+hopper) docs/re/canon.md */

void __fastcall FEQuad__SortCorners(float *param_1)

{
  float fVar1;
  
  if (param_1[4] < *param_1) {
    fVar1 = param_1[4];
    param_1[4] = *param_1;
    param_1[8] = *param_1;
    *param_1 = fVar1;
    param_1[0xc] = fVar1;
  }
  if (param_1[0xd] < param_1[1]) {
    fVar1 = param_1[0xd];
    param_1[9] = param_1[1];
    param_1[0xd] = param_1[1];
    param_1[1] = fVar1;
    param_1[5] = fVar1;
  }
  return;
}


// ==== 0x4f2810 FUN_004f2810

void FUN_004f2810(undefined4 param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined1 **ppuVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  float *extraout_EDX;
  undefined1 *puVar9;
  float *pfVar10;
  int iVar11;
  undefined1 *puStack_10c;
  undefined1 *puStack_108;
  undefined4 *puStack_104;
  float fVar12;
  float fVar13;
  float afStack_f4 [6];
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  undefined1 *puStack_b8;
  int iStack_b4;
  uint uStack_b0;
  float fStack_a4;
  undefined1 local_a0 [16];
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  float local_5c [3];
  undefined1 local_50 [76];
  
  local_90 = 0x3f800000;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0x3f800000;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0x3f800000;
  local_64 = 0;
  local_5c[2] = 1.0;
  local_60 = 0x43a00000;
  local_5c[0] = 240.0;
  local_5c[1] = 0.0;
  puStack_108 = (undefined1 *)(uint)*(ushort *)(*(int *)(param_2 + 0x54) + 0x20);
  puStack_104 = (undefined4 *)0x3f800000;
  puStack_10c = local_a0;
  FUN_004f1810(param_1);
  puStack_104 = &local_90;
  puStack_108 = local_50;
  puStack_10c = local_50;
  D3DXMatrixMultiply();
  iVar11 = *(int *)(*(int *)(param_2 + 0x54) + 0x18);
  if ((iVar11 != 1) && (iVar11 != 9)) {
    return;
  }
  fVar12 = -0.5;
  afStack_f4[0] = 0.0;
  afStack_f4[2] = 0.5;
  afStack_f4[3] = -0.5;
  afStack_f4[4] = 0.0;
  fStack_dc = 0.5;
  fStack_d8 = 0.5;
  fStack_d4 = 0.0;
  fStack_cc = -0.5;
  fStack_c8 = 0.5;
  fStack_c4 = 0.0;
  iVar11 = 4;
  ppuVar5 = &puStack_10c;
  do {
    puVar9 = (undefined1 *)((int)ppuVar5 + 0x10);
    D3DXVec3Transform(puVar9,puVar9,local_5c);
    *(undefined4 *)((int)ppuVar5 + 0x18) = 0;
    fVar13 = afStack_f4[2];
    fVar1 = afStack_f4[0];
    iVar11 = iVar11 + -1;
    ppuVar5 = (undefined1 **)puVar9;
  } while (iVar11 != 0);
  uVar6 = *(uint *)(param_2 + 0xb0) & 0xfffffffe;
  *(uint *)(param_2 + 0xb0) = uVar6;
  if ((((-0.499 < fStack_cc) || (-0.501 < fStack_cc == (fStack_cc == -0.501))) ||
      (afStack_f4[2] + 0.001 < fStack_dc)) ||
     (((afStack_f4[2] - 0.001 < fStack_dc == (afStack_f4[2] - 0.001 == fStack_dc) ||
       (-0.499 < afStack_f4[3])) ||
      ((-0.501 < afStack_f4[3] == (afStack_f4[3] == -0.501) ||
       ((fStack_d8 + 0.001 < fStack_c8 ||
        (fStack_d8 - 0.001 < fStack_c8 == (fStack_d8 - 0.001 == fStack_c8))))))))) {
    if ((-0.499 < afStack_f4[2]) ||
       (((((-0.501 < afStack_f4[2] == (afStack_f4[2] == -0.501) || (fStack_dc + 0.001 < fStack_cc))
          || (fStack_dc - 0.001 < fStack_cc == (fStack_dc - 0.001 == fStack_cc))) ||
         ((-0.499 < fStack_c8 || (-0.501 < fStack_c8 == (fStack_c8 == -0.501))))) ||
        ((afStack_f4[3] + 0.001 < fStack_d8 ||
         (afStack_f4[3] - 0.001 < fStack_d8 == (afStack_f4[3] - 0.001 == fStack_d8)))))))
    goto LAB_004f2ba7;
    *(uint *)(param_2 + 0xb0) = uVar6 | 1;
    fStack_a4 = afStack_f4[0];
    afStack_f4[0] = afStack_f4[4];
    afStack_f4[2] = fStack_dc;
    afStack_f4[3] = fStack_d8;
    afStack_f4[4] = fStack_d4;
    fStack_dc = fStack_cc;
    fStack_d8 = fStack_c8;
    fStack_d4 = fStack_c4;
    fStack_c4 = fVar1;
    fStack_cc = fVar12;
    fStack_c8 = -0.5;
  }
  else {
    *(uint *)(param_2 + 0xb0) = uVar6 | 1;
    fVar13 = fVar12;
  }
  FEQuad__SortCorners();
  fVar12 = fVar13;
LAB_004f2ba7:
  iStack_b4 = (int)local_5c - (param_2 + 0x60);
  puStack_b8 = &stack0xffffff04 + -(param_2 + 0x60);
  uVar6 = 0;
  pfVar10 = (float *)(param_2 + 0x68);
  iVar11 = 0;
  do {
    uStack_b0 = uVar6 + 1;
    uVar7 = uVar6 + 1 & 3;
    iVar8 = uVar7 * 0x10;
    fVar1 = *(float *)(&stack0xffffff04 + iVar8);
    fVar13 = *(float *)(&stack0xffffff04 + iVar11);
    *pfVar10 = 0.0;
    fVar2 = *(float *)(&stack0xffffff08 + iVar8);
    fVar3 = afStack_f4[uVar7 * 4];
    fVar4 = *(float *)(puStack_b8 + (int)pfVar10);
    fStack_a4 = fVar3 - fVar4;
    *(float *)((int)local_5c + iVar11) = fVar1 - fVar13;
    *(float *)(iStack_b4 + -4 + (int)pfVar10) = fVar2 - *(float *)(&stack0xffffff08 + iVar11);
    *(float *)(iStack_b4 + (int)pfVar10) = fVar3 - fVar4;
    fVar1 = *(float *)((int)local_5c + iVar11 + 4);
    pfVar10[-1] = *(float *)((int)local_5c + iVar11);
    pfVar10[-2] = -fVar1;
    bNormalize3();
    iVar8 = iVar11 + 0x10;
    *(float *)(param_2 + 0xa0 + uVar6 * 4) =
         -(*extraout_EDX * *(float *)(&stack0xffffff04 + iVar11) +
          *(float *)(puStack_b8 + (int)pfVar10) * *pfVar10 +
          pfVar10[-1] * *(float *)(&stack0xffffff08 + iVar11));
    uVar6 = uStack_b0;
    pfVar10 = pfVar10 + 4;
    iVar11 = iVar8;
  } while (iVar8 < 0x40);
  if ((*(byte *)(param_2 + 0xb0) & 1) != 0) {
    *(float *)(param_2 + 0xac) = fVar12;
    *(float *)(param_2 + 0xa0) = afStack_f4[3];
    *(float *)(param_2 + 0xa4) = fStack_dc;
    *(float *)(param_2 + 0xa8) = fStack_c8;
  }
  return;
}


// ==== 0x4f2cb0 FUN_004f2cb0

void FUN_004f2cb0(void)

{
  int in_EAX;
  undefined4 *puVar1;
  int unaff_EDI;
  
  if (*(int *)(in_EAX + 0x18) == 7) {
    *(uint *)(in_EAX + 0x1c) = *(uint *)(in_EAX + 0x1c) | 0x2000000;
  }
  puVar1 = *(undefined4 **)(unaff_EDI + 0x10);
  do {
    if (puVar1 == (undefined4 *)(unaff_EDI + 0x10)) {
      puVar1 = (undefined4 *)0x0;
LAB_004f2cdd:
      switch(*(int *)(in_EAX + 0x18)) {
      case 1:
        FUN_004f2000(unaff_EDI,in_EAX);
        return;
      case 2:
        FUN_004f25f0(puVar1);
        return;
      case 7:
        FUN_004f1d80(unaff_EDI,in_EAX,puVar1);
        break;
      case 9:
        FUN_004f2280(unaff_EDI,in_EAX);
        return;
      }
      return;
    }
    if (puVar1[2] == in_EAX) {
      if ((((uint)puVar1[3] >> 1 & 1) != 0) && ((*(uint *)(in_EAX + 0x1c) & 0x2000000) == 0)) {
        FUN_00514b90(puVar1);
        return;
      }
      goto LAB_004f2cdd;
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}


// ==== 0x4f2d60 FUN_004f2d60

void __fastcall FUN_004f2d60(int param_1)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int *piVar3;
  int *piVar4;
  
  piVar3 = (int *)(in_EAX + 0x10);
  piVar4 = (int *)*piVar3;
  if (piVar4 != piVar3) {
    while (piVar4[2] != param_1) {
      piVar4 = (int *)*piVar4;
      if (piVar4 == piVar3) {
        return;
      }
    }
    iVar1 = *piVar4;
    piVar3 = (int *)piVar4[1];
    *piVar3 = iVar1;
    *(int **)(iVar1 + 4) = piVar3;
    FUN_00514510();
    iVar2 = DAT_00735704;
    iVar1 = *(int *)(DAT_00735704 + 0x18);
    *piVar4 = *(int *)(DAT_00735704 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(int **)(iVar2 + 0x10) = piVar4;
  }
  return;
}


// ==== 0x4f2db0 FUN_004f2db0

void FUN_004f2db0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_00567160();
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2[2] = param_2;
    piVar2[5] = param_3;
    piVar2[3] = 0;
    piVar2[4] = 0;
    piVar1 = piVar2 + 6;
    *piVar1 = (int)piVar1;
    piVar2[7] = (int)piVar1;
    piVar2[8] = 0x3f800000;
    piVar2[9] = 0;
    piVar2[10] = 0;
    piVar2[0xb] = 0;
    piVar2[0xc] = 0;
    piVar2[0xd] = 0x3f800000;
    piVar2[0xe] = 0;
    piVar2[0xf] = 0;
    piVar2[0x10] = 0;
    piVar2[0x11] = 0;
    piVar2[0x12] = 0x3f800000;
    piVar2[0x13] = 0;
    piVar2[0x14] = 0;
    piVar2[0x15] = 0;
    piVar2[0x16] = 0;
    piVar2[0x17] = 0x3f800000;
  }
  piVar1 = *(int **)(param_1 + 0x14);
  *piVar1 = (int)piVar2;
  *(int **)(param_1 + 0x14) = piVar2;
  piVar2[1] = (int)piVar1;
  *piVar2 = param_1 + 0x10;
  return;
}


// ==== 0x4f2e30 FUN_004f2e30

void __thiscall FUN_004f2e30(uint param_1,int param_2)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  
  iVar1 = (param_1 & 0xffff) * 0xd0 + 0x20 + in_EAX;
  FUN_004f1810(in_EAX,iVar1,*(undefined2 *)(param_2 + 0x20),0x3f800000);
  *(undefined1 *)(iVar1 + 0xc0) = 1;
  if (*(int *)(iVar1 + 0x50) != param_2) {
    *(int *)(iVar1 + 0x50) = param_2;
    *(undefined4 *)(iVar1 + 0x54) = 0;
    iVar2 = *(int *)(param_2 + 0x60);
    if (iVar2 != 0) {
      while (((*(int *)(iVar2 + 0x18) != 1 && (*(int *)(iVar2 + 0x18) != 9)) ||
             ((*(byte *)(iVar2 + 0x1c) & 4) == 0))) {
        iVar2 = *(int *)(iVar2 + 4);
        if (iVar2 == 0) {
          return;
        }
      }
      *(int *)(iVar1 + 0x54) = iVar2;
    }
  }
  return;
}


// ==== 0x4f2eb0 FUN_004f2eb0

void FUN_004f2eb0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_EAX;
  int iVar4;
  int iVar5;
  int *piVar6;
  bool bVar7;
  
  piVar6 = (int *)(in_EAX + 0x70);
  iVar5 = 0x40;
  do {
    if (((((char)piVar6[0x1c] != '\0') && (piVar6[1] != 0)) && (*piVar6 != 0)) &&
       ((*(uint *)(*piVar6 + 0x1c) & 0x2000000) != 0)) {
      FUN_004f2810(in_EAX,piVar6 + -0x14);
    }
    piVar6 = piVar6 + 0x34;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  piVar6 = &DAT_00746910;
  iVar5 = DAT_007349b4;
  do {
    piVar1 = (int *)*piVar6;
    if (piVar1 != piVar6) {
      for (; piVar1 != piVar6; piVar1 = (int *)*piVar1) {
        FUN_004f2cb0();
        iVar5 = DAT_007349b4;
      }
      piVar1 = (int *)*piVar6;
      while (piVar1 != piVar6) {
        piVar1 = (int *)*piVar6;
        iVar4 = *piVar1;
        piVar2 = (int *)piVar1[1];
        *piVar2 = iVar4;
        *(int **)(iVar4 + 4) = piVar2;
        iVar4 = *(int *)(iVar5 + 0x18);
        *piVar1 = *(int *)(iVar5 + 0x10);
        *(int **)(iVar5 + 0x10) = piVar1;
        iVar4 = iVar4 + -1;
        bVar7 = DAT_007349b8 != 0;
        *(int *)(iVar5 + 0x18) = iVar4;
        iVar3 = DAT_007349b4;
        if (bVar7) {
          if (iVar4 == 0) {
            if (DAT_0073d814 != 0) {
              FUN_00407da0(&DAT_0073d818);
            }
            if (((*(byte *)(iVar5 + 0x14) & 8) != 0) && (0 < *(int *)(iVar5 + 0x18))) {
              FUN_00566f20(iVar5,0);
            }
            do {
              iVar5 = *(int *)(iVar5 + 8);
              FUN_00565ce0();
              iVar3 = iVar5;
            } while (iVar5 != 0);
          }
          else {
            DAT_007349b8 = 1;
          }
        }
        DAT_007349b4 = iVar3;
        piVar1 = (int *)*piVar6;
      }
    }
    piVar6 = piVar6 + -2;
  } while (0x746117 < (int)piVar6);
  return;
}


// ==== 0x4f2fd0 FEObject::SetAlphaClamped

/* [canon] hud med (ghidra-canon+hopper) docs/re/canon.md */

void FEObject__SetAlphaClamped(void)

{
  undefined4 in_EAX;
  int iVar1;
  
  iVar1 = _ftol_nocw();
  if (0xff < iVar1) {
    HudWidget__RegisterObject(in_EAX);
    return;
  }
  HudWidget__RegisterObject(in_EAX);
  return;
}


// ==== 0x4f3030 FEng::RenderPackages

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] hud med (ghidra+hopper+capstone) docs/re/hud_input.md */

void FEng__RenderPackages(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 **ppuVar3;
  undefined4 *puVar4;
  undefined1 *puStack_2ac;
  int *piStack_2a8;
  undefined4 *puStack_2a4;
  int *piStack_2a0;
  undefined4 *puStack_29c;
  undefined4 *puStack_298;
  undefined4 *puStack_294;
  int local_27c;
  float local_278;
  float local_274;
  undefined4 local_270;
  undefined4 local_26c;
  undefined4 local_268;
  undefined4 local_264;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined4 local_254;
  undefined4 local_250;
  undefined4 local_24c;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  float local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  float local_21c;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  float local_1c0;
  float local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 **local_e8;
  undefined4 *local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  float local_d8;
  undefined4 *local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  float local_c8;
  float local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 **local_b8;
  float local_b4;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  
  DAT_007357a8 = 0;
  if ((param_1 != DAT_007357a0) || (param_2 != DAT_007357a4)) {
    _DAT_00746110 = DAT_0073ad3c;
    DAT_007357a8 = 1;
  }
  local_278 = (float)(DAT_0073ad3c - _DAT_00746110);
  if (((float)(int)local_278 * 0.00025 <= 2.0) || (DAT_0077a920 == 3)) {
    puStack_294 = (undefined4 *)0x0;
    puStack_298 = (undefined4 *)0x1;
    puStack_29c = (undefined4 *)0x6b6a294f;
    DAT_007357a0 = param_1;
    DAT_007357a4 = param_2;
    local_130 = 0x3f800000;
    local_12c = 0;
    local_128 = 0;
    local_124 = 0;
    local_120 = 0;
    local_11c = 0x3f800000;
    local_118 = 0;
    local_114 = 0;
    local_110 = 0;
    local_10c = 0;
    local_108 = 0x3f800000;
    local_104 = 0;
    local_f4 = 0x3f800000;
    local_100 = 0x43a00000;
    local_fc = 0x43700000;
    local_f8 = 0;
    piStack_2a0 = (int *)0x4f3166;
    iVar1 = Texture_FindByHash();
    local_278 = (float)param_1;
    local_1f0 = 0x3f800000;
    local_1ec = 0;
    local_274 = (float)param_2;
    local_1e8 = 0;
    local_1e4 = 0;
    local_1e0 = 0;
    local_1dc = 0x3f800000;
    local_1d8 = 0;
    local_1d4 = 0;
    local_1d0 = 0;
    local_1cc = 0;
    local_1c8 = 0x3f800000;
    local_1c4 = 0;
    local_1b4 = 0x3f800000;
    local_1b8 = 0;
    local_170 = 0x3f800000;
    local_16c = 0;
    local_168 = 0;
    local_164 = 0;
    local_160 = 0;
    local_15c = 0x3f800000;
    local_158 = 0;
    local_154 = 0;
    local_150 = 0;
    local_14c = 0;
    local_148 = 0x3f800000;
    local_144 = 0;
    local_140 = 0;
    local_13c = 0;
    local_138 = 0;
    local_134 = 0x3f800000;
    local_1b0 = 0x3f800000;
    local_1ac = 0;
    local_1a8 = 0;
    local_1a4 = 0;
    local_1a0 = 0;
    local_19c = 0x3f800000;
    local_198 = 0;
    local_194 = 0;
    local_190 = 0;
    local_18c = 0;
    local_188 = 0x3f800000;
    local_184 = 0;
    local_180 = 0;
    local_17c = 0;
    local_178 = 0;
    local_174 = 0x3f800000;
    local_22c = 0;
    local_228 = 0;
    local_224 = 0;
    local_220 = 0;
    local_218 = 0;
    local_214 = 0;
    local_210 = 0;
    local_20c = 0;
    local_204 = 0;
    local_200 = 0;
    local_1fc = 0;
    local_1f8 = 0;
    local_1f4 = 0x3f800000;
    puStack_294 = &local_270;
    local_230 = (float)(int)*(short *)(iVar1 + 0x44);
    puStack_298 = &local_1f0;
    local_27c = (int)*(short *)(iVar1 + 0x46);
    puStack_29c = &local_270;
    local_21c = (float)local_27c;
    local_208 = 0;
    local_f0 = 0x3f800000;
    local_ec = 0;
    local_e8 = (undefined4 **)0x0;
    local_e4 = (undefined4 *)0x0;
    local_e0 = 0;
    local_dc = 0x3f800000;
    local_d8 = 0.0;
    local_d4 = (undefined4 *)0x0;
    local_d0 = 0;
    local_cc = 0;
    local_c8 = 1.0;
    local_c4 = 0.0;
    local_c0 = 0;
    local_bc = 0;
    local_b8 = (undefined4 **)0x0;
    local_b4 = 1.0;
    local_270 = 0x3f800000;
    local_26c = 0;
    local_268 = 0;
    local_264 = 0;
    local_260 = 0;
    local_25c = 0x3f800000;
    local_258 = 0;
    local_254 = 0;
    local_250 = 0;
    local_24c = 0;
    local_248 = 0x3f800000;
    local_244 = 0;
    local_240 = 0;
    local_23c = 0;
    local_238 = 0;
    local_234 = 0x3f800000;
    piStack_2a0 = (int *)0x4f358e;
    local_1c0 = local_278;
    local_1bc = local_274;
    D3DXMatrixMultiply();
    piStack_2a0 = &local_27c;
    puStack_2a4 = &local_17c;
    piStack_2a8 = &local_27c;
    puStack_2ac = (undefined1 *)0x4f35a5;
    D3DXMatrixMultiply();
    puStack_2ac = &stack0xfffffd78;
    D3DXMatrixMultiply(&stack0xfffffd78,&local_108);
    puVar4 = &local_1d4;
    ppuVar3 = &puStack_294;
    D3DXMatrixMultiply(ppuVar3,puVar4,&puStack_294);
    D3DXMatrixMultiply(&piStack_2a0,&local_260,&piStack_2a0);
    D3DXMatrixMultiply(&puStack_2ac,&puStack_2ac,&local_16c);
    if (*(short *)(iVar1 + 0x44) != 0) {
      uVar2 = (int)*(short *)(iVar1 + 0x44) - 1;
      do {
        uVar2 = uVar2 >> 1;
      } while (uVar2 != 0);
    }
    if (*(short *)(iVar1 + 0x46) != 0) {
      uVar2 = (int)*(short *)(iVar1 + 0x46) - 1;
      do {
        uVar2 = uVar2 >> 1;
      } while (uVar2 != 0);
    }
    puStack_2ac = (undefined1 *)0x0;
    piStack_2a8 = (int *)0x0;
    puStack_2a4 = (undefined4 *)0x3f800000;
    piStack_2a0 = (int *)0x0;
    puStack_29c = (undefined4 *)0x0;
    puStack_298 = (undefined4 *)0x0;
    puStack_294 = (undefined4 *)0x0;
    local_27c = 0x3f800000;
    ePoly__ePoly();
    local_d8 = (float)(*(short *)(iVar1 + 0x44) + param_1);
    uStack_78 = 0x80808080;
    uStack_74 = 0x80808080;
    local_c4 = (float)(*(short *)(iVar1 + 0x46) + param_2);
    uStack_70 = 0x80808080;
    uStack_a8 = 0;
    uStack_a4 = 0;
    uStack_a0 = 0x3f800000;
    uStack_9c = 0x3f800000;
    uStack_98 = 0;
    uStack_94 = 0x3f800000;
    uStack_90 = 0x3f800000;
    uStack_8c = 0x3f800000;
    uStack_88 = 0x3f800000;
    uStack_84 = 0;
    uStack_80 = 0x3f800000;
    uStack_7c = 0x3f800000;
    uStack_6c = 0x80808080;
    local_e8 = ppuVar3;
    local_e4 = puVar4;
    local_d4 = puVar4;
    local_c8 = local_d8;
    local_b8 = ppuVar3;
    local_b4 = local_c4;
    FUN_0040bef0();
  }
  return;
}


// ==== 0x4f37e0 FEScreenRegistry::CreateScreen

/* [canon] hud high (ghidra+capstone) docs/re/gameflow.md */

undefined4 FEScreenRegistry__CreateScreen(undefined4 param_1)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  int in_EAX;
  undefined4 uVar4;
  int iVar5;
  byte *pbVar6;
  undefined **ppuVar7;
  int iVar8;
  undefined *local_10;
  undefined4 local_c;
  int local_8;
  undefined4 local_4;
  
  iVar8 = 0;
  ppuVar7 = &PTR_s_Options_fng_006f94d8;
  while( true ) {
    pbVar6 = *ppuVar7;
    iVar5 = -1;
    if (pbVar6 != (byte *)0x0) {
      bVar2 = *pbVar6;
      while (bVar2 != 0) {
        if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
          bVar2 = bVar2 - 0x20;
        }
        iVar5 = iVar5 * 0x21 + (uint)bVar2;
        pbVar1 = pbVar6 + 1;
        pbVar6 = pbVar6 + 1;
        bVar2 = *pbVar1;
      }
    }
    if (in_EAX == iVar5) break;
    ppuVar7 = ppuVar7 + 5;
    iVar8 = iVar8 + 1;
    if (0x6f9fdb < (int)ppuVar7) {
      return 0;
    }
  }
  iVar5 = iVar8 * 0x14;
  local_10 = (&PTR_s_Options_fng_006f94d8)[iVar8 * 5];
  local_c = param_1;
  local_4 = *(undefined4 *)(iVar5 + 0x6f94e8);
  local_8 = iVar5 + 0x6f94e4;
  uVar4 = (*(code *)(&PTR_Screen_Options__Create_006f94dc)[iVar8 * 5])(&local_10);
  if (*(int *)(iVar5 + 0x6f94e0) == 0) {
    cVar3 = FUN_004f3d60();
    if (((((cVar3 == '\0') &&
          (iVar5 = FEPackageList__FindByName(&DAT_00746104), iVar8 = DAT_0073578c, iVar5 != 0)) &&
         (*(int *)(iVar5 + 0x18) != 0)) &&
        ((DAT_0073578c != 0 && (iVar5 = FEPackageList__FindByName(&DAT_00746104), iVar5 != 0)))) &&
       (*(int *)(iVar5 + 0x18) != 0)) {
      cFEng__PopPackage(*(undefined4 *)(iVar8 + 8),*(int *)(iVar5 + 0x18));
    }
  }
  else {
    iVar8 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar8 == 0) || (*(int *)(iVar8 + 0x18) == 0)) && (DAT_0073578c != 0)) {
      iVar5 = *(int *)(DAT_0073578c + 8);
      iVar8 = iVar5 + 0xdc;
      if ((iVar8 == 0) || (iVar8 = FUN_004fd1e0(iVar8), iVar8 == 0)) {
        cFEng__PushPackage(iVar5,"MU_HorizontalBrowserBack.fng",0x10,0);
        return uVar4;
      }
    }
  }
  return uVar4;
}


// ==== 0x4f3940 FEScreenRegistry::FindEntry

/* [canon] hud med (ghidra) docs/re/gameflow.md */

undefined ** FEScreenRegistry__FindEntry(void)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  int unaff_EBX;
  undefined **ppuVar5;
  int iVar6;
  
  iVar6 = 0;
  ppuVar5 = &PTR_s_Options_fng_006f94d8;
  while( true ) {
    pbVar4 = *ppuVar5;
    iVar3 = -1;
    if (pbVar4 != (byte *)0x0) {
      bVar2 = *pbVar4;
      while (bVar2 != 0) {
        if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
          bVar2 = bVar2 - 0x20;
        }
        iVar3 = iVar3 * 0x21 + (uint)bVar2;
        pbVar1 = pbVar4 + 1;
        pbVar4 = pbVar4 + 1;
        bVar2 = *pbVar1;
      }
    }
    if (unaff_EBX == iVar3) break;
    ppuVar5 = ppuVar5 + 5;
    iVar6 = iVar6 + 1;
    if (0x6f9fdb < (int)ppuVar5) {
      return (undefined **)0x0;
    }
  }
  return &PTR_s_Options_fng_006f94d8 + iVar6 * 5;
}


// ==== 0x4f39a0 FEScreenRegistry::SetFactory

/* [canon] hud med (ghidra) docs/re/gameflow.md */

void FEScreenRegistry__SetFactory(byte *param_1,undefined *param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined **ppuVar5;
  
  ppuVar5 = &PTR_s_Options_fng_006f94d8;
  do {
    pbVar3 = *ppuVar5;
    pbVar4 = param_1;
    do {
      bVar2 = *pbVar4;
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 & 0x5f;
      }
      bVar1 = *pbVar3;
      pbVar4 = pbVar4 + 1;
      if (('`' < (char)bVar1) && ((char)bVar1 < '{')) {
        bVar1 = bVar1 & 0x5f;
      }
      pbVar3 = pbVar3 + 1;
    } while (((bVar2 != 0) && (bVar1 != 0)) && (bVar2 == bVar1));
    if (bVar2 == bVar1) {
      ppuVar5[1] = param_2;
    }
    ppuVar5 = ppuVar5 + 5;
  } while ((int)ppuVar5 < 0x6f9fdc);
  return;
}


// ==== 0x4f3a00 FEPackageData::FEPackageData

/* [canon] assets med (Ghidra make FUN_004f3a00) docs/re/assets.md */

undefined4 * __fastcall FEPackageData__FEPackageData(undefined4 *param_1)

{
  int *in_EAX;
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  *param_1 = &PTR_FUN_006c1eac;
  *(undefined2 *)((int)param_1 + 0x1e) = 1;
  param_1[4] = in_EAX;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  *(undefined2 *)(param_1 + 7) = 0;
  param_1[8] = 0;
  if (*in_EAX == 0x30203) {
    param_1[3] = in_EAX + 2;
  }
  else if (*in_EAX == 0x30210) {
    param_1[3] = 0;
  }
  if (*in_EAX == 0x30203) {
    piVar1 = (int *)Resource_DecompressIfCOMP();
    if (((*piVar1 == -0x1891baba) && (piVar1[2] == 0x64486b50)) && (0x1ffff < (uint)piVar1[4])) {
      iVar2 = FEng__HashName();
      goto LAB_004f3a89;
    }
  }
  else if (*in_EAX == 0x30210) {
    iVar2 = in_EAX[2];
    goto LAB_004f3a89;
  }
  iVar2 = 0;
LAB_004f3a89:
  NullChunk__Loader("Load Package[%x]\n",iVar2);
  if (*(int *)param_1[4] == 0x30203) {
    piVar1 = (int *)Resource_DecompressIfCOMP();
    if (((*piVar1 == -0x1891baba) && (piVar1[2] == 0x64486b50)) && (0x1ffff < (uint)piVar1[4])) {
      FEng__HashName();
      uVar3 = FEScreenRegistry__FindEntry();
      param_1[8] = uVar3;
      return param_1;
    }
  }
  else if (*(int *)param_1[4] == 0x30210) {
    uVar3 = FEScreenRegistry__FindEntry();
    param_1[8] = uVar3;
    return param_1;
  }
  uVar3 = FEScreenRegistry__FindEntry();
  param_1[8] = uVar3;
  return param_1;
}


// ==== 0x4f3b10 FUN_004f3b10

void * __thiscall FUN_004f3b10(void *param_1,byte param_2)

{
  FUN_004f3b30();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4f3b30 FUN_004f3b30

void __fastcall FUN_004f3b30(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c1eac;
  if ((*(int *)param_1[4] != 0x30203) && (*(int *)param_1[4] == 0x30210)) {
    FUN_00565ce0();
  }
  param_1[3] = 0;
  return;
}


// ==== 0x4f3b60 FEPackageData::Activate

/* [canon] hud high (ghidra+capstone) docs/re/gameflow.md */

void FEPackageData__Activate(void)

{
  int in_EAX;
  int *piVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  *(int *)(in_EAX + 0x18) = unaff_ESI;
  if ((((**(int **)(in_EAX + 0x10) == 0x30203) &&
       (piVar1 = (int *)Resource_DecompressIfCOMP(), *piVar1 == -0x1891baba)) &&
      (piVar1[2] == 0x64486b50)) && (0x1ffff < (uint)piVar1[4])) {
    FEng__HashName();
  }
  uVar2 = FEScreenRegistry__CreateScreen();
  *(undefined4 *)(in_EAX + 0x14) = uVar2;
  *(undefined4 *)(in_EAX + 0x24) = *(undefined4 *)(unaff_ESI + 0x1c);
  NullChunk__Loader("Activate %s\n",*(undefined4 *)(unaff_ESI + 0xc));
  return;
}


// ==== 0x4f3bd0 FEPackageData::Deactivate

/* [canon] hud high (ghidra+hopper) docs/re/gameflow.md */

void FEPackageData__Deactivate(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar1 = DAT_0073578c;
  if (*(int *)(unaff_ESI + 0x18) != 0) {
    if (((DAT_0073578c != 0) && (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
       (*(int *)(iVar2 + 0x18) != 0)) {
      cFEng__PopPackage(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
    }
    if (*(undefined4 **)(unaff_ESI + 0x14) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(unaff_ESI + 0x14))(1);
    }
    *(undefined4 *)(unaff_ESI + 0x14) = 0;
    *(undefined4 *)(unaff_ESI + 0x18) = 0;
    if (**(int **)(unaff_ESI + 0x10) == 0x30210) {
      FUN_00565ce0();
      *(undefined4 *)(unaff_ESI + 0xc) = 0;
    }
  }
  return;
}


// ==== 0x4f3c40 Resource_DecompressIfCOMP

/* [canon] assets med (hopper+capstone) docs/re/misc.md */

undefined4 Resource_DecompressIfCOMP(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EDI;
  
  piVar1 = *(int **)(unaff_EDI + 0x10);
  if (*piVar1 == 0x30203) {
    return *(undefined4 *)(unaff_EDI + 0xc);
  }
  if (*piVar1 == 0x30210) {
    iVar2 = FUN_00565b60(piVar1[5],0,0,0);
    *(int *)(unaff_EDI + 0xc) = iVar2;
    if (iVar2 != 0) {
      if (piVar1[3] == 0x504d4f43) {
        DecompressCOMP(iVar2);
        return *(undefined4 *)(unaff_EDI + 0xc);
      }
      if (piVar1[3] == 0x5a4c444a) {
        FUN_0058d190();
      }
    }
    return *(undefined4 *)(unaff_EDI + 0xc);
  }
  return 0;
}


// ==== 0x4f3cb0 FUN_004f3cb0

int FUN_004f3cb0(void)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  
  iVar2 = **(int **)(in_EAX + 0x10);
  if (iVar2 == 0x30203) {
    piVar1 = (int *)Resource_DecompressIfCOMP();
    if (((*piVar1 == -0x1891baba) && (piVar1[2] == 0x64486b50)) && (0x1ffff < (uint)piVar1[4])) {
      iVar2 = FEng__HashName();
      return iVar2;
    }
  }
  else if (iVar2 == 0x30210) {
    return (*(int **)(in_EAX + 0x10))[2];
  }
  return 0;
}


// ==== 0x4f3d00 FUN_004f3d00

void __fastcall FUN_004f3d00(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = param_1 + 1;
  *param_1 = &PTR_FUN_006c1ea8;
  piVar2 = (int *)*piVar1;
  while (piVar2 != piVar1) {
    iVar3 = *piVar2;
    piVar4 = (int *)piVar2[1];
    *piVar4 = iVar3;
    *(int **)(iVar3 + 4) = piVar4;
    if (piVar2 + -1 != (int *)0x0) {
      (**(code **)piVar2[-1])(1);
    }
    piVar2 = (int *)*piVar1;
  }
  return;
}


// ==== 0x4f3d30 FEngLibrary::FEngLibrary

/* [canon] hud low (ghidra-canon) docs/re/canon.md */

void FEngLibrary__FEngLibrary(void)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  
  puVar1 = in_EAX + 1;
  *in_EAX = &PTR_FUN_006c1ea8;
  *puVar1 = puVar1;
  in_EAX[2] = puVar1;
  return;
}


// ==== 0x4f3d40 FUN_004f3d40

void * __thiscall FUN_004f3d40(void *param_1,byte param_2)

{
  FUN_004f3d00();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4f3d60 FUN_004f3d60

int __fastcall FUN_004f3d60(undefined4 param_1,int param_2)

{
  int iVar1;
  uint3 uVar2;
  int iVar3;
  
  if (*(int *)(param_2 + 4) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_2 + 4) + -4;
  }
  while( true ) {
    iVar3 = param_2;
    if (param_2 == -4) {
      iVar3 = 0;
    }
    uVar2 = (uint3)((uint)iVar1 >> 8);
    if (iVar1 == iVar3) break;
    if (((*(int *)(iVar1 + 0x18) != 0) && (*(int *)(iVar1 + 0x20) != 0)) &&
       (*(int *)(*(int *)(iVar1 + 0x20) + 8) != 0)) {
      return CONCAT31(uVar2,1);
    }
    if (*(int *)(iVar1 + 4) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 4) + -4;
    }
  }
  return (uint)uVar2 << 8;
}


// ==== 0x4f3dc0 FEManager::BroadcastMessage

/* [canon] hud med (ghidra) docs/re/gameflow.md */

void __fastcall FEManager__BroadcastMessage(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int aiStack_80 [32];
  
  iVar1 = *(int *)(param_2 + 4);
  iVar3 = 0;
  while( true ) {
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = iVar1 + -4;
    }
    iVar2 = param_2;
    if (param_2 == -4) {
      iVar2 = 0;
    }
    if (iVar1 == iVar2) break;
    if ((*(int *)(iVar1 + 0x18) != 0) && (iVar3 < 0x20)) {
      aiStack_80[iVar3] = iVar1;
      iVar3 = iVar3 + 1;
    }
    iVar1 = *(int *)(iVar1 + 4);
  }
  iVar1 = 0;
  if (0 < iVar3) {
    do {
      iVar2 = *(int *)(aiStack_80[iVar1] + 0x18);
      if ((iVar2 != 0) && (*(int *)(aiStack_80[iVar1] + 0x14) != 0)) {
        FUN_004f7c00(param_3,0,0,iVar2);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar3);
  }
  return;
}


// ==== 0x4f3e50 FUN_004f3e50

int __fastcall FUN_004f3e50(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 4);
  iVar3 = 0;
  while( true ) {
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = iVar6 + -4;
    }
    iVar5 = param_1;
    if (param_1 == -4) {
      iVar5 = 0;
    }
    if (iVar6 == iVar5) break;
    if (*(int *)(iVar6 + 0x18) != 0) {
      pbVar4 = *(byte **)(*(int *)(iVar6 + 0x18) + 0xc);
      iVar5 = -1;
      bVar2 = *pbVar4;
      while (bVar2 != 0) {
        iVar5 = iVar5 * 0x21 + (uint)bVar2;
        pbVar1 = pbVar4 + 1;
        pbVar4 = pbVar4 + 1;
        bVar2 = *pbVar1;
      }
      iVar3 = iVar3 + iVar5;
    }
    iVar6 = *(int *)(iVar6 + 4);
  }
  return iVar3;
}


// ==== 0x4f3eb0 FUN_004f3eb0

void FUN_004f3eb0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_EAX;
  int iVar1;
  int unaff_EBX;
  int iVar2;
  
  if (*(int *)(in_EAX + 4) == 0) goto LAB_004f3ec8;
  iVar2 = *(int *)(in_EAX + 4) + -4;
  while( true ) {
    iVar1 = in_EAX;
    if (in_EAX == -4) {
      iVar1 = 0;
    }
    if (iVar2 == iVar1) break;
    if (((*(int *)(iVar2 + 0x18) != 0) && (unaff_EBX == *(int *)(iVar2 + 0x18))) &&
       (*(int *)(iVar2 + 0x14) != 0)) {
      FUN_004f80e0(param_2,param_3,unaff_EBX);
    }
    if (*(int *)(iVar2 + 4) == 0) {
LAB_004f3ec8:
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 4) + -4;
    }
  }
  return;
}


// ==== 0x4f3f20 FUN_004f3f20

void FUN_004f3f20(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  
  if (*(int *)(in_EAX + 4) == 0) goto LAB_004f3f39;
  iVar2 = *(int *)(in_EAX + 4) + -4;
  while( true ) {
    iVar1 = in_EAX;
    if (in_EAX == -4) {
      iVar1 = 0;
    }
    if (iVar2 == iVar1) break;
    if (((*(int *)(iVar2 + 0x18) != 0) && (param_4 == *(int *)(iVar2 + 0x18))) &&
       (*(int *)(iVar2 + 0x14) != 0)) {
      FUN_004f7c00(param_1,param_2,param_3,param_4);
    }
    if (*(int *)(iVar2 + 4) == 0) {
LAB_004f3f39:
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 4) + -4;
    }
  }
  return;
}


// ==== 0x4f3f90 FEPackageList::FindByName

/* [canon] hud high (ghidra+capstone) docs/re/gameflow.md */

int FEPackageList__FindByName(int param_1)

{
  char cVar1;
  int *piVar2;
  char *in_EAX;
  int *piVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int *piVar7;
  int iVar8;
  
  iVar5 = 0;
  if (in_EAX != (char *)0x0) {
    cVar1 = *in_EAX;
    while (cVar1 != '\0') {
      iVar8 = iVar5 + 1;
      iVar5 = iVar5 + 1;
      cVar1 = in_EAX[iVar8];
    }
  }
  for (pcVar6 = in_EAX + iVar5; (pcVar6 != in_EAX && (*pcVar6 != '\\')); pcVar6 = pcVar6 + -1) {
  }
  iVar5 = FEng__HashName();
  piVar7 = (int *)(param_1 + 4);
  if (*piVar7 == 0) goto LAB_004f3fd9;
  iVar8 = *piVar7 + -4;
  do {
    iVar4 = param_1;
    if (piVar7 == (int *)0x0) {
      iVar4 = 0;
    }
    if (iVar8 == iVar4) {
      return 0;
    }
    iVar4 = **(int **)(iVar8 + 0x10);
    if (iVar4 == 0x30203) {
      piVar3 = (int *)Resource_DecompressIfCOMP();
      if (((*piVar3 == -0x1891baba) && (piVar3[2] == 0x64486b50)) && (0x1ffff < (uint)piVar3[4])) {
        iVar4 = FEng__HashName();
      }
      else {
LAB_004f4030:
        iVar4 = 0;
      }
    }
    else {
      if (iVar4 != 0x30210) goto LAB_004f4030;
      iVar4 = (*(int **)(iVar8 + 0x10))[2];
    }
    if (iVar4 == iVar5) {
      iVar5 = *(int *)(iVar8 + 4);
      piVar2 = *(int **)(iVar8 + 8);
      piVar3 = (int *)(iVar8 + 4);
      *piVar2 = iVar5;
      *(int **)(iVar5 + 4) = piVar2;
      iVar5 = *piVar7;
      *piVar7 = (int)piVar3;
      *(int **)(iVar5 + 4) = piVar3;
      *(int **)(iVar8 + 8) = piVar7;
      *piVar3 = iVar5;
      return iVar8;
    }
    if (*(int *)(iVar8 + 4) == 0) {
LAB_004f3fd9:
      iVar8 = 0;
    }
    else {
      iVar8 = *(int *)(iVar8 + 4) + -4;
    }
  } while( true );
}


// ==== 0x4f4070 FUN_004f4070

int __fastcall FUN_004f4070(undefined4 param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = (int *)(param_2 + 4);
  iVar3 = *piVar5;
  while( true ) {
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = iVar3 + -4;
    }
    iVar4 = param_2;
    if (piVar5 == (int *)0x0) {
      iVar4 = 0;
    }
    if (iVar3 == iVar4) break;
    if (*(int *)(iVar3 + 0x18) == in_EAX) {
      iVar4 = *(int *)(iVar3 + 4);
      piVar1 = (int *)(iVar3 + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *piVar2 = iVar4;
      *(int **)(iVar4 + 4) = piVar2;
      iVar4 = *piVar5;
      *piVar5 = (int)piVar1;
      *(int **)(iVar4 + 4) = piVar1;
      *piVar1 = iVar4;
      *(int **)(iVar3 + 8) = piVar5;
      return iVar3;
    }
    iVar3 = *(int *)(iVar3 + 4);
  }
  return 0;
}


// ==== 0x4f40c0 FUN_004f40c0

void FUN_004f40c0(int param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  
  if (*(int *)(in_EAX + 4) == 0) goto LAB_004f40d8;
  iVar2 = *(int *)(in_EAX + 4) + -4;
  while( true ) {
    iVar1 = in_EAX;
    if (in_EAX == -4) {
      iVar1 = 0;
    }
    if (iVar2 == iVar1) break;
    if ((*(short *)(iVar2 + 0x1c) == 0) || (param_1 != 0)) {
      FEPackageData__Deactivate();
    }
    if (*(int *)(iVar2 + 4) == 0) {
LAB_004f40d8:
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 4) + -4;
    }
  }
  return;
}


// ==== 0x4f4120 FEngLibrary::AddPackage

/* [canon] assets high (Hopper sub_4f4120 + Ghidra make: H+G agree) docs/re/assets.md */

void FEngLibrary__AddPackage(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006862d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar2 = _malloc(0x2c);
  local_4 = 0;
  if (pvVar2 != (void *)0x0) {
    iVar3 = FEPackageData__FEPackageData(pvVar2);
    if (iVar3 != 0) {
      puVar4 = (undefined4 *)(iVar3 + 4);
      goto LAB_004f4166;
    }
  }
  puVar4 = (undefined4 *)0x0;
LAB_004f4166:
  *DAT_0074610c = puVar4;
  puVar1 = puVar4;
  puVar4[1] = DAT_0074610c;
  DAT_0074610c = puVar1;
  *puVar4 = &DAT_00746108;
  ExceptionList = local_c;
  return;
}


// ==== 0x4f4190 FEngLibrary::RemovePackage

/* [canon] assets high (Ghidra make FUN_004f4190) docs/re/assets.md */

void FEngLibrary__RemovePackage(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int unaff_EDI;
  
  if (DAT_0073578c != 0) {
    FUN_004ef0b0(0);
  }
  if (param_1[1] == 0) goto LAB_004f41b7;
  puVar5 = (undefined4 *)(param_1[1] + -4);
  while( true ) {
    puVar3 = param_1;
    if (param_1 == (undefined4 *)0xfffffffc) {
      puVar3 = (undefined4 *)0x0;
    }
    if (puVar5 == puVar3) break;
    if (puVar5[4] == unaff_EDI) {
      uVar4 = FUN_004f3cb0();
      NullChunk__Loader("UNLOAD PACKAGE(%x)\n",uVar4);
      puVar5[10] = 0;
      FEPackageData__Deactivate();
      iVar1 = puVar5[1];
      piVar2 = (int *)puVar5[2];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
      (**(code **)*puVar5)(1);
      return;
    }
    if (puVar5[1] == 0) {
LAB_004f41b7:
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5 = (undefined4 *)(puVar5[1] + -4);
    }
  }
  return;
}


// ==== 0x4f4220 FUN_004f4220

void FUN_004f4220(void)

{
  int iVar1;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (iVar1 != 0) {
    if (*(undefined4 **)(iVar1 + 0x14) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(iVar1 + 0x14))(1);
    }
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(iVar1 + 0x18) = 0;
    if (**(int **)(iVar1 + 0x10) == 0x30210) {
      FUN_00565ce0();
      *(undefined4 *)(iVar1 + 0xc) = 0;
    }
  }
  return;
}


// ==== 0x4f4270 FUN_004f4270

undefined4 FUN_004f4270(void)

{
  int iVar1;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (iVar1 != 0) {
    return *(undefined4 *)(iVar1 + 0x14);
  }
  return 0;
}


// ==== 0x4f4290 FEngPackage::Loader

/* [canon] assets high (Ghidra make FUN_004f4290 (Hopper export lacks it; capstone agrees))
   docs/re/assets.md */

undefined4 FEngPackage__Loader(int *param_1)

{
  if ((*param_1 != 0x30203) && (*param_1 != 0x30210)) {
    return 0;
  }
  FEngLibrary__AddPackage(&DAT_00746104,param_1,0);
  return 1;
}


// ==== 0x4f42c0 FEngPackage::Unloader

/* [canon] assets high (Hopper sub_4f42c0 + Ghidra export FUN_004f42c0: H+G agree) docs/re/assets.md
    */

undefined4 FEngPackage__Unloader(int *param_1)

{
  if ((*param_1 != 0x30203) && (*param_1 != 0x30210)) {
    return 0;
  }
  FEngLibrary__RemovePackage(&DAT_00746104,0);
  return 1;
}


// ==== 0x4f42f0 FUN_004f42f0

int FUN_004f42f0(undefined4 param_1)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  byte local_100;
  byte local_ff [255];
  
  DAT_00730508 = &local_100;
  DAT_007304b8 = FUN_005669d0;
  DAT_007304bc = FUN_005669f0;
  iVar2 = bVPrintf(0,param_1,&stack0x00000008);
  pbVar3 = &local_100;
  if (iVar2 != -1) {
    *DAT_00730508 = 0;
  }
  iVar2 = -1;
  while (local_100 != 0) {
    iVar2 = iVar2 * 0x21 + (uint)local_100;
    pbVar1 = pbVar3 + 1;
    pbVar3 = pbVar3 + 1;
    local_100 = *pbVar1;
  }
  return iVar2;
}


// ==== 0x4f4360 FEngMemoryPool::Init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] hud high (ghidra+capstone) docs/re/gameflow.md */

void FEngMemoryPool__Init(void)

{
  undefined4 uVar1;
  
  if (DAT_006f94c8 != 0) {
    uVar1 = FUN_00565b60(DAT_006f94cc,0,0,0);
    _DAT_00735794 = uVar1;
    (&DAT_007301d4)[DAT_006f94c8] = &DAT_007301f8 + DAT_006f94c8 * 0x58;
    bInitMemoryPool(uVar1,"FEngMemoryPool");
    *(bool *)((&DAT_007301d4)[DAT_006f94c8] + 0x39) = DAT_00735798 != 0;
  }
  return;
}


// ==== 0x4f43d0 FEPackageList::FindByKeyWithAlias

/* [canon] hud med (ghidra-canon+hopper) docs/re/runtime.md */

undefined4 * FEPackageList__FindByKeyWithAlias(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  
  puVar2 = (undefined4 *)NullUpdate_ret();
  puVar1 = DAT_007460fc;
  do {
    for (; iVar4 = in_EAX, puVar1 != puVar2; puVar1 = (undefined4 *)*puVar1) {
      if (puVar1[5] == iVar4) {
        return puVar1;
      }
      in_EAX = iVar4;
    }
    piVar3 = &DAT_006f9490;
    while( true ) {
      if (0x6f9497 < (int)piVar3) {
        return (undefined4 *)0x0;
      }
      puVar1 = DAT_007460fc;
      in_EAX = piVar3[1];
      if (iVar4 == *piVar3) break;
      piVar3 = piVar3 + 2;
    }
  } while( true );
}


// ==== 0x4f4420 FEngFont_Load

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

undefined4 FEngFont_Load(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  
  if (*param_1 == 0x30201) {
    pvVar3 = _malloc(0x30);
    if (pvVar3 == (void *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)FEngFont_Init();
    }
    iVar2 = (int)DAT_007460fc;
    puVar1 = (undefined4 *)((int)DAT_007460fc + 4);
    DAT_007460fc = piVar4;
    *puVar1 = piVar4;
    piVar4[1] = (int)&DAT_007460fc;
    *piVar4 = iVar2;
    return 1;
  }
  return 0;
}


// ==== 0x4f4470 FEngFont_Unload

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 FEngFont_Unload(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *_Memory;
  
  if (*param_1 == 0x30201) {
    FEng__HashName();
    _Memory = (int *)FEPackageList__FindByKeyWithAlias();
    if (_Memory != (int *)0x0) {
      iVar1 = *_Memory;
      piVar2 = (int *)_Memory[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
      FUN_004f46b0();
      _free(_Memory);
    }
    return 1;
  }
  return 0;
}


// ==== 0x4f44c0 FEngFont_Init

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

void __fastcall FEngFont_Init(undefined4 param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  byte bVar8;
  int iVar9;
  int *piVar10;
  byte *pbVar11;
  byte *pbVar12;
  int unaff_EDI;
  int local_8;
  
  *(undefined4 *)(unaff_EDI + 8) = 0;
  *(undefined4 *)(unaff_EDI + 0xc) = 0;
  *(undefined4 *)(unaff_EDI + 0x10) = 0;
  *(undefined4 *)(unaff_EDI + 0x14) = 0;
  *(undefined4 *)(unaff_EDI + 0x18) = 0;
  *(undefined4 *)(unaff_EDI + 0x24) = 0;
  *(int *)(unaff_EDI + 0x1c) = param_2 + 8;
  *(int *)(unaff_EDI + 0x20) = param_2 + 0x108;
  iVar3 = FEng__HashName();
  local_8 = 0;
LAB_004f44f8:
  pcVar5 = *(char **)(unaff_EDI + 0x1c);
  iVar9 = 0;
  if (pcVar5 != (char *)0x0) {
    cVar1 = *pcVar5;
    while (cVar1 != '\0') {
      iVar6 = iVar9 + 1;
      iVar9 = iVar9 + 1;
      cVar1 = pcVar5[iVar6];
    }
  }
  if (local_8 < iVar9) {
    iVar9 = 0;
    pbVar12 = (byte *)(pcVar5 + local_8);
    do {
      uVar4 = 0;
      piVar10 = &DAT_006ee650;
      do {
        pbVar11 = pbVar12;
        if (*piVar10 == iVar9) {
          if ((uVar4 & 0xfffffff) != 0xff9119b) {
            pcVar5 = (&PTR_s_ENGLISH_006ee654)[uVar4 * 4];
            goto LAB_004f4540;
          }
          break;
        }
        piVar10 = piVar10 + 4;
        uVar4 = uVar4 + 1;
      } while ((int)piVar10 < 0x6ee6f0);
      pcVar5 = "UNKNOWN";
LAB_004f4540:
      do {
        bVar8 = *pbVar11;
        if (('`' < (char)bVar8) && ((char)bVar8 < '{')) {
          bVar8 = bVar8 & 0x5f;
        }
        bVar2 = *pcVar5;
        if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
          bVar2 = bVar2 & 0x5f;
        }
        pcVar5 = pcVar5 + 1;
      } while (((bVar8 != 0) && (bVar2 != 0)) && (pbVar11 = pbVar11 + 1, bVar8 == bVar2));
      if (((bVar8 == bVar2) && (0 < local_8)) && (pbVar12[-1] == 0x5f)) {
        local_8 = local_8 + 1;
        pbVar12[-1] = 0;
        goto LAB_004f44f8;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < 0xc);
    local_8 = local_8 + 1;
    goto LAB_004f44f8;
  }
  iVar6 = FUN_006387c0(*(int *)(unaff_EDI + 0x20) + 0x100);
  pbVar12 = *(byte **)(unaff_EDI + 0x1c);
  iVar9 = -1;
  *(int *)(unaff_EDI + 0xc) = iVar6;
  if (pbVar12 != (byte *)0x0) {
    bVar8 = *pbVar12;
    while (bVar8 != 0) {
      if (('`' < (char)bVar8) && ((char)bVar8 < '{')) {
        bVar8 = bVar8 - 0x20;
      }
      iVar9 = iVar9 * 0x21 + (uint)bVar8;
      pbVar11 = pbVar12 + 1;
      pbVar12 = pbVar12 + 1;
      bVar8 = *pbVar11;
    }
  }
  pbVar12 = *(byte **)(unaff_EDI + 0x20);
  *(int *)(unaff_EDI + 0x14) = iVar9;
  iVar9 = -1;
  if (pbVar12 != (byte *)0x0) {
    bVar8 = *pbVar12;
    while (bVar8 != 0) {
      if (('`' < (char)bVar8) && ((char)bVar8 < '{')) {
        bVar8 = bVar8 - 0x20;
      }
      iVar9 = iVar9 * 0x21 + (uint)bVar8;
      pbVar11 = pbVar12 + 1;
      pbVar12 = pbVar12 + 1;
      bVar8 = *pbVar11;
    }
  }
  *(int *)(unaff_EDI + 0x18) = iVar9;
  *(float *)(unaff_EDI + 0x24) =
       (float)((uint)*(byte *)(iVar6 + 0x13) + (uint)*(byte *)(iVar6 + 0x12));
  uVar7 = Texture_FindByHash(iVar9,0,0);
  *(undefined4 *)(unaff_EDI + 8) = uVar7;
  iVar9 = 0;
  piVar10 = &DAT_006f9498;
  do {
    if (iVar3 == *piVar10) {
      if (iVar9 * 0xc != -0x6f9498) {
        *(undefined4 *)(unaff_EDI + 0x28) = (&DAT_006f949c)[iVar9 * 3];
        *(undefined4 *)(unaff_EDI + 0x2c) = *(undefined4 *)(iVar9 * 0xc + 0x6f94a0);
        return;
      }
      break;
    }
    piVar10 = piVar10 + 3;
    iVar9 = iVar9 + 1;
  } while ((int)piVar10 < 0x6f94c8);
  *(undefined4 *)(unaff_EDI + 0x28) = 0;
  *(undefined4 *)(unaff_EDI + 0x2c) = 0x3f800000;
  return;
}


// ==== 0x4f46b0 FUN_004f46b0

void FUN_004f46b0(void)

{
  int in_EAX;
  
  FUN_006387e0(*(undefined4 *)(in_EAX + 0xc));
  return;
}


// ==== 0x4f46c0 FEngFont_ResolveTextures

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

void FEngFont_ResolveTextures(int param_1,char param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar2 = DAT_007460fc;
  puVar3 = (undefined4 *)NullUpdate_ret();
  do {
    if (puVar2 == puVar3) {
      return;
    }
    uVar1 = puVar2[6];
    iVar4 = puVar2[2];
    if (param_2 == '\0') {
      if (((iVar4 == 0) || (*(int *)(iVar4 + 0x68) != param_1)) ||
         ((*(int *)(param_1 + 0x70) != 0 &&
          (((iVar4 = *(int *)(*(int *)(param_1 + 0x70) + 0x74), iVar4 != 0 &&
            (iVar4 = BinarySearch_Hash(uVar1,iVar4,0), iVar4 != 0)) && (*(int *)(iVar4 + 4) != 0))))
         )) goto LAB_004f476f;
      iVar4 = Texture_FindByHash(uVar1,0,0);
    }
    else if (((iVar4 == 0) && (*(int *)(param_1 + 0x70) != 0)) &&
            ((iVar4 = *(int *)(*(int *)(param_1 + 0x70) + 0x74), iVar4 != 0 &&
             ((iVar4 = BinarySearch_Hash(uVar1,iVar4,0), iVar4 != 0 &&
              (iVar4 = *(int *)(iVar4 + 4), iVar4 != 0)))))) {
      *(undefined1 *)(iVar4 + 0x53) = 1;
    }
    else {
LAB_004f476f:
      iVar4 = puVar2[2];
    }
    if (iVar4 != puVar2[2]) {
      puVar2[2] = iVar4;
    }
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}


// ==== 0x4f4790 FUN_004f4790

void __thiscall FUN_004f4790(int param_1,float param_2,float param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int unaff_EDI;
  
  fVar1 = (float)(int)*(short *)(*(int *)(unaff_EDI + 8) + 0x44);
  fVar2 = (float)(int)*(short *)(*(int *)(unaff_EDI + 8) + 0x46);
  fVar3 = (float)*(byte *)(param_1 + 2);
  if (fVar3 < 4.0) {
    fVar3 = 4.0;
  }
  param_2 = (float)(int)*(char *)(param_1 + 9) + param_2;
  param_3 = (float)(int)*(char *)(param_1 + 10) + *(float *)(unaff_EDI + 0x28) + param_3;
  FUN_00514530(param_2,param_3,param_2 + fVar3,(float)*(byte *)(param_1 + 3) + param_3,0x3f800000,
               (float)(int)(*(ushort *)(param_1 + 4) - 1) / fVar1,
               (float)(int)(*(ushort *)(param_1 + 6) - 1) / fVar2,
               (float)(*(byte *)(param_1 + 2) + 1 + (uint)*(ushort *)(param_1 + 4)) / fVar1,
               (float)(*(byte *)(param_1 + 3) + 1 + (uint)*(ushort *)(param_1 + 6)) / fVar2,param_4)
  ;
  return;
}


// ==== 0x4f48b0 FUN_004f48b0

void __thiscall
FUN_004f48b0(int *param_1,int param_2,ushort *param_3,undefined4 *param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  float fVar4;
  bool bVar5;
  bool bVar6;
  int in_EAX;
  int iVar7;
  uint uVar8;
  int iVar9;
  ushort uVar10;
  int iVar11;
  ushort *puVar12;
  int iVar13;
  ushort *puVar14;
  uint uVar15;
  undefined4 *puVar16;
  uint uVar17;
  float10 fVar18;
  float local_3c;
  float local_38;
  float local_2c;
  int local_28;
  uint local_10;
  uint local_c;
  uint local_8;
  uint local_4;
  
  uVar1 = *(uint *)(in_EAX + 0x68);
  iVar7 = _ftol_nocw();
  uVar2 = *(uint *)(in_EAX + 0x1c);
  fVar18 = (float10)FUN_004f4f10(param_2,param_3,iVar7);
  if ((uVar1 & 4) == 0) {
    if ((uVar1 & 8) == 0) {
      local_38 = 0.0;
    }
    else {
      local_38 = (float)-fVar18;
    }
  }
  else {
    local_38 = (float)(fVar18 * (float10)-0.5);
  }
  fVar18 = (float10)FUN_004f4d00(param_2,param_3,*(undefined4 *)(in_EAX + 0x70));
  uVar8 = uVar1 & 1;
  if (uVar8 == 0) {
    if ((uVar1 & 2) == 0) {
      fVar18 = (float10)0.0;
    }
    else {
      fVar18 = -fVar18;
    }
  }
  else {
    fVar18 = fVar18 * (float10)-0.5;
  }
  local_3c = (float)fVar18;
  local_2c = (float)fVar18;
  local_10 = ((param_1[3] / 2 << 8 | *param_1 / 2) << 8 | param_1[1] / 2) << 8 | param_1[2] / 2;
  iVar3 = *(int *)(in_EAX + 0x70);
  if (*(int *)(param_2 + 8) != 0) {
    puVar16 = (undefined4 *)(param_5 + 0x20);
    for (iVar11 = 0x10; iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar16 = *param_4;
      param_4 = param_4 + 1;
      puVar16 = puVar16 + 1;
    }
    local_c = local_10;
    local_8 = local_10;
    local_4 = local_10;
    fVar18 = (float10)FUN_004f4d00(param_2,param_3,iVar3);
    uVar10 = *param_3;
    param_4 = (undefined4 *)(float)fVar18;
    bVar5 = true;
    local_28 = 0;
    if (uVar10 != 0) {
      uVar17 = uVar2 & 0x20;
      do {
        puVar14 = param_3 + 1;
        if ((uVar17 == 0) && ((uVar10 == 10 || (uVar10 == 0x5e)))) {
          if (*puVar14 == 0) break;
          fVar18 = (float10)FUN_004f4d00(param_2,puVar14,iVar3);
          param_4 = (undefined4 *)(float)fVar18;
          if (uVar8 == 0) {
            if ((uVar1 & 2) == 0) {
              local_3c = 0.0;
            }
            else {
              local_3c = -(float)param_4;
            }
          }
          else {
            local_3c = (float)param_4 * -0.5;
          }
          local_2c = local_3c;
          local_38 = (float)iVar7 + *(float *)(param_2 + 0x24) + local_38;
        }
        else if ((iVar3 == 0) || ((uVar10 != 0x20 || (local_3c - local_2c < (float)param_4)))) {
          if ((uVar17 == 0) && (uVar10 == 0x24)) {
            if (*puVar14 == 0x24) {
              puVar14 = param_3 + 2;
              local_28 = local_28 + 1;
              uVar10 = 0x24;
              bVar5 = false;
            }
            else if (bVar5) {
              return;
            }
          }
          bVar6 = true;
          if (((char)uVar2 < '\0') && (uVar10 == 0xa0)) {
            bVar6 = false;
            uVar10 = 0x20;
          }
          else {
            if (0xff7f < uVar10) {
              uVar10 = uVar10 & 0xff;
            }
            if (uVar10 == 0x99) {
              uVar10 = 0x2122;
            }
            else if (uVar10 == 0x9c) {
              uVar10 = 0x153;
            }
          }
          uVar15 = (uint)uVar10;
          iVar11 = *(int *)(param_2 + 0xc);
          iVar13 = *(int *)(iVar11 + 0x14) + iVar11;
          iVar9 = (-(uint)((*(uint *)(iVar11 + 0xc) & 0x40000) != 0) & 4) + 0xc;
          if (((int)(uint)*(ushort *)(iVar11 + 10) <= (int)(uVar15 - 0x20)) ||
             (puVar12 = (ushort *)((uVar15 - 0x20) * iVar9 + iVar13), *puVar12 != uVar15)) {
            puVar12 = (ushort *)FUN_00638780(uVar15,iVar13,(uint)*(ushort *)(iVar11 + 10),iVar9);
          }
          if (puVar12 != (ushort *)0x0) {
            if ((local_28 != 0) && (bVar6)) {
              iVar11 = FUN_006387f0(*(undefined4 *)(param_2 + 0xc),puVar12,(int)(short)puVar14[-2]);
              local_3c = (float)iVar11 + local_3c;
            }
            FUN_004f4790(local_3c,local_38,&local_10,param_5);
            local_3c = (float)(int)(short)puVar12[7] + local_3c;
            fVar4 = (float)iVar3;
            if (iVar3 < 0) {
              fVar4 = fVar4 + 4.2949673e+09;
            }
            if ((fVar4 != 0.0) && (fVar4 < local_3c - local_2c)) {
              fVar18 = (float10)FUN_004f4d00(param_2,puVar14,iVar3);
              param_4 = (undefined4 *)(float)fVar18;
              if (uVar8 == 0) {
                if ((uVar1 & 2) == 0) {
                  local_3c = 0.0;
                }
                else {
                  local_3c = -(float)param_4;
                }
              }
              else {
                local_3c = (float)param_4 * -0.5;
              }
              local_2c = local_3c;
              local_38 = (float)iVar7 + *(float *)(param_2 + 0x24) + local_38;
            }
          }
        }
        else {
          fVar18 = (float10)FUN_004f4d00(param_2,puVar14,iVar3);
          param_4 = (undefined4 *)(float)fVar18;
          if (uVar8 == 0) {
            if ((uVar1 & 2) == 0) {
              local_3c = 0.0;
            }
            else {
              local_3c = -(float)param_4;
            }
          }
          else {
            local_3c = (float)param_4 * -0.5;
          }
          local_2c = local_3c;
          local_38 = (float)iVar7 + *(float *)(param_2 + 0x24) + local_38;
        }
        uVar10 = *puVar14;
        local_28 = local_28 + 1;
        param_3 = puVar14;
      } while (uVar10 != 0);
    }
    FUN_00514b90(param_5);
  }
  return;
}


// ==== 0x4f4d00 FUN_004f4d00

float10 __thiscall FUN_004f4d00(uint param_1,int param_2,ushort *param_3,int param_4)

{
  float fVar1;
  ushort *puVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int local_10;
  float local_c;
  
  puVar2 = param_3;
  if (param_3 == (ushort *)0x0) {
    return (float10)0.0;
  }
  uVar3 = *param_3;
  param_3 = (ushort *)0x0;
  local_c = 0.0;
  local_10 = 0;
  if (uVar3 != 0) {
    do {
      if (((param_1 & 0x20) == 0) && ((uVar3 == 10 || (uVar3 == 0x5e)))) break;
      if (uVar3 != 0xd) {
        if (uVar3 == 0x20) {
          local_c = (float)param_3;
        }
        else {
          if (0xff7f < uVar3) {
            uVar3 = uVar3 & 0xff;
          }
          if (uVar3 == 0x99) {
            uVar3 = 0x2122;
          }
          else if (uVar3 == 0x9c) {
            uVar3 = 0x153;
          }
        }
        iVar5 = *(int *)(param_2 + 0xc);
        uVar9 = (uint)uVar3;
        iVar8 = *(int *)(iVar5 + 0x14) + iVar5;
        iVar4 = (-(uint)((*(uint *)(iVar5 + 0xc) & 0x40000) != 0) & 4) + 0xc;
        if (((int)(uint)*(ushort *)(iVar5 + 10) <= (int)(uVar9 - 0x20)) ||
           (iVar6 = (uVar9 - 0x20) * iVar4, iVar7 = iVar6 + iVar8,
           *(ushort *)(iVar6 + iVar8) != uVar9)) {
          iVar7 = FUN_00638780(uVar9,iVar8,(uint)*(ushort *)(iVar5 + 10),iVar4);
        }
        if (iVar7 != 0) {
          if (local_10 != 0) {
            iVar5 = FUN_006387f0(*(undefined4 *)(param_2 + 0xc),iVar7,puVar2);
            param_3 = (ushort *)((float)iVar5 + (float)param_3);
          }
          param_3 = (ushort *)((float)(int)*(short *)(iVar7 + 0xe) + (float)param_3);
          if (param_4 != 0) {
            fVar1 = (float)param_4;
            if (param_4 < 0) {
              fVar1 = fVar1 + 4.2949673e+09;
            }
            if (fVar1 < (float)param_3) {
              if (0.0 < local_c) {
                param_3 = (ushort *)local_c;
              }
              break;
            }
          }
        }
      }
      uVar3 = puVar2[1];
      local_10 = local_10 + 1;
      puVar2 = puVar2 + 1;
    } while (uVar3 != 0);
  }
  return (float10)(float)param_3;
}


// ==== 0x4f4ea0 FUN_004f4ea0

float10 FUN_004f4ea0(uint param_1)

{
  short sVar1;
  short *in_EAX;
  undefined4 unaff_EDI;
  float10 fVar2;
  float local_4;
  
  fVar2 = (float10)FUN_004f4d00(unaff_EDI,in_EAX,0);
  local_4 = (float)fVar2;
  sVar1 = *in_EAX;
  if (sVar1 != 0) {
    do {
      in_EAX = in_EAX + 1;
      if ((((param_1 & 0x20) != 0) || ((sVar1 != 10 && (sVar1 != 0x5e)))) &&
         (fVar2 = (float10)FUN_004f4d00(unaff_EDI,in_EAX,0), (float10)local_4 < fVar2)) {
        local_4 = (float)fVar2;
      }
      sVar1 = *in_EAX;
    } while (sVar1 != 0);
  }
  return (float10)local_4;
}


// ==== 0x4f4f10 FUN_004f4f10

float10 FUN_004f4f10(int param_1,ushort *param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float local_4;
  
  if (param_2 == (ushort *)0x0) {
    return (float10)0.0;
  }
  uVar1 = *param_2;
  local_4 = 0.0;
  bVar3 = true;
  if (uVar1 != 0) {
    do {
      param_2 = param_2 + 1;
      if ((uVar1 == 10) || (uVar1 == 0x5e)) {
        bVar3 = false;
        local_4 = (float)param_3 + local_4 + *(float *)(param_1 + 0x24);
      }
      else if (uVar1 != 0xd) {
        iVar2 = *(int *)(param_1 + 0xc);
        uVar4 = uVar1 & 0xff;
        iVar8 = *(int *)(iVar2 + 0x14) + iVar2;
        iVar5 = (-(uint)((*(uint *)(iVar2 + 0xc) & 0x40000) != 0) & 4) + 0xc;
        if (((int)(uint)*(ushort *)(iVar2 + 10) <= (int)(uVar4 - 0x20)) ||
           (iVar6 = (uVar4 - 0x20) * iVar5, iVar7 = iVar6 + iVar8,
           *(ushort *)(iVar6 + iVar8) != uVar4)) {
          iVar7 = FUN_00638780(uVar4,iVar8,(uint)*(ushort *)(iVar2 + 10),iVar5);
        }
        if (iVar7 != 0) {
          bVar3 = true;
        }
      }
      uVar1 = *param_2;
    } while (uVar1 != 0);
    if (!bVar3) goto LAB_004f4ff7;
  }
  local_4 = local_4 + *(float *)(param_1 + 0x24);
LAB_004f4ff7:
  return (float10)local_4;
}


// ==== 0x4f5000 FEngFont::CalculateXOffset

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

float10 FEngFont__CalculateXOffset(undefined4 param_1,byte param_2,float param_3)

{
  if ((param_2 & 1) != 0) {
    return (float10)param_3 * (float10)-0.5;
  }
  if ((param_2 & 2) != 0) {
    return -(float10)param_3;
  }
  return (float10)0.0;
}


// ==== 0x4f5030 FEngFont::CalculateYOffset

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

float10 FEngFont__CalculateYOffset(undefined4 param_1,byte param_2,float param_3)

{
  if ((param_2 & 4) != 0) {
    return (float10)param_3 * (float10)-0.5;
  }
  if ((param_2 & 8) != 0) {
    return -(float10)param_3;
  }
  return (float10)0.0;
}


// ==== 0x4f5060 FUN_004f5060

void FUN_004f5060(void)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  int *unaff_EDI;
  
  _Memory = (int *)*unaff_EDI;
  while (_Memory != unaff_EDI) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    FUN_004f46b0();
    _free(_Memory);
    _Memory = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x4f5090 FUN_004f5090

void __thiscall FUN_004f5090(int *param_1,int param_2,int param_3)

{
  for (; param_3 != 0; param_3 = param_3 + -1) {
    (**(code **)(*param_1 + 0x34))(*(undefined4 *)(param_2 + -8 + param_3 * 8));
  }
  return;
}


// ==== 0x4f50c0 FUN_004f50c0

void FUN_004f50c0(void)

{
  return;
}


// ==== 0x4f50d0 FEngRenderer::FEngRenderer

/* [canon] hud med (ghidra+capstone) docs/re/gameflow.md */

undefined4 * FEngRenderer__FEngRenderer(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068610b;
  local_c = ExceptionList;
  puVar2 = param_1 + 4;
  ExceptionList = &local_c;
  *param_1 = &PTR_FEngRenderer__ScalarDeletingDtor_006c1b80;
  *puVar2 = puVar2;
  param_1[5] = puVar2;
  local_4 = 0;
  FUN_00514480();
  puVar2 = param_1 + 8;
  for (iVar1 = 0xd00; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4f5130 FUN_004f5130

void __fastcall FUN_004f5130(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006860eb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FEngRenderer__ScalarDeletingDtor_006c1b80;
  local_4 = 0;
  SlotPool__Destroy();
  DAT_00735704 = 0;
  SlotPool__Destroy();
  DAT_00735708 = 0;
  FUN_004f7870();
  ExceptionList = local_c;
  return;
}


// ==== 0x4f51b0 FEngRenderer::ScalarDeletingDtor

/* [canon] hud med (ghidra-canon) docs/re/canon.md */

void * __thiscall FEngRenderer__ScalarDeletingDtor(void *param_1,byte param_2)

{
  FUN_004f5130();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4f51d0 GetBaseName

/* [canon] runtime high (ghidra-canon+nfsmw) docs/re/misc.md */

void GetBaseName(void)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  undefined1 *in_EAX;
  int iVar4;
  int iVar5;
  char *unaff_ESI;
  int iVar6;
  
  iVar4 = 0;
  iVar5 = 0;
  cVar2 = *unaff_ESI;
  while (iVar3 = iVar4, cVar2 != '\0') {
    pcVar1 = unaff_ESI + iVar4;
    iVar4 = iVar4 + 1;
    if ((*pcVar1 == '\\') || (*pcVar1 == '/')) {
      iVar5 = iVar4;
    }
    cVar2 = unaff_ESI[iVar4];
  }
  for (; (iVar6 = iVar4, iVar3 != 0 && (iVar6 = iVar3, unaff_ESI[iVar3] != '.')); iVar3 = iVar3 + -1
      ) {
  }
  if (iVar6 <= iVar5) {
    *in_EAX = 0;
    return;
  }
  iVar4 = iVar5;
  do {
    in_EAX[iVar4 - iVar5] = unaff_ESI[iVar4];
    iVar4 = iVar4 + 1;
  } while (iVar4 < iVar6);
  in_EAX[iVar6 - iVar5] = 0;
  return;
}


// ==== 0x4f5240 FEManager::FEManager

/* [canon] hud high (ghidra) docs/re/gameflow.md */

void FEManager__FEManager(void)

{
  undefined1 *puVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *unaff_EDI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006862b3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *unaff_EDI = &PTR_cFEng__GetPackageData_006c1b18;
  pvVar2 = _malloc(0x5254);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = cFEng__cFEng();
  }
  unaff_EDI[2] = iVar3;
  *(undefined4 **)(iVar3 + 0x10c) = unaff_EDI;
  FEObjectPool_Allocate(unaff_EDI[2]);
  FUN_004eeab0();
  puVar1 = (undefined1 *)unaff_EDI[2];
  iVar3 = *(int *)(puVar1 + 0xe4);
  *puVar1 = 1;
  for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
    *(undefined1 *)(iVar3 + 0x14) = *puVar1;
  }
  *(undefined1 *)(unaff_EDI[2] + 2) = 1;
  *(undefined1 *)(unaff_EDI + 1) = 0;
  *(undefined1 *)((int)unaff_EDI + 5) = 0;
  *(undefined1 *)((int)unaff_EDI + 6) = 1;
  pvVar2 = _malloc(0x3420);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    unaff_EDI[3] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar4 = FEngRenderer__FEngRenderer(pvVar2);
  unaff_EDI[3] = uVar4;
  ExceptionList = local_c;
  return;
}


// ==== 0x4f5310 cFEng::_cFEng

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 * __thiscall cFEng___cFEng(undefined4 *param_1,byte param_2)

{
  void *_Memory;
  
  *param_1 = &PTR_cFEng__GetPackageData_006c1b18;
  if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[3])(1);
  }
  FEManager__RemoveJoyHandlers(param_1);
  _Memory = (void *)param_1[2];
  if (_Memory != (void *)0x0) {
    FUN_004ee840(_Memory);
    _free(_Memory);
  }
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4f5360 cFEng::LoadResources

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 cFEng__LoadResources(undefined4 param_1,int param_2,int param_3)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  char *pcVar4;
  byte *pbVar5;
  int iVar6;
  char *pcVar7;
  int *piVar8;
  int iStack_104;
  byte abStack_100 [256];
  
  if (0 < param_2) {
    piVar8 = (int *)(param_3 + 0x10);
    iStack_104 = param_2;
    do {
      GetBaseName();
      if (abStack_100[0] != 0) {
        pbVar5 = abStack_100;
        do {
          bVar3 = *pbVar5;
          if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
            bVar3 = bVar3 & 0x5f;
          }
          *pbVar5 = bVar3;
          pbVar1 = pbVar5 + 1;
          pbVar5 = pbVar5 + 1;
        } while (*pbVar1 != 0);
      }
      iVar6 = piVar8[-2];
      if (iVar6 == 1) {
        iVar6 = -1;
        pbVar5 = abStack_100;
        if (abStack_100[0] != 0) {
          iVar6 = -1;
          bVar3 = abStack_100[0];
          do {
            iVar6 = iVar6 * 0x21 + (uint)bVar3;
            bVar3 = pbVar5[1];
            pbVar5 = pbVar5 + 1;
          } while (bVar3 != 0);
        }
LAB_004f5460:
        *piVar8 = iVar6;
      }
      else {
        if (iVar6 == 2) {
          iVar6 = -1;
          pbVar5 = abStack_100;
          bVar3 = abStack_100[0];
          while (bVar3 != 0) {
            iVar6 = iVar6 * 0x21 + (uint)bVar3;
            pbVar1 = pbVar5 + 1;
            pbVar5 = pbVar5 + 1;
            bVar3 = *pbVar1;
          }
          goto LAB_004f5460;
        }
        if (iVar6 != 4) {
          iVar6 = -1;
          pbVar5 = abStack_100;
          bVar3 = abStack_100[0];
          while (bVar3 != 0) {
            iVar6 = iVar6 * 0x21 + (uint)bVar3;
            pbVar1 = pbVar5 + 1;
            pbVar5 = pbVar5 + 1;
            bVar3 = *pbVar1;
          }
          goto LAB_004f5460;
        }
        pcVar4 = (char *)FUN_00565b60(0x100,0,0,0);
        iVar6 = 0x100;
        pcVar7 = pcVar4;
        do {
          cVar2 = pcVar7[(int)(abStack_100 + -(int)pcVar4)];
          iVar6 = iVar6 + -1;
          *pcVar7 = cVar2;
          if (cVar2 == '\0') break;
          pcVar7 = pcVar7 + 1;
        } while (iVar6 != 0);
        *piVar8 = (int)pcVar4;
      }
      piVar8[1] = 0;
      piVar8 = piVar8 + 6;
      iStack_104 = iStack_104 + -1;
    } while (iStack_104 != 0);
  }
  return 1;
}


// ==== 0x4f5490 cFEng::UnloadResources

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 cFEng__UnloadResources(undefined4 param_1,int param_2,int param_3)

{
  if (0 < param_2) {
    param_3 = param_3 + 0x10;
    do {
      if (*(int *)(param_3 + -8) == 4) {
        FUN_00565ce0();
      }
      param_3 = param_3 + 0x18;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return 1;
}


// ==== 0x4f54c0 cFEng::NotificationMessage

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void cFEng__NotificationMessage(int param_1)

{
  int extraout_ECX;
  int extraout_ECX_00;
  
  if (param_1 == 0x5922615) {
    NullChunk__Loader("Disabling inputs!!\n");
    *(undefined1 *)(*(int *)(extraout_ECX_00 + 8) + 1) = 0;
    return;
  }
  if (param_1 != 0x12345678) {
    if (param_1 != 0x7e4d1288) {
      FUN_004f3f20();
      return;
    }
    NullChunk__Loader("Enabling inputs!!\n");
    *(undefined1 *)(*(int *)(extraout_ECX + 8) + 1) = 1;
    return;
  }
  NullChunk__Loader("Message[%x] got to here!\n",0x12345678);
  return;
}


// ==== 0x4f5530 cFEng::NotifySoundMessage

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void cFEng__NotifySoundMessage(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_004f3eb0(param_1,param_2,param_3);
  return;
}


// ==== 0x4f5560 cFEng::GenerateRenderContext

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void cFEng__GenerateRenderContext(undefined4 param_1,undefined4 param_2)

{
  FUN_004f2e30(param_2);
  return;
}


// ==== 0x4f5580 cFEng::GetContextTransform

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 __thiscall cFEng__GetContextTransform(int param_1,ushort param_2,undefined4 *param_3)

{
  int iVar1;
  
  *param_3 = 0x3f800000;
  param_3[5] = 0x3f800000;
  param_3[10] = 0x3f800000;
  param_3[0xf] = 0x3f800000;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[4] = 0;
  param_3[6] = 0;
  param_3[7] = 0;
  param_3[8] = 0;
  param_3[9] = 0;
  param_3[0xb] = 0;
  param_3[0xc] = 0;
  param_3[0xd] = 0;
  param_3[0xe] = 0;
  if ((param_2 != 0) && (iVar1 = (uint)param_2 * 0xd0 + 0x20 + *(int *)(param_1 + 0xc), iVar1 != 0))
  {
    *param_3 = *(undefined4 *)(iVar1 + 0x10);
    param_3[1] = *(undefined4 *)(iVar1 + 0x14);
    param_3[2] = *(undefined4 *)(iVar1 + 0x18);
    param_3[3] = *(undefined4 *)(iVar1 + 0x1c);
    param_3[4] = *(undefined4 *)(iVar1 + 0x20);
    param_3[5] = *(undefined4 *)(iVar1 + 0x24);
    param_3[6] = *(undefined4 *)(iVar1 + 0x28);
    param_3[7] = *(undefined4 *)(iVar1 + 0x2c);
    param_3[8] = *(undefined4 *)(iVar1 + 0x30);
    param_3[9] = *(undefined4 *)(iVar1 + 0x34);
    param_3[10] = *(undefined4 *)(iVar1 + 0x38);
    param_3[0xb] = *(undefined4 *)(iVar1 + 0x3c);
    param_3[0xc] = *(undefined4 *)(iVar1 + 0x40);
    param_3[0xd] = *(undefined4 *)(iVar1 + 0x44);
    param_3[0xe] = *(undefined4 *)(iVar1 + 0x48);
    param_3[0xf] = *(undefined4 *)(iVar1 + 0x4c);
  }
  return 1;
}


// ==== 0x4f5640 cFEng::RenderObject

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall cFEng__RenderObject(int param_1,int param_2)

{
  if (((*(byte *)(param_2 + 0x1c) & 1) == 0) && (*(char *)(param_1 + 6) != '\0')) {
    FEObject__SetAlphaClamped();
  }
  return;
}


// ==== 0x4f5660 cFEng::GetViewTransformation

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void cFEng__GetViewTransformation(undefined4 *param_1)

{
  *param_1 = 0x3f800000;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0x3f800000;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0x3f800000;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0x3f800000;
  return;
}


// ==== 0x4f56a0 cFEng::BeginPackageRendering

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall cFEng__BeginPackageRendering(int param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  bool bVar3;
  
  bVar3 = DAT_00736104 != 0;
  *(undefined1 *)(param_1 + 6) = 1;
  if ((bVar3) && (*(int *)(param_2 + 0x10) != -0x6bd3674b)) {
    *(undefined1 *)(param_1 + 6) = 0;
  }
  if (DAT_00735784 != 0) {
    iVar1 = FEng__HashName();
    if (iVar1 != *(int *)(param_2 + 0x10)) {
      *(undefined1 *)(param_1 + 6) = 0;
    }
  }
  if ((*(char *)(param_1 + 4) != '\0') && (*(int *)(param_2 + 0x10) == 0x64e6a331)) {
    *(undefined1 *)(param_1 + 6) = 0;
  }
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar1 == 0) || (*(short *)(iVar1 + 0x1e) == 0)) {
    *(undefined1 *)(param_1 + 6) = 0;
  }
  puVar2 = (undefined1 *)(*(int *)(param_1 + 0xc) + 0xe0);
  iVar1 = 0x40;
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 0xd0;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


// ==== 0x4f5730 cFEng::EndPackageRendering

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void cFEng__EndPackageRendering(void)

{
  FUN_004f2eb0();
  return;
}


// ==== 0x4f5740 cFEng::InitPackage

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void cFEng__InitPackage(int param_1)

{
  int iVar1;
  int unaff_EDI;
  
  NullChunk__Loader("Init Package %s\n",*(undefined4 *)(unaff_EDI + 0xc));
  FUN_004ffa60(unaff_EDI);
  *(undefined1 *)(unaff_EDI + 0x14) = 1;
  if (*(char *)(unaff_EDI + 0x16) == '\0') {
    iVar1 = *(int *)(unaff_EDI + 0x40);
    *(undefined4 *)(unaff_EDI + 0x24) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(unaff_EDI + 0x28) = 0;
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
      FUN_004ffeb0(iVar1,0);
    }
  }
  return;
}


// ==== 0x4f57a0 MoviePlayer::BuildPath

/* [canon] canon med (hopper) docs/re/canon.md */

void __fastcall MoviePlayer__BuildPath(undefined4 param_1)

{
  char cVar1;
  FILE *_File;
  char *pcVar2;
  uint uVar3;
  char *unaff_EBX;
  char *pcVar4;
  char *pcVar5;
  char acStack_40 [64];
  
  bSPrintf_regdst(param_1,"%sMOVIES\\%s%s",&DAT_006b9172);
  _File = (FILE *)_fopen();
  if (_File == (FILE *)0x0) {
    if (DAT_0070108f == '\0') {
      return;
    }
    acStack_40[0] = DAT_0070108f;
    acStack_40[1] = 0x3a;
    acStack_40[2] = 0x5c;
    acStack_40[3] = 0;
    pcVar2 = unaff_EBX;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar5 = &stack0xffffffbf;
    do {
      pcVar4 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar4 != '\0');
    pcVar4 = unaff_EBX;
    for (uVar3 = (uint)((int)pcVar2 - (int)unaff_EBX) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar3 = (int)pcVar2 - (int)unaff_EBX & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar5 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    }
    _File = (FILE *)_fopen(acStack_40,&DAT_006c16ac);
    if (_File == (FILE *)0x0) {
      return;
    }
    pcVar2 = acStack_40;
    do {
      cVar1 = *pcVar2;
      pcVar2[(int)unaff_EBX - (int)acStack_40] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
  }
  _fclose(_File);
  return;
}


// ==== 0x4f5860 FEngMovieStarter::Callback

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 FEngMovieStarter__Callback(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 auStack_40 [64];
  
  if (*(int *)(param_1 + 0x18) == 7) {
    uVar2 = MovieNameToId();
    MoviePlayer__BuildPath();
    cVar1 = FUN_0063c4a0(auStack_40);
    if (cVar1 != '\0') {
      FUN_005a4a50(auStack_40,1,uVar2);
    }
    return 0;
  }
  return 1;
}


// ==== 0x4f58c0 FEngHidePCObjects::Callback

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 FEngHidePCObjects__Callback(int param_1)

{
  if ((*(byte *)(param_1 + 0x1c) & 0x40) != 0) {
    FEObject__SetInvisible(param_1);
    if ((*(uint *)(param_1 + 0x1c) & 0x10000000) != 0) {
      *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0xefffffff;
    }
    *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 0x400000;
  }
  return 1;
}


// ==== 0x4f5900 FEngMovieStopper::Callback

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 FEngMovieStopper__Callback(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 7) {
    FUN_005a4c80();
    return 0;
  }
  return 1;
}


// ==== 0x4f5920 cFEng::PackageWasLoaded

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall cFEng__PackageWasLoaded(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688820;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  cFEng__InitPackage(param_1);
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (iVar1 != 0) {
    FEPackageData__Activate();
  }
  local_4 = 0;
  FUN_004ffb00(param_2);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_004ffb00(param_2);
  ExceptionList = local_c;
  return;
}


// ==== 0x4f59a0 ObjectDirtySetter::Callback

/* [canon] hud med (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 ObjectDirtySetter__Callback(void)

{
  FUN_004f2d60();
  return 1;
}


// ==== 0x4f59c0 cFEng::PackageWillUnload

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 cFEng__PackageWillUnload(int param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00686ba0;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_004ffb00(param_1);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_004ffb00(param_1);
  FUN_004f4220();
  NullChunk__Loader("package[%s] will unload\n",*(undefined4 *)(param_1 + 0xc));
  ExceptionList = local_c;
  return 1;
}


// ==== 0x4f5a50 cFEng::GetPackageData

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 cFEng__GetPackageData(undefined4 param_1,undefined4 param_2,undefined1 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  *param_3 = 0;
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (iVar1 != 0) {
    uVar2 = Resource_DecompressIfCOMP();
    return uVar2;
  }
  return 0;
}


// ==== 0x4f5a80 cFEng::IsAnyJoyInputActive

/* [canon] hud med (ghidra-canon) docs/re/canon.md */

uint cFEng__IsAnyJoyInputActive(void)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = &DAT_006f923c;
  do {
    uVar1 = 0;
    piVar2 = piVar3;
    do {
      if (*piVar2 != 0) {
        return CONCAT31((int3)(uVar1 >> 8),1);
      }
      uVar1 = uVar1 + 1;
      piVar2 = piVar2 + 1;
    } while ((int)uVar1 < 4);
    piVar3 = piVar3 + 7;
  } while ((int)piVar3 < 0x6f9488);
  return uVar1 & 0xffffff00;
}


// ==== 0x4f5ab0 FEManager::AddJoyHandlers

/* [canon] hud med (ghidra+hopper) docs/re/gameflow.md */

void FEManager__AddJoyHandlers(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (DAT_00735788 == 0) {
    puVar3 = &DAT_006f923c;
    do {
      uVar1 = puVar3[-3];
      iVar2 = 0;
      do {
        InputEvents__AddSource(uVar1,cFEng__HandleJoy,param_1);
        iVar2 = iVar2 + 1;
      } while (iVar2 < 2);
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      NullChunk__Loader("Add Joy handler: %s\n",puVar3[-1]);
      puVar3 = puVar3 + 7;
    } while ((int)puVar3 < 0x6f9488);
    InputEvents__AddSource(0x2c,FUN_0059f5b0,0);
  }
  DAT_00735788 = 1;
  return;
}


// ==== 0x4f5b40 cFEng::HandleJoy

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void cFEng__HandleJoy(int param_1,undefined *param_2,undefined1 param_3)

{
  undefined **ppuVar1;
  undefined **extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *puVar2;
  
  ppuVar1 = &PTR_s_FEPad_Up_006f9238;
  puVar2 = &DAT_006f923c + param_1;
  do {
    if (ppuVar1[-2] == param_2) {
      NullChunk__Loader("Joy Event: %s[%d]\n",*ppuVar1,param_3);
      *puVar2 = extraout_EDX;
      ppuVar1 = extraout_ECX;
    }
    ppuVar1 = ppuVar1 + 7;
    puVar2 = puVar2 + 7;
  } while ((int)ppuVar1 < 0x6f9484);
  return;
}


// ==== 0x4f5b90 FEManager::RemoveJoyHandlers

/* [canon] hud med (hopper) docs/re/gameflow.md */

void FEManager__RemoveJoyHandlers(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (DAT_00735788 != 0) {
    puVar2 = &DAT_006f923c;
    do {
      uVar1 = puVar2[-3];
      iVar4 = 0;
      do {
        FUN_005740b0(uVar1);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 2);
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar3 = puVar2 + 7;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2 = puVar3;
    } while ((int)puVar3 < 0x6f9488);
    FUN_005740b0(0x2c);
  }
  DAT_00735788 = 0;
  return;
}


// ==== 0x4f5bf0 cFEng::GetJoyPadMask

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

uint cFEng__GetJoyPadMask(byte param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint *puVar4;
  int *piVar5;
  
  uVar1 = 0;
  iVar3 = -1;
  if (param_1 == 0) {
    iVar3 = 0;
  }
  else if (param_1 == 1) {
    iVar3 = 1;
  }
  else if (param_1 == 2) {
    iVar3 = 2;
  }
  else if (param_1 == 3) {
    iVar3 = 3;
  }
  if ((&DAT_007306c4)[iVar3] == -1) {
    puVar2 = &DAT_006f923c + param_1;
    iVar3 = 0x15;
    do {
      *puVar2 = 0;
      puVar2 = puVar2 + 7;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    return 0;
  }
  puVar4 = &DAT_006f9250;
  piVar5 = &DAT_006f9258 + param_1;
  do {
    if (piVar5[-7] != 0) {
      uVar1 = uVar1 | puVar4[-7];
    }
    if (*piVar5 != 0) {
      uVar1 = uVar1 | *puVar4;
    }
    if (piVar5[7] != 0) {
      uVar1 = uVar1 | puVar4[7];
    }
    if (piVar5[0xe] != 0) {
      uVar1 = uVar1 | puVar4[0xe];
    }
    if (piVar5[0x15] != 0) {
      uVar1 = uVar1 | puVar4[0x15];
    }
    if (piVar5[0x1c] != 0) {
      uVar1 = uVar1 | puVar4[0x1c];
    }
    if (piVar5[0x23] != 0) {
      uVar1 = uVar1 | puVar4[0x23];
    }
    puVar4 = puVar4 + 0x31;
    piVar5 = piVar5 + 0x31;
  } while ((int)puVar4 < 0x6f949c);
  return uVar1;
}


// ==== 0x4f5cd0 cFEng::OutputWarning

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void cFEng__OutputWarning(undefined4 param_1)

{
  NullChunk__Loader(&DAT_006cc568,param_1);
  return;
}


// ==== 0x4f5cf0 FEManager::PollControllers

/* [canon] hud med (ghidra) docs/re/gameflow.md */

void FEManager__PollControllers(void)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 unaff_EDI;
  
  uVar3 = _ftol_nocw();
  FUN_004ef0b0(uVar3);
  iVar4 = 0;
  do {
    bVar1 = (&DAT_007306c4)[iVar4];
    if (((&DAT_006f947c)[iVar4] != (uint)bVar1) && (bVar1 != 0xff)) {
      (&DAT_006f947c)[iVar4] = (uint)bVar1;
      cFEng__MakeLoadedPackagesDirty(unaff_EDI);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  FUN_005a4b20();
  if ((DAT_007356a8 != 0) &&
     (puVar2 = *(undefined4 **)(DAT_007356a8 + 0xa8), puVar2 != (undefined4 *)0x0)) {
    *(undefined4 *)(DAT_007356a8 + 0xa8) = 0;
    FUN_004d76a0(*puVar2,puVar2[1],puVar2[2],&DAT_006b9172);
  }
  return;
}


// ==== 0x4f5d80 FEng::AddObjectToSortList

/* [canon] hud med (ghidra-canon) docs/re/canon.md */

void __fastcall
FEng__AddObjectToSortList(int param_1,int param_2,undefined4 param_3,undefined2 param_4)

{
  int iVar1;
  float fVar2;
  int *unaff_ESI;
  
  iVar1 = *(int *)(param_2 + 0x2c);
  if (*(int *)(iVar1 + 0xc) != 0) {
    fVar2 = (*(float *)(iVar1 + 0x14) + *(float *)(iVar1 + 0x20)) * *(float *)(param_1 + 0x18) +
            (*(float *)(iVar1 + 0x10) + *(float *)(iVar1 + 0x1c)) * *(float *)(param_1 + 8) +
            (*(float *)(iVar1 + 0x18) + *(float *)(iVar1 + 0x24)) * *(float *)(param_1 + 0x28) +
            *(float *)(param_1 + 0x38);
    *(undefined2 *)(param_2 + 0x20) = param_4;
    if (fVar2 < 0.0 == (fVar2 == 0.0)) {
      unaff_ESI[*unaff_ESI * 2 + 1] = param_2;
      unaff_ESI[*unaff_ESI * 2 + 2] = (int)fVar2;
      *unaff_ESI = *unaff_ESI + 1;
      return;
    }
  }
  return;
}


// ==== 0x4f5e00 FEng::RenderPackage

/* [canon] hud med (ghidra-canon) docs/re/canon.md */

void FEng__RenderPackage(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_40 [64];
  
  (**(code **)(*param_1 + 0x3c))(local_40);
  (**(code **)(*param_1 + 0x20))(param_2);
  iVar1 = param_1[2];
  puVar3 = (undefined4 *)(iVar1 + 0x110);
  *puVar3 = 0;
  for (iVar2 = *(int *)(param_2 + 0x40); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
    if (*(int *)(iVar2 + 0x18) != 5) {
      FEng__AddObjectToSortList(param_1,0);
    }
  }
  FUN_004f16d0(puVar3);
  (**(code **)(*param_1 + 0x30))(iVar1 + 0x114,*puVar3);
  (**(code **)(*param_1 + 0x24))(param_2);
  return;
}


// ==== 0x4f5e90 cFEng::DrawForeground

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void cFEng__DrawForeground(void)

{
  int iVar1;
  int unaff_ESI;
  
  *(undefined1 *)(unaff_ESI + 5) = 1;
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) {
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      FEng__RenderPackage(unaff_ESI,iVar1);
    }
  }
  *(undefined1 *)(unaff_ESI + 5) = 0;
  return;
}


// ==== 0x4f5ed0 cFEng::SetCurrentButton

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void __fastcall cFEng__SetCurrentButton(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0x18), iVar1 != 0)) {
    iVar3 = *(int *)(iVar1 + 0x88);
    iVar4 = 0;
    if (iVar3 != 0) {
      piVar2 = *(int **)(iVar1 + 0x84);
      do {
        if (*(int *)(*piVar2 + 0x10) == param_1) {
          iVar4 = *piVar2;
        }
        piVar2 = piVar2 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      if (iVar4 != 0) {
        if (*(int *)(iVar1 + 0x80) != 0) {
          FUN_004f0700(0x55d1e635,0,iVar1,*(int *)(iVar1 + 0x80),0);
          FUN_004f0700(0x55d1e635,*(undefined4 *)(iVar1 + 0x80),iVar1,0xfffffffb,0);
        }
        FUN_004f0700(0xabc08912,0,iVar1,iVar4,0);
        FUN_004f0700(0xabc08912,iVar4,iVar1,0xfffffffb,0);
        *(int *)(iVar1 + 0x80) = iVar4;
      }
    }
  }
  return;
}


// ==== 0x4f5f80 cFEng::SetButtonState

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void cFEng__SetButtonState(undefined4 param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int unaff_EDI;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0x18), iVar1 != 0)) {
    iVar3 = *(int *)(iVar1 + 0x88);
    iVar4 = 0;
    if (iVar3 != 0) {
      piVar2 = *(int **)(iVar1 + 0x84);
      do {
        if (*(int *)(*piVar2 + 0x10) == unaff_EDI) {
          iVar4 = *piVar2;
        }
        piVar2 = piVar2 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      if (iVar4 != 0) {
        if (param_2 == '\x01') {
          *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfbffffff;
          return;
        }
        *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x4000000;
      }
    }
  }
  return;
}


// ==== 0x4f5fe0 FEngSetDirtyFlagsCallback::Callback

/* [canon] hud med (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 FEngSetDirtyFlagsCallback__Callback(int param_1)

{
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 0x400000;
  if (DAT_0073578c != 0) {
    FUN_004f2d60();
  }
  return 1;
}


// ==== 0x4f6010 cFEng::MakeLoadedPackagesDirty

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void cFEng__MakeLoadedPackagesDirty(int param_1)

{
  int iVar1;
  void **ppvVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685478;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 8) != -0xdc) {
    iVar1 = *(int *)(*(int *)(param_1 + 8) + 0xe4);
    local_4 = 0;
    ppvVar2 = &local_c;
    for (; ExceptionList = ppvVar2, iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
      FUN_004ffb00(iVar1);
      ppvVar2 = ExceptionList;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x4f6080 cFEng::GetMouseInfo

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void cFEng__GetMouseInfo(short *param_1)

{
  *param_1 = (short)DAT_0070649c + -0x140;
  param_1[1] = (short)DAT_007064a0 + -0xf0;
  param_1[3] = (ushort)DAT_007064b0;
  return;
}


// ==== 0x4f60c0 cFEng::DoesPointTouchObject

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void cFEng__DoesPointTouchObject(undefined4 param_1,undefined4 param_2)

{
  FUN_004f7660(param_1,param_2);
  return;
}


// ==== 0x4f60e0 FEManager::Init

/* [canon] hud high (hopper) docs/re/gameflow.md */

void __fastcall FEManager__Init(undefined4 param_1)

{
  void *pvVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686443;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEngMemoryPool__Init(param_1);
  DAT_00735dfc = FUN_00565b60(0x4c,0,0,0);
  DAT_00735e18 = FUN_00565b60(0x48,0,0,0);
  pvVar1 = _malloc(0x10);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    DAT_0073578c = 0;
  }
  else {
    DAT_0073578c = FEManager__FEManager();
  }
  if (DAT_0073578c != 0) {
    *(undefined4 *)(*(int *)(DAT_0073578c + 8) + 0xd0) = 2;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x4f6170 FEManager::Update

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] hud med (hopper+ghidra) docs/re/gameflow.md */

void FEManager__Update(void)

{
  undefined4 uVar1;
  
  if (((DAT_00735dbe != '\0') && (DAT_00735dbd == '\0')) &&
     (_DAT_0078eaf4 = DAT_0073ad38 + _DAT_0078eaf4, 0.13333334 < _DAT_0078eaf4)) {
    _DAT_0078eaf4 = 0.0;
  }
  uVar1 = GetGarageCarLoader();
  GarageCarLoader__Update(uVar1);
  uVar1 = GetGarageCarLoader();
  GarageCarLoader__Update(uVar1);
  if (DAT_0073578c != 0) {
    FEManager__PollControllers();
  }
  FEManager__BroadcastMessage(0xc98356ba);
  return;
}


// ==== 0x4f61f0 FEManager::ShowPackage

/* [canon] hud med (hopper+capstone) docs/re/gameflow.md */

void FEManager__ShowPackage(void)

{
  int iVar1;
  undefined4 in_EAX;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_0073578c;
  if (DAT_0073578c != 0) {
    iVar1 = *(int *)(DAT_0073578c + 8);
    iVar2 = iVar1 + 0xdc;
    if ((iVar2 == 0) || (iVar2 = FUN_004fd1e0(iVar2), iVar2 == 0)) {
      cFEng__PushPackage(iVar1,in_EAX,0x14,0xff);
      iVar3 = DAT_0073578c;
    }
    FEManager__AddJoyHandlers(iVar3);
    return;
  }
  return;
}


// ==== 0x4f6240 FEngStopInteraction

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void FEngStopInteraction(void)

{
  int in_EAX;
  int iVar1;
  
  if (DAT_0073578c != 0) {
    if (in_EAX == 0) {
      FUN_004f40c0(0);
    }
    else {
      iVar1 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) {
        FUN_004f09b0(*(int *)(iVar1 + 0x18));
        FEManager__RemoveJoyHandlers(DAT_0073578c);
        return;
      }
    }
    FEManager__RemoveJoyHandlers(DAT_0073578c);
  }
  return;
}


// ==== 0x4f62a0 FEManager::PushPackageChecked

/* [canon] hud low (capstone) docs/re/gameflow.md */

void FEManager__PushPackageChecked(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 in_EAX;
  int iVar2;
  
  if (DAT_0073578c != 0) {
    iVar1 = *(int *)(DAT_0073578c + 8);
    iVar2 = iVar1 + 0xdc;
    if ((iVar2 == 0) || (iVar2 = FUN_004fd1e0(iVar2), iVar2 == 0)) {
      cFEng__PushPackage(iVar1,in_EAX,param_1 + 0x10,param_2);
    }
  }
  return;
}


// ==== 0x4f62f0 FEngPushGarageMainPackage

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void FEngPushGarageMainPackage(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_0073578c != 0) {
    iVar1 = *(int *)(DAT_0073578c + 8);
    iVar2 = iVar1 + 0xdc;
    if ((iVar2 == 0) || (iVar2 = FUN_004fd1e0(iVar2), iVar2 == 0)) {
      cFEng__PushPackage(iVar1,"GarageMain.fng",0x10,0);
    }
  }
  return;
}


// ==== 0x4f6340 FEngSetControlMask

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void FEngSetControlMask(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FEngFindPackage();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
  }
  return;
}


// ==== 0x4f6360 FEngSwitchPackages

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void FEngSwitchPackages(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0073578c;
  if (((DAT_0073578c != 0) && (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
     (*(int *)(iVar2 + 0x18) != 0)) {
    FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
  }
  return;
}


// ==== 0x4f63a0 FEngPopPackage

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void FEngPopPackage(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0073578c;
  if (((DAT_0073578c != 0) && (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
     (*(int *)(iVar2 + 0x18) != 0)) {
    cFEng__PopPackage(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
  }
  return;
}


// ==== 0x4f63e0 FEngQueuePackagePush

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void FEngQueuePackagePush(undefined4 param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  
  iVar1 = DAT_0073578c;
  if (DAT_0073578c != 0) {
    if (in_EAX != 0) {
      iVar2 = FEPackageList__FindByName(&DAT_00746104);
      if (iVar2 != 0) {
        UIListNode_Alloc(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar2 + 0x18),param_1);
        return;
      }
    }
    UIListNode_Alloc(*(undefined4 *)(iVar1 + 8),0,param_1);
  }
  return;
}


// ==== 0x4f6430 FEngQueuePackagePop

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void FEngQueuePackagePop(void)

{
  int iVar1;
  
  if (((DAT_0073578c != 0) && (iVar1 = FEPackageList__FindByName(&DAT_00746104), iVar1 != 0)) &&
     (*(int *)(iVar1 + 0x18) != 0)) {
    FUN_004f09b0(*(int *)(iVar1 + 0x18));
  }
  return;
}


// ==== 0x4f6460 FEngSetUseIdleList

/* [canon] hud med (ghidra-canon+nfsug) docs/re/canon.md */

void FEngSetUseIdleList(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  
  if (DAT_0073578c != 0) {
    iVar1 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) {
      *(undefined1 *)(*(int *)(iVar1 + 0x18) + 0x15) = param_2;
    }
  }
  return;
}


// ==== 0x4f6490 FEngSetPermanent

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void FEngSetPermanent(undefined2 param_1)

{
  int iVar1;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x1c) = param_1;
  }
  return;
}


// ==== 0x4f64b0 FEngSetCurrentButton

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void FEngSetCurrentButton(void)

{
  if (DAT_0073578c != 0) {
    cFEng__SetCurrentButton(DAT_0073578c);
  }
  return;
}


// ==== 0x4f64d0 FEngGetCurrentButton

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 FEngGetCurrentButton(void)

{
  int iVar1;
  
  if (DAT_0073578c != 0) {
    iVar1 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x18);
    }
    if (iVar1 != 0) {
      return *(undefined4 *)(iVar1 + 0x80);
    }
  }
  return 0;
}


// ==== 0x4f6510 FEngIsButtonEnabled

/* [canon] hud med (ghidra-canon) docs/re/canon.md */

uint __fastcall FEngIsButtonEnabled(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_0073578c != 0) {
    iVar1 = FUN_004ef050(param_1);
    if (iVar1 != 0) {
      return ~(*(uint *)(iVar1 + 0x1c) >> 0x1a) & 1;
    }
  }
  return 0;
}


// ==== 0x4f6540 FEngSendMessageToObject

/* [canon] hud med (ghidra-canon) docs/re/canon.md */

void __fastcall
FEngSendMessageToObject(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
    FUN_004f0700(param_3,param_2,param_1,param_4,0);
  }
  return;
}


// ==== 0x4f6570 FEngQueueMessageToPackage

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void FEngQueueMessageToPackage(void)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 unaff_ESI;
  
  NullChunk__Loader("Send message[%x] to package [%s]\n");
  if ((((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) &&
      (iVar1 = FEPackageList__FindByName(&DAT_00746104), iVar1 != 0)) &&
     (*(int *)(iVar1 + 0x18) != 0)) {
    NullChunk__Loader("Message was queued\n");
    FUN_004f0700(unaff_ESI,0,extraout_ECX,0xffffffff,0);
  }
  return;
}


// ==== 0x4f65d0 FEngFindPackage

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

int FEngFindPackage(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar2 == 0) || (iVar2 = *(int *)(iVar2 + 0x18), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      return 0;
    }
    iVar1 = *(int *)(DAT_0073578c + 8);
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = FUN_004fd1e0(iVar1 + 0xdc);
    if (iVar2 == 0) {
      iVar2 = FUN_004fd1e0(iVar1 + 0xec);
    }
  }
  return iVar2;
}


// ==== 0x4f6630 FEngGetFirstPackage

/* [canon] hud low (ghidra-canon) docs/re/canon.md */

undefined4 FEngGetFirstPackage(void)

{
  if (*(int *)(DAT_0073578c + 8) == 0) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(DAT_0073578c + 8) + 0xe4);
}


// ==== 0x4f6650 FEngIsPackagePushed

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 FEngIsPackagePushed(void)

{
  int iVar1;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (iVar1 != 0) {
    return CONCAT31((int3)((uint)*(int *)(iVar1 + 0x18) >> 8),*(int *)(iVar1 + 0x18) != 0);
  }
  return 0;
}


// ==== 0x4f6670 FEngFindObject

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

int FEngFindObject(void)

{
  int iVar1;
  int unaff_ESI;
  undefined4 unaff_EDI;
  
  if (((unaff_ESI != 0) && (iVar1 = FEngFindPackage(), iVar1 != 0)) &&
     (iVar1 = FUN_004ffb70(), iVar1 != 0)) {
    return iVar1;
  }
  if (DAT_0073578c == 0) {
    return 0;
  }
  iVar1 = FUN_004ef050(unaff_EDI);
  return iVar1;
}


// ==== 0x4f66b0 FEngFindString

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

int FEngFindString(void)

{
  int iVar1;
  int unaff_ESI;
  undefined4 unaff_EDI;
  
  if (((((unaff_ESI != 0) && (iVar1 = FEngFindPackage(), iVar1 != 0)) &&
       (iVar1 = FUN_004ffb70(), iVar1 != 0)) ||
      ((DAT_0073578c != 0 && (iVar1 = FUN_004ef050(unaff_EDI), iVar1 != 0)))) &&
     (*(int *)(iVar1 + 0x18) == 2)) {
    return iVar1;
  }
  return 0;
}


// ==== 0x4f66f0 FEString::SetLabelHash

/* [canon] hud med (ghidra-canon+hopper) docs/re/runtime.md */

void FEString__SetLabelHash(void)

{
  undefined4 *puVar1;
  undefined4 in_EAX;
  int unaff_ESI;
  bool bVar2;
  
  if (unaff_ESI != 0) {
    *(uint *)(unaff_ESI + 0x1c) = *(uint *)(unaff_ESI + 0x1c) | 0x400000;
    puVar1 = DAT_00735710;
    bVar2 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(unaff_ESI + 0x5c) = in_EAX;
    if (bVar2) {
      (**(code **)*puVar1)();
    }
    *(uint *)(unaff_ESI + 0x1c) = *(uint *)(unaff_ESI + 0x1c) & 0xfffffffd | 0x400000;
  }
  return;
}


// ==== 0x4f6720 FEngSetLanguageHash

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall FEngSetLanguageHash(int param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  int iVar1;
  
  if (((param_1 == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) {
      return;
    }
    iVar1 = FUN_004ef050(in_EAX);
  }
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) == 2)) {
    FUN_0041f060(iVar1,param_2);
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 2;
  }
  return;
}


// ==== 0x4f6780 DoFEngPrintf

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

int __fastcall DoFEngPrintf(undefined4 param_1)

{
  int iVar1;
  int unaff_ESI;
  
  if (unaff_ESI != 0) {
    DAT_007304b8 = FUN_005669d0;
    DAT_007304bc = FUN_005669f0;
    DAT_00730508 = &DAT_0078f1d8;
    iVar1 = bVPrintf(0,param_1);
    if (iVar1 != -1) {
      *DAT_00730508 = 0;
    }
    if (*(int *)(unaff_ESI + 100) < 0x400) {
      (&DAT_0078f1d7)[*(int *)(unaff_ESI + 100)] = 0;
    }
    FUN_0041f060(unaff_ESI,&DAT_0078f1d8);
    *(uint *)(unaff_ESI + 0x1c) = *(uint *)(unaff_ESI + 0x1c) | 2;
    return iVar1;
  }
  return 0;
}


// ==== 0x4f67f0 FEngPrintf

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 FEngPrintf(void)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FEng__HashName();
  if (((in_EAX == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      return 0;
    }
    iVar2 = FUN_004ef050(uVar1);
  }
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x18) == 2)) {
    uVar1 = DoFEngPrintf();
    return uVar1;
  }
  return 0;
}


// ==== 0x4f6850 FEngPrintf

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 FEngPrintf(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_EDI;
  
  if (((in_EAX == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) {
      return 0;
    }
    iVar1 = FUN_004ef050(unaff_EDI);
  }
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) == 2)) {
    uVar2 = DoFEngPrintf();
    return uVar2;
  }
  return 0;
}


// ==== 0x4f68a0 FEObject::SetFormattedText

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

undefined4 FEObject__SetFormattedText(void)

{
  int in_EAX;
  undefined4 uVar1;
  
  if (in_EAX != 0) {
    uVar1 = DoFEngPrintf();
    return uVar1;
  }
  return 0;
}


// ==== 0x4f68c0 bSPrintf_regdst

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

void bSPrintf_regdst(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 *unaff_ESI;
  
  DAT_007304b8 = FUN_005669d0;
  DAT_007304bc = FUN_005669f0;
  DAT_00730508 = unaff_ESI;
  iVar1 = bVPrintf(0,param_2,&stack0x0000000c);
  if ((unaff_ESI != (undefined1 *)0x0) && (iVar1 != -1)) {
    *DAT_00730508 = 0;
  }
  return;
}


// ==== 0x4f6910 FEObject::SetInvisible

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void FEObject__SetInvisible(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 0x400001;
    if (*(int *)(param_1 + 0x18) == 5) {
      iVar1 = *(int *)(param_1 + 0x60);
      iVar2 = *(int *)(param_1 + 0x5c);
      if (0 < iVar2) {
        do {
          FEObject__SetInvisible(iVar1);
          iVar1 = *(int *)(iVar1 + 4);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
    }
    else if (DAT_0073578c != 0) {
      FUN_004f2d60();
      return;
    }
  }
  return;
}


// ==== 0x4f6970 FEObject::SetVisible

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void FEObject__SetVisible(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != 0) &&
     (*(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0xfffffffe | 0x400000,
     *(int *)(param_1 + 0x18) == 5)) {
    iVar1 = *(int *)(param_1 + 0x60);
    iVar2 = *(int *)(param_1 + 0x5c);
    if (0 < iVar2) {
      do {
        FEObject__SetVisible(iVar1);
        iVar1 = *(int *)(iVar1 + 4);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  return;
}


// ==== 0x4f69c0 FEngSetPackageVisibility

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void FEngSetPackageVisibility(byte param_1)

{
  int iVar1;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (iVar1 != 0) {
    *(ushort *)(iVar1 + 0x1e) = (ushort)param_1;
  }
  return;
}


// ==== 0x4f69e0 ObjectVisibilitySetter::Callback

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 __thiscall ObjectVisibilitySetter__Callback(int param_1,undefined4 param_2)

{
  if (*(char *)(param_1 + 4) != '\0') {
    FEObject__SetVisible(param_2);
    return 1;
  }
  FEObject__SetInvisible(param_2);
  return 1;
}


// ==== 0x4f6a10 FEngSetAllObjectsInPackageVisibility

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void FEngSetAllObjectsInPackageVisibility(void)

{
  int iVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686c88;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FEngFindPackage();
  if (iVar1 != 0) {
    local_4 = 0;
    FUN_004ffb00(iVar1);
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x4f6a70 FEngSetRotationZ

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void FEngSetRotationZ(void)

{
  int unaff_ESI;
  float10 fVar1;
  undefined1 local_60 [16];
  float local_50;
  float local_4c;
  undefined4 local_48;
  undefined4 local_44;
  float local_40;
  float local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  if (unaff_ESI != 0) {
    local_48 = 0;
    local_44 = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0x3f800000;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0x3f800000;
    _ftol_nocw();
    fVar1 = (float10)FUN_00564b10();
    local_3c = (float)fVar1;
    local_50 = (float)fVar1;
    _ftol_nocw();
    fVar1 = (float10)FUN_00564b10();
    local_4c = (float)fVar1;
    local_40 = (float)-fVar1;
    FUN_00566bf0();
    FUN_004ff420(unaff_ESI,local_60,0);
  }
  return;
}


// ==== 0x4f6b70 FEObject::SetScript

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void FEObject__SetScript(undefined4 param_1,char param_2)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  if ((unaff_EDI != 0) && (iVar2 = *(int *)(unaff_EDI + 0x4c), iVar2 != 0)) {
    while (iVar1 = FEng__HashName(), *(int *)(iVar2 + 0x30) != iVar1) {
      iVar2 = *(int *)(iVar2 + 4);
      if (iVar2 == 0) {
        return;
      }
    }
    if (iVar2 != 0) {
      if (iVar2 != *(int *)(unaff_EDI + 0x54)) {
        *(int *)(unaff_EDI + 0x54) = iVar2;
        FUN_004ff030(unaff_EDI);
        *(undefined4 *)(*(int *)(unaff_EDI + 0x54) + 0x10) = 0;
      }
      if (param_2 != '\0') {
        *(undefined4 *)(iVar2 + 0x10) = 0;
      }
    }
  }
  return;
}


// ==== 0x4f6bd0 FEngSetScript

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void FEngSetScript(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FEng__HashName();
  if ((((in_EAX == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
      (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
    FUN_004ef050(uVar1);
  }
  FEObject__SetScript(param_1,param_2);
  return;
}


// ==== 0x4f6c30 FUN_004f6c30

void FUN_004f6c30(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  int iVar1;
  int unaff_ESI;
  
  if ((((unaff_ESI == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
      (iVar1 = FUN_004ffb70(), iVar1 == 0)) && (DAT_0073578c != 0)) {
    FUN_004ef050(in_EAX);
  }
  FEObject__SetScript(param_1,param_2);
  return;
}


// ==== 0x4f6c80 FUN_004f6c80

uint FUN_004f6c80(void)

{
  int in_EAX;
  int iVar1;
  uint uVar2;
  undefined4 unaff_EDI;
  
  if (in_EAX == 0) {
LAB_004f6c9d:
    uVar2 = 0;
    if (DAT_0073578c == 0) goto LAB_004f6cd8;
    uVar2 = FUN_004ef050(unaff_EDI);
    if (uVar2 == 0) goto LAB_004f6cd8;
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_004f6c9d;
    uVar2 = FUN_004ffb70();
    if (uVar2 == 0) goto LAB_004f6c9d;
  }
  iVar1 = *(int *)(uVar2 + 0x54);
  if (iVar1 != 0) {
    uVar2 = bStrCmp();
    if ((uVar2 == 0) && (uVar2 = *(uint *)(iVar1 + 0x10), (int)uVar2 <= *(int *)(iVar1 + 0xc))) {
      return CONCAT31((int3)(uVar2 >> 8),1);
    }
  }
LAB_004f6cd8:
  return uVar2 & 0xffffff00;
}


// ==== 0x4f6ce0 FUN_004f6ce0

uint FUN_004f6ce0(void)

{
  int iVar1;
  uint in_EAX;
  
  if ((in_EAX != 0) && (iVar1 = *(int *)(in_EAX + 0x54), iVar1 != 0)) {
    in_EAX = bStrCmp();
    if ((in_EAX == 0) && (in_EAX = *(uint *)(iVar1 + 0x10), (int)in_EAX <= *(int *)(iVar1 + 0xc))) {
      return CONCAT31((int3)(in_EAX >> 8),1);
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== 0x4f6d10 FUN_004f6d10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f6d10(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  float10 fVar5;
  float10 fVar6;
  
  if (unaff_ESI != 0) {
    iVar3 = *(int *)(unaff_ESI + 0x2c);
    switch(*(undefined4 *)(unaff_ESI + 0x18)) {
    case 1:
    case 7:
    case 9:
      *param_1 = *(float *)(iVar3 + 0x1c) - *(float *)(iVar3 + 0x38) * _K_HALF;
      *param_2 = *(float *)(iVar3 + 0x20) - *(float *)(iVar3 + 0x3c) * _K_HALF;
      return;
    case 2:
      iVar4 = FEPackageList__FindByKeyWithAlias();
      if (iVar4 != 0) {
        fVar5 = (float10)FUN_004f4ea0(0);
        fVar1 = *(float *)(iVar3 + 0x38);
        fVar6 = (float10)FUN_004f4f10(iVar4,*(undefined4 *)(unaff_ESI + 0x60),
                                      *(undefined4 *)(unaff_ESI + 0x6c));
        fVar2 = *(float *)(iVar3 + 0x3c);
        fVar5 = (float10)FEngFont__CalculateXOffset
                                   (iVar4,*(undefined4 *)(unaff_ESI + 0x68),
                                    (float)(fVar5 * (float10)fVar1));
        *param_1 = (float)(fVar5 + (float10)*(float *)(iVar3 + 0x1c));
        fVar5 = (float10)FEngFont__CalculateYOffset
                                   (iVar4,*(undefined4 *)(unaff_ESI + 0x68),
                                    (float)(fVar6 * (float10)fVar2));
        *param_2 = (float)(fVar5 + (float10)*(float *)(iVar3 + 0x20));
        return;
      }
      break;
    default:
      *param_1 = *(float *)(iVar3 + 0x1c);
      *param_2 = *(float *)(iVar3 + 0x20);
      break;
    case 5:
      break;
    }
  }
  return;
}


// ==== 0x4f6e10 FUN_004f6e10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f6e10(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  undefined1 *puVar6;
  float10 fVar7;
  undefined1 local_800 [2048];
  
  if (param_1 != 0) {
    iVar3 = *(int *)(param_1 + 0x2c);
    switch(*(undefined4 *)(param_1 + 0x18)) {
    case 1:
    case 7:
    case 9:
      *param_2 = *(float *)(iVar3 + 0x38) * _K_HALF + *(float *)(iVar3 + 0x1c);
      *param_3 = *(float *)(iVar3 + 0x3c) * _K_HALF + *(float *)(iVar3 + 0x20);
      return;
    case 2:
      goto switchD_004f6e3f_caseD_2;
    default:
      *param_2 = *(float *)(iVar3 + 0x1c);
      *param_3 = *(float *)(iVar3 + 0x20);
      return;
    }
  }
  return;
switchD_004f6e3f_caseD_2:
  iVar5 = FEPackageList__FindByKeyWithAlias();
  if (iVar5 == 0) {
    return;
  }
  if ((*(byte *)(param_1 + 0x1c) & 2) == 0) {
    cVar4 = FUN_0059fc60(local_800,0x800);
    puVar6 = local_800;
    if (cVar4 != '\0') goto LAB_004f6eb3;
  }
  puVar6 = *(undefined1 **)(param_1 + 0x60);
LAB_004f6eb3:
  fVar7 = (float10)FUN_004f4ea0(0);
  fVar1 = (float)(fVar7 * (float10)*(float *)(iVar3 + 0x38));
  fVar7 = (float10)FUN_004f4f10(iVar5,puVar6,*(undefined4 *)(param_1 + 0x6c));
  fVar2 = (float)(fVar7 * (float10)*(float *)(iVar3 + 0x3c));
  fVar7 = (float10)FEngFont__CalculateXOffset(iVar5,*(undefined4 *)(param_1 + 0x68),fVar1);
  *param_2 = (float)(((float10)*(float *)(iVar3 + 0x1c) - fVar7) + (float10)fVar1);
  fVar7 = (float10)FEngFont__CalculateYOffset(iVar5,*(undefined4 *)(param_1 + 0x68),fVar2);
  *param_3 = (float)(((float10)*(float *)(iVar3 + 0x20) - fVar7) + (float10)fVar2);
  return;
}


// ==== 0x4f6f60 FUN_004f6f60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f6f60(float param_1,float param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int unaff_ESI;
  float local_18;
  float local_14;
  undefined4 local_10;
  float local_8;
  
  if (unaff_ESI != 0) {
    iVar1 = *(int *)(unaff_ESI + 0x2c);
    local_8 = *(float *)(iVar1 + 0x3c);
    local_10 = *(undefined4 *)(iVar1 + 0x24);
    iVar2 = *(int *)(unaff_ESI + 0x18);
    if (((iVar2 == 1) || (iVar2 == 7)) || (iVar2 == 9)) {
      local_18 = param_1 - *(float *)(iVar1 + 0x38) * _K_HALF;
      local_14 = param_2 - local_8 * _K_HALF;
    }
    else {
      local_18 = param_1;
      local_14 = param_2;
    }
    if (iVar2 < 0x100) {
      cVar3 = FEVector3__operator__();
      if (cVar3 == '\0') {
        *(uint *)(unaff_ESI + 0x1c) = *(uint *)(unaff_ESI + 0x1c) | 0x400000;
      }
      FUN_004ff1f0(unaff_ESI,2,&local_18,0);
    }
  }
  return;
}


// ==== 0x4f7000 FUN_004f7000

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f7000(float param_1,float param_2)

{
  float10 fVar1;
  char cVar2;
  int iVar3;
  undefined4 extraout_ECX;
  int unaff_ESI;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float local_18;
  float local_14;
  undefined4 local_10;
  float local_c;
  float local_8;
  
  if (unaff_ESI != 0) {
    iVar3 = *(int *)(unaff_ESI + 0x2c);
    local_18 = *(float *)(iVar3 + 0x1c);
    local_14 = *(float *)(iVar3 + 0x20);
    local_10 = *(undefined4 *)(iVar3 + 0x24);
    local_c = *(float *)(iVar3 + 0x38);
    local_8 = *(float *)(iVar3 + 0x3c);
    switch(*(undefined4 *)(unaff_ESI + 0x18)) {
    case 1:
    case 7:
    case 9:
      local_18 = local_c * _K_HALF + param_1;
      local_14 = local_8 * _K_HALF + param_2;
      break;
    case 2:
      iVar3 = FEPackageList__FindByKeyWithAlias();
      if (iVar3 != 0) {
        fVar4 = (float10)FUN_004f4ea0(0);
        fVar6 = (float10)local_c;
        fVar5 = (float10)FUN_004f4f10(iVar3,*(undefined4 *)(unaff_ESI + 0x60),
                                      *(undefined4 *)(unaff_ESI + 0x6c));
        fVar1 = (float10)local_8;
        fVar6 = (float10)FEngFont__CalculateXOffset
                                   (iVar3,*(undefined4 *)(unaff_ESI + 0x68),(float)(fVar4 * fVar6));
        local_18 = (float)((float10)param_1 - fVar6);
        fVar6 = (float10)FEngFont__CalculateYOffset(iVar3,extraout_ECX,(float)(fVar5 * fVar1));
        local_14 = (float)((float10)param_2 - fVar6);
      }
      break;
    default:
      local_18 = param_1;
      local_14 = param_2;
    }
    if (*(int *)(unaff_ESI + 0x18) < 0x100) {
      cVar2 = FEVector3__operator__();
      if (cVar2 == '\0') {
        *(uint *)(unaff_ESI + 0x1c) = *(uint *)(unaff_ESI + 0x1c) | 0x400000;
      }
      FUN_004ff1f0(unaff_ESI,2,&local_18,0);
    }
  }
  return;
}


// ==== 0x4f7140 FUN_004f7140

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f7140(float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  undefined4 extraout_ECX;
  int unaff_ESI;
  float10 fVar6;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  if (unaff_ESI != 0) {
    iVar3 = *(int *)(unaff_ESI + 0x2c);
    local_c = *(float *)(iVar3 + 0x1c);
    local_8 = *(float *)(iVar3 + 0x20);
    local_4 = *(undefined4 *)(iVar3 + 0x24);
    switch(*(undefined4 *)(unaff_ESI + 0x18)) {
    default:
      local_c = param_1;
      local_8 = param_2;
      break;
    case 2:
      iVar5 = FEPackageList__FindByKeyWithAlias();
      if (iVar5 != 0) {
        fVar6 = (float10)FUN_004f4ea0(0);
        fVar1 = (float)(fVar6 * (float10)*(float *)(iVar3 + 0x38));
        fVar6 = (float10)FUN_004f4f10(iVar5,*(undefined4 *)(unaff_ESI + 0x60),
                                      *(undefined4 *)(unaff_ESI + 0x6c));
        fVar2 = (float)(fVar6 * (float10)*(float *)(iVar3 + 0x3c));
        fVar6 = (float10)FEngFont__CalculateXOffset(iVar5,*(undefined4 *)(unaff_ESI + 0x68),fVar1);
        local_c = (float)((float10)param_1 - ((float10)fVar1 * (float10)_K_HALF + fVar6));
        fVar6 = (float10)FEngFont__CalculateYOffset(iVar5,extraout_ECX,fVar2);
        local_8 = (float)((float10)param_2 - ((float10)fVar2 * (float10)_K_HALF + fVar6));
      }
    }
    if (*(int *)(unaff_ESI + 0x18) < 0x100) {
      cVar4 = FEVector3__operator__();
      if (cVar4 == '\0') {
        *(uint *)(unaff_ESI + 0x1c) = *(uint *)(unaff_ESI + 0x1c) | 0x400000;
      }
      FUN_004ff1f0(unaff_ESI,2,&local_c,0);
    }
  }
  return;
}


// ==== 0x4f7260 FUN_004f7260

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f7260(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  float10 fVar5;
  
  if (unaff_ESI != 0) {
    iVar3 = *(int *)(unaff_ESI + 0x2c);
    switch(*(undefined4 *)(unaff_ESI + 0x18)) {
    default:
      *param_1 = *(float *)(iVar3 + 0x1c);
      *param_2 = *(float *)(iVar3 + 0x20);
      break;
    case 2:
      iVar4 = FEPackageList__FindByKeyWithAlias();
      if (iVar4 != 0) {
        fVar5 = (float10)FUN_004f4ea0(0);
        fVar1 = (float)(fVar5 * (float10)*(float *)(iVar3 + 0x38));
        fVar5 = (float10)FUN_004f4f10(iVar4,*(undefined4 *)(unaff_ESI + 0x60),
                                      *(undefined4 *)(unaff_ESI + 0x6c));
        fVar2 = (float)(fVar5 * (float10)*(float *)(iVar3 + 0x3c));
        fVar5 = (float10)FEngFont__CalculateXOffset(iVar4,*(undefined4 *)(unaff_ESI + 0x68),fVar1);
        *param_1 = (float)((float10)fVar1 * (float10)_K_HALF + fVar5 +
                          (float10)*(float *)(iVar3 + 0x1c));
        fVar5 = (float10)FEngFont__CalculateYOffset(iVar4,*(undefined4 *)(unaff_ESI + 0x68),fVar2);
        *param_2 = (float)((float10)fVar2 * (float10)_K_HALF + fVar5 +
                          (float10)*(float *)(iVar3 + 0x20));
        return;
      }
    }
  }
  return;
}


// ==== 0x4f7350 FUN_004f7350

void FUN_004f7350(float *param_1,float *param_2)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  float10 fVar3;
  
  if (unaff_ESI != 0) {
    iVar1 = *(int *)(unaff_ESI + 0x2c);
    switch(*(undefined4 *)(unaff_ESI + 0x18)) {
    case 1:
    case 7:
    case 9:
      *param_1 = *(float *)(iVar1 + 0x38);
      *param_2 = *(float *)(iVar1 + 0x3c);
      return;
    case 2:
      iVar2 = FEPackageList__FindByKeyWithAlias();
      if (iVar2 != 0) {
        fVar3 = (float10)FUN_004f4ea0(0);
        *param_1 = (float)(fVar3 * (float10)*(float *)(iVar1 + 0x38));
        fVar3 = (float10)FUN_004f4f10(iVar2,*(undefined4 *)(unaff_ESI + 0x60),
                                      *(undefined4 *)(unaff_ESI + 0x6c));
        *param_2 = (float)(fVar3 * (float10)*(float *)(iVar1 + 0x3c));
        return;
      }
      break;
    default:
      *param_1 = 0.0;
      *param_2 = 0.0;
    }
  }
  return;
}


// ==== 0x4f73f0 FUN_004f73f0

void FUN_004f73f0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  
  if (in_EAX != 0) {
    iVar1 = *(int *)(in_EAX + 0x18);
    iVar2 = *(int *)(in_EAX + 0x2c);
    if (((iVar1 == 1) || (iVar1 == 7)) || (iVar1 == 9)) {
      *(undefined4 *)(iVar2 + 0x38) = param_1;
      *(undefined4 *)(iVar2 + 0x3c) = param_2;
    }
    *(undefined4 *)(iVar2 + 0x38) = param_1;
    *(undefined4 *)(iVar2 + 0x3c) = param_2;
    *(uint *)(in_EAX + 0x1c) = *(uint *)(in_EAX + 0x1c) | 0x400000;
  }
  return;
}


// ==== 0x4f7430 FUN_004f7430

void FUN_004f7430(float param_1)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int unaff_ESI;
  
  if (unaff_ESI != 0) {
    iVar1 = *(int *)(unaff_ESI + 0x2c);
    fVar2 = *(float *)(iVar1 + 0x38);
    switch(*(undefined4 *)(unaff_ESI + 0x18)) {
    case 1:
    case 7:
    case 9:
      iVar3 = Texture_FindByHash(*(undefined4 *)(unaff_ESI + 0x24),1,0);
      param_1 = (float)(int)*(short *)(iVar3 + 0x44) * param_1;
      *(float *)(iVar1 + 0x38) = param_1;
      break;
    case 2:
      *(float *)(iVar1 + 0x38) = param_1;
    }
    if (param_1 + 1e-06 < fVar2) {
      *(uint *)(unaff_ESI + 0x1c) = *(uint *)(unaff_ESI + 0x1c) | 0x400000;
    }
    else if (fVar2 < param_1 - 1e-06) {
      *(uint *)(unaff_ESI + 0x1c) = *(uint *)(unaff_ESI + 0x1c) | 0x400000;
      return;
    }
  }
  return;
}


// ==== 0x4f74f0 FUN_004f74f0

void FUN_004f74f0(float param_1)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int unaff_ESI;
  
  if (unaff_ESI != 0) {
    iVar1 = *(int *)(unaff_ESI + 0x2c);
    fVar2 = *(float *)(iVar1 + 0x3c);
    switch(*(undefined4 *)(unaff_ESI + 0x18)) {
    case 1:
    case 7:
    case 9:
      iVar3 = Texture_FindByHash(*(undefined4 *)(unaff_ESI + 0x24),1,0);
      param_1 = (float)(int)*(short *)(iVar3 + 0x46) * param_1;
      *(float *)(iVar1 + 0x3c) = param_1;
      break;
    case 2:
      *(float *)(iVar1 + 0x3c) = param_1;
    }
    if (param_1 + 1e-06 < fVar2) {
      *(uint *)(unaff_ESI + 0x1c) = *(uint *)(unaff_ESI + 0x1c) | 0x400000;
    }
    else if (fVar2 < param_1 - 1e-06) {
      *(uint *)(unaff_ESI + 0x1c) = *(uint *)(unaff_ESI + 0x1c) | 0x400000;
      return;
    }
  }
  return;
}


// ==== 0x4f75b0 FUN_004f75b0

void __fastcall FUN_004f75b0(int param_1)

{
  char cVar1;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x18) < 0x100) {
      cVar1 = FEColor_NearlyEqual();
      if (cVar1 == '\0') {
        *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 0x400000;
      }
      FUN_004ff2f0(param_1,0,0);
    }
  }
  return;
}


// ==== 0x4f7620 FUN_004f7620

void FUN_004f7620(void)

{
  char cVar1;
  int unaff_EDI;
  
  if ((unaff_EDI != 0) && (*(int *)(unaff_EDI + 0x18) < 0x100)) {
    cVar1 = FEColor_NearlyEqual();
    if (cVar1 == '\0') {
      *(uint *)(unaff_EDI + 0x1c) = *(uint *)(unaff_EDI + 0x1c) | 0x400000;
    }
    FUN_004ff2f0(unaff_EDI,0,0);
  }
  return;
}


// ==== 0x4f7660 FUN_004f7660

undefined4 __thiscall FUN_004f7660(undefined4 param_1,float param_2,float param_3)

{
  undefined2 extraout_var;
  undefined4 uVar1;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  FUN_004f76c0(param_1,&local_10);
  uVar1 = CONCAT22(extraout_var,
                   (ushort)(param_2 < local_10) << 8 | (ushort)(NAN(param_2) || NAN(local_10)) << 10
                   | (ushort)(param_2 == local_10) << 0xe);
  if (param_2 >= local_10) {
    uVar1 = CONCAT22(extraout_var,
                     (ushort)(param_2 < local_8) << 8 | (ushort)(NAN(param_2) || NAN(local_8)) << 10
                     | (ushort)(param_2 == local_8) << 0xe);
    if (param_2 < local_8 != (param_2 == local_8)) {
      uVar1 = CONCAT22(extraout_var,
                       (ushort)(param_3 < local_c) << 8 |
                       (ushort)(NAN(param_3) || NAN(local_c)) << 10 |
                       (ushort)(param_3 == local_c) << 0xe);
      if (param_3 >= local_c) {
        uVar1 = CONCAT22(extraout_var,
                         (ushort)(param_3 < local_4) << 8 |
                         (ushort)(NAN(param_3) || NAN(local_4)) << 10 |
                         (ushort)(param_3 == local_4) << 0xe);
        if (param_3 < local_4 != (param_3 == local_4)) {
          return CONCAT31((int3)((uint)uVar1 >> 8),1);
        }
      }
    }
  }
  return uVar1;
}


// ==== 0x4f76c0 FUN_004f76c0

undefined4 FUN_004f76c0(int param_1,float *param_2)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (param_1 != 0) {
    switch(*(undefined4 *)(param_1 + 0x18)) {
    case 1:
    case 7:
    case 9:
    case 10:
    case 0xb:
      FUN_004f6d10(param_2,param_2 + 1);
      FUN_004f6e10(param_1,param_2 + 2,param_2 + 3);
      return 1;
    case 2:
      FUN_004f6d10(param_2,param_2 + 1);
      FUN_004f6e10(param_1,param_2 + 2,param_2 + 3);
      return 1;
    case 3:
    case 4:
    case 6:
      FUN_004f6d10(param_2,param_2 + 1);
      FUN_004f6e10(param_1,param_2 + 2,param_2 + 3);
      return 1;
    case 5:
      bVar2 = false;
      break;
    default:
      return 0;
    }
    for (iVar1 = *(int *)(param_1 + 0x60); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
      cVar3 = FUN_004f76c0(iVar1,&local_10);
      if (cVar3 != '\0') {
        if (bVar2) {
          if (local_10 < *param_2) {
            *param_2 = local_10;
          }
          if (param_2[2] < local_8) {
            param_2[2] = local_8;
          }
          if (local_c < param_2[1]) {
            param_2[1] = local_c;
          }
          if (param_2[3] < local_4) {
            param_2[3] = local_4;
          }
        }
        else {
          *param_2 = local_10;
          param_2[1] = local_c;
          param_2[2] = local_8;
          param_2[3] = local_4;
        }
        bVar2 = true;
      }
    }
  }
  return 1;
}


// ==== 0x4f7840 MovieNameToId

/* [canon] canon high (hopper+capstone) docs/re/canon.md */

undefined4 MovieNameToId(void)

{
  int iVar1;
  int iVar2;
  char *unaff_EDI;
  
  iVar2 = 0;
  do {
    iVar1 = __stricmp(unaff_EDI,*(char **)(iVar2 * 8 + 0x6f90d8));
    if (iVar1 == 0) {
      return *(undefined4 *)(iVar2 * 8 + 0x6f90dc);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x2a);
  return 0xffffffff;
}


// ==== 0x4f7870 FUN_004f7870

void FUN_004f7870(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EBX;
  
  iVar4 = DAT_00735704;
  piVar1 = (int *)*unaff_EBX;
  while (piVar1 != unaff_EBX) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    FUN_00514510();
    iVar2 = *(int *)(iVar4 + 0x18);
    *piVar1 = *(int *)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*unaff_EBX;
  }
  return;
}


// ==== 0x4f78b0 FUN_004f78b0

void __fastcall FUN_004f78b0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c186c;
  return;
}


// ==== 0x4f78c0 FUN_004f78c0

void * __thiscall FUN_004f78c0(void *param_1,byte param_2)

{
  FUN_004f78b0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4f78e0 FEScreen::FEScreen

/* [canon] hud high (ghidra+capstone+hopper) docs/re/gameflow.md */

undefined4 * FEScreen__FEScreen(undefined4 *param_1,int *param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686fb8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreenBase__FEScreenBase();
  *param_1 = &PTR_FEScreen__ScalarDeletingDtor_006c1874;
  param_1[4] = *param_2;
  param_1[5] = param_2[1];
  param_1[6] = param_2[2];
  param_1[7] = param_2[3];
  iVar3 = *param_2;
  local_4 = 0;
  param_1[3] = iVar3;
  *(undefined1 *)(param_1 + 8) = 0;
  if (iVar3 == 0) {
LAB_004f795e:
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xaa68bfce);
    }
  }
  else {
    iVar3 = FEngFindPackage();
    if (iVar3 == 0) goto LAB_004f795e;
    iVar3 = FUN_004ffb70();
    if (iVar3 == 0) goto LAB_004f795e;
  }
  param_1[10] = iVar3;
  if (param_1[3] == 0) {
LAB_004f799f:
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xaa68bfd4);
    }
  }
  else {
    iVar3 = FEngFindPackage();
    if (iVar3 == 0) goto LAB_004f799f;
    iVar3 = FUN_004ffb70();
    if (iVar3 == 0) goto LAB_004f799f;
  }
  param_1[0xb] = iVar3;
  if (param_1[3] == 0) {
LAB_004f79e0:
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xaa68bfc6);
    }
  }
  else {
    iVar3 = FEngFindPackage();
    if (iVar3 == 0) goto LAB_004f79e0;
    iVar3 = FUN_004ffb70();
    if (iVar3 == 0) goto LAB_004f79e0;
  }
  param_1[0xd] = iVar3;
  if (param_1[3] == 0) {
LAB_004f7a21:
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xaa68bfd7);
    }
  }
  else {
    iVar3 = FEngFindPackage();
    if (iVar3 == 0) goto LAB_004f7a21;
    iVar3 = FUN_004ffb70();
    if (iVar3 == 0) goto LAB_004f7a21;
  }
  param_1[0xc] = iVar3;
  param_1[0xf] = param_2[3];
  if (param_1[3] == 0) {
LAB_004f7a68:
    if (DAT_0073578c != 0) {
      iVar3 = FUN_004ef050(0xff4bb93f);
      if (iVar3 != 0) goto LAB_004f7a84;
    }
    cVar2 = '\0';
  }
  else {
    iVar3 = FEngFindPackage();
    if (iVar3 == 0) goto LAB_004f7a68;
    iVar3 = FUN_004ffb70();
    if (iVar3 == 0) goto LAB_004f7a68;
LAB_004f7a84:
    cVar2 = '\x01';
  }
  *(char *)(param_1 + 0xe) = cVar2;
  if (cVar2 == '\x01') {
    FUN_004f8000(param_1);
    pcVar1 = (char *)param_1[3];
    DAT_0072cdd0 = *pcVar1;
    if (DAT_0072cdd0 != '\0') {
      pcVar4 = &DAT_0072cdd0;
      do {
        cVar2 = (pcVar1 + -0x72cdcf)[(int)pcVar4];
        pcVar4 = pcVar4 + 1;
        *pcVar4 = cVar2;
      } while (cVar2 != '\0');
    }
    iVar3 = FEngFindPackage();
    if (iVar3 == 0) {
      FEManager__PushPackageChecked(0x32,0);
    }
  }
  FUN_004f7f60();
  if (DAT_0073578c == 0) {
    param_1[9] = 0;
  }
  else {
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x18);
    }
    uVar5 = 0;
    if (iVar3 != 0) {
      uVar5 = *(undefined4 *)(iVar3 + 0x80);
    }
    param_1[9] = uVar5;
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4f7b30 FEScreen::ScalarDeletingDtor

/* [canon] hud med (capstone) docs/re/gameflow.md */

void * __thiscall FEScreen__ScalarDeletingDtor(void *param_1,byte param_2)

{
  FUN_004f7b50();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4f7b50 FUN_004f7b50

void __fastcall FUN_004f7b50(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00686f98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FEScreen__ScalarDeletingDtor_006c1874;
  local_4 = 0;
  if (*(int *)(param_1[5] + 0x80) != 0) {
    *(undefined4 *)param_1[6] = *(undefined4 *)(*(int *)(param_1[5] + 0x80) + 0x10);
  }
  if ((((*(char *)(param_1 + 0xe) != '\0') &&
       (iVar2 = FEngFindPackage(), iVar1 = DAT_0073578c, iVar2 != 0)) && (DAT_0073578c != 0)) &&
     ((iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0 && (*(int *)(iVar2 + 0x18) != 0)
      ))) {
    cFEng__PopPackage(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
  }
  local_4 = 0xffffffff;
  FUN_004cd350();
  ExceptionList = local_c;
  return;
}


// ==== 0x4f7c00 FUN_004f7c00

void FUN_004f7c00(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *unaff_ESI;
  int *piVar4;
  undefined4 local_38;
  int local_34 [8];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 local_4;
  
  if (param_1 == -0x3ae6403d) {
    if (unaff_ESI[0xf] != 0) {
      FUN_004f8340(unaff_ESI[3]);
      iVar2 = unaff_ESI[3];
      piVar4 = local_34;
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar4 = 0;
        piVar4 = piVar4 + 1;
      }
      local_34[0] = unaff_ESI[0xf];
      local_4 = 0;
      local_c = 0;
      local_8 = 0;
      local_14 = 1;
      local_38 = 0x169268;
      local_10 = 0x639;
      InfoDialog__OpenModalDialog(&local_38,iVar2);
    }
  }
  else if (param_1 == -0x367ca946) {
    if (((char)unaff_ESI[0xe] != '\0') && (*(int *)(param_4 + 0x1c) != 0)) {
      cVar1 = FEngIsPackagePushed();
      if (cVar1 == '\0') {
        FEManager__PushPackageChecked(0x32,0);
      }
    }
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FEPackageList__FindByName(&DAT_00746104);
      if (iVar2 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(iVar2 + 0x18);
      }
      iVar2 = 0;
      if (iVar3 != 0) {
        iVar2 = *(int *)(iVar3 + 0x80);
      }
    }
    if (((unaff_ESI[9] != 0) && (iVar2 != 0)) &&
       (*(int *)(unaff_ESI[9] + 0x10) != *(int *)(iVar2 + 0x10))) {
      FUN_004f8340(unaff_ESI[3]);
    }
    unaff_ESI[9] = iVar2;
  }
  (**(code **)(*unaff_ESI + 8))(param_1,param_2,param_3,param_4);
  return;
}


// ==== 0x4f7d30 FUN_004f7d30

void FUN_004f7d30(void)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int unaff_ESI;
  
  if ((*(char *)(unaff_ESI + 0x20) != '\0') &&
     ((iVar4 = FEngFindPackage(), iVar4 == 0 || (*(int *)(iVar4 + 0x1c) != 0)))) {
    fVar1 = (float)(DAT_0070649c + -0x140);
    fVar2 = (float)(DAT_007064a0 + -0xf0);
    if (DAT_007064b2 != '\0') {
      if ((*(int *)(unaff_ESI + 0x28) != 0) && (*(int *)(unaff_ESI + 0x2c) != 0)) {
        cVar3 = FUN_004f7660(fVar1,fVar2);
        if (cVar3 != '\0') {
          FUN_004c96c0(0x9120409e);
          iVar4 = FEng_FindObjectByHash2();
          iVar5 = FEngFindPackage();
          if ((iVar5 != 0) && (iVar4 != 0)) {
            FEngSendMessageToObject(0xd51d9c13,iVar4);
          }
        }
        cVar3 = FUN_004f7660(fVar1,fVar2);
        if (cVar3 != '\0') {
          FUN_004c96c0(0xb5971bf1);
          iVar4 = FEng_FindObjectByHash2();
          iVar5 = FEngFindPackage();
          if ((iVar5 != 0) && (iVar4 != 0)) {
            FEngSendMessageToObject(0x793fe606,iVar4);
          }
        }
      }
      if ((*(int *)(unaff_ESI + 0x34) != 0) && (*(int *)(unaff_ESI + 0x30) != 0)) {
        cVar3 = FUN_004f7660(fVar1,fVar2);
        if (cVar3 != '\0') {
          FUN_004c96c0(0x72619778);
        }
        cVar3 = FUN_004f7660(fVar1,fVar2);
        if (cVar3 != '\0') {
          FUN_004c96c0(0x911c0a4b);
        }
      }
    }
  }
  return;
}


// ==== 0x4f7eb0 FUN_004f7eb0

undefined4 __fastcall FUN_004f7eb0(int param_1)

{
  char cVar1;
  
  if ((param_1 != 0) && (DAT_007064b2 != '\0')) {
    cVar1 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0));
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== 0x4f7f10 FUN_004f7f10

undefined4 __fastcall FUN_004f7f10(int param_1)

{
  char cVar1;
  
  if (param_1 != 0) {
    cVar1 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0));
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== 0x4f7f60 FUN_004f7f60

void FUN_004f7f60(void)

{
  int iVar1;
  int unaff_EDI;
  
  if ((((*(int *)(unaff_EDI + 0xc) != 0) && (iVar1 = FEngFindPackage(), iVar1 != 0)) &&
      (iVar1 = FUN_004ffb70(), iVar1 != 0)) ||
     ((DAT_0073578c != 0 && (iVar1 = FUN_004ef050(0xfd5daf49), iVar1 != 0)))) {
    FEObject__SetInvisible(iVar1);
  }
  if (((*(int *)(unaff_EDI + 0xc) == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) {
      return;
    }
    iVar1 = FUN_004ef050(0xcb86b1f9);
    if (iVar1 == 0) {
      return;
    }
  }
  FEObject__SetInvisible(iVar1);
  return;
}


// ==== 0x4f8000 FUN_004f8000

undefined4 FUN_004f8000(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  DAT_00735780 = 0;
  iVar4 = 0;
  do {
    uVar1 = (&DAT_00706fd8)[iVar4];
    if (param_1[3] == 0) goto LAB_004f8080;
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar3 != 0) && (iVar3 = *(int *)(iVar3 + 0x18), iVar3 != 0)) goto LAB_004f806f;
    if (DAT_0073578c != 0) {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if (iVar2 == 0) {
LAB_004f8080:
        if (DAT_0073578c != 0) {
          iVar3 = FUN_004ef050(uVar1);
          if (iVar3 != 0) goto LAB_004f8098;
        }
      }
      else {
        iVar3 = FUN_004fd1e0(iVar2 + 0xdc);
        if (iVar3 == 0) {
          iVar3 = FUN_004fd1e0(iVar2 + 0xec);
          if (iVar3 == 0) goto LAB_004f8080;
        }
LAB_004f806f:
        if (iVar3 == 0) goto LAB_004f8080;
        iVar3 = FUN_004ffb70();
        if (iVar3 == 0) goto LAB_004f8080;
LAB_004f8098:
        DAT_00735780 = DAT_00735780 | 1 << ((byte)iVar4 & 0x1f);
      }
    }
    iVar4 = iVar4 + 1;
    if (0xf < iVar4) {
      DAT_00735780 = (**(code **)(*param_1 + 4))(DAT_00735780);
      return 1;
    }
  } while( true );
}


// ==== 0x4f80e0 FUN_004f80e0

void __fastcall FUN_004f80e0(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0xc))();
  if ((&DAT_006f8a48)[iVar1 * 2] != iVar1) {
    uVar2 = 0;
    do {
      if (*(int *)((int)&DAT_006f8a48 + uVar2) == iVar1) break;
      uVar2 = uVar2 + 8;
    } while (uVar2 < 0x70);
  }
  FUN_004cd180(0);
  return;
}


// ==== 0x4f81a0 FUN_004f81a0

undefined4 * FUN_004f81a0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068683b;
  local_c = ExceptionList;
  puVar1 = param_1 + 1;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c7ad4;
  *puVar1 = puVar1;
  param_1[2] = puVar1;
  local_4 = 0;
  uVar3 = FEng__HashName();
  if (DAT_0073578c == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004ef050(uVar3);
  }
  iVar2 = DAT_0073578c;
  param_1[4] = uVar3;
  uVar3 = FEng__HashName();
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004ef050(uVar3);
  }
  param_1[5] = uVar3;
  param_1[3] = 0;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4f8240 FUN_004f8240

void FUN_004f8240(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_ESI + 4);
  while( true ) {
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = iVar1 + -4;
    }
    iVar2 = unaff_ESI;
    if (unaff_ESI == -4) {
      iVar2 = 0;
    }
    if (iVar1 == iVar2) break;
    if (*(int *)(iVar1 + 0xc) == unaff_EDI) {
      *(int *)(unaff_ESI + 0xc) = iVar1;
      if (*(int *)(*(int *)(unaff_ESI + 0x10) + 0x18) == 2) {
        FUN_0041f060(*(int *)(unaff_ESI + 0x10),*(undefined4 *)(iVar1 + 0x10));
      }
      return;
    }
    iVar1 = *(int *)(iVar1 + 4);
  }
  return;
}


// ==== 0x4f8290 FUN_004f8290

void __fastcall FUN_004f8290(int param_1)

{
  int in_EAX;
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int unaff_EDI;
  
  if (in_EAX == *(int *)(param_1 + 0x14)) {
    iVar1 = FEng__HashName();
    if (unaff_EDI == iVar1) {
      if (*(int *)(param_1 + 0xc) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(param_1 + 0xc) + 4;
      }
      iVar1 = *(int *)(iVar1 + 4);
      if (iVar1 == param_1 + 4) {
        iVar1 = *(int *)(param_1 + 8);
      }
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = iVar1 + -4;
      }
      *(int *)(param_1 + 0xc) = iVar1;
      if (*(int *)(*(int *)(param_1 + 0x10) + 0x18) == 2) {
        FUN_0041f060(*(int *)(param_1 + 0x10),*(undefined4 *)(iVar1 + 0x10));
        return;
      }
    }
    else {
      iVar1 = FEng__HashName();
      if (unaff_EDI == iVar1) {
        if (*(int *)(param_1 + 0xc) == 0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = (int *)(*(int *)(param_1 + 0xc) + 4);
        }
        puVar3 = (undefined4 *)*piVar2;
        if (puVar3 == (undefined4 *)(param_1 + 4)) {
          puVar3 = *(undefined4 **)(param_1 + 4);
        }
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          puVar3 = puVar3 + -1;
        }
        *(undefined4 **)(param_1 + 0xc) = puVar3;
        if (*(int *)(*(int *)(param_1 + 0x10) + 0x18) == 2) {
          FUN_0041f060(*(int *)(param_1 + 0x10),puVar3[4]);
        }
      }
    }
  }
  return;
}


// ==== 0x4f8340 FUN_004f8340

void FUN_004f8340(void)

{
  int in_EAX;
  uint uVar1;
  
  if ((&DAT_006f8a48)[in_EAX * 2] != in_EAX) {
    uVar1 = 0;
    do {
      if (*(int *)((int)&DAT_006f8a48 + uVar1) == in_EAX) break;
      uVar1 = uVar1 + 8;
    } while (uVar1 < 0x70);
  }
  FUN_004cd180(0);
  return;
}


// ==== 0x4f8370 FUN_004f8370

undefined4 * __thiscall
FUN_004f8370(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685aeb;
  local_c = ExceptionList;
  puVar1 = param_2 + 1;
  ExceptionList = &local_c;
  *param_2 = &PTR_FUN_006c1870;
  *puVar1 = puVar1;
  param_2[2] = puVar1;
  local_4 = 0;
  puVar1 = _malloc(0x30);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[9] = 0x3f800000;
    puVar1[10] = 0x3f800000;
    *(undefined2 *)(puVar1 + 0xb) = 0;
    *(undefined2 *)((int)puVar1 + 0x2e) = 1;
  }
  param_2[4] = puVar1;
  puVar1[9] = 0x3f000000;
  *(undefined2 *)(param_2[4] + 0x2e) = 0;
  param_2[7] = 0;
  param_2[3] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[8] = param_1;
  param_2[9] = param_4;
  uVar2 = FEng__HashName();
  if (param_1 != 0) {
    iVar3 = FEngFindPackage();
    if (iVar3 != 0) {
      iVar3 = FUN_004ffb70();
      if (iVar3 != 0) goto LAB_004f8446;
    }
  }
  if (DAT_0073578c == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_004ef050(uVar2);
  }
LAB_004f8446:
  param_2[10] = iVar3;
  FUN_004f7350(param_2 + 0xb,param_2 + 0xc);
  uVar2 = FUN_004f86c0();
  param_2[0xd] = uVar2;
  FEObject__SetInvisible(param_2[10]);
  FUN_004f7260(param_2 + 5,param_2 + 6);
  FUN_004f8680();
  param_2[0xe] = 0;
  ExceptionList = local_c;
  return param_2;
}


// ==== 0x4f84b0 FUN_004f84b0

void * __thiscall FUN_004f84b0(void *param_1,byte param_2)

{
  FUN_004f84d0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4f84d0 FUN_004f84d0

void __fastcall FUN_004f84d0(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  
  iVar4 = param_1[10];
  uVar2 = param_1[0xc];
  uVar3 = param_1[0xb];
  *param_1 = &PTR_FUN_006c1870;
  if (iVar4 != 0) {
    iVar5 = *(int *)(iVar4 + 0x18);
    iVar6 = *(int *)(iVar4 + 0x2c);
    if (((iVar5 == 1) || (iVar5 == 7)) || (iVar5 == 9)) {
      *(undefined4 *)(iVar6 + 0x38) = uVar3;
      *(undefined4 *)(iVar6 + 0x3c) = uVar2;
    }
    *(undefined4 *)(iVar6 + 0x38) = uVar3;
    *(undefined4 *)(iVar6 + 0x3c) = uVar2;
    *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
  }
  piVar1 = param_1 + 1;
  piVar7 = (int *)param_1[1];
  while (piVar7 != piVar1) {
    piVar7 = (int *)*piVar1;
    iVar4 = *piVar7;
    piVar8 = (int *)piVar7[1];
    *piVar8 = iVar4;
    *(int **)(iVar4 + 4) = piVar8;
    iVar4 = piVar7[8];
    iVar6 = piVar7[3];
    iVar5 = piVar7[7];
    if (iVar6 != 0) {
      iVar9 = *(int *)(iVar6 + 0x18);
      iVar10 = *(int *)(iVar6 + 0x2c);
      if (((iVar9 == 1) || (iVar9 == 7)) || (iVar9 == 9)) {
        *(int *)(iVar10 + 0x38) = iVar5;
        *(int *)(iVar10 + 0x3c) = iVar4;
      }
      *(int *)(iVar10 + 0x38) = iVar5;
      *(int *)(iVar10 + 0x3c) = iVar4;
      *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) | 0x400000;
    }
    _free(piVar7);
    piVar7 = (int *)*piVar1;
  }
  _free((void *)param_1[4]);
  piVar7 = (int *)*piVar1;
  while (piVar7 != piVar1) {
    iVar4 = *piVar7;
    piVar8 = (int *)piVar7[1];
    *piVar8 = iVar4;
    *(int **)(iVar4 + 4) = piVar8;
    _free(piVar7);
    piVar7 = (int *)*piVar1;
  }
  return;
}


// ==== 0x4f85b0 FUN_004f85b0

void FUN_004f85b0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *_Memory;
  int *piVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int unaff_EBX;
  
  iVar3 = *(int *)(unaff_EBX + 0x28);
  uVar10 = *(undefined4 *)(unaff_EBX + 0x30);
  uVar2 = *(undefined4 *)(unaff_EBX + 0x2c);
  if (iVar3 != 0) {
    iVar4 = *(int *)(iVar3 + 0x18);
    iVar5 = *(int *)(iVar3 + 0x2c);
    if (((iVar4 == 1) || (iVar4 == 7)) || (iVar4 == 9)) {
      *(undefined4 *)(iVar5 + 0x38) = uVar2;
      *(undefined4 *)(iVar5 + 0x3c) = uVar10;
    }
    *(undefined4 *)(iVar5 + 0x38) = uVar2;
    *(undefined4 *)(iVar5 + 0x3c) = uVar10;
    *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | 0x400000;
  }
  FUN_004f8680();
  puVar1 = (undefined4 *)(unaff_EBX + 4);
  *(undefined4 *)(unaff_EBX + 0x1c) = 0;
  *(undefined4 *)(unaff_EBX + 0xc) = 0;
  puVar6 = (undefined4 *)*puVar1;
  while (puVar6 != puVar1) {
    _Memory = (int *)*puVar1;
    iVar3 = *_Memory;
    piVar7 = (int *)_Memory[1];
    *piVar7 = iVar3;
    *(int **)(iVar3 + 4) = piVar7;
    iVar3 = _Memory[8];
    iVar5 = _Memory[3];
    iVar4 = _Memory[7];
    if (iVar5 != 0) {
      iVar8 = *(int *)(iVar5 + 0x18);
      iVar9 = *(int *)(iVar5 + 0x2c);
      if (((iVar8 == 1) || (iVar8 == 7)) || (iVar8 == 9)) {
        *(int *)(iVar9 + 0x38) = iVar4;
        *(int *)(iVar9 + 0x3c) = iVar3;
      }
      *(int *)(iVar9 + 0x38) = iVar4;
      *(int *)(iVar9 + 0x3c) = iVar3;
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 0x400000;
    }
    _free(_Memory);
    puVar6 = (undefined4 *)*puVar1;
  }
  uVar10 = FUN_004f86c0();
  *(undefined4 *)(unaff_EBX + 0x34) = uVar10;
  return;
}


// ==== 0x4f8680 FUN_004f8680

void FUN_004f8680(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FEngFindPackage();
  iVar3 = *(int *)(iVar1 + 0x40);
  iVar1 = *(int *)(iVar1 + 0x44);
  iVar2 = FEng__HashName();
  while( true ) {
    if (*(int *)(iVar3 + 0x10) == iVar2) {
      FEObject__SetInvisible(iVar3);
    }
    if (iVar3 == iVar1) break;
    iVar3 = *(int *)(iVar3 + 4);
  }
  return;
}


// ==== 0x4f86c0 FUN_004f86c0

int __fastcall FUN_004f86c0(int param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  byte *pbVar7;
  
  iVar3 = FEngFindPackage();
  if (in_EAX == 0) {
    iVar4 = *(int *)(iVar3 + 0x40);
  }
  else {
    iVar4 = *(int *)(in_EAX + 4);
  }
  pbVar2 = *(byte **)(param_1 + 0x24);
  while( true ) {
    iVar6 = -1;
    if (pbVar2 != (byte *)0x0) {
      bVar5 = *pbVar2;
      pbVar7 = pbVar2;
      while (bVar5 != 0) {
        if (('`' < (char)bVar5) && ((char)bVar5 < '{')) {
          bVar5 = bVar5 - 0x20;
        }
        iVar6 = iVar6 * 0x21 + (uint)bVar5;
        pbVar1 = pbVar7 + 1;
        pbVar7 = pbVar7 + 1;
        bVar5 = *pbVar1;
      }
    }
    if (*(int *)(iVar4 + 0x10) == iVar6) break;
    if (iVar4 == *(int *)(iVar3 + 0x44)) {
      return 0;
    }
    iVar4 = *(int *)(iVar4 + 4);
  }
  return iVar4;
}


// ==== 0x4f8730 FUN_004f8730

int FUN_004f8730(int param_1,int param_2,float param_3,undefined1 param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 0x34) == 0) {
    return 0;
  }
  piVar2 = _malloc(0x24);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x34);
    piVar2[2] = param_2;
    piVar2[3] = iVar3;
    piVar2[4] = 0;
    *(undefined1 *)(piVar2 + 6) = 0;
    *(undefined1 *)((int)piVar2 + 0x19) = 1;
  }
  *(undefined1 *)(piVar2 + 6) = param_3._0_1_;
  piVar2[4] = *(int *)(param_1 + 0x1c);
  iVar3 = GetHudObjectColor();
  piVar2[5] = iVar3;
  *(undefined1 *)((int)piVar2 + 0x19) = param_4;
  FUN_004f7350(piVar2 + 7,piVar2 + 8);
  FUN_004f7350(&param_3,&param_4);
  *(float *)(param_1 + 0x1c) = param_3 + *(float *)(param_1 + 0x1c);
  puVar1 = *(undefined4 **)(param_1 + 8);
  *puVar1 = piVar2;
  *(int **)(param_1 + 8) = piVar2;
  piVar2[1] = (int)puVar1;
  *piVar2 = param_1 + 4;
  uVar4 = FUN_004f86c0();
  *(undefined4 *)(param_1 + 0x34) = uVar4;
  return piVar2[3];
}


// ==== 0x4f87f0 FUN_004f87f0

void FUN_004f87f0(void)

{
  int *piVar1;
  bool bVar2;
  bool bVar3;
  int in_EAX;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  bVar3 = true;
  bVar2 = true;
  for (piVar1 = *(int **)(in_EAX + 4);
      (piVar1 != (int *)(in_EAX + 4) && (iVar6 = iVar6 + 1, piVar1 != (int *)0x0));
      piVar1 = (int *)*piVar1) {
  }
  if (iVar6 < 2) {
    bVar2 = false;
  }
  else {
    if (*(int *)(in_EAX + 0xc) == *(int *)(in_EAX + 8)) {
      bVar2 = false;
      bVar3 = true;
      goto LAB_004f8840;
    }
    if (*(int *)(in_EAX + 0xc) != *(int *)(in_EAX + 4)) goto LAB_004f8840;
    bVar2 = true;
  }
  bVar3 = false;
LAB_004f8840:
  uVar4 = FEng__HashName();
  iVar6 = FEngFindPackage();
  if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar6 == 0)) {
    if (DAT_0073578c == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_004ef050(uVar4);
    }
  }
  uVar4 = FEng__HashName();
  iVar5 = FEngFindPackage();
  if ((iVar5 == 0) || (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
    if (DAT_0073578c == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004ef050(uVar4);
    }
  }
  if (bVar2) {
    FEObject__SetVisible();
  }
  else {
    FEObject__SetInvisible(iVar5);
  }
  if (bVar3) {
    FEObject__SetVisible();
    return;
  }
  FEObject__SetInvisible(iVar6);
  return;
}


// ==== 0x4f8910 FUN_004f8910

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004f8910(undefined4 param_1,int param_2)

{
  float fVar1;
  float *pfVar2;
  int *piVar3;
  int unaff_ESI;
  
  piVar3 = *(int **)(param_2 + 4);
  if (piVar3 != (int *)(param_2 + 4)) {
    while (unaff_ESI != piVar3[2]) {
      piVar3 = (int *)*piVar3;
      if (piVar3 == (int *)(param_2 + 4)) {
        return;
      }
    }
    if (piVar3 != *(int **)(param_2 + 0xc)) {
      pfVar2 = *(float **)(param_2 + 0x10);
      *(int **)(param_2 + 0xc) = piVar3;
      fVar1 = (float)piVar3[4];
      pfVar2[2] = -fVar1;
      if (-fVar1 != *pfVar2) {
        *(undefined2 *)(pfVar2 + 0xb) = 2;
      }
    }
    FUN_004f87f0();
    _DAT_007460f8 = DAT_0073ad3c;
  }
  return;
}


// ==== 0x4f8960 FUN_004f8960

void __fastcall FUN_004f8960(undefined4 param_1,int param_2)

{
  float fVar1;
  float *pfVar2;
  undefined4 *puVar3;
  int unaff_ESI;
  
  for (puVar3 = *(undefined4 **)(unaff_ESI + 4); puVar3 != (undefined4 *)(unaff_ESI + 4);
      puVar3 = (undefined4 *)*puVar3) {
    if (param_2 == puVar3[2]) goto LAB_004f897d;
  }
  puVar3 = (undefined4 *)0x0;
LAB_004f897d:
  if (puVar3 != *(undefined4 **)(unaff_ESI + 0xc)) {
    pfVar2 = *(float **)(unaff_ESI + 0x10);
    *(undefined4 **)(unaff_ESI + 0xc) = puVar3;
    fVar1 = (float)puVar3[4];
    pfVar2[2] = -fVar1;
    if (-fVar1 != *pfVar2) {
      *(undefined2 *)(pfVar2 + 0xb) = 2;
    }
    puVar3 = *(undefined4 **)(unaff_ESI + 0x10);
    *puVar3 = puVar3[2];
    puVar3[1] = puVar3[3];
    *(undefined2 *)(puVar3 + 0xb) = 0;
    FUN_004f8b80(unaff_ESI,**(undefined4 **)(unaff_ESI + 0x10));
  }
  FUN_004f87f0();
  return;
}


// ==== 0x4f89d0 FUN_004f89d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f89d0(void)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int unaff_EDI;
  float local_10;
  float local_c;
  undefined4 local_8;
  undefined1 local_4 [4];
  
  FUN_004f8b80(unaff_EDI,**(undefined4 **)(unaff_EDI + 0x10));
  FUN_00593ec0(DAT_0073ad38,0,0);
  if (2.0 < *(float *)(unaff_EDI + 0x38)) {
    *(undefined4 *)(unaff_EDI + 0x38) = 0;
  }
  iVar3 = *(int *)(unaff_EDI + 0xc);
  uVar2 = GetHudObjectColor();
  local_10 = (float)(uint)*(byte *)(iVar3 + 0x17);
  local_c = (float)(int)local_10;
  local_8 = 0x437f0000;
  FUN_004f7260(&local_10,local_4);
  if ((-3.0 < local_10) && (local_10 < 3.0)) {
    if (2.0 < *(float *)(unaff_EDI + 0x38)) {
      *(undefined4 *)(unaff_EDI + 0x38) = 0;
    }
    if (*(float *)(unaff_EDI + 0x38) <= _K_ONE) {
      fVar1 = *(float *)(unaff_EDI + 0x38);
    }
    else {
      fVar1 = 2.0 - *(float *)(unaff_EDI + 0x38);
    }
    fVar1 = fVar1 * local_c * 1.1 + 127.5;
    if (K_BLUR_MIN_T < fVar1) {
      fVar1 = K_BLUR_MIN_T;
    }
    iVar3 = *(int *)(unaff_EDI + 0xc);
    fVar1 = fVar1 * 0.000117647054 + 0.97;
    if (*(char *)(iVar3 + 0x19) == '\0') {
      *(float *)(unaff_EDI + 0x38) = *(float *)(unaff_EDI + 0x38) + 0.03;
    }
    else {
      FUN_004f73f0(fVar1 * *(float *)(iVar3 + 0x1c),fVar1 * *(float *)(iVar3 + 0x20));
      *(float *)(unaff_EDI + 0x38) = *(float *)(unaff_EDI + 0x38) + 0.03;
    }
  }
  if (*(char *)(*(int *)(unaff_EDI + 0xc) + 0x19) != '\0') {
    iVar3 = _ftol_nocw();
    FUN_004f75b0(iVar3 << 0x18 | uVar2 & 0xffffff);
    FUN_004f87f0();
    return;
  }
  FUN_004f87f0();
  return;
}


// ==== 0x4f8b80 FUN_004f8b80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f8b80(int param_1,float param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14 [4];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar10 = *(int **)(param_1 + 4);
  if (piVar10 != (int *)(param_1 + 4)) {
    do {
      fVar2 = param_2 + (float)piVar10[4] + *(float *)(param_1 + 0x14);
      if ((fVar2 < -200.0) || (200.0 < fVar2)) {
        FEObject__SetInvisible(piVar10[3]);
      }
      else {
        FEObject__SetVisible(piVar10[3]);
      }
      iVar4 = piVar10[3];
      iVar9 = piVar10[8];
      iVar1 = piVar10[7];
      if (iVar4 != 0) {
        iVar5 = *(int *)(iVar4 + 0x18);
        iVar6 = *(int *)(iVar4 + 0x2c);
        if (((iVar5 == 1) || (iVar5 == 7)) || (iVar5 == 9)) {
          *(int *)(iVar6 + 0x38) = iVar1;
          *(int *)(iVar6 + 0x3c) = iVar9;
        }
        *(int *)(iVar6 + 0x38) = iVar1;
        *(int *)(iVar6 + 0x3c) = iVar9;
        *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
      }
      FUN_004f7140(fVar2,*(undefined4 *)(param_1 + 0x18));
      FUN_004f6e10(piVar10[3],local_14,&local_1c);
      if (fVar2 < -320.0) {
LAB_004f8cad:
        local_20 = 0.0;
      }
      else if (0.0 <= fVar2) {
        if (320.0 <= fVar2) goto LAB_004f8cad;
        local_20 = _K_ONE - fVar2 * 0.003125;
      }
      else {
        local_20 = fVar2 * 0.003125 + _K_ONE;
      }
      iVar9 = piVar10[3];
      fVar2 = (float)piVar10[8];
      fVar3 = (float)piVar10[7];
      if (iVar9 != 0) {
        iVar1 = *(int *)(iVar9 + 0x18);
        iVar4 = *(int *)(iVar9 + 0x2c);
        if (((iVar1 == 1) || (iVar1 == 7)) || (iVar1 == 9)) {
          *(float *)(iVar4 + 0x38) = local_20 * fVar3;
          *(float *)(iVar4 + 0x3c) = local_20 * fVar2;
        }
        *(float *)(iVar4 + 0x38) = local_20 * fVar3;
        *(float *)(iVar4 + 0x3c) = local_20 * fVar2;
        *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) | 0x400000;
      }
      FUN_004f6e10(piVar10[3],&local_18,local_14);
      FUN_004f6f60(local_18,local_1c);
      if (piVar10[3] == 0) {
        local_4 = 0;
        local_8 = 0;
        local_c = 0;
        local_10 = 0;
      }
      else {
        puVar7 = *(undefined4 **)(piVar10[3] + 0x2c);
        local_10 = *puVar7;
        local_c = puVar7[1];
        local_8 = puVar7[2];
        local_4 = puVar7[3];
      }
      uVar8 = FEColor__operator_unsigned_long();
      iVar9 = _ftol_nocw();
      FUN_004f75b0(iVar9 << 0x18 | uVar8 & 0xffffff);
      piVar10 = (int *)*piVar10;
    } while (piVar10 != (int *)(param_1 + 4));
  }
  return;
}


// ==== 0x4f8dd0 FUN_004f8dd0

void FUN_004f8dd0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  do {
    if (puVar1 == (undefined4 *)(param_1 + 8)) {
      iVar2 = *(int *)(param_1 + 0x10);
      if (iVar2 != 0) {
        pcVar5 = "Highlight";
        iVar4 = -1;
        bVar3 = 0x48;
        do {
          if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
            bVar3 = bVar3 - 0x20;
          }
          iVar4 = iVar4 * 0x21 + (uint)bVar3;
          bVar3 = pcVar5[1];
          pcVar5 = pcVar5 + 1;
        } while (bVar3 != 0);
        iVar6 = *(int *)(iVar2 + 0x4c);
        if (iVar6 != 0) {
          while (*(int *)(iVar6 + 0x30) != iVar4) {
            iVar6 = *(int *)(iVar6 + 4);
            if (iVar6 == 0) {
              return;
            }
          }
          if (iVar6 != 0) {
            if (iVar6 != *(int *)(iVar2 + 0x54)) {
              *(int *)(iVar2 + 0x54) = iVar6;
              FUN_004ff030(iVar2);
              *(undefined4 *)(*(int *)(iVar2 + 0x54) + 0x10) = 0;
            }
            *(undefined4 *)(iVar6 + 0x10) = 0;
          }
        }
      }
      return;
    }
    iVar2 = puVar1[2];
    if (iVar2 != 0) {
      pcVar5 = "Highlight";
      iVar4 = -1;
      bVar3 = 0x48;
      do {
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 - 0x20;
        }
        iVar4 = iVar4 * 0x21 + (uint)bVar3;
        bVar3 = pcVar5[1];
        pcVar5 = pcVar5 + 1;
      } while (bVar3 != 0);
      for (iVar6 = *(int *)(iVar2 + 0x4c); iVar6 != 0; iVar6 = *(int *)(iVar6 + 4)) {
        if (*(int *)(iVar6 + 0x30) == iVar4) {
          if (iVar6 != 0) {
            if (iVar6 != *(int *)(iVar2 + 0x54)) {
              *(int *)(iVar2 + 0x54) = iVar6;
              FUN_004ff030(iVar2);
              *(undefined4 *)(*(int *)(iVar2 + 0x54) + 0x10) = 0;
            }
            *(undefined4 *)(iVar6 + 0x10) = 0;
          }
          break;
        }
      }
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}


// ==== 0x4f8ec0 FUN_004f8ec0

void FUN_004f8ec0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  do {
    if (puVar1 == (undefined4 *)(param_1 + 8)) {
      iVar2 = *(int *)(param_1 + 0x10);
      if (iVar2 != 0) {
        pcVar5 = "UnHighlight";
        iVar4 = -1;
        bVar3 = 0x55;
        do {
          if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
            bVar3 = bVar3 - 0x20;
          }
          iVar4 = iVar4 * 0x21 + (uint)bVar3;
          bVar3 = pcVar5[1];
          pcVar5 = pcVar5 + 1;
        } while (bVar3 != 0);
        iVar6 = *(int *)(iVar2 + 0x4c);
        if (iVar6 != 0) {
          while (*(int *)(iVar6 + 0x30) != iVar4) {
            iVar6 = *(int *)(iVar6 + 4);
            if (iVar6 == 0) {
              return;
            }
          }
          if (iVar6 != 0) {
            if (iVar6 != *(int *)(iVar2 + 0x54)) {
              *(int *)(iVar2 + 0x54) = iVar6;
              FUN_004ff030(iVar2);
              *(undefined4 *)(*(int *)(iVar2 + 0x54) + 0x10) = 0;
            }
            *(undefined4 *)(iVar6 + 0x10) = 0;
          }
        }
      }
      return;
    }
    iVar2 = puVar1[2];
    if (iVar2 != 0) {
      pcVar5 = "UnHighlight";
      iVar4 = -1;
      bVar3 = 0x55;
      do {
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 - 0x20;
        }
        iVar4 = iVar4 * 0x21 + (uint)bVar3;
        bVar3 = pcVar5[1];
        pcVar5 = pcVar5 + 1;
      } while (bVar3 != 0);
      for (iVar6 = *(int *)(iVar2 + 0x4c); iVar6 != 0; iVar6 = *(int *)(iVar6 + 4)) {
        if (*(int *)(iVar6 + 0x30) == iVar4) {
          if (iVar6 != 0) {
            if (iVar6 != *(int *)(iVar2 + 0x54)) {
              *(int *)(iVar2 + 0x54) = iVar6;
              FUN_004ff030(iVar2);
              *(undefined4 *)(*(int *)(iVar2 + 0x54) + 0x10) = 0;
            }
            *(undefined4 *)(iVar6 + 0x10) = 0;
          }
          break;
        }
      }
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}


// ==== 0x4f8fb0 FUN_004f8fb0

void FUN_004f8fb0(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int extraout_EDX;
  int extraout_EDX_00;
  int iVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  if (puVar1 != (undefined4 *)(param_1 + 8)) {
    for (; puVar1 != (undefined4 *)(param_1 + 8); puVar1 = (undefined4 *)*puVar1) {
      iVar3 = puVar1[2];
      if ((iVar3 != 0) &&
         (*(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) & 0xfffffffe | 0x400000,
         *(int *)(iVar3 + 0x18) == 5)) {
        uVar2 = *(undefined4 *)(iVar3 + 0x60);
        iVar3 = *(int *)(iVar3 + 0x5c);
        if (0 < iVar3) {
          do {
            FEObject__SetVisible(uVar2);
            uVar2 = *(undefined4 *)(extraout_EDX + 4);
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
      }
    }
    iVar3 = *(int *)(param_1 + 0x10);
    if ((iVar3 != 0) &&
       (*(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar3 + 0x18) == 5)) {
      uVar2 = *(undefined4 *)(iVar3 + 0x60);
      iVar3 = *(int *)(iVar3 + 0x5c);
      if (0 < iVar3) {
        do {
          FEObject__SetVisible(uVar2);
          uVar2 = *(undefined4 *)(extraout_EDX_00 + 4);
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
  }
  return;
}


// ==== 0x4f9060 FUN_004f9060

void FUN_004f9060(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int in_EAX;
  int *piVar4;
  int iVar5;
  int *unaff_ESI;
  int iVar6;
  
  piVar4 = (int *)*unaff_ESI;
  if ((piVar4 != unaff_ESI) && (piVar1 = unaff_ESI + 2, (int *)unaff_ESI[2] != piVar1)) {
    if (in_EAX == 1) {
      piVar2 = *(int **)unaff_ESI[4];
      if (piVar2 == piVar1) {
        return;
      }
      iVar6 = 0;
      unaff_ESI[4] = (int)piVar2;
      for (piVar3 = (int *)unaff_ESI[5]; (piVar3 != piVar1 && (iVar6 = iVar6 + 1, piVar3 != piVar2))
          ; piVar3 = (int *)*piVar3) {
      }
      iVar5 = 0;
      do {
        iVar5 = iVar5 + 1;
        if (piVar4 == (int *)0x0) break;
        piVar4 = (int *)*piVar4;
      } while (piVar4 != unaff_ESI);
      if (iVar5 < iVar6) {
        unaff_ESI[5] = *(int *)unaff_ESI[5];
      }
      if (unaff_ESI[6] != unaff_ESI[1]) {
        FUN_004f8ec0(unaff_ESI[6]);
        iVar6 = *(int *)unaff_ESI[6];
        unaff_ESI[6] = iVar6;
        FUN_004f8dd0(iVar6);
        FUN_004f9240(unaff_ESI);
        return;
      }
    }
    else if (in_EAX == -1) {
      if (unaff_ESI[4] == *piVar1) {
        return;
      }
      iVar6 = *(int *)(unaff_ESI[4] + 4);
      unaff_ESI[4] = iVar6;
      if (iVar6 == *(int *)(unaff_ESI[5] + 4)) {
        unaff_ESI[5] = iVar6;
      }
      if ((int *)unaff_ESI[6] != piVar4) {
        FUN_004f8ec0(unaff_ESI[6]);
        iVar6 = *(int *)(unaff_ESI[6] + 4);
        unaff_ESI[6] = iVar6;
        FUN_004f8dd0(iVar6);
      }
    }
    FUN_004f9240(unaff_ESI);
  }
  return;
}


// ==== 0x4f9130 FUN_004f9130

void FUN_004f9130(char param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int in_EAX;
  int iVar6;
  int iVar7;
  int *unaff_ESI;
  
  if ((int *)*unaff_ESI == unaff_ESI) {
    return;
  }
  piVar5 = unaff_ESI + 2;
  if ((int *)unaff_ESI[2] == piVar5) {
    return;
  }
  if (in_EAX == 1) {
    piVar1 = *(int **)unaff_ESI[4];
    if (piVar1 == piVar5) {
      return;
    }
    puVar2 = (undefined4 *)((undefined4 *)unaff_ESI[4])[1];
    *puVar2 = piVar1;
    piVar1[1] = (int)puVar2;
    iVar7 = *piVar1;
    piVar3 = (int *)unaff_ESI[4];
    *piVar1 = (int)piVar3;
    *(int **)(iVar7 + 4) = piVar3;
    piVar3[1] = (int)piVar1;
    *piVar3 = iVar7;
    piVar1 = (int *)unaff_ESI[5];
    piVar3 = (int *)unaff_ESI[4];
    if (piVar1 == piVar3) {
      unaff_ESI[5] = piVar3[1];
    }
    else {
      iVar7 = 0;
      for (piVar4 = piVar1; (piVar4 != piVar5 && (iVar7 = iVar7 + 1, piVar4 != piVar3));
          piVar4 = (int *)*piVar4) {
      }
      iVar6 = 0;
      for (piVar5 = (int *)*unaff_ESI;
          (piVar5 != unaff_ESI && (iVar6 = iVar6 + 1, piVar5 != (int *)0x0));
          piVar5 = (int *)*piVar5) {
      }
      if (iVar6 < iVar7) {
        unaff_ESI[5] = *piVar1;
      }
    }
    if (unaff_ESI[6] == unaff_ESI[1]) goto LAB_004f9220;
    FUN_004f8ec0(unaff_ESI[6]);
    iVar7 = *(int *)unaff_ESI[6];
  }
  else {
    if (in_EAX != -1) goto LAB_004f9220;
    piVar1 = (int *)unaff_ESI[4];
    if (piVar1 == (int *)*piVar5) {
      return;
    }
    piVar5 = (int *)piVar1[1];
    iVar7 = *piVar1;
    *piVar5 = iVar7;
    *(int **)(iVar7 + 4) = piVar5;
    puVar2 = (undefined4 *)piVar5[1];
    piVar1 = (int *)unaff_ESI[4];
    *puVar2 = piVar1;
    piVar5[1] = (int)piVar1;
    piVar1[1] = (int)puVar2;
    *piVar1 = (int)piVar5;
    if (*(int *)(unaff_ESI[5] + 4) == unaff_ESI[4]) {
      unaff_ESI[5] = unaff_ESI[4];
    }
    if (unaff_ESI[6] == *unaff_ESI) goto LAB_004f9220;
    FUN_004f8ec0(unaff_ESI[6]);
    iVar7 = *(int *)(unaff_ESI[6] + 4);
  }
  unaff_ESI[6] = iVar7;
  FUN_004f8dd0(iVar7);
LAB_004f9220:
  if (param_1 == '\0') {
    return;
  }
  FUN_004f9240();
  return;
}


// ==== 0x4f9240 FUN_004f9240

void FUN_004f9240(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  piVar1 = (int *)*param_1;
  if ((piVar1 != param_1) && ((int *)param_1[2] != param_1 + 2)) {
    piVar2 = (int *)param_1[5];
    piVar5 = (int *)NullUpdate_ret();
    for (; piVar1 != piVar5; piVar1 = (int *)*piVar1) {
      piVar3 = (int *)piVar2[2];
      FUN_004f8fb0(piVar1);
      for (piVar4 = (int *)piVar1[2]; piVar4 != piVar1 + 2; piVar4 = (int *)*piVar4) {
        FEObject__SetFormattedText(&DAT_006cc568,piVar3 + 2);
        piVar3 = (int *)*piVar3;
        if ((piVar3 == piVar2 + 2) && ((int *)*piVar4 != piVar1 + 2)) break;
      }
      piVar2 = (int *)*piVar2;
      if (piVar2 == param_1 + 2) break;
    }
    if (piVar1 != param_1) {
      for (piVar1 = (int *)*piVar1; piVar1 != piVar5; piVar1 = (int *)*piVar1) {
        piVar2 = (int *)piVar1[2];
        if (piVar2 != piVar1 + 2) {
          for (; piVar2 != piVar1 + 2; piVar2 = (int *)*piVar2) {
            FEObject__SetInvisible(piVar2[2]);
          }
          FEObject__SetInvisible(piVar1[4]);
        }
      }
    }
  }
  return;
}


// ==== 0x4f9340 FUN_004f9340

void FUN_004f9340(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = (int *)(param_1 + 8);
  piVar2 = *(int **)(param_1 + 8);
  while (piVar2 != piVar1) {
    piVar2 = (int *)*piVar1;
    iVar3 = *piVar2;
    piVar4 = (int *)piVar2[1];
    *piVar4 = iVar3;
    *(int **)(iVar3 + 4) = piVar4;
    bTList___bTList();
    _free(piVar2);
    piVar2 = (int *)*piVar1;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// ==== 0x4f9390 FUN_004f9390

void __fastcall FUN_004f9390(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c1884;
  FUN_004f7b50();
  return;
}


// ==== 0x4f93a0 FUN_004f93a0

void * __thiscall FUN_004f93a0(void *param_1,byte param_2)

{
  FUN_004f9390();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4f93c0 FUN_004f93c0

undefined4 FUN_004f93c0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687963;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x50);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_004f9420(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4f9420 FUN_004f9420

undefined4 * FUN_004f9420(undefined4 *param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  byte local_2c;
  byte local_2b [31];
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687938;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  *param_1 = &PTR_FUN_006c1884;
  param_1[0x10] = 0;
  local_4 = 0;
  if (((param_1[3] == 0) || (iVar4 = FEngFindPackage(), iVar4 == 0)) ||
     (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
    if (DAT_0073578c == 0) {
      iVar4 = 0;
      goto LAB_004f94a3;
    }
    uVar5 = FUN_004ef050(0x12dfbc68);
    FEObject__SetInvisible(uVar5);
    iVar4 = 0;
  }
  else {
LAB_004f94a3:
    FEObject__SetInvisible(iVar4);
    iVar4 = 0;
  }
  do {
    iVar4 = iVar4 + 1;
    bSPrintf_regdst(0x20,"Crumb_0%d",iVar4);
    iVar8 = -1;
    pbVar7 = &local_2c;
    bVar3 = local_2c;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      pbVar1 = pbVar7 + 1;
      iVar8 = iVar8 * 0x21 + (uint)bVar3;
      pbVar7 = pbVar7 + 1;
      bVar3 = *pbVar1;
    }
    if (param_1[3] == 0) {
LAB_004f9593:
      if (DAT_0073578c == 0) goto LAB_004f95a9;
      uVar5 = FUN_004ef050(iVar8);
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_004f955b:
        local_4._0_1_ = 1;
        FUN_004ffb00(iVar6);
        local_4 = (uint)local_4._1_3_ << 8;
        goto LAB_004f9593;
      }
      if (DAT_0073578c != 0) {
        iVar2 = *(int *)(DAT_0073578c + 8);
        if ((iVar2 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar2 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar2 + 0xec), iVar6 == 0)))) goto LAB_004f9593;
        goto LAB_004f955b;
      }
LAB_004f95a9:
      uVar5 = 0;
    }
    FEObject__SetInvisible(uVar5);
  } while (iVar4 < 6);
  param_1[0x13] = 6;
  param_1[0x10] = 0;
  *(undefined1 *)(param_1 + 0x11) = 0;
  if (param_1[3] != 0) {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
      if (DAT_0073578c == 0) goto LAB_004f96d5;
      iVar8 = *(int *)(DAT_0073578c + 8);
      if (iVar8 != 0) {
        iVar4 = FUN_004fd1e0(iVar8 + 0xdc);
        if (iVar4 != 0) goto LAB_004f9641;
        iVar4 = FUN_004fd1e0(iVar8 + 0xec);
        if (iVar4 != 0) goto LAB_004f963d;
      }
    }
    else {
LAB_004f963d:
      if (iVar4 != 0) {
LAB_004f9641:
        local_4._0_1_ = 2;
        FUN_004ffb00(iVar4);
        local_4 = (uint)local_4._1_3_ << 8;
      }
    }
  }
  if (DAT_0073578c != 0) {
    FUN_004ef050(0x12dfbc68);
  }
LAB_004f96d5:
  uVar5 = FEColor__operator_unsigned_long();
  param_1[0x12] = uVar5;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4f9700 FUN_004f9700

void __thiscall FUN_004f9700(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 < 0x2cbd3c6c) {
    if (param_2 == 0x2cbd3c6b) {
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
         (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
        if (DAT_0073578c != 0) {
          uVar2 = FUN_004ef050(0x12dfbc68);
          FEObject__SetVisible(uVar2);
          goto LAB_004f985f;
        }
        iVar1 = 0;
      }
      FEObject__SetVisible(iVar1);
      goto LAB_004f985f;
    }
    switch(param_2) {
    case 0x1c2d8258:
      FUN_004f9a60(param_1,0);
      return;
    case 0x1c2d8259:
      FUN_004f9a60(param_1,1);
      return;
    case 0x1c2d825a:
      FUN_004f9a60(param_1,2);
      return;
    case 0x1c2d825b:
      FUN_004f9a60(param_1,3);
      return;
    case 0x1c2d825c:
      FUN_004f9a60(param_1,4);
      return;
    case 0x1c2d825d:
      FUN_004f9a60(param_1,5);
      return;
    case 0x1c2d825e:
      FUN_004f9a60(param_1,6);
      return;
    }
  }
  else if (param_2 < 0x50fe8c16) {
    if (param_2 == 0x50fe8c15) {
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
         (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
        if (DAT_0073578c == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = FUN_004ef050(0x12dfbc68);
        }
      }
      FEObject__SetVisible(iVar1);
      FUN_00495f70();
      return;
    }
    if (param_2 < 0x2cbd3c8e) {
      if (param_2 == 0x2cbd3c8d) {
        FUN_004f9b70();
        return;
      }
      if (param_2 == 0x2cbd3c6c) {
        if (((*(int *)(param_1 + 0xc) == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
           (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
          if (DAT_0073578c != 0) {
            uVar2 = FUN_004ef050(0x12dfbc68);
            FEObject__SetVisible(uVar2);
            goto LAB_004f985f;
          }
          iVar1 = 0;
        }
        FEObject__SetVisible(iVar1);
      }
      else {
        if (param_2 != 0x2cbd3c6d) {
          return;
        }
        if (((*(int *)(param_1 + 0xc) == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
           (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
          if (DAT_0073578c == 0) {
            iVar1 = 0;
          }
          else {
            iVar1 = FUN_004ef050(0x12dfbc68);
          }
        }
        FEObject__SetVisible(iVar1);
      }
LAB_004f985f:
      uVar2 = bStringHash();
      FUN_004ad7b0(uVar2);
      return;
    }
    if (param_2 == 0x2cbd3c8f) {
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
         (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
        if (DAT_0073578c == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = FUN_004ef050(0x12dfbc68);
        }
      }
      FEObject__SetVisible(iVar1);
      uVar2 = bStringHash();
      FUN_004ad7b0(uVar2);
      return;
    }
    if (param_2 == 0x50fe5db4) {
      FUN_004f9e60();
      return;
    }
  }
  else if (param_2 < 0xc98356bb) {
    if (param_2 == 0xc98356ba) {
      FUN_004f9dd0();
      return;
    }
    if (param_2 == 0xa1f0e37d) {
      FUN_004f9d10();
      return;
    }
    if (param_2 == 0xa310e4c9) {
      FEngSetPackageVisibility(0);
      return;
    }
  }
  else if (param_2 == 0xe8e61aab) {
    FUN_004f9c50();
  }
  else if (param_2 == 0xf7fbf050) {
    FEngSetPackageVisibility(1);
    return;
  }
  return;
}


// ==== 0x4f9a60 FUN_004f9a60

void FUN_004f9a60(int param_1)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  byte local_20;
  byte local_1f [31];
  
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x4c)) {
    do {
      iVar4 = iVar4 + 1;
      bSPrintf_regdst(0x20,"Crumb_0%d",iVar4);
      iVar8 = -1;
      pbVar6 = &local_20;
      bVar3 = local_20;
      while (bVar3 != 0) {
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 - 0x20;
        }
        iVar8 = iVar8 * 0x21 + (uint)bVar3;
        pbVar1 = pbVar6 + 1;
        pbVar6 = pbVar6 + 1;
        bVar3 = *pbVar1;
      }
      iVar7 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_004f9b29:
        if (iVar7 == 0) {
LAB_004f9b3a:
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_004ef050(iVar8);
        }
      }
      else {
        iVar5 = FEPackageList__FindByName(&DAT_00746104);
        iVar7 = DAT_0073578c;
        if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) {
          if (DAT_0073578c != 0) {
            iVar2 = *(int *)(DAT_0073578c + 8);
            if ((iVar2 == 0) ||
               ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
                (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_004f9b29;
            goto LAB_004f9b12;
          }
          goto LAB_004f9b3a;
        }
LAB_004f9b12:
        if ((iVar5 == 0) || (iVar5 = FUN_004ffb70(), iVar7 = DAT_0073578c, iVar5 == 0))
        goto LAB_004f9b29;
      }
      FEObject__SetInvisible(iVar5);
    } while (iVar4 < *(int *)(param_1 + 0x4c));
  }
  return;
}


// ==== 0x4f9b70 FUN_004f9b70

void FUN_004f9b70(void)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 uVar2;
  int unaff_EBX;
  
  if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x12dfbc68);
    }
  }
  FEObject__SetVisible(iVar1);
  switch(in_EAX) {
  case 0:
    FUN_00495f70();
    return;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  default:
    goto switchD_004f9bc0_default;
  }
  uVar2 = bStringHash();
  FUN_004ad7b0(uVar2);
switchD_004f9bc0_default:
  return;
}


// ==== 0x4f9c50 FUN_004f9c50

void FUN_004f9c50(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EBX;
  
  iVar2 = *(int *)(unaff_EBX + 0xc);
  uVar1 = FEng__HashName();
  if ((((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
      (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
    FUN_004ef050(uVar1);
  }
  FUN_004f75b0(0x9600ff00);
  iVar2 = *(int *)(unaff_EBX + 0xc);
  uVar1 = FEng__HashName();
  if ((((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
      (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
    FUN_004ef050(uVar1);
    FUN_004f75b0(0x9600ff00);
    return;
  }
  FUN_004f75b0(0x9600ff00);
  return;
}


// ==== 0x4f9d10 FUN_004f9d10

void FUN_004f9d10(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EBX;
  
  iVar2 = *(int *)(unaff_EBX + 0xc);
  uVar1 = FEng__HashName();
  if ((((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
      (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
    FUN_004ef050(uVar1);
  }
  FUN_004f75b0(0x6478adc7);
  iVar2 = *(int *)(unaff_EBX + 0xc);
  uVar1 = FEng__HashName();
  if ((((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
      (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
    FUN_004ef050(uVar1);
    FUN_004f75b0(0x6478adc7);
    return;
  }
  FUN_004f75b0(0x6478adc7);
  return;
}


// ==== 0x4f9dd0 FUN_004f9dd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f9dd0(void)

{
  int iVar1;
  int unaff_EDI;
  
  if ((_K_HALF < (float)(DAT_0073ad3c - *(int *)(unaff_EDI + 0x40)) * 0.00025) &&
     (*(char *)(unaff_EDI + 0x44) != '\0')) {
    *(undefined1 *)(unaff_EDI + 0x44) = 0;
    if (((*(int *)(unaff_EDI + 0xc) == 0) ||
        ((iVar1 = FEngFindPackage(), iVar1 == 0 || (iVar1 = FUN_004ffb70(), iVar1 == 0)))) &&
       (DAT_0073578c != 0)) {
      FUN_004ef050(0x12dfbc68);
      FUN_004f75b0(*(undefined4 *)(unaff_EDI + 0x48));
      return;
    }
    FUN_004f75b0(*(undefined4 *)(unaff_EDI + 0x48));
  }
  return;
}


// ==== 0x4f9e60 FUN_004f9e60

void FUN_004f9e60(void)

{
  uint uVar1;
  int iVar2;
  int unaff_EDI;
  
  if (*(char *)(unaff_EDI + 0x44) == '\0') {
    uVar1 = *(uint *)(unaff_EDI + 0x48);
    *(undefined1 *)(unaff_EDI + 0x44) = 1;
    if ((((*(int *)(unaff_EDI + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
        (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(0x12dfbc68);
    }
    FUN_004f75b0(uVar1 >> 1);
    *(undefined4 *)(unaff_EDI + 0x40) = DAT_0073ad3c;
    return;
  }
  *(undefined4 *)(unaff_EDI + 0x40) = DAT_0073ad3c;
  return;
}


// ==== 0x4f9ed0 FUN_004f9ed0

void __fastcall FUN_004f9ed0(undefined4 param_1,int param_2)

{
  int *piVar1;
  int *in_EAX;
  int iVar2;
  
  if (in_EAX[2] != 0) {
    piVar1 = in_EAX + 5;
    *piVar1 = *piVar1 + param_2;
    if (*piVar1 < 0) {
      in_EAX[5] = 0;
    }
    iVar2 = in_EAX[2] + -1;
    if (iVar2 < in_EAX[5]) {
      in_EAX[5] = iVar2;
    }
    iVar2 = in_EAX[5];
    if (in_EAX[6] < iVar2) {
      if (in_EAX[7] <= iVar2) {
        in_EAX[7] = iVar2 + 1;
        in_EAX[6] = (iVar2 + 1) - in_EAX[3];
      }
    }
    else {
      in_EAX[6] = iVar2;
      in_EAX[7] = in_EAX[3] + iVar2;
    }
    in_EAX[4] = iVar2 - in_EAX[6];
    if (*in_EAX <= iVar2 - in_EAX[6]) {
      in_EAX[4] = *in_EAX + -1;
    }
  }
  return;
}


// ==== 0x4f9f30 FUN_004f9f30

void __fastcall FUN_004f9f30(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_EAX;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (in_EAX[1] < param_1) {
    param_1 = in_EAX[1];
  }
  in_EAX[2] = param_1;
  if (param_1 < in_EAX[7]) {
    in_EAX[7] = param_1;
    in_EAX[6] = param_1 - *in_EAX;
    if (param_1 - *in_EAX < 0) {
      in_EAX[6] = 0;
    }
  }
  iVar1 = *in_EAX;
  if (param_1 < iVar1) {
    in_EAX[7] = param_1;
  }
  else {
    if (iVar1 <= in_EAX[7] - in_EAX[6]) goto LAB_004f9f7e;
    in_EAX[7] = iVar1;
  }
  in_EAX[6] = 0;
LAB_004f9f7e:
  if (param_1 + -1 < in_EAX[5]) {
    in_EAX[5] = param_1 + -1;
  }
  iVar2 = in_EAX[6];
  if (in_EAX[5] < iVar2) {
    in_EAX[5] = iVar2;
  }
  iVar3 = in_EAX[7];
  if (iVar3 < in_EAX[5]) {
    in_EAX[5] = iVar3;
  }
  in_EAX[3] = iVar3 - iVar2;
  in_EAX[4] = in_EAX[5] - iVar2;
  if (iVar1 <= in_EAX[5] - iVar2) {
    in_EAX[4] = iVar1 + -1;
  }
  return;
}


// ==== 0x4f9fc0 FUN_004f9fc0

void __fastcall FUN_004f9fc0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c185c;
  FUN_004f7b50();
  return;
}


// ==== 0x4f9fd0 FUN_004f9fd0

void * __thiscall FUN_004f9fd0(void *param_1,byte param_2)

{
  FUN_004f9fc0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4f9ff0 Screen_DiscError::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_DiscError__Create(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006881f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x40);
  local_4 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FEScreen__FEScreen(puVar1,param_1);
    *puVar1 = &PTR_FUN_006c185c;
    puVar2 = puVar1;
  }
  ExceptionList = local_c;
  return puVar2;
}


// ==== 0x4fa050 FUN_004fa050

int FUN_004fa050(void)

{
  uint in_EAX;
  
  if ((in_EAX & 1) != 0) {
    return 0;
  }
  if ((in_EAX & 2) != 0) {
    return 1;
  }
  if ((in_EAX & 4) != 0) {
    return 2;
  }
  return (-(uint)((in_EAX & 8) != 0) & 4) - 1;
}


// ==== 0x4fa080 FUN_004fa080

byte FUN_004fa080(void)

{
  int in_EAX;
  
  if (in_EAX == 0) {
    return 1;
  }
  if (in_EAX == 1) {
    return 2;
  }
  if (in_EAX == 2) {
    return 4;
  }
  return (in_EAX != 3) - 1U & 8;
}


// ==== 0x4fa0b0 FUN_004fa0b0

void __fastcall FUN_004fa0b0(undefined4 param_1,int param_2,int param_3)

{
  char cVar1;
  char *in_EAX;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (in_EAX != (char *)0x0) {
    cVar1 = *in_EAX;
    while (cVar1 != '\0') {
      iVar2 = iVar3 + 1;
      iVar3 = iVar3 + 1;
      cVar1 = in_EAX[iVar2];
    }
  }
  iVar2 = 0;
  if (0 < iVar3) {
    do {
      if (iVar2 == param_3 + -1) break;
      *(undefined1 *)(iVar2 + param_2) = 0x2a;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar3);
  }
  *(undefined1 *)(iVar2 + param_2) = 0;
  return;
}


// ==== 0x4fa0f0 FUN_004fa0f0

void FUN_004fa0f0(void)

{
  undefined1 *puVar1;
  
  if ((DAT_006f9228 != 0) && (DAT_0073578c != 0)) {
    puVar1 = (undefined1 *)(DAT_0073578c + 4);
    *puVar1 = 1;
    FUN_004f0390();
    *puVar1 = 0;
    FEng__RenderPackages(DAT_0070649c,DAT_007064a0);
  }
  DAT_00735784 = 0;
  return;
}


// ==== 0x4fa140 FUN_004fa140

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004fa140(int *param_1,int param_2,int param_3,undefined4 param_4,uint param_5)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  uint uVar7;
  uint uVar8;
  float local_38;
  uint local_34;
  float *local_30;
  uint local_2c;
  
  local_38 = 1e+30;
  local_2c = 0;
  FUN_004fa310(param_1);
  local_30 = (float *)&DAT_00705a70;
  local_34 = 0;
  do {
    if ((local_34 == 0) || ((*(uint *)((int)&DAT_006f8a30 + local_34) & param_5) != 0)) {
      fVar1 = *local_30;
      uVar8 = 0;
      fVar2 = local_30[1];
      if (param_1[1] != 0) {
        do {
          iVar3 = *(int *)(*param_1 + uVar8 * 4);
          fVar6 = local_38;
          uVar7 = local_2c;
          if (((*(uint *)(iVar3 + 0x1c) & 0x4000000) == 0) && (param_2 != iVar3)) {
            FUN_004fa310(param_1);
            fVar4 = 0.0 - (fVar1 + 0.0);
            fVar5 = 0.0 - (fVar2 + 0.0);
            fVar6 = SQRT(fVar4 * fVar4 + fVar5 * fVar5);
            if (0.0001 <= fVar6) {
              fVar4 = fVar4 * (_K_ONE / fVar6) * *(float *)(&DAT_00705a30 + param_3 * 8) +
                      fVar5 * (_K_ONE / fVar6) * *(float *)(&DAT_00705a34 + param_3 * 8);
              if (0.0 <= fVar4) {
                fVar4 = fVar4 * fVar4;
              }
              if (fVar4 < 0.25) {
                fVar6 = 1500.0;
              }
              else {
                fVar6 = (_K_ONE - fVar4) * 200.0 + fVar6;
              }
              uVar7 = uVar8;
              if (fVar6 < local_38) goto LAB_004fa2ac;
            }
            fVar6 = local_38;
            uVar7 = local_2c;
          }
LAB_004fa2ac:
          local_2c = uVar7;
          local_38 = fVar6;
          uVar8 = uVar8 + 1;
        } while (uVar8 < (uint)param_1[1]);
      }
    }
    local_34 = local_34 + 4;
    local_30 = local_30 + 2;
    if (0x13 < local_34) {
      if (1500.0 <= local_38) {
        return 0;
      }
      return *(undefined4 *)(*param_1 + local_2c * 4);
    }
  } while( true );
}


// ==== 0x4fa310 FUN_004fa310

void __fastcall FUN_004fa310(int *param_1)

{
  int iVar1;
  char cVar2;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  undefined4 uVar3;
  undefined1 local_40 [64];
  
  if ((param_1 != (int *)0x0) && (*(short *)(unaff_EDI + 0x20) != 0)) {
    cVar2 = (**(code **)(*param_1 + 0x2c))(*(short *)(unaff_EDI + 0x20),local_40);
    if (cVar2 == '\0') {
      iVar1 = *(int *)(unaff_EDI + 0x2c);
      *unaff_ESI = *(undefined4 *)(iVar1 + 0x1c);
      unaff_ESI[1] = *(undefined4 *)(iVar1 + 0x20);
      return;
    }
    uVar3 = 0;
    Mat4_TransformPoint();
    *unaff_ESI = uVar3;
    unaff_ESI[1] = 0;
    return;
  }
  iVar1 = *(int *)(unaff_EDI + 0x2c);
  *unaff_ESI = *(undefined4 *)(iVar1 + 0x1c);
  unaff_ESI[1] = *(undefined4 *)(iVar1 + 0x20);
  return;
}


// ==== 0x4fa3a0 FUN_004fa3a0

void __fastcall FUN_004fa3a0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0x3f800000;
  param_1[2] = 0x3f800000;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[9] = 0xffffffff;
  return;
}


// ==== 0x4fa3d0 FUN_004fa3d0

int __fastcall FUN_004fa3d0(int param_1)

{
  int in_EAX;
  
  if (-1 < in_EAX) {
    return in_EAX % param_1;
  }
  if (1 < param_1) {
    return param_1 - -in_EAX % param_1;
  }
  return 0;
}


// ==== 0x4fa3f0 FEGrid_GetCell

/* [canon] hud med (ghidra-canon+nfsug) docs/re/hud.md */

int FEGrid_GetCell(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_EAX;
  int iVar4;
  int unaff_ESI;
  
  iVar4 = param_1;
  iVar1 = *(int *)(unaff_ESI + 0x68);
  iVar2 = *(int *)(unaff_ESI + 0x5c);
  if (iVar1 == 0) {
    param_1 = -1;
  }
  else {
    if (iVar1 <= in_EAX) {
      in_EAX = in_EAX % iVar1;
    }
    param_1 = in_EAX - *(int *)(unaff_ESI + 0x70);
    if ((param_1 < 0) && (param_1 = param_1 + iVar1, param_1 < 0)) {
      if (iVar2 < 2) {
        param_1 = 0;
      }
      else {
        param_1 = iVar2 - -param_1 % iVar2;
      }
    }
    else {
      param_1 = param_1 % iVar2;
    }
  }
  iVar1 = *(int *)(unaff_ESI + 0x6c);
  iVar3 = *(int *)(unaff_ESI + 0x60);
  if (iVar1 == 0) {
    iVar4 = -1;
  }
  else {
    if (iVar1 <= iVar4) {
      iVar4 = iVar4 % iVar1;
    }
    iVar4 = iVar4 - *(int *)(unaff_ESI + 0x74);
    if ((iVar4 < 0) && (iVar4 = iVar4 + iVar1, iVar4 < 0)) {
      if (iVar3 < 2) {
        iVar4 = 0;
      }
      else {
        iVar4 = iVar3 - -iVar4 % iVar3;
      }
    }
    else {
      iVar4 = iVar4 % iVar3;
    }
  }
  return (iVar2 * iVar4 + param_1) * 0x30 + *(int *)(unaff_ESI + 0x88);
}


// ==== 0x4fa4a0 FUN_004fa4a0

void FUN_004fa4a0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FEObject__FEObject();
  *puVar1 = &PTR_FUN_006c183c;
  puVar1[0x16] = 0;
  puVar1[0x17] = 0;
  puVar1[0x18] = 0;
  puVar1[0x19] = 2;
  puVar1[0x1a] = 0;
  puVar1[0x1b] = 0;
  puVar1[0x1c] = 0;
  puVar1[0x1d] = 0;
  puVar1[0x1e] = 0;
  puVar1[0x1f] = 0;
  puVar1[0x20] = 0;
  puVar1[0x21] = 0;
  puVar1[0x22] = 0;
  puVar1[0x23] = 0;
  puVar1[0x24] = 0;
  puVar1[0x25] = 0;
  puVar1[0x26] = 0;
  puVar1[0x27] = 0;
  puVar1[0x28] = 0x3f800000;
  puVar1[0x29] = 0xbab60b61;
  puVar1[0x2d] = 0xff;
  puVar1[0x2c] = 0xff;
  puVar1[0x2b] = 0xff;
  puVar1[0x2a] = 0xff;
  puVar1[0x2e] = PTR_FUN_006f8a0c;
  puVar1[0x2f] = 0;
  puVar1[0x30] = 0;
  puVar1[6] = 6;
  return;
}


// ==== 0x4fa550 FUN_004fa550

void * __thiscall FUN_004fa550(void *param_1,byte param_2)

{
  FUN_004fa870();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4fa570 FUN_004fa570

void __fastcall FUN_004fa570(int param_1)

{
  undefined4 uVar1;
  undefined4 in_EAX;
  undefined4 *unaff_ESI;
  
  FUN_004fec30(unaff_ESI,param_1,in_EAX);
  *unaff_ESI = &PTR_FUN_006c183c;
  uVar1 = *(undefined4 *)(param_1 + 0x58);
  unaff_ESI[0x17] = 0;
  unaff_ESI[0x18] = 0;
  unaff_ESI[0x19] = 0;
  unaff_ESI[0x16] = uVar1;
  unaff_ESI[0x1a] = *(undefined4 *)(param_1 + 0x68);
  uVar1 = *(undefined4 *)(param_1 + 0x6c);
  unaff_ESI[0x1c] = 0;
  unaff_ESI[0x1d] = 0;
  unaff_ESI[0x1e] = 0;
  unaff_ESI[0x1f] = 0;
  unaff_ESI[0x1b] = uVar1;
  unaff_ESI[0x20] = *(undefined4 *)(param_1 + 0x80);
  uVar1 = *(undefined4 *)(param_1 + 0x84);
  unaff_ESI[0x22] = 0;
  unaff_ESI[0x23] = 0;
  unaff_ESI[0x24] = 0;
  unaff_ESI[0x25] = 0;
  unaff_ESI[0x26] = 0;
  unaff_ESI[0x27] = 0;
  unaff_ESI[0x21] = uVar1;
  unaff_ESI[0x28] = 0x3f800000;
  unaff_ESI[0x29] = 0xbab60b61;
  unaff_ESI[0x2d] = 0xff;
  unaff_ESI[0x2c] = 0xff;
  unaff_ESI[0x2b] = 0xff;
  unaff_ESI[0x2a] = 0xff;
  unaff_ESI[0x2e] = *(undefined4 *)(param_1 + 0xb8);
  unaff_ESI[0x2f] = *(undefined4 *)(param_1 + 0xbc);
  unaff_ESI[0x30] = *(undefined4 *)(param_1 + 0xc0);
  FUN_004fa650();
  return;
}


// ==== 0x4fa650 FUN_004fa650

void FUN_004fa650(void)

{
  short sVar1;
  int iVar2;
  undefined2 *puVar3;
  int in_EAX;
  uint uVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  short *psVar8;
  int unaff_EDI;
  uint local_8;
  
  *(uint *)(in_EAX + 100) = *(uint *)(in_EAX + 100) | *(uint *)(unaff_EDI + 100) & 0xe;
  *(undefined4 *)(in_EAX + 0x80) = *(undefined4 *)(unaff_EDI + 0x80);
  *(undefined4 *)(in_EAX + 0x84) = *(undefined4 *)(unaff_EDI + 0x84);
  *(undefined4 *)(in_EAX + 0x68) = *(undefined4 *)(unaff_EDI + 0x68);
  *(undefined4 *)(in_EAX + 0x6c) = *(undefined4 *)(unaff_EDI + 0x6c);
  FUN_004fa8c0(in_EAX);
  if (*(void **)(in_EAX + 0x9c) != (void *)0x0) {
    _free(*(void **)(in_EAX + 0x9c));
    *(undefined4 *)(in_EAX + 0x9c) = 0;
  }
  if (*(void **)(in_EAX + 0x98) != (void *)0x0) {
    _free(*(void **)(in_EAX + 0x98));
    *(undefined4 *)(in_EAX + 0x98) = 0;
  }
  *(undefined4 *)(in_EAX + 0x8c) = 0;
  *(undefined4 *)(in_EAX + 0x94) = 0;
  *(undefined4 *)(in_EAX + 0x90) = 0;
  FEGrid_AllocStringBuffers(*(undefined4 *)(unaff_EDI + 0x8c),*(undefined4 *)(unaff_EDI + 0x90));
  uVar4 = *(int *)(in_EAX + 0x60) * *(int *)(in_EAX + 0x5c);
  local_8 = 0;
  if (uVar4 != 0) {
    iVar5 = 0;
    do {
      *(undefined4 *)(iVar5 + *(int *)(in_EAX + 0x88)) =
           *(undefined4 *)(iVar5 + *(int *)(unaff_EDI + 0x88));
      *(undefined4 *)(iVar5 + 0x18 + *(int *)(in_EAX + 0x88)) =
           *(undefined4 *)(iVar5 + 0x18 + *(int *)(unaff_EDI + 0x88));
      iVar7 = *(int *)(unaff_EDI + 0x88);
      iVar2 = *(int *)(in_EAX + 0x88);
      *(undefined4 *)(iVar5 + 4 + iVar2) = *(undefined4 *)(iVar5 + 4 + iVar7);
      *(undefined4 *)(iVar5 + 8 + iVar2) = *(undefined4 *)(iVar5 + iVar7 + 8);
      *(undefined4 *)(iVar5 + 0xc + *(int *)(in_EAX + 0x88)) =
           *(undefined4 *)(iVar5 + 0xc + *(int *)(unaff_EDI + 0x88));
      *(undefined4 *)(iVar5 + 0x14 + *(int *)(in_EAX + 0x88)) =
           *(undefined4 *)(iVar5 + 0x14 + *(int *)(unaff_EDI + 0x88));
      *(undefined4 *)(iVar5 + 0x10 + *(int *)(in_EAX + 0x88)) =
           *(undefined4 *)(iVar5 + 0x10 + *(int *)(unaff_EDI + 0x88));
      *(undefined4 *)(iVar5 + 0x1c + *(int *)(in_EAX + 0x88)) =
           *(undefined4 *)(iVar5 + 0x1c + *(int *)(unaff_EDI + 0x88));
      if (*(int *)(iVar5 + 0x18 + *(int *)(in_EAX + 0x88)) == 2) {
        psVar8 = *(short **)(iVar5 + 0x20 + *(int *)(unaff_EDI + 0x88));
        if (psVar8 == (short *)0x0) {
          return;
        }
        puVar3 = *(undefined2 **)(*(int *)(in_EAX + 0x98) + *(int *)(in_EAX + 0x94) * 4);
        *(int *)(in_EAX + 0x94) = *(int *)(in_EAX + 0x94) + 1;
        *puVar3 = 0;
        *(undefined2 **)(iVar5 + 0x20 + *(int *)(in_EAX + 0x88)) = puVar3;
        psVar6 = *(short **)(iVar5 + 0x20 + *(int *)(in_EAX + 0x88));
        if (psVar6 != (short *)0x0) {
          sVar1 = *psVar8;
          while (sVar1 != 0) {
            *psVar6 = sVar1;
            psVar8 = psVar8 + 1;
            psVar6 = psVar6 + 1;
            sVar1 = *psVar8;
          }
          *psVar6 = 0;
        }
      }
      iVar7 = *(int *)(in_EAX + 0x88) + iVar5;
      if (*(int *)(*(int *)(in_EAX + 0x88) + 0x18 + iVar5) == 1) {
        iVar2 = iVar5 + 0x20 + *(int *)(unaff_EDI + 0x88);
        *(undefined4 *)(iVar7 + 0x20) = *(undefined4 *)(iVar5 + 0x20 + *(int *)(unaff_EDI + 0x88));
        *(undefined4 *)(iVar7 + 0x24) = *(undefined4 *)(iVar2 + 4);
        *(undefined4 *)(iVar7 + 0x28) = *(undefined4 *)(iVar2 + 8);
        *(undefined4 *)(iVar7 + 0x2c) = *(undefined4 *)(iVar2 + 0xc);
      }
      local_8 = local_8 + 1;
      iVar5 = iVar5 + 0x30;
    } while (local_8 < uVar4);
  }
  return;
}


// ==== 0x4fa870 FUN_004fa870

void FUN_004fa870(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_FUN_006c183c;
  if ((void *)unaff_ESI[0x22] != (void *)0x0) {
    _free((void *)unaff_ESI[0x22]);
  }
  if ((void *)unaff_ESI[0x27] != (void *)0x0) {
    _free((void *)unaff_ESI[0x27]);
  }
  if ((void *)unaff_ESI[0x26] != (void *)0x0) {
    _free((void *)unaff_ESI[0x26]);
  }
  FUN_004fef10();
  return;
}


// ==== 0x4fa8c0 FUN_004fa8c0

void __thiscall FUN_004fa8c0(int param_1,int param_2)

{
  undefined4 *_Memory;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int in_EAX;
  int iVar5;
  void *pvVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 *local_14;
  undefined4 *local_10;
  undefined4 local_8;
  
  _Memory = *(undefined4 **)(param_2 + 0x88);
  uVar1 = *(uint *)(param_2 + 0x5c);
  *(int *)(param_2 + 0x5c) = in_EAX;
  iVar5 = in_EAX * param_1;
  uVar2 = *(uint *)(param_2 + 0x60);
  *(int *)(param_2 + 0x60) = param_1;
  pvVar6 = _malloc(iVar5 * 0x30);
  if (pvVar6 == (void *)0x0) {
    pvVar6 = (void *)0x0;
  }
  else if (-1 < iVar5 + -1) {
    puVar7 = (undefined4 *)((int)pvVar6 + 0x10);
    do {
      puVar7[-4] = 0;
      puVar7[-3] = 0x3f800000;
      puVar7[-2] = 0x3f800000;
      puVar7[-1] = 0;
      *puVar7 = 0;
      puVar7[1] = 0;
      puVar7[2] = 0;
      puVar7[4] = 0;
      puVar7[5] = 0xffffffff;
      puVar7 = puVar7 + 0xc;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  *(void **)(param_2 + 0x88) = pvVar6;
  FEListBox__InitializeCell();
  uVar8 = *(uint *)(param_2 + 0x5c);
  uVar9 = *(uint *)(param_2 + 0x78);
  *(uint *)(param_2 + 0x68) = uVar8;
  if (uVar8 <= uVar9) {
    if (uVar8 == 0) {
      uVar9 = 0;
    }
    else {
      uVar9 = uVar8 - 1;
    }
  }
  uVar11 = *(uint *)(param_2 + 100) & 8;
  if (uVar11 != 0) {
    iVar5 = uVar9 - (uVar8 >> 1);
    if (iVar5 < 0) {
      if ((int)uVar8 < 2) {
        uVar9 = 0;
      }
      else {
        uVar9 = uVar8 - -iVar5 % (int)uVar8;
      }
    }
    else {
      uVar9 = iVar5 % (int)uVar8;
    }
  }
  uVar3 = *(uint *)(param_2 + 0x60);
  *(uint *)(param_2 + 0x70) = uVar9;
  uVar9 = *(uint *)(param_2 + 0x7c);
  *(uint *)(param_2 + 0x6c) = uVar3;
  if (uVar3 <= uVar9) {
    if (uVar3 == 0) {
      uVar9 = 0;
    }
    else {
      uVar9 = uVar3 - 1;
    }
  }
  if (uVar11 != 0) {
    iVar5 = uVar9 - (uVar3 >> 1);
    if (iVar5 < 0) {
      if ((int)uVar3 < 2) {
        uVar9 = 0;
      }
      else {
        uVar9 = uVar3 - -iVar5 % (int)uVar3;
      }
    }
    else {
      uVar9 = iVar5 % (int)uVar3;
    }
  }
  *(uint *)(param_2 + 0x74) = uVar9;
  if ((*(byte *)(param_2 + 100) & 1) != 0) {
    uVar9 = uVar1;
    if (uVar8 < uVar1) {
      uVar9 = uVar8;
    }
    uVar8 = uVar2;
    if (uVar3 < uVar2) {
      uVar8 = uVar3;
    }
    if (_Memory != (undefined4 *)0x0) {
      uVar11 = 0;
      if (uVar8 != 0) {
        local_10 = _Memory + uVar9 * 0xc + 8;
        local_14 = _Memory;
        do {
          puVar7 = local_14;
          puVar12 = (undefined4 *)
                    (*(int *)(param_2 + 0x5c) * uVar11 * 0x30 + *(int *)(param_2 + 0x88));
          for (iVar5 = (*(int *)(param_2 + 0x5c) * 3 & 0xfffffffU) << 2; iVar5 != 0;
              iVar5 = iVar5 + -1) {
            *puVar12 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar12 = puVar12 + 1;
          }
          for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
            *(undefined1 *)puVar12 = *(undefined1 *)puVar7;
            puVar7 = (undefined4 *)((int)puVar7 + 1);
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
          if (uVar9 < uVar1) {
            iVar5 = uVar1 - uVar9;
            puVar7 = local_10;
            do {
              if (puVar7[-2] == 2) {
                uVar4 = *puVar7;
                iVar10 = *(int *)(param_2 + 0x94) + -1;
                *(int *)(param_2 + 0x94) = iVar10;
                *(undefined4 *)(*(int *)(param_2 + 0x98) + iVar10 * 4) = uVar4;
              }
              puVar7 = puVar7 + 0xc;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
          local_14 = local_14 + uVar1 * 0xc;
          local_10 = local_10 + uVar1 * 0xc;
          uVar11 = uVar11 + 1;
        } while (uVar11 < uVar8);
      }
      if (uVar8 < uVar2) {
        puVar7 = _Memory + uVar8 * uVar1 * 0xc + 8;
        local_8 = uVar2 - uVar8;
        uVar2 = uVar1;
        puVar12 = puVar7;
        do {
          for (; uVar2 != 0; uVar2 = uVar2 - 1) {
            if (puVar7[-2] == 2) {
              uVar4 = *puVar7;
              iVar5 = *(int *)(param_2 + 0x94) + -1;
              *(int *)(param_2 + 0x94) = iVar5;
              *(undefined4 *)(*(int *)(param_2 + 0x98) + iVar5 * 4) = uVar4;
            }
            puVar7 = puVar7 + 0xc;
          }
          puVar7 = puVar12 + uVar1 * 0xc;
          local_8 = local_8 + -1;
          uVar2 = uVar1;
          puVar12 = puVar7;
        } while (local_8 != 0);
      }
      _free(_Memory);
    }
  }
  *(uint *)(param_2 + 100) = *(uint *)(param_2 + 100) | 1;
  return;
}


// ==== 0x4fab90 FUN_004fab90

void FUN_004fab90(void)

{
  void *pvVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0xc4);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_004fa570();
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x4fabf0 FEGrid_ForEachCellInRect

/* [canon] hud med (ghidra-canon+nfsug) docs/re/hud.md */

uint FEGrid_ForEachCellInRect(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint in_EAX;
  uint uVar4;
  int iVar5;
  int iVar6;
  int unaff_ESI;
  uint local_c;
  uint local_8;
  
  local_c = *(uint *)(unaff_ESI + 0x68);
  if ((((local_c != 0) && (uVar1 = *(uint *)(unaff_ESI + 0x6c), uVar1 != 0)) &&
      (in_EAX = *(uint *)(unaff_ESI + 0x60), in_EAX != 0)) &&
     (uVar4 = *(uint *)(unaff_ESI + 0x5c), uVar4 != 0)) {
    iVar6 = *(int *)(unaff_ESI + 0x74);
    iVar2 = *(int *)(unaff_ESI + 0x70);
    if (uVar1 < in_EAX) {
      in_EAX = uVar1;
    }
    if (uVar4 <= local_c) {
      local_c = uVar4;
    }
    if (*(int *)(unaff_ESI + 0xbc) == 0) {
      uVar1 = in_EAX;
      if (*(int *)(unaff_ESI + 0x58) != 0) {
        for (; iVar5 = iVar2, uVar4 = local_c, uVar1 != 0; uVar1 = uVar1 - 1) {
          for (; uVar4 != 0; uVar4 = uVar4 - 1) {
            (**(code **)(**(int **)(unaff_ESI + 0x58) + 0x4c))();
            iVar3 = *(int *)(unaff_ESI + 0x68);
            iVar5 = iVar5 + 1;
            if (iVar5 < 0) {
              if (iVar3 < 2) {
                iVar5 = 0;
              }
              else {
                iVar5 = iVar3 - -iVar5 % iVar3;
              }
            }
            else {
              iVar5 = iVar5 % iVar3;
            }
          }
          iVar5 = *(int *)(unaff_ESI + 0x6c);
          in_EAX = iVar6 + 1;
          if ((int)in_EAX < 0) {
            if (iVar5 < 2) {
              iVar6 = 0;
            }
            else {
              iVar6 = -in_EAX;
              in_EAX = iVar6 / iVar5;
              iVar6 = iVar5 - iVar6 % iVar5;
            }
          }
          else {
            iVar6 = (int)in_EAX % iVar5;
            in_EAX = (int)in_EAX / iVar5;
          }
        }
      }
    }
    else {
      iVar5 = iVar2;
      uVar1 = local_c;
      local_8 = in_EAX;
      if (in_EAX != 0) {
        do {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            (**(code **)(unaff_ESI + 0xbc))(*(undefined4 *)(unaff_ESI + 0xc0));
            iVar3 = *(int *)(unaff_ESI + 0x68);
            iVar5 = iVar5 + 1;
            if (iVar5 < 0) {
              if (iVar3 < 2) {
                iVar5 = 0;
              }
              else {
                iVar5 = iVar3 - -iVar5 % iVar3;
              }
            }
            else {
              iVar5 = iVar5 % iVar3;
            }
          }
          iVar5 = *(int *)(unaff_ESI + 0x6c);
          uVar4 = iVar6 + 1;
          if ((int)uVar4 < 0) {
            if (iVar5 < 2) {
              iVar6 = 0;
            }
            else {
              iVar6 = -uVar4;
              uVar4 = iVar6 / iVar5;
              iVar6 = iVar5 - iVar6 % iVar5;
            }
          }
          else {
            iVar6 = (int)uVar4 % iVar5;
            uVar4 = (int)uVar4 / iVar5;
          }
          local_8 = local_8 - 1;
          iVar5 = iVar2;
          uVar1 = local_c;
        } while (local_8 != 0);
        return uVar4;
      }
    }
  }
  return in_EAX;
}


// ==== 0x4fad70 FEGrid_AllocStringBuffers

/* [canon] hud med (ghidra-canon+nfsug) docs/re/hud.md */

void FEGrid_AllocStringBuffers(uint param_1,int param_2)

{
  void *_Memory;
  void *_Memory_00;
  short *psVar1;
  void *pvVar2;
  int iVar3;
  undefined2 *puVar4;
  uint uVar5;
  int iVar6;
  int unaff_ESI;
  uint uVar7;
  undefined4 *puVar8;
  
  _Memory = *(void **)(unaff_ESI + 0x9c);
  _Memory_00 = *(void **)(unaff_ESI + 0x98);
  *(undefined4 *)(unaff_ESI + 0x8c) = 0;
  *(undefined4 *)(unaff_ESI + 0x94) = 0;
  *(undefined4 *)(unaff_ESI + 0x90) = 0;
  *(undefined4 *)(unaff_ESI + 0x9c) = 0;
  *(undefined4 *)(unaff_ESI + 0x98) = 0;
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar7 = param_1 * param_2 * 2;
    pvVar2 = _malloc(uVar7);
    *(void **)(unaff_ESI + 0x9c) = pvVar2;
    pvVar2 = _malloc(param_1 * 4);
    *(void **)(unaff_ESI + 0x98) = pvVar2;
    puVar8 = *(undefined4 **)(unaff_ESI + 0x9c);
    for (uVar5 = (param_1 * param_2 & 0x7fffffff) >> 1; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined1 *)puVar8 = 0;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    uVar5 = 0;
    if (param_1 != 0) {
      iVar6 = 0;
      do {
        *(int *)(*(int *)(unaff_ESI + 0x98) + uVar5 * 4) = *(int *)(unaff_ESI + 0x9c) + iVar6;
        uVar5 = uVar5 + 1;
        iVar6 = iVar6 + param_2 * 2;
      } while (uVar5 < param_1);
    }
    *(uint *)(unaff_ESI + 0x8c) = param_1;
    *(int *)(unaff_ESI + 0x90) = param_2;
    if (_Memory == (void *)0x0) goto LAB_004faf12;
    if ((_Memory_00 != (void *)0x0) && (param_1 = 0, *(int *)(unaff_ESI + 0x60) != 0)) {
      do {
        uVar5 = 0;
        if (*(int *)(unaff_ESI + 0x5c) != 0) {
          do {
            iVar6 = (*(int *)(unaff_ESI + 0x5c) * param_1 + uVar5) * 0x30;
            iVar3 = iVar6 + *(int *)(unaff_ESI + 0x88);
            if (*(int *)(iVar6 + 0x18 + *(int *)(unaff_ESI + 0x88)) == 2) {
              puVar4 = *(undefined2 **)(*(int *)(unaff_ESI + 0x98) + *(int *)(unaff_ESI + 0x94) * 4)
              ;
              psVar1 = *(short **)(iVar3 + 0x20);
              *(int *)(unaff_ESI + 0x94) = *(int *)(unaff_ESI + 0x94) + 1;
              *puVar4 = 0;
              *(undefined2 **)(iVar3 + 0x20) = puVar4;
              if (psVar1 != (short *)0x0) {
                iVar6 = 0;
                if (*psVar1 != 0) {
                  iVar3 = (int)psVar1 - (int)puVar4;
                  do {
                    if (param_2 + -1 == iVar6) break;
                    *puVar4 = *(undefined2 *)(iVar3 + (int)puVar4);
                    puVar4 = puVar4 + 1;
                    iVar6 = iVar6 + 1;
                  } while (*(short *)(iVar3 + (int)puVar4) != 0);
                }
              }
              *puVar4 = 0;
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < *(uint *)(unaff_ESI + 0x5c));
        }
        param_1 = param_1 + 1;
      } while (param_1 < *(uint *)(unaff_ESI + 0x60));
    }
  }
  if (_Memory != (void *)0x0) {
    _free(_Memory);
  }
LAB_004faf12:
  if (_Memory_00 != (void *)0x0) {
    _free(_Memory_00);
  }
  return;
}


// ==== 0x4faf30 FUN_004faf30

void FUN_004faf30(void)

{
  int unaff_ESI;
  
  FUN_004fb210(unaff_ESI,unaff_ESI + 0x70,unaff_ESI + 0x78,*(undefined4 *)(unaff_ESI + 0x68),
               *(undefined4 *)(unaff_ESI + 0x5c),1);
  FUN_004fb210(unaff_ESI,unaff_ESI + 0x74,unaff_ESI + 0x7c,*(undefined4 *)(unaff_ESI + 0x6c),
               *(undefined4 *)(unaff_ESI + 0x60),0);
  return;
}


// ==== 0x4faf70 FUN_004faf70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004faf70(float param_1)

{
  float fVar1;
  int unaff_ESI;
  
  if (*(code **)(unaff_ESI + 0xb8) != (code *)0x0) {
    (**(code **)(unaff_ESI + 0xb8))();
  }
  fVar1 = param_1 * *(float *)(unaff_ESI + 0xa4) + *(float *)(unaff_ESI + 0xa0);
  *(float *)(unaff_ESI + 0xa0) = fVar1;
  if (fVar1 < 0.0) {
    *(undefined4 *)(unaff_ESI + 0xa0) = 0;
    *(float *)(unaff_ESI + 0xa4) = -*(float *)(unaff_ESI + 0xa4);
    return;
  }
  if (_K_ONE < fVar1) {
    *(undefined4 *)(unaff_ESI + 0xa0) = 0x3f800000;
    *(float *)(unaff_ESI + 0xa4) = -*(float *)(unaff_ESI + 0xa4);
  }
  return;
}


// ==== 0x4faff0 FUN_004faff0

void FUN_004faff0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = *(undefined4 *)(param_1 + 0xa8);
  uVar2 = *(undefined4 *)(param_1 + 0xac);
  uVar3 = *(undefined4 *)(param_1 + 0xb0);
  uVar4 = _ftol_nocw();
  *(undefined4 *)(param_1 + 0xa8) = uVar1;
  *(undefined4 *)(param_1 + 0xb0) = uVar3;
  *(undefined4 *)(param_1 + 0xac) = uVar2;
  *(undefined4 *)(param_1 + 0xb4) = uVar4;
  return;
}


// ==== 0x4fb040 FUN_004fb040

uint __fastcall FUN_004fb040(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  undefined4 uVar3;
  int unaff_ESI;
  
  uVar2 = *(uint *)(unaff_ESI + 100) & 4;
  if ((uVar2 != 0) && (param_2 <= param_5)) {
    iVar1 = **(int **)(unaff_ESI + 0x58);
    uVar3 = FEng__HashName();
    (**(code **)(iVar1 + 0x18))(uVar3);
LAB_004fb08e:
    iVar1 = **(int **)(unaff_ESI + 0x58);
    uVar3 = FEng__HashName();
    uVar2 = (**(code **)(iVar1 + 0x18))(uVar3);
    return uVar2 & 0xffffff00;
  }
  if ((*(uint *)(unaff_ESI + 100) & 2) != 0) {
    if (uVar2 == 0) {
      uVar2 = in_EAX + param_4;
      if ((int)uVar2 < 0) goto LAB_004fb0bd;
    }
    else {
      uVar2 = param_3 + in_EAX;
      if ((int)uVar2 < 0) {
LAB_004fb0bd:
        iVar1 = **(int **)(unaff_ESI + 0x58);
        uVar3 = FEng__HashName();
        uVar2 = (**(code **)(iVar1 + 0x18))(uVar3);
        return uVar2 & 0xffffff00;
      }
      param_2 = param_2 - param_5;
    }
    if (param_2 <= (int)uVar2) goto LAB_004fb08e;
  }
  return CONCAT31((int3)(uVar2 >> 8),1);
}


// ==== 0x4fb0f0 FUN_004fb0f0

undefined4 __thiscall FUN_004fb0f0(int param_1,uint *param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int unaff_EDI;
  
  uVar3 = *(uint *)(in_EAX + 100);
  if ((uVar3 & 8) != 0) {
    iVar2 = *param_2 + unaff_EDI;
    if (iVar2 < 0) {
      if (param_1 < 2) {
        uVar3 = 0;
      }
      else {
        uVar3 = param_1 - -iVar2 % param_1;
      }
    }
    else {
      uVar3 = iVar2 % param_1;
    }
    *param_2 = uVar3;
    iVar2 = *param_3 + unaff_EDI;
    if (-1 < iVar2) {
      *param_3 = iVar2 % param_1;
      return 1;
    }
    if (1 < param_1) {
      *param_3 = param_1 - -iVar2 % param_1;
      return 1;
    }
    *param_3 = 0;
    return 1;
  }
  if (((uVar3 & 4) != 0) && ((uVar3 & 2) != 0)) {
    iVar2 = *param_2 + unaff_EDI;
    if (-1 < iVar2) {
      *param_2 = iVar2 % param_1;
      *param_3 = iVar2 % param_1;
      return 1;
    }
    if (1 < param_1) {
      uVar3 = param_1 - -iVar2 % param_1;
      *param_2 = uVar3;
      *param_3 = uVar3;
      return 1;
    }
    *param_2 = 0;
    *param_3 = 0;
    return 1;
  }
  uVar3 = *param_3;
  iVar2 = uVar3 + unaff_EDI;
  if (iVar2 < 0) {
    if (param_1 < 2) {
      uVar4 = 0;
    }
    else {
      uVar4 = param_1 - -iVar2 % param_1;
    }
  }
  else {
    uVar4 = iVar2 % param_1;
  }
  *param_3 = uVar4;
  if (unaff_EDI < 0) {
    if (*param_2 == uVar3) {
LAB_004fb1fc:
      *param_2 = uVar4;
      return 1;
    }
  }
  else {
    uVar1 = *param_2;
    if (uVar1 != uVar3) {
      if (uVar1 < uVar4) {
        uVar4 = uVar4 - uVar1;
      }
      else {
        uVar4 = (uVar4 - uVar1) + param_1;
      }
      if (param_4 <= uVar4) {
        uVar4 = FUN_004fa3d0();
        goto LAB_004fb1fc;
      }
    }
  }
  return 0;
}


// ==== 0x4fb210 FUN_004fb210

undefined4
FUN_004fb210(int param_1,undefined4 *param_2,undefined4 *param_3,int param_4,uint param_5,
            char param_6)

{
  undefined4 uVar1;
  char cVar2;
  int in_EAX;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  if (in_EAX == 0) {
    return 0;
  }
  cVar2 = FUN_004fb040(*param_2,*param_3,param_5);
  if ((cVar2 != '\0') && (cVar2 = FUN_004fb0f0(param_2,param_3,param_5), cVar2 != '\0')) {
    if (param_4 != 0) {
      if (param_6 == '\0') {
        if (in_EAX < 1) {
          if (*(int *)(param_1 + 0xbc) == 0) {
            if (*(int *)(param_1 + 0x58) != 0) {
              uVar7 = *(uint *)(param_1 + 0x5c);
              _param_6 = 0;
              if (uVar7 != 0) {
                param_5 = 0;
                do {
                  iVar8 = *(int *)(param_1 + 0x60) + -1;
                  uVar3 = *(undefined4 *)
                           ((uVar7 * iVar8 + _param_6) * 0x30 + 0x20 + *(int *)(param_1 + 0x88));
                  while (iVar8 != 0) {
                    iVar5 = *(int *)(param_1 + 0x5c) * iVar8 + _param_6;
                    iVar8 = iVar8 + -1;
                    puVar10 = (undefined4 *)
                              ((iVar5 - *(int *)(param_1 + 0x5c)) * 0x30 + *(int *)(param_1 + 0x88))
                    ;
                    puVar9 = (undefined4 *)(iVar5 * 0x30 + *(int *)(param_1 + 0x88));
                    for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
                      *puVar9 = *puVar10;
                      puVar10 = puVar10 + 1;
                      puVar9 = puVar9 + 1;
                    }
                  }
                  *(undefined4 *)(param_5 + 0x20 + *(int *)(param_1 + 0x88)) = uVar3;
                  iVar8 = *(int *)(param_1 + 0x74);
                  iVar5 = *(int *)(param_1 + 0x6c);
                  if (iVar8 < 0) {
                    if (iVar5 < 2) {
                      iVar8 = 0;
                    }
                    else {
                      iVar8 = iVar5 - -iVar8 % iVar5;
                    }
                  }
                  else {
                    iVar8 = iVar8 % iVar5;
                  }
                  (**(code **)(**(int **)(param_1 + 0x58) + 0x4c))
                            (param_1,*(undefined4 *)(param_1 + 0x70),iVar8);
                  uVar7 = *(uint *)(param_1 + 0x5c);
                  _param_6 = _param_6 + 1;
                  param_5 = param_5 + 0x30;
                } while (_param_6 < uVar7);
              }
            }
          }
          else {
            uVar7 = *(uint *)(param_1 + 0x5c);
            _param_6 = 0;
            if (uVar7 != 0) {
              param_5 = 0;
              do {
                iVar8 = *(int *)(param_1 + 0x60) + -1;
                uVar3 = *(undefined4 *)
                         ((uVar7 * iVar8 + _param_6) * 0x30 + 0x20 + *(int *)(param_1 + 0x88));
                while (iVar8 != 0) {
                  iVar5 = *(int *)(param_1 + 0x5c) * iVar8 + _param_6;
                  iVar8 = iVar8 + -1;
                  puVar10 = (undefined4 *)
                            ((iVar5 - *(int *)(param_1 + 0x5c)) * 0x30 + *(int *)(param_1 + 0x88));
                  puVar9 = (undefined4 *)(iVar5 * 0x30 + *(int *)(param_1 + 0x88));
                  for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
                    *puVar9 = *puVar10;
                    puVar10 = puVar10 + 1;
                    puVar9 = puVar9 + 1;
                  }
                }
                *(undefined4 *)(param_5 + 0x20 + *(int *)(param_1 + 0x88)) = uVar3;
                iVar8 = *(int *)(param_1 + 0x74);
                iVar5 = *(int *)(param_1 + 0x6c);
                if (iVar8 < 0) {
                  if (iVar5 < 2) {
                    iVar8 = 0;
                  }
                  else {
                    iVar8 = iVar5 - -iVar8 % iVar5;
                  }
                }
                else {
                  iVar8 = iVar8 % iVar5;
                }
                (**(code **)(param_1 + 0xbc))
                          (*(undefined4 *)(param_1 + 0xc0),param_1,*(undefined4 *)(param_1 + 0x70),
                           iVar8);
                uVar7 = *(uint *)(param_1 + 0x5c);
                _param_6 = _param_6 + 1;
                param_5 = param_5 + 0x30;
              } while (_param_6 < uVar7);
              return 1;
            }
          }
        }
        else {
          iVar8 = *(int *)(param_1 + 0x60);
          uVar3 = FUN_004fa3d0();
          if (*(int *)(param_1 + 0xbc) == 0) {
            if ((*(int *)(param_1 + 0x58) != 0) && (param_5 = 0, *(int *)(param_1 + 0x5c) != 0)) {
              param_3 = (undefined4 *)0x0;
              do {
                uVar1 = *(undefined4 *)((int)param_3 + 0x20 + *(int *)(param_1 + 0x88));
                uVar7 = 0;
                if (iVar8 != 1) {
                  do {
                    iVar5 = *(int *)(param_1 + 0x5c) * uVar7 + param_5;
                    uVar7 = uVar7 + 1;
                    puVar10 = (undefined4 *)
                              ((*(int *)(param_1 + 0x5c) + iVar5) * 0x30 + *(int *)(param_1 + 0x88))
                    ;
                    puVar9 = (undefined4 *)(iVar5 * 0x30 + *(int *)(param_1 + 0x88));
                    for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
                      *puVar9 = *puVar10;
                      puVar10 = puVar10 + 1;
                      puVar9 = puVar9 + 1;
                    }
                  } while (uVar7 < iVar8 - 1U);
                }
                *(undefined4 *)
                 ((*(int *)(param_1 + 0x5c) * uVar7 + param_5) * 0x30 + 0x20 +
                 *(int *)(param_1 + 0x88)) = uVar1;
                iVar4 = *(int *)(param_1 + 0x70) + param_5;
                iVar5 = *(int *)(param_1 + 0x68);
                if (iVar4 < 0) {
                  if (iVar5 < 2) {
                    iVar4 = 0;
                  }
                  else {
                    iVar4 = iVar5 - -iVar4 % iVar5;
                  }
                }
                else {
                  iVar4 = iVar4 % iVar5;
                }
                (**(code **)(**(int **)(param_1 + 0x58) + 0x4c))(param_1,iVar4,uVar3);
                param_5 = param_5 + 1;
                param_3 = (undefined4 *)((int)param_3 + 0x30);
              } while (param_5 < *(uint *)(param_1 + 0x5c));
              return 1;
            }
          }
          else {
            param_5 = 0;
            if (*(int *)(param_1 + 0x5c) != 0) {
              param_3 = (undefined4 *)0x0;
              do {
                uVar1 = *(undefined4 *)((int)param_3 + 0x20 + *(int *)(param_1 + 0x88));
                uVar7 = 0;
                if (iVar8 != 1) {
                  do {
                    iVar5 = *(int *)(param_1 + 0x5c) * uVar7 + param_5;
                    uVar7 = uVar7 + 1;
                    puVar10 = (undefined4 *)
                              ((*(int *)(param_1 + 0x5c) + iVar5) * 0x30 + *(int *)(param_1 + 0x88))
                    ;
                    puVar9 = (undefined4 *)(iVar5 * 0x30 + *(int *)(param_1 + 0x88));
                    for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
                      *puVar9 = *puVar10;
                      puVar10 = puVar10 + 1;
                      puVar9 = puVar9 + 1;
                    }
                  } while (uVar7 < iVar8 - 1U);
                }
                *(undefined4 *)
                 ((*(int *)(param_1 + 0x5c) * uVar7 + param_5) * 0x30 + 0x20 +
                 *(int *)(param_1 + 0x88)) = uVar1;
                iVar4 = *(int *)(param_1 + 0x70) + param_5;
                iVar5 = *(int *)(param_1 + 0x68);
                if (iVar4 < 0) {
                  if (iVar5 < 2) {
                    iVar4 = 0;
                  }
                  else {
                    iVar4 = iVar5 - -iVar4 % iVar5;
                  }
                }
                else {
                  iVar4 = iVar4 % iVar5;
                }
                (**(code **)(param_1 + 0xbc))(*(undefined4 *)(param_1 + 0xc0),param_1,iVar4,uVar3);
                param_5 = param_5 + 1;
                param_3 = (undefined4 *)((int)param_3 + 0x30);
              } while (param_5 < *(uint *)(param_1 + 0x5c));
              return 1;
            }
          }
        }
      }
      else if (in_EAX < 1) {
        if (*(int *)(param_1 + 0xbc) == 0) {
          if (*(int *)(param_1 + 0x58) != 0) {
            uVar7 = 0;
            if (*(int *)(param_1 + 0x60) != 0) {
              _param_6 = 0x30;
              do {
                iVar8 = *(int *)(param_1 + 0x5c);
                uVar3 = *(undefined4 *)(iVar8 * _param_6 + -0x10 + *(int *)(param_1 + 0x88));
                while (iVar8 = iVar8 + -1, iVar8 != 0) {
                  puVar10 = (undefined4 *)
                            ((*(int *)(param_1 + 0x5c) * uVar7 + iVar8) * 0x30 +
                            *(int *)(param_1 + 0x88));
                  puVar9 = puVar10 + -0xc;
                  for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
                    *puVar10 = *puVar9;
                    puVar9 = puVar9 + 1;
                    puVar10 = puVar10 + 1;
                  }
                }
                *(undefined4 *)
                 (*(int *)(param_1 + 0x5c) * uVar7 * 0x30 + 0x20 + *(int *)(param_1 + 0x88)) = uVar3
                ;
                iVar5 = *(int *)(param_1 + 0x74) + uVar7;
                iVar8 = *(int *)(param_1 + 0x6c);
                if (iVar5 < 0) {
                  if (iVar8 < 2) {
                    iVar5 = 0;
                  }
                  else {
                    iVar5 = iVar8 - -iVar5 % iVar8;
                  }
                }
                else {
                  iVar5 = iVar5 % iVar8;
                }
                (**(code **)(**(int **)(param_1 + 0x58) + 0x4c))
                          (param_1,*(undefined4 *)(param_1 + 0x70),iVar5);
                uVar7 = uVar7 + 1;
                _param_6 = _param_6 + 0x30;
              } while (uVar7 < *(uint *)(param_1 + 0x60));
              return 1;
            }
          }
        }
        else {
          uVar7 = 0;
          if (*(int *)(param_1 + 0x60) != 0) {
            _param_6 = 0x30;
            do {
              iVar8 = *(int *)(param_1 + 0x5c);
              uVar3 = *(undefined4 *)(iVar8 * _param_6 + -0x10 + *(int *)(param_1 + 0x88));
              while (iVar8 = iVar8 + -1, iVar8 != 0) {
                puVar10 = (undefined4 *)
                          ((*(int *)(param_1 + 0x5c) * uVar7 + iVar8) * 0x30 +
                          *(int *)(param_1 + 0x88));
                puVar9 = puVar10 + -0xc;
                for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
                  *puVar10 = *puVar9;
                  puVar9 = puVar9 + 1;
                  puVar10 = puVar10 + 1;
                }
              }
              *(undefined4 *)
               (*(int *)(param_1 + 0x5c) * uVar7 * 0x30 + 0x20 + *(int *)(param_1 + 0x88)) = uVar3;
              iVar5 = *(int *)(param_1 + 0x74) + uVar7;
              iVar8 = *(int *)(param_1 + 0x6c);
              if (iVar5 < 0) {
                if (iVar8 < 2) {
                  iVar5 = 0;
                }
                else {
                  iVar5 = iVar8 - -iVar5 % iVar8;
                }
              }
              else {
                iVar5 = iVar5 % iVar8;
              }
              (**(code **)(param_1 + 0xbc))
                        (*(undefined4 *)(param_1 + 0xc0),param_1,*(undefined4 *)(param_1 + 0x70),
                         iVar5);
              uVar7 = uVar7 + 1;
              _param_6 = _param_6 + 0x30;
            } while (uVar7 < *(uint *)(param_1 + 0x60));
            return 1;
          }
        }
      }
      else {
        iVar8 = *(int *)(param_1 + 0x5c);
        uVar3 = FUN_004fa3d0();
        if (*(int *)(param_1 + 0xbc) == 0) {
          if (*(int *)(param_1 + 0x58) != 0) {
            uVar7 = 0;
            if (*(int *)(param_1 + 0x60) != 0) {
              do {
                uVar1 = *(undefined4 *)
                         (*(int *)(param_1 + 0x5c) * uVar7 * 0x30 + 0x20 + *(int *)(param_1 + 0x88))
                ;
                uVar6 = 0;
                if (iVar8 != 1) {
                  do {
                    puVar10 = (undefined4 *)
                              ((*(int *)(param_1 + 0x5c) * uVar7 + uVar6) * 0x30 +
                              *(int *)(param_1 + 0x88));
                    uVar6 = uVar6 + 1;
                    puVar9 = puVar10 + 0xc;
                    for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
                      *puVar10 = *puVar9;
                      puVar9 = puVar9 + 1;
                      puVar10 = puVar10 + 1;
                    }
                  } while (uVar6 < iVar8 - 1U);
                }
                *(undefined4 *)
                 ((*(int *)(param_1 + 0x5c) * uVar7 + uVar6) * 0x30 + 0x20 +
                 *(int *)(param_1 + 0x88)) = uVar1;
                iVar4 = *(int *)(param_1 + 0x74) + uVar7;
                iVar5 = *(int *)(param_1 + 0x6c);
                if (iVar4 < 0) {
                  if (iVar5 < 2) {
                    iVar4 = 0;
                  }
                  else {
                    iVar4 = iVar5 - -iVar4 % iVar5;
                  }
                }
                else {
                  iVar4 = iVar4 % iVar5;
                }
                (**(code **)(**(int **)(param_1 + 0x58) + 0x4c))(param_1,uVar3,iVar4);
                uVar7 = uVar7 + 1;
              } while (uVar7 < *(uint *)(param_1 + 0x60));
              return 1;
            }
          }
        }
        else {
          uVar7 = 0;
          if (*(int *)(param_1 + 0x60) != 0) {
            do {
              uVar1 = *(undefined4 *)
                       (*(int *)(param_1 + 0x5c) * uVar7 * 0x30 + 0x20 + *(int *)(param_1 + 0x88));
              uVar6 = 0;
              if (iVar8 != 1) {
                do {
                  puVar10 = (undefined4 *)
                            ((*(int *)(param_1 + 0x5c) * uVar7 + uVar6) * 0x30 +
                            *(int *)(param_1 + 0x88));
                  uVar6 = uVar6 + 1;
                  puVar9 = puVar10 + 0xc;
                  for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
                    *puVar10 = *puVar9;
                    puVar9 = puVar9 + 1;
                    puVar10 = puVar10 + 1;
                  }
                } while (uVar6 < iVar8 - 1U);
              }
              *(undefined4 *)
               ((*(int *)(param_1 + 0x5c) * uVar7 + uVar6) * 0x30 + 0x20 + *(int *)(param_1 + 0x88))
                   = uVar1;
              iVar4 = *(int *)(param_1 + 0x74) + uVar7;
              iVar5 = *(int *)(param_1 + 0x6c);
              if (iVar4 < 0) {
                if (iVar5 < 2) {
                  iVar4 = 0;
                }
                else {
                  iVar4 = iVar5 - -iVar4 % iVar5;
                }
              }
              else {
                iVar4 = iVar4 % iVar5;
              }
              (**(code **)(param_1 + 0xbc))(*(undefined4 *)(param_1 + 0xc0),param_1,uVar3,iVar4);
              uVar7 = uVar7 + 1;
            } while (uVar7 < *(uint *)(param_1 + 0x60));
            return 1;
          }
        }
      }
    }
    return 1;
  }
  return 0;
}


// ==== 0x4fb9e0 FECodeListBox::SetCellColor

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void FECodeListBox__SetCellColor
               (uint param_1,uint param_2,undefined4 param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar2 = param_5 + param_2;
  for (; uVar1 = param_1, param_2 < uVar2; param_2 = param_2 + 1) {
    for (; uVar1 < param_4 + param_1; uVar1 = uVar1 + 1) {
      puVar3 = (undefined4 *)FEGrid_GetCell(param_2);
      *puVar3 = param_3;
    }
  }
  return;
}


// ==== 0x4fba30 FECodeListBox::SetCellScale

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void FECodeListBox__SetCellScale
               (uint param_1,uint param_2,undefined4 *param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = param_5 + param_2;
  for (; uVar1 = param_1, param_2 < uVar2; param_2 = param_2 + 1) {
    for (; uVar1 < param_4 + param_1; uVar1 = uVar1 + 1) {
      iVar3 = FEGrid_GetCell(param_2);
      *(undefined4 *)(iVar3 + 4) = *param_3;
      *(undefined4 *)(iVar3 + 8) = param_3[1];
    }
  }
  return;
}


// ==== 0x4fbaa0 FECodeListBox::SetCellJustification

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void FECodeListBox__SetCellJustification
               (uint param_1,uint param_2,undefined4 param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = param_5 + param_2;
  for (; uVar1 = param_1, param_2 < uVar2; param_2 = param_2 + 1) {
    for (; uVar1 < param_4 + param_1; uVar1 = uVar1 + 1) {
      iVar3 = FEGrid_GetCell(param_2);
      *(undefined4 *)(iVar3 + 0x1c) = param_3;
    }
  }
  return;
}


// ==== 0x4fbaf0 FEListEntryArray::SetCount

/* [canon] hud med (ghidra-canon+hopper) docs/re/hud.md */

void FEListEntryArray__SetCount(int *param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_2 != *param_1) {
    if (param_2 == 0) {
      if ((void *)param_1[1] != (void *)0x0) {
        _free((void *)param_1[1]);
      }
      param_1[1] = 0;
      *param_1 = 0;
      return;
    }
    puVar1 = _malloc(param_2 * 0xc);
    if (param_2 < *param_1) {
      puVar4 = (undefined4 *)param_1[1];
      puVar5 = puVar1;
      for (uVar2 = param_2 * 3 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
    }
    else {
      puVar4 = (undefined4 *)param_1[1];
      puVar5 = puVar1;
      for (uVar2 = *param_1 * 3 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
      puVar4 = puVar1 + *param_1 * 3;
      for (uVar2 = (param_2 - *param_1) * 3 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar4 = 0;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
    }
    _free((void *)param_1[1]);
    param_1[1] = (int)puVar1;
    *param_1 = param_2;
  }
  return;
}


// ==== 0x4fbbc0 FUN_004fbbc0

undefined4 FUN_004fbbc0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x68);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_004fbd00(pvVar1,1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4fbc30 FEGroup::AddChild

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void __fastcall FEGroup__AddChild(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  
  iVar1 = *(int *)(param_2 + 100);
  if (in_EAX != 0) {
    if (iVar1 == 0) {
      iVar2 = *(int *)(param_2 + 0x60);
      *(int *)(in_EAX + 4) = iVar2;
      if (iVar2 != 0) {
        *(int *)(iVar2 + 8) = in_EAX;
      }
      *(undefined4 *)(in_EAX + 8) = 0;
      *(int *)(param_2 + 0x60) = in_EAX;
    }
    else {
      iVar2 = *(int *)(iVar1 + 4);
      *(int *)(in_EAX + 4) = iVar2;
      if (iVar2 != 0) {
        *(int *)(iVar2 + 8) = in_EAX;
      }
      *(int *)(in_EAX + 8) = iVar1;
      *(int *)(iVar1 + 4) = in_EAX;
    }
    if (*(int *)(param_2 + 100) == iVar1) {
      *(int *)(param_2 + 100) = in_EAX;
    }
    *(int *)(param_2 + 0x5c) = *(int *)(param_2 + 0x5c) + 1;
  }
  return;
}


// ==== 0x4fbc80 FUN_004fbc80

void * __thiscall FUN_004fbc80(void *param_1,byte param_2)

{
  FUN_004fbca0(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4fbca0 FUN_004fbca0

void FUN_004fbca0(int param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685458;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *(undefined ***)(param_1 + 0x58) = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  local_4 = 0xffffffff;
  FUN_004fef10();
  ExceptionList = local_c;
  return;
}


// ==== 0x4fbd00 FUN_004fbd00

undefined4 * __thiscall
FUN_004fbd00(int param_1,undefined4 *param_2,char param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685ad3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004fec30(param_2,param_1,param_4);
  *param_2 = &PTR_FUN_006c1834;
  param_2[0x16] = &PTR_FUN_006c2c4c;
  param_2[0x18] = 0;
  param_2[0x19] = 0;
  param_2[0x17] = 0;
  local_4 = 1;
  if (param_3 != '\0') {
    for (piVar1 = *(int **)(param_1 + 0x60); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
      iVar4 = (**(code **)(*piVar1 + 4))(param_4);
      iVar2 = param_2[0x19];
      if (iVar4 != 0) {
        if (iVar2 == 0) {
          iVar3 = param_2[0x18];
          *(int *)(iVar4 + 4) = iVar3;
          if (iVar3 != 0) {
            *(int *)(iVar3 + 8) = iVar4;
          }
          *(undefined4 *)(iVar4 + 8) = 0;
          param_2[0x18] = iVar4;
        }
        else {
          iVar3 = *(int *)(iVar2 + 4);
          *(int *)(iVar4 + 4) = iVar3;
          if (iVar3 != 0) {
            *(int *)(iVar3 + 8) = iVar4;
          }
          *(int *)(iVar4 + 8) = iVar2;
          *(int *)(iVar2 + 4) = iVar4;
        }
        if (param_2[0x19] == iVar2) {
          param_2[0x19] = iVar4;
        }
        param_2[0x17] = param_2[0x17] + 1;
      }
    }
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== 0x4fbdd0 FEJoyPad::FEJoyPad

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

undefined4 * __fastcall FEJoyPad__FEJoyPad(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_1[1] = 0;
  *param_1 = 0;
  puVar2 = param_1 + 2;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}


// ==== 0x4fbdf0 FUN_004fbdf0

void __fastcall FUN_004fbdf0(uint param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int unaff_EDI;
  
  uVar1 = param_2[1];
  param_2[1] = param_1;
  *param_2 = uVar1;
  iVar2 = 0;
  puVar3 = param_2 + 2;
  do {
    uVar1 = 1 << ((byte)iVar2 & 0x1f);
    if ((param_2[1] & uVar1) != 0) {
      if ((*param_2 & uVar1) == 0) {
        *puVar3 = 0;
      }
      else {
        *puVar3 = *puVar3 + unaff_EDI;
      }
    }
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar2 < 0x20);
  return;
}


// ==== 0x4fbe30 FUN_004fbe30

void __fastcall FUN_004fbe30(int param_1)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint unaff_EDI;
  
  uVar3 = 0xffffffff;
  puVar5 = (uint *)(param_1 + 0xc);
  iVar4 = 2;
  do {
    bVar2 = (byte)iVar4;
    if (((unaff_EDI & 1 << (bVar2 - 2 & 0x1f)) != 0) && (puVar5[-1] <= uVar3)) {
      uVar3 = puVar5[-1];
    }
    if (((unaff_EDI & 1 << (bVar2 - 1 & 0x1f)) != 0) && (*puVar5 <= uVar3)) {
      uVar3 = *puVar5;
    }
    if (((unaff_EDI & 1 << (bVar2 & 0x1f)) != 0) && (puVar5[1] <= uVar3)) {
      uVar3 = puVar5[1];
    }
    if (((unaff_EDI & 1 << (bVar2 + 1 & 0x1f)) != 0) && (puVar5[2] <= uVar3)) {
      uVar3 = puVar5[2];
    }
    if (((unaff_EDI & 1 << (bVar2 + 2 & 0x1f)) != 0) && (puVar5[3] <= uVar3)) {
      uVar3 = puVar5[3];
    }
    if (((unaff_EDI & 1 << (bVar2 + 3 & 0x1f)) != 0) && (puVar5[4] <= uVar3)) {
      uVar3 = puVar5[4];
    }
    if (((unaff_EDI & 1 << (bVar2 + 4 & 0x1f)) != 0) && (puVar5[5] <= uVar3)) {
      uVar3 = puVar5[5];
    }
    if (((unaff_EDI & 1 << (bVar2 + 5 & 0x1f)) != 0) && (puVar5[6] <= uVar3)) {
      uVar3 = puVar5[6];
    }
    iVar1 = iVar4 + 6;
    puVar5 = puVar5 + 8;
    iVar4 = iVar4 + 8;
  } while (iVar1 < 0x20);
  return;
}


// ==== 0x4fbf10 FUN_004fbf10

void __fastcall FUN_004fbf10(int param_1)

{
  char cVar1;
  uint in_EAX;
  int iVar2;
  
  iVar2 = (in_EAX & 0xff) * 0x38 + *(int *)(param_1 + 0x20);
  cVar1 = *(char *)(iVar2 + 2);
  if (cVar1 == '\0') {
    FUN_004fc9a0();
  }
  else if ((cVar1 == '\x01') || (cVar1 == '\x03')) {
    FUN_004fc100(iVar2);
    return;
  }
  return;
}


// ==== 0x4fbf60 FUN_004fbf60

void __fastcall FUN_004fbf60(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int unaff_ESI;
  int iVar3;
  
  if (-1 < *(char *)(unaff_ESI + 3)) {
    cVar1 = *(char *)(unaff_ESI + 2);
    if (cVar1 == '\0') {
      FUN_004fc9a0(param_2,param_1);
    }
    else if ((cVar1 == '\x01') || (cVar1 == '\x03')) {
      FUN_004fc100();
    }
    iVar3 = 0;
    iVar2 = *(int *)(unaff_ESI + 0x30);
    if (*(char *)(unaff_ESI + 0x2c) != '\0') {
      iVar2 = FUN_004fc0e0();
    }
    if (iVar2 != 0) {
      do {
        iVar2 = *(int *)(iVar2 + 4);
        iVar3 = iVar3 + 1;
      } while (iVar2 != 0);
      if (iVar3 != 0) {
        return;
      }
    }
    *(byte *)(unaff_ESI + 3) = *(byte *)(unaff_ESI + 3) | 0x80;
  }
  return;
}


// ==== 0x4fbfc0 FEQuaternion_Multiply

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void __fastcall FEQuaternion_Multiply(float *param_1,float *param_2)

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
  float *in_EAX;
  
  fVar1 = *param_1;
  fVar2 = param_2[2];
  fVar3 = *param_2;
  fVar4 = param_1[2];
  fVar5 = param_1[1];
  fVar6 = *param_2;
  fVar7 = param_2[1];
  fVar8 = *param_1;
  fVar9 = param_1[3];
  fVar10 = param_2[1];
  fVar11 = param_1[1];
  fVar12 = param_2[3];
  fVar13 = param_2[3];
  fVar14 = param_1[2];
  fVar15 = param_1[3];
  fVar16 = param_2[2];
  fVar17 = param_1[3];
  fVar18 = param_2[3];
  fVar19 = *param_1;
  fVar20 = *param_2;
  fVar21 = param_1[1];
  fVar22 = param_2[1];
  fVar23 = param_1[2];
  fVar24 = param_2[2];
  *in_EAX = param_1[3] * *param_2 + param_2[3] * *param_1 +
            (param_2[1] * param_1[2] - param_1[1] * param_2[2]);
  in_EAX[1] = fVar11 * fVar12 + fVar9 * fVar10 + (fVar1 * fVar2 - fVar3 * fVar4);
  in_EAX[2] = fVar15 * fVar16 + fVar13 * fVar14 + (fVar5 * fVar6 - fVar7 * fVar8);
  in_EAX[3] = fVar17 * fVar18 - (fVar23 * fVar24 + fVar21 * fVar22 + fVar19 * fVar20);
  return;
}


// ==== 0x4fc070 FUN_004fc070

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004fc070(float *param_1)

{
  float fVar1;
  
  fVar1 = _K_ONE / SQRT(param_1[3] * param_1[3] +
                        param_1[2] * param_1[2] + param_1[1] * param_1[1] + *param_1 * *param_1);
  if (_K_EPS_SPEED < fVar1) {
    *param_1 = fVar1 * *param_1;
    param_1[1] = fVar1 * param_1[1];
    param_1[2] = fVar1 * param_1[2];
    param_1[3] = fVar1 * param_1[3];
    return;
  }
  param_1[2] = 0.0;
  param_1[1] = 0.0;
  *param_1 = 0.0;
  param_1[3] = 1.0;
  return;
}


// ==== 0x4fc0e0 FUN_004fc0e0

undefined4 FUN_004fc0e0(void)

{
  char cVar1;
  int in_EAX;
  
  cVar1 = *(char *)(in_EAX + 4);
  while (cVar1 != '\0') {
    in_EAX = *(int *)(in_EAX + 8);
    cVar1 = *(char *)(in_EAX + 4);
  }
  return *(undefined4 *)(in_EAX + 8);
}


// ==== 0x4fc100 FUN_004fc100

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004fc100(undefined1 *param_1,int param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  byte bVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  float local_20;
  int local_1c;
  
  iVar8 = 0;
  pfVar6 = (float *)(param_1 + 0x18);
  iVar5 = *(int *)(param_1 + 0x30);
  local_20 = 0.0;
  local_1c = 0;
  if (param_1[0x2c] != '\0') {
    iVar5 = FUN_004fc0e0();
  }
  if (iVar5 == 0) goto LAB_004fc29b;
  do {
    iVar5 = *(int *)(iVar5 + 4);
    iVar8 = iVar8 + 1;
  } while (iVar5 != 0);
  if (iVar8 == 0) goto LAB_004fc29b;
  bVar4 = param_1[3] & 0x7f;
  if ((param_1[3] & 0x7f) == 0) {
    iVar5 = FUN_004fccb0();
    if (iVar5 == 0) goto LAB_004fc29b;
    local_1c = *(int *)(iVar5 + 8);
    if (local_1c == 0) {
      local_20 = 1.0;
    }
    else if (param_2 < *(int *)(iVar5 + 0xc)) {
      local_20 = (float)(*(int *)(iVar5 + 0xc) - *(int *)(local_1c + 0xc));
      if (local_20 <= _K_EPS_SPEED) goto LAB_004fc285;
      local_20 = (float)(param_2 - *(int *)(local_1c + 0xc)) / local_20;
    }
    else {
      local_20 = 1.0;
    }
  }
  else if (bVar4 == 1) {
    local_1c = FUN_004fccb0();
    if (local_1c == 0) goto LAB_004fc29b;
    iVar8 = *(int *)(local_1c + 0xc);
    if (iVar8 < param_2) {
      iVar5 = *(int *)(param_1 + 0x30);
      if (param_1[0x2c] != '\0') {
        iVar5 = FUN_004fc0e0();
      }
      local_20 = (float)((((*(int *)(param_1 + 4) << 8) >> 8) + *(int *)(iVar5 + 0xc)) -
                        *(int *)(local_1c + 0xc));
      if (local_20 <= _K_EPS_SPEED) goto LAB_004fc285;
      local_20 = (float)(param_2 - *(int *)(local_1c + 0xc)) / local_20;
    }
    else {
      iVar5 = local_1c;
      if (iVar8 == param_2) {
        local_20 = 0.0;
      }
      else {
        local_1c = *(int *)(local_1c + 8);
        if (local_1c == 0) {
          iVar9 = *(int *)(param_1 + 4);
          local_1c = FUN_004fcc70();
          iVar9 = ((iVar9 << 8) >> 8) - *(int *)(local_1c + 0xc);
          local_20 = (float)(iVar9 + iVar8);
          if (local_20 <= _K_EPS_SPEED) {
LAB_004fc285:
            local_20 = 0.0;
          }
          else {
            local_20 = (float)(iVar9 + param_2) / local_20;
          }
        }
        else {
          local_20 = (float)(iVar8 - *(int *)(local_1c + 0xc));
          if (local_20 <= _K_EPS_SPEED) goto LAB_004fc285;
          local_20 = (float)(param_2 - *(int *)(local_1c + 0xc)) / local_20;
        }
      }
    }
  }
  else {
    if (bVar4 != 2) goto LAB_004fc29b;
    iVar5 = FUN_004fccb0();
  }
  if (iVar5 != 0) {
    iVar8 = local_1c;
    if ((local_20 != 0.0) && (iVar8 = iVar5, local_20 != _K_ONE)) {
      switch(*param_1) {
      case 1:
        FUN_004fc5d0(local_20,pfVar6,param_3);
        return;
      case 2:
        *param_3 = (*(float *)(iVar5 + 0x10) - *(float *)(local_1c + 0x10)) * local_20 +
                   *(float *)(local_1c + 0x10) + *pfVar6;
        return;
      case 3:
        *param_3 = (*(float *)(iVar5 + 0x10) - *(float *)(local_1c + 0x10)) * local_20 + *pfVar6 +
                   *(float *)(local_1c + 0x10);
        param_3[1] = (*(float *)(iVar5 + 0x14) - *(float *)(local_1c + 0x14)) * local_20 +
                     *(float *)(param_1 + 0x1c) + *(float *)(local_1c + 0x14);
        return;
      case 4:
        FUN_004fc600(local_20);
        return;
      case 5:
        FUN_004fc640(local_20,pfVar6);
        return;
      case 6:
        FUN_004fc8e0(local_1c + 0x10,iVar5 + 0x10,local_20);
        return;
      default:
        return;
      }
    }
    pfVar7 = (float *)(iVar8 + 0x10);
    switch(*param_1) {
    case 1:
      *param_3 = (float)((int)*pfVar6 + (int)*pfVar7);
      return;
    case 2:
      *param_3 = *pfVar6 + *pfVar7;
      return;
    case 3:
      *param_3 = *pfVar6 + *pfVar7;
      param_3[1] = *(float *)(iVar8 + 0x14) + *(float *)(param_1 + 0x1c);
      return;
    case 4:
      *param_3 = *pfVar6 + *pfVar7;
      param_3[1] = *(float *)(iVar8 + 0x14) + *(float *)(param_1 + 0x1c);
      param_3[2] = *(float *)(iVar8 + 0x18) + *(float *)(param_1 + 0x20);
      return;
    case 5:
      pfVar6 = (float *)FEQuaternion_Multiply();
      *param_3 = *pfVar6;
      param_3[1] = pfVar6[1];
      param_3[2] = pfVar6[2];
      param_3[3] = pfVar6[3];
      return;
    case 6:
      param_3[2] = (float)(*(int *)(iVar8 + 0x18) + *(int *)(param_1 + 0x20));
      param_3[1] = (float)(*(int *)(iVar8 + 0x14) + *(int *)(param_1 + 0x1c));
      *param_3 = (float)((int)*pfVar6 + (int)*pfVar7);
      param_3[3] = (float)(*(int *)(iVar8 + 0x1c) + *(int *)(param_1 + 0x24));
      return;
    default:
      return;
    }
  }
LAB_004fc29b:
  switch(*param_1) {
  case 1:
  case 2:
    *param_3 = *pfVar6;
    return;
  case 3:
    fVar1 = *(float *)(param_1 + 0x1c);
    *param_3 = *pfVar6;
    param_3[1] = fVar1;
    return;
  case 4:
    fVar1 = *(float *)(param_1 + 0x1c);
    fVar2 = *(float *)(param_1 + 0x20);
    *param_3 = *pfVar6;
    param_3[1] = fVar1;
    param_3[2] = fVar2;
    return;
  case 5:
  case 6:
    fVar1 = *(float *)(param_1 + 0x1c);
    fVar2 = *(float *)(param_1 + 0x20);
    fVar3 = *(float *)(param_1 + 0x24);
    *param_3 = *pfVar6;
    param_3[1] = fVar1;
    param_3[2] = fVar2;
    param_3[3] = fVar3;
    return;
  default:
    return;
  }
}


// ==== 0x4fc5d0 FUN_004fc5d0

void FUN_004fc5d0(undefined4 param_1,int *param_2,int *param_3)

{
  int in_EAX;
  int iVar1;
  int unaff_ESI;
  
  iVar1 = _ftol_nocw(in_EAX - unaff_ESI);
  *param_3 = iVar1 + *param_2 + unaff_ESI;
  return;
}


// ==== 0x4fc600 FUN_004fc600

void __fastcall FUN_004fc600(float *param_1,float *param_2,float param_3)

{
  float *in_EAX;
  float *unaff_ESI;
  
  *param_1 = (*unaff_ESI - *in_EAX) * param_3 + *in_EAX + *param_2;
  param_1[1] = (unaff_ESI[1] - in_EAX[1]) * param_3 + param_2[1] + in_EAX[1];
  param_1[2] = (unaff_ESI[2] - in_EAX[2]) * param_3 + param_2[2] + in_EAX[2];
  return;
}


// ==== 0x4fc640 FUN_004fc640

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004fc640(float *param_1)

{
  short sVar1;
  undefined4 *puVar2;
  float *unaff_ESI;
  undefined4 *unaff_EDI;
  float10 fVar3;
  float fVar4;
  
  fVar4 = param_1[1] * unaff_ESI[1] +
          param_1[3] * unaff_ESI[3] + param_1[2] * unaff_ESI[2] + *param_1 * *unaff_ESI;
  if (fVar4 < 0.0) {
    fVar4 = -fVar4;
  }
  if (0.999 <= fVar4) {
    FUN_004fc070();
  }
  else {
    sVar1 = FUN_00564cd0(fVar4);
    fVar4 = (float)(ushort)(0x4000 - sVar1) * 9.58738e-05;
    _ftol_nocw();
    fVar3 = (float10)FUN_00564b10();
    _ftol_nocw((float)fVar3,fVar4);
    FUN_00564b10();
    _ftol_nocw();
    FUN_00564b10();
  }
  puVar2 = (undefined4 *)FEQuaternion_Multiply();
  *unaff_EDI = *puVar2;
  unaff_EDI[1] = puVar2[1];
  unaff_EDI[2] = puVar2[2];
  unaff_EDI[3] = puVar2[3];
  return;
}


// ==== 0x4fc8e0 FUN_004fc8e0

void FUN_004fc8e0(int *param_1)

{
  int iVar1;
  int iVar2;
  int *unaff_ESI;
  int *unaff_EDI;
  
  iVar1 = _ftol_nocw();
  *unaff_ESI = iVar1 + *unaff_EDI + *param_1;
  iVar1 = _ftol_nocw();
  unaff_ESI[1] = iVar1 + unaff_EDI[1] + param_1[1];
  iVar1 = _ftol_nocw();
  unaff_ESI[2] = iVar1 + unaff_EDI[2] + param_1[2];
  iVar1 = param_1[3];
  iVar2 = _ftol_nocw();
  unaff_ESI[3] = iVar2 + unaff_EDI[3] + iVar1;
  return;
}


// ==== 0x4fc9a0 FUN_004fc9a0

void FUN_004fc9a0(int param_1,undefined4 *param_2)

{
  byte bVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  bVar1 = *(byte *)(in_EAX + 1);
  if ((*(int *)(in_EAX + 4) << 8) >> 8 < param_1) {
    iVar2 = FUN_004fcc70();
    iVar4 = *(int *)(iVar2 + 4);
    if ((iVar4 == 0) || (param_1 <= *(int *)(iVar2 + 0xc))) goto LAB_004fca01;
  }
  else {
    iVar2 = FUN_004fcc70();
    iVar4 = *(int *)(iVar2 + 8);
    if ((iVar4 == 0) || (*(int *)(iVar2 + 0xc) <= param_1)) {
LAB_004fca01:
      puVar5 = (undefined4 *)(iVar2 + 0x10);
      for (uVar3 = (uint)(bVar1 >> 2); uVar3 != 0; uVar3 = uVar3 - 1) {
        *param_2 = *puVar5;
        puVar5 = puVar5 + 1;
        param_2 = param_2 + 1;
      }
      for (uVar3 = bVar1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)param_2 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        param_2 = (undefined4 *)((int)param_2 + 1);
      }
      return;
    }
  }
  puVar5 = (undefined4 *)(iVar4 + 0x10);
  for (uVar3 = (uint)(bVar1 >> 2); uVar3 != 0; uVar3 = uVar3 - 1) {
    *param_2 = *puVar5;
    puVar5 = puVar5 + 1;
    param_2 = param_2 + 1;
  }
  for (uVar3 = bVar1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)param_2 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  return;
}


// ==== 0x4fca20 FUN_004fca20

void FUN_004fca20(void)

{
  undefined4 *puVar1;
  int unaff_EDI;
  
  puVar1 = *(undefined4 **)(unaff_EDI + 8);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00514300();
    do {
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      puVar1 = *(undefined4 **)(unaff_EDI + 8);
      if (puVar1 != (undefined4 *)0x0) {
        *(undefined4 *)(unaff_EDI + 8) = puVar1[1];
        if (puVar1 == *(undefined4 **)(unaff_EDI + 0xc)) {
          *(undefined4 *)(unaff_EDI + 0xc) = puVar1[2];
        }
        if (puVar1[2] != 0) {
          *(undefined4 *)(puVar1[2] + 4) = puVar1[1];
        }
        if (puVar1[1] != 0) {
          *(undefined4 *)(puVar1[1] + 8) = puVar1[2];
        }
        puVar1[1] = 0xabadcafe;
        puVar1[2] = 0xabadcafe;
      }
    } while (puVar1 != (undefined4 *)0x0);
  }
  return;
}


// ==== 0x4fca90 FEKeyNode::FEKeyNode

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void __fastcall FEKeyNode__FEKeyNode(undefined4 *param_1)

{
  param_1[1] = 0xabadcafe;
  param_1[2] = 0xabadcafe;
  *param_1 = &PTR_FUN_006c1830;
  return;
}


// ==== 0x4fcab0 FUN_004fcab0

void __fastcall FUN_004fcab0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c2c50;
  return;
}


// ==== 0x4fcac0 FUN_004fcac0

undefined4 * __thiscall FUN_004fcac0(undefined4 *param_1,byte param_2)

{
  FUN_004fcab0();
  if ((param_2 & 1) != 0) {
    (**(code **)*param_1)(0);
    FUN_004fcda0();
  }
  return param_1;
}


// ==== 0x4fcaf0 FUN_004fcaf0

void FUN_004fcaf0(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006c2c4c;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  in_EAX[1] = 0;
  return;
}


// ==== 0x4fcb10 FUN_004fcb10

void FUN_004fcb10(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  return;
}


// ==== 0x4fcb20 FUN_004fcb20

/* WARNING: Removing unreachable block (ram,0x004fcbcf) */

void FUN_004fcb20(undefined1 *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 *in_EAX;
  undefined4 *puVar3;
  int iVar4;
  
  FUN_004fca20();
  *param_1 = *in_EAX;
  param_1[1] = in_EAX[1];
  param_1[2] = in_EAX[2];
  param_1[3] = in_EAX[3];
  *(uint *)(param_1 + 4) =
       *(uint *)(param_1 + 4) ^
       ((*(int *)(in_EAX + 4) << 8) >> 8 ^ *(uint *)(param_1 + 4)) & 0xffffff;
  param_1[7] = in_EAX[7];
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(in_EAX + 0x14);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(in_EAX + 0x18);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(in_EAX + 0x1c);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(in_EAX + 0x20);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(in_EAX + 0x24);
  if (in_EAX[0x2c] == '\0') {
    for (iVar4 = *(int *)(in_EAX + 0x30); iVar4 != 0; iVar4 = *(int *)(iVar4 + 4)) {
      puVar3 = (undefined4 *)FUN_004fccf0();
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3[1] = 0xabadcafe;
        puVar3[2] = 0xabadcafe;
        *puVar3 = &PTR_FUN_006c1830;
      }
      puVar3[3] = *(undefined4 *)(iVar4 + 0xc);
      puVar3[4] = *(undefined4 *)(iVar4 + 0x10);
      puVar3[5] = *(undefined4 *)(iVar4 + 0x14);
      puVar3[6] = *(undefined4 *)(iVar4 + 0x18);
      puVar3[7] = *(undefined4 *)(iVar4 + 0x1c);
      iVar1 = *(int *)(param_1 + 0x34);
      if (iVar1 == 0) {
        iVar2 = *(int *)(param_1 + 0x30);
        puVar3[1] = iVar2;
        if (iVar2 != 0) {
          *(undefined4 **)(iVar2 + 8) = puVar3;
        }
        puVar3[2] = 0;
        *(undefined4 **)(param_1 + 0x30) = puVar3;
      }
      else {
        iVar2 = *(int *)(iVar1 + 4);
        puVar3[1] = iVar2;
        if (iVar2 != 0) {
          *(undefined4 **)(iVar2 + 8) = puVar3;
        }
        puVar3[2] = iVar1;
        *(undefined4 **)(iVar1 + 4) = puVar3;
      }
      if (*(int *)(param_1 + 0x34) == iVar1) {
        *(undefined4 **)(param_1 + 0x34) = puVar3;
      }
    }
    return;
  }
  if (in_EAX[0x2c] == '\0') {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(in_EAX + 0x30);
  }
  if (iVar4 == 0) {
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    param_1[0x2c] = 0;
    return;
  }
  if (param_1[0x2c] == '\0') {
    FUN_004fca20();
  }
  *(int *)(param_1 + 0x30) = iVar4;
  param_1[0x2c] = 1;
  return;
}


// ==== 0x4fcc70 FUN_004fcc70

int FUN_004fcc70(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  if (-1 < unaff_EDI) {
    iVar2 = *(int *)(unaff_ESI + 0x30);
    if (*(char *)(unaff_ESI + 0x2c) != '\0') {
      iVar2 = FUN_004fc0e0();
    }
    if (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 4);
      while ((iVar1 != 0 && (*(int *)(iVar2 + 0xc) < unaff_EDI))) {
        iVar2 = *(int *)(iVar2 + 4);
        iVar1 = *(int *)(iVar2 + 4);
      }
      return iVar2;
    }
  }
  return unaff_ESI + 8;
}


// ==== 0x4fccb0 FUN_004fccb0

void FUN_004fccb0(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int unaff_ESI;
  
  iVar2 = *(int *)(in_EAX + 0x30);
  if (*(char *)(in_EAX + 0x2c) != '\0') {
    iVar2 = FUN_004fc0e0();
  }
  if (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 4);
    while ((iVar1 != 0 && (*(int *)(iVar2 + 0xc) < unaff_ESI))) {
      iVar2 = *(int *)(iVar2 + 4);
      iVar1 = *(int *)(iVar2 + 4);
    }
    return;
  }
  return;
}


// ==== 0x4fccf0 FUN_004fccf0

void FUN_004fccf0(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int unaff_EDI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  local_c = ExceptionList;
  for (iVar3 = *(int *)(unaff_EDI + 8); iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
    ExceptionList = &local_c;
    if (*(int *)(iVar3 + 0x2010) != 0) goto LAB_004fcd72;
  }
  ExceptionList = &local_c;
  pvVar2 = _malloc(0x2020);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FEKeyNode__StaticPoolInit(pvVar2);
  }
  if (iVar3 != 0) {
    iVar1 = *(int *)(unaff_EDI + 8);
    *(int *)(iVar3 + 4) = iVar1;
    if (iVar1 != 0) {
      *(int *)(iVar1 + 8) = iVar3;
    }
    *(undefined4 *)(iVar3 + 8) = 0;
    *(int *)(unaff_EDI + 8) = iVar3;
    if (*(int *)(unaff_EDI + 0xc) == 0) {
      *(int *)(unaff_EDI + 0xc) = iVar3;
    }
    *(int *)(unaff_EDI + 4) = *(int *)(unaff_EDI + 4) + 1;
  }
LAB_004fcd72:
  if (*(int *)(iVar3 + 0x2014) != 0) {
    FUN_004ee670();
  }
  *(int *)(iVar3 + 0x201c) = *(int *)(iVar3 + 0x201c) + 1;
  ExceptionList = local_c;
  return;
}


// ==== 0x4fcda0 FUN_004fcda0

void FUN_004fcda0(void)

{
  int *piVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  int unaff_EDI;
  
  puVar2 = *(undefined4 **)(unaff_EDI + 8);
  if (puVar2 != (undefined4 *)0x0) {
    while ((in_EAX < puVar2 + 3 || (puVar2 + 0x803 <= in_EAX))) {
      puVar2 = (undefined4 *)puVar2[1];
      if (puVar2 == (undefined4 *)0x0) {
        return;
      }
    }
    FUN_004ee590();
    piVar1 = puVar2 + 0x807;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      FUN_004ee670();
      (**(code **)*puVar2)(1);
    }
  }
  return;
}


// ==== 0x4fcdf0 FEKeyNode::StaticPoolInit

/* [canon] hud med (ghidra-canon+hopper) docs/re/hud.md */

undefined4 * FEKeyNode__StaticPoolInit(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684ef8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[1] = 0xabadcafe;
  param_1[2] = 0xabadcafe;
  local_4 = 0;
  *param_1 = &PTR_FUN_006c182c;
  eh_vector_constructor_iterator(param_1 + 3,0x20,0x100,FEKeyNode__FEKeyNode,FUN_004fcab0);
  param_1[0x803] = &PTR_FUN_006c2c4c;
  param_1[0x805] = 0;
  param_1[0x806] = 0;
  param_1[0x804] = 0;
  param_1[0x807] = 0;
  piVar4 = param_1 + 5;
  iVar5 = 0x40;
  do {
    iVar2 = param_1[0x806];
    if (piVar4 != (int *)0x8) {
      if (iVar2 == 0) {
        iVar3 = param_1[0x805];
        piVar4[-1] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar4 + -2;
        }
        *piVar4 = 0;
        param_1[0x805] = piVar4 + -2;
      }
      else {
        iVar3 = *(int *)(iVar2 + 4);
        piVar4[-1] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar4 + -2;
        }
        *piVar4 = iVar2;
        *(int **)(iVar2 + 4) = piVar4 + -2;
      }
      if (param_1[0x806] == iVar2) {
        param_1[0x806] = piVar4 + -2;
      }
      param_1[0x804] = param_1[0x804] + 1;
    }
    iVar2 = param_1[0x806];
    piVar1 = piVar4 + 6;
    if (piVar1 != (int *)0x0) {
      if (iVar2 == 0) {
        iVar3 = param_1[0x805];
        piVar4[7] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar1;
        }
        piVar4[8] = 0;
        param_1[0x805] = piVar1;
      }
      else {
        iVar3 = *(int *)(iVar2 + 4);
        piVar4[7] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar1;
        }
        piVar4[8] = iVar2;
        *(int **)(iVar2 + 4) = piVar1;
      }
      if (param_1[0x806] == iVar2) {
        param_1[0x806] = piVar1;
      }
      param_1[0x804] = param_1[0x804] + 1;
    }
    iVar2 = param_1[0x806];
    piVar1 = piVar4 + 0xe;
    if (piVar1 != (int *)0x0) {
      if (iVar2 == 0) {
        iVar3 = param_1[0x805];
        piVar4[0xf] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar1;
        }
        piVar4[0x10] = 0;
        param_1[0x805] = piVar1;
      }
      else {
        iVar3 = *(int *)(iVar2 + 4);
        piVar4[0xf] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar1;
        }
        piVar4[0x10] = iVar2;
        *(int **)(iVar2 + 4) = piVar1;
      }
      if (param_1[0x806] == iVar2) {
        param_1[0x806] = piVar1;
      }
      param_1[0x804] = param_1[0x804] + 1;
    }
    iVar2 = param_1[0x806];
    piVar1 = piVar4 + 0x16;
    if (piVar1 != (int *)0x0) {
      if (iVar2 == 0) {
        iVar3 = param_1[0x805];
        piVar4[0x17] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar1;
        }
        piVar4[0x18] = 0;
        param_1[0x805] = piVar1;
      }
      else {
        iVar3 = *(int *)(iVar2 + 4);
        piVar4[0x17] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar1;
        }
        piVar4[0x18] = iVar2;
        *(int **)(iVar2 + 4) = piVar1;
      }
      if (param_1[0x806] == iVar2) {
        param_1[0x806] = piVar1;
      }
      param_1[0x804] = param_1[0x804] + 1;
    }
    piVar4 = piVar4 + 0x20;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4fcff0 FUN_004fcff0

void FUN_004fcff0(undefined4 *param_1)

{
  int iVar1;
  void *local_c;
  code *pcStack_8;
  uint local_4;
  
  pcStack_8 = FUN_00684f51;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c182c;
  iVar1 = param_1[0x804];
  local_4 = 1;
  while (iVar1 != 0) {
    iVar1 = param_1[0x805];
    if (iVar1 != 0) {
      param_1[0x805] = *(undefined4 *)(iVar1 + 4);
      if (iVar1 == param_1[0x806]) {
        param_1[0x806] = *(undefined4 *)(iVar1 + 8);
      }
      if (*(int *)(iVar1 + 8) != 0) {
        *(undefined4 *)(*(int *)(iVar1 + 8) + 4) = *(undefined4 *)(iVar1 + 4);
      }
      if (*(int *)(iVar1 + 4) != 0) {
        *(undefined4 *)(*(int *)(iVar1 + 4) + 8) = *(undefined4 *)(iVar1 + 8);
      }
      *(undefined4 *)(iVar1 + 4) = 0xabadcafe;
      *(undefined4 *)(iVar1 + 8) = 0xabadcafe;
      param_1[0x804] = param_1[0x804] + -1;
    }
    iVar1 = param_1[0x804];
  }
  param_1[0x803] = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  local_4 = local_4 & 0xffffff00;
  eh_vector_destructor_iterator(param_1 + 3,0x20,0x100,FUN_004fcab0);
  *param_1 = &PTR_FUN_006c2c50;
  ExceptionList = local_c;
  return;
}


// ==== 0x4fd0d0 FUN_004fd0d0

void * __thiscall FUN_004fd0d0(void *param_1,byte param_2)

{
  FUN_004fcff0(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4fd0f0 FUN_004fd0f0

int __fastcall FUN_004fd0f0(undefined4 param_1,char *param_2)

{
  char cVar1;
  char *in_EAX;
  char cVar2;
  
  do {
    cVar2 = *in_EAX;
    if (('`' < cVar2) && (cVar2 < '{')) {
      cVar2 = cVar2 + -0x20;
    }
    cVar1 = *param_2;
    in_EAX = in_EAX + 1;
    if (('`' < cVar1) && (cVar1 < '{')) {
      cVar1 = cVar1 + -0x20;
    }
    param_2 = param_2 + 1;
  } while ((cVar2 != '\0') && (cVar2 == cVar1));
  return (int)cVar2 - (int)cVar1;
}


// ==== 0x4fd130 FUN_004fd130

void * __thiscall FUN_004fd130(void *param_1,byte param_2)

{
  FENode___FENode();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4fd150 FENode::_FENode

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void __fastcall FENode___FENode(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c1828;
  if ((void *)param_1[3] != (void *)0x0) {
    _free((void *)param_1[3]);
  }
  *param_1 = &PTR_FUN_006c2c50;
  return;
}


// ==== 0x4fd180 FENode::SetName

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

undefined1 FENode__SetName(void)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  int unaff_ESI;
  char *unaff_EDI;
  
  uVar4 = 0;
  if (*(void **)(unaff_ESI + 0xc) != (void *)0x0) {
    _free(*(void **)(unaff_ESI + 0xc));
    *(undefined4 *)(unaff_ESI + 0xc) = 0;
  }
  if (unaff_EDI != (char *)0x0) {
    pcVar2 = unaff_EDI;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = _malloc((size_t)(pcVar2 + (1 - (int)(unaff_EDI + 1))));
    *(char **)(unaff_ESI + 0xc) = pcVar2;
    if (pcVar2 != (char *)0x0) {
      do {
        cVar1 = *unaff_EDI;
        unaff_EDI = unaff_EDI + 1;
        *pcVar2 = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      uVar4 = 1;
    }
  }
  uVar3 = FEng__HashName();
  *(undefined4 *)(unaff_ESI + 0x10) = uVar3;
  return uVar4;
}


// ==== 0x4fd1e0 FUN_004fd1e0

int FUN_004fd1e0(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar1 = FEng__HashName();
  do {
    if (in_EAX == 0) {
      return 0;
    }
    iVar2 = unaff_EDI;
    if (*(int *)(in_EAX + 0xc) == 0) {
LAB_004fd20d:
      if (iVar2 == 0) {
        return in_EAX;
      }
    }
    else if (iVar1 == *(int *)(in_EAX + 0x10)) {
      iVar2 = FUN_004fd0f0();
      goto LAB_004fd20d;
    }
    in_EAX = *(int *)(in_EAX + 4);
  } while( true );
}


// ==== 0x4fd230 FEng::HashName

/* [canon] hud med (ghidra+hopper+capstone) docs/re/hud_input.md */

int __fastcall FEng__HashName(undefined4 param_1,byte *param_2)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  
  iVar2 = -1;
  if (param_2 != (byte *)0x0) {
    bVar3 = *param_2;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar2 = iVar2 * 0x21 + (uint)bVar3;
      pbVar1 = param_2 + 1;
      param_2 = param_2 + 1;
      bVar3 = *pbVar1;
    }
  }
  return iVar2;
}


// ==== 0x4fd260 FUN_004fd260

undefined4 * __thiscall FUN_004fd260(undefined4 *param_1,byte param_2)

{
  if ((param_2 & 2) != 0) {
    eh_vector_destructor_iterator(param_1,0x10,param_1[-1],FUN_004ee650);
    if ((param_2 & 1) != 0) {
      _free(param_1 + -1);
    }
    return param_1 + -1;
  }
  *param_1 = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4fd2c0 FUN_004fd2c0

void FUN_004fd2c0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FEObject__FEObject();
  *puVar1 = &PTR_FUN_006c1820;
  puVar1[0x16] = 4;
  puVar1[0x17] = 0;
  puVar1[0x18] = 0;
  puVar1[0x19] = 0;
  puVar1[0x1a] = 0;
  puVar1[0x1b] = 0;
  puVar1[0x1c] = 0;
  puVar1[0x1d] = 0;
  puVar1[0x1e] = 0;
  puVar1[0x1f] = 0x3f800000;
  puVar1[0x20] = 0x3f800000;
  puVar1[0x21] = 0;
  puVar1[0x22] = 0;
  puVar1[0x23] = 0;
  puVar1[0x24] = 0;
  puVar1[0x25] = 0;
  puVar1[0x26] = 0;
  puVar1[0x27] = 0;
  puVar1[0x28] = 0x3f800000;
  puVar1[0x29] = 0xbab60b61;
  puVar1[6] = 4;
  return;
}


// ==== 0x4fd340 FUN_004fd340

void * __thiscall FUN_004fd340(void *param_1,byte param_2)

{
  FUN_004fd360();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4fd360 FUN_004fd360

void FUN_004fd360(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_FUN_006c1820;
  FUN_004fd380();
  FUN_004fef10();
  return;
}


// ==== 0x4fd380 FUN_004fd380

void FUN_004fd380(void)

{
  int in_EAX;
  
  if ((*(uint *)(in_EAX + 0x58) & 1) != 0) {
    *(uint *)(in_EAX + 0x58) = *(uint *)(in_EAX + 0x58) & 0xfffffffe;
    if (*(int *)(in_EAX + 0x5c) != 0) {
      _free(*(void **)(in_EAX + 0x74));
      *(undefined4 *)(in_EAX + 0x74) = 0;
      *(undefined4 *)(in_EAX + 0x5c) = 0;
    }
    if (*(int *)(in_EAX + 0x60) != 0) {
      _free(*(void **)(in_EAX + 0x78));
      *(undefined4 *)(in_EAX + 0x78) = 0;
      *(undefined4 *)(in_EAX + 0x60) = 0;
    }
    FEListBox__CleanupCells();
  }
  return;
}


// ==== 0x4fd3d0 FUN_004fd3d0

void FUN_004fd3d0(uint param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *local_24;
  undefined4 *local_18;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  iVar2 = param_1;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684b68;
  local_c = ExceptionList;
  uVar6 = 0;
  if (param_2 == 0) {
    ExceptionList = &local_c;
    if (*(int *)(param_1 + 0x5c) != 0) {
      ExceptionList = &local_c;
      _free(*(void **)(param_1 + 0x74));
      *(undefined4 *)(param_1 + 0x74) = 0;
      *(undefined4 *)(param_1 + 0x5c) = 0;
    }
    FEListBox__CleanupCells();
  }
  else {
    ExceptionList = &local_c;
    puVar3 = _malloc(param_2 * 0xc);
    uVar4 = *(uint *)(param_1 + 0x5c);
    if (uVar4 != 0) {
      uVar6 = uVar4;
      if (param_2 <= uVar4) {
        uVar6 = param_2;
      }
      puVar7 = *(undefined4 **)(param_1 + 0x74);
      puVar8 = puVar3;
      for (uVar4 = uVar6 * 3 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      _free(*(void **)(param_1 + 0x74));
    }
    puVar7 = puVar3 + uVar6 * 3;
    for (uVar4 = (param_2 - uVar6) * 3 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar7 = 0;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    iVar5 = *(int *)(param_1 + 0x60) * param_2;
    local_18 = (undefined4 *)0x0;
    if (iVar5 != 0) {
      local_18 = _malloc(iVar5 * 0x30);
      local_4 = 0;
      if (local_18 == (undefined4 *)0x0) {
        local_18 = (undefined4 *)0x0;
      }
      else {
        CallNTimes(local_18,0x30,iVar5,FUN_004fa3a0);
      }
      if (*(int *)(param_1 + 0x8c) == 0) {
        FEListBox__InitializeCell();
      }
      else {
        piVar1 = (int *)(param_1 + 0x60);
        param_1 = 0;
        local_24 = local_18;
        if (*piVar1 != 0) {
          do {
            puVar7 = (undefined4 *)
                     (*(int *)(iVar2 + 0x5c) * param_1 * 0x30 + *(int *)(iVar2 + 0x8c));
            puVar8 = local_24;
            for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
              *puVar8 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar8 = puVar8 + 1;
            }
            for (uVar4 = uVar6 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
              *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
              puVar7 = (undefined4 *)((int)puVar7 + 1);
              puVar8 = (undefined4 *)((int)puVar8 + 1);
            }
            FEListBox__InitializeCell();
            param_1 = param_1 + 1;
            local_24 = local_24 + param_2 * 0xc;
          } while (param_1 < *(uint *)(iVar2 + 0x60));
        }
        _free(*(void **)(iVar2 + 0x8c));
      }
    }
    *(uint *)(iVar2 + 0x5c) = param_2;
    *(undefined4 **)(iVar2 + 0x74) = puVar3;
    *(undefined4 **)(iVar2 + 0x8c) = local_18;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x4fd5e0 FUN_004fd5e0

void FUN_004fd5e0(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *local_14;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684f18;
  local_c = ExceptionList;
  uVar5 = 0;
  if (param_2 == 0) {
    ExceptionList = &local_c;
    if (*(int *)(param_1 + 0x60) != 0) {
      ExceptionList = &local_c;
      _free(*(void **)(param_1 + 0x78));
      *(undefined4 *)(param_1 + 0x78) = 0;
      *(undefined4 *)(param_1 + 0x60) = 0;
    }
    FEListBox__CleanupCells();
  }
  else {
    ExceptionList = &local_c;
    puVar1 = _malloc(param_2 * 0xc);
    uVar3 = *(uint *)(param_1 + 0x60);
    if (uVar3 != 0) {
      uVar5 = uVar3;
      if (param_2 <= uVar3) {
        uVar5 = param_2;
      }
      puVar2 = *(undefined4 **)(param_1 + 0x78);
      puVar6 = puVar1;
      for (uVar3 = uVar5 * 3 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar6 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar6 = puVar6 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar6 = *(undefined1 *)puVar2;
        puVar2 = (undefined4 *)((int)puVar2 + 1);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
      _free(*(void **)(param_1 + 0x78));
    }
    puVar2 = puVar1 + uVar5 * 3;
    for (uVar3 = (param_2 - uVar5) * 3 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar2 = 0;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
    iVar4 = *(int *)(param_1 + 0x5c) * param_2;
    local_14 = (undefined4 *)0x0;
    if (iVar4 != 0) {
      puVar2 = _malloc(iVar4 * 0x30);
      local_4 = 0;
      local_14 = (undefined4 *)0x0;
      if (puVar2 != (undefined4 *)0x0) {
        CallNTimes(puVar2,0x30,iVar4,FUN_004fa3a0);
        local_14 = puVar2;
      }
      if (*(undefined4 **)(param_1 + 0x8c) == (undefined4 *)0x0) {
        FEListBox__InitializeCell();
      }
      else {
        uVar5 = *(int *)(param_1 + 0x5c) * uVar5;
        puVar2 = *(undefined4 **)(param_1 + 0x8c);
        puVar6 = local_14;
        for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar6 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar6 = puVar6 + 1;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined1 *)puVar6 = *(undefined1 *)puVar2;
          puVar2 = (undefined4 *)((int)puVar2 + 1);
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
        FEListBox__InitializeCell();
        _free(*(void **)(param_1 + 0x8c));
      }
    }
    *(uint *)(param_1 + 0x60) = param_2;
    *(undefined4 **)(param_1 + 0x78) = puVar1;
    *(undefined4 **)(param_1 + 0x8c) = local_14;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x4fd770 FEListBox::SetCellType

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void __fastcall FEListBox__SetCellType(int param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar2 = (*(int *)(param_1 + 0x88) * *(int *)(param_1 + 0x5c) + *(int *)(param_1 + 0x84)) * 0x30;
  iVar1 = *(int *)(iVar2 + 0x18 + *(int *)(param_1 + 0x8c));
  iVar2 = iVar2 + *(int *)(param_1 + 0x8c);
  if (iVar1 != unaff_EDI) {
    if ((iVar1 == 2) && (*(void **)(iVar2 + 0x20) != (void *)0x0)) {
      _free(*(void **)(iVar2 + 0x20));
      *(undefined4 *)(iVar2 + 0x20) = 0;
    }
    *(int *)(iVar2 + 0x18) = unaff_EDI;
  }
  return;
}


// ==== 0x4fd7c0 FEListBox::SetCellString

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void __fastcall FEListBox__SetCellString(int param_1)

{
  short sVar1;
  void *_Memory;
  short *in_EAX;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = (*(int *)(param_1 + 0x88) * *(int *)(param_1 + 0x5c) + *(int *)(param_1 + 0x84)) * 0x30;
  _Memory = *(void **)(iVar6 + 0x20 + *(int *)(param_1 + 0x8c));
  iVar6 = iVar6 + *(int *)(param_1 + 0x8c);
  if (_Memory != (void *)0x0) {
    _free(_Memory);
    *(undefined4 *)(iVar6 + 0x20) = 0;
  }
  if (in_EAX != (short *)0x0) {
    iVar2 = 0;
    sVar1 = *in_EAX;
    while (sVar1 != 0) {
      iVar2 = iVar2 + 1;
      sVar1 = in_EAX[iVar2];
    }
    uVar5 = iVar2 * 2 + 2;
    puVar3 = _malloc(uVar5);
    *(undefined4 **)(iVar6 + 0x20) = puVar3;
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar3 = *(undefined4 *)in_EAX;
      in_EAX = in_EAX + 2;
      puVar3 = puVar3 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(char *)puVar3 = (char)*in_EAX;
      in_EAX = (short *)((int)in_EAX + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  return;
}


// ==== 0x4fd840 FEListBox::IncrementCellByColumn

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void FEListBox__IncrementCellByColumn(void)

{
  int in_EAX;
  uint uVar1;
  
  uVar1 = *(int *)(in_EAX + 0x84) + 1;
  *(uint *)(in_EAX + 0x84) = uVar1;
  if (*(uint *)(in_EAX + 0x5c) <= uVar1) {
    uVar1 = *(int *)(in_EAX + 0x88) + 1;
    *(undefined4 *)(in_EAX + 0x84) = 0;
    *(uint *)(in_EAX + 0x88) = uVar1;
    if (*(uint *)(in_EAX + 0x60) <= uVar1) {
      *(undefined4 *)(in_EAX + 0x88) = 0;
    }
  }
  return;
}


// ==== 0x4fd880 FUN_004fd880

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004fd880(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int in_EAX;
  int iVar8;
  uint uVar9;
  uint uVar10;
  float *pfVar11;
  uint uVar12;
  
  uVar3 = *(uint *)(param_1 + 0x58);
  if (((byte)uVar3 & 0x60) == 0x60) {
    return;
  }
  if ((uVar3 & 0x20) != 0) {
    in_EAX = 0;
  }
  if ((uVar3 & 0x40) != 0) {
    param_2 = 0;
  }
  if (in_EAX == 0) {
    if (param_2 == 0) {
      return;
    }
  }
  else {
    if ((uVar3 & 0x20) == 0) {
      uVar12 = *(int *)(param_1 + 0x84) + in_EAX;
      uVar4 = *(uint *)(param_1 + 0x5c);
      if ((uVar3 & 4) == 0) {
        iVar8 = *(int *)(param_1 + 0x74);
        if ((int)uVar12 < 0) {
          uVar9 = uVar4 + uVar12;
          uVar2 = *(undefined4 *)(iVar8 + 4 + uVar9 * 0xc);
          *(undefined4 *)(param_1 + 0x90) = uVar2;
          *(undefined4 *)(param_1 + 0x6c) = uVar2;
          do {
            iVar1 = uVar9 * 0xc;
            uVar9 = (uVar9 + 1) % uVar4;
            *(float *)(param_1 + 0x6c) = *(float *)(iVar8 + iVar1) + *(float *)(param_1 + 0x6c);
          } while (uVar9 != *(uint *)(param_1 + 0x84));
        }
        else {
          if ((int)uVar12 < (int)uVar4) {
            *(uint *)(param_1 + 0x84) = uVar12;
            *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(iVar8 + 4 + uVar12 * 0xc);
            goto LAB_004fd99b;
          }
          uVar9 = *(uint *)(param_1 + 0x84);
          *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x6c);
          do {
            uVar10 = uVar9 % uVar4;
            uVar9 = uVar9 + 1;
            *(float *)(param_1 + 0x90) =
                 *(float *)(iVar8 + uVar10 * 0xc) + *(float *)(param_1 + 0x90);
          } while (uVar9 != uVar12);
        }
        *(uint *)(param_1 + 0x58) = uVar3 | 8;
        *(uint *)(param_1 + 0x84) = uVar12 % uVar4;
      }
      else {
        if ((int)uVar4 <= (int)uVar12) {
          uVar12 = uVar4 - 1;
        }
        if ((int)uVar12 < 0) {
          uVar12 = 0;
        }
        iVar8 = *(int *)(param_1 + 0x74);
        *(uint *)(param_1 + 0x84) = uVar12;
        *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(iVar8 + 4 + uVar12 * 0xc);
      }
LAB_004fd99b:
      uVar3 = *(uint *)(param_1 + 0x84);
      fVar5 = 0.0;
      if (uVar3 < uVar4) {
        pfVar11 = (float *)(iVar8 + uVar3 * 0xc);
        iVar8 = *(int *)(param_1 + 0x5c) - uVar3;
        do {
          fVar5 = fVar5 + *pfVar11;
          pfVar11 = pfVar11 + 3;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      if ((*(uint *)(param_1 + 0x58) & 4) == 0) {
        if (fVar5 < *(float *)(param_1 + 100)) {
          *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 8;
        }
      }
      else if (fVar5 < *(float *)(param_1 + 100)) {
        *(float *)(param_1 + 0x90) =
             *(float *)(param_1 + 0x90) - (*(float *)(param_1 + 100) - fVar5);
      }
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x20;
    }
    if (param_2 == 0) goto LAB_004fda96;
  }
  uVar3 = *(uint *)(param_1 + 0x58);
  if ((uVar3 & 0x40) != 0) goto LAB_004fda96;
  uVar4 = *(uint *)(param_1 + 0x60);
  uVar12 = *(int *)(param_1 + 0x88) + param_2;
  if ((uVar3 & 4) == 0) {
    if ((int)uVar12 < 0) {
      iVar8 = *(int *)(param_1 + 0x78);
      uVar9 = uVar4 + uVar12;
      uVar2 = *(undefined4 *)(iVar8 + 4 + uVar9 * 0xc);
      *(undefined4 *)(param_1 + 0x94) = uVar2;
      *(undefined4 *)(param_1 + 0x70) = uVar2;
      do {
        iVar1 = uVar9 * 0xc;
        uVar9 = (uVar9 + 1) % uVar4;
        *(float *)(param_1 + 0x70) = *(float *)(iVar8 + iVar1) + *(float *)(param_1 + 0x70);
      } while (uVar9 != *(uint *)(param_1 + 0x88));
    }
    else {
      if ((int)uVar12 < (int)uVar4) goto LAB_004fda2d;
      uVar9 = *(uint *)(param_1 + 0x88);
      iVar8 = *(int *)(param_1 + 0x78);
      *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x70);
      do {
        uVar10 = uVar9 % uVar4;
        uVar9 = uVar9 + 1;
        *(float *)(param_1 + 0x94) = *(float *)(iVar8 + uVar10 * 0xc) + *(float *)(param_1 + 0x94);
      } while (uVar9 != uVar12);
    }
    *(uint *)(param_1 + 0x58) = uVar3 | 8;
    *(uint *)(param_1 + 0x88) = uVar12 % uVar4;
  }
  else {
    if ((int)uVar4 <= (int)uVar12) {
      uVar12 = uVar4 - 1;
    }
    if ((int)uVar12 < 0) {
      uVar12 = 0;
    }
LAB_004fda2d:
    iVar8 = *(int *)(param_1 + 0x78);
    *(uint *)(param_1 + 0x88) = uVar12;
    *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(iVar8 + 4 + uVar12 * 0xc);
  }
  uVar3 = *(uint *)(param_1 + 0x88);
  fVar5 = 0.0;
  if (uVar3 < uVar4) {
    pfVar11 = (float *)(iVar8 + uVar3 * 0xc);
    iVar8 = *(int *)(param_1 + 0x60) - uVar3;
    do {
      fVar5 = fVar5 + *pfVar11;
      pfVar11 = pfVar11 + 3;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  if ((*(uint *)(param_1 + 0x58) & 4) == 0) {
    if (fVar5 < *(float *)(param_1 + 0x68)) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x10;
    }
  }
  else if (fVar5 < *(float *)(param_1 + 0x68)) {
    *(float *)(param_1 + 0x94) = *(float *)(param_1 + 0x94) - (*(float *)(param_1 + 0x68) - fVar5);
  }
  *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x40;
LAB_004fda96:
  *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 2;
  fVar5 = *(float *)(param_1 + 0x90) - *(float *)(param_1 + 0x6c);
  fVar7 = *(float *)(param_1 + 0x94) - *(float *)(param_1 + 0x70);
  *(float *)(param_1 + 0x98) = fVar5;
  *(float *)(param_1 + 0x9c) = fVar7;
  fVar6 = SQRT(fVar5 * fVar5 + fVar7 * fVar7);
  if (0.1 <= fVar6) {
    fVar6 = _K_ONE / fVar6;
    *(float *)(param_1 + 0x98) = fVar6 * fVar5;
    *(float *)(param_1 + 0x9c) = fVar7 * fVar6;
  }
  else {
    *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0x90);
    *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x94);
    uVar3 = *(uint *)(param_1 + 0x58);
    *(uint *)(param_1 + 0x58) = uVar3 & 0xffffff9d;
    if (*(int *)(param_1 + 0x84) == 0) {
      *(uint *)(param_1 + 0x58) = uVar3 & 0xffffff95;
      *(undefined4 *)(param_1 + 0x6c) = 0;
    }
    if (*(int *)(param_1 + 0x88) == 0) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xffffffef;
      *(undefined4 *)(param_1 + 0x70) = 0;
      return;
    }
  }
  return;
}


// ==== 0x4fdc20 FUN_004fdc20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004fdc20(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = param_2 * *(float *)(param_1 + 0xa4) + *(float *)(param_1 + 0xa0);
  *(float *)(param_1 + 0xa0) = fVar1;
  if (0.0 <= fVar1) {
    if (fVar1 <= _K_ONE) goto LAB_004fdc79;
    *(undefined4 *)(param_1 + 0xa0) = 0x3f800000;
  }
  else {
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  *(float *)(param_1 + 0xa4) = -*(float *)(param_1 + 0xa4);
LAB_004fdc79:
  if ((*(byte *)(param_1 + 0x58) & 2) != 0) {
    fVar1 = *(float *)(param_1 + 0x98);
    fVar2 = *(float *)(param_1 + 0x9c);
    param_2 = ABS(fVar1 * *(float *)(param_1 + 0x7c) + fVar2 * *(float *)(param_1 + 0x80)) * param_2
    ;
    fVar4 = fVar1 * param_2 + *(float *)(param_1 + 0x6c);
    *(float *)(param_1 + 0x6c) = fVar4;
    fVar3 = fVar2 * param_2 + *(float *)(param_1 + 0x70);
    *(float *)(param_1 + 0x70) = fVar3;
    if ((fVar1 * *(float *)(param_1 + 0x90) + fVar2 * *(float *)(param_1 + 0x94)) -
        (fVar4 * fVar1 + fVar3 * fVar2) < 0.0) {
      FUN_004fde00();
    }
  }
  return;
}


// ==== 0x4fdd00 FEListBox::InitializeCell

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void __fastcall FEListBox__InitializeCell(int param_1)

{
  int in_EAX;
  undefined4 *puVar1;
  
  if (param_1 != 0) {
    puVar1 = (undefined4 *)(in_EAX + 0x10);
    do {
      puVar1[-4] = 0xffffffff;
      puVar1[-3] = 0x3f800000;
      puVar1[-2] = 0x3f800000;
      puVar1[-1] = 0;
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      puVar1[6] = 0x3f800000;
      puVar1[7] = 0x3f800000;
      puVar1[3] = 0;
      puVar1 = puVar1 + 0xc;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}


// ==== 0x4fdd40 FEListBox::CleanupCells

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void FEListBox__CleanupCells(void)

{
  void *_Memory;
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x60) * *(int *)(unaff_EDI + 0x5c);
  if (iVar1 != 0) {
    iVar2 = 0;
    do {
      if ((*(int *)(*(int *)(unaff_EDI + 0x8c) + 0x18 + iVar2) == 2) &&
         (_Memory = *(void **)(*(int *)(unaff_EDI + 0x8c) + iVar2 + 0x20), _Memory != (void *)0x0))
      {
        _free(_Memory);
        *(undefined4 *)(*(int *)(unaff_EDI + 0x8c) + 0x20 + iVar2) = 0;
      }
      iVar2 = iVar2 + 0x30;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    _free(*(void **)(unaff_EDI + 0x8c));
    *(undefined4 *)(unaff_EDI + 0x8c) = 0;
  }
  return;
}


// ==== 0x4fddb0 FEListBox::RecalculateCummulative

/* [canon] hud high (ghidra-canon+mw) docs/re/hud.md */

void FEListBox__RecalculateCummulative(void)

{
  float fVar1;
  int in_EAX;
  float *pfVar2;
  uint uVar3;
  
  pfVar2 = *(float **)(in_EAX + 0x74);
  fVar1 = 0.0;
  uVar3 = 0;
  if (*(int *)(in_EAX + 0x5c) != 0) {
    do {
      pfVar2[1] = fVar1;
      fVar1 = fVar1 + *pfVar2;
      pfVar2 = pfVar2 + 3;
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_EAX + 0x5c));
  }
  pfVar2 = *(float **)(in_EAX + 0x78);
  fVar1 = 0.0;
  uVar3 = 0;
  if (*(int *)(in_EAX + 0x60) != 0) {
    do {
      pfVar2[1] = fVar1;
      fVar1 = fVar1 + *pfVar2;
      pfVar2 = pfVar2 + 3;
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(in_EAX + 0x60));
  }
  return;
}


// ==== 0x4fde00 FUN_004fde00

void FUN_004fde00(void)

{
  uint uVar1;
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x6c) = *(undefined4 *)(in_EAX + 0x90);
  *(undefined4 *)(in_EAX + 0x70) = *(undefined4 *)(in_EAX + 0x94);
  uVar1 = *(uint *)(in_EAX + 0x58);
  *(uint *)(in_EAX + 0x58) = uVar1 & 0xffffff9d;
  if (*(int *)(in_EAX + 0x84) == 0) {
    *(uint *)(in_EAX + 0x58) = uVar1 & 0xffffff95;
    *(undefined4 *)(in_EAX + 0x6c) = 0;
  }
  if (*(int *)(in_EAX + 0x88) == 0) {
    *(uint *)(in_EAX + 0x58) = *(uint *)(in_EAX + 0x58) & 0xffffffef;
    *(undefined4 *)(in_EAX + 0x70) = 0;
  }
  return;
}


// ==== 0x4fde50 FUN_004fde50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004fde50(float *param_1)

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
  float *in_EAX;
  
  fVar8 = *param_1 + *param_1;
  fVar10 = param_1[1] + param_1[1];
  fVar11 = param_1[2] + param_1[2];
  fVar9 = fVar8 * *param_1;
  fVar1 = *param_1;
  fVar2 = *param_1;
  fVar3 = param_1[1];
  fVar4 = param_1[1];
  fVar5 = param_1[2];
  fVar8 = fVar8 * param_1[3];
  fVar6 = param_1[3];
  fVar7 = param_1[3];
  in_EAX[0xc] = 0.0;
  in_EAX[0xd] = 0.0;
  in_EAX[0xe] = 0.0;
  in_EAX[3] = 0.0;
  fVar12 = _K_ONE - (fVar11 * fVar5 + fVar10 * fVar3);
  in_EAX[7] = 0.0;
  in_EAX[0xb] = 0.0;
  *in_EAX = fVar12;
  in_EAX[0xf] = 1.0;
  in_EAX[4] = fVar10 * fVar1 - fVar11 * fVar7;
  in_EAX[8] = fVar10 * fVar6 + fVar11 * fVar2;
  in_EAX[1] = fVar11 * fVar7 + fVar10 * fVar1;
  in_EAX[5] = _K_ONE - (fVar11 * fVar5 + fVar9);
  in_EAX[9] = fVar11 * fVar4 - fVar8;
  in_EAX[2] = fVar11 * fVar2 - fVar10 * fVar6;
  in_EAX[6] = fVar8 + fVar11 * fVar4;
  in_EAX[10] = _K_ONE - (fVar10 * fVar3 + fVar9);
  return;
}


// ==== 0x4fdf40 FUN_004fdf40

void __fastcall FUN_004fdf40(float *param_1,float *param_2)

{
  float *in_EAX;
  int iVar1;
  float *pfVar2;
  float local_40 [4];
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_40[0] = in_EAX[1] * param_1[4] +
                in_EAX[2] * param_1[8] + in_EAX[3] * param_1[0xc] + *param_1 * *in_EAX;
  local_40[1] = param_1[9] * in_EAX[2] +
                in_EAX[1] * param_1[5] + param_1[1] * *in_EAX + param_1[0xd] * in_EAX[3];
  local_40[2] = in_EAX[3] * param_1[0xe] +
                param_1[2] * *in_EAX + param_1[6] * in_EAX[1] + param_1[10] * in_EAX[2];
  local_40[3] = *in_EAX * param_1[3] +
                in_EAX[2] * param_1[0xb] + param_1[0xf] * in_EAX[3] + param_1[7] * in_EAX[1];
  local_30 = in_EAX[4] * *param_1 +
             in_EAX[7] * param_1[0xc] + param_1[4] * in_EAX[5] + in_EAX[6] * param_1[8];
  local_2c = in_EAX[7] * param_1[0xd] +
             in_EAX[5] * param_1[5] + in_EAX[4] * param_1[1] + in_EAX[6] * param_1[9];
  local_28 = in_EAX[4] * param_1[2] +
             param_1[6] * in_EAX[5] + in_EAX[6] * param_1[10] + in_EAX[7] * param_1[0xe];
  local_24 = param_1[7] * in_EAX[5] +
             in_EAX[4] * param_1[3] + in_EAX[6] * param_1[0xb] + param_1[0xf] * in_EAX[7];
  local_20 = in_EAX[8] * *param_1 +
             in_EAX[0xb] * param_1[0xc] + in_EAX[9] * param_1[4] + in_EAX[10] * param_1[8];
  local_1c = in_EAX[0xb] * param_1[0xd] +
             in_EAX[9] * param_1[5] + in_EAX[8] * param_1[1] + in_EAX[10] * param_1[9];
  local_18 = in_EAX[8] * param_1[2] +
             param_1[6] * in_EAX[9] + in_EAX[10] * param_1[10] + in_EAX[0xb] * param_1[0xe];
  local_14 = param_1[7] * in_EAX[9] +
             in_EAX[8] * param_1[3] + in_EAX[10] * param_1[0xb] + param_1[0xf] * in_EAX[0xb];
  local_10 = in_EAX[0xc] * *param_1 +
             in_EAX[0xf] * param_1[0xc] + in_EAX[0xd] * param_1[4] + in_EAX[0xe] * param_1[8];
  local_c = in_EAX[0xf] * param_1[0xd] +
            in_EAX[0xd] * param_1[5] + in_EAX[0xc] * param_1[1] + in_EAX[0xe] * param_1[9];
  local_8 = in_EAX[0xc] * param_1[2] +
            param_1[6] * in_EAX[0xd] + in_EAX[0xe] * param_1[10] + in_EAX[0xf] * param_1[0xe];
  local_4 = param_1[7] * in_EAX[0xd] +
            in_EAX[0xc] * param_1[3] + in_EAX[0xe] * param_1[0xb] + param_1[0xf] * in_EAX[0xf];
  pfVar2 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_2 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    param_2 = param_2 + 1;
  }
  return;
}


// ==== 0x4fe170 Mat4_TransformPoint

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

void __fastcall Mat4_TransformPoint(float *param_1,float *param_2)

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
  float *in_EAX;
  
  fVar1 = in_EAX[9];
  fVar2 = param_1[2];
  fVar3 = in_EAX[1];
  fVar4 = *param_1;
  fVar5 = in_EAX[5];
  fVar6 = param_1[1];
  fVar7 = in_EAX[0xd];
  fVar8 = in_EAX[10];
  fVar9 = param_1[2];
  fVar10 = in_EAX[2];
  fVar11 = *param_1;
  fVar12 = in_EAX[6];
  fVar13 = param_1[1];
  fVar14 = in_EAX[0xe];
  *param_2 = *in_EAX * *param_1 + in_EAX[4] * param_1[1] + in_EAX[8] * param_1[2] + in_EAX[0xc];
  param_2[1] = fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2 + fVar7;
  param_2[2] = fVar12 * fVar13 + fVar10 * fVar11 + fVar8 * fVar9 + fVar14;
  return;
}


// ==== 0x4fe1d0 FUN_004fe1d0

void __fastcall FUN_004fe1d0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ==== 0x4fe1e0 FEMessageResponse::FEMessageResponse

/* [canon] hud high (ghidra-canon+mw) docs/re/hud.md */

void __fastcall FEMessageResponse__FEMessageResponse(undefined4 *param_1)

{
  param_1[1] = 0xabadcafe;
  param_1[2] = 0xabadcafe;
  *param_1 = &PTR_FUN_006c181c;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  return;
}


// ==== 0x4fe200 FUN_004fe200

undefined4 * __thiscall FUN_004fe200(undefined4 *param_1,byte param_2)

{
  FEMessageResponse___FEMessageResponse();
  if ((param_2 & 1) != 0) {
    (**(code **)*param_1)(0);
    FUN_004fe620();
  }
  return param_1;
}


// ==== 0x4fe230 FEResponse::ReleaseParam

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void __fastcall FEResponse__ReleaseParam(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if (((0x1ff < uVar1) && (uVar1 < 0x205)) && (uVar1 != 0x203)) {
    _free((void *)param_1[1]);
  }
  param_1[1] = 0;
  return;
}


// ==== 0x4fe260 FUN_004fe260

void FUN_004fe260(uint *param_1)

{
  uint uVar1;
  uint *unaff_ESI;
  
  uVar1 = *unaff_ESI;
  if (((0x1ff < uVar1) && (uVar1 < 0x205)) && (uVar1 != 0x203)) {
    _free((void *)unaff_ESI[1]);
  }
  unaff_ESI[1] = 0;
  uVar1 = *param_1;
  *unaff_ESI = uVar1;
  if (((0x1ff < uVar1) && (uVar1 < 0x205)) && (uVar1 != 0x203)) {
    Variant_SetString(unaff_ESI);
    unaff_ESI[2] = param_1[2];
    return;
  }
  unaff_ESI[1] = param_1[1];
  unaff_ESI[2] = param_1[2];
  return;
}


// ==== 0x4fe2e0 Variant_SetString

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

void Variant_SetString(uint *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  void *pvVar4;
  int iVar5;
  char *unaff_EDI;
  
  uVar2 = *param_1;
  if (((0x1ff < uVar2) && (uVar2 < 0x205)) && (uVar2 != 0x203)) {
    _free((void *)param_1[1]);
  }
  param_1[1] = 0;
  if (unaff_EDI != (char *)0x0) {
    pcVar3 = unaff_EDI;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pvVar4 = _malloc((size_t)(pcVar3 + (1 - (int)(unaff_EDI + 1))));
    iVar5 = (int)pvVar4 - (int)unaff_EDI;
    do {
      cVar1 = *unaff_EDI;
      unaff_EDI[iVar5] = cVar1;
      unaff_EDI = unaff_EDI + 1;
    } while (cVar1 != '\0');
    param_1[1] = (uint)pvVar4;
  }
  return;
}


// ==== 0x4fe350 FEMessageResponse::_FEMessageResponse

/* [canon] hud high (ghidra-canon+mw) docs/re/hud.md */

void __fastcall FEMessageResponse___FEMessageResponse(undefined4 *param_1)

{
  void *pvVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685438;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c181c;
  pvVar1 = (void *)param_1[5];
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    eh_vector_destructor_iterator(pvVar1,0xc,*(int *)((int)pvVar1 + -4),FEResponse__ReleaseParam);
    _free((void *)((int)pvVar1 + -4));
  }
  param_1[5] = 0;
  param_1[4] = 0;
  *param_1 = &PTR_FUN_006c2c50;
  ExceptionList = local_c;
  return;
}


// ==== 0x4fe3d0 FUN_004fe3d0

void FUN_004fe3d0(int param_1,uint *param_2)

{
  void *pvVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  uVar3 = (uint)param_2;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684b48;
  local_c = ExceptionList;
  if (param_2 != (uint *)*(uint *)(param_1 + 0x10)) {
    iVar5 = 0;
    if (param_2 == (uint *)0x0) {
      pvVar1 = *(void **)(param_1 + 0x14);
      if (pvVar1 != (void *)0x0) {
        ExceptionList = &local_c;
        eh_vector_destructor_iterator
                  (pvVar1,0xc,*(int *)((int)pvVar1 + -4),FEResponse__ReleaseParam);
        _free((void *)((int)pvVar1 + -4));
      }
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    else {
      ExceptionList = &local_c;
      puVar4 = _malloc((int)param_2 * 0xc + 4);
      local_4 = 0;
      if (puVar4 == (uint *)0x0) {
        param_2 = (uint *)0x0;
      }
      else {
        *puVar4 = (uint)param_2;
        eh_vector_constructor_iterator
                  (puVar4 + 1,0xc,(int)param_2,FUN_004fe1d0,FEResponse__ReleaseParam);
        param_2 = puVar4 + 1;
      }
      local_4 = 0xffffffff;
      uVar2 = *(uint *)(param_1 + 0x10);
      if (uVar3 < *(uint *)(param_1 + 0x10)) {
        uVar2 = uVar3;
      }
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        FUN_004fe260(*(int *)(param_1 + 0x14) + iVar5);
        iVar5 = iVar5 + 0xc;
      }
      pvVar1 = *(void **)(param_1 + 0x14);
      if (pvVar1 != (void *)0x0) {
        eh_vector_destructor_iterator
                  (pvVar1,0xc,*(int *)((int)pvVar1 + -4),FEResponse__ReleaseParam);
        _free((void *)((int)pvVar1 + -4));
      }
      *(uint **)(param_1 + 0x14) = param_2;
      *(uint *)(param_1 + 0x10) = uVar3;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x4fe500 FEMessageResponse::FindConditionBranchTarget

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

uint __fastcall FEMessageResponse__FindConditionBranchTarget(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = *(uint *)(param_2 + 0x10);
  if (param_1 == uVar1 - 1) {
    return uVar1;
  }
  iVar4 = 1;
  iVar3 = *(int *)(param_2 + 0x14) + param_1 * 0xc;
  do {
    uVar2 = *(uint *)(iVar3 + 0xc);
    iVar3 = iVar3 + 0xc;
    param_1 = param_1 + 1;
    if (uVar2 < 0x501) {
      if (uVar2 == 0x500) {
        if (iVar4 == 1) {
          iVar4 = 0;
        }
      }
      else if ((0x2ff < uVar2) && (uVar2 < 0x302)) {
        iVar4 = iVar4 + 1;
      }
    }
    else if (uVar2 == 0x501) {
      iVar4 = iVar4 + -1;
    }
  } while ((param_1 < uVar1) && (iVar4 != 0));
  return param_1;
}


// ==== 0x4fe570 FUN_004fe570

void FUN_004fe570(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int unaff_EDI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  local_c = ExceptionList;
  for (iVar3 = *(int *)(unaff_EDI + 8); iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
    ExceptionList = &local_c;
    if (*(int *)(iVar3 + 0x610) != 0) goto LAB_004fe5f2;
  }
  ExceptionList = &local_c;
  pvVar2 = _malloc(0x620);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FEMessageResponse__StaticPoolInit(pvVar2);
  }
  if (iVar3 != 0) {
    iVar1 = *(int *)(unaff_EDI + 8);
    *(int *)(iVar3 + 4) = iVar1;
    if (iVar1 != 0) {
      *(int *)(iVar1 + 8) = iVar3;
    }
    *(undefined4 *)(iVar3 + 8) = 0;
    *(int *)(unaff_EDI + 8) = iVar3;
    if (*(int *)(unaff_EDI + 0xc) == 0) {
      *(int *)(unaff_EDI + 0xc) = iVar3;
    }
    *(int *)(unaff_EDI + 4) = *(int *)(unaff_EDI + 4) + 1;
  }
LAB_004fe5f2:
  if (*(int *)(iVar3 + 0x614) != 0) {
    FUN_004ee670();
  }
  *(int *)(iVar3 + 0x61c) = *(int *)(iVar3 + 0x61c) + 1;
  ExceptionList = local_c;
  return;
}


// ==== 0x4fe620 FUN_004fe620

void FUN_004fe620(void)

{
  int *piVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  int unaff_EDI;
  
  puVar2 = *(undefined4 **)(unaff_EDI + 8);
  if (puVar2 != (undefined4 *)0x0) {
    while ((in_EAX < puVar2 + 3 || (puVar2 + 0x183 <= in_EAX))) {
      puVar2 = (undefined4 *)puVar2[1];
      if (puVar2 == (undefined4 *)0x0) {
        return;
      }
    }
    FUN_004ee590();
    piVar1 = puVar2 + 0x187;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      FUN_004ee670();
      (**(code **)*puVar2)(1);
    }
  }
  return;
}


// ==== 0x4fe670 FEMessageResponse::StaticPoolInit

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

undefined4 * FEMessageResponse__StaticPoolInit(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684ef8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[1] = 0xabadcafe;
  param_1[2] = 0xabadcafe;
  local_4 = 0;
  *param_1 = &PTR_FUN_006c1818;
  eh_vector_constructor_iterator
            (param_1 + 3,0x18,0x40,FEMessageResponse__FEMessageResponse,
             FEMessageResponse___FEMessageResponse);
  param_1[0x183] = &PTR_FUN_006c2c4c;
  param_1[0x185] = 0;
  param_1[0x186] = 0;
  param_1[0x184] = 0;
  param_1[0x187] = 0;
  piVar4 = param_1 + 5;
  iVar5 = 0x10;
  do {
    iVar2 = param_1[0x186];
    if (piVar4 != (int *)0x8) {
      if (iVar2 == 0) {
        iVar3 = param_1[0x185];
        piVar4[-1] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar4 + -2;
        }
        *piVar4 = 0;
        param_1[0x185] = piVar4 + -2;
      }
      else {
        iVar3 = *(int *)(iVar2 + 4);
        piVar4[-1] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar4 + -2;
        }
        *piVar4 = iVar2;
        *(int **)(iVar2 + 4) = piVar4 + -2;
      }
      if (param_1[0x186] == iVar2) {
        param_1[0x186] = piVar4 + -2;
      }
      param_1[0x184] = param_1[0x184] + 1;
    }
    iVar2 = param_1[0x186];
    piVar1 = piVar4 + 4;
    if (piVar1 != (int *)0x0) {
      if (iVar2 == 0) {
        iVar3 = param_1[0x185];
        piVar4[5] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar1;
        }
        piVar4[6] = 0;
        param_1[0x185] = piVar1;
      }
      else {
        iVar3 = *(int *)(iVar2 + 4);
        piVar4[5] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar1;
        }
        piVar4[6] = iVar2;
        *(int **)(iVar2 + 4) = piVar1;
      }
      if (param_1[0x186] == iVar2) {
        param_1[0x186] = piVar1;
      }
      param_1[0x184] = param_1[0x184] + 1;
    }
    iVar2 = param_1[0x186];
    piVar1 = piVar4 + 10;
    if (piVar1 != (int *)0x0) {
      if (iVar2 == 0) {
        iVar3 = param_1[0x185];
        piVar4[0xb] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar1;
        }
        piVar4[0xc] = 0;
        param_1[0x185] = piVar1;
      }
      else {
        iVar3 = *(int *)(iVar2 + 4);
        piVar4[0xb] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar1;
        }
        piVar4[0xc] = iVar2;
        *(int **)(iVar2 + 4) = piVar1;
      }
      if (param_1[0x186] == iVar2) {
        param_1[0x186] = piVar1;
      }
      param_1[0x184] = param_1[0x184] + 1;
    }
    iVar2 = param_1[0x186];
    piVar1 = piVar4 + 0x10;
    if (piVar1 != (int *)0x0) {
      if (iVar2 == 0) {
        iVar3 = param_1[0x185];
        piVar4[0x11] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar1;
        }
        piVar4[0x12] = 0;
        param_1[0x185] = piVar1;
      }
      else {
        iVar3 = *(int *)(iVar2 + 4);
        piVar4[0x11] = iVar3;
        if (iVar3 != 0) {
          *(int **)(iVar3 + 8) = piVar1;
        }
        piVar4[0x12] = iVar2;
        *(int **)(iVar2 + 4) = piVar1;
      }
      if (param_1[0x186] == iVar2) {
        param_1[0x186] = piVar1;
      }
      param_1[0x184] = param_1[0x184] + 1;
    }
    piVar4 = piVar4 + 0x18;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4fe860 FUN_004fe860

void FUN_004fe860(undefined4 *param_1)

{
  int iVar1;
  void *local_c;
  code *pcStack_8;
  uint local_4;
  
  pcStack_8 = FUN_006858ee;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c1818;
  iVar1 = param_1[0x184];
  local_4 = 1;
  while (iVar1 != 0) {
    iVar1 = param_1[0x185];
    if (iVar1 != 0) {
      param_1[0x185] = *(undefined4 *)(iVar1 + 4);
      if (iVar1 == param_1[0x186]) {
        param_1[0x186] = *(undefined4 *)(iVar1 + 8);
      }
      if (*(int *)(iVar1 + 8) != 0) {
        *(undefined4 *)(*(int *)(iVar1 + 8) + 4) = *(undefined4 *)(iVar1 + 4);
      }
      if (*(int *)(iVar1 + 4) != 0) {
        *(undefined4 *)(*(int *)(iVar1 + 4) + 8) = *(undefined4 *)(iVar1 + 8);
      }
      *(undefined4 *)(iVar1 + 4) = 0xabadcafe;
      *(undefined4 *)(iVar1 + 8) = 0xabadcafe;
      param_1[0x184] = param_1[0x184] + -1;
    }
    iVar1 = param_1[0x184];
  }
  param_1[0x183] = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  local_4 = local_4 & 0xffffff00;
  eh_vector_destructor_iterator(param_1 + 3,0x18,0x40,FEMessageResponse___FEMessageResponse);
  *param_1 = &PTR_FUN_006c2c50;
  ExceptionList = local_c;
  return;
}


// ==== 0x4fe940 FUN_004fe940

void * __thiscall FUN_004fe940(void *param_1,byte param_2)

{
  FUN_004fe860(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4fe960 FEEventList::FEEventList

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void __fastcall FEEventList__FEEventList(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ==== 0x4fe970 FUN_004fe970

void __fastcall FUN_004fe970(int param_1)

{
  _free(*(void **)(param_1 + 0xc));
  return;
}


// ==== 0x4fe980 FEEventList::SetCount

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void FEEventList__SetCount(int param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_2 != 0) {
    if (param_2 != *(uint *)(param_1 + 4)) {
      puVar1 = _malloc(param_2 * 4);
      uVar2 = *(uint *)(param_1 + 4);
      if (param_2 < uVar2) {
        puVar4 = *(undefined4 **)(param_1 + 0xc);
        puVar5 = puVar1;
        for (uVar2 = param_2 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
          puVar5 = (undefined4 *)((int)puVar5 + 1);
        }
      }
      else {
        puVar4 = *(undefined4 **)(param_1 + 0xc);
        puVar5 = puVar1;
        for (; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
      }
      _free(*(void **)(param_1 + 0xc));
      *(undefined4 **)(param_1 + 0xc) = puVar1;
    }
    *(uint *)(param_1 + 4) = param_2;
    return;
  }
  _free(*(void **)(param_1 + 0xc));
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


// ==== 0x4fea10 FEVector3::operator__

/* [canon] hud med (ghidra-canon) docs/re/canon.md */

ushort __fastcall FEVector3__operator__(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  ushort uVar3;
  
  fVar1 = *param_1;
  fVar2 = *param_2 + 1e-06;
  uVar3 = (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
          (ushort)(fVar2 == fVar1) << 0xe;
  if (fVar2 >= fVar1) {
    fVar2 = *param_2 - 1e-06;
    uVar3 = (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
            (ushort)(fVar2 == fVar1) << 0xe;
    if (fVar2 < fVar1 != (fVar2 == fVar1)) {
      fVar1 = param_1[1];
      fVar2 = param_2[1] + 1e-06;
      uVar3 = (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
              (ushort)(fVar2 == fVar1) << 0xe;
      if (fVar2 >= fVar1) {
        fVar2 = param_2[1] - 1e-06;
        uVar3 = (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                (ushort)(fVar2 == fVar1) << 0xe;
        if (fVar2 < fVar1 != (fVar2 == fVar1)) {
          fVar1 = param_1[2];
          if ((fVar1 <= param_2[2] + 1e-06) &&
             (fVar2 = param_2[2] - 1e-06, fVar2 < fVar1 != (fVar2 == fVar1))) {
            return 1;
          }
          return 0;
        }
      }
    }
  }
  return uVar3;
}


// ==== 0x4feab0 FUN_004feab0

ushort __fastcall FUN_004feab0(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  ushort uVar3;
  
  fVar1 = *param_1;
  fVar2 = *param_2 + 1e-06;
  uVar3 = (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
          (ushort)(fVar2 == fVar1) << 0xe;
  if (fVar2 >= fVar1) {
    fVar2 = *param_2 - 1e-06;
    uVar3 = (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
            (ushort)(fVar2 == fVar1) << 0xe;
    if (fVar2 < fVar1 != (fVar2 == fVar1)) {
      fVar1 = param_1[1];
      fVar2 = param_2[1] + 1e-06;
      uVar3 = (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
              (ushort)(fVar2 == fVar1) << 0xe;
      if (fVar2 >= fVar1) {
        fVar2 = param_2[1] - 1e-06;
        uVar3 = (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                (ushort)(fVar2 == fVar1) << 0xe;
        if (fVar2 < fVar1 != (fVar2 == fVar1)) {
          fVar1 = param_1[2];
          if ((fVar1 <= param_2[2] + 1e-06) &&
             (fVar2 = param_2[2] - 1e-06, fVar2 < fVar1 != (fVar2 == fVar1))) {
            return 1;
          }
          return 0;
        }
      }
    }
  }
  return uVar3;
}


// ==== 0x4feb50 FEColor_NearlyEqual

/* [canon] hud med (ghidra-canon+hopper) docs/re/runtime.md */

uint __fastcall FEColor_NearlyEqual(int *param_1)

{
  int *in_EAX;
  
  if ((in_EAX[2] <= param_1[2] + 1) && (param_1[2] + -1 <= in_EAX[2])) {
    if ((in_EAX[1] <= param_1[1] + 1) && (param_1[1] + -1 <= in_EAX[1])) {
      if ((*in_EAX <= *param_1 + 1) && (*param_1 + -1 <= *in_EAX)) {
        if ((in_EAX[3] <= param_1[3] + 1) && (param_1[3] + -1 <= in_EAX[3])) {
          return 1;
        }
        return 0;
      }
    }
  }
  return (uint)in_EAX & 0xffffff00;
}


// ==== 0x4febb0 FEObject::FEObject

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void FEObject__FEObject(void)

{
  int iVar1;
  undefined4 *in_EAX;
  
  in_EAX[1] = 0xabadcafe;
  in_EAX[2] = 0xabadcafe;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  in_EAX[7] = 0;
  *(undefined2 *)(in_EAX + 8) = 0;
  in_EAX[9] = 0;
  in_EAX[10] = 0;
  in_EAX[0xb] = 0;
  in_EAX[0xc] = 0;
  *in_EAX = &PTR_FUN_006c1810;
  in_EAX[0xf] = 0;
  in_EAX[0x10] = 0;
  in_EAX[0xe] = 0;
  in_EAX[0xd] = &PTR_FUN_006c2c4c;
  in_EAX[0x13] = 0;
  in_EAX[0x14] = 0;
  in_EAX[0x12] = 0;
  in_EAX[0x11] = &PTR_FUN_006c2c4c;
  iVar1 = DAT_006f9fdc + 1;
  in_EAX[3] = DAT_006f9fdc;
  DAT_006f9fdc = iVar1;
  return;
}


// ==== 0x4fec10 FUN_004fec10

void * __thiscall FUN_004fec10(void *param_1,byte param_2)

{
  FUN_004fef10();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4fec30 FUN_004fec30

undefined4 * FUN_004fec30(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int local_14;
  int local_10;
  void *local_c;
  code *pcStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  pcStack_8 = FUN_00685ab6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[1] = 0xabadcafe;
  param_1[2] = 0xabadcafe;
  *param_1 = &PTR_FUN_006c1810;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[7] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xd] = &PTR_FUN_006c2c4c;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0xe] = 0;
  param_1[0x11] = &PTR_FUN_006c2c4c;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x12] = 0;
  iVar5 = DAT_006f9fdc + 1;
  param_1[3] = DAT_006f9fdc;
  DAT_006f9fdc = iVar5;
  uVar7 = *(uint *)(param_2 + 0x30);
  local_4 = 2;
  uStack_3 = 0;
  FUN_005033d0(&DAT_007460c8);
  param_1[0xb] = 0;
  puVar2 = (undefined4 *)FUN_00503330(&DAT_007460c8);
  param_1[0xc] = uVar7;
  param_1[0xb] = puVar2;
  for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  param_1[6] = *(undefined4 *)(param_2 + 0x18);
  param_1[7] = *(undefined4 *)(param_2 + 0x1c);
  *(undefined2 *)(param_1 + 8) = *(undefined2 *)(param_2 + 0x20);
  *(undefined2 *)((int)param_1 + 0x22) = *(undefined2 *)(param_2 + 0x22);
  param_1[9] = *(undefined4 *)(param_2 + 0x24);
  FEObject__SetName();
  for (iVar5 = *(int *)(param_2 + 0x3c); iVar5 != 0; iVar5 = *(int *)(iVar5 + 4)) {
    puVar2 = (undefined4 *)FUN_004fe570();
    puVar2[1] = 0xabadcafe;
    puVar2[2] = 0xabadcafe;
    *puVar2 = &PTR_FUN_006c181c;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    local_10 = *(int *)(iVar5 + 0x10);
    FUN_004fe3d0(puVar2,local_10);
    puVar2[3] = *(undefined4 *)(iVar5 + 0xc);
    if (local_10 != 0) {
      local_14 = 0;
      do {
        FUN_004fe260(*(int *)(iVar5 + 0x14) + local_14);
        local_14 = local_14 + 0xc;
        local_10 = local_10 + -1;
      } while (local_10 != 0);
    }
    iVar3 = param_1[0x10];
    if (iVar3 == 0) {
      iVar4 = param_1[0xf];
      puVar2[1] = iVar4;
      if (iVar4 != 0) {
        *(undefined4 **)(iVar4 + 8) = puVar2;
      }
      puVar2[2] = 0;
      param_1[0xf] = puVar2;
    }
    else {
      iVar4 = *(int *)(iVar3 + 4);
      puVar2[1] = iVar4;
      if (iVar4 != 0) {
        *(undefined4 **)(iVar4 + 8) = puVar2;
      }
      puVar2[2] = iVar3;
      *(undefined4 **)(iVar3 + 4) = puVar2;
    }
    if (param_1[0x10] == iVar3) {
      param_1[0x10] = puVar2;
    }
    param_1[0xe] = param_1[0xe] + 1;
  }
  for (iVar5 = *(int *)(param_2 + 0x4c); iVar5 != 0; iVar5 = *(int *)(iVar5 + 4)) {
    iVar3 = FUN_00502cd0();
    *(undefined4 *)(iVar3 + 0x2c) = 0;
    *(undefined4 *)(iVar3 + 0x30) = 0;
    *(undefined4 *)(iVar3 + 0xc) = 0;
    *(undefined4 *)(iVar3 + 0x14) = 0;
    *(undefined4 *)(iVar3 + 0x18) = 0;
    *(undefined4 *)(iVar3 + 0x1c) = 0;
    *(undefined4 *)(iVar3 + 0x20) = 0;
    local_4 = 3;
    iVar4 = FUN_00502970(iVar3,iVar5,param_3);
    iVar3 = param_1[0x14];
    local_4 = 2;
    if (iVar4 != 0) {
      if (iVar3 == 0) {
        iVar1 = param_1[0x13];
        *(int *)(iVar4 + 4) = iVar1;
        if (iVar1 != 0) {
          *(int *)(iVar1 + 8) = iVar4;
        }
        *(undefined4 *)(iVar4 + 8) = 0;
        param_1[0x13] = iVar4;
      }
      else {
        iVar1 = *(int *)(iVar3 + 4);
        *(int *)(iVar4 + 4) = iVar1;
        if (iVar1 != 0) {
          *(int *)(iVar1 + 8) = iVar4;
        }
        *(int *)(iVar4 + 8) = iVar3;
        *(int *)(iVar3 + 4) = iVar4;
      }
      if (param_1[0x14] == iVar3) {
        param_1[0x14] = iVar4;
      }
      param_1[0x12] = param_1[0x12] + 1;
    }
  }
  iVar5 = param_1[0x13];
  if (iVar5 != 0) {
    do {
      if (*(int *)(iVar5 + 0x30) == *(int *)(*(int *)(param_2 + 0x54) + 0x30)) break;
      iVar5 = *(int *)(iVar5 + 4);
    } while (iVar5 != 0);
  }
  param_1[0x15] = iVar5;
  if (iVar5 != 0) {
    FUN_004ff030(param_1);
  }
  iVar5 = *(int *)(param_2 + 0x4c);
  iVar3 = param_1[0x13];
  do {
    if (iVar5 == 0) {
      ExceptionList = local_c;
      return param_1;
    }
    if (*(int *)(iVar5 + 0x18) != 0) {
      iVar4 = param_1[0x13];
      if (iVar4 != 0) {
        do {
          if (*(int *)(iVar4 + 0x30) == *(int *)(*(int *)(iVar5 + 0x18) + 0x30)) break;
          iVar4 = *(int *)(iVar4 + 4);
        } while (iVar4 != 0);
      }
      *(int *)(iVar3 + 0x18) = iVar4;
    }
    iVar5 = *(int *)(iVar5 + 4);
    iVar3 = *(int *)(iVar3 + 4);
  } while( true );
}


// ==== 0x4fef10 FUN_004fef10

void __fastcall FUN_004fef10(undefined4 *param_1)

{
  void *pvStack_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_0068541e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c1810;
  local_4 = 2;
  if (DAT_0073577c != (undefined4 *)0x0) {
    (**(code **)*DAT_0073577c)(param_1);
  }
  FUN_005033d0(&DAT_007460c8);
  if ((void *)param_1[5] != (void *)0x0) {
    _free((void *)param_1[5]);
  }
  local_4._0_1_ = 1;
  param_1[0x11] = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  local_4 = (uint)local_4._1_3_ << 8;
  param_1[0xd] = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  *param_1 = &PTR_FUN_006c2c50;
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4fefb0 FEObject::SetName

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void FEObject__SetName(void)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  int unaff_ESI;
  char *unaff_EDI;
  
  if (*(void **)(unaff_ESI + 0x14) != (void *)0x0) {
    _free(*(void **)(unaff_ESI + 0x14));
    *(undefined4 *)(unaff_ESI + 0x14) = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x10) = 0xffffffff;
  if (unaff_EDI != (char *)0x0) {
    pcVar2 = unaff_EDI;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = _malloc((size_t)(pcVar2 + (1 - (int)(unaff_EDI + 1))));
    *(char **)(unaff_ESI + 0x14) = pcVar2;
    do {
      cVar1 = *unaff_EDI;
      unaff_EDI = unaff_EDI + 1;
      *pcVar2 = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    uVar3 = FEng__HashName();
    *(undefined4 *)(unaff_ESI + 0x10) = uVar3;
  }
  return;
}


// ==== 0x4ff010 FEObject::FindScript

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void __fastcall FEObject__FindScript(int param_1)

{
  int iVar1;
  int in_EAX;
  
  for (iVar1 = *(int *)(in_EAX + 0x4c); (iVar1 != 0 && (*(int *)(iVar1 + 0x30) != param_1));
      iVar1 = *(int *)(iVar1 + 4)) {
  }
  return;
}


// ==== 0x4ff030 FUN_004ff030

void FUN_004ff030(int param_1)

{
  int *piVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float fVar8;
  undefined4 *puVar9;
  int iVar10;
  float *pfVar11;
  
  iVar7 = param_1;
  piVar1 = (int *)(param_1 + 0x54);
  param_1 = *(int *)(*piVar1 + 0x1c);
  if (param_1 != 0) {
    pfVar11 = (float *)(*(int *)(*piVar1 + 0x20) + 0x1c);
    do {
      *(byte *)((int)pfVar11 + -0x19) = *(byte *)((int)pfVar11 + -0x19) & 0x7f;
      if ((*(char *)((int)pfVar11 + -0x1a) != '\x03') && (*(char *)((int)pfVar11 + -0x1a) != '\x04')
         ) goto switchD_004ff0a1_default;
      pfVar2 = (float *)(*(int *)(iVar7 + 0x2c) + *(char *)((int)pfVar11 + -0x15) * 4);
      if (*(char *)(pfVar11 + 4) == '\0') {
        fVar8 = pfVar11[5];
      }
      else {
        fVar8 = (float)FUN_004fc0e0();
      }
      if (fVar8 == 0.0) goto switchD_004ff0a1_default;
      switch(*(undefined1 *)(pfVar11 + -7)) {
      case 1:
        iVar10 = (int)*pfVar2 - (int)pfVar11[-1];
        goto LAB_004ff18a;
      case 2:
        *(float *)((int)fVar8 + 0x10) = *pfVar2 - pfVar11[-1];
        break;
      case 3:
        fVar3 = pfVar2[1];
        fVar4 = *pfVar11;
        *(float *)((int)fVar8 + 0x10) = *pfVar2 - pfVar11[-1];
        *(float *)((int)fVar8 + 0x14) = fVar3 - fVar4;
        break;
      case 4:
        fVar3 = pfVar2[1];
        fVar4 = *pfVar11;
        fVar5 = pfVar2[2];
        fVar6 = pfVar11[1];
        *(float *)((int)fVar8 + 0x10) = *pfVar2 - pfVar11[-1];
        *(float *)((int)fVar8 + 0x18) = fVar5 - fVar6;
        *(float *)((int)fVar8 + 0x14) = fVar3 - fVar4;
        break;
      case 5:
        puVar9 = (undefined4 *)FEQuaternion_Multiply();
        *(undefined4 *)((int)fVar8 + 0x10) = *puVar9;
        *(undefined4 *)((int)fVar8 + 0x14) = puVar9[1];
        *(undefined4 *)((int)fVar8 + 0x18) = puVar9[2];
        *(undefined4 *)((int)fVar8 + 0x1c) = puVar9[3];
        break;
      case 6:
        fVar3 = *pfVar11;
        fVar4 = pfVar2[1];
        fVar5 = pfVar2[3];
        iVar10 = (int)*pfVar2 - (int)pfVar11[-1];
        fVar6 = pfVar11[2];
        *(int *)((int)fVar8 + 0x18) = (int)pfVar2[2] - (int)pfVar11[1];
        *(int *)((int)fVar8 + 0x1c) = (int)fVar5 - (int)fVar6;
        *(int *)((int)fVar8 + 0x14) = (int)fVar4 - (int)fVar3;
LAB_004ff18a:
        *(int *)((int)fVar8 + 0x10) = iVar10;
      }
switchD_004ff0a1_default:
      pfVar11 = pfVar11 + 0xe;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}


// ==== 0x4ff1d0 FEObject::FindResponse

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void __fastcall FEObject__FindResponse(int param_1)

{
  int iVar1;
  int in_EAX;
  
  for (iVar1 = *(int *)(in_EAX + 0x3c); (iVar1 != 0 && (*(int *)(iVar1 + 0xc) != param_1));
      iVar1 = *(int *)(iVar1 + 4)) {
  }
  return;
}


// ==== 0x4ff1f0 FUN_004ff1f0

void FUN_004ff1f0(int param_1,int param_2,float *param_3,char param_4)

{
  int iVar1;
  float *pfVar2;
  uint uVar3;
  int extraout_ECX;
  int extraout_ECX_00;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x4c);
  do {
    if (iVar1 == 0) {
      if (param_4 != '\0') {
        iVar1 = FEObject__GetDataOffset(param_1);
        pfVar2 = (float *)(iVar1 + *(int *)(extraout_ECX + 0x2c));
        *pfVar2 = *(float *)(iVar1 + *(int *)(extraout_ECX + 0x2c)) + *param_3;
        pfVar2[1] = param_3[1] + pfVar2[1];
        pfVar2[2] = param_3[2] + pfVar2[2];
        return;
      }
      iVar1 = FEObject__GetDataOffset(param_1);
      pfVar2 = (float *)(iVar1 + *(int *)(extraout_ECX_00 + 0x2c));
      *pfVar2 = *param_3;
      pfVar2[1] = param_3[1];
      pfVar2[2] = param_3[2];
      return;
    }
    uVar3 = 0;
    if (*(uint *)(iVar1 + 0x1c) != 0) {
      iVar4 = *(int *)(iVar1 + 0x20) + 4;
      do {
        if ((int)*(char *)(iVar4 + 3) == *(int *)(&DAT_006b66e4 + param_2 * 4)) {
          iVar4 = uVar3 * 0x38 + *(int *)(iVar1 + 0x20);
          if (iVar4 != 0) {
            if (param_4 == '\0') {
              *(float *)(iVar4 + 0x18) = *param_3;
              *(float *)(iVar4 + 0x1c) = param_3[1];
              *(float *)(iVar4 + 0x20) = param_3[2];
            }
            else {
              *(float *)(iVar4 + 0x18) = *param_3 + *(float *)(iVar4 + 0x18);
              *(float *)(iVar4 + 0x1c) = param_3[1] + *(float *)(iVar4 + 0x1c);
              *(float *)(iVar4 + 0x20) = param_3[2] + *(float *)(iVar4 + 0x20);
            }
            *(byte *)(iVar4 + 3) = *(byte *)(iVar4 + 3) & 0x7f;
          }
          break;
        }
        uVar3 = uVar3 + 1;
        iVar4 = iVar4 + 0x38;
      } while (uVar3 < *(uint *)(iVar1 + 0x1c));
    }
    iVar1 = *(int *)(iVar1 + 4);
  } while( true );
}


// ==== 0x4ff2f0 FUN_004ff2f0

void FUN_004ff2f0(int param_1,int param_2,char param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int extraout_ECX;
  int extraout_ECX_00;
  int *unaff_ESI;
  int iVar5;
  
  iVar3 = *(int *)(param_1 + 0x4c);
  do {
    if (iVar3 == 0) {
      if (param_3 != '\0') {
        iVar1 = FEObject__GetDataOffset(param_1);
        iVar3 = *(int *)(extraout_ECX + 0x2c);
        iVar5 = *(int *)(iVar1 + 4 + iVar3);
        piVar2 = (int *)(iVar1 + iVar3);
        piVar2[2] = *(int *)(iVar1 + 8 + iVar3) + unaff_ESI[2];
        piVar2[1] = iVar5 + unaff_ESI[1];
        *piVar2 = *piVar2 + *unaff_ESI;
        piVar2[3] = piVar2[3] + unaff_ESI[3];
        return;
      }
      iVar3 = FEObject__GetDataOffset(param_1);
      piVar2 = (int *)(iVar3 + *(int *)(extraout_ECX_00 + 0x2c));
      piVar2[3] = unaff_ESI[3];
      piVar2[2] = unaff_ESI[2];
      piVar2[1] = unaff_ESI[1];
      *piVar2 = *unaff_ESI;
      return;
    }
    uVar4 = 0;
    if (*(uint *)(iVar3 + 0x1c) != 0) {
      iVar5 = *(int *)(iVar3 + 0x20) + 4;
      do {
        if ((int)*(char *)(iVar5 + 3) == *(int *)(&DAT_006b66e4 + param_2 * 4)) {
          iVar5 = uVar4 * 0x38 + *(int *)(iVar3 + 0x20);
          if (iVar5 != 0) {
            if (param_3 == '\0') {
              *(int *)(iVar5 + 0x24) = unaff_ESI[3];
              *(int *)(iVar5 + 0x20) = unaff_ESI[2];
              *(int *)(iVar5 + 0x1c) = unaff_ESI[1];
              *(int *)(iVar5 + 0x18) = *unaff_ESI;
            }
            else {
              *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + unaff_ESI[2];
              *(int *)(iVar5 + 0x1c) = *(int *)(iVar5 + 0x1c) + unaff_ESI[1];
              *(int *)(iVar5 + 0x18) = *(int *)(iVar5 + 0x18) + *unaff_ESI;
              *(int *)(iVar5 + 0x24) = *(int *)(iVar5 + 0x24) + unaff_ESI[3];
            }
            *(byte *)(iVar5 + 3) = *(byte *)(iVar5 + 3) & 0x7f;
          }
          break;
        }
        uVar4 = uVar4 + 1;
        iVar5 = iVar5 + 0x38;
      } while (uVar4 < *(uint *)(iVar3 + 0x1c));
    }
    iVar3 = *(int *)(iVar3 + 4);
  } while( true );
}


// ==== 0x4ff420 FUN_004ff420

void FUN_004ff420(int param_1,undefined4 *param_2,char param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint *puVar5;
  
  if (*(int *)(param_1 + 0x18) < 0x100) {
    iVar1 = *(int *)(param_1 + 0x4c);
    *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 0x400000;
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
      uVar2 = 0;
      if (*(uint *)(iVar1 + 0x1c) != 0) {
        puVar5 = (uint *)(*(int *)(iVar1 + 0x20) + 4);
        do {
          if ((*puVar5 & 0xff000000) == 0xa000000) {
            iVar3 = uVar2 * 0x38 + *(int *)(iVar1 + 0x20);
            if (iVar3 != 0) {
              if (param_3 == '\0') {
                *(undefined4 *)(iVar3 + 0x18) = *param_2;
                *(undefined4 *)(iVar3 + 0x1c) = param_2[1];
                *(undefined4 *)(iVar3 + 0x20) = param_2[2];
                *(undefined4 *)(iVar3 + 0x24) = param_2[3];
              }
              else {
                puVar4 = (undefined4 *)FEQuaternion_Multiply();
                *(undefined4 *)(iVar3 + 0x18) = *puVar4;
                *(undefined4 *)(iVar3 + 0x1c) = puVar4[1];
                *(undefined4 *)(iVar3 + 0x20) = puVar4[2];
                *(undefined4 *)(iVar3 + 0x24) = puVar4[3];
              }
              *(byte *)(iVar3 + 3) = *(byte *)(iVar3 + 3) & 0x7f;
            }
            break;
          }
          uVar2 = uVar2 + 1;
          puVar5 = puVar5 + 0xe;
        } while (uVar2 < *(uint *)(iVar1 + 0x1c));
      }
    }
    if (param_3 != '\0') {
      iVar1 = *(int *)(param_1 + 0x2c);
      puVar4 = (undefined4 *)FEQuaternion_Multiply();
      *(undefined4 *)(iVar1 + 0x28) = *puVar4;
      *(undefined4 *)(iVar1 + 0x2c) = puVar4[1];
      *(undefined4 *)(iVar1 + 0x30) = puVar4[2];
      *(undefined4 *)(iVar1 + 0x34) = puVar4[3];
      return;
    }
    iVar1 = *(int *)(param_1 + 0x2c);
    *(undefined4 *)(iVar1 + 0x28) = *param_2;
    *(undefined4 *)(iVar1 + 0x2c) = param_2[1];
    *(undefined4 *)(iVar1 + 0x30) = param_2[2];
    *(undefined4 *)(iVar1 + 0x34) = param_2[3];
  }
  return;
}


// ==== 0x4ff560 FEObject::GetDataOffset

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

undefined4 FEObject__GetDataOffset(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  default:
    return 0;
  case 1:
    return 0x10;
  case 2:
    return 0x1c;
  case 3:
    return 0x28;
  case 4:
    return 0x38;
  case 5:
    return 0x44;
  case 6:
    return 0x4c;
  case 7:
    return 0x54;
  case 8:
    return 100;
  case 9:
    return 0x74;
  case 10:
    return 0x84;
  }
}


// ==== 0x4ff5f0 FUN_004ff5f0

undefined4 __thiscall FUN_004ff5f0(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = _malloc(0x58);
  uStack_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_004fec30(pvVar1,param_1,param_2);
    ExceptionList = pvStack_c;
    return uVar2;
  }
  ExceptionList = pvStack_c;
  return 0;
}


// ==== 0x4ff660 FUN_004ff660

void FUN_004ff660(void)

{
  undefined4 *in_EAX;
  
  _free((void *)*in_EAX);
  return;
}


// ==== 0x4ff670 FUN_004ff670

void __fastcall FUN_004ff670(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0xffffffff;
  param_1[2] = 0;
  return;
}


// ==== 0x4ff690 FEListBox::SetCurrentColumn

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void __fastcall FEListBox__SetCurrentColumn(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x5c);
  if (uVar1 == 0) {
    *(undefined4 *)(param_1 + 0x84) = 0;
    return;
  }
  if (uVar1 <= param_2) {
    *(uint *)(param_1 + 0x84) = uVar1 - 1;
    return;
  }
  *(uint *)(param_1 + 0x84) = param_2;
  return;
}


// ==== 0x4ff6c0 FEListBox::SetCurrentRow

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void __fastcall FEListBox__SetCurrentRow(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x60);
  if (uVar1 == 0) {
    *(undefined4 *)(param_1 + 0x88) = 0;
    return;
  }
  if (uVar1 <= param_2) {
    *(uint *)(param_1 + 0x88) = uVar1 - 1;
    return;
  }
  *(uint *)(param_1 + 0x88) = param_2;
  return;
}


// ==== 0x4ff6f0 FEListBox::SetCellResource

/* [canon] hud med (ghidra-canon+hopper) docs/re/hud.md */

void __thiscall
FEListBox__SetCellResource(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           ((*(int *)(param_1 + 0x88) * *(int *)(param_1 + 0x5c) + *(int *)(param_1 + 0x84)) * 0x30
            + 0xc + *(int *)(param_1 + 0x8c));
  *puVar1 = param_2;
  puVar1[1] = param_3;
  puVar1[2] = param_4;
  return;
}


// ==== 0x4ff730 FUN_004ff730

undefined4 FUN_004ff730(int param_1)

{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 0x4c); (iVar1 != 0 && (*(int *)(iVar1 + 0x30) != 0x1744b3));
      iVar1 = *(int *)(iVar1 + 4)) {
  }
  *(int *)(param_1 + 0x54) = iVar1;
  if (iVar1 != 0) {
    FUN_004ff030(param_1);
  }
  iVar1 = *(int *)(param_1 + 0x54);
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 0x3c00000;
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


// ==== 0x4ff780 FEPackage::FEPackage

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void FEPackage__FEPackage(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006c17f4;
  in_EAX[1] = 0xabadcafe;
  in_EAX[2] = 0xabadcafe;
  in_EAX[3] = 0;
  in_EAX[4] = 0;
  in_EAX[0x10] = 0;
  in_EAX[0x11] = 0;
  in_EAX[0xf] = 0;
  in_EAX[0xe] = &PTR_FUN_006c2c4c;
  in_EAX[0x12] = &PTR_FUN_006c2c4c;
  in_EAX[0x14] = 0;
  in_EAX[0x15] = 0;
  in_EAX[0x13] = 0;
  in_EAX[0x1c] = 0;
  in_EAX[0x1d] = 0;
  in_EAX[0x1b] = 0;
  in_EAX[0x1a] = &PTR_FUN_006c2c48;
  in_EAX[0x21] = 0;
  in_EAX[0x22] = 0;
  in_EAX[0x24] = &PTR_FUN_006c2c4c;
  in_EAX[0x26] = 0;
  in_EAX[0x27] = 0;
  in_EAX[0x25] = 0;
  in_EAX[7] = 0xff;
  *(undefined1 *)(in_EAX + 5) = 0;
  *(undefined1 *)((int)in_EAX + 0x15) = 0;
  *(undefined1 *)((int)in_EAX + 0x16) = 0;
  *(undefined1 *)((int)in_EAX + 0x17) = 0;
  in_EAX[6] = 0;
  in_EAX[0xb] = 0;
  in_EAX[0xc] = 0;
  in_EAX[0xd] = 0;
  in_EAX[0x16] = 0;
  in_EAX[0x17] = 0;
  in_EAX[0x18] = 0;
  in_EAX[0x19] = 0;
  in_EAX[0x20] = 0;
  in_EAX[0x23] = 0;
  in_EAX[0x1e] = 0;
  in_EAX[0x1f] = 0;
  return;
}


// ==== 0x4ff830 FUN_004ff830

void * __thiscall FUN_004ff830(void *param_1,byte param_2)

{
  FUN_004ff850(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4ff850 FUN_004ff850

void FUN_004ff850(undefined4 *param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  void *pvStack_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_006853f4;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c17f4;
  local_4 = 5;
  _free((void *)param_1[0xb]);
  if ((void *)param_1[0x17] != (void *)0x0) {
    _free((void *)param_1[0x17]);
  }
  pvVar1 = (void *)param_1[0x19];
  if (pvVar1 != (void *)0x0) {
    eh_vector_destructor_iterator(pvVar1,0x10,*(int *)((int)pvVar1 + -4),FUN_004fe970);
    _free((void *)((int)pvVar1 + -4));
  }
  if ((void *)param_1[0x23] != (void *)0x0) {
    _free((void *)param_1[0x23]);
  }
  puVar2 = (undefined4 *)0x0;
  if (param_1[0x26] != 0) {
    puVar2 = (undefined4 *)FUN_004ee670();
  }
  while (puVar2 != (undefined4 *)0x0) {
    _free((void *)puVar2[4]);
    (**(code **)*puVar2)(1);
    puVar2 = (undefined4 *)param_1[0x26];
    if (puVar2 != (undefined4 *)0x0) {
      param_1[0x26] = puVar2[1];
      if (puVar2 == (undefined4 *)param_1[0x27]) {
        param_1[0x27] = puVar2[2];
      }
      if (puVar2[2] != 0) {
        *(undefined4 *)(puVar2[2] + 4) = puVar2[1];
      }
      if (puVar2[1] != 0) {
        *(undefined4 *)(puVar2[1] + 8) = puVar2[2];
      }
      puVar2[1] = 0xabadcafe;
      puVar2[2] = 0xabadcafe;
      param_1[0x25] = param_1[0x25] + -1;
    }
  }
  if ((void *)param_1[0x1f] != (void *)0x0) {
    _free((void *)param_1[0x1f]);
  }
  local_4._0_1_ = 4;
  param_1[0x24] = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  _free((void *)param_1[0x21]);
  local_4._0_1_ = 2;
  param_1[0x1a] = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  local_4._0_1_ = 1;
  param_1[0x12] = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  local_4 = (uint)local_4._1_3_ << 8;
  param_1[0xe] = &PTR_FUN_006c2c4c;
  FUN_004ee5e0();
  *param_1 = &PTR_FUN_006c1828;
  if ((void *)param_1[3] != (void *)0x0) {
    _free((void *)param_1[3]);
  }
  *param_1 = &PTR_FUN_006c2c50;
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4ff9e0 FUN_004ff9e0

void FUN_004ff9e0(void)

{
  char cVar1;
  char *pcVar2;
  char *unaff_ESI;
  int unaff_EDI;
  
  _free(*(void **)(unaff_EDI + 0x2c));
  *(undefined4 *)(unaff_EDI + 0x2c) = 0;
  if (unaff_ESI != (char *)0x0) {
    pcVar2 = unaff_ESI;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = _malloc((size_t)(pcVar2 + (1 - (int)(unaff_ESI + 1))));
    *(char **)(unaff_EDI + 0x2c) = pcVar2;
    do {
      cVar1 = *unaff_ESI;
      unaff_ESI = unaff_ESI + 1;
      *pcVar2 = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
  }
  return;
}


// ==== 0x4ffa30 FUN_004ffa30

bool __fastcall FUN_004ffa30(int *param_1)

{
  char cVar1;
  undefined4 unaff_ESI;
  
  cVar1 = (**(code **)(*param_1 + 4))();
  FUN_00500500(unaff_ESI);
  return cVar1 != '\0';
}


// ==== 0x4ffa60 FUN_004ffa60

void FUN_004ffa60(undefined4 param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685398;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_004ffb00(param_1);
  ExceptionList = local_c;
  return;
}


// ==== 0x4ffab0 FUN_004ffab0

undefined4 FUN_004ffab0(int param_1,int *param_2)

{
  int iVar1;
  char cVar2;
  
  iVar1 = *(int *)(param_1 + 0x60);
  while( true ) {
    if (iVar1 == 0) {
      return 1;
    }
    cVar2 = (**(code **)(*param_2 + 4))(iVar1);
    if ((cVar2 == '\0') ||
       ((*(int *)(iVar1 + 0x18) == 5 && (cVar2 = FUN_004ffab0(iVar1,param_2), cVar2 == '\0'))))
    break;
    iVar1 = *(int *)(iVar1 + 4);
  }
  return 0;
}


// ==== 0x4ffb00 FUN_004ffb00

undefined4 FUN_004ffb00(int param_1)

{
  int iVar1;
  char cVar2;
  int *unaff_EDI;
  
  iVar1 = *(int *)(param_1 + 0x40);
  while( true ) {
    if (iVar1 == 0) {
      return 1;
    }
    cVar2 = (**(code **)(*unaff_EDI + 4))(iVar1);
    if ((cVar2 == '\0') ||
       ((*(int *)(iVar1 + 0x18) == 5 && (cVar2 = FUN_004ffab0(iVar1,unaff_EDI), cVar2 == '\0'))))
    break;
    iVar1 = *(int *)(iVar1 + 4);
  }
  return 0;
}


// ==== 0x4ffb50 FEFindByHash::Callback

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

undefined4 __thiscall FEFindByHash__Callback(int param_1,int param_2)

{
  if (*(int *)(param_2 + 0x10) == *(int *)(param_1 + 4)) {
    *(int *)(param_1 + 8) = param_2;
    return 0;
  }
  return 1;
}


// ==== 0x4ffb70 FUN_004ffb70

undefined4 __fastcall FUN_004ffb70(undefined4 param_1,undefined4 param_2)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006858b8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_004ffb00(param_2);
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4ffbc0 FEFindByGUID::Callback

/* [canon] hud high (ghidra-canon+mw) docs/re/hud.md */

undefined4 __thiscall FEFindByGUID__Callback(int param_1,int param_2)

{
  if (*(int *)(param_2 + 0xc) == *(int *)(param_1 + 4)) {
    *(int *)(param_1 + 8) = param_2;
    return 0;
  }
  return 1;
}


// ==== 0x4ffbe0 FUN_004ffbe0

undefined4 __fastcall FUN_004ffbe0(undefined4 param_1,undefined4 param_2)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006858b8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_004ffb00(param_2);
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4ffc30 FUN_004ffc30

void __fastcall FUN_004ffc30(uint param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int in_EAX;
  uint *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int unaff_ESI;
  
  iVar1 = *(int *)(in_EAX + 0x24);
  if ((int)param_1 <= (int)param_4) {
    if (param_4 == *(uint *)(in_EAX + 0xc)) {
      param_4 = param_4 + 1;
    }
    iVar7 = 0;
    if (0 < iVar1) {
      puVar3 = (uint *)(*(int *)(in_EAX + 0x28) + 8);
      while (*puVar3 < param_1) {
        iVar7 = iVar7 + 1;
        puVar3 = puVar3 + 3;
        if (iVar1 <= iVar7) {
          return;
        }
      }
      if (iVar7 < iVar1) {
        piVar8 = (int *)(*(int *)(in_EAX + 0x28) + iVar7 * 0xc);
        do {
          if (param_4 <= (uint)piVar8[2]) {
            return;
          }
          uVar2 = piVar8[1];
          if (uVar2 < 0xfffffffc) {
            if (uVar2 == 0xfffffffb) {
              iVar4 = *piVar8;
              uVar5 = 0xfffffffb;
            }
            else if (uVar2 == 0) {
              iVar4 = *piVar8;
              if (iVar4 == 0x1b3909aa) {
                iVar4 = FUN_004ffbe0();
                if (*(int *)(unaff_ESI + 0x80) != 0) {
                  FUN_004f0700(0x55d1e635,0,unaff_ESI,*(int *)(unaff_ESI + 0x80),0);
                  FUN_004f0700(0x55d1e635,*(undefined4 *)(unaff_ESI + 0x80),unaff_ESI,0xfffffffb,0);
                }
                if (iVar4 != 0) {
                  FUN_004f0700(0xabc08912,0,unaff_ESI,iVar4,0);
                  FUN_004f0700(0xabc08912,iVar4,unaff_ESI,0xfffffffb,0);
                }
LAB_004ffd45:
                *(int *)(unaff_ESI + 0x80) = iVar4;
                goto LAB_004ffe49;
              }
              uVar5 = 0;
            }
            else {
              if (uVar2 != 0xfffffffa) goto LAB_004ffd89;
              iVar4 = *piVar8;
              uVar5 = 0xfffffffa;
            }
LAB_004ffe44:
            FUN_004f0700(iVar4,param_3,unaff_ESI,uVar5,0);
          }
          else {
            if (uVar2 == 0xfffffffc) {
              iVar4 = *piVar8;
              uVar5 = 0xfffffffc;
              goto LAB_004ffe44;
            }
            if (uVar2 == 0xffffffff) {
              (**(code **)(**(int **)(param_2 + 0x10c) + 0x18))(*piVar8,param_3,0);
            }
            else {
LAB_004ffd89:
              uVar5 = FUN_004ffbe0();
              iVar4 = *piVar8;
              if (iVar4 == 0x1b3909aa) {
                iVar6 = FUN_004ffbe0();
                if (*(int *)(unaff_ESI + 0x80) != 0) {
                  FUN_004f0700(0x55d1e635,0,unaff_ESI,*(int *)(unaff_ESI + 0x80),0);
                  FUN_004f0700(0x55d1e635,*(undefined4 *)(unaff_ESI + 0x80),unaff_ESI,0xfffffffb,0);
                }
                iVar4 = 0;
                if (iVar6 == 0) goto LAB_004ffd45;
                FUN_004f0700(0xabc08912,0,unaff_ESI,iVar6,0);
                FUN_004f0700(0xabc08912,iVar6,unaff_ESI,0xfffffffb,0);
                *(int *)(unaff_ESI + 0x80) = iVar6;
              }
              else if (param_3 != 0) goto LAB_004ffe44;
            }
          }
LAB_004ffe49:
          iVar7 = iVar7 + 1;
          piVar8 = piVar8 + 3;
        } while (iVar7 < iVar1);
      }
    }
  }
  return;
}


// ==== 0x4ffe70 FUN_004ffe70

void FUN_004ffe70(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int unaff_EDI;
  
  for (iVar1 = *(int *)(unaff_EDI + 0x60); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
    FUN_004ffeb0(iVar1,param_2);
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | *(uint *)(unaff_EDI + 0x1c) & 0x3c00000;
  }
  return;
}


// ==== 0x4ffeb0 FUN_004ffeb0

void __thiscall FUN_004ffeb0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = *(uint *)(param_2 + 0x1c);
  if ((uVar4 & 0x1c00000) == 0) {
    *(uint *)(param_2 + 0x1c) = (DAT_006f89ec | 0xfdffffff) & uVar4;
  }
  else {
    *(uint *)(param_2 + 0x1c) = uVar4 | 0x2000000;
  }
  iVar5 = *(int *)(param_2 + 0x54);
  iVar1 = *(int *)(iVar5 + 0x10);
  iVar2 = *(int *)(iVar5 + 0xc);
  iVar3 = *(int *)(param_1 + 0x28) + iVar1;
  *(int *)(iVar5 + 0x10) = iVar3;
  if (iVar3 < 0) {
    *(undefined4 *)(iVar5 + 0x10) = 0;
  }
  iVar3 = *(int *)(iVar5 + 0x10);
  if (iVar3 < iVar2) {
    if ((*(char *)(param_1 + 0x14) == '\0') || (*(int *)(iVar5 + 0x24) == 0)) goto LAB_0050008b;
    uVar4 = *(uint *)(iVar5 + 0x14) & 3;
    if (uVar4 != 0) {
      if (uVar4 == 1) {
        if (iVar3 < iVar1) {
          FUN_004ffc30(param_2,iVar2);
          iVar3 = *(int *)(iVar5 + 0x10);
        }
      }
      else {
        if (uVar4 != 2) goto LAB_0050008b;
        if (iVar1 < iVar2) {
          if (iVar2 <= iVar3) {
            FUN_004ffc30(param_2,iVar2);
            iVar3 = *(int *)(iVar5 + 0x10) - iVar2;
          }
        }
        else if (iVar3 < iVar2) {
          FUN_004ffc30(param_2,0);
          iVar3 = *(int *)(iVar5 + 0x10);
        }
        else {
          iVar3 = iVar3 - iVar2;
        }
      }
    }
  }
  else {
    if (*(char *)(param_1 + 0x14) == '\0') goto LAB_0050008b;
    if (*(int *)(iVar5 + 0x18) == 0) {
      uVar4 = *(uint *)(iVar5 + 0x14) & 3;
      if (uVar4 == 0) {
        if (*(int *)(iVar5 + 0x24) != 0) {
          FUN_004ffc30(param_2,iVar2);
        }
        *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0xc) + 1;
        goto LAB_0050008b;
      }
      if (uVar4 == 1) {
        if (0 < iVar2) {
          if (*(int *)(iVar5 + 0x24) != 0) {
            FUN_004ffc30(param_2,iVar2);
          }
          iVar3 = *(int *)(iVar5 + 0x10) % *(int *)(iVar5 + 0xc);
          *(int *)(iVar5 + 0x10) = iVar3;
          if (*(int *)(iVar5 + 0x24) != 0) {
            FUN_004ffc30(param_2,iVar3);
          }
          FUN_004ff030(param_2);
          goto LAB_0050008b;
        }
      }
      else {
        if (uVar4 != 2) goto LAB_0050008b;
        if (0 < iVar2) {
          *(int *)(iVar5 + 0x10) = iVar3 % (iVar2 * 2);
          goto LAB_0050008b;
        }
      }
      *(undefined4 *)(iVar5 + 0x10) = 0;
      goto LAB_0050008b;
    }
    FUN_005001b0(param_2);
    iVar3 = *(int *)(iVar5 + 0x10) - iVar2;
    *(undefined4 *)(iVar5 + 0x10) = 0;
    if (*(int *)(iVar5 + 0x24) != 0) {
      FUN_004ffc30(param_2,iVar2);
    }
    iVar5 = *(int *)(iVar5 + 0x18);
    *(int *)(param_2 + 0x54) = iVar5;
    if (iVar5 != 0) {
      FUN_004ff030(param_2);
    }
    *(int *)(iVar5 + 0x10) = iVar3;
    if (*(int *)(iVar5 + 0x24) == 0) goto LAB_0050008b;
  }
  FUN_004ffc30(param_2,iVar3);
LAB_0050008b:
  if ((((*(char *)(param_1 + 0x14) == '\0') || (iVar1 != *(int *)(iVar5 + 0x10))) ||
      (iVar1 != *(int *)(iVar5 + 0xc) + 1)) || ((*(uint *)(param_2 + 0x1c) & 0x400000) != 0)) {
    FUN_005001b0(param_2);
  }
  switch(*(undefined4 *)(param_2 + 0x18)) {
  case 4:
    FUN_004fdc20((float)param_3);
    break;
  case 5:
    FUN_004ffe70(param_1,param_3);
    break;
  case 6:
    FUN_004faf70((float)param_3);
    break;
  case 7:
    if (*(char *)(param_1 + 0x14) != '\0') {
      *(int *)(param_2 + 0x58) = *(int *)(param_2 + 0x58) + param_3;
    }
  }
  uVar4 = DAT_006f89ec;
  if (((*(char *)(param_1 + 0x14) == '\x01') && (iVar1 == *(int *)(iVar5 + 0x10))) &&
     ((iVar1 == *(int *)(iVar5 + 0xc) + 1 && ((*(uint *)(param_2 + 0x1c) & 0x400000) == 0)))) {
    *(uint *)(param_2 + 0x1c) = (DAT_006f89ec | 0xfe7fffff) & *(uint *)(param_2 + 0x1c);
  }
  uVar4 = *(uint *)(param_2 + 0x1c) & (uVar4 | 0xffbfffff);
  *(uint *)(param_2 + 0x1c) = uVar4;
  if ((uVar4 & 0x1c00000) != 0) {
    *(uint *)(param_2 + 0x1c) = uVar4 | 0x2000000;
  }
  return;
}


// ==== 0x5001b0 FUN_005001b0

void __thiscall FUN_005001b0(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int in_EAX;
  uint uVar6;
  int iVar7;
  
  uVar6 = DAT_006f89ec;
  iVar4 = *(int *)(param_2 + 0x2c);
  uVar5 = *(undefined4 *)(param_1 + 0x10);
  iVar7 = *(int *)(param_1 + 0x20);
  if (*(char *)(in_EAX + 0x14) == '\0') {
    if ((iVar7 != 0) && ((*(uint *)(iVar7 + 4) & 0xff000000) == 0)) {
      cVar3 = *(char *)(iVar7 + 2);
      if (cVar3 == '\0') {
        FUN_004fc9a0(uVar5,iVar4);
      }
      else if ((cVar3 == '\x01') || (cVar3 == '\x03')) {
        FUN_004fc100(iVar7,uVar5,iVar4);
      }
    }
    if ((*(int *)(*(int *)(param_2 + 0x2c) + 0xc) != 0) && (*(byte *)(param_1 + 0x1c) != 0)) {
      uVar6 = (uint)*(byte *)(param_1 + 0x1c);
      do {
        cVar3 = *(char *)(iVar7 + 2);
        iVar1 = iVar4 + *(char *)(iVar7 + 7) * 4;
        if (cVar3 == '\0') {
          FUN_004fc9a0(uVar5,iVar1);
        }
        else if ((cVar3 == '\x01') || (cVar3 == '\x03')) {
          FUN_004fc100(iVar7,uVar5,iVar1);
        }
        iVar7 = iVar7 + 0x38;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
  }
  else {
    if ((iVar7 == 0) || ((*(uint *)(iVar7 + 4) & 0xff000000) != 0)) {
      *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) & (DAT_006f89ec | 0xff7fffff);
    }
    else {
      if (*(char *)(iVar7 + 3) < '\0') {
        uVar6 = *(uint *)(param_2 + 0x1c) & (DAT_006f89ec | 0xff7fffff);
      }
      else {
        uVar6 = *(uint *)(param_2 + 0x1c) | 0x800000;
      }
      *(uint *)(param_2 + 0x1c) = uVar6;
      FUN_004fbf60();
      uVar6 = DAT_006f89ec;
    }
    bVar2 = 0x80;
    if ((*(int *)(*(int *)(param_2 + 0x2c) + 0xc) != 0) && (*(byte *)(param_1 + 0x1c) != 0)) {
      uVar6 = (uint)*(byte *)(param_1 + 0x1c);
      do {
        if (*(char *)(iVar7 + 7) < '\x10') {
          bVar2 = bVar2 & *(byte *)(iVar7 + 3);
        }
        FUN_004fbf60();
        iVar7 = iVar7 + 0x38;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
      uVar6 = DAT_006f89ec;
      if (bVar2 == 0) {
        *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 0x1000000;
        goto LAB_0050032c;
      }
    }
    *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) & (uVar6 | 0xfeffffff);
  }
LAB_0050032c:
  if ((*(uint *)(param_2 + 0x1c) & 0x1c00000) != 0) {
    *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 0x2000000;
  }
  return;
}


// ==== 0x500350 FUN_00500350

void FUN_00500350(int param_1)

{
  char in_AL;
  int unaff_ESI;
  
  if (in_AL != '\0') {
    if (*(int *)(unaff_ESI + 0x80) != 0) {
      FUN_004f0700(0x55d1e635,0,unaff_ESI,*(int *)(unaff_ESI + 0x80),0);
      FUN_004f0700(0x55d1e635,*(undefined4 *)(unaff_ESI + 0x80),unaff_ESI,0xfffffffb,0);
    }
    if (param_1 != 0) {
      FUN_004f0700(0xabc08912,0,unaff_ESI,param_1,0);
      FUN_004f0700(0xabc08912,param_1,unaff_ESI,0xfffffffb,0);
    }
  }
  *(int *)(unaff_ESI + 0x80) = param_1;
  return;
}


// ==== 0x5003c0 FUN_005003c0

undefined4 __thiscall FUN_005003c0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x18);
  if (iVar1 == 4) {
    ResourceConnector__ConnectListBoxResources(param_1);
  }
  else if (((iVar1 != 5) && (iVar1 != 6)) && (*(ushort *)(param_2 + 0x22) != 0xffff)) {
    iVar1 = (uint)*(ushort *)(param_2 + 0x22) * 0x18;
    *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(**(int **)(param_1 + 8) + 0x14 + iVar1);
    *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(**(int **)(param_1 + 8) + 0x10 + iVar1);
    return 1;
  }
  return 1;
}


// ==== 0x500410 ResourceConnector::ConnectListBoxResources

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void ResourceConnector__ConnectListBoxResources(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int in_EAX;
  int iVar8;
  uint uVar9;
  
  uVar2 = *(uint *)(in_EAX + 0x5c);
  *(undefined4 *)(in_EAX + 0x84) = 0;
  iVar3 = *(int *)(in_EAX + 0x60);
  *(undefined4 *)(in_EAX + 0x88) = 0;
  uVar6 = uVar2;
  for (; uVar7 = uVar2, iVar3 != 0; iVar3 = iVar3 + -1) {
    for (; uVar7 != 0; uVar7 = uVar7 - 1) {
      iVar8 = (*(int *)(in_EAX + 0x88) * uVar6 + *(int *)(in_EAX + 0x84)) * 0x30 +
              *(int *)(in_EAX + 0x8c);
      iVar4 = *(int *)(iVar8 + 0x14);
      if (iVar4 == -1) {
        *(undefined4 *)(iVar8 + 0xc) = 0;
        *(undefined4 *)(iVar8 + 0x10) = 0;
        *(undefined4 *)(iVar8 + 0x14) = 0xffffffff;
      }
      else {
        iVar1 = **(int **)(param_1 + 8) + iVar4 * 0x18;
        uVar5 = *(undefined4 *)(iVar1 + 0x14);
        *(undefined4 *)(iVar8 + 0xc) = *(undefined4 *)(iVar1 + 0x10);
        *(undefined4 *)(iVar8 + 0x10) = uVar5;
        *(int *)(iVar8 + 0x14) = iVar4;
      }
      uVar6 = *(uint *)(in_EAX + 0x5c);
      uVar9 = *(int *)(in_EAX + 0x84) + 1;
      *(uint *)(in_EAX + 0x84) = uVar9;
      if (uVar6 <= uVar9) {
        uVar9 = *(int *)(in_EAX + 0x88) + 1;
        *(undefined4 *)(in_EAX + 0x84) = 0;
        *(uint *)(in_EAX + 0x88) = uVar9;
        if (*(uint *)(in_EAX + 0x60) <= uVar9) {
          *(undefined4 *)(in_EAX + 0x88) = 0;
        }
      }
    }
  }
  return;
}


// ==== 0x500500 FUN_00500500

void FUN_00500500(undefined4 param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006858b8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_004ffb00(param_1);
  ExceptionList = local_c;
  return;
}


// ==== 0x500560 FUN_00500560

void FUN_00500560(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006c2c5c;
  return;
}


// ==== 0x500570 FUN_00500570

void FUN_00500570(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  uVar1 = (uint)param_2;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684b48;
  local_c = ExceptionList;
  if (param_2 == (undefined4 *)0x0) {
    if (*(void **)(param_1 + 0x7c) != (void *)0x0) {
      ExceptionList = &local_c;
      _free(*(void **)(param_1 + 0x7c));
    }
    *(undefined4 *)(param_1 + 0x7c) = 0;
  }
  else {
    ExceptionList = &local_c;
    puVar2 = _malloc((int)param_2 * 0xc);
    local_4 = 0;
    if (puVar2 == (undefined4 *)0x0) {
      param_2 = (undefined4 *)0x0;
    }
    else {
      CallNTimes(puVar2,0xc,param_2,FUN_004ff670);
      param_2 = puVar2;
    }
    uVar3 = uVar1;
    if (*(uint *)(param_1 + 0x78) < uVar1) {
      uVar3 = *(uint *)(param_1 + 0x78);
    }
    if (uVar3 != 0) {
      puVar2 = *(undefined4 **)(param_1 + 0x7c);
      puVar5 = param_2;
      for (uVar3 = uVar3 * 3 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar5 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar5 = puVar5 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar5 = *(undefined1 *)puVar2;
        puVar2 = (undefined4 *)((int)puVar2 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
    }
    if (*(void **)(param_1 + 0x7c) != (void *)0x0) {
      _free(*(void **)(param_1 + 0x7c));
    }
    *(undefined4 **)(param_1 + 0x7c) = param_2;
    *(uint *)(param_1 + 0x78) = uVar1;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x500640 FUN_00500640

void __fastcall FUN_00500640(int param_1)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar2 = *(int *)(unaff_ESI + 0xc);
  if (iVar2 != 0) {
    do {
      if (*(int *)(iVar2 + 0x18) <= *(int *)(param_1 + 0x18)) break;
      iVar2 = *(int *)(iVar2 + 8);
    } while (iVar2 != 0);
  }
  if (param_1 != 0) {
    if (iVar2 == 0) {
      iVar1 = *(int *)(unaff_ESI + 8);
      *(int *)(param_1 + 4) = iVar1;
      if (iVar1 != 0) {
        *(int *)(iVar1 + 8) = param_1;
      }
      *(undefined4 *)(param_1 + 8) = 0;
      *(int *)(unaff_ESI + 8) = param_1;
    }
    else {
      iVar1 = *(int *)(iVar2 + 4);
      *(int *)(param_1 + 4) = iVar1;
      if (iVar1 != 0) {
        *(int *)(iVar1 + 8) = param_1;
      }
      *(int *)(param_1 + 8) = iVar2;
      *(int *)(iVar2 + 4) = param_1;
    }
    if (*(int *)(unaff_ESI + 0xc) == iVar2) {
      *(int *)(unaff_ESI + 0xc) = param_1;
    }
    *(int *)(unaff_ESI + 4) = *(int *)(unaff_ESI + 4) + 1;
  }
  return;
}


// ==== 0x5006a0 FETypeNode::GetFieldAt

/* [canon] hud med (ghidra-canon+hopper) docs/re/hud.md */

void __fastcall FETypeNode__GetFieldAt(undefined4 param_1,int param_2)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  
  iVar1 = *(int *)(in_EAX + 0x1c);
  for (iVar2 = 0; (iVar1 != 0 && (iVar2 != param_2)); iVar2 = iVar2 + 1) {
    iVar1 = *(int *)(iVar1 + 4);
  }
  return;
}


// ==== 0x5006c0 FUN_005006c0

undefined4 * __thiscall FUN_005006c0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006c17bc;
  if (*(char *)(param_1 + 1) == '\0') {
    FUN_004fca20();
  }
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5006f0 FEKeyTrack::FEKeyTrack

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void __fastcall FEKeyTrack__FEKeyTrack(undefined1 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xff000000;
  param_1[7] = 0;
  *(undefined4 *)(param_1 + 0xc) = 0xabadcafe;
  *(undefined4 *)(param_1 + 0x10) = 0xabadcafe;
  *(undefined ***)(param_1 + 8) = &PTR_FUN_006c1830;
  *(undefined ***)(param_1 + 0x28) = &PTR_FUN_006c17bc;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  param_1[0x2c] = 0;
  return;
}


// ==== 0x500740 FUN_00500740

void FUN_00500740(void)

{
  int unaff_ESI;
  
  _free(*(void **)(unaff_ESI + 4));
  *(undefined4 *)(unaff_ESI + 4) = 0;
  return;
}


// ==== 0x500760 FEScript::FEScript

/* [canon] hud high (ghidra-canon+mw) docs/re/hud.md */

void __fastcall FEScript__FEScript(undefined4 *param_1)

{
  param_1[1] = 0xabadcafe;
  param_1[2] = 0xabadcafe;
  *param_1 = &PTR_FUN_006c17f0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  return;
}


// ==== 0x5007a0 FUN_005007a0

undefined4 * __thiscall FUN_005007a0(undefined4 *param_1,byte param_2)

{
  FEScript___FEScript();
  if ((param_2 & 1) != 0) {
    (**(code **)*param_1)(0);
    FUN_00502d80();
  }
  return param_1;
}


// ==== 0x5007d0 FEPackage::AddResponse

/* [canon] hud med (ghidra-canon+hopper) docs/re/hud.md */

void __fastcall FEPackage__AddResponse(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  
  iVar1 = *(int *)(param_2 + 0x54);
  if (in_EAX != 0) {
    if (iVar1 == 0) {
      iVar2 = *(int *)(param_2 + 0x50);
      *(int *)(in_EAX + 4) = iVar2;
      if (iVar2 != 0) {
        *(int *)(iVar2 + 8) = in_EAX;
      }
      *(undefined4 *)(in_EAX + 8) = 0;
      *(int *)(param_2 + 0x50) = in_EAX;
    }
    else {
      iVar2 = *(int *)(iVar1 + 4);
      *(int *)(in_EAX + 4) = iVar2;
      if (iVar2 != 0) {
        *(int *)(iVar2 + 8) = in_EAX;
      }
      *(int *)(in_EAX + 8) = iVar1;
      *(int *)(iVar1 + 4) = in_EAX;
    }
    if (*(int *)(param_2 + 0x54) == iVar1) {
      *(int *)(param_2 + 0x54) = in_EAX;
    }
    *(int *)(param_2 + 0x4c) = *(int *)(param_2 + 0x4c) + 1;
  }
  return;
}


// ==== 0x500820 FEPackage::AddObject

/* [canon] hud med (ghidra-canon+hopper) docs/re/hud.md */

void __fastcall FEPackage__AddObject(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  
  iVar1 = *(int *)(param_2 + 0x44);
  if (in_EAX != 0) {
    if (iVar1 == 0) {
      iVar2 = *(int *)(param_2 + 0x40);
      *(int *)(in_EAX + 4) = iVar2;
      if (iVar2 != 0) {
        *(int *)(iVar2 + 8) = in_EAX;
      }
      *(undefined4 *)(in_EAX + 8) = 0;
      *(int *)(param_2 + 0x40) = in_EAX;
    }
    else {
      iVar2 = *(int *)(iVar1 + 4);
      *(int *)(in_EAX + 4) = iVar2;
      if (iVar2 != 0) {
        *(int *)(iVar2 + 8) = in_EAX;
      }
      *(int *)(in_EAX + 8) = iVar1;
      *(int *)(iVar1 + 4) = in_EAX;
    }
    if (*(int *)(param_2 + 0x44) == iVar1) {
      *(int *)(param_2 + 0x44) = in_EAX;
    }
    *(int *)(param_2 + 0x3c) = *(int *)(param_2 + 0x3c) + 1;
  }
  return;
}


// ==== 0x500870 FUN_00500870

void FUN_00500870(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  uVar1 = FEColor__operator_unsigned_long();
  *(undefined4 *)
   ((*(int *)(unaff_ESI + 0x88) * *(int *)(unaff_ESI + 0x5c) + *(int *)(unaff_ESI + 0x84)) * 0x30 +
   *(int *)(unaff_ESI + 0x8c)) = uVar1;
  return;
}


// ==== 0x5008a0 FEListBox::SetCurrentCellScale

/* [canon] hud med (ghidra-canon) docs/re/hud.md */

void __fastcall FEListBox__SetCurrentCellScale(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           ((*(int *)(param_1 + 0x88) * *(int *)(param_1 + 0x5c) + *(int *)(param_1 + 0x84)) * 0x30
            + 4 + *(int *)(param_1 + 0x8c));
  *puVar1 = *param_2;
  puVar1[1] = param_2[1];
  return;
}


// ==== 0x5008d0 FEListBox::SetCellImageUV

/* [canon] hud med (ghidra-canon+hopper) docs/re/hud.md */

void __fastcall FEListBox__SetCellImageUV(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           ((*(int *)(param_2 + 0x88) * *(int *)(param_2 + 0x5c) + *(int *)(param_2 + 0x84)) * 0x30
            + 0x20 + *(int *)(param_2 + 0x8c));
  *puVar1 = *param_1;
  puVar1[1] = param_1[1];
  puVar1[2] = param_1[2];
  puVar1[3] = param_1[3];
  return;
}


// ==== 0x500910 FUN_00500910

void FUN_00500910(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FEObject__FEObject();
  *puVar1 = &PTR_FUN_006c1834;
  puVar1[0x16] = &PTR_FUN_006c2c4c;
  puVar1[0x18] = 0;
  puVar1[0x19] = 0;
  puVar1[0x17] = 0;
  puVar1[6] = 5;
  return;
}


// ==== 0x500940 FUN_00500940

void FUN_00500940(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FEObject__FEObject();
  *puVar1 = &PTR_FUN_006c17c8;
  puVar1[0x16] = 0;
  puVar1[0x17] = 0xffffffff;
  puVar1[0x18] = 0;
  puVar1[0x19] = 0;
  puVar1[0x1a] = 0;
  puVar1[0x1b] = 0;
  puVar1[0x1c] = 0;
  puVar1[6] = 2;
  return;
}


// ==== 0x500970 FUN_00500970

void FUN_00500970(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_FUN_006c17c8;
  _free((void *)unaff_ESI[0x16]);
  if ((void *)unaff_ESI[0x18] != (void *)0x0) {
    _free((void *)unaff_ESI[0x18]);
  }
  FUN_004fef10();
  return;
}


// ==== 0x5009a0 FUN_005009a0

undefined4 __thiscall FUN_005009a0(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x74);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_00514350(pvVar1,param_1,param_2);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x500a10 FUN_00500a10

void * __thiscall FUN_00500a10(void *param_1,byte param_2)

{
  FUN_00500970();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x500a30 FUN_00500a30

void FUN_00500a30(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FEObject__FEObject();
  *puVar1 = &PTR_FUN_006c17c0;
  puVar1[0x16] = 0;
  puVar1[6] = 7;
  return;
}


// ==== 0x500a50 FUN_00500a50

void __fastcall FUN_00500a50(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c17c0;
  FUN_004fef10();
  return;
}


// ==== 0x500a60 FUN_00500a60

undefined4 * __thiscall FUN_00500a60(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x5c);
  local_4 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_004fec30(puVar1,param_1,param_2);
    *puVar1 = &PTR_FUN_006c17c0;
    puVar1[0x16] = *(undefined4 *)(param_1 + 0x58);
    puVar2 = puVar1;
  }
  ExceptionList = local_c;
  return puVar2;
}


// ==== 0x500ad0 FUN_00500ad0

void * __thiscall FUN_00500ad0(void *param_1,byte param_2)

{
  FUN_00500a50();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x500af0 FUN_00500af0

void FUN_00500af0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FEObject__FEObject();
  *puVar1 = &PTR_FUN_006c17d8;
  puVar1[6] = 1;
  puVar1[0x16] = 0;
  return;
}


// ==== 0x500b10 FUN_00500b10

void __fastcall FUN_00500b10(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c17d8;
  FUN_004fef10();
  return;
}


// ==== 0x500b20 FUN_00500b20

undefined4 * __thiscall FUN_00500b20(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x5c);
  local_4 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_004fec30(puVar1,param_1,param_2);
    *puVar1 = &PTR_FUN_006c17d8;
    puVar1[0x16] = *(undefined4 *)(param_1 + 0x58);
    puVar2 = puVar1;
  }
  ExceptionList = local_c;
  return puVar2;
}


// ==== 0x500b90 FUN_00500b90

void FUN_00500b90(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FEObject__FEObject();
  puVar1[0x16] = 0;
  *puVar1 = &PTR_FUN_006c17e0;
  puVar1[6] = 9;
  return;
}


// ==== 0x500bb0 FUN_00500bb0

undefined4 * __thiscall FUN_00500bb0(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x5c);
  local_4 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_004fec30(puVar1,param_1,param_2);
    *puVar1 = &PTR_FUN_006c17d8;
    puVar1[0x16] = *(undefined4 *)(param_1 + 0x58);
    *puVar1 = &PTR_FUN_006c17e0;
    puVar2 = puVar1;
  }
  ExceptionList = local_c;
  return puVar2;
}


// ==== 0x500c20 FUN_00500c20

void FUN_00500c20(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FEObject__FEObject();
  puVar1[0x16] = 0;
  *puVar1 = &PTR_FUN_006c17d0;
  puVar1[6] = 10;
  return;
}


// ==== 0x500c40 FUN_00500c40

undefined4 * __thiscall FUN_00500c40(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x5c);
  local_4 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_004fec30(puVar1,param_1,param_2);
    *puVar1 = &PTR_FUN_006c17d8;
    puVar1[0x16] = *(undefined4 *)(param_1 + 0x58);
    *puVar1 = &PTR_FUN_006c17d0;
    puVar2 = puVar1;
  }
  ExceptionList = local_c;
  return puVar2;
}


// ==== 0x500cb0 FUN_00500cb0

void * __thiscall FUN_00500cb0(void *param_1,byte param_2)

{
  FUN_00500b10();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x500cd0 FUN_00500cd0

void FUN_00500cd0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FEObject__FEObject();
  *puVar1 = &PTR_FUN_006c17e8;
  puVar1[6] = 0xb;
  return;
}


// ==== 0x500cf0 FUN_00500cf0

void __fastcall FUN_00500cf0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c17e8;
  FUN_004fef10();
  return;
}


// ==== 0x500d00 FUN_00500d00

undefined4 * __thiscall FUN_00500d00(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x58);
  local_4 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_004fec30(puVar1,param_1,param_2);
    *puVar1 = &PTR_FUN_006c17e8;
    puVar2 = puVar1;
  }
  ExceptionList = local_c;
  return puVar2;
}


// ==== 0x500d60 FUN_00500d60

void * __thiscall FUN_00500d60(void *param_1,byte param_2)

{
  FUN_00500cf0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x500d80 FUN_00500d80

int __fastcall
FUN_00500d80(undefined1 param_1,undefined1 param_2,int param_3,int param_4,int param_5)

{
  undefined1 in_AL;
  char cVar1;
  int iVar2;
  int *unaff_EDI;
  
  *(undefined1 *)(unaff_EDI + 2) = in_AL;
  *(undefined1 *)((int)unaff_EDI + 9) = param_1;
  *(undefined1 *)((int)unaff_EDI + 10) = param_2;
  iVar2 = 0;
  *unaff_EDI = 0;
  unaff_EDI[3] = 0;
  unaff_EDI[5] = 0;
  unaff_EDI[4] = 0;
  unaff_EDI[0xc] = 0;
  unaff_EDI[0xd] = 0;
  unaff_EDI[0x11] = 0;
  unaff_EDI[0x10] = 0;
  unaff_EDI[0x13] = 0;
  unaff_EDI[0x12] = 0;
  unaff_EDI[1] = param_3;
  unaff_EDI[0xe] = param_4;
  unaff_EDI[0xf] = param_5;
  cVar1 = FUN_00500eb0(unaff_EDI);
  if (cVar1 != '\0') {
    cVar1 = FUN_00500e50();
    if (cVar1 != '\0') {
      cVar1 = FUN_00500f30(unaff_EDI);
      if (cVar1 != '\0') {
        cVar1 = FUN_00501130(unaff_EDI);
        if (cVar1 != '\0') {
          cVar1 = FEPackage__ReadResourceRequests(unaff_EDI);
          if (cVar1 != '\0') {
            cVar1 = FUN_005013a0(unaff_EDI);
            if (cVar1 != '\0') {
              cVar1 = FUN_00501340();
              if (cVar1 != '\0') {
                cVar1 = FUN_00502650(unaff_EDI);
                if (cVar1 != '\0') {
                  *(char *)(*unaff_EDI + 0x16) = (char)unaff_EDI[2];
                  cVar1 = FUN_004ffa30();
                  if (cVar1 != '\0') {
                    iVar2 = *unaff_EDI;
                    *unaff_EDI = 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ((undefined4 *)*unaff_EDI != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*unaff_EDI)(1);
  }
  *unaff_EDI = 0;
  return iVar2;
}


// ==== 0x500e50 FUN_00500e50

undefined4 __fastcall FUN_00500e50(undefined4 param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  iVar2 = *(int *)(param_2 + 4);
  piVar4 = (int *)(iVar2 + 8);
  if (*piVar4 != 0x53707954) {
    while (piVar4 != (int *)(*(int *)(iVar2 + 4) + 8 + iVar2)) {
      piVar4 = (int *)((int)piVar4 + piVar4[1] + 8);
      if (*piVar4 == 0x53707954) {
        uVar3 = piVar4[1];
        *(int **)(param_2 + 0x34) = piVar4 + 2;
        *(uint *)(param_2 + 0x30) = uVar3 >> 3;
        return CONCAT31((int3)((uint)(piVar4 + 2) >> 8),1);
      }
    }
    if (*piVar4 != 0x53707954) goto LAB_00500ea3;
  }
  puVar1 = (uint *)(piVar4 + 1);
  piVar4 = piVar4 + 2;
  *(uint *)(param_2 + 0x30) = *puVar1 >> 3;
  *(int **)(param_2 + 0x34) = piVar4;
LAB_00500ea3:
  return CONCAT31((int3)((uint)piVar4 >> 8),1);
}


// ==== 0x500eb0 FUN_00500eb0

undefined4 FUN_00500eb0(int *param_1)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  
  piVar1 = (int *)param_1[1];
  if (((*piVar1 == -0x1891baba) && (piVar1[2] == 0x64486b50)) && (0x1ffff < (uint)piVar1[4])) {
    pvVar2 = _malloc(0xa0);
    if (pvVar2 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FEPackage__FEPackage();
    }
    *param_1 = iVar3;
    *(undefined4 *)(iVar3 + 0x80) = 0;
    param_1[0x10] = piVar1[6];
    param_1[0x11] = piVar1[7];
    FENode__SetName();
    FUN_004ff9e0();
    return 1;
  }
  return 0;
}


// ==== 0x500f30 FUN_00500f30

undefined4 FUN_00500f30(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 unaff_EBP;
  undefined4 uStack_10;
  uint local_c;
  uint *local_8;
  uint local_4;
  
  iVar1 = param_1[1];
  iVar8 = *(int *)(iVar1 + 8);
  piVar6 = (int *)(iVar1 + 8);
  do {
    if (iVar8 == 0x4c62694c) {
LAB_00500f63:
      iVar1 = *param_1;
      local_8 = (uint *)(piVar6 + 2);
      local_4 = *local_8;
      local_c = 0;
      if (local_4 != 0) {
        do {
          puVar7 = _malloc(0x14);
          if (puVar7 == (undefined4 *)0x0) {
            puVar7 = (undefined4 *)0x0;
          }
          else {
            puVar7[1] = 0xabadcafe;
            puVar7[2] = 0xabadcafe;
            *puVar7 = &PTR_FUN_006c1828;
            puVar7[3] = 0;
            puVar7[4] = 0;
          }
          FENode__SetName();
          iVar8 = *(int *)(iVar1 + 0x74);
          if (puVar7 != (undefined4 *)0x0) {
            if (iVar8 == 0) {
              iVar2 = *(int *)(iVar1 + 0x70);
              puVar7[1] = iVar2;
              if (iVar2 != 0) {
                *(undefined4 **)(iVar2 + 8) = puVar7;
              }
              puVar7[2] = 0;
              *(undefined4 **)(iVar1 + 0x70) = puVar7;
            }
            else {
              iVar2 = *(int *)(iVar8 + 4);
              puVar7[1] = iVar2;
              if (iVar2 != 0) {
                *(undefined4 **)(iVar2 + 8) = puVar7;
              }
              puVar7[2] = iVar8;
              *(undefined4 **)(iVar8 + 4) = puVar7;
            }
            if (*(int *)(iVar1 + 0x74) == iVar8) {
              *(undefined4 **)(iVar1 + 0x74) = puVar7;
            }
            *(int *)(iVar1 + 0x6c) = *(int *)(iVar1 + 0x6c) + 1;
          }
          local_c = local_c + 1;
        } while (local_c < local_4);
      }
      iVar1 = *(int *)(iVar1 + 0x70);
      do {
        if (iVar1 == 0) {
          return 1;
        }
        iVar8 = UIList__FindNodeByNameHash();
        if (iVar8 == 0) {
          iVar8 = (*(code *)**(undefined4 **)param_1[0xe])
                            (*(undefined4 *)(iVar1 + 0xc),&local_4,(int)&uStack_10 + 3);
          if (iVar8 == 0) {
            return 0;
          }
          iVar8 = FUN_004eeb90(iVar8,1);
          if ((char)((uint)unaff_EBP >> 0x18) != '\0') {
            _free(uStack_10);
          }
          puVar5 = local_8;
          if (iVar8 == 0) {
            return 0;
          }
          (**(code **)(*(int *)local_8[0xe] + 0xc))(iVar8);
          *(undefined4 *)(iVar8 + 0x18) = 1;
          uVar3 = puVar5[0xf];
          iVar2 = *(int *)(uVar3 + 0x108);
          if (iVar2 == 0) {
            iVar4 = *(int *)(uVar3 + 0x104);
            *(int *)(iVar8 + 4) = iVar4;
            if (iVar4 != 0) {
              *(int *)(iVar4 + 8) = iVar8;
            }
            *(undefined4 *)(iVar8 + 8) = 0;
            *(int *)(uVar3 + 0x104) = iVar8;
          }
          else {
            iVar4 = *(int *)(iVar2 + 4);
            *(int *)(iVar8 + 4) = iVar4;
            if (iVar4 != 0) {
              *(int *)(iVar4 + 8) = iVar8;
            }
            *(int *)(iVar8 + 8) = iVar2;
            *(int *)(iVar2 + 4) = iVar8;
          }
          if (*(int *)(uVar3 + 0x108) == iVar2) {
            *(int *)(uVar3 + 0x108) = iVar8;
          }
          *(int *)(uVar3 + 0x100) = *(int *)(uVar3 + 0x100) + 1;
        }
        else {
          *(int *)(iVar8 + 0x18) = *(int *)(iVar8 + 0x18) + 1;
        }
        iVar1 = *(int *)(iVar1 + 4);
      } while( true );
    }
    if (piVar6 == (int *)(*(int *)(iVar1 + 4) + 8 + iVar1)) {
      if (*piVar6 != 0x4c62694c) {
        return 1;
      }
      goto LAB_00500f63;
    }
    piVar6 = (int *)((int)piVar6 + piVar6[1] + 8);
    iVar8 = *piVar6;
  } while( true );
}


