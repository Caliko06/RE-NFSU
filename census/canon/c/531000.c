// ==== 0x531030 FUN_00531030

void __fastcall FUN_00531030(int param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x351) == '\0') {
    *(undefined4 *)(*(int *)(param_1 + 0x2fc) + 0x10) =
         *(undefined4 *)(*(int *)(param_1 + 0x21c) + 0x40);
    EAX_linear_ramp_evaluate__not_SetCsisName_();
    if (*(char *)(*(int *)(param_1 + 0x2fc) + 0x18) != '\0') {
      EAX_linear_ramp_evaluate__not_SetCsisName_();
    }
    uVar1 = _ftol_nocw();
    *(undefined4 *)(param_1 + 0x24c) = uVar1;
  }
  return;
}


// ==== 0x531080 stSoundCollision::BeginScrape

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void stSoundCollision__BeginScrape(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *unaff_EDI;
  
  stSoundCollision__CalcCollisionPositionData();
  (**(code **)(*unaff_EDI + 0x34))();
  unaff_EDI[0x91] = DAT_006f4f28;
  (**(code **)(*unaff_EDI + 0x40))();
  iVar1 = unaff_EDI[0x91];
  stSoundCollision__AdjustVolume();
  iVar2 = unaff_EDI[0x13];
  FUN_00584310((float)iVar2);
  iVar3 = unaff_EDI[0xcf];
  if (iVar3 == 0) {
    PTR_s_CSISSOUND_006f8714 = s_SND_WORLDScrape_006be774;
  }
  else {
    if (iVar3 == 1) {
      return;
    }
    if (iVar3 == 2) {
      PTR_s_CSISSOUND_006f8714 = s_SND_SmokeableScrape_006be784;
    }
  }
  _DAT_00706fd4 = unaff_EDI[0xd2];
  unaff_EDI[0xc2] = iVar1;
  unaff_EDI[0xc4] = iVar2;
  unaff_EDI[0xc6] = 0x1000;
  unaff_EDI[200] = unaff_EDI[0x93];
  (**(code **)(*unaff_EDI + 0x68))();
  *(undefined1 *)(unaff_EDI + 0xd4) = 1;
  *(undefined1 *)(unaff_EDI + 0xbd) = 0;
  *(undefined1 *)((int)unaff_EDI + 0x351) = 0;
  return;
}


// ==== 0x531150 FUN_00531150

void __fastcall FUN_00531150(int param_1)

{
  *(undefined1 *)(param_1 + 0x219) = 1;
  return;
}


// ==== 0x531160 FUN_00531160

bool __fastcall FUN_00531160(int param_1)

{
  return *(char *)(param_1 + 0x219) == '\0';
}


// ==== 0x531170 FUN_00531170

int __fastcall FUN_00531170(int param_1)

{
  float fVar1;
  float fVar2;
  uint3 uVar3;
  
  fVar1 = *(float *)(*(int *)(param_1 + 0x21c) + 0x40);
  fVar2 = *(float *)(*(int *)(param_1 + 0x2fc) + 8);
  uVar3 = (uint3)(CONCAT22((short)((uint)*(int *)(param_1 + 0x21c) >> 0x10),
                           (ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                           (ushort)(fVar1 == fVar2) << 0xe) >> 8);
  if (fVar1 < fVar2) {
    return (uint)uVar3 << 8;
  }
  return CONCAT31(uVar3,1);
}


// ==== 0x531190 FUN_00531190

uint __fastcall FUN_00531190(int param_1)

{
  float fVar1;
  uint in_EAX;
  
  if (((*(byte *)(param_1 + 0x344) & 1) != 0) && (in_EAX = 0, *(int *)(param_1 + 0x32c) != 0)) {
    fVar1 = *(float *)(param_1 + 0x330);
    in_EAX = CONCAT22((short)((uint)*(int *)(param_1 + 0x32c) >> 0x10),
                      (ushort)(fVar1 < 80.0) << 8 | (ushort)NAN(fVar1) << 10 |
                      (ushort)(fVar1 == 80.0) << 0xe);
    if (fVar1 >= 80.0) {
      return CONCAT31((int3)(in_EAX >> 8),0x77 < *(int *)(param_1 + 0x248));
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== 0x5311d0 stSoundCollision::BeginMixerEnvelope

/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall stSoundCollision__BeginMixerEnvelope(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 auStack_6c [11];
  int iStack_40;
  undefined4 auStack_2c [9];
  undefined4 uStack_8;
  
  uVar2 = DAT_007356ac;
  if (((*(int *)(param_1 + 0x32c) != 0) &&
      (iVar1 = *(int *)(*(int *)(param_1 + 0x32c) + 0x878), iVar1 != 0)) &&
     (iVar1 = *(int *)(iVar1 + 0x264), iVar1 < 4)) {
    auStack_2c[2] = 0;
    auStack_2c[1] = 0;
    puVar4 = &DAT_00736650;
    puVar5 = auStack_2c + 3;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    uStack_8 = 0x420c0000;
    auStack_2c[0] = 7;
    puVar4 = auStack_2c;
    puVar5 = auStack_6c;
    iStack_40 = iVar1;
    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    EAXMixMgr__ReceiveTrigger(DAT_007356ac);
    auStack_2c[2] = 0;
    auStack_2c[1] = 0;
    puVar4 = &DAT_00736670;
    puVar5 = auStack_2c + 3;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    uStack_8 = 0xc2480000;
    auStack_2c[0] = 1;
    puVar4 = auStack_2c;
    puVar5 = auStack_6c;
    iStack_40 = iVar1;
    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    EAXMixMgr__ReceiveTrigger(uVar2);
    auStack_2c[0] = 2;
    puVar4 = auStack_2c;
    puVar5 = auStack_6c;
    iStack_40 = iVar1;
    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    EAXMixMgr__ReceiveTrigger(uVar2);
    auStack_2c[0] = 3;
    puVar4 = auStack_2c;
    puVar5 = auStack_6c;
    iStack_40 = iVar1;
    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    EAXMixMgr__ReceiveTrigger(uVar2);
    auStack_2c[0] = 4;
    puVar4 = auStack_2c;
    puVar5 = auStack_6c;
    iStack_40 = iVar1;
    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    EAXMixMgr__ReceiveTrigger(uVar2);
    auStack_2c[0] = 5;
    puVar4 = auStack_2c;
    puVar5 = auStack_6c;
    iStack_40 = iVar1;
    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    EAXMixMgr__ReceiveTrigger(uVar2);
    auStack_2c[0] = 6;
    puVar4 = auStack_2c;
    puVar5 = auStack_6c;
    iStack_40 = iVar1;
    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    EAXMixMgr__ReceiveTrigger(uVar2);
    auStack_2c[0] = 8;
    puVar4 = auStack_2c;
    puVar5 = auStack_6c;
    iStack_40 = iVar1;
    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    EAXMixMgr__ReceiveTrigger(uVar2);
  }
  return;
}


// ==== 0x531350 stSoundCollision::BeginImpact

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall stSoundCollision__BeginImpact(int *param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  
  stSoundCollision__CalcCollisionPositionData();
  (**(code **)(*param_1 + 0x3c))();
  cVar3 = (**(code **)(*param_1 + 0x54))();
  if (cVar3 != '\0') {
    (**(code **)(*param_1 + 0x58))();
  }
  iVar4 = (**(code **)(*param_1 + 0x30))();
  stSoundCollision__AdjustVolume();
  iVar1 = *(int *)(DAT_007356ac + 0x3e1c);
  iVar2 = param_1[0xcf];
  if (-1 < iVar2) {
    if (iVar2 < 2) {
      PTR_s_CSISSOUND_006f8714 = s_SND_WORLDImpact_006be750;
    }
    else if (iVar2 == 2) {
      PTR_s_CSISSOUND_006f8714 = s_SND_SmokeableImpact_006be760;
    }
  }
  param_1[0xc3] = param_1[0x13];
  param_1[199] = param_1[0x92];
  param_1[0xc1] = iVar1 * iVar4 >> 0xf;
  param_1[0xc5] = 0x1000;
  (**(code **)(*param_1 + 100))();
  iVar1 = param_1[0x87];
  *(undefined1 *)((int)param_1 + 0x34e) = 1;
  *(undefined1 *)((int)param_1 + 0x351) = 0;
  *(undefined1 *)((int)param_1 + 0x34f) = 1;
  _DAT_00736734 = *(undefined4 *)(iVar1 + 0x74);
  _DAT_00736730 = *(undefined4 *)(iVar1 + 0x70);
  _DAT_00736738 = *(undefined4 *)(iVar1 + 0x78);
  iVar1 = param_1[0x87];
  _DAT_00736740 = *(undefined4 *)(iVar1 + 0x30);
  _DAT_00736744 = *(undefined4 *)(iVar1 + 0x34);
  _DAT_00736748 = *(undefined4 *)(iVar1 + 0x38);
  return;
}


// ==== 0x531460 FUN_00531460

void __fastcall FUN_00531460(int param_1)

{
  *(undefined4 *)(param_1 + 0x334) = 0;
  return;
}


// ==== 0x531470 FUN_00531470

int __fastcall FUN_00531470(int param_1)

{
  *(undefined4 *)(param_1 + 0x338) = 0;
  return *(int *)(param_1 + 0x33c) + -2;
}


// ==== 0x531490 FUN_00531490

int FUN_00531490(void)

{
  int iVar1;
  int extraout_ECX;
  
  iVar1 = FUN_0052f5c0();
  return iVar1 * *(int *)(extraout_ECX + 0x240) >> 0xf;
}


// ==== 0x5314b0 FUN_005314b0

void FUN_005314b0(void)

{
  undefined4 uVar1;
  int extraout_ECX;
  
  uVar1 = FUN_0052f7b0();
  *(undefined4 *)(extraout_ECX + 0x334) = uVar1;
  return;
}


// ==== 0x5314d0 EAXS_3DMixer::IsThisObjectIntheLead__default_returns_0_

/* [canon] audio med (ghidra) docs/re/sound.md */

undefined1 EAXS_3DMixer__IsThisObjectIntheLead__default_returns_0_(void)

{
  return 0;
}


// ==== 0x5314e0 FUN_005314e0

undefined1 __fastcall FUN_005314e0(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if (((*(byte *)(param_1 + 0x344) & 1) == 0) && (*(int *)(param_1 + 0x248) < 10)) {
    return 0;
  }
  iVar5 = *(int *)(*(int *)(DAT_007356a8 + 0x80) + 0x24);
  if (iVar5 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = iVar5 + -0x210;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x21c) + 100);
  uVar3 = *(uint *)(iVar1 + 600);
  if (*(char *)(uVar3 + 0x15) != '\x01') {
    uVar3 = *(uint *)(iVar1 + 0x25c);
    uVar3 = (*(char *)(uVar3 + 0x15) != '\x01') - 1 & uVar3;
  }
  if (iVar2 != 0) {
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = iVar5 + -0x210;
    }
    iVar2 = FUN_005325f0();
    while (iVar5 != iVar2) {
      if (*(int *)(iVar5 + 0x21c) != 0) {
        iVar1 = *(int *)(*(int *)(iVar5 + 0x21c) + 100);
        uVar4 = *(uint *)(iVar1 + 600);
        if ((*(char *)(uVar4 + 0x15) != '\x01') &&
           (uVar4 = *(uint *)(iVar1 + 0x25c), *(char *)(uVar4 + 0x15) != '\x01')) {
          return 1;
        }
        if (uVar4 == 0) {
          return 1;
        }
        if ((uVar4 == uVar3) && (*(char *)(iVar5 + 0x34e) != '\0')) {
          return 0;
        }
      }
      if (*(int *)(iVar5 + 0x210) == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(iVar5 + 0x210) + -0x210;
      }
    }
  }
  return 1;
}


// ==== 0x5315d0 FUN_005315d0

void FUN_005315d0(void)

{
  undefined4 uVar1;
  int extraout_ECX;
  
  uVar1 = FUN_0052f750();
  *(undefined4 *)(extraout_ECX + 0x338) = uVar1;
  return;
}


// ==== 0x5315f0 FUN_005315f0

void __thiscall FUN_005315f0(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  FUN_00530840(param_2);
  *(undefined **)(param_1 + 0x2f8) = &DAT_0073676c;
  *(undefined **)(param_1 + 0x2fc) = &DAT_00736788;
  iVar1 = *(int *)(*(int *)(param_1 + 0x21c) + 100);
  uVar2 = *(uint *)(iVar1 + 600);
  if (*(char *)(uVar2 + 0x15) != '\x01') {
    uVar2 = *(uint *)(iVar1 + 0x25c);
    uVar2 = uVar2 & (*(char *)(uVar2 + 0x15) != '\x01') - 1;
  }
  *(uint *)(param_1 + 0x364) = uVar2;
  iVar1 = *(int *)(uVar2 + 0x158);
  *(int *)(param_1 + 0x368) = iVar1;
  *(undefined4 *)(param_1 + 0x360) = *(undefined4 *)(iVar1 + 0xd8);
  return;
}


// ==== 0x531670 FUN_00531670

void __fastcall FUN_00531670(int param_1)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  float10 fVar9;
  float afStack_1c [4];
  float fStack_c;
  float fStack_8;
  char cStack_4;
  
  fVar1 = *(float *)(*(int *)(param_1 + 0x21c) + 0x60);
  iVar2 = *(int *)(*(int *)(param_1 + 0x21c) + 100);
  piVar5 = *(int **)(iVar2 + 600);
  if (*(char *)((int)piVar5 + 0x15) != '\x01') {
    uVar3 = *(uint *)(iVar2 + 0x25c);
    piVar5 = (int *)((*(char *)(uVar3 + 0x15) != '\x01') - 1 & uVar3);
  }
  fVar9 = (float10)(**(code **)(*piVar5 + 0x58))();
  iVar2 = *(int *)(param_1 + 0x340);
  pfVar7 = *(float **)(param_1 + 0x2f8);
  pfVar8 = afStack_1c;
  for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
    *pfVar8 = *pfVar7;
    pfVar7 = pfVar7 + 1;
    pfVar8 = pfVar8 + 1;
  }
  afStack_1c[3] = afStack_1c[3] * *(float *)(&DAT_006b6450 + iVar2 * 4);
  if (ABS(afStack_1c[3] - afStack_1c[2]) < 1e-06) {
    afStack_1c[3] = afStack_1c[3] + 1e-06;
  }
  fStack_c = (float)(fVar9 * (float10)fVar1);
  fStack_8 = afStack_1c[0];
  EAX_linear_ramp_evaluate__not_SetCsisName_();
  if (cStack_4 != '\0') {
    EAX_linear_ramp_evaluate__not_SetCsisName_();
  }
  uVar4 = _ftol_nocw();
  *(undefined4 *)(param_1 + 0x248) = uVar4;
  return;
}


// ==== 0x531750 FUN_00531750

undefined4 FUN_00531750(void)

{
  return 7;
}


// ==== 0x531760 FUN_00531760

void __fastcall FUN_00531760(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  local_c = ExceptionList;
  if ((param_1[0xc9] == 0) && (DAT_006f1dd8 != 0)) {
    ExceptionList = &local_c;
    local_10 = param_1;
    Csis__System__GetAllocator(&local_10);
    Mutex__Lock();
    puVar1 = (undefined4 *)(**(code **)*local_10)(0x18,4,0xffffffff);
    Mutex__Unlock();
    uStack_4 = 0;
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = 0;
    }
    else {
      local_10 = puVar1;
      uVar2 = FUN_0052f2c0(param_1[199]);
    }
    param_1[0xc9] = uVar2;
    DAT_00735624 = DAT_00735624 + 1;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x531810 FUN_00531810

void __fastcall FUN_00531810(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  local_c = ExceptionList;
  if ((param_1[0xca] == 0) && (DAT_006f1dd8 != 0)) {
    ExceptionList = &local_c;
    local_10 = param_1;
    Csis__System__GetAllocator(&local_10);
    Mutex__Lock();
    puVar1 = (undefined4 *)(**(code **)*local_10)(0x18,4,0xffffffff);
    Mutex__Unlock();
    uStack_4 = 0;
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = 0;
    }
    else {
      local_10 = puVar1;
      uVar2 = FUN_0052f440(param_1[200]);
    }
    param_1[0xca] = uVar2;
    DAT_00735620 = DAT_00735620 + 1;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x5318c0 FUN_005318c0

void __fastcall FUN_005318c0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x324);
  if (piVar1 != (int *)0x0) {
    iVar2 = *(int *)(param_1 + 0x30c);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0xffff < iVar2) {
      iVar2 = 0xffff;
    }
    piVar1[3] = iVar2;
    iVar2 = *(int *)(param_1 + 0x31c);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x7f < iVar2) {
      iVar2 = 0x7f;
    }
    piVar1[5] = iVar2;
    iVar2 = *(int *)(param_1 + 0x304);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x7fff < iVar2) {
      iVar2 = 0x7fff;
    }
    piVar1[1] = iVar2;
    if (*piVar1 != 0) {
      FUN_0064bc30(piVar1 + 1);
    }
  }
  return;
}


// ==== 0x531930 FUN_00531930

void __fastcall FUN_00531930(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x328);
  if (piVar1 != (int *)0x0) {
    iVar2 = *(int *)(param_1 + 0x310);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0xffff < iVar2) {
      iVar2 = 0xffff;
    }
    piVar1[3] = iVar2;
    iVar2 = *(int *)(param_1 + 800);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x7f < iVar2) {
      iVar2 = 0x7f;
    }
    piVar1[5] = iVar2;
    iVar2 = *(int *)(param_1 + 0x308);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x7fff < iVar2) {
      iVar2 = 0x7fff;
    }
    piVar1[1] = iVar2;
    if (*piVar1 != 0) {
      FUN_0064bc30(piVar1 + 1);
    }
  }
  return;
}


// ==== 0x5319a0 FUN_005319a0

undefined4 __fastcall FUN_005319a0(int param_1)

{
  int iStack_4;
  
  if (*(int **)(param_1 + 0x324) == (int *)0x0) {
    return 0;
  }
  iStack_4 = 0;
  if ((**(int **)(param_1 + 0x324) != 0) && (Csis__Class__GetRefCount(&iStack_4), iStack_4 == 1)) {
    return 0;
  }
  return 1;
}


// ==== 0x5319e0 FUN_005319e0

undefined4 __fastcall FUN_005319e0(int param_1)

{
  int iStack_4;
  
  if (*(int **)(param_1 + 0x328) == (int *)0x0) {
    return 0;
  }
  iStack_4 = 0;
  if ((**(int **)(param_1 + 0x328) != 0) && (Csis__Class__GetRefCount(&iStack_4), iStack_4 == 1)) {
    return 0;
  }
  return 1;
}


// ==== 0x531a20 FUN_00531a20

void __fastcall FUN_00531a20(int *param_1)

{
  int *piVar1;
  int *local_4;
  
  piVar1 = (int *)param_1[0xca];
  if (piVar1 != (int *)0x0) {
    local_4 = param_1;
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_4);
    Mutex__Lock();
    (**(code **)(*local_4 + 4))(piVar1);
    Mutex__Unlock();
    DAT_00735620 = DAT_00735620 + -1;
    param_1[0xca] = 0;
  }
  return;
}


// ==== 0x531a80 FUN_00531a80

uint __fastcall FUN_00531a80(int *param_1)

{
  float fVar1;
  uint in_EAX;
  int iVar2;
  
  if (((*(byte *)(param_1 + 0xd1) & 1) != 0) && (in_EAX = 0, param_1[0xcb] != 0)) {
    fVar1 = (float)param_1[0xcc];
    in_EAX = CONCAT22((short)((uint)param_1[0xcb] >> 0x10),
                      (ushort)(fVar1 < 80.0) << 8 | (ushort)NAN(fVar1) << 10 |
                      (ushort)(fVar1 == 80.0) << 0xe);
    if ((fVar1 >= 80.0) && (0x77 < param_1[0x92])) {
      iVar2 = (**(code **)(*param_1 + 0x60))();
      return CONCAT31((int3)((uint)-iVar2 >> 8),'\x01' - (iVar2 != 0));
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== 0x531ac0 FUN_00531ac0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00531ac0(int param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  
  if ((*(int *)(param_1 + 0x360) != 0) && (iVar2 = *(int *)(param_1 + 0x364), iVar2 != 0)) {
    bNormalize3();
    bNormalize3();
    if (K_BLUR_S_MUL < ABS(local_38 * local_38 + local_40 * local_40 + local_3c * local_3c)) {
      FUN_004655b0();
      FUN_004655b0();
      fVar1 = *(float *)(*(int *)(param_1 + 0x360) + 100);
      fVar3 = *(float *)(param_1 + 0x228) - *(float *)(iVar2 + 0x68);
      bNormalize3();
      bNormalize3();
      if ((ABS(local_30 * local_40 + local_2c * fVar1 + local_28 * fVar3) <= 0.8) ||
         (ABS(local_20 * local_40 + local_1c * fVar1 + local_38 * fVar3) <= 0.8)) {
        return 1;
      }
    }
  }
  return 0;
}


// ==== 0x531d10 FUN_00531d10

void __fastcall FUN_00531d10(int param_1)

{
  if (*(int *)(param_1 + 0x340) == 0) {
    DAT_0078eaac = DAT_0078eaac + 1;
    if (2 < DAT_0078eaac) {
      DAT_0078eaac = 0;
    }
    *(int *)(param_1 + 0x334) = DAT_0078eaac + 9;
    return;
  }
  if (*(int *)(param_1 + 0x340) == 1) {
    DAT_0078eaa8 = DAT_0078eaa8 + 1;
    if (3 < DAT_0078eaa8) {
      DAT_0078eaa8 = 0;
    }
    *(int *)(param_1 + 0x334) = DAT_0078eaa8 + 5;
    return;
  }
  *(undefined4 *)(param_1 + 0x334) = 0;
  return;
}


// ==== 0x531d70 FUN_00531d70

void __thiscall FUN_00531d70(int param_1,int param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x360) = 0;
  *(undefined4 *)(param_1 + 0x364) = 0;
  iVar1 = *(int *)(*(int *)(param_2 + 100) + 600);
  if (*(char *)(iVar1 + 0x15) == '\0') {
    *(undefined4 *)(param_1 + 0x360) = *(undefined4 *)(iVar1 + 0x140);
  }
  iVar1 = *(int *)(*(int *)(param_2 + 100) + 0x25c);
  if (*(char *)(iVar1 + 0x15) == '\0') {
    *(undefined4 *)(param_1 + 0x364) = *(undefined4 *)(iVar1 + 0x140);
  }
  FUN_00530840(param_2);
  *(undefined **)(param_1 + 0x2f8) = &DAT_007367dc;
  return;
}


// ==== 0x531dd0 FUN_00531dd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00531dd0(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  float local_20;
  float local_1c;
  float local_18;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x21c) + 100);
  iVar4 = *(int *)(iVar3 + 600);
  iVar7 = 0;
  iVar8 = 0;
  if (*(char *)(iVar4 + 0x15) == '\0') {
    iVar8 = *(int *)(iVar4 + 0x140);
  }
  iVar3 = *(int *)(iVar3 + 0x25c);
  if (*(char *)(iVar3 + 0x15) == '\0') {
    iVar7 = *(int *)(iVar3 + 0x140);
  }
  if ((iVar8 != 0) || (iVar8 = iVar7, iVar7 != 0)) {
    fVar1 = *(float *)(iVar8 + 0xb4);
    fVar5 = *(float *)(iVar8 + 0xb0);
    fVar2 = *(float *)(iVar8 + 0xb8);
    bNormalize3();
    if (ABS((local_1c + local_20) * 0.0 + local_18) <= K_BLUR_S_MUL) {
      uVar6 = 4;
      if (ABS(*(float *)(iVar8 + 0x90) * *(float *)(param_1 + 0x230) +
              *(float *)(iVar8 + 0x94) * *(float *)(param_1 + 0x234) +
              *(float *)(iVar8 + 0x98) * *(float *)(param_1 + 0x238)) <= 0.707) {
        uVar6 = 5;
      }
      return uVar6;
    }
    fVar1 = fVar1 * 0.0;
    fVar5 = fVar5 * 0.0;
    if (-0.1 < (fVar5 - fVar2 * _K_ONE) + fVar1) {
      return 2;
    }
    if (K_BLUR_S_MUL < fVar5 + fVar1 + fVar2) {
      return 3;
    }
  }
  return 4;
}


// ==== 0x531f50 thunk_FUN_00530840

void thunk_FUN_00530840(void)

{
  FUN_00530840();
  return;
}


// ==== 0x531f60 FUN_00531f60

void __fastcall FUN_00531f60(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  switch(*(undefined4 *)(param_1 + 0x340)) {
  case 2:
  case 5:
  case 6:
    DAT_0078eaa0 = DAT_0078eaa0 + 1;
    if (3 < DAT_0078eaa0) {
      DAT_0078eaa0 = 0;
    }
    *(int *)(param_1 + 0x334) = DAT_0078eaa0 + 5;
    return;
  case 3:
    iVar1 = DAT_0078eaa4 + 1;
    DAT_0078eaa4 = iVar1;
    if (2 < iVar1) {
      DAT_0078eaa4 = 0;
      *(undefined4 *)(param_1 + 0x334) = 0;
      return;
    }
    break;
  case 4:
    DAT_0078ea9c = DAT_0078ea9c + 1;
    if (2 < DAT_0078ea9c) {
      DAT_0078ea9c = 0;
    }
    iVar1 = DAT_0078ea9c + 9;
  }
  *(int *)(param_1 + 0x334) = iVar1;
  return;
}


// ==== 0x531ff0 FUN_00531ff0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00531ff0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float10 fVar8;
  int local_48;
  float local_20;
  float local_1c;
  float local_18;
  
  if (*(char *)(param_1 + 0x219) != '\0') {
    return 0;
  }
  piVar3 = (int *)(*(int *)(DAT_007356a8 + 0x80) + 0x24);
  if (piVar3 != (int *)0x0) {
    iVar6 = *piVar3;
    if (iVar6 == 0) {
      local_48 = 0;
    }
    else {
      local_48 = iVar6 + -0x210;
    }
    iVar1 = *(int *)(param_1 + 0x32c);
    if (iVar1 != 0) {
      bNormalize3();
      iVar2 = *(int *)(param_1 + 0x21c);
      FUN_004655b0();
      if ((0.95 < local_20 * local_20 + local_1c * local_1c + local_18 * local_18) &&
         (pfVar4 = (float *)Vec3_ScaleTo(0x3f733333),
         SQRT(pfVar4[2] * pfVar4[2] + pfVar4[1] * pfVar4[1] + *pfVar4 * *pfVar4) <
         SQRT(_DAT_00736730 * _DAT_00736730 +
              _DAT_00736734 * _DAT_00736734 + _DAT_00736738 * _DAT_00736738))) {
        fVar7 = (float10)bLength3();
        Vec3_ScaleTo(0x3f866666);
        fVar8 = (float10)bLength3();
        if (((float10)(float)fVar7 < fVar8) &&
           ((fVar7 = (float10)bDistance3(), fVar7 < (float10)_K_ONE &&
            (K_BLUR_S_MUL < ABS(*(float *)(iVar2 + 0x78)))))) {
          return 0;
        }
      }
      if (local_48 != 0) {
        if (iVar6 == 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = iVar6 + -0x210;
        }
        iVar5 = FUN_005325f0();
        while (iVar6 != iVar5) {
          if ((((*(char *)(iVar6 + 0x218) != '\0') && (*(int *)(iVar6 + 0x340) == 5)) &&
              (*(int *)(iVar6 + 0x32c) != 0)) && (*(int *)(iVar6 + 0x32c) == iVar1)) {
            if (iVar6 == param_1) {
              if (*(char *)(iVar6 + 0x34f) != '\0') {
                return 0;
              }
            }
            else if (0.8 < ABS(*(float *)(iVar2 + 0x70) * *(float *)(iVar6 + 0x230) +
                               *(float *)(iVar2 + 0x74) * *(float *)(iVar6 + 0x234) +
                               *(float *)(iVar2 + 0x78) * *(float *)(iVar6 + 0x238))) {
              return 0;
            }
          }
          if (*(int *)(iVar6 + 0x210) == 0) {
            iVar6 = 0;
          }
          else {
            iVar6 = *(int *)(iVar6 + 0x210) + -0x210;
          }
        }
      }
    }
  }
  return 1;
}


// ==== 0x532270 FUN_00532270

bool __fastcall FUN_00532270(int *param_1)

{
  int iVar1;
  
  if (((*(byte *)(param_1 + 0xd1) & 1) != 0) && (param_1[0xcb] != 0)) {
    if ((80.0 <= (float)param_1[0xcc]) && (0x77 < param_1[0x92])) {
      iVar1 = (**(code **)(*param_1 + 0x60))();
      return iVar1 == 4;
    }
  }
  return false;
}


// ==== 0x5322b0 FUN_005322b0

void __fastcall FUN_005322b0(int param_1)

{
  int *piVar1;
  int *piStack_4;
  
  if (*(int **)(param_1 + 0x36c) != (int *)0x0) {
    piStack_4 = (int *)0x0;
    if (**(int **)(param_1 + 0x36c) != 0) {
      Csis__Class__GetRefCount(&piStack_4);
      if (piStack_4 == (int *)0x1) {
        piVar1 = *(int **)(param_1 + 0x36c);
        if (piVar1 != (int *)0x0) {
          if (*piVar1 != 0) {
            FUN_0064bbd0();
          }
          Csis__System__GetAllocator(&piStack_4);
          Mutex__Lock();
          (**(code **)(*piStack_4 + 4))(piVar1);
          Mutex__Unlock();
        }
        *(undefined4 *)(param_1 + 0x36c) = 0;
        return;
      }
    }
    piStack_4 = DAT_006f4f2c;
    stSoundCollision__AdjustVolume();
    if ((int)piStack_4 < 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x36c) + 8) = 0;
      return;
    }
    if (0x7fff < (int)piStack_4) {
      piStack_4 = (int *)0x7fff;
    }
    *(int **)(*(int *)(param_1 + 0x36c) + 8) = piStack_4;
  }
  return;
}


// ==== 0x532370 FUN_00532370

void FUN_00532370(void)

{
  undefined4 *in_EAX;
  
  FUN_00530570();
  *in_EAX = &PTR_FUN_006be6c8;
  in_EAX[0xdb] = 0;
  return;
}


// ==== 0x532390 FUN_00532390

void * __thiscall FUN_00532390(void *param_1,byte param_2)

{
  FUN_005323b0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5323b0 FUN_005323b0

void __fastcall FUN_005323b0(undefined4 *param_1)

{
  int *piVar1;
  int *local_14;
  undefined4 *local_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006852e8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006be6c8;
  piVar1 = (int *)param_1[0xdb];
  local_4 = 0;
  local_10 = param_1;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_14);
    Mutex__Lock();
    (**(code **)(*local_14 + 4))(piVar1);
    Mutex__Unlock();
  }
  param_1[0xdb] = 0;
  local_4 = 0xffffffff;
  FUN_005306a0();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x532440 FUN_00532440

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00532440(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iStack_14;
  int *piStack_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  stSoundCollision__BeginImpact();
  if (((*(int *)(param_1 + 0x360) == 5) &&
      (iVar4 = *(int *)(param_1 + 0x364), *(char *)(iVar4 + 0x4c0) != '\0')) &&
     (*(char *)(iVar4 + 0x4c8) == '\0')) {
    *(undefined1 *)(iVar4 + 0x4c8) = 1;
    iVar4 = DAT_006f4f2c;
    iStack_14 = DAT_006f4f2c;
    if ((*(byte *)(param_1 + 0x344) & 0x10) != 0) {
      _DAT_00736760 = *(undefined4 *)(param_1 + 0x330);
      EAX_linear_ramp_evaluate__not_SetCsisName_();
      iVar2 = _ftol_nocw();
      iStack_14 = iVar2 * iVar4 >> 0xf;
    }
    stSoundCollision__AdjustVolume();
    piVar3 = *(int **)(param_1 + 0x36c);
    if (piVar3 != (int *)0x0) {
      if (*piVar3 != 0) {
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&piStack_10);
      Mutex__Lock();
      (**(code **)(*piStack_10 + 4))(piVar3);
      Mutex__Unlock();
    }
    *(undefined4 *)(param_1 + 0x36c) = 0;
    piVar3 = (int *)FUN_005256f0(0x1c);
    uStack_4 = 0;
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      iVar4 = *(int *)(param_1 + 0x4c);
      piVar1 = piVar3 + 1;
      *piVar1 = 3;
      if (iStack_14 < 0) {
        iStack_14 = 0;
      }
      else if (0x7fff < iStack_14) {
        iStack_14 = 0x7fff;
      }
      piVar3[2] = iStack_14;
      piVar3[3] = 0x1000;
      if (iVar4 < 0) {
        iVar4 = 0;
      }
      else if (0xffff < iVar4) {
        iVar4 = 0xffff;
      }
      piVar3[4] = iVar4;
      piVar3[5] = 1;
      piVar3[6] = 0;
      piStack_10 = piVar3;
      iVar4 = Csis__Class__CreateInstance(&DAT_00744230,piVar1,piVar3);
      if (iVar4 < 0) {
        Csis__ClassHandle__Set(&PTR_s_FX_ROADNOISE_006f81b8);
        Csis__Class__CreateInstance(&DAT_00744230,piVar1,piVar3);
      }
    }
    *(int **)(param_1 + 0x36c) = piVar3;
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x5325f0 FUN_005325f0

int FUN_005325f0(void)

{
  int in_EAX;
  
  if (in_EAX != 0) {
    return in_EAX + -0x210;
  }
  return 0;
}


// ==== 0x532600 FUN_00532600

int FUN_00532600(void)

{
  int extraout_EDX;
  
  FUN_00532640();
  *(undefined1 *)(extraout_EDX + 0x78) = 1;
  return extraout_EDX;
}


// ==== 0x532610 FUN_00532610

void FUN_00532610(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int unaff_ESI;
  
  FUN_00532640();
  FUN_00532670(param_1,param_2,param_3,0);
  *(undefined4 *)(unaff_ESI + 0x74) = param_1;
  return;
}


// ==== 0x532640 FUN_00532640

void __fastcall FUN_00532640(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  param_2[0x1d] = 0;
  *param_2 = 0;
  param_2[0x1c] = 0;
  param_2[0x1b] = 0;
  iVar2 = 0;
  puVar1 = param_2 + 0xd;
  do {
    puVar1[-6] = 0;
    *puVar1 = 0;
    puVar1[-0xc] = 0;
    *(undefined1 *)((int)param_2 + iVar2 + 0x4c) = 0;
    puVar1[8] = 0;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (iVar2 < 6);
  *(undefined1 *)(param_2 + 0x1e) = 0;
  return;
}


// ==== 0x532670 FUN_00532670

int __thiscall
FUN_00532670(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  float fVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x6c) == 5) {
    return -1;
  }
  *(float *)(param_1 + 4 + *(int *)(param_1 + 0x6c) * 4) = (float)param_4 * 0.001;
  fVar1 = *(float *)(param_1 + 4 + *(int *)(param_1 + 0x6c) * 4);
  if (fVar1 < 0.0 != (fVar1 == 0.0)) {
    *(undefined4 *)(param_1 + 4 + *(int *)(param_1 + 0x6c) * 4) = 0x3c23d70a;
  }
  *(undefined4 *)(param_1 + 0x34 + *(int *)(param_1 + 0x6c) * 4) = param_3;
  *(undefined4 *)(param_1 + 0x1c + *(int *)(param_1 + 0x6c) * 4) = param_2;
  *(undefined4 *)(param_1 + 0x54 + *(int *)(param_1 + 0x6c) * 4) = param_5;
  *(undefined1 *)(param_1 + 0x4c + *(int *)(param_1 + 0x6c)) = 0;
  *(undefined1 *)(param_1 + 0x78) = 0;
  if (*(int *)(param_1 + 0x6c) == 0) {
    *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x1c);
  }
  iVar2 = *(int *)(param_1 + 0x6c) + 1;
  *(int *)(param_1 + 0x6c) = iVar2;
  return iVar2;
}


// ==== 0x5326f0 FUN_005326f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005326f0(float *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  
  if ((*(char *)(param_1 + 0x1e) == '\0') && (param_1[0x1b] != 0.0)) {
    fVar2 = param_1[0x1c];
    param_2 = param_2 + *param_1;
    *param_1 = param_2;
    if (param_2 <= param_1[(int)fVar2 + 1]) {
      fVar1 = param_1[(int)fVar2 + 0x15];
      if (fVar1 != 1.4013e-45) {
        if (fVar1 != 2.8026e-45) {
          if (fVar1 == 4.2039e-45) {
            fVar1 = (_K_ONE / param_1[(int)fVar2 + 1]) * param_2 - _K_ONE;
            param_1[0x1d] =
                 (param_1[(int)fVar2 + 0xd] - param_1[(int)fVar2 + 7]) * (_K_ONE - fVar1 * fVar1) +
                 param_1[(int)fVar2 + 7];
            return;
          }
          param_1[0x1d] =
               (param_2 / param_1[(int)fVar2 + 1]) *
               (param_1[(int)fVar2 + 0xd] - param_1[(int)fVar2 + 7]) + param_1[(int)fVar2 + 7];
          return;
        }
        param_1[0x1d] =
             (param_1[(int)fVar2 + 0xd] - param_1[(int)fVar2 + 7]) *
             (param_2 / param_1[(int)fVar2 + 1]) * (param_2 / param_1[(int)fVar2 + 1]) +
             param_1[(int)fVar2 + 7];
      }
    }
    else {
      param_1[0x1d] = param_1[(int)fVar2 + 0xd];
      if ((int)param_1[0x1b] + -1 <= (int)fVar2) {
        *(undefined1 *)(param_1 + 0x1e) = 1;
        return;
      }
      fVar1 = param_1[(int)fVar2 + 1];
      param_1[0x1c] = (float)((int)fVar2 + 1);
      *param_1 = param_2 - fVar1;
      if (*(char *)((int)fVar2 + 0x4d + (int)param_1) != '\0') {
        param_1[(int)fVar2 + 8] = param_1[(int)fVar2 + 0xd];
        return;
      }
    }
  }
  return;
}


// ==== 0x5327f0 FUN_005327f0

void __thiscall
FUN_005327f0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,float param_4,float param_5)

{
  *param_1 = param_2;
  param_1[2] = param_4;
  param_1[1] = param_3;
  param_1[3] = param_5;
  if (ABS(param_5 - param_4) < 1e-06) {
    param_1[3] = param_5 + 1e-06;
  }
  param_1[4] = 0;
  param_1[5] = param_2;
  return;
}


// ==== 0x532840 EAX_linear_ramp_evaluate__not_SetCsisName_

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall EAX_linear_ramp_evaluate__not_SetCsisName_(float *param_1)

{
  float fVar1;
  
  fVar1 = (param_1[4] - param_1[2]) / (param_1[3] - param_1[2]);
  if (0.0 < fVar1) {
    if (_K_ONE < fVar1) {
      fVar1 = _K_ONE;
    }
    *(undefined1 *)(param_1 + 6) = 0;
    param_1[5] = (param_1[1] - *param_1) * fVar1 + *param_1;
    return;
  }
  *(undefined1 *)(param_1 + 6) = 0;
  param_1[5] = (param_1[1] - *param_1) * 0.0 + *param_1;
  return;
}


// ==== 0x5328b0 FUN_005328b0

int FUN_005328b0(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *in_EAX;
  int iVar8;
  
  if (DAT_007361c4 < 2) {
    return *(int *)(DAT_007361bc + 4);
  }
  iVar1 = *(int *)(DAT_007361bc + 4);
  fVar2 = *(float *)(iVar1 + 0x60) - *in_EAX;
  iVar8 = *(int *)(DAT_007361c0 + 4);
  fVar4 = *(float *)(iVar1 + 100) - in_EAX[1];
  fVar3 = *(float *)(iVar1 + 0x68) - in_EAX[2];
  fVar5 = *(float *)(iVar8 + 0x60) - *in_EAX;
  fVar6 = *(float *)(iVar8 + 100) - in_EAX[1];
  fVar7 = *(float *)(iVar8 + 0x68) - in_EAX[2];
  if (SQRT(fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3) <=
      SQRT(fVar5 * fVar5 + fVar6 * fVar6 + fVar7 * fVar7)) {
    iVar8 = iVar1;
  }
  return iVar8;
}


// ==== 0x532960 EA::Allocator::DefaultIAllocatorImpl::Allocate

/* [canon] runtime med (ghidra+hopper) docs/re/tuning.md */

void __thiscall EA__Allocator__DefaultIAllocatorImpl__Allocate(int param_1,uint param_2)

{
  if (param_2 < DAT_0072f560) {
    if (DAT_0073560c < param_2) {
      DAT_0073560c = param_2;
    }
    FUN_00567160();
    return;
  }
  *(undefined **)(param_1 + 4) = PTR_s_CSISSOUND_006f8714;
  PTR_s_CSISSOUND_006f8714 = s_CSIS_ALLOCATOR_006be510;
  FUN_00565b60(param_2,0,0,0);
  return;
}


// ==== 0x5329b0 FUN_005329b0

void FUN_005329b0(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = *(int *)(DAT_0072d558 + 0x18);
  piVar1 = (int *)(DAT_0072d558 + 0x18);
  puVar3 = (undefined4 *)(DAT_0072d558 + 0x10);
  *param_1 = *puVar3;
  *puVar3 = param_1;
  *piVar1 = iVar2 + -1;
  return;
}


// ==== 0x5329e0 FUN_005329e0

undefined4 * __thiscall FUN_005329e0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006be4fc;
  SlotPool__Destroy();
  DAT_0072d558 = 0;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x532a20 EAXSND8Wrapper::Initialize

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 EAXSND8Wrapper__Initialize(void)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  size_t _Size;
  int unaff_ESI;
  bool bVar4;
  undefined1 local_5;
  undefined1 local_4 [4];
  
  if (DAT_006f1dd8 == 0) {
    return 0;
  }
  local_5 = 0;
  iVar2 = FUN_0064e680(1,&local_5);
  if (iVar2 < 0) {
    return 0;
  }
  DAT_0072d558 = (undefined4 *)FUN_00566dc0(DAT_0072f560 + 3U & 0xfffffffc,"Csis SlotPools",0);
  if ((DAT_0072d558 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_0072d558;
    puVar1 = DAT_0072d558;
    DAT_0072d558[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_0072d558 = &DAT_0073d818;
  }
  FUN_0064b500(&PTR_PTR_00705810);
  FUN_0064b530();
  FUN_0064e9e0();
  FUN_0064ea10();
  FUN_0064e5f0(0x20);
  *(undefined4 *)(unaff_ESI + 0xc) = 0x39000;
  pvVar3 = _malloc(0x39000);
  *(void **)(unaff_ESI + 4) = pvVar3;
  FUN_0064e710(0,24000);
  bVar4 = DAT_006f1dd8 != 0;
  *(undefined4 *)(unaff_ESI + 0x14) = 1;
  *(undefined4 *)(unaff_ESI + 0x18) = 1;
  if (bVar4) {
    *(undefined4 *)(unaff_ESI + 0x14) = 1;
  }
  if ((DAT_00736334 == 0) || (DAT_006f7e88 = 0xac44, DAT_00736334 == 1)) {
    DAT_006f7e88 = 0x5622;
  }
  if (DAT_00735610 != 0) {
    DAT_006f7e88 = DAT_00735610;
  }
  FUN_0064e930(0,local_4);
  FUN_0064e780(0,0x40);
  FUN_0064e930(0,local_4);
  FUN_0064e620(DAT_006f7e84);
  FUN_0064e710(0,DAT_006f7e88);
  FUN_0064e900(0,*(undefined4 *)(unaff_ESI + 4),*(undefined4 *)(unaff_ESI + 0xc));
  FUN_0064e800(0x80407);
  if (DAT_006f1ddc != 0) {
    _Size = DAT_006f7e8c << 0xc;
    *(size_t *)(unaff_ESI + 0x10) = _Size;
    pvVar3 = _malloc(_Size);
    *(void **)(unaff_ESI + 8) = pvVar3;
    SNDAEMS_streaminit(pvVar3,*(undefined4 *)(unaff_ESI + 0x10),4);
  }
  return 1;
}


// ==== 0x532bb0 EAXSound_InitMixerBanks

/* [canon] audio med (hopper+capstone) docs/re/misc.md */

void EAXSound_InitMixerBanks(void)

{
  int unaff_EDI;
  undefined1 local_4 [4];
  
  if (DAT_006f1dd8 != 0) {
    FUN_0064e8e0();
    FUN_0064b560();
    FUN_0064b500(&PTR_PTR_00705810);
    FUN_0064b530();
    FUN_0064e9e0();
    FUN_0064ea10();
    FUN_0064e5f0(0x20);
    *(undefined4 *)(unaff_EDI + 0x14) = DAT_00758920;
    FUN_00532cb0(unaff_EDI);
    FUN_0064e710(0,24000);
    FUN_0064e900(0,*(undefined4 *)(unaff_EDI + 4),*(undefined4 *)(unaff_EDI + 0xc));
    if ((DAT_00736334 == 0) || (DAT_006f7e88 = 0xac44, DAT_00736334 == 1)) {
      DAT_006f7e88 = 0x5622;
    }
    if (DAT_00735610 != 0) {
      DAT_006f7e88 = DAT_00735610;
    }
    FUN_0064e930(0,local_4);
    FUN_0064e780(0,0x40);
    FUN_0064e930(0,local_4);
    FUN_0064e620(DAT_006f7e84);
    FUN_0064e710(0,DAT_006f7e88);
    FUN_0064e800(0x80407);
    if (DAT_006f1ddc != 0) {
      SNDAEMS_streaminit(*(undefined4 *)(unaff_EDI + 8),*(undefined4 *)(unaff_EDI + 0x10),4);
    }
  }
  return;
}


// ==== 0x532cb0 FUN_00532cb0

void FUN_00532cb0(void)

{
  undefined4 unaff_ESI;
  
  if (DAT_006f1dd8 != 0) {
    switch(unaff_ESI) {
    case 0:
      FUN_0064e6e0(0);
      return;
    case 1:
    case 2:
      FUN_0064e6e0(8);
      return;
    case 3:
      NullUpdate_ret();
      FUN_0064e6e0(5);
      FUN_0064e7f0(0x3f000000);
    }
  }
  return;
}


// ==== 0x532d20 FUN_00532d20

void __fastcall FUN_00532d20(int param_1)

{
  *(undefined1 *)(param_1 + 0x220) = 1;
  return;
}


// ==== 0x532d30 FUN_00532d30

void __fastcall FUN_00532d30(int param_1)

{
  *(undefined1 *)(param_1 + 0x220) = 0;
  return;
}


// ==== 0x532d40 FUN_00532d40

int * FUN_00532d40(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  void *pvVar6;
  int iVar7;
  char *pcVar8;
  int *piVar9;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685d09;
  local_c = ExceptionList;
  if (DAT_006f1dd8 == 0) {
    return (int *)0x0;
  }
  piVar9 = (int *)0x0;
  pcVar8 = "TrolleySoundObject";
  uVar5 = 0x54;
  iVar7 = -1;
  do {
    iVar7 = iVar7 * 0x21 + uVar5;
    pbVar1 = (byte *)(pcVar8 + 1);
    uVar5 = (uint)*pbVar1;
    pcVar8 = pcVar8 + 1;
  } while (*pbVar1 != 0);
  if (param_1 == iVar7) {
    ExceptionList = &local_c;
    pvVar6 = _malloc(0x310);
    local_4 = 0;
    if (pvVar6 == (void *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      piVar9 = (int *)FUN_00533990();
    }
    local_4 = 0xffffffff;
    (**(code **)(*piVar9 + 0x10))(&DAT_006f4570);
    (**(code **)(*piVar9 + 0x24))();
  }
  else {
    pcVar8 = "BridgeWarningSoundObject";
    iVar7 = -1;
    uVar5 = 0x42;
    do {
      iVar7 = iVar7 * 0x21 + uVar5;
      pbVar1 = (byte *)(pcVar8 + 1);
      uVar5 = (uint)*pbVar1;
      pcVar8 = pcVar8 + 1;
    } while (*pbVar1 != 0);
    if (param_1 == iVar7) {
      ExceptionList = &local_c;
      pvVar6 = _malloc(0x2a0);
      if (pvVar6 == (void *)0x0) {
        piVar9 = (int *)0x0;
      }
      else {
        piVar9 = (int *)FUN_00534110();
      }
      (**(code **)(*piVar9 + 0x10))(&DAT_006f45e0);
      (**(code **)(*piVar9 + 0x24))();
    }
    else {
      ExceptionList = &local_c;
      iVar7 = FUN_00567c70();
      if (param_1 == iVar7) {
        if (DAT_00735600 != 0) {
          DAT_00735600 = DAT_00735600 + 1;
          if (DAT_007441b8 != (int *)0x0) {
            (**(code **)(DAT_007441b8[-0x84] + 0x40))(param_2,0);
            ExceptionList = local_c;
            return (int *)0x0;
          }
          (**(code **)(iRam00000000 + 0x40))(param_2,0);
          ExceptionList = local_c;
          return (int *)0x0;
        }
        DAT_00735600 = 1;
        pvVar6 = _malloc(0x290);
        local_4 = 1;
        if (pvVar6 == (void *)0x0) {
          piVar9 = (int *)0x0;
        }
        else {
          piVar9 = (int *)FUN_00534800();
        }
        local_4 = 0xffffffff;
        (**(code **)(*piVar9 + 0x10))(&DAT_006f46c0);
        (**(code **)(*piVar9 + 0x24))();
      }
      else {
        iVar7 = FUN_00567c70();
        if (param_1 == iVar7) {
          pvVar6 = _malloc(0x290);
          if (pvVar6 == (void *)0x0) {
            piVar9 = (int *)0x0;
          }
          else {
            piVar9 = (int *)FUN_005344d0();
          }
          (**(code **)(*piVar9 + 0x10))(&DAT_006f4650);
          (**(code **)(*piVar9 + 0x24))();
        }
        iVar7 = FUN_00567c70();
        if (param_1 == iVar7) {
          pvVar6 = _malloc(0x290);
          local_4 = 2;
          if (pvVar6 == (void *)0x0) {
            piVar9 = (int *)0x0;
          }
          else {
            piVar9 = (int *)FUN_005343e0(pvVar6);
          }
          local_4 = 0xffffffff;
          (**(code **)(*piVar9 + 0x10))(&DAT_006f4730);
          (**(code **)(*piVar9 + 0x24))();
        }
      }
    }
  }
  piVar4 = DAT_007441b8;
  if (piVar9 != (int *)0x0) {
    piVar3 = piVar9 + 0x84;
    piVar2 = DAT_007441b8 + 1;
    DAT_007441b8 = piVar3;
    *piVar2 = (int)piVar3;
    piVar9[0x85] = (int)&DAT_007441b8;
    *piVar3 = (int)piVar4;
  }
  ExceptionList = local_c;
  return piVar9;
}


// ==== 0x532fc0 FUN_00532fc0

void FUN_00532fc0(void)

{
  int *piVar1;
  int *piVar2;
  
  if (DAT_007441b8 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(DAT_007441b8 + -0x210);
  }
  piVar1 = (int *)FUN_005325f0();
  while (piVar2 != piVar1) {
    (**(code **)(*piVar2 + 0x2c))();
    if (piVar2[0x84] == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)(piVar2[0x84] + -0x210);
    }
  }
  return;
}


// ==== 0x533010 FUN_00533010

void FUN_00533010(void)

{
  int *piVar1;
  int *piVar2;
  
  if (DAT_007441b8 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(DAT_007441b8 + -0x210);
  }
  piVar1 = (int *)FUN_005325f0();
  while (piVar2 != piVar1) {
    (**(code **)(*piVar2 + 0x30))();
    if (piVar2[0x84] == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)(piVar2[0x84] + -0x210);
    }
  }
  return;
}


// ==== 0x533060 FUN_00533060

void FUN_00533060(void)

{
  int *piVar1;
  int *piVar2;
  
  if (DAT_007441b8 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(DAT_007441b8 + -0x210);
  }
  piVar1 = (int *)FUN_005325f0();
  while (piVar2 != piVar1) {
    (**(code **)(*piVar2 + 0x34))();
    if (piVar2[0x84] == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)(piVar2[0x84] + -0x210);
    }
  }
  return;
}


// ==== 0x5330b0 FUN_005330b0

void FUN_005330b0(void)

{
  int *piVar1;
  int *piVar2;
  
  if (DAT_007441b8 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(DAT_007441b8 + -0x210);
  }
  piVar1 = (int *)FUN_005325f0();
  while (piVar2 != piVar1) {
    (**(code **)(*piVar2 + 0x24))();
    if (piVar2[0x84] == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)(piVar2[0x84] + -0x210);
    }
  }
  return;
}


// ==== 0x533100 FUN_00533100

void FUN_00533100(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  piVar4 = &DAT_0072f568;
  do {
    puVar1 = (undefined4 *)*piVar4;
    if (puVar1 != (undefined4 *)0x0) {
      iVar2 = puVar1[0x84];
      piVar3 = (int *)puVar1[0x85];
      *piVar3 = iVar2;
      *(int **)(iVar2 + 4) = piVar3;
      (**(code **)*puVar1)(1);
      *piVar4 = 0;
    }
    piVar4 = piVar4 + 1;
  } while ((int)piVar4 < 0x72f5e4);
  DAT_00735604 = 0;
  return;
}


// ==== 0x533140 FUN_00533140

void FUN_00533140(void)

{
  char *pcVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  int unaff_EDI;
  
  FUN_00533100();
  if (unaff_EDI == 0x3ec) {
    pcVar6 = "WorldObject";
    do {
      pcVar1 = pcVar6 + 1;
      pcVar6 = pcVar6 + 1;
    } while (*pcVar1 != '\0');
    pcVar6 = "XO_PlaneA_1b_01";
    do {
      pcVar1 = pcVar6 + 1;
      pcVar6 = pcVar6 + 1;
    } while (*pcVar1 != '\0');
    iVar3 = FUN_00578010();
    if (iVar3 != 0) {
      pcVar6 = "PlaneSOB";
      iVar7 = -1;
      uVar5 = 0x50;
      do {
        iVar7 = iVar7 * 0x21 + uVar5;
        pbVar2 = (byte *)(pcVar6 + 1);
        uVar5 = (uint)*pbVar2;
        pcVar6 = pcVar6 + 1;
      } while (*pbVar2 != 0);
      uVar4 = FUN_00532d40(iVar7,iVar3);
      (&DAT_0072f568)[DAT_00735604] = uVar4;
      DAT_00735604 = DAT_00735604 + 1;
    }
  }
  switch(unaff_EDI) {
  case 0x3e9:
  case 0x450:
    uVar4 = FUN_00567c70(0);
    uVar4 = FUN_00532d40(uVar4);
    (&DAT_0072f568)[DAT_00735604] = uVar4;
    DAT_00735604 = DAT_00735604 + 1;
    uVar4 = FUN_00567c70(0);
    uVar4 = FUN_00532d40(uVar4);
    (&DAT_0072f568)[DAT_00735604] = uVar4;
    DAT_00735604 = DAT_00735604 + 1;
  case 0x3eb:
  case 0x3ec:
  case 0x3ed:
  case 0x3ee:
  case 0x3ef:
  case 0x3f0:
  case 0x44e:
  case 0x44f:
  case 0x451:
  case 0x452:
  case 0x453:
  case 0x454:
  case 0x455:
    pcVar6 = "FountainObj";
    iVar3 = -1;
    uVar5 = 0x46;
    do {
      iVar3 = iVar3 * 0x21 + uVar5;
      pbVar2 = (byte *)(pcVar6 + 1);
      uVar5 = (uint)*pbVar2;
      pcVar6 = pcVar6 + 1;
    } while (*pbVar2 != 0);
    uVar4 = FUN_00532d40(iVar3,0);
    (&DAT_0072f568)[DAT_00735604] = uVar4;
    DAT_00735604 = DAT_00735604 + 1;
    pcVar6 = "FountainObj";
    iVar3 = -1;
    uVar5 = 0x46;
    do {
      iVar3 = iVar3 * 0x21 + uVar5;
      pbVar2 = (byte *)(pcVar6 + 1);
      uVar5 = (uint)*pbVar2;
      pcVar6 = pcVar6 + 1;
    } while (*pbVar2 != 0);
    uVar4 = FUN_00532d40(iVar3,0);
    (&DAT_0072f568)[DAT_00735604] = uVar4;
    DAT_00735604 = DAT_00735604 + 1;
    pcVar6 = "FountainObj";
    iVar3 = -1;
    uVar5 = 0x46;
    do {
      iVar3 = iVar3 * 0x21 + uVar5;
      pbVar2 = (byte *)(pcVar6 + 1);
      uVar5 = (uint)*pbVar2;
      pcVar6 = pcVar6 + 1;
    } while (*pbVar2 != 0);
    uVar4 = FUN_00532d40(iVar3,0);
    (&DAT_0072f568)[DAT_00735604] = uVar4;
    DAT_00735604 = DAT_00735604 + 1;
    pcVar6 = "FountainObj";
    iVar3 = -1;
    uVar5 = 0x46;
    do {
      iVar3 = iVar3 * 0x21 + uVar5;
      pbVar2 = (byte *)(pcVar6 + 1);
      uVar5 = (uint)*pbVar2;
      pcVar6 = pcVar6 + 1;
    } while (*pbVar2 != 0);
    uVar4 = FUN_00532d40(iVar3,0);
    (&DAT_0072f568)[DAT_00735604] = uVar4;
    DAT_00735604 = DAT_00735604 + 1;
    pcVar6 = "FountainObj";
    iVar3 = -1;
    uVar5 = 0x46;
    do {
      iVar3 = iVar3 * 0x21 + uVar5;
      pbVar2 = (byte *)(pcVar6 + 1);
      uVar5 = (uint)*pbVar2;
      pcVar6 = pcVar6 + 1;
    } while (*pbVar2 != 0);
    uVar4 = FUN_00532d40(iVar3,0);
    (&DAT_0072f568)[DAT_00735604] = uVar4;
    DAT_00735604 = DAT_00735604 + 1;
    pcVar6 = "FountainObj";
    iVar3 = -1;
    uVar5 = 0x46;
    do {
      iVar3 = iVar3 * 0x21 + uVar5;
      pbVar2 = (byte *)(pcVar6 + 1);
      uVar5 = (uint)*pbVar2;
      pcVar6 = pcVar6 + 1;
    } while (*pbVar2 != 0);
    uVar4 = FUN_00532d40(iVar3,0);
    (&DAT_0072f568)[DAT_00735604] = uVar4;
    DAT_00735604 = DAT_00735604 + 1;
    pcVar6 = "FountainObj";
    iVar3 = -1;
    uVar5 = 0x46;
    do {
      iVar3 = iVar3 * 0x21 + uVar5;
      pbVar2 = (byte *)(pcVar6 + 1);
      uVar5 = (uint)*pbVar2;
      pcVar6 = pcVar6 + 1;
    } while (*pbVar2 != 0);
    uVar4 = FUN_00532d40(iVar3,0);
    (&DAT_0072f568)[DAT_00735604] = uVar4;
    DAT_00735604 = DAT_00735604 + 1;
    pcVar6 = "FountainObj";
    iVar3 = -1;
    uVar5 = 0x46;
    do {
      iVar3 = iVar3 * 0x21 + uVar5;
      pbVar2 = (byte *)(pcVar6 + 1);
      uVar5 = (uint)*pbVar2;
      pcVar6 = pcVar6 + 1;
    } while (*pbVar2 != 0);
    uVar4 = FUN_00532d40(iVar3,0);
    (&DAT_0072f568)[DAT_00735604] = uVar4;
    DAT_00735604 = DAT_00735604 + 1;
    pcVar6 = "FountainObj";
    iVar3 = -1;
    uVar5 = 0x46;
    do {
      iVar3 = iVar3 * 0x21 + uVar5;
      pbVar2 = (byte *)(pcVar6 + 1);
      uVar5 = (uint)*pbVar2;
      pcVar6 = pcVar6 + 1;
    } while (*pbVar2 != 0);
    uVar4 = 0;
    break;
  default:
    goto switchD_00533206_caseD_3ea;
  case 0x4b1:
    uVar4 = 0;
    iVar3 = FUN_00567c70(0);
  }
  uVar4 = FUN_00532d40(iVar3,uVar4);
  (&DAT_0072f568)[DAT_00735604] = uVar4;
  DAT_00735604 = DAT_00735604 + 1;
switchD_00533206_caseD_3ea:
  return;
}


// ==== 0x5336c0 SoundObject::SoundObject_WorldObject__

/* [canon] audio med (ghidra) docs/re/sound.md */

undefined4 * SoundObject__SoundObject_WorldObject__(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *extraout_EDX;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006852c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  EAXS_3DMixer__EAXS_3DMixer();
  *param_1 = &PTR_EAXS_3DMixer_derived_deleting_destructor__map__EAXS_SoundShape_____006be428;
  param_1[0x8c] = param_2;
  param_1[0x86] = 0x42c80000;
  param_1[0x87] = 0x40a00000;
  *(undefined1 *)(param_1 + 0x88) = 0;
  param_1[0x89] = 0;
  param_1[0x8a] = 0;
  param_1[0x2f] = &DAT_006f4500;
  iVar3 = *(int *)(param_2 + 0x1c);
  local_4 = 0;
  if (*(int *)(iVar3 + 0xe4) != 0) {
    FUN_005791c0();
  }
  uVar1 = *(undefined4 *)(iVar3 + 0x44);
  uVar2 = *(undefined4 *)(iVar3 + 0x48);
  param_1[0x94] = *(undefined4 *)(iVar3 + 0x40);
  param_1[0x95] = uVar1;
  param_1[0x96] = uVar2;
  iVar3 = *(int *)(param_2 + 0x1c);
  if (*(int *)(iVar3 + 0xe4) != 0) {
    FUN_005791c0();
  }
  uVar1 = *(undefined4 *)(iVar3 + 0x44);
  uVar2 = *(undefined4 *)(iVar3 + 0x48);
  param_1[0x90] = *(undefined4 *)(iVar3 + 0x40);
  param_1[0x91] = uVar1;
  param_1[0x92] = uVar2;
  iVar3 = *(int *)(param_2 + 0x1c);
  if (*(int *)(iVar3 + 0xe4) != 0) {
    FUN_005791c0();
  }
  uVar2 = *(undefined4 *)(iVar3 + 0x40);
  uVar1 = *(undefined4 *)(iVar3 + 0x48);
  param_1[0x9d] = *(undefined4 *)(iVar3 + 0x44);
  param_1[0x9c] = uVar2;
  param_1[0x9e] = uVar1;
  bNormalize3();
  uVar1 = extraout_EDX[1];
  uVar2 = extraout_EDX[2];
  param_1[0x98] = *extraout_EDX;
  param_1[0x99] = uVar1;
  param_1[0x9a] = uVar2;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x5337f0 SoundObject::SoundObject_bVector3_const__

/* [canon] audio med (ghidra) docs/re/sound.md */

void SoundObject__SoundObject_bVector3_const__(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *extraout_EDX;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  EAXS_3DMixer__EAXS_3DMixer();
  *unaff_ESI = &PTR_EAXS_3DMixer_derived_deleting_destructor__map__EAXS_SoundShape_____006be428;
  unaff_ESI[0x8c] = 0;
  uVar1 = unaff_EDI[1];
  uVar2 = unaff_EDI[2];
  unaff_ESI[0x90] = *unaff_EDI;
  unaff_ESI[0x91] = uVar1;
  unaff_ESI[0x92] = uVar2;
  unaff_ESI[0x86] = 0x42c80000;
  unaff_ESI[0x87] = 0x40a00000;
  *(undefined1 *)(unaff_ESI + 0x88) = 0;
  unaff_ESI[0x89] = 0;
  unaff_ESI[0x8a] = 0;
  uVar1 = unaff_EDI[1];
  uVar2 = unaff_EDI[2];
  unaff_ESI[0x94] = *unaff_EDI;
  unaff_ESI[0x95] = uVar1;
  unaff_ESI[0x96] = uVar2;
  uVar1 = unaff_EDI[1];
  uVar2 = unaff_EDI[2];
  unaff_ESI[0x90] = *unaff_EDI;
  unaff_ESI[0x91] = uVar1;
  unaff_ESI[0x92] = uVar2;
  uVar1 = unaff_EDI[1];
  uVar2 = unaff_EDI[2];
  unaff_ESI[0x9c] = *unaff_EDI;
  unaff_ESI[0x9d] = uVar1;
  unaff_ESI[0x9e] = uVar2;
  bNormalize3();
  uVar1 = extraout_EDX[1];
  uVar2 = extraout_EDX[2];
  unaff_ESI[0x98] = *extraout_EDX;
  unaff_ESI[0x99] = uVar1;
  unaff_ESI[0x9a] = uVar2;
  return;
}


// ==== 0x5338c0 SoundObject::Update

/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall SoundObject__Update(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  
  if (param_1[0x8c] != 0) {
    iVar3 = *(int *)(param_1[0x8c] + 0x1c);
    if (*(int *)(iVar3 + 0xe4) != 0) {
      FUN_005791c0();
    }
    iVar1 = *(int *)(iVar3 + 0x44);
    iVar2 = *(int *)(iVar3 + 0x48);
    param_1[0x90] = *(int *)(iVar3 + 0x40);
    param_1[0x91] = iVar1;
    param_1[0x92] = iVar2;
  }
  EAXS_3DMixer__Update3DMix(param_1 + 0x90,param_1 + 0x98);
  if (param_1[0x14] < 1) {
    cVar4 = (**(code **)(*param_1 + 0x44))();
    if (cVar4 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0053393b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0x3c))();
      return;
    }
  }
  else {
    cVar4 = (**(code **)(*param_1 + 0x44))();
    if (cVar4 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x0053392c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0x38))();
      return;
    }
  }
  return;
}


// ==== 0x533940 FUN_00533940

void FUN_00533940(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *unaff_ESI;
  
  piVar1 = (int *)*unaff_ESI;
  while (piVar1 != unaff_ESI) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    if (piVar1 + -0x84 != (int *)0x0) {
      (**(code **)piVar1[-0x84])(1);
    }
    piVar1 = (int *)*unaff_ESI;
  }
  return;
}


// ==== 0x533970 FUN_00533970

bool __fastcall FUN_00533970(int param_1)

{
  return *(int *)(param_1 + 0x280) != 0;
}


// ==== 0x533980 FUN_00533980

bool __fastcall FUN_00533980(int param_1)

{
  return *(int *)(param_1 + 0x290) != 0;
}


// ==== 0x533990 FUN_00533990

void FUN_00533990(void)

{
  undefined4 in_EAX;
  int extraout_EDX;
  undefined4 *unaff_ESI;
  
  SoundObject__SoundObject_WorldObject__(unaff_ESI,in_EAX);
  *unaff_ESI = &PTR_FUN_006be368;
  FUN_00532640();
  *(undefined1 *)(extraout_EDX + 0x78) = 1;
  unaff_ESI[0x89] = 1;
  unaff_ESI[0xa0] = 0;
  unaff_ESI[0xa1] = 0;
  *(undefined1 *)(unaff_ESI + 0xc1) = 0;
  unaff_ESI[0x86] = 0x42a00000;
  return;
}


// ==== 0x5339e0 FUN_005339e0

void * __thiscall FUN_005339e0(void *param_1,byte param_2)

{
  FUN_00533a00(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x533a00 FUN_00533a00

void FUN_00533a00(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006852c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006be368;
  local_4 = 0;
  FUN_005340c0();
  *param_1 = &PTR_FUN_006be7c4;
  ExceptionList = local_c;
  return;
}


// ==== 0x533a50 FUN_00533a50

void __fastcall FUN_00533a50(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  int local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_30;
  float local_2c;
  
  *(undefined4 *)(param_1 + 0x218) = 0x42a00000;
  SoundObject__Update();
  FUN_005326f0(0x3c83126f);
  iVar7 = *(int *)(param_1 + 0x50) * DAT_006f4f30 >> 0xf;
  if (*(int *)(param_1 + 0x280) != 0) {
    iVar6 = *(int *)(param_1 + 0x4c);
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    else if (0xffff < iVar6) {
      iVar6 = 0xffff;
    }
    *(int *)(*(int *)(param_1 + 0x280) + 0x10) = iVar6;
    iVar6 = _ftol_nocw();
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    else if (0x1fa0 < iVar6) {
      iVar6 = 0x1fa0;
    }
    *(int *)(*(int *)(param_1 + 0x280) + 0xc) = iVar6;
    if (DAT_007356b0 < 4) {
      if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
        iVar7 = 0;
      }
      if ((DAT_007361f0 != (int *)0x0) && ((*DAT_007361f0 == 1 || (*DAT_007361f0 == 7)))) {
        iVar7 = 0;
      }
      iVar7 = *(int *)(DAT_007356b0 * 0xd10 + 0xab8 + DAT_007356ac) * iVar7 >> 0xf;
    }
    iVar7 = DAT_006f4f48 * iVar7 >> 0xf;
    if (iVar7 < 0) {
      iVar7 = 0;
    }
    else if (0x7fff < iVar7) {
      iVar7 = 0x7fff;
    }
    *(int *)(*(int *)(param_1 + 0x280) + 8) = iVar7;
    if (**(int **)(param_1 + 0x280) != 0) {
      FUN_0064bc30(*(int **)(param_1 + 0x280) + 1);
    }
  }
  if (*(int *)(param_1 + 0x230) != 0) {
    iVar7 = *(int *)(*(int *)(param_1 + 0x230) + 0x1c);
    if (*(int *)(iVar7 + 0xe4) != 0) {
      FUN_005791c0();
    }
    fVar2 = *(float *)(iVar7 + 0x40);
    fVar1 = *(float *)(iVar7 + 0x44);
    if (*(int *)(*(int *)(*(int *)(param_1 + 0x230) + 0x1c) + 0xe4) != 0) {
      FUN_005791c0();
    }
    bNormalize3();
    if (DAT_0073619c != 0) {
      local_64 = *(int *)(DAT_0073619c + 0x24);
      bVar5 = false;
      if (0 < local_64) {
        iVar6 = 0x520;
        iVar7 = DAT_0073619c;
        do {
          fVar3 = *(float *)(**(int **)(iVar6 + iVar7) + 0x60) - fVar2;
          fVar4 = *(float *)(**(int **)(iVar6 + iVar7) + 100) - fVar1;
          if (SQRT(fVar3 * fVar3 + fVar4 * fVar4) <= *(float *)(param_1 + 0x218)) {
            bNormalize3();
            fVar3 = local_58 * local_58 + local_30 * local_60 + local_2c * local_5c;
            if ((((0.0 < fVar3) && (fVar8 = (float10)FUN_00564b10(), fVar8 < (float10)fVar3)) &&
                (0 < *(int *)(param_1 + 0x50))) && (bVar5 = true, *(int *)(param_1 + 0x284) == 0)) {
              FUN_00533f70(param_1);
              iVar7 = DAT_0073619c;
            }
          }
          iVar6 = iVar6 + 4;
          local_64 = local_64 + -1;
        } while (local_64 != 0);
        if (bVar5) goto LAB_00533d5a;
      }
      if ((*(int *)(param_1 + 0x284) != 0) && (*(char *)(param_1 + 0x304) == '\0')) {
        *(undefined1 *)(param_1 + 0x304) = 1;
        FUN_00532640();
        FUN_00532670(0x3f800000,0,200,0);
        *(undefined4 *)(param_1 + 0x2fc) = 0x3f800000;
      }
    }
  }
LAB_00533d5a:
  if (*(int *)(param_1 + 0x284) != 0) {
    iVar7 = *(int *)(param_1 + 0x4c);
    if (iVar7 < 0) {
      iVar7 = 0;
    }
    else if (0xffff < iVar7) {
      iVar7 = 0xffff;
    }
    *(int *)(*(int *)(param_1 + 0x284) + 0x10) = iVar7;
    iVar7 = _ftol_nocw();
    if (iVar7 < 0) {
      iVar7 = 0;
    }
    else if (0x1fa0 < iVar7) {
      iVar7 = 0x1fa0;
    }
    *(int *)(*(int *)(param_1 + 0x284) + 0xc) = iVar7;
    iVar7 = _ftol_nocw();
    if (iVar7 < 0) {
      iVar7 = 0;
    }
    else if (0x7fff < iVar7) {
      iVar7 = 0x7fff;
    }
    *(int *)(*(int *)(param_1 + 0x284) + 8) = iVar7;
    if (**(int **)(param_1 + 0x284) != 0) {
      FUN_0064bc30(*(int **)(param_1 + 0x284) + 1);
    }
  }
  if ((*(char *)(param_1 + 0x304) != '\0') && (*(char *)(param_1 + 0x300) != '\0')) {
    *(undefined1 *)(param_1 + 0x304) = 0;
    FUN_00534070();
  }
  return;
}


// ==== 0x533e80 FUN_00533e80

void __fastcall FUN_00533e80(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puStack_14;
  int iStack_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  pvStack_c = ExceptionList;
  if ((DAT_006f1dd8 != 0) && (*(int *)(param_1 + 0x280) == 0)) {
    ExceptionList = &pvStack_c;
    Csis__System__GetAllocator(&puStack_14);
    Mutex__Lock();
    iVar2 = (**(code **)*puStack_14)(0x18,4,0xffffffff);
    Mutex__Unlock();
    uStack_4 = 0;
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      puVar1 = (undefined4 *)(iVar2 + 4);
      *puVar1 = 1;
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined4 *)(iVar2 + 0xc) = 0xfff;
      *(undefined4 *)(iVar2 + 0x10) = 0;
      *(undefined4 *)(iVar2 + 0x14) = 1;
      iStack_10 = iVar2;
      iVar3 = Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar2);
      if (iVar3 < 0) {
        Csis__ClassHandle__Set(&PTR_s_ENV_STATIC_006f81c0);
        Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar2);
      }
    }
    *(int *)(param_1 + 0x280) = iVar2;
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x533f70 FUN_00533f70

void FUN_00533f70(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  puVar2 = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  local_c = ExceptionList;
  if (DAT_006f1dd8 != 0) {
    ExceptionList = &local_c;
    Csis__System__GetAllocator(&param_1);
    Mutex__Lock();
    iVar3 = (**(code **)*param_1)(0x18,4,0xffffffff);
    Mutex__Unlock();
    uStack_4 = 0;
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      puVar1 = (undefined4 *)(iVar3 + 4);
      *puVar1 = 0;
      *(undefined4 *)(iVar3 + 8) = 0;
      *(undefined4 *)(iVar3 + 0xc) = 0xfff;
      *(undefined4 *)(iVar3 + 0x10) = 0;
      *(undefined4 *)(iVar3 + 0x14) = 1;
      iVar4 = Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar3);
      if (iVar4 < 0) {
        Csis__ClassHandle__Set(&PTR_s_ENV_STATIC_006f81c0);
        Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar3);
      }
    }
    puVar2[0xa1] = iVar3;
    FUN_00532640();
    FUN_00532670(0x3f800000,0x3f800000,1,0);
    puVar2[0xbf] = 0x3f800000;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x534070 FUN_00534070

void FUN_00534070(void)

{
  int *piVar1;
  int unaff_EDI;
  int *local_4;
  
  piVar1 = *(int **)(unaff_EDI + 0x284);
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_4);
    Mutex__Lock();
    (**(code **)(*local_4 + 4))(piVar1);
    Mutex__Unlock();
  }
  *(undefined4 *)(unaff_EDI + 0x284) = 0;
  return;
}


// ==== 0x5340c0 FUN_005340c0

void __fastcall FUN_005340c0(int *param_1)

{
  int *piVar1;
  int *local_4;
  
  piVar1 = (int *)param_1[0xa0];
  if (piVar1 != (int *)0x0) {
    local_4 = param_1;
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_4);
    Mutex__Lock();
    (**(code **)(*local_4 + 4))(piVar1);
    Mutex__Unlock();
  }
  param_1[0xa0] = 0;
  return;
}


// ==== 0x534110 FUN_00534110

void FUN_00534110(void)

{
  undefined4 *in_EAX;
  
  SoundObject__SoundObject_bVector3_const__();
  in_EAX[0x86] = 0x43be0000;
  *in_EAX = &PTR_FUN_006be2c8;
  in_EAX[0xa4] = 0;
  return;
}


// ==== 0x534140 FUN_00534140

void * __thiscall FUN_00534140(void *param_1,byte param_2)

{
  FUN_00534160(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x534160 FUN_00534160

void FUN_00534160(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006852c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006be2c8;
  local_4 = 0;
  FUN_00534390();
  *param_1 = &PTR_FUN_006be7c4;
  ExceptionList = local_c;
  return;
}


// ==== 0x5341b0 FUN_005341b0

void __fastcall FUN_005341b0(int param_1)

{
  int iVar1;
  int iVar2;
  
  SoundObject__Update();
  iVar2 = *(int *)(param_1 + 0x50) * DAT_006f4f38 >> 0xf;
  if (DAT_007356b0 < 4) {
    if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
      iVar2 = 0;
    }
    if ((DAT_007361f0 != (int *)0x0) && ((*DAT_007361f0 == 1 || (*DAT_007361f0 == 7)))) {
      iVar2 = 0;
    }
    iVar2 = *(int *)(DAT_007356b0 * 0xd10 + 0xab8 + DAT_007356ac) * iVar2 >> 0xf;
  }
  if (*(int *)(param_1 + 0x290) != 0) {
    iVar1 = *(int *)(param_1 + 0x4c);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0xffff < iVar1) {
      iVar1 = 0xffff;
    }
    *(int *)(*(int *)(param_1 + 0x290) + 0x10) = iVar1;
    iVar1 = _ftol_nocw();
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x1fa0 < iVar1) {
      iVar1 = 0x1fa0;
    }
    *(int *)(*(int *)(param_1 + 0x290) + 0xc) = iVar1;
    iVar2 = DAT_006f4f4c * iVar2 >> 0xf;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x7fff < iVar2) {
      iVar2 = 0x7fff;
    }
    *(int *)(*(int *)(param_1 + 0x290) + 8) = iVar2;
    if (**(int **)(param_1 + 0x290) != 0) {
      FUN_0064bc30(*(int **)(param_1 + 0x290) + 1);
    }
  }
  return;
}


// ==== 0x5342b0 FUN_005342b0

void __fastcall FUN_005342b0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puStack_14;
  int iStack_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  pvStack_c = ExceptionList;
  if ((DAT_006f1dd8 != 0) && (*(int *)(param_1 + 0x290) == 0)) {
    ExceptionList = &pvStack_c;
    Csis__System__GetAllocator(&puStack_14);
    Mutex__Lock();
    iVar2 = (**(code **)*puStack_14)(0x18,4,0xffffffff);
    Mutex__Unlock();
    uStack_4 = 0;
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      puVar1 = (undefined4 *)(iVar2 + 4);
      *puVar1 = 2;
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined4 *)(iVar2 + 0xc) = 0;
      *(undefined4 *)(iVar2 + 0x10) = 0;
      *(undefined4 *)(iVar2 + 0x14) = 1;
      iStack_10 = iVar2;
      iVar3 = Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar2);
      if (iVar3 < 0) {
        Csis__ClassHandle__Set(&PTR_s_ENV_STATIC_006f81c0);
        Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar2);
      }
    }
    *(int *)(param_1 + 0x290) = iVar2;
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x534390 FUN_00534390

void __fastcall FUN_00534390(int *param_1)

{
  int *piVar1;
  int *local_4;
  
  piVar1 = (int *)param_1[0xa4];
  if (piVar1 != (int *)0x0) {
    local_4 = param_1;
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_4);
    Mutex__Lock();
    (**(code **)(*local_4 + 4))(piVar1);
    Mutex__Unlock();
  }
  param_1[0xa4] = 0;
  return;
}


// ==== 0x5343e0 FUN_005343e0

undefined4 * __thiscall FUN_005343e0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006852c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  SoundObject__SoundObject_WorldObject__(param_2,param_1);
  *param_2 = &PTR_FUN_006be280;
  iVar3 = *(int *)(param_1 + 0x1c);
  local_4 = 0;
  if (*(int *)(iVar3 + 0xe4) != 0) {
    FUN_005791c0();
  }
  uVar4 = DAT_0072f5e8;
  uVar1 = *(undefined4 *)(iVar3 + 0x44);
  uVar2 = *(undefined4 *)(iVar3 + 0x48);
  param_2[0x94] = *(undefined4 *)(iVar3 + 0x40);
  param_2[0x95] = uVar1;
  param_2[0x96] = uVar2;
  uVar1 = *(undefined4 *)(iVar3 + 0x44);
  uVar2 = *(undefined4 *)(iVar3 + 0x48);
  param_2[0x90] = *(undefined4 *)(iVar3 + 0x40);
  param_2[0x91] = uVar1;
  param_2[0x92] = uVar2;
  *(undefined1 *)(param_2 + 0xa0) = 0;
  param_2[0xa1] = uVar4;
  ExceptionList = local_c;
  return param_2;
}


// ==== 0x534490 FUN_00534490

void * __thiscall FUN_00534490(void *param_1,byte param_2)

{
  FUN_00534720();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5344b0 FUN_005344b0

void * __thiscall FUN_005344b0(void *param_1,byte param_2)

{
  FUN_00534500(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5344d0 FUN_005344d0

void FUN_005344d0(void)

{
  undefined4 *in_EAX;
  
  SoundObject__SoundObject_bVector3_const__();
  *in_EAX = &PTR_FUN_006be320;
  in_EAX[0xa0] = 0;
  in_EAX[0x86] = 0x43c80000;
  in_EAX[0x87] = 0x42480000;
  return;
}


// ==== 0x534500 FUN_00534500

void FUN_00534500(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006852c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006be320;
  local_4 = 0;
  FUN_005340c0();
  *param_1 = &PTR_FUN_006be7c4;
  ExceptionList = local_c;
  return;
}


// ==== 0x534547 FUN_00534547

void __fastcall FUN_00534547(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  void *unaff_EBX;
  undefined4 *puStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*param_1 + 0x3c))();
  Csis__System__GetAllocator(&puStack_14);
  Mutex__Lock();
  iVar2 = (**(code **)*puStack_14)(0x18,4,0xffffffff);
  Mutex__Unlock();
  uStack_10 = 0;
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)(iVar2 + 4);
    *puVar1 = 3;
    *(undefined4 *)(iVar2 + 8) = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    *(undefined4 *)(iVar2 + 0x14) = 1;
    iVar3 = Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar2);
    if (iVar3 < 0) {
      Csis__ClassHandle__Set(&PTR_s_ENV_STATIC_006f81c0);
      Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar2);
    }
    param_1[0xa0] = iVar2;
    ExceptionList = unaff_EBX;
    return;
  }
  param_1[0xa0] = 0;
  ExceptionList = unaff_EBX;
  return;
}


// ==== 0x534549 FUN_00534549

void __fastcall FUN_00534549(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  void *unaff_EBX;
  undefined4 *puStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*param_1 + 0x3c))();
  Csis__System__GetAllocator(&puStack_14);
  Mutex__Lock();
  iVar2 = (**(code **)*puStack_14)(0x18,4,0xffffffff);
  Mutex__Unlock();
  uStack_10 = 0;
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)(iVar2 + 4);
    *puVar1 = 3;
    *(undefined4 *)(iVar2 + 8) = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    *(undefined4 *)(iVar2 + 0x14) = 1;
    iVar3 = Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar2);
    if (iVar3 < 0) {
      Csis__ClassHandle__Set(&PTR_s_ENV_STATIC_006f81c0);
      Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar2);
    }
    param_1[0xa0] = iVar2;
    ExceptionList = unaff_EBX;
    return;
  }
  param_1[0xa0] = 0;
  ExceptionList = unaff_EBX;
  return;
}


// ==== 0x53454b FUN_0053454b

void __fastcall FUN_0053454b(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  void *unaff_EBX;
  undefined4 *puStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*param_1 + 0x3c))();
  Csis__System__GetAllocator(&puStack_14);
  Mutex__Lock();
  iVar2 = (**(code **)*puStack_14)(0x18,4,0xffffffff);
  Mutex__Unlock();
  uStack_10 = 0;
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)(iVar2 + 4);
    *puVar1 = 3;
    *(undefined4 *)(iVar2 + 8) = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    *(undefined4 *)(iVar2 + 0x14) = 1;
    iVar3 = Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar2);
    if (iVar3 < 0) {
      Csis__ClassHandle__Set(&PTR_s_ENV_STATIC_006f81c0);
      Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar2);
    }
    param_1[0xa0] = iVar2;
    ExceptionList = unaff_EBX;
    return;
  }
  param_1[0xa0] = 0;
  ExceptionList = unaff_EBX;
  return;
}


// ==== 0x53454d FUN_0053454d

void __fastcall FUN_0053454d(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  void *unaff_EBX;
  undefined4 *puStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*param_1 + 0x3c))();
  Csis__System__GetAllocator(&puStack_14);
  Mutex__Lock();
  iVar2 = (**(code **)*puStack_14)(0x18,4,0xffffffff);
  Mutex__Unlock();
  uStack_10 = 0;
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)(iVar2 + 4);
    *puVar1 = 3;
    *(undefined4 *)(iVar2 + 8) = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    *(undefined4 *)(iVar2 + 0x14) = 1;
    iVar3 = Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar2);
    if (iVar3 < 0) {
      Csis__ClassHandle__Set(&PTR_s_ENV_STATIC_006f81c0);
      Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar2);
    }
    param_1[0xa0] = iVar2;
    ExceptionList = unaff_EBX;
    return;
  }
  param_1[0xa0] = 0;
  ExceptionList = unaff_EBX;
  return;
}


// ==== 0x53454e FUN_0053454e

void __fastcall FUN_0053454e(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  void *unaff_EBX;
  undefined4 *puStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*param_1 + 0x3c))();
  Csis__System__GetAllocator(&puStack_14);
  Mutex__Lock();
  iVar2 = (**(code **)*puStack_14)(0x18,4,0xffffffff);
  Mutex__Unlock();
  uStack_10 = 0;
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)(iVar2 + 4);
    *puVar1 = 3;
    *(undefined4 *)(iVar2 + 8) = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    *(undefined4 *)(iVar2 + 0x14) = 1;
    iVar3 = Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar2);
    if (iVar3 < 0) {
      Csis__ClassHandle__Set(&PTR_s_ENV_STATIC_006f81c0);
      Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar2);
    }
    param_1[0xa0] = iVar2;
    ExceptionList = unaff_EBX;
    return;
  }
  param_1[0xa0] = 0;
  ExceptionList = unaff_EBX;
  return;
}


// ==== 0x534550 FUN_00534550

void __fastcall FUN_00534550(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  void *unaff_EBX;
  undefined4 *puStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*param_1 + 0x3c))();
  Csis__System__GetAllocator(&puStack_14);
  Mutex__Lock();
  iVar2 = (**(code **)*puStack_14)(0x18,4,0xffffffff);
  Mutex__Unlock();
  uStack_10 = 0;
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)(iVar2 + 4);
    *puVar1 = 3;
    *(undefined4 *)(iVar2 + 8) = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    *(undefined4 *)(iVar2 + 0x14) = 1;
    iVar3 = Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar2);
    if (iVar3 < 0) {
      Csis__ClassHandle__Set(&PTR_s_ENV_STATIC_006f81c0);
      Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar2);
    }
    param_1[0xa0] = iVar2;
    ExceptionList = unaff_EBX;
    return;
  }
  param_1[0xa0] = 0;
  ExceptionList = unaff_EBX;
  return;
}


// ==== 0x534620 FUN_00534620

void __fastcall FUN_00534620(int param_1)

{
  int iVar1;
  int iStack_4;
  
  iStack_4 = param_1;
  SoundObject__Update();
  if (*(int *)(param_1 + 0x280) != 0) {
    iVar1 = *(int *)(param_1 + 0x4c);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0xffff < iVar1) {
      iVar1 = 0xffff;
    }
    *(int *)(*(int *)(param_1 + 0x280) + 0x10) = iVar1;
    *(undefined4 *)(*(int *)(param_1 + 0x280) + 0xc) = 0x1001;
    iVar1 = *(int *)(param_1 + 0x50) * DAT_006f4f3c >> 0xf;
    if (DAT_007356b0 < 4) {
      if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
        iVar1 = 0;
      }
      if ((DAT_007361f0 != (int *)0x0) && ((*DAT_007361f0 == 1 || (*DAT_007361f0 == 7)))) {
        iVar1 = 0;
      }
      iVar1 = *(int *)(DAT_007356b0 * 0xd10 + 0xab8 + DAT_007356ac) * iVar1 >> 0xf;
    }
    iVar1 = DAT_006f4f50 * iVar1 >> 0xf;
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    else if (0x7fff < iVar1) {
      iVar1 = 0x7fff;
    }
    *(int *)(*(int *)(param_1 + 0x280) + 8) = iVar1;
    if (**(int **)(param_1 + 0x280) != 0) {
      FUN_0064bc30(*(int **)(param_1 + 0x280) + 1);
    }
    iStack_4 = 0;
    if (**(int **)(param_1 + 0x280) != 0) {
      Csis__Class__GetRefCount(&iStack_4);
    }
  }
  return;
}


// ==== 0x534720 FUN_00534720

void FUN_00534720(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006be7c4;
  return;
}


// ==== 0x534730 FUN_00534730

void __fastcall FUN_00534730(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  
  if ((*(int *)(DAT_007356a8 + 0xf8) == 5) && (DAT_0078a2f0 == 0x3ec)) {
    SoundObject__Update();
    if (*(int *)(param_1 + 0xcc) == -0x55555556) {
      *(undefined4 *)(param_1 + 0xcc) = 0;
    }
    cVar5 = EAXS_3DMixer__IsInsideMinDistance();
    iVar3 = DAT_007356a8;
    if (cVar5 == '\x01') {
      *(undefined1 *)(DAT_007356a8 + 0x73) = 1;
      *(undefined1 *)(param_1 + 0x280) = 1;
      iVar3 = *(int *)(iVar3 + 0x104);
      if (iVar3 != 0) {
        uVar1 = *(undefined4 *)(param_1 + 0x244);
        uVar2 = *(undefined4 *)(param_1 + 0x248);
        *(undefined4 *)(iVar3 + 0x230) = *(undefined4 *)(param_1 + 0x240);
        *(undefined4 *)(iVar3 + 0x234) = uVar1;
        *(undefined4 *)(iVar3 + 0x238) = uVar2;
        return;
      }
    }
    else {
      iVar4 = *(int *)(DAT_007356a8 + 0x104);
      if (iVar4 != 0) {
        uVar1 = *(undefined4 *)(param_1 + 0x244);
        uVar2 = *(undefined4 *)(param_1 + 0x248);
        *(undefined4 *)(iVar4 + 0x230) = *(undefined4 *)(param_1 + 0x240);
        *(undefined4 *)(iVar4 + 0x234) = uVar1;
        *(undefined4 *)(iVar4 + 0x238) = uVar2;
      }
      *(undefined1 *)(iVar3 + 0x73) = 0;
    }
  }
  return;
}


// ==== 0x534800 FUN_00534800

void FUN_00534800(void)

{
  undefined4 in_EAX;
  undefined4 *unaff_ESI;
  
  SoundObject__SoundObject_WorldObject__(unaff_ESI,in_EAX);
  *(undefined1 *)(unaff_ESI + 0xa0) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x281) = 0;
  unaff_ESI[0xa2] = 0;
  *unaff_ESI = &PTR_FUN_006be3d0;
  return;
}


// ==== 0x534830 FUN_00534830

void * __thiscall FUN_00534830(void *param_1,byte param_2)

{
  FUN_00534850(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x534850 FUN_00534850

void FUN_00534850(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006852c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006be3d0;
  local_4 = 0;
  DAT_00735600 = 0;
  if ((undefined4 *)param_1[0xa2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xa2])(1);
    param_1[0xa2] = 0;
  }
  *param_1 = &PTR_FUN_006be7c4;
  ExceptionList = local_c;
  return;
}


// ==== 0x5348c0 FUN_005348c0

void __thiscall FUN_005348c0(int param_1,undefined4 param_2,char param_3)

{
  if (param_3 == '\0') {
    *(undefined4 *)(param_1 + 0x284) = param_2;
  }
  return;
}


// ==== 0x5348e0 FUN_005348e0

void __fastcall FUN_005348e0(int param_1)

{
  int iVar1;
  char cVar2;
  void *pvVar3;
  undefined4 uVar4;
  int extraout_EDX;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685fd3;
  local_c = ExceptionList;
  if (((*DAT_007361f0 == 4) && (*(int *)(DAT_007356a8 + 0xf8) == 2)) && (DAT_0078a2f0 == 0x4b1)) {
    ExceptionList = &local_c;
    SoundObject__Update();
    if (*(int *)(param_1 + 0xcc) == -0x55555556) {
      *(undefined4 *)(param_1 + 0xcc) = 0;
    }
    cVar2 = EAXS_3DMixer__IsInsideMinDistance();
    iVar1 = DAT_007356a8;
    if (cVar2 == '\x01') {
      *(undefined1 *)(DAT_007356a8 + 0x70) = 1;
      *(undefined1 *)(iVar1 + 0x72) = 0;
      if (*(char *)(param_1 + 0x280) == '\0') {
        pvVar3 = _malloc(0x280);
        local_4 = 0;
        if (pvVar3 == (void *)0x0) {
          uVar4 = 0;
        }
        else {
          uVar4 = SoundObject__SoundObject_WorldObject__(pvVar3,*(undefined4 *)(param_1 + 0x284));
        }
        local_4 = 0xffffffff;
        *(undefined4 *)(param_1 + 0x288) = uVar4;
      }
      *(undefined1 *)(param_1 + 0x280) = 1;
      uVar4 = FUN_00578710();
      FUN_00578710(uVar4);
      FUN_00520430(uVar4);
      ExceptionList = local_c;
      return;
    }
    uVar4 = FUN_00578710();
    FUN_00578710(uVar4);
    FUN_00520430(uVar4);
    *(undefined1 *)(extraout_EDX + 0x70) = 0;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x534a20 FUN_00534a20

void FUN_00534a20(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_FUN_006be3c4;
  eh_vector_constructor_iterator(unaff_ESI + 8,0x230,2,FUN_00535520,EAXS_3DMixer___EAXS_3DMixer);
  unaff_ESI[0x120] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[4] = 0;
  puVar1 = unaff_ESI + 0x8d;
  iVar2 = 2;
  do {
    puVar1[-1] = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 0x8c;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== 0x534a70 FUN_00534a70

void * __thiscall FUN_00534a70(void *param_1,byte param_2)

{
  FUN_00534ab0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x534a90 EAXS_3DMixer_derived_deleting_destructor__map:_EAXS_SoundShape::__

/* [canon] audio med (ghidra) docs/re/sound.md */

void * __thiscall
EAXS_3DMixer_derived_deleting_destructor__map__EAXS_SoundShape____(void *param_1,byte param_2)

{
  EAXS_3DMixer___EAXS_3DMixer();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x534ab0 FUN_00534ab0

void __fastcall FUN_00534ab0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *local_14;
  int *local_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006852a9;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = (int)&PTR_FUN_006be3c4;
  local_4 = 0;
  iVar2 = 2;
  piVar3 = param_1;
  local_10 = param_1;
  do {
    piVar3 = piVar3 + 0x8c;
    piVar1 = (int *)*piVar3;
    if (piVar1 != (int *)0x0) {
      if (*piVar1 != 0) {
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&local_14);
      Mutex__Lock();
      (**(code **)(*local_14 + 4))(piVar1);
      Mutex__Unlock();
      *piVar3 = 0;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  local_4 = 0xffffffff;
  eh_vector_destructor_iterator(param_1 + 8,0x230,2,EAXS_3DMixer___EAXS_3DMixer);
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x534b70 FUN_00534b70

void __thiscall FUN_00534b70(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  param_1[4] = (int)param_2;
  param_1[5] = 0;
  iVar2 = 2;
  do {
    piVar3 = param_1 + 0x8c;
    piVar1 = (int *)*piVar3;
    param_1[0x8d] = 0;
    param_1[0x8e] = 0;
    if (piVar1 != (int *)0x0) {
      if (*piVar1 != 0) {
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&param_2);
      Mutex__Lock();
      (**(code **)(*param_2 + 4))(piVar1);
      Mutex__Unlock();
      *piVar3 = 0;
    }
    iVar2 = iVar2 + -1;
    param_1 = piVar3;
  } while (iVar2 != 0);
  return;
}


// ==== 0x534be0 EAXS_WindNoise::UpdateChannels__map:_EAXS_VerticalCylinder::Update_

/* [canon] audio low (ghidra) docs/re/sound.md */

void EAXS_WindNoise__UpdateChannels__map__EAXS_VerticalCylinder__Update_(int param_1)

{
  int *piVar1;
  int iVar2;
  LARGE_INTEGER local_c;
  
  if (DAT_006f1dd8 != 0) {
    QueryPerformanceCounter(&local_c);
    piVar1 = (int *)(param_1 + 0x20);
    iVar2 = 2;
    do {
      if (piVar1[0x84] != 0) {
        (**(code **)(*piVar1 + 0x28))(piVar1[0x85],0);
      }
      piVar1 = piVar1 + 0x8c;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    FUN_00534c50(param_1);
  }
  return;
}


// ==== 0x534c45 FUN_00534c45

void __fastcall FUN_00534c45(char param_1)

{
  int unaff_EBP;
  
  *(char *)(unaff_EBP + 0x75) = *(char *)(unaff_EBP + 0x75) + param_1;
  return;
}


// ==== 0x534c50 FUN_00534c50

void FUN_00534c50(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int local_4;
  
  if (DAT_006f1dd8 != 0) {
    local_4 = 2;
    iVar3 = DAT_007356ac;
    piVar4 = DAT_007361f0;
    piVar1 = param_1;
    do {
      piVar5 = piVar1 + 0x8c;
      if (*piVar5 != 0) {
        iVar2 = (int)(((uint)(piVar1[0x8f] * 0x3fff) >> 0xf) * param_1[6]) >> 0xf;
        if (DAT_007356b0 < 4) {
          if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
            iVar2 = 0;
          }
          if ((piVar4 != (int *)0x0) && ((*piVar4 == 1 || (*piVar4 == 7)))) {
            iVar2 = 0;
          }
          iVar2 = *(int *)(DAT_007356b0 * 0xd10 + 0xab8 + iVar3) * iVar2 >> 0xf;
        }
        iVar2 = *(int *)(iVar3 + 0x3e1c) * iVar2 >> 0xf;
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        else if (0x7fff < iVar2) {
          iVar2 = 0x7fff;
        }
        *(int *)(*piVar5 + 8) = iVar2;
        iVar2 = piVar1[0x90];
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        else if (0x1fa0 < iVar2) {
          iVar2 = 0x1fa0;
        }
        *(int *)(*piVar5 + 0xc) = iVar2;
        iVar2 = piVar1[0x1b];
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        else if (0xffff < iVar2) {
          iVar2 = 0xffff;
        }
        *(int *)(*piVar5 + 0x10) = iVar2;
        if (*(int *)*piVar5 != 0) {
          FUN_0064bc30((int *)*piVar5 + 1);
          iVar3 = DAT_007356ac;
          piVar4 = DAT_007361f0;
        }
      }
      local_4 = local_4 + -1;
      piVar1 = piVar5;
    } while (local_4 != 0);
  }
  return;
}


// ==== 0x534d80 FUN_00534d80

void * __thiscall FUN_00534d80(void *param_1,byte param_2)

{
  FUN_00534da0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x534da0 FUN_00534da0

void __fastcall FUN_00534da0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006be3b0;
  FUN_00534ab0();
  return;
}


// ==== 0x534db0 FUN_00534db0

void __thiscall FUN_00534db0(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + 0x20);
  iVar2 = 2;
  do {
    (**(code **)(*piVar1 + 0x10))(&DAT_006f4c00);
    (**(code **)(*piVar1 + 0x24))();
    piVar1 = piVar1 + 0x8c;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_00534b70(param_2);
  return;
}


// ==== 0x534df0 FUN_00534df0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00534df0(int param_1,int *param_2,undefined4 *param_3)

{
  ulonglong uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  float10 extraout_ST0;
  float10 fVar8;
  LARGE_INTEGER local_18;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_00684d6b;
  local_10 = ExceptionList;
  if (DAT_006f1dd8 != 0) {
    iVar4 = 0;
    piVar2 = (int *)(param_1 + 0x234);
    do {
      if ((piVar2[-1] != 0) && (param_2 == (int *)*piVar2)) {
        return;
      }
      iVar4 = iVar4 + 1;
      piVar2 = piVar2 + 0x8c;
    } while (iVar4 < 2);
    ExceptionList = &local_10;
    *(int **)(*(int *)(param_1 + 0x480) * 0x230 + 0x234 + param_1) = param_2;
    piVar2 = *(int **)((*(int *)(param_1 + 0x480) + 1) * 0x230 + param_1);
    if (piVar2 != (int *)0x0) {
      if (*piVar2 != 0) {
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&param_2);
      Mutex__Lock();
      (**(code **)(*param_2 + 4))(piVar2);
      Mutex__Unlock();
      *(undefined4 *)((*(int *)(param_1 + 0x480) + 1) * 0x230 + param_1) = 0;
    }
    uVar1 = (ulonglong)DAT_006f227c;
    uVar5 = DAT_006f227c ^ 0x1d872b41;
    uVar6 = uVar5 >> 5 ^ uVar5;
    DAT_006f227c = uVar6 << 0x1b ^ uVar6 ^ uVar5;
    switch((int)((uVar1 % 1000) % 5)) {
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
    }
    iVar4 = *(int *)(param_1 + 0x480) * 0x230 + param_1;
    (**(code **)(*(int *)(iVar4 + 0x20) + 0x28))(*(undefined4 *)(iVar4 + 0x234),0);
    iVar7 = *(int *)(param_1 + 0x480) * 0x230;
    iVar4 = *(int *)(iVar7 + 0x6c + param_1);
    *(int *)(param_1 + 0x18) = iVar4;
    if (0x7fff < iVar4) {
      *(int *)(param_1 + 0x18) = 0xffff - iVar4;
    }
    *(uint *)(param_1 + 0x18) = (0x3fff - (*(uint *)(param_1 + 0x18) & 0x3fff)) * 2;
    if (40.0 < (float)param_3) {
      param_3 = (undefined4 *)0x42200000;
    }
    if ((float)param_3 < 18.0 != ((float)param_3 == 18.0)) {
      param_3 = (undefined4 *)&DAT_41900000;
    }
    uVar3 = _ftol_nocw();
    fVar8 = (float10)_K_ONE;
    *(undefined4 *)(iVar7 + param_1 + 0x240) = uVar3;
    iVar7 = (**(code **)(*(int *)(*(int *)(param_1 + 0x480) * 0x230 + 0x20 + param_1) + 4))
                      (0,(float)(fVar8 - extraout_ST0));
    iVar4 = *(int *)(param_1 + 0x480) * 0x230 + param_1;
    *(int *)(iVar4 + 0x23c) =
         *(int *)(iVar4 + 0x70) * (iVar7 * *(int *)(param_1 + 0x18) >> 0xf) >> 0xf;
    if (*(int *)(*(int *)(param_1 + 0x480) * 0x230 + 0x23c + param_1) != 0) {
      Csis__System__GetAllocator(&param_3);
      Mutex__Lock();
      iVar4 = (**(code **)*param_3)(0x18,4,0xffffffff);
      Mutex__Unlock();
      local_8 = 0;
      param_3 = (undefined4 *)iVar4;
      if (iVar4 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = FUN_00524870(*(undefined4 *)(*(int *)(param_1 + 0x480) * 0x230 + 0x6c + param_1),0);
      }
      *(undefined4 *)((*(int *)(param_1 + 0x480) + 1) * 0x230 + param_1) = uVar3;
      QueryPerformanceCounter(&local_18);
      uVar3 = __allshr();
      *(undefined4 *)(*(int *)(param_1 + 0x480) * 0x230 + 0x238 + param_1) = uVar3;
    }
    iVar4 = *(int *)(param_1 + 0x480) + 1;
    *(int *)(param_1 + 0x480) = iVar4;
    if (1 < iVar4) {
      *(undefined4 *)(param_1 + 0x480) = 0;
    }
  }
  ExceptionList = local_10;
  return;
}


// ==== 0x535130 FUN_00535130

void * __thiscall FUN_00535130(void *param_1,byte param_2)

{
  FUN_00535150();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x535150 FUN_00535150

void __fastcall FUN_00535150(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006be310;
  FUN_00534ab0();
  return;
}


// ==== 0x535160 FUN_00535160

undefined4 __fastcall FUN_00535160(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + 0x20);
  iVar2 = 2;
  do {
    (**(code **)(*piVar1 + 0x24))();
    piVar1 = piVar1 + 0x8c;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}


// ==== 0x535190 FUN_00535190

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00535190(int param_1,int *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  float10 extraout_ST0;
  float10 fVar9;
  LARGE_INTEGER local_18;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_00684d4b;
  local_10 = ExceptionList;
  if (DAT_006f1dd8 != 0) {
    iVar5 = 0;
    piVar2 = (int *)(param_1 + 0x234);
    do {
      if ((piVar2[-1] != 0) && (param_2 == (int *)*piVar2)) {
        return;
      }
      iVar5 = iVar5 + 1;
      piVar2 = piVar2 + 0x8c;
    } while (iVar5 < 2);
    ExceptionList = &local_10;
    *(int **)(*(int *)(param_1 + 0x480) * 0x230 + 0x234 + param_1) = param_2;
    piVar2 = *(int **)((*(int *)(param_1 + 0x480) + 1) * 0x230 + param_1);
    if (piVar2 != (int *)0x0) {
      if (*piVar2 != 0) {
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&param_2);
      Mutex__Lock();
      (**(code **)(*param_2 + 4))(piVar2);
      Mutex__Unlock();
      *(undefined4 *)((*(int *)(param_1 + 0x480) + 1) * 0x230 + param_1) = 0;
    }
    uVar6 = DAT_006f227c ^ 0x1d872b41;
    uVar7 = uVar6 >> 5 ^ uVar6;
    DAT_006f227c = uVar7 << 0x1b ^ uVar7 ^ uVar6;
    iVar5 = *(int *)(param_1 + 0x480) * 0x230 + param_1;
    (**(code **)(*(int *)(iVar5 + 0x20) + 0x28))(*(undefined4 *)(iVar5 + 0x234),0);
    iVar8 = *(int *)(param_1 + 0x480) * 0x230;
    iVar5 = *(int *)(iVar8 + 0x6c + param_1);
    *(int *)(param_1 + 0x18) = iVar5;
    if (0x7fff < iVar5) {
      *(int *)(param_1 + 0x18) = 0xffff - iVar5;
    }
    *(uint *)(param_1 + 0x18) = (0x3fff - (*(uint *)(param_1 + 0x18) & 0x3fff)) * 2;
    if (40.0 < (float)param_3) {
      param_3 = (undefined4 *)0x42200000;
    }
    if ((float)param_3 < 18.0 != ((float)param_3 == 18.0)) {
      param_3 = (undefined4 *)&DAT_41900000;
    }
    uVar3 = _ftol_nocw();
    fVar9 = (float10)_K_ONE;
    *(undefined4 *)(iVar8 + param_1 + 0x240) = uVar3;
    iVar8 = (**(code **)(*(int *)(*(int *)(param_1 + 0x480) * 0x230 + 0x20 + param_1) + 4))
                      (0,(float)(fVar9 - extraout_ST0));
    iVar5 = *(int *)(param_1 + 0x480) * 0x230 + param_1;
    *(int *)(iVar5 + 0x23c) =
         *(int *)(iVar5 + 0x70) * (iVar8 * *(int *)(param_1 + 0x18) >> 0xf) >> 0xf;
    if ((uint)(*(int *)(*(int *)(param_1 + 0x480) * 0x230 + 0x23c + param_1) *
              *(int *)(param_1 + 0x18)) >> 0xf != 0) {
      Csis__System__GetAllocator(&param_3);
      Mutex__Lock();
      iVar5 = (**(code **)*param_3)(0x18,4,0xffffffff);
      Mutex__Unlock();
      local_8 = 0;
      param_2 = (int *)iVar5;
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar4 = *(int *)(param_1 + 0x480) * 0x230;
        iVar8 = *(int *)(iVar4 + 0x6c + param_1);
        iVar4 = *(int *)(iVar4 + param_1 + 0x240);
        puVar1 = (undefined4 *)(iVar5 + 4);
        *puVar1 = 8;
        *(undefined4 *)(iVar5 + 8) = 0;
        if (iVar4 < 0) {
          iVar4 = 0;
        }
        else if (0x1fa0 < iVar4) {
          iVar4 = 0x1fa0;
        }
        *(int *)(iVar5 + 0xc) = iVar4;
        if (iVar8 < 0) {
          iVar8 = 0;
        }
        else if (0xffff < iVar8) {
          iVar8 = 0xffff;
        }
        *(int *)(iVar5 + 0x10) = iVar8;
        *(undefined4 *)(iVar5 + 0x14) = 0;
        iVar8 = Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar5);
        if (iVar8 < 0) {
          Csis__ClassHandle__Set(&PTR_s_ENV_STATIC_006f81c0);
          Csis__Class__CreateInstance(&DAT_00744220,puVar1,iVar5);
        }
      }
      *(int *)((*(int *)(param_1 + 0x480) + 1) * 0x230 + param_1) = iVar5;
      QueryPerformanceCounter(&local_18);
      uVar3 = __allshr();
      *(undefined4 *)(*(int *)(param_1 + 0x480) * 0x230 + 0x238 + param_1) = uVar3;
    }
    iVar5 = *(int *)(param_1 + 0x480) + 1;
    *(int *)(param_1 + 0x480) = iVar5;
    if (1 < iVar5) {
      *(undefined4 *)(param_1 + 0x480) = 0;
    }
  }
  ExceptionList = local_10;
  return;
}


// ==== 0x535500 FUN_00535500

void * __thiscall FUN_00535500(void *param_1,byte param_2)

{
  FUN_00535530();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x535520 FUN_00535520

void FUN_00535520(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)EAXS_3DMixer__EAXS_3DMixer();
  *puVar1 = &PTR_EAXS_3DMixer_derived_deleting_destructor__map__EAXS_SoundShape_____006be798;
  return;
}


// ==== 0x535530 FUN_00535530

void __fastcall FUN_00535530(undefined4 *param_1)

{
  int *piVar1;
  int *local_14;
  undefined4 *local_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068527b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006be3c0;
  piVar1 = (int *)param_1[0x3d];
  local_4 = 0;
  local_10 = param_1;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_14);
    Mutex__Lock();
    (**(code **)(*local_14 + 4))(piVar1);
    Mutex__Unlock();
    param_1[0x3d] = 0;
  }
  local_4 = 0xffffffff;
  eh_vector_destructor_iterator(param_1 + 0x40,0x220,2,EAXS_3DMixer___EAXS_3DMixer);
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x5355d0 FUN_005355d0

void FUN_005355d0(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  LARGE_INTEGER local_14;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  puVar2 = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d4b;
  local_c = ExceptionList;
  if (DAT_006f1dd8 != 0) {
    ExceptionList = &local_c;
    *(undefined1 *)(param_1 + 4) = 1;
    QueryPerformanceCounter(&local_14);
    uVar3 = __allshr();
    puVar2[0x38] = uVar3;
    *(undefined1 *)((int)puVar2 + 0x11) = 0;
    puVar2[5] = param_2;
    Csis__System__GetAllocator(&param_1);
    Mutex__Lock();
    iVar4 = (**(code **)*param_1)(0x20,4,0xffffffff);
    Mutex__Unlock();
    uStack_4 = 0;
    param_2 = iVar4;
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      puVar1 = (undefined4 *)(iVar4 + 4);
      *puVar1 = 0;
      *(undefined4 *)(iVar4 + 8) = 0;
      *(undefined4 *)(iVar4 + 0xc) = 0x1000;
      *(undefined4 *)(iVar4 + 0x10) = 0;
      *(undefined4 *)(iVar4 + 0x14) = 0;
      *(undefined4 *)(iVar4 + 0x18) = 0;
      *(undefined4 *)(iVar4 + 0x1c) = 0;
      iVar5 = Csis__Class__CreateInstance(&DAT_00744228,puVar1,iVar4);
      if (iVar5 < 0) {
        Csis__ClassHandle__Set(&PTR_s_FX_WIND_006f81c8);
        Csis__Class__CreateInstance(&DAT_00744228,puVar1,iVar4);
      }
    }
    puVar2[0x3d] = iVar4;
    uStack_4 = 0xffffffff;
    uVar7 = 0;
    piVar6 = puVar2 + 0x40;
    do {
      piVar6[0x84] = uVar7 & 1;
      (**(code **)(*piVar6 + 0x10))(&DAT_006f4c70);
      (**(code **)(*piVar6 + 0x24))();
      uVar7 = uVar7 + 1;
      piVar6 = piVar6 + 0x88;
    } while ((int)uVar7 < 2);
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x535710 EAXS_WindNoise::Update

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXS_WindNoise__Update(void)

{
  int iVar1;
  undefined4 uVar2;
  float *pfVar3;
  int *piVar4;
  int unaff_ESI;
  float10 extraout_ST0;
  float10 fVar5;
  float10 fVar6;
  int local_34;
  LARGE_INTEGER local_30 [2];
  float local_20;
  float local_1c;
  float fStack_18;
  
  QueryPerformanceCounter(local_30);
  uVar2 = DAT_007349c8;
  local_34 = __allshr();
  local_34 = local_34 - *(int *)(unaff_ESI + 0xe0);
  if (local_34 < 0) {
    local_34 = 0;
  }
  local_30[0]._0_4_ = 1 << ((byte)uVar2 & 0x1f);
  *(float *)(unaff_ESI + 0xdc) = (float)(int)local_30[0]._0_4_ * (float)local_34 * _DAT_007301d0;
  QueryPerformanceCounter(local_30);
  uVar2 = __allshr();
  *(undefined4 *)(unaff_ESI + 0xe0) = uVar2;
  if (DAT_00740500 != 0) {
    iVar1 = *(int *)(*(int *)(unaff_ESI + 0x14) + 0x234);
    uVar2 = _ftol_nocw();
    *(undefined4 *)(unaff_ESI + 0x314) = uVar2;
    _ftol_nocw();
    uVar2 = _ftol_nocw();
    fVar5 = (float10)_K_ONE;
    *(undefined4 *)(unaff_ESI + 0xf0) = uVar2;
    fVar5 = (fVar5 - extraout_ST0) * (float10)65.0;
    *(float *)(unaff_ESI + 0xec) = (float)fVar5;
    if (fVar5 < (float10)*(float *)(*(int *)(unaff_ESI + 0x14) + 0x260)) {
      *(float *)(unaff_ESI + 0xec) = *(float *)(*(int *)(unaff_ESI + 0x14) + 0x260) * 1.01;
    }
    fVar5 = (float10)FUN_00564b10();
    fVar6 = (float10)FUN_00564b10();
    local_30[0]._0_4_ =
         (undefined4)
         (((float10)(float)fVar5 * (float10)*(float *)(iVar1 + 0x90) -
          fVar6 * (float10)*(float *)(iVar1 + 0x94)) * (float10)*(float *)(unaff_ESI + 0xec));
    local_30[0]._4_4_ =
         (undefined4)
         ((fVar6 * (float10)*(float *)(iVar1 + 0x90) +
          (float10)(float)fVar5 * (float10)*(float *)(iVar1 + 0x94)) *
         (float10)*(float *)(unaff_ESI + 0xec));
    fVar5 = (float10)FUN_00564b10();
    fVar6 = (float10)FUN_00564b10();
    piVar4 = (int *)(unaff_ESI + 0x100);
    local_20 = (float)(((float10)(float)fVar5 * (float10)*(float *)(iVar1 + 0x90) -
                       fVar6 * (float10)*(float *)(iVar1 + 0x94)) *
                      (float10)*(float *)(unaff_ESI + 0xec));
    local_34 = 2;
    local_1c = (float)((fVar6 * (float10)*(float *)(iVar1 + 0x90) +
                       (float10)(float)fVar5 * (float10)*(float *)(iVar1 + 0x94)) *
                      (float10)*(float *)(unaff_ESI + 0xec));
    do {
      if (piVar4[0x84] == 0) {
        pfVar3 = (float *)(unaff_ESI + 0x80);
        *pfVar3 = (float)local_30[0]._0_4_ + *(float *)(iVar1 + 0x60);
        *(float *)(unaff_ESI + 0x84) = (float)local_30[0]._4_4_ + *(float *)(iVar1 + 100);
        *(undefined4 *)(unaff_ESI + 0x88) = *(undefined4 *)(iVar1 + 0x68);
      }
      else {
        pfVar3 = (float *)(unaff_ESI + 0x90);
        *pfVar3 = local_20 + *(float *)(iVar1 + 0x60);
        *(float *)(unaff_ESI + 0x94) = local_1c + *(float *)(iVar1 + 100);
        *(undefined4 *)(unaff_ESI + 0x98) = *(undefined4 *)(iVar1 + 0x68);
      }
      (**(code **)(*piVar4 + 0x28))(pfVar3,0);
      piVar4 = piVar4 + 0x88;
      local_34 = local_34 + -1;
    } while (local_34 != 0);
    if (*(char *)(unaff_ESI + 0x11) == '\x01') {
      if (*(char *)(unaff_ESI + 0xd0) != '\0') {
        *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(unaff_ESI + 0x90);
        *(undefined4 *)(unaff_ESI + 0x24) = *(undefined4 *)(unaff_ESI + 0x94);
        *(undefined4 *)(unaff_ESI + 0x28) = *(undefined4 *)(unaff_ESI + 0x98);
      }
      if (*(float *)(unaff_ESI + 0xc0) <
          (*(float *)(unaff_ESI + 0xd4) / *(float *)(unaff_ESI + 200)) *
          *(float *)(unaff_ESI + 0xc0)) {
        if (*(char *)(unaff_ESI + 0xd0) == '\0') {
          fVar5 = (float10)bDistance3();
          fStack_18 = *(float *)(unaff_ESI + 0x88) - *(float *)(unaff_ESI + 0x48);
          *(float *)(unaff_ESI + 0xa0) = *(float *)(unaff_ESI + 0x80) - *(float *)(unaff_ESI + 0x40)
          ;
          *(float *)(unaff_ESI + 0xa8) = fStack_18;
          *(float *)(unaff_ESI + 0xa4) = *(float *)(unaff_ESI + 0x84) - *(float *)(unaff_ESI + 0x44)
          ;
          fVar6 = (fVar5 / (float10)*(float *)(unaff_ESI + 0xc0)) *
                  (float10)*(float *)(unaff_ESI + 200);
          *(float *)(unaff_ESI + 200) = (float)fVar6;
          local_30[0]._0_4_ = *(float *)(unaff_ESI + 0xa8);
          fVar6 = (float10)_K_ONE / fVar6;
          *(float *)(unaff_ESI + 0xa0) = (float)(fVar6 * (float10)*(float *)(unaff_ESI + 0xa0));
          *(float *)(unaff_ESI + 0xa4) = (float)((float10)*(float *)(unaff_ESI + 0xa4) * fVar6);
          *(float *)(unaff_ESI + 0xa8) = (float)((float10)(float)local_30[0]._0_4_ * fVar6);
          *(undefined1 *)(unaff_ESI + 0xd0) = 1;
          *(undefined4 *)(unaff_ESI + 0xd4) = 0;
          *(float *)(unaff_ESI + 0xc0) = (float)fVar5;
          *(float *)(unaff_ESI + 0x20) = *(float *)(unaff_ESI + 0x80);
          *(undefined4 *)(unaff_ESI + 0x24) = *(undefined4 *)(unaff_ESI + 0x84);
          *(undefined4 *)(unaff_ESI + 0x28) = *(undefined4 *)(unaff_ESI + 0x88);
        }
        else if (*(char *)(unaff_ESI + 0xd1) == '\x01') {
          *(undefined1 *)(unaff_ESI + 0x11) = 0;
        }
      }
      *(float *)(unaff_ESI + 0x40) = *(float *)(unaff_ESI + 0x40) + *(float *)(unaff_ESI + 0xa0);
      *(float *)(unaff_ESI + 0x44) = *(float *)(unaff_ESI + 0xa4) + *(float *)(unaff_ESI + 0x44);
      *(float *)(unaff_ESI + 0x48) = *(float *)(unaff_ESI + 0xa8) + *(float *)(unaff_ESI + 0x48);
      if (*(char *)(unaff_ESI + 0xd1) == '\x01') {
        *(undefined4 *)(unaff_ESI + 0x30) = *(undefined4 *)(unaff_ESI + 0x90);
        *(undefined4 *)(unaff_ESI + 0x34) = *(undefined4 *)(unaff_ESI + 0x94);
        *(undefined4 *)(unaff_ESI + 0x38) = *(undefined4 *)(unaff_ESI + 0x98);
      }
      if (*(float *)(unaff_ESI + 0xc4) <
          (*(float *)(unaff_ESI + 0xd8) / *(float *)(unaff_ESI + 0xcc)) *
          *(float *)(unaff_ESI + 0xc4)) {
        if (*(char *)(unaff_ESI + 0xd1) == '\0') {
          pfVar3 = (float *)(unaff_ESI + 0x90);
          fVar5 = (float10)bDistance3();
          fStack_18 = *(float *)(unaff_ESI + 0x98) - *(float *)(unaff_ESI + 0x58);
          *(float *)(unaff_ESI + 0xb0) = *pfVar3 - *(float *)(unaff_ESI + 0x50);
          *(float *)(unaff_ESI + 0xb8) = fStack_18;
          *(float *)(unaff_ESI + 0xb4) = *(float *)(unaff_ESI + 0x94) - *(float *)(unaff_ESI + 0x54)
          ;
          fVar6 = (fVar5 / (float10)*(float *)(unaff_ESI + 0xc4)) *
                  (float10)*(float *)(unaff_ESI + 0xcc);
          *(float *)(unaff_ESI + 0xcc) = (float)fVar6;
          local_30[0]._0_4_ = *(float *)(unaff_ESI + 0xb8);
          fVar6 = (float10)_K_ONE / fVar6;
          *(float *)(unaff_ESI + 0xb0) = (float)(fVar6 * (float10)*(float *)(unaff_ESI + 0xb0));
          *(float *)(unaff_ESI + 0xb4) = (float)((float10)*(float *)(unaff_ESI + 0xb4) * fVar6);
          *(float *)(unaff_ESI + 0xb8) = (float)((float10)(float)local_30[0]._0_4_ * fVar6);
          *(undefined1 *)(unaff_ESI + 0xd1) = 1;
          *(undefined4 *)(unaff_ESI + 0xd8) = 0;
          *(float *)(unaff_ESI + 0xc4) = (float)fVar5;
          *pfVar3 = *pfVar3;
          *(undefined4 *)(unaff_ESI + 0x94) = *(undefined4 *)(unaff_ESI + 0x94);
          *(undefined4 *)(unaff_ESI + 0x98) = *(undefined4 *)(unaff_ESI + 0x98);
        }
        else if (*(char *)(unaff_ESI + 0xd0) == '\x01') {
          *(undefined1 *)(unaff_ESI + 0x11) = 0;
        }
      }
      pfVar3 = (float *)(unaff_ESI + 0x50);
      piVar4 = (int *)(unaff_ESI + 0x100);
      local_34 = 2;
      *pfVar3 = *pfVar3 + *(float *)(unaff_ESI + 0xb0);
      *(float *)(unaff_ESI + 0x54) = *(float *)(unaff_ESI + 0xb4) + *(float *)(unaff_ESI + 0x54);
      *(float *)(unaff_ESI + 0x58) = *(float *)(unaff_ESI + 0xb8) + *(float *)(unaff_ESI + 0x58);
      do {
        if (piVar4[0x84] == 0) {
          (**(code **)(*piVar4 + 0x28))(unaff_ESI + 0x40);
        }
        else {
          (**(code **)(*piVar4 + 0x28))(pfVar3,0);
        }
        piVar4 = piVar4 + 0x88;
        local_34 = local_34 + -1;
      } while (local_34 != 0);
      *(float *)(unaff_ESI + 0xd8) = *(float *)(unaff_ESI + 0xd8) + *(float *)(unaff_ESI + 0xdc);
      *(float *)(unaff_ESI + 0xd4) = *(float *)(unaff_ESI + 0xd4) + *(float *)(unaff_ESI + 0xdc);
    }
    EAXS_WindNoise__UpdateCSISParams();
  }
  return;
}


// ==== 0x535c90 EAXS_WindNoise::UpdateCSISParams

/* [canon] audio med (ghidra) docs/re/sound.md */

void EAXS_WindNoise__UpdateCSISParams(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(in_EAX + 0x14) + 0x264);
  iVar2 = *(int *)(in_EAX + 0x150) * *(int *)(in_EAX + 0xf0) >> 0xf;
  iVar1 = *(int *)(in_EAX + 0x370) * *(int *)(in_EAX + 0xf0) >> 0xf;
  if (iVar3 < 4) {
    if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
      iVar2 = 0;
    }
    if ((DAT_007361f0 != (int *)0x0) && ((*DAT_007361f0 == 1 || (*DAT_007361f0 == 7)))) {
      iVar2 = 0;
    }
    iVar2 = *(int *)(iVar3 * 0xd10 + 0x728 + DAT_007356ac) * iVar2 >> 0xf;
    if (iVar3 < 4) {
      if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
        iVar1 = 0;
      }
      if ((DAT_007361f0 != (int *)0x0) && ((*DAT_007361f0 == 1 || (*DAT_007361f0 == 7)))) {
        iVar1 = 0;
      }
      iVar1 = *(int *)(iVar3 * 0xd10 + 0x728 + DAT_007356ac) * iVar1 >> 0xf;
    }
  }
  iVar3 = *(int *)(DAT_007356ac + 0x3e18) * iVar2 >> 0xf;
  iVar1 = *(int *)(DAT_007356ac + 0x3e18) * iVar1 >> 0xf;
  if (((*(int *)(*(int *)(in_EAX + 0x14) + 0x2b0) != 2) && (DAT_0078a344 == '\0')) &&
     (DAT_007361a8 == 0)) {
    iVar3 = iVar3 * 11000 >> 0xf;
    iVar1 = iVar1 * 11000 >> 0xf;
  }
  iVar2 = DAT_006f4f58 * iVar3 >> 0xf;
  iVar3 = DAT_006f4f58 * iVar1 >> 0xf;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  else if (0x7fff < iVar2) {
    iVar2 = 0x7fff;
  }
  *(int *)(*(int *)(in_EAX + 0xf4) + 8) = iVar2;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  else if (0x7fff < iVar3) {
    iVar3 = 0x7fff;
  }
  *(int *)(*(int *)(in_EAX + 0xf4) + 0x14) = iVar3;
  *(undefined4 *)(*(int *)(in_EAX + 0xf4) + 0xc) = 0x1000;
  iVar3 = *(int *)(in_EAX + 0x14c);
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  else if (0xffff < iVar3) {
    iVar3 = 0xffff;
  }
  *(int *)(*(int *)(in_EAX + 0xf4) + 0x10) = iVar3;
  iVar3 = *(int *)(in_EAX + 0x36c);
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  else if (0xffff < iVar3) {
    iVar3 = 0xffff;
  }
  *(int *)(*(int *)(in_EAX + 0xf4) + 0x18) = iVar3;
  iVar3 = *(int *)(in_EAX + 0x314);
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  else if (0x410 < iVar3) {
    iVar3 = 0x410;
  }
  *(int *)(*(int *)(in_EAX + 0xf4) + 0x1c) = iVar3;
  if (**(int **)(in_EAX + 0xf4) != 0) {
    FUN_0064bc30(*(int **)(in_EAX + 0xf4) + 1);
  }
  return;
}


// ==== 0x535e90 EAXS_WindNoise::SetupSoundSphere

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void __thiscall EAXS_WindNoise__SetupSoundSphere(undefined4 *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  int unaff_ESI;
  float10 fVar5;
  LARGE_INTEGER local_8;
  
  if ((*(char *)(unaff_ESI + 0x11) != '\x01') && (18.8 <= param_2)) {
    *(float *)(unaff_ESI + 0xe8) = param_2;
    if (70.0 < param_2) {
      *(undefined4 *)(unaff_ESI + 0xe8) = 0x428c0000;
    }
    if (*(float *)(unaff_ESI + 0xe8) < 2.0) {
      *(undefined4 *)(unaff_ESI + 0xe8) = 0x40000000;
    }
    *(undefined1 *)(unaff_ESI + 0x11) = 1;
    Atan2ToAngle16(*param_1,param_1[1]);
    fVar1 = *(float *)(*(int *)(unaff_ESI + 0x14) + 0x260);
    *(undefined4 *)(unaff_ESI + 0x44) = *(undefined4 *)(unaff_ESI + 0x84);
    *(undefined4 *)(unaff_ESI + 0x40) = *(undefined4 *)(unaff_ESI + 0x80);
    *(undefined4 *)(unaff_ESI + 0x48) = *(undefined4 *)(unaff_ESI + 0x88);
    *(undefined4 *)(unaff_ESI + 0x50) = *(undefined4 *)(unaff_ESI + 0x90);
    *(undefined4 *)(unaff_ESI + 0x54) = *(undefined4 *)(unaff_ESI + 0x94);
    *(undefined4 *)(unaff_ESI + 0x58) = *(undefined4 *)(unaff_ESI + 0x98);
    fVar5 = (float10)FUN_00564b10();
    *(float *)(unaff_ESI + 0x24) =
         (float)(fVar5 * (float10)fVar1 + (float10)*(float *)(extraout_EDX + 0x254));
    fVar5 = (float10)FUN_00564b10();
    *(float *)(unaff_ESI + 0x20) =
         (float)(fVar5 * (float10)fVar1 + (float10)*(float *)(extraout_EDX_00 + 0x250));
    *(undefined4 *)(unaff_ESI + 0x28) = *(undefined4 *)(extraout_EDX_00 + 600);
    fVar5 = (float10)FUN_00564b10();
    *(float *)(unaff_ESI + 0x34) =
         (float)(fVar5 * (float10)fVar1 + (float10)*(float *)(extraout_EDX_01 + 0x254));
    fVar5 = (float10)FUN_00564b10();
    *(float *)(unaff_ESI + 0x30) =
         (float)(fVar5 * (float10)fVar1 + (float10)*(float *)(extraout_EDX_02 + 0x250));
    *(undefined4 *)(unaff_ESI + 0x38) = *(undefined4 *)(extraout_EDX_02 + 600);
    fVar1 = *(float *)(unaff_ESI + 0x20) - *(float *)(unaff_ESI + 0x40);
    fVar2 = *(float *)(unaff_ESI + 0x24) - *(float *)(unaff_ESI + 0x44);
    fVar3 = *(float *)(unaff_ESI + 0x28) - *(float *)(unaff_ESI + 0x48);
    *(float *)(unaff_ESI + 0xc0) = SQRT(fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3) + _K_ONE;
    fVar1 = *(float *)(unaff_ESI + 0x30) - *(float *)(unaff_ESI + 0x50);
    fVar3 = *(float *)(unaff_ESI + 0x34) - *(float *)(unaff_ESI + 0x54);
    fVar2 = *(float *)(unaff_ESI + 0x38) - *(float *)(unaff_ESI + 0x58);
    *(float *)(unaff_ESI + 0xc4) = SQRT(fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2) + _K_ONE;
    *(float *)(unaff_ESI + 0xa0) = *(float *)(unaff_ESI + 0x20) - *(float *)(unaff_ESI + 0x40);
    *(float *)(unaff_ESI + 0xa4) = *(float *)(unaff_ESI + 0x24) - *(float *)(unaff_ESI + 0x44);
    *(float *)(unaff_ESI + 0xa8) = *(float *)(unaff_ESI + 0x28) - *(float *)(unaff_ESI + 0x48);
    *(float *)(unaff_ESI + 0xb0) = *(float *)(unaff_ESI + 0x30) - *(float *)(unaff_ESI + 0x50);
    *(float *)(unaff_ESI + 0xb4) = *(float *)(unaff_ESI + 0x34) - *(float *)(unaff_ESI + 0x54);
    *(float *)(unaff_ESI + 0xb8) = *(float *)(unaff_ESI + 0x38) - *(float *)(unaff_ESI + 0x58);
    fVar1 = _K_ONE / *(float *)(unaff_ESI + 0xe8);
    *(float *)(unaff_ESI + 0xcc) = fVar1 * *(float *)(unaff_ESI + 0xc0) * 1.0 * 1000.0;
    fVar1 = fVar1 * *(float *)(unaff_ESI + 0xc4) * 1.0 * 1000.0;
    *(float *)(unaff_ESI + 200) = fVar1;
    fVar1 = _K_ONE / fVar1;
    *(float *)(unaff_ESI + 0xa0) = fVar1 * *(float *)(unaff_ESI + 0xa0);
    *(float *)(unaff_ESI + 0xa4) = *(float *)(unaff_ESI + 0xa4) * fVar1;
    *(float *)(unaff_ESI + 0xa8) = *(float *)(unaff_ESI + 0xa8) * fVar1;
    fVar1 = _K_ONE / *(float *)(unaff_ESI + 0xcc);
    *(float *)(unaff_ESI + 0xb0) = fVar1 * *(float *)(unaff_ESI + 0xb0);
    *(float *)(unaff_ESI + 0xb4) = *(float *)(unaff_ESI + 0xb4) * fVar1;
    *(float *)(unaff_ESI + 0xb8) = *(float *)(unaff_ESI + 0xb8) * fVar1;
    *(undefined4 *)(unaff_ESI + 0xd4) = 0;
    *(undefined4 *)(unaff_ESI + 0xd8) = 0;
    QueryPerformanceCounter(&local_8);
    uVar4 = __allshr();
    *(undefined1 *)(unaff_ESI + 0xd0) = 0;
    *(undefined1 *)(unaff_ESI + 0xd1) = 0;
    *(undefined4 *)(unaff_ESI + 0xe0) = uVar4;
  }
  return;
}


// ==== 0x5361d0 FUN_005361d0

undefined4 * __fastcall FUN_005361d0(undefined4 *param_1)

{
  int extraout_EDX;
  
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xc] = 0;
  param_1[0xb] = 0;
  param_1[4] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  FUN_00532640();
  *(undefined1 *)(param_1 + 0x2b) = 1;
  FUN_00532640();
  *(undefined1 *)(extraout_EDX + 0x78) = 1;
  FUN_00532640();
  FUN_00532670(0,0,0,0);
  param_1[0x2a] = 0;
  *(undefined1 *)(param_1 + 0x4b) = 0;
  *param_1 = 0x3fe6;
  param_1[1] = 0x3fe6;
  return param_1;
}


// ==== 0x536250 EAXChannel::ReceiveEnvelopeEvent

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXChannel__ReceiveEnvelopeEvent(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_a8 [8];
  undefined1 local_7c [124];
  
  puVar1 = (undefined4 *)&stack0x00000008;
  puVar3 = (undefined4 *)(param_1 + 8);
  for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)(param_1 + 0x14);
  puVar3 = auStack_a8;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)EAXChannel__GenerateEnvelope(param_1,local_7c);
  puVar3 = (undefined4 *)(param_1 + 0x34);
  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ==== 0x5362a0 EAXChannel::GenerateEnvelope

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 *
EAXChannel__GenerateEnvelope
          (int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
          undefined4 param_10)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_7c [7];
  undefined4 auStack_60 [6];
  undefined4 auStack_48 [6];
  undefined1 auStack_30 [8];
  undefined4 auStack_28 [6];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 local_4;
  
  iVar2 = 0;
  do {
    auStack_60[iVar2] = 0;
    auStack_48[iVar2] = 0;
    local_7c[iVar2 + 1] = 0;
    auStack_30[iVar2] = 0;
    auStack_28[iVar2] = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  local_8 = 0;
  local_7c[0] = 0;
  local_c = 0;
  local_10 = 0;
  iVar2 = 0;
  do {
    auStack_60[iVar2] = 0;
    auStack_48[iVar2] = 0;
    local_7c[iVar2 + 1] = 0;
    auStack_30[iVar2] = 0;
    auStack_28[iVar2] = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  local_4 = 0;
  FUN_00532670(0,0,0,0);
  uVar1 = *(undefined4 *)(param_1 + 0xa8);
  local_8 = 0;
  switch(param_3) {
  case 1:
  case 2:
    FUN_00532640();
    FUN_00532670(uVar1,param_9,param_4,0);
    FUN_00532670(param_9,param_9,param_5,0);
    FUN_00532670(param_9,param_10,param_6,0);
    FUN_00532670(param_10,param_10,param_7,0);
    param_9 = 0;
    param_4 = param_8;
    break;
  case 3:
  case 4:
    FUN_00532640();
    param_10 = uVar1;
    break;
  case 5:
    FUN_00532640();
    param_9 = 0;
    param_10 = uVar1;
    break;
  default:
    goto switchD_0053635b_default;
  }
  FUN_00532670(param_10,param_9,param_4,0);
switchD_0053635b_default:
  puVar3 = local_7c;
  puVar4 = param_2;
  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  return param_2;
}


// ==== 0x536450 FUN_00536450

void FUN_00536450(undefined4 param_1)

{
  int iVar1;
  int unaff_ESI;
  
  FUN_005326f0(param_1);
  FUN_005326f0(param_1);
  if (*(char *)(unaff_ESI + 0x128) == '\0') {
    _ftol_nocw();
  }
  iVar1 = _ftol_nocw();
  *(int *)(unaff_ESI + 4) = iVar1;
  if (iVar1 < 0x8000) {
    if ((iVar1 < 0x7fff) && (*(char *)(unaff_ESI + 300) != '\0')) {
      *(undefined1 *)(unaff_ESI + 300) = 0;
    }
  }
  else {
    *(undefined4 *)(unaff_ESI + 4) = 0x7fff;
    if (*(char *)(unaff_ESI + 300) == '\0') {
      *(undefined1 *)(unaff_ESI + 300) = 1;
      return;
    }
  }
  return;
}


// ==== 0x5364e0 EAXMixMgr::EAXMixMgr

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 * EAXMixMgr__EAXMixMgr(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685249;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  eh_vector_constructor_iterator(param_1 + 1,0x130,0x2c,FUN_005361d0,NullUpdate_ret);
  local_4 = 0;
  eh_vector_constructor_iterator(param_1 + 0xd26,0x130,8,FUN_005361d0,NullUpdate_ret);
  param_1[0xd25] = 0;
  *param_1 = 0;
  param_1[0xf88] = 0;
  FUN_00536df0(param_1);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x536570 FUN_00536570

void FUN_00536570(int param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685249;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  eh_vector_destructor_iterator((void *)(param_1 + 0x3498),0x130,8,NullUpdate_ret);
  local_4 = 0xffffffff;
  eh_vector_destructor_iterator((void *)(param_1 + 4),0x130,0x2c,NullUpdate_ret);
  ExceptionList = local_c;
  return;
}


// ==== 0x5365e0 FUN_005365e0

void __fastcall FUN_005365e0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EDI;
  
  uVar2 = _ftol_nocw(param_1);
  *(undefined4 *)(unaff_EDI + 0x3e20) = uVar2;
  if ((((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) || (DAT_0078a344 != '\0')) ||
     (DAT_007361a8 != 0)) {
    *(undefined4 *)(unaff_EDI + 0x3e20) = 0;
  }
  iVar1 = *(int *)(unaff_EDI + 0x3e20);
  iVar3 = _ftol_nocw();
  if (iVar3 < 1) {
    iVar3 = 0;
  }
  else if (0x1ff < iVar3) {
    iVar3 = 0x1ff;
  }
  iVar3 = (&DAT_006f7a1c)[-iVar3];
  *(int *)(unaff_EDI + 0x3e1c) = (iVar1 * 0x2a0f >> 0xf) + 22000;
  *(int *)(unaff_EDI + 0x3e18) = 0x7fff - iVar3;
  return;
}


// ==== 0x536690 FUN_00536690

void FUN_00536690(void)

{
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  FUN_005366e0(unaff_ESI);
  EAXMixMgr__SetMixType(unaff_ESI,unaff_EDI,0xbf800000,0);
  EAXMixMgr__SetMixType(unaff_ESI,unaff_EDI,0xbf800000,1);
  EAXMixMgr__SetMixType(unaff_ESI,unaff_EDI,0xbf800000,2);
  EAXMixMgr__SetMixType(unaff_ESI,unaff_EDI,0xbf800000,3);
  return;
}


// ==== 0x5366e0 FUN_005366e0

void FUN_005366e0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int extraout_ECX;
  int extraout_ECX_00;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int local_4;
  
  puVar4 = (undefined4 *)(param_1 + 0xa8);
  local_4 = 4;
  do {
    iVar5 = 0xb;
    do {
      puVar4[1] = 0;
      puVar4[-0x1c] = 0;
      *puVar4 = 0;
      puVar4[-1] = 0;
      iVar3 = 0;
      puVar1 = puVar4 + -0xf;
      do {
        puVar1[-6] = 0;
        *puVar1 = 0;
        puVar1[-0xc] = 0;
        *(undefined1 *)((int)puVar4 + iVar3 + -0x24) = 0;
        puVar1[8] = 0;
        iVar3 = iVar3 + 1;
        puVar1 = puVar1 + 1;
      } while (iVar3 < 6);
      *(undefined1 *)(puVar4 + 2) = 0;
      FUN_00532670(0,0,0,0);
      *(undefined4 *)(extraout_ECX + 0x74) = 0;
      puVar4[-0x29] = 0x3fe6;
      puVar4[-0x28] = 0x3fe6;
      *(undefined1 *)(puVar4 + 0x22) = 0;
      puVar4 = puVar4 + 0x4c;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  puVar4 = (undefined4 *)(param_1 + 0x353c);
  iVar5 = 8;
  do {
    puVar4[1] = 0;
    puVar4[-0x1c] = 0;
    *puVar4 = 0;
    puVar4[-1] = 0;
    iVar3 = 0;
    puVar1 = puVar4 + -0xf;
    do {
      puVar1[-6] = 0;
      *puVar1 = 0;
      puVar1[-0xc] = 0;
      *(undefined1 *)((int)puVar4 + iVar3 + -0x24) = 0;
      puVar1[8] = 0;
      iVar3 = iVar3 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar3 < 6);
    *(undefined1 *)(puVar4 + 2) = 0;
    FUN_00532670(0,0,0,0);
    *(undefined4 *)(extraout_ECX_00 + 0x74) = 0;
    puVar4[-0x29] = 0x3fe6;
    puVar4[-0x28] = 0x3fe6;
    *(undefined1 *)(puVar4 + 0x22) = 0;
    puVar4 = puVar4 + 0x4c;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar5 = param_1 + 0x3444;
  puVar4 = (undefined4 *)(param_1 + 0x3484);
  iVar3 = 4;
  do {
    iVar2 = 0;
    do {
      *(undefined1 *)(iVar5 + iVar2) = 0;
      iVar2 = iVar2 + 1;
      puVar4[-4] = 0;
      *puVar4 = 0;
    } while (iVar2 < 0xc);
    puVar4 = puVar4 + 1;
    iVar5 = iVar5 + 0xc;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


// ==== 0x536800 FUN_00536800

void FUN_00536800(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 4;
  do {
    iVar2 = 0xb;
    do {
      FUN_00536450(param_2);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 8;
  do {
    FUN_00536450(param_2);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((DAT_0073619c != (int *)0x0) && (*param_1 != *DAT_0073619c)) {
    *param_1 = *DAT_0073619c;
  }
  return;
}


// ==== 0x536870 EAXMix_SetupAllTypes

/* [canon] audio med (hopper+capstone) docs/re/misc.md */

void EAXMix_SetupAllTypes(undefined4 param_1)

{
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  EAXMixMgr__SetMixType(unaff_EDI,unaff_ESI,param_1,0);
  EAXMixMgr__SetMixType(unaff_EDI,unaff_ESI,param_1,1);
  EAXMixMgr__SetMixType(unaff_EDI,unaff_ESI,param_1,2);
  EAXMixMgr__SetMixType(unaff_EDI,unaff_ESI,param_1,3);
  return;
}


// ==== 0x5368b0 EAXMixMgr::SetMixType

/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall
EAXMixMgr__SetMixType
          (undefined4 param_1,char param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined4 *puVar8;
  
  if (((param_6 < 4) && (iVar1 = *(int *)(param_3 + 0x3474 + param_6 * 4), iVar1 != param_4)) &&
     ((param_4 == 0 ||
      ((param_2 != '\0' ||
       ((int)(&DAT_00743ca8)[iVar1 * 0x1b] <= (int)(&DAT_00743ca8)[param_4 * 0x1b])))))) {
    *(int *)(param_3 + 0x3484 + param_6 * 4) = iVar1;
    *(int *)(param_3 + 0x3474 + param_6 * 4) = param_4;
    *(undefined1 *)(param_4 + (param_6 * 3 + 0xd11) * 4 + param_3) = 1;
    iVar1 = *(int *)(*(int *)(DAT_007356a8 + 0xa0) + 8);
    uVar3 = _ftol_nocw();
    piVar6 = &DAT_00743cb4 + param_4 * 0x1b;
    piVar7 = (int *)(param_6 * 0xd10 + 4 + param_3);
    param_5 = 0xb;
    do {
      iVar2 = *piVar6;
      iVar5 = *piVar7;
      *piVar7 = iVar2;
      FUN_00532640();
      FUN_00532670((float)(iVar5 - iVar2),0,uVar3,0);
      piVar7 = piVar7 + 0x4c;
      piVar6 = piVar6 + 1;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
    if ((&DAT_007356b0)[iVar1] == param_6) {
      piVar6 = &DAT_00743ce0 + param_4 * 0x1b;
      puVar8 = (undefined4 *)(param_3 + 0x35b8);
      param_5 = 8;
      do {
        *(int *)(param_3 + 0x3494) = param_4;
        iVar1 = *piVar6;
        iVar2 = puVar8[-0x48];
        puVar8[-0x48] = iVar1;
        puVar8[1] = 0;
        puVar8[-0x1c] = 0;
        *puVar8 = 0;
        puVar8[-1] = 0;
        iVar5 = 0;
        puVar4 = puVar8 + -0xf;
        do {
          puVar4[-6] = 0;
          *puVar4 = 0;
          puVar4[-0xc] = 0;
          *(undefined1 *)((int)puVar8 + iVar5 + -0x24) = 0;
          puVar4[8] = 0;
          iVar5 = iVar5 + 1;
          puVar4 = puVar4 + 1;
        } while (iVar5 < 6);
        *(undefined1 *)(puVar8 + 2) = 0;
        FUN_00532670((float)(iVar2 - iVar1),0,uVar3,0);
        piVar6 = piVar6 + 1;
        puVar8 = puVar8 + 0x4c;
        param_5 = param_5 + -1;
      } while (param_5 != 0);
    }
  }
  return;
}


// ==== 0x536a70 EAXMixMgr::EndMixType

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXMixMgr__EndMixType(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  
  iVar2 = param_3;
  if (((param_3 < 4) &&
      (pcVar7 = (char *)(param_2 + (param_3 * 3 + 0xd11) * 4 + param_1), *pcVar7 != '\0')) &&
     (*pcVar7 = '\0', *(int *)(param_1 + 0x3474 + param_3 * 4) == param_2)) {
    pcVar7 = (char *)(param_1 + 0x3445 + param_3 * 0xc);
    iVar6 = 0;
    iVar4 = 0;
    iVar3 = 0;
    param_3 = 0x6c;
    iVar5 = 2;
    do {
      if ((pcVar7[-1] != '\0') &&
         (*(int *)((int)&DAT_00743ca8 + iVar4) < *(int *)((int)&DAT_00743ca8 + iVar3))) {
        iVar6 = iVar5 + -2;
        iVar4 = iVar3;
      }
      if ((*pcVar7 != '\0') &&
         (*(int *)((int)&DAT_00743ca8 + iVar4) < *(int *)((int)&DAT_00743d14 + iVar3))) {
        iVar6 = iVar5 + -1;
        iVar4 = param_3;
      }
      if ((pcVar7[1] != '\0') &&
         (*(int *)((int)&DAT_00743ca8 + iVar4) < *(int *)((int)&DAT_00743d80 + iVar3))) {
        iVar4 = iVar3 + 0xd8;
        iVar6 = iVar5;
      }
      if ((pcVar7[2] != '\0') &&
         (*(int *)((int)&DAT_00743ca8 + iVar4) < *(int *)((int)&DAT_00743dec + iVar3))) {
        iVar6 = iVar5 + 1;
        iVar4 = iVar3 + 0x144;
      }
      if ((pcVar7[3] != '\0') &&
         (*(int *)((int)&DAT_00743ca8 + iVar4) < *(int *)((int)&DAT_00743e58 + iVar3))) {
        iVar6 = iVar5 + 2;
        iVar4 = iVar3 + 0x1b0;
      }
      if ((pcVar7[4] != '\0') &&
         (*(int *)((int)&DAT_00743ca8 + iVar4) < *(int *)((int)&DAT_00743ec4 + iVar3))) {
        iVar6 = iVar5 + 3;
        iVar4 = iVar3 + 0x21c;
      }
      param_3 = param_3 + 0x288;
      iVar1 = iVar5 + 4;
      pcVar7 = pcVar7 + 6;
      iVar3 = iVar3 + 0x288;
      iVar5 = iVar5 + 6;
    } while (iVar1 < 0xc);
    EAXMixMgr__SetMixType(param_1,iVar6,*(undefined4 *)(&DAT_00743cb0 + param_2 * 0x6c),iVar2);
  }
  return;
}


// ==== 0x536c20 FUN_00536c20

void __thiscall FUN_00536c20(int *param_1,int param_2)

{
  int in_EAX;
  int unaff_ESI;
  
  if (in_EAX < 4) {
    if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
      *param_1 = 0;
    }
    if ((DAT_007361f0 != (int *)0x0) && ((*DAT_007361f0 == 1 || (*DAT_007361f0 == 7)))) {
      *param_1 = 0;
    }
    if (unaff_ESI != 0) {
      *param_1 = *(int *)((in_EAX * 0xb + unaff_ESI) * 0x130 + 8 + param_2) * *param_1 >> 0xf;
    }
  }
  return;
}


// ==== 0x536c80 EAXMixMgr::ReceiveTrigger

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXMixMgr__ReceiveTrigger(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_stack_00000034;
  undefined4 auStack_3c [11];
  
  iVar1 = in_stack_00000034;
  if (in_stack_00000034 < 4) {
    if (param_2 != 0) {
      puVar3 = &param_2;
      puVar4 = auStack_3c;
      for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      EAXChannel__ReceiveEnvelopeEvent((in_stack_00000034 * 0xb + param_2) * 0x130 + 4 + param_1);
    }
    if (param_3 != 0) {
      puVar3 = &param_2;
      puVar4 = auStack_3c;
      for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      EAXChannel__ReceiveEnvelopeEvent((iVar1 * 0xb + param_3) * 0x130 + 4 + param_1);
    }
  }
  return;
}


// ==== 0x536d00 FUN_00536d00

void __fastcall FUN_00536d00(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_1[1] = 0x3f800000;
  param_1[2] = 0x3f800000;
  *param_1 = 0;
  iVar1 = 0;
  puVar2 = param_1 + 3;
  do {
    *puVar2 = 0xffffffff;
    *(undefined1 *)((int)param_1 + iVar1 + 0x58) = 1;
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar1 < 0xb);
  iVar1 = 0;
  puVar2 = param_1 + 0xe;
  do {
    *puVar2 = 0xffffffff;
    *(undefined1 *)((int)param_1 + iVar1 + 99) = 1;
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar1 < 8);
  param_1[0xd] = 0x3fe6;
  param_1[0x15] = 0x3fe6;
  return;
}


// ==== 0x536d60 FUN_00536d60

void FUN_00536d60(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = 0;
  do {
    iVar2 = 0;
    piVar3 = (int *)((int)&DAT_00743ce0 + iVar1);
    do {
      if (*piVar3 == -1) {
        *piVar3 = *(int *)((int)&DAT_00743cfc + iVar1);
        (&DAT_00743d0b)[iVar2 + iVar1] = 1;
      }
      else {
        (&DAT_00743d0b)[iVar2 + iVar1] = 0;
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < 8);
    iVar2 = 0;
    piVar3 = (int *)((int)&DAT_00743cb4 + iVar1);
    do {
      if (*piVar3 == -1) {
        *piVar3 = *(int *)((int)&DAT_00743cdc + iVar1);
        (&DAT_00743d00)[iVar2 + iVar1] = 1;
      }
      else {
        (&DAT_00743d00)[iVar2 + iVar1] = 0;
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < 0xb);
    (&DAT_00743d12)[iVar1] = 1;
    (&DAT_00743d0a)[iVar1] = 1;
    iVar1 = iVar1 + 0x6c;
  } while (iVar1 < 0x510);
  return;
}


// ==== 0x536df0 FUN_00536df0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00536df0(void)

{
  DAT_00736650 = 1;
  _DAT_0073665c = 400;
  _DAT_0073667c = 400;
  DAT_007366f0 = 1;
  _DAT_00736658 = 100;
  _DAT_00736678 = 100;
  _DAT_00736690 = 4;
  _DAT_00736694 = 4000;
  _DAT_007366b4 = 4000;
  _DAT_007366f8 = 100;
  _DAT_00736710 = 4;
  DAT_00744008 = 100;
  _DAT_00744054 = 13000;
  _DAT_00743edc = 13000;
  _DAT_00736668 = 0x41f00000;
  _DAT_0073666c = 0;
  DAT_00736654 = 0;
  _DAT_00736660 = 0;
  _DAT_00736664 = 0;
  DAT_00736670 = 2;
  _DAT_00736688 = 0xc1c80000;
  _DAT_0073668c = 0;
  DAT_00736674 = 0;
  _DAT_00736680 = 0;
  _DAT_00736684 = 0;
  _DAT_007366a8 = 0x42c80000;
  _DAT_007366b0 = 3;
  _DAT_007366c8 = 0x41c80000;
  _DAT_007366d0 = 5;
  _DAT_00736708 = 0x41f00000;
  DAT_007366f4 = 0;
  _DAT_007366fc = 0x226;
  _DAT_00736728 = 0x42c80000;
  _DAT_00736714 = 0;
  _DAT_0074400c = 0;
  _DAT_00744010 = 0;
  _DAT_0074405c = 0x7fff;
  _DAT_0074403c = 0x3fe6;
  _DAT_00744044 = 0x6784;
  _DAT_00744078 = 0x3e800000;
  _DAT_0074407c = 0x40000000;
  DAT_00744074 = 0x65;
  _DAT_007440c8 = 0x7fff;
  _DAT_007440a8 = 0x3fe6;
  _DAT_007440b0 = 0x189c;
  _DAT_007440c0 = 14000;
  _DAT_007440c4 = 0x7fff;
  _DAT_00743cac = 0x3fc00000;
  _DAT_00743cb0 = 0x3fc00000;
  DAT_00743ca8 = 0;
  DAT_00743cfc = 0x7fff;
  DAT_00743cdc = 0x3fe6;
  _DAT_00743ec8 = 0;
  _DAT_00743ecc = 0x3f000000;
  DAT_00743ec4 = 10;
  _DAT_00743f00 = 0x7fff;
  _DAT_00743f04 = 10000;
  _DAT_00743f08 = 10000;
  _DAT_00743f0c = 0x7b0c;
  _DAT_00743f18 = 0x7fff;
  _DAT_00743ed4 = 16000;
  _DAT_00743ed8 = 0x7fff;
  _DAT_00743ee0 = 12000;
  _DAT_00743ee4 = 0x6f54;
  DAT_00743e58 = 5;
  _DAT_00743e98 = 10000;
  _DAT_00743e7c = 10000;
  _DAT_00743d44 = 10000;
  _DAT_00743e04 = 10000;
  _DAT_00743ee8 = 0x7ef4;
  _DAT_00743eec = 0x5014;
  _DAT_00743ef0 = 16000;
  _DAT_00743ef4 = 0x733c;
  _DAT_00743ef8 = 0x3fe6;
  _DAT_00743efc = 0x3fe6;
  _DAT_00743e5c = 0x3dcccccd;
  _DAT_00743e60 = 0x3e99999a;
  _DAT_00743e94 = 0x7fff;
  _DAT_00743e9c = 14000;
  _DAT_00743ea0 = 0x7b0c;
  _DAT_00743e68 = 0x57e4;
  _DAT_00743e6c = 22000;
  _DAT_00743e70 = 0x30d4;
  _DAT_00743e74 = 0x6f54;
  _DAT_00743e78 = 18000;
  _DAT_00743e80 = 0x6f54;
  _DAT_00743e84 = 20000;
  _DAT_00743e88 = 28000;
  _DAT_00743fa0 = 0;
  _DAT_00743fa4 = 0x3e4ccccd;
  DAT_00743f9c = 0x32;
  _DAT_00743fd8 = 0x7fff;
  _DAT_00743fdc = 14000;
  _DAT_00743fe0 = 16000;
  _DAT_00743fe4 = 0x7b0c;
  _DAT_00743fac = 22000;
  _DAT_00743fb0 = 9000;
  _DAT_00743fb4 = 5000;
  _DAT_00743fb8 = 20000;
  _DAT_00743fbc = 8000;
  _DAT_00743fc0 = 0x7724;
  _DAT_00743fc4 = 0x6f54;
  _DAT_00743fc8 = 24000;
  _DAT_00743fcc = 28000;
  _DAT_00743d18 = 0x3fc00000;
  _DAT_00743d1c = 0x3fc00000;
  DAT_00743d14 = 1;
  _DAT_00743d50 = 0x6784;
  _DAT_00743d54 = 16000;
  _DAT_00743d58 = 12000;
  _DAT_00743d5c = 12000;
  _DAT_00743d24 = 0x34bc;
  _DAT_00743d28 = 9000;
  _DAT_00743d2c = 7000;
  _DAT_00743d30 = 0x7724;
  _DAT_00743d34 = 23000;
  _DAT_00743d38 = 5000;
  _DAT_00743d3c = 0x7fff;
  _DAT_00743d40 = 22000;
  _DAT_00743df0 = 0x3fc00000;
  _DAT_00743df4 = 0x3fc00000;
  DAT_00743dec = 1;
  _DAT_00743e28 = 0x7fff;
  _DAT_00743e2c = 16000;
  _DAT_00743e30 = 14000;
  _DAT_00743e34 = 0x7ef4;
  _DAT_00743df8 = 0x3fe6;
  _DAT_00743dfc = 18000;
  _DAT_00743e00 = 16000;
  _DAT_00743e08 = 0x5fb4;
  _DAT_00743e0c = 0x53fc;
  _DAT_00743e10 = 23000;
  _DAT_00743e14 = 0x6784;
  _DAT_00743e18 = 0x5fb4;
  _DAT_00743e1c = 0x7ef4;
  _DAT_00743e20 = 0x3fe6;
  _DAT_00743e24 = 0x3fe6;
  _DAT_00743d84 = 0x3fc00000;
  _DAT_00743d88 = 0x3fc00000;
  DAT_00743d80 = 1;
  _DAT_00743dbc = 1000;
  _DAT_00743dc0 = 5000;
  _DAT_007440f4 = 0x6f54;
  _DAT_00744108 = 0x6f54;
  _DAT_00744168 = 16000;
  _DAT_00744124 = 20000;
  _DAT_0074418c = 20000;
  _DAT_00744190 = 20000;
  _DAT_00743d94 = 15000;
  _DAT_00743d98 = 15000;
  _DAT_0074416c = 15000;
  _DAT_00743dc4 = 6000;
  _DAT_00743dc8 = 0x7fff;
  _DAT_00743d8c = 0x3fe6;
  _DAT_00743d90 = 21000;
  _DAT_00743d9c = 26000;
  _DAT_00743da0 = 0x7ef4;
  _DAT_00743da4 = 32000;
  _DAT_00743da8 = 0x733c;
  _DAT_00743dac = 0x733c;
  _DAT_00743db0 = 0x7b0c;
  _DAT_00743db4 = 0x3fe6;
  _DAT_007440e4 = 0x40a00000;
  _DAT_007440e8 = 0x3f000000;
  DAT_007440e0 = 0xb;
  _DAT_0074411c = 0x7fff;
  _DAT_00744120 = 6000;
  _DAT_00744128 = 0x7ef4;
  _DAT_007440ec = 0x3fe6;
  _DAT_007440f0 = 0x38a4;
  _DAT_007440f8 = 8000;
  _DAT_007440fc = 18000;
  _DAT_00744100 = 14000;
  _DAT_00744104 = 0x7fff;
  _DAT_0074410c = 0x7ef4;
  _DAT_00744110 = 31000;
  _DAT_00744114 = 0x3fe6;
  _DAT_00744118 = 0x3fe6;
  _DAT_00744150 = 0x40400000;
  _DAT_00744154 = 0x40400000;
  DAT_0074414c = 2;
  _DAT_00744188 = 0x7fff;
  _DAT_00744194 = 0x7ef4;
  _DAT_00744158 = 0x3fe6;
  _DAT_0074415c = 0x251c;
  _DAT_00744160 = 9000;
  _DAT_00744164 = 7000;
  _DAT_00744170 = 13000;
  _DAT_00744174 = 0x4844;
  _DAT_00744178 = 0x4c2c;
  _DAT_0074417c = 24000;
  _DAT_00744180 = 0x3fe6;
  _DAT_00744184 = 0x3fe6;
  FUN_00536d60();
  return;
}


// ==== 0x536ee8 FUN_00536ee8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00536ee8(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  _DAT_007366c8 = 0x41c80000;
  _DAT_00736708 = 0x41f00000;
  _DAT_007366fc = 0x226;
  _DAT_00736728 = 0x42c80000;
  _DAT_00744044 = 0x6784;
  _DAT_00744078 = 0x3e800000;
  _DAT_0074407c = 0x40000000;
  DAT_00744074 = 0x65;
  _DAT_007440b0 = 0x189c;
  _DAT_007440c0 = 14000;
  _DAT_00743cac = 0x3fc00000;
  _DAT_00743cb0 = 0x3fc00000;
  _DAT_00743ecc = 0x3f000000;
  DAT_00743ec4 = 10;
  _DAT_00743f0c = 0x7b0c;
  _DAT_00743ee0 = 12000;
  _DAT_00743ee8 = 0x7ef4;
  _DAT_00743eec = 0x5014;
  _DAT_00743ef4 = 0x733c;
  _DAT_00743e5c = 0x3dcccccd;
  _DAT_00743e60 = 0x3e99999a;
  _DAT_00743e9c = 14000;
  _DAT_00743ea0 = 0x7b0c;
  _DAT_00743e68 = 0x57e4;
  _DAT_00743e6c = 22000;
  _DAT_00743e70 = 0x30d4;
  _DAT_00743e78 = 18000;
  _DAT_00743e84 = 20000;
  _DAT_00743e88 = 28000;
  _DAT_00743fa0 = 0;
  _DAT_00743fa4 = 0x3e4ccccd;
  DAT_00743f9c = 0x32;
  _DAT_00743fdc = 14000;
  _DAT_00743fe4 = 0x7b0c;
  _DAT_00743fac = 22000;
  _DAT_00743fb0 = 9000;
  _DAT_00743fb4 = 5000;
  _DAT_00743fb8 = 20000;
  _DAT_00743fbc = 8000;
  _DAT_00743fc0 = 0x7724;
  _DAT_00743fc8 = 24000;
  _DAT_00743fcc = 28000;
  _DAT_00743d18 = 0x3fc00000;
  _DAT_00743d1c = 0x3fc00000;
  DAT_00743d14 = 1;
  _DAT_00743d50 = 0x6784;
  _DAT_00743d58 = 12000;
  _DAT_00743d5c = 12000;
  _DAT_00743d24 = 0x34bc;
  _DAT_00743d28 = 9000;
  _DAT_00743d2c = 7000;
  _DAT_00743d30 = 0x7724;
  _DAT_00743d34 = 23000;
  _DAT_00743d38 = 5000;
  _DAT_00743d40 = 22000;
  _DAT_00743df0 = 0x3fc00000;
  _DAT_00743df4 = 0x3fc00000;
  DAT_00743dec = 1;
  _DAT_00743e30 = 14000;
  _DAT_00743e34 = 0x7ef4;
  _DAT_00743dfc = 18000;
  _DAT_00743e08 = 0x5fb4;
  _DAT_00743e0c = 0x53fc;
  _DAT_00743e10 = 23000;
  _DAT_00743e14 = 0x6784;
  _DAT_00743e18 = 0x5fb4;
  _DAT_00743e1c = 0x7ef4;
  _DAT_00743d84 = 0x3fc00000;
  _DAT_00743d88 = 0x3fc00000;
  DAT_00743d80 = 1;
  _DAT_00743dbc = 1000;
  _DAT_00743dc0 = 5000;
  _DAT_00744124 = 20000;
  _DAT_0074418c = 20000;
  _DAT_00744190 = 20000;
  _DAT_00743d94 = 15000;
  _DAT_00743d98 = 15000;
  _DAT_0074416c = 15000;
  _DAT_00743dc4 = 6000;
  _DAT_00743d90 = 21000;
  _DAT_00743d9c = 26000;
  _DAT_00743da0 = 0x7ef4;
  _DAT_00743da4 = 32000;
  _DAT_00743da8 = 0x733c;
  _DAT_00743dac = 0x733c;
  _DAT_00743db0 = 0x7b0c;
  _DAT_007440e4 = 0x40a00000;
  _DAT_007440e8 = 0x3f000000;
  DAT_007440e0 = 0xb;
  _DAT_00744120 = 6000;
  _DAT_00744128 = 0x7ef4;
  _DAT_007440f0 = 0x38a4;
  _DAT_007440f8 = 8000;
  _DAT_007440fc = 18000;
  _DAT_00744100 = 14000;
  _DAT_0074410c = 0x7ef4;
  _DAT_00744110 = 31000;
  _DAT_00744150 = 0x40400000;
  _DAT_00744154 = 0x40400000;
  DAT_0074414c = 2;
  _DAT_00744194 = 0x7ef4;
  _DAT_0074415c = 0x251c;
  _DAT_00744160 = 9000;
  _DAT_00744164 = 7000;
  _DAT_00744170 = 13000;
  _DAT_00744174 = 0x4844;
  _DAT_00744178 = 0x4c2c;
  _DAT_0074417c = 24000;
  _DAT_007366d0 = unaff_EBP;
  DAT_007366f4 = param_2;
  _DAT_00736714 = param_2;
  DAT_00743ca8 = param_2;
  DAT_00743cdc = in_EAX;
  DAT_00743cfc = param_1;
  _DAT_00743d3c = param_1;
  _DAT_00743d44 = unaff_EBX;
  _DAT_00743d54 = unaff_ESI;
  _DAT_00743d8c = in_EAX;
  _DAT_00743db4 = in_EAX;
  _DAT_00743dc8 = param_1;
  _DAT_00743df8 = in_EAX;
  _DAT_00743e00 = unaff_ESI;
  _DAT_00743e04 = unaff_EBX;
  _DAT_00743e20 = in_EAX;
  _DAT_00743e24 = in_EAX;
  _DAT_00743e28 = param_1;
  _DAT_00743e2c = unaff_ESI;
  DAT_00743e58 = unaff_EBP;
  _DAT_00743e74 = unaff_EDI;
  _DAT_00743e7c = unaff_EBX;
  _DAT_00743e80 = unaff_EDI;
  _DAT_00743e94 = param_1;
  _DAT_00743e98 = unaff_EBX;
  _DAT_00743ec8 = param_2;
  _DAT_00743ed4 = unaff_ESI;
  _DAT_00743ed8 = param_1;
  _DAT_00743ee4 = unaff_EDI;
  _DAT_00743ef0 = unaff_ESI;
  _DAT_00743ef8 = in_EAX;
  _DAT_00743efc = in_EAX;
  _DAT_00743f00 = param_1;
  _DAT_00743f04 = unaff_EBX;
  _DAT_00743f08 = unaff_EBX;
  _DAT_00743f18 = param_1;
  _DAT_00743fc4 = unaff_EDI;
  _DAT_00743fd8 = param_1;
  _DAT_00743fe0 = unaff_ESI;
  _DAT_0074400c = param_2;
  _DAT_00744010 = param_2;
  _DAT_0074403c = in_EAX;
  _DAT_0074405c = param_1;
  _DAT_007440a8 = in_EAX;
  _DAT_007440c4 = param_1;
  _DAT_007440c8 = param_1;
  _DAT_007440ec = in_EAX;
  _DAT_007440f4 = unaff_EDI;
  _DAT_00744104 = param_1;
  _DAT_00744108 = unaff_EDI;
  _DAT_00744114 = in_EAX;
  _DAT_00744118 = in_EAX;
  _DAT_0074411c = param_1;
  _DAT_00744158 = in_EAX;
  _DAT_00744168 = unaff_ESI;
  _DAT_00744180 = in_EAX;
  _DAT_00744184 = in_EAX;
  _DAT_00744188 = param_1;
  FUN_00536d60();
  return;
}


// ==== 0x537450 FUN_00537450

undefined4 __fastcall FUN_00537450(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}


// ==== 0x537460 EAXMod::SetOwner__this_0x10___arg__owner_meaning_unproven_

/* [canon] audio I (ghidra) docs/re/sound.md */

void __thiscall
EAXMod__SetOwner__this_0x10___arg__owner_meaning_unproven_(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return;
}


// ==== 0x537470 FUN_00537470

void __thiscall FUN_00537470(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}


// ==== 0x537480 FUN_00537480

void __thiscall FUN_00537480(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}


// ==== 0x537490 FUN_00537490

float10 FUN_00537490(void)

{
  return (float10)0.0;
}


// ==== 0x5374a0 FUN_005374a0

undefined4 * FUN_005374a0(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684d28;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006bdee0;
  eh_vector_constructor_iterator(param_1 + 0x10,0x2e0,2,FUN_00537910,FUN_00537580);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x537500 FUN_00537500

void __fastcall FUN_00537500(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684d08;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006bdee0;
  local_4 = 0;
  eh_vector_destructor_iterator(param_1 + 0x10,0x2e0,2,FUN_00537580);
  *param_1 = &PTR_FUN_006bdd40;
  ExceptionList = local_c;
  return;
}


// ==== 0x537560 FUN_00537560

void * __thiscall FUN_00537560(void *param_1,byte param_2)

{
  FUN_00537500();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x537580 FUN_00537580

void __fastcall FUN_00537580(int param_1)

{
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_006be7c4;
  return;
}


// ==== 0x537590 FUN_00537590

undefined4 * FUN_00537590(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684d28;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006be080;
  eh_vector_constructor_iterator(param_1 + 0x14,0x2e0,2,FUN_00537910,FUN_00537580);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x5375f0 FUN_005375f0

void __fastcall FUN_005375f0(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684d08;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006be080;
  local_4 = 0;
  eh_vector_destructor_iterator(param_1 + 0x14,0x2e0,2,FUN_00537580);
  *param_1 = &PTR_FUN_006bdd40;
  ExceptionList = local_c;
  return;
}


// ==== 0x537650 FUN_00537650

void * __thiscall FUN_00537650(void *param_1,byte param_2)

{
  FUN_005375f0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x537670 FUN_00537670

undefined4 * FUN_00537670(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684d28;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006be150;
  eh_vector_constructor_iterator(param_1 + 0x10,0x2e0,2,FUN_00537910,FUN_00537580);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x5376d0 FUN_005376d0

void __fastcall FUN_005376d0(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684d08;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006be150;
  local_4 = 0;
  eh_vector_destructor_iterator(param_1 + 0x10,0x2e0,2,FUN_00537580);
  *param_1 = &PTR_FUN_006bdd40;
  ExceptionList = local_c;
  return;
}


// ==== 0x537730 FUN_00537730

void * __thiscall FUN_00537730(void *param_1,byte param_2)

{
  FUN_005376d0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x537750 FUN_00537750

undefined4 * FUN_00537750(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684d28;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006bdfb0;
  eh_vector_constructor_iterator(param_1 + 0x10,0x2e0,2,FUN_00537910,FUN_00537580);
  *(undefined1 *)(param_1 + 0xf) = 0;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x5377b0 FUN_005377b0

void __fastcall FUN_005377b0(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684d08;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006bdfb0;
  local_4 = 0;
  eh_vector_destructor_iterator(param_1 + 0x10,0x2e0,2,FUN_00537580);
  *param_1 = &PTR_FUN_006bdd40;
  ExceptionList = local_c;
  return;
}


// ==== 0x537810 FUN_00537810

void * __thiscall FUN_00537810(void *param_1,byte param_2)

{
  FUN_005377b0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x537830 FUN_00537830

undefined4 * FUN_00537830(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684d28;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006bde10;
  eh_vector_constructor_iterator(param_1 + 0x10,0x2e0,2,FUN_00537910,FUN_00537580);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x537890 FUN_00537890

void __fastcall FUN_00537890(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684d08;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006bde10;
  local_4 = 0;
  eh_vector_destructor_iterator(param_1 + 0x10,0x2e0,2,FUN_00537580);
  *param_1 = &PTR_FUN_006bdd40;
  ExceptionList = local_c;
  return;
}


// ==== 0x5378f0 FUN_005378f0

void * __thiscall FUN_005378f0(void *param_1,byte param_2)

{
  FUN_00537890();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x537910 FUN_00537910

undefined4 __fastcall FUN_00537910(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)EAXS_3DMixer__EAXS_3DMixer();
  *puVar1 = &PTR_EAXS_3DMixer_derived_deleting_destructor__map__EAXS_SoundShape_____006bdd08;
  puVar1[0x85] = 0x43ff8000;
  return param_1;
}


// ==== 0x537930 FUN_00537930

void FUN_00537930(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006bde0c;
  in_EAX[0x23] = 0;
  in_EAX[5] = 0;
  in_EAX[6] = 0;
  in_EAX[7] = 0;
  in_EAX[8] = 0;
  in_EAX[9] = 0;
  in_EAX[0x25] = 0;
  *(undefined1 *)(in_EAX + 0x69) = 0;
  in_EAX[0x1f] = 0;
  *(undefined1 *)(in_EAX + 4) = 0;
  in_EAX[0x7f] = 0;
  in_EAX[0x80] = 0;
  in_EAX[0x7d] = 0;
  in_EAX[0x7c] = 0;
  in_EAX[0x97] = 2;
  in_EAX[0xb1] = 0;
  *(undefined1 *)((int)in_EAX + 0x1a5) = 0;
  in_EAX[0xae] = 0;
  in_EAX[0xaf] = 0;
  *(undefined1 *)(in_EAX + 0xb0) = 0;
  return;
}


// ==== 0x5379a0 FUN_005379a0

undefined4 * __thiscall FUN_005379a0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006bde0c;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5379c0 FUN_005379c0

void FUN_005379c0(void)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(in_EAX + 0x14);
  iVar2 = 5;
  do {
    if ((int *)*piVar1 != (int *)0x0) {
      (**(code **)(*(int *)*piVar1 + 0x28))();
      if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar1)(1);
      }
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== 0x537a00 FUN_00537a00

void FUN_00537a00(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int in_EAX;
  int iVar3;
  int unaff_EDI;
  
  if (in_EAX == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = in_EAX;
    if ((((in_EAX != 1) && (in_EAX != 2)) && (in_EAX != 3)) &&
       ((iVar3 = -1, 3 < in_EAX && (in_EAX < 10)))) {
      iVar3 = 4;
    }
  }
  piVar1 = *(int **)(unaff_EDI + 0x14 + iVar3 * 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x28))();
    puVar2 = *(undefined4 **)(unaff_EDI + 0x14 + iVar3 * 4);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    *(undefined4 *)(unaff_EDI + 0x14 + iVar3 * 4) = 0;
  }
  return;
}


// ==== 0x537a60 FUN_00537a60

void FUN_00537a60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int unaff_ESI;
  int iVar4;
  undefined4 local_14;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0068521f;
  local_c = ExceptionList;
  if (5 < *(int *)(unaff_ESI + 0x8c)) {
    return;
  }
  local_14 = 0;
  if (param_1 == 0) {
    if (*(int *)(unaff_ESI + 0x14) != 0) {
      return;
    }
    ExceptionList = &local_c;
    pvVar1 = _malloc(0x620);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      *(undefined4 *)(unaff_ESI + 0x14) = 0;
      iVar4 = 0;
      uVar2 = 0x6400;
    }
    else {
      uVar2 = FUN_00537590(pvVar1);
      *(undefined4 *)(unaff_ESI + 0x14) = uVar2;
      iVar4 = 0;
      uVar2 = 0x6400;
    }
  }
  else {
    if (param_1 == 1) {
      if (*(int *)(unaff_ESI + 0x18) != 0) {
        return;
      }
      ExceptionList = &local_c;
      pvVar1 = _malloc(0x610);
      local_4 = 1;
      if (pvVar1 == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_005374a0(pvVar1);
      }
      *(undefined4 *)(unaff_ESI + 0x18) = uVar2;
      iVar4 = 1;
      uVar2 = 0x6400;
      uVar3 = 4;
      local_14 = 1;
      goto LAB_00537c14;
    }
    iVar4 = 2;
    if (param_1 == 2) {
      if (*(int *)(unaff_ESI + 0x1c) != 0) {
        return;
      }
      ExceptionList = &local_c;
      pvVar1 = _malloc(0x600);
      local_4 = 2;
      if (pvVar1 == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_00537670(pvVar1);
      }
      *(undefined4 *)(unaff_ESI + 0x1c) = uVar2;
      uVar2 = 0x3200;
      uVar3 = 2;
      local_14 = 1;
      goto LAB_00537c14;
    }
    if (param_1 == 3) {
      if (*(int *)(unaff_ESI + 0x20) != 0) {
        return;
      }
      ExceptionList = &local_c;
      pvVar1 = _malloc(0x600);
      iVar4 = 3;
      local_4 = 3;
      if (pvVar1 == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_00537750(pvVar1);
      }
      *(undefined4 *)(unaff_ESI + 0x20) = uVar2;
      uVar2 = 0x3200;
      uVar3 = 2;
      local_14 = 1;
      goto LAB_00537c14;
    }
    iVar4 = 4;
    if (param_1 < 4) {
      return;
    }
    if (9 < param_1) {
      return;
    }
    if (*(int *)(unaff_ESI + 0x24) != 0) {
      return;
    }
    ExceptionList = &local_c;
    pvVar1 = _malloc(0x600);
    local_4 = 4;
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_00537830(pvVar1);
    }
    *(undefined4 *)(unaff_ESI + 0x24) = uVar2;
    uVar2 = 0x3200;
  }
  uVar3 = 3;
LAB_00537c14:
  *(int *)(unaff_ESI + 0x28 + iVar4 * 4) = param_1;
  local_4 = 0xffffffff;
  (**(code **)(**(int **)(unaff_ESI + 0x14 + iVar4 * 4) + 0x1c))
            (param_1,uVar3,local_14,param_2,uVar2,param_3,param_4);
  *(int *)(unaff_ESI + 0x8c) = *(int *)(unaff_ESI + 0x8c) + 1;
  (**(code **)(**(int **)(unaff_ESI + 0x14 + iVar4 * 4) + 0xc))(0);
  (**(code **)(**(int **)(unaff_ESI + 0x14 + iVar4 * 4) + 8))(0);
  (**(code **)(**(int **)(unaff_ESI + 0x14 + iVar4 * 4) + 0x14))(unaff_ESI + 0x1b0);
  if (param_1 == 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x14) + 0x8c))();
    *(undefined4 *)(unaff_ESI + 0x2a8) = 0;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x537ca0 FUN_00537ca0

void FUN_00537ca0(undefined4 param_1)

{
  int in_EAX;
  
  if (DAT_006f1dd8 != 0) {
    *(undefined4 *)(in_EAX + 0x1c4) = param_1;
    FUN_00537cc0();
  }
  return;
}


// ==== 0x537cc0 FUN_00537cc0

void FUN_00537cc0(void)

{
  int iVar1;
  int unaff_ESI;
  int *piVar2;
  
  iVar1 = 5;
  if (*(int *)(unaff_ESI + 0x1c4) == 4) {
    *(undefined4 *)(unaff_ESI + 0x1c4) = 5;
    *(undefined4 *)(unaff_ESI + 0x1c0) = 5;
  }
  if (*(int *)(unaff_ESI + 0x1c4) == 2) {
    *(undefined4 *)(unaff_ESI + 0x1d0) = DAT_0078a2f0;
    piVar2 = (int *)(unaff_ESI + 0x14);
    if (*(int *)(unaff_ESI + 0x1c0) == 5) {
      do {
        if ((int *)*piVar2 != (int *)0x0) {
          (**(code **)(*(int *)*piVar2 + 0x4c))();
        }
        piVar2 = piVar2 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    else {
      do {
        if ((int *)*piVar2 != (int *)0x0) {
          (**(code **)(*(int *)*piVar2 + 0x54))();
        }
        piVar2 = piVar2 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    *(undefined4 *)(unaff_ESI + 0x1c0) = 3;
    *(undefined1 *)(unaff_ESI + 0x219) = 0;
    *(undefined1 *)(unaff_ESI + 0x21b) = 0;
    *(undefined1 *)(unaff_ESI + 0x21a) = 0;
    *(undefined1 *)(unaff_ESI + 0x21f) = 0;
    *(undefined1 *)(unaff_ESI + 0x220) = 0;
    *(undefined1 *)(unaff_ESI + 0x21c) = 0;
    *(undefined1 *)(unaff_ESI + 0x221) = 0;
    *(undefined1 *)(unaff_ESI + 0x222) = 0;
    *(undefined1 *)(unaff_ESI + 0x223) = 0;
    *(undefined4 *)(unaff_ESI + 0x1c4) = 3;
    *(undefined4 *)(unaff_ESI + 0x1c0) = 3;
    return;
  }
  if (*(int *)(unaff_ESI + 0x1c4) == 5) {
    piVar2 = (int *)(unaff_ESI + 0x14);
    do {
      if ((int *)*piVar2 != (int *)0x0) {
        (**(code **)(*(int *)*piVar2 + 0x50))();
      }
      piVar2 = piVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  *(undefined4 *)(unaff_ESI + 0x1c0) = *(undefined4 *)(unaff_ESI + 0x1c4);
  return;
}


// ==== 0x537db0 FUN_00537db0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00537db0(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int *piVar4;
  
  uVar1 = DAT_00779818;
  iVar2 = *(int *)(unaff_ESI + 0x1b4);
  if (iVar2 == *(int *)(unaff_ESI + 0x1b0)) {
    if (((*(int *)(unaff_ESI + 0x1b0) != 4) ||
        (*(int *)(unaff_ESI + 0x1bc) == *(int *)(unaff_ESI + 0x1b8))) ||
       (*(int *)(unaff_ESI + 0x1bc) != 4)) goto LAB_00538068;
    piVar4 = (int *)(unaff_ESI + 0x14);
    iVar2 = 5;
    do {
      if ((int *)*piVar4 != (int *)0x0) {
        (**(code **)(*(int *)*piVar4 + 0x48))();
      }
      piVar4 = piVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  else {
    if (iVar2 == 8) {
      iVar2 = 0;
      if (*(int *)(DAT_007356a8 + 0xc4) != 0) {
        iVar2 = *(int *)(*(int *)(DAT_007356a8 + 0xc4) + 0x234);
      }
      *(undefined4 *)(unaff_ESI + 0x1e8) = 0xffffffff;
      *(undefined4 *)(unaff_ESI + 0x1ec) = 0xffffffff;
      if (iVar2 != 0) {
        *(int *)(unaff_ESI + 0x1e8) = (int)*(char *)(*(int *)(iVar2 + 0x1c) + 0xc);
        *(uint *)(unaff_ESI + 0x1ec) = uVar1 & 3;
      }
      piVar4 = (int *)(unaff_ESI + 0x14);
      iVar2 = 5;
      do {
        if ((int *)*piVar4 != (int *)0x0) {
          (**(code **)(*(int *)*piVar4 + 0x38))();
        }
        piVar4 = piVar4 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      piVar4 = (int *)(unaff_ESI + 0x14);
      iVar2 = 5;
      do {
        if ((int *)*piVar4 != (int *)0x0) {
          (**(code **)(*(int *)*piVar4 + 0x3c))();
        }
        piVar4 = piVar4 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      *(undefined1 *)(unaff_ESI + 0x10) = 1;
      goto LAB_00538068;
    }
    if (iVar2 == 1) {
      piVar4 = (int *)(unaff_ESI + 0x14);
      iVar2 = 5;
      do {
        if ((int *)*piVar4 != (int *)0x0) {
          (**(code **)(*(int *)*piVar4 + 0x38))();
        }
        piVar4 = piVar4 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    iVar2 = *(int *)(unaff_ESI + 0x1bc);
    if (iVar2 == 2) {
      iVar2 = uVar1 - 0x8fc;
      *(undefined4 *)(unaff_ESI + 0x1ec) = 0xffffffff;
      if (iVar2 < 0x14) {
        iVar2 = uVar1 - 0x8fd;
      }
      else if ((iVar2 < 0x1e) || (0x23 < iVar2)) {
        if (iVar2 == 0x26) {
          iVar2 = 0x18;
        }
      }
      else {
        iVar2 = uVar1 - 0x907;
      }
      *(int *)(unaff_ESI + 0x288) = iVar2;
      iVar3 = DAT_007356a8;
      *(int *)(unaff_ESI + 0x28c) = iVar2 * 3;
      iVar3 = (**(code **)(**(int **)(iVar3 + 0xc4) + 0x44))();
      if (iVar3 < 2) {
        iVar3 = 0;
      }
      else {
        iVar3 = iVar3 + -1;
      }
      *(int *)(unaff_ESI + 0x284) = iVar3;
      *(int *)(unaff_ESI + 0x1ec) = iVar3 + iVar2 * 3;
      piVar4 = (int *)(unaff_ESI + 0x14);
      iVar2 = 5;
      do {
        if ((int *)*piVar4 != (int *)0x0) {
          (**(code **)(*(int *)*piVar4 + 0x40))();
        }
        piVar4 = piVar4 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      goto LAB_00538068;
    }
    if (iVar2 == 3) {
      *(int *)(unaff_ESI + 0x90) = DAT_00740500 + 0x40;
      *(undefined1 *)(unaff_ESI + 0x1a5) = 1;
      EAXS_StreamManager__GetCurrentAmbientZone();
      iVar3 = DAT_007356a8;
      iVar2 = uVar1 - 0x8fc;
      if (iVar2 < 0x14) {
        iVar2 = uVar1 - 0x8fd;
      }
      else if ((iVar2 < 0x1e) || (0x23 < iVar2)) {
        if (iVar2 == 0x26) {
          iVar2 = 0x18;
        }
      }
      else {
        iVar2 = uVar1 - 0x907;
      }
      *(int *)(unaff_ESI + 0x288) = iVar2;
      *(int *)(unaff_ESI + 0x28c) = iVar2 * 3;
      iVar3 = (**(code **)(**(int **)(iVar3 + 0xc4) + 0x44))();
      if (iVar3 < 2) {
        iVar3 = 0;
      }
      else {
        iVar3 = iVar3 + -1;
      }
      *(int *)(unaff_ESI + 0x284) = iVar3;
      *(int *)(unaff_ESI + 0x1ec) = iVar3 + iVar2 * 3;
      piVar4 = (int *)(unaff_ESI + 0x14);
      iVar2 = 5;
      do {
        if ((int *)*piVar4 != (int *)0x0) {
          (**(code **)(*(int *)*piVar4 + 0x44))();
        }
        piVar4 = piVar4 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      goto LAB_00538068;
    }
    if (iVar2 != 4) {
      if ((*(int *)(unaff_ESI + 0x1b4) == 1) && (*(int *)(unaff_ESI + 0x1b0) == 4)) {
        piVar4 = (int *)(unaff_ESI + 0x14);
        iVar2 = 5;
        do {
          if ((int *)*piVar4 != (int *)0x0) {
            (**(code **)(*(int *)*piVar4 + 0x38))();
          }
          piVar4 = piVar4 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      goto LAB_00538068;
    }
    if (*(int *)(unaff_ESI + 0x1b8) != 3) goto LAB_00538068;
    *(undefined1 *)(unaff_ESI + 0x1a5) = 1;
    piVar4 = (int *)(unaff_ESI + 0x14);
    iVar2 = 5;
    do {
      if ((int *)*piVar4 != (int *)0x0) {
        (**(code **)(*(int *)*piVar4 + 0x48))();
      }
      piVar4 = piVar4 + 1;
      iVar2 = iVar2 + -1;
      _DAT_0073635c = 0;
    } while (iVar2 != 0);
  }
  *(undefined1 *)(unaff_ESI + 0x10) = 0;
LAB_00538068:
  *(undefined4 *)(unaff_ESI + 0x1b8) = *(undefined4 *)(unaff_ESI + 0x1bc);
  *(undefined4 *)(unaff_ESI + 0x1b0) = *(undefined4 *)(unaff_ESI + 0x1b4);
  return;
}


// ==== 0x538090 FUN_00538090

bool FUN_00538090(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  float10 fVar3;
  undefined4 uVar4;
  float fVar5;
  
  iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x20) + 0x94))(0);
  fVar5 = 1.4013e-45;
  iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x20) + 0x94))();
  uVar4 = 0;
  fVar3 = (float10)(**(code **)(**(int **)(unaff_ESI + 0x20) + 0x84))(0);
  fVar3 = (float10)(**(code **)(**(int **)(unaff_ESI + 0x20) + 0x84))(1,uVar4,fVar5,(float)fVar3);
  if ((float10)fVar5 < fVar3) {
    if ((float10)5000.0 <= fVar3) {
      (**(code **)(**(int **)(unaff_ESI + 0x20) + 0xa8))(1);
      return true;
    }
    (**(code **)(**(int **)(unaff_ESI + 0x20) + 0xa8))(iVar1 < iVar2);
    return iVar1 < iVar2;
  }
  if (5000.0 <= fVar5) {
    (**(code **)(**(int **)(unaff_ESI + 0x20) + 0xa8))(0);
    return false;
  }
  (**(code **)(**(int **)(unaff_ESI + 0x20) + 0xa8))(iVar1 < iVar2);
  return iVar1 < iVar2;
}


// ==== 0x538170 FUN_00538170

undefined4 FUN_00538170(void)

{
  int in_EAX;
  int iVar1;
  undefined4 unaff_EDI;
  
  iVar1 = (**(code **)(**(int **)(in_EAX + 0x20) + 0xa4))();
  if (iVar1 != -1) {
    (**(code **)(**(int **)(in_EAX + 0x20) + 0x90))();
    return 1;
  }
  iVar1 = FUN_00538090(unaff_EDI);
  if (-1 < iVar1) {
    (**(code **)(**(int **)(in_EAX + 0x20) + 0x90))();
    return 1;
  }
  return 0;
}


// ==== 0x5381b0 FUN_005381b0

void FUN_005381b0(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0x1c8);
  if (iVar1 < 0x13) {
    if ((iVar1 == 4) || (iVar1 == 0x12)) {
      if (*(char *)(DAT_007356a8 + 0x73) != '\0') {
        if (*(char *)(unaff_ESI + 0x223) == '\0') {
          *(undefined1 *)(unaff_ESI + 0x223) = 1;
          FUN_00538170();
          return;
        }
        if (*(char *)(DAT_007356a8 + 0x73) != '\0') {
          return;
        }
      }
      iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x20) + 0x7c))(0);
      if ((iVar1 != 4) &&
         (iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x20) + 0x7c))(1), iVar1 != 4)) {
        *(undefined1 *)(unaff_ESI + 0x223) = 0;
        return;
      }
    }
  }
  else if ((iVar1 < 0x1a) && (*(int *)(unaff_ESI + 0x1b0) == 4)) {
    if ((*(int *)(unaff_ESI + 0x1d0) == 0x4b1) &&
       (((*(char *)(unaff_ESI + 0x221) != '\0' && (*(char *)(unaff_ESI + 0x222) == '\0')) &&
        (*(char *)(unaff_ESI + 0x10) == '\0')))) {
      *(undefined1 *)(unaff_ESI + 0x222) = 1;
      FUN_00538170();
    }
    if (((*(char *)(unaff_ESI + 0x219) == '\x01') && (*(char *)(unaff_ESI + 0x21b) == '\0')) &&
       (*(char *)(unaff_ESI + 0x21d) == '\0')) {
      *(undefined1 *)(unaff_ESI + 0x21b) = 1;
      FUN_00538170();
    }
    if (((*(int *)(DAT_007356a8 + 0xa0) != 0) &&
        (iVar1 = *(int *)(*(int *)(DAT_007356a8 + 0xa0) + 4), iVar1 != 0)) &&
       ((*(int *)(iVar1 + 0x188) == 1 &&
        (((*(char *)(unaff_ESI + 0x21a) == '\x01' && (*(char *)(unaff_ESI + 0x21c) == '\0')) &&
         (*(char *)(unaff_ESI + 0x21e) == '\0')))))) {
      *(undefined1 *)(unaff_ESI + 0x21c) = 1;
      FUN_00538170();
    }
    if ((*(char *)(unaff_ESI + 0x21d) == '\x01') && (*(char *)(unaff_ESI + 0x21f) == '\0')) {
      *(undefined1 *)(unaff_ESI + 0x21f) = 1;
      FUN_00538170();
    }
    if (((*(int *)(DAT_007356a8 + 0xa0) != 0) &&
        (iVar1 = *(int *)(*(int *)(DAT_007356a8 + 0xa0) + 4), iVar1 != 0)) &&
       ((*(int *)(iVar1 + 0x188) == 1 &&
        ((*(char *)(unaff_ESI + 0x21e) == '\x01' && (*(char *)(unaff_ESI + 0x220) == '\0')))))) {
      *(undefined1 *)(unaff_ESI + 0x220) = 1;
      FUN_00538170();
    }
  }
  return;
}


// ==== 0x538360 FUN_00538360

void FUN_00538360(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  int in_EAX;
  undefined4 uVar6;
  int iVar7;
  bool bVar8;
  
  puVar4 = DAT_0073619c;
  if ((DAT_007361f0 != (undefined4 *)0x0) && (DAT_0073619c != (undefined4 *)0x0)) {
    *(undefined4 *)(in_EAX + 0x1b4) = *DAT_007361f0;
    *(undefined4 *)(in_EAX + 0x1bc) = *puVar4;
    EAXS_StreamManager__GetCurrentAmbientZone();
    uVar6 = Zone_Find(DAT_0078a2fc);
    *(undefined4 *)(in_EAX + 700) = uVar6;
    if ((*(int *)(in_EAX + 0x1b4) != *(int *)(in_EAX + 0x1b0)) ||
       (*(int *)(in_EAX + 0x1bc) != *(int *)(in_EAX + 0x1b8))) {
      FUN_00537db0();
    }
    FUN_005381b0();
    iVar2 = DAT_007356a8;
    switch(DAT_0078a2f0) {
    case 0x4b1:
      if (*(char *)(DAT_007356a8 + 0x70) != '\0') {
        *(undefined1 *)(in_EAX + 0x221) = 1;
      }
    case 0x4b2:
    case 0x4b6:
    case 0x4b7:
    case 0x4ba:
    case 0x4be:
      iVar2 = *(int *)(iVar2 + 0xa0);
      if (iVar2 == 0) {
        iVar7 = 0;
      }
      else if (*(int *)(iVar2 + 4) == 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = *(int *)(*(int *)(iVar2 + 4) + 0x188);
      }
      iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0x168);
      if (*(int *)(iVar3 + 0x28) == 1) {
        bVar8 = *(int *)(*(int *)(*(int *)(iVar3 + 0x34) + 0x48) + 0x94) != 0;
      }
      else {
        bVar8 = false;
      }
      *(bool *)(in_EAX + 0x219) = bVar8;
      if (iVar7 == 1) {
        uVar5 = FUN_0042a690();
        *(undefined1 *)(in_EAX + 0x21a) = uVar5;
      }
      cVar1 = *(char *)(*(int *)(*(int *)(iVar2 + 4) + 0x168) + 0x874);
      *(char *)(in_EAX + 0x21d) = cVar1;
      if (cVar1 == '\x01') {
        *(undefined1 *)(in_EAX + 0x21e) = 0;
      }
      if (iVar7 == 1) {
        *(undefined1 *)(in_EAX + 0x21e) =
             *(undefined1 *)(*(int *)(*(int *)(iVar2 + 4) + 0x16c) + 0x874);
      }
    default:
    }
  }
  return;
}


// ==== 0x5384e0 FUN_005384e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005384e0(void)

{
  int iVar1;
  char cVar2;
  int in_EAX;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  LARGE_INTEGER local_14;
  int local_c;
  char local_5;
  
  QueryPerformanceCounter(&local_14);
  uVar3 = DAT_007349c8;
  local_c = __allshr();
  local_c = local_c - *(int *)(in_EAX + 0x27c);
  if (local_c < 0) {
    local_c = 0;
  }
  local_14.s.HighPart = 1 << ((byte)uVar3 & 0x1f);
  *(float *)(in_EAX + 0x278) = (float)local_14.s.HighPart * (float)local_c * _DAT_007301d0;
  QueryPerformanceCounter(&local_14);
  uVar3 = __allshr();
  iVar6 = DAT_007356a8;
  *(undefined4 *)(in_EAX + 0x27c) = uVar3;
  iVar4 = 0;
  *(undefined4 *)(in_EAX + 0x240) = DAT_00740500;
  piVar5 = (int *)(iVar6 + 0xc4);
  do {
    if (((*piVar5 != 0) && (iVar6 = *(int *)(*piVar5 + 0x234), iVar6 != 0)) &&
       (iVar1 = *(int *)(iVar6 + 0x14), *(int *)(iVar1 + 4) == 1)) {
      if ((*(char *)(iVar1 + 0x734) == '\0') && (iVar4 == 0)) {
        *(int *)(in_EAX + 0x244) = iVar6;
        goto LAB_005385c6;
      }
      if ((*(char *)(iVar1 + 0x734) == '\0') && (iVar4 == 1)) {
        *(int *)(in_EAX + 0x248) = iVar6;
        goto LAB_005385c6;
      }
    }
    iVar4 = iVar4 + 1;
    piVar5 = piVar5 + 1;
    if (1 < iVar4) {
LAB_005385c6:
      if ((DAT_0077aadc == '\0') || (7 < *(int *)(in_EAX + 0x94))) {
        *(undefined1 *)(in_EAX + 0x1a4) = 0;
      }
      else {
        *(undefined1 *)(in_EAX + 0x1a4) = 1;
      }
      local_5 = '\0';
      *(undefined4 *)(in_EAX + 0x50) = 0;
      if (*(int *)(in_EAX + 0x1c0) != 5) {
        FUN_00538360();
      }
      iVar6 = 0;
      piVar5 = (int *)(in_EAX + 0x14);
      do {
        if (((int *)*piVar5 != (int *)0x0) &&
           (cVar2 = (**(code **)(*(int *)*piVar5 + 0x2c))(), cVar2 == '\0')) {
          *(int *)(in_EAX + 0x3c + *(int *)(in_EAX + 0x50) * 4) = iVar6;
          *(int *)(in_EAX + 0x50) = *(int *)(in_EAX + 0x50) + 1;
          local_5 = '\x01';
        }
        iVar6 = iVar6 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar6 < 5);
      if (local_5 == '\x01') {
        FUN_00538690();
      }
      piVar5 = (int *)(in_EAX + 0x14);
      iVar6 = 5;
      do {
        if ((int *)*piVar5 != (int *)0x0) {
          (**(code **)(*(int *)*piVar5 + 0x30))();
        }
        piVar5 = piVar5 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      *(undefined4 *)(in_EAX + 0x1d8) = *(undefined4 *)(in_EAX + 0x1dc);
      *(undefined4 *)(in_EAX + 0x1e0) = *(undefined4 *)(in_EAX + 0x1e4);
      *(undefined1 *)(in_EAX + 0x1d4) = *(undefined1 *)(in_EAX + 0x1d5);
      *(undefined1 *)(in_EAX + 0x218) = 0;
      return;
    }
  } while( true );
}


// ==== 0x538690 FUN_00538690

void FUN_00538690(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_ESI;
  float local_4;
  
  iVar4 = 0;
  *(undefined4 *)(unaff_ESI + 0x80) = 0;
  *(undefined4 *)(unaff_ESI + 0x84) = 0;
  *(undefined4 *)(unaff_ESI + 0x88) = 0;
  if (0 < *(int *)(unaff_ESI + 0x50)) {
    piVar3 = (int *)(unaff_ESI + 0x3c);
    do {
      cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x14 + *piVar3 * 4) + 0x34))();
      if (cVar1 != '\0') {
        iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x14 + *piVar3 * 4) + 0x88))();
        if (iVar2 == 0) {
          *(int *)(unaff_ESI + 0x68 + *(int *)(unaff_ESI + 0x84) * 4) = *piVar3;
          *(int *)(unaff_ESI + 0x84) = *(int *)(unaff_ESI + 0x84) + 1;
        }
        else {
          *(int *)(unaff_ESI + 0x54 + *(int *)(unaff_ESI + 0x88) * 4) = *piVar3;
          *(int *)(unaff_ESI + 0x88) = *(int *)(unaff_ESI + 0x88) + 1;
        }
      }
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar4 < *(int *)(unaff_ESI + 0x50));
  }
  if ((*(int *)(unaff_ESI + 0x88) != 0) && (DAT_0077aadc != '\0')) {
    iVar4 = 0;
    local_4 = 0.0;
    if (0 < *(int *)(unaff_ESI + 0x88)) {
      piVar3 = (int *)(unaff_ESI + 0x54);
      do {
        (**(code **)(**(int **)(unaff_ESI + 0x14 + *piVar3 * 4) + 0x58))(local_4);
        local_4 = local_4 + 250.0;
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar4 < *(int *)(unaff_ESI + 0x88));
    }
  }
  return;
}


// ==== 0x538770 EAXS_StreamManager::SetupWorldDataTransitionData

/* [canon] audio med (ghidra) docs/re/sound.md */

void EAXS_StreamManager__SetupWorldDataTransitionData(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  LARGE_INTEGER local_c;
  
  iVar1 = DAT_00740500;
  QueryPerformanceCounter(&local_c);
  uVar2 = __allshr();
  *(int *)(unaff_ESI + 0x90) = iVar1 + 0x40;
  *(undefined4 *)(unaff_ESI + 0x7c) = uVar2;
  *(undefined4 *)(unaff_ESI + 0x94) = 0;
  return;
}


// ==== 0x5387c0 EAXS_StreamManager::GetCurrentAmbientZone

/* [canon] audio med (ghidra) docs/re/sound.md */

undefined4 EAXS_StreamManager__GetCurrentAmbientZone(void)

{
  short sVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if ((*(int *)(in_EAX + 0x264) == 0) && (*(int *)(in_EAX + 0x268) == 0)) {
    return 0xffffffff;
  }
  iVar2 = *(int *)(DAT_007356a8 + 0xc4);
  iVar5 = 0;
  if (iVar2 != 0) {
    iVar5 = *(int *)(iVar2 + 0x234);
  }
  iVar4 = 0;
  if (iVar5 == 0) {
    if (DAT_00740500 == 0) goto LAB_0053881c;
    iVar2 = DAT_00740500 + 0x40;
  }
  else {
    iVar2 = *(int *)(iVar2 + 0x234) + 0x60;
  }
  iVar4 = StreamBoundaries__FindContaining(iVar2);
LAB_0053881c:
  *(undefined1 *)(in_EAX + 0x1a5) = 0;
  if (iVar4 != 0) {
    sVar1 = *(short *)(iVar4 + 8);
    *(char *)(in_EAX + 0x1d5) =
         (((char)((int)sVar1 / 100) + (char)(sVar1 >> 7)) -
         (char)((longlong)(int)sVar1 * 0x51eb851f >> 0x3f)) + '@';
    iVar2 = (int)*(short *)(iVar4 + 8) % 100;
    *(int *)(in_EAX + 0x1e4) = iVar2;
    if ((*(char *)(in_EAX + 0x1d5) != *(char *)(in_EAX + 0x1d4)) ||
       (iVar2 != *(int *)(in_EAX + 0x1e0))) {
      *(undefined1 *)(in_EAX + 0x218) = 1;
      EAXS_StreamManager__SetupWorldDataTransitionData();
      uVar3 = FUN_00538c50();
      return uVar3;
    }
  }
  return 0xffffffff;
}


// ==== 0x538890 FUN_00538890

void __fastcall FUN_00538890(undefined4 param_1)

{
  int in_EAX;
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  *(undefined4 *)(in_EAX + 0x1c8) = param_1;
  *(undefined4 *)(in_EAX + 0x1cc) = param_1;
  iVar2 = 8;
  switch(param_1) {
  case 1:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f4ff8;
    *(undefined4 *)(in_EAX + 0x26c) = 5;
    break;
  case 2:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f50c0;
    *(undefined4 *)(in_EAX + 0x26c) = 4;
    break;
  case 3:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f5160;
    *(undefined4 *)(in_EAX + 0x26c) = 3;
    break;
  case 4:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f51d8;
    *(undefined4 *)(in_EAX + 0x26c) = 4;
    break;
  case 5:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f5278;
    *(undefined4 *)(in_EAX + 0x26c) = 4;
    break;
  case 6:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f5318;
    *(undefined4 *)(in_EAX + 0x26c) = 5;
    break;
  case 7:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f53e0;
    *(undefined4 *)(in_EAX + 0x26c) = 4;
    break;
  case 8:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f5480;
    *(undefined4 *)(in_EAX + 0x26c) = 6;
    break;
  default:
    uVar3 = 0;
    *(undefined4 *)(in_EAX + 0x264) = 0;
    *(undefined4 *)(in_EAX + 0x268) = 0;
    goto LAB_00538bb9;
  case 0xb:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f5818;
    *(undefined4 *)(in_EAX + 0x26c) = 5;
    break;
  case 0xc:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f58e0;
    *(undefined4 *)(in_EAX + 0x26c) = 9;
    break;
  case 0xd:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f5a48;
    goto LAB_00538a2d;
  case 0xe:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f5b88;
    *(undefined **)(in_EAX + 0x268) = &DAT_006f6918;
    uVar3 = 10;
    goto LAB_00538bb9;
  case 0xf:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f5d18;
    *(undefined **)(in_EAX + 0x268) = &DAT_006f6918;
    *(undefined4 *)(in_EAX + 0x26c) = 9;
    *(undefined4 *)(in_EAX + 0x270) = 10;
    goto LAB_00538bc5;
  case 0x10:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f5e80;
    *(undefined **)(in_EAX + 0x268) = &DAT_006f6918;
    uVar3 = 10;
LAB_00538bb9:
    *(undefined4 *)(in_EAX + 0x26c) = uVar3;
    *(undefined4 *)(in_EAX + 0x270) = uVar3;
    goto LAB_00538bc5;
  case 0x11:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f6010;
LAB_00538a2d:
    *(undefined4 *)(in_EAX + 0x26c) = 8;
    break;
  case 0x12:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f6150;
    *(undefined **)(in_EAX + 0x268) = &DAT_006f6918;
    *(undefined4 *)(in_EAX + 0x26c) = 7;
    *(undefined4 *)(in_EAX + 0x270) = 10;
    goto LAB_00538bc5;
  case 0x13:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f6268;
    *(undefined **)(in_EAX + 0x268) = &DAT_006f6918;
    *(undefined4 *)(in_EAX + 0x26c) = 3;
    *(undefined4 *)(in_EAX + 0x270) = 10;
    goto LAB_00538bc5;
  case 0x14:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f62e0;
    *(undefined **)(in_EAX + 0x268) = &DAT_006f6918;
    *(undefined4 *)(in_EAX + 0x26c) = 3;
    *(undefined4 *)(in_EAX + 0x270) = 10;
    goto LAB_00538bc5;
  case 0x15:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f63d0;
    *(undefined **)(in_EAX + 0x268) = &DAT_006f6918;
    *(undefined4 *)(in_EAX + 0x26c) = 3;
    *(undefined4 *)(in_EAX + 0x270) = 10;
    goto LAB_00538bc5;
  case 0x16:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f6448;
    *(undefined **)(in_EAX + 0x268) = &DAT_006f6918;
    *(undefined4 *)(in_EAX + 0x26c) = 3;
    *(undefined4 *)(in_EAX + 0x270) = 10;
    goto LAB_00538bc5;
  case 0x17:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f64c0;
    *(undefined **)(in_EAX + 0x268) = &DAT_006f6918;
    *(undefined4 *)(in_EAX + 0x26c) = 3;
    *(undefined4 *)(in_EAX + 0x270) = 10;
    goto LAB_00538bc5;
  case 0x18:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f6538;
    *(undefined **)(in_EAX + 0x268) = &DAT_006f6918;
    *(undefined4 *)(in_EAX + 0x26c) = 3;
    *(undefined4 *)(in_EAX + 0x270) = 10;
    goto LAB_00538bc5;
  case 0x1a:
    *(undefined **)(in_EAX + 0x264) = &DAT_006f5660;
    *(undefined **)(in_EAX + 0x268) = &DAT_006f6918;
    *(undefined4 *)(in_EAX + 0x26c) = 0xb;
    *(undefined4 *)(in_EAX + 0x270) = 10;
    goto LAB_00538bc5;
  }
  *(undefined **)(in_EAX + 0x268) = &DAT_006f6918;
  *(undefined4 *)(in_EAX + 0x270) = 10;
LAB_00538bc5:
  puVar1 = (undefined4 *)(in_EAX + 0x98);
  do {
    *puVar1 = 0xbf800000;
    puVar1 = puVar1 + 8;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== 0x538c50 FUN_00538c50

undefined4 __fastcall FUN_00538c50(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  int *piVar7;
  
  iVar6 = *(int *)(param_1 + 0x268);
  iVar1 = *(int *)(param_1 + 0x270);
  iVar3 = 0;
  do {
    if (((*(int *)(iVar6 + iVar1 * iVar3 * 4) == (int)*(char *)(param_1 + 0x1d5)) &&
        (uVar2 = *(uint *)(param_1 + 0x1e4), 0 < (int)uVar2)) && ((int)uVar2 < iVar1)) {
      iVar6 = 0;
      *(undefined4 *)(param_1 + 0x204) = 0xffffffff;
      uVar4 = (int)*(char *)(param_1 + 0x1d5) << 8 | uVar2;
      puVar5 = &DAT_006f661c;
      do {
        if (puVar5[-5] == uVar4) {
          *(int *)(param_1 + 0x204) = iVar6;
        }
        if (*puVar5 == uVar4) {
          *(int *)(param_1 + 0x204) = iVar6 + 1;
        }
        if (puVar5[5] == uVar4) {
          *(int *)(param_1 + 0x204) = iVar6 + 2;
        }
        puVar5 = puVar5 + 0xf;
        iVar6 = iVar6 + 3;
      } while ((int)puVar5 < 0x6f6928);
      iVar6 = *(int *)(param_1 + 0x268);
      *(undefined4 *)(param_1 + 0x208) = *(undefined4 *)(iVar6 + (uVar2 + iVar1 * iVar3) * 4);
      *(undefined4 *)(param_1 + 600) = *(undefined4 *)(&DAT_006f6fe0 + DAT_00735608 * 8);
      *(undefined4 *)(param_1 + 0x250) = *(undefined4 *)(&DAT_006f6fe4 + DAT_00735608 * 8);
      DAT_00735608 = DAT_00735608 + 1 & 3;
      iVar3 = 0xe;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xe);
  iVar6 = 0;
  *(undefined4 *)(param_1 + 0x20c) = 0xffffffff;
  do {
    if ((&DAT_006f5570)[iVar6 * 10] == (int)*(char *)(param_1 + 0x1d5)) {
      *(undefined4 *)(param_1 + 0x20c) = (&DAT_006f5570)[*(int *)(param_1 + 0x1e4) + iVar6 * 10];
      iVar6 = 6;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 6);
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x26c)) {
    piVar7 = *(int **)(param_1 + 0x264);
    do {
      if (((*piVar7 == (int)*(char *)(param_1 + 0x1d5)) && (0 < *(int *)(param_1 + 0x1e4))) &&
         (*(int *)(param_1 + 0x1e4) < iVar1)) {
        *(int *)(param_1 + 0x1dc) = iVar6;
        *(int *)(param_1 + 500) =
             (*(int **)(param_1 + 0x264))[iVar1 * iVar6 + *(int *)(param_1 + 0x1e4)];
        return 0;
      }
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + iVar1;
    } while (iVar6 < *(int *)(param_1 + 0x26c));
  }
  return 0xffffffff;
}


// ==== 0x538df0 FUN_00538df0

void FUN_00538df0(void)

{
  int unaff_EBX;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(unaff_EBX + 0x14);
  iVar2 = 5;
  do {
    if ((int *)*piVar1 != (int *)0x0) {
      (**(code **)(*(int *)*piVar1 + 0xa0))();
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_005384e0();
  return;
}


// ==== 0x538e20 FUN_00538e20

void FUN_00538e20(void)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(in_EAX + 0x14);
  iVar2 = 5;
  do {
    if ((int *)*piVar1 != (int *)0x0) {
      (**(code **)(*(int *)*piVar1 + 0x24))();
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== 0x538e50 FUN_00538e50

void FUN_00538e50(void)

{
  return;
}


// ==== 0x538e60 FUN_00538e60

undefined4 FUN_00538e60(void)

{
  return 1;
}


// ==== 0x538e70 FUN_00538e70

float10 FUN_00538e70(void)

{
  return (float10)60.0;
}


// ==== 0x538e80 FUN_00538e80

undefined4 * __thiscall FUN_00538e80(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006bdd40;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x538ea0 FUN_00538ea0

void __fastcall FUN_00538ea0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bdd40;
  return;
}


// ==== 0x538eb0 FUN_00538eb0

void __fastcall FUN_00538eb0(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}


// ==== 0x538ed0 EAXS_StreamControl::SetMasterVolume

/* [canon] audio high (ghidra) docs/re/sound.md */

void __thiscall EAXS_StreamControl__SetMasterVolume(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  if (*(int *)(param_1 + 0x2c) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x24) = param_2;
    FUN_00539b10();
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x24) = param_2;
    FUN_00539b10();
  }
  return;
}


// ==== 0x538f10 EAXS_StreamControl::DelayStartBy

/* [canon] audio high (ghidra) docs/re/sound.md */

void __thiscall EAXS_StreamControl__DelayStartBy(int param_1,undefined4 param_2)

{
  if (*(int *)(*(int *)(param_1 + 0x2c) + 0xc) == 2) {
    *(undefined4 *)(*(int *)(param_1 + 0x2c) + 8) = 3;
    *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xc) = 3;
    *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x74) = param_2;
  }
  if (*(int *)(*(int *)(param_1 + 0x30) + 0xc) == 2) {
    *(undefined4 *)(*(int *)(param_1 + 0x30) + 8) = 3;
    *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc) = 3;
    *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x74) = param_2;
  }
  return;
}


// ==== 0x538f60 EAXS_StreamControl::SetStreamStage

/* [canon] audio high (ghidra) docs/re/sound.md */

void __thiscall EAXS_StreamControl__SetStreamStage(int param_1,undefined4 param_2)

{
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x14) = param_2;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x14) = param_2;
  return;
}


// ==== 0x538f80 EAXS_StreamControl::UpdateStreams

/* [canon] audio high (ghidra) docs/re/sound.md */

undefined4 __fastcall EAXS_StreamControl__UpdateStreams(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  uint uVar4;
  
  if (*(int *)(*(int *)(param_1 + 4) + 0x10) == 0) {
    return CONCAT31((int3)((uint)*(int *)(param_1 + 4) >> 8),1);
  }
  iVar1 = *(int *)(param_1 + 0x1c);
  *(int *)(param_1 + 0x20) = iVar1;
  iVar2 = *(int *)(param_1 + 0x2c + iVar1 * 4);
  *(undefined1 *)(iVar1 + 0x24 + param_1) = 1;
  if (*(int *)(iVar2 + 0x14) == 1) {
    uVar3 = FUN_00539560();
    *(undefined1 *)(param_1 + 0x24 + *(int *)(param_1 + 0x20)) = uVar3;
  }
  uVar4 = *(int *)(param_1 + 0x20) - 1U & 1;
  *(uint *)(param_1 + 0x20) = uVar4;
  iVar1 = *(int *)(param_1 + 0x2c + uVar4 * 4);
  *(undefined1 *)(uVar4 + 0x24 + param_1) = 1;
  if (*(int *)(iVar1 + 0x14) == 1) {
    uVar3 = FUN_00539560();
    *(undefined1 *)(param_1 + 0x24 + *(int *)(param_1 + 0x20)) = uVar3;
  }
  if ((*(char *)(param_1 + 0x24) != '\0') && (*(char *)(param_1 + 0x25) != '\0')) {
    return 1;
  }
  return 0;
}


// ==== 0x539000 FUN_00539000

void __fastcall FUN_00539000(int *param_1)

{
  param_1[8] = param_1[7];
  (**(code **)(*param_1 + 0xb0))();
  param_1[8] = param_1[8] - 1U & 1;
                    /* WARNING: Could not recover jumptable at 0x00539020. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xb0))();
  return;
}


// ==== 0x539030 FUN_00539030

void __fastcall FUN_00539030(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[param_1[8] + 0xb];
  if (*(int *)(iVar1 + 0x14) != 1) {
    return;
  }
  if (*(char *)(param_1[8] + 0x24 + (int)param_1) != '\x01') {
    switch(*(undefined4 *)(iVar1 + 0xc)) {
    case 0:
      (**(code **)(*param_1 + 0xc0))();
      break;
    case 1:
      (**(code **)(*param_1 + 0x5c))();
      break;
    case 2:
      (**(code **)(*param_1 + 0xb4))();
      break;
    case 4:
      (**(code **)(*param_1 + 0xc4))();
      break;
    case 8:
      (**(code **)(*param_1 + 200))();
    }
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0xc);
    goto LAB_00539110;
  }
  switch(*(undefined4 *)(iVar1 + 0xc)) {
  case 0:
    if (*(int *)(iVar1 + 8) != 0) {
      (**(code **)(*param_1 + 0xc0))();
      *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0xc);
      goto LAB_00539110;
    }
    break;
  case 1:
    (**(code **)(*param_1 + 0xac))();
    break;
  case 2:
    (**(code **)(*param_1 + 0xb4))();
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0xc);
    goto LAB_00539110;
  case 4:
    (**(code **)(*param_1 + 0xc4))();
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0xc);
    goto LAB_00539110;
  case 8:
    (**(code **)(*param_1 + 0xac))();
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0xc);
    goto LAB_00539110;
  }
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0xc);
LAB_00539110:
  *(undefined4 *)(param_1[param_1[8] + 0xd] + 0x210) = *(undefined4 *)(param_1[1] + 200);
  return;
}


// ==== 0x539180 FUN_00539180

void __fastcall FUN_00539180(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00539182. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 200))();
  return;
}


// ==== 0x539190 FUN_00539190

void __fastcall FUN_00539190(int *param_1)

{
  param_1[8] = 0;
  (**(code **)(*param_1 + 0xbc))();
  param_1[8] = 1;
                    /* WARNING: Could not recover jumptable at 0x005391ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xbc))();
  return;
}


// ==== 0x5391c0 FUN_005391c0

void FUN_005391c0(void)

{
  return;
}


// ==== 0x5391d0 FUN_005391d0

void __fastcall FUN_005391d0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x2c + *(int *)(param_1 + 0x20) * 4);
  if (*(int *)(iVar1 + 8) == 7) {
    *(undefined4 *)(iVar1 + 0xc) = 10;
  }
  return;
}


// ==== 0x5391f0 FUN_005391f0

void __fastcall FUN_005391f0(int param_1)

{
  if (*(int *)(*(int *)(param_1 + 0x2c) + 8) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xc) = 0;
  }
  if (*(int *)(*(int *)(param_1 + 0x30) + 8) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc) = 0;
  }
  return;
}


// ==== 0x539210 EAXS_Streams::InitializeStream

/* [canon] audio med (ghidra) docs/re/sound.md */

void __thiscall
EAXS_Streams__InitializeStream
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x218) = param_2;
  *(undefined4 *)(param_1 + 0x220) = 0;
  *(undefined4 *)(param_1 + 0x224) = 0;
  *(undefined4 *)(param_1 + 0x228) = 0;
  *(undefined4 *)(param_1 + 0x22c) = 0;
  *(undefined4 *)(param_1 + 0x238) = 0;
  *(undefined4 *)(param_1 + 0x248) = 0;
  *(undefined4 *)(param_1 + 600) = 0;
  *(undefined4 *)(param_1 + 0x25c) = 0;
  *(undefined4 *)(param_1 + 0x260) = 0;
  *(undefined4 *)(param_1 + 0x264) = 0;
  *(undefined4 *)(param_1 + 0x268) = 0;
  *(undefined4 *)(param_1 + 0x26c) = 0;
  *(undefined4 *)(param_1 + 0x270) = 0;
  *(undefined4 *)(param_1 + 0x290) = 0;
  *(undefined4 *)(param_1 + 0x250) = 1;
  *(undefined4 *)(param_1 + 0x254) = 1;
  uVar1 = DAT_006f4f68;
  *(undefined4 *)(param_1 + 0x298) = param_6;
  *(undefined4 *)(param_1 + 0x284) = uVar1;
  uVar1 = DAT_006f4f6c;
  *(undefined4 *)(param_1 + 0x2a8) = param_7;
  *(undefined4 *)(param_1 + 0x21c) = param_3;
  *(undefined4 *)(param_1 + 0x280) = uVar1;
  uVar1 = DAT_007355e0;
  *(undefined4 *)(param_1 + 0x2ac) = param_8;
  *(undefined4 *)(param_1 + 0x230) = param_4;
  *(undefined4 *)(param_1 + 0x28c) = uVar1;
  uVar1 = DAT_006f4f70;
  *(undefined4 *)(param_1 + 0x244) = 0x7fff;
  *(undefined4 *)(param_1 + 0x240) = 0x7fff;
  *(undefined4 *)(param_1 + 0x24c) = 0x4000;
  *(undefined4 *)(param_1 + 0x288) = uVar1;
  *(undefined4 *)(param_1 + 0x2a0) = param_5;
  *(undefined4 *)(param_1 + 0x23c) = 0x7fff;
  FUN_00539d10(param_5);
  return;
}


// ==== 0x539320 FUN_00539320

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00539320(int param_1)

{
  float fVar1;
  
  if (*(float *)(param_1 + 0x28c) < 0.0 != (*(float *)(param_1 + 0x28c) == 0.0)) {
    *(undefined4 *)(param_1 + 0x224) = 2;
    *(undefined4 *)(param_1 + 0x290) = 0;
    return 0;
  }
  fVar1 = *(float *)(param_1 + 0x290);
  *(float *)(param_1 + 0x290) = *(float *)(param_1 + 0x210) + *(float *)(param_1 + 0x290);
  if (_K_ONE <= fVar1 / *(float *)(param_1 + 0x28c)) {
    *(undefined4 *)(param_1 + 0x290) = 0;
    *(undefined4 *)(param_1 + 0x224) = 2;
    return 0;
  }
  return 1;
}


// ==== 0x5393a0 FUN_005393a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005393a0(void)

{
  float fVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar2 = 0;
  if (0.0 <= *(float *)(unaff_ESI + 0x280)) {
    fVar1 = *(float *)(unaff_ESI + 0x290);
    *(float *)(unaff_ESI + 0x290) = *(float *)(unaff_ESI + 0x210) + *(float *)(unaff_ESI + 0x290);
    if (_K_ONE < fVar1 / *(float *)(unaff_ESI + 0x280)) {
      *(undefined4 *)(unaff_ESI + 0x290) = 0;
      *(undefined4 *)(unaff_ESI + 0x224) = 0;
      *(undefined4 *)(unaff_ESI + 0x244) = 0;
      return 0;
    }
    iVar2 = _ftol_nocw();
    iVar2 = (&DAT_006f7220)[iVar2];
    *(undefined4 *)(unaff_ESI + 0x224) = 1;
  }
  iVar2 = (*(int *)(unaff_ESI + 0x240) * iVar2 >> 0xf) * *(int *)(unaff_ESI + 0x50) >> 0xf;
  *(int *)(unaff_ESI + 0x244) = iVar2;
  return iVar2;
}


// ==== 0x539430 FUN_00539430

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00539430(void)

{
  float fVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar2 = 0x7fff;
  if (0.0 <= *(float *)(unaff_ESI + 0x284)) {
    fVar1 = *(float *)(unaff_ESI + 0x290);
    *(float *)(unaff_ESI + 0x290) = *(float *)(unaff_ESI + 0x210) + *(float *)(unaff_ESI + 0x290);
    if (fVar1 / *(float *)(unaff_ESI + 0x284) <= _K_ONE) {
      iVar2 = _ftol_nocw();
      iVar2 = (&DAT_006f7220)[iVar2];
      *(undefined4 *)(unaff_ESI + 0x224) = 8;
    }
    else {
      *(undefined4 *)(unaff_ESI + 0x220) = 4;
      *(undefined4 *)(unaff_ESI + 0x224) = 4;
      *(undefined4 *)(unaff_ESI + 0x290) = 0;
    }
  }
  *(int *)(unaff_ESI + 0x244) =
       (*(int *)(unaff_ESI + 0x240) * iVar2 >> 0xf) * *(int *)(unaff_ESI + 0x50) >> 0xf;
  return;
}


// ==== 0x5394d0 FUN_005394d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_005394d0(int param_1)

{
  if (0.0 <= *(float *)(param_1 + 0x288)) {
    if (_K_ONE < *(float *)(param_1 + 0x290) / *(float *)(param_1 + 0x288)) {
      *(undefined4 *)(param_1 + 0x224) = 1;
      *(undefined4 *)(param_1 + 0x290) = 0;
      return 0xffffffff;
    }
    *(float *)(param_1 + 0x290) = *(float *)(param_1 + 0x210) + *(float *)(param_1 + 0x290);
  }
  return 0;
}


// ==== 0x539530 FUN_00539530

void FUN_00539530(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x228) = 2;
  *(undefined4 *)(in_EAX + 0x220) = 2;
  *(undefined4 *)(in_EAX + 0x224) = 2;
  *(undefined4 *)(in_EAX + 0x290) = 0;
  return;
}


// ==== 0x539560 FUN_00539560

bool FUN_00539560(void)

{
  int iVar1;
  int iVar2;
  int *in_EAX;
  bool bVar3;
  
  iVar1 = in_EAX[0x88];
  iVar2 = in_EAX[0x89];
  bVar3 = iVar1 == iVar2;
  if (in_EAX[0x8b] == 1) {
    if (iVar1 == iVar2) {
      switch(iVar1) {
      case 1:
        FUN_005393a0();
        break;
      case 3:
        (**(code **)(*in_EAX + 0x30))();
        break;
      case 4:
        (**(code **)(*in_EAX + 0x34))();
        break;
      case 8:
        FUN_00539430();
      }
      return in_EAX[0x88] == in_EAX[0x89];
    }
    switch(iVar2) {
    case 0:
      in_EAX[0x88] = 0;
      in_EAX[0x89] = 0;
      in_EAX[0x8a] = 0;
      return bVar3;
    case 1:
      FUN_005393a0();
      return bVar3;
    case 2:
      FUN_00539530();
      return bVar3;
    case 3:
      in_EAX[0x88] = 3;
      break;
    case 7:
      in_EAX[0x8a] = iVar1;
      in_EAX[0x88] = 7;
      return bVar3;
    case 8:
      FUN_00539430();
      return bVar3;
    case 10:
      in_EAX[0x88] = in_EAX[0x8a];
      in_EAX[0x89] = in_EAX[0x8a];
      return bVar3;
    }
  }
  return bVar3;
}


// ==== 0x5396a0 FUN_005396a0

undefined4 FUN_005396a0(void)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int local_8;
  int local_4;
  
  iVar8 = DAT_007356a8;
  local_8 = *(int *)(in_EAX + 0x268);
  if (local_8 < 0) {
    local_8 = *(int *)(in_EAX + 0x260);
  }
  switch(*(undefined4 *)(in_EAX + 0x230)) {
  case 0:
    *(int *)(in_EAX + 0x260) = local_8;
    *(undefined4 *)(in_EAX + 0x264) = *(undefined4 *)(in_EAX + 0x26c);
    goto LAB_00539a89;
  default:
    iVar3 = local_8 * 4;
    uVar9 = *(uint *)(iVar3 + *(int *)(in_EAX + 0x2a8));
    if ((int)uVar9 < 1) {
LAB_005397da:
      *(undefined4 *)(in_EAX + 0x26c) = 0;
    }
    else {
      uVar9 = DAT_007356d8 % uVar9;
      uVar6 = DAT_007356d8 ^ 0x1d872b41;
      uVar4 = uVar6 >> 5 ^ uVar6;
      DAT_007356d8 = uVar4 << 0x1b ^ uVar4 ^ uVar6;
      *(uint *)(in_EAX + 0x26c) = uVar9;
    }
    break;
  case 2:
    *(undefined4 *)(in_EAX + 0x26c) = *(undefined4 *)(in_EAX + 0x264);
    return 0;
  case 3:
    iVar3 = local_8 * 4;
    iVar7 = *(int *)(iVar3 + *(int *)(in_EAX + 0x2a8));
    if (iVar7 < 1) goto LAB_005397da;
    uVar2 = FUN_0051cd20(DAT_007356a8,iVar7);
    *(undefined4 *)(in_EAX + 0x26c) = uVar2;
    break;
  case 4:
    if (*(int *)(in_EAX + 0x2a0) < 1) {
      *(undefined4 *)(in_EAX + 0x268) = 0;
    }
    else {
      uVar2 = FUN_0051cd20(DAT_007356a8,*(int *)(in_EAX + 0x2a0));
      *(undefined4 *)(in_EAX + 0x268) = uVar2;
    }
    local_8 = *(int *)(in_EAX + 0x268);
    iVar3 = local_8 * 4;
    iVar7 = *(int *)(iVar3 + *(int *)(in_EAX + 0x2a8));
    if (iVar7 < 1) goto LAB_005397da;
    uVar2 = FUN_0051cd20(iVar8,iVar7);
    *(undefined4 *)(in_EAX + 0x26c) = uVar2;
  }
  if (local_8 < 0) {
    iVar7 = *(int *)(iVar3 + *(int *)(in_EAX + 0x2b4));
    local_4 = *(int *)(iVar3 + *(int *)(in_EAX + 0x2a8));
  }
  else {
    iVar7 = *(int *)(iVar3 + *(int *)(in_EAX + 0x2b4));
    local_4 = *(int *)(iVar3 + *(int *)(in_EAX + 0x2a8));
  }
  iVar3 = *(int *)(in_EAX + 0x26c);
  iVar1 = *(int *)(in_EAX + 0x2b0);
  if (*(int *)(iVar1 + (iVar3 + iVar7) * 4) != 0) {
    if (*(int *)(in_EAX + 0x218) == 0) {
      if ((DAT_0077a920 == 3) ||
         (uVar9 = DAT_00758934, *(int *)(*(int *)(iVar8 + 0x104) + 0x1b0) == 8)) {
        uVar9 = DAT_00758930;
      }
      if (uVar9 == 0) {
        return 0xffffffff;
      }
      if ((uVar9 & 1 << ((byte)iVar3 & 0x1f)) != 0) {
        *(undefined4 *)(iVar1 + (iVar3 + iVar7) * 4) = 0;
        goto LAB_00539a89;
      }
      uVar4 = FUN_0051cd20(iVar8,10);
      iVar8 = *(int *)(in_EAX + 0x26c);
      if (uVar4 < 6) {
        if (iVar8 < local_4) {
          iVar3 = (iVar8 + iVar7) * 4;
          do {
            piVar5 = (int *)(*(int *)(in_EAX + 0x2b0) + iVar3);
            if (*piVar5 != 0) {
              *piVar5 = 0;
              *(int *)(in_EAX + 0x26c) = iVar8;
              if ((uVar9 & 1 << ((byte)iVar8 & 0x1f)) != 0) goto LAB_005399e6;
            }
            iVar8 = iVar8 + 1;
            iVar3 = iVar3 + 4;
          } while (iVar8 < local_4);
        }
        iVar8 = *(int *)(in_EAX + 0x26c);
        if (-1 < iVar8) {
          iVar3 = (iVar8 + iVar7) * 4;
          do {
            if (*(int *)(*(int *)(in_EAX + 0x2b0) + iVar3) != 0) {
              *(undefined4 *)(*(int *)(in_EAX + 0x2b0) + iVar3) = 0;
              *(int *)(in_EAX + 0x26c) = iVar8;
              if ((uVar9 & 1 << ((byte)iVar8 & 0x1f)) != 0) {
                iVar8 = iVar8 + iVar7;
                goto LAB_00539a7c;
              }
            }
            iVar8 = iVar8 + -1;
            iVar3 = iVar3 + -4;
          } while (-1 < iVar8);
        }
      }
      else {
        if (-1 < iVar8) {
          iVar3 = (iVar8 + iVar7) * 4;
          do {
            if (*(int *)(*(int *)(in_EAX + 0x2b0) + iVar3) != 0) {
              *(undefined4 *)(*(int *)(in_EAX + 0x2b0) + iVar3) = 0;
              *(int *)(in_EAX + 0x26c) = iVar8;
              if ((uVar9 & 1 << ((byte)iVar8 & 0x1f)) != 0) goto LAB_005399e6;
            }
            iVar8 = iVar8 + -1;
            iVar3 = iVar3 + -4;
          } while (-1 < iVar8);
        }
        iVar8 = *(int *)(in_EAX + 0x26c);
        if (iVar8 < local_4) {
          iVar3 = (iVar8 + iVar7) * 4;
          do {
            piVar5 = (int *)(*(int *)(in_EAX + 0x2b0) + iVar3);
            if (*piVar5 != 0) {
              *piVar5 = 0;
              *(int *)(in_EAX + 0x26c) = iVar8;
              if ((uVar9 & 1 << ((byte)iVar8 & 0x1f)) != 0) goto LAB_005399e6;
            }
            iVar8 = iVar8 + 1;
            iVar3 = iVar3 + 4;
          } while (iVar8 < local_4);
        }
      }
      iVar8 = FUN_00539dd0(local_8);
      if (iVar8 == -1) {
        return 0xffffffff;
      }
    }
    *(undefined4 *)(*(int *)(in_EAX + 0x2b0) + (*(int *)(in_EAX + 0x26c) + iVar7) * 4) = 0;
    goto LAB_00539a89;
  }
  if (-1 < iVar3) {
    piVar5 = (int *)(iVar1 + (iVar3 + iVar7) * 4);
    iVar8 = iVar3;
    do {
      if (*piVar5 != 0) {
        *(undefined4 *)(iVar1 + (iVar7 + iVar8) * 4) = 0;
        *(int *)(in_EAX + 0x26c) = iVar8;
        goto LAB_00539a89;
      }
      iVar8 = iVar8 + -1;
      piVar5 = piVar5 + -1;
    } while (-1 < iVar8);
  }
  if (iVar3 < local_4) {
    piVar5 = (int *)(iVar1 + (iVar3 + iVar7) * 4);
    do {
      if (*piVar5 != 0) {
        *(undefined4 *)(iVar1 + (iVar3 + iVar7) * 4) = 0;
        *(int *)(in_EAX + 0x26c) = iVar3;
        goto LAB_00539a89;
      }
      iVar3 = iVar3 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar3 < local_4);
  }
  iVar8 = FUN_00539dd0(local_8);
  if (iVar8 == -1) {
    return 0xffffffff;
  }
  iVar8 = *(int *)(in_EAX + 0x26c) + iVar7;
LAB_00539a7c:
  *(undefined4 *)(*(int *)(in_EAX + 0x2b0) + iVar8 * 4) = 0;
LAB_00539a89:
  *(int *)(in_EAX + 0x260) = local_8;
  *(undefined4 *)(in_EAX + 0x264) = *(undefined4 *)(in_EAX + 0x26c);
  return 0;
LAB_005399e6:
  iVar8 = iVar8 + iVar7;
  goto LAB_00539a7c;
}


// ==== 0x539ac0 EAXS_Streams::Update3DParams

/* [canon] audio med (ghidra) docs/re/sound.md */

void EAXS_Streams__Update3DParams(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x220) == 4) {
    iVar1 = *(int *)(unaff_ESI + 0x240);
  }
  else {
    iVar1 = *(int *)(unaff_ESI + 0x244);
  }
  *(int *)(unaff_ESI + 0x244) = *(int *)(unaff_ESI + 0x50) * iVar1 >> 0xf;
  uVar2 = _ftol_nocw();
  *(undefined4 *)(unaff_ESI + 0x24c) = uVar2;
  *(undefined4 *)(unaff_ESI + 0x248) = *(undefined4 *)(unaff_ESI + 0x4c);
  return;
}


// ==== 0x539b10 FUN_00539b10

void FUN_00539b10(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = *(int *)(in_EAX + 0x264);
  iVar1 = *(int *)(in_EAX + 0x260);
  if (0 < iVar1) {
    piVar3 = *(int **)(in_EAX + 0x2a8);
    iVar4 = iVar1;
    do {
      iVar2 = iVar2 + *piVar3;
      piVar3 = piVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  *(int *)(in_EAX + 0x270) = iVar2;
  iVar2 = *(int *)(*(int *)(in_EAX + 0x2ac) + iVar1 * 4);
  *(int *)(in_EAX + 0x240) = iVar2;
  *(uint *)(in_EAX + 0x244) = (uint)(0xf < *(int *)(in_EAX + 0x23c) * iVar2);
  return;
}


// ==== 0x539b70 EAXS_Streams::SetupStartParameters

/* [canon] audio med (ghidra) docs/re/sound.md */

undefined4 EAXS_Streams__SetupStartParameters(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int unaff_ESI;
  LARGE_INTEGER local_8;
  
  iVar2 = FUN_005396a0();
  if (iVar2 == -1) {
    return 0xffffffff;
  }
  iVar2 = *(int *)(unaff_ESI + 0x264);
  iVar1 = *(int *)(unaff_ESI + 0x260);
  if (0 < iVar1) {
    piVar4 = *(int **)(unaff_ESI + 0x2a8);
    iVar5 = iVar1;
    do {
      iVar2 = iVar2 + *piVar4;
      piVar4 = piVar4 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  *(int *)(unaff_ESI + 0x270) = iVar2;
  if (*(int *)(unaff_ESI + 0x218) < 4) {
    *(undefined4 *)(unaff_ESI + 0x240) = *(undefined4 *)(*(int *)(unaff_ESI + 0x2ac) + iVar1 * 4);
  }
  else {
    *(undefined4 *)(unaff_ESI + 0x240) = 0x7fff;
  }
  iVar2 = *(int *)(unaff_ESI + 0x23c) * *(int *)(unaff_ESI + 0x240) >> 0xf;
  *(int *)(unaff_ESI + 0x244) = iVar2;
  *(undefined4 *)(unaff_ESI + 0x22c) = 1;
  switch(*(undefined4 *)(unaff_ESI + 0x21c)) {
  case 0:
  case 3:
    *(undefined4 *)(unaff_ESI + 0x220) = 4;
    *(undefined4 *)(unaff_ESI + 0x224) = 4;
    *(int *)(unaff_ESI + 0x244) = iVar2;
    *(undefined4 *)(unaff_ESI + 0x24c) = 0x1000;
    goto LAB_00539c9a;
  case 1:
  case 4:
    *(undefined4 *)(unaff_ESI + 0x220) = 8;
    *(undefined4 *)(unaff_ESI + 0x224) = 8;
    *(undefined4 *)(unaff_ESI + 0x24c) = 0x1000;
    break;
  case 2:
  case 5:
    *(undefined4 *)(unaff_ESI + 0x220) = 4;
    *(undefined4 *)(unaff_ESI + 0x224) = 4;
    *(int *)(unaff_ESI + 0x244) = *(int *)(unaff_ESI + 0x50) * iVar2 >> 0xf;
    *(undefined4 *)(unaff_ESI + 0x248) = *(undefined4 *)(unaff_ESI + 0x4c);
    uVar3 = _ftol_nocw();
    *(undefined4 *)(unaff_ESI + 0x24c) = uVar3;
    goto LAB_00539ca0;
  default:
    *(undefined4 *)(unaff_ESI + 0x220) = 0;
    *(undefined4 *)(unaff_ESI + 0x224) = 0;
    *(undefined4 *)(unaff_ESI + 0x24c) = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x244) = 0;
LAB_00539c9a:
  *(undefined4 *)(unaff_ESI + 0x248) = 0;
LAB_00539ca0:
  local_8.s.LowPart = *(int *)(unaff_ESI + 0x29c) * 1000;
  *(undefined4 *)(unaff_ESI + 0x290) = 0;
  *(float *)(unaff_ESI + 0x234) =
       ((float)(int)local_8.s.LowPart + (float)(int)local_8.s.LowPart) /
       (float)*(int *)(unaff_ESI + 0x298);
  QueryPerformanceCounter(&local_8);
  uVar3 = __allshr();
  *(undefined4 *)(unaff_ESI + 0x294) = uVar3;
  return 0;
}


// ==== 0x539d10 FUN_00539d10

void FUN_00539d10(int param_1)

{
  void *pvVar1;
  int unaff_EBX;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  pvVar1 = _malloc(param_1 * 4);
  *(void **)(unaff_EBX + 0x2b4) = pvVar1;
  if (0 < param_1) {
    do {
      *(int *)(*(int *)(unaff_EBX + 0x2b4) + iVar2 * 4) = iVar3;
      iVar3 = iVar3 + *(int *)(*(int *)(unaff_EBX + 0x2a8) + iVar2 * 4);
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1);
  }
  pvVar1 = _malloc(iVar3 * 4);
  *(int *)(unaff_EBX + 0x2a4) = iVar3;
  *(void **)(unaff_EBX + 0x2b0) = pvVar1;
  return;
}


// ==== 0x539d80 FUN_00539d80

void FUN_00539d80(void)

{
  int unaff_ESI;
  
  if (*(void **)(unaff_ESI + 0x2b4) != (void *)0x0) {
    _free(*(void **)(unaff_ESI + 0x2b4));
    *(undefined4 *)(unaff_ESI + 0x2b4) = 0;
  }
  if (*(void **)(unaff_ESI + 0x2b0) != (void *)0x0) {
    _free(*(void **)(unaff_ESI + 0x2b0));
    *(undefined4 *)(unaff_ESI + 0x2b0) = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x224) = 0;
  *(undefined4 *)(unaff_ESI + 0x220) = 0;
  *(undefined4 *)(unaff_ESI + 0x22c) = 0;
  return;
}


// ==== 0x539dd0 FUN_00539dd0

undefined4 FUN_00539dd0(int param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int unaff_ESI;
  
  piVar4 = *(int **)(unaff_ESI + 0x2a8);
  iVar3 = 0;
  *(undefined4 *)(unaff_ESI + 0x264) = 0;
  *(int *)(unaff_ESI + 0x260) = param_1;
  iVar1 = piVar4[param_1];
  if (*(int *)(unaff_ESI + 0x218) == 0) {
    bVar2 = false;
    if ((DAT_0077a920 == 3) ||
       (uVar5 = DAT_00758934, *(int *)(*(int *)(DAT_007356a8 + 0x104) + 0x1b0) == 8)) {
      uVar5 = DAT_00758930;
    }
    iVar3 = 0;
    if (0 < param_1) {
      iVar7 = *(int *)(unaff_ESI + 0x260);
      do {
        iVar3 = iVar3 + *piVar4;
        piVar4 = piVar4 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    if (iVar3 < iVar1) {
      do {
        if ((uVar5 & 1 << ((byte)iVar3 & 0x1f)) != 0) {
          bVar2 = true;
          *(undefined4 *)(*(int *)(unaff_ESI + 0x2b0) + iVar3 * 4) = 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
      if (bVar2) goto LAB_00539ea8;
    }
    return 0xffffffff;
  }
  if (0 < param_1) {
    iVar7 = *(int *)(unaff_ESI + 0x260);
    do {
      iVar3 = iVar3 + *piVar4;
      piVar4 = piVar4 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  for (; iVar3 < iVar1; iVar3 = iVar3 + 1) {
    *(undefined4 *)(*(int *)(unaff_ESI + 0x2b0) + iVar3 * 4) = 1;
  }
LAB_00539ea8:
  uVar8 = DAT_007356d8 % *(uint *)(*(int *)(unaff_ESI + 0x2a8) + param_1 * 4);
  uVar6 = DAT_007356d8 ^ 0x1d872b41;
  uVar5 = uVar6 >> 5 ^ uVar6;
  DAT_007356d8 = uVar5 << 0x1b ^ uVar5 ^ uVar6;
  *(uint *)(unaff_ESI + 0x26c) = uVar8;
  return 0;
}


// ==== 0x539ef0 FUN_00539ef0

void __fastcall FUN_00539ef0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int unaff_EBX;
  int unaff_ESI;
  
  if (in_EAX < 0) {
    in_EAX = 0;
  }
  else if (7 < in_EAX) {
    in_EAX = 7;
  }
  piVar1 = (int *)(unaff_ESI + 4);
  *piVar1 = in_EAX;
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (0xff < param_1) {
    param_1 = 0xff;
  }
  *(int *)(unaff_ESI + 8) = param_1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0x7fff < param_2) {
    param_2 = 0x7fff;
  }
  *(int *)(unaff_ESI + 0xc) = param_2;
  if (unaff_EBX < 0) {
    unaff_EBX = 0;
  }
  else if (0x1fff < unaff_EBX) {
    unaff_EBX = 0x1fff;
  }
  *(int *)(unaff_ESI + 0x10) = unaff_EBX;
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0xffff < param_3) {
    param_3 = 0xffff;
  }
  *(int *)(unaff_ESI + 0x14) = param_3;
  iVar2 = Csis__Class__CreateInstance(&DAT_0073d7e4,piVar1);
  if (iVar2 < 0) {
    Csis__ClassHandle__Set(&PTR_s_AMBIENT_MONO_STREAM_006f2220);
    Csis__Class__CreateInstance(&DAT_0073d7e4,piVar1);
  }
  return;
}


// ==== 0x539fb0 FUN_00539fb0

void __thiscall
FUN_00539fb0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 uVar3;
  
  *(undefined4 *)(param_1 + 0x314) = 3;
  *(undefined4 *)(param_1 + 0x5f4) = 3;
  *(undefined4 *)(param_1 + 0x318) = 0x443b8000;
  *(undefined4 *)(param_1 + 0x5f8) = 0x443b8000;
  *(int *)(param_1 + 0x5f0) = param_1 + 0x548;
  *(int *)(param_1 + 0x30) = param_1 + 0x548;
  *(int *)(param_1 + 0x310) = param_1 + 0x268;
  *(int *)(param_1 + 0x2c) = param_1 + 0x268;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x28) = 2;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 800) = 0;
  *(int **)(param_1 + 0x34) = (int *)(param_1 + 0x50);
  *(int **)(param_1 + 0x38) = (int *)(param_1 + 0x330);
  uVar3 = param_8;
  (**(code **)(*(int *)(param_1 + 0x50) + 0x2c))(param_2,param_3,3,param_5,param_6,param_7,param_8);
  (**(code **)(*(int *)(param_1 + 0x330) + 0x2c))
            (param_7,uVar3,3,unaff_ESI,unaff_EBP,unaff_EBX,param_8);
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x70) = 0xbf800000;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x70) = 0xbf800000;
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x38) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x38) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x24) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x38) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x24) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 800) = 0;
  iVar2 = DAT_007356a8;
  piVar1 = *(int **)(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  piVar1[0x2f] = (int)&DAT_006f4880;
  piVar1[0x81] = *(int *)(*(int *)(iVar2 + 0xa0) + 4);
  (**(code **)(*piVar1 + 0x24))();
  iVar2 = DAT_007356a8;
  piVar1 = *(int **)(param_1 + 0x38);
  piVar1[0x2f] = (int)&DAT_006f4880;
  piVar1[0x81] = *(int *)(*(int *)(iVar2 + 0xa0) + 4);
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== 0x53a110 FUN_0053a110

undefined4 __thiscall FUN_0053a110(int param_1,int param_2)

{
  return CONCAT31((int3)((uint)(param_2 * 0x2e0) >> 8),
                  *(int *)(param_2 * 0x2e0 + 0x40 + param_1) != 0);
}


// ==== 0x53a130 FUN_0053a130

void __fastcall FUN_0053a130(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *local_14 [4];
  
  local_14[0] = (int *)param_1[0xb];
  if ((*(int *)(param_1[0xc4] + 0x2c) == 0) &&
     (((*(int *)(param_1[1] + 0x28) != DAT_007355d8 && (*(int *)(param_1[1] + 0x30) != DAT_007355dc)
       ) || ((*(int *)(param_1[1] + 0x28) == DAT_007355d8 &&
             (*(int *)(param_1[1] + 0x30) != DAT_007355dc)))))) {
    *(undefined4 *)(param_1[0xc4] + 0xc) = 0;
    DAT_007355d8 = *(int *)(param_1[1] + 0x28);
    DAT_007355dc = *(int *)(param_1[1] + 0x30);
  }
  if ((local_14[0][5] == 1) && (iVar3 = param_1[1], *(int *)(iVar3 + 0x58) != -1)) {
    if ((int *)param_1[0x10] == (int *)0x0) {
      if ((*(char *)(iVar3 + 0x68) == '\x01') && (*(int *)(iVar3 + 0x18) < 0x13)) {
        iVar3 = FUN_0051cd20(DAT_007356a8,4);
        *(undefined4 *)(param_1[1] + 0x50) =
             *(undefined4 *)(&DAT_006f660c + (iVar3 + *(int *)(param_1[1] + 0x54) * 5) * 4);
        *(undefined4 *)(param_1[0xc4] + 0x50) = *(undefined4 *)(param_1[1] + 0x50);
        *(undefined4 *)(param_1[1] + 0x4c) = *(undefined4 *)(param_1[1] + 0x50);
        if (*(int *)(param_1[0xc4] + 0x18) == 3) {
          *(undefined4 *)(param_1[1] + 0x9c) = *(undefined4 *)(param_1[1] + 0xa0);
          *(undefined4 *)(param_1[1] + 0xa4) = *(undefined4 *)(param_1[1] + 0xa8);
          iVar3 = (iVar3 + *(int *)(param_1[1] + 0x54) * 4) * 0x10;
          uVar1 = *(undefined4 *)(&DAT_00704e54 + iVar3);
          *(undefined4 *)(param_1[1] + 0x80) = *(undefined4 *)(&DAT_00704e50 + iVar3);
          *(undefined4 *)(param_1[1] + 0x84) = uVar1;
          *(undefined4 *)(param_1[1] + 0x88) = 0;
          *(undefined4 *)(param_1[0xc4] + 0x74) = 0x43fa0000;
          *(undefined4 *)(param_1[0xc4] + 0x78) = 0;
          *(undefined4 *)(param_1[0xc4] + 0x6c) = 0x42c80000;
          *(undefined4 *)(param_1[0xc4] + 0xc) = 2;
          *(undefined4 *)(param_1[0xc4] + 0x2c) = 1;
          EAXS_StreamControl__UpdateStreams();
          return;
        }
      }
    }
    else {
      local_14[0] = (int *)0x0;
      if (*(int *)param_1[0x10] != 0) {
        Csis__Class__GetRefCount(local_14);
      }
      param_1[6] = (int)local_14[0];
      if ((int)local_14[0] < param_1[5]) {
        piVar2 = (int *)param_1[0x10];
        if (piVar2 != (int *)0x0) {
          if (*piVar2 != 0) {
            FUN_0064bbd0();
          }
          Csis__System__GetAllocator(local_14);
          Mutex__Lock();
          (**(code **)(*local_14[0] + 4))(piVar2);
          Mutex__Unlock();
        }
        param_1[0x10] = 0;
        param_1[5] = param_1[6];
        EAXS_StreamControl__UpdateStreams();
        return;
      }
      (**(code **)(param_1[0x14] + 0x28))(param_1[1] + 0x80,0);
      EAXS_Streams__Update3DParams();
      (**(code **)(*param_1 + 200))();
    }
  }
  EAXS_StreamControl__UpdateStreams();
  return;
}


// ==== 0x53a370 FUN_0053a370

void __fastcall FUN_0053a370(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x310) + 0x14) = 1;
  return;
}


// ==== 0x53a380 FUN_0053a380

void __fastcall FUN_0053a380(int param_1)

{
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}


// ==== 0x53a390 FUN_0053a390

void __fastcall FUN_0053a390(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(param_1 + 0x310);
  iVar3 = 2;
  do {
    if (*(int *)(*piVar2 + 8) == 7) {
      if (piVar2[-0xb4] != 0) {
        iVar1 = *(int *)(*piVar2 + 0x34);
        if (iVar1 < 0) {
          iVar1 = 0;
        }
        else if (0x1fff < iVar1) {
          iVar1 = 0x1fff;
        }
        *(int *)(piVar2[-0xb4] + 0x10) = iVar1;
        iVar1 = *(int *)(*piVar2 + 0x2c);
        if (iVar1 < 0) {
          iVar1 = 0;
        }
        else if (0x7fff < iVar1) {
          iVar1 = 0x7fff;
        }
        *(int *)(piVar2[-0xb4] + 0xc) = iVar1;
        if (*(int *)piVar2[-0xb4] != 0) {
          FUN_0064bc30((int *)piVar2[-0xb4] + 1);
        }
      }
      *(undefined4 *)(*piVar2 + 0xc) = 4;
    }
    piVar2 = piVar2 + 0xb8;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


// ==== 0x53a420 FUN_0053a420

void __fastcall FUN_0053a420(int **param_1)

{
  int **ppiVar1;
  int *piVar2;
  int **ppiVar3;
  int iVar4;
  int *piVar5;
  undefined4 *unaff_EBX;
  void *unaff_ESI;
  int **ppiStack_28;
  int *local_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  pvStack_c = ExceptionList;
  piVar5 = param_1[8];
  piVar2 = param_1[(int)piVar5 + 0xb];
  ppiVar3 = (int **)param_1[(int)piVar5 * 0xb8 + 0x10];
  ppiVar1 = param_1 + (int)piVar5 * 0xb8 + 0x10;
  ExceptionList = &pvStack_c;
  if (ppiVar3 != (int **)0x0) {
    ExceptionList = &pvStack_c;
    if (*ppiVar3 != (int *)0x0) {
      ppiStack_28 = (int **)0x53a468;
      ExceptionList = &pvStack_c;
      FUN_0064bbd0();
    }
    ppiStack_28 = &local_10;
    Csis__System__GetAllocator();
    ppiStack_28 = (int **)0x53a47a;
    Mutex__Lock();
    ppiStack_28 = ppiVar3;
    (**(code **)(*local_10 + 4))();
    ppiStack_28 = (int **)0x53a489;
    Mutex__Unlock();
    *ppiVar1 = (int *)0x0;
  }
  ppiStack_28 = (int **)0x0;
  (*(code *)ppiVar1[4][10])(param_1[1] + 0x20);
  EAXS_Streams__Update3DParams();
  EAXS_Streams__SetupStartParameters();
  if (piVar2[2] != 0) {
    Csis__System__GetAllocator(&stack0xffffffe8);
    Mutex__Lock();
    iVar4 = (**(code **)*unaff_EBX)(0x18,4,0xffffffff);
    Mutex__Unlock();
    if (iVar4 == 0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_00539ef0(piVar2[0xc]);
      param_1 = ppiStack_28;
    }
    *ppiVar1 = piVar5;
    piVar2[0x1e] = 0;
    ppiStack_28 = (int **)0x0;
    if (**ppiVar1 != 0) {
      Csis__Class__GetRefCount(&ppiStack_28);
    }
    param_1[5] = (int *)ppiStack_28;
    DAT_007355d8 = param_1[1][10];
    DAT_007355dc = param_1[1][0xc];
    ExceptionList = unaff_ESI;
    return;
  }
  piVar2[0x1e] = 0;
  ExceptionList = param_1;
  return;
}


// ==== 0x53a580 FUN_0053a580

void __fastcall FUN_0053a580(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piStack_4;
  
  iVar1 = param_1[8];
  iVar2 = param_1[iVar1 + 0xb];
  piVar3 = (int *)param_1[iVar1 * 0xb8 + 0x10];
  if (piVar3 != (int *)0x0) {
    piStack_4 = param_1;
    if (*piVar3 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar3);
    Mutex__Unlock();
    param_1[iVar1 * 0xb8 + 0x10] = 0;
    if ((int *)param_1[(param_1[8] - 1U & 1) * 0xb8 + 0x10] != (int *)0x0) {
      if (*(int *)param_1[(param_1[8] - 1U & 1) * 0xb8 + 0x10] != 0) {
        Csis__Class__GetRefCount(&stack0xfffffff8);
      }
      param_1[5] = 0;
    }
    *(undefined4 *)(iVar2 + 0xc) = 0;
    return;
  }
  *(undefined4 *)(iVar2 + 0xc) = 0;
  return;
}


// ==== 0x53a620 FUN_0053a620

void __fastcall FUN_0053a620(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piStack_4;
  
  iVar2 = param_1[param_1[8] + 0xb];
  piVar1 = param_1 + param_1[8] * 0xb8 + 0x10;
  if (*(int *)(param_1[1] + 0x10) == 5) {
    piVar3 = (int *)*piVar1;
    if (piVar3 != (int *)0x0) {
      piStack_4 = param_1;
      if (*piVar3 != 0) {
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&piStack_4);
      Mutex__Lock();
      (**(code **)(*piStack_4 + 4))(piVar3);
      Mutex__Unlock();
      *piVar1 = 0;
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined4 *)(iVar2 + 0xc) = 0;
      return;
    }
  }
  else if ((int *)*piVar1 != (int *)0x0) {
    piStack_4 = (int *)0x0;
    if (*(int *)*piVar1 != 0) {
      Csis__Class__GetRefCount(&piStack_4);
    }
    if ((int)piStack_4 < param_1[5]) {
      piVar3 = (int *)*piVar1;
      if (piVar3 != (int *)0x0) {
        if (*piVar3 != 0) {
          FUN_0064bbd0();
        }
        Csis__System__GetAllocator(&piStack_4);
        Mutex__Lock();
        (**(code **)(*piStack_4 + 4))(piVar3);
        Mutex__Unlock();
      }
      *piVar1 = 0;
      *(undefined4 *)(piVar1[0xb4] + 0xc) = 0;
      *(undefined4 *)(piVar1[0xb4] + 8) = 0;
      return;
    }
    (**(code **)(piVar1[4] + 0x28))(param_1[1] + 0x80,0);
    EAXS_Streams__Update3DParams();
    (**(code **)(*param_1 + 200))();
  }
  return;
}


// ==== 0x53a730 FUN_0053a730

void __fastcall FUN_0053a730(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x20) * 0x2e0;
  iVar2 = *(int *)(param_1 + 0x310 + iVar1);
  param_1 = param_1 + iVar1;
  if ((*(int *)(iVar2 + 8) != 7) && (*(int *)(param_1 + 0x40) != 0)) {
    iVar2 = *(int *)(iVar2 + 0x2c);
    if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
      iVar2 = 0;
    }
    if ((DAT_007361f0 != (int *)0x0) && ((*DAT_007361f0 == 1 || (*DAT_007361f0 == 7)))) {
      iVar2 = 0;
    }
    iVar2 = (*(int *)(DAT_007356ac + 0x382c) * iVar2 >> 0xf) * *(int *)(DAT_007356ac + 0x3e18) >>
            0xf;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x7fff < iVar2) {
      iVar2 = 0x7fff;
    }
    *(int *)(*(int *)(param_1 + 0x40) + 0xc) = iVar2;
    iVar2 = *(int *)(*(int *)(param_1 + 0x310) + 0x34);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x1fff < iVar2) {
      iVar2 = 0x1fff;
    }
    *(int *)(*(int *)(param_1 + 0x40) + 0x10) = iVar2;
    iVar2 = *(int *)(*(int *)(param_1 + 0x310) + 0x30);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0xffff < iVar2) {
      iVar2 = 0xffff;
    }
    *(int *)(*(int *)(param_1 + 0x40) + 0x14) = iVar2;
    if (**(int **)(param_1 + 0x40) != 0) {
      FUN_0064bc30(*(int **)(param_1 + 0x40) + 1);
    }
  }
  return;
}


// ==== 0x53a820 FUN_0053a820

undefined4 __thiscall FUN_0053a820(int param_1,int param_2)

{
  return *(undefined4 *)(param_2 * 0x2e0 + 0x314 + param_1);
}


// ==== 0x53a840 FUN_0053a840

float10 __thiscall FUN_0053a840(int param_1,int param_2)

{
  return (float10)*(float *)(param_2 * 0x2e0 + 0x318 + param_1);
}


// ==== 0x53a860 FUN_0053a860

void __thiscall FUN_0053a860(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 * 0x2e0 + 0x314 + param_1) = param_3;
  return;
}


// ==== 0x53a880 FUN_0053a880

void __thiscall FUN_0053a880(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 * 0x2e0 + 0x318 + param_1) = param_3;
  return;
}


// ==== 0x53a8a0 FUN_0053a8a0

void __fastcall FUN_0053a8a0(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0x50) + 0x24))();
                    /* WARNING: Could not recover jumptable at 0x0053a8b9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0x330) + 0x24))();
  return;
}


// ==== 0x53a8c0 FUN_0053a8c0

undefined4 __fastcall FUN_0053a8c0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + param_1 + 0x310);
  param_1 = (*(int *)(param_1 + 0x20) - 1U & 1) * 0x2e0 + 0x40 + param_1;
  iVar2 = *(int *)(iVar1 + 0xc);
  if ((iVar2 != 1) || (bVar4 = true, *(int *)(*(int *)(param_1 + 0x2d0) + 8) != 0)) {
    bVar4 = false;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x2d0) + 0xc);
  if ((iVar3 == 1) && (*(int *)(iVar1 + 8) == 0)) {
    bVar5 = true;
  }
  else {
    bVar5 = false;
  }
  if ((((iVar2 != 2) && (!bVar4)) && (iVar3 != 2)) && (!bVar5)) {
    return 0;
  }
  return 1;
}


// ==== 0x53a950 FUN_0053a950

void __fastcall FUN_0053a950(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int unaff_EBX;
  int unaff_ESI;
  
  if (in_EAX < 0) {
    in_EAX = 0;
  }
  else if (7 < in_EAX) {
    in_EAX = 7;
  }
  piVar1 = (int *)(unaff_ESI + 4);
  *piVar1 = in_EAX;
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (0x1ff < param_1) {
    param_1 = 0x1ff;
  }
  *(int *)(unaff_ESI + 8) = param_1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0x7fff < param_2) {
    param_2 = 0x7fff;
  }
  *(int *)(unaff_ESI + 0xc) = param_2;
  if (unaff_EBX < 0) {
    unaff_EBX = 0;
  }
  else if (0x1fff < unaff_EBX) {
    unaff_EBX = 0x1fff;
  }
  *(int *)(unaff_ESI + 0x10) = unaff_EBX;
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0xffff < param_3) {
    param_3 = 0xffff;
  }
  *(int *)(unaff_ESI + 0x14) = param_3;
  iVar2 = Csis__Class__CreateInstance(&DAT_0073d7dc,piVar1);
  if (iVar2 < 0) {
    Csis__ClassHandle__Set(&PTR_s_AMBIENT_STEREO_STREAM_006f2218);
    Csis__Class__CreateInstance(&DAT_0073d7dc,piVar1);
  }
  return;
}


// ==== 0x53aa10 FUN_0053aa10

void __thiscall
FUN_0053aa10(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  *(int *)(param_1 + 0x30) = param_1 + 0x548;
  *(int *)(param_1 + 0x5f0) = param_1 + 0x548;
  *(int *)(param_1 + 0x310) = param_1 + 0x268;
  *(int *)(param_1 + 0x2c) = param_1 + 0x268;
  *(undefined4 *)(param_1 + 0x318) = 0x437a0000;
  *(undefined4 *)(param_1 + 0x5f8) = 0x437a0000;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x28) = 1;
  *(int **)(param_1 + 0x34) = (int *)(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0x314) = 1;
  *(undefined4 *)(param_1 + 0x5f4) = 1;
  *(int **)(param_1 + 0x38) = (int *)(param_1 + 0x330);
  *(undefined4 *)(param_1 + 0x2c8) = 0x437a0000;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x60) = 0x437a0000;
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 100) = 0x437a0000;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 100) = 0x437a0000;
  (**(code **)(*(int *)(param_1 + 0x50) + 0x2c))(param_2,param_3,3,param_5,param_6,param_7,param_8);
  (**(code **)(*(int *)(param_1 + 0x330) + 0x2c))
            (param_7,param_8,3,unaff_ESI,unaff_EBP,unaff_EBX,unaff_retaddr);
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x38) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x24) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x38) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x24) = *(undefined4 *)(param_1 + 8);
  piVar1 = *(int **)(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 800) = 0;
  iVar2 = DAT_007356a8;
  piVar1[0x2f] = (int)&DAT_006f4960;
  piVar1[0x81] = *(int *)(*(int *)(iVar2 + 0xa0) + 4);
  (**(code **)(*piVar1 + 0x24))();
  iVar2 = DAT_007356a8;
  piVar1 = *(int **)(param_1 + 0x38);
  piVar1[0x2f] = (int)&DAT_006f4960;
  piVar1[0x81] = *(int *)(*(int *)(iVar2 + 0xa0) + 4);
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== 0x53ab60 FUN_0053ab60

void __fastcall FUN_0053ab60(int *param_1)

{
  int *piVar1;
  int *piStack_4;
  
  piVar1 = (int *)param_1[0x10];
  piStack_4 = param_1;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar1);
    Mutex__Unlock();
    param_1[0x10] = 0;
  }
  piVar1 = (int *)param_1[200];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar1);
    Mutex__Unlock();
    param_1[200] = 0;
  }
  param_1[5] = 0;
  FUN_00539d80();
  FUN_00539d80();
  return;
}


// ==== 0x53ac00 FUN_0053ac00

undefined4 __fastcall FUN_0053ac00(int param_1)

{
  if (*(int *)(*(int *)(param_1 + 0x2c) + 0xc) == 2) {
    return *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x38);
  }
  if (*(int *)(*(int *)(param_1 + 0x30) + 0xc) == 2) {
    return *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x38);
  }
  return 1;
}


// ==== 0x53ac30 EAXS_AmbStereoStream::UpdateStreams

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall EAXS_AmbStereoStream__UpdateStreams(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  bVar5 = false;
  if (*(int *)(*(int *)(param_1 + 0x2c + *(int *)(param_1 + 0x20) * 4) + 0x14) == 1) {
    iVar6 = *(int *)(param_1 + 4);
    iVar7 = *(int *)(iVar6 + 0x44);
    if (iVar7 != -1) {
      iVar2 = *(int *)(iVar6 + 0x108);
      if (*(int *)(iVar6 + 0x10c) == iVar2) {
        if (iVar2 != 0) {
          if (*(int *)(iVar6 + 0x40) != iVar7) {
            *(int *)(iVar6 + 0x48) = iVar7;
          }
          iVar6 = *(int *)(*(int *)(param_1 + 4) + 0x5c);
          if (-1 < iVar6) {
            *(int *)(*(int *)(param_1 + 4) + 0x44) = iVar6;
          }
        }
      }
      else if (*(int *)(iVar6 + 0x10c) == 0) {
        *(undefined4 *)(iVar6 + 0x44) = *(undefined4 *)(iVar6 + 0x48);
        bVar5 = true;
        *(undefined4 *)(*(int *)(param_1 + 4) + 0x108) =
             *(undefined4 *)(*(int *)(param_1 + 4) + 0x10c);
      }
      else {
        if (iVar2 == 0) {
          *(int *)(iVar6 + 0x48) = iVar7;
          iVar6 = *(int *)(param_1 + 4);
        }
        if (-1 < *(int *)(iVar6 + 0x5c)) {
          *(int *)(iVar6 + 0x44) = *(int *)(iVar6 + 0x5c);
        }
        *(undefined4 *)(*(int *)(param_1 + 4) + 0x108) =
             *(undefined4 *)(*(int *)(param_1 + 4) + 0x10c);
        *(undefined4 *)(*(int *)(param_1 + 4) + 0x108) =
             *(undefined4 *)(*(int *)(param_1 + 4) + 0x10c);
      }
      piVar3 = *(int **)(param_1 + 4);
      if (piVar3[0x10] != piVar3[0x11]) {
        if ((piVar3[2] == 4) && (*piVar3 != 8)) {
          iVar6 = *(int *)(param_1 + 0x1c) * 0x2e0;
          if ((*(int *)(iVar6 + 0x40 + param_1) != 0) &&
             ((iVar6 = *(int *)(iVar6 + param_1 + 0x310), *(int *)(iVar6 + 8) == 4 &&
              (uVar8 = *(int *)(param_1 + 0x1c) - 1U & 1, 1000.0 < *(float *)(iVar6 + 0x78))))) {
            iVar7 = uVar8 * 0x2e0;
            iVar6 = *(int *)(iVar7 + 0x310 + param_1);
            piVar1 = (int *)(iVar7 + 0x310 + param_1);
            if (*(int *)(iVar6 + 0xc) != 2) {
              if (((*(int *)(DAT_007356a8 + 0xc4) == 0) ||
                  (iVar7 = *(int *)(*(int *)(DAT_007356a8 + 0xc4) + 0x234), iVar7 == 0)) ||
                 (0x12 < piVar3[6])) {
                *(undefined4 *)(iVar6 + 0x78) = 0;
                *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c) * 0x2e0 + 0x310 + param_1) + 0x78)
                     = 0;
                *(undefined4 *)(*piVar1 + 0x70) = 0x45dac000;
                *(undefined4 *)(*piVar1 + 0x6c) = 0x449c4000;
                *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c) * 0x2e0 + 0x310 + param_1) + 0x68)
                     = *(undefined4 *)(*piVar1 + 0x6c);
              }
              else {
                fVar4 = _K_ONE - *(float *)(iVar7 + 0x3d4) / 200.0;
                if ((piVar3[0x42] != 0) || (bVar5)) {
                  *(undefined4 *)(iVar6 + 0x6c) = 0x437a0000;
                  *(undefined4 *)(*piVar1 + 0x70) = 0x457a0000;
                }
                else {
                  *(float *)(iVar6 + 0x70) = fVar4 * 9000.0;
                  *(float *)(*piVar1 + 0x6c) = fVar4 * 1250.0 + 250.0;
                }
                *(undefined4 *)(*piVar1 + 0x78) = 0;
                *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c) * 0x2e0 + 0x310 + param_1) + 0x68)
                     = *(undefined4 *)(*piVar1 + 0x6c);
                *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c) * 0x2e0 + 0x310 + param_1) + 0x78)
                     = 0;
                *(undefined4 *)(*(int *)(param_1 + 4) + 0xe0) = *(undefined4 *)(iVar7 + 0x3d4);
                *(float *)(*(int *)(param_1 + 4) + 0xe4) = fVar4;
              }
              *(undefined4 *)(*piVar1 + 0xc) = 2;
              *(undefined4 *)(*piVar1 + 0x50) = *(undefined4 *)(*(int *)(param_1 + 4) + 0x44);
              *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c) * 0x2e0 + 0x310 + param_1) + 0xc) =
                   1;
              *(uint *)(param_1 + 0x1c) = uVar8;
            }
          }
        }
        if (*(int *)(param_1 + 0x20) == *(int *)(param_1 + 0x1c)) {
          *(undefined4 *)(*(int *)(param_1 + 4) + 0x40) =
               *(undefined4 *)(*(int *)(param_1 + 4) + 0x44);
        }
      }
    }
  }
  EAXS_StreamControl__UpdateStreams();
  return;
}


// ==== 0x53aed0 FUN_0053aed0

void __fastcall FUN_0053aed0(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piStack_4;
  
  piVar1 = (int *)param_1[param_1[7] * 0xb8 + 0x10];
  piVar2 = param_1 + param_1[7] * 0xb8 + 0x10;
  piStack_4 = param_1;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar1);
    Mutex__Unlock();
    *piVar2 = 0;
    *(undefined4 *)(piVar2[0xb4] + 0xc) = 0;
    *(undefined4 *)(piVar2[0xb4] + 8) = 0;
  }
  param_1 = param_1 + (param_1[7] - 1U & 1) * 0xb8 + 0x10;
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    if (*piVar2 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar2);
    Mutex__Unlock();
    *param_1 = 0;
    *(undefined4 *)(param_1[0xb4] + 0xc) = 0;
    *(undefined4 *)(param_1[0xb4] + 8) = 0;
  }
  return;
}


// ==== 0x53af90 FUN_0053af90

void __fastcall FUN_0053af90(int param_1)

{
  if (*(int *)(param_1 + 0x40) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x310) + 0xc) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x310) + 0x68) = 0x43fa0000;
    *(undefined4 *)(*(int *)(param_1 + 0x310) + 0x78) = 0;
  }
  if (*(int *)(param_1 + 800) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x5f0) + 0xc) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x5f0) + 0x68) = 0x43fa0000;
    *(undefined4 *)(*(int *)(param_1 + 0x5f0) + 0x78) = 0;
  }
  return;
}


// ==== 0x53aff0 FUN_0053aff0

void __fastcall FUN_0053aff0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piStack_4;
  
  iVar2 = param_1[7];
  if (param_1[iVar2 * 0xb8 + 0x10] != 0) {
    *(undefined4 *)(param_1[iVar2 * 0xb8 + 0xc4] + 0x78) = 0;
    *(undefined4 *)(param_1[iVar2 * 0xb8 + 0xc4] + 0xc) = 1;
  }
  uVar4 = param_1[7] - 1U & 1;
  param_1[7] = uVar4;
  piVar1 = param_1 + uVar4 * 0xb8 + 0x10;
  piVar3 = (int *)*piVar1;
  if (piVar3 != (int *)0x0) {
    piStack_4 = param_1;
    if (*piVar3 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar3);
    Mutex__Unlock();
    *piVar1 = 0;
  }
  if (*(int *)(param_1[1] + 0x38) == 1) {
    *(undefined4 *)(piVar1[0xb4] + 0x50) = 1;
  }
  else {
    *(undefined4 *)(piVar1[0xb4] + 0x50) = 2;
  }
  if (*(int *)(param_1[1] + 0x3c) == -1) {
    *(undefined4 *)(piVar1[0xb4] + 0x4c) = 0;
    *(undefined4 *)(piVar1[0xb4] + 0x18) = 1;
  }
  else {
    *(int *)(piVar1[0xb4] + 0x4c) = *(int *)(param_1[1] + 0x3c);
    *(undefined4 *)(piVar1[0xb4] + 0x18) = 0;
  }
  *(undefined4 *)(piVar1[0xb4] + 0x38) = 0;
  *(undefined4 *)(piVar1[0xb4] + 0x70) = 0x45fa0000;
  *(undefined4 *)(piVar1[0xb4] + 0xc) = 2;
  return;
}


// ==== 0x53b0f0 FUN_0053b0f0

void __fastcall FUN_0053b0f0(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  LARGE_INTEGER LStack_8;
  
  iVar3 = *(int *)(param_1 + 0x1c) * 0x2e0;
  piVar2 = *(int **)(iVar3 + 0x40 + param_1);
  puVar1 = (undefined4 *)(iVar3 + 0x40 + param_1);
  if (piVar2 != (int *)0x0) {
    if (*piVar2 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&LStack_8);
    Mutex__Lock();
    (**(code **)(*(int *)LStack_8.s.LowPart + 4))(piVar2);
    Mutex__Unlock();
    *puVar1 = 0;
  }
  if (*(int *)(*(int *)(param_1 + 4) + 0x3c) == -1) {
    *(undefined4 *)(puVar1[0xb4] + 0x70) = 0xbf800000;
    *(undefined4 *)(puVar1[0xb4] + 0x4c) = 0;
    *(undefined4 *)(puVar1[0xb4] + 0x54) = 0;
    *(undefined4 *)(puVar1[0xb4] + 0x50) = 0;
    *(undefined4 *)(puVar1[0xb4] + 0x18) = 0;
  }
  else {
    *(undefined4 *)(puVar1[0xb4] + 0x70) = 0xbf800000;
    *(undefined4 *)(puVar1[0xb4] + 0x6c) = 0x41a00000;
    *(undefined4 *)(puVar1[0xb4] + 0x4c) = *(undefined4 *)(*(int *)(param_1 + 4) + 0x3c);
    *(undefined4 *)(puVar1[0xb4] + 0x54) = *(undefined4 *)(*(int *)(param_1 + 4) + 0x3c);
    *(undefined4 *)(puVar1[0xb4] + 0x50) = 0;
    *(undefined4 *)(puVar1[0xb4] + 0x18) = 0;
  }
  *(undefined4 *)(puVar1[0xb4] + 4) = 4;
  *(undefined4 *)(puVar1[0xb4] + 0x38) = 0;
  *(undefined4 *)(puVar1[0xb4] + 0xc) = 2;
  *(undefined4 *)(puVar1[0xb4] + 0x14) = 1;
  QueryPerformanceCounter(&LStack_8);
  uVar4 = __allshr();
  *(undefined4 *)(param_1 + 0x600) = uVar4;
  return;
}


// ==== 0x53b220 EAXS_AmbStereoStream::EnterRaceCountDown

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall EAXS_AmbStereoStream__EnterRaceCountDown(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iStack_c;
  LARGE_INTEGER LStack_8;
  
  QueryPerformanceCounter(&LStack_8);
  uVar3 = DAT_007349c8;
  iStack_c = __allshr();
  iStack_c = iStack_c - *(int *)(param_1 + 0x600);
  if (iStack_c < 0) {
    iStack_c = 0;
  }
  iVar6 = *(int *)(param_1 + 0x1c) * 0x2e0;
  iVar5 = iVar6 + 0x40 + param_1;
  if (*(int *)(iVar6 + 0x40 + param_1) != 0) {
    LStack_8.s.LowPart = 1 << ((byte)uVar3 & 0x1f);
    if (*(float *)(&DAT_006f7e20 + *(int *)(*(int *)(param_1 + 4) + 0xd8) * 4) -
        (float)(int)LStack_8.s.LowPart * (float)iStack_c * _DAT_007301d0 < 100.0) {
      *(undefined4 *)(*(int *)(iVar5 + 0x2d0) + 0x70) = 0x45cb2000;
      *(undefined4 *)(*(int *)(iVar5 + 0x2d0) + 0x78) = 0;
      *(undefined4 *)(*(int *)(iVar5 + 0x2d0) + 0x18) = 3;
      *(undefined4 *)(*(int *)(iVar5 + 0x2d0) + 4) = 4;
      *(undefined4 *)(*(int *)(iVar5 + 0x2d0) + 0x38) = 1;
      *(undefined4 *)(*(int *)(iVar5 + 0x2d0) + 0x14) = 1;
      *(undefined4 *)
       (*(int *)((*(int *)(param_1 + 0x1c) - 1U & 1) * 0x2e0 + 0x310 + param_1) + 0x14) = 1;
      return;
    }
    *(undefined4 *)(*(int *)(iVar5 + 0x2d0) + 0x68) = 0x447a0000;
    *(undefined4 *)(*(int *)(iVar5 + 0x2d0) + 0x70) = 0x457a0000;
    *(undefined4 *)(*(int *)(iVar5 + 0x2d0) + 0x78) = 0;
    *(undefined4 *)(*(int *)(iVar5 + 0x2d0) + 0xc) = 1;
    *(undefined4 *)(*(int *)(iVar5 + 0x2d0) + 0x18) = 0;
    *(undefined4 *)(*(int *)(iVar5 + 0x2d0) + 4) = 4;
    *(undefined4 *)(*(int *)(iVar5 + 0x2d0) + 0x38) = 1;
  }
  uVar4 = *(int *)(param_1 + 0x1c) - 1U & 1;
  *(uint *)(param_1 + 0x1c) = uVar4;
  iVar5 = uVar4 * 0x2e0;
  piVar2 = *(int **)(iVar5 + 0x40 + param_1);
  puVar1 = (undefined4 *)(iVar5 + 0x40 + param_1);
  if (piVar2 != (int *)0x0) {
    if (*piVar2 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&LStack_8);
    Mutex__Lock();
    (**(code **)(*(int *)LStack_8.s.LowPart + 4))(piVar2);
    Mutex__Unlock();
    *puVar1 = 0;
  }
  *(undefined4 *)(puVar1[0xb4] + 0x70) = 0x45cb2000;
  *(undefined4 *)(puVar1[0xb4] + 0x50) = 4;
  *(undefined4 *)(puVar1[0xb4] + 0x54) = *(undefined4 *)(*(int *)(param_1 + 4) + 0x3c);
  *(undefined4 *)(puVar1[0xb4] + 0x4c) = *(undefined4 *)(*(int *)(param_1 + 4) + 0x3c);
  *(undefined4 *)(puVar1[0xb4] + 0x18) = 0;
  *(undefined4 *)(puVar1[0xb4] + 0x74) = 0;
  *(undefined4 *)(puVar1[0xb4] + 0x6c) = 0x42c80000;
  *(undefined4 *)(puVar1[0xb4] + 0xc) = 2;
  *(undefined4 *)(puVar1[0xb4] + 0x14) = 1;
  *(undefined4 *)(puVar1[0xb4] + 4) = 4;
  return;
}


// ==== 0x53b430 FUN_0053b430

void __fastcall FUN_0053b430(int param_1)

{
  int *piVar1;
  int **ppiVar2;
  int iVar3;
  undefined4 *unaff_EBX;
  int **ppiVar4;
  void *unaff_ESI;
  int **ppiStack_28;
  int *local_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  pvStack_c = ExceptionList;
  iVar3 = *(int *)(param_1 + 0x20);
  ppiVar4 = *(int ***)(param_1 + 0x2c + iVar3 * 4);
  piVar1 = (int *)(iVar3 * 0x2e0 + 0x40 + param_1);
  ExceptionList = &pvStack_c;
  if (((*(int *)(*(int *)(iVar3 * 0x2e0 + 0x310 + param_1) + 8) == 3) &&
      (ExceptionList = &pvStack_c, iVar3 != *(int *)(param_1 + 0x1c))) &&
     (iVar3 = *(int *)(param_1 + 0x1c) * 0x2e0, ExceptionList = &pvStack_c,
     *(int *)(iVar3 + 0x40 + param_1) != 0)) {
    ExceptionList = &pvStack_c;
    *(undefined4 *)(*(int *)(iVar3 + param_1 + 0x310) + 0x78) = 0;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c) * 0x2e0 + 0x310 + param_1) + 8) = 1;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c) * 0x2e0 + 0x310 + param_1) + 0xc) = 1;
  }
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x20);
  ppiVar2 = (int **)*piVar1;
  if (ppiVar2 != (int **)0x0) {
    if (*ppiVar2 != (int *)0x0) {
      ppiStack_28 = (int **)0x53b4d9;
      FUN_0064bbd0();
    }
    ppiStack_28 = &local_10;
    Csis__System__GetAllocator();
    ppiStack_28 = (int **)0x53b4eb;
    Mutex__Lock();
    ppiStack_28 = ppiVar2;
    (**(code **)(*local_10 + 4))();
    ppiStack_28 = (int **)0x53b4fa;
    Mutex__Unlock();
    *piVar1 = 0;
  }
  ppiStack_28 = (int **)0x0;
  (**(code **)(piVar1[4] + 0x28))(0);
  EAXS_Streams__Update3DParams();
  EAXS_Streams__SetupStartParameters();
  if (ppiVar4[2] != (int *)0x0) {
    Csis__System__GetAllocator(&stack0xffffffe8);
    Mutex__Lock();
    iVar3 = (**(code **)*unaff_EBX)(0x18,4,0xffffffff);
    Mutex__Unlock();
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_0053a950(ppiVar4[0xc]);
      ppiVar4 = ppiStack_28;
    }
    *piVar1 = iVar3;
    ppiVar4[0x1e] = (int *)0x0;
    ppiStack_28 = (int **)0x0;
    if (*(int *)*piVar1 != 0) {
      Csis__Class__GetRefCount(&ppiStack_28);
    }
    *(int ***)(param_1 + 0x14) = ppiStack_28;
    ExceptionList = unaff_ESI;
    return;
  }
  ppiVar4[0x1e] = (int *)0x0;
  ExceptionList = ppiVar4;
  return;
}


// ==== 0x53b5e0 FUN_0053b5e0

void __fastcall FUN_0053b5e0(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x40 + param_1);
  if (*(int *)(piVar1[0xb4] + 8) != 0) {
    if (*piVar1 != 0) {
      *(undefined4 *)(*piVar1 + 0x10) = 0;
      *(undefined4 *)(*piVar1 + 0xc) = 0;
      if (*(int *)*piVar1 != 0) {
        FUN_0064bc30((int *)*piVar1 + 1);
      }
    }
    *(undefined4 *)(piVar1[0xb4] + 0xc) = 7;
  }
  return;
}


// ==== 0x53b630 FUN_0053b630

void __fastcall FUN_0053b630(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x40 + param_1);
  if (*piVar1 != 0) {
    iVar2 = piVar1[0xb4];
    if (*(int *)(iVar2 + 0x48) == 0) {
      *(undefined4 *)(iVar2 + 0xc) = 0;
      return;
    }
    iVar2 = *(int *)(param_1 + 0x2c + *(int *)(param_1 + 0x20) * 4);
    if (*(int *)(iVar2 + 8) == 7) {
      *(undefined4 *)(iVar2 + 0xc) = 10;
    }
  }
  return;
}


// ==== 0x53b670 FUN_0053b670

void __fastcall FUN_0053b670(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piStack_8;
  int iStack_4;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x40 + param_1);
  iStack_4 = *(int *)(param_1 + 0x2c + *(int *)(param_1 + 0x20) * 4);
  if ((int *)*piVar1 != (int *)0x0) {
    piStack_8 = (int *)0x0;
    if (*(int *)*piVar1 != 0) {
      Csis__Class__GetRefCount(&piStack_8);
    }
    *(int **)(param_1 + 0x14) = piStack_8;
    piVar2 = (int *)*piVar1;
    if (piVar2 != (int *)0x0) {
      if (*piVar2 != 0) {
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&piStack_8);
      Mutex__Lock();
      (**(code **)(*piStack_8 + 4))(piVar2);
      Mutex__Unlock();
    }
    *piVar1 = 0;
    piVar1 = *(int **)((*(int *)(param_1 + 0x20) - 1U & 1) * 0x2e0 + 0x40 + param_1);
    if (piVar1 != (int *)0x0) {
      piStack_8 = (int *)0x0;
      if (*piVar1 != 0) {
        Csis__Class__GetRefCount(&piStack_8);
      }
      *(int **)(param_1 + 0x14) = piStack_8;
      *(undefined4 *)(iStack_4 + 0xc) = 0;
      return;
    }
  }
  *(undefined4 *)(iStack_4 + 0xc) = 0;
  return;
}


// ==== 0x53b740 FUN_0053b740

void __fastcall FUN_0053b740(int *param_1)

{
  (**(code **)(param_1[param_1[8] * 0xb8 + 0x14] + 0x28))(0,0);
  EAXS_Streams__Update3DParams();
                    /* WARNING: Could not recover jumptable at 0x0053b76b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 200))();
  return;
}


// ==== 0x53b780 FUN_0053b780

void __fastcall FUN_0053b780(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piStack_4;
  
  piVar1 = param_1 + param_1[8] * 0xb8 + 0x10;
  if ((int *)param_1[param_1[8] * 0xb8 + 0x10] == (int *)0x0) {
    *(undefined4 *)(piVar1[0xb4] + 8) = 0;
    *(undefined4 *)(piVar1[0xb4] + 0xc) = 0;
  }
  else {
    piStack_4 = (int *)0x0;
    if (*(int *)param_1[param_1[8] * 0xb8 + 0x10] != 0) {
      Csis__Class__GetRefCount(&piStack_4);
    }
    iVar2 = param_1[8];
    uVar4 = iVar2 - 1U & 1;
    piVar3 = param_1 + uVar4 * 0xb8 + 0x10;
    param_1[6] = (int)piStack_4;
    if (param_1[5] <= (int)piStack_4) {
      (**(code **)(piVar1[4] + 0x28))(0,0);
      EAXS_Streams__Update3DParams();
      (**(code **)(*param_1 + 200))();
      return;
    }
    if (*(int *)(piVar1[0xb4] + 0x18) < 2) {
      if (iVar2 == param_1[7]) {
        if (*piVar3 == 0) {
          *(undefined4 *)(piVar1[0xb4] + 8) = 0;
          *(undefined4 *)(piVar1[0xb4] + 0xc) = 0;
          *(undefined4 *)(piVar1[0xb4] + 0x18) = 3;
          (**(code **)(*param_1 + 0xc0))();
          if (*(int *)(piVar3[0xb4] + 8) == 0) {
            *(undefined4 *)(piVar3[0xb4] + 0xc) = 2;
            return;
          }
        }
        else if (*(int *)(piVar3[0xb4] + 8) < 2) {
          param_1[8] = uVar4;
          *(undefined4 *)(piVar3[0xb4] + 8) = 0;
          *(undefined4 *)(piVar3[0xb4] + 0xc) = 0;
          (**(code **)(*param_1 + 0xc0))();
          param_1[8] = uVar4 - 1 & 1;
          param_1[5] = param_1[6];
          return;
        }
      }
    }
    else if (iVar2 == param_1[7]) {
      if ((*piVar3 != 0) && (*(int *)(piVar3[0xb4] + 8) < 2)) {
        param_1[8] = uVar4;
        *(undefined4 *)(piVar3[0xb4] + 8) = 0;
        *(undefined4 *)(piVar3[0xb4] + 0xc) = 0;
        (**(code **)(*param_1 + 0xc0))();
        param_1[8] = uVar4 - 1 & 1;
        param_1[5] = param_1[6];
        return;
      }
      if (param_1[5] < 2) {
        piVar3 = (int *)*piVar1;
        if (piVar3 != (int *)0x0) {
          if (*piVar3 != 0) {
            FUN_0064bbd0();
          }
          Csis__System__GetAllocator(&piStack_4);
          Mutex__Lock();
          (**(code **)(*piStack_4 + 4))(piVar3);
          Mutex__Unlock();
        }
        *piVar1 = 0;
        *(undefined4 *)(piVar1[0xb4] + 0x50) = *(undefined4 *)(param_1[1] + 0x44);
        *(undefined4 *)(param_1[1] + 0x40) = *(undefined4 *)(param_1[1] + 0x44);
        *(undefined4 *)(piVar1[0xb4] + 0xc) = 2;
        return;
      }
    }
  }
  return;
}


// ==== 0x53b980 FUN_0053b980

float10 __thiscall FUN_0053b980(int param_1,int param_2)

{
  int iVar1;
  
  param_1 = param_2 * 0x2e0 + 0x40 + param_1;
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x2d0);
    switch(*(undefined4 *)(iVar1 + 8)) {
    case 0:
      return (float10)0.0;
    case 1:
      return (float10)*(float *)(iVar1 + 0x68) - (float10)*(float *)(iVar1 + 0x78);
    case 2:
      return (float10)*(float *)(iVar1 + 0x70) + (float10)*(float *)(iVar1 + 0x6c);
    case 3:
      return (float10)*(float *)(iVar1 + 0x74) + (float10)*(float *)(iVar1 + 0x70) +
             (float10)*(float *)(iVar1 + 0x6c);
    case 4:
      return (float10)*(float *)(iVar1 + 0x70) - (float10)*(float *)(iVar1 + 0x78);
    case 8:
      return ((float10)*(float *)(iVar1 + 0x6c) - (float10)*(float *)(iVar1 + 0x78)) +
             (float10)*(float *)(iVar1 + 0x70);
    }
  }
  return (float10)-1.0;
}


// ==== 0x53ba10 EAXS_AmbStereoStream::UpdateFadeTransition

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall EAXS_AmbStereoStream__UpdateFadeTransition(int *param_1)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  uint uVar4;
  
  if (param_1[8] != param_1[7]) {
    (**(code **)(param_1[param_1[7] * 0xb8 + 0x14] + 0x28))(0,0);
    EAXS_Streams__Update3DParams();
                    /* WARNING: Could not recover jumptable at 0x0053bb9b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 200))();
    return;
  }
  iVar2 = *(int *)(param_1[1] + 0x94);
  uVar4 = param_1[8] - 1U & 1;
  if (iVar2 != 0) {
    fVar3 = _K_ONE - *(float *)(iVar2 + 0x3d4) / 200.0;
    piVar1 = param_1 + uVar4 * 0xb8 + 0xc4;
    if (*(int *)(param_1[1] + 0x18) < 0x13) {
      *(float *)(*piVar1 + 0x70) = fVar3 * 7000.0 + 2000.0;
    }
    else {
      *(undefined4 *)(*piVar1 + 0x70) = 0x45dac000;
    }
    if (*(int *)(param_1[1] + 0x108) == 0) {
      *(float *)(*piVar1 + 0x6c) = fVar3 * 1250.0 + 250.0;
    }
    else {
      *(undefined4 *)(*piVar1 + 0x70) = 0x459c4000;
      *(undefined4 *)(*piVar1 + 0x6c) = 0x447a0000;
    }
    *(undefined4 *)(param_1[param_1[7] * 0xb8 + 0xc4] + 0x68) = *(undefined4 *)(*piVar1 + 0x6c);
    *(undefined4 *)(param_1[1] + 0xe0) = *(undefined4 *)(*(int *)(param_1[1] + 0x94) + 0x3d4);
    *(float *)(param_1[1] + 0xe4) = fVar3;
  }
  piVar1 = param_1 + uVar4 * 0xb8 + 0xc4;
  *(undefined4 *)(param_1[uVar4 * 0xb8 + 0xc4] + 0x18) = 3;
  *(undefined4 *)(*piVar1 + 0x38) = 1;
  if (*(int *)param_1[1] == 8) {
    *(undefined4 *)(*piVar1 + 0x50) = 3;
    *(undefined4 *)(*piVar1 + 0x6c) = 0x447a0000;
    *(undefined4 *)(*piVar1 + 0x70) = 0x45dac000;
    *(undefined4 *)(param_1[1] + 0x40) = 3;
    *(undefined4 *)(param_1[param_1[8] * 0xb8 + 0xc4] + 0x70) = 0x45dac000;
    *(undefined4 *)(*piVar1 + 0xc) = 2;
    return;
  }
  *(int *)(*piVar1 + 0x50) = ((int *)param_1[1])[0x11];
  *(undefined4 *)(param_1[1] + 0x40) = *(undefined4 *)(param_1[1] + 0x44);
  *(undefined4 *)(*piVar1 + 0xc) = 2;
  return;
}


// ==== 0x53bbb0 FUN_0053bbb0

void __fastcall FUN_0053bbb0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x40 + param_1);
  if (*piVar1 != 0) {
    iVar2 = *(int *)(piVar1[0xb4] + 0x2c);
    if (4 < *(int *)(piVar1[0xb4] + 0x48)) {
      if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
        iVar2 = 0;
      }
      if ((DAT_007361f0 != (int *)0x0) && ((*DAT_007361f0 == 1 || (*DAT_007361f0 == 7)))) {
        iVar2 = 0;
      }
      iVar2 = (*(int *)(DAT_007356ac + 0x36fc) * iVar2 >> 0xf) * *(int *)(DAT_007356ac + 0x3e18) >>
              0xf;
    }
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x7fff < iVar2) {
      iVar2 = 0x7fff;
    }
    *(int *)(*piVar1 + 0xc) = iVar2;
    iVar2 = *(int *)(piVar1[0xb4] + 0x34);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x1fff < iVar2) {
      iVar2 = 0x1fff;
    }
    *(int *)(*piVar1 + 0x10) = iVar2;
    iVar2 = *(int *)(piVar1[0xb4] + 0x30);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0xffff < iVar2) {
      iVar2 = 0xffff;
    }
    *(int *)(*piVar1 + 0x14) = iVar2;
    if (*(int *)*piVar1 != 0) {
      FUN_0064bc30((int *)*piVar1 + 1);
    }
  }
  return;
}


// ==== 0x53bca0 FUN_0053bca0

undefined4 __fastcall FUN_0053bca0(int *param_1)

{
  undefined4 uVar1;
  undefined4 local_4;
  
  local_4 = 0;
  uVar1 = 0;
  if (*param_1 != 0) {
    Csis__Class__GetRefCount(&local_4);
    uVar1 = local_4;
  }
  return uVar1;
}


// ==== 0x53bcc0 FUN_0053bcc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0053bcc0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 uVar3;
  
  *(int *)(param_1 + 800) = param_1 + 0x278;
  *(int *)(param_1 + 0x2c) = param_1 + 0x278;
  *(undefined4 *)(param_1 + 0x324) = 2;
  *(undefined4 *)(param_1 + 0x604) = 2;
  *(int *)(param_1 + 0x600) = param_1 + 0x558;
  *(int *)(param_1 + 0x30) = param_1 + 0x558;
  *(undefined4 *)(param_1 + 0x328) = 0x437a0000;
  *(undefined4 *)(param_1 + 0x608) = 0x437a0000;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(int **)(param_1 + 0x34) = (int *)(param_1 + 0x60);
  *(int **)(param_1 + 0x38) = (int *)(param_1 + 0x340);
  uVar3 = param_8;
  (**(code **)(*(int *)(param_1 + 0x60) + 0x2c))(param_2,param_3,4,param_5,param_6,param_7,param_8);
  (**(code **)(*(int *)(param_1 + 0x340) + 0x2c))
            (param_7,uVar3,2,unaff_ESI,unaff_EBP,unaff_EBX,param_8);
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x38) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x24) = 0x7fff;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x38) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x24) = 0x7fff;
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x70) = 0xbf800000;
  iVar2 = DAT_007356a8;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x70) = 0xbf800000;
  piVar1 = *(int **)(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x330) = 0;
  piVar1[0x2f] = (int)&DAT_006f49d0;
  piVar1[0x81] = *(int *)(*(int *)(iVar2 + 0xa0) + 4);
  (**(code **)(*piVar1 + 0x24))();
  iVar2 = DAT_007356a8;
  piVar1 = *(int **)(param_1 + 0x38);
  piVar1[0x2f] = (int)&DAT_006f49d0;
  piVar1[0x81] = *(int *)(*(int *)(iVar2 + 0xa0) + 4);
  (**(code **)(*piVar1 + 0x24))();
  *(undefined4 *)(param_1 + 0x610) = 0;
  *(undefined4 *)(param_1 + 0x614) = 0;
  _DAT_0072f5ec = param_1;
  return;
}


// ==== 0x53be20 FUN_0053be20

void __fastcall FUN_0053be20(int *param_1)

{
  int *piVar1;
  int *piStack_4;
  
  piVar1 = (int *)param_1[0x14];
  piStack_4 = param_1;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar1);
    Mutex__Unlock();
    param_1[0x14] = 0;
  }
  piVar1 = (int *)param_1[0xcc];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar1);
    Mutex__Unlock();
    param_1[0xcc] = 0;
  }
  param_1[5] = 0;
  FUN_00539d80();
  FUN_00539d80();
  return;
}


// ==== 0x53bec0 FUN_0053bec0

undefined4 __thiscall FUN_0053bec0(int param_1,int param_2)

{
  return CONCAT31((int3)((uint)(param_2 * 0x2e0) >> 8),
                  *(int *)(param_2 * 0x2e0 + 0x50 + param_1) != 0);
}


// ==== 0x53bee0 FUN_0053bee0

void __thiscall FUN_0053bee0(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = DAT_007356a8;
  if (-1 < param_3) {
    *(undefined4 *)(param_1[1] + 0xf4) = *(undefined4 *)(param_1[1] + 0xf0);
    *(undefined4 *)(param_1[1] + 0xf0) = 99;
    *(int *)(param_1[1] + 0xf8) = param_3;
    *(undefined4 *)(param_1[200] + 0x18) = 0;
    *(undefined4 *)(param_1[200] + 0x74) = 0;
    *(undefined4 *)(param_1[200] + 0xc) = 2;
    *(int *)(param_1[200] + 0x54) = param_3;
    *(int *)(param_1[200] + 0x4c) = param_3;
    *(undefined4 *)(param_1[200] + 0x14) = 1;
    return;
  }
  if ((param_1[0x14] == 0) || (param_3 != -1)) {
    *(undefined4 *)(param_1[200] + 0x14) = 1;
    if (*(int *)(*(int *)(iVar1 + 8) + 0x30) == 0) {
      *(undefined4 *)(param_1[200] + 0x18) = 0;
    }
    else {
      *(undefined4 *)(param_1[200] + 0x18) = 4;
    }
    *(undefined4 *)(param_1[200] + 0x74) = 0;
    *(undefined4 *)(param_1[200] + 0xc) = 2;
  }
  else if (*(int *)(param_1[200] + 8) == 7) {
    (**(code **)(*param_1 + 0x4c))();
    return;
  }
  return;
}


// ==== 0x53bfc0 EAXS_MusicStream::InitializeEATRAX

/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall EAXS_MusicStream__InitializeEATRAX(int param_1)

{
  undefined4 uStack_4;
  
  uStack_4 = 0;
  EAXSound__InitEATraxMasks(DAT_007356a8,&uStack_4,0);
  *(undefined4 *)(*(int *)(param_1 + 4) + 0xe8) = 0;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0xec) = uStack_4;
  if (*(int *)(*(int *)(param_1 + 4) + 0xf0) != 99) {
    *(undefined4 *)(*(int *)(param_1 + 4) + 0xf0) = DAT_0075892c;
  }
  return;
}


// ==== 0x53c020 FUN_0053c020

undefined4 __fastcall FUN_0053c020(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[param_1[8] + 0xb];
  iVar2 = _ftol_nocw();
  if ((((0 < iVar2) && (*(int *)(iVar1 + 8) == 0)) && (param_1[0x184] == 1)) &&
     (*(int *)(param_1[1] + 0x10) != 5)) {
    (**(code **)(*param_1 + 0xc0))();
    (**(code **)(*param_1 + 0x40))();
    param_1[0x184] = 0;
    EAXS_StreamControl__UpdateStreams();
    return 0;
  }
  EAXS_StreamControl__UpdateStreams();
  return 1;
}


// ==== 0x53c0a0 FUN_0053c0a0

void __fastcall FUN_0053c0a0(int *param_1)

{
  int *piVar1;
  int *piStack_4;
  
  piVar1 = (int *)param_1[0x14];
  piStack_4 = param_1;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar1);
    Mutex__Unlock();
    param_1[0x14] = 0;
    *(undefined4 *)(param_1[200] + 0xc) = 0;
    *(undefined4 *)(param_1[200] + 8) = 0;
  }
  piVar1 = (int *)param_1[0xcc];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar1);
    Mutex__Unlock();
    param_1[0xcc] = 0;
    *(undefined4 *)(param_1[0x180] + 0xc) = 0;
    *(undefined4 *)(param_1[0x180] + 8) = 0;
  }
  return;
}


// ==== 0x53c150 FUN_0053c150

void __fastcall FUN_0053c150(int param_1)

{
  if (*(int *)(param_1 + 0x50) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 800) + 0xc) = 1;
    *(undefined4 *)(*(int *)(param_1 + 800) + 0x68) = 0x447a0000;
    *(undefined4 *)(*(int *)(param_1 + 800) + 0x78) = 0;
  }
  if (*(int *)(param_1 + 0x330) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x600) + 0xc) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x600) + 0x68) = 0x447a0000;
    *(undefined4 *)(*(int *)(param_1 + 0x600) + 0x78) = 0;
  }
  return;
}


// ==== 0x53c1b0 FUN_0053c1b0

void __fastcall FUN_0053c1b0(int param_1)

{
  int *piVar1;
  
  DAT_007355d4 = 0;
  if ((*(int *)(*(int *)(param_1 + 800) + 0xc) != 0) && (*(int *)(param_1 + 0x50) != 0)) {
    *(undefined4 *)(*(int *)(param_1 + 800) + 0x78) = 0;
    *(undefined4 *)(*(int *)(param_1 + 800) + 0xc) = 1;
  }
  if (((DAT_006f1dd8 != 0) && (*(int *)(DAT_007356a8 + 0x104) != 0)) &&
     (piVar1 = *(int **)(*(int *)(DAT_007356a8 + 0x104) + 0x14), piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x98))(0,0xfffffffe);
  }
  return;
}


// ==== 0x53c210 FUN_0053c210

void __fastcall FUN_0053c210(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piStack_4;
  
  piStack_4 = param_1;
  if ((0 < *(int *)(param_1[1] + 0x18)) && (*(int *)(param_1[1] + 0x18) < 0x13)) {
    piVar1 = (int *)param_1[0x14];
    if (piVar1 != (int *)0x0) {
      if (*piVar1 != 0) {
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&piStack_4);
      Mutex__Lock();
      (**(code **)(*piStack_4 + 4))(piVar1);
      Mutex__Unlock();
      param_1[0x14] = 0;
    }
    iVar2 = DAT_007356a8;
    *(undefined4 *)(param_1[200] + 0x14) = 1;
    if (*(int *)(*(int *)(iVar2 + 8) + 0x30) == 0) {
      *(undefined4 *)(param_1[200] + 0x18) = 0;
    }
    else {
      *(undefined4 *)(param_1[200] + 0x18) = 4;
    }
    *(undefined4 *)(param_1[200] + 0x74) = 0x42c80000;
    DAT_007355d4 = 1;
    *(undefined4 *)(param_1[200] + 0xc) = 3;
    return;
  }
  piVar1 = (int *)param_1[0x14];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar1);
    Mutex__Unlock();
    param_1[0x14] = 0;
  }
  piVar1 = (int *)param_1[0xcc];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar1);
    Mutex__Unlock();
    param_1[0xcc] = 0;
  }
  DAT_007355d4 = 1;
  return;
}


// ==== 0x53c350 FUN_0053c350

void __fastcall FUN_0053c350(int *param_1)

{
  if (DAT_007355d4 == '\0') {
    (**(code **)(*param_1 + 0x40))();
  }
  DAT_007355d4 = 0;
  return;
}


// ==== 0x53c370 FUN_0053c370

void __fastcall FUN_0053c370(int *param_1)

{
  param_1[8] = 0;
  (**(code **)(*param_1 + 0xb8))();
  param_1[8] = 1;
                    /* WARNING: Could not recover jumptable at 0x0053c38e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xb8))();
  return;
}


// ==== 0x53c3a0 FUN_0053c3a0

void __fastcall FUN_0053c3a0(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_20;
  int *local_18;
  int iStack_14;
  int iStack_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  pvStack_c = ExceptionList;
  iVar6 = param_1[8];
  iVar3 = param_1[iVar6 + 0xb];
  local_20 = *(int *)(param_1[1] + 0xf8);
  piVar4 = (int *)param_1[iVar6 * 0xb8 + 0x14];
  piVar2 = param_1 + iVar6 * 0xb8 + 0x14;
  ExceptionList = &pvStack_c;
  if (piVar4 != (int *)0x0) {
    ExceptionList = &pvStack_c;
    if (*piVar4 != 0) {
      ExceptionList = &pvStack_c;
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_18);
    Mutex__Lock();
    (**(code **)(*local_18 + 4))(piVar4);
    Mutex__Unlock();
    *piVar2 = 0;
  }
  *(undefined4 *)(iVar3 + 0x50) = 0;
  (**(code **)(*param_1 + 0x8c))();
  if (*(int *)(iVar3 + 0x18) < 3) {
    if ((DAT_0077a920 == 3) || (piVar4 = (int *)param_1[1], *piVar4 == 8)) {
      iVar6 = 0;
      if (*(int *)(DAT_007356a8 + 0x90) != 0) {
        ExceptionList = pvStack_c;
        return;
      }
      iVar8 = param_1[1];
      if (*(int *)(iVar8 + 0xf0) == 99) {
        if (((DAT_00758930 | DAT_00758934) & 1 << ((char)*(undefined4 *)(iVar8 + 0xf8) + 1U & 0x1f))
            == 0) {
          *(undefined4 *)(iVar3 + 8) = 0;
          *(undefined4 *)(iVar3 + 0xc) = 0;
        }
        else {
          *(undefined4 *)(iVar3 + 0xc) = 2;
        }
      }
      else {
        iVar9 = *(int *)(iVar8 + 0xf8);
        local_20 = (&DAT_00758b58)[iVar9 * 2];
        while( true ) {
          local_20 = local_20 + 1;
          if ((DAT_00758930 & 1 << ((byte)local_20 & 0x1f)) != 0) break;
          *(int *)(iVar8 + 0xf8) = iVar9 + 1;
          if (0x19 < *(int *)(param_1[1] + 0xf8)) {
            *(undefined4 *)(param_1[1] + 0xf8) = 0;
          }
          iVar8 = param_1[1];
          iVar9 = *(int *)(iVar8 + 0xf8);
          local_20 = (&DAT_00758b58)[iVar9 * 2];
          iVar6 = iVar6 + 1;
          if (0x19 < iVar6) {
            *(undefined4 *)(iVar3 + 8) = 0;
            *(undefined4 *)(iVar3 + 0xc) = 0;
            ExceptionList = pvStack_c;
            return;
          }
        }
      }
    }
    else {
      iVar6 = piVar4[0x3e];
      local_20 = (&DAT_00758b58)[iVar6 * 2];
      iVar8 = 0;
      while( true ) {
        local_20 = local_20 + 1;
        if ((DAT_00758934 & 1 << ((byte)local_20 & 0x1f)) != 0) break;
        piVar4[0x3e] = iVar6 + 1;
        if (0x19 < *(int *)(param_1[1] + 0xf8)) {
          *(undefined4 *)(param_1[1] + 0xf8) = 0;
        }
        piVar4 = (int *)param_1[1];
        iVar6 = piVar4[0x3e];
        local_20 = (&DAT_00758b58)[iVar6 * 2];
        iVar8 = iVar8 + 1;
        if (0x19 < iVar8) {
          *(undefined4 *)(iVar3 + 8) = 0;
          *(undefined4 *)(iVar3 + 0xc) = 0;
          ExceptionList = pvStack_c;
          return;
        }
      }
    }
    if (*(int *)(param_1[1] + 0xf0) == 99) {
      local_20 = local_20 + 1;
    }
    *(int *)(iVar3 + 0x54) = local_20;
    *(int *)(iVar3 + 0x4c) = local_20;
    *(int *)(iVar3 + 0x58) = local_20;
    *(int *)(param_1[1] + 0xfc) = local_20 + -1;
    (**(code **)(piVar2[4] + 0x28))(0,0);
    EAXS_Streams__Update3DParams();
    iVar6 = EAXS_Streams__SetupStartParameters();
    if (iVar6 == -1) goto LAB_0053c689;
    iVar6 = param_1[1];
    if (*(int *)(iVar6 + 0xf0) == 99) {
      *(undefined4 *)(iVar6 + 0xf0) = *(undefined4 *)(iVar6 + 0xf4);
    }
    else {
      cVar5 = FUN_0053cbd0();
      if (cVar5 != '\0') {
        ExceptionList = pvStack_c;
        return;
      }
    }
    if (0 < piVar2[0x18]) {
      FUN_0051c7b0();
    }
    *(int *)(param_1[1] + 0xf8) = *(int *)(param_1[1] + 0xf8) + 1;
    if (0x19 < *(int *)(param_1[1] + 0xf8)) {
      *(undefined4 *)(param_1[1] + 0xf8) = 0;
    }
  }
  else {
    if (*(int *)(DAT_007356a8 + 0x90) != 0) {
      ExceptionList = pvStack_c;
      return;
    }
    (**(code **)(piVar2[4] + 0x28))(0,0);
    EAXS_Streams__Update3DParams();
    iVar6 = EAXS_Streams__SetupStartParameters();
    if (iVar6 == -1) {
LAB_0053c689:
      *(undefined4 *)(iVar3 + 8) = 0;
      *(undefined4 *)(iVar3 + 0xc) = 0;
      ExceptionList = pvStack_c;
      return;
    }
    cVar5 = FUN_0053cbd0();
    if (cVar5 != '\0') {
      ExceptionList = pvStack_c;
      return;
    }
    if ((*(int *)(iVar3 + 0x50) == 0) && (*(int *)(iVar3 + 0x54) == 0)) {
      *(undefined4 *)(iVar3 + 0x54) = 1;
      *(undefined4 *)(iVar3 + 0x4c) = 1;
      *(undefined4 *)(iVar3 + 0x58) = 1;
    }
    if (*(int *)(param_1[1] + 0xc) == 2) {
      *(undefined4 *)(iVar3 + 0x74) = *(undefined4 *)(&DAT_006f6f20 + *(int *)(iVar3 + 0x58) * 4);
    }
    *(int *)(param_1[1] + 0xfc) = *(int *)(iVar3 + 0x4c) + -1;
    if (0 < piVar2[0x18]) {
      FUN_0051c7b0();
    }
  }
  if (piVar2[0x18] == 0) {
    param_1[0x184] = 1;
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar3 + 0xc) = 0;
  }
  if (*(int *)(iVar3 + 8) == 0) {
    *(undefined4 *)(iVar3 + 0x78) = 0;
    ExceptionList = pvStack_c;
    return;
  }
  iVar6 = FUN_005256f0(0x28);
  uStack_4 = 0;
  iStack_10 = iVar6;
  if (iVar6 == 0) {
    iVar6 = 0;
  }
  else {
    iVar8 = *(int *)(iVar3 + 0x30);
    iStack_14 = *(int *)(iVar3 + 0x58);
    iVar9 = *(int *)(iVar3 + 0x2c);
    iVar7 = *(int *)(iVar3 + 0x48);
    iVar10 = *(int *)(iVar3 + 0x34);
    puVar1 = (undefined4 *)(iVar6 + 4);
    *puVar1 = 0;
    if (iVar7 < 0) {
      iVar7 = 0;
    }
    else if (3 < iVar7) {
      iVar7 = 3;
    }
    *(int *)(iVar6 + 8) = iVar7;
    if (iVar9 < 0) {
      iVar9 = 0;
    }
    else if (0x7fff < iVar9) {
      iVar9 = 0x7fff;
    }
    *(int *)(iVar6 + 0xc) = iVar9;
    if (iVar10 < 0) {
      iVar10 = 0;
    }
    else if (0x2000 < iVar10) {
      iVar10 = 0x2000;
    }
    *(int *)(iVar6 + 0x10) = iVar10;
    if (iVar8 < 0) {
      iVar8 = 0;
    }
    else if (0xffff < iVar8) {
      iVar8 = 0xffff;
    }
    *(int *)(iVar6 + 0x14) = iVar8;
    *(undefined4 *)(iVar6 + 0x18) = 0;
    *(undefined4 *)(iVar6 + 0x1c) = 0;
    *(undefined4 *)(iVar6 + 0x20) = 0;
    if (iStack_14 < 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = iStack_14;
      if (0x1a < iStack_14) {
        iVar8 = 0x1a;
      }
    }
    *(int *)(iVar6 + 0x24) = iVar8;
    iVar8 = Csis__Class__CreateInstance(&DAT_0073d7cc,puVar1,iVar6);
    if (iVar8 < 0) {
      Csis__ClassHandle__Set(&PTR_s_MUSIC_STREAM_006f2210);
      Csis__Class__CreateInstance(&DAT_0073d7cc,puVar1,iVar6);
    }
  }
  *piVar2 = iVar6;
  *(undefined4 *)(iVar3 + 0x78) = 0;
  uStack_4 = 0xffffffff;
  iVar6 = FUN_0053bca0();
  param_1[5] = iVar6;
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x53c870 FUN_0053c870

void __fastcall FUN_0053c870(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x2c + *(int *)(param_1 + 0x20) * 4);
  piVar1 = (int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x50 + param_1);
  if (*(int *)(iVar2 + 8) != 0) {
    if (*piVar1 != 0) {
      *(undefined4 *)(*piVar1 + 0x10) = 0;
      *(undefined4 *)(*piVar1 + 0xc) = 0;
      if (*(int *)*piVar1 != 0) {
        FUN_0064bc30((int *)*piVar1 + 1);
      }
    }
    *(undefined4 *)(iVar2 + 0xc) = 7;
  }
  return;
}


// ==== 0x53c8c0 FUN_0053c8c0

void __fastcall FUN_0053c8c0(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piStack_4;
  
  iVar1 = param_1[8];
  iVar2 = param_1[iVar1 + 0xb];
  piVar3 = (int *)param_1[iVar1 * 0xb8 + 0x14];
  if (piVar3 != (int *)0x0) {
    piStack_4 = param_1;
    if (*piVar3 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar3);
    Mutex__Unlock();
    param_1[iVar1 * 0xb8 + 0x14] = 0;
    if ((int *)param_1[(param_1[8] - 1U & 1) * 0xb8 + 0x14] != (int *)0x0) {
      if (*(int *)param_1[(param_1[8] - 1U & 1) * 0xb8 + 0x14] != 0) {
        Csis__Class__GetRefCount(&stack0xfffffff8);
      }
      param_1[5] = 0;
    }
    *(undefined4 *)(iVar2 + 0xc) = 0;
    return;
  }
  *(undefined4 *)(iVar2 + 0xc) = 0;
  return;
}


// ==== 0x53c960 FUN_0053c960

void __fastcall FUN_0053c960(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piStack_4;
  
  iVar5 = param_1[8];
  iVar2 = param_1[iVar5 + 0xb];
  piVar1 = param_1 + iVar5 * 0xb8 + 0x14;
  if ((*(int *)(param_1[1] + 0x10) == 5) && (iVar5 == 1)) {
    if ((int *)*piVar1 != (int *)0x0) {
      piStack_4 = (int *)0x0;
      if (*(int *)*piVar1 != 0) {
        Csis__Class__GetRefCount(&piStack_4);
      }
      param_1[6] = (int)piStack_4;
      if ((int)piStack_4 < param_1[5]) {
LAB_0053c9dc:
        piVar4 = (int *)*piVar1;
        if (piVar4 != (int *)0x0) {
          if (*piVar4 != 0) {
            FUN_0064bbd0();
          }
          Csis__System__GetAllocator(&piStack_4);
          Mutex__Lock();
          (**(code **)(*piStack_4 + 4))(piVar4);
          Mutex__Unlock();
        }
        *piVar1 = 0;
        *(undefined4 *)(iVar2 + 0xc) = 2;
        return;
      }
    }
  }
  else {
    iVar3 = *(int *)(param_1[1] + 0x18);
    piStack_4 = param_1;
    if ((iVar3 < 0) || (0x12 < iVar3)) {
      if (*piVar1 == 0) {
        return;
      }
    }
    else {
      if (iVar5 != 0) {
        return;
      }
      if (*piVar1 == 0) {
        return;
      }
      iVar5 = FUN_0053bca0();
      param_1[6] = iVar5;
      if (iVar5 < param_1[5]) goto LAB_0053c9dc;
    }
    (**(code **)(piVar1[4] + 0x28))(0,0);
    EAXS_Streams__Update3DParams();
    (**(code **)(*param_1 + 200))();
  }
  return;
}


// ==== 0x53ca50 FUN_0053ca50

void __fastcall FUN_0053ca50(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x50 + param_1);
  if (*piVar1 != 0) {
    iVar2 = *(int *)(piVar1[0xb4] + 0x2c);
    *(uint *)(piVar1[0xb4] + 0x34) = -(uint)(iVar2 != 0) & 0x1000;
    if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
      iVar2 = 0;
    }
    if ((DAT_007361f0 != (int *)0x0) && ((*DAT_007361f0 == 1 || (*DAT_007361f0 == 7)))) {
      iVar2 = 0;
    }
    iVar2 = *(int *)(DAT_007356ac + 0x35cc) * iVar2 >> 0xf;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x7fff < iVar2) {
      iVar2 = 0x7fff;
    }
    *(int *)(*piVar1 + 0xc) = iVar2;
    iVar2 = *(int *)(piVar1[0xb4] + 0x34);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x2000 < iVar2) {
      iVar2 = 0x2000;
    }
    *(int *)(*piVar1 + 0x10) = iVar2;
    iVar2 = *(int *)(piVar1[0xb4] + 0x30);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0xffff < iVar2) {
      iVar2 = 0xffff;
    }
    *(int *)(*piVar1 + 0x14) = iVar2;
    if (*(int *)*piVar1 != 0) {
      FUN_0064bc30((int *)*piVar1 + 1);
    }
  }
  return;
}


// ==== 0x53cb30 FUN_0053cb30

undefined4 __thiscall FUN_0053cb30(int param_1,int param_2)

{
  return *(undefined4 *)(param_2 * 0x2e0 + 0x324 + param_1);
}


// ==== 0x53cb50 FUN_0053cb50

float10 __thiscall FUN_0053cb50(int param_1,int param_2)

{
  return (float10)*(float *)(*(int *)(param_2 * 0x2e0 + 800 + param_1) + 100);
}


// ==== 0x53cb70 FUN_0053cb70

void __thiscall FUN_0053cb70(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 * 0x2e0 + 0x324 + param_1) = param_3;
  return;
}


// ==== 0x53cb90 FUN_0053cb90

void __thiscall FUN_0053cb90(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(*(int *)(param_2 * 0x2e0 + 800 + param_1) + 100) = param_3;
  return;
}


// ==== 0x53cbb0 FUN_0053cbb0

void __fastcall FUN_0053cbb0(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0x60) + 0x24))();
                    /* WARNING: Could not recover jumptable at 0x0053cbc9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0x340) + 0x24))();
  return;
}


// ==== 0x53cbd0 FUN_0053cbd0

uint FUN_0053cbd0(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_EAX;
  int *piVar4;
  byte bVar5;
  uint uVar6;
  uint local_4;
  
  uVar3 = DAT_00758930;
  uVar2 = DAT_007356a8;
  iVar1 = *(int *)(in_EAX + 0x2c + *(int *)(in_EAX + 0x20) * 4);
  local_4 = DAT_00758934;
  if (*(int *)(iVar1 + 0x18) < 3) {
    bVar5 = (char)(&DAT_00758b58)[*(int *)(*(int *)(in_EAX + 4) + 0xf8) * 2] + 1;
  }
  else {
    bVar5 = (byte)*(undefined4 *)(iVar1 + 0x54);
  }
  uVar6 = 1 << (bVar5 & 0x1f);
  if (DAT_00758934 == 0) {
    EAXSound__InitEATraxMasks(DAT_007356a8,&local_4,0);
  }
  if (uVar3 == 0) {
    EAXSound__InitEATraxMasks(uVar2,0,0);
  }
  if ((DAT_0077a920 == 3) || (piVar4 = *(int **)(in_EAX + 4), *piVar4 == 8)) {
    if ((uVar3 & uVar6) != 0) {
      DAT_00758930 = DAT_00758930 - uVar6;
      *(undefined4 *)(in_EAX + 0x614) = 0;
      return uVar3 & 0xffffff00;
    }
    piVar4 = *(int **)(in_EAX + 4);
  }
  else if ((local_4 & uVar6) != 0) {
    DAT_00758934 = DAT_00758934 - uVar6;
    *(undefined4 *)(in_EAX + 0x614) = 0;
    return (uint)piVar4 & 0xffffff00;
  }
  piVar4[0x3e] = piVar4[0x3e] + 1;
  if (0x19 < *(int *)(*(int *)(in_EAX + 4) + 0xf8)) {
    *(undefined4 *)(*(int *)(in_EAX + 4) + 0xf8) = 0;
  }
  *(undefined4 *)(iVar1 + 0xc) = 2;
  return CONCAT31((int3)((uint)piVar4 >> 8),1);
}


// ==== 0x53cce0 FUN_0053cce0

undefined4 __fastcall FUN_0053cce0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + param_1 + 800);
  param_1 = (*(int *)(param_1 + 0x20) - 1U & 1) * 0x2e0 + 0x50 + param_1;
  iVar2 = *(int *)(iVar1 + 0xc);
  if ((iVar2 != 1) || (bVar4 = true, *(int *)(*(int *)(param_1 + 0x2d0) + 8) != 0)) {
    bVar4 = false;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x2d0) + 0xc);
  if ((iVar3 == 1) && (*(int *)(iVar1 + 8) == 0)) {
    bVar5 = true;
  }
  else {
    bVar5 = false;
  }
  if ((((iVar2 != 2) && (!bVar4)) && (iVar3 != 2)) && (!bVar5)) {
    return 0;
  }
  return 1;
}


// ==== 0x53cd70 FUN_0053cd70

void __fastcall FUN_0053cd70(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int unaff_EBX;
  int unaff_ESI;
  
  if (in_EAX < 0) {
    in_EAX = 0;
  }
  else if (7 < in_EAX) {
    in_EAX = 7;
  }
  piVar1 = (int *)(unaff_ESI + 4);
  *piVar1 = in_EAX;
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (0xf < param_1) {
    param_1 = 0xf;
  }
  *(int *)(unaff_ESI + 8) = param_1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0x7fff < param_2) {
    param_2 = 0x7fff;
  }
  *(int *)(unaff_ESI + 0xc) = param_2;
  if (unaff_EBX < 0) {
    unaff_EBX = 0;
  }
  else if (0x1fff < unaff_EBX) {
    unaff_EBX = 0x1fff;
  }
  *(int *)(unaff_ESI + 0x10) = unaff_EBX;
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0xffff < param_3) {
    param_3 = 0xffff;
  }
  *(int *)(unaff_ESI + 0x14) = param_3;
  iVar2 = Csis__Class__CreateInstance(&DAT_0073d7d4,piVar1);
  if (iVar2 < 0) {
    Csis__ClassHandle__Set(&PTR_s_TCAR_MONO_STREAM_006f2228);
    Csis__Class__CreateInstance(&DAT_0073d7d4,piVar1);
  }
  return;
}


// ==== 0x53ce30 FUN_0053ce30

void __thiscall
FUN_0053ce30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 uVar3;
  
  *(int *)(param_1 + 0x5f0) = param_1 + 0x548;
  *(int *)(param_1 + 0x30) = param_1 + 0x548;
  *(int *)(param_1 + 0x310) = param_1 + 0x268;
  *(int *)(param_1 + 0x2c) = param_1 + 0x268;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x28) = 2;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 800) = 0;
  *(int **)(param_1 + 0x34) = (int *)(param_1 + 0x50);
  *(int **)(param_1 + 0x38) = (int *)(param_1 + 0x330);
  *(undefined4 *)(param_1 + 0x314) = 0;
  *(undefined4 *)(param_1 + 0x5f4) = 0;
  *(undefined4 *)(param_1 + 0x318) = 0;
  *(undefined4 *)(param_1 + 0x5f8) = 0;
  uVar3 = param_8;
  (**(code **)(*(int *)(param_1 + 0x50) + 0x2c))(param_2,param_3,1,param_5,param_6,param_7,param_8);
  (**(code **)(*(int *)(param_1 + 0x330) + 0x2c))
            (param_7,uVar3,1,unaff_ESI,unaff_EBP,unaff_EBX,param_8);
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x38) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x24) = 0x7f73;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x38) = 1;
  iVar2 = DAT_007356a8;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x24) = 0x7f73;
  piVar1 = *(int **)(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 800) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  piVar1[0x2f] = (int)&DAT_006f4b20;
  piVar1[0x81] = *(int *)(*(int *)(iVar2 + 0xa0) + 4);
  (**(code **)(*piVar1 + 0x24))();
  iVar2 = DAT_007356a8;
  piVar1 = *(int **)(param_1 + 0x38);
  piVar1[0x2f] = (int)&DAT_006f4b90;
  piVar1[0x81] = *(int *)(*(int *)(iVar2 + 0xa0) + 4);
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== 0x53cf70 FUN_0053cf70

void __fastcall FUN_0053cf70(int *param_1)

{
  int *piVar1;
  int *piStack_4;
  
  piVar1 = (int *)param_1[0x10];
  piStack_4 = param_1;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar1);
    Mutex__Unlock();
    param_1[0x10] = 0;
  }
  piVar1 = (int *)param_1[200];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar1);
    Mutex__Unlock();
    param_1[200] = 0;
  }
  param_1[5] = 0;
  FUN_00539d80();
  FUN_00539d80();
  return;
}


// ==== 0x53d010 FUN_0053d010

undefined4 __thiscall FUN_0053d010(int param_1,int param_2)

{
  param_1 = param_2 * 0x2e0 + param_1;
  if (*(int *)(param_1 + 0x40) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x310) + 0x48);
  }
  return 0xffffffff;
}


// ==== 0x53d040 FUN_0053d040

uint __thiscall FUN_0053d040(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  
  piVar1 = (int *)((int)param_2 * 0x2e0 + 0x40 + param_1);
  uVar3 = 0;
  if ((int *)*piVar1 != (int *)0x0) {
    param_2 = (int *)0x0;
    if ((*(int *)*piVar1 != 0) && (Csis__Class__GetRefCount(&param_2), 1 < (int)param_2)) {
      return 1;
    }
    piVar2 = (int *)*piVar1;
    if (piVar2 != (int *)0x0) {
      if (*piVar2 != 0) {
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&param_2);
      Mutex__Lock();
      (**(code **)(*param_2 + 4))(piVar2);
      Mutex__Unlock();
    }
    *piVar1 = 0;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 0xc) = 0;
    uVar3 = *(int *)(param_1 + 0x20) * 0x2e0;
    *(undefined4 *)(*(int *)(uVar3 + 0x310 + param_1) + 8) = 0;
  }
  return uVar3 & 0xffffff00;
}


// ==== 0x53d100 FUN_0053d100

void __thiscall FUN_0053d100(int param_1,int param_2)

{
  *(undefined4 *)(param_1 + 0x20) = 0;
  if ((*(int *)(param_1 + 0x40) == 0) ||
     (*(undefined4 *)(param_1 + 0x20) = 1, *(int *)(param_1 + 800) == 0)) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x50 + param_1) + 0x14))
              ((&PTR_DAT_006f4cdc)[param_2]);
    (**(code **)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x50 + param_1) + 0x24))();
    *(int *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 0x50) = param_2;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 0x54) = 0;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 0xc) = 2;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 4) = 3;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 0x18) = 1;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 0x70) =
         0xbf800000;
  }
  return;
}


// ==== 0x53d1f0 FUN_0053d1f0

float10 __thiscall FUN_0053d1f0(int param_1,int param_2)

{
  param_1 = param_2 * 0x2e0 + param_1;
  if (*(int *)(param_1 + 0x40) != 0) {
    return (float10)*(float *)(*(int *)(param_1 + 0x310) + 0x78);
  }
  return (float10)0.0;
}


// ==== 0x53d220 FUN_0053d220

void __fastcall FUN_0053d220(int *param_1)

{
  int *piVar1;
  int *piStack_4;
  
  piStack_4 = param_1;
  if ((int *)param_1[param_1[8] * 0xb8 + 0x10] != (int *)0x0) {
    piStack_4 = (int *)0x0;
    if (*(int *)param_1[param_1[8] * 0xb8 + 0x10] != 0) {
      Csis__Class__GetRefCount(&piStack_4);
    }
    param_1[6] = (int)piStack_4;
    if ((int)piStack_4 < param_1[5]) {
      piVar1 = (int *)param_1[param_1[8] * 0xb8 + 0x10];
      if (piVar1 != (int *)0x0) {
        if (*piVar1 != 0) {
          FUN_0064bbd0();
        }
        Csis__System__GetAllocator(&piStack_4);
        Mutex__Lock();
        (**(code **)(*piStack_4 + 4))(piVar1);
        Mutex__Unlock();
      }
      param_1[param_1[8] * 0xb8 + 0x10] = 0;
      param_1[5] = param_1[6];
    }
  }
  EAXS_StreamControl__UpdateStreams();
  return;
}


// ==== 0x53d2c0 FUN_0053d2c0

void __fastcall FUN_0053d2c0(int param_1)

{
  if (*(int *)(param_1 + 0x40) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x310) + 0xc) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x310) + 0x68) = 0x43fa0000;
    *(undefined4 *)(*(int *)(param_1 + 0x310) + 0x78) = 0;
  }
  if (*(int *)(param_1 + 800) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x5f0) + 0xc) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x5f0) + 0x68) = 0x43fa0000;
    *(undefined4 *)(*(int *)(param_1 + 0x5f0) + 0x78) = 0;
  }
  if (*(char *)(DAT_007356a8 + 0x70) != '\0') {
    *(undefined1 *)(DAT_007356a8 + 0x72) = 1;
  }
  return;
}


// ==== 0x53d330 FUN_0053d330

void __fastcall FUN_0053d330(int *param_1)

{
  int *piVar1;
  int *piStack_4;
  
  piVar1 = (int *)param_1[0x10];
  piStack_4 = param_1;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar1);
    Mutex__Unlock();
    param_1[0x10] = 0;
    *(undefined4 *)(param_1[0xc4] + 0xc) = 0;
    *(undefined4 *)(param_1[0xc4] + 8) = 0;
  }
  piVar1 = (int *)param_1[200];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar1);
    Mutex__Unlock();
    param_1[200] = 0;
    *(undefined4 *)(param_1[0x17c] + 0xc) = 0;
    *(undefined4 *)(param_1[0x17c] + 8) = 0;
  }
  return;
}


// ==== 0x53d3e0 FUN_0053d3e0

void __fastcall FUN_0053d3e0(int param_1)

{
  *(undefined1 *)(param_1 + 0x3c) = 1;
  return;
}


// ==== 0x53d3f0 FUN_0053d3f0

void __fastcall FUN_0053d3f0(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x310) + 0x14) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x5f0) + 0x14) = 1;
  return;
}


// ==== 0x53d410 FUN_0053d410

void __fastcall FUN_0053d410(int param_1)

{
  *(undefined1 *)(param_1 + 0x3c) = 0;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x71) = 0;
  return;
}


// ==== 0x53d420 FUN_0053d420

void __fastcall FUN_0053d420(int **param_1)

{
  int **ppiVar1;
  int *piVar2;
  int **ppiVar3;
  int iVar4;
  int *piVar5;
  undefined4 *unaff_EBX;
  void *unaff_ESI;
  int **ppiStack_28;
  int *local_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  pvStack_c = ExceptionList;
  piVar2 = param_1[8];
  ppiVar3 = (int **)param_1[(int)piVar2 * 0xb8 + 0x10];
  ppiVar1 = param_1 + (int)piVar2 * 0xb8 + 0x10;
  piVar2 = param_1[(int)piVar2 + 0xb];
  ExceptionList = &pvStack_c;
  if (ppiVar3 != (int **)0x0) {
    ExceptionList = &pvStack_c;
    if (*ppiVar3 != (int *)0x0) {
      ppiStack_28 = (int **)0x53d468;
      ExceptionList = &pvStack_c;
      FUN_0064bbd0();
    }
    ppiStack_28 = &local_10;
    Csis__System__GetAllocator();
    ppiStack_28 = (int **)0x53d47a;
    Mutex__Lock();
    ppiStack_28 = ppiVar3;
    (**(code **)(*local_10 + 4))();
    ppiStack_28 = (int **)0x53d489;
    Mutex__Unlock();
    *ppiVar1 = (int *)0x0;
  }
  ppiVar3 = ppiVar1 + 4;
  ppiStack_28 = (int **)0x53d498;
  EAXS_Streams__SetupStartParameters();
  if (piVar2[0x12] == 3) {
    ppiStack_28 = (int **)&DAT_006f46c0;
    (*(code *)(*ppiVar3)[4])();
  }
  else if (piVar2[0x12] == 4) {
    ppiStack_28 = (int **)&DAT_006f4730;
    (*(code *)(*ppiVar3)[4])();
  }
  if (piVar2[2] != 0) {
    ppiStack_28 = (int **)0x0;
    (*(code *)(*ppiVar3)[10])(param_1[1] + 0x20);
    EAXS_Streams__Update3DParams();
    Csis__System__GetAllocator(&stack0xffffffe8);
    Mutex__Lock();
    iVar4 = (**(code **)*unaff_EBX)(0x18,4,0xffffffff);
    Mutex__Unlock();
    if (iVar4 == 0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_0053cd70(piVar2[0xc]);
      param_1 = ppiStack_28;
    }
    *ppiVar1 = piVar5;
    piVar2[0x1e] = 0;
    ppiStack_28 = (int **)0x0;
    if (**ppiVar1 != 0) {
      Csis__Class__GetRefCount(&ppiStack_28);
    }
    param_1[5] = (int *)ppiStack_28;
    ExceptionList = unaff_ESI;
    return;
  }
  piVar2[0x1e] = 0;
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x53d590 FUN_0053d590

void __fastcall FUN_0053d590(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x2c + *(int *)(param_1 + 0x20) * 4);
  piVar1 = (int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x40 + param_1);
  if (*(int *)(iVar2 + 8) != 0) {
    if (*piVar1 != 0) {
      *(undefined4 *)(*piVar1 + 0x10) = 0;
      *(undefined4 *)(*piVar1 + 0xc) = 0;
      if (*(int *)*piVar1 != 0) {
        FUN_0064bc30((int *)*piVar1 + 1);
      }
    }
    *(undefined4 *)(iVar2 + 0xc) = 7;
  }
  return;
}


// ==== 0x53d5e0 FUN_0053d5e0

void __fastcall FUN_0053d5e0(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piStack_4;
  
  iVar1 = param_1[8];
  iVar2 = param_1[iVar1 + 0xb];
  piVar3 = (int *)param_1[iVar1 * 0xb8 + 0x10];
  if (piVar3 != (int *)0x0) {
    piStack_4 = param_1;
    if (*piVar3 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar3);
    Mutex__Unlock();
    param_1[iVar1 * 0xb8 + 0x10] = 0;
  }
  *(undefined4 *)(iVar2 + 0xc) = 0;
  return;
}


// ==== 0x53d640 EAXS_TCMStream::PlayStream

/* [canon] audio high (ghidra) docs/re/sound.md */

void __fastcall EAXS_TCMStream__PlayStream(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piStack_4;
  
  iVar2 = param_1[param_1[8] + 0xb];
  piVar1 = param_1 + param_1[8] * 0xb8 + 0x10;
  piStack_4 = param_1;
  if (*(int *)(param_1[1] + 0x10) == 5) {
    piVar3 = (int *)*piVar1;
    if (piVar3 != (int *)0x0) {
      if (*piVar3 != 0) {
        FUN_0064bbd0();
      }
      Csis__System__GetAllocator(&piStack_4);
      Mutex__Lock();
      (**(code **)(*piStack_4 + 4))(piVar3);
      Mutex__Unlock();
      *piVar1 = 0;
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined4 *)(iVar2 + 0xc) = 0;
    }
  }
  else if ((int *)*piVar1 != (int *)0x0) {
    piStack_4 = (int *)0x0;
    if (*(int *)*piVar1 != 0) {
      Csis__Class__GetRefCount(&piStack_4);
    }
    if ((int)piStack_4 < param_1[5]) {
      piVar3 = (int *)*piVar1;
      if (piVar3 != (int *)0x0) {
        if (*piVar3 != 0) {
          FUN_0064bbd0();
        }
        Csis__System__GetAllocator(&piStack_4);
        Mutex__Lock();
        (**(code **)(*piStack_4 + 4))(piVar3);
        Mutex__Unlock();
      }
      *piVar1 = 0;
      *(undefined4 *)(piVar1[0xb4] + 0xc) = 0;
      *(undefined4 *)(piVar1[0xb4] + 8) = 0;
    }
    else {
      (**(code **)(piVar1[4] + 0x28))(param_1[1] + 0x80,0);
      EAXS_Streams__Update3DParams();
      (**(code **)(*param_1 + 200))();
    }
  }
  (**(code **)(*param_1 + 0x9c))("Proc Stream PlayStream");
  return;
}


// ==== 0x53d760 FUN_0053d760

void __fastcall FUN_0053d760(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x40 + param_1);
  if (*piVar1 != 0) {
    iVar2 = *(int *)(piVar1[0xb4] + 0x2c);
    if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
      iVar2 = 0;
    }
    if ((DAT_007361f0 != (int *)0x0) && ((*DAT_007361f0 == 1 || (*DAT_007361f0 == 7)))) {
      iVar2 = 0;
    }
    iVar2 = *(int *)(DAT_007356ac + 0x395c) * iVar2 >> 0xf;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x7fff < iVar2) {
      iVar2 = 0x7fff;
    }
    *(int *)(*piVar1 + 0xc) = iVar2;
    iVar2 = *(int *)(piVar1[0xb4] + 0x34);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x1fff < iVar2) {
      iVar2 = 0x1fff;
    }
    *(int *)(*piVar1 + 0x10) = iVar2;
    iVar2 = *(int *)(piVar1[0xb4] + 0x30);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0xffff < iVar2) {
      iVar2 = 0xffff;
    }
    *(int *)(*piVar1 + 0x14) = iVar2;
    if (*(int *)*piVar1 != 0) {
      FUN_0064bc30((int *)*piVar1 + 1);
    }
  }
  return;
}


// ==== 0x53d830 FUN_0053d830

int __fastcall FUN_0053d830(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x80))(0);
  if (cVar1 == '\0') {
    return 0;
  }
  cVar1 = (**(code **)(*param_1 + 0x80))(1);
  return (-(uint)(cVar1 != '\0') & 0xfffffffe) + 1;
}


// ==== 0x53d860 FUN_0053d860

undefined4 __thiscall FUN_0053d860(int *param_1,int param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x80))(param_2);
  if (cVar1 == '\x01') {
    return *(undefined4 *)(param_1[param_2 * 0xb8 + 0xc4] + 0x48);
  }
  return 0xffffffff;
}


// ==== 0x53d8a0 FUN_0053d8a0

void __thiscall FUN_0053d8a0(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)((int)param_2 * 0x2e0 + 0x40 + param_1);
  piVar2 = (int *)*piVar1;
  if (piVar2 != (int *)0x0) {
    if (*piVar2 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&param_2);
    Mutex__Lock();
    (**(code **)(*param_2 + 4))(piVar2);
    Mutex__Unlock();
    *piVar1 = 0;
    *(undefined4 *)(piVar1[0xb4] + 8) = 0;
    *(undefined4 *)(piVar1[0xb4] + 0xc) = 0;
  }
  return;
}


// ==== 0x53d910 FUN_0053d910

void FUN_0053d910(undefined4 param_1)

{
  int *local_4;
  
  Csis__System__GetAllocator(&local_4);
  Mutex__Lock();
  (**(code **)(*local_4 + 4))(param_1);
  Mutex__Unlock();
  return;
}


// ==== 0x53d940 FUN_0053d940

void __fastcall FUN_0053d940(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int unaff_EBX;
  int unaff_ESI;
  
  if (in_EAX < 0) {
    in_EAX = 0;
  }
  else if (7 < in_EAX) {
    in_EAX = 7;
  }
  piVar1 = (int *)(unaff_ESI + 4);
  *piVar1 = in_EAX;
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (0x1ff < param_1) {
    param_1 = 0x1ff;
  }
  *(int *)(unaff_ESI + 8) = param_1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0x7fff < param_2) {
    param_2 = 0x7fff;
  }
  *(int *)(unaff_ESI + 0xc) = param_2;
  if (unaff_EBX < 0) {
    unaff_EBX = 0;
  }
  else if (0x1fff < unaff_EBX) {
    unaff_EBX = 0x1fff;
  }
  *(int *)(unaff_ESI + 0x10) = unaff_EBX;
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0xffff < param_3) {
    param_3 = 0xffff;
  }
  *(int *)(unaff_ESI + 0x14) = param_3;
  iVar2 = Csis__Class__CreateInstance(&DAT_0073d7ec,piVar1);
  if (iVar2 < 0) {
    Csis__ClassHandle__Set(&PTR_s_SPEECH_STREAM_006f2230);
    Csis__Class__CreateInstance(&DAT_0073d7ec,piVar1);
  }
  return;
}


// ==== 0x53da00 FUN_0053da00

void __thiscall
FUN_0053da00(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 uVar3;
  
  *(int *)(param_1 + 0x5f0) = param_1 + 0x548;
  *(int *)(param_1 + 0x30) = param_1 + 0x548;
  *(int *)(param_1 + 0x310) = param_1 + 0x268;
  *(int *)(param_1 + 0x2c) = param_1 + 0x268;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x28) = 2;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 800) = 0;
  *(int **)(param_1 + 0x34) = (int *)(param_1 + 0x50);
  *(int **)(param_1 + 0x38) = (int *)(param_1 + 0x330);
  *(undefined4 *)(param_1 + 0x314) = 0;
  *(undefined4 *)(param_1 + 0x5f4) = 0;
  *(undefined4 *)(param_1 + 0x318) = 0;
  *(undefined4 *)(param_1 + 0x5f8) = 0;
  uVar3 = param_8;
  (**(code **)(*(int *)(param_1 + 0x50) + 0x2c))(param_2,param_3,1,param_5,param_6,param_7,param_8);
  (**(code **)(*(int *)(param_1 + 0x330) + 0x2c))
            (param_7,uVar3,1,unaff_ESI,unaff_EBP,unaff_EBX,param_8);
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x38) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x24) = 0x7fff;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x38) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x24) = 0x7fff;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 800) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x14) = 1;
  iVar2 = DAT_007356a8;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x14) = 1;
  piVar1 = *(int **)(param_1 + 0x34);
  piVar1[0x2f] = (int)&DAT_006f4a40;
  piVar1[0x81] = *(int *)(*(int *)(iVar2 + 0xa0) + 4);
  (**(code **)(*piVar1 + 0x24))();
  iVar2 = DAT_007356a8;
  piVar1 = *(int **)(param_1 + 0x38);
  piVar1[0x2f] = (int)&DAT_006f4a40;
  piVar1[0x81] = *(int *)(*(int *)(iVar2 + 0xa0) + 4);
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== 0x53db50 EAXS_StreamControl::UpdateStreams

void EAXS_StreamControl__UpdateStreams(void)

{
  EAXS_StreamControl__UpdateStreams();
  return;
}


// ==== 0x53db60 FUN_0053db60

void __thiscall FUN_0053db60(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x20) = 0;
  if (*(int *)(param_1 + 0x40) == 0) {
    if (*(int *)(*(int *)(param_1 + 0x2c) + 0x14) != 1) {
      return;
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
    iVar1 = *(int *)(param_1 + 0x310);
  }
  else {
    *(undefined4 *)(param_1 + 0x20) = 1;
    if (*(int *)(param_1 + 800) != 0) {
      return;
    }
    if (*(int *)(*(int *)(param_1 + 0x30) + 0x14) != 1) {
      return;
    }
    *(undefined4 *)(param_1 + 0x20) = 1;
    iVar1 = *(int *)(param_1 + 0x5f0);
  }
  *(undefined4 *)(iVar1 + 0x50) = param_2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 0x54) = param_3;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 0x18) = 0;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 0xc) = 2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 4) = 3;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 0x70) = 0xbf800000;
  return;
}


// ==== 0x53dc30 FUN_0053dc30

void __thiscall FUN_0053dc30(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x20) = 0;
  if (*(int *)(param_1 + 0x40) == 0) {
    if (*(int *)(*(int *)(param_1 + 0x2c) + 0x14) != 1) {
      return;
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x310) + 0x50) = param_2;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 0x54) = 0;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 0x4c) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x20) = 1;
    if (*(int *)(param_1 + 800) != 0) {
      return;
    }
    if (*(int *)(*(int *)(param_1 + 0x30) + 0x14) != 1) {
      return;
    }
    *(undefined4 *)(param_1 + 0x20) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x5f0) + 0x50) = param_2;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 0x4c) = 0;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 0x54) = 0;
  }
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 0x18) = 1;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 0xc) = 2;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 4) = 3;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x310 + param_1) + 0x70) = 0xbf800000;
  return;
}


// ==== 0x53dd40 FUN_0053dd40

void __fastcall FUN_0053dd40(int **param_1)

{
  int **ppiVar1;
  int *piVar2;
  int **ppiVar3;
  int iVar4;
  int *piVar5;
  undefined4 *unaff_EBX;
  void *unaff_ESI;
  int **ppiStack_28;
  int *local_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00684d8b;
  pvStack_c = ExceptionList;
  piVar5 = param_1[8];
  piVar2 = param_1[(int)piVar5 + 0xb];
  ppiVar3 = (int **)param_1[(int)piVar5 * 0xb8 + 0x10];
  ppiVar1 = param_1 + (int)piVar5 * 0xb8 + 0x10;
  ExceptionList = &pvStack_c;
  if (ppiVar3 != (int **)0x0) {
    ExceptionList = &pvStack_c;
    if (*ppiVar3 != (int *)0x0) {
      ppiStack_28 = (int **)0x53dd88;
      ExceptionList = &pvStack_c;
      FUN_0064bbd0();
    }
    ppiStack_28 = &local_10;
    Csis__System__GetAllocator();
    ppiStack_28 = (int **)0x53dd9a;
    Mutex__Lock();
    ppiStack_28 = ppiVar3;
    (**(code **)(*local_10 + 4))();
    ppiStack_28 = (int **)0x53dda9;
    Mutex__Unlock();
    *ppiVar1 = (int *)0x0;
  }
  ppiStack_28 = (int **)0x0;
  (*(code *)ppiVar1[4][10])(0);
  EAXS_Streams__Update3DParams();
  (*(code *)(*param_1)[0x32])();
  EAXS_Streams__SetupStartParameters();
  if (piVar2[2] != 0) {
    Csis__System__GetAllocator(&stack0xffffffe8);
    Mutex__Lock();
    iVar4 = (**(code **)*unaff_EBX)(0x18,4,0xffffffff);
    Mutex__Unlock();
    if (iVar4 == 0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_0053d940(piVar2[0xc]);
      param_1 = ppiStack_28;
    }
    *ppiVar1 = piVar5;
    piVar2[0x1e] = 0;
    ppiStack_28 = (int **)0x0;
    if (**ppiVar1 != 0) {
      Csis__Class__GetRefCount(&ppiStack_28);
    }
    param_1[5] = (int *)ppiStack_28;
    ExceptionList = unaff_ESI;
    return;
  }
  piVar2[0x1e] = 0;
  ExceptionList = param_1;
  return;
}


// ==== 0x53de90 FUN_0053de90

void __fastcall FUN_0053de90(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piStack_4;
  
  piVar1 = param_1 + param_1[8] * 0xb8 + 0x10;
  if ((int *)*piVar1 == (int *)0x0) {
    return;
  }
  piStack_4 = (int *)0x0;
  if ((*(int *)*piVar1 != 0) && (Csis__Class__GetRefCount(&piStack_4), 1 < (int)piStack_4)) {
    (**(code **)(piVar1[4] + 0x28))(0,0);
    EAXS_Streams__Update3DParams();
    (**(code **)(*param_1 + 200))();
    return;
  }
  param_1[5] = (int)piStack_4;
  piVar2 = (int *)*piVar1;
  if (piVar2 != (int *)0x0) {
    if (*piVar2 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_4);
    Mutex__Lock();
    (**(code **)(*piStack_4 + 4))(piVar2);
    Mutex__Unlock();
  }
  *piVar1 = 0;
  *(undefined4 *)(piVar1[0xb4] + 0xc) = 0;
  *(undefined4 *)(piVar1[0xb4] + 8) = 0;
  return;
}


// ==== 0x53df50 FUN_0053df50

void __fastcall FUN_0053df50(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x20) * 0x2e0 + 0x40 + param_1);
  if (*piVar1 != 0) {
    iVar2 = *(int *)(piVar1[0xb4] + 0x2c);
    if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
      iVar2 = 0;
    }
    if ((DAT_007361f0 != (int *)0x0) && ((*DAT_007361f0 == 1 || (*DAT_007361f0 == 7)))) {
      iVar2 = 0;
    }
    iVar2 = *(int *)(DAT_007356ac + 0x3bbc) * iVar2 >> 0xf;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x7fff < iVar2) {
      iVar2 = 0x7fff;
    }
    *(int *)(*piVar1 + 0xc) = iVar2;
    iVar2 = *(int *)(piVar1[0xb4] + 0x34);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0x1fff < iVar2) {
      iVar2 = 0x1fff;
    }
    *(int *)(*piVar1 + 0x10) = iVar2;
    iVar2 = *(int *)(piVar1[0xb4] + 0x30);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (0xffff < iVar2) {
      iVar2 = 0xffff;
    }
    *(int *)(*piVar1 + 0x14) = iVar2;
    if (*(int *)*piVar1 != 0) {
      FUN_0064bc30((int *)*piVar1 + 1);
    }
  }
  return;
}


// ==== 0x53e020 Render_InitSubsystem

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render high (hopper+ghidra) docs/re/render.md */

void Render_InitSubsystem(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  DAT_0072f5f8 = _malloc(0x64000);
  DAT_0072f5fc = _malloc(0x64000);
  DAT_007355b4 = DAT_0072f5f8;
  DAT_007355b8 = (int)DAT_0072f5f8 + 0x64000;
  DAT_007355ac = 0x64000;
  _DAT_007355c0 = 0;
  DAT_0073559c = (undefined4 *)FUN_00566dc0(0x110,"DynamicFrameMemorySlotPool",0);
  if ((DAT_0073559c != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_0073559c;
    puVar3 = DAT_0073559c;
    DAT_0073559c[1] = DAT_0073d81c;
    DAT_0073d81c = puVar3;
    *DAT_0073559c = &DAT_0073d818;
  }
  DAT_007355a0 = (undefined4 *)FUN_00566dc0(0x30,"ePointSprite3DSlotPool",0);
  if ((DAT_007355a0 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_007355a0;
    puVar3 = DAT_007355a0;
    DAT_007355a0[1] = DAT_0073d81c;
    DAT_0073d81c = puVar3;
    *DAT_007355a0 = &DAT_0073d818;
  }
  _DAT_007355a4 = (undefined4 *)FUN_00566dc0(0x50,"eLightFlareSlotPool",0);
  if ((_DAT_007355a4 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = _DAT_007355a4;
    puVar3 = _DAT_007355a4;
    _DAT_007355a4[1] = DAT_0073d81c;
    DAT_0073d81c = puVar3;
    *_DAT_007355a4 = &DAT_0073d818;
  }
  _DAT_007355a8 = (undefined4 *)FUN_00566dc0(0xa0,"ePolySlotPool",0);
  if ((_DAT_007355a8 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = _DAT_007355a8;
    puVar3 = _DAT_007355a8;
    _DAT_007355a8[1] = DAT_0073d81c;
    DAT_0073d81c = puVar3;
    *_DAT_007355a8 = &DAT_0073d818;
  }
  puVar3 = DAT_0073559c;
  uVar1 = DAT_0073559c[5];
  DAT_0073559c[5] = uVar1 & 0xfffffffe;
  puVar3[5] = uVar1 & 0xfffffffc;
  DAT_007355a0[5] = DAT_007355a0[5] & 0xfffffffd;
  _DAT_007355a8[5] = _DAT_007355a8[5] & 0xfffffffd;
  FUN_0053f690();
  DAT_0072fa00 = 0;
  DAT_0072fa04 = 0;
  DAT_0072fa08 = 0;
  DAT_0072fa0c = 0;
  _DAT_0072fa10 = 0;
  puVar3 = &DAT_0072f600;
  for (iVar2 = 0x100; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  SetBlurCameraObject();
  puVar3 = (undefined4 *)PTR_DAT_006f3df0;
  for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  eLightMaterialPlatInfo_PoolCreate();
  RenderViews_InitLists();
  FUN_0061f020(FUN_00549460);
  FUN_0061f030(FUN_00447030);
  EAGLAnim__FnAnimFactory__New(0x19000,0);
  FUN_00408830();
  return;
}


// ==== 0x53e210 DynamicFrameMemory_Swap

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render high (hopper+ghidra) docs/re/render.md */

void DynamicFrameMemory_Swap(void)

{
  _DAT_007355b0 = DAT_0072f5fc;
  if ((DAT_007355c4 != 0) && (DAT_007355cc < DAT_007355c8)) {
    DAT_007355cc = DAT_007355c8;
  }
  _DAT_0072f5f4 = DAT_0072f5f0;
  DAT_0072f5f0 = DAT_007355b4 - DAT_0072f5f8;
  DAT_0072f5fc = DAT_0072f5f8;
  DAT_007355c4 = 0;
  DAT_007355c8 = 0;
  DAT_0072f5f8 = _DAT_007355b0;
  DAT_007355b4 = _DAT_007355b0;
  DAT_007355b8 = DAT_007355ac + _DAT_007355b0;
  _DAT_007355c0 = 0;
  return;
}


// ==== 0x53e290 FUN_0053e290

void __thiscall FUN_0053e290(int param_1,int param_2)

{
  int iVar1;
  uint in_EAX;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  uVar2 = in_EAX | 0x10;
  if ((iVar1 == 1) || (iVar1 == 2)) {
    uVar2 = in_EAX | 0x12;
  }
  if ((DAT_007364a0 == 4) || (DAT_007364a0 == 3)) {
    uVar2 = uVar2 | 1;
  }
  if ((9 < iVar1) && (iVar1 < 0x10)) {
    uVar2 = uVar2 | 0x100;
  }
  if (DAT_0078a2fc == 0) {
    uVar2 = uVar2 | 8;
  }
  else if (DAT_0078a2fc == 1) {
    uVar2 = uVar2 | 4;
  }
  if ((uVar2 & 0x800) != 0) {
    FUN_00408e30(param_2);
    *(uint *)(param_2 + 0x84) = uVar2 | 0x40;
    return;
  }
  if ((uVar2 & 0x1000) != 0) {
    uVar2 = uVar2 | 0x20;
  }
  FUN_00408e30(param_2);
  *(uint *)(param_2 + 0x84) = uVar2;
  return;
}


// ==== 0x53e330 FrameLists_Recycle

/* [canon] render med (hopper+ghidra) docs/re/render.md */

void FrameLists_Recycle(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = DAT_0073559c;
  if ((int **)DAT_00743c88 != &DAT_00743c88) {
    do {
      piVar4 = DAT_00743c88;
      iVar1 = *DAT_00743c88;
      piVar2 = (int *)DAT_00743c88[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
      iVar1 = *(int *)(iVar3 + 0x18);
      DAT_007355d0 = DAT_007355d0 + -1;
      *piVar4 = *(int *)(iVar3 + 0x10);
      *(int *)(iVar3 + 0x18) = iVar1 + -1;
      *(int **)(iVar3 + 0x10) = piVar4;
    } while ((int **)DAT_00743c88 != &DAT_00743c88);
  }
  if ((undefined4 **)DAT_00743c78 != &DAT_00743c78) {
    *DAT_00743c7c = &DAT_00743c88;
    DAT_00743c78[1] = DAT_00743c8c;
    *DAT_00743c8c = DAT_00743c78;
    DAT_00743c8c = DAT_00743c7c;
    DAT_00743c78 = &DAT_00743c78;
    DAT_00743c7c = &DAT_00743c78;
  }
  return;
}


// ==== 0x53e3c0 FUN_0053e3c0

void FUN_0053e3c0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = DAT_0073559c;
  piVar1 = (int *)*unaff_EDI;
  while (piVar1 != unaff_EDI) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    iVar2 = *(int *)(iVar4 + 0x18);
    *piVar1 = *(int *)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x53e400 BinarySearch_Hash

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

int BinarySearch_Hash(uint param_1,int param_2,int param_3)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint unaff_EDI;
  
  if (((param_2 != 0) && (0 < in_EAX)) && (param_3 + 4U <= unaff_EDI)) {
    iVar4 = 0;
    iVar5 = in_EAX + -1;
    if (-1 < iVar5) {
      do {
        iVar2 = (iVar5 + iVar4) / 2;
        iVar1 = iVar2 * unaff_EDI + param_2;
        if (param_1 < *(uint *)(iVar1 + param_3)) {
          iVar5 = iVar2 + -1;
        }
        else {
          if (param_1 <= *(uint *)(iVar1 + param_3)) {
            if (iVar2 < 1) {
              return iVar1;
            }
            puVar3 = (uint *)((iVar1 - unaff_EDI) + param_3);
            do {
              if (*puVar3 != param_1) {
                return iVar1;
              }
              iVar1 = iVar1 - unaff_EDI;
              puVar3 = (uint *)((int)puVar3 - unaff_EDI);
              iVar2 = iVar2 + -1;
            } while (0 < iVar2);
            return iVar1;
          }
          iVar4 = iVar2 + 1;
        }
      } while (iVar4 <= iVar5);
    }
  }
  return 0;
}


// ==== 0x53e480 FUN_0053e480

void __fastcall
FUN_0053e480(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  
  puVar1 = in_EAX + 6;
  *puVar1 = puVar1;
  in_EAX[7] = puVar1;
  in_EAX[8] = 0;
  in_EAX[0xb] = 0;
  in_EAX[0xc] = 0;
  in_EAX[0xd] = 0;
  *in_EAX = param_3;
  in_EAX[1] = param_2;
  in_EAX[2] = param_4;
  in_EAX[3] = param_5;
  in_EAX[4] = param_6;
  in_EAX[5] = param_7;
  return;
}


// ==== 0x53e4f0 StringList_Find

/* [canon] runtime med (hopper+capstone) docs/re/misc.md */

int * StringList_Find(int param_1,int param_2)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  piVar5 = (int *)(param_1 + 0x18);
  piVar3 = (int *)*piVar5;
  do {
    if (piVar3 == piVar5) {
      return (int *)0x0;
    }
    piVar4 = piVar3 + 2;
    iVar6 = param_2 - (int)piVar4;
    do {
      cVar1 = *(char *)(iVar6 + (int)piVar4);
      cVar2 = (char)*piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
      if ((cVar1 == '\0') || (cVar2 == '\0')) break;
    } while (cVar1 == cVar2);
    if (cVar1 == cVar2) {
      iVar6 = *piVar3;
      piVar4 = (int *)piVar3[1];
      *piVar4 = iVar6;
      *(int **)(iVar6 + 4) = piVar4;
      iVar6 = *piVar5;
      *piVar5 = (int)piVar3;
      *(int **)(iVar6 + 4) = piVar3;
      *piVar3 = iVar6;
      piVar3[1] = (int)piVar5;
      return piVar3;
    }
    piVar3 = (int *)*piVar3;
  } while( true );
}


// ==== 0x53e560 FUN_0053e560

int * FUN_0053e560(int param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = (int *)(param_1 + 0x18);
  piVar1 = (int *)*piVar4;
  while( true ) {
    if (piVar1 == piVar4) {
      return (int *)0x0;
    }
    if (((*(char *)((int)piVar1 + 0x8b) == '\0') && (piVar1[0x27] != 0)) &&
       (iVar3 = BinarySearch_Hash(param_2,piVar1[0x27],0), iVar3 != 0)) break;
    piVar1 = (int *)*piVar1;
  }
  iVar3 = *piVar1;
  piVar2 = (int *)piVar1[1];
  *piVar2 = iVar3;
  *(int **)(iVar3 + 4) = piVar2;
  iVar3 = *piVar4;
  *piVar4 = (int)piVar1;
  *(int **)(iVar3 + 4) = piVar1;
  *piVar1 = iVar3;
  piVar1[1] = (int)piVar4;
  return piVar1;
}


// ==== 0x53e5e0 FUN_0053e5e0

int __thiscall FUN_0053e5e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (((*(char *)(param_1 + 0x8b) == '\0') && (*(int *)(param_1 + 0x9c) != 0)) &&
     (iVar1 = BinarySearch_Hash(param_3,*(int *)(param_1 + 0x9c),0), iVar1 != 0)) {
    return iVar1;
  }
  return 0;
}


// ==== 0x53e620 FUN_0053e620

int FUN_0053e620(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  while( true ) {
    if (puVar1 == (undefined4 *)(param_1 + 0x18)) {
      return 0;
    }
    if (((*(char *)((int)puVar1 + 0x8b) == '\0') && (puVar1[0x27] != 0)) &&
       (iVar2 = BinarySearch_Hash(param_2,puVar1[0x27],0), iVar2 != 0)) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return iVar2;
}


// ==== 0x53e680 FUN_0053e680

undefined4 * FUN_0053e680(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  pcVar1 = (char *)((int)&DAT_0072f600 + 1);
  do {
    if (*pcVar1 == '\0') {
      *(undefined4 *)(iVar2 * 0x10 + 0x72f60c) = param_1;
      *(undefined1 *)((int)&DAT_0072f600 + iVar2 * 0x10 + 1) = 1;
      return &DAT_0072f600 + iVar2 * 4;
    }
    pcVar1 = pcVar1 + 0x10;
    iVar2 = iVar2 + 1;
  } while ((int)pcVar1 < 0x72fa01);
  return (undefined4 *)0x0;
}


// ==== 0x53e6c0 FUN_0053e6c0

void FUN_0053e6c0(undefined4 *param_1,int param_2,byte *param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uStack_84;
  
  uVar1 = *param_1;
  piVar2 = *(int **)(param_3 + 0xc);
  iVar3 = FUN_0053e560(piVar2,uVar1);
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0xef;
  if (param_2 == 0) {
    piVar2[0xc] = piVar2[0xc] + 1;
    piVar2[0xd] = piVar2[0xd] + param_1[2];
    if ((*(byte *)((int)param_1 + 0xd) & 0x20) == 0) {
      uVar5 = param_1[4] + (*piVar2 - 1U) & ~(*piVar2 - 1U);
      if ((*(byte *)((int)param_1 + 0xd) & 1) != 0) {
        FUN_00565da0("StrmEntryU: 0x%08x",uVar1);
        iVar6 = *(int *)(uVar5 + 8) + *piVar2;
        uStack_84 = 0x2000;
        if ((*param_3 != 0) && (iVar4 = bLargestFreeBlock(), iVar6 + 0x80 < iVar4)) {
          uStack_84 = *param_3 & 7 | 0x2000;
        }
        iVar6 = FUN_00565b60(iVar6,0,0,uStack_84);
        param_1[4] = iVar6;
        uVar5 = (*piVar2 - 1U) + iVar6 & ~(*piVar2 - 1U);
        DecompressBuffer();
        FUN_00565ce0();
      }
      (*(code *)piVar2[1])(uVar5,param_1,iVar3);
    }
    else {
      FUN_0053ebc0(iVar3);
      *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0xdf;
    }
  }
  if (iVar3 != 0) {
    *(int *)(iVar3 + 0xa4) = *(int *)(iVar3 + 0xa4) + -1;
  }
  *(short *)(param_3 + 2) = *(short *)(param_3 + 2) + -1;
  if (*(short *)(param_3 + 2) == 0) {
    if (*(code **)(param_3 + 4) != (code *)0x0) {
      (**(code **)(param_3 + 4))(*(undefined4 *)(param_3 + 8));
    }
    param_3[0xc] = 0;
    param_3[0xd] = 0;
    param_3[0xe] = 0;
    param_3[0xf] = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    param_3[3] = 0;
    param_3[4] = 0;
    param_3[5] = 0;
    param_3[6] = 0;
    param_3[7] = 0;
    param_3[8] = 0;
    param_3[9] = 0;
    param_3[10] = 0;
    param_3[0xb] = 0;
  }
  return;
}


// ==== 0x53e830 FUN_0053e830

void FUN_0053e830(int *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *unaff_EDI;
  uint local_84;
  
  if (((param_2 != (byte *)0x0) && (param_3 != 0)) && (unaff_EDI != (undefined4 *)0x0)) {
    if (*(short *)((int)unaff_EDI + 0xe) != 0) {
      *(short *)((int)unaff_EDI + 0xe) = *(short *)((int)unaff_EDI + 0xe) + 1;
      return;
    }
    bVar1 = *(byte *)((int)unaff_EDI + 0xd);
    if ((bVar1 & 0x10) != 0) {
      *(byte *)((int)unaff_EDI + 0xd) = bVar1 & 0xdf;
      *(undefined2 *)((int)unaff_EDI + 0xe) = 1;
      *(int *)(param_3 + 0xa8) = *(int *)(param_3 + 0xa8) + 1;
      *(int *)(param_3 + 0xac) = *(int *)(param_3 + 0xac) + unaff_EDI[2];
      return;
    }
    FUN_00565da0("StrmEntry%c: 0x%08x",(-((bVar1 & 1) != 0) & 0x23U) + 0x20,*unaff_EDI);
    iVar2 = unaff_EDI[2];
    iVar3 = *param_1;
    local_84 = 0x2000;
    if ((*(byte *)((int)unaff_EDI + 0xd) & 1) == 0) {
      if (*param_2 != 0) {
        iVar4 = bLargestFreeBlock();
        if (iVar2 + iVar3 + 0x80 < iVar4) {
          local_84 = *param_2 & 7 | 0x2000;
        }
      }
    }
    else {
      local_84 = 0x2008;
    }
    uVar5 = FUN_00565b60(iVar2 + iVar3,0,0,local_84);
    *(short *)((int)unaff_EDI + 0xe) = *(short *)((int)unaff_EDI + 0xe) + 1;
    unaff_EDI[4] = uVar5;
    *(int *)(param_3 + 0xa4) = *(int *)(param_3 + 0xa4) + 1;
    *(short *)(param_2 + 2) = *(short *)(param_2 + 2) + 1;
    *(byte *)((int)unaff_EDI + 0xd) = *(byte *)((int)unaff_EDI + 0xd) | 0x10;
    FUN_0058ac20(unaff_EDI[4] + (*param_1 - 1U) & ~(*param_1 - 1U),param_3 + 8,unaff_EDI[1],
                 unaff_EDI[2],FUN_0053e6c0);
    *(int *)(param_3 + 0xa8) = *(int *)(param_3 + 0xa8) + 1;
    *(int *)(param_3 + 0xac) = *(int *)(param_3 + 0xac) + unaff_EDI[2];
  }
  return;
}


// ==== 0x53e9b0 FUN_0053e9b0

undefined4 FUN_0053e9b0(int param_1,int param_2)

{
  if ((*(uint *)(param_1 + 8) <= *(uint *)(param_2 + 8)) &&
     ((*(uint *)(param_2 + 8) != *(uint *)(param_1 + 8) ||
      (*(uint *)(param_1 + 0x10) <= *(uint *)(param_2 + 0x10))))) {
    return 1;
  }
  return 0;
}


// ==== 0x53e9e0 FUN_0053e9e0

void FUN_0053e9e0(undefined4 param_1,int param_2,int param_3,code *param_4,undefined4 param_5,
                 undefined1 param_6)

{
  undefined4 uVar1;
  uint uVar2;
  int ****ppppiVar3;
  int ***pppiVar4;
  int ***pppiVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  int ****ppppiVar9;
  int *piVar10;
  uint local_1c;
  int ***local_14;
  int ***local_10;
  void *local_c;
  code *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = FUN_00686b38;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar6 = (undefined1 *)FUN_0053e680(param_1);
  if (puVar6 != (undefined1 *)0x0) {
    *puVar6 = param_6;
    *(code **)(puVar6 + 4) = param_4;
    *(undefined4 *)(puVar6 + 8) = param_5;
    local_14 = (int ***)&local_14;
    local_10 = (int ***)&local_14;
    local_4 = 0;
    iVar7 = FUN_00565b60(param_3 * 0x14,0,0,8);
    local_1c = 0x7fffffff;
    _param_6 = 0;
    if (0 < param_3) {
      piVar10 = (int *)(iVar7 + 8);
      do {
        uVar1 = *(undefined4 *)(param_2 + _param_6 * 4);
        iVar7 = FUN_0053e560(param_1,uVar1);
        if ((((iVar7 != 0) && (*(char *)(iVar7 + 0x8b) == '\0')) && (*(int *)(iVar7 + 0x9c) != 0))
           && (iVar8 = BinarySearch_Hash(uVar1,*(int *)(iVar7 + 0x9c),0), iVar8 != 0)) {
          uVar2 = *(uint *)(iVar8 + 4);
          piVar10[1] = iVar8;
          piVar10[2] = uVar2;
          *piVar10 = iVar7;
          if (uVar2 < local_1c) {
            local_1c = uVar2;
          }
          ppppiVar3 = (int ****)(piVar10 + -2);
          *local_10 = (int **)ppppiVar3;
          piVar10[-1] = (int)local_10;
          *ppppiVar3 = (int ***)&local_14;
          piVar10 = piVar10 + 5;
          local_10 = (int ***)ppppiVar3;
        }
        _param_6 = _param_6 + 1;
      } while (_param_6 < param_3);
    }
    bList__Sort(&local_14,FUN_0053e9b0);
    ppppiVar3 = (int ****)local_14;
    ppppiVar9 = (int ****)NullUpdate_ret();
    for (; ppppiVar3 != ppppiVar9; ppppiVar3 = (int ****)*ppppiVar3) {
      FUN_0053e830(param_1,puVar6,ppppiVar3[2]);
    }
    local_10 = (int ***)&local_14;
    local_14 = (int ***)&local_14;
    FUN_00565ce0();
    if ((*(short *)(puVar6 + 2) == 0) && (param_4 != (code *)0x0)) {
      puVar6[1] = 0;
      (*param_4)(param_5);
    }
    if ((int ****)local_14 != &local_14) {
      do {
        pppiVar4 = (int ***)*local_14;
        pppiVar5 = (int ***)local_14[1];
        *pppiVar5 = (int **)pppiVar4;
        pppiVar4[1] = (int **)pppiVar5;
        _free(local_14);
      } while ((int ****)local_14 != &local_14);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x53ebc0 FUN_0053ebc0

void FUN_0053ebc0(int param_1)

{
  int unaff_ESI;
  int *unaff_EDI;
  
  if ((*(byte *)(unaff_ESI + 0xd) & 0x20) == 0) {
    (*(code *)unaff_EDI[2])(*(int *)(unaff_ESI + 0x10) + (*unaff_EDI - 1U) & ~(*unaff_EDI - 1U));
  }
  FUN_00565ce0();
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) + -1;
  *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) - *(int *)(unaff_ESI + 8);
  unaff_EDI[0xc] = unaff_EDI[0xc] + -1;
  unaff_EDI[0xd] = unaff_EDI[0xd] - *(int *)(unaff_ESI + 8);
  return;
}


// ==== 0x53ec30 FUN_0053ec30

void __thiscall FUN_0053ec30(undefined4 param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  
  if (param_2 != 0) {
    if ((in_EAX == 0) && (in_EAX = FUN_0053e560(param_1,param_2), in_EAX == 0)) {
      return;
    }
    iVar1 = FUN_0053e5e0(param_1,param_2);
    if ((iVar1 != 0) &&
       (*(short *)(iVar1 + 0xe) = *(short *)(iVar1 + 0xe) + -1, *(short *)(iVar1 + 0xe) == 0)) {
      if ((*(byte *)(iVar1 + 0xd) & 0x10) != 0) {
        *(byte *)(iVar1 + 0xd) = *(byte *)(iVar1 + 0xd) | 0x20;
        return;
      }
      FUN_0053ebc0(in_EAX);
    }
  }
  return;
}


// ==== 0x53ec90 FUN_0053ec90

void FUN_0053ec90(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_3) {
    do {
      iVar2 = *(int *)(param_2 + iVar3 * 4);
      if ((((iVar2 != 0) && (iVar1 = FUN_0053e560(param_1,iVar2), iVar1 != 0)) &&
          (*(char *)(iVar1 + 0x8b) == '\0')) &&
         (((*(int *)(iVar1 + 0x9c) != 0 &&
           (iVar2 = BinarySearch_Hash(iVar2,*(int *)(iVar1 + 0x9c),0), iVar2 != 0)) &&
          (*(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1, *(short *)(iVar2 + 0xe) == 0))))
      {
        if ((*(byte *)(iVar2 + 0xd) & 0x10) == 0) {
          FUN_0053ebc0(iVar1);
        }
        else {
          *(byte *)(iVar2 + 0xd) = *(byte *)(iVar2 + 0xd) | 0x20;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_3);
  }
  return;
}


// ==== 0x53ed20 FUN_0053ed20

void FUN_0053ed20(undefined4 param_1)

{
  undefined4 in_EAX;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = StringList_Find(param_1,in_EAX);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0xa0);
    puVar3 = *(undefined4 **)(iVar1 + 0x9c);
    if (0 < iVar2) {
      do {
        if (puVar3[4] != 0) {
          FUN_0053ec30(*puVar3);
        }
        puVar3 = puVar3 + 5;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  return;
}


// ==== 0x53ed70 FUN_0053ed70

undefined4 FUN_0053ed70(int param_1,int param_2)

{
  char cVar1;
  char cVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  
  puVar3 = *(undefined4 **)(param_1 + 0x18);
  do {
    if (puVar3 == (undefined4 *)(param_1 + 0x18)) {
      return 0;
    }
    if (param_2 == 0) {
LAB_0053edad:
      if ((puVar3[0x24] == 0) || (0 < (int)puVar3[0x29])) {
        return 1;
      }
    }
    else {
      pcVar4 = (char *)(puVar3 + 2);
      iVar5 = param_2 - (int)pcVar4;
      do {
        cVar1 = pcVar4[iVar5];
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        if ((cVar1 == '\0') || (cVar2 == '\0')) break;
      } while (cVar1 == cVar2);
      if (cVar1 == cVar2) goto LAB_0053edad;
    }
    puVar3 = (undefined4 *)*puVar3;
  } while( true );
}


// ==== 0x53ede0 FUN_0053ede0

int FUN_0053ede0(int *param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int local_808;
  int local_804;
  undefined4 auStack_800 [512];
  
  iVar4 = 0;
  local_808 = 0;
  local_804 = 0;
  iVar1 = 0;
  if (0 < param_3) {
    do {
      iVar1 = FUN_0053e620(param_1,*(undefined4 *)(param_2 + local_804 * 4));
      if (((iVar1 != 0) && (*(short *)(iVar1 + 0xe) == 0)) && ((*(byte *)(iVar1 + 0xd) & 0x10) == 0)
         ) {
        iVar1 = *(int *)(iVar1 + 8) + *param_1;
        if ((&DAT_007301d4)[param_4] == 0) {
LAB_0053ee60:
          iVar2 = 0;
        }
        else if (param_4 == 0) {
          iVar2 = 0x6300000;
        }
        else {
          iVar2 = FUN_00565810();
          iVar2 = iVar2 + -0x58;
          if (iVar2 < 0) goto LAB_0053ee60;
        }
        if (iVar1 + 0x80 < iVar2) {
          uVar3 = FUN_00565b60(iVar1,0,0,param_4 & 7 | 0x2000);
          auStack_800[iVar4] = uVar3;
          iVar4 = iVar4 + 1;
        }
        else {
          local_808 = local_808 + iVar1;
        }
      }
      local_804 = local_804 + 1;
      iVar1 = local_808;
    } while (local_804 < param_3);
  }
  iVar2 = 0;
  if (0 < iVar4) {
    do {
      FUN_00565ce0();
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar4);
  }
  return iVar1;
}


// ==== 0x53eed0 FUN_0053eed0

int * FUN_0053eed0(int param_1,char *param_2,int param_3,int param_4,int param_5)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  
  pcVar3 = param_2;
  piVar4 = (int *)StringList_Find(param_1,param_2);
  if (piVar4 != (int *)0x0) {
    piVar4[0x2c] = piVar4[0x2c] + 1;
    return piVar4;
  }
  uVar5 = 0;
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    do {
      iVar6 = uVar5 + 1;
      uVar5 = uVar5 + 1;
    } while (param_2[iVar6] != '\0');
    if (0x7f < uVar5) {
      return (int *)0x0;
    }
  }
  iVar6 = bOpenFile(param_2,1,1);
  if (((iVar6 == 0) || (iVar6 = *(int *)(iVar6 + 4), iVar6 < 0)) || (iVar6 < 0x11)) {
    return (int *)0x0;
  }
  FUN_00594d40();
  piVar4 = (int *)FUN_00565b60(0x10,0,0,8);
  *piVar4 = 0;
  piVar4[1] = 0;
  piVar4[2] = 0;
  piVar4[3] = 0;
  piVar4[2] = param_3;
  piVar4[3] = param_4;
  param_2 = (char *)0x0;
  if ((param_5 != 0) && (iVar7 = bLargestFreeBlock(), 0x13c < iVar7)) {
    param_2 = (char *)param_5;
  }
  piVar8 = _malloc(0xbc);
  piVar9 = piVar8;
  for (iVar7 = 0x2f; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar9 = 0;
    piVar9 = piVar9 + 1;
  }
  piVar9 = piVar8 + 2;
  iVar7 = 0x7f;
  iVar10 = (int)pcVar3 - (int)piVar9;
  do {
    cVar1 = *(char *)((int)piVar9 + iVar10);
    iVar7 = iVar7 + -1;
    *(char *)piVar9 = cVar1;
    if (cVar1 == '\0') break;
    piVar9 = (int *)((int)piVar9 + 1);
  } while (iVar7 != 0);
  *(short *)(piVar8 + 0x22) = (short)param_5;
  *(undefined1 *)((int)piVar8 + 0x87) = 0;
  *(bool *)((int)piVar8 + 0x8a) = param_2 == (char *)param_5;
  piVar8[0x2c] = 1;
  piVar8[0x23] = (int)piVar4;
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  *puVar2 = piVar8;
  *(int **)(param_1 + 0x1c) = piVar8;
  piVar8[1] = (int)puVar2;
  *piVar8 = param_1 + 0x18;
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
  if (0x7fff < iVar6) {
    iVar6 = 0x8000;
  }
  iVar7 = FUN_00565b60(iVar6,0,0,0x2008);
  piVar8[0x25] = iVar7;
  *piVar4 = iVar6;
  FUN_0058ac20(piVar8[0x25],piVar8 + 2,0,iVar6,FUN_0053f070,param_1,piVar8);
  return piVar8;
}


// ==== 0x53f070 FUN_0053f070

void FUN_0053f070(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  short sVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  char *pcVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uint uStack_41c;
  char *pcStack_414;
  undefined4 uStack_410;
  int iStack_40c;
  uint uStack_408;
  int iStack_404;
  
  uStack_410 = *(undefined4 *)(param_3 + 0x94);
  iStack_40c = 0;
  piVar3 = *(int **)(param_3 + 0x8c);
  uStack_408 = 0;
  pcVar9 = (char *)(param_3 + 8);
  pcStack_414 = pcVar9;
  (**(code **)(param_1 + 0xc))(&pcStack_414);
  iVar5 = 0;
  if (pcVar9 != (char *)0x0) {
    cVar1 = *pcVar9;
    while (cVar1 != '\0') {
      iVar6 = iVar5 + 1;
      iVar5 = iVar5 + 1;
      cVar1 = pcVar9[iVar6];
    }
  }
  if (0x3ff < iVar5 + 0x40U) {
    pcVar9 = "<filename too long>";
  }
  FUN_00565da0("StrmHdrChks: %s",pcVar9);
  uVar4 = uStack_408;
  iVar5 = iStack_40c;
  sVar2 = *(short *)(param_3 + 0x88);
  iStack_404 = iStack_40c;
  uStack_41c = 0x2000;
  if (sVar2 != 0) {
    if ((&DAT_007301d4)[sVar2] == 0) {
      iVar6 = 0;
    }
    else if (sVar2 == 0) {
      iVar6 = 0x6300000;
    }
    else {
      iVar6 = FUN_00565810();
      iVar6 = iVar6 + -0x58;
      if (iVar6 < 0) {
        iVar6 = 0;
      }
    }
    if ((int)(uVar4 + 0x80) < iVar6) {
      uStack_41c = *(byte *)(param_3 + 0x88) & 7 | 0x2000;
    }
    else {
      *(undefined1 *)(param_3 + 0x8a) = 0;
    }
  }
  puVar7 = (undefined4 *)FUN_00565b60(uVar4,0,0,uStack_41c);
  if ((int)(iVar5 + uVar4) < *piVar3) {
    puVar10 = (undefined4 *)(iVar5 + *(int *)(param_3 + 0x94));
    puVar11 = puVar7;
    for (uVar8 = uVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar11 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
    }
    for (uVar8 = uVar4 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    piVar3[1] = 1;
    iVar5 = iStack_404;
  }
  FUN_00565ce0();
  *(undefined4 **)(param_3 + 0x94) = puVar7;
  if (piVar3[1] == 0) {
    FUN_0058ac20(puVar7,param_3 + 8,iVar5,uVar4,FUN_0053f220,param_1,param_3);
  }
  if (piVar3[1] != 0) {
    FUN_0053f220(param_1,0,param_3);
  }
  return;
}


// ==== 0x53f220 FUN_0053f220

void FUN_0053f220(int param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int local_428 [4];
  undefined4 uStack_418;
  undefined4 uStack_414;
  undefined4 uStack_410;
  undefined4 uStack_40c;
  undefined4 uStack_408;
  int iStack_404;
  undefined1 auStack_400 [1024];
  
  piVar5 = local_428;
  for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  local_428[1] = *(undefined4 *)(param_3 + 0x94);
  iVar4 = param_3 + 8;
  local_428[2] = *(undefined4 *)(*(int *)(param_3 + 0x8c) + 4);
  local_428[3] = param_3;
  local_428[0] = iVar4;
  (**(code **)(param_1 + 0x10))(local_428);
  *(undefined4 *)(param_3 + 0xa0) = uStack_414;
  *(undefined4 *)(param_3 + 0x9c) = uStack_418;
  *(undefined4 *)(param_3 + 0xb4) = uStack_410;
  *(undefined4 *)(param_3 + 0xb8) = uStack_40c;
  if (iStack_404 == 0) goto LAB_0053f351;
  uVar3 = CreateResourceFile(iVar4,6,0,uStack_408,iStack_404);
  *(undefined4 *)(param_3 + 0x98) = uVar3;
  FUN_00565da0("StrmHdrRes: %s",iVar4);
  sVar1 = *(short *)(param_3 + 0x88);
  if (sVar1 != 0) {
    if ((&DAT_007301d4)[sVar1] == 0) {
LAB_0053f301:
      iVar4 = 0;
    }
    else if (sVar1 == 0) {
      iVar4 = 0x6300000;
    }
    else {
      iVar4 = FUN_00565810();
      iVar4 = iVar4 + -0x58;
      if (iVar4 < 0) goto LAB_0053f301;
    }
    if (iVar4 <= iStack_404 + 0x80) {
      *(undefined1 *)(param_3 + 0x8a) = 0;
    }
  }
  FUN_00448070(auStack_400);
  ResourceFile__BeginLoading();
LAB_0053f351:
  if (*(int *)(param_3 + 0x98) == 0) {
    pcVar2 = *(code **)(*(int *)(param_3 + 0x8c) + 8);
    uVar3 = *(undefined4 *)(*(int *)(param_3 + 0x8c) + 0xc);
    *(undefined4 *)(param_3 + 0x90) = 1;
    FUN_00565ce0();
    *(undefined4 *)(param_3 + 0x8c) = 0;
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(uVar3);
    }
  }
  return;
}


// ==== 0x53f3a0 FUN_0053f3a0

void FUN_0053f3a0(int param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x8c) + 0xc);
  pcVar2 = *(code **)(*(int *)(param_1 + 0x8c) + 8);
  *(undefined4 *)(param_1 + 0x90) = 1;
  FUN_00565ce0();
  *(undefined4 *)(param_1 + 0x8c) = 0;
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(uVar1);
  }
  return;
}


// ==== 0x53f3e0 ResourceFileList_Remove

/* [canon] assets med (hopper+capstone) docs/re/misc.md */

undefined4 ResourceFileList_Remove(undefined4 param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int *_Memory;
  int unaff_EDI;
  
  _Memory = (int *)StringList_Find(unaff_EDI,param_1);
  if (_Memory == (int *)0x0) {
    return 0;
  }
  piVar2 = _Memory + 0x2c;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    *(undefined1 *)((int)_Memory + 0x8b) = 0;
    FUN_0053ed20(unaff_EDI);
    (**(code **)(unaff_EDI + 0x14))(_Memory);
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    if (_Memory[0x25] != 0) {
      FUN_00565ce0();
    }
    if (_Memory[0x26] != 0) {
      UnloadResourceFile();
    }
    _free(_Memory);
    *(int *)(unaff_EDI + 0x2c) = *(int *)(unaff_EDI + 0x2c) + -1;
    if (param_2 != (code *)0x0) {
      (*param_2)(param_3);
    }
  }
  return 1;
}


// ==== 0x53f470 FUN_0053f470

void FUN_0053f470(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 *unaff_EDI;
  
  unaff_EDI[2] = in_EAX;
  unaff_EDI[4] = 0;
  unaff_EDI[5] = 0;
  if (in_EAX != 0) {
    *DAT_00743c74 = unaff_EDI;
    puVar1 = unaff_EDI;
    unaff_EDI[1] = DAT_00743c74;
    DAT_00743c74 = puVar1;
    *unaff_EDI = &DAT_00743c70;
  }
  if (unaff_EDI[2] != 0) {
    Solid_FindInAllLists();
    FUN_0053f4b0();
  }
  return;
}


// ==== 0x53f4b0 FUN_0053f4b0

void FUN_0053f4b0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *in_EAX;
  int unaff_ESI;
  
  if ((in_EAX[2] != 0) && (unaff_ESI != in_EAX[3])) {
    iVar1 = *in_EAX;
    piVar2 = (int *)in_EAX[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    if (unaff_ESI != 0) {
      puVar3 = *(undefined4 **)(unaff_ESI + 0x8c);
      *puVar3 = in_EAX;
      *(int **)(unaff_ESI + 0x8c) = in_EAX;
      in_EAX[1] = (int)puVar3;
      *in_EAX = unaff_ESI + 0x88;
      in_EAX[3] = unaff_ESI;
      return;
    }
    *DAT_00743c74 = (int)in_EAX;
    piVar2 = in_EAX;
    in_EAX[1] = (int)DAT_00743c74;
    DAT_00743c74 = piVar2;
    *in_EAX = (int)&DAT_00743c70;
    in_EAX[3] = 0;
  }
  return;
}


// ==== 0x53f500 FUN_0053f500

void FUN_0053f500(void)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(in_EAX + 0x14);
  if (((*(int *)(in_EAX + 0x10) != 0) && (*(int *)(in_EAX + 0xc) != 0)) && (0 < iVar4)) {
    piVar3 = (int *)(*(int *)(in_EAX + 0x10) + 0xc);
    do {
      piVar1 = (int *)*piVar3;
      if (piVar1 != (int *)0x0) {
        iVar2 = *piVar1;
        *piVar1 = piVar3[-1];
        *piVar3 = 0;
        piVar3[-1] = iVar2;
      }
      piVar3 = piVar3 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}


// ==== 0x53f540 FUN_0053f540

void FUN_0053f540(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int in_EAX;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  
  iVar2 = *(int *)(in_EAX + 0xc);
  piVar3 = *(int **)(in_EAX + 0x10);
  iVar4 = *(int *)(in_EAX + 0x14);
  cVar1 = *(char *)(iVar2 + 0x19);
  if ((piVar3 != (int *)0x0) && (iVar4 != 0)) {
    if (0 < iVar4) {
      piVar6 = piVar3 + 2;
      iVar8 = iVar4;
      do {
        if (*piVar6 == -1) {
          iVar5 = Texture_FindByHash(piVar6[-1],1,0);
          *piVar6 = iVar5;
        }
        piVar6 = piVar6 + 4;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    iVar8 = 0;
    if (0 < cVar1) {
      do {
        iVar5 = *(int *)(iVar2 + 0x2c) + iVar8 * 8;
        iVar7 = 0;
        piVar6 = piVar3;
        if (0 < iVar4) {
          do {
            if ((piVar6[1] != 0) && (*piVar6 == *(int *)(*(int *)(iVar2 + 0x2c) + iVar8 * 8))) {
              iVar7 = *(int *)(iVar5 + 4);
              *(int *)(iVar5 + 4) = piVar6[2];
              piVar6[3] = *(int *)(iVar2 + 0x2c) + 4 + iVar8 * 8;
              piVar6[2] = iVar7;
              break;
            }
            piVar6 = piVar6 + 4;
            iVar7 = iVar7 + 1;
          } while (iVar7 < iVar4);
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < cVar1);
    }
  }
  return;
}


// ==== 0x53f5f0 FUN_0053f5f0

undefined4 __fastcall FUN_0053f5f0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int in_EAX;
  
  iVar3 = *(int *)(in_EAX + 0xc);
  if (iVar3 != 0) {
    uVar4 = *(undefined4 *)(iVar3 + 0x30);
    uVar1 = *(undefined4 *)(iVar3 + 0x24);
    uVar2 = *(undefined4 *)(iVar3 + 0x28);
    uVar5 = *(undefined4 *)(iVar3 + 0x34);
    uVar6 = *(undefined4 *)(iVar3 + 0x38);
    *param_2 = *(undefined4 *)(iVar3 + 0x20);
    param_2[1] = uVar1;
    param_2[2] = uVar2;
    *param_1 = uVar4;
    param_1[1] = uVar5;
    param_1[2] = uVar6;
    return 1;
  }
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return 0;
}


// ==== 0x53f660 FUN_0053f660

void __fastcall FUN_0053f660(undefined4 param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  
  iVar1 = *(int *)(in_EAX + 0xc);
  if ((iVar1 != 0) && (param_2 != 0)) {
    piVar2 = *(int **)(iVar1 + 0x3c);
    iVar1 = (int)*(char *)(iVar1 + 0x1a);
    if (0 < iVar1) {
      do {
        if (*piVar2 == unaff_ESI) {
          piVar2[1] = param_2;
        }
        piVar2 = piVar2 + 2;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return;
}


// ==== 0x53f690 FUN_0053f690

void FUN_0053f690(void)

{
  undefined4 *puVar1;
  
  DAT_0073557c = (undefined4 *)FUN_00566dc0(0x18,"eModelSlotPool",0);
  if (DAT_0073557c == (undefined4 *)0x0) {
    return;
  }
  if (DAT_0073d814 == 1) {
    *DAT_0073d81c = DAT_0073557c;
    puVar1 = DAT_0073557c;
    DAT_0073557c[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_0073557c = &DAT_0073d818;
  }
  return;
}


// ==== 0x53f6e0 Solid_ResolvePending

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets med (Hopper export + Ghidra export) docs/re/assets.md */

void Solid_ResolvePending(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  float fVar5;
  float fVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int local_c;
  LARGE_INTEGER local_8;
  
  QueryPerformanceCounter(&local_8);
  iVar9 = __allshr();
  piVar1 = DAT_00743c70;
  piVar10 = (int *)NullUpdate_ret();
  while (piVar7 = piVar1, piVar7 != piVar10) {
    piVar1 = (int *)*piVar7;
    if (((piVar7[2] != 0) && (iVar11 = Solid_FindInAllLists(), piVar7[2] != 0)) &&
       (iVar11 != piVar7[3])) {
      iVar2 = *piVar7;
      piVar3 = (int *)piVar7[1];
      *piVar3 = iVar2;
      *(int **)(iVar2 + 4) = piVar3;
      if (iVar11 == 0) {
        *DAT_00743c74 = (int)piVar7;
        piVar3 = piVar7;
        piVar7[1] = (int)DAT_00743c74;
        DAT_00743c74 = piVar3;
        *piVar7 = (int)&DAT_00743c70;
      }
      else {
        puVar4 = *(undefined4 **)(iVar11 + 0x8c);
        *puVar4 = piVar7;
        *(int **)(iVar11 + 0x8c) = piVar7;
        piVar7[1] = (int)puVar4;
        *piVar7 = iVar11 + 0x88;
      }
      piVar7[3] = iVar11;
    }
  }
  QueryPerformanceCounter(&local_8);
  uVar8 = DAT_007349c8;
  local_c = __allshr();
  local_c = local_c - iVar9;
  if (local_c < 0) {
    local_c = 0;
  }
  fVar5 = (float)(1 << ((byte)uVar8 & 0x1f)) * (float)local_c * _DAT_007301d0;
  fVar6 = fVar5;
  if (fVar5 < _DAT_00735580) {
    fVar6 = _DAT_00735580;
  }
  _DAT_00735580 = fVar6;
  _DAT_00735588 = _DAT_00735588 + fVar5;
  DAT_00735594 = DAT_00735594 + 1;
  _DAT_00735590 = _DAT_0073558c + _DAT_00735588;
  return;
}


// ==== 0x53f830 FUN_0053f830

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053f830(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  float fVar6;
  float fVar7;
  undefined4 uVar8;
  int in_EAX;
  int iVar9;
  int iVar10;
  int local_c;
  LARGE_INTEGER local_8;
  
  QueryPerformanceCounter(&local_8);
  iVar9 = __allshr();
  puVar1 = (undefined4 *)(in_EAX + 0x88);
  if ((undefined4 *)*puVar1 != puVar1) {
    iVar10 = 0;
    if (*(char *)(in_EAX + 0xe) < '\0') {
      iVar10 = Solid_FindInAllLists();
    }
    puVar2 = (undefined4 *)*puVar1;
    while (puVar2 != puVar1) {
      piVar3 = (int *)*puVar1;
      if ((piVar3[2] != 0) && (iVar10 != piVar3[3])) {
        iVar4 = *piVar3;
        piVar5 = (int *)piVar3[1];
        *piVar5 = iVar4;
        *(int **)(iVar4 + 4) = piVar5;
        if (iVar10 == 0) {
          *DAT_00743c74 = (int)piVar3;
          piVar5 = piVar3;
          piVar3[1] = (int)DAT_00743c74;
          DAT_00743c74 = piVar5;
          *piVar3 = (int)&DAT_00743c70;
        }
        else {
          puVar2 = *(undefined4 **)(iVar10 + 0x8c);
          *puVar2 = piVar3;
          *(int **)(iVar10 + 0x8c) = piVar3;
          piVar3[1] = (int)puVar2;
          *piVar3 = iVar10 + 0x88;
        }
        piVar3[3] = iVar10;
      }
      puVar2 = (undefined4 *)*puVar1;
    }
  }
  QueryPerformanceCounter(&local_8);
  uVar8 = DAT_007349c8;
  local_c = __allshr();
  local_c = local_c - iVar9;
  if (local_c < 0) {
    local_c = 0;
  }
  fVar6 = (float)(1 << ((byte)uVar8 & 0x1f)) * (float)local_c * _DAT_007301d0;
  fVar7 = fVar6;
  if (fVar6 < _DAT_00735584) {
    fVar7 = _DAT_00735584;
  }
  _DAT_00735584 = fVar7;
  _DAT_0073558c = _DAT_0073558c + fVar6;
  DAT_00735598 = DAT_00735598 + 1;
  _DAT_00735590 = _DAT_00735588 + _DAT_0073558c;
  return;
}


// ==== 0x53f970 FUN_0053f970

void FUN_0053f970(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *unaff_EBX;
  
  iVar4 = DAT_0073557c;
  piVar1 = (int *)*unaff_EBX;
  while (piVar1 != unaff_EBX) {
    piVar2 = (int *)piVar1[1];
    iVar3 = *piVar1;
    *piVar2 = iVar3;
    *(int **)(iVar3 + 4) = piVar2;
    ListRef_Release();
    iVar3 = *(int *)(iVar4 + 0x18);
    *piVar1 = *(int *)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar3 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*unaff_EBX;
  }
  return;
}


// ==== 0x53f9b0 Solid_ResolveTextures

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

void Solid_ResolveTextures(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBX;
  int iVar3;
  
  iVar3 = 0;
  if ('\0' < *(char *)(unaff_EBX + 0x19)) {
    do {
      iVar1 = *(int *)(unaff_EBX + 0x2c);
      uVar2 = Texture_FindByHash(*(undefined4 *)(iVar1 + iVar3 * 8),1,0);
      *(undefined4 *)(iVar1 + iVar3 * 8 + 4) = uVar2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(char *)(unaff_EBX + 0x19));
  }
  return;
}


// ==== 0x53f9f0 FUN_0053f9f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0053f9f0(int param_1,int param_2,char param_3)

{
  int iVar1;
  code *pcVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 local_11;
  LARGE_INTEGER local_10;
  LARGE_INTEGER local_8;
  
  QueryPerformanceCounter(&local_8);
  local_8.s.LowPart = __allshr();
  local_11 = 0;
  local_10.s.LowPart = 0;
  if ('\0' < *(char *)(param_1 + 0x19)) {
    do {
      uVar6 = *(undefined4 *)(*(int *)(param_1 + 0x2c) + local_10.s.LowPart * 8);
      iVar1 = *(int *)(param_1 + 0x2c) + local_10.s.LowPart * 8;
      if (param_3 == '\0') {
        if ((*(int *)(*(int *)(iVar1 + 4) + 0x68) != param_2) ||
           ((((*(int *)(param_2 + 0x70) != 0 &&
              (iVar5 = *(int *)(*(int *)(param_2 + 0x70) + 0x74), iVar5 != 0)) &&
             (iVar5 = BinarySearch_Hash(uVar6,iVar5,0), iVar5 != 0)) && (*(int *)(iVar5 + 4) != 0)))
           ) goto LAB_0053faef;
        iVar5 = Texture_FindByHash(uVar6,0,0);
        if ((iVar5 == 0) && (iVar5 = DAT_0073551c, DAT_0073551c == 0)) {
          pcVar2 = (code *)swi(3);
          uVar6 = (*pcVar2)();
          return uVar6;
        }
      }
      else if (((*(int *)(iVar1 + 4) == DAT_0073551c) && (*(int *)(param_2 + 0x70) != 0)) &&
              ((iVar5 = *(int *)(*(int *)(param_2 + 0x70) + 0x74), iVar5 != 0 &&
               ((iVar5 = BinarySearch_Hash(uVar6,iVar5,0), iVar5 != 0 &&
                (iVar5 = *(int *)(iVar5 + 4), iVar5 != 0)))))) {
        *(undefined1 *)(iVar5 + 0x53) = 1;
      }
      else {
LAB_0053faef:
        iVar5 = *(int *)(iVar1 + 4);
      }
      if (iVar5 != *(int *)(iVar1 + 4)) {
        *(int *)(iVar1 + 4) = iVar5;
        local_11 = 1;
      }
      local_10.s.LowPart = local_10.s.LowPart + 1;
    } while ((int)local_10.s.LowPart < (int)*(char *)(param_1 + 0x19));
  }
  QueryPerformanceCounter(&local_10);
  uVar6 = DAT_007349c8;
  _param_3 = __allshr();
  _param_3 = _param_3 - local_8._0_4_;
  if (_param_3 < 0) {
    _param_3 = 0;
  }
  fVar3 = (float)(1 << ((byte)uVar6 & 0x1f)) * (float)_param_3 * _DAT_007301d0;
  fVar4 = fVar3;
  if (fVar3 < _DAT_00735558) {
    fVar4 = _DAT_00735558;
  }
  _DAT_00735558 = fVar4;
  DAT_00735560 = DAT_00735560 + 1;
  _DAT_0073555c = _DAT_0073555c + fVar3;
  return CONCAT31((int3)((uint)DAT_00735560 >> 8),local_11);
}


// ==== 0x53fbc0 FUN_0053fbc0

void FUN_0053fbc0(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int in_EAX;
  uint *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_3c;
  
  iVar8 = *(int *)(in_EAX + 0x84);
  if ((((iVar8 != 0) && (param_1 != 0)) && (0 < param_2)) &&
     (local_3c = (int)*(short *)(iVar8 + 10), 0 < local_3c)) {
    puVar5 = *(uint **)(iVar8 + 4);
    do {
      uVar1 = puVar5[1];
      uVar2 = *puVar5;
      iVar9 = -1;
      iVar10 = 0;
      iVar8 = param_2 + -1;
      if (-1 < iVar8) {
        do {
          iVar6 = iVar9;
          if (iVar9 != -1) goto LAB_0053fc74;
          iVar6 = (iVar8 + iVar10) / 2;
          uVar3 = **(uint **)(param_1 + iVar6 * 4);
          if (uVar2 < uVar3) {
            iVar8 = iVar6 + -1;
            iVar6 = iVar9;
          }
          else if (uVar3 < uVar2) {
            iVar10 = iVar6 + 1;
            iVar6 = iVar9;
          }
          iVar9 = iVar6;
        } while (iVar10 <= iVar8);
        if (iVar6 != -1) {
LAB_0053fc74:
          if (0 < iVar6) {
            puVar7 = (undefined4 *)(param_1 + -4 + iVar6 * 4);
            do {
              if (*(uint *)*puVar7 != uVar2) break;
              iVar6 = iVar6 + -1;
              puVar7 = puVar7 + -1;
            } while (0 < iVar6);
          }
          while ((iVar6 < param_2 && (puVar4 = *(uint **)(param_1 + iVar6 * 4), *puVar4 == uVar2)))
          {
            if ((uVar1 & 1 << ((byte)puVar4[1] & 0x1f)) != 0) {
              bNormalize3();
            }
            iVar6 = iVar6 + 1;
          }
          bNormalize3();
        }
      }
      puVar5 = puVar5 + 3;
      local_3c = local_3c + -1;
    } while (local_3c != 0);
  }
  return;
}


// ==== 0x53fd70 FUN_0053fd70

undefined4 FUN_0053fd70(int *param_1,int param_2)

{
  uint *puVar1;
  int *piVar2;
  void *_Memory;
  int *piVar3;
  void *_Memory_00;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int local_18;
  int local_10;
  LARGE_INTEGER local_8;
  
  if ((param_1 != (int *)0x0) && (-1 < param_2)) {
    if (param_2 != 0) {
      _Memory = _malloc(param_2 * 4);
      local_10 = 0;
      if (0 < param_2) {
        local_10 = 0;
        piVar3 = param_1;
        iVar5 = param_2;
        do {
          if ((*piVar3 == 0) || (iVar6 = *(int *)(*piVar3 + 0x84), iVar6 == 0)) {
            *piVar3 = 0;
          }
          else {
            local_10 = local_10 + *(short *)(iVar6 + 8);
          }
          *(undefined4 *)(((int)_Memory - (int)param_1) + (int)piVar3) = 0;
          piVar3 = piVar3 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      QueryPerformanceCounter(&local_8);
      _Memory_00 = _malloc(local_10 * 4);
      local_18 = 0;
      if (0 < local_10) {
        do {
          puVar4 = (uint *)0x0;
          iVar5 = 0;
          iVar6 = 0;
          if (0 < param_2) {
            local_8.s.LowPart = (int)_Memory - (int)param_1;
            piVar3 = param_1;
            do {
              if (*piVar3 != 0) {
                piVar2 = *(int **)(*piVar3 + 0x84);
                if ((*(int *)((int)piVar3 + local_8.s.LowPart) < (int)(short)piVar2[2]) &&
                   ((puVar1 = (uint *)(*piVar2 + *(int *)((int)piVar3 + local_8.s.LowPart) * 8),
                    puVar4 == (uint *)0x0 || (*puVar1 < *puVar4)))) {
                  puVar4 = puVar1;
                  iVar5 = iVar6;
                }
              }
              iVar6 = iVar6 + 1;
              piVar3 = piVar3 + 1;
            } while (iVar6 < param_2);
            if (puVar4 != (uint *)0x0) {
              *(uint **)((int)_Memory_00 + local_18 * 4) = puVar4;
              local_18 = local_18 + 1;
              piVar3 = (int *)((int)_Memory + iVar5 * 4);
              *piVar3 = *piVar3 + 1;
            }
          }
          local_10 = local_10 + -1;
        } while (local_10 != 0);
      }
      iVar5 = 0;
      if (0 < param_2) {
        do {
          if (param_1[iVar5] != 0) {
            FUN_0053fbc0(_Memory_00,local_18);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < param_2);
      }
      _free(_Memory);
      _free(_Memory_00);
      return 1;
    }
    return 1;
  }
  return 0;
}


// ==== 0x53fef0 SolidList_LoadContainer

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

int * SolidList_LoadContainer(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_EAX;
  int *piVar4;
  int *piVar5;
  
  piVar4 = (int *)(in_EAX + 8);
  piVar1 = (int *)(*(int *)(in_EAX + 4) + 8 + in_EAX);
  if (piVar4 < piVar1) {
    piVar5 = (int *)0x0;
    do {
      iVar3 = *piVar4;
      if (iVar3 == 0x134002) {
        piVar5 = piVar4 + 2;
        FUN_00565da0("SolidList,%s",piVar4 + 6);
        piVar4[0x1f] = 0;
        *DAT_00743c64 = (int)piVar5;
        piVar2 = piVar5;
        piVar4[3] = (int)DAT_00743c64;
        DAT_00743c64 = piVar2;
        *piVar5 = (int)&DAT_00743c60;
        DAT_0072fa00 = DAT_0072fa00 + 1;
      }
      else if (iVar3 == 0x134003) {
        piVar5[0x1e] = (int)(piVar4 + 2);
      }
      else if (iVar3 == 0x134004) {
        piVar5[0x1f] = (int)(piVar4 + 2);
      }
      else if (iVar3 == -0x7fecbff8) {
        for (piVar2 = piVar4 + 2; piVar2 < (int *)(piVar4[1] + 8 + (int)piVar4);
            piVar2 = (int *)((int)piVar2 + piVar2[1] + 8)) {
        }
      }
      piVar4 = (int *)((int)piVar4 + piVar4[1] + 8);
    } while (piVar4 < piVar1);
    if (piVar5 != (int *)0x0) {
      *(undefined2 *)((int)piVar5 + 0x72) = 1;
      return piVar5;
    }
  }
  return (int *)0x0;
}


// ==== 0x53ffd0 Solid_Load

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

uint Solid_Load(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  
  if (*param_1 != -0x7fecbff0) {
    return 0;
  }
  piVar10 = param_1 + 2;
  piVar2 = (int *)((int)param_1 + param_1[1] + 8);
  uVar9 = 0;
  bVar3 = true;
  if (piVar10 < piVar2) {
    do {
      iVar11 = *piVar10;
      if (iVar11 == 0x134011) {
        uVar9 = (int)piVar10 + 0x17U & 0xfffffff0;
        iVar11 = uVar9 + 0x88;
        *(int *)iVar11 = iVar11;
        *(int *)(uVar9 + 0x8c) = iVar11;
      }
      else if (iVar11 == 0x134012) {
        *(int **)(uVar9 + 0x2c) = piVar10 + 2;
      }
      else if (iVar11 == 0x134013) {
        *(int **)(uVar9 + 0x3c) = piVar10 + 2;
      }
      else if (iVar11 == 0x134017) {
        *(int **)(uVar9 + 0x84) = piVar10 + 2;
        DAT_0072fa0c = DAT_0072fa0c + piVar10[1];
      }
      else if (iVar11 == 0x134018) {
        **(int **)(uVar9 + 0x84) = (int)(piVar10 + 2);
        *(short *)(*(int *)(uVar9 + 0x84) + 8) = (short)((uint)piVar10[1] >> 3);
        DAT_0072fa0c = DAT_0072fa0c + piVar10[1];
      }
      else if (iVar11 == 0x134019) {
        *(int **)(*(int *)(uVar9 + 0x84) + 4) = piVar10 + 2;
        *(short *)(*(int *)(uVar9 + 0x84) + 10) = (short)((uint)piVar10[1] / 0xc);
        DAT_0072fa0c = DAT_0072fa0c + piVar10[1];
      }
      else if (iVar11 == 0x13401b) {
        *(int **)(uVar9 + 0x90) = piVar10 + 2;
        _DAT_0072fa10 = _DAT_0072fa10 + piVar10[1];
      }
      else if (iVar11 == 0x13401a) {
        *(uint *)(uVar9 + 0x80) = (int)piVar10 + 0x17U & 0xfffffff0;
        *(char *)(uVar9 + 0x1b) =
             (char)(((piVar10[1] - ((int)piVar10 + 0x17U & 0xfffffff0)) + 8 + (int)piVar10) / 0x50);
      }
      else if ((iVar11 == -0x7fecbf00) && (iVar11 = Mesh_Load(uVar9), iVar11 == 0)) {
        bVar3 = false;
      }
      piVar10 = (int *)((int)piVar10 + piVar10[1] + 8);
    } while (piVar10 < piVar2);
    if (uVar9 != 0) {
      *(undefined1 *)(uVar9 + 0xd) = 1;
    }
  }
  Solid_ResolveTextures();
  iVar11 = (int)*(char *)(uVar9 + 0x1a);
  piVar10 = *(int **)(uVar9 + 0x3c);
  if (0 < iVar11) {
    puVar5 = (undefined *)Ptr_BaseAdjustMinus4();
    puVar4 = PTR_DAT_006f3df0;
    do {
      if (DAT_00743c18 == 0) {
        puVar6 = (undefined *)0x0;
      }
      else {
        puVar6 = (undefined *)(DAT_00743c18 + -4);
      }
      puVar7 = puVar4;
      if (puVar6 != puVar5) {
        do {
          puVar7 = puVar6;
          if (*(int *)(puVar6 + 0xc) == *piVar10) break;
          if (*(int *)(puVar6 + 4) == 0) {
            puVar6 = (undefined *)0x0;
          }
          else {
            puVar6 = (undefined *)(*(int *)(puVar6 + 4) + -4);
          }
          puVar7 = puVar4;
        } while (puVar6 != puVar5);
      }
      piVar10[1] = (int)puVar7;
      piVar10 = piVar10 + 2;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  if (((*(byte *)(uVar9 + 0xe) & 0x10) == 0) && (iVar11 = Solid_FindInAllLists(), iVar11 != 0)) {
    *(ushort *)(uVar9 + 0xe) = *(ushort *)(uVar9 + 0xe) | 0x80;
    *(ushort *)(iVar11 + 0xe) = *(ushort *)(iVar11 + 0xe) | 0x80;
    if (DAT_00735554 == 0) {
      *(ushort *)(uVar9 + 0xe) = *(ushort *)(uVar9 + 0xe) | 0x100;
      *(ushort *)(iVar11 + 0xe) = *(ushort *)(iVar11 + 0xe) | 0x100;
    }
  }
  if (param_2 == 0) {
    iVar11 = 0;
  }
  else {
    iVar11 = BinarySearch_Hash(*(undefined4 *)(uVar9 + 0x10),*(undefined4 *)(param_2 + 0x78),0);
  }
  if (bVar3) {
    if (iVar11 != 0) {
      *(uint *)(iVar11 + 4) = uVar9;
    }
    puVar8 = DAT_00743c5c;
    puVar1 = (undefined4 *)(uVar9 + 4);
    *DAT_00743c5c = puVar1;
    DAT_00743c5c = puVar1;
    *puVar1 = &DAT_00743c58;
  }
  else {
    if (iVar11 != 0) {
      *(undefined4 *)(iVar11 + 4) = 0;
    }
    puVar8 = DAT_00743c6c;
    puVar1 = (undefined4 *)(uVar9 + 4);
    *DAT_00743c6c = puVar1;
    DAT_00743c6c = puVar1;
    *puVar1 = &DAT_00743c68;
  }
  *(undefined4 **)(uVar9 + 8) = puVar8;
  DAT_0072fa04 = DAT_0072fa04 + 1;
  DAT_0072fa08 = DAT_0072fa08 + param_1[1];
  DAT_00735568 = 1;
  return uVar9;
}


// ==== 0x540270 SolidList_Unload_Impl

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

int * __fastcall SolidList_Unload_Impl(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  if (*param_2 == -0x7fecbfff) {
    iVar2 = param_2[1];
    piVar5 = (int *)0x0;
    for (piVar1 = param_2 + 2; piVar1 < (int *)(iVar2 + 8 + (int)param_2);
        piVar1 = (int *)((int)piVar1 + piVar1[1] + 8)) {
      iVar3 = *piVar1;
      if (iVar3 == 0x134002) {
        iVar3 = piVar1[2];
        piVar4 = (int *)piVar1[3];
        piVar5 = piVar1 + 2;
        *piVar4 = iVar3;
        *(int **)(iVar3 + 4) = piVar4;
        DAT_0072fa00 = DAT_0072fa00 + -1;
      }
      else if (((iVar3 != 0x134003) && (iVar3 != 0x134004)) && (iVar3 == -0x7fecbff8)) {
        for (piVar4 = piVar1 + 2; piVar4 < (int *)(piVar1[1] + 8 + (int)piVar1);
            piVar4 = (int *)((int)piVar4 + piVar4[1] + 8)) {
        }
      }
    }
    return piVar5;
  }
  return (int *)0x0;
}


// ==== 0x5402f0 SolidList_Release

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets med (Hopper export + Ghidra export) docs/re/assets.md */

void SolidList_Release(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (*param_1 == -0x7fecbff0) {
    iVar3 = param_1[1];
    uVar5 = 0;
    iVar4 = DAT_0072fa0c;
    for (piVar1 = param_1 + 2; piVar1 < (int *)(iVar3 + 8 + (int)param_1);
        piVar1 = (int *)((int)piVar1 + piVar1[1] + 8)) {
      iVar2 = *piVar1;
      if (iVar2 == 0x134011) {
        uVar5 = (int)piVar1 + 0x17U & 0xfffffff0;
      }
      else if (iVar2 == 0x134017) {
        DAT_0072fa0c = iVar4 - piVar1[1];
        iVar4 = DAT_0072fa0c;
      }
      else if (iVar2 == 0x134018) {
        DAT_0072fa0c = iVar4 - piVar1[1];
        iVar4 = DAT_0072fa0c;
      }
      else if (iVar2 == 0x134019) {
        DAT_0072fa0c = iVar4 - piVar1[1];
        iVar4 = DAT_0072fa0c;
      }
      else if (iVar2 == 0x13401b) {
        _DAT_0072fa10 = _DAT_0072fa10 - piVar1[1];
      }
      else if ((iVar2 != 0x13401a) && (iVar2 == -0x7fecbf00)) {
        Mesh_Free(piVar1);
        iVar4 = DAT_0072fa0c;
      }
    }
    if ((param_2 != 0) &&
       (iVar3 = BinarySearch_Hash(*(undefined4 *)(uVar5 + 0x10),*(undefined4 *)(param_2 + 0x78),0),
       iVar3 != 0)) {
      *(undefined4 *)(iVar3 + 4) = 0;
    }
    FUN_0053f830();
    iVar3 = *(int *)(uVar5 + 4);
    piVar1 = *(int **)(uVar5 + 8);
    *piVar1 = iVar3;
    *(int **)(iVar3 + 4) = piVar1;
    DAT_0072fa04 = DAT_0072fa04 + -1;
    DAT_0072fa08 = DAT_0072fa08 - param_1[1];
    DAT_00735568 = 1;
  }
  return;
}


// ==== 0x540420 SolidList_Load

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 SolidList_Load(int *param_1)

{
  if (*param_1 != -0x7fecbfff) {
    return 0;
  }
  SolidList_LoadContainer();
  return 1;
}


// ==== 0x540440 SolidList_Unload

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 SolidList_Unload(int *param_1)

{
  if (*param_1 != -0x7fecbfff) {
    return 0;
  }
  SolidList_Unload_Impl();
  return 1;
}


// ==== 0x540460 SolidPack_Load

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 SolidPack_Load(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*param_1 != -0x7fecc000) {
    return 0;
  }
  piVar1 = param_1 + 2;
  param_1 = (int *)(param_1[1] + 8 + (int)param_1);
  iVar2 = 0;
  if (piVar1 < param_1) {
    do {
      if (*piVar1 == -0x7fecbfff) {
        if (iVar2 != 0) {
          Solid_ResolvePending(iVar2);
        }
        iVar2 = SolidList_LoadContainer();
      }
      else if (*piVar1 == -0x7fecbff0) {
        Solid_Load(piVar1,iVar2);
      }
      piVar1 = (int *)((int)piVar1 + piVar1[1] + 8);
    } while (piVar1 < param_1);
    if (iVar2 != 0) {
      Solid_ResolvePending(iVar2);
    }
  }
  return 1;
}


// ==== 0x5404e0 SolidPack_Unload

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 SolidPack_Unload(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*param_1 == -0x7fecc000) {
    iVar2 = param_1[1];
    uVar3 = 0;
    for (piVar1 = param_1 + 2; piVar1 < (int *)(iVar2 + 8 + (int)param_1);
        piVar1 = (int *)((int)piVar1 + piVar1[1] + 8)) {
      if (*piVar1 == -0x7fecbfff) {
        uVar3 = SolidList_Unload_Impl();
      }
      else if (*piVar1 == -0x7fecbff0) {
        SolidList_Release(piVar1,uVar3);
      }
    }
    return 1;
  }
  return 0;
}


// ==== 0x540540 FUN_00540540

void FUN_00540540(int param_1,undefined4 param_2,int param_3)

{
  FUN_00447bb0(param_1 + 8,*(int *)(param_1 + 4) + 8 + param_1);
  Solid_Load(param_1,*(undefined4 *)(param_3 + 0xb4));
  Solid_ResolvePending(*(undefined4 *)(param_3 + 0xb4));
  return;
}


// ==== 0x540580 FUN_00540580

void FUN_00540580(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = Solid_FindInAllLists();
  if (iVar1 != 0) {
    SolidList_Release(param_1,*(undefined4 *)(param_3 + 0xb4));
  }
  return;
}


// ==== 0x5405b0 FUN_005405b0

void FUN_005405b0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  iVar2 = *(int *)(iVar1 + 0x14 + *(int *)(param_1 + 4));
  *(int *)(param_1 + 8) = iVar1 + 0x10;
  *(int *)(param_1 + 0xc) = iVar2 + 0x10;
  return;
}


// ==== 0x5405d0 FUN_005405d0

void FUN_005405d0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  FUN_00447bb0(iVar1 + 8,*(int *)(iVar1 + 4) + 8 + iVar1);
  iVar1 = SolidList_LoadContainer();
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar1 + 0x7c);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar1 + 0xc);
  *(int *)(param_1 + 0x18) = iVar1;
  if (*(int *)(iVar1 + 0x6c) != 0) {
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 0x68);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(iVar1 + 0x6c);
  }
  return;
}


// ==== 0x540620 FUN_00540620

void FUN_00540620(void)

{
  SolidList_Unload_Impl();
  return;
}


// ==== 0x540630 Solid_FindByHash

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

int Solid_FindByHash(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = DAT_00743c60;
  puVar2 = (undefined4 *)NullUpdate_ret();
  while( true ) {
    if (puVar1 == puVar2) {
      return 0;
    }
    if ((puVar1 != (undefined4 *)0x0) &&
       (iVar3 = BinarySearch_Hash(param_1,puVar1[0x1e],0), iVar3 != 0)) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return iVar3;
}


// ==== 0x540680 Solid_FindInAllLists

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

int __fastcall Solid_FindInAllLists(int param_1)

{
  undefined4 uVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  float10 fVar6;
  int local_c;
  LARGE_INTEGER local_8;
  
  QueryPerformanceCounter(&local_8);
  iVar2 = __allshr();
  if (DAT_006f41ac == 0) {
    if (DAT_00743c58 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = DAT_00743c58 + -4;
    }
    iVar4 = Ptr_BaseAdjustMinus4();
    while (iVar3 != iVar4) {
      if (*(int *)(iVar3 + 0x10) == param_1) {
        QueryPerformanceCounter(&local_8);
        uVar1 = DAT_007349c8;
        local_c = __allshr();
        local_c = local_c - iVar2;
        if (local_c < 0) {
          local_c = 0;
        }
        bVar5 = (byte)uVar1;
        goto LAB_0054078e;
      }
      if (*(int *)(iVar3 + 4) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(iVar3 + 4) + -4;
      }
    }
  }
  else {
    if (in_EAX == 0) {
      iVar3 = Solid_FindByHash(param_1);
    }
    else {
      iVar3 = BinarySearch_Hash(param_1,*(undefined4 *)(in_EAX + 0x78),0);
    }
    if (iVar3 != 0) {
      QueryPerformanceCounter(&local_8);
      __allshr();
      fVar6 = (float10)FUN_005648f0();
      _DAT_00735578 = (float)(fVar6 + (float10)_DAT_00735578);
      return *(int *)(iVar3 + 4);
    }
  }
  QueryPerformanceCounter(&local_8);
  uVar1 = DAT_007349c8;
  local_c = __allshr();
  local_c = local_c - iVar2;
  if (local_c < 0) {
    local_c = 0;
  }
  bVar5 = (byte)uVar1;
  iVar3 = 0;
LAB_0054078e:
  _DAT_00735578 = (float)(1 << (bVar5 & 0x1f)) * (float)local_c * _DAT_007301d0 + _DAT_00735578;
  return iVar3;
}


// ==== 0x5407f0 FUN_005407f0

void FUN_005407f0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *unaff_EDI;
  
  piVar1 = (int *)*unaff_EDI;
  while (piVar1 != unaff_EDI) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    if (piVar1 + -1 != (int *)0x0) {
      FUN_00540820();
      _free(piVar1 + -1);
    }
    piVar1 = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x540820 FUN_00540820

void FUN_00540820(void)

{
  FUN_0053f970();
  return;
}


// ==== 0x540830 FUN_00540830

float10 FUN_00540830(void)

{
  float *in_EAX;
  
  return SQRT((float10)in_EAX[2] * (float10)in_EAX[2] +
              (float10)in_EAX[1] * (float10)in_EAX[1] + (float10)*in_EAX * (float10)*in_EAX +
              (float10)in_EAX[3] + (float10)in_EAX[3]);
}


// ==== 0x540860 FUN_00540860

void __thiscall FUN_00540860(float *param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float *in_EAX;
  float local_4;
  
  fVar1 = param_1[1];
  fVar2 = param_1[2];
  *in_EAX = *param_1 - param_2;
  in_EAX[1] = fVar1 - param_3;
  in_EAX[2] = fVar2 - param_4;
  in_EAX[3] = local_4;
  return;
}


// ==== 0x5408b0 FUN_005408b0

void __thiscall FUN_005408b0(float *param_1,float param_2,float param_3,float param_4,float param_5)

{
  float *in_EAX;
  
  *in_EAX = param_2 * *param_1 + param_3 * param_1[1] + param_4 * param_1[2];
  in_EAX[1] = param_3;
  in_EAX[2] = param_4;
  in_EAX[3] = param_5;
  return;
}


// ==== 0x5408f0 FUN_005408f0

void __thiscall
FUN_005408f0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *in_EAX;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  *in_EAX = *param_1;
  in_EAX[1] = param_1[1];
  in_EAX[2] = param_1[2];
  in_EAX[3] = param_1[3];
  return;
}


// ==== 0x540930 FUN_00540930

void __fastcall FUN_00540930(undefined4 *param_1)

{
  undefined4 *in_EAX;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *in_EAX = *param_1;
  in_EAX[1] = local_c;
  in_EAX[2] = local_8;
  in_EAX[3] = local_4;
  return;
}


// ==== 0x540960 FUN_00540960

void __fastcall FUN_00540960(int param_1)

{
  undefined4 uVar1;
  undefined4 *in_EAX;
  undefined4 local_10;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar1 = *(undefined4 *)(param_1 + 4);
  *in_EAX = local_10;
  in_EAX[1] = uVar1;
  in_EAX[2] = local_8;
  in_EAX[3] = local_4;
  return;
}


// ==== 0x540990 FUN_00540990

void __fastcall FUN_00540990(int param_1)

{
  undefined4 uVar1;
  undefined4 *in_EAX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_4;
  
  uVar1 = *(undefined4 *)(param_1 + 8);
  *in_EAX = local_10;
  in_EAX[1] = local_c;
  in_EAX[2] = uVar1;
  in_EAX[3] = local_4;
  return;
}


// ==== 0x5409c0 FUN_005409c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005409c0(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *in_EAX;
  float local_4;
  
  fVar3 = _K_ONE / SQRT(param_1[2] * param_1[2] + param_1[1] * param_1[1] + *param_1 * *param_1);
  fVar1 = param_1[1];
  fVar2 = param_1[2];
  *in_EAX = fVar3 * *param_1;
  in_EAX[1] = fVar3 * fVar1;
  in_EAX[2] = fVar3 * fVar2;
  in_EAX[3] = local_4;
  return;
}


// ==== 0x540a30 FUN_00540a30

void __fastcall FUN_00540a30(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *in_EAX;
  
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  *in_EAX = *param_1;
  in_EAX[1] = param_1[1];
  in_EAX[2] = param_1[2];
  in_EAX[3] = param_1[3];
  return;
}


// ==== 0x540a60 FUN_00540a60

void FUN_00540a60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *unaff_ESI;
  int local_30 [4];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_20 = param_2;
  local_1c = param_3;
  local_18 = param_4;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_14 = 0;
  thunk_FUN_005ac436();
  *unaff_ESI = (int)local_30;
  unaff_ESI[1] = (int)&local_20;
  unaff_ESI[2] = param_1;
  unaff_ESI[3] = local_30[0];
  return;
}


// ==== 0x540ae0 FUN_00540ae0

void FUN_00540ae0(void)

{
  undefined4 *unaff_ESI;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined1 local_20 [28];
  
  D3DXVec3Transform(local_20,&stack0x00000004);
  *unaff_ESI = uStack_2c;
  unaff_ESI[1] = uStack_28;
  unaff_ESI[2] = uStack_24;
  unaff_ESI[3] = uStack_30;
  return;
}


// ==== 0x540b40 FUN_00540b40

void __fastcall FUN_00540b40(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_EAX;
  
  *in_EAX = 0;
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  in_EAX[6] = 0;
  in_EAX[7] = 0;
  in_EAX[8] = 0;
  in_EAX[9] = 0;
  in_EAX[10] = 0;
  in_EAX[0xb] = 0;
  in_EAX[0xc] = 0;
  in_EAX[0xd] = 0;
  in_EAX[0xe] = 0;
  in_EAX[0xf] = 0;
  *in_EAX = *param_2;
  in_EAX[1] = param_2[1];
  in_EAX[2] = param_2[2];
  in_EAX[3] = param_2[3];
  in_EAX[4] = param_2[4];
  in_EAX[5] = param_2[5];
  in_EAX[6] = param_2[6];
  in_EAX[7] = param_2[7];
  in_EAX[8] = param_2[8];
  in_EAX[9] = param_2[9];
  in_EAX[10] = param_2[10];
  in_EAX[0xb] = param_2[0xb];
  in_EAX[0xc] = param_2[0xc];
  in_EAX[0xd] = param_2[0xd];
  in_EAX[0xe] = param_2[0xe];
  in_EAX[0xf] = param_2[0xf];
  return;
}


// ==== 0x540be0 FUN_00540be0

void __fastcall FUN_00540be0(int param_1)

{
  float fVar1;
  undefined4 *in_EAX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_4;
  
  fVar1 = *(float *)(param_1 + 8);
  *in_EAX = local_10;
  in_EAX[1] = local_c;
  in_EAX[2] = -fVar1;
  in_EAX[3] = local_4;
  return;
}


// ==== 0x540c10 FUN_00540c10

void FUN_00540c10(void)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = in_EAX + 0x38;
  *(int *)iVar1 = iVar1;
  *(int *)(in_EAX + 0x3c) = iVar1;
  return;
}


// ==== 0x540c20 FUN_00540c20

void FUN_00540c20(void)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  int in_EAX;
  
  _Memory = *(int **)(in_EAX + 0x38);
  while (_Memory != (int *)(in_EAX + 0x38)) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = *(int **)(in_EAX + 0x38);
  }
  return;
}


// ==== 0x540c50 FUN_00540c50

bool FUN_00540c50(int param_1,int param_2)

{
  return *(short *)(param_1 + 0x2c) <= *(short *)(param_2 + 0x2c);
}


// ==== 0x540c70 FUN_00540c70

void FUN_00540c70(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar1 = DAT_00735538 + 1;
  if (0 < iVar1) {
    iVar5 = DAT_0073553c + 1;
    puVar4 = &DAT_00740b50;
    do {
      puVar2 = puVar4;
      iVar3 = iVar5;
      if (0 < iVar5) {
        do {
          *puVar2 = 0;
          iVar3 = iVar3 + -1;
          puVar2 = puVar2 + 0xc;
        } while (iVar3 != 0);
      }
      puVar4 = puVar4 + 0x78;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}


// ==== 0x540cc0 FUN_00540cc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00540cc0(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  DAT_0072fa20 = 0;
  DAT_00735538 = 0;
  DAT_0073553c = 0;
  _DAT_00735540 = 0;
  puVar1 = &DAT_00740b68;
  do {
    iVar2 = 10;
    do {
      puVar1[-5] = 0;
      puVar1[-3] = 0;
      puVar1[-4] = 0;
      puVar1[-2] = 0xc97423f0;
      puVar1[-1] = 0xc97423f0;
      *puVar1 = 0xc97423f0;
      puVar1[2] = 0x497423f0;
      puVar1[3] = 0x497423f0;
      puVar1[4] = 0x497423f0;
      puVar1 = puVar1 + 0xc;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  } while ((int)puVar1 < 0x743c28);
  return;
}


// ==== 0x540d20 FUN_00540d20

void FUN_00540d20(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  int iVar9;
  float *pfVar10;
  float *pfVar11;
  int *piVar12;
  int iVar13;
  int local_28;
  
  puVar4 = DAT_00740a60;
  DAT_0072fa20 = 0;
  iVar13 = -1;
  puVar5 = (undefined4 *)NullUpdate_ret();
  for (; puVar4 != puVar5; puVar4 = (undefined4 *)*puVar4) {
    piVar12 = (int *)puVar4[0xe];
    if (piVar12 != puVar4 + 0xe) {
      do {
        iVar7 = (int)(short)piVar12[0xb];
        iVar6 = iVar7 / 100;
        iVar9 = iVar7 % 100;
        if (DAT_00735538 < iVar6) {
          DAT_00735538 = iVar6;
        }
        if (DAT_0073553c < iVar9) {
          DAT_0073553c = iVar9;
        }
        if (iVar13 == iVar7) {
          if (DAT_0072fa20 != 0) {
            iVar9 = iVar9 + iVar6 * 10;
            (&DAT_00740b58)[iVar9 * 0xc] = (&DAT_00740b58)[iVar9 * 0xc] + 1;
          }
        }
        else {
          iVar9 = iVar9 + iVar6 * 10;
          (&DAT_00740b54)[iVar9 * 0xc] = iVar7;
          (&DAT_00740b5c)[iVar9 * 0xc] = piVar12;
          (&DAT_00740b58)[iVar9 * 0xc] = 1;
          DAT_0072fa20 = DAT_0072fa20 + 1;
          iVar13 = iVar7;
        }
        piVar12 = (int *)*piVar12;
      } while (piVar12 != puVar4 + 0xe);
    }
  }
  local_28 = DAT_00735538 + 1;
  if (0 < local_28) {
    iVar13 = DAT_0073553c + 1;
    pfVar11 = (float *)&DAT_00740b60;
    do {
      pfVar8 = pfVar11;
      iVar9 = iVar13;
      if (0 < iVar13) {
        do {
          pfVar10 = (float *)pfVar8[-1];
          iVar6 = 0;
          if (0 < (int)pfVar8[-2]) {
            do {
              fVar1 = pfVar10[4];
              iVar6 = iVar6 + 1;
              fVar2 = pfVar10[5];
              fVar3 = pfVar10[6];
              if (*pfVar8 < fVar1) {
                *pfVar8 = fVar1;
              }
              if (pfVar8[1] < fVar2) {
                pfVar8[1] = fVar2;
              }
              if (pfVar8[2] < fVar3) {
                pfVar8[2] = fVar3;
              }
              if (fVar1 < pfVar8[4]) {
                pfVar8[4] = fVar1;
              }
              if (fVar2 < pfVar8[5]) {
                pfVar8[5] = fVar2;
              }
              if (fVar3 < pfVar8[6]) {
                pfVar8[6] = fVar3;
              }
              pfVar10 = (float *)*pfVar10;
            } while (iVar6 < (int)pfVar8[-2]);
          }
          iVar9 = iVar9 + -1;
          pfVar8 = pfVar8 + 0xc;
        } while (iVar9 != 0);
      }
      pfVar11 = pfVar11 + 0x78;
      local_28 = local_28 + -1;
    } while (local_28 != 0);
  }
  return;
}


// ==== 0x540f10 LightPack_Load

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 LightPack_Load(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  
  iVar2 = *param_1;
  if (iVar2 == 0x135200) {
    if (param_1[6] == 3) {
      iVar2 = FUN_00567160();
      param_1[2] = iVar2;
      LightPack_ChunkDispatch();
      piVar4 = param_1 + 3;
      *DAT_00743c1c = (int)piVar4;
      piVar5 = piVar4;
      param_1[4] = (int)DAT_00743c1c;
      DAT_00743c1c = piVar5;
      *piVar4 = (int)&DAT_00743c18;
      if (param_1[5] == 0x2c420d64) {
        PTR_DAT_006f3df0 = (undefined *)(param_1 + 2);
      }
    }
    return 1;
  }
  if (iVar2 != -0x7fecaf00) {
    if (iVar2 != -0x7fecb000) {
      return 0;
    }
    piVar4 = param_1 + 2;
    param_1 = (int *)(param_1[1] + 8 + (int)param_1);
    puVar6 = (undefined4 *)0x0;
    if (piVar4 != param_1) {
      do {
        iVar2 = *piVar4;
        if (iVar2 == 0x135001) {
          puVar6 = (undefined4 *)((int)piVar4 + 0x17U & 0xfffffff0);
          if (puVar6[2] != 3) {
            return 1;
          }
        }
        else if (iVar2 == 0x135002) {
          piVar5 = (int *)((int)piVar4 + 0x17U & 0xfffffff0);
          puVar6[3] = piVar5;
          *piVar5 = (int)(piVar5 + 4);
        }
        else if (iVar2 == 0x135003) {
          puVar6[5] = (int)piVar4 + 0x17U & 0xfffffff0;
        }
        piVar4 = (int *)((int)piVar4 + piVar4[1] + 8);
      } while (piVar4 != param_1);
      if (puVar6 != (undefined4 *)0x0) {
        *DAT_00740a6c = puVar6;
        puVar3 = puVar6;
        puVar6[1] = DAT_00740a6c;
        DAT_00740a6c = puVar3;
        *puVar6 = &DAT_00740a68;
      }
    }
    return 1;
  }
  piVar4 = param_1 + 2;
  param_1 = (int *)(param_1[1] + 8 + (int)param_1);
  puVar6 = (undefined4 *)0x0;
  if (piVar4 != param_1) {
    do {
      if (*piVar4 == 0x135101) {
        puVar6 = (undefined4 *)((int)piVar4 + 0x17U & 0xfffffff0);
        if (puVar6[2] == 3) {
          puVar3 = puVar6 + 0xe;
          *puVar3 = puVar3;
          puVar6[0xf] = puVar3;
        }
        else {
          puVar6 = (undefined4 *)0x0;
        }
      }
      else if ((*piVar4 == 0x135102) && (puVar6 != (undefined4 *)0x0)) {
        FUN_00540cc0();
        iVar2 = puVar6[0xc];
        puVar3 = (undefined4 *)((int)piVar4 + 0x17U & 0xfffffff0);
        if (iVar2 != 0) {
          do {
            puVar1 = (undefined4 *)puVar6[0xf];
            *puVar1 = puVar3;
            puVar6[0xf] = puVar3;
            puVar3[1] = puVar1;
            *puVar3 = puVar6 + 0xe;
            puVar3 = puVar3 + 0x14;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
      }
      piVar4 = (int *)((int)piVar4 + piVar4[1] + 8);
    } while (piVar4 != param_1);
    if (puVar6 != (undefined4 *)0x0) {
      *DAT_00740a64 = puVar6;
      puVar3 = puVar6;
      puVar6[1] = DAT_00740a64;
      DAT_00740a64 = puVar3;
      *puVar6 = &DAT_00740a60;
      bList__Sort(puVar6 + 0xe,FUN_00540c50);
      FUN_00540d20();
    }
  }
  return 1;
}


