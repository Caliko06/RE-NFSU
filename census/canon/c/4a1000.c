// ==== 0x4a1290 HudTurbo::HudTurbo

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

int HudTurbo__HudTurbo(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00687e78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(param_1 + 8) = param_2;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(undefined4 *)(param_1 + 0x10) = 0x10000060;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  local_4 = 0;
  FEng__HashName();
  uVar1 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  FEng__HashName();
  uVar1 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  FEng__HashName();
  uVar1 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  FEng__HashName();
  uVar1 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  FEng__HashName();
  uVar1 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  FEng__HashName();
  uVar1 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  FEng__HashName();
  uVar1 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  FEng__HashName();
  uVar1 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  FEng__HashName();
  uVar1 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4a13a0 HudTurbo::Update

/* WARNING: Removing unreachable block (ram,0x004a13fd) */
/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void __fastcall HudTurbo__Update(int param_1)

{
  int in_EAX;
  float10 fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((DAT_006fbf14 == 0) && (*(int *)(in_EAX + 0x10) == 0)) {
    RaceManager__FindRacerById();
  }
  fVar1 = (float10)Car__GetTurboBoost();
  if ((*(uint *)(param_1 + 0x18) & *(uint *)(param_1 + 0x10)) != 0 ||
      (*(uint *)(param_1 + 0x1c) & *(uint *)(param_1 + 0x14)) != 0) {
    HudLapCounter__SetVisible();
    if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
      uVar3 = 0x435b0000;
      uVar2 = 0x41f00000;
    }
    else {
      uVar3 = 0x42700000;
      uVar2 = 0x43960000;
    }
    fVar1 = (float10)TurboMeter__CalcNeedleAngle(param_1,(float)fVar1,uVar2,uVar3);
    FUN_004f6a70((float)fVar1);
  }
  return;
}


// ==== 0x4a1460 TurboMeter::CalcNeedleAngle

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

float10 TurboMeter__CalcNeedleAngle(undefined4 param_1,float param_2,float param_3,float param_4)

{
  float10 fVar1;
  
  if (param_4 <= param_3) {
    fVar1 = ((float10)360.0 - (float10)param_3) + (float10)param_4;
  }
  else {
    fVar1 = (float10)param_4 - (float10)param_3;
  }
  fVar1 = ((float10)param_2 + (float10)_K_ONE) * (float10)_K_HALF * fVar1 + (float10)param_3;
  if ((float10)360.0 < fVar1) {
    fVar1 = fVar1 - (float10)360.0;
  }
  if (fVar1 < (float10)0.0) {
    fVar1 = (float10)360.0 - fVar1;
  }
  return fVar1;
}


// ==== 0x4a14d0 HudLapCounter::SetVisible

/* [canon] hud med (ghidra-canon) docs/re/canon.md */

void HudLapCounter__SetVisible(void)

{
  char in_AL;
  int unaff_ESI;
  
  if (in_AL != '\0') {
    FEObject__SetVisible();
    FEObject__SetVisible(*(undefined4 *)(unaff_ESI + 0x24));
    FEObject__SetVisible(*(undefined4 *)(unaff_ESI + 0x28));
    FEObject__SetVisible(*(undefined4 *)(unaff_ESI + 0x2c));
    FEObject__SetVisible(*(undefined4 *)(unaff_ESI + 0x30));
    FEObject__SetVisible(*(undefined4 *)(unaff_ESI + 0x34));
    FEObject__SetVisible(*(undefined4 *)(unaff_ESI + 0x38));
    FEObject__SetVisible(*(undefined4 *)(unaff_ESI + 0x3c));
    FEObject__SetVisible(*(undefined4 *)(unaff_ESI + 0x40));
    return;
  }
  FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0x20));
  FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0x24));
  FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0x28));
  FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0x2c));
  FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0x30));
  FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0x34));
  FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0x38));
  FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0x3c));
  FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0x40));
  return;
}


// ==== 0x4a1580 HudLapCounter::HudLapCounter

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

int HudLapCounter__HudLapCounter(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  undefined4 *puVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  byte *pbVar10;
  int iVar11;
  int *piVar12;
  byte local_2c;
  byte local_2b [31];
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_00687e20;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0x508;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  local_4 = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x20) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x24) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x28) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x2c) = uVar5;
  uVar5 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar5);
  uVar5 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar5);
  uVar5 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar5);
  iVar6 = 0;
  do {
    iVar6 = iVar6 + 1;
    bSPrintf_regdst(0x20,"LapCounterBacking_%d",iVar6);
    iVar11 = -1;
    pbVar10 = &local_2c;
    bVar4 = local_2c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      pbVar1 = pbVar10 + 1;
      iVar11 = iVar11 * 0x21 + (uint)bVar4;
      pbVar10 = pbVar10 + 1;
      bVar4 = *pbVar1;
    }
    if (*(int *)(param_1 + 8) == 0) {
LAB_004a1748:
      if ((DAT_0073578c != 0) && (iVar11 = FUN_004ef050(iVar11), iVar11 != 0)) {
        if (DAT_007349b4 == 0) {
          FUN_005649f0();
        }
        iVar7 = DAT_007349b4;
        piVar12 = (int *)(DAT_007349b4 + 0x10);
        if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
          FUN_00566e60();
        }
        piVar9 = (int *)*piVar12;
        iVar8 = *(int *)(iVar7 + 0x18) + 1;
        if (piVar9 == (int *)0x0) {
          piVar9 = (int *)0x0;
        }
        else {
          iVar2 = *piVar9;
          if (*(int *)(iVar7 + 0x1c) < iVar8) {
            *(int *)(iVar7 + 0x1c) = iVar8;
          }
          *(int *)(iVar7 + 0x18) = iVar8;
          bVar4 = *(byte *)(iVar7 + 0x14);
          *piVar12 = iVar2;
          if (((bVar4 & 2) != 0) &&
             (iVar7 = *(int *)(iVar7 + 0x28) >> 2, piVar12 = piVar9, 0 < iVar7)) {
            for (; iVar7 != 0; iVar7 = iVar7 + -1) {
              *piVar12 = 0;
              piVar12 = piVar12 + 1;
            }
          }
          piVar9[2] = iVar11;
        }
        puVar3 = *(undefined4 **)(param_1 + 4);
        *puVar3 = piVar9;
        *(int **)(param_1 + 4) = piVar9;
        piVar9[1] = (int)puVar3;
        *piVar9 = param_1;
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar7 != 0) && (iVar7 = *(int *)(iVar7 + 0x18), iVar7 != 0)) {
LAB_004a1702:
        if (iVar7 != 0) {
          local_4._0_1_ = 1;
          FUN_004ffb00(iVar7);
          local_4 = (uint)local_4._1_3_ << 8;
        }
        goto LAB_004a1748;
      }
      if (DAT_0073578c != 0) {
        iVar8 = *(int *)(DAT_0073578c + 8);
        if ((iVar8 == 0) ||
           ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
            (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_004a1748;
        goto LAB_004a1702;
      }
    }
    if (2 < iVar6) {
      *(undefined4 *)(param_1 + 0x44) = 0;
      *(undefined4 *)(param_1 + 0x48) = 0;
      ExceptionList = local_c;
      return param_1;
    }
  } while( true );
}


// ==== 0x4a1820 HudLapCounter::Update

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void HudLapCounter__Update(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int unaff_EBX;
  int iVar4;
  undefined *puVar5;
  float local_2c;
  float local_28;
  undefined1 local_24 [4];
  undefined1 local_20 [32];
  
  iVar4 = *(int *)(param_1 + 4);
  if (((DAT_006fbf14 == 0) && (*(int *)(param_1 + 0x10) == 0)) &&
     (iVar2 = RaceManager__FindRacerById(), iVar2 != 0)) {
    iVar4 = iVar2;
  }
  iVar4 = *(int *)(iVar4 + 0x1c);
  if (iVar4 == 0) {
    return;
  }
  if ((*(uint *)(unaff_EBX + 0x18) & *(uint *)(unaff_EBX + 0x10)) == 0 &&
      (*(uint *)(unaff_EBX + 0x1c) & *(uint *)(unaff_EBX + 0x14)) == 0) {
    return;
  }
  iVar2 = (int)*(char *)(iVar4 + 9);
  if (((DAT_0078a30c == 1) && (DAT_0078a31c == 0)) && (DAT_0078a368 == 0)) {
    FEObject__SetInvisible(*(undefined4 *)(unaff_EBX + 0x24));
    FEng_FindObjectByHash2();
    FUN_004f6d10(&local_28,&local_2c);
    FUN_004f7350(&local_2c,local_24);
    FUN_00496010(local_2c + local_28 + 10.0);
    if (0x62 < iVar2) {
      iVar2 = 0x62;
    }
  }
  else {
    FEObject__SetFormattedText(&DAT_006c72e8,*(undefined4 *)(DAT_0073619c + 0x530));
    FEObject__SetVisible(*(undefined4 *)(unaff_EBX + 0x24));
  }
  FEObject__SetFormattedText(&PTR_FUN_006c7968,iVar2 + 1);
  iVar2 = DAT_0073619c;
  if (((DAT_0078a30c == 2) && (DAT_0078a310 != 0)) &&
     ((DAT_0078a310 != 0x7fffffff && (DAT_0078a368 == 0)))) {
    iVar2 = *(int *)(iVar4 + 0x24 + *(char *)(DAT_0073619c + 0x53e) * 4);
    if ((iVar2 == 0) || (iVar2 == 0x7fffffff)) {
LAB_004a1a58:
      FEString__SetLabelHash();
      goto LAB_004a1a65;
    }
    local_2c = (float)((iVar2 - DAT_0073ad34) + DAT_0078a310);
    FUN_00586580(local_20);
  }
  else {
    iVar1 = *(int *)(iVar4 + 0x24 + *(char *)(DAT_0073619c + 0x53e) * 4);
    if ((iVar1 == 0) || (iVar1 == 0x7fffffff)) goto LAB_004a1a58;
    if (*(char *)(iVar4 + 0xd) != '\0') {
      *(int *)(unaff_EBX + 0x44) = DAT_0073ad34;
      *(undefined4 *)(unaff_EBX + 0x48) =
           *(undefined4 *)(iVar4 + 0x38 + *(char *)(iVar2 + 0x53f) * 4);
    }
    local_28 = (float)(DAT_0073ad34 - *(int *)(unaff_EBX + 0x44));
    if (3.0 < (float)(int)local_28 * 0.00025) {
      *(int *)(unaff_EBX + 0x48) =
           DAT_0073ad34 - *(int *)(iVar4 + 0x24 + *(char *)(iVar2 + 0x53e) * 4);
    }
    FUN_00586580(local_20);
  }
  FEObject__SetFormattedText(&DAT_006cc568,local_20);
LAB_004a1a65:
  if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
    local_2c = *(float *)(iVar4 + 0x60 + *(char *)(DAT_0073619c + 0x53f) * 4);
    if ((float)(int)local_2c * 0.00025 == 0.0) {
      bSPrintf_regdst(0x20,"--:--:--");
    }
    else {
      FUN_00586580(local_20);
    }
    puVar3 = local_20;
    puVar5 = &DAT_006cc568;
  }
  else {
    puVar3 = (undefined1 *)_ftol_nocw();
    puVar5 = &DAT_006ca778;
  }
  FEObject__SetFormattedText(puVar5,puVar3);
  if (((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) && (DAT_0078a320 == 2)) {
    FUN_00414a10();
    FUN_00414a10();
    FUN_00414a10();
  }
  return;
}


// ==== 0x4a1b50 HudSplitTime::HudSplitTime

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

int HudSplitTime__HudSplitTime(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00687e78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0x80;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  local_4 = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  FEng__HashName();
  uVar1 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  FEng__HashName();
  uVar1 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  *(undefined1 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0xff962020;
  *(undefined4 *)(param_1 + 0x40) = 0xff00ff00;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4a1bf0 HudSplitTime::Update

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void HudSplitTime__Update(int param_1)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  bool bVar3;
  
  FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0x24));
  if ((*(uint *)(unaff_ESI + 0x18) & *(uint *)(unaff_ESI + 0x10)) != 0 ||
      (*(uint *)(unaff_ESI + 0x1c) & *(uint *)(unaff_ESI + 0x14)) != 0) {
    bVar3 = DAT_006fbf14 == 0;
    *(undefined4 *)(unaff_ESI + 0x34) = 0;
    *(undefined4 *)(unaff_ESI + 0x30) = 0;
    iVar2 = *(int *)(param_1 + 4);
    if (((bVar3) && (*(int *)(param_1 + 0x10) == 0)) &&
       (iVar1 = RaceManager__FindRacerById(), iVar1 != 0)) {
      iVar2 = iVar1;
    }
    iVar2 = *(int *)(iVar2 + 0x1c);
    if ((iVar2 == 0) || ((*(char *)(iVar2 + 0xd) == '\0' && (*(char *)(iVar2 + 0xe) == '\0')))) {
      if (3.0 < (float)(DAT_0073ad34 - *(int *)(unaff_ESI + 0x2c)) * 0.00025) {
        FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0x20));
        FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0x24));
        *(undefined1 *)(unaff_ESI + 0x28) = 0;
      }
    }
    else {
      switch(*(undefined1 *)(param_1 + 0x26)) {
      case 0:
        FUN_004a1d00();
        return;
      case 1:
        FUN_004a1e20();
        return;
      case 2:
        FUN_004a1d90();
        return;
      case 3:
        FUN_004a1e80();
        return;
      }
    }
  }
  return;
}


// ==== 0x4a1d00 FUN_004a1d00

void __fastcall FUN_004a1d00(int param_1)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  undefined1 local_20 [32];
  
  iVar1 = *(int *)(DAT_0073619c + 0x24);
  if (iVar1 < 2) {
    return;
  }
  if ((param_1 == 0) || (*(char *)(param_1 + 10) != '\x01')) {
    if (0 < iVar1) {
      uVar2 = *(undefined4 *)(DAT_0073619c + 0x520);
      goto LAB_004a1d3c;
    }
  }
  else if (1 < iVar1) {
    uVar2 = *(undefined4 *)(DAT_0073619c + 0x524);
    goto LAB_004a1d3c;
  }
  uVar2 = 0;
LAB_004a1d3c:
  Race__CalcTimeGapBetween((int *)(in_EAX + 0x34),param_1,uVar2);
  if ((float)*(int *)(in_EAX + 0x34) * 0.00025 != 0.0) {
    FUN_00586580(local_20);
    FEObject__SetFormattedText(&DAT_006cc568,local_20);
    HudSplitTime__Show();
  }
  return;
}


// ==== 0x4a1d90 FUN_004a1d90

void __fastcall FUN_004a1d90(int param_1)

{
  int in_EAX;
  int iVar1;
  undefined1 local_20 [32];
  
  if (*(char *)(param_1 + 0xd) != '\0') {
    iVar1 = *(int *)(param_1 + 0x38 + *(char *)(DAT_0073619c + 0x53f) * 4) -
            *(int *)(DAT_0073619c + 0x18);
    if ((float)iVar1 * 0.00025 == 0.0) {
      *(int *)(in_EAX + 0x34) =
           *(int *)(param_1 + 0x84 + *(char *)(param_1 + 9) * 4) - *(int *)(DAT_0073619c + 0x18);
    }
    else {
      *(int *)(in_EAX + 0x34) = iVar1;
    }
    FUN_00586580(local_20);
    FEObject__SetFormattedText(&DAT_006cc568,local_20);
    HudSplitTime__Show();
  }
  return;
}


// ==== 0x4a1e20 FUN_004a1e20

void __fastcall FUN_004a1e20(int param_1)

{
  int in_EAX;
  undefined1 local_20 [32];
  
  if (*(char *)(in_EAX + 0xd) != '\0') {
    *(undefined4 *)(param_1 + 0x34) =
         *(undefined4 *)(in_EAX + 0x38 + *(char *)(DAT_0073619c + 0x53f) * 4);
    FUN_00586580(local_20);
    FEObject__SetFormattedText(&DAT_006cc568,local_20);
    HudSplitTime__Show();
  }
  return;
}


// ==== 0x4a1e80 FUN_004a1e80

void __fastcall FUN_004a1e80(int param_1)

{
  int in_EAX;
  int iVar1;
  undefined1 local_20 [32];
  
  if ((*(char *)(param_1 + 0xd) != '\0') && (iVar1 = (int)*(char *)(param_1 + 9), 1 < iVar1)) {
    *(int *)(in_EAX + 0x34) =
         *(int *)(param_1 + 0x88 + iVar1 * 4) - *(int *)(param_1 + 0x84 + iVar1 * 4);
    FUN_00586580(local_20);
    FEObject__SetFormattedText(&DAT_006cc568,local_20);
    HudSplitTime__Show();
  }
  return;
}


// ==== 0x4a1ee0 HudSplitTime::Show

/* [canon] hud med (ghidra-canon) docs/re/canon.md */

void HudSplitTime__Show(void)

{
  int unaff_ESI;
  char *pcVar1;
  
  if (*(char *)(unaff_ESI + 0x28) == '\0') {
    *(undefined4 *)(unaff_ESI + 0x2c) = DAT_0073ad34;
    if ((float)*(int *)(unaff_ESI + 0x34) * 0.00025 <= 0.0) {
      pcVar1 = "ZoominGreen";
    }
    else {
      pcVar1 = "ZoominRed";
    }
    FEObject__SetScript(pcVar1,1);
    FEObject__SetVisible(*(undefined4 *)(unaff_ESI + 0x20));
    *(undefined1 *)(unaff_ESI + 0x28) = 1;
  }
  return;
}


// ==== 0x4a1f40 HudLeaderboard::HudLeaderboard

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

int HudLeaderboard__HudLeaderboard(int param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  byte *pbVar8;
  char *pcVar9;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  undefined4 uVar10;
  int extraout_EDX_02;
  int iVar11;
  undefined4 *puVar12;
  int *piVar13;
  byte local_2c;
  byte local_2b [31];
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_00687df8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(int *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0x800000;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  local_4 = 0;
  puVar12 = (undefined4 *)(param_1 + 0x20);
  param_2 = 4;
  do {
    puVar12[2] = 0;
    *puVar12 = 0xffffffff;
    puVar12[1] = 0xffffffff;
    puVar12[2] = 0;
    bSPrintf_regdst(0x20,&DAT_006b9172);
    puVar12[0xb] = 0;
    puVar12 = puVar12 + 0xc;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  *(undefined4 *)(param_1 + 0x13c) = 0;
  param_2 = 0;
  do {
    iVar4 = param_2 + 1;
    bSPrintf_regdst(0x20,"LBData_%d",iVar4);
    iVar11 = -1;
    pbVar8 = &local_2c;
    bVar3 = local_2c;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      pbVar1 = pbVar8 + 1;
      iVar11 = iVar11 * 0x21 + (uint)bVar3;
      pbVar8 = pbVar8 + 1;
      bVar3 = *pbVar1;
    }
    if (*(int *)(param_1 + 8) == 0) goto LAB_004a20bf;
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) goto LAB_004a2087;
    if (DAT_0073578c == 0) {
LAB_004a2165:
      iVar11 = 0;
    }
    else {
      iVar6 = *(int *)(DAT_0073578c + 8);
      if (iVar6 != 0) {
        FUN_004ee660();
        iVar5 = FUN_004fd1e0(iVar6 + 0xdc);
        if (iVar5 == 0) {
          FUN_004ee660();
          iVar5 = FUN_004fd1e0(iVar6 + 0xec);
          if (iVar5 == 0) goto LAB_004a20bf;
        }
LAB_004a2087:
        local_4._0_1_ = 1;
        FUN_004ffb00(iVar5);
        local_4 = (uint)local_4._1_3_ << 8;
      }
LAB_004a20bf:
      if (((DAT_0073578c == 0) || (iVar11 = FUN_004ef050(iVar11), iVar11 == 0)) ||
         (*(int *)(iVar11 + 0x18) != 2)) goto LAB_004a2165;
      if (DAT_007349b4 == 0) {
        FUN_005649f0();
      }
      iVar5 = DAT_007349b4;
      piVar13 = (int *)(DAT_007349b4 + 0x10);
      if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
        FUN_00566e60();
      }
      piVar7 = (int *)*piVar13;
      iVar6 = *(int *)(iVar5 + 0x18) + 1;
      if (piVar7 == (int *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        iVar2 = *piVar7;
        if (*(int *)(iVar5 + 0x1c) < iVar6) {
          *(int *)(iVar5 + 0x1c) = iVar6;
        }
        *(int *)(iVar5 + 0x18) = iVar6;
        bVar3 = *(byte *)(iVar5 + 0x14);
        *piVar13 = iVar2;
        if (((bVar3 & 2) != 0) && (iVar5 = *(int *)(iVar5 + 0x28) >> 2, piVar13 = piVar7, 0 < iVar5)
           ) {
          for (; iVar5 != 0; iVar5 = iVar5 + -1) {
            *piVar13 = 0;
            piVar13 = piVar13 + 1;
          }
        }
        piVar7[2] = iVar11;
      }
      puVar12 = *(undefined4 **)(param_1 + 4);
      *puVar12 = piVar7;
      *(int **)(param_1 + 4) = piVar7;
      piVar7[1] = (int)puVar12;
      *piVar7 = param_1;
    }
    *(int *)(param_1 + 0xf4 + param_2 * 4) = iVar11;
    if ((iVar11 != 0) &&
       (*(uint *)(iVar11 + 0x1c) = *(uint *)(iVar11 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar11 + 0x18) == 5)) {
      uVar10 = *(undefined4 *)(iVar11 + 0x60);
      iVar11 = *(int *)(iVar11 + 0x5c);
      if (0 < iVar11) {
        do {
          FEObject__SetVisible(uVar10);
          uVar10 = *(undefined4 *)(extraout_EDX + 4);
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
      }
    }
    bSPrintf_regdst(0x20,"LBTextBacking_%d",iVar4);
    iVar11 = -1;
    pbVar8 = &local_2c;
    bVar3 = local_2c;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar11 = iVar11 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar8 + 1;
      pbVar8 = pbVar8 + 1;
      bVar3 = *pbVar1;
    }
    if (*(int *)(param_1 + 8) == 0) goto LAB_004a22a6;
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) goto LAB_004a226e;
    if (DAT_0073578c == 0) {
LAB_004a234c:
      iVar11 = 0;
    }
    else {
      iVar6 = *(int *)(DAT_0073578c + 8);
      if (iVar6 != 0) {
        FUN_004ee660();
        iVar5 = FUN_004fd1e0(iVar6 + 0xdc);
        if (iVar5 == 0) {
          FUN_004ee660();
          iVar5 = FUN_004fd1e0(iVar6 + 0xec);
          if (iVar5 == 0) goto LAB_004a22a6;
        }
LAB_004a226e:
        local_4._0_1_ = 2;
        FUN_004ffb00(iVar5);
        local_4 = (uint)local_4._1_3_ << 8;
      }
LAB_004a22a6:
      if (((DAT_0073578c == 0) || (iVar11 = FUN_004ef050(iVar11), iVar11 == 0)) ||
         (*(int *)(iVar11 + 0x18) != 1)) goto LAB_004a234c;
      if (DAT_007349b4 == 0) {
        FUN_005649f0();
      }
      iVar5 = DAT_007349b4;
      piVar13 = (int *)(DAT_007349b4 + 0x10);
      if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
        FUN_00566e60();
      }
      piVar7 = (int *)*piVar13;
      iVar6 = *(int *)(iVar5 + 0x18) + 1;
      if (piVar7 == (int *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        iVar2 = *piVar7;
        if (*(int *)(iVar5 + 0x1c) < iVar6) {
          *(int *)(iVar5 + 0x1c) = iVar6;
        }
        *(int *)(iVar5 + 0x18) = iVar6;
        bVar3 = *(byte *)(iVar5 + 0x14);
        *piVar13 = iVar2;
        if (((bVar3 & 2) != 0) && (iVar5 = *(int *)(iVar5 + 0x28) >> 2, piVar13 = piVar7, 0 < iVar5)
           ) {
          for (; iVar5 != 0; iVar5 = iVar5 + -1) {
            *piVar13 = 0;
            piVar13 = piVar13 + 1;
          }
        }
        piVar7[2] = iVar11;
      }
      puVar12 = *(undefined4 **)(param_1 + 4);
      *puVar12 = piVar7;
      *(int **)(param_1 + 4) = piVar7;
      piVar7[1] = (int)puVar12;
      *piVar7 = param_1;
    }
    *(int *)(param_1 + 0x114 + param_2 * 4) = iVar11;
    if ((iVar11 != 0) &&
       (*(uint *)(iVar11 + 0x1c) = *(uint *)(iVar11 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar11 + 0x18) == 5)) {
      uVar10 = *(undefined4 *)(iVar11 + 0x60);
      iVar11 = *(int *)(iVar11 + 0x5c);
      if (0 < iVar11) {
        do {
          FEObject__SetVisible(uVar10);
          uVar10 = *(undefined4 *)(extraout_EDX_00 + 4);
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
      }
    }
    bSPrintf_regdst(0x20,"LeaderText_%d",iVar4);
    iVar11 = -1;
    pbVar8 = &local_2c;
    bVar3 = local_2c;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      pbVar1 = pbVar8 + 1;
      iVar11 = iVar11 * 0x21 + (uint)bVar3;
      pbVar8 = pbVar8 + 1;
      bVar3 = *pbVar1;
    }
    if (*(int *)(param_1 + 8) == 0) goto LAB_004a2490;
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) goto LAB_004a2458;
    if (DAT_0073578c == 0) {
LAB_004a2538:
      iVar11 = 0;
    }
    else {
      iVar6 = *(int *)(DAT_0073578c + 8);
      if (iVar6 != 0) {
        FUN_004ee660();
        iVar5 = FUN_004fd1e0(iVar6 + 0xdc);
        if (iVar5 == 0) {
          FUN_004ee660();
          iVar5 = FUN_004fd1e0(iVar6 + 0xec);
          if (iVar5 == 0) goto LAB_004a2490;
        }
LAB_004a2458:
        local_4._0_1_ = 3;
        FUN_004ffb00(iVar5);
        local_4 = (uint)local_4._1_3_ << 8;
      }
LAB_004a2490:
      if (((DAT_0073578c == 0) || (iVar11 = FUN_004ef050(iVar11), iVar11 == 0)) ||
         (*(int *)(iVar11 + 0x18) != 2)) goto LAB_004a2538;
      if (DAT_007349b4 == 0) {
        FUN_005649f0();
      }
      iVar5 = DAT_007349b4;
      piVar13 = (int *)(DAT_007349b4 + 0x10);
      if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
        FUN_00566e60();
      }
      piVar7 = (int *)*piVar13;
      iVar6 = *(int *)(iVar5 + 0x18) + 1;
      if (piVar7 == (int *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        iVar2 = *piVar7;
        if (*(int *)(iVar5 + 0x1c) < iVar6) {
          *(int *)(iVar5 + 0x1c) = iVar6;
        }
        *(int *)(iVar5 + 0x18) = iVar6;
        bVar3 = *(byte *)(iVar5 + 0x14);
        *piVar13 = iVar2;
        if (((bVar3 & 2) != 0) && (iVar5 = *(int *)(iVar5 + 0x28) >> 2, piVar13 = piVar7, 0 < iVar5)
           ) {
          for (; iVar5 != 0; iVar5 = iVar5 + -1) {
            *piVar13 = 0;
            piVar13 = piVar13 + 1;
          }
        }
        piVar7[2] = iVar11;
      }
      puVar12 = *(undefined4 **)(param_1 + 4);
      *puVar12 = piVar7;
      *(int **)(param_1 + 4) = piVar7;
      piVar7[1] = (int)puVar12;
      *piVar7 = param_1;
    }
    *(int *)(param_1 + 0x104 + param_2 * 4) = iVar11;
    if ((iVar11 != 0) &&
       (*(uint *)(iVar11 + 0x1c) = *(uint *)(iVar11 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar11 + 0x18) == 5)) {
      uVar10 = *(undefined4 *)(iVar11 + 0x60);
      iVar11 = *(int *)(iVar11 + 0x5c);
      if (0 < iVar11) {
        do {
          FEObject__SetVisible(uVar10);
          uVar10 = *(undefined4 *)(extraout_EDX_01 + 4);
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
      }
    }
    bSPrintf_regdst(0x20,"LBBacking_%d",iVar4);
    iVar11 = -1;
    pbVar8 = &local_2c;
    bVar3 = local_2c;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      pbVar1 = pbVar8 + 1;
      iVar11 = iVar11 * 0x21 + (uint)bVar3;
      pbVar8 = pbVar8 + 1;
      bVar3 = *pbVar1;
    }
    if (*(int *)(param_1 + 8) == 0) goto LAB_004a2680;
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) goto LAB_004a2648;
    if (DAT_0073578c == 0) {
LAB_004a2728:
      iVar11 = 0;
    }
    else {
      iVar6 = *(int *)(DAT_0073578c + 8);
      if (iVar6 != 0) {
        FUN_004ee660();
        iVar5 = FUN_004fd1e0(iVar6 + 0xdc);
        if (iVar5 == 0) {
          FUN_004ee660();
          iVar5 = FUN_004fd1e0(iVar6 + 0xec);
          if (iVar5 == 0) goto LAB_004a2680;
        }
LAB_004a2648:
        local_4._0_1_ = 4;
        FUN_004ffb00(iVar5);
        local_4 = (uint)local_4._1_3_ << 8;
      }
LAB_004a2680:
      if (((DAT_0073578c == 0) || (iVar11 = FUN_004ef050(iVar11), iVar11 == 0)) ||
         (*(int *)(iVar11 + 0x18) != 1)) goto LAB_004a2728;
      if (DAT_007349b4 == 0) {
        FUN_005649f0();
      }
      iVar5 = DAT_007349b4;
      piVar13 = (int *)(DAT_007349b4 + 0x10);
      if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
        FUN_00566e60();
      }
      piVar7 = (int *)*piVar13;
      iVar6 = *(int *)(iVar5 + 0x18) + 1;
      if (piVar7 == (int *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        iVar2 = *piVar7;
        if (*(int *)(iVar5 + 0x1c) < iVar6) {
          *(int *)(iVar5 + 0x1c) = iVar6;
        }
        *(int *)(iVar5 + 0x18) = iVar6;
        bVar3 = *(byte *)(iVar5 + 0x14);
        *piVar13 = iVar2;
        if (((bVar3 & 2) != 0) && (iVar5 = *(int *)(iVar5 + 0x28) >> 2, piVar13 = piVar7, 0 < iVar5)
           ) {
          for (; iVar5 != 0; iVar5 = iVar5 + -1) {
            *piVar13 = 0;
            piVar13 = piVar13 + 1;
          }
        }
        piVar7[2] = iVar11;
      }
      puVar12 = *(undefined4 **)(param_1 + 4);
      *puVar12 = piVar7;
      *(int **)(param_1 + 4) = piVar7;
      piVar7[1] = (int)puVar12;
      *piVar7 = param_1;
    }
    *(int *)(param_1 + 0x124 + param_2 * 4) = iVar11;
    if ((iVar11 != 0) &&
       (*(uint *)(iVar11 + 0x1c) = *(uint *)(iVar11 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar11 + 0x18) == 5)) {
      iVar5 = *(int *)(iVar11 + 0x5c);
      uVar10 = *(undefined4 *)(iVar11 + 0x60);
      if (0 < iVar5) {
        do {
          FEObject__SetVisible(uVar10);
          uVar10 = *(undefined4 *)(extraout_EDX_02 + 4);
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
    }
    puVar12 = (undefined4 *)(param_2 * 0x30 + 0x144 + param_1);
    for (iVar11 = 0xc; iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
    param_2 = iVar4;
  } while (iVar4 < 4);
  pcVar9 = "LeaderBoardFill";
  iVar11 = -1;
  bVar3 = 0x4c;
  do {
    if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
      bVar3 = bVar3 - 0x20;
    }
    iVar11 = iVar11 * 0x21 + (uint)bVar3;
    bVar3 = pcVar9[1];
    pcVar9 = pcVar9 + 1;
  } while (bVar3 != 0);
  if (*(int *)(param_1 + 8) == 0) goto LAB_004a2874;
  iVar4 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) goto LAB_004a283c;
  if (DAT_0073578c == 0) {
LAB_004a2918:
    iVar11 = 0;
  }
  else {
    iVar5 = *(int *)(DAT_0073578c + 8);
    if (iVar5 != 0) {
      FUN_004ee660();
      iVar4 = FUN_004fd1e0(iVar5 + 0xdc);
      if (iVar4 == 0) {
        FUN_004ee660();
        iVar4 = FUN_004fd1e0(iVar5 + 0xec);
        if (iVar4 == 0) goto LAB_004a2874;
      }
LAB_004a283c:
      local_4._0_1_ = 5;
      FUN_004ffb00(iVar4);
      local_4 = (uint)local_4._1_3_ << 8;
    }
LAB_004a2874:
    if (((DAT_0073578c == 0) || (iVar11 = FUN_004ef050(iVar11), iVar11 == 0)) ||
       (*(int *)(iVar11 + 0x18) != 1)) goto LAB_004a2918;
    if (DAT_007349b4 == 0) {
      FUN_005649f0();
    }
    iVar4 = DAT_007349b4;
    piVar13 = (int *)(DAT_007349b4 + 0x10);
    if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
      FUN_00566e60();
    }
    piVar7 = (int *)*piVar13;
    iVar5 = *(int *)(iVar4 + 0x18) + 1;
    if (piVar7 == (int *)0x0) {
      piVar7 = (int *)0x0;
    }
    else {
      iVar6 = *piVar7;
      if (*(int *)(iVar4 + 0x1c) < iVar5) {
        *(int *)(iVar4 + 0x1c) = iVar5;
      }
      *(int *)(iVar4 + 0x18) = iVar5;
      bVar3 = *(byte *)(iVar4 + 0x14);
      *piVar13 = iVar6;
      if (((bVar3 & 2) != 0) && (iVar4 = *(int *)(iVar4 + 0x28) >> 2, piVar13 = piVar7, 0 < iVar4))
      {
        for (; iVar4 != 0; iVar4 = iVar4 + -1) {
          *piVar13 = 0;
          piVar13 = piVar13 + 1;
        }
      }
      piVar7[2] = iVar11;
    }
    puVar12 = *(undefined4 **)(param_1 + 4);
    *puVar12 = piVar7;
    *(int **)(param_1 + 4) = piVar7;
    piVar7[1] = (int)puVar12;
    *piVar7 = param_1;
  }
  *(int *)(param_1 + 0x134) = iVar11;
  pcVar9 = "LeaderBoardLine";
  iVar11 = -1;
  bVar3 = 0x4c;
  do {
    if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
      bVar3 = bVar3 - 0x20;
    }
    iVar11 = iVar11 * 0x21 + (uint)bVar3;
    bVar3 = pcVar9[1];
    pcVar9 = pcVar9 + 1;
  } while (bVar3 != 0);
  if (*(int *)(param_1 + 8) == 0) goto LAB_004a2a07;
  iVar4 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) goto LAB_004a29cf;
  if (DAT_0073578c != 0) {
    iVar5 = *(int *)(DAT_0073578c + 8);
    if (iVar5 != 0) {
      FUN_004ee660();
      iVar4 = FUN_004fd1e0(iVar5 + 0xdc);
      if (iVar4 == 0) {
        FUN_004ee660();
        iVar4 = FUN_004fd1e0(iVar5 + 0xec);
        if (iVar4 == 0) goto LAB_004a2a07;
      }
LAB_004a29cf:
      local_4._0_1_ = 6;
      FUN_004ffb00(iVar4);
      local_4 = (uint)local_4._1_3_ << 8;
    }
LAB_004a2a07:
    if (((DAT_0073578c != 0) && (iVar11 = FUN_004ef050(iVar11), iVar11 != 0)) &&
       (*(int *)(iVar11 + 0x18) == 1)) {
      if (DAT_007349b4 == 0) {
        FUN_005649f0();
      }
      iVar4 = DAT_007349b4;
      piVar13 = (int *)(DAT_007349b4 + 0x10);
      if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
        FUN_00566e60();
      }
      piVar7 = (int *)*piVar13;
      iVar5 = *(int *)(iVar4 + 0x18) + 1;
      if (piVar7 == (int *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        iVar6 = *piVar7;
        if (*(int *)(iVar4 + 0x1c) < iVar5) {
          *(int *)(iVar4 + 0x1c) = iVar5;
        }
        *(int *)(iVar4 + 0x18) = iVar5;
        bVar3 = *(byte *)(iVar4 + 0x14);
        *piVar13 = iVar6;
        if (((bVar3 & 2) != 0) && (iVar4 = *(int *)(iVar4 + 0x28) >> 2, piVar13 = piVar7, 0 < iVar4)
           ) {
          for (; iVar4 != 0; iVar4 = iVar4 + -1) {
            *piVar13 = 0;
            piVar13 = piVar13 + 1;
          }
        }
        piVar7[2] = iVar11;
      }
      puVar12 = *(undefined4 **)(param_1 + 4);
      *puVar12 = piVar7;
      *(int **)(param_1 + 4) = piVar7;
      piVar7[1] = (int)puVar12;
      *piVar7 = param_1;
      goto LAB_004a2abb;
    }
  }
  iVar11 = 0;
LAB_004a2abb:
  *(int *)(param_1 + 0x138) = iVar11;
  *(undefined4 *)(param_1 + 0xf0) = 4;
  *(undefined4 *)(param_1 + 0x13c) = DAT_0073ad34;
  *(undefined1 *)(param_1 + 0x140) = 0;
  *(undefined1 *)(param_1 + 0x141) = 0;
  *(undefined1 *)(param_1 + 0x142) = 0;
  *(undefined4 *)(param_1 + 0x204) = 0;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4a2b10 HudLeaderboard::Update

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void HudLeaderboard__Update(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  undefined1 *puVar3;
  int unaff_ESI;
  int iVar4;
  undefined4 *puVar5;
  undefined **ppuVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int local_24;
  undefined1 local_20 [32];
  
  if ((*(uint *)(unaff_ESI + 0x18) & *(uint *)(unaff_ESI + 0x10)) == 0 &&
      (*(uint *)(unaff_ESI + 0x1c) & *(uint *)(unaff_ESI + 0x14)) == 0) {
    return;
  }
  *(undefined4 *)(unaff_ESI + 0xe0) = 0;
  *(undefined4 *)(unaff_ESI + 0xe4) = 0;
  *(undefined4 *)(unaff_ESI + 0xe8) = 0;
  *(undefined4 *)(unaff_ESI + 0xec) = 0;
  FUN_004a3930(unaff_ESI,in_EAX);
  if (DAT_0078a320 == 1) {
    if (*(char *)(unaff_ESI + 0x141) == '\0') {
      if (*(char *)(unaff_ESI + 0x140) == '\0') {
        local_24 = DAT_0073ad34 - *(int *)(unaff_ESI + 0x13c);
        if (10.0 < (float)local_24 * 0.00025) {
          *(int *)(unaff_ESI + 0x13c) = DAT_0073ad34;
          if (*(char *)(unaff_ESI + 0x142) == '\0') {
            *(undefined1 *)(unaff_ESI + 0x140) = 1;
          }
          else {
            *(undefined1 *)(unaff_ESI + 0x141) = 1;
          }
        }
        cVar1 = IsDriftMode();
        if (cVar1 == '\0') {
          FUN_004a31e0(unaff_ESI);
        }
        else {
          FUN_004a34c0(unaff_ESI,in_EAX);
        }
      }
      else {
        local_24 = DAT_0073ad34 - *(int *)(unaff_ESI + 0x13c);
        if (2.0 < (float)local_24 * 0.00025) {
          *(int *)(unaff_ESI + 0x13c) = DAT_0073ad34;
          *(undefined1 *)(unaff_ESI + 0x140) = 0;
          *(undefined1 *)(unaff_ESI + 0x142) = 1;
        }
        cVar1 = IsDriftMode();
        if (cVar1 == '\0') {
          FUN_004a2ef0(unaff_ESI);
        }
        else {
          FUN_004a3690(unaff_ESI,in_EAX);
        }
      }
    }
    else {
      local_24 = DAT_0073ad34 - *(int *)(unaff_ESI + 0x13c);
      if (2.0 < (float)local_24 * 0.00025) {
        *(int *)(unaff_ESI + 0x13c) = DAT_0073ad34;
        *(undefined1 *)(unaff_ESI + 0x141) = 0;
        *(undefined1 *)(unaff_ESI + 0x142) = 0;
      }
      if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
        FUN_004a3020(unaff_ESI);
      }
      else {
        FUN_004a37d0(unaff_ESI,in_EAX);
      }
    }
    if (((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) || (cVar1 = FUN_0043a2e0(), cVar1 != '\0'))
    {
      iVar4 = *(int *)(DAT_0073619c + 0x24);
    }
    else {
      iVar4 = 4;
    }
    if (iVar4 < 1) {
      FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0xf4));
      FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0x114));
      FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0x104));
      FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0x124));
    }
    if (*(int *)(unaff_ESI + 0xf0) <= iVar4) {
      return;
    }
    puVar5 = (undefined4 *)(unaff_ESI + 0x114 + iVar4 * 4);
    do {
      FEObject__SetInvisible(puVar5[-8]);
      FEObject__SetInvisible(*puVar5);
      FEObject__SetInvisible(puVar5[-4]);
      FEObject__SetInvisible(puVar5[4]);
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar4 < *(int *)(unaff_ESI + 0xf0));
    return;
  }
  if ((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) {
    FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0xf4));
    FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0x124));
    return;
  }
  iVar4 = 0;
  if (0 < *(int *)(unaff_ESI + 0xf0)) {
    puVar5 = (undefined4 *)(unaff_ESI + 0x114);
    do {
      FEObject__SetInvisible(puVar5[-8]);
      FEObject__SetInvisible(*puVar5);
      FEObject__SetInvisible(puVar5[-4]);
      FEObject__SetInvisible(puVar5[4]);
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar4 < *(int *)(unaff_ESI + 0xf0));
  }
  FEObject__SetVisible(*(undefined4 *)(unaff_ESI + 0xf4));
  FEObject__SetVisible(*(undefined4 *)(unaff_ESI + 0x124));
  uVar8 = DAT_0078a414;
  if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
    iVar4 = FUN_0049fcf0();
    uVar8 = *(undefined4 *)(iVar4 + 0x1c);
    iVar4 = FUN_0049fcf0();
    local_24 = 0;
    uVar7 = *(undefined4 *)(iVar4 + 0x1c);
    if (((*(int *)(in_EAX + 0x10) == 0) ||
        (uVar7 = uVar8, uVar8 = *(undefined4 *)(iVar4 + 0x1c), *(int *)(in_EAX + 0x10) == 1)) &&
       (Race__CalcTimeGapBetween(&local_24,uVar7,uVar8), local_24 < 0)) {
      FUN_00586580(local_20);
    }
    else {
      FUN_00586580(local_20);
    }
    puVar3 = local_20;
    ppuVar6 = (undefined **)&DAT_006cc568;
    goto LAB_004a2ed8;
  }
  FUN_0043ea50(DAT_0078a410);
  iVar4 = _ftol_nocw();
  FUN_0043ea50(uVar8);
  iVar2 = _ftol_nocw();
  puVar3 = (undefined1 *)0x0;
  if (*(int *)(in_EAX + 0x10) == 0) {
    puVar3 = (undefined1 *)(iVar4 - iVar2);
LAB_004a2e36:
    if ((int)puVar3 < 0) {
      ppuVar6 = (undefined **)&DAT_006ca778;
      goto LAB_004a2ed8;
    }
  }
  else if (*(int *)(in_EAX + 0x10) == 1) {
    puVar3 = (undefined1 *)(iVar2 - iVar4);
    goto LAB_004a2e36;
  }
  ppuVar6 = &PTR_FUN_006c7228;
LAB_004a2ed8:
  FEObject__SetFormattedText(ppuVar6,puVar3);
  return;
}


// ==== 0x4a2ef0 FUN_004a2ef0

void FUN_004a2ef0(int param_1)

{
  char cVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  iVar2 = param_1;
  iVar6 = *(int *)(in_EAX + 4);
  if (((DAT_006fbf14 == 0) && (*(int *)(in_EAX + 0x10) == 0)) &&
     (iVar3 = RaceManager__FindRacerById(), iVar3 != 0)) {
    iVar6 = iVar3;
  }
  if (*(int *)(iVar6 + 0x1c) != 0) {
    cVar1 = *(char *)(*(int *)(iVar6 + 0x1c) + 10);
    piVar5 = (int *)(param_1 + 0xf0);
    param_1 = 0;
    if (0 < *piVar5) {
      piVar5 = (int *)(iVar2 + 0xe0);
LAB_004a2f50:
      if (param_1 < *(int *)(DAT_0073619c + 0x24)) {
        iVar6 = piVar5[0x11];
        if (*(int *)(*piVar5 * 0x30 + 0x20 + iVar2) == (int)cVar1) {
          if (iVar6 != 0) {
            for (iVar3 = *(int *)(iVar6 + 0x4c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
              iVar4 = FEng__HashName();
              if (*(int *)(iVar3 + 0x30) == iVar4) goto LAB_004a2fbe;
            }
          }
        }
        else if (iVar6 != 0) {
          for (iVar3 = *(int *)(iVar6 + 0x4c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
            iVar4 = FEng__HashName();
            if (*(int *)(iVar3 + 0x30) == iVar4) goto LAB_004a2fbe;
          }
        }
        goto LAB_004a2fe1;
      }
    }
  }
  return;
LAB_004a2fbe:
  if (iVar3 != 0) {
    if (iVar3 != *(int *)(iVar6 + 0x54)) {
      *(int *)(iVar6 + 0x54) = iVar3;
      FUN_004ff030(iVar6);
      *(undefined4 *)(*(int *)(iVar6 + 0x54) + 0x10) = 0;
    }
    *(undefined4 *)(iVar3 + 0x10) = 0;
  }
LAB_004a2fe1:
  FEObject__SetFormattedText(&DAT_006cc568,*piVar5 * 0x30 + 0x2c + iVar2);
  param_1 = param_1 + 1;
  piVar5 = piVar5 + 1;
  if (*(int *)(iVar2 + 0xf0) <= param_1) {
    return;
  }
  goto LAB_004a2f50;
}


// ==== 0x4a3020 FUN_004a3020

void FUN_004a3020(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_8;
  
  iVar7 = *(int *)(in_EAX + 4);
  if (((DAT_006fbf14 == 0) && (*(int *)(in_EAX + 0x10) == 0)) &&
     (iVar3 = RaceManager__FindRacerById(), iVar3 != 0)) {
    iVar7 = iVar3;
  }
  if (*(int *)(iVar7 + 0x1c) != 0) {
    cVar1 = *(char *)(*(int *)(iVar7 + 0x1c) + 10);
    local_8 = 0;
    if (0 < *(int *)(param_1 + 0xf0)) {
      piVar5 = (int *)(param_1 + 0xe0);
      puVar6 = DAT_00735710;
      do {
        if (*(int *)(DAT_0073619c + 0x24) <= local_8) {
          return;
        }
        iVar7 = piVar5[0x11];
        if (*(int *)(*piVar5 * 0x30 + 0x20 + param_1) == (int)cVar1) {
          if (iVar7 != 0) {
            for (iVar3 = *(int *)(iVar7 + 0x4c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
              iVar4 = FEng__HashName();
              if (*(int *)(iVar3 + 0x30) == iVar4) {
                if (iVar3 != 0) {
                  if (iVar3 != *(int *)(iVar7 + 0x54)) {
                    *(int *)(iVar7 + 0x54) = iVar3;
                    FUN_004ff030(iVar7);
                    *(undefined4 *)(*(int *)(iVar7 + 0x54) + 0x10) = 0;
                  }
                  *(undefined4 *)(iVar3 + 0x10) = 0;
                }
                break;
              }
            }
          }
          FEObject__SetFormattedText(&DAT_006cc568,*piVar5 * 0x30 + 0x2c + param_1);
          puVar6 = DAT_00735710;
        }
        else {
          if (iVar7 != 0) {
            for (iVar3 = *(int *)(iVar7 + 0x4c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
              iVar4 = FEng__HashName();
              if (*(int *)(iVar3 + 0x30) == iVar4) {
                if (iVar3 != 0) {
                  if (iVar3 != *(int *)(iVar7 + 0x54)) {
                    *(int *)(iVar7 + 0x54) = iVar3;
                    FUN_004ff030(iVar7);
                    *(undefined4 *)(*(int *)(iVar7 + 0x54) + 0x10) = 0;
                  }
                  *(undefined4 *)(iVar3 + 0x10) = 0;
                }
                break;
              }
            }
          }
          iVar7 = piVar5[5];
          uVar2 = *(undefined4 *)(*piVar5 * 0x30 + 0x4c + param_1);
          if (iVar7 != 0) {
            *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | 0x400000;
            *(undefined4 *)(iVar7 + 0x5c) = uVar2;
            if (puVar6 != (undefined4 *)0x0) {
              (**(code **)*puVar6)(iVar7);
              puVar6 = DAT_00735710;
            }
            *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) & 0xfffffffd | 0x400000;
          }
        }
        local_8 = local_8 + 1;
        piVar5 = piVar5 + 1;
      } while (local_8 < *(int *)(param_1 + 0xf0));
    }
  }
  return;
}


// ==== 0x4a31e0 FUN_004a31e0

void FUN_004a31e0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_EAX;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  int *piVar9;
  bool bVar10;
  undefined1 local_20 [32];
  
  iVar3 = param_1;
  iVar6 = *(int *)(in_EAX + 4);
  if (((DAT_006fbf14 == 0) && (*(int *)(in_EAX + 0x10) == 0)) &&
     (iVar4 = RaceManager__FindRacerById(), iVar4 != 0)) {
    iVar6 = iVar4;
  }
  if (*(int *)(iVar6 + 0x1c) != 0) {
    cVar1 = *(char *)(*(int *)(iVar6 + 0x1c) + 10);
    piVar9 = (int *)(param_1 + 0xf0);
    param_1 = 0;
    if (0 < *piVar9) {
      piVar9 = (int *)(iVar3 + 0xe0);
      do {
        if (*(int *)(DAT_0073619c + 0x24) <= param_1) {
          return;
        }
        iVar6 = piVar9[0x11];
        if (*(int *)(*piVar9 * 0x30 + 0x20 + iVar3) == (int)cVar1) {
          if ((iVar6 == 0) || (iVar4 = *(int *)(iVar6 + 0x4c), iVar4 == 0)) {
LAB_004a32ba:
            puVar8 = (undefined1 *)(*piVar9 * 0x30 + 0x2c + iVar3);
          }
          else {
            do {
              iVar5 = FEng__HashName();
              if (*(int *)(iVar4 + 0x30) == iVar5) {
                if (iVar4 != 0) {
                  if (iVar4 != *(int *)(iVar6 + 0x54)) {
                    *(int *)(iVar6 + 0x54) = iVar4;
                    FUN_004ff030(iVar6);
                    *(undefined4 *)(*(int *)(iVar6 + 0x54) + 0x10) = 0;
                  }
                  *(undefined4 *)(iVar4 + 0x10) = 0;
                }
                goto LAB_004a32ba;
              }
              iVar4 = *(int *)(iVar4 + 4);
            } while (iVar4 != 0);
            puVar8 = (undefined1 *)(*piVar9 * 0x30 + 0x2c + iVar3);
          }
LAB_004a33c0:
          FEObject__SetFormattedText(&DAT_006cc568,puVar8);
        }
        else {
          if (iVar6 != 0) {
            for (iVar4 = *(int *)(iVar6 + 0x4c); iVar4 != 0; iVar4 = *(int *)(iVar4 + 4)) {
              iVar5 = FEng__HashName();
              if (*(int *)(iVar4 + 0x30) == iVar5) {
                if (iVar4 != 0) {
                  if (iVar4 != *(int *)(iVar6 + 0x54)) {
                    *(int *)(iVar6 + 0x54) = iVar4;
                    FUN_004ff030(iVar6);
                    *(undefined4 *)(*(int *)(iVar6 + 0x54) + 0x10) = 0;
                  }
                  *(undefined4 *)(iVar4 + 0x10) = 0;
                }
                break;
              }
            }
          }
          iVar6 = *(int *)(*piVar9 * 0x30 + 0x20 + iVar3);
          if (*(int *)(DAT_0073619c + 0x24) < iVar6) {
            iVar6 = 0;
          }
          else {
            iVar6 = *(int *)(DAT_0073619c + 0x51c + iVar6 * 4);
          }
          if (*(short *)(iVar6 + 0x10) == 0) {
            FUN_00586580(local_20);
            puVar8 = local_20;
            goto LAB_004a33c0;
          }
          switch(*(short *)(iVar6 + 0x10)) {
          case 3:
            uVar7 = 0x5d82dba2;
            break;
          default:
            uVar7 = 0xd4293449;
            break;
          case 6:
            uVar7 = 0x1e66364;
            break;
          case 7:
            uVar7 = 0xb7b75185;
            break;
          case 9:
            uVar7 = 0x1ce129e0;
            break;
          case 10:
            uVar7 = 0xa7db717f;
          }
          iVar6 = piVar9[5];
          if (iVar6 != 0) {
            *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) | 0x400000;
            puVar2 = DAT_00735710;
            bVar10 = DAT_00735710 != (undefined4 *)0x0;
            *(undefined4 *)(iVar6 + 0x5c) = uVar7;
            if (bVar10) {
              (**(code **)*puVar2)(iVar6);
            }
            *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) & 0xfffffffd | 0x400000;
          }
        }
        param_1 = param_1 + 1;
        piVar9 = piVar9 + 1;
      } while (param_1 < *(int *)(iVar3 + 0xf0));
    }
  }
  return;
}


// ==== 0x4a3420 FUN_004a3420

void __fastcall FUN_004a3420(undefined4 param_1,int param_2,undefined4 param_3)

{
  if ((*(uint *)(param_2 + 8) & 0x800000) != 0) {
    FUN_004a3440(*(undefined4 *)(param_2 + 0x44),param_3);
  }
  return;
}


// ==== 0x4a3440 FUN_004a3440

void FUN_004a3440(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar1 = FUN_0043f1f0();
  puVar4 = (undefined4 *)(param_1 + 0x148);
  do {
    iVar2 = bTList__EndOfList();
    if (iVar1 == iVar2) {
      return;
    }
    puVar4[-1] = *(undefined4 *)(iVar1 + 8);
    *puVar4 = *(undefined4 *)(iVar1 + 0x10);
    *(undefined1 *)(puVar4 + 1) = *(undefined1 *)(iVar1 + 0x14);
    bSPrintf_regdst(0x20,*(undefined4 *)(iVar1 + 0x18));
    uVar3 = GetCarModelNameHash();
    puVar4[10] = uVar3;
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 0xc;
    iVar1 = FUN_0043f1f0();
  } while (iVar5 < 4);
  return;
}


// ==== 0x4a34c0 FUN_004a34c0

void FUN_004a34c0(int param_1)

{
  undefined4 *puVar1;
  byte bVar2;
  char cVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  undefined *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  undefined4 *local_8;
  
  iVar12 = 0;
  if (*(int *)(param_1 + 0xf0) < 1) {
    return;
  }
  local_8 = (undefined4 *)(param_1 + 0x144);
  piVar4 = (int *)(param_1 + 0x124);
LAB_004a34f0:
  iVar10 = *piVar4;
  if (*(char *)(local_8 + 2) == '\0') {
    if (iVar10 != 0) {
      puVar9 = &DAT_006c7a3c;
      bVar2 = 0x49;
      iVar7 = -1;
      do {
        if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
          bVar2 = bVar2 - 0x20;
        }
        iVar7 = iVar7 * 0x21 + (uint)bVar2;
        bVar2 = puVar9[1];
        puVar9 = puVar9 + 1;
      } while (bVar2 != 0);
      for (iVar11 = *(int *)(iVar10 + 0x4c); iVar11 != 0; iVar11 = *(int *)(iVar11 + 4)) {
        if (*(int *)(iVar11 + 0x30) == iVar7) goto LAB_004a357f;
      }
    }
  }
  else if (iVar10 != 0) {
    pcVar8 = "SetPlayerColor";
    iVar7 = -1;
    bVar2 = 0x53;
    do {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar7 = iVar7 * 0x21 + (uint)bVar2;
      bVar2 = pcVar8[1];
      pcVar8 = pcVar8 + 1;
    } while (bVar2 != 0);
    for (iVar11 = *(int *)(iVar10 + 0x4c); iVar11 != 0; iVar11 = *(int *)(iVar11 + 4)) {
      if (*(int *)(iVar11 + 0x30) == iVar7) goto LAB_004a357f;
    }
  }
  goto LAB_004a359a;
LAB_004a357f:
  if (iVar11 != 0) {
    if (iVar11 != *(int *)(iVar10 + 0x54)) {
      *(int *)(iVar10 + 0x54) = iVar11;
      FUN_004ff030(iVar10);
      *(undefined4 *)(*(int *)(iVar10 + 0x54) + 0x10) = 0;
    }
    *(undefined4 *)(iVar11 + 0x10) = 0;
  }
LAB_004a359a:
  iVar10 = 0;
  cVar3 = FUN_0043a2e0();
  if (((cVar3 != '\0') && (piVar5 = (int *)Race__GetPlayer(*local_8), piVar5 != (int *)0x0)) &&
     (((iVar7 = *piVar5, iVar7 == 3 || (((iVar7 == 4 || (iVar7 == 5)) || (iVar7 == 0)))) ||
      (iVar7 == 6)))) {
    if (piVar5[0xc] == 9) {
      iVar10 = 0x1ce129e0;
    }
    else if (piVar5[0xc] == 10) {
      iVar10 = -0x58248e81;
    }
    else {
      iVar10 = -0x2bd6cbb7;
    }
  }
  iVar12 = iVar12 + 1;
  FEObject__SetFormattedText(&DAT_006c7214,iVar12);
  if (iVar10 == 0) {
    uVar6 = _ftol_nocw();
    FEObject__SetFormattedText(&DAT_006ca778,uVar6);
  }
  else {
    iVar7 = piVar4[-0xc];
    if (iVar7 != 0) {
      *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | 0x400000;
      puVar1 = DAT_00735710;
      bVar13 = DAT_00735710 != (undefined4 *)0x0;
      *(int *)(iVar7 + 0x5c) = iVar10;
      if (bVar13) {
        (**(code **)*puVar1)(iVar7);
      }
      *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) & 0xfffffffd | 0x400000;
    }
  }
  local_8 = local_8 + 0xc;
  piVar4 = piVar4 + 1;
  if (*(int *)(param_1 + 0xf0) <= iVar12) {
    return;
  }
  goto LAB_004a34f0;
}


// ==== 0x4a3690 FUN_004a3690

void FUN_004a3690(int param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  undefined *puVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int local_4;
  
  iVar6 = 0;
  if (*(int *)(param_1 + 0xf0) < 1) {
    return;
  }
  local_4 = param_1 + 0x14d;
  piVar7 = (int *)(param_1 + 0x124);
LAB_004a36c0:
  iVar1 = *piVar7;
  if (*(char *)(local_4 + -1) == '\0') {
    if (iVar1 != 0) {
      puVar5 = &DAT_006c7a3c;
      bVar2 = 0x49;
      iVar3 = -1;
      do {
        if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
          bVar2 = bVar2 - 0x20;
        }
        iVar3 = iVar3 * 0x21 + (uint)bVar2;
        bVar2 = puVar5[1];
        puVar5 = puVar5 + 1;
      } while (bVar2 != 0);
      for (iVar8 = *(int *)(iVar1 + 0x4c); iVar8 != 0; iVar8 = *(int *)(iVar8 + 4)) {
        if (*(int *)(iVar8 + 0x30) == iVar3) goto LAB_004a374f;
      }
    }
  }
  else if (iVar1 != 0) {
    pcVar4 = "SetPlayerColor";
    iVar3 = -1;
    bVar2 = 0x53;
    do {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar3 = iVar3 * 0x21 + (uint)bVar2;
      bVar2 = pcVar4[1];
      pcVar4 = pcVar4 + 1;
    } while (bVar2 != 0);
    for (iVar8 = *(int *)(iVar1 + 0x4c); iVar8 != 0; iVar8 = *(int *)(iVar8 + 4)) {
      if (*(int *)(iVar8 + 0x30) == iVar3) goto LAB_004a374f;
    }
  }
  goto LAB_004a3772;
LAB_004a374f:
  if (iVar8 != 0) {
    if (iVar8 != *(int *)(iVar1 + 0x54)) {
      *(int *)(iVar1 + 0x54) = iVar8;
      FUN_004ff030(iVar1);
      *(undefined4 *)(*(int *)(iVar1 + 0x54) + 0x10) = 0;
    }
    *(undefined4 *)(iVar8 + 0x10) = 0;
  }
LAB_004a3772:
  FEObject__SetFormattedText(&DAT_006cc568,local_4);
  iVar6 = iVar6 + 1;
  FEObject__SetFormattedText(&DAT_006c7214,iVar6);
  local_4 = local_4 + 0x30;
  piVar7 = piVar7 + 1;
  if (*(int *)(param_1 + 0xf0) <= iVar6) {
    return;
  }
  goto LAB_004a36c0;
}


// ==== 0x4a37d0 FUN_004a37d0

void FUN_004a37d0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  byte bVar4;
  int iVar5;
  char *pcVar6;
  undefined *puVar7;
  int *piVar8;
  int iVar9;
  bool bVar10;
  undefined4 *local_8;
  int local_4;
  
  local_4 = 0;
  if (*(int *)(param_1 + 0xf0) < 1) {
    return;
  }
  local_8 = (undefined4 *)(param_1 + 0x170);
  piVar8 = (int *)(param_1 + 0x124);
LAB_004a3800:
  iVar1 = *piVar8;
  if (*(char *)(local_8 + -9) == '\0') {
    if (iVar1 != 0) {
      puVar7 = &DAT_006c7a3c;
      bVar4 = 0x49;
      iVar5 = -1;
      do {
        if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
          bVar4 = bVar4 - 0x20;
        }
        iVar5 = iVar5 * 0x21 + (uint)bVar4;
        bVar4 = puVar7[1];
        puVar7 = puVar7 + 1;
      } while (bVar4 != 0);
      for (iVar9 = *(int *)(iVar1 + 0x4c); iVar9 != 0; iVar9 = *(int *)(iVar9 + 4)) {
        if (*(int *)(iVar9 + 0x30) == iVar5) goto LAB_004a388f;
      }
    }
  }
  else if (iVar1 != 0) {
    pcVar6 = "SetPlayerColor";
    iVar5 = -1;
    bVar4 = 0x53;
    do {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      iVar5 = iVar5 * 0x21 + (uint)bVar4;
      bVar4 = pcVar6[1];
      pcVar6 = pcVar6 + 1;
    } while (bVar4 != 0);
    for (iVar9 = *(int *)(iVar1 + 0x4c); iVar9 != 0; iVar9 = *(int *)(iVar9 + 4)) {
      if (*(int *)(iVar9 + 0x30) == iVar5) goto LAB_004a388f;
    }
  }
  goto LAB_004a38aa;
LAB_004a388f:
  if (iVar9 != 0) {
    if (iVar9 != *(int *)(iVar1 + 0x54)) {
      *(int *)(iVar1 + 0x54) = iVar9;
      FUN_004ff030(iVar1);
      *(undefined4 *)(*(int *)(iVar1 + 0x54) + 0x10) = 0;
    }
    *(undefined4 *)(iVar9 + 0x10) = 0;
  }
LAB_004a38aa:
  iVar1 = piVar8[-0xc];
  uVar2 = *local_8;
  if (iVar1 != 0) {
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
    puVar3 = DAT_00735710;
    bVar10 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar1 + 0x5c) = uVar2;
    if (bVar10) {
      (**(code **)*puVar3)(iVar1);
    }
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffd | 0x400000;
  }
  local_4 = local_4 + 1;
  FEObject__SetFormattedText(&DAT_006c7214,local_4);
  local_8 = local_8 + 0xc;
  piVar8 = piVar8 + 1;
  if (*(int *)(param_1 + 0xf0) <= local_4) {
    return;
  }
  goto LAB_004a3800;
}


// ==== 0x4a3930 FUN_004a3930

void FUN_004a3930(int param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_c;
  int local_8;
  
  iVar8 = *(int *)(param_2 + 4);
  if (((DAT_006fbf14 == 0) && (*(int *)(param_2 + 0x10) == 0)) &&
     (iVar4 = RaceManager__FindRacerById(), iVar4 != 0)) {
    iVar8 = iVar4;
  }
  iVar8 = *(int *)(iVar8 + 0x1c);
  if (iVar8 != 0) {
    iVar4 = *(int *)(DAT_0073619c + 0x24);
    if (0 < iVar4) {
      local_8 = 1;
      iVar9 = param_1 + 0x2c;
      local_c = 0x520;
      iVar7 = DAT_0073619c;
      do {
        if (((local_8 <= iVar4) && (piVar1 = *(int **)(local_c + iVar7), piVar1 != (int *)0x0)) &&
           ((iVar4 = *piVar1, iVar4 != 0 && (*(int *)(iVar4 + 0xc) != 0)))) {
          *(int *)(iVar9 + -0xc) = local_8;
          uVar5 = GetCarModelNameHash();
          *(undefined4 *)(iVar9 + 0x20) = uVar5;
          cVar3 = FUN_0043a2e0();
          if (cVar3 == '\0') {
            iVar4 = *(int *)(iVar4 + 0x14);
            if ((*(int *)(iVar4 + 4) == 1) && (*(char *)(iVar4 + 0x734) == '\0')) {
              puVar6 = &DAT_007588c4 + *(int *)(param_2 + 0x10) * 0xf944;
            }
            else {
              puVar6 = (undefined1 *)(iVar4 + 0x73c);
            }
LAB_004a3a2b:
            bSPrintf_regdst(0x20,puVar6);
          }
          else {
            iVar4 = Race__GetPlayer((int)*(short *)(iVar4 + 10));
            if (iVar4 != 0) {
              puVar6 = (undefined1 *)(iVar4 + 0x19);
              goto LAB_004a3a2b;
            }
          }
          iVar7 = DAT_0073619c;
          if ((short)piVar1[4] == 0) {
            Race__CalcTimeGapBetween(iVar9 + -4,piVar1,iVar8);
          }
          else {
            *(undefined4 *)(iVar9 + -4) = 0;
          }
        }
        iVar4 = *(int *)(iVar7 + 0x24);
        local_c = local_c + 4;
        iVar9 = iVar9 + 0x30;
        bVar2 = local_8 < iVar4;
        local_8 = local_8 + 1;
      } while (bVar2);
    }
    FUN_004a3aa0(param_1);
  }
  return;
}


// ==== 0x4a3aa0 FUN_004a3aa0

void FUN_004a3aa0(int param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int local_40;
  int local_3c [8];
  int local_1c [7];
  
  iVar3 = *(int *)(in_EAX + 4);
  if (((DAT_006fbf14 == 0) && (*(int *)(in_EAX + 0x10) == 0)) &&
     (iVar2 = RaceManager__FindRacerById(), iVar2 != 0)) {
    iVar3 = iVar2;
  }
  iVar2 = 0;
  if (*(int *)(iVar3 + 0x1c) != 0) {
    iVar5 = (int)*(char *)(*(int *)(iVar3 + 0x1c) + 10);
    iVar6 = iVar5 + -1;
    iVar3 = *(int *)(param_1 + 0xf0) + -1;
    local_3c[0] = 0;
    *(undefined4 *)(param_1 + 0xe0) = 0;
    if (0 < iVar3) {
      iVar1 = *(int *)(DAT_0073619c + 0x24);
      iVar8 = iVar5 + -2;
      local_40 = 0;
      if (0 < iVar1) {
        do {
          if (iVar3 < 1) break;
          if ((0 < iVar8) && (1 < iVar3)) {
            local_3c[iVar2 + 1] = iVar8;
            iVar2 = iVar2 + 1;
            iVar3 = iVar3 + -1;
            iVar8 = iVar8 + -1;
          }
          if ((iVar5 < iVar1) && (0 < iVar3)) {
            local_1c[local_3c[0]] = iVar5;
            iVar3 = iVar3 + -1;
            local_3c[0] = local_3c[0] + 1;
            iVar5 = iVar5 + 1;
          }
          local_40 = local_40 + 1;
        } while (local_40 < iVar1);
      }
    }
    iVar3 = 1;
    if (0 < iVar2) {
      piVar7 = (int *)(param_1 + 0xe4);
      piVar4 = local_3c + iVar2;
      iVar3 = iVar2 + 1;
      do {
        *piVar7 = *piVar4;
        piVar4 = piVar4 + -1;
        piVar7 = piVar7 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    if (iVar6 != 0) {
      *(int *)(param_1 + 0xe0 + iVar3 * 4) = iVar6;
      iVar3 = iVar3 + 1;
    }
    if (0 < local_3c[0]) {
      piVar7 = local_1c;
      piVar4 = (int *)(param_1 + 0xe0 + iVar3 * 4);
      for (; local_3c[0] != 0; local_3c[0] = local_3c[0] + -1) {
        *piVar4 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar4 = piVar4 + 1;
      }
    }
  }
  return;
}


// ==== 0x4a3ba0 HudWrongWay::HudWrongWay

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

int HudWrongWay__HudWrongWay(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00687e78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0x4000;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  local_4 = 0;
  FEng__HashName();
  uVar1 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  FEng__HashName();
  uVar1 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  FEng__HashName();
  uVar1 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  *(undefined1 *)(param_1 + 0x2d) = 0;
  FEObject__SetInvisible(*(undefined4 *)(param_1 + 0x20));
  FEObject__SetInvisible(*(undefined4 *)(param_1 + 0x24));
  FEObject__SetInvisible(*(undefined4 *)(param_1 + 0x28));
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4a3c60 HudWrongWay::Update

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void HudWrongWay__Update(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  char cVar3;
  char cVar4;
  bool bVar5;
  float10 fVar6;
  
  if ((*(uint *)(param_1 + 0x18) & *(uint *)(param_1 + 0x10)) == 0 &&
      (*(uint *)(param_1 + 0x1c) & *(uint *)(param_1 + 0x14)) == 0) {
    return;
  }
  cVar4 = *(char *)(param_2 + 0x4ac);
  cVar3 = FUN_0043a2e0();
  if (cVar3 == '\0') {
    FEObject__SetInvisible();
    iVar1 = *(int *)(param_1 + 0x20);
    if (iVar1 != 0) {
      *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
      puVar2 = DAT_00735710;
      bVar5 = DAT_00735710 != (undefined4 *)0x0;
      *(undefined4 *)(iVar1 + 0x5c) = 0x49a8afc;
      if (bVar5) {
        (**(code **)*puVar2)();
      }
      *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffd | 0x400000;
    }
  }
  else {
    FUN_00439a50();
    if (0 < param_1) {
      fVar6 = (float10)FEString__SetLabelHash();
      FEObject__SetFormattedText("%1.1f",(double)fVar6);
      FEObject__SetVisible(*(undefined4 *)(param_1 + 0x28));
      goto LAB_004a3d3d;
    }
    FEObject__SetInvisible();
  }
  if (cVar4 == '\0') {
    FEObject__SetInvisible();
    if ((*(char *)(param_1 + 0x2c) != '\0') && (cVar4 = FUN_004f6ce0(), cVar4 == '\0')) {
      FEObject__SetScript("FadeOut",1);
      *(undefined1 *)(param_1 + 0x2c) = 0;
    }
    if ((*(char *)(param_1 + 0x2d) != '\0') && (cVar4 = FUN_004f6ce0(), cVar4 == '\0')) {
      FEObject__SetScript("FadeOut",1);
      *(undefined1 *)(param_1 + 0x2d) = 0;
    }
    if (*(char *)(param_1 + 0x2c) != '\0') {
      return;
    }
    cVar4 = FUN_004f6ce0();
    if (cVar4 == '\0') {
      FEObject__SetInvisible();
    }
    if (*(char *)(param_1 + 0x2c) != '\0') {
      return;
    }
    cVar4 = FUN_004f6ce0();
    if (cVar4 != '\0') {
      return;
    }
    FEObject__SetInvisible();
    return;
  }
LAB_004a3d3d:
  if ((*(char *)(param_1 + 0x2c) == '\0') && (cVar4 = FUN_004f6ce0(), cVar4 == '\0')) {
    FEObject__SetVisible();
    FEObject__SetScript("FadeIn",1);
    *(undefined1 *)(param_1 + 0x2c) = 1;
  }
  if ((*(char *)(param_1 + 0x2d) == '\0') && (cVar4 = FUN_004f6ce0(), cVar4 == '\0')) {
    FEObject__SetVisible();
    FEObject__SetScript("FadeIn",1);
    *(undefined1 *)(param_1 + 0x2d) = 1;
  }
  if (((*(char *)(param_1 + 0x2c) != '\0') && (cVar4 = FUN_004f6ce0(), cVar4 == '\0')) &&
     (cVar4 = FUN_004f6ce0(), cVar4 == '\0')) {
    FEObject__SetScript("Blink",1);
  }
  if (((*(char *)(param_1 + 0x2d) != '\0') && (cVar4 = FUN_004f6ce0(), cVar4 == '\0')) &&
     (cVar4 = FUN_004f6ce0(), cVar4 == '\0')) {
    FEObject__SetScript("Blink",1);
    return;
  }
  return;
}


// ==== 0x4a3f00 HudTachDrag::HudTachDrag

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

int HudTachDrag__HudTachDrag(int param_1,int *param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  undefined4 *puVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  byte *pbVar9;
  undefined *puVar10;
  char *pcVar11;
  int iVar12;
  int *piVar13;
  int local_44;
  int local_40;
  undefined **local_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  byte local_2c;
  byte local_2b [31];
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_00687da8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(int **)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0x10000060;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  local_4 = 0;
  *(undefined1 *)(param_1 + 0xa0) = 0;
  uVar5 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar5);
  uVar5 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar5);
  uVar5 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar5);
  FEng__HashName();
  uVar5 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x34) = uVar5;
  FEng__HashName();
  uVar5 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x2c) = uVar5;
  FEng__HashName();
  uVar5 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x28) = uVar5;
  FEng__HashName();
  uVar5 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x20) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x6c) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x70) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x74) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x78) = uVar5;
  if (DAT_0078a320 < 2) {
    FEng__HashName();
    uVar5 = HudElement__RegisterImage();
    *(undefined4 *)(param_1 + 0x30) = uVar5;
  }
  else {
    FEng__HashName();
    uVar5 = HudElement__RegisterImage();
    *(undefined4 *)(param_1 + 0x30) = uVar5;
    FEng__HashName();
    HudElement__RegisterImage();
  }
  local_44 = 0;
  param_2 = (int *)(param_1 + 0x38);
  do {
    local_44 = local_44 + 1;
    bSPrintf_regdst(0x20,"RPM_%d",local_44);
    iVar12 = -1;
    pbVar9 = &local_2c;
    bVar4 = local_2c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      pbVar1 = pbVar9 + 1;
      iVar12 = iVar12 * 0x21 + (uint)bVar4;
      pbVar9 = pbVar9 + 1;
      bVar4 = *pbVar1;
    }
    if (*(int *)(param_1 + 8) == 0) goto LAB_004a4160;
    iVar6 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) goto LAB_004a4128;
    if (DAT_0073578c == 0) {
LAB_004a4204:
      iVar6 = 0;
    }
    else {
      iVar7 = *(int *)(DAT_0073578c + 8);
      if (iVar7 == 0) {
LAB_004a4160:
        if (DAT_0073578c == 0) goto LAB_004a4204;
        iVar6 = FUN_004ef050(iVar12);
      }
      else {
        FUN_004ee660();
        iVar6 = FUN_004fd1e0(iVar7 + 0xdc);
        if (iVar6 == 0) {
          FUN_004ee660();
          iVar6 = FUN_004fd1e0(iVar7 + 0xec);
          if (iVar6 == 0) goto LAB_004a4160;
        }
LAB_004a4128:
        local_3c = &PTR_FUN_006c1800;
        local_4._0_1_ = 1;
        local_34 = 0;
        local_38 = iVar12;
        FUN_004ffb00(iVar6);
        local_4 = (uint)local_4._1_3_ << 8;
        local_3c = &PTR_FUN_006c2c5c;
        iVar6 = local_34;
        if (local_34 == 0) goto LAB_004a4160;
      }
      if ((iVar6 == 0) || (*(int *)(iVar6 + 0x18) != 1)) goto LAB_004a4204;
      if (DAT_007349b4 == 0) {
        FUN_005649f0();
      }
      iVar12 = DAT_007349b4;
      piVar13 = (int *)(DAT_007349b4 + 0x10);
      if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
        FUN_00566e60();
      }
      piVar8 = (int *)*piVar13;
      iVar7 = *(int *)(iVar12 + 0x18) + 1;
      if (piVar8 == (int *)0x0) {
        piVar8 = (int *)0x0;
      }
      else {
        iVar2 = *piVar8;
        if (*(int *)(iVar12 + 0x1c) < iVar7) {
          *(int *)(iVar12 + 0x1c) = iVar7;
        }
        *(int *)(iVar12 + 0x18) = iVar7;
        bVar4 = *(byte *)(iVar12 + 0x14);
        *piVar13 = iVar2;
        if (((bVar4 & 2) != 0) &&
           (iVar12 = *(int *)(iVar12 + 0x28) >> 2, piVar13 = piVar8, 0 < iVar12)) {
          for (; iVar12 != 0; iVar12 = iVar12 + -1) {
            *piVar13 = 0;
            piVar13 = piVar13 + 1;
          }
        }
        piVar8[2] = iVar6;
      }
      puVar3 = *(undefined4 **)(param_1 + 4);
      *puVar3 = piVar8;
      *(int **)(param_1 + 4) = piVar8;
      piVar8[1] = (int)puVar3;
      *piVar8 = param_1;
    }
    *param_2 = iVar6;
    param_2 = param_2 + 1;
  } while (local_44 < 10);
  puVar10 = &DAT_006c744c;
  iVar12 = -1;
  bVar4 = 0x52;
  do {
    if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
      bVar4 = bVar4 - 0x20;
    }
    iVar12 = iVar12 * 0x21 + (uint)bVar4;
    bVar4 = puVar10[1];
    puVar10 = puVar10 + 1;
  } while (bVar4 != 0);
  if (*(int *)(param_1 + 8) == 0) goto LAB_004a4302;
  iVar6 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) goto LAB_004a42ca;
  if (DAT_0073578c == 0) {
LAB_004a43a6:
    iVar6 = 0;
  }
  else {
    iVar7 = *(int *)(DAT_0073578c + 8);
    if (iVar7 == 0) {
LAB_004a4302:
      if (DAT_0073578c == 0) goto LAB_004a43a6;
      iVar6 = FUN_004ef050(iVar12);
    }
    else {
      FUN_004ee660();
      iVar6 = FUN_004fd1e0(iVar7 + 0xdc);
      if (iVar6 == 0) {
        FUN_004ee660();
        iVar6 = FUN_004fd1e0(iVar7 + 0xec);
        if (iVar6 == 0) goto LAB_004a4302;
      }
LAB_004a42ca:
      local_3c = &PTR_FUN_006c1800;
      local_4._0_1_ = 2;
      local_34 = 0;
      local_38 = iVar12;
      FUN_004ffb00(iVar6);
      local_4 = (uint)local_4._1_3_ << 8;
      local_3c = &PTR_FUN_006c2c5c;
      iVar6 = local_34;
      if (local_34 == 0) goto LAB_004a4302;
    }
    if ((iVar6 == 0) || (*(int *)(iVar6 + 0x18) != 1)) goto LAB_004a43a6;
    if (DAT_007349b4 == 0) {
      FUN_005649f0();
    }
    iVar12 = DAT_007349b4;
    piVar13 = (int *)(DAT_007349b4 + 0x10);
    if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
      FUN_00566e60();
    }
    piVar8 = (int *)*piVar13;
    iVar7 = *(int *)(iVar12 + 0x18) + 1;
    if (piVar8 == (int *)0x0) {
      piVar8 = (int *)0x0;
    }
    else {
      iVar2 = *piVar8;
      if (*(int *)(iVar12 + 0x1c) < iVar7) {
        *(int *)(iVar12 + 0x1c) = iVar7;
      }
      *(int *)(iVar12 + 0x18) = iVar7;
      bVar4 = *(byte *)(iVar12 + 0x14);
      *piVar13 = iVar2;
      if (((bVar4 & 2) != 0) &&
         (iVar12 = *(int *)(iVar12 + 0x28) >> 2, piVar13 = piVar8, 0 < iVar12)) {
        for (; iVar12 != 0; iVar12 = iVar12 + -1) {
          *piVar13 = 0;
          piVar13 = piVar13 + 1;
        }
      }
      piVar8[2] = iVar6;
    }
    puVar3 = *(undefined4 **)(param_1 + 4);
    *puVar3 = piVar8;
    *(int **)(param_1 + 4) = piVar8;
    piVar8[1] = (int)puVar3;
    *piVar8 = param_1;
  }
  *(int *)(param_1 + 0x60) = iVar6;
  pcVar11 = "RPM45Corner_Left";
  iVar12 = -1;
  bVar4 = 0x52;
  do {
    if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
      bVar4 = bVar4 - 0x20;
    }
    iVar12 = iVar12 * 0x21 + (uint)bVar4;
    bVar4 = pcVar11[1];
    pcVar11 = pcVar11 + 1;
  } while (bVar4 != 0);
  if (*(int *)(param_1 + 8) == 0) goto LAB_004a4492;
  iVar6 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) goto LAB_004a445a;
  if (DAT_0073578c == 0) {
LAB_004a4536:
    iVar6 = 0;
  }
  else {
    iVar7 = *(int *)(DAT_0073578c + 8);
    if (iVar7 == 0) {
LAB_004a4492:
      if (DAT_0073578c == 0) goto LAB_004a4536;
      iVar6 = FUN_004ef050(iVar12);
    }
    else {
      FUN_004ee660();
      iVar6 = FUN_004fd1e0(iVar7 + 0xdc);
      if (iVar6 == 0) {
        FUN_004ee660();
        iVar6 = FUN_004fd1e0(iVar7 + 0xec);
        if (iVar6 == 0) goto LAB_004a4492;
      }
LAB_004a445a:
      local_3c = &PTR_FUN_006c1800;
      local_4._0_1_ = 3;
      local_34 = 0;
      local_38 = iVar12;
      FUN_004ffb00(iVar6);
      local_4 = (uint)local_4._1_3_ << 8;
      local_3c = &PTR_FUN_006c2c5c;
      iVar6 = local_34;
      if (local_34 == 0) goto LAB_004a4492;
    }
    if ((iVar6 == 0) || (*(int *)(iVar6 + 0x18) != 1)) goto LAB_004a4536;
    if (DAT_007349b4 == 0) {
      FUN_005649f0();
    }
    iVar12 = DAT_007349b4;
    piVar13 = (int *)(DAT_007349b4 + 0x10);
    if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
      FUN_00566e60();
    }
    piVar8 = (int *)*piVar13;
    iVar7 = *(int *)(iVar12 + 0x18) + 1;
    if (piVar8 == (int *)0x0) {
      piVar8 = (int *)0x0;
    }
    else {
      iVar2 = *piVar8;
      if (*(int *)(iVar12 + 0x1c) < iVar7) {
        *(int *)(iVar12 + 0x1c) = iVar7;
      }
      *(int *)(iVar12 + 0x18) = iVar7;
      bVar4 = *(byte *)(iVar12 + 0x14);
      *piVar13 = iVar2;
      if (((bVar4 & 2) != 0) &&
         (iVar12 = *(int *)(iVar12 + 0x28) >> 2, piVar13 = piVar8, 0 < iVar12)) {
        for (; iVar12 != 0; iVar12 = iVar12 + -1) {
          *piVar13 = 0;
          piVar13 = piVar13 + 1;
        }
      }
      piVar8[2] = iVar6;
    }
    puVar3 = *(undefined4 **)(param_1 + 4);
    *puVar3 = piVar8;
    *(int **)(param_1 + 4) = piVar8;
    piVar8[1] = (int)puVar3;
    *piVar8 = param_1;
  }
  *(int *)(param_1 + 100) = iVar6;
  pcVar11 = "RPM45Corner_Right";
  iVar12 = -1;
  bVar4 = 0x52;
  do {
    if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
      bVar4 = bVar4 - 0x20;
    }
    iVar12 = iVar12 * 0x21 + (uint)bVar4;
    bVar4 = pcVar11[1];
    pcVar11 = pcVar11 + 1;
  } while (bVar4 != 0);
  if (*(int *)(param_1 + 8) == 0) goto LAB_004a4622;
  iVar6 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) goto LAB_004a45ea;
  if (DAT_0073578c != 0) {
    iVar7 = *(int *)(DAT_0073578c + 8);
    if (iVar7 == 0) {
LAB_004a4622:
      if (DAT_0073578c == 0) goto LAB_004a4642;
      iVar6 = FUN_004ef050(iVar12);
    }
    else {
      FUN_004ee660();
      iVar6 = FUN_004fd1e0(iVar7 + 0xdc);
      if (iVar6 == 0) {
        FUN_004ee660();
        iVar6 = FUN_004fd1e0(iVar7 + 0xec);
        if (iVar6 == 0) goto LAB_004a4622;
      }
LAB_004a45ea:
      local_3c = &PTR_FUN_006c1800;
      local_4._0_1_ = 4;
      local_34 = 0;
      local_38 = iVar12;
      FUN_004ffb00(iVar6);
      local_4 = (uint)local_4._1_3_ << 8;
      local_3c = &PTR_FUN_006c2c5c;
      iVar6 = local_34;
      if (local_34 == 0) goto LAB_004a4622;
    }
    if ((iVar6 != 0) && (*(int *)(iVar6 + 0x18) == 1)) {
      if (DAT_007349b4 == 0) {
        FUN_005649f0();
      }
      iVar12 = DAT_007349b4;
      piVar13 = (int *)(DAT_007349b4 + 0x10);
      if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
        FUN_00566e60();
      }
      piVar8 = (int *)*piVar13;
      iVar7 = *(int *)(iVar12 + 0x18) + 1;
      if (piVar8 == (int *)0x0) {
        piVar8 = (int *)0x0;
      }
      else {
        iVar2 = *piVar8;
        if (*(int *)(iVar12 + 0x1c) < iVar7) {
          *(int *)(iVar12 + 0x1c) = iVar7;
        }
        *(int *)(iVar12 + 0x18) = iVar7;
        bVar4 = *(byte *)(iVar12 + 0x14);
        *piVar13 = iVar2;
        if (((bVar4 & 2) != 0) &&
           (iVar12 = *(int *)(iVar12 + 0x28) >> 2, piVar13 = piVar8, 0 < iVar12)) {
          for (; iVar12 != 0; iVar12 = iVar12 + -1) {
            *piVar13 = 0;
            piVar13 = piVar13 + 1;
          }
        }
        piVar8[2] = iVar6;
      }
      puVar3 = *(undefined4 **)(param_1 + 4);
      *puVar3 = piVar8;
      *(int **)(param_1 + 4) = piVar8;
      piVar8[1] = (int)puVar3;
      *piVar8 = param_1;
      goto LAB_004a46d6;
    }
  }
LAB_004a4642:
  iVar6 = 0;
LAB_004a46d6:
  *(int *)(param_1 + 0x68) = iVar6;
  if ((int)(&DAT_0078a410)[param_3] < 0) {
    iVar12 = 0;
  }
  else {
    iVar12 = 0;
    if (0 < DAT_0078a41c) {
      pcVar11 = (char *)(DAT_0078a418 + 1);
      do {
        if ((&DAT_0078a410)[param_3] == (int)*pcVar11) {
          iVar12 = iVar12 * 0x750 + DAT_0078a418;
          goto LAB_004a4726;
        }
        iVar12 = iVar12 + 1;
        pcVar11 = pcVar11 + 0x750;
      } while (iVar12 < DAT_0078a41c);
    }
    iVar12 = 0;
  }
LAB_004a4726:
  if (*(char *)(iVar12 + 0x434) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  if ((iVar12 != 0) && (iVar12 != -0x260)) {
    HudTach_PickFaceHashes(*(undefined4 *)(iVar12 + 0x10),(int)DAT_0078a3f5,&local_44);
    iVar12 = local_44;
    iVar6 = Texture_FindByHash(local_44,0,0);
    if (iVar6 == 0) {
      *(undefined1 *)(param_1 + 0xa0) = 1;
    }
    else {
      iVar6 = *(int *)(param_1 + 0x2c);
      if ((iVar6 != 0) && (*(int *)(iVar6 + 0x24) != iVar12)) {
        *(int *)(iVar6 + 0x24) = iVar12;
        *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) | 0x400000;
      }
    }
    iVar12 = *(int *)(param_1 + 0x28);
    if ((iVar12 != 0) && (*(int *)(iVar12 + 0x24) != local_40)) {
      *(int *)(iVar12 + 0x24) = local_40;
      *(uint *)(iVar12 + 0x1c) = *(uint *)(iVar12 + 0x1c) | 0x400000;
    }
  }
  local_34 = 0;
  *(undefined4 *)(param_1 + 0x80) = 1;
  *(undefined4 *)(param_1 + 0x7c) = 1;
  *(undefined1 *)(param_1 + 0x84) = 0;
  *(undefined1 *)(param_1 + 0x85) = 0;
  *(undefined1 *)(param_1 + 0x86) = 0;
  *(undefined1 *)(param_1 + 0x87) = 0;
  *(undefined1 *)(param_1 + 0x88) = 0;
  *(undefined1 *)(param_1 + 0x89) = 0;
  *(undefined1 *)(param_1 + 0x8a) = 0;
  if (*(int *)(param_1 + 0x6c) == 0) {
    local_30 = 0;
    local_38 = 0;
    local_3c = (undefined **)0x0;
  }
  else {
    puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x6c) + 0x2c);
    local_38 = puVar3[1];
    local_3c = (undefined **)*puVar3;
    local_30 = puVar3[3];
    local_34 = puVar3[2];
  }
  uVar5 = FEColor__operator_unsigned_long();
  *(undefined4 *)(param_1 + 0x94) = uVar5;
  if (*(int *)(param_1 + 0x20) == 0) {
    local_30 = 0;
    local_34 = 0;
    local_38 = 0;
    local_3c = (undefined **)0x0;
  }
  else {
    puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x20) + 0x2c);
    local_3c = (undefined **)*puVar3;
    local_38 = puVar3[1];
    local_34 = puVar3[2];
    local_30 = puVar3[3];
  }
  uVar5 = FEColor__operator_unsigned_long();
  *(undefined4 *)(param_1 + 0x98) = uVar5;
  if (*(int *)(param_1 + 0x60) == 0) {
    local_30 = 0;
    local_34 = 0;
    local_38 = 0;
    local_3c = (undefined **)0x0;
  }
  else {
    puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x60) + 0x2c);
    local_3c = (undefined **)*puVar3;
    local_38 = puVar3[1];
    local_34 = puVar3[2];
    local_30 = puVar3[3];
  }
  uVar5 = FEColor__operator_unsigned_long();
  *(undefined4 *)(param_1 + 0x9c) = uVar5;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined1 *)(param_1 + 0xa1) = 1;
  *(undefined1 *)(param_1 + 0xa2) = 1;
  HudWidget__SetVisible(0,0);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4a4900 FUN_004a4900

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004a4900(float *param_1,float *param_2,undefined4 param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float *in_EAX;
  
  *param_1 = (*param_2 - *in_EAX) * param_4 + *in_EAX;
  param_1[1] = (param_2[1] - in_EAX[1]) * param_4 + in_EAX[1];
  param_1[2] = (param_2[2] - in_EAX[2]) * param_4 + in_EAX[2];
  fVar1 = *param_1;
  param_1[3] = (param_2[3] - in_EAX[3]) * param_4 + in_EAX[3];
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
  }
  else if (K_BLUR_MIN_T < fVar1) {
    fVar1 = K_BLUR_MIN_T;
  }
  fVar2 = param_1[1];
  *param_1 = fVar1;
  if (fVar2 <= 0.0) {
    fVar2 = 0.0;
  }
  else if (K_BLUR_MIN_T < fVar2) {
    fVar2 = K_BLUR_MIN_T;
  }
  fVar1 = param_1[2];
  param_1[1] = fVar2;
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
  }
  else if (K_BLUR_MIN_T < fVar1) {
    fVar1 = K_BLUR_MIN_T;
  }
  fVar2 = param_1[3];
  param_1[2] = fVar1;
  if (fVar2 <= 0.0) {
    fVar2 = 0.0;
  }
  else if (K_BLUR_MIN_T < fVar2) {
    param_1[3] = 255.0;
    return;
  }
  param_1[3] = fVar2;
  return;
}


// ==== 0x4a4a50 HudTachDrag::Update

/* WARNING: Removing unreachable block (ram,0x004a5601) */
/* WARNING: Removing unreachable block (ram,0x004a556a) */
/* WARNING: Removing unreachable block (ram,0x004a55c0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void HudTachDrag__Update(float param_1,int param_2)

{
  float fVar1;
  float fVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  bool bVar10;
  int iVar11;
  char cVar12;
  int iVar13;
  undefined4 uVar14;
  char *pcVar15;
  uint uVar16;
  float10 fVar17;
  int local_34;
  float local_30;
  float local_2c;
  uint local_28;
  uint local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar11 = (int)param_1;
  local_34 = *(int *)(param_2 + 4);
  if (((DAT_006fbf14 == 0) && (*(int *)(param_2 + 0x10) == 0)) &&
     (iVar13 = RaceManager__FindRacerById(), iVar13 != 0)) {
    local_34 = iVar13;
  }
  *(undefined4 *)((int)param_1 + 0x80) = *(undefined4 *)(local_34 + 0x3d8);
  if ((*(int *)(local_34 + 0x28) == 1) &&
     (iVar13 = *(int *)(*(int *)(local_34 + 0x34) + 0x4c), *(int *)(iVar13 + 0x48) != 0)) {
    if (*(char *)((int)param_1 + 0x88) == '\0') {
      *(undefined4 *)((int)param_1 + 0x8c) = *(undefined4 *)(iVar13 + 0x6c);
      *(undefined1 *)((int)param_1 + 0x88) = 1;
    }
  }
  else {
    *(undefined1 *)((int)param_1 + 0x88) = 0;
  }
  if (DAT_007000e4 == 100.0) {
    param_1 = *(float *)(local_34 + 0x3e0);
  }
  else {
    param_1 = DAT_007000e4;
  }
  if ((*(uint *)(iVar11 + 0x18) & *(uint *)(iVar11 + 0x10)) == 0 &&
      (*(uint *)(iVar11 + 0x1c) & *(uint *)(iVar11 + 0x14)) == 0) goto LAB_004a5799;
  if (DAT_0078a3f5 == '\x01') {
    local_2c = 3.6;
  }
  else {
    local_2c = 2.237;
  }
  local_2c = *(float *)(local_34 + 0x3d4) * local_2c;
  iVar13 = LanguageStrings__FindByHash();
  if (iVar13 == 0) {
    iVar13 = LanguageStrings__FindByHash();
  }
  FEObject__SetFormattedText(iVar13);
  uVar14 = _ftol_nocw();
  FEObject__SetFormattedText(&DAT_006c740c,uVar14);
  iVar13 = *(int *)(local_34 + 0x20);
  if (DAT_0078a320 == 1) {
    fVar17 = (float10)DragTachometer__CalcAngleForRPMDrag(iVar11,param_1);
    FUN_004f6a70((float)fVar17);
  }
  else {
    FUN_004f6d10(&local_30,&local_28);
    FUN_004f7350(&local_2c,&local_28);
    local_2c = local_2c + local_30;
    local_30 = ((251.0 - local_2c) / *(float *)(iVar13 + 500)) * param_1;
    if (280.0 < local_30) {
      local_30 = 280.0;
    }
    FUN_00496040(local_30);
    FUN_004f6d10(&local_24,&local_28);
    FUN_004f7000(local_2c,local_28);
    FUN_004f6d10(&local_24,&local_28);
    FUN_004f7000(local_30 + local_2c,local_28);
  }
  if (*(int *)(local_34 + 0x28) == 1) {
    local_30 = *(float *)(*(int *)(*(int *)(local_34 + 0x34) + 0x4c) + 0x68);
    if (((0.0 <= local_30) || (*(char *)(iVar11 + 0x87) != '\0')) ||
       (param_1 <= *(float *)(*(int *)(local_34 + 0x20) + 500))) goto LAB_004a4d00;
    if (*(char *)(iVar11 + 0x8a) == '\0') {
      *(undefined4 *)(iVar11 + 0x90) = DAT_0073ad3c;
      *(undefined1 *)(iVar11 + 0x8a) = 1;
    }
    if (*(char *)(iVar11 + 0x89) == '\0') {
      FEObject__SetScript("Blink",1);
      *(undefined1 *)(iVar11 + 0x89) = 1;
    }
  }
  else {
    local_30 = 0.0;
LAB_004a4d00:
    if (*(char *)(iVar11 + 0x89) != '\0') {
      FEObject__SetScript(&DAT_006c7a3c,1);
      *(undefined1 *)(iVar11 + 0x89) = 0;
      *(undefined1 *)(iVar11 + 0x8a) = 0;
    }
  }
  if (*(int *)(iVar11 + 0x6c) != 0) {
    iVar13 = *(int *)(local_34 + 1000);
    uVar16 = 0;
    do {
      if (*(int *)(iVar11 + 0x80) == (int)(char)(&DAT_006fb7b0)[uVar16 * 2]) {
        cVar12 = *(char *)(uVar16 * 2 + 0x6fb7b1);
        goto LAB_004a4d54;
      }
      uVar16 = uVar16 + 1;
    } while (uVar16 < 10);
    cVar12 = 'X';
LAB_004a4d54:
    FEObject__SetFormattedText(&DAT_006c7408,(int)cVar12);
    if (iVar13 == 0) {
      uVar14 = 0xffff8000;
    }
    else {
      uVar14 = *(undefined4 *)(iVar11 + 0x94);
    }
    FUN_004f75b0(uVar14);
  }
  if ((local_30 <= 0.0) || (local_30 < _K_ONE == (local_30 == _K_ONE))) {
LAB_004a4e5d:
    if (*(char *)(iVar11 + 0x84) != '\0') {
LAB_004a4e67:
      iVar13 = *(int *)(iVar11 + 0x70);
      if ((iVar13 != 0) && (iVar6 = *(int *)(iVar13 + 0x54), iVar6 != 0)) {
        pcVar15 = "ZoomIn";
        do {
          cVar12 = pcVar15[*(int *)(iVar6 + 0x2c) + -0x6c7188];
          cVar3 = *pcVar15;
          pcVar15 = pcVar15 + 1;
          if ((cVar12 == '\0') || (cVar3 == '\0')) break;
        } while (cVar12 == cVar3);
        if ((cVar12 == cVar3) && (*(int *)(iVar6 + 0x10) <= *(int *)(iVar6 + 0xc)))
        goto LAB_004a4ec5;
      }
      if ((*(int *)(param_2 + 0x60) != 6) && (*(int *)(param_2 + 0x60) != 7)) {
        *(undefined1 *)(iVar11 + 0x84) = 0;
      }
      FEObject__SetInvisible(iVar13);
    }
  }
  else {
    if (*(char *)(iVar11 + 0x84) != '\0') goto LAB_004a4e67;
    if (*(int *)(local_34 + 0x3d8) == *(int *)(iVar11 + 0x7c)) goto LAB_004a4e5d;
    if (local_30 < _K_HALF == (local_30 == _K_HALF)) {
      FEString__SetLabelHash();
      if (((((DAT_00777b4c == 1) && (DAT_0073619c != (int *)0x0)) && (*DAT_0073619c == 4)) &&
          ((*(char *)(iVar11 + 0xa1) == '\0' && (1 < *(int *)(local_34 + 0x3d8))))) &&
         (*(char *)(iVar11 + 0xa2) == '\x01')) {
        *(undefined1 *)(iVar11 + 0xa2) = 0;
      }
    }
    else {
      FEString__SetLabelHash();
    }
    FEObject__SetScript("ZoomIn",1);
    FEObject__SetVisible(*(undefined4 *)(iVar11 + 0x70));
    *(undefined1 *)(iVar11 + 0x84) = 1;
  }
LAB_004a4ec5:
  if ((*(int *)(local_34 + 0x28) != 1) ||
     (*(float *)(*(int *)(*(int *)(local_34 + 0x34) + 0x4c) + 0x5c) <= 0.0)) {
    if (*(char *)(iVar11 + 0x85) == '\0') goto LAB_004a4ffd;
LAB_004a4f9b:
    iVar13 = *(int *)(iVar11 + 0x70);
    if ((iVar13 != 0) && (iVar6 = *(int *)(iVar13 + 0x54), iVar6 != 0)) {
      pcVar15 = "ZoomIn";
      do {
        cVar12 = pcVar15[*(int *)(iVar6 + 0x2c) + -0x6c7188];
        cVar3 = *pcVar15;
        pcVar15 = pcVar15 + 1;
        if ((cVar12 == '\0') || (cVar3 == '\0')) break;
      } while (cVar12 == cVar3);
      if ((cVar12 == cVar3) && (*(int *)(iVar6 + 0x10) <= *(int *)(iVar6 + 0xc))) goto LAB_004a4ffd;
    }
    if ((*(int *)(param_2 + 0x60) != 6) && (*(int *)(param_2 + 0x60) != 7)) {
      *(undefined1 *)(iVar11 + 0x85) = 0;
    }
    FEObject__SetInvisible(iVar13);
LAB_004a4ffd:
    if (((*DAT_0073619c != 4) || (*(int *)(iVar11 + 0x80) <= *(int *)(iVar11 + 0x7c))) ||
       ((*(int *)(iVar11 + 0x7c) == 0 ||
        ((*(char *)(iVar11 + 0x84) != '\0' || (*(char *)(iVar11 + 0x85) != '\0'))))))
    goto LAB_004a5128;
    if ((local_30 == 0.0) && (*(char *)(iVar11 + 0x86) == '\0')) {
      FEString__SetLabelHash();
      FEObject__SetScript("ZoomIn",1);
      FEObject__SetVisible(*(undefined4 *)(iVar11 + 0x70));
      *(undefined1 *)(iVar11 + 0x86) = 1;
    }
    else if ((local_30 < 0.0) && (*(char *)(iVar11 + 0x87) == '\0')) {
      FEString__SetLabelHash();
      FEObject__SetScript("ZoomIn",1);
      FEObject__SetVisible(*(undefined4 *)(iVar11 + 0x70));
      *(undefined1 *)(iVar11 + 0x87) = 1;
    }
    if ((((DAT_00777b4c == 1) && (DAT_0073619c != (int *)0x0)) && (*DAT_0073619c == 4)) &&
       (((*(char *)(iVar11 + 0xa1) == '\0' && (1 < *(int *)(local_34 + 0x3d8))) &&
        (*(char *)(iVar11 + 0xa2) == '\x01')))) {
      *(undefined1 *)(iVar11 + 0xa2) = 0;
    }
  }
  else {
    if (*(char *)(iVar11 + 0x85) != '\0') goto LAB_004a4f9b;
    FEString__SetLabelHash();
    FEObject__SetScript("ZoomIn",1);
    FEObject__SetVisible(*(undefined4 *)(iVar11 + 0x70));
    *(undefined1 *)(iVar11 + 0x85) = 1;
    if ((DAT_00777b4c != 1) || (DAT_0073619c == (int *)0x0)) goto LAB_004a4ffd;
    if (*DAT_0073619c == 4) {
      if (((*(char *)(iVar11 + 0xa1) == '\0') && (1 < *(int *)(local_34 + 0x3d8))) &&
         (*(char *)(iVar11 + 0xa2) == '\x01')) {
        *(undefined1 *)(iVar11 + 0xa2) = 0;
      }
      goto LAB_004a4ffd;
    }
LAB_004a5128:
    if (*(char *)(iVar11 + 0x86) != '\0') {
      iVar13 = *(int *)(iVar11 + 0x70);
      if ((iVar13 != 0) && (iVar6 = *(int *)(iVar13 + 0x54), iVar6 != 0)) {
        pcVar15 = "ZoomIn";
        do {
          cVar12 = pcVar15[*(int *)(iVar6 + 0x2c) + -0x6c7188];
          cVar3 = *pcVar15;
          pcVar15 = pcVar15 + 1;
          if ((cVar12 == '\0') || (cVar3 == '\0')) break;
        } while (cVar12 == cVar3);
        if ((cVar12 == cVar3) && (*(int *)(iVar6 + 0x10) <= *(int *)(iVar6 + 0xc)))
        goto LAB_004a5195;
      }
      if ((*(int *)(param_2 + 0x60) != 6) && (*(int *)(param_2 + 0x60) != 7)) {
        *(undefined1 *)(iVar11 + 0x86) = 0;
      }
      FEObject__SetInvisible(iVar13);
    }
LAB_004a5195:
    if (*(char *)(iVar11 + 0x87) != '\0') {
      iVar13 = *(int *)(iVar11 + 0x70);
      if ((iVar13 != 0) && (iVar6 = *(int *)(iVar13 + 0x54), iVar6 != 0)) {
        pcVar15 = "ZoomIn";
        do {
          cVar12 = pcVar15[*(int *)(iVar6 + 0x2c) + -0x6c7188];
          cVar3 = *pcVar15;
          pcVar15 = pcVar15 + 1;
          if ((cVar12 == '\0') || (cVar3 == '\0')) break;
        } while (cVar12 == cVar3);
        if ((cVar12 == cVar3) && (*(int *)(iVar6 + 0x10) <= *(int *)(iVar6 + 0xc)))
        goto LAB_004a51fc;
      }
      if ((*(int *)(param_2 + 0x60) != 6) && (*(int *)(param_2 + 0x60) != 7)) {
        *(undefined1 *)(iVar11 + 0x87) = 0;
      }
      FEObject__SetInvisible(iVar13);
    }
  }
LAB_004a51fc:
  iVar13 = *(int *)(local_34 + 0x10);
  if (*(char *)(iVar13 + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  iVar6 = *(int *)(iVar11 + 0x7c);
  iVar7 = *(int *)(local_34 + 0x28);
  fVar1 = *(float *)(&DAT_006fff60 + (iVar6 + *(char *)(iVar13 + 0x424) * 9) * 4);
  if (iVar7 == 1) {
    iVar13 = *(int *)(*(int *)(local_34 + 0x34) + 0x4c);
    iVar8 = *(int *)(iVar13 + 0xe0);
    fVar1 = *(float *)(&DAT_006fff60 + (iVar8 + iVar6 + iVar8 * 8) * 4) * *(float *)(iVar13 + 0xd8);
    local_2c = *(float *)(*(int *)(*(int *)(local_34 + 0x34) + 0x4c) + 0x80 + iVar6 * 4);
  }
  else if (iVar7 == 3) {
    local_2c = *(float *)(*(int *)(*(int *)(local_34 + 0x34) + 0x24) + 0x198 + iVar6 * 4);
  }
  else {
    local_2c = 0.0;
  }
  local_2c = local_2c - _DAT_006fff58 * _K_HALF * fVar1;
  local_30 = local_2c - 1500.0;
  if (iVar7 == 1) {
    fVar2 = *(float *)(*(int *)(*(int *)(local_34 + 0x34) + 0x4c) + 0x80 + iVar6 * 4);
  }
  else if (iVar7 == 3) {
    fVar2 = *(float *)(*(int *)(*(int *)(local_34 + 0x34) + 0x24) + 0x198 + iVar6 * 4);
  }
  else {
    fVar2 = 0.0;
  }
  local_10 = 0x437f0000;
  local_c = 0;
  local_8 = 0x43000000;
  local_4 = 0x43400000;
  if (local_30 <= param_1) {
    if (param_1 <= (_K_ONE - _DAT_006fff58) * fVar1 + fVar2) {
      if (param_1 <= local_2c) {
        if (*(int *)(local_34 + 0x3d8) != 0) {
          if (DAT_0078a320 == 1) {
            local_24 = *(uint *)(iVar11 + 0x98);
            bVar4 = *(byte *)(iVar11 + 0x9a);
            bVar5 = *(byte *)(iVar11 + 0x99);
          }
          else {
            local_24 = *(uint *)(iVar11 + 0x9c);
            bVar4 = *(byte *)(iVar11 + 0x9e);
            bVar5 = *(byte *)(iVar11 + 0x9d);
          }
          local_20 = (float)(local_24 >> 0x18);
          local_24 = local_24 & 0xff;
          local_28 = (uint)bVar5;
          local_18 = (float)local_28;
          local_1c = (float)bVar4;
          local_14 = (float)local_24;
          cVar12 = FUN_004f6ce0("PulseBlue");
          if (cVar12 == '\0') {
            FEObject__SetScript("PulseBlue",1);
          }
          FUN_004a4900(iVar11,(param_1 - local_30) * 0.00066666666);
          if (DAT_0078a320 == 1) {
            uVar14 = Hud_PackColorFromFloats();
          }
          else {
            uVar14 = Hud_PackColorFromFloats();
            FUN_004f75b0(uVar14);
            uVar14 = Hud_PackColorFromFloats();
            FUN_004f75b0(uVar14);
            uVar14 = Hud_PackColorFromFloats();
          }
          goto LAB_004a569c;
        }
      }
      else if (*(int *)(local_34 + 0x3d8) != 0) {
        if (DAT_0078a320 == 1) {
          FUN_004f75b0(0xff00ff00);
        }
        else {
          FUN_004f75b0(0xff00ff00);
          FUN_004f75b0(0xff00ff00);
          FUN_004f75b0(0xff00ff00);
        }
        cVar12 = FUN_004f6ce0("PulseGreen");
        if (cVar12 == '\0') {
          FEObject__SetScript("PulseGreen",1);
        }
        if ((((DAT_00777b4c == 1) && (DAT_0073619c != (int *)0x0)) && (*DAT_0073619c == 4)) &&
           ((0 < *(int *)(local_34 + 0x3d8) && (*(char *)(iVar11 + 0xa1) == '\x01')))) {
          *(undefined1 *)(iVar11 + 0xa1) = 0;
        }
      }
    }
    else if (*(int *)(local_34 + 0x3d8) == 0) {
      if (*(float *)(*(int *)(local_34 + 0x20) + 500) < param_1) {
        cVar12 = FUN_004f6ce0("PulseRed");
        if (cVar12 == '\0') {
          FEObject__SetScript("PulseRed",1);
        }
        if (DAT_0078a320 == 1) {
          uVar14 = 0xff800000;
          goto LAB_004a569c;
        }
        FUN_004f75b0(0xff802020);
        FUN_004f75b0(0xff802020);
        FUN_004f75b0(0xff802020);
      }
    }
    else {
      if (DAT_0078a320 == 1) {
        FUN_004f75b0(0xff800000);
      }
      else {
        FUN_004f75b0(0xff802020);
        FUN_004f75b0(0xff802020);
        FUN_004f75b0(0xff802020);
      }
      cVar12 = FUN_004f6ce0("PulseRed");
      if (cVar12 == '\0') {
        FEObject__SetScript("PulseRed",1);
      }
    }
  }
  else if (DAT_0078a320 == 1) {
    uVar14 = *(undefined4 *)(iVar11 + 0x98);
LAB_004a569c:
    FUN_004f75b0(uVar14);
  }
  else {
    FUN_004f75b0(*(undefined4 *)(iVar11 + 0x9c));
    FUN_004f75b0(*(undefined4 *)(iVar11 + 0x9c));
    FUN_004f75b0(*(undefined4 *)(iVar11 + 0x9c));
  }
  if ((*(char *)(param_2 + 0x23) == '\x01') || (*(char *)(param_2 + 0x23) == '\x03')) {
    bVar10 = true;
  }
  else {
    bVar10 = false;
  }
  iVar13 = *(int *)(local_34 + 0x10);
  if (*(char *)(iVar13 + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  iVar6 = *(int *)(local_34 + 0x3d8);
  fVar1 = *(float *)(&DAT_006fff60 + (iVar6 + *(char *)(iVar13 + 0x424) * 9) * 4);
  if (*(int *)(local_34 + 0x28) == 1) {
    iVar13 = *(int *)(*(int *)(local_34 + 0x34) + 0x4c);
    iVar7 = *(int *)(iVar13 + 0xe0);
    fVar1 = *(float *)(&DAT_006fff60 + (iVar7 + iVar6 + iVar7 * 8) * 4) * *(float *)(iVar13 + 0xd8);
    fVar2 = *(float *)(*(int *)(*(int *)(local_34 + 0x34) + 0x4c) + 0x80 + iVar6 * 4);
  }
  else if (*(int *)(local_34 + 0x28) == 3) {
    fVar2 = *(float *)(*(int *)(*(int *)(local_34 + 0x34) + 0x24) + 0x198 + iVar6 * 4);
  }
  else {
    fVar2 = 0.0;
  }
  fVar9 = DAT_007000e4;
  if (DAT_007000e4 == 100.0) {
    fVar9 = *(float *)(local_34 + 0x3e0);
  }
  if ((fVar9 <= fVar2 - _DAT_006fff58 * fVar1) || (!bVar10)) {
    FEObject__SetInvisible(*(undefined4 *)(iVar11 + 0x30));
  }
  else {
    FEObject__SetVisible(*(undefined4 *)(iVar11 + 0x30));
  }
LAB_004a5799:
  *(undefined4 *)(iVar11 + 0x7c) = *(undefined4 *)(iVar11 + 0x80);
  if (*(char *)(iVar11 + 0xa0) != '\0') {
    FEObject__SetInvisible(*(undefined4 *)(iVar11 + 0x2c));
    FEObject__SetInvisible(*(undefined4 *)(iVar11 + 0x28));
  }
  return;
}


// ==== 0x4a57d0 DragTachometer::CalcAngleForRPMDrag

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

float10 __thiscall DragTachometer__CalcAngleForRPMDrag(int param_1,undefined4 param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  
  fVar3 = (float10)param_3 / (float10)*(float *)(in_EAX + 8);
  if ((float10)0.0 <= fVar3) {
    if ((float10)_K_ONE < fVar3) {
      fVar3 = (float10)_K_ONE;
    }
  }
  else {
    fVar3 = (float10)0.0;
  }
  if (DAT_0078a320 == 1) {
    fVar1 = *(float *)(param_1 + 0xc);
    fVar2 = *(float *)(param_1 + 0x10);
  }
  else {
    fVar1 = *(float *)(param_1 + 4);
    fVar2 = *(float *)(param_1 + 8);
  }
  fVar5 = (float10)fVar1;
  fVar4 = (float10)fVar2;
  if (fVar4 <= fVar5) {
    fVar4 = ((float10)360.0 - fVar5) + fVar4;
  }
  else {
    fVar4 = fVar4 - fVar5;
  }
  fVar5 = fVar5 + fVar4 * fVar3;
  if ((float10)360.0 < fVar5) {
    fVar5 = fVar5 - (float10)360.0;
  }
  if (fVar5 < (float10)-360.0) {
    fVar5 = fVar5 + (float10)360.0;
  }
  return fVar5;
}


// ==== 0x4a5860 HudEngineHeat::HudEngineHeat

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

int HudEngineHeat__HudEngineHeat(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  int *piVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  byte *pbVar8;
  int iVar9;
  byte local_2c;
  byte local_2b [31];
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00687e78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0x20000000;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  local_4 = 0;
  uVar4 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar4);
  uVar4 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar4);
  FEng__HashName();
  uVar4 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x20) = uVar4;
  EngineTempGauge__BuildTempBarImageList(param_1);
  FEng__HashName();
  uVar4 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x44) = uVar4;
  FEng__HashName();
  uVar4 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x48) = uVar4;
  FEng__HashName();
  uVar4 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x4c) = uVar4;
  FEng__HashName();
  uVar4 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x50) = uVar4;
  if (DAT_0078a320 == 2) {
    iVar5 = 0;
    do {
      iVar5 = iVar5 + 1;
      bSPrintf_regdst(0x20,"back_heat_%d",iVar5);
      iVar9 = -1;
      pbVar8 = &local_2c;
      bVar3 = local_2c;
      while (bVar3 != 0) {
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 - 0x20;
        }
        pbVar1 = pbVar8 + 1;
        iVar9 = iVar9 * 0x21 + (uint)bVar3;
        pbVar8 = pbVar8 + 1;
        bVar3 = *pbVar1;
      }
      if (((*(int *)(param_1 + 8) == 0) || (iVar6 = FUN_004f65d0(), iVar6 == 0)) ||
         (iVar6 = FUN_004ffb70(), iVar6 == 0)) {
        if (DAT_0073578c != 0) {
          iVar6 = FUN_004ef050(iVar9);
          goto LAB_004a59b3;
        }
      }
      else {
LAB_004a59b3:
        if ((iVar6 != 0) && (*(int *)(iVar6 + 0x18) == 1)) {
          if (DAT_007349b4 == 0) {
            FUN_005649f0();
          }
          piVar7 = (int *)FUN_00567160();
          if (piVar7 == (int *)0x0) {
            piVar7 = (int *)0x0;
          }
          else {
            piVar7[2] = iVar6;
          }
          piVar2 = *(int **)(param_1 + 4);
          *piVar2 = (int)piVar7;
          *(int **)(param_1 + 4) = piVar7;
          piVar7[1] = (int)piVar2;
          *piVar7 = param_1;
        }
      }
    } while (iVar5 < 8);
  }
  *(undefined1 *)(param_1 + 0x54) = 0;
  *(undefined1 *)(param_1 + 0x55) = 1;
  HudWidget__SetVisible(0,0);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4a5a30 EngineTempGauge::BuildTempBarImageList

/* [canon] canon high (ghidra+hopper) docs/re/tuning.md */

void EngineTempGauge__BuildTempBarImageList(int param_1)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int *local_10;
  byte local_8;
  byte local_7 [7];
  
  iVar4 = 0;
  local_10 = (int *)(param_1 + 0x24);
  do {
    iVar4 = iVar4 + 1;
    FUN_00565da0("heat_%d",iVar4);
    iVar7 = -1;
    pbVar6 = &local_8;
    bVar3 = local_8;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar7 = iVar7 * 0x21 + (uint)bVar3;
      pbVar6 = pbVar6 + 1;
      bVar3 = *pbVar1;
    }
    if (*(int *)(param_1 + 8) == 0) goto LAB_004a5b01;
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) goto LAB_004a5af0;
    if (DAT_0073578c == 0) {
LAB_004a5b4f:
      iVar5 = 0;
    }
    else {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if (iVar2 == 0) {
LAB_004a5b01:
        if ((DAT_0073578c == 0) || (iVar5 = FUN_004ef050(iVar7), iVar5 == 0)) goto LAB_004a5b4f;
      }
      else {
        FUN_004ee660();
        iVar5 = FUN_004fd1e0(iVar2 + 0xdc);
        if (iVar5 == 0) {
          FUN_004ee660();
          iVar5 = FUN_004fd1e0(iVar2 + 0xec);
          if (iVar5 == 0) goto LAB_004a5b01;
        }
LAB_004a5af0:
        if ((iVar5 == 0) || (iVar5 = FUN_004ffb70(), iVar5 == 0)) goto LAB_004a5b01;
      }
      if (*(int *)(iVar5 + 0x18) != 1) goto LAB_004a5b4f;
      HudWidget__RegisterObject(iVar5);
    }
    *local_10 = iVar5;
    local_10 = local_10 + 1;
    if (7 < iVar4) {
      return;
    }
  } while( true );
}


// ==== 0x4a5b60 HudEngineHeat::Update

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void __fastcall HudEngineHeat__Update(undefined4 param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int *extraout_EDX;
  int *piVar3;
  float local_4;
  
  if ((*(uint *)(in_EAX + 0x18) & *(uint *)(in_EAX + 0x10)) != 0 ||
      (*(uint *)(in_EAX + 0x1c) & *(uint *)(in_EAX + 0x14)) != 0) {
    iVar2 = *(int *)(param_2 + 4);
    if (((DAT_006fbf14 == 0) && (*(int *)(param_2 + 0x10) == 0)) &&
       (iVar1 = RaceManager__FindRacerById(), iVar1 != 0)) {
      iVar2 = iVar1;
    }
    if (*(int *)(iVar2 + 0x28) == 1) {
      local_4 = *(float *)(*(int *)(*(int *)(iVar2 + 0x34) + 0x48) + 0x8c);
    }
    else {
      local_4 = 0.0;
    }
    FEObject__SetFormattedText(&DAT_006cc464,(double)local_4);
    iVar2 = _ftol_nocw();
    FEObject__SetInvisible(*(undefined4 *)(in_EAX + 0x50));
    if (4 < iVar2) {
      if (((DAT_00777b4c == 1) && (DAT_0073619c != (int *)0x0)) &&
         ((*DAT_0073619c == 4 && (*(char *)(in_EAX + 0x55) == '\x01')))) {
        *(undefined1 *)(in_EAX + 0x55) = 0;
      }
      FEObject__SetVisible();
      if (*(char *)(in_EAX + 0x54) == '\0') {
        FEObject__SetScript("Blink",1);
        *(undefined1 *)(in_EAX + 0x54) = 1;
      }
    }
    iVar1 = 0;
    if (0 < iVar2) {
      piVar3 = (int *)(in_EAX + 0x24);
      iVar1 = iVar2;
      do {
        if (*piVar3 != 0) {
          FEObject__SetVisible();
          piVar3 = extraout_EDX;
        }
        piVar3 = piVar3 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      iVar1 = iVar2;
      if (7 < iVar2) {
        return;
      }
    }
    iVar1 = 8 - iVar1;
    do {
      FEObject__SetInvisible();
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}


// ==== 0x4a5ca0 HudNos::HudNos

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

int HudNos__HudNos(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  undefined4 *puVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  byte *pbVar10;
  int iVar11;
  int *piVar12;
  int *local_44;
  byte local_2c;
  byte local_2b [31];
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_00687d70;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0x40000;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  local_4 = 0;
  uVar5 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar5);
  uVar5 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar5);
  FEng__HashName();
  uVar5 = HudElement__RegisterImage();
  local_44 = (int *)(param_1 + 0x4c);
  *(undefined4 *)(param_1 + 100) = uVar5;
  *(undefined4 *)(param_1 + 0x24) = 1;
  iVar6 = 0;
  do {
    *(undefined1 *)(param_1 + 0x28 + iVar6) = 1;
    iVar6 = iVar6 + 1;
    bSPrintf_regdst(0x20,"NOS_bar_6_%d",iVar6);
    iVar11 = -1;
    pbVar10 = &local_2c;
    bVar4 = local_2c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      pbVar1 = pbVar10 + 1;
      iVar11 = iVar11 * 0x21 + (uint)bVar4;
      pbVar10 = pbVar10 + 1;
      bVar4 = *pbVar1;
    }
    if (*(int *)(param_1 + 8) == 0) goto LAB_004a5e1b;
    iVar7 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar7 != 0) && (iVar7 = *(int *)(iVar7 + 0x18), iVar7 != 0)) goto LAB_004a5de3;
    if (DAT_0073578c == 0) {
LAB_004a5ebf:
      iVar11 = 0;
    }
    else {
      iVar8 = *(int *)(DAT_0073578c + 8);
      if (iVar8 != 0) {
        FUN_004ee660();
        iVar7 = FUN_004fd1e0(iVar8 + 0xdc);
        if (iVar7 == 0) {
          FUN_004ee660();
          iVar7 = FUN_004fd1e0(iVar8 + 0xec);
          if (iVar7 == 0) goto LAB_004a5e1b;
        }
LAB_004a5de3:
        local_4._0_1_ = 1;
        FUN_004ffb00(iVar7);
        local_4 = (uint)local_4._1_3_ << 8;
      }
LAB_004a5e1b:
      if (((DAT_0073578c == 0) || (iVar11 = FUN_004ef050(iVar11), iVar11 == 0)) ||
         (*(int *)(iVar11 + 0x18) != 1)) goto LAB_004a5ebf;
      if (DAT_007349b4 == 0) {
        FUN_005649f0();
      }
      iVar7 = DAT_007349b4;
      piVar12 = (int *)(DAT_007349b4 + 0x10);
      if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
        FUN_00566e60();
      }
      piVar9 = (int *)*piVar12;
      iVar8 = *(int *)(iVar7 + 0x18) + 1;
      if (piVar9 == (int *)0x0) {
        piVar9 = (int *)0x0;
      }
      else {
        iVar2 = *piVar9;
        if (*(int *)(iVar7 + 0x1c) < iVar8) {
          *(int *)(iVar7 + 0x1c) = iVar8;
        }
        *(int *)(iVar7 + 0x18) = iVar8;
        bVar4 = *(byte *)(iVar7 + 0x14);
        *piVar12 = iVar2;
        if (((bVar4 & 2) != 0) && (iVar7 = *(int *)(iVar7 + 0x28) >> 2, piVar12 = piVar9, 0 < iVar7)
           ) {
          for (; iVar7 != 0; iVar7 = iVar7 + -1) {
            *piVar12 = 0;
            piVar12 = piVar12 + 1;
          }
        }
        piVar9[2] = iVar11;
      }
      puVar3 = *(undefined4 **)(param_1 + 4);
      *puVar3 = piVar9;
      *(int **)(param_1 + 4) = piVar9;
      piVar9[1] = (int)puVar3;
      *piVar9 = param_1;
    }
    *local_44 = iVar11;
    local_44 = local_44 + 1;
  } while (iVar6 < 6);
  iVar6 = 0;
  local_44 = (int *)(param_1 + 0x3c);
  do {
    iVar6 = iVar6 + 1;
    bSPrintf_regdst(0x20,"NOS_bar_4_%d",iVar6);
    iVar11 = -1;
    pbVar10 = &local_2c;
    bVar4 = local_2c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      pbVar1 = pbVar10 + 1;
      iVar11 = iVar11 * 0x21 + (uint)bVar4;
      pbVar10 = pbVar10 + 1;
      bVar4 = *pbVar1;
    }
    if (*(int *)(param_1 + 8) == 0) goto LAB_004a5ff0;
    iVar7 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar7 != 0) && (iVar7 = *(int *)(iVar7 + 0x18), iVar7 != 0)) goto LAB_004a5fb8;
    if (DAT_0073578c == 0) {
LAB_004a6043:
      iVar11 = 0;
    }
    else {
      iVar8 = *(int *)(DAT_0073578c + 8);
      if (iVar8 != 0) {
        FUN_004ee660();
        iVar7 = FUN_004fd1e0(iVar8 + 0xdc);
        if (iVar7 == 0) {
          FUN_004ee660();
          iVar7 = FUN_004fd1e0(iVar8 + 0xec);
          if (iVar7 == 0) goto LAB_004a5ff0;
        }
LAB_004a5fb8:
        local_4._0_1_ = 2;
        FUN_004ffb00(iVar7);
        local_4 = (uint)local_4._1_3_ << 8;
      }
LAB_004a5ff0:
      if (((DAT_0073578c == 0) || (iVar11 = FUN_004ef050(iVar11), iVar11 == 0)) ||
         (*(int *)(iVar11 + 0x18) != 1)) goto LAB_004a6043;
      if (DAT_007349b4 == 0) {
        iVar7 = FUN_00566dc0(0xc,"bPNode SlotPool",0);
        if ((iVar7 != 0) && (DAT_0073d814 == 1)) {
          bList__AddTail();
        }
        DAT_007349b8 = 0;
        DAT_007349b4 = iVar7;
      }
      iVar7 = DAT_007349b4;
      piVar12 = (int *)(DAT_007349b4 + 0x10);
      if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
        FUN_00566e60();
      }
      piVar9 = (int *)*piVar12;
      iVar8 = *(int *)(iVar7 + 0x18) + 1;
      if (piVar9 == (int *)0x0) {
        piVar9 = (int *)0x0;
      }
      else {
        iVar2 = *piVar9;
        if (*(int *)(iVar7 + 0x1c) < iVar8) {
          *(int *)(iVar7 + 0x1c) = iVar8;
        }
        *(int *)(iVar7 + 0x18) = iVar8;
        bVar4 = *(byte *)(iVar7 + 0x14);
        *piVar12 = iVar2;
        if (((bVar4 & 2) != 0) && (iVar7 = *(int *)(iVar7 + 0x28) >> 2, piVar12 = piVar9, 0 < iVar7)
           ) {
          for (; iVar7 != 0; iVar7 = iVar7 + -1) {
            *piVar12 = 0;
            piVar12 = piVar12 + 1;
          }
        }
        piVar9[2] = iVar11;
      }
      puVar3 = *(undefined4 **)(param_1 + 4);
      *puVar3 = piVar9;
      *(int **)(param_1 + 4) = piVar9;
      piVar9[1] = (int)puVar3;
      *piVar9 = param_1;
    }
    *local_44 = iVar11;
    local_44 = local_44 + 1;
  } while (iVar6 < 4);
  iVar6 = 0;
  local_44 = (int *)(param_1 + 0x34);
  do {
    iVar6 = iVar6 + 1;
    bSPrintf_regdst(0x20,"NOS_bar_2_%d",iVar6);
    iVar11 = -1;
    pbVar10 = &local_2c;
    bVar4 = local_2c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      pbVar1 = pbVar10 + 1;
      iVar11 = iVar11 * 0x21 + (uint)bVar4;
      pbVar10 = pbVar10 + 1;
      bVar4 = *pbVar1;
    }
    if (*(int *)(param_1 + 8) == 0) goto LAB_004a61f0;
    iVar7 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar7 != 0) && (iVar7 = *(int *)(iVar7 + 0x18), iVar7 != 0)) goto LAB_004a61b8;
    if (DAT_0073578c == 0) {
LAB_004a6218:
      iVar11 = 0;
    }
    else {
      iVar8 = *(int *)(DAT_0073578c + 8);
      if (iVar8 != 0) {
        FUN_004ee660();
        iVar7 = FUN_004fd1e0(iVar8 + 0xdc);
        if (iVar7 == 0) {
          FUN_004ee660();
          iVar7 = FUN_004fd1e0(iVar8 + 0xec);
          if (iVar7 == 0) goto LAB_004a61f0;
        }
LAB_004a61b8:
        local_4._0_1_ = 3;
        FUN_004ffb00(iVar7);
        local_4 = (uint)local_4._1_3_ << 8;
      }
LAB_004a61f0:
      if (((DAT_0073578c == 0) || (iVar11 = FUN_004ef050(iVar11), iVar11 == 0)) ||
         (*(int *)(iVar11 + 0x18) != 1)) goto LAB_004a6218;
      if (DAT_007349b4 == 0) {
        iVar7 = FUN_00566dc0(0xc,"bPNode SlotPool",0);
        if ((iVar7 != 0) && (DAT_0073d814 == 1)) {
          bList__AddTail();
        }
        DAT_007349b8 = 0;
        DAT_007349b4 = iVar7;
      }
      iVar7 = DAT_007349b4;
      piVar12 = (int *)(DAT_007349b4 + 0x10);
      if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
        FUN_00566e60();
      }
      piVar9 = (int *)*piVar12;
      iVar8 = *(int *)(iVar7 + 0x18) + 1;
      if (piVar9 == (int *)0x0) {
        piVar9 = (int *)0x0;
      }
      else {
        iVar2 = *piVar9;
        if (*(int *)(iVar7 + 0x1c) < iVar8) {
          *(int *)(iVar7 + 0x1c) = iVar8;
        }
        *(int *)(iVar7 + 0x18) = iVar8;
        bVar4 = *(byte *)(iVar7 + 0x14);
        *piVar12 = iVar2;
        if (((bVar4 & 2) != 0) && (iVar7 = *(int *)(iVar7 + 0x28) >> 2, piVar12 = piVar9, 0 < iVar7)
           ) {
          for (; iVar7 != 0; iVar7 = iVar7 + -1) {
            *piVar12 = 0;
            piVar12 = piVar12 + 1;
          }
        }
        piVar9[2] = iVar11;
      }
      puVar3 = *(undefined4 **)(param_1 + 4);
      *puVar3 = piVar9;
      *(int **)(param_1 + 4) = piVar9;
      piVar9[1] = (int)puVar3;
      *piVar9 = param_1;
    }
    *local_44 = iVar11;
    local_44 = local_44 + 1;
    if (1 < iVar6) {
      uVar5 = FEColor__operator_unsigned_long();
      *(undefined4 *)(param_1 + 0x30) = uVar5;
      *(undefined1 *)(param_1 + 0x2e) = 0;
      HudWidget__SetVisible(0,0);
      ExceptionList = local_c;
      return param_1;
    }
  } while( true );
}


// ==== 0x4a6360 FUN_004a6360

void FUN_004a6360(char param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 uVar6;
  int extraout_EDX;
  int unaff_EBX;
  int iVar7;
  byte local_20;
  byte local_1f [31];
  
  iVar3 = 0;
  if (0 < param_2) {
    do {
      iVar3 = iVar3 + 1;
      bSPrintf_regdst(0x20,"NOS_bar_%d_%d",param_2,iVar3);
      iVar7 = -1;
      pbVar5 = &local_20;
      bVar2 = local_20;
      if (param_1 == '\0') {
        while (bVar2 != 0) {
          if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
            bVar2 = bVar2 - 0x20;
          }
          pbVar1 = pbVar5 + 1;
          iVar7 = iVar7 * 0x21 + (uint)bVar2;
          pbVar5 = pbVar5 + 1;
          bVar2 = *pbVar1;
        }
        if (((*(int *)(unaff_EBX + 8) == 0) || (iVar4 = FUN_004f65d0(), iVar4 == 0)) ||
           (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
          if (DAT_0073578c == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = FUN_004ef050(iVar7);
          }
        }
        FEObject__SetInvisible(iVar4);
      }
      else {
        while (bVar2 != 0) {
          if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
            bVar2 = bVar2 - 0x20;
          }
          pbVar1 = pbVar5 + 1;
          iVar7 = iVar7 * 0x21 + (uint)bVar2;
          pbVar5 = pbVar5 + 1;
          bVar2 = *pbVar1;
        }
        if (((((*(int *)(unaff_EBX + 8) != 0) && (iVar4 = FUN_004f65d0(), iVar4 != 0)) &&
             (iVar4 = FUN_004ffb70(), iVar4 != 0)) ||
            ((DAT_0073578c != 0 && (iVar4 = FUN_004ef050(iVar7), iVar4 != 0)))) &&
           (*(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffe | 0x400000,
           *(int *)(iVar4 + 0x18) == 5)) {
          uVar6 = *(undefined4 *)(iVar4 + 0x60);
          iVar7 = *(int *)(iVar4 + 0x5c);
          if (0 < iVar7) {
            do {
              FEObject__SetVisible(uVar6);
              uVar6 = *(undefined4 *)(extraout_EDX + 4);
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
        }
      }
    } while (iVar3 < param_2);
  }
  return;
}


// ==== 0x4a64b0 FUN_004a64b0

void FUN_004a64b0(int param_1)

{
  float fVar1;
  byte bVar2;
  char cVar3;
  int in_EAX;
  int *piVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float local_18;
  
  if (((*(int *)(in_EAX + 0x3b0) != 0) && (*(int *)(in_EAX + 0x3b0) != 0x7fffffff)) &&
     (fVar1 = (float)*(int *)(in_EAX + 0x3b0) * 0.00025, fVar1 != 0.0)) {
    fVar7 = (float10)FUN_00449f80();
    bVar2 = _ftol_nocw();
    if ((*(int *)(in_EAX + 0x3b0) == 0) || (*(int *)(in_EAX + 0x3b0) == 0x7fffffff)) {
      fVar1 = 0.0;
    }
    fVar1 = fVar1 * 0.16666667;
    if (((*(int *)(in_EAX + 0x3bc) == 0) || (*(int *)(in_EAX + 0x3bc) == 0x7fffffff)) ||
       ((float)*(int *)(in_EAX + 0x3bc) * 0.00025 == 0.0)) {
      if ((*(int *)(in_EAX + 0x3b8) == 0) || (*(int *)(in_EAX + 0x3b8) == 0x7fffffff)) {
        local_18 = 0.0;
      }
      else {
        local_18 = (float)*(int *)(in_EAX + 0x3b8) * 0.00025;
      }
      local_18 = local_18 - (float)bVar2 * fVar1;
    }
    else {
      local_18 = (float)fVar7 - (float)bVar2 * fVar1;
    }
    local_18 = local_18 / fVar1;
    if (local_18 < 0.0) {
      local_18 = 0.0;
    }
    iVar6 = 5;
    if ((int)(6 - (uint)bVar2) < 6) {
      iVar5 = 6 - (6 - (uint)bVar2);
      iVar6 = 5 - iVar5;
      do {
        FUN_004f75b0(*(undefined4 *)(param_1 + 0x30));
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    if ((bVar2 < 6) && (0.0 < local_18)) {
      iVar5 = _ftol_nocw();
      FUN_004f75b0(iVar5 * 0x1000000 + (*(uint *)(param_1 + 0x30) & 0xffffff));
      iVar6 = iVar6 + -1;
    }
    if (-1 < iVar6) {
      piVar4 = (int *)(param_1 + 0x4c + iVar6 * 4);
      iVar6 = iVar6 + 1;
      do {
        iVar5 = *piVar4;
        if ((iVar5 != 0) && (*(int *)(iVar5 + 0x18) < 0x100)) {
          cVar3 = FEColor_NearlyEqual();
          if (cVar3 == '\0') {
            *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 0x400000;
          }
          FUN_004ff2f0(iVar5,0,0);
        }
        piVar4 = piVar4 + -1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  return;
}


// ==== 0x4a67a0 HudNos::Update

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void __fastcall HudNos__Update(undefined4 param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((*(uint *)(in_EAX + 0x18) & *(uint *)(in_EAX + 0x10)) != 0 ||
      (*(uint *)(in_EAX + 0x1c) & *(uint *)(in_EAX + 0x14)) != 0) {
    iVar2 = *(int *)(param_2 + 4);
    if ((DAT_006fbf14 == 0) && (*(int *)(param_2 + 0x10) == 0)) {
      iVar1 = RaceManager__FindRacerById();
      if (iVar1 != 0) {
        iVar2 = iVar1;
      }
    }
    if ((((*(int *)(iVar2 + 0x20) == -0x2a0) || (*(int *)(iVar2 + 0x3f0) == 0)) ||
        (*(int *)(iVar2 + 0x3f0) == 0x7fffffff)) ||
       ((float)*(int *)(iVar2 + 0x3f0) * 0.00025 <= 0.0)) {
      FEObject__SetInvisible(*(undefined4 *)(in_EAX + 100));
      uVar3 = 0;
    }
    else {
      *(undefined4 *)(in_EAX + 0x20) = *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x2a4);
      FEObject__SetVisible(*(undefined4 *)(in_EAX + 100));
      uVar3 = 1;
    }
    FUN_004a6360(uVar3,6);
    FUN_004a6360(0,4);
    FUN_004a6360(0,2);
    FUN_004a64b0(in_EAX);
    if ((DAT_0078a320 == 2) && ((DAT_0078a345 != '\0' || (DAT_007361a4 != 0)))) {
      FUN_004a6360(0,2);
      FUN_004a6360(0,4);
      FUN_004a6360(0,6);
    }
  }
  return;
}


// ==== 0x4a68a0 HudSmokeApplause::HudSmokeApplause

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

int HudSmokeApplause__HudSmokeApplause(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00687e78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0x10000;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  local_4 = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  FEng__HashName();
  uVar1 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  FEng__HashName();
  uVar1 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  FEng__HashName();
  uVar1 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  FEng__HashName();
  uVar1 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  FEng__HashName();
  uVar1 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  FEng__HashName();
  uVar1 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  FEng__HashName();
  uVar1 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x50) = uVar1;
  FEng__HashName();
  uVar1 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x54) = uVar1;
  FEng__HashName();
  HudWidget__RegisterString();
  FEng__HashName();
  HudWidget__RegisterString();
  FEng__HashName();
  HudElement__RegisterImage();
  uVar1 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar1);
  uVar1 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar1);
  HudWidget__SetVisible(0,0);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4a6a10 HudSmokeApplause::Update

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void HudSmokeApplause__Update(int param_1)

{
  int iVar1;
  float fVar2;
  char cVar3;
  int in_EAX;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  float10 fVar10;
  int *local_30;
  float local_2c;
  uint local_28;
  undefined1 local_24 [4];
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  iVar8 = param_1;
  if ((*(uint *)(in_EAX + 0x18) & *(uint *)(in_EAX + 0x10)) != 0 ||
      (*(uint *)(in_EAX + 0x1c) & *(uint *)(in_EAX + 0x14)) != 0) {
    if (*(int *)(in_EAX + 0x24) != 0) {
      FUN_0049ff50(in_EAX,*(undefined4 *)(param_1 + 0x110),0x40a00000,0x41200000,&DAT_41900000);
      fVar10 = (float10)Player__GetTimeUntilOnFire();
      if (fVar10 < (float10)0.0) {
        local_20 = 0x80;
        local_14 = 0x80;
        local_18 = 0x80;
        local_1c = 0x80;
      }
      else {
        fVar10 = (float10)FUN_0049fc50();
        local_30 = (int *)(float)fVar10;
        Curve_Evaluate(&local_2c,local_30);
        if (local_2c * _K_HALF <= DAT_0073457c) {
          local_2c = *(float *)(in_EAX + 0x20);
          fVar10 = (float10)(int)local_2c * (float10)_K_HALF;
          *(int *)(in_EAX + 0x20) = 1 - (int)local_2c;
        }
        else {
          local_30 = (int *)((float)local_30 / local_2c);
          fVar10 = (float10)FUN_004387e0(local_30);
          fVar10 = (float10)(float)local_30 - fVar10;
        }
        local_30 = (int *)(float)fVar10;
        FUN_004a9810(&PTR_DAT_00705ae8,local_30);
        local_2c = (float)Hud_PackColorFromFloats();
        local_14 = (uint)local_2c >> 0x18;
        local_1c = (uint)local_2c >> 8 & 0xff;
        local_18 = (uint)local_2c >> 0x10 & 0xff;
        local_20 = (uint)local_2c & 0xff;
      }
      iVar1 = *(int *)(in_EAX + 0x24);
      if (*(int *)(iVar1 + 0x18) < 0x100) {
        cVar3 = FEColor_NearlyEqual();
        if (cVar3 == '\0') {
          *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
        }
        FUN_004ff2f0(iVar1,0,0);
      }
    }
    if (*(int *)(in_EAX + 0x2c) != 0) {
      local_2c = *(float *)(iVar8 + 0x104);
      uVar4 = _ftol_nocw();
      FEObject__SetFormattedText(&DAT_006c6f70,uVar4);
      FUN_004a9810(&PTR_DAT_00705ad8,local_2c);
      iVar5 = _ftol_nocw();
      uVar6 = _ftol_nocw();
      uVar7 = _ftol_nocw();
      local_20 = _ftol_nocw();
      iVar1 = *(int *)(in_EAX + 0x2c);
      local_2c = (float)(((iVar5 << 8 | uVar6) << 8 | uVar7) << 8 | local_20);
      local_1c = (uint)local_2c >> 8 & 0xff;
      local_18 = (uint)local_2c >> 0x10 & 0xff;
      local_14 = (uint)local_2c >> 0x18;
      local_20 = local_20 & 0xff;
      if (*(int *)(iVar1 + 0x18) < 0x100) {
        cVar3 = FEColor_NearlyEqual();
        if (cVar3 == '\0') {
          *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
        }
        FUN_004ff2f0(iVar1,0,0);
      }
    }
    if ((((*(int *)(in_EAX + 0x3c) != 0) && (*(int *)(in_EAX + 0x40) != 0)) &&
        (*(int *)(in_EAX + 0x48) != 0)) && (*(int *)(in_EAX + 0x44) != 0)) {
      iVar8 = FUN_0049fcf0();
      puVar9 = (undefined4 *)(iVar8 + 0x3a4);
      local_2c = 5.60519e-45;
      local_30 = (int *)(in_EAX + 0x3c);
      do {
        FUN_004a9810(&PTR_DAT_00705ae0,*puVar9);
        iVar8 = _ftol_nocw();
        uVar6 = _ftol_nocw();
        uVar7 = _ftol_nocw();
        local_20 = _ftol_nocw();
        local_28 = ((iVar8 << 8 | uVar6) << 8 | uVar7) << 8 | local_20;
        local_14 = local_28 >> 0x18;
        local_18 = local_28 >> 0x10 & 0xff;
        iVar8 = *local_30;
        local_1c = local_28 >> 8 & 0xff;
        local_20 = local_20 & 0xff;
        if (*(int *)(iVar8 + 0x18) < 0x100) {
          cVar3 = FEColor_NearlyEqual();
          if (cVar3 == '\0') {
            *(uint *)(iVar8 + 0x1c) = *(uint *)(iVar8 + 0x1c) | 0x400000;
          }
          FUN_004ff2f0(iVar8,0,0);
        }
        local_30 = local_30 + 1;
        puVar9 = puVar9 + 1;
        local_2c = (float)((int)local_2c + -1);
      } while (local_2c != 0.0);
      local_2c = 0.0;
      iVar8 = param_1;
    }
    if (*(int *)(in_EAX + 0x38) != 0) {
      FUN_00432cc0();
      local_28 = _ftol_nocw();
      FUN_005864f0(local_24,&local_2c,&param_1,&local_30);
      if ((int)local_2c < 1) {
        FEObject__SetFormattedText(" 0:%02d",param_1);
      }
      else {
        FEObject__SetFormattedText("%2d:%02d",local_2c,param_1);
      }
    }
    if (*(int *)(in_EAX + 0x4c) != 0) {
      FEObject__SetInvisible(*(int *)(in_EAX + 0x4c));
    }
    if (*(int *)(in_EAX + 0x50) != 0) {
      FEObject__SetFormattedText(&DAT_006c6f54,1);
    }
    if (*(int *)(in_EAX + 0x54) != 0) {
      if (*(int *)(iVar8 + 0x130) == 0) {
        fVar2 = -1.0;
      }
      else {
        fVar2 = *(float *)(iVar8 + 0x184) / *(float *)(*(int *)(*(int *)(iVar8 + 0x130) + 4) + 0xc);
      }
      if (fVar2 * 100.0 < 0.0) {
        FEObject__SetInvisible(*(int *)(in_EAX + 0x54));
      }
      else {
        FEObject__SetVisible();
        uVar4 = _ftol_nocw();
        FEObject__SetFormattedText("%2d%%",uVar4);
      }
    }
    if (*(int *)(in_EAX + 0x34) != 0) {
      uVar4 = _ftol_nocw();
      FEObject__SetFormattedText(&DAT_006c6f48,uVar4);
    }
    if (*(int *)(in_EAX + 0x30) != 0) {
      uVar4 = _ftol_nocw();
      FEObject__SetFormattedText(&DAT_006c6f48,uVar4);
    }
  }
  return;
}


// ==== 0x4a6eb0 HudStylePoints::FillMoment

/* [canon] hud low (ghidra-canon) docs/re/canon.md */

void __fastcall HudStylePoints__FillMoment(int param_1)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = DAT_00736198;
  *(undefined4 *)(in_EAX + 0x18) = 0;
  *(bool *)(in_EAX + 8) = *(char *)(*(int *)(param_1 + 0xc) * 0x20 + 6 + iVar1) != '\0';
  *(undefined4 *)(in_EAX + 0xc) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(*(int *)(param_1 + 0xc) * 0x20 + iVar1);
  *(undefined4 *)(in_EAX + 0x18) = 0;
  *(undefined1 *)(in_EAX + 0x20) = 0;
  *(bool *)(in_EAX + 0x21) = *(int *)(param_1 + 0x10) == 4;
  return;
}


// ==== 0x4a6f10 HudSpeedTrapDrift::HudSpeedTrapDrift

/* WARNING: Removing unreachable block (ram,0x004a73a2) */
/* WARNING: Removing unreachable block (ram,0x004a7549) */
/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

int HudSpeedTrapDrift__HudSpeedTrapDrift(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  undefined4 *puVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  byte *pbVar10;
  char *pcVar11;
  uint uVar12;
  int iVar13;
  int *piVar14;
  byte local_2c;
  byte local_2b [31];
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_00687d38;
  local_c = ExceptionList;
  iVar13 = 0;
  ExceptionList = &local_c;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0x80000000;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined1 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 1;
  *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined1 *)(param_1 + 0x40) = 0;
  *(undefined1 *)(param_1 + 0x41) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  local_4 = 0;
  *(undefined1 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined1 *)(param_1 + 0xac) = 0;
  *(undefined1 *)(param_1 + 0xad) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0x3d4ccccd;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined1 *)(param_1 + 0xbc) = 0;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x80) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x84) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x70) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x6c) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x88) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x74) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  iVar6 = *(int *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x78) = uVar5;
  uVar5 = FEng__HashName();
  if (((((iVar6 == 0) || (iVar6 = FUN_004f65d0(), iVar6 == 0)) ||
       (iVar6 = FUN_004ffb70(), iVar6 == 0)) &&
      ((DAT_0073578c == 0 || (iVar6 = FUN_004ef050(uVar5), iVar6 == 0)))) ||
     (*(int *)(iVar6 + 0x18) != 2)) {
    iVar6 = 0;
  }
  iVar7 = *(int *)(param_1 + 8);
  *(int *)(param_1 + 100) = iVar6;
  uVar5 = FEng__HashName();
  if (((((iVar7 == 0) || (iVar6 = FUN_004f65d0(), iVar6 == 0)) ||
       (iVar6 = FUN_004ffb70(), iVar6 == 0)) &&
      ((DAT_0073578c == 0 || (iVar6 = FUN_004ef050(uVar5), iVar6 == 0)))) ||
     (*(int *)(iVar6 + 0x18) != 2)) {
    iVar6 = 0;
  }
  iVar7 = *(int *)(param_1 + 8);
  *(int *)(param_1 + 0x68) = iVar6;
  uVar5 = FEng__HashName();
  if (((((iVar7 == 0) || (iVar6 = FUN_004f65d0(), iVar6 == 0)) ||
       (iVar6 = FUN_004ffb70(), iVar6 == 0)) &&
      ((DAT_0073578c == 0 || (iVar6 = FUN_004ef050(uVar5), iVar6 == 0)))) ||
     (*(int *)(iVar6 + 0x18) != 2)) {
    iVar6 = 0;
  }
  iVar7 = *(int *)(param_1 + 8);
  *(int *)(param_1 + 0x8c) = iVar6;
  uVar5 = FEng__HashName();
  if (((((iVar7 == 0) || (iVar6 = FUN_004f65d0(), iVar6 == 0)) ||
       (iVar6 = FUN_004ffb70(), iVar6 == 0)) &&
      ((DAT_0073578c == 0 || (iVar6 = FUN_004ef050(uVar5), iVar6 == 0)))) ||
     (*(int *)(iVar6 + 0x18) != 2)) {
    iVar6 = 0;
  }
  *(int *)(param_1 + 0x90) = iVar6;
  FEObject__SetInvisible(*(undefined4 *)(param_1 + 0x8c));
  FEObject__SetInvisible(*(undefined4 *)(param_1 + 0x90));
  FEng__HashName();
  HudElement__RegisterImage();
  FEng__HashName();
  HudWidget__RegisterString();
  FEng__HashName();
  uVar5 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x44) = uVar5;
  FEng__HashName();
  uVar5 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x48) = uVar5;
  FEng__HashName();
  uVar5 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x4c) = uVar5;
  FEng__HashName();
  uVar5 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x50) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x54) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x58) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x5c) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x60) = uVar5;
  uVar5 = FUN_0049fc90();
  *(undefined4 *)(param_1 + 0x94) = uVar5;
  uVar5 = FUN_0049fc90();
  *(undefined4 *)(param_1 + 0x98) = uVar5;
  uVar5 = FUN_0049fc90();
  *(undefined4 *)(param_1 + 0x9c) = uVar5;
  do {
    iVar13 = iVar13 + 1;
    bSPrintf_regdst(0x20,"CurrentSpeed_Trap_Backing_0%d",iVar13);
    iVar6 = -1;
    pbVar10 = &local_2c;
    bVar4 = local_2c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      iVar6 = iVar6 * 0x21 + (uint)bVar4;
      pbVar1 = pbVar10 + 1;
      pbVar10 = pbVar10 + 1;
      bVar4 = *pbVar1;
    }
    if (*(int *)(param_1 + 8) == 0) goto LAB_004a73a8;
    iVar7 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar7 != 0) && (iVar7 = *(int *)(iVar7 + 0x18), iVar7 != 0)) goto LAB_004a736a;
    if (DAT_0073578c != 0) {
      iVar8 = *(int *)(DAT_0073578c + 8);
      if (iVar8 != 0) {
        FUN_004ee660();
        iVar7 = FUN_004fd1e0(iVar8 + 0xdc);
        if (iVar7 == 0) {
          FUN_004ee660();
          iVar7 = FUN_004fd1e0(iVar8 + 0xec);
          if (iVar7 == 0) goto LAB_004a73a8;
        }
LAB_004a736a:
        local_4._0_1_ = 1;
        FUN_004ffb00(iVar7);
        local_4 = (uint)local_4._1_3_ << 8;
      }
LAB_004a73a8:
      if (((DAT_0073578c != 0) && (iVar6 = FUN_004ef050(iVar6), iVar6 != 0)) &&
         (*(int *)(iVar6 + 0x18) == 1)) {
        if (DAT_007349b4 == 0) {
          FUN_005649f0();
        }
        iVar7 = DAT_007349b4;
        piVar14 = (int *)(DAT_007349b4 + 0x10);
        if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
          FUN_00566e60();
        }
        piVar9 = (int *)*piVar14;
        iVar8 = *(int *)(iVar7 + 0x18) + 1;
        if (piVar9 == (int *)0x0) {
          piVar9 = (int *)0x0;
        }
        else {
          iVar2 = *piVar9;
          if (*(int *)(iVar7 + 0x1c) < iVar8) {
            *(int *)(iVar7 + 0x1c) = iVar8;
          }
          *(int *)(iVar7 + 0x18) = iVar8;
          bVar4 = *(byte *)(iVar7 + 0x14);
          *piVar14 = iVar2;
          if (((bVar4 & 2) != 0) &&
             (iVar7 = *(int *)(iVar7 + 0x28) >> 2, piVar14 = piVar9, 0 < iVar7)) {
            for (; iVar7 != 0; iVar7 = iVar7 + -1) {
              *piVar14 = 0;
              piVar14 = piVar14 + 1;
            }
          }
          piVar9[2] = iVar6;
        }
        puVar3 = *(undefined4 **)(param_1 + 4);
        *puVar3 = piVar9;
        *(int **)(param_1 + 4) = piVar9;
        piVar9[1] = (int)puVar3;
        *piVar9 = param_1;
      }
    }
  } while (iVar13 < 3);
  pcVar11 = "NextSpeeed_Trap_Indicator";
  iVar13 = -1;
  bVar4 = 0x4e;
  do {
    if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
      bVar4 = bVar4 - 0x20;
    }
    uVar12 = (uint)bVar4;
    bVar4 = pcVar11[1];
    iVar13 = iVar13 * 0x21 + uVar12;
    pcVar11 = pcVar11 + 1;
  } while (bVar4 != 0);
  if (*(int *)(param_1 + 8) == 0) goto LAB_004a7553;
  iVar6 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar6 == 0) || (iVar6 = *(int *)(iVar6 + 0x18), iVar6 == 0)) {
    if (DAT_0073578c != 0) {
      iVar7 = *(int *)(DAT_0073578c + 8);
      if (iVar7 != 0) {
        FUN_004ee660();
        iVar6 = FUN_004fd1e0(iVar7 + 0xdc);
        if (iVar6 == 0) {
          FUN_004ee660();
          iVar6 = FUN_004fd1e0(iVar7 + 0xec);
          if (iVar6 == 0) goto LAB_004a7553;
        }
        if (iVar6 != 0) goto LAB_004a7511;
      }
      goto LAB_004a7553;
    }
  }
  else {
LAB_004a7511:
    local_4._0_1_ = 2;
    FUN_004ffb00(iVar6);
    local_4 = (uint)local_4._1_3_ << 8;
LAB_004a7553:
    if (((DAT_0073578c != 0) && (iVar13 = FUN_004ef050(iVar13), iVar13 != 0)) &&
       (*(int *)(iVar13 + 0x18) == 2)) {
      if (DAT_007349b4 == 0) {
        FUN_005649f0();
      }
      iVar6 = DAT_007349b4;
      piVar14 = (int *)(DAT_007349b4 + 0x10);
      if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
        FUN_00566e60();
      }
      piVar9 = (int *)*piVar14;
      iVar7 = *(int *)(iVar6 + 0x18) + 1;
      if (piVar9 == (int *)0x0) {
        piVar9 = (int *)0x0;
      }
      else {
        iVar8 = *piVar9;
        if (*(int *)(iVar6 + 0x1c) < iVar7) {
          *(int *)(iVar6 + 0x1c) = iVar7;
        }
        *(int *)(iVar6 + 0x18) = iVar7;
        bVar4 = *(byte *)(iVar6 + 0x14);
        *piVar14 = iVar8;
        if (((bVar4 & 2) != 0) && (iVar6 = *(int *)(iVar6 + 0x28) >> 2, piVar14 = piVar9, 0 < iVar6)
           ) {
          for (; iVar6 != 0; iVar6 = iVar6 + -1) {
            *piVar14 = 0;
            piVar14 = piVar14 + 1;
          }
        }
        piVar9[2] = iVar13;
      }
      puVar3 = *(undefined4 **)(param_1 + 4);
      *puVar3 = piVar9;
      *(int **)(param_1 + 4) = piVar9;
      piVar9[1] = (int)puVar3;
      *piVar9 = param_1;
      goto LAB_004a7614;
    }
  }
  iVar13 = 0;
LAB_004a7614:
  *(int *)(param_1 + 0x7c) = iVar13;
  if (DAT_0078a3f5 == '\0') {
    pcVar11 = "%3.1f";
  }
  else {
    pcVar11 = (char *)&PTR_LAB_006c6d6c;
  }
  FEObject__SetFormattedText(pcVar11,0,0);
  FUN_004a7990(param_1,0);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4a7660 HudSpeedTrapDrift::Update

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void HudSpeedTrapDrift__Update(int param_1)

{
  char cVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  int unaff_EBX;
  int iVar8;
  float10 fVar9;
  char local_20 [32];
  
  if ((*(uint *)(unaff_EBX + 0x18) & *(uint *)(unaff_EBX + 0x10)) != 0 ||
      (*(uint *)(unaff_EBX + 0x1c) & *(uint *)(unaff_EBX + 0x14)) != 0) {
    FEObject__SetInvisible(*(undefined4 *)(unaff_EBX + 0x6c));
    iVar8 = *(int *)(param_1 + 4);
    if ((DAT_006fbf14 == 0) && (*(int *)(param_1 + 0x10) == 0)) {
      iVar3 = RaceManager__FindRacerById();
      if (iVar3 != 0) {
        iVar8 = iVar3;
      }
    }
    fVar9 = (float10)CarState__GetYaw();
    FUN_004a7b00((float)(fVar9 * (float10)57.295776),*(undefined4 *)(iVar8 + 0x3d0));
    if (*(char *)(unaff_EBX + 0xac) == '\0') {
      FUN_004a7b80(*(undefined1 *)(param_1 + 0x9f3));
      if (*(int *)(param_1 + 0x9f4) == 1) {
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x95c) + 0x50) + 0x50) = 0xffffff00;
      }
      else {
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x95c) + 0x50) + 0x50) = 0xffff8020;
      }
      iVar8 = *(int *)(param_1 + 0x9fc);
      iVar3 = _ftol_nocw();
      if (iVar8 < 1) {
        FEObject__SetFormattedText(&DAT_006c6d7c);
        FEString__SetLabelHash();
        FUN_004f75b0(0xffffff00);
      }
      else {
        FEObject__SetFormattedText(&DAT_006ca778,iVar8);
        iVar4 = LanguageStrings__FindByHash();
        if (iVar4 == 0) {
          iVar4 = LanguageStrings__FindByHash();
        }
        iVar7 = 0x20;
        pcVar6 = local_20;
        do {
          cVar1 = pcVar6[iVar4 - (int)local_20];
          iVar7 = iVar7 + -1;
          *pcVar6 = cVar1;
          if (cVar1 == '\0') break;
          pcVar6 = pcVar6 + 1;
        } while (iVar7 != 0);
        bSPrintf_regdst(0x20,local_20,*(int *)(param_1 + 0x9f8) + 1);
        FEObject__SetFormattedText(&DAT_006cc568,local_20);
        if (iVar3 < iVar8) {
          fVar2 = _K_HALF;
          if ((0 < iVar3) &&
             (fVar2 = ((float)iVar8 / (float)iVar3) * *(float *)(unaff_EBX + 0xb4), _K_HALF < fVar2)
             ) {
            fVar2 = _K_HALF;
          }
          if (fVar2 < (float)(DAT_0073ad34 - *(int *)(unaff_EBX + 0xb8)) * 0.00025) {
            *(bool *)(unaff_EBX + 0xbc) = *(char *)(unaff_EBX + 0xbc) == '\0';
            *(int *)(unaff_EBX + 0xb8) = DAT_0073ad34;
            if (*(char *)(unaff_EBX + 0xbc) == '\0') {
              FUN_004f75b0(0xffffff00);
            }
            else {
              FUN_004f75b0(0xff962020);
            }
          }
        }
        else {
          FUN_004f75b0(0xffffff00);
        }
      }
    }
    DriftGauge__UpdateCountdown();
    DriftGauge__UpdateDriftMessage();
    if (((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) &&
       (*(int *)(*(int *)(param_1 + 0x960) + 0x10) == 3)) {
      uVar5 = _ftol_nocw();
      FEObject__SetFormattedText(&DAT_006ca778,uVar5);
      FEObject__SetScript("Highlight",1);
      FEObject__SetScript("Highlight",1);
    }
  }
  return;
}


// ==== 0x4a7920 DriftGauge::SetTrapSpeed

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void DriftGauge__SetTrapSpeed(undefined4 param_1)

{
  int iVar1;
  int unaff_EDI;
  
  if ((*(uint *)(unaff_EDI + 0x18) & *(uint *)(unaff_EDI + 0x10)) != 0 ||
      (*(uint *)(unaff_EDI + 0x1c) & *(uint *)(unaff_EDI + 0x14)) != 0) {
    *(undefined1 *)(unaff_EDI + 0xad) = 1;
    *(undefined4 *)(unaff_EDI + 0xb0) = DAT_0073ad34;
    iVar1 = *(int *)(unaff_EDI + 0x88);
    if (iVar1 != 0) {
      *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
      *(undefined4 *)(iVar1 + 0x5c) = param_1;
      if (DAT_00735710 != (undefined4 *)0x0) {
        (**(code **)*DAT_00735710)(iVar1);
      }
      *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffd | 0x400000;
    }
    FEObject__SetVisible(*(undefined4 *)(unaff_EDI + 0x88));
  }
  return;
}


// ==== 0x4a7990 FUN_004a7990

void FUN_004a7990(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0xa0) < param_2) && (iVar1 = *(int *)(param_1 + 0x70), iVar1 != 0)) {
    for (iVar2 = *(int *)(iVar1 + 0x4c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      iVar3 = FEng__HashName();
      if (*(int *)(iVar2 + 0x30) == iVar3) {
        if (iVar2 != 0) {
          if (iVar2 != *(int *)(iVar1 + 0x54)) {
            *(int *)(iVar1 + 0x54) = iVar2;
            FUN_004ff030(iVar1);
            *(undefined4 *)(*(int *)(iVar1 + 0x54) + 0x10) = 0;
          }
          *(undefined4 *)(iVar2 + 0x10) = 0;
        }
        break;
      }
    }
  }
  FEObject__SetFormattedText(&DAT_006c6d68,param_2);
  *(int *)(param_1 + 0xa0) = param_2;
  return;
}


// ==== 0x4a7a10 DriftGauge::UpdateCountdown

/* [canon] hud high (ghidra-canon+nfsug) docs/re/runtime.md */

void __fastcall DriftGauge__UpdateCountdown(int param_1)

{
  float fVar1;
  
  if (*(float *)(param_1 + 0xa4) <= 0.0) {
    FEObject__SetInvisible();
    return;
  }
  fVar1 = *(float *)(param_1 + 0xa4) - (float)(DAT_0073ad34 - *(int *)(param_1 + 0xa8)) * 0.00025;
  if (fVar1 < 0.0) {
    *(undefined4 *)(param_1 + 0xa4) = 0;
    FEObject__SetInvisible();
    return;
  }
  FEObject__SetFormattedText("%1.1f",(double)fVar1);
  return;
}


// ==== 0x4a7aa0 DriftGauge::UpdateDriftMessage

/* [canon] hud high (ghidra-canon+nfsug) docs/re/runtime.md */

void __fastcall DriftGauge__UpdateDriftMessage(int param_1)

{
  if (*(char *)(param_1 + 0xad) == '\0') {
    FEObject__SetInvisible(*(undefined4 *)(param_1 + 0x88),param_1);
  }
  else if (2.0 < (float)(DAT_0073ad34 - *(int *)(param_1 + 0xb0)) * 0.00025) {
    FEObject__SetInvisible(*(undefined4 *)(param_1 + 0x88));
    return;
  }
  return;
}


// ==== 0x4a7b00 FUN_004a7b00

void FUN_004a7b00(float param_1,float param_2)

{
  int in_EAX;
  undefined4 uVar1;
  
  if (in_EAX == 0) {
    param_1 = 0.0;
  }
  if (param_2 < 0.0) {
    param_1 = 0.0;
  }
  param_1 = ABS(param_1);
  if (90.0 < param_1) {
    param_1 = 90.0;
  }
  uVar1 = _ftol_nocw();
  FEObject__SetFormattedText(&DAT_006ca778,uVar1);
  FUN_004f6a70(param_1 + 90.0);
  return;
}


// ==== 0x4a7b80 FUN_004a7b80

void __fastcall FUN_004a7b80(undefined4 param_1,int param_2,char param_3)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char in_AL;
  char *pcVar4;
  int extraout_EDX;
  int extraout_EDX_00;
  
  if (in_AL != '\0') {
    FEObject__SetVisible(*(undefined4 *)(param_2 + 0x80));
    if ((*(int *)(extraout_EDX + 0x80) != 0) &&
       (iVar3 = *(int *)(*(int *)(extraout_EDX + 0x80) + 0x54), iVar3 != 0)) {
      pcVar4 = "LosingMult";
      do {
        cVar1 = pcVar4[*(int *)(iVar3 + 0x2c) + -0x6c6d5c];
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        if ((cVar1 == '\0') || (cVar2 == '\0')) break;
      } while (cVar1 == cVar2);
      if ((cVar1 == cVar2) && (*(int *)(iVar3 + 0x10) <= *(int *)(iVar3 + 0xc))) {
        return;
      }
    }
    FEObject__SetScript("LosingMult",1);
    return;
  }
  if (param_3 == '\0') {
    FEObject__SetInvisible(*(undefined4 *)(param_2 + 0x80));
    return;
  }
  FEObject__SetVisible(*(undefined4 *)(param_2 + 0x80));
  if ((*(int *)(extraout_EDX_00 + 0x80) != 0) &&
     (iVar3 = *(int *)(*(int *)(extraout_EDX_00 + 0x80) + 0x54), iVar3 != 0)) {
    pcVar4 = "TooSlowToGain";
    do {
      cVar1 = pcVar4[*(int *)(iVar3 + 0x2c) + -0x6c6d4c];
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      if ((cVar1 == '\0') || (cVar2 == '\0')) break;
    } while (cVar1 == cVar2);
    if ((cVar1 == cVar2) && (*(int *)(iVar3 + 0x10) <= *(int *)(iVar3 + 0xc))) {
      return;
    }
  }
  FEObject__SetScript("TooSlowToGain",1);
  return;
}


// ==== 0x4a7c70 FUN_004a7c70

void __fastcall FUN_004a7c70(int param_1)

{
  undefined4 in_EAX;
  
  FUN_004a7990(*(undefined4 *)(param_1 + 0x2c),in_EAX);
  return;
}


// ==== 0x4a7c80 FUN_004a7c80

void FUN_004a7c80(void)

{
  undefined4 in_EAX;
  
  DriftGauge__SetTrapSpeed(in_EAX);
  return;
}


// ==== 0x4a7c90 HudRaceOver::HudRaceOver

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

int HudRaceOver__HudRaceOver(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00687e78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 4;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  local_4 = 0;
  FEng__HashName();
  uVar1 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  FEng__HashName();
  uVar1 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar1);
  uVar1 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar1);
  uVar1 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar1);
  uVar1 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar1);
  *(undefined1 *)(param_1 + 0x28) = 0;
  HudWidget__SetVisible(0,0);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4a7d60 HudRaceOver::Update

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void __fastcall HudRaceOver__Update(undefined4 param_1,int param_2,int param_3)

{
  char cVar1;
  short sVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  char local_40 [32];
  undefined1 local_20 [32];
  
  if ((*(uint *)(param_3 + 0x18) & *(uint *)(param_3 + 0x10)) == 0 &&
      (*(uint *)(param_3 + 0x1c) & *(uint *)(param_3 + 0x14)) == 0) {
    return;
  }
  iVar6 = *(int *)(param_2 + 4);
  if (((DAT_006fbf14 == 0) && (*(int *)(param_2 + 0x10) == 0)) &&
     (iVar4 = RaceManager__FindRacerById(), iVar4 != 0)) {
    iVar6 = iVar4;
  }
  if (*(int *)(iVar6 + 0x1c) == 0) {
    return;
  }
  sVar2 = *(short *)(*(int *)(iVar6 + 0x1c) + 0x10);
  FUN_00586580(local_20);
  if ((*(int *)(param_3 + 0x20) == 0) ||
     (iVar6 = *(int *)(*(int *)(param_3 + 0x20) + 0x54), iVar6 == 0)) {
LAB_004a7e18:
    if (*(char *)(param_3 + 0x28) == '\0') {
      FEObject__SetScript("Animate",1);
      FEObject__SetScript("Animate",1);
      *(undefined1 *)(param_3 + 0x28) = 1;
    }
  }
  else {
    pcVar5 = "Animate";
    do {
      cVar3 = pcVar5[*(int *)(iVar6 + 0x2c) + -0x6c6cbc];
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      if ((cVar3 == '\0') || (cVar1 == '\0')) break;
    } while (cVar3 == cVar1);
    if ((cVar3 != cVar1) || (*(int *)(iVar6 + 0xc) < *(int *)(iVar6 + 0x10))) goto LAB_004a7e18;
  }
  if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
    if (sVar2 == 3) {
      iVar6 = LanguageStrings__FindByHash();
      if (iVar6 == 0) {
        iVar6 = LanguageStrings__FindByHash();
      }
      FEObject__SetFormattedText(&DAT_006cc568,iVar6);
      goto LAB_004a7f31;
    }
  }
  else {
    if (sVar2 == 1) {
      iVar6 = LanguageStrings__FindByHash();
      if (iVar6 == 0) {
        iVar6 = LanguageStrings__FindByHash();
      }
      iVar4 = 0x20;
      pcVar5 = local_40;
      do {
        cVar3 = pcVar5[iVar6 - (int)local_40];
        iVar4 = iVar4 + -1;
        *pcVar5 = cVar3;
        if (cVar3 == '\0') break;
        pcVar5 = pcVar5 + 1;
      } while (iVar4 != 0);
      iVar6 = LanguageStrings__FindByHash();
      if (iVar6 == 0) {
        iVar6 = LanguageStrings__FindByHash();
      }
      FEObject__SetFormattedText("%s\n%s%s  ",iVar6,local_40,local_20);
      goto LAB_004a7f31;
    }
    if ((sVar2 != 6) && (sVar2 != 7)) goto LAB_004a7f31;
  }
  FEString__SetLabelHash();
LAB_004a7f31:
  cVar3 = FUN_0043a2e0();
  if (cVar3 != '\0') {
    if (sVar2 == 9) {
      FEString__SetLabelHash();
      return;
    }
    if (sVar2 == 10) {
      IsFlag7346c8Set();
      FEString__SetLabelHash();
    }
  }
  return;
}


// ==== 0x4a7f90 HudWidget::HudWidget

/* [canon] hud low (ghidra-canon) docs/re/canon.md */

int HudWidget__HudWidget(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00687e78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0x20000;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  local_4 = 0;
  uVar1 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  HudWidget__SetVisible(0,0);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4a8000 FUN_004a8000

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a8000(void)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  int extraout_EDX;
  int unaff_EDI;
  float10 fVar4;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((*(uint *)(unaff_EDI + 0x18) & *(uint *)(unaff_EDI + 0x10)) != 0 ||
      (*(uint *)(unaff_EDI + 0x1c) & *(uint *)(unaff_EDI + 0x14)) != 0) {
    iVar2 = TimedMessage__GetPhase();
    if (iVar2 == 0) {
      FEObject__SetInvisible(*(undefined4 *)(unaff_EDI + 0x20));
      return;
    }
    FEObject__SetVisible(*(undefined4 *)(unaff_EDI + 0x20));
    if (extraout_EDX == 4) {
      FEString__SetLabelHash();
    }
    else {
      FEObject__SetFormattedText(&DAT_006ca778,extraout_EDX);
    }
    fVar4 = (float10)FUN_00434dd0();
    _ftol_nocw();
    FUN_00564b10();
    iVar2 = _ftol_nocw();
    uVar3 = FUN_0049fc90();
    FUN_004f75b0(iVar2 << 0x18 | uVar3 & 0xffffff);
    FUN_004f7260(&local_4,&local_8);
    fVar1 = (float)fVar4 * 2.0 + _K_ONE;
    FUN_004f74f0(fVar1);
    FUN_004f7430(fVar1);
    FUN_004f7140(local_4,local_8);
  }
  return;
}


// ==== 0x4a8140 HudTrackMap::HudTrackMap

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

int HudTrackMap__HudTrackMap(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00687e78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 1;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  local_4 = 0;
  uVar1 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar1);
  uVar1 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar1);
  uVar1 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar1);
  if (((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) && (DAT_0078a320 == 2)) {
    uVar1 = FEng__HashName();
    HudWidget__RegisterObjectByHash(uVar1);
  }
  HudWidget__SetVisible(0,0);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4a8200 HudStylePoints::HudStylePoints

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

int HudStylePoints__HudStylePoints(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00687d13;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0x20000;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  iVar1 = param_1 + 0x20;
  *(int *)iVar1 = iVar1;
  *(int *)(param_1 + 0x24) = iVar1;
  local_4 = 1;
  FEng__HashName();
  uVar2 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x28) = uVar2;
  FEng__HashName();
  uVar2 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x2c) = uVar2;
  FEng__HashName();
  uVar2 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x2c) = uVar2;
  FEng__HashName();
  uVar2 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x34) = uVar2;
  FEng__HashName();
  uVar2 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x38) = uVar2;
  FEng__HashName();
  uVar2 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x3c) = uVar2;
  FEng__HashName();
  uVar2 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x40) = uVar2;
  FEng__HashName();
  HudElement__RegisterImage();
  FEng__HashName();
  HudWidget__RegisterString();
  FEng__HashName();
  HudWidget__RegisterString();
  FEng__HashName();
  HudWidget__RegisterString();
  FEng__HashName();
  HudWidget__RegisterString();
  FEng__HashName();
  HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  uVar2 = FUN_0049fc90();
  *(undefined4 *)(param_1 + 0x4c) = uVar2;
  *(undefined4 *)(param_1 + 0x50) = uVar2;
  FEObject__SetFormattedText(&DAT_006ca778,0);
  *(undefined4 *)(param_1 + 0x54) = param_3;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4a8380 FUN_004a8380

void FUN_004a8380(void)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  int in_EAX;
  
  _Memory = *(int **)(in_EAX + 0x20);
  while (_Memory != (int *)(in_EAX + 0x20)) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = *(int **)(in_EAX + 0x20);
  }
  FUN_00421900();
  return;
}


// ==== 0x4a83c0 HudStylePoints::Update

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void HudStylePoints__Update(void)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  float fVar4;
  int iVar5;
  int unaff_EBX;
  int *_Memory;
  undefined4 uVar6;
  
  if ((*(uint *)(unaff_EBX + 0x18) & *(uint *)(unaff_EBX + 0x10)) != 0 ||
      (*(uint *)(unaff_EBX + 0x1c) & *(uint *)(unaff_EBX + 0x14)) != 0) {
    *(undefined4 *)(unaff_EBX + 0x44) =
         *(undefined4 *)((&DAT_007361b4)[*(int *)(unaff_EBX + 0x54)] + 0x9dc);
    if ((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) {
      iVar5 = *(int *)(*(int *)((&DAT_007361b4)[*(int *)(unaff_EBX + 0x54)] + 0x95c) + 0x2c);
      FEObject__SetInvisible(*(undefined4 *)(iVar5 + 0x90));
      FEObject__SetInvisible(*(undefined4 *)(iVar5 + 0x8c));
      if (*(char *)(iVar5 + 0x40) != '\0') {
        FUN_004a87b0(unaff_EBX,*(undefined4 *)(iVar5 + 0x8c));
        if (*(char *)(iVar5 + 0x41) == '\0') {
          *(undefined1 *)(iVar5 + 0x40) = 0;
          *(undefined4 *)(iVar5 + 0x38) = 0;
        }
        else if (1.0 < (float)(DAT_0073ad34 - *(int *)(iVar5 + 0x38)) * 0.00025) {
          *(undefined1 *)(iVar5 + 0x40) = 0;
          *(undefined4 *)(iVar5 + 0x38) = 0;
          FEObject__SetInvisible(*(undefined4 *)(iVar5 + 0x90));
          FEObject__SetInvisible(*(undefined4 *)(iVar5 + 0x8c));
        }
      }
    }
    piVar3 = *(int **)(unaff_EBX + 0x20);
    piVar1 = (int *)(unaff_EBX + 0x20);
    if (piVar3 == piVar1) {
      FEObject__SetInvisible(*(undefined4 *)(unaff_EBX + 0x3c));
      FEObject__SetInvisible(*(undefined4 *)(unaff_EBX + 0x40));
    }
    else {
      cVar2 = (char)piVar3[2];
      _Memory = piVar3;
      while (cVar2 != '\0') {
        if (_Memory == piVar1) goto LAB_004a84d5;
        _Memory = (int *)*_Memory;
        cVar2 = *(char *)(_Memory + 2);
      }
      if (_Memory == piVar1) {
LAB_004a84d5:
        _Memory = piVar3;
      }
      if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
        uVar6 = *(undefined4 *)(unaff_EBX + 0x3c);
      }
      else {
        uVar6 = 0;
      }
      FUN_004a87b0(unaff_EBX,uVar6);
      iVar5 = 0;
      for (piVar3 = (int *)*piVar1; (piVar3 != piVar1 && (iVar5 = iVar5 + 1, piVar3 != (int *)0x0));
          piVar3 = (int *)*piVar3) {
      }
      if (iVar5 < 2) {
        fVar4 = 1.0;
      }
      else {
        fVar4 = 0.5;
      }
      if ((fVar4 < (float)(DAT_0073ad34 - _Memory[6]) * 0.00025) ||
         (((char)_Memory[2] != '\0' && ((DAT_0078a345 != '\0' || (DAT_007361a4 != 0)))))) {
        iVar5 = *_Memory;
        piVar1 = (int *)_Memory[1];
        *piVar1 = iVar5;
        *(int **)(iVar5 + 4) = piVar1;
        _free(_Memory);
      }
    }
    if (*(float *)(unaff_EBX + 0x48) != *(float *)(unaff_EBX + 0x44)) {
      *(undefined4 *)(unaff_EBX + 0x48) = *(undefined4 *)(unaff_EBX + 0x44);
      uVar6 = _ftol_nocw();
      FEObject__SetFormattedText(&DAT_006ca778,uVar6);
      FEObject__SetScript("Highlight",1);
      FEObject__SetScript("Highlight",1);
    }
  }
  return;
}


// ==== 0x4a85e0 FUN_004a85e0

void FUN_004a85e0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *in_EAX;
  undefined4 *puVar5;
  undefined4 *puVar6;
  void *pvVar7;
  int *piVar8;
  int *piVar9;
  
  piVar1 = (int *)*in_EAX;
  if (piVar1 != in_EAX) {
    puVar5 = (undefined4 *)NullUpdate_ret();
    for (; piVar1 != puVar5; piVar1 = (int *)*piVar1) {
      if (((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) || (piVar1[3] != 0)) {
        piVar8 = *(int **)(param_1 + 0x20);
        piVar9 = (int *)(param_1 + 0x20);
        if (piVar8 != piVar9) {
          for (; piVar8 != piVar9; piVar8 = (int *)*piVar8) {
            if (((piVar8 != (int *)0x0) && (piVar1 != (undefined4 *)0x0)) &&
               ((piVar1[3] == piVar8[5] && ((float)piVar1[8] != 0.0)))) {
              *(bool *)((int)piVar8 + 0x21) = piVar1[4] == 4;
              piVar8[3] = piVar1[8];
              if (piVar1[4] != 3) {
                piVar8[4] = piVar1[6];
              }
              piVar8[6] = 0;
              goto LAB_004a8791;
            }
          }
        }
        if ((float)piVar1[8] != 0.0) {
          if (0.0 <= (float)piVar1[8]) {
            pvVar7 = _malloc(0x24);
            if (pvVar7 == (void *)0x0) {
              puVar6 = (undefined4 *)0x0;
            }
            else {
              puVar6 = (undefined4 *)HudStylePoints__FillMoment();
            }
            puVar4 = *(undefined4 **)(param_1 + 0x24);
            *puVar4 = puVar6;
            *(undefined4 **)(param_1 + 0x24) = puVar6;
            puVar6[1] = puVar4;
            *puVar6 = piVar9;
          }
          else {
            pvVar7 = _malloc(0x24);
            if (pvVar7 == (void *)0x0) {
              iRam00000000 = *piVar9;
              *piVar9 = 0;
              *(undefined4 *)(iRam00000000 + 4) = 0;
              piRam00000004 = piVar9;
            }
            else {
              piVar8 = (int *)HudStylePoints__FillMoment();
              iVar2 = *piVar9;
              *piVar9 = (int)piVar8;
              *(int **)(iVar2 + 4) = piVar8;
              piVar8[1] = (int)piVar9;
              *piVar8 = iVar2;
            }
          }
        }
      }
      else {
        iVar2 = *(int *)(*(int *)((&DAT_007361b4)[*(int *)(param_1 + 0x54)] + 0x95c) + 0x2c);
        uVar3 = *(undefined4 *)(iVar2 + 0x2c);
        puVar6 = (undefined4 *)HudStylePoints__FillMoment();
        *(undefined4 *)(iVar2 + 0x20) = *puVar6;
        *(undefined4 *)(iVar2 + 0x24) = puVar6[1];
        *(undefined1 *)(iVar2 + 0x28) = *(undefined1 *)(puVar6 + 2);
        *(undefined4 *)(iVar2 + 0x2c) = puVar6[3];
        *(undefined4 *)(iVar2 + 0x30) = puVar6[4];
        *(undefined4 *)(iVar2 + 0x34) = puVar6[5];
        *(undefined4 *)(iVar2 + 0x38) = puVar6[6];
        *(undefined4 *)(iVar2 + 0x3c) = puVar6[7];
        *(undefined1 *)(iVar2 + 0x40) = *(undefined1 *)(puVar6 + 8);
        *(undefined1 *)(iVar2 + 0x41) = *(undefined1 *)((int)puVar6 + 0x21);
        *(undefined1 *)(iVar2 + 0x40) = 1;
        *(undefined4 *)(iVar2 + 0x38) = 0;
        if (piVar1[4] == 4) {
          *(undefined4 *)(iVar2 + 0x2c) = uVar3;
          FEObject__SetInvisible(*(undefined4 *)(iVar2 + 0x88));
        }
      }
LAB_004a8791:
    }
  }
  return;
}


// ==== 0x4a87b0 FUN_004a87b0

void FUN_004a87b0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int unaff_ESI;
  int unaff_EDI;
  bool bVar4;
  undefined **ppuVar5;
  
  iVar1 = *(int *)(unaff_ESI + 0x1c);
  bVar4 = iVar1 != -0x5b955158;
  uVar3 = _ftol_nocw();
  if ((*(char *)(unaff_ESI + 0x21) != '\0') || (*(float *)(unaff_ESI + 0xc) < 0.0)) {
    FUN_004f75b0(0xff800000);
    FUN_004f75b0(0xff800000);
    if ((*(int *)(unaff_ESI + 0x10) < 2) || (!bVar4)) {
      FEObject__SetFormattedText(&DAT_006ca778,uVar3);
    }
    else {
      FEObject__SetFormattedText("%dx%d",uVar3,*(int *)(unaff_ESI + 0x10));
    }
LAB_004a8835:
    if ((1 < *(int *)(unaff_ESI + 0x10)) && (bVar4)) {
      FEObject__SetFormattedText("%dx%d",uVar3,*(int *)(unaff_ESI + 0x10));
      goto LAB_004a8926;
    }
    ppuVar5 = (undefined **)&DAT_006ca778;
  }
  else {
    if (((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) && (iVar1 == -0x5b955158)) {
      FUN_004f75b0(*(undefined4 *)(param_1 + 0x50));
      FUN_004f75b0(*(undefined4 *)(param_1 + 0x50));
      goto LAB_004a8835;
    }
    FUN_004f75b0(*(undefined4 *)(param_1 + 0x4c));
    FUN_004f75b0(*(undefined4 *)(param_1 + 0x4c));
    if ((1 < *(int *)(unaff_ESI + 0x10)) && (bVar4)) {
      FEObject__SetFormattedText("%+dx%d",uVar3,*(int *)(unaff_ESI + 0x10));
      goto LAB_004a8926;
    }
    ppuVar5 = &PTR_FUN_006c7228;
  }
  FEObject__SetFormattedText(ppuVar5,uVar3);
LAB_004a8926:
  uVar3 = *(undefined4 *)(unaff_ESI + 0x1c);
  if (unaff_EDI != 0) {
    *(uint *)(unaff_EDI + 0x1c) = *(uint *)(unaff_EDI + 0x1c) | 0x400000;
    puVar2 = DAT_00735710;
    bVar4 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(unaff_EDI + 0x5c) = uVar3;
    if (bVar4) {
      (**(code **)*puVar2)();
    }
    *(uint *)(unaff_EDI + 0x1c) = *(uint *)(unaff_EDI + 0x1c) & 0xfffffffd | 0x400000;
  }
  if (param_2 != 0) {
    FEObject__SetVisible(param_2);
  }
  FEObject__SetVisible();
  if ((*(int *)(unaff_ESI + 0x18) == 0) || (*(int *)(unaff_ESI + 0x18) == 0x7fffffff)) {
    *(undefined1 *)(unaff_ESI + 0x20) = 1;
    *(undefined4 *)(unaff_ESI + 0x18) = DAT_0073ad34;
  }
  return;
}


// ==== 0x4a8990 FUN_004a8990

void FUN_004a8990(void)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00686bdb;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_004a89e0();
  local_4 = 0xffffffff;
  FUN_00421900();
  ExceptionList = local_c;
  return;
}


// ==== 0x4a89e0 FUN_004a89e0

void FUN_004a89e0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *in_EAX;
  int iVar4;
  int *piVar5;
  bool bVar6;
  
  FEObject__SetInvisible(*in_EAX);
  in_EAX[4] = 0;
  in_EAX[3] = 0;
  piVar5 = in_EAX + 5;
  piVar1 = (int *)in_EAX[5];
  while (piVar1 != piVar5) {
    _free(*(void **)(*piVar5 + 8));
    piVar1 = (int *)*piVar5;
    iVar4 = *piVar1;
    piVar2 = (int *)piVar1[1];
    *piVar2 = iVar4;
    *(int **)(iVar4 + 4) = piVar2;
    iVar3 = DAT_007349b4;
    iVar4 = *(int *)(DAT_007349b4 + 0x18);
    *piVar1 = *(int *)(DAT_007349b4 + 0x10);
    *(int **)(iVar3 + 0x10) = piVar1;
    iVar4 = iVar4 + -1;
    bVar6 = DAT_007349b8 != 0;
    *(int *)(iVar3 + 0x18) = iVar4;
    if (bVar6) {
      if (iVar4 == 0) {
        SlotPool__Destroy();
        DAT_007349b4 = 0;
      }
      else {
        DAT_007349b8 = 1;
      }
    }
    piVar1 = (int *)*piVar5;
  }
  return;
}


// ==== 0x4a8a70 FUN_004a8a70

void FUN_004a8a70(undefined4 param_1)

{
  void *_Memory;
  int *piVar1;
  int iVar2;
  undefined4 *unaff_ESI;
  
  if ((unaff_ESI[4] == 0) || (unaff_ESI[4] == 0x7fffffff)) {
LAB_004a8a92:
    iVar2 = unaff_ESI[3];
    if (iVar2 < 1) goto LAB_004a8ae2;
    _Memory = *(void **)(unaff_ESI[5] + 8);
    FEObject__SetFormattedText(_Memory);
    iVar2 = _ftol_nocw();
    unaff_ESI[4] = iVar2;
    _free(_Memory);
    iVar2 = *(int *)unaff_ESI[5];
    piVar1 = (int *)((int *)unaff_ESI[5])[1];
    *piVar1 = iVar2;
    *(int **)(iVar2 + 4) = piVar1;
    FUN_0041f570();
    unaff_ESI[3] = unaff_ESI[3] + -1;
  }
  else {
    iVar2 = FUN_00586640(param_1);
    if (iVar2 == 0) goto LAB_004a8a92;
  }
  iVar2 = unaff_ESI[3];
LAB_004a8ae2:
  if ((iVar2 == 0) && ((iVar2 = unaff_ESI[4], iVar2 == 0 || (iVar2 == 0x7fffffff)))) {
    FEObject__SetInvisible(*unaff_ESI);
    return;
  }
  FEObject__SetVisible(*unaff_ESI);
  return;
}


// ==== 0x4a8b10 FUN_004a8b10

void FUN_004a8b10(void)

{
  int iVar1;
  char cVar2;
  char *in_EAX;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int unaff_EBX;
  
  if (*(int *)(unaff_EBX + 0xc) == *(int *)(unaff_EBX + 8)) {
    *(undefined4 *)(unaff_EBX + 0x10) = 0;
    FUN_004a8a70(0);
  }
  iVar3 = 0;
  if (in_EAX != (char *)0x0) {
    cVar2 = *in_EAX;
    while (cVar2 != '\0') {
      iVar1 = iVar3 + 1;
      iVar3 = iVar3 + 1;
      cVar2 = in_EAX[iVar1];
    }
  }
  pcVar4 = _malloc(iVar3 + 1);
  cVar2 = *in_EAX;
  *pcVar4 = cVar2;
  if (cVar2 != '\0') {
    pcVar5 = pcVar4;
    do {
      cVar2 = pcVar5[(int)(in_EAX + (1 - (int)pcVar4))];
      pcVar5 = pcVar5 + 1;
      *pcVar5 = cVar2;
    } while (cVar2 != '\0');
  }
  HudWidget__RegisterObject(pcVar4);
  *(int *)(unaff_EBX + 0xc) = *(int *)(unaff_EBX + 0xc) + 1;
  return;
}


// ==== 0x4a8b80 HudOnline::HudOnline

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

int HudOnline__HudOnline(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00687e78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0x4000;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  local_4 = 0;
  *(undefined4 *)(param_1 + 0x20) = param_2;
  FEng__HashName();
  uVar2 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x24) = uVar2;
  FEng__HashName();
  uVar2 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x28) = uVar2;
  FEObject__SetInvisible(*(undefined4 *)(param_1 + 0x24));
  FEObject__SetInvisible(*(undefined4 *)(param_1 + 0x28));
  puVar3 = _malloc(0x1c);
  if (puVar3 == (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x24);
    puVar3[4] = 0;
    puVar1 = puVar3 + 5;
    *puVar1 = puVar1;
    puVar3[6] = puVar1;
    puVar3[3] = 0;
    puVar3[2] = 4;
    *puVar3 = uVar2;
    puVar3[1] = 0x3fc00000;
    puVar3[4] = 0;
    *(undefined4 **)(param_1 + 0x2c) = puVar3;
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4a8c50 FUN_004a8c50

void FUN_004a8c50(int param_1)

{
  void *_Memory;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00687e78;
  local_c = ExceptionList;
  _Memory = *(void **)(param_1 + 0x2c);
  local_4 = 0;
  ExceptionList = &local_c;
  if (_Memory != (void *)0x0) {
    ExceptionList = &local_c;
    FUN_004a8990(_Memory);
    _free(_Memory);
  }
  local_4 = 0xffffffff;
  FUN_00421900();
  ExceptionList = local_c;
  return;
}


// ==== 0x4a8cb0 HudOnline::Update

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void HudOnline__Update(void)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  float10 fVar6;
  
  piVar1 = DAT_0077b244;
  fVar6 = (float10)Race__GetClockSeconds();
  if (fVar6 < (float10)0.0) {
    FEObject__SetInvisible();
  }
  else {
    fVar6 = (float10)Race__GetClockSeconds();
    FEObject__SetVisible();
    FEObject__SetFormattedText("%1.1f",(double)(float)fVar6);
    iVar4 = *piVar1;
    if ((((iVar4 != 3) && (iVar4 != 4)) && (iVar4 != 5)) && ((iVar4 != 0 && (iVar4 != 6)))) {
      uVar2 = _ftol_nocw();
      uVar3 = uVar2 & 0x80000001;
      bVar5 = uVar3 == 0;
      if ((int)uVar3 < 0) {
        bVar5 = (uVar3 - 1 | 0xfffffffe) == 0xffffffff;
      }
      if ((bVar5) && (ABS((float)fVar6 - (float)(int)uVar2) < DAT_0073457c)) {
        iVar4 = LanguageStrings__FindByHash();
        if (iVar4 == 0) {
          LanguageStrings__FindByHash();
        }
        FUN_004a8b10();
      }
    }
  }
  FUN_004a8a70();
  return;
}


// ==== 0x4a8d90 FUN_004a8d90

void FUN_004a8d90(int param_1)

{
  int iVar1;
  
  if (*(int *)(*(int *)(DAT_007361b4 + 0x95c) + 0x54) != 0) {
    iVar1 = LanguageStrings__FindByHash();
    if (iVar1 == 0) {
      iVar1 = LanguageStrings__FindByHash();
    }
    bSPrintf_regdst(0x100,iVar1,param_1 + 0x19);
    FUN_004a8b10();
  }
  return;
}


// ==== 0x4a8e00 FUN_004a8e00

void FUN_004a8e00(void)

{
  int iVar1;
  
  if (*(int *)(*(int *)(DAT_007361b4 + 0x95c) + 0x54) != 0) {
    iVar1 = LanguageStrings__FindByHash();
    if (iVar1 == 0) {
      LanguageStrings__FindByHash();
    }
    FUN_004a8b10();
  }
  return;
}


// ==== 0x4a8e40 HudManager::HudManager

/* [canon] hud high (ghidra+hopper+capstone) docs/re/hud_input.md */

void __thiscall HudManager__HudManager(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 *unaff_ESI;
  bool bVar6;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  iVar3 = DAT_0073578c;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688456;
  local_c = ExceptionList;
  bVar6 = DAT_0073578c != 0;
  ExceptionList = &local_c;
  *unaff_ESI = &PTR_FUN_006c65c0;
  unaff_ESI[4] = param_1;
  unaff_ESI[5] = param_2;
  if (bVar6) {
    iVar1 = *(int *)(iVar3 + 8);
    iVar3 = iVar1 + 0xdc;
    if (iVar3 != 0) {
      iVar3 = FUN_004fd1e0(iVar3);
      if (iVar3 != 0) goto LAB_004a8ea2;
    }
    cFEng__PushPackage(iVar1,param_1,0x10,0);
  }
LAB_004a8ea2:
  if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
    FUN_004f6a10(param_1,0);
  }
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[6] = 0;
  unaff_ESI[7] = 0;
  unaff_ESI[0xe] = 0;
  unaff_ESI[0x11] = 0;
  unaff_ESI[8] = 0;
  unaff_ESI[9] = 0;
  unaff_ESI[10] = 0;
  unaff_ESI[0xb] = 0;
  unaff_ESI[0xc] = 0;
  unaff_ESI[0xd] = 0;
  unaff_ESI[0xf] = 0;
  unaff_ESI[0x10] = 0;
  unaff_ESI[0x12] = 0;
  unaff_ESI[0x13] = 0;
  unaff_ESI[0x14] = 0;
  unaff_ESI[0x15] = 0;
  unaff_ESI[0x16] = 0;
  if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
    pvVar4 = _malloc(0xa0);
    local_4 = 2;
    if (pvVar4 == (void *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = HudTach__HudTach(pvVar4,param_1,param_2);
    }
    unaff_ESI[6] = uVar5;
    pvVar4 = _malloc(0x210);
    local_4 = 3;
  }
  else {
    pvVar4 = _malloc(0xa8);
    local_4 = 0;
    if (pvVar4 == (void *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = HudTachDrag__HudTachDrag(pvVar4,param_1,param_2);
    }
    unaff_ESI[0xe] = uVar5;
    pvVar4 = _malloc(0x210);
    local_4 = 1;
  }
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = HudLeaderboard__HudLeaderboard(pvVar4,param_1,param_2);
  }
  unaff_ESI[0x11] = uVar5;
  pvVar4 = _malloc(0x48);
  local_4 = 4;
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = HudTurbo__HudTurbo(pvVar4,param_1,param_2);
  }
  unaff_ESI[7] = uVar5;
  pvVar4 = _malloc(0x48);
  local_4 = 5;
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = HudPosition__HudPosition(pvVar4,param_1,param_2);
  }
  unaff_ESI[8] = uVar5;
  pvVar4 = _malloc(0x58);
  local_4 = 6;
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = HudEngineHeat__HudEngineHeat(pvVar4,param_1,param_2);
  }
  unaff_ESI[9] = uVar5;
  pvVar4 = _malloc(0x68);
  local_4 = 7;
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = HudNos__HudNos(pvVar4,param_1,param_2);
  }
  unaff_ESI[10] = uVar5;
  pvVar4 = _malloc(0xc0);
  local_4 = 8;
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = HudSpeedTrapDrift__HudSpeedTrapDrift(pvVar4,param_1,param_2);
  }
  unaff_ESI[0xb] = uVar5;
  pvVar4 = _malloc(0x30);
  local_4 = 9;
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = HudRaceOver__HudRaceOver(pvVar4,param_1,param_2);
  }
  unaff_ESI[0xc] = uVar5;
  pvVar4 = _malloc(0x58);
  local_4 = 10;
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = HudSmokeApplause__HudSmokeApplause(pvVar4,param_1,param_2);
  }
  unaff_ESI[0xd] = uVar5;
  pvVar4 = _malloc(0x20);
  local_4 = 0xb;
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = HudTrackMap__HudTrackMap(pvVar4,param_1,param_2);
  }
  unaff_ESI[0xf] = uVar5;
  pvVar4 = _malloc(0x50);
  local_4 = 0xc;
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = HudLapCounter__HudLapCounter(pvVar4,param_1,param_2);
  }
  unaff_ESI[0x10] = uVar5;
  pvVar4 = _malloc(0x30);
  local_4 = 0xd;
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = HudWrongWay__HudWrongWay(pvVar4,param_1,param_2);
  }
  unaff_ESI[0x12] = uVar5;
  pvVar4 = _malloc(0x48);
  local_4 = 0xe;
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = HudSplitTime__HudSplitTime(pvVar4,param_1,param_2);
  }
  unaff_ESI[0x13] = uVar5;
  pvVar4 = _malloc(0x58);
  local_4 = 0xf;
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = HudStylePoints__HudStylePoints(pvVar4,param_1,param_2);
  }
  unaff_ESI[0x14] = uVar5;
  pvVar4 = _malloc(0x28);
  local_4 = 0x10;
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = HudWidget__HudWidget(pvVar4,param_1,param_2);
  }
  local_4 = 0xffffffff;
  unaff_ESI[0x16] = uVar5;
  cVar2 = FUN_0043a2e0();
  if (cVar2 == '\0') {
    uVar5 = FEng_FindObjectByHash();
    FEObject__SetInvisible(uVar5);
    uVar5 = FEng_FindObjectByHash();
    FEObject__SetInvisible(uVar5);
  }
  else {
    pvVar4 = _malloc(0x30);
    local_4 = 0x11;
    if (pvVar4 == (void *)0x0) {
      local_4 = 0xffffffff;
      unaff_ESI[0x15] = 0;
    }
    else {
      uVar5 = HudOnline__HudOnline(pvVar4,param_1);
      local_4 = 0xffffffff;
      unaff_ESI[0x15] = uVar5;
    }
  }
  HudManager__SetFlags(unaff_ESI,0xffffffff,0);
  HudManager__SetFlags(unaff_ESI,0,0);
  ExceptionList = local_c;
  return;
}


// ==== 0x4a9270 FUN_004a9270

void * __thiscall FUN_004a9270(void *param_1,byte param_2)

{
  FUN_004a9290();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4a9290 FUN_004a9290

undefined4 __fastcall FUN_004a9290(undefined4 *param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  pvVar1 = (void *)param_1[6];
  *param_1 = &PTR_FUN_006c65c0;
  if (pvVar1 != (void *)0x0) {
    thunk_FUN_00421900();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[7];
  if (pvVar1 != (void *)0x0) {
    thunk_FUN_00421900();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[8];
  if (pvVar1 != (void *)0x0) {
    thunk_FUN_00421900();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[0xe];
  if (pvVar1 != (void *)0x0) {
    thunk_FUN_00421900();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[9];
  if (pvVar1 != (void *)0x0) {
    thunk_FUN_00421900();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[10];
  if (pvVar1 != (void *)0x0) {
    thunk_FUN_00421900();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[0xb];
  if (pvVar1 != (void *)0x0) {
    thunk_FUN_00421900();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[0xc];
  if (pvVar1 != (void *)0x0) {
    thunk_FUN_00421900();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[0xd];
  if (pvVar1 != (void *)0x0) {
    thunk_FUN_00421900();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[0xf];
  if (pvVar1 != (void *)0x0) {
    thunk_FUN_00421900();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[0x10];
  if (pvVar1 != (void *)0x0) {
    thunk_FUN_00421900();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[0x11];
  if (pvVar1 != (void *)0x0) {
    thunk_FUN_00421900();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[0x12];
  if (pvVar1 != (void *)0x0) {
    thunk_FUN_00421900();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[0x13];
  if (pvVar1 != (void *)0x0) {
    thunk_FUN_00421900();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[0x14];
  if (pvVar1 != (void *)0x0) {
    FUN_004a8380();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[0x15];
  if (pvVar1 != (void *)0x0) {
    FUN_004a8c50(pvVar1);
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[0x16];
  if (pvVar1 != (void *)0x0) {
    thunk_FUN_00421900();
    _free(pvVar1);
  }
  iVar2 = DAT_0073578c;
  uVar4 = param_1[4];
  if (DAT_0073578c != 0) {
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    uVar4 = 0;
    if ((iVar3 != 0) && (uVar4 = 0, *(int *)(iVar3 + 0x18) != 0)) {
      uVar4 = cFEng__PopPackage(*(undefined4 *)(iVar2 + 8),*(int *)(iVar3 + 0x18));
    }
  }
  return uVar4;
}


// ==== 0x4a9440 HudManager::Update

/* [canon] hud high (ghidra+hopper+capstone) docs/re/hud_input.md */

void HudManager__Update(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x18) != 0) {
    HudTach__Update(param_2);
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    HudTurbo__Update();
  }
  if (*(int *)(param_1 + 0x38) != 0) {
    HudTachDrag__Update(*(int *)(param_1 + 0x38),param_2);
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    HudPosition__Update(param_2);
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    HudEngineHeat__Update();
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    HudNos__Update();
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    HudSpeedTrapDrift__Update(param_2);
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    HudRaceOver__Update(*(int *)(param_1 + 0x30));
  }
  if (*(int *)(param_1 + 0x34) != 0) {
    HudSmokeApplause__Update(param_2);
  }
  if (*(int *)(param_1 + 0x40) != 0) {
    HudLapCounter__Update(param_2);
  }
  if (*(int *)(param_1 + 0x44) != 0) {
    HudLeaderboard__Update();
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    HudWrongWay__Update(*(int *)(param_1 + 0x48),param_2);
  }
  if (*(int *)(param_1 + 0x4c) != 0) {
    HudSplitTime__Update(param_2);
  }
  if (*(int *)(param_1 + 0x50) != 0) {
    HudStylePoints__Update(param_2);
  }
  if (*(int *)(param_1 + 0x54) != 0) {
    HudOnline__Update(param_2);
  }
  if (*(int *)(param_1 + 0x58) != 0) {
    FUN_004a8000(param_2);
  }
  return;
}


// ==== 0x4a9540 HudManager::SetFlags

/* [canon] hud high (ghidra+hopper+capstone) docs/re/hud_input.md */

void __fastcall
HudManager__SetFlags(undefined4 param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  
  uVar4 = param_4 & 0xfdfbffff;
  uVar3 = *(uint *)(param_3 + 0xc) ^ param_5;
  uVar2 = *(uint *)(param_3 + 8) ^ uVar4;
  if ((param_2 != 0) && ((uVar2 & 0x1000) != 0)) {
    Player__SetRearViewMirrorCameraMover(param_4 & 0x1000);
  }
  if ((*(int *)(param_3 + 0x18) != 0) && ((uVar2 & 0x40) != 0)) {
    HudWidget__SetVisible(uVar4,param_5);
  }
  if ((*(int *)(param_3 + 0x1c) != 0) && ((uVar2 & 0x40) != 0)) {
    HudWidget__SetVisible(uVar4,param_5);
  }
  if ((*(int *)(param_3 + 0x38) != 0) && ((uVar2 & 0x40) != 0)) {
    HudWidget__SetVisible(uVar4,param_5);
  }
  if ((*(int *)(param_3 + 0x20) != 0) && ((uVar2 & 0x200) != 0)) {
    HudWidget__SetVisible(uVar4,param_5);
  }
  if ((*(int *)(param_3 + 0x24) != 0) && ((uVar2 & 0x20000000) != 0)) {
    HudWidget__SetVisible(uVar4,param_5);
  }
  if ((*(int *)(param_3 + 0x28) != 0) && ((uVar3 & 0x40000) != 0)) {
    HudWidget__SetVisible(uVar4,param_5);
  }
  if ((*(int *)(param_3 + 0x2c) != 0) && ((uVar2 & 0x80000000) != 0)) {
    HudWidget__SetVisible(uVar4,param_5);
  }
  if ((*(int *)(param_3 + 0x30) != 0) && ((uVar2 & 4) != 0)) {
    HudWidget__SetVisible(uVar4,param_5);
  }
  if ((*(int *)(param_3 + 0x34) != 0) && ((uVar2 & 0x10000) != 0)) {
    HudWidget__SetVisible(uVar4,param_5);
  }
  if ((*(int *)(param_3 + 0x3c) != 0) && ((uVar2 & 1) != 0)) {
    HudWidget__SetVisible(uVar4,param_5);
  }
  if ((*(int *)(param_3 + 0x40) != 0) && ((uVar2 & 0x400) != 0)) {
    HudWidget__SetVisible(uVar4,param_5);
  }
  if ((*(int *)(param_3 + 0x44) != 0) && ((uVar2 & 0x800000) != 0)) {
    HudWidget__SetVisible(uVar4,param_5);
  }
  if ((param_4 & 0x800000) == 0) {
    FEng__HashName("Leaderboard_Off");
    cVar1 = FUN_004f6c80();
    if (cVar1 != '\0') goto LAB_004a976e;
    pcVar5 = "Leaderboard_Off";
  }
  else {
    FEng__HashName(&DAT_006c7a3c);
    cVar1 = FUN_004f6c80();
    if (cVar1 != '\0') goto LAB_004a976e;
    pcVar5 = "Init";
  }
  FEng__HashName(pcVar5,1);
  FUN_004f6c30();
LAB_004a976e:
  if ((*(int *)(param_3 + 0x4c) != 0) && ((uVar2 & 0x80) != 0)) {
    HudWidget__SetVisible(uVar4,param_5);
  }
  if ((*(int *)(param_3 + 0x50) != 0) && ((uVar2 & 0x20000) != 0)) {
    HudWidget__SetVisible(uVar4,param_5);
  }
  if ((*(int *)(param_3 + 0x48) != 0) && ((uVar2 & 0x4000) != 0)) {
    HudWidget__SetVisible(uVar4,param_5);
  }
  if ((*(int *)(param_3 + 0x58) != 0) && ((uVar3 & 0x20000) != 0)) {
    HudWidget__SetVisible(uVar4,param_5);
  }
  *(uint *)(param_3 + 8) = uVar4;
  *(uint *)(param_3 + 0xc) = param_5;
  return;
}


// ==== 0x4a9810 FUN_004a9810

void __thiscall FUN_004a9810(float *param_1,int *param_2,float param_3)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  
  iVar1 = param_2[1];
  if (iVar1 < 2) {
    if (iVar1 < 1) {
      return;
    }
    pfVar3 = (float *)(*param_2 + 4);
  }
  else {
    pfVar3 = (float *)*param_2;
    if (param_3 < *pfVar3 != (param_3 == *pfVar3)) {
      *param_1 = pfVar3[1];
      param_1[1] = pfVar3[2];
      param_1[2] = pfVar3[3];
      param_1[3] = pfVar3[4];
      return;
    }
    if (param_3 < pfVar3[iVar1 * 5 + -5]) {
      iVar2 = 0;
      pfVar4 = pfVar3;
      if (iVar1 + -1 < 1) {
        return;
      }
      while ((param_3 < *pfVar4 || (pfVar4[5] <= param_3))) {
        iVar2 = iVar2 + 1;
        pfVar4 = pfVar4 + 5;
        if (iVar1 + -1 <= iVar2) {
          return;
        }
      }
      FUN_004a4900(param_2,(param_3 - pfVar3[iVar2 * 5]) /
                           ((pfVar3 + iVar2 * 5)[5] - pfVar3[iVar2 * 5]));
      return;
    }
    pfVar3 = pfVar3 + iVar1 * 5 + -4;
  }
  *param_1 = *pfVar3;
  param_1[1] = pfVar3[1];
  param_1[2] = pfVar3[2];
  param_1[3] = pfVar3[3];
  return;
}


// ==== 0x4a9900 HudWidget::RegisterObject

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void HudWidget__RegisterObject(int param_1)

{
  int *piVar1;
  int *piVar2;
  int unaff_ESI;
  
  if (DAT_007349b4 == 0) {
    FUN_005649f0();
  }
  piVar2 = (int *)FUN_00567160();
  if (piVar2 != (int *)0x0) {
    piVar2[2] = param_1;
    piVar1 = *(int **)(unaff_ESI + 4);
    *piVar1 = (int)piVar2;
    *(int **)(unaff_ESI + 4) = piVar2;
    piVar2[1] = (int)piVar1;
    *piVar2 = unaff_ESI;
    return;
  }
  puRam00000004 = *(undefined4 **)(unaff_ESI + 4);
  *puRam00000004 = 0;
  *(undefined4 *)(unaff_ESI + 4) = 0;
  iRam00000000 = unaff_ESI;
  return;
}


// ==== 0x4a9950 FUN_004a9950

undefined4 FUN_004a9950(void)

{
  return DAT_0073616c;
}


// ==== 0x4a9960 FUN_004a9960

void __fastcall FUN_004a9960(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c6434;
  return;
}


// ==== 0x4a9970 FUN_004a9970

undefined4 * __thiscall FUN_004a9970(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006c6434;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4a9990 FUN_004a9990

void __fastcall FUN_004a9990(undefined4 *param_1)

{
  undefined4 *in_EAX;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  *in_EAX = *param_1;
  in_EAX[1] = param_1[1];
  in_EAX[2] = param_1[2];
  in_EAX[3] = param_1[3];
  in_EAX[4] = param_1[4];
  in_EAX[5] = param_1[5];
  in_EAX[6] = param_1[6];
  in_EAX[7] = param_1[7];
  puVar2 = in_EAX + 8;
  iVar1 = (int)param_1 - (int)in_EAX;
  iVar3 = 0xb;
  do {
    *puVar2 = *(undefined4 *)(iVar1 + (int)puVar2);
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar2 = in_EAX + 0x13;
  iVar3 = 0xb;
  do {
    *puVar2 = *(undefined4 *)((int)puVar2 + iVar1);
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  in_EAX[0x1e] = param_1[0x1e];
  in_EAX[0x1f] = param_1[0x1f];
  in_EAX[0x20] = param_1[0x20];
  in_EAX[0x21] = param_1[0x21];
  in_EAX[0x22] = param_1[0x22];
  in_EAX[0x23] = param_1[0x23];
  in_EAX[0x24] = param_1[0x24];
  in_EAX[0x25] = param_1[0x25];
  in_EAX[0x26] = param_1[0x26];
  in_EAX[0x27] = param_1[0x27];
  in_EAX[0x28] = param_1[0x28];
  in_EAX[0x29] = param_1[0x29];
  in_EAX[0x2a] = param_1[0x2a];
  in_EAX[0x2b] = param_1[0x2b];
  in_EAX[0x2c] = param_1[0x2c];
  in_EAX[0x2d] = param_1[0x2d];
  in_EAX[0x2e] = param_1[0x2e];
  in_EAX[0x2f] = param_1[0x2f];
  in_EAX[0x30] = param_1[0x30];
  in_EAX[0x31] = param_1[0x31];
  puVar2 = in_EAX + 0x32;
  iVar3 = 0xb;
  do {
    *puVar2 = *(undefined4 *)((int)puVar2 + iVar1);
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar2 = in_EAX + 0x3d;
  iVar3 = 0xb;
  do {
    *puVar2 = *(undefined4 *)((int)puVar2 + iVar1);
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  in_EAX[0x48] = param_1[0x48];
  in_EAX[0x49] = param_1[0x49];
  in_EAX[0x4a] = param_1[0x4a];
  in_EAX[0x4b] = param_1[0x4b];
  in_EAX[0x4c] = param_1[0x4c];
  in_EAX[0x4d] = param_1[0x4d];
  in_EAX[0x4e] = param_1[0x4e];
  in_EAX[0x4f] = param_1[0x4f];
  in_EAX[0x50] = param_1[0x50];
  in_EAX[0x51] = param_1[0x51];
  in_EAX[0x52] = param_1[0x52];
  in_EAX[0x53] = param_1[0x53];
  in_EAX[0x54] = param_1[0x54];
  in_EAX[0x55] = param_1[0x55];
  in_EAX[0x56] = param_1[0x56];
  return;
}


// ==== 0x4a9bc0 FUN_004a9bc0

int FUN_004a9bc0(int param_1)

{
  int iVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006859b6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004aa200();
  local_4 = 0;
  eh_vector_constructor_iterator((void *)(param_1 + 0xf954),0xf944,2,FUN_004aa200,FUN_004a9d60);
  *(undefined4 *)(param_1 + 0x2ebf0) = 0xae83b9db;
  *(undefined4 *)(param_1 + 0x2ebf4) = 0x6a97b51f;
  *(undefined4 *)(param_1 + 0x2ebf8) = 0xceffd44;
  *(undefined4 *)(param_1 + 0x2ec00) = 0;
  *(undefined1 *)(param_1 + 0x2ec04) = 0;
  iVar1 = 8;
  *(undefined4 *)(param_1 + 0x2ebfc) = 8;
  local_4 = CONCAT31(local_4._1_3_,1);
  *(undefined4 *)(param_1 + 0x2eca0) = 0;
  *(undefined4 *)(param_1 + 0x2eca4) = 0x18ed8cac;
  *(undefined4 *)(param_1 + 0x2eca8) = 0x9c7511d8;
  *(undefined4 *)(param_1 + 0x2ecac) = 0;
  *(undefined4 *)(param_1 + 0x2ecb0) = 0;
  *(undefined4 *)(param_1 + 0x2ecb4) = 0;
  *(undefined4 *)(param_1 + 0x2ecb8) = 0;
  *(undefined4 *)(param_1 + 0x2ecbc) = 0;
  do {
    FUN_00438860();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined4 *)(param_1 + 0x2f914) = 1;
  *(undefined4 *)(param_1 + 0x2f918) = 1;
  *(undefined1 *)(param_1 + 0x2f844) = 0;
  *(undefined1 *)(param_1 + 0x2f855) = 0;
  *(undefined1 *)(param_1 + 0x2f877) = 0;
  *(undefined1 *)(param_1 + 0x2f866) = 0;
  *(undefined1 *)(param_1 + 0x2f8aa) = 0;
  *(undefined1 *)(param_1 + 0x2f920) = 0;
  *(undefined4 *)(param_1 + 0x2f924) = 0;
  *(undefined1 *)(param_1 + 0x2f910) = 1;
  *(undefined1 *)(param_1 + 0x2f911) = 1;
  *(undefined4 *)(param_1 + 0x2f91c) = 0x7d3;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4a9d00 FUN_004a9d00

void FUN_004a9d00(int param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684f8b;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  eh_vector_destructor_iterator((void *)(param_1 + 0xf954),0xf944,2,FUN_004a9d60);
  local_4 = 0xffffffff;
  Career___Career(param_1 + 0x6644);
  ExceptionList = local_c;
  return;
}


// ==== 0x4a9d60 FUN_004a9d60

void __fastcall FUN_004a9d60(int param_1)

{
  Career___Career(param_1 + 0x6634);
  return;
}


// ==== 0x4a9d70 Career::_Career

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void Career___Career(int param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684f6e;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  eh_vector_destructor_iterator((void *)(param_1 + 0x13a8),0x454,0x1b,NullUpdate_ret);
  *(undefined ***)(param_1 + 0x44c) = &PTR_FUN_006c6434;
  ExceptionList = local_c;
  return;
}


// ==== 0x4a9dd0 Opt::ResetGeneralBlock

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

undefined1 * __fastcall Opt__ResetGeneralBlock(undefined1 *param_1)

{
  int iVar1;
  bool bVar2;
  
  param_1[1] = 1;
  param_1[2] = 1;
  param_1[3] = 1;
  param_1[4] = 1;
  param_1[5] = 1;
  param_1[6] = 1;
  param_1[7] = 1;
  param_1[8] = 1;
  param_1[9] = 1;
  param_1[10] = 1;
  *(undefined4 *)(param_1 + 0x18) = 1;
  bVar2 = DAT_006ee6f0 != 0;
  *param_1 = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0x3f000000;
  *(uint *)(param_1 + 0x1c) = (uint)bVar2;
  iVar1 = DAT_006fa5b4 / 2;
  *(int *)(param_1 + 0x20) = iVar1;
  *(int *)(param_1 + 0x24) = iVar1;
  return param_1;
}


// ==== 0x4a9e30 HighScoresDatabase::FindHighScore

/* [canon] canon high (ghidra-canon+nfsug) docs/re/canon.md */

int __fastcall HighScoresDatabase__FindHighScore(undefined4 param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar2 = 0;
  pcVar1 = (char *)(param_2 + 2);
  while (((*(short *)(pcVar1 + -2) != unaff_EBX || (pcVar1[1] != unaff_EDI)) ||
         (*pcVar1 != unaff_ESI))) {
    iVar2 = iVar2 + 1;
    pcVar1 = pcVar1 + 8;
    if (0x13f < iVar2) {
      return 0;
    }
  }
  return param_2 + iVar2 * 8;
}


// ==== 0x4a9e70 FUN_004a9e70

undefined1 FUN_004a9e70(int param_1,undefined1 param_2,undefined1 param_3,int param_4)

{
  undefined2 in_AX;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined8 uVar5;
  
  uVar5 = HighScoresDatabase__FindHighScore();
  iVar3 = (int)((ulonglong)uVar5 >> 0x20);
  puVar4 = (undefined2 *)uVar5;
  if (puVar4 == (undefined2 *)0x0) {
    iVar1 = 0;
    while (*(short *)(iVar3 + iVar1 * 8) != 0) {
      iVar1 = iVar1 + 1;
      if (0x13f < iVar1) {
        return 0;
      }
    }
    puVar4 = (undefined2 *)(iVar3 + iVar1 * 8);
    if (puVar4 == (undefined2 *)0x0) {
      return 0;
    }
    if (param_1 == 2) {
      if (*(float *)(param_4 + 0xbc) < 0.0) {
        return 0;
      }
    }
    else {
      if (*(int *)(param_4 + 0x10) == 0) {
        return 0;
      }
      if (*(int *)(param_4 + 0x10) == 0x7fffffff) {
        return 0;
      }
      if ((float)*(int *)(param_4 + 0x10) * 0.00025 == 0.0) {
        return 0;
      }
    }
    *puVar4 = in_AX;
    *(undefined1 *)((int)puVar4 + 3) = param_2;
    *(undefined1 *)(puVar4 + 1) = param_3;
  }
  else if (param_1 == 2) {
    if (*(float *)(param_4 + 0xbc) <= (float)*(int *)(puVar4 + 2)) {
      return 0;
    }
  }
  else {
    iVar3 = *(int *)(param_4 + 0x10);
    if (iVar3 == 0) {
      return 0;
    }
    if (iVar3 == 0x7fffffff) {
      return 0;
    }
    if (*(int *)(puVar4 + 2) <= iVar3) {
      return 0;
    }
  }
  if (param_1 != 2) {
    iVar3 = *(int *)(param_4 + 0x10);
    if ((iVar3 != 0) && (iVar3 != 0x7fffffff)) {
      *(int *)(puVar4 + 2) = iVar3;
    }
    return 1;
  }
  uVar2 = _ftol_nocw();
  *(undefined4 *)(puVar4 + 2) = uVar2;
  return 1;
}


// ==== 0x4a9fd0 FUN_004a9fd0

void __fastcall
FUN_004a9fd0(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  int *piVar1;
  int *piVar2;
  int *in_EAX;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  if ((DAT_00777b4c == 1) && (*(int *)(DAT_00777ccc + 0x58a0) == 0)) {
    return;
  }
  iVar7 = *in_EAX;
  uVar5 = (uint)(iVar7 == 1);
  if (param_1 != -1) {
    piVar2 = (int *)(param_2 + 0xa18 + param_1 * 0xc);
    FUN_004960a0();
    iVar3 = _ftol_nocw();
    piVar1 = (int *)(param_2 + (param_1 * 3 + 0x285) * 4);
    iVar6 = *piVar1;
    *piVar2 = *piVar2 + iVar3;
    *piVar1 = iVar6 + uVar5;
    if ((param_1 == 1) && (in_EAX[2] == 7)) {
      *(int *)(param_2 + 0xa4c) = *(int *)(param_2 + 0xa4c) + 1;
    }
  }
  if (param_6 != 0) {
    FUN_004960a0();
    uVar4 = _ftol_nocw();
    *(undefined4 *)(param_2 + 0xa48) = uVar4;
    *(uint *)(param_2 + 0xa44) = uVar5;
  }
  *(float *)(param_2 + 0xa00) = (float)in_EAX[0x2b] + *(float *)(param_2 + 0xa00);
  *(uint *)(param_2 + 0xa08) = *(int *)(param_2 + 0xa08) + (uint)(*in_EAX == 1);
  *(uint *)(param_2 + 0xa0c) = *(int *)(param_2 + 0xa0c) + (uint)(iVar7 != 1);
  uVar5 = FUN_004a9e70(param_1,param_4,param_5,in_EAX);
  in_EAX[0x56] = uVar5 & 0xff;
  iVar6 = 0;
  iVar7 = DAT_00736168;
  if (0 < DAT_0073616c) {
    do {
      if (*(short *)(iVar7 + 0x6c) == param_3) goto LAB_004aa10b;
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 0xfc;
    } while (iVar6 < DAT_0073616c);
  }
  iVar7 = 0;
LAB_004aa10b:
  if ((0x513 < param_3) && (param_3 < 0x578)) {
    if (iVar7 == 0) goto LAB_004aa1a8;
    if (DAT_0075f240 == 2) {
      if (param_4 == 0) {
        uVar4 = *(undefined4 *)(iVar7 + 0x88);
      }
      else {
        uVar4 = *(undefined4 *)(iVar7 + 0x84);
      }
      FUN_0051ba00(param_3,uVar4);
      FUN_004aa1c0();
      return;
    }
  }
  if ((iVar7 != 0) && (DAT_0075f240 == 2)) {
    if (param_4 == 0) {
      param_3 = *(undefined4 *)(iVar7 + 0x80);
    }
    else {
      param_3 = *(undefined4 *)(iVar7 + 0x7c);
    }
    FUN_0051b8d0((float)in_EAX[4] * 0.25,param_3);
  }
LAB_004aa1a8:
  FUN_004aa1c0();
  return;
}


// ==== 0x4aa1c0 FUN_004aa1c0

void FUN_004aa1c0(void)

{
  int unaff_EBX;
  int iVar1;
  undefined1 local_10 [16];
  
  iVar1 = 0;
  do {
    if (*(short *)(unaff_EBX + iVar1 * 8) != 0) {
      FUN_00586580(local_10);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x140);
  return;
}


// ==== 0x4aa200 FUN_004aa200

int __fastcall FUN_004aa200(int param_1)

{
  Opt__ResetGeneralBlock();
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0x3f666666;
  *(undefined4 *)(param_1 + 0x3c) = 0x3f666666;
  *(undefined4 *)(param_1 + 0x40) = 0x3f666666;
  *(undefined4 *)(param_1 + 0x44) = 0x3f666666;
  *(undefined4 *)(param_1 + 0x48) = 0x3f666666;
  *(undefined4 *)(param_1 + 0x4c) = 0x3f666666;
  *(undefined4 *)(param_1 + 0x50) = 0x3f666666;
  *(undefined4 *)(param_1 + 0x54) = 0x3f666666;
  *(undefined4 *)(param_1 + 0x58) = 0x3f666666;
  *(undefined4 *)(param_1 + 0x5c) = 1;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 1;
  *(undefined4 *)(param_1 + 0x84) = 1;
  *(undefined4 *)(param_1 + 0x88) = 1;
  *(undefined1 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 4;
  *(undefined4 *)(param_1 + 0x7c) = 2;
  *(undefined1 *)(param_1 + 0x8d) = 0x80;
  *(undefined1 *)(param_1 + 0x8e) = 0x80;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x98) = 1;
  *(undefined4 *)(param_1 + 0x9c) = 1;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined1 *)(param_1 + 0xa8) = 1;
  *(undefined1 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined1 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 4;
  *(undefined4 *)(param_1 + 0xc0) = 1;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 2;
  *(undefined4 *)(param_1 + 0xd0) = 1;
  *(undefined4 *)(param_1 + 0xd4) = 1;
  *(undefined1 *)(param_1 + 0xd8) = 1;
  *(undefined1 *)(param_1 + 0xd9) = 0;
  *(undefined1 *)(param_1 + 0xda) = 1;
  *(undefined1 *)(param_1 + 0xdb) = 1;
  *(undefined4 *)(param_1 + 0xc4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xdc) = 4;
  *(undefined4 *)(param_1 + 0xe0) = 1;
  *(undefined4 *)(param_1 + 0xe4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xe8) = 0;
  *(undefined4 *)(param_1 + 0xec) = 2;
  *(undefined4 *)(param_1 + 0xf0) = 1;
  *(undefined4 *)(param_1 + 0xf4) = 1;
  *(undefined1 *)(param_1 + 0xf8) = 1;
  *(undefined1 *)(param_1 + 0xf9) = 0;
  *(undefined1 *)(param_1 + 0xfa) = 1;
  *(undefined1 *)(param_1 + 0xfb) = 1;
  *(undefined4 *)(param_1 + 0xfc) = 4;
  *(undefined4 *)(param_1 + 0x100) = 1;
  *(undefined4 *)(param_1 + 0x104) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(param_1 + 0x10c) = 3;
  *(undefined4 *)(param_1 + 0x110) = 1;
  *(undefined4 *)(param_1 + 0x114) = 1;
  *(undefined1 *)(param_1 + 0x118) = 1;
  *(undefined1 *)(param_1 + 0x119) = 0;
  *(undefined1 *)(param_1 + 0x11a) = 1;
  *(undefined1 *)(param_1 + 0x11b) = 1;
  *(undefined4 *)(param_1 + 0x11c) = 1;
  *(undefined4 *)(param_1 + 0x120) = 1;
  *(undefined4 *)(param_1 + 0x130) = 1;
  *(undefined4 *)(param_1 + 0x134) = 1;
  *(undefined1 *)(param_1 + 0x138) = 1;
  *(undefined1 *)(param_1 + 0x13a) = 1;
  *(undefined4 *)(param_1 + 0x124) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0xffffffff;
  *(undefined1 *)(param_1 + 0x139) = 0;
  *(undefined1 *)(param_1 + 0x13b) = 0;
  *(undefined4 *)(param_1 + 0x144) = 1;
  *(undefined4 *)(param_1 + 0x154) = 1;
  *(undefined4 *)(param_1 + 0x158) = 1;
  *(undefined1 *)(param_1 + 0x15c) = 1;
  *(undefined1 *)(param_1 + 0x15e) = 1;
  *(undefined4 *)(param_1 + 0x140) = 4;
  *(undefined4 *)(param_1 + 0x148) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(undefined4 *)(param_1 + 0x150) = 2;
  *(undefined4 *)(param_1 + 0x160) = 3;
  *(undefined1 *)(param_1 + 0x15d) = 0;
  *(undefined1 *)(param_1 + 0x15f) = 0;
  *(undefined4 *)(param_1 + 0x1c8) = 1;
  *(undefined4 *)(param_1 + 0x1ec) = 1;
  *(undefined4 *)(param_1 + 0x1d8) = 1;
  *(undefined4 *)(param_1 + 0x1dc) = 1;
  *(undefined4 *)(param_1 + 0x1e4) = 1;
  *(undefined1 *)(param_1 + 0x1e1) = 1;
  *(undefined1 *)(param_1 + 0x1e2) = 1;
  *(undefined4 *)(param_1 + 0x1c4) = 4;
  *(undefined4 *)(param_1 + 0x1cc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1d0) = 0;
  *(undefined4 *)(param_1 + 0x1d4) = 0;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined1 *)(param_1 + 0x1e0) = 0;
  *(undefined1 *)(param_1 + 0x1e3) = 0;
  *(undefined4 *)(param_1 + 0x1f0) = 1;
  *(undefined4 *)(param_1 + 500) = 1;
  *(undefined4 *)(param_1 + 0x204) = 1;
  *(undefined1 *)(param_1 + 0x20e) = 1;
  *(undefined4 *)(param_1 + 0x1f8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1fc) = 0;
  *(undefined4 *)(param_1 + 0x200) = 2;
  *(undefined4 *)(param_1 + 0x208) = 0;
  *(undefined1 *)(param_1 + 0x20c) = 0;
  *(undefined1 *)(param_1 + 0x20d) = 0;
  *(undefined1 *)(param_1 + 0x20f) = 0;
  HighScoresDatabase__Default();
  FUN_005a0940(param_1 + 0x6634);
  return param_1;
}


// ==== 0x4aa4d0 Player::Init

/* [canon] canon low (capstone) docs/re/canon.md */

void Player__Init(char param_1)

{
  char cVar1;
  bool bVar2;
  char *in_EAX;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char *unaff_EDI;
  char local_20 [32];
  
  bVar2 = false;
  if ((in_EAX != (char *)0x0) && (iVar3 = 0, *in_EAX != '\0')) {
    do {
      iVar5 = iVar3 + 1;
      iVar3 = iVar3 + 1;
    } while (in_EAX[iVar5] != '\0');
    if (0 < iVar3) {
      bVar2 = true;
    }
  }
  unaff_EDI[0] = '\0';
  unaff_EDI[1] = '\0';
  unaff_EDI[2] = '\0';
  unaff_EDI[3] = '\0';
  unaff_EDI[4] = '\0';
  unaff_EDI[5] = '\0';
  unaff_EDI[6] = '\0';
  unaff_EDI[7] = '\0';
  unaff_EDI[8] = '\0';
  unaff_EDI[9] = '\0';
  unaff_EDI[10] = '\0';
  unaff_EDI[0xb] = '\0';
  unaff_EDI[0xc] = '\0';
  if (!bVar2) {
    if (param_1 == '\x01') {
      iVar3 = LanguageStrings__FindByHash();
      if (iVar3 == 0) {
        iVar3 = LanguageStrings__FindByHash();
      }
      iVar5 = 0x20;
      pcVar4 = local_20;
      do {
        cVar1 = pcVar4[iVar3 - (int)local_20];
        iVar5 = iVar5 + -1;
        *pcVar4 = cVar1;
        if (cVar1 == '\0') break;
        pcVar4 = pcVar4 + 1;
      } while (iVar5 != 0);
    }
    else {
      iVar3 = LanguageStrings__FindByHash();
      if (iVar3 == 0) {
        iVar3 = LanguageStrings__FindByHash();
      }
      iVar5 = 0x20;
      pcVar4 = local_20;
      do {
        cVar1 = pcVar4[iVar3 - (int)local_20];
        iVar5 = iVar5 + -1;
        *pcVar4 = cVar1;
        if (cVar1 == '\0') break;
        pcVar4 = pcVar4 + 1;
      } while (iVar5 != 0);
    }
    iVar3 = 0xd;
    pcVar4 = unaff_EDI;
    do {
      cVar1 = pcVar4[(int)(local_20 + -(int)unaff_EDI)];
      iVar3 = iVar3 + -1;
      *pcVar4 = cVar1;
      if (cVar1 == '\0') break;
      pcVar4 = pcVar4 + 1;
    } while (iVar3 != 0);
    unaff_EDI[0xd] = '\0';
    return;
  }
  iVar3 = 0xd;
  pcVar4 = unaff_EDI;
  do {
    cVar1 = pcVar4[(int)in_EAX - (int)unaff_EDI];
    iVar3 = iVar3 + -1;
    *pcVar4 = cVar1;
    if (cVar1 == '\0') break;
    pcVar4 = pcVar4 + 1;
  } while (iVar3 != 0);
  unaff_EDI[0xd] = '\x01';
  return;
}


// ==== 0x4aa5e0 FUN_004aa5e0

void FUN_004aa5e0(void)

{
  int in_EAX;
  int iVar1;
  int unaff_EBX;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  Player__Init(in_EAX == 0);
  *(undefined4 *)(unaff_EBX + 0xeeec) = 0;
  *(undefined1 *)(unaff_EBX + 0xeef0) = 1;
  *(undefined4 *)(unaff_EBX + 0x210) = 0;
  puVar2 = (undefined4 *)(unaff_EBX + 0x214);
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  uVar3 = DAT_006f1da8;
  if (in_EAX == 0) {
    uVar3 = DAT_006f1da4;
  }
  CustomizationDB__Init(unaff_EBX + 0x364,uVar3);
  FUN_004ac220();
  Career__Reset();
  puVar2 = (undefined4 *)(unaff_EBX + 0xeef4);
  for (iVar1 = 0x294; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(unaff_EBX + 0xeee8) = 0;
  return;
}


// ==== 0x4aa670 UserProfile::Default

/* [canon] canon med (ghidra-canon+nfsug) docs/re/canon.md */

void UserProfile__Default(void)

{
  char cVar1;
  undefined *puVar2;
  char cVar3;
  int in_EAX;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  int local_8;
  undefined **local_4;
  
  *(undefined4 *)(in_EAX + 0xc0) = 1;
  *(undefined4 *)(in_EAX + 0xd0) = 1;
  *(undefined4 *)(in_EAX + 0xd4) = 1;
  *(undefined1 *)(in_EAX + 0xd8) = 1;
  *(undefined1 *)(in_EAX + 0xda) = 1;
  *(undefined1 *)(in_EAX + 0xdb) = 1;
  *(undefined4 *)(in_EAX + 0xc4) = 0xffffffff;
  *(undefined4 *)(in_EAX + 200) = 0;
  *(undefined1 *)(in_EAX + 0xd9) = 0;
  *(undefined4 *)(in_EAX + 0xcc) = 2;
  *(undefined4 *)(in_EAX + 0xbc) = 4;
  *(undefined4 *)(in_EAX + 0xdc) = 4;
  *(undefined4 *)(in_EAX + 0xe0) = 1;
  *(undefined4 *)(in_EAX + 0xe4) = 0xffffffff;
  *(undefined4 *)(in_EAX + 0xe8) = 0;
  *(undefined4 *)(in_EAX + 0xec) = 2;
  *(undefined4 *)(in_EAX + 0xf0) = 1;
  *(undefined4 *)(in_EAX + 0xf4) = 1;
  *(undefined1 *)(in_EAX + 0xf8) = 1;
  *(undefined1 *)(in_EAX + 0xf9) = 0;
  *(undefined1 *)(in_EAX + 0xfa) = 1;
  *(undefined1 *)(in_EAX + 0xfb) = 1;
  *(undefined4 *)(in_EAX + 0xfc) = 4;
  *(undefined4 *)(in_EAX + 0x100) = 1;
  *(undefined4 *)(in_EAX + 0x104) = 0xffffffff;
  *(undefined4 *)(in_EAX + 0x108) = 0;
  *(undefined4 *)(in_EAX + 0x110) = 1;
  *(undefined4 *)(in_EAX + 0x114) = 1;
  *(undefined1 *)(in_EAX + 0x118) = 1;
  *(undefined1 *)(in_EAX + 0x119) = 0;
  *(undefined1 *)(in_EAX + 0x11a) = 1;
  *(undefined1 *)(in_EAX + 0x11b) = 1;
  *(undefined4 *)(in_EAX + 0x10c) = 3;
  *(undefined4 *)(in_EAX + 0x11c) = 1;
  *(undefined4 *)(in_EAX + 0x120) = 1;
  *(undefined4 *)(in_EAX + 0x124) = 0xffffffff;
  *(undefined4 *)(in_EAX + 0x128) = 0;
  *(undefined4 *)(in_EAX + 300) = 0xffffffff;
  *(undefined4 *)(in_EAX + 0x130) = 1;
  *(undefined4 *)(in_EAX + 0x134) = 1;
  *(undefined1 *)(in_EAX + 0x138) = 1;
  *(undefined1 *)(in_EAX + 0x139) = 0;
  *(undefined1 *)(in_EAX + 0x13a) = 1;
  *(undefined1 *)(in_EAX + 0x13b) = 0;
  *(undefined4 *)(in_EAX + 0x1f0) = 1;
  *(undefined4 *)(in_EAX + 500) = 1;
  *(undefined4 *)(in_EAX + 0x1f8) = 0xffffffff;
  *(undefined4 *)(in_EAX + 0x1fc) = 0;
  *(undefined4 *)(in_EAX + 0x200) = 2;
  *(undefined4 *)(in_EAX + 0x204) = 1;
  *(undefined4 *)(in_EAX + 0x208) = 0;
  *(undefined1 *)(in_EAX + 0x20c) = 0;
  *(undefined1 *)(in_EAX + 0x20d) = 0;
  *(undefined1 *)(in_EAX + 0x20e) = 1;
  *(undefined1 *)(in_EAX + 0x20f) = 0;
  *(undefined4 *)(in_EAX + 0x140) = 4;
  *(undefined4 *)(in_EAX + 0x144) = 1;
  *(undefined4 *)(in_EAX + 0x148) = 0xffffffff;
  *(undefined4 *)(in_EAX + 0x14c) = 0;
  *(undefined4 *)(in_EAX + 0x150) = 2;
  *(undefined4 *)(in_EAX + 0x154) = 1;
  *(undefined4 *)(in_EAX + 0x158) = 1;
  *(undefined4 *)(in_EAX + 0x160) = 3;
  *(undefined1 *)(in_EAX + 0x15c) = 1;
  *(undefined1 *)(in_EAX + 0x15d) = 0;
  *(undefined1 *)(in_EAX + 0x15e) = 1;
  *(undefined1 *)(in_EAX + 0x15f) = 0;
  *(undefined4 *)(in_EAX + 0x1c4) = 4;
  *(undefined4 *)(in_EAX + 0x1c8) = 1;
  *(undefined4 *)(in_EAX + 0x1ec) = 1;
  *(undefined4 *)(in_EAX + 0x1cc) = 0xffffffff;
  bVar6 = DAT_007356a8 != 0;
  *(undefined4 *)(in_EAX + 0x1d0) = 0;
  *(undefined4 *)(in_EAX + 0x1d4) = 0;
  *(undefined4 *)(in_EAX + 0x1d8) = 1;
  *(undefined4 *)(in_EAX + 0x1dc) = 1;
  *(undefined4 *)(in_EAX + 0x1e4) = 1;
  *(undefined4 *)(in_EAX + 0x1e8) = 0;
  *(undefined1 *)(in_EAX + 0x1e0) = 0;
  *(undefined1 *)(in_EAX + 0x1e1) = 1;
  *(undefined1 *)(in_EAX + 0x1e2) = 1;
  *(undefined1 *)(in_EAX + 0x1e3) = 0;
  if (bVar6) {
    *(undefined4 *)(in_EAX + 0x5c) = 1;
  }
  local_8 = 0;
  local_4 = &PTR_DAT_006f4d14;
  pcVar5 = (char *)(in_EAX + 0x298);
  do {
    *(int *)(pcVar5 + -4) = local_8;
    puVar2 = *local_4;
    pcVar4 = "FE";
    do {
      cVar3 = pcVar4[(int)(puVar2 + -0x6bdcf8)];
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      if ((cVar3 == '\0') || (cVar1 == '\0')) break;
    } while (cVar3 == cVar1);
    if (cVar3 == cVar1) {
      cVar3 = '\x01';
    }
    else {
      pcVar4 = "IG";
      do {
        cVar3 = pcVar4[(int)(puVar2 + -0x6bdcfc)];
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        if ((cVar3 == '\0') || (cVar1 == '\0')) break;
      } while (cVar3 == cVar1);
      if (cVar3 == cVar1) {
        cVar3 = '\x02';
      }
      else {
        pcVar4 = "AL";
        do {
          cVar3 = pcVar4[(int)(puVar2 + -0x6c6540)];
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
          if ((cVar3 == '\0') || (cVar1 == '\0')) break;
        } while (cVar3 == cVar1);
        cVar3 = (-(cVar3 != cVar1) & 0xfdU) + 3;
      }
    }
    *pcVar5 = cVar3;
    local_4 = local_4 + 4;
    local_8 = local_8 + 1;
    pcVar5 = pcVar5 + 8;
    if (0x6f4eb3 < (int)local_4) {
      return;
    }
  } while( true );
}


// ==== 0x4aa970 ThresholdTable_MarkReached

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

void ThresholdTable_MarkReached(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int unaff_EBX;
  
  iVar3 = DAT_00735ebc;
  iVar2 = DAT_007343fc;
  iVar4 = 0;
  piVar5 = DAT_007343f8;
  if (0 < DAT_007343fc) {
    do {
      if (((-1 < iVar4) && (iVar4 < iVar2)) && (piVar5 != (int *)0x0)) {
        iVar1 = param_2;
        if (DAT_00735ec0 != '\0') {
          iVar1 = iVar3;
        }
        if (*piVar5 <= iVar1) {
          *(undefined1 *)(iVar4 + unaff_EBX) = 1;
        }
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 8;
    } while (iVar4 < iVar2);
  }
  return;
}


// ==== 0x4aa9d0 UserProfile::IsStyleRewardUnlocked

/* [canon] canon high (ghidra-canon+nfsug) docs/re/canon.md */

bool UserProfile__IsStyleRewardUnlocked(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  
  iVar1 = DAT_007343fc;
  if ((DAT_0073494c != 0) || (DAT_00735ec1 != '\0')) {
    return true;
  }
  iVar4 = 0;
  if (0 < DAT_007343fc) {
    psVar3 = (short *)(DAT_007343f8 + 4);
    do {
      if ((((-1 < iVar4) && (iVar4 < iVar1)) && (psVar3 != (short *)0x4)) && (*psVar3 == param_2)) {
        switch((int)*psVar3) {
        case 0:
          if (*(int *)(psVar3 + 2) == param_3) {
            return *(char *)(iVar4 + 0x214 + param_1) == '\x01';
          }
          break;
        case 1:
          iVar2 = bStrICmp();
          if (iVar2 == 0) {
            return *(char *)(iVar4 + 0x214 + param_1) == '\x01';
          }
          break;
        case 2:
        case 3:
          if (*(int *)(psVar3 + 2) == param_3) {
            return *(char *)(iVar4 + 0x214 + param_1) == '\x01';
          }
        }
      }
      iVar4 = iVar4 + 1;
      psVar3 = psVar3 + 0x10;
    } while (iVar4 < iVar1);
  }
  if (((param_2 != 0) && (param_2 != 1)) && (param_2 != 2)) {
    return true;
  }
  return false;
}


// ==== 0x4aaad0 Opt::Serialize

/* [canon] canon high (capstone) docs/re/canon.md */

void __fastcall Opt__Serialize(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar1 = (undefined4 *)(param_3 + (int)param_1);
  if (param_1 + 1 <= puVar1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  if ((undefined4 *)((int)param_1 + 0xd) <= puVar1) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    *(undefined1 *)(param_1 + 3) = *(undefined1 *)(param_2 + 3);
    param_1 = (undefined4 *)((int)param_1 + 0xd);
  }
  puVar5 = param_1;
  if (param_1 + 10 <= puVar1) {
    puVar3 = param_2 + 4;
    puVar4 = param_1;
    for (iVar2 = 10; puVar5 = param_1 + 10, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  puVar3 = puVar5;
  if (puVar5 + 0xf <= puVar1) {
    puVar4 = param_2 + 0xe;
    puVar6 = puVar5;
    for (iVar2 = 0xf; puVar3 = puVar5 + 0xf, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  puVar5 = puVar3;
  if (puVar3 + 7 <= puVar1) {
    puVar4 = param_2 + 0x1d;
    puVar6 = puVar3;
    for (iVar2 = 7; puVar5 = puVar3 + 7, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  puVar3 = puVar5;
  if (puVar5 + 7 <= puVar1) {
    puVar4 = param_2 + 0x24;
    puVar6 = puVar5;
    for (iVar2 = 7; puVar3 = puVar5 + 7, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  if (puVar3 + 2 <= puVar1) {
    *puVar3 = param_2[0x2b];
    puVar3[1] = param_2[0x2c];
    puVar3 = puVar3 + 2;
  }
  if (puVar3 + 2 <= puVar1) {
    *puVar3 = param_2[0x2d];
    puVar3[1] = param_2[0x2e];
    puVar3 = puVar3 + 2;
  }
  puVar5 = puVar3;
  if (puVar3 + 0x34 <= puVar1) {
    puVar4 = param_2 + 0xa5;
    puVar6 = puVar3;
    for (iVar2 = 0x34; puVar5 = puVar3 + 0x34, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  puVar3 = puVar5;
  if (puVar5 + 8 <= puVar1) {
    puVar4 = param_2 + 0x2f;
    puVar6 = puVar5;
    for (iVar2 = 8; puVar3 = puVar5 + 8, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  puVar5 = puVar3;
  if (puVar3 + 8 <= puVar1) {
    puVar4 = param_2 + 0x37;
    puVar6 = puVar3;
    for (iVar2 = 8; puVar5 = puVar3 + 8, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  puVar3 = puVar5;
  if (puVar5 + 8 <= puVar1) {
    puVar4 = param_2 + 0x3f;
    puVar6 = puVar5;
    for (iVar2 = 8; puVar3 = puVar5 + 8, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  puVar5 = puVar3;
  if (puVar3 + 9 <= puVar1) {
    puVar4 = param_2 + 0x47;
    puVar6 = puVar3;
    for (iVar2 = 9; puVar5 = puVar3 + 9, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  puVar3 = puVar5;
  if (puVar5 + 0x21 <= puVar1) {
    puVar4 = param_2 + 0x50;
    puVar6 = puVar5;
    for (iVar2 = 0x21; puVar3 = puVar5 + 0x21, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  puVar5 = puVar3;
  if (puVar3 + 0xb <= puVar1) {
    puVar4 = param_2 + 0x71;
    puVar6 = puVar3;
    for (iVar2 = 0xb; puVar5 = puVar3 + 0xb, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  puVar3 = puVar5;
  if (puVar5 + 8 <= puVar1) {
    puVar4 = param_2 + 0x7c;
    puVar6 = puVar5;
    for (iVar2 = 8; puVar3 = puVar5 + 8, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  if (puVar3 + 1 <= puVar1) {
    *puVar3 = param_2[0x3bbb];
  }
  return;
}


// ==== 0x4aac70 Opt::Deserialize

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

void __thiscall Opt__Deserialize(int param_1,char param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_EAX;
  int iVar3;
  undefined4 *unaff_EBX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_160 [7];
  undefined1 local_144;
  undefined1 local_143;
  undefined1 local_142;
  undefined1 local_141;
  undefined4 local_140 [7];
  undefined1 local_124;
  undefined1 local_123;
  undefined1 local_122;
  undefined1 local_121;
  undefined4 local_120 [7];
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  undefined1 local_101;
  undefined4 local_100 [7];
  undefined1 local_e4;
  undefined1 local_e3;
  undefined1 local_e2;
  undefined1 local_e1;
  undefined4 local_e0 [7];
  undefined1 local_c4;
  undefined1 local_c3;
  undefined1 local_c2;
  undefined1 local_c1;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4 [7];
  undefined1 local_98;
  undefined1 local_97;
  undefined1 local_96;
  undefined1 local_95;
  undefined4 local_90 [7];
  undefined1 local_74;
  undefined1 local_73;
  undefined1 local_72;
  undefined1 local_71;
  undefined4 local_70;
  
  puVar1 = (undefined4 *)(in_EAX + param_1);
  if ((undefined4 *)(in_EAX + 0x11U) <= puVar1) {
    *unaff_EBX = *(undefined4 *)(in_EAX + 4);
    unaff_EBX[1] = *(undefined4 *)(in_EAX + 8);
    unaff_EBX[2] = *(undefined4 *)(in_EAX + 0xc);
    *(undefined1 *)(unaff_EBX + 3) = *(undefined1 *)(in_EAX + 0x10);
  }
  if ((undefined4 *)(in_EAX + 0x39U) <= puVar1) {
    puVar4 = (undefined4 *)(in_EAX + 0x11U);
    puVar5 = unaff_EBX + 4;
    for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  if ((undefined4 *)(in_EAX + 0x75U) <= puVar1) {
    puVar4 = (undefined4 *)(in_EAX + 0x39U);
    puVar5 = unaff_EBX + 0xe;
    for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  if ((undefined4 *)(in_EAX + 0x91U) <= puVar1) {
    puVar4 = (undefined4 *)(in_EAX + 0x75U);
    puVar5 = unaff_EBX + 0x1d;
    for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  if ((undefined4 *)(in_EAX + 0xadU) <= puVar1) {
    puVar4 = (undefined4 *)(in_EAX + 0x91U);
    puVar5 = unaff_EBX + 0x24;
    for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  if ((undefined4 *)(in_EAX + 0xb5U) <= puVar1) {
    unaff_EBX[0x2b] = *(undefined4 *)(in_EAX + 0xadU);
    unaff_EBX[0x2c] = *(undefined4 *)(in_EAX + 0xb1);
  }
  if ((undefined4 *)(in_EAX + 0xbdU) <= puVar1) {
    unaff_EBX[0x2d] = *(undefined4 *)(in_EAX + 0xb5U);
    unaff_EBX[0x2e] = *(undefined4 *)(in_EAX + 0xb9);
  }
  if ((undefined4 *)(in_EAX + 0x18dU) <= puVar1) {
    puVar4 = (undefined4 *)(in_EAX + 0xbdU);
    puVar5 = unaff_EBX + 0xa5;
    for (iVar3 = 0x34; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  local_100[0] = 4;
  local_100[1] = 1;
  local_100[2] = 0xffffffff;
  local_100[3] = 0;
  local_100[4] = 2;
  local_100[5] = 1;
  local_100[6] = 1;
  local_e4 = 1;
  local_e3 = 0;
  local_e2 = 1;
  local_e1 = 1;
  local_120[0] = 4;
  local_120[1] = 1;
  local_120[2] = 0xffffffff;
  local_120[3] = 0;
  local_120[4] = 2;
  local_120[5] = 1;
  local_120[6] = 1;
  local_104 = 1;
  local_103 = 0;
  local_102 = 1;
  local_101 = 1;
  local_160[0] = 4;
  local_160[1] = 1;
  local_160[2] = 0xffffffff;
  local_160[3] = 0;
  local_160[4] = 3;
  local_160[5] = 1;
  local_160[6] = 1;
  local_144 = 1;
  local_143 = 0;
  local_142 = 1;
  local_141 = 1;
  local_b4[0] = 1;
  local_b4[1] = 1;
  local_b4[2] = 0xffffffff;
  local_b4[3] = 0;
  local_b4[4] = 0xffffffff;
  local_b4[5] = 1;
  local_b4[6] = 1;
  local_98 = 1;
  local_97 = 0;
  local_96 = 1;
  local_95 = 0;
  local_90[0] = 4;
  local_90[1] = 1;
  local_90[2] = 0xffffffff;
  local_90[3] = 0;
  local_90[4] = 2;
  local_90[5] = 1;
  local_90[6] = 1;
  local_70 = 3;
  local_74 = 1;
  local_73 = 0;
  local_72 = 1;
  local_71 = 0;
  local_e0[0] = 4;
  local_e0[1] = 1;
  local_b8 = 1;
  local_e0[2] = 0xffffffff;
  local_e0[3] = 0;
  local_e0[4] = 0;
  local_e0[5] = 1;
  local_e0[6] = 1;
  local_c0 = 1;
  local_bc = 0;
  local_c4 = 0;
  local_c3 = 1;
  local_c2 = 1;
  local_c1 = 0;
  local_140[0] = 1;
  local_140[1] = 1;
  local_140[2] = 0xffffffff;
  local_140[3] = 0;
  local_140[4] = 2;
  local_140[5] = 1;
  local_140[6] = 0;
  local_124 = 0;
  local_123 = 0;
  local_122 = 1;
  local_121 = 0;
  if ((undefined4 *)(in_EAX + 0x1adU) <= puVar1) {
    puVar4 = (undefined4 *)(in_EAX + 0x18dU);
    puVar5 = local_100;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  if ((undefined4 *)(in_EAX + 0x1cdU) <= puVar1) {
    puVar4 = (undefined4 *)(in_EAX + 0x1adU);
    puVar5 = local_120;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  if ((undefined4 *)(in_EAX + 0x1edU) <= puVar1) {
    puVar4 = (undefined4 *)(in_EAX + 0x1cdU);
    puVar5 = local_160;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  if ((undefined4 *)(in_EAX + 0x211U) <= puVar1) {
    puVar4 = (undefined4 *)(in_EAX + 0x1edU);
    puVar5 = local_b4;
    for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  if ((undefined4 *)(in_EAX + 0x295U) <= puVar1) {
    puVar4 = (undefined4 *)(in_EAX + 0x211U);
    puVar5 = local_90;
    for (iVar3 = 0x21; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  if ((undefined4 *)(in_EAX + 0x2c1U) <= puVar1) {
    puVar4 = (undefined4 *)(in_EAX + 0x295U);
    puVar5 = local_e0;
    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  if ((undefined4 *)(in_EAX + 0x2e1U) <= puVar1) {
    puVar4 = (undefined4 *)(in_EAX + 0x2c1U);
    puVar5 = local_140;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  puVar4 = local_100;
  puVar5 = unaff_EBX + 0x2f;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar4 = local_120;
  puVar5 = unaff_EBX + 0x37;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar4 = local_160;
  puVar5 = unaff_EBX + 0x3f;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar4 = local_b4;
  puVar5 = unaff_EBX + 0x47;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar4 = local_90;
  puVar5 = unaff_EBX + 0x50;
  for (iVar3 = 0x21; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar4 = local_e0;
  puVar5 = unaff_EBX + 0x71;
  for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar4 = local_140;
  puVar5 = unaff_EBX + 0x7c;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  if ((undefined4 *)(in_EAX + 0x2e5U) <= puVar1) {
    unaff_EBX[0x3bbb] = *(undefined4 *)(in_EAX + 0x2e1U);
  }
  *(undefined1 *)((int)unaff_EBX + 0xd) = 1;
  iVar3 = DAT_007356a8;
  if (param_2 != '\0') {
    uVar2 = unaff_EBX[0x17];
    if (DAT_006f1dd8 != 0) {
      *(undefined4 *)(*(int *)(DAT_007356a8 + 0x100) + 0x14) = uVar2;
    }
    unaff_EBX[0x17] = uVar2;
    *(undefined4 **)(iVar3 + 8) = unaff_EBX + 0xe;
    FUN_0051cc10(iVar3);
    _DAT_006f8718 = unaff_EBX[0x14];
    _DAT_006f871c = _ftol_nocw();
  }
  return;
}


// ==== 0x4ab120 Ugd::PackBlock

/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

void Ugd__PackBlock(int param_1,int param_2)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  puVar7 = (undefined4 *)((int)in_EAX + param_2);
  if (in_EAX + 1 <= puVar7) {
    *in_EAX = 0;
    in_EAX = in_EAX + 1;
  }
  if (in_EAX + 1 <= puVar7) {
    *in_EAX = *(undefined4 *)(param_1 + 0x210);
    in_EAX = in_EAX + 1;
  }
  puVar1 = (undefined4 *)(param_1 + 0x364);
  puVar2 = in_EAX;
  for (iVar3 = 0x18b4; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar1 = in_EAX + 0x18b4;
  uVar5 = 0x88b4;
  if ((int)puVar7 - (int)puVar1 < 0x88b5) {
    uVar5 = (int)puVar7 - (int)puVar1;
  }
  puVar2 = (undefined4 *)(param_1 + 0x6634);
  puVar6 = puVar1;
  for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar6 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar6 = puVar6 + 1;
  }
  puVar1 = (undefined4 *)((int)puVar1 + uVar5);
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined1 *)puVar6 = *(undefined1 *)puVar2;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  if (puVar1 + 1 <= puVar7) {
    *puVar1 = *(undefined4 *)(param_1 + 0xeee8);
    puVar1 = puVar1 + 1;
  }
  puVar2 = puVar1;
  if (puVar1 + 0x294 <= puVar7) {
    puVar6 = (undefined4 *)(param_1 + 0xeef4);
    puVar8 = puVar1;
    for (iVar3 = 0x294; puVar2 = puVar1 + 0x294, iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
  }
  if (puVar2 + 0x20 <= puVar7) {
    puVar7 = (undefined4 *)(param_1 + 0x214);
    for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar2 = puVar2 + 1;
    }
  }
  return;
}


// ==== 0x4ab200 Ugd::UnpackBlock

/* [canon] canon high (hopper+ghidra+capstone) docs/re/canon.md */

void __fastcall Ugd__UnpackBlock(int param_1,int param_2)

{
  int in_EAX;
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  puVar6 = (undefined4 *)(in_EAX + param_1);
  if ((undefined4 *)(in_EAX + 8U) <= puVar6) {
    *(undefined4 *)(param_2 + 0x210) = *(undefined4 *)(in_EAX + 4);
  }
  puVar1 = (undefined4 *)(in_EAX + 8U);
  puVar5 = (undefined4 *)(param_2 + 0x364);
  for (iVar2 = 0x18b4; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar1 = (undefined4 *)(in_EAX + 0x62d8);
  uVar3 = (int)puVar6 - (int)puVar1;
  if (0x88b4 < (int)uVar3) {
    uVar3 = 0x88b4;
  }
  puVar5 = puVar1;
  puVar7 = (undefined4 *)(param_2 + 0x6634);
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)puVar7 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  puVar1 = (undefined4 *)((int)puVar1 + uVar3);
  if (puVar1 + 1 <= puVar6) {
    *(undefined4 *)(param_2 + 0xeee8) = *puVar1;
  }
  if (puVar1 + 0x295 <= puVar6) {
    puVar5 = puVar1 + 1;
    puVar7 = (undefined4 *)(param_2 + 0xeef4);
    for (iVar2 = 0x294; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
  }
  if (puVar1 + 0x2b5 <= puVar6) {
    puVar6 = puVar1 + 0x295;
    puVar1 = (undefined4 *)(param_2 + 0x214);
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar1 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar1 = puVar1 + 1;
    }
  }
  return;
}


// ==== 0x4ab2b0 FUN_004ab2b0

void FUN_004ab2b0(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  *param_1 = 1;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 5) = 1;
  param_1[0xbb56] = 0;
  Player__Init(1);
  param_1[0x3bbf] = 0;
  param_1[0x88] = 0;
  *(undefined1 *)(param_1 + 0x3bc0) = 1;
  puVar3 = param_1 + 0x89;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  CustomizationDB__Init(param_1 + 0xdd,DAT_006f1da4);
  FUN_004ac220();
  Career__Reset();
  puVar3 = param_1 + 0x3bc1;
  for (iVar2 = 0x294; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  param_1[0x3bbe] = 0;
  Player__Init(1);
  param_1[0x7a10] = 0;
  *(undefined1 *)(param_1 + 0x7a11) = 1;
  param_1[0x3ed9] = 0;
  puVar3 = param_1 + 0x3eda;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  CustomizationDB__Init(param_1 + 0x3f2e,DAT_006f1da4);
  FUN_004ac220();
  Career__Reset();
  puVar3 = param_1 + 0x7a12;
  for (iVar2 = 0x294; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  param_1[0x7a0f] = 0;
  Player__Init(0);
  uVar1 = DAT_006f1da8;
  param_1[0xb861] = 0;
  *(undefined1 *)(param_1 + 0xb862) = 1;
  param_1[0x7d2a] = 0;
  puVar3 = param_1 + 0x7d2b;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  CustomizationDB__Init(param_1 + 0x7d7f,uVar1);
  FUN_004ac220();
  Career__Reset();
  puVar3 = param_1 + 0xb863;
  for (iVar2 = 0x294; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  param_1[0xb860] = 0;
  UserProfile__Default(0,1);
  UserProfile__Default(0,1);
  UserProfile__Default(1,1);
  param_1[0xbb52] = 0;
  param_1[0xbb53] = 0;
  param_1[0xbb54] = 0;
  param_1[0xbb55] = 0;
  param_1[2] = 0;
  param_1[0xbaf7] = 2;
  *(undefined1 *)(param_1 + 0xbb40) = 0;
  param_1[3] = 1;
  return;
}


// ==== 0x4ab470 cFrontendDatabase::IsTrackAvailableForRaceType

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

uint cFrontendDatabase__IsTrackAvailableForRaceType(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar2 = 0;
  iVar1 = DAT_00736168;
  if (0 < DAT_0073616c) {
    do {
      if (*(short *)(iVar1 + 0x6c) == unaff_ESI) {
        switch(unaff_EDI) {
        case 0:
          return *(uint *)(iVar1 + 0x74) & 1;
        case 1:
          return *(uint *)(iVar1 + 0x74) & 4;
        case 2:
          return *(uint *)(iVar1 + 0x74) & 0x40;
        case 3:
          return *(uint *)(iVar1 + 0x74) & 0x10;
        case 4:
          return *(uint *)(iVar1 + 0x74) & 0x20;
        case 5:
          return *(uint *)(iVar1 + 0x74) & 2;
        case 6:
          return *(uint *)(iVar1 + 0x74) & 8;
        default:
          return 0;
        }
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0xfc;
    } while (iVar2 < DAT_0073616c);
  }
  return 0;
}


// ==== 0x4ab510 RaceOptions_Get

/* [canon] traffic low (C+H) docs/re/traffic.md */

int __fastcall RaceOptions_Get(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  switch(param_2) {
  case 0:
    return param_1 + 0xfa10;
  case 1:
    return param_1 + 0xfa30;
  case 2:
    return param_1 + 0xfa50;
  case 3:
    return param_1 + 0xfa70;
  case 4:
    return param_1 + 0xfa94;
  case 5:
    return param_1 + 0xfb18;
  case 6:
    iVar1 = param_1 + 0xfb44;
  }
  return iVar1;
}


// ==== 0x4ab570 FUN_004ab570

void FUN_004ab570(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (in_EAX != -0x1f5fc) {
    iVar1 = *(int *)(in_EAX + 0x257d4);
    iVar3 = 0;
    if (0 < iVar1) {
      iVar4 = in_EAX + 0x21634;
      do {
        if ((iVar3 < 0) || (iVar2 = iVar4, 0x13 < iVar3)) {
          iVar2 = 0;
        }
        FUN_004ac820(iVar2);
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x348;
      } while (iVar3 < iVar1);
    }
  }
  return;
}


// ==== 0x4ab5c0 FUN_004ab5c0

int FUN_004ab5c0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_4;
  
  iVar1 = DAT_0073616c;
  iVar3 = 0;
  local_4 = 0;
  iVar2 = 0;
  if (0 < DAT_0073616c) {
    do {
      iVar2 = cFrontendDatabase__IsTrackAvailableForRaceType(&DAT_00748f70);
      if (iVar2 != 0) {
        local_4 = local_4 + 1;
      }
      iVar3 = iVar3 + 1;
      iVar2 = local_4;
    } while (iVar3 < iVar1);
  }
  return iVar2;
}


// ==== 0x4ab640 FERaceEvent::HasMagazineReward

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

uint __fastcall FERaceEvent__HasMagazineReward(int param_1)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 0;
  if (0 < *(int *)(param_1 + 0x74)) {
    piVar2 = (int *)(param_1 + 0x38);
    do {
      if (*piVar2 == 1) {
        return CONCAT31((int3)(uVar1 >> 8),1);
      }
      uVar1 = uVar1 + 1;
      piVar2 = piVar2 + 3;
    } while ((int)uVar1 < *(int *)(param_1 + 0x74));
  }
  return uVar1 & 0xffffff00;
}


// ==== 0x4ab670 FUN_004ab670

char * FUN_004ab670(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  int in_EAX;
  char *local_4;
  
  local_4 = "MU_Main_PC.fng";
  if (in_EAX == 0) {
    switch(DAT_00777b4c) {
    case 1:
      iVar1 = *(int *)(param_1 + 0x1e838);
      if (iVar1 == 0) goto LAB_004ab6a4;
      cVar3 = Race__DidPlayerWin(iVar1,0);
      cVar4 = Race__DidPlayerWin(iVar1,0);
      cVar5 = FUN_005a3340();
      iVar2 = *(int *)(iVar1 + 0x58a4);
      if ((iVar2 == 2) && (cVar6 = Race__DidPlayerWin(iVar1,0), cVar6 != '\0')) {
        return "MU_UG_JunkmanGiveth.fng";
      }
      if ((iVar2 == 3) && (cVar6 = Race__DidPlayerWin(iVar1,0), cVar6 != '\0')) {
        cVar3 = Career__EventGivesLevel4Part();
        if (cVar3 != '\0') {
          return "MU_UG_SamanthaGiveth.fng";
        }
      }
      else {
        if (*(int *)(iVar1 + 0x58a0) == 0) {
          if (cVar3 == '\0') {
            return local_4;
          }
          if (cVar5 == '\0') {
            return local_4;
          }
          if (cVar4 == '\0') {
            return local_4;
          }
          return "MU_UG_NewCareerExtroFMV.fng";
        }
        if ((*(char *)(iVar1 + 0x5964) != '\0') && (cVar4 != '\0')) {
LAB_004ab7e2:
          return "MU_UG_NewCareerExtroFMV.fng";
        }
        if (*(char *)(iVar1 + 0x5958) == '\0') {
          if (cVar4 == '\0') goto LAB_004ab771;
        }
        else if (cVar4 == '\0') goto LAB_004ab7e2;
        cVar3 = FERaceEvent__HasMagazineReward();
        if ((cVar3 != '\0') || (cVar3 = FUN_0051ba80(), cVar3 != '\0')) {
          return "MU_UG_MagazineGiveth.fng";
        }
      }
LAB_004ab771:
      return "MU_UG_UndergroundMenu.fng";
    case 2:
    case 4:
      return "MU_QuickRaceModeSelect.fng";
    case 8:
      local_4 = "MU_OnlineMenu.fng";
    }
  }
  else {
    if (in_EAX == 1) {
LAB_004ab6a4:
      return "MU_Garage.fng";
    }
    if (in_EAX == 2) {
      return "MU_UG_MapScreen.fng";
    }
  }
  return local_4;
}


// ==== 0x4ab880 cFrontendDatabase::CalcRaceTypeForHighScores

/* [canon] canon high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 cFrontendDatabase__CalcRaceTypeForHighScores(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = DAT_00736168;
  if (0 < DAT_0073616c) {
    do {
      if (*(short *)(iVar3 + 0x6c) == DAT_0078a2f0) {
        uVar1 = *(uint *)(iVar3 + 0x74);
        if ((uVar1 & 1) != 0) {
          return 3;
        }
        if ((uVar1 & 2) != 0) {
          return 1;
        }
        if ((uVar1 & 4) != 0) {
          return 0;
        }
        if ((uVar1 & 8) == 0) {
          return 0xffffffff;
        }
        return 2;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xfc;
    } while (iVar2 < DAT_0073616c);
  }
  return 0xffffffff;
}


// ==== 0x4ab900 FUN_004ab900

void FUN_004ab900(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_EAX;
  int iVar4;
  int *piVar5;
  int iVar6;
  bool bVar7;
  undefined4 unaff_retaddr;
  
  FUN_004ad210(param_1);
  bVar7 = *(int *)(in_EAX + 0x2ebdc) == 4;
  cFrontendDatabase__CalcRaceTypeForHighScores(in_EAX);
  uVar3 = DAT_0078a31c;
  uVar2 = DAT_0078a2fc;
  uVar1 = DAT_0078a2f0;
  iVar4 = 0;
  if (0 < *(int *)(in_EAX + 0x2f840)) {
    piVar5 = (int *)(in_EAX + 0x2ed64);
    do {
      if (*piVar5 == DAT_0078a410) {
        iVar4 = iVar4 * 0x15c + in_EAX + 0x2ed60;
        goto LAB_004ab980;
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 0x57;
    } while (iVar4 < *(int *)(in_EAX + 0x2f840));
  }
  iVar4 = 0;
LAB_004ab980:
  iVar6 = 0;
  FUN_004a9fd0(DAT_0078a2f0,DAT_0078a2fc,DAT_0078a31c,bVar7);
  if (bVar7) {
    iVar6 = 0;
    if (0 < *(int *)(in_EAX + 0x2f840)) {
      piVar5 = (int *)(in_EAX + 0x2ed64);
      do {
        if (*piVar5 == DAT_0078a414) {
          iVar6 = iVar6 * 0x15c + in_EAX + 0x2ed60;
          goto LAB_004ab9d1;
        }
        iVar6 = iVar6 + 1;
        piVar5 = piVar5 + 0x57;
      } while (iVar6 < *(int *)(in_EAX + 0x2f840));
    }
    iVar6 = 0;
LAB_004ab9d1:
    FUN_004a9fd0(uVar1,uVar2,uVar3,1);
  }
  FUN_004abf10(*(undefined4 *)(iVar4 + 0xac));
  if (bVar7) {
    FUN_004abf10(*(undefined4 *)(iVar6 + 0xac));
  }
  if (DAT_00777b4c == 8) {
    FUN_0051b720();
  }
  if (*(int **)(in_EAX + 0x2ed5c) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0x2ed5c) + 8))(unaff_retaddr);
  }
  return;
}


// ==== 0x4aba80 cFrontendDatabase::NotifyRestartRace

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void cFrontendDatabase__NotifyRestartRace(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x2f928) = 2;
  if (*(int **)(in_EAX + 0x2ed5c) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004aba96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_EAX + 0x2ed5c) + 0xc))();
    return;
  }
  return;
}


// ==== 0x4abaa0 FUN_004abaa0

void FUN_004abaa0(void)

{
  int iVar1;
  int iVar2;
  int *unaff_ESI;
  
  iVar1 = *unaff_ESI;
  iVar2 = cFrontendDatabase__CalcRaceTypeForHighScores(unaff_ESI);
  if (unaff_ESI[0xbaf7] == 1) {
    if (*(int *)(unaff_ESI[0xbb57] + 0x58a0) == 0) goto LAB_004abb12;
    unaff_ESI[0x7c93] = unaff_ESI[0x7c93] + 1;
  }
  else {
    unaff_ESI[0x7c93] = unaff_ESI[0x7c93] + 1;
  }
  if (iVar2 != -1) {
    unaff_ESI[iVar2 * 3 + 0x7c96] = unaff_ESI[iVar2 * 3 + 0x7c96] + 1;
  }
  if (iVar1 != 2) {
    return;
  }
  unaff_ESI[0x7ca2] = unaff_ESI[0x7ca2] + 1;
LAB_004abb12:
  if (iVar1 == 2) {
    unaff_ESI[0xbae4] = unaff_ESI[0xbae4] + 1;
    if (iVar2 != -1) {
      unaff_ESI[iVar2 * 3 + 0xbae7] = unaff_ESI[iVar2 * 3 + 0xbae7] + 1;
    }
    unaff_ESI[0xbaf3] = unaff_ESI[0xbaf3] + 1;
  }
  return;
}


// ==== 0x4abb50 cFrontendDatabase::NotifyExitRaceToFrontend

/* [canon] canon high (ghidra-canon+nfsug) docs/re/canon.md */

void cFrontendDatabase__NotifyExitRaceToFrontend(int param_1)

{
  int iVar1;
  char cVar2;
  int unaff_EBX;
  
  *(undefined4 *)(unaff_EBX + 0x2f928) = 1;
  if (*(int **)(unaff_EBX + 0x2ed5c) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_EBX + 0x2ed5c) + 0x14))();
    iVar1 = *(int *)(unaff_EBX + 0x2ebdc);
    if ((iVar1 == 1) && (unaff_EBX != -0x15f88)) {
      iVar1 = *(int *)(unaff_EBX + 0x2ed5c);
      cVar2 = Race__DidPlayerWin(iVar1,1);
      if (cVar2 == '\0') {
        Career__QuitEvent();
      }
      else {
        Career__WinEvent(*(undefined4 *)(iVar1 + 0x58a0));
      }
    }
    else if (((iVar1 == 2) || (iVar1 == 4)) && (*(int *)(unaff_EBX + 0x2ed58) == 4)) {
      if (*(undefined4 **)(unaff_EBX + 0x2ed5c) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(unaff_EBX + 0x2ed5c))(1);
      }
      *(undefined4 *)(unaff_EBX + 0x2ed5c) = 0;
    }
  }
  if (param_1 == 0) {
    if ((*(int *)(unaff_EBX + 0x2ebdc) != 1) ||
       (*(int *)(*(int *)(unaff_EBX + 0x2ed5c) + 0x58a0) != 0)) {
      *(int *)(unaff_EBX + 0x1f254) = *(int *)(unaff_EBX + 0x1f254) + 1;
    }
    if (*(int *)(unaff_EBX + 0x2ebdc) == 4) {
      *(int *)(unaff_EBX + 0x2eb98) = *(int *)(unaff_EBX + 0x2eb98) + 1;
    }
  }
  return;
}


// ==== 0x4abc20 cFrontendDatabase::NotifyChangeToNextRace

/* [canon] canon med (ghidra-canon+nfsug) docs/re/canon.md */

void cFrontendDatabase__NotifyChangeToNextRace(void)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)(*(int *)(in_EAX + 0x2ed5c) + 0x5864);
  iVar2 = 0;
  iVar3 = DAT_00736168;
  if (0 < DAT_0073616c) {
    do {
      if ((int)*(short *)(iVar3 + 0x6c) == *piVar1) goto LAB_004abc58;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xfc;
    } while (iVar2 < DAT_0073616c);
  }
  iVar3 = 0;
LAB_004abc58:
  DAT_0078a2f0 = (int)*(short *)(iVar3 + 0x6c);
  DAT_0078a318 = (int)*(char *)(iVar3 + 0x69);
  DAT_0078a2fc = piVar1[1];
  DAT_0078a31c = piVar1[2];
  return;
}


// ==== 0x4abc90 cFrontendDatabase::ResetRaceSlotState

/* [canon] canon med (ghidra-canon+hopper) docs/re/canon.md */

void cFrontendDatabase__ResetRaceSlotState(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x2ebe4) = 0;
  *(undefined4 *)(in_EAX + 0x2ebe8) = 4;
  *(undefined4 *)(in_EAX + 0x2ebec) = 4;
  *(undefined4 *)(in_EAX + 0x2ed44) = 0;
  *(undefined1 *)(in_EAX + 0x2ecc0) = 0;
  *(undefined1 *)(in_EAX + 0x2ed00) = 0;
  *(undefined1 *)(in_EAX + 0x2ed20) = 0;
  *(undefined4 *)(in_EAX + 0x2ed40) = 0;
  return;
}


// ==== 0x4abcd0 LanguageStrings_FindByRegionName

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void LanguageStrings_FindByRegionName(void)

{
  char cVar1;
  char cVar2;
  int in_EAX;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  do {
    pcVar3 = (&PTR_DAT_006fb6f8)[uVar5 * 2];
    iVar4 = (in_EAX + 2) - (int)pcVar3;
    do {
      cVar1 = pcVar3[iVar4];
      cVar2 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      if ((cVar1 == '\0') || (cVar2 == '\0')) break;
    } while (cVar1 == cVar2);
    if (cVar1 == cVar2) {
      iVar4 = LanguageStrings__FindByHash();
      if (iVar4 == 0) {
        LanguageStrings__FindByHash();
      }
      return;
    }
    uVar5 = uVar5 + 1;
    if (6 < uVar5) {
      return;
    }
  } while( true );
}


// ==== 0x4abd40 FE_GetSlotPrefix

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

undefined * FE_GetSlotPrefix(void)

{
  char cVar1;
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0:
    break;
  case 1:
    cVar1 = Obj_GetByte19();
    if (cVar1 == '\0') {
      return &DAT_006c64f8;
    }
    return &DAT_006c64fc;
  case 2:
    cVar1 = Obj_GetByte19();
    if (cVar1 == '\0') {
      return &DAT_006c64f0;
    }
    return &DAT_006c64f4;
  case 3:
    cVar1 = Obj_GetByte19();
    if (cVar1 == '\0') {
      return &DAT_006c64e8;
    }
    return &DAT_006c64ec;
  default:
    return &DAT_006c64e4;
  }
  cVar1 = Obj_GetByte19();
  if (cVar1 == '\0') {
    return &DAT_006c6500;
  }
  return &DAT_006c6504;
}


// ==== 0x4abde0 cFrontendDatabase::SetString2ED20

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

void __fastcall cFrontendDatabase__SetString2ED20(undefined4 param_1,char *param_2)

{
  char cVar1;
  int in_EAX;
  char *pcVar2;
  char *pcVar3;
  
  cVar1 = *param_2;
  pcVar2 = (char *)(in_EAX + 0x2ed20);
  *pcVar2 = cVar1;
  if (cVar1 != '\0') {
    pcVar3 = pcVar2;
    do {
      cVar1 = pcVar3[(int)(param_2 + (1 - (int)pcVar2))];
      pcVar3 = pcVar3 + 1;
      *pcVar3 = cVar1;
    } while (cVar1 != '\0');
  }
  return;
}


// ==== 0x4abe00 HighScoresDatabase::Default

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

void HighScoresDatabase__Default(void)

{
  undefined4 *in_EAX;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = in_EAX + 2;
  iVar3 = 10;
  do {
    iVar1 = 0;
    do {
      puVar2[iVar1 + 0xb8] = 0;
      puVar2[iVar1 + 0xc3] = 0;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0xb);
    *puVar2 = 0;
    puVar2 = puVar2 + 0xce;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar2 = in_EAX + 0x80e;
  iVar3 = 0x14;
  do {
    iVar1 = 0;
    do {
      puVar2[iVar1 + 0xb8] = 0;
      puVar2[iVar1 + 0xc3] = 0;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0xb);
    *puVar2 = 0;
    puVar2 = puVar2 + 0xd2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  in_EAX[0x1876] = 0;
  *in_EAX = 0;
  in_EAX[1] = 0;
  return;
}


// ==== 0x4abe90 FUN_004abe90

void FUN_004abe90(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *unaff_ESI;
  undefined4 *unaff_EDI;
  
  iVar1 = FUN_004abfc0(unaff_ESI,*unaff_EDI);
  if (DAT_00777b4c == 8) {
    unaff_ESI[1] = *(int *)(iVar1 + 0x344);
  }
  else {
    *unaff_ESI = *(int *)(iVar1 + 0x344);
  }
  if (DAT_00777b4c == 8) {
    iVar1 = unaff_ESI[1];
  }
  else {
    iVar1 = *unaff_ESI;
  }
  iVar2 = 0;
  if (0 < unaff_ESI[0x1876]) {
    piVar3 = unaff_ESI + 0x8df;
    while (*piVar3 != iVar1) {
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 0xd2;
      if (unaff_ESI[0x1876] <= iVar2) {
        return;
      }
    }
    if (unaff_ESI + iVar2 * 0xd2 + 0x80e != (int *)0x0) {
      FECarConfig__FillFromRide(unaff_ESI + iVar2 * 0xd2 + 0x80e,unaff_EDI);
    }
  }
  return;
}


// ==== 0x4abf10 FUN_004abf10

void __thiscall FUN_004abf10(int param_1,float param_2)

{
  int in_EAX;
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(param_1 + 0x237c);
  do {
    if (in_EAX == *piVar2) {
      iVar1 = FUN_004ac0b0();
      *(float *)(iVar1 + 0x340) = param_2 + *(float *)(iVar1 + 0x340);
      return;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 0xd2;
  } while (iVar1 < 0x14);
  return;
}


// ==== 0x4abf50 FUN_004abf50

uint FUN_004abf50(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *unaff_EDI;
  
  if (DAT_00777b4c == 8) {
    iVar5 = unaff_EDI[1];
  }
  else {
    iVar5 = *unaff_EDI;
  }
  piVar4 = unaff_EDI + 0x1877;
  piVar1 = (int *)0x0;
  piVar3 = piVar4;
  do {
    if (iVar5 == *piVar3) {
      iVar2 = 0;
      if (0 < unaff_EDI[0x18b3]) goto LAB_004abf90;
      goto LAB_004abf9c;
    }
    piVar1 = (int *)((int)piVar1 + 1);
    piVar3 = piVar3 + 4;
  } while ((int)piVar1 < 0xf);
  goto LAB_004abf7d;
  while( true ) {
    iVar2 = iVar2 + 1;
    piVar4 = piVar4 + 4;
    if (unaff_EDI[0x18b3] <= iVar2) break;
LAB_004abf90:
    if (*piVar4 == iVar5) {
      piVar1 = unaff_EDI + iVar2 * 4 + 0x1877;
      goto LAB_004abf9e;
    }
  }
LAB_004abf9c:
  piVar1 = (int *)0x0;
LAB_004abf9e:
  if (piVar1[2] == 8) {
    return CONCAT31((int3)((uint)piVar1 >> 8),1);
  }
LAB_004abf7d:
  return (uint)piVar1 & 0xffffff00;
}


// ==== 0x4abfc0 FUN_004abfc0

int FUN_004abfc0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  piVar3 = (int *)(param_1 + 0x2040);
  do {
    iVar1 = 0;
    piVar2 = (int *)(DAT_00734588 + 0xd0);
    do {
      if (*piVar2 == *piVar3) {
        iVar1 = iVar1 * 0xc90 + DAT_00734588;
        goto LAB_004abff8;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x324;
    } while (iVar1 < 0x23);
    iVar1 = 0;
LAB_004abff8:
    if (*(int *)(iVar1 + 0xc50) == param_2) {
      return iVar4 * 0x348 + 0x2038 + param_1;
    }
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 0xd2;
    if (0x13 < iVar4) {
      return 0;
    }
  } while( true );
}


// ==== 0x4ac040 FEPlayerCarDB::HasCarHandle

/* [canon] canon med (ghidra-canon+hopper) docs/re/canon.md */

uint __fastcall FEPlayerCarDB__HasCarHandle(int param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 0;
  piVar2 = (int *)(param_1 + 0x61dc);
  do {
    if (param_2 == *piVar2) {
      return CONCAT31((int3)(uVar1 >> 8),1);
    }
    uVar1 = uVar1 + 1;
    piVar2 = piVar2 + 4;
  } while ((int)uVar1 < 0xf);
  return uVar1 & 0xffffff00;
}


// ==== 0x4ac060 FUN_004ac060

int * FUN_004ac060(void)

{
  int iVar1;
  int *piVar2;
  int *unaff_ESI;
  int iVar3;
  
  if (DAT_00777b4c == 8) {
    iVar3 = unaff_ESI[1];
  }
  else {
    iVar3 = *unaff_ESI;
  }
  iVar1 = 0;
  if (0 < unaff_ESI[0x1876]) {
    piVar2 = unaff_ESI + 0x8df;
    do {
      if (*piVar2 == iVar3) {
        return unaff_ESI + iVar1 * 0xd2 + 0x80e;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0xd2;
    } while (iVar1 < unaff_ESI[0x1876]);
  }
  return (int *)0x0;
}


// ==== 0x4ac0b0 FUN_004ac0b0

int FUN_004ac0b0(void)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar1 = 0;
  if (0 < *(int *)(unaff_ESI + 0x61d8)) {
    piVar2 = (int *)(unaff_ESI + 0x237c);
    do {
      if (*piVar2 == unaff_EDI) {
        return iVar1 * 0x348 + 0x2038 + unaff_ESI;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0xd2;
    } while (iVar1 < *(int *)(unaff_ESI + 0x61d8));
  }
  return 0;
}


// ==== 0x4ac0f0 cFrontendDatabase::BuildRideForCarHandle

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void __fastcall cFrontendDatabase__BuildRideForCarHandle(int param_1,int param_2,int param_3)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  iVar1 = 0;
  piVar3 = (int *)(param_1 + 0x237c);
  do {
    if (in_EAX == *piVar3) {
      uVar2 = FUN_004ac0b0(param_2,param_3);
      FECarConfig__BuildRide(uVar2,param_2,param_3);
      return;
    }
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 0xd2;
  } while (iVar1 < 0x14);
  iVar1 = 0;
  piVar3 = (int *)(param_1 + 0x61dc);
  do {
    if (in_EAX == *piVar3) {
      uVar2 = FUN_004f42f0("DUMMY_SKIN%d",param_2 + 1);
      *(undefined4 *)(param_3 + 0x444) = uVar2;
      uVar2 = FUN_004f42f0("DUMMY_WHEEL%d",param_2 + 1);
      *(undefined4 *)(param_3 + 0x448) = uVar2;
      FUN_004ac1f0(param_3);
      PresetRide__ApplyToRide();
      iVar1 = 0;
      piVar3 = (int *)(param_1 + 0x61e4);
      while ((in_EAX != piVar3[-2] || (*piVar3 != 8))) {
        iVar1 = iVar1 + 1;
        piVar3 = piVar3 + 4;
        if (0xe < iVar1) {
          return;
        }
      }
      puVar4 = (undefined4 *)(param_3 + 8);
      for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = 2;
        puVar4 = puVar4 + 1;
      }
      RideInfo__RebuildPhysicsInfo(1);
      return;
    }
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 4;
  } while (iVar1 < 0xf);
  if (((&DAT_0076027c)[param_2 * 0x7ca2] != 0) && (in_EAX == (&DAT_0075f23c)[param_2 * 0x3e51])) {
    FECarConfig__BuildRide(&DAT_0075eef8 + param_2 * 0x3e51,param_2,param_3);
  }
  return;
}


// ==== 0x4ac1f0 FUN_004ac1f0

int FUN_004ac1f0(void)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar1 = 0;
  if (0 < *(int *)(unaff_ESI + 0x62cc)) {
    piVar2 = (int *)(unaff_ESI + 0x61dc);
    do {
      if (*piVar2 == unaff_EDI) {
        return iVar1 * 0x10 + 0x61dc + unaff_ESI;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 4;
    } while (iVar1 < *(int *)(unaff_ESI + 0x62cc));
  }
  return 0;
}


// ==== 0x4ac220 FUN_004ac220

void FUN_004ac220(void)

{
  byte *pbVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x62cc) = 0;
  pcVar7 = "ONLINE_RX7";
  iVar9 = -1;
  uVar3 = 0x4f;
  do {
    iVar9 = iVar9 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar7 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar7 = pcVar7 + 1;
  } while (*pbVar1 != 0);
  pcVar7 = "ONLINE_1";
  iVar4 = -1;
  uVar3 = 0x4f;
  do {
    iVar4 = iVar4 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar7 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar7 = pcVar7 + 1;
  } while (*pbVar1 != 0);
  *(int *)(unaff_ESI + 0x61dc) = iVar4;
  *(int *)((*(int *)(unaff_ESI + 0x62cc) + 0x61e) * 0x10 + unaff_ESI) = iVar9;
  *(undefined4 *)(*(int *)(unaff_ESI + 0x62cc) * 0x10 + 0x61e4 + unaff_ESI) = 8;
  *(undefined4 *)(*(int *)(unaff_ESI + 0x62cc) * 0x10 + 0x61e8 + unaff_ESI) = 0xffffffff;
  iVar9 = *(int *)(unaff_ESI + 0x62cc) + 1;
  *(int *)(unaff_ESI + 0x62cc) = iVar9;
  pcVar7 = "ONLINE_NEON";
  iVar4 = -1;
  uVar3 = 0x4f;
  do {
    iVar4 = iVar4 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar7 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar7 = pcVar7 + 1;
  } while (*pbVar1 != 0);
  pcVar7 = "ONLINE_2";
  iVar8 = -1;
  uVar3 = 0x4f;
  do {
    iVar8 = iVar8 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar7 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar7 = pcVar7 + 1;
  } while (*pbVar1 != 0);
  *(int *)(iVar9 * 0x10 + 0x61dc + unaff_ESI) = iVar8;
  *(int *)((*(int *)(unaff_ESI + 0x62cc) + 0x61e) * 0x10 + unaff_ESI) = iVar4;
  *(undefined4 *)(*(int *)(unaff_ESI + 0x62cc) * 0x10 + 0x61e4 + unaff_ESI) = 8;
  iVar4 = -1;
  *(undefined4 *)(*(int *)(unaff_ESI + 0x62cc) * 0x10 + 0x61e8 + unaff_ESI) = 0xffffffff;
  iVar9 = *(int *)(unaff_ESI + 0x62cc) + 1;
  *(int *)(unaff_ESI + 0x62cc) = iVar9;
  pcVar7 = "ONLINE_CELICA";
  uVar3 = 0x4f;
  do {
    iVar4 = iVar4 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar7 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar7 = pcVar7 + 1;
  } while (*pbVar1 != 0);
  pcVar7 = "ONLINE_3";
  uVar3 = 0x4f;
  iVar8 = -1;
  do {
    iVar8 = iVar8 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar7 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar7 = pcVar7 + 1;
  } while (*pbVar1 != 0);
  *(int *)(iVar9 * 0x10 + 0x61dc + unaff_ESI) = iVar8;
  *(int *)((*(int *)(unaff_ESI + 0x62cc) + 0x61e) * 0x10 + unaff_ESI) = iVar4;
  *(undefined4 *)(*(int *)(unaff_ESI + 0x62cc) * 0x10 + 0x61e4 + unaff_ESI) = 8;
  *(undefined4 *)(*(int *)(unaff_ESI + 0x62cc) * 0x10 + 0x61e8 + unaff_ESI) = 0xffffffff;
  *(int *)(unaff_ESI + 0x62cc) = *(int *)(unaff_ESI + 0x62cc) + 1;
  iVar9 = 0;
  if (0 < DAT_007343fc) {
    iVar8 = 0;
    iVar4 = DAT_007343fc;
    do {
      if ((iVar8 < 0) || (iVar4 <= iVar9)) {
        iVar5 = 0;
      }
      else {
        iVar5 = DAT_007343f8 + iVar8;
      }
      if (*(short *)(iVar5 + 4) == 3) {
        uVar2 = *(undefined4 *)(iVar5 + 8);
        uVar6 = FUN_004f42f0("STYLE_SPONSOR_CAR_%d",iVar9);
        *(undefined4 *)(*(int *)(unaff_ESI + 0x62cc) * 0x10 + 0x61dc + unaff_ESI) = uVar6;
        *(undefined4 *)((*(int *)(unaff_ESI + 0x62cc) + 0x61e) * 0x10 + unaff_ESI) = uVar2;
        *(undefined4 *)(*(int *)(unaff_ESI + 0x62cc) * 0x10 + 0x61e4 + unaff_ESI) = 0xff;
        *(int *)(*(int *)(unaff_ESI + 0x62cc) * 0x10 + 0x61e8 + unaff_ESI) = iVar9;
        iVar4 = DAT_007343fc;
        *(int *)(unaff_ESI + 0x62cc) = *(int *)(unaff_ESI + 0x62cc) + 1;
      }
      iVar9 = iVar9 + 1;
      iVar8 = iVar8 + 0x20;
    } while (iVar9 < iVar4);
  }
  return;
}


// ==== 0x4ac460 CustomizationDB::Init

/* [canon] canon med (hopper+ghidra+capstone) docs/re/canon.md */

void CustomizationDB__Init(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  puVar1 = param_1;
  param_1 = param_1 + 2;
  iVar5 = 0;
  do {
    if ((iVar5 < 0) || (puVar4 = param_1, 9 < iVar5)) {
      puVar4 = (undefined4 *)0x0;
    }
    uVar2 = FUN_004f42f0("PRESET_SLOT_%d",iVar5);
    puVar6 = puVar4;
    for (iVar3 = 0xce; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    iVar5 = iVar5 + 1;
    param_1 = param_1 + 0xce;
    puVar4[1] = uVar2;
  } while (iVar5 < 10);
  puVar1[0x1876] = 0;
  iVar5 = 0;
  do {
    iVar3 = DAT_00734588 + iVar5;
    if ((((iVar3 != 0) && (*(char *)(iVar3 + 0x40) != '\0')) && (*(int *)(iVar3 + 0xc54) == 0)) &&
       ((int)puVar1[0x1876] < 0x14)) {
      FUN_004f42f0("CUSTOMIZABLE_%s",iVar3);
      FUN_004acb90();
      puVar1[0x1876] = puVar1[0x1876] + 1;
    }
    iVar5 = iVar5 + 0xc90;
  } while (iVar5 < 0x1b7b0);
  iVar5 = FUN_004abfc0(puVar1,param_2);
  *puVar1 = *(undefined4 *)(iVar5 + 0x344);
  puVar1[1] = *(undefined4 *)(iVar5 + 0x344);
  return;
}


// ==== 0x4ac550 FUN_004ac550

void __fastcall FUN_004ac550(int param_1,int param_2)

{
  int iVar1;
  int unaff_ESI;
  
  if (unaff_ESI == 0) {
    *(undefined1 *)(param_1 + 0x10 + param_2) = 0;
    *(undefined1 *)(param_1 + 0x88 + param_2) = 0;
    *(undefined4 *)(param_2 + 0x100 + param_1 * 4) = 0;
    return;
  }
  *(undefined1 *)(param_1 + 0x10 + param_2) = *(undefined1 *)(unaff_ESI + 0x10);
  iVar1 = 0;
  do {
    if (*(int *)(unaff_ESI + 4) == (&DAT_006fb730)[iVar1]) goto LAB_004ac572;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x20);
  iVar1 = 0;
LAB_004ac572:
  *(char *)(param_1 + 0x88 + param_2) = (char)iVar1;
  *(undefined4 *)(param_2 + 0x100 + param_1 * 4) = *(undefined4 *)(unaff_ESI + 8);
  return;
}


// ==== 0x4ac5a0 FECarConfig::BuildRide

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void FECarConfig__BuildRide(int param_1,int param_2,undefined4 *param_3)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  byte *pbVar6;
  char *pcVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int *local_758;
  byte local_750;
  byte local_74f [1867];
  
  RideInfo__Init();
  iVar3 = 0;
  piVar5 = (int *)(DAT_00734588 + 0xd0);
  do {
    if (*piVar5 == *(int *)(param_1 + 8)) {
      iVar3 = iVar3 * 0xc90 + DAT_00734588;
      goto LAB_004ac5e6;
    }
    iVar3 = iVar3 + 1;
    piVar5 = piVar5 + 0x324;
  } while (iVar3 < 0x23);
  iVar3 = 0;
LAB_004ac5e6:
  uVar9 = 1;
  *param_3 = *(undefined4 *)(iVar3 + 0xc50);
  uVar4 = 1;
  if (param_2 == 1) {
    uVar4 = 2;
    uVar9 = 2;
  }
  FUN_00565da0("DUMMY_SKIN%d",uVar4);
  iVar3 = -1;
  pbVar6 = &local_750;
  bVar2 = local_750;
  while (bVar2 != 0) {
    iVar3 = iVar3 * 0x21 + (uint)bVar2;
    pbVar1 = pbVar6 + 1;
    pbVar6 = pbVar6 + 1;
    bVar2 = *pbVar1;
  }
  param_3[0x111] = iVar3;
  FUN_00565da0("DUMMY_WHEEL%d",uVar9);
  iVar3 = -1;
  pbVar6 = &local_750;
  while (local_750 != 0) {
    pbVar1 = pbVar6 + 1;
    iVar3 = iVar3 * 0x21 + (uint)local_750;
    pbVar6 = pbVar6 + 1;
    local_750 = *pbVar1;
  }
  param_3[0x112] = iVar3;
  local_758 = (int *)(param_1 + 0x100);
  iVar3 = -(int)param_3;
  pcVar7 = (char *)(param_3 + 0x18b);
  puVar8 = param_3 + 0x113;
  do {
    if (*local_758 == 0) {
      *puVar8 = 0;
    }
    else {
      uVar4 = CarPartDatabase__GetCarPart
                        ((&DAT_006fb730)[pcVar7[param_1 + iVar3 + -0x5a4]],
                         (int)pcVar7[param_1 + iVar3 + -0x61c],*local_758,0,0xffffffff);
      *puVar8 = uVar4;
    }
    *pcVar7 = *pcVar7 + '\x01';
    RideInfo__UpdatePartsEnabled(param_3);
    local_758 = local_758 + 1;
    puVar8 = puVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while ((int)(pcVar7 + iVar3 + -0x62c) < 0x78);
  puVar8 = (undefined4 *)(param_1 + 0x2e0);
  puVar10 = param_3 + 2;
  for (iVar3 = 0x16; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar10 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar10 = puVar10 + 1;
  }
  RideInfo__RebuildPhysicsInfo(1);
  *(undefined1 *)((int)param_3 + 0x425) = *(undefined1 *)(param_1 + 0xc);
  return;
}


// ==== 0x4ac750 FECarConfig::FillFromRide

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void FECarConfig__FillFromRide(undefined4 *param_1,int *param_2)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  int *piVar9;
  
  puVar3 = param_1;
  iVar4 = *param_2 * 0xc90 + DAT_00734588;
  iVar6 = -1;
  bVar2 = *(byte *)(*param_2 * 0xc90 + DAT_00734588);
  while (bVar2 != 0) {
    iVar6 = iVar6 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(iVar4 + 1);
    iVar4 = iVar4 + 1;
    bVar2 = *pbVar1;
  }
  param_1[2] = iVar6;
  puVar5 = param_1 + 4;
  puVar8 = param_1 + 0x40;
  piVar7 = param_2 + 0x113;
  param_1 = (undefined4 *)0x78;
  do {
    iVar4 = *piVar7;
    if (iVar4 == 0) {
      *(undefined1 *)(puVar5 + 0x1e) = 0;
      *(undefined1 *)puVar5 = 0;
      *puVar8 = 0;
    }
    else {
      iVar6 = 0;
      do {
        if (*(int *)(iVar4 + 4) == (&DAT_006fb730)[iVar6]) goto LAB_004ac7c1;
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0x20);
      iVar6 = 0;
LAB_004ac7c1:
      *(char *)(puVar5 + 0x1e) = (char)iVar6;
      *(undefined1 *)puVar5 = *(undefined1 *)(iVar4 + 0x10);
      *puVar8 = *(undefined4 *)(iVar4 + 8);
    }
    piVar7 = piVar7 + 1;
    puVar8 = puVar8 + 1;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    param_1 = (undefined4 *)((int)param_1 + -1);
    if (param_1 == (undefined4 *)0x0) {
      piVar7 = param_2 + 2;
      piVar9 = puVar3 + 0xb8;
      for (iVar4 = 0x16; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar9 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar9 = piVar9 + 1;
      }
      *(undefined1 *)(puVar3 + 3) = *(undefined1 *)((int)param_2 + 0x425);
      *puVar3 = 1;
      return;
    }
  } while( true );
}


// ==== 0x4ac820 FUN_004ac820

void FUN_004ac820(int param_1)

{
  byte *pbVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  char *pcVar13;
  undefined *puVar14;
  int iVar15;
  int local_40;
  float local_3c;
  int local_34;
  
  if (*(int *)(param_1 + 0x178) != 0) {
    uVar2 = (&DAT_006fb730)[*(char *)(param_1 + 0xa6)];
    iVar9 = CarPartDatabase__GetCarPart
                      (uVar2,(int)*(char *)(param_1 + 0x2e),*(int *)(param_1 + 0x178),0,0xffffffff);
    if (iVar9 != 0) {
      puVar14 = &DAT_006c7a38;
      iVar12 = -1;
      uVar10 = 0x52;
      do {
        iVar12 = iVar12 * 0x21 + uVar10;
        pbVar1 = puVar14 + 1;
        uVar10 = (uint)*pbVar1;
        puVar14 = puVar14 + 1;
      } while (*pbVar1 != 0);
      iVar15 = (int)*(short *)(iVar9 + 0x1c);
      piVar11 = *(int **)(iVar9 + 0x14);
      piVar8 = piVar11;
      if (piVar11 != (int *)0x0) {
        for (; piVar8 < piVar11 + iVar15 * 2; piVar8 = piVar8 + 2) {
          if ((iVar12 == 0) || (*piVar8 == iVar12)) {
            if (piVar8 != (int *)0x0) {
              local_40 = piVar8[1];
              goto LAB_004ac8bb;
            }
            break;
          }
        }
      }
      local_40 = 0;
LAB_004ac8bb:
      fVar3 = (float)local_40;
      pcVar13 = "GREEN";
      uVar10 = 0x47;
      iVar9 = -1;
      do {
        iVar9 = iVar9 * 0x21 + uVar10;
        pbVar1 = (byte *)(pcVar13 + 1);
        uVar10 = (uint)*pbVar1;
        pcVar13 = pcVar13 + 1;
      } while (*pbVar1 != 0);
      piVar8 = piVar11;
      if (piVar11 != (int *)0x0) {
        for (; piVar8 < piVar11 + iVar15 * 2; piVar8 = piVar8 + 2) {
          if ((iVar9 == 0) || (*piVar8 == iVar9)) {
            if (piVar8 != (int *)0x0) {
              local_40 = piVar8[1];
              goto LAB_004ac90b;
            }
            break;
          }
        }
      }
      local_40 = 0;
LAB_004ac90b:
      fVar4 = (float)local_40;
      puVar14 = &DAT_006c7a28;
      uVar10 = 0x42;
      iVar9 = -1;
      do {
        iVar9 = iVar9 * 0x21 + uVar10;
        pbVar1 = puVar14 + 1;
        uVar10 = (uint)*pbVar1;
        puVar14 = puVar14 + 1;
      } while (*pbVar1 != 0);
      piVar8 = piVar11 + iVar15 * 2;
      if (piVar11 != (int *)0x0) {
        for (; piVar11 < piVar8; piVar11 = piVar11 + 2) {
          if ((iVar9 == 0) || (*piVar11 == iVar9)) {
            if (piVar11 != (int *)0x0) {
              local_40 = piVar11[1];
              goto LAB_004ac95b;
            }
            break;
          }
        }
      }
      local_40 = 0;
LAB_004ac95b:
      fVar5 = (float)local_40;
      local_3c = 0.0;
      local_34 = 0;
      iVar9 = CarPartDatabase__GetCarPart(uVar2,0x1e,0,0,0xffffffff);
      if (iVar9 != 0) {
        do {
          puVar14 = &DAT_006c7a38;
          iVar12 = -1;
          uVar10 = 0x52;
          do {
            iVar12 = iVar12 * 0x21 + uVar10;
            pbVar1 = puVar14 + 1;
            uVar10 = (uint)*pbVar1;
            puVar14 = puVar14 + 1;
          } while (*pbVar1 != 0);
          iVar15 = (int)*(short *)(iVar9 + 0x1c);
          piVar11 = *(int **)(iVar9 + 0x14);
          piVar8 = piVar11;
          if (piVar11 != (int *)0x0) {
            for (; piVar8 < piVar11 + iVar15 * 2; piVar8 = piVar8 + 2) {
              if ((iVar12 == 0) || (*piVar8 == iVar12)) {
                if (piVar8 != (int *)0x0) {
                  local_40 = piVar8[1];
                  goto LAB_004ac9e6;
                }
                break;
              }
            }
          }
          local_40 = 0;
LAB_004ac9e6:
          fVar6 = (float)local_40;
          pcVar13 = "GREEN";
          iVar12 = -1;
          uVar10 = 0x47;
          do {
            iVar12 = iVar12 * 0x21 + uVar10;
            pbVar1 = (byte *)(pcVar13 + 1);
            uVar10 = (uint)*pbVar1;
            pcVar13 = pcVar13 + 1;
          } while (*pbVar1 != 0);
          piVar8 = piVar11;
          if (piVar11 != (int *)0x0) {
            for (; piVar8 < piVar11 + iVar15 * 2; piVar8 = piVar8 + 2) {
              if ((iVar12 == 0) || (*piVar8 == iVar12)) {
                if (piVar8 != (int *)0x0) {
                  local_40 = piVar8[1];
                  goto LAB_004aca34;
                }
                break;
              }
            }
          }
          local_40 = 0;
LAB_004aca34:
          fVar7 = (float)local_40;
          puVar14 = &DAT_006c7a28;
          iVar12 = -1;
          uVar10 = 0x42;
          do {
            iVar12 = iVar12 * 0x21 + uVar10;
            pbVar1 = puVar14 + 1;
            uVar10 = (uint)*pbVar1;
            puVar14 = puVar14 + 1;
          } while (*pbVar1 != 0);
          piVar8 = piVar11 + iVar15 * 2;
          if (piVar11 != (int *)0x0) {
            for (; piVar11 < piVar8; piVar11 = piVar11 + 2) {
              if ((iVar12 == 0) || (*piVar11 == iVar12)) {
                if (piVar11 != (int *)0x0) {
                  local_40 = piVar11[1];
                  goto LAB_004aca82;
                }
                break;
              }
            }
          }
          local_40 = 0;
LAB_004aca82:
          fVar6 = SQRT((fVar6 - fVar3) * (fVar6 - fVar3) +
                       ((float)local_40 - fVar5) * ((float)local_40 - fVar5) +
                       (fVar7 - fVar4) * (fVar7 - fVar4));
          if (local_3c < fVar6) {
            local_3c = fVar6;
            local_34 = iVar9;
          }
          iVar9 = CarPartDatabase__GetCarPart(uVar2,0x1e,0,iVar9,0xffffffff);
        } while (iVar9 != 0);
        if (local_34 != 0) {
          FUN_004ac550();
        }
      }
    }
  }
  return;
}


// ==== 0x4acb90 FUN_004acb90

void __fastcall FUN_004acb90(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 in_EAX;
  byte *pbVar3;
  int unaff_EBX;
  int iVar4;
  byte local_750;
  byte local_74f [31];
  undefined1 local_730 [1060];
  char local_30c;
  undefined4 local_308;
  int local_2ec;
  int local_2e8;
  int local_26c;
  char local_e6;
  
  *(undefined4 *)(unaff_EBX + 0x344) = in_EAX;
  iVar4 = param_1 * 0xc90 + DAT_00734588;
  RideInfo__Init();
  Ride_Init(1,0,0);
  FUN_00565da0("DUMMY_SKIN%d",1);
  local_2ec = -1;
  pbVar3 = &local_750;
  bVar2 = local_750;
  while (bVar2 != 0) {
    local_2ec = local_2ec * 0x21 + (uint)bVar2;
    pbVar1 = pbVar3 + 1;
    pbVar3 = pbVar3 + 1;
    bVar2 = *pbVar1;
  }
  FUN_00565da0("DUMMY_WHEEL%d",1);
  local_2e8 = -1;
  pbVar3 = &local_750;
  while (local_750 != 0) {
    local_2e8 = local_2e8 * 0x21 + (uint)local_750;
    pbVar1 = pbVar3 + 1;
    pbVar3 = pbVar3 + 1;
    local_750 = *pbVar1;
  }
  FUN_0057d340(local_730);
  FUN_0057e9a0(local_730);
  iVar4 = CarPartDatabase__GetCarPart(0,0x1e,*(undefined4 *)(iVar4 + 0xc5c),0,0xffffffff);
  if (iVar4 != 0) {
    local_e6 = local_e6 + '\x01';
    local_26c = iVar4;
    RideInfo__UpdatePartsEnabled(local_730);
  }
  if (local_30c == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  *(undefined4 *)(unaff_EBX + 0x338) = local_308;
  FECarConfig__FillFromRide(unaff_EBX,local_730);
  *(undefined4 *)(unaff_EBX + 0x340) = 0;
  return;
}


// ==== 0x4acce0 FECarConfig::GetCarType

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 FECarConfig__GetCarType(void)

{
  int in_EAX;
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(DAT_00734588 + 0xd0);
  do {
    if (*piVar2 == *(int *)(in_EAX + 8)) {
      return *(undefined4 *)(iVar1 * 0xc90 + DAT_00734588 + 0xc50);
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 0x324;
  } while (iVar1 < 0x23);
  return uRam00000c50;
}


// ==== 0x4acd20 FUN_004acd20

/* WARNING: Removing unreachable block (ram,0x004ad14a) */
/* WARNING: Removing unreachable block (ram,0x004ad05b) */
/* WARNING: Removing unreachable block (ram,0x004ad0ba) */
/* WARNING: Removing unreachable block (ram,0x004ad1e1) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004acd20(int *param_1,char param_2)

{
  float fVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int *unaff_ESI;
  uint uVar10;
  float10 fVar11;
  int *local_4;
  
  piVar2 = param_1;
  iVar7 = *param_1;
  if (iVar7 == 0) {
    param_1 = (int *)0x0;
  }
  else {
    param_1 = *(int **)(iVar7 + 0x18);
  }
  if ((((*(char *)(*(int *)(iVar7 + 0x14) + 0x734) != '\0') && (param_2 == '\0')) &&
      (piVar4 = (int *)Race__GetPlayer((int)*(short *)(iVar7 + 10)), piVar4 != (int *)0x0)) &&
     (((iVar5 = *piVar4, iVar5 == 3 || (iVar5 == 4)) ||
      ((iVar5 == 5 || ((iVar5 == 0 || (iVar5 == 6)))))))) {
    FUN_004a9990();
    return;
  }
  *unaff_ESI = (int)*(char *)((int)piVar2 + 10);
  unaff_ESI[1] = (int)*(short *)(*piVar2 + 10);
  unaff_ESI[2] = (int)(short)piVar2[4];
  unaff_ESI[3] = piVar2[0x44];
  Floats11_Max();
  iVar5 = _ftol_nocw();
  unaff_ESI[0x31] = iVar5;
  unaff_ESI[6] = piVar2[0x46];
  unaff_ESI[7] = piVar2[0x47];
  unaff_ESI[0x1e] = (int)*(char *)((int)piVar2 + 9);
  unaff_ESI[0x1f] = piVar2[5];
  unaff_ESI[0x2b] = *(int *)(*piVar2 + 0x3b8);
  unaff_ESI[0x2c] = piVar2[0x48];
  unaff_ESI[0x2d] = piVar2[0x4a];
  unaff_ESI[0x2e] = piVar2[0x49];
  unaff_ESI[0x55] = piVar2[0x4b];
  unaff_ESI[0x54] = piVar2[0x4c];
  unaff_ESI[0x2a] = 0;
  unaff_ESI[4] = 0;
  if (0 < unaff_ESI[0x1e]) {
    unaff_ESI[4] = piVar2[*(char *)(DAT_0073619c + 0x53f) + 0x18];
  }
  if (param_1 == (int *)0x0) {
    unaff_ESI[0x2f] = 0;
    unaff_ESI[0x30] = 0;
    unaff_ESI[5] = -1;
  }
  else {
    unaff_ESI[0x2f] = *(int *)((int)param_1 + 0x9dc);
    fVar1 = *(float *)(*(int *)(iVar7 + 0x14) + 0x738);
    if (fVar1 <= _K_ONE) {
      fVar1 = _K_ONE;
    }
    unaff_ESI[0x30] = (int)fVar1;
    unaff_ESI[5] = (int)*(char *)((int)param_1 + 0x22);
  }
  unaff_ESI[0x52] = 0;
  unaff_ESI[0x53] = 0;
  piVar4 = unaff_ESI + 0x48;
  for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  piVar4 = unaff_ESI + 0x3d;
  for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  if ((param_1 != (int *)0x0) && ((DAT_0078a345 != '\0' || (DAT_007361a4 != 0)))) {
    iVar7 = *(int *)((int)param_1 + 0x960);
    iVar5 = _ftol_nocw();
    unaff_ESI[0x52] = iVar5;
    unaff_ESI[0x53] = *(int *)(iVar7 + 0x2c);
  }
  piVar4 = unaff_ESI + 0x13;
  iVar7 = 0xb;
  do {
    piVar4[-0xb] = 0;
    *piVar4 = 0;
    piVar4[0x1f] = 0;
    piVar4 = piVar4 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  _param_2 = 1;
  if (0 < DAT_0078a31c) {
    local_4 = (int *)((int)param_1 + 0xa0c);
    piVar4 = unaff_ESI + 0x14;
    piVar9 = piVar2 + 0x2e;
    do {
      if (10 < _param_2) break;
      piVar4[-0xb] = piVar9[-0xb];
      *piVar4 = *piVar9;
      iVar7 = _ftol_nocw();
      piVar4[0x1f] = iVar7;
      piVar4[0x2a] = piVar4[0x29] + iVar7;
      if (param_1 != (int *)0x0) {
        piVar4[0x34] = *local_4;
      }
      _param_2 = _param_2 + 1;
      local_4 = local_4 + 1;
      piVar9 = piVar9 + 1;
      piVar4 = piVar4 + 1;
    } while (_param_2 <= DAT_0078a31c);
  }
  if (((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) && (cVar3 = FUN_0043a2e0(), cVar3 == '\0')) {
    *unaff_ESI = unaff_ESI[DAT_0078a31c + 0x47];
  }
  if (unaff_ESI[2] == 3) {
    unaff_ESI[3] = 0;
  }
  if (unaff_ESI[2] == 1) {
    if ((((float)unaff_ESI[0x2e] < 0.0 != ((float)unaff_ESI[0x2e] == 0.0)) || (unaff_ESI[0x2d] == 0)
        ) || (unaff_ESI[0x2d] == 0x7fffffff)) {
      uVar8 = DAT_006f227c % 0x7fffffff;
      uVar10 = DAT_006f227c ^ 0x1d872b41;
      uVar6 = uVar10 >> 5 ^ uVar10;
      DAT_006f227c = uVar6 << 0x1b ^ uVar6 ^ uVar10;
      fVar1 = (float)uVar8 * 4.656613e-10;
      unaff_ESI[0x2e] =
           (int)(((fVar1 + fVar1) - _K_ONE) * *(float *)(*(int *)(*piVar2 + 0x10) + 0x440) * 0.05 +
                *(float *)(*(int *)(*piVar2 + 0x10) + 0x440));
      uVar8 = DAT_006f227c ^ 0x1d872b41;
      uVar6 = uVar8 >> 5 ^ uVar8;
      DAT_006f227c = uVar6 << 0x1b ^ uVar6 ^ uVar8;
      iVar7 = _ftol_nocw();
      unaff_ESI[0x2d] = iVar7;
    }
    if ((unaff_ESI[0x2c] == 0) || (unaff_ESI[0x2c] == 0x7fffffff)) {
      uVar8 = DAT_006f227c ^ 0x1d872b41;
      uVar6 = uVar8 >> 5 ^ uVar8;
      DAT_006f227c = uVar6 << 0x1b ^ uVar6 ^ uVar8;
      iVar7 = _ftol_nocw();
      unaff_ESI[0x2c] = iVar7;
    }
    if (((char)piVar2[0x45] != '\0') && ((DAT_0078a344 != '\0' || (DAT_007361a8 != 0)))) {
      fVar11 = (float10)RideInfo__GetTheoreticalTopSpeed();
      uVar10 = DAT_006f227c % 0x7fffffff;
      uVar8 = DAT_006f227c ^ 0x1d872b41;
      uVar6 = uVar8 >> 5 ^ uVar8;
      DAT_006f227c = uVar6 << 0x1b ^ uVar6 ^ uVar8;
      unaff_ESI[6] = (int)(float)(fVar11 - (float10)uVar10 * (float10)4.656613e-10 * fVar11 *
                                           (float10)0.05);
    }
  }
  return;
}


// ==== 0x4ad210 FUN_004ad210

void FUN_004ad210(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar2 = 0;
  *(undefined4 *)(unaff_EDI + 0xae0) = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    puVar1 = (undefined4 *)(param_1 + 0x520);
    do {
      FUN_004acd20(*puVar1,0);
      *(int *)(unaff_EDI + 0xae0) = *(int *)(unaff_EDI + 0xae0) + 1;
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x24));
  }
  FUN_004ad2d0();
  return;
}


// ==== 0x4ad270 RacingCars_FindByKey

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

int RacingCars_FindByKey(void)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar1 = 0;
  if (0 < *(int *)(unaff_ESI + 0xae0)) {
    piVar2 = (int *)(unaff_ESI + 4);
    do {
      if (*piVar2 == unaff_EDI) {
        return iVar1 * 0x15c + unaff_ESI;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x57;
    } while (iVar1 < *(int *)(unaff_ESI + 0xae0));
  }
  return 0;
}


// ==== 0x4ad2a0 FUN_004ad2a0

int * FUN_004ad2a0(void)

{
  int iVar1;
  int *piVar2;
  int *unaff_ESI;
  int unaff_EDI;
  
  iVar1 = 0;
  piVar2 = unaff_ESI;
  if (0 < unaff_ESI[0x2b8]) {
    do {
      if (*piVar2 == unaff_EDI) {
        return unaff_ESI + iVar1 * 0x57;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x57;
    } while (iVar1 < unaff_ESI[0x2b8]);
  }
  return (int *)0x0;
}


// ==== 0x4ad2d0 FUN_004ad2d0

void FUN_004ad2d0(void)

{
  int ***pppiVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int ****ppppiVar5;
  int ****ppppiVar6;
  undefined4 *puVar7;
  int iVar8;
  int **ppiVar9;
  int **local_28;
  int local_24;
  int ***local_20;
  int ***local_1c;
  void *local_14;
  code *pcStack_10;
  undefined4 local_c;
  
  pcStack_10 = FUN_00686858;
  local_14 = ExceptionList;
  local_20 = (int ***)&local_20;
  local_c = 0;
  local_24 = 0;
  ExceptionList = &local_14;
  local_1c = (int ***)&local_20;
  if (0 < DAT_0078a328 + DAT_0078a32c + DAT_0078a324 + DAT_0078a320) {
    local_28 = (int **)&DAT_00777cd0;
    iVar8 = DAT_007349b4;
    ExceptionList = &local_14;
    do {
      local_28[0x2a] = (int *)0x0;
      iVar3 = iVar8;
      if (iVar8 == 0) {
        iVar3 = FUN_00566dc0(0xc,"bPNode SlotPool",0);
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else if (DAT_0073d814 == 1) {
          bList__AddTail();
        }
        DAT_007349b8 = 0;
        DAT_007349b4 = iVar3;
      }
      iVar8 = iVar3;
      if ((*(int *)(iVar3 + 0x10) == 0) && ((*(byte *)(iVar3 + 0x14) & 1) != 0)) {
        FUN_00566e60();
        iVar8 = DAT_007349b4;
      }
      ppppiVar5 = *(int *****)(iVar3 + 0x10);
      iVar4 = *(int *)(iVar3 + 0x18) + 1;
      if (ppppiVar5 == (int ****)0x0) {
        ppppiVar5 = (int ****)0x0;
      }
      else {
        pppiVar1 = *ppppiVar5;
        if (*(int *)(iVar3 + 0x1c) < iVar4) {
          *(int *)(iVar3 + 0x1c) = iVar4;
        }
        *(int *)(iVar3 + 0x18) = iVar4;
        *(int ****)(iVar3 + 0x10) = pppiVar1;
        if (((*(byte *)(iVar3 + 0x14) & 2) != 0) &&
           (iVar3 = *(int *)(iVar3 + 0x28) >> 2, ppppiVar6 = ppppiVar5, 0 < iVar3)) {
          for (; iVar3 != 0; iVar3 = iVar3 + -1) {
            *ppppiVar6 = (int ***)0x0;
            ppppiVar6 = ppppiVar6 + 1;
          }
        }
        ppppiVar5[2] = (int ***)local_28;
      }
      *local_1c = (int **)ppppiVar5;
      ppppiVar5[1] = local_1c;
      *ppppiVar5 = (int ***)&local_20;
      local_28 = local_28 + 0x57;
      local_24 = local_24 + 1;
      local_1c = (int ***)ppppiVar5;
    } while (local_24 < DAT_0078a328 + DAT_0078a32c + DAT_0078a324 + DAT_0078a320);
  }
  DAT_00735ecc = 1;
  while( true ) {
    iVar8 = DAT_0078a31c;
    iVar3 = DAT_0078a31c;
    if (10 < DAT_0078a31c) {
      iVar3 = 0xb;
    }
    if (iVar3 < DAT_00735ecc) break;
    bList__Sort(&local_20,SortRacingCarByTime);
    ppppiVar5 = (int ****)local_20;
    ppiVar9 = (int **)0x1;
    ppppiVar6 = (int ****)NullUpdate_ret();
    for (; ppppiVar5 != ppppiVar6; ppppiVar5 = (int ****)*ppppiVar5) {
      pppiVar1 = ppppiVar5[2];
      pppiVar1[DAT_00735ecc + 0x1f] = ppiVar9;
      if (ppiVar9 == (int **)0x1) {
        pppiVar1 = pppiVar1 + 0x2a;
        *pppiVar1 = (int **)((int)*pppiVar1 + 1);
      }
      ppiVar9 = (int **)((int)ppiVar9 + 1);
    }
    DAT_00735ecc = DAT_00735ecc + 1;
  }
  if ((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) {
    iVar3 = DAT_0078a328 + DAT_0078a32c + DAT_0078a324 + DAT_0078a320;
    if (0 < iVar3) {
      puVar7 = &DAT_00777d78;
      do {
        *puVar7 = 0;
        puVar7 = puVar7 + 0x57;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    DAT_00735ecc = 1;
    while( true ) {
      if (10 < iVar8) {
        iVar8 = 0xb;
      }
      if (iVar8 < DAT_00735ecc) break;
      bList__Sort(&local_20,SortRacingCarByTable2);
      ppppiVar5 = (int ****)local_20;
      ppiVar9 = (int **)0x1;
      ppppiVar6 = (int ****)NullUpdate_ret();
      iVar8 = DAT_0078a31c;
      for (; DAT_0078a31c = iVar8, ppppiVar5 != ppppiVar6; ppppiVar5 = (int ****)*ppppiVar5) {
        pppiVar1 = ppppiVar5[2];
        cVar2 = FUN_0043a2e0();
        if (cVar2 == '\0') {
          ppiVar9 = pppiVar1[DAT_00735ecc + 0x47];
        }
        else {
          pppiVar1[DAT_00735ecc + 0x47] = ppiVar9;
        }
        if (ppiVar9 == (int **)0x1) {
          pppiVar1[0x2a] = (int **)((int)pppiVar1[0x2a] + 1);
        }
        ppiVar9 = (int **)((int)ppiVar9 + 1);
        iVar8 = DAT_0078a31c;
      }
      DAT_00735ecc = DAT_00735ecc + 1;
    }
  }
  local_c = 0xffffffff;
  FUN_00421900();
  ExceptionList = local_14;
  return;
}


// ==== 0x4ad5d0 SortRacingCarByTime

/* [canon] runtime high (ghidra-canon+nfsug) docs/re/runtime.md */

bool SortRacingCarByTime(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  uVar2 = 0;
  if ((float)*(int *)(*(int *)(param_1 + 8) + 0x20 + DAT_00735ecc * 4) * 0.00025 == 0.0) {
    uVar1 = 2;
  }
  if ((float)*(int *)(*(int *)(param_2 + 8) + 0x20 + DAT_00735ecc * 4) * 0.00025 == 0.0) {
    uVar2 = 2;
  }
  if (*(int *)(*(int *)(param_2 + 8) + 0x4c + DAT_00735ecc * 4) <
      *(int *)(*(int *)(param_1 + 8) + 0x4c + DAT_00735ecc * 4)) {
    return uVar1 + 1 <= uVar2;
  }
  return uVar1 <= uVar2 + 1;
}


// ==== 0x4ad660 SortRacingCarByTable2

/* [canon] runtime low (ghidra-canon) docs/re/runtime.md */

bool SortRacingCarByTable2(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  uVar2 = 0;
  if (*(int *)(*(int *)(param_1 + 8) + 200 + DAT_00735ecc * 4) == 0) {
    uVar1 = 2;
  }
  if ((float)*(int *)(*(int *)(param_2 + 8) + 200 + DAT_00735ecc * 4) == 0.0) {
    uVar2 = 2;
  }
  if (*(int *)(*(int *)(param_1 + 8) + 0xf4 + DAT_00735ecc * 4) <
      *(int *)(*(int *)(param_2 + 8) + 0xf4 + DAT_00735ecc * 4)) {
    return uVar1 + 1 <= uVar2;
  }
  return uVar1 <= uVar2 + 1;
}


// ==== 0x4ad6d0 FUN_004ad6d0

undefined4 FUN_004ad6d0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_ESI;
  
  iVar1 = 0;
  iVar3 = DAT_00736168;
  if (0 < DAT_0073616c) {
    do {
      if (*(short *)(iVar3 + 0x6c) == unaff_ESI) {
        if (param_1 != 0) {
          uVar2 = FUN_004f42f0("REVERSE_TRACK_NAME_%d",(int)*(short *)(iVar3 + 0x6c));
          return uVar2;
        }
        uVar2 = FUN_004f42f0("TRACK_NAME_%d",(int)*(short *)(iVar3 + 0x6c));
        return uVar2;
      }
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0xfc;
    } while (iVar1 < DAT_0073616c);
  }
  return 0;
}


// ==== 0x4ad730 FUN_004ad730

void FUN_004ad730(void)

{
  undefined1 *in_EAX;
  
  *in_EAX = 0;
  in_EAX[0x11] = 0;
  in_EAX[0x33] = 0;
  in_EAX[0x22] = 0;
  in_EAX[0x66] = 0;
  in_EAX[0xcc] = 1;
  in_EAX[0xcd] = 1;
  in_EAX[0xdc] = 0;
  *(undefined4 *)(in_EAX + 0xd0) = 1;
  *(undefined4 *)(in_EAX + 0xd4) = 1;
  *(undefined4 *)(in_EAX + 0xd8) = 0x7d3;
  *(undefined4 *)(in_EAX + 0xe0) = 0;
  return;
}


// ==== 0x4ad780 Struct_InitHashPair

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

void Struct_InitHashPair(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = 0;
  in_EAX[1] = 0x18ed8cac;
  in_EAX[2] = 0x9c7511d8;
  in_EAX[3] = 0;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  in_EAX[6] = 0;
  in_EAX[7] = 0;
  return;
}


// ==== 0x4ad7b0 FUN_004ad7b0

void FUN_004ad7b0(int param_1)

{
  int iVar1;
  int unaff_ESI;
  undefined4 unaff_EDI;
  
  if (((unaff_ESI == 0) || (iVar1 = FUN_004f65d0(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) {
      return;
    }
    iVar1 = FUN_004ef050(unaff_EDI);
    if (iVar1 == 0) {
      return;
    }
  }
  if ((*(int *)(iVar1 + 0x18) == 1) && (*(int *)(iVar1 + 0x24) != param_1)) {
    *(int *)(iVar1 + 0x24) = param_1;
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
  }
  return;
}


// ==== 0x4ad810 MiniWorld::MiniWorld

/* [canon] car med (ghidra-canon+nfsug) docs/re/tuning.md */

int MiniWorld__MiniWorld(int param_1)

{
  int iVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685981;
  local_c = ExceptionList;
  iVar1 = param_1 + 0x48;
  ExceptionList = &local_c;
  *(int *)iVar1 = iVar1;
  *(int *)(param_1 + 0x4c) = iVar1;
  *(undefined4 *)(param_1 + 0x44) = 1;
  *(undefined1 *)(param_1 + 0x24) = 0;
  local_4 = 0;
  eh_vector_constructor_iterator((void *)(param_1 + 0x50),0x68,0x20,FUN_004ad8d0,NullUpdate_ret);
  local_4 = CONCAT31(local_4._1_3_,1);
  eh_vector_constructor_iterator
            ((void *)(param_1 + 0xd50),0x2e0,2,MiniWorldSegment__MiniWorldSegment,
             MiniWorldSegment___MiniWorldSegment);
  *(undefined4 *)(param_1 + 0x1318) = 0;
  *(undefined4 *)(param_1 + 0x131c) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4ad8a0 IList_FreeNodes_Member2C

/* [canon] car low (ghidra-canon+nfsug) docs/re/tuning.md */

void IList_FreeNodes_Member2C(void)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  int in_EAX;
  
  _Memory = *(int **)(in_EAX + 0x2c);
  while (_Memory != (int *)(in_EAX + 0x2c)) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = *(int **)(in_EAX + 0x2c);
  }
  return;
}


// ==== 0x4ad8d0 FUN_004ad8d0

undefined4 __fastcall FUN_004ad8d0(undefined4 param_1)

{
  return param_1;
}


// ==== 0x4ad8e0 MiniWorldSegment::MiniWorldSegment

/* [canon] car med (ghidra-canon+nfsug) docs/re/tuning.md */

void * __fastcall MiniWorldSegment__MiniWorldSegment(void *param_1)

{
  int iVar1;
  
  eh_vector_constructor_iterator(param_1,0x18,0x1e,ListRef_Init,ListRef_Release);
  iVar1 = (int)param_1 + 0x2d0;
  *(int *)iVar1 = iVar1;
  *(int *)((int)param_1 + 0x2d4) = iVar1;
  iVar1 = (int)param_1 + 0x2d8;
  *(int *)iVar1 = iVar1;
  *(int *)((int)param_1 + 0x2dc) = iVar1;
  return param_1;
}


// ==== 0x4ad920 MiniWorldSegment::_MiniWorldSegment

/* [canon] car med (ghidra-canon+nfsug) docs/re/tuning.md */

void __fastcall MiniWorldSegment___MiniWorldSegment(void *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = *(int **)((int)param_1 + 0x2d8);
  while (piVar1 != (int *)((int)param_1 + 0x2d8)) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(piVar1);
    piVar1 = *(int **)((int)param_1 + 0x2d8);
  }
  piVar1 = *(int **)((int)param_1 + 0x2d0);
  while (piVar1 != (int *)((int)param_1 + 0x2d0)) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(piVar1);
    piVar1 = *(int **)((int)param_1 + 0x2d0);
  }
  eh_vector_destructor_iterator(param_1,0x18,0x1e,ListRef_Release);
  return;
}


// ==== 0x4ad990 MiniWorld::_MiniWorld

/* [canon] car med (ghidra-canon+nfsug) docs/re/tuning.md */

void MiniWorld___MiniWorld(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  void *local_c;
  code *pcStack_8;
  uint local_4;
  
  pcStack_8 = FUN_00685981;
  local_c = ExceptionList;
  local_4 = 1;
  if ((*(int *)(param_1 + 0x1318) != 0) ||
     (ExceptionList = &local_c, *(int *)(param_1 + 0x131c) != 0)) {
    iVar1 = *(int *)(param_1 + 0x1310);
    piVar2 = *(int **)(param_1 + 0x1314);
    ExceptionList = &local_c;
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
  }
  *(undefined4 *)(param_1 + 0x131c) = 0;
  *(undefined4 *)(param_1 + 0x1318) = 0;
  *(undefined4 *)(param_1 + 0x1320) = 0;
  *(undefined4 *)(param_1 + 0x1324) = 0;
  eh_vector_destructor_iterator
            ((void *)(param_1 + 0xd50),0x2e0,2,MiniWorldSegment___MiniWorldSegment);
  local_4 = local_4 & 0xffffff00;
  eh_vector_destructor_iterator((void *)(param_1 + 0x50),0x68,0x20,NullUpdate_ret);
  piVar2 = *(int **)(param_1 + 0x48);
  while (piVar2 != (int *)(param_1 + 0x48)) {
    iVar1 = *piVar2;
    piVar3 = (int *)piVar2[1];
    *piVar3 = iVar1;
    *(int **)(iVar1 + 4) = piVar3;
    _free(piVar2);
    piVar2 = *(int **)(param_1 + 0x48);
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x4ada60 FUN_004ada60

void FUN_004ada60(undefined4 *param_1)

{
  undefined4 *puVar1;
  byte *pbVar2;
  char cVar3;
  byte bVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  uint *puVar8;
  undefined4 uVar9;
  char *pcVar10;
  uint uVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined *puVar14;
  uint *puVar15;
  int iVar16;
  byte *pbVar17;
  uint *puVar18;
  int *piVar19;
  undefined4 *puVar20;
  byte local_a0;
  byte local_9f [127];
  uint *local_20;
  int *local_1c;
  uint *local_18;
  int local_14;
  uint *local_10;
  undefined4 *local_c;
  int local_8;
  
  if (param_1[6] == 0) {
    FUN_005715d0(0xbe43edbb);
    FUN_005715d0(0x72923c81);
    uVar9 = DAT_006fb03c;
    param_1[3] = DAT_006fb03c;
    pcVar10 = (char *)(param_1 + 9);
    param_1[6] = 1;
    param_1[5] = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[4] = uVar9;
    *param_1 = 0x43480000;
    iVar13 = 0x1f;
    iVar16 = (int)"MiniWorld_DynamicLights" - (int)pcVar10;
    do {
      cVar3 = pcVar10[iVar16];
      iVar13 = iVar13 + -1;
      *pcVar10 = cVar3;
      if (cVar3 == '\0') break;
      pcVar10 = pcVar10 + 1;
    } while (iVar13 != 0);
    *(undefined1 *)((int)param_1 + 0x43) = 0;
    param_1[0x11] = 1;
    puVar20 = param_1 + 0x12;
    puVar12 = param_1 + 0x2f;
    local_8 = 4;
    do {
      puVar5 = (undefined4 *)param_1[0x13];
      puVar1 = puVar12 + -0x1b;
      *puVar5 = puVar1;
      param_1[0x13] = puVar1;
      *puVar1 = puVar20;
      puVar12[-0x1a] = puVar5;
      puVar5 = (undefined4 *)param_1[0x13];
      puVar1 = puVar12 + -1;
      *puVar5 = puVar1;
      param_1[0x13] = puVar1;
      *puVar1 = puVar20;
      *puVar12 = puVar5;
      puVar5 = (undefined4 *)param_1[0x13];
      puVar1 = puVar12 + 0x19;
      *puVar5 = puVar1;
      param_1[0x13] = puVar1;
      *puVar1 = puVar20;
      puVar12[0x1a] = puVar5;
      puVar5 = (undefined4 *)param_1[0x13];
      puVar1 = puVar12 + 0x33;
      *puVar5 = puVar1;
      param_1[0x13] = puVar1;
      *puVar1 = puVar20;
      puVar12[0x34] = puVar5;
      puVar5 = (undefined4 *)param_1[0x13];
      puVar1 = puVar12 + 0x4d;
      *puVar5 = puVar1;
      param_1[0x13] = puVar1;
      *puVar1 = puVar20;
      puVar12[0x4e] = puVar5;
      puVar5 = (undefined4 *)param_1[0x13];
      puVar1 = puVar12 + 0x67;
      *puVar5 = puVar1;
      param_1[0x13] = puVar1;
      *puVar1 = puVar20;
      puVar12[0x68] = puVar5;
      puVar5 = (undefined4 *)param_1[0x13];
      puVar1 = puVar12 + 0x81;
      *puVar5 = puVar1;
      param_1[0x13] = puVar1;
      *puVar1 = puVar20;
      puVar12[0x82] = puVar5;
      puVar5 = (undefined4 *)param_1[0x13];
      puVar1 = puVar12 + 0x9b;
      *puVar5 = puVar1;
      param_1[0x13] = puVar1;
      *puVar1 = puVar20;
      puVar12[0x9c] = puVar5;
      puVar12 = puVar12 + 0xd0;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
    puVar20 = param_1 + 7;
    if (puVar20 != (undefined4 *)0x0) {
      *DAT_00743c14 = puVar20;
      puVar12 = puVar20;
      param_1[8] = DAT_00743c14;
      DAT_00743c14 = puVar12;
      *puVar20 = &DAT_00743c10;
    }
    local_c = param_1 + 0x354;
    local_14 = 2;
    do {
      puVar20 = local_c;
      for (iVar13 = 0xb4; iVar13 != 0; iVar13 = iVar13 + -1) {
        *puVar20 = 0;
        puVar20 = puVar20 + 1;
      }
      local_8 = 0;
      do {
        if (local_8 == 0) {
          FUN_00565da0("TRFE_ROAD02");
        }
        else {
          FUN_00565da0("TRFE_ROAD02_%02d",local_8);
        }
        pbVar17 = &local_a0;
        local_18 = (uint *)0xffffffff;
        local_18 = (uint *)0xffffffff;
        bVar4 = local_a0;
        while (bVar4 != 0) {
          local_18 = (uint *)((int)local_18 * 0x21 + (uint)bVar4);
          pbVar2 = pbVar17 + 1;
          pbVar17 = pbVar17 + 1;
          bVar4 = *pbVar2;
        }
        puVar14 = &DAT_006c63f8;
        uVar11 = 0x5f;
        puVar18 = local_18;
        do {
          puVar18 = (uint *)((int)puVar18 * 0x21 + uVar11);
          pbVar17 = puVar14 + 1;
          uVar11 = (uint)*pbVar17;
          puVar14 = puVar14 + 1;
        } while (*pbVar17 != 0);
        puVar14 = &DAT_006c63f4;
        uVar11 = 0x5f;
        local_20 = local_18;
        do {
          local_20 = (uint *)((int)local_20 * 0x21 + uVar11);
          pbVar17 = puVar14 + 1;
          uVar11 = (uint)*pbVar17;
          puVar14 = puVar14 + 1;
        } while (*pbVar17 != 0);
        puVar14 = &DAT_006c63f0;
        uVar11 = 0x5f;
        local_10 = local_18;
        do {
          local_10 = (uint *)((int)local_10 * 0x21 + uVar11);
          pbVar17 = puVar14 + 1;
          uVar11 = (uint)*pbVar17;
          puVar14 = puVar14 + 1;
        } while (*pbVar17 != 0);
        piVar19 = local_c + local_8 * 0x12;
        piVar19[2] = (int)puVar18;
        piVar19[4] = 0;
        piVar19[5] = 0;
        if (puVar18 != (uint *)0x0) {
          *DAT_00743c74 = (int)piVar19;
          piVar6 = piVar19;
          piVar19[1] = (int)DAT_00743c74;
          DAT_00743c74 = piVar6;
          *piVar19 = (int)&DAT_00743c70;
        }
        local_1c = piVar19;
        if (((piVar19[2] != 0) && (iVar13 = Solid_FindInAllLists(), piVar19[2] != 0)) &&
           (iVar13 != piVar19[3])) {
          iVar16 = *piVar19;
          piVar6 = (int *)piVar19[1];
          *piVar6 = iVar16;
          *(int **)(iVar16 + 4) = piVar6;
          if (iVar13 == 0) {
            *DAT_00743c74 = (int)piVar19;
            piVar6 = piVar19;
            piVar19[1] = (int)DAT_00743c74;
            DAT_00743c74 = piVar6;
            *piVar19 = (int)&DAT_00743c70;
          }
          else {
            puVar20 = *(undefined4 **)(iVar13 + 0x8c);
            *puVar20 = piVar19;
            *(int **)(iVar13 + 0x8c) = piVar19;
            piVar19[1] = (int)puVar20;
            *piVar19 = iVar13 + 0x88;
          }
          piVar19[3] = iVar13;
        }
        piVar6 = piVar19 + 6;
        piVar19[8] = (int)local_20;
        piVar19[10] = 0;
        piVar19[0xb] = 0;
        if (local_20 != (uint *)0x0) {
          *DAT_00743c74 = (int)piVar6;
          piVar7 = piVar6;
          piVar19[7] = (int)DAT_00743c74;
          DAT_00743c74 = piVar7;
          *piVar6 = (int)&DAT_00743c70;
        }
        if (((piVar19[8] != 0) && (iVar13 = Solid_FindInAllLists(), piVar19[8] != 0)) &&
           (iVar13 != piVar19[9])) {
          iVar16 = *piVar6;
          piVar7 = (int *)piVar19[7];
          *piVar7 = iVar16;
          *(int **)(iVar16 + 4) = piVar7;
          if (iVar13 == 0) {
            *DAT_00743c74 = (int)piVar6;
            piVar7 = piVar6;
            piVar19[7] = (int)DAT_00743c74;
            DAT_00743c74 = piVar7;
            *piVar6 = (int)&DAT_00743c70;
          }
          else {
            puVar20 = *(undefined4 **)(iVar13 + 0x8c);
            *puVar20 = piVar6;
            *(int **)(iVar13 + 0x8c) = piVar6;
            piVar19[7] = (int)puVar20;
            *piVar6 = iVar13 + 0x88;
          }
          piVar19[9] = iVar13;
        }
        piVar6 = piVar19 + 0xc;
        piVar19[0xe] = (int)local_10;
        piVar19[0x10] = 0;
        piVar19[0x11] = 0;
        if (local_10 != (uint *)0x0) {
          *DAT_00743c74 = (int)piVar6;
          piVar7 = piVar6;
          piVar19[0xd] = (int)DAT_00743c74;
          DAT_00743c74 = piVar7;
          *piVar6 = (int)&DAT_00743c70;
        }
        if (((piVar19[0xe] != 0) && (iVar13 = Solid_FindInAllLists(), piVar19[0xe] != 0)) &&
           (iVar13 != piVar19[0xf])) {
          iVar16 = *piVar6;
          piVar7 = (int *)piVar19[0xd];
          *piVar7 = iVar16;
          *(int **)(iVar16 + 4) = piVar7;
          if (iVar13 == 0) {
            *DAT_00743c74 = (int)piVar6;
            piVar7 = piVar6;
            piVar19[0xd] = (int)DAT_00743c74;
            DAT_00743c74 = piVar7;
            *piVar6 = (int)&DAT_00743c70;
          }
          else {
            puVar20 = *(undefined4 **)(iVar13 + 0x8c);
            *puVar20 = piVar6;
            *(int **)(iVar13 + 0x8c) = piVar6;
            piVar19[0xd] = (int)puVar20;
            *piVar6 = iVar13 + 0x88;
          }
          piVar19[0xf] = iVar13;
        }
        if (piVar19[3] != 0) {
          puVar15 = (uint *)0x0;
          pcVar10 = "_FLARE";
          uVar11 = 0x5f;
          puVar18 = local_18;
          do {
            puVar18 = (uint *)((int)puVar18 * 0x21 + uVar11);
            pbVar17 = (byte *)(pcVar10 + 1);
            uVar11 = (uint)*pbVar17;
            pcVar10 = pcVar10 + 1;
          } while (*pbVar17 != 0);
          while (iVar13 = local_1c[3], iVar13 != 0) {
            puVar8 = *(uint **)(iVar13 + 0x80);
            if ((puVar8 == (uint *)0x0) || (*(char *)(iVar13 + 0x1b) == 0)) {
LAB_004adea0:
              puVar8 = (uint *)0x0;
            }
            else if (puVar15 != (uint *)0x0) {
              if ((puVar15 < puVar8) ||
                 (puVar8 + (*(char *)(iVar13 + 0x1b) * 5 + -5) * 4 <= puVar15)) goto LAB_004adea0;
              puVar8 = puVar15 + 0x14;
            }
            puVar15 = puVar8;
            local_10 = puVar15;
            if (puVar15 == (uint *)0x0) break;
            if ((uint *)*puVar15 == puVar18) {
              puVar12 = _malloc(0x50);
              puVar12[2] = puVar18;
              *(undefined1 *)(puVar12 + 3) = 1;
              *(undefined1 *)((int)puVar12 + 0xd) = 9;
              *(undefined2 *)((int)puVar12 + 0xe) = 0;
              puVar12[4] = puVar15[0x10];
              puVar12[5] = puVar15[0x11];
              puVar12[6] = puVar15[0x12];
              puVar12[7] = -(float)puVar15[0x12];
              puVar12[8] = puVar15[0xc];
              puVar12[9] = puVar15[0xd];
              puVar12[10] = puVar15[0xe];
              *(undefined2 *)(puVar12 + 0xb) = 0;
              *(undefined1 *)((int)puVar12 + 0x2e) = 0;
              puVar20 = (undefined4 *)local_c[0xb5];
              *puVar20 = puVar12;
              local_c[0xb5] = puVar12;
              puVar12[1] = puVar20;
              *puVar12 = local_c + 0xb4;
              puVar12 = _malloc(0x68);
              puVar12[2] = puVar18;
              *(undefined1 *)(puVar12 + 3) = 2;
              *(undefined1 *)((int)puVar12 + 0xd) = 2;
              *(undefined1 *)((int)puVar12 + 0xe) = 0;
              *(undefined1 *)((int)puVar12 + 0xf) = 1;
              puVar12[4] = 0;
              puVar12[5] = 0xff00ff;
              puVar12[6] = puVar15[0x10];
              puVar12[7] = puVar15[0x11];
              puVar12[8] = puVar15[0x12];
              puVar12[9] = 0;
              puVar12[10] = puVar15[0xc];
              puVar12[0xb] = puVar15[0xd];
              puVar12[0xc] = puVar15[0xe];
              puVar12[0xd] = 0;
              puVar12[0xe] = 0;
              puVar12[0xf] = 0;
              puVar12[0x10] = 0;
              *(undefined2 *)(puVar12 + 0x11) = 0;
              puVar20 = (undefined4 *)local_c[0xb7];
              *puVar20 = puVar12;
              local_c[0xb7] = puVar12;
              puVar12[1] = puVar20;
              *puVar12 = local_c + 0xb6;
            }
          }
        }
        local_8 = local_8 + 1;
      } while (local_8 < 10);
      local_c = local_c + 0xb8;
      local_14 = local_14 + -1;
    } while (local_14 != 0);
    pcVar10 = "MARKER_GOLDRING";
    iVar13 = -1;
    uVar11 = 0x4d;
    do {
      iVar13 = iVar13 * 0x21 + uVar11;
      pbVar17 = (byte *)(pcVar10 + 1);
      uVar11 = (uint)*pbVar17;
      pcVar10 = pcVar10 + 1;
    } while (*pbVar17 != 0);
    piVar19 = param_1 + 0x4c4;
    param_1[0x4c6] = iVar13;
    param_1[0x4c8] = 0;
    param_1[0x4c9] = 0;
    if (iVar13 != 0) {
      *DAT_00743c74 = (int)piVar19;
      piVar6 = piVar19;
      param_1[0x4c5] = DAT_00743c74;
      DAT_00743c74 = piVar6;
      *piVar19 = (int)&DAT_00743c70;
    }
    if (((param_1[0x4c6] != 0) && (iVar13 = Solid_FindInAllLists(), param_1[0x4c6] != 0)) &&
       (iVar13 != param_1[0x4c7])) {
      iVar16 = *piVar19;
      piVar6 = (int *)param_1[0x4c5];
      *piVar6 = iVar16;
      *(int **)(iVar16 + 4) = piVar6;
      if (iVar13 != 0) {
        puVar20 = *(undefined4 **)(iVar13 + 0x8c);
        *puVar20 = piVar19;
        *(int **)(iVar13 + 0x8c) = piVar19;
        param_1[0x4c5] = puVar20;
        *piVar19 = iVar13 + 0x88;
        param_1[0x4c7] = iVar13;
        return;
      }
      *DAT_00743c74 = (int)piVar19;
      piVar6 = piVar19;
      param_1[0x4c5] = DAT_00743c74;
      DAT_00743c74 = piVar6;
      *piVar19 = (int)&DAT_00743c70;
      param_1[0x4c7] = 0;
    }
  }
  return;
}


// ==== 0x4ae070 MiniWorld::Close

/* [canon] car high (ghidra-canon+nfsug) docs/re/tuning.md */

void MiniWorld__Close(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  iVar4 = param_1;
  if (*(int *)(param_1 + 0x18) != 0) {
    if ((int *)(param_1 + 0x1c) != (int *)0x0) {
      iVar6 = *(int *)(param_1 + 0x1c);
      piVar5 = *(int **)(param_1 + 0x20);
      *piVar5 = iVar6;
      *(int **)(iVar6 + 4) = piVar5;
    }
    piVar5 = (int *)(param_1 + 0x50);
    iVar6 = 0x20;
    do {
      iVar7 = *piVar5;
      piVar1 = (int *)piVar5[1];
      piVar5 = piVar5 + 0x1a;
      iVar6 = iVar6 + -1;
      *piVar1 = iVar7;
      *(int **)(iVar7 + 4) = piVar1;
    } while (iVar6 != 0);
    iVar6 = param_1 + 0xd50;
    param_1 = 2;
    do {
      piVar5 = (int *)(iVar6 + 0x24);
      iVar7 = 10;
      do {
        if ((piVar5[-7] != 0) || (piVar5[-6] != 0)) {
          iVar2 = piVar5[-9];
          piVar1 = (int *)piVar5[-8];
          *piVar1 = iVar2;
          *(int **)(iVar2 + 4) = piVar1;
        }
        piVar5[-6] = 0;
        piVar5[-7] = 0;
        piVar5[-5] = 0;
        piVar5[-4] = 0;
        if ((piVar5[-1] != 0) || (*piVar5 != 0)) {
          iVar2 = piVar5[-3];
          piVar1 = (int *)piVar5[-2];
          *piVar1 = iVar2;
          *(int **)(iVar2 + 4) = piVar1;
        }
        *piVar5 = 0;
        piVar5[-1] = 0;
        piVar5[1] = 0;
        piVar5[2] = 0;
        if ((piVar5[5] != 0) || (piVar5[6] != 0)) {
          iVar2 = piVar5[3];
          piVar1 = (int *)piVar5[4];
          *piVar1 = iVar2;
          *(int **)(iVar2 + 4) = piVar1;
        }
        piVar5[6] = 0;
        piVar5[5] = 0;
        piVar5[7] = 0;
        piVar5[8] = 0;
        piVar5 = piVar5 + 0x12;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      piVar5 = (int *)(iVar6 + 0x2d0);
      piVar1 = *(int **)(iVar6 + 0x2d0);
      while (piVar1 != piVar5) {
        piVar1 = (int *)*piVar5;
        iVar7 = *piVar1;
        piVar3 = (int *)piVar1[1];
        *piVar3 = iVar7;
        *(int **)(iVar7 + 4) = piVar3;
        _free(piVar1);
        piVar1 = (int *)*piVar5;
      }
      piVar5 = (int *)(iVar6 + 0x2d8);
      piVar1 = *(int **)(iVar6 + 0x2d8);
      while (piVar1 != piVar5) {
        piVar1 = (int *)*piVar5;
        iVar7 = *piVar1;
        piVar3 = (int *)piVar1[1];
        *piVar3 = iVar7;
        *(int **)(iVar7 + 4) = piVar3;
        _free(piVar1);
        piVar1 = (int *)*piVar5;
      }
      iVar6 = iVar6 + 0x2e0;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
    if ((*(int *)(iVar4 + 0x1318) != 0) || (*(int *)(iVar4 + 0x131c) != 0)) {
      iVar6 = *(int *)(iVar4 + 0x1310);
      piVar5 = *(int **)(iVar4 + 0x1314);
      *piVar5 = iVar6;
      *(int **)(iVar6 + 4) = piVar5;
    }
    *(undefined4 *)(iVar4 + 0x131c) = 0;
    *(undefined4 *)(iVar4 + 0x1318) = 0;
    *(undefined4 *)(iVar4 + 0x1320) = 0;
    *(undefined4 *)(iVar4 + 0x1324) = 0;
    *(undefined4 *)(iVar4 + 0x18) = 0;
  }
  return;
}


// ==== 0x4ae1f0 FUN_004ae1f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ae1f0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *in_EAX;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  undefined1 *puVar9;
  float fVar10;
  float10 fVar11;
  float10 fVar12;
  float local_c;
  float local_8;
  
  if (((in_EAX[6] != 0.0) && (DAT_006fb038 != 0)) && (in_EAX[5] != DAT_007364dc)) {
    in_EAX[5] = DAT_007364dc;
    fVar3 = in_EAX[3];
    if (DAT_00735e8c == 0) {
      if (in_EAX[3] <= in_EAX[4]) {
        if ((in_EAX[3] < in_EAX[4]) &&
           (fVar4 = DAT_0073ad38 * _DAT_006fb040 + in_EAX[3], in_EAX[3] = fVar4, in_EAX[4] < fVar4))
        {
          in_EAX[3] = in_EAX[4];
        }
      }
      else {
        fVar4 = in_EAX[3] - DAT_0073ad38 * _DAT_006fb040;
        in_EAX[3] = fVar4;
        if (fVar4 < in_EAX[4]) {
          in_EAX[3] = in_EAX[4];
        }
      }
      _ftol_nocw();
      fVar11 = (float10)FUN_00564b10();
      _ftol_nocw();
      fVar12 = (float10)FUN_00564b10();
      fVar11 = fVar12 * (float10)3.0 + (float10)(float)(fVar11 * (float10)2.0);
      if (fVar3 < 20.0) {
        if (5.0 <= fVar3) {
          fVar11 = (((float10)fVar3 - (float10)5.0) / ((float10)20.0 - (float10)5.0)) * fVar11;
        }
        else {
          fVar11 = (float10)0.0;
        }
      }
      fVar11 = fVar11 + (float10)fVar3;
    }
    else {
      fVar11 = (float10)DAT_006fb03c;
    }
    fVar11 = fVar11 * (float10)1000.0 * (float10)0.00027777778;
    fVar12 = (float10)DAT_0073ad38 * fVar11;
    in_EAX[2] = (float)fVar12;
    fVar12 = fVar12 + (float10)in_EAX[1];
    in_EAX[1] = (float)fVar12;
    if ((float10)*in_EAX < fVar12) {
      do {
        in_EAX[1] = in_EAX[1] - *in_EAX;
      } while (*in_EAX < in_EAX[1]);
    }
    _DAT_00748110 = (float)fVar11;
    _DAT_00748114 = 0;
    _DAT_00748118 = 0;
    iVar6 = MiniWorld__SetupRenderParameters(&DAT_007404c0);
    fVar4 = DAT_00735e90;
    fVar3 = DAT_006fb044;
    if (iVar6 != 0) {
      fVar1 = in_EAX[0x4cd];
      local_c = in_EAX[0x4cb];
      fVar10 = (float)(((DAT_00735ea8 | 0xffffff00) << 8 | DAT_00735ea4) << 8 | DAT_00735ea0);
      local_8 = in_EAX[0x4ca];
      iVar6 = 0;
      do {
        if (local_c == 0.0) break;
        pfVar8 = (float *)in_EAX[(int)local_8 * 0xb8 + 0x40a];
        if (pfVar8 != (float *)0x0) {
          pfVar7 = in_EAX + iVar6 * 0x1a + 0x17;
          do {
            if ((0x1f < iVar6) || (pfVar8 == in_EAX + (int)local_8 * 0xb8 + 0x40a)) break;
            pfVar7[-1] = pfVar8[2];
            *(undefined1 *)((int)pfVar7 + 2) = 0;
            pfVar7[1] = 0.0;
            fVar5 = DAT_006fb054;
            *(undefined1 *)pfVar7 = 2;
            *(undefined1 *)((int)pfVar7 + 1) = 2;
            *(undefined1 *)((int)pfVar7 + 3) = 1;
            pfVar7[2] = fVar10;
            iVar6 = iVar6 + 1;
            pfVar7[3] = pfVar8[6] - fVar1;
            pfVar7[4] = fVar4 + pfVar8[7];
            fVar2 = pfVar8[8];
            pfVar7[6] = fVar5;
            pfVar7[5] = fVar3 + fVar2;
            pfVar7[7] = pfVar8[10];
            pfVar7[8] = pfVar8[0xb];
            pfVar7[9] = pfVar8[0xc];
            pfVar7[10] = DAT_006fb058;
            pfVar7[0xb] = DAT_00735e94;
            pfVar7[0xc] = DAT_00735e98;
            pfVar7[0xd] = DAT_00735e9c;
            *(undefined2 *)(pfVar7 + 0xe) = 0;
            pfVar8 = (float *)*pfVar8;
            pfVar7 = pfVar7 + 0x1a;
          } while (pfVar8 != (float *)0x0);
        }
        local_8 = (float)((int)local_8 + 1U & 0x80000001);
        if ((int)local_8 < 0) {
          local_8 = (float)(((int)local_8 - 1U | 0xfffffffe) + 1);
        }
        fVar1 = fVar1 + 100.0;
        local_c = (float)((int)local_c + -1);
      } while (iVar6 < 0x20);
      if (iVar6 < 0x20) {
        puVar9 = (undefined1 *)(iVar6 * 0x68 + 0x5f + (int)in_EAX);
        iVar6 = 0x20 - iVar6;
        do {
          *puVar9 = 0;
          puVar9 = puVar9 + 0x68;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
    }
  }
  return;
}


// ==== 0x4ae530 MiniWorld::SetupRenderParameters

/* [canon] car high (ghidra-canon+nfsug) docs/re/tuning.md */

undefined4 MiniWorld__SetupRenderParameters(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int unaff_ESI;
  int iVar6;
  
  uVar4 = 0;
  *(undefined4 *)(unaff_ESI + 0x1328) = 0;
  *(undefined4 *)(unaff_ESI + 0x132c) = 0;
  *(undefined4 *)(unaff_ESI + 0x1330) = 0;
  *(undefined4 *)(unaff_ESI + 0x1334) = 0;
  *(undefined4 *)(unaff_ESI + 0x1338) = 0;
  if ((*(int *)(unaff_ESI + 0x18) == 0) || (DAT_006fb038 == 0)) {
    return 0;
  }
  iVar6 = *(int *)(param_1 + 4);
  if ((iVar6 < 4) || (5 < iVar6)) {
    if ((iVar6 < 10) || (0xf < iVar6)) {
      if (iVar6 < 1) {
        return 0;
      }
      if (3 < iVar6) {
        return 0;
      }
      uVar5 = 0;
      iVar6 = DAT_006fb048;
    }
    else {
      uVar4 = 2;
      uVar5 = 1;
      iVar6 = DAT_006fb050;
    }
  }
  else {
    uVar4 = 1;
    uVar5 = 2;
    iVar6 = DAT_006fb04c;
  }
  iVar1 = _ftol_nocw();
  uVar2 = iVar1 - iVar6 & 0x80000001;
  if ((int)uVar2 < 0) {
    uVar3 = uVar2 - 1 | 0xfffffffe;
    uVar2 = uVar3 + 1;
    if ((int)uVar2 < 0) {
      uVar2 = uVar3 + 3 + (-uVar2 - 1 & 0xfffffffe);
    }
  }
  uVar2 = uVar2 & 0x80000001;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffffe) + 1;
  }
  *(undefined4 *)(unaff_ESI + 0x1338) = uVar5;
  *(uint *)(unaff_ESI + 0x1328) = uVar2;
  *(undefined4 *)(unaff_ESI + 0x1330) = uVar4;
  *(int *)(unaff_ESI + 0x132c) = iVar6 * 2 + 1;
  *(float *)(unaff_ESI + 0x1334) =
       (*(float *)(unaff_ESI + 4) - (float)iVar1 * 100.0) - (float)iVar6 * 100.0;
  return 1;
}


// ==== 0x4ae650 DrawEmitters

/* [canon] render I (C) docs/re/blur.md */

void DrawEmitters(int param_1,undefined4 param_2)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  
  iVar6 = MiniWorld__SetupRenderParameters(param_2);
  uVar5 = DAT_00735e90;
  uVar4 = DAT_006fb044;
  if (iVar6 != 0) {
    uVar9 = *(uint *)(param_1 + 0x1328);
    iVar6 = *(int *)(param_1 + 0x1330);
    fVar1 = *(float *)(param_1 + 0x1334);
    uVar2 = DAT_007355b4;
    uVar3 = DAT_007355b4;
    for (iVar7 = *(int *)(param_1 + 0x132c); DAT_007355b4 = uVar3, iVar7 != 0; iVar7 = iVar7 + -1) {
      DAT_007355b4 = uVar2 + 0x40;
      if (DAT_007355b4 < DAT_007355b8) {
        uVar8 = DAT_007355b4;
        if (uVar2 != 0) {
          bMatrixCopy_b();
          *(float *)(uVar2 + 0x30) = -fVar1;
          *(undefined4 *)(uVar2 + 0x34) = uVar5;
          *(undefined4 *)(uVar2 + 0x38) = uVar4;
          iVar10 = 0;
          iVar11 = uVar9 * 0x2e0 + 0xd50 + param_1 + iVar6 * 0x18;
          do {
            FUN_0040c910(param_2,iVar11,uVar2,0,0);
            iVar10 = iVar10 + 1;
            iVar11 = iVar11 + 0x48;
            uVar8 = DAT_007355b4;
          } while (iVar10 < 10);
        }
      }
      else {
        DAT_007355c8 = DAT_007355c8 + 0x40;
        DAT_007355c4 = 1;
        uVar8 = uVar2;
        DAT_007355b4 = uVar3;
      }
      uVar9 = uVar9 + 1 & 0x80000001;
      if ((int)uVar9 < 0) {
        uVar9 = (uVar9 - 1 | 0xfffffffe) + 1;
      }
      fVar1 = fVar1 + 100.0;
      uVar2 = uVar8;
      uVar3 = DAT_007355b4;
    }
  }
  return;
}


// ==== 0x4ae7d0 Emitters_DrawFlares

/* [canon] render low (hopper+ghidra) docs/re/render.md */

void Emitters_DrawFlares(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  
  iVar8 = MiniWorld__SetupRenderParameters(param_2);
  uVar7 = DAT_00735e90;
  uVar6 = DAT_006fb044;
  if (iVar8 != 0) {
    uVar9 = *(uint *)(param_1 + 0x1328);
    fVar2 = *(float *)(param_1 + 0x1334);
    uVar3 = *(undefined4 *)(param_1 + 0x1338);
    uVar5 = DAT_007355b4;
    for (iVar8 = *(int *)(param_1 + 0x132c); DAT_007355b4 = uVar5, iVar8 != 0; iVar8 = iVar8 + -1) {
      DAT_007355b4 = uVar5 + 0x40;
      if (DAT_007355b8 <= DAT_007355b4) {
        DAT_007355b4 = uVar5;
        DAT_007355c4 = 1;
        DAT_007355c8 = DAT_007355c8 + 0x40;
        return;
      }
      if (uVar5 == 0) {
        return;
      }
      bMatrixCopy_b();
      *(float *)(uVar5 + 0x30) = -fVar2;
      puVar1 = (undefined4 *)(uVar9 * 0x2e0 + param_1 + 0x1020);
      *(undefined4 *)(uVar5 + 0x34) = uVar7;
      *(undefined4 *)(uVar5 + 0x38) = uVar6;
      for (puVar4 = (undefined4 *)*puVar1; (puVar4 != (undefined4 *)0x0 && (puVar4 != puVar1));
          puVar4 = (undefined4 *)*puVar4) {
        FUN_005447c0(param_2,puVar4,0x3f800000,0,uVar3,0);
      }
      uVar9 = uVar9 + 1 & 0x80000001;
      if ((int)uVar9 < 0) {
        uVar9 = (uVar9 - 1 | 0xfffffffe) + 1;
      }
      fVar2 = fVar2 + 100.0;
      uVar5 = DAT_007355b4;
    }
  }
  return;
}


// ==== 0x4ae910 FUN_004ae910

void FUN_004ae910(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_004aeb60(param_1,param_2,param_3);
  return;
}


// ==== 0x4ae930 CarOrbiter::CarOrbiter

/* [canon] car high (ghidra-canon+nfsug) docs/re/tuning.md */

void CarOrbiter__CarOrbiter(void)

{
  undefined4 uVar1;
  undefined4 in_EAX;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *unaff_EDI;
  
  *unaff_EDI = 0;
  unaff_EDI[2] = in_EAX;
  unaff_EDI[3] = 4;
  unaff_EDI[1] = 0;
  puVar2 = &DAT_006fb05c;
  do {
    if (unaff_EDI[2] == -2) {
      uVar1 = *puVar2;
      iVar3 = 0;
      do {
        InputEvents__AddSource(uVar1,FUN_004ae910);
        iVar3 = iVar3 + 1;
      } while (iVar3 < 2);
    }
    puVar2 = puVar2 + 1;
  } while ((int)puVar2 < 0x6fb088);
  return;
}


// ==== 0x4ae990 FUN_004ae990

void FUN_004ae990(void)

{
  undefined4 in_EAX;
  
  FUN_004aea00(in_EAX);
  return;
}


// ==== 0x4ae9a0 FUN_004ae9a0

void FUN_004ae9a0(void)

{
  undefined4 uVar1;
  undefined4 in_EAX;
  undefined4 *puVar2;
  int iVar3;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + 8) = in_EAX;
  *(undefined4 *)(unaff_EDI + 4) = 0;
  puVar2 = &DAT_006fb05c;
  do {
    if (*(int *)(unaff_EDI + 8) == -2) {
      uVar1 = *puVar2;
      iVar3 = 0;
      do {
        InputEvents__AddSource(uVar1,FUN_004ae910);
        iVar3 = iVar3 + 1;
      } while (iVar3 < 2);
    }
    else {
      InputEvents__AddSource(*puVar2,FUN_004ae910);
    }
    puVar2 = puVar2 + 1;
  } while ((int)puVar2 < 0x6fb088);
  return;
}


// ==== 0x4aea00 FUN_004aea00

void FUN_004aea00(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_006fb05c;
  do {
    if (*(int *)(param_1 + 8) == -2) {
      uVar1 = *puVar2;
      iVar3 = 0;
      do {
        FUN_005740b0(uVar1);
        iVar3 = iVar3 + 1;
      } while (iVar3 < 2);
    }
    else {
      FUN_005740b0(*puVar2);
    }
    puVar2 = puVar2 + 1;
  } while ((int)puVar2 < 0x6fb088);
  return;
}


// ==== 0x4aea50 FUN_004aea50

void __fastcall FUN_004aea50(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_006fb0b0;
  do {
    if (*piVar1 == param_2) {
      iVar2 = iVar2 * 0x30;
      if (iVar2 != -0x6fb0b0) {
        SelectCarCameraMover__SetMagazineOrientation
                  (*(undefined4 *)(iVar2 + 0x6fb0b4),*(undefined4 *)(iVar2 + 0x6fb0b8),
                   *(undefined4 *)(iVar2 + 0x6fb0bc),*(undefined4 *)(iVar2 + 0x6fb0c0),
                   *(undefined4 *)(iVar2 + 0x6fb0c4),*(undefined4 *)(iVar2 + 0x6fb0c8),
                   *(undefined4 *)(iVar2 + 0x6fb0cc),*(undefined4 *)(iVar2 + 0x6fb0d0),
                   *(undefined4 *)(iVar2 + 0x6fb0d4),*(undefined4 *)(iVar2 + 0x6fb0d8),
                   *(undefined4 *)(iVar2 + 0x6fb0dc));
      }
      return;
    }
    piVar1 = piVar1 + 0xc;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x6fb6e0);
  return;
}


// ==== 0x4aeac0 FUN_004aeac0

undefined4 FUN_004aeac0(void)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined **ppuVar7;
  
  if (*(int *)(DAT_0073578c + 8) != 0) {
    for (iVar1 = *(int *)(*(int *)(DAT_0073578c + 8) + 0xe4); iVar1 != 0;
        iVar1 = *(int *)(iVar1 + 4)) {
      ppuVar7 = &PTR_s_MU_Garage_fng_00707020;
      do {
        pbVar5 = *ppuVar7;
        pbVar6 = *(byte **)(iVar1 + 0xc);
        do {
          bVar4 = *pbVar6;
          if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
            bVar4 = bVar4 & 0x5f;
          }
          bVar2 = *pbVar5;
          pbVar6 = pbVar6 + 1;
          if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
            bVar2 = bVar2 & 0x5f;
          }
          pbVar5 = pbVar5 + 1;
        } while (((bVar4 != 0) && (bVar2 != 0)) && (bVar4 == bVar2));
        if ((bVar4 == bVar2) &&
           ((iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 == 0 ||
            (*(int *)(iVar3 + 0x18) == 0)))) {
          return 1;
        }
        ppuVar7 = ppuVar7 + 1;
      } while ((int)ppuVar7 < 0x7070b0);
    }
  }
  return 0;
}


// ==== 0x4aeb60 FUN_004aeb60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004aeb60(undefined4 param_1,undefined4 param_2,byte param_3)

{
  char cVar1;
  int unaff_ESI;
  
  if (((*(int *)(unaff_ESI + 4) != 0) && (*(int *)(unaff_ESI + 0xc) == 4)) &&
     (cVar1 = FUN_004aeac0(unaff_ESI), cVar1 != '\0')) {
    switch(param_2) {
    case 0x3a:
      if (DAT_0078eb38 != 0) {
        CameraMover_SetTransitionParamB((float)(int)-(uint)param_3 * _K_BLUR_MIN_T);
        DAT_006fb02c = 0;
        DAT_00735e84 = 0;
        DAT_0074810c = DAT_0073ad3c;
      }
      DAT_0078eb38 = DAT_0078eb38 + 1;
      return;
    case 0x3b:
      if (DAT_0078eb34 != 0) {
        CameraMover_SetTransitionParamB((float)param_3 * _K_BLUR_MIN_T);
        DAT_006fb02c = 0;
        DAT_00735e84 = 0;
        DAT_0074810c = DAT_0073ad3c;
      }
      DAT_0078eb34 = DAT_0078eb34 + 1;
      return;
    case 0x3c:
      if (DAT_0078eb2c != 0) {
        CameraMover_SetTransitionParamA((float)param_3 * _K_BLUR_MIN_T);
        DAT_006fb02c = 0;
        DAT_00735e84 = 0;
        DAT_0074810c = DAT_0073ad3c;
      }
      DAT_0078eb2c = DAT_0078eb2c + 1;
      return;
    case 0x3d:
      if (DAT_0078eb28 != 0) {
        CameraMover_SetTransitionParamA((float)(int)-(uint)param_3 * _K_BLUR_MIN_T);
        DAT_006fb02c = 0;
        DAT_00735e84 = 0;
        DAT_0074810c = DAT_0073ad3c;
      }
      DAT_0078eb28 = DAT_0078eb28 + 1;
      return;
    case 0x3e:
      if (DAT_0078eb20 != 0) {
        SelectCarCameraMover__SetZoomSpeed((float)(int)-(uint)param_3 * _K_BLUR_MIN_T);
        DAT_0074810c = DAT_0073ad3c;
        DAT_006fb02c = 0;
        DAT_00735e84 = 0;
        CameraMover_SetTransitionParamB(0);
        CameraMover_SetTransitionParamA(0);
      }
      DAT_0078eb20 = DAT_0078eb20 + 1;
      return;
    case 0x3f:
      if (DAT_0078eb1c != 0) {
        SelectCarCameraMover__SetZoomSpeed((float)param_3 * _K_BLUR_MIN_T);
        DAT_0074810c = DAT_0073ad3c;
        DAT_006fb02c = 0;
        DAT_00735e84 = 0;
        CameraMover_SetTransitionParamB(0);
        CameraMover_SetTransitionParamA(0);
      }
      DAT_0078eb1c = DAT_0078eb1c + 1;
      return;
    case 0x40:
      if (DAT_0078eb30 != 0) {
        CameraMover_SetTransitionParamB(-(((float)param_3 - 128.0) * 0.0078125));
        DAT_006fb02c = 0;
        DAT_00735e84 = 0;
        DAT_0074810c = DAT_0073ad3c;
      }
      DAT_0078eb30 = DAT_0078eb30 + 1;
      return;
    case 0x41:
      if (DAT_0078eb24 != 0) {
        CameraMover_SetTransitionParamA(-(((float)param_3 - 128.0) * 0.0078125));
        DAT_006fb02c = 0;
        DAT_00735e84 = 0;
        DAT_0074810c = DAT_0073ad3c;
      }
      DAT_0078eb24 = DAT_0078eb24 + 1;
      return;
    case 0x42:
      if (DAT_0078eb18 != 0) {
        SelectCarCameraMover__SetZoomSpeed(((float)param_3 - 128.0) * 0.0078125);
        DAT_0074810c = DAT_0073ad3c;
        DAT_006fb02c = 0;
        DAT_00735e84 = 0;
        CameraMover_SetTransitionParamB(0);
        CameraMover_SetTransitionParamA(0);
      }
      DAT_0078eb18 = DAT_0078eb18 + 1;
    }
  }
  return;
}


// ==== 0x4aee90 FUN_004aee90

void __fastcall FUN_004aee90(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined1 *unaff_EDI;
  undefined4 local_8;
  undefined1 local_4 [4];
  
  *(undefined4 *)(unaff_EDI + 8) = param_1;
  *(undefined4 *)(unaff_EDI + 0xc) = in_EAX;
  *unaff_EDI = 0;
  FUN_004f7350(&local_8,local_4);
  *(undefined4 *)(unaff_EDI + 0x10) = local_8;
  FUN_004f6d10(&local_8,local_4);
  *(undefined4 *)(unaff_EDI + 4) = local_8;
  *(undefined4 *)(unaff_EDI + 0x14) = 0;
  return;
}


// ==== 0x4aeee0 FUN_004aeee0

void FUN_004aeee0(float param_1)

{
  undefined4 uVar1;
  int unaff_EDI;
  undefined1 local_4 [4];
  
  FUN_00496040(param_1 * *(float *)(unaff_EDI + 0x10));
  uVar1 = *(undefined4 *)(unaff_EDI + 4);
  FUN_004f6d10(local_4,&param_1);
  FUN_004f7000(uVar1,param_1);
  FUN_004f7350(&param_1,local_4);
  *(float *)(unaff_EDI + 0x14) = param_1;
  return;
}


// ==== 0x4aef50 FUN_004aef50

void __fastcall FUN_004aef50(undefined4 param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int extraout_EDX;
  undefined1 local_4 [4];
  
  FEObject__SetVisible(*(undefined4 *)(param_2 + 0xc));
  if (*(int *)(extraout_EDX + 0xc) != 0) {
    fVar2 = param_3 * *(float *)(extraout_EDX + 0x10);
    fVar1 = *(float *)(extraout_EDX + 4);
    FUN_004f7260(local_4,&param_3);
    FUN_004f7140(fVar2 + fVar1,param_3);
  }
  return;
}


// ==== 0x4aefa0 FUN_004aefa0

undefined4 * __fastcall FUN_004aefa0(undefined4 *param_1)

{
  *param_1 = 1;
  RideInfo__Init();
  RideInfo__Init();
  RideInfo__Init();
  RideInfo__Init();
  param_1[0x724] = 0;
  param_1[0x725] = 0;
  param_1[0x726] = 0;
  param_1[0x727] = 0;
  param_1[0x728] = 0;
  param_1[0x729] = 0;
  param_1[0x72a] = 0;
  param_1[0x72b] = 1;
  param_1[0x72c] = 1;
  return param_1;
}


// ==== 0x4af020 FUN_004af020

void FUN_004af020(void)

{
  FUN_004af030();
  return;
}


// ==== 0x4af030 FUN_004af030

void FUN_004af030(void)

{
  int iVar1;
  int unaff_ESI;
  
  if (((*(int *)(unaff_ESI + 0x1ca0) != 0) && (iVar1 = *(int *)(unaff_ESI + 0x1c90), iVar1 != 0)) &&
     (*(int *)(iVar1 + 8) != 0)) {
    FUN_0058c500(iVar1);
    CarLoader__DeleteUnusedRideInfos();
  }
  if (((*(int *)(unaff_ESI + 0x1ca4) != 0) && (iVar1 = *(int *)(unaff_ESI + 0x1c94), iVar1 != 0)) &&
     (*(int *)(iVar1 + 8) != 0)) {
    FUN_0058c500(iVar1);
    CarLoader__DeleteUnusedRideInfos();
  }
  if (((*(int *)(unaff_ESI + 0x1ca8) != 0) && (iVar1 = *(int *)(unaff_ESI + 0x1c98), iVar1 != 0)) &&
     (*(int *)(iVar1 + 8) != 0)) {
    FUN_0058c500(iVar1);
    CarLoader__DeleteUnusedRideInfos();
  }
  *(undefined4 *)(unaff_ESI + 0x1c9c) = 0;
  *(undefined4 *)(unaff_ESI + 0x1ca0) = 0;
  *(undefined4 *)(unaff_ESI + 0x1ca4) = 0;
  *(undefined4 *)(unaff_ESI + 0x1ca8) = 0;
  *(undefined4 *)(unaff_ESI + 0x1cb0) = 1;
  return;
}


// ==== 0x4af0e0 GarageCarLoader::LoadRideInfo

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GarageCarLoader__LoadRideInfo(void)

{
  undefined4 in_EAX;
  int unaff_ESI;
  
  RideInfo__operator_((int *)(unaff_ESI + 0x10),in_EAX);
  RideInfo__RebuildPhysicsInfo(1);
  *(undefined4 *)(unaff_ESI + 0x1c9c) = 1;
  if (*(int *)(unaff_ESI + 0x1ca8) == 0) {
    *(undefined4 *)(unaff_ESI + 0x1cb0) = 1;
    return;
  }
  if (*(int *)(unaff_ESI + 0x1cb0) == 0) {
    *(uint *)(unaff_ESI + 0x1cb0) =
         (uint)(*(int *)(unaff_ESI + 0x1570) != *(int *)(unaff_ESI + 0x10));
  }
  return;
}


// ==== 0x4af136 FUN_004af136

/* WARNING: Control flow encountered bad instruction data */

void FUN_004af136(void)

{
  func_0xff35da46();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== 0x4af140 GarageCarLoader::Update

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void GarageCarLoader__Update(int *param_1)

{
  byte *pbVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  byte *pbVar7;
  byte local_40;
  byte local_3f [63];
  
  if (param_1[0x728] != 0) {
    if (((param_1[0x724] != 0) && (*(int *)(param_1[0x724] + 8) != 0)) &&
       (iVar4 = FUN_0058c370(&DAT_00737b58), iVar4 != 0)) {
      if (((param_1[0x729] != 0) && (iVar4 = param_1[0x725], iVar4 != 0)) &&
         (*(int *)(iVar4 + 8) != 0)) {
        FUN_0058c500(iVar4);
        CarLoader__DeleteUnusedRideInfos();
      }
      RideInfo__operator_(param_1 + 0x394,param_1 + 0x1cc);
      RideInfo__RebuildPhysicsInfo(1);
      param_1[0x725] = param_1[0x724];
      param_1[0x728] = 0;
      param_1[0x729] = 1;
    }
    if (param_1[0x728] != 0) {
      return;
    }
  }
  if (param_1[0x727] != 0) {
    if (param_1[0x729] != 0) {
      iVar4 = param_1[0x725];
      if ((iVar4 != 0) && (*(int *)(iVar4 + 8) != 0)) {
        FUN_0058c500(iVar4);
        CarLoader__DeleteUnusedRideInfos();
      }
      param_1[0x729] = 0;
    }
    RideInfo__operator_(param_1 + 0x1cc,param_1 + 4);
    RideInfo__RebuildPhysicsInfo(1);
    iVar4 = 1;
    param_1[0x728] = 1;
    param_1[0x727] = 0;
    if (param_1[0x72b] == 0) {
      iVar4 = 2;
    }
    if (*param_1 == 2) {
      iVar4 = iVar4 + 2;
    }
    FUN_00565da0("DUMMY_SKIN%d",iVar4);
    iVar5 = -1;
    pbVar7 = &local_40;
    bVar2 = local_40;
    while (bVar2 != 0) {
      iVar5 = iVar5 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar7 + 1;
      pbVar7 = pbVar7 + 1;
      bVar2 = *pbVar1;
    }
    param_1[0x2dd] = iVar5;
    FUN_00565da0("DUMMY_WHEEL%d",iVar4);
    iVar4 = -1;
    pbVar7 = &local_40;
    while (local_40 != 0) {
      iVar4 = iVar4 * 0x21 + (uint)local_40;
      pbVar1 = pbVar7 + 1;
      pbVar7 = pbVar7 + 1;
      local_40 = *pbVar1;
    }
    param_1[0x2de] = iVar4;
    piVar6 = (int *)CarLoader__AllocateRideInfo(&DAT_00737b58,param_1 + 0x1cc);
    iVar4 = *piVar6;
    piVar3 = (int *)piVar6[1];
    *piVar3 = iVar4;
    *(int **)(iVar4 + 4) = piVar3;
    *DAT_00737ba8 = (int)piVar6;
    piVar3 = piVar6;
    piVar6[1] = (int)DAT_00737ba8;
    DAT_00737ba8 = piVar3;
    *piVar6 = (int)&DAT_00737ba4;
    param_1[0x724] = (int)piVar6;
    if (DAT_00737b64 == 0) {
      FUN_0058c840(&DAT_00737b58);
    }
    if (DAT_00737b6c == 0) {
      FUN_0058cbb0();
    }
  }
  return;
}


// ==== 0x4af340 FUN_004af340

void FUN_004af340(void)

{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x1ca4) != 0) {
    if (((*(int *)(unaff_ESI + 0x1ca8) != 0) && (iVar2 = *(int *)(unaff_ESI + 0x1c98), iVar2 != 0))
       && (*(int *)(iVar2 + 8) != 0)) {
      FUN_0058c500(iVar2);
      CarLoader__DeleteUnusedRideInfos();
    }
    piVar1 = (int *)(unaff_ESI + 0x1570);
    RideInfo__operator_(piVar1,unaff_ESI + 0xe50);
    RideInfo__RebuildPhysicsInfo(1);
    *(undefined4 *)(unaff_ESI + 0x1c98) = *(undefined4 *)(unaff_ESI + 0x1c94);
    *(undefined4 *)(unaff_ESI + 0x1ca4) = 0;
    *(undefined4 *)(unaff_ESI + 0x1ca8) = 1;
    *(undefined4 *)(unaff_ESI + 0x1cb0) = 0;
    if ((*(int *)(unaff_ESI + 0x1c9c) != 0) && (*(int *)(unaff_ESI + 0x10) != *piVar1)) {
      *(undefined4 *)(unaff_ESI + 0x1cb0) = 1;
    }
    if ((*(int *)(unaff_ESI + 0x1ca0) != 0) && (*(int *)(unaff_ESI + 0x730) != *piVar1)) {
      *(undefined4 *)(unaff_ESI + 0x1cb0) = 1;
    }
    *(uint *)(unaff_ESI + 0x1cac) = (uint)(*(int *)(unaff_ESI + 0x1cac) == 0);
  }
  return;
}


// ==== 0x4af420 GetGarageCarLoader

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined * GetGarageCarLoader(void)

{
  undefined *puVar1;
  int unaff_ESI;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  pcStack_c = FUN_00688d0e;
  local_10 = ExceptionList;
  if ((DAT_00792fa0 & 1) == 0) {
    DAT_00792fa0 = DAT_00792fa0 | 1;
    local_8 = 0;
    ExceptionList = &local_10;
    eh_vector_constructor_iterator(&DAT_0078f620,0x1cc0,2,FUN_004aefa0,FUN_004af020);
    _atexit(FUN_006964a0);
  }
  if ((unaff_ESI == 1) || (puVar1 = &DAT_007912e0, unaff_ESI != 2)) {
    puVar1 = &DAT_0078f620;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== 0x4af4a0 FUN_004af4a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004af4a0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)GetGarageCarLoader();
  *puVar1 = 1;
  _DAT_00737b60 = 1;
  DAT_00737b64 = 1;
  _DAT_00737b68 = 0;
  _DAT_00737b70 = 0;
  puVar1[0x727] = 0;
  puVar1[0x728] = 0;
  puVar1[0x729] = 0;
  puVar1[0x72a] = 0;
  puVar1[0x72c] = 1;
  puVar1[0x72b] = 1;
  puVar1 = (undefined4 *)GetGarageCarLoader();
  *puVar1 = 2;
  _DAT_00737b60 = 1;
  DAT_00737b64 = 1;
  _DAT_00737b68 = 0;
  _DAT_00737b70 = 0;
  puVar1[0x727] = 0;
  puVar1[0x728] = 0;
  puVar1[0x729] = 0;
  puVar1[0x72a] = 0;
  puVar1[0x72c] = 1;
  puVar1[0x72b] = 1;
  return;
}


// ==== 0x4af540 FUN_004af540

undefined4 FUN_004af540(void)

{
  int iVar1;
  
  iVar1 = GetGarageCarLoader();
  if (*(int *)(iVar1 + 0x1c9c) == 0) {
    iVar1 = GetGarageCarLoader();
    if (*(int *)(iVar1 + 0x1ca0) == 0) {
      iVar1 = GetGarageCarLoader();
      if (*(int *)(iVar1 + 0x1c9c) == 0) {
        iVar1 = GetGarageCarLoader();
        if (*(int *)(iVar1 + 0x1ca0) == 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}


// ==== 0x4af5a0 FUN_004af5a0

void FUN_004af5a0(void)

{
  int iVar1;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (iVar1 != 0) {
    *(undefined4 *)(*(int *)(iVar1 + 0x14) + 0x9c) = 0;
    return;
  }
  uRam0000009c = 0;
  return;
}


// ==== 0x4af5d0 FUN_004af5d0

void FUN_004af5d0(void)

{
  FEPackageList__FindByName(&DAT_00746104);
  if (DAT_006fb02c != 0) {
    FUN_004aff20();
  }
  DAT_00735e84 = 1;
  DAT_006fb02c = 0;
  DAT_0074810c = DAT_0073ad3c;
  return;
}


// ==== 0x4af620 GarageMainScreen::GarageMainScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 *
GarageMainScreen__GarageMainScreen
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,int *param_4,int param_5)

{
  byte *pbVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  void *pvVar7;
  uint uVar8;
  char *pcVar9;
  bool bVar10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689356;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FEScreen__FEScreen(param_1,param_2);
  *param_1 = &PTR_GarageMainScreen___GarageMainScreen_006c61e0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  local_4._0_1_ = 1;
  local_4._1_3_ = 0;
  param_1[0x1a] = param_5;
  CarOrbiter__CarOrbiter();
  param_1[0x25] = 1;
  param_1[0x26] = 1;
  param_1[0x28] = 1;
  param_1[0x24] = 0;
  param_1[0x27] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  *(undefined1 *)(param_1 + 0x29) = 0;
  param_1[0x2d] = 0;
  param_1[0x2a] = 0;
  param_1[0x2e] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  *(undefined1 *)(param_1 + 0x2f) = 0;
  param_1[0x33] = 0;
  param_1[0x30] = 0;
  param_1[0x34] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  *(undefined1 *)(param_1 + 0x35) = 0;
  param_1[0x39] = 0;
  param_1[0x36] = 0;
  param_1[0x3a] = 0;
  param_1[0x46] = 1;
  param_1[0x43] = 1;
  local_4._0_1_ = 2;
  param_1[0x44] = param_3;
  param_1[0x49] = 4;
  *(undefined2 *)(param_1 + 0x19) = 0;
  param_1[0x3b] = 4;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  *(undefined2 *)(param_1 + 0x42) = 0;
  if (param_5 == 0) {
    uVar5 = FEng_FindObjectByHash();
    param_1[0x1b] = uVar5;
    uVar5 = FEng_FindObjectByHash();
    param_1[0x1c] = uVar5;
    uVar5 = FEng_FindObjectByHash();
    param_1[0x1d] = uVar5;
    FEObject__SetFormattedText(&DAT_006cc568,&DAT_007588c4);
    iVar6 = LanguageStrings__FindByHash();
    if (iVar6 == 0) {
      iVar6 = LanguageStrings__FindByHash();
    }
    FEObject__SetFormattedText("%s %d",iVar6,DAT_00758ad4);
    if ((((param_1[3] == 0) || (iVar6 = FUN_004f65d0(), iVar6 == 0)) ||
        (iVar6 = FUN_004ffb70(), iVar6 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(0x19598ef7);
    }
    if ((((param_1[3] == 0) || (iVar6 = FUN_004f65d0(), iVar6 == 0)) ||
        (iVar6 = FUN_004ffb70(), iVar6 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(0xcd20936b);
    }
    FUN_004aee90();
    if ((((param_1[3] == 0) || (iVar6 = FUN_004f65d0(), iVar6 == 0)) ||
        (iVar6 = FUN_004ffb70(), iVar6 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(0xe3507743);
    }
    if ((((param_1[3] == 0) || (iVar6 = FUN_004f65d0(), iVar6 == 0)) ||
        (iVar6 = FUN_004ffb70(), iVar6 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(0xc34fd0d6);
    }
    FUN_004aee90();
    if ((((param_1[3] == 0) || (iVar6 = FUN_004f65d0(), iVar6 == 0)) ||
        (iVar6 = FUN_004ffb70(), iVar6 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(0x595086e4);
    }
    if ((((param_1[3] == 0) || (iVar6 = FUN_004f65d0(), iVar6 == 0)) ||
        (iVar6 = FUN_004ffb70(), iVar6 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(0xd178b58);
    }
  }
  else {
    if (param_5 != 1) goto LAB_004afbee;
    uVar5 = FEng_FindObjectByHash();
    param_1[0x1b] = uVar5;
    uVar5 = FEng_FindObjectByHash();
    param_1[0x1c] = uVar5;
    uVar5 = FEng_FindObjectByHash();
    param_1[0x1d] = uVar5;
    FEObject__SetFormattedText(&DAT_006cc568,&DAT_00768208);
    iVar6 = LanguageStrings__FindByHash();
    if (iVar6 == 0) {
      iVar6 = LanguageStrings__FindByHash();
    }
    FEObject__SetFormattedText("%s %d",iVar6,DAT_00768418);
    if ((((param_1[3] == 0) || (iVar6 = FUN_004f65d0(), iVar6 == 0)) ||
        (iVar6 = FUN_004ffb70(), iVar6 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(0x19598ef8);
    }
    if ((((param_1[3] == 0) || (iVar6 = FUN_004f65d0(), iVar6 == 0)) ||
        (iVar6 = FUN_004ffb70(), iVar6 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(0xcd20936c);
    }
    FUN_004aee90();
    if ((((param_1[3] == 0) || (iVar6 = FUN_004f65d0(), iVar6 == 0)) ||
        (iVar6 = FUN_004ffb70(), iVar6 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(0xe3507744);
    }
    if ((((param_1[3] == 0) || (iVar6 = FUN_004f65d0(), iVar6 == 0)) ||
        (iVar6 = FUN_004ffb70(), iVar6 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(0xc34fd0d7);
    }
    FUN_004aee90();
    if ((((param_1[3] == 0) || (iVar6 = FUN_004f65d0(), iVar6 == 0)) ||
        (iVar6 = FUN_004ffb70(), iVar6 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(0x595086e5);
    }
    if ((((param_1[3] == 0) || (iVar6 = FUN_004f65d0(), iVar6 == 0)) ||
        (iVar6 = FUN_004ffb70(), iVar6 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(0xd178b59);
    }
  }
  FUN_004aee90();
LAB_004afbee:
  uVar5 = GetGarageCarLoader();
  param_1[0x45] = uVar5;
  GarageMainScreen__SetRideInfo(param_1,param_4,param_1[0x46]);
  pvVar7 = _malloc(0x9b0);
  local_4._0_1_ = 3;
  if (pvVar7 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FrontEndRenderingCar__FrontEndRenderingCar(0,param_1[0x44]);
  }
  param_1[0x10] = uVar5;
  pvVar7 = _malloc(0x9b0);
  local_4._0_1_ = 4;
  if (pvVar7 == (void *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = FrontEndRenderingCar__FrontEndRenderingCar(0,param_1[0x44]);
  }
  param_1[0x11] = iVar6;
  *(undefined4 *)(iVar6 + 0x994) = 1;
  *(undefined4 *)(param_1[0x11] + 0x99c) = 1;
  local_4 = CONCAT31(local_4._1_3_,2);
  if ((*(int *)(param_1[0x45] + 0x1ca8) != 0) && (iVar6 = param_1[0x45] + 0x1570, iVar6 != 0)) {
    FrontEndRenderingCar__ReInit(iVar6);
    FrontEndRenderingCar__ReInit(iVar6);
  }
  pvVar7 = _malloc(0x1a0);
  if (pvVar7 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = SelectCarCameraMover__ctor();
  }
  param_1[0x18] = uVar5;
  param_1[0x20] = uVar5;
  SelectCarCameraMover__SetDramaticMode();
  param_1[0x21] = 1;
  pcVar9 = "PLATFORM";
  uVar8 = 0x50;
  iVar6 = -1;
  do {
    iVar6 = iVar6 * 0x21 + uVar8;
    pbVar1 = (byte *)(pcVar9 + 1);
    uVar8 = (uint)*pbVar1;
    pcVar9 = pcVar9 + 1;
  } while (*pbVar1 != 0);
  puVar2 = param_1 + 0x12;
  param_1[0x14] = iVar6;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  if (iVar6 != 0) {
    *DAT_00743c74 = puVar2;
    puVar4 = puVar2;
    param_1[0x13] = DAT_00743c74;
    DAT_00743c74 = puVar4;
    *puVar2 = &DAT_00743c70;
  }
  if (param_1[0x14] != 0) {
    Solid_FindInAllLists();
    FUN_0053f4b0();
  }
  FUN_004ada60(&DAT_00746dd0);
  bSPrintf_regdst(0x20,"CAR_NAME_%s",*param_4 * 0xc90 + DAT_00734588);
  uVar5 = FEng__HashName();
  iVar6 = param_1[0x1b];
  if (iVar6 != 0) {
    *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) | 0x400000;
    puVar2 = DAT_00735710;
    bVar10 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar6 + 0x5c) = uVar5;
    if (bVar10) {
      (**(code **)*puVar2)(iVar6);
    }
    *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) & 0xfffffffd | 0x400000;
  }
  param_1[0x47] = 0;
  DAT_006fb02c = 0;
  FUN_004b1c50(0);
  FUN_004b1d20();
  FUN_004b0340(0);
  if (((DAT_006f1dd8 != 0) && (*(int *)(DAT_007356a8 + 0x104) != 0)) &&
     (piVar3 = *(int **)(*(int *)(DAT_007356a8 + 0x104) + 0x14), piVar3 != (int *)0x0)) {
    (**(code **)(*piVar3 + 0x98))(0,0xffffffff);
  }
  ExceptionList = pvStack_c;
  return param_1;
}


// ==== 0x4afe20 GarageMainScreen::_GarageMainScreen

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void * __thiscall GarageMainScreen___GarageMainScreen(void *param_1,byte param_2)

{
  FUN_004afe40(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4afe40 FUN_004afe40

void FUN_004afe40(undefined4 *param_1)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006873d0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_GarageMainScreen___GarageMainScreen_006c61e0;
  local_4 = 2;
  MiniWorld__Close(&DAT_00746dd0);
  if ((undefined4 *)param_1[0x18] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x18])(1);
  }
  pvVar1 = (void *)param_1[0x10];
  if (pvVar1 != (void *)0x0) {
    FUN_0056a0d0();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[0x11];
  if (pvVar1 != (void *)0x0) {
    FUN_0056a0d0();
    _free(pvVar1);
  }
  if (*(int *)(DAT_007356a8 + 0xbc) != 0) {
    FUN_00523060(*(int *)(DAT_007356a8 + 0xbc));
  }
  FUN_004aea00(param_1 + 0x20);
  if ((param_1[0x14] != 0) || (param_1[0x15] != 0)) {
    iVar2 = param_1[0x12];
    piVar3 = (int *)param_1[0x13];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
  }
  param_1[0x15] = 0;
  param_1[0x14] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4aff20 FUN_004aff20

void __fastcall FUN_004aff20(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x60);
  if ((*(int *)(iVar1 + 0x2c) != 2) && (*(int *)(iVar1 + 0x2c) != 0)) {
    *(undefined4 *)(iVar1 + 0x2c) = 3;
    *(undefined4 *)(iVar1 + 0x188) = 0;
  }
  iVar1 = *(int *)(param_2 + 0x60);
  if ((*(int *)(iVar1 + 0x2c) != 2) && (*(int *)(iVar1 + 0x2c) != 0)) {
    *(undefined4 *)(iVar1 + 0x2c) = 3;
    *(undefined4 *)(iVar1 + 0x184) = 0;
  }
  if (DAT_006fb02c != 0) {
    FUN_004aea50(param_2 + 0x80,DAT_00735e88);
  }
  return;
}


// ==== 0x4aff90 GarageMainScreen::UpdateCarStatisticsBars

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GarageMainScreen__UpdateCarStatisticsBars(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  
  iVar2 = param_1;
  uVar1 = (&DAT_00758ad4)[*(int *)(param_1 + 0x68) * 0x3e51];
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  FEObject__SetFormattedText("%s %d",iVar3,uVar1);
  param_1 = *(int *)(param_1 + 0x114);
  if (*(int *)(param_1 + 0x1c9c) == 0) {
    if (*(int *)(param_1 + 0x1ca0) == 0) {
      if (*(int *)(param_1 + 0x1ca4) == 0) {
        if (*(int *)(param_1 + 0x1ca8) == 0) {
          param_1 = 0;
        }
        else {
          param_1 = param_1 + 0x1570;
        }
      }
      else {
        param_1 = param_1 + 0xe50;
      }
    }
    else {
      param_1 = param_1 + 0x730;
    }
  }
  else {
    param_1 = param_1 + 0x10;
  }
  if ((*(int *)(iVar2 + 0x94) == 0) && (param_1 != 0)) {
    FUN_004b1cb0(0);
    fVar4 = (float10)RideInfo__GetAccelRating();
    FUN_004aeee0((float)fVar4);
    fVar4 = (float10)RideInfo__GetTopSpeedRating();
    FUN_004aeee0((float)fVar4);
    fVar4 = (float10)RideInfo__GetHandlingRating();
    FUN_004aeee0((float)fVar4);
    if (*(int *)(iVar2 + 0x98) == 0) {
      fVar4 = (float10)RideInfo__GetAccelRating();
      FUN_004aef50((float)fVar4);
      fVar4 = (float10)RideInfo__GetTopSpeedRating();
      FUN_004aef50((float)fVar4);
      fVar4 = (float10)RideInfo__GetHandlingRating();
      FUN_004aef50((float)fVar4);
      return;
    }
    if (*(int *)(iVar2 + 0xb0) != 0) {
      FEObject__SetInvisible(*(int *)(iVar2 + 0xb0));
    }
    if (*(int *)(iVar2 + 200) != 0) {
      FEObject__SetInvisible(*(int *)(iVar2 + 200));
    }
    if (*(int *)(iVar2 + 0xe0) != 0) {
      FEObject__SetInvisible(*(int *)(iVar2 + 0xe0));
      return;
    }
  }
  else {
    FUN_004b1c50(0);
  }
  return;
}


// ==== 0x4b0150 FUN_004b0150

void __fastcall FUN_004b0150(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_EAX;
  undefined4 unaff_EDI;
  
  DAT_0074810c = DAT_0073ad3c;
  iVar1 = *(int *)(in_EAX + 0x60);
  DAT_006fb02c = 0;
  DAT_00735e84 = 0;
  if ((*(int *)(iVar1 + 0x2c) != 2) && (*(int *)(iVar1 + 0x2c) != 0)) {
    *(undefined4 *)(iVar1 + 0x2c) = 3;
    *(undefined4 *)(iVar1 + 0x188) = 0;
  }
  iVar1 = *(int *)(in_EAX + 0x60);
  if ((*(int *)(iVar1 + 0x2c) != 2) && (*(int *)(iVar1 + 0x2c) != 0)) {
    *(undefined4 *)(iVar1 + 0x2c) = 3;
    *(undefined4 *)(iVar1 + 0x184) = 0;
  }
  DAT_006fb034 = param_2;
  DAT_00735e88 = unaff_EDI;
  FUN_004aea50(in_EAX + 0x80,unaff_EDI);
  return;
}


// ==== 0x4b01c0 FUN_004b01c0

void FUN_004b01c0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + 0xf8) = 0;
  *(undefined4 *)(unaff_EDI + 0xfc) = 0;
  *(undefined4 *)(unaff_EDI + 0x100) = 0;
  *(undefined4 *)(unaff_EDI + 0xf0) = 0;
  DAT_006fb02c = 0;
  DAT_00735e84 = 0;
  *(undefined4 *)(unaff_EDI + 0xf4) = 0x41b1c71c;
  DAT_0074810c = DAT_0073ad3c;
  SelectCarCameraMover__SetPresetB();
  iVar2 = DAT_007356a8;
  if (((*(int *)(DAT_007356a8 + 0xbc) != 0) && (*(int *)(*(int *)(unaff_EDI + 0x114) + 0x1ca8) != 0)
      ) && (puVar1 = (undefined4 *)(*(int *)(unaff_EDI + 0x114) + 0x1570),
           puVar1 != (undefined4 *)0x0)) {
    FUN_00522f90();
    EAXFrontEnd__PlayDriveOnSnd
              (*(undefined4 *)(iVar2 + 0xbc),0x55,*(undefined4 *)(unaff_EDI + 0x110),*puVar1);
  }
  return;
}


// ==== 0x4b0270 FUN_004b0270

void FUN_004b0270(void)

{
  undefined4 *puVar1;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + 0x100) = 0;
  DAT_006fb02c = 0;
  DAT_00735e84 = 0;
  *(undefined4 *)(unaff_EDI + 0xf8) = 0x41a00000;
  *(undefined4 *)(unaff_EDI + 0xf4) = 0xc1555555;
  *(undefined4 *)(unaff_EDI + 0xfc) = 0xc1700000;
  *(undefined4 *)(unaff_EDI + 0xf0) = 0xc1700000;
  DAT_0074810c = DAT_0073ad3c;
  SelectCarCameraMover__SetPresetC();
  if (((*(int *)(DAT_007356a8 + 0xbc) != 0) && (*(int *)(*(int *)(unaff_EDI + 0x114) + 0x1ca8) != 0)
      ) && (puVar1 = (undefined4 *)(*(int *)(unaff_EDI + 0x114) + 0x1570),
           puVar1 != (undefined4 *)0x0)) {
    EAXFrontEnd__PlayDriveOnSnd
              (*(int *)(DAT_007356a8 + 0xbc),0x53,*(undefined4 *)(unaff_EDI + 0x110),*puVar1);
    EAXFrontEnd__PlayDriveOnSnd
              (*(undefined4 *)(DAT_007356a8 + 0xbc),0x54,*(undefined4 *)(unaff_EDI + 0x110),*puVar1)
    ;
  }
  return;
}


// ==== 0x4b0340 FUN_004b0340

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b0340(void)

{
  float fVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  int unaff_EBX;
  bool bVar7;
  ushort uVar8;
  float10 fVar9;
  float local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined1 local_d0 [64];
  char local_90 [140];
  
  local_108 = *(float *)(unaff_EBX + 0xf0);
  bVar7 = false;
  if (*(int *)(unaff_EBX + 0x10c) == 0) {
    bVar7 = *(int *)(*(int *)(unaff_EBX + 0x114) + 0x1ca4) != 0;
    if (bVar7) {
      FUN_004af340();
    }
    *(undefined4 *)(unaff_EBX + 0xf0) = 0;
    *(undefined4 *)(unaff_EBX + 0xec) = 4;
  }
  else {
    switch(*(undefined4 *)(unaff_EBX + 0xec)) {
    case 0:
      if (*(int *)(*(int *)(unaff_EBX + 0x60) + 0x2c) != 1) {
        *(undefined4 *)(*(int *)(unaff_EBX + 0x60) + 0x2c) = 2;
      }
      iVar3 = SelectCarCameraMover__IsPresetDone();
      if (iVar3 != 0) {
        FUN_004b01c0();
        *(undefined4 *)(unaff_EBX + 0xec) = 1;
      }
      break;
    case 1:
      fVar1 = DAT_0073ad38 + *(float *)(unaff_EBX + 0x100);
      *(float *)(unaff_EBX + 0x100) = fVar1;
      *(float *)(unaff_EBX + 0xf0) =
           fVar1 * *(float *)(unaff_EBX + 0xf8) +
           fVar1 * *(float *)(unaff_EBX + 0xf4) * fVar1 * _K_HALF + *(float *)(unaff_EBX + 0xfc);
      if (1.5 < fVar1) {
LAB_004b04a2:
        *(undefined4 *)(unaff_EBX + 0xec) = 2;
      }
      break;
    case 2:
      iVar3 = *(int *)(unaff_EBX + 0x114);
      if (*(int *)(iVar3 + 0x1ca4) == 0) {
        if ((*(int *)(iVar3 + 0x1ca8) != 0) && (*(int *)(iVar3 + 0x1cb0) != 0)) {
          fVar9 = (float10)DAT_0073ad38 + (float10)*(float *)(unaff_EBX + 0x100);
          *(float *)(unaff_EBX + 0x100) = (float)fVar9;
          fVar9 = fVar9 * (float10)*(float *)(unaff_EBX + 0xf8) +
                  fVar9 * (float10)*(float *)(unaff_EBX + 0xf4) * fVar9 * (float10)_K_HALF +
                  (float10)*(float *)(unaff_EBX + 0xfc);
          goto LAB_004b05bb;
        }
      }
      else {
        iVar3 = *(int *)(iVar3 + 0x1cb0);
        FUN_004af340();
        if (iVar3 == 0) {
          *(undefined4 *)(unaff_EBX + 0xec) = 4;
          bVar7 = true;
        }
        else {
          FUN_004b0270();
          *(undefined4 *)(unaff_EBX + 0xec) = 3;
          bVar7 = true;
        }
      }
      break;
    case 3:
      fVar1 = DAT_0073ad38 + *(float *)(unaff_EBX + 0x100);
      *(float *)(unaff_EBX + 0x100) = fVar1;
      if (fVar1 <= 1.5) {
        bDegreesToAngle16((fVar1 / 1.5) * 45.0 + 225.0);
        fVar9 = (float10)FUN_00564b10();
        fVar9 = -((fVar9 + (float10)_K_ONE) * (float10)3.4142137 * (float10)15.0);
LAB_004b05bb:
        *(float *)(unaff_EBX + 0xf0) = (float)fVar9;
      }
      else {
        SelectCarCameraMover__EndPreset();
        *(undefined4 *)(unaff_EBX + 0xf0) = 0;
        *(undefined4 *)(unaff_EBX + 0xec) = 4;
      }
      break;
    case 4:
      iVar3 = *(int *)(unaff_EBX + 0x114);
      if (*(int *)(iVar3 + 0x1ca0) == 0) {
        if (*(int *)(iVar3 + 0x1ca4) != 0) {
          if ((*(int *)(iVar3 + 0x1ca8) == 0) || (*(int *)(iVar3 + 0x1cb0) == 0)) {
            FUN_004af340();
            bVar7 = true;
          }
          else {
            SelectCarCameraMover__SetPresetA();
            *(undefined4 *)(unaff_EBX + 0xec) = 0;
          }
        }
      }
      else {
        if ((*(int *)(iVar3 + 0x1ca8) == 0) || (*(int *)(iVar3 + 0x1cb0) == 0)) goto LAB_004b04a2;
        SelectCarCameraMover__SetPresetA();
        *(undefined4 *)(unaff_EBX + 0xec) = 0;
      }
    }
    *(undefined4 *)(*(int *)(unaff_EBX + 0x60) + 0x194) = *(undefined4 *)(unaff_EBX + 0xf0);
  }
  *(float *)(unaff_EBX + 0x104) = *(float *)(unaff_EBX + 0xf0) - local_108;
  if (((bVar7) && (*(int *)(*(int *)(unaff_EBX + 0x114) + 0x1ca8) != 0)) &&
     (iVar3 = *(int *)(unaff_EBX + 0x114) + 0x1570, iVar3 != 0)) {
    if (*(int *)(unaff_EBX + 0x40) != 0) {
      FrontEndRenderingCar__ReInit(iVar3);
    }
    if (*(int *)(unaff_EBX + 0x44) != 0) {
      FrontEndRenderingCar__ReInit(iVar3);
    }
  }
  iVar3 = *(int *)(unaff_EBX + 0x114);
  if (*(int *)(iVar3 + 0x1c9c) == 0) {
    if (*(int *)(iVar3 + 0x1ca0) != 0) {
      iVar3 = iVar3 + 0x730;
      goto LAB_004b0665;
    }
    if (*(int *)(iVar3 + 0x1ca4) != 0) {
      iVar3 = iVar3 + 0xe50;
      goto LAB_004b0665;
    }
    if (*(int *)(iVar3 + 0x1ca8) != 0) {
      iVar3 = iVar3 + 0x1570;
      goto LAB_004b0665;
    }
  }
  else {
    iVar3 = iVar3 + 0x10;
LAB_004b0665:
    if (iVar3 != 0) {
      if (DAT_00745e40 == 0) {
        fVar9 = (float10)CalculateRideReputationPoints();
        *(float *)(unaff_EBX + 0x7c) = (float)fVar9;
        *(float *)(unaff_EBX + 0x78) = (float)fVar9;
      }
      else {
        fVar9 = (float10)CalculateRideReputationPoints();
        *(float *)(unaff_EBX + 0x78) = (float)fVar9;
        fVar9 = (float10)CalculateRideReputationPoints();
        *(float *)(unaff_EBX + 0x7c) = (float)fVar9;
      }
    }
  }
  FUN_004ae1f0();
  if (DAT_00735768 == '\0') {
    if (DAT_0078eb14 != '\0') {
      *(undefined4 *)(*(int *)(unaff_EBX + 0x60) + 0x2c) = 3;
      DAT_0078eb14 = '\0';
    }
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) &&
       (iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 != 0)) {
      *(undefined2 *)(iVar3 + 0x1e) = 1;
    }
  }
  else {
    DAT_0078eb14 = '\x01';
    if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
       (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
      if (DAT_0073578c == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(0xf80dbcae);
      }
    }
    FEObject__SetInvisible(iVar3);
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) &&
       (iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 != 0)) {
      *(undefined2 *)(iVar3 + 0x1e) = 0;
    }
    DAT_0074810c = DAT_0073ad3c;
    DAT_00748840 = DAT_0073ad3c;
    DAT_006fb02c = 0;
    local_f0 = 0x42c60000;
    local_ec = 0x42c60000;
    local_e8 = 0x42c60000;
    local_e0 = 0x42c60000;
    local_dc = 0x42c60000;
    local_d8 = 0x42c60000;
    local_100 = 0;
    local_fc = 0;
    local_f8 = 0x3f800000;
    local_108 = 0.0;
    local_104 = 0x42340000;
    cVar2 = FUN_005136f0(&local_108,&local_104);
    if ((DAT_00735f0c == '\0') && (cVar2 != '\0')) {
      CameraMover_SetupSpline
                (local_f0,local_ec,local_e8,local_e0,local_dc,local_d8,local_108,local_104,local_100
                 ,local_fc,local_f8);
    }
    else {
      CameraMover_SetupSpline
                (DAT_006fbe58,DAT_006fbe54,DAT_006fbe5c,DAT_00735f14,DAT_006fbe64,DAT_00735f18,
                 local_108,local_104,local_100,local_fc,local_f8);
    }
  }
  if (DAT_00777b4c == 1) {
    iVar3 = LanguageStrings__FindByHash();
    if (iVar3 == 0) {
      iVar3 = LanguageStrings__FindByHash();
    }
    iVar6 = 0x80;
    pcVar5 = local_90;
    do {
      cVar2 = pcVar5[iVar3 - (int)local_90];
      iVar6 = iVar6 + -1;
      *pcVar5 = cVar2;
      if (cVar2 == '\0') break;
      pcVar5 = pcVar5 + 1;
    } while (iVar6 != 0);
    if (((DAT_0073494c != 0) || (DAT_00735ec1 != '\0')) ||
       (uVar4 = DAT_0076026c, DAT_0073440c != '\0')) {
      uVar4 = 1000000000;
    }
    bSPrintf_regdst(0x40,&DAT_006ca778,uVar4);
    FUN_004f6850(local_90,local_d0);
    if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
       (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
      if (DAT_0073578c != 0) {
        uVar4 = FUN_004ef050(0x29566d7);
        FEObject__SetVisible(uVar4);
        goto LAB_004b09ed;
      }
      iVar3 = 0;
    }
    FEObject__SetVisible(iVar3);
  }
  else {
    FUN_004f6850(&DAT_006b9172);
    if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar3 = FUN_004f65d0(), iVar3 == 0)) ||
       (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
      if (DAT_0073578c == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(0x29566d7);
      }
    }
    FEObject__SetInvisible(iVar3);
  }
LAB_004b09ed:
  if (*(int *)(unaff_EBX + 0x68) == 0) {
    uVar4 = FEng_FindObjectByHash();
    iVar3 = *(int *)(unaff_EBX + 0x68);
  }
  else {
    if (*(int *)(unaff_EBX + 0x68) != 1) goto LAB_004b0a48;
    uVar4 = FEng_FindObjectByHash();
    iVar3 = *(int *)(unaff_EBX + 0x68);
  }
  *(undefined4 *)(unaff_EBX + 0x70) = uVar4;
  FEObject__SetFormattedText(&DAT_006cc568,&DAT_007588c4 + iVar3 * 0xf944);
LAB_004b0a48:
  local_108 = (float)(DAT_0073ad3c - DAT_0074810c);
  fVar1 = (float)(int)local_108 * 0.00025;
  if (DAT_00735e84 == '\0') {
    uVar8 = (ushort)(fVar1 < 30.0) << 8 | (ushort)(fVar1 == 30.0) << 0xe;
  }
  else {
    uVar8 = (ushort)(fVar1 < 120.0) << 8 | (ushort)(fVar1 == 120.0) << 0xe;
  }
  if ((DAT_006fb02c == 0) || (uVar8 != 0)) {
    DAT_00748840 = DAT_0073ad3c;
  }
  if ((DAT_006fb02c == 0) && (uVar8 == 0)) {
    DAT_0074810c = DAT_0073ad3c;
    DAT_00748840 = DAT_0073ad3c;
    DAT_006fb02c = 1;
  }
  if ((*(int *)(unaff_EBX + 0x124) == 4) && (DAT_006fb02c != 0)) {
    if (*(int *)(*(int *)(unaff_EBX + 0x60) + 0x34) == 0) {
      CameraMover_SetTransitionParamB(0x3e19999a);
      local_108 = (float)(DAT_0073ad3c - DAT_00748840);
      FUN_00564ad0((float)(int)local_108 * 0.00025,0x41e80000);
      _ftol_nocw();
      fVar9 = (float10)FUN_00564b10();
      if (fVar9 <= (float10)_K_HALF) {
        if (fVar9 < (float10)-0.5) {
          fVar9 = (float10)-0.5;
        }
      }
      else {
        fVar9 = (float10)_K_HALF;
      }
      CameraMover_SetTransitionParamA((float)((float10)0.05 * fVar9));
    }
    else {
      SelectCarCameraMover__ApplyMagazineOrientation();
    }
  }
  FUN_004b1760(unaff_EBX,*(undefined4 *)(unaff_EBX + 0x40),0);
  FUN_004b1760(unaff_EBX,*(undefined4 *)(unaff_EBX + 0x44),1);
  GarageMainScreen__UpdateCarStatisticsBars(unaff_EBX);
  if (((-1 < DAT_006f0fb8) && (*(int *)(*(int *)(unaff_EBX + 0x114) + 0x1ca8) != 0)) &&
     (iVar3 = *(int *)(unaff_EBX + 0x114) + 0x1570, iVar3 != 0)) {
    DAT_006f0fb8 = -1;
    FUN_005824b0(iVar3);
  }
  GarageMainScreen__DisplayReputation(unaff_EBX);
  return;
}


// ==== 0x4b0c00 FUN_004b0c00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b0c00(void)

{
  int iVar1;
  float fVar2;
  char cVar3;
  int in_EAX;
  int iVar4;
  int iVar5;
  
  iVar1 = in_EAX + 0x80;
  cVar3 = FUN_004aeac0(iVar1);
  if (cVar3 != '\0') {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar4 == 0) || (*(int *)(iVar4 + 0x18) == 0)) &&
       (((float)DAT_007064ac != 0.0 || (DAT_00735eb4 != '\0')))) {
      DAT_00735eb4 = (float)DAT_007064ac != 0.0;
      iVar4 = *(int *)(in_EAX + 0x60);
      if ((*(int *)(iVar4 + 0x2c) != 2) && (*(int *)(iVar4 + 0x2c) != 0)) {
        iVar5 = -DAT_007064ac;
        *(undefined4 *)(iVar4 + 0x2c) = 3;
        *(float *)(iVar4 + 0x180) = (float)iVar5 * 0.02;
      }
      DAT_006fb02c = 0;
      DAT_00735e84 = 0;
      DAT_0074810c = DAT_0073ad3c;
    }
    if (DAT_007064b0 != '\0') {
      iVar4 = *(int *)(in_EAX + 0x60);
      if ((*(int *)(iVar4 + 0x2c) != 2) && (*(int *)(iVar4 + 0x2c) != 0)) {
        fVar2 = (float)DAT_007064a4;
        *(undefined4 *)(iVar4 + 0x2c) = 3;
        *(float *)(iVar4 + 0x188) = fVar2 * _K_HALF;
      }
      iVar4 = *(int *)(in_EAX + 0x60);
      if ((*(int *)(iVar4 + 0x2c) != 2) && (*(int *)(iVar4 + 0x2c) != 0)) {
        fVar2 = (float)DAT_007064a8;
        *(undefined4 *)(iVar4 + 0x2c) = 3;
        *(float *)(iVar4 + 0x184) = fVar2 * _K_HALF;
      }
      DAT_006fb02c = 0;
      DAT_00735e84 = 0;
      DAT_0074810c = DAT_0073ad3c;
    }
    if (((DAT_007064b1 != '\0') ||
        ((iVar4 = FEPackageList__FindByName(&DAT_00746104), iVar4 != 0 &&
         (*(int *)(iVar4 + 0x18) != 0)))) && (*(int *)(in_EAX + 0x84) != 0)) {
      if ((*(int *)(in_EAX + 0x8c) == 4) && (cVar3 = FUN_004aeac0(iVar1), cVar3 != '\0')) {
        if (DAT_0078eb30 != 0) {
          CameraMover_SetTransitionParamB(0);
          DAT_006fb02c = 0;
          DAT_00735e84 = 0;
          DAT_0074810c = DAT_0073ad3c;
        }
        DAT_0078eb30 = DAT_0078eb30 + 1;
      }
      if (*(int *)(in_EAX + 0x84) != 0) {
        if ((*(int *)(in_EAX + 0x8c) == 4) && (cVar3 = FUN_004aeac0(iVar1), cVar3 != '\0')) {
          if (DAT_0078eb24 != 0) {
            CameraMover_SetTransitionParamA(0);
            DAT_006fb02c = 0;
            DAT_00735e84 = 0;
            DAT_0074810c = DAT_0073ad3c;
          }
          DAT_0078eb24 = DAT_0078eb24 + 1;
        }
        if (((*(int *)(in_EAX + 0x84) != 0) && (*(int *)(in_EAX + 0x8c) == 4)) &&
           (cVar3 = FUN_004aeac0(iVar1), cVar3 != '\0')) {
          if (DAT_0078eb18 != 0) {
            SelectCarCameraMover__SetZoomSpeed(0);
            DAT_0074810c = DAT_0073ad3c;
            DAT_006fb02c = 0;
            DAT_00735e84 = 0;
            CameraMover_SetTransitionParamB(0);
            CameraMover_SetTransitionParamA(0);
          }
          DAT_0078eb18 = DAT_0078eb18 + 1;
        }
      }
    }
  }
  return;
}


// ==== 0x4b0e50 GarageMainScreen::SetRideInfo

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GarageMainScreen__SetRideInfo(int param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  
  GarageCarLoader__LoadRideInfo();
  bSPrintf_regdst(0x20,"CAR_NAME_%s",*param_2 * 0xc90 + DAT_00734588);
  uVar2 = FEng__HashName();
  iVar3 = *(int *)(param_1 + 0x6c);
  if (iVar3 != 0) {
    *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | 0x400000;
    puVar1 = DAT_00735710;
    bVar4 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar3 + 0x5c) = uVar2;
    if (bVar4) {
      (**(code **)*puVar1)(iVar3);
    }
    *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) & 0xfffffffd | 0x400000;
  }
  if (DAT_00777b4c != 1) {
    if (*(int *)(param_1 + 0xc) != 0) {
      iVar3 = FUN_004f65d0();
      if (iVar3 != 0) {
        iVar3 = FUN_004ffb70();
        if (iVar3 != 0) goto LAB_004b0fa7;
      }
    }
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x13c45e);
    }
LAB_004b0fa7:
    FEObject__SetInvisible(iVar3);
    GarageMainScreen__CarLoadingHasStarted(param_1,param_2);
    return;
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    iVar3 = FUN_004f65d0();
    if (iVar3 != 0) {
      iVar3 = FUN_004ffb70();
      if (iVar3 != 0) goto LAB_004b0f12;
    }
  }
  if (DAT_0073578c == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_004ef050(0x13c45e);
  }
LAB_004b0f12:
  FEObject__SetVisible(iVar3);
  if (((DAT_0073494c != 0) || (DAT_00735ec1 != '\0')) ||
     (uVar2 = DAT_0076026c, DAT_0073440c != '\0')) {
    uVar2 = 1000000000;
  }
  FUN_004f6850("Cash: %d",uVar2);
  GarageMainScreen__CarLoadingHasStarted(param_1,param_2);
  return;
}


// ==== 0x4b0fd0 GarageMainScreen::DisplayReputation

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car low (ghidra+hopper) docs/re/tuning.md */

void GarageMainScreen__DisplayReputation(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  float10 fVar7;
  int local_a4 [10];
  int aiStack_7c [10];
  int aiStack_54 [5];
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  float local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  float local_c;
  uint local_8;
  
  iVar6 = 0;
  if (*(int *)(param_1 + 0x94) != 0) {
    return;
  }
  local_c = 0.0;
  fVar1 = *(float *)(param_1 + 0x120) + 0.032;
  local_1c = 0;
  *(float *)(param_1 + 0x120) = fVar1;
  if (DAT_00745e40 == 0) {
    local_1c = 0xffb7bf00;
    local_c = *(float *)(param_1 + 0x78);
    goto LAB_004b1083;
  }
  if (_K_ONE < fVar1) {
    uVar5 = *(int *)(param_1 + 0x11c) + 1U & 0x80000001;
    *(undefined4 *)(param_1 + 0x120) = 0;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffffe) + 1;
    }
    *(uint *)(param_1 + 0x11c) = uVar5;
  }
  if (*(int *)(param_1 + 0x11c) == 0) {
    local_c = *(float *)(param_1 + 0x78);
    local_1c = 0xffb7bf00;
LAB_004b1070:
  }
  else if (*(int *)(param_1 + 0x11c) == 1) {
    local_c = *(float *)(param_1 + 0x7c);
    local_1c = 0xfffaa21b;
    goto LAB_004b1070;
  }
  if (*(float *)(param_1 + 0x7c) == *(float *)(param_1 + 0x78)) {
    local_1c = 0xffb7bf00;
  }
LAB_004b1083:
  local_18 = 0x3fc13fbe;
  iVar3 = 0x58b092ef;
  local_14 = 0x775adf8e;
  local_8 = 5;
  do {
    if (((((*(int *)(param_1 + 0xc) == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
         (iVar2 = FUN_004ffb70(), iVar2 == 0)) &&
        ((DAT_0073578c == 0 || (iVar2 = FUN_004ef050(iVar3), iVar2 == 0)))) ||
       (*(int *)(iVar2 + 0x18) != 1)) {
      iVar2 = 0;
    }
    *(int *)((int)aiStack_54 + iVar6) = iVar2;
    iVar3 = iVar3 + 1;
    if (((((*(int *)(param_1 + 0xc) == 0) || (iVar2 = FUN_004f65d0(), iVar2 == 0)) ||
         (iVar2 = FUN_004ffb70(), iVar2 == 0)) &&
        ((DAT_0073578c == 0 || (iVar2 = FUN_004ef050(local_14), iVar2 == 0)))) ||
       (*(int *)(iVar2 + 0x18) != 2)) {
      iVar2 = 0;
    }
    *(int *)((int)aiStack_7c + iVar6) = iVar2;
    local_14 = local_14 + 1;
    iVar6 = iVar6 + 4;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  piVar4 = local_a4;
  local_8 = 10;
  do {
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004b11cb:
      if ((DAT_0073578c == 0) || (iVar6 = FUN_004ef050(local_18), iVar6 == 0)) goto LAB_004b11ec;
LAB_004b11e6:
      if (*(int *)(iVar6 + 0x18) != 1) goto LAB_004b11ec;
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_004b11b9:
        if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar6 == 0)) goto LAB_004b11cb;
        goto LAB_004b11e6;
      }
      if (DAT_0073578c != 0) {
        iVar3 = *(int *)(DAT_0073578c + 8);
        if ((iVar3 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar3 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar3 + 0xec), iVar6 == 0)))) goto LAB_004b11cb;
        goto LAB_004b11b9;
      }
LAB_004b11ec:
      iVar6 = 0;
    }
    *piVar4 = iVar6;
    local_18 = local_18 + 1;
    piVar4 = piVar4 + 1;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  local_30 = 0.0;
  param_1 = 0;
  do {
    if (local_c < _K_ONE) {
      if (0.0 < local_c) {
        local_30 = local_c;
      }
      fVar1 = 0.0;
LAB_004b1263:
      uVar5 = 0xff0080c0;
      local_14 = 0x3f400000;
    }
    else {
      fVar1 = K_BLUR_MIN_T;
      if (2.0 <= local_c) goto LAB_004b1263;
      local_14 = 0x3f666666;
      uVar5 = local_1c;
    }
    local_18 = uVar5;
    local_8 = local_1c;
    if (fVar1 == 0.0) {
      local_8 = 0xff0080c0;
    }
    local_10 = *(int *)((int)aiStack_54 + param_1);
    if (local_10 != 0) {
      local_38 = local_8 >> 0x10 & 0xff;
      local_3c = local_8 >> 8 & 0xff;
      local_40 = local_8 & 0xff;
      local_34 = local_8 >> 0x18;
      if (*(int *)(local_10 + 0x18) < 0x100) {
        piVar4 = *(int **)(local_10 + 0x2c);
        local_8 = piVar4[2];
        if (((((int)(local_38 + 1) < (int)local_8) || ((int)local_8 < (int)(local_38 - 1))) ||
            ((int)(local_3c + 1) < piVar4[1])) ||
           (((piVar4[1] < (int)(local_3c - 1) || ((int)(local_40 + 1) < *piVar4)) ||
            ((*piVar4 < (int)(local_40 - 1) ||
             (((int)(local_34 + 1) < piVar4[3] || (piVar4[3] < (int)(local_34 - 1))))))))) {
          *(uint *)(local_10 + 0x1c) = *(uint *)(local_10 + 0x1c) | 0x400000;
        }
        FUN_004ff2f0(local_10,0,0);
      }
    }
    iVar6 = *(int *)((int)aiStack_7c + param_1);
    if (iVar6 != 0) {
      local_24 = local_18 >> 0x10 & 0xff;
      local_28 = uVar5 >> 8 & 0xff;
      local_20 = uVar5 >> 0x18;
      local_2c = uVar5 & 0xff;
      if (*(int *)(iVar6 + 0x18) < 0x100) {
        piVar4 = *(int **)(iVar6 + 0x2c);
        local_10 = piVar4[2];
        if (((((int)(local_24 + 1) < local_10) || (local_10 < (int)(local_24 - 1))) ||
            ((int)(local_28 + 1) < piVar4[1])) ||
           (((piVar4[1] < (int)(local_28 - 1) || ((int)(local_2c + 1) < *piVar4)) ||
            ((*piVar4 < (int)(local_2c - 1) ||
             (((int)(local_20 + 1) < piVar4[3] || (piVar4[3] < (int)(local_20 - 1))))))))) {
          *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) | 0x400000;
        }
        FUN_004ff2f0(iVar6,0,0);
      }
    }
    iVar6 = local_14;
    local_c = local_c - _K_ONE;
    FUN_004f7430(local_14);
    FUN_004f74f0(iVar6);
    FUN_004f7430(iVar6);
    FUN_004f74f0(iVar6);
    param_1 = param_1 + 4;
    if (0x13 < param_1) {
      fVar7 = (float10)local_30;
      local_10 = 0;
      do {
        param_1._2_1_ = 0;
        local_20 = 0xff0080c0;
        if ((float10)0.15 <= fVar7) {
          param_1._2_1_ = (byte)(local_1c >> 0x10);
          local_20 = local_1c;
        }
        iVar6 = local_a4[local_10];
        if (iVar6 != 0) {
          local_24 = (uint)param_1._2_1_;
          local_28 = local_20 >> 8 & 0xff;
          local_2c = local_20 & 0xff;
          local_20 = local_20 >> 0x18;
          if (*(int *)(iVar6 + 0x18) < 0x100) {
            piVar4 = *(int **)(iVar6 + 0x2c);
            if ((((((int)(local_24 + 1) < piVar4[2]) || (piVar4[2] < (int)(local_24 - 1))) ||
                 ((int)(local_28 + 1) < piVar4[1])) ||
                ((piVar4[1] < (int)(local_28 - 1) || ((int)(local_2c + 1) < *piVar4)))) ||
               ((*piVar4 < (int)(local_2c - 1) ||
                (((int)(local_20 + 1) < piVar4[3] || (piVar4[3] < (int)(local_20 - 1))))))) {
              *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) | 0x400000;
            }
            fVar7 = (float10)FUN_004ff2f0(iVar6,0,0);
          }
        }
        fVar7 = fVar7 - (float10)0.1;
        local_10 = local_10 + 1;
      } while (local_10 < 10);
      return;
    }
  } while( true );
}


