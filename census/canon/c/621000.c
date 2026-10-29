// ==== 0x621020 EAGL::PC::GetDirectDraw

/* [canon] render low (hopper+ghidra) docs/re/render.md */

int EAGL__PC__GetDirectDraw(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int *unaff_EDI;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *local_18c;
  undefined4 auStack_188 [12];
  uint uStack_158;
  
  if (DAT_006dfb5c == 0xffffffff) {
    iVar3 = DirectDrawCreate(0,&local_18c,0);
    if (iVar3 < 0) {
      DAT_006dfb5c = 0;
    }
    else {
      puVar4 = auStack_188;
      for (iVar3 = 0x5f; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      auStack_188[0] = 0x17c;
      iVar3 = (**(code **)(*local_18c + 0x2c))(local_18c,auStack_188,0);
      DAT_006dfb5c = (iVar3 < 0) - 1 & uStack_158;
      (**(code **)(*unaff_EDI + 8))(unaff_EDI);
    }
  }
  FUN_0061f040();
  cVar1 = FUN_0061f5e0();
  if ((DAT_00709d94 == 0) || (DAT_00709d90 == 0)) {
    if (cVar1 == '\0') {
      if (DAT_00709d90 != 0) goto LAB_006210ec;
      uVar5 = 0;
    }
    else {
      if (DAT_00709d94 != 0) goto LAB_006210e4;
      uVar5 = 1;
    }
    cVar2 = EAGL__PC__InitCaps(uVar5);
    if (cVar2 == '\0') {
      return 0;
    }
  }
LAB_006210e4:
  if ((cVar1 != '\0') && (DAT_00709d94 != 0)) {
    return DAT_00709d94;
  }
LAB_006210ec:
  if (DAT_00709d80 != 0) {
    FUN_0061f040();
    iVar3 = FUN_0061efe0();
    if ((iVar3 != 0) && ((cVar1 == '\0' || (DAT_00709d94 != 0)))) {
      FUN_0061f040();
      iVar3 = FUN_0061efe0();
      switch(*(undefined4 *)(*(int *)(iVar3 + 0x1c) + 0xc4)) {
      case 0:
      case 2:
        break;
      case 1:
      case 3:
        return DAT_00709d94;
      default:
        return 0;
      }
    }
  }
  return DAT_00709d90;
}


// ==== 0x621160 FUN_00621160

void __fastcall FUN_00621160(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  BOOL BVar2;
  
  iVar1 = (**(code **)(*DAT_00709d80 + 0xc))(DAT_00709d80);
  while (iVar1 == -0x7789f798) {
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 0xc) + 0xe8);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
      (*UNRECOVERED_JUMPTABLE)();
    }
    BVar2 = PeekMessageA((LPMSG)&DAT_00709738,(HWND)0x0,0,0,1);
    if (BVar2 != 0) {
      TranslateMessage((MSG *)&DAT_00709738);
      DispatchMessageA((MSG *)&DAT_00709738);
    }
    iVar1 = (**(code **)(*DAT_00709d80 + 0xc))(DAT_00709d80);
  }
  if (iVar1 != 0) {
    DAT_006dfb4c = 0xffffffff;
    iVar1 = FUN_006205b0();
    if ((iVar1 < 0) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 0xc) + 0xf0),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
      (*UNRECOVERED_JUMPTABLE)();
    }
    FUN_00621e10();
    FUN_00622380();
    FUN_006228c0();
    FUN_00623f40();
    FUN_006227f0();
    DAT_00709570 = 0;
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 0xc) + 0xec);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0062122e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
  }
  return;
}


// ==== 0x621240 FUN_00621240

int __fastcall FUN_00621240(int param_1)

{
  int iVar1;
  int iVar2;
  
  Sleep(0);
  iVar1 = (**(code **)(*DAT_00709d80 + 0x3c))(DAT_00709d80,0,0,0,0);
  if (iVar1 == -0x7789f798) {
    FUN_00621160();
  }
  iVar2 = *(int *)(param_1 + 100) + 1;
  iVar1 = *(int *)(param_1 + 0xb4) + 1;
  *(int *)(param_1 + 0xb4) = iVar1 % iVar2;
  DAT_00709570 = DAT_00709570 + 1;
  return iVar1 / iVar2;
}


// ==== 0x621290 NullUpdate_ret

void NullUpdate_ret(void)

{
  return;
}


// ==== 0x6212a0 FUN_006212a0

void FUN_006212a0(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *param_1 >> 0x10;
  uVar1 = *param_1 & 0xffff;
  if ((uVar2 == 0x13) || (uVar2 == 0x16)) {
    if (DAT_0070fde0 == 0) {
      if (DAT_0070fdf4 == 0) {
        uVar3 = uVar2 << 0x10 | uVar1;
      }
      else {
        if (uVar2 == 0x16) {
          *param_1 = uVar1 | 0x180000;
          return;
        }
        uVar3 = uVar1 | 0x150000;
      }
    }
    else {
      if (uVar2 == 0x16) {
        *param_1 = uVar1 | 0x170000;
        return;
      }
      uVar3 = uVar1 | 0x140000;
    }
    *param_1 = uVar3;
  }
  if ((uVar2 == 0x25) || (uVar2 == 0x28)) {
    if (DAT_0070fde0 != 0) {
      if (uVar2 == 0x28) {
        *param_1 = uVar1 | 0x290000;
        return;
      }
      *param_1 = uVar1 | 0x260000;
      return;
    }
    if (DAT_0070fdf4 != 0) {
      if (uVar2 == 0x28) {
        *param_1 = uVar1 | 0x2a0000;
        return;
      }
      *param_1 = uVar1 | 0x270000;
      return;
    }
    *param_1 = uVar2 << 0x10 | uVar1;
  }
  return;
}


// ==== 0x621390 FUN_00621390

uint * FUN_00621390(int param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = (uint *)0x0;
  if (((param_2 != (uint *)0x0) && (-1 < param_1)) && (iVar3 = 0, puVar1 = param_2, param_1 != 0)) {
    do {
      uVar2 = *param_2 >> 0x10;
      if (((((uVar2 == 0x11) || (uVar2 == 0x10)) ||
           ((uVar2 == 0x41 || ((uVar2 == 0x40 || (uVar2 == 0x30)))))) || (uVar2 == 0x2f)) ||
         ((uVar2 == 0x43 || (uVar2 == 0x42)))) {
        param_2 = param_2 + (*param_2 & 0xffff);
        iVar3 = iVar3 + 1;
      }
      uVar2 = *param_2;
      if (uVar2 == 0) {
        param_2 = param_2 + 1;
      }
      puVar1 = param_2 + (uVar2 & 0xffff);
      param_2 = puVar1;
    } while (iVar3 != param_1);
  }
  return puVar1;
}


// ==== 0x621410 FUN_00621410

void FUN_00621410(uint param_1,undefined4 param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  uint local_8;
  uint local_4;
  
  puVar3 = (uint *)FUN_00621390(param_2,param_1 + 4);
  uVar5 = *puVar3;
  while (uVar5 != 0) {
    local_4 = *puVar3 & 0xffff;
    uVar5 = *puVar3 >> 0x10;
    local_c = uVar5;
    FUN_006212a0(puVar3);
    if ((uVar5 == 0x40) || (uVar5 == 0x41)) {
      puVar1 = puVar3 + 1;
      uVar4 = puVar3[1];
      while (uVar4 != 0) {
        uVar4 = *puVar1 >> 0x10;
        local_8 = *puVar1 & 0xffff;
        if (uVar4 == 4) {
          if (puVar1[9] == 1) {
            uVar5 = puVar1[8];
            puVar1[9] = 0;
            param_1._1_3_ = (undefined3)(param_1 >> 8);
            param_1 = CONCAT31(param_1._1_3_,0 < (int)uVar5);
            if (0 >= (int)uVar5) {
              uVar5 = -uVar5;
            }
            local_14 = *(undefined4 *)(puVar1[4] + 4);
            FUN_00622c60(&local_14,0);
            *(undefined4 *)(puVar1[4] + 4) = 0;
            iVar6 = 1;
            if (1 < (int)uVar5) {
              do {
                if ((char)param_1 != '\0') {
                  local_14 = *(undefined4 *)(puVar1[4] + 4 + iVar6 * 8);
                  FUN_00622c60(&local_14,0);
                  *(undefined4 *)(puVar1[4] + 4 + iVar6 * 8) = 0;
                }
                iVar6 = iVar6 + 1;
              } while (iVar6 < (int)uVar5);
            }
            (*(code *)PTR_FUN_006dfaa0)(puVar1[4],8);
            puVar1[4] = 0;
            uVar5 = local_c;
          }
        }
        else if ((uVar4 == 0x4b) && (puVar1[9] == 1)) {
          param_1 = puVar1[4];
          puVar1[9] = 0;
          FUN_00622c10(&param_1);
          puVar1[4] = 0xffffffff;
          puVar1[10] = 0xffffffff;
        }
        puVar2 = puVar1 + local_8;
        puVar1 = puVar1 + local_8;
        uVar4 = *puVar2;
      }
    }
    if (uVar5 == 4) {
      if (puVar3[9] == 1) {
        uVar5 = puVar3[8];
        puVar3[9] = 0;
        param_1 = CONCAT31(param_1._1_3_,0 < (int)uVar5);
        if (0 >= (int)uVar5) {
          uVar5 = -uVar5;
        }
        local_10 = *(undefined4 *)(puVar3[4] + 4);
        FUN_00622c60(&local_10,0);
        iVar6 = 1;
        *(undefined4 *)(puVar3[4] + 4) = 0;
        if (1 < (int)uVar5) {
          do {
            if ((char)param_1 != '\0') {
              local_10 = *(undefined4 *)(puVar3[4] + 4 + iVar6 * 8);
              FUN_00622c60(&local_10,0);
              *(undefined4 *)(puVar3[4] + 4 + iVar6 * 8) = 0;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < (int)uVar5);
        }
        (*(code *)PTR_FUN_006dfaa0)(puVar3[4],8);
        puVar3[4] = 0;
      }
    }
    else if (uVar5 == 0x4b) {
      if (puVar3[9] == 1) {
        param_1 = puVar3[4];
        puVar3[9] = 0;
        FUN_00622c10(&param_1);
        puVar3[4] = 0xffffffff;
        puVar3[10] = 0xffffffff;
      }
    }
    else if ((uVar5 == 7) && (puVar3[2] == 1)) {
      FUN_00623500(puVar3 + 3);
      puVar3[2] = 0;
    }
    puVar1 = puVar3 + local_4;
    puVar3 = puVar3 + local_4;
    uVar5 = *puVar1;
  }
  return;
}


// ==== 0x621670 FUN_00621670

void FUN_00621670(int param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 uStack_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  uint local_4;
  
  puVar4 = (uint *)FUN_00621390(param_2,param_1 + 4);
  uVar6 = *puVar4;
  while (uVar6 != 0) {
    uVar6 = *puVar4 >> 0x10;
    local_4 = *puVar4 & 0xffff;
    if (uVar6 == 4) {
      uVar6 = puVar4[4];
      if ((uVar6 != 0) && (uVar6 != 0xffffffff)) {
        uVar2 = puVar4[8];
        if ((int)uVar2 < 1) {
          uStack_18 = *(undefined4 *)(uVar6 + 4);
          FUN_00622c60(&uStack_18,0);
        }
        else {
          iVar7 = 0;
          if (0 < (int)uVar2) {
            do {
              param_1 = *(int *)(puVar4[4] + 4 + iVar7 * 8);
              FUN_00622c60(&param_1,0);
              iVar7 = iVar7 + 1;
            } while (iVar7 < (int)uVar2);
          }
        }
        (*(code *)PTR_FUN_006dfaa0)(puVar4[4],8);
      }
      puVar4[4] = 0;
    }
    else {
      if ((uVar6 == 5) || (uVar6 == 0x4c)) {
        uStack_14 = puVar4[4];
        FUN_00622c60(&uStack_14,0);
        puVar4[4] = 0xffffffff;
      }
      if (uVar6 == 0x4b) {
        uStack_14 = puVar4[4];
        puVar4[4] = 0;
        FUN_00622c10(&uStack_14);
        puVar5 = (undefined4 *)(puVar4[10] - *(int *)(puVar4[10] - 4));
        (*(code *)PTR_FUN_006dfaa0)(puVar5,*puVar5);
      }
      else if (uVar6 == 7) {
        if (puVar4[2] == 1) {
          FUN_00623500(puVar4 + 3);
        }
      }
      else if ((uVar6 == 0x40) || (uVar6 == 0x41)) {
        puVar3 = puVar4 + 1;
        uVar6 = puVar4[1];
        while (uVar6 != 0) {
          uVar6 = *puVar3 >> 0x10;
          uStack_8 = *puVar3 & 0xffff;
          if (uVar6 == 4) {
            uVar6 = puVar3[4];
            if ((uVar6 != 0) && (uVar6 != 0xffffffff)) {
              uVar2 = puVar3[8];
              if ((int)uVar2 < 1) {
                uStack_c = *(undefined4 *)(uVar6 + 4);
                FUN_00622c60(&uStack_c,0);
              }
              else if (0 < (int)uVar2) {
                iVar7 = 0;
                do {
                  uStack_10 = *(undefined4 *)(puVar3[4] + 4 + iVar7 * 8);
                  FUN_00622c60(&uStack_10,0);
                  iVar7 = iVar7 + 1;
                } while (iVar7 < (int)uVar2);
              }
              (*(code *)PTR_FUN_006dfaa0)(puVar3[4],8);
            }
            puVar3[4] = 0;
          }
          else {
            if ((uVar6 == 5) || (uVar6 == 0x4c)) {
              uStack_14 = puVar3[4];
              FUN_00622c60(&uStack_14,0);
              puVar3[4] = 0xffffffff;
            }
            if (uVar6 == 0x4b) {
              uStack_14 = puVar3[4];
              puVar3[4] = 0;
              FUN_00622c10(&uStack_14);
              puVar5 = (undefined4 *)(puVar3[10] - *(int *)(puVar3[10] - 4));
              (*(code *)PTR_FUN_006dfaa0)(puVar5,*puVar5);
            }
          }
          puVar1 = puVar3 + uStack_8;
          puVar3 = puVar3 + uStack_8;
          uVar6 = *puVar1;
        }
      }
    }
    puVar4 = puVar4 + local_4;
    uVar6 = *puVar4;
  }
  return;
}


// ==== 0x6218b0 FUN_006218b0

void __thiscall
FUN_006218b0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  param_1[2] = param_3;
  param_1[3] = param_4;
  param_1[5] = param_5;
  *param_1 = param_2;
  param_1[6] = param_6;
  param_1[1] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0xffffffff;
  param_1[0xb] = param_7;
  param_1[0xc] = 0;
  param_1[4] = DAT_00709d84;
  DAT_00709d84 = param_1;
  return;
}


// ==== 0x621910 FUN_00621910

void FUN_00621910(int *param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  int local_10;
  uint local_c;
  uint local_8;
  int local_4;
  
  iVar4 = FUN_00626990();
  local_4 = iVar4;
  if ((param_1[1] != 0) && (local_10 = 0, 0 < iVar4)) {
    do {
      puVar3 = *(uint **)(param_1[1] + local_10 * 4);
      uVar5 = *puVar3;
      uVar7 = local_c;
      while (local_c = uVar7, uVar5 != 0) {
        uVar5 = *puVar3 >> 0x10;
        local_8 = *puVar3 & 0xffff;
        if (uVar5 == 5) {
          if (puVar3[3] != 0xffffffff) {
            local_c = puVar3[4];
            if (local_c != 0xffffffff) {
              FUN_00622c60(&local_c,0);
            }
            puVar3[1] = 0xffffffff;
            puVar3[2] = 0xffffffff;
            puVar3[3] = 0xffffffff;
            puVar3[4] = 0xffffffff;
            puVar3[5] = 0xffffffff;
            uVar7 = local_c;
          }
        }
        else if (uVar5 == 8) {
          local_c = puVar3[2];
          if (local_c != 0xffffffff) {
            FUN_00623500(&local_c);
            puVar3[1] = 0xffffffff;
            puVar3[2] = 0xffffffff;
            uVar7 = local_c;
          }
        }
        else if ((((uVar5 == 0x40) || (uVar5 == 0x41)) || (uVar5 == 0x42)) || (uVar5 == 0x43)) {
          puVar1 = puVar3 + 1;
          uVar5 = puVar3[1];
          while (uVar7 = local_c, uVar5 != 0) {
            uVar7 = *puVar1 >> 0x10;
            uVar5 = *puVar1 & 0xffff;
            if ((uVar7 == 5) || (uVar7 == 0x4c)) {
              local_c = puVar1[4];
              FUN_00622c60(&local_c,0);
              puVar1[1] = 0xffffffff;
              puVar1[2] = 0xffffffff;
              puVar1[3] = 0xffffffff;
              puVar1[4] = 0xffffffff;
              puVar1[5] = 0xffffffff;
            }
            puVar2 = puVar1 + uVar5;
            puVar1 = puVar1 + uVar5;
            uVar5 = *puVar2;
          }
        }
        local_c = uVar7;
        puVar1 = puVar3 + local_8;
        puVar3 = puVar3 + local_8;
        iVar4 = local_4;
        uVar7 = local_c;
        uVar5 = *puVar1;
      }
      local_10 = local_10 + 1;
    } while (local_10 < iVar4);
  }
  iVar4 = 1;
  if (param_1[3] != 0) {
    iVar4 = FUN_00626990();
  }
  if (param_1[9] != 0) {
    iVar9 = 0;
    if (0 < iVar4) {
      do {
        uVar6 = FUN_00626980(iVar9);
        if (param_1[6] == 0) {
          if (iVar9 == 0) {
            FUN_00621670(param_1[9]);
          }
          else {
            FUN_00621410(param_1[9],uVar6);
          }
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar4);
    }
    param_1[9] = 0;
  }
  puVar8 = (undefined4 *)(*param_1 + -4);
  *param_1 = (int)puVar8;
  (*(code *)PTR_FUN_006dfaa0)(puVar8,*puVar8);
  iVar4 = param_1[1];
  *param_1 = 0;
  if (iVar4 != 0) {
    (*(code *)PTR_FUN_006dfaa0)(iVar4 + -4,*(undefined4 *)(iVar4 + -4));
  }
  param_1[1] = 0;
  return;
}


// ==== 0x621b00 FUN_00621b00

void FUN_00621b00(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0xc) != 0) && (iVar1 = FUN_00626990(), *(int *)(param_1 + 0x24) != 0)) {
    iVar3 = 0;
    if (0 < iVar1) {
      do {
        uVar2 = FUN_00626980(iVar3);
        if (*(int *)(param_1 + 0x18) == 0) {
          if (iVar3 == 0) {
            FUN_00621670(*(undefined4 *)(param_1 + 0x24));
          }
          else {
            FUN_00621410(*(undefined4 *)(param_1 + 0x24),uVar2);
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
    }
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  iVar1 = *(int *)(param_1 + 0xc);
  if ((iVar1 != 0) && (*(int *)(param_1 + 0x20) == 0)) {
    FUN_00626b60();
    (*(code *)PTR_FUN_006dfaa0)(iVar1,0x24);
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    (*(code *)PTR_FUN_006dfaa0)(iVar1 + -4,*(undefined4 *)(iVar1 + -4));
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


// ==== 0x621bc0 FUN_00621bc0

void __fastcall FUN_00621bc0(int *param_1)

{
  int iVar1;
  float fVar2;
  
  iVar1 = *(int *)(param_1[9] + 0x18);
  if ((&DAT_00709eb4)[*param_1] != iVar1) {
    (&DAT_00709eb4)[*param_1] = iVar1;
    (**(code **)(*DAT_00709d80 + 0xf4))(DAT_00709d80,*param_1,iVar1);
  }
  if (*(int *)(param_1[9] + 0x20) != -1) {
    (**(code **)(*DAT_00709d80 + 0x110))(DAT_00709d80,*(int *)(param_1[9] + 0x20));
  }
  if ((&DAT_006e2870)[*param_1] != param_1[2]) {
    (&DAT_006e2870)[*param_1] = param_1[2];
    (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,*param_1,0xd,param_1[2]);
  }
  if ((&DAT_006e2890)[*param_1] != param_1[3]) {
    (&DAT_006e2890)[*param_1] = param_1[3];
    (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,*param_1,0xe,param_1[3]);
  }
  if ((&DAT_006e28b0)[*param_1] != param_1[4]) {
    (&DAT_006e28b0)[*param_1] = param_1[4];
    (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,*param_1,0x19,param_1[4]);
  }
  if ((&DAT_006e2910)[*param_1] != param_1[5]) {
    (&DAT_006e2910)[*param_1] = param_1[5];
    (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,*param_1,0x15,param_1[5]);
  }
  iVar1 = DAT_006e2848;
  if (DAT_006e2848 == -1) {
    if ((&DAT_006e28d0)[*param_1] == param_1[6]) goto LAB_00621d35;
    (&DAT_006e28d0)[*param_1] = param_1[6];
    (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,*param_1,0x10,param_1[6]);
    iVar1 = param_1[6];
  }
  else {
    if ((&DAT_006e28d0)[*param_1] == DAT_006e2848) goto LAB_00621d35;
    (&DAT_006e28d0)[*param_1] = DAT_006e2848;
    (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,*param_1,0x10,iVar1);
    iVar1 = DAT_006e2848;
  }
  (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,*param_1,0x11,iVar1);
LAB_00621d35:
  iVar1 = DAT_006e284c;
  if (DAT_006e284c == -1) {
    if ((&DAT_006e28f0)[*param_1] != param_1[8]) {
      (&DAT_006e28f0)[*param_1] = param_1[8];
      (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,*param_1,0x12,param_1[8]);
    }
  }
  else if ((&DAT_006e28f0)[*param_1] != DAT_006e284c) {
    (&DAT_006e28f0)[*param_1] = DAT_006e284c;
    (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,*param_1,0x12,iVar1);
  }
  fVar2 = DAT_00709ea4;
  iVar1 = *param_1;
  if (DAT_00709ea4 == 0.0) {
    if ((float)(&DAT_00709ed4)[iVar1] == (float)param_1[7]) {
      return;
    }
    (&DAT_00709ed4)[iVar1] = param_1[7];
    fVar2 = (float)param_1[7];
  }
  else {
    if ((float)(&DAT_00709ed4)[iVar1] == DAT_00709ea4) {
      return;
    }
    (&DAT_00709ed4)[iVar1] = DAT_00709ea4;
  }
  (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,*param_1,0x13,fVar2);
  return;
}


// ==== 0x621e00 FUN_00621e00

undefined4 __thiscall FUN_00621e00(undefined4 *param_1,undefined4 param_2)

{
  param_1 = (undefined4 *)*param_1;
  *param_1 = param_2;
  return CONCAT31((int3)((uint)param_1 >> 8),1);
}


// ==== 0x621e10 FUN_00621e10

void FUN_00621e10(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_006e2910;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_006e28f0;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_00709ed4;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_006e28d0;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_006e28b0;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_006e2890;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_006e2870;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_006e2850;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_00709eb4;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== 0x621ea0 FUN_00621ea0

void FUN_00621ea0(void)

{
  int *piVar1;
  int *piVar2;
  
  for (piVar2 = DAT_00709ea0; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[3]) {
    if (*piVar2 != 0) {
      piVar1 = *(int **)(*(int *)(*piVar2 + 0x24) + 0x18);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *(undefined4 *)(*(int *)(*piVar2 + 0x24) + 0x18) = 0;
      }
      piVar1 = *(int **)(*(int *)(*piVar2 + 0x24) + 0x1c);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *(undefined4 *)(*(int *)(*piVar2 + 0x24) + 0x1c) = 0;
      }
    }
  }
  return;
}


// ==== 0x621f00 FUN_00621f00

void __fastcall FUN_00621f00(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uStack_4;
  
  uStack_4 = param_1;
  for (piVar2 = DAT_00709ea0; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[3]) {
    iVar1 = *piVar2;
    if (iVar1 != 0) {
      if ((*(byte *)(piVar2 + 1) & 1) != 0) {
        iVar3 = *(int *)(iVar1 + 0x24);
        iVar3 = (**(code **)(*DAT_00709d80 + 0x50))
                          (DAT_00709d80,*(undefined4 *)(iVar3 + 4),*(undefined4 *)(iVar3 + 8),
                           *(undefined4 *)(iVar3 + 0xc),1,*(undefined4 *)(iVar3 + 0x14),0,
                           iVar3 + 0x18);
        if (iVar3 < 0) {
          *(undefined4 *)(*(int *)(iVar1 + 0x24) + 0x18) = 0;
        }
      }
      if ((*(byte *)(piVar2 + 1) & 2) != 0) {
        puVar4 = &uStack_4;
        FUN_0061f040(puVar4);
        FUN_0061efe0();
        FUN_0061f780(puVar4);
        iVar1 = *(int *)(iVar1 + 0x24);
        (**(code **)(*DAT_00709d80 + 0x68))
                  (DAT_00709d80,*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 8),
                   *(undefined4 *)(iVar1 + 0x14),uStack_4,iVar1 + 0x1c);
      }
    }
  }
  return;
}


// ==== 0x621fb0 FUN_00621fb0

void __thiscall FUN_00621fb0(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[5] = param_2[5];
  param_1[10] = param_2[10];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  param_1[6] = param_2[6];
  param_1[7] = param_2[7];
  param_1[8] = param_2[8];
  param_1[9] = param_2[9];
  param_1[0xd] = param_2[0xd];
  param_1[0xe] = param_2[0xe];
  param_1[0xc] = param_2[0xc];
  param_1[0xb] = param_2[0xb];
  param_1[0xf] = param_2[0xf];
  param_1[0x10] = param_2[0x10];
  return;
}


// ==== 0x622020 FUN_00622020

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00622020(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  bool bVar5;
  int **ppiVar6;
  undefined4 uVar7;
  int *local_4;
  
  DAT_0070a410 = *param_1;
  local_4 = param_1;
  if (param_1[9] == 0) {
    iVar2 = 0;
    do {
      if ((&DAT_00709eb4)[iVar2] != 0) {
        (**(code **)(*DAT_00709d80 + 0xf4))(DAT_00709d80,iVar2,0);
      }
      (&DAT_00709eb4)[iVar2] = 0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
  }
  if (DAT_006e29b4 != param_1[0x10]) {
    if (param_1[0x10] == 0xffffffff) {
      ppiVar6 = &local_4;
      FUN_0061f040(ppiVar6);
      FUN_0061efe0();
      FUN_0061f760(ppiVar6);
      piVar3 = local_4;
      FUN_0061f040(local_4);
      FUN_0061efe0();
      FUN_0061f720(piVar3);
    }
    else {
      DAT_006dfb54 = *(byte *)(param_1 + 0x10) & 1;
      DAT_006e29b4 = (uint)DAT_006dfb54;
      (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0xe,param_1[0x10]);
    }
  }
  iVar2 = 0x11;
  bVar5 = true;
  piVar3 = &DAT_00709f10;
  piVar4 = param_1;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *piVar3 == *piVar4;
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    return 1;
  }
  FUN_0063f1b0(&DAT_00709f10,param_1,0x44);
  if ((float)_DAT_006e29b0 != (float)param_1[0xf]) {
    _DAT_006e29b0 = _ftol_nocw();
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0xa4,param_1[0xf]);
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0xa3,0);
  }
  if (DAT_006e29a8 != param_1[0xb]) {
    DAT_006e29a8 = param_1[0xb];
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,8,param_1[0xb]);
  }
  if (DAT_006e29ac != param_1[0xc]) {
    DAT_006e29ac = param_1[0xc];
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0xab,param_1[0xc]);
  }
  iVar2 = param_1[2];
  if ((DAT_006e297c != iVar2) || (DAT_006e2980 != param_1[3])) {
    DAT_006e2980 = param_1[3];
    DAT_006e297c = iVar2;
    if (param_1[2] == 0) {
      uVar7 = 1;
    }
    else {
      if (param_1[3] != 0) {
        if (param_1[3] == 1) {
          (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x16,3);
        }
        goto LAB_006221e7;
      }
      uVar7 = 2;
    }
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x16,uVar7);
  }
LAB_006221e7:
  iVar2 = param_1[1];
  if (DAT_006e2978 == iVar2) goto LAB_00622243;
  iVar1 = param_1[1];
  DAT_006e2978 = iVar2;
  if (iVar1 == 0) {
    uVar7 = 1;
LAB_00622221:
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,9,uVar7);
    uVar7 = 0;
  }
  else {
    if (iVar1 == 1) {
      uVar7 = 2;
      goto LAB_00622221;
    }
    if (iVar1 != 2) goto LAB_00622243;
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,9,2);
    uVar7 = 1;
  }
  (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x1d,uVar7);
LAB_00622243:
  if (DAT_006e2984 != param_1[4]) {
    DAT_006e2984 = param_1[4];
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x17,param_1[4]);
  }
  if (((DAT_006e2990 != param_1[5]) || (DAT_006e2988 != param_1[0xd])) ||
     (DAT_006e298c != param_1[0xe])) {
    DAT_006e2988 = param_1[0xd];
    DAT_006e298c = param_1[0xe];
    DAT_006e2990 = param_1[5];
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x13,param_1[0xd]);
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x14,param_1[0xe]);
  }
  if (DAT_006e2994 != param_1[6]) {
    DAT_006e2994 = param_1[6];
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0xf,param_1[6]);
  }
  if (DAT_006e2998 != param_1[7]) {
    DAT_006e2998 = param_1[7];
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x18,param_1[7]);
  }
  if (DAT_006e299c != param_1[8]) {
    DAT_006e299c = param_1[8];
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x19,param_1[8]);
  }
  iVar2 = param_1[10];
  if (DAT_006e29a4 != iVar2) {
    DAT_006e29a4 = iVar2;
    if (param_1[10] == 0) {
      (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x1b,0);
    }
    else if (param_1[10] == 1) {
      (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x1b,1);
      return 1;
    }
  }
  return 1;
}


// ==== 0x622380 FUN_00622380

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00622380(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00709f10;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  _DAT_006e2974 = 0xffffffff;
  DAT_006e2978 = 0xffffffff;
  DAT_006e297c = 0xffffffff;
  DAT_006e2980 = 0xffffffff;
  DAT_006e2984 = 0xffffffff;
  DAT_006e2988 = 0xffffffff;
  DAT_006e298c = 0xffffffff;
  DAT_006e2990 = 0xffffffff;
  DAT_006e2994 = 0xffffffff;
  DAT_006e2998 = 0xffffffff;
  DAT_006e299c = 0xffffffff;
  _DAT_006e29a0 = 0xffffffff;
  DAT_006e29a4 = 0xffffffff;
  DAT_006e29a8 = 0xffffffff;
  DAT_006e29ac = 0xffffffff;
  _DAT_006e29b0 = 1;
  DAT_006e29b4 = 0xfffffffe;
  return;
}


// ==== 0x622400 FUN_00622400

void __fastcall FUN_00622400(undefined4 *param_1)

{
  param_1[1] = 1;
  param_1[5] = 0;
  param_1[10] = 0;
  param_1[2] = 0;
  param_1[3] = 1;
  param_1[6] = 1;
  param_1[9] = 1;
  param_1[0xc] = 1;
  *param_1 = 4;
  param_1[4] = 4;
  param_1[7] = 0x10;
  param_1[8] = 5;
  param_1[0xd] = 5;
  param_1[0xe] = 6;
  param_1[0xb] = 3;
  param_1[0xf] = 0x3f800000;
  param_1[0x10] = 0xffffffff;
  return;
}


// ==== 0x622460 FUN_00622460

void __thiscall FUN_00622460(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_40 [64];
  
  FUN_00643d70(param_1,param_2,local_40);
  FUN_0063f1b0(param_1,local_40,0x40);
  return;
}


// ==== 0x622490 FUN_00622490

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00622490(float *param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  
  fVar1 = param_1[4] + param_1[8] + *param_1;
  if (0.0 < fVar1) {
    fVar1 = SQRT(fVar1 + _K_ONE);
    param_2[3] = _K_HALF * fVar1;
    fVar1 = _K_HALF / fVar1;
    *param_2 = (param_1[5] - param_1[7]) * fVar1;
    param_2[1] = (param_1[6] - param_1[2]) * fVar1;
    param_2[2] = (param_1[1] - param_1[3]) * fVar1;
    return;
  }
  if (param_1[4] <= *param_1) {
    iVar2 = 0;
  }
  else {
    iVar2 = 4;
  }
  if (param_1[iVar2] < param_1[8]) {
    fVar1 = SQRT((param_1[8] - (param_1[4] + *param_1)) + _K_ONE);
    param_2[2] = _K_HALF * fVar1;
    if (fVar1 != 0.0) {
      fVar1 = _K_HALF / fVar1;
    }
    param_2[3] = (param_1[1] - param_1[3]) * fVar1;
    *param_2 = (param_1[6] + param_1[2]) * fVar1;
    param_2[1] = (param_1[7] + param_1[5]) * fVar1;
    return;
  }
  if (iVar2 != 0) {
    fVar1 = SQRT((param_1[4] - (*param_1 + param_1[8])) + _K_ONE);
    param_2[1] = _K_HALF * fVar1;
    if (fVar1 != 0.0) {
      fVar1 = _K_HALF / fVar1;
    }
    param_2[3] = (param_1[6] - param_1[2]) * fVar1;
    param_2[2] = (param_1[7] + param_1[5]) * fVar1;
    *param_2 = (param_1[3] + param_1[1]) * fVar1;
    return;
  }
  fVar1 = SQRT((*param_1 - (param_1[4] + param_1[8])) + _K_ONE);
  *param_2 = _K_HALF * fVar1;
  if (fVar1 != 0.0) {
    fVar1 = _K_HALF / fVar1;
  }
  param_2[3] = (param_1[5] - param_1[7]) * fVar1;
  param_2[1] = (param_1[3] + param_1[1]) * fVar1;
  param_2[2] = (param_1[6] + param_1[2]) * fVar1;
  return;
}


// ==== 0x622610 FUN_00622610

void __thiscall FUN_00622610(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_24 = *param_1;
  local_20 = param_1[1];
  local_1c = param_1[2];
  local_18 = param_1[4];
  local_14 = param_1[5];
  local_c = param_1[8];
  local_8 = param_1[9];
  local_10 = param_1[6];
  local_4 = param_1[10];
  FUN_00622490(&local_24,param_2);
  *param_3 = param_1[0xc];
  param_3[1] = param_1[0xd];
  param_3[2] = param_1[0xe];
  param_3[3] = param_1[0xf];
  return;
}


// ==== 0x622690 FUN_00622690

void __thiscall FUN_00622690(undefined4 param_1,int param_2,int param_3,int param_4)

{
  if (param_2 != 0) {
    param_4 = param_4 - param_3;
    do {
      FUN_00643ec0(param_3,param_1,param_4 + param_3);
      param_3 = param_3 + 0x10;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


// ==== 0x6226d0 FUN_006226d0

void FUN_006226d0(int *param_1)

{
  if (DAT_0070a418 != *param_1) {
    DAT_0070a418 = *param_1;
    (**(code **)(*DAT_00709d80 + 0x130))(DAT_00709d80,*param_1);
    FUN_0061f040();
    return;
  }
  return;
}


// ==== 0x622700 FUN_00622700

void FUN_00622700(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*DAT_00709d80 + 0x13c))(DAT_00709d80,param_1,param_2,param_3);
  return;
}


// ==== 0x622720 FUN_00622720

void FUN_00622720(int param_1,int param_2)

{
  if ((&DAT_0070a428)[param_1] != param_2) {
    (**(code **)(*DAT_00709d80 + 0x14c))
              (DAT_00709d80,param_1,*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 0x10));
    (&DAT_0070a428)[param_1] = param_2;
  }
  return;
}


// ==== 0x622760 FUN_00622760

void FUN_00622760(undefined4 param_1)

{
  DAT_0070a41c = param_1;
  return;
}


// ==== 0x622770 FUN_00622770

void FUN_00622770(undefined4 param_1)

{
  DAT_0070a420 = param_1;
  return;
}


// ==== 0x622780 FUN_00622780

void FUN_00622780(void)

{
  if ((DAT_006e2a40 != DAT_0070a41c) || (DAT_006e2a44 != DAT_0070a420)) {
    DAT_006e2a40 = DAT_0070a41c;
    DAT_006e2a44 = DAT_0070a420;
    (**(code **)(*DAT_00709d80 + 0x154))(DAT_00709d80,*DAT_0070a41c,DAT_0070a420);
  }
  return;
}


// ==== 0x6227c0 FUN_006227c0

void FUN_006227c0(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (DAT_0070a414 != iVar1) {
    DAT_0070a414 = iVar1;
    (**(code **)(*DAT_00709d80 + 0x160))(DAT_00709d80,iVar1);
  }
  return;
}


// ==== 0x6227f0 FUN_006227f0

void FUN_006227f0(void)

{
  if (DAT_0070a414 != 0) {
    DAT_0070a414 = 0;
    (**(code **)(*DAT_00709d80 + 0x160))(DAT_00709d80,0);
  }
  return;
}


// ==== 0x622820 FUN_00622820

void FUN_00622820(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*DAT_00709d80 + 0x16c))(DAT_00709d80,param_1,param_2,param_3);
  return;
}


// ==== 0x622840 FUN_00622840

void FUN_00622840(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*DAT_00709d80 + 0x118))(DAT_00709d80,DAT_0070a410,param_1,param_3);
  return;
}


// ==== 0x622860 FUN_00622860

void FUN_00622860(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 unaff_retaddr;
  
  iVar1 = (**(code **)(*DAT_00709d80 + 0xc))(DAT_00709d80);
  if (iVar1 == 0) {
    (**(code **)(*DAT_00709d80 + 0x11c))
              (DAT_00709d80,DAT_0070a410,unaff_retaddr,param_1,param_2,param_4);
  }
  return;
}


// ==== 0x6228a0 FUN_006228a0

void FUN_006228a0(void)

{
  DAT_0070a41c = 0;
  DAT_0070a420 = 0;
  DAT_006e2a40 = 0xffffffff;
  DAT_006e2a44 = 0xffffffff;
  return;
}


// ==== 0x6228c0 FUN_006228c0

void FUN_006228c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_0070a428;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  DAT_0070a414 = 0;
  DAT_0070a418 = 0;
  DAT_0070a41c = 0;
  DAT_0070a420 = 0;
  DAT_006e2a40 = 0xffffffff;
  DAT_006e2a44 = 0xffffffff;
  DAT_006e2a48 = 0xffffffff;
  (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x3c,0xffffffff);
  return;
}


// ==== 0x622910 FUN_00622910

void FUN_00622910(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_0070a428;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== 0x622930 FUN_00622930

undefined4 FUN_00622930(void)

{
  return DAT_0070a414;
}


// ==== 0x622940 FUN_00622940

void FUN_00622940(int param_1)

{
  if (DAT_006e2a48 != param_1) {
    DAT_006e2a48 = param_1;
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x3c,param_1);
  }
  return;
}


// ==== 0x622970 FUN_00622970

undefined4 * __thiscall
FUN_00622970(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            int param_5,undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  char cVar2;
  
  param_1[3] = param_2;
  param_1[7] = param_4;
  *param_1 = &PTR_FUN_006a79c0;
  param_1[2] = 0;
  param_1[4] = param_3;
  param_1[5] = param_7;
  param_1[6] = 0;
  if (param_5 == 0) {
    param_1[8] = 0;
    cVar2 = FUN_00620230();
  }
  else {
    param_1[8] = param_6;
    cVar2 = FUN_00620240();
  }
  if (cVar2 != '\0') {
    (**(code **)(*DAT_00709d80 + 0x5c))(DAT_00709d80,param_1[3],param_1[7],param_1[8],0,param_1 + 1)
    ;
    return param_1;
  }
  uVar1 = param_1[7];
  param_1[7] = uVar1 | 0x10;
  (**(code **)(*DAT_00709d80 + 0x5c))(DAT_00709d80,param_1[3],uVar1 | 0x10,param_1[8],0,param_1 + 1)
  ;
  return param_1;
}


// ==== 0x622a10 FUN_00622a10

undefined4 __fastcall FUN_00622a10(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 **ppuVar8;
  int iStack_50;
  undefined4 **ppuStack_4c;
  int *piStack_48;
  int *piStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 **ppuStack_38;
  undefined4 *puStack_34;
  int *piStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 *puStack_1c;
  undefined4 local_c [3];
  
  iVar4 = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x30);
  local_c[0] = 0;
  puStack_1c = (undefined4 *)0x622a2d;
  EAGL__PC__GetDirectDraw();
  puStack_1c = (undefined4 *)0x622a32;
  cVar2 = FUN_00620230();
  if (cVar2 == '\0') {
    puStack_1c = (undefined4 *)0x622a3b;
    FUN_00620240();
  }
  puStack_1c = local_c;
  uStack_24 = *(undefined4 *)(param_1 + 0x20);
  uStack_20 = 0;
  uStack_28 = *(undefined4 *)(param_1 + 0x1c);
  piStack_30 = DAT_00709d80;
  puStack_34 = (undefined4 *)0x622a56;
  iStack_2c = iVar4;
  iVar3 = (**(code **)(*DAT_00709d80 + 0x5c))();
  if (iVar3 < 0) {
    puStack_34 = &uStack_24;
    uStack_3c = *(undefined4 *)(param_1 + 0x20);
    ppuStack_38 = (undefined4 **)0x2;
    uStack_40 = *(undefined4 *)(param_1 + 0x1c);
    piStack_48 = DAT_00709d80;
    ppuStack_4c = (undefined4 **)0x622a75;
    piStack_44 = (int *)iVar4;
    (**(code **)(*DAT_00709d80 + 0x5c))();
  }
  piStack_44 = *(int **)(param_1 + 4);
  puStack_34 = (undefined4 *)0x1000;
  ppuStack_38 = &puStack_1c;
  uStack_3c = *(undefined4 *)(param_1 + 0xc);
  uStack_40 = 0;
  piStack_48 = (int *)0x622a8e;
  (**(code **)(*piStack_44 + 0x2c))();
  piStack_48 = (int *)0x2000;
  ppuStack_4c = &puStack_34;
  iStack_50 = *(int *)(param_1 + 0xc);
  ppuVar8 = ppuStack_38;
  (*(code *)(*ppuStack_38)[0xb])(ppuStack_38);
  FUN_0063f1b0(piStack_48,piStack_44,*(undefined4 *)(param_1 + 0xc));
  (*(code *)(*ppuStack_4c)[0xc])(ppuStack_4c);
  (**(code **)(**(int **)(param_1 + 4) + 0x30))(*(int **)(param_1 + 4));
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  uVar7 = 0x1000;
  piVar6 = &iStack_50;
  uVar5 = uVar1;
  (**(code **)(iRam00000000 + 0x2c))(0,uVar1,*(undefined4 *)(param_1 + 0x30),piVar6,0x1000);
  FUN_0063f1b0(uVar7,ppuVar8,*(undefined4 *)(param_1 + 0x30));
  (**(code **)(*piVar6 + 0x30))(piVar6);
  (**(code **)(**(int **)(param_1 + 4) + 8))(*(int **)(param_1 + 4));
  *(undefined4 *)(param_1 + 4) = uVar5;
  *(int *)(param_1 + 0xc) = iVar4;
  *(int *)(param_1 + 8) = iVar4;
  FUN_00622910();
  return uVar1;
}


// ==== 0x622b40 FUN_00622b40

void __fastcall FUN_00622b40(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 0x30))(*(int **)(param_1 + 4));
  return;
}


// ==== 0x622b50 FUN_00622b50

void __fastcall FUN_00622b50(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}


// ==== 0x622b70 FUN_00622b70

void __fastcall FUN_00622b70(int param_1)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  
  cVar2 = FUN_00620230();
  if (cVar2 == '\0') {
    cVar2 = FUN_00620240();
    if (cVar2 == '\0') {
      uStack_1c = *(undefined4 *)(param_1 + 0x20);
      iStack_14 = param_1 + 4;
      uStack_18 = 0;
      uVar3 = *(uint *)(param_1 + 0x1c) | 0x10;
      *(uint *)(param_1 + 0x1c) = uVar3;
      (**(code **)(*DAT_00709d80 + 0x5c))(DAT_00709d80,*(undefined4 *)(param_1 + 0xc),uVar3);
      goto LAB_00622bcc;
    }
  }
  uStack_18 = *(undefined4 *)(param_1 + 0x20);
  iStack_14 = 0;
  uStack_1c = *(undefined4 *)(param_1 + 0x1c);
  (**(code **)(*DAT_00709d80 + 0x5c))(DAT_00709d80,*(undefined4 *)(param_1 + 0xc));
LAB_00622bcc:
  if (*(int *)(param_1 + 0x18) != 0) {
    piVar1 = *(int **)(param_1 + 4);
    uVar4 = *(undefined4 *)(param_1 + 0xc);
    (**(code **)(*piVar1 + 0x2c))(piVar1,0,uVar4,&uStack_1c,0);
    FUN_0063f1b0(uVar4,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0xc));
    piVar1 = *(int **)(param_1 + 4);
    (**(code **)(*piVar1 + 0x30))(piVar1);
  }
  return;
}


// ==== 0x622c10 FUN_00622c10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00622c10(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)*param_1;
  if ((puVar1 != (undefined4 *)0x0) && (iVar2 = 0, 0 < DAT_006e2a8c)) {
    while (*(undefined4 **)(DAT_0070a488 + iVar2 * 4) != puVar1) {
      iVar2 = iVar2 + 1;
      if (DAT_006e2a8c <= iVar2) {
        return;
      }
    }
    (**(code **)*puVar1)(1);
    *param_1 = 0;
    *(undefined4 *)(DAT_0070a488 + iVar2 * 4) = 0;
    _DAT_0070a498 = _DAT_0070a498 + -1;
  }
  return;
}


// ==== 0x622c60 FUN_00622c60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00622c60(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*param_1 != 0) {
    if (*param_1 == (&DAT_0070a428)[param_2]) {
      (&DAT_0070a428)[param_2] = 0;
    }
    iVar2 = 0;
    if (0 < DAT_006e2a8c) {
      puVar1 = (undefined4 *)*param_1;
      while (*(undefined4 **)(DAT_0070a488 + iVar2 * 4) != puVar1) {
        iVar2 = iVar2 + 1;
        if (DAT_006e2a8c <= iVar2) {
          return;
        }
      }
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      *param_1 = 0;
      *(undefined4 *)(DAT_0070a488 + iVar2 * 4) = 0;
      _DAT_0070a498 = _DAT_0070a498 + -1;
    }
  }
  return;
}


// ==== 0x622cd0 EAGL::VertexBuffer::New

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render med (hopper+ghidra) docs/re/render.md */

void EAGL__VertexBuffer__New
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,int param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_6 == 0) {
    param_6 = param_1;
  }
  iVar1 = (*(code *)PTR_FUN_006dfa9c)(0x24,"EAGL::VertexBuffer new");
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00622970(param_6,param_2,param_3,param_5,param_4,0);
  }
  iVar1 = 0;
  if (0 < DAT_006e2a8c) {
    while (*(int *)(DAT_0070a488 + iVar1 * 4) != 0) {
      iVar1 = iVar1 + 1;
      if (DAT_006e2a8c <= iVar1) {
        return;
      }
    }
    *(undefined4 *)(DAT_0070a488 + iVar1 * 4) = uVar2;
    _DAT_0070a498 = _DAT_0070a498 + 1;
  }
  return;
}


// ==== 0x622d40 FUN_00622d40

int __thiscall FUN_00622d40(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  char cVar1;
  
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (param_4 == 0) {
    cVar1 = FUN_00620230();
  }
  else {
    cVar1 = FUN_00620240();
  }
  if (cVar1 == '\0') {
    param_3 = param_3 | 0x10;
  }
  *(uint *)(param_1 + 0xc) = param_3;
  (**(code **)(*DAT_00709d80 + 0x60))
            (DAT_00709d80,*(undefined4 *)(param_1 + 8),param_3,0x65,0,param_1);
  return param_1;
}


// ==== 0x622da0 FUN_00622da0

void __thiscall
FUN_00622da0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  (**(code **)(*(int *)*param_1 + 0x2c))((int *)*param_1,param_2,param_3,param_4,param_5);
  return;
}


// ==== 0x622dc0 FUN_00622dc0

void __fastcall FUN_00622dc0(undefined4 *param_1)

{
  (**(code **)(*(int *)*param_1 + 0x30))((int *)*param_1);
  return;
}


// ==== 0x622dd0 FUN_00622dd0

void __fastcall FUN_00622dd0(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[4];
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[4] = iVar1 + -1;
  if ((iVar1 + -1 == 0) && (*(char *)(param_1 + 3) == '\0')) {
    (**(code **)(*DAT_00709d80 + 0x138))(DAT_00709d80,*param_1);
  }
  if (param_1[6] != 0) {
    *(undefined4 *)(param_1[6] + 0x14) = param_1[5];
  }
  if (param_1[5] != 0) {
    *(undefined4 *)(param_1[5] + 0x18) = param_1[6];
  }
  if (param_1 == DAT_0070a4a4) {
    DAT_0070a4a4 = (undefined4 *)param_1[5];
  }
  param_1[6] = 0;
  param_1[5] = 0;
  return;
}


// ==== 0x622e30 FUN_00622e30

void __fastcall FUN_00622e30(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2];
  param_1[1] = 0;
  param_1[2] = iVar1 + -1;
  if ((iVar1 + -1 == 0) && (*param_1 != 0)) {
    (**(code **)(*DAT_00709d80 + 0x168))(DAT_00709d80,*param_1);
  }
  if (param_1[4] != 0) {
    *(int *)(param_1[4] + 0xc) = param_1[3];
  }
  if (param_1[3] != 0) {
    *(int *)(param_1[3] + 0x10) = param_1[4];
  }
  if (param_1 == DAT_0070a4a8) {
    DAT_0070a4a8 = (int *)param_1[3];
  }
  param_1[4] = 0;
  param_1[3] = 0;
  return;
}


// ==== 0x622e90 FUN_00622e90

void FUN_00622e90(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_006e2a8c) {
    do {
      piVar1 = *(int **)(DAT_0070a488 + iVar3 * 4);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))();
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_006e2a8c);
  }
  iVar3 = 0;
  if (0 < DAT_006e2a90) {
    do {
      piVar1 = *(int **)(DAT_0070a48c + iVar3 * 4);
      if ((piVar1 != (int *)0x0) && (piVar2 = (int *)*piVar1, piVar2 != (int *)0x0)) {
        (**(code **)(*piVar2 + 8))(piVar2);
        *piVar1 = 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_006e2a90);
  }
  return;
}


// ==== 0x622f00 FUN_00622f00

void __fastcall FUN_00622f00(undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uStack_4;
  
  iVar4 = 0;
  uStack_4 = param_1;
  if (0 < DAT_006e2a8c) {
    do {
      piVar1 = *(int **)(DAT_0070a488 + iVar4 * 4);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))();
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_006e2a8c);
  }
  iVar4 = 0;
  if (0 < DAT_006e2a90) {
    do {
      puVar2 = *(undefined4 **)(DAT_0070a48c + iVar4 * 4);
      if (puVar2 != (undefined4 *)0x0) {
        cVar3 = FUN_00620230();
        if (cVar3 == '\0') {
          FUN_00620240();
        }
        (**(code **)(*DAT_00709d80 + 0x60))(DAT_00709d80,puVar2[2],puVar2[3],0x65,0,puVar2);
        if (puVar2[4] != 0) {
          uVar5 = puVar2[2];
          (**(code **)(*(int *)*puVar2 + 0x2c))((int *)*puVar2,0,uVar5,&uStack_4,0);
          FUN_0063f1b0(uVar5,puVar2[4],puVar2[2]);
          (**(code **)(*(int *)*puVar2 + 0x30))((int *)*puVar2);
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_006e2a90);
  }
  return;
}


// ==== 0x622fb0 FUN_00622fb0

void FUN_00622fb0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  
  for (puVar2 = DAT_0070a4a4; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)puVar2[5]) {
    if (*(char *)(puVar2 + 3) == '\0') {
      piVar1 = puVar2 + 4;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)(*DAT_00709d80 + 0x138))(DAT_00709d80,*puVar2);
      }
      *puVar2 = 0;
    }
  }
  return;
}


// ==== 0x622ff0 FUN_00622ff0

void FUN_00622ff0(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  
  for (iVar1 = DAT_0070a4a4; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x14)) {
    if (((*(char *)(iVar1 + 0xc) == '\0') && (*(int *)(iVar1 + 4) != 0)) &&
       (*(int *)(iVar1 + 8) != 0)) {
      cVar2 = FUN_00620230();
      if (cVar2 == '\0') {
        FUN_0061f7a0(1);
        uVar3 = 0x10;
      }
      else {
        FUN_0061f7a0(0);
        uVar3 = 0;
      }
      (**(code **)(*DAT_00709d80 + 300))
                (DAT_00709d80,*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 8),iVar1,uVar3);
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
    }
  }
  return;
}


// ==== 0x623060 FUN_00623060

void FUN_00623060(void)

{
  int *piVar1;
  int *piVar2;
  
  for (piVar2 = DAT_0070a4a8; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[3]) {
    piVar1 = piVar2 + 2;
    *piVar1 = *piVar1 + -1;
    if ((*piVar1 == 0) && (*piVar2 != 0)) {
      (**(code **)(*DAT_00709d80 + 0x168))(DAT_00709d80,*piVar2);
    }
  }
  return;
}


// ==== 0x6230a0 FUN_006230a0

void FUN_006230a0(void)

{
  int iVar1;
  
  for (iVar1 = DAT_0070a4a8; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
    if (*(int *)(iVar1 + 4) != 0) {
      (**(code **)(*DAT_00709d80 + 0x15c))(DAT_00709d80,*(int *)(iVar1 + 4),iVar1);
    }
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  }
  return;
}


// ==== 0x6230e0 FUN_006230e0

int __thiscall
FUN_006230e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  undefined4 unaff_EDI;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 local_4;
  
  iVar2 = DAT_00709570;
  if (*(char *)(param_1 + 0x40) != '\0') {
    if (*(char *)(*(int *)(param_1 + 0x3c) + 0xc) != '\0') {
      (**(code **)(**(int **)(param_1 + 4) + 0x2c))
                (*(int **)(param_1 + 4),0,*(undefined4 *)(param_1 + 0x30),&param_5,0);
      FUN_0063f1b0(local_4,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x30));
      (**(code **)(**(int **)(param_1 + 4) + 0x30))(*(int **)(param_1 + 4));
      *(undefined1 *)(*(int *)(param_1 + 0x3c) + 0xc) = 0;
      FUN_00622910();
    }
    (**(code **)(**(int **)(param_1 + 4) + 0x2c))
              (*(int **)(param_1 + 4),0,*(undefined4 *)(param_1 + 0x30),param_4,0);
    return 0;
  }
  iVar6 = *(int *)(param_1 + 0x38) + -1;
  if (0 < iVar6) {
    iVar6 = DAT_00709f70;
  }
  piVar7 = (int *)(iVar6 * 0x210 + *(int *)(param_1 + 0x3c));
  if (DAT_00709570 != *(int *)(iVar6 * 0x210 + *(int *)(param_1 + 0x3c))) {
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *piVar7 = iVar2;
    piVar7[1] = 0;
  }
  iVar2 = piVar7[1];
  piVar7[1] = iVar2 + 1;
  uVar4 = piVar7[iVar2 + 4];
  if (uVar4 == 0xffffffff) {
    uVar4 = FUN_00622a10(param_5);
    piVar7[iVar2 + 4] = uVar4;
    *(undefined1 *)(piVar7 + 3) = 1;
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  }
  if ((char)piVar7[3] != '\0') {
    piVar5 = piVar7 + 4;
    iVar2 = piVar7[4];
    while (iVar2 != -1) {
      (**(code **)(**(int **)(param_1 + 4) + 0x2c))
                (*(int **)(param_1 + 4),iVar2,*(undefined4 *)(param_1 + 0x30),&local_4,0);
      FUN_0063f1b0(unaff_EDI,local_4,*(undefined4 *)(param_1 + 0x30));
      (**(code **)(**(int **)(param_1 + 4) + 0x30))(*(int **)(param_1 + 4));
      piVar1 = piVar5 + 1;
      piVar5 = piVar5 + 1;
      iVar2 = *piVar1;
    }
    *(undefined1 *)(piVar7 + 3) = 0;
    FUN_00622910();
  }
  uVar3 = *(uint *)(param_1 + 0x30);
  iVar2 = *(int *)(param_1 + 0x34);
  if (*(int *)(param_1 + 0x2c) == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = 0x1000;
  }
  (**(code **)(**(int **)(param_1 + 4) + 0x2c))(*(int **)(param_1 + 4),uVar4,uVar3,param_4,uVar8);
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
  return (uVar4 / uVar3) * iVar2;
}


// ==== 0x623260 FUN_00623260

undefined4 * __thiscall FUN_00623260(undefined4 *param_1,byte param_2)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[1];
  *param_1 = &PTR_FUN_006a79c0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  param_1[1] = 0;
  param_1[6] = 0;
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x24);
  }
  return param_1;
}


// ==== 0x6232a0 FUN_006232a0

void __thiscall FUN_006232a0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  uVar1 = param_3;
  uVar3 = 0x2000;
  puVar2 = &param_3;
  (**(code **)(**(int **)(param_1 + 4) + 0x2c))(*(int **)(param_1 + 4),0,param_3,puVar2,0x2000);
  FUN_0063f1b0(uVar3,puVar2,uVar1);
  (**(code **)(**(int **)(param_1 + 4) + 0x30))(*(int **)(param_1 + 4));
  *(undefined4 *)(param_1 + 8) = uVar1;
  return;
}


// ==== 0x6232f0 EAGL::IndexBuffer::New

/* [canon] render med (hopper+ghidra) docs/re/render.md */

void EAGL__IndexBuffer__New(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_FUN_006dfa9c)(0x14,"EAGL::IndexBuffer new");
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00622d40(param_1,param_3,param_2);
  }
  iVar1 = 0;
  if (0 < DAT_006e2a90) {
    while (*(int *)(DAT_0070a48c + iVar1 * 4) != 0) {
      iVar1 = iVar1 + 1;
      if (DAT_006e2a90 <= iVar1) {
        return;
      }
    }
    *(undefined4 *)(DAT_0070a48c + iVar1 * 4) = uVar2;
    DAT_0070a49c = DAT_0070a49c + 1;
  }
  return;
}


// ==== 0x623350 FUN_00623350

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00623350(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (DAT_0070a4a0 != '\0') {
    iVar6 = 0;
    if (0 < DAT_006e2a90) {
      do {
        piVar1 = *(int **)(DAT_0070a48c + iVar6 * 4);
        if (piVar1 != (int *)0x0) {
          piVar2 = (int *)*piVar1;
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 8))(piVar2);
          }
          *piVar1 = 0;
          piVar1[4] = 0;
          (*(code *)PTR_FUN_006dfaa0)(piVar1,0x14);
          DAT_0070a49c = DAT_0070a49c + -1;
        }
        *(undefined4 *)(DAT_0070a48c + iVar6 * 4) = 0;
        iVar6 = iVar6 + 1;
      } while (iVar6 < DAT_006e2a90);
    }
    iVar6 = 0;
    if (0 < DAT_006e2a8c) {
      do {
        puVar3 = *(undefined4 **)(DAT_0070a488 + iVar6 * 4);
        if (puVar3 != (undefined4 *)0x0) {
          (**(code **)*puVar3)(1);
          _DAT_0070a498 = _DAT_0070a498 + -1;
        }
        *(undefined4 *)(DAT_0070a488 + iVar6 * 4) = 0;
        iVar6 = iVar6 + 1;
      } while (iVar6 < DAT_006e2a8c);
    }
    iVar5 = 0;
    iVar6 = DAT_006e2a8c;
    if (0 < DAT_006e2a8c) {
      iVar7 = 0;
      do {
        iVar4 = *(int *)(iVar7 + 0x10 + DAT_0070a4ac);
        puVar3 = (undefined4 *)(iVar7 + 0x10 + DAT_0070a4ac);
        if (iVar4 != 0) {
          (*(code *)PTR_FUN_006dfaa0)(iVar4,iVar6 << 2);
          *puVar3 = 0;
          iVar6 = DAT_006e2a8c;
        }
        iVar5 = iVar5 + 1;
        iVar7 = iVar7 + 0x14;
      } while (iVar5 < iVar6);
    }
    if (DAT_0070a48c != 0) {
      (*(code *)PTR_FUN_006dfaa0)(DAT_0070a48c,DAT_006e2a90 * 4);
      iVar6 = DAT_006e2a8c;
    }
    if (DAT_0070a488 != 0) {
      (*(code *)PTR_FUN_006dfaa0)(DAT_0070a488,iVar6 * 4);
      iVar6 = DAT_006e2a8c;
    }
    if (DAT_0070a4ac != 0) {
      (*(code *)PTR_FUN_006dfaa0)(DAT_0070a4ac,0x14);
      iVar6 = DAT_006e2a8c;
    }
    if (DAT_0070a490 != 0) {
      (*(code *)PTR_FUN_006dfaa0)(DAT_0070a490,iVar6 << 2);
    }
    if (DAT_0070a494 != 0) {
      (*(code *)PTR_FUN_006dfaa0)(DAT_0070a494,DAT_006e2a90 * 4);
    }
    DAT_0070a4a0 = '\0';
  }
  return;
}


// ==== 0x6234f0 thunk_FUN_00623350

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_00623350(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (DAT_0070a4a0 != '\0') {
    iVar6 = 0;
    if (0 < DAT_006e2a90) {
      do {
        piVar1 = *(int **)(DAT_0070a48c + iVar6 * 4);
        if (piVar1 != (int *)0x0) {
          piVar2 = (int *)*piVar1;
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 8))(piVar2);
          }
          *piVar1 = 0;
          piVar1[4] = 0;
          (*(code *)PTR_FUN_006dfaa0)(piVar1,0x14);
          DAT_0070a49c = DAT_0070a49c + -1;
        }
        *(undefined4 *)(DAT_0070a48c + iVar6 * 4) = 0;
        iVar6 = iVar6 + 1;
      } while (iVar6 < DAT_006e2a90);
    }
    iVar6 = 0;
    if (0 < DAT_006e2a8c) {
      do {
        puVar3 = *(undefined4 **)(DAT_0070a488 + iVar6 * 4);
        if (puVar3 != (undefined4 *)0x0) {
          (**(code **)*puVar3)(1);
          _DAT_0070a498 = _DAT_0070a498 + -1;
        }
        *(undefined4 *)(DAT_0070a488 + iVar6 * 4) = 0;
        iVar6 = iVar6 + 1;
      } while (iVar6 < DAT_006e2a8c);
    }
    iVar5 = 0;
    iVar6 = DAT_006e2a8c;
    if (0 < DAT_006e2a8c) {
      iVar7 = 0;
      do {
        iVar4 = *(int *)(iVar7 + 0x10 + DAT_0070a4ac);
        puVar3 = (undefined4 *)(iVar7 + 0x10 + DAT_0070a4ac);
        if (iVar4 != 0) {
          (*(code *)PTR_FUN_006dfaa0)(iVar4,iVar6 << 2);
          *puVar3 = 0;
          iVar6 = DAT_006e2a8c;
        }
        iVar5 = iVar5 + 1;
        iVar7 = iVar7 + 0x14;
      } while (iVar5 < iVar6);
    }
    if (DAT_0070a48c != 0) {
      (*(code *)PTR_FUN_006dfaa0)(DAT_0070a48c,DAT_006e2a90 * 4);
      iVar6 = DAT_006e2a8c;
    }
    if (DAT_0070a488 != 0) {
      (*(code *)PTR_FUN_006dfaa0)(DAT_0070a488,iVar6 * 4);
      iVar6 = DAT_006e2a8c;
    }
    if (DAT_0070a4ac != 0) {
      (*(code *)PTR_FUN_006dfaa0)(DAT_0070a4ac,0x14);
      iVar6 = DAT_006e2a8c;
    }
    if (DAT_0070a490 != 0) {
      (*(code *)PTR_FUN_006dfaa0)(DAT_0070a490,iVar6 << 2);
    }
    if (DAT_0070a494 != 0) {
      (*(code *)PTR_FUN_006dfaa0)(DAT_0070a494,DAT_006e2a90 * 4);
    }
    DAT_0070a4a0 = '\0';
  }
  return;
}


// ==== 0x623500 FUN_00623500

void FUN_00623500(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if (*param_1 != 0) {
    if (*param_1 == DAT_0070a41c) {
      DAT_0070a41c = 0;
    }
    iVar3 = 0;
    if (0 < DAT_006e2a90) {
      piVar1 = (int *)*param_1;
      while (*(int **)(DAT_0070a48c + iVar3 * 4) != piVar1) {
        iVar3 = iVar3 + 1;
        if (DAT_006e2a90 <= iVar3) {
          return;
        }
      }
      if (piVar1 != (int *)0x0) {
        piVar2 = (int *)*piVar1;
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 8))(piVar2);
        }
        *piVar1 = 0;
        piVar1[4] = 0;
        (*(code *)PTR_FUN_006dfaa0)(piVar1,0x14);
      }
      *param_1 = 0;
      *(undefined4 *)(DAT_0070a48c + iVar3 * 4) = 0;
      DAT_0070a49c = DAT_0070a49c + -1;
    }
  }
  return;
}


// ==== 0x623590 FUN_00623590

void FUN_00623590(void)

{
  int *piVar1;
  int *piVar2;
  
  for (piVar2 = DAT_0070a4f8; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[3]) {
    piVar1 = *(int **)(*piVar2 + 0x44);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(*piVar2 + 0x44) = 0;
    }
  }
  return;
}


// ==== 0x6235d0 FUN_006235d0

void FUN_006235d0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar1 = DAT_0070a4f8;
  while (piVar5 = piVar1, piVar5 != (int *)0x0) {
    piVar1 = (int *)piVar5[3];
    iVar2 = piVar5[2];
    if (piVar5[1] != 0) {
      iVar3 = *(int *)(piVar5[1] + 0x24);
      if ((iVar3 == 0) || (piVar4 = *(int **)(iVar3 + 0x18), piVar4 == (int *)0x0)) {
        if (iVar2 != 0) {
          *(int **)(iVar2 + 0xc) = piVar1;
        }
        if (piVar5[3] != 0) {
          *(int *)(piVar5[3] + 8) = iVar2;
        }
        if (DAT_0070a4f8 == piVar5) {
          DAT_0070a4f8 = piVar1;
        }
        *piVar5 = 0;
        piVar5[1] = 0;
        piVar5[2] = 0;
        piVar5[3] = 0;
        (*(code *)PTR_FUN_006dfaa0)(piVar5,0x10);
      }
      else {
        (**(code **)(*piVar4 + 0x3c))(piVar4,0,*piVar5 + 0x44);
      }
    }
  }
  return;
}


// ==== 0x623650 FUN_00623650

void FUN_00623650(void)

{
  int iVar1;
  int *piVar2;
  
  for (piVar2 = DAT_0070a4fc; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[3]) {
    if (piVar2[1] != 0) {
      iVar1 = *(int *)(*(int *)(piVar2[1] + 0x24) + 0x1c);
      if (iVar1 == 0) {
        if (piVar2[2] != 0) {
          *(int *)(piVar2[2] + 0xc) = piVar2[3];
        }
        if (piVar2[3] != 0) {
          *(int *)(piVar2[3] + 8) = piVar2[2];
        }
        if (DAT_0070a4fc == piVar2) {
          DAT_0070a4fc = (int *)piVar2[3];
        }
        *piVar2 = 0;
        piVar2[1] = 0;
        piVar2[2] = 0;
        piVar2[3] = 0;
        (*(code *)PTR_FUN_006dfaa0)(piVar2,0x10);
        piVar2 = (int *)0x0;
      }
      else {
        *(int *)(*piVar2 + 0x48) = iVar1;
      }
    }
  }
  return;
}


// ==== 0x6236d0 FUN_006236d0

void __fastcall FUN_006236d0(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (iVar1 == 0) {
      *param_1 = 4;
    }
    else {
      param_1[iVar1] = 1;
    }
    param_1[iVar1 + 8] = 1;
    param_1[iVar1 + 0x10] = 2;
    param_1[iVar1 + 0x18] = 1;
    if (iVar1 == 0) {
      param_1[0x20] = 2;
    }
    else {
      param_1[iVar1 + 0x20] = 1;
    }
    param_1[iVar1 + 0x28] = 1;
    param_1[iVar1 + 0x30] = 2;
    param_1[iVar1 + 0x38] = 1;
    param_1[iVar1 + 0x40] = 1;
    param_1[iVar1 + 0x48] = 0;
    param_1[iVar1 + 0x50] = 0;
    param_1[iVar1 + 0x58] = 0;
    param_1[iVar1 + 0x60] = 0;
    param_1[iVar1 + 0x68] = iVar1;
    param_1[iVar1 + 0x70] = 0;
    param_1[iVar1 + 0x78] = 0;
    param_1[iVar1 + 0x80] = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  param_1[0x88] = 0;
  return;
}


// ==== 0x623780 FUN_00623780

void __fastcall FUN_00623780(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  iVar2 = FUN_00622930();
  if (iVar2 == 0) {
    uVar4 = 0;
    piVar3 = (int *)(param_1 + 0x40);
    do {
      if (piVar3[-0x10] != (&DAT_0070a758)[uVar4]) {
        (&DAT_0070a758)[uVar4] = piVar3[-0x10];
        (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,uVar4,1,piVar3[-0x10]);
        piVar1 = DAT_00709d80;
        if (((piVar3[-0x10] == 2) && (*piVar3 == 0)) || ((piVar3[-0x10] == 3 && (piVar3[8] == 0))))
        {
          (&DAT_00709eb4)[uVar4] = 0;
          (**(code **)(*piVar1 + 0xf4))(piVar1,uVar4,0);
        }
      }
      if (piVar3[-8] != (&DAT_0070a778)[uVar4]) {
        (&DAT_0070a778)[uVar4] = piVar3[-8];
        (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,uVar4,0x1a,piVar3[-8]);
      }
      if (*piVar3 != *(int *)((int)piVar3 + ((int)&DAT_0070a758 - param_1))) {
        *(int *)((int)piVar3 + ((int)&DAT_0070a758 - param_1)) = *piVar3;
        (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,uVar4,2,*piVar3);
      }
      if (piVar3[8] != *(int *)(((int)&DAT_0070a778 - param_1) + (int)piVar3)) {
        *(int *)(((int)&DAT_0070a778 - param_1) + (int)piVar3) = piVar3[8];
        (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,uVar4,3,piVar3[8]);
      }
      if (piVar3[0x10] != *(int *)(((int)&DAT_0070a798 - param_1) + (int)piVar3)) {
        *(int *)(((int)&DAT_0070a798 - param_1) + (int)piVar3) = piVar3[0x10];
        (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,uVar4,4,piVar3[0x10]);
      }
      if (piVar3[0x18] != *(int *)(((int)&DAT_0070a7b8 - param_1) + (int)piVar3)) {
        *(int *)(((int)&DAT_0070a7b8 - param_1) + (int)piVar3) = piVar3[0x18];
        (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,uVar4,0x1b,piVar3[0x18]);
      }
      if (piVar3[0x20] != *(int *)(((int)&DAT_0070a7d8 - param_1) + (int)piVar3)) {
        *(int *)(((int)&DAT_0070a7d8 - param_1) + (int)piVar3) = piVar3[0x20];
        (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,uVar4,5,piVar3[0x20]);
      }
      if (piVar3[0x28] != *(int *)(((int)&DAT_0070a7f8 - param_1) + (int)piVar3)) {
        *(int *)(((int)&DAT_0070a7f8 - param_1) + (int)piVar3) = piVar3[0x28];
        (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,uVar4,6,piVar3[0x28]);
      }
      if (piVar3[0x30] != *(int *)(((int)&DAT_0070a818 - param_1) + (int)piVar3)) {
        *(int *)(((int)&DAT_0070a818 - param_1) + (int)piVar3) = piVar3[0x30];
        (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,uVar4,0x1c,piVar3[0x30]);
      }
      if (piVar3[0x38] != *(int *)(((int)&DAT_0070a838 - param_1) + (int)piVar3)) {
        *(int *)(((int)&DAT_0070a838 - param_1) + (int)piVar3) = piVar3[0x38];
        (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,uVar4,7,piVar3[0x38]);
      }
      if (piVar3[0x40] != *(int *)(((int)&DAT_0070a858 - param_1) + (int)piVar3)) {
        *(int *)(((int)&DAT_0070a858 - param_1) + (int)piVar3) = piVar3[0x40];
        (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,uVar4,8,piVar3[0x40]);
      }
      if (piVar3[0x48] != *(int *)(((int)&DAT_0070a878 - param_1) + (int)piVar3)) {
        *(int *)(((int)&DAT_0070a878 - param_1) + (int)piVar3) = piVar3[0x48];
        (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,uVar4,9,piVar3[0x48]);
      }
      if (piVar3[0x50] != *(int *)(((int)&DAT_0070a898 - param_1) + (int)piVar3)) {
        *(int *)(((int)&DAT_0070a898 - param_1) + (int)piVar3) = piVar3[0x50];
        (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,uVar4,10,piVar3[0x50]);
      }
      if (piVar3[0x58] != *(int *)(((int)&DAT_0070a8b8 - param_1) + (int)piVar3)) {
        *(int *)(((int)&DAT_0070a8b8 - param_1) + (int)piVar3) = piVar3[0x58];
        (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,uVar4,0xb,piVar3[0x58]);
      }
      if (piVar3[0x60] != *(int *)(((int)&DAT_0070a8d8 - param_1) + (int)piVar3)) {
        *(int *)(((int)&DAT_0070a8d8 - param_1) + (int)piVar3) = piVar3[0x60];
        (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,uVar4,0x16,piVar3[0x60]);
      }
      if (piVar3[0x68] != *(int *)(((int)&DAT_0070a8f8 - param_1) + (int)piVar3)) {
        *(int *)(((int)&DAT_0070a8f8 - param_1) + (int)piVar3) = piVar3[0x68];
        (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,uVar4,0x17,piVar3[0x68]);
      }
      if (piVar3[0x70] != *(int *)(((int)&DAT_0070a918 - param_1) + (int)piVar3)) {
        *(int *)(((int)&DAT_0070a918 - param_1) + (int)piVar3) = piVar3[0x70];
        (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,uVar4,0x18,piVar3[0x70]);
      }
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 1;
      piVar1 = DAT_00709d80;
    } while (uVar4 <= *(uint *)(param_1 + 0x220));
    for (; DAT_00709d80 = piVar1, uVar4 < 8; uVar4 = uVar4 + 1) {
      if ((&DAT_0070a758)[uVar4] != 1) {
        (&DAT_0070a758)[uVar4] = 1;
        (**(code **)(*piVar1 + 0xfc))(piVar1,uVar4,1,*(undefined4 *)(param_1 + uVar4 * 4));
      }
      piVar1 = DAT_00709d80;
    }
  }
  return;
}


// ==== 0x623f40 FUN_00623f40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00623f40(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar2 = 0;
  do {
    if (iVar2 == 0) {
      DAT_0070a758 = 4;
    }
    else {
      (&DAT_0070a758)[iVar2] = 1;
    }
    (&DAT_0070a778)[iVar2] = 1;
    (&DAT_0070a798)[iVar2] = 2;
    (&DAT_0070a7b8)[iVar2] = 1;
    if (iVar2 == 0) {
      DAT_0070a7d8 = 2;
    }
    else {
      (&DAT_0070a7d8)[iVar2] = 1;
    }
    (&DAT_0070a7f8)[iVar2] = 1;
    (&DAT_0070a818)[iVar2] = 2;
    (&DAT_0070a838)[iVar2] = 1;
    (&DAT_0070a858)[iVar2] = 1;
    (&DAT_0070a878)[iVar2] = 0;
    (&DAT_0070a898)[iVar2] = 0;
    (&DAT_0070a8b8)[iVar2] = 0;
    (&DAT_0070a8d8)[iVar2] = 0;
    (&DAT_0070a8f8)[iVar2] = iVar2;
    (&DAT_0070a918)[iVar2] = 0;
    (&DAT_0070a938)[iVar2] = 0;
    (&DAT_0070a958)[iVar2] = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  _DAT_0070a978 = 0;
  FUN_0063f1b0(&DAT_0070a518,&DAT_0070a758,0x224);
  iVar2 = EAGL__PC__GetDirectDraw();
  iVar2 = *(int *)(iVar2 + 0x2b8) + -1;
  iVar4 = 0;
  if (-1 < iVar2) {
    puVar3 = &DAT_0070a798;
    do {
      (&DAT_0070a758)[iVar4] = puVar3[-0x10];
      (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,iVar4,1,puVar3[-0x10]);
      (&DAT_0070a778)[iVar4] = puVar3[-8];
      piVar5 = DAT_00709d80;
      (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,iVar4,0x1a,puVar3[-8]);
      *puVar3 = *puVar3;
      iVar10 = iVar4;
      (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,iVar4,2,*puVar3);
      *(undefined4 *)((int)piVar5 + (int)puVar3) = puVar3[8];
      iVar9 = 3;
      (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,iVar4,3,puVar3[8]);
      *(undefined4 *)(iVar10 + (int)puVar3) = puVar3[0x10];
      iVar10 = puVar3[0x10];
      piVar5 = DAT_00709d80;
      (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,iVar4,4);
      *(undefined4 *)(iVar9 + (int)puVar3) = puVar3[0x18];
      iVar9 = iVar4;
      (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,iVar4,0x1b,puVar3[0x18]);
      *(undefined4 *)(iVar10 + (int)puVar3) = puVar3[0x20];
      iVar8 = 5;
      (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,iVar4,5,puVar3[0x20]);
      *(undefined4 *)((int)piVar5 + (int)puVar3) = puVar3[0x28];
      iVar10 = puVar3[0x28];
      piVar7 = DAT_00709d80;
      (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,iVar4,6);
      *(undefined4 *)(iVar9 + (int)puVar3) = puVar3[0x30];
      iVar6 = iVar4;
      (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,iVar4,0x1c,puVar3[0x30]);
      *(undefined4 *)(iVar8 + (int)puVar3) = puVar3[0x38];
      iVar8 = 7;
      (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,iVar4,7,puVar3[0x38]);
      *(undefined4 *)(iVar10 + (int)puVar3) = puVar3[0x40];
      iVar10 = puVar3[0x40];
      piVar5 = DAT_00709d80;
      (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,iVar4,8);
      *(undefined4 *)((int)piVar7 + (int)puVar3) = puVar3[0x48];
      iVar9 = iVar4;
      (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,iVar4,9,puVar3[0x48]);
      *(undefined4 *)(iVar6 + (int)puVar3) = puVar3[0x50];
      (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,iVar4,10,puVar3[0x50]);
      *(undefined4 *)(iVar8 + (int)puVar3) = puVar3[0x58];
      (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,iVar4,0xb,puVar3[0x58]);
      *(undefined4 *)(iVar10 + (int)puVar3) = puVar3[0x60];
      (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,iVar4,0x16,puVar3[0x60]);
      *(undefined4 *)((int)piVar5 + (int)puVar3) = puVar3[0x68];
      (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,iVar4,0x17,puVar3[0x68]);
      *(undefined4 *)(iVar9 + (int)puVar3) = puVar3[0x70];
      (**(code **)(*DAT_00709d80 + 0xfc))(DAT_00709d80,iVar4,0x18,puVar3[0x70]);
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar4 <= iVar2);
    if (7 < iVar4) {
      return;
    }
  }
  puVar3 = &DAT_0070a8f8 + iVar4;
  do {
    piVar5 = DAT_00709d80;
    (&DAT_0070a758)[iVar4] = 1;
    (**(code **)(*piVar5 + 0xfc))(piVar5,iVar4,1,1);
    piVar5 = DAT_00709d80;
    (&DAT_0070a7d8)[iVar4] = 1;
    (**(code **)(*piVar5 + 0xfc))(piVar5,iVar4,4,1);
    piVar5 = DAT_00709d80;
    uVar1 = *puVar3;
    (&DAT_0070a8f8)[iVar4] = uVar1;
    (**(code **)(*piVar5 + 0xfc))(piVar5,iVar4,0xb,uVar1);
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar4 < 8);
  return;
}


// ==== 0x624000 FUN_00624000

void FUN_00624000(int param_1,int param_2,float *param_3,int param_4)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  int iVar12;
  int iVar13;
  
  pfVar1 = (float *)(param_1 * 0x10 + param_4);
  iVar12 = ((uint)*pfVar1 & 0xff) * 0x40;
  pfVar2 = (float *)(iVar12 + param_2);
  fVar6 = pfVar2[1];
  fVar7 = pfVar2[2];
  fVar8 = pfVar2[3];
  iVar12 = iVar12 + param_2;
  iVar13 = ((uint)pfVar1[1] & 0xff) * 0x40;
  pfVar3 = (float *)(iVar13 + param_2);
  fVar9 = pfVar3[1];
  fVar10 = pfVar3[2];
  fVar11 = pfVar3[3];
  iVar13 = iVar13 + param_2;
  fVar4 = *pfVar1;
  fVar5 = pfVar1[1];
  *param_3 = *pfVar2 * fVar4 + *pfVar3 * fVar5;
  param_3[1] = fVar6 * fVar4 + fVar9 * fVar5;
  param_3[2] = fVar7 * fVar4 + fVar10 * fVar5;
  param_3[3] = fVar8 * fVar4 + fVar11 * fVar5;
  fVar6 = *(float *)(iVar13 + 0x14);
  fVar7 = *(float *)(iVar13 + 0x18);
  fVar8 = *(float *)(iVar13 + 0x1c);
  fVar9 = *(float *)(iVar12 + 0x14);
  fVar10 = *(float *)(iVar12 + 0x18);
  fVar11 = *(float *)(iVar12 + 0x1c);
  param_3[4] = *(float *)(iVar12 + 0x10) * fVar4 + *(float *)(iVar13 + 0x10) * fVar5;
  param_3[5] = fVar9 * fVar4 + fVar6 * fVar5;
  param_3[6] = fVar10 * fVar4 + fVar7 * fVar5;
  param_3[7] = fVar11 * fVar4 + fVar8 * fVar5;
  fVar6 = *(float *)(iVar13 + 0x24);
  fVar7 = *(float *)(iVar13 + 0x28);
  fVar8 = *(float *)(iVar13 + 0x2c);
  fVar9 = *(float *)(iVar12 + 0x24);
  fVar10 = *(float *)(iVar12 + 0x28);
  fVar11 = *(float *)(iVar12 + 0x2c);
  param_3[8] = *(float *)(iVar12 + 0x20) * fVar4 + *(float *)(iVar13 + 0x20) * fVar5;
  param_3[9] = fVar9 * fVar4 + fVar6 * fVar5;
  param_3[10] = fVar10 * fVar4 + fVar7 * fVar5;
  param_3[0xb] = fVar11 * fVar4 + fVar8 * fVar5;
  fVar6 = *(float *)(iVar13 + 0x34);
  fVar7 = *(float *)(iVar13 + 0x38);
  fVar8 = *(float *)(iVar13 + 0x3c);
  fVar9 = *(float *)(iVar12 + 0x34);
  fVar10 = *(float *)(iVar12 + 0x38);
  fVar11 = *(float *)(iVar12 + 0x3c);
  param_3[0xc] = *(float *)(iVar12 + 0x30) * fVar4 + *(float *)(iVar13 + 0x30) * fVar5;
  param_3[0xd] = fVar9 * fVar4 + fVar6 * fVar5;
  param_3[0xe] = fVar10 * fVar4 + fVar7 * fVar5;
  param_3[0xf] = fVar11 * fVar4 + fVar8 * fVar5;
  return;
}


// ==== 0x6240b0 FUN_006240b0

void FUN_006240b0(int param_1,int param_2,float *param_3,int param_4)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
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
  int iVar17;
  int iVar18;
  int iVar19;
  
  pfVar1 = (float *)(param_1 * 0x10 + param_4);
  iVar17 = ((uint)*pfVar1 & 0xff) * 0x40;
  pfVar2 = (float *)(iVar17 + param_2);
  fVar8 = pfVar2[1];
  fVar9 = pfVar2[2];
  fVar10 = pfVar2[3];
  iVar17 = iVar17 + param_2;
  iVar18 = ((uint)pfVar1[1] & 0xff) * 0x40;
  pfVar3 = (float *)(iVar18 + param_2);
  fVar11 = pfVar3[1];
  fVar12 = pfVar3[2];
  fVar13 = pfVar3[3];
  iVar18 = iVar18 + param_2;
  iVar19 = (*(uint *)(param_1 * 0x10 + 8 + param_4) & 0xff) * 0x40;
  pfVar4 = (float *)(iVar19 + param_2);
  fVar14 = pfVar4[1];
  fVar15 = pfVar4[2];
  fVar16 = pfVar4[3];
  iVar19 = iVar19 + param_2;
  fVar5 = *pfVar1;
  fVar6 = pfVar1[1];
  fVar7 = pfVar1[2];
  *param_3 = *pfVar2 * fVar5 + *pfVar3 * fVar6 + *pfVar4 * fVar7;
  param_3[1] = fVar8 * fVar5 + fVar11 * fVar6 + fVar14 * fVar7;
  param_3[2] = fVar9 * fVar5 + fVar12 * fVar6 + fVar15 * fVar7;
  param_3[3] = fVar10 * fVar5 + fVar13 * fVar6 + fVar16 * fVar7;
  fVar8 = *(float *)(iVar18 + 0x14);
  fVar9 = *(float *)(iVar18 + 0x18);
  fVar10 = *(float *)(iVar18 + 0x1c);
  fVar11 = *(float *)(iVar17 + 0x14);
  fVar12 = *(float *)(iVar17 + 0x18);
  fVar13 = *(float *)(iVar17 + 0x1c);
  fVar14 = *(float *)(iVar19 + 0x14);
  fVar15 = *(float *)(iVar19 + 0x18);
  fVar16 = *(float *)(iVar19 + 0x1c);
  param_3[4] = *(float *)(iVar17 + 0x10) * fVar5 + *(float *)(iVar18 + 0x10) * fVar6 +
               *(float *)(iVar19 + 0x10) * fVar7;
  param_3[5] = fVar11 * fVar5 + fVar8 * fVar6 + fVar14 * fVar7;
  param_3[6] = fVar12 * fVar5 + fVar9 * fVar6 + fVar15 * fVar7;
  param_3[7] = fVar13 * fVar5 + fVar10 * fVar6 + fVar16 * fVar7;
  fVar8 = *(float *)(iVar18 + 0x24);
  fVar9 = *(float *)(iVar18 + 0x28);
  fVar10 = *(float *)(iVar18 + 0x2c);
  fVar11 = *(float *)(iVar17 + 0x24);
  fVar12 = *(float *)(iVar17 + 0x28);
  fVar13 = *(float *)(iVar17 + 0x2c);
  fVar14 = *(float *)(iVar19 + 0x24);
  fVar15 = *(float *)(iVar19 + 0x28);
  fVar16 = *(float *)(iVar19 + 0x2c);
  param_3[8] = *(float *)(iVar17 + 0x20) * fVar5 + *(float *)(iVar18 + 0x20) * fVar6 +
               *(float *)(iVar19 + 0x20) * fVar7;
  param_3[9] = fVar11 * fVar5 + fVar8 * fVar6 + fVar14 * fVar7;
  param_3[10] = fVar12 * fVar5 + fVar9 * fVar6 + fVar15 * fVar7;
  param_3[0xb] = fVar13 * fVar5 + fVar10 * fVar6 + fVar16 * fVar7;
  fVar8 = *(float *)(iVar19 + 0x34);
  fVar9 = *(float *)(iVar19 + 0x38);
  fVar10 = *(float *)(iVar19 + 0x3c);
  fVar11 = *(float *)(iVar18 + 0x34);
  fVar12 = *(float *)(iVar18 + 0x38);
  fVar13 = *(float *)(iVar18 + 0x3c);
  fVar14 = *(float *)(iVar17 + 0x34);
  fVar15 = *(float *)(iVar17 + 0x38);
  fVar16 = *(float *)(iVar17 + 0x3c);
  param_3[0xc] = *(float *)(iVar17 + 0x30) * fVar5 + *(float *)(iVar18 + 0x30) * fVar6 +
                 *(float *)(iVar19 + 0x30) * fVar7;
  param_3[0xd] = fVar14 * fVar5 + fVar11 * fVar6 + fVar8 * fVar7;
  param_3[0xe] = fVar15 * fVar5 + fVar12 * fVar6 + fVar9 * fVar7;
  param_3[0xf] = fVar16 * fVar5 + fVar13 * fVar6 + fVar10 * fVar7;
  return;
}


// ==== 0x6241b0 FUN_006241b0

void FUN_006241b0(int param_1,int param_2,undefined8 *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  uVar1 = *(uint *)(param_4 + param_1 * 0x10);
  uVar2 = *(uint *)(param_4 + param_1 * 0x10 + 4);
  uVar6 = CONCAT44(uVar1,uVar1);
  uVar8 = CONCAT44(uVar2,uVar2);
  iVar3 = (uVar1 & 0xff) * 0x40;
  iVar4 = iVar3 + param_2;
  iVar5 = (uVar2 & 0xff) * 0x40;
  uVar7 = PackedFloatingMUL(*(undefined8 *)(iVar5 + param_2),uVar8);
  uVar9 = PackedFloatingMUL(*(undefined8 *)(iVar3 + param_2),uVar6);
  uVar7 = PackedFloatingADD(uVar9,uVar7);
  *param_3 = uVar7;
  uVar7 = PackedFloatingMUL(*(undefined8 *)(iVar5 + 8 + param_2),uVar8);
  iVar5 = iVar5 + param_2;
  uVar9 = PackedFloatingMUL(*(undefined8 *)(iVar4 + 8),uVar6);
  uVar7 = PackedFloatingADD(uVar9,uVar7);
  param_3[1] = uVar7;
  uVar7 = PackedFloatingMUL(*(undefined8 *)(iVar5 + 0x10),uVar8);
  uVar9 = PackedFloatingMUL(*(undefined8 *)(iVar4 + 0x10),uVar6);
  uVar7 = PackedFloatingADD(uVar9,uVar7);
  param_3[2] = uVar7;
  uVar7 = PackedFloatingMUL(*(undefined8 *)(iVar5 + 0x18),uVar8);
  uVar9 = PackedFloatingMUL(*(undefined8 *)(iVar4 + 0x18),uVar6);
  uVar7 = PackedFloatingADD(uVar9,uVar7);
  param_3[3] = uVar7;
  uVar7 = PackedFloatingMUL(*(undefined8 *)(iVar5 + 0x20),uVar8);
  uVar9 = PackedFloatingMUL(*(undefined8 *)(iVar4 + 0x20),uVar6);
  uVar7 = PackedFloatingADD(uVar9,uVar7);
  param_3[4] = uVar7;
  uVar7 = PackedFloatingMUL(*(undefined8 *)(iVar5 + 0x28),uVar8);
  uVar9 = PackedFloatingMUL(*(undefined8 *)(iVar4 + 0x28),uVar6);
  uVar7 = PackedFloatingADD(uVar9,uVar7);
  param_3[5] = uVar7;
  uVar7 = PackedFloatingMUL(*(undefined8 *)(iVar5 + 0x30),uVar8);
  uVar9 = PackedFloatingMUL(*(undefined8 *)(iVar4 + 0x30),uVar6);
  uVar7 = PackedFloatingADD(uVar9,uVar7);
  param_3[6] = uVar7;
  uVar8 = PackedFloatingMUL(*(undefined8 *)(iVar5 + 0x38),uVar8);
  uVar6 = PackedFloatingMUL(*(undefined8 *)(iVar4 + 0x38),uVar6);
  uVar6 = PackedFloatingADD(uVar6,uVar8);
  param_3[7] = uVar6;
  return;
}


// ==== 0x6242d0 FUN_006242d0

void FUN_006242d0(int param_1,int param_2,undefined8 *param_3,int param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  
  puVar1 = (uint *)(param_1 * 0x10 + param_4);
  uVar2 = puVar1[1];
  uVar3 = *puVar1;
  uVar4 = puVar1[2];
  uVar10 = CONCAT44(uVar3,uVar3);
  uVar11 = CONCAT44(uVar2,uVar2);
  iVar5 = (uVar3 & 0xff) * 0x40;
  iVar6 = iVar5 + param_2;
  iVar7 = (uVar2 & 0xff) * 0x40;
  iVar8 = iVar7 + param_2;
  puVar9 = (undefined8 *)((uVar4 & 0xff) * 0x40 + param_2);
  uVar13 = CONCAT44(uVar4,uVar4);
  uVar12 = PackedFloatingMUL(*puVar9,uVar13);
  uVar14 = PackedFloatingMUL(*(undefined8 *)(iVar7 + param_2),uVar11);
  uVar15 = PackedFloatingMUL(*(undefined8 *)(iVar5 + param_2),uVar10);
  uVar14 = PackedFloatingADD(uVar15,uVar14);
  uVar12 = PackedFloatingADD(uVar14,uVar12);
  *param_3 = uVar12;
  uVar12 = PackedFloatingMUL(puVar9[1],uVar13);
  uVar14 = PackedFloatingMUL(*(undefined8 *)(iVar8 + 8),uVar11);
  uVar15 = PackedFloatingMUL(*(undefined8 *)(iVar6 + 8),uVar10);
  uVar14 = PackedFloatingADD(uVar15,uVar14);
  uVar12 = PackedFloatingADD(uVar14,uVar12);
  param_3[1] = uVar12;
  uVar12 = PackedFloatingMUL(puVar9[2],uVar13);
  uVar14 = PackedFloatingMUL(*(undefined8 *)(iVar8 + 0x10),uVar11);
  uVar15 = PackedFloatingMUL(*(undefined8 *)(iVar6 + 0x10),uVar10);
  uVar14 = PackedFloatingADD(uVar15,uVar14);
  uVar12 = PackedFloatingADD(uVar14,uVar12);
  param_3[2] = uVar12;
  uVar12 = PackedFloatingMUL(puVar9[3],uVar13);
  uVar14 = PackedFloatingMUL(*(undefined8 *)(iVar8 + 0x18),uVar11);
  uVar15 = PackedFloatingMUL(*(undefined8 *)(iVar6 + 0x18),uVar10);
  uVar14 = PackedFloatingADD(uVar15,uVar14);
  uVar12 = PackedFloatingADD(uVar14,uVar12);
  param_3[3] = uVar12;
  uVar12 = PackedFloatingMUL(puVar9[4],uVar13);
  uVar14 = PackedFloatingMUL(*(undefined8 *)(iVar8 + 0x20),uVar11);
  uVar15 = PackedFloatingMUL(*(undefined8 *)(iVar6 + 0x20),uVar10);
  uVar14 = PackedFloatingADD(uVar15,uVar14);
  uVar12 = PackedFloatingADD(uVar14,uVar12);
  param_3[4] = uVar12;
  uVar12 = PackedFloatingMUL(puVar9[5],uVar13);
  uVar14 = PackedFloatingMUL(*(undefined8 *)(iVar8 + 0x28),uVar11);
  uVar15 = PackedFloatingMUL(*(undefined8 *)(iVar6 + 0x28),uVar10);
  uVar14 = PackedFloatingADD(uVar15,uVar14);
  uVar12 = PackedFloatingADD(uVar14,uVar12);
  param_3[5] = uVar12;
  uVar12 = PackedFloatingMUL(puVar9[6],uVar13);
  uVar14 = PackedFloatingMUL(*(undefined8 *)(iVar8 + 0x30),uVar11);
  uVar15 = PackedFloatingMUL(*(undefined8 *)(iVar6 + 0x30),uVar10);
  uVar14 = PackedFloatingADD(uVar15,uVar14);
  uVar12 = PackedFloatingADD(uVar14,uVar12);
  param_3[6] = uVar12;
  uVar13 = PackedFloatingMUL(puVar9[7],uVar13);
  uVar11 = PackedFloatingMUL(*(undefined8 *)(iVar8 + 0x38),uVar11);
  uVar10 = PackedFloatingMUL(*(undefined8 *)(iVar6 + 0x38),uVar10);
  uVar10 = PackedFloatingADD(uVar10,uVar11);
  uVar10 = PackedFloatingADD(uVar10,uVar13);
  param_3[7] = uVar10;
  return;
}


// ==== 0x624470 FUN_00624470

void FUN_00624470(int param_1,int param_2,float *param_3,int param_4)

{
  int iVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  float *pfVar6;
  
  param_1 = param_1 * 0x10;
  fVar2 = *(float *)(param_4 + param_1);
  uVar4 = *(uint *)(param_4 + 4 + param_1);
  fVar3 = *(float *)(param_4 + 4 + param_1);
  iVar5 = (*(uint *)(param_4 + param_1) & 0xff) * 0x40;
  iVar1 = iVar5 + param_2;
  *param_3 = fVar2 * *(float *)(iVar5 + param_2);
  pfVar6 = (float *)((uVar4 & 0xff) * 0x40 + param_2);
  *param_3 = fVar3 * *pfVar6 + *param_3;
  param_3[4] = fVar2 * *(float *)(iVar1 + 0x10);
  param_3[4] = fVar3 * pfVar6[4] + param_3[4];
  param_3[8] = fVar2 * *(float *)(iVar1 + 0x20);
  param_3[8] = fVar3 * pfVar6[8] + param_3[8];
  param_3[0xc] = fVar2 * *(float *)(iVar1 + 0x30);
  param_3[0xc] = fVar3 * pfVar6[0xc] + param_3[0xc];
  param_3[1] = fVar2 * *(float *)(iVar1 + 4);
  param_3[1] = fVar3 * pfVar6[1] + param_3[1];
  param_3[5] = fVar2 * *(float *)(iVar1 + 0x14);
  param_3[5] = fVar3 * pfVar6[5] + param_3[5];
  param_3[9] = fVar2 * *(float *)(iVar1 + 0x24);
  param_3[9] = fVar3 * pfVar6[9] + param_3[9];
  param_3[0xd] = fVar2 * *(float *)(iVar1 + 0x34);
  param_3[0xd] = fVar3 * pfVar6[0xd] + param_3[0xd];
  param_3[2] = fVar2 * *(float *)(iVar1 + 8);
  param_3[2] = fVar3 * pfVar6[2] + param_3[2];
  param_3[6] = fVar2 * *(float *)(iVar1 + 0x18);
  param_3[6] = fVar3 * pfVar6[6] + param_3[6];
  param_3[10] = fVar2 * *(float *)(iVar1 + 0x28);
  param_3[10] = fVar3 * pfVar6[10] + param_3[10];
  param_3[0xe] = fVar2 * *(float *)(iVar1 + 0x38);
  param_3[0xe] = fVar3 * pfVar6[0xe] + param_3[0xe];
  param_3[3] = fVar2 * *(float *)(iVar1 + 0xc);
  param_3[3] = fVar3 * pfVar6[3] + param_3[3];
  param_3[7] = fVar2 * *(float *)(iVar1 + 0x1c);
  param_3[7] = fVar3 * pfVar6[7] + param_3[7];
  param_3[0xb] = fVar2 * *(float *)(iVar1 + 0x2c);
  param_3[0xb] = fVar3 * pfVar6[0xb] + param_3[0xb];
  param_3[0xf] = fVar2 * *(float *)(iVar1 + 0x3c);
  param_3[0xf] = fVar3 * pfVar6[0xf] + param_3[0xf];
  return;
}


// ==== 0x6245e0 FUN_006245e0

void FUN_006245e0(int param_1,int param_2,float *param_3,int param_4)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  float fVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  float *pfVar10;
  
  param_1 = param_1 * 0x10;
  fVar1 = *(float *)(param_1 + param_4);
  uVar3 = *(uint *)(param_1 + 4 + param_4);
  fVar2 = *(float *)(param_1 + 4 + param_4);
  puVar6 = (uint *)(param_1 + param_4);
  uVar4 = puVar6[2];
  fVar5 = (float)puVar6[2];
  iVar7 = (*puVar6 & 0xff) * 0x40;
  iVar8 = iVar7 + param_2;
  *param_3 = fVar1 * *(float *)(iVar7 + param_2);
  pfVar9 = (float *)((uVar3 & 0xff) * 0x40 + param_2);
  pfVar10 = (float *)((uVar4 & 0xff) * 0x40 + param_2);
  *param_3 = fVar2 * *pfVar9 + *param_3;
  *param_3 = fVar5 * *pfVar10 + *param_3;
  param_3[4] = fVar1 * *(float *)(iVar8 + 0x10);
  param_3[4] = fVar2 * pfVar9[4] + param_3[4];
  param_3[4] = fVar5 * pfVar10[4] + param_3[4];
  param_3[8] = fVar1 * *(float *)(iVar8 + 0x20);
  param_3[8] = fVar2 * pfVar9[8] + param_3[8];
  param_3[8] = fVar5 * pfVar10[8] + param_3[8];
  param_3[0xc] = fVar1 * *(float *)(iVar8 + 0x30);
  param_3[0xc] = fVar2 * pfVar9[0xc] + param_3[0xc];
  param_3[0xc] = fVar5 * pfVar10[0xc] + param_3[0xc];
  param_3[1] = fVar1 * *(float *)(iVar8 + 4);
  param_3[1] = fVar2 * pfVar9[1] + param_3[1];
  param_3[1] = fVar5 * pfVar10[1] + param_3[1];
  param_3[5] = fVar1 * *(float *)(iVar8 + 0x14);
  param_3[5] = fVar2 * pfVar9[5] + param_3[5];
  param_3[5] = fVar5 * pfVar10[5] + param_3[5];
  param_3[9] = fVar1 * *(float *)(iVar8 + 0x24);
  param_3[9] = fVar2 * pfVar9[9] + param_3[9];
  param_3[9] = fVar5 * pfVar10[9] + param_3[9];
  param_3[0xd] = fVar1 * *(float *)(iVar8 + 0x34);
  param_3[0xd] = fVar2 * pfVar9[0xd] + param_3[0xd];
  param_3[0xd] = fVar5 * pfVar10[0xd] + param_3[0xd];
  param_3[2] = fVar1 * *(float *)(iVar8 + 8);
  param_3[2] = fVar2 * pfVar9[2] + param_3[2];
  param_3[2] = fVar5 * pfVar10[2] + param_3[2];
  param_3[6] = fVar1 * *(float *)(iVar8 + 0x18);
  param_3[6] = fVar2 * pfVar9[6] + param_3[6];
  param_3[6] = fVar5 * pfVar10[6] + param_3[6];
  param_3[10] = fVar1 * *(float *)(iVar8 + 0x28);
  param_3[10] = fVar2 * pfVar9[10] + param_3[10];
  param_3[10] = fVar5 * pfVar10[10] + param_3[10];
  param_3[0xe] = fVar1 * *(float *)(iVar8 + 0x38);
  param_3[0xe] = fVar2 * pfVar9[0xe] + param_3[0xe];
  param_3[0xe] = fVar5 * pfVar10[0xe] + param_3[0xe];
  param_3[3] = fVar1 * *(float *)(iVar8 + 0xc);
  param_3[3] = fVar2 * pfVar9[3] + param_3[3];
  param_3[3] = fVar5 * pfVar10[3] + param_3[3];
  param_3[7] = fVar1 * *(float *)(iVar8 + 0x1c);
  param_3[7] = fVar2 * pfVar9[7] + param_3[7];
  param_3[7] = fVar5 * pfVar10[7] + param_3[7];
  param_3[0xb] = fVar1 * *(float *)(iVar8 + 0x2c);
  param_3[0xb] = fVar2 * pfVar9[0xb] + param_3[0xb];
  param_3[0xb] = fVar5 * pfVar10[0xb] + param_3[0xb];
  param_3[0xf] = fVar1 * *(float *)(iVar8 + 0x3c);
  param_3[0xf] = fVar2 * pfVar9[0xf] + param_3[0xf];
  param_3[0xf] = fVar5 * pfVar10[0xf] + param_3[0xf];
  return;
}


// ==== 0x624830 FUN_00624830

void FUN_00624830(void)

{
  FUN_00622700(*(undefined4 *)(DAT_00709df0 + 4),*(undefined4 *)(DAT_00709df8 + 4),
               *(int *)(DAT_00709df0 + 8) >> 2);
  return;
}


// ==== 0x624860 FUN_00624860

void FUN_00624860(void)

{
  FUN_00622720(*(undefined4 *)(DAT_00709df0 + 4),
               *(undefined4 *)(*(int *)(DAT_00709df0 + 0x10) + 4 + DAT_00709f70 * 8));
  return;
}


// ==== 0x624880 FUN_00624880

void FUN_00624880(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = *(undefined4 *)(DAT_00709df0 + 4);
  uVar1 = *(undefined4 *)(DAT_00709df0 + 0xc);
  uStack_8 = *(undefined4 *)(DAT_00709df0 + 0x10);
  iVar2 = *(int *)(DAT_00709df0 + 8);
  iVar3 = *DAT_00709df8 * iVar2;
  if (*(int *)(DAT_00709df0 + 0x14) < *DAT_00709df8) {
    if (*(int *)(DAT_00709df0 + 0x10) != -1) {
      FUN_00622c60(&uStack_8,uStack_4);
    }
    uStack_8 = EAGL__VertexBuffer__New(iVar3,iVar2,0x208,uVar1,DAT_0070ab48,iVar3 * 4);
    FUN_00622910();
    *(undefined4 *)(DAT_00709df0 + 0x10) = uStack_8;
    *(int *)(DAT_00709df0 + 0x14) = *DAT_00709df8 << 2;
  }
  if (DAT_00709e00 == 0) {
    FUN_006232a0(DAT_00709df8[1],iVar3);
  }
  FUN_00622720(uStack_4,uStack_8);
  return;
}


// ==== 0x624950 FUN_00624950

void FUN_00624950(void)

{
  int iVar1;
  int iVar2;
  int iStack_8;
  undefined4 uStack_4;
  
  iVar2 = *(int *)(DAT_00709df0 + 4) * *DAT_00709df8;
  iVar1 = DAT_00709df8[1];
  iStack_8 = *(int *)(DAT_00709df0 + 8);
  if (*(int *)(DAT_00709df0 + 8) != -1) {
    if (iVar2 <= *(int *)(iStack_8 + 8)) goto LAB_006249c5;
    if (*(int *)(DAT_00709df0 + 8) != -1) {
      FUN_00623500(&iStack_8);
    }
  }
  iStack_8 = EAGL__IndexBuffer__New(iVar2 * 4,DAT_0070ab48,0x208);
  FUN_006228a0();
  *(int *)(DAT_00709df0 + 8) = iStack_8;
LAB_006249c5:
  if (DAT_00709e00 == 0) {
    FUN_00622da0(0,iVar2,&uStack_4,0x2000);
    FUN_0063f1b0(uStack_4,iVar1,iVar2);
    FUN_00622dc0();
  }
  FUN_00622760(iStack_8);
  return;
}


// ==== 0x624a10 FUN_00624a10

void FUN_00624a10(void)

{
  FUN_00622760(*(undefined4 *)(DAT_00709df0 + 0xc));
  return;
}


// ==== 0x624a20 FUN_00624a20

void FUN_00624a20(void)

{
  *(int *)(&DAT_0070ab00 + *(int *)(DAT_00709df0 + 4) * 4) =
       *(int *)(DAT_00709df0 + 8) * DAT_00709f70 + *(int *)(DAT_00709df8 + 4);
  return;
}


// ==== 0x624a50 FUN_00624a50

void FUN_00624a50(void)

{
  PTR_DAT_006e2b90 = *(undefined **)(DAT_00709df8 + 4);
  return;
}


// ==== 0x624a60 FUN_00624a60

void FUN_00624a60(void)

{
  D3DXMatrixTranspose(&DAT_0070ab58,*(undefined4 *)(DAT_00709df8 + 4));
  FUN_00622700(*(undefined4 *)(DAT_00709df0 + 4),&DAT_0070ab58,4);
  return;
}


// ==== 0x624a90 FUN_00624a90

void FUN_00624a90(void)

{
  int iVar1;
  int iStack_4;
  
  FUN_006269a0(&iStack_4,PTR_DAT_006e2b90);
  iVar1 = 0;
  if (0 < iStack_4) {
    do {
      FUN_006269d0(iVar1,PTR_DAT_006e2b90);
      FUN_00622020();
      FUN_00622840(0,DAT_00709e04,DAT_00709dfc);
      iVar1 = iVar1 + 1;
    } while (iVar1 < iStack_4);
  }
  NullUpdate_ret();
  return;
}


// ==== 0x624b00 FUN_00624b00

void FUN_00624b00(void)

{
  int iVar1;
  int iStack_4;
  
  FUN_00622770(DAT_0070ab50);
  FUN_006269a0(&iStack_4,PTR_DAT_006e2b90);
  iVar1 = 0;
  if (0 < iStack_4) {
    do {
      FUN_006269d0(iVar1,PTR_DAT_006e2b90);
      FUN_00622020();
      FUN_00622780();
      FUN_00622860(0,DAT_00709e04,0,DAT_00709e08,DAT_00709dfc);
      iVar1 = iVar1 + 1;
    } while (iVar1 < iStack_4);
  }
  NullUpdate_ret();
  return;
}


// ==== 0x624b90 FUN_00624b90

void FUN_00624b90(void)

{
  DAT_0070a9c0 = DAT_00709df8[1];
  DAT_0070a9c4 = *DAT_00709df8;
  DAT_0070ab3c = *(undefined4 *)(DAT_00709df0 + 4);
  DAT_0070ab40 = *(undefined4 *)(DAT_00709df0 + 8);
  DAT_0070ab44 = *(undefined4 *)(DAT_00709df0 + 0xc);
  return;
}


// ==== 0x624bd0 FUN_00624bd0

void FUN_00624bd0(void)

{
  FUN_00621fb0(*(undefined4 *)(DAT_00709df8 + 4));
  PTR_DAT_006e2b90 = &DAT_0070cbf8;
  return;
}


// ==== 0x624bf0 FUN_00624bf0

void FUN_00624bf0(void)

{
  int iVar1;
  int iStack_4;
  
  FUN_006269a0(&iStack_4,PTR_DAT_006e2b90);
  iVar1 = 0;
  if (0 < iStack_4) {
    do {
      FUN_006269d0(iVar1,PTR_DAT_006e2b90);
      FUN_00622020();
      FUN_00622840(0,DAT_00709e04,
                   (DAT_00709e04 - *(int *)(&DAT_006e2b54 + DAT_0070a410 * 8)) /
                   *(int *)(&DAT_006e2b50 + DAT_0070a410 * 8));
      iVar1 = iVar1 + 1;
    } while (iVar1 < iStack_4);
  }
  NullUpdate_ret();
  return;
}


// ==== 0x624c80 FUN_00624c80

void FUN_00624c80(void)

{
  int iVar1;
  int iStack_4;
  
  FUN_00622770(DAT_0070ab50);
  FUN_006269a0(&iStack_4,PTR_DAT_006e2b90);
  iVar1 = 0;
  if (0 < iStack_4) {
    do {
      FUN_006269d0(iVar1,PTR_DAT_006e2b90);
      FUN_00622020();
      FUN_00622780();
      FUN_00622860(0,DAT_00709e04,0,DAT_00709e08,
                   (DAT_00709e08 - *(int *)(&DAT_006e2b54 + DAT_0070a410 * 8)) /
                   *(int *)(&DAT_006e2b50 + DAT_0070a410 * 8));
      iVar1 = iVar1 + 1;
    } while (iVar1 < iStack_4);
  }
  NullUpdate_ret();
  return;
}


// ==== 0x624d20 FUN_00624d20

void FUN_00624d20(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iStack_4;
  
  FUN_00622770(DAT_0070ab50);
  FUN_006269a0(&iStack_4,PTR_DAT_006e2b90);
  iVar3 = 0;
  if (0 < iStack_4) {
    do {
      FUN_006269d0(iVar3,PTR_DAT_006e2b90);
      FUN_00622020();
      iVar2 = DAT_00709e08 - *(int *)(&DAT_006e2b54 + DAT_0070a410 * 8);
      iVar1 = *(int *)(&DAT_006e2b50 + DAT_0070a410 * 8);
      FUN_00622780();
      FUN_00622860(0,DAT_00709e04,0,DAT_00709e08,iVar2 / iVar1);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iStack_4);
  }
  NullUpdate_ret();
  return;
}


// ==== 0x624dd0 FUN_00624dd0

void FUN_00624dd0(void)

{
  D3DXMatrixTranspose(&DAT_0070ab58,*(undefined4 *)(DAT_00709df8 + 4));
  FUN_00622820(*(undefined4 *)(DAT_00709df0 + 4),&DAT_0070ab58,4);
  return;
}


// ==== 0x624e00 FUN_00624e00

void FUN_00624e00(void)

{
  FUN_00622820(*(undefined4 *)(DAT_00709df0 + 4),*(undefined4 *)(DAT_00709df8 + 4),
               *(int *)(DAT_00709df0 + 8) >> 2);
  return;
}


// ==== 0x624e30 FUN_00624e30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00624e30(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  undefined4 *puVar7;
  float *pfVar8;
  bool bVar9;
  float *pfStack_14;
  
  iVar5 = *(int *)(DAT_00709df0 + 8);
  iVar2 = EAGL__PC__GetDirectDraw();
  iVar2 = *(int *)(iVar2 + 0x2c4);
  bVar9 = iVar5 != 0;
  if (bVar9 != (bool)DAT_0070a4c8) {
    DAT_0070a4c8 = bVar9;
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x89,bVar9);
  }
  if (iVar5 != 0) {
    puVar7 = &DAT_0070a9c8;
    for (iVar5 = 0x4e; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    iVar5 = *(int *)(DAT_00709df4 + 4 + *(int *)(DAT_00709df0 + 4) * 8);
    uVar3 = (((int)ROUND(*(float *)(iVar5 + 0x6c) * K_BLUR_MIN_T) << 8 |
             (int)ROUND(*(float *)(iVar5 + 0x60) * K_BLUR_MIN_T)) << 8 |
            (int)ROUND(*(float *)(iVar5 + 100) * K_BLUR_MIN_T)) << 8 |
            (int)ROUND(*(float *)(iVar5 + 0x68) * K_BLUR_MIN_T);
    if (DAT_0070a4cc != uVar3) {
      DAT_0070a4cc = uVar3;
      (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x8b,uVar3);
    }
    iVar4 = 3;
    if (iVar2 < 4) {
      iVar4 = iVar2;
    }
    iVar2 = 0;
    if (0 < iVar4) {
      pfVar8 = (float *)(iVar5 + 0x20);
      pfStack_14 = (float *)(iVar5 + 0x30);
      pfVar6 = (float *)&DAT_0070aa08;
      do {
        pfVar6[-0x10] = 4.2039e-45;
        pfVar6[-0xf] = *pfStack_14;
        pfVar6[-0xe] = pfStack_14[1];
        pfVar6[-0xd] = pfStack_14[2];
        pfVar6[-0xc] = pfStack_14[3];
        piVar1 = DAT_00709d80;
        *pfVar6 = -pfVar8[-8];
        pfVar6[1] = -pfVar8[-4];
        pfVar6[2] = -*pfVar8;
        (**(code **)(*piVar1 + 0xb0))(piVar1,iVar2,pfVar6 + -0x10);
        iVar2 = iVar2 + 1;
        pfStack_14 = pfStack_14 + 4;
        pfVar8 = pfVar8 + 1;
        pfVar6 = pfVar6 + 0x1a;
      } while (iVar2 < iVar4);
    }
  }
  return;
}


// ==== 0x624fd0 FUN_00624fd0

void FUN_00624fd0(void)

{
  (**(code **)(*DAT_00709d80 + 0x94))
            (DAT_00709d80,0x100,*(undefined4 *)(DAT_00709df4 + 4 + *(int *)(DAT_00709df0 + 4) * 8));
  DAT_0070ab4c = 0;
  return;
}


// ==== 0x625010 FUN_00625010

void FUN_00625010(void)

{
  (**(code **)(*DAT_00709d80 + 0x94))
            (DAT_00709d80,2,*(undefined4 *)(DAT_00709df4 + 4 + *(int *)(DAT_00709df0 + 4) * 8));
  DAT_0070ab4c = 0;
  return;
}


// ==== 0x625040 FUN_00625040

void FUN_00625040(void)

{
  (**(code **)(*DAT_00709d80 + 0x94))
            (DAT_00709d80,0x10,*(undefined4 *)(DAT_00709df4 + 4 + *(int *)(DAT_00709df0 + 4) * 8));
  return;
}


// ==== 0x625070 FUN_00625070

void FUN_00625070(void)

{
  (**(code **)(*DAT_00709d80 + 0x94))
            (DAT_00709d80,0x11,*(undefined4 *)(DAT_00709df4 + 4 + *(int *)(DAT_00709df0 + 4) * 8));
  return;
}


// ==== 0x6250a0 FUN_006250a0

void FUN_006250a0(void)

{
  (**(code **)(*DAT_00709d80 + 0x94))
            (DAT_00709d80,0x12,*(undefined4 *)(DAT_00709df4 + 4 + *(int *)(DAT_00709df0 + 4) * 8));
  return;
}


// ==== 0x6250d0 FUN_006250d0

void FUN_006250d0(void)

{
  (**(code **)(*DAT_00709d80 + 0x94))
            (DAT_00709d80,0x13,*(undefined4 *)(DAT_00709df4 + 4 + *(int *)(DAT_00709df0 + 4) * 8));
  return;
}


// ==== 0x625100 FUN_00625100

void FUN_00625100(void)

{
  (**(code **)(*DAT_00709d80 + 0x94))
            (DAT_00709d80,0x14,*(undefined4 *)(DAT_00709df4 + 4 + *(int *)(DAT_00709df0 + 4) * 8));
  return;
}


// ==== 0x625130 FUN_00625130

void FUN_00625130(void)

{
  (**(code **)(*DAT_00709d80 + 0x94))
            (DAT_00709d80,0x15,*(undefined4 *)(DAT_00709df4 + 4 + *(int *)(DAT_00709df0 + 4) * 8));
  return;
}


// ==== 0x625160 FUN_00625160

void FUN_00625160(void)

{
  (**(code **)(*DAT_00709d80 + 0x94))
            (DAT_00709d80,0x16,*(undefined4 *)(DAT_00709df4 + 4 + *(int *)(DAT_00709df0 + 4) * 8));
  return;
}


// ==== 0x625190 FUN_00625190

void FUN_00625190(void)

{
  (**(code **)(*DAT_00709d80 + 0x94))
            (DAT_00709d80,0x17,*(undefined4 *)(DAT_00709df4 + 4 + *(int *)(DAT_00709df0 + 4) * 8));
  return;
}


// ==== 0x6251c0 FUN_006251c0

void FUN_006251c0(void)

{
  (**(code **)(*DAT_00709d80 + 0x94))
            (DAT_00709d80,3,*(undefined4 *)(DAT_00709df4 + 4 + *(int *)(DAT_00709df0 + 4) * 8));
  DAT_0070ab4c = 0;
  return;
}


// ==== 0x6251f0 FUN_006251f0

void FUN_006251f0(void)

{
  (**(code **)(*DAT_00709d80 + 0x94))
            (DAT_00709d80,0x100,*(undefined4 *)(DAT_00709df4 + 4 + *(int *)(DAT_00709df0 + 4) * 8));
  if (DAT_0070ab4c == '\0') {
    (**(code **)(*DAT_00709d80 + 0x94))(DAT_00709d80,3,&DAT_00709660);
    (**(code **)(*DAT_00709d80 + 0x94))(DAT_00709d80,2,&DAT_00709660);
  }
  DAT_0070ab4c = 1;
  return;
}


// ==== 0x625260 FUN_00625260

void FUN_00625260(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iStack_4;
  
  FUN_006269a0(&iStack_4,PTR_DAT_006e2b90);
  iVar2 = (int)DAT_00709df0;
  DAT_00709df0 = (uint *)((int)DAT_00709df0 + 4);
  iVar3 = 0;
  if (0 < iStack_4) {
    do {
      uVar1 = *DAT_00709df0;
      while ((uVar1 != 0 && (uVar1 >> 0x10 != 0x44))) {
        (*(code *)(&PTR_NullUpdate_ret_006e2b98)[uVar1 >> 0x10])();
        DAT_00709df0 = DAT_00709df0 + (uVar1 & 0xffff);
        uVar1 = *DAT_00709df0;
      }
      FUN_006269d0(iVar3,PTR_DAT_006e2b90);
      FUN_00622020();
      FUN_00622840(0,DAT_00709e04,DAT_00709dfc);
      DAT_00709df0 = DAT_00709df0 + (*DAT_00709df0 & 0xffff);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iStack_4);
  }
  NullUpdate_ret();
  DAT_00709df0 = (uint *)iVar2;
  return;
}


// ==== 0x625340 FUN_00625340

void FUN_00625340(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iStack_4;
  
  FUN_006269a0(&iStack_4,PTR_DAT_006e2b90);
  iVar2 = (int)DAT_00709df0;
  DAT_00709df0 = (uint *)((int)DAT_00709df0 + 4);
  iVar3 = 0;
  if (0 < iStack_4) {
    do {
      uVar1 = *DAT_00709df0;
      while ((uVar1 != 0 && (uVar1 >> 0x10 != 0x44))) {
        (*(code *)(&PTR_NullUpdate_ret_006e2b98)[uVar1 >> 0x10])();
        DAT_00709df0 = DAT_00709df0 + (uVar1 & 0xffff);
        uVar1 = *DAT_00709df0;
      }
      FUN_00622770(DAT_0070ab50);
      FUN_006269d0(iVar3,PTR_DAT_006e2b90);
      FUN_00622020();
      FUN_00622780();
      FUN_00622860(0,DAT_00709e04,0,DAT_00709e08,DAT_00709dfc);
      iVar3 = iVar3 + 1;
      DAT_00709df0 = DAT_00709df0 + (*DAT_00709df0 & 0xffff);
    } while (iVar3 < iStack_4);
  }
  NullUpdate_ret();
  DAT_00709df0 = (uint *)iVar2;
  return;
}


// ==== 0x625400 FUN_00625400

void __fastcall FUN_00625400(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint *in_EAX;
  undefined4 unaff_EBX;
  int unaff_EDI;
  int in_stack_00000020;
  
  DAT_00709df0 = in_EAX;
  while( true ) {
    unaff_EDI = unaff_EDI + 1;
    DAT_00709df0 = DAT_00709df0 + (param_2 & 0xffff);
    if (in_stack_00000020 <= unaff_EDI) break;
    uVar1 = *DAT_00709df0;
    while ((uVar1 != 0 && (uVar1 >> 0x10 != 0x44))) {
      (*(code *)(&PTR_NullUpdate_ret_006e2b98)[uVar1 >> 0x10])();
      DAT_00709df0 = DAT_00709df0 + (uVar1 & 0xffff);
      uVar1 = *DAT_00709df0;
    }
    FUN_00622770();
    FUN_006269d0();
    FUN_00622020();
    FUN_00622780();
    FUN_00622860();
    param_2 = *DAT_00709df0;
  }
  NullUpdate_ret();
  DAT_00709df0 = (uint *)unaff_EBX;
  return;
}


// ==== 0x625440 FUN_00625440

void FUN_00625440(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iStack_4;
  
  FUN_006269a0(&iStack_4,PTR_DAT_006e2b90);
  iVar2 = (int)DAT_00709df0;
  DAT_00709df0 = (uint *)((int)DAT_00709df0 + 4);
  iVar3 = 0;
  if (0 < iStack_4) {
    do {
      uVar1 = *DAT_00709df0;
      while ((uVar1 != 0 && (uVar1 >> 0x10 != 0x44))) {
        (*(code *)(&PTR_NullUpdate_ret_006e2b98)[uVar1 >> 0x10])();
        DAT_00709df0 = DAT_00709df0 + (uVar1 & 0xffff);
        uVar1 = *DAT_00709df0;
      }
      FUN_006269d0(iVar3,PTR_DAT_006e2b90);
      FUN_00622020();
      FUN_00622840(0,DAT_00709e04,
                   (DAT_00709e08 - *(int *)(&DAT_006e2b54 + DAT_0070a410 * 8)) /
                   *(int *)(&DAT_006e2b50 + DAT_0070a410 * 8));
      iVar3 = iVar3 + 1;
      DAT_00709df0 = DAT_00709df0 + (*DAT_00709df0 & 0xffff);
    } while (iVar3 < iStack_4);
  }
  NullUpdate_ret();
  DAT_00709df0 = (uint *)iVar2;
  return;
}


// ==== 0x625530 FUN_00625530

void FUN_00625530(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iStack_4;
  
  FUN_006269a0(&iStack_4,PTR_DAT_006e2b90);
  iVar2 = (int)DAT_00709df0;
  DAT_00709df0 = (uint *)((int)DAT_00709df0 + 4);
  iVar3 = 0;
  if (0 < iStack_4) {
    do {
      uVar1 = *DAT_00709df0;
      while ((uVar1 != 0 && (uVar1 >> 0x10 != 0x44))) {
        (*(code *)(&PTR_NullUpdate_ret_006e2b98)[uVar1 >> 0x10])();
        DAT_00709df0 = DAT_00709df0 + (uVar1 & 0xffff);
        uVar1 = *DAT_00709df0;
      }
      FUN_006269d0(iVar3,PTR_DAT_006e2b90);
      FUN_00622020();
      FUN_00622770(DAT_0070ab50);
      FUN_00622780();
      FUN_00622860(0,DAT_00709e04,0,DAT_00709e08,
                   (DAT_00709e08 - *(int *)(&DAT_006e2b54 + DAT_0070a410 * 8)) /
                   *(int *)(&DAT_006e2b50 + DAT_0070a410 * 8));
      DAT_00709df0 = DAT_00709df0 + (*DAT_00709df0 & 0xffff);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iStack_4);
  }
  NullUpdate_ret();
  DAT_00709df0 = (uint *)iVar2;
  return;
}


// ==== 0x625640 FUN_00625640

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00625640(void)

{
  float fVar1;
  char cVar2;
  int iVar3;
  char cVar4;
  float *pfVar5;
  char cStack_39;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  int iStack_28;
  float fStack_24;
  float afStack_20 [6];
  float fStack_8;
  float fStack_4;
  
  if (DAT_0070a4c8 != '\0') {
    DAT_0070a4c8 = '\0';
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x89,0);
  }
  DAT_0070ab48 = *(int *)(DAT_00709df0 + 4);
  cVar4 = '\x01';
  if (DAT_0070ab48 == 0) {
LAB_00625692:
    cVar2 = FUN_00620230();
    if (cVar2 != '\0') {
LAB_0062569b:
      cVar4 = '\0';
    }
  }
  else {
    cVar2 = FUN_00620240();
    if (cVar2 != '\0') goto LAB_0062569b;
    if (DAT_0070ab48 == 0) goto LAB_00625692;
  }
  FUN_0061f7a0(cVar4);
  FUN_0061f040();
  FUN_0061efe0();
  FUN_006202f0(&cStack_39);
  if (cStack_39 != DAT_0070a4d0) {
    DAT_0070a4d0 = cStack_39;
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x1c,cStack_39);
  }
  if (cStack_39 == '\0') {
    DAT_0070ab50 = 0;
    return;
  }
  if (DAT_0070ab48 != 0) {
    iVar3 = EAGL__PC__GetDirectDraw();
    FUN_00620330(&iStack_28);
    FUN_00620310(&fStack_24);
    if (iStack_28 != DAT_0070a4d4) {
      DAT_0070a4d4 = iStack_28;
      (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x8c,iStack_28);
    }
    if (fStack_24 != DAT_0070a4d8) {
      DAT_0070a4d8 = fStack_24;
      (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x23,fStack_24);
    }
    if ((cVar4 == '\0') && ((*(uint *)(iVar3 + 0x248) & 0x100000) != 0)) {
      FUN_006202b0(&fStack_38);
      FUN_006202d0(&fStack_34);
      if (DAT_006e2b88 != fStack_38) {
        DAT_006e2b88 = fStack_38;
        (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x24,fStack_38);
      }
      if (DAT_006e2b8c != fStack_34) {
        DAT_006e2b8c = fStack_34;
        (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x25,fStack_34);
      }
      DAT_0070ab50 = 0;
      return;
    }
    iVar3 = FUN_0061f0d0();
    if (iVar3 == 0) {
      FUN_0061f040();
      FUN_0061eff0();
      FUN_0061f0d0();
    }
    FUN_006267a0(&fStack_38);
    FUN_006267c0(&fStack_34);
    FUN_00626800(&fStack_30);
    FUN_006267e0(&fStack_2c);
    pfVar5 = afStack_20;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pfVar5 = 0.0;
      pfVar5 = pfVar5 + 1;
    }
    FUN_006202b0(&DAT_0070ab34);
    FUN_006202d0(&DAT_0070ab38);
    if ((((fStack_38 != _DAT_0070ab24) || (fStack_34 != _DAT_0070ab28)) ||
        (fStack_30 != _DAT_0070ab2c)) ||
       (((fStack_2c != _DAT_0070ab30 || (afStack_20[2] != _DAT_0070ab34)) ||
        (fStack_8 != _DAT_0070ab38)))) {
      _DAT_0070ab24 = fStack_38;
      _DAT_0070ab28 = fStack_34;
      _DAT_0070ab30 = fStack_2c;
      _DAT_0070ab34 = afStack_20[2];
      _DAT_0070ab2c = fStack_30;
      _DAT_0070ab38 = fStack_8;
      fStack_4 = 1.0;
      afStack_20[3] = 1.0;
      afStack_20[2] = afStack_20[2] - fStack_38;
      fStack_8 = fStack_8 - fStack_38;
      FUN_00622690(2,afStack_20,afStack_20);
      fVar1 = afStack_20[2] / afStack_20[3];
      if (DAT_006e2b88 != fVar1) {
        DAT_006e2b88 = fVar1;
        (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x24,fVar1);
      }
      fVar1 = fStack_8 / fStack_4;
      if (DAT_006e2b8c != fVar1) {
        DAT_006e2b8c = fVar1;
        (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x25,fVar1);
        DAT_0070ab50 = 0;
        return;
      }
    }
    DAT_0070ab50 = 0;
    return;
  }
  FUN_006202b0(&fStack_24);
  FUN_006202d0(&fStack_2c);
  FUN_00620350(&fStack_30);
  _DAT_00709e64 = _K_ONE / (fStack_2c - fStack_24);
  _DAT_00709e60 = _DAT_00709e64 * -1.0;
  _DAT_00709e64 = _DAT_00709e64 * fStack_2c;
  FUN_0061f040();
  FUN_0061efe0();
  FUN_00620330(&iStack_28);
  if (iStack_28 == 1) {
    _DAT_00709e6c = 1.442695;
  }
  else {
    if (iStack_28 != 2) goto LAB_00625a6a;
    _DAT_00709e6c = 1.2011224;
  }
  _DAT_00709e6c = _DAT_00709e6c * fStack_30;
LAB_00625a6a:
  if (DAT_0070a4d4 != 0) {
    DAT_0070a4d4 = 0;
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x8c,0);
  }
  if (DAT_0070a4d8 != 0.0) {
    DAT_0070a4d8 = 0.0;
    (**(code **)(*DAT_00709d80 + 200))(DAT_00709d80,0x23,0);
  }
  DAT_0070ab50 = 0;
  return;
}


// ==== 0x625ad0 FUN_00625ad0

void FUN_00625ad0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uStack_4;
  
  uStack_4 = *(undefined4 *)(DAT_00709df0 + 0x10);
  uVar1 = *(undefined4 *)(DAT_00709df0 + 0xc);
  uVar2 = *(undefined4 *)(DAT_00709df0 + 4);
  iVar3 = *(int *)(DAT_00709df0 + 8);
  iVar4 = *(int *)(DAT_00709df4 + *(int *)(DAT_00709df0 + 0x28) * 8);
  iVar5 = iVar4 * iVar3;
  if (*(int *)(DAT_00709df0 + 0x14) < iVar4) {
    if (*(int *)(DAT_00709df0 + 0x10) != -1) {
      FUN_00622c60(&uStack_4,uVar2);
    }
    uStack_4 = EAGL__VertexBuffer__New(iVar5,iVar3,0x208,uVar1,DAT_0070ab48,iVar5 * 4);
    FUN_00622910();
    *(undefined4 *)(DAT_00709df0 + 0x10) = uStack_4;
    *(int *)(DAT_00709df0 + 0x14) = *(int *)(DAT_00709df4 + *(int *)(DAT_00709df0 + 0x28) * 8) << 2;
  }
  if (DAT_00709e00 == 0) {
    FUN_006232a0(*(undefined4 *)(DAT_00709df4 + 4 + *(int *)(DAT_00709df0 + 0x28) * 8),iVar5);
  }
  FUN_00622720(uVar2,uStack_4);
  return;
}


// ==== 0x625ba0 FUN_00625ba0

void FUN_00625ba0(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = _ftol_nocw();
  uVar2 = _ftol_nocw();
  uVar3 = _ftol_nocw();
  uVar4 = _ftol_nocw();
  FUN_00622940(((iVar1 << 8 | uVar2) << 8 | uVar3) << 8 | uVar4);
  return;
}


// ==== 0x625c10 FUN_00625c10

void FUN_00625c10(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = param_4;
  param_5 = param_4 + param_5;
  iVar1 = 0;
  if (0 < param_4) {
    param_4 = param_2;
    do {
      FUN_006240b0(iVar1,param_1,param_4,param_3);
      iVar1 = iVar1 + 1;
      param_4 = param_4 + 0x40;
    } while (iVar1 < iVar2);
  }
  if (iVar1 < param_5) {
    iVar2 = iVar1 * 0x40 + param_2;
    do {
      FUN_00624000(iVar1,param_1,iVar2,param_3);
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x40;
    } while (iVar1 < param_5);
  }
  if (iVar1 < param_5 + param_6) {
    param_2 = iVar1 * 0x40 + param_2;
    puVar3 = (uint *)(iVar1 * 0x10 + param_3);
    iVar1 = (param_5 + param_6) - iVar1;
    do {
      FUN_0063f1b0(param_2,(*puVar3 & 0xff) * 0x40 + param_1,0x40);
      puVar3 = puVar3 + 4;
      param_2 = param_2 + 0x40;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}


// ==== 0x625ce0 FUN_00625ce0

void FUN_00625ce0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = param_4;
  param_5 = param_4 + param_5;
  iVar1 = 0;
  if (0 < param_4) {
    param_4 = param_2;
    do {
      FUN_006242d0(iVar1,param_1,param_4,param_3);
      iVar1 = iVar1 + 1;
      param_4 = param_4 + 0x40;
    } while (iVar1 < iVar2);
  }
  if (iVar1 < param_5) {
    iVar2 = iVar1 * 0x40 + param_2;
    do {
      FUN_006241b0(iVar1,param_1,iVar2,param_3);
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x40;
    } while (iVar1 < param_5);
  }
  if (iVar1 < param_5 + param_6) {
    param_2 = iVar1 * 0x40 + param_2;
    puVar3 = (uint *)(iVar1 * 0x10 + param_3);
    iVar1 = (param_5 + param_6) - iVar1;
    do {
      FUN_0063f1b0(param_2,(*puVar3 & 0xff) * 0x40 + param_1,0x40);
      puVar3 = puVar3 + 4;
      param_2 = param_2 + 0x40;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}


// ==== 0x625db0 FUN_00625db0

void FUN_00625db0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = param_4;
  param_5 = param_4 + param_5;
  iVar1 = 0;
  if (0 < param_4) {
    param_4 = param_2;
    do {
      FUN_006245e0(iVar1,param_1,param_4,param_3);
      iVar1 = iVar1 + 1;
      param_4 = param_4 + 0x40;
    } while (iVar1 < iVar2);
  }
  if (iVar1 < param_5) {
    iVar2 = iVar1 * 0x40 + param_2;
    do {
      FUN_00624470(iVar1,param_1,iVar2,param_3);
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x40;
    } while (iVar1 < param_5);
  }
  if (iVar1 < param_5 + param_6) {
    param_2 = iVar1 * 0x40 + param_2;
    puVar3 = (uint *)(iVar1 * 0x10 + param_3);
    iVar1 = (param_5 + param_6) - iVar1;
    do {
      FUN_0063f1b0(param_2,(*puVar3 & 0xff) * 0x40 + param_1,0x40);
      puVar3 = puVar3 + 4;
      param_2 = param_2 + 0x40;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}


// ==== 0x625e80 FUN_00625e80

void FUN_00625e80(void)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_00709df0 + 8) >> 2;
  if (DAT_0070a9c4 < iVar1) {
    iVar1 = DAT_0070a9c4;
  }
  FUN_00625c10(*(undefined4 *)(DAT_00709df8 + 4),&DAT_0070aba0,DAT_0070a9c0,DAT_0070ab3c,
               DAT_0070ab40,DAT_0070ab44);
  FUN_00622700(*(undefined4 *)(DAT_00709df0 + 4),&DAT_0070aba0,iVar1 * 4);
  return;
}


// ==== 0x625ef0 FUN_00625ef0

void FUN_00625ef0(void)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_00709df0 + 8) >> 2;
  if (DAT_0070a9c4 < iVar1) {
    iVar1 = DAT_0070a9c4;
  }
  FUN_00625ce0(*(undefined4 *)(DAT_00709df8 + 4),&DAT_0070aba0,DAT_0070a9c0,DAT_0070ab3c,
               DAT_0070ab40,DAT_0070ab44);
  FUN_00622700(*(undefined4 *)(DAT_00709df0 + 4),&DAT_0070aba0,iVar1 * 4);
  return;
}


// ==== 0x625f60 FUN_00625f60

void FUN_00625f60(void)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_00709df0 + 8) >> 2;
  if (DAT_0070a9c4 < iVar2) {
    iVar2 = DAT_0070a9c4;
  }
  FUN_00625db0(*(undefined4 *)(DAT_00709df8 + 4),&DAT_0070aba0,DAT_0070a9c0,DAT_0070ab3c,
               DAT_0070ab40,DAT_0070ab44);
  if (0 < iVar2) {
    puVar1 = &DAT_0070aba0;
    do {
      D3DXMatrixTranspose(puVar1,puVar1);
      puVar1 = puVar1 + 0x40;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}


// ==== 0x625fd0 FUN_00625fd0

void FUN_00625fd0(void)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_00709df0 + 8) >> 2;
  if (DAT_0070a9c4 < iVar1) {
    iVar1 = DAT_0070a9c4;
  }
  FUN_00625db0(*(undefined4 *)(DAT_00709df8 + 4),&DAT_0070aba0,DAT_0070a9c0,DAT_0070ab3c,
               DAT_0070ab40,DAT_0070ab44);
  FUN_00622700(*(undefined4 *)(DAT_00709df0 + 4),&DAT_0070aba0,iVar1 * 4);
  return;
}


// ==== 0x626040 FUN_00626040

void FUN_00626040(void)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_00709df0 + 8) >> 2;
  if (DAT_0070a9c4 < iVar2) {
    iVar2 = DAT_0070a9c4;
  }
  FUN_00625c10(*(undefined4 *)(DAT_00709df8 + 4),&DAT_0070aba0,DAT_0070a9c0,DAT_0070ab3c,
               DAT_0070ab40,DAT_0070ab44);
  if (0 < iVar2) {
    puVar1 = &DAT_0070aba0;
    do {
      D3DXMatrixTranspose(puVar1,puVar1);
      puVar1 = puVar1 + 0x40;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}


// ==== 0x6260b0 FUN_006260b0

void FUN_006260b0(void)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_00709df0 + 8) >> 2;
  if (DAT_0070a9c4 < iVar2) {
    iVar2 = DAT_0070a9c4;
  }
  FUN_00625ce0(*(undefined4 *)(DAT_00709df8 + 4),&DAT_0070aba0,DAT_0070a9c0,DAT_0070ab3c,
               DAT_0070ab40,DAT_0070ab44);
  if (0 < iVar2) {
    puVar1 = &DAT_0070aba0;
    do {
      D3DXMatrixTranspose(puVar1,puVar1);
      puVar1 = puVar1 + 0x40;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}


// ==== 0x626120 FUN_00626120

void FUN_00626120(int param_1)

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
  undefined4 uVar13;
  int iVar14;
  float *pfVar15;
  float *pfVar16;
  float *pfVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  float *local_60;
  float *local_5c;
  float *local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float *local_40;
  float *local_3c;
  float *local_38;
  undefined4 local_34;
  float local_30 [4];
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  if (*(int *)(DAT_00709df0 + 0x20) < 0) {
    pfVar15 = *(float **)(DAT_00709df0 + 0x28);
    iVar14 = *(int *)(DAT_00709df0 + 0x18);
  }
  else {
    iVar14 = *(int *)(DAT_00709df0 + 8) * DAT_00709f70 * *(int *)(DAT_00709df0 + 0x1c) +
             *(int *)(DAT_00709df0 + 0x18);
    pfVar15 = (float *)(DAT_00709f70 * *(int *)(DAT_00709df0 + 0x1c) * 0x20 +
                       *(int *)(DAT_00709df0 + 0x28));
  }
  pfVar17 = *(float **)(DAT_00709df0 + 0x1c);
  local_34 = *(undefined4 *)(DAT_00709df0 + 0x10);
  local_5c = pfVar15;
  local_38 = pfVar17;
  DAT_0070ab50 = FUN_006230e0(0,(int)pfVar17 * param_1,&local_60,iVar14);
  if (DAT_0070fde0 == 0) {
    if (DAT_0070fdf4 == 0) {
      if (0 < (int)pfVar17) {
        do {
          local_58 = pfVar17;
          pfVar17 = local_60;
          local_3c = (float *)(&DAT_0070aba0 + (int)pfVar15[3] * 0x40);
          FUN_00643e50(pfVar15,local_3c,local_60);
          local_38 = pfVar17 + 4;
          local_40 = pfVar15 + 4;
          fVar1 = *local_40;
          fVar2 = local_3c[1];
          fVar3 = *local_40;
          fVar4 = local_3c[2];
          fVar5 = pfVar15[5];
          fVar6 = local_3c[5];
          fVar7 = pfVar15[5];
          fVar8 = local_3c[6];
          fVar9 = pfVar15[6];
          fVar10 = local_3c[9];
          fVar11 = pfVar15[6];
          fVar12 = local_3c[10];
          *local_38 = pfVar15[6] * local_3c[8] + pfVar15[5] * local_3c[4] + *local_40 * *local_3c;
          pfVar17[5] = fVar9 * fVar10 + fVar5 * fVar6 + fVar1 * fVar2;
          pfVar17[6] = fVar11 * fVar12 + fVar7 * fVar8 + fVar3 * fVar4;
          local_60 = (float *)((int)local_60 + param_1);
          pfVar15 = pfVar15 + 8;
          local_58 = (float *)((int)local_58 + -1);
          pfVar17 = local_58;
        } while (local_58 != (float *)0x0);
      }
    }
    else if (0 < (int)pfVar17) {
      pfVar17 = pfVar15 + 6;
      local_58 = local_38;
      do {
        FastExitMediaState();
        uVar18 = CONCAT44(*pfVar15,*pfVar15);
        uVar19 = CONCAT44(pfVar17[-5],pfVar17[-5]);
        uVar22 = CONCAT44(pfVar17[-4],pfVar17[-4]);
        iVar14 = (int)pfVar17[-3] * 0x40;
        uVar20 = PackedFloatingMUL(*(undefined8 *)(&DAT_0070abc0 + iVar14),uVar22);
        uVar21 = PackedFloatingADD(uVar20,*(undefined8 *)(&DAT_0070abd0 + iVar14));
        uVar20 = PackedFloatingMUL(*(undefined8 *)(&DAT_0070abb0 + iVar14),uVar19);
        uVar23 = PackedFloatingMUL(*(undefined8 *)(&DAT_0070aba0 + iVar14),uVar18);
        uVar20 = PackedFloatingADD(uVar23,uVar20);
        uVar20 = PackedFloatingADD(uVar20,uVar21);
        *(undefined8 *)local_60 = uVar20;
        uVar22 = PackedFloatingMUL(*(undefined8 *)(&DAT_0070abc8 + iVar14),uVar22);
        uVar22 = PackedFloatingADD(uVar22,*(undefined8 *)(&DAT_0070abd8 + iVar14));
        uVar19 = PackedFloatingMUL(*(undefined8 *)(&DAT_0070abb8 + iVar14),uVar19);
        uVar18 = PackedFloatingMUL(*(undefined8 *)(&DAT_0070aba8 + iVar14),uVar18);
        uVar18 = PackedFloatingADD(uVar18,uVar19);
        uVar18 = PackedFloatingADD(uVar18,uVar22);
        *(undefined8 *)(local_60 + 2) = uVar18;
        local_3c = pfVar17 + -2;
        uVar18 = CONCAT44(*local_3c,*local_3c);
        uVar19 = CONCAT44(pfVar17[-1],pfVar17[-1]);
        uVar22 = CONCAT44(*pfVar17,*pfVar17);
        uVar20 = PackedFloatingMUL(*(undefined8 *)(&DAT_0070abc0 + iVar14),uVar22);
        uVar21 = PackedFloatingMUL(*(undefined8 *)(&DAT_0070abb0 + iVar14),uVar19);
        uVar23 = PackedFloatingMUL(*(undefined8 *)(&DAT_0070aba0 + iVar14),uVar18);
        uVar21 = PackedFloatingADD(uVar23,uVar21);
        uVar20 = PackedFloatingADD(uVar21,uVar20);
        *(undefined8 *)(local_60 + 4) = uVar20;
        uVar22 = PackedFloatingMUL(*(undefined8 *)(&DAT_0070abc8 + iVar14),uVar22);
        uVar19 = PackedFloatingMUL(*(undefined8 *)(&DAT_0070abb8 + iVar14),uVar19);
        uVar18 = PackedFloatingMUL(*(undefined8 *)(&DAT_0070aba8 + iVar14),uVar18);
        uVar18 = PackedFloatingADD(uVar18,uVar19);
        uVar18 = PackedFloatingADD(uVar18,uVar22);
        local_38 = local_60;
        *(undefined8 *)(local_60 + 6) = uVar18;
        local_60[7] = pfVar17[1];
        FastExitMediaState();
        pfVar15 = pfVar15 + 8;
        local_60 = (float *)((int)local_60 + param_1);
        pfVar17 = pfVar17 + 8;
        local_58 = (float *)((int)local_58 + -1);
      } while (local_58 != (float *)0x0);
      local_58 = (float *)0x0;
    }
  }
  else if (0 < (int)pfVar17) {
    pfVar16 = pfVar15 + 5;
    local_58 = pfVar17;
    do {
      local_54 = *pfVar15;
      local_4c = pfVar16[-3];
      local_38 = local_60;
      local_50 = pfVar16[-4];
      iVar14 = (int)pfVar16[-2] * 0x40;
      local_48 = pfVar16[1];
      local_44 = *pfVar16;
      local_40 = (float *)pfVar16[-1];
      local_3c = pfVar16 + -1;
      local_30[0] = *(float *)(&DAT_0070aba0 + iVar14) * local_54 +
                    *(float *)(&DAT_0070abb0 + iVar14) * local_50 +
                    *(float *)(&DAT_0070abc0 + iVar14) * local_4c +
                    *(float *)(&DAT_0070abd0 + iVar14);
      local_30[1] = *(float *)(&DAT_0070aba4 + iVar14) * local_54 +
                    *(float *)(&DAT_0070abb4 + iVar14) * local_50 +
                    *(float *)(&DAT_0070abc4 + iVar14) * local_4c + *(float *)(iVar14 + 0x70abd4);
      local_30[2] = *(float *)(&DAT_0070aba8 + iVar14) * local_54 +
                    *(float *)(&DAT_0070abb8 + iVar14) * local_50 +
                    *(float *)(&DAT_0070abc8 + iVar14) * local_4c +
                    *(float *)(&DAT_0070abd8 + iVar14);
      local_30[3] = *(float *)(iVar14 + 0x70abac) * local_54 +
                    *(float *)(iVar14 + 0x70abbc) * local_50 +
                    *(float *)(iVar14 + 0x70abcc) * local_4c + *(float *)(iVar14 + 0x70abdc);
      local_20 = *(float *)(&DAT_0070aba0 + iVar14) * (float)local_40 +
                 *(float *)(&DAT_0070abb0 + iVar14) * local_44 +
                 *(float *)(&DAT_0070abc0 + iVar14) * local_48;
      fStack_1c = *(float *)(&DAT_0070aba4 + iVar14) * (float)local_40 +
                  *(float *)(&DAT_0070abb4 + iVar14) * local_44 +
                  *(float *)(&DAT_0070abc4 + iVar14) * local_48;
      fStack_18 = *(float *)(&DAT_0070aba8 + iVar14) * (float)local_40 +
                  *(float *)(&DAT_0070abb8 + iVar14) * local_44 +
                  *(float *)(&DAT_0070abc8 + iVar14) * local_48;
      fStack_14 = pfVar16[2];
      pfVar15 = local_30;
      pfVar17 = local_60;
      for (iVar14 = 8; iVar14 != 0; iVar14 = iVar14 + -1) {
        *pfVar17 = *pfVar15;
        pfVar15 = pfVar15 + 1;
        pfVar17 = pfVar17 + 1;
      }
      pfVar15 = local_5c + 8;
      local_60 = (float *)((int)local_60 + param_1);
      pfVar16 = pfVar16 + 8;
      local_58 = (float *)((int)local_58 + -1);
      local_5c = pfVar15;
    } while (local_58 != (float *)0x0);
    local_58 = (float *)0x0;
  }
  uVar13 = local_34;
  FUN_00622b40();
  FUN_00622720(*(undefined4 *)(DAT_00709df0 + 4),uVar13);
  return;
}


// ==== 0x626520 FUN_00626520

void FUN_00626520(int param_1,int param_2)

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
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  float *pfVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  float *local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  
  if (*(int *)(DAT_00709df0 + 0x20) < 0) {
    iVar14 = *(int *)(DAT_00709df0 + 0x18);
    pfVar16 = *(float **)(DAT_00709df0 + 0x28);
  }
  else {
    iVar14 = *(int *)(DAT_00709df0 + 8) * DAT_00709f70 * *(int *)(DAT_00709df0 + 0x1c) +
             *(int *)(DAT_00709df0 + 0x18);
    pfVar16 = (float *)(DAT_00709f70 * *(int *)(DAT_00709df0 + 0x1c) * 0x10 +
                       *(int *)(DAT_00709df0 + 0x28));
  }
  iVar15 = *(int *)(DAT_00709df0 + 0x1c);
  local_14 = *(undefined4 *)(DAT_00709df0 + 0x10);
  DAT_0070ab50 = FUN_006230e0(0,iVar15 * param_1,&local_24,iVar14);
  if (DAT_0070fde0 == 0) {
    if (DAT_0070fdf4 == 0) {
      if (0 < iVar15) {
        do {
          FUN_00643e50(pfVar16,&DAT_0070aba0 + (int)pfVar16[3] * 0x40,local_24);
          local_24 = (float *)((int)local_24 + param_1);
          pfVar16 = (float *)((int)pfVar16 + param_2);
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
    }
    else if (0 < iVar15) {
      do {
        FastExitMediaState();
        uVar17 = CONCAT44(*pfVar16,*pfVar16);
        uVar18 = CONCAT44(pfVar16[1],pfVar16[1]);
        uVar21 = CONCAT44(pfVar16[2],pfVar16[2]);
        iVar14 = (int)pfVar16[3] * 0x40;
        uVar19 = PackedFloatingMUL(*(undefined8 *)(&DAT_0070abc0 + iVar14),uVar21);
        uVar20 = PackedFloatingADD(uVar19,*(undefined8 *)(&DAT_0070abd0 + iVar14));
        uVar19 = PackedFloatingMUL(*(undefined8 *)(&DAT_0070abb0 + iVar14),uVar18);
        uVar22 = PackedFloatingMUL(*(undefined8 *)(&DAT_0070aba0 + iVar14),uVar17);
        uVar19 = PackedFloatingADD(uVar22,uVar19);
        uVar19 = PackedFloatingADD(uVar19,uVar20);
        *(undefined8 *)local_24 = uVar19;
        uVar21 = PackedFloatingMUL(*(undefined8 *)(&DAT_0070abc8 + iVar14),uVar21);
        uVar21 = PackedFloatingADD(uVar21,*(undefined8 *)(&DAT_0070abd8 + iVar14));
        uVar18 = PackedFloatingMUL(*(undefined8 *)(&DAT_0070abb8 + iVar14),uVar18);
        uVar17 = PackedFloatingMUL(*(undefined8 *)(&DAT_0070aba8 + iVar14),uVar17);
        uVar17 = PackedFloatingADD(uVar17,uVar18);
        uVar17 = PackedFloatingADD(uVar17,uVar21);
        *(undefined8 *)(local_24 + 2) = uVar17;
        local_24 = (float *)((int)local_24 + param_1);
        pfVar16 = (float *)((int)pfVar16 + param_2);
        iVar15 = iVar15 + -1;
        FastExitMediaState();
      } while (iVar15 != 0);
    }
  }
  else if (0 < iVar15) {
    do {
      local_20 = pfVar16[2];
      local_1c = pfVar16[1];
      iVar14 = (int)pfVar16[3] * 0x40;
      fVar1 = *(float *)(iVar14 + 0x70abd4);
      fVar2 = *(float *)(&DAT_0070abd8 + iVar14);
      fVar3 = *(float *)(iVar14 + 0x70abdc);
      fVar4 = *(float *)(&DAT_0070abc4 + iVar14);
      fVar5 = *(float *)(&DAT_0070abc8 + iVar14);
      fVar6 = *(float *)(iVar14 + 0x70abcc);
      fVar7 = *(float *)(&DAT_0070aba4 + iVar14);
      fVar8 = *(float *)(&DAT_0070aba8 + iVar14);
      fVar9 = *(float *)(iVar14 + 0x70abac);
      local_18 = *pfVar16;
      fVar10 = *(float *)(&DAT_0070abb4 + iVar14);
      fVar11 = *(float *)(&DAT_0070abb8 + iVar14);
      fVar12 = *(float *)(iVar14 + 0x70abbc);
      *local_24 = *(float *)(&DAT_0070aba0 + iVar14) * local_18 +
                  *(float *)(&DAT_0070abb0 + iVar14) * local_1c +
                  *(float *)(&DAT_0070abc0 + iVar14) * local_20 + *(float *)(&DAT_0070abd0 + iVar14)
      ;
      local_24[1] = fVar7 * local_18 + fVar10 * local_1c + fVar4 * local_20 + fVar1;
      local_24[2] = fVar8 * local_18 + fVar11 * local_1c + fVar5 * local_20 + fVar2;
      local_24[3] = fVar9 * local_18 + fVar12 * local_1c + fVar6 * local_20 + fVar3;
      local_24 = (float *)((int)local_24 + param_1);
      pfVar16 = (float *)((int)pfVar16 + param_2);
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
  }
  uVar13 = local_14;
  FUN_00622b40();
  FUN_00622720(*(undefined4 *)(DAT_00709df0 + 4),uVar13);
  return;
}


// ==== 0x626740 FUN_00626740

void FUN_00626740(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(DAT_00709df0 + 0xc);
  uVar1 = *(undefined4 *)(DAT_00709df0 + 8);
  iVar2 = EAGL__PC__GetDirectDraw();
  uVar4 = uVar4 & 0x10;
  if ((uVar4 != 0) && ((0 < *(int *)(iVar2 + 0x2c4) || (DAT_0070ab48 == 0)))) {
    FUN_00626120(uVar1);
    return;
  }
  uVar3 = 0x10;
  if (uVar4 != 0) {
    uVar3 = 0x20;
  }
  FUN_00626520(uVar1,uVar3);
  return;
}


// ==== 0x626772 FUN_00626772

void FUN_00626772(void)

{
  return;
}


// ==== 0x6267a0 FUN_006267a0

void __thiscall FUN_006267a0(int *param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(*param_1 + 0x110);
  return;
}


// ==== 0x6267c0 FUN_006267c0

void __thiscall FUN_006267c0(int *param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(*param_1 + 0x114);
  return;
}


// ==== 0x6267e0 FUN_006267e0

void __thiscall FUN_006267e0(int *param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(*param_1 + 0x108);
  return;
}


// ==== 0x626800 FUN_00626800

void __thiscall FUN_00626800(int *param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(*param_1 + 0x10c);
  return;
}


// ==== 0x626820 FUN_00626820

void __thiscall FUN_00626820(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *param_1) {
    do {
      piVar1 = *(int **)(param_1[1] + iVar2 * 4);
      switch(piVar1[2]) {
      case 3:
        if (*(int *)(&DAT_0070ab00 + piVar1[3] * 4) != 0) {
          FUN_00621e00(piVar1[1]);
          FUN_00621bc0();
        }
        break;
      case 4:
        FUN_00623780();
        break;
      case 5:
        *(int *)(*piVar1 + param_2) = piVar1[3];
        break;
      case 6:
        iVar3 = piVar1[3];
        goto LAB_006268a1;
      case 7:
        FUN_006227c0(piVar1[3]);
        break;
      case 8:
        iVar3 = piVar1[3];
LAB_006268a1:
        FUN_006226d0(iVar3);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *param_1);
  }
  return;
}


// ==== 0x6268d0 FUN_006268d0

void __thiscall FUN_006268d0(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *param_1) {
    do {
      piVar1 = *(int **)(param_1[1] + iVar2 * 4);
      switch(piVar1[2]) {
      case 3:
        if (*(int *)(&DAT_0070ab00 + piVar1[3] * 4) != 0) {
          FUN_00621e00(piVar1[1]);
          FUN_00621bc0();
        }
        break;
      case 5:
        *(int *)(*piVar1 + param_2) = piVar1[3];
        break;
      case 6:
        iVar3 = piVar1[3];
        goto LAB_00626944;
      case 7:
        FUN_006227c0(piVar1[3]);
        break;
      case 8:
        iVar3 = piVar1[3];
LAB_00626944:
        FUN_006226d0(iVar3);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *param_1);
  }
  return;
}


// ==== 0x626980 FUN_00626980

undefined4 __thiscall FUN_00626980(int param_1,int param_2)

{
  return *(undefined4 *)(*(int *)(param_1 + 0x18) + param_2 * 4);
}


// ==== 0x626990 FUN_00626990

undefined4 __fastcall FUN_00626990(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1c);
}


// ==== 0x6269a0 FUN_006269a0

void __thiscall FUN_006269a0(int param_1,undefined4 *param_2,undefined4 param_3)

{
  *param_2 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x20) * 4) + 8);
  FUN_006268d0(param_3);
  return;
}


// ==== 0x6269d0 FUN_006269d0

void FUN_006269d0(undefined4 param_1,undefined4 param_2)

{
  FUN_00626820(param_2);
  return;
}


// ==== 0x6269f0 FUN_006269f0

void __fastcall FUN_006269f0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = 0;
  if (0 < *param_1) {
    do {
      iVar1 = *(int *)(param_1[1] + iVar2 * 4);
      if (iVar1 != 0) {
        iVar3 = *(int *)(iVar1 + 8);
        if (iVar3 == 6) {
LAB_00626a18:
          iVar3 = *(int *)(iVar1 + 0xc);
          if (iVar3 != 0) {
            FUN_00622dd0();
            uVar4 = 0x20;
LAB_00626a28:
            (*(code *)PTR_FUN_006dfaa0)(iVar3,uVar4);
          }
LAB_00626a32:
          *(undefined4 *)(iVar1 + 0xc) = 0;
        }
        else {
          if (iVar3 == 7) {
            iVar3 = *(int *)(iVar1 + 0xc);
            if ((iVar3 != 0) && (iVar3 != -1)) {
              FUN_00622e30();
              uVar4 = 0x14;
              goto LAB_00626a28;
            }
            goto LAB_00626a32;
          }
          if (iVar3 == 8) goto LAB_00626a18;
        }
        (*(code *)PTR_FUN_006dfaa0)(iVar1,0x10);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *param_1);
  }
  if (param_1[1] != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1[1],*param_1 << 2);
  }
  return;
}


// ==== 0x626a80 FUN_00626a80

void __fastcall FUN_00626a80(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (0 < param_1[2]) {
    iVar2 = 0;
    do {
      iVar1 = *(int *)(param_1[3] + iVar2 * 4);
      if (iVar1 != 0) {
        FUN_006269f0();
        (*(code *)PTR_FUN_006dfaa0)(iVar1,8);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[2]);
  }
  if (param_1[3] != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1[3],param_1[2] << 2);
  }
  iVar2 = 0;
  if (0 < *param_1) {
    do {
      iVar1 = *(int *)(param_1[1] + iVar2 * 4);
      if (iVar1 != 0) {
        iVar3 = *(int *)(iVar1 + 8);
        if (iVar3 == 6) {
LAB_00626aee:
          iVar3 = *(int *)(iVar1 + 0xc);
          if (iVar3 != 0) {
            FUN_00622dd0();
            uVar4 = 0x20;
LAB_00626afe:
            (*(code *)PTR_FUN_006dfaa0)(iVar3,uVar4);
          }
LAB_00626b08:
          *(undefined4 *)(iVar1 + 0xc) = 0;
        }
        else {
          if (iVar3 == 7) {
            iVar3 = *(int *)(iVar1 + 0xc);
            if ((iVar3 != 0) && (iVar3 != -1)) {
              FUN_00622e30();
              uVar4 = 0x14;
              goto LAB_00626afe;
            }
            goto LAB_00626b08;
          }
          if (iVar3 == 8) goto LAB_00626aee;
        }
        (*(code *)PTR_FUN_006dfaa0)(iVar1,0x10);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *param_1);
  }
  if (param_1[1] != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1[1],*param_1 << 2);
  }
  return;
}


// ==== 0x626b60 FUN_00626b60

void __fastcall FUN_00626b60(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_1[2]) {
    do {
      iVar1 = *(int *)(param_1[4] + iVar2 * 4);
      if (iVar1 != 0) {
        FUN_00626a80();
        (*(code *)PTR_FUN_006dfaa0)(iVar1,0x14);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[2]);
  }
  if (param_1[4] != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1[4],param_1[2] << 2);
    param_1[4] = 0;
  }
  if (param_1[3] != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1[3],param_1[2] << 2);
    param_1[3] = 0;
  }
  if (*param_1 != 0) {
    (*(code *)PTR_FUN_006dfaa0)(*param_1,param_1[1] << 2);
    *param_1 = 0;
  }
  if (param_1[5] != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1[5],param_1[7] << 2);
    param_1[5] = 0;
  }
  if (param_1[6] != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1[6],param_1[7] << 2);
    param_1[6] = 0;
  }
  return;
}


// ==== 0x626c20 FUN_00626c20

void FUN_00626c20(void)

{
  return;
}


// ==== 0x626c30 FUN_00626c30

undefined1 FUN_00626c30(void)

{
  return 0;
}


// ==== 0x626c40 FUN_00626c40

undefined1 FUN_00626c40(void)

{
  return 0;
}


// ==== 0x626c50 FUN_00626c50

undefined1 FUN_00626c50(void)

{
  return 0;
}


// ==== 0x626c60 FUN_00626c60

undefined4 * __fastcall FUN_00626c60(undefined4 *param_1)

{
  FUN_00628eb0();
  *param_1 = &PTR_FUN_006a7a98;
  *(undefined1 *)(param_1 + 4) = 1;
  param_1[2] = 0;
  return param_1;
}


// ==== 0x626c80 FUN_00626c80

undefined4 __thiscall FUN_00626c80(int param_1,float *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *param_2 = (float)*(int *)(iVar1 + 0xc);
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


// ==== 0x626ca0 FUN_00626ca0

undefined4 * __thiscall FUN_00626ca0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a7a98;
  FUN_00628ed0();
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x14);
  }
  return param_1;
}


// ==== 0x626cd0 FUN_00626cd0

undefined4 * __fastcall FUN_00626cd0(undefined4 *param_1)

{
  FUN_00628eb0();
  param_1[4] = 0;
  param_1[5] = 0;
  *param_1 = &PTR_FUN_006a7ae0;
  param_1[2] = 1;
  return param_1;
}


// ==== 0x626d00 FUN_00626d00

void __thiscall FUN_00626d00(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// ==== 0x626d20 FUN_00626d20

undefined4 __thiscall
FUN_00626d20(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  FUN_00628f60(param_2,param_3,param_1 + 0x10,param_1 + 0x14,param_4,param_5);
  return 1;
}


// ==== 0x626d50 FUN_00626d50

void __thiscall FUN_00626d50(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(*param_1 + 0x24))(param_2,param_3,param_4,0);
  return;
}


// ==== 0x626d70 FUN_00626d70

undefined4 * __thiscall FUN_00626d70(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a7ae0;
  FUN_00628ed0();
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x18);
  }
  return param_1;
}


// ==== 0x626da0 FUN_00626da0

undefined4 * __fastcall FUN_00626da0(undefined4 *param_1)

{
  FUN_00628eb0();
  *param_1 = &PTR_FUN_006a7b28;
  *(undefined1 *)(param_1 + 4) = 1;
  param_1[2] = 2;
  return param_1;
}


// ==== 0x626dc0 FUN_00626dc0

undefined4 __thiscall FUN_00626dc0(int param_1,float *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *param_2 = (float)*(ushort *)(iVar1 + 6);
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


// ==== 0x626de0 FUN_00626de0

undefined4 * __thiscall FUN_00626de0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a7b28;
  FUN_00628ed0();
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x14);
  }
  return param_1;
}


// ==== 0x626e10 FUN_00626e10

undefined4 __thiscall FUN_00626e10(undefined4 param_1,byte param_2)

{
  FUN_00629280();
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x20);
  }
  return param_1;
}


// ==== 0x626e40 FUN_00626e40

undefined4 * __fastcall FUN_00626e40(undefined4 *param_1)

{
  FUN_00628eb0();
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[4] = 0xffffffff;
  *param_1 = &PTR_FUN_006a7bb8;
  param_1[2] = 0xc;
  return param_1;
}


// ==== 0x626e70 FUN_00626e70

undefined4 * __fastcall FUN_00626e70(undefined4 *param_1)

{
  FUN_00628eb0();
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[4] = 0xffffffff;
  *param_1 = &PTR_FUN_006a7c00;
  param_1[2] = 0xd;
  return param_1;
}


// ==== 0x626ea0 FUN_00626ea0

undefined4 __thiscall FUN_00626ea0(undefined4 param_1,byte param_2)

{
  FUN_00629240();
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x20);
  }
  return param_1;
}


// ==== 0x626ed0 FUN_00626ed0

undefined4 __thiscall FUN_00626ed0(int param_1,float *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *param_2 = (float)*(ushort *)(iVar1 + 8);
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


// ==== 0x626ef0 FUN_00626ef0

undefined4 * __thiscall FUN_00626ef0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a7a94;
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x14);
  }
  return param_1;
}


// ==== 0x626f20 FUN_00626f20

void __thiscall FUN_00626f20(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      (**(code **)(**(int **)(*(int *)(param_1 + 0xc) + iVar1 * 4) + 0xc))(param_2,param_3,param_4);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x10));
  }
  return;
}


// ==== 0x626f70 FUN_00626f70

void __fastcall FUN_00626f70(undefined4 *param_1)

{
  param_1[1] = 0;
  *param_1 = &PTR_FUN_006a7ccc;
  param_1[3] = 0;
  param_1[10] = 0xffffffff;
  param_1[5] = 0;
  param_1[4] = 0;
  *(undefined1 *)((int)param_1 + 0x7d) = 0;
  *(undefined1 *)(param_1 + 0x1f) = 0;
  param_1[2] = 6;
  return;
}


// ==== 0x626fa0 FUN_00626fa0

undefined4 * __thiscall FUN_00626fa0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a7a94;
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x80);
  }
  return param_1;
}


// ==== 0x626fd0 FUN_00626fd0

void __fastcall FUN_00626fd0(undefined4 *param_1)

{
  param_1[1] = 0;
  *param_1 = &PTR_FUN_006a7d08;
  param_1[3] = 0;
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 0x19) = 1;
  param_1[2] = 7;
  return;
}


// ==== 0x627000 FUN_00627000

void __thiscall FUN_00627000(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_retaddr;
  
  if (*(char *)(param_1 + 0x19) != '\0') {
    (**(code **)(**(int **)(param_1 + 0xc) + 0xc))(param_2,param_3,*(undefined4 *)(param_1 + 0x14));
    FUN_00627ec0(*(undefined4 *)(param_1 + 0x14),unaff_retaddr,*(undefined1 *)(param_1 + 0x18),0);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0062703e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0xc) + 0xc))();
  return;
}


// ==== 0x627050 FUN_00627050

char __thiscall FUN_00627050(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 unaff_ESI;
  
  if (*(char *)(param_1 + 0x19) != '\0') {
    cVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))
                      (param_2,*(undefined4 *)(param_1 + 0x14),param_4);
    if (cVar1 != '\0') {
      FUN_00627ec0(*(undefined4 *)(param_1 + 0x14),unaff_ESI,*(undefined1 *)(param_1 + 0x18),param_4
                  );
    }
    return cVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x00627099. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  cVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
  return cVar1;
}


// ==== 0x6270a0 FUN_006270a0

undefined4 * __thiscall FUN_006270a0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a7a94;
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x1c);
  }
  return param_1;
}


// ==== 0x6270d0 FUN_006270d0

undefined4 * __thiscall FUN_006270d0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a7a94;
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x2c);
  }
  return param_1;
}


// ==== 0x627100 FUN_00627100

undefined4 * __fastcall FUN_00627100(undefined4 *param_1)

{
  FUN_00628eb0();
  *param_1 = &PTR_FUN_006a7dc0;
  *(undefined2 *)(param_1 + 4) = 0;
  *(undefined1 *)((int)param_1 + 0x15) = 1;
  param_1[2] = 0xe;
  return param_1;
}


// ==== 0x627130 FUN_00627130

undefined4 __fastcall FUN_00627130(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}


// ==== 0x627140 FUN_00627140

undefined4 * __fastcall FUN_00627140(undefined4 *param_1)

{
  FUN_00628eb0();
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  *(undefined1 *)((int)param_1 + 0x15) = 0;
  *param_1 = &PTR_FUN_006a7e08;
  param_1[2] = 0xf;
  return param_1;
}


// ==== 0x627170 FUN_00627170

undefined4 __fastcall FUN_00627170(int param_1)

{
  return CONCAT22((short)((uint)*(int *)(param_1 + 0xc) >> 0x10),
                  *(undefined2 *)(*(int *)(param_1 + 0xc) + 2));
}


// ==== 0x627180 FUN_00627180

undefined4 __thiscall FUN_00627180(int param_1,float *param_2)

{
  float fVar1;
  
  fVar1 = (float)*(ushort *)(*(int *)(param_1 + 0xc) + 10);
  *param_2 = fVar1;
  if (*(char *)(param_1 + 0x14) != '\0') {
    *param_2 = fVar1 / (float)*(byte *)(param_1 + 0x15);
  }
  return 1;
}


// ==== 0x6271c0 FUN_006271c0

undefined4 __thiscall FUN_006271c0(undefined4 param_1,byte param_2)

{
  FUN_0062b0d0();
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x18);
  }
  return param_1;
}


// ==== 0x6271f0 FUN_006271f0

undefined4 * __fastcall FUN_006271f0(undefined4 *param_1)

{
  FUN_00628eb0();
  *param_1 = &PTR_FUN_006a7e50;
  param_1[4] = 0;
  param_1[2] = 0x10;
  return param_1;
}


// ==== 0x627210 FUN_00627210

void __thiscall FUN_00627210(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(*param_1 + 0x2c))(param_3,param_4);
  return;
}


// ==== 0x627230 FUN_00627230

undefined4 * __thiscall FUN_00627230(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a7e50;
  FUN_00628ed0();
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x14);
  }
  return param_1;
}


// ==== 0x627260 FUN_00627260

int FUN_00627260(void)

{
  return DAT_0070cee8 - DAT_0070d35c;
}


// ==== 0x627270 FUN_00627270

int FUN_00627270(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_0070d364 + 0xc))();
  return DAT_0070d358 - iVar1;
}


// ==== 0x627290 FUN_00627290

void FUN_00627290(ushort param_1)

{
  ushort uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_1;
  puVar2 = (undefined4 *)(&DAT_0070cef0)[uVar3];
  if (puVar2 == (undefined4 *)0x0) {
    uVar1 = *(ushort *)(&DAT_006e58a8 + uVar3 * 2);
    *DAT_0070cee8 = 0;
    (&DAT_0070cef0)[uVar3] = DAT_0070cee8;
    DAT_0070cee8 = (undefined4 *)((int)DAT_0070cee8 + (uint)uVar1);
    puVar2 = (undefined4 *)(&DAT_0070cef0)[uVar3];
  }
  (&DAT_0070cef0)[uVar3] = *puVar2;
  return;
}


// ==== 0x6272e0 FUN_006272e0

uint * FUN_006272e0(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = param_1 >> 4 & 0xff;
  puVar1 = (uint *)(&DAT_0070cf50)[uVar2];
  if (puVar1 != (uint *)0x0) {
    (&DAT_0070cf50)[uVar2] = *puVar1;
    return puVar1;
  }
  *DAT_0070cee8 = uVar2;
  puVar1 = DAT_0070cee8 + 1;
  DAT_0070cee8 = DAT_0070cee8 + uVar2 * 4 + 5;
  return puVar1;
}


// ==== 0x627330 FUN_00627330

void FUN_00627330(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  DAT_0070cee8 = DAT_0070d35c;
  puVar2 = &DAT_0070cf50;
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_0070cef0;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== 0x627360 EAGLAnim::MemoryPool_Create

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render low (hopper+ghidra) docs/re/render.md */

void EAGLAnim__MemoryPool_Create(undefined4 param_1)

{
  DAT_0070d358 = param_1;
  DAT_0070d35c = (*(code *)PTR_FUN_006dfa9c)(param_1,"EAGLAnim Memory Pool");
  _DAT_0070d354 = 0;
  (**(code **)(*DAT_0070d364 + 0x34))();
  return;
}


// ==== 0x6273a0 FUN_006273a0

void FUN_006273a0(void)

{
  (*(code *)PTR_FUN_006dfaa0)(DAT_0070d35c,DAT_0070d358);
  return;
}


// ==== 0x6273c0 FUN_006273c0

int * FUN_006273c0(short *param_1)

{
  short sVar1;
  int *piVar2;
  
  sVar1 = *param_1;
  if ((sVar1 != 0x16) && (sVar1 != 0x17)) {
    piVar2 = (int *)(**(code **)(*DAT_0070d364 + 0x28))(sVar1);
    (**(code **)(*piVar2 + 0x3c))(param_1);
    return piVar2;
  }
  (**(code **)(*(int *)(param_1 + -0xc) + 0x3c))(param_1);
  return (int *)(param_1 + -0xc);
}


// ==== 0x627410 FUN_00627410

void FUN_00627410(undefined2 *param_1)

{
  switch(*param_1) {
  case 0:
    FUN_0062be20(param_1);
    return;
  case 0xf:
    FUN_0062b530(param_1);
    return;
  case 0x16:
    FUN_0062b950(param_1);
    return;
  case 0x17:
    FUN_0062b920(param_1);
  }
  return;
}


// ==== 0x627490 FUN_00627490

void FUN_00627490(ushort param_1,undefined4 *param_2)

{
  *param_2 = (&DAT_0070cef0)[param_1];
  (&DAT_0070cef0)[param_1] = param_2;
  return;
}


// ==== 0x6274b0 FUN_006274b0

void FUN_006274b0(undefined4 *param_1)

{
  *param_1 = (&DAT_0070cf50)[param_1[-1]];
  (&DAT_0070cf50)[param_1[-1]] = param_1;
  return;
}


// ==== 0x6274d0 FUN_006274d0

void FUN_006274d0(undefined4 *param_1)

{
  if ((param_1[2] != 0x16) && (param_1[2] != 0x17)) {
    (**(code **)*param_1)(0);
    (**(code **)(*DAT_0070d364 + 0x20))(*(undefined2 *)(param_1 + 2),param_1);
  }
  return;
}


// ==== 0x627510 FUN_00627510

void __thiscall FUN_00627510(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00627530(param_3,param_4,*(undefined1 *)(param_1 + 0x10));
  return;
}


// ==== 0x627530 FUN_00627530

void __thiscall FUN_00627530(int param_1,float param_2,undefined4 param_3,char param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 < 0.0) {
    fVar1 = param_2 + 0.499999;
  }
  else {
    fVar1 = param_2 - 0.499999;
  }
  iVar3 = (int)ROUND(fVar1);
  if (iVar3 < 0) {
    FUN_00627600(0,param_3);
    return;
  }
  iVar2 = *(ushort *)(param_1 + 6) - 1;
  if (iVar2 <= iVar3) {
    FUN_00627600(iVar2,param_3);
    return;
  }
  if ((param_2 - (float)iVar3 != 0.0) && (param_4 != '\0')) {
    FUN_00627640(param_2 - (float)iVar3,iVar3,iVar3 + 1,param_3);
    return;
  }
  FUN_00627600(iVar3,param_3);
  return;
}


// ==== 0x627600 FUN_00627600

void __thiscall FUN_00627600(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)*(ushort *)(param_1 + 4);
  iVar1 = 0;
  if (uVar2 != 0) {
    do {
      *(undefined4 *)(param_3 + (uint)*(ushort *)(param_1 + 8 + iVar1 * 2) * 4) =
           *(undefined4 *)
            (param_1 + ((uVar2 + 1 & 0xfffffffe) + 4 + uVar2 * param_2 * 2) * 2 + iVar1 * 4);
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)(uint)*(ushort *)(param_1 + 4));
  }
  return;
}


// ==== 0x627640 FUN_00627640

void __thiscall FUN_00627640(int param_1,float param_2,int param_3,int param_4,int param_5)

{
  float *pfVar1;
  int iVar2;
  float *pfVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = (uint)*(ushort *)(param_1 + 4);
  uVar4 = uVar6 + 1 & 0xfffffffe;
  iVar5 = 0;
  pfVar1 = (float *)(param_1 + (uVar4 + 4 + uVar6 * param_3 * 2) * 2);
  if (uVar6 != 0) {
    pfVar3 = pfVar1;
    do {
      iVar2 = iVar5 * 2;
      iVar5 = iVar5 + 1;
      *(float *)(param_5 + (uint)*(ushort *)(param_1 + 8 + iVar2) * 4) =
           (*(float *)(((param_1 + (uVar4 + 4 + uVar6 * param_4 * 2) * 2) - (int)pfVar1) +
                      (int)pfVar3) - *pfVar3) * param_2 + *pfVar3;
      pfVar3 = pfVar3 + 1;
    } while (iVar5 < (int)(uint)*(ushort *)(param_1 + 4));
  }
  return;
}


// ==== 0x6276b0 FUN_006276b0

undefined4 * __fastcall FUN_006276b0(undefined4 *param_1)

{
  FUN_00628eb0();
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[4] = 0xffffffff;
  *param_1 = &PTR_FUN_006a7eb8;
  param_1[2] = 10;
  return param_1;
}


// ==== 0x6276e0 FUN_006276e0

undefined4 * __fastcall FUN_006276e0(undefined4 *param_1)

{
  FUN_00628eb0();
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[4] = 0xffffffff;
  *param_1 = &PTR_FUN_006a7f00;
  param_1[2] = 0xb;
  return param_1;
}


// ==== 0x627710 FUN_00627710

void __thiscall FUN_00627710(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  float10 fVar2;
  float fVar3;
  
  iVar1 = **(int **)(param_1 + 0x18);
  fVar2 = (float10)FUN_00627750(param_3);
  fVar3 = (float)fVar2;
  fVar2 = (float10)FUN_00627750(param_2);
  (**(code **)(iVar1 + 0xc))((float)fVar2,fVar3,param_4);
  return;
}


// ==== 0x627750 FUN_00627750

float10 __thiscall FUN_00627750(int param_1,float param_2)

{
  float fVar1;
  undefined4 local_8;
  
  if (param_2 < *(float *)(param_1 + 0xc)) {
    param_2 = param_2 - *(float *)(param_1 + 0xc);
    fVar1 = param_2 / *(float *)(param_1 + 0x14);
    if (fVar1 < 0.0) {
      fVar1 = fVar1 + 0.499999;
    }
    else {
      fVar1 = fVar1 - 0.499999;
    }
    local_8 = (int)ROUND(fVar1);
    return (float10)*(float *)(param_1 + 0x10) -
           ((float10)param_2 - (float10)local_8 * (float10)*(float *)(param_1 + 0x14));
  }
  if (*(float *)(param_1 + 0x10) < param_2) {
    param_2 = param_2 - *(float *)(param_1 + 0x10);
    fVar1 = param_2 / *(float *)(param_1 + 0x14);
    if (fVar1 < 0.0) {
      fVar1 = fVar1 + 0.499999;
    }
    else {
      fVar1 = fVar1 - 0.499999;
    }
    local_8 = (int)ROUND(fVar1);
    return ((float10)param_2 - (float10)local_8 * (float10)*(float *)(param_1 + 0x14)) +
           (float10)*(float *)(param_1 + 0xc);
  }
  return (float10)param_2;
}


// ==== 0x627850 FUN_00627850

void __thiscall
FUN_00627850(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  float10 fVar2;
  float fVar3;
  
  iVar1 = **(int **)(param_1 + 0x18);
  fVar2 = (float10)FUN_00627750(param_3);
  fVar3 = (float)fVar2;
  fVar2 = (float10)FUN_00627750(param_2);
  (**(code **)(iVar1 + 0x24))((float)fVar2,fVar3,param_4,param_5);
  return;
}


// ==== 0x627890 FUN_00627890

void __thiscall FUN_00627890(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = **(int **)(param_1 + 0x18);
  fVar2 = (float10)FUN_00627750(param_2);
  (**(code **)(iVar1 + 0x18))((float)fVar2,param_3,param_4);
  return;
}


// ==== 0x6278c0 FUN_006278c0

void __thiscall FUN_006278c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = **(int **)(param_1 + 0x18);
  fVar2 = (float10)FUN_00627750(param_2);
  (**(code **)(iVar1 + 0x1c))((float)fVar2,param_3);
  return;
}


// ==== 0x6278f0 FUN_006278f0

undefined4 __thiscall FUN_006278f0(undefined4 param_1,byte param_2)

{
  FUN_00628ed0();
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x18);
  }
  return param_1;
}


// ==== 0x627920 FUN_00627920

undefined4 * FUN_00627920(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_0070d364 + 0x1c))(param_1);
  switch(param_1) {
  case 0:
    if (puVar1 != (undefined4 *)0x0) {
      FUN_00626c60();
      return puVar1;
    }
    break;
  case 1:
    if (puVar1 != (undefined4 *)0x0) {
      FUN_00626cd0();
      return puVar1;
    }
    break;
  case 2:
    if (puVar1 != (undefined4 *)0x0) {
      FUN_00626da0();
      return puVar1;
    }
    break;
  case 3:
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 0;
      *puVar1 = &PTR_FUN_006a7d44;
      puVar1[2] = 3;
      return puVar1;
    }
    break;
  case 4:
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 0;
      *puVar1 = &PTR_FUN_006a7d80;
      puVar1[2] = 4;
      return puVar1;
    }
    break;
  case 5:
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 0;
      *puVar1 = &PTR_FUN_006a7c90;
      puVar1[2] = 5;
      return puVar1;
    }
    break;
  case 6:
    if (puVar1 != (undefined4 *)0x0) {
      FUN_00626f70();
      return puVar1;
    }
    break;
  case 7:
    if (puVar1 != (undefined4 *)0x0) {
      FUN_00626fd0();
      return puVar1;
    }
    break;
  case 8:
    if (puVar1 != (undefined4 *)0x0) {
      FUN_006331b0();
      return puVar1;
    }
    break;
  case 9:
    if (puVar1 != (undefined4 *)0x0) {
      FUN_00632890();
      return puVar1;
    }
    break;
  case 10:
    if (puVar1 != (undefined4 *)0x0) {
      FUN_006276b0();
      return puVar1;
    }
    break;
  case 0xb:
    if (puVar1 != (undefined4 *)0x0) {
      FUN_006276e0();
      return puVar1;
    }
    break;
  case 0xc:
    if (puVar1 != (undefined4 *)0x0) {
      FUN_00626e40();
      return puVar1;
    }
    break;
  case 0xd:
    if (puVar1 != (undefined4 *)0x0) {
      FUN_00626e70();
      return puVar1;
    }
    break;
  case 0xe:
    if (puVar1 != (undefined4 *)0x0) {
      FUN_00627100();
      return puVar1;
    }
    break;
  case 0xf:
    if (puVar1 != (undefined4 *)0x0) {
      FUN_00627140();
      return puVar1;
    }
    break;
  case 0x10:
    if (puVar1 != (undefined4 *)0x0) {
      FUN_006271f0();
      return puVar1;
    }
    break;
  case 0x11:
    if (puVar1 != (undefined4 *)0x0) {
      FUN_00631360();
      return puVar1;
    }
    break;
  case 0x12:
    if (puVar1 != (undefined4 *)0x0) {
      FUN_00630100();
      return puVar1;
    }
    break;
  case 0x13:
    if (puVar1 != (undefined4 *)0x0) {
      FUN_0062ea30();
      return puVar1;
    }
    break;
  case 0x14:
    if (puVar1 != (undefined4 *)0x0) {
      FUN_0062d1f0();
      return puVar1;
    }
    break;
  case 0x15:
    if (puVar1 != (undefined4 *)0x0) {
      FUN_0062c100();
    }
  }
  return puVar1;
}


// ==== 0x627b90 EAGLAnim::FnAnimFactory::New

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render med (hopper+ghidra) docs/re/render.md */

void EAGLAnim__FnAnimFactory__New(undefined4 param_1)

{
  _DAT_0070d360 = _malloc(4);
  if (_DAT_0070d360 == (int *)0x0) {
    _DAT_0070d360 = (int *)0x0;
  }
  else {
    *_DAT_0070d360 = (int)&PTR_FUN_006a7f5c;
  }
  DAT_0070d364 = _DAT_0070d360;
  (**(code **)(*_DAT_0070d360 + 4))(param_1);
  _DAT_0070d3c8 = (*(code *)PTR_FUN_006dfa9c)(1,"EAGLAnim::FnAnimFactory new");
  FUN_0061f540("AnimationBank",FUN_00627c20,NullUpdate_ret);
  return;
}


// ==== 0x627bf0 FUN_00627bf0

void FUN_00627bf0(void)

{
                    /* WARNING: Could not recover jumptable at 0x00627bf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_0070d364 + 0xc))();
  return;
}


// ==== 0x627c00 FUN_00627c00

undefined4 * __thiscall FUN_00627c00(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a7f5c;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x627c20 FUN_00627c20

void FUN_00627c20(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    (**(code **)(*DAT_0070d364 + 0x30))(*(undefined4 *)(*(int *)(param_1 + 0xc) + iVar1 * 4));
  }
  return;
}


// ==== 0x627c50 FUN_00627c50

int __thiscall FUN_00627c50(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  bool bVar8;
  
  iVar4 = 0;
  iVar5 = *(int *)(param_1 + 4) + -1;
  if (-1 < iVar5) {
    do {
      iVar7 = iVar4 + iVar5 >> 1;
      pbVar6 = *(byte **)(*(int *)(param_1 + 0x10) + iVar7 * 4);
      pbVar3 = param_2;
      do {
        bVar1 = *pbVar3;
        bVar8 = bVar1 < *pbVar6;
        if (bVar1 != *pbVar6) {
LAB_00627c98:
          iVar2 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_00627c9d;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar8 = bVar1 < pbVar6[1];
        if (bVar1 != pbVar6[1]) goto LAB_00627c98;
        pbVar3 = pbVar3 + 2;
        pbVar6 = pbVar6 + 2;
      } while (bVar1 != 0);
      iVar2 = 0;
LAB_00627c9d:
      if (iVar2 < 1) {
        if (-1 < iVar2) {
          return iVar7;
        }
        iVar5 = iVar7 + -1;
      }
      else {
        iVar4 = iVar7 + 1;
      }
    } while (iVar4 <= iVar5);
  }
  return -1;
}


// ==== 0x627cd0 FUN_00627cd0

int * FUN_00627cd0(short *param_1)

{
  short sVar1;
  int *piVar2;
  
  sVar1 = *param_1;
  if (sVar1 == 0xf) {
    piVar2 = (int *)(**(code **)(*DAT_0070d364 + 0x1c))(0xf);
    if (piVar2 != (int *)0x0) {
      FUN_00628eb0();
      *piVar2 = (int)&PTR_FUN_006a7e08;
      piVar2[4] = 0;
      *(undefined1 *)(piVar2 + 5) = 0;
      *(undefined1 *)((int)piVar2 + 0x15) = 0;
      piVar2[2] = 0xf;
      (**(code **)(*piVar2 + 0x3c))(param_1);
      return piVar2;
    }
    (**(code **)(iRam00000000 + 0x3c))(param_1);
    return (int *)0x0;
  }
  if (sVar1 != 0x16) {
    if (sVar1 != 0x17) {
      return (int *)0x0;
    }
    (**(code **)(*(int *)(param_1 + -0xc) + 0x3c))(param_1);
    return (int *)(param_1 + -0xc);
  }
  (**(code **)(*(int *)(param_1 + -0xc) + 0x3c))(param_1);
  return (int *)(param_1 + -0xc);
}


// ==== 0x627d60 FUN_00627d60

void __thiscall FUN_00627d60(int param_1,int param_2)

{
  FUN_00627cd0(*(undefined4 *)(*(int *)(param_1 + 0xc) + param_2 * 4));
  return;
}


// ==== 0x627d80 FUN_00627d80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00627d80(float *param_1,float param_2,float param_3,float param_4,float param_5,float param_6,
            float param_7,float param_8,float param_9,float param_10,float param_11)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  param_1[3] = 0.0;
  param_1[7] = 0.0;
  fVar4 = param_6 + param_6;
  fVar3 = param_7 + param_7;
  fVar2 = (param_5 + param_5) * param_8;
  fVar1 = (param_5 + param_5) * param_5;
  *param_1 = (_K_ONE - (fVar3 * param_7 + fVar4 * param_6)) * param_2;
  param_1[4] = (param_5 * fVar4 - fVar3 * param_8) * param_3;
  param_1[8] = (fVar3 * param_5 + param_8 * fVar4) * param_4;
  param_1[1] = (param_5 * fVar4 + fVar3 * param_8) * param_2;
  param_1[5] = (_K_ONE - (fVar3 * param_7 + fVar1)) * param_3;
  param_1[9] = (fVar3 * param_6 - fVar2) * param_4;
  param_1[2] = (fVar3 * param_5 - param_8 * fVar4) * param_2;
  param_1[6] = (fVar3 * param_6 + fVar2) * param_3;
  param_1[10] = (_K_ONE - (fVar4 * param_6 + fVar1)) * param_4;
  param_1[0xb] = 0.0;
  param_1[0xc] = param_9;
  param_1[0xd] = param_10;
  param_1[0xe] = param_11;
  param_1[0xf] = 1.0;
  return;
}


// ==== 0x627ea0 FUN_00627ea0

undefined4 __thiscall FUN_00627ea0(int param_1,int param_2)

{
  return CONCAT31((int3)(param_2 >> 0xd),
                  (*(uint *)(param_1 + (param_2 >> 5) * 4) & 1 << ((byte)param_2 & 0x1f)) != 0);
}


// ==== 0x627ec0 FUN_00627ec0

void __thiscall FUN_00627ec0(int param_1,int *param_2,int param_3,char param_4,int param_5)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  
  iVar9 = *(int *)(param_1 + 8);
  if (param_5 == 0) {
    if (param_2 == (int *)param_3) {
      iVar10 = 0;
      if (3 < iVar9) {
        piVar8 = (int *)(param_1 + 0xac);
        puVar4 = (undefined4 *)(param_3 + 0x4c);
        iVar5 = 2;
        do {
          iVar6 = piVar8[-0x1c];
          if (iVar10 < iVar6) {
            fVar1 = *(float *)(iVar6 * 0x30 + 0x10 + param_3);
            iVar6 = iVar6 * 0x30 + param_3;
            *(float *)(iVar6 + 0x10) = -(float)puVar4[-0xf];
            puVar4[-0xf] = -fVar1;
            fVar1 = *(float *)(iVar6 + 0x14);
            *(float *)(iVar6 + 0x14) = -(float)puVar4[-0xe];
            puVar4[-0xe] = -fVar1;
            uVar2 = *(undefined4 *)(iVar6 + 0x18);
            *(undefined4 *)(iVar6 + 0x18) = puVar4[-0xd];
            puVar4[-0xd] = uVar2;
            uVar2 = *(undefined4 *)(iVar6 + 0x1c);
            *(undefined4 *)(iVar6 + 0x1c) = puVar4[-0xc];
            puVar4[-0xc] = uVar2;
            uVar2 = *(undefined4 *)(iVar6 + 0x20);
            *(undefined4 *)(iVar6 + 0x20) = puVar4[-0xb];
            puVar4[-0xb] = uVar2;
            uVar2 = *(undefined4 *)(iVar6 + 0x24);
            *(undefined4 *)(iVar6 + 0x24) = puVar4[-10];
            puVar4[-10] = uVar2;
            fVar1 = *(float *)(iVar6 + 0x28);
            *(float *)(iVar6 + 0x28) = -(float)puVar4[-9];
LAB_00628661:
            puVar4[-9] = -fVar1;
          }
          else if (iVar6 == iVar10) {
            puVar4[-0xf] = -(float)puVar4[-0xf];
            puVar4[-0xe] = -(float)puVar4[-0xe];
            fVar1 = (float)puVar4[-9];
            goto LAB_00628661;
          }
          iVar6 = *piVar8;
          if (iVar5 + -1 < iVar6) {
            fVar1 = *(float *)(iVar6 * 0x30 + 0x10 + param_3);
            iVar6 = iVar6 * 0x30 + param_3;
            *(float *)(iVar6 + 0x10) = -(float)puVar4[-3];
            puVar4[-3] = -fVar1;
            fVar1 = *(float *)(iVar6 + 0x14);
            *(float *)(iVar6 + 0x14) = -(float)puVar4[-2];
            puVar4[-2] = -fVar1;
            uVar2 = *(undefined4 *)(iVar6 + 0x18);
            *(undefined4 *)(iVar6 + 0x18) = puVar4[-1];
            puVar4[-1] = uVar2;
            uVar2 = *(undefined4 *)(iVar6 + 0x1c);
            *(undefined4 *)(iVar6 + 0x1c) = *puVar4;
            *puVar4 = uVar2;
            uVar2 = *(undefined4 *)(iVar6 + 0x20);
            *(undefined4 *)(iVar6 + 0x20) = puVar4[1];
            puVar4[1] = uVar2;
            uVar2 = *(undefined4 *)(iVar6 + 0x24);
            *(undefined4 *)(iVar6 + 0x24) = puVar4[2];
            puVar4[2] = uVar2;
            fVar1 = *(float *)(iVar6 + 0x28);
            *(float *)(iVar6 + 0x28) = -(float)puVar4[3];
LAB_006286ec:
            puVar4[3] = -fVar1;
          }
          else if (iVar6 == iVar5 + -1) {
            puVar4[-3] = -(float)puVar4[-3];
            puVar4[-2] = -(float)puVar4[-2];
            fVar1 = (float)puVar4[3];
            goto LAB_006286ec;
          }
          iVar6 = piVar8[0x1c];
          if (iVar5 < iVar6) {
            fVar1 = *(float *)(iVar6 * 0x30 + 0x10 + param_3);
            iVar6 = iVar6 * 0x30 + param_3;
            *(float *)(iVar6 + 0x10) = -(float)puVar4[9];
            puVar4[9] = -fVar1;
            fVar1 = *(float *)(iVar6 + 0x14);
            *(float *)(iVar6 + 0x14) = -(float)puVar4[10];
            puVar4[10] = -fVar1;
            uVar2 = *(undefined4 *)(iVar6 + 0x18);
            *(undefined4 *)(iVar6 + 0x18) = puVar4[0xb];
            puVar4[0xb] = uVar2;
            uVar2 = *(undefined4 *)(iVar6 + 0x1c);
            *(undefined4 *)(iVar6 + 0x1c) = puVar4[0xc];
            puVar4[0xc] = uVar2;
            uVar2 = *(undefined4 *)(iVar6 + 0x20);
            *(undefined4 *)(iVar6 + 0x20) = puVar4[0xd];
            puVar4[0xd] = uVar2;
            uVar2 = *(undefined4 *)(iVar6 + 0x24);
            *(undefined4 *)(iVar6 + 0x24) = puVar4[0xe];
            puVar4[0xe] = uVar2;
            fVar1 = *(float *)(iVar6 + 0x28);
            *(float *)(iVar6 + 0x28) = -(float)puVar4[0xf];
LAB_00628777:
            puVar4[0xf] = -fVar1;
          }
          else if (iVar6 == iVar5) {
            puVar4[9] = -(float)puVar4[9];
            puVar4[10] = -(float)puVar4[10];
            fVar1 = (float)puVar4[0xf];
            goto LAB_00628777;
          }
          iVar6 = piVar8[0x38];
          if (iVar5 + 1 < iVar6) {
            fVar1 = *(float *)(iVar6 * 0x30 + 0x10 + param_3);
            iVar6 = iVar6 * 0x30 + param_3;
            *(float *)(iVar6 + 0x10) = -(float)puVar4[0x15];
            puVar4[0x15] = -fVar1;
            fVar1 = *(float *)(iVar6 + 0x14);
            *(float *)(iVar6 + 0x14) = -(float)puVar4[0x16];
            puVar4[0x16] = -fVar1;
            uVar2 = *(undefined4 *)(iVar6 + 0x18);
            *(undefined4 *)(iVar6 + 0x18) = puVar4[0x17];
            puVar4[0x17] = uVar2;
            uVar2 = *(undefined4 *)(iVar6 + 0x1c);
            *(undefined4 *)(iVar6 + 0x1c) = puVar4[0x18];
            puVar4[0x18] = uVar2;
            uVar2 = *(undefined4 *)(iVar6 + 0x20);
            *(undefined4 *)(iVar6 + 0x20) = puVar4[0x19];
            puVar4[0x19] = uVar2;
            uVar2 = *(undefined4 *)(iVar6 + 0x24);
            *(undefined4 *)(iVar6 + 0x24) = puVar4[0x1a];
            puVar4[0x1a] = uVar2;
            fVar1 = *(float *)(iVar6 + 0x28);
            *(float *)(iVar6 + 0x28) = -(float)puVar4[0x1b];
LAB_00628808:
            puVar4[0x1b] = -fVar1;
          }
          else if (iVar6 == iVar5 + 1) {
            puVar4[0x15] = -(float)puVar4[0x15];
            puVar4[0x16] = -(float)puVar4[0x16];
            fVar1 = (float)puVar4[0x1b];
            goto LAB_00628808;
          }
          piVar8 = piVar8 + 0x70;
          iVar6 = iVar5 + 5;
          iVar10 = iVar10 + 4;
          puVar4 = puVar4 + 0x30;
          iVar5 = iVar5 + 4;
        } while (iVar6 < iVar9);
      }
      if (iVar10 < iVar9) {
        puVar4 = (undefined4 *)(iVar10 * 0x30 + 0x1c + param_3);
        piVar8 = (int *)(iVar10 * 0x70 + 0x3c + param_1);
        do {
          iVar5 = *piVar8;
          if (iVar10 < iVar5) {
            fVar1 = *(float *)(iVar5 * 0x30 + 0x10 + param_3);
            iVar5 = iVar5 * 0x30 + param_3;
            *(float *)(iVar5 + 0x10) = -(float)puVar4[-3];
            puVar4[-3] = -fVar1;
            fVar1 = *(float *)(iVar5 + 0x14);
            *(float *)(iVar5 + 0x14) = -(float)puVar4[-2];
            puVar4[-2] = -fVar1;
            uVar2 = *(undefined4 *)(iVar5 + 0x18);
            *(undefined4 *)(iVar5 + 0x18) = puVar4[-1];
            puVar4[-1] = uVar2;
            uVar2 = *(undefined4 *)(iVar5 + 0x1c);
            *(undefined4 *)(iVar5 + 0x1c) = *puVar4;
            *puVar4 = uVar2;
            uVar2 = *(undefined4 *)(iVar5 + 0x20);
            *(undefined4 *)(iVar5 + 0x20) = puVar4[1];
            puVar4[1] = uVar2;
            uVar2 = *(undefined4 *)(iVar5 + 0x24);
            *(undefined4 *)(iVar5 + 0x24) = puVar4[2];
            puVar4[2] = uVar2;
            fVar1 = *(float *)(iVar5 + 0x28);
            *(float *)(iVar5 + 0x28) = -(float)puVar4[3];
LAB_006288cf:
            puVar4[3] = -fVar1;
          }
          else if (iVar5 == iVar10) {
            puVar4[-3] = -(float)puVar4[-3];
            puVar4[-2] = -(float)puVar4[-2];
            fVar1 = (float)puVar4[3];
            goto LAB_006288cf;
          }
          iVar10 = iVar10 + 1;
          piVar8 = piVar8 + 0x1c;
          puVar4 = puVar4 + 0xc;
        } while (iVar10 < iVar9);
      }
    }
    else {
      iVar10 = 0;
      if (3 < iVar9) {
        piVar8 = (int *)(param_1 + 0xac);
        iVar5 = 3;
        puVar4 = (undefined4 *)((int)param_2 + 0x38);
        do {
          iVar6 = piVar8[-0x1c] * 0x30;
          *(undefined4 *)(iVar6 + param_3) = puVar4[-0xe];
          *(undefined4 *)(iVar6 + 4 + param_3) = puVar4[-0xd];
          *(undefined4 *)(iVar6 + 8 + param_3) = puVar4[-0xc];
          iVar6 = iVar6 + param_3;
          *(float *)(iVar6 + 0x10) = -(float)puVar4[-10];
          *(float *)(iVar6 + 0x14) = -(float)puVar4[-9];
          *(undefined4 *)(iVar6 + 0x18) = puVar4[-8];
          *(undefined4 *)(iVar6 + 0x1c) = puVar4[-7];
          *(undefined4 *)(iVar6 + 0x20) = puVar4[-6];
          *(undefined4 *)(iVar6 + 0x24) = puVar4[-5];
          *(float *)(iVar6 + 0x28) = -(float)puVar4[-4];
          iVar6 = *piVar8 * 0x30;
          *(undefined4 *)(iVar6 + param_3) = puVar4[-2];
          *(undefined4 *)(iVar6 + 4 + param_3) = puVar4[-1];
          iVar6 = iVar6 + param_3;
          *(undefined4 *)(iVar6 + 8) = *puVar4;
          *(float *)(iVar6 + 0x10) = -(float)puVar4[2];
          *(float *)(iVar6 + 0x14) = -(float)puVar4[3];
          *(undefined4 *)(iVar6 + 0x18) = puVar4[4];
          *(undefined4 *)(iVar6 + 0x1c) = puVar4[5];
          *(undefined4 *)(iVar6 + 0x20) = puVar4[6];
          *(undefined4 *)(iVar6 + 0x24) = puVar4[7];
          *(float *)(iVar6 + 0x28) = -(float)puVar4[8];
          puVar7 = (undefined4 *)(piVar8[0x1c] * 0x30 + param_3);
          *puVar7 = puVar4[10];
          puVar7[1] = puVar4[0xb];
          puVar7[2] = puVar4[0xc];
          puVar7[4] = -(float)puVar4[0xe];
          puVar7[5] = -(float)puVar4[0xf];
          puVar7[6] = puVar4[0x10];
          puVar7[7] = puVar4[0x11];
          puVar7[8] = puVar4[0x12];
          puVar7[9] = puVar4[0x13];
          puVar7[10] = -(float)puVar4[0x14];
          puVar7 = (undefined4 *)(piVar8[0x38] * 0x30 + param_3);
          *puVar7 = puVar4[0x16];
          puVar7[1] = puVar4[0x17];
          puVar7[2] = puVar4[0x18];
          iVar5 = iVar5 + 4;
          puVar7[4] = -(float)puVar4[0x1a];
          iVar10 = iVar10 + 4;
          piVar8 = piVar8 + 0x70;
          puVar7[5] = -(float)puVar4[0x1b];
          puVar7[6] = puVar4[0x1c];
          puVar7[7] = puVar4[0x1d];
          puVar7[8] = puVar4[0x1e];
          puVar7[9] = puVar4[0x1f];
          puVar7[10] = -(float)puVar4[0x20];
          puVar4 = puVar4 + 0x30;
        } while (iVar5 < iVar9);
      }
      if (iVar10 < iVar9) {
        piVar8 = (int *)(iVar10 * 0x70 + 0x3c + param_1);
        iVar9 = iVar9 - iVar10;
        puVar4 = (undefined4 *)(iVar10 * 0x30 + 8 + (int)param_2);
        do {
          puVar7 = (undefined4 *)(*piVar8 * 0x30 + param_3);
          *puVar7 = puVar4[-2];
          puVar7[1] = puVar4[-1];
          puVar7[2] = *puVar4;
          puVar7[4] = -(float)puVar4[2];
          piVar8 = piVar8 + 0x1c;
          iVar9 = iVar9 + -1;
          puVar7[5] = -(float)puVar4[3];
          puVar7[6] = puVar4[4];
          puVar7[7] = puVar4[5];
          puVar7[8] = puVar4[6];
          puVar7[9] = puVar4[7];
          puVar7[10] = -(float)puVar4[8];
          puVar4 = puVar4 + 0xc;
        } while (iVar9 != 0);
      }
    }
    if (param_4 == '\0') {
      fVar1 = *(float *)(param_3 + 0x18);
      uVar2 = *(undefined4 *)(param_3 + 0x1c);
      *(float *)(param_3 + 0x18) = -*(float *)(param_3 + 0x10);
      *(float *)(param_3 + 0x10) = fVar1;
      *(float *)(param_3 + 0x1c) = -*(float *)(param_3 + 0x14);
      *(undefined4 *)(param_3 + 0x14) = uVar2;
      *(float *)(param_3 + 0x20) = -*(float *)(param_3 + 0x20);
      *(float *)(param_3 + 0x28) = -*(float *)(param_3 + 0x28);
    }
  }
  else {
    iVar10 = 0;
    if (param_2 == (int *)param_3) {
      if (3 < iVar9) {
        param_2 = (int *)(param_1 + 0xac);
        puVar4 = (undefined4 *)(param_3 + 0x4c);
        iVar5 = 2;
        do {
          if ((*(uint *)(param_5 + (iVar10 >> 5) * 4) & 1 << ((byte)iVar10 & 0x1f)) != 0) {
            iVar6 = param_2[-0x1c];
            if (iVar10 < iVar6) {
              fVar1 = *(float *)(iVar6 * 0x30 + 0x10 + param_3);
              iVar6 = iVar6 * 0x30 + param_3;
              *(float *)(iVar6 + 0x10) = -(float)puVar4[-0xf];
              puVar4[-0xf] = -fVar1;
              fVar1 = *(float *)(iVar6 + 0x14);
              *(float *)(iVar6 + 0x14) = -(float)puVar4[-0xe];
              puVar4[-0xe] = -fVar1;
              uVar2 = *(undefined4 *)(iVar6 + 0x18);
              *(undefined4 *)(iVar6 + 0x18) = puVar4[-0xd];
              puVar4[-0xd] = uVar2;
              uVar2 = *(undefined4 *)(iVar6 + 0x1c);
              *(undefined4 *)(iVar6 + 0x1c) = puVar4[-0xc];
              puVar4[-0xc] = uVar2;
              uVar2 = *(undefined4 *)(iVar6 + 0x20);
              *(undefined4 *)(iVar6 + 0x20) = puVar4[-0xb];
              puVar4[-0xb] = uVar2;
              uVar2 = *(undefined4 *)(iVar6 + 0x24);
              *(undefined4 *)(iVar6 + 0x24) = puVar4[-10];
              puVar4[-10] = uVar2;
              fVar1 = *(float *)(iVar6 + 0x28);
              *(float *)(iVar6 + 0x28) = -(float)puVar4[-9];
            }
            else {
              if (iVar6 != iVar10) goto LAB_00627fbd;
              puVar4[-0xf] = -(float)puVar4[-0xf];
              puVar4[-0xe] = -(float)puVar4[-0xe];
              fVar1 = (float)puVar4[-9];
            }
            puVar4[-9] = -fVar1;
          }
LAB_00627fbd:
          iVar6 = iVar5 + -1;
          if ((*(uint *)(param_5 + (iVar6 >> 5) * 4) & 1 << ((byte)iVar6 & 0x1f)) != 0) {
            iVar3 = *param_2;
            if (iVar6 < iVar3) {
              fVar1 = *(float *)(iVar3 * 0x30 + 0x10 + param_3);
              iVar6 = iVar3 * 0x30 + param_3;
              *(float *)(iVar6 + 0x10) = -(float)puVar4[-3];
              puVar4[-3] = -fVar1;
              fVar1 = *(float *)(iVar6 + 0x14);
              *(float *)(iVar6 + 0x14) = -(float)puVar4[-2];
              puVar4[-2] = -fVar1;
              uVar2 = *(undefined4 *)(iVar6 + 0x18);
              *(undefined4 *)(iVar6 + 0x18) = puVar4[-1];
              puVar4[-1] = uVar2;
              uVar2 = *(undefined4 *)(iVar6 + 0x1c);
              *(undefined4 *)(iVar6 + 0x1c) = *puVar4;
              *puVar4 = uVar2;
              uVar2 = *(undefined4 *)(iVar6 + 0x20);
              *(undefined4 *)(iVar6 + 0x20) = puVar4[1];
              puVar4[1] = uVar2;
              uVar2 = *(undefined4 *)(iVar6 + 0x24);
              *(undefined4 *)(iVar6 + 0x24) = puVar4[2];
              puVar4[2] = uVar2;
              fVar1 = *(float *)(iVar6 + 0x28);
              *(float *)(iVar6 + 0x28) = -(float)puVar4[3];
            }
            else {
              if (iVar3 != iVar6) goto LAB_00628066;
              puVar4[-3] = -(float)puVar4[-3];
              puVar4[-2] = -(float)puVar4[-2];
              fVar1 = (float)puVar4[3];
            }
            puVar4[3] = -fVar1;
          }
LAB_00628066:
          if ((*(uint *)(param_5 + (iVar5 >> 5) * 4) & 1 << ((byte)iVar5 & 0x1f)) != 0) {
            iVar6 = param_2[0x1c];
            if (iVar5 < iVar6) {
              fVar1 = *(float *)(iVar6 * 0x30 + 0x10 + param_3);
              iVar6 = iVar6 * 0x30 + param_3;
              *(float *)(iVar6 + 0x10) = -(float)puVar4[9];
              puVar4[9] = -fVar1;
              fVar1 = *(float *)(iVar6 + 0x14);
              *(float *)(iVar6 + 0x14) = -(float)puVar4[10];
              puVar4[10] = -fVar1;
              uVar2 = *(undefined4 *)(iVar6 + 0x18);
              *(undefined4 *)(iVar6 + 0x18) = puVar4[0xb];
              puVar4[0xb] = uVar2;
              uVar2 = *(undefined4 *)(iVar6 + 0x1c);
              *(undefined4 *)(iVar6 + 0x1c) = puVar4[0xc];
              puVar4[0xc] = uVar2;
              uVar2 = *(undefined4 *)(iVar6 + 0x20);
              *(undefined4 *)(iVar6 + 0x20) = puVar4[0xd];
              puVar4[0xd] = uVar2;
              uVar2 = *(undefined4 *)(iVar6 + 0x24);
              *(undefined4 *)(iVar6 + 0x24) = puVar4[0xe];
              puVar4[0xe] = uVar2;
              fVar1 = *(float *)(iVar6 + 0x28);
              *(float *)(iVar6 + 0x28) = -(float)puVar4[0xf];
            }
            else {
              if (iVar6 != iVar5) goto LAB_0062810f;
              puVar4[9] = -(float)puVar4[9];
              puVar4[10] = -(float)puVar4[10];
              fVar1 = (float)puVar4[0xf];
            }
            puVar4[0xf] = -fVar1;
          }
LAB_0062810f:
          iVar6 = iVar5 + 1;
          if ((*(uint *)(param_5 + (iVar6 >> 5) * 4) & 1 << ((byte)iVar6 & 0x1f)) != 0) {
            iVar3 = param_2[0x38];
            if (iVar6 < iVar3) {
              fVar1 = *(float *)(iVar3 * 0x30 + 0x10 + param_3);
              iVar6 = iVar3 * 0x30 + param_3;
              *(float *)(iVar6 + 0x10) = -(float)puVar4[0x15];
              puVar4[0x15] = -fVar1;
              fVar1 = *(float *)(iVar6 + 0x14);
              *(float *)(iVar6 + 0x14) = -(float)puVar4[0x16];
              puVar4[0x16] = -fVar1;
              uVar2 = *(undefined4 *)(iVar6 + 0x18);
              *(undefined4 *)(iVar6 + 0x18) = puVar4[0x17];
              puVar4[0x17] = uVar2;
              uVar2 = *(undefined4 *)(iVar6 + 0x1c);
              *(undefined4 *)(iVar6 + 0x1c) = puVar4[0x18];
              puVar4[0x18] = uVar2;
              uVar2 = *(undefined4 *)(iVar6 + 0x20);
              *(undefined4 *)(iVar6 + 0x20) = puVar4[0x19];
              puVar4[0x19] = uVar2;
              uVar2 = *(undefined4 *)(iVar6 + 0x24);
              *(undefined4 *)(iVar6 + 0x24) = puVar4[0x1a];
              puVar4[0x1a] = uVar2;
              fVar1 = *(float *)(iVar6 + 0x28);
              *(float *)(iVar6 + 0x28) = -(float)puVar4[0x1b];
            }
            else {
              if (iVar3 != iVar6) goto LAB_006281be;
              puVar4[0x15] = -(float)puVar4[0x15];
              puVar4[0x16] = -(float)puVar4[0x16];
              fVar1 = (float)puVar4[0x1b];
            }
            puVar4[0x1b] = -fVar1;
          }
LAB_006281be:
          param_2 = param_2 + 0x70;
          iVar6 = iVar5 + 5;
          iVar10 = iVar10 + 4;
          puVar4 = puVar4 + 0x30;
          iVar5 = iVar5 + 4;
        } while (iVar6 < iVar9);
      }
      if (iVar10 < iVar9) {
        puVar4 = (undefined4 *)(iVar10 * 0x30 + 0x1c + param_3);
        piVar8 = (int *)(iVar10 * 0x70 + 0x3c + param_1);
        do {
          if ((*(uint *)(param_5 + (iVar10 >> 5) * 4) & 1 << ((byte)iVar10 & 0x1f)) != 0) {
            iVar5 = *piVar8;
            if (iVar10 < iVar5) {
              fVar1 = *(float *)(iVar5 * 0x30 + 0x10 + param_3);
              iVar5 = iVar5 * 0x30 + param_3;
              *(float *)(iVar5 + 0x10) = -(float)puVar4[-3];
              puVar4[-3] = -fVar1;
              fVar1 = *(float *)(iVar5 + 0x14);
              *(float *)(iVar5 + 0x14) = -(float)puVar4[-2];
              puVar4[-2] = -fVar1;
              uVar2 = *(undefined4 *)(iVar5 + 0x18);
              *(undefined4 *)(iVar5 + 0x18) = puVar4[-1];
              puVar4[-1] = uVar2;
              uVar2 = *(undefined4 *)(iVar5 + 0x1c);
              *(undefined4 *)(iVar5 + 0x1c) = *puVar4;
              *puVar4 = uVar2;
              uVar2 = *(undefined4 *)(iVar5 + 0x20);
              *(undefined4 *)(iVar5 + 0x20) = puVar4[1];
              puVar4[1] = uVar2;
              uVar2 = *(undefined4 *)(iVar5 + 0x24);
              *(undefined4 *)(iVar5 + 0x24) = puVar4[2];
              puVar4[2] = uVar2;
              fVar1 = *(float *)(iVar5 + 0x28);
              *(float *)(iVar5 + 0x28) = -(float)puVar4[3];
            }
            else {
              if (iVar5 != iVar10) goto LAB_006282b2;
              puVar4[-3] = -(float)puVar4[-3];
              puVar4[-2] = -(float)puVar4[-2];
              fVar1 = (float)puVar4[3];
            }
            puVar4[3] = -fVar1;
          }
LAB_006282b2:
          iVar10 = iVar10 + 1;
          piVar8 = piVar8 + 0x1c;
          puVar4 = puVar4 + 0xc;
        } while (iVar10 < iVar9);
      }
    }
    else {
      if (3 < iVar9) {
        piVar8 = (int *)(param_1 + 0xac);
        puVar4 = (undefined4 *)((int)param_2 + 0x38);
        iVar5 = 2;
        do {
          if ((*(uint *)(param_5 + (iVar10 >> 5) * 4) & 1 << ((byte)iVar10 & 0x1f)) != 0) {
            puVar7 = (undefined4 *)(piVar8[-0x1c] * 0x30 + param_3);
            *puVar7 = puVar4[-0xe];
            puVar7[1] = puVar4[-0xd];
            puVar7[2] = puVar4[-0xc];
            puVar7[4] = -(float)puVar4[-10];
            puVar7[5] = -(float)puVar4[-9];
            puVar7[6] = puVar4[-8];
            puVar7[7] = puVar4[-7];
            puVar7[8] = puVar4[-6];
            puVar7[9] = puVar4[-5];
            puVar7[10] = -(float)puVar4[-4];
          }
          if ((*(uint *)(param_5 + (iVar5 + -1 >> 5) * 4) & 1 << ((byte)(iVar5 + -1) & 0x1f)) != 0)
          {
            puVar7 = (undefined4 *)(*piVar8 * 0x30 + param_3);
            *puVar7 = puVar4[-2];
            puVar7[1] = puVar4[-1];
            puVar7[2] = *puVar4;
            puVar7[4] = -(float)puVar4[2];
            puVar7[5] = -(float)puVar4[3];
            puVar7[6] = puVar4[4];
            puVar7[7] = puVar4[5];
            puVar7[8] = puVar4[6];
            puVar7[9] = puVar4[7];
            puVar7[10] = -(float)puVar4[8];
          }
          if ((*(uint *)(param_5 + (iVar5 >> 5) * 4) & 1 << ((byte)iVar5 & 0x1f)) != 0) {
            puVar7 = (undefined4 *)(piVar8[0x1c] * 0x30 + param_3);
            *puVar7 = puVar4[10];
            puVar7[1] = puVar4[0xb];
            puVar7[2] = puVar4[0xc];
            puVar7[4] = -(float)puVar4[0xe];
            puVar7[5] = -(float)puVar4[0xf];
            puVar7[6] = puVar4[0x10];
            puVar7[7] = puVar4[0x11];
            puVar7[8] = puVar4[0x12];
            puVar7[9] = puVar4[0x13];
            puVar7[10] = -(float)puVar4[0x14];
          }
          if ((*(uint *)(param_5 + (iVar5 + 1 >> 5) * 4) & 1 << ((byte)(iVar5 + 1) & 0x1f)) != 0) {
            puVar7 = (undefined4 *)(piVar8[0x38] * 0x30 + param_3);
            *puVar7 = puVar4[0x16];
            puVar7[1] = puVar4[0x17];
            puVar7[2] = puVar4[0x18];
            puVar7[4] = -(float)puVar4[0x1a];
            puVar7[5] = -(float)puVar4[0x1b];
            puVar7[6] = puVar4[0x1c];
            puVar7[7] = puVar4[0x1d];
            puVar7[8] = puVar4[0x1e];
            puVar7[9] = puVar4[0x1f];
            puVar7[10] = -(float)puVar4[0x20];
          }
          iVar6 = iVar5 + 5;
          iVar10 = iVar10 + 4;
          puVar4 = puVar4 + 0x30;
          piVar8 = piVar8 + 0x70;
          iVar5 = iVar5 + 4;
        } while (iVar6 < iVar9);
      }
      if (iVar10 < iVar9) {
        puVar4 = (undefined4 *)(iVar10 * 0x30 + 8 + (int)param_2);
        piVar8 = (int *)(iVar10 * 0x70 + 0x3c + param_1);
        do {
          if ((*(uint *)(param_5 + (iVar10 >> 5) * 4) & 1 << ((byte)iVar10 & 0x1f)) != 0) {
            puVar7 = (undefined4 *)(*piVar8 * 0x30 + param_3);
            *puVar7 = puVar4[-2];
            puVar7[1] = puVar4[-1];
            puVar7[2] = *puVar4;
            puVar7[4] = -(float)puVar4[2];
            puVar7[5] = -(float)puVar4[3];
            puVar7[6] = puVar4[4];
            puVar7[7] = puVar4[5];
            puVar7[8] = puVar4[6];
            puVar7[9] = puVar4[7];
            puVar7[10] = -(float)puVar4[8];
          }
          iVar10 = iVar10 + 1;
          puVar4 = puVar4 + 0xc;
          piVar8 = piVar8 + 0x1c;
        } while (iVar10 < iVar9);
      }
    }
    if (param_4 == '\0') {
      fVar1 = *(float *)(param_3 + 0x18);
      uVar2 = *(undefined4 *)(param_3 + 0x1c);
      *(float *)(param_3 + 0x18) = -*(float *)(param_3 + 0x10);
      *(float *)(param_3 + 0x1c) = -*(float *)(param_3 + 0x14);
      *(float *)(param_3 + 0x20) = -*(float *)(param_3 + 0x20);
      *(float *)(param_3 + 0x10) = fVar1;
      *(float *)(param_3 + 0x28) = -*(float *)(param_3 + 0x28);
      *(undefined4 *)(param_3 + 0x14) = uVar2;
      return;
    }
  }
  return;
}


// ==== 0x628b30 FUN_00628b30

void __thiscall FUN_00628b30(int param_1,int param_2,float *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  float *pfVar5;
  
  iVar3 = *(int *)(param_1 + 8);
  if (param_4 == 0) {
    if (0 < iVar3) {
      puVar4 = (undefined4 *)(param_2 + 0x24);
      piVar2 = (int *)(param_1 + 0x1c);
      pfVar5 = param_3;
      do {
        FUN_00627d80(puVar4[-9],puVar4[-8],puVar4[-7],puVar4[-5],puVar4[-4],puVar4[-3],puVar4[-2],
                     puVar4[-1],*puVar4,puVar4[1]);
        *pfVar5 = (float)puVar4[-6] * *pfVar5;
        pfVar5[4] = pfVar5[4] * (float)puVar4[-6];
        pfVar5[8] = (float)puVar4[-6] * pfVar5[8];
        if (-1 < *piVar2) {
          (*(code *)PTR_FUN_006e58dc)(pfVar5,param_3 + *piVar2 * 0x10,pfVar5);
        }
        puVar4 = puVar4 + 0xc;
        piVar2 = piVar2 + 0x1c;
        pfVar5 = pfVar5 + 0x10;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  else {
    iVar1 = 0;
    if (0 < iVar3) {
      puVar4 = (undefined4 *)(param_2 + 0x24);
      piVar2 = (int *)(param_1 + 0x1c);
      pfVar5 = param_3;
      do {
        if ((*(uint *)(param_4 + (iVar1 >> 5) * 4) & 1 << ((byte)iVar1 & 0x1f)) != 0) {
          FUN_00627d80(puVar4[-9],puVar4[-8],puVar4[-7],puVar4[-5],puVar4[-4],puVar4[-3],puVar4[-2],
                       puVar4[-1],*puVar4,puVar4[1]);
          *pfVar5 = *pfVar5 * (float)puVar4[-6];
          pfVar5[4] = pfVar5[4] * (float)puVar4[-6];
          pfVar5[8] = (float)puVar4[-6] * pfVar5[8];
          if (-1 < *piVar2) {
            (*(code *)PTR_FUN_006e58dc)(pfVar5,param_3 + *piVar2 * 0x10,pfVar5);
          }
        }
        puVar4 = puVar4 + 0xc;
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 0x1c;
        pfVar5 = pfVar5 + 0x10;
      } while (iVar1 < iVar3);
      return;
    }
  }
  return;
}


// ==== 0x628c90 FUN_00628c90

void __thiscall FUN_00628c90(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 8);
  if (param_3 == 0) {
    if (*(int *)(param_1 + 0xc) == 0) {
      if (0 < iVar3) {
        puVar1 = (undefined4 *)(param_1 + 0x18);
        do {
          *param_2 = puVar1[-2];
          param_2[1] = puVar1[-1];
          param_2[2] = *puVar1;
          param_2[3] = 0x3f800000;
          param_2[4] = puVar1[2];
          param_2[5] = puVar1[3];
          param_2[6] = puVar1[4];
          param_2[7] = puVar1[5];
          param_2[8] = puVar1[6];
          param_2[9] = puVar1[7];
          param_2[10] = puVar1[8];
          param_2[0xb] = 0x3f800000;
          param_2 = param_2 + 0xc;
          puVar1 = puVar1 + 0x1c;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
    else {
      iVar2 = 0;
      if (0 < iVar3) {
        puVar1 = (undefined4 *)(param_1 + 0x18);
        do {
          *param_2 = puVar1[-2];
          param_2[1] = puVar1[-1];
          param_2[2] = *puVar1;
          param_2[3] = *(undefined4 *)(*(int *)(param_1 + 0xc) + iVar2 * 4);
          param_2[4] = puVar1[2];
          param_2[5] = puVar1[3];
          param_2[6] = puVar1[4];
          param_2[7] = puVar1[5];
          param_2[8] = puVar1[6];
          param_2[9] = puVar1[7];
          param_2[10] = puVar1[8];
          param_2[0xb] = 0x3f800000;
          param_2 = param_2 + 0xc;
          iVar2 = iVar2 + 1;
          puVar1 = puVar1 + 0x1c;
        } while (iVar2 < iVar3);
        return;
      }
    }
  }
  else {
    iVar2 = 0;
    if (*(int *)(param_1 + 0xc) == 0) {
      if (0 < iVar3) {
        puVar1 = (undefined4 *)(param_1 + 0x18);
        do {
          if ((*(uint *)(param_3 + (iVar2 >> 5) * 4) & 1 << ((byte)iVar2 & 0x1f)) != 0) {
            *param_2 = puVar1[-2];
            param_2[1] = puVar1[-1];
            param_2[2] = *puVar1;
            param_2[3] = 0x3f800000;
            param_2[4] = puVar1[2];
            param_2[5] = puVar1[3];
            param_2[6] = puVar1[4];
            param_2[7] = puVar1[5];
            param_2[8] = puVar1[6];
            param_2[9] = puVar1[7];
            param_2[10] = puVar1[8];
            param_2[0xb] = 0x3f800000;
          }
          param_2 = param_2 + 0xc;
          iVar2 = iVar2 + 1;
          puVar1 = puVar1 + 0x1c;
        } while (iVar2 < iVar3);
        return;
      }
    }
    else if (0 < iVar3) {
      puVar1 = (undefined4 *)(param_1 + 0x18);
      do {
        if ((*(uint *)(param_3 + (iVar2 >> 5) * 4) & 1 << ((byte)iVar2 & 0x1f)) != 0) {
          *param_2 = puVar1[-2];
          param_2[1] = puVar1[-1];
          param_2[2] = *puVar1;
          param_2[3] = *(undefined4 *)(*(int *)(param_1 + 0xc) + iVar2 * 4);
          param_2[4] = puVar1[2];
          param_2[5] = puVar1[3];
          param_2[6] = puVar1[4];
          param_2[7] = puVar1[5];
          param_2[8] = puVar1[6];
          param_2[9] = puVar1[7];
          param_2[10] = puVar1[8];
          param_2[0xb] = 0x3f800000;
        }
        param_2 = param_2 + 0xc;
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 0x1c;
      } while (iVar2 < iVar3);
      return;
    }
  }
  return;
}


// ==== 0x628eb0 FUN_00628eb0

void __fastcall FUN_00628eb0(undefined4 *param_1)

{
  param_1[1] = 0;
  *param_1 = &PTR_FUN_006a8010;
  param_1[3] = 0;
  return;
}


// ==== 0x628ed0 FUN_00628ed0

void __fastcall FUN_00628ed0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a7a94;
  return;
}


// ==== 0x628ee0 FUN_00628ee0

void __thiscall FUN_00628ee0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}


// ==== 0x628ef0 FUN_00628ef0

undefined4 * __thiscall FUN_00628ef0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a7a94;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x628f10 FUN_00628f10

void __thiscall FUN_00628f10(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0062c010(param_3,param_4,*(undefined1 *)(param_1 + 0x10),0);
  return;
}


// ==== 0x628f30 FUN_00628f30

undefined4 __thiscall
FUN_00628f30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0062c010(param_2,param_3,*(undefined1 *)(param_1 + 0x10),param_4);
  return 1;
}


// ==== 0x628f60 FUN_00628f60

void __thiscall
FUN_00628f60(int param_1,float param_2,float param_3,int *param_4,float *param_5,int param_6,
            undefined4 param_7)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  int *piVar6;
  
  iVar1 = *(int *)(param_1 + 4);
  param_1 = param_1 + 8;
  if (param_2 < *param_5) {
    iVar3 = *param_4;
    if (-1 < iVar3) {
      pfVar4 = (float *)(iVar3 * 0x10 + 4 + param_1);
      do {
        if (*pfVar4 < param_2 != (*pfVar4 == param_2)) break;
        iVar3 = iVar3 + -1;
        pfVar4 = pfVar4 + -4;
      } while (-1 < iVar3);
    }
    *param_4 = iVar3 + 1;
  }
  iVar3 = *param_4;
  if (3 < iVar1 - iVar3) {
    iVar5 = iVar3 + 3;
    pfVar4 = (float *)(iVar3 * 0x10 + 0x14 + param_1);
    do {
      if (param_2 < pfVar4[-4]) goto LAB_00629035;
      if (param_2 < *pfVar4) {
        iVar3 = iVar3 + 1;
        goto LAB_00629035;
      }
      if (param_2 < pfVar4[4]) {
        iVar3 = iVar3 + 2;
        goto LAB_00629035;
      }
      if (param_2 < pfVar4[8]) {
        iVar3 = iVar3 + 3;
        goto LAB_00629035;
      }
      iVar5 = iVar5 + 4;
      iVar3 = iVar3 + 4;
      pfVar4 = pfVar4 + 0x10;
    } while (iVar5 < iVar1);
  }
  if (iVar3 < iVar1) {
    pfVar4 = (float *)(iVar3 * 0x10 + 4 + param_1);
    do {
      if (param_2 < *pfVar4) break;
      iVar3 = iVar3 + 1;
      pfVar4 = pfVar4 + 4;
    } while (iVar3 < iVar1);
  }
LAB_00629035:
  *param_4 = iVar3;
  if (param_2 == param_3) {
    if (iVar1 <= iVar3) {
      *param_4 = iVar1 + -1;
    }
    iVar3 = *param_4;
    if (-1 < iVar3) {
      pfVar4 = (float *)(iVar3 * 0x10 + 4 + param_1);
      do {
        if (*pfVar4 < param_3) break;
        iVar3 = iVar3 + -1;
        pfVar4 = pfVar4 + -4;
      } while (-1 < iVar3);
    }
    *param_4 = iVar3 + 1;
  }
  else if (param_3 < param_2) {
    if (iVar3 < iVar1) {
      piVar6 = (int *)(iVar3 * 0x10 + param_1);
      iVar3 = iVar1 - iVar3;
      do {
        puVar2 = *(undefined4 **)(param_6 + *piVar6 * 4);
        if (puVar2 != (undefined4 *)0x0) {
          (**(code **)*puVar2)(param_3,piVar6,param_7);
        }
        piVar6 = piVar6 + 4;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    *param_4 = 0;
  }
  iVar3 = *param_4;
  if (iVar3 < iVar1) {
    piVar6 = (int *)(iVar3 * 0x10 + param_1);
    do {
      if ((float)piVar6[1] < param_3 == ((float)piVar6[1] == param_3)) break;
      puVar2 = *(undefined4 **)(param_6 + *piVar6 * 4);
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)*puVar2)(param_3,piVar6,param_7);
      }
      iVar3 = iVar3 + 1;
      piVar6 = piVar6 + 4;
    } while (iVar3 < iVar1);
  }
  *param_4 = iVar3;
  if (iVar3 < iVar1) {
    *param_5 = param_3;
    return;
  }
  *param_4 = iVar1 + -1;
  *param_5 = param_3;
  return;
}


// ==== 0x629140 FUN_00629140

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00629140(float param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  
  if (param_3[3] * param_2[3] +
      param_2[1] * param_3[1] + param_2[2] * param_3[2] + *param_2 * *param_3 <= 0.0) {
    *param_4 = *param_2 - (*param_2 + *param_3) * param_1;
    param_4[1] = param_2[1] - (param_2[1] + param_3[1]) * param_1;
    param_4[2] = param_2[2] - (param_2[2] + param_3[2]) * param_1;
    fVar1 = param_2[3] - (param_3[3] + param_2[3]) * param_1;
  }
  else {
    *param_4 = (*param_3 - *param_2) * param_1 + *param_2;
    param_4[1] = (param_3[1] - param_2[1]) * param_1 + param_2[1];
    param_4[2] = (param_3[2] - param_2[2]) * param_1 + param_2[2];
    fVar1 = (param_3[3] - param_2[3]) * param_1 + param_2[3];
  }
  param_4[3] = fVar1;
  fVar1 = _K_ONE / SQRT(param_4[3] * param_4[3] +
                        param_4[2] * param_4[2] + param_4[1] * param_4[1] + *param_4 * *param_4);
  *param_4 = fVar1 * *param_4;
  param_4[1] = fVar1 * param_4[1];
  param_4[2] = fVar1 * param_4[2];
  param_4[3] = fVar1 * param_4[3];
  return;
}


// ==== 0x629240 FUN_00629240

void __fastcall FUN_00629240(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a7c48;
  if (param_1[5] != 0) {
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[5]);
  }
  if (param_1[7] != 0) {
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[7]);
  }
  FUN_00628ed0();
  return;
}


// ==== 0x629280 FUN_00629280

void __fastcall FUN_00629280(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a7b70;
  if (param_1[5] != 0) {
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[5]);
  }
  if (param_1[7] != 0) {
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[7]);
  }
  FUN_00628ed0();
  return;
}


// ==== 0x6292c0 FUN_006292c0

void __thiscall FUN_006292c0(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    uVar1 = **(ushort **)(param_2 + 4);
  }
  else {
    if (**(ushort **)(param_2 + 4) < **(ushort **)(*(int *)(param_1 + 0xc) + 4)) goto LAB_0062930f;
    (**(code **)(*DAT_0070d364 + 0x18))(*(int *)(param_1 + 0x14));
    uVar1 = **(ushort **)(param_2 + 4);
  }
  uVar2 = (**(code **)(*DAT_0070d364 + 0x14))((uint)uVar1 << 2);
  *(undefined4 *)(param_1 + 0x14) = uVar2;
LAB_0062930f:
  *(int *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
  return;
}


// ==== 0x629320 FUN_00629320

undefined4 __thiscall FUN_00629320(int param_1,float *param_2)

{
  int iVar1;
  
  iVar1 = *(ushort *)
           (*(int *)(*(int *)(param_1 + 0xc) + 8) + -4 +
           (uint)*(ushort *)(*(int *)(param_1 + 0xc) + 0xc) * 2) + 1;
  *param_2 = (float)iVar1;
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


// ==== 0x629350 FUN_00629350

int FUN_00629350(float param_1)

{
  if (0.0 <= param_1) {
    return (int)ROUND(param_1 - 0.499999);
  }
  return (int)ROUND(param_1 + 0.499999);
}


// ==== 0x6293a0 FUN_006293a0

void __thiscall FUN_006293a0(int param_1,undefined4 param_2,float param_3,int param_4)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  if (param_3 < 0.0) {
    fVar4 = param_3 + 0.499999;
  }
  else {
    fVar4 = param_3 - 0.499999;
  }
  iVar7 = (int)ROUND(fVar4);
  uVar5 = (uint)*(ushort *)(*(int *)(param_1 + 0xc) + 8);
  if (iVar7 < (int)uVar5) {
    iVar6 = iVar7;
    if (iVar7 < 0) {
      iVar6 = 0;
    }
  }
  else {
    iVar6 = uVar5 - 1;
  }
  FUN_00634180(0,**(undefined2 **)(*(int *)(param_1 + 0xc) + 4),*(undefined4 *)(param_1 + 0x10),
               iVar6,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x14));
  *(int *)(param_1 + 0x10) = iVar6;
  iVar6 = *(int *)(param_1 + 0xc);
  uVar3 = **(ushort **)(iVar6 + 4);
  if ((param_3 != (float)iVar7) && (iVar7 + 1 < (int)(uint)*(ushort *)(iVar6 + 8))) {
    FUN_006345a0(0,uVar3,iVar7,iVar7 + 1,*(undefined4 *)(param_1 + 0x14),param_4,1,iVar6 + 10,
                 param_3 - (float)iVar7);
    return;
  }
  iVar7 = 0;
  if (uVar3 != 0) {
    do {
      iVar1 = iVar7 * 2;
      iVar2 = iVar7 * 4;
      iVar7 = iVar7 + 1;
      *(undefined4 *)(param_4 + (uint)*(ushort *)(iVar6 + 10 + iVar1) * 4) =
           *(undefined4 *)(*(int *)(param_1 + 0x14) + iVar2);
    } while (iVar7 < (int)(uint)uVar3);
  }
  return;
}


// ==== 0x6294c0 FUN_006294c0

undefined4 __thiscall FUN_006294c0(int param_1,float param_2,int param_3,int param_4)

{
  int iVar1;
  ushort uVar2;
  float fVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  iVar6 = *(int *)(param_1 + 0xc);
  uVar2 = *(ushort *)(iVar6 + 8);
  iVar1 = iVar6 + 10;
  if ((*(int *)(param_1 + 0x1c) == 0) && (**(ushort **)(iVar6 + 4) != 0)) {
    uVar7 = (uint)**(ushort **)(iVar6 + 4);
    uVar4 = (**(code **)(*DAT_0070d364 + 0x14))(uVar7 * 2);
    iVar6 = 0;
    *(undefined4 *)(param_1 + 0x1c) = uVar4;
    if (uVar7 != 0) {
      do {
        uVar5 = *(ushort *)(iVar1 + iVar6 * 2) / 0xc;
        if ((*(uint *)(param_4 + ((int)(uVar5 & 0xff) >> 5) * 4) & 1 << ((byte)uVar5 & 0x1f)) != 0)
        {
          *(short *)(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18) * 2) = (short)iVar6;
          *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < (int)uVar7);
    }
  }
  if (param_2 < 0.0) {
    fVar3 = param_2 + 0.499999;
  }
  else {
    fVar3 = param_2 - 0.499999;
  }
  iVar6 = (int)ROUND(fVar3);
  uVar7 = (uint)*(ushort *)(*(int *)(param_1 + 0xc) + 8);
  if (iVar6 < (int)uVar7) {
    iVar8 = iVar6;
    if (iVar6 < 0) {
      iVar8 = 0;
    }
  }
  else {
    iVar8 = uVar7 - 1;
  }
  FUN_00634b20(1,*(undefined4 *)(param_1 + 0x10),iVar8,*(undefined4 *)(param_1 + 0x14),
               *(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),
               *(undefined4 *)(param_1 + 0x1c));
  *(int *)(param_1 + 0x10) = iVar8;
  if ((param_2 != (float)iVar6) && (iVar6 + 1 < (int)(uint)uVar2)) {
    FUN_00634ed0(iVar6,iVar6 + 1,*(undefined4 *)(param_1 + 0x14),param_3,1,iVar1,
                 param_2 - (float)iVar6,*(undefined4 *)(param_1 + 0x18),
                 *(undefined4 *)(param_1 + 0x1c));
    return 1;
  }
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      uVar7 = (uint)*(ushort *)(*(int *)(param_1 + 0x1c) + iVar6 * 2);
      *(undefined4 *)(param_3 + (uint)*(ushort *)(iVar1 + uVar7 * 2) * 4) =
           *(undefined4 *)(*(int *)(param_1 + 0x14) + uVar7 * 4);
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(param_1 + 0x18));
  }
  return 1;
}


// ==== 0x629680 FUN_00629680

void __thiscall FUN_00629680(int param_1,undefined4 param_2,float param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  ushort uVar3;
  float fVar4;
  uint uVar5;
  ushort *puVar6;
  int iVar7;
  int iVar8;
  
  if (param_3 < 0.0) {
    fVar4 = param_3 + 0.499999;
  }
  else {
    fVar4 = param_3 - 0.499999;
  }
  iVar8 = (int)ROUND(fVar4);
  uVar5 = (uint)*(ushort *)(*(int *)(param_1 + 0xc) + 8);
  if (iVar8 < (int)uVar5) {
    iVar7 = iVar8;
    if (iVar8 < 0) {
      iVar7 = 0;
    }
  }
  else {
    iVar7 = uVar5 - 1;
  }
  FUN_00634180(0,**(undefined2 **)(*(int *)(param_1 + 0xc) + 4),*(undefined4 *)(param_1 + 0x10),
               iVar7,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x14));
  *(int *)(param_1 + 0x10) = iVar7;
  iVar7 = *(int *)(param_1 + 0xc);
  uVar3 = **(ushort **)(iVar7 + 4);
  puVar6 = (ushort *)(iVar7 + 10);
  if ((param_3 != (float)iVar8) && (iVar8 + 1 < (int)(uint)*(ushort *)(iVar7 + 8))) {
    FUN_006345a0(0,uVar3,iVar8,iVar8 + 1,*(undefined4 *)(param_1 + 0x14),param_4,4,puVar6,
                 param_3 - (float)iVar8);
    return;
  }
  iVar8 = 0;
  if (uVar3 != 0) {
    do {
      puVar1 = (undefined4 *)(*(int *)(param_1 + 0x14) + iVar8 * 4);
      puVar2 = (undefined4 *)(param_4 + (uint)*puVar6 * 4);
      *puVar2 = *puVar1;
      puVar2[1] = puVar1[1];
      puVar2[2] = puVar1[2];
      iVar8 = iVar8 + 4;
      puVar6 = puVar6 + 1;
      puVar2[3] = puVar1[3];
    } while (iVar8 < (int)(uint)uVar3);
  }
  return;
}


// ==== 0x6297c0 FUN_006297c0

undefined4 __thiscall FUN_006297c0(int param_1,float param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  ushort uVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  
  iVar6 = *(int *)(param_1 + 0xc);
  uVar3 = *(ushort *)(iVar6 + 8);
  iVar1 = iVar6 + 10;
  if ((*(int *)(param_1 + 0x1c) == 0) && (**(ushort **)(iVar6 + 4) != 0)) {
    uVar8 = (uint)**(ushort **)(iVar6 + 4);
    uVar5 = (**(code **)(*DAT_0070d364 + 0x14))(uVar8 * 2);
    iVar6 = 0;
    *(undefined4 *)(param_1 + 0x1c) = uVar5;
    if (uVar8 != 0) {
      iVar9 = (uVar8 - 1 >> 2) + 1;
      do {
        uVar8 = *(ushort *)(iVar1 + iVar6 * 2) / 0xc;
        if ((*(uint *)(param_4 + ((int)(uVar8 & 0xff) >> 5) * 4) & 1 << ((byte)uVar8 & 0x1f)) != 0)
        {
          *(short *)(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18) * 2) = (short)iVar6;
          *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
        }
        iVar6 = iVar6 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
  }
  if (param_2 < 0.0) {
    fVar4 = param_2 + 0.499999;
  }
  else {
    fVar4 = param_2 - 0.499999;
  }
  iVar6 = (int)ROUND(fVar4);
  uVar8 = (uint)*(ushort *)(*(int *)(param_1 + 0xc) + 8);
  if (iVar6 < (int)uVar8) {
    iVar9 = iVar6;
    if (iVar6 < 0) {
      iVar9 = 0;
    }
  }
  else {
    iVar9 = uVar8 - 1;
  }
  FUN_00634b20(4,*(undefined4 *)(param_1 + 0x10),iVar9,*(undefined4 *)(param_1 + 0x14),
               *(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),
               *(undefined4 *)(param_1 + 0x1c));
  *(int *)(param_1 + 0x10) = iVar9;
  if ((param_2 != (float)iVar6) && (iVar6 + 1 < (int)(uint)uVar3)) {
    FUN_00634ed0(iVar6,iVar6 + 1,*(undefined4 *)(param_1 + 0x14),param_3,4,iVar1,
                 param_2 - (float)iVar6,*(undefined4 *)(param_1 + 0x18),
                 *(undefined4 *)(param_1 + 0x1c));
    return 1;
  }
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      uVar8 = (uint)*(ushort *)(*(int *)(param_1 + 0x1c) + iVar6 * 2);
      puVar2 = (undefined4 *)(param_3 + (uint)*(ushort *)(iVar1 + uVar8 * 2) * 4);
      puVar7 = (undefined4 *)(uVar8 * 0x10 + *(int *)(param_1 + 0x14));
      *puVar2 = *puVar7;
      puVar2[1] = puVar7[1];
      puVar2[2] = puVar7[2];
      puVar2[3] = puVar7[3];
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(param_1 + 0x18));
  }
  return 1;
}


// ==== 0x6299a0 FUN_006299a0

int __thiscall FUN_006299a0(int param_1,float param_2)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  
  if (param_2 < 0.0) {
    fVar2 = param_2 + 0.499999;
  }
  else {
    fVar2 = param_2 - 0.499999;
  }
  iVar6 = (int)ROUND(fVar2);
  puVar5 = *(ushort **)(*(int *)(param_1 + 0xc) + 8);
  if (param_2 < (float)*puVar5) {
    return 0;
  }
  if (*(int *)(param_1 + 0x10) < 1) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x10) + -1;
  }
  if (iVar6 < (int)(uint)puVar5[iVar4]) {
    for (; (0 < iVar4 && (iVar6 < (int)(uint)puVar5[iVar4])); iVar4 = iVar4 + -1) {
    }
  }
  else {
    iVar1 = *(ushort *)(*(int *)(param_1 + 0xc) + 0xc) - 2;
    if (iVar4 < iVar1) {
      puVar5 = puVar5 + iVar4 + 1;
      iVar3 = iVar4;
      while (iVar4 = iVar3, (int)(uint)*puVar5 <= iVar6) {
        puVar5 = puVar5 + 1;
        iVar3 = iVar4 + 1;
        if (iVar1 <= iVar4 + 1) {
          return iVar4 + 2;
        }
      }
    }
  }
  return iVar4 + 1;
}


// ==== 0x629a80 FUN_00629a80

undefined4 __thiscall FUN_00629a80(int param_1,float param_2,int param_3,int param_4)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = *(int *)(param_1 + 0xc);
  uVar2 = *(ushort *)(iVar7 + 0xc);
  iVar3 = *(int *)(iVar7 + 8);
  iVar1 = iVar7 + 0xe;
  if ((*(int *)(param_1 + 0x1c) == 0) && (**(ushort **)(iVar7 + 4) != 0)) {
    uVar6 = (uint)**(ushort **)(iVar7 + 4);
    uVar4 = (**(code **)(*DAT_0070d364 + 0x14))(uVar6 * 2);
    iVar7 = 0;
    *(undefined4 *)(param_1 + 0x1c) = uVar4;
    if (uVar6 != 0) {
      do {
        uVar5 = *(ushort *)(iVar1 + iVar7 * 2) / 0xc;
        if ((*(uint *)(param_4 + ((int)(uVar5 & 0xff) >> 5) * 4) & 1 << ((byte)uVar5 & 0x1f)) != 0)
        {
          *(short *)(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18) * 2) = (short)iVar7;
          *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)uVar6);
    }
  }
  iVar7 = FUN_006299a0(param_2);
  FUN_00634b20(1,*(undefined4 *)(param_1 + 0x10),iVar7,*(undefined4 *)(param_1 + 0x14),
               *(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),
               *(undefined4 *)(param_1 + 0x1c));
  *(int *)(param_1 + 0x10) = iVar7;
  if (iVar7 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (uint)*(ushort *)(iVar3 + -2 + iVar7 * 2);
  }
  if ((((float)uVar6 != param_2) &&
      ((iVar7 != uVar2 - 1 || (param_2 <= (float)*(ushort *)(iVar3 + -4 + (uint)uVar2 * 2))))) &&
     ((iVar7 != 0 || (0.0 <= param_2)))) {
    FUN_00634ed0(iVar7,iVar7 + 1,*(undefined4 *)(param_1 + 0x14),param_3,1,iVar1,
                 (param_2 - (float)uVar6) / (float)(int)(*(ushort *)(iVar3 + iVar7 * 2) - uVar6),
                 *(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));
    return 1;
  }
  iVar7 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      uVar6 = (uint)*(ushort *)(*(int *)(param_1 + 0x1c) + iVar7 * 2);
      *(undefined4 *)(param_3 + (uint)*(ushort *)(iVar1 + uVar6 * 2) * 4) =
           *(undefined4 *)(*(int *)(param_1 + 0x14) + uVar6 * 4);
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(param_1 + 0x18));
  }
  return 1;
}


// ==== 0x629c20 FUN_00629c20

undefined4 __thiscall FUN_00629c20(int param_1,float param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  int iStack_20;
  undefined1 auStack_10 [16];
  
  iVar3 = *(int *)(param_1 + 0xc);
  uVar2 = *(ushort *)(iVar3 + 0xc);
  iVar6 = *(int *)(iVar3 + 8);
  if ((*(int *)(param_1 + 0x1c) == 0) && (**(ushort **)(iVar3 + 4) != 0)) {
    uVar8 = (uint)**(ushort **)(iVar3 + 4);
    uVar4 = (**(code **)(*DAT_0070d364 + 0x14))(uVar8 * 2);
    iVar7 = 0;
    *(undefined4 *)(param_1 + 0x1c) = uVar4;
    if (uVar8 != 0) {
      iStack_20 = (uVar8 - 1 >> 2) + 1;
      do {
        uVar8 = *(ushort *)(iVar3 + 0xe + iVar7 * 2) / 0xc;
        if ((*(uint *)(param_4 + ((int)(uVar8 & 0xff) >> 5) * 4) & 1 << ((byte)uVar8 & 0x1f)) != 0)
        {
          *(short *)(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18) * 2) = (short)iVar7;
          *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
        }
        iVar7 = iVar7 + 1;
        iStack_20 = iStack_20 + -1;
      } while (iStack_20 != 0);
    }
  }
  iVar7 = FUN_006299a0(param_2);
  FUN_00634b20(4,*(undefined4 *)(param_1 + 0x10),iVar7,*(undefined4 *)(param_1 + 0x14),
               *(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),
               *(undefined4 *)(param_1 + 0x1c));
  *(int *)(param_1 + 0x10) = iVar7;
  if (iVar7 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = (uint)*(ushort *)(iVar6 + -2 + iVar7 * 2);
  }
  if ((((float)uVar8 == param_2) ||
      ((iVar7 == uVar2 - 1 && ((float)*(ushort *)(iVar6 + -4 + (uint)uVar2 * 2) < param_2)))) ||
     ((iVar7 == 0 && (param_2 < 0.0)))) {
    iVar6 = 0;
    if (0 < *(int *)(param_1 + 0x18)) {
      do {
        uVar8 = (uint)*(ushort *)(*(int *)(param_1 + 0x1c) + iVar6 * 2);
        puVar10 = (undefined4 *)(uVar8 * 0x10 + *(int *)(param_1 + 0x14));
        puVar1 = (undefined4 *)(param_3 + (uint)*(ushort *)(iVar3 + 0xe + uVar8 * 2) * 4);
        *puVar1 = *puVar10;
        puVar1[1] = puVar10[1];
        puVar1[2] = puVar10[2];
        puVar1[3] = puVar10[3];
        iVar6 = iVar6 + 1;
      } while (iVar6 < *(int *)(param_1 + 0x18));
    }
  }
  else {
    uVar2 = *(ushort *)(iVar6 + iVar7 * 2);
    iVar6 = *(int *)(param_1 + 0x18);
    iVar9 = 0;
    if (0 < iVar6) {
      do {
        uVar5 = (uint)*(ushort *)(*(int *)(param_1 + 0x1c) + iVar9 * 2);
        FUN_00634180(uVar5 << 2,4,iVar7,iVar7 + 1,uVar5 * 0x10 + *(int *)(param_1 + 0x14),auStack_10
                    );
        uVar5 = (uint)*(ushort *)(*(int *)(param_1 + 0x1c) + iVar9 * 2);
        FUN_00629140((param_2 - (float)uVar8) / (float)(int)(uVar2 - uVar8),
                     uVar5 * 0x10 + *(int *)(param_1 + 0x14),auStack_10,
                     param_3 + (uint)*(ushort *)(iVar3 + 0xe + uVar5 * 2) * 4);
        iVar9 = iVar9 + 1;
      } while (iVar9 < *(int *)(param_1 + 0x18));
      return CONCAT31((int3)((uint)*(int *)(param_1 + 0x18) >> 8),1);
    }
  }
  return CONCAT31((int3)((uint)iVar6 >> 8),1);
}


// ==== 0x629e50 FUN_00629e50

undefined4 __thiscall FUN_00629e50(int param_1,float param_2,int param_3,int param_4)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  if (param_4 != 0) {
    uVar4 = FUN_006294c0(param_2,param_3,param_4);
    return uVar4;
  }
  iVar5 = FUN_00629350(param_2);
  uVar6 = (uint)*(ushort *)(*(int *)(param_1 + 0xc) + 8);
  if (iVar5 < (int)uVar6) {
    iVar7 = iVar5;
    if (iVar5 < 0) {
      iVar7 = 0;
    }
  }
  else {
    iVar7 = uVar6 - 1;
  }
  FUN_00634180(0,**(undefined2 **)(*(int *)(param_1 + 0xc) + 4),*(undefined4 *)(param_1 + 0x10),
               iVar7,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x14));
  iVar3 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0x10) = iVar7;
  uVar2 = **(ushort **)(iVar3 + 4);
  if ((param_2 != (float)iVar5) && (iVar5 + 1 < (int)(uint)*(ushort *)(iVar3 + 8))) {
    FUN_006345a0(0,uVar2,iVar5,iVar5 + 1,*(undefined4 *)(param_1 + 0x14),param_3,1,iVar3 + 10,
                 param_2 - (float)iVar5);
    return 1;
  }
  iVar5 = 0;
  if (uVar2 != 0) {
    do {
      iVar7 = iVar5 * 2;
      iVar1 = iVar5 * 4;
      iVar5 = iVar5 + 1;
      *(undefined4 *)(param_3 + (uint)*(ushort *)(iVar3 + 10 + iVar7) * 4) =
           *(undefined4 *)(*(int *)(param_1 + 0x14) + iVar1);
    } while (iVar5 < (int)(uint)uVar2);
  }
  return 1;
}


// ==== 0x629f40 FUN_00629f40

undefined4 __thiscall FUN_00629f40(int param_1,float param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  ushort uVar3;
  ushort uVar4;
  undefined4 uVar5;
  ushort *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  if (param_4 != 0) {
    uVar5 = FUN_006297c0(param_2,param_3,param_4);
    return uVar5;
  }
  iVar7 = *(int *)(param_1 + 0xc);
  uVar3 = *(ushort *)(iVar7 + 8);
  uVar4 = **(ushort **)(iVar7 + 4);
  puVar6 = (ushort *)(iVar7 + 10);
  iVar7 = FUN_00629350(param_2);
  uVar8 = (uint)*(ushort *)(*(int *)(param_1 + 0xc) + 8);
  if (iVar7 < (int)uVar8) {
    iVar9 = iVar7;
    if (iVar7 < 0) {
      iVar9 = 0;
    }
  }
  else {
    iVar9 = uVar8 - 1;
  }
  FUN_00634180(0,**(undefined2 **)(*(int *)(param_1 + 0xc) + 4),*(undefined4 *)(param_1 + 0x10),
               iVar9,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x14));
  *(int *)(param_1 + 0x10) = iVar9;
  if ((param_2 != (float)iVar7) && (iVar7 + 1 < (int)(uint)uVar3)) {
    FUN_006345a0(0,uVar4,iVar7,iVar7 + 1,*(undefined4 *)(param_1 + 0x14),param_3,4,puVar6,
                 param_2 - (float)iVar7);
    return 1;
  }
  iVar7 = 0;
  if (uVar4 != 0) {
    do {
      puVar1 = (undefined4 *)(*(int *)(param_1 + 0x14) + iVar7 * 4);
      puVar2 = (undefined4 *)(param_3 + (uint)*puVar6 * 4);
      *puVar2 = *puVar1;
      puVar2[1] = puVar1[1];
      puVar2[2] = puVar1[2];
      iVar7 = iVar7 + 4;
      puVar6 = puVar6 + 1;
      puVar2[3] = puVar1[3];
    } while (iVar7 < (int)(uint)uVar4);
  }
  return 1;
}


// ==== 0x62a080 FUN_0062a080

undefined4 __thiscall FUN_0062a080(int param_1,float param_2,int param_3,uint param_4)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  if (param_4 != 0) {
    uVar4 = FUN_00629a80(param_2,param_3,param_4);
    return uVar4;
  }
  iVar5 = FUN_006299a0(param_2);
  FUN_00634180(0,**(undefined2 **)(*(int *)(param_1 + 0xc) + 4),*(undefined4 *)(param_1 + 0x10),
               iVar5,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x14));
  iVar3 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0x10) = iVar5;
  iVar6 = *(int *)(iVar3 + 8);
  uVar2 = **(ushort **)(iVar3 + 4);
  if (iVar5 == 0) {
    param_4 = 0;
  }
  else {
    param_4 = (uint)*(ushort *)(iVar6 + -2 + iVar5 * 2);
  }
  if ((((float)param_4 != param_2) &&
      ((iVar5 != *(ushort *)(iVar3 + 0xc) - 1 ||
       (param_2 <= (float)*(ushort *)(iVar6 + -4 + (uint)*(ushort *)(iVar3 + 0xc) * 2))))) &&
     ((iVar5 != 0 || (0.0 <= param_2)))) {
    FUN_006345a0(0,uVar2,iVar5,iVar5 + 1,*(undefined4 *)(param_1 + 0x14),param_3,1,iVar3 + 0xe,
                 (param_2 - (float)param_4) / (float)(int)(*(ushort *)(iVar6 + iVar5 * 2) - param_4)
                );
    return 1;
  }
  iVar6 = 0;
  if (uVar2 != 0) {
    do {
      iVar5 = iVar6 * 2;
      iVar1 = iVar6 * 4;
      iVar6 = iVar6 + 1;
      *(undefined4 *)(param_3 + (uint)*(ushort *)(iVar3 + 0xe + iVar5) * 4) =
           *(undefined4 *)(*(int *)(param_1 + 0x14) + iVar1);
    } while (iVar6 < (int)(uint)uVar2);
  }
  return 1;
}


// ==== 0x62a1d0 FUN_0062a1d0

undefined4 __thiscall FUN_0062a1d0(int param_1,ushort *param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  ushort uVar3;
  ushort uVar4;
  float fVar5;
  undefined4 uVar6;
  ushort *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined1 auStack_10 [16];
  
  if (param_4 != 0) {
    uVar6 = FUN_00629c20(param_2,param_3,param_4);
    return uVar6;
  }
  iVar8 = *(int *)(param_1 + 0xc);
  uVar3 = *(ushort *)(iVar8 + 0xc);
  uVar4 = **(ushort **)(iVar8 + 4);
  iVar9 = *(int *)(iVar8 + 8);
  puVar7 = (ushort *)(iVar8 + 0xe);
  iVar8 = FUN_006299a0(param_2);
  FUN_00634180(0,**(undefined2 **)(*(int *)(param_1 + 0xc) + 4),*(undefined4 *)(param_1 + 0x10),
               iVar8,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x14));
  *(int *)(param_1 + 0x10) = iVar8;
  if (iVar8 == 0) {
    uVar10 = 0;
  }
  else {
    uVar10 = (uint)*(ushort *)(iVar9 + -2 + iVar8 * 2);
  }
  if ((((float)uVar10 == (float)param_2) ||
      ((iVar8 == uVar3 - 1 && ((float)*(ushort *)(iVar9 + -4 + (uint)uVar3 * 2) < (float)param_2))))
     || ((iVar8 == 0 && ((float)param_2 < 0.0)))) {
    iVar9 = 0;
    if (uVar4 != 0) {
      do {
        puVar1 = (undefined4 *)(*(int *)(param_1 + 0x14) + iVar9 * 4);
        puVar2 = (undefined4 *)(param_3 + (uint)*puVar7 * 4);
        *puVar2 = *puVar1;
        puVar2[1] = puVar1[1];
        puVar2[2] = puVar1[2];
        iVar9 = iVar9 + 4;
        puVar7 = puVar7 + 1;
        puVar2[3] = puVar1[3];
      } while (iVar9 < (int)(uint)uVar4);
    }
  }
  else {
    uVar3 = *(ushort *)(iVar9 + iVar8 * 2);
    fVar5 = (float)param_2 - (float)uVar10;
    iVar11 = 0;
    iVar9 = 0;
    param_2 = puVar7;
    if (uVar4 != 0) {
      do {
        FUN_00634180(iVar11,4,iVar8,iVar8 + 1,*(int *)(param_1 + 0x14) + iVar11 * 4,auStack_10);
        FUN_00629140(fVar5 / (float)(int)(uVar3 - uVar10),*(int *)(param_1 + 0x14) + iVar11 * 4,
                     auStack_10,param_3 + (uint)*param_2 * 4);
        iVar11 = iVar11 + 4;
        param_2 = param_2 + 1;
      } while (iVar11 < (int)(uint)uVar4);
      return CONCAT31((uint3)(byte)(uVar4 >> 8),1);
    }
  }
  return CONCAT31((int3)((uint)iVar9 >> 8),1);
}


// ==== 0x62a3a0 FUN_0062a3a0

void FUN_0062a3a0(float param_1,float *param_2,float *param_3,float *param_4)

{
  *param_4 = (*param_3 - *param_2) * param_1 + *param_2;
  param_4[1] = (param_3[1] - param_2[1]) * param_1 + param_2[1];
  param_4[2] = (param_3[2] - param_2[2]) * param_1 + param_2[2];
  return;
}


// ==== 0x62a3e0 FUN_0062a3e0

void FUN_0062a3e0(int param_1,float param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  
  if (param_6 == 0) {
    if (0 < param_1) {
      do {
        FUN_00629140(param_2,param_3 + 0x10,param_4 + 0x10,param_5 + 0x10);
        param_1 = param_1 + -1;
        *(float *)(param_5 + 0x20) =
             (*(float *)(param_4 + 0x20) - *(float *)(param_3 + 0x20)) * param_2 +
             *(float *)(param_3 + 0x20);
        *(float *)(param_5 + 0x24) =
             (*(float *)(param_4 + 0x24) - *(float *)(param_3 + 0x24)) * param_2 +
             *(float *)(param_3 + 0x24);
        *(float *)(param_5 + 0x28) =
             (*(float *)(param_4 + 0x28) - *(float *)(param_3 + 0x28)) * param_2 +
             *(float *)(param_3 + 0x28);
        param_4 = param_4 + 0x30;
        param_3 = param_3 + 0x30;
        param_5 = param_5 + 0x30;
      } while (param_1 != 0);
      return;
    }
  }
  else {
    iVar1 = 0;
    if (0 < param_1) {
      do {
        if ((*(uint *)(param_6 + (iVar1 >> 5) * 4) & 1 << ((byte)iVar1 & 0x1f)) != 0) {
          FUN_00629140(param_2,param_3 + 0x10,param_4 + 0x10,param_5 + 0x10);
          *(float *)(param_5 + 0x20) =
               (*(float *)(param_4 + 0x20) - *(float *)(param_3 + 0x20)) * param_2 +
               *(float *)(param_3 + 0x20);
          *(float *)(param_5 + 0x24) =
               (*(float *)(param_4 + 0x24) - *(float *)(param_3 + 0x24)) * param_2 +
               *(float *)(param_3 + 0x24);
          *(float *)(param_5 + 0x28) =
               (*(float *)(param_4 + 0x28) - *(float *)(param_3 + 0x28)) * param_2 +
               *(float *)(param_3 + 0x28);
        }
        param_5 = param_5 + 0x30;
        param_3 = param_3 + 0x30;
        param_4 = param_4 + 0x30;
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_1);
    }
  }
  return;
}


// ==== 0x62a520 FUN_0062a520

undefined4 __thiscall FUN_0062a520(int param_1,float param_2,int param_3,byte *param_4)

{
  int iVar1;
  char cVar2;
  undefined4 unaff_EBX;
  int iVar3;
  undefined4 unaff_EDI;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  float local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  
  if (param_2 < *(float *)(param_1 + 0x70) == (param_2 == *(float *)(param_1 + 0x70))) {
    if (param_2 < *(float *)(param_1 + 0x78)) {
      local_78 = (param_2 - *(float *)(param_1 + 0x70)) / *(float *)(param_1 + 0x74);
      if (*(char *)(param_1 + 0x7c) != '\0') {
        FUN_00628c90(*(undefined4 *)(param_1 + 0x10),param_4);
      }
      if (*(char *)(param_1 + 0x7d) != '\0') {
        FUN_00628c90(*(undefined4 *)(param_1 + 0x14),param_4);
      }
      cVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x18))
                        (param_2 - *(float *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x10),
                         param_4);
      if ((cVar2 != '\0') &&
         (cVar2 = (**(code **)(**(int **)(param_1 + 0x1c) + 0x18))
                            (param_2 - *(float *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x14),
                             param_4), cVar2 != '\0')) {
        if (param_4 != (byte *)0x0) {
          if (-1 < *(int *)(param_1 + 0x28)) {
            iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8) + -1;
            if (iVar4 < 0) {
              return 1;
            }
            iVar3 = iVar4 * 0x30 + 0x10;
            do {
              if ((*(uint *)(param_4 + (iVar4 >> 5) * 4) & 1 << ((byte)iVar4 & 0x1f)) != 0) {
                if (iVar4 == *(int *)(param_1 + 0x28)) {
                  iVar1 = *(int *)(param_1 + 0x14);
                  iVar6 = *(int *)(param_1 + 0x28) * 0x30;
                  puVar5 = (undefined4 *)(iVar6 + iVar1);
                  FUN_00627d80(*puVar5,puVar5[1],puVar5[2],puVar5[4],puVar5[5],puVar5[6],puVar5[7],
                               puVar5[8],*(undefined4 *)(iVar6 + 0x24 + iVar1),
                               *(undefined4 *)(iVar6 + 0x28 + iVar1));
                  FUN_00622460(param_1 + 0x30);
                  FUN_00622610(&stack0xffffff78,&local_78);
                  puVar5[4] = unaff_EBX;
                  puVar5[5] = uStack_84;
                  puVar5[6] = uStack_80;
                  puVar5[7] = uStack_7c;
                  puVar5[8] = local_78;
                  puVar5[9] = uStack_74;
                  puVar5[10] = uStack_70;
                  iVar1 = *(int *)(param_1 + 0x28) * 4 + 0x20;
                  FUN_0062a3a0(unaff_EDI,*(int *)(param_1 + 0x10) + iVar1,
                               *(int *)(param_1 + 0x14) + iVar1,iVar1 + param_3);
                }
                FUN_00629140(unaff_EDI,*(int *)(param_1 + 0x10) + iVar3,
                             *(int *)(param_1 + 0x14) + iVar3,iVar3 + param_3);
              }
              iVar4 = iVar4 + -1;
              iVar3 = iVar3 + -0x30;
            } while (-1 < iVar4);
            return 1;
          }
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8) + -1;
          if (-1 < iVar4) {
            iVar3 = iVar4 * 0x30 + 0x10;
            do {
              if ((*(uint *)(param_4 + (iVar4 >> 5) * 4) & 1 << ((byte)iVar4 & 0x1f)) != 0) {
                FUN_00629140(unaff_EDI,*(int *)(param_1 + 0x10) + iVar3,
                             *(int *)(param_1 + 0x14) + iVar3,iVar3 + param_3);
              }
              iVar4 = iVar4 + -1;
              iVar3 = iVar3 + -0x30;
            } while (-1 < iVar4);
          }
          if ((*param_4 & 1) == 0) {
            return 1;
          }
          FUN_0062a3a0(unaff_EDI,*(int *)(param_1 + 0x10) + 0x20,*(int *)(param_1 + 0x14) + 0x20,
                       param_3 + 0x20);
          return 1;
        }
        if (*(int *)(param_1 + 0x28) < 0) {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
          if (-1 < iVar4 + -1) {
            iVar3 = (iVar4 + -1) * 0x30 + 0x10;
            do {
              FUN_00629140(unaff_EDI,*(int *)(param_1 + 0x10) + iVar3,
                           *(int *)(param_1 + 0x14) + iVar3,iVar3 + param_3);
              iVar3 = iVar3 + -0x30;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          FUN_0062a3a0(unaff_EDI,*(int *)(param_1 + 0x10) + 0x20,*(int *)(param_1 + 0x14) + 0x20,
                       param_3 + 0x20);
          return 1;
        }
        iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8) + -1;
        if (iVar4 < 0) {
          return 1;
        }
        iVar3 = iVar4 * 0x30 + 0x10;
        do {
          if (iVar4 == *(int *)(param_1 + 0x28)) {
            iVar1 = *(int *)(param_1 + 0x14);
            iVar6 = *(int *)(param_1 + 0x28) * 0x30;
            puVar5 = (undefined4 *)(iVar6 + iVar1);
            FUN_00627d80(*puVar5,puVar5[1],puVar5[2],puVar5[4],puVar5[5],puVar5[6],puVar5[7],
                         puVar5[8],*(undefined4 *)(iVar6 + 0x24 + iVar1),
                         *(undefined4 *)(iVar6 + 0x28 + iVar1));
            FUN_00622460(param_1 + 0x30);
            FUN_00622610(&stack0xffffff78,&local_78);
            puVar5[4] = unaff_EBX;
            puVar5[5] = uStack_84;
            puVar5[6] = uStack_80;
            puVar5[7] = uStack_7c;
            puVar5[8] = local_78;
            puVar5[9] = uStack_74;
            puVar5[10] = uStack_70;
            iVar1 = *(int *)(param_1 + 0x28) * 4 + 0x20;
            FUN_0062a3a0(unaff_EDI,*(int *)(param_1 + 0x10) + iVar1,*(int *)(param_1 + 0x14) + iVar1
                         ,iVar1 + param_3);
          }
          FUN_00629140(unaff_EDI,*(int *)(param_1 + 0x10) + iVar3,*(int *)(param_1 + 0x14) + iVar3,
                       iVar3 + param_3);
          iVar4 = iVar4 + -1;
          iVar3 = iVar3 + -0x30;
        } while (-1 < iVar4);
        return 1;
      }
    }
    else {
      cVar2 = (**(code **)(**(int **)(param_1 + 0x1c) + 0x18))
                        (param_2 - *(float *)(param_1 + 0x24),param_3,param_4);
      if (cVar2 != '\0') {
        iVar4 = *(int *)(param_1 + 0x28);
        if (iVar4 < 0) {
          return 1;
        }
        if ((param_4 != (byte *)0x0) && (cVar2 = FUN_00627ea0(iVar4), cVar2 == '\0')) {
          return 1;
        }
        iVar4 = iVar4 * 0x30;
        puVar5 = (undefined4 *)(iVar4 + param_3);
        FUN_00627d80(*puVar5,puVar5[1],puVar5[2],puVar5[4],puVar5[5],puVar5[6],puVar5[7],puVar5[8],
                     *(undefined4 *)(iVar4 + 0x24 + param_3),*(undefined4 *)(iVar4 + 0x28 + param_3)
                    );
        FUN_00622460(param_1 + 0x30);
        FUN_00622610(&uStack_7c,&uStack_6c);
        puVar5[4] = uStack_7c;
        puVar5[5] = local_78;
        puVar5[6] = uStack_74;
        puVar5[7] = uStack_70;
        puVar5[8] = uStack_6c;
        puVar5[9] = uStack_68;
        puVar5[10] = uStack_64;
        return 1;
      }
    }
  }
  else {
    cVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x18))
                      (param_2 - *(float *)(param_1 + 0x20),param_3,param_4);
    if (cVar2 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== 0x62aa30 FUN_0062aa30

void __thiscall FUN_0062aa30(int param_1,float param_2,float param_3,int param_4)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  undefined4 unaff_EBX;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  undefined4 uStack_84;
  undefined4 uStack_80;
  float local_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  
  if (param_3 < *(float *)(param_1 + 0x70) != (param_3 == *(float *)(param_1 + 0x70))) {
    (**(code **)(**(int **)(param_1 + 0x18) + 0xc))
              (param_2 - *(float *)(param_1 + 0x20),param_3 - *(float *)(param_1 + 0x20),param_4);
    return;
  }
  if (param_3 < *(float *)(param_1 + 0x78)) {
    local_7c = (param_3 - *(float *)(param_1 + 0x70)) / *(float *)(param_1 + 0x74);
    if (*(char *)(param_1 + 0x7c) != '\0') {
      FUN_00628c90(*(undefined4 *)(param_1 + 0x10),0);
    }
    if (*(char *)(param_1 + 0x7d) != '\0') {
      FUN_00628c90(*(undefined4 *)(param_1 + 0x14),0);
    }
    fVar8 = *(float *)(param_1 + 0x10);
    (**(code **)(**(int **)(param_1 + 0x18) + 0xc))
              (param_2 - *(float *)(param_1 + 0x20),param_3 - *(float *)(param_1 + 0x20));
    (**(code **)(**(int **)(param_1 + 0x1c) + 0xc))
              (param_2 - *(float *)(param_1 + 0x24),param_3 - *(float *)(param_1 + 0x24),
               *(undefined4 *)(param_1 + 0x14));
    if (*(int *)(param_1 + 0x28) < 0) {
      for (iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8) * 0xc + -8; 3 < iVar4; iVar4 = iVar4 + -0xc
          ) {
        iVar6 = iVar4 * 4;
        FUN_00629140(fVar8,*(int *)(param_1 + 0x10) + iVar6,*(int *)(param_1 + 0x14) + iVar6,
                     iVar6 + param_4);
      }
      iVar4 = *(int *)(param_1 + 0x14);
      iVar6 = *(int *)(param_1 + 0x10);
      *(float *)(param_4 + 0x20) =
           (*(float *)(iVar4 + 0x20) - *(float *)(iVar6 + 0x20)) * fVar8 + *(float *)(iVar6 + 0x20);
      *(float *)(param_4 + 0x24) =
           (*(float *)(iVar4 + 0x24) - *(float *)(iVar6 + 0x24)) * fVar8 + *(float *)(iVar6 + 0x24);
      *(float *)(param_4 + 0x28) =
           (*(float *)(iVar4 + 0x28) - *(float *)(iVar6 + 0x28)) * fVar8 + *(float *)(iVar6 + 0x28);
    }
    else {
      iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8) + -1;
      if (-1 < iVar4) {
        iVar6 = iVar4 * 0x30 + 0x10;
        do {
          if (iVar4 == *(int *)(param_1 + 0x28)) {
            iVar1 = *(int *)(param_1 + 0x14);
            iVar7 = *(int *)(param_1 + 0x28) * 0x30;
            puVar5 = (undefined4 *)(iVar7 + iVar1);
            FUN_00627d80(*puVar5,puVar5[1],puVar5[2],puVar5[4],puVar5[5],puVar5[6],puVar5[7],
                         puVar5[8],*(undefined4 *)(iVar7 + 0x24 + iVar1),
                         *(undefined4 *)(iVar7 + 0x28 + iVar1));
            FUN_00622460(param_1 + 0x30);
            FUN_00622610(&stack0xffffff78,&uStack_78);
            puVar5[4] = unaff_EBX;
            puVar5[5] = uStack_84;
            puVar5[6] = uStack_80;
            puVar5[7] = local_7c;
            puVar5[8] = uStack_78;
            puVar5[9] = uStack_74;
            puVar5[10] = uStack_70;
            iVar1 = *(int *)(param_1 + 0x28) * 4;
            iVar7 = iVar1 + 0x20;
            iVar3 = *(int *)(param_1 + 0x14) + iVar7;
            pfVar2 = (float *)(*(int *)(param_1 + 0x10) + iVar7);
            *(float *)(iVar7 + param_4) =
                 (*(float *)(*(int *)(param_1 + 0x14) + iVar7) -
                 *(float *)(*(int *)(param_1 + 0x10) + iVar7)) * fVar8 + *pfVar2;
            *(float *)(iVar1 + 0x24 + param_4) =
                 (*(float *)(iVar3 + 4) - pfVar2[1]) * fVar8 + pfVar2[1];
            *(float *)(iVar1 + 0x28 + param_4) =
                 (*(float *)(iVar3 + 8) - pfVar2[2]) * fVar8 + pfVar2[2];
          }
          FUN_00629140(fVar8,*(int *)(param_1 + 0x10) + iVar6,*(int *)(param_1 + 0x14) + iVar6,
                       iVar6 + param_4);
          iVar4 = iVar4 + -1;
          iVar6 = iVar6 + -0x30;
        } while (-1 < iVar4);
        return;
      }
    }
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x1c) + 0xc))
              (param_2 - *(float *)(param_1 + 0x24),param_3 - *(float *)(param_1 + 0x24),param_4);
    if (-1 < *(int *)(param_1 + 0x28)) {
      iVar4 = *(int *)(param_1 + 0x28) * 0x30;
      puVar5 = (undefined4 *)(iVar4 + param_4);
      FUN_00627d80(*puVar5,puVar5[1],puVar5[2],puVar5[4],puVar5[5],puVar5[6],puVar5[7],
                   *(undefined4 *)(iVar4 + 0x20 + param_4),*(undefined4 *)(iVar4 + 0x24 + param_4),
                   *(undefined4 *)(iVar4 + 0x28 + param_4));
      FUN_00622460(param_1 + 0x30);
      FUN_00622610(&local_7c,&uStack_6c);
      puVar5[4] = local_7c;
      puVar5[5] = uStack_78;
      puVar5[6] = uStack_74;
      puVar5[7] = uStack_70;
      puVar5[8] = uStack_6c;
      puVar5[9] = uStack_68;
      puVar5[10] = uStack_64;
      return;
    }
  }
  return;
}


// ==== 0x62ada0 FUN_0062ada0

void __thiscall FUN_0062ada0(int param_1,float param_2,float param_3,undefined4 param_4)

{
  float unaff_ESI;
  float unaff_EDI;
  
  if (param_3 < *(float *)(param_1 + 0x1c) == (param_3 == *(float *)(param_1 + 0x1c))) {
    if (param_3 < *(float *)(param_1 + 0x20)) {
      if (*(int *)(param_1 + 0x28) == 0) goto LAB_0062ae3f;
      if (*(int *)(param_1 + 0x28) != 1) {
        (**(code **)(**(int **)(param_1 + 0xc) + 0xc))
                  (param_2 - *(float *)(param_1 + 0x14),param_3 - *(float *)(param_1 + 0x14),param_4
                  );
        (**(code **)(**(int **)(param_1 + 0x10) + 0xc))
                  (unaff_EDI - *(float *)(param_1 + 0x18),unaff_ESI - *(float *)(param_1 + 0x18),
                   param_4);
        return;
      }
    }
    (**(code **)(**(int **)(param_1 + 0x10) + 0xc))
              (param_2 - *(float *)(param_1 + 0x18),param_3 - *(float *)(param_1 + 0x18),param_4);
    return;
  }
LAB_0062ae3f:
  (**(code **)(**(int **)(param_1 + 0xc) + 0xc))
            (param_2 - *(float *)(param_1 + 0x14),param_3 - *(float *)(param_1 + 0x14),param_4);
  return;
}


// ==== 0x62ae70 FUN_0062ae70

undefined4 __thiscall FUN_0062ae70(int param_1,float *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *param_2 = (float)*(ushort *)(iVar1 + 4);
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


// ==== 0x62ae90 FUN_0062ae90

void __thiscall FUN_0062ae90(int param_1,int param_2)

{
  byte bVar1;
  
  *(int *)(param_1 + 0xc) = param_2;
  *(undefined2 *)(param_1 + 0x10) = 0;
  *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(param_2 + 6);
  *(byte *)(param_1 + 0x14) = ~*(byte *)(param_2 + 8) & 1;
  bVar1 = *(byte *)(param_2 + 8);
  if ((bVar1 & 8) != 0) {
    *(undefined1 *)(param_1 + 0x15) = 1;
    return;
  }
  if ((bVar1 & 0x10) != 0) {
    *(undefined1 *)(param_1 + 0x15) = 2;
    return;
  }
  if ((bVar1 & 0x20) != 0) {
    *(undefined1 *)(param_1 + 0x15) = 4;
    return;
  }
  *(byte *)(param_1 + 0x15) = (-((bVar1 & 0x40) != 0) & 7U) + 1;
  return;
}


// ==== 0x62aef0 FUN_0062aef0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0062aef0(int param_1,undefined4 param_2,float param_3,float *param_4)

{
  byte bVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int local_8;
  
  iVar2 = *(int *)(param_1 + 0xc);
  iVar8 = *(ushort *)(iVar2 + 4) - 1;
  if ((*(byte *)(iVar2 + 8) & 2) != 0) {
    fVar3 = (float)iVar8;
    if (0.0 <= param_3) {
      if (fVar3 < param_3) {
        iVar5 = FUN_00629350((param_3 - fVar3) / fVar3);
        param_3 = (param_3 - fVar3) - (float)(iVar5 * iVar8);
      }
    }
    else {
      iVar5 = FUN_00629350(param_3 / fVar3);
      param_3 = fVar3 - (param_3 - (float)(iVar8 * iVar5));
    }
  }
  if (param_3 < 0.0) {
    fVar3 = param_3 + 0.499999;
  }
  else {
    fVar3 = param_3 - 0.499999;
  }
  local_8 = (int)ROUND(fVar3);
  uVar7 = (uint)*(byte *)(param_1 + 0x15);
  local_8 = local_8 / (int)uVar7;
  uVar6 = (uint)*(byte *)(iVar2 + 9);
  fVar3 = (param_3 - (float)(int)(uVar7 * local_8)) / (float)uVar7;
  if (*(byte *)(iVar2 + 9) < 2) {
    uVar6 = 2;
  }
  fVar4 = (float)*(byte *)(uVar6 + local_8 + 10 + iVar2) * 1.4117647 - 180.0;
  *param_4 = fVar4;
  bVar1 = *(byte *)(iVar2 + 9);
  if (iVar8 / (int)(uint)*(byte *)(param_1 + 0x15) + 1 <= local_8) {
    uVar6 = (uint)bVar1;
    if (bVar1 < 2) {
      uVar6 = 2;
    }
    *param_4 = (fVar3 + _K_ONE) * fVar4 -
               ((float)*(byte *)(uVar6 + local_8 + 9 + iVar2) * 1.4117647 - 180.0) * fVar3;
    return;
  }
  uVar6 = (uint)bVar1;
  if (bVar1 < 2) {
    uVar6 = 2;
  }
  *param_4 = (_K_ONE - fVar3) * fVar4 +
             ((float)*(byte *)(uVar6 + local_8 + 0xb + iVar2) * 1.4117647 - 180.0) * fVar3;
  return;
}


// ==== 0x62b0d0 FUN_0062b0d0

void __fastcall FUN_0062b0d0(undefined4 *param_1)

{
  uint uVar1;
  
  *param_1 = &PTR_FUN_006a7e08;
  if (param_1[4] != 0) {
    uVar1 = (uint)*(ushort *)(param_1[3] + 8);
    while (uVar1 = uVar1 - 1, -1 < (int)uVar1) {
      (**(code **)(*DAT_0070d364 + 0x2c))(*(undefined4 *)(param_1[4] + uVar1 * 4));
    }
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[4]);
  }
  FUN_00628ed0();
  return;
}


// ==== 0x62b120 FUN_0062b120

void __thiscall FUN_0062b120(int param_1,int param_2)

{
  uint uVar1;
  
  *(int *)(param_1 + 0xc) = param_2;
  if (*(int *)(param_1 + 0x10) != 0) {
    uVar1 = (uint)*(ushort *)(param_2 + 8);
    while (uVar1 = uVar1 - 1, -1 < (int)uVar1) {
      (**(code **)(*DAT_0070d364 + 0x2c))(*(undefined4 *)(*(int *)(param_1 + 0x10) + uVar1 * 4));
    }
    (**(code **)(*DAT_0070d364 + 0x18))(*(undefined4 *)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


// ==== 0x62b170 FUN_0062b170

undefined4 __fastcall FUN_0062b170(int param_1)

{
  return *(undefined4 *)(*(int *)(param_1 + 0xc) + 4);
}


// ==== 0x62b180 FUN_0062b180

void __fastcall FUN_0062b180(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar1 = *(int *)(param_1 + 0xc);
  uVar2 = (**(code **)(*DAT_0070d364 + 0x14))((uint)*(ushort *)(iVar1 + 8) << 2);
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  iVar3 = *(ushort *)(iVar1 + 8) - 1;
  if (-1 < iVar3) {
    puVar4 = (undefined4 *)(iVar1 + 0xc + iVar3 * 4);
    do {
      uVar2 = (**(code **)(*DAT_0070d364 + 0x24))(*puVar4);
      *(undefined4 *)(*(int *)(param_1 + 0x10) + iVar3 * 4) = uVar2;
      iVar3 = iVar3 + -1;
      puVar4 = puVar4 + -1;
    } while (-1 < iVar3);
  }
  return;
}


// ==== 0x62b1d0 FUN_0062b1d0

void __thiscall FUN_0062b1d0(int param_1,float param_2,float param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0x10) == 0) {
    FUN_0062b180();
  }
  if (*(char *)(param_1 + 0x14) != '\0') {
    param_2 = param_2 * (float)*(byte *)(param_1 + 0x15);
    param_3 = (float)*(byte *)(param_1 + 0x15) * param_3;
  }
  uVar2 = (uint)*(ushort *)(iVar1 + 8);
  while (uVar2 = uVar2 - 1, -1 < (int)uVar2) {
    (**(code **)(**(int **)(*(int *)(param_1 + 0x10) + uVar2 * 4) + 0xc))(param_2,param_3,param_4);
  }
  return;
}


// ==== 0x62b240 FUN_0062b240

byte __thiscall
FUN_0062b240(int param_1,float param_2,float param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0xc);
  bVar3 = 0;
  if (*(int *)(param_1 + 0x10) == 0) {
    FUN_0062b180();
  }
  if (*(char *)(param_1 + 0x14) != '\0') {
    param_2 = param_2 * (float)*(byte *)(param_1 + 0x15);
    param_3 = (float)*(byte *)(param_1 + 0x15) * param_3;
  }
  uVar4 = (uint)*(ushort *)(iVar1 + 8);
  while (uVar4 = uVar4 - 1, -1 < (int)uVar4) {
    bVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x10) + uVar4 * 4) + 0x24))
                      (param_2,param_3,param_4,param_5);
    bVar3 = bVar3 | bVar2;
  }
  return bVar3;
}


// ==== 0x62b2c0 FUN_0062b2c0

byte __thiscall FUN_0062b2c0(int param_1,float param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0xc);
  bVar3 = 0;
  if (*(int *)(param_1 + 0x10) == 0) {
    FUN_0062b180();
  }
  if (*(char *)(param_1 + 0x14) != '\0') {
    param_2 = (float)*(byte *)(param_1 + 0x15) * param_2;
  }
  uVar4 = (uint)*(ushort *)(iVar1 + 8);
  while (uVar4 = uVar4 - 1, -1 < (int)uVar4) {
    bVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x10) + uVar4 * 4) + 0x18))
                      (param_2,param_3,param_4);
    bVar3 = bVar3 | bVar2;
  }
  return bVar3;
}


// ==== 0x62b330 FUN_0062b330

byte __thiscall FUN_0062b330(int param_1,float param_2,undefined4 param_3)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0xc);
  bVar3 = 0;
  if (*(int *)(param_1 + 0x10) == 0) {
    FUN_0062b180();
  }
  if (*(char *)(param_1 + 0x14) != '\0') {
    param_2 = (float)*(byte *)(param_1 + 0x15) * param_2;
  }
  uVar4 = (uint)*(ushort *)(iVar1 + 8);
  while (uVar4 = uVar4 - 1, -1 < (int)uVar4) {
    bVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x10) + uVar4 * 4) + 0x28))(param_2,param_3);
    bVar3 = bVar3 | bVar2;
  }
  return bVar3;
}


// ==== 0x62b390 FUN_0062b390

byte __thiscall FUN_0062b390(int param_1,float param_2,undefined4 param_3)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0xc);
  bVar3 = 0;
  if (*(int *)(param_1 + 0x10) == 0) {
    FUN_0062b180();
  }
  if (*(char *)(param_1 + 0x14) != '\0') {
    param_2 = (float)*(byte *)(param_1 + 0x15) * param_2;
  }
  uVar4 = (uint)*(ushort *)(iVar1 + 8);
  while (uVar4 = uVar4 - 1, -1 < (int)uVar4) {
    bVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x10) + uVar4 * 4) + 0x20))(param_2,param_3);
    bVar3 = bVar3 | bVar2;
  }
  return bVar3;
}


// ==== 0x62b3f0 FUN_0062b3f0

byte __thiscall FUN_0062b3f0(int param_1,float param_2,undefined4 param_3)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0xc);
  bVar3 = 0;
  if (*(int *)(param_1 + 0x10) == 0) {
    FUN_0062b180();
  }
  if (*(char *)(param_1 + 0x14) != '\0') {
    param_2 = (float)*(byte *)(param_1 + 0x15) * param_2;
  }
  uVar4 = (uint)*(ushort *)(iVar1 + 8);
  while (uVar4 = uVar4 - 1, -1 < (int)uVar4) {
    bVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x10) + uVar4 * 4) + 0x2c))(param_2,param_3);
    bVar3 = bVar3 | bVar2;
  }
  return bVar3;
}


// ==== 0x62b450 FUN_0062b450

uint __thiscall FUN_0062b450(int param_1,undefined4 param_2,float param_3,float *param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 0xc);
  if (*(char *)(param_1 + 0x14) != '\0') {
    param_3 = (float)*(byte *)(param_1 + 0x15) * param_3;
  }
  uVar2 = (uint)*(ushort *)(uVar1 + 8);
  do {
    uVar2 = uVar2 - 1;
    if ((int)uVar2 < 0) {
      return uVar1 & 0xffffff00;
    }
    uVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0x10) + uVar2 * 4) + 0x30))
                      (param_2,param_3,param_4);
  } while ((char)uVar1 == '\0');
  uVar1 = CONCAT31((int3)(uVar1 >> 8),*(char *)(param_1 + 0x14));
  if (*(char *)(param_1 + 0x14) != '\0') {
    uVar1 = (uint)*(byte *)(param_1 + 0x15);
    *param_4 = *param_4 / (float)uVar1;
  }
  return CONCAT31((int3)(uVar1 >> 8),1);
}


// ==== 0x62b4d0 FUN_0062b4d0

byte __thiscall FUN_0062b4d0(int param_1,float param_2,undefined4 param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  
  bVar2 = 0;
  if (*(char *)(param_1 + 0x14) != '\0') {
    param_2 = (float)*(byte *)(param_1 + 0x15) * param_2;
  }
  uVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0xc) + 8);
  while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
    bVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0x10) + uVar3 * 4) + 0x1c))(param_2,param_3);
    bVar2 = bVar2 | bVar1;
  }
  return bVar2;
}


// ==== 0x62b530 FUN_0062b530

void FUN_0062b530(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  uVar1 = (uint)*(ushort *)(param_1 + 8);
  if (-1 < (int)(uVar1 - 1)) {
    puVar2 = (undefined4 *)(param_1 + 0xc + (uVar1 - 1) * 4);
    do {
      (**(code **)(*DAT_0070d364 + 0x30))(*puVar2);
      puVar2 = puVar2 + -1;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return;
}


// ==== 0x62b560 FUN_0062b560

int __fastcall FUN_0062b560(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0x10) == 0) {
    FUN_0062b180();
  }
  uVar2 = (uint)*(ushort *)(iVar1 + 8);
  do {
    uVar2 = uVar2 - 1;
    if ((int)uVar2 < 0) {
      return 0;
    }
    iVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0x10) + uVar2 * 4) + 0x34))();
  } while (iVar1 == 0);
  return iVar1;
}


// ==== 0x62b5a0 FUN_0062b5a0

void __thiscall FUN_0062b5a0(int *param_1,char param_2)

{
  char cVar1;
  int iVar2;
  
  *(char *)(param_1 + 5) = param_2;
  if ((*(char *)((int)param_1 + 0x15) == '\0') && (param_2 != '\0')) {
    iVar2 = (**(code **)(*param_1 + 0x38))();
    if (iVar2 != 0) {
      cVar1 = FUN_006353a0(CONCAT22((short)((uint)&param_2 >> 0x10),1),&param_2);
      if (cVar1 != '\0') {
        *(char *)((int)param_1 + 0x15) = param_2;
      }
    }
  }
  return;
}


// ==== 0x62b5f0 FUN_0062b5f0

void __thiscall FUN_0062b5f0(int param_1,uint *param_2,int param_3)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  byte bVar6;
  undefined2 *puVar7;
  int local_4;
  
  iVar3 = param_3;
  iVar1 = *(int *)(param_1 + 0xc);
  uVar4 = 0;
  bVar6 = 0;
  local_4 = 0;
  if (*(char *)(iVar1 + 8) != '\0') {
    puVar7 = (undefined2 *)(iVar1 + 10);
    do {
      bVar2 = (byte)((ushort)*puVar7 >> 8);
      bVar5 = bVar2 >> 3 & 3;
      switch(bVar2 >> 5) {
      case 0:
        bVar6 = bVar6 + 1;
        uVar4 = (byte)((byte)*param_2 >> (8 - bVar6 & 0x1f)) & 1;
        break;
      case 1:
        bVar6 = bVar6 + 2;
        uVar4 = (byte)((byte)*param_2 >> (8 - bVar6 & 0x1f)) & 3;
        break;
      case 2:
        bVar6 = bVar6 + 4;
        uVar4 = (byte)((byte)*param_2 >> (8 - bVar6 & 0x1f)) & 0xf;
        break;
      case 3:
        uVar4 = (uint)(byte)*param_2;
        param_2 = (uint *)((int)param_2 + 1);
        break;
      case 4:
        uVar4 = (uint)(ushort)*param_2;
        param_2 = (uint *)((int)param_2 + 2);
        break;
      case 5:
        uVar4 = *param_2;
        param_2 = param_2 + 1;
      }
      if (7 < bVar6) {
        param_2 = (uint *)((int)param_2 + 1);
        bVar6 = 0;
      }
      param_3._0_1_ = (byte)*puVar7;
      if (bVar5 == 0) {
        *(char *)((uint)(byte)param_3 + iVar3) = (char)uVar4;
      }
      else if (bVar5 == 1) {
        *(short *)((uint)(byte)param_3 + iVar3) = (short)uVar4;
      }
      else if (bVar5 == 3) {
        *(uint *)((uint)(byte)param_3 + iVar3) = uVar4;
      }
      local_4 = local_4 + 1;
      puVar7 = puVar7 + 1;
    } while (local_4 < (int)(uint)*(byte *)(iVar1 + 8));
  }
  return;
}


// ==== 0x62b700 FUN_0062b700

undefined4 __thiscall FUN_0062b700(int param_1,float param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = *(int *)(param_1 + 0xc);
  uVar5 = (uint)*(byte *)(iVar1 + 8);
  bVar3 = *(byte *)(iVar1 + 8) & 1;
  iVar6 = iVar1 + 10 + uVar5 * 2;
  if (bVar3 == 0) {
    iVar6 = iVar1 + 0xc + uVar5 * 2;
  }
  uVar4 = (uint)*(byte *)(iVar1 + 9);
  iVar7 = *(int *)(param_1 + 0x10);
  if (param_2 < *(float *)(iVar6 + iVar7 * uVar4)) {
    iVar7 = iVar7 + -1;
    if (-1 < iVar7) {
      iVar6 = uVar4 * iVar7;
      do {
        iVar2 = iVar1 + 10 + uVar5 * 2;
        if (bVar3 == 0) {
          iVar2 = iVar1 + 0xc + uVar5 * 2;
        }
        if ((float)(iVar2 + iVar6) <= param_2) {
          FUN_0062b5f0(iVar2 + iVar6 + 4,param_3);
          *(int *)(param_1 + 0x10) = iVar7;
          return 1;
        }
        iVar7 = iVar7 + -1;
        iVar6 = iVar6 - uVar4;
      } while (-1 < iVar7);
    }
    if (bVar3 == 0) {
      iVar6 = iVar1 + 0xc + uVar5 * 2;
    }
    else {
      iVar6 = iVar1 + 10 + uVar5 * 2;
    }
    FUN_0062b5f0(iVar6 + 4,param_3);
    *(undefined4 *)(param_1 + 0x10) = 0;
    return 1;
  }
  if (iVar7 < (int)(uint)*(ushort *)(iVar1 + 6)) {
    iVar6 = uVar4 * iVar7;
    do {
      iVar2 = iVar1 + 10 + uVar5 * 2;
      if (bVar3 == 0) {
        iVar2 = iVar1 + 0xc + uVar5 * 2;
      }
      if (param_2 < *(float *)(uVar4 + iVar6 + iVar2)) {
        FUN_0062b5f0(iVar6 + iVar2 + 4,param_3);
        *(int *)(param_1 + 0x10) = iVar7;
        return 1;
      }
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + uVar4;
    } while (iVar7 < (int)(uint)*(ushort *)(iVar1 + 6));
  }
  if (bVar3 == 0) {
    iVar6 = iVar1 + 0xc + uVar5 * 2;
  }
  else {
    iVar6 = iVar1 + 10 + uVar5 * 2;
  }
  FUN_0062b5f0((*(ushort *)(iVar1 + 6) - 1) * uVar4 + 4 + iVar6,param_3);
  *(uint *)(param_1 + 0x10) = *(ushort *)(iVar1 + 6) - 1;
  return 1;
}


// ==== 0x62b880 FUN_0062b880

undefined4 __thiscall FUN_0062b880(int param_1,undefined4 *param_2,float param_3,float *param_4)

{
  float fVar1;
  byte bVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_50 [80];
  
  iVar3 = *(int *)(param_1 + 0xc);
  iVar7 = 0;
  if (*(short *)(iVar3 + 6) != 0) {
    do {
      bVar2 = *(byte *)(iVar3 + 8);
      if ((bVar2 & 1) == 0) {
        iVar5 = iVar3 + 0xc + (uint)bVar2 * 2;
      }
      else {
        iVar5 = iVar3 + 10 + (uint)bVar2 * 2;
      }
      iVar6 = (uint)*(byte *)(iVar3 + 9) * iVar7;
      fVar1 = *(float *)(iVar6 + iVar5);
      if (fVar1 < param_3 == (fVar1 == param_3)) {
        FUN_0062b5f0(iVar6 + iVar5 + 4,auStack_50);
        cVar4 = (**(code **)*param_2)(auStack_50);
        if (cVar4 != '\0') {
          *param_4 = fVar1;
          return 1;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)(uint)*(ushort *)(iVar3 + 6));
  }
  return 0;
}


// ==== 0x62b920 FUN_0062b920

void FUN_0062b920(int param_1)

{
  undefined4 local_18;
  
  FUN_006353d0();
  *(undefined4 *)(param_1 + -0x18) = local_18;
  FUN_006353f0();
  return;
}


// ==== 0x62b950 FUN_0062b950

void FUN_0062b950(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_18;
  
  FUN_00636b20();
  *(int *)(param_1 + -0x18) = local_18;
  FUN_00636b40();
  iVar2 = *(int *)(param_1 + 0x10);
  if (iVar2 != 0) {
    piVar1 = (int *)(iVar2 + -0x18);
    FUN_006353d0();
    *piVar1 = local_18;
    FUN_006353f0();
    (**(code **)(*piVar1 + 0x3c))(iVar2);
    *(int **)(param_1 + 0x10) = piVar1;
  }
  return;
}


// ==== 0x62b9b0 FUN_0062b9b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0062b9b0(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  
  fVar4 = (float10)fcos((float10)*param_1 * (float10)_K_HALF);
  fVar5 = (float10)fcos((float10)param_1[1] * (float10)_K_HALF);
  fVar1 = (float)fVar5;
  fVar5 = (float10)fcos((float10)(param_1[2] * _K_HALF));
  fVar6 = (float10)fsin((float10)*param_1 * (float10)_K_HALF);
  fVar7 = (float10)fsin((float10)param_1[1] * (float10)_K_HALF);
  fVar8 = (float10)fsin((float10)(param_1[2] * _K_HALF));
  fVar3 = (float)fVar5 * (float)fVar4;
  fVar4 = (float10)(float)fVar4 * fVar8;
  fVar5 = (float10)(float)fVar6 * (float10)(float)fVar5;
  fVar2 = (float)(fVar8 * (float10)(float)fVar6);
  *param_2 = (float)((float10)fVar1 * fVar5 - fVar4 * fVar7);
  param_2[1] = (float)((float10)fVar2 * (float10)fVar1 + (float10)fVar3 * fVar7);
  param_2[2] = (float)(fVar4 * (float10)fVar1 - fVar5 * fVar7);
  param_2[3] = (float)((float10)fVar3 * (float10)fVar1 + (float10)fVar2 * fVar7);
  return;
}


// ==== 0x62ba70 FUN_0062ba70

void FUN_0062ba70(int *param_1,undefined4 *param_2)

{
  int iVar1;
  
  *param_2 = *(undefined4 *)*param_1;
  iVar1 = *param_1;
  *param_1 = iVar1 + 4;
  param_2[1] = *(undefined4 *)(iVar1 + 4);
  iVar1 = *param_1;
  *param_1 = iVar1 + 4;
  param_2[2] = *(undefined4 *)(iVar1 + 4);
  iVar1 = *param_1;
  *param_1 = iVar1 + 4;
  param_2[3] = *(undefined4 *)(iVar1 + 4);
  *param_1 = *param_1 + 4;
  return;
}


// ==== 0x62bab0 FUN_0062bab0

void FUN_0062bab0(int *param_1,int param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)*param_1;
  iVar1 = *param_1;
  *param_1 = iVar1 + 4;
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(iVar1 + 4);
  iVar1 = *param_1;
  *param_1 = iVar1 + 4;
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(iVar1 + 4);
  *param_1 = *param_1 + 4;
  return;
}


// ==== 0x62bae0 FUN_0062bae0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0062bae0(undefined4 param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  
  _DAT_0070d520 = *(undefined4 *)*param_2;
  iVar1 = *param_2;
  *param_2 = iVar1 + 4;
  _DAT_0070d524 = *(undefined4 *)(iVar1 + 4);
  iVar1 = *param_2;
  *param_2 = iVar1 + 4;
  _DAT_0070d528 = *(undefined4 *)(iVar1 + 4);
  iVar1 = *param_2;
  *param_2 = iVar1 + 4;
  _DAT_0070d52c = *(undefined4 *)(iVar1 + 4);
  *param_2 = *param_2 + 4;
  *param_4 = *(undefined4 *)*param_3;
  iVar1 = *param_3;
  *param_3 = iVar1 + 4;
  param_4[1] = *(undefined4 *)(iVar1 + 4);
  iVar1 = *param_3;
  *param_3 = iVar1 + 4;
  param_4[2] = *(undefined4 *)(iVar1 + 4);
  iVar1 = *param_3;
  *param_3 = iVar1 + 4;
  param_4[3] = *(undefined4 *)(iVar1 + 4);
  *param_3 = *param_3 + 4;
  FUN_00629140();
  return;
}


// ==== 0x62bb70 FUN_0062bb70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0062bb70(float param_1,int *param_2,int *param_3,int param_4)

{
  int iVar1;
  
  _DAT_0070d530 = *(float *)*param_2;
  iVar1 = *param_2;
  *param_2 = iVar1 + 4;
  _DAT_0070d534 = *(float *)(iVar1 + 4);
  iVar1 = *param_2;
  *param_2 = iVar1 + 4;
  _DAT_0070d538 = *(float *)(iVar1 + 4);
  *param_2 = *param_2 + 4;
  *(undefined4 *)(param_4 + 0x10) = *(undefined4 *)*param_3;
  iVar1 = *param_3;
  *param_3 = iVar1 + 4;
  *(undefined4 *)(param_4 + 0x14) = *(undefined4 *)(iVar1 + 4);
  iVar1 = *param_3;
  *param_3 = iVar1 + 4;
  *(undefined4 *)(param_4 + 0x18) = *(undefined4 *)(iVar1 + 4);
  *param_3 = *param_3 + 4;
  *(float *)(param_4 + 0x10) =
       (*(float *)(param_4 + 0x10) - _DAT_0070d530) * param_1 + _DAT_0070d530;
  *(float *)(param_4 + 0x14) =
       (*(float *)(param_4 + 0x14) - _DAT_0070d534) * param_1 + _DAT_0070d534;
  *(float *)(param_4 + 0x18) =
       (*(float *)(param_4 + 0x18) - _DAT_0070d538) * param_1 + _DAT_0070d538;
  return;
}


// ==== 0x62bc20 FUN_0062bc20

void FUN_0062bc20(undefined4 *param_1,undefined4 param_2)

{
  float *pfVar1;
  float local_c;
  float local_8;
  float local_4;
  
  pfVar1 = (float *)*param_1;
  local_c = *pfVar1;
  *param_1 = pfVar1 + 1;
  local_c = local_c * 0.017453294;
  local_8 = pfVar1[1];
  *param_1 = pfVar1 + 2;
  local_8 = local_8 * 0.017453294;
  local_4 = pfVar1[2];
  *param_1 = pfVar1 + 3;
  local_4 = local_4 * 0.017453294;
  FUN_0062b9b0(&local_c,param_2);
  return;
}


// ==== 0x62bc80 FUN_0062bc80

void FUN_0062bc80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0062bc20(param_2,&DAT_0070d520);
  FUN_0062bc20(param_3,param_4);
  FUN_00629140(param_1,&DAT_0070d520,param_4,param_4);
  return;
}


// ==== 0x62bcc0 FUN_0062bcc0

void __thiscall
FUN_0062bcc0(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_4;
  
  iVar5 = *(int *)(param_1 + 4);
  iVar3 = iVar5 * 2 + 4;
  param_4 = param_1 + (*(int *)(param_1 + 8) * param_4 + iVar3) * 4;
  piVar4 = (int *)(param_1 + 0x10 + iVar5 * 4);
  param_3 = param_1 + (*(int *)(param_1 + 8) * param_3 + iVar3) * 4;
  piVar1 = piVar4 + iVar5;
  if (param_6 == 0) {
    if (piVar4 < piVar1) {
      iVar3 = param_5 + 0x10;
      do {
        iVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        if (0 < iVar5) {
          do {
            pcVar2 = (code *)*piVar4;
            piVar4 = piVar4 + 1;
            (*pcVar2)(param_2,&param_3,&param_4,iVar3);
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        iVar3 = iVar3 + 0x30;
      } while (piVar4 < piVar1);
      return;
    }
  }
  else {
    local_4 = 0;
    if (piVar4 < piVar1) {
      iVar3 = param_5 + 0x10;
      do {
        iVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        if ((*(uint *)(param_6 + (local_4 >> 5) * 4) & 1 << ((byte)local_4 & 0x1f)) == 0) {
          if (0 < iVar5) {
            do {
              pcVar2 = (code *)*piVar4;
              piVar4 = piVar4 + 1;
              if ((pcVar2 == FUN_0062bc80) || (pcVar2 == FUN_0062bb70)) {
                param_3 = param_3 + 0xc;
                param_4 = param_4 + 0xc;
              }
              else if (pcVar2 == FUN_0062bae0) {
                param_3 = param_3 + 0x10;
                param_4 = param_4 + 0x10;
              }
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
        }
        else if (0 < iVar5) {
          do {
            pcVar2 = (code *)*piVar4;
            piVar4 = piVar4 + 1;
            (*pcVar2)(param_2,&param_3,&param_4,iVar3);
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        iVar3 = iVar3 + 0x30;
        local_4 = local_4 + 1;
      } while (piVar4 < piVar1);
    }
  }
  return;
}


// ==== 0x62be20 FUN_0062be20

void FUN_0062be20(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar5 = 0;
  piVar4 = (int *)(param_1 + 0x10);
  if (0 < iVar1) {
    do {
      iVar3 = *piVar4;
      piVar4 = piVar4 + 1;
      iVar5 = iVar5 + 1;
      if (0 < iVar3) {
        iVar5 = iVar5 + iVar3;
        do {
          iVar2 = *piVar4;
          if (iVar2 == 0) {
            *piVar4 = (int)FUN_0062ba70;
          }
          else if (iVar2 == 1) {
            *piVar4 = (int)FUN_0062bc20;
          }
          else if (iVar2 == 2) {
            *piVar4 = (int)FUN_0062bab0;
          }
          else {
            _printf_67147f("Bad signature channel type\n");
          }
          piVar4 = piVar4 + 1;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    } while (iVar5 < iVar1);
  }
  iVar5 = 0;
  piVar4 = (int *)(param_1 + 0x10 + *(int *)(param_1 + 4) * 4);
  if (0 < iVar1) {
    do {
      iVar3 = *piVar4;
      piVar4 = piVar4 + 1;
      iVar5 = iVar5 + 1;
      if (0 < iVar3) {
        iVar5 = iVar5 + iVar3;
        do {
          iVar2 = *piVar4;
          if (iVar2 == 0) {
            *piVar4 = (int)FUN_0062bae0;
          }
          else if (iVar2 == 1) {
            *piVar4 = (int)FUN_0062bc80;
          }
          else if (iVar2 == 2) {
            *piVar4 = (int)FUN_0062bb70;
          }
          else {
            _printf_67147f("Bad signature channel type\n");
          }
          piVar4 = piVar4 + 1;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    } while (iVar5 < iVar1);
  }
  return;
}


// ==== 0x62bef0 FUN_0062bef0

void __thiscall FUN_0062bef0(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  piVar4 = (int *)(param_1 + 0x10);
  param_2 = param_1 + (*(int *)(param_1 + 8) * param_2 + 4 + *(int *)(param_1 + 4) * 2) * 4;
  piVar1 = piVar4 + *(int *)(param_1 + 4);
  if (param_4 == 0) {
    if (piVar4 < piVar1) {
      iVar3 = param_3 + 0x10;
      do {
        iVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        if (0 < iVar5) {
          do {
            pcVar2 = (code *)*piVar4;
            piVar4 = piVar4 + 1;
            (*pcVar2)(&param_2,iVar3);
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        iVar3 = iVar3 + 0x30;
      } while (piVar4 < piVar1);
      return;
    }
  }
  else {
    iVar3 = 0;
    if (piVar4 < piVar1) {
      iVar5 = param_3 + 0x10;
      do {
        iVar6 = *piVar4;
        piVar4 = piVar4 + 1;
        if ((*(uint *)(param_4 + (iVar3 >> 5) * 4) & 1 << ((byte)iVar3 & 0x1f)) == 0) {
          if (0 < iVar6) {
            do {
              pcVar2 = (code *)*piVar4;
              piVar4 = piVar4 + 1;
              if ((pcVar2 == FUN_0062bc20) || (pcVar2 == FUN_0062bab0)) {
                param_2 = param_2 + 0xc;
              }
              else if (pcVar2 == FUN_0062ba70) {
                param_2 = param_2 + 0x10;
              }
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
        }
        else if (0 < iVar6) {
          do {
            pcVar2 = (code *)*piVar4;
            piVar4 = piVar4 + 1;
            (*pcVar2)(&param_2,iVar5);
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
        iVar5 = iVar5 + 0x30;
        iVar3 = iVar3 + 1;
      } while (piVar4 < piVar1);
    }
  }
  return;
}


// ==== 0x62c010 FUN_0062c010

void __thiscall
FUN_0062c010(int param_1,float param_2,undefined4 param_3,char param_4,undefined4 param_5)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 < 0.0) {
    fVar1 = param_2 + 0.499999;
  }
  else {
    fVar1 = param_2 - 0.499999;
  }
  iVar3 = (int)ROUND(fVar1);
  if (iVar3 < 0) {
    FUN_0062bef0(0,param_3,param_5);
    return;
  }
  iVar2 = *(int *)(param_1 + 0xc) + -1;
  if (iVar2 <= iVar3) {
    FUN_0062bef0(iVar2,param_3,param_5);
    return;
  }
  if ((param_2 - (float)iVar3 != 0.0) && (param_4 != '\0')) {
    FUN_0062bcc0(param_2 - (float)iVar3,iVar3,iVar3 + 1,param_3,param_5);
    return;
  }
  FUN_0062bef0(iVar3,param_3,param_5);
  return;
}


// ==== 0x62c100 FUN_0062c100

undefined4 * __fastcall FUN_0062c100(undefined4 *param_1)

{
  FUN_00628eb0();
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  *param_1 = &PTR_FUN_006a8198;
  param_1[4] = 0xffffffff;
  param_1[7] = 0xffffffff;
  param_1[2] = 0x15;
  return param_1;
}


// ==== 0x62c130 FUN_0062c130

undefined4 __thiscall FUN_0062c130(int param_1,float *param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar1 + 8) == 0) {
    uVar2 = CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0xc));
  }
  else {
    uVar2 = (uint)(ushort)(*(short *)(*(int *)(iVar1 + 8) + -4 + (uint)*(ushort *)(iVar1 + 0xc) * 2)
                          + 1);
  }
  *param_2 = (float)(uVar2 & 0xffff);
  return CONCAT31((int3)(uVar2 >> 8),1);
}


// ==== 0x62c170 FUN_0062c170

void __fastcall FUN_0062c170(int param_1)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = *(int *)(param_1 + 0xc);
  if (*(ushort *)(iVar2 + 0xe) != 0) {
    uVar4 = (**(code **)(*DAT_0070d364 + 0x14))((uint)*(ushort *)(iVar2 + 0xe) << 2);
    *(undefined4 *)(param_1 + 0x18) = uVar4;
    *(undefined4 *)(param_1 + 0x14) = uVar4;
    uVar4 = (**(code **)(*DAT_0070d364 + 0x14))((uint)*(ushort *)(iVar2 + 0xe) << 2);
    *(undefined4 *)(param_1 + 0x24) = uVar4;
    *(undefined4 *)(param_1 + 0x20) = uVar4;
    uVar4 = (**(code **)(*DAT_0070d364 + 0x14))((uint)*(ushort *)(iVar2 + 0xe) << 4);
    *(undefined4 *)(param_1 + 0x2c) = uVar4;
    iVar7 = 0;
    if (*(short *)(iVar2 + 0xe) != 0) {
      iVar6 = 0;
      puVar5 = (undefined4 *)(iVar2 + 0x14);
      do {
        *(undefined4 *)(iVar6 + *(int *)(param_1 + 0x2c)) = *puVar5;
        *(undefined4 *)(iVar6 + 4 + *(int *)(param_1 + 0x2c)) = puVar5[1];
        iVar7 = iVar7 + 1;
        *(float *)(iVar6 + 4 + *(int *)(param_1 + 0x2c)) =
             *(float *)(iVar6 + 4 + *(int *)(param_1 + 0x2c)) * 1.5259022e-05;
        fVar3 = (float)*(ushort *)(puVar5 + 2) * (float)puVar5[1] * 1.5259022e-05;
        *(float *)(iVar6 + 8 + *(int *)(param_1 + 0x2c)) = (fVar3 + fVar3) - (float)puVar5[1];
        fVar3 = (float)*(ushort *)((int)puVar5 + 10) * (float)puVar5[1] * 1.5259022e-05;
        *(float *)(iVar6 + 0xc + *(int *)(param_1 + 0x2c)) = fVar3 + fVar3;
        pfVar1 = (float *)(iVar6 + 0xc + *(int *)(param_1 + 0x2c));
        iVar6 = iVar6 + 0x10;
        *pfVar1 = *pfVar1 * 0.003921569;
        puVar5 = puVar5 + 3;
      } while (iVar7 < (int)(uint)*(ushort *)(iVar2 + 0xe));
    }
  }
  return;
}


// ==== 0x62c280 FUN_0062c280

undefined4 __thiscall FUN_0062c280(undefined4 param_1,byte param_2)

{
  FUN_0062c2b0();
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x30);
  }
  return param_1;
}


// ==== 0x62c2b0 FUN_0062c2b0

void __fastcall FUN_0062c2b0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a8198;
  if (param_1[6] != 0) {
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[5]);
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[8]);
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[0xb]);
  }
  FUN_00628ed0();
  return;
}


// ==== 0x62c300 FUN_0062c300

undefined4 __thiscall FUN_0062c300(int param_1,float param_2,uint param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  float fVar4;
  bool bVar5;
  undefined2 uVar8;
  uint3 uVar7;
  uint uVar6;
  uint uVar9;
  int iVar10;
  float *pfVar11;
  uint uVar12;
  byte *pbVar13;
  ushort *puVar14;
  ushort *puVar15;
  undefined4 *puVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  byte *pbVar22;
  ushort uVar23;
  float local_80;
  ushort *local_7c;
  byte *local_78;
  int local_74;
  int local_68;
  int local_64;
  uint local_60;
  byte local_50 [80];
  
  if (param_4 != *(int *)(param_1 + 0x28)) {
    *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
    *(int *)(param_1 + 0x28) = param_4;
  }
  iVar2 = *(int *)(param_1 + 0xc);
  if (param_2 < 0.0) {
    fVar4 = param_2 + 0.499999;
  }
  else {
    fVar4 = param_2 - 0.499999;
  }
  local_60 = (uint)ROUND(fVar4);
  puVar15 = *(ushort **)(iVar2 + 8);
  if (puVar15 == (ushort *)0x0) {
    if ((int)local_60 < 0) {
      uVar18 = 0;
    }
    else {
      uVar18 = local_60;
      if ((int)(uint)*(ushort *)(iVar2 + 0xc) <= (int)local_60) {
        uVar18 = *(ushort *)(iVar2 + 0xc) - 1;
      }
    }
  }
  else if ((int)local_60 < (int)(uint)*puVar15) {
    uVar18 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x10) < 1) {
      iVar20 = 0;
    }
    else {
      iVar20 = *(int *)(param_1 + 0x10) + -1;
    }
    puVar14 = puVar15 + iVar20;
    if ((int)local_60 < (int)(uint)puVar15[iVar20]) {
      for (; (0 < iVar20 && ((int)local_60 < (int)(uint)*puVar14)); puVar14 = puVar14 + -1) {
        iVar20 = iVar20 + -1;
      }
    }
    else {
      while ((iVar20 < (int)(*(ushort *)(iVar2 + 0xc) - 2) &&
             (puVar14 = puVar14 + 1, (int)(uint)*puVar14 <= (int)local_60))) {
        iVar20 = iVar20 + 1;
      }
    }
    uVar18 = iVar20 + 1;
  }
  bVar1 = *(byte *)(iVar2 + 0x10);
  uVar6 = *(uint *)(param_1 + 0x10);
  uVar19 = 0x7fffffff >> (0x1f - bVar1 & 0x1f);
  uVar12 = (int)uVar18 >> (bVar1 & 0x1f);
  uVar9 = uVar19 & uVar18;
  uVar17 = (uint)*(ushort *)(iVar2 + 0xe);
  iVar20 = iVar2 + (((1 << (bVar1 & 0x1f)) + 1) * uVar17 + 1 & 0xfffffffe) * uVar12 + 0x14 +
           uVar17 * 0xc;
  iVar10 = 0;
  if (uVar17 != 0) {
    do {
      local_50[iVar10] = (byte)(*(ushort *)(*(int *)(iVar2 + 4) + iVar10 * 2) / 0xc);
      iVar10 = iVar10 + 1;
    } while (iVar10 < (int)uVar17);
  }
  if (((int)uVar6 <= (int)uVar18) || (bVar5 = true, DAT_006e58d8 != '\0')) {
    bVar5 = false;
  }
  if (uVar18 == *(uint *)(param_1 + 0x1c)) {
    uVar3 = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x24) = uVar3;
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  }
  else {
    if (((uVar6 == 0xffffffff) || (uVar12 != (int)uVar6 >> (bVar1 & 0x1f))) || (bVar5)) {
      iVar10 = 0;
      if (uVar17 != 0) {
        iVar21 = 0;
        do {
          if ((*(uint *)(param_4 + ((int)(uint)local_50[iVar10] >> 5) * 4) &
              1 << (local_50[iVar10] & 0x1f)) != 0) {
            pfVar11 = (float *)(*(int *)(param_1 + 0x2c) + iVar21);
            *(float *)(*(int *)(param_1 + 0x18) + iVar10 * 4) =
                 (float)*(ushort *)(iVar20 + iVar10 * 2) * pfVar11[1] + *pfVar11;
          }
          iVar10 = iVar10 + 1;
          iVar21 = iVar21 + 0x10;
        } while (iVar10 < (int)(uint)*(ushort *)(iVar2 + 0xe));
      }
      uVar6 = 0;
    }
    else {
      uVar6 = uVar6 & uVar19;
    }
    if ((int)uVar6 < (int)uVar9) {
      uVar19 = (uint)*(ushort *)(iVar2 + 0xe);
      pbVar22 = (byte *)((uVar6 + 2) * uVar19 + iVar20);
      local_78 = local_50 + -(int)pbVar22;
      local_74 = uVar9 - uVar6;
      do {
        iVar20 = 0;
        if (uVar19 != 0) {
          iVar10 = 0;
          pbVar13 = pbVar22;
          do {
            if ((*(uint *)(param_4 + ((int)(uint)pbVar13[(int)local_78] >> 5) * 4) &
                1 << (pbVar13[(int)local_78] & 0x1f)) != 0) {
              iVar21 = *(int *)(param_1 + 0x2c) + iVar10;
              pfVar11 = (float *)(*(int *)(param_1 + 0x18) + iVar20 * 4);
              *pfVar11 = (float)*pbVar13 * *(float *)(iVar21 + 0xc) + *(float *)(iVar21 + 8) +
                         *pfVar11;
            }
            uVar19 = (uint)*(ushort *)(iVar2 + 0xe);
            iVar20 = iVar20 + 1;
            iVar10 = iVar10 + 0x10;
            pbVar13 = pbVar13 + 1;
          } while (iVar20 < (int)uVar19);
        }
        pbVar22 = pbVar22 + uVar17;
        local_78 = local_78 + -uVar17;
        local_74 = local_74 + -1;
      } while (local_74 != 0);
    }
    else if ((int)uVar9 < (int)uVar6) {
      uVar19 = (uint)*(ushort *)(iVar2 + 0xe);
      pbVar22 = (byte *)((uVar6 + 1) * uVar19 + iVar20);
      if ((int)uVar9 <= (int)(uVar6 - 1)) {
        local_78 = local_50 + -(int)pbVar22;
        local_74 = ((uVar6 - 1) - uVar9) + 1;
        do {
          iVar20 = 0;
          if (uVar19 != 0) {
            iVar10 = 0;
            pbVar13 = pbVar22;
            do {
              if ((*(uint *)(param_4 + ((int)(uint)pbVar13[(int)local_78] >> 5) * 4) &
                  1 << (pbVar13[(int)local_78] & 0x1f)) != 0) {
                iVar21 = *(int *)(param_1 + 0x2c) + iVar10;
                pfVar11 = (float *)(*(int *)(param_1 + 0x18) + iVar20 * 4);
                *pfVar11 = *pfVar11 -
                           ((float)*pbVar13 * *(float *)(iVar21 + 0xc) + *(float *)(iVar21 + 8));
              }
              uVar19 = (uint)*(ushort *)(iVar2 + 0xe);
              iVar20 = iVar20 + 1;
              iVar10 = iVar10 + 0x10;
              pbVar13 = pbVar13 + 1;
            } while (iVar20 < (int)uVar19);
          }
          pbVar22 = pbVar22 + -uVar17;
          local_78 = local_78 + uVar17;
          local_74 = local_74 + -1;
        } while (local_74 != 0);
      }
    }
  }
  *(uint *)(param_1 + 0x10) = uVar18;
  puVar15 = *(ushort **)(iVar2 + 8);
  iVar20 = uVar18 + 1;
  local_80 = 1.0;
  uVar8 = (undefined2)((uint)param_1 >> 0x10);
  if (puVar15 == (ushort *)0x0) {
    fVar4 = (float)(int)local_60;
    uVar6 = CONCAT22(uVar8,(ushort)(param_2 < fVar4) << 8 |
                           (ushort)(NAN(param_2) || NAN(fVar4)) << 10 |
                           (ushort)(param_2 == fVar4) << 0xe);
    if (param_2 != fVar4) {
      uVar7 = (uint3)(uVar6 >> 8);
      local_80 = param_2 - fVar4;
LAB_0062c7b7:
      uVar6 = CONCAT31(uVar7,1);
    }
  }
  else if (uVar18 == 0) {
    uVar7 = (uint3)(CONCAT22(uVar8,(ushort)(param_2 < 0.0) << 8 | (ushort)NAN(param_2) << 10 |
                                   (ushort)(param_2 == 0.0) << 0xe) >> 8);
    if (param_2 == 0.0) {
      uVar6 = (uint)uVar7 << 8;
    }
    else {
      uVar6 = CONCAT31(uVar7,1);
      local_80 = param_2 / (float)*puVar15;
    }
  }
  else {
    fVar4 = (float)puVar15[uVar18 - 1];
    uVar23 = (ushort)(param_2 < fVar4) << 8 | (ushort)(NAN(param_2) || NAN(fVar4)) << 10 |
             (ushort)(param_2 == fVar4) << 0xe;
    uVar6 = (uint)uVar23;
    if (param_2 != fVar4) {
      uVar7 = (uint3)(byte)(uVar23 >> 8);
      local_80 = (param_2 - fVar4) / ((float)puVar15[uVar18] - fVar4);
      goto LAB_0062c7b7;
    }
  }
  local_7c = *(ushort **)(iVar2 + 4);
  if (((char)uVar6 == '\0') || (uVar6 = *(ushort *)(iVar2 + 0xc) - 1, (int)uVar6 <= (int)uVar18)) {
    iVar20 = 0;
    if (*(short *)(iVar2 + 0xe) != 0) {
      do {
        if ((*(uint *)(param_4 + ((int)(uint)local_50[iVar20] >> 5) * 4) &
            1 << (local_50[iVar20] & 0x1f)) != 0) {
          *(undefined4 *)(param_3 + (uint)local_7c[iVar20] * 4) =
               *(undefined4 *)(*(int *)(param_1 + 0x18) + iVar20 * 4);
        }
        uVar6 = (uint)*(ushort *)(iVar2 + 0xe);
        iVar20 = iVar20 + 1;
      } while (iVar20 < (int)uVar6);
    }
  }
  else {
    uVar18 = (uint)*(ushort *)(iVar2 + 0xe);
    uVar6 = iVar20 >> (bVar1 & 0x1f);
    iVar10 = iVar2 + (((1 << (*(byte *)(iVar2 + 0x10) & 0x1f)) + 1) * uVar18 + 1 & 0xfffffffe) *
                     uVar6 + 0x14 + uVar18 * 0xc;
    if (iVar20 == *(int *)(param_1 + 0x1c)) {
      iVar20 = 0;
      if (uVar18 != 0) {
        do {
          uVar6 = (int)(uint)local_50[iVar20] >> 5;
          if ((*(uint *)(param_4 + uVar6 * 4) & 1 << (local_50[iVar20] & 0x1f)) != 0) {
            *(float *)(param_3 + (uint)*local_7c * 4) =
                 (*(float *)(*(int *)(param_1 + 0x24) + iVar20 * 4) -
                 *(float *)(*(int *)(param_1 + 0x18) + iVar20 * 4)) * local_80 +
                 *(float *)(*(int *)(param_1 + 0x18) + iVar20 * 4);
            uVar6 = param_3;
          }
          local_7c = local_7c + 1;
          iVar20 = iVar20 + 1;
        } while (iVar20 < (int)(uint)*(ushort *)(iVar2 + 0xe));
      }
    }
    else {
      if (uVar6 == uVar12) {
        pbVar22 = (byte *)((uVar9 + 2) * uVar18 + iVar10);
        uVar6 = 0;
        if (uVar18 != 0) {
          iVar10 = -(int)pbVar22;
          local_64 = 0;
          do {
            if ((*(uint *)(param_4 + ((int)(uint)pbVar22[(int)(local_50 + iVar10)] >> 5) * 4) &
                1 << (pbVar22[(int)(local_50 + iVar10)] & 0x1f)) != 0) {
              iVar21 = *(int *)(param_1 + 0x2c) + local_64;
              *(float *)(*(int *)(param_1 + 0x24) + uVar6 * 4) =
                   (float)*pbVar22 * *(float *)(iVar21 + 0xc) + *(float *)(iVar21 + 8) +
                   *(float *)(*(int *)(param_1 + 0x18) + uVar6 * 4);
              pfVar11 = (float *)(*(int *)(param_1 + 0x18) + uVar6 * 4);
              *(float *)(param_3 + (uint)*local_7c * 4) =
                   (*(float *)(*(int *)(param_1 + 0x24) + uVar6 * 4) - *pfVar11) * local_80 +
                   *pfVar11;
            }
            local_64 = local_64 + 0x10;
            local_7c = local_7c + 1;
            uVar6 = uVar6 + 1;
            pbVar22 = pbVar22 + 1;
          } while ((int)uVar6 < (int)(uint)*(ushort *)(iVar2 + 0xe));
        }
      }
      else {
        uVar6 = 0;
        if (uVar18 != 0) {
          iVar21 = 0;
          do {
            if ((*(uint *)(param_4 + ((int)(uint)local_50[uVar6] >> 5) * 4) &
                1 << (local_50[uVar6] & 0x1f)) != 0) {
              pfVar11 = (float *)(*(int *)(param_1 + 0x2c) + iVar21);
              *(float *)(*(int *)(param_1 + 0x24) + uVar6 * 4) =
                   (float)*(ushort *)(iVar10 + uVar6 * 2) * pfVar11[1] + *pfVar11;
              pfVar11 = (float *)(*(int *)(param_1 + 0x18) + uVar6 * 4);
              *(float *)(param_3 + (uint)*local_7c * 4) =
                   (*(float *)(*(int *)(param_1 + 0x24) + uVar6 * 4) - *pfVar11) * local_80 +
                   *pfVar11;
            }
            local_7c = local_7c + 1;
            uVar6 = uVar6 + 1;
            iVar21 = iVar21 + 0x10;
          } while ((int)uVar6 < (int)(uint)*(ushort *)(iVar2 + 0xe));
          *(int *)(param_1 + 0x1c) = iVar20;
          goto LAB_0062ca41;
        }
      }
      *(int *)(param_1 + 0x1c) = iVar20;
    }
  }
LAB_0062ca41:
  iVar20 = CONCAT31((int3)(uVar6 >> 8),*(char *)(iVar2 + 0x11));
  if (*(char *)(iVar2 + 0x11) != '\0') {
    bVar1 = *(byte *)(iVar2 + 0x10);
    uVar6 = (uint)*(ushort *)(iVar2 + 0xe);
    puVar15 = (ushort *)
              (iVar2 + (((1 << (bVar1 & 0x1f)) + 1) * uVar6 + 1 & 0xfffffffe) *
                       (uint)(*(ushort *)(iVar2 + 0xc) >> (bVar1 & 0x1f)) + 0x14 + uVar6 * 0xc);
    uVar18 = 0x7fffffffU >> (0x1f - bVar1 & 0x1f) & (uint)*(ushort *)(iVar2 + 0xc);
    puVar14 = puVar15;
    if (uVar18 != 0) {
      puVar14 = (ushort *)((uVar18 + 1) * uVar6 + 1 + (int)puVar15 & 0xfffffffe);
    }
    if (*(short *)(iVar2 + 0xe) == 0) {
      puVar14 = (ushort *)((int)puVar14 + 1U & 0xfffffffe);
    }
    if (uVar18 != 0) {
      puVar15 = (ushort *)((uVar18 + 1) * uVar6 + 1 + (int)puVar15 & 0xfffffffe);
    }
    if (*(short *)(iVar2 + 0xe) == 0) {
      puVar15 = (ushort *)((int)puVar15 + 1U & 0xfffffffe);
    }
    puVar16 = (undefined4 *)((int)puVar15 + (uint)*(byte *)(iVar2 + 0x11) * 2 + 3 & 0xfffffffc);
    local_68 = 0;
    iVar20 = 0;
    if (*(byte *)(iVar2 + 0x11) != 0) {
      do {
        uVar23 = *puVar14;
        uVar18 = uVar23 / 0xc;
        puVar14 = puVar14 + 1;
        if ((*(uint *)(param_4 + ((int)uVar18 >> 5) * 4) & 1 << ((byte)uVar18 & 0x1f)) != 0) {
          *(undefined4 *)(param_3 + (uint)uVar23 * 4) = *puVar16;
        }
        puVar16 = puVar16 + 1;
        iVar20 = local_68 + 1;
        local_68 = iVar20;
      } while (iVar20 < (int)(uint)*(byte *)(iVar2 + 0x11));
    }
  }
  return CONCAT31((int3)((uint)iVar20 >> 8),1);
}


// ==== 0x62cb50 FUN_0062cb50

undefined4 __thiscall FUN_0062cb50(int param_1,float param_2,int param_3,int param_4)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  float fVar4;
  bool bVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  float *pfVar15;
  int iVar16;
  uint uVar17;
  ushort *puVar18;
  int iVar19;
  ushort *puVar20;
  uint uVar21;
  float local_20;
  int local_18;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_0062c170();
  }
  if (param_4 != 0) {
    uVar6 = FUN_0062c300(param_2,param_3,param_4);
    return uVar6;
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  iVar3 = *(int *)(param_1 + 0xc);
  uVar7 = FUN_00629350(param_2);
  puVar20 = *(ushort **)(iVar3 + 8);
  if (puVar20 == (ushort *)0x0) {
    if ((int)uVar7 < 0) {
      uVar21 = 0;
    }
    else {
      uVar21 = uVar7;
      if ((int)(uint)*(ushort *)(iVar3 + 0xc) <= (int)uVar7) {
        uVar21 = *(ushort *)(iVar3 + 0xc) - 1;
      }
    }
  }
  else if ((int)uVar7 < (int)(uint)*puVar20) {
    uVar21 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x10) < 1) {
      iVar16 = 0;
    }
    else {
      iVar16 = *(int *)(param_1 + 0x10) + -1;
    }
    puVar18 = puVar20 + iVar16;
    if ((int)uVar7 < (int)(uint)puVar20[iVar16]) {
      for (; (0 < iVar16 && ((int)uVar7 < (int)(uint)*puVar18)); puVar18 = puVar18 + -1) {
        iVar16 = iVar16 + -1;
      }
    }
    else {
      while ((iVar16 < (int)(*(ushort *)(iVar3 + 0xc) - 2) &&
             (puVar18 = puVar18 + 1, (int)(uint)*puVar18 <= (int)uVar7))) {
        iVar16 = iVar16 + 1;
      }
    }
    uVar21 = iVar16 + 1;
  }
  bVar2 = *(byte *)(iVar3 + 0x10);
  uVar17 = 0x7fffffff >> (0x1f - bVar2 & 0x1f);
  iVar19 = (int)uVar21 >> (bVar2 & 0x1f);
  uVar12 = uVar17 & uVar21;
  uVar13 = *(uint *)(param_1 + 0x10);
  uVar8 = (uint)*(ushort *)(iVar3 + 0xe);
  iVar16 = iVar3 + (((1 << (bVar2 & 0x1f)) + 1) * uVar8 + 1 & 0xfffffffe) * iVar19 + 0x14 +
           uVar8 * 0xc;
  if (((int)uVar13 <= (int)uVar21) || (bVar5 = true, DAT_006e58d8 != '\0')) {
    bVar5 = false;
  }
  if (uVar21 == *(uint *)(param_1 + 0x1c)) {
    uVar6 = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x24) = uVar6;
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  }
  else {
    if ((((uVar13 == 0xffffffff) || (iVar19 != (int)uVar13 >> (bVar2 & 0x1f))) || (uVar12 == 0)) ||
       (bVar5)) {
      iVar14 = 0;
      if (uVar8 != 0) {
        iVar10 = 0;
        do {
          iVar9 = iVar14 * 2;
          pfVar15 = (float *)(*(int *)(param_1 + 0x2c) + iVar10);
          iVar14 = iVar14 + 1;
          iVar10 = iVar10 + 0x10;
          *(float *)(*(int *)(param_1 + 0x18) + -4 + iVar14 * 4) =
               (float)*(ushort *)(iVar16 + iVar9) * pfVar15[1] + *pfVar15;
        } while (iVar14 < (int)(uint)*(ushort *)(iVar3 + 0xe));
      }
      uVar13 = 0;
    }
    else {
      uVar13 = uVar13 & uVar17;
    }
    if ((int)uVar13 < (int)uVar12) {
      uVar17 = (uint)*(ushort *)(iVar3 + 0xe);
      iVar16 = (uVar13 + 2) * uVar17 + iVar16;
      local_18 = uVar12 - uVar13;
      do {
        iVar14 = 0;
        if (uVar17 != 0) {
          iVar10 = 0;
          do {
            pbVar1 = (byte *)(iVar14 + iVar16);
            iVar9 = *(int *)(param_1 + 0x2c) + iVar10;
            pfVar15 = (float *)(*(int *)(param_1 + 0x18) + iVar14 * 4);
            iVar14 = iVar14 + 1;
            iVar10 = iVar10 + 0x10;
            *pfVar15 = (float)*pbVar1 * *(float *)(iVar9 + 0xc) + *(float *)(iVar9 + 8) + *pfVar15;
            uVar17 = (uint)*(ushort *)(iVar3 + 0xe);
          } while (iVar14 < (int)uVar17);
        }
        iVar16 = iVar16 + uVar8;
        local_18 = local_18 + -1;
      } while (local_18 != 0);
    }
    else if ((int)uVar12 < (int)uVar13) {
      uVar17 = (uint)*(ushort *)(iVar3 + 0xe);
      iVar16 = (uVar13 + 1) * uVar17 + iVar16;
      if ((int)uVar12 <= (int)(uVar13 - 1)) {
        local_18 = ((uVar13 - 1) - uVar12) + 1;
        do {
          iVar14 = 0;
          if (uVar17 != 0) {
            iVar10 = 0;
            do {
              pbVar1 = (byte *)(iVar14 + iVar16);
              iVar9 = *(int *)(param_1 + 0x2c) + iVar10;
              pfVar15 = (float *)(*(int *)(param_1 + 0x18) + iVar14 * 4);
              iVar14 = iVar14 + 1;
              iVar10 = iVar10 + 0x10;
              *pfVar15 = *pfVar15 -
                         ((float)*pbVar1 * *(float *)(iVar9 + 0xc) + *(float *)(iVar9 + 8));
              uVar17 = (uint)*(ushort *)(iVar3 + 0xe);
            } while (iVar14 < (int)uVar17);
          }
          iVar16 = iVar16 - uVar8;
          local_18 = local_18 + -1;
        } while (local_18 != 0);
      }
    }
  }
  *(uint *)(param_1 + 0x10) = uVar21;
  puVar20 = *(ushort **)(iVar3 + 8);
  iVar16 = uVar21 + 1;
  local_20 = 1.0;
  if (puVar20 == (ushort *)0x0) {
    if (param_2 == (float)(int)uVar7) {
LAB_0062cf6d:
      bVar5 = false;
    }
    else {
      local_20 = param_2 - (float)(int)uVar7;
LAB_0062cec8:
      bVar5 = true;
    }
  }
  else {
    if (uVar21 != 0) {
      fVar4 = (float)puVar20[uVar21 - 1];
      if (param_2 == fVar4) goto LAB_0062cf6d;
      local_20 = (param_2 - fVar4) / ((float)puVar20[uVar21] - fVar4);
      goto LAB_0062cec8;
    }
    if (param_2 == 0.0) {
      bVar5 = false;
    }
    else {
      bVar5 = true;
      local_20 = param_2 / (float)*puVar20;
    }
  }
  puVar20 = *(ushort **)(iVar3 + 4);
  if ((bVar5) && ((int)uVar21 < (int)(*(ushort *)(iVar3 + 0xc) - 1))) {
    uVar7 = (uint)*(ushort *)(iVar3 + 0xe);
    iVar10 = iVar16 >> (bVar2 & 0x1f);
    iVar14 = iVar3 + (((1 << (*(byte *)(iVar3 + 0x10) & 0x1f)) + 1) * uVar7 + 1 & 0xfffffffe) *
                     iVar10 + 0x14 + uVar7 * 0xc;
    if (iVar16 == *(int *)(param_1 + 0x1c)) {
      iVar19 = 0;
      if (uVar7 != 0) {
        do {
          iVar16 = iVar19 * 4;
          pfVar15 = (float *)(*(int *)(param_1 + 0x18) + iVar19 * 4);
          iVar19 = iVar19 + 1;
          *(float *)(param_3 + (uint)*puVar20 * 4) =
               (*(float *)(*(int *)(param_1 + 0x24) + iVar16) - *pfVar15) * local_20 + *pfVar15;
          puVar20 = puVar20 + 1;
        } while (iVar19 < (int)(uint)*(ushort *)(iVar3 + 0xe));
      }
    }
    else {
      if (iVar10 == iVar19) {
        iVar19 = 0;
        if (uVar7 != 0) {
          param_2 = 0.0;
          do {
            iVar10 = *(int *)(param_1 + 0x2c) + (int)param_2;
            *(float *)(*(int *)(param_1 + 0x24) + iVar19 * 4) =
                 (float)*(byte *)(iVar19 + (uVar12 + 2) * uVar7 + iVar14) * *(float *)(iVar10 + 0xc)
                 + *(float *)(iVar10 + 8) + *(float *)(*(int *)(param_1 + 0x18) + iVar19 * 4);
            iVar10 = iVar19 * 4;
            pfVar15 = (float *)(*(int *)(param_1 + 0x18) + iVar19 * 4);
            iVar19 = iVar19 + 1;
            *(float *)(param_3 + (uint)*puVar20 * 4) =
                 (*(float *)(*(int *)(param_1 + 0x24) + iVar10) - *pfVar15) * local_20 + *pfVar15;
            param_2 = (float)((int)param_2 + 0x10);
            puVar20 = puVar20 + 1;
          } while (iVar19 < (int)(uint)*(ushort *)(iVar3 + 0xe));
          *(int *)(param_1 + 0x1c) = iVar16;
          goto LAB_0062d0a6;
        }
      }
      else {
        iVar19 = 0;
        if (uVar7 != 0) {
          param_2 = 0.0;
          do {
            pfVar15 = (float *)(*(int *)(param_1 + 0x2c) + (int)param_2);
            *(float *)(*(int *)(param_1 + 0x24) + iVar19 * 4) =
                 (float)*(ushort *)(iVar14 + iVar19 * 2) * pfVar15[1] + *pfVar15;
            iVar10 = iVar19 * 4;
            pfVar15 = (float *)(*(int *)(param_1 + 0x18) + iVar19 * 4);
            iVar19 = iVar19 + 1;
            *(float *)(param_3 + (uint)*puVar20 * 4) =
                 (*(float *)(*(int *)(param_1 + 0x24) + iVar10) - *pfVar15) * local_20 + *pfVar15;
            param_2 = (float)((int)param_2 + 0x10);
            puVar20 = puVar20 + 1;
          } while (iVar19 < (int)(uint)*(ushort *)(iVar3 + 0xe));
          *(int *)(param_1 + 0x1c) = iVar16;
          goto LAB_0062d0a6;
        }
      }
      iVar19 = 0;
      *(int *)(param_1 + 0x1c) = iVar16;
    }
  }
  else {
    iVar19 = 0;
    if (*(short *)(iVar3 + 0xe) != 0) {
      do {
        *(undefined4 *)(param_3 + (uint)puVar20[iVar19] * 4) =
             *(undefined4 *)(*(int *)(param_1 + 0x18) + iVar19 * 4);
        iVar19 = iVar19 + 1;
      } while (iVar19 < (int)(uint)*(ushort *)(iVar3 + 0xe));
    }
  }
LAB_0062d0a6:
  puVar11 = (undefined4 *)CONCAT31((int3)((uint)iVar19 >> 8),*(char *)(iVar3 + 0x11));
  if (*(char *)(iVar3 + 0x11) != '\0') {
    bVar2 = *(byte *)(iVar3 + 0x10);
    uVar21 = (uint)*(ushort *)(iVar3 + 0xe);
    puVar20 = (ushort *)
              (iVar3 + (((1 << (bVar2 & 0x1f)) + 1) * uVar21 + 1 & 0xfffffffe) *
                       (uint)(*(ushort *)(iVar3 + 0xc) >> (bVar2 & 0x1f)) + 0x14 + uVar21 * 0xc);
    uVar7 = 0x7fffffffU >> (0x1f - bVar2 & 0x1f) & (uint)*(ushort *)(iVar3 + 0xc);
    puVar18 = puVar20;
    if (uVar7 != 0) {
      puVar18 = (ushort *)((uVar7 + 1) * uVar21 + 1 + (int)puVar20 & 0xfffffffe);
    }
    if (*(short *)(iVar3 + 0xe) == 0) {
      puVar18 = (ushort *)((int)puVar18 + 1U & 0xfffffffe);
    }
    if (uVar7 != 0) {
      puVar20 = (ushort *)((uVar7 + 1) * uVar21 + 1 + (int)puVar20 & 0xfffffffe);
    }
    if (*(short *)(iVar3 + 0xe) == 0) {
      puVar20 = (ushort *)((int)puVar20 + 1U & 0xfffffffe);
    }
    puVar11 = (undefined4 *)((int)puVar20 + (uint)*(byte *)(iVar3 + 0x11) * 2 + 3 & 0xfffffffc);
    iVar16 = 0;
    if (*(byte *)(iVar3 + 0x11) != 0) {
      do {
        *(undefined4 *)(param_3 + (uint)*puVar18 * 4) = *puVar11;
        puVar18 = puVar18 + 1;
        puVar11 = puVar11 + 1;
        iVar16 = iVar16 + 1;
      } while (iVar16 < (int)(uint)*(byte *)(iVar3 + 0x11));
    }
  }
  return CONCAT31((int3)((uint)puVar11 >> 8),1);
}


// ==== 0x62d170 FUN_0062d170

uint __fastcall FUN_0062d170(int param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  uVar2 = (uint)*(ushort *)(param_1 + 0xe);
  uVar3 = param_1 + (((1 << (bVar1 & 0x1f)) + 1) * uVar2 * 3 + 1 & 0xfffffffe) *
                    (uint)(*(ushort *)(param_1 + 0xc) >> (bVar1 & 0x1f)) + 0x14 + uVar2 * 0x24;
  uVar4 = 0x7fffffffU >> (0x1f - bVar1 & 0x1f) & (uint)*(ushort *)(param_1 + 0xc);
  if (uVar4 != 0) {
    uVar3 = (uVar4 + 1) * uVar2 * 3 + 1 + uVar3 & 0xfffffffe;
  }
  if (*(ushort *)(param_1 + 0xe) == 0) {
    uVar3 = uVar3 + 1 & 0xfffffffe;
  }
  return uVar3;
}


// ==== 0x62d1f0 FUN_0062d1f0

undefined4 * __fastcall FUN_0062d1f0(undefined4 *param_1)

{
  FUN_00628eb0();
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  *param_1 = &PTR_FUN_006a8210;
  param_1[4] = 0xffffffff;
  param_1[7] = 0xffffffff;
  param_1[2] = 0x14;
  return param_1;
}


// ==== 0x62d220 FUN_0062d220

void __thiscall FUN_0062d220(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  return;
}


// ==== 0x62d240 FUN_0062d240

undefined4 __thiscall FUN_0062d240(int *param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*param_1 + 0xc))(param_2,param_2,param_3);
  return 1;
}


// ==== 0x62d260 FUN_0062d260

void __fastcall FUN_0062d260(int param_1)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = *(int *)(param_1 + 0xc);
  if (*(ushort *)(iVar2 + 0xe) != 0) {
    uVar4 = (**(code **)(*DAT_0070d364 + 0x14))((uint)*(ushort *)(iVar2 + 0xe) << 4);
    *(undefined4 *)(param_1 + 0x18) = uVar4;
    *(undefined4 *)(param_1 + 0x14) = uVar4;
    uVar4 = (**(code **)(*DAT_0070d364 + 0x14))((uint)*(ushort *)(iVar2 + 0xe) << 4);
    *(undefined4 *)(param_1 + 0x24) = uVar4;
    *(undefined4 *)(param_1 + 0x20) = uVar4;
    uVar4 = (**(code **)(*DAT_0070d364 + 0x14))((uint)*(ushort *)(iVar2 + 0xe) * 0x30);
    *(undefined4 *)(param_1 + 0x2c) = uVar4;
    iVar7 = 0;
    if (*(short *)(iVar2 + 0xe) != 0) {
      iVar6 = 0xc;
      puVar5 = (undefined4 *)(iVar2 + 0x14);
      do {
        *(undefined4 *)(iVar6 + -0xc + *(int *)(param_1 + 0x2c)) = *puVar5;
        *(undefined4 *)(iVar6 + *(int *)(param_1 + 0x2c)) = puVar5[3];
        *(float *)(*(int *)(param_1 + 0x2c) + iVar6) =
             *(float *)(*(int *)(param_1 + 0x2c) + iVar6) * 1.5259022e-05;
        fVar3 = (float)*(ushort *)(puVar5 + 6) * (float)puVar5[3] * 1.5259022e-05;
        *(float *)(iVar6 + 0xc + *(int *)(param_1 + 0x2c)) = (fVar3 + fVar3) - (float)puVar5[3];
        fVar3 = (float)*(ushort *)((int)puVar5 + 0x1e) * (float)puVar5[3] * 1.5259022e-05;
        *(float *)(iVar6 + 0x18 + *(int *)(param_1 + 0x2c)) = fVar3 + fVar3;
        pfVar1 = (float *)(iVar6 + 0x18 + *(int *)(param_1 + 0x2c));
        *pfVar1 = *pfVar1 * 0.003921569;
        *(undefined4 *)(iVar6 + -8 + *(int *)(param_1 + 0x2c)) = puVar5[1];
        *(undefined4 *)(iVar6 + 4 + *(int *)(param_1 + 0x2c)) = puVar5[4];
        *(float *)(iVar6 + 4 + *(int *)(param_1 + 0x2c)) =
             *(float *)(iVar6 + 4 + *(int *)(param_1 + 0x2c)) * 1.5259022e-05;
        fVar3 = (float)*(ushort *)((int)puVar5 + 0x1a) * (float)puVar5[4] * 1.5259022e-05;
        *(float *)(iVar6 + 0x10 + *(int *)(param_1 + 0x2c)) = (fVar3 + fVar3) - (float)puVar5[4];
        fVar3 = (float)*(ushort *)(puVar5 + 8) * (float)puVar5[4] * 1.5259022e-05;
        *(float *)(iVar6 + 0x1c + *(int *)(param_1 + 0x2c)) = fVar3 + fVar3;
        pfVar1 = (float *)(iVar6 + 0x1c + *(int *)(param_1 + 0x2c));
        *pfVar1 = *pfVar1 * 0.003921569;
        *(undefined4 *)(iVar6 + -4 + *(int *)(param_1 + 0x2c)) = puVar5[2];
        *(undefined4 *)(iVar6 + 8 + *(int *)(param_1 + 0x2c)) = puVar5[5];
        *(float *)(iVar6 + 8 + *(int *)(param_1 + 0x2c)) =
             *(float *)(iVar6 + 8 + *(int *)(param_1 + 0x2c)) * 1.5259022e-05;
        fVar3 = (float)*(ushort *)(puVar5 + 7) * (float)puVar5[5] * 1.5259022e-05;
        iVar7 = iVar7 + 1;
        *(float *)(iVar6 + 0x14 + *(int *)(param_1 + 0x2c)) = (fVar3 + fVar3) - (float)puVar5[5];
        fVar3 = (float)*(ushort *)((int)puVar5 + 0x22) * (float)puVar5[5] * 1.5259022e-05;
        *(float *)(iVar6 + 0x20 + *(int *)(param_1 + 0x2c)) = fVar3 + fVar3;
        pfVar1 = (float *)(iVar6 + 0x20 + *(int *)(param_1 + 0x2c));
        iVar6 = iVar6 + 0x30;
        *pfVar1 = *pfVar1 * 0.003921569;
        puVar5 = puVar5 + 9;
      } while (iVar7 < (int)(uint)*(ushort *)(iVar2 + 0xe));
    }
  }
  return;
}


// ==== 0x62d460 FUN_0062d460

undefined4 __thiscall FUN_0062d460(undefined4 param_1,byte param_2)

{
  FUN_0062d490();
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x30);
  }
  return param_1;
}


// ==== 0x62d490 FUN_0062d490

void __fastcall FUN_0062d490(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a8210;
  if (param_1[6] != 0) {
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[5]);
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[8]);
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[0xb]);
  }
  FUN_00628ed0();
  return;
}


// ==== 0x62d4e0 FUN_0062d4e0

undefined4 __thiscall FUN_0062d4e0(int param_1,float param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  ushort uVar8;
  int iVar9;
  undefined4 uVar10;
  bool bVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  float *pfVar16;
  int iVar17;
  float *pfVar18;
  undefined4 *puVar19;
  uint uVar20;
  ushort *puVar21;
  byte *pbVar22;
  byte *pbVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  undefined4 *puVar27;
  int iVar28;
  ushort *puVar29;
  float local_8c;
  ushort *local_88;
  byte *local_80;
  int local_7c;
  int local_78;
  int local_74;
  uint local_6c;
  byte abStack_50 [80];
  
  if (param_4 != *(int *)(param_1 + 0x28)) {
    *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
    *(int *)(param_1 + 0x28) = param_4;
  }
  iVar9 = *(int *)(param_1 + 0xc);
  if (param_2 < 0.0) {
    fVar1 = param_2 + 0.499999;
  }
  else {
    fVar1 = param_2 - 0.499999;
  }
  local_6c = (uint)ROUND(fVar1);
  puVar21 = *(ushort **)(iVar9 + 8);
  if (puVar21 == (ushort *)0x0) {
    if ((int)local_6c < 0) {
      uVar24 = 0;
    }
    else {
      uVar24 = local_6c;
      if ((int)(uint)*(ushort *)(iVar9 + 0xc) <= (int)local_6c) {
        uVar24 = *(ushort *)(iVar9 + 0xc) - 1;
      }
    }
  }
  else if ((int)local_6c < (int)(uint)*puVar21) {
    uVar24 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x10) < 1) {
      iVar15 = 0;
    }
    else {
      iVar15 = *(int *)(param_1 + 0x10) + -1;
    }
    puVar29 = puVar21 + iVar15;
    if ((int)local_6c < (int)(uint)puVar21[iVar15]) {
      for (; (0 < iVar15 && ((int)local_6c < (int)(uint)*puVar29)); puVar29 = puVar29 + -1) {
        iVar15 = iVar15 + -1;
      }
    }
    else {
      while ((iVar15 < (int)(*(ushort *)(iVar9 + 0xc) - 2) &&
             (puVar29 = puVar29 + 1, (int)(uint)*puVar29 <= (int)local_6c))) {
        iVar15 = iVar15 + 1;
      }
    }
    uVar24 = iVar15 + 1;
  }
  bVar5 = *(byte *)(iVar9 + 0x10);
  uVar20 = *(uint *)(param_1 + 0x10);
  uVar25 = 0x7fffffff >> (0x1f - bVar5 & 0x1f);
  iVar12 = (int)uVar24 >> (bVar5 & 0x1f);
  uVar13 = uVar25 & uVar24;
  uVar26 = (uint)*(ushort *)(iVar9 + 0xe);
  iVar15 = iVar9 + (((1 << (bVar5 & 0x1f)) + 1) * uVar26 * 3 + 1 & 0xfffffffe) * iVar12 + 0x14 +
           uVar26 * 0x24;
  iVar17 = 0;
  if (uVar26 != 0) {
    do {
      abStack_50[iVar17] = (byte)(*(ushort *)(*(int *)(iVar9 + 4) + iVar17 * 2) / 0xc);
      iVar17 = iVar17 + 1;
    } while (iVar17 < (int)uVar26);
  }
  if (((int)uVar20 <= (int)uVar24) || (bVar11 = true, DAT_006e58d8 != '\0')) {
    bVar11 = false;
  }
  if (uVar24 == *(uint *)(param_1 + 0x1c)) {
    uVar10 = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x24) = uVar10;
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  }
  else {
    if (((uVar20 == 0xffffffff) || (iVar12 != (int)uVar20 >> (bVar5 & 0x1f))) || (bVar11)) {
      iVar17 = 0;
      if (uVar26 != 0) {
        iVar28 = 0;
        local_80 = (byte *)0x0;
        puVar21 = (ushort *)(iVar15 + 4);
        do {
          if ((*(uint *)(param_4 + ((int)(uint)abStack_50[iVar17] >> 5) * 4) &
              1 << (abStack_50[iVar17] & 0x1f)) != 0) {
            pfVar18 = (float *)(*(int *)(param_1 + 0x18) + iVar28);
            pfVar16 = (float *)(*(int *)(param_1 + 0x2c) + (int)local_80);
            *pfVar18 = (float)puVar21[-2] * pfVar16[3] + *pfVar16;
            pfVar18[1] = (float)puVar21[-1] * pfVar16[4] + pfVar16[1];
            pfVar18[2] = (float)*puVar21 * pfVar16[5] + pfVar16[2];
          }
          iVar17 = iVar17 + 1;
          local_80 = (byte *)((int)local_80 + 0x30);
          iVar28 = iVar28 + 0x10;
          puVar21 = puVar21 + 3;
        } while (iVar17 < (int)(uint)*(ushort *)(iVar9 + 0xe));
      }
      uVar20 = 0;
    }
    else {
      uVar20 = uVar20 & uVar25;
    }
    if ((int)uVar20 < (int)uVar13) {
      uVar25 = (uint)*(ushort *)(iVar9 + 0xe);
      iVar15 = iVar15 + (uVar20 + 2) * uVar25 * 3;
      local_78 = uVar13 - uVar20;
      do {
        iVar17 = 0;
        if (uVar25 != 0) {
          iVar28 = 0;
          local_80 = (byte *)0x0;
          pbVar22 = (byte *)(iVar15 + 2);
          do {
            if ((*(uint *)(param_4 + ((int)(uint)abStack_50[iVar17] >> 5) * 4) &
                1 << (abStack_50[iVar17] & 0x1f)) != 0) {
              iVar14 = *(int *)(param_1 + 0x2c) + (int)local_80;
              bVar6 = pbVar22[-1];
              bVar7 = *pbVar22;
              fVar1 = *(float *)(iVar14 + 0x28);
              fVar2 = *(float *)(iVar14 + 0x1c);
              fVar3 = *(float *)(iVar14 + 0x2c);
              fVar4 = *(float *)(iVar14 + 0x20);
              pfVar16 = (float *)(*(int *)(param_1 + 0x18) + iVar28);
              *pfVar16 = (float)pbVar22[-2] * *(float *)(iVar14 + 0x24) + *(float *)(iVar14 + 0x18)
                         + *pfVar16;
              *(float *)(*(int *)(param_1 + 0x18) + 4 + iVar28) =
                   (float)bVar6 * fVar1 + fVar2 + *(float *)(*(int *)(param_1 + 0x18) + 4 + iVar28);
              *(float *)(*(int *)(param_1 + 0x18) + 8 + iVar28) =
                   (float)bVar7 * fVar3 + fVar4 + *(float *)(*(int *)(param_1 + 0x18) + 8 + iVar28);
            }
            uVar25 = (uint)*(ushort *)(iVar9 + 0xe);
            iVar17 = iVar17 + 1;
            local_80 = (byte *)((int)local_80 + 0x30);
            pbVar22 = pbVar22 + 3;
            iVar28 = iVar28 + 0x10;
          } while (iVar17 < (int)uVar25);
        }
        iVar15 = iVar15 + uVar26 * 3;
        local_78 = local_78 + -1;
      } while (local_78 != 0);
    }
    else if ((int)uVar13 < (int)uVar20) {
      uVar25 = (uint)*(ushort *)(iVar9 + 0xe);
      if ((int)uVar13 <= (int)(uVar20 - 1)) {
        pbVar22 = (byte *)(iVar15 + (uVar20 + 1) * uVar25 * 3 + 2);
        local_80 = (byte *)(((uVar20 - 1) - uVar13) + 1);
        do {
          iVar15 = 0;
          if (uVar25 != 0) {
            iVar17 = 0;
            local_7c = 0;
            pbVar23 = pbVar22;
            do {
              if ((*(uint *)(param_4 + ((int)(uint)abStack_50[iVar15] >> 5) * 4) &
                  1 << (abStack_50[iVar15] & 0x1f)) != 0) {
                iVar28 = *(int *)(param_1 + 0x2c) + local_7c;
                bVar6 = pbVar23[-1];
                bVar7 = *pbVar23;
                fVar1 = *(float *)(iVar28 + 0x28);
                fVar2 = *(float *)(iVar28 + 0x1c);
                fVar3 = *(float *)(iVar28 + 0x2c);
                fVar4 = *(float *)(iVar28 + 0x20);
                pfVar16 = (float *)(*(int *)(param_1 + 0x18) + iVar17);
                *pfVar16 = *pfVar16 -
                           ((float)pbVar23[-2] * *(float *)(iVar28 + 0x24) +
                           *(float *)(iVar28 + 0x18));
                *(float *)(*(int *)(param_1 + 0x18) + 4 + iVar17) =
                     *(float *)(*(int *)(param_1 + 0x18) + 4 + iVar17) -
                     ((float)bVar6 * fVar1 + fVar2);
                pfVar16 = (float *)(*(int *)(param_1 + 0x18) + 8 + iVar17);
                *pfVar16 = *pfVar16 - ((float)bVar7 * fVar3 + fVar4);
              }
              uVar25 = (uint)*(ushort *)(iVar9 + 0xe);
              iVar15 = iVar15 + 1;
              local_7c = local_7c + 0x30;
              pbVar23 = pbVar23 + 3;
              iVar17 = iVar17 + 0x10;
            } while (iVar15 < (int)uVar25);
          }
          pbVar22 = pbVar22 + uVar26 * -3;
          local_80 = (byte *)((int)local_80 + -1);
        } while (local_80 != (byte *)0x0);
      }
    }
  }
  *(uint *)(param_1 + 0x10) = uVar24;
  puVar21 = *(ushort **)(iVar9 + 8);
  iVar15 = uVar24 + 1;
  local_8c = 1.0;
  if (puVar21 == (ushort *)0x0) {
    bVar11 = false;
    if (param_2 == (float)(int)local_6c) goto LAB_0062da74;
    local_8c = param_2 - (float)(int)local_6c;
  }
  else {
    if (uVar24 == 0) {
      if (param_2 == 0.0) {
        bVar11 = false;
      }
      else {
        bVar11 = true;
        local_8c = param_2 / (float)*puVar21;
      }
      goto LAB_0062da74;
    }
    fVar1 = (float)puVar21[uVar24 - 1];
    bVar11 = false;
    if (param_2 == fVar1) goto LAB_0062da74;
    local_8c = (param_2 - fVar1) / ((float)puVar21[uVar24] - fVar1);
  }
  bVar11 = true;
LAB_0062da74:
  puVar21 = *(ushort **)(iVar9 + 4);
  if ((bVar11) && ((int)uVar24 < (int)(*(ushort *)(iVar9 + 0xc) - 1))) {
    uVar24 = (uint)*(ushort *)(iVar9 + 0xe);
    iVar28 = iVar15 >> (bVar5 & 0x1f);
    iVar17 = iVar9 + (((1 << (*(byte *)(iVar9 + 0x10) & 0x1f)) + 1) * uVar24 * 3 + 1 & 0xfffffffe) *
                     iVar28 + 0x14 + uVar24 * 0x24;
    if (iVar15 == *(int *)(param_1 + 0x1c)) {
      local_88 = (ushort *)0x0;
      if (uVar24 != 0) {
        iVar15 = 0;
        do {
          if ((*(uint *)(param_4 + ((int)(uint)abStack_50[(int)local_88] >> 5) * 4) &
              1 << (abStack_50[(int)local_88] & 0x1f)) != 0) {
            pfVar16 = (float *)(*(int *)(param_1 + 0x18) + iVar15);
            *(float *)(param_3 + (uint)*puVar21 * 4) =
                 (*(float *)(*(int *)(param_1 + 0x24) + iVar15) - *pfVar16) * local_8c + *pfVar16;
            *(float *)(param_3 + 4 + (uint)*puVar21 * 4) =
                 (*(float *)(*(int *)(param_1 + 0x24) + 4 + iVar15) -
                 *(float *)(*(int *)(param_1 + 0x18) + 4 + iVar15)) * local_8c +
                 *(float *)(*(int *)(param_1 + 0x18) + 4 + iVar15);
            *(float *)(param_3 + 8 + (uint)*puVar21 * 4) =
                 (*(float *)(*(int *)(param_1 + 0x24) + 8 + iVar15) -
                 *(float *)(*(int *)(param_1 + 0x18) + 8 + iVar15)) * local_8c +
                 *(float *)(*(int *)(param_1 + 0x18) + 8 + iVar15);
          }
          puVar21 = puVar21 + 1;
          local_88 = (ushort *)((int)local_88 + 1);
          iVar15 = iVar15 + 0x10;
        } while ((int)local_88 < (int)(uint)*(ushort *)(iVar9 + 0xe));
      }
    }
    else if (iVar28 == iVar12) {
      local_88 = (ushort *)0x0;
      if (uVar24 != 0) {
        iVar12 = 0;
        local_80 = (byte *)(iVar17 + (uVar13 + 2) * uVar24 * 3 + 2);
        local_74 = 0;
        do {
          if ((*(uint *)(param_4 + ((int)(uint)abStack_50[(int)local_88] >> 5) * 4) &
              1 << (abStack_50[(int)local_88] & 0x1f)) != 0) {
            iVar17 = *(int *)(param_1 + 0x2c) + local_74;
            fVar1 = (float)local_80[-2] * *(float *)(iVar17 + 0x24) + *(float *)(iVar17 + 0x18);
            fVar2 = (float)local_80[-1] * *(float *)(iVar17 + 0x28) + *(float *)(iVar17 + 0x1c);
            fVar3 = (float)*local_80 * *(float *)(iVar17 + 0x2c) + *(float *)(iVar17 + 0x20);
            *(int *)(param_1 + 0x1c) = iVar15;
            *(float *)(iVar12 + *(int *)(param_1 + 0x24)) =
                 fVar1 + *(float *)(*(int *)(param_1 + 0x18) + iVar12);
            *(float *)(*(int *)(param_1 + 0x24) + 4 + iVar12) =
                 fVar2 + *(float *)(*(int *)(param_1 + 0x18) + 4 + iVar12);
            *(float *)(*(int *)(param_1 + 0x24) + 8 + iVar12) =
                 fVar3 + *(float *)(*(int *)(param_1 + 0x18) + 8 + iVar12);
            *(float *)(param_3 + (uint)*puVar21 * 4) =
                 fVar1 * local_8c + *(float *)(*(int *)(param_1 + 0x18) + iVar12);
            *(float *)(param_3 + 4 + (uint)*puVar21 * 4) =
                 fVar2 * local_8c + *(float *)(*(int *)(param_1 + 0x18) + 4 + iVar12);
            *(float *)(param_3 + 8 + (uint)*puVar21 * 4) =
                 fVar3 * local_8c + *(float *)(*(int *)(param_1 + 0x18) + 8 + iVar12);
          }
          local_80 = local_80 + 3;
          puVar21 = puVar21 + 1;
          local_88 = (ushort *)((int)local_88 + 1);
          local_74 = local_74 + 0x30;
          iVar12 = iVar12 + 0x10;
        } while ((int)local_88 < (int)(uint)*(ushort *)(iVar9 + 0xe));
      }
    }
    else {
      local_88 = (ushort *)0x0;
      if (uVar24 != 0) {
        iVar12 = 0;
        puVar29 = (ushort *)(iVar17 + 4);
        local_74 = 0;
        do {
          if ((*(uint *)(param_4 + ((int)(uint)abStack_50[(int)local_88] >> 5) * 4) &
              1 << (abStack_50[(int)local_88] & 0x1f)) != 0) {
            pfVar16 = (float *)(*(int *)(param_1 + 0x2c) + local_74);
            pfVar18 = (float *)(*(int *)(param_1 + 0x24) + iVar12);
            *pfVar18 = (float)puVar29[-2] * pfVar16[3] + *pfVar16;
            pfVar18[1] = (float)puVar29[-1] * pfVar16[4] + pfVar16[1];
            pfVar18[2] = (float)*puVar29 * pfVar16[5] + pfVar16[2];
            *(int *)(param_1 + 0x1c) = iVar15;
            *(float *)(param_3 + (uint)*puVar21 * 4) =
                 (*(float *)(*(int *)(param_1 + 0x24) + iVar12) -
                 *(float *)(*(int *)(param_1 + 0x18) + iVar12)) * local_8c +
                 *(float *)(*(int *)(param_1 + 0x18) + iVar12);
            *(float *)(param_3 + 4 + (uint)*puVar21 * 4) =
                 (*(float *)(*(int *)(param_1 + 0x24) + 4 + iVar12) -
                 *(float *)(*(int *)(param_1 + 0x18) + 4 + iVar12)) * local_8c +
                 *(float *)(*(int *)(param_1 + 0x18) + 4 + iVar12);
            *(float *)(param_3 + 8 + (uint)*puVar21 * 4) =
                 (*(float *)(*(int *)(param_1 + 0x24) + 8 + iVar12) -
                 *(float *)(*(int *)(param_1 + 0x18) + 8 + iVar12)) * local_8c +
                 *(float *)(*(int *)(param_1 + 0x18) + 8 + iVar12);
          }
          local_74 = local_74 + 0x30;
          puVar21 = puVar21 + 1;
          puVar29 = puVar29 + 3;
          local_88 = (ushort *)((int)local_88 + 1);
          iVar12 = iVar12 + 0x10;
        } while ((int)local_88 < (int)(uint)*(ushort *)(iVar9 + 0xe));
      }
    }
  }
  else {
    iVar15 = 0;
    if (*(short *)(iVar9 + 0xe) != 0) {
      iVar12 = 0;
      do {
        if ((*(uint *)(param_4 + ((int)(uint)abStack_50[iVar15] >> 5) * 4) &
            1 << (abStack_50[iVar15] & 0x1f)) != 0) {
          puVar19 = (undefined4 *)(*(int *)(param_1 + 0x18) + iVar12);
          puVar27 = (undefined4 *)(param_3 + (uint)puVar21[iVar15] * 4);
          *puVar27 = *puVar19;
          puVar27[1] = puVar19[1];
          puVar27[2] = puVar19[2];
        }
        iVar15 = iVar15 + 1;
        iVar12 = iVar12 + 0x10;
      } while (iVar15 < (int)(uint)*(ushort *)(iVar9 + 0xe));
    }
  }
  bVar5 = *(byte *)(iVar9 + 0x11);
  if (bVar5 != 0) {
    local_88 = (ushort *)FUN_0062d170();
    iVar15 = FUN_0062d170();
    puVar27 = (undefined4 *)(iVar15 + 3 + (uint)bVar5 * 2 & 0xfffffffc);
    local_6c = 0;
    if (bVar5 != 0) {
      do {
        uVar8 = *local_88;
        local_88 = local_88 + 1;
        uVar24 = uVar8 / 0xc;
        if ((*(uint *)(param_4 + ((int)uVar24 >> 5) * 4) & 1 << ((byte)uVar24 & 0x1f)) != 0) {
          *(undefined4 *)(param_3 + (uint)uVar8 * 4) = *puVar27;
          *(undefined4 *)(param_3 + (uint)(ushort)(uVar8 + 1) * 4) = puVar27[1];
          *(undefined4 *)(param_3 + (uint)(ushort)(uVar8 + 2) * 4) = puVar27[2];
        }
        puVar27 = puVar27 + 3;
        local_6c = local_6c + 1;
      } while ((int)local_6c < (int)(uint)*(byte *)(iVar9 + 0x11));
    }
  }
  return 1;
}


// ==== 0x62df90 FUN_0062df90

undefined4 __thiscall FUN_0062df90(int param_1,ushort *param_2,undefined4 *param_3,float param_4)

{
  byte *pbVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  ushort uVar10;
  int iVar11;
  bool bVar12;
  int iVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  undefined4 *puVar19;
  float *pfVar20;
  float *pfVar21;
  ushort *puVar22;
  int iVar23;
  uint uVar24;
  byte *pbVar25;
  byte *pbVar26;
  undefined4 *puVar27;
  uint uVar28;
  uint uVar29;
  ushort *puVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  undefined4 *puStack_20;
  
  iVar13 = (int)param_3;
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_0062d260();
  }
  if (param_4 != 0.0) {
    uVar14 = FUN_0062d4e0(param_2,param_3,param_4);
    return uVar14;
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  iVar11 = *(int *)(param_1 + 0xc);
  uVar15 = FUN_00629350(param_2);
  puVar22 = *(ushort **)(iVar11 + 8);
  if (puVar22 == (ushort *)0x0) {
    if ((int)uVar15 < 0) {
      uVar28 = 0;
    }
    else {
      uVar28 = uVar15;
      if ((int)(uint)*(ushort *)(iVar11 + 0xc) <= (int)uVar15) {
        uVar28 = *(ushort *)(iVar11 + 0xc) - 1;
      }
    }
  }
  else if ((int)uVar15 < (int)(uint)*puVar22) {
    uVar28 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x10) < 1) {
      iVar23 = 0;
    }
    else {
      iVar23 = *(int *)(param_1 + 0x10) + -1;
    }
    puVar30 = puVar22 + iVar23;
    if ((int)uVar15 < (int)(uint)puVar22[iVar23]) {
      for (; (0 < iVar23 && ((int)uVar15 < (int)(uint)*puVar30)); puVar30 = puVar30 + -1) {
        iVar23 = iVar23 + -1;
      }
    }
    else {
      while ((iVar23 < (int)(*(ushort *)(iVar11 + 0xc) - 2) &&
             (puVar30 = puVar30 + 1, (int)(uint)*puVar30 <= (int)uVar15))) {
        iVar23 = iVar23 + 1;
      }
    }
    uVar28 = iVar23 + 1;
  }
  bVar7 = *(byte *)(iVar11 + 0x10);
  uVar16 = 0x7fffffff >> (0x1f - bVar7 & 0x1f);
  uVar17 = uVar16 & uVar28;
  uVar29 = (uint)*(ushort *)(iVar11 + 0xe);
  uVar24 = *(uint *)(param_1 + 0x10);
  iVar32 = (int)uVar28 >> (bVar7 & 0x1f);
  iVar23 = iVar11 + (((1 << (bVar7 & 0x1f)) + 1) * uVar29 * 3 + 1 & 0xfffffffe) * iVar32 + 0x14 +
           uVar29 * 0x24;
  if (((int)uVar24 <= (int)uVar28) || (bVar12 = true, DAT_006e58d8 != '\0')) {
    bVar12 = false;
  }
  if (uVar28 == *(uint *)(param_1 + 0x1c)) {
    uVar14 = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x24) = uVar14;
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  }
  else {
    if ((((uVar24 == 0xffffffff) || (iVar32 != (int)uVar24 >> (bVar7 & 0x1f))) || (uVar17 == 0)) ||
       (bVar12)) {
      iStack_28 = 0;
      if (uVar29 != 0) {
        param_4 = 0.0;
        iVar33 = 0;
        puVar22 = (ushort *)(iVar23 + 4);
        do {
          pfVar20 = (float *)(*(int *)(param_1 + 0x2c) + (int)param_4);
          pfVar21 = (float *)(*(int *)(param_1 + 0x18) + iVar33);
          iVar33 = iVar33 + 0x10;
          *pfVar21 = (float)puVar22[-2] * pfVar20[3] + *pfVar20;
          pfVar21[1] = (float)puVar22[-1] * pfVar20[4] + pfVar20[1];
          iStack_28 = iStack_28 + 1;
          pfVar21[2] = (float)*puVar22 * pfVar20[5] + pfVar20[2];
          param_4 = (float)((int)param_4 + 0x30);
          puVar22 = puVar22 + 3;
        } while (iStack_28 < (int)(uint)*(ushort *)(iVar11 + 0xe));
      }
      uVar24 = 0;
    }
    else {
      uVar24 = uVar24 & uVar16;
    }
    if ((int)uVar24 < (int)uVar17) {
      uVar16 = (uint)*(ushort *)(iVar11 + 0xe);
      iVar23 = iVar23 + (uVar24 + 2) * uVar16 * 3;
      iStack_24 = uVar17 - uVar24;
      do {
        iVar33 = 0;
        param_4 = 0.0;
        if (uVar16 != 0) {
          iVar31 = 0;
          pbVar25 = (byte *)(iVar23 + 2);
          do {
            pbVar26 = pbVar25 + -2;
            iVar18 = *(int *)(param_1 + 0x2c) + iVar33;
            bVar9 = pbVar25[-1];
            bVar8 = *pbVar25;
            iVar33 = iVar33 + 0x30;
            pbVar25 = pbVar25 + 3;
            fVar3 = *(float *)(iVar18 + 0x28);
            fVar4 = *(float *)(iVar18 + 0x1c);
            fVar5 = *(float *)(iVar18 + 0x2c);
            fVar6 = *(float *)(iVar18 + 0x20);
            pfVar20 = (float *)(*(int *)(param_1 + 0x18) + iVar31);
            param_4 = (float)((int)param_4 + 1);
            *pfVar20 = (float)*pbVar26 * *(float *)(iVar18 + 0x24) + *(float *)(iVar18 + 0x18) +
                       *pfVar20;
            pfVar20 = (float *)(iVar31 + 4 + *(int *)(param_1 + 0x18));
            *pfVar20 = (float)bVar9 * fVar3 + fVar4 + *pfVar20;
            pfVar20 = (float *)(iVar31 + 8 + *(int *)(param_1 + 0x18));
            iVar31 = iVar31 + 0x10;
            *pfVar20 = (float)bVar8 * fVar5 + fVar6 + *pfVar20;
            uVar16 = (uint)*(ushort *)(iVar11 + 0xe);
          } while ((int)param_4 < (int)uVar16);
        }
        iVar23 = iVar23 + uVar29 * 3;
        iStack_24 = iStack_24 + -1;
      } while (iStack_24 != 0);
    }
    else if ((int)uVar17 < (int)uVar24) {
      uVar16 = (uint)*(ushort *)(iVar11 + 0xe);
      if ((int)uVar17 <= (int)(uVar24 - 1)) {
        pbVar25 = (byte *)(iVar23 + (uVar24 + 1) * uVar16 * 3 + 2);
        iStack_28 = ((uVar24 - 1) - uVar17) + 1;
        do {
          iVar23 = 0;
          param_4 = 0.0;
          if (uVar16 != 0) {
            iVar33 = 0;
            pbVar26 = pbVar25;
            do {
              pbVar1 = pbVar26 + -2;
              iVar31 = *(int *)(param_1 + 0x2c) + iVar23;
              bVar9 = pbVar26[-1];
              bVar8 = *pbVar26;
              iVar23 = iVar23 + 0x30;
              pbVar26 = pbVar26 + 3;
              fVar3 = *(float *)(iVar31 + 0x28);
              fVar4 = *(float *)(iVar31 + 0x1c);
              fVar5 = *(float *)(iVar31 + 0x2c);
              fVar6 = *(float *)(iVar31 + 0x20);
              pfVar20 = (float *)(*(int *)(param_1 + 0x18) + iVar33);
              param_4 = (float)((int)param_4 + 1);
              *pfVar20 = *pfVar20 -
                         ((float)*pbVar1 * *(float *)(iVar31 + 0x24) + *(float *)(iVar31 + 0x18));
              *(float *)(iVar33 + 4 + *(int *)(param_1 + 0x18)) =
                   *(float *)(iVar33 + 4 + *(int *)(param_1 + 0x18)) -
                   ((float)bVar9 * fVar3 + fVar4);
              pfVar20 = (float *)(iVar33 + 8 + *(int *)(param_1 + 0x18));
              iVar33 = iVar33 + 0x10;
              *pfVar20 = *pfVar20 - ((float)bVar8 * fVar5 + fVar6);
              uVar16 = (uint)*(ushort *)(iVar11 + 0xe);
            } while ((int)param_4 < (int)uVar16);
          }
          pbVar25 = pbVar25 + uVar29 * -3;
          iStack_28 = iStack_28 + -1;
        } while (iStack_28 != 0);
      }
    }
  }
  iVar23 = uVar28 + 1;
  *(uint *)(param_1 + 0x10) = uVar28;
  puVar22 = *(ushort **)(iVar11 + 8);
  param_4 = 1.0;
  if (puVar22 == (ushort *)0x0) {
    if ((float)param_2 == (float)(int)uVar15) {
LAB_0062e51a:
      bVar12 = false;
    }
    else {
      param_4 = (float)param_2 - (float)(int)uVar15;
LAB_0062e428:
      bVar12 = true;
    }
  }
  else {
    if (uVar28 != 0) {
      fVar3 = (float)puVar22[uVar28 - 1];
      if ((float)param_2 == fVar3) goto LAB_0062e51a;
      param_4 = ((float)param_2 - fVar3) / ((float)puVar22[uVar28] - fVar3);
      goto LAB_0062e428;
    }
    if ((float)param_2 == 0.0) {
      bVar12 = false;
    }
    else {
      bVar12 = true;
      param_4 = (float)param_2 / (float)*puVar22;
    }
  }
  puVar22 = *(ushort **)(iVar11 + 4);
  if ((bVar12) && ((int)uVar28 < (int)(*(ushort *)(iVar11 + 0xc) - 1))) {
    iVar31 = iVar23 >> (bVar7 & 0x1f);
    iVar33 = iVar11 + (((1 << (*(byte *)(iVar11 + 0x10) & 0x1f)) + 1) *
                       (uint)*(ushort *)(iVar11 + 0xe) * 3 + 1 & 0xfffffffe) * iVar31 + 0x14 +
             (uint)*(ushort *)(iVar11 + 0xe) * 0x24;
    if (iVar23 == *(int *)(param_1 + 0x1c)) {
      param_2 = (ushort *)0x0;
      puVar19 = (undefined4 *)0x0;
      if (*(short *)(iVar11 + 0xe) != 0) {
        puVar19 = (undefined4 *)0x0;
        do {
          *(float *)((int)param_3 + (uint)*puVar22 * 4) =
               (*(float *)((int)puVar19 + *(int *)(param_1 + 0x24)) -
               *(float *)(*(int *)(param_1 + 0x18) + (int)puVar19)) * param_4 +
               *(float *)(*(int *)(param_1 + 0x18) + (int)puVar19);
          *(float *)((int)param_3 + 4 + (uint)*puVar22 * 4) =
               (*(float *)((int)puVar19 + *(int *)(param_1 + 0x24) + 4) -
               *(float *)((int)puVar19 + *(int *)(param_1 + 0x18) + 4)) * param_4 +
               *(float *)((int)puVar19 + *(int *)(param_1 + 0x18) + 4);
          pfVar20 = (float *)((int)puVar19 + *(int *)(param_1 + 0x24) + 8);
          pfVar21 = (float *)((int)puVar19 + *(int *)(param_1 + 0x18) + 8);
          pfVar2 = (float *)((int)puVar19 + *(int *)(param_1 + 0x18) + 8);
          puVar19 = puVar19 + 4;
          *(float *)((int)param_3 + 8 + (uint)*puVar22 * 4) =
               (*pfVar20 - *pfVar21) * param_4 + *pfVar2;
          param_2 = (ushort *)((int)param_2 + 1);
          puVar22 = puVar22 + 1;
        } while ((int)param_2 < (int)(uint)*(ushort *)(iVar11 + 0xe));
      }
    }
    else {
      if (iVar31 == iVar32) {
        puVar19 = (undefined4 *)(iVar33 + (uVar17 + 2) * (uint)*(ushort *)(iVar11 + 0xe) * 3);
        puStack_20 = (undefined4 *)0x0;
        if (*(ushort *)(iVar11 + 0xe) != 0) {
          param_2 = (ushort *)((int)puVar19 + 2);
          param_3 = (undefined4 *)0x0;
          puVar19 = (undefined4 *)0x0;
          do {
            iVar32 = *(int *)(param_1 + 0x2c) + (int)param_3;
            bVar7 = *(byte *)((int)param_2 + -1);
            bVar9 = *(byte *)param_2;
            fVar3 = *(float *)(iVar32 + 0x28);
            fVar4 = *(float *)(iVar32 + 0x1c);
            fVar5 = *(float *)(iVar32 + 0x2c);
            fVar6 = *(float *)(iVar32 + 0x20);
            *(float *)((int)puVar19 + *(int *)(param_1 + 0x24)) =
                 (float)*(byte *)((int)param_2 + -2) * *(float *)(iVar32 + 0x24) +
                 *(float *)(iVar32 + 0x18) + *(float *)((int)puVar19 + *(int *)(param_1 + 0x18));
            *(float *)((int)puVar19 + *(int *)(param_1 + 0x24) + 4) =
                 (float)bVar7 * fVar3 + fVar4 +
                 *(float *)((int)puVar19 + *(int *)(param_1 + 0x18) + 4);
            *(float *)((int)puVar19 + *(int *)(param_1 + 0x24) + 8) =
                 (float)bVar9 * fVar5 + fVar6 +
                 *(float *)((int)puVar19 + *(int *)(param_1 + 0x18) + 8);
            *(float *)(iVar13 + (uint)*puVar22 * 4) =
                 (*(float *)((int)puVar19 + *(int *)(param_1 + 0x24)) -
                 *(float *)(*(int *)(param_1 + 0x18) + (int)puVar19)) * param_4 +
                 *(float *)(*(int *)(param_1 + 0x18) + (int)puVar19);
            *(float *)(iVar13 + 4 + (uint)*puVar22 * 4) =
                 (*(float *)((int)puVar19 + *(int *)(param_1 + 0x24) + 4) -
                 *(float *)((int)puVar19 + *(int *)(param_1 + 0x18) + 4)) * param_4 +
                 *(float *)((int)puVar19 + *(int *)(param_1 + 0x18) + 4);
            param_3 = (undefined4 *)((int)param_3 + 0x30);
            param_2 = (ushort *)((int)param_2 + 3);
            *(float *)(iVar13 + 8 + (uint)*puVar22 * 4) =
                 (*(float *)((int)puVar19 + *(int *)(param_1 + 0x24) + 8) -
                 *(float *)((int)puVar19 + *(int *)(param_1 + 0x18) + 8)) * param_4 +
                 *(float *)((int)puVar19 + *(int *)(param_1 + 0x18) + 8);
            puStack_20 = (undefined4 *)((int)puStack_20 + 1);
            puVar19 = puVar19 + 4;
            puVar22 = puVar22 + 1;
          } while ((int)puStack_20 < (int)(uint)*(ushort *)(iVar11 + 0xe));
        }
      }
      else {
        iVar32 = 0;
        puStack_20 = (undefined4 *)0x0;
        puVar19 = (undefined4 *)0x0;
        if (*(short *)(iVar11 + 0xe) != 0) {
          param_2 = (ushort *)(iVar33 + 4);
          iStack_2c = 0;
          do {
            pfVar20 = (float *)(*(int *)(param_1 + 0x24) + iVar32);
            pfVar21 = (float *)(*(int *)(param_1 + 0x2c) + iStack_2c);
            *pfVar20 = (float)param_2[-2] * pfVar21[3] + *pfVar21;
            pfVar20[1] = (float)param_2[-1] * pfVar21[4] + pfVar21[1];
            pfVar20[2] = (float)*param_2 * pfVar21[5] + pfVar21[2];
            *(float *)((int)param_3 + (uint)*puVar22 * 4) =
                 (*(float *)(iVar32 + *(int *)(param_1 + 0x24)) -
                 *(float *)(*(int *)(param_1 + 0x18) + iVar32)) * param_4 +
                 *(float *)(*(int *)(param_1 + 0x18) + iVar32);
            *(float *)((int)param_3 + 4 + (uint)*puVar22 * 4) =
                 (*(float *)(iVar32 + 4 + *(int *)(param_1 + 0x24)) -
                 *(float *)(iVar32 + 4 + *(int *)(param_1 + 0x18))) * param_4 +
                 *(float *)(iVar32 + 4 + *(int *)(param_1 + 0x18));
            iVar33 = iVar32 + 8;
            iVar31 = iVar32 + 8;
            iVar18 = iVar32 + 8;
            iStack_2c = iStack_2c + 0x30;
            iVar32 = iVar32 + 0x10;
            *(float *)((int)param_3 + 8 + (uint)*puVar22 * 4) =
                 (*(float *)(iVar33 + *(int *)(param_1 + 0x24)) -
                 *(float *)(iVar31 + *(int *)(param_1 + 0x18))) * param_4 +
                 *(float *)(iVar18 + *(int *)(param_1 + 0x18));
            param_2 = param_2 + 3;
            puVar19 = (undefined4 *)((int)puStack_20 + 1);
            puVar22 = puVar22 + 1;
            puStack_20 = puVar19;
          } while ((int)puVar19 < (int)(uint)*(ushort *)(iVar11 + 0xe));
          *(int *)(param_1 + 0x1c) = iVar23;
          goto LAB_0062e7dc;
        }
      }
      *(int *)(param_1 + 0x1c) = iVar23;
    }
  }
  else {
    puVar19 = (undefined4 *)0x0;
    param_3 = (undefined4 *)0x0;
    if (*(short *)(iVar11 + 0xe) != 0) {
      param_2 = (ushort *)0x0;
      do {
        puVar27 = (undefined4 *)(*(int *)(param_1 + 0x18) + (int)param_2);
        puVar19 = (undefined4 *)(iVar13 + (uint)puVar22[(int)param_3] * 4);
        *puVar19 = *puVar27;
        puVar19[1] = puVar27[1];
        puVar19[2] = puVar27[2];
        param_2 = (ushort *)((int)param_2 + 0x10);
        puVar19 = (undefined4 *)((int)param_3 + 1);
        param_3 = puVar19;
      } while ((int)puVar19 < (int)(uint)*(ushort *)(iVar11 + 0xe));
    }
  }
LAB_0062e7dc:
  bVar7 = *(byte *)(iVar11 + 0x11);
  if (bVar7 != 0) {
    puVar22 = (ushort *)FUN_0062d170();
    iVar23 = FUN_0062d170();
    puVar19 = (undefined4 *)(iVar23 + 3 + (uint)bVar7 * 2 & 0xfffffffc);
    iVar23 = 0;
    if (bVar7 != 0) {
      do {
        uVar10 = *puVar22;
        *(undefined4 *)(iVar13 + (uint)uVar10 * 4) = *puVar19;
        puVar22 = puVar22 + 1;
        iVar32 = uVar10 + 1;
        *(undefined4 *)(iVar13 + iVar32 * 4) = puVar19[1];
        *(undefined4 *)(iVar13 + 4 + iVar32 * 4) = puVar19[2];
        puVar19 = puVar19 + 3;
        iVar23 = iVar23 + 1;
      } while (iVar23 < (int)(uint)*(byte *)(iVar11 + 0x11));
    }
  }
  return CONCAT31((int3)((uint)puVar19 >> 8),1);
}


// ==== 0x62e840 FUN_0062e840

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0062e840(ushort *param_1,float *param_2)

{
  param_2[2] = (float)param_1[2] * 3.0518044e-05 - _K_ONE;
  param_2[3] = (float)param_1[3] * 3.0518044e-05 - _K_ONE;
  param_2[4] = (float)param_1[4] * 3.0518044e-05;
  param_2[5] = (float)param_1[5] * 3.0518044e-05;
  *(char *)(param_2 + 6) = (char)param_1[6];
  *param_2 = (float)*param_1 * _DAT_0070d5a8 * 1.5259022e-05 + -3.1415927;
  param_2[1] = (float)param_1[1] * _DAT_0070d5a8 * 1.5259022e-05 + -3.1415927;
  return;
}


// ==== 0x62e8f0 FUN_0062e8f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0062e8f0(byte *param_1,int param_2,float *param_3)

{
  param_3[2] = 0.0;
  param_3[1] = 0.0;
  *param_3 = 0.0;
  if (param_2 == 0) {
    *param_3 = (float)*param_1 * 0.007843138 - _K_ONE;
  }
  else if (param_2 == 1) {
    param_3[1] = (float)*param_1 * 0.007843138 - _K_ONE;
  }
  else {
    param_3[2] = (float)*param_1 * 0.007843138 - _K_ONE;
  }
  param_3[3] = (float)param_1[1] * 0.007843138 - _K_ONE;
  return;
}


// ==== 0x62e980 FUN_0062e980

void __thiscall FUN_0062e980(byte *param_1,int param_2,float *param_3)

{
  param_3[2] = 0.0;
  param_3[1] = 0.0;
  *param_3 = 0.0;
  if (*(char *)(param_2 + 0x18) == '\0') {
    *param_3 = (float)(*param_1 >> 4) * *(float *)(param_2 + 0x10) * 0.06666667 +
               *(float *)(param_2 + 8);
  }
  else if (*(char *)(param_2 + 0x18) == '\x01') {
    param_3[1] = (float)(*param_1 >> 4) * *(float *)(param_2 + 0x10) * 0.06666667 +
                 *(float *)(param_2 + 8);
  }
  else {
    param_3[2] = (float)(*param_1 >> 4) * *(float *)(param_2 + 0x10) * 0.06666667 +
                 *(float *)(param_2 + 8);
  }
  param_3[3] = (float)(*param_1 & 0xf) * *(float *)(param_2 + 0x14) * 0.06666667 +
               *(float *)(param_2 + 0xc);
  return;
}


// ==== 0x62ea30 FUN_0062ea30

undefined4 * __fastcall FUN_0062ea30(undefined4 *param_1)

{
  FUN_00628eb0();
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  *param_1 = &PTR_FUN_006a8288;
  param_1[6] = 0xffffffff;
  param_1[7] = 0xffffffff;
  param_1[2] = 0x13;
  return param_1;
}


// ==== 0x62ea70 FUN_0062ea70

void __fastcall FUN_0062ea70(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_28 [24];
  char cStack_10;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    iVar1 = *(int *)(param_1 + 0xc);
    *(uint *)(param_1 + 0x14) = (uint)*(byte *)(iVar1 + 6) * 0xe + iVar1 + 0x10;
    *(uint *)(param_1 + 0x18) =
         ((1 << (*(byte *)(iVar1 + 7) & 0x1f)) + 1) * (uint)*(byte *)(iVar1 + 6) + 1 & 0xfffffffe;
    uVar2 = (**(code **)(*DAT_0070d364 + 0x14))((uint)*(byte *)(iVar1 + 6) << 4);
    *(undefined4 *)(param_1 + 0x20) = uVar2;
    *(undefined4 *)(param_1 + 0x24) = uVar2;
    *(int *)(param_1 + 0x10) = iVar1 + 0x10;
    uVar2 = (**(code **)(*DAT_0070d364 + 0x14))((uint)*(byte *)(iVar1 + 6) << 4);
    *(undefined4 *)(param_1 + 0x28) = uVar2;
    uVar2 = (**(code **)(*DAT_0070d364 + 0x14))((uint)*(byte *)(iVar1 + 6) << 4);
    *(undefined4 *)(param_1 + 0x2c) = uVar2;
    if (*(char *)(iVar1 + 6) != '\0') {
      iVar4 = 0;
      iVar3 = 0;
      do {
        FUN_0062e840(auStack_28);
        if (cStack_10 == '\0') {
          *(undefined4 *)(*(int *)(param_1 + 0x28) + iVar4) = 0;
          *(undefined4 *)(*(int *)(param_1 + 0x28) + 4 + iVar4) = 0;
          *(undefined4 *)(*(int *)(param_1 + 0x28) + 8 + iVar4) = 0;
          *(undefined4 *)(*(int *)(param_1 + 0x28) + 0xc + iVar4) = 0x3f800000;
          FUN_0062b9b0(&stack0xffffffcc,*(int *)(param_1 + 0x2c) + iVar4);
        }
        else if (cStack_10 == '\x01') {
          FUN_0062b9b0(&stack0xffffffcc,*(int *)(param_1 + 0x28) + iVar4);
          FUN_0062b9b0(&stack0xffffffcc,*(int *)(param_1 + 0x2c) + iVar4);
        }
        else {
          FUN_0062b9b0(&stack0xffffffcc,*(int *)(param_1 + 0x28) + iVar4);
          *(undefined4 *)(*(int *)(param_1 + 0x2c) + iVar4) = 0;
          *(undefined4 *)(*(int *)(param_1 + 0x2c) + 4 + iVar4) = 0;
          *(undefined4 *)(*(int *)(param_1 + 0x2c) + 8 + iVar4) = 0;
          *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xc + iVar4) = 0x3f800000;
        }
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x10;
      } while (iVar3 < (int)(uint)*(byte *)(iVar1 + 6));
    }
  }
  return;
}


// ==== 0x62ec30 FUN_0062ec30

void __fastcall FUN_0062ec30(float *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int in_EAX;
  float *unaff_ESI;
  
  fVar1 = *unaff_ESI * *(float *)(param_2 + 0xc);
  fVar2 = *(float *)(param_2 + 4) * unaff_ESI[3];
  fVar3 = -(*(float *)(param_2 + 4) * *unaff_ESI);
  fVar4 = unaff_ESI[3] * *(float *)(param_2 + 0xc);
  *param_1 = fVar1 * *(float *)(in_EAX + 0xc) - fVar2 * *(float *)(in_EAX + 8);
  param_1[1] = fVar1 * *(float *)(in_EAX + 8) + fVar2 * *(float *)(in_EAX + 0xc);
  param_1[2] = fVar3 * *(float *)(in_EAX + 0xc) + fVar4 * *(float *)(in_EAX + 8);
  param_1[3] = fVar4 * *(float *)(in_EAX + 0xc) - fVar3 * *(float *)(in_EAX + 8);
  return;
}


// ==== 0x62eca0 FUN_0062eca0

undefined4 * __thiscall FUN_0062eca0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a8288;
  if (param_1[8] != 0) {
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[8]);
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[10]);
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[0xb]);
  }
  FUN_00628ed0();
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x30);
  }
  return param_1;
}


// ==== 0x62ed00 FUN_0062ed00

undefined4 __thiscall FUN_0062ed00(int *param_1,float param_2,int param_3,uint param_4)

{
  float fVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  undefined2 uVar16;
  undefined3 uVar15;
  float *pfVar13;
  int iVar14;
  int iVar17;
  uint uVar18;
  float *pfVar19;
  float *pfVar20;
  ushort *puVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  int iVar25;
  int iStack_64;
  int iStack_60;
  int iStack_5c;
  uint uStack_58;
  float afStack_48 [2];
  float fStack_40;
  float fStack_3c;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  undefined1 auStack_1c [28];
  
  if (param_4 != 0) {
    uVar10 = (**(code **)(*param_1 + 0x48))(param_2,param_4,param_3);
    return uVar10;
  }
  FUN_0062ea70();
  iVar4 = param_1[3];
  uVar11 = FUN_00629350(param_2);
  puVar5 = *(ushort **)(iVar4 + 8);
  if (puVar5 == (ushort *)0x0) {
    if ((int)uVar11 < 0) {
      param_4 = 0;
    }
    else {
      param_4 = uVar11;
      if ((int)(uint)*(ushort *)(iVar4 + 4) <= (int)uVar11) {
        param_4 = *(ushort *)(iVar4 + 4) - 1;
      }
    }
  }
  else if ((int)uVar11 < (int)(uint)*puVar5) {
    param_4 = 0;
  }
  else {
    if (param_1[7] < 1) {
      iVar17 = 0;
    }
    else {
      iVar17 = param_1[7] + -1;
    }
    puVar21 = puVar5 + iVar17;
    if ((int)uVar11 < (int)(uint)puVar5[iVar17]) {
      for (; (0 < iVar17 && ((int)uVar11 < (int)(uint)*puVar21)); puVar21 = puVar21 + -1) {
        iVar17 = iVar17 + -1;
      }
    }
    else {
      while ((iVar17 < (int)(*(ushort *)(iVar4 + 4) - 2) &&
             (puVar21 = puVar21 + 1, (int)(uint)*puVar21 <= (int)uVar11))) {
        iVar17 = iVar17 + 1;
      }
    }
    param_4 = iVar17 + 1;
  }
  bVar2 = *(byte *)(iVar4 + 7);
  iVar17 = *(int *)(iVar4 + 0xc);
  uVar12 = 0x7fffffff >> (0x1f - bVar2 & 0x1f);
  iVar22 = (int)param_4 >> (bVar2 & 0x1f);
  uVar23 = param_1[7];
  uVar18 = uVar12 & param_4;
  if (((uVar23 == 0xffffffff) || (iVar22 != (int)uVar23 >> (bVar2 & 0x1f))) ||
     ((int)param_4 < (int)uVar23)) {
    uVar12 = 0;
    uStack_58 = 0;
    if (*(char *)(iVar4 + 6) != '\0') {
      iStack_64 = 0;
      iVar25 = 0;
      do {
        FUN_0062e8f0(*(undefined2 *)(param_1[4] + 0xc + iStack_64),param_1[9] + iVar25);
        iStack_64 = iStack_64 + 0xe;
        uVar12 = uStack_58 + 1;
        iVar25 = iVar25 + 0x10;
        uStack_58 = uVar12;
      } while ((int)uVar12 < (int)(uint)*(byte *)(iVar4 + 6));
    }
    uVar23 = 0;
  }
  else {
    uVar23 = uVar23 & uVar12;
  }
  if ((int)uVar23 < (int)uVar18) {
    uVar12 = (uint)*(byte *)(iVar4 + 6);
    iStack_60 = uVar18 - uVar23;
    do {
      uStack_58 = 0;
      if (uVar12 != 0) {
        iVar25 = 0;
        do {
          FUN_0062e840(afStack_48);
          FUN_0062e980(afStack_48,&fStack_2c);
          *(float *)(param_1[9] + iVar25) = fStack_2c + *(float *)(param_1[9] + iVar25);
          pfVar19 = (float *)(iVar25 + 4 + param_1[9]);
          uStack_58 = uStack_58 + 1;
          *pfVar19 = fStack_28 + *pfVar19;
          pfVar19 = (float *)(iVar25 + 8 + param_1[9]);
          *pfVar19 = fStack_24 + *pfVar19;
          pfVar19 = (float *)(iVar25 + 0xc + param_1[9]);
          iVar25 = iVar25 + 0x10;
          *pfVar19 = fStack_20 + *pfVar19;
          uVar12 = (uint)*(byte *)(iVar4 + 6);
        } while ((int)uStack_58 < (int)uVar12);
      }
      iStack_60 = iStack_60 + -1;
    } while (iStack_60 != 0);
  }
  param_1[7] = param_4;
  puVar5 = *(ushort **)(iVar4 + 8);
  uVar16 = (undefined2)(uVar12 >> 0x10);
  if (puVar5 == (ushort *)0x0) {
    fVar1 = (float)(int)uVar11;
    uVar11 = CONCAT22(uVar16,(ushort)(param_2 < fVar1) << 8 |
                             (ushort)(NAN(param_2) || NAN(fVar1)) << 10 |
                             (ushort)(param_2 == fVar1) << 0xe);
    if (param_2 != fVar1) {
      param_2 = param_2 - fVar1;
      goto LAB_0062f03f;
    }
  }
  else if (param_4 == 0) {
    uVar11 = CONCAT22(uVar16,(ushort)(param_2 < 0.0) << 8 | (ushort)NAN(param_2) << 10 |
                             (ushort)(param_2 == 0.0) << 0xe);
    if (param_2 != 0.0) {
      param_2 = param_2 / (float)*puVar5;
LAB_0062f03f:
      uVar11 = *(ushort *)(iVar4 + 4) - 1;
      if ((int)param_4 < (int)uVar11) {
        iVar24 = (int)(param_4 + 1) >> (bVar2 & 0x1f);
        iVar25 = param_1[6] * iVar24 + param_1[5];
        uVar15 = (undefined3)((uint)iVar4 >> 8);
        if (iVar24 == iVar22) {
          iVar22 = 0;
          iVar24 = 0;
          if (*(char *)(iVar4 + 6) != '\0') {
            iStack_5c = 0;
            do {
              iVar6 = param_1[4];
              FUN_0062e840(auStack_1c);
              FUN_0062e980(auStack_1c,&fStack_2c);
              fStack_2c = fStack_2c + *(float *)(iVar22 + param_1[9]);
              iVar25 = iVar22 + param_1[9];
              fStack_28 = fStack_28 + *(float *)(iVar25 + 4);
              fStack_24 = fStack_24 + *(float *)(iVar25 + 8);
              fStack_20 = fStack_20 + *(float *)(iVar25 + 0xc);
              FUN_00631410(param_2);
              sVar3 = *(short *)(iStack_5c + iVar6 + 0xc);
              if (sVar3 == 0) {
                pfVar13 = (float *)(param_1[0xb] + iVar22);
                pfVar19 = (float *)((uint)*(byte *)(iVar17 + iVar24) * 0x30 + 0x10 + param_3);
                *pfVar19 = afStack_48[0] * pfVar13[3] + fStack_3c * *pfVar13;
                pfVar19[1] = afStack_48[0] * pfVar13[2] + fStack_3c * pfVar13[1];
                pfVar19[2] = fStack_3c * pfVar13[2] - afStack_48[0] * pfVar13[1];
                fVar1 = pfVar13[3];
                fVar7 = afStack_48[0] * *pfVar13;
LAB_0062f3ab:
                pfVar19[3] = fStack_3c * fVar1 - fVar7;
              }
              else {
                if (sVar3 != 1) {
                  pfVar19 = (float *)((uint)*(byte *)(iVar17 + iVar24) * 0x30 + 0x10 + param_3);
                  pfVar13 = (float *)(param_1[10] + iVar22);
                  *pfVar19 = fStack_3c * *(float *)(param_1[10] + iVar22) - fStack_40 * pfVar13[1];
                  pfVar19[1] = fStack_3c * pfVar13[1] + fStack_40 * *pfVar13;
                  pfVar19[2] = fStack_3c * pfVar13[2] + fStack_40 * pfVar13[3];
                  fVar1 = pfVar13[3];
                  fVar7 = fStack_40 * pfVar13[2];
                  goto LAB_0062f3ab;
                }
                FUN_0062ec30();
              }
              iVar24 = iVar24 + 1;
              iStack_5c = iStack_5c + 0xe;
              iVar22 = iVar22 + 0x10;
              if ((int)(uint)*(byte *)(iVar4 + 6) <= iVar24) {
                return CONCAT31(uVar15,1);
              }
            } while( true );
          }
        }
        else {
          iVar22 = 0;
          if (*(char *)(iVar4 + 6) != '\0') {
            iVar25 = 0;
            iStack_60 = 0;
            do {
              sVar3 = *(short *)(param_1[4] + 0xc + iStack_60);
              FUN_0062e8f0(sVar3,&fStack_2c);
              FUN_00631410(param_2);
              if (sVar3 == 0) {
                pfVar13 = (float *)(param_1[0xb] + iVar25);
                pfVar19 = (float *)((uint)*(byte *)(iVar17 + iVar22) * 0x30 + 0x10 + param_3);
                *pfVar19 = afStack_48[0] * pfVar13[3] + fStack_3c * *pfVar13;
                pfVar19[1] = fStack_3c * pfVar13[1] + afStack_48[0] * pfVar13[2];
                pfVar19[2] = fStack_3c * pfVar13[2] - afStack_48[0] * pfVar13[1];
                fVar1 = pfVar13[3];
                fVar7 = afStack_48[0] * *pfVar13;
LAB_0062f1cb:
                pfVar19[3] = fStack_3c * fVar1 - fVar7;
              }
              else {
                if (sVar3 != 1) {
                  pfVar19 = (float *)((uint)*(byte *)(iVar17 + iVar22) * 0x30 + 0x10 + param_3);
                  pfVar13 = (float *)(param_1[10] + iVar25);
                  *pfVar19 = fStack_3c * *(float *)(param_1[10] + iVar25) - fStack_40 * pfVar13[1];
                  pfVar19[1] = fStack_3c * pfVar13[1] + fStack_40 * *pfVar13;
                  pfVar19[2] = fStack_3c * pfVar13[2] + fStack_40 * pfVar13[3];
                  fVar1 = pfVar13[3];
                  fVar7 = fStack_40 * pfVar13[2];
                  goto LAB_0062f1cb;
                }
                FUN_0062ec30();
              }
              iVar22 = iVar22 + 1;
              iStack_60 = iStack_60 + 0xe;
              iVar25 = iVar25 + 0x10;
              if ((int)(uint)*(byte *)(iVar4 + 6) <= iVar22) {
                return CONCAT31(uVar15,1);
              }
            } while( true );
          }
        }
        goto LAB_0062f583;
      }
    }
  }
  else {
    fVar1 = (float)puVar5[param_4 - 1];
    uVar11 = (uint)(ushort)((ushort)(param_2 < fVar1) << 8 |
                            (ushort)(NAN(param_2) || NAN(fVar1)) << 10 |
                           (ushort)(param_2 == fVar1) << 0xe);
    if (param_2 != fVar1) {
      param_2 = (param_2 - fVar1) / ((float)puVar5[param_4] - fVar1);
      goto LAB_0062f03f;
    }
  }
  iVar22 = 0;
  iVar25 = CONCAT31((int3)(uVar11 >> 8),*(char *)(iVar4 + 6));
  if (*(char *)(iVar4 + 6) != '\0') {
    iVar24 = 0;
    param_2 = 0.0;
    do {
      sVar3 = *(short *)((int)param_2 + 0xc + param_1[4]);
      if (sVar3 == 0) {
        pfVar19 = (float *)((uint)*(byte *)(iVar17 + iVar22) * 0x30 + 0x10 + param_3);
        pfVar13 = (float *)(param_1[0xb] + iVar24);
        pfVar20 = (float *)(param_1[9] + iVar24);
        *pfVar19 = pfVar13[3] * *pfVar20 + *pfVar13 * pfVar20[3];
        pfVar19[1] = *pfVar20 * pfVar13[2] + pfVar20[3] * pfVar13[1];
        pfVar19[2] = pfVar20[3] * pfVar13[2] - *pfVar20 * pfVar13[1];
        fVar1 = pfVar13[3] * pfVar20[3];
        fVar7 = *pfVar20 * *pfVar13;
LAB_0062f559:
        pfVar19[3] = fVar1 - fVar7;
      }
      else {
        if (sVar3 != 1) {
          pfVar19 = (float *)((uint)*(byte *)(iVar17 + iVar22) * 0x30 + 0x10 + param_3);
          iVar25 = param_1[9] + iVar24;
          pfVar13 = (float *)(param_1[10] + iVar24);
          *pfVar19 = *(float *)(param_1[10] + iVar24) * *(float *)(iVar25 + 0xc) -
                     pfVar13[1] * *(float *)(iVar25 + 8);
          pfVar19[1] = pfVar13[1] * *(float *)(iVar25 + 0xc) + *pfVar13 * *(float *)(iVar25 + 8);
          pfVar19[2] = pfVar13[3] * *(float *)(iVar25 + 8) + pfVar13[2] * *(float *)(iVar25 + 0xc);
          fVar1 = pfVar13[3] * *(float *)(iVar25 + 0xc);
          fVar7 = pfVar13[2] * *(float *)(iVar25 + 8);
          goto LAB_0062f559;
        }
        iVar25 = param_1[10];
        pfVar19 = (float *)((uint)*(byte *)(iVar17 + iVar22) * 0x30 + 0x10 + param_3);
        iVar6 = param_1[9];
        fVar1 = *(float *)(iVar6 + 0xc + iVar24) * *(float *)(iVar25 + iVar24);
        iVar14 = param_1[0xb] + iVar24;
        fVar7 = *(float *)(iVar6 + 4 + iVar24) * *(float *)(iVar25 + 0xc + iVar24);
        fVar8 = -(*(float *)(iVar6 + iVar24 + 4) * *(float *)(iVar25 + iVar24));
        fVar9 = *(float *)(iVar6 + iVar24 + 0xc) * ((float *)(iVar25 + iVar24))[3];
        *pfVar19 = fVar1 * *(float *)(iVar14 + 0xc) - fVar7 * *(float *)(iVar14 + 8);
        pfVar19[1] = fVar1 * *(float *)(iVar14 + 8) + fVar7 * *(float *)(iVar14 + 0xc);
        pfVar19[2] = fVar8 * *(float *)(iVar14 + 0xc) + fVar9 * *(float *)(iVar14 + 8);
        pfVar19[3] = fVar9 * *(float *)(iVar14 + 0xc) - fVar8 * *(float *)(iVar14 + 8);
      }
      iVar22 = iVar22 + 1;
      param_2 = (float)((int)param_2 + 0xe);
      iVar24 = iVar24 + 0x10;
      iVar25 = iVar4;
    } while (iVar22 < (int)(uint)*(byte *)(iVar4 + 6));
  }
LAB_0062f583:
  return CONCAT31((int3)((uint)iVar25 >> 8),1);
}


// ==== 0x62f590 FUN_0062f590

undefined4 __thiscall FUN_0062f590(int param_1,float param_2,int param_3,int param_4)

{
  float fVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  ushort *puVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  int iVar10;
  undefined2 uVar14;
  uint uVar11;
  float *pfVar12;
  int iVar13;
  ushort *puVar15;
  uint uVar16;
  float *pfVar17;
  int iVar18;
  float *pfVar19;
  uint uVar20;
  int iVar21;
  int iVar22;
  uint uVar23;
  float fStack_68;
  int iStack_60;
  int iStack_5c;
  uint uStack_58;
  float afStack_48 [2];
  float fStack_40;
  float fStack_3c;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  undefined1 auStack_1c [28];
  
  FUN_0062ea70();
  iVar4 = *(int *)(param_1 + 0xc);
  if (param_2 < 0.0) {
    fVar1 = param_2 + 0.499999;
  }
  else {
    fVar1 = param_2 - 0.499999;
  }
  uStack_58 = (uint)ROUND(fVar1);
  puVar5 = *(ushort **)(iVar4 + 8);
  if (puVar5 == (ushort *)0x0) {
    if ((int)uStack_58 < 0) {
      uVar11 = 0;
    }
    else {
      uVar11 = uStack_58;
      if ((int)(uint)*(ushort *)(iVar4 + 4) <= (int)uStack_58) {
        uVar11 = *(ushort *)(iVar4 + 4) - 1;
      }
    }
  }
  else if ((int)uStack_58 < (int)(uint)*puVar5) {
    uVar11 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x1c) < 1) {
      iVar9 = 0;
    }
    else {
      iVar9 = *(int *)(param_1 + 0x1c) + -1;
    }
    puVar15 = puVar5 + iVar9;
    if ((int)uStack_58 < (int)(uint)puVar5[iVar9]) {
      for (; (0 < iVar9 && ((int)uStack_58 < (int)(uint)*puVar15)); puVar15 = puVar15 + -1) {
        iVar9 = iVar9 + -1;
      }
    }
    else {
      while ((iVar9 < (int)(*(ushort *)(iVar4 + 4) - 2) &&
             (puVar15 = puVar15 + 1, (int)(uint)*puVar15 <= (int)uStack_58))) {
        iVar9 = iVar9 + 1;
      }
    }
    uVar11 = iVar9 + 1;
  }
  bVar2 = *(byte *)(iVar4 + 7);
  iVar9 = *(int *)(iVar4 + 0xc);
  uVar20 = 0x7fffffff >> (0x1f - bVar2 & 0x1f);
  iVar10 = (int)uVar11 >> (bVar2 & 0x1f);
  uVar16 = uVar20 & uVar11;
  uVar23 = *(uint *)(param_1 + 0x1c);
  if (((uVar23 == 0xffffffff) || (iVar10 != (int)uVar23 >> (bVar2 & 0x1f))) ||
     ((int)uVar11 < (int)uVar23)) {
    iVar21 = 0;
    if (*(char *)(iVar4 + 6) != '\0') {
      iVar13 = 0;
      iVar22 = 0;
      do {
        if ((*(uint *)(param_3 + ((int)(uint)*(byte *)(iVar21 + iVar9) >> 5) * 4) &
            1 << (*(byte *)(iVar21 + iVar9) & 0x1f)) != 0) {
          FUN_0062e8f0(*(undefined2 *)(*(int *)(param_1 + 0x10) + 0xc + iVar13),
                       *(int *)(param_1 + 0x24) + iVar22);
        }
        iVar21 = iVar21 + 1;
        iVar22 = iVar22 + 0x10;
        iVar13 = iVar13 + 0xe;
      } while (iVar21 < (int)(uint)*(byte *)(iVar4 + 6));
    }
    uVar23 = 0;
  }
  else {
    uVar23 = uVar23 & uVar20;
  }
  if ((int)uVar23 < (int)uVar16) {
    uVar20 = (uint)*(byte *)(iVar4 + 6);
    iStack_5c = uVar16 - uVar23;
    do {
      iVar21 = 0;
      if (uVar20 != 0) {
        iVar22 = 0;
        do {
          if ((*(uint *)(param_3 + ((int)(uint)*(byte *)(iVar21 + iVar9) >> 5) * 4) &
              1 << (*(byte *)(iVar21 + iVar9) & 0x1f)) != 0) {
            FUN_0062e840(afStack_48);
            FUN_0062e980(afStack_48,&fStack_2c);
            *(float *)(*(int *)(param_1 + 0x24) + iVar22) =
                 fStack_2c + *(float *)(*(int *)(param_1 + 0x24) + iVar22);
            *(float *)(*(int *)(param_1 + 0x24) + 4 + iVar22) =
                 fStack_28 + *(float *)(*(int *)(param_1 + 0x24) + 4 + iVar22);
            *(float *)(*(int *)(param_1 + 0x24) + 8 + iVar22) =
                 fStack_24 + *(float *)(*(int *)(param_1 + 0x24) + 8 + iVar22);
            *(float *)(*(int *)(param_1 + 0x24) + 0xc + iVar22) =
                 fStack_20 + *(float *)(*(int *)(param_1 + 0x24) + 0xc + iVar22);
          }
          uVar20 = (uint)*(byte *)(iVar4 + 6);
          iVar21 = iVar21 + 1;
          iVar22 = iVar22 + 0x10;
        } while (iVar21 < (int)uVar20);
      }
      iStack_5c = iStack_5c + -1;
    } while (iStack_5c != 0);
  }
  *(uint *)(param_1 + 0x1c) = uVar11;
  puVar5 = *(ushort **)(iVar4 + 8);
  iVar21 = 0;
  uVar14 = (undefined2)((uint)param_1 >> 0x10);
  if (puVar5 == (ushort *)0x0) {
    fStack_68 = (float)(int)uStack_58;
    uVar23 = CONCAT22(uVar14,(ushort)(param_2 < fStack_68) << 8 |
                             (ushort)(NAN(param_2) || NAN(fStack_68)) << 10 |
                             (ushort)(param_2 == fStack_68) << 0xe);
    if (param_2 != fStack_68) {
      fStack_68 = param_2 - fStack_68;
      goto LAB_0062f8ed;
    }
  }
  else if (uVar11 == 0) {
    uVar23 = CONCAT22(uVar14,(ushort)(param_2 < 0.0) << 8 | (ushort)NAN(param_2) << 10 |
                             (ushort)(param_2 == 0.0) << 0xe);
    if (param_2 != 0.0) {
      fStack_68 = param_2 / (float)*puVar5;
LAB_0062f8ed:
      uVar23 = *(ushort *)(iVar4 + 4) - 1;
      if ((int)uVar11 < (int)uVar23) {
        iVar22 = (int)(uVar11 + 1) >> (bVar2 & 0x1f);
        uVar11 = *(int *)(param_1 + 0x18) * iVar22 + *(int *)(param_1 + 0x14);
        if (iVar22 == iVar10) {
          iStack_5c = 0;
          if (*(char *)(iVar4 + 6) != '\0') {
            iStack_60 = 0;
            do {
              uVar11 = (uint)*(byte *)(iStack_5c + iVar9);
              if ((*(uint *)(param_3 + ((int)uVar11 >> 5) * 4) &
                  1 << (*(byte *)(iStack_5c + iVar9) & 0x1f)) != 0) {
                iVar22 = *(int *)(param_1 + 0x10);
                FUN_0062e840(auStack_1c);
                FUN_0062e980(auStack_1c,&fStack_2c);
                fStack_2c = fStack_2c + *(float *)(*(int *)(param_1 + 0x24) + iVar21);
                iVar10 = *(int *)(param_1 + 0x24) + iVar21;
                fStack_28 = fStack_28 + *(float *)(iVar10 + 4);
                fStack_24 = fStack_24 + *(float *)(iVar10 + 8);
                fStack_20 = fStack_20 + *(float *)(iVar10 + 0xc);
                FUN_00631410(fStack_68);
                sVar3 = *(short *)(iVar22 + iStack_60 + 0xc);
                if (sVar3 == 0) {
                  iVar10 = *(int *)(param_1 + 0x2c);
                  pfVar12 = (float *)(iVar10 + iVar21);
                  pfVar17 = (float *)(uVar11 * 0x30 + 0x10 + param_4);
                  *pfVar17 = fStack_3c * *(float *)(iVar10 + iVar21) +
                             afStack_48[0] * *(float *)(iVar10 + 0xc + iVar21);
                  pfVar17[1] = afStack_48[0] * pfVar12[2] + fStack_3c * pfVar12[1];
                  pfVar17[2] = fStack_3c * pfVar12[2] - afStack_48[0] * pfVar12[1];
                  fVar1 = pfVar12[3];
                  fVar6 = afStack_48[0] * *pfVar12;
                }
                else {
                  if (sVar3 == 1) {
                    FUN_0062ec30();
                    goto LAB_0062fc88;
                  }
                  pfVar17 = (float *)(uVar11 * 0x30 + 0x10 + param_4);
                  pfVar12 = (float *)(*(int *)(param_1 + 0x28) + iVar21);
                  *pfVar17 = fStack_3c * *(float *)(*(int *)(param_1 + 0x28) + iVar21) -
                             fStack_40 * pfVar12[1];
                  pfVar17[1] = fStack_3c * pfVar12[1] + fStack_40 * *pfVar12;
                  pfVar17[2] = fStack_3c * pfVar12[2] + fStack_40 * pfVar12[3];
                  fVar1 = pfVar12[3];
                  fVar6 = fStack_40 * pfVar12[2];
                }
                pfVar17[3] = fStack_3c * fVar1 - fVar6;
              }
LAB_0062fc88:
              iStack_5c = iStack_5c + 1;
              iStack_60 = iStack_60 + 0xe;
              iVar21 = iVar21 + 0x10;
              if ((int)(uint)*(byte *)(iVar4 + 6) <= iStack_5c) {
                return CONCAT31((int3)((uint)iStack_5c >> 8),1);
              }
            } while( true );
          }
        }
        else {
          iStack_60 = 0;
          if (*(char *)(iVar4 + 6) != '\0') {
            uStack_58 = 0;
            do {
              uVar11 = (uint)*(byte *)(iStack_60 + iVar9);
              if ((*(uint *)(param_3 + ((int)uVar11 >> 5) * 4) &
                  1 << (*(byte *)(iStack_60 + iVar9) & 0x1f)) != 0) {
                sVar3 = *(short *)(*(int *)(param_1 + 0x10) + 0xc + uStack_58);
                FUN_0062e8f0(sVar3,&fStack_2c);
                FUN_00631410(fStack_68);
                if (sVar3 == 0) {
                  pfVar17 = (float *)(uVar11 * 0x30 + 0x10 + param_4);
                  pfVar12 = (float *)(*(int *)(param_1 + 0x2c) + iVar21);
                  *pfVar17 = fStack_3c * *pfVar12 +
                             afStack_48[0] * *(float *)(*(int *)(param_1 + 0x2c) + 0xc + iVar21);
                  pfVar17[1] = afStack_48[0] * pfVar12[2] + fStack_3c * pfVar12[1];
                  pfVar17[2] = fStack_3c * pfVar12[2] - afStack_48[0] * pfVar12[1];
                  fVar1 = pfVar12[3];
                  fVar6 = afStack_48[0] * *pfVar12;
                }
                else {
                  if (sVar3 == 1) {
                    FUN_0062ec30();
                    goto LAB_0062fa8a;
                  }
                  pfVar17 = (float *)(uVar11 * 0x30 + 0x10 + param_4);
                  pfVar12 = (float *)(*(int *)(param_1 + 0x28) + iVar21);
                  *pfVar17 = fStack_3c * *(float *)(*(int *)(param_1 + 0x28) + iVar21) -
                             fStack_40 * pfVar12[1];
                  pfVar17[1] = fStack_3c * pfVar12[1] + fStack_40 * *pfVar12;
                  pfVar17[2] = fStack_3c * pfVar12[2] + fStack_40 * pfVar12[3];
                  fVar1 = pfVar12[3];
                  fVar6 = fStack_40 * pfVar12[2];
                }
                pfVar17[3] = fStack_3c * fVar1 - fVar6;
              }
LAB_0062fa8a:
              iStack_60 = iStack_60 + 1;
              uStack_58 = uStack_58 + 0xe;
              iVar21 = iVar21 + 0x10;
              if ((int)(uint)*(byte *)(iVar4 + 6) <= iStack_60) {
                return CONCAT31((int3)((uint)iStack_60 >> 8),1);
              }
            } while( true );
          }
        }
        goto LAB_0062fe5a;
      }
    }
  }
  else {
    fVar1 = (float)puVar5[uVar11 - 1];
    uVar23 = (uint)(ushort)((ushort)(param_2 < fVar1) << 8 |
                            (ushort)(NAN(param_2) || NAN(fVar1)) << 10 |
                           (ushort)(param_2 == fVar1) << 0xe);
    if (param_2 != fVar1) {
      fStack_68 = (param_2 - fVar1) / ((float)puVar5[uVar11] - fVar1);
      goto LAB_0062f8ed;
    }
  }
  uVar11 = CONCAT31((int3)(uVar23 >> 8),*(char *)(iVar4 + 6));
  if (*(char *)(iVar4 + 6) != '\0') {
    iVar22 = 0;
    iVar10 = 0;
    do {
      bVar2 = *(byte *)(iVar21 + iVar9);
      if ((*(uint *)(param_3 + ((int)(uint)bVar2 >> 5) * 4) & 1 << (bVar2 & 0x1f)) != 0) {
        sVar3 = *(short *)(*(int *)(param_1 + 0x10) + 0xc + iVar10);
        iVar13 = (uint)bVar2 * 0x30;
        if (sVar3 == 0) {
          pfVar17 = (float *)(iVar13 + 0x10 + param_4);
          iVar13 = *(int *)(param_1 + 0x24);
          pfVar12 = (float *)(*(int *)(param_1 + 0x2c) + iVar22);
          pfVar19 = (float *)(iVar13 + iVar22);
          *pfVar17 = *(float *)(iVar13 + 0xc + iVar22) * *pfVar12 +
                     *(float *)(*(int *)(param_1 + 0x2c) + 0xc + iVar22) *
                     *(float *)(iVar13 + iVar22);
          pfVar17[1] = pfVar12[2] * *pfVar19 + pfVar19[3] * pfVar12[1];
          pfVar17[2] = pfVar19[3] * pfVar12[2] - pfVar12[1] * *pfVar19;
          fVar1 = pfVar19[3] * pfVar12[3];
          fVar6 = *pfVar19 * *pfVar12;
        }
        else {
          pfVar17 = (float *)(iVar13 + 0x10 + param_4);
          if (sVar3 == 1) {
            iVar13 = *(int *)(param_1 + 0x2c) + iVar22;
            fVar7 = *(float *)(*(int *)(param_1 + 0x28) + iVar22) *
                    *(float *)(*(int *)(param_1 + 0x24) + 0xc + iVar22);
            iVar18 = *(int *)(param_1 + 0x24) + iVar22;
            pfVar12 = (float *)(*(int *)(param_1 + 0x28) + iVar22);
            fVar8 = *(float *)(iVar18 + 4) * pfVar12[3];
            fVar6 = -(*(float *)(iVar18 + 4) * *pfVar12);
            fVar1 = pfVar12[3] * *(float *)(iVar18 + 0xc);
            *pfVar17 = fVar7 * *(float *)(iVar13 + 0xc) - fVar8 * *(float *)(iVar13 + 8);
            pfVar17[1] = fVar7 * *(float *)(iVar13 + 8) + fVar8 * *(float *)(iVar13 + 0xc);
            pfVar17[2] = fVar6 * *(float *)(iVar13 + 0xc) + fVar1 * *(float *)(iVar13 + 8);
            fVar1 = fVar1 * *(float *)(iVar13 + 0xc);
            fVar6 = fVar6 * *(float *)(iVar13 + 8);
          }
          else {
            iVar13 = *(int *)(param_1 + 0x24) + iVar22;
            pfVar12 = (float *)(*(int *)(param_1 + 0x28) + iVar22);
            *pfVar17 = *(float *)(*(int *)(param_1 + 0x24) + 0xc + iVar22) *
                       *(float *)(*(int *)(param_1 + 0x28) + iVar22) -
                       *(float *)(iVar13 + 8) * pfVar12[1];
            pfVar17[1] = *(float *)(iVar13 + 0xc) * pfVar12[1] + *(float *)(iVar13 + 8) * *pfVar12;
            pfVar17[2] = pfVar12[2] * *(float *)(iVar13 + 0xc) + pfVar12[3] * *(float *)(iVar13 + 8)
            ;
            fVar1 = pfVar12[3] * *(float *)(iVar13 + 0xc);
            fVar6 = pfVar12[2] * *(float *)(iVar13 + 8);
          }
        }
        pfVar17[3] = fVar1 - fVar6;
      }
      uVar11 = (uint)*(byte *)(iVar4 + 6);
      iVar21 = iVar21 + 1;
      iVar10 = iVar10 + 0xe;
      iVar22 = iVar22 + 0x10;
    } while (iVar21 < (int)uVar11);
  }
LAB_0062fe5a:
  return CONCAT31((int3)(uVar11 >> 8),1);
}


// ==== 0x62fe70 FUN_0062fe70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0062fe70(ushort *param_1,float *param_2)

{
  *param_2 = (float)*param_1 * 3.0518044e-05 - _K_ONE;
  param_2[1] = (float)param_1[1] * 3.0518044e-05 - _K_ONE;
  param_2[2] = (float)param_1[2] * 3.0518044e-05 - _K_ONE;
  param_2[3] = (float)param_1[3] * 3.0518044e-05 - _K_ONE;
  param_2[4] = (float)param_1[4] * 3.0518044e-05;
  param_2[5] = (float)param_1[5] * 3.0518044e-05;
  param_2[6] = (float)param_1[6] * 3.0518044e-05;
  param_2[7] = (float)param_1[7] * 3.0518044e-05;
  return;
}


// ==== 0x62ff40 FUN_0062ff40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0062ff40(ushort *param_1,float *param_2)

{
  *param_2 = (float)(*param_1 >> 4) * 0.0004884005 - _K_ONE;
  param_2[1] = (float)(param_1[1] >> 4) * 0.0004884005 - _K_ONE;
  param_2[2] = (float)(param_1[2] >> 4) * 0.0004884005 - _K_ONE;
  param_2[3] = (float)((((byte)*param_1 & 0xf) * 0x10 + ((byte)param_1[1] & 0xf)) * 0x10 +
                      ((byte)param_1[2] & 0xf)) * 0.0004884005 - _K_ONE;
  return;
}


// ==== 0x62fff0 FUN_0062fff0

void __thiscall FUN_0062fff0(byte *param_1,float *param_2,float *param_3)

{
  *param_3 = (float)(*param_1 >> 2) * param_2[4] * 0.015873017 + *param_2;
  param_3[1] = (float)(param_1[1] >> 2) * param_2[5] * 0.015873017 + param_2[1];
  param_3[2] = (float)(param_1[2] >> 2) * param_2[6] * 0.015873017 + param_2[2];
  param_3[3] = (float)(byte)(((*param_1 & 3) * '\x04' + (param_1[1] & 3)) * '\x04' +
                            (param_1[2] & 3)) * param_2[7] * 0.015873017 + param_2[3];
  return;
}


// ==== 0x6300a0 FUN_006300a0

uint __fastcall FUN_006300a0(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (uint)*(byte *)(param_1 + 6);
  uVar4 = 1 << (*(byte *)(param_1 + 0x10) & 0x1f);
  uVar2 = (uint)*(ushort *)(param_1 + 4) % uVar4;
  iVar1 = uVar3 * 0x10 + 0x12 +
          param_1 + ((uVar4 + 1) * uVar3 * 3 + 1 & 0xfffffffe) * (*(ushort *)(param_1 + 4) / uVar4);
  if (0 < (int)uVar2) {
    iVar1 = iVar1 + (uVar2 + 1) * uVar3 * 3;
  }
  return *(byte *)(param_1 + 7) + 1 + iVar1 & 0xfffffffe;
}


// ==== 0x630100 FUN_00630100

undefined4 * __fastcall FUN_00630100(undefined4 *param_1)

{
  FUN_00628eb0();
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  *param_1 = &PTR_FUN_006a8318;
  param_1[6] = 0xffffffff;
  param_1[7] = 0xffffffff;
  param_1[10] = 0xffffffff;
  param_1[2] = 0x12;
  return param_1;
}


// ==== 0x630150 FUN_00630150

void __thiscall
FUN_00630150(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint uVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  uVar1 = (uint)*(byte *)(param_3 + 6);
  if (param_4 < param_5) {
    param_4 = param_5 - param_4;
    do {
      iVar2 = 0;
      if (uVar1 != 0) {
        iVar4 = 0;
        pfVar3 = (float *)(param_6 + 8);
        do {
          FUN_0062fff0(*(int *)(param_1 + 0x10) + iVar4,&local_10);
          iVar2 = iVar2 + 1;
          pfVar3[-2] = local_10 + pfVar3[-2];
          iVar4 = iVar4 + 0x20;
          pfVar3[-1] = local_c + pfVar3[-1];
          *pfVar3 = local_8 + *pfVar3;
          pfVar3[1] = local_4 + pfVar3[1];
          uVar1 = (uint)*(byte *)(param_3 + 6);
          pfVar3 = pfVar3 + 4;
        } while (iVar2 < (int)uVar1);
      }
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}


// ==== 0x630200 FUN_00630200

void __thiscall
FUN_00630200(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint uVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (param_5 <= param_4 + -1) {
    param_4 = ((param_4 + -1) - param_5) + 1;
    do {
      uVar1 = (uint)*(byte *)(param_3 + 6);
      iVar2 = uVar1 - 1;
      if (-1 < iVar2) {
        iVar4 = iVar2 * 0x20;
        pfVar3 = (float *)(iVar2 * 0x10 + 8 + param_6);
        do {
          FUN_0062fff0(*(int *)(param_1 + 0x10) + iVar4,&local_10);
          iVar4 = iVar4 + -0x20;
          uVar1 = uVar1 - 1;
          pfVar3[-2] = pfVar3[-2] - local_10;
          pfVar3[-1] = pfVar3[-1] - local_c;
          *pfVar3 = *pfVar3 - local_8;
          pfVar3[1] = pfVar3[1] - local_4;
          pfVar3 = pfVar3 + -4;
        } while (uVar1 != 0);
      }
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}


// ==== 0x6302c0 FUN_006302c0

void __thiscall FUN_006302c0(int param_1,int param_2,int param_3,int param_4)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar2 = param_2;
  if (param_3 != *(int *)(param_1 + 0x28)) {
    if (param_3 >> (*(byte *)(param_2 + 0x10) & 0x1f) == param_4) {
      param_4 = 0;
      if (*(char *)(param_2 + 6) != '\0') {
        param_2 = 0;
        iVar3 = 0;
        do {
          FUN_0062fff0(*(int *)(param_1 + 0x10) + param_2,&local_10);
          iVar4 = iVar3 + 0x10;
          *(float *)(iVar3 + *(int *)(param_1 + 0x30)) =
               local_10 + *(float *)(*(int *)(param_1 + 0x24) + iVar3);
          *(float *)(iVar3 + 4 + *(int *)(param_1 + 0x30)) =
               local_c + *(float *)(*(int *)(param_1 + 0x24) + -0xc + iVar4);
          *(float *)(iVar3 + 8 + *(int *)(param_1 + 0x30)) =
               local_8 + *(float *)(*(int *)(param_1 + 0x24) + -8 + iVar4);
          param_4 = param_4 + 1;
          *(float *)(iVar3 + 0xc + *(int *)(param_1 + 0x30)) =
               local_4 + *(float *)(*(int *)(param_1 + 0x24) + -4 + iVar4);
          param_2 = param_2 + 0x20;
          iVar3 = iVar4;
        } while (param_4 < (int)(uint)*(byte *)(iVar2 + 6));
      }
    }
    else {
      pcVar1 = (char *)(param_2 + 6);
      param_2 = 0;
      if (*pcVar1 != '\0') {
        iVar3 = 0;
        do {
          FUN_0062ff40(*(int *)(param_1 + 0x30) + iVar3);
          param_2 = param_2 + 1;
          iVar3 = iVar3 + 0x10;
        } while (param_2 < (int)(uint)*(byte *)(iVar2 + 6));
        *(int *)(param_1 + 0x28) = param_3;
        return;
      }
    }
    *(int *)(param_1 + 0x28) = param_3;
  }
  return;
}


// ==== 0x630400 FUN_00630400

void __thiscall
FUN_00630400(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar2 = *(int *)(param_3 + 0xc);
  uVar3 = (uint)*(byte *)(param_3 + 6);
  if (param_4 < param_5) {
    param_4 = param_5 - param_4;
    do {
      iVar6 = 0;
      if (uVar3 != 0) {
        iVar4 = 0;
        pfVar5 = (float *)(param_6 + 8);
        do {
          bVar1 = *(byte *)(iVar6 + iVar2);
          if ((*(uint *)(param_7 + ((int)(uint)bVar1 >> 5) * 4) & 1 << (bVar1 & 0x1f)) != 0) {
            FUN_0062fff0(*(int *)(param_1 + 0x10) + iVar4,&local_10);
            pfVar5[-2] = local_10 + pfVar5[-2];
            pfVar5[-1] = local_c + pfVar5[-1];
            *pfVar5 = local_8 + *pfVar5;
            pfVar5[1] = local_4 + pfVar5[1];
          }
          uVar3 = (uint)*(byte *)(param_3 + 6);
          iVar6 = iVar6 + 1;
          iVar4 = iVar4 + 0x20;
          pfVar5 = pfVar5 + 4;
        } while (iVar6 < (int)uVar3);
      }
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}


// ==== 0x6304e0 FUN_006304e0

void __thiscall
FUN_006304e0(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar2 = *(int *)(param_3 + 0xc);
  if (param_5 <= param_4 + -1) {
    param_4 = ((param_4 + -1) - param_5) + 1;
    do {
      iVar5 = *(byte *)(param_3 + 6) - 1;
      if (-1 < iVar5) {
        iVar3 = iVar5 * 0x20;
        pfVar4 = (float *)(iVar5 * 0x10 + 8 + param_6);
        do {
          bVar1 = *(byte *)(iVar5 + iVar2);
          if ((*(uint *)(param_7 + ((int)(uint)bVar1 >> 5) * 4) & 1 << (bVar1 & 0x1f)) != 0) {
            FUN_0062fff0(*(int *)(param_1 + 0x10) + iVar3,&local_10);
            pfVar4[-2] = pfVar4[-2] - local_10;
            pfVar4[-1] = pfVar4[-1] - local_c;
            *pfVar4 = *pfVar4 - local_8;
            pfVar4[1] = pfVar4[1] - local_4;
          }
          iVar5 = iVar5 + -1;
          iVar3 = iVar3 + -0x20;
          pfVar4 = pfVar4 + -4;
        } while (-1 < iVar5);
      }
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}


// ==== 0x6305d0 FUN_006305d0

void __thiscall
FUN_006305d0(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (param_3 != *(int *)(param_1 + 0x28)) {
    iVar2 = *(int *)(param_2 + 0xc);
    if (param_3 >> (*(byte *)(param_2 + 0x10) & 0x1f) == param_4) {
      iVar4 = 0;
      if (*(char *)(param_2 + 6) != '\0') {
        iVar3 = 0;
        param_4 = 0;
        do {
          bVar1 = *(byte *)(iVar4 + iVar2);
          if ((*(uint *)(param_6 + ((int)(uint)bVar1 >> 5) * 4) & 1 << (bVar1 & 0x1f)) != 0) {
            FUN_0062fff0(*(int *)(param_1 + 0x10) + param_4,&local_10);
            *(float *)(iVar3 + *(int *)(param_1 + 0x30)) =
                 local_10 + *(float *)(iVar3 + *(int *)(param_1 + 0x24));
            *(float *)(iVar3 + 4 + *(int *)(param_1 + 0x30)) =
                 local_c + *(float *)(iVar3 + 4 + *(int *)(param_1 + 0x24));
            *(float *)(iVar3 + 8 + *(int *)(param_1 + 0x30)) =
                 local_8 + *(float *)(iVar3 + 8 + *(int *)(param_1 + 0x24));
            *(float *)(iVar3 + 0xc + *(int *)(param_1 + 0x30)) =
                 local_4 + *(float *)(iVar3 + 0xc + *(int *)(param_1 + 0x24));
          }
          param_4 = param_4 + 0x20;
          iVar4 = iVar4 + 1;
          iVar3 = iVar3 + 0x10;
        } while (iVar4 < (int)(uint)*(byte *)(param_2 + 6));
      }
    }
    else {
      iVar4 = 0;
      if (*(char *)(param_2 + 6) != '\0') {
        iVar3 = 0;
        do {
          bVar1 = *(byte *)(iVar4 + iVar2);
          if ((*(uint *)(param_6 + ((int)(uint)bVar1 >> 5) * 4) & 1 << (bVar1 & 0x1f)) != 0) {
            FUN_0062ff40(*(int *)(param_1 + 0x30) + iVar3);
          }
          iVar4 = iVar4 + 1;
          iVar3 = iVar3 + 0x10;
        } while (iVar4 < (int)(uint)*(byte *)(param_2 + 6));
        *(int *)(param_1 + 0x28) = param_3;
        return;
      }
    }
    *(int *)(param_1 + 0x28) = param_3;
  }
  return;
}


// ==== 0x630760 FUN_00630760

void __thiscall FUN_00630760(int param_1,int *param_2,int *param_3,int *param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  *param_2 = param_1 + 0x12;
  *param_3 = (uint)*(byte *)(param_1 + 6) * 0x10 + param_1 + 0x12;
  uVar4 = (uint)*(byte *)(param_1 + 6);
  uVar5 = 1 << (*(byte *)(param_1 + 0x10) & 0x1f);
  uVar3 = (uint)*(ushort *)(param_1 + 4) % uVar5;
  iVar2 = uVar4 * 0x10 + 0x12 +
          param_1 + ((uVar5 + 1) * uVar4 * 3 + 1 & 0xfffffffe) * (*(ushort *)(param_1 + 4) / uVar5);
  if (0 < (int)uVar3) {
    iVar2 = iVar2 + (uVar3 + 1) * uVar4 * 3;
  }
  *param_4 = iVar2;
  uVar1 = FUN_006300a0();
  *param_5 = uVar1;
  return;
}


// ==== 0x6307e0 FUN_006307e0

undefined4 * __thiscall FUN_006307e0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a8318;
  if (param_1[4] != 0) {
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[4]);
  }
  FUN_00628ed0();
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x40);
  }
  return param_1;
}


// ==== 0x630820 FUN_00630820

void __fastcall FUN_00630820(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar1 = *(int *)(param_1 + 0xc);
  local_4 = param_1;
  FUN_00630760(&local_4,param_1 + 0x14,param_1 + 0x34,param_1 + 0x38);
  *(uint *)(param_1 + 0x18) =
       ((1 << (*(byte *)(iVar1 + 0x10) & 0x1f)) + 1) * (uint)*(byte *)(iVar1 + 6) * 3 + 1 &
       0xfffffffe;
  if (*(byte *)(iVar1 + 6) != 0) {
    uVar2 = (uint)*(byte *)(iVar1 + 6);
    iVar3 = (**(code **)(*DAT_0070d364 + 0x14))(uVar2 * 0x40);
    *(int *)(param_1 + 0x10) = iVar3;
    iVar3 = iVar3 + uVar2 * 0x20;
    iVar4 = uVar2 * 0x10 + iVar3;
    *(int *)(param_1 + 0x2c) = iVar4;
    *(int *)(param_1 + 0x30) = iVar4;
    *(int *)(param_1 + 0x20) = iVar3;
    *(int *)(param_1 + 0x24) = iVar3;
    iVar3 = 0;
    if (*(char *)(iVar1 + 6) != '\0') {
      iVar4 = 0;
      do {
        FUN_0062fe70(*(int *)(param_1 + 0x10) + iVar4);
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x20;
      } while (iVar3 < (int)(uint)*(byte *)(iVar1 + 6));
    }
  }
  return;
}


// ==== 0x6308e0 FUN_006308e0

void __thiscall FUN_006308e0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  FUN_00630820();
  return;
}


// ==== 0x6308f0 FUN_006308f0

undefined4 __thiscall FUN_006308f0(int param_1,float param_2,uint param_3,int param_4)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  ushort *puVar4;
  undefined4 uVar5;
  float fVar6;
  bool bVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  undefined2 uVar16;
  float *pfVar14;
  undefined4 *puVar15;
  float *pfVar17;
  undefined4 *puVar18;
  ushort *puVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  int local_20;
  
  if (param_4 != *(int *)(param_1 + 0x3c)) {
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
    *(int *)(param_1 + 0x3c) = param_4;
  }
  iVar3 = *(int *)(param_1 + 0xc);
  iVar22 = *(int *)(iVar3 + 0xc);
  iVar8 = param_3 + 0x10;
  uVar9 = CONCAT31((int3)((uint)iVar8 >> 8),*(char *)(iVar3 + 6));
  if (*(char *)(iVar3 + 6) == '\0') goto LAB_00630d11;
  uVar9 = FUN_00629350(param_2);
  puVar4 = *(ushort **)(iVar3 + 8);
  if (puVar4 == (ushort *)0x0) {
    if ((int)uVar9 < 0) {
      uVar23 = 0;
    }
    else {
      uVar23 = uVar9;
      if ((int)(uint)*(ushort *)(iVar3 + 4) <= (int)uVar9) {
        uVar23 = *(ushort *)(iVar3 + 4) - 1;
      }
    }
  }
  else if ((int)uVar9 < (int)(uint)*puVar4) {
    uVar23 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x1c) < 1) {
      iVar10 = 0;
    }
    else {
      iVar10 = *(int *)(param_1 + 0x1c) + -1;
    }
    puVar19 = puVar4 + iVar10;
    if ((int)uVar9 < (int)(uint)puVar4[iVar10]) {
      for (; (0 < iVar10 && ((int)uVar9 < (int)(uint)*puVar19)); puVar19 = puVar19 + -1) {
        iVar10 = iVar10 + -1;
      }
    }
    else {
      while ((iVar10 < (int)(*(ushort *)(iVar3 + 4) - 2) &&
             (puVar19 = puVar19 + 1, (int)(uint)*puVar19 <= (int)uVar9))) {
        iVar10 = iVar10 + 1;
      }
    }
    uVar23 = iVar10 + 1;
  }
  bVar1 = *(byte *)(iVar3 + 0x10);
  uVar21 = 0x7fffffff >> (0x1f - bVar1 & 0x1f);
  iVar10 = (int)uVar23 >> (bVar1 & 0x1f);
  uVar11 = uVar21 & uVar23;
  uVar13 = *(uint *)(param_1 + 0x1c);
  iVar20 = (int)uVar13 >> (bVar1 & 0x1f);
  if (*(uint *)(param_1 + 0x28) == uVar23) {
    uVar5 = *(undefined4 *)(param_1 + 0x30);
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x24) = uVar5;
    *(uint *)(param_1 + 0x28) = uVar13;
  }
  else {
    if (uVar13 == uVar23 + 1) {
      iVar12 = 0;
      local_20 = 0;
      if (*(char *)(iVar3 + 6) != '\0') {
        do {
          puVar15 = (undefined4 *)(*(int *)(param_1 + 0x24) + iVar12);
          puVar18 = (undefined4 *)(*(int *)(param_1 + 0x30) + iVar12);
          *puVar18 = *puVar15;
          puVar18[1] = puVar15[1];
          puVar18[2] = puVar15[2];
          puVar18[3] = puVar15[3];
          local_20 = local_20 + 1;
          iVar12 = iVar12 + 0x10;
        } while (local_20 < (int)(uint)*(byte *)(iVar3 + 6));
      }
      uVar13 = *(uint *)(param_1 + 0x1c);
      *(uint *)(param_1 + 0x28) = uVar13;
    }
    iVar12 = *(int *)(param_1 + 0x18) * iVar10 + *(int *)(param_1 + 0x14);
    if (((int)uVar13 <= (int)uVar23) || (bVar7 = true, DAT_006e58d8 != '\0')) {
      bVar7 = false;
    }
    if (((uVar13 == 0xffffffff) || (iVar10 != iVar20)) || (bVar7)) {
      iVar20 = 0;
      if (*(char *)(iVar3 + 6) != '\0') {
        param_3 = 0;
        do {
          if ((*(uint *)(param_4 + ((int)(uint)*(byte *)(iVar20 + iVar22) >> 5) * 4) &
              1 << (*(byte *)(iVar20 + iVar22) & 0x1f)) != 0) {
            FUN_0062ff40(*(int *)(param_1 + 0x24) + param_3);
          }
          param_3 = param_3 + 0x10;
          iVar20 = iVar20 + 1;
        } while (iVar20 < (int)(uint)*(byte *)(iVar3 + 6));
      }
      uVar13 = 0;
    }
    else {
      uVar13 = uVar13 & uVar21;
    }
    if ((int)uVar13 < (int)uVar11) {
      uVar13 = FUN_00630400(iVar12,iVar3,uVar13,uVar11,*(undefined4 *)(param_1 + 0x24),param_4);
    }
    else if ((int)uVar11 < (int)uVar13) {
      uVar13 = FUN_006304e0(iVar12,iVar3,uVar13,uVar11,*(undefined4 *)(param_1 + 0x24),param_4);
    }
  }
  *(uint *)(param_1 + 0x1c) = uVar23;
  puVar4 = *(ushort **)(iVar3 + 8);
  iVar20 = 0;
  uVar16 = (undefined2)(uVar13 >> 0x10);
  if (puVar4 == (ushort *)0x0) {
    fVar6 = (float)(int)uVar9;
    uVar9 = CONCAT22(uVar16,(ushort)(param_2 < fVar6) << 8 |
                            (ushort)(NAN(param_2) || NAN(fVar6)) << 10 |
                            (ushort)(param_2 == fVar6) << 0xe);
    if (param_2 != fVar6) {
      param_2 = param_2 - fVar6;
      goto LAB_00630bdb;
    }
  }
  else if (uVar23 == 0) {
    uVar9 = CONCAT22(uVar16,(ushort)(param_2 < 0.0) << 8 | (ushort)NAN(param_2) << 10 |
                            (ushort)(param_2 == 0.0) << 0xe);
    if (param_2 != 0.0) {
      param_2 = param_2 / (float)*puVar4;
LAB_00630bdb:
      uVar9 = *(ushort *)(iVar3 + 4) - 1;
      if ((int)uVar23 < (int)uVar9) {
        FUN_006305d0(iVar3,uVar23 + 1,iVar10,uVar11,param_4);
        uVar9 = 0;
        param_3 = 0;
        if (*(char *)(iVar3 + 6) != '\0') {
          iVar10 = 0;
          do {
            bVar1 = *(byte *)(param_3 + iVar22);
            if ((*(uint *)(param_4 + ((int)(uint)bVar1 >> 5) * 4) & 1 << (bVar1 & 0x1f)) != 0) {
              pfVar17 = (float *)((uint)bVar1 * 0x30 + iVar8);
              iVar20 = *(int *)(param_1 + 0x30) + iVar10;
              pfVar14 = (float *)(*(int *)(param_1 + 0x24) + iVar10);
              *pfVar17 = (*(float *)(*(int *)(param_1 + 0x30) + iVar10) -
                         *(float *)(*(int *)(param_1 + 0x24) + iVar10)) * param_2 + *pfVar14;
              pfVar17[1] = (*(float *)(iVar20 + 4) - pfVar14[1]) * param_2 + pfVar14[1];
              pfVar17[2] = (*(float *)(iVar20 + 8) - pfVar14[2]) * param_2 + pfVar14[2];
              pfVar17[3] = (*(float *)(iVar20 + 0xc) - pfVar14[3]) * param_2 + pfVar14[3];
            }
            uVar9 = param_3 + 1;
            iVar10 = iVar10 + 0x10;
            param_3 = uVar9;
          } while ((int)uVar9 < (int)(uint)*(byte *)(iVar3 + 6));
        }
        goto LAB_00630d11;
      }
    }
  }
  else {
    fVar6 = (float)puVar4[uVar23 - 1];
    uVar9 = (uint)(ushort)((ushort)(param_2 < fVar6) << 8 |
                           (ushort)(NAN(param_2) || NAN(fVar6)) << 10 |
                          (ushort)(param_2 == fVar6) << 0xe);
    if (param_2 != fVar6) {
      param_2 = (param_2 - fVar6) / ((float)puVar4[uVar23] - fVar6);
      goto LAB_00630bdb;
    }
  }
  uVar9 = CONCAT31((int3)(uVar9 >> 8),*(char *)(iVar3 + 6));
  if (*(char *)(iVar3 + 6) != '\0') {
    param_2 = 0.0;
    do {
      bVar1 = *(byte *)(iVar20 + iVar22);
      if ((*(uint *)(param_4 + ((int)(uint)bVar1 >> 5) * 4) & 1 << (bVar1 & 0x1f)) != 0) {
        puVar18 = (undefined4 *)(*(int *)(param_1 + 0x24) + (int)param_2);
        puVar15 = (undefined4 *)((uint)bVar1 * 0x30 + iVar8);
        *puVar15 = *puVar18;
        puVar15[1] = puVar18[1];
        puVar15[2] = puVar18[2];
        puVar15[3] = puVar18[3];
      }
      uVar9 = (uint)*(byte *)(iVar3 + 6);
      iVar20 = iVar20 + 1;
      param_2 = (float)((int)param_2 + 0x10);
    } while (iVar20 < (int)uVar9);
  }
LAB_00630d11:
  cVar2 = *(char *)(iVar3 + 7);
  uVar9 = CONCAT31((int3)(uVar9 >> 8),cVar2);
  if ((cVar2 != '\0') && (iVar22 = 0, cVar2 != '\0')) {
    do {
      bVar1 = *(byte *)(*(int *)(param_1 + 0x34) + iVar22);
      if ((*(uint *)(param_4 + ((int)(uint)bVar1 >> 5) * 4) & 1 << (bVar1 & 0x1f)) != 0) {
        FUN_0062ff40((uint)bVar1 * 0x30 + iVar8);
      }
      uVar9 = (uint)*(byte *)(iVar3 + 7);
      iVar22 = iVar22 + 1;
    } while (iVar22 < (int)uVar9);
  }
  return CONCAT31((int3)(uVar9 >> 8),1);
}


// ==== 0x630d80 FUN_00630d80

undefined4 __thiscall FUN_00630d80(int param_1,float param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  ushort *puVar3;
  float fVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  float *pfVar13;
  undefined3 uVar14;
  undefined3 extraout_var;
  float *pfVar15;
  undefined4 *puVar16;
  ushort *puVar17;
  int iVar18;
  float *pfVar19;
  uint uVar20;
  undefined4 *puVar21;
  int iVar22;
  uint uVar23;
  int iStack_14;
  
  if (param_4 != 0) {
    uVar12 = FUN_006308f0(param_2,param_3,param_4);
    return uVar12;
  }
  if (*(int *)(param_1 + 0x3c) != 0) {
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  iVar6 = param_3 + 0x10;
  iVar2 = *(int *)(param_1 + 0xc);
  iVar22 = *(int *)(iVar2 + 0xc);
  pfVar13 = (float *)CONCAT31((int3)((uint)iVar6 >> 8),*(char *)(iVar2 + 6));
  if (*(char *)(iVar2 + 6) == '\0') goto LAB_00631120;
  uVar7 = FUN_00629350(param_2);
  puVar3 = *(ushort **)(iVar2 + 8);
  uVar20 = 0;
  if (puVar3 == (ushort *)0x0) {
    if ((-1 < (int)uVar7) && (uVar20 = uVar7, (int)(uint)*(ushort *)(iVar2 + 4) <= (int)uVar7)) {
      uVar20 = *(ushort *)(iVar2 + 4) - 1;
    }
  }
  else if ((int)(uint)*puVar3 <= (int)uVar7) {
    if (*(int *)(param_1 + 0x1c) < 1) {
      iVar8 = 0;
    }
    else {
      iVar8 = *(int *)(param_1 + 0x1c) + -1;
    }
    puVar17 = puVar3 + iVar8;
    if ((int)uVar7 < (int)(uint)puVar3[iVar8]) {
      for (; (0 < iVar8 && ((int)uVar7 < (int)(uint)*puVar17)); puVar17 = puVar17 + -1) {
        iVar8 = iVar8 + -1;
      }
    }
    else {
      while ((iVar8 < (int)(*(ushort *)(iVar2 + 4) - 2) &&
             (puVar17 = puVar17 + 1, (int)(uint)*puVar17 <= (int)uVar7))) {
        iVar8 = iVar8 + 1;
      }
    }
    uVar20 = iVar8 + 1;
  }
  bVar1 = *(byte *)(iVar2 + 0x10);
  uVar23 = 0x7fffffff >> (0x1f - bVar1 & 0x1f);
  iVar8 = (int)uVar20 >> (bVar1 & 0x1f);
  uVar9 = uVar23 & uVar20;
  uVar11 = *(uint *)(param_1 + 0x1c);
  iVar18 = (int)uVar11 >> (bVar1 & 0x1f);
  if (*(uint *)(param_1 + 0x28) == uVar20) {
    uVar12 = *(undefined4 *)(param_1 + 0x30);
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x24) = uVar12;
    *(uint *)(param_1 + 0x28) = uVar11;
  }
  else {
    if (uVar11 == uVar20 + 1) {
      iVar10 = 0;
      param_3 = 0;
      if (*(char *)(iVar2 + 6) != '\0') {
        do {
          puVar16 = (undefined4 *)(*(int *)(param_1 + 0x24) + iVar10);
          puVar21 = (undefined4 *)(*(int *)(param_1 + 0x30) + iVar10);
          *puVar21 = *puVar16;
          puVar21[1] = puVar16[1];
          puVar21[2] = puVar16[2];
          puVar21[3] = puVar16[3];
          param_3 = param_3 + 1;
          iVar10 = iVar10 + 0x10;
        } while (param_3 < (int)(uint)*(byte *)(iVar2 + 6));
      }
      uVar11 = *(uint *)(param_1 + 0x1c);
      *(uint *)(param_1 + 0x28) = uVar11;
    }
    iVar10 = *(int *)(param_1 + 0x18) * iVar8 + *(int *)(param_1 + 0x14);
    if (((int)uVar11 <= (int)uVar20) || (bVar5 = true, DAT_006e58d8 != '\0')) {
      bVar5 = false;
    }
    if ((((uVar11 == 0xffffffff) || (iVar8 != iVar18)) || (uVar9 == 0)) || (bVar5)) {
      iVar18 = 0;
      iStack_14 = 0;
      if (*(char *)(iVar2 + 6) != '\0') {
        do {
          FUN_0062ff40(*(int *)(param_1 + 0x24) + iVar18);
          iStack_14 = iStack_14 + 1;
          iVar18 = iVar18 + 0x10;
        } while (iStack_14 < (int)(uint)*(byte *)(iVar2 + 6));
      }
      uVar11 = 0;
    }
    else {
      uVar11 = uVar11 & uVar23;
    }
    if ((int)uVar11 < (int)uVar9) {
      FUN_00630150(iVar10,iVar2,uVar11,uVar9,*(undefined4 *)(param_1 + 0x24));
    }
    else if ((int)uVar9 < (int)uVar11) {
      FUN_00630200(iVar10,iVar2,uVar11,uVar9,*(undefined4 *)(param_1 + 0x24));
    }
  }
  *(uint *)(param_1 + 0x1c) = uVar20;
  puVar3 = *(ushort **)(iVar2 + 8);
  if (puVar3 == (ushort *)0x0) {
    if (param_2 != (float)(int)uVar7) {
      param_2 = param_2 - (float)(int)uVar7;
      goto LAB_0063103d;
    }
  }
  else if (uVar20 == 0) {
    if (param_2 != 0.0) {
      param_2 = param_2 / (float)*puVar3;
LAB_0063103d:
      if ((int)uVar20 < (int)(*(ushort *)(iVar2 + 4) - 1)) {
        uVar12 = FUN_006302c0(iVar2,uVar20 + 1,iVar8,uVar9);
        pfVar13 = (float *)CONCAT31((int3)((uint)uVar12 >> 8),*(char *)(iVar2 + 6));
        iVar8 = 0;
        if (*(char *)(iVar2 + 6) != '\0') {
          iVar18 = 0;
          do {
            pfVar15 = (float *)((uint)*(byte *)(iVar8 + iVar22) * 0x30 + iVar6);
            pfVar13 = (float *)(*(int *)(param_1 + 0x24) + iVar18);
            pfVar19 = (float *)(*(int *)(param_1 + 0x30) + iVar18);
            iVar8 = iVar8 + 1;
            iVar18 = iVar18 + 0x10;
            *pfVar15 = (*pfVar19 - *pfVar13) * param_2 + *pfVar13;
            pfVar15[1] = (pfVar19[1] - pfVar13[1]) * param_2 + pfVar13[1];
            pfVar15[2] = (pfVar19[2] - pfVar13[2]) * param_2 + pfVar13[2];
            pfVar15[3] = (pfVar19[3] - pfVar13[3]) * param_2 + pfVar13[3];
          } while (iVar8 < (int)(uint)*(byte *)(iVar2 + 6));
        }
        goto LAB_00631120;
      }
    }
  }
  else {
    fVar4 = (float)puVar3[uVar20 - 1];
    if (param_2 != fVar4) {
      param_2 = (param_2 - fVar4) / ((float)puVar3[uVar20] - fVar4);
      goto LAB_0063103d;
    }
  }
  pfVar13 = (float *)0x0;
  if (*(char *)(iVar2 + 6) != '\0') {
    iVar8 = 0;
    do {
      puVar16 = (undefined4 *)((uint)*(byte *)((int)pfVar13 + iVar22) * 0x30 + iVar6);
      puVar21 = (undefined4 *)(*(int *)(param_1 + 0x24) + iVar8);
      *puVar16 = *puVar21;
      puVar16[1] = puVar21[1];
      puVar16[2] = puVar21[2];
      puVar16[3] = puVar21[3];
      pfVar13 = (float *)((int)pfVar13 + 1);
      iVar8 = iVar8 + 0x10;
    } while ((int)pfVar13 < (int)(uint)*(byte *)(iVar2 + 6));
  }
LAB_00631120:
  uVar14 = (undefined3)((uint)pfVar13 >> 8);
  if ((*(char *)(iVar2 + 7) != '\0') && (iVar22 = 0, *(char *)(iVar2 + 7) != '\0')) {
    do {
      FUN_0062ff40((uint)*(byte *)(*(int *)(param_1 + 0x34) + iVar22) * 0x30 + iVar6);
      iVar22 = iVar22 + 1;
      uVar14 = extraout_var;
    } while (iVar22 < (int)(uint)*(byte *)(iVar2 + 7));
  }
  return CONCAT31(uVar14,1);
}


// ==== 0x630d8c FUN_00630d8c

undefined4 __thiscall FUN_00630d8c(int param_1)

{
  byte bVar1;
  int iVar2;
  ushort *puVar3;
  float fVar4;
  bool bVar5;
  undefined4 in_EAX;
  int iVar6;
  ushort *puVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  float *pfVar13;
  undefined3 uVar14;
  undefined3 extraout_var;
  float *pfVar15;
  undefined4 *puVar16;
  ushort *puVar17;
  int iVar18;
  float *pfVar19;
  ushort *unaff_EBX;
  undefined4 *puVar20;
  int iVar21;
  uint uVar22;
  bool in_ZF;
  int iStack0000000c;
  float in_stack_00000024;
  int in_stack_00000028;
  
  if (!in_ZF) {
    uVar12 = FUN_006308f0(in_stack_00000024,in_stack_00000028,in_EAX);
    return uVar12;
  }
  if (*(ushort **)(param_1 + 0x3c) != unaff_EBX) {
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
    *(ushort **)(param_1 + 0x3c) = unaff_EBX;
  }
  iVar6 = in_stack_00000028 + 0x10;
  iVar2 = *(int *)(param_1 + 0xc);
  iVar21 = *(int *)(iVar2 + 0xc);
  pfVar13 = (float *)CONCAT31((int3)((uint)iVar6 >> 8),*(char *)(iVar2 + 6));
  if (*(char *)(iVar2 + 6) == '\0') goto LAB_00631120;
  puVar7 = (ushort *)FUN_00629350(in_stack_00000024);
  puVar3 = *(ushort **)(iVar2 + 8);
  if (puVar3 == unaff_EBX) {
    if (((int)unaff_EBX <= (int)puVar7) &&
       (unaff_EBX = puVar7, (int)(uint)*(ushort *)(iVar2 + 4) <= (int)puVar7)) {
      unaff_EBX = (ushort *)(*(ushort *)(iVar2 + 4) - 1);
    }
  }
  else if ((int)(uint)*puVar3 <= (int)puVar7) {
    if (*(int *)(param_1 + 0x1c) < 1) {
      iVar8 = 0;
    }
    else {
      iVar8 = *(int *)(param_1 + 0x1c) + -1;
    }
    puVar17 = puVar3 + iVar8;
    if ((int)puVar7 < (int)(uint)puVar3[iVar8]) {
      for (; ((int)unaff_EBX < iVar8 && ((int)puVar7 < (int)(uint)*puVar17)); puVar17 = puVar17 + -1
          ) {
        iVar8 = iVar8 + -1;
      }
    }
    else {
      while ((iVar8 < (int)(*(ushort *)(iVar2 + 4) - 2) &&
             (puVar17 = puVar17 + 1, (int)(uint)*puVar17 <= (int)puVar7))) {
        iVar8 = iVar8 + 1;
      }
    }
    unaff_EBX = (ushort *)(iVar8 + 1);
  }
  bVar1 = *(byte *)(iVar2 + 0x10);
  uVar22 = 0x7fffffff >> (0x1f - bVar1 & 0x1f);
  iVar8 = (int)unaff_EBX >> (bVar1 & 0x1f);
  uVar9 = uVar22 & (uint)unaff_EBX;
  uVar11 = *(uint *)(param_1 + 0x1c);
  iVar18 = (int)uVar11 >> (bVar1 & 0x1f);
  if (*(ushort **)(param_1 + 0x28) == unaff_EBX) {
    uVar12 = *(undefined4 *)(param_1 + 0x30);
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x24) = uVar12;
    *(uint *)(param_1 + 0x28) = uVar11;
  }
  else {
    if (uVar11 == (int)unaff_EBX + 1U) {
      iVar10 = 0;
      in_stack_00000028 = 0;
      if (*(char *)(iVar2 + 6) != '\0') {
        do {
          puVar16 = (undefined4 *)(*(int *)(param_1 + 0x24) + iVar10);
          puVar20 = (undefined4 *)(*(int *)(param_1 + 0x30) + iVar10);
          *puVar20 = *puVar16;
          puVar20[1] = puVar16[1];
          puVar20[2] = puVar16[2];
          puVar20[3] = puVar16[3];
          in_stack_00000028 = in_stack_00000028 + 1;
          iVar10 = iVar10 + 0x10;
        } while (in_stack_00000028 < (int)(uint)*(byte *)(iVar2 + 6));
      }
      uVar11 = *(uint *)(param_1 + 0x1c);
      *(uint *)(param_1 + 0x28) = uVar11;
    }
    iVar10 = *(int *)(param_1 + 0x18) * iVar8 + *(int *)(param_1 + 0x14);
    if (((int)uVar11 <= (int)unaff_EBX) || (bVar5 = true, DAT_006e58d8 != '\0')) {
      bVar5 = false;
    }
    if ((((uVar11 == 0xffffffff) || (iVar8 != iVar18)) || (uVar9 == 0)) || (bVar5)) {
      iVar18 = 0;
      iStack0000000c = 0;
      if (*(char *)(iVar2 + 6) != '\0') {
        do {
          FUN_0062ff40(*(int *)(param_1 + 0x24) + iVar18);
          iStack0000000c = iStack0000000c + 1;
          iVar18 = iVar18 + 0x10;
        } while (iStack0000000c < (int)(uint)*(byte *)(iVar2 + 6));
      }
      uVar11 = 0;
    }
    else {
      uVar11 = uVar11 & uVar22;
    }
    if ((int)uVar11 < (int)uVar9) {
      FUN_00630150(iVar10,iVar2,uVar11,uVar9,*(undefined4 *)(param_1 + 0x24));
    }
    else if ((int)uVar9 < (int)uVar11) {
      FUN_00630200(iVar10,iVar2,uVar11,uVar9,*(undefined4 *)(param_1 + 0x24));
    }
  }
  *(ushort **)(param_1 + 0x1c) = unaff_EBX;
  puVar3 = *(ushort **)(iVar2 + 8);
  if (puVar3 == (ushort *)0x0) {
    if (in_stack_00000024 != (float)(int)puVar7) {
      in_stack_00000024 = in_stack_00000024 - (float)(int)puVar7;
      goto LAB_0063103d;
    }
  }
  else if (unaff_EBX == (ushort *)0x0) {
    if (in_stack_00000024 != 0.0) {
      in_stack_00000024 = in_stack_00000024 / (float)*puVar3;
LAB_0063103d:
      if ((int)unaff_EBX < (int)(*(ushort *)(iVar2 + 4) - 1)) {
        uVar12 = FUN_006302c0(iVar2,(int)unaff_EBX + 1U,iVar8,uVar9);
        pfVar13 = (float *)CONCAT31((int3)((uint)uVar12 >> 8),*(char *)(iVar2 + 6));
        iVar8 = 0;
        if (*(char *)(iVar2 + 6) != '\0') {
          iVar18 = 0;
          do {
            pfVar15 = (float *)((uint)*(byte *)(iVar8 + iVar21) * 0x30 + iVar6);
            pfVar13 = (float *)(*(int *)(param_1 + 0x24) + iVar18);
            pfVar19 = (float *)(*(int *)(param_1 + 0x30) + iVar18);
            iVar8 = iVar8 + 1;
            iVar18 = iVar18 + 0x10;
            *pfVar15 = (*pfVar19 - *pfVar13) * in_stack_00000024 + *pfVar13;
            pfVar15[1] = (pfVar19[1] - pfVar13[1]) * in_stack_00000024 + pfVar13[1];
            pfVar15[2] = (pfVar19[2] - pfVar13[2]) * in_stack_00000024 + pfVar13[2];
            pfVar15[3] = (pfVar19[3] - pfVar13[3]) * in_stack_00000024 + pfVar13[3];
          } while (iVar8 < (int)(uint)*(byte *)(iVar2 + 6));
        }
        goto LAB_00631120;
      }
    }
  }
  else {
    fVar4 = (float)puVar3[(int)unaff_EBX + -1];
    if (in_stack_00000024 != fVar4) {
      in_stack_00000024 = (in_stack_00000024 - fVar4) / ((float)puVar3[(int)unaff_EBX] - fVar4);
      goto LAB_0063103d;
    }
  }
  pfVar13 = (float *)0x0;
  if (*(char *)(iVar2 + 6) != '\0') {
    iVar8 = 0;
    do {
      puVar16 = (undefined4 *)((uint)*(byte *)((int)pfVar13 + iVar21) * 0x30 + iVar6);
      puVar20 = (undefined4 *)(*(int *)(param_1 + 0x24) + iVar8);
      *puVar16 = *puVar20;
      puVar16[1] = puVar20[1];
      puVar16[2] = puVar20[2];
      puVar16[3] = puVar20[3];
      pfVar13 = (float *)((int)pfVar13 + 1);
      iVar8 = iVar8 + 0x10;
    } while ((int)pfVar13 < (int)(uint)*(byte *)(iVar2 + 6));
  }
LAB_00631120:
  uVar14 = (undefined3)((uint)pfVar13 >> 8);
  if ((*(char *)(iVar2 + 7) != '\0') && (iVar21 = 0, *(char *)(iVar2 + 7) != '\0')) {
    do {
      FUN_0062ff40((uint)*(byte *)(*(int *)(param_1 + 0x34) + iVar21) * 0x30 + iVar6);
      iVar21 = iVar21 + 1;
      uVar14 = extraout_var;
    } while (iVar21 < (int)(uint)*(byte *)(iVar2 + 7));
  }
  return CONCAT31(uVar14,1);
}


