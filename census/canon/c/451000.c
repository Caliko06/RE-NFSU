// ==== 0x451190 AIActionBlock::HasBeenAccomplished

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 __fastcall AIActionBlock__HasBeenAccomplished(int param_1)

{
  int iVar1;
  uint uStack_4;
  
  uStack_4 = 0;
  iVar1 = AIActionBlock__CalculateScore(&uStack_4);
  if (-1 < iVar1) {
    if (uStack_4 != *(uint *)(param_1 + 0x200)) {
      *(uint *)(param_1 + 0x200) = uStack_4;
    }
    return 0;
  }
  return 1;
}


// ==== 0x4511e0 AIActionBlock::HasFailed

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

uint __thiscall AIActionBlock__HasFailed(int param_1,int param_2)

{
  float fVar1;
  uint uVar2;
  uint3 uVar3;
  
  uVar2 = FUN_0057b4e0(*(undefined4 *)(param_1 + 0x200));
  if ((uVar2 != 0xffffffff) && (param_2 = uVar2 * 0x38 + 8 + param_2, uVar2 = 0, param_2 != 0)) {
    fVar1 = *(float *)(param_2 + 0x10);
    uVar3 = (uint3)(CONCAT22((short)((uint)param_2 >> 0x10),
                             (ushort)(fVar1 < 0.0) << 8 | (ushort)NAN(fVar1) << 10 |
                             (ushort)(fVar1 == 0.0) << 0xe) >> 8);
    if (fVar1 >= 0.0 && (fVar1 == 0.0) == 0) {
      return CONCAT31(uVar3,1);
    }
    return (uint)uVar3 << 8;
  }
  return uVar2 & 0xffffff00;
}


// ==== 0x451230 AIActionBlock::CalculatePointsToDrive

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall AIActionBlock__CalculatePointsToDrive(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  float10 fVar4;
  int iStack_28;
  float fStack_24;
  undefined4 uStack_18;
  
  iVar3 = *param_2;
  piVar2 = *(int **)(iVar3 + 0x2c);
  fStack_24 = DAT_007061e8;
  iStack_28 = 0;
  uStack_18 = 0;
  if ((&DAT_0077a344)[*(char *)(*(int *)(piVar2[1] + 0x14) + 0x736) * 8] != '\0') {
    uStack_18 = 0x3f800000;
  }
  *(undefined1 *)(iVar3 + 0x88c) = 1;
  *(undefined4 *)(iVar3 + 0x894) = 0;
  *(undefined4 *)(iVar3 + 0x898) = 0;
  *(undefined4 *)(iVar3 + 0x89c) = 0;
  *(undefined4 *)(iVar3 + 0x890) = 0x437f0000;
  iVar3 = FUN_0057b4e0(*(undefined4 *)(param_1 + 0x200));
  if ((iVar3 != -1) && (piVar1 = param_2 + iVar3 * 0xe + 2, piVar1 != (int *)0x0)) {
    iVar3 = param_2[0xe5];
    if ((iVar3 < 0) || (4 < iVar3)) {
      if ((iVar3 < 0xb) || (0x10 < iVar3)) {
        iStack_28 = 0;
      }
      else {
        iStack_28 = piVar1[iVar3 + -5];
      }
    }
    else {
      iStack_28 = piVar1[5];
    }
    param_2[0xe6] = 1;
    param_2[0xe7] = 0;
    *(undefined1 *)(param_2 + 0xe9) = 0;
    param_2[0xe8] = 0;
    FUN_00458f10(0,0);
    if (10.0 <= (float)piVar1[4] - (float)param_2[(char)param_2[0xe2] * 0xe + 6]) {
      if (0.001 < ABS((float)piVar1[1])) {
        fVar4 = (float10)LinearTable__Lookup11
                                   (&PTR_DAT_007061f4,
                                    ((float)piVar1[4] -
                                    (float)param_2[(char)param_2[0xe2] * 0xe + 6]) /
                                    (float)piVar1[1]);
        fStack_24 = (float)fVar4;
      }
    }
    else {
      fStack_24 = DAT_007061e8;
    }
  }
  FUN_0045c370(param_1 + 0x20,param_2,uStack_18,1,iStack_28,fStack_24);
  fVar4 = (float10)(**(code **)(*piVar2 + 0x5c))();
  *(float *)(param_1 + 0x1e4) = (float)fVar4;
  *(undefined1 *)(param_1 + 0x1f0) = 1;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0x40000000;
  *(undefined1 *)(param_1 + 0x1f1) = 1;
  *(undefined1 *)(param_1 + 0x1f2) = 1;
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  return;
}


// ==== 0x4512f0 FUN_004512f0

void __thiscall FUN_004512f0(undefined4 param_1)

{
  float fVar1;
  int in_EAX;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  float10 fVar2;
  undefined4 uStack00000018;
  int *in_stack_0000002c;
  
  if (in_EAX < 0x11) {
    uStack00000018 = *(undefined4 *)(unaff_EBX + -0x14 + in_EAX * 4);
  }
  else {
    uStack00000018 = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x398) = 1;
  *(undefined4 *)(unaff_ESI + 0x39c) = param_1;
  *(undefined1 *)(unaff_ESI + 0x3a4) = 0;
  *(undefined4 *)(unaff_ESI + 0x3a0) = param_1;
  FUN_00458f10(param_1,param_1);
  fVar1 = *(float *)(unaff_EBX + 0x10) -
          *(float *)(*(char *)(unaff_ESI + 0x388) * 0x38 + 0x18 + unaff_ESI);
  if ((10.0 <= fVar1) && (0.001 < ABS(*(float *)(unaff_EBX + 4)))) {
    LinearTable__Lookup11(&PTR_DAT_007061f4,fVar1 / *(float *)(unaff_EBX + 4));
  }
  FUN_0045c370(unaff_EDI + 0x20);
  fVar2 = (float10)(**(code **)(*in_stack_0000002c + 0x5c))();
  *(float *)(unaff_EDI + 0x1e4) = (float)fVar2;
  *(undefined1 *)(unaff_EDI + 0x1f0) = 1;
  *(undefined4 *)(unaff_EDI + 0x1e8) = 0;
  *(undefined4 *)(unaff_EDI + 0x1ec) = 0x40000000;
  *(undefined1 *)(unaff_EDI + 0x1f1) = 1;
  *(undefined1 *)(unaff_EDI + 0x1f2) = 1;
  *(undefined1 *)(unaff_EDI + 0x1e0) = 1;
  return;
}


// ==== 0x451400 AIActionPullOver::AIActionPullOver

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall
AIActionPullOver__AIActionPullOver(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  float *pfVar1;
  undefined4 *unaff_ESI;
  int *unaff_EDI;
  
  AIAction__AIAction(9,param_1,param_2);
  *unaff_ESI = &PTR_FUN_006c925c;
  unaff_ESI[0x80] = 0;
  unaff_ESI[0x81] = 0;
  unaff_ESI[0x80] = DAT_0073ad34;
  *(undefined1 *)(unaff_ESI + 0x82) = 1;
  unaff_ESI[0x83] = param_3;
  if ((unaff_EDI == (int *)0x0) || (unaff_EDI == (int *)0xfffffc74)) {
    *(undefined1 *)((int)unaff_ESI + 0x209) = 1;
  }
  else {
    pfVar1 = (float *)unaff_EDI[0xe4];
    if ((pfVar1[10] - (float)unaff_EDI[(char)unaff_EDI[0xe2] * 0xe + 4]) -
        ((*(float *)(*unaff_EDI + 0x60) - *pfVar1) * pfVar1[4] -
        (*(float *)(*unaff_EDI + 100) - pfVar1[1]) * pfVar1[3]) <= 2.0) {
      *(undefined1 *)((int)unaff_ESI + 0x209) = 0;
    }
    else {
      *(undefined1 *)((int)unaff_ESI + 0x209) = 1;
    }
  }
  unaff_ESI[0x81] = 0;
  FUN_00458f10(0,0);
  return;
}


// ==== 0x4514c0 AIActionPullOver::DoSnapshot

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall AIActionPullOver__DoSnapshot(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIActionPullOver");
  AIAction__DoSnapshot(param_2);
  FUN_00571c20(param_2,param_1 + 0x200,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x204,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x208,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x209,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x20c,4,0xffffffff,0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x451580 AIActionPullOver::HasBeenAccomplished

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

bool AIActionPullOver__HasBeenAccomplished(int *param_1)

{
  return *(int *)(*param_1 + 0x24) == 4;
}


// ==== 0x451590 AIActionPullOver::GetDistanceToRightEdgeOfRoute

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

float10 __fastcall AIActionPullOver__GetDistanceToRightEdgeOfRoute(undefined4 param_1,int *param_2)

{
  float *in_EAX;
  
  return ((float10)in_EAX[10] - (float10)(float)param_2[(char)param_2[0xe2] * 0xe + 4]) -
         (((float10)*(float *)(*param_2 + 0x60) - (float10)*in_EAX) * (float10)in_EAX[4] -
         ((float10)*(float *)(*param_2 + 100) - (float10)in_EAX[1]) * (float10)in_EAX[3]);
}


// ==== 0x4515c0 AIActionPullOver::CalculatePointsToDrive

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall AIActionPullOver__CalculatePointsToDrive(int param_1,int *param_2)

{
  int *piVar1;
  char cVar2;
  float fVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int *extraout_EDX;
  undefined4 *puVar7;
  undefined4 *puVar8;
  bool bVar9;
  float10 fVar10;
  float local_1e8;
  char local_1e2;
  undefined1 local_1e1;
  int local_1e0;
  int local_1dc;
  int local_1d8;
  uint local_1d4;
  undefined4 local_1d0 [105];
  undefined4 local_2c;
  undefined4 local_28;
  
  puVar7 = (undefined4 *)(*(int *)(*param_2 + 0x30) + 0x10);
  puVar8 = (undefined4 *)(param_1 + 0x20);
  for (iVar5 = 0x70; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  fVar3 = ABS(*(float *)(param_1 + 0x20c) - -999.0);
  *(undefined1 *)(param_1 + 0x1f0) = 0;
  *(undefined1 *)(param_1 + 0x1f1) = 1;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined1 *)(param_1 + 0x1f2) = 0;
  local_1e2 = *(int *)(*(int *)(*param_2 + 0x14) + 4) == 1;
  local_1e8 = (float)(DAT_0073ad34 - *(int *)(param_1 + 0x200));
  if ((fVar3 < 0.001 != (fVar3 == 0.001)) ||
     ((float)(int)local_1e8 * 0.00025 < *(float *)(param_1 + 0x20c))) {
    local_1e8 = (float)(DAT_0073ad34 - *(int *)(param_1 + 0x204));
    if ((0.3 < (float)(int)local_1e8 * 0.00025) || (*(char *)(param_1 + 0x20) == '\0')) {
      piVar1 = param_2 + 0xe6;
      *(int *)(param_1 + 0x204) = DAT_0073ad34;
      if (*piVar1 != 1) {
        *piVar1 = 1;
        param_2[0xe7] = 0;
        *(undefined1 *)(param_2 + 0xe9) = 0;
        param_2[0xe8] = 0;
      }
      *(undefined1 *)(param_1 + 0x208) = 1;
      if ((bool)local_1e2) {
        FUN_0045ae10(piVar1,param_1 + 0x20,param_2,0,2);
      }
      else {
        FUN_00458f10(0,0);
        FUN_0045c370(param_1 + 0x20,param_2,0,4,0,0x47c34f80);
      }
      local_1e8 = 0.0;
      iVar5 = FUN_00457590(&DAT_0077a4ac,param_1 + 0x20,param_2 + 0xe3,DAT_007006ec,&local_1e8);
      if ((iVar5 != 0) && (local_1e8 < 2.0)) {
        local_2c = 0;
        local_28 = 0;
        puVar7 = local_1d0;
        for (iVar6 = 0x70; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
        FUN_00458f10(0,0);
        local_1e1 = 1;
        local_1e0 = 2;
        local_1d4 = local_1d4 & 0xffffff00;
        local_1d8 = 0;
        local_1dc = iVar5;
        uVar4 = FUN_0045b150(&local_1e0,local_1d0,param_2,DAT_007006ec,&local_1e1,1);
        *(undefined1 *)(param_1 + 0x208) = uVar4;
        puVar7 = local_1d0;
        puVar8 = (undefined4 *)(param_1 + 0x20);
        for (iVar5 = 0x70; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        param_2[0xe6] = local_1e0;
        param_2[0xe7] = local_1dc;
        param_2[0xe8] = local_1d8;
        param_2[0xe9] = local_1d4;
      }
    }
    iVar5 = 0;
    local_1e8 = *(float *)(*param_2 + 0x3d4);
    if (local_1e2 == '\0') {
      if ((param_2[0xe3] == 0) || (*(char *)(param_1 + 0x208) == '\0')) {
        AIAction__SetDesiredSpeedToMaxDeceleration(0x3e4ccccd);
      }
      else if (local_1e8 <= 15.0) {
        fVar10 = (float10)AIActionPullOver__GetDistanceToRightEdgeOfRoute(param_1);
        if (*(char *)(param_1 + 0x209) == '\0') {
          if ((float10)2.0 + (float10)2.0 < fVar10) {
            *(undefined1 *)(param_1 + 0x209) = 1;
          }
        }
        else if (fVar10 < (float10)2.0) {
          *(undefined1 *)(param_1 + 0x209) = 0;
        }
        if (*(char *)(param_1 + 0x209) == '\0') {
          *(undefined4 *)(param_1 + 0x1e4) = 0;
          *(undefined4 *)(param_1 + 0x1ec) = 0;
        }
        else {
          fVar3 = 15.0 - _K_ONE;
          *(undefined4 *)(param_1 + 0x1ec) = 0x40000000;
          *(float *)(param_1 + 0x1e4) = fVar3;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x209) = 1;
        *(undefined4 *)(param_1 + 0x1e4) = 0;
        *(undefined4 *)(param_1 + 0x1ec) = 0;
      }
    }
    else if (*(char *)(param_1 + 0x208) == '\0') {
      fVar10 = (float10)FUN_00456960(*(undefined4 *)(*param_2 + 0x3d4));
      *(float *)(param_1 + 0x1e4) = (float)(fVar10 * (float10)0.2 + (float10)local_1e8);
      param_2 = extraout_EDX;
    }
    else {
      *(undefined4 *)(param_1 + 0x1e4) = 0;
      *(undefined4 *)(param_1 + 0x1ec) = 0;
    }
    if (0.5 <= *(float *)(param_1 + 0x1e4)) {
      local_1e8 = (float)(int)*(char *)(*(int *)(*param_2 + 0x3c) + 0x1c);
      if (0 < (int)local_1e8) {
        do {
          iVar6 = CollisionBody__GetCollision(iVar5);
          iVar6 = *(int *)(iVar6 + 100);
          cVar2 = *(char *)(*(int *)(iVar6 + 600) + 0x15);
          if ((cVar2 == '\0') && (*(char *)(*(int *)(iVar6 + 0x25c) + 0x15) == '\0')) {
LAB_004519bb:
            *(undefined4 *)(param_1 + 0x1e4) = 0;
            *(undefined4 *)(param_1 + 0x1ec) = 0;
            break;
          }
          if (cVar2 == '\0') {
            bVar9 = *(char *)(*(int *)(iVar6 + 0x25c) + 0x15) == '\x04';
LAB_004519a9:
            if (bVar9) goto LAB_004519bb;
          }
          else if (cVar2 == '\x04') {
            bVar9 = *(char *)(*(int *)(iVar6 + 0x25c) + 0x15) == '\0';
            goto LAB_004519a9;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < (int)local_1e8);
      }
      goto LAB_004519c9;
    }
  }
  else {
    local_1e0 = 1;
    local_1dc = 0;
    local_1d4 = local_1d4 & 0xffffff00;
    local_1d8 = 0;
    FUN_0045ae10(&local_1e0,param_1 + 0x20,param_2,0,2);
  }
  *(undefined4 *)(param_1 + 0x1e4) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
LAB_004519c9:
  *(undefined4 *)(param_1 + 0x1e8) = 0x3e4ccccd;
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  return;
}


// ==== 0x4519f0 AIActionGetUnstuck::AIActionGetUnstuck

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall
AIActionGetUnstuck__AIActionGetUnstuck(undefined4 param_1,undefined4 param_2,float param_3)

{
  undefined4 *unaff_ESI;
  
  AIAction__AIAction(10,param_1,param_2);
  *unaff_ESI = &PTR_FUN_006c916c;
  unaff_ESI[0x80] = 0;
  unaff_ESI[0x80] = DAT_0073ad34;
  unaff_ESI[0x81] = param_3;
  if (ABS(param_3 - -1.0) < 0.001 != (ABS(param_3 - -1.0) == 0.001)) {
    *(undefined1 *)(unaff_ESI + 0x82) = 0;
    return;
  }
  *(undefined1 *)(unaff_ESI + 0x82) = 1;
  return;
}


// ==== 0x451a70 AIActionGetUnstuck::DoSnapshot

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall AIActionGetUnstuck__DoSnapshot(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIActionGetUnstuck");
  FUN_00571c20(param_2,param_1 + 0x200,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x204,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x208,1,1,0);
  AIAction__DoSnapshot(param_2);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x451b00 AIActionGetUnstuck::CalculateScore

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 AIActionGetUnstuck__CalculateScore(int *param_1)

{
  float *pfVar1;
  float fVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  bVar3 = false;
  cVar4 = RaceManager__IsInRaceStartWindow(DAT_0073619c,*param_1);
  if (cVar4 != '\0') {
    return 0xffffffff;
  }
  if (param_1[0xe3] == 0) {
    return 0xffffffff;
  }
  cVar4 = FUN_0057a7d0();
  if (cVar4 == '\0') {
    return 0xffffffff;
  }
  pfVar1 = (float *)param_1[0xe4];
  if (pfVar1 == (float *)0x0) {
LAB_00451b94:
    iVar5 = *param_1;
    if ((((*(int *)(iVar5 + 0x24) != 3) ||
         (*(float *)(iVar5 + 0x3d4) < 25.0 == (*(float *)(iVar5 + 0x3d4) == 25.0))) &&
        ((*(int *)(iVar5 + 0x24) != 4 ||
         (*(float *)(iVar5 + 0x3d4) < 20.0 == (*(float *)(iVar5 + 0x3d4) == 20.0))))) ||
       (iVar5 = AIAction__GetHeadingClassification(1), iVar5 != 1)) goto LAB_00451be0;
  }
  else {
    fVar2 = (*(float *)(*param_1 + 0x60) - *pfVar1) * pfVar1[4] -
            (*(float *)(*param_1 + 100) - pfVar1[1]) * pfVar1[3];
    if (fVar2 <= 0.0) {
      fVar2 = -(fVar2 + pfVar1[9]);
    }
    else {
      fVar2 = fVar2 - pfVar1[10];
    }
    if (fVar2 < 20.0) goto LAB_00451b94;
  }
  bVar3 = true;
LAB_00451be0:
  iVar5 = *(int *)(*param_1 + 0x3c);
  iVar8 = 0;
  if ('\0' < *(char *)(iVar5 + 0x1c)) {
    do {
      if (bVar3) goto LAB_00451c8b;
      iVar6 = CollisionBody__GetCollision(iVar8);
      iVar7 = AIAction__GetCollisionClassification();
      if (((iVar7 == 0) && (0.4 <= (float)(DAT_0073ad34 - *(int *)(iVar6 + 8)) * 0.00025)) &&
         ((*(float *)(*param_1 + 0x3d4) < 5.0 ||
          (iVar6 = bAlmostEqual_float(*(float *)(*param_1 + 0x3d4),0x40a00000,0x3a83126f),
          iVar6 != 0)))) {
        bVar3 = true;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(char *)(iVar5 + 0x1c));
  }
  if (!bVar3) {
    return 0xffffffff;
  }
LAB_00451c8b:
  (**(code **)(**(int **)(*param_1 + 0x2c) + 0x2c))(1);
  return 500;
}


// ==== 0x451cb0 AIActionGetUnstuck::GetGoalPoint

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void AIActionGetUnstuck__GetGoalPoint(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  int *unaff_EBX;
  float *unaff_EDI;
  
  iVar3 = *unaff_EBX;
  pfVar6 = (float *)((((unaff_EBX[1] - iVar3) + -0x27c) / 0x88) * 0x88 + 0x414 + iVar3);
  if (pfVar6 == (float *)0x0) {
    pfVar6 = (float *)(*(short *)(iVar3 + 0x10) * 0x88 + 500 + iVar3);
  }
  fVar4 = (float)((int)*(short *)((int)pfVar6 + unaff_EBX[2] * 2 + 0x3c) << 8) * 1.5258789e-05;
  fVar1 = pfVar6[4];
  fVar5 = -pfVar6[3] * fVar4 + pfVar6[1];
  fVar2 = *pfVar6;
  unaff_EDI[1] = fVar5;
  *unaff_EDI = fVar1 * fVar4 + fVar2;
  fVar1 = pfVar6[4];
  *unaff_EDI = pfVar6[3] * 0.0 + *unaff_EDI;
  unaff_EDI[1] = fVar1 * 0.0 + fVar5;
  return;
}


// ==== 0x451d50 AIActionGetUnstuck::GetGoalPoint

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void AIActionGetUnstuck__GetGoalPoint(void)

{
  int iVar1;
  int iVar2;
  int *unaff_EDI;
  
  iVar1 = *unaff_EDI;
  iVar2 = (((unaff_EDI[1] - iVar1) + -0x27c) / 0x88) * 0x88 + 0x414 + iVar1;
  if (iVar2 == 0) {
    iVar2 = *(short *)(iVar1 + 0x10) * 0x88 + 500 + iVar1;
  }
  FUN_004422b0(0,(float)((int)*(short *)(iVar2 + 0x3c + unaff_EDI[2] * 2) << 8) * 1.5258789e-05);
  return;
}


// ==== 0x451dc0 AIActionGetUnstuck::HasBeenAccomplished

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 __thiscall AIActionGetUnstuck__HasBeenAccomplished(int param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  undefined2 extraout_var;
  int iVar5;
  int iVar6;
  int iVar7;
  float fStack_8;
  float fStack_4;
  
  if (*(char *)(param_1 + 0x208) != '\0') {
    iVar4 = DAT_0073ad34 - *(int *)(param_1 + 0x200);
    fVar2 = (float)iVar4 * 0.00025;
    fVar1 = *(float *)(param_1 + 0x204);
    if (fVar2 < fVar1) {
      return CONCAT22((short)((uint)iVar4 >> 0x10),
                      (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                      (ushort)(fVar2 == fVar1) << 0xe);
    }
  }
  AIActionGetUnstuck__GetGoalPoint(param_1);
  iVar4 = *param_2;
  fVar1 = *(float *)(iVar4 + 0x60);
  fVar2 = *(float *)(iVar4 + 100);
  bNormalize2();
  bNormalize2();
  fVar1 = (fStack_8 - fVar1) * fStack_8 + fStack_4 * (fStack_4 - fVar2);
  iVar4 = *(int *)(iVar4 + 0x3c);
  cVar3 = *(char *)(iVar4 + 0x1c);
  iVar5 = CONCAT31((int3)(CONCAT22(extraout_var,
                                   (ushort)(fVar1 < 0.9) << 8 | (ushort)NAN(fVar1) << 10 |
                                   (ushort)(fVar1 == 0.9) << 0xe) >> 8),cVar3);
  if ('\0' < cVar3) {
    iVar7 = 0;
    do {
      iVar5 = CollisionBody__GetCollision(iVar7);
      iVar6 = AIAction__GetCollisionClassification();
      if ((iVar6 == 0) && (0.4 <= (float)(DAT_0073ad34 - *(int *)(iVar5 + 8)) * 0.00025)) {
        fVar2 = *(float *)(*param_2 + 0x3d4);
        if (fVar2 < 5.0) {
          return CONCAT22((short)((uint)*(int *)(iVar5 + 8) >> 0x10),
                          (ushort)(fVar2 < 5.0) << 8 | (ushort)NAN(fVar2) << 10 |
                          (ushort)(fVar2 == 5.0) << 0xe);
        }
      }
      iVar5 = (int)*(char *)(iVar4 + 0x1c);
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar5);
  }
  return CONCAT31((int3)((uint)iVar5 >> 8),fVar1 < 0.9 == 0);
}


// ==== 0x451f10 AIActionGetUnstuck::HasFailed

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

char __thiscall AIActionGetUnstuck__HasFailed(int param_1,int *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  cVar2 = '\0';
  if (param_2[0xe3] == 0) {
    return '\x01';
  }
  cVar1 = FUN_0057a7d0();
  if (cVar1 != '\0') {
    if ((*(char *)(param_1 + 0x208) == '\0') ||
       (*(float *)(param_1 + 0x204) <= (float)(DAT_0073ad34 - *(int *)(param_1 + 0x200)) * 0.00025))
    {
      iVar3 = AIAction__GetHeadingClassification(1);
      if (iVar3 == 2) {
        return '\x01';
      }
      iVar3 = *(int *)(*param_2 + 0x3c);
      iVar6 = 0;
      if ('\0' < *(char *)(iVar3 + 0x1c)) {
        do {
          if (cVar2 != '\0') {
            return cVar2;
          }
          iVar4 = CollisionBody__GetCollision(iVar6);
          iVar5 = AIAction__GetCollisionClassification();
          if (((iVar5 == 1) && (0.4 <= (float)(DAT_0073ad34 - *(int *)(iVar4 + 8)) * 0.00025)) &&
             ((ABS(*(float *)(*param_2 + 0x3d4)) < 5.0 ||
              (iVar4 = bAlmostEqual_float(*(float *)(*param_2 + 0x3d4),0x40a00000,0x3a83126f),
              iVar4 != 0)))) {
            cVar2 = '\x01';
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(char *)(iVar3 + 0x1c));
      }
    }
    return cVar2;
  }
  return '\x01';
}


// ==== 0x452070 AIActionGetUnstuck::CalculatePointsToDrive

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall AIActionGetUnstuck__CalculatePointsToDrive(int param_1,int *param_2)

{
  int iVar1;
  undefined1 local_20 [28];
  
  if (param_2[0xe6] != 1) {
    param_2[0xe6] = 1;
    param_2[0xe7] = 0;
    *(undefined1 *)(param_2 + 0xe9) = 0;
    param_2[0xe8] = 0;
  }
  FUN_00458f10(0,0);
  *(undefined1 *)(param_1 + 0x1f0) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined1 *)(param_1 + 0x1f2) = 0;
  *(undefined1 *)(param_1 + 0x1f1) = 1;
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  if (param_2[0xe3] == 0) {
    *(undefined1 *)(param_1 + 0x1e0) = 0;
    return;
  }
  AIActionGetUnstuck__GetGoalPoint(param_1,local_20);
  iVar1 = param_2[0xe3];
  if (iVar1 != 0) {
    FUN_004594d0(*(undefined1 *)(iVar1 + 10),((param_2[0xe4] - iVar1) + -0x27c) / 0x88,param_2[0xe5]
                 ,0);
  }
  FUN_0045c370(param_1 + 0x20,param_2,0x3f800000,2,0,0x47c34f80);
  if (*(int *)(*param_2 + 0x24) == 3) {
    *(undefined4 *)(param_1 + 0x1e4) = 0xc1700000;
    return;
  }
  *(undefined4 *)(param_1 + 0x1e4) = 0xc0c00000;
  return;
}


// ==== 0x452190 AIActionGetUnstuck::CleanUp

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void AIActionGetUnstuck__CleanUp(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  (**(code **)(**(int **)(iVar1 + 0x2c) + 0x2c))(1);
  (**(code **)(**(int **)(iVar1 + 0x30) + 0x5c))();
  *(undefined1 *)(*param_1 + 0x88c) = 0;
  return;
}


// ==== 0x4521c0 AIActionIJustGotHit::AIActionIJustGotHit

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall
AIActionIJustGotHit__AIActionIJustGotHit(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *unaff_ESI;
  
  AIAction__AIAction(0xc,param_1,param_2);
  *unaff_ESI = &PTR_FUN_006c90cc;
  unaff_ESI[0x81] = 0;
  unaff_ESI[0x81] = 0;
  unaff_ESI[0x80] = param_3;
  return;
}


// ==== 0x452200 AIActionIJustGotHit::DoSnapshot

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall AIActionIJustGotHit__DoSnapshot(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIActionIJustGotHit");
  AIAction__DoSnapshot(param_2);
  FUN_00571c20(param_2,param_1 + 0x204,4,0xffffffff,0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x452270 AIActionIJustGotHit::HasBeenAccomplished

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall AIActionIJustGotHit__HasBeenAccomplished(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = AIAction__GetMostImportantNearbyCollidingAvoidable(param_2,0xbf800000,1);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x200) = *(undefined4 *)(iVar1 + 0x34);
  }
  return;
}


// ==== 0x4522a0 AIActionIJustGotHit::CalculatePointsToDrive

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall AIActionIJustGotHit__CalculatePointsToDrive(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  int *piVar7;
  float10 fVar8;
  
  piVar3 = param_2;
  piVar2 = *(int **)(*param_2 + 0x2c);
  iVar4 = 0;
  piVar1 = param_2 + 0xe6;
  if (0 < param_2[1]) {
    piVar7 = param_2 + 0xf;
    do {
      if (*piVar7 == *(int *)(param_1 + 0x200)) {
        if (iVar4 != -1) {
          param_2 = param_2 + iVar4 * 0xe + 2;
          goto LAB_004522e8;
        }
        break;
      }
      iVar4 = iVar4 + 1;
      piVar7 = piVar7 + 0xe;
    } while (iVar4 < param_2[1]);
  }
  param_2 = (int *)0x0;
LAB_004522e8:
  piVar7 = param_2;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined1 *)(param_1 + 0x1f0) = 0;
  *(undefined1 *)(param_1 + 0x1f1) = 1;
  if (param_2 == (int *)0x0) {
    param_2 = (int *)0x0;
    FUN_0045b150(piVar1,param_1 + 0x20,piVar3,DAT_007006ec,&param_2,1);
LAB_004523d8:
    *(undefined1 *)(param_1 + 0x1f0) = 1;
    goto LAB_004523df;
  }
  fVar8 = (float10)FUN_0057b480();
  iVar4 = *(int *)(param_1 + 0x200);
  if (fVar8 <= (float10)0.0) {
    if (iVar4 != 0) {
      *piVar1 = 3;
      goto LAB_00452352;
    }
  }
  else if (iVar4 != 0) {
    *piVar1 = 2;
LAB_00452352:
    piVar3[0xe7] = iVar4;
    *(undefined1 *)(piVar3 + 0xe9) = 0;
    piVar3[0xe8] = 0;
  }
  FUN_0045ae10(piVar1,param_1 + 0x20,piVar3,0,0);
  iVar4 = AIAction__GetHeadingClassification(0);
  if ((iVar4 == 1) && (0.0 < (float)piVar7[4] - (float)piVar3[(char)piVar3[0xe2] * 0xe + 6])) {
    AIAction__SetDesiredSpeedToMaxDeceleration(0x3e4ccccd);
    goto LAB_004523df;
  }
  iVar4 = *(int *)(param_1 + 0x200);
  iVar5 = FUN_00647b70();
  if (((iVar5 == 6) &&
      (*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 0x1d4) + 0x90) + 0x14) + 4) == 1)) &&
     (*(int *)(*(int *)(*piVar3 + 0x14) + 4) != 3)) {
    if (((float)piVar3[(char)piVar3[0xe2] * 0xe + 5] + (float)piVar7[3]) - 2.8 <
        (float)piVar7[4] - (float)piVar3[(char)piVar3[0xe2] * 0xe + 6]) {
      AIAction__SetDesiredSpeedSlowerThanThisAvoidable(param_1,0x40c00000,0x3e4ccccd);
      goto LAB_004523df;
    }
    if (2.8 - ((float)piVar3[(char)piVar3[0xe2] * 0xe + 5] + (float)piVar7[3]) <=
        (float)piVar7[4] - (float)piVar3[(char)piVar3[0xe2] * 0xe + 6]) goto LAB_004523d8;
LAB_004524bf:
    fVar8 = (float10)(**(code **)(*piVar2 + 0x5c))();
  }
  else {
    if ((float)piVar7[4] - (float)piVar3[(char)piVar3[0xe2] * 0xe + 6] <= 0.0) goto LAB_004524bf;
    iVar4 = *piVar3;
    if ((*(int *)(*(int *)(iVar4 + 0x14) + 4) != 3) ||
       (pfVar6 = (float *)FUN_00578730(),
       0.0 <= *(float *)(iVar4 + 0x90) * *pfVar6 + *(float *)(iVar4 + 0x94) * pfVar6[1])) {
      AIAction__SetDesiredSpeedSlowerThanThisAvoidable(param_1,0x3dcccccd,0x3e4ccccd);
      goto LAB_004523df;
    }
    *(undefined1 *)(param_1 + 0x1f1) = 0;
    fVar8 = (float10)*(float *)(*piVar3 + 0x3d4);
  }
  *(float *)(param_1 + 0x1e4) = (float)fVar8;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
LAB_004523df:
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  if ((*(char *)(param_1 + 0x1f0) == '\0') && (*(float *)(param_1 + 0x1e4) < 20.0)) {
    *(undefined4 *)(param_1 + 0x1e4) = 0x41a00000;
  }
  return;
}


// ==== 0x452570 AIActionAccidentRecovery::AIActionAccidentRecovery

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall
AIActionAccidentRecovery__AIActionAccidentRecovery(undefined4 param_1,undefined4 param_2)

{
  undefined4 *unaff_ESI;
  
  AIAction__AIAction(0xe,param_1,param_2);
  *unaff_ESI = &PTR_FUN_006c934c;
  unaff_ESI[0x80] = 0;
  unaff_ESI[0x80] = DAT_0073ad34;
  *(undefined1 *)(unaff_ESI + 0x81) = 0;
  return;
}


// ==== 0x4525b0 AIActionAccidentRecovery::DoSnapshot

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall AIActionAccidentRecovery__DoSnapshot(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIActionAccidentRecovery");
  FUN_00571c20(param_2,param_1 + 0x200,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x204,1,1,0);
  AIAction__DoSnapshot(param_2);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10 + 0x4c + param_2;
  *(int *)(iVar1 + 0xc) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x452630 AIActionAccidentRecovery::CalculateScore

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 AIActionAccidentRecovery__CalculateScore(void)

{
  int *in_EAX;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  if (*(int *)(*in_EAX + 0x3cc) < 2) {
    bNormalize3();
    if ((local_1c + local_20) * 0.0 + local_18 <= 0.707) {
      return 500;
    }
  }
  return 0xffffffff;
}


// ==== 0x452690 AIActionAccidentRecovery::SortOfParallelToTrack

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

short AIActionAccidentRecovery__SortOfParallelToTrack(float param_1)

{
  float fVar1;
  byte bVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  bNormalize3();
  fVar1 = (local_1c + local_20) * 0.0 + local_18;
  bVar2 = fVar1 < param_1 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(param_1)) << 10) >> 8) |
          (byte)((ushort)((ushort)(fVar1 == param_1) << 0xe) >> 8);
  if (fVar1 >= param_1 && (fVar1 == param_1) == 0) {
    return CONCAT11(bVar2,1);
  }
  return (ushort)bVar2 << 8;
}


// ==== 0x4526d0 AIActionAccidentRecovery::HasBeenAccomplished

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 __thiscall AIActionAccidentRecovery__HasBeenAccomplished(int param_1,int *param_2)

{
  char cVar1;
  
  if (*(char *)(param_1 + 0x204) != '\0') {
    return 1;
  }
  if ((*(int *)(*param_2 + 0x3cc) == 4) &&
     (cVar1 = AIActionAccidentRecovery__SortOfParallelToTrack(0x3f34fdf4), cVar1 != '\0')) {
    return 1;
  }
  return 0;
}


// ==== 0x452710 AIActionAccidentRecovery::CalculatePointsToDrive

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall AIActionAccidentRecovery__CalculatePointsToDrive(int param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = param_2 + 0xe6;
  if (*piVar1 != 1) {
    *piVar1 = 1;
    param_2[0xe7] = 0;
    *(undefined1 *)(param_2 + 0xe9) = 0;
    param_2[0xe8] = 0;
  }
  FUN_0045ae10(piVar1,param_1 + 0x20,param_2,0,2);
  *(undefined1 *)(param_1 + 0x1f0) = 0;
  *(undefined4 *)(param_1 + 0x1e4) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  *(undefined1 *)(param_1 + 0x1f1) = 0;
  if ((5.0 <= (float)(DAT_0073ad34 - *(int *)(param_1 + 0x200)) * 0.00025) &&
     (*(char *)(param_1 + 0x204) == '\0')) {
    if ((DAT_0078a368 == 0) || (*(int *)(*(int *)(*param_2 + 0x14) + 4) != 2)) {
      *(undefined4 *)(*param_2 + 0x87c) = 1;
    }
    *(undefined1 *)(param_1 + 0x204) = 1;
  }
  return;
}


// ==== 0x4527d0 AIActionDriveTrafficLane::AIActionDriveTrafficLane

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall
AIActionDriveTrafficLane__AIActionDriveTrafficLane(undefined4 param_1,undefined4 param_2)

{
  undefined4 *unaff_ESI;
  
  AIAction__AIAction(8,param_1,param_2);
  *unaff_ESI = &PTR_FUN_006c920c;
  unaff_ESI[0x80] = 0;
  unaff_ESI[0x80] = 0;
  return;
}


// ==== 0x452800 AIActionDriveTrafficLane::DoSnapshot

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall AIActionDriveTrafficLane__DoSnapshot(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIActionDriveTrafficLane");
  FUN_00571c20(param_2,param_1 + 0x200,4,0xffffffff,0);
  AIAction__DoSnapshot(param_2);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x452870 AIActionDriveTrafficLane::HasExpired

/* [canon] rivals med (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 __fastcall AIActionDriveTrafficLane__HasExpired(int param_1)

{
  if ((*(float *)(param_1 + 0xc) < (float)(DAT_0073ad34 - *(int *)(param_1 + 8)) * 0.00025) &&
     (*(char *)(param_1 + 4) != '\0')) {
    return 1;
  }
  return 0;
}


// ==== 0x4528b0 AIActionDriveTrafficLane::CalculatePointsToDrive

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall AIActionDriveTrafficLane__CalculatePointsToDrive(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  float10 fVar4;
  
  iVar1 = *param_2;
  piVar2 = *(int **)(iVar1 + 0x2c);
  if ((3.0 <= (float)(DAT_0073ad34 - *(int *)(param_1 + 0x200)) * 0.00025) ||
     (((iVar3 = param_2[0xe6], 1 < iVar3 && (iVar3 < 4)) || (iVar3 == 0)))) {
    *(int *)(param_1 + 0x200) = DAT_0073ad34;
    FUN_0045cff0(param_1 + 0x20,param_2,DAT_007006ec);
  }
  else {
    FUN_0045ae10(param_2 + 0xe6,param_1 + 0x20,param_2,0,0);
  }
  *(undefined1 *)(param_1 + 0x1f0) = 0;
  fVar4 = (float10)(**(code **)(*piVar2 + 0x5c))();
  *(float *)(param_1 + 0x1e4) = (float)fVar4;
  if (((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) && (*(int *)(*(int *)(iVar1 + 0x14) + 4) == 2)
     ) {
    AIAction__MaybeUseNitrous(param_1);
  }
  *(undefined4 *)(param_1 + 0x1ec) = 0x40000000;
  *(undefined1 *)(param_1 + 0x1f1) = 1;
  *(undefined1 *)(param_1 + 0x1f2) = 1;
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  return;
}


// ==== 0x452990 AIActionAvoidCrossTraffic::AIActionAvoidCrossTraffic

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 * __thiscall
AIActionAvoidCrossTraffic__AIActionAvoidCrossTraffic
          (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
          float param_5)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686048;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  AIAction__AIAction(2,param_1,param_3);
  *param_2 = &PTR_FUN_006c911c;
  iVar2 = 0;
  param_2[0x84] = 0;
  param_2[0x85] = param_5 + 2.0;
  param_2[0x80] = unaff_EDI;
  param_2[0x81] = param_5;
  param_2[0x83] = param_4;
  param_2[0x84] = DAT_0073ad34;
  local_4 = 0;
  iVar1 = FUN_00647b70();
  if ((iVar1 == 6) &&
     (*(int *)(*(int *)(*(int *)(*(int *)(unaff_EDI + 0x1d4) + 0x90) + 0x14) + 4) == 3)) {
    iVar1 = FUN_00647b70();
    if (iVar1 == 6) {
      iVar2 = *(int *)(*(int *)(*(int *)(unaff_EDI + 0x1d4) + 0x90) + 0x2c);
    }
    param_2[0x82] = *(undefined4 *)(iVar2 + 0x4e0);
  }
  else {
    param_2[0x82] = 0;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== 0x452a80 AIActionAvoidCrossTraffic::DoSnapshot

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall AIActionAvoidCrossTraffic__DoSnapshot(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIActionAvoidCrossTraffic");
  AIAction__DoSnapshot(param_2);
  FUN_00571c20(param_2,param_1 + 0x204,4,0xffffffff,0);
  FUN_005aaf90();
  FUN_00571c20(param_2,param_1 + 0x20c,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x214,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x210,4,0xffffffff,0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x452b40 AIActionAvoidCrossTraffic::CalculateScore

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 AIActionAvoidCrossTraffic__CalculateScore(undefined4 *param_1)

{
  undefined4 uVar1;
  char cVar2;
  int *in_EAX;
  int iVar3;
  int iVar4;
  int *unaff_EDI;
  undefined4 local_4;
  
  uVar1 = DAT_007006ec;
  *unaff_EDI = 0;
  local_4 = 0;
  iVar3 = FUN_00457590(&DAT_0077a4ac,*(int *)(*in_EAX + 0x30) + 0x10,in_EAX + 0xe3,uVar1,&local_4);
  if (iVar3 != 0) {
    if ((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) {
LAB_00452bd2:
      *unaff_EDI = iVar3;
      *param_1 = local_4;
      return 400;
    }
    iVar4 = FUN_00647b70();
    if ((iVar4 == 6) &&
       (*(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 0x1d4) + 0x90) + 0x14) + 4) == 3)) {
      iVar4 = FUN_0057a680();
      cVar2 = (**(code **)(**(int **)(*(int *)(iVar4 + 0x2c) + 0x3fc) + 0xc))();
      if (cVar2 != '\0') goto LAB_00452bd2;
    }
  }
  return 0xffffffff;
}


// ==== 0x452bf0 AIActionAvoidCrossTraffic::HasBeenAccomplished

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 __thiscall AIActionAvoidCrossTraffic__HasBeenAccomplished(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float10 fVar8;
  undefined4 uStack_4;
  
  piVar3 = param_2;
  iVar2 = param_2[0xe2];
  uStack_4 = 0x47c34f80;
  iVar5 = FUN_00457590(&DAT_0077a4ac,*(int *)(*param_2 + 0x30) + 0x10,param_2 + 0xe3,DAT_007006ec,
                       &uStack_4);
  if (((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) && (*(int *)(param_1 + 0x208) != 0)) {
    iVar1 = param_2[(char)iVar2 * 0xe + 0xf];
    iVar6 = FUN_00647b70();
    if (iVar6 == 4) {
      param_2 = *(int **)(*(int *)(iVar1 + 0x1d0) + 0x14);
    }
    else {
      fVar7 = (float10)(**(code **)(**(int **)(iVar1 + 0x1d4) + 0x24))();
      param_2 = (int *)(float)fVar7;
    }
    fVar7 = (float10)FUN_005ab160(param_2);
    fVar7 = (float10)TrackPath__WrapDistance((float)fVar7,param_2);
    fVar8 = (float10)FUN_005ab1b0();
    if (-(fVar8 + (float10)(float)piVar3[(char)iVar2 * 0xe + 5]) <= (float10)(float)fVar7) {
LAB_00452ceb:
      if (iVar5 != 0) {
        *(int *)(param_1 + 0x200) = iVar5;
        *(undefined4 *)(param_1 + 0x204) = uStack_4;
      }
      return 0;
    }
  }
  else if (iVar5 != 0) {
    cVar4 = TrafficCar_IsIntersectionObstacle(iVar5);
    if (cVar4 != '\0') goto LAB_00452ceb;
  }
  return 1;
}


// ==== 0x452d10 FUN_00452d10

undefined1 FUN_00452d10(void)

{
  return 0;
}


// ==== 0x452d20 AIActionAvoidCrossTraffic::CalculatePointsToDrive

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall AIActionAvoidCrossTraffic__CalculatePointsToDrive(int param_1,int *param_2)

{
  float fVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  float10 fVar6;
  float local_4c;
  float local_48;
  int *local_44;
  float *local_40;
  float local_3c;
  undefined4 *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  undefined4 local_14;
  
  local_44 = param_2 + 0xe6;
  local_38 = (undefined4 *)*param_2;
  piVar2 = (int *)local_38[0xb];
  iVar4 = 0;
  if (0 < param_2[1]) {
    piVar5 = param_2 + 0xf;
    do {
      if (*piVar5 == *(int *)(param_1 + 0x200)) {
        if ((iVar4 != -1) &&
           (local_40 = (float *)(param_2 + iVar4 * 0xe + 2), local_40 != (float *)0x0)) {
          local_4c = (float)CONCAT31(local_4c._1_3_,1);
          if (*local_40 <= 0.0) {
            local_4c = (float)((uint)local_4c._1_3_ << 8);
          }
          if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
            cVar3 = FUN_0045d250(local_44,DAT_007006ec,local_4c);
          }
          else {
            cVar3 = FUN_0045d130(param_1 + 0x20,DAT_007006ec,local_4c);
          }
          if (cVar3 != '\0') goto LAB_00452d8c;
          if (ABS(*(float *)(param_1 + 0x204)) < 0.001 ==
              (ABS(*(float *)(param_1 + 0x204)) == 0.001)) {
            local_3c = local_40[1];
            local_48 = local_40[4] - (float)param_2[(char)param_2[0xe2] * 0xe + 6];
            local_40 = (float *)*local_40;
            fVar6 = (float10)Car__GetForwardAcceleration();
            if ((fVar6 * (float10)*(float *)(param_1 + 0x204) * (float10)_K_HALF + (float10)local_3c
                ) * (float10)*(float *)(param_1 + 0x204) + (float10)local_48 <= (float10)3.0) {
              fVar6 = (float10)(**(code **)(*piVar2 + 0x5c))();
              *(float *)(param_1 + 0x1e4) = (float)(fVar6 + fVar6);
              *(undefined4 *)(param_1 + 0x1ec) = 0;
              *(undefined4 *)(param_1 + 0x1e8) = 0;
              AIAction__MaybeUseNitrous(param_1);
              goto LAB_00452dad;
            }
          }
          else if (local_40[4] - (float)param_2[(char)param_2[0xe2] * 0xe + 6] <= 0.0)
          goto LAB_00452d8c;
          local_28 = *(float *)(param_1 + 0x20c) * 0.33333334;
          local_20 = *(undefined4 *)(param_1 + 0x20c);
          local_30 = 0;
          local_18 = *(float *)(param_1 + 0x20c) + 0.001;
          local_1c = 0x3f7fbe77;
          local_24 = 0x3f666666;
          local_38 = &local_30;
          local_2c = 0;
          local_14 = 0x3f800000;
          local_34 = 4;
          Curve_Evaluate(&local_4c,*(undefined4 *)(param_1 + 0x204));
          if (_K_ONE <= local_4c) {
            fVar6 = (float10)(**(code **)(*piVar2 + 0x5c))();
            *(float *)(param_1 + 0x1e4) = (float)fVar6;
            *(undefined4 *)(param_1 + 0x1ec) = 0x40000000;
          }
          else {
            *(float *)(param_1 + 0x1e4) = *(float *)(*param_2 + 0x3d4) * local_4c;
            *(float *)(param_1 + 0x1ec) = local_4c + local_4c;
          }
          *(undefined4 *)(param_1 + 0x1e8) = 0;
          *(undefined1 *)(*param_2 + 0x88c) = 0;
          fVar1 = *(float *)(param_1 + 0x1e4);
          if (fVar1 <= 20.0) {
            fVar1 = 20.0;
          }
          *(float *)(param_1 + 0x1e4) = fVar1;
          goto LAB_00452db6;
        }
        break;
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 0xe;
    } while (iVar4 < param_2[1]);
  }
  FUN_0045c370(param_1 + 0x20,param_2,0,0,0,0x47c34f80);
LAB_00452d8c:
  fVar6 = (float10)(**(code **)(*piVar2 + 0x5c))();
  *(float *)(param_1 + 0x1e4) = (float)fVar6;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0x40000000;
LAB_00452dad:
  *(undefined1 *)(*param_2 + 0x88c) = 0;
LAB_00452db6:
  if ((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) {
    FUN_0045cff0(param_1 + 0x20,param_2,DAT_007006ec);
  }
  *(undefined1 *)(param_1 + 0x1f0) = 0;
  *(undefined1 *)(param_1 + 0x1f1) = 1;
  *(undefined1 *)(param_1 + 0x1f2) = 1;
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  return;
}


// ==== 0x453060 AIActionAvoidCrossTraffic::CleanUp

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void AIActionAvoidCrossTraffic__CleanUp(int *param_1)

{
  param_1[0xe6] = 1;
  param_1[0xe7] = 0;
  *(undefined1 *)(param_1 + 0xe9) = 0;
  param_1[0xe8] = 0;
  *(undefined1 *)(*param_1 + 0x88c) = 0;
  return;
}


// ==== 0x453090 AIActionIJustGotHitDragRace::AIActionIJustGotHitDragRace

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall
AIActionIJustGotHitDragRace__AIActionIJustGotHitDragRace
          (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *unaff_ESI;
  
  AIAction__AIAction(0xd,param_1,param_2);
  *unaff_ESI = &PTR_FUN_006c92fc;
  unaff_ESI[0x80] = param_3;
  return;
}


// ==== 0x4530c0 AIActionIJustGotHitDragRace::DoSnapshot

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void AIActionIJustGotHitDragRace__DoSnapshot(int param_1)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIActionIJustGotHitDragRace");
  AIAction__DoSnapshot(param_1);
  iVar1 = *(char *)(param_1 + 0x40) * 0x10;
  *(int *)(iVar1 + param_1 + 0x58) = *(int *)(param_1 + 0x150) - *(int *)(iVar1 + 0x58 + param_1);
  cVar2 = *(char *)(param_1 + 0x40) + -1;
  *(char *)(param_1 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_1 + 0x44)) {
    *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x453120 AIActionIJustGotHitDragRace::CalculatePointsToDrive

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall AIActionIJustGotHitDragRace__CalculatePointsToDrive(int param_1,int *param_2)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  bool bVar5;
  char cVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int extraout_EDX;
  float10 fVar12;
  
  iVar10 = *param_2;
  piVar11 = (int *)param_2[0xea];
  piVar1 = param_2 + 0xe6;
  piVar4 = *(int **)(iVar10 + 0x2c);
  if (*(int *)(iVar10 + 0x24) == 2) {
    piVar4[0x141] = 0xff;
    piVar4[0x142] = 0xff;
  }
  uVar7 = (**(code **)(*piVar11 + 4))();
  iVar8 = (int)(char)param_2[0xe2];
  iVar9 = 0;
  if (0 < param_2[1]) {
    piVar11 = param_2 + 0xf;
    do {
      if (*piVar11 == *(int *)(param_1 + 0x200)) break;
      iVar9 = iVar9 + 1;
      piVar11 = piVar11 + 0xe;
    } while (iVar9 < param_2[1]);
  }
  iVar9 = GetNearestTrafficLane(iVar10,uVar7,0xff,0xff);
  if (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x200) + 0x1d4) + 0x1c) + 0xe4) != 0) {
    FUN_005791c0();
  }
  iVar10 = GetNearestTrafficLane(iVar10,uVar7,0xff,0xff);
  if ((iVar9 == -1) || (iVar10 == -1)) {
    if (*piVar1 == 0) {
      *piVar1 = 1;
      param_2[0xe7] = 0;
      *(undefined1 *)(param_2 + 0xe9) = 0;
      param_2[0xe8] = 0;
    }
    goto LAB_0045340f;
  }
  fVar12 = (float10)FUN_0057b480();
  if (iVar9 == iVar10) {
    if ((iVar9 < 0) || (4 < iVar9)) {
      if ((iVar9 < 0xb) || (0x10 < iVar9)) {
        fVar2 = 0.0;
      }
      else {
        fVar2 = (float)param_2[iVar8 * 0xe + iVar9 + -3];
      }
    }
    else {
      fVar2 = (float)param_2[iVar8 * 0xe + 7];
    }
    if ((iVar9 < 0) || (4 < iVar9)) {
      if ((iVar9 < 0xb) || (0x10 < iVar9)) {
        fVar3 = 0.0;
      }
      else {
        fVar3 = *(float *)(extraout_EDX + -0x14 + iVar9 * 4);
      }
    }
    else {
      fVar3 = *(float *)(extraout_EDX + 0x14);
    }
    if (((float)param_2[iVar8 * 0xe + 4] <= ABS(fVar2)) ||
       (*(float *)(extraout_EDX + 8) <= ABS(fVar3))) {
      if (ABS(fVar3) <= ABS(fVar2)) goto LAB_0045337c;
      bVar5 = false;
    }
    else if (0.0 <= *(float *)(extraout_EDX + 0x10) - (float)param_2[(char)param_2[0xe2] * 0xe + 6])
    {
LAB_0045337c:
      bVar5 = true;
    }
    else {
      bVar5 = false;
    }
    cVar6 = FUN_005a7700(iVar9,*param_2);
    if ((cVar6 != '\0') && (!bVar5)) goto LAB_004533d4;
    iVar10 = iVar9 + -1;
    if ((float)fVar12 < 0.0) {
      iVar10 = iVar9 + 1;
    }
    cVar6 = FUN_005a7700(iVar9,*param_2);
    if (cVar6 == '\0') goto LAB_004533d4;
  }
  else {
LAB_004533d4:
    iVar10 = iVar9;
  }
  param_2[0xe5] = iVar10;
  *piVar1 = 1;
  param_2[0xe7] = 0;
  *(undefined1 *)(param_2 + 0xe9) = 0;
  param_2[0xe8] = 0;
LAB_0045340f:
  FUN_0045ae10(piVar1,param_1 + 0x20,param_2,0,0);
  fVar12 = (float10)(**(code **)(*piVar4 + 0x5c))();
  *(float *)(param_1 + 0x1e4) = (float)fVar12;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined1 *)(param_1 + 0x1f0) = 0;
  *(undefined1 *)(param_1 + 0x1f1) = 1;
  *(undefined1 *)(param_1 + 0x1f2) = 1;
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  return;
}


// ==== 0x453470 AIActionHitWallDragRace::AIActionHitWallDragRace

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall
AIActionHitWallDragRace__AIActionHitWallDragRace(undefined4 param_1,undefined4 param_2)

{
  undefined4 *unaff_ESI;
  
  AIAction__AIAction(0x10,param_1,param_2);
  *unaff_ESI = &PTR_FUN_006c9194;
  return;
}


// ==== 0x453490 AIActionHitWallDragRace::DoSnapshot

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void AIActionHitWallDragRace__DoSnapshot(int param_1)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIActionHitWallDragRace");
  AIAction__DoSnapshot(param_1);
  iVar1 = *(char *)(param_1 + 0x40) * 0x10;
  *(int *)(iVar1 + param_1 + 0x58) = *(int *)(param_1 + 0x150) - *(int *)(iVar1 + 0x58 + param_1);
  cVar2 = *(char *)(param_1 + 0x40) + -1;
  *(char *)(param_1 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_1 + 0x44)) {
    *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x4534f0 AIActionHitWallDragRace::CalculateScore

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 AIActionHitWallDragRace__CalculateScore(void)

{
  int iVar1;
  bool bVar2;
  int *in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = (int)*(char *)(*(int *)(*in_EAX + 0x3c) + 0x1c);
  bVar2 = false;
  iVar5 = 0;
  if (0 < iVar4) {
    do {
      if (bVar2) {
        return 300;
      }
      iVar3 = CollisionBody__GetCollision(iVar5);
      iVar1 = *(int *)(*(int *)(iVar3 + 100) + 600);
      if (((*(char *)(iVar1 + 0x15) == '\x03') &&
          (ABS(*(float *)(*(int *)(iVar1 + 0x60) + 0x78)) < 0.1)) ||
         ((iVar1 = *(int *)(*(int *)(iVar3 + 100) + 0x25c), *(char *)(iVar1 + 0x15) == '\x03' &&
          (ABS(*(float *)(*(int *)(iVar1 + 0x60) + 0x78)) < 0.1)))) {
        bVar2 = true;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar4);
    if (bVar2) {
      return 300;
    }
  }
  return 0xffffffff;
}


// ==== 0x453580 AIActionHitWallDragRace::HasBeenAccomplished

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

bool AIActionHitWallDragRace__HasBeenAccomplished(int *param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = (int)*(char *)(*(int *)(*param_1 + 0x3c) + 0x1c);
  iVar5 = 0;
  bVar2 = true;
  if (0 < iVar4) {
    do {
      if (!bVar2) {
        return bVar2;
      }
      iVar3 = CollisionBody__GetCollision(iVar5);
      iVar1 = *(int *)(*(int *)(iVar3 + 100) + 600);
      if (((*(char *)(iVar1 + 0x15) == '\x03') &&
          (ABS(*(float *)(*(int *)(iVar1 + 0x60) + 0x78)) < 0.1)) ||
         ((iVar1 = *(int *)(*(int *)(iVar3 + 100) + 0x25c), *(char *)(iVar1 + 0x15) == '\x03' &&
          (ABS(*(float *)(*(int *)(iVar1 + 0x60) + 0x78)) < 0.1)))) {
        bVar2 = false;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar4);
  }
  return bVar2;
}


// ==== 0x453600 AIActionHitWallDragRace::CalculatePointsToDrive

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall AIActionHitWallDragRace__CalculatePointsToDrive(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  float10 fVar5;
  
  iVar4 = *param_2;
  piVar2 = *(int **)(iVar4 + 0x2c);
  piVar1 = param_2 + 0xe6;
  uVar3 = (**(code **)(*(int *)param_2[0xea] + 4))();
  if (*(int *)(iVar4 + 0x24) == 2) {
    piVar2[0x141] = 0xff;
    piVar2[0x142] = 0xff;
  }
  iVar4 = GetNearestTrafficLane(iVar4,uVar3,0xff,0xff);
  if (iVar4 == -1) {
    if (*piVar1 != 0) goto LAB_004536da;
  }
  else {
    param_2[0xe5] = iVar4;
  }
  *piVar1 = 1;
  param_2[0xe7] = 0;
  *(undefined1 *)(param_2 + 0xe9) = 0;
  param_2[0xe8] = 0;
LAB_004536da:
  FUN_0045ae10(piVar1,param_1 + 0x20,param_2,0,0);
  fVar5 = (float10)(**(code **)(*piVar2 + 0x5c))();
  *(float *)(param_1 + 0x1e4) = (float)fVar5;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined1 *)(param_1 + 0x1f0) = 0;
  *(undefined1 *)(param_1 + 0x1f1) = 1;
  *(undefined1 *)(param_1 + 0x1f2) = 1;
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  return;
}


// ==== 0x453730 AIActionEndOfRace::AIActionEndOfRace

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall AIActionEndOfRace__AIActionEndOfRace(undefined4 param_1,undefined4 param_2)

{
  undefined4 *unaff_ESI;
  
  AIAction__AIAction(0x11,param_1,param_2);
  *unaff_ESI = &PTR_FUN_006c92d4;
  unaff_ESI[0x80] = 0;
  return;
}


// ==== 0x453760 AIActionEndOfRace::DoSnapshot

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall AIActionEndOfRace__DoSnapshot(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIActionEndOfRace");
  FUN_00571c20(param_2,param_1 + 0x200,4,0xffffffff,0);
  AIAction__DoSnapshot(param_2);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x4537d0 AIActionEndOfRace::CalculatePointsToDrive

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall AIActionEndOfRace__CalculatePointsToDrive(uint param_1,int param_2)

{
  undefined4 uStack_4;
  
  uStack_4 = param_1 & 0xffffff;
  FUN_0045b150(param_2 + 0x398,param_1 + 0x20,param_2,0x40000000,(int)&uStack_4 + 3,1);
  *(undefined4 *)(param_1 + 0x1e4) = 0;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined1 *)(param_1 + 0x1f0) = 0;
  *(undefined1 *)(param_1 + 0x1f1) = 1;
  *(undefined1 *)(param_1 + 0x1f2) = 1;
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  return;
}


// ==== 0x453830 AIActionEndOfRace::CleanUp

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void AIActionEndOfRace__CleanUp(int *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*param_1 + 0x30);
  *(undefined4 *)(iVar1 + 0x21c) = 0xbf800000;
  *(undefined4 *)(iVar1 + 0x210) = 0xbf800000;
  *(undefined1 *)(iVar1 + 0x220) = 0;
  *(undefined1 *)(*param_1 + 0x88c) = 0;
  return;
}


// ==== 0x453860 AIActionAvoidAvoidableAsTraffic::AIActionAvoidAvoidableAsTraffic

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall
AIActionAvoidAvoidableAsTraffic__AIActionAvoidAvoidableAsTraffic
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *unaff_ESI;
  
  AIAction__AIAction(3,param_1,param_2);
  unaff_ESI[0x81] = param_4;
  *unaff_ESI = &PTR_FUN_006c939c;
  unaff_ESI[0x80] = param_3;
  unaff_ESI[0x82] = 0x41f00000;
  return;
}


// ==== 0x4538a0 FUN_004538a0

void __thiscall FUN_004538a0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIActionAvoidAvoidableAsTraffic");
  AIAction__DoSnapshot(param_2);
  FUN_00571c20(param_2,param_1 + 0x204,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x208,4,0xffffffff,0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x453920 Finder_AvoidAsTraffic

/* [canon] traffic med (H) docs/re/traffic.md */

undefined4 Finder_AvoidAsTraffic(int *param_1,float *param_2,undefined4 *param_3)

{
  bool bVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int *unaff_ESI;
  float10 fVar6;
  float local_8;
  undefined4 local_4;
  
  piVar2 = param_1;
  *param_1 = 0;
  iVar5 = *(int *)(*unaff_ESI + 0x2c);
  iVar4 = unaff_ESI[0xe5];
  local_8 = 0.0;
  local_4 = 0;
  if ((iVar4 < 0) || (4 < iVar4)) {
    if ((iVar4 < 0xb) || (0x10 < iVar4)) {
      param_1 = (int *)0x0;
    }
    else {
      param_1 = (int *)unaff_ESI[(char)unaff_ESI[0xe2] * 0xe + iVar4 + -3];
    }
  }
  else {
    param_1 = (int *)unaff_ESI[(char)unaff_ESI[0xe2] * 0xe + 7];
  }
  iVar4 = AIAction__IsSomeoneAheadInThisLane(iVar4,param_1,0x47c34f80,&local_8,&local_4);
  cVar3 = (**(code **)(**(int **)(iVar5 + 0x3fc) + 0xc))();
  if ((cVar3 != '\0') && (iVar4 != 0)) {
    iVar5 = FUN_00647b70();
    if ((iVar5 == 6) && (*(int *)(*(int *)(*(int *)(iVar4 + 0x1d4) + 0x90) + 0x1c) != 0)) {
      fVar6 = (float10)FUN_0044d5f0();
      if ((float10)20.0 < fVar6) {
        bVar1 = true;
        goto LAB_00453a01;
      }
    }
  }
  bVar1 = false;
LAB_00453a01:
  if (((iVar4 != 0) && (!bVar1)) && (local_8 < 5.0 != (local_8 == 5.0))) {
    cVar3 = TrafficCar_IsIntersectionObstacle(iVar4);
    if (cVar3 != '\0') {
      *piVar2 = iVar4;
      *param_2 = local_8;
      *param_3 = local_4;
      return 300;
    }
  }
  return 0xffffffff;
}


// ==== 0x453a60 FUN_00453a60

char __thiscall FUN_00453a60(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  float fStack_4;
  
  iVar3 = 0;
  fStack_4 = 0.0;
  if (0 < *(int *)(param_2 + 4)) {
    piVar4 = (int *)(param_2 + 0x3c);
    do {
      if (*piVar4 == *(int *)(param_1 + 0x200)) {
        if (iVar3 == -1) {
          return '\x01';
        }
        iVar3 = iVar3 * 0x38 + 8 + param_2;
        if (iVar3 == 0) {
          return '\x01';
        }
        iVar1 = *(char *)(param_2 + 0x388) * 0x38 + param_2;
        if ((0.0 <= *(float *)(iVar3 + 0x10) - *(float *)(iVar1 + 0x18)) &&
           (*(float *)(iVar3 + 4) <= 5.0)) {
          return '\0';
        }
        iVar3 = *(int *)(param_2 + 0x394);
        if ((iVar3 < 0) || (4 < iVar3)) {
          if ((iVar3 < 0xb) || (0x10 < iVar3)) {
            param_2 = 0;
          }
          else {
            param_2 = *(undefined4 *)(iVar1 + -0xc + iVar3 * 4);
          }
        }
        else {
          param_2 = *(undefined4 *)(iVar1 + 0x1c);
        }
        iVar3 = AIAction__IsSomeoneAheadInThisLane
                          (iVar3,param_2,*(undefined4 *)(param_1 + 0x208),&fStack_4,&param_2);
        if (iVar3 == 0) {
          return '\x01';
        }
        if (fStack_4 < 5.0 == (fStack_4 == 5.0)) {
          return '\x01';
        }
        cVar2 = TrafficCar_IsIntersectionObstacle(iVar3);
        cVar2 = '\x01' - (cVar2 != '\0');
        if ((cVar2 == '\0') && (*(int *)(param_1 + 0x200) != iVar3)) {
          *(int *)(param_1 + 0x200) = iVar3;
          *(undefined4 *)(param_1 + 0x208) = 0x41f00000;
          *(float *)(param_1 + 0x204) = fStack_4;
          return '\0';
        }
        return cVar2;
      }
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 0xe;
    } while (iVar3 < *(int *)(param_2 + 4));
  }
  return '\x01';
}


// ==== 0x453b80 FUN_00453b80

void __fastcall FUN_00453b80(undefined4 param_1,undefined4 param_2)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + 0x208) = param_2;
  *(undefined4 *)(unaff_EBP + 0x204) = param_1;
  return;
}


// ==== 0x453ba0 FUN_00453ba0

undefined4 __thiscall FUN_00453ba0(int param_1,int param_2)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  undefined4 *unaff_ESI;
  float local_8;
  undefined1 local_4 [4];
  
  if ((in_EAX != param_1) && (cVar1 = FUN_005a7700(in_EAX,*unaff_ESI), cVar1 == '\0')) {
    return 0;
  }
  local_8 = 0.0;
  iVar2 = AIAction__IsSomeoneAheadInThisLane
                    (param_1,0,*(undefined4 *)(param_2 + 0x208),&local_8,local_4);
  if ((((iVar2 != 0) && (cVar1 = TrafficCar_IsIntersectionObstacle(iVar2), cVar1 != '\0')) &&
      (local_8 < 5.0 != (local_8 == 5.0))) &&
     ((local_8 < *(float *)(param_2 + 0x204) != (local_8 == *(float *)(param_2 + 0x204)) ||
      (iVar2 == *(int *)(param_2 + 0x200))))) {
    return 0;
  }
  return 1;
}


// ==== 0x453c60 Action_AvoidAvoidableAsTraffic::Update

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] traffic med (H) docs/re/traffic.md */

void __thiscall Action_AvoidAvoidableAsTraffic__Update(int param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  float *pfVar8;
  float10 fVar9;
  float fStack_44;
  float fStack_40;
  int *piStack_3c;
  float fStack_38;
  int *piStack_34;
  int iStack_30;
  int *piStack_2c;
  int *piStack_28;
  float fStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  
  piStack_3c = param_2 + (char)param_2[0xe2] * 0xe;
  iVar2 = *param_2;
  piStack_28 = *(int **)(iVar2 + 0x2c);
  piStack_34 = param_2 + 0xe6;
  piStack_2c = (int *)param_2[0xea];
  iStack_30 = piStack_2c[piStack_3c[0xe] + 2];
  iVar5 = 0;
  if (0 < param_2[1]) {
    piVar7 = param_2 + 0xf;
    do {
      if (*piVar7 == *(int *)(param_1 + 0x200)) {
        if (iVar5 != -1) {
          pfVar8 = (float *)(param_2 + iVar5 * 0xe + 2);
          goto LAB_00453ccf;
        }
        break;
      }
      iVar5 = iVar5 + 1;
      piVar7 = piVar7 + 0xe;
    } while (iVar5 < param_2[1]);
  }
  pfVar8 = (float *)0x0;
LAB_00453ccf:
  fStack_38 = 0.0;
  bVar3 = false;
  if ((pfVar8 != (float *)0x0) && (-40.0 < pfVar8[1])) {
    fStack_38 = ((pfVar8[4] - (float)piStack_3c[6]) - pfVar8[3]) - (float)piStack_3c[5];
    if (fStack_38 <= 0.0) {
      fStack_38 = 0.0;
    }
    fVar1 = *pfVar8;
    fStack_40 = (float)param_2[0xe5];
    if (((int)fStack_40 < 0xb) || (0x10 < (int)fStack_40)) {
      uVar6 = (**(code **)(*piStack_2c + 4))(0xff,0xff);
      FUN_0044a2c0(uVar6);
      fStack_40 = (float)GetNearestTrafficLane(iVar2);
    }
    if (fVar1 <= 0.0) {
      iStack_20 = (int)fStack_40 + 1;
      iStack_1c = (int)fStack_40 + -1;
      iStack_18 = (int)fStack_40 + 2;
      iStack_14 = (int)fStack_40 + -2;
    }
    else {
      iStack_20 = (int)fStack_40 + -1;
      iStack_1c = (int)fStack_40 + 1;
      iStack_18 = (int)fStack_40 + -2;
      iStack_14 = (int)fStack_40 + 2;
    }
    fStack_44 = 0.0;
    fStack_24 = fStack_40;
    do {
      cVar4 = FUN_00453ba0(param_1);
      if (cVar4 != '\0') {
        if ((&fStack_24)[(int)fStack_44] != 3.57331e-43) {
          param_2[0xe5] = (int)(&fStack_24)[(int)fStack_44];
          *piStack_34 = 1;
          piStack_34[1] = 0;
          *(undefined1 *)(piStack_34 + 3) = 0;
          piStack_34[2] = 0;
          goto LAB_00453e05;
        }
        break;
      }
      fStack_44 = (float)((int)fStack_44 + 1);
    } while ((int)fStack_44 < 5);
    bVar3 = true;
  }
LAB_00453e05:
  iVar5 = param_2[0xe5];
  if ((iVar5 < 0) || (4 < iVar5)) {
    if ((iVar5 < 0xb) || (0x10 < iVar5)) {
      piStack_3c = (int *)0x0;
    }
    else {
      piStack_3c = (int *)piStack_3c[iVar5 + -3];
    }
  }
  else {
    piStack_3c = (int *)piStack_3c[7];
  }
  fStack_44 = 0.0;
  fStack_40 = 0.0;
  iVar5 = AIAction__IsSomeoneAheadInThisLane
                    (iVar5,piStack_3c,*(undefined4 *)(param_1 + 0x208),&fStack_40,&fStack_44);
  if (iVar5 == 0) {
    if (bVar3) goto LAB_00454051;
  }
  else {
    if (*(int *)(param_1 + 0x200) != iVar5) {
      *(int *)(param_1 + 0x200) = iVar5;
      *(undefined4 *)(param_1 + 0x208) = 0x41f00000;
    }
    *(float *)(param_1 + 0x204) = fStack_40;
    if (*(float *)(iVar2 + 0x3d4) < _K_HALF) {
      fVar1 = *(float *)(param_1 + 0x208);
      if (fVar1 <= 30.0) {
        fVar1 = 30.0;
      }
      if (fVar1 < fStack_44) {
        fVar1 = fStack_44;
      }
      *(float *)(param_1 + 0x208) = fVar1;
      cVar4 = *(char *)(iStack_30 + 0x5c);
      if ((cVar4 == -1) || (*(short *)(iStack_30 + 0x5e) == -1)) {
        iStack_30 = 0;
      }
      else {
        if (cVar4 < 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = (&DAT_0077af30)[cVar4];
        }
        iStack_30 = *(short *)(iStack_30 + 0x5e) * 0x88 + 0x27c + iVar5;
      }
      uVar6 = (**(code **)(*piStack_2c + 4))(0xff,0xff);
      iVar5 = GetNearestTrafficLane(iVar2,uVar6);
      if (iVar5 != -1) {
        param_2[0xe5] = iVar5;
        *piStack_34 = 1;
        piStack_34[1] = 0;
        *(undefined1 *)(piStack_34 + 3) = 0;
        piStack_34[2] = 0;
      }
    }
    if ((fStack_40 < 1.5) ||
       (fStack_38 < *(float *)(param_1 + 0x208) != (fStack_38 == *(float *)(param_1 + 0x208)))) {
LAB_00454051:
      piStack_2c = *(int **)(param_1 + 0x200);
      if (fStack_44 <= 15.0) {
        *(undefined4 *)(param_1 + 0x1e4) = 0;
        *(undefined4 *)(param_1 + 0x1ec) = 0;
        iVar5 = FUN_00647b70();
        if ((iVar5 == 6) && (*(int *)(*(int *)(*(int *)(piStack_2c[0x75] + 0x90) + 0x14) + 4) == 3))
        {
          *(undefined1 *)(iVar2 + 0x88c) = 1;
          *(undefined4 *)(iVar2 + 0x890) = 0x437f0000;
          *(undefined4 *)(iVar2 + 0x898) = 0;
          *(undefined4 *)(iVar2 + 0x894) = 0;
          *(undefined4 *)(iVar2 + 0x89c) = 0;
          *(undefined4 *)(param_1 + 0x1e8) = 0;
          goto LAB_00454009;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x1e4) = 0x40c00000;
        *(undefined4 *)(param_1 + 0x1ec) = 0x40000000;
        iVar5 = FUN_00647b70();
        if ((iVar5 == 6) && (*(int *)(*(int *)(*(int *)(piStack_2c[0x75] + 0x90) + 0x14) + 4) == 3))
        {
          *(undefined1 *)(iVar2 + 0x88c) = 1;
          *(undefined4 *)(iVar2 + 0x890) = 0;
          *(undefined4 *)(iVar2 + 0x898) = 0x437f0000;
          *(undefined4 *)(iVar2 + 0x894) = 0;
          *(undefined4 *)(iVar2 + 0x89c) = 0;
          *(undefined4 *)(param_1 + 0x1e8) = 0;
          goto LAB_00454009;
        }
      }
      *(undefined1 *)(iVar2 + 0x88c) = 0;
      *(undefined4 *)(param_1 + 0x1e8) = 0;
      goto LAB_00454009;
    }
  }
  fVar9 = (float10)(**(code **)(*piStack_28 + 0x5c))();
  *(float *)(param_1 + 0x1e4) = (float)fVar9;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0x40000000;
  *(undefined1 *)(iVar2 + 0x88c) = 1;
  *(undefined4 *)(iVar2 + 0x890) = 0;
  *(undefined4 *)(iVar2 + 0x894) = 0x437f0000;
  *(undefined4 *)(iVar2 + 0x898) = 0;
  *(undefined4 *)(iVar2 + 0x89c) = 0;
LAB_00454009:
  FUN_0045ae10(piStack_34,param_1 + 0x20,param_2,0,0);
  *(undefined1 *)(param_1 + 0x1f0) = 0;
  *(undefined1 *)(param_1 + 0x1f1) = 1;
  *(undefined1 *)(param_1 + 0x1f2) = 1;
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  return;
}


// ==== 0x454170 FUN_00454170

void __thiscall
FUN_00454170(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *unaff_ESI;
  
  AIAction__AIAction(0x12,param_1,param_2);
  unaff_ESI[0x82] = param_4;
  *unaff_ESI = &PTR_FUN_006c92ac;
  unaff_ESI[0x80] = param_3;
  *(undefined1 *)(unaff_ESI + 0x81) = 0;
  return;
}


// ==== 0x4541b0 FUN_004541b0

void __thiscall FUN_004541b0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIActionObeyTrafficIntersections");
  FUN_00571c20(param_2,param_1 + 0x204,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x208,1,4,1);
  TrafficIntersection_SavePtr();
  AIAction__DoSnapshot(param_2);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10 + 0x4c + param_2;
  *(int *)(iVar1 + 0xc) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x454200 FUN_00454200

void FUN_00454200(void)

{
  int iVar1;
  char cVar2;
  int unaff_ESI;
  
  iVar1 = *(char *)(unaff_ESI + 0x40) * 0x10 + 0x4c + unaff_ESI;
  *(int *)(iVar1 + 0xc) = *(int *)(unaff_ESI + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(unaff_ESI + 0x40) + -1;
  *(char *)(unaff_ESI + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(unaff_ESI + 0x44)) {
    *(undefined4 *)(unaff_ESI + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x454240 FUN_00454240

undefined4 FUN_00454240(void)

{
  int iVar1;
  int unaff_EBX;
  
  Node_GetIntersection();
  iVar1 = FUN_005a6ea0();
  if ((iVar1 != 0xff) && (*(int *)(unaff_EBX + 0x394) == iVar1)) {
    FUN_005a7340();
    FUN_005aad90();
    iVar1 = Section_HasLane();
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// ==== 0x454330 FUN_00454330

/* WARNING: Removing unreachable block (ram,0x0045438d) */

undefined4 FUN_00454330(void)

{
  uint uVar1;
  float fVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 local_8;
  
  local_8 = -1.0;
  cVar3 = FUN_00454240();
  if (cVar3 != '\0') {
    local_8 = -0.66999996;
  }
  uVar1 = *(uint *)(DAT_007361f8 + 0x2d0);
  uVar6 = uVar1 ^ 0x1d872b41;
  uVar4 = uVar6 >> 5 ^ uVar6;
  *(uint *)(DAT_007361f8 + 0x2d0) = uVar4 << 0x1b ^ uVar4 ^ uVar6;
  fVar2 = (float)(uVar1 % 0x7fffffff) * 4.656613e-10;
  if (-1.0 <= fVar2) {
    uVar5 = 3;
    if (local_8 <= fVar2) {
      uVar5 = 1;
    }
    return uVar5;
  }
  return 2;
}


// ==== 0x4543d0 Finder_ObeyIntersections

/* [canon] traffic high (G) docs/re/traffic.md */

undefined4 Finder_ObeyIntersections(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  undefined4 uVar3;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  iVar1 = *(int *)(in_EAX + 0x3a8);
  *unaff_EDI = 0;
  *unaff_ESI = 0;
  iVar2 = *(int *)(iVar1 + 0xb8);
  if ((iVar2 != -1) && (*(int *)(iVar1 + 8 + iVar2 * 4) != 0)) {
    uVar3 = Node_GetIntersection();
    *unaff_EDI = uVar3;
    uVar3 = FUN_00454330();
    *unaff_ESI = uVar3;
    return 600;
  }
  return 0xffffffff;
}


// ==== 0x454420 FUN_00454420

uint __thiscall FUN_00454420(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_2 + 0x3a8);
  if ((*(int *)(iVar1 + 0xb8) != -1) && (*(int *)(iVar1 + 8 + *(int *)(iVar1 + 0xb8) * 4) != 0)) {
    uVar2 = Node_GetIntersection();
    if (uVar2 != *(uint *)(param_1 + 0x200)) {
      *(undefined1 *)(param_1 + 0x204) = 0;
      *(uint *)(param_1 + 0x200) = uVar2;
      uVar2 = FUN_00454330();
      *(uint *)(param_1 + 0x208) = uVar2;
      return uVar2 & 0xffffff00;
    }
    return uVar2 & 0xffffff00;
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


// ==== 0x454449 FUN_00454449

undefined1 __fastcall FUN_00454449(int param_1,uint param_2)

{
  char *in_EAX;
  undefined4 uVar1;
  char *pcVar2;
  undefined1 unaff_BL;
  int unaff_ESI;
  undefined1 in_stack_00000010;
  
  pcVar2 = (char *)(param_2 & *(uint *)(param_1 + -0x79c40001));
  *pcVar2 = *pcVar2 + (char)in_EAX;
  *in_EAX = *in_EAX + (char)in_EAX;
  if (*in_EAX != '\0') {
    *(undefined1 *)(unaff_ESI + 0x204) = unaff_BL;
    *(char **)(unaff_ESI + 0x200) = in_EAX;
    uVar1 = FUN_00454330();
    *(undefined4 *)(unaff_ESI + 0x208) = uVar1;
    return in_stack_00000010;
  }
  return unaff_BL;
}


// ==== 0x45444f FUN_0045444f

undefined1 __fastcall FUN_0045444f(undefined4 param_1,char *param_2)

{
  char *in_EAX;
  undefined4 uVar1;
  undefined1 unaff_BL;
  int unaff_ESI;
  undefined1 in_stack_00000010;
  
  *param_2 = *param_2 + (char)in_EAX;
  *in_EAX = *in_EAX + (char)in_EAX;
  if (*in_EAX != '\0') {
    *(undefined1 *)(unaff_ESI + 0x204) = unaff_BL;
    *(char **)(unaff_ESI + 0x200) = in_EAX;
    uVar1 = FUN_00454330();
    *(undefined4 *)(unaff_ESI + 0x208) = uVar1;
    return in_stack_00000010;
  }
  return unaff_BL;
}


// ==== 0x454490 Action_ObeyTrafficIntersections::Update

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] traffic med (G) docs/re/traffic.md */

void __thiscall Action_ObeyTrafficIntersections__Update(int param_1,float *param_2)

{
  int *piVar1;
  float fVar2;
  bool bVar3;
  char cVar4;
  undefined4 *puVar5;
  int iVar6;
  float10 fVar7;
  int local_30;
  float fStack_24;
  float *local_20;
  int *local_1c;
  float fStack_18;
  float local_14;
  
  local_14 = *param_2;
  piVar1 = (int *)param_2[0xea];
  local_1c = *(int **)((int)local_14 + 0x2c);
  local_20 = param_2 + *(char *)(param_2 + 0xe2) * 0xe + 2;
  if (piVar1[0x2e] == -1) {
    local_30 = 0;
  }
  else {
    local_30 = piVar1[piVar1[0x2e] + 2];
  }
  puVar5 = (undefined4 *)Node_GetIntersection();
  fVar7 = (float10)(**(code **)(*local_1c + 0x5c))();
  *(float *)(param_1 + 0x1e4) = (float)fVar7;
  fVar2 = param_2[0xe5];
  if (((int)fVar2 < 0) || (4 < (int)fVar2)) {
    if (((int)fVar2 < 0xb) || (0x10 < (int)fVar2)) {
      fStack_24 = 0.0;
    }
    else {
      fStack_24 = local_20[(int)fVar2 + -5];
    }
  }
  else {
    fStack_24 = local_20[5];
  }
  fStack_18 = 0.0;
  local_20 = (float *)0x0;
  iVar6 = AIAction__IsSomeoneAheadInThisLane(fVar2,fStack_24,0x41f00000,&fStack_18,&local_20);
  if (((iVar6 != 0) && (cVar4 = TrafficCar_IsIntersectionObstacle(iVar6), cVar4 != '\0')) &&
     ((fStack_18 < 1.5 || ((float)local_20 < 30.0)))) {
    fVar2 = *(float *)(param_1 + 0x1e4);
    if ((float)local_20 <= 15.0) {
      if (0.0 <= fVar2) {
        fVar2 = 0.0;
      }
      *(undefined4 *)(param_1 + 0x1ec) = 0;
    }
    else {
      if (6.0 <= fVar2) {
        fVar2 = 6.0;
      }
      *(undefined4 *)(param_1 + 0x1ec) = 0x40000000;
    }
    *(float *)(param_1 + 0x1e4) = fVar2;
    fVar2 = *param_2;
    *(undefined1 *)((int)fVar2 + 0x88c) = 1;
    *(undefined4 *)((int)fVar2 + 0x890) = 0x437f0000;
    *(undefined4 *)((int)fVar2 + 0x894) = 0x43000000;
    *(undefined4 *)((int)fVar2 + 0x898) = 0;
    *(undefined4 *)((int)fVar2 + 0x89c) = 0;
  }
  bVar3 = false;
  if (*(char *)(param_1 + 0x204) == '\0') {
    fStack_18 = (float)(int)*(char *)(local_30 + 0x5c);
    (**(code **)(*piVar1 + 4))();
    switch(*puVar5) {
    case 2:
      if (fStack_18 == (float)(int)*(char *)((int)puVar5 + 5)) goto switchD_00454665_caseD_3;
      break;
    case 3:
switchD_00454665_caseD_3:
      fVar2 = *param_2;
      *(undefined1 *)((int)fVar2 + 0x88c) = 1;
      bVar3 = true;
      *(undefined4 *)((int)fVar2 + 0x890) = 0;
      *(undefined4 *)((int)fVar2 + 0x894) = 0;
      *(undefined4 *)((int)fVar2 + 0x898) = 0x437f0000;
      *(undefined4 *)((int)fVar2 + 0x89c) = 0;
      goto LAB_0045476f;
    }
  }
  fStack_18 = (float)(int)*(char *)(local_30 + 0x5c);
  local_20 = (float *)(**(code **)(*piVar1 + 4))();
  iVar6 = 0;
  do {
    if ((float)(int)*(char *)((int)puVar5 + iVar6 + 4) == fStack_18) {
      if ((iVar6 != -1) && (cVar4 = FUN_005aaca0(local_20), cVar4 != '\0')) {
        iVar6 = 0;
        goto LAB_00454740;
      }
      break;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 2);
  fVar2 = *param_2;
  *(undefined1 *)((int)fVar2 + 0x88c) = 1;
  bVar3 = true;
  *(undefined4 *)((int)fVar2 + 0x890) = 0x437f0000;
  *(undefined4 *)((int)fVar2 + 0x894) = 0;
  *(undefined4 *)((int)fVar2 + 0x898) = 0;
  *(undefined4 *)((int)fVar2 + 0x89c) = 0;
LAB_0045476f:
  fVar7 = (float10)FUN_005a6e10(piVar1,param_2 + *(char *)(param_2 + 0xe2) * 0xe + 2);
  fStack_18 = (float)fVar7;
  if (bVar3) {
    if (fStack_18 <= 30.0) {
      fVar7 = (float10)*(float *)(param_1 + 0x1e4);
      if ((float10)6.0 <= fVar7) {
        fVar7 = (float10)6.0;
      }
    }
    else {
      fVar7 = (float10)(**(code **)(*local_1c + 0x5c))();
      local_1c = *(int **)(param_1 + 0x1e4);
      if ((float10)(float)local_1c < fVar7) {
        fVar7 = (float10)(float)local_1c;
      }
    }
    *(float *)(param_1 + 0x1e4) = (float)fVar7;
    if (fStack_18 < 0.0) {
      fVar2 = *(float *)(param_1 + 0x1e4);
      if (0.0 <= fVar2) {
        fVar2 = 0.0;
      }
      *(float *)(param_1 + 0x1e4) = fVar2;
      if (*(float *)((int)local_14 + 0x3d4) < _K_HALF) {
        *(undefined1 *)(param_1 + 0x204) = 1;
      }
    }
  }
  else {
    fVar7 = (float10)(**(code **)(*local_1c + 0x5c))();
    local_14 = *(float *)(param_1 + 0x1e4);
    if ((float10)local_14 < fVar7) {
      fVar7 = (float10)local_14;
    }
    *(float *)(param_1 + 0x1e4) = (float)fVar7;
    fVar2 = *param_2;
    *(undefined1 *)((int)fVar2 + 0x88c) = 1;
    *(undefined4 *)((int)fVar2 + 0x890) = 0;
    *(undefined4 *)((int)fVar2 + 0x894) = 0x437f0000;
    *(undefined4 *)((int)fVar2 + 0x898) = 0;
    *(undefined4 *)((int)fVar2 + 0x89c) = 0;
  }
  if (param_2[0xe6] == 0.0) {
    param_2[0xe6] = 1.4013e-45;
    param_2[0xe7] = 0.0;
    *(undefined1 *)(param_2 + 0xe9) = 0;
    param_2[0xe8] = 0.0;
  }
  FUN_0045ae10(param_2 + 0xe6,param_1 + 0x20,param_2,0,0);
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0x3f800000;
  *(undefined1 *)(param_1 + 0x1f0) = 0;
  *(undefined1 *)(param_1 + 0x1f1) = 1;
  *(undefined1 *)(param_1 + 0x1f2) = 0;
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  return;
  while (iVar6 = iVar6 + 1, iVar6 < 2) {
LAB_00454740:
    if (*(char *)((int)puVar5 + iVar6 + 4) == *(char *)(local_30 + 0x5c)) {
      if ((iVar6 != -1) && (puVar5[3] != (uint)(iVar6 == 0))) {
        puVar5[3] = iVar6;
      }
      break;
    }
  }
  goto LAB_0045476f;
}


// ==== 0x454910 FUN_00454910

void FUN_00454910(int *param_1)

{
  *(undefined1 *)(*param_1 + 0x88c) = 0;
  *(undefined1 *)(*param_1 + 0x88c) = 0;
  return;
}


// ==== 0x454930 FUN_00454930

void __thiscall FUN_00454930(undefined4 param_1,undefined4 param_2)

{
  undefined4 *unaff_ESI;
  
  AIAction__AIAction(0x13,param_1,param_2);
  *unaff_ESI = &PTR_FUN_006c91e4;
  *(undefined1 *)(unaff_ESI + 0x80) = 0;
  return;
}


// ==== 0x454960 FUN_00454960

void __thiscall FUN_00454960(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIActionPickRouteToAvoidAnimation");
  AIAction__DoSnapshot(param_2);
  FUN_00571c20(param_2,param_1 + 0x200,1,1,0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x4549d0 FUN_004549d0

undefined4 FUN_004549d0(void)

{
  if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
    return 0;
  }
  return 1;
}


// ==== 0x4549f0 FUN_004549f0

void __fastcall FUN_004549f0(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x14))();
  if (cVar1 != '\0') {
    AIAction__GetNewTrafficLane();
    return;
  }
  AIAction__GetNewBestLine();
  return;
}


// ==== 0x454a20 FUN_00454a20

undefined1 FUN_00454a20(int param_1)

{
  int iVar1;
  float fVar2;
  undefined1 uVar3;
  int iVar4;
  int *unaff_EDI;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = *unaff_EDI;
  if (iVar1 != 0) {
    fVar5 = (float10)TrackPath__WrapDistance(unaff_EDI[1],*(undefined4 *)(param_1 + 0x814));
    if ((float10)0.0 < fVar5) {
      fVar6 = (float10)FUN_004570d0((float)fVar5);
      iVar4 = iVar1;
      if ((*(int *)(iVar1 + 0xc) == 0x24cebc53) && (0 < *(int *)(iVar1 + 0x90))) {
        iVar4 = *(int *)(iVar1 + 0x98);
      }
      iVar4 = *(int *)(iVar4 + 0x20);
      fVar2 = *(float *)(*(int *)(iVar1 + 0x20) + 0x60);
      iVar1 = *(int *)(*(int *)(iVar1 + 0x20) + 0x14);
      if ((iVar1 == 0) || (*(char *)(iVar1 + 0x34) < '\0')) {
        local_18 = 0xbf800000;
        if (iVar1 != 0) {
          local_18 = *(undefined4 *)(iVar1 + 100);
        }
        fVar7 = (float10)FUN_0057a020(local_18,unaff_EDI[2]);
        fVar7 = fVar7 + (float10)fVar2;
      }
      else {
        fVar7 = (float10)FUN_00579ff0(unaff_EDI[2]);
      }
      iVar1 = *(int *)(iVar4 + 0x14);
      if ((iVar1 == 0) || (*(char *)(iVar1 + 0x34) < '\0')) {
        local_14 = 0xbf800000;
        if (iVar1 != 0) {
          local_14 = *(undefined4 *)(iVar1 + 100);
        }
        fVar8 = (float10)FUN_0057a020(local_14,unaff_EDI[3]);
        fVar8 = fVar8 + (float10)fVar2;
      }
      else {
        fVar8 = (float10)FUN_00579ff0(unaff_EDI[3]);
      }
      if (((float)(fVar6 - (float10)0.3) < (float)fVar7) ||
         (fVar8 < (float10)(float)(fVar6 - (float10)0.3))) {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
      if (((((float)fVar7 < 0.0) && ((float10)0.0 < fVar8)) &&
          (ABS(*(float *)(param_1 + 0x3d4)) < 0.001 != (ABS(*(float *)(param_1 + 0x3d4)) == 0.001)))
         && ((float)fVar5 < 30.0)) {
        return 0;
      }
      return uVar3;
    }
  }
  return 1;
}


// ==== 0x454bd0 FUN_00454bd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00454bd0(int *param_1)

{
  float fVar1;
  int iVar2;
  ushort uVar4;
  uint3 uVar3;
  
  fVar1 = *(float *)(*(int *)(*param_1 + 0x2c) + 0x4f0) - *(float *)(*param_1 + 0x814);
  iVar2 = DAT_007372b8;
  if ((0 < DAT_007372b8) &&
     (iVar2 = CONCAT31((int3)((uint)DAT_007372b8 >> 8),*(char *)(DAT_007372bc + 1)),
     *(char *)(DAT_007372bc + 1) != '\0')) {
    uVar4 = (ushort)((uint)DAT_007372b8 >> 0x10);
    iVar2 = (uint)uVar4 << 0x10;
    if (DAT_007372b0 * -0.5 <= fVar1) {
      iVar2 = (uint)uVar4 << 0x10;
      if (DAT_007372b0 * _K_HALF < fVar1) {
        fVar1 = fVar1 - DAT_007372b0;
      }
    }
    else {
      fVar1 = fVar1 + DAT_007372b0;
    }
  }
  uVar3 = (uint3)(CONCAT22((short)((uint)iVar2 >> 0x10),
                           (ushort)(fVar1 < 0.0) << 8 | (ushort)NAN(fVar1) << 10 |
                           (ushort)(fVar1 == 0.0) << 0xe) >> 8);
  if (fVar1 < 0.0) {
    return CONCAT31(uVar3,1);
  }
  return (uint)uVar3 << 8;
}


// ==== 0x454c42 FUN_00454c42

undefined1 FUN_00454c42(void)

{
  bool in_PF;
  
  if (!in_PF) {
    return 1;
  }
  return 0;
}


// ==== 0x454c44 FUN_00454c44

undefined1 FUN_00454c44(void)

{
  return 1;
}


// ==== 0x454c49 FUN_00454c49

undefined1 FUN_00454c49(void)

{
  return 0;
}


// ==== 0x454c50 FUN_00454c50

uint __fastcall FUN_00454c50(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  undefined3 uVar5;
  
  iVar3 = DAT_0073ad34 - *(int *)(param_1 + 8);
  fVar2 = (float)iVar3 * 0.00025;
  fVar1 = *(float *)(param_1 + 0xc);
  uVar4 = CONCAT22((short)((uint)iVar3 >> 0x10),
                   (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                   (ushort)(fVar2 == fVar1) << 0xe);
  if (fVar2 >= fVar1 && (fVar2 == fVar1) == 0) {
    uVar5 = (undefined3)(uVar4 >> 8);
    uVar4 = CONCAT31(uVar5,*(char *)(param_1 + 4));
    if (*(char *)(param_1 + 4) != '\0') {
      return CONCAT31(uVar5,1);
    }
  }
  return uVar4 & 0xffffff00;
}


// ==== 0x454c59 FUN_00454c59

uint __fastcall FUN_00454c59(int param_1)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  uint uVar3;
  undefined3 uVar4;
  
  fVar2 = (float)in_EAX * 0.00025;
  fVar1 = *(float *)(param_1 + 0xc);
  uVar3 = CONCAT22((short)((uint)in_EAX >> 0x10),
                   (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                   (ushort)(fVar2 == fVar1) << 0xe);
  if (fVar2 >= fVar1 && (fVar2 == fVar1) == 0) {
    uVar4 = (undefined3)(uVar3 >> 8);
    uVar3 = CONCAT31(uVar4,*(char *)(param_1 + 4));
    if (*(char *)(param_1 + 4) != '\0') {
      return CONCAT31(uVar4,1);
    }
  }
  return uVar3 & 0xffffff00;
}


// ==== 0x454c90 FUN_00454c90

void __thiscall FUN_00454c90(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  float *extraout_EDX;
  float10 fVar6;
  undefined1 uStack_19;
  int *piStack_18;
  int *piStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  int iStack_8;
  int *piStack_4;
  
  iVar5 = *param_2;
  piStack_4 = param_2 + (char)param_2[0xe2] * 0xe + 2;
  piVar1 = *(int **)(iVar5 + 0x2c);
  piStack_18 = param_2 + 0xe6;
  piStack_14 = piVar1 + 0x13b;
  iVar2 = param_2[0xea];
  fVar6 = (float10)(**(code **)(*piVar1 + 0x5c))();
  *(undefined4 *)(param_1 + 0x1ec) = 0x40000000;
  *(float *)(param_1 + 0x1e4) = (float)fVar6;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
    *(undefined1 *)(param_1 + 0x1f0) = 1;
  }
  else {
    *(undefined1 *)(param_1 + 0x1f0) = 0;
  }
  *(undefined1 *)(param_1 + 0x1f1) = 1;
  *(undefined1 *)(param_1 + 0x1f2) = 1;
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  bVar3 = false;
  if (*(int *)(iVar2 + 0xc0) == -1) {
    if ((*(char *)(param_1 + 0x200) == '\0') && (cVar4 = FUN_00454a20(iVar5), cVar4 == '\0')) {
      bVar3 = true;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x200) = 0;
    iVar5 = FUN_005a6d20();
    if ((iVar5 == 0) || (*(char *)(iVar5 + 0xb) != '\t')) {
      *(undefined1 *)(param_1 + 0x200) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x200) = 1;
    }
  }
  iStack_8 = param_2[0xe5];
  if ((iStack_8 < 0) || (4 < iStack_8)) {
    piStack_14 = (int *)0x0;
    uStack_10 = 0x47c34f80;
    uStack_c = 0xbf800000;
    cVar4 = FUN_0045b050(piStack_18,0,&uStack_c,&piStack_14,&uStack_10,0,DAT_007006ec);
    if (((cVar4 == '\0') &&
        (((piStack_14 != (int *)0x0 && (cVar4 = FUN_0057a6f0(), cVar4 != '\0')) &&
         (iVar5 = FUN_0057b520(), iVar5 != 0)))) &&
       ((0.0 < *(float *)(iVar5 + 0x10) - (float)param_2[(char)param_2[0xe2] * 0xe + 6] &&
        (fVar6 = (float10)FUN_0057b480(),
        fVar6 < (float10)extraout_EDX[2] + (float10)(float)piStack_4[2])))) {
      piStack_14 = (int *)CONCAT31(piStack_14._1_3_,1);
      if (*extraout_EDX <= 0.0) {
        piStack_14 = (int *)((uint)piStack_14._1_3_ << 8);
      }
      cVar4 = FUN_0045d130(param_1 + 0x20,DAT_007006ec,piStack_14);
      if (cVar4 == '\0') {
        FUN_0045ae10(param_2 + 0xe6,param_1 + 0x20,param_2,0,0);
        goto LAB_00454dc4;
      }
    }
  }
  else {
    uStack_19 = 0;
    cVar4 = FUN_0045b150(piStack_18,param_1 + 0x20,param_2,DAT_007006ec,&uStack_19,1);
    if (cVar4 == '\0') goto LAB_00454dc4;
  }
  if (!bVar3) {
    return;
  }
LAB_00454dc4:
  *(undefined1 *)(param_1 + 0x1f0) = 0;
  *(undefined4 *)(param_1 + 0x1e4) = 0;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  return;
}


// ==== 0x454d41 FUN_00454d41

/* WARNING: Instruction at (ram,0x00454d54) overlaps instruction at (ram,0x00454d51)
    */

void __thiscall FUN_00454d41(undefined4 param_1)

{
  char *pcVar1;
  undefined1 *puVar2;
  char cVar3;
  char *in_EAX;
  int iVar4;
  float *extraout_EDX;
  int unaff_EBX;
  int unaff_EBP;
  uint unaff_ESI;
  float10 fVar5;
  undefined1 uStack00000013;
  undefined4 in_stack_00000014;
  int in_stack_00000018;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000020;
  int iStack00000024;
  int in_stack_00000028;
  char in_stack_00000030;
  
  pcVar1 = (char *)(unaff_EBP + -0x7fec8b40);
  *pcVar1 = *pcVar1 + (char)in_EAX;
  if (*pcVar1 < '\0') {
    unaff_EBX = CONCAT31((int3)((uint)unaff_EBX >> 8),(char)unaff_EBX + (char)((uint)param_1 >> 8));
    puVar2 = (undefined1 *)(CONCAT31((int3)((uint)in_EAX >> 8),(char)in_EAX + *in_EAX) + 0x20085);
    *puVar2 = *puVar2;
  }
  else {
    *(uint *)(unaff_EBP + 0xd) = *(uint *)(unaff_EBP + 0xd) | unaff_ESI;
    *(undefined1 *)(unaff_EBP + 0x200) = 1;
  }
  iStack00000024 = *(int *)(unaff_EBX + 0x394);
  if ((iStack00000024 < 0) || (4 < iStack00000024)) {
    in_stack_00000018 = 0;
    in_stack_0000001c = 0x47c34f80;
    in_stack_00000020 = 0xbf800000;
    cVar3 = FUN_0045b050(in_stack_00000014,0,&stack0x00000020,&stack0x00000018,&stack0x0000001c,0,
                         DAT_007006ec);
    if (((cVar3 == '\0') &&
        (((in_stack_00000018 != 0 && (cVar3 = FUN_0057a6f0(), cVar3 != '\0')) &&
         (iVar4 = FUN_0057b520(), iVar4 != 0)))) &&
       ((0.0 < *(float *)(iVar4 + 0x10) -
               *(float *)(*(char *)(unaff_EBX + 0x388) * 0x38 + 0x18 + unaff_EBX) &&
        (fVar5 = (float10)FUN_0057b480(),
        fVar5 < (float10)extraout_EDX[2] + (float10)*(float *)(in_stack_00000028 + 8))))) {
      in_stack_00000018 = CONCAT31(in_stack_00000018._1_3_,1);
      if (*extraout_EDX <= 0.0) {
        in_stack_00000018 = (uint)in_stack_00000018._1_3_ << 8;
      }
      cVar3 = FUN_0045d130(unaff_EBP + 0x20,DAT_007006ec,in_stack_00000018);
      if (cVar3 == '\0') {
        FUN_0045ae10(unaff_EBX + 0x398,unaff_EBP + 0x20,unaff_EBX,0,0);
        goto LAB_00454dc4;
      }
    }
  }
  else {
    uStack00000013 = 0;
    cVar3 = FUN_0045b150(in_stack_00000014,unaff_EBP + 0x20,unaff_EBX,DAT_007006ec,&stack0x00000013,
                         1);
    if (cVar3 == '\0') goto LAB_00454dc4;
  }
  if (in_stack_00000030 == '\0') {
    return;
  }
LAB_00454dc4:
  *(undefined1 *)(unaff_EBP + 0x1f0) = 0;
  *(undefined4 *)(unaff_EBP + 0x1e4) = 0;
  *(undefined4 *)(unaff_EBP + 0x1e8) = 0;
  return;
}


// ==== 0x454d49 FUN_00454d49

void FUN_00454d49(void)

{
  char cVar1;
  int iVar2;
  float *extraout_EDX;
  int unaff_EBX;
  int unaff_EBP;
  uint unaff_ESI;
  float10 fVar3;
  undefined1 uStack00000013;
  undefined4 in_stack_00000014;
  int in_stack_00000018;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000020;
  int iStack00000024;
  int in_stack_00000028;
  char in_stack_00000030;
  
  *(uint *)(unaff_EBP + 0xd) = *(uint *)(unaff_EBP + 0xd) | unaff_ESI;
  *(undefined1 *)(unaff_EBP + 0x200) = 1;
  iStack00000024 = *(int *)(unaff_EBX + 0x394);
  if ((iStack00000024 < 0) || (4 < iStack00000024)) {
    in_stack_00000018 = 0;
    in_stack_0000001c = 0x47c34f80;
    in_stack_00000020 = 0xbf800000;
    cVar1 = FUN_0045b050(in_stack_00000014,0,&stack0x00000020,&stack0x00000018,&stack0x0000001c,0,
                         DAT_007006ec);
    if (((cVar1 == '\0') &&
        (((in_stack_00000018 != 0 && (cVar1 = FUN_0057a6f0(), cVar1 != '\0')) &&
         (iVar2 = FUN_0057b520(), iVar2 != 0)))) &&
       ((0.0 < *(float *)(iVar2 + 0x10) -
               *(float *)(*(char *)(unaff_EBX + 0x388) * 0x38 + 0x18 + unaff_EBX) &&
        (fVar3 = (float10)FUN_0057b480(),
        fVar3 < (float10)extraout_EDX[2] + (float10)*(float *)(in_stack_00000028 + 8))))) {
      in_stack_00000018 = CONCAT31(in_stack_00000018._1_3_,1);
      if (*extraout_EDX <= 0.0) {
        in_stack_00000018 = (uint)in_stack_00000018._1_3_ << 8;
      }
      cVar1 = FUN_0045d130(unaff_EBP + 0x20,DAT_007006ec,in_stack_00000018);
      if (cVar1 == '\0') {
        FUN_0045ae10(unaff_EBX + 0x398,unaff_EBP + 0x20,unaff_EBX,0,0);
        goto LAB_00454dc4;
      }
    }
  }
  else {
    uStack00000013 = 0;
    cVar1 = FUN_0045b150(in_stack_00000014,unaff_EBP + 0x20,unaff_EBX,DAT_007006ec,&stack0x00000013,
                         1);
    if (cVar1 == '\0') goto LAB_00454dc4;
  }
  if (in_stack_00000030 == '\0') {
    return;
  }
LAB_00454dc4:
  *(undefined1 *)(unaff_EBP + 0x1f0) = 0;
  *(undefined4 *)(unaff_EBP + 0x1e4) = 0;
  *(undefined4 *)(unaff_EBP + 0x1e8) = 0;
  return;
}


// ==== 0x454d55 FUN_00454d55

void FUN_00454d55(void)

{
  char cVar1;
  char *in_EAX;
  int iVar2;
  float *extraout_EDX;
  int unaff_EBX;
  int unaff_EBP;
  float10 fVar3;
  undefined1 uStack00000013;
  undefined4 in_stack_00000014;
  int in_stack_00000018;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000020;
  int iStack00000024;
  int in_stack_00000028;
  char in_stack_00000030;
  
  *in_EAX = *in_EAX + (char)in_EAX;
  iStack00000024 = *(int *)(unaff_EBX + 0x394);
  if ((iStack00000024 < 0) || (4 < iStack00000024)) {
    in_stack_00000018 = 0;
    in_stack_0000001c = 0x47c34f80;
    in_stack_00000020 = 0xbf800000;
    cVar1 = FUN_0045b050(in_stack_00000014,0,&stack0x00000020,&stack0x00000018,&stack0x0000001c,0,
                         DAT_007006ec);
    if (((cVar1 == '\0') &&
        (((in_stack_00000018 != 0 && (cVar1 = FUN_0057a6f0(), cVar1 != '\0')) &&
         (iVar2 = FUN_0057b520(), iVar2 != 0)))) &&
       ((0.0 < *(float *)(iVar2 + 0x10) -
               *(float *)(*(char *)(unaff_EBX + 0x388) * 0x38 + 0x18 + unaff_EBX) &&
        (fVar3 = (float10)FUN_0057b480(),
        fVar3 < (float10)extraout_EDX[2] + (float10)*(float *)(in_stack_00000028 + 8))))) {
      in_stack_00000018 = CONCAT31(in_stack_00000018._1_3_,1);
      if (*extraout_EDX <= 0.0) {
        in_stack_00000018 = (uint)in_stack_00000018._1_3_ << 8;
      }
      cVar1 = FUN_0045d130(unaff_EBP + 0x20,DAT_007006ec,in_stack_00000018);
      if (cVar1 == '\0') {
        FUN_0045ae10(unaff_EBX + 0x398,unaff_EBP + 0x20,unaff_EBX,0,0);
        goto LAB_00454dc4;
      }
    }
  }
  else {
    uStack00000013 = 0;
    cVar1 = FUN_0045b150(in_stack_00000014,unaff_EBP + 0x20,unaff_EBX,DAT_007006ec,&stack0x00000013,
                         1);
    if (cVar1 == '\0') goto LAB_00454dc4;
  }
  if (in_stack_00000030 == '\0') {
    return;
  }
LAB_00454dc4:
  *(undefined1 *)(unaff_EBP + 0x1f0) = 0;
  *(undefined4 *)(unaff_EBP + 0x1e4) = 0;
  *(undefined4 *)(unaff_EBP + 0x1e8) = 0;
  return;
}


// ==== 0x454e41 FUN_00454e41

void FUN_00454e41(void)

{
  char cVar1;
  char *in_EAX;
  int iVar2;
  float *extraout_EDX;
  int unaff_EBX;
  int unaff_EBP;
  char in_CF;
  float10 fVar3;
  int in_stack_00000028;
  char in_stack_00000030;
  
  iVar2 = CONCAT31((int3)((uint)in_EAX >> 8),(char)in_EAX + *in_EAX + in_CF);
  if (((iVar2 != 0) &&
      (0.0 < *(float *)(iVar2 + 0x10) -
             *(float *)(*(char *)(unaff_EBX + 0x388) * 0x38 + 0x18 + unaff_EBX))) &&
     (fVar3 = (float10)FUN_0057b480(),
     fVar3 < (float10)extraout_EDX[2] + (float10)*(float *)(in_stack_00000028 + 8))) {
    cVar1 = FUN_0045d130(unaff_EBP + 0x20,DAT_007006ec,0.0 < *extraout_EDX);
    if (cVar1 == '\0') {
      FUN_0045ae10(unaff_EBX + 0x398,unaff_EBP + 0x20,unaff_EBX,0,0);
      goto LAB_00454dc4;
    }
  }
  if (in_stack_00000030 == '\0') {
    return;
  }
LAB_00454dc4:
  *(undefined1 *)(unaff_EBP + 0x1f0) = 0;
  *(undefined4 *)(unaff_EBP + 0x1e4) = 0;
  *(undefined4 *)(unaff_EBP + 0x1e8) = 0;
  return;
}


// ==== 0x454e49 FUN_00454e49

/* WARNING: Control flow encountered bad instruction data */

void FUN_00454e49(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== 0x454e4f FUN_00454e4f

void __thiscall FUN_00454e4f(undefined4 param_1)

{
  char cVar1;
  int in_EAX;
  float *extraout_EDX;
  byte bVar2;
  int unaff_EBX;
  int unaff_EBP;
  float10 in_ST0;
  float10 fVar3;
  int in_stack_00000028;
  char in_stack_00000030;
  
  bVar2 = (byte)unaff_EBX;
  *(char *)(unaff_EBX + -0x40) =
       *(char *)(unaff_EBX + -0x40) + (char)((uint)param_1 >> 8) + CARRY1((byte)param_1,bVar2);
  *(char *)((int)&ExceptionList + in_EAX) =
       (*(char *)((int)&ExceptionList + in_EAX) - bVar2) - ((byte)in_EAX < bVar2);
  if (((float10)0.0 < in_ST0) &&
     (fVar3 = (float10)FUN_0057b480(),
     fVar3 < (float10)extraout_EDX[2] + (float10)*(float *)(in_stack_00000028 + 8))) {
    cVar1 = FUN_0045d130(unaff_EBP + 0x20,DAT_007006ec,0.0 < *extraout_EDX);
    if (cVar1 == '\0') {
      FUN_0045ae10(unaff_EBX + 0x398,unaff_EBP + 0x20,unaff_EBX,0,0);
      goto LAB_00454dc4;
    }
  }
  if (in_stack_00000030 == '\0') {
    return;
  }
LAB_00454dc4:
  *(undefined1 *)(unaff_EBP + 0x1f0) = 0;
  *(undefined4 *)(unaff_EBP + 0x1e4) = 0;
  *(undefined4 *)(unaff_EBP + 0x1e8) = 0;
  return;
}


// ==== 0x454ee0 FUN_00454ee0

void FUN_00454ee0(int *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*param_1 + 0x2c);
  *(undefined4 *)(iVar1 + 0x4ec) = 0;
  *(undefined4 *)(iVar1 + 0x4f0) = 0;
  *(undefined4 *)(iVar1 + 0x4f4) = 0;
  *(undefined4 *)(iVar1 + 0x4f8) = 0;
  *(undefined1 *)(*param_1 + 0x88c) = 0;
  return;
}


// ==== 0x454f10 FUN_00454f10

float10 FUN_00454f10(undefined4 param_1,float param_2)

{
  Curve_Evaluate(&param_2,param_2);
  return (float10)param_2;
}


// ==== 0x454f30 Curve_Evaluate

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

void Curve_Evaluate(float *param_1,float param_2)

{
  int iVar1;
  float fVar2;
  undefined4 *in_EAX;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  
  iVar1 = in_EAX[1];
  if (iVar1 < 2) {
    if (iVar1 < 1) {
      return;
    }
    pfVar4 = (float *)*in_EAX;
  }
  else {
    pfVar4 = (float *)*in_EAX;
    if (param_2 < *pfVar4 == (param_2 == *pfVar4)) {
      if (pfVar4[iVar1 * 2 + -2] <= param_2) {
        *param_1 = pfVar4[iVar1 * 2 + -1];
        return;
      }
      iVar3 = 0;
      pfVar5 = pfVar4;
      if (iVar1 + -1 < 1) {
        return;
      }
      while ((param_2 < *pfVar5 || (pfVar5[2] <= param_2))) {
        iVar3 = iVar3 + 1;
        pfVar5 = pfVar5 + 2;
        if (iVar1 + -1 <= iVar3) {
          return;
        }
      }
      fVar2 = (param_2 - pfVar4[iVar3 * 2]) / (pfVar4[iVar3 * 2 + 2] - pfVar4[iVar3 * 2]);
      *param_1 = fVar2 * pfVar4[iVar3 * 2 + 3] + (_K_ONE - fVar2) * pfVar4[iVar3 * 2 + 1];
      return;
    }
  }
  *param_1 = pfVar4[1];
  return;
}


// ==== 0x454ff0 FUN_00454ff0

int __fastcall FUN_00454ff0(int param_1)

{
  int in_EAX;
  
  return param_1 + 0x265 + in_EAX;
}


// ==== 0x455000 AIAction::AIAction

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 * __fastcall AIAction__AIAction(undefined4 param_1,undefined4 *param_2)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 *puVar2;
  
  param_2[0x19] = in_EAX;
  *(undefined1 *)(param_2 + 0x17) = 0xff;
  *(undefined2 *)((int)param_2 + 0x5e) = 0xffff;
  *param_2 = &PTR_FUN_006c8fc4;
  param_2[0x1a] = 0;
  param_2[0x1b] = 0;
  *(undefined1 *)(param_2 + 0x18) = 0;
  param_2[1] = 0;
  puVar2 = param_2 + 2;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_2[8] = 0;
  param_2[0xf] = 0;
  puVar2 = param_2 + 9;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = param_2 + 0x10;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return param_2;
}


// ==== 0x45504f FUN_0045504f

int __fastcall FUN_0045504f(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_2 + 0x24);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)(param_2 + 0x40);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return param_2;
}


// ==== 0x455059 FUN_00455059

int __fastcall FUN_00455059(int param_1,int param_2)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 *unaff_EDI;
  undefined4 *puVar2;
  
  for (; param_1 != 0; param_1 = param_1 + -1) {
    *unaff_EDI = in_EAX;
    unaff_EDI = unaff_EDI + 1;
  }
  puVar2 = (undefined4 *)(param_2 + 0x40);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = in_EAX;
    puVar2 = puVar2 + 1;
  }
  return param_2;
}


// ==== 0x455070 FUN_00455070

void __thiscall FUN_00455070(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  *param_1 = &PTR_FUN_006c8fc4;
  iVar2 = DAT_00733f60;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00733f60 + 0x18);
    *param_1 = *(undefined4 *)(DAT_00733f60 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return;
}


// ==== 0x4550a0 FUN_004550a0

void __fastcall FUN_004550a0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c8fc4;
  return;
}


// ==== 0x4550b0 FUN_004550b0

int FUN_004550b0(int param_1)

{
  return param_1 + 0xc;
}


// ==== 0x4550c0 FUN_004550c0

float10 FUN_004550c0(int param_1)

{
  return (float10)*(float *)(param_1 + 0x30);
}


// ==== 0x4550d0 FUN_004550d0

float10 FUN_004550d0(float *param_1,float *param_2)

{
  return ((float10)*param_2 - (float10)*param_1) * (float10)param_1[3] +
         ((float10)param_2[1] - (float10)param_1[1]) * (float10)param_1[4];
}


// ==== 0x4550f0 FUN_004550f0

float10 FUN_004550f0(float *param_1,float *param_2)

{
  return ((float10)*param_2 - (float10)*param_1) * (float10)param_1[4] -
         ((float10)param_2[1] - (float10)param_1[1]) * (float10)param_1[3];
}


// ==== 0x455110 FUN_00455110

void FUN_00455110(float *param_1,float *param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = param_1[4];
  fVar3 = -param_1[3] * param_4 + param_1[1];
  fVar2 = *param_1;
  param_2[1] = fVar3;
  *param_2 = fVar1 * param_4 + fVar2;
  fVar1 = param_1[4];
  *param_2 = param_3 * param_1[3] + *param_2;
  param_2[1] = param_3 * fVar1 + fVar3;
  return;
}


// ==== 0x455160 FUN_00455160

void FUN_00455160(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_004422b0(param_3,param_4);
  return;
}


// ==== 0x455180 FUN_00455180

undefined4 * __thiscall FUN_00455180(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_004550a0();
  iVar2 = DAT_00733f60;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00733f60 + 0x18);
    *param_1 = *(undefined4 *)(DAT_00733f60 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x4551b0 FUN_004551b0

undefined4 FUN_004551b0(void)

{
  return 1;
}


// ==== 0x4551c0 FUN_004551c0

int FUN_004551c0(int param_1)

{
  return param_1 + 0x14;
}


// ==== 0x4551d0 FUN_004551d0

float10 FUN_004551d0(int param_1)

{
  return (float10)*(float *)(param_1 + 0x34);
}


// ==== 0x4551e0 FUN_004551e0

void FUN_004551e0(float *param_1,float *param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = param_1[6];
  fVar3 = -param_1[5] * param_4 + param_1[1];
  fVar2 = *param_1;
  param_2[1] = fVar3;
  *param_2 = fVar1 * param_4 + fVar2;
  fVar1 = param_1[6];
  *param_2 = param_3 * param_1[5] + *param_2;
  param_2[1] = param_3 * fVar1 + fVar3;
  return;
}


// ==== 0x455230 FUN_00455230

void FUN_00455230(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  TrackRoutePoint__GetForwardPosition(param_3,param_4);
  return;
}


// ==== 0x45524f FUN_0045524f

void __fastcall FUN_0045524f(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0045524f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((int)&DAT_00733f64 + param_1))();
  return;
}


// ==== 0x455250 FUN_00455250

void __fastcall FUN_00455250(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00733f64;
  iVar1 = *(int *)(DAT_00733f64 + 0x18);
  *param_1 = *(undefined4 *)(DAT_00733f64 + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x455270 FUN_00455270

void FUN_00455270(void)

{
  undefined4 *in_EAX;
  int iVar1;
  undefined4 *puVar2;
  
  *in_EAX = &PTR_FUN_006b7efc;
  in_EAX[0x2a] = 0;
  puVar2 = in_EAX;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  FUN_005a5340();
  *in_EAX = &PTR_FUN_006c9030;
  return;
}


// ==== 0x4552a0 FUN_004552a0

void __fastcall FUN_004552a0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c9030;
  FUN_005a4f40();
  return;
}


// ==== 0x4552b0 FUN_004552b0

bool FUN_004552b0(int param_1)

{
  return *(char *)(param_1 + 0xd) != '\x01';
}


// ==== 0x4552d0 FUN_004552d0

undefined4 * FUN_004552d0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (&DAT_0077af30)[*(byte *)(param_1 + 0x83)];
  }
  if (*(char *)(iVar1 + 0x15) == '\0') {
    puVar2 = (undefined4 *)FUN_00567160();
    if (puVar2 != (undefined4 *)0x0) {
      AIAction__AIAction();
      *puVar2 = &PTR_FUN_006c8f90;
      return puVar2;
    }
  }
  else {
    puVar2 = (undefined4 *)FUN_00567160();
    if (puVar2 != (undefined4 *)0x0) {
      AIAction__AIAction();
      *puVar2 = &PTR_FUN_006c8f5c;
      return puVar2;
    }
  }
  return (undefined4 *)0x0;
}


// ==== 0x455345 FUN_00455345

float10 FUN_00455345(int param_1)

{
  return (float10)*(float *)(param_1 + 0x1c);
}


// ==== 0x455349 FUN_00455349

float10 FUN_00455349(int param_1)

{
  return (float10)*(float *)(param_1 + 0x1c);
}


// ==== 0x45534c FUN_0045534c

float10 FUN_0045534c(int param_1)

{
  return (float10)*(float *)(param_1 + 0x1c);
}


// ==== 0x45534f FUN_0045534f

float10 FUN_0045534f(int param_1)

{
  return (float10)*(float *)(param_1 + 0x1c);
}


// ==== 0x455350 FUN_00455350

float10 FUN_00455350(int param_1)

{
  return (float10)*(float *)(param_1 + 0x1c);
}


// ==== 0x455360 FUN_00455360

undefined4 * __thiscall FUN_00455360(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_004552a0();
  iVar2 = DAT_00733f64;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00733f64 + 0x18);
    *param_1 = *(undefined4 *)(DAT_00733f64 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x455390 FUN_00455390

void FUN_00455390(void)

{
  undefined4 *in_EAX;
  int iVar1;
  undefined4 *puVar2;
  
  *in_EAX = &PTR_FUN_006b7efc;
  in_EAX[0x2a] = 0;
  puVar2 = in_EAX;
  for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  FUN_005a5340();
  *in_EAX = &PTR_FUN_006c8ff8;
  return;
}


// ==== 0x4553c0 FUN_004553c0

void __fastcall FUN_004553c0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c8ff8;
  FUN_005a4f40();
  return;
}


// ==== 0x4553d0 FUN_004553d0

int FUN_004553d0(int param_1)

{
  if (param_1 < 5) {
    return param_1 + 5;
  }
  if ((10 < param_1) && (param_1 < 0x11)) {
    param_1 = param_1 + 6;
  }
  return param_1;
}


// ==== 0x4553f0 FUN_004553f0

bool FUN_004553f0(int param_1)

{
  return *(char *)(param_1 + 0xd) == '\x01';
}


// ==== 0x455410 FUN_00455410

undefined4 * FUN_00455410(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (&DAT_0077af30)[*(byte *)(param_1 + 0x83)];
  }
  if (*(char *)(iVar1 + 0x15) == '\0') {
    puVar2 = (undefined4 *)FUN_00567160();
    if (puVar2 != (undefined4 *)0x0) {
      AIAction__AIAction();
      *puVar2 = &PTR_FUN_006c8f5c;
      return puVar2;
    }
  }
  else {
    puVar2 = (undefined4 *)FUN_00567160();
    if (puVar2 != (undefined4 *)0x0) {
      AIAction__AIAction();
      *puVar2 = &PTR_FUN_006c8f90;
      return puVar2;
    }
  }
  return (undefined4 *)0x0;
}


// ==== 0x455441 FUN_00455441

undefined4 * FUN_00455441(void)

{
  undefined4 *unaff_ESI;
  
  if (unaff_ESI != (undefined4 *)0x0) {
    AIAction__AIAction();
    *unaff_ESI = &PTR_FUN_006c8f5c;
    return unaff_ESI;
  }
  return (undefined4 *)0x0;
}


// ==== 0x455445 FUN_00455445

void FUN_00455445(void)

{
  undefined4 *unaff_ESI;
  
  AIAction__AIAction();
  *unaff_ESI = &PTR_FUN_006c8f5c;
  return;
}


// ==== 0x455449 FUN_00455449

void FUN_00455449(void)

{
  undefined4 *unaff_ESI;
  
  AIAction__AIAction();
  *unaff_ESI = &PTR_FUN_006c8f5c;
  return;
}


// ==== 0x455455 FUN_00455455

void FUN_00455455(void)

{
  return;
}


// ==== 0x455490 FUN_00455490

float10 FUN_00455490(float *param_1,float *param_2)

{
  return ((float10)*param_2 - (float10)*param_1) * (float10)param_1[5] +
         ((float10)param_2[1] - (float10)param_1[1]) * (float10)param_1[6];
}


// ==== 0x4554b0 FUN_004554b0

float10 FUN_004554b0(float *param_1,float *param_2)

{
  return ((float10)*param_2 - (float10)*param_1) * (float10)param_1[6] -
         ((float10)param_2[1] - (float10)param_1[1]) * (float10)param_1[5];
}


// ==== 0x4554d0 FUN_004554d0

float10 FUN_004554d0(int param_1)

{
  return (float10)*(float *)(param_1 + 0x20);
}


// ==== 0x4554e0 FUN_004554e0

undefined4 * __thiscall FUN_004554e0(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_004553c0();
  iVar2 = DAT_00733f64;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00733f64 + 0x18);
    *param_1 = *(undefined4 *)(DAT_00733f64 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x455510 FUN_00455510

void __fastcall FUN_00455510(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_007344c8;
  iVar1 = *(int *)(DAT_007344c8 + 0x18);
  *param_1 = *(undefined4 *)(DAT_007344c8 + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x455530 FUN_00455530

void FUN_00455530(void)

{
  undefined4 *puVar1;
  
  DAT_0073609c = (undefined4 *)FUN_00566dc0(0x18,"AIGoalSlotPool",0);
  if ((DAT_0073609c != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_0073609c;
    puVar1 = DAT_0073609c;
    DAT_0073609c[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_0073609c = &DAT_0073d818;
  }
  DAT_00736098 = (undefined4 *)FUN_00566dc0(0x220,"AIActionSlotPool",0);
  if ((DAT_00736098 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_00736098;
    puVar1 = DAT_00736098;
    DAT_00736098[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_00736098 = &DAT_0073d818;
  }
  DAT_00733f64 = (undefined4 *)FUN_00566dc0(0xc4,"FuturePointsSlotPool",0);
  if ((DAT_00733f64 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_00733f64;
    puVar1 = DAT_00733f64;
    DAT_00733f64[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_00733f64 = &DAT_0073d818;
  }
  DAT_00733f60 = (undefined4 *)FUN_00566dc0(0x70,"FuturePointSlotPool",0);
  if (DAT_00733f60 == (undefined4 *)0x0) {
    return;
  }
  if (DAT_0073d814 == 1) {
    *DAT_0073d81c = DAT_00733f60;
    puVar1 = DAT_00733f60;
    DAT_00733f60[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_00733f60 = &DAT_0073d818;
  }
  return;
}


// ==== 0x455640 FUN_00455640

void FUN_00455640(void)

{
  if (DAT_00736098 != 0) {
    SlotPool__Destroy();
    DAT_00736098 = 0;
  }
  if (DAT_0073609c != 0) {
    SlotPool__Destroy();
    DAT_0073609c = 0;
  }
  if (DAT_00733f64 != 0) {
    SlotPool__Destroy();
    DAT_00733f64 = 0;
  }
  if (DAT_00733f60 != 0) {
    SlotPool__Destroy();
    DAT_00733f60 = 0;
  }
  FUN_00455ae0(&DAT_0077a4b0);
  FUN_00455ae0(&DAT_0077a6d8);
  return;
}


// ==== 0x4556d0 FUN_004556d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_004556d0(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *in_EAX;
  undefined2 extraout_var;
  uint3 uVar5;
  float local_10;
  float local_c;
  
  fVar1 = *in_EAX;
  local_10 = *(float *)(param_1 + 0x70);
  fVar2 = *(float *)(param_1 + 0x60);
  local_c = *(float *)(param_1 + 0x74);
  fVar3 = in_EAX[1];
  fVar4 = *(float *)(param_1 + 100);
  if (*(float *)(param_1 + 0x3d4) < _K_ONE) {
    local_c = *(float *)(param_1 + 0x94);
    local_10 = *(float *)(param_1 + 0x90);
  }
  bNormalize2();
  bNormalize2();
  fVar1 = local_c * (fVar3 - fVar4) + local_10 * (fVar1 - fVar2);
  uVar5 = (uint3)(CONCAT22(extraout_var,
                           (ushort)(fVar1 < param_2) << 8 |
                           (ushort)(NAN(fVar1) || NAN(param_2)) << 10 |
                           (ushort)(fVar1 == param_2) << 0xe) >> 8);
  if (fVar1 >= param_2 && (fVar1 == param_2) == 0) {
    return CONCAT31(uVar5,1);
  }
  return (uint)uVar5 << 8;
}


// ==== 0x455760 FUN_00455760

void FUN_00455760(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *unaff_ESI;
  float10 fVar3;
  undefined4 local_2e0;
  undefined4 local_2dc;
  undefined4 local_2d8;
  undefined1 local_2d0 [32];
  int aiStack_2b0 [160];
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  FUN_00440740();
  local_2e0 = *unaff_ESI;
  local_2dc = unaff_ESI[1];
  *param_1 = local_2e0;
  local_2d8 = 0;
  param_1[1] = unaff_ESI[1];
  fVar3 = (float10)GroundQuery__FindSurfaceBelow(local_2d0,&local_2e0,0,0,0);
  param_1[2] = (float)fVar3;
  iVar2 = 0;
  if (0 < local_30) {
    do {
      piVar1 = aiStack_2b0 + iVar2;
      iVar2 = iVar2 + 1;
      *(char *)(*piVar1 + 8) = *(char *)(*piVar1 + 8) + -1;
    } while (iVar2 < local_30);
  }
  return;
}


// ==== 0x455810 FUN_00455810

void FUN_00455810(char *param_1)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  char *pcVar10;
  undefined4 *puVar11;
  int *piVar12;
  int *piVar13;
  undefined **ppuVar14;
  undefined4 *puVar15;
  char *local_20;
  int local_1c;
  int local_18;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00686598;
  local_c = ExceptionList;
  if (*param_1 == '\0') {
    ppuVar14 = &PTR_DAT_00700684;
    piVar13 = (int *)(param_1 + 0x1e8);
    ExceptionList = &local_c;
    do {
      uVar7 = 0x4d;
      iVar5 = -1;
      pcVar10 = "MARKER_GREEN";
      do {
        iVar5 = iVar5 * 0x21 + uVar7;
        pbVar9 = (byte *)(pcVar10 + 1);
        uVar7 = (uint)*pbVar9;
        pcVar10 = pcVar10 + 1;
      } while (*pbVar9 != 0);
      piVar13[-1] = iVar5;
      pbVar9 = *ppuVar14;
      iVar5 = -1;
      bVar2 = *pbVar9;
      while (bVar2 != 0) {
        iVar5 = iVar5 * 0x21 + (uint)bVar2;
        pbVar1 = pbVar9 + 1;
        pbVar9 = pbVar9 + 1;
        bVar2 = *pbVar1;
      }
      if (iVar5 != *piVar13) {
        *piVar13 = iVar5;
        piVar13[1] = -1;
      }
      ppuVar14 = ppuVar14 + 1;
      piVar13 = piVar13 + 4;
    } while ((int)ppuVar14 < 0x700694);
    local_20 = param_1 + 4;
    local_18 = 3;
    do {
      local_1c = 0x28;
      do {
        iVar5 = DAT_007344c8;
        local_4 = 0xffffffff;
        puVar15 = (undefined4 *)(DAT_007344c8 + 0x10);
        if ((*(int *)(DAT_007344c8 + 0x10) == 0) && ((*(byte *)(DAT_007344c8 + 0x14) & 1) != 0)) {
          FUN_00566e60();
        }
        puVar11 = (undefined4 *)*puVar15;
        iVar6 = *(int *)(iVar5 + 0x18) + 1;
        if (puVar11 != (undefined4 *)0x0) {
          uVar3 = *puVar11;
          if (*(int *)(iVar5 + 0x1c) < iVar6) {
            *(int *)(iVar5 + 0x1c) = iVar6;
          }
          *(int *)(iVar5 + 0x18) = iVar6;
          bVar2 = *(byte *)(iVar5 + 0x14);
          *puVar15 = uVar3;
          if (((bVar2 & 2) != 0) &&
             (iVar5 = *(int *)(iVar5 + 0x28) >> 2, puVar15 = puVar11, 0 < iVar5)) {
            for (; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar15 = 0;
              puVar15 = puVar15 + 1;
            }
          }
        }
        iVar5 = DAT_0073557c;
        local_4 = 0;
        if (puVar11 == (undefined4 *)0x0) {
          puVar11 = (undefined4 *)0x0;
        }
        else {
          pcVar10 = "MARKER_GREENARROW";
          iVar6 = -1;
          uVar7 = 0x4d;
          do {
            iVar6 = iVar6 * 0x21 + uVar7;
            pbVar9 = (byte *)(pcVar10 + 1);
            uVar7 = (uint)*pbVar9;
            pcVar10 = pcVar10 + 1;
          } while (*pbVar9 != 0);
          piVar13 = (int *)(DAT_0073557c + 0x10);
          if ((*(int *)(DAT_0073557c + 0x10) == 0) && ((*(byte *)(DAT_0073557c + 0x14) & 1) != 0)) {
            FUN_00566e60();
          }
          piVar12 = (int *)*piVar13;
          iVar8 = *(int *)(iVar5 + 0x18) + 1;
          if (piVar12 == (int *)0x0) {
            piVar12 = (int *)0x0;
          }
          else {
            iVar4 = *piVar12;
            if (*(int *)(iVar5 + 0x1c) < iVar8) {
              *(int *)(iVar5 + 0x1c) = iVar8;
            }
            *(int *)(iVar5 + 0x18) = iVar8;
            *piVar13 = iVar4;
            if (((*(byte *)(iVar5 + 0x14) & 2) != 0) &&
               (iVar5 = *(int *)(iVar5 + 0x28) >> 2, piVar13 = piVar12, 0 < iVar5)) {
              for (; iVar5 != 0; iVar5 = iVar5 + -1) {
                *piVar13 = 0;
                piVar13 = piVar13 + 1;
              }
            }
            piVar12[3] = 0;
            piVar12[2] = iVar6;
            piVar12[4] = 0;
            piVar12[5] = 0;
            if (iVar6 != 0) {
              *DAT_00743c74 = (int)piVar12;
              piVar13 = piVar12;
              piVar12[1] = (int)DAT_00743c74;
              DAT_00743c74 = piVar13;
              *piVar12 = (int)&DAT_00743c70;
            }
            if (((piVar12[2] != 0) && (iVar5 = Solid_FindInAllLists(), piVar12[2] != 0)) &&
               (iVar5 != piVar12[3])) {
              iVar6 = *piVar12;
              piVar13 = (int *)piVar12[1];
              *piVar13 = iVar6;
              *(int **)(iVar6 + 4) = piVar13;
              if (iVar5 == 0) {
                *DAT_00743c74 = (int)piVar12;
                piVar13 = piVar12;
                piVar12[1] = (int)DAT_00743c74;
                DAT_00743c74 = piVar13;
                *piVar12 = (int)&DAT_00743c70;
                piVar12[3] = 0;
              }
              else {
                puVar15 = *(undefined4 **)(iVar5 + 0x8c);
                *puVar15 = piVar12;
                *(int **)(iVar5 + 0x8c) = piVar12;
                piVar12[1] = (int)puVar15;
                *piVar12 = iVar5 + 0x88;
                piVar12[3] = iVar5;
              }
            }
          }
          puVar11[2] = piVar12;
          puVar11[3] = 0;
          puVar11[5] = 1;
          puVar11[6] = 0;
          puVar11[4] = 0;
          puVar11[0x18] = 0;
          *DAT_00737820 = puVar11;
          puVar15 = puVar11;
          puVar11[1] = DAT_00737820;
          DAT_00737820 = puVar15;
          *puVar11 = &DAT_0073781c;
          *(undefined1 *)(puVar11 + 7) = 0;
        }
        *(undefined4 **)local_20 = puVar11;
        local_20 = local_20 + 4;
        local_1c = local_1c + -1;
        puVar11[4] = 0;
      } while (local_1c != 0);
      local_18 = local_18 + -1;
    } while (local_18 != 0);
    *param_1 = '\x01';
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x455ae0 FUN_00455ae0

void FUN_00455ae0(char *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_4;
  
  iVar3 = DAT_007344c8;
  if (*param_1 != '\0') {
    piVar5 = (int *)(param_1 + 4);
    local_4 = 3;
    do {
      iVar4 = 0x28;
      do {
        puVar1 = (undefined4 *)*piVar5;
        if (puVar1 != (undefined4 *)0x0) {
          FUN_00591c90(puVar1);
          iVar2 = *(int *)(iVar3 + 0x18);
          *puVar1 = *(undefined4 *)(iVar3 + 0x10);
          *(int *)(iVar3 + 0x18) = iVar2 + -1;
          *(undefined4 **)(iVar3 + 0x10) = puVar1;
        }
        *piVar5 = 0;
        piVar5 = piVar5 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      local_4 = local_4 + -1;
    } while (local_4 != 0);
    *param_1 = '\0';
  }
  return;
}


// ==== 0x455b50 FUN_00455b50

void __thiscall FUN_00455b50(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_2 + 4 + (param_3 + param_1 * 0x28) * 4);
  iVar2 = *(int *)(iVar1 + 0x60);
  *(undefined4 *)(iVar1 + 0x10) = 1;
  if (iVar2 == 0) {
    bMatrixCopy_b();
  }
  else {
    bMatrixCopy_b();
    if (*(int *)(iVar2 + 0xe4) == 0) {
      FUN_00579190();
      return;
    }
  }
  return;
}


// ==== 0x455c20 FUN_00455c20

void FUN_00455c20(void)

{
  int iVar1;
  char *in_EAX;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (*in_EAX != '\0') {
    piVar2 = (int *)(in_EAX + 4);
    iVar4 = 3;
    do {
      iVar3 = 0x28;
      do {
        iVar1 = *piVar2;
        piVar2 = piVar2 + 1;
        iVar3 = iVar3 + -1;
        *(undefined4 *)(iVar1 + 0x10) = 0;
      } while (iVar3 != 0);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}


// ==== 0x455c50 FUN_00455c50

void FUN_00455c50(int *param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  if (DAT_00700694 == 0) {
    if ((char)*param_1 == '\0') {
      return;
    }
    FUN_00455ae0(param_1);
  }
  else {
    if ((char)*param_1 != '\0') goto LAB_00455c9a;
    FUN_00455810(param_1);
  }
  if ((char)*param_1 == '\0') {
    return;
  }
LAB_00455c9a:
  iVar4 = 0;
  piVar3 = param_1;
  pcVar1 = param_2;
  do {
    piVar3 = piVar3 + 1;
    if ((iVar4 < param_2[0x1a0]) || (*param_2 <= iVar4)) {
      *(undefined4 *)(*piVar3 + 0x10) = 0;
    }
    else {
      local_18 = *(undefined4 *)(pcVar1 + 0x18);
      local_1c = *(undefined4 *)(pcVar1 + 0x14);
      local_20 = *(undefined4 *)(pcVar1 + 0x10);
      iVar2 = bAlmostEqual_float(local_18,0,0x3a83126f);
      if (iVar2 != 0) {
        FUN_00455760(&local_20);
      }
      FUN_00455b50(param_1,iVar4,0x3f99999a);
      iVar2 = *(int *)(*piVar3 + 8);
      *(int **)(iVar2 + 0x10) = param_1 + 0x7d;
      *(undefined4 *)(iVar2 + 0x14) = 1;
    }
    iVar4 = iVar4 + 1;
    pcVar1 = pcVar1 + 0x10;
  } while (iVar4 < 0x28);
  return;
}


// ==== 0x455d60 FUN_00455d60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00455d60(char *param_1,int param_2,int param_3)

{
  float fVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  int unaff_EDI;
  float10 fVar6;
  int local_330;
  int *local_32c;
  float fStack_328;
  float local_324;
  int local_31c;
  int local_318;
  undefined1 local_310 [8];
  float local_308;
  undefined1 local_300 [8];
  float local_2f8;
  undefined1 local_2f0 [8];
  float local_2e8;
  undefined1 local_2e0 [32];
  int aiStack_2c0 [160];
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  pcStack_18 = FUN_0068600b;
  local_1c = ExceptionList;
  if (DAT_00700698 == 0) {
    if (*param_1 == '\0') {
      return;
    }
    ExceptionList = &local_1c;
    FUN_00455ae0(param_1);
  }
  else {
    ExceptionList = &local_1c;
    if (*param_1 == '\0') {
      ExceptionList = &local_1c;
      FUN_00455810(param_1);
    }
  }
  if (*param_1 != '\0') {
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    FUN_00440740();
    piVar5 = (int *)(param_1 + 0x144);
    local_32c = (int *)(param_2 + 8);
    local_14 = 0;
    local_330 = 0;
    do {
      if (local_330 < *(int *)(param_2 + 4)) {
        piVar2 = (int *)*local_32c;
        local_324 = 1.2;
        if (param_3 == local_330) {
          iVar4 = *(int *)(piVar5[-0x50] + 8);
          pcVar3 = param_1 + 0x204;
          *(char **)(iVar4 + 0x10) = pcVar3;
          *(undefined4 *)(iVar4 + 0x14) = 1;
          iVar4 = *(int *)(piVar5[-0x28] + 8);
          *(char **)(iVar4 + 0x10) = pcVar3;
          *(undefined4 *)(iVar4 + 0x14) = 1;
          iVar4 = *(int *)(*piVar5 + 8);
          *(char **)(iVar4 + 0x10) = pcVar3;
          *(undefined4 *)(iVar4 + 0x14) = 1;
        }
        else {
          if ((char)piVar2[0x18] == '\0') {
            if ((unaff_EDI < 0) || (4 < unaff_EDI)) {
              if ((unaff_EDI < 0xb) || (0x10 < unaff_EDI)) {
                fVar1 = 0.0;
              }
              else {
                fVar1 = (float)piVar2[unaff_EDI + -9];
              }
            }
            else {
              fVar1 = (float)piVar2[1];
            }
            if (ABS(fVar1) < 0.001 == (ABS(fVar1) == 0.001)) {
              pcVar3 = param_1 + 0x214;
              local_324 = _K_BLUR_W_MUL * 1.2;
            }
            else {
              pcVar3 = param_1 + 500;
            }
          }
          else {
            pcVar3 = param_1 + 0x204;
            local_324 = 2.4;
          }
          iVar4 = *(int *)(*piVar5 + 8);
          *(char **)(iVar4 + 0x10) = pcVar3;
          *(undefined4 *)(iVar4 + 0x14) = 1;
          fVar6 = (float10)(**(code **)(*piVar2 + 8))();
          if (ABS((float10)local_324 - fVar6) < (float10)0.001 ==
              (ABS((float10)local_324 - fVar6) == (float10)0.001)) {
            iVar4 = *(int *)(piVar5[-0x50] + 8);
            *(char **)(iVar4 + 0x10) = param_1 + 0x214;
          }
          else {
            iVar4 = *(int *)(piVar5[-0x50] + 8);
            *(char **)(iVar4 + 0x10) = param_1 + 500;
          }
          *(undefined4 *)(iVar4 + 0x14) = 1;
          if ((unaff_EDI < 0) || (4 < unaff_EDI)) {
            if ((unaff_EDI < 0xb) || (0x10 < unaff_EDI)) {
              local_32c = (int *)0x0;
            }
            else {
              local_32c = (int *)piVar2[unaff_EDI + 5];
            }
          }
          else {
            local_32c = (int *)piVar2[0xf];
          }
          fVar6 = (float10)(**(code **)(*piVar2 + 0xc))();
          if (ABS((float10)fStack_328 - fVar6) < (float10)0.001 ==
              (ABS((float10)fStack_328 - fVar6) == (float10)0.001)) {
            iVar4 = *(int *)(piVar5[-0x28] + 8);
            *(char **)(iVar4 + 0x10) = param_1 + 0x214;
          }
          else {
            iVar4 = *(int *)(piVar5[-0x28] + 8);
            *(char **)(iVar4 + 0x10) = param_1 + 500;
          }
          *(undefined4 *)(iVar4 + 0x14) = 1;
        }
        if ((unaff_EDI < 0) || (4 < unaff_EDI)) {
          if ((unaff_EDI < 0xb) || (0x10 < unaff_EDI)) {
            local_318 = 0;
          }
          else {
            local_318 = piVar2[unaff_EDI + -2];
          }
        }
        else {
          local_318 = piVar2[8];
        }
        FUN_005a7270(local_2f0,piVar2[0x16],local_318,unaff_EDI);
        if ((unaff_EDI < 0) || (4 < unaff_EDI)) {
          if ((unaff_EDI < 0xb) || (0x10 < unaff_EDI)) {
            local_31c = 0;
          }
          else {
            local_31c = piVar2[unaff_EDI + 5];
          }
        }
        else {
          local_31c = piVar2[0xf];
        }
        FUN_005a7270(local_310,piVar2[0x16],local_31c,unaff_EDI);
        FUN_005a7270(local_300,piVar2[0x16],0,unaff_EDI);
        fVar6 = (float10)GroundQuery__FindSurfaceBelow(local_2e0,local_2f0,0,0,0);
        local_2e8 = (float)fVar6;
        fVar6 = (float10)GroundQuery__FindSurfaceBelow(local_2e0,local_300,0,0,0);
        local_2f8 = (float)fVar6;
        fVar6 = (float10)GroundQuery__FindSurfaceBelow(local_2e0,local_310,0,0,0);
        local_308 = (float)fVar6;
        FUN_00455b50(param_1,local_330,0x3f3851ec);
        FUN_00455b50(param_1,local_330,0x3f3851ec);
        FUN_00455b50(param_1,local_330,local_324);
      }
      else {
        *(undefined4 *)(piVar5[-0x50] + 0x10) = 0;
        *(undefined4 *)(piVar5[-0x28] + 0x10) = 0;
        *(undefined4 *)(*piVar5 + 0x10) = 0;
      }
      local_330 = local_330 + 1;
      local_32c = local_32c + 1;
      piVar5 = piVar5 + 1;
    } while (local_330 < 0x28);
    iVar4 = 0;
    if (0 < local_40) {
      do {
        piVar5 = aiStack_2c0 + iVar4;
        iVar4 = iVar4 + 1;
        *(char *)(*piVar5 + 8) = *(char *)(*piVar5 + 8) + -1;
      } while (iVar4 < local_40);
    }
  }
  ExceptionList = local_1c;
  return;
}


// ==== 0x4561a0 FUN_004561a0

void FUN_004561a0(void)

{
  undefined1 *in_EAX;
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(in_EAX + 0x1e4);
  iVar2 = 4;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1 = puVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *in_EAX = 0;
  return;
}


// ==== 0x4561d0 FUN_004561d0

undefined4 __thiscall
FUN_004561d0(float *param_1,undefined4 *param_2,uint param_3,undefined4 param_4)

{
  float fVar1;
  bool bVar2;
  int in_EAX;
  int *piVar3;
  int iVar4;
  float *pfVar5;
  float *extraout_EDX;
  int *piVar6;
  bool bVar7;
  float10 fVar8;
  float local_10;
  int *local_c;
  float *local_8;
  
  piVar6 = DAT_0077af20;
  bVar7 = DAT_0078a2fc == 0;
  local_8 = (float *)0x0;
  local_c = (int *)0x0;
  local_10 = 999999.0;
  bVar2 = false;
  if (((in_EAX != 0) && (in_EAX != 1)) && (bVar2 = true, in_EAX == 3)) {
    bVar7 = !bVar7;
  }
  if ((param_3 & 0x800) != 0) {
    local_10 = 48.0;
  }
  piVar3 = (int *)NullUpdate_ret();
  if (piVar6 != piVar3) {
    do {
      if (bVar2) {
        iVar4 = 0;
        do {
          if (*(char *)((int)piVar6 + iVar4 + (-(uint)bVar7 & 0xfffffffa) + 0x276) != '\0')
          goto LAB_00456273;
          iVar4 = iVar4 + 1;
        } while (iVar4 < 6);
      }
      else {
LAB_00456273:
        if ((char)param_3 < '\0') {
          iVar4 = 0;
          do {
            if (*(char *)((int)piVar6 + iVar4 + (-(uint)bVar7 & 0xfffffffa) + 0x276) != '\0')
            goto LAB_004562a1;
            iVar4 = iVar4 + 1;
          } while (iVar4 < 6);
        }
        else {
LAB_004562a1:
          if ((param_3 & 0x100) != 0) {
            iVar4 = 0;
            do {
              if (*(char *)((int)piVar6 + iVar4 + (-(uint)bVar7 & 0xfffffffa) + 0x276) != '\0')
              goto LAB_00456397;
              iVar4 = iVar4 + 1;
            } while (iVar4 < 6);
          }
          pfVar5 = (float *)FUN_00442690(piVar6,local_10,param_3,param_4);
          if (pfVar5 != (float *)0x0) {
            if ((param_3 & 0x20) == 0) {
              fVar8 = SQRT(((float10)*pfVar5 - (float10)*param_1) *
                           ((float10)*pfVar5 - (float10)*param_1) +
                           ((float10)pfVar5[1] - (float10)param_1[1]) *
                           ((float10)pfVar5[1] - (float10)param_1[1]));
            }
            else {
              fVar8 = (float10)FUN_004423b0(param_4);
              pfVar5 = extraout_EDX;
            }
            if ((param_3 & 0x40) != 0) {
              if (bVar7) {
                fVar1 = (*param_1 - *pfVar5) * pfVar5[4] - (param_1[1] - pfVar5[1]) * pfVar5[3];
                if (fVar1 <= 0.0) {
                  fVar1 = -(fVar1 + pfVar5[9]);
                }
                else {
                  fVar1 = fVar1 - pfVar5[10];
                }
              }
              else {
                fVar1 = (*param_1 - *pfVar5) * pfVar5[6] - (param_1[1] - pfVar5[1]) * pfVar5[5];
                if (0.0 <= fVar1) {
                  fVar1 = fVar1 - pfVar5[9];
                }
                else {
                  fVar1 = -(fVar1 + pfVar5[10]);
                }
              }
              if (0.0 <= fVar1) goto LAB_00456397;
            }
            if (fVar8 < (float10)local_10) {
              local_10 = (float)fVar8;
              local_c = piVar6;
              local_8 = pfVar5;
            }
          }
        }
      }
LAB_00456397:
      piVar6 = (int *)*piVar6;
    } while (piVar6 != piVar3);
    if ((local_c != (int *)0x0) && (local_8 != (float *)0x0)) {
      *param_2 = local_c;
      param_2[1] = local_8;
      return 1;
    }
  }
  return 0;
}


// ==== 0x4563d0 RoadGraph_Walk

/* WARNING: Removing unreachable block (ram,0x00456662) */
/* WARNING: Removing unreachable block (ram,0x00456573) */
/* WARNING: Removing unreachable block (ram,0x0045672b) */
/* WARNING: Removing unreachable block (ram,0x00456746) */
/* [canon] traffic med (H+C) docs/re/traffic.md */

undefined4 __thiscall
RoadGraph_Walk(int param_1,int *param_2,undefined4 param_3,float param_4,char param_5,char param_6)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  float *in_EAX;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  uint uVar9;
  int local_130;
  float local_128;
  int local_11c;
  
  if ((param_1 == 0) || (in_EAX == (float *)0x0)) {
    return 0;
  }
  local_128 = param_4;
  if (param_5 == '\0') {
    local_128 = in_EAX[7] + param_4;
  }
  local_11c = 1;
  local_130 = param_1;
LAB_00456452:
  local_128 = local_128 - in_EAX[7];
  if (local_128 < 0.0) {
    *param_2 = param_1;
    param_2[1] = (int)in_EAX;
    return 1;
  }
  bVar2 = false;
  iVar8 = 0;
  bVar3 = true;
LAB_0045649f:
  do {
    iVar5 = 0;
    do {
      if (*(char *)((int)in_EAX + iVar5 + 0x81) == -1) break;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
    if (iVar5 <= iVar8) goto LAB_00456674;
    uVar9 = (uint)*(byte *)((int)in_EAX + iVar8 + 0x81);
    if (uVar9 == 0xff) {
      iVar5 = 0;
    }
    else {
      iVar5 = uVar9 * 0x20 + DAT_00736150;
    }
    if (param_5 == '\0') {
      if (*(char *)(iVar5 + 0xd) == '\x01') goto LAB_004564fc;
LAB_00456615:
      iVar8 = iVar8 + 1;
      goto LAB_0045649f;
    }
    if (*(char *)(iVar5 + 0xd) != '\x01') {
LAB_004564fc:
      cVar1 = *(char *)(iVar5 + 0xb);
      bVar3 = false;
      if (cVar1 == '\x03') {
        local_128 = -1.0;
        goto LAB_00456674;
      }
      bVar4 = (byte)((uint)in_EAX[0x21] >> 0x19) & 1;
      param_1 = local_130;
      if (param_6 == '\0') {
        if (bVar4 != 0) {
          if (*(char *)(iVar5 + 0xc) == '\a') goto LAB_00456559;
          if (bVar4 != 0) {
            cVar1 = *(char *)(iVar5 + 0xc);
            goto LAB_00456538;
          }
        }
      }
      else if (((uint)in_EAX[0x21] >> 6 & 1) != 0) {
        if (cVar1 == '\a') {
LAB_00456559:
          bVar3 = true;
          iVar8 = iVar8 + 1;
          goto LAB_0045649f;
        }
LAB_00456538:
        if (cVar1 == '\x02') break;
      }
      FUN_00442110();
      iVar6 = FUN_00442630();
      if (iVar6 != 0) {
        Vec3Ring20__PushFront();
      }
      if (*(char *)(iVar5 + 0xb) != '\0') {
        Vec3Ring20__PushBack();
        bVar3 = false;
        bVar2 = true;
        goto LAB_00456615;
      }
      Vec3Ring20__PushFront();
      bVar2 = true;
      iVar8 = iVar8 + 1;
      bVar3 = false;
      goto LAB_0045649f;
    }
    iVar8 = iVar8 + 1;
  } while( true );
  pfVar7 = (float *)FUN_00442110();
  local_128 = (local_128 + in_EAX[7]) -
              ((*pfVar7 - *in_EAX) * in_EAX[3] + (pfVar7[1] - in_EAX[1]) * in_EAX[4]);
  param_1 = (&DAT_0077af30)[*(byte *)(iVar5 + 9)];
  bVar3 = false;
  in_EAX = pfVar7;
  local_130 = param_1;
LAB_00456674:
  if (bVar2) {
    in_EAX = (float *)0x0;
  }
  if (bVar3) {
    iVar8 = (int)in_EAX + (-0x27c - param_1);
    if (param_5 == '\0') {
      iVar8 = iVar8 / 0x88;
      if (iVar8 != 0) {
        in_EAX = (float *)(iVar8 * 0x88 + 500 + param_1);
        goto LAB_004566e9;
      }
    }
    else {
      iVar8 = iVar8 / 0x88;
      if (iVar8 + 1 < (int)*(short *)(param_1 + 0x10)) {
        in_EAX = (float *)(iVar8 * 0x88 + 0x304 + param_1);
        goto LAB_004566e9;
      }
    }
    in_EAX = (float *)0x0;
  }
LAB_004566e9:
  if (in_EAX == (float *)0x0) {
    return 0;
  }
  if (param_5 == '\0') {
    iVar8 = Node_IsDriveBack();
  }
  else {
    iVar8 = Node_IsDriveFwd();
  }
  if (iVar8 == 0) {
    return 0;
  }
  local_11c = local_11c + 1;
  if (0x19000 < local_11c) {
    return 0;
  }
  goto LAB_00456452;
}


// ==== 0x456780 FUN_00456780

uint FUN_00456780(int param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  uint in_EAX;
  uint uVar5;
  int iVar6;
  undefined2 uVar8;
  uint3 uVar7;
  int *unaff_ESI;
  bool bVar9;
  
  uVar5 = in_EAX & 0xffffff00;
  if ((param_1 != 0) &&
     (iVar2 = *(int *)(param_1 + 0x34), *(int *)(iVar2 + 0x1d4) != *(int *)(*unaff_ESI + 0x82c))) {
    iVar4 = unaff_ESI[0xe2];
    iVar6 = FUN_00647b70();
    if ((iVar6 == 6) &&
       (iVar2 = *(int *)(*(int *)(iVar2 + 0x1d4) + 0x90),
       bVar9 = *(int *)(*(int *)(iVar2 + 0x14) + 4) == 1,
       iVar6 = CONCAT31((int3)((uint)iVar2 >> 8),bVar9), uVar8 = (undefined2)((uint)iVar2 >> 0x10),
       bVar9)) {
      fVar1 = -0.5;
    }
    else {
      uVar8 = (undefined2)((uint)iVar6 >> 0x10);
      fVar1 = 0.0;
    }
    fVar3 = *(float *)(param_1 + 0x10) - (float)unaff_ESI[(char)unaff_ESI[0xe2] * 0xe + 6];
    fVar1 = -((float)unaff_ESI[(char)iVar4 * 0xe + 5] + *(float *)(param_1 + 0xc) + fVar1);
    uVar7 = (uint3)(CONCAT22(uVar8,(ushort)(fVar1 < fVar3) << 8 |
                                   (ushort)(NAN(fVar1) || NAN(fVar3)) << 10 |
                                   (ushort)(fVar1 == fVar3) << 0xe) >> 8);
    if (fVar1 < fVar3) {
      return CONCAT31(uVar7,1);
    }
    uVar5 = (uint)uVar7 << 8;
  }
  return uVar5;
}


// ==== 0x456830 FUN_00456830

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00456830(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float10 fVar5;
  float local_28;
  
  iVar3 = *(int *)(param_1 + 0x20);
  param_2 = param_2 / *(float *)(param_1 + 0x404);
  if (*(char *)(*(int *)(param_1 + 0x10) + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  fVar5 = (float10)FUN_00583ea0(param_2);
  local_28 = (float)fVar5;
  fVar4 = ((_K_ONE - *(float *)(param_1 + 0x47c)) * *(float *)(iVar3 + 0x260) * param_2 * param_2) /
          *(float *)(iVar3 + 0x110);
  fVar1 = *(float *)(*(int *)(param_1 + 0x10) + 0x42c);
  if (((0.0 < fVar1) && (fVar1 <= param_2)) && (fVar4 < local_28)) {
    local_28 = fVar4;
  }
  if (*(int *)(param_1 + 0x28) != 4) {
    fVar1 = *(float *)(param_1 + 0x78);
    fVar2 = *(float *)(param_1 + 0x98);
    bNormalize3();
    return ((float10)local_28 - (float10)fVar4) +
           -((float10)_DAT_007000ac * (float10)(fVar2 + fVar1));
  }
  fVar5 = (float10)FUN_004638a0();
  return ((float10)local_28 - (float10)fVar4) + fVar5;
}


// ==== 0x456960 FUN_00456960

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00456960(float param_1)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(in_EAX + 0x20);
  return -((((float10)*(float *)(iVar1 + 0xfc) + (float10)*(float *)(iVar1 + 0xdc)) *
            (float10)_K_HALF *
           ((float10)_DAT_007000ac * (float10)*(float *)(iVar1 + 0x110) +
           ((float10)*(float *)(iVar1 + 0x268) + (float10)*(float *)(iVar1 + 0x264)) *
           ABS((float10)param_1) * (float10)_K_HALF)) / (float10)*(float *)(iVar1 + 0x110));
}


// ==== 0x4569b0 FUN_004569b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004569b0(int param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  float *pfVar2;
  float10 fVar3;
  
  fVar1 = *(float *)(param_1 + 0x80) * *(float *)(param_1 + 0x90) +
          *(float *)(param_1 + 0x84) * *(float *)(param_1 + 0x94) +
          *(float *)(param_1 + 0x88) * *(float *)(param_1 + 0x98);
  if (param_4 < 0.0) {
    FUN_00456830(param_1,*(undefined4 *)(param_1 + 0x3d4));
  }
  pfVar2 = (float *)FUN_00578730();
  if (*(float *)(param_1 + 0x90) * *pfVar2 + *(float *)(param_1 + 0x94) * pfVar2[1] <= 0.0) {
    fVar3 = (float10)FUN_0057a5f0();
    fVar3 = fVar3 + (float10)fVar1;
  }
  else {
    fVar3 = (float10)FUN_0057a5f0();
    fVar3 = (float10)fVar1 - fVar3;
  }
  if ((float10)param_2 <
      ((float10)_DAT_007006f0 * fVar3 * (float10)_K_HALF + (float10)param_3) *
      (float10)_DAT_007006f0) {
    return 1;
  }
  return 0;
}


// ==== 0x456a80 FUN_00456a80

void FUN_00456a80(float param_1)

{
  float fVar1;
  float fVar2;
  int unaff_ESI;
  float *unaff_EDI;
  
  Angle16SinCos();
  fVar1 = *(float *)(unaff_ESI + 0x68);
  fVar2 = *(float *)(unaff_ESI + 0x60);
  if (param_1 < 5.0) {
    param_1 = 5.0;
  }
  unaff_EDI[1] = param_1 * 0.0 + *(float *)(unaff_ESI + 100);
  *unaff_EDI = param_1 * 0.0 + fVar2;
  unaff_EDI[2] = param_1 * 0.0 + fVar1;
  return;
}


// ==== 0x456b20 FUN_00456b20

void FUN_00456b20(float param_1)

{
  float fVar1;
  float fVar2;
  int unaff_ESI;
  float *unaff_EDI;
  float local_34;
  float local_20;
  float local_1c;
  float local_18;
  
  if (5.0 <= param_1) {
    local_34 = param_1;
  }
  else {
    local_34 = 5.0;
  }
  FUN_005673e0(local_34);
  fVar1 = *(float *)(unaff_ESI + 0x60);
  fVar2 = *(float *)(unaff_ESI + 100);
  unaff_EDI[2] = local_18 + *(float *)(unaff_ESI + 0x68);
  *unaff_EDI = fVar1 + local_20;
  unaff_EDI[1] = local_1c + fVar2;
  return;
}


// ==== 0x456ba0 FUN_00456ba0

void FUN_00456ba0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = DAT_007361f8;
  if ((DAT_007361f8 != 0) && (DAT_0073619c != 0)) {
    if (DAT_0078a320 == 2) {
      iVar6 = (int)*(char *)(*(int *)(*(int *)(DAT_007361b4 + 4) + 0x1c) + 10);
      iVar7 = (int)*(char *)(*(int *)(*(int *)(DAT_007361b8 + 4) + 0x1c) + 10);
      iVar4 = (int)*(char *)(DAT_007361b8 + 0x22);
      iVar5 = (int)*(char *)(DAT_007361b4 + 0x22);
      if (iVar7 < iVar6) {
        iVar4 = (int)*(char *)(DAT_007361b4 + 0x22);
        iVar5 = (int)*(char *)(DAT_007361b8 + 0x22);
      }
      iVar3 = DAT_0078a324 / 2;
      if (iVar6 <= iVar3) {
        iVar3 = iVar3 + 1;
      }
      if (iVar7 <= iVar3) {
        iVar3 = iVar3 + 1;
      }
      iVar6 = *(int *)(DAT_007361f8 + 0x1c);
      iVar7 = 0;
      if (*(int *)(DAT_007361f8 + 0x20) != iVar6 && -1 < *(int *)(DAT_007361f8 + 0x20) - iVar6) {
        do {
          iVar6 = *(int *)(iVar2 + 0x28 + (iVar6 + iVar7) * 4);
          if (iVar3 < *(char *)(*(int *)(iVar6 + 0x1c) + 10)) {
            *(int *)(iVar6 + 0x400) = iVar4;
          }
          else {
            *(int *)(iVar6 + 0x400) = iVar5;
          }
          iVar6 = *(int *)(iVar2 + 0x1c);
          iVar7 = iVar7 + 1;
        } while (iVar7 < *(int *)(iVar2 + 0x20) - iVar6);
        return;
      }
    }
    else {
      cVar1 = *(char *)(DAT_007361bc + 0x22);
      iVar4 = *(int *)(DAT_007361f8 + 0x1c);
      iVar5 = 0;
      if (*(int *)(DAT_007361f8 + 0x20) != iVar4 && -1 < *(int *)(DAT_007361f8 + 0x20) - iVar4) {
        do {
          *(int *)(*(int *)(iVar2 + 0x28 + (iVar4 + iVar5) * 4) + 0x400) = (int)cVar1;
          iVar4 = *(int *)(iVar2 + 0x1c);
          iVar5 = iVar5 + 1;
        } while (iVar5 < *(int *)(iVar2 + 0x20) - iVar4);
      }
    }
  }
  return;
}


// ==== 0x456c90 FUN_00456c90

undefined4 FUN_00456c90(void)

{
  int iVar1;
  int iVar2;
  int *in_EAX;
  
  iVar1 = *in_EAX;
  if ((((iVar1 != 0) && (in_EAX[1] != 0)) && (-1 < *(short *)(iVar1 + 10))) &&
     (((*(short *)(iVar1 + 10) < 0x78 && (iVar2 = ((in_EAX[1] - iVar1) + -0x27c) / 0x88, -1 < iVar2)
       ) && (iVar2 < *(short *)(iVar1 + 0x10))))) {
    return 1;
  }
  return 0;
}


// ==== 0x456ce0 FUN_00456ce0

void FUN_00456ce0(void)

{
  undefined2 uVar1;
  float fVar2;
  int unaff_ESI;
  float10 fVar3;
  float local_8;
  
  local_8 = DAT_00700680;
  fVar2 = *(float *)((*(int **)(unaff_ESI + 0x2c))[1] + 0x3d4);
  uVar1 = *(undefined2 *)(unaff_ESI + 0x3b4);
  fVar3 = (float10)(**(code **)(**(int **)(unaff_ESI + 0x2c) + 0x50))();
  fVar3 = fVar3 * (float10)fVar2;
  if (fVar3 <= (float10)local_8) {
  }
  else {
    local_8 = (float)fVar3;
  }
  FUN_00456de0(local_8,uVar1);
  return;
}


// ==== 0x456d50 FUN_00456d50

void FUN_00456d50(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EDI;
  float10 fVar4;
  
  if (*(int *)(*(int *)(*(int *)(unaff_EDI + 0x1d4) + 0x1c) + 0xe4) != 0) {
    FUN_005791c0();
  }
  if (*(int *)(*(int *)(*(int *)(unaff_EDI + 0x1d4) + 0x1c) + 0xe4) != 0) {
    FUN_005791c0();
  }
  puVar1 = (undefined4 *)FUN_00578730();
  iVar2 = FUN_00578730();
  uVar3 = Atan2ToAngle16(*puVar1,*(undefined4 *)(iVar2 + 4));
  fVar4 = (float10)FUN_0057a820(uVar3);
  FUN_00456de0((float)fVar4);
  return;
}


// ==== 0x456de0 FUN_00456de0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00456de0(undefined4 param_1,float *param_2)

{
  if (_K_ONE <= SQRT(param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2)) {
    bNormalize3();
  }
  else {
    Angle16SinCos();
  }
  FUN_00458f10(0,0);
  FUN_004594d0(0xffffffff,0xffffffff,0xffffffff,0);
  return;
}


// ==== 0x456e90 GetNearestTrafficLane

/* WARNING: Removing unreachable block (ram,0x00456ec0) */
/* [canon] runtime high (ghidra-canon+nfsug) docs/re/runtime.md */

uint __thiscall
GetNearestTrafficLane(float *param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  float *in_EAX;
  uint uVar5;
  short *psVar6;
  float local_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  if (in_EAX == (float *)0x0) {
    return 0xffffffff;
  }
  local_c = 9e+09;
  if (param_3 == 0) {
    uVar5 = 0xb;
    fVar2 = (*param_1 - *in_EAX) * in_EAX[4] - (param_1[1] - in_EAX[1]) * in_EAX[3];
  }
  else {
    uVar5 = 0x11;
    fVar2 = (*param_1 - *in_EAX) * in_EAX[6] - (param_1[1] - in_EAX[1]) * in_EAX[5];
    if (param_4 != 0xff) {
      param_4 = param_4 + 6;
    }
    if (param_5 != 0xff) {
      param_5 = param_5 + 6;
    }
  }
  uVar1 = uVar5 + 6;
  if ((param_4 == 0xff) || (param_5 == 0xff)) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  if (uVar5 < uVar1) {
    psVar6 = (short *)((int)in_EAX + uVar5 * 2 + 0x3c);
    do {
      if (((*(char *)((&DAT_0077af30)[*(byte *)((int)in_EAX + 0x83)] + 0x265 + uVar5) != '\0') &&
          (((bVar4 || ((int)uVar5 < param_4)) || (param_5 < (int)uVar5)))) &&
         (fVar3 = ABS((float)((int)*psVar6 << 8) * 1.5258789e-05 - fVar2), fVar3 < local_c)) {
        local_c = fVar3;
        local_8 = uVar5;
      }
      uVar5 = uVar5 + 1;
      psVar6 = psVar6 + 1;
    } while ((int)uVar5 < (int)uVar1);
    if ((local_8 != 0xffffffff) && (param_3 == 1)) {
      return local_8 - 6;
    }
  }
  else {
    local_8 = 0xffffffff;
  }
  return local_8;
}


// ==== 0x456fe0 IsForwardsTrafficLane

/* [canon] traffic med (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 IsForwardsTrafficLane(void)

{
  int in_EAX;
  
  if ((10 < in_EAX) && (in_EAX < 0x11)) {
    return 1;
  }
  return 0;
}


// ==== 0x457000 FUN_00457000

undefined4 FUN_00457000(void)

{
  int in_EAX;
  
  if ((10 < in_EAX) && (in_EAX < 0x17)) {
    return 1;
  }
  return 0;
}


// ==== 0x457020 FUN_00457020

undefined4 FUN_00457020(void)

{
  int in_EAX;
  
  if (((in_EAX < 0) || (4 < in_EAX)) && ((in_EAX < 0xb || (0x10 < in_EAX)))) {
    return 0;
  }
  return 1;
}


// ==== 0x457040 FUN_00457040

int FUN_00457040(void)

{
  int in_EAX;
  
  if (in_EAX < 5) {
    return in_EAX + 5;
  }
  if ((10 < in_EAX) && (in_EAX < 0x11)) {
    in_EAX = in_EAX + 6;
  }
  return in_EAX;
}


// ==== 0x457060 FUN_00457060

void FUN_00457060(int *param_1)

{
  int iVar1;
  int *piVar2;
  int unaff_EDI;
  
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 4))();
    if (iVar1 == unaff_EDI) {
      return;
    }
    (**(code **)*piVar2)(1);
  }
  if (unaff_EDI == 0) {
    iVar1 = FUN_00567160();
    if (iVar1 != 0) {
      iVar1 = FUN_00455270();
      *param_1 = iVar1;
      return;
    }
  }
  else {
    if (unaff_EDI != 1) goto LAB_004570be;
    iVar1 = FUN_00567160();
    if (iVar1 != 0) {
      iVar1 = FUN_00455390();
      *param_1 = iVar1;
      return;
    }
  }
  piVar2 = (int *)0x0;
LAB_004570be:
  *param_1 = (int)piVar2;
  return;
}


// ==== 0x4570d0 FUN_004570d0

float10 FUN_004570d0(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int in_EAX;
  float10 fVar4;
  
  fVar4 = (float10)99999.0;
  fVar1 = *(float *)(in_EAX + 0x3d4);
  fVar2 = *(float *)(in_EAX + 0x80) * *(float *)(in_EAX + 0x90) +
          *(float *)(in_EAX + 0x84) * *(float *)(in_EAX + 0x94) +
          *(float *)(in_EAX + 0x88) * *(float *)(in_EAX + 0x98);
  if (ABS(fVar2) < 0.001 == (ABS(fVar2) == 0.001)) {
    fVar4 = (float10)0.0;
    fVar3 = fVar2 * param_1 + fVar2 * param_1 + fVar1 * fVar1;
    if (0.0 < fVar3) {
      fVar4 = SQRT((float10)fVar3);
    }
    return (fVar4 - (float10)fVar1) / (float10)fVar2;
  }
  if (ABS(fVar1) < 0.001 == (ABS(fVar1) == 0.001)) {
    fVar4 = (float10)param_1 / (float10)fVar1;
  }
  return fVar4;
}


// ==== 0x457180 bSegmentsIntersect2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] traffic med (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 __fastcall bSegmentsIntersect2(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *in_EAX;
  
  fVar1 = *param_2 - *param_3;
  fVar6 = in_EAX[1] - param_1[1];
  fVar2 = param_2[1] - param_3[1];
  fVar7 = *in_EAX - *param_1;
  fVar5 = fVar6 * fVar1 - fVar7 * fVar2;
  fVar3 = ABS(fVar5);
  if (fVar3 < 0.0001) {
    return CONCAT22((short)((uint)in_EAX[1] >> 0x10),
                    (ushort)(fVar3 < 0.0001) << 8 | (ushort)NAN(fVar3) << 10 |
                    (ushort)(fVar3 == 0.0001) << 0xe);
  }
  fVar3 = param_3[1] - param_1[1];
  fVar4 = *param_3 - *param_1;
  fVar5 = _K_ONE / fVar5;
  fVar6 = (fVar3 * fVar7 - fVar4 * fVar6) * fVar5;
  fVar5 = (fVar3 * fVar1 - fVar4 * fVar2) * fVar5;
  if (fVar6 <= 0.0) {
    fVar1 = 0.0;
  }
  else {
    fVar1 = fVar6;
    if (_K_ONE < fVar6) {
      fVar1 = _K_ONE;
    }
  }
  if (fVar6 == fVar1) {
    if (fVar5 <= 0.0) {
      fVar1 = 0.0;
    }
    else {
      fVar1 = fVar5;
      if (_K_ONE < fVar5) {
        fVar1 = _K_ONE;
      }
    }
    if (fVar5 == fVar1) {
      return 1;
    }
  }
  return 0;
}


// ==== 0x457300 FUN_00457300

undefined4 __thiscall FUN_00457300(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  char cVar2;
  int in_EAX;
  int *piVar3;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (in_EAX == -1) {
    in_EAX = FUN_005a6150(param_1,param_2,1);
  }
  if (param_4 == -1) {
    param_4 = FUN_005a6150(param_1,param_3,2);
  }
  if (((in_EAX != -1) && (param_4 != -1)) && (in_EAX <= param_4)) {
    piVar3 = (int *)(param_1 + 8 + in_EAX * 4);
    while( true ) {
      iVar1 = *piVar3;
      FUN_005a7270(&local_30,*(undefined4 *)(iVar1 + 0x58),*(undefined4 *)(iVar1 + 0x20),0);
      local_40 = local_30;
      local_3c = local_2c;
      FUN_005a7270(&local_20,*(undefined4 *)(iVar1 + 0x58),*(undefined4 *)(iVar1 + 0x3c),0);
      local_38 = local_20;
      local_34 = local_1c;
      cVar2 = bSegmentsIntersect2(&local_40);
      if (cVar2 == '\0') break;
      in_EAX = in_EAX + 1;
      piVar3 = piVar3 + 1;
      if (param_4 < in_EAX) {
        return 1;
      }
    }
  }
  return 0;
}


// ==== 0x4573f0 Vec3Ring20::PushBack

/* [canon] traffic med (ghidra-canon) docs/re/canon.md */

void __fastcall Vec3Ring20__PushBack(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int in_EAX;
  int iVar2;
  
  if (*(char *)(in_EAX + 0xf8) == '\0') {
    puVar1 = (undefined4 *)(in_EAX + *(int *)(in_EAX + 0xf4) * 0xc);
    *puVar1 = *param_2;
    puVar1[1] = param_2[1];
    puVar1[2] = param_2[2];
    iVar2 = *(int *)(in_EAX + 0xf4) + 1;
    *(int *)(in_EAX + 0xf4) = iVar2;
    if (iVar2 == 0x14) {
      *(undefined4 *)(in_EAX + 0xf4) = 0;
    }
    *(bool *)(in_EAX + 0xf8) = *(int *)(in_EAX + 0xf4) == *(int *)(in_EAX + 0xf0);
  }
  return;
}


// ==== 0x457450 Vec3Ring20::PushFront

/* [canon] traffic med (ghidra-canon) docs/re/canon.md */

void Vec3Ring20__PushFront(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 *unaff_ESI;
  
  if (*(char *)(in_EAX + 0xf8) == '\0') {
    if (*(int *)(in_EAX + 0xf0) == 0) {
      *(undefined4 *)(in_EAX + 0xf0) = 0x13;
    }
    else {
      *(int *)(in_EAX + 0xf0) = *(int *)(in_EAX + 0xf0) + -1;
    }
    *(bool *)(in_EAX + 0xf8) = *(int *)(in_EAX + 0xf4) == *(int *)(in_EAX + 0xf0);
    puVar1 = (undefined4 *)(in_EAX + *(int *)(in_EAX + 0xf0) * 0xc);
    *puVar1 = *unaff_ESI;
    puVar1[1] = unaff_ESI[1];
    puVar1[2] = unaff_ESI[2];
  }
  return;
}


// ==== 0x4574b0 FUN_004574b0

undefined4 __fastcall FUN_004574b0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int in_EAX;
  int iVar2;
  
  if ((*(char *)(in_EAX + 0xf8) == '\0') && (*(int *)(in_EAX + 0xf4) == *(int *)(in_EAX + 0xf0))) {
    return 0;
  }
  puVar1 = (undefined4 *)(in_EAX + *(int *)(in_EAX + 0xf0) * 0xc);
  *param_2 = *puVar1;
  param_2[1] = puVar1[1];
  param_2[2] = puVar1[2];
  iVar2 = *(int *)(in_EAX + 0xf0) + 1;
  *(int *)(in_EAX + 0xf0) = iVar2;
  if (iVar2 == 0x14) {
    *(undefined4 *)(in_EAX + 0xf0) = 0;
  }
  *(undefined1 *)(in_EAX + 0xf8) = 0;
  return 1;
}


// ==== 0x457520 FUN_00457520

float10 FUN_00457520(void)

{
  int iVar1;
  int in_EAX;
  float *pfVar2;
  
  iVar1 = *(int *)(*(int *)(in_EAX + 0x1d4) + 0x1c);
  if (*(int *)(iVar1 + 0xe4) != 0) {
    FUN_005791c0();
  }
  pfVar2 = (float *)FUN_00578730();
  return (float10)*(float *)(iVar1 + 0x90) * (float10)*pfVar2 +
         (float10)*(float *)(iVar1 + 0x94) * (float10)pfVar2[1] +
         (float10)*(float *)(iVar1 + 0x98) * (float10)pfVar2[2];
}


// ==== 0x457570 FUN_00457570

undefined4 FUN_00457570(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x3f8) != 0) {
    return *(undefined4 *)(*(int *)(in_EAX + 0x3f8) + 0x1f8);
  }
  return 0x14;
}


// ==== 0x457590 FUN_00457590

int FUN_00457590(undefined4 param_1,char *param_2,int *param_3,undefined4 param_4,
                undefined4 *param_5)

{
  int iVar1;
  float fVar2;
  int *piVar3;
  undefined4 uVar4;
  char cVar5;
  int *in_EAX;
  int *piVar6;
  int *local_10;
  int local_c;
  int local_8;
  
  uVar4 = param_4;
  piVar3 = param_3;
  local_8 = 0;
  local_10 = (int *)0x47c34f80;
  if ((((param_3 != (int *)0x0) && (*param_3 != 0)) && ('\0' < *param_2)) && (*param_2 < '\x15')) {
    iVar1 = *(int *)(*(int *)(*in_EAX + 0x2c) + 1000);
    local_c = 0;
    if (0 < in_EAX[1]) {
      piVar6 = in_EAX + 0xf;
      do {
        cVar5 = FUN_00456780(piVar6 + -0xd);
        if (cVar5 != '\0') {
          param_3 = (int *)0x449a4000;
          fVar2 = ABS(*(float *)(*in_EAX + 0x3d4));
          if (((fVar2 < 0.001 == (fVar2 == 0.001)) && (*piVar6 != iVar1)) &&
             ((cVar5 = FUN_004576b0(param_1,param_2,piVar3,*in_EAX,uVar4,&param_3), cVar5 != '\0' &&
              ((float)param_3 < (float)local_10)))) {
            local_8 = *piVar6;
            local_10 = param_3;
          }
          *(int *)(DAT_007361f8 + 0x2f4) = *(int *)(DAT_007361f8 + 0x2f4) + 1;
        }
        local_c = local_c + 1;
        piVar6 = piVar6 + 0xe;
      } while (local_c < in_EAX[1]);
    }
    *param_5 = local_10;
    return local_8;
  }
  return 0;
}


// ==== 0x4576b0 FUN_004576b0

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_004576b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
            float param_6,float *param_7)

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
  int iVar17;
  int iVar18;
  float *pfVar19;
  float10 fVar20;
  float fStack_10e0;
  int local_10d8;
  undefined4 uStack_10d4;
  float fStack_10d0;
  float fStack_10cc;
  float *local_10c8;
  float local_10c4;
  float fStack_10c0;
  float fStack_10bc;
  float fStack_10b8;
  float *pfStack_10b0;
  float fStack_10ac;
  float fStack_10a8;
  float fStack_1090;
  float fStack_108c;
  float fStack_1088;
  float fStack_1084;
  float fStack_1040;
  float fStack_103c;
  undefined4 uStack_1038;
  undefined4 uStack_1034;
  float fStack_1030;
  float fStack_102c;
  undefined4 uStack_1028;
  undefined4 uStack_1024;
  char local_1020 [448];
  char local_e60 [448];
  float afStack_ca0 [400];
  float afStack_660 [399];
  undefined4 uStack_24;
  int iStack_20;
  void *pvStack_1c;
  code *pcStack_18;
  int iStack_14;
  
  iStack_14 = 0xffffffff;
  pcStack_18 = FUN_0068618c;
  pvStack_1c = ExceptionList;
  uStack_24 = 0x4576d6;
  local_10c4 = 99999.0;
  ExceptionList = &pvStack_1c;
  iStack_20 = param_1;
  FUN_00458150(param_3);
  FUN_00458150(param_1 + 0x10);
  iVar17 = FUN_00647b70();
  if (iVar17 == 6) {
    iVar17 = 0;
    iVar18 = FUN_00647b70();
    if (iVar18 == 6) {
      iVar17 = *(int *)(*(int *)(param_1 + 0x1d4) + 0x90);
    }
    iVar17 = *(int *)(iVar17 + 0x24);
    if (((iVar17 == 3) || (iVar17 == 2)) || (iVar17 == 4)) {
      local_10d8 = 0;
      iVar17 = FUN_00647b70();
      if (iVar17 == 6) {
        local_10d8 = *(int *)(*(int *)(*(int *)(param_1 + 0x1d4) + 0x90) + 0x2c);
      }
      goto LAB_0045777e;
    }
  }
  local_10d8 = 0;
LAB_0045777e:
  if ((*(int *)(*(int *)(param_5 + 0x14) + 4) != 3) ||
     (fVar20 = (float10)(**(code **)(**(int **)(param_5 + 0x2c) + 0x28))(), fVar20 <= (float10)-0.25
     )) {
    if (*(int *)(*(int *)(param_5 + 0x14) + 4) != 1) {
      DriveTarget__GetFirstPoint(*(undefined4 *)(param_5 + 0x3d0),param_5 + 0x60,param_5 + 0x70);
      FUN_0045a5b0(param_5 + 0x60,param_5 + 0x80);
    }
  }
  else {
    FUN_0045a1e0(local_1020);
  }
  iVar17 = FUN_00647b70();
  if ((iVar17 == 6) &&
     (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x1d4) + 0x90) + 0x14) + 4) == 3)) {
    iVar17 = 0;
    iVar18 = FUN_00647b70();
    if (iVar18 == 6) {
      iVar17 = *(int *)(*(int *)(param_1 + 0x1d4) + 0x90);
    }
    fVar20 = (float10)(**(code **)(**(int **)(iVar17 + 0x2c) + 0x28))();
    if (fVar20 <= (float10)-0.25) {
      if ((local_10d8 != 0) &&
         ((*(int *)(local_10d8 + 0x3f8) == 0 ||
          (*(int *)(*(int *)(local_10d8 + 0x3f8) + 0x1f8) != 7)))) {
        FUN_0045a510(local_e60);
      }
    }
    else {
      FUN_0045a250(local_e60);
    }
  }
  FUN_00647b70();
  fStack_10e0 = 1.0;
  if (((*(int *)(param_5 + 0x24) != 4) && (iVar17 = FUN_00647b70(), iVar17 == 6)) &&
     (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x1d4) + 0x90) + 0x14) + 4) == 3)) {
    fStack_10e0 = 1.3;
  }
  uStack_10d4 = 0x3f800000;
  iVar17 = *(int *)(*(int *)(param_1 + 0x1d4) + 0x1c);
  fStack_10cc = *(float *)(param_5 + 0x3d4);
  if (*(int *)(iVar17 + 0xe4) != 0) {
    FUN_005791c0();
  }
  fStack_10d0 = SQRT(*(float *)(iVar17 + 0x98) * *(float *)(iVar17 + 0x98) +
                     *(float *)(iVar17 + 0x94) * *(float *)(iVar17 + 0x94) +
                     *(float *)(iVar17 + 0x90) * *(float *)(iVar17 + 0x90));
  fVar1 = *(float *)(param_5 + 0x88);
  fVar2 = *(float *)(param_5 + 0x98);
  fVar3 = *(float *)(param_5 + 0x84);
  fVar4 = *(float *)(param_5 + 0x94);
  fVar5 = *(float *)(param_5 + 0x80);
  fVar6 = *(float *)(param_5 + 0x90);
  FUN_0057a5f0();
  if (*(float *)(param_5 + 0x3d0) < 0.0) {
    iVar17 = *(int *)(*(int *)(param_5 + 0x2c) + 0x3f8);
    if (iVar17 == 0) {
      iVar17 = 0x14;
    }
    else {
      iVar17 = *(int *)(iVar17 + 0x1f8);
    }
    if (((iVar17 == 10) || (iVar17 == 0x14)) || ((iVar17 == 0xe || (local_1020[0] == '\0')))) {
      FUN_00456ce0(local_1020);
      fStack_10cc = ABS(fStack_10cc);
      uStack_10d4 = 0x3fa66666;
    }
  }
  fVar20 = (float10)FUN_00457520();
  if ((fVar20 < (float10)0.0) &&
     ((((iVar17 = FUN_00647b70(), iVar17 == 6 &&
        (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x1d4) + 0x90) + 0x14) + 4) == 2)) ||
       ((iVar17 = FUN_00647b70(), iVar17 == 6 &&
        (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x1d4) + 0x90) + 0x14) + 4) == 3)))) &&
      (local_10d8 != 0)))) {
    if (*(int *)(local_10d8 + 0x3f8) == 0) {
      iVar17 = 0x14;
    }
    else {
      iVar17 = *(int *)(*(int *)(local_10d8 + 0x3f8) + 0x1f8);
    }
    if ((((iVar17 == 10) || (iVar17 == 0x14)) || (iVar17 == 0xe)) || (local_e60[0] == '\0')) {
      FUN_00456d50(local_e60);
      fStack_10d0 = ABS(fStack_10d0);
      fStack_10e0 = 1.3;
    }
  }
  if (fStack_10cc <= 0.001) {
    fStack_10cc = 0.001;
  }
  if (fStack_10d0 <= 0.001) {
    fStack_10d0 = 0.001;
  }
  if (fStack_10cc < 2.0) {
    uStack_10d4 = 0x3f800000;
  }
  if (fStack_10d0 < 2.0) {
    fStack_10e0 = 1.0;
  }
  eh_vector_constructor_iterator(afStack_660,0x50,0x14,FUN_0045a920,NullUpdate_ret);
  iStack_14 = 0;
  eh_vector_constructor_iterator(afStack_ca0,0x50,0x14,FUN_0045a920,NullUpdate_ret);
  iStack_14 = CONCAT31(iStack_14._1_3_,1);
  FUN_00458220(param_2,local_1020,uStack_10d4);
  FUN_00458290(param_2,local_e60,afStack_ca0,fStack_10e0);
  fStack_10b8 = 0.0;
  iVar18 = DriveTarget__GetFirstPoint
                     (*(undefined4 *)(param_5 + 0x3d0),(float *)(param_5 + 0x60),param_5 + 0x70);
  local_10d8 = FUN_004596b0(local_e60,param_1);
  fStack_10ac = *(float *)(param_5 + 0x60);
  fStack_10a8 = *(float *)(param_5 + 100);
  iVar17 = *(int *)(*(int *)(param_1 + 0x1d4) + 0x1c);
  if (*(int *)(iVar17 + 0xe4) != 0) {
    FUN_005791c0();
  }
  fStack_10bc = *(float *)(iVar17 + 0x44);
  fStack_10c0 = *(float *)(iVar17 + 0x40);
  fStack_1084 = afStack_660[iVar18 * 0x14 + 1];
  local_10c8 = afStack_660 + iVar18 * 0x14;
  fStack_1088 = *local_10c8;
  pfVar19 = afStack_ca0 + local_10d8 * 0x14;
  fStack_108c = afStack_ca0[local_10d8 * 0x14 + 1];
  fStack_1090 = *pfVar19;
  pfStack_10b0 = local_10c8;
  if (iVar18 < local_1020[0]) {
    do {
      if ((local_e60[0] <= local_10d8) || (fStack_10b8 < param_6 == (fStack_10b8 == param_6)))
      break;
      fVar12 = fStack_1088 - fStack_10ac;
      fVar13 = fStack_1084 - fStack_10a8;
      fVar7 = fStack_1090 - fStack_10c0;
      fVar8 = fStack_108c - fStack_10bc;
      fVar11 = SQRT(fVar12 * fVar12 + fVar13 * fVar13);
      fVar9 = SQRT(fVar7 * fVar7 + fVar8 * fVar8);
      fVar15 = fVar11 * (_K_ONE / fStack_10cc);
      fStack_10e0 = (_K_ONE / fStack_10d0) * fVar9;
      if (fVar15 < fStack_10e0) {
        fStack_10e0 = fVar15;
      }
      fStack_1030 = fStack_10c0 - fStack_10ac;
      fStack_102c = fStack_10bc - fStack_10a8;
      uStack_1028 = 0;
      uStack_1024 = 0;
      fVar14 = (_K_ONE / fStack_10cc) * fVar11;
      if (fVar14 == 0.0) {
        fVar10 = 0.0;
        fVar14 = _K_ONE;
      }
      else {
        fVar14 = _K_ONE / fVar14;
        fVar10 = fVar14 * fVar13;
        fVar14 = fVar12 * fVar14;
      }
      fVar16 = fVar9 * (_K_ONE / fStack_10d0);
      if (fVar16 == 0.0) {
        fStack_103c = 0.0;
        fStack_1040 = _K_ONE;
      }
      else {
        fVar16 = _K_ONE / fVar16;
        fStack_103c = fVar16 * fVar8;
        fStack_1040 = fVar7 * fVar16;
      }
      fStack_1040 = fStack_1040 - fVar14;
      fStack_103c = fStack_103c - fVar10;
      uStack_1038 = 0;
      uStack_1034 = 0;
      fVar20 = (float10)FUN_00458750(local_10c8,&fStack_1030,&fStack_1040);
      if (fVar20 < (float10)fStack_10e0 != (fVar20 == (float10)fStack_10e0)) {
        local_10c4 = (float)(fVar20 + (float10)fStack_10b8);
        break;
      }
      if (ABS(fVar11) <= _K_EPS_SPEED) {
        fVar12 = 0.0;
        fVar13 = 0.0;
      }
      else {
        fVar11 = (fStack_10e0 * fStack_10cc) / fVar11;
        fVar12 = fVar12 * fVar11;
        fVar13 = fVar13 * fVar11;
      }
      fStack_10ac = fVar12 + fStack_10ac;
      fStack_10a8 = fVar13 + fStack_10a8;
      fVar11 = fStack_10e0 * (fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2);
      fStack_10cc = fStack_10cc + fVar11;
      if (ABS(fVar9) <= _K_EPS_SPEED) {
        fVar7 = 0.0;
        fVar8 = 0.0;
      }
      else {
        fVar9 = (fStack_10e0 * fStack_10d0) / fVar9;
        fVar7 = fVar7 * fVar9;
        fVar8 = fVar8 * fVar9;
      }
      fStack_10c0 = fVar7 + fStack_10c0;
      fStack_10bc = fVar8 + fStack_10bc;
      fStack_10d0 = fVar11 + fStack_10d0;
      if (ABS(fVar15 - fStack_10e0) < 0.001 == (ABS(fVar15 - fStack_10e0) == 0.001)) {
        fStack_108c = pfVar19[0x15];
        fStack_1090 = pfVar19[0x14];
        local_10d8 = local_10d8 + 1;
        pfVar19 = pfVar19 + 0x14;
      }
      else {
        fStack_1084 = pfStack_10b0[0x15];
        iVar18 = iVar18 + 1;
        fStack_1088 = pfStack_10b0[0x14];
        local_10c8 = pfStack_10b0 + 0x14;
        pfStack_10b0 = local_10c8;
      }
      fStack_10b8 = fStack_10e0 + fStack_10b8;
    } while (iVar18 < local_1020[0]);
  }
  *param_7 = local_10c4;
  if ((local_10c4 < 99999.0) &&
     (ABS(local_10c4 - 99999.0) < 0.001 == (ABS(local_10c4 - 99999.0) == 0.001))) {
    iStack_14 = (uint)iStack_14._1_3_ << 8;
    eh_vector_destructor_iterator(afStack_ca0,0x50,0x14,NullUpdate_ret);
    iStack_14 = 0xffffffff;
    eh_vector_destructor_iterator(afStack_660,0x50,0x14,NullUpdate_ret);
    ExceptionList = pvStack_1c;
    return 1;
  }
  iStack_14 = (uint)iStack_14._1_3_ << 8;
  eh_vector_destructor_iterator(afStack_ca0,0x50,0x14,NullUpdate_ret);
  iStack_14 = 0xffffffff;
  eh_vector_destructor_iterator(afStack_660,0x50,0x14,NullUpdate_ret);
  ExceptionList = pvStack_1c;
  return 0;
}


// ==== 0x458150 FUN_00458150

void FUN_00458150(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 *in_EAX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  *in_EAX = *param_1;
  iVar5 = 0x14;
  puVar3 = (undefined4 *)(param_1 + (int)(in_EAX + 0x10) + (8 - (int)in_EAX));
  puVar4 = (undefined4 *)(in_EAX + 0x10);
  do {
    uVar1 = puVar3[-1];
    uVar2 = *puVar3;
    iVar5 = iVar5 + -1;
    *puVar4 = puVar3[-2];
    puVar4[1] = uVar1;
    *(undefined4 *)(in_EAX + (-0x10 - (int)param_1) + (int)(puVar3 + 4)) = uVar2;
    puVar3 = puVar3 + 4;
    puVar4 = puVar4 + 4;
  } while (iVar5 != 0);
  puVar3 = (undefined4 *)(param_1 + 0x150);
  puVar4 = (undefined4 *)(in_EAX + 0x150);
  for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar3 = (undefined4 *)(param_1 + 0x164);
  puVar4 = (undefined4 *)(in_EAX + 0x164);
  for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar3 = (undefined4 *)(param_1 + 0x18c);
  puVar4 = (undefined4 *)(in_EAX + 0x18c);
  for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  in_EAX[0x1a0] = param_1[0x1a0];
  *(undefined4 *)(in_EAX + 0x1a4) = *(undefined4 *)(param_1 + 0x1a4);
  *(undefined4 *)(in_EAX + 0x1a8) = *(undefined4 *)(param_1 + 0x1a8);
  *(undefined4 *)(in_EAX + 0x1ac) = *(undefined4 *)(param_1 + 0x1ac);
  in_EAX[0x1b0] = param_1[0x1b0];
  in_EAX[0x1b1] = param_1[0x1b1];
  return;
}


// ==== 0x458220 FUN_00458220

void __thiscall FUN_00458220(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00458340(param_2,param_3,*(undefined2 *)(param_1 + 0x3b4),param_4);
  return;
}


// ==== 0x458290 FUN_00458290

void FUN_00458290(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int unaff_EDI;
  
  iVar1 = (**(code **)(**(int **)(unaff_EDI + 0x1d4) + 0x28))();
  if (iVar1 != 0) {
    FUN_00576f30();
  }
  puVar2 = (undefined4 *)FUN_00578730();
  iVar1 = FUN_00578730(param_4);
  uVar3 = Atan2ToAngle16(*puVar2,*(undefined4 *)(iVar1 + 4));
  FUN_00458340(param_1,param_2,uVar3,param_4);
  return;
}


// ==== 0x458340 FUN_00458340

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00458340(float *param_1,undefined4 param_2,char *param_3,undefined4 param_4,float param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *in_EAX;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *unaff_ESI;
  float *pfVar10;
  
  fVar5 = ABS((*in_EAX - *param_1) * _K_HALF) * param_5;
  fVar6 = ABS((in_EAX[1] - param_1[1]) * _K_HALF) * param_5;
  param_5 = ABS((in_EAX[2] - param_1[2]) * _K_HALF) * param_5;
  Angle16SinCos();
  unaff_ESI[5] = 0;
  unaff_ESI[4] = 0;
  unaff_ESI[6] = 0;
  unaff_ESI[7] = 0;
  unaff_ESI[9] = 0;
  unaff_ESI[10] = 0;
  unaff_ESI[0xb] = 0;
  unaff_ESI[8] = 0x80000000;
  unaff_ESI[0xc] = 0;
  unaff_ESI[0xd] = 0;
  unaff_ESI[0xe] = 0x3f800000;
  unaff_ESI[0xf] = 0;
  unaff_ESI[0x10] = fVar5;
  unaff_ESI[0x11] = fVar6;
  unaff_ESI[0x12] = param_5;
  uVar1 = *(undefined4 *)(param_3 + 0x14);
  uVar2 = *(undefined4 *)(param_3 + 0x18);
  *unaff_ESI = *(undefined4 *)(param_3 + 0x10);
  unaff_ESI[1] = uVar1;
  iVar9 = 1;
  unaff_ESI[2] = uVar2;
  if ('\x01' < *param_3) {
    pfVar10 = (float *)(param_3 + 0x24);
    puVar8 = unaff_ESI + 0x1a;
    do {
      fVar4 = pfVar10[-5] - pfVar10[-1];
      fVar3 = pfVar10[-4] - *pfVar10;
      fVar7 = SQRT(fVar3 * fVar3 + fVar4 * fVar4);
      if (fVar7 == 0.0) {
        fVar3 = 0.0;
        fVar4 = _K_ONE;
      }
      else {
        fVar7 = _K_ONE / fVar7;
        fVar3 = fVar7 * fVar3;
        fVar4 = fVar4 * fVar7;
      }
      puVar8[-2] = fVar4;
      *puVar8 = 0;
      puVar8[1] = 0;
      puVar8[-1] = fVar3;
      puVar8[4] = 0;
      puVar8[5] = 0;
      puVar8[2] = -fVar3;
      iVar9 = iVar9 + 1;
      puVar8[3] = fVar4;
      puVar8[6] = 0;
      puVar8[7] = 0;
      puVar8[8] = 0x3f800000;
      puVar8[9] = 0;
      puVar8[10] = fVar5;
      puVar8[0xb] = fVar6;
      puVar8[0xc] = param_5;
      fVar3 = *pfVar10;
      fVar4 = pfVar10[1];
      puVar8[-6] = pfVar10[-1];
      puVar8[-5] = fVar3;
      pfVar10 = pfVar10 + 4;
      puVar8[-4] = fVar4;
      puVar8 = puVar8 + 0x14;
    } while (iVar9 < *param_3);
  }
  return;
}


// ==== 0x4584f0 FUN_004584f0

undefined4
FUN_004584f0(float param_1,float param_2,float param_3,float param_4,float *param_5,float *param_6)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float local_10 [4];
  
  local_10[0] = param_1;
  local_10[1] = param_2;
  local_10[2] = param_3;
  local_10[3] = param_4;
  iVar4 = 3;
  do {
    iVar2 = 0;
    if (3 < iVar4) {
      iVar3 = 3;
      do {
        if (local_10[iVar2 + 1] < local_10[iVar2]) {
          fVar1 = local_10[iVar2];
          local_10[iVar2] = local_10[iVar2 + 1];
          local_10[iVar2 + 1] = fVar1;
        }
        if (local_10[iVar2 + 2] < local_10[iVar2 + 1]) {
          fVar1 = local_10[iVar2 + 1];
          local_10[iVar2 + 1] = local_10[iVar2 + 2];
          local_10[iVar2 + 2] = fVar1;
        }
        if (local_10[iVar2 + 3] < local_10[iVar2 + 2]) {
          fVar1 = local_10[iVar2 + 2];
          local_10[iVar2 + 2] = local_10[iVar2 + 3];
          local_10[iVar2 + 3] = fVar1;
        }
        if (*(float *)(&stack0x00000000 + iVar2 * 4) < local_10[iVar2 + 3]) {
          fVar1 = local_10[iVar2 + 3];
          local_10[iVar2 + 3] = *(float *)(&stack0x00000000 + iVar2 * 4);
          *(float *)(&stack0x00000000 + iVar2 * 4) = fVar1;
        }
        iVar3 = iVar3 + 4;
        iVar2 = iVar2 + 4;
      } while (iVar3 < iVar4);
    }
    for (; iVar2 < iVar4; iVar2 = iVar2 + 1) {
      if (local_10[iVar2 + 1] < local_10[iVar2]) {
        fVar1 = local_10[iVar2];
        local_10[iVar2] = local_10[iVar2 + 1];
        local_10[iVar2 + 1] = fVar1;
      }
    }
    iVar4 = iVar4 + -1;
  } while (0 < iVar4);
  if ((((param_1 <= local_10[1]) && (local_10[1] < param_2 != (local_10[1] == param_2))) &&
      (param_3 <= local_10[1])) && (local_10[1] < param_4 != (local_10[1] == param_4))) {
    *param_5 = local_10[1];
    *param_6 = local_10[2];
    return 1;
  }
  return 0;
}


// ==== 0x4586a0 FUN_004586a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall
FUN_004586a0(undefined4 param_1,float *param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  float *unaff_ESI;
  
  if (0.0001 <= ABS(param_3)) {
    fVar1 = _K_ONE / param_3;
    *param_2 = (param_5 - param_4) * fVar1;
    *unaff_ESI = -((param_4 + param_5) * fVar1);
    if (param_3 < 0.0) {
      fVar1 = *unaff_ESI;
      *unaff_ESI = *param_2;
      *param_2 = fVar1;
    }
    return;
  }
  if (param_5 < ABS(param_4)) {
    *unaff_ESI = 9999.0;
    *param_2 = 9999.0;
    return;
  }
  *unaff_ESI = -9999.0;
  *param_2 = 9999.0;
  return;
}


// ==== 0x458750 FUN_00458750

float10 FUN_00458750(int param_1,float *param_2,float *param_3)

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
  float fVar14;
  float *pfVar15;
  int iVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  int unaff_EDI;
  float10 fVar21;
  undefined4 local_4;
  
  pfVar15 = param_3;
  fVar7 = *(float *)(param_1 + 0x44);
  fVar11 = *(float *)(unaff_EDI + 0x14) * *(float *)(param_1 + 0x14) +
           *(float *)(param_1 + 0x10) * *(float *)(unaff_EDI + 0x10);
  fVar8 = *(float *)(param_1 + 0x40);
  fVar12 = *(float *)(param_1 + 0x10) * *(float *)(unaff_EDI + 0x20) +
           *(float *)(unaff_EDI + 0x24) * *(float *)(param_1 + 0x14);
  fVar13 = *(float *)(param_1 + 0x20) * *(float *)(unaff_EDI + 0x10) +
           *(float *)(unaff_EDI + 0x14) * *(float *)(param_1 + 0x24);
  fVar14 = *(float *)(unaff_EDI + 0x20) * *(float *)(param_1 + 0x20) +
           *(float *)(unaff_EDI + 0x24) * *(float *)(param_1 + 0x24);
  fVar18 = ABS(fVar13 * *(float *)(unaff_EDI + 0x40));
  fVar17 = ABS(fVar14 * *(float *)(unaff_EDI + 0x44));
  fVar2 = *(float *)(unaff_EDI + 0x40);
  fVar3 = *(float *)(unaff_EDI + 0x44);
  fVar9 = *(float *)(unaff_EDI + 0x44);
  fVar4 = *(float *)(param_1 + 0x44);
  fVar10 = *(float *)(unaff_EDI + 0x40);
  fVar19 = ABS(fVar12 * *(float *)(param_1 + 0x40));
  fVar20 = ABS(fVar11 * *(float *)(param_1 + 0x40));
  fVar5 = *(float *)(param_1 + 0x44);
  pfVar1 = param_3 + 1;
  fVar6 = *param_3;
  param_3 = (float *)fVar17;
  FUN_004586a0(fVar6 * *(float *)(param_1 + 0x20) + *pfVar1 * *(float *)(param_1 + 0x24),
               *param_2 * *(float *)(param_1 + 0x20) + param_2[1] * *(float *)(param_1 + 0x24),
               fVar17 + fVar18 + ABS(fVar7));
  FUN_004586a0(*(float *)(param_1 + 0x10) * *pfVar15 + pfVar15[1] * *(float *)(param_1 + 0x14),
               *(float *)(param_1 + 0x10) * *param_2 + param_2[1] * *(float *)(param_1 + 0x14),
               ABS(fVar12 * fVar3) + ABS(fVar11 * fVar2) + ABS(fVar8));
  pfVar1 = param_2;
  FUN_004586a0(*(float *)(unaff_EDI + 0x20) * *pfVar15 + *(float *)(unaff_EDI + 0x24) * pfVar15[1],
               *(float *)(unaff_EDI + 0x20) * *param_2 + *(float *)(unaff_EDI + 0x24) * param_2[1],
               ABS(fVar14 * fVar4) + fVar19 + ABS(fVar9));
  FUN_004586a0(*pfVar15 * *(float *)(unaff_EDI + 0x10) + pfVar15[1] * *(float *)(unaff_EDI + 0x14),
               *pfVar1 * *(float *)(unaff_EDI + 0x10) + pfVar1[1] * *(float *)(unaff_EDI + 0x14),
               ABS(fVar13 * fVar5) + fVar20 + ABS(fVar10));
  iVar16 = FUN_004584f0(local_4,ABS(fVar7),fVar18,param_3,&param_2,&param_3);
  if (iVar16 != 0) {
    iVar16 = FUN_004584f0(param_2,param_3,fVar19,ABS(fVar9),&param_2,&param_3);
    if (iVar16 != 0) {
      iVar16 = FUN_004584f0(param_2,param_3,fVar20,ABS(fVar10),&param_2,&param_3);
      if (iVar16 != 0) {
        fVar21 = (float10)(float)param_2;
        if (fVar21 <= (float10)0.0) {
          if ((fVar21 < (float10)0.0) && (0.0 < (float)param_3)) {
            return (float10)0.0;
          }
          fVar21 = (float10)99999.0;
        }
        return fVar21;
      }
    }
  }
  return (float10)99999.0;
}


// ==== 0x458a50 FUN_00458a50

void FUN_00458a50(undefined4 param_1)

{
  uint *puVar1;
  undefined4 *in_EAX;
  uint *puVar2;
  int iVar3;
  
  puVar1 = in_EAX + 3;
  *in_EAX = &PTR_FUN_006c8f08;
  iVar3 = 8;
  puVar2 = puVar1;
  do {
    *puVar2 = *puVar2 & 0xfffffffe;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  in_EAX[1] = param_1;
  *puVar1 = *puVar1 & 0xfffffffe;
  in_EAX[4] = in_EAX[4] & 0xfffffffe;
  in_EAX[5] = in_EAX[5] & 0xfffffffe;
  in_EAX[6] = in_EAX[6] & 0xfffffffe;
  in_EAX[8] = in_EAX[8] & 0xfffffffe;
  in_EAX[9] = in_EAX[9] & 0xfffffffe;
  in_EAX[7] = in_EAX[7] & 0xfffffffe;
  in_EAX[10] = in_EAX[10] & 0xfffffffe;
  return;
}


// ==== 0x458ac0 FUN_00458ac0

undefined4 * __thiscall FUN_00458ac0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006c8f08;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x458ae0 FUN_00458ae0

void __thiscall FUN_00458ae0(int param_1,undefined4 param_2)

{
  (**(code **)(**(int **)(param_1 + 8) + 8))(param_2);
  FUN_00571c20(param_2,param_1 + 0xc,0x20,0xffffffff,0);
  return;
}


// ==== 0x458b10 FUN_00458b10

void __fastcall FUN_00458b10(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x28);
  if ((iVar1 != 1) && (iVar1 != 3)) {
    Car_SetMode();
  }
  return;
}


// ==== 0x458b50 FUN_00458b50

void __thiscall FUN_00458b50(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 != 0) && (iVar1 != -0x40)) {
    *(undefined4 *)(iVar1 + 0x404) = param_2;
  }
  return;
}


// ==== 0x458b70 FUN_00458b70

void __fastcall FUN_00458b70(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 != 0) && (iVar1 != -0x40)) {
    *(undefined4 *)(iVar1 + 0x404) = 0x3f800000;
  }
  return;
}


// ==== 0x458b90 FUN_00458b90

float10 __fastcall FUN_00458b90(int *param_1)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  
  fVar2 = DAT_00700680;
  fVar1 = *(float *)(param_1[1] + 0x3d4);
  fVar3 = (float10)(**(code **)(*param_1 + 0x50))();
  fVar3 = fVar3 * (float10)fVar1;
  if (fVar3 <= (float10)fVar2) {
    fVar3 = (float10)fVar2;
  }
  return fVar3;
}


// ==== 0x458bd0 RoadPath_LinkAccepted

/* [canon] traffic med (H) docs/re/traffic.md */

uint RoadPath_LinkAccepted(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uint *puVar5;
  uint uVar6;
  int *unaff_EDI;
  
  uVar6 = param_1 - DAT_00736150 >> 5 & 0xff;
  iVar1 = (**(code **)(*unaff_EDI + 0x40))();
  if (((bool)('\x01' - (iVar1 != 1)) != (*(char *)(param_1 + 0xd) == '\x01')) ||
     (*(char *)(param_1 + 0xb) == '\x03')) {
    return 0;
  }
  iVar1 = 0;
  puVar5 = (uint *)(unaff_EDI + 3);
  do {
    if (((*puVar5 & 1) != 0) && (uVar6 == (*puVar5 >> 2 & 0xff))) {
      return (uint)unaff_EDI[iVar1 + 3] >> 1 & 1;
    }
    iVar1 = iVar1 + 1;
    puVar5 = puVar5 + 1;
  } while (iVar1 < 8);
  uVar2 = (**(code **)(*unaff_EDI + 0x44))(param_1);
  if ((char)uVar2 != '\0') {
    (**(code **)(*unaff_EDI + 0x48))(param_1);
  }
  if (*(char *)(param_1 + 0xb) != '\t') {
    iVar1 = -1;
    iVar3 = 0;
    pbVar4 = (byte *)(unaff_EDI + 3);
    do {
      if ((*pbVar4 & 1) == 0) {
        iVar1 = iVar3;
        if (iVar3 != -1) goto LAB_00458c8d;
        break;
      }
      iVar3 = iVar3 + 1;
      pbVar4 = pbVar4 + 4;
    } while (iVar3 < 8);
    (**(code **)(*unaff_EDI + 0x40))();
    iVar3 = iVar1;
LAB_00458c8d:
    unaff_EDI[iVar3 + 3] = (uVar6 << 1 | uVar2 & 1) << 1 | unaff_EDI[iVar3 + 3] & 0xfffffc01U | 1;
  }
  return uVar2 & 0xff;
}


// ==== 0x458cc0 FUN_00458cc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00458cc0(int param_1)

{
  float fVar1;
  uint uVar2;
  float fVar3;
  int iVar4;
  int in_EAX;
  uint *puVar5;
  int iVar6;
  
  iVar4 = DAT_00736150;
  fVar1 = *(float *)(*(int *)(in_EAX + 4) + 0x814);
  puVar5 = (uint *)(in_EAX + 0xc);
  iVar6 = 8;
  do {
    uVar2 = *puVar5;
    if ((uVar2 & 1) != 0) {
      fVar3 = *(float *)((uVar2 >> 2 & 0xff) * 0x20 + iVar4) - fVar1;
      if ((0 < DAT_007372b8) && (*(char *)(DAT_007372bc + 1) != '\0')) {
        if (DAT_007372b0 * -0.5 <= fVar3) {
          if (DAT_007372b0 * _K_HALF < fVar3) {
            fVar3 = fVar3 - DAT_007372b0;
          }
        }
        else {
          fVar3 = fVar3 + DAT_007372b0;
        }
      }
      if (param_1 != DAT_0078a2fc) {
        fVar3 = -fVar3;
      }
      if (fVar3 < -10.0) {
        *puVar5 = uVar2 & 0xfffffffe;
      }
    }
    puVar5 = puVar5 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return;
}


// ==== 0x458d90 FUN_00458d90

void FUN_00458d90(void)

{
  int iVar1;
  undefined4 *unaff_ESI;
  
  unaff_ESI[0x69] = 0;
  unaff_ESI[0x6a] = 0;
  for (iVar1 = 0x70; iVar1 != 0; iVar1 = iVar1 + -1) {
    *unaff_ESI = 0;
    unaff_ESI = unaff_ESI + 1;
  }
  FUN_00458f10(0,0);
  return;
}


// ==== 0x458dc0 FUN_00458dc0

void FUN_00458dc0(void)

{
  int iVar1;
  char cVar2;
  char *unaff_EBX;
  char *pcVar3;
  int unaff_ESI;
  char *pcVar4;
  char *local_8;
  
  FUN_00571ea0(0,"DriveTarget");
  FUN_00571c20(unaff_ESI,unaff_EBX,1,1,1);
  FUN_00571c20(unaff_ESI,unaff_EBX + 0x1a0,1,1,1);
  FUN_00571c20(unaff_ESI,unaff_EBX + 0x1a4,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,unaff_EBX + 0x1a8,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,unaff_EBX + 0x1ac,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,unaff_EBX + 0x1b0,1,1,1);
  FUN_00571c20(unaff_ESI,unaff_EBX + 0x1b1,1,1,0);
  if ('\0' < *unaff_EBX) {
    pcVar4 = unaff_EBX + 0x18c;
    pcVar3 = unaff_EBX + 0x164;
    local_8 = unaff_EBX;
    do {
      local_8 = local_8 + 0x10;
      FUN_00571c20(unaff_ESI,local_8,0xc,0xffffffff,0);
      FUN_00571c20(unaff_ESI,pcVar3,2,2,1);
      FUN_00571c20(unaff_ESI,pcVar4 + -0x3c,1,1,1);
      FUN_00571c20(unaff_ESI,pcVar4,1,1,1);
      pcVar3 = pcVar3 + 2;
      pcVar4 = pcVar4 + 1;
    } while ((int)(pcVar4 + (-0x18c - (int)unaff_EBX)) < (int)*unaff_EBX);
  }
  iVar1 = *(char *)(unaff_ESI + 0x40) * 0x10 + 0x4c + unaff_ESI;
  *(int *)(iVar1 + 0xc) = *(int *)(unaff_ESI + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(unaff_ESI + 0x40) + -1;
  *(char *)(unaff_ESI + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(unaff_ESI + 0x44)) {
    *(undefined4 *)(unaff_ESI + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x458f10 FUN_00458f10

void FUN_00458f10(int param_1,float param_2)

{
  char cVar1;
  float *pfVar2;
  float *in_EAX;
  float *pfVar3;
  float *pfVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined1 local_20 [28];
  
  cVar1 = *(char *)in_EAX;
  if (cVar1 != '\0') {
    if ((ABS(param_2) < 0.001 == (ABS(param_2) == 0.001)) && (0.0 <= param_2)) {
      iVar7 = 0;
      if (0 < cVar1) {
        pfVar3 = (float *)FUN_0041f5e0();
        pfVar4 = (float *)FUN_00424df0();
        pfVar2 = in_EAX;
        do {
          if (0.0 < (pfVar2[5] - pfVar3[1]) * pfVar4[1] + (pfVar2[4] - *pfVar3) * *pfVar4) break;
          iVar7 = iVar7 + 1;
          pfVar2 = pfVar2 + 4;
        } while (iVar7 < *(char *)in_EAX);
      }
      if (iVar7 < cVar1) {
        if (0 < iVar7) {
          FUN_0045a7d0(0);
        }
        iVar7 = FUN_004590a0(param_2,local_20);
        if (iVar7 < *(char *)in_EAX + -1) {
          if (iVar7 < 0) goto LAB_00459028;
          *(char *)in_EAX = (char)iVar7 + '\x01';
          uVar5 = (uint)*(byte *)(iVar7 + 0x18c + (int)in_EAX);
          uVar6 = (uint)*(ushort *)((int)in_EAX + iVar7 * 2 + 0x164);
          cVar1 = *(char *)(iVar7 + 0x150 + (int)in_EAX);
        }
        else {
          if (-1 < iVar7) goto LAB_00459071;
LAB_00459028:
          iVar7 = DriveTarget__GetFirstPoint
                            (*(undefined4 *)(param_1 + 0x3d0),param_1 + 0x60,param_1 + 0x70);
          cVar1 = *(char *)(iVar7 + 0x150 + (int)in_EAX);
          uVar6 = (uint)*(short *)((int)in_EAX + iVar7 * 2 + 0x164);
          uVar5 = (uint)*(char *)(iVar7 + 0x18c + (int)in_EAX);
          *(undefined1 *)in_EAX = 0;
        }
        FUN_004594d0((int)cVar1,uVar6,uVar5,0);
        FUN_0045a8c0();
        goto LAB_00459071;
      }
    }
    *(undefined1 *)in_EAX = 0;
  }
  in_EAX[0x6b] = 0.0;
LAB_00459071:
  *(undefined1 *)(in_EAX + 0x6c) = 0xff;
  *(undefined1 *)((int)in_EAX + 0x1b1) = 0;
  in_EAX[0x69] = 0.0;
  in_EAX[0x6a] = 0.0;
  return;
}


// ==== 0x4590a0 FUN_004590a0

int __thiscall FUN_004590a0(char *param_1,float param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  char cVar9;
  int in_EAX;
  int iVar10;
  int iVar11;
  float *pfVar12;
  float *pfVar13;
  int iVar14;
  float afStack_64 [24];
  
  if (*param_1 == '\0') {
    return -1;
  }
  if (*param_1 == '\x01') {
    fVar1 = *(float *)(param_1 + 0x10);
    fVar2 = *(float *)(in_EAX + 0x60);
    fVar3 = *(float *)(param_1 + 0x14);
    fVar4 = *(float *)(in_EAX + 100);
    fVar5 = *(float *)(param_1 + 0x18);
    fVar6 = *(float *)(in_EAX + 0x68);
    FUN_005673e0(param_2);
    fVar7 = *(float *)(in_EAX + 100);
    fVar8 = *(float *)(in_EAX + 0x68);
    *param_3 = (fVar1 - fVar2) + *(float *)(in_EAX + 0x60);
    param_3[2] = fVar8 + (fVar5 - fVar6);
    param_3[1] = fVar7 + (fVar3 - fVar4);
    return 0;
  }
  pfVar13 = (float *)(in_EAX + 0x60);
  iVar10 = DriveTarget__GetFirstPoint(*(undefined4 *)(in_EAX + 0x3d0),pfVar13,in_EAX + 0x70);
  iVar11 = (iVar10 + 1) * 0x10;
  fVar1 = *(float *)(param_1 + iVar11 + 4) - *(float *)(in_EAX + 100);
  fVar2 = *(float *)(param_1 + iVar11 + 8) - *(float *)(in_EAX + 0x68);
  fVar1 = SQRT((*(float *)(param_1 + iVar11) - *pfVar13) * (*(float *)(param_1 + iVar11) - *pfVar13)
               + fVar2 * fVar2 + fVar1 * fVar1);
  afStack_64[iVar10 + 1] = fVar1;
  iVar11 = iVar10;
  if (fVar1 < param_2) {
    cVar9 = *param_1;
    iVar11 = iVar10 + 1;
    if (iVar11 < cVar9) {
      pfVar12 = (float *)(param_1 + iVar11 * 0x10 + 0x18);
      do {
        fVar1 = SQRT((pfVar12[-2] - pfVar12[-6]) * (pfVar12[-2] - pfVar12[-6]) +
                     (pfVar12[-1] - pfVar12[-5]) * (pfVar12[-1] - pfVar12[-5]) +
                     (*pfVar12 - pfVar12[-4]) * (*pfVar12 - pfVar12[-4])) + afStack_64[iVar11];
        afStack_64[iVar11 + 1] = fVar1;
        if (param_2 <= fVar1) break;
        iVar11 = iVar11 + 1;
        pfVar12 = pfVar12 + 4;
      } while (iVar11 < cVar9);
    }
  }
  iVar14 = *param_1 + -1;
  if (iVar11 <= iVar14) {
    if (iVar10 < iVar11) {
      iVar10 = iVar11 + -1;
      fVar1 = afStack_64[iVar11];
      pfVar13 = (float *)(param_1 + iVar11 * 0x10);
    }
    else {
      fVar1 = 0.0;
      iVar10 = -1;
    }
    pfVar12 = (float *)(param_1 + (iVar11 + 1) * 0x10);
    fVar7 = (param_2 - fVar1) / (afStack_64[iVar11 + 1] - fVar1);
    fVar1 = pfVar12[1];
    fVar2 = pfVar13[1];
    fVar3 = pfVar12[2];
    fVar4 = pfVar13[2];
    fVar5 = pfVar13[1];
    fVar6 = pfVar13[2];
    *param_3 = (*pfVar12 - *pfVar13) * fVar7 + *pfVar13;
    param_3[1] = (fVar1 - fVar2) * fVar7 + fVar5;
    param_3[2] = (fVar3 - fVar4) * fVar7 + fVar6;
    return iVar10;
  }
  fVar1 = *(float *)(param_1 + iVar14 * 0x10 + 0x10);
  pfVar13 = (float *)(param_1 + iVar14 * 0x10);
  fVar2 = *pfVar13;
  fVar3 = pfVar13[5];
  fVar4 = pfVar13[1];
  fVar5 = pfVar13[6];
  fVar6 = pfVar13[2];
  FUN_005673e0(param_2 - afStack_64[*param_1]);
  fVar7 = pfVar13[5];
  fVar8 = pfVar13[6];
  *param_3 = (fVar1 - fVar2) + pfVar13[4];
  param_3[2] = fVar8 + (fVar5 - fVar6);
  param_3[1] = fVar7 + (fVar3 - fVar4);
  return iVar14;
}


// ==== 0x4592f0 FUN_004592f0

float10 __fastcall FUN_004592f0(char *param_1,float *param_2)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  float fVar9;
  char cVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float *pfVar17;
  int iVar18;
  float10 fVar19;
  float local_50;
  float local_4c;
  float local_48;
  float local_40;
  float local_3c;
  float local_38;
  
  cVar10 = *param_1;
  if (cVar10 < '\x01') {
    return (float10)0.0;
  }
  fVar19 = (float10)*param_2 - (float10)*(float *)(param_1 + 0x10);
  if (cVar10 == '\x01') {
    return SQRT(fVar19 * fVar19 +
                ((float10)param_2[1] - (float10)*(float *)(param_1 + 0x14)) *
                ((float10)param_2[1] - (float10)*(float *)(param_1 + 0x14)) +
                ((float10)param_2[2] - (float10)*(float *)(param_1 + 0x18)) *
                ((float10)param_2[2] - (float10)*(float *)(param_1 + 0x18)));
  }
  local_40 = (float)fVar19;
  iVar18 = 2;
  local_3c = param_2[1] - *(float *)(param_1 + 0x14);
  local_38 = param_2[2] - *(float *)(param_1 + 0x18);
  local_50 = *(float *)(param_1 + 0x20) - *(float *)(param_1 + 0x10);
  local_4c = *(float *)(param_1 + 0x24) - *(float *)(param_1 + 0x14);
  local_48 = *(float *)(param_1 + 0x28) - *(float *)(param_1 + 0x18);
  if (0.0 < local_50 * local_40 + local_4c * local_3c + local_48 * local_38) {
    pfVar17 = (float *)(param_1 + 0x38);
    fVar11 = local_50;
    fVar12 = local_4c;
    fVar13 = local_48;
    fVar14 = local_40;
    fVar15 = local_3c;
    fVar16 = local_38;
    do {
      local_38 = fVar16;
      local_3c = fVar15;
      local_40 = fVar14;
      local_48 = fVar13;
      local_4c = fVar12;
      local_50 = fVar11;
      if (cVar10 <= iVar18) break;
      pfVar1 = pfVar17 + -6;
      pfVar2 = pfVar17 + -5;
      pfVar3 = pfVar17 + -4;
      pfVar4 = pfVar17 + -2;
      pfVar5 = pfVar17 + -6;
      pfVar6 = pfVar17 + -1;
      pfVar7 = pfVar17 + -5;
      fVar9 = *pfVar17;
      pfVar8 = pfVar17 + -4;
      pfVar17 = pfVar17 + 4;
      iVar18 = iVar18 + 1;
      fVar11 = *pfVar4 - *pfVar5;
      fVar12 = *pfVar6 - *pfVar7;
      fVar13 = fVar9 - *pfVar8;
      fVar14 = *param_2 - *pfVar1;
      fVar15 = param_2[1] - *pfVar2;
      fVar16 = param_2[2] - *pfVar3;
    } while (0.0 < (*pfVar4 - *pfVar5) * (*param_2 - *pfVar1) +
                   (*pfVar6 - *pfVar7) * (param_2[1] - *pfVar2) +
                   (fVar9 - *pfVar8) * (param_2[2] - *pfVar3));
  }
  bNormalize3();
  return (float10)(local_4c - local_48 * 0.0) * (float10)local_40 +
         (float10)(local_48 * 0.0 - local_50) * (float10)local_3c +
         (float10)(local_50 * 0.0 - local_4c * 0.0) * (float10)local_38;
}


// ==== 0x4594d0 FUN_004594d0

uint __thiscall FUN_004594d0(int param_1,char param_2,undefined2 param_3,char param_4,char param_5)

{
  float fVar1;
  float fVar2;
  char cVar3;
  uint in_EAX;
  uint uVar4;
  float *pfVar5;
  float *pfVar6;
  bool bVar7;
  char *unaff_ESI;
  float *unaff_EDI;
  
  cVar3 = *unaff_ESI;
  bVar7 = true;
  if ('\x13' < cVar3) {
    return in_EAX & 0xffffff00;
  }
  if (cVar3 < '\x01') {
    if (param_1 != 0) {
      fVar1 = *unaff_EDI - *(float *)(param_1 + 0x60);
      fVar2 = unaff_EDI[1] - *(float *)(param_1 + 100);
      fVar1 = SQRT(fVar2 * fVar2 + fVar1 * fVar1);
      if (fVar1 < 1.0) {
        return (uint)(ushort)((ushort)(fVar1 < 1.0) << 8 | (ushort)NAN(fVar1) << 10 |
                             (ushort)(fVar1 == 1.0) << 0xe);
      }
      cVar3 = FUN_004556d0(0);
      if ((cVar3 == '\0') && (fVar1 < 20.0 || (fVar1 == 20.0) != 0)) {
        return (uint)(ushort)((ushort)(fVar1 < 20.0) << 8 | (ushort)NAN(fVar1) << 10 |
                             (ushort)(fVar1 == 20.0) << 0xe);
      }
      bVar7 = true;
    }
    goto LAB_004595f5;
  }
  pfVar6 = (float *)(unaff_ESI + cVar3 * 0x10);
  fVar1 = SQRT((*unaff_EDI - *pfVar6) * (*unaff_EDI - *pfVar6) +
               (unaff_EDI[1] - pfVar6[1]) * (unaff_EDI[1] - pfVar6[1]));
  bVar7 = fVar1 >= 1.0;
  uVar4 = (uint)CONCAT11(fVar1 < 1.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8),param_5);
  if (param_5 != '\0') {
    if (!bVar7) goto LAB_0045969f;
    uVar4 = (uint)(ushort)((ushort)(fVar1 < 20.0) << 8 | (ushort)NAN(fVar1) << 10 |
                          (ushort)(fVar1 == 20.0) << 0xe);
    if (fVar1 < 20.0) {
      if (cVar3 < '\x02') {
        if (param_1 == 0) goto LAB_004595ed;
        pfVar5 = (float *)(param_1 + 0x60);
      }
      else {
        pfVar5 = pfVar6 + -4;
      }
      uVar4 = 0;
      if (pfVar5 != (float *)0x0) {
        fVar1 = (*unaff_EDI - *pfVar6) * (*pfVar6 - *pfVar5) +
                (unaff_EDI[1] - pfVar6[1]) * (pfVar6[1] - pfVar5[1]);
        if (fVar1 < 0.0) {
          return (uint)(ushort)((ushort)(fVar1 < 0.0) << 8 | (ushort)NAN(fVar1) << 10 |
                               (ushort)(fVar1 == 0.0) << 0xe);
        }
        bVar7 = true;
        goto LAB_004595f5;
      }
    }
  }
LAB_004595ed:
  if (!bVar7) {
LAB_0045969f:
    return CONCAT31((int3)(uVar4 >> 8),bVar7);
  }
LAB_004595f5:
  fVar1 = unaff_EDI[1];
  fVar2 = unaff_EDI[2];
  pfVar6 = (float *)(unaff_ESI + (*unaff_ESI + 1) * 0x10);
  *pfVar6 = *unaff_EDI;
  pfVar6[1] = fVar1;
  pfVar6[2] = fVar2;
  unaff_ESI[*unaff_ESI + 0x150] = param_2;
  *(undefined2 *)(unaff_ESI + *unaff_ESI * 2 + 0x164) = param_3;
  unaff_ESI[*unaff_ESI + 0x18c] = param_4;
  unaff_ESI[0x1a4] = '\0';
  unaff_ESI[0x1a5] = '\0';
  unaff_ESI[0x1a6] = '\0';
  unaff_ESI[0x1a7] = '\0';
  unaff_ESI[0x1a8] = '\0';
  unaff_ESI[0x1a9] = '\0';
  unaff_ESI[0x1aa] = '\0';
  unaff_ESI[0x1ab] = '\0';
  cVar3 = *unaff_ESI;
  if ('\0' < cVar3) {
    pfVar6 = (float *)(unaff_ESI + cVar3 * 0x10);
    *(float *)(unaff_ESI + 0x1ac) =
         SQRT((*unaff_EDI - *pfVar6) * (*unaff_EDI - *pfVar6) +
              (unaff_EDI[2] - pfVar6[2]) * (unaff_EDI[2] - pfVar6[2]) +
              (unaff_EDI[1] - pfVar6[1]) * (unaff_EDI[1] - pfVar6[1])) +
         *(float *)(unaff_ESI + 0x1ac);
  }
  *unaff_ESI = cVar3 + '\x01';
  return (uint)bVar7;
}


// ==== 0x4596b0 FUN_004596b0

void FUN_004596b0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  iVar2 = *(int *)(*(int *)(param_2 + 0x1d4) + 0x1c);
  if (*(int *)(iVar2 + 0xe4) != 0) {
    FUN_005791c0();
  }
  iVar1 = *(int *)(*(int *)(param_2 + 0x1d4) + 0x1c);
  if (*(int *)(iVar1 + 0xe4) != 0) {
    FUN_005791c0();
  }
  iVar2 = iVar2 + 0x90;
  iVar1 = iVar1 + 0x40;
  fVar3 = (float10)FUN_00457520(iVar1,iVar2);
  DriveTarget__GetFirstPoint((float)fVar3,iVar1,iVar2);
  return;
}


// ==== 0x459710 DriveTarget::GetFirstPoint

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

int DriveTarget__GetFirstPoint(undefined4 param_1,float *param_2)

{
  int iVar1;
  char cVar2;
  float fVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  float *unaff_ESI;
  int local_14;
  float local_8;
  float local_4;
  
  if (DAT_0073ad34 != unaff_ESI[0x69]) {
    cVar2 = *(char *)unaff_ESI;
    if ('\0' < cVar2) {
      iVar1 = cVar2 + -1;
      bNormalize2();
      iVar8 = 0;
      pfVar4 = unaff_ESI;
      local_14 = iVar1;
      if (0 < cVar2) {
        do {
          fVar3 = pfVar4[4] - *param_2;
          fVar5 = pfVar4[5] - param_2[1];
          fVar6 = fVar3 * fVar3 + fVar5 * fVar5;
          fVar7 = SQRT(fVar6);
          if (fVar7 == 0.0) {
            fVar5 = 0.0;
            fVar3 = _K_ONE;
          }
          else {
            fVar7 = _K_ONE / fVar7;
            fVar5 = fVar7 * fVar5;
            fVar3 = fVar7 * fVar3;
          }
        } while (((local_8 * fVar3 + local_4 * fVar5 <= 0.0) ||
                 (local_14 = iVar8, fVar6 <= _DAT_0077a4a8)) &&
                (iVar8 = iVar8 + 1, pfVar4 = pfVar4 + 4, local_14 = iVar1,
                iVar8 < *(char *)unaff_ESI));
      }
      *(undefined1 *)(unaff_ESI + 0x68) = (undefined1)local_14;
      unaff_ESI[0x69] = DAT_0073ad34;
      return (int)*(char *)(unaff_ESI + 0x68);
    }
    *(undefined1 *)(unaff_ESI + 0x68) = 0;
    unaff_ESI[0x69] = 0.0;
  }
  return (int)*(char *)(unaff_ESI + 0x68);
}


// ==== 0x459870 FUN_00459870

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00459870(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  float *unaff_ESI;
  char *unaff_EDI;
  float10 extraout_ST0;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  
  if (param_1 <= 0.0) {
    param_1 = 0.0;
  }
  if ((float)(*unaff_EDI + -1) < param_1) {
    param_1 = (float)(*unaff_EDI + -1);
  }
  Float_Truncate(param_1);
  iVar4 = _ftol_nocw();
  if ((float10)param_1 == extraout_ST0) {
    iVar4 = (iVar4 + 1) * 0x10;
    fVar1 = *(float *)(unaff_EDI + iVar4 + 4);
    fVar2 = *(float *)((int)(unaff_EDI + iVar4) + 8);
    *unaff_ESI = *(float *)(unaff_EDI + iVar4);
    unaff_ESI[1] = fVar1;
    unaff_ESI[2] = fVar2;
    return;
  }
  fVar7 = (float10)param_1 - extraout_ST0;
  iVar5 = (iVar4 + 1) * 0x10;
  fVar3 = *(float *)(unaff_EDI + iVar5 + 8);
  fVar8 = (float10)_K_ONE - fVar7;
  fVar1 = *(float *)((int)(unaff_EDI + iVar5) + 4);
  pfVar6 = (float *)(unaff_EDI + (iVar4 + 2) * 0x10);
  *unaff_ESI = (float)(fVar8 * (float10)*(float *)(unaff_EDI + iVar5));
  fVar9 = (float10)fVar1 * fVar8;
  unaff_ESI[1] = (float)fVar9;
  unaff_ESI[2] = (float)(fVar8 * (float10)fVar3);
  fVar1 = pfVar6[1];
  fVar2 = pfVar6[2];
  *unaff_ESI = (float)(fVar7 * (float10)*pfVar6 + (float10)*unaff_ESI);
  unaff_ESI[1] = (float)(fVar7 * (float10)fVar1 + (float10)(float)fVar9);
  unaff_ESI[2] = (float)(fVar7 * (float10)fVar2 + (float10)(float)(fVar8 * (float10)fVar3));
  return;
}


// ==== 0x459980 FUN_00459980

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00459980(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  char *in_EAX;
  int iVar5;
  undefined4 *puVar6;
  float *pfVar7;
  char *pcVar8;
  float fVar9;
  float10 fVar10;
  int local_204;
  float local_200;
  float *local_1f8;
  float local_1f4 [41];
  undefined4 local_150 [83];
  
  if ('\x02' < *in_EAX) {
    fVar9 = (float)(int)*in_EAX;
    local_1f8 = local_1f4 + 1;
    fVar4 = _K_ONE / (float)((int)fVar9 + -1);
    local_204 = 0;
    fVar3 = 0.0;
    local_200 = 0.0;
    if (0 < (int)fVar9) {
      pfVar7 = (float *)(in_EAX + 0x18);
      do {
        if (0 < local_204) {
          fVar3 = SQRT((pfVar7[-1] - pfVar7[-5]) * (pfVar7[-1] - pfVar7[-5]) +
                       (pfVar7[-2] - pfVar7[-6]) * (pfVar7[-2] - pfVar7[-6]) +
                       (*pfVar7 - pfVar7[-4]) * (*pfVar7 - pfVar7[-4])) + fVar3;
        }
        local_1f4[local_204 * 2 + 1] = fVar3;
        iVar5 = local_204 + 1;
        pfVar7 = pfVar7 + 4;
        local_1f4[iVar5 * 2] = (float)local_204;
        local_204 = iVar5;
        local_200 = fVar3;
      } while (iVar5 < (int)fVar9);
    }
    local_204 = 0;
    local_1f4[0] = fVar9;
    if (0 < (int)fVar9) {
      do {
        fVar10 = (float10)LinearTable__Lookup11(&local_1f8,(float)local_204 * local_200 * fVar4);
        FUN_00459870((float)fVar10);
        local_204 = local_204 + 1;
      } while (local_204 < (int)fVar9);
      puVar6 = local_150 + 2;
      pcVar8 = in_EAX + 0x18;
      do {
        uVar2 = *puVar6;
        *(undefined4 *)(pcVar8 + -8) = puVar6[-2];
        uVar1 = puVar6[-1];
        *(undefined4 *)pcVar8 = uVar2;
        *(undefined4 *)(pcVar8 + -4) = uVar1;
        puVar6 = puVar6 + 4;
        pcVar8 = pcVar8 + 0x10;
        fVar9 = (float)((int)fVar9 + -1);
      } while (fVar9 != 0.0);
    }
    *(float *)(in_EAX + 0x1ac) = local_200;
    in_EAX[0x1a4] = '\0';
    in_EAX[0x1a5] = '\0';
    in_EAX[0x1a6] = '\0';
    in_EAX[0x1a7] = '\0';
    in_EAX[0x1a8] = '\0';
    in_EAX[0x1a9] = '\0';
    in_EAX[0x1aa] = '\0';
    in_EAX[0x1ab] = '\0';
  }
  return;
}


// ==== 0x459ac0 FUN_00459ac0

void FUN_00459ac0(char *param_1,int param_2)

{
  char in_AL;
  int iVar1;
  undefined1 local_20 [28];
  
  if (((in_AL == '\0') || ((DAT_006fbf14 == 0 && (*(short *)(param_2 + 10) == DAT_006fbf18)))) &&
     (iVar1 = 0, '\0' < *param_1)) {
    do {
      if (param_2 != 0) {
        FUN_004650d0(local_20);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *param_1);
  }
  return;
}


// ==== 0x459b30 FUN_00459b30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00459b30(char *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  char cVar4;
  float fVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  float fVar11;
  float10 fVar12;
  float10 fVar13;
  bool local_af;
  char local_ae;
  float *local_ac;
  float local_a4 [20];
  float afStack_54 [21];
  
  bVar3 = true;
  if (*param_1 == '\0') {
    return (float10)-1.0;
  }
  local_af = *param_1 == '\x01';
  if (local_af) {
    local_a4[1] = *(float *)(param_2 + 0x3d4);
    fVar5 = *(float *)(param_2 + 0x60) - *(float *)(param_1 + 0x10);
    fVar11 = *(float *)(param_2 + 100) - *(float *)(param_1 + 0x14);
    afStack_54[1] = SQRT(fVar5 * fVar5 + fVar11 * fVar11);
  }
  fVar5 = (float)DriveTarget__GetFirstPoint
                           (*(undefined4 *)(param_2 + 0x3d0),param_2 + 0x60,param_2 + 0x70);
  local_a4[0] = fVar5;
  if ((int)fVar5 < (int)*param_1) {
    local_ac = (float *)(param_1 + (int)fVar5 * 0x10 + 0x14);
    fVar11 = fVar5;
    do {
      if (local_af) goto LAB_00459efb;
      local_a4[(int)fVar11 + 1] = *(float *)(param_2 + 0x3d4);
      if ((int)fVar5 < (int)fVar11) {
        fVar1 = local_ac[-1] - local_ac[-5];
        fVar2 = *local_ac - local_ac[-4];
      }
      else {
        pfVar6 = (float *)FUN_0041f5e0();
        fVar1 = local_ac[-1] - *pfVar6;
        fVar2 = *local_ac - pfVar6[1];
      }
      cVar4 = *param_1;
      fVar11 = (float)((int)fVar11 + 1);
      local_ac = local_ac + 4;
      afStack_54[(int)fVar11] = SQRT(fVar1 * fVar1 + fVar2 * fVar2);
    } while ((int)fVar11 < (int)cVar4);
  }
  else if (local_af) {
LAB_00459efb:
    iVar10 = (int)fVar5 + 1;
    fVar12 = ((float10)*(float *)(param_2 + 0x3d4) + (float10)local_a4[(int)fVar5 + 1]) *
             (float10)_K_HALF * (float10)afStack_54[(int)fVar5 + 1];
    fVar13 = (float10)afStack_54[(int)fVar5 + 1];
    while (iVar10 < *param_1) {
      pfVar6 = local_a4 + iVar10;
      iVar10 = iVar10 + 1;
      fVar12 = ((float10)*pfVar6 + (float10)local_a4[iVar10]) * (float10)_K_HALF *
               (float10)afStack_54[iVar10] + fVar12;
      fVar13 = fVar13 + (float10)afStack_54[iVar10];
    }
    if ((float10)0.0 < fVar13) {
      return fVar12 / fVar13;
    }
    goto LAB_00459f5d;
  }
  local_ae = '\x01';
  fVar11 = ABS(*(float *)(param_2 + 0x3d4));
  if ((fVar11 < 0.001 == (fVar11 == 0.001)) ||
     (fVar11 = ABS(local_a4[(int)fVar5 + 1]), fVar11 < 0.001 == (fVar11 == 0.001))) {
    fVar11 = afStack_54[(int)fVar5 + 1] /
             ((local_a4[(int)fVar5 + 1] + *(float *)(param_2 + 0x3d4)) * _K_HALF);
  }
  else {
    fVar11 = 9999999.0;
  }
  if (fVar11 < 0.4) {
    fVar11 = fVar5;
    pfVar6 = (float *)(param_1 + ((int)fVar5 + 1) * 0x10);
    do {
      fVar5 = fVar11;
      if ((int)*param_1 <= (int)fVar11) break;
      fVar5 = (float)((int)fVar11 + 1);
      pfVar7 = (float *)FUN_0041f5e0();
      fVar1 = *pfVar7 - pfVar6[4];
      fVar2 = ABS(*(float *)(param_2 + 0x3d4));
      if ((fVar2 < 0.001 == (fVar2 == 0.001)) ||
         (fVar2 = ABS(local_a4[(int)fVar11 + 2]), fVar2 < 0.001 == (fVar2 == 0.001))) {
        fVar1 = SQRT(fVar1 * fVar1 + (pfVar7[1] - pfVar6[5]) * (pfVar7[1] - pfVar6[5])) /
                ((local_a4[(int)fVar11 + 2] + *(float *)(param_2 + 0x3d4)) * _K_HALF);
      }
      else {
        fVar1 = 9999999.0;
      }
      fVar11 = fVar5;
      pfVar6 = pfVar6 + 4;
    } while (fVar1 < 0.4);
  }
  iVar10 = (int)fVar5 + 1;
  if ((iVar10 < *param_1) && (local_ae = FUN_00459f70(param_1,0x3f000000), local_ae == '\0')) {
    local_af = true;
    bVar3 = false;
  }
  if (param_1[0x1b0] == -1) {
    cVar4 = *param_1 + -2;
  }
  else {
    cVar4 = param_1[0x1b0] + -1;
  }
  fVar5 = local_a4[0];
  do {
    if ((local_af) || (cVar4 < iVar10)) {
      if (bVar3) goto LAB_00459efb;
      break;
    }
    pfVar6 = (float *)(param_1 + iVar10 * 0x10);
    iVar8 = (iVar10 + 1) * 0x10;
    pfVar7 = local_a4 + iVar10;
    fVar11 = pfVar6[1] - *(float *)((int)(param_1 + iVar8) + 4);
    local_ac = (float *)SQRT((*(float *)(param_1 + iVar10 * 0x10) - *(float *)(param_1 + iVar8)) *
                             (*(float *)(param_1 + iVar10 * 0x10) - *(float *)(param_1 + iVar8)) +
                             fVar11 * fVar11);
    fVar11 = ABS(*pfVar7);
    if ((fVar11 < 0.001 == (fVar11 == 0.001)) ||
       (fVar11 = ABS(local_a4[iVar10 + 1]), fVar11 < 0.001 == (fVar11 == 0.001))) {
      fVar11 = (float)local_ac / ((*pfVar7 + local_a4[iVar10 + 1]) * _K_HALF);
    }
    else {
      fVar11 = 9999999.0;
    }
    if (fVar11 < 0.4) {
      pfVar9 = (float *)(param_1 + iVar8);
      iVar8 = iVar10;
      do {
        iVar10 = iVar8;
        if (*param_1 <= iVar8) break;
        fVar11 = *pfVar6 - pfVar9[4];
        iVar10 = iVar8 + 1;
        local_ac = (float *)SQRT(fVar11 * fVar11 + (pfVar6[1] - pfVar9[5]) * (pfVar6[1] - pfVar9[5])
                                );
        fVar11 = ABS(*pfVar7);
        if ((fVar11 < 0.001 == (fVar11 == 0.001)) ||
           (fVar11 = ABS(local_a4[iVar8 + 2]), fVar11 < 0.001 == (fVar11 == 0.001))) {
          fVar11 = (float)local_ac / ((*pfVar7 + local_a4[iVar8 + 2]) * _K_HALF);
        }
        else {
          fVar11 = 9999999.0;
        }
        pfVar9 = pfVar9 + 4;
        iVar8 = iVar10;
      } while (fVar11 < 0.4);
    }
    local_a4[0] = fVar5;
    if (cVar4 < iVar10) {
      local_af = true;
    }
    else {
      local_ae = FUN_0045a000(param_1,param_2,param_1 + (iVar10 + 2) * 0x10,local_ac,*pfVar7);
      iVar10 = iVar10 + 1;
    }
    fVar5 = local_a4[0];
  } while (local_ae != '\0');
LAB_00459f5d:
  return (float10)-1.0;
}


// ==== 0x459f70 FUN_00459f70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00459f70(undefined4 param_1,float param_2)

{
  float *in_EAX;
  int unaff_ESI;
  float *unaff_EDI;
  
  param_2 = ABS(*(float *)(unaff_ESI + 0x3d0)) * param_2;
  if (_K_EPS_SPEED < ABS(*unaff_EDI)) {
    bScaleToLength2(*unaff_EDI,param_2,*in_EAX - *(float *)(unaff_ESI + 0x60),
                    in_EAX[1] - *(float *)(unaff_ESI + 100));
  }
  FUN_0045a0b0(param_1,unaff_ESI,param_2,*(undefined4 *)(unaff_ESI + 0x3d4));
  return;
}


// ==== 0x45a000 FUN_0045a000

undefined4
FUN_0045a000(undefined4 param_1,undefined4 param_2,undefined4 param_3,float param_4,float param_5)

{
  undefined4 uVar1;
  float *unaff_EDI;
  
  if (ABS(param_5) < 0.001 == (ABS(param_5) == 0.001)) {
    if (ABS(param_4) < 0.001 == (ABS(param_4) == 0.001)) {
      bScaleToLength2(param_5);
      bScaleToLength2(*unaff_EDI);
      uVar1 = FUN_0045a0b0(param_1,param_2,param_4,param_5);
      return uVar1;
    }
    *unaff_EDI = param_5;
  }
  return 1;
}


// ==== 0x45a0b0 FUN_0045a0b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __fastcall
FUN_0045a0b0(float *param_1,float *param_2,undefined4 param_3,undefined4 param_4,float param_5,
            float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *in_EAX;
  
  if ((ABS(param_6) < 0.001 == (ABS(param_6) == 0.001)) ||
     (fVar2 = ABS(*param_2), fVar2 < 0.001 == (fVar2 == 0.001))) {
    param_5 = param_5 / ((*param_2 + param_6) * _K_HALF);
  }
  else {
    param_5 = 9999999.0;
  }
  if (ABS(param_5) < 0.001 == (ABS(param_5) == 0.001)) {
    fVar2 = (*in_EAX - *param_1) * (_K_ONE / param_5);
    fVar3 = (in_EAX[1] - param_1[1]) * (_K_ONE / param_5);
    fVar4 = param_1[1] * param_1[1] + *param_1 * *param_1;
    if (ABS(fVar4) <= _K_EPS_SPEED) {
      fVar1 = 0.0;
      fVar4 = 0.0;
    }
    else {
      fVar4 = (fVar3 * param_1[1] + fVar2 * *param_1) / fVar4;
      fVar1 = fVar4 * *param_1;
      fVar4 = fVar4 * param_1[1];
    }
    fVar2 = fVar2 - fVar1;
    fVar3 = fVar3 - fVar4;
    fVar2 = SQRT(fVar2 * fVar2 + fVar3 * fVar3);
    if ((30.0 <= fVar2) && (fVar2 = ABS(fVar2 - 30.0), fVar2 < 0.001 == (fVar2 == 0.001))) {
      return 0;
    }
  }
  else {
    *param_2 = param_6;
  }
  return 1;
}


// ==== 0x45a1e0 FUN_0045a1e0

void FUN_0045a1e0(void)

{
  undefined2 uVar1;
  float fVar2;
  int unaff_ESI;
  float10 fVar3;
  float local_8;
  
  local_8 = DAT_00700680;
  fVar2 = *(float *)((*(int **)(unaff_ESI + 0x2c))[1] + 0x3d4);
  uVar1 = *(undefined2 *)(unaff_ESI + 0x3b4);
  fVar3 = (float10)(**(code **)(**(int **)(unaff_ESI + 0x2c) + 0x50))();
  fVar3 = fVar3 * (float10)fVar2;
  if (fVar3 <= (float10)local_8) {
  }
  else {
    local_8 = (float)fVar3;
  }
  FUN_0045a2f0(local_8,unaff_ESI + 0x70,unaff_ESI + 0x80,uVar1);
  return;
}


// ==== 0x45a250 FUN_0045a250

void FUN_0045a250(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EDI;
  float10 fVar5;
  
  iVar4 = *(int *)(*(int *)(unaff_EDI + 0x1d4) + 0x1c);
  if (*(int *)(iVar4 + 0xe4) != 0) {
    FUN_005791c0(iVar4);
  }
  if (*(int *)(*(int *)(*(int *)(unaff_EDI + 0x1d4) + 0x1c) + 0xe4) != 0) {
    FUN_005791c0();
  }
  puVar1 = (undefined4 *)FUN_00578730();
  iVar2 = FUN_00578730();
  uVar3 = Atan2ToAngle16(*puVar1,*(undefined4 *)(iVar2 + 4));
  iVar4 = iVar4 + 0x90;
  puVar1 = &DAT_007372a0;
  fVar5 = (float10)FUN_0057a820(iVar4,&DAT_007372a0,uVar3);
  FUN_0045a2f0((float)fVar5,iVar4,puVar1,uVar3);
  return;
}


// ==== 0x45a2f0 FUN_0045a2f0

void __thiscall
FUN_0045a2f0(char *param_1,float param_2,float *param_3,float *param_4,undefined4 param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *in_EAX;
  int local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_38;
  float local_34;
  
  FUN_00458f10(0,0);
  local_48 = *param_3;
  local_44 = param_3[1];
  fVar1 = param_4[1];
  fVar2 = *param_4;
  local_4c = 0.0;
  if (SQRT(local_48 * local_48 + local_44 * local_44) * 0.75 < SQRT(fVar2 * fVar2 + fVar1 * fVar1))
  {
    FUN_00456de0(param_2,param_5);
    return;
  }
  local_50 = 0;
  local_38 = *in_EAX;
  local_34 = in_EAX[1];
  if (0.0 < param_2) {
    while ((*param_1 < '\x14' && (local_50 < 0x14))) {
      local_48 = fVar2 * 0.1 + local_48;
      local_44 = fVar1 * 0.1 + local_44;
      fVar3 = local_48 * 0.1 + local_38;
      fVar4 = local_44 * 0.1 + local_34;
      FUN_004594d0(0xffffffff,0xffffffff,0xffffffff,1);
      local_38 = local_38 - fVar3;
      local_34 = local_34 - fVar4;
      local_50 = local_50 + 1;
      local_4c = SQRT(local_34 * local_34 + local_38 * local_38) + local_4c;
      if (local_48 * *param_3 + local_44 * param_3[1] < 0.0) {
        return;
      }
      local_38 = fVar3;
      local_34 = fVar4;
      if (param_2 <= local_4c) {
        return;
      }
    }
  }
  return;
}


// ==== 0x45a4c0 FUN_0045a4c0

void FUN_0045a4c0(void)

{
  int in_EAX;
  
  if (*(int *)(*(int *)(in_EAX + 0x14) + 4) != 1) {
    DriveTarget__GetFirstPoint(*(undefined4 *)(in_EAX + 0x3d0),in_EAX + 0x60,in_EAX + 0x70);
    FUN_0045a5b0(in_EAX + 0x60,in_EAX + 0x80);
  }
  return;
}


// ==== 0x45a510 FUN_0045a510

void FUN_0045a510(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = FUN_00647b70();
  if ((iVar1 != 6) ||
     (*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x1d4) + 0x90) + 0x14) + 4) != 1)) {
    if (*(int *)(*(int *)(*(int *)(in_EAX + 0x1d4) + 0x1c) + 0xe4) != 0) {
      FUN_005791c0();
    }
    iVar1 = *(int *)(*(int *)(in_EAX + 0x1d4) + 0x1c);
    if (*(int *)(iVar1 + 0xe4) != 0) {
      FUN_005791c0();
    }
    FUN_004596b0(param_1,in_EAX);
    FUN_0045a5b0(iVar1 + 0x40,&DAT_007372a0);
  }
  return;
}


// ==== 0x45a5b0 FUN_0045a5b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0045a5b0(char *param_1,int param_2,float *param_3,float *param_4)

{
  float fVar1;
  char cVar2;
  char cVar3;
  undefined2 uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float *in_EAX;
  char *extraout_ECX;
  char *pcVar9;
  float *pfVar10;
  float local_48;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  
  if (*(int *)(param_1 + 0x1a8) != DAT_0073ad34) {
    *(int *)(param_1 + 0x1a8) = DAT_0073ad34;
    local_40 = *param_3;
    local_3c = param_3[1];
    local_38 = *in_EAX;
    local_34 = in_EAX[1];
    fVar5 = *param_4;
    fVar6 = param_4[1];
    local_48 = 0.0;
    fVar7 = SQRT(in_EAX[2] * in_EAX[2] + in_EAX[1] * in_EAX[1] + *in_EAX * *in_EAX);
    if (_K_ONE <= fVar7) {
      pcVar9 = param_1 + param_2 * 2 + 0x164;
      pfVar10 = (float *)(param_1 + param_2 * 0x10 + 0x14);
      do {
        if (*param_1 <= param_2) {
          return;
        }
        if (param_2 == param_1[0x1a0]) {
          fVar8 = *param_3 - pfVar10[-1];
          fVar1 = param_3[1];
        }
        else {
          fVar8 = pfVar10[-5] - pfVar10[-1];
          fVar1 = pfVar10[-4];
        }
        fVar1 = SQRT(fVar8 * fVar8 + (fVar1 - *pfVar10) * (fVar1 - *pfVar10)) / fVar7;
        local_48 = fVar1 + local_48;
        local_38 = fVar5 * fVar1 + local_38;
        local_34 = fVar6 * fVar1 + local_34;
        local_40 = local_38 * fVar1 + local_40;
        local_3c = local_34 * fVar1 + local_3c;
        fVar1 = local_48 / 0.75;
        if (_K_ONE <= local_48 / 0.75) {
          fVar1 = _K_ONE;
        }
        fVar8 = _K_ONE - fVar1;
        uVar4 = *(undefined2 *)pcVar9;
        cVar2 = param_1[param_2 + 0x18c];
        cVar3 = param_1[param_2 + 0x150];
        if (-1 < param_2) {
          *pfVar10 = local_3c * fVar8 + fVar1 * *pfVar10;
          pfVar10[-1] = fVar8 * local_40 + fVar1 * pfVar10[-1];
          pfVar10[1] = 0.0;
          param_1[param_2 + 0x150] = cVar3;
          *(undefined2 *)pcVar9 = uVar4;
          param_1[param_2 + 0x18c] = cVar2;
          param_1[0x1a4] = '\0';
          param_1[0x1a5] = '\0';
          param_1[0x1a6] = '\0';
          param_1[0x1a7] = '\0';
          FUN_0045a8c0();
          param_1 = extraout_ECX;
        }
        param_2 = param_2 + 1;
        pcVar9 = pcVar9 + 2;
        pfVar10 = pfVar10 + 4;
      } while (local_48 < 0.75);
    }
  }
  return;
}


// ==== 0x45a7d0 FUN_0045a7d0

void __fastcall FUN_0045a7d0(char *param_1,int param_2,char param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *local_10;
  char *local_c;
  
  if (param_2 < *param_1) {
    if (0 < *param_1 - param_2) {
      local_10 = param_1 + param_2 * 2 + 0x164;
      local_c = param_1 + param_2 + 0x18c;
      pcVar3 = param_1 + 0x150;
      pcVar4 = param_1 + 0x164;
      pcVar5 = param_1 + param_2 * 0x10 + 0x18;
      pcVar6 = param_1 + 0x18;
      do {
        uVar1 = *(undefined4 *)(pcVar5 + -4);
        uVar2 = *(undefined4 *)pcVar5;
        *(undefined4 *)(pcVar6 + -8) = *(undefined4 *)(pcVar5 + -8);
        *(undefined4 *)(pcVar6 + -4) = uVar1;
        *(undefined4 *)pcVar6 = uVar2;
        *pcVar3 = pcVar3[param_2];
        *(undefined2 *)pcVar4 = *(undefined2 *)local_10;
        pcVar3[0x3c] = *local_c;
        local_10 = local_10 + 2;
        pcVar3 = pcVar3 + 1;
        local_c = local_c + 1;
        pcVar4 = pcVar4 + 2;
        pcVar5 = pcVar5 + 0x10;
        pcVar6 = pcVar6 + 0x10;
      } while ((int)(pcVar3 + (-0x150 - (int)param_1)) < *param_1 - param_2);
    }
    *param_1 = *param_1 - (char)param_2;
    param_1[0x1a4] = '\0';
    param_1[0x1a5] = '\0';
    param_1[0x1a6] = '\0';
    param_1[0x1a7] = '\0';
    param_1[0x1a8] = '\0';
    param_1[0x1a9] = '\0';
    param_1[0x1aa] = '\0';
    param_1[0x1ab] = '\0';
    if (param_3 != '\0') {
      FUN_0045a8c0();
    }
  }
  return;
}


// ==== 0x45a8c0 FUN_0045a8c0

void __fastcall FUN_0045a8c0(char *param_1)

{
  float *pfVar1;
  int iVar2;
  
  iVar2 = 0;
  param_1[0x1ac] = '\0';
  param_1[0x1ad] = '\0';
  param_1[0x1ae] = '\0';
  param_1[0x1af] = '\0';
  if (*param_1 != 1 && -1 < *param_1 + -1) {
    pfVar1 = (float *)(param_1 + 0x24);
    do {
      iVar2 = iVar2 + 1;
      *(float *)(param_1 + 0x1ac) =
           SQRT((pfVar1[-5] - pfVar1[-1]) * (pfVar1[-5] - pfVar1[-1]) +
                (pfVar1[-4] - *pfVar1) * (pfVar1[-4] - *pfVar1) +
                (pfVar1[-3] - pfVar1[1]) * (pfVar1[-3] - pfVar1[1])) + *(float *)(param_1 + 0x1ac);
      pfVar1 = pfVar1 + 4;
    } while (iVar2 < *param_1 + -1);
  }
  return;
}


// ==== 0x45a920 FUN_0045a920

void __fastcall FUN_0045a920(int param_1)

{
  *(undefined4 *)(param_1 + 0x4c) = 0;
  return;
}


// ==== 0x45a930 FUN_0045a930

void __thiscall FUN_0045a930(undefined4 *param_1,int param_2)

{
  char *pcVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 local_60 [36];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  void *pvStack_28;
  undefined4 uStack_20;
  void *pvStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  pcStack_18 = FUN_0068657b;
  pvStack_1c = ExceptionList;
  local_94 = *(float *)(param_2 + 0x40) + *(float *)(param_2 + 0x40);
  local_a0 = *(float *)(param_2 + 0x10) * local_94;
  local_9c = *(float *)(param_2 + 0x14) * local_94;
  local_98 = *(float *)(param_2 + 0x18) * local_94;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_94 = *(float *)(param_2 + 0x1c) * local_94;
  local_64 = 0x3f800000;
  local_e0 = 0x3f800000;
  local_dc = 0;
  local_d8 = 0;
  local_d4 = 0;
  local_84 = *(float *)(param_2 + 0x44) + *(float *)(param_2 + 0x44);
  local_d0 = 0;
  local_cc = 0x3f800000;
  local_c8 = 0;
  local_90 = *(float *)(param_2 + 0x20) * local_84;
  local_c4 = 0;
  local_c0 = 0;
  local_bc = 0;
  local_b8 = 0x3f800000;
  local_b4 = 0;
  local_8c = *(float *)(param_2 + 0x24) * local_84;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0x3f800000;
  local_88 = *(float *)(param_2 + 0x28) * local_84;
  local_84 = *(float *)(param_2 + 0x2c) * local_84;
  local_74 = *(float *)(param_2 + 0x48) + *(float *)(param_2 + 0x48);
  local_80 = *(float *)(param_2 + 0x30) * local_74;
  local_7c = *(float *)(param_2 + 0x34) * local_74;
  local_78 = *(float *)(param_2 + 0x38) * local_74;
  local_74 = local_74 * *(float *)(param_2 + 0x3c);
  ExceptionList = &pvStack_1c;
  D3DXMatrixMultiply(local_60,&local_a0,&local_e0);
  uStack_34 = param_1[2];
  uStack_3c = *param_1;
  uStack_38 = param_1[1];
  if (*(int *)(param_2 + 0x4c) == 0) {
    puVar3 = (undefined4 *)FUN_00567160();
    uStack_20 = 0;
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      pcVar6 = "DEBUG_CUBE";
      do {
        pcVar1 = pcVar6 + 1;
        pcVar6 = pcVar6 + 1;
      } while (*pcVar1 != '\0');
      iVar4 = FUN_00567160();
      if (iVar4 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = FUN_004454d0();
      }
      puVar3[2] = uVar5;
      puVar3[3] = 0;
      puVar3[5] = 1;
      puVar3[6] = 0;
      puVar3[4] = 0;
      puVar3[0x18] = 0;
      *DAT_00737820 = puVar3;
      puVar2 = puVar3;
      puVar3[1] = DAT_00737820;
      DAT_00737820 = puVar2;
      *puVar3 = &DAT_0073781c;
      *(undefined1 *)(puVar3 + 7) = 0;
    }
    uStack_20 = 0xffffffff;
    *(undefined4 **)(param_2 + 0x4c) = puVar3;
  }
  iVar4 = *(int *)(*(int *)(param_2 + 0x4c) + 0x60);
  *(undefined4 *)(*(int *)(param_2 + 0x4c) + 0x10) = 1;
  if (iVar4 == 0) {
    bMatrixCopy_b();
  }
  else {
    bMatrixCopy_b();
    if (*(int *)(iVar4 + 0xe4) == 0) {
      FUN_00579190();
      ExceptionList = pvStack_28;
      return;
    }
  }
  ExceptionList = pvStack_28;
  return;
}


// ==== 0x45ac50 FUN_0045ac50

undefined4 FUN_0045ac50(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x3dc);
}


// ==== 0x45ac60 FUN_0045ac60

void FUN_0045ac60(void)

{
  int in_EAX;
  int iVar1;
  char cVar2;
  int unaff_ESI;
  
  FUN_00571ea0(0,"DrivingChoice");
  FUN_00571c20(unaff_ESI,in_EAX,1,4,1);
  FUN_00571c20(unaff_ESI,in_EAX + 0xc,1,1,0);
  FUN_00571c20(unaff_ESI,in_EAX + 8,4,0xffffffff,0);
  iVar1 = *(char *)(unaff_ESI + 0x40) * 0x10;
  *(int *)(iVar1 + unaff_ESI + 0x58) =
       *(int *)(unaff_ESI + 0x150) - *(int *)(iVar1 + 0x58 + unaff_ESI);
  cVar2 = *(char *)(unaff_ESI + 0x40) + -1;
  *(char *)(unaff_ESI + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(unaff_ESI + 0x44)) {
    *(undefined4 *)(unaff_ESI + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x45ace0 FUN_0045ace0

void __fastcall FUN_0045ace0(int param_1,int param_2,undefined1 param_3,int param_4)

{
  int *in_EAX;
  
  if (param_1 == 1) {
    if (param_2 != 0) {
      return;
    }
  }
  else {
    if ((param_1 < 2) || (3 < param_1)) {
      if (param_1 != 0) {
        return;
      }
      *in_EAX = 0;
      in_EAX[1] = 0;
      *(undefined1 *)(in_EAX + 3) = 0;
      in_EAX[2] = 0;
      return;
    }
    if (param_2 == 0) {
      return;
    }
  }
  *in_EAX = param_1;
  in_EAX[1] = param_2;
  *(undefined1 *)(in_EAX + 3) = param_3;
  in_EAX[2] = param_4;
  return;
}


// ==== 0x45ad30 FUN_0045ad30

bool __fastcall FUN_0045ad30(int *param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (iVar3 == 1) {
    iVar3 = *(int *)(in_EAX + 0x38c);
    iVar1 = *(int *)(in_EAX + 0x394);
    iVar2 = (**(code **)(**(int **)(in_EAX + 0x3a8) + 8))(iVar1);
    if (iVar3 != 0) {
      if ((-1 < iVar1) && (iVar1 < 5)) {
        if ((*(char *)(iVar2 * 0x34 + 0x34 + iVar3) == '\0') &&
           (*(char *)(iVar2 * 0x34 + iVar3 + 0x35) == '\0')) {
          return false;
        }
        return true;
      }
      if ((10 < iVar1) && (iVar1 < 0x11)) {
        return *(char *)(iVar2 + 0x265 + iVar3) != '\0';
      }
    }
  }
  else if ((1 < iVar3) && (iVar3 < 4)) {
    iVar3 = FUN_0057b520();
    return iVar3 != 0;
  }
  return false;
}


// ==== 0x45add0 FUN_0045add0

undefined4 __fastcall FUN_0045add0(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  if ((iVar1 < 2) || (3 < iVar1)) {
    if ((iVar1 == *param_1) &&
       (ABS((float)param_2[2] - (float)param_1[2]) < 0.001 !=
        (ABS((float)param_2[2] - (float)param_1[2]) == 0.001))) {
      return 1;
    }
  }
  else if ((param_2[1] == param_1[1]) && (iVar1 == *param_1)) {
    return 1;
  }
  return 0;
}


// ==== 0x45ae10 FUN_0045ae10

/* WARNING: Removing unreachable block (ram,0x0045ae62) */
/* WARNING: Removing unreachable block (ram,0x0045ae6f) */
/* WARNING: Removing unreachable block (ram,0x0045ae71) */

undefined1
FUN_0045ae10(int *param_1,undefined4 *param_2,int *param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  puVar6 = param_2;
  iVar1 = *param_3;
  iVar5 = *(int *)(iVar1 + 0x2c);
  piVar2 = *(int **)(iVar5 + 0x3fc);
  if (((piVar2 == (int *)0x0) || (cVar3 = (**(code **)(*piVar2 + 0x1c))(), cVar3 == '\0')) &&
     (*(char *)(iVar5 + 0x4bc) == '\0')) {
    puVar6 = (undefined4 *)(*(int *)(iVar1 + 0x30) + 0x10);
    puVar7 = param_2;
    for (iVar5 = 0x70; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    DriveTarget__GetFirstPoint(*(undefined4 *)(iVar1 + 0x3d0),iVar1 + 0x60,iVar1 + 0x70);
    FUN_0045a7d0(1);
    uVar4 = 1;
    if (ABS((float)param_1[2]) < 0.001 != (ABS((float)param_1[2]) == 0.001)) {
      uVar4 = param_5;
    }
    FUN_0045c370(param_2,param_3,DAT_00700638,uVar4,param_1[2],0x47c34f80);
    param_2._0_1_ = 1;
  }
  else {
    FUN_00458f10(0,0);
    cVar3 = FUN_0045ad30();
    if (cVar3 == '\0') {
      param_2._0_1_ = 0;
      FUN_0045c370(puVar6,param_3,DAT_00700638,param_5,0,0x47c34f80);
    }
    else if (*param_1 == 1) {
      uVar4 = 1;
      if (ABS((float)param_1[2]) < 0.001 != (ABS((float)param_1[2]) == 0.001)) {
        uVar4 = param_5;
      }
      FUN_0045c370(param_2,param_3,DAT_00700638,uVar4,param_1[2],0x47c34f80);
      param_2._0_1_ = 1;
    }
    else {
      param_2._0_1_ = FUN_0045c760(param_1,param_2,param_3);
    }
  }
  iVar1 = *param_1;
  if (iVar1 != 1) {
    if ((1 < iVar1) && (iVar1 < 4)) {
      *(undefined4 *)(*(int *)(*param_3 + 0x2c) + 1000) = 0;
    }
    return param_2._0_1_;
  }
  *(undefined4 *)(*(int *)(*param_3 + 0x2c) + 1000) = 0;
  return param_2._0_1_;
}


// ==== 0x45afd0 FUN_0045afd0

void __thiscall
FUN_0045afd0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *in_EAX;
  
  puVar1 = (undefined4 *)(param_1 + 0x38c);
  uVar2 = *puVar1;
  uVar3 = *(undefined4 *)(param_1 + 0x390);
  uVar4 = *(undefined4 *)(param_1 + 0x394);
  *puVar1 = *in_EAX;
  *(undefined4 *)(param_1 + 0x390) = in_EAX[1];
  *(undefined4 *)(param_1 + 0x394) = in_EAX[2];
  FUN_0045b050(param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  *puVar1 = uVar2;
  *(undefined4 *)(param_1 + 0x390) = uVar3;
  *(undefined4 *)(param_1 + 0x394) = uVar4;
  return;
}


// ==== 0x45b050 FUN_0045b050

uint __thiscall
FUN_0045b050(undefined4 param_1,int param_2,char param_3,float *param_4,undefined4 *param_5,
            float *param_6,undefined4 param_7,float param_8)

{
  float fVar1;
  uint uVar2;
  undefined2 extraout_var;
  undefined4 uVar3;
  int *unaff_ESI;
  int unaff_EDI;
  float10 fVar4;
  
  *param_4 = -1.0;
  *param_5 = 0;
  *param_6 = 99999.0;
  uVar2 = FUN_0045ae10(param_2,unaff_EDI,unaff_ESI,param_7,param_1);
  if ((char)uVar2 != '\0') {
    fVar4 = (float10)FUN_00459b30(unaff_EDI,*unaff_ESI);
    fVar1 = (float)fVar4;
    *param_4 = fVar1;
    uVar2 = CONCAT22(extraout_var,
                     (ushort)(fVar1 < -1.0) << 8 | (ushort)NAN(fVar1) << 10 |
                     (ushort)(fVar1 == -1.0) << 0xe);
    if (fVar1 < -1.0 == 0 && (fVar1 == -1.0) == 0) {
      if ((param_3 == '\0') || (*(char *)(unaff_EDI + 0x1b1) != '\0')) {
        *(undefined4 *)(*(int *)(*unaff_ESI + 0x2c) + 1000) = 0;
      }
      else {
        *param_4 = fVar1 * 1.2;
        *(undefined4 *)(*(int *)(*unaff_ESI + 0x2c) + 1000) = *(undefined4 *)(param_2 + 4);
      }
      uVar3 = FUN_00457590(&DAT_0077a4ac,unaff_EDI,unaff_ESI + 0xe3,param_8,param_6);
      *param_5 = uVar3;
      fVar1 = *param_6;
      uVar2 = CONCAT31((int3)(CONCAT22((short)((uint)uVar3 >> 0x10),
                                       (ushort)(fVar1 < param_8) << 8 |
                                       (ushort)(NAN(fVar1) || NAN(param_8)) << 10 |
                                       (ushort)(fVar1 == param_8) << 0xe) >> 8),1);
      if ((uVar2 & 0x4100) == 0) goto LAB_0045b12a;
    }
  }
  uVar2 = uVar2 & 0xffffff00;
LAB_0045b12a:
  *(int *)(DAT_007361f8 + 0x2f8) = *(int *)(DAT_007361f8 + 0x2f8) + 1;
  return uVar2;
}


// ==== 0x45b150 FUN_0045b150

char FUN_0045b150(undefined4 *param_1,undefined4 *param_2,int *param_3,undefined4 param_4,
                 char *param_5,char param_6)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  char local_7a2;
  char local_7a1;
  int *local_7a0;
  int local_79c;
  int local_798;
  int local_794;
  int local_790;
  int local_78c;
  float local_788;
  undefined1 local_784;
  undefined1 local_5c0;
  undefined4 local_5bc;
  undefined4 local_5b8;
  undefined4 local_5b4;
  int local_5b0;
  int local_5ac;
  float local_5a8;
  undefined1 local_5a4;
  undefined4 local_5a0 [112];
  char local_3e0;
  float local_3dc;
  int local_3d8;
  float local_3d4;
  undefined4 local_3d0;
  undefined4 local_3cc;
  undefined4 local_3c8;
  undefined1 local_3c4;
  undefined4 local_3c0 [112];
  undefined1 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  float local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined1 local_1e4;
  undefined4 local_1e0 [112];
  char local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_79c = 0;
  local_7a2 = '\0';
  FUN_0045b860();
  FUN_0045b860();
  FUN_0045b860();
  FUN_0045b860();
  local_5b0 = 0;
  local_5ac = 0;
  local_5a8 = 0.0;
  local_5a4 = 0;
  FUN_00458f10(0,0);
  local_3e0 = '\0';
  local_3dc = -1.0;
  local_3d8 = 0;
  local_3d4 = 99999.0;
  local_790 = 0;
  local_78c = 0;
  local_788 = 0.0;
  local_784 = 0;
  FUN_00458f10(0,0);
  local_5c0 = 0;
  local_5bc = 0xbf800000;
  local_5b8 = 0;
  local_5b4 = 0x47c34f80;
  local_1f0 = 0;
  local_1ec = 0;
  local_1e8 = 0;
  local_1e4 = 0;
  FUN_00458f10(0,0);
  local_20 = '\0';
  local_1c = 0xbf800000;
  local_18 = 0;
  local_14 = 0x47c34f80;
  local_3d0 = 0;
  local_3cc = 0;
  local_3c8 = 0;
  local_3c4 = 0;
  FUN_00458f10(0,0);
  local_200 = 0;
  local_1fc = 0xbf800000;
  local_1f8 = 0;
  local_1f4 = 99999.0;
  local_5b0 = 1;
  local_5ac = 0;
  local_5a4 = 0;
  local_5a8 = 0.0;
  cVar3 = FUN_0045ad30();
  if (cVar3 != '\0') {
    FUN_0044a000();
  }
  if (param_6 == '\0') {
LAB_0045b3bf:
    local_790 = 1;
    local_78c = 0;
    local_784 = 0;
    local_788 = 0.0;
    if (((param_6 == '\0') || (local_5b0 != 1)) ||
       (ABS(-local_5a8) < 0.001 == (ABS(-local_5a8) == 0.001))) {
      local_5c0 = 0;
      FUN_0045b900(&local_790,param_4,&local_7a2,&local_1f0,&local_3d0,local_79c);
      if (local_7a2 != '\0') goto LAB_0045b71b;
    }
    local_798 = 0;
    if (0 < param_3[1]) {
      local_7a0 = param_3 + 0xf;
      do {
        piVar6 = local_7a0 + -0xd;
        cVar3 = FUN_00456780(piVar6);
        if (cVar3 != '\0') {
          local_7a1 = '\0';
          iVar4 = FUN_0045c0d0(param_1,piVar6);
          if (*local_7a0 != 0) {
            local_790 = 2;
            local_784 = 0;
            local_788 = 0.0;
            local_78c = *local_7a0;
          }
          if ((iVar4 == 2) || (iVar4 == 1)) {
            local_5c0 = 1;
          }
          else {
            local_5c0 = 0;
          }
          local_794 = iVar4;
          if (param_6 == '\0') {
LAB_0045b510:
            cVar3 = FUN_0045b900(&local_790,param_4,&local_7a2,&local_1f0,&local_3d0,local_79c);
            local_7a1 = cVar3 != '\0';
          }
          else if ((local_790 < 2) || (3 < local_790)) {
            if ((local_790 != local_5b0) ||
               (ABS(local_788 - local_5a8) < 0.001 == (ABS(local_788 - local_5a8) == 0.001)))
            goto LAB_0045b510;
          }
          else if ((local_78c != local_5ac) || (local_790 != local_5b0)) goto LAB_0045b510;
          if (*local_7a0 != 0) {
            local_790 = 3;
            local_784 = 0;
            local_788 = 0.0;
            local_78c = *local_7a0;
          }
          if ((iVar4 == 3) || (iVar4 == 1)) {
            local_5c0 = 1;
          }
          else {
            local_5c0 = 0;
          }
          if (param_6 == '\0') {
LAB_0045b657:
            cVar3 = FUN_0045b900(&local_790,param_4,&local_7a2,&local_1f0,&local_3d0,local_79c);
            if (local_7a1 != '\0') goto LAB_0045b6f3;
          }
          else {
            cVar3 = local_7a1;
            if ((local_790 < 2) || (3 < local_790)) {
              if ((local_790 != local_5b0) ||
                 (ABS(local_788 - local_5a8) < 0.001 == (ABS(local_788 - local_5a8) == 0.001)))
              goto LAB_0045b657;
            }
            else if ((local_78c != local_5ac) || (local_790 != local_5b0)) goto LAB_0045b657;
          }
          if (cVar3 == '\0') {
            iVar4 = *param_3;
            iVar1 = *(int *)(*(int *)(*local_7a0 + 0x1d4) + 0x1c);
            if (*(int *)(iVar1 + 0xe4) != 0) {
              FUN_005791c0();
            }
            if (*(float *)(iVar1 + 0x90) * *(float *)(iVar4 + 0x70) +
                *(float *)(iVar1 + 0x94) * *(float *)(iVar4 + 0x74) < 0.0) {
              if (local_794 == 2) {
                iVar4 = *local_7a0;
                if (iVar4 != 0) {
                  local_790 = 2;
LAB_0045b6a9:
                  local_784 = 1;
                  local_788 = 0.0;
                  local_78c = iVar4;
                }
              }
              else {
                iVar4 = *local_7a0;
                if (iVar4 != 0) {
                  local_790 = 3;
                  goto LAB_0045b6a9;
                }
              }
              local_5c0 = 1;
              FUN_0045b900(&local_790,param_4,&local_7a2,&local_1f0,&local_3d0,local_79c);
            }
          }
        }
LAB_0045b6f3:
        local_798 = local_798 + 1;
        local_7a0 = local_7a0 + 0xe;
      } while (local_798 < param_3[1]);
      if (local_7a2 != '\0') goto LAB_0045b71b;
    }
    cVar3 = FUN_0045ad30();
    uVar2 = DAT_00700638;
    if ((cVar3 == '\0') || (local_3d4 - 0.1 < local_1f4 == (local_3d4 - 0.1 == local_1f4))) {
      if (ABS(local_3dc - -1.0) < 0.001 == (ABS(local_3dc - -1.0) == 0.001)) {
        FUN_0044a000();
        puVar5 = local_5a0;
        for (iVar4 = 0x70; iVar4 != 0; iVar4 = iVar4 + -1) {
          *param_2 = *puVar5;
          puVar5 = puVar5 + 1;
          param_2 = param_2 + 1;
        }
        *param_5 = local_3e0;
      }
      else {
        *param_1 = 1;
        param_1[1] = 0;
        *(undefined1 *)(param_1 + 3) = 0;
        param_1[2] = 0;
        FUN_0045c370(param_2,param_3,uVar2,2,0,0x47c34f80);
        *param_5 = '\0';
        local_7a2 = '\0';
      }
    }
    else {
      FUN_0044a000();
      puVar5 = local_3c0;
      for (iVar4 = 0x70; iVar4 != 0; iVar4 = iVar4 + -1) {
        *param_2 = *puVar5;
        puVar5 = puVar5 + 1;
        param_2 = param_2 + 1;
      }
      *param_5 = '\x01';
    }
  }
  else {
    local_3e0 = '\0';
    if (((1 < local_5b0) && (local_5b0 < 4)) && (iVar4 = FUN_0057b520(), iVar4 != 0)) {
      FUN_0045c0d0(param_1,iVar4);
      local_3e0 = FUN_0045cfb0();
    }
    FUN_0045b900(&local_5b0,param_4,&local_7a2,&local_1f0,&local_3d0,0);
    local_79c = local_3d8;
    if ((local_3e0 != '\0') && (local_5ac == local_3d8)) {
      FUN_0045b8a0();
    }
    if (local_7a2 == '\0') goto LAB_0045b3bf;
LAB_0045b71b:
    FUN_0044a000();
    puVar5 = local_1e0;
    for (iVar4 = 0x70; iVar4 != 0; iVar4 = iVar4 + -1) {
      *param_2 = *puVar5;
      puVar5 = puVar5 + 1;
      param_2 = param_2 + 1;
    }
    *param_5 = local_20;
  }
  FUN_0045bfb0(*param_3,*param_5,param_3);
  return local_7a2;
}


// ==== 0x45b860 FUN_0045b860

void FUN_0045b860(void)

{
  int iVar1;
  undefined4 *unaff_ESI;
  undefined4 *puVar2;
  
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  *(undefined1 *)(unaff_ESI + 3) = 0;
  unaff_ESI[0x6d] = 0;
  unaff_ESI[0x6e] = 0;
  puVar2 = unaff_ESI + 4;
  for (iVar1 = 0x70; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  FUN_00458f10(0,0);
  return;
}


// ==== 0x45b8a0 FUN_0045b8a0

void __fastcall FUN_0045b8a0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_EAX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *in_EAX = *param_2;
  in_EAX[1] = param_2[1];
  in_EAX[2] = param_2[2];
  in_EAX[3] = param_2[3];
  puVar2 = param_2 + 4;
  puVar3 = in_EAX + 4;
  for (iVar1 = 0x70; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined1 *)(in_EAX + 0x74) = *(undefined1 *)(param_2 + 0x74);
  in_EAX[0x75] = param_2[0x75];
  in_EAX[0x76] = param_2[0x76];
  in_EAX[0x77] = param_2[0x77];
  return;
}


// ==== 0x45b900 FUN_0045b900

bool FUN_0045b900(int *param_1,undefined4 param_2,undefined1 *param_3,int param_4,undefined4 param_5
                 ,int param_6)

{
  float *pfVar1;
  bool bVar2;
  float fVar3;
  char cVar4;
  
  param_1[0x76] = 0;
  pfVar1 = (float *)(param_1 + 0x75);
  param_1[0x77] = 0x47c34f80;
  *pfVar1 = -1.0;
  cVar4 = FUN_0045b050(param_1,(char)param_1[0x74],pfVar1,param_1 + 0x76,param_1 + 0x77,0,param_2);
  if ((cVar4 != '\0') &&
     ((*(float *)(param_4 + 0x1d4) < *pfVar1 ||
      (fVar3 = ABS(*pfVar1 - *(float *)(param_4 + 0x1d4)), fVar3 < 0.1 != (fVar3 == 0.1))))) {
    *param_3 = 1;
    FUN_0045b8a0();
  }
  bVar2 = ABS(*pfVar1 - -1.0) < 0.001 == (ABS(*pfVar1 - -1.0) == 0.001);
  if ((((bVar2) && (1 < *param_1)) && (*param_1 < 4)) &&
     ((((char)param_1[3] == '\0' && (param_1[1] == param_6)) && ((char)param_1[0x74] != '\0')))) {
    FUN_0045b8a0();
  }
  return bVar2;
}


// ==== 0x45b9f0 FUN_0045b9f0

undefined4 __fastcall FUN_0045b9f0(int param_1)

{
  int iVar1;
  int iVar2;
  int *in_EAX;
  int iVar3;
  int extraout_EDX;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  
  iVar1 = *in_EAX;
  if (iVar1 == 1) {
    return 1;
  }
  if ((1 < iVar1) && (iVar1 < 4)) {
    iVar2 = *(int *)(param_1 + 0x394);
    iVar3 = FUN_0057b520();
    iVar3 = *(int *)(*(int *)(param_1 + 0x3a8) + 8 + *(int *)(iVar3 + 0x30) * 4);
    fVar4 = (float10)FUN_0057b480();
    fVar5 = (float10)*(float *)(*(char *)(param_1 + 0x388) * 0x38 + 0x10 + param_1) +
            (float10)*(float *)(extraout_EDX + 8) + (float10)5.0;
    if (iVar1 == 2) {
      if ((iVar2 < 0) || (4 < iVar2)) {
        if ((iVar2 < 0xb) || (0x10 < iVar2)) {
          fVar6 = (float10)0.0;
        }
        else {
          fVar6 = (float10)*(float *)(iVar3 + -8 + iVar2 * 4);
        }
      }
      else {
        fVar6 = (float10)*(float *)(iVar3 + 0x20);
      }
      if (fVar6 <= fVar4 - fVar5) {
        return 1;
      }
    }
    else {
      if ((iVar2 < 0) || (4 < iVar2)) {
        if ((iVar2 < 0xb) || (0x10 < iVar2)) {
          fVar6 = (float10)0.0;
        }
        else {
          fVar6 = (float10)*(float *)(iVar3 + 0x14 + iVar2 * 4);
        }
      }
      else {
        fVar6 = (float10)*(float *)(iVar3 + 0x3c);
      }
      fVar5 = fVar5 + fVar4;
      if (fVar5 < fVar6 != (fVar5 == fVar6)) {
        return 1;
      }
    }
    return 0;
  }
  return 0;
}


// ==== 0x45bae0 FUN_0045bae0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_0045bae0(int *param_1,undefined4 *param_2,undefined1 *param_3,int param_4,int *param_5,
                 undefined4 param_6,undefined4 param_7,char param_8)

{
  bool bVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  char local_21a;
  uint local_218;
  int local_214;
  undefined4 local_210;
  undefined1 local_20c;
  undefined4 local_208;
  uint local_204;
  int local_200;
  float local_1fc;
  undefined1 local_1f8;
  undefined1 local_1f4 [4];
  undefined4 local_1f0;
  undefined4 local_1ec;
  int local_1e8;
  undefined4 local_1e4;
  undefined1 local_1e0;
  undefined4 local_1dc;
  int local_1d8;
  float local_1d4;
  undefined4 local_1d0 [115];
  
  local_1d8 = FUN_0045c0d0(param_1,param_4);
  local_1f0 = 0xbf800000;
  local_21a = '\0';
  local_208 = 0x47c34f80;
  FUN_00458150(param_2);
  local_1d4 = -1.0;
  local_204 = 0;
  local_200 = 0;
  local_1fc = 0.0;
  local_1f8 = 0;
  if (*param_1 != 0) {
    FUN_0044a000();
  }
  iVar4 = *(int *)(*(int *)(*(int *)(param_4 + 0x34) + 0x1d4) + 0x1c);
  if (*(int *)(iVar4 + 0xe4) != 0) {
    FUN_005791c0();
  }
  if ((_DAT_00700674 <
       SQRT(*(float *)(iVar4 + 0x98) * *(float *)(iVar4 + 0x98) +
            *(float *)(iVar4 + 0x94) * *(float *)(iVar4 + 0x94) +
            *(float *)(iVar4 + 0x90) * *(float *)(iVar4 + 0x90))) ||
     (bVar1 = false, _DAT_00700674 < *(float *)(*param_5 + 0x3d4))) {
    bVar1 = true;
  }
  if (((param_8 != '\0') &&
      (((local_204 != 1 || (bVar1)) && (cVar2 = FUN_0045ad30(), cVar2 != '\0')))) &&
     ((((int)local_204 < 2 || (3 < (int)local_204)) || (*(int *)(param_4 + 0x34) == local_200)))) {
    uVar3 = FUN_0045cfb0();
    puVar5 = local_1d0;
    puVar6 = param_2;
    for (iVar4 = 0x70; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    local_1dc = CONCAT31(local_1dc._1_3_,uVar3);
    cVar2 = FUN_0045b050(&local_204,local_1dc,&local_1d4,local_1f4,&local_208,param_6,param_7);
    if (cVar2 != '\0') {
      *param_3 = (undefined1)local_1dc;
      local_21a = '\x01';
    }
  }
  local_218 = 0;
  local_214 = 0;
  local_210 = 0;
  local_20c = 0;
  if (local_21a != '\0') goto LAB_0045bf83;
  if (bVar1) {
    local_214 = 0;
    local_20c = 0;
    local_210 = 0;
    local_218 = 1;
    if ((param_8 == '\0') || (cVar2 = FUN_0045add0(), cVar2 == '\0')) {
      puVar5 = local_1d0;
      puVar6 = param_2;
      for (iVar4 = 0x70; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      cVar2 = FUN_0045b050(&local_218,0,&local_1f0,local_1f4,&local_208,param_6,param_7);
      if (cVar2 != '\0') {
        FUN_0044a000();
        *param_3 = 0;
        local_21a = '\x01';
        goto LAB_0045bf83;
      }
    }
  }
  local_218 = 0;
  local_1ec = 0;
  local_1e8 = 0;
  if ((local_1d8 == 2) || (local_1d8 == 1)) {
    if (*(int *)(param_4 + 0x34) != 0) {
      local_218 = 2;
      local_1ec = 3;
      local_1e8 = *(int *)(param_4 + 0x34);
    }
  }
  else if (*(int *)(param_4 + 0x34) != 0) {
    local_218 = 3;
    local_1ec = 2;
    local_1e8 = *(int *)(param_4 + 0x34);
  }
  local_1e0 = 0;
  local_1e4 = 0;
  local_20c = 0;
  local_210 = 0;
  local_214 = local_1e8;
  if (param_8 == '\0') {
LAB_0045be88:
    if ((bVar1) || (cVar2 = FUN_0045b9f0(), cVar2 != '\0')) {
      puVar5 = local_1d0;
      puVar6 = param_2;
      for (iVar4 = 0x70; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      cVar2 = FUN_0045b050(&local_218,1,&local_1f0,local_1f4,&local_208,param_6,param_7);
      if (cVar2 != '\0') {
        FUN_0044a000();
        *param_3 = 1;
        local_21a = '\x01';
        goto LAB_0045bf83;
      }
    }
  }
  else if ((local_218 < 2) || (3 < local_218)) {
    if ((local_218 != local_204) || (ABS(-local_1fc) < 0.001 == (ABS(-local_1fc) == 0.001)))
    goto LAB_0045be88;
  }
  else if ((local_1e8 != local_200) || (local_218 != local_204)) goto LAB_0045be88;
  if (((param_8 == '\0') || (cVar2 = FUN_0045add0(), cVar2 == '\0')) &&
     ((bVar1 || (cVar2 = FUN_0045b9f0(), cVar2 != '\0')))) {
    puVar5 = local_1d0;
    puVar6 = param_2;
    for (iVar4 = 0x70; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    cVar2 = FUN_0045b050(&local_1ec,0,&local_1f0,local_1f4,&local_208,param_6,param_7);
    if (cVar2 != '\0') {
      FUN_0044a000();
      *param_3 = 0;
      local_21a = '\x01';
      goto LAB_0045bf83;
    }
  }
  local_218 = 0;
  local_214 = 0;
  local_210 = 0;
  local_20c = 0;
  cVar2 = FUN_0045ad30();
  if ((cVar2 == '\0') || (ABS(local_1d4 - -1.0) < 0.001 != (ABS(local_1d4 - -1.0) == 0.001))) {
    local_218 = 1;
    local_214 = 0;
    local_20c = 0;
    local_210 = 0;
  }
  else {
    FUN_0044a000();
  }
  FUN_0045ae10(&local_218,param_2,param_5,param_6,2);
  FUN_0044a000();
LAB_0045bf83:
  FUN_0045bfb0(*param_5,*param_3,param_5);
  return local_21a;
}


// ==== 0x45bfb0 FUN_0045bfb0

void __thiscall FUN_0045bfb0(int param_1,int param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  char cVar4;
  float *pfVar5;
  int iVar6;
  int *unaff_EDI;
  
  iVar6 = *unaff_EDI;
  if (iVar6 != 1) {
    if (iVar6 < 2) {
      return;
    }
    if (3 < iVar6) {
      return;
    }
    if ((param_3 != '\0') && (*(char *)(param_1 + 0x1b1) == '\0')) {
      bVar3 = true;
      cVar4 = FUN_0057a720();
      if ((cVar4 != '\0') &&
         (pfVar5 = (float *)FUN_00578730(),
         *pfVar5 * *(float *)(param_2 + 0x90) + pfVar5[1] * *(float *)(param_2 + 0x94) < 0.0)) {
        iVar6 = FUN_0057a7a0();
        piVar1 = *(int **)(iVar6 + 0x3dc);
        iVar6 = FUN_00457570();
        cVar4 = FUN_0044a060();
        if (((cVar4 != '\0') && (*(int *)(piVar1[1] + 0x1d4) == *(int *)(param_2 + 0x82c))) &&
           (((iVar2 = *piVar1, iVar2 == 2 && (*unaff_EDI == 3)) ||
            ((iVar2 == 3 && (*unaff_EDI == 2)))))) {
          bVar3 = false;
        }
        if ((iVar6 == 9) && (*unaff_EDI == 2)) {
          return;
        }
        if (!bVar3) {
          return;
        }
      }
      cVar4 = FUN_0045b9f0();
      if (cVar4 == '\0') {
        return;
      }
      *(int *)(*(int *)(param_2 + 0x2c) + 1000) = unaff_EDI[1];
      return;
    }
  }
  *(undefined4 *)(*(int *)(param_2 + 0x2c) + 1000) = 0;
  return;
}


// ==== 0x45c0d0 FUN_0045c0d0

int FUN_0045c0d0(undefined4 param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  int *unaff_EDI;
  bool bVar11;
  ushort uVar12;
  float10 fVar13;
  float local_1c;
  float local_18;
  
  iVar9 = (int)(char)unaff_EDI[0xe2];
  fVar2 = *(float *)(param_2 + 0x10);
  iVar3 = unaff_EDI[0xe5];
  fVar4 = *(float *)(param_2 + 0xc);
  if ((iVar3 < 0) || (4 < iVar3)) {
    if ((iVar3 < 0xb) || (0x10 < iVar3)) {
      local_1c = 0.0;
    }
    else {
      local_1c = *(float *)(param_2 + -0x14 + iVar3 * 4);
    }
  }
  else {
    local_1c = *(float *)(param_2 + 0x14);
  }
  iVar5 = *(int *)(unaff_EDI[0xea] + 8 + *(int *)(param_2 + 0x30) * 4);
  fVar6 = (float)unaff_EDI[iVar9 * 0xe + 6];
  fVar7 = (float)unaff_EDI[iVar9 * 0xe + 5];
  if ((iVar3 < 0) || (4 < iVar3)) {
    if ((iVar3 < 0xb) || (0x10 < iVar3)) {
      local_18 = 0.0;
    }
    else {
      local_18 = (float)unaff_EDI[iVar9 * 0xe + iVar3 + -3];
    }
  }
  else {
    local_18 = (float)unaff_EDI[iVar9 * 0xe + 7];
  }
  fVar13 = (float10)FUN_005a6860(iVar3,0xbf800000);
  fVar1 = (float)fVar13;
  bVar11 = 0.0 < (fVar2 - fVar6) - (fVar7 + 5.0 + fVar4);
  iVar10 = 3;
  if ((*(int *)(*(int *)(*unaff_EDI + 0x14) + 4) != 3) || (5.0 <= local_1c)) {
    if ((ABS(local_18) < 1.0 == (ABS(local_18) == 1.0)) ||
       (((ABS(local_1c) < 1.0 == (ABS(local_1c) == 1.0) ||
         (*(float *)(param_2 + 0x10) - (float)unaff_EDI[(char)unaff_EDI[0xe2] * 0xe + 6] <= 50.0))
        || (ABS(fVar1) < 0.12)))) {
      if ((ABS(local_18 - local_1c) < 2.0) && (bVar11)) {
        iVar10 = 1;
        goto LAB_0045c27b;
      }
      uVar12 = (ushort)(local_18 < local_1c) << 8 | (ushort)(local_18 == local_1c) << 0xe;
    }
    else {
      uVar12 = (ushort)(fVar1 < 0.0) << 8 | (ushort)(fVar1 == 0.0) << 0xe;
    }
    if (uVar12 != 0) {
      iVar10 = 2;
    }
  }
LAB_0045c27b:
  fVar2 = (float)unaff_EDI[iVar9 * 0xe + 4] + *(float *)(param_2 + 8) + 5.0;
  if ((iVar3 < 0) || (4 < iVar3)) {
    if ((iVar3 < 0xb) || (0x10 < iVar3)) {
      fVar4 = 0.0;
    }
    else {
      fVar4 = *(float *)(iVar5 + -8 + iVar3 * 4);
    }
  }
  else {
    fVar4 = *(float *)(iVar5 + 0x20);
  }
  bVar8 = fVar4 <= local_1c - fVar2;
  if ((iVar3 < 0) || (4 < iVar3)) {
    if ((iVar3 < 0xb) || (0x10 < iVar3)) {
      fVar4 = 0.0;
    }
    else {
      fVar4 = *(float *)(iVar5 + 0x14 + iVar3 * 4);
    }
  }
  else {
    fVar4 = *(float *)(iVar5 + 0x3c);
  }
  fVar2 = fVar2 + local_1c;
  if (((iVar10 != 2) && (iVar10 != 1)) || (bVar8)) {
    if (((iVar10 == 3) || (iVar10 == 1)) && ((fVar4 < fVar2 && ((bVar8 && (bVar11)))))) {
      return 2;
    }
  }
  else if ((fVar2 <= fVar4) && (bVar11)) {
    return 3;
  }
  return iVar10;
}


// ==== 0x45c370 FUN_0045c370

void FUN_0045c370(char *param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,float param_6)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  float10 fVar6;
  float local_8;
  int local_4;
  
  piVar4 = param_2;
  iVar2 = param_2[0xe5];
  iVar3 = param_2[0xea];
  if (((param_2[0xe3] != 0) && (*(int *)(iVar3 + 4) != 0)) && (cVar1 = *param_1, cVar1 < '\x14')) {
    if (cVar1 == '\0') {
      iVar2 = param_2[0xe2];
      FUN_0044d5d0();
      fVar6 = (float10)FUN_0057a8e0();
      iVar5 = *(int *)(iVar3 + 4) + -1;
      local_4 = param_2[(char)iVar2 * 0xe + 0xe] + 1;
      if (iVar5 <= param_2[(char)iVar2 * 0xe + 0xe] + 1) {
        local_4 = iVar5;
      }
      param_2 = (int *)(float)fVar6;
      if (ABS((float)fVar6) < 2.0) {
        param_2 = (int *)0x0;
      }
    }
    else {
      local_4 = FUN_005a6150(iVar3,param_1 + cVar1 * 0x10,1);
      if (local_4 < 0) {
        return;
      }
      fVar6 = (float10)FUN_005a7390(param_1 + cVar1 * 0x10,iVar2);
      param_2 = (int *)(float)fVar6;
    }
    local_8 = param_6;
    if (ABS(param_6 - 99999.0) < 0.001 != (ABS(param_6 - 99999.0) == 0.001)) {
      fVar6 = (float10)FUN_0045c550(piVar4 + 0xe3);
      local_8 = (float)fVar6;
    }
    if (local_4 < *(int *)(iVar3 + 4)) {
      do {
        FUN_0045c640(local_8,param_5,param_3);
        FUN_0045c500(param_1,param_2,*piVar4);
        local_4 = local_4 + 1;
      } while (local_4 < *(int *)(iVar3 + 4));
    }
    *(undefined4 *)(*(int *)(*piVar4 + 0x2c) + 1000) = 0;
  }
  return;
}


// ==== 0x45c500 FUN_0045c500

void __thiscall FUN_0045c500(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_EAX;
  undefined1 local_20 [28];
  
  FUN_005a7270(local_20,*(undefined4 *)(in_EAX + 0x58),param_3,param_1);
  FUN_004594d0(*(undefined1 *)(in_EAX + 0x5c),*(undefined2 *)(in_EAX + 0x5e),param_1,1);
  return;
}


// ==== 0x45c550 FUN_0045c550

float10 __fastcall FUN_0045c550(int *param_1)

{
  int iVar1;
  char cVar2;
  int in_EAX;
  float10 fVar3;
  
  iVar1 = *param_1;
  if (in_EAX == 2) goto LAB_0045c558;
  if ((in_EAX == 4) || (in_EAX == 3)) {
    return (float10)0.5;
  }
  if (in_EAX == 1) {
    return (float10)1.0;
  }
  if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
    cVar2 = IsCar1099InMode4();
    if (cVar2 != '\0') goto LAB_0045c59f;
  }
  else {
LAB_0045c59f:
    if ((*(int *)(iVar1 + 0x24) == 3) || (*(int *)(iVar1 + 0x24) == 2)) {
      fVar3 = (float10)LinearTable__Lookup11(&PTR_DAT_007061dc,*(float *)(iVar1 + 0x3d4) * 2.237);
      return fVar3;
    }
  }
  if (*(int *)(iVar1 + 0x24) == 4) {
    return (float10)1.0;
  }
  fVar3 = (float10)FUN_00432c90();
  if (((float10)5.0 <= fVar3) &&
     (*(float *)(iVar1 + 0x3d4) < 26.821636 == (*(float *)(iVar1 + 0x3d4) == 26.821636))) {
    if (*(float *)(iVar1 + 0x3d4) <= 29.503801) {
      return (float10)0.25;
    }
    return (float10)0.5;
  }
LAB_0045c558:
  return (float10)0.0;
}


// ==== 0x45c640 FUN_0045c640

void __fastcall FUN_0045c640(int param_1,int param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int in_EAX;
  int unaff_ESI;
  float *unaff_EDI;
  float local_8;
  
  fVar1 = *unaff_EDI;
  fVar2 = *(float *)(*(char *)(in_EAX + 0x388) * 0x38 + 0x10 + in_EAX);
  if (param_2 == 4) {
    fVar3 = fVar1 + param_3;
  }
  else if (param_2 == 3) {
    fVar3 = fVar1 - param_3;
  }
  else {
    if (param_4 <= fVar1) {
      fVar3 = fVar1 - param_3;
      if (param_4 < fVar3) goto LAB_0045c6a0;
    }
    else {
      fVar3 = fVar1 + param_3;
      if (fVar1 + param_3 < param_4) goto LAB_0045c6a0;
    }
    fVar3 = param_4;
  }
LAB_0045c6a0:
  if ((param_1 < 0) || (4 < param_1)) {
    if ((param_1 < 0xb) || (0x10 < param_1)) {
      fVar1 = 0.0;
    }
    else {
      fVar1 = *(float *)(unaff_ESI + -8 + param_1 * 4);
    }
  }
  else {
    fVar1 = *(float *)(unaff_ESI + 0x20);
  }
  local_8 = fVar1 + fVar2 + param_5;
  if ((param_1 < 0) || (4 < param_1)) {
    if ((param_1 < 0xb) || (0x10 < param_1)) {
      fVar1 = 0.0;
    }
    else {
      fVar1 = *(float *)(unaff_ESI + 0x14 + param_1 * 4);
    }
  }
  else {
    fVar1 = *(float *)(unaff_ESI + 0x3c);
  }
  param_5 = (fVar1 - fVar2) - param_5;
  if (0.0 <= local_8) {
    local_8 = 0.0;
  }
  if (param_5 <= 0.0) {
    param_5 = 0.0;
  }
  if (fVar3 <= local_8) {
    fVar3 = local_8;
  }
  if (fVar3 <= param_5) {
    *unaff_EDI = fVar3;
    return;
  }
  *unaff_EDI = param_5;
  return;
}


// ==== 0x45c760 FUN_0045c760

undefined4 FUN_0045c760(int *param_1,char *param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  float10 fVar12;
  float local_1c;
  int local_18;
  float local_10;
  
  piVar7 = param_3;
  iVar4 = param_3[0xea];
  iVar9 = 0;
  iVar5 = param_3[0xe5];
  if (0 < param_3[1]) {
    piVar11 = param_3 + 0xf;
    do {
      if (*piVar11 == param_1[1]) {
        if (iVar9 != -1) {
          piVar11 = param_3 + iVar9 * 0xe + 2;
          goto LAB_0045c79e;
        }
        break;
      }
      iVar9 = iVar9 + 1;
      piVar11 = piVar11 + 0xe;
    } while (iVar9 < param_3[1]);
  }
  piVar11 = (int *)0x0;
LAB_0045c79e:
  iVar9 = (int)(char)param_3[0xe2];
  if ((iVar5 < 0) || (4 < iVar5)) {
    if ((iVar5 < 0xb) || (0x10 < iVar5)) {
      local_1c = 0.0;
    }
    else {
      local_1c = (float)piVar11[iVar5 + -5];
    }
  }
  else {
    local_1c = (float)piVar11[5];
  }
  iVar10 = *(int *)(iVar4 + 8 + piVar11[0xc] * 4);
  if ((iVar5 < 0) || (4 < iVar5)) {
    if ((iVar5 < 0xb) || (0x10 < iVar5)) {
      local_18 = 0;
    }
    else {
      local_18 = param_3[iVar9 * 0xe + iVar5 + -3];
    }
  }
  else {
    local_18 = param_3[iVar9 * 0xe + 7];
  }
  iVar6 = *(int *)(*(int *)(param_1[1] + 0x1d4) + 0x1c);
  if (*(int *)(iVar6 + 0xe4) != 0) {
    FUN_005791c0();
  }
  fVar12 = (float10)FUN_005a7390(iVar6 + 0x40,0);
  if (fVar12 <= (float10)0.0) {
    fVar12 = (float10)*(float *)(iVar10 + 0x20) - fVar12;
  }
  else {
    fVar12 = fVar12 - (float10)*(float *)(iVar10 + 0x3c);
  }
  if ((float10)5.0 <= fVar12) {
    FUN_0045c370(param_2,param_3,DAT_00700638,2,0,0x47c34f80);
    return 0;
  }
  local_10 = -1.0;
  if (*param_1 != 2) {
    local_10 = 1.0;
  }
  fVar12 = (float10)FUN_0045cea0(param_1,iVar4);
  if ((char)param_1[3] != '\0') {
    fVar12 = fVar12 + (float10)4.0;
  }
  fVar1 = (float)(((float10)(float)piVar11[2] + (float10)(float)param_3[iVar9 * 0xe + 4] + fVar12) *
                 (float10)local_10);
  local_1c = fVar1 + local_1c;
  if ((iVar5 < 0) || (4 < iVar5)) {
    if ((iVar5 < 0xb) || (0x10 < iVar5)) {
      fVar2 = 0.0;
    }
    else {
      fVar2 = *(float *)(iVar10 + 0x14 + iVar5 * 4);
    }
  }
  else {
    fVar2 = *(float *)(iVar10 + 0x3c);
  }
  fVar2 = (fVar2 - DAT_00700638) - (float)param_3[iVar9 * 0xe + 4];
  if ((iVar5 < 0) || (4 < iVar5)) {
    if ((iVar5 < 0xb) || (0x10 < iVar5)) {
      fVar3 = 0.0;
    }
    else {
      fVar3 = *(float *)(iVar10 + -8 + iVar5 * 4);
    }
  }
  else {
    fVar3 = *(float *)(iVar10 + 0x20);
  }
  param_3 = (int *)(fVar3 + (float)param_3[iVar9 * 0xe + 4] + DAT_00700638);
  if ((float)param_3 < local_1c) {
    param_3 = (int *)local_1c;
  }
  if (fVar2 < (float)param_3) {
    param_3 = (int *)fVar2;
  }
  FUN_005a6310(iVar4,param_2,local_18,param_3,iVar5,0);
  if ((param_2[0x1b1] == '\0') && ((float)param_3 == local_1c)) {
    cVar8 = '\0';
  }
  else {
    cVar8 = '\x01';
  }
  param_2[0x1b0] = *param_2 + -1;
  param_2[0x1b1] = cVar8;
  iVar9 = param_1[1];
  iVar10 = FUN_00647b70();
  if ((iVar10 != 6) ||
     (*(int *)(*(int *)(*(int *)(*(int *)(iVar9 + 0x1d4) + 0x90) + 0x14) + 4) != 1)) {
    iVar9 = param_1[1];
    iVar10 = FUN_00647b70();
    if ((iVar10 != 6) ||
       ((*(int *)(*(int *)(*(int *)(*(int *)(iVar9 + 0x1d4) + 0x90) + 0x14) + 4) != 3 ||
        (*(int *)(*(int *)(*piVar7 + 0x14) + 4) == 3)))) goto LAB_0045caad;
  }
  iVar9 = param_1[1];
  iVar10 = FUN_00647b70();
  if ((iVar10 != 6) ||
     (*(int *)(*(int *)(*(int *)(*(int *)(iVar9 + 0x1d4) + 0x90) + 0xc) + 0xc54) != 1)) {
    FUN_0045cb00(param_1,param_2,iVar4,fVar1,iVar5);
  }
LAB_0045caad:
  FUN_0045c370(param_2,piVar7,DAT_00700638,2,0,0x47c34f80);
  return 1;
}


// ==== 0x45cb00 FUN_0045cb00

void FUN_0045cb00(int *param_1,char *param_2,int param_3,float param_4,int param_5)

{
  char *pcVar1;
  char cVar2;
  int *in_EAX;
  int iVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float local_58;
  int *local_54;
  float local_50;
  float local_48;
  int local_44;
  float local_3c;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined1 local_20 [28];
  
  iVar3 = 0;
  if (0 < in_EAX[1]) {
    piVar5 = in_EAX + 0xf;
    do {
      if (*piVar5 == param_1[1]) {
        if (iVar3 != -1) {
          local_54 = in_EAX + iVar3 * 0xe + 2;
          goto LAB_0045cb3b;
        }
        break;
      }
      iVar3 = iVar3 + 1;
      piVar5 = piVar5 + 0xe;
    } while (iVar3 < in_EAX[1]);
  }
  local_54 = (int *)0x0;
LAB_0045cb3b:
  iVar4 = (int)(char)in_EAX[0xe2];
  iVar3 = *(int *)(*(int *)(param_1[1] + 0x1d4) + 0x1c);
  if (*(int *)(iVar3 + 0xe4) != 0) {
    FUN_005791c0();
  }
  if (((5.0 < SQRT(*(float *)(iVar3 + 0x98) * *(float *)(iVar3 + 0x98) +
                   *(float *)(iVar3 + 0x94) * *(float *)(iVar3 + 0x94) +
                   *(float *)(iVar3 + 0x90) * *(float *)(iVar3 + 0x90))) &&
      (5.0 < *(float *)(*in_EAX + 0x3d4))) && (local_54 != (int *)0x0)) {
    bNormalize2();
    if (*(int *)(*(int *)(*(int *)(param_1[1] + 0x1d4) + 0x1c) + 0xe4) != 0) {
      FUN_005791c0();
    }
    bNormalize2();
    if (0.7071 < local_2c * local_34 + local_28 * local_30) {
      local_50 = (float)in_EAX[iVar4 * 0xe + 6];
      cVar2 = *param_2;
      if (cVar2 != '\0') {
        iVar3 = FUN_005a6150(param_3,param_2 + cVar2 * 0x10,1);
        if (iVar3 != -1) {
          fVar7 = (float10)FUN_005a7560(param_2 + cVar2 * 0x10);
          fVar7 = (float10)bMax_float(local_50,(float)fVar7);
          local_50 = (float)fVar7;
        }
      }
      pcVar1 = (char *)(param_1[1] + 0x10);
      local_44 = FUN_004596b0(pcVar1,param_1[1]);
      fVar7 = (float10)FUN_0057a8e0();
      if (*param_2 < '\x14') {
        pcVar6 = pcVar1 + (local_44 + 1) * 0x10;
        do {
          if (*pcVar1 <= local_44) {
            return;
          }
          iVar3 = FUN_005a6150(param_3,pcVar6,1);
          if (iVar3 == -1) {
            return;
          }
          iVar3 = *(int *)(param_3 + 8 + iVar3 * 4);
          fVar8 = (float10)FUN_005a7560(pcVar6);
          fVar9 = (float10)FUN_005a7390(pcVar6,param_5);
          if (local_50 < (float)fVar8) {
            fVar9 = fVar9 + (float10)param_4;
            fVar10 = (float10)(float)(fVar7 + (float10)param_4);
            if (*param_1 == 2) {
              if (fVar10 < fVar9) {
LAB_0045cd66:
                fVar9 = (float10)(float)(fVar7 + (float10)param_4);
              }
            }
            else if (fVar9 < fVar10) goto LAB_0045cd66;
            if ((param_5 < 0) || (4 < param_5)) {
              if ((param_5 < 0xb) || (0x10 < param_5)) {
                local_58 = 0.0;
              }
              else {
                local_58 = *(float *)(iVar3 + -8 + param_5 * 4);
              }
            }
            else {
              local_58 = *(float *)(iVar3 + 0x20);
            }
            if ((param_5 < 0) || (4 < param_5)) {
              if ((param_5 < 0xb) || (0x10 < param_5)) {
                local_48 = 0.0;
              }
              else {
                local_48 = *(float *)(iVar3 + 0x14 + param_5 * 4);
              }
            }
            else {
              local_48 = *(float *)(iVar3 + 0x3c);
            }
            local_58 = local_58 + (float)in_EAX[iVar4 * 0xe + 4];
            local_48 = local_48 - (float)in_EAX[iVar4 * 0xe + 4];
            if (0.0 <= local_58) {
              local_58 = 0.0;
            }
            if (local_48 <= 0.0) {
              local_48 = 0.0;
            }
            if (fVar9 <= (float10)local_58) {
              fVar9 = (float10)local_58;
            }
            if (fVar9 <= (float10)local_48) {
              local_3c = (float)fVar9;
            }
            else {
              local_3c = local_48;
            }
            FUN_005a7270(local_20,(float)fVar8,local_3c,param_5);
            FUN_004594d0(*(undefined1 *)(iVar3 + 0x5c),*(undefined2 *)(iVar3 + 0x5e),param_5,1);
          }
          local_44 = local_44 + 1;
          pcVar6 = pcVar6 + 0x10;
        } while (*param_2 < '\x14');
      }
    }
  }
  return;
}


// ==== 0x45cea0 FUN_0045cea0

float10 __fastcall FUN_0045cea0(int *param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  float10 fVar4;
  undefined4 local_8;
  
  if (param_2 == 0) {
    return (float10)0.0;
  }
  iVar1 = *(int *)(param_2 + 0x34);
  iVar3 = *param_1;
  fVar4 = (float10)FUN_0057b480();
  local_8 = (float)ABS(fVar4);
  if (ABS(fVar4) <= (float10)0.0) {
    local_8 = 0.0;
  }
  if (*(int *)(*(int *)(iVar3 + 0x14) + 4) == 3) {
    fVar4 = (float10)2.0;
    goto LAB_0045cf86;
  }
  iVar3 = FUN_00647b70();
  if ((iVar3 == 6) && (*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 0x1d4) + 0x90) + 0x14) + 4) == 3)
     ) {
LAB_0045cf41:
    cVar2 = FUN_0057a720();
    if (cVar2 != '\0') {
      fVar4 = (float10)FUN_0044d5f0();
      if (ABS(fVar4) < (float10)5.0 != (ABS(fVar4) == (float10)5.0)) goto LAB_0045cf67;
    }
    cVar2 = FUN_0057a6b0();
    if (cVar2 == '\0') {
      fVar4 = (float10)2.0;
    }
    else {
      fVar4 = (float10)1.5;
    }
  }
  else {
    fVar4 = (float10)FUN_0044d5f0();
    if (ABS(fVar4) < (float10)5.0 == (ABS(fVar4) == (float10)5.0)) goto LAB_0045cf41;
LAB_0045cf67:
    fVar4 = (float10)5.0;
  }
LAB_0045cf86:
  if (fVar4 < (float10)local_8) {
    fVar4 = (float10)local_8;
  }
  return fVar4;
}


// ==== 0x45cfb0 FUN_0045cfb0

undefined4 __fastcall FUN_0045cfb0(undefined4 param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  int in_EAX;
  
  if ((in_EAX == 2) || (in_EAX == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((in_EAX == 3) || (in_EAX == 1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (((!bVar1) || (param_2 != 2)) && ((!bVar2 || (param_2 != 3)))) {
    return 0;
  }
  return 1;
}


// ==== 0x45cff0 FUN_0045cff0

undefined4 FUN_0045cff0(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  int *unaff_ESI;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined1 uStack_4;
  
  puVar2 = param_2;
  if (((*unaff_ESI == 1) && (10 < (int)param_2[0xe5])) && ((int)param_2[0xe5] < 0x11)) {
    FUN_0045ae10(unaff_ESI,param_1,param_2,0,0);
    return 1;
  }
  if ((int *)param_2[0xea] == (int *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (**(code **)(*(int *)param_2[0xea] + 4))();
  }
  uVar1 = puVar2[0xe4];
  iVar5 = GetNearestTrafficLane(*puVar2,uVar4,0xff,0xff);
  if (iVar5 != -1) {
    uStack_1c = puVar2[0xe3];
    uStack_20 = 0;
    param_2 = (undefined4 *)0x47c34f80;
    uStack_10 = 1;
    uStack_c = 0;
    uStack_4 = 0;
    uStack_8 = 0;
    uStack_18 = uVar1;
    iStack_14 = iVar5;
    cVar3 = FUN_0045afd0(&uStack_10,0,&uStack_20,&param_3,&param_2,0,param_3,0);
    if (cVar3 != '\0') {
      puVar2[0xe5] = iVar5;
      unaff_ESI[1] = 0;
      *(undefined1 *)(unaff_ESI + 3) = 0;
      unaff_ESI[2] = 0;
      *unaff_ESI = 1;
      return 1;
    }
  }
  if (*unaff_ESI == 0) {
    *unaff_ESI = 1;
    unaff_ESI[1] = 0;
    *(undefined1 *)(unaff_ESI + 3) = 0;
    unaff_ESI[2] = 0;
  }
  FUN_0045ae10(unaff_ESI,param_1,puVar2,0,0);
  return 0;
}


// ==== 0x45d130 FUN_0045d130

uint FUN_0045d130(undefined4 param_1,undefined4 param_2,char param_3)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *unaff_EDI;
  uint local_4;
  
  if (((*unaff_EDI != 1) || (iVar2 = *(int *)(in_EAX + 0x394), iVar2 < 0xb)) || (0x10 < iVar2)) {
    uVar3 = FUN_0045cff0(param_1,in_EAX,param_2);
    return uVar3 & 0xffffff00;
  }
  local_4 = 1;
  iVar4 = iVar2;
  do {
    iVar4 = iVar4 + -1;
    iVar2 = iVar2 + 1;
    iVar5 = iVar4;
    iVar6 = iVar2;
    if (param_3 != '\0') {
      iVar5 = iVar2;
      iVar6 = iVar4;
    }
    cVar1 = FUN_0045d540(unaff_EDI,param_1,param_2);
    if (cVar1 != '\0') {
      *(int *)(in_EAX + 0x394) = iVar6;
      unaff_EDI[1] = 0;
      *(undefined1 *)(unaff_EDI + 3) = 0;
      unaff_EDI[2] = 0;
      *unaff_EDI = 1;
      return 1;
    }
    cVar1 = FUN_0045d540(unaff_EDI,param_1,param_2);
    if (cVar1 != '\0') {
      *(int *)(in_EAX + 0x394) = iVar5;
      unaff_EDI[1] = 0;
      *(undefined1 *)(unaff_EDI + 3) = 0;
      unaff_EDI[2] = 0;
      *unaff_EDI = 1;
      return 1;
    }
    local_4 = local_4 + 1;
  } while ((int)local_4 < 6);
  return local_4 & 0xffffff00;
}


// ==== 0x45d250 FUN_0045d250

char __thiscall FUN_0045d250(undefined4 param_1,int *param_2,undefined4 param_3,char param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  char cVar7;
  int in_EAX;
  bool bVar8;
  char local_2c;
  float local_28;
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  undefined1 local_4;
  
  iVar2 = *(int *)(in_EAX + 0x394);
  iVar3 = *(int *)(*(int *)(in_EAX + 0x3a8) + 8 +
                  *(int *)((*(char *)(in_EAX + 0x388) + 1) * 0x38 + in_EAX) * 4);
  local_20 = 0x47c34f80;
  local_1c = 0xbf800000;
  local_2c = '\0';
  local_10 = 0;
  local_c = 0;
  local_8 = 0.0;
  local_4 = 0;
  if ((1 < *param_2) && (*param_2 < 4)) {
    *param_2 = 1;
    param_2[1] = 0;
    *(undefined1 *)(param_2 + 3) = 0;
    param_2[2] = 0;
  }
  cVar7 = FUN_0045b050(param_2,0,&local_1c,&local_18,&local_20,0,param_3);
  if (cVar7 != '\0') {
    return '\x01';
  }
  local_10 = 1;
  local_c = 0;
  local_4 = 0;
  local_8 = 0.0;
  cVar7 = FUN_0045b050(&local_10,0,&local_1c,&local_18,&local_20,0,param_3);
  if (cVar7 != '\0') {
    FUN_0044a000();
    return '\x01';
  }
  local_28 = 4.0;
  bVar4 = true;
  bVar8 = true;
  do {
    if ((!bVar4) && (!bVar8)) {
      if (local_2c != '\0') {
        FUN_0044a000();
        return local_2c;
      }
      FUN_0045ae10(param_2,param_1,in_EAX,0,0);
      return '\0';
    }
    local_18 = -local_28;
    if ((iVar2 < 0) || (4 < iVar2)) {
      if ((iVar2 < 0xb) || (0x10 < iVar2)) {
        fVar1 = 0.0;
      }
      else {
        fVar1 = *(float *)(iVar3 + -8 + iVar2 * 4);
      }
    }
    else {
      fVar1 = *(float *)(iVar3 + 0x20);
    }
    bVar8 = fVar1 < local_18;
    if ((iVar2 < 0) || (4 < iVar2)) {
      if ((iVar2 < 0xb) || (0x10 < iVar2)) {
        fVar1 = 0.0;
      }
      else {
        fVar1 = *(float *)(iVar3 + 0x14 + iVar2 * 4);
      }
    }
    else {
      fVar1 = *(float *)(iVar3 + 0x3c);
    }
    bVar4 = local_28 < fVar1;
    local_14 = local_28;
    fVar1 = local_18;
    bVar5 = bVar8;
    bVar6 = bVar4;
    if (param_4 == '\0') {
      fVar1 = local_28;
      local_14 = local_18;
      bVar5 = bVar4;
      bVar6 = bVar8;
    }
    if (bVar5) {
      local_10 = 1;
      local_c = 0;
      local_4 = 0;
      local_8 = fVar1;
      local_2c = FUN_0045b050(&local_10,0,&local_1c,&local_18,&local_20,0,param_3);
    }
    if ((local_2c == '\0') && (bVar6)) {
      local_8 = local_14;
      local_10 = 1;
      local_c = 0;
      local_4 = 0;
      local_2c = FUN_0045b050(&local_10,0,&local_1c,&local_18,&local_20,0,param_3);
    }
    local_28 = local_28 + 4.0;
  } while (local_2c == '\0');
  FUN_0044a000();
  return local_2c;
}


// ==== 0x45d540 FUN_0045d540

undefined4 FUN_0045d540(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 *unaff_ESI;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = unaff_ESI[0xe3];
  local_8 = unaff_ESI[0xe4];
  local_10 = 0;
  local_14 = 0x47c34f80;
  cVar1 = FUN_005a7700(unaff_ESI[0xe5],*unaff_ESI);
  if (cVar1 != '\0') {
    cVar1 = FUN_0045afd0(param_1,0,&local_10,&param_3,&local_14,0,param_3,0);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== 0x45d5e0 FUN_0045d5e0

uint FUN_0045d5e0(void)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  uint *puVar3;
  uint *unaff_ESI;
  
  uVar2 = *unaff_ESI;
  if ((1 < (int)uVar2) && ((int)uVar2 < 4)) {
    uVar2 = 0;
    if (0 < *(int *)(in_EAX + 4)) {
      puVar3 = (uint *)(in_EAX + 0x3c);
      do {
        if (*puVar3 == unaff_ESI[1]) {
          if ((uVar2 != 0xffffffff) && (iVar1 = uVar2 * 0x38 + 8 + in_EAX, uVar2 = 0, iVar1 != 0)) {
            FUN_0045c0d0(unaff_ESI,iVar1);
            uVar2 = FUN_0045cfb0();
            return uVar2;
          }
          break;
        }
        uVar2 = uVar2 + 1;
        puVar3 = puVar3 + 0xe;
      } while ((int)uVar2 < *(int *)(in_EAX + 4));
    }
  }
  return uVar2 & 0xffffff00;
}


// ==== 0x45d640 Racer::GetDirection

/* [canon] rivals V (capstone+Hopper) docs/re/rivals.md */

undefined4 Racer__GetDirection(void)

{
  return DAT_0078a2fc;
}


// ==== 0x45d650 FUN_0045d650

void __fastcall FUN_0045d650(int param_1)

{
  *(undefined4 *)(param_1 + 0x4e0) = DAT_0073ad34;
  return;
}


// ==== 0x45d660 FUN_0045d660

undefined4 * FUN_0045d660(undefined4 *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006868dd;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004620c0(param_1);
  local_4 = 0;
  *param_1 = &PTR_FUN_006c8d20;
  pvVar1 = _malloc(0x520);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004602c0(pvVar1);
  }
  param_1[2] = uVar2;
  param_1[0x141] = 0xff;
  param_1[0x142] = 0xff;
  param_1[0x140] = 2;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x45d6f0 FUN_0045d6f0

void * __thiscall FUN_0045d6f0(void *param_1,byte param_2)

{
  FUN_0045d710(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x45d710 FUN_0045d710

void FUN_0045d710(undefined4 *param_1)

{
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068553a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c8d20;
  local_4 = 0;
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[2])(1);
  }
  param_1[2] = 0;
  local_4 = 0xffffffff;
  FUN_00462250(param_1);
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x45d770 FUN_0045d770

void __thiscall FUN_0045d770(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"DragController");
  FUN_004622c0(param_2);
  FUN_00571c20(param_2,param_1 + 0x500,1,4,1);
  FUN_00571c20(param_2,param_1 + 0x504,4,4,0);
  FUN_00571c20(param_2,param_1 + 0x508,4,4,0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10 + 0x4c + param_2;
  *(int *)(iVar1 + 0xc) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x45d800 FUN_0045d800

void __thiscall FUN_0045d800(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  float fStack_8;
  undefined1 auStack_4 [4];
  
  if ((((param_1[0x141] != 0xff) || (param_1[0x142] != 0xff)) && (*(int *)param_1[0xf6] != 0)) &&
     (*(int *)(param_1[0xf9] + 4) != 0)) {
    iVar3 = param_1[1];
    uVar2 = (**(code **)(*param_1 + 0x40))(0xff,0xff);
    iVar3 = GetNearestTrafficLane(iVar3,uVar2);
    if ((iVar3 < param_1[0x141]) || (param_1[0x142] < iVar3)) {
      fStack_8 = 0.0;
      FUN_005a6700(auStack_4,&fStack_8,iVar3);
      if (ABS(fStack_8) < 0.5) {
        param_1[0x141] = 0xff;
        param_1[0x142] = 0xff;
      }
    }
  }
  iVar3 = *(int *)(param_1[0xf6] + 8);
  iVar1 = param_1[0x140];
  if ((iVar1 == 0) || (iVar1 == 1)) {
    FUN_0045d970();
  }
  else if (iVar1 == 2) {
    FUN_0045d920();
  }
  if (*(int *)(param_1[0xf6] + 8) != iVar3) {
    *(undefined1 *)(param_1 + 0x12f) = 1;
  }
  FUN_00462430(param_2);
  return;
}


// ==== 0x45d920 FUN_0045d920

void FUN_0045d920(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  if (**(int **)(unaff_ESI + 0x3d8) != 0) {
    uVar1 = (**(code **)(**(int **)(*(int *)(unaff_ESI + 4) + 0x2c) + 0x40))
                      (*(undefined4 *)(unaff_ESI + 0x504),*(undefined4 *)(unaff_ESI + 0x508));
    uVar1 = GetNearestTrafficLane(*(undefined4 *)(unaff_ESI + 4),uVar1);
    *(undefined4 *)(*(int *)(unaff_ESI + 0x3d8) + 8) = uVar1;
  }
  return;
}


// ==== 0x45d970 FUN_0045d970

bool __fastcall FUN_0045d970(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  char cVar3;
  int in_EAX;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  undefined4 uStack_c;
  int iStack_8;
  undefined1 auStack_4 [4];
  
  bVar7 = false;
  if ((*(int *)param_1[0xf6] != 0) && (*(int *)(param_1[0xf9] + 4) != 0)) {
    uVar4 = (**(code **)(*param_1 + 0x40))(0xff,0xff);
    iVar5 = GetNearestTrafficLane(param_1[1],uVar4);
    iVar6 = iVar5;
    if (iVar5 < 0xc) {
      iVar6 = 0xb;
    }
    *(int *)(param_1[0xf6] + 8) = iVar6;
    iStack_8 = iVar5;
    iVar6 = FUN_005a6700(auStack_4,&uStack_c,*(undefined4 *)(param_1[0xf6] + 8));
    uStack_c = *(undefined4 *)(param_1[0xf9] + 8 + iVar6 * 4);
    iVar2 = iVar5;
    iVar6 = iStack_8;
    if (in_EAX < 1) {
      for (; iStack_8 = iVar2, in_EAX < 0; in_EAX = in_EAX + 1) {
        iStack_8 = iVar6;
        cVar3 = FUN_005a7700(iVar5,param_1[1]);
        if (cVar3 == '\0') break;
        iVar5 = iVar5 + -1;
        iVar2 = iStack_8;
        iVar6 = iStack_8;
      }
    }
    else {
      do {
        iVar6 = iVar5 + 1;
        cVar3 = FUN_005a7700(iVar5,param_1[1]);
        if (cVar3 == '\0') break;
        in_EAX = in_EAX + -1;
        iVar5 = iVar6;
      } while (0 < in_EAX);
    }
    bVar7 = iVar5 != iStack_8;
    *(int *)(param_1[0xf6] + 8) = iVar5;
    puVar1 = (undefined4 *)param_1[0xf7];
    *puVar1 = 1;
    puVar1[1] = 0;
    *(undefined1 *)(puVar1 + 3) = 0;
    puVar1[2] = 0;
  }
  return bVar7;
}


// ==== 0x45da90 SmallBufferTriple_dtor

/* [canon] rivals low (ghidra-canon) docs/re/rivals.md */

void SmallBufferTriple_dtor(void)

{
  undefined4 *unaff_ESI;
  
  unaff_ESI[0x14] = &PTR_FUN_006b9694;
  if ((undefined4 *)unaff_ESI[0x18] != unaff_ESI + 0x19) {
    _free((undefined4 *)unaff_ESI[0x18]);
  }
  unaff_ESI[0x14] = &PTR_FUN_006c7d78;
  unaff_ESI[10] = &PTR_FUN_006b9694;
  if ((undefined4 *)unaff_ESI[0xe] != unaff_ESI + 0xf) {
    _free((undefined4 *)unaff_ESI[0xe]);
  }
  unaff_ESI[10] = &PTR_FUN_006c7d78;
  *unaff_ESI = &PTR_FUN_006b9694;
  if ((undefined4 *)unaff_ESI[4] != unaff_ESI + 5) {
    _free((undefined4 *)unaff_ESI[4]);
  }
  *unaff_ESI = &PTR_FUN_006c7d78;
  return;
}


// ==== 0x45db00 PsychoDriver_ScaledRatioTerm

/* [canon] rivals med (ghidra-canon+hopper) docs/re/rivals.md */

float10 PsychoDriver_ScaledRatioTerm(void)

{
  int in_EAX;
  
  if (*(byte *)(in_EAX + 0x2e) != 0) {
    return ((float10)*(float *)(in_EAX + 0x30) * (float10)*(byte *)(in_EAX + 0x2e)) /
           ((float10)*(float *)(in_EAX + 8) * (float10)*(float *)(in_EAX + 0x78));
  }
  return (float10)0.0;
}


// ==== 0x45db30 PsychoDriver::SetSteerToPoint

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

void __thiscall PsychoDriver__SetSteerToPoint(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *param_2;
  *(undefined4 *)(param_1 + 0x1f8) = param_2[1];
  *(undefined4 *)(param_1 + 500) = uVar1;
  return;
}


// ==== 0x45db50 FUN_0045db50

int __fastcall FUN_0045db50(int param_1)

{
  return param_1 + 500;
}


// ==== 0x45db60 FUN_0045db60

float10 __fastcall FUN_0045db60(int param_1)

{
  return (float10)*(float *)(param_1 + 0x200);
}


// ==== 0x45db70 FUN_0045db70

float10 __fastcall FUN_0045db70(int param_1)

{
  return (float10)*(float *)(param_1 + 0x204);
}


// ==== 0x45db80 FUN_0045db80

void __fastcall FUN_0045db80(int param_1)

{
  *(undefined1 *)(param_1 + 0x228) = 1;
  return;
}


// ==== 0x45db90 PsychoDriver::ClearFlag228AndCallSlot34

/* [canon] rivals med (ghidra-canon+hopper) docs/re/canon.md */

void __fastcall PsychoDriver__ClearFlag228AndCallSlot34(int *param_1)

{
  *(undefined1 *)(param_1 + 0x8a) = 0;
                    /* WARNING: Could not recover jumptable at 0x0045db99. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x34))();
  return;
}


// ==== 0x45dba0 PsychoDriver::ResetField1D4

/* [canon] rivals low (ghidra-canon) docs/re/canon.md */

void __fastcall PsychoDriver__ResetField1D4(int param_1)

{
  *(undefined4 *)(param_1 + 0x1d4) = 0xffffffff;
  return;
}


// ==== 0x45dbb0 FUN_0045dbb0

undefined4 * FUN_0045dbb0(undefined4 *param_1,undefined4 param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  void *pvVar7;
  char *pcVar8;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686560;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00424f60();
  param_1[0x7c] = param_2;
  local_4 = 0;
  *param_1 = &PTR_FUN_006c8c18;
  *(undefined2 *)(param_1 + 0x74) = 0;
  param_1[0x7f] = 0x3f800000;
  param_1[0x80] = 0;
  param_1[0x81] = 0;
  param_1[0x82] = 0;
  *(undefined1 *)(param_1 + 0x83) = 1;
  param_1[0x84] = 0;
  param_1[0x87] = 0;
  *(undefined1 *)(param_1 + 0x86) = 1;
  *(undefined1 *)(param_1 + 0x8a) = 0;
  *(undefined1 *)(param_1 + 0x88) = 0;
  *(undefined2 *)((int)param_1 + 0x222) = 0;
  puVar4 = (undefined4 *)FUN_00567160();
  local_4 = CONCAT31(local_4._1_3_,1);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    pcVar8 = "MARKER_GREENARROW";
    do {
      pcVar1 = pcVar8 + 1;
      pcVar8 = pcVar8 + 1;
    } while (*pcVar1 != '\0');
    iVar5 = FUN_00567160();
    if (iVar5 == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_004454d0();
    }
    puVar4[2] = uVar6;
    puVar4[3] = 0;
    puVar4[5] = 1;
    puVar4[6] = 0;
    puVar4[4] = 0;
    puVar4[0x18] = 0;
    *DAT_00737820 = puVar4;
    puVar3 = puVar4;
    puVar4[1] = DAT_00737820;
    DAT_00737820 = puVar3;
    *puVar4 = &DAT_0073781c;
    *(undefined1 *)(puVar4 + 7) = 0;
  }
  param_1[0x91] = puVar4;
  param_1[0x89] = 0;
  *(undefined1 *)((int)param_1 + 0x229) = 0;
  param_1[0x8b] = param_1[0x80];
  puVar4 = _malloc(0x84);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar4 + 1) = 4;
    *(undefined1 *)((int)puVar4 + 5) = 5;
    *(undefined1 *)((int)puVar4 + 6) = 0;
    *(undefined1 *)((int)puVar4 + 7) = 0;
    *puVar4 = &PTR_FUN_006b9694;
    puVar4[2] = 0;
    puVar4[3] = 0;
    puVar4[4] = puVar4 + 5;
    puVar4[5] = 0;
    puVar4[6] = 0;
    puVar4[7] = 0;
    puVar4[8] = 0;
    puVar4[9] = 0;
    *(undefined1 *)(puVar4 + 0xb) = 4;
    *(undefined1 *)((int)puVar4 + 0x2d) = 5;
    *(undefined1 *)((int)puVar4 + 0x2e) = 0;
    *(undefined1 *)((int)puVar4 + 0x2f) = 0;
    puVar4[10] = &PTR_FUN_006b9694;
    puVar4[0xc] = 0;
    puVar4[0xd] = 0;
    puVar4[0xe] = puVar4 + 0xf;
    puVar4[0xf] = 0;
    puVar4[0x10] = 0;
    puVar4[0x11] = 0;
    puVar4[0x12] = 0;
    puVar4[0x13] = 0;
    *(undefined1 *)(puVar4 + 0x15) = 4;
    *(undefined1 *)((int)puVar4 + 0x55) = 5;
    *(undefined1 *)((int)puVar4 + 0x56) = 0;
    *(undefined1 *)((int)puVar4 + 0x57) = 0;
    puVar4[0x14] = &PTR_FUN_006b9694;
    puVar4[0x16] = 0;
    puVar4[0x17] = 0;
    puVar4[0x18] = puVar4 + 0x19;
    puVar4[0x19] = 0;
    puVar4[0x1a] = 0;
    puVar4[0x1b] = 0;
    puVar4[0x1c] = 0;
    puVar4[0x1d] = 0;
    puVar4[0x1e] = 0x41f00000;
    puVar4[0x1f] = 0;
    puVar4[0x20] = 0;
  }
  param_1[0x8c] = puVar4;
  puVar4 = _malloc(0x84);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar4 + 1) = 4;
    *(undefined1 *)((int)puVar4 + 5) = 5;
    *(undefined1 *)((int)puVar4 + 6) = 0;
    *(undefined1 *)((int)puVar4 + 7) = 0;
    *puVar4 = &PTR_FUN_006b9694;
    puVar4[2] = 0;
    puVar4[3] = 0;
    puVar4[4] = puVar4 + 5;
    puVar4[5] = 0;
    puVar4[6] = 0;
    puVar4[7] = 0;
    puVar4[8] = 0;
    puVar4[9] = 0;
    *(undefined1 *)(puVar4 + 0xb) = 4;
    *(undefined1 *)((int)puVar4 + 0x2d) = 5;
    *(undefined1 *)((int)puVar4 + 0x2e) = 0;
    *(undefined1 *)((int)puVar4 + 0x2f) = 0;
    puVar4[10] = &PTR_FUN_006b9694;
    puVar4[0xc] = 0;
    puVar4[0xd] = 0;
    puVar4[0xe] = puVar4 + 0xf;
    puVar4[0xf] = 0;
    puVar4[0x10] = 0;
    puVar4[0x11] = 0;
    puVar4[0x12] = 0;
    puVar4[0x13] = 0;
    *(undefined1 *)(puVar4 + 0x15) = 4;
    *(undefined1 *)((int)puVar4 + 0x55) = 5;
    *(undefined1 *)((int)puVar4 + 0x56) = 0;
    *(undefined1 *)((int)puVar4 + 0x57) = 0;
    puVar4[0x14] = &PTR_FUN_006b9694;
    puVar4[0x16] = 0;
    puVar4[0x17] = 0;
    puVar4[0x18] = puVar4 + 0x19;
    puVar4[0x19] = 0;
    puVar4[0x1a] = 0;
    puVar4[0x1b] = 0;
    puVar4[0x1c] = 0;
    puVar4[0x1d] = 0;
    puVar4[0x1e] = 0x41f00000;
    puVar4[0x1f] = 0;
    puVar4[0x20] = 0;
  }
  param_1[0x8d] = puVar4;
  puVar4 = _malloc(0x84);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar4 + 1) = 4;
    *(undefined1 *)((int)puVar4 + 5) = 5;
    *(undefined1 *)((int)puVar4 + 6) = 0;
    *(undefined1 *)((int)puVar4 + 7) = 0;
    *puVar4 = &PTR_FUN_006b9694;
    puVar4[2] = 0;
    puVar4[3] = 0;
    puVar4[4] = puVar4 + 5;
    puVar4[5] = 0;
    puVar4[6] = 0;
    puVar4[7] = 0;
    puVar4[8] = 0;
    puVar4[9] = 0;
    *(undefined1 *)(puVar4 + 0xb) = 4;
    *(undefined1 *)((int)puVar4 + 0x2d) = 5;
    *(undefined1 *)((int)puVar4 + 0x2e) = 0;
    *(undefined1 *)((int)puVar4 + 0x2f) = 0;
    puVar4[10] = &PTR_FUN_006b9694;
    puVar4[0xc] = 0;
    puVar4[0xd] = 0;
    puVar4[0xe] = puVar4 + 0xf;
    puVar4[0xf] = 0;
    puVar4[0x10] = 0;
    puVar4[0x11] = 0;
    puVar4[0x12] = 0;
    puVar4[0x13] = 0;
    *(undefined1 *)(puVar4 + 0x15) = 4;
    *(undefined1 *)((int)puVar4 + 0x55) = 5;
    *(undefined1 *)((int)puVar4 + 0x56) = 0;
    *(undefined1 *)((int)puVar4 + 0x57) = 0;
    puVar4[0x14] = &PTR_FUN_006b9694;
    puVar4[0x16] = 0;
    puVar4[0x17] = 0;
    puVar4[0x18] = puVar4 + 0x19;
    puVar4[0x19] = 0;
    puVar4[0x1a] = 0;
    puVar4[0x1b] = 0;
    puVar4[0x1c] = 0;
    puVar4[0x1d] = 0;
    puVar4[0x1e] = 0x41f00000;
    puVar4[0x1f] = 0;
    puVar4[0x20] = 0;
  }
  param_1[0x8e] = puVar4;
  pvVar7 = _malloc(0x84);
  uVar2 = DAT_00700520;
  uVar6 = DAT_0070051c;
  if (pvVar7 == (void *)0x0) {
    pvVar7 = (void *)0x0;
  }
  else {
    FUN_00584180(DAT_0070051c);
    FUN_00584180(uVar6);
    FUN_00584180(uVar2);
    *(undefined4 *)((int)pvVar7 + 0x78) = 0x41f00000;
    *(undefined4 *)((int)pvVar7 + 0x7c) = 0;
    *(undefined4 *)((int)pvVar7 + 0x80) = 0;
  }
  param_1[0x8f] = pvVar7;
  puVar4 = _malloc(0x84);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar4 + 1) = 4;
    *(undefined1 *)((int)puVar4 + 5) = 4;
    *(undefined1 *)((int)puVar4 + 6) = 0;
    *(undefined1 *)((int)puVar4 + 7) = 0;
    *puVar4 = &PTR_FUN_006b9694;
    puVar4[2] = 0;
    puVar4[3] = 0;
    puVar4[4] = puVar4 + 5;
    puVar4[5] = 0;
    puVar4[6] = 0;
    puVar4[7] = 0;
    puVar4[8] = 0;
    *(undefined1 *)(puVar4 + 0xb) = 4;
    *(undefined1 *)((int)puVar4 + 0x2d) = 4;
    *(undefined1 *)((int)puVar4 + 0x2e) = 0;
    *(undefined1 *)((int)puVar4 + 0x2f) = 0;
    puVar4[10] = &PTR_FUN_006b9694;
    puVar4[0xc] = 0;
    puVar4[0xd] = 0;
    puVar4[0xe] = puVar4 + 0xf;
    puVar4[0xf] = 0;
    puVar4[0x10] = 0;
    puVar4[0x11] = 0;
    puVar4[0x12] = 0;
    *(undefined1 *)(puVar4 + 0x15) = 4;
    *(undefined1 *)((int)puVar4 + 0x55) = 4;
    *(undefined1 *)((int)puVar4 + 0x56) = 0;
    *(undefined1 *)((int)puVar4 + 0x57) = 0;
    puVar4[0x14] = &PTR_FUN_006b9694;
    puVar4[0x16] = 0;
    puVar4[0x17] = 0;
    puVar4[0x18] = puVar4 + 0x19;
    puVar4[0x19] = 0;
    puVar4[0x1a] = 0;
    puVar4[0x1b] = 0;
    puVar4[0x1c] = 0;
    puVar4[0x1e] = 0x41f00000;
    puVar4[0x1f] = 0;
    puVar4[0x20] = 0;
  }
  param_1[0x90] = puVar4;
  FUN_0045e520();
  iVar5 = param_1[0x8f];
  *(undefined4 *)(iVar5 + 0x7c) = 0;
  *(undefined4 *)(iVar5 + 0x80) = 0;
  FUN_005842d0(0);
  *(undefined4 *)(iVar5 + 0x7c) = 0;
  *(undefined4 *)(iVar5 + 0x80) = 0;
  FUN_005842d0(0);
  param_1[0x7d] = 0;
  param_1[0x7e] = 0;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x45e060 FUN_0045e060

void * __thiscall FUN_0045e060(void *param_1,byte param_2)

{
  FUN_0045e080(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x45e080 FUN_0045e080

void FUN_0045e080(undefined4 *param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006859c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c8c18;
  pvVar1 = (void *)param_1[0x8c];
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    SmallBufferTriple_dtor();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[0x8d];
  if (pvVar1 != (void *)0x0) {
    SmallBufferTriple_dtor();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[0x8e];
  if (pvVar1 != (void *)0x0) {
    SmallBufferTriple_dtor();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[0x8f];
  if (pvVar1 != (void *)0x0) {
    SmallBufferTriple_dtor();
    _free(pvVar1);
  }
  pvVar1 = (void *)param_1[0x90];
  if (pvVar1 != (void *)0x0) {
    SmallBufferTriple_dtor();
    _free(pvVar1);
  }
  puVar2 = (undefined4 *)param_1[0x91];
  if (puVar2 != (undefined4 *)0x0) {
    FUN_00591c90(puVar2);
    iVar4 = DAT_007344c8;
    iVar3 = *(int *)(DAT_007344c8 + 0x18);
    *puVar2 = *(undefined4 *)(DAT_007344c8 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar3 + -1;
    *(undefined4 **)(iVar4 + 0x10) = puVar2;
  }
  if (*(int **)(param_1[0x7c] + 0x878) != (int *)0x0) {
    (**(code **)(**(int **)(param_1[0x7c] + 0x878) + 0x4c))();
  }
  *param_1 = &PTR_PsychoDriver__scalar_deleting_dtor_006caa58;
  ExceptionList = local_c;
  return;
}


// ==== 0x45e180 PsychoDriver::SetDesiredSpeed

/* [canon] canon high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall
PsychoDriver__SetDesiredSpeed
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined1 param_5)

{
  *(undefined4 *)(param_1 + 0x200) = param_2;
  *(undefined4 *)(param_1 + 0x204) = param_3;
  *(undefined4 *)(param_1 + 0x208) = param_4;
  *(undefined1 *)(param_1 + 0x20c) = param_5;
  return;
}


// ==== 0x45e1b0 FUN_0045e1b0

void __thiscall FUN_0045e1b0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"PsychoDriver");
  FUN_00571c20(param_2,param_1 + 0x1fc,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x200,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x204,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x208,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 500,8,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x20c,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x210,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x218,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x21c,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x228,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x220,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x222,2,2,0);
  FUN_00571c20(param_2,param_1 + 0x224,1,4,1);
  FUN_00571c20(param_2,param_1 + 0x229,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x22c,4,0xffffffff,0);
  FUN_005846a0();
  FUN_005846a0();
  FUN_005846a0();
  FUN_005846a0();
  FUN_005846a0();
  FUN_004251a0(param_2);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x45e370 FUN_0045e370

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short FUN_0045e370(float *param_1,float *param_2,float *param_3)

{
  int iVar1;
  float fVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  int unaff_ESI;
  float10 fVar6;
  
  sVar3 = Atan2ToAngle16(*(float *)(unaff_ESI + 500) -
                         *(float *)(*(int *)(unaff_ESI + 0x1f0) + 0x60),
                         *(float *)(unaff_ESI + 0x1f8) -
                         *(float *)(*(int *)(unaff_ESI + 0x1f0) + 100));
  fVar2 = (float)(ushort)(*(short *)(*(int *)(unaff_ESI + 0x1f0) + 0x3b4) - sVar3) * 9.58738e-05;
  if (fVar2 <= 3.14159) {
    if (fVar2 < -3.14159) {
      fVar2 = fVar2 + 6.28318;
    }
  }
  else {
    fVar2 = fVar2 - 6.28318;
  }
  *param_1 = fVar2;
  iVar1 = *(int *)(unaff_ESI + 0x1f0);
  fVar6 = (float10)LinearTable__Lookup11(&PTR_DAT_007060c0,*(undefined4 *)(iVar1 + 0x3d4));
  if (fVar6 <= (float10)0.0) {
    *param_2 = fVar2;
  }
  else {
    sVar4 = Atan2ToAngle16(*(undefined4 *)(iVar1 + 0x70),*(undefined4 *)(iVar1 + 0x74));
    fVar2 = (float)(ushort)(sVar4 - sVar3) * 9.58738e-05;
    if (fVar2 <= 3.14159) {
      if (fVar2 < -3.14159) {
        fVar2 = fVar2 + 6.28318;
      }
    }
    else {
      fVar2 = fVar2 - 6.28318;
    }
    *param_2 = fVar2 * (float)fVar6 + (_K_ONE - (float)fVar6) * *param_1;
  }
  fVar6 = (float10)FUN_004592f0();
  uVar5 = Atan2ToAngle16(0x40a00000,(float)fVar6);
  fVar2 = (float)uVar5 * 9.58738e-05;
  if (fVar2 <= 3.14159) {
    if (fVar2 < -3.14159) {
      fVar2 = fVar2 + 6.28318;
    }
    *param_3 = fVar2;
    return sVar3;
  }
  *param_3 = fVar2 - 6.28318;
  return sVar3;
}


// ==== 0x45e520 FUN_0045e520

void __fastcall FUN_0045e520(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x230);
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(undefined4 *)(iVar1 + 0x80) = 0;
  FUN_005842d0(0);
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(undefined4 *)(iVar1 + 0x80) = 0;
  FUN_005842d0(0);
  iVar1 = *(int *)(param_1 + 0x238);
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(undefined4 *)(iVar1 + 0x80) = 0;
  FUN_005842d0(0);
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(undefined4 *)(iVar1 + 0x80) = 0;
  FUN_005842d0(0);
  return;
}


// ==== 0x45e580 FUN_0045e580

void __fastcall FUN_0045e580(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x230);
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(undefined4 *)(iVar1 + 0x80) = 0;
  FUN_005842d0(0);
  iVar1 = *(int *)(param_1 + 0x238);
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(undefined4 *)(iVar1 + 0x80) = 0;
  FUN_005842d0(0);
  return;
}


// ==== 0x45e5c0 FUN_0045e5c0

void __fastcall FUN_0045e5c0(int param_1)

{
  int iVar1;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  FUN_0045e370(&uStack_c,&uStack_4,&uStack_8);
  iVar1 = *(int *)(param_1 + 0x230);
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(undefined4 *)(iVar1 + 0x80) = uStack_c;
  FUN_005842d0(uStack_c);
  iVar1 = *(int *)(param_1 + 0x234);
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(undefined4 *)(iVar1 + 0x80) = uStack_8;
  FUN_005842d0(uStack_8);
  iVar1 = *(int *)(param_1 + 0x238);
  *(undefined4 *)(iVar1 + 0x80) = uStack_4;
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  FUN_005842d0(uStack_4);
  return;
}


// ==== 0x45e650 FUN_0045e650

void __fastcall FUN_0045e650(int param_1)

{
  int iVar1;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  FUN_0045e370(&uStack_c,&uStack_4,&uStack_8);
  iVar1 = *(int *)(param_1 + 0x230);
  *(undefined4 *)(iVar1 + 0x80) = uStack_c;
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  FUN_005842d0(uStack_c);
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(undefined4 *)(iVar1 + 0x80) = uStack_c;
  FUN_005842d0(uStack_c);
  iVar1 = *(int *)(param_1 + 0x234);
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(undefined4 *)(iVar1 + 0x80) = uStack_8;
  FUN_005842d0(uStack_8);
  *(undefined4 *)(iVar1 + 0x80) = uStack_8;
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  FUN_005842d0(uStack_8);
  iVar1 = *(int *)(param_1 + 0x238);
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(undefined4 *)(iVar1 + 0x80) = uStack_4;
  FUN_005842d0(uStack_4);
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(undefined4 *)(iVar1 + 0x80) = uStack_4;
  FUN_005842d0(uStack_4);
  return;
}


// ==== 0x45e710 FUN_0045e710

void __fastcall FUN_0045e710(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x23c);
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(undefined4 *)(iVar1 + 0x80) = 0;
  FUN_005842d0(0);
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(undefined4 *)(iVar1 + 0x80) = 0;
  FUN_005842d0(0);
  return;
}


// ==== 0x45e750 FUN_0045e750

void __fastcall FUN_0045e750(int param_1)

{
  int iVar1;
  float fVar2;
  
  fVar2 = ABS(*(float *)(param_1 + 0x200)) - *(float *)(*(int *)(param_1 + 0x1f0) + 0x3d4);
  iVar1 = *(int *)(param_1 + 0x23c);
  *(float *)(iVar1 + 0x80) = fVar2;
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  FUN_005842d0(fVar2);
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(float *)(iVar1 + 0x80) = fVar2;
  FUN_005842d0(fVar2);
  return;
}


// ==== 0x45e7b0 FUN_0045e7b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045e7b0(float param_1)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  byte bVar5;
  float *pfVar6;
  int iVar7;
  int unaff_EDI;
  
  fVar3 = 0.0;
  pfVar6 = (float *)(*(int *)(unaff_EDI + 0x1f0) + 0x374);
  iVar7 = 4;
  do {
    fVar1 = *pfVar6;
    fVar4 = -4.0;
    if (-4.0 < fVar1) {
      fVar4 = fVar1;
    }
    if (4.0 < fVar4) {
      fVar4 = 4.0;
    }
    if (fVar1 != fVar4) {
      fVar3 = fVar1 + fVar3;
    }
    pfVar6 = pfVar6 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  if (*(float *)(*(int *)(unaff_EDI + 0x1f0) + 0x3d0) < 0.0) {
    fVar3 = -fVar3;
  }
  iVar7 = *(int *)(unaff_EDI + 0x240);
  uVar2 = *(undefined4 *)(iVar7 + 0x7c);
  *(float *)(iVar7 + 0x7c) = fVar3;
  *(undefined4 *)(iVar7 + 0x80) = uVar2;
  fVar3 = fVar3 - *(float *)(iVar7 + 0x80);
  fVar1 = (fVar3 * _K_HALF + *(float *)(iVar7 + 0x80)) * param_1;
  fVar3 = fVar3 / param_1;
  if (*(byte *)(iVar7 + 6) < *(byte *)(iVar7 + 5)) {
    *(byte *)(iVar7 + 6) = *(byte *)(iVar7 + 6) + 1;
  }
  fVar4 = param_1 + *(float *)(iVar7 + 8);
  pfVar6 = (float *)(*(int *)(iVar7 + 0x10) + (uint)*(byte *)(iVar7 + 7) * 4);
  *(float *)(iVar7 + 8) = fVar4;
  *(float *)(iVar7 + 8) = fVar4 - *pfVar6;
  *pfVar6 = param_1;
  bVar5 = *(char *)(iVar7 + 7) + 1;
  *(byte *)(iVar7 + 7) = bVar5;
  *(float *)(iVar7 + 0xc) = *(float *)(iVar7 + 8) / (float)*(byte *)(iVar7 + 6);
  if (*(byte *)(iVar7 + 5) <= bVar5) {
    *(undefined1 *)(iVar7 + 7) = 0;
  }
  if (*(byte *)(iVar7 + 0x2e) < *(byte *)(iVar7 + 0x2d)) {
    *(byte *)(iVar7 + 0x2e) = *(byte *)(iVar7 + 0x2e) + 1;
  }
  fVar4 = fVar1 + *(float *)(iVar7 + 0x30);
  pfVar6 = (float *)(*(int *)(iVar7 + 0x38) + (uint)*(byte *)(iVar7 + 0x2f) * 4);
  *(float *)(iVar7 + 0x30) = fVar4;
  *(float *)(iVar7 + 0x30) = fVar4 - *pfVar6;
  *pfVar6 = fVar1;
  bVar5 = *(char *)(iVar7 + 0x2f) + 1;
  *(byte *)(iVar7 + 0x2f) = bVar5;
  *(float *)(iVar7 + 0x34) = *(float *)(iVar7 + 0x30) / (float)*(byte *)(iVar7 + 0x2e);
  if (*(byte *)(iVar7 + 0x2d) <= bVar5) {
    *(undefined1 *)(iVar7 + 0x2f) = 0;
  }
  if (*(byte *)(iVar7 + 0x56) < *(byte *)(iVar7 + 0x55)) {
    *(byte *)(iVar7 + 0x56) = *(byte *)(iVar7 + 0x56) + 1;
  }
  fVar1 = fVar3 + *(float *)(iVar7 + 0x58);
  pfVar6 = (float *)(*(int *)(iVar7 + 0x60) + (uint)*(byte *)(iVar7 + 0x57) * 4);
  *(float *)(iVar7 + 0x58) = fVar1;
  *(float *)(iVar7 + 0x58) = fVar1 - *pfVar6;
  *pfVar6 = fVar3;
  bVar5 = *(char *)(iVar7 + 0x57) + 1;
  *(byte *)(iVar7 + 0x57) = bVar5;
  *(float *)(iVar7 + 0x5c) = *(float *)(iVar7 + 0x58) / (float)*(byte *)(iVar7 + 0x56);
  if (*(byte *)(iVar7 + 0x55) <= bVar5) {
    *(undefined1 *)(iVar7 + 0x57) = 0;
  }
  return;
}


// ==== 0x45e970 FUN_0045e970

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0045e970(int *param_1,float param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  bool bVar7;
  char cVar8;
  short sVar9;
  int iVar10;
  byte bVar11;
  int iVar12;
  char *pcVar13;
  int iVar14;
  bool bVar15;
  bool bVar16;
  float10 fVar17;
  float local_34;
  float local_30;
  float local_2c;
  int local_28;
  int local_24;
  float local_20;
  float local_1c;
  float local_18;
  float fStack_14;
  float fStack_10;
  float local_c;
  float local_8;
  float fStack_4;
  
  local_28 = 0;
  local_24 = 0;
  if (param_2 <= 0.0001) {
    local_8 = 0.0001;
  }
  else {
    local_8 = param_2;
  }
  local_30 = *(float *)(param_1[0x7c] + 0x3d4);
  local_c = (float)(uint)*(ushort *)(param_1 + 0x74);
  local_18 = (float)(int)local_c * 0.005493164;
  if (180.0 < local_18) {
    local_18 = local_18 - 360.0;
  }
  if (*(float *)(param_1[0x7c] + 0x3d0) < 0.0) {
    local_30 = -local_30;
  }
  FUN_0045fb30();
  iVar14 = param_1[0x7c];
  bVar16 = false;
  bVar7 = false;
  iVar12 = 0;
  pcVar13 = (char *)(iVar14 + 0x350);
  do {
    if (*pcVar13 != '\0') {
      if (iVar12 < 2) {
        bVar16 = true;
      }
      fVar2 = *(float *)(*(int *)(iVar14 + 0x40) + 0x1c0);
      if (fVar2 <= 0.9) {
        if ((fVar2 < 0.1) && (iVar12 != 1)) {
          bVar15 = iVar12 == 0;
          goto LAB_0045ea72;
        }
      }
      else if (iVar12 != 2) {
        bVar15 = iVar12 == 3;
LAB_0045ea72:
        if (!bVar15) goto LAB_0045ea79;
      }
      bVar7 = true;
    }
LAB_0045ea79:
    iVar12 = iVar12 + 1;
    pcVar13 = pcVar13 + 1;
  } while (iVar12 < 4);
  iVar12 = *(int *)(iVar14 + 0x28);
  if (iVar12 == 1) {
    local_2c = 1.4013e-45;
    bVar15 = false;
  }
  else if (iVar12 == 3) {
    local_2c = (float)((*(int *)(iVar14 + 0x24) != 4) - 1 & 4);
    if ((local_2c == 4.2039e-45) || (local_2c == 5.60519e-45)) goto LAB_0045ea9e;
    bVar15 = false;
  }
  else if (iVar12 == 4) {
    local_2c = 0.0;
    bVar15 = false;
  }
  else {
    local_2c = 4.2039e-45;
LAB_0045ea9e:
    bVar15 = true;
  }
  param_1[0x87] = (int)((float)param_1[0x87] - param_2);
  if (0.0 < (float)param_1[0x87]) {
    local_2c = 7.00649e-45;
  }
  if ((char)param_1[0x88] != '\0') {
    local_2c = 8.40779e-45;
  }
  FUN_0045e370(&local_1c,&local_34,&local_20);
  if (param_1[0x89] == 1) {
    (**(code **)(*param_1 + 0x5c))();
LAB_0045eb6a:
    param_1[0x89] = 0;
  }
  else if (param_1[0x89] == 2) {
    (**(code **)(*param_1 + 100))();
    goto LAB_0045eb6a;
  }
  if (bVar16) {
    iVar14 = param_1[0x8c];
    iVar12 = param_1[0x89];
    *(undefined4 *)(iVar14 + 0x80) = *(undefined4 *)(iVar14 + 0x7c);
    fVar2 = local_1c - *(float *)(iVar14 + 0x80);
    bVar16 = iVar12 != 4;
    fVar5 = _K_HALF * fVar2;
    *(float *)(iVar14 + 0x7c) = local_1c;
    fVar5 = (fVar5 + *(float *)(iVar14 + 0x80)) * param_2;
    if (bVar16) {
      fVar2 = fVar2 / param_2;
    }
    else {
      fVar2 = 0.0;
    }
    if (*(byte *)(iVar14 + 6) < *(byte *)(iVar14 + 5)) {
      *(byte *)(iVar14 + 6) = *(byte *)(iVar14 + 6) + 1;
    }
    fVar4 = param_2 + *(float *)(iVar14 + 8);
    pfVar1 = (float *)(*(int *)(iVar14 + 0x10) + (uint)*(byte *)(iVar14 + 7) * 4);
    *(float *)(iVar14 + 8) = fVar4;
    *(float *)(iVar14 + 8) = fVar4 - *pfVar1;
    *pfVar1 = param_2;
    bVar11 = *(char *)(iVar14 + 7) + 1;
    *(byte *)(iVar14 + 7) = bVar11;
    *(float *)(iVar14 + 0xc) = *(float *)(iVar14 + 8) / (float)*(byte *)(iVar14 + 6);
    if (*(byte *)(iVar14 + 5) <= bVar11) {
      *(undefined1 *)(iVar14 + 7) = 0;
    }
    if (*(byte *)(iVar14 + 0x2e) < *(byte *)(iVar14 + 0x2d)) {
      *(byte *)(iVar14 + 0x2e) = *(byte *)(iVar14 + 0x2e) + 1;
    }
    fVar4 = fVar5 + *(float *)(iVar14 + 0x30);
    pfVar1 = (float *)(*(int *)(iVar14 + 0x38) + (uint)*(byte *)(iVar14 + 0x2f) * 4);
    *(float *)(iVar14 + 0x30) = fVar4;
    *(float *)(iVar14 + 0x30) = fVar4 - *pfVar1;
    *pfVar1 = fVar5;
    bVar11 = *(char *)(iVar14 + 0x2f) + 1;
    *(byte *)(iVar14 + 0x2f) = bVar11;
    *(float *)(iVar14 + 0x34) = *(float *)(iVar14 + 0x30) / (float)*(byte *)(iVar14 + 0x2e);
    if (*(byte *)(iVar14 + 0x2d) <= bVar11) {
      *(undefined1 *)(iVar14 + 0x2f) = 0;
    }
    if (*(byte *)(iVar14 + 0x56) < *(byte *)(iVar14 + 0x55)) {
      *(byte *)(iVar14 + 0x56) = *(byte *)(iVar14 + 0x56) + 1;
    }
    fVar5 = fVar2 + *(float *)(iVar14 + 0x58);
    pfVar1 = (float *)(*(int *)(iVar14 + 0x60) + (uint)*(byte *)(iVar14 + 0x57) * 4);
    *(float *)(iVar14 + 0x58) = fVar5;
    *(float *)(iVar14 + 0x58) = fVar5 - *pfVar1;
    *pfVar1 = fVar2;
    bVar11 = *(char *)(iVar14 + 0x57) + 1;
    *(byte *)(iVar14 + 0x57) = bVar11;
    *(float *)(iVar14 + 0x5c) = *(float *)(iVar14 + 0x58) / (float)*(byte *)(iVar14 + 0x56);
    if (*(byte *)(iVar14 + 0x55) <= bVar11) {
      *(undefined1 *)(iVar14 + 0x57) = 0;
    }
    iVar14 = param_1[0x8d];
    *(undefined4 *)(iVar14 + 0x80) = *(undefined4 *)(iVar14 + 0x7c);
    fVar5 = _K_HALF;
    fVar2 = local_20 - *(float *)(iVar14 + 0x80);
    *(float *)(iVar14 + 0x7c) = local_20;
    fVar5 = (fVar5 * fVar2 + *(float *)(iVar14 + 0x80)) * param_2;
    if (bVar16) {
      fVar2 = fVar2 / param_2;
    }
    else {
      fVar2 = 0.0;
    }
    if (*(byte *)(iVar14 + 6) < *(byte *)(iVar14 + 5)) {
      *(byte *)(iVar14 + 6) = *(byte *)(iVar14 + 6) + 1;
    }
    fVar4 = param_2 + *(float *)(iVar14 + 8);
    pfVar1 = (float *)(*(int *)(iVar14 + 0x10) + (uint)*(byte *)(iVar14 + 7) * 4);
    *(float *)(iVar14 + 8) = fVar4;
    *(float *)(iVar14 + 8) = fVar4 - *pfVar1;
    *pfVar1 = param_2;
    bVar11 = *(char *)(iVar14 + 7) + 1;
    *(byte *)(iVar14 + 7) = bVar11;
    *(float *)(iVar14 + 0xc) = *(float *)(iVar14 + 8) / (float)*(byte *)(iVar14 + 6);
    if (*(byte *)(iVar14 + 5) <= bVar11) {
      *(undefined1 *)(iVar14 + 7) = 0;
    }
    if (*(byte *)(iVar14 + 0x2e) < *(byte *)(iVar14 + 0x2d)) {
      *(byte *)(iVar14 + 0x2e) = *(byte *)(iVar14 + 0x2e) + 1;
    }
    fVar4 = fVar5 + *(float *)(iVar14 + 0x30);
    pfVar1 = (float *)(*(int *)(iVar14 + 0x38) + (uint)*(byte *)(iVar14 + 0x2f) * 4);
    *(float *)(iVar14 + 0x30) = fVar4;
    *(float *)(iVar14 + 0x30) = fVar4 - *pfVar1;
    *pfVar1 = fVar5;
    bVar11 = *(char *)(iVar14 + 0x2f) + 1;
    *(byte *)(iVar14 + 0x2f) = bVar11;
    *(float *)(iVar14 + 0x34) = *(float *)(iVar14 + 0x30) / (float)*(byte *)(iVar14 + 0x2e);
    if (*(byte *)(iVar14 + 0x2d) <= bVar11) {
      *(undefined1 *)(iVar14 + 0x2f) = 0;
    }
    if (*(byte *)(iVar14 + 0x56) < *(byte *)(iVar14 + 0x55)) {
      *(byte *)(iVar14 + 0x56) = *(byte *)(iVar14 + 0x56) + 1;
    }
    fVar5 = fVar2 + *(float *)(iVar14 + 0x58);
    pfVar1 = (float *)(*(int *)(iVar14 + 0x60) + (uint)*(byte *)(iVar14 + 0x57) * 4);
    *(float *)(iVar14 + 0x58) = fVar5;
    *(float *)(iVar14 + 0x58) = fVar5 - *pfVar1;
    *pfVar1 = fVar2;
    bVar11 = *(char *)(iVar14 + 0x57) + 1;
    *(byte *)(iVar14 + 0x57) = bVar11;
    *(float *)(iVar14 + 0x5c) = *(float *)(iVar14 + 0x58) / (float)*(byte *)(iVar14 + 0x56);
    if (*(byte *)(iVar14 + 0x55) <= bVar11) {
      *(undefined1 *)(iVar14 + 0x57) = 0;
    }
    iVar14 = param_1[0x8e];
    *(undefined4 *)(iVar14 + 0x80) = *(undefined4 *)(iVar14 + 0x7c);
    fVar5 = _K_HALF;
    fVar2 = local_34 - *(float *)(iVar14 + 0x80);
    *(float *)(iVar14 + 0x7c) = local_34;
    local_1c = (fVar5 * fVar2 + *(float *)(iVar14 + 0x80)) * param_2;
    if (bVar16) {
      fVar2 = fVar2 / param_2;
    }
    else {
      fVar2 = 0.0;
    }
    if (*(byte *)(iVar14 + 6) < *(byte *)(iVar14 + 5)) {
      *(byte *)(iVar14 + 6) = *(byte *)(iVar14 + 6) + 1;
    }
    fVar5 = param_2 + *(float *)(iVar14 + 8);
    pfVar1 = (float *)(*(int *)(iVar14 + 0x10) + (uint)*(byte *)(iVar14 + 7) * 4);
    *(float *)(iVar14 + 8) = fVar5;
    *(float *)(iVar14 + 8) = fVar5 - *pfVar1;
    *pfVar1 = param_2;
    bVar11 = *(char *)(iVar14 + 7) + 1;
    *(byte *)(iVar14 + 7) = bVar11;
    *(float *)(iVar14 + 0xc) = *(float *)(iVar14 + 8) / (float)*(byte *)(iVar14 + 6);
    if (*(byte *)(iVar14 + 5) <= bVar11) {
      *(undefined1 *)(iVar14 + 7) = 0;
    }
    if (*(byte *)(iVar14 + 0x2e) < *(byte *)(iVar14 + 0x2d)) {
      *(byte *)(iVar14 + 0x2e) = *(byte *)(iVar14 + 0x2e) + 1;
    }
    fVar5 = local_1c + *(float *)(iVar14 + 0x30);
    pfVar1 = (float *)(*(int *)(iVar14 + 0x38) + (uint)*(byte *)(iVar14 + 0x2f) * 4);
    *(float *)(iVar14 + 0x30) = fVar5;
    *(float *)(iVar14 + 0x30) = fVar5 - *pfVar1;
    *pfVar1 = local_1c;
    bVar11 = *(char *)(iVar14 + 0x2f) + 1;
    *(byte *)(iVar14 + 0x2f) = bVar11;
    *(float *)(iVar14 + 0x34) = *(float *)(iVar14 + 0x30) / (float)*(byte *)(iVar14 + 0x2e);
    if (*(byte *)(iVar14 + 0x2d) <= bVar11) {
      *(undefined1 *)(iVar14 + 0x2f) = 0;
    }
    if (*(byte *)(iVar14 + 0x56) < *(byte *)(iVar14 + 0x55)) {
      *(byte *)(iVar14 + 0x56) = *(byte *)(iVar14 + 0x56) + 1;
    }
    fVar5 = fVar2 + *(float *)(iVar14 + 0x58);
    pfVar1 = (float *)(*(int *)(iVar14 + 0x60) + (uint)*(byte *)(iVar14 + 0x57) * 4);
    *(float *)(iVar14 + 0x58) = fVar5;
    *(float *)(iVar14 + 0x58) = fVar5 - *pfVar1;
    *pfVar1 = fVar2;
    local_c = (float)(uint)*(byte *)(iVar14 + 0x56);
    bVar11 = *(char *)(iVar14 + 0x57) + 1;
    *(byte *)(iVar14 + 0x57) = bVar11;
    *(float *)(iVar14 + 0x5c) = *(float *)(iVar14 + 0x58) / (float)(int)local_c;
    if (*(byte *)(iVar14 + 0x55) <= bVar11) {
      *(undefined1 *)(iVar14 + 0x57) = 0;
    }
    if (!bVar16) {
      param_1[0x89] = 0;
    }
    iVar14 = param_1[0x8c];
    iVar12 = param_1[0x8e];
    fVar17 = (float10)LinearTable__Lookup11
                                (&PTR_DAT_007060a8,
                                 ABS(*(float *)(iVar14 + 0x7c) - *(float *)(iVar12 + 0x7c)));
    fVar2 = (float)fVar17;
    fVar5 = _K_ONE - fVar2;
    local_c = fVar2 * *(float *)(iVar14 + 0x7c) + fVar5 * *(float *)(iVar12 + 0x7c);
    if (*(byte *)(iVar14 + 0x2e) == 0) {
      fVar4 = 0.0;
    }
    else {
      fVar4 = (*(float *)(iVar14 + 0x30) * (float)*(byte *)(iVar14 + 0x2e)) /
              (*(float *)(iVar14 + 8) * *(float *)(iVar14 + 0x78));
    }
    if (*(byte *)(iVar12 + 0x2e) == 0) {
      fVar6 = 0.0;
    }
    else {
      fVar6 = (*(float *)(iVar12 + 0x30) * (float)*(byte *)(iVar12 + 0x2e)) /
              (*(float *)(iVar12 + 8) * *(float *)(iVar12 + 0x78));
    }
    fStack_10 = fVar4 * fVar2 + fVar6 * fVar5;
    local_20 = *(float *)(iVar14 + 0x5c) * fVar2 + *(float *)(iVar12 + 0x5c) * fVar5;
    local_1c = -DAT_0077a4a4;
    if (fStack_10 <= local_1c) {
      fStack_10 = local_1c;
    }
    if (DAT_0077a4a4 < fStack_10) {
      fStack_10 = DAT_0077a4a4;
    }
    fStack_14 = -1.0;
    if (-1.0 < local_20) {
      fStack_14 = local_20;
    }
    if (1.0 < fStack_14) {
      fStack_14 = 1.0;
    }
    if ((bVar15) || (local_2c == 7.00649e-45)) {
      local_34 = *(float *)(&DAT_006b73fc + (int)local_2c * 4);
      local_20 = *(float *)(&DAT_006b73e0 + (int)local_2c * 4);
      fVar2 = *(float *)(&DAT_006b73c4 + (int)local_2c * 4);
    }
    else {
      fVar2 = *(float *)(param_1[0x7c] + 0x3d4);
      local_1c = fVar2;
      fVar17 = (float10)FUN_00583ea0(fVar2);
      local_1c = (float)fVar17;
      fVar17 = (float10)FUN_00583ea0(fVar2);
      local_20 = (float)fVar17;
      fVar17 = (float10)FUN_00583ea0(fVar2);
      local_34 = (float)fVar17;
      iVar14 = *(int *)(param_1[0x7c] + 0x10);
      if (*(char *)(iVar14 + 0x424) == -1) {
        RideInfo__RebuildPhysicsInfo(1);
      }
      fVar2 = (float)(int)*(char *)(iVar14 + 0x424);
      fStack_4 = fVar2;
      fVar17 = (float10)FUN_00583ea0(fVar2);
      fStack_4 = (float)fVar17;
      fVar17 = (float10)FUN_00583ea0(fVar2);
      local_1c = fStack_4 * local_1c;
      local_34 = (float)(fVar17 * (float10)local_34);
      fVar17 = (float10)FUN_00583ea0(fVar2);
      local_20 = (float)(fVar17 * (float10)local_20);
      if (((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) ||
         (cVar8 = IsCar1099InMode4(), fVar2 = local_1c, cVar8 != '\0')) {
        local_34 = local_34 * 1.0;
        local_20 = local_20 * 1.0;
        fVar2 = local_1c * 1.0;
      }
    }
    local_34 = (-(fVar2 * local_c) - fStack_14 * local_34) - fStack_10 * local_20;
    if (*(int *)(param_1[0x7c] + 0x28) == 1) {
      iVar14 = (int)*(char *)(*(int *)(param_1[0x7c] + 0x3c) + 0x1c);
      iVar12 = 0;
      if (0 < iVar14) {
        do {
          iVar10 = CollisionBody__GetCollision(iVar12);
          iVar3 = *(int *)(*(int *)(iVar10 + 100) + 600);
          if ((((*(char *)(iVar3 + 0x15) == '\x03') &&
               (ABS(*(float *)(*(int *)(iVar3 + 0x60) + 0x78)) < 0.1)) ||
              ((iVar3 = *(int *)(*(int *)(iVar10 + 100) + 0x25c), *(char *)(iVar3 + 0x15) == '\x03'
               && (ABS(*(float *)(*(int *)(iVar3 + 0x60) + 0x78)) < 0.1)))) &&
             ((fStack_4 = (float)(DAT_0073ad34 - *(int *)(iVar10 + 0xc)),
              (float)(int)fStack_4 * 0.00025 < 0.2 && (10.0 < *(float *)(iVar10 + 0x60))))) {
            local_34 = local_c * -100.0;
            break;
          }
          iVar12 = iVar12 + 1;
        } while (iVar12 < iVar14);
      }
    }
  }
  else {
    iVar14 = param_1[0x7c];
    if (1.0 <= *(float *)(iVar14 + 0x3d0)) {
      sVar9 = Atan2ToAngle16(*(undefined4 *)(iVar14 + 0x70),*(undefined4 *)(iVar14 + 0x74));
      fStack_4 = (float)(uint)(ushort)(*(short *)(iVar14 + 0x3b4) - sVar9);
      local_34 = (float)(int)fStack_4 * 9.58738e-05;
      if (3.14159 < local_34) {
        local_34 = local_34 - 6.28318;
      }
    }
    else {
      local_34 = 0.0;
    }
    local_34 = -local_34;
    fStack_10 = 0.08726646;
    if (local_34 <= -0.08726646) {
      local_34 = -0.08726646;
    }
    if (0.08726646 < local_34) {
      local_34 = 0.08726646;
    }
  }
  if (local_34 <= -0.7853982) {
    local_34 = -0.7853982;
  }
  else if (0.7853982 < local_34) {
    local_34 = 0.7853982;
  }
  local_c = ABS((float)param_1[0x80]) - *(float *)(param_1[0x7c] + 0x3d4);
  local_1c = local_34;
  if (param_1[0x89] == 3) {
    (**(code **)(*param_1 + 0x6c))();
    param_1[0x89] = 0;
  }
  iVar14 = param_1[0x8f];
  *(undefined4 *)(iVar14 + 0x80) = *(undefined4 *)(iVar14 + 0x7c);
  fVar2 = local_c - *(float *)(iVar14 + 0x80);
  *(float *)(iVar14 + 0x7c) = local_c;
  fVar5 = (fVar2 * _K_HALF + *(float *)(iVar14 + 0x80)) * param_2;
  local_c = fVar2 / param_2;
  if (*(byte *)(iVar14 + 6) < *(byte *)(iVar14 + 5)) {
    *(byte *)(iVar14 + 6) = *(byte *)(iVar14 + 6) + 1;
  }
  fVar2 = param_2 + *(float *)(iVar14 + 8);
  pfVar1 = (float *)(*(int *)(iVar14 + 0x10) + (uint)*(byte *)(iVar14 + 7) * 4);
  *(float *)(iVar14 + 8) = fVar2;
  *(float *)(iVar14 + 8) = fVar2 - *pfVar1;
  *pfVar1 = param_2;
  bVar11 = *(char *)(iVar14 + 7) + 1;
  *(byte *)(iVar14 + 7) = bVar11;
  *(float *)(iVar14 + 0xc) = *(float *)(iVar14 + 8) / (float)*(byte *)(iVar14 + 6);
  if (*(byte *)(iVar14 + 5) <= bVar11) {
    *(undefined1 *)(iVar14 + 7) = 0;
  }
  if (*(byte *)(iVar14 + 0x2e) < *(byte *)(iVar14 + 0x2d)) {
    *(byte *)(iVar14 + 0x2e) = *(byte *)(iVar14 + 0x2e) + 1;
  }
  fVar2 = fVar5 + *(float *)(iVar14 + 0x30);
  pfVar1 = (float *)(*(int *)(iVar14 + 0x38) + (uint)*(byte *)(iVar14 + 0x2f) * 4);
  *(float *)(iVar14 + 0x30) = fVar2;
  *(float *)(iVar14 + 0x30) = fVar2 - *pfVar1;
  *pfVar1 = fVar5;
  bVar11 = *(char *)(iVar14 + 0x2f) + 1;
  *(byte *)(iVar14 + 0x2f) = bVar11;
  *(float *)(iVar14 + 0x34) = *(float *)(iVar14 + 0x30) / (float)*(byte *)(iVar14 + 0x2e);
  if (*(byte *)(iVar14 + 0x2d) <= bVar11) {
    *(undefined1 *)(iVar14 + 0x2f) = 0;
  }
  if (*(byte *)(iVar14 + 0x56) < *(byte *)(iVar14 + 0x55)) {
    *(byte *)(iVar14 + 0x56) = *(byte *)(iVar14 + 0x56) + 1;
  }
  fVar2 = local_c + *(float *)(iVar14 + 0x58);
  pfVar1 = (float *)(*(int *)(iVar14 + 0x60) + (uint)*(byte *)(iVar14 + 0x57) * 4);
  *(float *)(iVar14 + 0x58) = fVar2;
  *(float *)(iVar14 + 0x58) = fVar2 - *pfVar1;
  *pfVar1 = local_c;
  fStack_4 = (float)(uint)*(byte *)(iVar14 + 0x56);
  bVar11 = *(char *)(iVar14 + 0x57) + 1;
  *(byte *)(iVar14 + 0x57) = bVar11;
  *(float *)(iVar14 + 0x5c) = *(float *)(iVar14 + 0x58) / (float)(int)fStack_4;
  if (*(byte *)(iVar14 + 0x55) <= bVar11) {
    *(undefined1 *)(iVar14 + 0x57) = 0;
  }
  FUN_0045e7b0(param_2);
  iVar14 = param_1[0x88];
  if (bVar7) {
    if (ABS((float)param_1[0x80]) < 2.0) {
      local_24 = 0x3f800000;
      local_28 = 0;
      goto LAB_0045f56f;
    }
    if ((float)param_1[0x80] <= 0.0) {
      if (local_30 <= 7.0) {
        if (local_30 < 2.0) {
          *(undefined1 *)(param_1 + 0x86) = 1;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x86) = 0;
      }
      if ((char)param_1[0x86] == '\0') {
        (**(code **)(*param_1 + 0x68))();
        local_24 = 0x3f666666;
        local_28 = 0;
        goto LAB_0045f56f;
      }
      iVar12 = 0;
      local_34 = -local_1c;
    }
    else {
      if (-7.0 <= local_30) {
        if (-2.0 < local_30) {
          *(undefined1 *)(param_1 + 0x86) = 1;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x86) = 0;
      }
      if ((char)param_1[0x86] == '\0') {
        (**(code **)(*param_1 + 0x68))();
        local_34 = -local_1c;
        local_28 = 0;
        local_24 = 0x3f666666;
        goto LAB_0045f56f;
      }
      iVar12 = -1;
    }
LAB_0045f573:
    FUN_0045fc90(&local_28,&local_24);
  }
  else {
    local_28 = 0;
    local_24 = 0;
    iVar12 = (**(code **)(**(int **)(param_1[0x7c] + 0x34) + 0x10))();
    if (iVar12 == 2) {
      local_28 = param_1[0x7f];
    }
    (**(code **)(*param_1 + 0x68))();
LAB_0045f56f:
    iVar12 = -1;
    if ((char)iVar14 != '\0') goto LAB_0045f573;
  }
  fVar2 = local_30;
  local_1c = 45.0;
  if (bVar15) {
    fVar17 = (float10)FUN_00583ea0(local_30);
    local_1c = (float)(fVar17 * (float10)1.0);
    if (fVar17 * (float10)1.0 <= (float10)0.0) {
      local_1c = 0.0;
    }
    else if (45.0 < local_1c) {
      local_1c = 45.0;
    }
  }
  local_2c = local_34 / (local_1c * 0.017453292);
  local_20 = local_18 / local_1c;
  if (bVar15) {
    if (local_2c <= -1.0) {
      local_2c = -1.0;
    }
    else if (_K_ONE < local_2c) {
      local_2c = _K_ONE;
    }
  }
  local_c = local_2c - local_20;
  fVar17 = (float10)FUN_00583ea0(fVar2);
  fVar17 = fVar17 * (float10)4.0;
  if (((0.0 < local_20) && (local_2c < local_20)) || ((local_20 < 0.0 && (local_20 < local_2c)))) {
    fVar17 = fVar17 * (float10)2.0;
  }
  fVar2 = (float)(fVar17 * (float10)local_8);
  fVar17 = -(fVar17 * (float10)local_8);
  if (fVar17 < (float10)local_c) {
    fVar17 = (float10)local_c;
  }
  if ((float10)fVar2 < fVar17) {
    fVar17 = (float10)fVar2;
  }
  local_18 = (float)((fVar17 + (float10)local_20) * (float10)local_1c);
  if (bVar15) {
    local_18 = local_18 * *(float *)(*(int *)(param_1[0x7c] + 0x20) + 0x270);
  }
  param_1[0x81] = (int)((float)param_1[0x81] - param_2);
  fVar2 = (float)param_1[0x81];
  if (fVar2 <= 0.0) {
    fVar2 = 0.0;
  }
  param_1[0x81] = (int)fVar2;
  if ((char)param_1[0x8a] == '\0') {
    if ((char)param_1[0x83] == '\0') {
      param_1[0x77] = 0;
      param_1[0x79] = 0;
    }
    else {
      param_1[0x77] = local_28;
      param_1[0x79] = local_24;
    }
  }
  else {
    param_1[0x79] = 0x3f800000;
    iVar14 = *(int *)(param_1[0x7c] + 0x24);
    iVar12 = 1;
    if (((iVar14 == 3) || (iVar14 == 2)) || (iVar14 == 4)) {
      (**(code **)(**(int **)(param_1[0x7c] + 0x2c) + 0x58))();
    }
    param_1[0x77] = 0x3f800000;
  }
  iVar14 = *(int *)(param_1[0x7c] + 0x3fc);
  if ((iVar14 == 0) || (iVar14 == 0x7fffffff)) {
LAB_0045f96e:
    if (*(char *)((int)param_1 + 0x229) == '\0') goto LAB_0045f9bf;
  }
  else {
    fStack_4 = (float)(DAT_0073ad34 - iVar14);
    if ((float)*(int *)(param_1[0x7c] + 0x3f8) * 0.00025 < (float)(int)fStack_4 * 0.00025) {
      CarState__StopNitrous();
      goto LAB_0045f96e;
    }
    if (*(char *)((int)param_1 + 0x229) == '\0') {
      *(undefined1 *)((int)param_1 + 0x229) = 1;
      goto LAB_0045f96e;
    }
  }
  if (((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) ||
     ((float)param_1[0x80] < (float)param_1[0x8b])) {
    *(undefined1 *)((int)param_1 + 0x229) = 0;
  }
  else {
    param_1[0x77] = param_1[0x7f];
    param_1[0x79] = 0;
  }
LAB_0045f9bf:
  param_1[0x8b] = param_1[0x80];
  param_1[0x84] = (int)((float)param_1[0x84] - param_2);
  if (((float)param_1[0x84] <= 0.0) || (ABS(local_30) <= K_EPS_SPEED)) {
    param_1[0x78] = 0;
  }
  else {
    param_1[0x79] = 0;
    param_1[0x78] = 0x3f800000;
    param_1[0x77] = 0;
  }
  iVar14 = _ftol_nocw();
  *(short *)(param_1 + 0x74) =
       (short)((ulonglong)((longlong)iVar14 * 0xb60b60b7) >> 0x28) -
       ((short)(char)((char)(iVar14 / 0x1680000) + (char)(iVar14 >> 0x1f)) >> 0xf);
  param_1[0x75] = iVar12;
  if ((char)param_1[0x88] != '\0') {
    param_1[0x79] = 0x3f800000;
    param_1[0x78] = 0x3f800000;
    param_1[0x77] = 0;
    iVar14 = param_1[0x7c];
    *(undefined4 *)(iVar14 + 0x478) = 0x3fb33333;
    if (*(int *)(iVar14 + 0x28) == 1) {
      *(undefined4 *)(*(int *)(iVar14 + 0x34) + 0x78) = 0x3fb33333;
    }
  }
  if (*(float *)(param_1[0x7c] + 0x3b8) < _DAT_0070031c !=
      (*(float *)(param_1[0x7c] + 0x3b8) == _DAT_0070031c)) {
    *(undefined2 *)(param_1 + 0x74) = 0;
  }
  return;
}


// ==== 0x45faf0 FUN_0045faf0

void __thiscall FUN_0045faf0(int param_1,char *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (((param_2 != (char *)0x0) && (-1 < *param_2)) && (*param_2 < '\x15')) {
    puVar2 = (undefined4 *)(param_1 + 0x10);
    for (iVar1 = 0x70; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *(undefined4 *)param_2;
      param_2 = param_2 + 4;
      puVar2 = puVar2 + 1;
    }
    FUN_00459980();
    return;
  }
  return;
}


// ==== 0x45fb30 FUN_0045fb30

void FUN_0045fb30(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  uint uVar3;
  undefined4 *puVar4;
  float10 fVar5;
  float10 fVar6;
  float local_38;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar1 = *(int *)(in_EAX + 0x1f0);
  iVar2 = *(int *)(iVar1 + 0x28);
  if (iVar2 == 1) {
LAB_0045fb9f:
    fVar6 = (float10)FUN_00583ea0(*(undefined4 *)(iVar1 + 0x3d0));
    iVar1 = *(int *)(*(int *)(in_EAX + 0x1f0) + 0x10);
    if (*(char *)(iVar1 + 0x424) == -1) {
      RideInfo__RebuildPhysicsInfo(1);
    }
    fVar5 = (float10)FUN_00583ea0((float)(int)*(char *)(iVar1 + 0x424));
    fVar5 = fVar5 * (float10)(float)fVar6;
  }
  else {
    if (iVar2 == 3) {
      uVar3 = (*(int *)(iVar1 + 0x24) != 4) - 1 & 4;
      if ((uVar3 != 3) && (uVar3 != 4)) goto LAB_0045fb9f;
    }
    else {
      if (iVar2 == 4) goto LAB_0045fb9f;
      uVar3 = 3;
    }
    fVar5 = (float10)*(float *)(iVar1 + 0x3d0) * (float10)*(float *)(&DAT_006b7418 + uVar3 * 4);
    local_38 = *(float *)(&DAT_006b7434 + uVar3 * 4);
    if (fVar5 < (float10)local_38) goto LAB_0045fbf8;
  }
  local_38 = (float)fVar5;
LAB_0045fbf8:
  if (*(char *)(in_EAX + 0x10) < '\x02') {
    if (5.0 <= *(float *)(*(int *)(in_EAX + 0x1f0) + 0x3d0)) {
      puVar4 = (undefined4 *)FUN_00456b20(local_38);
      local_2c = puVar4[1];
      local_30 = *puVar4;
    }
    else {
      puVar4 = (undefined4 *)FUN_00456a80();
      local_2c = puVar4[1];
      local_30 = *puVar4;
    }
  }
  else {
    FUN_004590a0(local_38,&local_30);
  }
  *(undefined4 *)(in_EAX + 0x1f8) = local_2c;
  *(undefined4 *)(in_EAX + 500) = local_30;
  *(undefined4 *)(*(int *)(in_EAX + 0x244) + 0x10) = 0;
  return;
}


// ==== 0x45fc90 FUN_0045fc90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0045fc90(undefined4 param_1,int param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  float fVar7;
  float *pfVar8;
  char cVar9;
  int unaff_EDI;
  float10 fVar10;
  float10 fVar11;
  float local_c;
  float local_8;
  
  pfVar8 = param_3;
  if ((*(char *)(unaff_EDI + 0x220) != '\0') ||
     (fVar4 = ABS(*(float *)(unaff_EDI + 0x200)), 5.0 <= fVar4)) {
    iVar5 = *(int *)(unaff_EDI + 0x23c);
    if (*(byte *)(iVar5 + 0x2e) == 0) {
      fVar4 = 0.0;
    }
    else {
      fVar4 = (*(float *)(iVar5 + 0x30) * (float)*(byte *)(iVar5 + 0x2e)) /
              (*(float *)(iVar5 + 8) * *(float *)(iVar5 + 0x78));
    }
    fVar7 = -DAT_00700524;
    if (-DAT_00700524 < *(float *)(iVar5 + 0x5c)) {
      fVar7 = *(float *)(iVar5 + 0x5c);
    }
    if (DAT_00700524 < fVar7) {
      fVar7 = DAT_00700524;
    }
    if (ABS(*(float *)(unaff_EDI + 0x200)) + 2.0 <= *(float *)(*(int *)(unaff_EDI + 0x1f0) + 0x3d4))
    {
      fVar1 = *(float *)(&DAT_0070057c + param_2 * 4);
      local_8 = 0.0;
      fVar2 = *(float *)(&DAT_00700598 + param_2 * 4);
      fVar3 = *(float *)(&DAT_007005b4 + param_2 * 4);
      local_c = -_DAT_007003f8;
    }
    else {
      fVar1 = *(float *)(&DAT_00700528 + param_2 * 4);
      local_c = 0.0;
      fVar2 = *(float *)(&DAT_00700544 + param_2 * 4);
      fVar3 = *(float *)(&DAT_00700560 + param_2 * 4);
      local_8 = *(float *)(unaff_EDI + 0x1fc);
    }
    fVar4 = fVar1 * *(float *)(iVar5 + 0x7c) + fVar2 * fVar4 + fVar7 * fVar3;
    fVar10 = (float10)FUN_00583ea0(ABS(*(float *)(*(int *)(unaff_EDI + 0x1f0) + 0x3d4)));
    fVar11 = -fVar10;
    if (fVar11 < (float10)fVar4) {
      fVar11 = (float10)fVar4;
    }
    if ((float10)(float)fVar10 < fVar11) {
      fVar11 = (float10)(float)fVar10;
    }
    fVar11 = ((float10)*(float *)(unaff_EDI + 0x1dc) - (float10)*(float *)(unaff_EDI + 0x1e4)) +
             fVar11;
    if (fVar11 <= (float10)local_c) {
      fVar11 = (float10)local_c;
    }
    if (fVar11 <= (float10)local_8) {
      param_3 = (float *)(float)fVar11;
    }
    else {
      param_3 = (float *)local_8;
    }
    local_c = 1.0;
    cVar9 = FUN_00460100();
    if (cVar9 != '\0') {
      iVar5 = *(int *)(unaff_EDI + 0x240);
      if (*(byte *)(iVar5 + 0x2e) == 0) {
        fVar4 = 0.0;
      }
      else {
        fVar4 = (*(float *)(iVar5 + 0x30) * (float)*(byte *)(iVar5 + 0x2e)) /
                (*(float *)(iVar5 + 8) * *(float *)(iVar5 + 0x78));
      }
      if (0.0 <= (float)param_3) {
        fVar2 = -0.2;
        fVar1 = -0.02;
        fVar7 = -0.005;
      }
      else {
        fVar2 = 0.02;
        fVar1 = 0.02;
        fVar7 = 0.005;
      }
      local_c = fVar2 * *(float *)(iVar5 + 0x7c) + fVar1 * fVar4 + fVar7 * *(float *)(iVar5 + 0x5c)
                + _K_ONE;
    }
    if ((float)param_3 < 0.0) {
      param_3 = (float *)-(float)param_3;
      cVar9 = FUN_00460100();
      if ((cVar9 != '\0') && (local_c <= (float)param_3)) {
        param_3 = (float *)local_c;
      }
      *pfVar8 = 0.0;
      *param_4 = (float)param_3;
      goto LAB_0045ffb0;
    }
    cVar9 = FUN_00460100();
    if ((cVar9 != '\0') && (local_c <= (float)param_3)) {
      param_3 = (float *)local_c;
    }
    *pfVar8 = (float)param_3;
  }
  else {
    fVar7 = ABS(fVar4 - *(float *)(*(int *)(unaff_EDI + 0x1f0) + 0x3d4));
    if (fVar7 < _K_ONE == (fVar7 == _K_ONE)) {
      if (fVar4 <= *(float *)(*(int *)(unaff_EDI + 0x1f0) + 0x3d4)) {
        *param_3 = 0.0;
        *param_4 = 1.0;
      }
      else {
        *param_3 = 1.0;
        *param_4 = 0.0;
      }
      goto LAB_0045ffb0;
    }
    *param_3 = 0.0;
  }
  *param_4 = 0.0;
LAB_0045ffb0:
  iVar5 = *(int *)(unaff_EDI + 0x1f0);
  if ((*(int *)(iVar5 + 0x28) == 1) &&
     (piVar6 = *(int **)(iVar5 + 0x2c),
     _DAT_006ffff0 <= *(float *)(*(int *)(*(int *)(iVar5 + 0x34) + 0x48) + 0x8c))) {
    *pfVar8 = 0.0;
    cVar9 = CarState__IsNitrousOn();
    if (cVar9 != '\0') {
      CarState__StopNitrous();
      (**(code **)(*piVar6 + 0x80))();
    }
  }
  fVar4 = *pfVar8;
  if (fVar4 <= 0.0) {
    fVar4 = 0.0;
  }
  if (*(float *)(unaff_EDI + 0x1fc) < fVar4) {
    fVar4 = *(float *)(unaff_EDI + 0x1fc);
  }
  *pfVar8 = fVar4;
  fVar4 = *param_4;
  if (fVar4 <= 0.0) {
    fVar4 = 0.0;
  }
  else if (_K_ONE < fVar4) {
    *param_4 = 1.0;
    return;
  }
  *param_4 = fVar4;
  return;
}


// ==== 0x460090 PsychoDriver::StartHonkHorn

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void __fastcall PsychoDriver__StartHonkHorn(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x1f0) + 0x878);
  if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004600a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 0x48))();
    return;
  }
  return;
}


// ==== 0x4600b0 PsychoDriver::StopHonkHorn

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void __fastcall PsychoDriver__StopHonkHorn(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x1f0) + 0x878);
  if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004600c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 0x4c))();
    return;
  }
  return;
}


// ==== 0x4600d0 PsychoDriver::IsHonking

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

uint __fastcall PsychoDriver__IsHonking(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = *(int **)(*(uint *)(param_1 + 0x1f0) + 0x878);
  if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004600e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*piVar1 + 0x50))();
    return uVar2;
  }
  return *(uint *)(param_1 + 0x1f0) & 0xffffff00;
}


// ==== 0x4600ec FUN_004600ec

int __fastcall FUN_004600ec(int param_1)

{
  return (int)*(short *)(*(int *)(param_1 + 0x1f0) + 10);
}


// ==== 0x4600f0 PsychoDriver::GetDriverNumber

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

int __fastcall PsychoDriver__GetDriverNumber(int param_1)

{
  return (int)*(short *)(*(int *)(param_1 + 0x1f0) + 10);
}


// ==== 0x460100 FUN_00460100

undefined4 FUN_00460100(void)

{
  int iVar1;
  int in_EAX;
  float10 fVar2;
  
  if ((*(char *)(in_EAX + 0x228) == '\0') &&
     (iVar1 = *(int *)(in_EAX + 0x1f0), *(int *)(*(int *)(iVar1 + 0x14) + 4) != 3)) {
    fVar2 = (float10)FUN_00432c90();
    if (((float10)10.0 < fVar2) &&
       ((iVar1 = *(int *)(iVar1 + 0x1c), iVar1 == 0 || (*(short *)(iVar1 + 0x10) == 0)))) {
      return 1;
    }
  }
  return 0;
}


// ==== 0x460150 PsychoDriver::GetForceYaw

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

int __fastcall PsychoDriver__GetForceYaw(int param_1)

{
  int iVar1;
  uint uVar2;
  ushort uVar6;
  uint uVar3;
  uint uVar4;
  float *pfVar5;
  
  uVar6 = 0;
  if ((*(int *)(param_1 + 0x1f0) != 0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x1f0) + 0x1c), uVar6 = 0, iVar1 != 0)) {
    uVar6 = (ushort)((uint)iVar1 >> 0x10);
    if ((*(short *)(iVar1 + 0x10) != 0) && (*(short *)(iVar1 + 0x10) != 1)) goto LAB_0046022a;
  }
  if (*(char *)(param_1 + 0x220) == '\0') {
LAB_0046022a:
    return (uint)uVar6 << 0x10;
  }
  if (*(short *)(param_1 + 0x222) == 0) {
    uVar2 = *(uint *)(DAT_007361f8 + 0x2d0);
    uVar3 = uVar2 ^ 0x1d872b41;
    uVar4 = uVar3 >> 5 ^ uVar3;
    *(uint *)(DAT_007361f8 + 0x2d0) = uVar4 << 0x1b ^ uVar4 ^ uVar3;
    pfVar5 = (float *)(**(code **)(**(int **)(*(int *)(param_1 + 0x1f0) + 0x2c) + 0x18))(1);
    if (pfVar5 == (float *)0x0) {
      if ((uVar2 & 1) != 0) goto LAB_0046021a;
    }
    else if ((*(float *)(*(int *)(param_1 + 0x1f0) + 0x60) - *pfVar5) * pfVar5[4] -
             (*(float *)(*(int *)(param_1 + 0x1f0) + 100) - pfVar5[1]) * pfVar5[3] < 0.0) {
LAB_0046021a:
      *(undefined2 *)(param_1 + 0x222) = 0x4000;
      return 0x4000;
    }
    uVar6 = 0;
    *(undefined2 *)(param_1 + 0x222) = 0xc000;
  }
  return CONCAT22(uVar6,*(undefined2 *)(param_1 + 0x222));
}


// ==== 0x460230 DragDriver::GetPort

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void __fastcall DragDriver__GetPort(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00460238. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0x250) + 0xc))();
  return;
}


// ==== 0x460240 DragDriver::SetJoystickPort

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void __fastcall DragDriver__SetJoystickPort(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0046024c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0x250) + 0x10))();
  return;
}


// ==== 0x460250 DragDriver::EnableStartLineState

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void __fastcall DragDriver__EnableStartLineState(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0046025c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0x250) + 0x1c))();
  return;
}


// ==== 0x460260 DragDriver::DisableStartLineState

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void __fastcall DragDriver__DisableStartLineState(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0046026c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0x250) + 0x20))();
  return;
}


// ==== 0x460270 DragDriver::SetSportGear

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

void __fastcall DragDriver__SetSportGear(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0046027c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0x250) + 0x30))();
  return;
}


// ==== 0x460280 DragDriver::GetSportGear

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

void __fastcall DragDriver__GetSportGear(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00460288. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0x250) + 0x28))();
  return;
}


// ==== 0x460290 DragDriver::SetDesiredGear

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

void __fastcall DragDriver__SetDesiredGear(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0046029c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0x250) + 0x2c))();
  return;
}


// ==== 0x4602a0 DragDriver::GetDesiredGear

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

void __fastcall DragDriver__GetDesiredGear(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x004602a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0x250) + 0x24))();
  return;
}


// ==== 0x4602b0 DragDriver::SetLowGear

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

void __fastcall DragDriver__SetLowGear(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x004602bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0x250) + 0x34))();
  return;
}


// ==== 0x4602c0 FUN_004602c0

undefined4 * __thiscall FUN_004602c0(int param_1,undefined4 *param_2)

{
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006868a9;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0045dbb0(param_2,param_1);
  local_4 = 0;
  *param_2 = &PTR_FUN_006c8b90;
  FUN_00460e70();
  local_4 = CONCAT31(local_4._1_3_,1);
  if (*DAT_0073619c == 4) {
    (**(code **)(param_2[0x94] + 0x20))();
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    RealDriver__SetManualTransmission();
  }
  *(undefined1 *)(param_2 + 0x144) = 0;
  ExceptionList = pvStack_c;
  return param_2;
}


// ==== 0x460350 FUN_00460350

void * __thiscall FUN_00460350(void *param_1,byte param_2)

{
  FUN_00460370(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x460370 FUN_00460370

void FUN_00460370(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  uint local_4;
  
  pcStack_8 = FUN_006868a9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c8b90;
  local_4 = 1;
  FUN_00460560();
  local_4 = local_4 & 0xffffff00;
  FUN_00460f50(param_1 + 0x94);
  local_4 = 0xffffffff;
  FUN_0045e080(param_1);
  ExceptionList = local_c;
  return;
}


// ==== 0x4603d0 FUN_004603d0

void __thiscall FUN_004603d0(int param_1,int param_2)

{
  FUN_0045e970(param_2);
  (**(code **)(*(int *)(param_1 + 0x250) + 4))();
  if ((DAT_0073608c != 0) && (0xf < *(ushort *)(param_2 + 0x420))) {
    *(ushort *)(param_2 + 0x1d0) = *(ushort *)(param_2 + 0x420);
  }
  *(undefined4 *)(param_2 + 0x1e4) = *(undefined4 *)(param_2 + 0x434);
  *(undefined4 *)(param_2 + 0x1e0) = *(undefined4 *)(param_2 + 0x430);
  *(undefined4 *)(param_2 + 0x1dc) = *(undefined4 *)(param_2 + 0x42c);
  return;
}


// ==== 0x460450 FUN_00460450

void __thiscall FUN_00460450(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"DragDriver");
  (**(code **)(*(int *)(param_1 + 0x250) + 8))(param_2);
  FUN_0045e1b0(param_2);
  FUN_00571c20(param_2,param_1 + 0x510,1,1,0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x4604d0 DragDriver::AddJoyHandlers

/* [canon] canon high (ghidra-canon+nfsug) docs/re/canon.md */

void __fastcall DragDriver__AddJoyHandlers(int *param_1)

{
  (**(code **)(param_1[0x94] + 0x14))();
  if ((char)param_1[0x144] == '\0') {
    (**(code **)(*param_1 + 0xc))(0xa6,FUN_004605e0,param_1);
    InputEvents__AddSource();
    (**(code **)(*param_1 + 0xc))(0xa7,FUN_004605e0,param_1);
    InputEvents__AddSource();
    (**(code **)(*param_1 + 0xc))(0xa8,FUN_004605e0,param_1);
    InputEvents__AddSource();
    (**(code **)(*param_1 + 0xc))(0xa9,FUN_004605e0,param_1);
    InputEvents__AddSource();
    *(undefined1 *)(param_1 + 0x144) = 1;
  }
  return;
}


// ==== 0x460560 FUN_00460560

void __fastcall FUN_00460560(int *param_1)

{
  (**(code **)(param_1[0x94] + 0x18))();
  if ((char)param_1[0x144] != '\0') {
    (**(code **)(*param_1 + 0xc))(0xa6);
    FUN_005740b0();
    (**(code **)(*param_1 + 0xc))(0xa7);
    FUN_005740b0();
    (**(code **)(*param_1 + 0xc))(0xa8);
    FUN_005740b0();
    (**(code **)(*param_1 + 0xc))(0xa9);
    FUN_005740b0();
    *(undefined1 *)(param_1 + 0x144) = 0;
  }
  return;
}


// ==== 0x4605e0 FUN_004605e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004605e0(undefined4 param_1,undefined4 param_2,char param_3,int param_4)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (DAT_0073608c == 0) {
    iVar4 = *(int *)(param_4 + 0x1f0);
    piVar1 = *(int **)(iVar4 + 0x2c);
    if (_DAT_0070031c <= *(float *)(iVar4 + 0x3b8)) {
      switch(param_2) {
      case 0xa6:
      case 0xa8:
        if (DAT_007003d8 == 0) {
          if (param_3 != '\0') {
            FUN_0045d970();
            return;
          }
        }
        else {
          if (param_3 == '\0') {
LAB_004606b6:
            piVar1[0x140] = 2;
            *(undefined1 *)(piVar1 + 0x12f) = 1;
            return;
          }
          if (piVar1[0x140] != 0) {
            piVar1[0x140] = 0;
            piVar1[0x141] = 0xff;
            piVar1[0x142] = 0xff;
            uVar3 = (**(code **)(*piVar1 + 0x40))(0xff,0xff);
            (**(code **)(*piVar1 + 0x18))(0,uVar3);
            iVar4 = GetNearestTrafficLane(iVar4);
            cVar2 = FUN_0045d970();
            if ((cVar2 != '\0') && (0xb < iVar4)) {
              piVar1[0x141] = iVar4;
              piVar1[0x142] = 0x10;
              *(undefined1 *)(piVar1 + 0x12f) = 1;
            }
          }
        }
        break;
      case 0xa7:
      case 0xa9:
        if (DAT_007003d8 == 0) {
          if (param_3 != '\0') {
            FUN_0045d970();
            return;
          }
        }
        else {
          if (param_3 == '\0') goto LAB_004606b6;
          if (piVar1[0x140] != 1) {
            piVar1[0x140] = 1;
            piVar1[0x141] = 0xff;
            piVar1[0x142] = 0xff;
            uVar3 = (**(code **)(*piVar1 + 0x40))(0xff,0xff);
            (**(code **)(*piVar1 + 0x18))(0,uVar3);
            iVar4 = GetNearestTrafficLane(iVar4);
            cVar2 = FUN_0045d970();
            if ((cVar2 != '\0') && (iVar4 < 0x10)) {
              piVar1[0x142] = iVar4;
              piVar1[0x141] = 0xb;
              *(undefined1 *)(piVar1 + 0x12f) = 1;
              return;
            }
          }
        }
      }
    }
  }
  return;
}


// ==== 0x4607a0 RealDriver::IsDriftModeActive

/* [canon] car med (ghidra-canon+hopper) docs/re/car.md */

undefined4 RealDriver__IsDriftModeActive(void)

{
  int in_EAX;
  
  if (((*(char *)(in_EAX + 0x54) == '\0') && (DAT_007361a8 == 0)) &&
     ((DAT_00735fa0 != 0 || ((*(char *)(in_EAX + 0x55) != '\0' || (DAT_007361a4 != 0)))))) {
    return 1;
  }
  return 0;
}


// ==== 0x4607e0 RealDriver::SetJoystickPort

/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

void __thiscall RealDriver__SetJoystickPort(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x270) = param_2;
  return;
}


// ==== 0x4607f0 RealDriver::EnableStartLineState

/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

void __fastcall RealDriver__EnableStartLineState(int param_1)

{
  *(undefined4 *)(param_1 + 0x278) = 1;
  return;
}


// ==== 0x460800 RealDriver::GetDriverNumber

/* [canon] car med (ghidra-canon+nfsug) docs/re/car.md */

int __fastcall RealDriver__GetDriverNumber(int param_1)

{
  return (int)*(short *)(*(int *)(param_1 + 0x26c) + 10);
}


// ==== 0x460810 FUN_00460810

undefined4 __fastcall FUN_00460810(int param_1)

{
  return *(undefined4 *)(param_1 + 0x270);
}


// ==== 0x460820 StringBufPair_Destroy

/* [canon] runtime med (ghidra-canon+hopper) docs/re/car.md */

void StringBufPair_Destroy(void)

{
  int unaff_ESI;
  
  *(undefined ***)(unaff_ESI + 0x3c) = &PTR_FUN_006b968c;
  _free(*(void **)(unaff_ESI + 0x6c));
  *(undefined ***)(unaff_ESI + 0x3c) = &PTR_FUN_006b9694;
  if (*(void **)(unaff_ESI + 0x4c) != (void *)(unaff_ESI + 0x50)) {
    _free(*(void **)(unaff_ESI + 0x4c));
  }
  *(undefined ***)(unaff_ESI + 0x3c) = &PTR_FUN_006c7d78;
  *(undefined ***)(unaff_ESI + 8) = &PTR_FUN_006b968c;
  _free(*(void **)(unaff_ESI + 0x38));
  *(undefined ***)(unaff_ESI + 8) = &PTR_FUN_006b9694;
  if (*(void **)(unaff_ESI + 0x18) != (void *)(unaff_ESI + 0x1c)) {
    _free(*(void **)(unaff_ESI + 0x18));
  }
  *(undefined ***)(unaff_ESI + 8) = &PTR_FUN_006c7d78;
  return;
}


// ==== 0x460890 FUN_00460890

void FUN_00460890(void)

{
  int in_EAX;
  int iVar1;
  char cVar2;
  int unaff_ESI;
  
  FUN_00571ea0(0,"PlayerSteering");
  FUN_00571c20(unaff_ESI,in_EAX + 0x70,2,2,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x74,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x78,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 4,1,1,0);
  FUN_00584430();
  FUN_00584430();
  iVar1 = *(char *)(unaff_ESI + 0x40) * 0x10;
  *(int *)(iVar1 + unaff_ESI + 0x58) =
       *(int *)(unaff_ESI + 0x150) - *(int *)(iVar1 + 0x58 + unaff_ESI);
  cVar2 = *(char *)(unaff_ESI + 0x40) + -1;
  *(char *)(unaff_ESI + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(unaff_ESI + 0x44)) {
    *(undefined4 *)(unaff_ESI + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x460930 FUN_00460930

undefined2 FUN_00460930(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int unaff_ESI;
  
  FUN_00584500(param_1,(float)DAT_0073ad3c * 0.00025);
  FUN_00460970(param_1,param_2,param_3);
  *(undefined4 *)(unaff_ESI + 0x78) = param_1;
  return *(undefined2 *)(unaff_ESI + 0x70);
}


// ==== 0x460970 FUN_00460970

void FUN_00460970(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_EAX;
  int iVar1;
  
  FUN_00460a80(param_1,param_2,param_3);
  if (DAT_00736514 == '\0') {
    FUN_00460de0(param_1,param_2,param_3);
  }
  iVar1 = _ftol_nocw();
  *(short *)(in_EAX + 0x70) =
       (short)((ulonglong)((longlong)iVar1 * 0xb60b60b7) >> 0x28) -
       ((short)(char)((char)(iVar1 / 0x1680000) + (char)(iVar1 >> 0x1f)) >> 0xf);
  return;
}


// ==== 0x460a80 FUN_00460a80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00460a80(float param_1,float param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  char cVar10;
  int *unaff_EDI;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
  float local_14;
  float local_10;
  float local_c;
  
  if (DAT_00736514 == '\0') {
    fVar11 = (float10)FUN_00583ea0(*(undefined4 *)(*unaff_EDI + 0x3d0));
    iVar1 = *(int *)(*unaff_EDI + 0x30);
    fVar2 = *(float *)(iVar1 + 0x1dc);
    fVar3 = *(float *)(iVar1 + 0x1e4);
    fVar4 = *(float *)(iVar1 + 0x1e0);
    fVar12 = (float10)FUN_00583ea0(*(undefined4 *)(*unaff_EDI + 0x3d0));
    fVar5 = (float10)_K_ONE;
    fVar7 = (float10)_K_HALF;
    fVar8 = (float10)_K_HALF;
    fVar9 = (float10)_K_ONE;
    fVar6 = (float10)_K_ONE;
    fVar13 = (float10)FUN_00583ea0(ABS((float)unaff_EDI[5]));
    fVar13 = fVar13 * (float10)(float)(((fVar9 - (((float10)fVar2 + fVar5) -
                                                 ((float10)fVar4 + (float10)fVar3) * fVar7) * fVar8)
                                        * fVar12 * (float10)0.8 + fVar6) * (float10)(float)fVar11);
  }
  else {
    fVar13 = (float10)FUN_00583ea0(*(undefined4 *)(*unaff_EDI + 0x3d0));
  }
  local_14 = (float)fVar13;
  local_10 = 0.0;
  if (DAT_00736514 == '\0') {
    iVar1 = *(int *)(*(int *)(*unaff_EDI + 0x3c) + 0x14c);
    if (((iVar1 != 0) && (iVar1 != 0x7fffffff)) &&
       (fVar2 = (float)(DAT_0073ad34 - iVar1) * 0.00025, fVar2 < 1.0)) {
      fVar3 = *(float *)(*unaff_EDI + 0x3d0);
      fVar13 = (float10)RideInfo__GetTheoreticalTopSpeed();
      fVar13 = (float10)fVar3 / (fVar13 * (float10)0.7);
      if (fVar13 <= (float10)_K_ONE) {
        local_c = (float)fVar13;
      }
      else {
        local_c = 1.0;
      }
      fVar13 = (float10)LinearTable__Lookup11(&PTR_DAT_00705fe0,fVar2);
      local_10 = (float)fVar13;
      local_14 = ((_K_ONE - local_10) * (_K_ONE - local_c) + local_10) * local_14;
    }
  }
  cVar10 = DAT_00736514;
  if (1.0 <= *(float *)(*unaff_EDI + 0x3d0)) {
    fVar13 = (float10)CarState__GetYaw();
  }
  else {
    fVar13 = (float10)0.0;
  }
  iVar1 = *unaff_EDI;
  fVar2 = (float)ABS(fVar13 * (float10)57.295776);
  fVar3 = SQRT(*(float *)(iVar1 + 0x78) * *(float *)(iVar1 + 0x78) +
               *(float *)(iVar1 + 0x74) * *(float *)(iVar1 + 0x74) +
               *(float *)(iVar1 + 0x70) * *(float *)(iVar1 + 0x70));
  if ((char)unaff_EDI[1] == '\0') {
    if ((_DAT_0070013c < fVar2) && (_DAT_00700148 <= fVar3)) {
      *(undefined1 *)(unaff_EDI + 1) = 1;
    }
  }
  else if ((fVar2 < _DAT_00700140) || (fVar3 < _DAT_0070014c)) {
    *(undefined1 *)(unaff_EDI + 1) = 0;
  }
  fVar3 = local_14;
  if ((float10)0.0 <= (float10)param_1 * fVar13 * (float10)57.295776) {
    if (((cVar10 != '\0') || (ABS((float)unaff_EDI[5]) < 0.5)) ||
       (fVar3 = (float)unaff_EDI[0x1d] - param_2 * 0.0, local_14 <= fVar3)) goto LAB_00460dac;
  }
  else {
    if (((char)unaff_EDI[1] == '\0') && (fVar2 <= local_14)) goto LAB_00460dac;
    if (cVar10 == '\0') {
      RealDriver__IsDriftModeActive();
      fVar13 = (float10)FUN_00583ea0(ABS(param_1));
    }
    else {
      fVar13 = (float10)_K_ONE;
    }
    local_14 = (float)(((float10)local_10 * (float10)0.6666667 + (float10)_K_ONE) * fVar13 *
                      (float10)fVar2);
    if (fVar13 * (float10)45.0 < (float10)local_14) {
      fVar3 = (float)(fVar13 * (float10)45.0);
      goto LAB_00460dac;
    }
  }
  fVar3 = local_14;
LAB_00460dac:
  local_14 = fVar3;
  if (45.0 <= local_14) {
    local_14 = 45.0;
  }
  unaff_EDI[0x1d] = (int)local_14;
  return (float10)local_14;
}


// ==== 0x460de0 FUN_00460de0

float10 FUN_00460de0(float param_1,float param_2)

{
  int *unaff_EDI;
  float10 fVar1;
  float10 fVar2;
  float fVar3;
  
  fVar3 = (float)DAT_0073ad3c * 0.00025;
  fVar1 = (float10)FUN_00583ea0(ABS((param_1 - (float)unaff_EDI[0x1e]) / param_2));
  FUN_00584500((float)fVar1,fVar3);
  fVar1 = (float10)FUN_00583ea0(*(undefined4 *)(*unaff_EDI + 0x3d0));
  fVar3 = (float)unaff_EDI[0x12];
  fVar2 = (float10)FUN_00583ea0(ABS((float)unaff_EDI[5]));
  return fVar2 * (float10)(float)((float10)fVar3 * fVar1 * (float10)110.0);
}


// ==== 0x460e70 FUN_00460e70

void FUN_00460e70(void)

{
  undefined4 *in_EAX;
  undefined4 extraout_EDX;
  undefined4 unaff_EDI;
  
  FUN_00424f60();
  *in_EAX = &PTR_FUN_006c8ad0;
  FUN_00584360(0x3f0ccccd,0x42700000);
  FUN_00584360(0x3e19999a,0x42700000);
  in_EAX[0x7c] = unaff_EDI;
  *(undefined2 *)(in_EAX + 0x98) = 0;
  in_EAX[0x9a] = 0;
  in_EAX[0x99] = 0x42340000;
  *(undefined1 *)(in_EAX + 0x7d) = 0;
  in_EAX[0x9b] = unaff_EDI;
  in_EAX[0x9c] = 0xffffffff;
  in_EAX[0x9d] = 0;
  RealDriver__ResetJoyValues();
  in_EAX[0x9e] = 1;
  in_EAX[0x75] = 1;
  *(undefined1 *)(in_EAX + 0xae) = 1;
  in_EAX[0x9f] = extraout_EDX;
  in_EAX[0xa0] = extraout_EDX;
  in_EAX[0xa1] = extraout_EDX;
  *(char *)(in_EAX + 0xac) = (char)extraout_EDX;
  in_EAX[0xad] = 0x3f800000;
  return;
}


// ==== 0x460f30 FUN_00460f30

void * __thiscall FUN_00460f30(void *param_1,byte param_2)

{
  FUN_00460f50(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x460f50 FUN_00460f50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00460f50(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685526;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c8ad0;
  local_4 = 1;
  if (*(int *)(param_1[0x9b] + 0x18) != 0) {
    _gSpecialCameraActive = 0;
  }
  FUN_004613b0();
  StringBufPair_Destroy();
  *param_1 = &PTR_PsychoDriver__scalar_deleting_dtor_006caa58;
  ExceptionList = local_c;
  return;
}


// ==== 0x460fc0 FUN_00460fc0

void __thiscall FUN_00460fc0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"RealDriver");
  FUN_00571c20(param_2,param_1 + 0x270,1,4,1);
  FUN_00571c20(param_2,param_1 + 0x278,1,4,1);
  FUN_00571c20(param_2,param_1 + 0x27c,1,4,1);
  FUN_00571c20(param_2,param_1 + 0x284,1,4,1);
  FUN_00571c20(param_2,param_1 + 0x280,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x288,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x289,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x28c,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x290,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x291,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x292,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x294,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x298,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x299,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x29a,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x29c,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x2a0,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x2a1,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x2a4,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x2a8,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x2a9,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x2ac,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x2b0,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x2b4,4,0xffffffff,0);
  FUN_00460890();
  FUN_004251a0(param_2);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


