// ==== 0x431020 FUN_00431020

void FUN_00431020(int param_1)

{
  byte *pbVar1;
  undefined4 *puVar2;
  int in_EAX;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  
  *(int *)(param_1 + 4) = in_EAX;
  *(int *)(in_EAX + 0x18) = param_1;
  *(int *)(in_EAX + 0x400) = (int)*(char *)(param_1 + 0x22);
  if (*(int *)(in_EAX + 0x24) == 1) {
    RealDriver__SetManualTransmission();
  }
  *(undefined4 *)(param_1 + 0x2a0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x29c) = 0xffffffff;
  puVar3 = (undefined4 *)FUN_00567160();
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[2] = 0;
    puVar3[3] = 0;
  }
  *(undefined4 **)(param_1 + 400) = puVar3;
  pcVar6 = "MARKER_DIRECTION_AID";
  iVar5 = -1;
  uVar4 = 0x4d;
  do {
    iVar5 = iVar5 * 0x21 + uVar4;
    pbVar1 = (byte *)(pcVar6 + 1);
    uVar4 = (uint)*pbVar1;
    pcVar6 = pcVar6 + 1;
  } while (*pbVar1 != 0);
  puVar3[2] = iVar5;
  puVar3[4] = 0;
  puVar3[5] = 0;
  if (iVar5 != 0) {
    *DAT_00743c74 = puVar3;
    puVar2 = puVar3;
    puVar3[1] = DAT_00743c74;
    DAT_00743c74 = puVar2;
    *puVar3 = &DAT_00743c70;
  }
  if (puVar3[2] != 0) {
    Solid_FindInAllLists();
    FUN_0053f4b0();
  }
  if ((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) {
    FUN_0043dd40(param_1);
  }
  return;
}


// ==== 0x431100 Player::CleanupAfterRace

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera high (ghidra-canon+nfsug) docs/re/canon.md */

void Player__CleanupAfterRace(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  
  _gSpecialCameraActive = 0;
  *(undefined1 *)(unaff_ESI + 0x270) = 0;
  Player__ChangeCameraMover(unaff_ESI,0,0);
  if (*(undefined4 **)(unaff_ESI + 0x280) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_ESI + 0x280))(1);
    *(undefined4 *)(unaff_ESI + 0x280) = 0;
  }
  if (*(undefined4 **)(unaff_ESI + 0x284) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_ESI + 0x284))(1);
    *(undefined4 *)(unaff_ESI + 0x284) = 0;
  }
  Player__SetInputMode(0);
  *(undefined4 *)(*(int *)(unaff_ESI + 4) + 0x18) = 0;
  puVar1 = *(undefined4 **)(unaff_ESI + 400);
  *(undefined4 *)(unaff_ESI + 4) = 0;
  if (puVar1 != (undefined4 *)0x0) {
    ListRef_Release();
    iVar3 = DAT_0073557c;
    iVar2 = *(int *)(DAT_0073557c + 0x18);
    *puVar1 = *(undefined4 *)(DAT_0073557c + 0x10);
    *(int *)(iVar3 + 0x18) = iVar2 + -1;
    *(undefined4 **)(iVar3 + 0x10) = puVar1;
  }
  *(undefined4 *)(unaff_ESI + 400) = 0;
  return;
}


// ==== 0x431190 Players_AssignTypeFromTable

/* [canon] camera med (ghidra-canon+hopper) docs/re/canon.md */

void Players_AssignTypeFromTable(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_007361c4;
  iVar3 = 0;
  if (0 < DAT_007361c4) {
    do {
      piVar1 = &DAT_007361bc + iVar3;
      iVar3 = iVar3 + 1;
      *(uint *)(*piVar1 + 0xc) = (uint)(byte)(&DAT_007306c4)[*(int *)(*piVar1 + 8)];
    } while (iVar3 < iVar2);
  }
  return;
}


// ==== 0x4311c0 Players::UpdateAll

/* [canon] hud med (ghidra+hopper+capstone) docs/re/hud_input.md */

int Players__UpdateAll(void)

{
  int iVar1;
  
  iVar1 = 0;
  DAT_007361c8 = 0;
  if (0 < DAT_007361c4) {
    do {
      Player__UpdateFrame();
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_007361c4);
  }
  iVar1 = DAT_007361c4;
  if (((DAT_0073612c != 0) && (0 < DAT_007361c4)) &&
     (iVar1 = DAT_00734574 / 10, DAT_00734574 % 10 == 0)) {
    iVar1 = Player__UpdateFrame();
    return iVar1;
  }
  return iVar1;
}


// ==== 0x431230 Player::IsAllowedToReset

/* [canon] rivals med (ghidra-canon) docs/re/rivals.md */

uint __fastcall Player__IsAllowedToReset(int param_1)

{
  float fVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x60);
  if (((SpecialCamModeTable__flags__0_0_0_1_1_1_1_1___5_readers__recheck__0x42da40_refuses_a_new_special_camera_when_a_player_s_byte_is_non_zero__so__busy__not__enable___I_
        [uVar2] == (code)0x0) || (uVar2 == 6)) || (uVar2 == 7)) {
    fVar1 = *(float *)(*(int *)(param_1 + 4) + 0x3d4) * 2.237;
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),
                     (ushort)(fVar1 < 60.0) << 8 | (ushort)NAN(fVar1) << 10 |
                     (ushort)(fVar1 == 60.0) << 0xe);
    if (fVar1 < 60.0 || (fVar1 == 60.0) != 0) {
      uVar2 = Car__IsResetGraceActive();
      if ((char)uVar2 == '\0') {
        uVar2 = 0;
        if (DAT_0078a368 != 0) {
          fVar1 = (float)*(int *)(DAT_0073619c + 0x14) * 0.00025;
          uVar2 = CONCAT22((short)((uint)DAT_0073619c >> 0x10),
                           (ushort)(fVar1 < 5.0) << 8 | (ushort)NAN(fVar1) << 10 |
                           (ushort)(fVar1 == 5.0) << 0xe);
          if (fVar1 < 5.0) goto LAB_00431290;
        }
        return CONCAT31((int3)(uVar2 >> 8),1);
      }
    }
  }
LAB_00431290:
  return uVar2 & 0xffffff00;
}


// ==== 0x4312a0 FUN_004312a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004312a0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int unaff_EDI;
  float10 fVar7;
  
  fVar1 = *(float *)(*(int *)(unaff_EDI + 4) + 0x3d4) * 2.237;
  fVar2 = (float)(DAT_0073ad34 - *(int *)(*(int *)(*(int *)(unaff_EDI + 4) + 0x3c) + 0x144)) *
          0.00025;
  if (((60.0 < fVar1) && (fVar2 < 3.0)) &&
     (fVar7 = (float10)CarState__GetYaw(), (float10)50.0 < ABS(fVar7 * (float10)57.295776))) {
    *(int *)(unaff_EDI + 0xb4) = DAT_0073ad34;
  }
  fVar3 = (float)(DAT_0073ad34 - *(int *)(unaff_EDI + 0xc0)) * 0.00025;
  if (_K_HALF < fVar3) {
    if (((60.0 < *(float *)(unaff_EDI + 0xbc)) && (fVar2 < 3.0)) &&
       ((fVar1 - *(float *)(unaff_EDI + 0xbc)) / fVar3 < -70.0)) {
      *(int *)(unaff_EDI + 0xb4) = DAT_0073ad34;
    }
    *(float *)(unaff_EDI + 0xbc) = fVar1;
    *(int *)(unaff_EDI + 0xc0) = DAT_0073ad34;
  }
  if ((fVar1 < 10.0) && (*(float *)(*(int *)(unaff_EDI + 4) + 0xb8) < 0.0)) {
    *(int *)(unaff_EDI + 0xb4) = DAT_0073ad34;
  }
  iVar6 = DAT_0073ad34;
  iVar5 = _ftol_nocw();
  if (iVar5 < iVar6 - *(int *)(unaff_EDI + 0xb4)) {
    *(undefined4 *)(unaff_EDI + 0xb4) = 0;
    iVar6 = DAT_0073ad34;
  }
  if (((*(int *)(unaff_EDI + 0xb4) == 0) || (*(int *)(unaff_EDI + 0xb4) == 0x7fffffff)) ||
     (cVar4 = Player__IsAllowedToReset(), cVar4 == '\0')) {
    if (((*(int *)(unaff_EDI + 0xb8) != 0) && (*(int *)(unaff_EDI + 0xb8) != 0x7fffffff)) &&
       (iVar5 = _ftol_nocw(), iVar5 < iVar6 - *(int *)(unaff_EDI + 0xb8))) {
      *(undefined4 *)(unaff_EDI + 0xb8) = 0;
    }
  }
  else if ((*(int *)(unaff_EDI + 0xb8) == 0) || (*(int *)(unaff_EDI + 0xb8) == 0x7fffffff)) {
    *(undefined4 *)(unaff_EDI + 0xb4) = 0;
    return;
  }
  return;
}


// ==== 0x4314a0 Player::ResetToRoute

/* [canon] track high (hopper+ghidra) docs/re/track.md */

void Player__ResetToRoute(void)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  int in_EAX;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 unaff_EBX;
  float *pfVar9;
  undefined4 unaff_EDI;
  float10 fVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  float fStack_304;
  float *pfStack_300;
  undefined4 local_2fc;
  float fStack_2f8;
  float fStack_2f4;
  int local_2f0;
  int iStack_2ec;
  float *pfStack_2e8;
  float fStack_2e4;
  float fStack_2e0;
  undefined4 uStack_2dc;
  undefined1 auStack_2d4 [32];
  int aiStack_2b4 [160];
  int iStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  iVar2 = *(int *)(in_EAX + 4);
  if ((*(int *)(in_EAX + 0x60) == 6) || (*(int *)(in_EAX + 0x60) == 7)) {
    Player__EndSpecialCamera(1);
  }
  if ((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) {
    FUN_0043ef00();
  }
  fVar1 = *(float *)(iVar2 + 0x3d0);
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
  }
  local_2fc = *(float *)(iVar2 + 0x818) * *(float *)(iVar2 + 0x90) +
              *(float *)(iVar2 + 0x81c) * *(float *)(iVar2 + 0x94);
  if (local_2fc <= 0.0) {
    local_2fc = 0.0;
  }
  local_2fc = local_2fc * fVar1;
  if (DAT_00700d58 <= local_2fc) {
    local_2fc = DAT_00700d58;
  }
  local_2f0 = 0x3f800000;
  if (DAT_0078a2fc != 0) {
    local_2f0 = 0xbf800000;
  }
  iVar4 = (**(code **)(**(int **)(iVar2 + 0x2c) + 0x14))(1);
  if (iVar4 == 0) {
    fStack_2f8 = 0.0;
    pfStack_300 = (float *)0x0;
    local_2f0 = 0;
    pfVar9 = (float *)0x0;
    if (0 < DAT_007372c0) {
      pfStack_2e8 = (float *)FUN_0041f5e0();
      iStack_2ec = 0;
      do {
        if (iStack_2ec < 0) {
          pfVar9 = (float *)0x0;
        }
        else {
          pfVar9 = (float *)(iStack_2ec + DAT_007372c4);
        }
        fStack_2f4 = SQRT((*pfStack_2e8 - *pfVar9) * (*pfStack_2e8 - *pfVar9) +
                          (pfStack_2e8[1] - pfVar9[1]) * (pfStack_2e8[1] - pfVar9[1]));
        if ((pfStack_300 == (float *)0x0) || (fStack_2f4 < fStack_2f8)) {
          iStack_34 = 0;
          uStack_30 = 0;
          uStack_2c = 0;
          uStack_28 = 0;
          uStack_20 = 0;
          uStack_1c = 0;
          uStack_18 = 0;
          FUN_00440740();
          fStack_2e4 = *pfVar9;
          fStack_2e0 = pfVar9[1];
          uStack_2dc = 0x47c34f8d;
          GroundQuery__FindSurfaceBelow(auStack_2d4,&fStack_2e4,0,0,(int)&local_2fc + 3);
          if (local_2fc._3_1_ != '\0') {
            fStack_2f8 = fStack_2f4;
            pfStack_300 = pfVar9;
          }
          iVar4 = 0;
          if (0 < iStack_34) {
            do {
              piVar3 = aiStack_2b4 + iVar4;
              iVar4 = iVar4 + 1;
              *(char *)(*piVar3 + 8) = *(char *)(*piVar3 + 8) + -1;
            } while (iVar4 < iStack_34);
          }
        }
        local_2f0 = local_2f0 + 1;
        iStack_2ec = iStack_2ec + 0x14;
        pfVar9 = pfStack_300;
      } while (local_2f0 < DAT_007372c0);
    }
    fStack_2e4 = *pfVar9;
    fStack_2e0 = pfVar9[1];
    uStack_2dc = 0;
    uVar7 = Atan2ToAngle16(*(undefined4 *)(iVar2 + 0x818),*(undefined4 *)(iVar2 + 0x81c));
    FUN_00427c50(&fStack_2e4,0,uVar7);
    TrackPath__UpdateCursor(&DAT_007372b0,iVar2 + 0x60);
    (**(code **)(**(int **)(iVar2 + 0x2c) + 0x2c))(1);
    (**(code **)(**(int **)(iVar2 + 0x2c) + 0x30))();
    *(undefined4 *)(iVar2 + 0x884) = DAT_0073ad34;
    *(undefined4 *)(iVar2 + 0x888) = 0x40000000;
    return;
  }
  (**(code **)(**(int **)(iVar2 + 0x2c) + 0x14))(1);
  iVar4 = (**(code **)(**(int **)(iVar2 + 0x2c) + 0x18))(1);
  (**(code **)(**(int **)(iVar2 + 0x2c) + 0x1c))(1);
  fStack_304 = 0.0;
  if ((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) {
    iVar5 = (**(code **)(**(int **)(iVar2 + 0x2c) + 0x40))();
    iVar6 = GetNearestTrafficLane(iVar2,iVar5,0xff,0xff);
    if (iVar5 == 1) {
      if (iVar6 < 5) {
        iVar6 = iVar6 + 5;
      }
      else if ((10 < iVar6) && (iVar6 < 0x11)) {
        iVar6 = iVar6 + 6;
      }
    }
    if ((iVar4 != 0) && (iVar6 != -1)) {
      fVar10 = (float10)FUN_00442590();
      fStack_304 = (float)fVar10;
    }
  }
  piVar3 = *(int **)(iVar2 + 0x2c);
  uVar7 = (**(code **)(*piVar3 + 0x14))(1);
  uVar14 = 0;
  uVar13 = 1;
  uVar12 = 1;
  uVar11 = 1;
  uVar8 = (**(code **)(*piVar3 + 0x18))(1,unaff_EDI,1,fStack_304,1,0,unaff_EBX);
  FUN_00427f70(iVar2,uVar7,uVar8,uVar11,unaff_EDI,uVar12,fStack_304,uVar13,uVar14);
  return;
}


// ==== 0x431810 FUN_00431810

void FUN_00431810(void)

{
  undefined4 *puVar1;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 4) = 0;
  *(undefined4 *)(unaff_ESI + 8) = 0;
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
  *(undefined4 **)(unaff_ESI + 0xc) = puVar1;
  puVar1 = _malloc(0x30);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[9] = 0x3f800000;
    puVar1[10] = 0x3f800000;
    *(undefined2 *)(puVar1 + 0xb) = 0;
    *(undefined2 *)((int)puVar1 + 0x2e) = 1;
    *(undefined4 *)(unaff_ESI + 0x14) = 0;
    *(undefined4 *)(unaff_ESI + 0x18) = 0;
    *(undefined4 **)(unaff_ESI + 0x10) = puVar1;
    *(undefined4 *)(unaff_ESI + 0x1c) = 0x3f800000;
    *(undefined4 *)(unaff_ESI + 0x20) = 0x3f800000;
    return;
  }
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined4 *)(unaff_ESI + 0x18) = 0;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *(undefined4 *)(unaff_ESI + 0x1c) = 0x3f800000;
  *(undefined4 *)(unaff_ESI + 0x20) = 0x3f800000;
  return;
}


// ==== 0x4318b0 FUN_004318b0

void FUN_004318b0(void)

{
  int unaff_ESI;
  
  _free(*(void **)(unaff_ESI + 0xc));
  _free(*(void **)(unaff_ESI + 0x10));
  return;
}


// ==== 0x4318d0 FUN_004318d0

undefined4 FUN_004318d0(void)

{
  char cVar1;
  int in_EAX;
  
  if ((*(int *)(in_EAX + 4) != 0) && (*(int *)(in_EAX + 4) != -0x40)) {
    cVar1 = CarState__IsNitrousOn();
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== 0x431900 FUN_00431900

undefined4 FUN_00431900(void)

{
  char cVar1;
  int in_EAX;
  
  if ((*(int *)(in_EAX + 4) != 0) && (*(int *)(in_EAX + 4) != -0x40)) {
    cVar1 = FUN_00465490();
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== 0x431920 Player::StartHonkHorn

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void Player__StartHonkHorn(void)

{
  int *piVar1;
  int in_EAX;
  
  if ((*(int *)(*(int *)(*(int *)(in_EAX + 4) + 0xc) + 0xc54) != 1) &&
     (piVar1 = *(int **)(*(int *)(in_EAX + 4) + 0x878), piVar1 != (int *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0043193b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 0x48))();
    return;
  }
  return;
}


// ==== 0x431940 Player::StopHonkHorn

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void Player__StopHonkHorn(void)

{
  int *piVar1;
  int in_EAX;
  
  if ((*(int *)(*(int *)(*(int *)(in_EAX + 4) + 0xc) + 0xc54) != 1) &&
     (piVar1 = *(int **)(*(int *)(in_EAX + 4) + 0x878), piVar1 != (int *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0043195b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 0x4c))();
    return;
  }
  return;
}


// ==== 0x431960 SpecialCamCaller_431960

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera I (C) docs/re/camera.md */

void __thiscall SpecialCamCaller_431960(int param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  undefined4 in_EAX;
  int *piVar5;
  
  switch(in_EAX) {
  case 0x75:
    cVar3 = Player__IsDriftHudActive();
    if (cVar3 != '\0') {
      *(byte *)(param_1 + 0x124) = *(byte *)(param_1 + 0x124) ^ 1;
      return;
    }
    if ((((_K_ONE < (float)(DAT_0073ad3c - *(int *)(param_1 + 0xa0)) * 0.00025) &&
         ((*(int *)(param_1 + 0x278) == 2 || (*(int *)(param_1 + 0x278) == 3)))) &&
        (*(int *)(param_1 + 0x27c) != 0)) && (*(int *)(*(int *)(param_1 + 0x27c) + 0x14) != 0)) {
      uVar4 = Player__CyclePOV();
      *(undefined1 *)(param_1 + 0x24) = uVar4;
      return;
    }
    break;
  case 0x76:
    *(bool *)(param_1 + 0x4ad) = param_3 != '\0';
    if (DAT_007361fc == 0) {
      *(undefined4 *)(param_1 + 0x70) = DAT_0073ad34;
    }
    piVar5 = *(int **)(param_1 + 0x27c);
    if (((piVar5 != (int *)0x0) && (cVar3 = FUN_0042add0(), cVar3 != '\0')) ||
       ((piVar5 = *(int **)(param_1 + 0x280), piVar5 != (int *)0x0 &&
        (cVar3 = FUN_0042add0(), cVar3 != '\0')))) {
      (**(code **)(*piVar5 + 0x14))(*(undefined1 *)(param_1 + 0x4ad));
      return;
    }
    break;
  case 0x77:
    Player__StartSpecialCamera(1,1,1,1);
    return;
  case 0x78:
    Player__StartSpecialCamera(2,1,1,1);
    return;
  case 0x79:
    Player__StartSpecialCamera(3,1,1,1);
    return;
  case 0x99:
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x30);
    if ((param_3 != '\0') &&
       ((((*(int *)(*(int *)(param_1 + 4) + 0x24) != 1 || (iVar1 == 0)) ||
         (*(int *)(iVar1 + 0x278) == 0)) && (cVar3 = Player__IsAllowedToReset(), cVar3 != '\0')))) {
      Player__ResetToRoute();
      return;
    }
    break;
  case 0x9a:
    iVar1 = *(int *)(param_1 + 4);
    iVar2 = *(int *)(iVar1 + 0xc);
    if (param_3 == '\0') {
      Player__StopHonkHorn();
      if (*(int *)(iVar2 + 0xc54) != 1) {
        *(undefined1 *)(iVar1 + 0x855) = 0;
        return;
      }
    }
    else {
      Player__StartHonkHorn();
      if (*(int *)(iVar2 + 0xc54) != 1) {
        *(undefined1 *)(iVar1 + 0x855) = 1;
        return;
      }
      if (DAT_0078a368 == 0) {
        if (*(int *)(iVar1 + 0x834) != 0) {
          *(undefined4 *)(iVar1 + 0x858) = 0;
          *(undefined4 *)(iVar1 + 0x834) = 0;
          return;
        }
        *(undefined4 *)(iVar1 + 0x858) = 1;
        *(undefined4 *)(iVar1 + 0x834) = 2;
        return;
      }
    }
    break;
  case 0x9b:
  case 0x9c:
    cVar3 = IsDriftMode();
    if ((cVar3 == '\0') && (cVar3 = Player__IsDriftHudActive(), cVar3 == '\0')) {
      if (param_3 == '\0') {
        cVar3 = FUN_004318d0();
        if ((cVar3 != '\0') && (DAT_007000e8 != 0)) {
          CarState__StopNitrous();
        }
      }
      else {
        cVar3 = FUN_00431900();
        if ((cVar3 != '\0') && (cVar3 = FUN_004654f0(), cVar3 != '\0')) {
          if (*DAT_0073619c < 4) {
            FUN_0042abf0();
          }
          else {
            _gSpecialCameraActive = 1;
            *(undefined1 *)(param_1 + 0x270) = 1;
          }
          if (*(char *)(param_1 + 0x21) != '\0') {
            FUN_00574d90(0x3f800000);
            return;
          }
        }
      }
    }
    break;
  case 0x9d:
    *(int *)(param_1 + 0xa0) = DAT_0073ad3c;
    return;
  case 0x9e:
    *(int *)(param_1 + 0xa0) = DAT_0073ad3c;
    return;
  case 0xa3:
    *(byte *)(param_1 + 0x4ae) = *(byte *)(param_1 + 0x4ae) ^ 1;
    return;
  case 0xaa:
    if (*(int *)(param_1 + 0x4c) != 0) {
      Player__LookBackToggle(param_1,1);
      return;
    }
    break;
  case 0xab:
    cVar3 = FUN_004318d0();
    if (cVar3 != '\0') {
      CarState__StopNitrous();
    }
    FUN_00421c00(DAT_007361f0,5,param_2);
    return;
  }
  return;
}


// ==== 0x4319b4 caseD_75

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void switchD_0043197d::caseD_75(void)

{
  char cVar1;
  undefined1 uVar2;
  int unaff_ESI;
  
  cVar1 = Player__IsDriftHudActive();
  if (cVar1 != '\0') {
    *(byte *)(unaff_ESI + 0x124) = *(byte *)(unaff_ESI + 0x124) ^ 1;
    return;
  }
  if (((_K_ONE < (float)(DAT_0073ad3c - *(int *)(unaff_ESI + 0xa0)) * 0.00025) &&
      (((*(int *)(unaff_ESI + 0x278) == 2 || (*(int *)(unaff_ESI + 0x278) == 3)) &&
       (*(int *)(unaff_ESI + 0x27c) != 0)))) && (*(int *)(*(int *)(unaff_ESI + 0x27c) + 0x14) != 0))
  {
    uVar2 = Player__CyclePOV();
    *(undefined1 *)(unaff_ESI + 0x24) = uVar2;
    return;
  }
  return;
}


// ==== 0x431c0f caseD_9b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void switchD_0043197d::caseD_9b(void)

{
  char cVar1;
  char unaff_BL;
  int unaff_ESI;
  
  cVar1 = IsDriftMode();
  if (cVar1 == '\0') {
    cVar1 = Player__IsDriftHudActive();
    if (cVar1 == '\0') {
      if (unaff_BL == '\0') {
        cVar1 = FUN_004318d0();
        if ((cVar1 != '\0') && (DAT_007000e8 != 0)) {
          CarState__StopNitrous();
        }
      }
      else {
        cVar1 = FUN_00431900();
        if (cVar1 != '\0') {
          cVar1 = FUN_004654f0();
          if (cVar1 != '\0') {
            if (*DAT_0073619c < 4) {
              FUN_0042abf0();
            }
            else {
              _gSpecialCameraActive = 1;
              *(undefined1 *)(unaff_ESI + 0x270) = 1;
            }
            if (*(char *)(unaff_ESI + 0x21) != '\0') {
              FUN_00574d90(0x3f800000);
              return;
            }
          }
        }
      }
    }
  }
  return;
}


// ==== 0x431d30 FUN_00431d30

int FUN_00431d30(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_0043a2e0();
  if (cVar1 != '\0') {
    return DAT_0077b244 + 0x19;
  }
  return param_1 + 0x34;
}


// ==== 0x431d60 LinearTable::CopyFrom

/* [canon] runtime med (ghidra-canon) docs/re/canon.md */

void __fastcall LinearTable__CopyFrom(int param_1)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float local_14 [5];
  
  iVar2 = 0x3f;
  puVar1 = in_EAX;
  do {
    *puVar1 = *(undefined4 *)((param_1 - (int)in_EAX) + (int)puVar1);
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  local_14[1] = *(float *)(param_1 + 0x104);
  local_14[2] = *(float *)(param_1 + 0x108);
  local_14[0] = 8.96831e-44;
  local_14[3] = 63.0 / (*(float *)(param_1 + 0x108) - *(float *)(param_1 + 0x104));
  pfVar3 = local_14;
  pfVar4 = (float *)(in_EAX + 0x40);
  for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar4 = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pfVar4 = pfVar4 + 1;
  }
  return;
}


// ==== 0x431dd0 DriverInfo::InitDefault

/* [canon] rivals med (ghidra-canon) docs/re/rivals.md */

undefined1 * __fastcall DriverInfo__InitDefault(undefined1 *param_1)

{
  *param_1 = 0;
  RideInfo__Init();
  param_1[0x734] = 0;
  return param_1;
}


// ==== 0x431df0 FUN_00431df0

void FUN_00431df0(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *unaff_ESI;
  undefined4 *puVar4;
  
  puVar4 = unaff_ESI;
  for (iVar3 = 0x4e; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  unaff_ESI[2] = 3;
  unaff_ESI[4] = 3;
  unaff_ESI[0xc] = 1;
  unaff_ESI[0x12] = 1;
  unaff_ESI[0x19] = 1;
  unaff_ESI[0x1a] = 1;
  unaff_ESI[0x1b] = 1;
  unaff_ESI[0x1c] = 1;
  unaff_ESI[0x1d] = 1;
  unaff_ESI[0x1f] = 1;
  unaff_ESI[0x44] = 1;
  unaff_ESI[0x45] = 0x3f800000;
  unaff_ESI[0x46] = 0x3f800000;
  unaff_ESI[0xb] = 2;
  unaff_ESI[0x20] = 2;
  *unaff_ESI = 0xb;
  unaff_ESI[1] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[5] = 0x3f000000;
  *(undefined1 *)(unaff_ESI + 6) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x19) = 0;
  unaff_ESI[7] = 0;
  unaff_ESI[0xd] = 7;
  unaff_ESI[0xe] = 0;
  unaff_ESI[0xf] = 0;
  unaff_ESI[0x10] = 0;
  *(undefined1 *)((int)unaff_ESI + 0x46) = 0;
  *(undefined1 *)(unaff_ESI + 0x13) = 0;
  unaff_ESI[0x14] = 0;
  *(undefined1 *)(unaff_ESI + 0x11) = 7;
  *(undefined1 *)((int)unaff_ESI + 0x45) = 8;
  unaff_ESI[0x18] = 0;
  unaff_ESI[0x1e] = 0;
  unaff_ESI[0x23] = 0;
  unaff_ESI[0x43] = 0;
  puVar4 = (undefined4 *)&DAT_0077c790;
  for (iVar3 = 0x36d8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  unaff_ESI[0x48] = 0xffffffff;
  unaff_ESI[0x49] = 0xffffffff;
  unaff_ESI[0x16] = 0xffffffff;
  unaff_ESI[0x17] = 0xffffffff;
  unaff_ESI[0x4a] = &DAT_0077c790;
  unaff_ESI[0x4b] = 0;
  RaceParameters__InitDriverSlot();
  RaceParameters__InitDriverSlot();
  unaff_ESI[10] = 0;
  cPlayerSettings__ResetToDefaults();
  *(undefined1 *)((int)unaff_ESI + 0x47) = 0;
  uVar1 = DAT_006f227c ^ 0x1d872b41;
  uVar2 = uVar1 >> 5 ^ uVar1;
  uVar1 = uVar2 << 0x1b ^ uVar2 ^ uVar1;
  unaff_ESI[0x4c] = DAT_006f227c;
  DAT_006f227c = uVar1;
  unaff_ESI[0x4d] = 0;
  unaff_ESI[9] = 0;
  unaff_ESI[0x24] = 0x3f800000;
  unaff_ESI[0x47] = 2;
  return;
}


// ==== 0x431f40 FUN_00431f40

void FUN_00431f40(int param_1)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  char cVar3;
  int local_4;
  
  FUN_00571ea0(0,"RaceParameters");
  FUN_00571c20(in_EAX,param_1,2,4,0);
  FUN_00571c20(in_EAX,param_1 + 4,1,4,1);
  FUN_00571c20(in_EAX,param_1 + 8,1,4,1);
  FUN_00571c20(in_EAX,param_1 + 0xc,1,4,1);
  FUN_00571c20(in_EAX,param_1 + 0x10,1,4,1);
  FUN_00571c20(in_EAX,param_1 + 0x14,4,0xffffffff,0);
  FUN_00571c20(in_EAX,param_1 + 0x1c,1,4,1);
  FUN_00571c20(in_EAX,param_1 + 0x20,4,0xffffffff,0);
  FUN_00571c20(in_EAX,param_1 + 0x24,4,0xffffffff,0);
  FUN_00571c20(in_EAX,param_1 + 0x28,1,4,0);
  FUN_00571c20(in_EAX,param_1 + 0x2c,1,4,0);
  FUN_00571c20(in_EAX,param_1 + 0x30,1,4,0);
  FUN_00571c20(in_EAX,param_1 + 0x34,1,4,0);
  FUN_00571c20(in_EAX,param_1 + 0x38,1,4,0);
  FUN_00571c20(in_EAX,param_1 + 0x3c,1,4,0);
  FUN_00571c20(in_EAX,param_1 + 0x40,1,4,1);
  FUN_00571c20(in_EAX,param_1 + 0x44,1,1,1);
  FUN_00571c20(in_EAX,param_1 + 0x45,1,1,1);
  FUN_00571c20(in_EAX,param_1 + 0x46,1,1,0);
  FUN_00571c20(in_EAX,param_1 + 0x10a,1,1,1);
  FUN_00571c20(in_EAX,param_1 + 0x10b,1,1,1);
  FUN_00571c20(in_EAX,param_1 + 0x47,1,1,0);
  FUN_00571c20(in_EAX,param_1 + 0x14,4,0xffffffff,0);
  FUN_00571c20(in_EAX,param_1 + 0x48,1,4,1);
  FUN_00571c20(in_EAX,param_1 + 0x60,1,4,0);
  FUN_00571c20(in_EAX,param_1 + 100,1,4,0);
  FUN_00571c20(in_EAX,param_1 + 0x68,1,4,0);
  FUN_00571c20(in_EAX,param_1 + 0x6c,1,4,0);
  FUN_00571c20(in_EAX,param_1 + 0x70,1,4,0);
  FUN_00571c20(in_EAX,param_1 + 0x74,1,4,0);
  FUN_00571c20(in_EAX,param_1 + 0x78,1,4,0);
  FUN_00571c20(in_EAX,param_1 + 0x7c,1,4,0);
  FUN_00571c20(in_EAX,param_1 + 0x80,1,4,0);
  FUN_00571c20(in_EAX,param_1 + 0x84,1,4,0);
  FUN_00571c20(in_EAX,param_1 + 0x88,1,4,0);
  FUN_00571c20(in_EAX,param_1 + 0x8c,1,4,1);
  FUN_00432910();
  FUN_00432910();
  FUN_00571c20(in_EAX,param_1 + 0x10c,1,4,1);
  FUN_00571c20(in_EAX,param_1 + 0x110,1,4,0);
  FUN_00571c20(in_EAX,param_1 + 0x114,4,0xffffffff,0);
  FUN_00571c20(in_EAX,param_1 + 0x118,4,0xffffffff,0);
  piVar1 = (int *)(param_1 + 300);
  FUN_00571c20(in_EAX,piVar1,4,4,1);
  local_4 = 0;
  if (0 < *piVar1) {
    do {
      FUN_00580a40();
      local_4 = local_4 + 1;
    } while (local_4 < *piVar1);
  }
  iVar2 = *(char *)(in_EAX + 0x40) * 0x10;
  *(int *)(iVar2 + in_EAX + 0x58) = *(int *)(in_EAX + 0x150) - *(int *)(iVar2 + 0x58 + in_EAX);
  cVar3 = *(char *)(in_EAX + 0x40) + -1;
  *(char *)(in_EAX + 0x40) = cVar3;
  if ((int)cVar3 < *(int *)(in_EAX + 0x44)) {
    *(undefined4 *)(in_EAX + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x4322a0 RaceStatus::AddEntrant

/* [canon] rivals V (Ghidra+Hopper) docs/re/rivals.md */

void RaceStatus__AddEntrant(int param_1)

{
  int iVar1;
  int *piVar2;
  int unaff_EDI;
  
  if ((*(int *)(unaff_EDI + 4) == 1) && (*(char *)(unaff_EDI + 0x734) == '\0')) {
    iVar1 = 0;
    piVar2 = (int *)(param_1 + 0x120);
    do {
      if (iVar1 == 2) break;
      if (*piVar2 == -1) {
        *(int *)(param_1 + 0x120 + iVar1 * 4) = (int)*(char *)(unaff_EDI + 1);
        break;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < 3);
  }
  if (*(int *)(param_1 + 300) < 0x1e) {
    iVar1 = 0;
    if (0 < DAT_00734594) {
      piVar2 = DAT_00734590;
      do {
        if ((*piVar2 == *(int *)(unaff_EDI + 0x10)) &&
           (piVar2[1] == (int)*(char *)(unaff_EDI + 0x17))) break;
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 0x10;
      } while (iVar1 < DAT_00734594);
    }
    DriverInfo__operator_();
    *(int *)(param_1 + 300) = *(int *)(param_1 + 300) + 1;
    if (*(char *)(unaff_EDI + 0x734) != '\0') {
      if (*(int *)(unaff_EDI + 4) == 1) {
        *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
        return;
      }
      if (*(int *)(unaff_EDI + 4) == 2) {
        *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
      }
    }
  }
  return;
}


// ==== 0x432360 DriverInfo::operator_

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void DriverInfo__operator_(void)

{
  undefined1 *in_EAX;
  undefined1 *puVar1;
  int iVar2;
  undefined1 *unaff_ESI;
  
  *unaff_ESI = *in_EAX;
  unaff_ESI[1] = in_EAX[1];
  unaff_ESI[2] = in_EAX[2];
  unaff_ESI[3] = in_EAX[3];
  *(undefined4 *)(unaff_ESI + 4) = *(undefined4 *)(in_EAX + 4);
  RideInfo__operator_(unaff_ESI + 0x10,in_EAX + 0x10);
  *(undefined4 *)(unaff_ESI + 0x730) = *(undefined4 *)(in_EAX + 0x730);
  unaff_ESI[0x734] = in_EAX[0x734];
  unaff_ESI[0x735] = in_EAX[0x735];
  unaff_ESI[0x736] = in_EAX[0x736];
  *(undefined4 *)(unaff_ESI + 0x738) = *(undefined4 *)(in_EAX + 0x738);
  puVar1 = unaff_ESI + 0x73c;
  iVar2 = 0x10;
  do {
    *puVar1 = puVar1[(int)in_EAX - (int)unaff_ESI];
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== 0x4323f0 RideInfo::operator_

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 * RideInfo__operator_(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  *param_1 = *param_2;
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)(param_2 + 1);
  *(undefined1 *)((int)param_1 + 5) = *(undefined1 *)((int)param_2 + 5);
  *(undefined1 *)((int)param_1 + 6) = *(undefined1 *)((int)param_2 + 6);
  *(undefined1 *)((int)param_1 + 7) = *(undefined1 *)((int)param_2 + 7);
  puVar3 = param_2 + 2;
  puVar4 = param_1 + 2;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  CarPhysicsInfo__operator_(param_1 + 0x18,param_2 + 0x18);
  LinearTable__CopyFrom();
  *(undefined1 *)(param_1 + 0x109) = *(undefined1 *)(param_2 + 0x109);
  *(undefined1 *)((int)param_1 + 0x425) = *(undefined1 *)((int)param_2 + 0x425);
  *(undefined1 *)((int)param_1 + 0x426) = *(undefined1 *)((int)param_2 + 0x426);
  *(undefined1 *)((int)param_1 + 0x427) = *(undefined1 *)((int)param_2 + 0x427);
  param_1[0x10a] = param_2[0x10a];
  param_1[0x10b] = param_2[0x10b];
  param_1[0x10c] = param_2[0x10c];
  param_1[0x10d] = param_2[0x10d];
  param_1[0x10e] = param_2[0x10e];
  param_1[0x10f] = param_2[0x10f];
  param_1[0x110] = param_2[0x110];
  param_1[0x111] = param_2[0x111];
  param_1[0x112] = param_2[0x112];
  puVar3 = param_1 + 0x113;
  iVar1 = (int)param_2 - (int)param_1;
  iVar2 = 0x78;
  do {
    *puVar3 = *(undefined4 *)(iVar1 + (int)puVar3);
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar3 = param_1 + 0x18b;
  iVar2 = 0x78;
  do {
    *(undefined1 *)puVar3 = *(undefined1 *)((int)puVar3 + iVar1);
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar3 = param_1 + 0x1a9;
  iVar2 = 0x78;
  do {
    *(undefined1 *)puVar3 = *(undefined1 *)((int)puVar3 + iVar1);
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1[0x1c7] = param_2[0x1c7];
  return param_1;
}


// ==== 0x432540 CarPhysicsInfo::operator_

/* [canon] car med (ghidra-canon) docs/re/canon.md */

undefined4 * CarPhysicsInfo__operator_(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  uVar2 = *param_2;
  uVar1 = param_2[2];
  param_1[1] = param_2[1];
  *param_1 = uVar2;
  param_1[2] = uVar1;
  iVar5 = 4;
  puVar3 = param_2 + 6;
  puVar4 = param_1 + 8;
  do {
    uVar1 = puVar3[-1];
    uVar2 = *puVar3;
    iVar5 = iVar5 + -1;
    puVar4[-4] = puVar3[-2];
    puVar4[-3] = uVar1;
    *(undefined4 *)((int)param_1 + (-0x30 - (int)param_2) + (int)(puVar3 + 0xc)) = uVar2;
    *puVar4 = puVar3[2];
    puVar4[1] = puVar3[3];
    puVar4[2] = puVar3[4];
    puVar4[3] = puVar3[5];
    puVar4[4] = puVar3[6];
    puVar4[5] = puVar3[7];
    puVar4[6] = puVar3[8];
    puVar4[7] = puVar3[9];
    puVar3 = puVar3 + 0xc;
    puVar4 = puVar4 + 0xc;
  } while (iVar5 != 0);
  puVar3 = param_2 + 0x34;
  puVar4 = param_1 + 0x34;
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar3 = param_2 + 0x3c;
  puVar4 = param_1 + 0x3c;
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  param_1[0x44] = param_2[0x44];
  param_1[0x45] = param_2[0x45];
  param_1[0x46] = param_2[0x46];
  param_1[0x47] = param_2[0x47];
  bMatrixCopy_b();
  param_1[0x58] = param_2[0x58];
  param_1[0x59] = param_2[0x59];
  param_1[0x5a] = param_2[0x5a];
  param_1[0x5b] = param_2[0x5b];
  puVar3 = param_2 + 0x5c;
  puVar4 = param_1 + 0x5c;
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar3 = param_2 + 100;
  puVar4 = param_1 + 100;
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar3 = param_2 + 0x6c;
  puVar4 = param_1 + 0x6c;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar3 = param_2 + 0x7c;
  puVar4 = param_1 + 0x7c;
  for (iVar5 = 0x1c; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  param_1[0x98] = param_2[0x98];
  param_1[0x99] = param_2[0x99];
  param_1[0x9a] = param_2[0x9a];
  param_1[0x9b] = param_2[0x9b];
  puVar3 = param_2 + 0x9c;
  puVar4 = param_1 + 0x9c;
  for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  param_1[0xa8] = param_2[0xa8];
  param_1[0xa9] = param_2[0xa9];
  param_1[0xaa] = param_2[0xaa];
  param_1[0xab] = param_2[0xab];
  return param_1;
}


// ==== 0x432710 RaceStatus::RemoveEntrant

/* [canon] rivals med (ghidra-canon) docs/re/rivals.md */

void RaceStatus__RemoveEntrant(int param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int unaff_EDI;
  undefined4 local_4;
  
  iVar3 = 0;
  bVar2 = false;
  if (0 < *(int *)(unaff_EDI + 300)) {
    local_4 = 0;
    do {
      iVar1 = *(int *)(unaff_EDI + 0x128) + local_4;
      if (*(char *)(*(int *)(unaff_EDI + 0x128) + 1 + local_4) == param_1) {
        if (*(char *)(iVar1 + 0x734) != '\0') {
          iVar1 = *(int *)(iVar1 + 4);
          if (iVar1 == 1) {
            *(int *)(unaff_EDI + 0x38) = *(int *)(unaff_EDI + 0x38) + -1;
            *(int *)(unaff_EDI + 300) = *(int *)(unaff_EDI + 300) + -1;
            bVar2 = true;
            goto LAB_0043277d;
          }
          if (iVar1 == 2) {
            *(int *)(unaff_EDI + 0x3c) = *(int *)(unaff_EDI + 0x3c) + -1;
          }
        }
        *(int *)(unaff_EDI + 300) = *(int *)(unaff_EDI + 300) + -1;
        bVar2 = true;
LAB_0043277d:
        if (iVar3 < *(int *)(unaff_EDI + 300) + -1) {
          DriverInfo__operator_();
        }
      }
      else if (bVar2) goto LAB_0043277d;
      iVar3 = iVar3 + 1;
      local_4 = local_4 + 0x750;
    } while (iVar3 < *(int *)(unaff_EDI + 300));
  }
  return;
}


// ==== 0x4327c0 RaceStatus::GetEntrantAt

/* [canon] rivals med (ghidra-canon) docs/re/rivals.md */

int __fastcall RaceStatus__GetEntrantAt(int param_1)

{
  int in_EAX;
  
  return in_EAX * 0x750 + *(int *)(param_1 + 0x128);
}


// ==== 0x4327d0 RaceStatus::FindEntrantById

/* [canon] rivals med (ghidra-canon) docs/re/rivals.md */

int __fastcall RaceStatus__FindEntrantById(int param_1)

{
  int iVar1;
  char *pcVar2;
  int unaff_EDI;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 300)) {
    pcVar2 = (char *)(*(int *)(param_1 + 0x128) + 1);
    do {
      if (unaff_EDI == *pcVar2) {
        return iVar1 * 0x750 + *(int *)(param_1 + 0x128);
      }
      iVar1 = iVar1 + 1;
      pcVar2 = pcVar2 + 0x750;
    } while (iVar1 < *(int *)(param_1 + 300));
  }
  return 0;
}


// ==== 0x432810 FUN_00432810

undefined4 __fastcall FUN_00432810(int param_1)

{
  int in_EAX;
  undefined4 uVar1;
  
  if (-1 < *(int *)(param_1 + 0x120 + in_EAX * 4)) {
    uVar1 = RaceStatus__FindEntrantById();
    return uVar1;
  }
  return 0;
}


// ==== 0x432830 FUN_00432830

undefined4 __fastcall FUN_00432830(int param_1)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x120 + param_1 * 4);
}


// ==== 0x432890 RaceParameters::InitDriverSlot

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] rivals med (ghidra-canon) docs/re/canon.md */

void RaceParameters__InitDriverSlot(void)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  undefined1 *in_EAX;
  char *pcVar4;
  bool bVar5;
  
  uVar3 = _DAT_00734670;
  bVar5 = DAT_0073465c == 0;
  *in_EAX = 0;
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[4] = bVar5 - 1U & (byte)uVar3;
  pcVar1 = in_EAX + 0x14;
  in_EAX[3] = 0;
  in_EAX[5] = 0;
  in_EAX[6] = 0;
  in_EAX[7] = 0;
  in_EAX[8] = 0;
  in_EAX[9] = 1;
  in_EAX[10] = 0;
  *(undefined4 *)(in_EAX + 0x10) = 0x755;
  *pcVar1 = 'P';
  pcVar4 = pcVar1;
  do {
    cVar2 = pcVar4[(int)("PLAYER" + (1 - (int)pcVar1))];
    pcVar4 = pcVar4 + 1;
    *pcVar4 = cVar2;
  } while (cVar2 != '\0');
  *(undefined4 *)(in_EAX + 0x24) = 0;
  *(undefined4 *)(in_EAX + 0x28) = 0;
  *(undefined4 *)(in_EAX + 0x2c) = 1;
  *(undefined4 *)(in_EAX + 0x30) = 1;
  *(undefined4 *)(in_EAX + 0x34) = 0;
  return;
}


// ==== 0x432910 FUN_00432910

void FUN_00432910(void)

{
  int in_EAX;
  int iVar1;
  char cVar2;
  int unaff_ESI;
  
  FUN_00571ea0(0,"cPlayerSettings");
  FUN_00571c20(unaff_ESI,in_EAX + 2,1,1,1);
  FUN_00571c20(unaff_ESI,in_EAX + 3,1,1,1);
  FUN_00571c20(unaff_ESI,in_EAX + 7,1,1,1);
  FUN_00571c20(unaff_ESI,in_EAX + 10,1,1,1);
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


// ==== 0x4329a0 cPlayerSettings::ResetToDefaults

/* [canon] hud med (ghidra-canon) docs/re/canon.md */

void cPlayerSettings__ResetToDefaults(void)

{
  int iVar1;
  int iVar2;
  undefined1 *in_EAX;
  undefined1 uVar3;
  
  iVar2 = DAT_0073465c;
  iVar1 = DAT_006ee6f0;
  uVar3 = (undefined1)DAT_006f1d74;
  if (DAT_0073465c == 0) {
    uVar3 = 1;
  }
  *in_EAX = uVar3;
  uVar3 = iVar1 != 0;
  if (iVar2 != 0) {
    uVar3 = (undefined1)DAT_006f1d80;
  }
  in_EAX[1] = uVar3;
  uVar3 = (undefined1)DAT_006f1d88;
  in_EAX[2] = 0;
  in_EAX[3] = 7;
  in_EAX[4] = 8;
  in_EAX[5] = 2;
  if (iVar2 == 0) {
    uVar3 = 0x80;
  }
  in_EAX[6] = uVar3;
  uVar3 = (undefined1)DAT_006f1d8c;
  if (iVar2 == 0) {
    uVar3 = 0x80;
  }
  in_EAX[7] = uVar3;
  return;
}


// ==== 0x432a10 Player::IsPlainType1

/* [canon] hud med (ghidra-canon+hopper) docs/re/canon.md */

undefined4 Player__IsPlainType1(void)

{
  int in_EAX;
  
  if (((*(int *)(in_EAX + 0x1c) == 1) && (*(int *)(in_EAX + 0x2c) == 0)) &&
     (*(int *)(in_EAX + 0x78) == 0)) {
    return 1;
  }
  return 0;
}


// ==== 0x432a30 HudTach_PickFaceHashes

/* [canon] hud med (ghidra-canon) docs/re/canon.md */

void HudTach_PickFaceHashes(undefined4 param_1,undefined4 param_2,int *param_3)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined *puVar6;
  int unaff_EDI;
  
  if (((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) || (DAT_0078a320 != 1)) {
    pcVar5 = "3RDPERSON_";
    iVar3 = -1;
    uVar2 = 0x33;
    do {
      iVar3 = iVar3 * 0x21 + uVar2;
      pbVar1 = (byte *)(pcVar5 + 1);
      uVar2 = (uint)*pbVar1;
      pcVar5 = pcVar5 + 1;
    } while (*pbVar1 != 0);
  }
  else {
    pcVar5 = "3RDPERSONDRAG_";
    iVar3 = -1;
    uVar2 = 0x33;
    do {
      iVar3 = iVar3 * 0x21 + uVar2;
      pbVar1 = (byte *)(pcVar5 + 1);
      uVar2 = (uint)*pbVar1;
      pcVar5 = pcVar5 + 1;
    } while (*pbVar1 != 0);
  }
  if (9500.0 <= *(float *)(unaff_EDI + 8)) {
    pcVar5 = "10500LINES";
    uVar2 = 0x31;
    iVar4 = iVar3;
    do {
      iVar4 = iVar4 * 0x21 + uVar2;
      pbVar1 = (byte *)(pcVar5 + 1);
      uVar2 = (uint)*pbVar1;
      pcVar5 = pcVar5 + 1;
    } while (*pbVar1 != 0);
    *param_3 = iVar4;
    if (9000.0 <= *(float *)(unaff_EDI + 4)) {
      puVar6 = &DAT_006ca6f8;
      uVar2 = 0x39;
      do {
        iVar3 = iVar3 * 0x21 + uVar2;
        pbVar1 = puVar6 + 1;
        uVar2 = (uint)*pbVar1;
        puVar6 = puVar6 + 1;
      } while (*pbVar1 != 0);
      param_3[1] = iVar3;
      return;
    }
    puVar6 = &DAT_006ca6f0;
    uVar2 = 0x38;
    do {
      iVar3 = iVar3 * 0x21 + uVar2;
      pbVar1 = puVar6 + 1;
      uVar2 = (uint)*pbVar1;
      puVar6 = puVar6 + 1;
    } while (*pbVar1 != 0);
    param_3[1] = iVar3;
    return;
  }
  if (8500.0 <= *(float *)(unaff_EDI + 8)) {
    pcVar5 = "9500LINES";
    uVar2 = 0x39;
    iVar4 = iVar3;
    do {
      iVar4 = iVar4 * 0x21 + uVar2;
      pbVar1 = (byte *)(pcVar5 + 1);
      uVar2 = (uint)*pbVar1;
      pcVar5 = pcVar5 + 1;
    } while (*pbVar1 != 0);
    *param_3 = iVar4;
    if (8000.0 <= *(float *)(unaff_EDI + 4)) {
      puVar6 = &DAT_006ca6dc;
      uVar2 = 0x38;
      do {
        iVar3 = iVar3 * 0x21 + uVar2;
        pbVar1 = puVar6 + 1;
        uVar2 = (uint)*pbVar1;
        puVar6 = puVar6 + 1;
      } while (*pbVar1 != 0);
      param_3[1] = iVar3;
      return;
    }
    puVar6 = &DAT_006ca6d4;
    uVar2 = 0x37;
    do {
      iVar3 = iVar3 * 0x21 + uVar2;
      pbVar1 = puVar6 + 1;
      uVar2 = (uint)*pbVar1;
      puVar6 = puVar6 + 1;
    } while (*pbVar1 != 0);
    param_3[1] = iVar3;
    return;
  }
  if (*(float *)(unaff_EDI + 8) < 7500.0) {
    pcVar5 = "7500LINES";
    uVar2 = 0x37;
    do {
      iVar3 = iVar3 * 0x21 + uVar2;
      pbVar1 = (byte *)(pcVar5 + 1);
      uVar2 = (uint)*pbVar1;
      pcVar5 = pcVar5 + 1;
    } while (*pbVar1 != 0);
    *param_3 = iVar3;
    iVar3 = bStringHashSeeded();
    param_3[1] = iVar3;
  }
  else {
    pcVar5 = "8500LINES";
    uVar2 = 0x38;
    do {
      iVar3 = iVar3 * 0x21 + uVar2;
      pbVar1 = (byte *)(pcVar5 + 1);
      uVar2 = (uint)*pbVar1;
      pcVar5 = pcVar5 + 1;
    } while (*pbVar1 != 0);
    *param_3 = iVar3;
    if (7000.0 <= *(float *)(unaff_EDI + 4)) {
      iVar3 = bStringHashSeeded();
      param_3[1] = iVar3;
      return;
    }
    if (6500.0 <= *(float *)(unaff_EDI + 4)) {
      iVar3 = bStringHashSeeded();
      param_3[1] = iVar3;
      return;
    }
  }
  return;
}


// ==== 0x432c50 FUN_00432c50

int FUN_00432c50(void)

{
  int in_EAX;
  
  return (int)*(char *)(in_EAX + 0xd);
}


// ==== 0x432c60 FUN_00432c60

int FUN_00432c60(void)

{
  int in_EAX;
  
  return (int)*(char *)(in_EAX + 0xe);
}


// ==== 0x432c70 FUN_00432c70

int FUN_00432c70(void)

{
  int in_EAX;
  
  return in_EAX + 0x1c;
}


// ==== 0x432c80 FUN_00432c80

float10 FUN_00432c80(void)

{
  int in_EAX;
  
  return (float10)*(float *)(in_EAX + 0x20);
}


// ==== 0x432c90 FUN_00432c90

float10 __fastcall FUN_00432c90(int param_1)

{
  if ((*(int *)(param_1 + 4) != 0) && (*(int *)(param_1 + 4) != 0x7fffffff)) {
    return (float10)(DAT_0073ad34 - *(int *)(param_1 + 4)) * (float10)0.00025;
  }
  return (float10)-1.0;
}


// ==== 0x432cc0 FUN_00432cc0

float10 __fastcall FUN_00432cc0(int param_1)

{
  if ((*(int *)(param_1 + 0x10) != 0) && (*(int *)(param_1 + 0x10) != 0x7fffffff)) {
    return (float10)((DAT_0078a314 - DAT_0073ad34) + *(int *)(param_1 + 0x10)) * (float10)0.00025;
  }
  return (float10)DAT_0078a314 * (float10)0.00025;
}


// ==== 0x432d00 FUN_00432d00

float10 FUN_00432d00(void)

{
  int in_EAX;
  
  return (float10)*(float *)(in_EAX + 0x540 + *(char *)(in_EAX + 0x53e) * 4);
}


// ==== 0x432d10 FUN_00432d10

float10 FUN_00432d10(void)

{
  int in_EAX;
  
  return (float10)*(float *)(in_EAX + 0x28);
}


// ==== 0x432d20 FUN_00432d20

float10 FUN_00432d20(float param_1)

{
  float *in_EAX;
  
  return (float10)param_1 * (float10)0.01 * (float10)*in_EAX;
}


// ==== 0x432d30 FUN_00432d30

void FUN_00432d30(undefined1 param_1)

{
  int in_EAX;
  
  *(undefined1 *)(in_EAX + 0x4d0) = param_1;
  return;
}


// ==== 0x432d40 FUN_00432d40

int FUN_00432d40(void)

{
  int in_EAX;
  
  return in_EAX + 0x960;
}


// ==== 0x432d50 FUN_00432d50

int FUN_00432d50(void)

{
  int in_EAX;
  
  return in_EAX + 0xa40;
}


// ==== 0x432d60 FUN_00432d60

void __fastcall FUN_00432d60(float *param_1,int param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *in_EAX;
  
  if (param_2 == 0) {
    fVar1 = in_EAX[4];
    fVar3 = -in_EAX[3] * param_4 + in_EAX[1];
    fVar2 = *in_EAX;
    param_1[1] = fVar3;
    *param_1 = fVar1 * param_4 + fVar2;
    fVar1 = in_EAX[4];
    *param_1 = param_3 * in_EAX[3] + *param_1;
    param_1[1] = param_3 * fVar1 + fVar3;
    return;
  }
  fVar1 = in_EAX[6];
  fVar3 = -in_EAX[5] * param_4 + in_EAX[1];
  fVar2 = *in_EAX;
  param_1[1] = fVar3;
  *param_1 = fVar1 * param_4 + fVar2;
  fVar1 = in_EAX[6];
  *param_1 = param_3 * in_EAX[5] + *param_1;
  param_1[1] = param_3 * fVar1 + fVar3;
  return;
}


// ==== 0x432df0 FUN_00432df0

int __fastcall FUN_00432df0(int param_1)

{
  int in_EAX;
  
  return in_EAX * 0x88 + 0x27c + param_1;
}


// ==== 0x432e00 FUN_00432e00

int FUN_00432e00(void)

{
  int in_EAX;
  
  return (int)*(short *)(in_EAX + 0x10);
}


// ==== 0x432e10 PtrArray_GetOrNull

/* [canon] runtime low (ghidra-canon) docs/re/canon.md */

undefined4 __fastcall PtrArray_GetOrNull(int param_1)

{
  int in_EAX;
  
  if (-1 < in_EAX) {
    return *(undefined4 *)(param_1 + 0x10 + in_EAX * 4);
  }
  return 0;
}


// ==== 0x432e20 GameMode::IsNotMode0456

/* [canon] runtime low (ghidra-canon) docs/re/canon.md */

undefined4 GameMode__IsNotMode0456(void)

{
  int iVar1;
  int *in_EAX;
  
  iVar1 = *in_EAX;
  if ((((iVar1 != 4) && (iVar1 != 5)) && (iVar1 != 0)) && (iVar1 != 6)) {
    return 1;
  }
  return 0;
}


// ==== 0x432e40 GameMode::IsMode03456

/* [canon] runtime low (ghidra-canon) docs/re/canon.md */

undefined4 GameMode__IsMode03456(void)

{
  int iVar1;
  int *in_EAX;
  
  iVar1 = *in_EAX;
  if ((((iVar1 != 3) && (iVar1 != 4)) && (iVar1 != 5)) && ((iVar1 != 0 && (iVar1 != 6)))) {
    return 0;
  }
  return 1;
}


// ==== 0x432e70 FUN_00432e70

int FUN_00432e70(void)

{
  int in_EAX;
  
  return in_EAX + 0x28;
}


// ==== 0x432e80 FUN_00432e80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_00432e80(float *param_1,int param_2)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  float10 fVar12;
  float local_70;
  float local_6c;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_3c;
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar10 = DAT_0078a2fc;
  pfVar8 = param_1;
  for (iVar6 = 0x200; pfVar8 = pfVar8 + 1, iVar6 != 0; iVar6 = iVar6 + -1) {
    *pfVar8 = 0.0;
  }
  *param_1 = 0.0;
  piVar11 = DAT_0077af20;
  piVar5 = (int *)NullUpdate_ret();
  if (piVar11 != piVar5) {
    param_2 = param_2 + iVar10 * 5;
    do {
      if (((char)piVar11[param_2 * 0xd + 0xd] != '\0') ||
         (*(char *)(param_2 * 0x34 + 0x35 + (int)piVar11) != '\0')) {
        iVar9 = (int)(short)piVar11[4];
        local_28 = 0;
        local_10 = 0;
        local_c = 0;
        iVar6 = 0;
        local_30 = 0;
        local_2c = 0;
        local_24 = 0;
        local_20 = 0.0;
        local_1c = 0;
        local_18 = 0x3f800000;
        local_14 = 0;
        if (iVar9 != 1 && -1 < iVar9 + -1) {
          do {
            iVar1 = iVar6 + 1;
            iVar7 = iVar1;
            if (iVar10 == 1) {
              iVar9 = iVar9 - iVar6;
              iVar6 = iVar9 + -1;
              iVar7 = iVar9 + -2;
            }
            pfVar8 = (float *)(piVar11 + iVar6 * 0x22 + 0x9f);
            pfVar2 = (float *)(piVar11 + iVar7 * 0x22 + 0x9f);
            fVar3 = (float)((int)*(short *)((int)pfVar8 + param_2 * 2 + 0x3c) << 8) * 1.5258789e-05;
            local_3c = -pfVar8[3];
            local_50 = pfVar8[3] * 0.0 + pfVar8[4] * fVar3 + *pfVar8;
            local_4c = pfVar8[4] * 0.0 + local_3c * fVar3 + pfVar8[1];
            fVar3 = (float)((int)*(short *)((int)pfVar2 + param_2 * 2 + 0x3c) << 8) * 1.5258789e-05;
            local_34 = -pfVar2[3];
            local_48 = pfVar2[3] * 0.0 + pfVar2[4] * fVar3 + *pfVar2;
            local_44 = pfVar2[4] * 0.0 + local_34 * fVar3 + pfVar2[1];
            TrackPath__UpdateCursor(&DAT_007372b0,&local_50);
            fVar12 = (float10)Race__GetFractionFromMarker(local_20 * 100.0);
            local_70 = (float)fVar12;
            TrackPath__UpdateCursor(&DAT_007372b0,&local_48);
            fVar12 = (float10)Race__GetFractionFromMarker(local_20 * 100.0);
            if (fVar12 - (float10)local_70 <= (float10)0.5) {
              if ((float10)0.5 < (float10)local_70 - fVar12) {
                fVar12 = fVar12 + (float10)_K_ONE;
              }
            }
            else {
              local_70 = (float)((float10)local_70 + (float10)_K_ONE);
            }
            local_6c = 0.0;
            fVar3 = (float)((uint)*(byte *)(param_2 + 0x6a + (int)pfVar8) << 0x10) * 1.5258789e-05;
            if (0.0 < fVar3) {
              local_6c = (float)((fVar12 - (float10)local_70) /
                                (SQRT(((float10)local_50 - (float10)local_48) *
                                      ((float10)local_50 - (float10)local_48) +
                                      ((float10)local_4c - (float10)local_44) *
                                      ((float10)local_4c - (float10)local_44)) / (float10)fVar3));
            }
            _ftol_nocw();
            iVar6 = _ftol_nocw();
            if ((0.0 < local_6c) && (param_1[iVar6 * 2 + 1] == 0.0)) {
              param_1[iVar6 * 2 + 1] = local_6c;
            }
            iVar9 = (int)(short)piVar11[4];
            iVar6 = iVar1;
          } while (iVar1 < iVar9 + -1);
        }
      }
      piVar11 = (int *)*piVar11;
    } while (piVar11 != piVar5);
  }
  fVar4 = 0.0;
  fVar3 = 0.0055555557;
  iVar10 = 0x20;
  pfVar8 = param_1 + 4;
  do {
    pfVar8[-2] = fVar4;
    if (pfVar8[-3] == 0.0) {
      pfVar8[-3] = fVar3;
    }
    fVar4 = 0.00390625 / pfVar8[-3] + fVar4;
    *pfVar8 = fVar4;
    if (pfVar8[-1] == 0.0) {
      pfVar8[-1] = pfVar8[-3];
    }
    fVar4 = 0.00390625 / pfVar8[-1] + fVar4;
    pfVar8[2] = fVar4;
    if (pfVar8[1] == 0.0) {
      pfVar8[1] = pfVar8[-1];
    }
    fVar4 = 0.00390625 / pfVar8[1] + fVar4;
    pfVar8[4] = fVar4;
    if (pfVar8[3] == 0.0) {
      pfVar8[3] = pfVar8[1];
    }
    fVar4 = 0.00390625 / pfVar8[3] + fVar4;
    pfVar8[6] = fVar4;
    if (pfVar8[5] == 0.0) {
      pfVar8[5] = pfVar8[3];
    }
    fVar4 = 0.00390625 / pfVar8[5] + fVar4;
    pfVar8[8] = fVar4;
    if (pfVar8[7] == 0.0) {
      pfVar8[7] = pfVar8[5];
    }
    fVar4 = 0.00390625 / pfVar8[7] + fVar4;
    pfVar8[10] = fVar4;
    if (pfVar8[9] == 0.0) {
      pfVar8[9] = pfVar8[7];
    }
    fVar4 = 0.00390625 / pfVar8[9] + fVar4;
    pfVar8[0xc] = fVar4;
    if (pfVar8[0xb] == 0.0) {
      pfVar8[0xb] = pfVar8[9];
    }
    iVar10 = iVar10 + -1;
    fVar4 = 0.00390625 / pfVar8[0xb] + fVar4;
    fVar3 = pfVar8[0xb];
    pfVar8 = pfVar8 + 0x10;
  } while (iVar10 != 0);
  *param_1 = fVar4;
  return param_1;
}


// ==== 0x433340 CurveTable::Evaluate

/* [canon] runtime med (ghidra-canon+hopper) docs/re/canon.md */

void __fastcall CurveTable__Evaluate(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  float *unaff_ESI;
  float *unaff_EDI;
  float10 extraout_ST0;
  float10 extraout_ST1;
  
  uVar1 = _ftol_nocw(param_1);
  iVar2 = _ftol_nocw(uVar1);
  if (unaff_ESI != (float *)0x0) {
    *unaff_ESI = (float)(extraout_ST1 * (float10)*unaff_EDI +
                         (extraout_ST0 - (float10)iVar2 * (float10)0.00390625) /
                         (float10)unaff_EDI[iVar2 * 2 + 1] + (float10)(unaff_EDI + iVar2 * 2 + 1)[1]
                        );
    return;
  }
  return;
}


// ==== 0x4333c0 FUN_004333c0

void __fastcall FUN_004333c0(int *param_1)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  
  *param_1 = in_EAX;
  *(int **)(in_EAX + 0x1c) = param_1;
  *(undefined1 *)((int)param_1 + 10) = 0;
  *(undefined1 *)((int)param_1 + 0xb) = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  param_1[8] = 0;
  piVar1 = param_1 + 0xe;
  iVar2 = 5;
  param_1[7] = (int)(*(float *)(*param_1 + 0x810) * 100.0);
  do {
    piVar1[-5] = 0;
    *piVar1 = 0;
    piVar1[5] = 0;
    piVar1[10] = 0x7fffffff;
    piVar1[0xf] = 0x7fffffff;
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  piVar1 = param_1 + 0x38;
  iVar2 = 0xb;
  do {
    piVar1[-0x16] = 0;
    *piVar1 = 0;
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  *(undefined1 *)(param_1 + 0x45) = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = -0x40800000;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  *(undefined1 *)(param_1 + 0x4d) = 0;
  *(undefined1 *)((int)param_1 + 0x135) = 0;
  param_1[0x4e] = 1;
  *(undefined1 *)(param_1 + 2) = 0xff;
  *(undefined2 *)(param_1 + 1) = 0xffff;
  *(undefined2 *)((int)param_1 + 6) = 0xffff;
  *(undefined1 *)((int)param_1 + 9) = 0;
  RacingCar__UpdateLapCounts();
  return;
}


// ==== 0x4334a0 RacingCar::DoSnapshot

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void RacingCar__DoSnapshot(void)

{
  int in_EAX;
  int iVar1;
  char cVar2;
  int unaff_ESI;
  
  FUN_00571ea0(0,"RacingCar");
  FUN_00571c20(unaff_ESI,in_EAX + 4,2,2,1);
  FUN_00571c20(unaff_ESI,in_EAX + 6,2,2,1);
  FUN_00571c20(unaff_ESI,in_EAX + 8,1,1,1);
  FUN_00571c20(unaff_ESI,in_EAX + 9,1,1,1);
  FUN_00571c20(unaff_ESI,in_EAX + 10,1,1,1);
  FUN_00571c20(unaff_ESI,in_EAX + 0xb,1,1,1);
  FUN_00571c20(unaff_ESI,in_EAX + 0xc,1,1,1);
  FUN_00571c20(unaff_ESI,in_EAX + 0xd,1,1,1);
  FUN_00571c20(unaff_ESI,in_EAX + 0xe,1,1,1);
  FUN_00571c20(unaff_ESI,in_EAX + 0x10,2,2,1);
  FUN_00571c20(unaff_ESI,in_EAX + 0x14,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x18,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x1c,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x20,4,0xffffffff,0);
  if (DAT_0078a30c == 2) {
    FUN_00571c20(unaff_ESI,in_EAX + 0x24,4,0xffffffff,0);
    iVar1 = DAT_0073619c;
    FUN_00571c20(unaff_ESI,in_EAX + 0x24 + *(char *)(DAT_0073619c + 0x53f) * 4,4,0xffffffff,0);
    FUN_00571c20(unaff_ESI,in_EAX + 0x38 + *(char *)(iVar1 + 0x53f) * 4,4,0xffffffff,0);
  }
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


// ==== 0x433620 HudMeter::SetLevel

/* [canon] hud low (ghidra-canon) docs/re/canon.md */

void HudMeter__SetLevel(int param_1)

{
  char cVar1;
  int in_EAX;
  
  cVar1 = *(char *)(in_EAX + 8);
  *(undefined1 *)(in_EAX + 9) = (undefined1)param_1;
  *(undefined1 *)(in_EAX + 8) = (undefined1)param_1;
  *(float *)(in_EAX + 0x14) = (*(float *)(in_EAX + 0x14) - (float)(int)cVar1) + (float)param_1;
  return;
}


// ==== 0x433650 RacingCar::CheckBoundaryCrossing

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] rivals high (ghidra-canon+nfsug) docs/re/rivals.md */

undefined4 RacingCar__CheckBoundaryCrossing(int param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  undefined4 *unaff_ESI;
  
  param_2 = param_2 - param_3;
  if ((0 < DAT_007372b8) && (*(char *)(DAT_007372bc + 1) != '\0')) {
    if (-50.0 <= param_2) {
      if (50.0 < param_2) {
        param_2 = param_2 - 100.0;
      }
    }
    else {
      param_2 = param_2 + 100.0;
    }
  }
  param_3 = *(float *)(param_1 + 0x1c) - param_3;
  if ((0 < DAT_007372b8) && (*(char *)(DAT_007372bc + 1) != '\0')) {
    if (-50.0 <= param_3) {
      if (50.0 < param_3) {
        param_3 = param_3 - 100.0;
      }
    }
    else {
      param_3 = param_3 + 100.0;
    }
  }
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  if (25.0 < ABS(param_2)) {
    return 0;
  }
  if ((0.0 <= param_3) || (param_2 < 0.0)) {
    if (param_3 < 0.0) {
      return 0;
    }
    if (0.0 <= param_2) {
      return 0;
    }
    *unaff_ESI = 0;
    unaff_ESI[1] = 1;
  }
  else {
    *unaff_ESI = 1;
    unaff_ESI[1] = 0;
  }
  uVar1 = _ftol_nocw();
  unaff_ESI[2] = uVar1;
  return 1;
}


// ==== 0x4337a0 RacingCar::UpdateLapScore

/* [canon] rivals med (ghidra-canon) docs/re/canon.md */

void __thiscall RacingCar__UpdateLapScore(int *param_1,char param_2)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  
  if ((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) {
    if (param_2 != '\0') {
      iVar3 = *(int *)(*param_1 + 0x14);
      if ((*(int *)(iVar3 + 4) == 1) && (*(char *)(iVar3 + 0x734) == '\0')) {
        iVar3 = *(int *)(*param_1 + 0x18);
        FUN_0043e310(0);
        FUN_0043f240(0);
        piVar1 = (int *)(iVar3 + 0x960);
        StyleItemTable__FinishAll();
        StyleItemTable__Update(piVar1,iVar3,0);
        *(undefined1 *)(*piVar1 + 0x14) = 0;
      }
    }
    iVar3 = *param_1;
    fVar2 = 0.0;
    if ((*(int *)(*(int *)(iVar3 + 0x14) + 4) == 1) &&
       (*(char *)(*(int *)(iVar3 + 0x14) + 0x734) == '\0')) {
      fVar2 = *(float *)(*(int *)(*(int *)(iVar3 + 0x18) + 0x960) + 0x28);
    }
    else if ((*(char *)(*(int *)(iVar3 + 0x14) + 0x734) != '\0') &&
            (*(int *)(*(int *)(iVar3 + 0x14) + 4) == 1)) {
      iVar3 = Race__GetPlayer((int)*(short *)(iVar3 + 10));
      fVar2 = (float)*(int *)(iVar3 + 0xc);
    }
    iVar3 = (int)*(char *)((int)param_1 + 9);
    if (*(char *)((int)param_1 + 0xd) == '\0') {
      iVar3 = *(char *)((int)param_1 + 9) + 1;
      if (*(int *)(DAT_0073619c + 0x530) <= iVar3) {
        iVar3 = *(int *)(DAT_0073619c + 0x530);
      }
    }
    if ((float)param_1[iVar3 + 0x38] < fVar2 - (float)param_1[0x43]) {
      param_1[iVar3 + 0x38] = (int)(fVar2 - (float)param_1[0x43]);
    }
    if (*(char *)((int)param_1 + 0xd) != '\0') {
      param_1[0x43] = (int)fVar2;
      return;
    }
  }
  return;
}


// ==== 0x4338c0 RacingCar::UpdateLapCounts

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void RacingCar__UpdateLapCounts(void)

{
  float fVar1;
  float fVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  int *piVar8;
  int *unaff_EDI;
  float10 fVar9;
  float10 extraout_ST1;
  float local_18;
  int local_c;
  
  iVar7 = *unaff_EDI;
  *(undefined1 *)((int)unaff_EDI + 0xd) = 0;
  *(undefined1 *)((int)unaff_EDI + 0xe) = 0;
  if ((*(int *)(iVar7 + 0x28) != 0) || (*(char *)(*(int *)(iVar7 + 0x14) + 0x734) != '\0')) {
    fVar2 = *(float *)(iVar7 + 0x810) * 100.0;
    local_18 = 0.0;
    iVar7 = DAT_0073619c;
    if (0 < *(short *)(DAT_0073619c + 0x53c)) {
      piVar8 = unaff_EDI + 0xe;
      do {
        iVar4 = RacingCar__CheckBoundaryCrossing
                          (unaff_EDI,fVar2,
                           *(undefined4 *)((int)piVar8 + iVar7 + (0x508 - (int)unaff_EDI)));
        if (iVar4 != 0) {
          if (local_c == 0) {
            if (local_18 == (float)(int)*(char *)(iVar7 + 0x53f)) {
              *(char *)(unaff_EDI + 2) = (char)unaff_EDI[2] + -1;
            }
          }
          else {
            if (local_18 == (float)(int)*(char *)(iVar7 + 0x53f)) {
              cVar6 = (char)unaff_EDI[2] + '\x01';
              *(char *)(unaff_EDI + 2) = cVar6;
              if (*(char *)((int)unaff_EDI + 9) < cVar6) {
                *(char *)((int)unaff_EDI + 9) = cVar6;
                *(undefined1 *)((int)unaff_EDI + 0xd) = 1;
              }
            }
            sVar3 = SUB42(local_18,0) + (char)unaff_EDI[2] * 5;
            *(short *)(unaff_EDI + 1) = sVar3;
            if (*(short *)((int)unaff_EDI + 6) < sVar3) {
              *(short *)((int)unaff_EDI + 6) = sVar3;
              *(undefined1 *)((int)unaff_EDI + 0xe) = 1;
              FUN_00586690(0x3c23d70a);
              iVar4 = _ftol_nocw();
              iVar7 = DAT_0073619c;
              if (*DAT_007345d0 == 0) {
                if ((unaff_EDI[9] != 0) && (unaff_EDI[9] != 0x7fffffff)) {
                  piVar8[5] = *piVar8;
                  *piVar8 = iVar4 - unaff_EDI[9];
                  piVar8[0xf] = piVar8[10];
                  if (*piVar8 < piVar8[10]) {
                    piVar8[10] = *piVar8;
                  }
                  if (((local_18 == (float)(int)*(char *)(iVar7 + 0x53f)) &&
                      (cVar6 = (char)unaff_EDI[2], -1 < cVar6)) && (cVar6 < '\v')) {
                    unaff_EDI[cVar6 + 0x22] = *piVar8;
                    unaff_EDI[(char)unaff_EDI[2] + 0x2d] = unaff_EDI[(char)unaff_EDI[2] + 0x22];
                    cVar6 = (char)unaff_EDI[2];
                    if ('\0' < cVar6) {
                      unaff_EDI[cVar6 + 0x2d] = unaff_EDI[cVar6 + 0x2d] + unaff_EDI[cVar6 + 0x2c];
                    }
                  }
                }
                piVar8[-5] = iVar4;
              }
              else if ((DAT_0078a30c == 2) &&
                      (local_18 == (float)(int)*(char *)(DAT_0073619c + 0x53f))) {
                iVar5 = unaff_EDI[9];
                if ((iVar5 != 0) && (iVar5 != 0x7fffffff)) {
                  *piVar8 = iVar4 - iVar5;
                }
                piVar8[-5] = iVar4;
              }
            }
          }
        }
        local_18 = (float)((int)local_18 + 1);
        piVar8 = piVar8 + 1;
      } while ((int)local_18 < (int)*(short *)(iVar7 + 0x53c));
    }
    if (*DAT_007345d0 == 0) {
      iVar4 = *unaff_EDI;
      if (2 < *(int *)(iVar4 + 0x3cc)) {
        if (*(int *)(*(int *)(iVar4 + 0x14) + 4) == 1) {
          fVar1 = *(float *)(iVar4 + 0x3d0);
          if (*(float *)(iVar4 + 0x3d0) < (float)unaff_EDI[0x46]) {
            fVar1 = (float)unaff_EDI[0x46];
          }
        }
        else {
          local_18 = *(float *)(iVar4 + 0x404);
          if (local_18 < _K_ONE) {
            local_18 = 1.0;
          }
          fVar9 = (float10)(**(code **)(**(int **)(iVar4 + 0x30) + 0x70))();
          local_18 = (float)(fVar9 / (float10)local_18);
          if (ABS(*(float *)(*unaff_EDI + 0x3d0)) <= local_18) {
            local_18 = ABS(*(float *)(*unaff_EDI + 0x3d0));
          }
          fVar9 = (float10)RideInfo__GetTheoreticalTopSpeed();
          if (fVar9 <= (float10)local_18) {
            local_18 = (float)fVar9;
          }
          fVar1 = (float)unaff_EDI[0x46];
          if ((float)unaff_EDI[0x46] <= local_18) {
            fVar1 = local_18;
          }
          iVar7 = DAT_0073619c;
          if ((fVar1 < 0.0) || (1000.0 < fVar1)) {
            fVar1 = (float)unaff_EDI[0x46];
          }
        }
        if (fVar1 != (float)unaff_EDI[0x46]) {
          unaff_EDI[0x46] = (int)fVar1;
        }
      }
      if ((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) {
        iVar4 = *unaff_EDI;
        fVar1 = *(float *)(iVar4 + 0x814) -
                *(float *)(iVar7 + 0x540 + *(char *)(iVar7 + 0x53e) * 4) * 0.01 * DAT_007372b0;
        if ((0 < DAT_007372b8) && (*(char *)(DAT_007372bc + 1) != '\0')) {
          if (DAT_007372b0 * -0.5 <= fVar1) {
            if (DAT_007372b0 * _K_HALF < fVar1) {
              fVar1 = fVar1 - DAT_007372b0;
            }
          }
          else {
            fVar1 = fVar1 + DAT_007372b0;
          }
        }
        if ((400.0 <= ABS(fVar1)) && ((float)unaff_EDI[0x49] < 0.0)) {
          iVar5 = _ftol_nocw();
          unaff_EDI[0x4a] = iVar5;
          unaff_EDI[0x49] = *(int *)(iVar4 + 0x3d0);
        }
      }
      fVar1 = (float)*(int *)(iVar7 + 0x14) * 0.00025;
      if (0.0 < fVar1) {
        unaff_EDI[0x47] = (int)(*(float *)(*unaff_EDI + 0x3bc) / fVar1);
        if ((unaff_EDI[0x48] == 0) && (60.0 <= *(float *)(*unaff_EDI + 0x3d0) * 2.237)) {
          iVar4 = _ftol_nocw();
          unaff_EDI[0x48] = iVar4;
        }
      }
      iVar4 = *unaff_EDI;
      if ((((unaff_EDI[0x4e] < *(int *)(iVar4 + 0x3d8)) && (*(int *)(iVar4 + 0x3d8) != 0)) &&
          (unaff_EDI[0x4b] = unaff_EDI[0x4b] + 1, *(int *)(iVar4 + 0x28) == 1)) &&
         (_K_HALF < *(float *)(*(int *)(*(int *)(iVar4 + 0x34) + 0x4c) + 0x68))) {
        unaff_EDI[0x4c] = unaff_EDI[0x4c] + 1;
      }
      if (unaff_EDI[0x4e] != *(int *)(iVar4 + 0x3d8)) {
        unaff_EDI[0x4e] = *(int *)(iVar4 + 0x3d8);
      }
    }
    fVar9 = (float10)Race__GetFractionFromMarker(fVar2);
    fVar9 = (float10)(int)(char)unaff_EDI[2] + fVar9;
    unaff_EDI[5] = (int)(float)fVar9;
    unaff_EDI[8] = (int)(float)fVar9;
    if (0.0 < DAT_0073457c) {
      unaff_EDI[6] = (int)(float)((float10)0.667 * ((fVar9 - extraout_ST1) / (float10)DAT_0073457c)
                                 + ((float10)_K_ONE - (float10)0.667) * (float10)(float)unaff_EDI[6]
                                 );
    }
    unaff_EDI[7] = (int)fVar2;
    if ((*(char *)((int)unaff_EDI + 0xd) == '\0') ||
       ((int)*(char *)((int)unaff_EDI + 9) < *(int *)(iVar7 + 0x530))) {
      RacingCar__UpdateLapScore(0);
    }
  }
  return;
}


// ==== 0x433e20 RacingCar::ExtrapolateRaceTime

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void RacingCar__ExtrapolateRaceTime(int param_1,int param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  if ((((*(int *)(DAT_0073619c + 0x24) < 1) || (iVar3 = *(int *)(DAT_0073619c + 0x520), iVar3 == 0))
      || (iVar3 == param_1)) ||
     ((*(short *)(iVar3 + 0x10) != 1 || (*(char *)(iVar3 + 0x114) != '\0')))) {
    uVar4 = _ftol_nocw();
    *(undefined4 *)(param_1 + 0x110) = uVar4;
  }
  else {
    CurveTable__Evaluate(*(undefined4 *)(param_1 + 0x20));
    CurveTable__Evaluate((float)(int)*(char *)(iVar3 + 9));
    iVar3 = _ftol_nocw();
    *(int *)(param_1 + 0x110) = (DAT_0073ad34 - iVar3) - *param_3;
  }
  FUN_00586690(0x3c23d70a);
  uVar4 = _ftol_nocw();
  *(undefined4 *)(param_1 + 0x110) = uVar4;
  *(undefined1 *)(param_1 + 0x114) = 1;
  iVar3 = DAT_0073619c;
  if ((*(char *)(param_1 + 9) == '\0') && (0 < param_2)) {
    uVar4 = _ftol_nocw();
    *(undefined4 *)(param_1 + 0x60 + *(char *)(iVar3 + 0x53f) * 4) = uVar4;
    cVar1 = *(char *)(iVar3 + 0x53f);
    FUN_00586690(0x3c23d70a);
    uVar4 = _ftol_nocw();
    *(undefined4 *)(param_1 + 0x60 + cVar1 * 4) = uVar4;
  }
  iVar2 = DAT_0073619c;
  cVar1 = *(char *)(param_1 + 9);
  iVar3 = cVar1 + 1;
  if (3 < (param_2 - iVar3) + 1) {
    iVar5 = _ftol_nocw();
    param_3 = (int *)(cVar1 + 4);
    piVar6 = (int *)(param_1 + 0x88 + iVar3 * 4);
    do {
      *piVar6 = iVar5;
      piVar6[0xb] = piVar6[10] + iVar5;
      if (*piVar6 < *(int *)(param_1 + 0x60 + *(char *)(iVar2 + 0x53f) * 4)) {
        *(int *)(param_1 + 0x60 + *(char *)(iVar2 + 0x53f) * 4) = *piVar6;
      }
      piVar6[1] = iVar5;
      piVar6[0xc] = piVar6[0xb] + iVar5;
      if (piVar6[1] < *(int *)(param_1 + 0x60 + *(char *)(iVar2 + 0x53f) * 4)) {
        *(int *)(param_1 + 0x60 + *(char *)(iVar2 + 0x53f) * 4) = piVar6[1];
      }
      piVar6[2] = iVar5;
      piVar6[0xd] = piVar6[0xc] + iVar5;
      if (piVar6[2] < *(int *)(param_1 + 0x60 + *(char *)(iVar2 + 0x53f) * 4)) {
        *(int *)(param_1 + 0x60 + *(char *)(iVar2 + 0x53f) * 4) = piVar6[2];
      }
      piVar6[3] = iVar5;
      piVar6[0xe] = piVar6[0xd] + iVar5;
      if (piVar6[3] < *(int *)(param_1 + 0x60 + *(char *)(iVar2 + 0x53f) * 4)) {
        *(int *)(param_1 + 0x60 + *(char *)(iVar2 + 0x53f) * 4) = piVar6[3];
      }
      param_3 = (int *)((int)param_3 + 4);
      iVar3 = iVar3 + 4;
      piVar6 = piVar6 + 4;
    } while ((int)param_3 < param_2);
  }
  if (iVar3 <= param_2) {
    iVar5 = _ftol_nocw();
    iVar7 = (param_2 - iVar3) + 1;
    piVar6 = (int *)(param_1 + 0x88 + iVar3 * 4);
    do {
      *piVar6 = iVar5;
      piVar6[0xb] = piVar6[10] + iVar5;
      if (*piVar6 < *(int *)(param_1 + 0x60 + *(char *)(iVar2 + 0x53f) * 4)) {
        *(int *)(param_1 + 0x60 + *(char *)(iVar2 + 0x53f) * 4) = *piVar6;
      }
      piVar6 = piVar6 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    return;
  }
  return;
}


// ==== 0x434150 Floats11_Max

/* [canon] runtime med (ghidra-canon+hopper) docs/re/canon.md */

void Floats11_Max(void)

{
  float fVar1;
  int in_EAX;
  float *pfVar2;
  int iVar3;
  
  fVar1 = 0.0;
  iVar3 = 0;
  pfVar2 = (float *)(in_EAX + 0xe4);
  do {
    if (fVar1 <= pfVar2[-1]) {
      fVar1 = pfVar2[-1];
    }
    if (fVar1 <= *pfVar2) {
      fVar1 = *pfVar2;
    }
    if (fVar1 <= pfVar2[1]) {
      fVar1 = pfVar2[1];
    }
    if (fVar1 <= pfVar2[2]) {
      fVar1 = pfVar2[2];
    }
    if (fVar1 <= pfVar2[3]) {
      fVar1 = pfVar2[3];
    }
    if (fVar1 <= pfVar2[4]) {
      fVar1 = pfVar2[4];
    }
    if (fVar1 <= pfVar2[5]) {
      fVar1 = pfVar2[5];
    }
    if (fVar1 <= pfVar2[6]) {
      fVar1 = pfVar2[6];
    }
    iVar3 = iVar3 + 8;
    pfVar2 = pfVar2 + 8;
  } while (iVar3 < 4);
  if (iVar3 < 0xb) {
    pfVar2 = (float *)(in_EAX + 0xe0 + iVar3 * 4);
    iVar3 = 0xb - iVar3;
    do {
      if (fVar1 <= *pfVar2) {
        fVar1 = *pfVar2;
      }
      pfVar2 = pfVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}


// ==== 0x434270 Race::Race

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void Race__Race(void)

{
  undefined4 *in_EAX;
  int iVar1;
  bool bVar2;
  
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  in_EAX[6] = 0;
  in_EAX[7] = 0;
  iVar1 = 4;
  do {
    RaceStatus__Reset();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *in_EAX = 0;
  iVar1 = DAT_0078a31c;
  bVar2 = DAT_0078a31c != 0;
  DAT_0073619c = in_EAX;
  in_EAX[0x14c] = DAT_0078a31c;
  if (((bVar2) && (((DAT_0078a318 != 0 || (DAT_0078a344 != '\0')) || (DAT_007361a8 != 0)))) &&
     (iVar1 != 1)) {
    in_EAX[0x14c] = 1;
  }
  in_EAX[0x14d] = 0;
  in_EAX[0x14e] = 0;
  in_EAX[4] = 0;
  in_EAX[1] = 0;
  in_EAX[5] = 0;
  in_EAX[6] = 0x7fffffff;
  in_EAX[7] = 0;
  in_EAX[8] = 0;
  in_EAX[9] = 0;
  in_EAX[10] = 0;
  *(undefined1 *)(in_EAX + 0xb) = 0;
  in_EAX[2] = 0;
  if (DAT_0078a368 == 0) {
    in_EAX[3] = 0x3f666666;
  }
  else {
    in_EAX[3] = 0x3f800000;
  }
  in_EAX[0x155] = 0;
  in_EAX[0x156] = 0;
  in_EAX[0x157] = 0;
  in_EAX[0x158] = 0;
  Race__FigureOutBoundaries();
  in_EAX[0x159] = 0;
  return;
}


// ==== 0x434360 RaceStatus::Reset

/* [canon] rivals med (ghidra-canon) docs/re/rivals.md */

int __fastcall RaceStatus__Reset(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  puVar2 = (undefined4 *)(param_1 + 0x88);
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)(param_1 + 0xb4);
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x128) = 0;
  return param_1;
}


// ==== 0x4343f0 Race::DoSnapshot

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __fastcall Race__DoSnapshot(int param_1)

{
  int in_EAX;
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char local_5;
  int local_4;
  
  FUN_00571ea0(0,&DAT_006cae4c);
  FUN_00571c20(in_EAX,param_1,1,4,1);
  FUN_00571c20(in_EAX,param_1 + 8,4,0xffffffff,0);
  FUN_00571c20(in_EAX,param_1 + 0x10,4,0xffffffff,0);
  FUN_00571c20(in_EAX,param_1 + 4,4,0xffffffff,0);
  FUN_00571c20(in_EAX,param_1 + 0x14,4,0xffffffff,0);
  FUN_00571c20(in_EAX,param_1 + 0x1c,4,0xffffffff,0);
  FUN_00571c20(in_EAX,param_1 + 0x20,4,0xffffffff,0);
  if ((*(char *)(in_EAX + 0x3e) != '\0') || (*(char *)(in_EAX + 0x3f) != '\0')) {
    FUN_00571c20(in_EAX,param_1 + 0x24,1,4,0);
  }
  FUN_00571c20(in_EAX,param_1 + 0x28,1,4,0);
  FUN_00571c20(in_EAX,param_1 + 0x2c,1,1,0);
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    local_4 = param_1 + 0x30;
    piVar3 = (int *)(param_1 + 0x520);
    do {
      RacingCar__DoSnapshot();
      iVar2 = (*piVar3 - param_1) + -0x30;
      local_5 = ((char)(iVar2 / 0x13c) + (char)(iVar2 >> 0x1f)) -
                (char)((longlong)iVar2 * 0x67b23a55 >> 0x3f);
      FUN_00571c20(in_EAX,&local_5,1,1,1);
      *piVar3 = local_5 * 0x13c + 0x30 + param_1;
      iVar4 = iVar4 + 1;
      local_4 = local_4 + 0x13c;
      piVar3 = piVar3 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x24));
  }
  if ((*(char *)(in_EAX + 0x3e) != '\0') || (*(char *)(in_EAX + 0x3f) != '\0')) {
    FUN_00571c20(in_EAX,param_1 + 0x530,1,4,0);
  }
  iVar4 = *(char *)(in_EAX + 0x40) * 0x10 + 0x4c + in_EAX;
  *(int *)(iVar4 + 0xc) = *(int *)(in_EAX + 0x150) - *(int *)(iVar4 + 0xc);
  cVar1 = *(char *)(in_EAX + 0x40) + -1;
  *(char *)(in_EAX + 0x40) = cVar1;
  if ((int)cVar1 < *(int *)(in_EAX + 0x44)) {
    *(undefined4 *)(in_EAX + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x434590 Race::Init

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall Race__Init(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00689773;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  Race__AddRacingCars();
  Race__SetInitialRoutesForAI(param_1);
  Race__SetRaceStage(param_1,param_2);
  if ((DAT_0078a368 == 0) || (DAT_0078a320 != 2)) {
    iVar2 = *(int *)(param_1 + 0x30);
  }
  else {
    iVar2 = *(int *)(param_1 + 0x16c);
  }
  iVar2 = *(int *)(iVar2 + 0x10);
  if (*(char *)(iVar2 + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  cVar1 = *(char *)(iVar2 + 0x424);
  pvVar3 = _malloc(0x804);
  uStack_4 = 0;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00432e80(pvVar3,(int)cVar1);
  }
  *(undefined4 *)(param_1 + 0x564) = uVar4;
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x434640 Race::AddMarkerPoint

/* [canon] rivals med (ghidra-canon) docs/re/canon.md */

int Race__AddMarkerPoint(int param_1,undefined4 *param_2,float param_3,int param_4)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  byte *in_EAX;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  
  iVar4 = param_1;
  iVar8 = 0;
  *param_2 = 0;
  param_2[1] = 0;
  if (100.0 < param_3) {
    param_3 = param_3 - 100.0;
  }
  iVar5 = -1;
  bVar2 = *in_EAX;
  bVar3 = bVar2;
  pbVar7 = in_EAX;
  while (bVar3 != 0) {
    iVar5 = iVar5 * 0x21 + (uint)bVar3;
    pbVar1 = pbVar7 + 1;
    pbVar7 = pbVar7 + 1;
    bVar3 = *pbVar1;
  }
  param_1 = TrackMarker_Get(iVar5,0);
  if (param_4 != 0) {
    iVar5 = -1;
    bVar3 = bVar2;
    pbVar7 = in_EAX;
    while (bVar3 != 0) {
      iVar5 = iVar5 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar7 + 1;
      pbVar7 = pbVar7 + 1;
      bVar3 = *pbVar1;
    }
    iVar5 = TrackMarker_Count(iVar5);
    if (0 < iVar5) {
      do {
        iVar6 = -1;
        bVar3 = bVar2;
        pbVar7 = in_EAX;
        while (bVar3 != 0) {
          iVar6 = iVar6 * 0x21 + (uint)bVar3;
          pbVar1 = pbVar7 + 1;
          pbVar7 = pbVar7 + 1;
          bVar3 = *pbVar1;
        }
        iVar6 = TrackMarker_Get(iVar6,iVar8);
        if (param_4 == *(int *)(iVar6 + 0xc)) {
          param_1 = iVar6;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar5);
    }
  }
  if (param_1 != 0) {
    TrackPath__UpdateCursor(&DAT_007372b0,(undefined4 *)(param_1 + 0x10));
    *param_2 = *(undefined4 *)(param_1 + 0x10);
    param_2[1] = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(iVar4 + 0x540 + *(short *)(iVar4 + 0x53c) * 4) = 0;
    *(short *)(iVar4 + 0x53c) = *(short *)(iVar4 + 0x53c) + 1;
    return *(short *)(iVar4 + 0x53c) + -1;
  }
  if (0.0 <= param_3) {
    *(float *)(iVar4 + 0x540 + *(short *)(iVar4 + 0x53c) * 4) = param_3;
    *(short *)(iVar4 + 0x53c) = *(short *)(iVar4 + 0x53c) + 1;
    return *(short *)(iVar4 + 0x53c) + -1;
  }
  return -1;
}


// ==== 0x434810 Race::FigureOutBoundaries

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void Race__FigureOutBoundaries(void)

{
  float fVar1;
  undefined1 uVar2;
  int unaff_ESI;
  undefined4 uVar3;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined2 *)(unaff_ESI + 0x53c) = 0;
  if (DAT_0078a2fc == 0) {
    uVar2 = Race__AddMarkerPoint(unaff_ESI,&local_8,0x40a00000,0);
    *(undefined1 *)(unaff_ESI + 0x53e) = uVar2;
    *(undefined4 *)(unaff_ESI + 0x554) = local_8;
    *(undefined4 *)(unaff_ESI + 0x558) = local_4;
    Race__AddMarkerPoint
              (unaff_ESI,&local_8,
               *(float *)(unaff_ESI + 0x540 + *(char *)(unaff_ESI + 0x53e) * 4) + 33.0,0);
    Race__AddMarkerPoint
              (unaff_ESI,&local_8,
               *(float *)(unaff_ESI + 0x540 + *(char *)(unaff_ESI + 0x53e) * 4) + 66.0,0);
    Race__AddMarkerPoint(unaff_ESI,&local_8,0xbf800000,0);
    if (DAT_0078a318 == 0) {
LAB_004349e1:
      *(undefined1 *)(unaff_ESI + 0x53f) = *(undefined1 *)(unaff_ESI + 0x53e);
      *(undefined4 *)(unaff_ESI + 0x560) = *(undefined4 *)(unaff_ESI + 0x558);
      *(undefined4 *)(unaff_ESI + 0x55c) = *(undefined4 *)(unaff_ESI + 0x554);
      return;
    }
    fVar1 = *(float *)(unaff_ESI + 0x540 + *(char *)(unaff_ESI + 0x53e) * 4);
    uVar3 = DAT_0078a340;
  }
  else {
    uVar2 = Race__AddMarkerPoint(unaff_ESI,&local_8,0x40a00000,DAT_0078a340);
    *(undefined1 *)(unaff_ESI + 0x53e) = uVar2;
    *(undefined4 *)(unaff_ESI + 0x558) = local_4;
    *(undefined4 *)(unaff_ESI + 0x554) = local_8;
    Race__AddMarkerPoint(unaff_ESI,&local_8,0xbf800000,0);
    Race__AddMarkerPoint
              (unaff_ESI,&local_8,
               *(float *)(unaff_ESI + 0x540 + *(char *)(unaff_ESI + 0x53e) * 4) + 33.0,0);
    Race__AddMarkerPoint
              (unaff_ESI,&local_8,
               *(float *)(unaff_ESI + 0x540 + *(char *)(unaff_ESI + 0x53e) * 4) + 66.0,0);
    if (DAT_0078a318 == 0) goto LAB_004349e1;
    uVar3 = 0;
    fVar1 = *(float *)(unaff_ESI + 0x540 + *(char *)(unaff_ESI + 0x53e) * 4);
  }
  uVar2 = Race__AddMarkerPoint(unaff_ESI,&local_8,fVar1 + 95.0,uVar3);
  *(undefined1 *)(unaff_ESI + 0x53f) = uVar2;
  *(undefined4 *)(unaff_ESI + 0x560) = local_4;
  *(undefined4 *)(unaff_ESI + 0x55c) = local_8;
  return;
}


// ==== 0x434a10 Race::GetFractionFromMarker

/* [canon] rivals med (ghidra-canon) docs/re/canon.md */

float10 Race__GetFractionFromMarker(float param_1)

{
  int in_EAX;
  float10 fVar1;
  
  fVar1 = (float10)param_1 - (float10)*(float *)(in_EAX + 0x540 + *(char *)(in_EAX + 0x53f) * 4);
  if ((0 < DAT_007372b8) && (*(char *)(DAT_007372bc + 1) != '\0')) {
    if ((float10)-50.0 <= fVar1) {
      if ((float10)50.0 < fVar1) {
        fVar1 = fVar1 - (float10)100.0;
      }
    }
    else {
      fVar1 = fVar1 + (float10)100.0;
    }
  }
  if (fVar1 < (float10)0.0) {
    fVar1 = fVar1 + (float10)100.0;
  }
  return fVar1 * (float10)0.01;
}


// ==== 0x434a80 Race::AddRacingCars

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void Race__AddRacingCars(void)

{
  int iVar1;
  int unaff_ESI;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = DAT_007361f8;
  if (0 < *(int *)(DAT_007361f8 + 0x1c)) {
    do {
      FUN_004333c0();
      *(int *)(unaff_ESI + 0x520 + *(int *)(unaff_ESI + 0x24) * 4) =
           *(int *)(unaff_ESI + 0x24) * 0x13c + 0x30 + unaff_ESI;
      iVar1 = DAT_007361f8;
      *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(iVar1 + 0x1c));
  }
  iVar2 = 0;
  if (*(int *)(iVar1 + 0x20) != *(int *)(iVar1 + 0x1c) &&
      -1 < *(int *)(iVar1 + 0x20) - *(int *)(iVar1 + 0x1c)) {
    do {
      FUN_004333c0();
      *(int *)(unaff_ESI + 0x520 + *(int *)(unaff_ESI + 0x24) * 4) =
           *(int *)(unaff_ESI + 0x24) * 0x13c + 0x30 + unaff_ESI;
      iVar1 = DAT_007361f8;
      *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(iVar1 + 0x20) - *(int *)(iVar1 + 0x1c));
  }
  Race__UpdatePlayerRanks();
  Race__UpdatePlayerRanks();
  return;
}


// ==== 0x434b50 Race::SetRaceStage

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall Race__SetRaceStage(undefined4 param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (((param_3 == 3) && (cVar3 = FUN_0043a2e0(param_1), cVar3 != '\0')) && (DAT_0077b240 != 6)) {
    if (DAT_0077b240 != 5) {
      FUN_0043aed0();
      return;
    }
  }
  else {
    *param_2 = param_3;
    iVar6 = 0;
    if (0 < param_2[9]) {
      iVar5 = 0x520;
      do {
        piVar1 = *(int **)((int)param_2 + iVar5);
        iVar4 = *piVar1;
        iVar2 = *(int *)(iVar4 + 0x24);
        if (0 < iVar2) {
          if (iVar2 < 3) {
LAB_00434be4:
            if (*param_2 == 4) {
              (**(code **)(**(int **)(iVar4 + 0x30) + 0x20))();
            }
            else {
LAB_00434bf9:
              (**(code **)(**(int **)(iVar4 + 0x30) + 0x1c))();
            }
          }
          else if (iVar2 == 3) {
            iVar2 = *(int *)(iVar4 + 0x30);
            if (*param_2 == 4) {
              *(undefined4 *)(iVar2 + 0x1e0) = 0;
              *(undefined4 *)(iVar2 + 0x1e4) = 0;
              *(undefined4 *)(iVar2 + 0x1dc) = 0x3f800000;
              goto LAB_00434be4;
            }
            goto LAB_00434bf9;
          }
        }
        if (param_3 == 4) {
          piVar1[9] = DAT_0073ad34;
          FUN_00586690(0x3c23d70a);
          iVar4 = _ftol_nocw();
          piVar1[9] = iVar4;
          *(undefined2 *)((int)piVar1 + 6) = 0;
          if (DAT_0078a318 != 0) {
            *(undefined1 *)(piVar1 + 2) = 0;
            *(undefined2 *)(piVar1 + 1) = 0;
          }
        }
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + 4;
      } while (iVar6 < param_2[9]);
    }
    if (param_3 == 3) {
      param_2[2] = DAT_0073ad34;
    }
    else if (param_3 == 4) {
      param_2[4] = DAT_0073ad34;
      FUN_00586690(0x3c23d70a);
      iVar6 = _ftol_nocw();
      param_2[4] = iVar6;
      param_2[1] = DAT_0073ad34;
      param_2[2] = 0;
    }
    if ((param_3 == 3) || (param_3 == 4)) {
      iVar6 = *(int *)(DAT_007361f8 + 0x18) - *(int *)(DAT_007361f8 + 0x24);
      iVar5 = 0;
      if (0 < iVar6) {
        do {
          *(undefined1 *)
           (*(int *)(DAT_007361f8 + 0x28 + (*(int *)(DAT_007361f8 + 0x24) + iVar5) * 4) + 0x4d0) = 1
          ;
          Car_SetMode();
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar6);
      }
    }
  }
  return;
}


// ==== 0x434d10 Race::GetCountdownNumberToDisplay

/* [canon] runtime med (ghidra-canon+nfsug) docs/re/runtime.md */

undefined4 __fastcall Race__GetCountdownNumberToDisplay(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 4) == 0x7fffffff)) {
    if ((*(int *)(param_1 + 8) != 0) && (*(int *)(param_1 + 8) != 0x7fffffff)) {
      fVar1 = (float)(DAT_0073ad34 - *(int *)(param_1 + 8)) * 0.00025;
      if (fVar1 < *(float *)(param_1 + 0xc)) {
        return 3;
      }
      if (fVar1 < *(float *)(param_1 + 0xc) + *(float *)(param_1 + 0xc)) {
        return 2;
      }
      if (fVar1 < *(float *)(param_1 + 0xc) * 3.0) {
        return 1;
      }
      return 4;
    }
  }
  else {
    if (*(float *)(param_1 + 0xc) < (float)(DAT_0073ad34 - *(int *)(param_1 + 4)) * 0.00025) {
      return 0;
    }
    uVar2 = 4;
  }
  return uVar2;
}


// ==== 0x434dd0 TimedMessage::GetPhaseProgress

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] runtime med (ghidra-canon) docs/re/canon.md */

float10 __fastcall TimedMessage__GetPhaseProgress(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float10 fVar4;
  
  if (*(float *)(param_1 + 0xc) == 0.0) {
    return (float10)0.0;
  }
  fVar4 = (float10)0.0;
  if ((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 4) == 0x7fffffff)) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == 0) {
      return fVar4;
    }
    if (iVar1 == 0x7fffffff) {
      return fVar4;
    }
    fVar2 = (float)(DAT_0073ad34 - iVar1) * 0.00025;
    if (fVar2 < *(float *)(param_1 + 0xc)) {
      return ((float10)fVar2 - (float10)*(float *)(param_1 + 0xc) * (float10)0.0) /
             (float10)*(float *)(param_1 + 0xc);
    }
    fVar3 = *(float *)(param_1 + 0xc) + *(float *)(param_1 + 0xc);
    if (fVar2 < fVar3) {
      return ((float10)fVar2 - (float10)*(float *)(param_1 + 0xc)) /
             (float10)*(float *)(param_1 + 0xc);
    }
    if (*(float *)(param_1 + 0xc) * 3.0 <= fVar2) {
      return fVar4;
    }
    fVar4 = (float10)fVar2 - (float10)fVar3;
  }
  else {
    fVar4 = (float10)(DAT_0073ad34 - *(int *)(param_1 + 4)) * (float10)0.00025;
    if ((float10)*(float *)(param_1 + 0xc) <= fVar4) {
      return (float10)_K_ONE;
    }
  }
  return fVar4 / (float10)*(float *)(param_1 + 0xc);
}


// ==== 0x434ed0 Race::UpdatePlayerRanks

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

void __fastcall Race__UpdatePlayerRanks(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_8;
  int local_4;
  
  do {
    local_8 = 0;
    local_4 = 0;
    if (*(int *)(param_2 + 0x24) == 1 || *(int *)(param_2 + 0x24) + -1 < 0) break;
    piVar3 = (int *)(param_2 + 0x524);
    do {
      iVar2 = piVar3[-1];
      iVar1 = *piVar3;
      if ((*(char *)(iVar2 + 0xc) == '\0') || (*(char *)(iVar1 + 0xc) == '\0')) {
        if (*(float *)(iVar2 + 0x20) < *(float *)(iVar1 + 0x20)) goto LAB_00434f15;
      }
      else if (*(char *)(iVar1 + 0xc) < *(char *)(iVar2 + 0xc)) {
LAB_00434f15:
        local_8 = local_8 + 1;
        piVar3[-1] = iVar1;
        *piVar3 = iVar2;
      }
      local_4 = local_4 + 1;
      piVar3 = piVar3 + 1;
    } while (local_4 < *(int *)(param_2 + 0x24) + -1);
  } while (local_8 != 0);
  iVar2 = 0;
  if (0 < *(int *)(param_2 + 0x24)) {
    piVar3 = (int *)(param_2 + 0x520);
    do {
      iVar1 = *piVar3;
      iVar2 = iVar2 + 1;
      *(undefined1 *)(iVar1 + 0xb) = *(undefined1 *)(iVar1 + 10);
      *(char *)(iVar1 + 10) = (char)iVar2;
      piVar3 = piVar3 + 1;
    } while (iVar2 < *(int *)(param_2 + 0x24));
  }
  return;
}


// ==== 0x434f80 Race::MonitorLeadership

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void Race__MonitorLeadership(int param_1)

{
  float fVar1;
  char cVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  char *pcVar14;
  
  iVar13 = 0;
  if (0 < DAT_007361c4) {
    do {
      if ((&DAT_007361bc)[iVar13] != 0) {
        piVar4 = *(int **)(*(int *)((&DAT_007361bc)[iVar13] + 4) + 0x1c);
        cVar2 = *(char *)((int)piVar4 + 10);
        cVar3 = *(char *)((int)piVar4 + 0xb);
        if (cVar2 != cVar3) {
          iVar11 = (int)cVar3;
          if (*(int *)(param_1 + 0x24) < iVar11) {
            piVar12 = (int *)0x0;
          }
          else {
            piVar12 = *(int **)(param_1 + 0x51c + iVar11 * 4);
          }
          iVar5 = *piVar4;
          fVar1 = *(float *)(iVar5 + 0x3d4);
          iVar6 = *piVar12;
          fVar7 = *(float *)(iVar6 + 0x3d4);
          if ((40.0 < fVar1) &&
             (fVar8 = *(float *)(iVar5 + 0x60) - *(float *)(iVar6 + 0x60),
             fVar10 = *(float *)(iVar5 + 100) - *(float *)(iVar6 + 100),
             fVar9 = *(float *)(iVar5 + 0x68) - *(float *)(iVar6 + 0x68),
             SQRT(fVar8 * fVar8 + fVar10 * fVar10 + fVar9 * fVar9) < 25.0)) {
            if (cVar2 < cVar3) {
              pcVar14 = "GainPosition";
              fVar8 = 4.0 / (float)(int)cVar2 + 1.0;
            }
            else {
              pcVar14 = "LosePosition";
              fVar8 = 2.0 / (float)iVar11;
            }
            FUN_00572970(fVar8,pcVar14);
            if (ABS(fVar1 - fVar7) < 7.0) {
              FUN_00572970(0x40200000,"ClosePass");
            }
          }
        }
      }
      iVar13 = iVar13 + 1;
    } while (iVar13 < DAT_007361c4);
  }
  return;
}


// ==== 0x4350d0 Race::FinishCar

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall Race__FinishCar(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  int in_EAX;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int local_4;
  
  piVar1 = *(int **)(param_1 + 0x520 + in_EAX * 4);
  iVar2 = *piVar1;
  if (iVar2 == 0) {
    local_4 = 0;
  }
  else {
    local_4 = *(int *)(iVar2 + 0x18);
  }
  if (param_4 == 4) {
    piVar1[0x44] = DAT_0073ad34 - *(int *)(param_1 + 0x10);
LAB_0043514a:
    FUN_00586690(0x3c23d70a);
    iVar5 = _ftol_nocw();
    piVar1[0x44] = iVar5;
  }
  else if (param_4 == 5) {
    iVar5 = _ftol_nocw();
    piVar1[0x44] = iVar5;
    goto LAB_0043514a;
  }
  *(short *)(piVar1 + 4) = (short)param_4;
  piVar1[8] = piVar1[5];
  RacingCar__UpdateLapScore(1);
  cVar3 = FUN_0043a2e0();
  iVar5 = DAT_0077b244;
  if (cVar3 == '\0') {
    if (param_2 == 0) {
      if ((int)*(char *)((int)piVar1 + 9) == *(int *)(param_1 + 0x530)) {
        uVar4 = Race_FindFirstMissingRank(param_1);
        iVar5 = DAT_0073619c;
        *(undefined1 *)(piVar1 + 3) = uVar4;
        piVar1[0x44] = piVar1[*(char *)(iVar5 + 0x53f) + 9] - *(int *)(param_1 + 0x10);
        goto LAB_004352bc;
      }
      uVar4 = Race_FindFirstMissingRank(param_1);
      *(undefined1 *)(piVar1 + 3) = uVar4;
    }
    else if ((param_2 < 0) || (*(char *)(piVar1 + 3) = (char)param_2, DAT_0078a30c != 3))
    goto LAB_004352bc;
    RacingCar__ExtrapolateRaceTime(piVar1,*(undefined4 *)(param_1 + 0x530),param_1 + 0x10);
  }
  else {
    if ((((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) &&
        (*(int *)(*(int *)(*piVar1 + 0x14) + 4) == 1)) &&
       (((*(char *)(*(int *)(*piVar1 + 0x14) + 0x734) == '\0' && (param_4 == 9)) &&
        (iVar6 = FUN_00439930(4), *(int *)(iVar5 + 0x18c + iVar6 * 4) == 0)))) {
      param_4 = 1;
      *(undefined2 *)(piVar1 + 4) = 1;
    }
    if ((char)piVar1[3] == '\0') {
      if (param_4 == 1) {
        uVar4 = Race_FindFirstMissingRank(param_1);
      }
      else {
        uVar4 = Race__GetLastAvailableRank();
      }
      *(undefined1 *)(piVar1 + 3) = uVar4;
    }
    if ((int)*(char *)((int)piVar1 + 9) == *(int *)(param_1 + 0x530)) {
      piVar1[0x44] = piVar1[*(char *)(DAT_0073619c + 0x53f) + 9] - *(int *)(param_1 + 0x10);
    }
    else {
      piVar1[0x44] = DAT_0073ad34 - *(int *)(param_1 + 0x10);
    }
    cVar3 = FUN_0043be30((int)*(short *)(iVar2 + 10),(int)(char)piVar1[3],param_3,param_4);
    if (cVar3 == '\0') {
      *(undefined2 *)(piVar1 + 4) = 0;
      return;
    }
    iVar5 = *piVar1;
    if (((*(int *)(*(int *)(iVar5 + 0x14) + 4) == 1) && (param_4 == 1)) &&
       ((char)piVar1[3] == '\x01')) {
      iVar6 = SpecialCamCooldown();
      if (((iVar6 == 0) && (iVar5 = Race__GetPlayer((int)*(short *)(iVar5 + 10)), iVar5 != 0)) &&
         (cVar3 = GameMode__IsMode03456(), cVar3 != '\0')) {
        *(int *)(param_1 + 0x1c) = *(int *)(iVar5 + 0x34) + *(int *)(param_1 + 0x10);
        *(undefined4 *)(param_1 + 0x20) = 0x41f00000;
      }
    }
  }
LAB_004352bc:
  if ((local_4 != 0) && ((char)piVar1[3] == '\x01')) {
    uVar7 = DAT_006f227c ^ 0x1d872b41;
    uVar8 = uVar7 >> 5 ^ uVar7;
    DAT_006f227c = uVar8 << 0x1b ^ uVar8 ^ uVar7;
  }
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  if (local_4 != 0) {
    FUN_0042c1f0();
    cVar3 = FUN_0043a2e0();
    Player__SetInputMode(-(cVar3 != '\0') & 8);
    FUN_00425fe0();
  }
  if (*(int *)(iVar2 + 0x24) == 3) {
    *(undefined4 *)(*(int *)(iVar2 + 0x2c) + 0x3f4) = 0x11;
  }
  if ((char)param_3 != '\0') {
    *(int *)(iVar2 + 0x884) = DAT_0073ad34;
    *(undefined4 *)(iVar2 + 0x888) = 0x40000000;
    *(undefined1 *)(iVar2 + 0x8a8) = 1;
    *(undefined1 *)(iVar2 + 0x8a9) = 0;
  }
  return;
}


// ==== 0x4353e0 Race::CalcTimeGapBetween

/* [canon] rivals med (ghidra-canon) docs/re/canon.md */

void Race__CalcTimeGapBetween(int *param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  int unaff_EBX;
  
  sVar1 = *(short *)(param_2 + 0x10);
  if ((sVar1 == 1) && (*(short *)(param_3 + 0x10) == 1)) {
    *param_1 = *(int *)(param_3 + 0x110) - *(int *)(param_2 + 0x110);
    return;
  }
  if (sVar1 != 1) {
    if (*(short *)(param_3 + 0x10) == 1) {
      CurveTable__Evaluate((float)(int)*(char *)(param_3 + 9));
      CurveTable__Evaluate(*(undefined4 *)(param_2 + 0x20));
      iVar2 = _ftol_nocw();
      *param_1 = ((iVar2 - *(int *)(param_3 + 0x110)) - *(int *)(unaff_EBX + 0x10)) + DAT_0073ad34;
      return;
    }
    if (sVar1 != 1) goto LAB_00435513;
  }
  if (*(short *)(param_3 + 0x10) != 1) {
    CurveTable__Evaluate(*(undefined4 *)(param_3 + 0x20));
    CurveTable__Evaluate((float)(int)*(char *)(param_2 + 9));
    iVar2 = _ftol_nocw();
    *param_1 = (iVar2 + *(int *)(param_2 + 0x110) + *(int *)(unaff_EBX + 0x10)) - DAT_0073ad34;
    return;
  }
LAB_00435513:
  CurveTable__Evaluate(*(undefined4 *)(param_3 + 0x20));
  CurveTable__Evaluate(*(undefined4 *)(param_2 + 0x20));
  iVar2 = _ftol_nocw();
  *param_1 = iVar2;
  return;
}


// ==== 0x435570 Race::Update

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __fastcall Race__Update(undefined4 param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int *unaff_ESI;
  undefined4 uVar9;
  
  if ((*unaff_ESI == 3) && (iVar3 = Race__GetCountdownNumberToDisplay(param_1), iVar3 == 4)) {
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar3 != 0) && ((*(int *)(iVar3 + 0x18) != 0 && (*(int **)(iVar3 + 0x14) != (int *)0x0))))
    {
      (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0xd8692111,0,0,*(int *)(iVar3 + 0x18));
    }
    Race__SetRaceStage(unaff_ESI,4);
  }
  if (*unaff_ESI == 4) {
    unaff_ESI[5] = DAT_0073ad34 - unaff_ESI[4];
    FUN_00586690(0x3c23d70a);
    iVar3 = _ftol_nocw();
    unaff_ESI[5] = iVar3;
  }
  iVar3 = 0;
  if (0 < unaff_ESI[9]) {
    piVar6 = unaff_ESI + 0x148;
    do {
      piVar8 = (int *)*piVar6;
      if ((((short)piVar8[4] == 0) &&
          (RacingCar__UpdateLapCounts(), *(int *)(*(int *)(*piVar8 + 0x14) + 4) == 1)) &&
         (piVar8[*(char *)(DAT_0073619c + 0x53f) + 0x18] < unaff_ESI[6])) {
        unaff_ESI[6] = piVar8[*(char *)(DAT_0073619c + 0x53f) + 0x18];
      }
      iVar3 = iVar3 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar3 < unaff_ESI[9]);
  }
  iVar3 = unaff_ESI[0x14d];
  iVar4 = 0;
  if ((iVar3 != 0) && (unaff_ESI[10] = 0, 0 < unaff_ESI[9])) {
    piVar6 = unaff_ESI + 0x148;
    do {
      piVar8 = (int *)*piVar6;
      if ((((short)piVar8[4] == 0) && (*piVar8 != 0)) &&
         ((iVar5 = *(int *)(*piVar8 + 0x18), iVar5 != 0 &&
          (unaff_ESI[0x14e] == *(int *)(iVar5 + 0x10))))) {
        Race__FinishCar(iVar3,0,1);
        if (((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) && (iVar3 == 1)) {
          piVar8[unaff_ESI[0x14c] + 0x38] = 0x497423fe;
          *(undefined4 *)(iVar5 + 0xa08 + unaff_ESI[0x14c] * 4) = 1;
        }
        break;
      }
      iVar4 = iVar4 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar4 < unaff_ESI[9]);
  }
  Race__UpdatePlayerRanks();
  Race__MonitorLeadership(unaff_ESI);
  if ((DAT_0078a30c == 3) && (0 < unaff_ESI[9])) {
    piVar6 = unaff_ESI + 0x148;
    iVar3 = 1;
    do {
      iVar4 = *piVar6;
      if (((*(char *)(iVar4 + 0xd) != '\0') &&
          ((int)*(char *)(iVar4 + 10) + (int)*(char *)(iVar4 + 9) == unaff_ESI[9])) &&
         (iVar4 = iVar3, piVar8 = piVar6, iVar3 < unaff_ESI[9])) {
        do {
          piVar1 = (int *)piVar8[1];
          if ((short)piVar1[4] == 0) {
            iVar5 = *piVar1;
            if (iVar5 == 0) {
              iVar5 = 0;
            }
            else {
              iVar5 = *(int *)(iVar5 + 0x18);
            }
            Race__FinishCar(iVar4 + 1,iVar5 == 0,3);
          }
          iVar4 = iVar4 + 1;
          piVar8 = piVar8 + 1;
        } while (iVar4 < unaff_ESI[9]);
      }
      piVar6 = piVar6 + 1;
      bVar2 = iVar3 < unaff_ESI[9];
      iVar3 = iVar3 + 1;
    } while (bVar2);
  }
  if (((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) && (iVar3 = 0, 0 < unaff_ESI[9])) {
    piVar6 = unaff_ESI + 0x148;
    do {
      piVar8 = (int *)*piVar6;
      iVar4 = *piVar8;
      if ((*(char *)(iVar4 + 0x874) == '\0') || ((short)piVar8[4] != 0)) {
        if ((*(int *)(iVar4 + 0x28) == 1) &&
           ((*(int *)(*(int *)(*(int *)(iVar4 + 0x34) + 0x48) + 0x94) != 0 &&
            ((short)piVar8[4] == 0)))) {
          iVar4 = unaff_ESI[9];
          if (0 < iVar4) {
            piVar8 = unaff_ESI + iVar4 + 0x147;
            iVar5 = iVar4;
            do {
              if (iVar4 < iVar5) {
                iVar7 = 0;
              }
              else {
                iVar7 = *piVar8;
              }
              if (*(char *)(iVar7 + 0xc) == '\0') goto LAB_00435842;
              iVar5 = iVar5 + -1;
              piVar8 = piVar8 + -1;
            } while (0 < iVar5);
          }
          iVar5 = Race_FindFirstMissingRank(unaff_ESI);
LAB_00435842:
          uVar9 = 6;
          goto LAB_00435844;
        }
      }
      else {
        iVar4 = unaff_ESI[9];
        if (0 < iVar4) {
          piVar8 = unaff_ESI + iVar4 + 0x147;
          iVar5 = iVar4;
          do {
            if (iVar4 < iVar5) {
              iVar7 = 0;
            }
            else {
              iVar7 = *piVar8;
            }
            if (*(char *)(iVar7 + 0xc) == '\0') goto LAB_004357ee;
            iVar5 = iVar5 + -1;
            piVar8 = piVar8 + -1;
          } while (0 < iVar5);
        }
        iVar5 = Race_FindFirstMissingRank(unaff_ESI);
LAB_004357ee:
        uVar9 = 7;
LAB_00435844:
        Race__FinishCar(iVar5,0,uVar9);
      }
      iVar3 = iVar3 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar3 < unaff_ESI[9]);
  }
  if ((DAT_0078a346 != '\0') || (DAT_007361a0 != 0)) {
    iVar3 = *(int *)(*(int *)(DAT_007361bc + 4) + 0x1c);
    iVar4 = unaff_ESI[4];
    iVar5 = DAT_0078a314;
    if ((iVar4 != 0) && (iVar4 != 0x7fffffff)) {
      iVar5 = (iVar4 - DAT_0073ad34) + DAT_0078a314;
    }
    if (((float)iVar5 * 0.00025 < 0.0) && (*(short *)(iVar3 + 0x10) == 0)) {
      iVar4 = 0;
      if (0 < unaff_ESI[9]) {
        piVar6 = unaff_ESI + 0x148;
        do {
          if (iVar3 == *piVar6) {
            Race__FinishCar(1,0,8);
            break;
          }
          iVar4 = iVar4 + 1;
          piVar6 = piVar6 + 1;
        } while (iVar4 < unaff_ESI[9]);
      }
    }
  }
  if ((DAT_0078a30c == 2) && (iVar3 = 0, 0 < unaff_ESI[9])) {
    piVar6 = unaff_ESI + 0x148;
    do {
      iVar4 = *piVar6;
      if ((((*(char *)(iVar4 + 0xd) != '\0') && (*(short *)(iVar4 + 0x10) == 0)) &&
          (iVar4 = *(int *)(iVar4 + 0x38 + *(char *)(DAT_0073619c + 0x53f) * 4), iVar4 != 0)) &&
         ((iVar4 != 0x7fffffff && (iVar4 <= DAT_0078a310)))) {
        Race__FinishCar(0,0,1);
      }
      iVar3 = iVar3 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar3 < unaff_ESI[9]);
  }
  if (((0.0 < (float)unaff_ESI[8]) && (unaff_ESI[7] != 0)) &&
     ((unaff_ESI[7] != 0x7fffffff &&
      (((float)unaff_ESI[8] <= (float)(DAT_0073ad34 - unaff_ESI[7]) * 0.00025 &&
       (iVar3 = 0, 0 < unaff_ESI[9])))))) {
    piVar6 = unaff_ESI + 0x148;
    do {
      if (*(short *)(*piVar6 + 0x10) == 0) {
        iVar4 = unaff_ESI[9];
        if (0 < iVar4) {
          piVar8 = unaff_ESI + iVar4 + 0x147;
          iVar5 = iVar4;
          do {
            if (iVar4 < iVar5) {
              iVar7 = 0;
            }
            else {
              iVar7 = *piVar8;
            }
            if (*(char *)(iVar7 + 0xc) == '\0') goto LAB_004359fe;
            iVar5 = iVar5 + -1;
            piVar8 = piVar8 + -1;
          } while (0 < iVar5);
        }
        iVar5 = Race_FindFirstMissingRank(unaff_ESI);
LAB_004359fe:
        Race__FinishCar(iVar5,0,9);
      }
      iVar3 = iVar3 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar3 < unaff_ESI[9]);
  }
  if ((unaff_ESI[0x14c] != 0) && (iVar3 = 0, 0 < unaff_ESI[9])) {
    piVar6 = unaff_ESI + 0x148;
    do {
      if ((*(short *)(*piVar6 + 0x10) == 0) && ((int)*(char *)(*piVar6 + 9) == unaff_ESI[0x14c])) {
        Race__FinishCar(0,0,1);
      }
      iVar3 = iVar3 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar3 < unaff_ESI[9]);
  }
  return;
}


// ==== 0x435a70 Race::SimulateRaceFinish

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void Race__SimulateRaceFinish(void)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  int iVar3;
  
  if ((DAT_0078a30c == 3) && (*(int *)(unaff_ESI + 0x534) == 0)) {
    iVar1 = *(int *)(unaff_ESI + 0x24);
    if (0 < iVar1) {
      piVar2 = (int *)(unaff_ESI + 0x51c + iVar1 * 4);
      do {
        if (*(int *)(unaff_ESI + 0x24) < iVar1) {
          iVar3 = 0;
        }
        else {
          iVar3 = *piVar2;
        }
        if (*(short *)(iVar3 + 0x10) == 0) {
          Race__FinishCar(iVar1,0,(iVar1 != 1) * '\x02' + '\x01');
          *(char *)(iVar3 + 9) = '\x04' - (char)iVar1;
        }
        iVar1 = iVar1 + -1;
        piVar2 = piVar2 + -1;
      } while (0 < iVar1);
      return;
    }
  }
  else {
    iVar1 = 0;
    if (0 < *(int *)(unaff_ESI + 0x24)) {
      piVar2 = (int *)(unaff_ESI + 0x520);
      do {
        if (*(short *)(*piVar2 + 0x10) == 0) {
          Race__FinishCar(0,0,1);
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar1 < *(int *)(unaff_ESI + 0x24));
    }
    Race__UpdatePlayerRanks();
    *(undefined4 *)(unaff_ESI + 0x534) = 0;
    *(undefined4 *)(unaff_ESI + 0x538) = 0;
  }
  return;
}


// ==== 0x435b30 Race::AreAllPlayersFinishedRacing

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 Race__AreAllPlayersFinishedRacing(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  cVar1 = FUN_0043a2e0();
  if (cVar1 != '\0') {
    uVar2 = FUN_0043da90();
    return uVar2;
  }
  iVar3 = 0;
  if (0 < DAT_007361c4) {
    do {
      if (*(int *)((&DAT_007361bc)[iVar3] + 0x58) == 0) {
        return 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_007361c4);
  }
  return 1;
}


// ==== 0x435b90 Players_FindNisPlayer

/* [canon] camera med (ghidra-canon+hopper) docs/re/canon.md */

int Players_FindNisPlayer(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = 0;
  iVar3 = 0;
  if (0 < DAT_007361c4) {
    do {
      iVar1 = *(int *)((&DAT_007361bc)[iVar3] + 0x58);
      if ((iVar1 != 0) && (iVar4 < iVar1)) {
        iVar2 = (&DAT_007361bc)[iVar3];
        iVar4 = iVar1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_007361c4);
  }
  return iVar2;
}


// ==== 0x435bd0 Race_FindFirstMissingRank

/* [canon] rivals med (ghidra-canon+hopper) docs/re/rivals.md */

void Race_FindFirstMissingRank(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 1;
  do {
    iVar3 = 0;
    if (*(int *)(param_1 + 0x24) < 1) {
      return;
    }
    piVar2 = (int *)(param_1 + 0x520);
    while (iVar1 != *(char *)(*piVar2 + 0xc)) {
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
      if (*(int *)(param_1 + 0x24) <= iVar3) {
        return;
      }
    }
    iVar1 = iVar1 + 1;
  } while( true );
}


// ==== 0x435c10 Race::GetLastAvailableRank

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void Race__GetLastAvailableRank(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x24);
  if (0 < iVar1) {
    piVar4 = (int *)(unaff_EDI + 0x51c + iVar1 * 4);
    iVar2 = iVar1;
    do {
      if (iVar1 < iVar2) {
        iVar3 = 0;
      }
      else {
        iVar3 = *piVar4;
      }
      if (*(char *)(iVar3 + 0xc) == '\0') {
        return;
      }
      iVar2 = iVar2 + -1;
      piVar4 = piVar4 + -1;
    } while (0 < iVar2);
  }
  Race_FindFirstMissingRank(unaff_EDI);
  return;
}


// ==== 0x435c50 Race::FinishCar

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall
Race__FinishCar(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    piVar2 = (int *)(param_1 + 0x520);
    while (*(int *)(param_2 + 0x1c) != *piVar2) {
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
      if (*(int *)(param_1 + 0x24) <= iVar1) {
        return;
      }
    }
    if (param_3 == 0) {
      param_3 = (int)*(char *)(*(int *)(param_2 + 0x1c) + 10);
    }
    Race__FinishCar(param_3,param_4,param_5);
  }
  return;
}


// ==== 0x435ca0 RaceManager::IsInRaceStartWindow

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] rivals med (ghidra-canon) docs/re/rivals.md */

uint RaceManager__IsInRaceStartWindow(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  undefined4 in_EAX;
  int iVar3;
  uint uVar4;
  
  uVar4 = CONCAT31((int3)((uint)in_EAX >> 8),DAT_0078a344);
  if (((DAT_0078a344 != '\0') || (uVar4 = DAT_007361a8, DAT_007361a8 != 0)) ||
     (DAT_0078a2f0 == 1099)) {
    return uVar4 & 0xffffff00;
  }
  iVar3 = (int)*(short *)(param_2 + 10);
  fVar1 = _DAT_00700a9c;
  if ((100 < iVar3) && (iVar3 < 0x96)) {
    fVar1 = (float)(100 - iVar3) * _DAT_00700aa0 + _DAT_00700a9c;
  }
  fVar2 = (float)(DAT_0073ad34 - *(int *)(param_1 + 0x10)) * 0.00025;
  if (fVar2 < fVar1 != (fVar2 == fVar1)) {
    return 1;
  }
  return 0;
}


// ==== 0x435d30 Race::SetInitialRoutesForAI

/* [canon] rivals high (ghidra-canon+nfsug) docs/re/canon.md */

void Race__SetInitialRoutesForAI(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_8;
  int local_4;
  
  iVar2 = *(int *)(DAT_007361f8 + 0x1c);
  iVar6 = 0;
  iVar7 = 0;
  local_4 = 0;
  if (*(int *)(DAT_007361f8 + 0x20) != iVar2 && -1 < *(int *)(DAT_007361f8 + 0x20) - iVar2) {
    do {
      iVar2 = *(int *)(DAT_007361f8 + 0x28 + (iVar2 + local_4) * 4);
      piVar1 = *(int **)(iVar2 + 0x2c);
      switch(*(undefined1 *)(*(int *)(iVar2 + 0x14) + 3)) {
      case 1:
        local_8 = 1;
        break;
      case 2:
        local_8 = 2;
        break;
      default:
        local_8 = 0;
        break;
      case 4:
        local_8 = 3;
      }
      iVar3 = 0;
      iVar5 = DAT_00736168;
      if (0 < DAT_0073616c) {
        do {
          if (*(short *)(iVar5 + 0x6c) == DAT_0078a2f0) goto LAB_00435dcf;
          iVar3 = iVar3 + 1;
          iVar5 = iVar5 + 0xfc;
        } while (iVar3 < DAT_0073616c);
      }
      iVar5 = 0;
LAB_00435dcf:
      iVar5 = (int)*(short *)(iVar5 + (local_8 + 0x54 + DAT_0078a2fc * 4) * 2);
      if (iVar5 < 0) {
        if (((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) &&
           ((DAT_0078a2f0 != 1099 || ((DAT_00735fb0 == 0 || (DAT_00735fb8 != 4)))))) {
          if ((local_4 != 0) ||
             (((((iVar6 != 0 && (iVar7 != 0)) && (-1 < *(short *)(iVar6 + 10))) &&
               ((*(short *)(iVar6 + 10) < 0x78 &&
                (iVar5 = ((iVar7 - iVar6) + -0x27c) / 0x88, -1 < iVar5)))) &&
              (iVar5 < *(short *)(iVar6 + 0x10))))) {
            if (*(char *)(*(int *)(iVar2 + 0x10) + 0x424) == -1) {
              RideInfo__RebuildPhysicsInfo(1);
            }
            goto LAB_00435f2b;
          }
          (**(code **)(*piVar1 + 0x2c))(0);
        }
        else {
          (**(code **)(*piVar1 + 0x2c))(0);
          uVar4 = (**(code **)(*piVar1 + 0x40))(0xff,0xff);
          (**(code **)(*piVar1 + 0x18))(1,uVar4);
          uVar4 = GetNearestTrafficLane(iVar2);
          iVar6 = *piVar1;
          uVar4 = (**(code **)(iVar6 + 0x18))(1,uVar4);
          uVar4 = (**(code **)(*piVar1 + 0x14))(1,uVar4);
          (**(code **)(iVar6 + 0x10))(uVar4);
        }
        iVar6 = (**(code **)(*piVar1 + 0x14))(1);
        iVar7 = (**(code **)(*piVar1 + 0x18))(1);
      }
      else {
        iVar6 = (&DAT_0077af30)[iVar5];
        iVar7 = FUN_00442690(iVar6,0x4cbebc20,0,0);
        iVar2 = *(int *)(iVar2 + 0x10);
        if (*(char *)(iVar2 + 0x424) == -1) {
          RideInfo__RebuildPhysicsInfo(1);
        }
        (**(code **)(*piVar1 + 0x10))(iVar6,iVar7,(int)*(char *)(iVar2 + 0x424));
      }
LAB_00435f2b:
      iVar2 = *(int *)(DAT_007361f8 + 0x1c);
      local_4 = local_4 + 1;
    } while (local_4 < *(int *)(DAT_007361f8 + 0x20) - iVar2);
  }
  return;
}


// ==== 0x435f70 Countdown::GetTotalSeconds

/* [canon] runtime low (ghidra-canon) docs/re/canon.md */

float10 Countdown__GetTotalSeconds(void)

{
  int in_EAX;
  
  return (float10)*(float *)(in_EAX + 0xc) * (float10)3.0;
}


// ==== 0x435f80 Countdown::GetSecondsRemaining

/* [canon] runtime med (ghidra-canon+hopper) docs/re/canon.md */

float10 Countdown__GetSecondsRemaining(void)

{
  int iVar1;
  int *in_EAX;
  
  if (*in_EAX == 3) {
    return (float10)(float)in_EAX[3] * (float10)3.0 -
           (float10)(DAT_0073ad34 - in_EAX[2]) * (float10)0.00025;
  }
  iVar1 = in_EAX[1];
  if ((iVar1 != 0) && (iVar1 != 0x7fffffff)) {
    return -((float10)(DAT_0073ad34 - iVar1) * (float10)0.00025);
  }
  return -(float10)-1.0;
}


// ==== 0x435fe0 ModeFlags_GetRow

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

int ModeFlags_GetRow(void)

{
  int in_EAX;
  
  return *(int *)(in_EAX + 0xc) * 0x20 + DAT_00736198;
}


// ==== 0x435ff0 FUN_00435ff0

undefined4 FUN_00435ff0(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x95c);
}


// ==== 0x436000 ModeFlags_Load

/* [canon] assets high (Hopper export has no block (inside another sub_); Ghidra export has no
   block; live Ghidra decompile + capstone) docs/re/assets.md */

undefined4 ModeFlags_Load(int *param_1)

{
  if (*param_1 == 0x34a07) {
    DAT_00736198 = (int)param_1 + 0x17U & 0xfffffff0;
    return 1;
  }
  return 0;
}


// ==== 0x436020 ModeFlags_Unload

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 ModeFlags_Unload(int *param_1)

{
  if (*param_1 == 0x34a07) {
    DAT_00736198 = 0;
    return 1;
  }
  return 0;
}


// ==== 0x436040 StyleItem::StyleItem

/* [canon] audio med (ghidra-canon) docs/re/canon.md */

int __fastcall StyleItem__StyleItem(int param_1)

{
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined1 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 0x15) = 1;
  *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
  *(undefined4 *)(param_1 + 8) = 0;
  StyleItem__Reset();
  return param_1;
}


// ==== 0x436070 StyleItem::Update

/* [canon] audio med (ghidra-canon) docs/re/canon.md */

void StyleItem__Update(float param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int in_EAX;
  int iVar4;
  int iVar5;
  float10 fVar6;
  
  iVar3 = DAT_00736190;
  iVar2 = DAT_0073618c;
  while( true ) {
    fVar1 = (float)(DAT_0073ad34 - *(int *)(in_EAX + 0x3c)) * 0.00025;
    if (*(float *)(*(int *)(in_EAX + 8) + 0xc) < fVar1) {
      if (*(int *)(in_EAX + 0x10) == 0) {
        StyleItem__Cancel(0);
      }
      else if (*(int *)(in_EAX + 0x10) == 1) {
        StyleItem__Finish(0);
        StyleItem__Rearm();
      }
    }
    if (((*(int *)(in_EAX + 0x10) == 0) || (*(int *)(in_EAX + 0x10) == 1)) &&
       (fVar1 < param_1 + param_1)) {
      fVar6 = (float10)StyleItem__AccumulateStep(param_1);
      *(float *)(in_EAX + 0x20) = (float)fVar6;
    }
    if (((*(int *)(in_EAX + 0x10) == 1) &&
        (iVar4 = *(int *)(in_EAX + 8),
        *(float *)(iVar4 + 8) < (float)(DAT_0073ad34 - *(int *)(in_EAX + 0x40)) * 0.00025)) &&
       (((*(float *)(iVar4 + 0x18) < 0.0 && (*(float *)(in_EAX + 0x24) < *(float *)(iVar4 + 0x10)))
        || ((0.0 < *(float *)(iVar4 + 0x18) &&
            (*(float *)(iVar4 + 0x10) < *(float *)(in_EAX + 0x24))))))) {
      *(int *)(in_EAX + 0x1c) = *(int *)(in_EAX + 0x1c) + 1;
      *(undefined4 *)(in_EAX + 0x10) = 0;
    }
    if ((*(int *)(in_EAX + 0xc) != 0) || (iVar2 == 0)) break;
    iVar5 = (iVar2 << 7) % iVar3;
    iVar4 = iVar5;
    if (iVar5 < 0) {
      iVar4 = -iVar5;
    }
    if (in_EAX == iVar4 * 0x44 + iVar2) {
      return;
    }
    if (iVar5 < 0) {
      iVar5 = -iVar5;
    }
    in_EAX = iVar5 * 0x44 + iVar2;
  }
  return;
}


// ==== 0x4361b0 StyleItem::AccumulateStep

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

void __fastcall StyleItem__AccumulateStep(undefined4 param_1,int param_2,float param_3)

{
  float fVar1;
  int iVar2;
  undefined4 local_4;
  
  iVar2 = *(int *)(param_2 + 8);
  local_4 = (float)*(int *)(param_2 + 0x18) * *(float *)(iVar2 + 0x18) * *(float *)(param_2 + 0x38)
            * param_3 + *(float *)(param_2 + 0x20);
  fVar1 = *(float *)(iVar2 + 0x14);
  if (*(float *)(iVar2 + 0x14) <= 0.0) {
    if ((0.0 <= fVar1) || (fVar1 = *(float *)(iVar2 + 0x14), *(float *)(iVar2 + 0x14) <= local_4))
    goto LAB_00436209;
  }
  else if (local_4 <= fVar1) goto LAB_00436209;
  local_4 = fVar1;
LAB_00436209:
  param_3 = *(float *)(iVar2 + 0x18) * *(float *)(param_2 + 0x38) * param_3;
  if (local_4 < param_3) {
    param_3 = local_4;
  }
  *(float *)(param_2 + 0x24) = param_3 + *(float *)(param_2 + 0x24);
  return;
}


// ==== 0x436230 StyleItem::Trigger

/* [canon] audio med (ghidra-canon) docs/re/canon.md */

void __thiscall StyleItem__Trigger(int *param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  float10 fVar8;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685028;
  local_c = ExceptionList;
  if ((-1 < *(char *)(param_1[2] + 0x1e)) && ((int)*(char *)(param_1[2] + 0x1e) <= param_1[7])) {
    return;
  }
  if (param_1[4] == 3) {
    return;
  }
  if (param_1[4] == 4) {
    return;
  }
  ExceptionList = &local_c;
  param_1[0xe] = param_2;
  param_1[0xf] = DAT_0073ad34;
  if (*(char *)(param_1[2] + 6) == '\0') {
    fVar8 = (float10)StyleItem__AccumulateStep(0x3f800000);
    iVar5 = param_1[2];
    if (((*(float *)(iVar5 + 0x18) < 0.0) && (fVar8 < (float10)*(float *)(iVar5 + 0x10))) ||
       ((piVar6 = DAT_0073618c, 0.0 < *(float *)(iVar5 + 0x18) &&
        ((float10)*(float *)(iVar5 + 0x10) < fVar8)))) {
      param_1[8] = (int)(float)fVar8;
      param_1[4] = 0;
      StyleItem__Cancel(0);
      piVar6 = DAT_0073618c;
    }
    goto LAB_0043640d;
  }
  piVar6 = DAT_0073618c;
  if (param_1[4] != 2) goto LAB_0043640d;
  if ((param_1[3] == 0) &&
     (cVar2 = FUN_0043a2e0(), piVar1 = DAT_0073618c, piVar6 = DAT_0073618c, cVar2 != '\0')) {
    if (DAT_0073618c != (int *)0x0) {
      iVar5 = ((int)DAT_0073618c << 7) % DAT_00736190;
      if (iVar5 < 0) {
        iVar5 = -iVar5;
      }
      if (param_1 == DAT_0073618c + iVar5 * 0x11) goto LAB_004363f3;
    }
    iVar5 = RandomInt(0x32);
    iVar5 = iVar5 + 5;
    DAT_00736190 = iVar5;
    piVar3 = _malloc(iVar5 * 0x44 + 4);
    local_4 = 0;
    if (piVar3 == (int *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = piVar3 + 1;
      *piVar3 = iVar5;
      eh_vector_constructor_iterator(piVar6,0x44,iVar5,StyleItem__StyleItem,NullUpdate_ret);
    }
    iVar5 = ((int)piVar6 << 7) % DAT_00736190;
    local_4 = 0xffffffff;
    if (iVar5 < 0) {
      iVar5 = -iVar5;
    }
    piVar3 = param_1;
    piVar7 = piVar6 + iVar5 * 0x11;
    DAT_0073618c = piVar6;
    for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar7 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar7 = piVar7 + 1;
    }
    if (piVar1 != (int *)0x0) {
      eh_vector_destructor_iterator(piVar1,0x44,piVar1[-1],NullUpdate_ret);
      _free(piVar1 + -1);
      piVar6 = DAT_0073618c;
    }
  }
LAB_004363f3:
  param_1[0x10] = DAT_0073ad34;
  param_1[4] = 1;
LAB_0043640d:
  if ((param_1[3] == 0) && (piVar6 != (int *)0x0)) {
    iVar5 = ((int)piVar6 << 7) % DAT_00736190;
    if (iVar5 < 0) {
      iVar5 = -iVar5;
    }
    if (param_1 != piVar6 + iVar5 * 0x11) {
      StyleItem__Trigger(param_2);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x436460 StyleItem::Finish

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

void __thiscall StyleItem__Finish(int param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = DAT_00736190;
  iVar1 = DAT_0073618c;
  while( true ) {
    if (*(int *)(param_1 + 0x10) == 1) {
      *(undefined4 *)(param_1 + 0x20) = 0;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    *(undefined1 *)(param_1 + 0x34) = param_2;
    *(undefined4 *)(param_1 + 0x10) = 4;
    if ((*(int *)(param_1 + 0xc) != 0) || (iVar1 == 0)) {
      return;
    }
    iVar4 = (iVar1 << 7) % iVar2;
    iVar3 = iVar4;
    if (iVar4 < 0) {
      iVar3 = -iVar4;
    }
    if (param_1 == iVar3 * 0x44 + iVar1) break;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    param_1 = iVar4 * 0x44 + iVar1;
  }
  return;
}


// ==== 0x4364d0 StyleItem::Cancel

/* [canon] audio med (ghidra-canon) docs/re/canon.md */

void __thiscall StyleItem__Cancel(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  *(char *)(param_1 + 0xd) = (char)param_2;
  param_1[4] = 3;
  param_1[10] = (float)param_1[8] + (float)param_1[10];
  if ((param_1[3] == 0) && (DAT_0073618c != 0)) {
    iVar1 = (DAT_0073618c << 7) % DAT_00736190;
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    if (param_1 != (undefined4 *)(iVar1 * 0x44 + DAT_0073618c)) {
      StyleItem__Cancel(param_2);
      iVar2 = (DAT_0073618c << 7) % DAT_00736190;
      iVar1 = iVar2;
      if (iVar2 < 0) {
        iVar1 = -iVar2;
      }
      if (*(float *)(iVar1 * 0x44 + 0x28 + DAT_0073618c) < (float)param_1[10]) {
        if (iVar2 < 0) {
          iVar2 = -iVar2;
        }
        puVar3 = (undefined4 *)(iVar2 * 0x44 + DAT_0073618c);
        for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
          *param_1 = *puVar3;
          puVar3 = puVar3 + 1;
          param_1 = param_1 + 1;
        }
      }
    }
  }
  return;
}


// ==== 0x436580 StyleItem::Reset

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

void __fastcall StyleItem__Reset(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = DAT_00736190;
  iVar1 = DAT_0073618c;
  while( true ) {
    *(undefined4 *)(param_1 + 0x18) = 1;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined1 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x10) = 2;
    if ((*(int *)(param_1 + 0xc) != 0) || (iVar1 == 0)) {
      return;
    }
    iVar4 = (iVar1 << 7) % iVar2;
    iVar3 = iVar4;
    if (iVar4 < 0) {
      iVar3 = -iVar4;
    }
    if (param_1 == iVar3 * 0x44 + iVar1) break;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    param_1 = iVar4 * 0x44 + iVar1;
  }
  return;
}


// ==== 0x436600 StyleItem::Rearm

/* [canon] audio med (ghidra-canon) docs/re/canon.md */

void StyleItem__Rearm(void)

{
  char cVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int in_EAX;
  int iVar5;
  int iVar6;
  
  iVar4 = DAT_00736190;
  iVar3 = DAT_0073618c;
  cVar1 = *(char *)(in_EAX + 0x34);
  while( true ) {
    if (cVar1 != '\0') {
      *(undefined1 *)(in_EAX + 0x34) = 0;
      return;
    }
    if (*(int *)(in_EAX + 0x10) == 3) {
      *(int *)(in_EAX + 0x1c) = *(int *)(in_EAX + 0x1c) + 1;
      StyleItem__AdvanceLevel();
      fVar2 = (float)(DAT_0073ad34 - *(int *)(in_EAX + 0x40)) * 0.00025;
      if (*(float *)(in_EAX + 0x2c) < fVar2) {
        *(float *)(in_EAX + 0x2c) = fVar2;
      }
      if (*(float *)(in_EAX + 0x30) < *(float *)(in_EAX + 0x20)) {
        *(undefined4 *)(in_EAX + 0x30) = *(undefined4 *)(in_EAX + 0x20);
      }
    }
    *(undefined4 *)(in_EAX + 0x20) = 0;
    *(undefined4 *)(in_EAX + 0x24) = 0;
    *(undefined4 *)(in_EAX + 0x40) = 0;
    *(undefined4 *)(in_EAX + 0x10) = 2;
    if (*(int *)(in_EAX + 0xc) != 0) {
      return;
    }
    if (iVar3 == 0) {
      return;
    }
    iVar6 = (iVar3 << 7) % iVar4;
    iVar5 = iVar6;
    if (iVar6 < 0) {
      iVar5 = -iVar6;
    }
    if (in_EAX == iVar5 * 0x44 + iVar3) break;
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    in_EAX = iVar6 * 0x44 + iVar3;
    cVar1 = *(char *)(in_EAX + 0x34);
  }
  return;
}


// ==== 0x4366c0 StyleItem::AdvanceLevel

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

void __fastcall StyleItem__AdvanceLevel(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = DAT_00736190;
  iVar1 = DAT_0073618c;
  while( true ) {
    if (*(int *)(param_1 + 0x18) < (int)*(char *)(*(int *)(param_1 + 8) + 0x1c)) {
      *(int *)(param_1 + 0x18) =
           (int)*(char *)(*(int *)(param_1 + 8) + 0x1d) + *(int *)(param_1 + 0x18);
    }
    if ((*(int *)(param_1 + 0xc) != 0) || (iVar1 == 0)) {
      return;
    }
    iVar4 = (iVar1 << 7) % iVar2;
    iVar3 = iVar4;
    if (iVar4 < 0) {
      iVar3 = -iVar4;
    }
    if (param_1 == iVar3 * 0x44 + iVar1) break;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    param_1 = iVar4 * 0x44 + iVar1;
  }
  return;
}


// ==== 0x436720 StyleItem::SetLevel

/* [canon] runtime med (ghidra-canon) docs/re/canon.md */

void StyleItem__SetLevel(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(in_EAX + 0xc);
  *(undefined4 *)(in_EAX + 0x18) = param_1;
  iVar2 = DAT_00736190;
  iVar1 = DAT_0073618c;
  while( true ) {
    if ((iVar3 != 0) || (iVar1 == 0)) {
      return;
    }
    iVar4 = (iVar1 << 7) % iVar2;
    iVar3 = iVar4;
    if (iVar4 < 0) {
      iVar3 = -iVar4;
    }
    if (in_EAX == iVar3 * 0x44 + iVar1) break;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    in_EAX = iVar4 * 0x44 + iVar1;
    *(undefined4 *)(in_EAX + 0x18) = param_1;
    iVar3 = *(int *)(in_EAX + 0xc);
  }
  return;
}


// ==== 0x436780 StyleItem::ResetLevel

/* [canon] runtime low (ghidra-canon) docs/re/runtime.md */

void StyleItem__ResetLevel(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(in_EAX + 0xc);
  *(undefined4 *)(in_EAX + 0x18) = 1;
  iVar2 = DAT_00736190;
  iVar1 = DAT_0073618c;
  while( true ) {
    if ((iVar3 != 0) || (iVar1 == 0)) {
      return;
    }
    iVar4 = (iVar1 << 7) % iVar2;
    iVar3 = iVar4;
    if (iVar4 < 0) {
      iVar3 = -iVar4;
    }
    if (in_EAX == iVar3 * 0x44 + iVar1) break;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    in_EAX = iVar4 * 0x44 + iVar1;
    *(undefined4 *)(in_EAX + 0x18) = 1;
    iVar3 = *(int *)(in_EAX + 0xc);
  }
  return;
}


// ==== 0x4367e0 StyleItemTable::StyleItemTable

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void StyleItemTable__StyleItemTable(int param_1)

{
  int iVar1;
  byte bVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685013;
  local_c = ExceptionList;
  iVar5 = 0;
  iVar4 = 0;
  ExceptionList = &local_c;
  do {
    local_4 = 0xffffffff;
    pvVar3 = _malloc(0x44);
    iVar1 = DAT_00736198;
    local_4 = 0;
    if (pvVar3 == (void *)0x0) {
      pvVar3 = (void *)0x0;
    }
    else {
      *(undefined4 *)((int)pvVar3 + 0x3c) = 0;
      *(undefined4 *)((int)pvVar3 + 0x40) = 0;
      *(int *)((int)pvVar3 + 8) = iVar1 + iVar4;
      *(undefined1 *)((int)pvVar3 + 0x14) = 0;
      *(undefined1 *)((int)pvVar3 + 0x15) = 1;
      *(int *)((int)pvVar3 + 0xc) = iVar5;
      StyleItem__Reset();
    }
    *(void **)(param_1 + iVar5 * 4) = pvVar3;
    iVar1 = DAT_007361a4;
    iVar4 = iVar4 + 0x20;
    iVar5 = iVar5 + 1;
  } while (iVar4 < 0x3e0);
  iVar4 = 0;
  do {
    if ((DAT_0078a345 == '\0') && (iVar1 == 0)) {
      if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
        bVar2 = ((DAT_0078a318 == 0) - 1U & 7) + 1;
      }
      else {
        bVar2 = 2;
      }
    }
    else {
      bVar2 = 4;
    }
    iVar5 = *(int *)(param_1 + iVar4 * 4);
    iVar4 = iVar4 + 1;
    *(bool *)(iVar5 + 0x14) =
         (*(byte *)(*(int *)(iVar5 + 0xc) * 0x20 + 7 + DAT_00736198) & bVar2) != 0;
  } while (iVar4 < 0x1f);
  *(undefined4 *)(param_1 + 0x7c) = 0;
  ExceptionList = local_c;
  return;
}


// ==== 0x4368e0 Player::FreeMember960

/* [canon] canon med (ghidra-canon+hopper) docs/re/canon.md */

void Player__FreeMember960(void)

{
  void *pvVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar2 = 0;
  do {
    pvVar1 = *(void **)(unaff_EDI + iVar2 * 4);
    if (pvVar1 != (void *)0x0) {
      _free(pvVar1);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x1f);
  if (DAT_0073618c != (void *)0x0) {
    pvVar1 = (void *)((int)DAT_0073618c + -4);
    eh_vector_destructor_iterator(DAT_0073618c,0x44,*(int *)((int)DAT_0073618c + -4),NullUpdate_ret)
    ;
    _free(pvVar1);
  }
  DAT_0073618c = (void *)0x0;
  DAT_00736190 = 0;
  return;
}


// ==== 0x436940 StyleItemTable::Update

/* [canon] audio med (ghidra-canon) docs/re/canon.md */

void StyleItemTable__Update(int param_1,int param_2,undefined4 param_3)

{
  int ******ppppppiVar1;
  int *****pppppiVar2;
  int *****pppppiVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int ******ppppppiVar9;
  int *****local_14;
  int *****local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00686b38;
  local_c = ExceptionList;
  iVar7 = 0;
  if (DAT_00736194 != 0) {
    DAT_00736194 = 0;
  }
  local_14 = (int *****)&local_14;
  local_10 = (int *****)&local_14;
  local_4 = 0;
  ExceptionList = &local_c;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  do {
    ppppppiVar1 = *(int *******)(param_1 + iVar7 * 4);
    pppppiVar2 = ppppppiVar1[4];
    if (((pppppiVar2 == (int *****)0x0) || ((2 < (int)pppppiVar2 && ((int)pppppiVar2 < 5)))) &&
       (*(char *)(ppppppiVar1 + 0xd) == '\0')) {
      *local_10 = (int ****)ppppppiVar1;
      ppppppiVar1[1] = local_10;
      *ppppppiVar1 = (int *****)&local_14;
      local_10 = (int *****)ppppppiVar1;
    }
    if (((ppppppiVar1[3] == (int *****)0x0) && (cVar4 = FUN_0043a2e0(), cVar4 != '\0')) &&
       ((ppppppiVar1[4] == (int *****)0x3 || (ppppppiVar1[4] == (int *****)0x4)))) {
      iVar6 = (DAT_0073618c << 7) % DAT_00736190;
      iVar5 = iVar6;
      if (iVar6 < 0) {
        iVar5 = -iVar6;
      }
      if (*(float *)(iVar5 * 0x44 + 0x28 + DAT_0073618c) < (float)ppppppiVar1[10]) {
        if (iVar6 < 0) {
          iVar6 = -iVar6;
        }
        piVar8 = (int *)(iVar6 * 0x44 + DAT_0073618c);
        ppppppiVar9 = ppppppiVar1;
        for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {
          *ppppppiVar9 = (int *****)*piVar8;
          piVar8 = piVar8 + 1;
          ppppppiVar9 = ppppppiVar9 + 1;
        }
      }
    }
    if (*(char *)((int)ppppppiVar1 + 0x15) != '\0') {
      iVar5 = _ftol_nocw();
      *(float *)(param_1 + 0x7c) = (float)iVar5 + *(float *)(param_1 + 0x7c);
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x1f);
  if ((int ******)local_14 != &local_14) {
    if ((*(uint *)(*(int *)(param_2 + 0x95c) + 8) & 0x20000) != 0) {
      CunningStuntSpread__UpdateStylePoints(*(undefined4 *)(*(int *)(param_2 + 0x95c) + 0x50));
    }
    while ((int ******)local_14 != &local_14) {
      pppppiVar2 = (int *****)*local_14;
      pppppiVar3 = (int *****)local_14[1];
      *pppppiVar3 = (int ****)pppppiVar2;
      pppppiVar2[1] = (int ****)pppppiVar3;
    }
  }
  iVar7 = 0;
  do {
    iVar5 = *(int *)(*(int *)(param_1 + iVar7 * 4) + 0x10);
    if ((iVar5 == 3) || (iVar5 == 4)) {
      StyleItem__Rearm();
    }
    StyleItem__Update(param_3);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x1f);
  if ((int ******)local_14 != &local_14) {
    do {
      pppppiVar2 = (int *****)*local_14;
      pppppiVar3 = (int *****)local_14[1];
      *pppppiVar3 = (int ****)pppppiVar2;
      pppppiVar2[1] = (int ****)pppppiVar3;
      _free(local_14);
    } while ((int ******)local_14 != &local_14);
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x436b20 StyleItemTable::TriggerItem

/* [canon] audio med (ghidra-canon) docs/re/canon.md */

void __fastcall StyleItemTable__TriggerItem(int param_1)

{
  int in_EAX;
  
  if (*(char *)(*(int *)(in_EAX + param_1 * 4) + 0x14) != '\0') {
    StyleItem__Trigger();
    return;
  }
  return;
}


// ==== 0x436b40 StyleItemTable::FinishItem

/* [canon] runtime med (ghidra-canon) docs/re/canon.md */

void __fastcall StyleItemTable__FinishItem(int param_1)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(in_EAX + param_1 * 4);
  if ((*(char *)(iVar1 + 0x14) != '\0') &&
     ((iVar1 = *(int *)(iVar1 + 0x10), iVar1 == 0 || (iVar1 == 1)))) {
    StyleItem__Finish(1);
  }
  return;
}


// ==== 0x436b60 StyleItemTable::ResetItemLevel

/* [canon] runtime med (ghidra-canon) docs/re/canon.md */

void __fastcall StyleItemTable__ResetItemLevel(int param_1)

{
  int in_EAX;
  
  if (*(char *)(*(int *)(in_EAX + param_1 * 4) + 0x14) != '\0') {
    StyleItem__ResetLevel();
    return;
  }
  return;
}


// ==== 0x436b70 StyleItemTable::FinishAll

/* [canon] unknown med (ghidra-canon) docs/re/canon.md */

void StyleItemTable__FinishAll(void)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar2 = 0;
  do {
    iVar1 = *(int *)(unaff_EDI + iVar2 * 4);
    if (*(char *)(iVar1 + 0x14) != '\0') {
      iVar1 = *(int *)(iVar1 + 0x10);
      if (iVar1 == 0) {
        StyleItem__Cancel(1);
      }
      else if (iVar1 == 1) {
        StyleItem__Finish(1);
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x1f);
  return;
}


// ==== 0x436ba0 StyleSet::RecomputeTotal

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

float10 StyleSet__RecomputeTotal(void)

{
  char in_AL;
  int iVar1;
  int iVar2;
  int unaff_ESI;
  int *piVar3;
  
  if (in_AL != '\0') {
    iVar2 = 0;
    *(undefined4 *)(unaff_ESI + 0x7c) = 0;
    piVar3 = (int *)(unaff_ESI + 8);
    do {
      if ((*(char *)(piVar3[-2] + 0x14) != '\0') && (*(char *)(piVar3[-2] + 0x15) != '\0')) {
        iVar1 = _ftol_nocw();
        *(float *)(unaff_ESI + 0x7c) = (float)iVar1 + *(float *)(unaff_ESI + 0x7c);
      }
      if ((*(char *)(piVar3[-1] + 0x14) != '\0') && (*(char *)(piVar3[-1] + 0x15) != '\0')) {
        iVar1 = _ftol_nocw();
        *(float *)(unaff_ESI + 0x7c) = (float)iVar1 + *(float *)(unaff_ESI + 0x7c);
      }
      if ((*(char *)(*piVar3 + 0x14) != '\0') && (*(char *)(*piVar3 + 0x15) != '\0')) {
        iVar1 = _ftol_nocw();
        *(float *)(unaff_ESI + 0x7c) = (float)iVar1 + *(float *)(unaff_ESI + 0x7c);
      }
      if ((*(char *)(piVar3[1] + 0x14) != '\0') && (*(char *)(piVar3[1] + 0x15) != '\0')) {
        iVar1 = _ftol_nocw();
        *(float *)(unaff_ESI + 0x7c) = (float)iVar1 + *(float *)(unaff_ESI + 0x7c);
      }
      if ((*(char *)(piVar3[2] + 0x14) != '\0') && (*(char *)(piVar3[2] + 0x15) != '\0')) {
        iVar1 = _ftol_nocw();
        *(float *)(unaff_ESI + 0x7c) = (float)iVar1 + *(float *)(unaff_ESI + 0x7c);
      }
      if ((*(char *)(piVar3[3] + 0x14) != '\0') && (*(char *)(piVar3[3] + 0x15) != '\0')) {
        iVar1 = _ftol_nocw();
        *(float *)(unaff_ESI + 0x7c) = (float)iVar1 + *(float *)(unaff_ESI + 0x7c);
      }
      if ((*(char *)(piVar3[4] + 0x14) != '\0') && (*(char *)(piVar3[4] + 0x15) != '\0')) {
        iVar1 = _ftol_nocw();
        *(float *)(unaff_ESI + 0x7c) = (float)iVar1 + *(float *)(unaff_ESI + 0x7c);
      }
      if ((*(char *)(piVar3[5] + 0x14) != '\0') && (*(char *)(piVar3[5] + 0x15) != '\0')) {
        iVar1 = _ftol_nocw();
        *(float *)(unaff_ESI + 0x7c) = (float)iVar1 + *(float *)(unaff_ESI + 0x7c);
      }
      iVar2 = iVar2 + 8;
      piVar3 = piVar3 + 8;
    } while (iVar2 < 0x18);
    for (; iVar2 < 0x1f; iVar2 = iVar2 + 1) {
      iVar1 = *(int *)(unaff_ESI + iVar2 * 4);
      if ((*(char *)(iVar1 + 0x14) != '\0') && (*(char *)(iVar1 + 0x15) != '\0')) {
        iVar1 = _ftol_nocw();
        *(float *)(unaff_ESI + 0x7c) = (float)iVar1 + *(float *)(unaff_ESI + 0x7c);
      }
    }
  }
  return (float10)*(float *)(unaff_ESI + 0x7c);
}


// ==== 0x436d40 std::list::clear__free_every_node__head_in_ESI_

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

void std__list__clear__free_every_node__head_in_ESI_(void)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  int *unaff_ESI;
  
  _Memory = (int *)*unaff_ESI;
  while (_Memory != unaff_ESI) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)*unaff_ESI;
  }
  return;
}


// ==== 0x436d60 bLength3

/* [canon] runtime high (ghidra-canon) docs/re/runtime.md */

float10 bLength3(void)

{
  float *in_EAX;
  
  return SQRT((float10)in_EAX[2] * (float10)in_EAX[2] +
              (float10)in_EAX[1] * (float10)in_EAX[1] + (float10)*in_EAX * (float10)*in_EAX);
}


// ==== 0x436d90 BitStream::ReadBitsValue

/* [canon] online low (ghidra-canon) docs/re/canon.md */

undefined4 BitStream__ReadBitsValue(void)

{
  undefined4 in_EAX;
  
  FUN_005488d0(in_EAX);
  return 0;
}


// ==== 0x436db0 FUN_00436db0

undefined4 FUN_00436db0(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 300);
}


// ==== 0x436dc0 BitStream::WriteFloatRounded

/* [canon] online med (ghidra-canon) docs/re/canon.md */

void BitStream__WriteFloatRounded(void)

{
  undefined4 uVar1;
  
  uVar1 = _ftol_nocw();
  FUN_00548840(uVar1);
  return;
}


// ==== 0x436e20 BitStream::ReadQuantizedFloat

/* [canon] online med (ghidra-canon) docs/re/canon.md */

void BitStream__ReadQuantizedFloat(float *param_1,int param_2)

{
  float10 fVar1;
  
  FUN_005488d0(*(undefined4 *)(param_2 + 300));
  fVar1 = (float10)FUN_00548c30();
  *param_1 = (float)fVar1;
  return;
}


// ==== 0x436e60 BitStream::WriteClampedInt

/* [canon] online med (ghidra-canon) docs/re/canon.md */

void __fastcall BitStream__WriteClampedInt(int param_1)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(in_EAX + 0x130);
  if (param_1 < iVar1) {
    param_1 = iVar1;
  }
  if (*(int *)(in_EAX + 0x134) < param_1) {
    param_1 = *(int *)(in_EAX + 0x134);
  }
  FUN_00548840(param_1 - iVar1);
  return;
}


// ==== 0x436e90 BitStream::ReadQuantizedInt

/* [canon] online low (ghidra-canon) docs/re/canon.md */

void BitStream__ReadQuantizedInt(undefined4 *param_1,int param_2)

{
  FUN_005488d0(*(undefined4 *)(param_2 + 300));
  *param_1 = *(undefined4 *)(param_2 + 0x130);
  return;
}


// ==== 0x436ed0 BitStream::WriteByteBits

/* [canon] online low (ghidra-canon) docs/re/canon.md */

void BitStream__WriteByteBits(void)

{
  undefined1 in_AL;
  
  FUN_00548840(in_AL);
  return;
}


// ==== 0x436ee0 BitStream::ReadBool

/* [canon] online low (ghidra-canon) docs/re/canon.md */

undefined4 BitStream__ReadBool(void)

{
  FUN_005488d0(1);
  return 0;
}


// ==== 0x436f10 BitStream::WriteBitsThunk

/* [canon] online low (ghidra-canon) docs/re/canon.md */

void BitStream__WriteBitsThunk(void)

{
  undefined4 in_EAX;
  
  FUN_00548840(in_EAX);
  return;
}


// ==== 0x436f20 BitStream::ReadU32

/* [canon] online low (ghidra-canon) docs/re/canon.md */

undefined4 BitStream__ReadU32(void)

{
  FUN_005488d0(0x20);
  return 0;
}


// ==== 0x436f40 PidCarController::scalar_deleting_destructor

/* [canon] runtime low (ghidra-canon) docs/re/canon.md */

undefined4 * __thiscall
PidCarController__scalar_deleting_destructor(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_PidCarController__scalar_deleting_destructor_006ca4a4;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x436f60 PidCarController::_PidCarController

/* [canon] runtime med (ghidra-canon+hopper) docs/re/canon.md */

void __fastcall PidCarController___PidCarController(undefined4 *param_1)

{
  *param_1 = &PTR_PidCarController__scalar_deleting_destructor_006ca494;
  param_1[0x96] = &PTR_FUN_006b9694;
  if ((undefined4 *)param_1[0x9a] != param_1 + 0x9b) {
    _free((undefined4 *)param_1[0x9a]);
  }
  param_1[0x96] = &PTR_FUN_006c7d78;
  *param_1 = &PTR_PidCarController__scalar_deleting_destructor_006ca4a4;
  return;
}


// ==== 0x436fa0 PidCarController::scalar_deleting_destructor

/* [canon] runtime low (ghidra-canon) docs/re/canon.md */

void * __thiscall PidCarController__scalar_deleting_destructor(void *param_1,byte param_2)

{
  PidCarController___PidCarController();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x436fc0 AntiTamper::DecodeFloat

/* [canon] runtime med (ghidra-canon) docs/re/canon.md */

void __fastcall AntiTamper__DecodeFloat(undefined4 param_1,float *param_2,uint param_3,int param_4)

{
  uint *in_EAX;
  
  *param_2 = (float)(*in_EAX ^ param_3) - (float)param_4;
  return;
}


// ==== 0x436fe0 FUN_00436fe0

void __fastcall FUN_00436fe0(undefined4 *param_1)

{
  *param_1 = &PTR_PidCarController__scalar_deleting_destructor_006ca4a4;
  return;
}


// ==== 0x436ff0 PidCarController::PidCarController

/* [canon] runtime med (ghidra-canon) docs/re/canon.md */

undefined4 * PidCarController__PidCarController(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  void *pvStack_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  pcStack_18 = FUN_0068690e;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  *param_1 = &PTR_PidCarController__scalar_deleting_destructor_006ca4a4;
  *param_1 = &PTR_PidCarController__scalar_deleting_destructor_006ca494;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x2c] = 0;
  local_14 = 0;
  CameraMoverBase_InitFields(0x3f800000,0x3f800000);
  param_1[0x74] = 0;
  param_1[0x75] = 0;
  param_1[0x76] = 0;
  param_1[0x77] = 0;
  param_1[0x7d] = 0x3f800000;
  param_1[0x7e] = 0x3f800000;
  *(undefined2 *)(param_1 + 0x7f) = 0;
  *(undefined2 *)((int)param_1 + 0x1fe) = 1;
  param_1[0x8d] = 0;
  param_1[0x8f] = 0;
  *(undefined1 *)(param_1 + 0x97) = 4;
  *(undefined1 *)((int)param_1 + 0x25d) = 10;
  *(undefined1 *)((int)param_1 + 0x25e) = 0;
  *(undefined1 *)((int)param_1 + 0x25f) = 0;
  param_1[0x96] = &PTR_FUN_006b9694;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x9a] = param_1 + 0x9b;
  puVar2 = _malloc(0x28);
  param_1[0x9a] = puVar2;
  for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  DAT_00736188 = (uint)DAT_006f3d84;
  param_1[1] = param_2;
  puVar2 = param_1 + 4;
  for (iVar6 = 0x20; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_14._0_1_ = 1;
  if (DAT_007346c4 != 0) {
    param_1[0x28] = 0;
    param_1[0x29] = 0;
    param_1[0x2a] = 0;
    param_1[0x2c] = DAT_0073ad34;
  }
  param_1[0x24] = 0;
  iVar6 = param_1[1];
  if (*(char *)(*(int *)(iVar6 + 0x14) + 0x734) != '\0') {
    if (*(int *)(iVar6 + 0x28) != 3) {
      if (*(undefined4 **)(iVar6 + 0x34) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(iVar6 + 0x34))(1);
      }
      *(undefined4 *)(iVar6 + 0x34) = 0;
      *(undefined4 *)(iVar6 + 0x28) = 3;
      iVar3 = FUN_00567160();
      local_14._0_1_ = 3;
      if (iVar3 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = MellowMover__MellowMover(iVar3,iVar6,*(undefined4 *)(iVar6 + 0x20));
      }
      *(undefined4 *)(iVar6 + 0x34) = uVar4;
      *(undefined4 *)(*(int *)(iVar6 + 0x3c) + 0x60) = 1;
      local_14._0_1_ = 1;
      CarCollisionBody__SetupPhysicsPointers();
      *(undefined4 *)(*(int *)(iVar6 + 0x34) + 4) = *(undefined4 *)(iVar6 + 0x30);
    }
    *(undefined4 *)(*(int *)(param_1[1] + 0x30) + 0x1e4) = 0x3f800000;
  }
  FUN_00439da0();
  iVar6 = param_1[1];
  uVar4 = *(undefined4 *)(iVar6 + 100);
  uVar1 = *(undefined4 *)(iVar6 + 0x68);
  param_1[0x84] = *(undefined4 *)(iVar6 + 0x60);
  param_1[0x85] = uVar4;
  param_1[0x86] = uVar1;
  iVar6 = param_1[1];
  uVar4 = *(undefined4 *)(iVar6 + 0x74);
  uVar1 = *(undefined4 *)(iVar6 + 0x78);
  param_1[0x88] = *(undefined4 *)(iVar6 + 0x70);
  param_1[0x89] = uVar4;
  param_1[0x8a] = uVar1;
  param_1[0x90] = 0;
  param_1[0x91] = 0;
  param_1[0x92] = 0;
  param_1[0x8c] = 0;
  param_1[0x8d] = 0;
  param_1[0x8f] = 0;
  param_1[0x8e] = 0;
  param_1[0x94] = 0x3f800000;
  iVar6 = RaceStatus__FindCurrentEntrant();
  uVar7 = DAT_006f227c % 0x2ac;
  uVar8 = DAT_006f227c ^ 0x1d872b41;
  uVar5 = uVar8 >> 5 ^ uVar8;
  DAT_006f227c = uVar5 << 0x1b ^ uVar5 ^ uVar8;
  param_1[0xa6] = *(int *)(iVar6 + 0x10) * 0xc90 + uVar7 + DAT_00734588;
  iVar6 = _ftol_nocw();
  iVar3 = _ftol_nocw();
  param_1[0xa7] = iVar3 - iVar6;
  param_1[0xa0] =
       *(uint *)param_1[0xa6] ^ (uint)((float)(int)param_1[0xa7] + *(float *)(param_1[1] + 0x60));
  param_1[0xa1] =
       *(uint *)param_1[0xa6] ^ (uint)((float)(int)param_1[0xa7] + *(float *)(param_1[1] + 100));
  param_1[0xa2] =
       *(uint *)param_1[0xa6] ^ (uint)((float)(int)param_1[0xa7] + *(float *)(param_1[1] + 0x68));
  param_1[0x95] = *(uint *)param_1[0xa6] ^ (uint)((float)(int)param_1[0xa7] + 635.0);
  param_1[0xa5] = *(uint *)param_1[0xa6] ^ (uint)(float)(int)param_1[0xa7];
  ExceptionList = pvStack_1c;
  return param_1;
}


// ==== 0x4373d0 RemoteCarState::WriteState

/* [canon] online med (ghidra-canon) docs/re/canon.md */

void __fastcall RemoteCarState__WriteState(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  float fStack00000004;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  float fStack_4;
  
  BitStream__WriteFloatRounded(*(undefined4 *)(*(int *)(param_1 + 4) + 0x60));
  BitStream__WriteFloatRounded(*(undefined4 *)(*(int *)(param_1 + 4) + 100));
  BitStream__WriteFloatRounded(*(undefined4 *)(*(int *)(param_1 + 4) + 0x68));
  BitStream__WriteFloatRounded(*(undefined4 *)(*(int *)(param_1 + 4) + 0x70));
  BitStream__WriteFloatRounded(*(undefined4 *)(*(int *)(param_1 + 4) + 0x74));
  BitStream__WriteFloatRounded(*(undefined4 *)(*(int *)(param_1 + 4) + 0x78));
  FUN_00566bf0();
  BitStream__WriteFloatRounded(uStack_10);
  BitStream__WriteFloatRounded(uStack_c);
  BitStream__WriteFloatRounded(uStack_8);
  BitStream__WriteFloatRounded(-fStack_4);
  BitStream__WriteFloatRounded(*(undefined4 *)(*(int *)(param_1 + 4) + 0xd0));
  BitStream__WriteFloatRounded(*(undefined4 *)(*(int *)(param_1 + 4) + 0xd4));
  BitStream__WriteFloatRounded(*(undefined4 *)(*(int *)(param_1 + 4) + 0xd8));
  FUN_00548840((uint)*(ushort *)(*(int *)(param_1 + 4) + 0x3b4) << 0x10);
  FUN_00548840(*(undefined2 *)(*(int *)(*(int *)(param_1 + 4) + 0x30) + 0x1d0));
  uVar1 = CarState__IsNitrousOn();
  FUN_00548840(uVar1);
  BitStream__WriteFloatRounded(*(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0x30) + 0x1dc));
  BitStream__WriteFloatRounded(*(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0x30) + 0x1e4));
  BitStream__WriteFloatRounded(*(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0x30) + 0x1e0));
  if (DAT_007000e4 == 100.0) {
    fStack00000004 = *(float *)(*(int *)(param_1 + 4) + 0x3e0);
  }
  else {
    fStack00000004 = DAT_007000e4;
  }
  BitStream__WriteFloatRounded(fStack00000004);
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x3d8);
  if (iVar2 < DAT_0077c758) {
    iVar2 = DAT_0077c758;
  }
  if (DAT_0077c75c < iVar2) {
    iVar2 = DAT_0077c75c;
  }
  FUN_00548840(iVar2 - DAT_0077c758);
  return;
}


// ==== 0x4375e0 RemoteCarState::ApplyState

/* WARNING: Removing unreachable block (ram,0x00437bff) */
/* WARNING: Removing unreachable block (ram,0x00437b33) */
/* WARNING: Removing unreachable block (ram,0x00437a02) */
/* WARNING: Removing unreachable block (ram,0x00437936) */
/* WARNING: Removing unreachable block (ram,0x0043786a) */
/* WARNING: Removing unreachable block (ram,0x0043779e) */
/* WARNING: Removing unreachable block (ram,0x004376d2) */
/* WARNING: Removing unreachable block (ram,0x00437738) */
/* WARNING: Removing unreachable block (ram,0x00437804) */
/* WARNING: Removing unreachable block (ram,0x004378d0) */
/* WARNING: Removing unreachable block (ram,0x0043799c) */
/* WARNING: Removing unreachable block (ram,0x00437a68) */
/* WARNING: Removing unreachable block (ram,0x00437b99) */
/* WARNING: Removing unreachable block (ram,0x00437c65) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] online med (ghidra-canon) docs/re/canon.md */

void __thiscall RemoteCarState__ApplyState(int param_1,undefined4 param_2,float param_3)

{
  undefined4 uVar1;
  float fVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 auStack_60 [23];
  
  if (param_3 <= *(float *)(param_1 + 0x78)) {
    return;
  }
  if (param_3 < (float)*(int *)(param_1 + 0x234) * 0.00025) {
    return;
  }
  *(float *)(param_1 + 0x78) = param_3;
  *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
  uVar4 = _ftol_nocw();
  *(undefined4 *)(param_1 + 0x94) = uVar4;
  FUN_00584270((float)*(int *)(param_1 + 0x94));
  BitStream__ReadQuantizedFloat(param_1 + 0x10,&DAT_0077ba7c);
  BitStream__ReadQuantizedFloat(param_1 + 0x14,&DAT_0077bbc8);
  BitStream__ReadQuantizedFloat(param_1 + 0x18,&DAT_0077bd14);
  FUN_005488d0(DAT_0077bf8c);
  fVar2 = _DAT_0077bf9c * 0.0 + _DAT_0077bf90;
  if (fVar2 < _DAT_0077bf90) {
    fVar2 = _DAT_0077bf90;
  }
  if (_DAT_0077bf94 < fVar2) {
    fVar2 = _DAT_0077bf94;
  }
  *(float *)(param_1 + 0x20) = fVar2;
  FUN_005488d0(DAT_0077bf8c);
  fVar2 = _DAT_0077bf9c * 0.0 + _DAT_0077bf90;
  if (fVar2 < _DAT_0077bf90) {
    fVar2 = _DAT_0077bf90;
  }
  if (_DAT_0077bf94 < fVar2) {
    fVar2 = _DAT_0077bf94;
  }
  *(float *)(param_1 + 0x24) = fVar2;
  FUN_005488d0(DAT_0077bf8c);
  fVar2 = _DAT_0077bf9c * 0.0 + _DAT_0077bf90;
  if (fVar2 < _DAT_0077bf90) {
    fVar2 = _DAT_0077bf90;
  }
  if (_DAT_0077bf94 < fVar2) {
    fVar2 = _DAT_0077bf94;
  }
  *(float *)(param_1 + 0x28) = fVar2;
  FUN_005488d0(DAT_0077c0d8);
  fVar2 = _DAT_0077c0e8 * 0.0 + _DAT_0077c0dc;
  if (fVar2 < _DAT_0077c0dc) {
    fVar2 = _DAT_0077c0dc;
  }
  if (_DAT_0077c0e0 < fVar2) {
    fVar2 = _DAT_0077c0e0;
  }
  *(float *)(param_1 + 0x30) = fVar2;
  FUN_005488d0(DAT_0077c0d8);
  fVar2 = _DAT_0077c0e8 * 0.0 + _DAT_0077c0dc;
  if (fVar2 < _DAT_0077c0dc) {
    fVar2 = _DAT_0077c0dc;
  }
  if (_DAT_0077c0e0 < fVar2) {
    fVar2 = _DAT_0077c0e0;
  }
  *(float *)(param_1 + 0x34) = fVar2;
  FUN_005488d0(DAT_0077c0d8);
  fVar2 = _DAT_0077c0e8 * 0.0 + _DAT_0077c0dc;
  if (fVar2 < _DAT_0077c0dc) {
    fVar2 = _DAT_0077c0dc;
  }
  if (_DAT_0077c0e0 < fVar2) {
    fVar2 = _DAT_0077c0e0;
  }
  *(float *)(param_1 + 0x38) = fVar2;
  FUN_005488d0(DAT_0077c0d8);
  fVar2 = _DAT_0077c0e8 * 0.0 + _DAT_0077c0dc;
  if (fVar2 < _DAT_0077c0dc) {
    fVar2 = _DAT_0077c0dc;
  }
  if (_DAT_0077c0e0 < fVar2) {
    fVar2 = _DAT_0077c0e0;
  }
  *(float *)(param_1 + 0x3c) = fVar2;
  FUN_005488d0(DAT_0077c370);
  fVar2 = _DAT_0077c380 * 0.0 + _DAT_0077c374;
  if (fVar2 < _DAT_0077c374) {
    fVar2 = _DAT_0077c374;
  }
  if (_DAT_0077c378 < fVar2) {
    fVar2 = _DAT_0077c378;
  }
  *(float *)(param_1 + 0x40) = fVar2;
  FUN_005488d0(DAT_0077c370);
  fVar2 = _DAT_0077c380 * 0.0 + _DAT_0077c374;
  if (fVar2 < _DAT_0077c374) {
    fVar2 = _DAT_0077c374;
  }
  if (_DAT_0077c378 < fVar2) {
    fVar2 = _DAT_0077c378;
  }
  *(float *)(param_1 + 0x44) = fVar2;
  FUN_005488d0(DAT_0077c370);
  fVar2 = _DAT_0077c380 * 0.0 + _DAT_0077c374;
  if (fVar2 < _DAT_0077c374) {
    fVar2 = _DAT_0077c374;
  }
  if (_DAT_0077c378 < fVar2) {
    fVar2 = _DAT_0077c378;
  }
  *(float *)(param_1 + 0x48) = fVar2;
  FUN_005488d0(0x20);
  *(undefined4 *)(param_1 + 0x60) = 0;
  FUN_005488d0(0x20);
  *(undefined2 *)(param_1 + 100) = 0;
  FUN_005488d0(1);
  *(undefined1 *)(param_1 + 0x74) = 0;
  FUN_005488d0(DAT_0077c4bc);
  fVar2 = _DAT_0077c4cc * 0.0 + _DAT_0077c4c0;
  if (fVar2 < _DAT_0077c4c0) {
    fVar2 = _DAT_0077c4c0;
  }
  if (_DAT_0077c4c4 < fVar2) {
    fVar2 = _DAT_0077c4c4;
  }
  *(float *)(param_1 + 0x6c) = fVar2;
  FUN_005488d0(DAT_0077c4bc);
  fVar2 = _DAT_0077c4cc * 0.0 + _DAT_0077c4c0;
  if (fVar2 < _DAT_0077c4c0) {
    fVar2 = _DAT_0077c4c0;
  }
  if (_DAT_0077c4c4 < fVar2) {
    fVar2 = _DAT_0077c4c4;
  }
  *(float *)(param_1 + 0x68) = fVar2;
  FUN_005488d0(DAT_0077c4bc);
  fVar2 = _DAT_0077c4cc * 0.0 + _DAT_0077c4c0;
  if (fVar2 < _DAT_0077c4c0) {
    fVar2 = _DAT_0077c4c0;
  }
  if (_DAT_0077c4c4 < fVar2) {
    fVar2 = _DAT_0077c4c4;
  }
  *(float *)(param_1 + 0x70) = fVar2;
  FUN_005488d0(DAT_0077c608);
  fVar2 = _DAT_0077c618 * 0.0 + _DAT_0077c60c;
  if (fVar2 < _DAT_0077c60c) {
    fVar2 = _DAT_0077c60c;
  }
  if (_DAT_0077c610 < fVar2) {
    fVar2 = _DAT_0077c610;
  }
  *(float *)(param_1 + 0x7c) = fVar2;
  FUN_005488d0(DAT_0077c754);
  *(undefined4 *)(param_1 + 0x80) = DAT_0077c758;
  if (*(int *)(param_1 + 0x90) == 0) {
    if (DAT_00736188 != 0) {
      CarTracker_CapturePosVel();
    }
    *(undefined4 *)(param_1 + 0x90) = 1;
  }
  if (*(char *)(param_1 + 0x74) != '\0') {
    cVar3 = CarState__IsNitrousOn();
    if (cVar3 == '\0') {
      FUN_004654f0();
      goto LAB_00437d4f;
    }
    if (*(char *)(param_1 + 0x74) != '\0') goto LAB_00437d4f;
  }
  cVar3 = CarState__IsNitrousOn();
  if (cVar3 != '\0') {
    CarState__StopNitrous();
  }
LAB_00437d4f:
  iVar6 = *(int *)(param_1 + 4);
  param_3 = _DAT_006f0898 - param_3;
  FUN_00483160(*(undefined4 *)(iVar6 + 0x60),*(undefined4 *)(iVar6 + 100),
               *(undefined4 *)(iVar6 + 0x68));
  iVar6 = *(int *)(param_1 + 4);
  FUN_00593bc0(*(undefined4 *)(iVar6 + 0x70),*(undefined4 *)(iVar6 + 0x74),
               *(undefined4 *)(iVar6 + 0x78));
  *(undefined4 *)(param_1 + 0x164) = 0x3e4ccccd;
  *(undefined4 *)(param_1 + 0x194) = 0x3e4ccccd;
  *(undefined4 *)(param_1 + 0x1c4) = 0x3e4ccccd;
  FUN_00566bf0();
  *(float *)(param_1 + 0x200) = -*(float *)(param_1 + 0x20c);
  *(undefined4 *)(param_1 + 0x238) = 0;
  Car_SetMode();
  iVar6 = *(int *)(param_1 + 4);
  uVar4 = *(undefined4 *)(param_1 + 0x18);
  uVar1 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(iVar6 + 100) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(iVar6 + 0x60) = uVar1;
  *(undefined4 *)(iVar6 + 0x68) = uVar4;
  FUN_00566b10();
  bMatrixCopy_b();
  FUN_00465390();
  RigidBody__SetVelocity();
  iVar6 = *(int *)(param_1 + 4);
  *(float *)(iVar6 + 0x3d0) =
       *(float *)(iVar6 + 0x90) * *(float *)(param_1 + 0x20) +
       *(float *)(iVar6 + 0x94) * *(float *)(param_1 + 0x24) +
       *(float *)(iVar6 + 0x98) * *(float *)(param_1 + 0x28);
  iVar6 = *(int *)(param_1 + 4);
  uVar4 = *(undefined4 *)(param_1 + 0x48);
  uVar1 = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(iVar6 + 0xd4) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(iVar6 + 0xd0) = uVar1;
  *(undefined4 *)(iVar6 + 0xd8) = uVar4;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x3d8) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x3e0) = *(undefined4 *)(param_1 + 0x7c);
  Car__SyncWheelsToSpeed(param_3);
  Car_SetMode();
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 0x30);
  *(undefined4 *)(iVar6 + 0x1dc) = *(undefined4 *)(param_1 + 0x6c);
  *(undefined4 *)(iVar6 + 0x1e4) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(iVar6 + 0x1e0) = *(undefined4 *)(param_1 + 0x70);
  *(short *)(iVar6 + 0x1d0) =
       (short)(((int)*(short *)(param_1 + 100) + (int)*(short *)(iVar6 + 0x1d0)) / 2);
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 0x34) + 8) + 4))();
  iVar6 = *(int *)(param_1 + 4);
  puVar8 = (undefined4 *)(iVar6 + 0x300);
  iVar5 = 0;
  puVar7 = puVar8;
  do {
    auStack_60[iVar5] = *puVar7;
    iVar5 = iVar5 + 1;
    puVar7 = puVar7 + 1;
  } while (iVar5 < 4);
  if (param_3 <= 0.0) {
    _DAT_0078eb5c = _DAT_0078eb5c + 1;
  }
  else {
    (**(code **)(**(int **)(iVar6 + 0x3c) + 0x28))(param_3);
  }
  iVar6 = 0;
  do {
    puVar7 = auStack_60 + iVar6;
    iVar6 = iVar6 + 1;
    *puVar8 = *puVar7;
    puVar8 = puVar8 + 1;
  } while (iVar6 < 4);
  return;
}


// ==== 0x437fa0 RemoteCarState::ClearStaleInput

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] online med (ghidra-canon+hopper) docs/re/canon.md */

void RemoteCarState__ClearStaleInput(int param_1)

{
  int iVar1;
  
  if (4.0 < _DAT_006f0898 - *(float *)(param_1 + 0x78)) {
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x30);
    *(undefined4 *)(iVar1 + 0x1dc) = 0;
    *(undefined4 *)(iVar1 + 0x1e4) = 0;
    *(undefined4 *)(iVar1 + 0x1e0) = 0;
    *(undefined2 *)(iVar1 + 0x1d0) = 0;
  }
  return;
}


// ==== 0x437fe0 CarTracker_CapturePosVel

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

void CarTracker_CapturePosVel(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_EAX;
  
  iVar3 = *(int *)(in_EAX + 4);
  uVar1 = *(undefined4 *)(iVar3 + 100);
  uVar2 = *(undefined4 *)(iVar3 + 0x68);
  *(undefined4 *)(in_EAX + 0x210) = *(undefined4 *)(iVar3 + 0x60);
  *(undefined4 *)(in_EAX + 0x214) = uVar1;
  *(undefined4 *)(in_EAX + 0x218) = uVar2;
  iVar3 = *(int *)(in_EAX + 4);
  uVar1 = *(undefined4 *)(iVar3 + 0x74);
  uVar2 = *(undefined4 *)(iVar3 + 0x78);
  *(undefined4 *)(in_EAX + 0x220) = *(undefined4 *)(iVar3 + 0x70);
  *(undefined4 *)(in_EAX + 0x224) = uVar1;
  *(undefined4 *)(in_EAX + 0x228) = uVar2;
  *(undefined4 *)(in_EAX + 0x238) = 1;
  return;
}


// ==== 0x438030 RemoteCarState::SmoothPosition

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] online med (ghidra-canon) docs/re/canon.md */

int * RemoteCarState__SmoothPosition(float param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int in_EAX;
  int *piVar11;
  float10 fVar12;
  float10 fVar13;
  float local_30;
  float local_2c;
  float local_28;
  
  piVar11 = DAT_0073619c;
  if ((*DAT_0073619c == 4) &&
     (piVar11 = (int *)Race__AreAllPlayersFinishedRacing(DAT_0073619c), piVar11 == (int *)0x0)) {
    iVar4 = *(int *)(in_EAX + 4);
    piVar11 = *(int **)(iVar4 + 0x14);
    if (((char)piVar11[0x1cd] != '\0') &&
       ((piVar11 = (int *)0x0, *(int *)(in_EAX + 0x90) != 0 &&
        (piVar11 = (int *)0x0, DAT_00736188 != 0)))) {
      if (*(int *)(in_EAX + 0x238) == 0) {
        FUN_005674d0(param_1 * *(float *)(in_EAX + 0x250));
        fVar7 = (*(float *)(iVar4 + 0x60) - local_30) * 0.1 + local_30;
        fVar5 = (*(float *)(iVar4 + 100) - local_2c) * 0.1 + local_2c;
        fVar6 = (*(float *)(iVar4 + 0x68) - local_28) * 0.1 + local_28;
        if (1e-05 < param_1) {
          param_1 = _K_ONE / param_1;
          *(float *)(in_EAX + 0x220) = (fVar7 - *(float *)(in_EAX + 0x210)) * param_1;
          *(float *)(in_EAX + 0x224) = (fVar5 - *(float *)(in_EAX + 0x214)) * param_1;
          *(float *)(in_EAX + 0x228) = (fVar6 - *(float *)(in_EAX + 0x218)) * param_1;
        }
        iVar4 = *(int *)(in_EAX + 4);
        *(undefined4 *)(in_EAX + 0x250) = 0x3f800000;
        fVar8 = fVar7 - *(float *)(iVar4 + 0x60);
        fVar9 = fVar5 - *(float *)(iVar4 + 100);
        fVar10 = fVar6 - *(float *)(iVar4 + 0x68);
        if (0.0 < fVar8 * *(float *)(in_EAX + 0x240) +
                  fVar10 * *(float *)(in_EAX + 0x248) + fVar9 * *(float *)(in_EAX + 0x244)) {
          fVar12 = (float10)bLength3();
          if ((float10)0.1 * (float10)0.2 < fVar12) {
            fVar13 = (float10)bLength3();
            fVar12 = ((float10)(float)fVar12 - fVar13) / (float10)(float)fVar12;
            fVar1 = (float)fVar12;
            if (((float10)0.0 < fVar12) && (fVar1 < _K_ONE)) {
              *(float *)(in_EAX + 0x250) = _K_ONE - fVar1;
            }
          }
        }
        *(float *)(in_EAX + 0x248) = fVar10;
        *(float *)(in_EAX + 0x240) = fVar8;
        *(float *)(in_EAX + 0x244) = fVar9;
        *(float *)(in_EAX + 0x218) = fVar6;
        *(float *)(in_EAX + 0x210) = fVar7;
        *(float *)(in_EAX + 0x214) = fVar5;
        fVar12 = (float10)bLength3();
        if ((float10)0.1 <= fVar12) {
          if (fVar10 < 0.0) {
            *(undefined4 *)(in_EAX + 0x218) = *(undefined4 *)(*(int *)(in_EAX + 4) + 0x68);
          }
          piVar11 = (int *)Vec3_TransformSub();
          return piVar11;
        }
        CarTracker_CapturePosVel();
        piVar11 = (int *)Vec3_TransformSub();
        return piVar11;
      }
      uVar2 = *(undefined4 *)(iVar4 + 100);
      uVar3 = *(undefined4 *)(iVar4 + 0x68);
      *(undefined4 *)(in_EAX + 0x210) = *(undefined4 *)(iVar4 + 0x60);
      *(undefined4 *)(in_EAX + 0x214) = uVar2;
      *(undefined4 *)(in_EAX + 0x218) = uVar3;
      iVar4 = *(int *)(in_EAX + 4);
      uVar2 = *(undefined4 *)(iVar4 + 0x74);
      uVar3 = *(undefined4 *)(iVar4 + 0x78);
      piVar11 = (int *)(iVar4 + 0x70);
      *(undefined4 *)(in_EAX + 0x220) = *(undefined4 *)(iVar4 + 0x70);
      *(undefined4 *)(in_EAX + 0x224) = uVar2;
      *(undefined4 *)(in_EAX + 0x228) = uVar3;
    }
  }
  return piVar11;
}


// ==== 0x438300 RemoteCarState::DelayNextApply

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] online low (ghidra-canon) docs/re/canon.md */

void RemoteCarState__DelayNextApply(float param_1)

{
  int iVar1;
  int unaff_ESI;
  
  if (_DAT_00700a58 < param_1) {
    CarTracker_CapturePosVel();
    iVar1 = _ftol_nocw();
    *(int *)(unaff_ESI + 0x234) = iVar1 + DAT_0073ad34;
    *(int *)(unaff_ESI + 0x23c) = DAT_0073ad34 + 10000;
  }
  return;
}


// ==== 0x438390 Car::SyncWheelsToSpeed

/* [canon] car med (ghidra-canon) docs/re/canon.md */

void Car__SyncWheelsToSpeed(void)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  int in_EAX;
  undefined4 *puVar5;
  undefined4 *puVar6;
  float *pfVar7;
  char *pcVar8;
  int iVar9;
  int local_4;
  
  iVar4 = *(int *)(in_EAX + 4);
  fVar1 = *(float *)(iVar4 + 0x3d0);
  pfVar7 = (float *)(*(int *)(iVar4 + 0x20) + 0x20);
  pcVar8 = (char *)(iVar4 + 0x350);
  puVar6 = (undefined4 *)(iVar4 + 0x374);
  puVar5 = (undefined4 *)(iVar4 + 0x340);
  local_4 = 4;
  do {
    fVar2 = *pfVar7;
    *puVar5 = 0;
    puVar5[-0x14] = fVar1 / fVar2;
    *puVar6 = 0;
    puVar6[1] = 0;
    puVar5[0x15] = 0;
    puVar5[-0xc] = 0;
    *(undefined4 *)(iVar4 + 0x330) = 0;
    *(undefined4 *)(iVar4 + 0x334) = 0;
    *(undefined4 *)(iVar4 + 0x338) = 0;
    *(undefined4 *)(iVar4 + 0x33c) = 0;
    cVar3 = *pcVar8;
    *pcVar8 = '\x01';
    if (cVar3 == '\0') {
      *(int *)(iVar4 + 0x3cc) = *(int *)(iVar4 + 0x3cc) + 1;
    }
    puVar5[5] = 1;
    if ((int)puVar5[9] < 1) {
      puVar5[9] = 1;
    }
    puVar5 = puVar5 + 1;
    pfVar7 = pfVar7 + 0xc;
    puVar6 = puVar6 + 2;
    pcVar8 = pcVar8 + 1;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  iVar9 = 0;
  do {
    FUN_00465150(iVar4 + 0x40);
    iVar9 = iVar9 + 1;
  } while (iVar9 < 4);
  return;
}


// ==== 0x438440 RemoteCarState::AntiCheatCheck

/* [canon] online med (ghidra-canon) docs/re/canon.md */

void RemoteCarState__AntiCheatCheck(float param_1)

{
  float fVar1;
  uint *puVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int unaff_ESI;
  uint uVar11;
  float10 fVar12;
  float local_28;
  
  if (DAT_0077b240 != 6) {
    return;
  }
  iVar6 = Race__GetPlayer((int)*(short *)(*(int *)(unaff_ESI + 4) + 10));
  if (*(float *)(unaff_ESI + 0x254) == 0.0) {
    local_28 = (float)(**(uint **)(unaff_ESI + 0x298) ^ *(uint *)(unaff_ESI + 0x294)) -
               (float)*(int *)(unaff_ESI + 0x29c);
    if ((*(char *)(unaff_ESI + 0x74) != '\0') || (cVar5 = CarState__IsNitrousOn(), cVar5 != '\0')) {
      local_28 = local_28 + param_1;
      iVar7 = *(int *)(*(int *)(unaff_ESI + 4) + 0x3f0);
      if ((iVar7 == 0) || (iVar7 == 0x7fffffff)) {
        fVar1 = 0.0;
      }
      else {
        fVar1 = (float)*(int *)(*(int *)(unaff_ESI + 4) + 0x3f0) * 0.00025;
      }
      if (fVar1 + 0.75 < local_28) {
        FUN_004399a0(8);
        iVar7 = *(int *)(*(int *)(unaff_ESI + 4) + 0x14);
        if ((*(int *)(iVar7 + 4) == 1) && (*(char *)(iVar7 + 0x734) == '\0')) {
          FUN_0043a830();
        }
      }
    }
    fVar1 = *(float *)(*(int *)(unaff_ESI + 4) + 0x3d0);
    fVar12 = (float10)RideInfo__GetTheoreticalTopSpeed();
    if (fVar12 * (float10)1.15 < (float10)fVar1) {
      FUN_004399a0(8);
      iVar7 = *(int *)(*(int *)(unaff_ESI + 4) + 0x14);
      if ((*(int *)(iVar7 + 4) == 1) && (*(char *)(iVar7 + 0x734) == '\0')) {
        FUN_0043a830();
      }
    }
    fVar1 = (float)*(int *)(unaff_ESI + 0x29c);
    uVar8 = **(uint **)(unaff_ESI + 0x298);
    if (*DAT_0073619c == 4) {
      iVar7 = *(int *)(unaff_ESI + 4);
      if ((((*(int *)(*(int *)(iVar7 + 0x14) + 4) == 1) &&
           (*(char *)(*(int *)(iVar7 + 0x14) + 0x734) == '\0')) ||
          (*(float *)(unaff_ESI + 0x264) < 250.0)) &&
         (fVar3 = ((float)(*(uint *)(unaff_ESI + 0x280) ^ uVar8) - fVar1) - *(float *)(iVar7 + 0x60)
         , fVar4 = ((float)(*(uint *)(unaff_ESI + 0x284) ^ uVar8) - fVar1) - *(float *)(iVar7 + 100)
         , fVar1 = ((float)(*(uint *)(unaff_ESI + 0x288) ^ uVar8) - fVar1) -
                   *(float *)(iVar7 + 0x68),
         100.0 < SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar1 * fVar1))) {
        FUN_004399a0(8);
        iVar7 = RacerNode__IsLocalHuman();
        if (iVar7 != 0) {
          FUN_0043a830();
        }
      }
    }
    if (((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) && (10000.0 < (float)*(int *)(iVar6 + 0x10))
       ) {
      FUN_004399a0(0x10);
      iVar6 = RacerNode__IsLocalHuman();
      if (iVar6 != 0) {
        FUN_0043a830();
      }
    }
    iVar7 = RaceStatus__FindCurrentEntrant();
    uVar10 = DAT_006f227c % 0x2ac;
    uVar11 = DAT_006f227c ^ 0x1d872b41;
    uVar8 = uVar11 >> 5 ^ uVar11;
    DAT_006f227c = uVar8 << 0x1b ^ uVar8 ^ uVar11;
    iVar6 = *(int *)(unaff_ESI + 4);
    *(uint *)(unaff_ESI + 0x298) = *(int *)(iVar7 + 0x10) * 0xc90 + uVar10 + DAT_00734588;
    iVar7 = _ftol_nocw();
    iVar9 = _ftol_nocw();
    *(int *)(unaff_ESI + 0x29c) = iVar9 - iVar7;
    puVar2 = *(uint **)(unaff_ESI + 0x298);
    *(uint *)(unaff_ESI + 0x280) =
         *puVar2 ^ (uint)((float)(iVar9 - iVar7) + *(float *)(iVar6 + 0x60));
    *(uint *)(unaff_ESI + 0x284) =
         *puVar2 ^ (uint)((float)*(int *)(unaff_ESI + 0x29c) + *(float *)(iVar6 + 100));
    *(uint *)(unaff_ESI + 0x288) =
         *puVar2 ^ (uint)((float)*(int *)(unaff_ESI + 0x29c) + *(float *)(iVar6 + 0x68));
    *(uint *)(unaff_ESI + 0x294) = *puVar2 ^ (uint)((float)*(int *)(unaff_ESI + 0x29c) + local_28);
    *(uint *)(unaff_ESI + 0x254) = *puVar2 ^ (uint)((float)*(int *)(unaff_ESI + 0x29c) + 635.0);
    return;
  }
  FUN_004399a0(0x20);
  FUN_0043a830();
  return;
}


// ==== 0x4387e0 Float_Truncate

/* [canon] runtime med (ghidra-canon) docs/re/canon.md */

float10 __fastcall Float_Truncate(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _ftol_nocw(param_1);
  return (float10)iVar1;
}


// ==== 0x438800 bCeil

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

float10 bCeil(float param_1)

{
  int iVar1;
  undefined4 local_8;
  
  iVar1 = _ftol_nocw();
  local_8 = (float)iVar1;
  if (local_8 < param_1) {
    local_8 = local_8 + _K_ONE;
  }
  return (float10)local_8;
}


// ==== 0x438840 int_NotEqual

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

bool __thiscall int_NotEqual(int *param_1,int *param_2)

{
  return *param_1 != *param_2;
}


// ==== 0x438860 PtrSlots::PtrSlots

/* [canon] runtime low (ghidra-canon) docs/re/canon.md */

int __fastcall PtrSlots__PtrSlots(int param_1)

{
  Ptr_SetNull();
  Ptr_SetNull();
  CallNTimes(param_1 + 0x20,4,0xb,Ptr_SetNull);
  CallNTimes(param_1 + 0x4c,4,0xb,Ptr_SetNull);
  Ptr_SetNull();
  Ptr_SetNull();
  return param_1;
}


// ==== 0x4388d0 BitStream::GetSizeInBytes

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] online med (ghidra-canon) docs/re/canon.md */

void BitStream__GetSizeInBytes(void)

{
  _ftol_nocw();
  _ftol_nocw();
  return;
}


// ==== 0x438920 Float2_ToIntPair

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] runtime low (ghidra-canon) docs/re/runtime.md */

void Float2_ToIntPair(void)

{
  _ftol_nocw();
  _ftol_nocw();
  return;
}


// ==== 0x438980 BitStream::ReadRangedInt

/* [canon] online med (ghidra-canon) docs/re/canon.md */

void BitStream__ReadRangedInt(void)

{
  FUN_00436db0();
  BitStream__ReadBitsValue();
  FUN_005491b0();
  return;
}


// ==== 0x4389b0 BitStream::WriteByte

/* [canon] online low (ghidra-canon) docs/re/canon.md */

void BitStream__WriteByte(undefined1 param_1)

{
  FUN_00548840(param_1);
  return;
}


// ==== 0x4389e0 BitStream::ReadByte

/* [canon] online low (ghidra-canon) docs/re/canon.md */

void BitStream__ReadByte(void)

{
  BitStream__ReadBitsValue();
  return;
}


// ==== 0x438a00 BitStream::WriteShort

/* [canon] online low (ghidra-canon) docs/re/canon.md */

void BitStream__WriteShort(short param_1)

{
  FUN_00548840((int)param_1);
  return;
}


// ==== 0x438a30 bFree_Thunk

/* [canon] runtime low (ghidra-canon) docs/re/canon.md */

void bFree_Thunk(void)

{
  FUN_00565ce0();
  return;
}


// ==== 0x438a40 Obj_GetByte4

/* [canon] runtime med (ghidra-canon) docs/re/canon.md */

undefined1 __fastcall Obj_GetByte4(int param_1)

{
  return *(undefined1 *)(param_1 + 4);
}


// ==== 0x438a60 Obj_GetByte19

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

undefined1 __fastcall Obj_GetByte19(int param_1)

{
  return *(undefined1 *)(param_1 + 0x19);
}


// ==== 0x438a80 Race::HasPlayer

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

bool __thiscall Race__HasPlayer(int param_1,int param_2)

{
  return *(int *)(param_1 + 8 + param_2 * 4) != 0;
}


// ==== 0x438aa0 Obj_GetField830

/* [canon] runtime med (ghidra-canon) docs/re/canon.md */

undefined4 __fastcall Obj_GetField830(int param_1)

{
  return *(undefined4 *)(param_1 + 0x830);
}


// ==== 0x438ac0 Obj_GetField34

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

undefined4 __fastcall Obj_GetField34(int param_1)

{
  return *(undefined4 *)(param_1 + 0x34);
}


// ==== 0x438ae0 GetNetModeCode

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

undefined1 GetNetModeCode(void)

{
  char cVar1;
  undefined1 local_5;
  
  local_5 = 5;
  cVar1 = FUN_00452d10(&DAT_0078e948);
  if (cVar1 != '\0') {
    local_5 = 6;
  }
  return local_5;
}


// ==== 0x438b10 Counter_7354e0_IsPositive

/* [canon] car low (ghidra-canon) docs/re/car.md */

bool Counter_7354e0_IsPositive(void)

{
  return 0 < DAT_007354e0;
}


// ==== 0x438b30 Counter_735500_IsPositive

/* [canon] car low (ghidra-canon) docs/re/car.md */

bool Counter_735500_IsPositive(void)

{
  return 0 < DAT_00735500;
}


// ==== 0x438b50 Flag_73014c_Get

/* [canon] car low (ghidra-canon) docs/re/car.md */

undefined1 Flag_73014c_Get(void)

{
  return DAT_0073014c;
}


// ==== 0x438b60 Career_ComputeCashAfterRace

/* [canon] car med (ghidra-canon) docs/re/car.md */

undefined4
Career_ComputeCashAfterRace
          (uint param_1,char param_2,uint param_3,byte param_4,byte param_5,char param_6,
          ushort param_7)

{
  undefined4 uVar1;
  double local_1c;
  double local_14;
  double local_c;
  
  local_14 = 0.0;
  local_1c = 1.0;
  if (param_2 != '\x01') {
    if (param_2 == '\x02') {
      if (param_4 == 2) {
        local_14 = -((double)param_1 * 0.1);
      }
      else if (2 < param_4) {
        local_14 = 0.0;
      }
    }
    else if (param_2 == '\x03') {
      if (param_4 == 3) {
        local_14 = (double)param_1 * 0.1;
      }
      else {
        local_14 = (double)param_1 * 0.05;
      }
      local_14 = -local_14;
    }
    else {
      local_14 = -((double)param_1 * 0.1);
    }
    goto LAB_00438d8d;
  }
  local_14 = (double)param_3 * 0.1;
  if (10000.0 < local_14) {
    local_14 = 10000.0;
  }
  if ((param_6 == '\0') || (param_6 == '\x03')) {
    if (param_5 == 3) {
      local_1c = 1.1;
    }
    else if (3 < param_5) {
      local_1c = ((double)param_5 - 4.0) * 0.5 + 0.2 + 1.0;
    }
  }
  if (param_6 == '\x02') goto switchD_00438c80_caseD_3ee;
  if (param_7 < 0x456) {
    if (param_7 < 0x454) {
      switch(param_7) {
      case 0x3e9:
      case 0x3ea:
        goto switchD_00438c80_caseD_3e9;
      case 0x3eb:
      case 0x44f:
        break;
      case 0x3ec:
      case 0x3ed:
      case 0x450:
      case 0x451:
      case 0x452:
        goto switchD_00438c80_caseD_3ec;
      default:
        goto switchD_00438c80_caseD_3ee;
      case 0x453:
        goto switchD_00438c80_caseD_453;
      }
    }
switchD_00438c80_caseD_3eb:
    local_1c = local_1c + 0.1;
  }
  else {
    switch(param_7) {
    case 0x516:
    case 0x517:
      goto switchD_00438c80_caseD_3eb;
    case 0x518:
switchD_00438c80_caseD_3ec:
      local_1c = local_1c + 0.2;
      break;
    case 0x519:
    case 0x51b:
    case 0x51c:
switchD_00438c80_caseD_3e9:
      local_1c = local_1c + 0.3;
      break;
    case 0x51a:
switchD_00438c80_caseD_453:
      local_1c = local_1c + 0.4;
    }
  }
switchD_00438c80_caseD_3ee:
LAB_00438d8d:
  if (-20000.0 <= local_14) {
    local_c = (double)param_1 + local_14 * local_1c + 0.5;
  }
  else {
    local_c = (double)param_1 - 20000.0;
  }
  if (local_c <= 99999999.0) {
    if (100.0 <= local_c) {
      uVar1 = _ftol_nocw();
    }
    else {
      uVar1 = 100;
    }
  }
  else {
    uVar1 = 99999999;
  }
  return uVar1;
}


// ==== 0x438ec0 FUN_00438ec0

undefined4 * __thiscall
FUN_00438ec0(undefined4 *param_1,undefined1 param_2,undefined1 param_3,int param_4)

{
  Ptr_SetNull();
  PtrSlots__PtrSlots();
  Ptr_SetNull();
  Ptr_SetNull();
  *(undefined1 *)(param_1 + 1) = param_2;
  *(undefined1 *)((int)param_1 + 5) = 0xff;
  param_1[0x69] = 0xbf800000;
  param_1[2] = 100;
  param_1[3] = 0;
  param_1[4] = 0;
  *param_1 = 0;
  *(undefined1 *)(param_1 + 6) = param_3;
  param_1[0x62] = 0;
  param_1[0x61] = 0;
  param_1[0x6d] = 0;
  param_1[0x6e] = 0xbf800000;
  param_1[0x6f] = 0xbf800000;
  param_1[0x6a] = 0;
  FUN_00439810();
  FUN_00424cc0();
  if (param_4 == 0) {
    *(undefined4 *)((int)param_1 + 0x19) = 0;
    *(undefined4 *)((int)param_1 + 0x1d) = 0;
    *(undefined4 *)((int)param_1 + 0x21) = 0;
    *(undefined1 *)((int)param_1 + 0x25) = 0;
  }
  else {
    FUN_00438fe0(param_4);
  }
  return param_1;
}


// ==== 0x438fe0 FUN_00438fe0

void __thiscall FUN_00438fe0(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x19) = *param_2;
  *(undefined4 *)(param_1 + 0x1d) = param_2[1];
  *(undefined4 *)(param_1 + 0x21) = param_2[2];
  *(undefined1 *)(param_1 + 0x25) = *(undefined1 *)(param_2 + 3);
  return;
}


// ==== 0x439010 RaceStatus::FindCurrentEntrant

/* [canon] rivals low (ghidra-canon) docs/re/canon.md */

void RaceStatus__FindCurrentEntrant(void)

{
  RaceStatus__FindEntrantById();
  return;
}


// ==== 0x439030 Race_TickTrackerSet

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

void __thiscall Race_TickTrackerSet(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  float fVar3;
  
  if (*(int *)(param_1 + 0xc) != param_2) {
    iVar1 = SpecialCamCooldown();
    if (iVar1 != 0) {
      fVar3 = (float)(param_2 - *(int *)(param_1 + 0xc));
      int_Sub(param_1 + 0x14);
      bTickerToSeconds(fVar3);
      uVar2 = _ftol_nocw();
      *(undefined4 *)(param_1 + 0x10) = uVar2;
    }
    FUN_00405560();
    *(int *)(param_1 + 0xc) = param_2;
  }
  iVar1 = SpecialCamCooldown();
  if (iVar1 == 0) {
    FUN_00405560();
  }
  return;
}


// ==== 0x4390d0 FUN_004390d0

void __thiscall FUN_004390d0(int *param_1,int param_2)

{
  if (param_2 != *param_1) {
    *param_1 = param_2;
  }
  return;
}


// ==== 0x4390f0 Race::GetRacingCarOfRacer

/* [canon] rivals low (ghidra-canon) docs/re/canon.md */

undefined4 __fastcall Race__GetRacingCarOfRacer(undefined4 param_1)

{
  int iVar1;
  undefined4 local_c;
  
  local_c = 0;
  iVar1 = Race__FindRacerById(param_1);
  if (iVar1 != 0) {
    local_c = FUN_004081e0();
  }
  return local_c;
}


// ==== 0x439130 Race::FindRacerById

/* [canon] rivals low (ghidra-canon) docs/re/canon.md */

undefined4 Race__FindRacerById(void)

{
  undefined4 local_8;
  
  local_8 = 0;
  if ((DAT_0073619c != 0) && (DAT_007361f8 != 0)) {
    local_8 = RaceManager__FindRacerByIdIn();
  }
  return local_8;
}


// ==== 0x439170 NetPlayer::SendFinishMessage

/* WARNING: Removing unreachable block (ram,0x0043925d) */
/* [canon] online low (ghidra-canon) docs/re/canon.md */

void __thiscall
NetPlayer__SendFinishMessage(int param_1,undefined1 param_2,char param_3,uint param_4)

{
  char cVar1;
  undefined1 local_416;
  undefined1 local_414 [1040];
  
  FUN_00548820();
  FUN_00548840(*(undefined1 *)(param_1 + 4));
  FUN_00548840(param_2);
  if ((param_3 == '\0') && (param_4 != 9)) {
    local_416 = 0;
  }
  else {
    local_416 = 1;
  }
  FUN_00548840(local_416);
  FUN_00548840(param_4 & 0xff);
  FUN_00548980(local_414,param_1 + 0x18c);
  FUN_00439440();
  FUN_00548980(local_414,param_1 + 0x28);
  cVar1 = FUN_005466e0();
  if (cVar1 != '\0') {
    FUN_00546830();
  }
  FUN_004390d0(3);
  return;
}


// ==== 0x4392a0 BitStream::BitStream

/* [canon] online med (ghidra-canon) docs/re/canon.md */

undefined4 __fastcall BitStream__BitStream(undefined4 param_1)

{
  FUN_00548820();
  return param_1;
}


// ==== 0x4392c0 FUN_004392c0

/* WARNING: Removing unreachable block (ram,0x004393e6) */
/* WARNING: Removing unreachable block (ram,0x004393f7) */
/* WARNING: Removing unreachable block (ram,0x00439408) */
/* WARNING: Removing unreachable block (ram,0x00439411) */
/* WARNING: Removing unreachable block (ram,0x00439422) */

void __fastcall FUN_004392c0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_30;
  undefined1 local_24 [29];
  undefined1 local_7;
  char local_5;
  
  FUN_005488d0(8);
  local_7 = 0;
  FUN_005488d0(8);
  local_5 = '\0';
  FUN_005488d0(8);
  FUN_005489c0(local_24,0x18);
  FUN_005489c0(param_1 + 0x28,0x15c);
  for (local_30 = 0; local_30 < 6; local_30 = local_30 + 1) {
    uVar1 = FUN_004109f0();
    *(undefined4 *)(param_1 + 0x18c + local_30 * 4) = uVar1;
  }
  FUN_004390d0(3);
  iVar2 = Race__GetRacingCarOfRacer();
  if ((iVar2 != 0) && (iVar2 = FUN_00424e90(), iVar2 == 0)) {
    uVar4 = 0;
    uVar3 = (uint)(local_5 != '\0');
    uVar5 = 0;
    uVar1 = FUN_00421960(0,uVar3,0);
    Race__FinishCar(uVar1,uVar5,uVar3,uVar4);
  }
  if (*(int *)(param_1 + 0x184) == 0) {
    FUN_004399a0(0x20);
  }
  return;
}


// ==== 0x439440 FUN_00439440

void FUN_00439440(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  uVar1 = Race__GetRacingCarOfRacer(1);
  FUN_004acd20(uVar1,uVar2);
  return;
}


// ==== 0x439470 FUN_00439470

void __thiscall FUN_00439470(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  cVar1 = GameMode__IsNotMode0456(param_1);
  if (cVar1 != '\0') {
    FUN_004390d0(param_2);
  }
  iVar2 = Race__GetRacingCarOfRacer();
  if (iVar2 != 0) {
    iVar2 = FUN_00424e90();
    if (iVar2 == 0) {
      RaceStatus__FindCurrentEntrant(param_3);
      uVar3 = DriverInfo__IsRemote();
      uVar5 = 0;
      uVar4 = FUN_00421960(0,uVar3);
      Race__FinishCar(uVar4,uVar5,uVar3,param_3);
      FUN_00439440();
    }
  }
  return;
}


// ==== 0x4394f0 FUN_004394f0

/* WARNING: Removing unreachable block (ram,0x004397e0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004394f0(int param_1)

{
  float fVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  float10 fVar6;
  float10 fVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  *(undefined4 *)(param_1 + 0x1b4) = 0;
  *(undefined4 *)(param_1 + 0x1b8) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x1bc) = 0xbf800000;
  FUN_00424f10();
  if (DAT_0073619c == 0) {
    return;
  }
  iVar3 = Race__AreAllPlayersFinishedRacing(DAT_0073619c);
  if (iVar3 != 0) {
    return;
  }
  iVar3 = FUN_00421960();
  if (iVar3 != 4) {
    return;
  }
  FUN_00432c70();
  iVar3 = SpecialCamCooldown();
  if (iVar3 != 0) {
    fVar6 = (float10)FUN_00432c80();
    uVar4 = FUN_00432c70();
    int_Sub(uVar4);
    fVar7 = (float10)bTickerToSeconds();
    *(float *)(param_1 + 0x1bc) = (float)((float10)(float)fVar6 - fVar7);
  }
  cVar2 = GameMode__IsMode03456();
  if ((cVar2 != '\0') || (DAT_0077b259 == '\0')) goto LAB_004397af;
  cVar2 = IsDriftMode();
  if (cVar2 == '\0') {
    cVar2 = FUN_00424f20();
    if (cVar2 == '\0') {
      FUN_00417490();
      fVar6 = (float10)FUN_00424e00();
      if ((float10)0.0 <= fVar6) goto LAB_00439615;
    }
    iVar3 = SpecialCamCooldown();
    if (iVar3 == 0) {
      FUN_00405560();
    }
  }
  else {
LAB_00439615:
    FUN_00424cc0();
  }
  FUN_00417490();
  fVar6 = (float10)FUN_00424e10();
  if (fVar6 <= (float10)10.0) {
    iVar3 = SpecialCamCooldown();
    if (iVar3 == 0) {
      FUN_00405560();
    }
  }
  else {
    FUN_00424cc0();
  }
  iVar3 = SpecialCamCooldown();
  if (iVar3 != 0) {
    int_Sub(param_1 + 0x1ac);
    fVar6 = (float10)bTickerToSeconds();
    fVar1 = (float)fVar6;
    if (fVar1 <= _DAT_0077c788) {
      if (2.0 < fVar1) {
        *(undefined4 *)(param_1 + 0x1b4) = 1;
        *(float *)(param_1 + 0x1b8) = _DAT_0077c788 - fVar1;
      }
    }
    else {
      Player__ResetToRoute();
    }
  }
  iVar3 = SpecialCamCooldown();
  if (iVar3 != 0) {
    int_Sub(param_1 + 0x1b0);
    fVar6 = (float10)bTickerToSeconds();
    fVar1 = (float)fVar6;
    if (fVar1 <= _DAT_0077c788) {
      if (2.0 < fVar1) {
        *(undefined4 *)(param_1 + 0x1b4) = 2;
        *(float *)(param_1 + 0x1b8) = _DAT_0077c788 - fVar1;
      }
    }
    else {
      FUN_004399a0(4);
      uVar9 = 9;
      uVar8 = 0;
      uVar4 = Race__GetLastAvailableRank(0,9);
      uVar5 = FUN_00417490(uVar4);
      Race__FinishCar(uVar5,uVar4,uVar8,uVar9);
    }
  }
LAB_004397af:
  Race__GetRacingCarOfRacer();
  iVar3 = FUN_00432c60();
  if ((iVar3 != 0) && (iVar3 = FUN_005647d0(), iVar3 != 0x238562c5)) {
    FUN_004399a0(0x20);
    FUN_0043a830();
  }
  return;
}


// ==== 0x439810 FUN_00439810

void __fastcall FUN_00439810(int param_1)

{
  undefined4 local_8;
  
  *(undefined4 *)(param_1 + 0x188) = 0;
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    *(undefined4 *)(param_1 + 0x18c + local_8 * 4) = 0;
  }
  return;
}


// ==== 0x439860 FUN_00439860

undefined4 __thiscall FUN_00439860(int param_1,float param_2)

{
  uint uVar1;
  int local_8;
  
  *(undefined4 *)(param_1 + 0x188) = 0;
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    if (((*(float *)(&DAT_006b7998 + local_8 * 4) == 0.0) &&
        (0 < *(int *)(param_1 + 0x18c + local_8 * 4))) ||
       ((0.0 < param_2 &&
        (*(float *)(&DAT_006b7998 + local_8 * 4) <
         ((float)*(int *)(param_1 + 0x18c + local_8 * 4) / param_2) * 60.0)))) {
      uVar1 = FUN_00439980(local_8);
      *(uint *)(param_1 + 0x188) = *(uint *)(param_1 + 0x188) | uVar1;
    }
  }
  return *(undefined4 *)(param_1 + 0x188);
}


// ==== 0x439930 FUN_00439930

int FUN_00439930(int param_1)

{
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  while( true ) {
    if (5 < local_c) {
      return 0;
    }
    if ((param_1 >> ((byte)local_c & 0x1f) & 1U) != 0) break;
    local_8 = local_8 + 1;
    local_c = local_c + 1;
  }
  return local_8;
}


// ==== 0x439980 FUN_00439980

int FUN_00439980(byte param_1)

{
  return 1 << (param_1 & 0x1f);
}


// ==== 0x4399a0 FUN_004399a0

void __thiscall FUN_004399a0(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  
  *(uint *)(param_1 + 0x188) = *(uint *)(param_1 + 0x188) | param_2;
  iVar2 = FUN_00439930(param_2);
  piVar1 = (int *)(param_1 + 0x18c + iVar2 * 4);
  *piVar1 = *piVar1 + 1;
  return;
}


// ==== 0x4399f0 FUN_004399f0

undefined4 __thiscall FUN_004399f0(int param_1,char param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x184) == 0) || (param_2 != '\0')) {
    RaceStatus__FindCurrentEntrant();
    FUN_00421a70();
    uVar1 = FUN_0057f130();
    uVar1 = FUN_00576440(param_1,uVar1);
    *(undefined4 *)(param_1 + 0x184) = uVar1;
  }
  return *(undefined4 *)(param_1 + 0x184);
}


// ==== 0x439a50 FUN_00439a50

float10 __thiscall FUN_00439a50(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x1b4);
  return (float10)*(float *)(param_1 + 0x1b8);
}


// ==== 0x439a80 Race::GetClockSeconds

/* [canon] rivals low (ghidra-canon) docs/re/rivals.md */

float10 __fastcall Race__GetClockSeconds(int param_1)

{
  return (float10)*(float *)(param_1 + 0x1bc);
}


// ==== 0x439a94 FUN_00439a94

void FUN_00439a94(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== 0x439a9a FUN_00439a9a

void FUN_00439a9a(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== 0x439aa0 FUN_00439aa0

undefined4 * __fastcall FUN_00439aa0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int local_14;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_00684c70;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  Ptr_SetNull();
  Ptr_SetNull();
  Ptr_SetNull();
  Ptr_SetNull();
  Ptr_SetNull();
  Ptr_SetNull();
  Ptr_SetNull();
  FUN_00549100();
  local_8 = 0;
  FUN_00549100();
  local_8._0_1_ = 1;
  FUN_00549100();
  local_8._0_1_ = 2;
  FUN_00549100();
  local_8._0_1_ = 3;
  FUN_00549100();
  local_8._0_1_ = 4;
  FUN_00548a90();
  local_8._0_1_ = 5;
  FUN_00548a90();
  local_8._0_1_ = 6;
  FUN_00548a90();
  local_8._0_1_ = 7;
  FUN_00548a90();
  local_8._0_1_ = 8;
  FUN_00548a90();
  local_8._0_1_ = 9;
  FUN_00548a90();
  local_8._0_1_ = 10;
  FUN_00548a90();
  local_8._0_1_ = 0xb;
  FUN_00548a90();
  local_8._0_1_ = 0xc;
  FUN_00548a90();
  local_8._0_1_ = 0xd;
  FUN_00548a90();
  local_8._0_1_ = 0xe;
  FUN_00549100();
  local_8 = CONCAT31(local_8._1_3_,0xf);
  *param_1 = 0;
  puVar2 = param_1 + 0x17;
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  FUN_00549140(0);
  FUN_00549140(0);
  FUN_00549140(0);
  FUN_00549140(0);
  FUN_00549140(0);
  FUN_00548ba0(0,0x46610000);
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  param_1[0x16] = 0;
  *(undefined1 *)((int)param_1 + 0x19) = 0;
  *(undefined1 *)((int)param_1 + 0x1a) = 0;
  FUN_00424cc0();
  FUN_00424cc0();
  FUN_00424cc0();
  FUN_00424cc0();
  FUN_00424cc0();
  FUN_00424cc0();
  FUN_00424cc0();
  for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
    param_1[local_14 + 2] = 0;
  }
  FUN_0043d120();
  ExceptionList = local_10;
  return param_1;
}


// ==== 0x439da0 FUN_00439da0

void FUN_00439da0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = DAT_0077b178;
  uVar3 = DAT_0077b174;
  uVar2 = DAT_0077b168;
  uVar1 = DAT_0077b164;
  FUN_00548ad0(DAT_0077b160,DAT_0077b170,0x3c23d70a);
  FUN_00548ad0(uVar1,uVar3,0x3c23d70a);
  FUN_00548ad0(uVar2,uVar4,0x3c23d70a);
  FUN_00548ad0(-DAT_006f0904,DAT_006f0904,0x3ca3d70a);
  FUN_00548ad0(0xbf800000,0x3f800000,0x3c23d70a);
  FUN_00548ad0(0xc4480000,0x44480000,0x3dcccccd);
  FUN_00548ad0(0xc1a00000,0x41a00000,0x3dcccccd);
  FUN_00548ad0(0,0x3f800000,0x3d4ccccd);
  FUN_00548ad0(0x43fa0000,0x461c4000,0x42c80000);
  FUN_00549140(0);
  return;
}


// ==== 0x439f80 FUN_00439f80

void __fastcall FUN_00439f80(int param_1)

{
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0x83c);
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0x988);
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0xad4);
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0xc20);
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0xeb8);
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0x1004);
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0xd6c);
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0x1150);
  return;
}


// ==== 0x43a001 FUN_0043a001

void FUN_0043a001(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== 0x43a010 FUN_0043a010

void __fastcall FUN_0043a010(int param_1)

{
  void *local_10;
  code *pcStack_c;
  int local_8;
  
  pcStack_c = FUN_00685e80;
  local_10 = ExceptionList;
  local_8 = 0xf;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x58) != 0) {
    ExceptionList = &local_10;
    FUN_00565b10();
    FUN_00565ce0();
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  local_8._0_1_ = 0xe;
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0x13e8);
  local_8._0_1_ = 0xd;
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0x129c);
  local_8._0_1_ = 0xc;
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0x1150);
  local_8._0_1_ = 0xb;
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0x1004);
  local_8._0_1_ = 10;
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0xeb8);
  local_8._0_1_ = 9;
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0xd6c);
  local_8._0_1_ = 8;
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0xc20);
  local_8._0_1_ = 7;
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0xad4);
  local_8._0_1_ = 6;
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0x988);
  local_8._0_1_ = 5;
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0x83c);
  local_8._0_1_ = 4;
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0x6f0);
  local_8._0_1_ = 3;
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0x5ac);
  local_8._0_1_ = 2;
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0x468);
  local_8._0_1_ = 1;
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0x324);
  local_8 = (uint)local_8._1_3_ << 8;
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0x1e0);
  local_8 = 0xffffffff;
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1 + 0x9c);
  ExceptionList = local_10;
  return;
}


// ==== 0x43a1a0 FUN_0043a1a0

/* WARNING: Removing unreachable block (ram,0x0043a1b0) */

void __fastcall FUN_0043a1a0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00401000("Online Buffer",0);
  *(undefined4 *)(param_1 + 0x58) = uVar1;
  FUN_00565af0(*(undefined4 *)(param_1 + 0x58));
  if (DAT_0073465c == 0) {
    DAT_007346c4 = 1;
  }
  if (DAT_007346c4 != 0) {
    FUN_005492c0();
  }
  return;
}


// ==== 0x43a220 FUN_0043a220

void __thiscall FUN_0043a220(int *param_1,char param_2)

{
  undefined4 uVar1;
  int local_8;
  
  if (*(char *)((int)param_1 + 0x1a) != '\0') {
    FUN_00546680();
  }
  *(undefined1 *)((int)param_1 + 0x1a) = 0;
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    if (param_1[local_8 + 2] != 0) {
      uVar1 = 0;
      Race__GetPlayer(local_8);
      FUN_004390d0(uVar1);
    }
  }
  if (((*param_1 == 3) && (DAT_006f1f64 != 0)) && (param_2 == '\0')) {
    FUN_004390d0(1);
  }
  else {
    if (DAT_006f1f64 != 0) {
      FUN_00549980();
    }
    FUN_004390d0(0);
  }
  FUN_0043b680();
  return;
}


// ==== 0x43a2e0 FUN_0043a2e0

undefined1 __fastcall FUN_0043a2e0(int param_1)

{
  undefined1 local_c;
  
  if (((*(char *)(param_1 + 0x1a) == '\0') && (DAT_007354e0 < 1)) && (DAT_00735500 < 1)) {
    local_c = 0;
  }
  else {
    local_c = 1;
  }
  return local_c;
}


// ==== 0x43a340 IsFlag7346c8Set

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

bool IsFlag7346c8Set(void)

{
  return DAT_007346c8 != 0;
}


// ==== 0x43a360 FUN_0043a360

void __thiscall FUN_0043a360(undefined4 *param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  float10 fVar6;
  int local_24;
  int local_1c;
  int local_c;
  
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_("OnlineManager::Update");
  FUN_00546780();
  switch(*param_1) {
  case 1:
    if ((DAT_006f1f64 == 0) || (DAT_00734fd0 != '\0')) {
      FUN_004390d0(2);
      if (DAT_0073465c != 0) {
        FUN_0043aba0();
      }
    }
    else {
      FUN_00549aa0();
    }
    break;
  case 5:
    iVar5 = FUN_0043b770();
    if (iVar5 == 0) {
      FUN_0043af80();
    }
    else if ((0.0 < (float)param_1[7]) &&
            (fVar6 = (float10)bTickerToSeconds(), (float10)(float)param_1[7] <= fVar6)) {
      FUN_0043af80();
    }
    break;
  case 6:
    iVar5 = FUN_00424ea0();
    if ((iVar5 != 0) && (iVar5 = Race__AreAllPlayersFinishedRacing(DAT_0073619c), iVar5 == 0)) {
      for (local_c = 0; local_c < 4; local_c = local_c + 1) {
        iVar5 = Race__GetPlayer(local_c);
        if (iVar5 != 0) {
          iVar5 = Race__FindRacerById();
          iVar5 = *(int *)(iVar5 + 0x830);
          AntiTamper__DecodeFloat(**(undefined4 **)(iVar5 + 0x298),*(undefined4 *)(iVar5 + 0x29c));
          iVar3 = _ftol_nocw();
          if (iVar3 != 5) {
            FUN_004399a0(0x20);
            FUN_0043a830();
            break;
          }
          *(undefined4 *)(iVar5 + 0x254) = 0;
        }
      }
    }
    iVar5 = FUN_0043b770();
    if ((iVar5 == 0) && (cVar2 = GameMode__IsMode03456(), cVar2 == '\0')) {
      FUN_00439470(0,10);
    }
    bVar1 = true;
    for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
      puVar4 = (undefined4 *)Race__GetPlayer(local_1c);
      if (puVar4 != (undefined4 *)0x0) {
        cVar2 = GameMode__IsMode03456();
        if (cVar2 == '\0') {
          bVar1 = false;
          break;
        }
        Race__GetRacingCarOfRacer();
        iVar5 = FUN_00424e90();
        if (iVar5 == 0) {
          HudOnlineMsgBox__PushPlayerMessage(puVar4);
          FUN_00439470(*puVar4,10);
        }
      }
    }
    if (bVar1) {
      FUN_0043ac10(0);
    }
    else {
      cVar2 = IsFlag7346c8Set();
      if ((cVar2 != '\0') && (iVar5 = FUN_00586640(DAT_0073ad38), iVar5 == 0)) {
        FUN_0043cef0();
        FUN_00424cd0(param_1 + 0x11,0x3f800000);
      }
      cVar2 = IsDriftMode();
      if ((cVar2 != '\0') && (iVar5 = FUN_00586640(DAT_0073ad38), iVar5 == 0)) {
        FUN_0043d030();
        FUN_00424cd0(param_1 + 0x12,0x3f800000);
      }
      iVar5 = FUN_00586640(DAT_0073ad38);
      if (iVar5 == 0) {
        FUN_0043d5f0();
        FUN_00424cd0(param_1 + 0x13,0x40a00000);
      }
      int_Sub(param_1 + 0x25);
      fVar6 = (float10)bTickerToSeconds();
      if ((float10)2.0 < fVar6) {
        FUN_0043d4f0();
        FUN_00405560();
      }
    }
    cVar2 = GameMode__IsNotMode0456();
    if (cVar2 != '\0') {
      FUN_004394f0(DAT_0073457c);
      fVar6 = (float10)Race__GetClockSeconds();
      if (fVar6 < -(float10)3.0) {
        for (local_24 = 0; local_24 < 4; local_24 = local_24 + 1) {
          iVar5 = Race__GetPlayer(local_24);
          if ((iVar5 != 0) && (cVar2 = GameMode__IsMode03456(), cVar2 == '\0')) {
            FUN_004399a0(0x10);
            FUN_00439470(3,9);
          }
        }
      }
    }
    break;
  case 7:
    iVar5 = SpecialCamCooldown();
    if (((iVar5 == 0) && (iVar5 = GameMode__IsMode7Or11(), iVar5 == 0)) &&
       (iVar5 = FUN_00421960(), iVar5 == 4)) {
      FUN_00405560();
    }
  }
  if (param_2 != '\0') {
    FUN_0043a7f0();
    FUN_0043a810();
  }
  return;
}


// ==== 0x43a7e4 FUN_0043a7e4

void FUN_0043a7e4(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== 0x43a7ea FUN_0043a7ea

void FUN_0043a7ea(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== 0x43a7f0 FUN_0043a7f0

void __fastcall FUN_0043a7f0(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = FUN_0043a2e0(param_1);
  if (cVar1 != '\0') {
    FUN_00546710();
  }
  return;
}


// ==== 0x43a810 FUN_0043a810

void __fastcall FUN_0043a810(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = FUN_0043a2e0(param_1);
  if (cVar1 != '\0') {
    FUN_00546750();
  }
  return;
}


// ==== 0x43a830 FUN_0043a830

void __fastcall FUN_0043a830(int param_1)

{
  int iVar1;
  undefined4 local_8;
  
  FUN_00439470(5,10);
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    iVar1 = Race__GetPlayer(local_8);
    if ((iVar1 != 0) && (iVar1 != *(int *)(param_1 + 4))) {
      FUN_00439470(0,10);
    }
  }
  return;
}


// ==== 0x43a8a0 FUN_0043a8a0

/* WARNING: Removing unreachable block (ram,0x0043aaaf) */
/* WARNING: Removing unreachable block (ram,0x0043aac1) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_0043a8a0(int *param_1,float param_2)

{
  float fVar1;
  char cVar2;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  float local_8;
  
  local_8 = param_2 * 1.0;
  cVar2 = FUN_0043a2e0();
  if (cVar2 != '\0') {
    if (*(char *)((int)param_1 + 0x19) != '\0') {
      if (param_2 <= 0.083333336) {
        DAT_0078eb58 = 0;
      }
      else {
        DAT_0078eb58 = DAT_0078eb58 + 1;
        if (0xe < DAT_0078eb58) {
          HudOnlineMsgBox__PushLocalizedMessage(param_1[1]);
        }
      }
    }
    cVar2 = IsFlag7346c8Set();
    if (cVar2 == '\0') {
      iVar3 = SpecialCamCooldown();
      if (iVar3 != 0) {
        int_Sub(param_1 + 0x14);
        fVar4 = (float10)bTickerToSeconds();
        FUN_00424c90((float)fVar4);
        FUN_00424cb0();
      }
      FUN_00405560();
      if ((param_2 <= 0.0) || (*param_1 != 6)) {
        FUN_00405560();
        fVar4 = (float10)bTickerToSeconds();
        _DAT_006f0898 = (float)fVar4;
        DAT_0073014c = '\0';
      }
      else if (DAT_0073014c != '\0') {
        fVar4 = (float10)bTickerToSeconds();
        fVar5 = (float10)bTickerToSeconds();
        fVar1 = (float)((float10)(float)fVar4 - fVar5);
        fVar4 = (float10)FUN_00405600(fVar1);
        if (fVar4 <= (float10)0.25) {
          fVar4 = (float10)FUN_00405600(fVar1);
          if (fVar4 <= (float10)0.001) {
            DAT_0073014c = '\0';
          }
          else {
            fVar4 = (float10)bClampF(param_2 + fVar1,param_2 * 0.85,param_2 * 1.2);
            local_8 = (float)fVar4;
          }
        }
        else {
          FUN_0043aae0(fVar1,0);
          FUN_00405560();
          fVar4 = (float10)bTickerToSeconds();
          _DAT_006f0898 = (float)fVar4;
          DAT_0073014c = '\0';
        }
      }
    }
    else {
      FUN_00405560();
    }
  }
  return (float10)local_8;
}


// ==== 0x43aae0 FUN_0043aae0

void __thiscall FUN_0043aae0(int param_1,float param_2,char param_3)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int local_8;
  
  for (local_8 = 0; local_8 < (int)(uint)*(byte *)(param_1 + 0x40); local_8 = local_8 + 1) {
    uVar3 = *(undefined4 *)(param_1 + 0x20 + local_8 * 4);
    piVar2 = (int *)FUN_00417490();
    cVar1 = FUN_0057a180(param_1,piVar2,uVar3);
    if (cVar1 != '\0') {
      if (param_3 != '\0') {
        FUN_00579f90(0);
      }
      if (param_2 != 0.0) {
        (**(code **)(*piVar2 + 4))(param_2);
      }
    }
  }
  return;
}


// ==== 0x43ab70 FUN_0043ab70

void __fastcall FUN_0043ab70(int *param_1)

{
  if ((*param_1 == 0) || (DAT_00734fd0 == '\0')) {
    FUN_004390d0(1);
  }
  return;
}


// ==== 0x43aba0 FUN_0043aba0

void __fastcall FUN_0043aba0(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  if (*param_1 == 2) {
    puVar3 = &DAT_00734718;
    uVar2 = IsFlag7346c8Set(&DAT_00734718);
    FUN_0043b560(0,0,uVar2,puVar3);
    if ((DAT_0073465c == 0) && (cVar1 = IsFlag7346c8Set(), cVar1 != '\0')) {
      FUN_0043b900();
    }
    FUN_00546600();
    *(undefined1 *)((int)param_1 + 0x1a) = 1;
    FUN_004390d0(3);
  }
  return;
}


// ==== 0x43ac10 FUN_0043ac10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0043ac10(int *param_1,char param_2)

{
  char cVar1;
  int iVar2;
  float10 fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  float fVar6;
  int local_c;
  int local_8;
  
  _DAT_006f0894 = 0x40400000;
  if (DAT_007361f8 != 0) {
    SetGlobal_006ffdbc_30f(DAT_007361f8);
  }
  if (((*param_1 == 6) || (*param_1 == 4)) || (*param_1 == 5)) {
    if (param_2 != '\0') {
      if (param_1[1] != 0) {
        FUN_00439470(5,10);
      }
      for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
        if (param_1[local_8 + 2] != 0) {
          iVar2 = Race__GetPlayer(local_8);
          if (iVar2 != param_1[1]) {
            Race__GetPlayer(local_8);
            cVar1 = GameMode__IsMode03456();
            if (cVar1 == '\0') {
              uVar5 = 10;
              uVar4 = 0;
              Race__GetPlayer(local_8);
              FUN_00439470(uVar4,uVar5);
            }
          }
        }
      }
    }
    for (local_c = 0; local_c < 4; local_c = local_c + 1) {
      if (param_1[local_c + 2] != 0) {
        FUN_00421a90();
        fVar3 = (float10)bTickerToSeconds();
        fVar6 = (float)fVar3;
        Race__GetPlayer(local_c);
        FUN_00439860(fVar6);
      }
    }
    FUN_0043bfe0();
    FUN_0043c300();
    FUN_0043d120();
    FUN_006497d0();
    FUN_00439f80();
  }
  if ((param_2 == '\0') && (*param_1 != 7)) {
    FUN_004390d0(7);
  }
  else {
    FUN_0043a220(0);
  }
  return;
}


// ==== 0x43ada0 Race::RequestStartOrRestart

/* [canon] canon med (capstone) docs/re/gameflow.md */

void __fastcall Race__RequestStartOrRestart(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  if (DAT_006f1f64 != 0) {
    Race__ApplyPendingSlotNames();
    FUN_0043d7e0();
    FUN_00549980();
    cFrontendDatabase__ResetRaceSlotState();
  }
  cVar1 = IsDriftMode();
  if (cVar1 != '\0') {
    DriftManager__BuildLeaderBoard(0);
  }
  FUN_004390d0(4);
  cVar1 = GameFlow__IsInFrontEnd();
  if (cVar1 == '\0') {
    GameFlow__SetNextLoadingTrackCommon();
  }
  else {
    GameFlow__SetNextUnloadingFrontEnd();
  }
  uVar2 = FUN_004399f0(1);
  *(undefined4 *)(param_1 + 0x98) = uVar2;
  return;
}


// ==== 0x43ae40 FUN_0043ae40

void __fastcall FUN_0043ae40(int *param_1)

{
  char cVar1;
  
  if (*param_1 == 4) {
    param_1[7] = 0;
    FUN_00424cc0();
    FUN_00424cc0();
    FUN_00424cc0();
    FUN_00424cc0();
    FUN_00424cc0();
    FUN_00424cc0();
    FUN_00424cc0();
    FUN_00405560();
    cVar1 = FUN_005466e0();
    if (cVar1 != '\0') {
      FUN_005467f0();
    }
  }
  return;
}


// ==== 0x43aed0 FUN_0043aed0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0043aed0(int *param_1)

{
  char cVar1;
  
  if (*param_1 == 4) {
    FUN_004390d0(5);
    FEManager__PushPackageChecked(0,0);
    if (DAT_007361f8 != 0) {
      _DAT_006f0894 = 0x40c00000;
      FUN_00420080(DAT_007361f8);
      FUN_00405560();
      FUN_0043d160();
    }
    cVar1 = FUN_005466e0();
    if (cVar1 != '\0') {
      FUN_00546810();
    }
  }
  return;
}


// ==== 0x43af50 FUN_0043af50

/* WARNING: Removing unreachable block (ram,0x0043af5d) */

void __thiscall FUN_0043af50(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  return;
}


// ==== 0x43af80 FUN_0043af80

/* WARNING: Removing unreachable block (ram,0x0043af8f) */
/* WARNING: Removing unreachable block (ram,0x0043b064) */

void __fastcall FUN_0043af80(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int local_8;
  
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    if (*(int *)(param_1 + 8 + local_8 * 4) != 0) {
      Race__GetPlayer(local_8);
      cVar1 = GameMode__IsNotMode0456();
      if (cVar1 != '\0') {
        uVar3 = 2;
        Race__GetPlayer(local_8);
        FUN_004390d0(uVar3);
      }
    }
  }
  FUN_004390d0(6);
  if ((DAT_007361f8 != 0) && (DAT_0073619c != 0)) {
    SetGlobal_006ffdbc_30f(DAT_007361f8);
    Race__SetRaceStage(DAT_0073619c,3);
    FUN_0043aae0(0,1);
  }
  DAT_00779814 = 0xffffffff;
  iVar2 = FUN_005647d0();
  if (iVar2 != 0x238562c5) {
    FUN_004399a0(0x20);
    FUN_0043a830();
  }
  return;
}


// ==== 0x43b090 FUN_0043b090

void FUN_0043b090(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  FUN_005488d0(8);
  DAT_00777cc8 = 0;
  iVar1 = RaceOptions_Get();
  FUN_005488d0(0x10);
  *(undefined4 *)(iVar1 + 8) = 0;
  FUN_005488d0(8);
  *(undefined4 *)(iVar1 + 0xc) = 0;
  FUN_005488d0(8);
  *(undefined1 *)(iVar1 + 0x1f) = 0;
  FUN_005488d0(0x20);
  FUN_005488d0(0x20);
  if (DAT_0073465c == 0) {
    FUN_0043b900();
  }
  else {
    DAT_0078a30c = FUN_004b39e0();
    DAT_0078a2f0 = *(undefined4 *)(iVar1 + 8);
    DAT_0078a2fc = *(undefined4 *)(iVar1 + 0xc);
    DAT_0078a400 = (uint)*(byte *)(iVar1 + 0x1f);
    DAT_0078a3fc = *(undefined4 *)(iVar1 + 0x14);
    DAT_0078a31c = *(undefined4 *)(iVar1 + 0x10);
  }
  FUN_0043b930(param_1);
  FUN_0043b560(param_2,0,1,0);
  uVar2 = BitStream__ReadBitsValue();
  DAT_00779814 = uVar2 & 0xff;
  return;
}


// ==== 0x43b210 FUN_0043b210

/* WARNING: Removing unreachable block (ram,0x0043b3e7) */

void __thiscall FUN_0043b210(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_2c;
  char local_9;
  
  if (*(int *)(param_1 + 4) == 0) {
    FUN_0043b930(param_2);
  }
  if (DAT_0073465c == 0) {
    iVar1 = RaceOptions_Get();
    FUN_00548840(DAT_00777cc8 & 0xff);
    FUN_00548840((int)*(short *)(iVar1 + 8));
    FUN_00548840(*(undefined1 *)(iVar1 + 0xc));
    FUN_00548840(*(undefined1 *)(iVar1 + 0x1f));
    BitStream__WriteBitsThunk();
    BitStream__WriteBitsThunk();
    local_9 = DAT_00777cc8 == 6;
  }
  else {
    FUN_00548840((undefined1)DAT_0078a30c);
    FUN_00548840((int)(short)DAT_0078a2f0);
    FUN_00548840((undefined1)DAT_0078a2fc);
    FUN_00548840((undefined1)DAT_0078a400);
    BitStream__WriteBitsThunk();
    BitStream__WriteBitsThunk();
    local_9 = IsDriftMode();
  }
  if ((int)DAT_00779814 < 0) {
    if (local_9 == '\0') {
      local_2c = FUN_0047c010(&DAT_00779800);
    }
    else {
      local_2c = FUN_0047c010(&DAT_00779800);
    }
    DAT_00779814 = RandomInt(local_2c);
  }
  FUN_00548840(DAT_00779814 & 0xff);
  return;
}


// ==== 0x43b400 FUN_0043b400

void FUN_0043b400(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined1 local_780 [16];
  undefined1 local_770;
  char local_76f;
  char local_76d;
  undefined1 local_3c;
  
  DriverInfo__InitDefault();
  iVar2 = FUN_00432830();
  if (param_1 != iVar2) {
    FUN_0043cad0(&local_770,param_2);
    FUN_00548a30(param_2);
    local_3c = 1;
    local_76d = local_76f + '\x01';
    RaceStatus__AddEntrant(&DAT_0078a2f0);
    cVar1 = DriverInfo__IsPlayerKind();
    if ((cVar1 != '\0') || (cVar1 = DriverInfo__IsRivalKind(), cVar1 != '\0')) {
      FUN_0043b560((int)local_76f,param_2,0,local_780);
    }
  }
  return;
}


// ==== 0x43b4e0 FUN_0043b4e0

/* WARNING: Removing unreachable block (ram,0x0043b547) */

void __thiscall FUN_0043b4e0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = RaceStatus__FindEntrantById();
  if ((iVar1 != 0) && (FUN_0043ca70(iVar1,param_3), *(int *)(param_1 + 8 + param_2 * 4) != 0)) {
    Race__GetPlayer(param_2);
    FUN_0042ae40();
    FUN_00548a00(param_3);
  }
  return;
}


// ==== 0x43b560 FUN_0043b560

void __thiscall
FUN_0043b560(int param_1,uint param_2,undefined4 param_3,undefined1 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 local_2c;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_006861ab;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0043b680();
  if (*(int *)(param_1 + 8 + param_2 * 4) == 0) {
    iVar1 = FUN_00401000("OnlineRacer",0);
    local_8 = 0;
    if (iVar1 == 0) {
      local_2c = 0;
    }
    else {
      local_2c = FUN_00438ec0(param_2 & 0xff,param_4,param_5);
    }
    local_8 = 0xffffffff;
    *(undefined4 *)(param_1 + 8 + param_2 * 4) = local_2c;
    FUN_004390d0(1);
    *(char *)(param_1 + 0x18) = *(char *)(param_1 + 0x18) + '\x01';
  }
  else {
    iVar1 = Race__GetPlayer(param_2);
    if (*(char *)(iVar1 + 0x18) != '\0') {
      Race__GetPlayer(param_2);
      FUN_00438fe0(param_5);
    }
  }
  ExceptionList = local_10;
  return;
}


// ==== 0x43b680 FUN_0043b680

void __fastcall FUN_0043b680(int param_1)

{
  char cVar1;
  int local_8;
  
  if ((*(int *)(param_1 + 4) != 0) && (cVar1 = GameMode__IsNotMode0456(), cVar1 == '\0')) {
    *(undefined4 *)(param_1 + 4) = 0;
  }
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    if (*(int *)(param_1 + 8 + local_8 * 4) != 0) {
      Race__GetPlayer(local_8);
      cVar1 = GameMode__IsNotMode0456();
      if (cVar1 == '\0') {
        if (*(int *)(param_1 + 8 + local_8 * 4) != 0) {
          FUN_006497d0();
          FUN_00565ce0();
        }
        *(undefined4 *)(param_1 + 8 + local_8 * 4) = 0;
        *(char *)(param_1 + 0x18) = *(char *)(param_1 + 0x18) + -1;
      }
    }
  }
  return;
}


// ==== 0x43b770 FUN_0043b770

int __fastcall FUN_0043b770(int param_1)

{
  char cVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  local_8 = 0;
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    if (*(int *)(param_1 + 8 + local_c * 4) != 0) {
      iVar2 = Race__GetPlayer(local_c);
      if (iVar2 != *(int *)(param_1 + 4)) {
        Race__GetPlayer(local_c);
        cVar1 = GameMode__IsNotMode0456();
        if (cVar1 != '\0') {
          local_8 = local_8 + 1;
        }
      }
    }
  }
  return local_8;
}


// ==== 0x43b7f0 FUN_0043b7f0

int __fastcall FUN_0043b7f0(int param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    if (*(int *)(param_1 + 8 + local_c * 4) != 0) {
      local_8 = local_8 + 1;
    }
  }
  return local_8;
}


// ==== 0x43b850 Race::GetPlayer

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

undefined4 __thiscall Race__GetPlayer(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 8 + param_2 * 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 8 + param_2 * 4);
  }
  return uVar1;
}


// ==== 0x43b890 FUN_0043b890

undefined4 __fastcall FUN_0043b890(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (3 < local_8) {
      return 0;
    }
    if ((*(int *)(param_1 + 8 + local_8 * 4) != 0) &&
       (iVar1 = Race__GetPlayer(local_8), *(char *)(iVar1 + 0x18) != '\0')) break;
    local_8 = local_8 + 1;
  }
  uVar2 = Race__GetPlayer(local_8);
  return uVar2;
}


// ==== 0x43b900 FUN_0043b900

void __fastcall FUN_0043b900(undefined4 param_1)

{
  FUN_004b5d20(param_1);
  DAT_0078a3fa = 0;
  DAT_00735fa0 = 0;
  return;
}


// ==== 0x43b930 FUN_0043b930

void __thiscall FUN_0043b930(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = FUN_00432810();
  if (iVar2 != 0) {
    DAT_0078a410 = param_2;
    cVar1 = (char)param_2;
    DAT_0078a334 = cVar1 + '\x01';
    *(char *)(iVar2 + 1) = cVar1;
    *(char *)(iVar2 + 3) = cVar1 + '\x01';
    if (param_2 != 0) {
      *(undefined4 *)(param_1 + 8 + param_2 * 4) = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(param_1 + 8) = 0;
    }
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 8 + param_2 * 4);
    *(char *)(*(int *)(param_1 + 4) + 4) = cVar1;
    FUN_00565da0("DUMMY_SKIN%d",*(char *)(iVar2 + 1) + 1);
    FUN_00421a70();
    iVar3 = FUN_0057efe0();
    iVar4 = bStringHash();
    if (iVar3 != iVar4) {
      bStringHash();
      FUN_00421a70();
      FUN_0057eff0();
    }
    FUN_00565da0("DUMMY_WHEEL%d",*(char *)(iVar2 + 1) + 1);
    FUN_00421a70();
    iVar2 = FUN_0057f000();
    iVar3 = bStringHash();
    if (iVar2 != iVar3) {
      bStringHash();
      FUN_00421a70();
      FUN_0057f010();
    }
  }
  return;
}


// ==== 0x43ba60 FUN_0043ba60

void __thiscall FUN_0043ba60(int *param_1,int param_2,char param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int local_10;
  int local_c;
  
  if (param_1[param_2 + 2] != 0) {
    iVar1 = Race__GetPlayer(param_2);
    if (*param_1 == 3) {
      FUN_004390d0(0);
      RaceStatus__RemoveEntrant((int)*(char *)(iVar1 + 4));
      if (*(char *)(iVar1 + 0x18) != '\0') {
        for (local_c = 0; local_c < 4; local_c = local_c + 1) {
          if ((param_1[local_c + 2] != 0) && (iVar2 = Race__GetPlayer(local_c), iVar2 != iVar1)) {
            uVar3 = 0;
            Race__GetPlayer(local_c);
            FUN_004390d0(uVar3);
            iVar2 = Race__GetPlayer(local_c);
            RaceStatus__RemoveEntrant((int)*(char *)(iVar2 + 4));
          }
        }
      }
    }
    else if (DAT_0073619c == 0) {
      FUN_004390d0((param_3 != '\0') + '\x04');
    }
    else {
      HudOnlineMsgBox__PushPlayerMessage(iVar1);
      if (*param_1 == 7) {
        FUN_00439470(0,10);
      }
      else {
        FUN_00439470((param_3 != '\0') + '\x04',10);
      }
      if (*(char *)(iVar1 + 0x18) != '\0') {
        for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
          if ((param_1[local_10 + 2] != 0) && (iVar2 = Race__GetPlayer(local_10), iVar2 != iVar1)) {
            uVar4 = 10;
            uVar3 = 0;
            Race__GetPlayer(local_10);
            FUN_00439470(uVar3,uVar4);
          }
        }
      }
    }
  }
  return;
}


// ==== 0x43bc30 FUN_0043bc30

void __thiscall FUN_0043bc30(int param_1,undefined4 param_2)

{
  FUN_005488d0(8);
  if (*(int *)(param_1 + 8) != 0) {
    Race__GetPlayer(0);
    FUN_004392c0(param_2);
  }
  return;
}


// ==== 0x43bc90 FUN_0043bc90

void FUN_0043bc90(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = BitStream__ReadBitsValue();
  uVar2 = BitStream__ReadU32();
  uVar3 = BitStream__ReadU32();
  iVar4 = Race__GetPlayer(uVar1);
  if ((iVar4 != 0) && (*(uint *)(iVar4 + 0x1a8) < uVar2)) {
    *(uint *)(iVar4 + 0x1a8) = uVar2;
    Race_TickTrackerSet(uVar3);
  }
  return;
}


// ==== 0x43bd10 FUN_0043bd10

void __fastcall FUN_0043bd10(int *param_1)

{
  byte bVar1;
  char cVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  int local_10;
  
  if ((*param_1 == 6) || (*param_1 == 5)) {
    bVar1 = BitStream__ReadBitsValue();
    FUN_00436db0();
    BitStream__ReadBitsValue();
    fVar3 = (float10)FUN_00548c30();
    if (bVar1 == *(byte *)(param_1 + 0x10)) {
      for (local_10 = 0; local_10 < (int)(uint)bVar1; local_10 = local_10 + 1) {
        FUN_00417490();
        cVar2 = BitStream__ReadBool();
        FUN_00436db0();
        BitStream__ReadBitsValue();
        fVar4 = (float10)FUN_00548c30();
        if (cVar2 == '\0') {
          FUN_0057a170();
        }
        else {
          FUN_0057a160();
        }
        fVar5 = (float10)bTickerToSeconds();
        FUN_00579f90((float)fVar4 + (float)(fVar5 - (float10)(float)fVar3));
      }
    }
  }
  return;
}


// ==== 0x43be30 FUN_0043be30

char __thiscall
FUN_0043be30(int param_1,int param_2,undefined4 param_3,undefined1 param_4,int param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_18;
  char local_5;
  
  local_5 = '\0';
  if (*(int *)(param_1 + 8 + param_2 * 4) != 0) {
    iVar2 = Race__GetPlayer(param_2);
    local_5 = GameMode__IsMode03456();
    if ((local_5 == '\0') && (iVar2 == *(int *)(param_1 + 4))) {
      if ((param_5 == 1) &&
         (((cVar1 = IsDriftMode(), cVar1 == '\0' && (cVar1 = FUN_00421a50(), cVar1 == '\0')) &&
          (DAT_0078a318 == 0)))) {
        Race__GetRacingCarOfRacer();
        iVar3 = FUN_0042ac60();
        if (iVar3 < DAT_0078a31c) {
          FUN_004399a0(0x10);
          FUN_0043a830();
          return '\0';
        }
        iVar3 = RaceOptions_Get();
        iVar4 = FUN_0042ac60();
        if (iVar4 < *(int *)(iVar3 + 0x10)) {
          FUN_004399a0(0x10);
          FUN_0043a830();
          return '\0';
        }
      }
      cVar1 = IsDriftMode();
      if (cVar1 != '\0') {
        FUN_0043d030();
      }
      NetPlayer__SendFinishMessage(param_3,param_4,param_5);
      local_5 = '\x01';
      if ((param_5 == 9) && (iVar3 = FUN_00421ac0(iVar2), 0 < iVar3)) {
        for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
          iVar3 = Race__GetPlayer(local_18);
          if ((iVar3 != 0) && (iVar3 != iVar2)) {
            FUN_00439470(0,10);
          }
        }
      }
    }
  }
  return local_5;
}


// ==== 0x43bfe0 FUN_0043bfe0

void __fastcall FUN_0043bfe0(int param_1)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint local_6c;
  uint local_68;
  int local_50;
  uint local_44;
  int local_40;
  int local_34 [6];
  char local_19;
  int local_18;
  int aiStack_14 [4];
  
  local_18 = 0;
  for (local_34[5] = 0; local_34[5] < 4; local_34[5] = local_34[5] + 1) {
    if (*(int *)(param_1 + 8 + local_34[5] * 4) != 0) {
      iVar4 = Race__GetPlayer(local_34[5]);
      aiStack_14[local_18] = iVar4;
      local_18 = local_18 + 1;
    }
  }
  do {
    local_19 = '\0';
    for (local_34[4] = 0; local_34[4] < local_18 + -1; local_34[4] = local_34[4] + 1) {
      iVar4 = aiStack_14[local_34[4]];
      iVar7 = aiStack_14[local_34[4] + 1];
      local_34[2] = 0;
      local_34[3] = 0;
      local_34[0] = FUN_00432e70();
      local_34[1] = FUN_00432e70();
      for (local_40 = 0; local_40 < 2; local_40 = local_40 + 1) {
        if (*(int *)(local_34[local_40] + 8) == 10) {
          local_34[local_40 + 2] = local_34[local_40 + 2] + 2;
        }
        else if (*(int *)(local_34[local_40] + 8) != 1) {
          local_34[local_40 + 2] = local_34[local_40 + 2] + 1;
        }
      }
      if (local_34[2] == local_34[3]) {
        local_44 = 0xffffffff;
        cVar3 = IsDriftMode();
        if (cVar3 == '\0') {
          if (local_34[2] == 0) {
            if (*(int *)(local_34[0] + 0xc) != *(int *)(local_34[1] + 0xc)) {
              iVar5 = int_Less();
              local_44 = (uint)(iVar5 != 0);
            }
          }
          else if (*(float *)(local_34[0] + 0x7c) != *(float *)(local_34[1] + 0x7c)) {
            local_6c = (uint)(*(float *)(local_34[1] + 0x7c) < *(float *)(local_34[0] + 0x7c));
            local_44 = local_6c;
          }
        }
        else {
          fVar1 = (float)*(int *)(local_34[0] + 0xf4 + DAT_0078a31c * 4);
          fVar2 = (float)*(int *)(local_34[1] + 0xf4 + DAT_0078a31c * 4);
          if (fVar1 != fVar2) {
            local_68 = (uint)(fVar2 < fVar1);
            local_44 = local_68;
          }
        }
        if (-1 < (int)local_44) {
          local_34[local_44 + 2] = local_34[local_44 + 2] + 1;
        }
      }
      if (local_34[3] < local_34[2]) {
        aiStack_14[local_34[4]] = iVar7;
        aiStack_14[local_34[4] + 1] = iVar4;
        local_19 = '\x01';
      }
    }
  } while (local_19 != '\0');
  for (local_50 = 0; local_50 < local_18; local_50 = local_50 + 1) {
    iVar4 = aiStack_14[local_50];
    piVar6 = (int *)FUN_00432e70();
    *piVar6 = local_50 + 1;
    iVar7 = Race__GetRacingCarOfRacer();
    *(char *)(iVar7 + 0xc) = (char)local_50 + '\x01';
    if (local_50 == 0) {
      iVar7 = FUN_00432e70();
      *(float *)(iVar7 + 0xbc) = *(float *)(iVar7 + 0xbc) + *(float *)(DAT_00736198 + 0x1b8);
      if (iVar4 == *(int *)(param_1 + 4)) {
        Race__FindRacerById();
        uVar8 = FUN_00424db0();
        uVar9 = 0x3f800000;
        FUN_00432d40(0x3f800000);
        StyleItemTable__TriggerItem(uVar9);
        uVar10 = 0;
        uVar9 = FUN_00432d40(uVar8,0);
        StyleItemTable__Update(uVar9,uVar8,uVar10);
      }
    }
  }
  return;
}


// ==== 0x43c300 FUN_0043c300

/* WARNING: Removing unreachable block (ram,0x0043c451) */
/* WARNING: Removing unreachable block (ram,0x0043c9cd) */

void __fastcall FUN_0043c300(int param_1)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  float10 fVar4;
  undefined1 local_9a4 [1024];
  int local_5a4;
  int local_5a0;
  int local_59c;
  int local_598;
  int *local_594;
  undefined4 *local_590;
  undefined1 *local_58c;
  undefined1 local_585;
  undefined4 local_584 [49];
  undefined4 local_4c0;
  undefined4 auStack_4bc [11];
  undefined4 auStack_490 [27];
  int local_424;
  uint local_420;
  undefined1 local_41c [1040];
  undefined4 local_c;
  undefined1 *local_8;
  
  FUN_00548820();
  local_420 = 0;
  cVar2 = FUN_00421a50();
  if (cVar2 == '\0') {
    cVar2 = IsDriftMode();
    if (cVar2 == '\0') {
      if (DAT_0078a318 != 0) {
        local_420 = 1;
      }
    }
    else {
      local_420 = 3;
    }
  }
  else {
    local_420 = 2;
  }
  uVar3 = FUN_0043b7f0();
  FUN_00548840(uVar3);
  FUN_00548840(local_420 & 0xff);
  FUN_00548840(*(undefined1 *)(*(int *)(param_1 + 4) + 5));
  FUN_00548840((int)(short)DAT_0078a2f0);
  FUN_00548840((undefined1)DAT_0078a2fc);
  FUN_00548840(DAT_0078a31c & 0xff);
  for (local_424 = 0; local_424 < 4; local_424 = local_424 + 1) {
    if (*(int *)(param_1 + 8 + local_424 * 4) != 0) {
      local_594 = (int *)Race__GetPlayer(local_424);
      PtrSlots__PtrSlots();
      local_590 = (undefined4 *)FUN_00432e70();
      if ((local_594 != *(int **)(param_1 + 4)) &&
         (local_598 = Race__GetRacingCarOfRacer(), local_598 != 0)) {
        FUN_004acd20(local_598,1);
        local_584[0] = *local_590;
        auStack_490[DAT_0078a31c] = local_590[DAT_0078a31c + 0x3d];
        local_4c0 = local_590[0x31];
        for (local_59c = 1; local_59c <= (int)DAT_0078a31c; local_59c = local_59c + 1) {
          auStack_4bc[local_59c] = local_590[local_59c + 0x32];
        }
        local_590 = local_584;
      }
      FUN_00548840(*(undefined1 *)((int)local_594 + 5));
      RaceStatus__FindCurrentEntrant();
      uVar3 = DriverInfo__IsRivalKind();
      FUN_00548840(uVar3);
      FUN_00548840(*(undefined1 *)local_590);
      FUN_00548840(*(undefined1 *)(local_590 + 2));
      FUN_00548a80(local_590[0x1f]);
      fVar4 = (float10)bTickerToSeconds();
      FUN_00548a80((float)fVar4);
      if (local_590[0x1e] == 0) {
        FUN_00548a80(0);
      }
      else {
        fVar4 = (float10)bTickerToSeconds();
        FUN_00548a80((float)fVar4);
      }
      for (local_5a0 = 1; local_5a0 <= (int)DAT_0078a31c; local_5a0 = local_5a0 + 1) {
        fVar4 = (float10)bTickerToSeconds();
        FUN_00548a80((float)fVar4);
      }
      FUN_00548a80(local_590[7]);
      FUN_00548a80(local_590[6]);
      FUN_00548a80(local_590[0x2b]);
      fVar4 = (float10)bTickerToSeconds();
      FUN_00548a80((float)fVar4);
      fVar4 = (float10)bTickerToSeconds();
      FUN_00548a80((float)fVar4);
      FUN_00548a80(local_590[0x2e]);
      BitStream__WriteBitsThunk();
      BitStream__WriteBitsThunk();
      for (local_5a4 = 1; local_5a4 <= (int)DAT_0078a31c; local_5a4 = local_5a4 + 1) {
        BitStream__WriteBitsThunk();
      }
      BitStream__WriteBitsThunk();
      FUN_00548840(local_594[0x62] & 0xff);
      iVar1 = *local_594;
      if (iVar1 == 4) {
        local_585 = 1;
      }
      else if (iVar1 == 5) {
        local_585 = 2;
      }
      else if (iVar1 == 6) {
        local_585 = 3;
      }
      else {
        local_585 = 0;
      }
      FUN_00548840(local_585);
      RaceStatus__FindCurrentEntrant();
      local_58c = (undefined1 *)FUN_00421a70();
      FUN_00548840(*local_58c);
      RideInfo__GetAccelRating();
      uVar3 = _ftol_nocw();
      FUN_00548840(uVar3);
      RideInfo__GetTopSpeedRating();
      uVar3 = _ftol_nocw();
      FUN_00548840(uVar3);
      RideInfo__GetHandlingRating();
      uVar3 = _ftol_nocw();
      FUN_00548840(uVar3);
    }
  }
  local_8 = local_41c;
  local_c = BitStream__GetSizeInBytes();
  if (DAT_006f1f64 != 0) {
    FUN_005ab2b0(local_8,local_c,local_9a4,0x400,1);
    FUN_0054b170(&DAT_0073d868);
  }
  return;
}


// ==== 0x43ca70 FUN_0043ca70

void FUN_0043ca70(int param_1,undefined4 param_2)

{
  FUN_00548840(*(undefined1 *)(param_1 + 4));
  FUN_00548840(*(undefined1 *)(param_1 + 1));
  FUN_0043cb60(param_1 + 0x10,param_2,1);
  return;
}


// ==== 0x43cad0 FUN_0043cad0

void FUN_0043cad0(int param_1,undefined4 param_2)

{
  FUN_005488d0(8);
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_005488d0(8);
  *(undefined1 *)(param_1 + 1) = 0;
  FUN_0043ccf0(param_1 + 0x10,param_2,*(char *)(param_1 + 1) + 1);
  *(undefined1 *)(param_1 + 0x735) = 0xfe;
  *(undefined4 *)(param_1 + 0x730) = 0;
  return;
}


// ==== 0x43cb60 FUN_0043cb60

/* WARNING: Removing unreachable block (ram,0x0043ccde) */

void FUN_0043cb60(undefined4 param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  int local_18;
  int local_14;
  int local_10;
  
  BitStream__GetSizeInBytes();
  BitStream__WriteClampedInt();
  for (local_10 = 0; local_10 < 0xb; local_10 = local_10 + 1) {
    FUN_00424c60();
    FUN_00575950();
    BitStream__WriteClampedInt();
    FUN_00424c60();
    FUN_00424c40();
    BitStream__WriteByteBits();
  }
  if (param_3 == '\0') {
    BitStream__WriteClampedInt();
  }
  else {
    BitStream__WriteClampedInt();
    local_14 = 0;
    for (local_18 = 0; local_18 < 0x78; local_18 = local_18 + 1) {
      if ((local_14 < 0xc) && (local_18 == *(int *)(&DAT_00700a28 + local_14 * 4))) {
        local_14 = local_14 + 1;
      }
      else {
        iVar1 = FUN_0057ea40();
        if (iVar1 == 0) {
          BitStream__WriteClampedInt();
        }
        else {
          FUN_0057ccb0((int)*(char *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 8));
          BitStream__WriteClampedInt();
        }
      }
    }
  }
  return;
}


// ==== 0x43ccf0 FUN_0043ccf0

void __thiscall FUN_0043ccf0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_2c [9];
  undefined1 local_8 [4];
  
  BitStream__ReadQuantizedInt(local_8,param_1 + 0x1e0);
  Ride_Init(param_4,0,0);
  FUN_00565da0("DUMMY_SKIN%d",param_4);
  bStringHash();
  FUN_0057eff0();
  FUN_00565da0("DUMMY_WHEEL%d",param_4);
  bStringHash();
  FUN_0057f010();
  for (local_3c = 0; local_3c < 0xb; local_3c = local_3c + 1) {
    BitStream__ReadQuantizedInt(local_8,param_1 + 0x468);
    FUN_00424c60();
    FUN_004175a0();
    FUN_005488d0(1);
    FUN_00424c60();
    FUN_004175b0();
  }
  RideInfo__RebuildPhysicsInfo(1);
  BitStream__ReadQuantizedInt(local_2c,param_1 + 0x9c);
  if (local_2c[0] == 0) {
    FUN_0057d340(param_2);
  }
  else {
    local_40 = 0;
    local_44 = 0;
    local_48 = 0;
    while ((local_48 < 0x78 && (local_44 < local_2c[0]))) {
      if ((local_40 < 0xc) && (local_48 == *(int *)(&DAT_00700a28 + local_40 * 4))) {
        local_40 = local_40 + 1;
      }
      else {
        FUN_00436db0();
        BitStream__ReadBitsValue();
        iVar1 = FUN_005491b0();
        if ((iVar1 < 0x1ffe) && (iVar1 = FUN_0057cd30(), iVar1 != 0)) {
          FUN_0057ea50();
        }
        local_44 = local_44 + 1;
      }
      local_48 = local_48 + 1;
    }
  }
  return;
}


// ==== 0x43cef0 FUN_0043cef0

void __fastcall FUN_0043cef0(int param_1)

{
  char cVar1;
  float10 fVar2;
  int local_418;
  
  if (*(char *)(param_1 + 0x40) != '\0') {
    FUN_00548820();
    FUN_00548840(*(undefined1 *)(param_1 + 0x40));
    fVar2 = (float10)bTickerToSeconds();
    BitStream__WriteFloatRounded((float)fVar2);
    for (local_418 = 0; local_418 < (int)(uint)*(byte *)(param_1 + 0x40); local_418 = local_418 + 1)
    {
      FUN_00417490();
      FUN_0057a180();
      BitStream__WriteByteBits();
      fVar2 = (float10)FUN_00579fc0();
      BitStream__WriteFloatRounded((float)fVar2);
    }
    cVar1 = FUN_005466e0();
    if (cVar1 != '\0') {
      thunk_FUN_00547770();
    }
  }
  return;
}


// ==== 0x43d030 FUN_0043d030

void __fastcall FUN_0043d030(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  FUN_00424f10();
  FUN_00432d40();
  FUN_00575950();
  FUN_00432d10();
  uVar2 = _ftol_nocw();
  Race_TickTrackerSet(uVar2);
  FUN_00548820();
  FUN_00548840(*(undefined1 *)(*(int *)(param_1 + 4) + 4));
  *(int *)(*(int *)(param_1 + 4) + 0x1a8) = *(int *)(*(int *)(param_1 + 4) + 0x1a8) + 1;
  BitStream__WriteBitsThunk();
  FUN_004134c0();
  BitStream__WriteBitsThunk();
  cVar1 = FUN_005466e0();
  if (cVar1 != '\0') {
    FUN_00546850();
  }
  return;
}


// ==== 0x43d120 FUN_0043d120

void __fastcall FUN_0043d120(int param_1)

{
  undefined4 local_8;
  
  *(undefined1 *)(param_1 + 0x40) = 0;
  for (local_8 = 0; local_8 < 8; local_8 = local_8 + 1) {
    *(undefined4 *)(param_1 + 0x20 + local_8 * 4) = 0;
  }
  return;
}


// ==== 0x43d160 FUN_0043d160

void __fastcall FUN_0043d160(int param_1)

{
  int iVar1;
  
  FUN_0043d120();
  bStringHash();
  while( true ) {
    do {
      iVar1 = FUN_00577dd0();
      if (iVar1 == 0) {
        return;
      }
    } while ((*(int *)(iVar1 + 0x34) == 0) || (*(int *)(iVar1 + 0x24) != 4));
    if (*(char *)(param_1 + 0x40) == '\b') break;
    *(int *)(param_1 + 0x20 + (uint)*(byte *)(param_1 + 0x40) * 4) = iVar1;
    *(char *)(param_1 + 0x40) = *(char *)(param_1 + 0x40) + '\x01';
  }
  return;
}


// ==== 0x43d1f0 FUN_0043d1f0

void __thiscall FUN_0043d1f0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x5c);
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== 0x43d220 Race::ApplyPendingSlotNames

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

void __fastcall Race__ApplyPendingSlotNames(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    if (*(char *)(param_1 + 0x5c + local_8 * 0xd) != '\0') {
      for (local_c = 0; local_c < 4; local_c = local_c + 1) {
        iVar1 = Race__GetPlayer(local_c);
        if (iVar1 != 0) {
          FUN_0042ae40();
          iVar2 = bStrICmp();
          if (iVar2 == 0) {
            *(undefined1 *)(iVar1 + 5) = (undefined1)local_8;
          }
        }
      }
    }
  }
  puVar3 = (undefined4 *)(param_1 + 0x5c);
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ==== 0x43d2d0 FUN_0043d2d0

/* WARNING: Removing unreachable block (ram,0x0043d379) */

void __thiscall FUN_0043d2d0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  
  if ((*(int *)(param_1 + 8 + param_2 * 4) != 0) && (iVar2 = Float2_ToIntPair(), 1 < iVar2)) {
    Race__GetPlayer(param_2);
    fVar3 = (float10)Countdown__GetTotalSeconds();
    cVar1 = GameMode__IsMode03456();
    if ((cVar1 == '\0') &&
       ((*(float *)(param_1 + 0x1c) == 0.0 ||
        (fVar4 = (float10)bTickerToSeconds(),
        fVar4 < (float10)(float)fVar3 + (float10)*(float *)(param_1 + 0x1c))))) {
      FUN_004399a0(1);
    }
    if ((DAT_007361f8 != 0) && (iVar2 = RaceManager__FindRacerByIdIn(), iVar2 != 0)) {
      (**(code **)(**(int **)(iVar2 + 0x830) + 0xc))(param_3,param_4);
    }
  }
  return;
}


// ==== 0x43d3d0 FUN_0043d3d0

/* WARNING: Removing unreachable block (ram,0x0043d484) */

void __thiscall FUN_0043d3d0(int param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  
  if (((DAT_0073619c == 0) || (iVar2 = FUN_00421960(), 3 < iVar2)) &&
     (*(int *)(param_1 + 8 + param_2 * 4) != 0)) {
    Race__GetPlayer(param_2);
    fVar3 = (float10)Countdown__GetTotalSeconds();
    cVar1 = GameMode__IsMode03456();
    if ((cVar1 == '\0') &&
       ((*(float *)(param_1 + 0x1c) == 0.0 ||
        (fVar4 = (float10)bTickerToSeconds(),
        fVar4 < (float10)(float)fVar3 + (float10)*(float *)(param_1 + 0x1c))))) {
      FUN_004399a0(1);
    }
    if ((DAT_007361f8 != 0) && (iVar2 = RaceManager__FindRacerByIdIn(), iVar2 != 0)) {
      (**(code **)(**(int **)(iVar2 + 0x830) + 4))(param_3);
    }
  }
  return;
}


// ==== 0x43d4f0 FUN_0043d4f0

/* WARNING: Removing unreachable block (ram,0x0043d4ff) */

void __fastcall FUN_0043d4f0(int param_1)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  
  iVar1 = SpecialCamCooldown();
  if (iVar1 != 0) {
    int_Sub(param_1 + 0x90);
    fVar2 = (float10)bTickerToSeconds();
    int_Sub(param_1 + 0x94);
    fVar3 = (float10)bTickerToSeconds();
    fVar2 = (float10)FUN_00405600((float)fVar2 - (float)fVar3);
    if (((((float10)0.25 * (float10)2.0 < fVar2) && (iVar1 = FUN_0043b890(), iVar1 != 0)) &&
        (FUN_004399a0(2), iVar1 == *(int *)(param_1 + 4))) &&
       (iVar1 = FUN_00421ac0(iVar1), 5 < iVar1)) {
      FUN_0043a830();
    }
  }
  FUN_00405560();
  FUN_00405560();
  return;
}


// ==== 0x43d5f0 FUN_0043d5f0

/* WARNING: Removing unreachable block (ram,0x0043d6a9) */

void __fastcall FUN_0043d5f0(int param_1)

{
  char cVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 4) != 0) {
    FUN_00548820();
    FUN_00548840(*(undefined1 *)(*(int *)(param_1 + 4) + 4));
    FUN_004399f0(1);
    BitStream__WriteBitsThunk();
    cVar1 = FUN_005466e0();
    if (cVar1 != '\0') {
      FUN_00546880();
    }
    iVar2 = FUN_004399f0(0);
    if (iVar2 != *(int *)(param_1 + 0x98)) {
      FUN_004399a0(0x20);
      FUN_0043a830();
    }
  }
  return;
}


// ==== 0x43d6e0 FUN_0043d6e0

void __fastcall FUN_0043d6e0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = BitStream__ReadBitsValue();
  iVar2 = BitStream__ReadU32();
  if (*(int *)(param_1 + 8 + cVar1 * 4) != 0) {
    Race__GetPlayer((int)cVar1);
    iVar3 = FUN_004399f0(0);
    if (iVar2 != iVar3) {
      FUN_004399a0(0x20);
    }
  }
  return;
}


// ==== 0x43d760 FUN_0043d760

undefined1 __fastcall FUN_0043d760(int *param_1)

{
  int iVar1;
  int local_c;
  
  if (*param_1 == 7) {
    for (local_c = 0; local_c < 4; local_c = local_c + 1) {
      if ((param_1[local_c + 2] != 0) &&
         (iVar1 = Race__GetPlayer(local_c), *(int *)(iVar1 + 0x188) != 0)) {
        return 1;
      }
    }
  }
  return 0;
}


// ==== 0x43d7e0 FUN_0043d7e0

void FUN_0043d7e0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 local_70;
  undefined4 local_54;
  undefined4 local_38;
  undefined4 local_1c;
  int local_8;
  
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    iVar2 = Race__GetPlayer(local_8);
    if (iVar2 != 0) {
      FUN_0042ae40();
      iVar3 = FUN_0054a1b0();
      if (iVar3 == 0) {
        cVar1 = FUN_00421a50();
        if (cVar1 == '\0') {
          cVar1 = IsDriftMode();
          if (cVar1 == '\0') {
            if (DAT_0078a318 == 0) {
              *(undefined4 *)(iVar2 + 8) = local_70;
            }
            else {
              *(undefined4 *)(iVar2 + 8) = local_54;
            }
          }
          else {
            *(undefined4 *)(iVar2 + 8) = local_1c;
          }
        }
        else {
          *(undefined4 *)(iVar2 + 8) = local_38;
        }
        if (*(uint *)(iVar2 + 8) < 100) {
          *(undefined4 *)(iVar2 + 8) = 100;
        }
      }
    }
  }
  return;
}


// ==== 0x43d8c0 FUN_0043d8c0

uint __thiscall FUN_0043d8c0(int *param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  undefined4 uVar7;
  int local_20;
  undefined1 local_18;
  uint local_c;
  
  local_c = 0;
  iVar4 = Race__GetPlayer(param_2);
  if (iVar4 != 0) {
    if (param_3 == 0) {
      puVar5 = (uint *)FUN_00432e70();
      param_3 = *puVar5;
    }
    uVar1 = *(uint *)(iVar4 + 8);
    iVar6 = FUN_0043da30();
    local_18 = 0;
    cVar3 = FUN_00421a50();
    if (cVar3 == '\0') {
      cVar3 = IsDriftMode();
      if (cVar3 == '\0') {
        if (DAT_0078a318 != 0) {
          local_18 = 1;
        }
      }
      else {
        local_18 = 3;
      }
    }
    else {
      local_18 = 2;
    }
    uVar7 = FUN_0043b7f0((undefined1)DAT_0078a31c,local_18,(undefined2)DAT_0078a2f0);
    local_c = Career_ComputeCashAfterRace(uVar1,param_3 & 0xff,iVar6 - uVar1,uVar7);
    if (*param_1 == 7) {
      if (uVar1 < local_c) {
        iVar4 = FUN_00432e70();
        if (*(int *)(iVar4 + 8) != 1) {
          local_c = uVar1;
        }
      }
      else if (local_c < uVar1) {
        bVar2 = false;
        for (local_20 = 0; local_20 < 4; local_20 = local_20 + 1) {
          iVar6 = Race__GetPlayer(local_20);
          if (((iVar6 != 0) && (iVar6 != iVar4)) &&
             (iVar6 = FUN_00432e70(), *(int *)(iVar6 + 8) == 1)) {
            bVar2 = true;
            break;
          }
        }
        if (!bVar2) {
          local_c = uVar1;
        }
      }
    }
  }
  return local_c;
}


// ==== 0x43da30 FUN_0043da30

int __fastcall FUN_0043da30(int param_1)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    if (*(int *)(param_1 + 8 + local_c * 4) != 0) {
      iVar1 = Race__GetPlayer(local_c);
      local_8 = local_8 + *(int *)(iVar1 + 8);
    }
  }
  return local_8;
}


// ==== 0x43da90 FUN_0043da90

undefined4 __fastcall FUN_0043da90(int *param_1)

{
  char cVar1;
  int iVar2;
  float10 fVar3;
  undefined4 local_14;
  
  if (*param_1 == 7) {
    cVar1 = GameMode__IsNotMode0456();
    if ((cVar1 == '\0') && (*(int *)param_1[1] != 5)) {
      iVar2 = SpecialCamCooldown();
      if (iVar2 != 0) {
        int_Sub(param_1 + 0x15);
        fVar3 = (float10)bTickerToSeconds();
        if ((float10)3.0 < fVar3) {
          return 1;
        }
      }
      local_14 = 0;
    }
    else {
      local_14 = 1;
    }
  }
  else if (*param_1 == 0) {
    local_14 = 1;
  }
  else {
    local_14 = 0;
  }
  return local_14;
}


// ==== 0x43db30 FUN_0043db30

void __fastcall FUN_0043db30(undefined1 param_1)

{
  int in_EAX;
  
  *(undefined1 *)(in_EAX + 0x15) = param_1;
  return;
}


// ==== 0x43db40 FUN_0043db40

float10 FUN_0043db40(void)

{
  int in_EAX;
  
  return (float10)*(float *)(in_EAX + 0x24);
}


// ==== 0x43db50 RacerRecord::SetRank

/* [canon] rivals low (ghidra-canon) docs/re/rivals.md */

void RacerRecord__SetRank(undefined2 param_1)

{
  int in_EAX;
  
  *(undefined2 *)(in_EAX + 0x1a) = param_1;
  return;
}


// ==== 0x43db60 FUN_0043db60

int FUN_0043db60(void)

{
  int in_EAX;
  
  return (int)*(short *)(in_EAX + 0x1a);
}


// ==== 0x43db70 Zone_FindTrafficDensity

/* [canon] traffic med (G+H) docs/re/traffic.md */

void Zone_FindTrafficDensity(void)

{
  undefined4 in_EAX;
  
  Zone_Find(in_EAX);
  return;
}


// ==== 0x43db80 FUN_0043db80

int __fastcall FUN_0043db80(int param_1)

{
  FUN_00556750();
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined1 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 8) = 0xffffffff;
  *(undefined1 **)(param_1 + 0x18) = &DAT_006b9172;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xc) = 3;
  return param_1;
}


// ==== 0x43dbb0 FUN_0043dbb0

void FUN_0043dbb0(undefined4 param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int unaff_ESI;
  
  FUN_00556750();
  *(undefined4 *)(unaff_ESI + 8) = param_2;
  *(undefined4 *)(unaff_ESI + 0x10) = param_1;
  *(undefined1 *)(unaff_ESI + 0x14) = param_3;
  *(undefined4 *)(unaff_ESI + 0x18) = param_4;
  *(undefined4 *)(unaff_ESI + 0x1c) = param_5;
  *(undefined4 *)(unaff_ESI + 0xc) = param_6;
  return;
}


// ==== 0x43dbf0 RivalList::GetRival

/* [canon] rivals med (ghidra-canon) docs/re/canon.md */

int __fastcall RivalList__GetRival(int param_1)

{
  int in_EAX;
  
  if ((-1 < in_EAX) && (in_EAX < *(int *)(param_1 + 0x128))) {
    return in_EAX * 0x1c + 0xd4 + param_1;
  }
  return 0;
}


// ==== 0x43dc10 FUN_0043dc10

int FUN_0043dc10(void)

{
  int in_EAX;
  
  return in_EAX + 0x58a0;
}


// ==== 0x43dc20 RacerRecord::_RacerRecord

/* [canon] rivals med (ghidra-canon) docs/re/canon.md */

void __fastcall RacerRecord___RacerRecord(undefined4 param_1)

{
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1);
  return;
}


// ==== 0x43dc40 DriftManager::DriftManager

/* [canon] runtime high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 * __fastcall DriftManager__DriftManager(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  Ptr_SetNull();
  Ptr_SetNull();
  param_1[1] = 0;
  *param_1 = 0;
  param_1[6] = 1;
  param_1[5] = 1;
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  *(undefined1 *)((int)param_1 + 0x12) = 0;
  *(undefined1 *)((int)param_1 + 0x13) = 0;
  param_1[10] = 0xbf800000;
  param_1[7] = 0;
  param_1[0x15] = 0;
  param_1[2] = 0;
  FUN_00424cc0();
  FUN_00424cc0();
  puVar2 = param_1 + 0xb;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  return param_1;
}


// ==== 0x43dd10 DriftManager::_DriftManager

/* [canon] runtime high (ghidra-canon+nfsug) docs/re/canon.md */

void __fastcall DriftManager___DriftManager(undefined4 param_1)

{
  int iVar1;
  
  while( true ) {
    iVar1 = bList__IsEmpty(param_1);
    if (iVar1 != 0) break;
    bList__RemoveHead();
  }
  return;
}


// ==== 0x43dd40 FUN_0043dd40

void __thiscall FUN_0043dd40(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  float10 fVar4;
  int local_1c;
  int local_c;
  
  param_1[1] = param_2;
  uVar2 = FUN_00432d40();
  *param_1 = uVar2;
  uVar2 = FUN_00417490();
  param_1[2] = uVar2;
  FUN_0041e4c0();
  cVar1 = FUN_0057f150();
  param_1[3] = (int)cVar1;
  uVar2 = _ftol_nocw();
  param_1[7] = uVar2;
  iVar3 = FUN_0041e4c0();
  if (iVar3 == 0) {
    if (DAT_0078a347 == '\0') {
      local_1c = 4;
    }
    else {
      local_1c = FUN_0042ab20();
    }
    for (local_c = 0; local_c < local_1c; local_c = local_c + 1) {
      *(undefined4 *)(&DAT_0077b1b0 + local_c * 0x28) = 0;
      fVar4 = (float10)FUN_00564a80(0x3f800000);
      *(float *)(&DAT_0077b1c4 + local_c * 0x28) = (float)fVar4;
      iVar3 = FUN_0041f5c0();
      if (*(int *)(&DAT_0077b1a8 + local_c * 0x28) == iVar3) {
        uVar2 = FUN_00431d30(param_2);
        *(undefined4 *)(&DAT_0077b1b8 + local_c * 0x28) = uVar2;
      }
      bList__AddTail();
    }
  }
  FUN_00575950();
  FUN_0043db30();
  return;
}


// ==== 0x43de90 DriftManager::BuildLeaderBoard

/* WARNING: Removing unreachable block (ram,0x0043e1e4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] runtime med (ghidra-canon+nfsug) docs/re/runtime.md */

void DriftManager__BuildLeaderBoard(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float10 fVar5;
  undefined4 uVar6;
  undefined1 local_7dc [40];
  undefined4 local_7b4;
  int local_7b0;
  int local_7ac;
  int local_7a8;
  int local_7a4;
  int local_7a0 [456];
  int local_80;
  int local_7c;
  int local_78 [4];
  byte local_65;
  int local_64;
  undefined4 *local_60;
  undefined1 local_5c [40];
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_29;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  float local_18;
  int *local_14;
  
  while (iVar2 = bList__IsEmpty(), iVar2 == 0) {
    bList__RemoveHead();
  }
  local_14 = (int *)0x0;
  local_18 = 99.9;
  local_1c = 999;
  local_20 = 0;
  for (local_24 = 0; local_24 < DAT_0078a320 + DAT_0078a328; local_24 = local_24 + 1) {
    local_28 = RaceStatus__GetEntrantAt();
    local_29 = 0;
    local_30 = 0;
    cVar1 = DriverInfo__IsPlayerKind();
    if ((cVar1 == '\0') || (cVar1 = DriverInfo__IsRemote(), cVar1 != '\0')) {
      cVar1 = DriverInfo__IsRemote();
      if ((cVar1 != '\0') && (cVar1 = DriverInfo__IsRivalKind(), cVar1 == '\0')) {
        local_34 = Race__GetPlayer((int)*(char *)(local_28 + 1));
        local_30 = FUN_0042ae40();
      }
    }
    else {
      local_14 = (int *)FUN_00421a70();
      local_29 = 1;
      cVar1 = FUN_0043a2e0();
      if (cVar1 == '\0') {
        local_30 = FUN_00580af0();
      }
      else {
        FUN_00417490();
        local_30 = FUN_0042ae40();
      }
    }
    FUN_00421a70();
    cVar1 = FUN_0057f150();
    iVar2 = (int)cVar1;
    puVar3 = (undefined4 *)FUN_00421a70(iVar2);
    local_60 = (undefined4 *)
               FUN_0043dbb0(0,(int)*(char *)(local_28 + 1),local_29,local_30,*puVar3,iVar2);
    puVar3 = local_60;
    puVar4 = (undefined4 *)(&DAT_0077b1a0 + local_24 * 0x28);
    for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(local_5c);
    local_20 = local_20 + 1;
    FUN_00421a70();
    cVar1 = FUN_0057f150();
    if (cVar1 < local_1c) {
      FUN_00421a70();
      cVar1 = FUN_0057f150();
      local_1c = (int)cVar1;
    }
    uVar6 = 1;
    FUN_00421a70(1);
    fVar5 = (float10)RideInfo__GetPerformanceMeasure(uVar6);
    if (fVar5 < (float10)local_18) {
      uVar6 = 1;
      FUN_00421a70(1,0,0x41200000);
      fVar5 = (float10)RideInfo__GetPerformanceMeasure(uVar6);
      fVar5 = (float10)bClampF((float)fVar5);
      local_18 = (float)fVar5;
    }
  }
  DAT_00700a18 = (_K_ONE - 0.65) * (local_18 / 1.0) + 0.65;
  fVar5 = (float10)bClampF(DAT_00700a18,0x3f266666,0x3f800000);
  DAT_00700a18 = (float)fVar5;
  cVar1 = FUN_0043a2e0();
  if (cVar1 == '\0') {
    local_64 = 4 - local_20;
    local_65 = 0;
    Race__PickOpponentNames(local_78);
    for (local_7c = 0; local_7c < local_64; local_7c = local_7c + 1) {
      local_80 = local_7c + 100;
      RideInfo__Init();
      local_7a4 = local_78[local_7c];
      local_7a8 = -1;
      if ((param_1 == 0) || (DAT_0078a33c == '\0')) {
        Race__BuildRandomOpponentRide
                  (local_7a0,0,CONCAT31((int3)(-(uint)local_65 >> 8),'\x01' - (local_65 != 0)),
                   local_14);
        if ((local_65 == 0) && (local_7a0[0] != *local_14)) {
          local_7b4 = 0;
        }
        else {
          local_7b4 = 1;
        }
        local_65 = (byte)local_7b4;
      }
      else {
        FUN_0043dc10(local_80,local_7c + 2);
        RivalList__GetRival();
        FUN_004b4010();
        FUN_0043dc10();
        local_7ac = RivalList__GetRival();
        local_7b0 = DAT_0078a3fc;
        local_7a8 = (int)*(short *)(local_7ac + 0x10 + DAT_0078a3fc * 2);
        local_7a4 = local_7ac;
        if ((local_7a8 < 0) || (9 < local_7a8)) {
          local_7a8 = -1;
        }
      }
      if (local_7a8 == -1) {
        local_7a8 = Race__RollOpponentSkill();
      }
      puVar3 = (undefined4 *)FUN_0043dbb0(0,local_80,0,local_7a4,local_7a0[0],local_1c);
      puVar4 = (undefined4 *)(&DAT_0077b1a0 + (local_7c + local_20) * 0x28);
      for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(local_7dc);
      *(int *)(&DAT_0077b1c0 + (local_7c + local_20) * 0x28) = local_7a8;
      fVar5 = (float10)FUN_00564a80(0x3f800000);
      *(float *)(&DAT_0077b1c4 + (local_7c + local_20) * 0x28) = (float)fVar5;
    }
  }
  return;
}


// ==== 0x43e310 FUN_0043e310

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0043e310(int param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  undefined4 local_10;
  
  iVar2 = FUN_0041e4b0();
  if (iVar2 == 0) {
    FUN_0043ef30();
    FUN_0043ede0();
    fVar3 = (float10)FUN_0043e540(param_2);
    local_10 = DriftManager__CalcDriftMultiplier(param_2);
    fVar4 = (float10)DriftManager__CalcBonusZoneMult(param_2);
    fVar5 = (float10)DriftManager__GetCollisionIntensity();
    fVar1 = (float)fVar5;
    if (fVar1 <= 0.2) {
      if (0.0 < (float)fVar3) {
        FUN_00575950();
        StyleItem__SetLevel(local_10);
        StyleItem__Trigger((float)fVar3 * 1.0 * (float)fVar4);
        iVar2 = FUN_0041e4c0();
        if (iVar2 == 0) {
          FUN_00417490();
          FUN_00424dd0();
          fVar3 = (float10)FUN_00464ea0();
          fVar1 = (float)fVar3;
          if ((fVar1 * *(float *)(param_1 + 0x5c) < 0.0) &&
             (fVar3 = (float10)FUN_00405600(fVar1), (float10)0.4 / (float10)_K_BLUR_W_MUL < fVar3))
          {
            fVar3 = (float10)FUN_00405600(*(undefined4 *)(param_1 + 0x5c));
            if ((float10)0.4 < fVar3) {
              FUN_00417490();
              fVar3 = (float10)FUN_00424e10();
              if ((float10)17.88109 < fVar3) {
                StyleItemTable__TriggerItem(0x3f800000);
              }
            }
            *(float *)(param_1 + 0x5c) = fVar1;
          }
        }
      }
    }
    else {
      local_10 = 1;
      StyleItemTable__FinishItem();
      if (5.0 < fVar1) {
        FUN_00432d50();
        MiscStyleManager__ClearFlags();
        if (*(char *)(param_1 + 0x11) != '\0') {
          StyleItemTable__TriggerItem(fVar1);
        }
      }
    }
    DriftManager__UpdateLeaderBoard();
    FUN_00435ff0();
    FEngHud__SetMultiplier();
    *(undefined4 *)(param_1 + 0x18) = local_10;
  }
  else {
    iVar2 = FUN_00424ea0();
    if (iVar2 != 0) {
      DriftManager__UpdateLeaderBoard();
    }
  }
  return;
}


// ==== 0x43e540 FUN_0043e540

float10 __fastcall FUN_0043e540(int param_1)

{
  float fVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float local_30;
  float local_8;
  
  local_8 = 0.0;
  FUN_004081e0();
  fVar5 = (float10)FUN_00424e80();
  if (fVar5 <= (float10)*(float *)(param_1 + 0x54)) goto LAB_0043e6aa;
  FUN_00424dd0();
  fVar5 = (float10)FUN_00464ea0();
  fVar5 = (float10)FUN_00405600((float)fVar5);
  fVar6 = (float10)FUN_00424e10();
  FUN_0041e4c0();
  cVar3 = FUN_0057f150();
  iVar4 = FUN_00424de0();
  fVar7 = (float10)FUN_00405600(*(undefined4 *)(iVar4 + 8));
  if (fVar7 <= (float10)0.1) {
LAB_0043e60f:
    bVar2 = false;
  }
  else {
    iVar4 = FUN_00424de0();
    FUN_00424dd0();
    fVar7 = (float10)FUN_00464ea0();
    if ((float10)0.0 <= fVar7 * (float10)*(float *)(iVar4 + 8)) goto LAB_0043e60f;
    bVar2 = true;
  }
  FUN_00575950();
  iVar4 = FUN_0041e4c0();
  if ((iVar4 != 0) || (bVar2)) {
    local_30 = *(float *)(&DAT_006b7880 + cVar3 * 4);
  }
  else {
    local_30 = *(float *)(&DAT_006b7890 + cVar3 * 4);
  }
  iVar4 = SpecialCamCooldown();
  if (iVar4 == 0) {
    fVar7 = (float10)DegToRad(0x40a00000);
    if ((fVar7 < (float10)(float)fVar5) && (local_30 < (float)fVar6)) {
      fVar1 = (float)fVar6 / 10.083333;
      local_8 = fVar1 * fVar1 * (float)fVar5;
    }
  }
LAB_0043e6aa:
  FUN_004081e0();
  fVar5 = (float10)FUN_00424e80();
  fVar5 = (float10)bMax_float(*(undefined4 *)(param_1 + 0x54),(float)fVar5);
  *(float *)(param_1 + 0x54) = (float)fVar5;
  return (float10)local_8;
}


// ==== 0x43e6e0 DriftManager::CalcBonusZoneMult

/* [canon] runtime high (ghidra-canon+nfsug) docs/re/canon.md */

float10 __fastcall DriftManager__CalcBonusZoneMult(int param_1)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 1.0;
  *(undefined4 *)(param_1 + 0x14) = 1;
  local_c = 0;
  for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
    FUN_00424dd0();
    iVar1 = FUN_00424d40();
    if (iVar1 == 3) {
      local_c = local_c + 1;
    }
  }
  if (1 < local_c) {
    FUN_0041e4c0();
    fVar2 = (float10)RideInfo__GetTheoreticalTopSpeed();
    fVar3 = (float10)FUN_00424e10();
    if ((float10)(float)(fVar2 * (float10)0.25) < fVar3) {
      *(int *)(param_1 + 0x14) = local_c;
      local_8 = (float)local_c;
    }
  }
  return (float10)local_8;
}


// ==== 0x43e790 DriftManager::CalcDriftMultiplier

/* WARNING: Removing unreachable block (ram,0x0043e92f) */
/* [canon] runtime high (ghidra-canon+nfsug) docs/re/canon.md */

int __fastcall DriftManager__CalcDriftMultiplier(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  float10 fVar3;
  int local_c;
  
  local_c = *(int *)(param_1 + 0x18);
  FUN_00575950();
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x13) = 0;
  if ((*(int *)(param_1 + 0x18) < 2) ||
     ((iVar1 = SpecialCamCooldown(), iVar1 == 0 &&
      (fVar3 = (float10)FUN_00424e10(),
      (float10)1.388889 + (float10)*(float *)(&DAT_006b7934 + *(int *)(param_1 + 0x18) * 4) <= fVar3
      )))) {
    iVar1 = SpecialCamCooldown();
    if (iVar1 == 0) {
      if ((3 < *(int *)(param_1 + 0x18)) ||
         (fVar3 = (float10)FUN_00424e10(),
         (float10)*(float *)(&DAT_006b7938 + *(int *)(param_1 + 0x18) * 4) - (float10)1.388889 <=
         fVar3)) {
        FUN_00424cc0();
        iVar1 = FUN_0041e4c0();
        if ((iVar1 == 0) &&
           ((*(int *)(param_1 + 0x18) < 5 &&
            (fVar3 = (float10)FUN_00432c80(), (float10)*(int *)(param_1 + 0x1c) < fVar3)))) {
          local_c = *(int *)(param_1 + 0x18) + 1;
          uVar2 = _ftol_nocw();
          *(undefined4 *)(param_1 + 0x1c) = uVar2;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x13) = 1;
        FUN_00424cc0();
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x13) = 1;
      int_Sub(param_1 + 0x20);
      fVar3 = (float10)bTickerToSeconds();
      if ((float10)1.5 < fVar3) {
        FUN_00424cc0();
      }
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x12) = 1;
    iVar1 = SpecialCamCooldown();
    if (iVar1 != 0) {
      int_Sub(param_1 + 0x20);
      fVar3 = (float10)bTickerToSeconds();
      if (fVar3 <= (float10)1.5) goto LAB_0043e97c;
    }
    local_c = *(int *)(param_1 + 0x18) + -1;
    FUN_00405560();
  }
LAB_0043e97c:
  if (local_c < 5) {
    uVar2 = _ftol_nocw();
    *(undefined4 *)(param_1 + 0x1c) = uVar2;
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return local_c;
}


// ==== 0x43e9d0 DriftManager::GetCollisionIntensity

/* [canon] runtime high (ghidra-canon+nfsug) docs/re/canon.md */

float10 __fastcall DriftManager__GetCollisionIntensity(int param_1)

{
  int iVar1;
  float10 fVar2;
  undefined4 local_8;
  
  local_8 = 0.0;
  FUN_00432d50();
  fVar2 = (float10)MiscStyleManager__GetTimeSinceLastCollision();
  if ((float10)0.5 <= fVar2) {
    *(undefined1 *)(param_1 + 0x11) = 0;
  }
  else if (*(char *)(param_1 + 0x11) == '\0') {
    FUN_00432d50();
    iVar1 = FUN_0041f5d0();
    *(char *)(param_1 + 0x11) = '\x01' - (iVar1 != 3);
    FUN_00432d50();
    fVar2 = (float10)FUN_00432d10();
    local_8 = (float)fVar2;
  }
  return (float10)local_8;
}


// ==== 0x43ea50 FUN_0043ea50

int __thiscall FUN_0043ea50(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00421960(param_1);
  while( true ) {
    iVar2 = NullUpdate_ret();
    if (iVar1 == iVar2) {
      return 0;
    }
    if (*(int *)(iVar1 + 8) == param_2) break;
    iVar1 = FUN_00421960();
  }
  return iVar1;
}


// ==== 0x43eaa0 RaceManager::GetRacerRank

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

int RaceManager__GetRacerRank(int param_1)

{
  int iVar1;
  int local_c;
  int local_8;
  
  local_8 = 1;
  local_c = FUN_00421960();
  while( true ) {
    iVar1 = NullUpdate_ret();
    if (local_c == iVar1) {
      return 0;
    }
    if (*(int *)(local_c + 8) == param_1) break;
    local_8 = local_8 + 1;
    local_c = FUN_00421960();
  }
  return local_8;
}


// ==== 0x43eb00 DriftManager::UpdateLeaderBoard

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] rivals med (Ghidra+Hopper+capstone) docs/re/rivals.md */

void __fastcall DriftManager__UpdateLeaderBoard(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float local_54;
  int local_28;
  int local_c;
  
  local_c = 0;
  while( true ) {
    iVar2 = FUN_004081e0();
    if (iVar2 <= local_c) break;
    FUN_00401d80();
    iVar2 = RacerNode__IsLocalHuman();
    if (iVar2 == 0) {
      iVar2 = RacerNode__IsPlayerKind();
      if (iVar2 != 0) {
        iVar2 = RacerNode__IsRemote();
        if (iVar2 != 0) {
          uVar3 = FUN_0041f5c0();
          Race__GetPlayer(uVar3);
          iVar2 = FUN_004134c0();
          uVar3 = FUN_0041f5c0();
          iVar4 = FUN_0043ea50(uVar3);
          *(float *)(iVar4 + 0x10) = (float)iVar2;
        }
      }
    }
    else {
      FUN_00424db0();
      FUN_00432d40();
      FUN_00575950();
      fVar7 = (float10)FUN_00432d10();
      uVar3 = FUN_0041f5c0();
      iVar2 = FUN_0043ea50(uVar3);
      *(float *)(iVar2 + 0x10) = (float)fVar7;
    }
    local_c = local_c + 1;
  }
  cVar1 = FUN_0043a2e0();
  if (cVar1 == '\0') {
    iVar2 = DriftManager__GetCurrentDriftSpeedGate(*(undefined4 *)(param_1 + 8));
    if (iVar2 != 0) {
      iVar4 = FUN_0043db60();
      FUN_004081e0();
      iVar5 = FUN_0042ac60();
      if (iVar4 <= iVar5) {
        iVar4 = FUN_0043db60();
        RacerRecord__SetRank(iVar4 + 1);
        iVar4 = FUN_004081e0();
        for (local_28 = 0; local_28 < 4 - iVar4; local_28 = local_28 + 1) {
          iVar5 = FUN_0043ea50(local_28 + 100);
          FUN_004081e0();
          iVar6 = FUN_0042ac60();
          if (iVar6 == 0) {
            iVar6 = *(int *)(iVar2 + 0x94 + *(int *)(iVar5 + 0xc) * 4);
          }
          else {
            iVar6 = *(int *)(iVar2 + 0xa4 + *(int *)(iVar5 + 0xc) * 4);
          }
          local_54 = (float)iVar6;
          *(float *)(iVar5 + 0x10) =
               local_54 *
               ((*(float *)(&DAT_0077a040 + *(int *)(iVar5 + 0x20) * 0x54) -
                *(float *)(&DAT_0077a03c + *(int *)(iVar5 + 0x20) * 0x54)) *
                *(float *)(iVar5 + 0x24) + *(float *)(&DAT_0077a03c + *(int *)(iVar5 + 0x20) * 0x54)
               ) * _DAT_0078a380 * 1.0 * DAT_00700a18 + *(float *)(iVar5 + 0x10);
        }
      }
    }
  }
  iVar2 = bList__IsEmpty();
  if (iVar2 == 0) {
    bList__Sort(&DAT_0077b198,SortScoreList);
    FUN_00435ff0(&DAT_0077b198);
    FEUpdateDriftLeaderBoard();
  }
  FUN_004081e0();
  iVar2 = FUN_00432c50();
  if (iVar2 != 0) {
    FUN_004081e0();
    iVar2 = FUN_0042ac60();
    if (iVar2 < 0xb) {
      uVar3 = FUN_0041f5c0();
      uVar3 = RaceManager__GetRacerRank(uVar3);
      FUN_004081e0();
      iVar2 = FUN_0042ac60();
      *(undefined4 *)(param_1 + 0x28 + iVar2 * 4) = uVar3;
    }
  }
  return;
}


// ==== 0x43ede0 FUN_0043ede0

/* WARNING: Removing unreachable block (ram,0x0043eea7) */

void __fastcall FUN_0043ede0(int param_1)

{
  float fVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  float10 fVar5;
  
  cVar3 = FUN_00424f20();
  if ((cVar3 != '\0') || (fVar5 = (float10)FUN_00424e00(), fVar5 < (float10)0.0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  *(undefined4 *)(param_1 + 0x28) = 0xbf800000;
  if (bVar2) {
    iVar4 = SpecialCamCooldown();
    if (iVar4 == 0) {
      FUN_00405560();
    }
    int_Sub(param_1 + 0x24);
    fVar5 = (float10)bTickerToSeconds();
    fVar1 = (float)fVar5;
    if (4.0 < fVar1) {
      FUN_00424cc0();
      Player__ResetToRoute();
    }
    if (1.0 < fVar1) {
      *(float *)(param_1 + 0x28) = 4.0 - fVar1;
    }
  }
  else {
    FUN_00424cc0();
  }
  return;
}


// ==== 0x43ef00 FUN_0043ef00

void __fastcall FUN_0043ef00(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 1;
  StyleItemTable__FinishItem();
  StyleItemTable__ResetItemLevel();
  return;
}


// ==== 0x43ef30 FUN_0043ef30

void __fastcall FUN_0043ef30(int param_1)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  
  FUN_00575950();
  iVar2 = FUN_0041e4c0();
  if (iVar2 == 0) {
    if (1 < *(int *)(param_1 + 0x14)) {
      StyleItemTable__TriggerItem((float)*(int *)(param_1 + 0x14) / 2.0);
    }
    if (*(int *)(param_1 + 0x58) < 7) {
      FUN_00575950();
      fVar3 = (float10)FUN_00432c80();
      iVar2 = ModeFlags_GetRow();
      if (*(float *)(iVar2 + 8) < (float)fVar3) {
        StyleItem__Trigger(0x3f800000);
        *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
        ModeFlags_GetRow();
        FUN_00435ff0();
        FEngHud__SetTrapSpeed();
      }
    }
    FUN_00417490();
    FUN_00424dd0();
    fVar3 = (float10)FUN_00464ea0();
    fVar1 = (float)fVar3;
    FUN_00417490();
    FUN_00424de0();
    if (*(float *)(param_1 + 0x5c) == 0.0) {
      *(float *)(param_1 + 0x5c) = fVar1;
    }
    else if ((0.0 < fVar1 * *(float *)(param_1 + 0x5c)) &&
            (((fVar1 < 0.0 && (fVar1 < *(float *)(param_1 + 0x5c))) ||
             ((0.0 < fVar1 && (*(float *)(param_1 + 0x5c) < fVar1)))))) {
      *(float *)(param_1 + 0x5c) = fVar1;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x5c) = 0;
    *(undefined4 *)(param_1 + 0x58) = 0;
    StyleItemTable__ResetItemLevel();
  }
  return;
}


// ==== 0x43f0e0 DriftManager::GetCurrentDriftSpeedGate

/* [canon] runtime high (ghidra-canon+nfsug) docs/re/canon.md */

void DriftManager__GetCurrentDriftSpeedGate(void)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_0041f5d0();
  (**(code **)(*piVar1 + 0x40))();
  FUN_00424e60();
  Zone_FindTrafficDensity();
  return;
}


// ==== 0x43f130 SortScoreList

/* [canon] runtime high (ghidra-canon+nfsug) docs/re/canon.md */

bool SortScoreList(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)(param_2 + 0x10);
  fVar2 = *(float *)(param_1 + 0x10);
  return (!NAN(fVar1) && !NAN(fVar2)) && fVar1 < fVar2 != (fVar1 == fVar2);
}


// ==== 0x43f160 _GLOBAL__D___12DriftManager

/* [canon] runtime high (ghidra-canon+nfsug) docs/re/canon.md */

void __fastcall _GLOBAL__D___12DriftManager(undefined4 param_1)

{
  int iVar1;
  void *_Memory;
  
  while (iVar1 = bList__IsEmpty(), iVar1 == 0) {
    _Memory = (void *)bList__RemoveHead();
    if (_Memory != (void *)0x0) {
      EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(_Memory);
      _free(_Memory);
    }
  }
  EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(param_1);
  return;
}


// ==== 0x43f1d0 bTList::EndOfList

/* [canon] runtime med (ghidra-canon) docs/re/canon.md */

void __fastcall bTList__EndOfList(undefined4 param_1)

{
  NullUpdate_ret(param_1);
  return;
}


// ==== 0x43f1f0 FUN_0043f1f0

void __fastcall FUN_0043f1f0(undefined4 param_1)

{
  FUN_00421960(param_1);
  return;
}


// ==== 0x43f210 MiscStyleManager::IsAirTimeActive

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

undefined4 __fastcall MiscStyleManager__IsAirTimeActive(int param_1)

{
  if ((((*(int *)(param_1 + 0x1c) == 2) && (*(int *)(param_1 + 0x20) != 0)) &&
      (*(int *)(param_1 + 0x20) != 0x7fffffff)) && (*(int *)(param_1 + 0x78) == 0)) {
    return 1;
  }
  return 0;
}


// ==== 0x43f240 FUN_0043f240

void FUN_0043f240(void)

{
  int *piVar1;
  char cVar2;
  int *in_EAX;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float fVar6;
  
  FUN_0043f430();
  if (*(int *)(*in_EAX + 0x58) == 0) {
    FUN_0043f550();
    FUN_0043f8b0(in_EAX);
    FUN_0043f9b0();
    FUN_0043f630();
    FUN_0043fa90();
    Commentator__ShortcutZoneEntered(in_EAX);
    return;
  }
  piVar1 = *(int **)(*(int *)(*in_EAX + 4) + 0x1c);
  if (((*(char *)((int)in_EAX + 10) != '\0') && (*(char *)((int)piVar1 + 9) == DAT_0078a31c)) &&
     (*(undefined1 *)((int)in_EAX + 10) = 0, *(char *)(*(int *)(in_EAX[1] + 0x4c) + 0x14) != '\0'))
  {
    StyleItem__Trigger(0x3f800000);
  }
  if (*(char *)((int)in_EAX + 0xd) != '\0') {
    return;
  }
  *(undefined1 *)((int)in_EAX + 0xd) = 1;
  cVar2 = FUN_0043a2e0();
  if (cVar2 != '\0') goto LAB_0043f39d;
  if (DAT_0078a328 + DAT_0078a32c + DAT_0078a324 + DAT_0078a320 < 2) {
    if ((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) {
LAB_0043f355:
      cVar2 = FUN_0043a2e0();
      if (cVar2 != '\0') goto LAB_0043f380;
      iVar3 = RaceManager__GetRacerRank((int)*(short *)(*piVar1 + 10));
      if (iVar3 != 1) goto LAB_0043f39d;
      iVar3 = *(int *)(in_EAX[1] + 0x34);
      goto LAB_0043f38c;
    }
    cVar2 = MiscStyleManager__IsAirTimeActive();
    if (((cVar2 == '\0') || (DAT_0078a310 <= piVar1[0x44])) ||
       (*(char *)(*(int *)(in_EAX[1] + 0x6c) + 0x14) == '\0')) goto LAB_0043f39d;
    fVar6 = (float)(DAT_0078a310 - piVar1[0x44]) * 0.00025;
  }
  else {
    if ((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) goto LAB_0043f355;
LAB_0043f380:
    if ((char)piVar1[3] != '\x01') goto LAB_0043f39d;
    iVar3 = *(int *)(in_EAX[1] + 0x34);
LAB_0043f38c:
    if (*(char *)(iVar3 + 0x14) == '\0') goto LAB_0043f39d;
    fVar6 = 1.0;
  }
  StyleItem__Trigger(fVar6);
LAB_0043f39d:
  fVar5 = (float10)StyleSet__RecomputeTotal();
  if ((float10)0.0 < fVar5) {
    if ((short)piVar1[4] == 7) {
      iVar3 = in_EAX[1];
      iVar4 = *(int *)(iVar3 + 0x74);
    }
    else {
      if ((short)piVar1[4] != 6) {
        return;
      }
      iVar3 = in_EAX[1];
      iVar4 = *(int *)(iVar3 + 0x78);
    }
    if (*(char *)(iVar4 + 0x14) != '\0') {
      StyleItem__Trigger(*(undefined4 *)(iVar3 + 0x7c));
    }
  }
  return;
}


// ==== 0x43f3f0 MiscStyleManager::GetTimeSinceLastCollision

/* [canon] runtime med (ghidra-canon+nfsug) docs/re/runtime.md */

float10 __fastcall MiscStyleManager__GetTimeSinceLastCollision(int param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)99999.9;
  if ((*(int *)(param_1 + 0x24) != 0) && (*(int *)(param_1 + 0x24) != 0x7fffffff)) {
    fVar1 = (float10)(DAT_0073ad34 - *(int *)(param_1 + 0x24)) * (float10)0.00025;
  }
  return fVar1;
}


// ==== 0x43f420 MiscStyleManager::ClearFlags

/* [canon] runtime low (ghidra-canon) docs/re/runtime.md */

void MiscStyleManager__ClearFlags(void)

{
  int in_EAX;
  
  *(undefined1 *)(in_EAX + 9) = 0;
  *(undefined1 *)(in_EAX + 10) = 0;
  *(undefined1 *)(in_EAX + 8) = 0;
  return;
}


// ==== 0x43f430 FUN_0043f430

void FUN_0043f430(void)

{
  int *piVar1;
  uint uVar2;
  int *unaff_ESI;
  
  piVar1 = *(int **)(*(int *)(*unaff_ESI + 4) + 0x1c);
  if ((*(char *)((int)piVar1 + 0xe) == '\0') || (*(char *)((int)unaff_ESI + 0xb) != '\0')) {
    *(bool *)((int)unaff_ESI + 0xb) = *(char *)((int)piVar1 + 0xe) != '\0';
  }
  else {
    *(undefined1 *)((int)unaff_ESI + 0xb) = 1;
    if ((char)unaff_ESI[2] == '\0') {
      *(undefined1 *)(unaff_ESI + 2) = 1;
      if (*(char *)(*(int *)(unaff_ESI[1] + 0x44) + 0x14) != '\0') {
        StyleItem__ResetLevel();
      }
    }
    else if (*(char *)(*(int *)(unaff_ESI[1] + 0x44) + 0x14) != '\0') {
      StyleItem__Trigger(0x3f800000);
    }
  }
  if ((*(char *)((int)piVar1 + 0xd) == '\0') || ((char)unaff_ESI[3] != '\0')) {
    *(bool *)(unaff_ESI + 3) = *(char *)((int)piVar1 + 0xd) != '\0';
  }
  else {
    *(undefined1 *)(unaff_ESI + 3) = 1;
    if (*(char *)((int)unaff_ESI + 9) == '\0') {
      *(undefined1 *)((int)unaff_ESI + 9) = 1;
      if (*(char *)(*(int *)(unaff_ESI[1] + 0x48) + 0x14) != '\0') {
        StyleItem__ResetLevel();
      }
    }
    else if (*(char *)(*(int *)(unaff_ESI[1] + 0x48) + 0x14) != '\0') {
      StyleItem__Trigger(0x3f800000);
    }
    if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
      uVar2 = (uint)(*(char *)((int)piVar1 + 10) == '\x01');
    }
    else {
      uVar2 = RaceManager__GetRacerRank((int)*(short *)(*piVar1 + 10));
    }
    if (uVar2 == 0) {
      if (*(char *)(*(int *)(unaff_ESI[1] + 0x40) + 0x14) != '\0') {
        StyleItem__ResetLevel();
        return;
      }
    }
    else if (*(char *)(*(int *)(unaff_ESI[1] + 0x40) + 0x14) != '\0') {
      StyleItem__Trigger(0x3f800000);
      return;
    }
  }
  return;
}


// ==== 0x43f550 FUN_0043f550

void FUN_0043f550(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  bool bVar4;
  int *unaff_ESI;
  float10 fVar5;
  
  fVar1 = 99999.9;
  iVar3 = *(int *)(*unaff_ESI + 4);
  if ((unaff_ESI[9] != 0) && (unaff_ESI[9] != 0x7fffffff)) {
    fVar1 = (float)(DAT_0073ad34 - unaff_ESI[9]) * 0.00025;
  }
  if ((((*(int *)(iVar3 + 0x3cc) != 0) || (*(char *)(*(int *)(iVar3 + 0x3c) + 0x1c) != '\0')) ||
      ((*(float *)(iVar3 + 0xb8) <= 0.8 && (*(int *)(*(int *)(unaff_ESI[1] + 0x30) + 0x10) != 0))))
     || ((fVar1 <= 0.5 && (*(int *)(*(int *)(unaff_ESI[1] + 0x30) + 0x10) != 0)))) {
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  fVar1 = *(float *)(iVar3 + 0x68);
  fVar2 = *(float *)(*(int *)(iVar3 + 0x20) + 8);
  fVar5 = (float10)GroundQuery__FindSurfaceBelow(iVar3 + 0x540,iVar3 + 0x60,0,0,0);
  if (((bVar4) && ((float10)0.75 < (float10)(fVar1 - fVar2) - fVar5)) &&
     (*(char *)(*(int *)(unaff_ESI[1] + 0x30) + 0x14) != '\0')) {
    StyleItem__Trigger(0x3f800000);
    return;
  }
  return;
}


// ==== 0x43f630 FUN_0043f630

void FUN_0043f630(void)

{
  float fVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *extraout_EDX;
  int *unaff_ESI;
  int iVar7;
  float10 fVar8;
  
  fVar1 = 99999.9;
  iVar4 = *(int *)(*unaff_ESI + 4);
  if ((unaff_ESI[9] != 0) && (unaff_ESI[9] != 0x7fffffff)) {
    fVar1 = (float)(DAT_0073ad34 - unaff_ESI[9]) * 0.00025;
  }
  iVar7 = *(int *)(iVar4 + 0x884);
  if ((((iVar7 != 0) && (iVar7 != 0x7fffffff)) &&
      ((float)(DAT_0073ad34 - iVar7) * 0.00025 < *(float *)(iVar4 + 0x888))) ||
     ((*(float *)(iVar4 + 0x3d4) <= 20.116228 || (fVar1 <= 0.5)))) {
    unaff_ESI[6] = 0;
    unaff_ESI[8] = 0;
    unaff_ESI[7] = 0;
LAB_0043f8a5:
    *(undefined1 *)(unaff_ESI + 5) = 0;
  }
  else {
    if ((char)unaff_ESI[5] == '\0') {
      unaff_ESI[6] = 0;
      unaff_ESI[8] = 0;
      unaff_ESI[7] = 0;
      if (DAT_00779be0 == 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = DAT_00779be0 + -0x250;
      }
      iVar5 = FUN_00421970();
      while (iVar7 != iVar5) {
        iVar6 = CollisionBodyWitness__HasExpired();
        if ((((iVar6 == 0) && (*(char *)(iVar7 + 0x14) == '\0')) &&
            ((*(char *)(*(int *)(iVar7 + 600) + 0x15) == '\0' &&
             (*(char *)(*(int *)(iVar7 + 0x25c) + 0x15) == '\0')))) &&
           ((((*(int *)(*(int *)(iVar7 + 600) + 0x140) == iVar4 ||
              (*(int *)(*(int *)(iVar7 + 0x25c) + 0x140) == iVar4)) &&
             (cVar3 = Car__IsResetGraceActive(), cVar3 == '\0')) &&
            ((cVar3 = Car__IsResetGraceActive(), cVar3 == '\0' && (*(float *)(iVar7 + 0x10) < 1.5)))
            ))) {
          piVar2 = *(int **)(iVar7 + 600);
          (**(code **)(*extraout_EDX + 0xc))();
          (**(code **)(*piVar2 + 0xc))();
          Vec3_Sub();
          fVar8 = (float10)bLength3();
          if ((float10)40.232456 < fVar8) {
            unaff_ESI[6] = iVar7;
            unaff_ESI[7] = *(int *)(iVar7 + 600);
            unaff_ESI[8] = *(int *)(iVar7 + 0x25c);
            break;
          }
        }
        if (*(int *)(iVar7 + 0x250) == 0) {
          iVar7 = 0;
        }
        else {
          iVar7 = *(int *)(iVar7 + 0x250) + -0x250;
        }
      }
      if (unaff_ESI[6] == 0) goto LAB_0043f733;
    }
    else {
      if ((char)unaff_ESI[5] != '\x01') goto LAB_0043f733;
      iVar4 = unaff_ESI[6];
      if ((unaff_ESI[7] != *(int *)(iVar4 + 600)) || (unaff_ESI[8] != *(int *)(iVar4 + 0x25c))) {
        *(undefined1 *)(unaff_ESI + 5) = 2;
        goto LAB_0043f733;
      }
      if (*(int *)(iVar4 + 0x264) != 0) goto LAB_0043f8a5;
      fVar1 = *(float *)(iVar4 + 0x10);
      iVar4 = CollisionBodyWitness__HasExpired();
      if ((iVar4 == 0) && (fVar1 <= 1.875)) goto LAB_0043f733;
    }
    *(char *)(unaff_ESI + 5) = (char)unaff_ESI[5] + '\x01';
  }
LAB_0043f733:
  if ((char)unaff_ESI[5] == '\x02') {
    if (*(char *)(*(int *)(unaff_ESI[1] + 0x58) + 0x14) != '\0') {
      StyleItem__Trigger(0x3f800000);
    }
    *(undefined1 *)(unaff_ESI + 5) = 0;
    unaff_ESI[6] = 0;
    unaff_ESI[8] = 0;
    unaff_ESI[7] = 0;
  }
  return;
}


// ==== 0x43f8b0 FUN_0043f8b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043f8b0(int *param_1)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = *(int *)(*param_1 + 4);
  if (1.0 <= *(float *)(iVar1 + 0x3d0)) {
    fVar2 = (float10)CarState__GetYaw();
  }
  else {
    fVar2 = (float10)0.0;
  }
  if ((((0.08726646 < (float)ABS(fVar2)) && (25.0 < *(float *)(iVar1 + 0x3d4))) &&
      (*(int *)(iVar1 + 0x3cc) == 4)) && (*(char *)(*(int *)(param_1[1] + 0x2c) + 0x14) != '\0')) {
    StyleItem__Trigger();
    return;
  }
  return;
}


// ==== 0x43f980 AngleDiffDegrees

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

float10 AngleDiffDegrees(float param_1,float param_2)

{
  float10 fVar1;
  
  fVar1 = ABS((float10)param_1 - (float10)param_2);
  if ((float10)(float)((float10)360.0 - fVar1) <= fVar1) {
    fVar1 = (float10)(float)((float10)360.0 - fVar1);
  }
  return fVar1;
}


// ==== 0x43f9b0 FUN_0043f9b0

void FUN_0043f9b0(void)

{
  char cVar1;
  int iVar2;
  float fVar3;
  int *unaff_ESI;
  float10 fVar4;
  
  iVar2 = *(int *)(*unaff_ESI + 4);
  fVar3 = (float)*(ushort *)(iVar2 + 0x3b4) * 0.005493164;
  if ((*(int *)(iVar2 + 0x3cc) != 4) ||
     (((cVar1 = *(char *)((int)unaff_ESI + 0xe), cVar1 != '\0' ||
       (ABS(*(float *)(iVar2 + 0xd8)) <= 2.0)) &&
      ((cVar1 < '\x01' || (ABS(*(float *)(iVar2 + 0xd8)) <= 1.0)))))) {
    *(undefined1 *)((int)unaff_ESI + 0xe) = 0;
  }
  else if (cVar1 == '\0') {
    unaff_ESI[4] = (int)fVar3;
    *(undefined1 *)((int)unaff_ESI + 0xe) = 1;
  }
  else if ((('\0' < cVar1) && (cVar1 < '\x03')) &&
          (fVar4 = (float10)AngleDiffDegrees(fVar3,unaff_ESI[4]), (float10)170.0 <= ABS(fVar4))) {
    *(char *)((int)unaff_ESI + 0xe) = cVar1 + '\x01';
    unaff_ESI[4] = (int)fVar3;
  }
  if (*(char *)((int)unaff_ESI + 0xe) == '\x03') {
    if (*(char *)(*(int *)(unaff_ESI[1] + 100) + 0x14) != '\0') {
      StyleItem__Trigger(0x3f800000);
    }
    *(undefined1 *)((int)unaff_ESI + 0xe) = 0;
  }
  return;
}


// ==== 0x43fa90 FUN_0043fa90

void FUN_0043fa90(void)

{
  int iVar1;
  int *unaff_ESI;
  
  iVar1 = *(int *)(*unaff_ESI + 4);
  if (((((DAT_0073619c != (int *)0x0) && (*DAT_0073619c == 4)) &&
       (1 < DAT_0078a328 + DAT_0078a32c + DAT_0078a324 + DAT_0078a320)) &&
      ((1.0 < (float)DAT_0073619c[5] * 0.00025 && ((float)DAT_0073619c[5] * 0.00025 < 1.5)))) &&
     ((*(char *)(*(int *)(iVar1 + 0x1c) + 10) == '\x01' &&
      (*(char *)(*(int *)(unaff_ESI[1] + 0x70) + 0x14) != '\0')))) {
    StyleItem__Trigger(0x3f800000);
  }
  if (((20.0 < *(float *)(iVar1 + 0x3d4)) && (0.25 < *(float *)(iVar1 + 0x47c))) &&
     (*(char *)(*(int *)(unaff_ESI[1] + 0x68) + 0x14) != '\0')) {
    StyleItem__Trigger(*(undefined4 *)(iVar1 + 0x47c));
  }
  return;
}


// ==== 0x43fb50 Commentator::ShortcutZoneEntered

/* [canon] track high (hopper+ghidra) docs/re/track.md */

void Commentator__ShortcutZoneEntered(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = (**(code **)(**(int **)(*(int *)(*param_1 + 4) + 0x2c) + 0x40))();
  iVar2 = Zone_Find(uVar1);
  if (((iVar2 != 0) && (*(short *)(iVar2 + 0x1a) == 0)) &&
     (*(undefined2 *)(iVar2 + 0x1a) = 1, *(char *)(*(int *)(param_1[1] + 0x50) + 0x14) != '\0')) {
    StyleItem__Trigger();
    return;
  }
  return;
}


// ==== 0x43fbb0 FUN_0043fbb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0043fbb0(int param_1,float param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int *unaff_EDI;
  
  iVar1 = (int)param_2;
  if (((5.0 <= *(float *)((int)param_2 + 0x60)) &&
      (iVar3 = DAT_0073ad34 - *(int *)((int)param_2 + 8), (float)iVar3 * 0.00025 <= 0.1)) &&
     ((cVar2 = Collision__IsWallInvolved(), cVar2 != '\0' ||
      (((cVar2 = Collision__IsTwoCarCollision(), cVar2 != '\0' ||
        (*(int *)(*(int *)(*unaff_EDI + 4) + 0x3cc) < 1)) ||
       (*(float *)(*(int *)(*unaff_EDI + 4) + 0xb8) <= 0.9)))))) {
    if (10.0 < *(float *)((int)param_2 + 0x60)) {
      *(undefined1 *)((int)unaff_EDI + 9) = 0;
      *(undefined1 *)((int)unaff_EDI + 10) = 0;
      *(undefined1 *)(unaff_EDI + 2) = 0;
    }
    if ((*(char *)(*(int *)(*(int *)((int)param_2 + 100) + 600) + 0x15) == '\0') &&
       (*(char *)(*(int *)(*(int *)((int)param_2 + 100) + 0x25c) + 0x15) == '\0')) {
      Collision__GetCollidingCars();
      if ((*(int *)(*(int *)(iVar3 + 0x14) + 4) == 3) ||
         (*(int *)(*(int *)(param_1 + 0x14) + 4) == 3)) {
        param_2 = *(float *)((int)param_2 + 0x60) / 40.0;
        if (_K_ONE < param_2) {
          param_2 = 1.0;
        }
        if ((*(short *)(*(int *)(*(int *)(*unaff_EDI + 4) + 0x1c) + 0x10) == 0) &&
           (*(char *)(*(int *)(unaff_EDI[1] + 0x3c) + 0x14) != '\0')) {
          StyleItem__Trigger(param_2);
        }
      }
      if (*(char *)(*(int *)(unaff_EDI[1] + 0x58) + 0x14) != '\0') {
        StyleItem__ResetLevel();
      }
      unaff_EDI[0xb] = 0;
    }
    else {
      unaff_EDI[0xb] = 3;
    }
    unaff_EDI[9] = DAT_0073ad34;
    unaff_EDI[10] = *(int *)(iVar1 + 0x60);
  }
  return;
}


// ==== 0x43fd20 TrackPolyRow::UnpackVertices

/* [canon] track high (hopper+ghidra) docs/re/track.md */

void __fastcall TrackPolyRow__UnpackVertices(float *param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int in_EAX;
  
  sVar1 = *(short *)(in_EAX + 0x10);
  sVar2 = *(short *)(in_EAX + 4);
  sVar3 = *(short *)(in_EAX + 0x18);
  *param_1 = (float)((int)*(short *)(in_EAX + 8) << 0xd) * 1.5258789e-05;
  param_1[1] = (float)((int)sVar1 << 0xd) * 1.5258789e-05;
  param_1[2] = (float)((sVar2 * 0x100 + (int)sVar3) * 0x100) * 1.5258789e-05;
  sVar1 = *(short *)(in_EAX + 0x12);
  sVar2 = *(short *)(in_EAX + 0x1a);
  sVar3 = *(short *)(in_EAX + 4);
  param_1[4] = (float)((int)*(short *)(in_EAX + 10) << 0xd) * 1.5258789e-05;
  param_1[5] = (float)((int)sVar1 << 0xd) * 1.5258789e-05;
  param_1[6] = (float)((sVar3 * 0x100 + (int)sVar2) * 0x100) * 1.5258789e-05;
  sVar1 = *(short *)(in_EAX + 0x14);
  sVar2 = *(short *)(in_EAX + 0x1c);
  sVar3 = *(short *)(in_EAX + 4);
  param_1[8] = (float)((int)*(short *)(in_EAX + 0xc) << 0xd) * 1.5258789e-05;
  param_1[9] = (float)((int)sVar1 << 0xd) * 1.5258789e-05;
  param_1[10] = (float)((sVar3 * 0x100 + (int)sVar2) * 0x100) * 1.5258789e-05;
  sVar1 = *(short *)(in_EAX + 0x16);
  sVar2 = *(short *)(in_EAX + 0x1e);
  sVar3 = *(short *)(in_EAX + 4);
  param_1[0xc] = (float)((int)*(short *)(in_EAX + 0xe) << 0xd) * 1.5258789e-05;
  param_1[0xd] = (float)((int)sVar1 << 0xd) * 1.5258789e-05;
  param_1[0xe] = (float)((sVar3 * 0x100 + (int)sVar2) * 0x100) * 1.5258789e-05;
  return;
}


// ==== 0x43fe70 TrackPolyBody::FromSlotIndex

/* [canon] track high (hopper+ghidra) docs/re/track.md */

int __fastcall TrackPolyBody__FromSlotIndex(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = DAT_00736184;
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    if ((-1 < param_1) && (param_1 < *(int *)(iVar2 + 0x24))) break;
    piVar1 = (int *)(iVar2 + 0x24);
    iVar2 = *(int *)(iVar2 + 8);
    param_1 = param_1 - *piVar1;
  }
  return *(int *)(DAT_00736184 + 0x28) * param_1 + 0x30 + iVar2;
}


// ==== 0x43feb0 TrackMarker_Count

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

int TrackMarker_Count(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = DAT_0077b190;
  iVar3 = 0;
  puVar2 = (undefined4 *)NullUpdate_ret();
  for (; puVar1 != puVar2; puVar1 = (undefined4 *)*puVar1) {
    if (puVar1[2] == param_1) {
      iVar3 = iVar3 + 1;
    }
  }
  return iVar3;
}


// ==== 0x43fef0 TrackMarker_Get

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

undefined4 * TrackMarker_Get(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = DAT_0077b190;
  iVar3 = 0;
  puVar2 = (undefined4 *)NullUpdate_ret();
  do {
    if (puVar1 == puVar2) {
      return (undefined4 *)0x0;
    }
    if (puVar1[2] == param_1) {
      if (iVar3 == param_2) {
        return puVar1;
      }
      iVar3 = iVar3 + 1;
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}


// ==== 0x43ff30 TrackPolyBody::Build

/* [canon] track high (hopper+ghidra) docs/re/track.md */

void TrackPolyBody__Build(void)

{
  float *pfVar1;
  byte bVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined2 uVar12;
  int unaff_ESI;
  int unaff_EDI;
  
  *(undefined1 *)(unaff_ESI + 0xb) = *(undefined1 *)(unaff_EDI + 2);
  *(undefined1 *)(unaff_ESI + 10) = *(undefined1 *)(unaff_EDI + 3);
  *(undefined1 *)(unaff_ESI + 8) = 0;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  bVar2 = *(byte *)(unaff_EDI + 1);
  sVar3 = *(short *)(unaff_EDI + 0x10 + (bVar2 >> 2 & 3) * 2);
  sVar4 = *(short *)(unaff_EDI + 8 + (bVar2 >> 4 & 3) * 2);
  sVar5 = *(short *)(unaff_EDI + 0x10 + (uint)(bVar2 >> 6) * 2);
  pfVar1 = (float *)(unaff_ESI + 0x30);
  *(float *)(unaff_ESI + 0x14) =
       (float)((int)*(short *)(unaff_EDI + 8 + (bVar2 & 3) * 2) << 0xd) * 1.5258789e-05;
  *(float *)(unaff_ESI + 0x18) = (float)((int)sVar3 << 0xd) * 1.5258789e-05;
  *(float *)(unaff_ESI + 0x1c) = (float)((int)sVar4 << 0xd) * 1.5258789e-05;
  *(float *)(unaff_ESI + 0x20) = (float)((int)sVar5 << 0xd) * 1.5258789e-05;
  TrackPolyRow__UnpackVertices();
  *(undefined1 *)(unaff_ESI + 9) = 4;
  if ((*(byte *)(unaff_ESI + 10) & 0x10) == 0) {
    *(undefined1 *)(unaff_ESI + 9) = 3;
  }
  if ((*(byte *)(unaff_ESI + 10) & 4) != 0) {
    *(float *)(unaff_ESI + 0x38) = *(float *)(unaff_ESI + 0x38) * 4.0;
    *(float *)(unaff_ESI + 0x48) = *(float *)(unaff_ESI + 0x48) * 4.0;
    *(float *)(unaff_ESI + 0x58) = *(float *)(unaff_ESI + 0x58) * 4.0;
    *(float *)(unaff_ESI + 0x68) = *(float *)(unaff_ESI + 0x68) * 4.0;
  }
  fVar6 = *(float *)(unaff_ESI + 0x40) - *pfVar1;
  fVar9 = *(float *)(unaff_ESI + 0x44) - *(float *)(unaff_ESI + 0x34);
  fVar7 = *(float *)(unaff_ESI + 0x48) - *(float *)(unaff_ESI + 0x38);
  fVar10 = *(float *)(unaff_ESI + 0x50) - *pfVar1;
  fVar11 = *(float *)(unaff_ESI + 0x54) - *(float *)(unaff_ESI + 0x34);
  fVar8 = *(float *)(unaff_ESI + 0x58) - *(float *)(unaff_ESI + 0x38);
  bNormalize3();
  *(float *)(unaff_ESI + 0x74) = fVar7 * fVar10 - fVar8 * fVar6;
  *(float *)(unaff_ESI + 0x70) = fVar8 * fVar9 - fVar11 * fVar7;
  *(float *)(unaff_ESI + 0x78) = fVar11 * fVar6 - fVar9 * fVar10;
  *(float *)(unaff_ESI + 0x7c) =
       *pfVar1 * *(float *)(unaff_ESI + 0x70) +
       *(float *)(unaff_ESI + 0x34) * *(float *)(unaff_ESI + 0x74) +
       *(float *)(unaff_ESI + 0x38) * *(float *)(unaff_ESI + 0x78);
  uVar12 = SlotPool__IndexOfSlot(unaff_ESI);
  *(undefined2 *)(unaff_EDI + 6) = uVar12;
  *(int *)(unaff_ESI + 0xc) = unaff_EDI;
  return;
}


// ==== 0x4400d0 TrackPolyBody::DetachRow

/* [canon] track high (hopper+ghidra) docs/re/track.md */

void TrackPolyBody__DetachRow(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0xc) != 0) {
    *(undefined2 *)(*(int *)(in_EAX + 0xc) + 6) = 0xffff;
  }
  return;
}


// ==== 0x4400e0 TrackPolyBody::EdgeDistanceMax

/* [canon] track high (hopper+ghidra) docs/re/track.md */

float10 __fastcall TrackPolyBody__EdgeDistanceMax(int param_1,float *param_2)

{
  float fVar1;
  float10 fVar2;
  
  fVar2 = (float10)-1.0;
  fVar1 = (*param_2 - *(float *)(param_1 + 0x30)) *
          (*(float *)(param_1 + 0x44) - *(float *)(param_1 + 0x34)) -
          (*(float *)(param_1 + 0x40) - *(float *)(param_1 + 0x30)) *
          (param_2[1] - *(float *)(param_1 + 0x34));
  if ((-1.0 <= fVar1) && (fVar2 = (float10)fVar1, 0.0 < fVar1)) {
    return (float10)fVar1;
  }
  fVar1 = (*param_2 - *(float *)(param_1 + 0x40)) *
          (*(float *)(param_1 + 0x54) - *(float *)(param_1 + 0x44)) -
          (*(float *)(param_1 + 0x50) - *(float *)(param_1 + 0x40)) *
          (param_2[1] - *(float *)(param_1 + 0x44));
  if (fVar2 <= (float10)fVar1) {
    fVar2 = (float10)fVar1;
  }
  if (fVar2 <= (float10)0.0) {
    fVar1 = (*param_2 - *(float *)(param_1 + 0x60)) *
            (*(float *)(param_1 + 0x34) - *(float *)(param_1 + 100)) -
            (*(float *)(param_1 + 0x30) - *(float *)(param_1 + 0x60)) *
            (param_2[1] - *(float *)(param_1 + 100));
    if (fVar2 <= (float10)fVar1) {
      fVar2 = (float10)fVar1;
    }
    if (((fVar2 <= (float10)0.0) && (*(char *)(param_1 + 9) == '\x04')) &&
       (fVar1 = (*param_2 - *(float *)(param_1 + 0x50)) *
                (*(float *)(param_1 + 100) - *(float *)(param_1 + 0x54)) -
                (*(float *)(param_1 + 0x60) - *(float *)(param_1 + 0x50)) *
                (param_2[1] - *(float *)(param_1 + 0x54)), fVar2 <= (float10)fVar1)) {
      fVar2 = (float10)fVar1;
    }
  }
  return fVar2;
}


// ==== 0x440200 TrackPolygon::PointInShaft

/* [canon] track high (ghidra-canon+nfsug) docs/re/track.md */

undefined4 __fastcall TrackPolygon__PointInShaft(undefined4 param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  int unaff_EDI;
  float local_b0 [6];
  float local_98;
  float local_90;
  float local_8c;
  float local_88;
  float local_80;
  float local_7c;
  float local_78;
  int local_64;
  float local_60 [6];
  float local_48;
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  float local_18;
  
  iVar8 = (int)*(char *)(unaff_EDI + 9);
  if (0 < iVar8) {
    pfVar5 = (float *)(unaff_EDI + 0x38);
    pfVar6 = local_b0 + 2;
    local_64 = iVar8;
    do {
      fVar1 = pfVar5[-1];
      fVar2 = param_2[1];
      fVar3 = *pfVar5;
      fVar4 = param_2[2];
      local_18 = fVar3 - fVar4;
      pfVar6[-2] = pfVar5[-2] - *param_2;
      *pfVar6 = fVar3 - fVar4;
      pfVar6[-1] = fVar1 - fVar2;
      local_64 = local_64 + -1;
      pfVar5 = pfVar5 + 4;
      pfVar6 = pfVar6 + 4;
    } while (local_64 != 0);
  }
  local_60[0] = local_98 * local_b0[1] - local_b0[5] * local_b0[2];
  local_60[1] = local_b0[4] * local_b0[2] - local_98 * local_b0[0];
  local_60[2] = local_b0[5] * local_b0[0] - local_b0[4] * local_b0[1];
  local_60[4] = local_88 * local_b0[5] - local_8c * local_98;
  local_60[5] = local_90 * local_98 - local_88 * local_b0[4];
  local_48 = local_8c * local_b0[4] - local_90 * local_b0[5];
  if (*(char *)(unaff_EDI + 9) == '\x04') {
    local_40 = local_78 * local_8c - local_7c * local_88;
    local_3c = local_80 * local_88 - local_78 * local_90;
    local_38 = local_7c * local_90 - local_80 * local_8c;
    local_30 = local_7c * local_b0[2] - local_78 * local_b0[1];
    local_2c = local_78 * local_b0[0] - local_80 * local_b0[2];
    local_28 = local_80 * local_b0[1] - local_7c * local_b0[0];
  }
  else {
    local_40 = local_8c * local_b0[2] - local_88 * local_b0[1];
    local_3c = local_88 * local_b0[0] - local_90 * local_b0[2];
    local_38 = local_90 * local_b0[1] - local_8c * local_b0[0];
  }
  iVar7 = 0;
  if (0 < iVar8) {
    pfVar5 = local_60 + 1;
    do {
      if (*(float *)(unaff_EDI + 0x74) * *pfVar5 +
          pfVar5[1] * *(float *)(unaff_EDI + 0x78) + pfVar5[-1] * *(float *)(unaff_EDI + 0x70) < 0.0
         ) {
        return 0;
      }
      iVar7 = iVar7 + 1;
      pfVar5 = pfVar5 + 4;
    } while (iVar7 < iVar8);
  }
  if (param_3 != (float *)0x0) {
    *param_3 = -(local_b0[0] * *(float *)(unaff_EDI + 0x70) +
                local_b0[1] * *(float *)(unaff_EDI + 0x74) +
                local_b0[2] * *(float *)(unaff_EDI + 0x78));
  }
  return 1;
}


// ==== 0x440450 FUN_00440450

undefined4 __fastcall FUN_00440450(float *param_1,float *param_2)

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
  char cVar11;
  int in_EAX;
  float *unaff_ESI;
  
  fVar10 = (*param_1 - *(float *)(in_EAX + 0x30)) * *(float *)(in_EAX + 0x70) +
           (param_1[2] - *(float *)(in_EAX + 0x38)) * *(float *)(in_EAX + 0x78) +
           (param_1[1] - *(float *)(in_EAX + 0x34)) * *(float *)(in_EAX + 0x74);
  fVar7 = (*param_2 - *(float *)(in_EAX + 0x30)) * *(float *)(in_EAX + 0x70) +
          (param_2[2] - *(float *)(in_EAX + 0x38)) * *(float *)(in_EAX + 0x78) +
          (param_2[1] - *(float *)(in_EAX + 0x34)) * *(float *)(in_EAX + 0x74);
  if (fVar7 * fVar10 < 0.0) {
    fVar1 = *param_2;
    fVar2 = *param_1;
    fVar3 = param_2[1];
    fVar4 = param_1[1];
    fVar5 = param_2[2];
    fVar6 = param_1[2];
    fVar10 = ABS(fVar10);
    fVar10 = fVar10 / (ABS(fVar7) + fVar10);
    fVar7 = *param_1;
    fVar8 = param_1[1];
    fVar9 = param_1[2];
    cVar11 = TrackPolygon__PointInShaft(0);
    if (cVar11 != '\0') {
      if (unaff_ESI != (float *)0x0) {
        *unaff_ESI = (fVar1 - fVar2) * fVar10 + fVar7;
        unaff_ESI[1] = (fVar3 - fVar4) * fVar10 + fVar8;
        unaff_ESI[2] = (fVar5 - fVar6) * fVar10 + fVar9;
      }
      return 1;
    }
  }
  return 0;
}


// ==== 0x440560 FUN_00440560

uint FUN_00440560(float *param_1,float *param_2,undefined4 param_3,float *param_4,float *param_5,
                 char param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined2 uVar8;
  uint uVar6;
  uint uVar7;
  int iVar9;
  int unaff_EDI;
  
  fVar1 = *(float *)(unaff_EDI + 0x30);
  fVar2 = *(float *)(unaff_EDI + 0x34);
  fVar3 = *(float *)(unaff_EDI + 0x38);
  iVar5 = (int)*(char *)(unaff_EDI + 9);
  if (1 < iVar5) {
    iVar9 = iVar5 + -1;
    do {
      iVar5 = FUN_00567740();
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  fVar4 = *param_4;
  uVar8 = (undefined2)((uint)iVar5 >> 0x10);
  uVar6 = CONCAT22(uVar8,(ushort)(fVar4 < fVar1) << 8 | (ushort)(NAN(fVar4) || NAN(fVar1)) << 10 |
                         (ushort)(fVar4 == fVar1) << 0xe);
  if (fVar4 < fVar1) {
    fVar4 = *param_5;
    uVar6 = CONCAT22(uVar8,(ushort)(fVar4 < fVar1) << 8 | (ushort)(NAN(fVar4) || NAN(fVar1)) << 10 |
                           (ushort)(fVar4 == fVar1) << 0xe);
    if (fVar4 >= fVar1 && (fVar4 == fVar1) == 0) {
      fVar4 = param_4[1];
      uVar6 = CONCAT22(uVar8,(ushort)(fVar4 < fVar2) << 8 | (ushort)(NAN(fVar4) || NAN(fVar2)) << 10
                             | (ushort)(fVar4 == fVar2) << 0xe);
      if (fVar4 < fVar2) {
        fVar4 = param_5[1];
        uVar6 = CONCAT22(uVar8,(ushort)(fVar4 < fVar2) << 8 |
                               (ushort)(NAN(fVar4) || NAN(fVar2)) << 10 |
                               (ushort)(fVar4 == fVar2) << 0xe);
        if (fVar4 >= fVar2 && (fVar4 == fVar2) == 0) {
          fVar4 = param_4[2];
          uVar6 = CONCAT22(uVar8,(ushort)(fVar4 < fVar3) << 8 |
                                 (ushort)(NAN(fVar4) || NAN(fVar3)) << 10 |
                                 (ushort)(fVar4 == fVar3) << 0xe);
          if (fVar4 < fVar3) {
            fVar4 = param_5[2];
            uVar6 = CONCAT22(uVar8,(ushort)(fVar4 < fVar3) << 8 |
                                   (ushort)(NAN(fVar4) || NAN(fVar3)) << 10 |
                                   (ushort)(fVar4 == fVar3) << 0xe);
            if ((fVar4 >= fVar3 && (fVar4 == fVar3) == 0) &&
               (uVar6 = FUN_00440450(), (char)uVar6 != '\0')) {
              fVar1 = fVar1 - *param_2;
              fVar2 = fVar2 - param_2[1];
              fVar3 = fVar3 - param_2[2];
              uVar7 = CONCAT31((int3)(uVar6 >> 8),param_6);
              if (param_6 == '\0') {
                fVar4 = fVar1 * *(float *)(unaff_EDI + 0x70) +
                        fVar2 * *(float *)(unaff_EDI + 0x74) + fVar3 * *(float *)(unaff_EDI + 0x78);
                uVar6 = CONCAT22((short)(uVar6 >> 0x10),
                                 (ushort)(fVar4 < 0.0) << 8 | (ushort)NAN(fVar4) << 10 |
                                 (ushort)(fVar4 == 0.0) << 0xe);
                uVar7 = uVar6;
                if (fVar4 >= 0.0) goto LAB_004406bd;
              }
              fVar2 = SQRT(fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3);
              fVar1 = *param_1;
              uVar6 = CONCAT22((short)(uVar7 >> 0x10),
                               (ushort)(fVar2 < fVar1) << 8 |
                               (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                               (ushort)(fVar2 == fVar1) << 0xe);
              if (fVar2 < fVar1) {
                *param_1 = fVar2;
                return CONCAT31((int3)(uVar6 >> 8),1);
              }
            }
          }
        }
      }
    }
  }
LAB_004406bd:
  return uVar6 & 0xffffff00;
}


// ==== 0x4406d0 FUN_004406d0

void FUN_004406d0(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x2a0) = 0;
  *(undefined4 *)(in_EAX + 0x2a4) = 0;
  *(undefined4 *)(in_EAX + 0x2a8) = 0;
  *(undefined4 *)(in_EAX + 0x2ac) = 0;
  *(undefined4 *)(in_EAX + 0x2b4) = 0;
  *(undefined4 *)(in_EAX + 0x2b8) = 0;
  *(undefined4 *)(in_EAX + 700) = 0;
  FUN_00440740();
  return;
}


// ==== 0x440710 RefArray_DecrementAll

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

void RefArray_DecrementAll(void)

{
  int iVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(in_EAX + 0x2a0);
  if (0 < iVar3) {
    piVar2 = (int *)(in_EAX + 0x20);
    do {
      iVar1 = *piVar2;
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + -1;
      *(char *)(iVar1 + 8) = *(char *)(iVar1 + 8) + -1;
    } while (iVar3 != 0);
  }
  return;
}


// ==== 0x440740 FUN_00440740

void FUN_00440740(void)

{
  int iVar1;
  undefined4 *in_EAX;
  int *piVar2;
  int iVar3;
  
  *in_EAX = 0x7f7fffff;
  in_EAX[1] = 0x7f7fffff;
  in_EAX[2] = 0xff7fffff;
  in_EAX[3] = 0xff7fffff;
  in_EAX[4] = 0x7f7fffff;
  in_EAX[5] = 0x7f7fffff;
  in_EAX[6] = 0xff7fffff;
  in_EAX[7] = 0xff7fffff;
  iVar3 = in_EAX[0xa8];
  if (0 < iVar3) {
    piVar2 = in_EAX + 8;
    do {
      iVar1 = *piVar2;
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + -1;
      *(char *)(iVar1 + 8) = *(char *)(iVar1 + 8) + -1;
    } while (iVar3 != 0);
  }
  in_EAX[0xa8] = 0;
  in_EAX[0xa9] = 0;
  in_EAX[0xaa] = 0;
  in_EAX[0xab] = 0;
  in_EAX[0xac] = 0;
  return;
}


// ==== 0x4407b0 GroundQuery::RefillCache

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] track high (hopper+ghidra) docs/re/track.md */

void GroundQuery__RefillCache(float *param_1,float param_2,float *param_3)

{
  float *pfVar1;
  float fVar2;
  float *pfVar3;
  float fVar4;
  float *extraout_EDX;
  float *extraout_EDX_00;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  float *unaff_EDI;
  float local_290 [160];
  float local_10;
  float local_c;
  int local_8;
  
  pfVar1 = param_1;
  *unaff_EDI = 3.4028235e+38;
  unaff_EDI[1] = 3.4028235e+38;
  unaff_EDI[2] = -3.4028235e+38;
  unaff_EDI[3] = -3.4028235e+38;
  Aabb2D__GrowByCircle(param_2);
  pfVar6 = unaff_EDI + 4;
  pfVar5 = unaff_EDI + 6;
  if ((((*unaff_EDI < unaff_EDI[4]) || (unaff_EDI[2] < *pfVar5 == (unaff_EDI[2] == *pfVar5))) ||
      (unaff_EDI[1] < unaff_EDI[5])) ||
     (unaff_EDI[3] < unaff_EDI[7] == (unaff_EDI[3] == unaff_EDI[7]))) {
    param_1 = (float *)unaff_EDI[0xa8];
    if (0 < (int)param_1) {
      pfVar3 = unaff_EDI + 8;
      do {
        *(char *)((int)*pfVar3 + 8) = *(char *)((int)*pfVar3 + 8) + -1;
        pfVar3 = pfVar3 + 1;
        param_1 = (float *)((int)param_1 + -1);
      } while (param_1 != (float *)0x0);
    }
    param_2 = param_2 + _K_HALF;
    unaff_EDI[0xa8] = 0.0;
    unaff_EDI[0xa9] = 0.0;
    unaff_EDI[0xaa] = 0.0;
    unaff_EDI[0xab] = 0.0;
    unaff_EDI[0xac] = 0.0;
    if (param_3 == (float *)0x0) {
      *pfVar6 = 3.4028235e+38;
      unaff_EDI[5] = 3.4028235e+38;
      *pfVar5 = -3.4028235e+38;
      unaff_EDI[7] = -3.4028235e+38;
      Aabb2D__GrowByCircle(param_2);
      pfVar5 = extraout_EDX_00;
    }
    else {
      param_1 = (float *)0x3e19999a;
      local_8 = 0;
      do {
        *pfVar6 = 3.4028235e+38;
        unaff_EDI[5] = 3.4028235e+38;
        *pfVar5 = -3.4028235e+38;
        pfVar5[1] = -3.4028235e+38;
        Aabb2D__GrowByCircle(param_2);
        local_10 = (float)param_1 * *param_3 + *pfVar1;
        local_c = (float)param_1 * param_3[1] + pfVar1[1];
        Aabb2D__GrowByCircle(param_2);
        pfVar5 = extraout_EDX;
        if (SQRT((unaff_EDI[5] - extraout_EDX[1]) * (unaff_EDI[5] - extraout_EDX[1]) +
                 (*pfVar6 - *extraout_EDX) * (*pfVar6 - *extraout_EDX)) < 28.8) break;
        param_1 = (float *)((float)param_1 * 0.75);
        if (local_8 == 3) {
          param_1 = (float *)0x0;
        }
        local_8 = local_8 + 1;
      } while (local_8 < 5);
    }
    fVar2 = (float)TrackCollision__QueryBox(&DAT_0077b130,local_290,0xa0,pfVar5);
    fVar4 = 0.0;
    iVar7 = 0;
    if (0 < (int)fVar2) {
      pfVar6 = unaff_EDI + 8;
      do {
        if ((*(byte *)((int)local_290[iVar7] + 10) & 10) == 0) {
          *pfVar6 = local_290[iVar7];
          fVar4 = (float)((int)fVar4 + 1);
          pfVar6 = pfVar6 + 1;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)fVar2);
    }
    unaff_EDI[0xa9] = fVar4;
    if ((fVar4 != fVar2) && (iVar7 = 0, 0 < (int)fVar2)) {
      pfVar6 = unaff_EDI + (int)fVar4 + 8;
      do {
        if ((*(byte *)((int)local_290[iVar7] + 10) & 2) != 0) {
          *pfVar6 = local_290[iVar7];
          fVar4 = (float)((int)fVar4 + 1);
          pfVar6 = pfVar6 + 1;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)fVar2);
    }
    unaff_EDI[0xaa] = (float)((int)fVar4 - (int)unaff_EDI[0xa9]);
    if ((fVar4 != fVar2) && (iVar7 = 0, 0 < (int)fVar2)) {
      pfVar6 = unaff_EDI + (int)fVar4 + 8;
      do {
        if ((*(byte *)((int)local_290[iVar7] + 10) & 8) != 0) {
          *pfVar6 = local_290[iVar7];
          fVar4 = (float)((int)fVar4 + 1);
          pfVar6 = pfVar6 + 1;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)fVar2);
    }
    unaff_EDI[0xab] = (float)(((int)fVar4 - (int)unaff_EDI[0xa9]) - (int)unaff_EDI[0xaa]);
    unaff_EDI[0xa8] = fVar2;
  }
  return;
}


// ==== 0x440a40 GroundQuery::FindSurfaceBelow

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] track high (hopper+ghidra) docs/re/track.md */

int * GroundQuery__FindSurfaceBelow
                (float *param_1,float *param_2,int *param_3,int *param_4,undefined1 *param_5)

{
  int iVar1;
  float fVar2;
  float *pfVar3;
  float fVar4;
  int iVar5;
  float10 fVar6;
  int local_c;
  float local_8;
  int local_4;
  
  pfVar3 = param_2;
  if (param_5 != (undefined1 *)0x0) {
    *param_5 = 1;
  }
  fVar4 = param_1[0xac];
  if ((fVar4 == 0.0) || (fVar6 = (float10)TrackPolyBody__EdgeDistanceMax(), (float10)0.0 <= fVar6))
  {
    if ((*param_2 < *param_1) ||
       (((param_1[2] < *param_2 || (param_2[1] < param_1[1])) || (param_1[3] < param_2[1])))) {
      GroundQuery__RefillCache(param_2,0x41000000,0);
    }
    fVar4 = param_1[0xa9];
    local_8 = param_2[2] + _K_ONE;
    local_4 = 0;
    do {
      iVar5 = 0;
      param_2 = (float *)0xff7fffff;
      local_c = -1;
      if (0 < (int)fVar4) {
        do {
          fVar4 = param_1[iVar5 + 8];
          if (((*(float *)((int)fVar4 + 0x14) <= *pfVar3) &&
              (*pfVar3 < *(float *)((int)fVar4 + 0x1c) != (*pfVar3 == *(float *)((int)fVar4 + 0x1c))
              )) && ((*(float *)((int)fVar4 + 0x18) <= pfVar3[1] &&
                     (pfVar3[1] < *(float *)((int)fVar4 + 0x20) !=
                      (pfVar3[1] == *(float *)((int)fVar4 + 0x20)))))) {
            fVar6 = (float10)TrackPolyBody__EdgeDistanceMax();
            if (((fVar6 < (float10)0.0 != (fVar6 == (float10)0.0)) &&
                (fVar2 = -(((*(float *)((int)fVar4 + 0x70) * *pfVar3 +
                            *(float *)((int)fVar4 + 0x74) * pfVar3[1]) -
                           *(float *)((int)fVar4 + 0x7c)) / *(float *)((int)fVar4 + 0x78)),
                (float)param_2 < fVar2)) &&
               ((fVar2 < local_8 &&
                ((param_2 = (float *)fVar2, local_c = iVar5, (*(byte *)((int)fVar4 + 10) & 1) == 0
                 && ((float)fVar6 < 0.0)))))) {
              param_1[0xac] = fVar4;
              goto LAB_00440c7c;
            }
          }
          fVar4 = param_1[0xa9];
          iVar5 = iVar5 + 1;
        } while (iVar5 < (int)fVar4);
        if (-1 < local_c) {
LAB_00440c7c:
          if (-1 < local_c) {
            fVar4 = param_1[local_c + 8];
            if (4 < local_c) {
              for (; 0 < local_c; local_c = local_c + -1) {
                param_1[local_c + 8] = param_1[local_c + 7];
              }
              param_1[8] = fVar4;
            }
            if (param_3 != (int *)0x0) {
              *param_3 = (int)*(char *)((int)fVar4 + 0xb);
            }
            if (param_4 == (int *)0x0) {
              return (int *)0x0;
            }
            iVar5 = *(int *)((int)fVar4 + 0x78);
            iVar1 = *(int *)((int)fVar4 + 0x70);
            param_4[1] = *(int *)((int)fVar4 + 0x74);
            *param_4 = iVar1;
            param_4[2] = iVar5;
            return param_4;
          }
          goto LAB_00440c40;
        }
      }
      local_4 = local_4 + 1;
      local_8 = 3.4028235e+38;
    } while (local_4 < 2);
    if (param_5 != (undefined1 *)0x0) {
      *param_5 = 0;
    }
LAB_00440c40:
    if (param_3 != (int *)0x0) {
      *param_3 = 1;
    }
    param_3 = param_4;
    if (param_4 != (int *)0x0) {
      *param_4 = 0;
      param_4[1] = 0;
      param_4[2] = -0x40800000;
    }
  }
  else {
    if (param_3 != (int *)0x0) {
      *param_3 = (int)*(char *)((int)fVar4 + 0xb);
    }
    if (param_4 != (int *)0x0) {
      fVar4 = param_1[0xac];
      iVar1 = *(int *)((int)fVar4 + 0x70);
      iVar5 = *(int *)((int)fVar4 + 0x78);
      param_4[1] = *(int *)((int)fVar4 + 0x74);
      *param_4 = iVar1;
      param_4[2] = iVar5;
      return (int *)((int)fVar4 + 0x70);
    }
  }
  return param_3;
}


// ==== 0x440ce0 GroundQuery::HasGroundAt

/* [canon] track med (hopper+ghidra) docs/re/track.md */

undefined1 GroundQuery__HasGroundAt(undefined4 param_1)

{
  undefined4 *in_EAX;
  undefined1 local_21;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_20 = *in_EAX;
  local_1c = in_EAX[1];
  local_18 = 0x47c34f8d;
  GroundQuery__FindSurfaceBelow(param_1,&local_20,0,0,&local_21);
  return local_21;
}


// ==== 0x440d30 FUN_00440d30

undefined4 FUN_00440d30(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_30 = *param_2;
  local_2c = param_2[1];
  local_28 = param_2[2];
  local_20 = local_30;
  local_1c = local_2c;
  local_18 = local_28;
  FUN_005677d0(param_4);
  local_34 = 0x497423f0;
  local_38 = 0;
  if (0 < *(int *)(param_1 + 0x2a0)) {
    do {
      cVar1 = FUN_00440560(&local_34,param_2,param_3,&local_20,&local_30,0);
      if (cVar1 != '\0') {
        return 1;
      }
      local_38 = local_38 + 1;
    } while (local_38 < *(int *)(param_1 + 0x2a0));
  }
  return 0;
}


// ==== 0x440e00 GroundQuery::SweepSegment

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] track med (hopper+ghidra) docs/re/track.md */

undefined4 GroundQuery__SweepSegment(float *param_1)

{
  float fVar1;
  float fVar2;
  char cVar3;
  undefined4 in_EAX;
  undefined4 uVar4;
  int iVar5;
  float *unaff_ESI;
  int local_70;
  float local_60;
  float local_5c;
  float local_58;
  float local_50;
  float local_4c;
  float local_48;
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  float local_1c;
  float local_18;
  
  fVar1 = SQRT((*param_1 - *unaff_ESI) * (*param_1 - *unaff_ESI) +
               (param_1[1] - unaff_ESI[1]) * (param_1[1] - unaff_ESI[1]) +
               (param_1[2] - unaff_ESI[2]) * (param_1[2] - unaff_ESI[2]));
  if (fVar1 < 30.0) {
    local_60 = (*param_1 + *unaff_ESI) * _K_HALF;
    local_5c = (unaff_ESI[1] + param_1[1]) * _K_HALF;
    local_58 = (unaff_ESI[2] + param_1[2]) * _K_HALF;
    GroundQuery__RefillCache(&local_60,fVar1 * _K_HALF,0);
    uVar4 = FUN_00440d30(in_EAX,param_1,unaff_ESI,0x3f000000);
    return uVar4;
  }
  bCeil(fVar1 / 30.0);
  iVar5 = _ftol_nocw();
  local_40 = *unaff_ESI;
  local_3c = unaff_ESI[1];
  local_38 = unaff_ESI[2];
  local_70 = 1;
  local_30 = *param_1 - *unaff_ESI;
  local_2c = param_1[1] - unaff_ESI[1];
  local_28 = param_1[2] - unaff_ESI[2];
  if (0 < iVar5) {
    fVar1 = (fVar1 / (float)iVar5) * _K_HALF;
    do {
      fVar2 = (float)local_70 / (float)iVar5;
      local_1c = local_2c * fVar2;
      local_18 = local_28 * fVar2;
      local_50 = local_30 * fVar2 + *unaff_ESI;
      local_4c = local_1c + unaff_ESI[1];
      local_48 = local_18 + unaff_ESI[2];
      local_60 = (local_50 + local_40) * _K_HALF;
      local_5c = (local_4c + local_3c) * _K_HALF;
      local_58 = (local_48 + local_38) * _K_HALF;
      GroundQuery__RefillCache(&local_60,fVar1,0);
      cVar3 = FUN_00440d30(in_EAX,&local_50,&local_40,0x3f000000);
      if (cVar3 != '\0') {
        return 1;
      }
      local_3c = local_4c;
      local_38 = local_48;
      local_70 = local_70 + 1;
      local_40 = local_50;
    } while (local_70 <= iVar5);
    return 0;
  }
  return 0;
}


