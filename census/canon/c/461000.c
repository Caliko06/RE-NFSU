// ==== 0x4611f0 RealDriver::AddJoyHandlers

/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

void __fastcall RealDriver__AddJoyHandlers(int param_1)

{
  if (*(int *)(param_1 + 0x274) == 0) {
    if (*(char *)(param_1 + 0x2b8) != '\0') {
      InputEvents__AddSource(0x87,RealDriver__JoyHandler_Steer,param_1);
      InputEvents__AddSource(0x88,RealDriver__JoyHandler_Steer,param_1);
    }
    InputEvents__AddSource(0x89,RealDriver__JoyHandler_Throttle,param_1);
    InputEvents__AddSource(0x8a,RealDriver__JoyHandler_Throttle,param_1);
    InputEvents__AddSource(0x8b,RealDriver__JoyHandler_Throttle,param_1);
    InputEvents__AddSource(0x8c,RealDriver__JoyHandler_Brake,param_1);
    InputEvents__AddSource(0x8d,RealDriver__JoyHandler_Brake,param_1);
    InputEvents__AddSource(0x8e,RealDriver__JoyHandler_Brake,param_1);
    InputEvents__AddSource(0x8f,RealDriver__JoyHandler_Reverse,param_1);
    InputEvents__AddSource(0x90,RealDriver__JoyHandler_Reverse,param_1);
    InputEvents__AddSource(0x91,FUN_00461e10,param_1);
    InputEvents__AddSource(0x92,FUN_00461e10,param_1);
    InputEvents__AddSource(0x93,FUN_00461e70,param_1);
    InputEvents__AddSource(0x95,FUN_00461e70,param_1);
    InputEvents__AddSource(0x94,FUN_00461f40,param_1);
    InputEvents__AddSource(0x96,FUN_00461f40,param_1);
    InputEvents__AddSource(0x97,FUN_00461ff0,param_1);
    InputEvents__AddSource(0x98,FUN_00461ff0,param_1);
    *(undefined4 *)(param_1 + 0x274) = 1;
  }
  return;
}


// ==== 0x4613b0 FUN_004613b0

void __fastcall FUN_004613b0(int *param_1)

{
  if (param_1[0x9d] != 0) {
    if ((char)param_1[0xae] != '\0') {
      FUN_005740b0(0x87);
      FUN_005740b0(0x88);
    }
    FUN_005740b0(0x89);
    FUN_005740b0(0x8a);
    FUN_005740b0(0x8b);
    FUN_005740b0(0x8c);
    FUN_005740b0(0x8d);
    FUN_005740b0(0x8e);
    FUN_005740b0(0x8f);
    FUN_005740b0(0x90);
    FUN_005740b0(0x91);
    FUN_005740b0(0x92);
    FUN_005740b0(0x93);
    FUN_005740b0(0x95);
    FUN_005740b0(0x94);
    FUN_005740b0(0x96);
    FUN_005740b0(0x97);
    FUN_005740b0(0x98);
    (**(code **)(*param_1 + 0x4c))();
    param_1[0x9d] = 0;
  }
  return;
}


// ==== 0x461510 RealDriver::DisableStartLineState

/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

void __fastcall RealDriver__DisableStartLineState(int *param_1)

{
  param_1[0x9e] = 0;
                    /* WARNING: Could not recover jumptable at 0x0046151c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x34))();
  return;
}


// ==== 0x461520 RealDriver::SetManualTransmission

/* [canon] runtime high (ghidra-canon+nfsug) docs/re/runtime.md */

void __fastcall RealDriver__SetManualTransmission(int param_1)

{
  int in_EAX;
  
  if (param_1 == 3) {
    *(undefined4 *)(in_EAX + 0x1d4) = *(undefined4 *)(*(int *)(in_EAX + 0x26c) + 0x3d8);
    *(undefined4 *)(in_EAX + 0x284) = 3;
  }
  else if (param_1 == 1) {
    *(undefined4 *)(in_EAX + 0x1d4) = *(undefined4 *)(*(int *)(in_EAX + 0x26c) + 0x3d8);
    *(undefined4 *)(in_EAX + 0x284) = 1;
  }
  else {
    *(undefined4 *)(in_EAX + 0x1d4) = 0xffffffff;
    if (param_1 == 0) {
      *(undefined4 *)(in_EAX + 0x284) = 0;
    }
    else {
      *(undefined4 *)(in_EAX + 0x284) = 2;
    }
  }
  if (*(int *)(*(int *)(in_EAX + 0x26c) + 0x28) == 1) {
    *(undefined4 *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x26c) + 0x34) + 0x4c) + 0x60) =
         *(undefined4 *)(in_EAX + 0x284);
  }
  return;
}


// ==== 0x4615b0 RealDriver::SetLowGear

/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

void __fastcall RealDriver__SetLowGear(int param_1)

{
  if ((*(int *)(param_1 + 0x284) != 1) && (*(int *)(param_1 + 0x284) != 3)) {
    *(undefined4 *)(param_1 + 0x1d4) = 0xffffffff;
    return;
  }
  *(undefined4 *)(param_1 + 0x1d4) = 2;
  return;
}


// ==== 0x4615e0 FUN_004615e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004615e0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  (**(code **)(**(int **)(*(int *)(param_1 + 0x26c) + 0x2c) + 0x40))();
  if (*(char *)(*(int *)(*(int *)(param_1 + 0x26c) + 0x10) + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  if ((&DAT_007306c4)[*(int *)(param_1 + 0x270)] == -1) {
    RealDriver__ResetJoyValues();
  }
  if (*(int *)(param_1 + 0x27c) != 0) {
    *(undefined4 *)(param_1 + 0x294) = 0;
    *(undefined4 *)(param_1 + 0x29c) = 0x3f800000;
  }
  FUN_00461a60(param_1,param_2);
  if ((*(char *)(param_1 + 0x2b8) != '\0') &&
     (_DAT_0070031c < *(float *)(*(int *)(param_1 + 0x26c) + 0x3b8))) {
    uVar3 = FUN_00460930(*(undefined4 *)(param_1 + 0x28c),param_2,*(undefined4 *)(param_1 + 0x270));
    *(undefined2 *)(param_1 + 0x1d0) = uVar3;
  }
  if (*(int *)(param_1 + 0x278) != 0) {
    *(undefined4 *)(param_1 + 0x1d4) = 1;
    *(undefined4 *)(param_1 + 0x1e4) = 0x3f800000;
  }
  iVar1 = *(int *)(param_1 + 0x26c);
  if (*(int *)(iVar1 + 0x28) == 1) {
    iVar2 = *(int *)(*(int *)(iVar1 + 0x34) + 0x4c);
    if (*(int *)(param_1 + 0x284) == 3) {
      if ((*(int *)(iVar1 + 0x3d8) != *(int *)(param_1 + 0x1d4)) &&
         ((*(int *)(iVar1 + 0x3d8) < 2 || (*(int *)(param_1 + 0x1d4) < 2)))) {
        *(undefined4 *)(param_1 + 0x284) = 4;
        *(undefined4 *)(iVar2 + 0x60) = 0;
      }
    }
    else if ((*(int *)(param_1 + 0x284) == 4) &&
            ((*(int *)(iVar1 + 0x28) != 1 ||
             (*(int *)(*(int *)(*(int *)(iVar1 + 0x34) + 0x4c) + 0x48) == 0)))) {
      *(undefined4 *)(param_1 + 0x284) = 3;
      *(undefined4 *)(iVar2 + 0x60) = 3;
    }
    if (*(int *)(param_1 + 0x284) == 3) {
      *(undefined4 *)(iVar2 + 0x60) = 3;
      DriveTrain__SetManualClutchEngaged(*(undefined4 *)(param_1 + 0x2b4));
      return;
    }
    if (((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) &&
       ((DAT_00735fa0 != 0 || ((DAT_0078a345 != '\0' || (DAT_007361a4 != 0)))))) {
      if (0.6 < *(float *)(param_1 + 0x1e0)) {
        *(undefined1 *)(iVar2 + 0x74) = 1;
        return;
      }
      *(undefined1 *)(iVar2 + 0x74) = 0;
    }
  }
  return;
}


// ==== 0x4617d0 RealDriver::ResetJoyValues

/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

void RealDriver__ResetJoyValues(void)

{
  int in_EAX;
  
  *(undefined1 *)(in_EAX + 0x288) = 0x80;
  *(undefined1 *)(in_EAX + 0x289) = 0x80;
  *(undefined1 *)(in_EAX + 0x290) = 0;
  *(undefined1 *)(in_EAX + 0x291) = 0;
  *(undefined1 *)(in_EAX + 0x292) = 0;
  *(undefined1 *)(in_EAX + 0x298) = 0;
  *(undefined1 *)(in_EAX + 0x299) = 0;
  *(undefined1 *)(in_EAX + 0x29a) = 0;
  *(undefined1 *)(in_EAX + 0x2a0) = 0;
  *(undefined1 *)(in_EAX + 0x2a1) = 0;
  *(undefined1 *)(in_EAX + 0x2a8) = 0;
  *(undefined1 *)(in_EAX + 0x2a9) = 0;
  *(undefined4 *)(in_EAX + 0x28c) = 0;
  *(undefined4 *)(in_EAX + 0x294) = 0;
  *(undefined4 *)(in_EAX + 0x29c) = 0;
  *(undefined4 *)(in_EAX + 0x2a4) = 0;
  *(undefined4 *)(in_EAX + 0x2ac) = 0;
  return;
}


// ==== 0x461840 RealDriver::JoyHandler_Steer

/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

void RealDriver__JoyHandler_Steer(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  byte bVar1;
  
  if (param_2 == 0x87) {
    *(undefined1 *)(param_4 + 0x288) = param_3;
  }
  else if (param_2 == 0x88) {
    *(undefined1 *)(param_4 + 0x289) = param_3;
  }
  bVar1 = *(byte *)(param_4 + 0x288);
  if (bVar1 == 0x80) {
    bVar1 = *(byte *)(param_4 + 0x289);
  }
  if (bVar1 == 0xff) {
    *(undefined4 *)(param_4 + 0x28c) = 0xbf800000;
    return;
  }
  *(float *)(param_4 + 0x28c) = ((float)bVar1 - 128.0) * -0.0078125;
  return;
}


// ==== 0x4618b0 RealDriver::JoyHandler_Throttle

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

void RealDriver__JoyHandler_Throttle(undefined4 param_1,float param_2,byte param_3,int param_4)

{
  int iVar1;
  undefined1 uVar2;
  byte bVar3;
  
  iVar1 = param_4;
  if (param_2 == 1.91978e-43) {
    *(byte *)(param_4 + 0x290) = param_3;
  }
  else if (param_2 == 1.93379e-43) {
    param_2 = (float)(uint)param_3;
    uVar2 = _ftol_nocw();
    *(undefined1 *)(iVar1 + 0x291) = uVar2;
  }
  else if (param_2 == 1.9478e-43) {
    param_2 = (float)(uint)param_3;
    uVar2 = _ftol_nocw();
    *(undefined1 *)(iVar1 + 0x292) = uVar2;
  }
  bVar3 = *(byte *)(iVar1 + 0x290);
  if (*(byte *)(iVar1 + 0x290) == 0) {
    bVar3 = *(byte *)(iVar1 + 0x291);
    if (*(byte *)(iVar1 + 0x291) <= *(byte *)(iVar1 + 0x292)) {
      bVar3 = *(byte *)(iVar1 + 0x292);
    }
  }
  param_2 = (float)bVar3 * _K_BLUR_MIN_T;
  *(float *)(iVar1 + 0x294) = param_2;
  if (*(int *)(*(int *)(iVar1 + 0x26c) + 0x3d8) == 1) {
    Curve_Evaluate(&param_2,param_2);
    *(float *)(iVar1 + 0x294) = param_2;
  }
  return;
}


// ==== 0x4619c0 RealDriver::JoyHandler_Reverse

/* WARNING: Removing unreachable block (ram,0x004619f3) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car med (ghidra-canon+nfsug) docs/re/car.md */

void RealDriver__JoyHandler_Reverse(undefined4 param_1,int param_2,byte param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  
  if (param_2 == 0x8f) {
    *(byte *)(param_4 + 0x2a0) = param_3;
  }
  else if (param_2 == 0x90) {
    uVar2 = (uint)param_3;
    if (*(int *)(*(int *)(param_4 + 0x26c) + 0x3d8) == 1) {
      uVar2 = _ftol_nocw();
    }
    if (uVar2 < 0x100) {
      *(char *)(param_4 + 0x2a1) = (char)uVar2;
    }
    else {
      *(undefined1 *)(param_4 + 0x2a1) = 0xff;
    }
  }
  bVar1 = *(byte *)(param_4 + 0x2a0);
  if (bVar1 == 0) {
    bVar1 = *(byte *)(param_4 + 0x2a1);
  }
  *(float *)(param_4 + 0x2a4) = (float)bVar1 * _K_BLUR_MIN_T;
  return;
}


// ==== 0x461a60 FUN_00461a60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00461a60(int *param_1,float param_2)

{
  float fVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  bool bVar7;
  float10 fVar8;
  float local_c;
  float local_8;
  
  iVar2 = param_1[0x9b];
  fVar3 = *(float *)(iVar2 + 0x3d0);
  param_1[0xa0] = (int)((float)param_1[0xa0] - param_2);
  if (((float)param_1[0xa0] <= 0.0) || (ABS(fVar3) <= K_EPS_SPEED)) {
    param_1[0xa0] = 0;
    fVar1 = (float)param_1[0xa5];
    param_1[0x78] = param_1[0xab];
  }
  else {
    fVar1 = 0.0;
    param_1[0x78] = 0x3f800000;
  }
  if ((float)param_1[0xa7] <= 0.6) {
    if (_DAT_007003ac < fVar3) {
      *(undefined1 *)(param_1 + 0xac) = 0;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0xac) = 1;
  }
  local_c = fVar1;
  if (fVar3 <= _DAT_007003a4) {
    if ((fVar3 < _DAT_007003a8) || (((char)param_1[0xac] != '\0' && (fVar3 < _DAT_007003ac)))) {
      local_c = 0.0;
    }
    else {
      fVar1 = 0.0;
    }
    local_8 = (float)param_1[0xa7];
  }
  else {
    fVar1 = (float)param_1[0xa7];
    local_8 = 0.0;
  }
  local_8 = local_8 + local_8;
  if (_K_ONE < local_8) {
    local_8 = 1.0;
  }
  param_1[0x79] = (int)fVar1;
  if (_K_HALF < (float)param_1[0x78]) {
    uVar6 = DAT_006f08a4 + 1U & 0x80000007;
    bVar7 = uVar6 == 0;
    if ((int)uVar6 < 0) {
      bVar7 = (uVar6 - 1 | 0xfffffff8) == 0xffffffff;
    }
    if ((bVar7) && (10.0 < *(float *)(param_1[0x9b] + 0x3d4))) {
      FUN_00572970(0x3f800000,"EBrake");
    }
  }
  if (local_c + 0.2 < local_8) {
    param_1[0x77] = (int)local_8;
    param_1[0x75] = 0;
    goto LAB_00461d3f;
  }
  iVar4 = param_1[0x9b];
  if (*(int *)(iVar4 + 0x3d8) == 1) {
    fVar3 = _DAT_007003b0 * param_2 + (float)param_1[0x77];
    fVar1 = (float)param_1[0x77] - _DAT_007003b4 * param_2;
    if (fVar1 < local_c) {
      fVar1 = local_c;
    }
    local_c = fVar1;
    if (fVar3 < fVar1) {
      local_c = fVar3;
    }
    if ((((float)param_1[0xa5] <= 0.6) ||
        (fVar8 = (float10)FUN_00424e20(iVar4),
        (float10)*(float *)(*(int *)(iVar4 + 0x20) + 0x1f0) + (float10)1000.0 <= fVar8)) ||
       (0.6 <= local_c)) goto LAB_00461cf3;
    local_c = 0.6;
LAB_00461d08:
    if (_K_ONE < local_c) {
      local_c = _K_ONE;
    }
  }
  else {
LAB_00461cf3:
    if (0.0 < local_c) goto LAB_00461d08;
    local_c = 0.0;
  }
  param_1[0x77] = (int)local_c;
  if (param_1[0x75] == 0) {
    (**(code **)(*param_1 + 0x34))();
  }
LAB_00461d3f:
  cVar5 = FUN_0043a2e0();
  if ((cVar5 != '\0') && ((*DAT_007361f0 == 7 || (*DAT_007361f0 == 0xb)))) {
    param_1[0x77] = 0;
    param_1[0x79] = 0x3f000000;
  }
  *(int *)(iVar2 + 0x3dc) = param_1[0x77];
  return;
}


// ==== 0x461da0 RealDriver::JoyHandler_Brake

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car med (ghidra-canon+nfsug) docs/re/car.md */

void RealDriver__JoyHandler_Brake(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  byte bVar1;
  
  if (param_2 == 0x8c) {
    *(undefined1 *)(param_4 + 0x298) = param_3;
  }
  else if (param_2 == 0x8d) {
    *(undefined1 *)(param_4 + 0x299) = param_3;
  }
  else if (param_2 == 0x8e) {
    *(undefined1 *)(param_4 + 0x29a) = param_3;
  }
  bVar1 = *(byte *)(param_4 + 0x298);
  if (*(byte *)(param_4 + 0x298) == 0) {
    bVar1 = *(byte *)(param_4 + 0x299);
    if (*(byte *)(param_4 + 0x299) <= *(byte *)(param_4 + 0x29a)) {
      bVar1 = *(byte *)(param_4 + 0x29a);
    }
  }
  *(float *)(param_4 + 0x29c) = (float)bVar1 * _K_BLUR_MIN_T;
  return;
}


// ==== 0x461e10 FUN_00461e10

/* WARNING: Removing unreachable block (ram,0x00461e32) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00461e10(undefined4 param_1,int param_2,char param_3,int param_4)

{
  byte bVar1;
  
  if (param_2 == 0x91) {
    *(char *)(param_4 + 0x2a8) = param_3;
  }
  else if (param_2 == 0x92) {
    *(char *)(param_4 + 0x2a9) = param_3 << 1;
  }
  bVar1 = *(byte *)(param_4 + 0x2a8);
  if (bVar1 == 0) {
    bVar1 = *(byte *)(param_4 + 0x2a9);
  }
  *(float *)(param_4 + 0x2ac) = (float)bVar1 * _K_BLUR_MIN_T;
  return;
}


// ==== 0x461e70 FUN_00461e70

void FUN_00461e70(undefined4 param_1,undefined4 param_2,char param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_3 != '\0') {
    iVar1 = *(int *)(param_4 + 0x284);
    if (iVar1 == 3) {
      if (*(int *)(param_4 + 0x1d4) != 0) {
        iVar1 = *(int *)(*(int *)(param_4 + 0x26c) + 0x3d8);
        if (iVar1 < *(int *)(*(int *)(*(int *)(param_4 + 0x26c) + 0x20) + 0x1c8) + 1) {
          *(int *)(param_4 + 0x1d4) = iVar1 + 1;
          return;
        }
LAB_00461edf:
        *(int *)(param_4 + 0x1d4) = iVar1;
        return;
      }
    }
    else if (iVar1 == 1) {
      iVar1 = *(int *)(param_4 + 0x1d4);
      if ((iVar1 != 0) && (iVar1 < *(int *)(*(int *)(*(int *)(param_4 + 0x26c) + 0x20) + 0x1c8) + 1)
         ) {
        iVar1 = iVar1 + 1;
        goto LAB_00461edf;
      }
    }
    else if ((iVar1 == 2) && (iVar1 = *(int *)(param_4 + 0x26c), *(int *)(iVar1 + 0x28) != 3)) {
      if (*(int *)(param_4 + 0x1d4) != -2) {
        *(undefined4 *)(param_4 + 0x1d4) = 0xfffffffe;
        iVar2 = *(int *)(iVar1 + 0x3d8);
        if (iVar2 < *(int *)(*(int *)(iVar1 + 0x20) + 0x1c8) + 1) {
          iVar2 = iVar2 + 1;
        }
        *(int *)(param_4 + 0x1d8) = iVar2;
        return;
      }
      *(int *)(param_4 + 0x1d8) = *(int *)(param_4 + 0x1d8) + 1;
    }
  }
  return;
}


// ==== 0x461f40 FUN_00461f40

void FUN_00461f40(undefined4 param_1,undefined4 param_2,char param_3,int param_4)

{
  int iVar1;
  
  if (param_3 != '\0') {
    iVar1 = *(int *)(param_4 + 0x284);
    if (iVar1 == 3) {
      if (*(int *)(param_4 + 0x1d4) != 0) {
        iVar1 = *(int *)(*(int *)(param_4 + 0x26c) + 0x3d8);
        if (1 < iVar1) {
          *(int *)(param_4 + 0x1d4) = iVar1 + -1;
          return;
        }
LAB_00461f93:
        *(int *)(param_4 + 0x1d4) = iVar1;
        return;
      }
    }
    else if (iVar1 == 1) {
      iVar1 = *(int *)(param_4 + 0x1d4);
      if ((iVar1 != 0) && (1 < iVar1)) {
        iVar1 = iVar1 + -1;
        goto LAB_00461f93;
      }
    }
    else if ((iVar1 == 2) && (*(int *)(*(int *)(param_4 + 0x26c) + 0x28) != 3)) {
      if (*(int *)(param_4 + 0x1d4) == -2) {
        iVar1 = *(int *)(param_4 + 0x1d8);
      }
      else {
        *(undefined4 *)(param_4 + 0x1d4) = 0xfffffffe;
        iVar1 = *(int *)(*(int *)(param_4 + 0x26c) + 0x3d8);
        if (iVar1 < 3) {
          *(int *)(param_4 + 0x1d8) = iVar1;
          return;
        }
      }
      *(int *)(param_4 + 0x1d8) = iVar1 + -1;
    }
  }
  return;
}


// ==== 0x461ff0 FUN_00461ff0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00461ff0(undefined4 param_1,int param_2,byte param_3,int param_4)

{
  float fVar1;
  
  if (*(int *)(param_4 + 0x284) == 3) {
    if (param_2 == 0x97) {
      if (param_3 != 0) {
        *(undefined4 *)(param_4 + 0x2b4) = 0;
        return;
      }
      *(undefined4 *)(param_4 + 0x2b4) = 0x3f800000;
    }
    else if (param_2 == 0x98) {
      fVar1 = (float)param_3 * 1.07;
      if (K_BLUR_MIN_T < (float)param_3 * 1.07) {
        fVar1 = K_BLUR_MIN_T;
      }
      *(float *)(param_4 + 0x2b4) = _K_ONE - fVar1 * _K_BLUR_MIN_T;
      return;
    }
  }
  return;
}


// ==== 0x462070 RacerAITuning::Loader

/* [canon] assets high (Hopper sub_462070 + Ghidra make FUN_00462070: H+G agree) docs/re/assets.md
    */

undefined4 RacerAITuning__Loader(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (*param_1 == 0x34b00) {
    piVar2 = param_1 + 2;
    piVar3 = &DAT_00779c78;
    for (iVar1 = 0x20b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    return 1;
  }
  return 0;
}


// ==== 0x4620a0 RacerAITuning::Unloader

/* [canon] assets high (Ghidra make FUN_004620a0 (Hopper export lacks it)) docs/re/assets.md */

bool RacerAITuning__Unloader(int *param_1)

{
  return *param_1 == 0x34b00;
}


// ==== 0x4620c0 FUN_004620c0

undefined4 * FUN_004620c0(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  int unaff_EDI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006866fb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0044a330(param_1,unaff_EDI);
  *param_1 = &PTR_FUN_006c89f0;
  param_1[0x135] = 0;
  param_1[0x136] = 0;
  param_1[0x138] = 0;
  param_1[0x139] = 0;
  param_1[0x13a] = 0;
  param_1[0x13b] = 0;
  param_1[0x13c] = 0;
  param_1[0x13d] = 0;
  param_1[0x13e] = 0;
  local_4 = 0;
  param_1[0xfe] = 0;
  param_1[0x134] = 0;
  puVar1 = _malloc(0x28);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar1 + 1) = 4;
    *(undefined1 *)((int)puVar1 + 5) = 5;
    *(undefined1 *)((int)puVar1 + 6) = 0;
    *(undefined1 *)((int)puVar1 + 7) = 0;
    *puVar1 = &PTR_FUN_006b9694;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = puVar1 + 5;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
  }
  param_1[0x137] = puVar1;
  if (*(int *)(unaff_EDI + 0x24) == 3) {
    pvVar2 = _malloc(0x250);
    local_4 = CONCAT31(local_4._1_3_,1);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_0045dbb0(pvVar2,unaff_EDI);
    }
    param_1[2] = uVar3;
  }
  param_1[0x13b] = 0;
  param_1[0x13c] = 0;
  param_1[0x13d] = 0;
  param_1[0x13e] = 0;
  param_1[0x135] = 0;
  uVar3 = _ftol_nocw();
  param_1[0x136] = uVar3;
  uVar3 = DAT_007000f4;
  param_1[0x138] = 0;
  param_1[0x139] = 0;
  param_1[0x13a] = 0;
  *(undefined4 *)(unaff_EDI + 0x478) = uVar3;
  if (*(int *)(unaff_EDI + 0x28) == 1) {
    *(undefined4 *)(*(int *)(unaff_EDI + 0x34) + 0x78) = DAT_007000f4;
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x462230 FUN_00462230

void * __thiscall FUN_00462230(void *param_1,byte param_2)

{
  FUN_00462250(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x462250 FUN_00462250

void FUN_00462250(undefined4 *param_1)

{
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006850e8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c89f0;
  local_4 = 0;
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[2])(1);
  }
  if ((undefined4 *)param_1[0x137] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x137])(1);
  }
  local_4 = 0xffffffff;
  FUN_0044a660();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4622c0 FUN_004622c0

void __thiscall FUN_004622c0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIDriver");
  FUN_0044a6f0(param_2);
  FUN_00571c20(param_2,param_1 + 0x4d4,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x4d8,4,0xffffffff,0);
  FUN_005840c0(*(undefined4 *)(*(int *)(param_1 + 0x4dc) + 0x10));
  FUN_00462ee0();
  FUN_00571c20(param_2,param_1 + 0x4e0,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x4e4,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x4e8,4,0xffffffff,0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10 + 0x4c + param_2;
  *(int *)(iVar1 + 0xc) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x462390 FUN_00462390

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00462390(void)

{
  float fVar1;
  float10 fVar2;
  
  fVar1 = DAT_007006ec;
  if (DAT_007006ec < _DAT_007006f0) {
    fVar1 = _DAT_007006f0;
  }
  fVar2 = (float10)fVar1;
  if (fVar2 <= (float10)2.0) {
    fVar2 = (float10)2.0;
  }
  return fVar2;
}


// ==== 0x4623d0 Racer::ChooseGoal

/* [canon] rivals V (capstone+Hopper) docs/re/rivals.md */

void __fastcall Racer__ChooseGoal(int param_1)

{
  if (((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) &&
     ((DAT_0078a2f0 != 1099 || ((DAT_00735fb0 == 0 || (DAT_00735fb8 != 4)))))) {
    AIGoal__Create(1);
    return;
  }
  if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 0x14) + 4) == 1) {
    AIGoal__Create(3);
    return;
  }
  AIGoal__Create(2);
  return;
}


// ==== 0x462430 FUN_00462430

void __thiscall FUN_00462430(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x478) = DAT_007000f4;
  if (*(int *)(iVar1 + 0x28) == 1) {
    *(undefined4 *)(*(int *)(iVar1 + 0x34) + 0x78) = DAT_007000f4;
  }
  if ((*(int *)(param_1 + 0x4d8) != 0) && (*(int *)(param_1 + 0x4d8) != 0x7fffffff)) {
    iVar1 = FUN_00586640(param_2);
    if (iVar1 == 0) {
      uVar2 = _ftol_nocw();
      *(undefined4 *)(param_1 + 0x4d8) = uVar2;
      FUN_00584270(ABS(*(float *)(*(int *)(*(int *)(param_1 + 4) + 0x1c) + 0x18)) * DAT_007372b0);
    }
  }
  FUN_0044b1b0(param_2);
  return;
}


// ==== 0x4624d0 FUN_004624d0

void __thiscall FUN_004624d0(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *unaff_ESI;
  undefined4 uVar4;
  
  if (param_3 == 0x14) {
    iVar3 = *(int *)(param_1 + 0x3f8);
    uVar4 = 0xffffffff;
    uVar1 = 0x14;
    if (iVar3 != 0) {
      uVar1 = *(undefined4 *)(iVar3 + 0x1f8);
      uVar4 = *(undefined4 *)(iVar3 + 500);
    }
    if (*(int **)(param_1 + 0x3fc) != (int *)0x0) {
      uVar1 = (**(code **)(**(int **)(param_1 + 0x3fc) + 0x14))(param_1 + 0x2c,uVar1,uVar4);
      *unaff_ESI = uVar1;
      return;
    }
    puVar2 = (undefined4 *)FUN_00567160();
    if (puVar2 != (undefined4 *)0x0) {
      AIAction__AIAction(8,0,0xbf800000);
      *puVar2 = &PTR_FUN_006c920c;
      puVar2[0x80] = 0;
      puVar2[0x80] = 0;
      *param_2 = puVar2;
      return;
    }
    *param_2 = 0;
    return;
  }
  switch(param_3) {
  case 4:
    iVar3 = FUN_00567160();
    if (iVar3 != 0) {
      uVar1 = AIActionDraft__AIActionDraft(0xbf800000);
      *param_2 = uVar1;
      return;
    }
    break;
  default:
    iVar3 = FUN_00567160();
    if (iVar3 != 0) {
      uVar1 = AIActionPullOver__AIActionPullOver(0xbf800000,DAT_007006fc);
      *param_2 = uVar1;
      return;
    }
    goto LAB_00462704;
  case 7:
    iVar3 = FUN_00567160();
    if (iVar3 != 0) {
      uVar1 = AIActionJustDrive__AIActionJustDrive(0xbf800000);
      *param_2 = uVar1;
      return;
    }
    break;
  case 9:
    iVar3 = FUN_00567160();
    if (iVar3 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = AIActionPullOver__AIActionPullOver(0xbf800000,*(undefined4 *)(param_1 + 0x40c));
    }
    *param_2 = uVar1;
    *(undefined4 *)(param_1 + 0x40c) = 0x4b189680;
    return;
  case 10:
    iVar3 = FUN_00567160();
    if (iVar3 != 0) {
      uVar1 = AIActionGetUnstuck__AIActionGetUnstuck(0x40a00000,0xbf800000);
      *param_2 = uVar1;
      return;
    }
    goto LAB_00462704;
  case 0xe:
    iVar3 = FUN_00567160();
    if (iVar3 != 0) {
      uVar1 = AIActionAccidentRecovery__AIActionAccidentRecovery(0xbf800000);
      *param_2 = uVar1;
      return;
    }
LAB_00462704:
    *param_2 = 0;
    return;
  case 0x11:
    iVar3 = FUN_00567160();
    if (iVar3 != 0) {
      uVar1 = AIActionEndOfRace__AIActionEndOfRace(0xbf800000,*(undefined4 *)(param_1 + 4));
      *param_2 = uVar1;
      return;
    }
  }
  *param_2 = 0;
  return;
}


// ==== 0x462740 Racer::PersonalityDraw

/* [canon] rivals V (capstone) docs/re/rivals.md */

undefined4 __thiscall Racer__PersonalityDraw(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  float10 fVar5;
  
  fVar1 = (float)(DAT_0073ad34 - param_1[0x135]) * 0.00025;
  uVar3 = CONCAT22((short)((uint)(DAT_0073ad34 - param_1[0x135]) >> 0x10),
                   (ushort)(fVar1 < 1.0) << 8 | (ushort)NAN(fVar1) << 10 |
                   (ushort)(fVar1 == 1.0) << 0xe);
  if (fVar1 >= 1.0) {
    param_1[0x134] = 0;
  }
  if (param_2 != param_1[0x134]) {
    fVar5 = (float10)Random_NextFloat(0x3f800000);
    fVar1 = (float)fVar5;
    iVar4 = (**(code **)(*param_1 + 0x58))();
    if (iVar4 == -2) {
      iVar4 = 0;
    }
    fVar2 = (float)(&DAT_0077a004)[iVar4 * 0x15];
    uVar3 = CONCAT22((short)((uint)(iVar4 * 0x54) >> 0x10),
                     (ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                     (ushort)(fVar1 == fVar2) << 0xe);
    if (fVar1 < fVar2) {
      return CONCAT31((int3)((uint)uVar3 >> 8),1);
    }
    param_1[0x134] = param_2;
    param_1[0x135] = DAT_0073ad34;
  }
  return uVar3;
}


// ==== 0x4627e0 FUN_004627e0

void __thiscall
FUN_004627e0(int param_1,undefined4 *param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  
  *param_2 = 0;
  *param_3 = 99;
  if (*(int **)(param_1 + 0x3f8) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x3f8) + 0x14))();
    *param_4 = uVar1;
    return;
  }
  if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
    *param_4 = 0;
    return;
  }
  *param_4 = 1;
  return;
}


// ==== 0x462840 Racer::ShouldTakeFork

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] rivals I (capstone) docs/re/rivals.md */

bool __thiscall Racer__ShouldTakeFork(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  float10 fVar3;
  
  cVar1 = *(char *)(param_2 + 0xb);
  if (((cVar1 == '\b') && (*(int *)(*(int *)(param_1[1] + 0x14) + 4) == 1)) || (cVar1 == '\x02')) {
    return true;
  }
  if ((cVar1 == '\x05') || (cVar1 == '\a')) {
    return false;
  }
  if (cVar1 == '\t') {
    if (param_1[0x13b] == 0) {
      FUN_00462e60();
    }
    cVar1 = FUN_00454a20(param_1[1]);
    return (bool)('\x01' - (cVar1 != '\0'));
  }
  if (*(char *)(param_2 + 0xf) != '\0') {
    return false;
  }
  if (*(short *)(DAT_00736174 + 0xb8) == -1) {
    cVar1 = RaceManager__IsInRaceStartWindow(DAT_0073619c,param_1[1]);
    if (cVar1 != '\0') {
      return false;
    }
  }
  else if ((float)*(int *)(DAT_0073619c + 0x14) * 0.00025 <=
           (float)(int)*(short *)(DAT_00736174 + 0xb8)) {
    return false;
  }
  cVar1 = Msg_ReadOnOffByType(param_1);
  if (cVar1 == '\0') {
    if (*(char *)(param_2 + 0xb) == '\x04') {
      fVar3 = (float10)Random_NextFloat(0x3f800000);
      if (fVar3 < (float10)_K_HALF) {
        return true;
      }
    }
    else {
      iVar2 = (**(code **)(*param_1 + 0x58))();
      if (iVar2 < 1) {
        iVar2 = 0;
      }
      else if (9 < iVar2) {
        iVar2 = 9;
      }
      fVar3 = (float10)Random_NextFloat(0x3f800000);
      iVar2 = iVar2 * 0x54;
      if (fVar3 < (float10)*(float *)(&DAT_00779ff8 + iVar2) !=
          (fVar3 == (float10)*(float *)(&DAT_00779ff8 + iVar2))) {
        return *(char *)(param_2 + 0xb) == '\x01';
      }
      if ((fVar3 < (float10)*(float *)(iVar2 + 0x779ffc) !=
           (fVar3 == (float10)*(float *)(iVar2 + 0x779ffc))) ||
         (fVar3 < (float10)*(float *)(iVar2 + 0x77a000) ==
          (fVar3 == (float10)*(float *)(iVar2 + 0x77a000)))) {
        return *(char *)(param_2 + 0xb) == '\0';
      }
    }
  }
  return false;
}


// ==== 0x4629e0 FUN_004629e0

void __thiscall FUN_004629e0(int param_1,int param_2)

{
  if (*(char *)(param_2 + 8) == '\x02') {
    *(uint *)(param_1 + 0x478) = param_2 - DAT_00736150 >> 5 & 0xff;
  }
  return;
}


// ==== 0x462a00 FUN_00462a00

void __thiscall FUN_00462a00(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(char *)(param_2 + 8) == '\x01') {
    uVar1 = _ftol_nocw();
    *(undefined4 *)(param_1 + 0x47c) = uVar1;
  }
  if ((param_2 - DAT_00736150 >> 5 & 0xffU) == *(uint *)(param_1 + 0x478)) {
    *(undefined4 *)(param_1 + 0x478) = 0xffffffff;
  }
  return;
}


// ==== 0x462a60 FUN_00462a60

undefined4 FUN_00462a60(void)

{
  if (((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) &&
     ((DAT_0078a2f0 != 1099 || ((DAT_00735fb0 == 0 || (DAT_00735fb8 != 4)))))) {
    return 0;
  }
  return 1;
}


// ==== 0x462aa0 Racer::GetUnstuckReady

/* [canon] rivals I (capstone) docs/re/rivals.md */

undefined4 __fastcall Racer__GetUnstuckReady(int param_1)

{
  if (6.0 < (float)(DAT_0073ad34 - *(int *)(param_1 + 0x408)) * 0.00025) {
    return 1;
  }
  return 0;
}


// ==== 0x462ae0 FUN_00462ae0

float10 __fastcall FUN_00462ae0(int *param_1)

{
  int iVar1;
  float10 fVar2;
  
  fVar2 = (float10)(**(code **)(*param_1 + 0x28))();
  if ((((float10)0.0 < fVar2) &&
      (iVar1 = param_1[0x137], *(char *)(iVar1 + 6) == *(char *)(iVar1 + 5))) &&
     (*(float *)(iVar1 + 0xc) < 0.2)) {
    return (float10)1.6;
  }
  return (float10)1.3;
}


// ==== 0x462b30 FUN_00462b30

undefined1 __thiscall FUN_00462b30(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  bool bVar4;
  char cVar5;
  undefined1 uVar6;
  uint uVar7;
  int iVar8;
  int extraout_EDX;
  int iVar9;
  bool bVar10;
  float10 fVar11;
  float fStack_14;
  
  iVar8 = param_2[0xea];
  iVar2 = *param_2;
  uVar7 = (**(code **)(*param_1 + 0x58))();
  if (*(int *)(iVar2 + 0x28) == 4) {
    return 0;
  }
  if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
    fVar11 = (float10)TrackPathManager__ComparePercentDistances
                                (*(float *)(iVar2 + 0x810) * 100.0,
                                 *(undefined4 *)
                                  (DAT_0073619c + 0x540 + *(char *)(DAT_0073619c + 0x53e) * 4));
    if (fVar11 < (float10)0.0) {
      fVar11 = fVar11 + (float10)100.0;
    }
    iVar9 = (((int)uVar7 < 1) - 1 & uVar7) * 0x54;
    bVar10 = (int)*(char *)(extraout_EDX + 9) != DAT_0078a31c + -1;
    if ((bVar10) || ((float10)0.01 * fVar11 <= (float10)0.75)) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
    if ((((&DAT_0077a04a)[iVar9] != '\0') &&
        (fVar11 = (float10)FUN_00449f80(), fVar11 <= (float10)1.0)) && (!bVar4)) {
      return 0;
    }
    fVar3 = *(float *)(&DAT_0077a038 + iVar9);
    CarState__IsNitrousOn();
    cVar5 = CarState__IsNitrousOn();
    if ((cVar5 != '\0') && (fVar3 <= (float)(DAT_0073ad34 - param_1[0x138]) * 0.00025)) {
      return 0;
    }
    fStack_14 = *(float *)(&DAT_0077a02c + iVar9);
    if (!bVar10) {
      fStack_14 = *(float *)(&DAT_0077a030 + iVar9);
    }
    if (bVar4) {
      fStack_14 = 0.0;
    }
    cVar5 = CarState__IsNitrousOn();
    if ((cVar5 == '\0') && ((float)(DAT_0073ad34 - param_1[0x139]) * 0.00025 <= fStack_14)) {
      return 0;
    }
    iVar9 = param_2[0xe5];
    bVar10 = false;
    bVar4 = false;
    fVar11 = (float10)FUN_0059bab0();
    cVar5 = IsForwardsTrafficLane();
    if (cVar5 == '\0') {
      if (0.001 < (float)fVar11) {
        if (0.8 <= *(float *)(iVar2 + 0x3d4) / (float)fVar11) {
          bVar10 = false;
        }
        else {
          bVar10 = true;
        }
      }
    }
    else {
      bVar10 = true;
    }
    cVar5 = FUN_005a6ef0(iVar8,iVar9);
    piVar1 = param_1 + 0x13a;
    if (cVar5 == '\0') {
      *piVar1 = 0;
    }
    else {
      iVar8 = SpecialCamCooldown();
      if (iVar8 == 0) {
        *piVar1 = DAT_0073ad34;
      }
    }
    iVar8 = SpecialCamCooldown();
    if ((iVar8 != 0) && (bVar4 = true, (float)(DAT_0073ad34 - *piVar1) * 0.00025 <= 1.0)) {
      bVar4 = false;
    }
    if ((!bVar10) && (!bVar4)) {
      return 0;
    }
  }
  uVar6 = FUN_0044cac0(param_1);
  return uVar6;
}


// ==== 0x462df0 FUN_00462df0

undefined4 __fastcall FUN_00462df0(int *param_1)

{
  undefined4 in_EAX;
  uint uVar1;
  int iVar2;
  
  iVar2 = CONCAT31((int3)((uint)in_EAX >> 8),DAT_0078a344);
  if ((DAT_0078a344 == '\0') && (iVar2 = DAT_007361a8, DAT_007361a8 == 0)) {
    uVar1 = (**(code **)(*param_1 + 0x58))();
    if (*(float *)(&DAT_0077a034 + (uVar1 & ((int)uVar1 < 1) - 1) * 0x54) <
        (float)(DAT_0073ad34 - param_1[0x138]) * 0.00025) {
      return 1;
    }
    return 0;
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}


// ==== 0x462e60 FUN_00462e60

void FUN_00462e60(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int *unaff_EDI;
  float10 fVar5;
  
  iVar1 = *(int *)(in_EAX + 0x18);
  iVar2 = *(int *)(in_EAX + 0x1c);
  iVar3 = FUN_00577d10(*(undefined4 *)(in_EAX + 0x14));
  if (iVar3 != 0) {
    iVar4 = *(int *)(iVar3 + 0x2c);
    if (iVar4 == iVar3 + 0x2c) {
      iVar4 = FUN_00577e60(0);
    }
    else {
      if (iVar4 == 0) {
        return;
      }
      iVar4 = iVar4 + -4;
    }
    if ((iVar4 != 0) && (iVar3 = FUN_00647b70(), iVar3 == 4)) {
      *unaff_EDI = iVar4;
      fVar5 = (float10)FUN_0057a0e0((float)iVar1);
      unaff_EDI[1] = (int)(float)fVar5;
      unaff_EDI[2] = (int)(float)iVar1;
      unaff_EDI[3] = (int)(float)iVar2;
    }
  }
  return;
}


// ==== 0x462ee0 FUN_00462ee0

void FUN_00462ee0(void)

{
  int iVar1;
  undefined4 *in_EAX;
  char cVar2;
  int unaff_ESI;
  undefined4 local_4;
  
  FUN_00571ea0(0,"AnimationToAvoidInfo");
  local_4 = 0;
  if (*(char *)(unaff_ESI + 0x3c) != '\0') {
    local_4 = *in_EAX;
  }
  FUN_00571c20(unaff_ESI,&local_4,4,4,0);
  if (*(char *)(unaff_ESI + 0x3d) != '\0') {
    *in_EAX = local_4;
  }
  FUN_00571c20(unaff_ESI,in_EAX + 1,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 2,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 3,4,0xffffffff,0);
  iVar1 = *(char *)(unaff_ESI + 0x40) * 0x10 + 0x4c + unaff_ESI;
  *(int *)(iVar1 + 0xc) = *(int *)(unaff_ESI + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(unaff_ESI + 0x40) + -1;
  *(char *)(unaff_ESI + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(unaff_ESI + 0x44)) {
    *(undefined4 *)(unaff_ESI + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x462f90 FUN_00462f90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00462f90(float *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int *in_EAX;
  float *pfVar7;
  undefined *puVar8;
  float local_5c;
  float local_58;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  undefined1 auStack_44 [4];
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  undefined4 local_30;
  undefined4 local_2c;
  float local_28;
  undefined1 local_20 [28];
  
  if ((char)in_EAX[0xc] == '\0') {
    in_EAX[8] = 0;
    in_EAX[9] = 0;
    in_EAX[10] = 0;
    if (param_1 != (float *)0x0) {
      *param_1 = 0.0;
      return;
    }
  }
  else {
    iVar2 = in_EAX[1];
    local_54 = *(float *)(iVar2 + 0xa8);
    local_50 = 0;
    local_4c = 0;
    local_48 = 0.0;
    local_5c = SQRT(*(float *)(iVar2 + 0xa8) * *(float *)(iVar2 + 0xa8) +
                    *(float *)(iVar2 + 0xa4) * *(float *)(iVar2 + 0xa4) +
                    *(float *)(iVar2 + 0xa0) * *(float *)(iVar2 + 0xa0)) / (float)in_EAX[2];
    fVar4 = -((float)in_EAX[3] * *(float *)*in_EAX * local_5c *
             ((_K_ONE - (float)in_EAX[4]) * (_DAT_007000ec - _K_ONE) + _K_ONE));
    fVar1 = *(float *)(iVar2 + 0xa4);
    in_EAX[8] = (int)(fVar4 * *(float *)(iVar2 + 0xa0));
    in_EAX[9] = (int)(fVar1 * fVar4);
    in_EAX[10] = (int)(local_54 * fVar4);
    if (_K_HALF <= (float)in_EAX[5]) {
      local_48 = (_K_ONE - (float)in_EAX[4]) * _DAT_007000f0;
    }
    FUN_00584cd0();
    iVar2 = in_EAX[1];
    fVar1 = *(float *)(iVar2 + 0x58);
    if (fVar1 < 0.0) {
      fVar1 = 0.0;
    }
    if (_K_HALF <= (float)in_EAX[5]) {
      fVar1 = _K_ONE;
    }
    fVar5 = 0.0;
    fVar4 = 0.0;
    fVar6 = _K_ONE;
    if (0.0001 < local_5c) {
      fVar4 = _K_ONE / local_5c;
      fVar6 = fVar4 * *(float *)(iVar2 + 0xa0);
      fVar5 = *(float *)(iVar2 + 0xa4) * fVar4;
      fVar4 = *(float *)(iVar2 + 0xa8) * fVar4;
    }
    fVar4 = fVar6 * *(float *)(iVar2 + 0x30) +
            fVar5 * *(float *)(iVar2 + 0x34) + fVar4 * *(float *)(iVar2 + 0x38);
    if (fVar4 < 0.0) {
      fVar4 = 0.0;
    }
    fVar4 = fVar4 * fVar4 * fVar4 * fVar4;
    iVar3 = *in_EAX;
    if ((float)in_EAX[5] == 0.0) {
      local_58 = (*(float *)(iVar3 + 8) + *(float *)(iVar3 + 4)) * fVar4 * fVar1 * local_5c;
      local_54 = local_58 * 0.4;
      local_58 = local_58 * 0.41;
    }
    else {
      local_54 = fVar4 * *(float *)(iVar3 + 4) * fVar1 * local_5c;
      local_58 = fVar4 * *(float *)(iVar3 + 8) * fVar1 * local_5c;
    }
    local_38 = -local_54;
    local_28 = -local_58;
    local_40 = 0;
    local_3c = 0;
    local_30 = 0;
    local_2c = 0;
    D3DXVec3Transform(local_20,&local_40,iVar2 + 0x30);
    puVar8 = &DAT_00705f00;
    pfVar7 = &local_5c;
    D3DXVec3Transform(pfVar7,&DAT_00705f00,iVar2 + 0x30);
    FUN_00584cd0();
    iVar2 = in_EAX[1];
    D3DXVec3Transform(&stack0xffffff98,&local_48,iVar2 + 0x30);
    D3DXVec3Transform(auStack_44,&DAT_00705f10,iVar2 + 0x30);
    FUN_00584cd0();
    if (param_1 != (float *)0x0) {
      *param_1 = (float)pfVar7 + (float)puVar8;
    }
  }
  return;
}


// ==== 0x463260 FUN_00463260

undefined4 * __thiscall FUN_00463260(undefined4 param_1,undefined4 *param_2)

{
  float fVar1;
  byte bVar2;
  float fVar3;
  float *pfVar4;
  float fVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  void *pvVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 *extraout_EDX;
  int iVar12;
  undefined4 *puVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  undefined4 *local_24;
  int local_18;
  undefined4 *local_14;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  pcStack_c = FUN_00686538;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_2[1] = 0;
  local_8 = 0;
  *param_2 = &PTR_FUN_006c89dc;
  param_2[2] = param_1;
  *(undefined1 *)(param_2 + 0xd) = 0;
  param_2[9] = 0;
  param_2[8] = 0;
  param_2[7] = 0;
  param_2[4] = 0;
  param_2[3] = 0;
  puVar6 = _malloc(0x28);
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar6 + 1) = 4;
    *(undefined1 *)((int)puVar6 + 5) = 0x1e;
    *(undefined1 *)((int)puVar6 + 6) = 0;
    *(undefined1 *)((int)puVar6 + 7) = 0;
    *puVar6 = &PTR_FUN_006b9694;
    puVar6[2] = 0;
    puVar6[3] = 0;
    puVar6[4] = puVar6 + 5;
    puVar7 = _malloc(0x78);
    puVar6[4] = puVar7;
    for (iVar11 = 0x1e; iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
  }
  param_2[0xc] = puVar6;
  puVar6 = _malloc(0x2c);
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    *puVar6 = 0;
    *(undefined1 *)((int)puVar6 + 0x19) = 1;
    *(undefined2 *)(puVar6 + 7) = 0x14;
    pvVar8 = _malloc(0x170);
    puVar6[8] = pvVar8;
    puVar6[1] = 2;
    puVar6[2] = 0;
    puVar6[10] = &DAT_007376b0;
    puVar6[9] = (int)pvVar8 + 0x10;
    *(undefined1 *)((int)puVar6 + 0x1a) = 2;
    puVar6[5] = 0;
    *(undefined1 *)(puVar6 + 6) = 1;
    *(undefined2 *)((int)puVar6 + 0x1e) = 0;
    puVar6[3] = 0;
    puVar6[4] = 0;
    Spline__InitBasis();
  }
  param_2[5] = puVar6;
  puVar6 = _malloc(0x30);
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    *puVar6 = 0;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6[3] = 0;
    puVar6[9] = 0x3f800000;
    puVar6[10] = 0x3f800000;
    *(undefined2 *)(puVar6 + 0xb) = 0;
    *(undefined2 *)((int)puVar6 + 0x2e) = 1;
  }
  param_2[6] = puVar6;
  puVar6 = _malloc(0x60);
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    *puVar6 = 0;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6[3] = 0;
    puVar6[9] = 0x3f800000;
    puVar6[10] = 0x3f800000;
    *(undefined2 *)(puVar6 + 0xb) = 0;
    *(undefined2 *)((int)puVar6 + 0x2e) = 1;
    puVar6[0xc] = 0;
    puVar6[0xd] = 0;
    puVar6[0xe] = 0;
    puVar6[0xf] = 0;
    puVar6[0x15] = 0x3f800000;
    puVar6[0x16] = 0x3f800000;
    *(undefined2 *)(puVar6 + 0x17) = 0;
    *(undefined2 *)((int)puVar6 + 0x5e) = 1;
  }
  param_2[10] = puVar6;
  puVar6 = _malloc(0x60);
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    *puVar6 = 0;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6[3] = 0;
    puVar6[9] = 0x3f800000;
    puVar6[10] = 0x3f800000;
    *(undefined2 *)(puVar6 + 0xb) = 0;
    *(undefined2 *)((int)puVar6 + 0x2e) = 1;
    puVar6[0xc] = 0;
    puVar6[0xd] = 0;
    puVar6[0xe] = 0;
    puVar6[0xf] = 0;
    puVar6[0x15] = 0x3f800000;
    puVar6[0x16] = 0x3f800000;
    *(undefined2 *)(puVar6 + 0x17) = 0;
    *(undefined2 *)((int)puVar6 + 0x5e) = 1;
  }
  param_2[0xb] = puVar6;
  fVar3 = *(float *)(param_2[2] + 0x3d4);
  fVar5 = *(float *)(param_2[2] + 0xd8) * 0.4 * fVar3;
  fVar14 = (float10)FUN_00564b10();
  fVar15 = (float10)FUN_00564b10();
  fVar16 = (float10)FUN_00564b10();
  fVar1 = (float)(fVar16 * (float10)fVar5);
  fVar16 = (float10)FUN_00564b10();
  fVar16 = fVar16 * (float10)fVar5;
  pfVar4 = (float *)param_2[10];
  *pfVar4 = (float)(fVar14 * (float10)fVar3);
  if ((float)(fVar14 * (float10)fVar3) != pfVar4[2]) {
    *(undefined2 *)(pfVar4 + 0xb) = 2;
  }
  pfVar4[0xc] = (float)(fVar15 * (float10)fVar3);
  if ((float)(fVar15 * (float10)fVar3) != pfVar4[0xe]) {
    *(undefined2 *)(pfVar4 + 0x17) = 2;
  }
  iVar11 = param_2[10];
  *(float *)(iVar11 + 4) = fVar1;
  if (fVar1 != *(float *)(iVar11 + 0xc)) {
    *(undefined2 *)(iVar11 + 0x2c) = 2;
  }
  *(float *)(iVar11 + 0x34) = (float)fVar16;
  if (fVar16 != (float10)*(float *)(iVar11 + 0x3c)) {
    *(undefined2 *)(iVar11 + 0x5c) = 2;
  }
  iVar11 = param_2[0xb];
  *(undefined4 *)(iVar11 + 0x24) = 0x3e99999a;
  *(undefined4 *)(iVar11 + 0x54) = 0x3e99999a;
  iVar11 = *(int *)(param_2[2] + 0x20);
  local_24 = param_2 + 0xe;
  local_18 = iVar11 + 0x10;
  puVar6 = extraout_EDX;
  local_14 = extraout_EDX;
  do {
    iVar12 = DAT_00735f74;
    puVar7 = (undefined4 *)(DAT_00735f74 + 0x10);
    if ((*(undefined4 **)(DAT_00735f74 + 0x10) == puVar6) &&
       ((*(byte *)(DAT_00735f74 + 0x14) & 1) != 0)) {
      FUN_00566e60();
      puVar6 = (undefined4 *)0x0;
    }
    puVar13 = (undefined4 *)*puVar7;
    iVar9 = *(int *)(iVar12 + 0x18) + 1;
    if (puVar13 == puVar6) {
      uVar10 = 0;
    }
    else {
      uVar10 = *puVar13;
      if (*(int *)(iVar12 + 0x1c) < iVar9) {
        *(int *)(iVar12 + 0x1c) = iVar9;
      }
      *(int *)(iVar12 + 0x18) = iVar9;
      bVar2 = *(byte *)(iVar12 + 0x14);
      *puVar7 = uVar10;
      if (((bVar2 & 2) != 0) && (iVar12 = *(int *)(iVar12 + 0x28) >> 2, 0 < iVar12)) {
        for (; iVar12 != 0; iVar12 = iVar12 + -1) {
          *puVar13 = 0;
          puVar13 = puVar13 + 1;
        }
      }
      uVar10 = FUN_005868e0(local_18,((int)local_14 / 2) * 0x20 + 0xd0 + iVar11,iVar11 + 0x270);
      puVar6 = (undefined4 *)0x0;
    }
    *local_24 = uVar10;
    local_14 = (undefined4 *)((int)local_14 + 1);
    local_24 = local_24 + 1;
    local_18 = local_18 + 0x30;
  } while ((int)local_14 < 4);
  ExceptionList = local_10;
  return param_2;
}


// ==== 0x463610 FUN_00463610

void * __thiscall FUN_00463610(void *param_1,byte param_2)

{
  FUN_00463630(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x463630 FUN_00463630

void FUN_00463630(undefined4 *param_1)

{
  void *_Memory;
  int iVar1;
  int *piVar2;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685d78;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c89dc;
  local_4 = 0;
  FUN_00463e80();
  if ((undefined4 *)param_1[0xc] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xc])(1);
  }
  _Memory = (void *)param_1[5];
  if (_Memory != (void *)0x0) {
    if (*(char *)((int)_Memory + 0x19) != '\0') {
      _free(*(void **)((int)_Memory + 0x20));
    }
    _free(_Memory);
  }
  _free((void *)param_1[6]);
  _free((void *)param_1[10]);
  _free((void *)param_1[0xb]);
  piVar2 = param_1 + 0xe;
  iVar1 = 4;
  do {
    if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *param_1 = &PTR_PsychoDriverDerived__scalar_deleting_dtor_006caadc;
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4636f0 FUN_004636f0

void __thiscall FUN_004636f0(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  FUN_00571ea0(0,"BeltMover");
  FUN_00571c20(param_2,param_1 + 0x1c,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x20,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x24,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0xc,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x10,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x34,1,1,0);
  FUN_00571c20(param_2,*(undefined4 *)(param_1 + 0x18),0x30,0xffffffff,0);
  FUN_00571c20(param_2,*(undefined4 *)(param_1 + 0x28),0x60,0xffffffff,0);
  FUN_00571c20(param_2,*(undefined4 *)(param_1 + 0x2c),0x60,0xffffffff,0);
  FUN_0059ca70(*(undefined4 *)(param_1 + 0x14),3);
  FUN_005840c0(*(undefined4 *)(*(int *)(param_1 + 0x30) + 0x10));
  iVar2 = 4;
  do {
    FUN_005869c0();
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = *(char *)(param_2 + 0x40) * 0x10 + 0x4c + param_2;
  *(int *)(iVar2 + 0xc) = *(int *)(param_2 + 0x150) - *(int *)(iVar2 + 0xc);
  cVar1 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar1;
  if ((int)cVar1 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x463800 FUN_00463800

float10 FUN_00463800(undefined4 param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *unaff_ESI;
  float *unaff_EDI;
  float local_20;
  float local_1c;
  float local_18;
  
  FUN_0059d350(&local_20,param_3,0);
  *unaff_ESI = local_20;
  unaff_ESI[1] = local_1c;
  unaff_ESI[2] = local_18;
  FUN_0059d350(&local_20,param_3,1);
  *unaff_EDI = local_20;
  unaff_EDI[1] = local_1c;
  unaff_EDI[2] = local_18;
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  *unaff_ESI = *unaff_ESI - *param_2;
  fVar3 = unaff_ESI[1];
  unaff_ESI[1] = fVar3 - fVar1;
  fVar4 = unaff_ESI[2];
  unaff_ESI[2] = (float)((float10)fVar4 - (float10)fVar2);
  return (float10)*unaff_ESI * (float10)*unaff_EDI +
         ((float10)fVar4 - (float10)fVar2) * (float10)unaff_EDI[2] +
         (float10)(fVar3 - fVar1) * (float10)unaff_EDI[1];
}


// ==== 0x4638a0 FUN_004638a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_004638a0(int param_1)

{
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  
  if (*(short *)(*(int *)(param_1 + 0x14) + 0x1e) == 0) {
    return (float10)0.0;
  }
  FUN_0059d350(&local_20,*(undefined4 *)(param_1 + 0x1c),1);
  bNormalize3(local_20,local_1c);
  return -((float10)_DAT_007000ac * (float10)local_18);
}


// ==== 0x463910 FUN_00463910

void FUN_00463910(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  float *pfVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float10 fVar11;
  float10 fVar12;
  undefined8 uVar13;
  float local_30;
  float fStack_2c;
  float fStack_28;
  float local_20;
  float fStack_1c;
  float fStack_18;
  
  piVar4 = *(int **)(*(int *)(param_1 + 8) + 0x30);
  fVar1 = (float)piVar4[0x6f];
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(float *)(param_1 + 0x10) = (float)((char)piVar4[4] + -1) / fVar1;
  uVar13 = FUN_0059d430(0);
  fVar11 = (float10)FUN_0059d540((int)((ulonglong)uVar13 >> 0x20),(float)(int)uVar13,0x3ba3d70a,0);
  FUN_00463800(param_1,*(int *)(param_1 + 8) + 0x60,(float)fVar11);
  *(float *)(param_1 + 0x1c) = (float)fVar11;
  bNormalize3();
  fVar2 = *(float *)(*(int *)(param_1 + 8) + 0x3d0) * *(float *)(param_1 + 0x10);
  *(float *)(param_1 + 0x20) = fVar2;
  fVar11 = (float10)(**(code **)(*piVar4 + 0x70))();
  fVar1 = *(float *)(param_1 + 0x10);
  fVar12 = (float10)(**(code **)(*piVar4 + 0x74))();
  if (fVar12 <= (float10)0.0) {
    fVar12 = (float10)0.5;
  }
  else {
    fVar12 = (float10)(**(code **)(*piVar4 + 0x74))();
  }
  *(float *)(param_1 + 0x24) =
       (float)((float10)(float)(fVar11 * (float10)1.0 * (float10)fVar1 - (float10)fVar2) / fVar12);
  fVar11 = (float10)FUN_00456830(*(undefined4 *)(param_1 + 8),
                                 *(float *)(param_1 + 0x20) / *(float *)(param_1 + 0x10));
  fVar11 = fVar11 * (float10)*(float *)(param_1 + 0x10);
  if ((float10)*(float *)(param_1 + 0x24) <= fVar11) {
    fVar1 = *(float *)(param_1 + 0x10) * -20.0;
    if (*(float *)(param_1 + 0x24) < fVar1) {
      *(float *)(param_1 + 0x24) = fVar1;
    }
  }
  else {
    *(float *)(param_1 + 0x24) = (float)fVar11;
  }
  iVar5 = *(int *)(param_1 + 8);
  pfVar6 = *(float **)(param_1 + 0x18);
  fVar7 = fStack_2c - fStack_28 * 0.0;
  fVar8 = fStack_28 * 0.0 - local_30;
  fVar9 = local_30 * 0.0 - fStack_2c * 0.0;
  fVar10 = -(fVar7 * local_20 + fStack_1c * fVar8 + fStack_18 * fVar9);
  fVar1 = *(float *)(iVar5 + 0x78);
  fVar2 = *(float *)(iVar5 + 0x74);
  fVar3 = *(float *)(iVar5 + 0x70);
  *pfVar6 = fVar10;
  if (fVar10 != pfVar6[2]) {
    *(undefined2 *)(pfVar6 + 0xb) = 2;
  }
  iVar5 = *(int *)(param_1 + 0x18);
  fVar1 = (fVar7 * fVar3 + fVar8 * fVar2 + fVar9 * fVar1) * 0.5;
  *(float *)(iVar5 + 4) = fVar1;
  if (fVar1 != *(float *)(iVar5 + 0xc)) {
    *(undefined2 *)(iVar5 + 0x2c) = 2;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x24) = 0x3f000000;
  iVar5 = *(int *)(param_1 + 0x28);
  *(undefined4 *)(iVar5 + 0x24) = 0x3ecccccd;
  *(undefined4 *)(iVar5 + 0x54) = 0x3ecccccd;
  return;
}


// ==== 0x463b30 FUN_00463b30

void FUN_00463b30(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  char *pcVar7;
  int unaff_EDI;
  
  *(undefined2 *)(*(int *)(unaff_EDI + 0x18) + 0x2e) = 0;
  *(undefined2 *)(*(int *)(unaff_EDI + 0x18) + 0x2e) = 0;
  *(undefined2 *)(*(int *)(unaff_EDI + 0x18) + 0x2e) = 0;
  iVar3 = *(int *)(*(int *)(unaff_EDI + 8) + 0x30);
  pcVar7 = (char *)(iVar3 + 0x10);
  FUN_00459980(*(int *)(unaff_EDI + 8));
  FUN_0059cb20();
  iVar6 = 0;
  if ('\0' < *pcVar7) {
    puVar5 = (undefined4 *)(iVar3 + 0x28);
    do {
      iVar3 = *(int *)(unaff_EDI + 0x14);
      uVar1 = puVar5[-1];
      uVar2 = *puVar5;
      puVar4 = (undefined4 *)(*(int *)(iVar3 + 0x24) + (-0x18 - (int)pcVar7) + (int)puVar5);
      *puVar4 = puVar5[-2];
      puVar4[3] = 0;
      puVar4[1] = uVar1;
      iVar6 = iVar6 + 1;
      puVar5 = puVar5 + 4;
      puVar4[2] = uVar2;
      *(undefined1 *)(iVar3 + 0x18) = 1;
    } while (iVar6 < *pcVar7);
  }
  FUN_00463910(unaff_EDI);
  return;
}


// ==== 0x463bc0 FUN_00463bc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_00463bc0(undefined4 param_1,int param_2,float param_3)

{
  int iVar1;
  undefined *puVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined **ppuVar7;
  float10 fVar8;
  
  iVar1 = *(int *)(*(int *)(param_2 + 8) + 0x20);
  fVar5 = ABS(param_3);
  if (fVar5 <= _K_EPS_SPEED) {
    param_3 = 0.0;
  }
  else {
    param_3 = param_3 / fVar5;
  }
  fVar5 = (*(float *)(iVar1 + 0xd8) + *(float *)(iVar1 + 0xf8)) * _K_HALF *
          *(float *)(iVar1 + 0x110) * fVar5;
  if (*(char *)(param_2 + 0x34) == '\0') {
    fVar6 = *(float *)(iVar1 + 0xdc) + *(float *)(iVar1 + 0xfc);
  }
  else {
    fVar6 = *(float *)(iVar1 + 0xe0) + *(float *)(iVar1 + 0x100);
  }
  ppuVar7 = &PTR_DAT_00705ef0;
  fVar6 = (_DAT_007000ac * *(float *)(iVar1 + 0x110) +
          (*(float *)(param_2 + 0x20) / *(float *)(param_2 + 0x10)) *
          (*(float *)(iVar1 + 0x268) + *(float *)(iVar1 + 0x264)) * _K_HALF) * fVar6 * _K_HALF;
  if (*(char *)(param_2 + 0x34) == '\0') {
    ppuVar7 = &PTR_DAT_00705ee8;
  }
  puVar2 = *ppuVar7;
  *(float *)(puVar2 + 8) = (_K_ONE - 0.1) * fVar6;
  *(float *)(puVar2 + 0x10) = (_K_ONE + 0.1) * fVar6;
  *(float *)(puVar2 + 0x18) = fVar6 * 1.5;
  if ((bool)*(char *)(param_2 + 0x34) != fVar6 < fVar5) {
    iVar1 = *(int *)(param_2 + 0x2c);
    if (fVar5 <= fVar6) {
      *(undefined4 *)(iVar1 + 0x24) = 0x3e99999a;
      *(undefined4 *)(iVar1 + 0x54) = 0x3e99999a;
      iVar1 = *(int *)(param_2 + 0x2c);
      fVar3 = *(float *)(iVar1 + 4) * 1.6;
      fVar4 = *(float *)(iVar1 + 0x34) * 1.6;
      *(float *)(iVar1 + 4) = fVar3;
      if (fVar3 != *(float *)(iVar1 + 0xc)) {
        *(undefined2 *)(iVar1 + 0x2c) = 2;
      }
      *(float *)(iVar1 + 0x34) = fVar4;
      if (fVar4 != *(float *)(iVar1 + 0x3c)) {
        *(undefined2 *)(iVar1 + 0x5c) = 2;
      }
    }
    else {
      *(undefined4 *)(iVar1 + 0x24) = 0x3f800000;
      *(undefined4 *)(iVar1 + 0x54) = 0x3f800000;
    }
    *(bool *)(param_2 + 0x34) = fVar6 < fVar5;
  }
  fVar8 = (float10)LinearTable__Lookup11(ppuVar7,fVar5);
  return fVar8 * (float10)param_3;
}


// ==== 0x463d50 FUN_00463d50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00463d50(float param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int in_EAX;
  int local_4c;
  float local_48;
  float local_40;
  float local_28;
  float local_18;
  
  iVar1 = *(int *)(*(int *)(in_EAX + 8) + 0x20);
  fVar5 = ((*(float *)(in_EAX + 0x20) / *(float *)(in_EAX + 0x10)) *
           (*(float *)(iVar1 + 0x268) + *(float *)(iVar1 + 0x264)) * _K_HALF) /
          *(float *)(iVar1 + 0x110) + _DAT_007000ac;
  FUN_004645d0(*(undefined4 *)(in_EAX + 0xc));
  FUN_00464660(*(undefined4 *)(in_EAX + 0xc));
  local_48 = 0.0;
  local_40 = 0.0;
  local_4c = 1;
  do {
    fVar2 = (float)local_4c * param_1 * 0.1;
    fVar3 = fVar2 + *(float *)(in_EAX + 0xc);
    FUN_004645d0(fVar3);
    fVar4 = (((fVar2 - local_40) * -fVar5 + local_18) * (fVar2 - local_40) + local_28) - local_28;
    if (fVar4 <= 0.0) {
      FUN_00464660(fVar3);
      local_40 = fVar2;
    }
    else if (local_48 <= fVar4) {
      local_48 = fVar4;
    }
    local_4c = local_4c + 1;
  } while (local_4c < 10);
  return (float10)local_48;
}


// ==== 0x463e80 FUN_00463e80

void FUN_00463e80(void)

{
  int iVar1;
  float fVar2;
  int unaff_EDI;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  FUN_00464660(*(undefined4 *)(unaff_EDI + 0xc));
  fVar2 = (*(float *)(unaff_EDI + 0x24) * *(float *)(unaff_EDI + 0xc) + *(float *)(unaff_EDI + 0x20)
          ) / *(float *)(unaff_EDI + 0x10);
  FUN_005673e0(fVar2);
  iVar1 = *(int *)(unaff_EDI + 8);
  *(float *)(iVar1 + 0x70) = local_20;
  *(float *)(iVar1 + 0x74) = local_1c;
  *(float *)(iVar1 + 0x78) = local_18;
  *(undefined1 *)(iVar1 + 0x460) = 0;
  *(float *)(iVar1 + 0x3d0) = fVar2;
  *(float *)(iVar1 + 0x3d4) = SQRT(local_1c * local_1c + local_18 * local_18 + local_20 * local_20);
  return;
}


// ==== 0x463f20 FUN_00463f20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_00463f20(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined2 uVar10;
  undefined4 uVar11;
  float *pfVar12;
  float unaff_EDI;
  int iVar13;
  float10 fVar14;
  undefined4 uVar15;
  int *local_80;
  float *local_7c;
  short sStack_78;
  float *local_74;
  int local_70;
  float fStack_5c;
  float fStack_58;
  float local_50;
  float local_4c;
  float local_48;
  float fStack_34;
  float local_30;
  float local_2c;
  float local_28;
  float fStack_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  if (*(ushort *)(*(int *)(param_1 + 0x14) + 0x1e) < 2) {
    FUN_00463b30();
  }
  iVar13 = *(int *)(param_1 + 8);
  local_1c = *(undefined4 *)(iVar13 + 100);
  local_20 = *(undefined4 *)(iVar13 + 0x60);
  local_18 = *(undefined4 *)(iVar13 + 0x68);
  fVar14 = (float10)FUN_00463d50(0x3f000000);
  if ((float10)1.0 < fVar14) {
    uVar11 = _ftol_nocw();
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x2c) + 0x424) = uVar11;
  }
  fVar4 = param_2 + *(float *)(param_1 + 0xc);
  *(float *)(param_1 + 0xc) = fVar4;
  fVar7 = (fVar4 * *(float *)(param_1 + 0x24) + *(float *)(param_1 + 0x20)) /
          *(float *)(param_1 + 0x10);
  FUN_00464660(fVar4 + 0.5);
  pfVar12 = *(float **)(param_1 + 0x28);
  pfVar12[2] = local_50;
  if (local_50 != *pfVar12) {
    *(undefined2 *)(pfVar12 + 0xb) = 2;
  }
  pfVar12[0xe] = local_4c;
  if (local_4c != pfVar12[0xc]) {
    *(undefined2 *)(pfVar12 + 0x17) = 2;
  }
  FUN_00593ec0(param_2,0,0);
  FUN_00593ec0(param_2,0,0);
  fVar1 = *(float *)(param_1 + 0xc) + 0.3;
  fVar4 = **(float **)(param_1 + 0x28);
  fVar5 = (*(float **)(param_1 + 0x28))[0xc];
  FUN_00464660(fVar1);
  fVar2 = local_2c - local_28 * 0.0;
  fVar3 = local_28 * 0.0 - local_30;
  fVar8 = local_30 * 0.0;
  fVar9 = local_2c * 0.0;
  bNormalize3();
  FUN_004646d0(fVar1);
  FUN_00584270(local_2c * fVar3 + local_28 * (fVar8 - fVar9) + fVar2 * local_30);
  iVar6 = *(int *)(param_1 + 0x18);
  fVar14 = (float10)FUN_00463bc0(*(float *)(*(int *)(param_1 + 0x30) + 0xc) * 1.0 +
                                 (*(float *)(iVar6 + 0x14) + *(float *)(iVar6 + 0x14) +
                                 (*(float *)(iVar6 + 0x20) / *(float *)(iVar6 + 0x24)) *
                                 *(float *)(iVar6 + 0x10) * 6.0) * 0.0);
  pfVar12 = *(float **)(param_1 + 0x2c);
  local_2c = (float)fVar14 * 0.3 * fVar7;
  fVar2 = fVar2 * local_2c;
  local_2c = fVar3 * local_2c;
  pfVar12[2] = fVar2;
  if (fVar2 != *pfVar12) {
    *(undefined2 *)(pfVar12 + 0xb) = 2;
  }
  pfVar12[0xe] = local_2c;
  if (local_2c != pfVar12[0xc]) {
    *(undefined2 *)(pfVar12 + 0x17) = 2;
  }
  FUN_00593ec0(param_2,0,0);
  FUN_00593ec0(param_2,0,0);
  fVar4 = **(float **)(param_1 + 0x2c) + fVar4;
  fVar5 = (*(float **)(param_1 + 0x2c))[0xc] + fVar5;
  uVar10 = Atan2ToAngle16(fVar4,fVar5);
  *(undefined2 *)(iVar13 + 0x3b4) = uVar10;
  FUN_00464660(*(undefined4 *)(param_1 + 0xc));
  fVar1 = local_2c - local_28 * 0.0;
  fVar2 = local_28 * 0.0 - local_30;
  fVar3 = local_30 * 0.0 - local_2c * 0.0;
  bNormalize3();
  fVar8 = (float)fVar14 * -1.0;
  pfVar12 = *(float **)(param_1 + 0x18);
  pfVar12[2] = fVar8;
  if (fVar8 != *pfVar12) {
    *(undefined2 *)(pfVar12 + 0xb) = 2;
  }
  FUN_00593ec0(param_2,fVar7 * 0.0,fVar7 * 0.0);
  fVar7 = **(float **)(param_1 + 0x18);
  FUN_004645d0(*(undefined4 *)(param_1 + 0xc));
  *(float *)(iVar13 + 0x60) = fVar1 * fVar7 + fVar4;
  *(float *)(iVar13 + 0x68) = fVar3 * fVar7 + local_48;
  *(float *)(iVar13 + 100) = fVar2 * fVar7 + fVar5;
  FUN_004278d0();
  D3DXVec3Transform(&local_30,*(undefined4 *)(iVar13 + 0x40),iVar13 + 0x90);
  *(float *)(iVar13 + 0x58) = *(float *)(iVar13 + 0x68) - fStack_34;
  *(float *)(iVar13 + 0x50) = *(float *)(iVar13 + 0x60) - fVar2;
  *(float *)(iVar13 + 0x54) = *(float *)(iVar13 + 100) - fVar3;
  *(undefined4 *)(iVar13 + 0xd0) = 0;
  fVar4 = _K_ONE;
  *(undefined4 *)(iVar13 + 0xd4) = 0;
  fVar4 = fVar4 / param_2;
  *(float *)(iVar13 + 0xd8) =
       (float)(int)(short)(sStack_78 - SUB42(fVar7,0)) * 9.5873795e-05 * fVar4;
  iVar6 = *(int *)(param_1 + 8);
  fStack_5c = *(float *)(iVar6 + 0x60) - local_2c;
  fStack_58 = *(float *)(iVar6 + 100) - local_28;
  fStack_24 = *(float *)(iVar6 + 0x68) - fStack_24;
  if (ABS(param_2) < 0.0001 == (ABS(param_2) == 0.0001)) {
    fStack_5c = fStack_5c * fVar4;
    fStack_58 = fStack_58 * fVar4;
    fStack_24 = fVar4 * fStack_24;
  }
  else {
    FUN_005673e0(unaff_EDI);
  }
  *(float *)(iVar13 + 0x78) = fStack_24;
  *(float *)(iVar13 + 0x70) = fStack_5c;
  *(float *)(iVar13 + 0x74) = fStack_58;
  *(float *)(iVar13 + 0x3d0) = unaff_EDI;
  *(undefined1 *)(iVar13 + 0x460) = 0;
  local_80 = (int *)(param_1 + 0x38);
  local_74 = (float *)(iVar13 + 0x374);
  pfVar12 = (float *)(iVar13 + 0x300);
  local_70 = 4;
  *(float *)(iVar13 + 0x3d4) =
       SQRT(fStack_24 * fStack_24 + fStack_58 * fStack_58 + fStack_5c * fStack_5c);
  iVar13 = *(int *)(param_1 + 8);
  fVar7 = -(fStack_5c * *(float *)(iVar13 + 0xa0) +
           fStack_58 * *(float *)(iVar13 + 0xa4) + fStack_24 * *(float *)(iVar13 + 0xa8));
  local_7c = (float *)(*(int *)(iVar13 + 0x20) + 0x20);
  fVar4 = unaff_EDI -
          (fStack_5c * *(float *)(iVar13 + 0x90) +
          fStack_58 * *(float *)(iVar13 + 0x94) + fStack_24 * *(float *)(iVar13 + 0x98));
  do {
    fVar5 = *local_7c;
    fVar1 = pfVar12[-4];
    fVar2 = *(float *)(param_1 + 0xc);
    fVar3 = *pfVar12;
    uVar15 = 0;
    uVar11 = _ftol_nocw(0);
    FUN_00586bb0(fVar1 * fVar2 + fVar3,unaff_EDI / fVar5,uVar11,uVar15);
    *local_74 = fVar4;
    local_74[1] = fVar7;
    pfVar12[0x25] = 0.0;
    iVar13 = *local_80;
    if (1 < *(int *)(*(int *)(iVar13 + 0x14) + 0x18)) {
      *(float *)(iVar13 + 0x100) = fVar4;
      *(float *)(iVar13 + 0x104) = fVar7;
      *(float *)(iVar13 + 0x160) = fVar4;
      *(undefined1 *)(*local_80 + 0x154) = *(undefined1 *)(param_1 + 0x34);
    }
    local_80 = local_80 + 1;
    pfVar12 = pfVar12 + 1;
    local_7c = local_7c + 0xc;
    local_74 = local_74 + 2;
    local_70 = local_70 + -1;
  } while (local_70 != 0);
  iVar13 = *(int *)(param_1 + 8);
  if ((((*(int *)(*(int *)(iVar13 + 0x14) + 4) != 3) && (*(char *)(iVar13 + 0x8a8) == '\0')) &&
      (*(char *)(iVar13 + 0x4d0) != '\0')) &&
     (fVar14 = (float10)FUN_00421400(), fVar14 < (float10)200.0)) {
    iVar13 = 4;
    do {
      FUN_00587e90(param_2,*(undefined4 *)(param_1 + 8));
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
  }
  FUN_00427a30();
  return (float10)param_2;
}


// ==== 0x4645d0 FUN_004645d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004645d0(float param_1)

{
  float fVar1;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  
  fVar1 = (param_1 * *(float *)(unaff_EDI + 0x24) * _K_HALF + *(float *)(unaff_EDI + 0x20)) *
          param_1 + *(float *)(unaff_EDI + 0x1c);
  FUN_0059d350(&local_20,fVar1,0);
  unaff_ESI[2] = local_18;
  unaff_ESI[1] = local_1c;
  *unaff_ESI = local_20;
  if (0.0 <= fVar1) {
    return;
  }
  fVar1 = *(float *)(*(int *)(*(int *)(unaff_EDI + 0x14) + 0x24) + 8);
  if (local_18 < fVar1) {
    unaff_ESI[2] = fVar1;
    return;
  }
  return;
}


// ==== 0x464660 FUN_00464660

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00464660(float param_1)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  float *unaff_ESI;
  float local_20;
  float local_1c;
  float local_18;
  
  fVar1 = param_1 * *(float *)(in_EAX + 0x24);
  fVar2 = fVar1 + *(float *)(in_EAX + 0x20);
  FUN_0059d350(&local_20,
               (fVar1 * _K_HALF + *(float *)(in_EAX + 0x20)) * param_1 + *(float *)(in_EAX + 0x1c),1
              );
  *unaff_ESI = local_20 * fVar2;
  unaff_ESI[1] = local_1c * fVar2;
  unaff_ESI[2] = local_18 * fVar2;
  return;
}


// ==== 0x4646d0 FUN_004646d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004646d0(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int unaff_ESI;
  float *unaff_EDI;
  float local_20;
  float local_1c;
  float local_18;
  
  fVar1 = *(float *)(unaff_ESI + 0x24);
  fVar4 = param_1 * *(float *)(unaff_ESI + 0x24);
  fVar5 = (_K_HALF * fVar4 + *(float *)(unaff_ESI + 0x20)) * param_1 + *(float *)(unaff_ESI + 0x1c);
  fVar4 = fVar4 + *(float *)(unaff_ESI + 0x20);
  FUN_0059d350(&local_20,fVar5,1);
  fVar2 = local_20 * fVar1;
  fVar3 = local_1c * fVar1;
  fVar1 = local_18 * fVar1;
  FUN_0059d350(&local_20,fVar5,2);
  fVar4 = fVar4 * fVar4;
  *unaff_EDI = local_20 * fVar4 + fVar2;
  unaff_EDI[2] = local_18 * fVar4 + fVar1;
  unaff_EDI[1] = local_1c * fVar4 + fVar3;
  return;
}


// ==== 0x4647c0 Float9_Max_Off10

/* [canon] car med (ghidra-canon) docs/re/car.md */

float10 __fastcall Float9_Max_Off10(int param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)0.0;
  if (0.0 < *(float *)(param_1 + 0x10)) {
    fVar1 = (float10)*(float *)(param_1 + 0x10);
  }
  if (fVar1 < (float10)*(float *)(param_1 + 0x14)) {
    fVar1 = (float10)*(float *)(param_1 + 0x14);
  }
  if (fVar1 < (float10)*(float *)(param_1 + 0x18)) {
    fVar1 = (float10)*(float *)(param_1 + 0x18);
  }
  if (fVar1 < (float10)*(float *)(param_1 + 0x1c)) {
    fVar1 = (float10)*(float *)(param_1 + 0x1c);
  }
  if (fVar1 < (float10)*(float *)(param_1 + 0x20)) {
    fVar1 = (float10)*(float *)(param_1 + 0x20);
  }
  if (fVar1 < (float10)*(float *)(param_1 + 0x24)) {
    fVar1 = (float10)*(float *)(param_1 + 0x24);
  }
  if (fVar1 < (float10)*(float *)(param_1 + 0x28)) {
    fVar1 = (float10)*(float *)(param_1 + 0x28);
  }
  if (fVar1 < (float10)*(float *)(param_1 + 0x2c)) {
    fVar1 = (float10)*(float *)(param_1 + 0x2c);
  }
  if (fVar1 < (float10)*(float *)(param_1 + 0x30)) {
    fVar1 = (float10)*(float *)(param_1 + 0x30);
  }
  return fVar1;
}


// ==== 0x464860 FUN_00464860

void __fastcall FUN_00464860(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_EAX;
  
  in_EAX[0xec] = 0;
  in_EAX[0xed] = 0;
  in_EAX[0xee] = 0;
  in_EAX[0xef] = 0;
  in_EAX[1] = param_1;
  in_EAX[2] = param_2;
  *in_EAX = param_3;
  in_EAX[0xf0] = 0;
  in_EAX[0xde] = 0;
  in_EAX[0xdf] = 0;
  in_EAX[8] = 0;
  in_EAX[9] = 0;
  in_EAX[10] = 0;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  in_EAX[6] = 0;
  in_EAX[0xec] = 0;
  FUN_00464c80();
  return;
}


// ==== 0x4648c0 FUN_004648c0

void FUN_004648c0(void)

{
  int in_EAX;
  char cVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int local_4;
  
  FUN_00571ea0(0,"CarState");
  FUN_00571c20(in_EAX,unaff_ESI + 0x10,0xc,0xffffffff,0);
  if (*(char *)(in_EAX + 0x3d) != '\0' || *(char *)(in_EAX + 0x3c) != '\0') {
    *(uint *)(unaff_ESI + 0x20) = *(uint *)(unaff_ESI + 0x20) & 0xfffffff0;
  }
  FUN_00571c20(in_EAX,unaff_ESI + 0x20,0xc,0xffffffff,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x30,0xc,0xffffffff,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x40,0xc,0xffffffff,0);
  FUN_00571d90();
  FUN_00571c20(in_EAX,unaff_ESI + 0x90,0xc,0xffffffff,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0xa0,0xc,0xffffffff,0);
  local_4 = unaff_ESI + 0x334;
  iVar2 = 0;
  iVar3 = unaff_ESI + 0x2c0;
  do {
    FUN_00571c20(in_EAX,iVar3 + -0x10,4,0xffffffff,0);
    FUN_00571c20(in_EAX,iVar3,4,0xffffffff,0);
    FUN_00571c20(in_EAX,iVar3 + 0x10,4,0xffffffff,0);
    FUN_00571c20(in_EAX,iVar3 + 0x30,4,0xffffffff,0);
    FUN_00571c20(in_EAX,unaff_ESI + 0x310 + iVar2,1,1,1);
    FUN_00571c20(in_EAX,iVar3 + 0x54,1,4,1);
    FUN_00571c20(in_EAX,local_4,8,0xffffffff,0);
    FUN_00571c20(in_EAX,iVar3 + 0x94,4,0xffffffff,0);
    FUN_00571c20(in_EAX,iVar3 + 0x40,4,0xffffffff,0);
    FUN_00571c20(in_EAX,iVar3 + 0xa4,4,0xffffffff,0);
    if (*(char *)(in_EAX + 0x3d) != '\0' || *(char *)(in_EAX + 0x3c) != '\0') {
      *(undefined4 *)(iVar3 + 100) = 1;
    }
    iVar2 = iVar2 + 1;
    local_4 = local_4 + 8;
    iVar3 = iVar3 + 4;
  } while (iVar2 < 4);
  iVar3 = 0;
  FUN_00571c20(in_EAX,unaff_ESI + 0x374,2,2,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x376,2,2,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x378,4,0xffffffff,0);
  if (*(char *)(in_EAX + 0x3d) != '\0' || *(char *)(in_EAX + 0x3c) != '\0') {
    *(undefined4 *)(unaff_ESI + 0x380) = 0;
    *(undefined4 *)(unaff_ESI + 900) = 0;
    *(undefined4 *)(unaff_ESI + 0x388) = 0;
  }
  FUN_00571c20(in_EAX,unaff_ESI + 0x390,4,0xffffffff,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x394,4,0xffffffff,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x398,1,4,1);
  FUN_00571c20(in_EAX,unaff_ESI + 0x39c,4,0xffffffff,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x3a0,4,0xffffffff,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x3a8,1,4,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x3ac,4,0xffffffff,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x3b8,4,0xffffffff,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x3bc,4,0xffffffff,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x3c0,1,4,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x3c4,4,0xffffffff,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x3c8,4,4,1);
  FUN_00571c20(in_EAX,unaff_ESI + 0x3cc,4,0xffffffff,0);
  FUN_00571c20(in_EAX,unaff_ESI + 0x3d0,4,0xffffffff,0);
  if (*(char *)(in_EAX + 0x3d) != '\0' || *(char *)(in_EAX + 0x3c) != '\0') {
    *(undefined4 *)(unaff_ESI + 0x3e4) = 0;
    *(undefined4 *)(unaff_ESI + 1000) = 0;
    *(undefined4 *)(unaff_ESI + 0x3ec) = 0;
    *(undefined4 *)(unaff_ESI + 0x3f0) = 0;
    *(undefined4 *)(unaff_ESI + 0x3f8) = 0;
    *(undefined4 *)(unaff_ESI + 0x3fc) = 0;
    *(undefined4 *)(unaff_ESI + 0x400) = 0;
    *(undefined4 *)(unaff_ESI + 0x404) = 0;
    *(undefined4 *)(unaff_ESI + 0x40c) = 0;
    *(undefined4 *)(unaff_ESI + 0x410) = 0;
    *(undefined4 *)(unaff_ESI + 0x414) = 0;
    *(undefined4 *)(unaff_ESI + 0x418) = 0;
    *(undefined4 *)(unaff_ESI + 0x3e0) = 0x3f800000;
    *(undefined4 *)(unaff_ESI + 0x3f4) = 0x3f800000;
    *(undefined4 *)(unaff_ESI + 0x408) = 0x3f800000;
    *(undefined4 *)(unaff_ESI + 0x41c) = 0x3f800000;
    *(undefined4 *)(unaff_ESI + 0x38c) = 0;
    *(undefined1 *)(unaff_ESI + 0x420) = 0;
    *(int *)(unaff_ESI + 0x38c) = (int)*(char *)(unaff_ESI + 0x310);
    iVar2 = (int)*(char *)(unaff_ESI + 0x310) + (int)*(char *)(unaff_ESI + 0x311);
    *(int *)(unaff_ESI + 0x38c) = iVar2;
    iVar2 = iVar2 + *(char *)(unaff_ESI + 0x312);
    *(int *)(unaff_ESI + 0x38c) = iVar2;
    *(int *)(unaff_ESI + 0x38c) = *(char *)(unaff_ESI + 0x313) + iVar2;
    do {
      FUN_00465150(unaff_ESI);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
  }
  iVar3 = *(char *)(in_EAX + 0x40) * 0x10 + 0x4c + in_EAX;
  *(int *)(iVar3 + 0xc) = *(int *)(in_EAX + 0x150) - *(int *)(iVar3 + 0xc);
  cVar1 = *(char *)(in_EAX + 0x40) + -1;
  *(char *)(in_EAX + 0x40) = cVar1;
  if ((int)cVar1 < *(int *)(in_EAX + 0x44)) {
    *(undefined4 *)(in_EAX + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x464c80 FUN_00464c80

void FUN_00464c80(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *unaff_ESI;
  
  unaff_ESI[0xc] = 0;
  unaff_ESI[0xd] = 0;
  unaff_ESI[0xe] = 0;
  unaff_ESI[0x10] = 0;
  unaff_ESI[0x11] = 0;
  unaff_ESI[0x12] = 0;
  unaff_ESI[0x15] = 0;
  unaff_ESI[0x16] = 0;
  unaff_ESI[0x17] = 0;
  unaff_ESI[0x18] = 0;
  unaff_ESI[0x1a] = 0;
  unaff_ESI[0x1b] = 0;
  unaff_ESI[0x1c] = 0;
  unaff_ESI[0x1d] = 0;
  unaff_ESI[0x1f] = 0;
  unaff_ESI[0x20] = 0;
  unaff_ESI[0x21] = 0;
  unaff_ESI[0x22] = 0;
  unaff_ESI[0x14] = 0x3f800000;
  unaff_ESI[0x19] = 0x3f800000;
  unaff_ESI[0x1e] = 0x3f800000;
  unaff_ESI[0x23] = 0x3f800000;
  *(undefined2 *)(unaff_ESI + 0xdd) = 0;
  *(undefined2 *)((int)unaff_ESI + 0x376) = 0;
  unaff_ESI[0x24] = 0;
  unaff_ESI[0x25] = 0;
  unaff_ESI[0x26] = 0;
  unaff_ESI[0x28] = 0;
  unaff_ESI[0x29] = 0;
  unaff_ESI[0x2a] = 0;
  iVar3 = 0;
  piVar4 = unaff_ESI + 0xcd;
  piVar1 = unaff_ESI + 0xb0;
  do {
    piVar1[-4] = 0;
    *piVar1 = 0;
    piVar1[4] = 0;
    piVar1[8] = 0;
    piVar1[0xc] = 0;
    *(undefined1 *)((int)unaff_ESI + iVar3 + 0x310) = 1;
    piVar1[0x15] = 1;
    piVar1[0x19] = 1;
    *piVar4 = 0;
    piVar4[1] = 0;
    piVar1[0x25] = 0;
    piVar1[0x10] = 0;
    piVar1[0x29] = 0;
    iVar3 = iVar3 + 1;
    piVar1 = piVar1 + 1;
    piVar4 = piVar4 + 2;
  } while (iVar3 < 4);
  unaff_ESI[0xe3] = 4;
  iVar3 = 0;
  do {
    FUN_00465150(unaff_ESI);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  unaff_ESI[0xe0] = 0;
  unaff_ESI[0xe1] = 0;
  unaff_ESI[0xe2] = 0;
  unaff_ESI[0xe4] = 0;
  unaff_ESI[0xe5] = 0;
  unaff_ESI[0xe6] = 1;
  unaff_ESI[0xe7] = 0;
  unaff_ESI[0xe8] = 0x447a0000;
  unaff_ESI[0xe9] = -0x40800000;
  unaff_ESI[0xea] = 1;
  if (((unaff_ESI[0xec] == 0) || (unaff_ESI[0xec] == 0x7fffffff)) ||
     ((float)unaff_ESI[0xec] * 0.00025 == 0.0)) {
    iVar3 = *unaff_ESI;
    iVar2 = _ftol_nocw();
    unaff_ESI[0xec] = iVar2;
    iVar2 = _ftol_nocw();
    unaff_ESI[0xee] = iVar2;
    if (*(int *)(iVar3 + 0x2a4) < 1) {
      unaff_ESI[0xed] = 0;
    }
    else {
      iVar3 = _ftol_nocw();
      unaff_ESI[0xed] = iVar3;
    }
    unaff_ESI[0xef] = 0;
  }
  unaff_ESI[0xf1] = 0x3f800000;
  unaff_ESI[0xf2] = 0;
  unaff_ESI[0xf3] = 0;
  unaff_ESI[0xf4] = 0x3f800000;
  piVar4 = unaff_ESI + 0xf8;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  *(undefined1 *)(unaff_ESI + 0x108) = 0;
  return;
}


// ==== 0x464ea0 FUN_00464ea0

float10 FUN_00464ea0(void)

{
  int in_EAX;
  float10 fVar1;
  
  if (*(float *)(in_EAX + 0x390) < 1.0) {
    return (float10)0.0;
  }
  fVar1 = (float10)CarState__GetYaw();
  return fVar1;
}


// ==== 0x464ed0 CarState::GetYaw

/* [canon] car med (ghidra-canon+nfsug) docs/re/car.md */

float10 __fastcall CarState__GetYaw(undefined4 param_1)

{
  short sVar1;
  int unaff_ESI;
  float10 fVar2;
  
  sVar1 = Atan2ToAngle16(*(undefined4 *)(unaff_ESI + 0x30),*(undefined4 *)(unaff_ESI + 0x34),param_1
                        );
  fVar2 = (float10)(ushort)(*(short *)(unaff_ESI + 0x374) - sVar1) * (float10)9.58738e-05;
  if ((float10)3.14159 < fVar2) {
    fVar2 = fVar2 - (float10)6.28318;
  }
  return fVar2;
}


// ==== 0x464f20 FUN_00464f20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00464f20(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *extraout_EDX;
  int unaff_EDI;
  float10 fVar5;
  float10 fVar6;
  
  if (*(char *)(unaff_EDI + 0x420) == '\0') {
    fVar1 = *(float *)(unaff_EDI + 0x30);
    fVar2 = *(float *)(unaff_EDI + 0x34);
    fVar3 = *(float *)(unaff_EDI + 0x38);
    if (*(float *)(unaff_EDI + 0x390) < 0.0) {
      fVar1 = -fVar1;
      fVar2 = -fVar2;
      fVar3 = -fVar3;
    }
    *(float *)(unaff_EDI + 0x3e0) = 1.0;
    *(undefined4 *)(unaff_EDI + 0x3e4) = 0;
    *(undefined4 *)(unaff_EDI + 1000) = 0;
    *(undefined4 *)(unaff_EDI + 0x3ec) = 0;
    *(undefined4 *)(unaff_EDI + 0x3f0) = 0;
    *(undefined4 *)(unaff_EDI + 0x3f4) = 0x3f800000;
    *(undefined4 *)(unaff_EDI + 0x3f8) = 0;
    *(undefined4 *)(unaff_EDI + 0x3fc) = 0;
    *(undefined4 *)(unaff_EDI + 0x400) = 0;
    *(undefined4 *)(unaff_EDI + 0x404) = 0;
    *(undefined4 *)(unaff_EDI + 0x408) = 0x3f800000;
    *(undefined4 *)(unaff_EDI + 0x40c) = 0;
    fVar4 = _K_ONE;
    *(undefined4 *)(unaff_EDI + 0x410) = 0;
    *(undefined4 *)(unaff_EDI + 0x414) = 0;
    *(undefined4 *)(unaff_EDI + 0x418) = 0;
    *(undefined4 *)(unaff_EDI + 0x41c) = 0x3f800000;
    if (fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3 <= fVar4) {
      fVar5 = (float10)FUN_00564b10();
      fVar6 = (float10)FUN_00564b10();
      extraout_EDX[2] = 0.0;
      extraout_EDX[3] = 0.0;
      *extraout_EDX = (float)fVar6;
      extraout_EDX[1] = -(float)fVar5;
      *(float *)(unaff_EDI + 0x3f0) = (float)fVar5;
      *(undefined4 *)(unaff_EDI + 0x3f8) = 0;
      *(float *)(unaff_EDI + 0x3f4) = (float)fVar6;
      *(undefined4 *)(unaff_EDI + 0x3fc) = 0;
      *(undefined4 *)(unaff_EDI + 0x400) = 0;
      *(undefined4 *)(unaff_EDI + 0x404) = 0;
      *(undefined4 *)(unaff_EDI + 0x408) = 0x3f800000;
      *(undefined4 *)(unaff_EDI + 0x40c) = 0;
      *(undefined4 *)(unaff_EDI + 0x41c) = 0x3f800000;
    }
    else {
      *(undefined4 *)(unaff_EDI + 1000) = 0;
      *(undefined4 *)(unaff_EDI + 0x3ec) = 0;
      *(float *)(unaff_EDI + 0x3e0) = fVar2;
      *(float *)(unaff_EDI + 0x3e4) = -fVar1;
      *(float *)(unaff_EDI + 0x3f4) = fVar2;
      *(undefined4 *)(unaff_EDI + 0x3f8) = 0;
      *(float *)(unaff_EDI + 0x3f0) = fVar1;
      *(undefined4 *)(unaff_EDI + 0x3fc) = 0;
      *(undefined4 *)(unaff_EDI + 0x400) = 0;
      *(undefined4 *)(unaff_EDI + 0x404) = 0;
      *(undefined4 *)(unaff_EDI + 0x408) = 0x3f800000;
      *(undefined4 *)(unaff_EDI + 0x40c) = 0;
      *(undefined4 *)(unaff_EDI + 0x41c) = 0x3f800000;
    }
    *(undefined4 *)(unaff_EDI + 0x418) = 0;
    *(undefined4 *)(unaff_EDI + 0x414) = 0;
    *(undefined4 *)(unaff_EDI + 0x410) = 0;
    eOrthonormalizeMatrix();
    *(undefined1 *)(unaff_EDI + 0x420) = 1;
  }
  return unaff_EDI + 0x3e0;
}


// ==== 0x4650d0 FUN_004650d0

void FUN_004650d0(undefined4 *param_1)

{
  int in_EAX;
  undefined4 unaff_EBX;
  float *unaff_ESI;
  undefined4 uStack_68;
  float local_60;
  float local_5c;
  undefined4 local_58;
  undefined1 local_50 [76];
  
  FUN_00464f20();
  bMatrixCopy();
  local_60 = *unaff_ESI - *(float *)(in_EAX + 0x20);
  local_58 = 0;
  local_5c = unaff_ESI[1] - *(float *)(in_EAX + 0x24);
  bMatrixCopy();
  D3DXVec3Transform(&local_60,&local_60,local_50);
  *param_1 = unaff_EBX;
  param_1[1] = uStack_68;
  return;
}


// ==== 0x465150 FUN_00465150

void FUN_00465150(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
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
  undefined4 local_a0;
  undefined4 local_9c;
  float local_98;
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
  undefined4 local_5c;
  float local_58;
  undefined4 local_54;
  undefined1 local_50 [76];
  
  local_d0 = 0x3f800000;
  local_cc = 0;
  local_c8 = 0;
  local_c4 = 0;
  local_c0 = 0;
  local_bc = 0x3f800000;
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0x3f800000;
  local_a4 = 0;
  local_a0 = 0;
  local_9c = 0;
  local_98 = 0.0;
  local_94 = 0x3f800000;
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
  local_60 = 0;
  local_5c = 0;
  local_58 = 0.0;
  local_54 = 0x3f800000;
  _ftol_nocw();
  FUN_0040ba40(&local_d0,&local_d0);
  if (in_EAX < 2) {
    FUN_0040b930();
    D3DXMatrixMultiply(&local_d0,&local_d0,local_50);
    FUN_0040b930();
    D3DXMatrixMultiply(&local_9c,&local_9c,&local_5c);
  }
  iVar2 = *param_1;
  iVar3 = in_EAX * 0x30;
  local_5c = *(undefined4 *)(iVar3 + 0x14 + iVar2);
  puVar1 = (undefined4 *)(iVar3 + 0x10 + iVar2);
  local_60 = *puVar1;
  local_54 = 0x3f800000;
  local_9c = puVar1[1];
  local_a0 = *puVar1;
  local_58 = *(float *)(iVar3 + 0x18 + iVar2) + (float)param_1[in_EAX + 0xc0];
  local_94 = 0x3f800000;
  local_98 = (float)puVar1[2] + (float)param_1[in_EAX + 0xc0];
  bMatrixCopy_b();
  bMatrixCopy_b();
  return;
}


// ==== 0x465390 FUN_00465390

void FUN_00465390(void)

{
  float fVar1;
  float *unaff_ESI;
  undefined1 local_20 [28];
  
  fVar1 = *unaff_ESI;
  D3DXVec3Transform();
  unaff_ESI[4] = unaff_ESI[8] - (float)local_20;
  unaff_ESI[6] = unaff_ESI[10] - (float)(unaff_ESI + 0x14);
  unaff_ESI[5] = unaff_ESI[9] - fVar1;
  return;
}


// ==== 0x4653e0 Vec3_TransformSub

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

void Vec3_TransformSub(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *unaff_ESI;
  float *unaff_EDI;
  undefined1 local_20 [28];
  
  fVar3 = *unaff_ESI;
  D3DXVec3Transform();
  fVar1 = unaff_EDI[1];
  fVar2 = unaff_EDI[2];
  unaff_ESI[4] = *unaff_EDI - (float)local_20;
  unaff_ESI[6] = fVar2 - (float)(unaff_ESI + 0x14);
  unaff_ESI[5] = fVar1 - fVar3;
  return;
}


// ==== 0x465430 CarState::IsNitrousOn

/* [canon] runtime high (ghidra-canon+nfsug) docs/re/runtime.md */

uint CarState__IsNitrousOn(void)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  int iVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(in_EAX + 0x3bc);
  if ((uVar4 != 0) && (uVar4 != 0x7fffffff)) {
    iVar3 = DAT_0073ad34 - *(int *)(in_EAX + 0x3bc);
    fVar1 = (float)iVar3 * 0.00025;
    fVar2 = (float)*(int *)(in_EAX + 0x3b8) * 0.00025;
    if (fVar2 >= fVar1) {
      return CONCAT31((int3)(CONCAT22((short)((uint)iVar3 >> 0x10),
                                      (ushort)(fVar2 < fVar1) << 8 |
                                      (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                                      (ushort)(fVar2 == fVar1) << 0xe) >> 8),1);
    }
    uVar4 = CarState__StopNitrous();
  }
  return uVar4 & 0xffffff00;
}


// ==== 0x465490 FUN_00465490

uint __fastcall FUN_00465490(int param_1)

{
  float fVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x3b8);
  if ((uVar2 != 0) && (uVar2 != 0x7fffffff)) {
    fVar1 = (float)*(int *)(param_1 + 0x3b8) * 0.00025;
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),
                     (ushort)(fVar1 < 0.0) << 8 | (ushort)NAN(fVar1) << 10 |
                     (ushort)(fVar1 == 0.0) << 0xe);
    if (fVar1 >= 0.0 && (fVar1 == 0.0) == 0) {
      if ((*(int *)(param_1 + 0x3bc) != 0) && (*(int *)(param_1 + 0x3bc) != 0x7fffffff)) {
        return 0;
      }
      return 1;
    }
  }
  return uVar2 & 0xffffff00;
}


// ==== 0x4654f0 FUN_004654f0

void FUN_004654f0(void)

{
  char cVar1;
  int extraout_EDX;
  
  cVar1 = FUN_00465490();
  if (cVar1 != '\0') {
    *(undefined4 *)(extraout_EDX + 0x3bc) = DAT_0073ad34;
    if (DAT_007000e8 != 0) {
      *(undefined4 *)(extraout_EDX + 0x3b4) = *(undefined4 *)(extraout_EDX + 0x3b8);
      return;
    }
    *(int *)(extraout_EDX + 0x3b8) = *(int *)(extraout_EDX + 0x3b8) - *(int *)(extraout_EDX + 0x3b4)
    ;
  }
  return;
}


// ==== 0x465530 CarState::StopNitrous

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

void CarState__StopNitrous(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  if ((*(int *)(unaff_ESI + 0x3bc) != 0) && (*(int *)(unaff_ESI + 0x3bc) != 0x7fffffff)) {
    uVar1 = _ftol_nocw();
    *(undefined4 *)(unaff_ESI + 0x3b8) = uVar1;
    *(undefined4 *)(unaff_ESI + 0x3b4) = 0;
    *(undefined4 *)(unaff_ESI + 0x3bc) = 0;
  }
  return;
}


// ==== 0x4655b0 FUN_004655b0

void FUN_004655b0(void)

{
  undefined4 *unaff_ESI;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  bNormalize3();
  *unaff_ESI = local_20;
  unaff_ESI[1] = local_1c;
  unaff_ESI[2] = local_18;
  return;
}


// ==== 0x4655e0 FUN_004655e0

int FUN_004655e0(void)

{
  int in_EAX;
  
  return in_EAX + 0x554;
}


// ==== 0x4655f0 FUN_004655f0

void FUN_004655f0(void)

{
  undefined4 *puVar1;
  
  DAT_00736088 = (undefined4 *)FUN_00566dc0(0x80,"CollisionSlotPool",0);
  if (DAT_00736088 == (undefined4 *)0x0) {
    return;
  }
  if (DAT_0073d814 == 1) {
    *DAT_0073d81c = DAT_00736088;
    puVar1 = DAT_00736088;
    DAT_00736088[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_00736088 = &DAT_0073d818;
  }
  return;
}


// ==== 0x465640 FUN_00465640

void __fastcall FUN_00465640(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int *unaff_ESI;
  bool bVar5;
  
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[0x14] = 0;
  unaff_ESI[0x15] = 0;
  unaff_ESI[0x16] = 0;
  unaff_ESI[0x19] = in_EAX;
  iVar4 = DAT_007361f8;
  iVar3 = DAT_007361f8 + 0x10;
  unaff_ESI[0x18] = 0;
  puVar1 = *(undefined4 **)(iVar4 + 0x14);
  *puVar1 = unaff_ESI;
  *(int **)(iVar4 + 0x14) = unaff_ESI;
  unaff_ESI[1] = (int)puVar1;
  *unaff_ESI = iVar3;
  if (param_2 == (int *)0x0) {
    unaff_ESI[8] = 0;
    unaff_ESI[9] = 0;
    unaff_ESI[10] = 0;
  }
  else {
    iVar3 = *param_2;
    iVar4 = param_2[2];
    bVar5 = DAT_006f1dd8 != 0;
    unaff_ESI[9] = param_2[1];
    unaff_ESI[8] = iVar3;
    unaff_ESI[10] = iVar4;
    if (bVar5) {
      EAXCollision__CreatCollisionSample(unaff_ESI);
    }
  }
  iVar4 = DAT_0073ad34;
  unaff_ESI[2] = DAT_0073ad34;
  unaff_ESI[3] = iVar4;
  unaff_ESI[4] = 0;
  *(undefined1 *)(unaff_ESI + 0x1a) = 0;
  unaff_ESI[0x1c] = 0;
  unaff_ESI[0x1d] = 0;
  unaff_ESI[0x1e] = 0;
  cVar2 = Collision__IsWallInvolved();
  if (cVar2 != '\0') {
    iVar4 = *(int *)(unaff_ESI[0x19] + 600);
    if (*(char *)(iVar4 + 0x15) == '\x03') {
      iVar4 = *(int *)(unaff_ESI[0x19] + 0x25c);
    }
    if (iVar4 != 0) {
      *(int *)(iVar4 + 0x130) = *(int *)(iVar4 + 0x130) + 1;
    }
  }
  return;
}


// ==== 0x465700 FUN_00465700

void FUN_00465700(void)

{
  int *piVar1;
  char cVar2;
  int *in_EAX;
  uint uVar3;
  int iVar4;
  
  iVar4 = *in_EAX;
  piVar1 = (int *)in_EAX[1];
  *piVar1 = iVar4;
  *(int **)(iVar4 + 4) = piVar1;
  if (DAT_006f1dd8 != 0) {
    EAXCollision__ReleaseCollisionSample();
  }
  cVar2 = Collision__IsWallInvolved();
  if (cVar2 != '\0') {
    iVar4 = *(int *)(in_EAX[0x19] + 600);
    if (*(char *)(iVar4 + 0x15) == '\x03') {
      iVar4 = *(int *)(in_EAX[0x19] + 0x25c);
    }
    if (iVar4 != 0) {
      uVar3 = *(int *)(iVar4 + 0x130) - 1;
      *(uint *)(iVar4 + 0x130) = uVar3 & ((int)uVar3 < 0) - 1;
    }
  }
  return;
}


// ==== 0x465770 FUN_00465770

void FUN_00465770(void)

{
  int in_EAX;
  int iVar1;
  char cVar2;
  int unaff_ESI;
  
  FUN_00571ea0(in_EAX,"Collision");
  FUN_00571c20(unaff_ESI,in_EAX + 8,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0xc,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x20,0xc,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x30,0xc,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x50,0xc,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x60,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x10,4,4,0);
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


// ==== 0x465830 FUN_00465830

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00465830(int param_1,undefined4 *param_2,float *param_3,float param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float fVar8;
  float fVar9;
  float local_34;
  int *piStack_30;
  int iStack_2c;
  float local_28;
  float local_24;
  int iStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  fVar9 = param_3[1];
  fVar8 = param_3[2];
  *(float *)(param_1 + 0x50) = *param_3 + *(float *)(param_1 + 0x50);
  *(float *)(param_1 + 0x54) = fVar9 + *(float *)(param_1 + 0x54);
  *(float *)(param_1 + 0x58) = fVar8 + *(float *)(param_1 + 0x58);
  fVar9 = SQRT(param_3[1] * param_3[1] + param_3[2] * param_3[2] + *param_3 * *param_3);
  *(float *)(param_1 + 0x60) = fVar9 + *(float *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0xc) = DAT_0073ad34;
  uVar1 = param_2[2];
  uVar2 = *param_2;
  *(undefined4 *)(param_1 + 0x34) = param_2[1];
  *(undefined4 *)(param_1 + 0x30) = uVar2;
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  *(float *)(param_1 + 0x40) = param_4;
  SpecialCamCaller_465d00(param_1,param_2,param_3);
  fVar7 = (float10)FUN_004212f0();
  if (fVar7 < (float10)50.0) {
    iVar4 = Collision__GetTerrainType();
    iVar5 = iVar4 * 0x94;
    if (*(float *)(&DAT_006ef35c + iVar5) < param_4) {
      if ((ABS(*(float *)(&DAT_006ef360 + iVar5) - *(float *)(&DAT_006ef35c + iVar5)) <=
           _K_EPS_SPEED) ||
         (local_28 = (param_4 - *(float *)(&DAT_006ef35c + iVar5)) /
                     (*(float *)(&DAT_006ef360 + iVar5) - *(float *)(&DAT_006ef35c + iVar5)),
         local_28 <= 0.0)) {
        local_28 = 0.0;
      }
      else if (_K_ONE < local_28) {
        local_28 = 1.0;
      }
      (**(code **)(**(int **)(*(int *)(param_1 + 100) + 600) + 0xc))();
      (**(code **)(**(int **)(*(int *)(param_1 + 100) + 0x25c) + 0xc))();
      FUN_00598260(iVar4,local_28);
    }
    if (*(float *)(&DAT_006ef350 + iVar5) < fVar9) {
      local_24 = (fVar9 - *(float *)(&DAT_006ef350 + iVar5)) /
                 (*(float *)(&DAT_006ef354 + iVar5) - *(float *)(&DAT_006ef350 + iVar5));
      if (local_24 <= 0.0) {
        local_24 = 0.0;
      }
      else if (_K_ONE < local_24) {
        local_24 = 1.0;
      }
      iStack_20 = 0;
      uStack_1c = 0;
      uStack_18 = 0;
      FUN_00598260(iVar4,local_24);
    }
    bNormalize3();
    fVar7 = (float10)FUN_00421400();
    if (((fVar7 < (float10)100.0) && (DAT_006f1dd8 != 0)) &&
       (EAXCollision__StartCollisionSample(), DAT_006f1dd8 != 0)) {
      EAXCollision__PlayScrape();
    }
  }
  cVar3 = Collision__IsPlayerInvolved();
  if (cVar3 != '\0') {
    iVar4 = *(int *)(*(int *)(param_1 + 100) + 600);
    iStack_20 = 0;
    uStack_1c = 0;
    if (*(char *)(iVar4 + 0x15) == '\0') {
      iStack_20 = *(int *)(iVar4 + 0x140);
    }
    iVar4 = *(int *)(*(int *)(param_1 + 100) + 0x25c);
    if (*(char *)(iVar4 + 0x15) == '\0') {
      uStack_1c = *(undefined4 *)(iVar4 + 0x140);
    }
    piStack_30 = &iStack_20;
    iStack_2c = 2;
    do {
      iVar4 = *piStack_30;
      if ((iVar4 != 0) && (iVar5 = *(int *)(iVar4 + 0x18), iVar5 != 0)) {
        FUN_0043fbb0(param_1);
        fVar8 = *(float *)(*(int *)(iVar4 + 0x20) + 0x110);
        local_34 = _K_ONE;
        if (1.3 < fVar8) {
          local_34 = 1.3 / fVar8;
        }
        local_34 = SQRT(param_3[1] * param_3[1] + param_3[2] * param_3[2] + *param_3 * *param_3) *
                   local_34;
        if (iStack_2c == 2) {
          cVar3 = *(char *)(*(int *)(*(int *)(param_1 + 100) + 0x25c) + 0x15);
        }
        else {
          cVar3 = *(char *)(*(int *)(*(int *)(param_1 + 100) + 600) + 0x15);
        }
        if (cVar3 == '\x01') {
          local_34 = local_34 * 10.0;
        }
        if (((DAT_007361f0 != (int *)0x0) && (iVar4 = *DAT_007361f0, iVar4 != 5)) &&
           ((iVar4 != 6 && (((iVar4 != 10 && (iVar4 != 9)) && (*(char *)(iVar5 + 0x21) != '\0'))))))
        {
          FUN_00574d90(local_34);
        }
      }
      piStack_30 = piStack_30 + 1;
      iStack_2c = iStack_2c + -1;
    } while (0 < iStack_2c);
  }
  iVar4 = *(int *)(*(int *)(param_1 + 100) + 600);
  iVar5 = 0;
  iVar6 = 0;
  if (*(char *)(iVar4 + 0x15) == '\0') {
    iVar5 = *(int *)(iVar4 + 0x140);
  }
  iVar4 = *(int *)(*(int *)(param_1 + 100) + 0x25c);
  if (*(char *)(iVar4 + 0x15) == '\0') {
    iVar6 = *(int *)(iVar4 + 0x140);
  }
  if ((iVar5 != 0) && (*(char *)(*(int *)(iVar5 + 0x14) + 0x734) != '\0')) {
    fVar8 = fVar9;
    Obj_GetField830(fVar9);
    RemoteCarState__DelayNextApply(fVar8);
  }
  if ((iVar6 != 0) && (*(char *)(*(int *)(iVar6 + 0x14) + 0x734) != '\0')) {
    Obj_GetField830(fVar9);
    RemoteCarState__DelayNextApply(fVar9);
  }
  return;
}


// ==== 0x465d00 SpecialCamCaller_465d00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera I (G+C) docs/re/camera.md */

void SpecialCamCaller_465d00(int param_1,float *param_2,float *param_3)

{
  int *piVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  int iVar6;
  float *pfVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  float10 fVar12;
  float fStack_124;
  float fStack_120;
  undefined1 auStack_11c [4];
  float fStack_118;
  float local_114;
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  int local_f0;
  int local_e8 [2];
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_cc;
  float fStack_c8;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a0;
  float fStack_9c;
  float fStack_88;
  float fStack_78;
  float fStack_68;
  float fStack_58;
  undefined1 auStack_50 [76];
  
  local_114 = SQRT(param_3[2] * param_3[2] + param_3[1] * param_3[1] + *param_3 * *param_3);
  if (50.0 <= local_114) {
    local_114 = 50.0;
  }
  iVar6 = *(int *)(*(int *)(param_1 + 100) + 600);
  local_e8[0] = 0;
  local_e8[1] = 0;
  if (*(char *)(iVar6 + 0x15) == '\0') {
    local_e8[0] = iVar6;
  }
  iVar6 = *(int *)(*(int *)(param_1 + 100) + 0x25c);
  if (*(char *)(iVar6 + 0x15) == '\0') {
    local_e8[1] = iVar6;
  }
  local_f0 = 0;
  do {
    piVar1 = (int *)local_e8[local_f0];
    if (piVar1 != (int *)0x0) {
      if ((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) {
        fVar3 = 35.0;
        if (local_f0 == 0) {
          iVar6 = *(int *)(*(int *)(param_1 + 100) + 0x25c);
        }
        else {
          iVar6 = *(int *)(*(int *)(param_1 + 100) + 600);
        }
        if ((((iVar6 != 0) && (*(char *)(iVar6 + 0x15) == '\x04')) && (*(int *)(iVar6 + 0x140) != 0)
            ) && ((iVar6 = *(int *)(*(int *)(iVar6 + 0x140) + 0xc), iVar6 == 0x24cebc53 ||
                  (iVar6 == 0x427a6453)))) {
          fVar3 = 15.0;
        }
        if ((fVar3 <= local_114) && (iVar6 = piVar1[0x50], *(int *)(iVar6 + 0x28) == 1)) {
          iVar10 = *(int *)(iVar6 + 0x868);
          *(undefined1 *)(iVar6 + 0x874) = 1;
          if ((iVar10 != 0) && (*(char *)(iVar10 + 8) != '\x01')) {
            *(undefined1 *)(iVar10 + 8) = 1;
            FUN_0058db20();
          }
          *(undefined4 *)(*(int *)(*(int *)(piVar1[0x50] + 0x34) + 0x48) + 0x8c) = 0x3fc00000;
        }
      }
      if (((30.0 <= local_114) && (*(int *)(piVar1[0x50] + 0x38) == 0)) &&
         (((*(char *)(*(int *)(*(int *)(param_1 + 100) + 600) + 0x15) == '\0' &&
           (*(char *)(*(int *)(*(int *)(param_1 + 100) + 0x25c) + 0x15) == '\0')) ||
          (cVar5 = Collision__IsCarWorldObjectCollision(), cVar5 != '\0')))) {
        *(undefined4 *)(param_1 + 0x10) = 1;
        iVar6 = piVar1[0x50];
        *(undefined4 *)(iVar6 + 0x38) = 1;
        *(undefined4 *)(iVar6 + 0x4cc) = 0;
        if ((*(int *)(*(int *)(iVar6 + 0x14) + 4) == 1) &&
           (*(char *)(*(int *)(iVar6 + 0x14) + 0x734) == '\0')) {
          *(undefined4 *)(iVar6 + 0x4c8) = DAT_0073ad34;
        }
        pfVar7 = (float *)(**(code **)(*piVar1 + 8))();
        fStack_10c = param_2[1] - pfVar7[1];
        fStack_108 = param_2[2] - pfVar7[2];
        fStack_110 = *param_2 - *pfVar7;
        if (local_f0 == 0) {
          fStack_100 = *param_3;
          fStack_fc = param_3[1];
          fStack_f8 = param_3[2];
        }
        else {
          fStack_100 = -*param_3;
          fStack_fc = -param_3[1];
          fStack_f8 = -param_3[2];
          fStack_88 = fStack_f8;
        }
        bNormalize3();
        fStack_e0 = fStack_b0;
        fStack_d8 = fStack_a8;
        fStack_dc = fStack_ac;
        (**(code **)(*piVar1 + 0xc))();
        bNormalize3();
        fStack_c8 = fStack_b8;
        fStack_cc = fStack_bc;
        fStack_118 = fStack_bc * fStack_dc + fStack_b8 * fStack_d8 + fStack_e0 * fStack_c0;
        if (fStack_118 < -0.97) {
          fStack_a0 = fStack_c0 * fStack_118;
          fStack_9c = fStack_bc * fStack_118;
          fStack_58 = fStack_b8 * fStack_118;
          fStack_100 = fStack_e0 - fStack_a0;
          fStack_fc = fStack_dc - fStack_9c;
          fStack_f8 = fStack_d8 - fStack_58;
          fStack_78 = fStack_f8;
          bNormalize3();
          fStack_f8 = 0.0;
          fVar3 = -(ABS(fStack_118) * 0.2 * local_114);
          fStack_100 = fStack_100 * fVar3;
          fStack_fc = fVar3 * fStack_fc;
          (**(code **)(*piVar1 + 0x4c))(&fStack_100,&fStack_110);
        }
        pfVar7 = (float *)(**(code **)(*piVar1 + 8))();
        fStack_110 = *param_2 - *pfVar7;
        fStack_10c = param_2[1] - pfVar7[1];
        fStack_108 = param_2[2] - pfVar7[2];
        fStack_68 = fStack_108;
        (**(code **)(*piVar1 + 0x14))();
        bMatrixCopy();
        D3DXVec3Transform(&fStack_110,&fStack_110,auStack_50);
        fStack_108 = 0.0;
        if (-0.97 <= fStack_118) {
          cVar5 = Collision__IsTwoCarCollision();
          if (cVar5 != '\0') {
            fVar3 = ABS(*(float *)(*(int *)(piVar1[0x50] + 0x20) + 0x14) -
                        *(float *)(*(int *)(piVar1[0x50] + 0x20) + 0x44)) * 1.19 * _K_HALF;
            fVar4 = fStack_10c * 1.19;
            fStack_10c = fVar3;
            if ((fVar4 <= fVar3) && (fStack_10c = fVar4, fVar4 < -fVar3)) {
              fStack_10c = -fVar3;
            }
            fStack_110 = fStack_110 * 1.0;
            goto LAB_004661ed;
          }
        }
        else {
          uVar2 = *(uint *)(DAT_007361f8 + 0x2d0);
          uVar11 = uVar2 ^ 0x1d872b41;
          uVar8 = uVar11 >> 5 ^ uVar11;
          *(uint *)(DAT_007361f8 + 0x2d0) = uVar8 << 0x1b ^ uVar8 ^ uVar11;
          if (0x31 < uVar2 % 100) {
            fStack_110 = -(fStack_110 * 1.1);
          }
          if (0.13 < ABS(fStack_10c)) {
            fStack_10c = fStack_10c * 0.2;
          }
LAB_004661ed:
          uVar9 = (**(code **)(*piVar1 + 0x14))();
          D3DXVec3Transform(&fStack_110,&fStack_110,uVar9);
          if ((DAT_0078a344 != '\0') || (fVar3 = _K_ONE, DAT_007361a8 != 0)) {
            fVar3 = 1.2;
          }
          fStack_108 = 0.0;
          fStack_f8 = fVar3 * 4.1;
          fStack_10c = 0.0;
          fVar12 = (float10)bClampF(ABS(fStack_124) * 0.0675 * fStack_120 * fVar3,-fStack_f8,
                                    fStack_f8);
          fStack_104 = (float)fVar12;
          (**(code **)(*piVar1 + 0x4c))(&fStack_10c,auStack_11c);
        }
        if ((((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) &&
            (cVar5 = Collision__IsTwoCarCollision(), cVar5 != '\0')) && (35.0 <= local_114)) {
          iVar6 = piVar1[0x50];
          iVar10 = RacerNode__IsLocalHuman();
          if (((iVar10 != 0) && (iVar6 = *(int *)(*(int *)(iVar6 + 0x18) + 0x60), iVar6 != 6)) &&
             ((iVar6 != 7 && (cVar5 = Player__IsJumpCamAvailable(), cVar5 != '\0')))) {
            cVar5 = Player__StartSpecialCamera(6,0,1,1);
            if (cVar5 == '\0') {
              Player__CleanUpJumpCam();
            }
            else {
              iVar6 = *(int *)(piVar1[0x50] + 0x868);
              if ((iVar6 != 0) && (FUN_0058dbe0(), *(char *)(iVar6 + 8) != '\x01')) {
                *(undefined1 *)(iVar6 + 8) = 1;
                FUN_0058db20();
              }
            }
          }
        }
      }
    }
    local_f0 = local_f0 + 1;
    if (1 < local_f0) {
      return;
    }
  } while( true );
}


// ==== 0x466350 Collision::GetTerrainType

/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

int Collision__GetTerrainType(void)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar1 = (**(code **)(**(int **)(*(int *)(unaff_EDI + 100) + 600) + 0x54))();
  iVar2 = (**(code **)(**(int **)(*(int *)(unaff_EDI + 100) + 0x25c) + 0x54))();
  if (*(float *)(&DAT_006ef300 + iVar1 * 0x94) < *(float *)(&DAT_006ef300 + iVar2 * 0x94)) {
    iVar1 = iVar2;
  }
  return iVar1;
}


// ==== 0x4663a0 Collision::IsTwoCarCollision

/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

undefined4 Collision__IsTwoCarCollision(void)

{
  int in_EAX;
  
  if ((*(char *)(*(int *)(*(int *)(in_EAX + 100) + 600) + 0x15) == '\0') &&
     (*(char *)(*(int *)(*(int *)(in_EAX + 100) + 0x25c) + 0x15) == '\0')) {
    return 1;
  }
  return 0;
}


// ==== 0x4663d0 Collision::IsCarWorldObjectCollision

/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

uint Collision__IsCarWorldObjectCollision(void)

{
  char cVar1;
  uint uVar2;
  int in_EAX;
  
  uVar2 = *(uint *)(in_EAX + 100);
  cVar1 = *(char *)(*(int *)(uVar2 + 600) + 0x15);
  if (cVar1 == '\0') {
    return (uint)(*(char *)(*(int *)(uVar2 + 0x25c) + 0x15) == '\x04');
  }
  if (cVar1 == '\x04') {
    return CONCAT31((int3)((uint)*(int *)(uVar2 + 0x25c) >> 8),
                    *(char *)(*(int *)(uVar2 + 0x25c) + 0x15) == '\0');
  }
  return uVar2 & 0xffffff00;
}


// ==== 0x466410 Collision::GetCollidingCars

/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

void __fastcall Collision__GetCollidingCars(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 *unaff_ESI;
  
  *param_1 = 0;
  *unaff_ESI = 0;
  iVar1 = *(int *)(*(int *)(param_2 + 100) + 600);
  if (*(char *)(iVar1 + 0x15) == '\0') {
    *param_1 = *(undefined4 *)(iVar1 + 0x140);
  }
  iVar1 = *(int *)(*(int *)(param_2 + 100) + 0x25c);
  if (*(char *)(iVar1 + 0x15) == '\0') {
    *unaff_ESI = *(undefined4 *)(iVar1 + 0x140);
  }
  return;
}


// ==== 0x466450 FUN_00466450

void __fastcall FUN_00466450(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  *unaff_ESI = 0;
  *unaff_EDI = 0;
  iVar1 = *(int *)(*(int *)(param_2 + 100) + 600);
  if (*(char *)(iVar1 + 0x15) == '\0') {
    *unaff_ESI = *(undefined4 *)(iVar1 + 0x140);
  }
  else if (*(char *)(iVar1 + 0x15) == '\x04') {
    *unaff_EDI = *(undefined4 *)(iVar1 + 0x140);
  }
  iVar1 = *(int *)(*(int *)(param_2 + 100) + 0x25c);
  if (*(char *)(iVar1 + 0x15) == '\0') {
    *unaff_ESI = *(undefined4 *)(iVar1 + 0x140);
    return;
  }
  if (*(char *)(iVar1 + 0x15) == '\x04') {
    *unaff_EDI = *(undefined4 *)(iVar1 + 0x140);
  }
  return;
}


// ==== 0x4664b0 Collision::IsPlayerInvolved

/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

uint Collision__IsPlayerInvolved(void)

{
  int in_EAX;
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(*(int *)(in_EAX + 100) + 600);
  iVar3 = 0;
  iVar4 = 0;
  if (*(char *)(iVar1 + 0x15) == '\0') {
    iVar3 = *(int *)(iVar1 + 0x140);
  }
  uVar2 = *(uint *)(*(int *)(in_EAX + 100) + 0x25c);
  if (*(char *)(uVar2 + 0x15) == '\0') {
    iVar4 = *(int *)(uVar2 + 0x140);
  }
  if (((iVar3 == 0) || (iVar1 = *(int *)(iVar3 + 0x18), uVar2 = 0, iVar1 == 0)) &&
     ((iVar4 == 0 || (iVar1 = *(int *)(iVar4 + 0x18), uVar2 = 0, iVar1 == 0)))) {
    return uVar2 & 0xffffff00;
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


// ==== 0x466500 Collision::IsWallInvolved

/* [canon] car med (ghidra-canon) docs/re/car.md */

uint Collision__IsWallInvolved(void)

{
  int iVar1;
  float fVar2;
  int in_EAX;
  uint uVar3;
  
  uVar3 = *(uint *)(*(int *)(in_EAX + 100) + 600);
  if (*(char *)(uVar3 + 0x15) == '\x03') {
    fVar2 = ABS(*(float *)(*(int *)(uVar3 + 0x60) + 0x78));
    uVar3 = CONCAT22((short)((uint)*(int *)(uVar3 + 0x60) >> 0x10),
                     (ushort)(fVar2 < 0.1) << 8 | (ushort)NAN(fVar2) << 10 |
                     (ushort)(fVar2 == 0.1) << 0xe);
    if (fVar2 < 0.1) goto LAB_00466549;
  }
  iVar1 = *(int *)(*(int *)(in_EAX + 100) + 0x25c);
  if (*(char *)(iVar1 + 0x15) == '\x03') {
    fVar2 = ABS(*(float *)(*(int *)(iVar1 + 0x60) + 0x78));
    uVar3 = CONCAT22((short)(uVar3 >> 0x10),
                     (ushort)(fVar2 < 0.1) << 8 | (ushort)NAN(fVar2) << 10 |
                     (ushort)(fVar2 == 0.1) << 0xe);
    if (fVar2 < 0.1) {
LAB_00466549:
      return CONCAT31((int3)(uVar3 >> 8),1);
    }
  }
  return uVar3 & 0xffffff00;
}


// ==== 0x466550 Collision_IsFlatSurfaceInvolved

/* [canon] car med (ghidra-canon+hopper) docs/re/car.md */

uint Collision_IsFlatSurfaceInvolved(void)

{
  int iVar1;
  float fVar2;
  int in_EAX;
  uint uVar3;
  
  uVar3 = *(uint *)(*(int *)(in_EAX + 100) + 600);
  if (*(char *)(uVar3 + 0x15) == '\x03') {
    fVar2 = ABS(*(float *)(*(int *)(uVar3 + 0x60) + 0x78));
    uVar3 = CONCAT22((short)((uint)*(int *)(uVar3 + 0x60) >> 0x10),
                     (ushort)(fVar2 < 0.7) << 8 | (ushort)NAN(fVar2) << 10 |
                     (ushort)(fVar2 == 0.7) << 0xe);
    if (fVar2 >= 0.7 && (fVar2 == 0.7) == 0) goto LAB_00466599;
  }
  iVar1 = *(int *)(*(int *)(in_EAX + 100) + 0x25c);
  if (*(char *)(iVar1 + 0x15) == '\x03') {
    fVar2 = ABS(*(float *)(*(int *)(iVar1 + 0x60) + 0x78));
    uVar3 = CONCAT22((short)(uVar3 >> 0x10),
                     (ushort)(fVar2 < 0.7) << 8 | (ushort)NAN(fVar2) << 10 |
                     (ushort)(fVar2 == 0.7) << 0xe);
    if (fVar2 >= 0.7 && (fVar2 == 0.7) == 0) {
LAB_00466599:
      return CONCAT31((int3)(uVar3 >> 8),1);
    }
  }
  return uVar3 & 0xffffff00;
}


// ==== 0x4665a0 PtrList_FreeAllPayloadsAndClear

/* [canon] runtime med (ghidra-canon) docs/re/canon.md */

void PtrList_FreeAllPayloadsAndClear(void)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)*in_EAX;
  puVar2 = (undefined4 *)NullUpdate_ret();
  for (; puVar1 != puVar2; puVar1 = (undefined4 *)*puVar1) {
    if ((void *)puVar1[2] != (void *)0x0) {
      _free((void *)puVar1[2]);
    }
  }
  FUN_00421900();
  return;
}


// ==== 0x4665e0 Struct_ClearHeader

/* [canon] runtime med (ghidra-canon+hopper) docs/re/runtime.md */

void __fastcall Struct_ClearHeader(int param_1)

{
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined2 *)(param_1 + 10) = 0;
  *(undefined2 *)(param_1 + 0xc) = 0;
  *(undefined2 *)(param_1 + 0xe) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}


// ==== 0x466600 CollisionBody_BBoxesOverlap

/* [canon] car med (ghidra-canon) docs/re/canon.md */

undefined4 __fastcall CollisionBody_BBoxesOverlap(int param_1,int param_2,float param_3)

{
  float fVar1;
  
  if ((((*(float *)(param_2 + 0x24) <= param_3 + *(float *)(param_1 + 0x2c)) &&
       (fVar1 = *(float *)(param_1 + 0x24) - param_3,
       fVar1 < *(float *)(param_2 + 0x2c) != (fVar1 == *(float *)(param_2 + 0x2c)))) &&
      (*(float *)(param_2 + 0x28) <= param_3 + *(float *)(param_1 + 0x30))) &&
     (param_3 = *(float *)(param_1 + 0x28) - param_3,
     param_3 < *(float *)(param_2 + 0x30) != (param_3 == *(float *)(param_2 + 0x30)))) {
    return 1;
  }
  return 0;
}


// ==== 0x466660 FUN_00466660

undefined * FUN_00466660(void)

{
  return &DAT_00779bf0;
}


// ==== 0x466670 FUN_00466670

float10 __fastcall FUN_00466670(int param_1)

{
  return (float10)*(float *)(param_1 + 0x20);
}


// ==== 0x466680 FUN_00466680

float10 FUN_00466680(void)

{
  return (float10)1000.0;
}


// ==== 0x466690 StaticCollisionBody::Interpolate

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void StaticCollisionBody__Interpolate(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  bMatrixCopy_b();
  uVar2 = _DAT_007372a8;
  uVar1 = _DAT_007372a4;
  *param_1 = DAT_007372a0;
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  return;
}


// ==== 0x4666d0 StaticCollisionBody::GetCurrentVelocities

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void StaticCollisionBody__GetCurrentVelocities(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = _DAT_007372a8;
  uVar1 = _DAT_007372a4;
  *param_1 = DAT_007372a0;
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  uVar2 = _DAT_007372a8;
  uVar1 = _DAT_007372a4;
  *param_2 = DAT_007372a0;
  param_2[1] = uVar1;
  param_2[2] = uVar2;
  return;
}


// ==== 0x466720 StaticCollisionBody::GetTestImpulseVelocities

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void StaticCollisionBody__GetTestImpulseVelocities(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = _DAT_007372a8;
  uVar1 = _DAT_007372a4;
  *param_1 = DAT_007372a0;
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  uVar2 = _DAT_007372a8;
  uVar1 = _DAT_007372a4;
  *param_2 = DAT_007372a0;
  param_2[1] = uVar1;
  param_2[2] = uVar2;
  return;
}


// ==== 0x466770 FUN_00466770

float10 FUN_00466770(void)

{
  return (float10)0.0;
}


// ==== 0x466780 FUN_00466780

undefined4 * FUN_00466780(void)

{
  return &DAT_00779c30;
}


// ==== 0x466790 StaticCollisionBody::ChangeInEnergy

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

float10 StaticCollisionBody__ChangeInEnergy(void)

{
  return (float10)0.0;
}


// ==== 0x4667a0 FUN_004667a0

void __fastcall FUN_004667a0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_0072cbf4;
  iVar1 = *(int *)(DAT_0072cbf4 + 0x18);
  *param_1 = *(undefined4 *)(DAT_0072cbf4 + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x4667c0 Object_SetVec3ViaVtable8

/* [canon] runtime low (ghidra-canon) docs/re/runtime.md */

void __thiscall Object_SetVec3ViaVtable8(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(**(code **)(*param_1 + 8))();
  uVar1 = param_2[1];
  uVar2 = param_2[2];
  *puVar3 = *param_2;
  puVar3[1] = uVar1;
  puVar3[2] = uVar2;
  return;
}


// ==== 0x4667e0 FUN_004667e0

float10 __fastcall FUN_004667e0(int param_1)

{
  return (float10)*(float *)(param_1 + 0x70);
}


// ==== 0x4667f0 DynamicCollisionBody::GetMassInverse

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

float10 __fastcall DynamicCollisionBody__GetMassInverse(int param_1)

{
  return (float10)*(float *)(*(int *)(param_1 + 0x6c) + 0x148);
}


// ==== 0x466800 CarCollisionBody::GetTransformPtr

/* [canon] car low (ghidra-canon) docs/re/runtime.md */

int __fastcall CarCollisionBody__GetTransformPtr(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x6c);
  if (*(int *)(iVar1 + 0x138) != 0) {
    return iVar1 + 400;
  }
  return iVar1 + 0x150;
}


// ==== 0x466820 DynamicCollisionBody::ApplyImpulse

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void DynamicCollisionBody__ApplyImpulse(void)

{
  FUN_00584e30();
  return;
}


// ==== 0x466840 Virtual::ReturnOne__float_constant_getter_

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

float10 Virtual__ReturnOne__float_constant_getter_(void)

{
  return (float10)_K_ONE;
}


// ==== 0x466850 CarCollisionBody::IsMoveable

/* [canon] car med (ghidra-canon+nfsug) docs/re/canon.md */

bool __fastcall CarCollisionBody__IsMoveable(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x140) + 0x28);
  if ((iVar1 != 1) && (iVar1 != 3)) {
    return true;
  }
  iVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0x140) + 0x34) + 0x10))();
  return iVar1 != 2;
}


// ==== 0x466890 CarState::IsResetGraceOrLockActive

/* [canon] car low (ghidra-canon) docs/re/runtime.md */

undefined4 __fastcall CarState__IsResetGraceOrLockActive(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x140);
  if ((((*(int *)(iVar1 + 0x884) == 0) || (*(int *)(iVar1 + 0x884) == 0x7fffffff)) ||
      (*(float *)(iVar1 + 0x888) <= (float)(DAT_0073ad34 - *(int *)(iVar1 + 0x884)) * 0.00025)) &&
     (*(char *)(iVar1 + 0x8a8) == '\0')) {
    return 0;
  }
  return 1;
}


// ==== 0x4668f0 FUN_004668f0

undefined4 FUN_004668f0(void)

{
  return 0x1c;
}


// ==== 0x466900 FUN_00466900

float10 FUN_00466900(void)

{
  return (float10)0.1;
}


// ==== 0x466910 FUN_00466910

float10 FUN_00466910(void)

{
  return (float10)0.3;
}


// ==== 0x466920 NumberAllocator::AllocateNumber

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void NumberAllocator__AllocateNumber(void)

{
  int iVar1;
  byte *pbVar2;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI[2] == unaff_EDI) {
    iVar1 = unaff_EDI + 1;
    if (iVar1 < *unaff_ESI) {
      do {
        if ((*(byte *)((iVar1 >> 3) + unaff_ESI[1]) & (byte)(1 << ((byte)iVar1 & 7))) == 0) break;
        iVar1 = iVar1 + 1;
      } while (iVar1 < *unaff_ESI);
    }
    unaff_ESI[2] = iVar1;
  }
  pbVar2 = (byte *)(unaff_ESI[1] + (unaff_EDI >> 3));
  *pbVar2 = *pbVar2 | '\x01' << ((byte)unaff_EDI & 7);
  return;
}


// ==== 0x466970 InitCollisionBody

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void InitCollisionBody(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  DAT_0072cbf8 = (undefined4 *)FUN_00566dc0(0x410,"WorldObjectCollisionBodySlotPool",0);
  if ((DAT_0072cbf8 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_0072cbf8;
    puVar1 = DAT_0072cbf8;
    DAT_0072cbf8[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_0072cbf8 = &DAT_0073d818;
  }
  DAT_0072cbf0 = (undefined4 *)FUN_00566dc0(400,"CarCollisionBodySlotPool",0);
  if ((DAT_0072cbf0 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_0072cbf0;
    puVar1 = DAT_0072cbf0;
    DAT_0072cbf0[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_0072cbf0 = &DAT_0073d818;
  }
  DAT_0072cbf4 = (undefined4 *)FUN_00566dc0(0x270,"TrackPolygonCollisionBodySlotPool",0);
  if ((DAT_0072cbf4 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_0072cbf4;
    puVar1 = DAT_0072cbf4;
    DAT_0072cbf4[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_0072cbf4 = &DAT_0073d818;
  }
  DAT_0072cc00 = (undefined4 *)FUN_00566dc0(0x280,"CollisionBodyWitnessSlotPool",0);
  if ((DAT_0072cc00 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_0072cc00;
    puVar1 = DAT_0072cc00;
    DAT_0072cc00[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_0072cc00 = &DAT_0073d818;
  }
  DAT_0072cc04 = (undefined4 *)FUN_00566dc0(0x10,"SubworldObjectsSlotPool",0);
  if ((DAT_0072cc04 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_0072cc04;
    puVar1 = DAT_0072cc04;
    DAT_0072cc04[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_0072cc04 = &DAT_0073d818;
  }
  DAT_0072cc08 = (undefined4 *)FUN_00566dc0(0x28,"SubworldSlotPool",0);
  if ((DAT_0072cc08 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_0072cc08;
    puVar1 = DAT_0072cc08;
    DAT_0072cc08[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_0072cc08 = &DAT_0073d818;
  }
  puVar1 = _malloc(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[1] = 0;
    puVar1[2] = 0;
    *puVar1 = 0xde;
    puVar2 = _malloc(0x1b);
    puVar1[1] = puVar2;
    for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    *(undefined2 *)puVar2 = 0;
    *(undefined1 *)((int)puVar2 + 2) = 0;
    puVar1[2] = 0;
  }
  DAT_00736070 = puVar1;
  DAT_00736050 = _malloc(0x378);
  puVar1 = DAT_00736050;
  for (iVar3 = 0xde; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  _DAT_00779bf0 = 0x3f800000;
  _DAT_00779bf4 = 0;
  _DAT_00779bf8 = 0;
  _DAT_00779bfc = 0;
  _DAT_00779c00 = 0;
  _DAT_00779c04 = 0x3f800000;
  _DAT_00779c08 = 0;
  _DAT_00779c0c = 0;
  _DAT_00779c10 = 0;
  _DAT_00779c14 = 0;
  _DAT_00779c18 = 0x3f800000;
  _DAT_00779c1c = 0;
  _DAT_00779c20 = 0;
  _DAT_00779c24 = 0;
  _DAT_00779c28 = 0;
  _DAT_00779c2c = 0x3f800000;
  puVar1 = &DAT_00779c30;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  DAT_0072cbfc = _malloc(0x1810);
  puVar1 = DAT_0072cbfc;
  for (iVar3 = 0x604; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  return;
}


// ==== 0x466bf0 CloseCollisionBody

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void CloseCollisionBody(void)

{
  int *piVar1;
  int *_Memory;
  
  SlotPool__Destroy();
  SlotPool__Destroy();
  SlotPool__Destroy();
  SlotPool__Destroy();
  SlotPool__Destroy();
  SlotPool__Destroy();
  _Memory = DAT_00736070;
  DAT_0072cbf4 = 0;
  DAT_0072cbf8 = 0;
  DAT_0072cbf0 = 0;
  DAT_0072cc00 = 0;
  DAT_0072cc04 = 0;
  DAT_0072cc08 = 0;
  if (DAT_00736070 != (int *)0x0) {
    if (*DAT_00736070 != 0) {
      piVar1 = DAT_00736070 + 1;
      *DAT_00736070 = 0;
      _free((void *)*piVar1);
      *piVar1 = 0;
      _Memory[2] = 0;
    }
    _free(_Memory);
  }
  DAT_00736070 = (int *)0x0;
  _free(DAT_00736050);
  DAT_00736050 = (void *)0x0;
  _free(DAT_0072cbfc);
  DAT_0072cbfc = (void *)0x0;
  return;
}


// ==== 0x466ce0 CollisionBodyWitness::CollisionBodyWitness

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void CollisionBodyWitness__CollisionBodyWitness(int param_1)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_EAX;
  int iVar5;
  int iVar6;
  undefined4 *unaff_ESI;
  
  unaff_ESI[0x4e] = 0;
  *unaff_ESI = &PTR_CollisionBodyWitness___CollisionBodyWitness_006c8810;
  if ((*(int *)(in_EAX + 0x10) != 0) && (*(int *)(param_1 + 0x10) != 0)) {
    GJKWitness__Initialize();
  }
  unaff_ESI[0x9a] = 0xbf800000;
  unaff_ESI[0x9b] = 0xbf800000;
  unaff_ESI[0x9c] = 0;
  DAT_00736000 = DAT_00736000 + 1;
  if (DAT_00736028 < DAT_00736000) {
    DAT_00736028 = DAT_00736000;
  }
  puVar1 = unaff_ESI + 0x94;
  *DAT_00779be4 = puVar1;
  puVar4 = puVar1;
  unaff_ESI[0x95] = DAT_00779be4;
  DAT_00779be4 = puVar4;
  *puVar1 = &DAT_00779be0;
  unaff_ESI[0x96] = in_EAX;
  unaff_ESI[0x97] = param_1;
  unaff_ESI[0x99] = 0;
  unaff_ESI[0x9d] = 0;
  iVar3 = DAT_0072cbfc;
  iVar5 = *(short *)(in_EAX + 0x18) * 0xde + (int)*(short *)(param_1 + 0x18);
  pbVar2 = (byte *)((iVar5 >> 3) + DAT_0072cbfc);
  *pbVar2 = *pbVar2 | '\x01' << ((byte)iVar5 & 7);
  iVar5 = *(short *)(unaff_ESI[0x97] + 0x18) * 0xde + (int)*(short *)(unaff_ESI[0x96] + 0x18);
  iVar6 = iVar5 >> 3;
  *(byte *)(iVar6 + iVar3) = *(byte *)(iVar6 + iVar3) | '\x01' << ((byte)iVar5 & 7);
  *(char *)(unaff_ESI[0x96] + 0x1a) = *(char *)(unaff_ESI[0x96] + 0x1a) + '\x01';
  *(char *)(unaff_ESI[0x97] + 0x1a) = *(char *)(unaff_ESI[0x97] + 0x1a) + '\x01';
  return;
}


// ==== 0x466df0 CollisionBodyWitness::_CollisionBodyWitness

/* [canon] car med (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 * __thiscall
CollisionBodyWitness___CollisionBodyWitness(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  CollisionBodyWitness___CollisionBodyWitness(param_1);
  iVar2 = DAT_0072cc00;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_0072cc00 + 0x18);
    *param_1 = *(undefined4 *)(DAT_0072cc00 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x466e20 CollisionBodyWitness::_CollisionBodyWitness

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void CollisionBodyWitness___CollisionBodyWitness(undefined4 *param_1)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006854f8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_CollisionBodyWitness___CollisionBodyWitness_006c8810;
  DAT_00736000 = DAT_00736000 + -1;
  local_4 = 0;
  if (param_1[0x99] != 0) {
    CollisionBodyWitness__EndCollision();
  }
  piVar2 = (int *)param_1[0x95];
  iVar3 = param_1[0x94];
  *piVar2 = iVar3;
  *(int **)(iVar3 + 4) = piVar2;
  *(char *)(param_1[0x96] + 0x1a) = *(char *)(param_1[0x96] + 0x1a) + -1;
  *(char *)(param_1[0x97] + 0x1a) = *(char *)(param_1[0x97] + 0x1a) + -1;
  iVar3 = DAT_0072cbfc;
  iVar5 = *(short *)(param_1[0x96] + 0x18) * 0xde + (int)*(short *)(param_1[0x97] + 0x18);
  pbVar1 = (byte *)((iVar5 >> 3) + DAT_0072cbfc);
  *pbVar1 = *pbVar1 & ~('\x01' << ((byte)iVar5 & 7));
  iVar5 = *(short *)(param_1[0x97] + 0x18) * 0xde + (int)*(short *)(param_1[0x96] + 0x18);
  pbVar1 = (byte *)((iVar5 >> 3) + iVar3);
  *pbVar1 = *pbVar1 & ~('\x01' << ((byte)iVar5 & 7));
  puVar4 = (undefined4 *)param_1[0x96];
  if ((*(char *)((int)puVar4 + 0x15) == '\x03') && (*(char *)((int)puVar4 + 0x1a) == '\0')) {
    if (puVar4 != (undefined4 *)0x0) {
      (**(code **)*puVar4)(1);
    }
    param_1[0x96] = 0;
  }
  puVar4 = (undefined4 *)param_1[0x97];
  if ((*(char *)((int)puVar4 + 0x15) == '\x03') && (*(char *)((int)puVar4 + 0x1a) == '\0')) {
    if (puVar4 != (undefined4 *)0x0) {
      (**(code **)*puVar4)(1);
    }
    param_1[0x97] = 0;
  }
  if (param_1[0x9c] != 0) {
    FUN_005935e0();
  }
  *param_1 = &PTR_FUN_006c84d4;
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x466f70 CollisionBodyWitness::DoSnapshot

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void CollisionBodyWitness__DoSnapshot(int param_1)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  char cVar3;
  
  iVar2 = param_1;
  FUN_00571ea0(in_EAX,"CollisionBodyWitness");
  FUN_00472600();
  param_1 = CONCAT31(param_1._1_3_,*(int *)(in_EAX + 0x264) != 0);
  FUN_00571c20(iVar2,&param_1,1,1,1);
  if ((char)param_1 != '\0') {
    if (*(char *)(iVar2 + 0x3d) != '\0') {
      CollisionBodyWitness__BeginCollision(0);
    }
    FUN_00465770();
  }
  iVar1 = *(char *)(iVar2 + 0x40) * 0x10 + 0x4c + iVar2;
  *(int *)(iVar1 + 0xc) = *(int *)(iVar2 + 0x150) - *(int *)(iVar1 + 0xc);
  cVar3 = *(char *)(iVar2 + 0x40) + -1;
  *(char *)(iVar2 + 0x40) = cVar3;
  if ((int)cVar3 < *(int *)(iVar2 + 0x44)) {
    *(undefined4 *)(iVar2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x467010 CollisionBodyWitness::SnapshotEverything

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void CollisionBodyWitness__SnapshotEverything(uint param_1)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  undefined4 *puVar8;
  short local_14 [2];
  short local_10 [2];
  undefined4 local_c;
  undefined4 local_8;
  uint local_4;
  
  iVar4 = param_1;
  FUN_00571ea0(0,"AllCollisionBodyWitnesses");
  if (*(char *)(iVar4 + 0x3d) == '\0') {
    FUN_00571c20(iVar4,&DAT_00736000,2,4,1);
    if (DAT_00779be0 == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = DAT_00779be0 + -0x250;
    }
    iVar5 = FUN_00421970();
    while (iVar7 != iVar5) {
      param_1 = (uint)*(ushort *)(*(int *)(iVar7 + 600) + 0x18);
      local_4 = (uint)*(ushort *)(*(int *)(iVar7 + 0x25c) + 0x18);
      FUN_00571c20(iVar4,&param_1,2,2,1);
      FUN_00571c20(iVar4,&local_4,2,2,1);
      CollisionBodyWitness__DoSnapshot(iVar4);
      if (*(int *)(iVar7 + 0x250) == 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = *(int *)(iVar7 + 0x250) + -0x250;
      }
    }
  }
  else {
    FUN_00571c20(iVar4,&param_1,2,2,1);
    local_4 = 0;
    if (0 < (short)param_1) {
      do {
        FUN_00571c20(iVar4,local_14,2,2,1);
        FUN_00571c20(iVar4,local_10,2,2,1);
        iVar7 = DAT_0072cc00;
        if (local_14[0] < 0) {
          local_8 = 0;
        }
        else {
          local_8 = *(undefined4 *)(DAT_00736050 + local_14[0] * 4);
        }
        if (local_10[0] < 0) {
          local_c = 0;
        }
        else {
          local_c = *(undefined4 *)(DAT_00736050 + local_10[0] * 4);
        }
        puVar1 = (undefined4 *)(DAT_0072cc00 + 0x10);
        if ((*(int *)(DAT_0072cc00 + 0x10) == 0) && ((*(byte *)(DAT_0072cc00 + 0x14) & 1) != 0)) {
          FUN_00566e60();
        }
        puVar8 = (undefined4 *)*puVar1;
        iVar5 = *(int *)(iVar7 + 0x18) + 1;
        if (puVar8 != (undefined4 *)0x0) {
          uVar3 = *puVar8;
          if (*(int *)(iVar7 + 0x1c) < iVar5) {
            *(int *)(iVar7 + 0x1c) = iVar5;
          }
          *(int *)(iVar7 + 0x18) = iVar5;
          bVar2 = *(byte *)(iVar7 + 0x14);
          *puVar1 = uVar3;
          if (((bVar2 & 2) != 0) && (iVar7 = *(int *)(iVar7 + 0x28) >> 2, 0 < iVar7)) {
            for (; iVar7 != 0; iVar7 = iVar7 + -1) {
              *puVar8 = 0;
              puVar8 = puVar8 + 1;
            }
          }
          CollisionBodyWitness__CollisionBodyWitness(local_c);
        }
        CollisionBodyWitness__DoSnapshot(iVar4);
        local_4 = local_4 + 1;
      } while ((int)local_4 < (int)(short)param_1);
    }
  }
  iVar7 = *(char *)(iVar4 + 0x40) * 0x10 + 0x4c + iVar4;
  *(int *)(iVar7 + 0xc) = *(int *)(iVar4 + 0x150) - *(int *)(iVar7 + 0xc);
  cVar6 = *(char *)(iVar4 + 0x40) + -1;
  *(char *)(iVar4 + 0x40) = cVar6;
  if ((int)cVar6 < *(int *)(iVar4 + 0x44)) {
    *(undefined4 *)(iVar4 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x467220 CollisionBodyWitness::BeginCollision

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void CollisionBodyWitness__BeginCollision(void)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EDI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686518;
  local_c = ExceptionList;
  pcVar1 = (char *)(*(int *)(unaff_EDI + 600) + 0x1c);
  ExceptionList = &local_c;
  *pcVar1 = *pcVar1 + '\x01';
  pcVar1 = (char *)(*(int *)(unaff_EDI + 0x25c) + 0x1c);
  *pcVar1 = *pcVar1 + '\x01';
  DAT_00736004 = DAT_00736004 + 1;
  if (DAT_0073602c < DAT_00736004) {
    DAT_0073602c = DAT_00736004;
  }
  iVar2 = FUN_00567160();
  uVar3 = 0;
  local_4 = 0;
  if (iVar2 != 0) {
    uVar3 = FUN_00465640();
  }
  *(undefined4 *)(unaff_EDI + 0x264) = uVar3;
  ExceptionList = local_c;
  return;
}


// ==== 0x4672a0 CollisionBodyWitness::EndCollision

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void CollisionBodyWitness__EndCollision(void)

{
  char *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int in_EAX;
  
  puVar2 = *(undefined4 **)(in_EAX + 0x264);
  if (puVar2 != (undefined4 *)0x0) {
    FUN_00465700();
    iVar4 = DAT_00736088;
    iVar3 = *(int *)(DAT_00736088 + 0x18);
    *puVar2 = *(undefined4 *)(DAT_00736088 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar3 + -1;
    *(undefined4 **)(iVar4 + 0x10) = puVar2;
  }
  *(undefined4 *)(in_EAX + 0x264) = 0;
  DAT_00736004 = DAT_00736004 + -1;
  pcVar1 = (char *)(*(int *)(in_EAX + 600) + 0x1c);
  *pcVar1 = *pcVar1 + -1;
  *(char *)(*(int *)(in_EAX + 0x25c) + 0x1c) = *(char *)(*(int *)(in_EAX + 0x25c) + 0x1c) + -1;
  return;
}


// ==== 0x467300 CollisionBodyWitness::HasExpired

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 CollisionBodyWitness__HasExpired(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x264) != 0) {
    return 0;
  }
  iVar3 = *(int *)(unaff_EDI + 0x25c);
  piVar1 = *(int **)(unaff_EDI + 600);
  iVar2 = CollisionBody_BBoxesOverlap(0);
  if ((iVar2 != 0) && ((*(char *)((int)piVar1 + 0x1d) != '\0' || (*(char *)(iVar3 + 0x1d) != '\0')))
     ) {
    iVar3 = (**(code **)(*piVar1 + 0x50))();
    if (iVar3 != 0) {
      iVar3 = (**(code **)(**(int **)(unaff_EDI + 0x25c) + 0x50))();
      if (iVar3 != 0) {
        return 0;
      }
    }
  }
  return 1;
}


// ==== 0x467360 IsYawControlInducingCollisionBody

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

uint __fastcall IsYawControlInducingCollisionBody(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x15);
  if (-1 < cVar1) {
    if (cVar1 < '\x03') {
      return 1;
    }
    if (cVar1 == '\x03') {
      return ((int)*(char *)(*(int *)(param_1 + 0x60) + 10) & 2U) >> 1;
    }
  }
  return 0;
}


// ==== 0x467390 CollisionBodyWitness::EstimateClosestPoints

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 CollisionBodyWitness__EstimateClosestPoints(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float *in_EAX;
  float *pfVar11;
  float *pfVar12;
  int *piVar13;
  int *piVar14;
  float10 fVar15;
  float10 fVar16;
  float *local_5c;
  
  if (DAT_00736078 == 0) {
    piVar14 = *(int **)(param_1 + 600);
    if ((*(char *)((int)piVar14 + 0x15) == '\x03') ||
       (*(char *)(*(int *)(param_1 + 0x25c) + 0x15) == '\x03')) {
      local_5c = param_2;
      if (*(char *)((int)piVar14 + 0x15) == '\x03') {
        piVar13 = piVar14;
        param_2 = in_EAX;
        piVar14 = *(int **)(param_1 + 0x25c);
      }
      else {
        piVar13 = *(int **)(param_1 + 0x25c);
        local_5c = in_EAX;
      }
      iVar7 = piVar13[0x18];
      fVar1 = *(float *)(iVar7 + 0x74);
      fVar6 = *(float *)(iVar7 + 0x70);
      fVar2 = *(float *)(iVar7 + 0x78);
      fVar8 = -fVar6;
      fVar9 = -fVar1;
      fVar10 = -fVar2;
      pfVar11 = (float *)(**(code **)(*piVar14 + 8))();
      fVar3 = pfVar11[1];
      fVar4 = pfVar11[2];
      *param_2 = *pfVar11;
      param_2[1] = fVar3;
      param_2[2] = fVar4;
      fVar15 = (float10)(**(code **)(*piVar14 + 0x20))();
      fVar3 = (float)fVar15;
      *param_2 = fVar8 * fVar3 + *param_2;
      param_2[1] = fVar9 * fVar3 + param_2[1];
      param_2[2] = fVar10 * fVar3 + param_2[2];
      iVar7 = piVar13[0x18];
      fVar3 = *(float *)(iVar7 + 0x38);
      fVar4 = *(float *)(iVar7 + 0x34);
      fVar5 = *(float *)(iVar7 + 0x30);
      pfVar11 = (float *)(**(code **)(*piVar14 + 8))();
      fVar3 = -((fVar6 * *pfVar11 + fVar1 * pfVar11[1] + fVar2 * pfVar11[2] +
                fVar8 * fVar5 + fVar9 * fVar4 + fVar10 * fVar3) /
               (fVar8 * fVar6 + fVar9 * fVar1 + fVar10 * fVar2));
      pfVar11 = (float *)(**(code **)(*piVar14 + 8))();
      fVar1 = pfVar11[1];
      fVar2 = pfVar11[2];
      fVar4 = fVar8 * fVar3 + *pfVar11;
      *local_5c = fVar4;
      fVar1 = fVar9 * fVar3 + fVar1;
      local_5c[1] = fVar1;
      fVar2 = fVar10 * fVar3 + fVar2;
      local_5c[2] = fVar2;
      fVar4 = *param_2 - fVar4;
      fVar1 = param_2[1] - fVar1;
      fVar2 = param_2[2] - fVar2;
      fVar15 = (float10)(**(code **)(*piVar14 + 0x20))();
      if (fVar15 <= (float10)SQRT(fVar4 * fVar4 + fVar1 * fVar1 + fVar2 * fVar2)) {
        return 1;
      }
    }
    else {
      pfVar11 = (float *)(**(code **)(*piVar14 + 8))();
      pfVar12 = (float *)(**(code **)(**(int **)(param_1 + 0x25c) + 8))();
      fVar1 = *pfVar12;
      fVar2 = *pfVar11;
      fVar3 = pfVar12[1];
      fVar4 = pfVar11[1];
      fVar5 = pfVar12[2];
      fVar6 = pfVar11[2];
      piVar14 = *(int **)(param_1 + 600);
      fVar15 = (float10)(**(code **)(**(int **)(param_1 + 0x25c) + 0x20))();
      fVar16 = (float10)(**(code **)(*piVar14 + 0x20))();
      if (fVar16 + (float10)(float)fVar15 <=
          (float10)SQRT((fVar1 - fVar2) * (fVar1 - fVar2) +
                        (fVar5 - fVar6) * (fVar5 - fVar6) + (fVar3 - fVar4) * (fVar3 - fVar4))) {
        bNormalize3();
        fVar1 = pfVar11[2];
        fVar2 = *pfVar11;
        param_2[1] = pfVar11[1];
        *param_2 = fVar2;
        param_2[2] = fVar1;
        fVar15 = (float10)(**(code **)(**(int **)(param_1 + 600) + 0x20))();
        pfVar11 = (float *)Vec3_ScaleTo((float)fVar15);
        fVar1 = pfVar11[1];
        fVar2 = pfVar11[2];
        *param_2 = *pfVar11 + *param_2;
        param_2[1] = fVar1 + param_2[1];
        param_2[2] = fVar2 + param_2[2];
        fVar1 = pfVar12[1];
        fVar2 = pfVar12[2];
        *in_EAX = *pfVar12;
        in_EAX[1] = fVar1;
        in_EAX[2] = fVar2;
        fVar15 = (float10)(**(code **)(**(int **)(param_1 + 0x25c) + 0x20))();
        pfVar11 = (float *)Vec3_ScaleTo((float)-fVar15);
        fVar1 = pfVar11[1];
        fVar2 = pfVar11[2];
        *in_EAX = *pfVar11 + *in_EAX;
        in_EAX[1] = fVar1 + in_EAX[1];
        in_EAX[2] = fVar2 + in_EAX[2];
        return 1;
      }
    }
  }
  return 0;
}


// ==== 0x467700 CollisionBodyWitness::GetTOI

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

float10 CollisionBodyWitness__GetTOI(float param_1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  char cVar6;
  int in_EAX;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  float *pfVar10;
  int iVar11;
  float10 fVar12;
  float10 fVar13;
  int *local_b8;
  float local_b4;
  float local_ac;
  float fStack_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_60;
  float local_5c;
  float local_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float local_34;
  float local_28;
  float fStack_18;
  
  if (0.0 <= param_1) {
    *(undefined4 *)(in_EAX + 0x268) = 0xbf800000;
    iVar11 = 0;
    do {
      if ((iVar11 == 0) &&
         (cVar6 = CollisionBodyWitness__EstimateClosestPoints(in_EAX,&local_60), cVar6 != '\0')) {
        local_90 = local_70 - local_60;
        local_8c = local_6c - local_5c;
        local_88 = local_68 - local_58;
        local_74 = SQRT(local_90 * local_90 + local_8c * local_8c + local_88 * local_88);
        iVar11 = 0;
        local_28 = local_88;
      }
      else {
        piVar1 = *(int **)(in_EAX + 0x25c);
        local_b8 = *(int **)(in_EAX + 600);
        iVar11 = iVar11 + 1;
        uVar7 = (**(code **)(*piVar1 + 8))();
        uVar8 = (**(code **)(*piVar1 + 0x14))(uVar7);
        (**(code **)(*local_b8 + 8))(uVar8);
        uVar9 = (**(code **)(*local_b8 + 0x14))();
        FUN_00472830(uVar9,uVar8,uVar7);
        FUN_00472950();
        local_5c = *(float *)(in_EAX + 0x24);
        local_70 = *(float *)(in_EAX + 0x30);
        local_60 = *(float *)(in_EAX + 0x20);
        local_74 = *(float *)(in_EAX + 0x10);
        local_58 = *(float *)(in_EAX + 0x28);
        local_6c = *(float *)(in_EAX + 0x34);
        local_68 = *(float *)(in_EAX + 0x38);
        local_90 = local_70 - local_60;
        local_8c = local_6c - local_5c;
        local_88 = local_68 - local_58;
        fStack_18 = local_88;
      }
      local_34 = -1.0;
      local_ac = 0.0;
      local_b4 = 0.0;
      if (local_74 < _K_EPS_SPEED == (local_74 == _K_EPS_SPEED)) {
        bNormalize3();
        if (*(char *)((int)*(int **)(in_EAX + 600) + 0x16) != '\0') {
          (**(code **)(**(int **)(in_EAX + 600) + 0x44))(*(undefined4 *)(in_EAX + 0x25c));
          (**(code **)(**(int **)(in_EAX + 600) + 0x10))();
          pfVar10 = (float *)(**(code **)(**(int **)(in_EAX + 600) + 0x5c))();
          fVar2 = *pfVar10;
          fVar3 = pfVar10[5];
          local_ac = pfVar10[10];
          if (fVar2 < fVar3) {
            fVar3 = fVar2;
          }
          if (fVar3 < local_ac) {
            local_ac = fVar3;
          }
          if (local_ac != 0.0) {
            (**(code **)(**(int **)(in_EAX + 600) + 0x18))();
          }
          (**(code **)(**(int **)(in_EAX + 600) + 0x20))();
          pfVar10 = (float *)(**(code **)(**(int **)(in_EAX + 600) + 0xc))();
          local_b4 = (float)local_b8 * fVar2 +
                     local_90 * *pfVar10 + local_8c * pfVar10[1] + local_88 * pfVar10[2];
        }
        if (*(char *)((int)*(int **)(in_EAX + 0x25c) + 0x16) != '\0') {
          (**(code **)(**(int **)(in_EAX + 0x25c) + 0x44))(*(undefined4 *)(in_EAX + 600));
          fStack_54 = -fStack_94;
          fStack_50 = -local_90;
          fStack_4c = -local_8c;
          (**(code **)(**(int **)(in_EAX + 0x25c) + 0x10))();
          pfVar10 = (float *)(**(code **)(**(int **)(in_EAX + 600) + 0x5c))();
          fVar2 = *pfVar10;
          fVar3 = pfVar10[5];
          local_ac = pfVar10[10];
          if (fVar2 < fVar3) {
            fVar3 = fVar2;
          }
          if (fVar3 < local_ac) {
            local_ac = fVar3;
          }
          if (local_ac != 0.0) {
            (**(code **)(**(int **)(in_EAX + 600) + 0x18))();
          }
          (**(code **)(**(int **)(in_EAX + 0x25c) + 0x20))();
          pfVar10 = (float *)(**(code **)(**(int **)(in_EAX + 0x25c) + 0xc))();
          local_b4 = (float)local_b8 * fVar2 +
                     fStack_50 * *pfVar10 + fStack_4c * pfVar10[1] + fStack_48 * pfVar10[2] +
                     local_b4;
        }
        if (local_ac == 0.0) {
          if (local_b4 != 0.0) {
            fVar12 = (float10)local_74 / (float10)local_b4;
            goto LAB_00467c3c;
          }
LAB_00467c35:
          fVar12 = (float10)local_34;
        }
        else {
          if (local_b4 == 0.0) goto LAB_00467c35;
          local_b8 = (int *)(local_ac * local_74 * 4.0 + local_b4 * local_b4);
          if ((float)local_b8 == 0.0) {
            fVar12 = -(float10)local_b4 / ((float10)local_ac + (float10)local_ac);
          }
          else {
            if ((float)local_b8 <= 0.0) goto LAB_00467c35;
            piVar4 = (int *)((SQRT((float)local_b8) - local_b4) / (local_ac + local_ac));
            local_b8 = (int *)((-SQRT((float)local_b8) - local_b4) / (local_ac + local_ac));
            piVar1 = local_b8;
            if ((float)piVar4 < (float)local_b8) {
              piVar1 = piVar4;
            }
            fVar12 = (float10)(float)piVar1;
            if (fVar12 < (float10)0.0) {
              fVar12 = (float10)bMax_float(piVar4,local_b8);
            }
          }
        }
LAB_00467c3c:
        fVar13 = ABS(fVar12);
        if (fVar13 < (float10)_DAT_007000d0 != (fVar13 == (float10)_DAT_007000d0)) {
          fVar12 = (float10)(float)fVar13;
        }
        if (fVar12 < (float10)0.0) break;
      }
      else {
        fVar12 = (float10)0.0;
      }
      iVar5 = DAT_0073607c;
      *(float *)(in_EAX + 0x268) = (float)fVar12;
      if (iVar5 != 0) break;
      iVar11 = iVar11 + 1;
      if (1 < iVar11) {
        return (float10)*(float *)(in_EAX + 0x268);
      }
    } while( true );
  }
  return (float10)*(float *)(in_EAX + 0x268);
}


// ==== 0x467ca0 CollisionBodyWitness_UpdatePolygonSideFlag

/* [canon] car low (ghidra-canon) docs/re/canon.md */

void __thiscall CollisionBodyWitness_UpdatePolygonSideFlag(int param_1,char param_2)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int *piVar8;
  int *piVar9;
  
  piVar3 = *(int **)(param_1 + 600);
  if ((((*(char *)((int)piVar3 + 0x15) == '\x03') &&
       (piVar9 = *(int **)(param_1 + 0x25c), piVar8 = piVar3,
       *(char *)((int)piVar9 + 0x15) == '\x01')) ||
      ((*(char *)((int)*(int **)(param_1 + 0x25c) + 0x15) == '\x03' &&
       (piVar8 = *(int **)(param_1 + 0x25c), piVar9 = piVar3,
       *(char *)((int)piVar3 + 0x15) == '\x01')))) &&
     ((piVar8 != (int *)0x0 && (piVar9 != (int *)0x0)))) {
    if ((param_2 == '\0') || (*(char *)((int)piVar9 + 0x15) == '\0')) {
      iVar6 = piVar8[0x18];
      fVar1 = *(float *)(iVar6 + 0x74);
      fVar4 = *(float *)(iVar6 + 0x70);
      iVar5 = piVar8[4];
      fVar2 = *(float *)(iVar6 + 0x78);
      if ((*(byte *)(iVar6 + 10) & 2) != 0) {
        iVar6 = (**(code **)(*piVar9 + 8))();
        *(undefined4 *)(iVar5 + 0x1f8) = *(undefined4 *)(iVar6 + 8);
      }
      pfVar7 = (float *)(**(code **)(*piVar9 + 8))();
      if (0.0 < (pfVar7[1] - *(float *)(iVar5 + 500)) * fVar1 +
                (*pfVar7 - *(float *)(iVar5 + 0x1f0)) * fVar4 +
                fVar2 * (pfVar7[2] - *(float *)(iVar5 + 0x1f8))) {
        *(undefined1 *)(piVar8[4] + 0x1d0) = 1;
        return;
      }
      param_2 = '\0';
    }
    *(char *)(piVar8[4] + 0x1d0) = param_2;
  }
  return;
}


// ==== 0x467db0 CollisionBodyWitness_ClearPolygonSideFlag

/* [canon] car med (ghidra-canon) docs/re/canon.md */

void __fastcall CollisionBodyWitness_ClearPolygonSideFlag(int param_1)

{
  if (*(char *)(*(int *)(param_1 + 600) + 0x15) == '\x03') {
    *(undefined1 *)(*(int *)(*(int *)(param_1 + 600) + 0x10) + 0x1d0) = 0;
    return;
  }
  if (*(char *)(*(int *)(param_1 + 0x25c) + 0x15) == '\x03') {
    *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x25c) + 0x10) + 0x1d0) = 0;
  }
  return;
}


// ==== 0x467df0 CollisionBodyWitness::TestForContact

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 __fastcall CollisionBodyWitness__TestForContact(int param_1)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  float fVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_006864f8;
  local_c = ExceptionList;
  cVar1 = *(char *)((int)*(int **)(param_1 + 600) + 0x15);
  uVar10 = 0;
  if (((cVar1 == '\x04') && (cVar2 = *(char *)(*(int *)(param_1 + 0x25c) + 0x15), cVar2 != '\0')) &&
     (cVar2 != '\x01')) {
    return 0;
  }
  if ((((*(char *)(*(int *)(param_1 + 0x25c) + 0x15) != '\x04') || (cVar1 == '\0')) ||
      (cVar1 == '\x01')) &&
     ((ExceptionList = &local_c, iVar6 = (**(code **)(**(int **)(param_1 + 600) + 0x50))(),
      iVar6 != 0 && (iVar6 = (**(code **)(**(int **)(param_1 + 0x25c) + 0x50))(), iVar6 != 0)))) {
    iVar6 = *(int *)(param_1 + 0x264);
    uVar7 = 0;
    if (iVar6 != 0) {
      fVar5 = (float)(DAT_0073ad34 - *(int *)(iVar6 + 8)) * 0.00025;
      uVar7 = CONCAT22((short)((uint)iVar6 >> 0x10),
                       (ushort)(fVar5 < 0.05) << 8 | (ushort)NAN(fVar5) << 10 |
                       (ushort)(fVar5 == 0.05) << 0xe);
      if (fVar5 >= 0.05 && (fVar5 == 0.05) == 0) {
        uVar7 = CONCAT31((int3)((uint)uVar7 >> 8),1);
      }
    }
    CollisionBodyWitness_UpdatePolygonSideFlag(uVar7);
    piVar3 = *(int **)(param_1 + 0x25c);
    piVar4 = *(int **)(param_1 + 600);
    uVar7 = (**(code **)(*piVar3 + 8))();
    uVar8 = (**(code **)(*piVar3 + 0x14))(uVar7);
    (**(code **)(*piVar4 + 8))(uVar8);
    uVar9 = (**(code **)(*piVar4 + 0x14))();
    FUN_00472830(uVar9,uVar8,uVar7);
    FUN_00472950();
    cVar1 = *(char *)(param_1 + 0x14);
    CollisionBodyWitness_ClearPolygonSideFlag();
    if (cVar1 != '\0') {
      iVar6 = (**(code **)(**(int **)(param_1 + 600) + 0x68))();
      if ((((iVar6 == 0) &&
           (iVar6 = (**(code **)(**(int **)(param_1 + 0x25c) + 0x68))(), iVar6 == 0)) ||
          (iVar6 = *(int *)(param_1 + 600), *(char *)(iVar6 + 0x16) == '\0')) ||
         (*(char *)(*(int *)(param_1 + 0x25c) + 0x16) == '\0')) {
        if (*(char *)(*(int *)(param_1 + 600) + 0x15) == '\0') {
          uVar11 = IsYawControlInducingCollisionBody();
          if ((int)uVar11 != 0) {
            *(int *)((int)((ulonglong)uVar11 >> 0x20) + 0x14c) = DAT_0073ad34;
          }
          *(int *)(*(int *)(param_1 + 600) + 0x144) = DAT_0073ad34;
        }
        if (*(char *)(*(int *)(param_1 + 0x25c) + 0x15) == '\0') {
          uVar11 = IsYawControlInducingCollisionBody();
          if ((int)uVar11 != 0) {
            *(int *)((int)((ulonglong)uVar11 >> 0x20) + 0x14c) = DAT_0073ad34;
          }
          *(int *)(*(int *)(param_1 + 0x25c) + 0x144) = DAT_0073ad34;
        }
        iVar6 = FUN_00567160();
        uVar10 = 0;
        uStack_4 = 0;
        if (iVar6 != 0) {
          uVar10 = FUN_0046ae40();
        }
      }
      else {
        if (*(char *)(iVar6 + 0x15) == '\0') {
          *(int *)(iVar6 + 0x148) = DAT_0073ad34;
        }
        if (*(char *)(*(int *)(param_1 + 0x25c) + 0x15) == '\0') {
          *(int *)(*(int *)(param_1 + 0x25c) + 0x148) = DAT_0073ad34;
          ExceptionList = local_c;
          return 0;
        }
      }
    }
    ExceptionList = local_c;
    return uVar10;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x468060 CollisionBodyWitness::TestForContact

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall CollisionBodyWitness__TestForContact(int param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  float fVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_006864f8;
  local_c = ExceptionList;
  cVar1 = *(char *)((int)*(int **)(param_1 + 600) + 0x15);
  if (((((cVar1 != '\x04') || (cVar2 = *(char *)(*(int *)(param_1 + 0x25c) + 0x15), cVar2 == '\0'))
       || (cVar2 == '\x01')) &&
      (((*(char *)(*(int *)(param_1 + 0x25c) + 0x15) != '\x04' || (cVar1 == '\0')) ||
       (cVar1 == '\x01')))) &&
     ((ExceptionList = &local_c, iVar6 = (**(code **)(**(int **)(param_1 + 600) + 0x50))(),
      iVar6 != 0 && (iVar6 = (**(code **)(**(int **)(param_1 + 0x25c) + 0x50))(), iVar6 != 0)))) {
    iVar6 = *(int *)(param_1 + 0x264);
    uVar7 = 0;
    if (iVar6 != 0) {
      fVar5 = (float)(DAT_0073ad34 - *(int *)(iVar6 + 8)) * 0.00025;
      uVar7 = CONCAT22((short)((uint)iVar6 >> 0x10),
                       (ushort)(fVar5 < 0.05) << 8 | (ushort)NAN(fVar5) << 10 |
                       (ushort)(fVar5 == 0.05) << 0xe);
      if (fVar5 >= 0.05 && (fVar5 == 0.05) == 0) {
        uVar7 = CONCAT31((int3)((uint)uVar7 >> 8),1);
      }
    }
    CollisionBodyWitness_UpdatePolygonSideFlag(uVar7);
    piVar3 = *(int **)(param_1 + 0x25c);
    piVar4 = *(int **)(param_1 + 600);
    uVar7 = (**(code **)(*piVar3 + 8))();
    uVar8 = (**(code **)(*piVar3 + 0x14))(uVar7);
    (**(code **)(*piVar4 + 8))(uVar8);
    uVar9 = (**(code **)(*piVar4 + 0x14))();
    FUN_00472830(uVar9,uVar8,uVar7);
    FUN_00472950();
    cVar1 = *(char *)(param_1 + 0x15);
    CollisionBodyWitness_ClearPolygonSideFlag();
    if (cVar1 != '\0') {
      iVar6 = (**(code **)(**(int **)(param_1 + 600) + 0x68))();
      if ((((iVar6 == 0) &&
           (iVar6 = (**(code **)(**(int **)(param_1 + 0x25c) + 0x68))(), iVar6 == 0)) ||
          (iVar6 = *(int *)(param_1 + 600), *(char *)(iVar6 + 0x16) == '\0')) ||
         (*(char *)(*(int *)(param_1 + 0x25c) + 0x16) == '\0')) {
        if (*(char *)(*(int *)(param_1 + 600) + 0x15) == '\0') {
          uVar10 = IsYawControlInducingCollisionBody();
          if ((int)uVar10 != 0) {
            *(int *)((int)((ulonglong)uVar10 >> 0x20) + 0x14c) = DAT_0073ad34;
          }
          *(int *)(*(int *)(param_1 + 600) + 0x144) = DAT_0073ad34;
        }
        if (*(char *)(*(int *)(param_1 + 0x25c) + 0x15) == '\0') {
          uVar10 = IsYawControlInducingCollisionBody();
          if ((int)uVar10 != 0) {
            *(int *)((int)((ulonglong)uVar10 >> 0x20) + 0x14c) = DAT_0073ad34;
          }
          *(int *)(*(int *)(param_1 + 0x25c) + 0x144) = DAT_0073ad34;
        }
        iVar6 = FUN_00567160();
        uStack_4 = 0;
        if (iVar6 != 0) {
          FUN_0046ae40();
        }
        uStack_4 = 0xffffffff;
        FUN_00564940(param_2,FUN_0046adc0);
      }
      else {
        if (*(char *)(iVar6 + 0x15) == '\0') {
          *(int *)(iVar6 + 0x148) = DAT_0073ad34;
        }
        if (*(char *)(*(int *)(param_1 + 0x25c) + 0x15) == '\0') {
          *(int *)(*(int *)(param_1 + 0x25c) + 0x148) = DAT_0073ad34;
          ExceptionList = local_c;
          return;
        }
      }
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x4682c0 CollisionBodyWitness::EliminateAllWitnesses

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void CollisionBodyWitness__EliminateAllWitnesses(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_00779be0;
  if ((undefined4 **)DAT_00779be0 != &DAT_00779be0) {
    do {
      if ((puVar1 != (undefined4 *)0x0) && (puVar1 + -0x94 != (undefined4 *)0x0)) {
        (**(code **)puVar1[-0x94])(1);
        puVar1 = DAT_00779be0;
      }
    } while ((undefined4 **)puVar1 != &DAT_00779be0);
  }
  return;
}


// ==== 0x468300 CollisionBodyWitness::DoesWitnessExist

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

uint __fastcall CollisionBodyWitness__DoesWitnessExist(int param_1)

{
  int in_EAX;
  int iVar1;
  
  if ((-1 < *(short *)(in_EAX + 0x18)) && (-1 < *(short *)(param_1 + 0x18))) {
    iVar1 = *(short *)(in_EAX + 0x18) * 0xde + (int)*(short *)(param_1 + 0x18);
    return 1 << ((byte)iVar1 & 7) & (uint)*(byte *)((iVar1 >> 3) + DAT_0072cbfc);
  }
  return 0;
}


// ==== 0x468340 CollisionBody::CollisionBody

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 * CollisionBody__CollisionBody(undefined4 *param_1,undefined1 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_EAX;
  
  *param_1 = &PTR_CollisionBody___CollisionBody_006c86a8;
  *(short *)(param_1 + 6) = (short)in_EAX;
  *(undefined1 *)((int)param_1 + 0x15) = param_2;
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[3] = &DAT_007377f0;
  if (-1 < in_EAX) {
    NumberAllocator__AllocateNumber();
    *(undefined4 **)(DAT_00736050 + *(short *)(param_1 + 6) * 4) = param_1;
  }
  DAT_00736008 = DAT_00736008 + 1;
  if (DAT_00736030 < DAT_00736008) {
    DAT_00736030 = DAT_00736008;
  }
  param_1[9] = 0xcb18967f;
  param_1[10] = 0xcb18967f;
  param_1[0xb] = 0xcb18967f;
  param_1[0xc] = 0xcb18967f;
  *(undefined1 *)(param_1 + 0xd) = 0;
  param_1[0x17] = 0;
  iVar3 = (int)DAT_00779c70;
  piVar1 = param_1 + 1;
  piVar2 = (int *)((int)DAT_00779c70 + 4);
  DAT_00779c70 = piVar1;
  *piVar2 = (int)piVar1;
  param_1[2] = &DAT_00779c70;
  *piVar1 = iVar3;
  *(undefined1 *)((int)param_1 + 0x1b) = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  *(undefined1 *)((int)param_1 + 0x1a) = 0;
  *(undefined1 *)((int)param_1 + 0x1d) = 0;
  return param_1;
}


// ==== 0x4683f0 CollisionBody::_CollisionBody

/* [canon] car med (ghidra-canon+nfsug) docs/re/canon.md */

void * __thiscall CollisionBody___CollisionBody(void *param_1,byte param_2)

{
  CollisionBody___CollisionBody();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x468410 CollisionBody::_CollisionBody

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void __fastcall CollisionBody___CollisionBody(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  *param_1 = &PTR_CollisionBody___CollisionBody_006c86a8;
  DAT_00736008 = DAT_00736008 + -1;
  CollisionBody__UpdateMaxCollisionBodyWidth(0);
  iVar1 = param_1[1];
  piVar2 = (int *)param_1[2];
  *piVar2 = iVar1;
  *(int **)(iVar1 + 4) = piVar2;
  if (*(char *)((int)param_1 + 0x1a) != '\0') {
    if (DAT_00779be0 == 0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      puVar6 = (undefined4 *)(DAT_00779be0 + -0x250);
    }
    puVar4 = (undefined4 *)FUN_00421970();
    while (puVar3 = puVar6, puVar3 != puVar4) {
      if (puVar3[0x94] == 0) {
        puVar6 = (undefined4 *)0x0;
      }
      else {
        puVar6 = (undefined4 *)(puVar3[0x94] + -0x250);
      }
      if (((undefined4 *)puVar3[0x96] == param_1) || ((undefined4 *)puVar3[0x97] == param_1)) {
        (**(code **)*puVar3)(1);
      }
    }
  }
  if (-1 < *(short *)(param_1 + 6)) {
    *(undefined4 *)(DAT_00736050 + *(short *)(param_1 + 6) * 4) = 0;
    iVar1 = DAT_00736070;
    iVar5 = (int)*(short *)(param_1 + 6);
    *(byte *)(*(int *)(DAT_00736070 + 4) + (iVar5 >> 3)) =
         *(byte *)(*(int *)(DAT_00736070 + 4) + (iVar5 >> 3)) &
         ~('\x01' << ((byte)*(short *)(param_1 + 6) & 7));
    if (iVar5 < *(int *)(iVar1 + 8)) {
      *(int *)(iVar1 + 8) = iVar5;
    }
  }
  return;
}


// ==== 0x4684f0 CollisionBody::DoSnapshot

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall CollisionBody__DoSnapshot(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_2;
  if (*(char *)(param_2 + 0x3d) == '\0') {
    param_2 = CONCAT31(param_2._1_3_,*(char *)(param_1 + 0x1d) * '\x10' + *(char *)(param_1 + 0x1b))
    ;
    FUN_00571c20(iVar1,&param_2,1,1,0);
  }
  else {
    FUN_00571c20(param_2,&param_2,1,1,0);
    *(byte *)(param_1 + 0x1d) = (byte)param_2 >> 4;
    *(byte *)(param_1 + 0x1b) = (byte)param_2 & 0xf;
  }
  if ((*(char *)(iVar1 + 0x3e) != '\0') || (*(char *)(iVar1 + 0x3f) != '\0')) {
    FUN_00571c20(iVar1,param_1 + 0x18,2,2,1);
  }
  if ((*(char *)(iVar1 + 0x3e) != '\0') || (*(char *)(iVar1 + 0x3f) != '\0')) {
    FUN_00571c20(iVar1,param_1 + 0x15,1,1,1);
  }
  if ((*(char *)(iVar1 + 0x3e) != '\0') || (*(char *)(iVar1 + 0x3f) != '\0')) {
    FUN_00571c20(iVar1,param_1 + 0x16,1,1,1);
  }
  return;
}


// ==== 0x4685a0 CollisionBody::UpdateMaxCollisionBodyWidth

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void CollisionBody__UpdateMaxCollisionBodyWidth(float param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  
  fVar1 = *(float *)(unaff_EDI + 0x2c) - *(float *)(unaff_EDI + 0x24);
  if (param_1 != fVar1) {
    if ((fVar1 < param_1) && (_DAT_00736054 < param_1)) {
      _DAT_00736054 = param_1;
      return;
    }
    if ((param_1 < fVar1) && (fVar1 == _DAT_00736054)) {
      param_1 = 0.0;
      if (DAT_00779c70 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = DAT_00779c70 + -4;
      }
      iVar2 = Ptr_BaseAdjustMinus4();
      _DAT_00736054 = param_1;
      while (iVar3 != iVar2) {
        param_1 = _DAT_00736054;
        if ((iVar3 != unaff_EDI) &&
           (fVar1 = *(float *)(iVar3 + 0x2c) - *(float *)(iVar3 + 0x24), param_1 = _DAT_00736054,
           _DAT_00736054 < fVar1)) {
          param_1 = fVar1;
        }
        _DAT_00736054 = param_1;
        if (*(int *)(iVar3 + 4) == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(iVar3 + 4) + -4;
        }
      }
    }
  }
  return;
}


// ==== 0x468680 CollisionBody::SetBBoxMinMax

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void CollisionBody__SetBBoxMinMax(int param_1,float *param_2)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float *in_EAX;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  CollisionBody__UpdateMaxCollisionBodyWidth(*in_EAX - *param_2);
  fVar2 = *(float *)(param_1 + 0x2c);
  fVar3 = param_2[1];
  *(float *)(param_1 + 0x24) = *param_2;
  *(float *)(param_1 + 0x28) = fVar3;
  fVar3 = *in_EAX;
  *(float *)(param_1 + 0x30) = in_EAX[1];
  *(float *)(param_1 + 0x2c) = fVar3;
  if (fVar2 == *in_EAX) {
    return;
  }
  iVar4 = Ptr_BaseAdjustMinus4();
  piVar1 = (int *)(param_1 + 4);
  do {
    while( true ) {
      if (*(int *)(param_1 + 8) == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(param_1 + 8) + -4;
      }
      if (*piVar1 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = *piVar1 + -4;
      }
      if (iVar5 != iVar4) break;
LAB_0046876c:
      if (iVar9 == iVar4) {
        return;
      }
      if (iVar9 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = iVar9 + 4;
      }
      iVar8 = param_1;
      if (piVar1 == (int *)0x0) {
        iVar8 = 0;
      }
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = iVar5 + -4;
      }
      if (*(float *)(iVar8 + 0x2c) <= *(float *)(iVar5 + 0x2c)) {
        if (*(float *)(iVar8 + 0x2c) < *(float *)(iVar5 + 0x2c)) {
          return;
        }
        if (*(short *)(iVar8 + 0x18) <= *(short *)(iVar5 + 0x18)) {
          return;
        }
      }
      iVar5 = *piVar1;
      piVar6 = *(int **)(param_1 + 8);
      *piVar6 = iVar5;
      *(int **)(iVar5 + 4) = piVar6;
      if (iVar9 == 0) {
        piVar6 = (int *)0x0;
      }
      else {
        piVar6 = (int *)(iVar9 + 4);
      }
      iVar5 = *piVar6;
      *piVar6 = (int)piVar1;
      *(int **)(iVar5 + 4) = piVar1;
      *(int **)(param_1 + 8) = piVar6;
      *piVar1 = iVar5;
    }
    if ((iVar5 == 0) || (iVar8 = iVar5, iVar5 == -4)) {
      iVar8 = 0;
    }
    iVar7 = param_1;
    if (piVar1 == (int *)0x0) {
      iVar7 = 0;
    }
    if ((*(float *)(iVar8 + 0x2c) <= *(float *)(iVar7 + 0x2c)) &&
       ((*(float *)(iVar8 + 0x2c) < *(float *)(iVar7 + 0x2c) ||
        (*(short *)(iVar8 + 0x18) <= *(short *)(iVar7 + 0x18))))) goto LAB_0046876c;
    iVar9 = *piVar1;
    piVar6 = *(int **)(param_1 + 8);
    *piVar6 = iVar9;
    *(int **)(iVar9 + 4) = piVar6;
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = iVar5 + 4;
    }
    piVar6 = *(int **)(iVar5 + 4);
    *piVar6 = (int)piVar1;
    *(int **)(iVar5 + 4) = piVar1;
    *(int **)(param_1 + 8) = piVar6;
    *piVar1 = iVar5;
  } while( true );
}


// ==== 0x468800 CarBody_DisableCountInc

/* [canon] traffic low (H+G) docs/re/traffic.md */

void CarBody_DisableCountInc(void)

{
  int in_EAX;
  
  *(char *)(in_EAX + 0x1b) = *(char *)(in_EAX + 0x1b) + '\x01';
  return;
}


// ==== 0x468810 CollisionBody::EnableCollisions

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void __fastcall CollisionBody__EnableCollisions(int param_1)

{
  if (*(char *)(param_1 + 0x1b) != '\0') {
    *(char *)(param_1 + 0x1b) = *(char *)(param_1 + 0x1b) + -1;
  }
  return;
}


// ==== 0x468820 CollisionBody::GetCollision

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 CollisionBody__GetCollision(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  
  if (param_1 < *(char *)(unaff_EDI + 0x1c)) {
    iVar2 = 0;
    if (DAT_00779be0 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = DAT_00779be0 + -0x250;
    }
    iVar1 = FUN_00421970();
    while (iVar3 != iVar1) {
      if ((*(int *)(iVar3 + 0x264) != 0) &&
         ((*(int *)(iVar3 + 600) == unaff_EDI || (*(int *)(iVar3 + 0x25c) == unaff_EDI)))) {
        if (iVar2 == param_1) {
          return *(undefined4 *)(iVar3 + 0x264);
        }
        iVar2 = iVar2 + 1;
      }
      if (*(int *)(iVar3 + 0x250) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(iVar3 + 0x250) + -0x250;
      }
    }
  }
  return 0;
}


// ==== 0x4688a0 DynamicCollisionBody::_DynamicCollisionBody

/* [canon] car med (ghidra-canon+nfsug) docs/re/canon.md */

void * __thiscall DynamicCollisionBody___DynamicCollisionBody(void *param_1,byte param_2)

{
  DynamicCollisionBody___DynamicCollisionBody();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4688c0 DynamicCollisionBody::_DynamicCollisionBody

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void __fastcall DynamicCollisionBody___DynamicCollisionBody(undefined4 *param_1)

{
  *param_1 = &PTR_DynamicCollisionBody___DynamicCollisionBody_006c85b8;
  DAT_00736010 = DAT_00736010 + -1;
  CollisionBody___CollisionBody();
  return;
}


// ==== 0x4688e0 DynamicCollisionBody::DoSnapshot

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall DynamicCollisionBody__DoSnapshot(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  
  FUN_00571ea0(param_1,"DynamicCollisionBody");
  CollisionBody__DoSnapshot(param_2);
  FUN_00571c20(param_2,param_1 + 0x60,1,4,0);
  if (*(char *)(param_2 + 0x3c) != '\0' || *(char *)(param_2 + 0x3d) != '\0') {
    FUN_00440740();
  }
  if ((*(char *)(param_2 + 0x3e) != '\0') || (*(char *)(param_2 + 0x3f) != '\0')) {
    FUN_00571c20(param_2,param_1 + 0xe0,4,0xffffffff,0);
  }
  if ((*(char *)(param_2 + 0x3e) != '\0') || (*(char *)(param_2 + 0x3f) != '\0')) {
    FUN_00571c20(param_2,param_1 + 0xe4,4,0xffffffff,0);
  }
  if ((*(char *)(param_2 + 0x3e) != '\0') || (*(char *)(param_2 + 0x3f) != '\0')) {
    FUN_00571c20(param_2,param_1 + 0xe8,4,0xffffffff,0);
  }
  if ((*(char *)(param_2 + 0x3e) != '\0') || (*(char *)(param_2 + 0x3f) != '\0')) {
    FUN_00571c20(param_2,param_1 + 0xf0,0xc,0xffffffff,0);
  }
  if ((*(char *)(param_2 + 0x3e) != '\0') || (*(char *)(param_2 + 0x3f) != '\0')) {
    FUN_00571c20(param_2,param_1 + 0x100,0xc,0xffffffff,0);
  }
  if (*(char *)(param_2 + 0x3c) != '\0' || *(char *)(param_2 + 0x3d) != '\0') {
    *(undefined4 *)(param_1 + 0x70) = 0;
    puVar3 = (undefined4 *)(param_1 + 0x80);
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    *(undefined4 *)(param_1 + 0xc0) = 0;
    *(undefined4 *)(param_1 + 0xc4) = 0;
    *(undefined4 *)(param_1 + 200) = 0;
    *(undefined4 *)(param_1 + 0xcc) = 0;
    *(undefined4 *)(param_1 + 0xd0) = 0;
    *(undefined4 *)(param_1 + 0xd4) = 0;
    *(undefined4 *)(param_1 + 0xd8) = 0;
    *(undefined4 *)(param_1 + 0xdc) = 0;
  }
  iVar2 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar2 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar2 + 0x58 + param_2);
  cVar1 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar1;
  if ((int)cVar1 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x468a50 DynamicCollisionBody::BuildBoundingVolumes

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void DynamicCollisionBody__BuildBoundingVolumes(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int unaff_EDI;
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
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  undefined1 local_50 [16];
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  
  local_80 = 0.0;
  local_98 = 0.0;
  local_84 = 0.0;
  local_90 = 0.0;
  local_88 = 0.0;
  local_9c = 0.0;
  local_78 = 0.0;
  local_94 = 0.0;
  local_7c = 0.0;
  local_8c = 0.0;
  Struct_ClearHeader();
  iVar4 = 0;
  if (0 < *(int *)(*(int *)(unaff_EDI + 0x10) + 0x14)) {
    do {
      (**(code **)(*(int *)(unaff_EDI + 0x10) + 0xc))(*(int *)(unaff_EDI + 0x10),iVar4,local_50);
      fVar2 = fStack_3c * fStack_3c + fStack_40 * fStack_40;
      fVar3 = SQRT(fVar2);
      fVar2 = SQRT(fStack_38 * fStack_38 + fVar2);
      if (local_80 < fVar2) {
        local_80 = fVar2;
      }
      if (local_98 < fVar3) {
        local_98 = fVar3;
      }
      if (fStack_38 <= local_84) {
        if (fStack_38 < local_90) {
          local_90 = fStack_38;
        }
      }
      else {
        local_84 = fStack_38;
      }
      if (fStack_40 <= local_9c) {
        if (fStack_40 < local_88) {
          local_88 = fStack_40;
        }
      }
      else {
        local_9c = fStack_40;
      }
      if (fStack_3c <= local_94) {
        if (fStack_3c < local_78) {
          local_78 = fStack_3c;
        }
      }
      else {
        local_94 = fStack_3c;
      }
      if (fStack_38 <= local_8c) {
        if (fStack_38 < local_7c) {
          local_7c = fStack_38;
        }
      }
      else {
        local_8c = fStack_38;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(*(int *)(unaff_EDI + 0x10) + 0x14));
  }
  iVar4 = *(int *)(unaff_EDI + 0x10);
  *(float *)(unaff_EDI + 0xe8) = local_98 + 0.05;
  *(float *)(unaff_EDI + 0xec) = local_80;
  *(float *)(unaff_EDI + 0xf8) = local_7c;
  *(float *)(unaff_EDI + 0xf0) = local_88;
  *(float *)(unaff_EDI + 0xe4) = local_84 + 0.05;
  *(float *)(unaff_EDI + 0xf4) = local_78;
  *(float *)(unaff_EDI + 0x108) = local_8c;
  *(float *)(unaff_EDI + 0x100) = local_9c;
  *(float *)(unaff_EDI + 0xe0) = 0.05 - local_90;
  *(float *)(unaff_EDI + 0x104) = local_94;
  iVar1 = *(int *)(iVar4 + 0x10);
  if (iVar1 == 1) {
    FUN_004733a0(&fStack_60);
  }
  else if (iVar1 == 3) {
    fStack_60 = *(float *)(iVar4 + 0x20) - *(float *)(iVar4 + 0x30);
    fStack_5c = *(float *)(iVar4 + 0x24) - *(float *)(iVar4 + 0x34);
    fStack_58 = *(float *)(iVar4 + 0x28) - *(float *)(iVar4 + 0x38);
    fStack_70 = *(float *)(iVar4 + 0x20) + *(float *)(iVar4 + 0x30);
    fStack_6c = *(float *)(iVar4 + 0x34) + *(float *)(iVar4 + 0x24);
    fStack_68 = *(float *)(iVar4 + 0x38) + *(float *)(iVar4 + 0x28);
  }
  else if (iVar1 == 4) {
    fStack_5c = *(float *)(iVar4 + 0x34);
    fStack_70 = *(float *)(iVar4 + 0x30);
    fStack_58 = *(float *)(iVar4 + 0x38);
    fStack_6c = *(float *)(iVar4 + 0x34);
    fStack_68 = *(float *)(iVar4 + 0x38);
    fStack_60 = fStack_70;
  }
  *(float *)(unaff_EDI + 0x120) = (fStack_70 + fStack_60) * _K_HALF;
  *(float *)(unaff_EDI + 0x124) = (fStack_6c + fStack_5c) * _K_HALF;
  *(float *)(unaff_EDI + 0x128) = (fStack_68 + fStack_58) * _K_HALF;
  return;
}


// ==== 0x468d70 DynamicCollisionBody::UpdateProjectedBBox

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void DynamicCollisionBody__UpdateProjectedBBox(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  int *unaff_ESI;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  
  pfVar4 = (float *)(**(code **)(*unaff_ESI + 8))();
  pfVar5 = (float *)(**(code **)(*unaff_ESI + 0xc))();
  pfVar6 = (float *)(**(code **)(*unaff_ESI + 0x10))();
  fVar1 = param_1 * *pfVar5;
  fVar2 = pfVar5[1] * param_1;
  if (DAT_00736084 != 0) {
    fVar3 = param_1 * param_1 * _K_HALF;
    fVar1 = fVar3 * *pfVar6 + fVar1;
    fVar2 = pfVar6[1] * fVar3 + fVar2;
  }
  fStack_28 = (fVar1 + *pfVar4) - (float)unaff_ESI[0x3a];
  if (*pfVar4 - (float)unaff_ESI[0x3a] < fStack_28) {
    fStack_28 = *pfVar4 - (float)unaff_ESI[0x3a];
  }
  fStack_24 = (fVar2 + pfVar4[1]) - (float)unaff_ESI[0x3a];
  if (pfVar4[1] - (float)unaff_ESI[0x3a] < fStack_24) {
    fStack_24 = pfVar4[1] - (float)unaff_ESI[0x3a];
  }
  fStack_20 = fVar1 + *pfVar4 + (float)unaff_ESI[0x3a];
  if (fStack_20 < *pfVar4 + (float)unaff_ESI[0x3a]) {
    fStack_20 = *pfVar4 + (float)unaff_ESI[0x3a];
  }
  fStack_1c = fVar2 + pfVar4[1] + (float)unaff_ESI[0x3a];
  if (fStack_1c < (float)unaff_ESI[0x3a] + pfVar4[1]) {
    fStack_1c = (float)unaff_ESI[0x3a] + pfVar4[1];
  }
  CollisionBody__SetBBoxMinMax(unaff_ESI,&fStack_28);
  return;
}


// ==== 0x468ec0 DynamicCollisionBody::UpdatePosition

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void DynamicCollisionBody__UpdatePosition(void)

{
  float *pfVar1;
  int *unaff_ESI;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  undefined1 auStack_20 [28];
  
  pfVar1 = (float *)(**(code **)(*unaff_ESI + 8))();
  fStack_30 = *pfVar1 - (float)unaff_ESI[0x3a];
  fStack_2c = pfVar1[1] - (float)unaff_ESI[0x3a];
  fStack_28 = (float)unaff_ESI[0x3a] + *pfVar1;
  fStack_24 = pfVar1[1] + (float)unaff_ESI[0x3a];
  CollisionBody__SetBBoxMinMax(unaff_ESI,&fStack_30);
  D3DXVec3Transform(auStack_20,unaff_ESI + 0x48,unaff_ESI + 0x20);
  unaff_ESI[0x44] = (int)(fStack_2c + (float)unaff_ESI[0x30]);
  unaff_ESI[0x46] = (int)((float)unaff_ESI[0x32] + fStack_24);
  unaff_ESI[0x45] = (int)((float)unaff_ESI[0x31] + fStack_28);
  return;
}


// ==== 0x468f70 DynamicCollisionBody::BeginMove

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void DynamicCollisionBody__BeginMove(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *unaff_ESI;
  
  (**(code **)(*unaff_ESI + 0x14))();
  bMatrixCopy_b();
  piVar3 = (int *)(**(code **)(*unaff_ESI + 8))();
  iVar1 = piVar3[1];
  iVar2 = piVar3[2];
  unaff_ESI[0x30] = *piVar3;
  unaff_ESI[0x31] = iVar1;
  unaff_ESI[0x32] = iVar2;
  piVar3 = (int *)(**(code **)(*unaff_ESI + 0xc))();
  iVar1 = piVar3[2];
  iVar2 = *piVar3;
  unaff_ESI[0x35] = piVar3[1];
  unaff_ESI[0x34] = iVar2;
  unaff_ESI[0x36] = iVar1;
  unaff_ESI[0x1c] = param_1;
  return;
}


// ==== 0x468fe0 DynamicCollisionBody::Interpolate

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall
DynamicCollisionBody__Interpolate(int *param_1,float *param_2,float *param_3,float param_4)

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
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  float *pfVar40;
  float *pfVar41;
  
  pfVar40 = (float *)(**(code **)(*param_1 + 8))();
  pfVar41 = (float *)(**(code **)(*param_1 + 0x14))();
  if ((float)param_1[0x1c] < 1e-06) {
    fVar1 = pfVar40[1];
    fVar2 = pfVar40[2];
    *param_2 = *pfVar40;
    param_2[1] = fVar1;
    param_2[2] = fVar2;
    bMatrixCopy_b();
    return;
  }
  fVar39 = ((float)param_1[0x1c] - param_4) / (float)param_1[0x1c];
  fVar1 = pfVar40[1];
  fVar2 = (float)param_1[0x31];
  fVar3 = pfVar40[2];
  fVar4 = (float)param_1[0x32];
  fVar5 = *pfVar41;
  fVar6 = (float)param_1[0x20];
  fVar7 = pfVar41[1];
  fVar8 = (float)param_1[0x21];
  fVar9 = pfVar41[2];
  fVar10 = (float)param_1[0x22];
  fVar11 = pfVar41[3];
  fVar12 = (float)param_1[0x23];
  fVar13 = pfVar41[4];
  fVar14 = (float)param_1[0x24];
  fVar15 = pfVar41[5];
  fVar16 = (float)param_1[0x25];
  fVar17 = pfVar41[6];
  fVar18 = (float)param_1[0x26];
  fVar19 = pfVar41[7];
  fVar20 = (float)param_1[0x27];
  fVar21 = pfVar41[8];
  fVar22 = (float)param_1[0x28];
  fVar23 = pfVar41[9];
  fVar24 = (float)param_1[0x29];
  fVar25 = pfVar41[10];
  fVar26 = (float)param_1[0x2a];
  fVar27 = pfVar41[0xb];
  fVar28 = (float)param_1[0x2b];
  fVar29 = pfVar41[0xc];
  fVar30 = (float)param_1[0x2c];
  fVar31 = pfVar41[0xd];
  fVar32 = (float)param_1[0x2d];
  fVar33 = pfVar41[0xe];
  fVar34 = (float)param_1[0x2e];
  fVar35 = pfVar41[0xf];
  fVar36 = (float)param_1[0x2f];
  fVar37 = (float)param_1[0x31];
  fVar38 = (float)param_1[0x32];
  *param_2 = (*pfVar40 - (float)param_1[0x30]) * fVar39 + (float)param_1[0x30];
  param_2[1] = (fVar1 - fVar2) * fVar39 + fVar37;
  param_2[2] = (fVar3 - fVar4) * fVar39 + fVar38;
  fVar2 = (float)param_1[0x22];
  fVar3 = (float)param_1[0x23];
  fVar1 = (float)param_1[0x21];
  *param_3 = (fVar5 - fVar6) * fVar39 + (float)param_1[0x20];
  param_3[1] = (fVar7 - fVar8) * fVar39 + fVar1;
  param_3[2] = (fVar9 - fVar10) * fVar39 + fVar2;
  param_3[3] = (fVar11 - fVar12) * fVar39 + fVar3;
  fVar2 = (float)param_1[0x26];
  fVar3 = (float)param_1[0x27];
  fVar1 = (float)param_1[0x25];
  param_3[4] = (fVar13 - fVar14) * fVar39 + (float)param_1[0x24];
  param_3[5] = (fVar15 - fVar16) * fVar39 + fVar1;
  param_3[6] = (fVar17 - fVar18) * fVar39 + fVar2;
  param_3[7] = (fVar19 - fVar20) * fVar39 + fVar3;
  fVar2 = (float)param_1[0x2a];
  fVar3 = (float)param_1[0x2b];
  fVar1 = (float)param_1[0x29];
  param_3[8] = (fVar21 - fVar22) * fVar39 + (float)param_1[0x28];
  param_3[9] = (fVar23 - fVar24) * fVar39 + fVar1;
  param_3[10] = (fVar25 - fVar26) * fVar39 + fVar2;
  param_3[0xb] = (fVar27 - fVar28) * fVar39 + fVar3;
  fVar1 = (float)param_1[0x2d];
  fVar2 = (float)param_1[0x2e];
  fVar3 = (float)param_1[0x2f];
  param_3[0xc] = (fVar29 - fVar30) * fVar39 + (float)param_1[0x2c];
  param_3[0xd] = (fVar31 - fVar32) * fVar39 + fVar1;
  param_3[0xe] = (fVar33 - fVar34) * fVar39 + fVar2;
  param_3[0xf] = (fVar35 - fVar36) * fVar39 + fVar3;
  return;
}


// ==== 0x4692f0 DynamicCollisionBody::InterpolateVelocity

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void DynamicCollisionBody__InterpolateVelocity(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  int *unaff_ESI;
  float *unaff_EDI;
  
  if ((float)unaff_ESI[0x1c] < 1e-06) {
    pfVar8 = (float *)(**(code **)(*unaff_ESI + 0xc))();
    fVar1 = pfVar8[1];
    fVar2 = pfVar8[2];
    *unaff_EDI = *pfVar8;
    unaff_EDI[1] = fVar1;
    unaff_EDI[2] = fVar2;
    return;
  }
  fVar7 = ((float)unaff_ESI[0x1c] - param_1) / (float)unaff_ESI[0x1c];
  pfVar8 = (float *)(**(code **)(*unaff_ESI + 0xc))();
  fVar1 = pfVar8[1];
  fVar2 = (float)unaff_ESI[0x35];
  fVar3 = pfVar8[2];
  fVar4 = (float)unaff_ESI[0x36];
  fVar5 = (float)unaff_ESI[0x35];
  fVar6 = (float)unaff_ESI[0x36];
  *unaff_EDI = (*pfVar8 - (float)unaff_ESI[0x34]) * fVar7 + (float)unaff_ESI[0x34];
  unaff_EDI[1] = (fVar1 - fVar2) * fVar7 + fVar5;
  unaff_EDI[2] = (fVar3 - fVar4) * fVar7 + fVar6;
  return;
}


// ==== 0x469390 DynamicCollisionBody::Backup

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall DynamicCollisionBody__Backup(int *param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  float unaff_EBX;
  float unaff_ESI;
  float fStack_74;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 local_60 [4];
  undefined1 auStack_5c [12];
  undefined1 local_50 [76];
  
  (**(code **)(*param_1 + 0x30))(local_60,local_50,param_2);
  DynamicCollisionBody__InterpolateVelocity(param_2);
  iVar2 = param_1[0x1b];
  if (iVar2 != 0) {
    fVar1 = *(float *)(iVar2 + 0x144);
    *(undefined4 *)(iVar2 + 0x20) = uStack_6c;
    *(undefined4 *)(iVar2 + 0x24) = uStack_68;
    *(undefined4 *)(iVar2 + 0x28) = uStack_64;
    bMatrixCopy_b();
    iVar2 = param_1[0x1b];
    *(float *)(iVar2 + 0x74) = unaff_EBX * fVar1;
    *(float *)(iVar2 + 0x70) = unaff_ESI * fVar1;
    *(float *)(iVar2 + 0x78) = fStack_74 * fVar1;
    return;
  }
  (**(code **)(*param_1 + 0x74))(param_2,&uStack_6c,auStack_5c,&stack0xffffff84);
  return;
}


// ==== 0x469460 DynamicCollisionBody::RecomputeAuxilliaries

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void __fastcall DynamicCollisionBody__RecomputeAuxilliaries(int param_1)

{
  if (*(int *)(param_1 + 0x60) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0046946c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x68) + 4))();
    return;
  }
  return;
}


// ==== 0x469470 DynamicCollisionBody::GetCurrentVelocities

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall
DynamicCollisionBody__GetCurrentVelocities(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  if (param_1[0x18] != 0) {
    iVar2 = param_1[0x1b];
    uVar3 = *(undefined4 *)(iVar2 + 0xa0);
    uVar1 = *(undefined4 *)(iVar2 + 0xa8);
    param_2[1] = *(undefined4 *)(iVar2 + 0xa4);
    *param_2 = uVar3;
    param_2[2] = uVar1;
    iVar2 = param_1[0x1b];
    uVar3 = *(undefined4 *)(iVar2 + 0xc0);
    uVar1 = *(undefined4 *)(iVar2 + 200);
    param_3[1] = *(undefined4 *)(iVar2 + 0xc4);
    *param_3 = uVar3;
    param_3[2] = uVar1;
    return;
  }
  puVar4 = (undefined4 *)(**(code **)(*param_1 + 0xc))();
  uVar1 = puVar4[2];
  uVar3 = *puVar4;
  param_2[1] = puVar4[1];
  *param_2 = uVar3;
  param_2[2] = uVar1;
  puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x18))();
  uVar1 = puVar4[2];
  uVar3 = *puVar4;
  param_3[1] = puVar4[1];
  *param_3 = uVar3;
  param_3[2] = uVar1;
  return;
}


// ==== 0x469510 DynamicCollisionBody::GetTestImpulseVelocities

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall
DynamicCollisionBody__GetTestImpulseVelocities(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (param_1[0x18] != 0) {
    FUN_005850a0(param_3);
    return;
  }
  puVar3 = (undefined4 *)(**(code **)(*param_1 + 0xc))();
  uVar1 = puVar3[2];
  uVar2 = *puVar3;
  param_2[1] = puVar3[1];
  *param_2 = uVar2;
  param_2[2] = uVar1;
  puVar3 = (undefined4 *)(**(code **)(*param_1 + 0x18))();
  uVar1 = puVar3[2];
  uVar2 = *puVar3;
  param_3[1] = puVar3[1];
  *param_3 = uVar2;
  param_3[2] = uVar1;
  return;
}


// ==== 0x469580 WorldObjects::Broadphase

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] props high (hopper+ghidra) docs/re/props.md */

void WorldObjects__Broadphase(int *param_1)

{
  float *pfVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar3 = param_1;
  iVar4 = (**(code **)(*param_1 + 0x50))();
  if (iVar4 != 0) {
    DynamicCollisionBody__CreateTrackPolygonCollisionBodies();
    fVar2 = (float)param_1[9];
    if (param_1[2] == 0) {
      piVar7 = (int *)0x0;
    }
    else {
      piVar7 = (int *)(param_1[2] + -4);
    }
    piVar5 = (int *)Ptr_BaseAdjustMinus4();
    while ((piVar7 != piVar5 && (fVar2 <= (float)piVar7[0xb]))) {
      if (piVar7[2] == 0) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = (int *)(piVar7[2] + -4);
      }
    }
    pfVar1 = (float *)(param_1 + 0xb);
    if (param_1[1] == 0) {
      param_1 = (int *)0x0;
    }
    else {
      param_1 = (int *)(param_1[1] + -4);
    }
    while ((param_1 != piVar5 &&
           ((float)param_1[0xb] < _DAT_00736054 + *pfVar1 !=
            ((float)param_1[0xb] == _DAT_00736054 + *pfVar1)))) {
      if (param_1[1] == 0) {
        param_1 = (int *)0x0;
      }
      else {
        param_1 = (int *)(param_1[1] + -4);
      }
    }
    piVar5 = (int *)0x0;
    if (piVar7 == (int *)0x779c6c) {
      if (DAT_00779c70 != 0) {
        piVar5 = (int *)(DAT_00779c70 + -4);
      }
    }
    else if (piVar7[1] != 0) {
      piVar5 = (int *)(piVar7[1] + -4);
    }
    while (piVar7 = piVar5, piVar7 != param_1) {
      if (piVar7[1] == 0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)(piVar7[1] + -4);
      }
      if ((((piVar7 != piVar3) &&
           ((float)piVar3[9] < (float)piVar7[0xb] != ((float)piVar3[9] == (float)piVar7[0xb]))) &&
          ((float)piVar7[9] <= (float)piVar3[0xb])) &&
         (((((float)piVar3[10] < (float)piVar7[0xc] != ((float)piVar3[10] == (float)piVar7[0xc]) &&
            ((float)piVar7[10] <= (float)piVar3[0xc])) &&
           (((short)piVar3[6] < 0 ||
            (((short)piVar7[6] < 0 ||
             (iVar4 = (short)piVar3[6] * 0xde + (int)(short)piVar7[6],
             (1 << ((byte)iVar4 & 7) & (uint)*(byte *)((iVar4 >> 3) + DAT_0072cbfc)) == 0)))))) &&
          (iVar4 = (**(code **)(*piVar7 + 0x50))(), iVar4 != 0)))) {
        piVar6 = piVar7;
        if (*(char *)((int)piVar7 + 0x15) == '\x02') {
          piVar6 = (int *)VirginSmokeable__Wake();
          (**(code **)*piVar7)(1);
        }
        if (((piVar6 != (int *)0x0) && (iVar4 = CollisionBody_BBoxesOverlap(0), iVar4 != 0)) &&
           (iVar4 = FUN_00567160(), iVar4 != 0)) {
          CollisionBodyWitness__CollisionBodyWitness(piVar6);
        }
      }
    }
  }
  return;
}


// ==== 0x469770 DynamicCollisionBody::MaybeCreateWitness

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 * DynamicCollisionBody__MaybeCreateWitness(void)

{
  int *in_EAX;
  int iVar1;
  int *unaff_EBX;
  undefined4 *puVar2;
  
  iVar1 = (**(code **)(*unaff_EBX + 0x50))();
  if (iVar1 == 0) {
    return (undefined4 *)0x0;
  }
  puVar2 = (undefined4 *)0x0;
  iVar1 = CollisionBody_BBoxesOverlap(0);
  if (((iVar1 != 0) && (iVar1 = CollisionBodyWitness__DoesWitnessExist(), iVar1 == 0)) &&
     (iVar1 = (**(code **)(*in_EAX + 0x50))(), iVar1 != 0)) {
    if (*(char *)((int)in_EAX + 0x15) == '\x02') {
      in_EAX = (int *)FUN_005962c0();
      if (in_EAX == (int *)0x0) {
        return (undefined4 *)0x0;
      }
      iVar1 = CollisionBody_BBoxesOverlap(0);
      if (iVar1 == 0) {
        return (undefined4 *)0x0;
      }
    }
    iVar1 = FUN_00567160();
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)CollisionBodyWitness__CollisionBodyWitness(in_EAX);
    }
    iVar1 = CollisionBodyWitness__HasExpired();
    if (iVar1 != 0) {
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)*puVar2)(1);
      }
      puVar2 = (undefined4 *)0x0;
    }
  }
  return puVar2;
}


// ==== 0x469810 DynamicCollisionBody::CreateTrackPolygonCollisionBodies

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

int __fastcall DynamicCollisionBody__CreateTrackPolygonCollisionBodies(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int local_e0;
  int local_dc;
  int aiStack_cc [48];
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006864db;
  local_c = ExceptionList;
  iVar6 = *(int *)(*(int *)(param_1 + 100) + 0x2a0);
  local_e0 = 0;
  if (0 < iVar6) {
    iVar7 = 0x20;
    ExceptionList = &local_c;
    do {
      iVar5 = *(int *)(*(int *)(param_1 + 100) + iVar7);
      if (((((*(int *)(iVar5 + 0x10) == 0) &&
            (*(float *)(param_1 + 0x24) < *(float *)(iVar5 + 0x1c) !=
             (*(float *)(param_1 + 0x24) == *(float *)(iVar5 + 0x1c)))) &&
           (*(float *)(iVar5 + 0x14) <= *(float *)(param_1 + 0x2c))) &&
          ((*(float *)(param_1 + 0x28) < *(float *)(iVar5 + 0x20) !=
            (*(float *)(param_1 + 0x28) == *(float *)(iVar5 + 0x20)) &&
           (*(float *)(iVar5 + 0x18) <= *(float *)(param_1 + 0x30))))) &&
         ((iVar4 = DynamicCollisionBody__TrackPolygonCheck(), iVar4 != 0 && (local_e0 < 0x30)))) {
        aiStack_cc[local_e0] = iVar5;
        local_e0 = local_e0 + 1;
      }
      iVar7 = iVar7 + 4;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    if (local_e0 != 0) {
      do {
        iVar7 = 0;
        iVar6 = 0;
        if (local_e0 + -1 < 1) break;
        do {
          iVar5 = aiStack_cc[iVar6];
          if (*(uint *)(aiStack_cc[iVar6 + 1] + 0xc) < *(uint *)(iVar5 + 0xc)) {
            aiStack_cc[iVar6] = aiStack_cc[iVar6 + 1];
            aiStack_cc[iVar6 + 1] = iVar5;
            iVar7 = iVar7 + 1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < local_e0 + -1);
      } while (iVar7 != 0);
      local_dc = 0;
      iVar6 = DAT_0072cbf4;
      if (local_e0 < 1) {
        ExceptionList = local_c;
        return local_e0;
      }
      do {
        if (*(int *)(iVar6 + 0x18) == *(int *)(iVar6 + 0x2c)) {
          ExceptionList = local_c;
          return local_dc;
        }
        uVar2 = *(undefined4 *)(aiStack_cc[local_dc] + 0xc);
        uVar1 = *(undefined2 *)(DAT_00736070 + 8);
        piVar8 = (int *)(iVar6 + 0x10);
        iVar7 = iVar6;
        if ((*piVar8 == 0) && ((*(byte *)(iVar6 + 0x14) & 1) != 0)) {
          FUN_00566e60();
          iVar7 = DAT_0072cbf4;
        }
        piVar3 = (int *)*piVar8;
        iVar5 = *(int *)(iVar6 + 0x18) + 1;
        if (piVar3 != (int *)0x0) {
          iVar4 = *piVar3;
          if (*(int *)(iVar6 + 0x1c) < iVar5) {
            *(int *)(iVar6 + 0x1c) = iVar5;
          }
          *(int *)(iVar6 + 0x18) = iVar5;
          *piVar8 = iVar4;
          if (((*(byte *)(iVar6 + 0x14) & 2) != 0) &&
             (iVar6 = *(int *)(iVar6 + 0x28) >> 2, piVar8 = piVar3, 0 < iVar6)) {
            for (; iVar6 != 0; iVar6 = iVar6 + -1) {
              *piVar8 = 0;
              piVar8 = piVar8 + 1;
            }
          }
        }
        local_4 = 0;
        if (piVar3 != (int *)0x0) {
          FUN_0046a440(piVar3,uVar1,uVar2);
          iVar7 = DAT_0072cbf4;
        }
        local_dc = local_dc + 1;
        local_4 = 0xffffffff;
        iVar6 = iVar7;
      } while (local_dc < local_e0);
      ExceptionList = local_c;
      return local_e0;
    }
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x469a00 DynamicCollisionBody::TrackPolygonCheck

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

bool DynamicCollisionBody__TrackPolygonCheck(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float *pfVar6;
  int unaff_ESI;
  int *unaff_EDI;
  float local_8;
  
  fVar1 = (float)unaff_EDI[0x38];
  fVar2 = (float)unaff_EDI[0x3a];
  iVar5 = (**(code **)(*unaff_EDI + 0x14))();
  local_8 = *(float *)(iVar5 + 0x20) * *(float *)(unaff_ESI + 0x70) +
            *(float *)(iVar5 + 0x24) * *(float *)(unaff_ESI + 0x74) +
            *(float *)(iVar5 + 0x28) * *(float *)(unaff_ESI + 0x78);
  if (_K_ONE < local_8) {
    local_8 = 1.0;
  }
  fVar4 = _K_ONE - local_8 * local_8;
  pfVar6 = (float *)(**(code **)(*unaff_EDI + 8))();
  fVar3 = (*pfVar6 * *(float *)(unaff_ESI + 0x70) +
          pfVar6[1] * *(float *)(unaff_ESI + 0x74) + pfVar6[2] * *(float *)(unaff_ESI + 0x78)) -
          *(float *)(unaff_ESI + 0x7c);
  if (local_8 * fVar3 < 0.0) {
    fVar1 = (float)unaff_EDI[0x39];
  }
  return ABS(fVar3) < SQRT(fVar4) * fVar2 + ABS(local_8) * fVar1;
}


// ==== 0x469ad0 DynamicCollisionBody::ChangeInEnergy

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

float10 DynamicCollisionBody__ChangeInEnergy(void)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)RigidBody__GetTestImpulseEnergy();
  fVar2 = (float10)FUN_005851a0();
  return (float10)(float)fVar1 - fVar2;
}


// ==== 0x469b00 CarCollisionBody::CarCollisionBody

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 * CarCollisionBody__CarCollisionBody(undefined4 *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  char local_14 [8];
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685c78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CollisionBody__CollisionBody(param_1,0);
  *param_1 = &PTR_DynamicCollisionBody___DynamicCollisionBody_006c85b8;
  param_1[0x19] = param_2 + 0x540;
  DAT_00736010 = DAT_00736010 + 1;
  if (DAT_00736038 < DAT_00736010) {
    DAT_00736038 = DAT_00736010;
  }
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  *(undefined1 *)((int)param_1 + 0x16) = 1;
  param_1[0x18] = 0;
  param_1[0x4c] = 0;
  *param_1 = &PTR_CarCollisionBody___CarCollisionBody_006c8798;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  DAT_00736018 = DAT_00736018 + 1;
  local_4 = 0;
  if (DAT_00736040 < DAT_00736018) {
    DAT_00736040 = DAT_00736018;
  }
  param_1[0x50] = param_2;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  *(undefined1 *)((int)param_1 + 0x1d) = 1;
  param_1[0x51] = DAT_0073ad34;
  param_1[0x52] = DAT_0073ad34;
  param_1[0x53] = DAT_0073ad34;
  FUN_00565da0("Car%d",(int)*(short *)(param_2 + 10));
  pcVar2 = (char *)(param_1 + 0xd);
  iVar7 = 0x28;
  iVar3 = -(int)pcVar2;
  do {
    cVar1 = pcVar2[(int)(local_14 + iVar3)];
    iVar7 = iVar7 + -1;
    *pcVar2 = cVar1;
    if (cVar1 == '\0') break;
    pcVar2 = pcVar2 + 1;
  } while (iVar7 != 0);
  *(undefined1 *)((int)param_1 + 0x5b) = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  iVar3 = FUN_0057f020();
  puVar8 = DAT_00779bd8;
  puVar4 = (undefined4 *)NullUpdate_ret();
  for (; puVar8 != puVar4; puVar8 = (undefined4 *)*puVar8) {
    if (puVar8[6] == iVar3) {
      param_1[4] = puVar8;
      goto LAB_00469cac;
    }
  }
  iVar3 = FUN_0057f0d0();
  puVar8 = DAT_00779bd8;
  do {
    if (puVar8 == puVar4) {
      pvVar5 = _malloc(0x40);
      if (pvVar5 == (void *)0x0) {
        param_1[4] = 0;
        *(undefined1 *)(param_1 + 5) = 1;
      }
      else {
        uVar6 = FUN_00473ca0(0xc00de354,0xbf789375,0xbe4ccccd,0x400a8f5c,0x3f789375,0x3f1fbe77);
        param_1[4] = uVar6;
        *(undefined1 *)(param_1 + 5) = 1;
      }
LAB_00469d19:
      DynamicCollisionBody__BuildBoundingVolumes();
      DynamicCollisionBody__UpdatePosition();
      ExceptionList = local_c;
      return param_1;
    }
    if (puVar8[6] == iVar3) {
      param_1[4] = puVar8;
LAB_00469cac:
      if (*(char *)((int)puVar8 + 0x3e) != '\0') {
        if (*(int *)(*(int *)(param_2 + 0x14) + 4) != 3) {
          pvVar5 = _malloc(0x60);
          if (pvVar5 == (void *)0x0) {
            uVar6 = 0;
          }
          else {
            uVar6 = FUN_00472cb0();
          }
          param_1[4] = uVar6;
          *(undefined1 *)(param_1 + 5) = 1;
          FUN_00472cf0(uVar6,puVar8);
          FUN_00472ea0();
          puVar8 = (undefined4 *)param_1[4];
        }
        if (*(char *)((int)puVar8 + 0x3e) != '\0') goto LAB_00469d19;
      }
      FUN_00472e40();
      goto LAB_00469d19;
    }
    puVar8 = (undefined4 *)*puVar8;
  } while( true );
}


// ==== 0x469d40 CarCollisionBody::_CarCollisionBody

/* [canon] car med (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 * __thiscall CarCollisionBody___CarCollisionBody(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  CarCollisionBody___CarCollisionBody(param_1);
  iVar2 = DAT_0072cbf0;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_0072cbf0 + 0x18);
    *param_1 = *(undefined4 *)(DAT_0072cbf0 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x469d70 CarCollisionBody::_CarCollisionBody

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void CarCollisionBody___CarCollisionBody(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685c78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_CarCollisionBody___CarCollisionBody_006c8798;
  DAT_00736018 = DAT_00736018 + -1;
  local_4 = 0;
  if (*(char *)(param_1 + 5) == '\0') {
    if ((*(int *)(param_1[4] + 0x10) == 1) && (*(int *)(*(int *)(param_1[0x50] + 0x14) + 4) != 3)) {
      FUN_00472ea0();
    }
  }
  else {
    if (*(int *)(param_1[4] + 0x10) == 1) {
      FUN_00472df0();
    }
    if ((void *)param_1[4] != (void *)0x0) {
      _free((void *)param_1[4]);
    }
  }
  *param_1 = &PTR_DynamicCollisionBody___DynamicCollisionBody_006c85b8;
  DAT_00736010 = DAT_00736010 + -1;
  local_4 = 0xffffffff;
  CollisionBody___CollisionBody();
  ExceptionList = local_c;
  return;
}


// ==== 0x469e20 CarCollisionBody::DoSnapshot

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall CarCollisionBody__DoSnapshot(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  
  iVar2 = param_2;
  FUN_00571ea0(param_1,"CarCollisionBody");
  DynamicCollisionBody__DoSnapshot(iVar2);
  param_2 = CONCAT31(param_2._1_3_,*(undefined1 *)(*(int *)(param_1 + 0x140) + 10));
  if ((*(char *)(iVar2 + 0x3e) != '\0') || (*(char *)(iVar2 + 0x3f) != '\0')) {
    FUN_00571c20(iVar2,&param_2,1,1,1);
  }
  if (*(char *)(iVar2 + 0x3d) != '\0') {
    CarCollisionBody__SetupPhysicsPointers();
  }
  if (*(char *)(iVar2 + 0x3c) != '\0' || *(char *)(iVar2 + 0x3d) != '\0') {
    DynamicCollisionBody__UpdatePosition();
  }
  if ((*(char *)(iVar2 + 0x3e) != '\0') || (*(char *)(iVar2 + 0x3f) != '\0')) {
    FUN_00571c20(iVar2,param_1 + 0x24,8,0xffffffff,0);
  }
  if ((*(char *)(iVar2 + 0x3e) != '\0') || (*(char *)(iVar2 + 0x3f) != '\0')) {
    FUN_00571c20(iVar2,param_1 + 0x2c,8,0xffffffff,0);
  }
  FUN_00571c20(iVar2,param_1 + 0x144,4,0xffffffff,0);
  FUN_00571c20(iVar2,param_1 + 0x148,4,0xffffffff,0);
  FUN_00571c20(iVar2,param_1 + 0x14c,4,0xffffffff,0);
  iVar1 = *(char *)(iVar2 + 0x40) * 0x10 + 0x4c + iVar2;
  *(int *)(iVar1 + 0xc) = *(int *)(iVar2 + 0x150) - *(int *)(iVar1 + 0xc);
  cVar3 = *(char *)(iVar2 + 0x40) + -1;
  *(char *)(iVar2 + 0x40) = cVar3;
  if ((int)cVar3 < *(int *)(iVar2 + 0x44)) {
    *(undefined4 *)(iVar2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x469f30 CarCollisionBody::SetupPhysicsPointers

/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

int __fastcall CarCollisionBody__SetupPhysicsPointers(undefined4 param_1,int param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_2 + 0x68) = 0;
  *(undefined4 *)(param_2 + 0x6c) = 0;
  iVar1 = 0;
  if (*(int *)(param_2 + 0x60) != 0) {
    iVar1 = *(int *)(param_2 + 0x140);
    if (*(int *)(iVar1 + 0x28) == 1) {
      if (*(int *)(iVar1 + 0x34) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0x34) + 8;
      }
      *(int *)(param_2 + 0x68) = iVar1;
      if (iVar1 != 0) {
        *(undefined4 *)(param_2 + 0x6c) = *(undefined4 *)(iVar1 + 0x18);
        return iVar1 + -8;
      }
      iVar1 = 0;
      *(int *)(param_2 + 0x6c) = iRam00000020;
    }
    else if (*(int *)(iVar1 + 0x28) == 3) {
      if (*(int *)(iVar1 + 0x34) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0x34) + 8;
      }
      *(int *)(param_2 + 0x68) = iVar1;
      if (iVar1 != 0) {
        iVar1 = *(int *)(iVar1 + 0x18);
        *(int *)(param_2 + 0x6c) = iVar1;
        return iVar1;
      }
      iVar1 = iRam00000020;
      *(int *)(param_2 + 0x6c) = iRam00000020;
      return iVar1;
    }
  }
  return iVar1;
}


// ==== 0x469fb0 CarCollisionBody::SetToPhysicsMode

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall CarCollisionBody__SetToPhysicsMode(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_2 == 0) || (*(char *)(param_2 + 0x15) != '\0')) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_2 + 0x140);
  }
  piVar1 = *(int **)(*(int *)(param_1 + 0x140) + 0x2c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x34))(uVar3,0);
    CarCollisionBody__SetupPhysicsPointers();
    *(undefined1 *)(param_1 + 0x1d) = 1;
    return;
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x140) + 0x28);
  if ((iVar2 != 1) && (iVar2 != 3)) {
    Car_SetMode();
  }
  CarCollisionBody__SetupPhysicsPointers();
  *(undefined1 *)(param_1 + 0x1d) = 1;
  return;
}


// ==== 0x46a030 CarCollisionBody::Move

/* [canon] car high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall CarCollisionBody__Move(int param_1,undefined4 param_2)

{
  DynamicCollisionBody__BeginMove(param_2);
  Car__ServiceResetRequest(*(undefined4 *)(param_1 + 0x140),param_2);
  if (DAT_00736200 == 0) {
    DynamicCollisionBody__UpdatePosition();
  }
  return;
}


// ==== 0x46a060 FUN_0046a060

bool __fastcall FUN_0046a060(int param_1)

{
  if (DAT_00736090 != 0) {
    return false;
  }
  return *(char *)(param_1 + 0x1b) == '\0';
}


// ==== 0x46a080 FUN_0046a080

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_0046a080(int param_1)

{
  float10 fVar1;
  
  if (*(int *)(param_1 + 0x6c) == 0) {
    return (float10)0.0;
  }
  fVar1 = (float10)*(float *)(*(int *)(param_1 + 0x6c) + 0x148);
  if ((float10)(_K_ONE / 1.85) < fVar1) {
    fVar1 = (float10)(_K_ONE / 1.85);
  }
  return fVar1;
}


// ==== 0x46a0c0 CarCollisionBody::UpdateScaledMatrix

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car low (ghidra-canon) docs/re/runtime.md */

void __fastcall CarCollisionBody__UpdateScaledMatrix(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float *pfVar6;
  
  fVar3 = _K_ONE;
  if (*(int *)(*(int *)(param_1 + 0x140) + 0x38) != 1) {
    fVar3 = 0.4;
  }
  iVar4 = *(int *)(param_1 + 0x6c);
  pfVar6 = (float *)(iVar4 + 400);
  if (*(int *)(iVar4 + 0x138) == 0) {
    pfVar6 = (float *)(iVar4 + 0x150);
  }
  fVar1 = pfVar6[1];
  fVar2 = pfVar6[2];
  fVar5 = pfVar6[3];
  *(float *)(param_1 + 0x150) = fVar3 * *pfVar6;
  *(float *)(param_1 + 0x154) = fVar1 * fVar3;
  *(float *)(param_1 + 0x158) = fVar2 * fVar3;
  *(float *)(param_1 + 0x15c) = fVar5 * fVar3;
  fVar5 = pfVar6[7];
  fVar1 = pfVar6[5];
  fVar2 = pfVar6[6];
  *(float *)(param_1 + 0x160) = fVar3 * pfVar6[4];
  *(float *)(param_1 + 0x164) = fVar1 * fVar3;
  *(float *)(param_1 + 0x168) = fVar2 * fVar3;
  *(float *)(param_1 + 0x16c) = fVar5 * fVar3;
  fVar5 = pfVar6[0xb];
  fVar1 = pfVar6[9];
  fVar2 = pfVar6[10];
  *(float *)(param_1 + 0x170) = fVar3 * pfVar6[8];
  *(float *)(param_1 + 0x174) = fVar1 * fVar3;
  *(float *)(param_1 + 0x178) = fVar2 * fVar3;
  *(float *)(param_1 + 0x17c) = fVar5 * fVar3;
  fVar2 = pfVar6[0xf];
  fVar3 = pfVar6[0xd];
  fVar1 = pfVar6[0xe];
  *(float *)(param_1 + 0x180) = pfVar6[0xc];
  *(float *)(param_1 + 0x184) = fVar3;
  *(float *)(param_1 + 0x18c) = fVar2;
  *(float *)(param_1 + 0x188) = fVar1;
  return;
}


// ==== 0x46a1c0 FUN_0046a1c0

int __fastcall FUN_0046a1c0(int param_1)

{
  if (*(int *)(param_1 + 0x60) != 0) {
    return *(int *)(param_1 + 0x6c) + 0x20;
  }
  return *(int *)(param_1 + 0x140) + 0x60;
}


// ==== 0x46a1e0 CarCollisionBody::GetStatePtrA

/* [canon] car low (ghidra-canon) docs/re/runtime.md */

int __fastcall CarCollisionBody__GetStatePtrA(int param_1)

{
  if (*(int *)(param_1 + 0x60) != 0) {
    return *(int *)(param_1 + 0x6c) + 0xa0;
  }
  return *(int *)(param_1 + 0x140) + 0x70;
}


// ==== 0x46a200 CarCollisionBody::GetStatePtrB

/* [canon] car low (ghidra-canon) docs/re/runtime.md */

int __fastcall CarCollisionBody__GetStatePtrB(int param_1)

{
  if (*(int *)(param_1 + 0x60) != 0) {
    return *(int *)(param_1 + 0x6c) + 0xb0;
  }
  return *(int *)(param_1 + 0x140) + 0x80;
}


// ==== 0x46a220 FUN_0046a220

int __fastcall FUN_0046a220(int param_1)

{
  if (*(int *)(param_1 + 0x60) != 0) {
    return *(int *)(param_1 + 0x6c) + 0x30;
  }
  return *(int *)(param_1 + 0x140) + 0x90;
}


// ==== 0x46a240 FUN_0046a240

int __fastcall FUN_0046a240(int param_1)

{
  if (*(int *)(param_1 + 0x60) != 0) {
    return *(int *)(param_1 + 0x6c) + 0xc0;
  }
  return *(int *)(param_1 + 0x140) + 0xd0;
}


// ==== 0x46a260 FUN_0046a260

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0046a260(int param_1,float *param_2)

{
  float fVar1;
  undefined4 extraout_EDX;
  undefined4 local_78;
  float local_70;
  float local_6c;
  float local_68;
  undefined1 local_60 [16];
  undefined1 local_50 [76];
  
  fVar1 = *(float *)(*(int *)(param_1 + 0x6c) + 0x148);
  local_68 = _K_ONE;
  if (_K_ONE / 1.85 < fVar1) {
    local_68 = (_K_ONE / 1.85) / fVar1;
  }
  local_70 = local_68 * *param_2;
  local_6c = param_2[1] * local_68;
  local_68 = param_2[2] * local_68;
  fVar1 = SQRT(local_70 * local_70 + local_6c * local_6c + local_68 * local_68);
  if (*(int *)(*(int *)(param_1 + 0x140) + 0x38) == 1) {
    local_78 = 0x3f800000;
  }
  else {
    local_78 = 0x3ecccccd;
  }
  FUN_00584f60(local_78);
  FUN_0046a370(extraout_EDX,fVar1);
  if ((*(int *)(*(int *)(param_1 + 0x140) + 0x18) != 0) && (4.0 < fVar1)) {
    bMatrixCopy();
    D3DXVec3Transform(local_60,&local_70,local_50);
  }
  return;
}


// ==== 0x46a370 FUN_0046a370

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046a370(undefined4 param_1,float param_2)

{
  int unaff_EDI;
  undefined1 local_60 [16];
  undefined1 local_50 [76];
  
  if (*(int *)(*(int *)(unaff_EDI + 0x140) + 0x868) != 0) {
    bMatrixCopy();
    D3DXVec3Transform(local_60,param_1,local_50);
    FUN_0058d930(_DAT_007000cc * param_2);
  }
  if (*(int *)(*(int *)(unaff_EDI + 0x140) + 0x18) != 0) {
    FUN_0042f5f0(param_2);
  }
  return;
}


// ==== 0x46a3f0 FUN_0046a3f0

void * __thiscall FUN_0046a3f0(void *param_1,byte param_2)

{
  FUN_0046a410();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x46a410 FUN_0046a410

void __fastcall FUN_0046a410(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c8720;
  DAT_0073600c = DAT_0073600c + -1;
  CollisionBody___CollisionBody();
  return;
}


// ==== 0x46a430 CollisionBody::DoSnapshot

void CollisionBody__DoSnapshot(void)

{
  CollisionBody__DoSnapshot();
  return;
}


// ==== 0x46a440 FUN_0046a440

undefined4 * FUN_0046a440(undefined4 *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char local_48 [24];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 *puStack_20;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  pcStack_18 = FUN_00685d59;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  CollisionBody__CollisionBody(param_1,3);
  *param_1 = &PTR_FUN_006c8720;
  DAT_0073600c = DAT_0073600c + 1;
  if (DAT_00736034 < DAT_0073600c) {
    DAT_00736034 = DAT_0073600c;
  }
  *(undefined1 *)((int)param_1 + 0x16) = 0;
  local_14 = 0;
  *param_1 = &PTR_FUN_006c8630;
  FUN_00473410();
  DAT_00736014 = DAT_00736014 + 1;
  local_14 = CONCAT31(local_14._1_3_,1);
  if (DAT_0073603c < DAT_00736014) {
    DAT_0073603c = DAT_00736014;
  }
  param_1[4] = param_1 + 0x1c;
  FUN_00565da0("TrackPolygon%d",param_3 - DAT_0077b140 >> 5);
  pcVar2 = (char *)(param_1 + 0xd);
  iVar4 = 0x28;
  iVar3 = -(int)pcVar2;
  do {
    cVar1 = pcVar2[(int)(local_48 + iVar3)];
    iVar4 = iVar4 + -1;
    *pcVar2 = cVar1;
    if (cVar1 == '\0') break;
    pcVar2 = pcVar2 + 1;
  } while (iVar4 != 0);
  *(undefined1 *)((int)param_1 + 0x5b) = 0;
  iVar3 = TrackPoly__AcquireBody(&DAT_0077b130);
  param_1[0x18] = iVar3;
  *(undefined4 **)(iVar3 + 0x10) = param_1;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  FUN_00473480(param_1[0x18],0x3f800000);
  CollisionBody__SetBBoxMinMax(param_1,param_1[0x18] + 0x14);
  ExceptionList = local_1c;
  return param_1;
}


// ==== 0x46a580 FUN_0046a580

undefined4 * __thiscall FUN_0046a580(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_0046a5b0(param_1);
  iVar2 = DAT_0072cbf4;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_0072cbf4 + 0x18);
    *param_1 = *(undefined4 *)(DAT_0072cbf4 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x46a5b0 FUN_0046a5b0

void FUN_0046a5b0(undefined4 *param_1)

{
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  pcStack_c = FUN_00685c58;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = &PTR_FUN_006c8630;
  *(undefined4 *)(param_1[0x18] + 0x10) = 0;
  local_8 = 0;
  *(char *)(param_1[0x18] + 8) = *(char *)(param_1[0x18] + 8) + -1;
  DAT_00736014 = DAT_00736014 + -1;
  eh_vector_destructor_iterator(param_1 + 0x24,0x30,9,NullUpdate_ret);
  *param_1 = &PTR_FUN_006c8720;
  DAT_0073600c = DAT_0073600c + -1;
  local_8 = 0xffffffff;
  CollisionBody___CollisionBody();
  ExceptionList = local_10;
  return;
}


// ==== 0x46a640 FUN_0046a640

void __thiscall FUN_0046a640(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(param_1,"TrackPolygonCollisionBody");
  CollisionBody__DoSnapshot(param_2);
  if ((*(char *)(param_2 + 0x3e) != '\0') || (*(char *)(param_2 + 0x3f) != '\0')) {
    FUN_00571c20(param_2,param_1 + 0x24,8,0xffffffff,0);
  }
  if ((*(char *)(param_2 + 0x3e) != '\0') || (*(char *)(param_2 + 0x3f) != '\0')) {
    FUN_00571c20(param_2,param_1 + 0x2c,8,0xffffffff,0);
  }
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x46a6e0 AllTrackPolygonCollisionBodies::Serialize

/* [canon] track high (hopper+ghidra) docs/re/track.md */

void AllTrackPolygonCollisionBodies__Serialize(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  char cVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *local_20;
  int local_1c;
  undefined4 *local_18;
  undefined2 local_14 [2];
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  iVar1 = param_1;
  local_8 = 0xffffffff;
  pcStack_c = FUN_006864b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00571ea0(0,"AllTrackPolygonCollisionBodies");
  if ((*(char *)(iVar1 + 0x3e) != '\0') || (*(char *)(iVar1 + 0x3f) != '\0')) {
    FUN_00571c20(iVar1,&DAT_00736014,4,4,1);
  }
  if (*(char *)(iVar1 + 0x3d) == '\0') {
    if (DAT_00779c70 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)(DAT_00779c70 + -4);
    }
    piVar4 = (int *)Ptr_BaseAdjustMinus4();
    while (piVar3 != piVar4) {
      if (*(char *)((int)piVar3 + 0x15) == '\x03') {
        local_1c = *(int *)(piVar3[0x18] + 0xc) - DAT_0077b140 >> 5;
        FUN_00571c20(iVar1,&local_1c,2,2,0);
        local_18 = (undefined4 *)(uint)*(ushort *)(piVar3 + 6);
        FUN_00571c20(iVar1,&local_18,2,2,0);
        (**(code **)(*piVar3 + 4))(iVar1);
      }
      if (piVar3[1] == 0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = (int *)(piVar3[1] + -4);
      }
    }
    local_20 = (undefined4 *)0xffff;
    FUN_00571c20(iVar1,&local_20,2,2,0);
  }
  else {
    while( true ) {
      FUN_00571c20(iVar1,(int)&param_1 + 2,2,2,0);
      if (param_1._2_2_ == 0xffff) break;
      local_1c = (uint)param_1._2_2_ * 0x20 + DAT_0077b140;
      FUN_00571c20(iVar1,local_14,2,2,0);
      iVar6 = DAT_0072cbf4;
      local_18 = (undefined4 *)(DAT_0072cbf4 + 0x10);
      if ((*(int *)(DAT_0072cbf4 + 0x10) == 0) && ((*(byte *)(DAT_0072cbf4 + 0x14) & 1) != 0)) {
        FUN_00566e60();
      }
      local_20 = (undefined4 *)*local_18;
      iVar2 = *(int *)(iVar6 + 0x18) + 1;
      if (local_20 != (undefined4 *)0x0) {
        puVar7 = (undefined4 *)*local_20;
        if (*(int *)(iVar6 + 0x1c) < iVar2) {
          *(int *)(iVar6 + 0x1c) = iVar2;
        }
        *(int *)(iVar6 + 0x18) = iVar2;
        *local_18 = puVar7;
        local_18 = puVar7;
        if (((*(byte *)(iVar6 + 0x14) & 2) != 0) &&
           (iVar6 = *(int *)(iVar6 + 0x28) >> 2, puVar7 = local_20, 0 < iVar6)) {
          for (; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
          }
        }
      }
      piVar3 = (int *)0x0;
      local_8 = 0;
      if (local_20 != (undefined4 *)0x0) {
        piVar3 = (int *)FUN_0046a440(local_20,local_14[0],local_1c);
      }
      local_8 = 0xffffffff;
      (**(code **)(*piVar3 + 4))(iVar1);
    }
  }
  iVar6 = *(char *)(iVar1 + 0x40) * 0x10;
  *(int *)(iVar6 + iVar1 + 0x58) = *(int *)(iVar1 + 0x150) - *(int *)(iVar6 + 0x58 + iVar1);
  cVar5 = *(char *)(iVar1 + 0x40) + -1;
  *(char *)(iVar1 + 0x40) = cVar5;
  if ((int)cVar5 < *(int *)(iVar1 + 0x44)) {
    *(undefined4 *)(iVar1 + 0x44) = 0xffffffff;
  }
  ExceptionList = local_10;
  return;
}


// ==== 0x46a8f0 FUN_0046a8f0

undefined4 * FUN_0046a8f0(void)

{
  return &DAT_007372a0;
}


// ==== 0x46a900 FUN_0046a900

int __fastcall FUN_0046a900(int param_1)

{
  return (int)*(char *)(*(int *)(param_1 + 0x60) + 0xb);
}


// ==== 0x46a910 FUN_0046a910

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_0046a910(int param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)0.3;
  if ((*(byte *)(*(int *)(param_1 + 0x60) + 10) & 10) == 0) {
    fVar1 = (float10)_DAT_007000d4;
  }
  return fVar1;
}


// ==== 0x46a930 _GLOBAL__D_TheCollisionStats

/* [canon] car med (ghidra-canon+hopper) docs/re/car.md */

void _GLOBAL__D_TheCollisionStats(void)

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
    if (piVar1 + -0x94 != (int *)0x0) {
      (**(code **)piVar1[-0x94])(1);
    }
    piVar1 = (int *)*unaff_ESI;
  }
  return;
}


// ==== 0x46a960 PhysicsComponent::scalar_deleting_destructor

/* [canon] car low (ghidra-canon) docs/re/car.md */

void * __thiscall PhysicsComponent__scalar_deleting_destructor(void *param_1,byte param_2)

{
  FUN_0046a980();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x46a980 FUN_0046a980

void __fastcall FUN_0046a980(undefined4 *param_1)

{
  *param_1 = &PTR_PhysicsComponent__scalar_deleting_destructor_006c8584;
  return;
}


// ==== 0x46a990 FUN_0046a990

void * __thiscall FUN_0046a990(void *param_1,byte param_2)

{
  PhysicsSystem___PhysicsSystem();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x46a9b0 PhysicsSystem::_PhysicsSystem

/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

void __fastcall PhysicsSystem___PhysicsSystem(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pvStack_c = ExceptionList;
  pcStack_8 = FUN_006854db;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c85a8;
  piVar2 = (int *)param_1[3];
  piVar1 = param_1 + 3;
  local_4 = 0;
  while (piVar2 != piVar1) {
    piVar2 = (int *)*piVar1;
    iVar3 = *piVar2;
    piVar4 = (int *)piVar2[1];
    *piVar4 = iVar3;
    *(int **)(iVar3 + 4) = piVar4;
    if (piVar2 + -1 != (int *)0x0) {
      (**(code **)piVar2[-1])(1);
    }
    piVar2 = (int *)*piVar1;
  }
  piVar2 = (int *)*piVar1;
  local_4 = 0xffffffff;
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
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x46aa40 FUN_0046aa40

void FUN_0046aa40(int *param_1,float param_2)

{
  int *piVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  int local_234;
  float local_230 [140];
  
  PhysicsSystem__GetDerivative(param_1,local_230);
  iVar5 = param_1[3];
  local_234 = 0;
  while( true ) {
    if (iVar5 == 0) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = (int *)(iVar5 + -4);
    }
    if (param_1 == (int *)0xfffffff4) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = param_1 + 2;
    }
    if (piVar6 == piVar1) break;
    iVar2 = (**(code **)(*piVar6 + 4))();
    pfVar3 = (float *)(**(code **)(*piVar6 + 0xc))();
    pfVar9 = local_230 + local_234;
    (**(code **)(*piVar6 + 0x20))();
    iVar5 = 0;
    if (3 < iVar2) {
      iVar4 = 3;
      pfVar7 = pfVar3;
      pfVar8 = pfVar9;
      do {
        iVar4 = iVar4 + 4;
        iVar5 = iVar5 + 4;
        pfVar3 = pfVar7 + 4;
        pfVar9 = pfVar8 + 4;
        *pfVar7 = param_2 * *pfVar8 + *pfVar7;
        pfVar7[1] = param_2 * pfVar8[1] + pfVar7[1];
        pfVar7[2] = param_2 * pfVar8[2] + pfVar7[2];
        pfVar7[3] = param_2 * pfVar8[3] + pfVar7[3];
        pfVar7 = pfVar3;
        pfVar8 = pfVar9;
      } while (iVar4 < iVar2);
    }
    if (iVar5 < iVar2) {
      iVar5 = iVar2 - iVar5;
      do {
        iVar5 = iVar5 + -1;
        *pfVar3 = param_2 * *pfVar9 + *pfVar3;
        pfVar3 = pfVar3 + 1;
        pfVar9 = pfVar9 + 1;
      } while (iVar5 != 0);
    }
    iVar5 = piVar6[1];
    local_234 = local_234 + iVar2;
  }
  (**(code **)(*param_1 + 4))();
  return;
}


// ==== 0x46ab70 PhysicsSystem::GetDerivative

/* [canon] car high (ghidra-canon+nfsug) docs/re/runtime.md */

void PhysicsSystem__GetDerivative(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  if (*(int *)(param_1 + 0xc) == 0) goto LAB_0046ab8d;
  piVar3 = (int *)(*(int *)(param_1 + 0xc) + -4);
  while( true ) {
    if (param_1 == -0xc) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)(param_1 + 8);
    }
    if (piVar3 == piVar1) break;
    (**(code **)(*piVar3 + 0x18))(param_2 + iVar4 * 4);
    iVar2 = (**(code **)(*piVar3 + 4))();
    iVar4 = iVar4 + iVar2;
    if (piVar3[1] == 0) {
LAB_0046ab8d:
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)(piVar3[1] + -4);
    }
  }
  return;
}


// ==== 0x46abd0 PhysicsSystem::ComputeAuxiliaries

/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

void __fastcall PhysicsSystem__ComputeAuxiliaries(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0xc) == 0) goto LAB_0046abe1;
  piVar2 = (int *)(*(int *)(param_1 + 0xc) + -4);
  while( true ) {
    if (param_1 == -0xc) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)(param_1 + 8);
    }
    if (piVar2 == piVar1) break;
    (**(code **)(*piVar2 + 0x1c))();
    if (piVar2[1] == 0) {
LAB_0046abe1:
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)(piVar2[1] + -4);
    }
  }
  return;
}


// ==== 0x46ac10 CarState::IsTimedFlagActive

/* [canon] car med (ghidra-canon+hopper) docs/re/runtime.md */

undefined4 CarState__IsTimedFlagActive(void)

{
  int in_EAX;
  
  if ((*(char *)(in_EAX + 0x1d0) != '\0') && (0.0 < *(float *)(in_EAX + 0x1d4))) {
    return 1;
  }
  return 0;
}


// ==== 0x46ac40 FUN_0046ac40

void FUN_0046ac40(void)

{
  undefined4 *puVar1;
  
  DAT_00735fe4 = (undefined4 *)FUN_00566dc0(0x40,"ContactSlotPool",0);
  if (DAT_00735fe4 == (undefined4 *)0x0) {
    return;
  }
  if (DAT_0073d814 == 1) {
    *DAT_0073d81c = DAT_00735fe4;
    puVar1 = DAT_00735fe4;
    DAT_00735fe4[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_00735fe4 = &DAT_0073d818;
  }
  return;
}


// ==== 0x46ac90 Contact::RemoveContacts

/* [canon] car high (ghidra-canon+nfsug) docs/re/runtime.md */

void Contact__RemoveContacts(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *in_EAX;
  int *piVar6;
  int unaff_EBX;
  
  piVar1 = (int *)*in_EAX;
  piVar6 = (int *)NullUpdate_ret();
  iVar5 = DAT_00735fe4;
  while (piVar4 = piVar1, piVar4 != piVar6) {
    piVar1 = (int *)*piVar4;
    if ((piVar4[3] == unaff_EBX) || (piVar4[4] == unaff_EBX)) {
      piVar2 = (int *)piVar4[1];
      *piVar2 = (int)piVar1;
      piVar1[1] = (int)piVar2;
      iVar3 = *(int *)(iVar5 + 0x18);
      *piVar4 = *(int *)(iVar5 + 0x10);
      *(int *)(iVar5 + 0x18) = iVar3 + -1;
      *(int **)(iVar5 + 0x10) = piVar4;
    }
  }
  return;
}


// ==== 0x46ace0 FUN_0046ace0

float10 FUN_0046ace0(void)

{
  float *pfVar1;
  undefined4 *unaff_EBX;
  int unaff_EDI;
  float local_30;
  float local_2c;
  float local_28;
  
  if (*(char *)(*(int *)(unaff_EDI + 0xc) + 0x15) == '\x03') {
    if (*(char *)(*(int *)(unaff_EDI + 0x10) + 0x16) != '\0') {
      FindWaferNormal(unaff_EDI);
      *unaff_EBX = 1;
      pfVar1 = (float *)(**(code **)(**(int **)(unaff_EDI + 0x10) + 8))();
      return (float10)local_30 * (float10)*pfVar1 +
             (float10)local_28 * (float10)pfVar1[2] + (float10)local_2c * (float10)pfVar1[1];
    }
  }
  else if ((*(char *)(*(int *)(unaff_EDI + 0x10) + 0x15) == '\x03') &&
          (*(char *)(*(int *)(unaff_EDI + 0xc) + 0x16) != '\0')) {
    FindWaferNormal(unaff_EDI);
    *unaff_EBX = 1;
    pfVar1 = (float *)(**(code **)(**(int **)(unaff_EDI + 0xc) + 8))();
    return (float10)-local_30 * (float10)*pfVar1 +
           (float10)-local_2c * (float10)pfVar1[1] + (float10)-local_28 * (float10)pfVar1[2];
  }
  *unaff_EBX = 0;
  return (float10)0.0;
}


// ==== 0x46adc0 FUN_0046adc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0046adc0(int param_1,int param_2)

{
  ushort uVar1;
  float10 fVar2;
  float10 fVar3;
  
  if (_DAT_00700088 <= ABS(*(float *)(param_1 + 8) - *(float *)(param_2 + 8))) {
    uVar1 = (ushort)(*(float *)(param_1 + 8) < *(float *)(param_2 + 8)) << 8 |
            (ushort)(*(float *)(param_1 + 8) == *(float *)(param_2 + 8)) << 0xe;
  }
  else {
    fVar2 = (float10)FUN_0046ace0();
    fVar3 = (float10)FUN_0046ace0();
    if (param_1 == 0) {
      return 1;
    }
    if (param_2 == 0) {
      return 1;
    }
    uVar1 = (ushort)((float)fVar2 < (float)fVar3) << 8 |
            (ushort)((float)fVar2 == (float)fVar3) << 0xe;
  }
  if (uVar1 != 0) {
    return 1;
  }
  return 0;
}


// ==== 0x46ae40 FUN_0046ae40

void __fastcall FUN_0046ae40(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  int unaff_ESI;
  float10 fVar1;
  
  *(undefined4 *)(unaff_ESI + 0xc) = in_EAX;
  *(undefined4 *)(unaff_ESI + 0x10) = param_1;
  *(undefined4 *)(unaff_ESI + 0x14) = param_2;
  fVar1 = (float10)FUN_0046ae60();
  *(float *)(unaff_ESI + 8) = (float)fVar1;
  *(undefined4 *)(unaff_ESI + 0x30) = DAT_006f08a4;
  return;
}


// ==== 0x46ae60 FUN_0046ae60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0046ae60(void)

{
  char cVar1;
  int iVar2;
  float fVar3;
  int in_EAX;
  float10 fVar4;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  int iStack_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
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
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [76];
  
  if (DAT_00736200 != 0) {
    return (float10)0.0;
  }
  *(undefined4 *)(in_EAX + 0x20) = 0;
  *(undefined4 *)(in_EAX + 0x24) = 0;
  *(undefined4 *)(in_EAX + 0x28) = 0;
  local_a0 = 0x3f800000;
  local_9c = 0;
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0x3f800000;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0x3f800000;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0x3f800000;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  fVar4 = (float10)(**(code **)(**(int **)(in_EAX + 0xc) + 0x24))();
  fStack_c0 = (float)fVar4;
  fVar4 = (float10)(**(code **)(**(int **)(in_EAX + 0x10) + 0x24))();
  if (fVar4 <= (float10)fStack_c0) {
    fStack_c0 = (float)fVar4;
  }
  fStack_b8 = 0.0;
  CollisionBodyWitness_UpdatePolygonSideFlag(1);
  iStack_b4 = 0;
  do {
    fVar3 = (fStack_c0 - fStack_b8) * _K_HALF + fStack_b8;
    fStack_bc = fVar3;
    (**(code **)(**(int **)(in_EAX + 0xc) + 0x30))(auStack_60,auStack_50,fVar3);
    (**(code **)(**(int **)(in_EAX + 0x10) + 0x30))(&fStack_bc,&local_ac,fVar3);
    FUN_00472830(auStack_50,&local_a0,&local_b0);
    FUN_00472950();
    cVar1 = *(char *)(*(int *)(in_EAX + 0x14) + 0x15);
    if (cVar1 == '\0') {
      if (*(char *)(*(int *)(in_EAX + 0x14) + 0x14) != '\0') goto LAB_0046b020;
      fStack_c0 = fStack_bc;
    }
    else {
      fStack_b8 = fStack_bc;
    }
    iStack_b4 = iStack_b4 + 1;
  } while (iStack_b4 < 8);
  if (cVar1 != '\0') {
    FUN_0046b260(in_EAX,fStack_bc);
  }
LAB_0046b020:
  iVar2 = *(int *)(*(int *)(in_EAX + 0x14) + 600);
  if (*(char *)(iVar2 + 0x15) != '\x03') {
    iVar2 = *(int *)(*(int *)(in_EAX + 0x14) + 0x25c);
    if (*(char *)(iVar2 + 0x15) == '\x03') {
      *(undefined1 *)(*(int *)(iVar2 + 0x10) + 0x1d0) = 0;
    }
    return (float10)fStack_bc;
  }
  *(undefined1 *)(*(int *)(iVar2 + 0x10) + 0x1d0) = 0;
  return (float10)fStack_bc;
}


// ==== 0x46b070 FindWaferNormal

/* [canon] car med (ghidra-canon+nfsug) docs/re/runtime.md */

void __fastcall FindWaferNormal(int param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int in_EAX;
  int iVar4;
  float *pfVar5;
  float *unaff_ESI;
  float local_20;
  float local_1c;
  float local_18;
  
  iVar4 = *(int *)(param_1 + 0x60);
  fVar1 = *(float *)(iVar4 + 0x70);
  fVar2 = *(float *)(iVar4 + 0x74);
  fVar3 = *(float *)(iVar4 + 0x78);
  if (DAT_00735ff0 == 0) {
    iVar4 = *(int *)(param_1 + 0x10);
    if ((*(char *)(iVar4 + 0x1d0) == '\0') || (*(float *)(iVar4 + 0x1d4) <= 0.0)) {
      pfVar5 = (float *)(iVar4 + 0x1e0);
    }
    else {
      pfVar5 = (float *)(iVar4 + 0x1f0);
    }
    if ((param_2 == (float *)0x0) || (*(char *)(in_EAX + 0x15) == '\0')) {
      param_2 = (float *)(in_EAX + 0x110);
    }
    if (DAT_00700090 != 0) {
      if (*(char *)(in_EAX + 0x15) == '\x01') {
        iVar4 = *(int *)(*(int *)(param_3 + 0x14) + 0x274);
      }
      else {
        iVar4 = 0;
      }
      if (iVar4 == 0) {
        Vec3_Sub();
        if (local_20 * fVar1 + local_1c * fVar2 + local_18 * fVar3 < 0.0) {
          unaff_ESI[2] = -fVar3;
          *unaff_ESI = -fVar1;
          unaff_ESI[1] = -fVar2;
          *(undefined4 *)(*(int *)(param_3 + 0x14) + 0x274) = 2;
          return;
        }
        *unaff_ESI = fVar1;
        unaff_ESI[1] = fVar2;
        unaff_ESI[2] = fVar3;
        *(undefined4 *)(*(int *)(param_3 + 0x14) + 0x274) = 1;
        return;
      }
      if (iVar4 == 1) {
        *unaff_ESI = fVar1;
        unaff_ESI[1] = fVar2;
        unaff_ESI[2] = fVar3;
        return;
      }
      if (iVar4 == 2) {
        unaff_ESI[2] = -fVar3;
        *unaff_ESI = -fVar1;
        unaff_ESI[1] = -fVar2;
        return;
      }
      return;
    }
    if ((*param_2 - *pfVar5) * fVar1 +
        (param_2[1] - pfVar5[1]) * fVar2 + fVar3 * (param_2[2] - pfVar5[2]) < 0.0) {
      unaff_ESI[2] = -fVar3;
      *unaff_ESI = -fVar1;
      unaff_ESI[1] = -fVar2;
      return;
    }
  }
  *unaff_ESI = fVar1;
  unaff_ESI[1] = fVar2;
  unaff_ESI[2] = fVar3;
  return;
}


// ==== 0x46b260 FUN_0046b260

void FUN_0046b260(int param_1,float param_2)

{
  char cVar1;
  char cVar2;
  float fVar3;
  undefined4 *puVar4;
  float *pfVar5;
  int iVar6;
  float unaff_EDI;
  undefined1 *puStack_158;
  float fStack_154;
  float fStack_13c;
  float fStack_11c;
  float fStack_110;
  float fStack_108;
  float fStack_104;
  float fStack_100;
  undefined1 auStack_fc [4];
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  undefined1 local_e0 [4];
  int iStack_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_c0;
  float fStack_b0;
  undefined1 auStack_a8 [12];
  undefined1 auStack_9c [52];
  undefined1 auStack_68 [24];
  undefined1 local_50 [76];
  
  fStack_154 = param_2;
  puStack_158 = local_50;
  (**(code **)(**(int **)(param_1 + 0xc) + 0x30))(local_e0);
  (**(code **)(**(int **)(param_1 + 0x10) + 0x30))(auStack_fc,auStack_9c,param_2);
  cVar1 = *(char *)((int)*(int **)(param_1 + 0xc) + 0x15);
  if (cVar1 == '\x03') {
    FindWaferNormal(param_1);
    goto LAB_0046b3f2;
  }
  cVar2 = *(char *)((int)*(int **)(param_1 + 0x10) + 0x15);
  if (cVar2 == '\x03') {
    FindWaferNormal(param_1);
    puStack_158 = (undefined1 *)-(float)puStack_158;
    fStack_154 = -param_2;
    unaff_EDI = -unaff_EDI;
    goto LAB_0046b3f2;
  }
  if ((cVar1 == '\x02') || (cVar1 == '\x01')) {
    pfVar5 = (float *)(**(code **)(**(int **)(param_1 + 0x10) + 0xc))();
    puStack_158 = (undefined1 *)-*pfVar5;
    fStack_154 = -pfVar5[1];
    unaff_EDI = -pfVar5[2];
LAB_0046b390:
    if (SQRT((float)puStack_158 * (float)puStack_158 +
             fStack_154 * fStack_154 + unaff_EDI * unaff_EDI) < 27.777779) goto LAB_0046b3db;
  }
  else {
    if ((cVar2 == '\x02') || (cVar2 == '\x01')) {
      puVar4 = (undefined4 *)(**(code **)(**(int **)(param_1 + 0xc) + 0xc))();
      fStack_154 = (float)puVar4[1];
      puStack_158 = (undefined1 *)*puVar4;
      unaff_EDI = (float)puVar4[2];
      goto LAB_0046b390;
    }
LAB_0046b3db:
    unaff_EDI = fStack_100 - fStack_f0;
    fStack_154 = fStack_104 - fStack_f4;
    puStack_158 = (undefined1 *)(fStack_108 - fStack_f8);
  }
  bNormalize3();
LAB_0046b3f2:
  fStack_13c = 0.0;
  fStack_11c = 0.005;
  iStack_dc = 0;
  while( true ) {
    fVar3 = fStack_f0;
    fStack_13c = fStack_11c + fStack_13c;
    if (fStack_11c < 0.1) {
      fStack_11c = fStack_11c + 0.01;
    }
    fStack_110 = unaff_EDI * fStack_13c;
    if (fStack_110 <= 0.15) {
      if (fStack_110 < -0.15) {
        fStack_110 = -0.15;
      }
    }
    else {
      fStack_110 = 0.15;
    }
    fStack_d8 = fStack_108;
    fStack_d4 = fStack_104;
    fStack_d0 = fStack_100;
    iVar6 = (**(code **)(**(int **)(param_1 + 0xc) + 0x60))();
    if (iVar6 != 0) {
      fStack_c0 = fVar3 - fStack_110;
    }
    iVar6 = (**(code **)(**(int **)(param_1 + 0x10) + 0x60))();
    if (iVar6 != 0) {
      fStack_d8 = fStack_d8 + (float)puStack_158 * fStack_13c;
      fStack_d4 = fStack_d4 + fStack_154 * fStack_13c;
      fStack_d0 = fStack_d0 + fStack_110;
      fStack_b0 = fStack_d0;
    }
    FUN_00472830(auStack_68,auStack_a8,&fStack_d8);
    FUN_00472950();
    if ((*(char *)(*(int *)(param_1 + 0x14) + 0x14) == '\0') ||
       (*(char *)(*(int *)(param_1 + 0x14) + 0x15) == '\0')) break;
    iStack_dc = iStack_dc + 1;
    if (0x13 < iStack_dc) {
      return;
    }
  }
  *(float *)(param_1 + 0x20) = (float)puStack_158 * fStack_13c;
  *(float *)(param_1 + 0x24) = fStack_154 * fStack_13c;
  *(float *)(param_1 + 0x28) = fStack_110;
  return;
}


// ==== 0x46b5e0 FUN_0046b5e0

void FUN_0046b5e0(void)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  float *pfVar4;
  int unaff_ESI;
  int *piVar5;
  int *piVar6;
  undefined1 auStack_44 [4];
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_28;
  
  (**(code **)(**(int **)(unaff_ESI + 0xc) + 0x44))(*(undefined4 *)(unaff_ESI + 0x10));
  (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x44))(*(undefined4 *)(unaff_ESI + 0xc));
  (**(code **)(**(int **)(unaff_ESI + 0xc) + 0x2c))(*(undefined4 *)(unaff_ESI + 8));
  (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x2c))(*(undefined4 *)(unaff_ESI + 8));
  iVar3 = (**(code **)(**(int **)(unaff_ESI + 0xc) + 8))();
  fVar1 = *(float *)(iVar3 + 8);
  pfVar4 = (float *)(**(code **)(**(int **)(unaff_ESI + 0x10) + 8))();
  fStack_3c = pfVar4[1];
  fStack_38 = pfVar4[2];
  fStack_40 = *pfVar4;
  piVar2 = *(int **)(unaff_ESI + 0xc);
  piVar5 = (int *)0x0;
  if ((((*(char *)((int)piVar2 + 0x15) != '\0') ||
       (*(char *)(*(int *)(unaff_ESI + 0x10) + 0x15) != '\x01')) ||
      (piVar6 = piVar2, *(int *)(*(int *)(unaff_ESI + 0x10) + 0x130) < 1)) &&
     (((piVar6 = piVar5, *(char *)((int)*(int **)(unaff_ESI + 0x10) + 0x15) == '\0' &&
       (*(char *)((int)piVar2 + 0x15) == '\x01')) && (0 < piVar2[0x4c])))) {
    piVar6 = *(int **)(unaff_ESI + 0x10);
  }
  iVar3 = (**(code **)(*piVar2 + 0x60))();
  if (iVar3 != 0) {
    fStack_28 = fVar1 - *(float *)(unaff_ESI + 0x28);
    if (*(int **)(unaff_ESI + 0xc) == piVar6) {
      (**(code **)(**(int **)(unaff_ESI + 0xc) + 8))();
    }
  }
  iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x60))();
  if (iVar3 != 0) {
    fStack_40 = fStack_40 + *(float *)(unaff_ESI + 0x20);
    fStack_3c = *(float *)(unaff_ESI + 0x24) + fStack_3c;
    fStack_38 = *(float *)(unaff_ESI + 0x28) + fStack_38;
    fStack_28 = fStack_38;
    if (*(int **)(unaff_ESI + 0x10) == piVar6) {
      iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x10) + 8))();
      fStack_38 = *(float *)(iVar3 + 8);
    }
  }
  (**(code **)(**(int **)(unaff_ESI + 0xc) + 0x1c))(&stack0xffffffb0);
  (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x1c))(auStack_44);
  (**(code **)(**(int **)(unaff_ESI + 0xc) + 0x34))();
  (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x34))();
  FUN_0046bae0(unaff_ESI);
  (**(code **)(**(int **)(unaff_ESI + 0xc) + 0x34))();
  (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x34))();
  (**(code **)(**(int **)(unaff_ESI + 0xc) + 0x28))(*(undefined4 *)(unaff_ESI + 8));
  (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x28))(*(undefined4 *)(unaff_ESI + 8));
  return;
}


// ==== 0x46b790 FUN_0046b790

void FUN_0046b790(void)

{
  float *pfVar1;
  int iVar2;
  int unaff_ESI;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  undefined1 auStack_3c [4];
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_20;
  
  fStack_44 = *(float *)(unaff_ESI + 0x10);
  fStack_48 = 6.494364e-39;
  (**(code **)(**(int **)(unaff_ESI + 0xc) + 0x44))();
  fStack_48 = *(float *)(unaff_ESI + 0xc);
  (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x44))();
  if (*(char *)(*(int *)(unaff_ESI + 0x14) + 0x15) != '\0') {
    FUN_0046b260(unaff_ESI,0);
    pfVar1 = (float *)(**(code **)(**(int **)(unaff_ESI + 0xc) + 8))();
    fStack_44 = pfVar1[1];
    fStack_40 = pfVar1[2];
    fStack_48 = *pfVar1;
    pfVar1 = (float *)(**(code **)(**(int **)(unaff_ESI + 0x10) + 8))();
    fStack_34 = pfVar1[1];
    fStack_30 = pfVar1[2];
    fStack_38 = *pfVar1;
    iVar2 = (**(code **)(**(int **)(unaff_ESI + 0xc) + 0x60))();
    if (iVar2 != 0) {
      fStack_48 = fStack_48 - *(float *)(unaff_ESI + 0x20);
      fStack_44 = fStack_44 - *(float *)(unaff_ESI + 0x24);
      fStack_40 = fStack_40 - *(float *)(unaff_ESI + 0x28);
      fStack_20 = fStack_40;
    }
    iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x60))();
    if (iVar2 != 0) {
      fStack_38 = fStack_38 + *(float *)(unaff_ESI + 0x20);
      fStack_34 = *(float *)(unaff_ESI + 0x24) + fStack_34;
      fStack_30 = *(float *)(unaff_ESI + 0x28) + fStack_30;
      fStack_20 = fStack_30;
    }
    (**(code **)(**(int **)(unaff_ESI + 0xc) + 0x1c))(&fStack_48);
    (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x1c))(auStack_3c);
    (**(code **)(**(int **)(unaff_ESI + 0xc) + 0x34))();
    (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x34))();
  }
  FUN_0046bae0(unaff_ESI);
  (**(code **)(**(int **)(unaff_ESI + 0xc) + 0x34))();
  (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x34))();
  return;
}


// ==== 0x46b8c0 Contact::FindContactPointAndNormal

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

void __fastcall Contact__FindContactPointAndNormal(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float *in_EAX;
  float *pfVar8;
  float *pfVar9;
  int unaff_EDI;
  
  iVar5 = *(int *)(unaff_EDI + 0x14);
  fVar1 = *(float *)(iVar5 + 0x24);
  fVar6 = *(float *)(iVar5 + 0x20);
  fVar2 = *(float *)(iVar5 + 0x28);
  fVar7 = *(float *)(iVar5 + 0x30);
  fVar3 = *(float *)(iVar5 + 0x34);
  fVar4 = *(float *)(iVar5 + 0x38);
  *param_1 = (fVar7 + fVar6) * _K_HALF;
  param_1[1] = (fVar3 + fVar1) * _K_HALF;
  param_1[2] = (fVar4 + fVar2) * _K_HALF;
  if (*(char *)(*(int *)(unaff_EDI + 0xc) + 0x16) == '\0') {
    FindWaferNormal(unaff_EDI);
    return;
  }
  if (*(char *)(*(int *)(unaff_EDI + 0x10) + 0x16) == '\0') {
    FindWaferNormal(unaff_EDI);
    in_EAX[2] = -in_EAX[2];
    *in_EAX = -*in_EAX;
    in_EAX[1] = -in_EAX[1];
    return;
  }
  fVar7 = fVar7 - fVar6;
  fVar3 = fVar3 - fVar1;
  fVar4 = fVar4 - fVar2;
  *in_EAX = fVar7;
  in_EAX[1] = fVar3;
  in_EAX[2] = fVar4;
  fVar1 = SQRT(fVar7 * fVar7 + fVar3 * fVar3 + fVar4 * fVar4);
  if (fVar1 < 1e-06) {
    pfVar8 = (float *)(**(code **)(**(int **)(unaff_EDI + 0xc) + 8))();
    pfVar9 = (float *)(**(code **)(**(int **)(unaff_EDI + 0x10) + 8))();
    fVar1 = pfVar9[1];
    fVar2 = pfVar8[1];
    fVar3 = pfVar9[2];
    fVar4 = pfVar8[2];
    *in_EAX = *pfVar9 - *pfVar8;
    in_EAX[2] = fVar3 - fVar4;
    in_EAX[1] = fVar1 - fVar2;
    bNormalize3();
    return;
  }
  fVar1 = _K_ONE / fVar1;
  *in_EAX = fVar7 * fVar1;
  in_EAX[1] = fVar3 * fVar1;
  in_EAX[2] = fVar4 * fVar1;
  return;
}


// ==== 0x46ba50 DenominatorTerm

/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

float10 DenominatorTerm(void)

{
  float in_EAX;
  float *unaff_ESI;
  float *unaff_EDI;
  undefined1 local_30 [16];
  float local_20;
  float local_1c;
  float local_18;
  
  local_20 = unaff_EDI[2] * unaff_ESI[1] - unaff_ESI[2] * unaff_EDI[1];
  local_1c = unaff_ESI[2] * *unaff_EDI - unaff_EDI[2] * *unaff_ESI;
  local_18 = unaff_EDI[1] * *unaff_ESI - *unaff_EDI * unaff_ESI[1];
  D3DXVec3Transform();
  return ((float10)(float)&local_20 * (float10)unaff_ESI[2] -
         (float10)in_EAX * (float10)unaff_ESI[1]) * (float10)*unaff_EDI +
         ((float10)in_EAX * (float10)*unaff_ESI - (float10)(float)local_30 * (float10)unaff_ESI[2])
         * (float10)unaff_EDI[1] +
         ((float10)(float)local_30 * (float10)unaff_ESI[1] -
         (float10)(float)&local_20 * (float10)*unaff_ESI) * (float10)unaff_EDI[2];
}


// ==== 0x46bae0 FUN_0046bae0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046bae0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  float *pfVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  float unaff_EBX;
  int *piVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float *pfStack_210;
  undefined4 uStack_208;
  float *pfStack_204;
  float fVar15;
  float fVar16;
  float fStack_1f0;
  float fStack_1ec;
  float fStack_1e8;
  float fStack_1e0;
  float fStack_1dc;
  float fStack_1d8;
  float fStack_1d4;
  float fStack_1d0;
  float fStack_1cc;
  float fStack_1c8;
  float fStack_1c4;
  float fStack_1bc;
  undefined1 auStack_1b8 [4];
  undefined4 uStack_1b4;
  float fStack_1b0;
  float fStack_1ac;
  float fStack_1a8;
  float fStack_1a4;
  float fStack_1a0;
  float fStack_19c;
  float fStack_198;
  float fStack_194;
  float fStack_190;
  float fStack_18c;
  float fStack_188;
  float *pfStack_184;
  float fStack_180;
  float fStack_17c;
  float fStack_178;
  float fStack_170;
  float fStack_16c;
  float fStack_168;
  float fStack_164;
  float local_160;
  float fStack_15c;
  float fStack_158;
  undefined1 auStack_150 [28];
  int iStack_134;
  float local_130;
  float fStack_12c;
  float fStack_128;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  undefined4 local_114;
  float fStack_110;
  float fStack_10c;
  float afStack_108 [4];
  float fStack_f8;
  float fStack_e0;
  float fStack_dc;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float afStack_c0 [2];
  float fStack_b8;
  float fStack_9c;
  float fStack_98;
  int iStack_94;
  float fStack_7c;
  float fStack_78;
  float fStack_70;
  float fStack_6c;
  float afStack_68 [4];
  float fStack_58;
  float fStack_50;
  float fStack_38;
  float fStack_30;
  
  pfStack_204 = (float *)0x46bb07;
  Contact__FindContactPointAndNormal();
  iVar7 = *(int *)(param_1 + 0x14);
  if (*(int *)(iVar7 + 0x264) == 0) {
    pfStack_204 = &local_130;
    uStack_208 = (float *)0x46bb21;
    CollisionBodyWitness__BeginCollision();
  }
  local_114 = *(undefined4 *)(iVar7 + 0x264);
  pfStack_204 = (float *)0x46bb36;
  pfVar6 = (float *)(**(code **)(**(int **)(param_1 + 0xc) + 8))();
  fStack_1dc = fStack_12c - pfVar6[1];
  fStack_1d8 = fStack_128 - pfVar6[2];
  fStack_1e0 = local_130 - *pfVar6;
  pfStack_204 = (float *)0x46bb69;
  pfVar6 = (float *)(**(code **)(**(int **)(param_1 + 0x10) + 8))();
  fStack_1cc = fStack_12c - pfVar6[1];
  fStack_1c8 = fStack_128 - pfVar6[2];
  fStack_1d0 = local_130 - *pfVar6;
  do {
    pfStack_204 = &fStack_110;
    uStack_208 = afStack_c0;
    (**(code **)(**(int **)(param_1 + 0xc) + 0x38))();
    pfStack_210 = afStack_68;
    (**(code **)(**(int **)(param_1 + 0x10) + 0x38))();
    fStack_9c = fStack_118 * fStack_1f0 - fStack_1e8 * fStack_120;
    fStack_98 = fStack_1ec * fStack_120 - fStack_11c * fStack_1f0;
    fStack_50 = (fStack_11c * fStack_1e8 - fStack_118 * fStack_1ec) + fStack_d0;
    fStack_58 = fStack_c8 + fStack_98;
    fStack_7c = afStack_108[0] * fStack_1e0 - fStack_1d8 * fStack_110;
    fStack_78 = fStack_1dc * fStack_110 - fStack_10c * fStack_1e0;
    afStack_c0[0] = (fStack_10c * fStack_1d8 - afStack_108[0] * fStack_1dc) + fStack_70;
    fStack_b8 = afStack_68[0] + fStack_78;
    fStack_e0 = afStack_c0[0] - fStack_50;
    fStack_dc = (fStack_6c + fStack_7c) - (fStack_cc + fStack_9c);
    fVar16 = fStack_e0 * fStack_170 + fStack_16c * fStack_dc + fStack_168 * (fStack_b8 - fStack_58);
    fVar15 = -fVar16;
    local_160 = fStack_170 * fVar15 + fStack_e0;
    fStack_15c = fStack_16c * fVar15 + fStack_dc;
    fStack_158 = fStack_168 * fVar15 + (fStack_b8 - fStack_58);
    if (0.0 <= fVar16) {
      return;
    }
    fStack_38 = fStack_b8;
    fVar12 = (float10)(**(code **)(**(int **)(param_1 + 0xc) + 0x6c))();
    fVar13 = (float10)(**(code **)(**(int **)(param_1 + 0x10) + 0x6c))();
    fStack_1a8 = (float)fVar12;
    if ((float10)(float)fVar12 <= fVar13) {
      fStack_1a8 = (float)fVar13;
    }
    cVar5 = Contact_IsSideSwipeCandidate(param_1,&fStack_1f0,&fStack_1e0);
    if (cVar5 != '\0') {
      fStack_1a8 = fStack_1a8 * 0.5;
    }
    fVar12 = (float10)(**(code **)(**(int **)(param_1 + 0xc) + 0x58))();
    fStack_1c4 = (float)fVar12;
    fVar12 = (float10)(**(code **)(**(int **)(param_1 + 0x10) + 0x58))();
    fVar1 = (float)fVar12;
    fStack_1a4 = -((fStack_1a8 + _K_ONE) * fVar16);
    (**(code **)(**(int **)(param_1 + 0xc) + 0x5c))();
    fVar13 = (float10)DenominatorTerm();
    fVar12 = (float10)fStack_1c4;
    (**(code **)(**(int **)(param_1 + 0x10) + 0x5c))();
    fVar14 = (float10)DenominatorTerm();
    fVar15 = (float)(fVar14 + (float10)(float)((float10)fVar1 + fVar12 + fVar13));
    if (fVar1 < fStack_1c4) {
      fVar1 = fStack_1c4;
    }
    fVar16 = fStack_1a4 / fVar15;
    if (fVar16 < _DAT_0070009c / fVar1) {
      fVar16 = _DAT_0070009c / fVar1;
    }
    fStack_190 = fStack_170 * fVar16;
    fStack_18c = fStack_16c * fVar16;
    fStack_188 = fStack_168 * fVar16;
    fVar12 = (float10)(**(code **)(**(int **)(param_1 + 0x10) + 0x48))(&fStack_190,&fStack_1e0);
    uStack_208 = (float *)(float)fVar12;
    fStack_198 = -fStack_198;
    fStack_194 = -fStack_194;
    fStack_190 = -fStack_190;
    fStack_30 = fStack_190;
    fVar12 = (float10)(**(code **)(**(int **)(param_1 + 0xc) + 0x48))(&fStack_198,&stack0xfffffe08);
    if (fVar12 == (float10)-57575.0) {
      return;
    }
    if ((float)pfStack_210 == -57575.0) {
      return;
    }
    uStack_1b4 = 1;
    if ((float10)0.0 <= fVar12) {
      if (0.0 <= (float)pfStack_210) {
        uStack_1b4 = 0;
      }
      else {
        pfStack_210 = (float *)-(float)pfStack_210;
      }
    }
    else {
      fVar12 = -fVar12;
    }
    if ((float10)(float)pfStack_210 <= fVar12) {
      pfStack_184 = pfStack_210;
    }
    else {
      pfStack_184 = (float *)(float)fVar12;
    }
    fVar2 = (float)pfStack_184 * (float)afStack_108;
    fVar12 = (float10)(**(code **)(**(int **)(param_1 + 0xc) + 0x70))();
    fVar1 = (float)fVar12;
    fVar12 = (float10)(**(code **)(**(int **)(param_1 + 0x10) + 0x70))();
    fStack_1bc = fVar1;
    if ((float10)fVar1 <= fVar12) {
      fStack_1bc = (float)fVar12;
    }
    piVar11 = (int *)0x0;
    uStack_208 = (float *)((uint)uStack_208 & 0xffffff);
    if ((((fStack_1d4 != 0.0) || (fVar12 != (float10)0.3)) ||
        (*(char *)((int)*(int **)(param_1 + 0x10) + 0x15) != '\0')) ||
       (iVar7 = (**(code **)(**(int **)(param_1 + 0x10) + 0x14))(), *(float *)(iVar7 + 0x28) <= 0.7)
       ) {
      if ((((float)pfStack_204 == 0.0) && (fVar1 == 0.3)) &&
         ((*(char *)((int)*(int **)(param_1 + 0xc) + 0x15) == '\0' &&
          (iVar7 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))(), 0.7 < *(float *)(iVar7 + 0x28)
          )))) {
        piVar11 = *(int **)(param_1 + 0xc);
        goto LAB_0046c09b;
      }
    }
    else {
      piVar11 = *(int **)(param_1 + 0x10);
LAB_0046c09b:
      fStack_1bc = 0.1;
      uStack_208 = (float *)CONCAT13(1,(undefined3)uStack_208);
    }
    iVar7 = iStack_134;
    pfStack_204 = (float *)SQRT(fStack_170 * fStack_170 +
                                fStack_16c * fStack_16c + fStack_168 * fStack_168);
    fStack_158 = fStack_1bc * fVar2;
    if ((float)pfStack_204 < _DAT_007000a8) {
      fStack_158 = (fStack_158 / _DAT_007000a8) * (float)pfStack_204;
    }
    if ((float)pfStack_204 <= _K_EPS_SPEED) {
      local_160 = 0.0;
      fStack_15c = 0.0;
      fStack_158 = 0.0;
    }
    else {
      fStack_158 = (-1.0 / (float)pfStack_204) * fStack_158;
      local_160 = fStack_170 * fStack_158;
      fStack_15c = fStack_16c * fStack_158;
      fStack_158 = fStack_168 * fStack_158;
    }
    fStack_1a0 = fStack_180 * fVar2;
    fStack_19c = fStack_17c * fVar2;
    fStack_198 = fStack_178 * fVar2;
    cVar5 = Collision__IsWallInvolved();
    fStack_1c8 = fStack_158;
    if (cVar5 != '\0') {
      fStack_1c8 = fStack_158 * 1.0;
    }
    fStack_1d0 = local_160 + fStack_1a0;
    fStack_1cc = fStack_15c + fStack_19c;
    fStack_1c8 = fStack_198 + fStack_1c8;
    fStack_1b0 = -fStack_1d0;
    fStack_1ac = -fStack_1cc;
    fStack_1a8 = -fStack_1c8;
    if (uStack_208._3_1_ != '\0') {
      pfVar6 = (float *)(**(code **)(*piVar11 + 0xc))();
      fVar1 = pfVar6[1];
      fStack_110 = *pfVar6;
      fVar2 = SQRT(fStack_110 * fStack_110 + pfVar6[2] * pfVar6[2] + fVar1 * fVar1);
      if (30.0 < fVar2) {
        fVar3 = -0.025;
        if (fVar2 * -0.025 < -0.4) {
          fVar3 = (-1.0 / fVar2) * 0.4;
        }
        fStack_110 = fStack_110 * fVar3;
        if (fStack_1d4 == 0.0) {
          fVar4 = SQRT(fStack_1d0 * fStack_1d0 + fStack_1c8 * fStack_1c8 + fStack_1cc * fStack_1cc);
          fStack_1d0 = fStack_110 + fStack_1d0;
          fStack_1cc = fVar3 * fVar1 + fStack_1cc;
          if (_K_ONE < fVar4 + fVar2) {
            fVar4 = fVar4 / (fVar2 / 1.75 + fVar4);
            fStack_1f0 = fStack_1f0 * fVar4;
            fStack_1ec = fStack_1ec * fVar4;
            fStack_1e8 = fStack_1e8 * fVar4;
          }
        }
        else {
          fVar4 = SQRT(fStack_1b0 * fStack_1b0 + fStack_1a8 * fStack_1a8 + fStack_1ac * fStack_1ac);
          fStack_1b0 = fStack_110 + fStack_1b0;
          fStack_1ac = fVar3 * fVar1 + fStack_1ac;
          if (_K_ONE < fVar4 + fVar2) {
            fVar4 = fVar4 / (fVar2 / 1.75 + fVar4);
            fVar15 = fVar15 * fVar4;
            fVar16 = fVar16 * fVar4;
            unaff_EBX = unaff_EBX * fVar4;
          }
        }
      }
    }
    FUN_00465830(iVar7,auStack_150,&fStack_1b0,pfStack_204);
    if (*(int *)(iVar7 + 0x10) != 0) {
      iStack_94 = *(int *)(param_1 + 0x10);
      if ((*(char *)(*(int *)(param_1 + 0xc) + 0x15) == '\0') &&
         (iVar7 = *(int *)(*(int *)(param_1 + 0xc) + 0x140), *(int *)(iVar7 + 0x3cc) == 4)) {
        fStack_f8 = *(float *)(iVar7 + 0xb8);
        fVar15 = *(float *)(iVar7 + 0xb0) * fVar15 +
                 *(float *)(iVar7 + 0xb4) * fVar16 + fStack_f8 * unaff_EBX;
        afStack_c0[0] = *(float *)(iVar7 + 0xb0) * fVar15;
        unaff_EBX = unaff_EBX - fStack_f8 * fVar15;
      }
      if ((*(char *)(iStack_94 + 0x15) == '\0') &&
         (iVar7 = *(int *)(iStack_94 + 0x140), *(int *)(iVar7 + 0x3cc) == 4)) {
        fStack_f8 = *(float *)(iVar7 + 0xb8);
        fVar15 = *(float *)(iVar7 + 0xb0) * fStack_1f0 +
                 *(float *)(iVar7 + 0xb4) * fStack_1ec + fStack_f8 * fStack_1e8;
        afStack_c0[0] = *(float *)(iVar7 + 0xb0) * fVar15;
        fStack_1f0 = fStack_1f0 - afStack_c0[0];
        fStack_1ec = fStack_1ec - *(float *)(iVar7 + 0xb4) * fVar15;
        fStack_1e8 = fStack_1e8 - fStack_f8 * fVar15;
      }
    }
    piVar11 = *(int **)(param_1 + 0xc);
    piVar9 = (int *)0x0;
    if ((((*(char *)((int)piVar11 + 0x15) != '\0') ||
         (piVar8 = *(int **)(param_1 + 0x10), *(char *)((int)piVar8 + 0x15) != '\x01')) ||
        (piVar10 = piVar11, piVar8[0x4c] < 1)) &&
       (((piVar8 = *(int **)(param_1 + 0x10), piVar10 = piVar9,
         *(char *)((int)piVar8 + 0x15) == '\0' && (*(char *)((int)piVar11 + 0x15) == '\x01')) &&
        (0 < piVar11[0x4c])))) {
      piVar10 = piVar8;
    }
    if (piVar11 == piVar10) {
      fStack_1a8 = fStack_1a8 * 0.25;
      if (fStack_1a8 < 0.0) {
        fStack_1a8 = 0.0;
      }
    }
    else if ((piVar8 == piVar10) && (fStack_1c8 = fStack_1c8 * 0.25, fStack_1c8 < 0.0)) {
      fStack_1c8 = 0.0;
    }
    (**(code **)(*piVar8 + 0x4c))(&fStack_1d0,&fStack_1f0);
    (**(code **)(**(int **)(param_1 + 0xc) + 0x4c))(auStack_1b8,&uStack_208);
    if (fStack_164 == _K_ONE) {
      return;
    }
    if (fStack_194 != 0.0) {
      return;
    }
  } while( true );
}


// ==== 0x46c620 Contact_IsSideSwipeCandidate

/* [canon] car low (ghidra-canon) docs/re/car.md */

uint __fastcall
Contact_IsSideSwipeCandidate
          (undefined4 param_1,int *param_2,undefined4 param_3,int param_4,int param_5)

{
  float fVar1;
  int *in_EAX;
  int *piVar2;
  float *pfVar4;
  float local_20;
  float fStack_1c;
  float fStack_18;
  int *piVar3;
  
  piVar3 = in_EAX;
  if ((*(char *)((int)param_2 + 0x15) == '\0') && (*(char *)((int)in_EAX + 0x15) == '\x03')) {
    fVar1 = ABS(*(float *)(in_EAX[0x18] + 0x78));
    piVar2 = (int *)CONCAT22((short)((uint)in_EAX[0x18] >> 0x10),
                             (ushort)(fVar1 < 0.1) << 8 | (ushort)NAN(fVar1) << 10 |
                             (ushort)(fVar1 == 0.1) << 0xe);
    piVar3 = piVar2;
    if (fVar1 >= 0.1) goto LAB_0046c655;
  }
  else {
LAB_0046c655:
    piVar2 = (int *)CONCAT31((int3)((uint)piVar3 >> 8),*(char *)((int)in_EAX + 0x15));
    if ((*(char *)((int)in_EAX + 0x15) != '\0') || (*(char *)((int)param_2 + 0x15) != '\x03'))
    goto LAB_0046c6c1;
    fVar1 = ABS(*(float *)(param_2[0x18] + 0x78));
    piVar2 = (int *)CONCAT22((short)((uint)piVar3 >> 0x10),
                             (ushort)(fVar1 < 0.1) << 8 | (ushort)NAN(fVar1) << 10 |
                             (ushort)(fVar1 == 0.1) << 0xe);
    param_4 = param_5;
    param_2 = in_EAX;
    if (fVar1 >= 0.1) goto LAB_0046c6c1;
  }
  if ((param_2 != (int *)0x0) && (param_4 != 0)) {
    bNormalize3();
    pfVar4 = (float *)(**(code **)(*param_2 + 0x14))();
    fVar1 = ABS(local_20 * *pfVar4 + fStack_18 * pfVar4[2] + fStack_1c * pfVar4[1]);
    piVar2 = (int *)CONCAT22((short)((uint)pfVar4 >> 0x10),
                             (ushort)(fVar1 < 0.9) << 8 | (ushort)NAN(fVar1) << 10 |
                             (ushort)(fVar1 == 0.9) << 0xe);
    if (fVar1 < 0.9) {
      return CONCAT31((int3)((uint)piVar2 >> 8),1);
    }
  }
LAB_0046c6c1:
  return (uint)piVar2 & 0xffffff00;
}


// ==== 0x46c6d0 Float9_Max_Off34

/* [canon] car med (ghidra-canon) docs/re/car.md */

float10 __fastcall Float9_Max_Off34(int param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)0.0;
  if (0.0 < *(float *)(param_1 + 0x34)) {
    fVar1 = (float10)*(float *)(param_1 + 0x34);
  }
  if (fVar1 < (float10)*(float *)(param_1 + 0x38)) {
    fVar1 = (float10)*(float *)(param_1 + 0x38);
  }
  if (fVar1 < (float10)*(float *)(param_1 + 0x3c)) {
    fVar1 = (float10)*(float *)(param_1 + 0x3c);
  }
  if (fVar1 < (float10)*(float *)(param_1 + 0x40)) {
    fVar1 = (float10)*(float *)(param_1 + 0x40);
  }
  if (fVar1 < (float10)*(float *)(param_1 + 0x44)) {
    fVar1 = (float10)*(float *)(param_1 + 0x44);
  }
  if (fVar1 < (float10)*(float *)(param_1 + 0x48)) {
    fVar1 = (float10)*(float *)(param_1 + 0x48);
  }
  if (fVar1 < (float10)*(float *)(param_1 + 0x4c)) {
    fVar1 = (float10)*(float *)(param_1 + 0x4c);
  }
  if (fVar1 < (float10)*(float *)(param_1 + 0x50)) {
    fVar1 = (float10)*(float *)(param_1 + 0x50);
  }
  if (fVar1 < (float10)*(float *)(param_1 + 0x54)) {
    fVar1 = (float10)*(float *)(param_1 + 0x54);
  }
  return fVar1;
}


// ==== 0x46c770 FUN_0046c770

int __fastcall FUN_0046c770(int param_1)

{
  return param_1 + 0x14;
}


// ==== 0x46c780 Engine::GetState

/* [canon] car med (ghidra-canon+nfsug) docs/re/car.md */

void __thiscall Engine__GetState(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x14);
  return;
}


// ==== 0x46c790 Engine::SetState

/* [canon] car med (ghidra-canon+nfsug) docs/re/car.md */

void __thiscall Engine__SetState(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x14) = *param_2;
  return;
}


// ==== 0x46c7a0 FUN_0046c7a0

void __fastcall FUN_0046c7a0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00735f7c;
  iVar1 = *(int *)(DAT_00735f7c + 0x18);
  *param_1 = *(undefined4 *)(DAT_00735f7c + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x46c7c0 FUN_0046c7c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0046c7c0(float *param_1,undefined4 param_2)

{
  char *pcVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  char *pcVar5;
  undefined4 *unaff_ESI;
  float10 fVar6;
  
  *unaff_ESI = &PTR_Engine__scalar_deleting_destructor_006c8508;
  fVar2 = param_1[2];
  fVar3 = *param_1;
  unaff_ESI[10] = fVar3;
  unaff_ESI[9] = 9;
  unaff_ESI[0xb] = fVar2;
  unaff_ESI[0xd] = param_1 + 4;
  unaff_ESI[0xc] = K_ONE / (fVar2 - fVar3);
  fVar2 = param_1[2];
  fVar3 = *param_1;
  unaff_ESI[0x12] = param_1 + 0x16;
  unaff_ESI[0xf] = fVar3;
  unaff_ESI[0xe] = 3;
  unaff_ESI[0x10] = fVar2;
  unaff_ESI[0x11] = 2.0 / (fVar2 - fVar3);
  fVar2 = param_1[2];
  fVar3 = *param_1;
  unaff_ESI[0x13] = 9;
  unaff_ESI[0x14] = fVar3;
  unaff_ESI[0x17] = param_1 + 0xd;
  unaff_ESI[0x15] = fVar2;
  unaff_ESI[0x16] = K_ONE / (fVar2 - fVar3);
  fVar2 = param_1[1];
  fVar3 = *param_1;
  unaff_ESI[0x18] = 9;
  unaff_ESI[0x19] = fVar3;
  unaff_ESI[0x1c] = &DAT_006fff34;
  unaff_ESI[0x1a] = fVar2;
  unaff_ESI[0x1b] = K_ONE / (fVar2 - fVar3);
  unaff_ESI[7] = param_2;
  unaff_ESI[6] = param_1;
  unaff_ESI[0x1d] = 0;
  unaff_ESI[0x21] = 0;
  unaff_ESI[0x22] = 0;
  unaff_ESI[0x20] = 0x3f800000;
  unaff_ESI[0x28] = 0x3f800000;
  fVar2 = (float)DAT_0073ad34;
  unaff_ESI[0x23] = 0;
  unaff_ESI[0x25] = 0;
  unaff_ESI[0x26] = 0;
  unaff_ESI[0x27] = 0;
  unaff_ESI[0x24] = fVar2 * 0.00025;
  unaff_ESI[0x29] = 0;
  unaff_ESI[0x2b] = 0;
  unaff_ESI[0x2d] = 0;
  unaff_ESI[0x2e] = 0;
  unaff_ESI[0x2c] = 0;
  unaff_ESI[0x2f] = 0;
  fVar6 = (float10)Float9_Max_Off34();
  unaff_ESI[0x2a] = (float)fVar6;
  pcVar1 = (char *)(unaff_ESI + 3);
  unaff_ESI[8] = 0;
  *pcVar1 = 'E';
  pcVar5 = pcVar1;
  do {
    cVar4 = pcVar5[(int)("Engine" + (1 - (int)pcVar1))];
    pcVar5 = pcVar5 + 1;
    *pcVar5 = cVar4;
  } while (cVar4 != '\0');
  return;
}


// ==== 0x46c920 Engine::scalar_deleting_destructor

/* [canon] car med (ghidra-canon+nfsug) docs/re/car.md */

void Engine__scalar_deleting_destructor(byte param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)FUN_00584950();
  iVar2 = DAT_00735f78;
  if ((param_1 & 1) != 0) {
    iVar1 = *(int *)(DAT_00735f78 + 0x18);
    *puVar3 = *(undefined4 *)(DAT_00735f78 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = puVar3;
  }
  return;
}


// ==== 0x46c950 FUN_0046c950

void FUN_0046c950(void)

{
  int in_EAX;
  int iVar1;
  char cVar2;
  int unaff_ESI;
  
  if (*(char *)(unaff_ESI + 0x3d) != '\0' || *(char *)(unaff_ESI + 0x3c) != '\0') {
    *(undefined4 *)(in_EAX + 0xa0) = 0;
  }
  FUN_00571ea0(0,"Engine");
  FUN_00571c20(unaff_ESI,in_EAX + 0x14,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x78,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x7c,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x80,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x88,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x84,4,4,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x8c,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x90,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x94,4,4,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x98,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x9c,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0xa4,4,0xffffffff,0);
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


// ==== 0x46ca90 FUN_0046ca90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0046ca90(int param_1)

{
  float fVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  pfVar2 = *(float **)(param_1 + 0x18);
  fVar3 = *pfVar2 * 0.10471967;
  if (*pfVar2 * 0.10471967 < *(float *)(param_1 + 0x14)) {
    fVar3 = *(float *)(param_1 + 0x14);
  }
  if (pfVar2[2] * 0.10471967 < fVar3) {
    fVar3 = pfVar2[2] * 0.10471967;
  }
  *(float *)(param_1 + 0x14) = fVar3;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  if (((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) && (*(int *)(param_1 + 0x94) == 0)) {
    if ((*DAT_0073619c < 4) ||
       ((*(int *)(*(int *)(param_1 + 0x20) + 0x3c) == 2 &&
        (0.0 < *(float *)(*(int *)(param_1 + 0x20) + 0x68))))) {
      *(float *)(param_1 + 0x90) = (float)DAT_0073ad34 * 0.00025;
    }
    fVar4 = (float)DAT_0073ad34;
    fVar1 = *(float *)(param_1 + 0x90);
    *(float *)(param_1 + 0x90) = fVar4 * 0.00025;
    fVar5 = _DAT_00700000;
    if (pfVar2[1] <= fVar3 * 9.549304) {
      fVar5 = _DAT_006ffff8;
    }
    if (*(int *)(param_1 + 0x84) != 0) {
      fVar5 = fVar5 + _DAT_006ffffc;
    }
    if ((fVar5 < 0.0) || (*(float *)(param_1 + 0x8c) < _K_ONE)) {
      *(float *)(param_1 + 0x8c) = fVar5 * (fVar4 * 0.00025 - fVar1) + *(float *)(param_1 + 0x8c);
    }
    if (*(float *)(param_1 + 0x8c) < 0.0) {
      *(undefined4 *)(param_1 + 0x8c) = 0;
    }
    if (*(float *)(param_1 + 0x8c) < 0.95) {
      *(undefined4 *)(param_1 + 0x98) = 0;
    }
    else {
      if (*(float *)(param_1 + 0x98) == 0.0) {
        *(float *)(param_1 + 0x98) = (float)DAT_0073ad34 * 0.00025;
      }
      if (1.0 < (float)DAT_0073ad34 * 0.00025 - *(float *)(param_1 + 0x98)) {
        *(undefined4 *)(param_1 + 0x94) = 1;
      }
    }
  }
  if (*(float *)(param_1 + 0x9c) == 0.0) {
    if (pfVar2[2] - 50.0 < fVar3 * 9.549304) {
      *(float *)(param_1 + 0x9c) =
           (float)DAT_0073ad34 * 0.00025 +
           *(float *)(&DAT_00700004 + *(int *)(*(int *)(param_1 + 0x20) + 0x3c) * 4);
      FUN_0046ccc0();
      return;
    }
  }
  else if (*(float *)(param_1 + 0x9c) < (float)DAT_0073ad34 * 0.00025) {
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  FUN_0046ccc0();
  return;
}


// ==== 0x46ccc0 FUN_0046ccc0

void FUN_0046ccc0(void)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  bool bVar7;
  int unaff_ESI;
  float10 fVar8;
  
  if (*(float *)(unaff_ESI + 0xa8) < 0.0 == (*(float *)(unaff_ESI + 0xa8) == 0.0)) {
    fVar6 = (float)DAT_0073ad34 * 0.00025 - *(float *)(unaff_ESI + 0xbc);
    if (0.016666668 < fVar6) {
      *(float *)(unaff_ESI + 0xbc) = (float)DAT_0073ad34 * 0.00025;
      iVar1 = *(int *)(unaff_ESI + 0xac);
      fVar3 = *(float *)(unaff_ESI + 0x14) * 9.549304;
      fVar4 = *(float *)(unaff_ESI + 0xa8) / 0.19;
      fVar5 = -(fVar4 * 0.25);
      if (iVar1 == 0) {
        fVar8 = (float10)Engine__GetEffectiveThrottle();
        if (fVar8 < (float10)0.3) {
          pfVar2 = *(float **)(unaff_ESI + 0x18);
          fVar6 = (fVar3 - *pfVar2) / (pfVar2[2] - *pfVar2);
          fVar8 = (float10)bMin(0x3f800000,fVar6 + fVar6);
          *(float *)(unaff_ESI + 0xa4) = (float)(fVar8 * (float10)fVar5);
          return;
        }
        *(undefined4 *)(unaff_ESI + 0xac) = 1;
        return;
      }
      if (iVar1 == 1) {
        fVar8 = (float10)Engine__GetEffectiveThrottle();
        if ((float10)0.3 <= fVar8) {
          pfVar2 = *(float **)(unaff_ESI + 0x18);
          fVar8 = (float10)Engine__GetEffectiveThrottle();
          fVar8 = (float10)bMin(0x3f800000,(float)fVar8);
          fVar8 = (float10)bMin(fVar4,(float)((((float10)fVar3 - (float10)*pfVar2) /
                                              ((float10)pfVar2[2] - (float10)*pfVar2)) * fVar8 *
                                              (float10)2.0 * (float10)fVar6 +
                                             (float10)*(float *)(unaff_ESI + 0xa4)));
          *(float *)(unaff_ESI + 0xa4) = (float)fVar8;
          return;
        }
        if (*(float *)(unaff_ESI + 0x9c) == 0.0) {
          *(undefined4 *)(unaff_ESI + 0xac) = 2;
          *(float *)(unaff_ESI + 0xb4) = fVar6;
          *(undefined4 *)(unaff_ESI + 0xb0) = *(undefined4 *)(unaff_ESI + 0xa4);
          return;
        }
      }
      else if (iVar1 == 2) {
        fVar3 = *(float *)(unaff_ESI + 0xb4) + 1.1;
        fVar3 = fVar3 * fVar3;
        bVar7 = false;
        fVar8 = (float10)FUN_00405610(fVar3 * fVar3 * 6.5,fVar5 + fVar5,
                                      *(undefined4 *)(unaff_ESI + 0xb0));
        fVar8 = (float10)bClampF((float)((((float10)*(float *)(unaff_ESI + 0xb0) / (float10)fVar4) /
                                         (float10)*(float *)(unaff_ESI + 0xb4)) * fVar8 *
                                         (float10)0.015 + (float10)fVar5));
        if (*(float *)(unaff_ESI + 0xb8) == 0.0) {
          *(float *)(unaff_ESI + 0xb8) = (float)fVar8;
        }
        else if ((((float10)*(float *)(unaff_ESI + 0xa4) < fVar8) &&
                 (fVar8 < (float10)*(float *)(unaff_ESI + 0xb8))) ||
                ((fVar8 < (float10)*(float *)(unaff_ESI + 0xa4) &&
                 ((float10)*(float *)(unaff_ESI + 0xb8) < fVar8)))) {
          if (0.15 <= ABS(*(float *)(unaff_ESI + 0xa4) - *(float *)(unaff_ESI + 0xb8))) {
            *(undefined4 *)(unaff_ESI + 0xb8) = *(undefined4 *)(unaff_ESI + 0xa4);
          }
          else {
            bVar7 = true;
          }
        }
        fVar6 = fVar6 + *(float *)(unaff_ESI + 0xb4);
        *(float *)(unaff_ESI + 0xb4) = fVar6;
        *(float *)(unaff_ESI + 0xa4) = (float)fVar8;
        if ((bVar7) || (0.5 < fVar6)) {
          *(undefined4 *)(unaff_ESI + 0xac) = 0;
          *(undefined4 *)(unaff_ESI + 0xb8) = 0;
          return;
        }
      }
    }
  }
  return;
}


// ==== 0x46cf80 FUN_0046cf80

undefined4 __thiscall FUN_0046cf80(int param_1,float *param_2)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  
  fVar2 = (float10)FUN_0046cff0();
  fVar3 = (float10)*(float *)(*(int *)(param_1 + 0x18) + 0xc);
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0x44);
  if ((iVar1 == 2) || (iVar1 == 0)) {
    fVar3 = fVar3 * (float10)1.0;
  }
  *param_2 = (float)((fVar2 + (float10)*(float *)(param_1 + 0x7c)) / fVar3);
  return 0;
}


// ==== 0x46cfc0 Engine::GetEffectiveThrottle

/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

float10 __fastcall Engine__GetEffectiveThrottle(int param_1)

{
  if (*(float *)(param_1 + 0x9c) == 0.0) {
    return (float10)*(float *)(param_1 + 0x80) * (float10)*(float *)(param_1 + 0x78);
  }
  return (float10)0.0;
}


// ==== 0x46cff0 FUN_0046cff0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0046cff0(void)

{
  int iVar1;
  float fVar2;
  int unaff_EDI;
  float10 fVar3;
  float10 fVar4;
  undefined4 local_8;
  undefined4 local_4;
  
  fVar3 = (float10)FUN_00583ea0(*(float *)(unaff_EDI + 0x14) * 9.549304);
  fVar3 = fVar3 * (float10)*(float *)(unaff_EDI + 0xa0);
  if (*(int *)(unaff_EDI + 0x74) != 0) {
    fVar3 = fVar3 * (float10)_DAT_00700024;
  }
  if (*(float *)(unaff_EDI + 0x9c) == 0.0) {
    fVar4 = (float10)*(float *)(unaff_EDI + 0x80) * (float10)*(float *)(unaff_EDI + 0x78);
  }
  else {
    fVar4 = (float10)0.0;
  }
  local_8 = (float)(fVar3 * fVar4);
  if (*(int *)(unaff_EDI + 0x84) != 0) {
    iVar1 = **(int **)(unaff_EDI + 0x1c);
    fVar3 = (float10)FUN_00583ea0(*(float *)(unaff_EDI + 0x14) * 9.549304);
    local_8 = (float)(fVar3 * (float10)*(float *)(iVar1 + 0x2ac) + (float10)local_8);
    if (((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) &&
       (fVar2 = _DAT_0070002c + *(float *)(unaff_EDI + 0x88),
       (float)DAT_0073ad34 * 0.00025 < fVar2 != ((float)DAT_0073ad34 * 0.00025 == fVar2))) {
      local_8 = local_8 * 1.5;
    }
  }
  if (_DAT_006ffff0 < *(float *)(unaff_EDI + 0x8c)) {
    local_8 = ((_K_ONE - (*(float *)(unaff_EDI + 0x8c) - _DAT_006ffff0) / (_K_ONE - _DAT_006ffff0))
              / 1.1) * local_8;
  }
  if (*(float *)(unaff_EDI + 0x9c) == 0.0) {
    local_4 = *(float *)(unaff_EDI + 0x80) * *(float *)(unaff_EDI + 0x78);
  }
  else {
    local_4 = 0.0;
  }
  fVar3 = (float10)FUN_00583ea0(*(float *)(unaff_EDI + 0x14) * 9.549304);
  fVar3 = -(((float10)_K_ONE - (float10)local_4) * fVar3);
  if ((0.0 < *(float *)(unaff_EDI + 0x9c)) && (*(int *)(*(int *)(unaff_EDI + 0x20) + 0x3c) != 1)) {
    fVar3 = fVar3 * (float10)4.0;
  }
  fVar3 = fVar3 + (float10)local_8;
  if (fVar3 < (float10)0.0) {
    if (*(int *)(*(int *)(unaff_EDI + 0x20) + 0x3c) == 1) {
      return fVar3 * (float10)0.85;
    }
    if (*(int *)(*(int *)(unaff_EDI + 0x1c) + 0x3c0) == 1) {
      fVar3 = fVar3 * (float10)0.4;
    }
  }
  return fVar3;
}


// ==== 0x46d1c0 FUN_0046d1c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0046d1c0(undefined4 param_1,int param_2,float *param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  float *unaff_EDI;
  float10 fVar9;
  float10 fVar10;
  float *local_34;
  
  iVar6 = (int)param_4;
  iVar8 = 2;
  *(float *)((int)param_4 + 4) = (unaff_EDI[1] - *unaff_EDI) * *param_3 + *unaff_EDI;
  fVar1 = param_3[6];
  if ((int)fVar1 + 1 < 3) {
    *(float *)((int)param_4 + 8) = unaff_EDI[1];
    return;
  }
  local_34 = (float *)(param_2 + 0xc);
  pfVar7 = param_3 + 0xb;
  do {
    fVar2 = pfVar7[-1];
    fVar3 = *pfVar7;
    if (DAT_00700030 == 0) {
      param_4 = (unaff_EDI[1] - *unaff_EDI) * *param_3 + *unaff_EDI;
    }
    else {
      fVar4 = unaff_EDI[1];
      param_4 = (unaff_EDI[1] + *unaff_EDI) * _K_HALF;
      if (param_4 < fVar4) {
        do {
          fVar9 = (float10)FUN_00583ea0(param_4);
          if (ABS(fVar2) <= _K_EPS_SPEED) {
            fVar10 = (float10)0.0;
          }
          else {
            fVar5 = _K_ONE / fVar2;
            fVar10 = (float10)FUN_00583ea0(fVar5 * param_4 * fVar3);
            fVar10 = fVar10 * (float10)fVar5 * (float10)fVar3;
          }
          if ((float10)(float)fVar9 < fVar10) goto LAB_0046d319;
          param_4 = param_4 + 50.0;
        } while (param_4 < fVar4);
      }
      param_4 = unaff_EDI[1] - 100.0;
    }
LAB_0046d319:
    *(float *)(iVar6 + iVar8 * 4) = param_4;
    if (ABS(fVar2) <= _K_EPS_SPEED) {
      *local_34 = 0.0;
    }
    else {
      *local_34 = (fVar3 / fVar2) * *(float *)(iVar6 + iVar8 * 4);
    }
    iVar8 = iVar8 + 1;
    pfVar7 = pfVar7 + 1;
    local_34 = local_34 + 1;
    if ((int)fVar1 + 1 <= iVar8) {
      *(float *)(iVar6 + iVar8 * 4) = unaff_EDI[1];
      return;
    }
  } while( true );
}


// ==== 0x46d390 DriveTrain::DriveTrain

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 * __fastcall
DriveTrain__DriveTrain
          (undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
          undefined4 *param_5,undefined4 param_6)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006854b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_3[7] = param_2;
  *param_3 = &PTR_DriveTrain__scalar_deleting_destructor_006c84e4;
  param_3[6] = param_4;
  param_3[0x38] = 3;
  param_3[8] = param_1;
  param_3[9] = *param_5;
  param_3[10] = param_5[1];
  param_3[0xb] = param_5[2];
  param_3[0xc] = param_5[3];
  param_3[0xf] = 1;
  param_3[0xe] = 1;
  param_3[0xd] = param_6;
  param_3[5] = 0;
  param_3[0x11] = 2;
  param_3[0x12] = 0;
  param_3[0x16] = 0;
  param_3[0x18] = 0;
  param_3[0x17] = 0;
  param_3[0x19] = 0;
  param_3[0x1a] = 0;
  param_3[0x1b] = 0;
  local_4 = 0;
  FUN_0046d1c0(param_4,param_3 + 0x20);
  FUN_0046d760();
  uVar3 = DAT_006fff30;
  param_3[0x21] = *(float *)(param_3[7] + 0x5c) * (float)param_3[0x21];
  param_3[0x32] = uVar3;
  param_3[0x33] = 0;
  param_3[0x34] = 0xc2c80000;
  param_3[0x35] = 0;
  param_3[0x36] = 0x3f800000;
  param_3[0x37] = 0x3f800000;
  pcVar1 = (char *)(param_3 + 3);
  param_3[0x39] = *(undefined4 *)(param_3[7] + 0x60);
  *(undefined1 *)(param_3 + 0x1d) = 0;
  *pcVar1 = 'D';
  pcVar4 = pcVar1;
  do {
    cVar2 = pcVar4[(int)("Drvtrn" + (1 - (int)pcVar1))];
    pcVar4 = pcVar4 + 1;
    *pcVar4 = cVar2;
  } while (cVar2 != '\0');
  ExceptionList = local_c;
  return param_3;
}


// ==== 0x46d4e0 DriveTrain::scalar_deleting_destructor

/* [canon] car med (ghidra-canon) docs/re/car.md */

undefined4 * __thiscall DriveTrain__scalar_deleting_destructor(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_00584950();
  iVar2 = DAT_00735f7c;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00735f7c + 0x18);
    *param_1 = *(undefined4 *)(DAT_00735f7c + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x46d510 FUN_0046d510

void FUN_0046d510(void)

{
  int iVar1;
  char cVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  FUN_00571ea0(0,"DriveTrain");
  FUN_00571c20(unaff_ESI,unaff_EDI + 0x14,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,unaff_EDI + 0x38,1,4,1);
  FUN_00571c20(unaff_ESI,unaff_EDI + 0x54,1,4,1);
  FUN_00571c20(unaff_ESI,unaff_EDI + 0x40,1,4,1);
  FUN_00571c20(unaff_ESI,unaff_EDI + 0x3c,1,4,1);
  FUN_00571c20(unaff_ESI,unaff_EDI + 0x44,1,4,1);
  FUN_00571c20(unaff_ESI,unaff_EDI + 0x48,4,4,0);
  FUN_00571c20(unaff_ESI,unaff_EDI + 0x4c,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,unaff_EDI + 0x50,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,unaff_EDI + 0x58,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,unaff_EDI + 0x5c,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,unaff_EDI + 0x60,1,4,0);
  FUN_00571c20(unaff_ESI,unaff_EDI + 100,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,unaff_EDI + 0x68,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,unaff_EDI + 0x6c,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,unaff_EDI + 0x74,1,1,0);
  FUN_00571c20(unaff_ESI,unaff_EDI + 0x78,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,unaff_EDI + 0x7c,4,0xffffffff,0);
  *(undefined4 *)(unaff_EDI + 0x70) = 0;
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


// ==== 0x46d680 FUN_0046d680

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_0046d680(undefined4 param_1,int param_2)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  
  iVar2 = *(int *)(param_2 + 0x18);
  fVar3 = (float10)0.0;
  if (0.001 <= *(float *)(iVar2 + 0x10)) {
    fVar3 = ((float10)*(float *)(*(int *)(param_2 + 0x30) + 0x28) +
            (float10)*(float *)(*(int *)(param_2 + 0x2c) + 0x28)) * (float10)_K_HALF *
            (float10)*(float *)(iVar2 + 0xc);
  }
  fVar1 = *(float *)(iVar2 + 0x10);
  if ((!NAN(fVar1) && fVar1 < 0.999 != (fVar1 == 0.999)) &&
     (fVar3 = ((float10)*(float *)(*(int *)(param_2 + 0x28) + 0x28) +
              (float10)*(float *)(*(int *)(param_2 + 0x24) + 0x28)) * (float10)_K_HALF *
              (float10)*(float *)(iVar2 + 8) + fVar3, 0.001 <= *(float *)(iVar2 + 0x10))) {
    fVar3 = fVar3 * (float10)_K_HALF;
  }
  return fVar3 * (float10)*(float *)(iVar2 + 0x20 + *(int *)(param_2 + 0x3c) * 4);
}


// ==== 0x46d700 FUN_0046d700

float10 __thiscall FUN_0046d700(char param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  float10 fVar3;
  
  if (param_1 == '\0') {
    fVar1 = *(float *)(in_EAX + 0x78);
  }
  else {
    fVar1 = *(float *)(in_EAX + 200);
  }
  fVar1 = fVar1 + *(float *)(in_EAX + 0x80 + param_2 * 4);
  if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
    fVar2 = *(float *)(*(int *)(*(int *)(in_EAX + 0x20) + 0x18) + 4);
  }
  else {
    fVar2 = *(float *)(*(int *)(*(int *)(in_EAX + 0x20) + 0x18) + 8);
  }
  fVar3 = (float10)fVar2;
  if ((float10)fVar1 <= fVar3) {
    fVar3 = (float10)fVar1;
  }
  return fVar3;
}


// ==== 0x46d760 FUN_0046d760

/* WARNING: Removing unreachable block (ram,0x0046d7af) */
/* WARNING: Removing unreachable block (ram,0x0046d80d) */

void __fastcall FUN_0046d760(int param_1)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar4 = DAT_007361f8;
  fVar1 = *(float *)(param_1 + 0xcc);
  fVar2 = *(float *)(param_1 + 200);
  uVar3 = *(uint *)(DAT_007361f8 + 0x2d0);
  uVar6 = uVar3 ^ 0x1d872b41;
  uVar5 = uVar6 >> 5 ^ uVar6;
  *(uint *)(DAT_007361f8 + 0x2d0) = uVar5 << 0x1b ^ uVar5 ^ uVar6;
  *(float *)(param_1 + 0x78) =
       (float)(uVar3 % 0x7fffffff) * 4.656613e-10 * (fVar1 - fVar2) + *(float *)(param_1 + 200);
  uVar3 = *(uint *)(iVar4 + 0x2d0);
  fVar1 = *(float *)(param_1 + 0xd4);
  fVar2 = *(float *)(param_1 + 0xd0);
  uVar6 = uVar3 ^ 0x1d872b41;
  uVar5 = uVar6 >> 5 ^ uVar6;
  *(uint *)(iVar4 + 0x2d0) = uVar5 << 0x1b ^ uVar5 ^ uVar6;
  *(float *)(param_1 + 0x7c) =
       (float)(uVar3 % 0x7fffffff) * 4.656613e-10 * (fVar1 - fVar2) + *(float *)(param_1 + 0xd0);
  return;
}


// ==== 0x46d830 DriveTrain::GetDifferentialAngularVelocity

/* [canon] car med (ghidra-canon+nfsug) docs/re/car.md */

float10 __fastcall DriveTrain__GetDifferentialAngularVelocity(int param_1)

{
  float fVar1;
  float10 fVar2;
  undefined4 local_4;
  
  fVar2 = (float10)0.0;
  local_4 = 0;
  if (0.001 <= *(float *)(*(int *)(param_1 + 0x18) + 0x10)) {
    fVar2 = (float10)*(float *)(*(int *)(param_1 + 0x30) + 0x164) +
            (float10)*(float *)(*(int *)(param_1 + 0x2c) + 0x164);
    local_4 = 2;
  }
  fVar1 = *(float *)(*(int *)(param_1 + 0x18) + 0x10);
  if (fVar1 < 0.999 != (fVar1 == 0.999)) {
    local_4 = local_4 + 2;
    fVar2 = (float10)*(float *)(*(int *)(param_1 + 0x28) + 0x164) +
            (float10)*(float *)(*(int *)(param_1 + 0x24) + 0x164) + fVar2;
  }
  return fVar2 / (float10)local_4;
}


// ==== 0x46d8b0 FUN_0046d8b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046d8b0(float param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  float fVar4;
  int unaff_ESI;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  
  fVar5 = (float10)FUN_0046d680();
  fVar4 = *(float *)(*(int *)(unaff_ESI + 0x34) + 0x394) * 2.237;
  bVar3 = fVar4 < 40.0;
  iVar1 = *(int *)(unaff_ESI + 0x18);
  if (0.001 <= *(float *)(iVar1 + 0x10)) {
    iVar2 = *(int *)(unaff_ESI + 0x2c);
    if ((*(char *)(iVar2 + 0x155) == '\0') &&
       (*(char *)(*(int *)(unaff_ESI + 0x30) + 0x155) == '\0')) {
      bVar3 = true;
    }
    fVar6 = ((float10)param_1 - fVar5) /
            ((float10)*(float *)(iVar1 + 0x20 + *(int *)(unaff_ESI + 0x3c) * 4) *
            (float10)*(float *)(iVar1 + 0xc));
    fVar7 = (float10)*(float *)(*(int *)(unaff_ESI + 0x30) + 0x28);
    if (bVar3) {
      fVar8 = (fVar7 + (float10)*(float *)(iVar2 + 0x28)) * (float10)_K_HALF;
      fVar7 = fVar8;
    }
    else {
      fVar8 = (float10)*(float *)(iVar2 + 0x28);
    }
    *(float *)(iVar2 + 0x28) = (float)(fVar8 + fVar6);
    *(float *)(*(int *)(unaff_ESI + 0x30) + 0x28) = (float)(fVar7 + fVar6);
  }
  bVar3 = fVar4 < 40.0;
  iVar1 = *(int *)(unaff_ESI + 0x18);
  if (*(float *)(iVar1 + 0x10) < 0.999 != (*(float *)(iVar1 + 0x10) == 0.999)) {
    iVar2 = *(int *)(unaff_ESI + 0x24);
    if ((*(char *)(iVar2 + 0x155) == '\0') &&
       (*(char *)(*(int *)(unaff_ESI + 0x28) + 0x155) == '\0')) {
      bVar3 = true;
    }
    fVar7 = ((float10)param_1 - fVar5) /
            ((float10)*(float *)(iVar1 + 0x20 + *(int *)(unaff_ESI + 0x3c) * 4) *
            (float10)*(float *)(iVar1 + 8));
    fVar5 = (float10)*(float *)(*(int *)(unaff_ESI + 0x28) + 0x28);
    if (bVar3) {
      fVar5 = (fVar5 + (float10)*(float *)(iVar2 + 0x28)) * (float10)_K_HALF;
      *(float *)(iVar2 + 0x28) = (float)(fVar5 + fVar7);
      *(float *)(*(int *)(unaff_ESI + 0x28) + 0x28) = (float)(fVar5 + fVar7);
      return;
    }
    *(float *)(iVar2 + 0x28) = (float)((float10)*(float *)(iVar2 + 0x28) + fVar7);
    *(float *)(*(int *)(unaff_ESI + 0x28) + 0x28) = (float)(fVar5 + fVar7);
  }
  return;
}


// ==== 0x46d9f0 DriveTrain::GetDifferentialAngularAcceleration

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

float10 __fastcall DriveTrain__GetDifferentialAngularAcceleration(undefined4 param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  
  fVar5 = (float10)0.0;
  iVar2 = *(int *)(param_2 + 0x18);
  if (0.001 <= *(float *)(iVar2 + 0x10)) {
    iVar3 = *(int *)(param_2 + 0x30);
    iVar4 = *(int *)(param_2 + 0x2c);
    fVar5 = (((float10)*(float *)(iVar4 + 0x108) -
             (float10)*(float *)(*(int *)(iVar4 + 0x14) + 0x10) * (float10)*(float *)(iVar4 + 0x118)
             ) / (float10)*(float *)(iVar4 + 0x2c) +
            ((float10)*(float *)(iVar3 + 0x108) -
            (float10)*(float *)(*(int *)(iVar3 + 0x14) + 0x10) * (float10)*(float *)(iVar3 + 0x118))
            / (float10)*(float *)(iVar3 + 0x2c)) * (float10)_K_HALF *
            (float10)*(float *)(iVar2 + 0xc);
  }
  fVar1 = *(float *)(iVar2 + 0x10);
  if (!NAN(fVar1) && fVar1 < 0.999 != (fVar1 == 0.999)) {
    iVar3 = *(int *)(param_2 + 0x28);
    iVar4 = *(int *)(param_2 + 0x24);
    fVar5 = (((float10)*(float *)(iVar4 + 0x108) -
             (float10)*(float *)(*(int *)(iVar4 + 0x14) + 0x10) * (float10)*(float *)(iVar4 + 0x118)
             ) / (float10)*(float *)(iVar4 + 0x2c) +
            ((float10)*(float *)(iVar3 + 0x108) -
            (float10)*(float *)(*(int *)(iVar3 + 0x14) + 0x10) * (float10)*(float *)(iVar3 + 0x118))
            / (float10)*(float *)(iVar3 + 0x2c)) * (float10)_K_HALF * (float10)*(float *)(iVar2 + 8)
            + fVar5;
    if (0.001 <= *(float *)(iVar2 + 0x10)) {
      fVar5 = fVar5 * (float10)_K_HALF;
    }
  }
  return fVar5 * (float10)*(float *)(iVar2 + 0x20 + *(int *)(param_2 + 0x3c) * 4);
}


// ==== 0x46dac0 DriveTrain::SetManualClutchEngaged

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

void __thiscall DriveTrain__SetManualClutchEngaged(int param_1,float param_2)

{
  *(undefined4 *)(param_1 + 0x60) = 3;
  if (0.95 < param_2) {
    *(undefined4 *)(param_1 + 0x44) = 3;
    *(float *)(param_1 + 0x14) = _K_ONE;
    return;
  }
  if (param_2 < 0.05) {
    *(undefined4 *)(param_1 + 0x44) = 1;
    *(undefined4 *)(param_1 + 0x14) = 0;
    return;
  }
  if (param_2 == _K_ONE) {
    *(undefined4 *)(param_1 + 0x44) = 3;
    *(float *)(param_1 + 0x14) = param_2;
    return;
  }
  if (param_2 == 0.0) {
    *(undefined4 *)(param_1 + 0x44) = 1;
    *(float *)(param_1 + 0x14) = param_2;
    return;
  }
  if (*(float *)(param_1 + 0x14) < param_2) {
    *(undefined4 *)(param_1 + 0x44) = 2;
    *(float *)(param_1 + 0x14) = param_2;
    return;
  }
  *(float *)(param_1 + 0x14) = param_2;
  *(undefined4 *)(param_1 + 0x44) = 0;
  return;
}


// ==== 0x46db60 FUN_0046db60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0046db60(int param_1)

{
  undefined4 uVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  float10 fVar5;
  
  fVar5 = (float10)FUN_0046d680();
  *(float *)(param_1 + 0x4c) = (float)fVar5;
  if (*(int *)(param_1 + 0x60) == 3) {
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x80) = 0x3f800000;
    *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x60);
    if (*(int *)(param_1 + 0x44) == 3) {
      iVar4 = *(int *)(param_1 + 0x20);
      *(float *)(param_1 + 0x6c) = *(float *)(iVar4 + 0x14) * 9.549304;
      if ((0.0 < *(float *)(param_1 + 0x68)) && (*(float *)(param_1 + 100) == 0.0)) {
        *(float *)(param_1 + 100) = (float)DAT_0073ad34 * 0.00025;
      }
      if (*(int *)(param_1 + 0x3c) != 1) {
        fVar2 = *(float *)(param_1 + 0x4c) - *(float *)(iVar4 + 0x14);
        if ((*(float *)(iVar4 + 0x78) <= 0.2) ||
           (fVar5 = (float10)DriveTrain__GetDifferentialAngularVelocity(), fVar5 <= (float10)0.0)) {
          if ((0.0 < fVar2) || (DAT_006fff2c == 0)) {
            *(float *)(iVar4 + 0x14) = fVar2 * 0.04 + *(float *)(iVar4 + 0x14);
          }
        }
        else {
          uVar1 = *(undefined4 *)(iVar4 + 0x14);
          *(undefined4 *)(param_1 + 0x4c) = uVar1;
          FUN_0046d8b0(uVar1);
        }
      }
    }
    else if ((*(int *)(param_1 + 0x44) == 1) && (*(int *)(param_1 + 0x48) != 0)) {
      *(undefined4 *)(param_1 + 0x48) = 0;
      *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x38);
    }
  }
  else {
    switch(*(undefined4 *)(param_1 + 0x44)) {
    case 0:
      fVar2 = _K_ONE;
      if (*(char *)(param_1 + 0x74) == '\0') {
        fVar2 = 0.0;
      }
      *(float *)(*(int *)(param_1 + 0x20) + 0x80) = fVar2;
      if (*(float *)(param_1 + 0x14) < 0.0 != (*(float *)(param_1 + 0x14) == 0.0)) {
        *(undefined4 *)(param_1 + 0x14) = 0;
        *(undefined4 *)(param_1 + 0x44) = 1;
      }
      if (*(char *)(param_1 + 0x74) != '\0') {
        *(undefined4 *)(param_1 + 0x44) = 1;
      }
      break;
    case 1:
      fVar2 = _K_ONE;
      if (*(char *)(param_1 + 0x74) == '\0') {
        fVar2 = 0.0;
      }
      *(float *)(*(int *)(param_1 + 0x20) + 0x80) = fVar2;
      *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x38);
      if ((*(int *)(param_1 + 0x48) != 0) || (iVar4 = DriveTrain__Idling(), iVar4 == 0)) {
        *(undefined4 *)(param_1 + 0x48) = 0;
        if (*(char *)(param_1 + 0x74) == '\0') {
          *(undefined4 *)(param_1 + 0x44) = 2;
        }
        FUN_0046d760();
      }
      break;
    case 2:
      fVar2 = _K_ONE;
      if (*(char *)(param_1 + 0x74) == '\0') {
        fVar2 = 0.7;
      }
      *(float *)(*(int *)(param_1 + 0x20) + 0x80) = fVar2;
      if (_K_ONE <= *(float *)(param_1 + 0x14)) {
        *(undefined4 *)(param_1 + 0x14) = 0x3f800000;
        iVar4 = DriveTrain__ClutchMatched();
        if ((iVar4 != 0) || (*(int *)(param_1 + 0x3c) == 1)) {
          *(undefined4 *)(param_1 + 0x44) = 3;
        }
      }
      iVar4 = DriveTrain__Idling();
      if ((iVar4 != 0) && (*(int *)(param_1 + 0x3c) != 1)) {
        *(undefined4 *)(param_1 + 0x44) = 0;
      }
      if (*(char *)(param_1 + 0x74) != '\0') {
        *(undefined4 *)(param_1 + 0x44) = 1;
      }
      break;
    case 3:
      if ((0.0 < *(float *)(param_1 + 0x68)) && (*(float *)(param_1 + 100) == 0.0)) {
        *(float *)(param_1 + 100) = (float)DAT_0073ad34 * 0.00025;
      }
      cVar3 = RealDriver__IsDriftModeActive();
      if (cVar3 == '\0') {
        uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x60);
      }
      else {
        uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 100);
      }
      *(undefined4 *)(param_1 + 0xe4) = uVar1;
      *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x80) = 0x3f800000;
      if (*(int *)(param_1 + 0x3c) != 1) {
        iVar4 = *(int *)(param_1 + 0x20);
        fVar2 = *(float *)(param_1 + 0x4c) - *(float *)(iVar4 + 0x14);
        if ((*(float *)(iVar4 + 0x78) <= 0.2) ||
           (fVar5 = (float10)DriveTrain__GetDifferentialAngularVelocity(), fVar5 <= (float10)0.0)) {
          if ((0.0 < fVar2) || (DAT_006fff2c == 0)) {
            *(float *)(iVar4 + 0x14) = fVar2 * 0.04 + *(float *)(iVar4 + 0x14);
          }
        }
        else {
          uVar1 = *(undefined4 *)(iVar4 + 0x14);
          *(undefined4 *)(param_1 + 0x4c) = uVar1;
          FUN_0046d8b0(uVar1);
        }
        iVar4 = DriveTrain__Idling();
        if (iVar4 != 0) {
          *(undefined4 *)(param_1 + 0x44) = 0;
        }
      }
      if (*(int *)(param_1 + 0x3c) != *(int *)(param_1 + 0x38)) {
        *(undefined4 *)(param_1 + 0x48) = 1;
        fVar2 = *(float *)(*(int *)(param_1 + 0x20) + 0x14);
        *(undefined4 *)(param_1 + 0x44) = 0;
        *(float *)(param_1 + 0x6c) = fVar2 * 9.549304;
        if ((*(int *)(param_1 + 0x3c) == 1) && (*(int *)(param_1 + 0x38) == 2)) {
          *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x68);
        }
      }
      if (*(char *)(param_1 + 0x74) != '\0') {
        *(undefined4 *)(param_1 + 0x44) = 1;
      }
    }
  }
  if (*(float *)(param_1 + 0x5c) == 0.0) {
    if ((*(int *)(param_1 + 0x44) == 3) && (0.0 < *(float *)(param_1 + 100))) {
      fVar2 = ((0.5 - ((float)DAT_0073ad34 * 0.00025 - *(float *)(param_1 + 100))) / 0.5) *
              *(float *)(param_1 + 0x68) * 2.0;
      if (0.0 < fVar2) {
        *(float *)(*(int *)(param_1 + 0x20) + 0x80) = fVar2 + _K_ONE;
      }
      if (0.5 <= (float)DAT_0073ad34 * 0.00025 - *(float *)(param_1 + 100)) {
        *(undefined4 *)(param_1 + 100) = 0;
        *(undefined4 *)(param_1 + 0x68) = 0;
      }
    }
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x80) = 0;
    if (0.45 <= (float)DAT_0073ad34 * 0.00025 - *(float *)(param_1 + 0x5c)) {
      *(undefined4 *)(param_1 + 0x5c) = 0;
      return;
    }
  }
  return;
}


// ==== 0x46dfa0 DriveTrain::GetDerivative

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

undefined4 __thiscall DriveTrain__GetDerivative(int param_1,float *param_2)

{
  float fVar1;
  
  if (*(int *)(param_1 + 0x60) != 3) {
    fVar1 = *(float *)(*(int *)(param_1 + 0x18) + 0x1c) * *(float *)(param_1 + 0xdc);
    if (*(float *)(param_1 + 0x68) <= 0.0) {
      if ((*(float *)(param_1 + 0x68) < 0.0) && (2 < *(int *)(param_1 + 0x38))) {
        fVar1 = fVar1 * 0.35;
      }
    }
    else {
      fVar1 = (*(float *)(param_1 + 0x68) + _K_ONE) * fVar1;
    }
    *param_2 = fVar1 * (float)(&DAT_00700034)[*(int *)(param_1 + 0x44)];
    return 0;
  }
  *param_2 = 0.0;
  return 0;
}


// ==== 0x46e020 DriveTrain::ApplyClutchTorque

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

void __thiscall DriveTrain__ApplyClutchTorque(int param_1,float param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  if (*(int *)(param_1 + 0x3c) != 1) {
    *(float *)(param_1 + 0x70) = param_2 + *(float *)(param_1 + 0x70);
    *(float *)(*(int *)(param_1 + 0x20) + 0x7c) =
         *(float *)(*(int *)(param_1 + 0x20) + 0x7c) - param_2;
    iVar1 = *(int *)(param_1 + 0x18);
    param_2 = param_2 * *(float *)(iVar1 + 0x20 + *(int *)(param_1 + 0x3c) * 4);
    iVar2 = *(int *)(param_1 + 0x24);
    fVar3 = (_K_ONE - *(float *)(iVar1 + 0x10)) * *(float *)(iVar1 + 8) * param_2;
    fVar4 = param_2 * *(float *)(iVar1 + 0xc) * *(float *)(iVar1 + 0x10);
    if ((*(char *)(iVar2 + 0x155) == '\0') || (*(char *)(*(int *)(param_1 + 0x28) + 0x155) == '\0'))
    {
      param_2 = 0.5;
    }
    else {
      param_2 = DAT_00700044;
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0x34) + 0x3c8);
    if (iVar1 == 1) {
      fVar5 = _K_ONE - param_2;
    }
    else {
      fVar5 = param_2;
      if (iVar1 != 2) {
        fVar6 = *(float *)(iVar2 + 0x28) + *(float *)(*(int *)(param_1 + 0x28) + 0x28);
        fVar5 = _K_HALF;
        if (_K_EPS_SPEED < ABS(fVar6)) {
          fVar5 = *(float *)(*(int *)(param_1 + 0x28) + 0x28) / fVar6;
          if (param_2 <= fVar5) {
            if (_K_ONE - param_2 < fVar5) {
              fVar5 = DAT_00700044 * _K_HALF;
            }
          }
          else {
            fVar5 = _K_ONE - DAT_00700044 * _K_HALF;
          }
        }
      }
    }
    if (*(int *)(iVar2 + 0x10c) == 0) {
      *(float *)(iVar2 + 0x108) = (_K_ONE - fVar5) * fVar3 + *(float *)(iVar2 + 0x108);
    }
    iVar1 = *(int *)(param_1 + 0x28);
    if (*(int *)(iVar1 + 0x10c) == 0) {
      *(float *)(iVar1 + 0x108) = fVar5 * fVar3 + *(float *)(iVar1 + 0x108);
    }
    iVar1 = *(int *)(param_1 + 0x2c);
    if ((*(char *)(iVar1 + 0x155) == '\0') || (*(char *)(*(int *)(param_1 + 0x30) + 0x155) == '\0'))
    {
      param_2 = 0.5;
    }
    else {
      param_2 = DAT_00700044;
    }
    iVar2 = *(int *)(*(int *)(param_1 + 0x34) + 0x3c8);
    if (iVar2 == 1) {
      fVar3 = _K_ONE - param_2;
    }
    else {
      fVar3 = param_2;
      if ((iVar2 != 2) &&
         (fVar5 = *(float *)(*(int *)(param_1 + 0x30) + 0x28) + *(float *)(iVar1 + 0x28),
         fVar3 = _K_HALF, _K_EPS_SPEED < ABS(fVar5))) {
        fVar3 = *(float *)(iVar1 + 0x28) / fVar5;
        if (param_2 <= fVar3) {
          if (_K_ONE - param_2 < fVar3) {
            fVar3 = DAT_00700044 * _K_HALF;
          }
        }
        else {
          fVar3 = _K_ONE - DAT_00700044 * _K_HALF;
        }
      }
    }
    if (*(int *)(iVar1 + 0x10c) == 0) {
      *(float *)(iVar1 + 0x108) = fVar3 * fVar4 + *(float *)(iVar1 + 0x108);
    }
    iVar1 = *(int *)(param_1 + 0x30);
    if (*(int *)(iVar1 + 0x10c) == 0) {
      *(float *)(iVar1 + 0x108) = (_K_ONE - fVar3) * fVar4 + *(float *)(iVar1 + 0x108);
    }
  }
  return;
}


// ==== 0x46e270 FUN_0046e270

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046e270(void)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int unaff_ESI;
  float10 fVar5;
  
  iVar2 = *(int *)(unaff_ESI + 0x44);
  *(undefined4 *)(unaff_ESI + 0x70) = 0;
  if ((iVar2 == 0) || (iVar2 == 2)) {
    fVar1 = *(float *)(*(int *)(unaff_ESI + 0x20) + 0x14) - *(float *)(unaff_ESI + 0x4c);
    fVar4 = _DAT_006fff28;
    if ((fVar1 <= _DAT_006fff28) && (fVar4 = fVar1, fVar1 < -_DAT_006fff28)) {
      fVar4 = -_DAT_006fff28;
    }
    fVar1 = *(float *)(*(int *)(unaff_ESI + 0x18) + 0x14);
    fVar3 = (*(float *)(unaff_ESI + 0x4c) - *(float *)(*(int *)(unaff_ESI + 0x20) + 0x14)) *
            9.549304;
    if ((((*(float *)(unaff_ESI + 0x58) != 0.0) && (fVar3 * *(float *)(unaff_ESI + 0x58) < 0.0)) &&
        (2000.0 < ABS(fVar3))) && (2000.0 < ABS(*(float *)(unaff_ESI + 0x58)))) {
      fVar1 = fVar1 * 0.3;
    }
    *(float *)(unaff_ESI + 0x58) = fVar3;
    DriveTrain__ApplyClutchTorque(fVar1 * *(float *)(unaff_ESI + 0x14) * fVar4);
  }
  else if (iVar2 == 3) {
    fVar5 = (float10)FUN_0046cff0();
    DriveTrain__ApplyClutchTorque((float)fVar5);
    return;
  }
  return;
}


// ==== 0x46e360 FUN_0046e360

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046e360(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float fVar6;
  
  if (*(int *)(unaff_ESI + 0x44) == 3) {
    iVar1 = *(int *)(unaff_ESI + 0x20);
    fVar3 = (float10)FUN_0046cff0();
    fVar4 = (float10)*(float *)(*(int *)(iVar1 + 0x18) + 0xc);
    iVar2 = *(int *)(*(int *)(iVar1 + 0x20) + 0x44);
    if ((iVar2 == 2) || (iVar2 == 0)) {
      fVar4 = fVar4 * (float10)1.0;
    }
    fVar6 = (float)((fVar3 + (float10)*(float *)(iVar1 + 0x7c)) / fVar4);
    fVar3 = (float10)DriveTrain__GetDifferentialAngularAcceleration(fVar6);
    fVar4 = (float10)_K_ONE / (float10)*(float *)(*(int *)(*(int *)(unaff_ESI + 0x20) + 0x18) + 0xc)
    ;
    iVar1 = *(int *)(unaff_ESI + 0x18);
    if (*(float *)(iVar1 + 0x10) < 0.999 != (*(float *)(iVar1 + 0x10) == 0.999)) {
      fVar5 = (float10)*(float *)(iVar1 + 0x20 + *(int *)(unaff_ESI + 0x3c) * 4) *
              (float10)*(float *)(iVar1 + 8);
      fVar4 = (((float10)_K_ONE - (float10)*(float *)(iVar1 + 0x10)) /
              (float10)*(float *)(*(int *)(unaff_ESI + 0x24) + 0x2c)) * fVar5 * fVar5 *
              (float10)_K_HALF + fVar4;
    }
    if (0.001 <= *(float *)(iVar1 + 0x10)) {
      fVar5 = (float10)*(float *)(iVar1 + 0x20 + *(int *)(unaff_ESI + 0x3c) * 4) *
              (float10)*(float *)(iVar1 + 0xc);
      fVar4 = (fVar5 / (float10)*(float *)(*(int *)(unaff_ESI + 0x2c) + 0x2c)) * fVar5 *
              (float10)*(float *)(iVar1 + 0x10) * (float10)_K_HALF + fVar4;
    }
    DriveTrain__ApplyClutchTorque((float)(((float10)fVar6 - fVar3) / fVar4));
  }
  return;
}


// ==== 0x46e440 FUN_0046e440

void FUN_0046e440(void)

{
  float fVar1;
  int iVar2;
  int unaff_ESI;
  float10 fVar3;
  float local_4;
  
  if (DAT_006fff2c != 0) {
    if ((((*(int *)(unaff_ESI + 0x3c) != 1) && (*(int *)(unaff_ESI + 0x44) == 3)) &&
        ((local_4 = *(float *)(unaff_ESI + 0x4c) - *(float *)(*(int *)(unaff_ESI + 0x20) + 0x14),
         *(float *)(*(int *)(unaff_ESI + 0x20) + 0x78) <= 0.2 ||
         (fVar3 = (float10)DriveTrain__GetDifferentialAngularVelocity(), fVar3 <= (float10)0.0))))
       && (local_4 < 0.0)) {
      fVar3 = (float10)FUN_0046cff0();
      iVar2 = *(int *)(unaff_ESI + 0x20);
      fVar3 = (float10)bClampF(local_4 * *(float *)(*(int *)(unaff_ESI + 0x18) + 0x14),
                               -(float)ABS(fVar3 + fVar3),(float)ABS(fVar3 + fVar3));
      *(float *)(iVar2 + 0x7c) = (float)(fVar3 + (float10)*(float *)(iVar2 + 0x7c));
    }
    fVar3 = (float10)FUN_0046cff0();
    iVar2 = *(int *)(unaff_ESI + 0x20);
    fVar1 = (float)((float10)*(float *)(iVar2 + 0x7c) + fVar3);
    if (((float10)*(float *)(iVar2 + 0x7c) < fVar3) && (fVar1 < 0.0)) {
      Curve_Evaluate(&local_4,fVar1);
      *(float *)(iVar2 + 0x7c) =
           local_4 * *(float *)(unaff_ESI + 0xe4) * fVar1 + *(float *)(iVar2 + 0x7c);
    }
  }
  return;
}


// ==== 0x46e540 DriveTrain::Idling

/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

undefined4 __fastcall DriveTrain__Idling(undefined4 param_1,int param_2)

{
  if ((*(float *)(*(int *)(param_2 + 0x20) + 0x78) < 0.3) &&
     (*(float *)(param_2 + 0x4c) <=
      **(float **)(*(int *)(param_2 + 0x20) + 0x18) * 0.10471967 + 0.0001)) {
    return 1;
  }
  return 0;
}


// ==== 0x46e580 DriveTrain::ClutchMatched

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

undefined4 DriveTrain__ClutchMatched(void)

{
  float fVar1;
  int in_EAX;
  
  fVar1 = ABS(*(float *)(*(int *)(in_EAX + 0x20) + 0x14) - *(float *)(in_EAX + 0x4c));
  if (fVar1 < _DAT_00700070 != (fVar1 == _DAT_00700070)) {
    return 1;
  }
  return 0;
}


// ==== 0x46e5b0 FUN_0046e5b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0046e5b0(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  byte bVar7;
  float fVar8;
  float fVar9;
  int *piVar10;
  int iVar11;
  int unaff_ESI;
  float10 fVar12;
  float10 fVar13;
  float local_8;
  
  if (param_1 != -1) {
    if (param_1 == -2) {
      fVar1 = DAT_0073457c + *(float *)(unaff_ESI + 0x50);
      *(float *)(unaff_ESI + 0x50) = fVar1;
      if (*(int *)(unaff_ESI + 0x44) != 3) {
        return -2;
      }
      iVar2 = *(int *)(unaff_ESI + 0x20);
      fVar4 = **(float **)(iVar2 + 0x18);
      fVar5 = (*(float **)(iVar2 + 0x18))[2];
      fVar8 = *(float *)(iVar2 + 0x14) * 9.549304;
      iVar11 = *(int *)(unaff_ESI + 0x3c);
      if (iVar11 < 3) {
        if (0.2 <= *(float *)(iVar2 + 0x78)) {
          fVar9 = 0.0;
        }
        else {
          fVar9 = fVar4 + 100.0;
        }
      }
      else {
        fVar9 = (*(float *)(*(int *)(unaff_ESI + 0x18) + 0x20 + iVar11 * 4) /
                *(float *)(*(int *)(unaff_ESI + 0x18) + 0x1c + iVar11 * 4)) * _DAT_00700074 * fVar5;
      }
      iVar2 = *(int *)(unaff_ESI + 0x38);
      iVar3 = *(int *)(unaff_ESI + 0x54);
      if (iVar3 == iVar2) {
        if ((10.0 < fVar1) || ((*(int *)(unaff_ESI + 0x40) < iVar11 && (fVar5 - 300.0 < fVar8)))) {
          return -1;
        }
      }
      else {
        *(int *)(unaff_ESI + 0x40) = iVar11;
        if (iVar3 < iVar2) {
          *(undefined4 *)(unaff_ESI + 0x50) = 0;
          if (fVar9 < fVar8) {
            *(int *)(unaff_ESI + 0x54) = iVar11;
            *(int *)(unaff_ESI + 0x38) = iVar11;
            return -2;
          }
          *(int *)(unaff_ESI + 0x38) = iVar11 + -1;
          return -2;
        }
        if (iVar2 < iVar3) {
          *(int *)(unaff_ESI + 0x38) = iVar11 + 1;
          *(undefined4 *)(unaff_ESI + 0x50) = 0;
          return -2;
        }
      }
      if (fVar4 + 100.0 <= fVar8) {
        return -2;
      }
      if (iVar11 < 3) {
        return -2;
      }
      *(int *)(unaff_ESI + 0x38) = iVar11 + -1;
      return -1;
    }
    if (*(int *)(unaff_ESI + 0x60) == 3) {
      iVar2 = *(int *)(unaff_ESI + 0x3c);
      if (param_1 != iVar2) {
        if (*(int *)(unaff_ESI + 0x44) != 1) {
          *(undefined4 *)(unaff_ESI + 0x48) = 0;
          *(float *)(unaff_ESI + 0x5c) = (float)DAT_0073ad34 * 0.00025;
          return iVar2;
        }
        if (*(int *)(unaff_ESI + 0x48) != 0) {
          return param_1;
        }
        *(undefined4 *)(unaff_ESI + 0x48) = 1;
        *(int *)(unaff_ESI + 0x38) = param_1;
        if (param_1 <= iVar2) {
          return param_1;
        }
        if (iVar2 < 1) {
          return param_1;
        }
        FUN_0046e940(*(undefined4 *)(unaff_ESI + 0x6c));
        return param_1;
      }
    }
    iVar2 = *(int *)(unaff_ESI + 0x3c);
    if (param_1 == iVar2) {
      return param_1;
    }
    if (param_1 == *(int *)(unaff_ESI + 0x38)) {
      return param_1;
    }
    *(int *)(unaff_ESI + 0x38) = param_1;
    if (param_1 <= iVar2) {
      return param_1;
    }
    if (iVar2 < 1) {
      return param_1;
    }
    FUN_0046e940(*(float *)(*(int *)(unaff_ESI + 0x20) + 0x14) * 9.549304);
    return param_1;
  }
  iVar2 = *(int *)(unaff_ESI + 0x3c);
  iVar11 = *(int *)(unaff_ESI + 0x20);
  fVar1 = *(float *)(iVar11 + 0x14);
  *(undefined4 *)(unaff_ESI + 0x54) = 1;
  fVar1 = fVar1 * 9.549304;
  if (iVar2 < 2) {
    *(undefined4 *)(unaff_ESI + 0x38) = 2;
    goto LAB_0046e708;
  }
  if (*(int *)(unaff_ESI + 0x44) != 3) goto LAB_0046e708;
  fVar12 = (float10)FUN_0046d700(iVar2);
  local_8 = *(float *)(unaff_ESI + 0x7c) + *(float *)(unaff_ESI + 0xa4 + iVar2 * 4);
  fVar13 = (float10)0.0;
  if (iVar2 == 2) {
LAB_0046e64c:
    if (0.2 <= *(float *)(iVar11 + 0x78)) {
      local_8 = 0.0;
    }
    else {
      local_8 = **(float **)(iVar11 + 0x18) + 100.0;
    }
  }
  else {
    iVar3 = *(int *)(unaff_ESI + 0x18);
    fVar13 = (float10)FUN_0046d700(iVar2 + -1);
    fVar13 = ((float10)*(float *)(iVar3 + 0x20 + iVar2 * 4) /
             (float10)*(float *)(iVar3 + 0x1c + iVar2 * 4)) * fVar13 - (float10)200.0;
    if (iVar2 < 3) goto LAB_0046e64c;
  }
  if ((fVar1 < (float)fVar12) || (*(int *)(*(int *)(unaff_ESI + 0x18) + 0x18) + 1 <= iVar2)) {
    if ((fVar1 < local_8 != (fVar1 == local_8)) &&
       ((float10)fVar1 < fVar13 != ((float10)fVar1 == fVar13))) {
      *(int *)(unaff_ESI + 0x38) = iVar2 + -1;
    }
  }
  else {
    bVar6 = true;
    piVar10 = (int *)(unaff_ESI + 0x24);
    iVar11 = 4;
    do {
      if ((*(char *)(*piVar10 + 0x155) == '\0') || (4.0 <= *(float *)(*piVar10 + 0x160))) {
        bVar7 = 0;
      }
      else {
        bVar7 = 1;
      }
      bVar6 = (bool)(bVar6 & bVar7);
      piVar10 = piVar10 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    if (bVar6) {
      *(int *)(unaff_ESI + 0x38) = iVar2 + 1;
    }
  }
LAB_0046e708:
  if (((*(int *)(unaff_ESI + 0x44) == 3) && (iVar2 < *(int *)(unaff_ESI + 0x38))) && (0 < iVar2)) {
    FUN_0046e940(fVar1);
    return -1;
  }
  return -1;
}


// ==== 0x46e940 FUN_0046e940

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0046e940(int param_1,float param_2)

{
  int iVar1;
  float fVar2;
  
  if (((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) &&
     (iVar1 = *(int *)(param_1 + 0x3c), iVar1 <= *(int *)(param_1 + 0x38))) {
    *(undefined4 *)(param_1 + 0x68) = 0;
    param_2 = *(float *)(param_1 + 0x80 + iVar1 * 4) - param_2;
    fVar2 = *(float *)(&DAT_006fff60 +
                      (*(int *)(param_1 + 0xe0) + iVar1 + *(int *)(param_1 + 0xe0) * 8) * 4) *
            *(float *)(param_1 + 0xd8);
    if (param_2 < 0.0) {
      if ((_K_ONE - _DAT_006fff58) * fVar2 <= ABS(param_2)) {
        *(undefined4 *)(param_1 + 0x68) = 0xbf800000;
        return;
      }
      *(undefined4 *)(param_1 + 0x68) = 0x3f800000;
      return;
    }
    fVar2 = _K_ONE - param_2 / (_DAT_006fff58 * fVar2);
    if (fVar2 < 0.0) {
      fVar2 = 0.0;
    }
    *(float *)(param_1 + 0x68) = fVar2;
    if (0.0 < fVar2) {
      if (_K_HALF <= fVar2) {
        *(undefined4 *)(param_1 + 0x68) = 0x3f59999a;
        return;
      }
      *(undefined4 *)(param_1 + 0x68) = 0x3f000000;
      return;
    }
  }
  return;
}


// ==== 0x46ea30 DriveTrain::SetState

/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

void __thiscall DriveTrain__SetState(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x14) = *param_2;
  *(undefined4 *)(param_1 + 0x58) = 0;
  return;
}


// ==== 0x46ea50 SCEA_GJKsimplexPair::DistanceSqr

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra-canon+nfsug) docs/re/car.md */

float * __fastcall SCEA_GJKsimplexPair__DistanceSqr(undefined4 param_1,float *param_2)

{
  int iVar1;
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
  bool bVar22;
  int iVar23;
  int iVar24;
  float fVar25;
  float *pfVar26;
  float *pfVar27;
  float *pfVar28;
  float fVar29;
  float *pfVar30;
  float *extraout_EDX;
  int iVar31;
  int iVar32;
  int iVar33;
  float *unaff_ESI;
  int iVar34;
  float *pfVar35;
  int iVar36;
  float local_278;
  float local_274;
  float local_270;
  float local_26c;
  float local_268;
  int local_254;
  int local_250;
  float *local_24c;
  int local_248;
  float *local_244;
  int local_22c;
  int local_228;
  int local_224;
  float *local_218;
  int local_214;
  int local_1fc;
  int local_1f8;
  float local_1f4;
  float *local_1f0;
  float local_1e8;
  int local_19c [4];
  float *local_18c;
  int local_188 [4];
  float local_178;
  float local_174;
  float local_170;
  float local_16c;
  float local_168;
  float local_160;
  float local_15c;
  float local_158;
  float local_150;
  float local_14c;
  float local_148;
  float local_140;
  float local_13c;
  float local_138;
  float local_124;
  float local_120;
  float local_118;
  float local_110;
  float local_10c;
  float local_108;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f0;
  float local_e8;
  float local_d8;
  float local_d0;
  float local_c8;
  float local_b8;
  float local_b0;
  float local_a8;
  float local_98;
  float local_88;
  float local_78;
  float local_68;
  float local_58;
  float local_48;
  float local_38;
  float local_28;
  float local_18;
  
  fVar29 = unaff_ESI[0x30];
  fVar11 = unaff_ESI[0x35];
  bVar22 = false;
  local_1f4 = 3.4028235e+38;
  if (fVar29 == 1.4013e-45) {
    if (fVar11 == 1.4013e-45) {
      pfVar26 = (float *)*unaff_ESI;
      unaff_ESI[0x20] = (float)pfVar26;
      unaff_ESI[0x21] = unaff_ESI[1];
      unaff_ESI[0x22] = unaff_ESI[2];
      unaff_ESI[0x24] = unaff_ESI[0x10];
      unaff_ESI[0x25] = unaff_ESI[0x11];
      unaff_ESI[0x26] = unaff_ESI[0x12];
      fVar29 = unaff_ESI[0x25];
      fVar11 = unaff_ESI[0x21];
      fVar25 = unaff_ESI[0x26];
      fVar2 = unaff_ESI[0x22];
      *param_2 = unaff_ESI[0x24] - unaff_ESI[0x20];
      param_2[1] = fVar29 - fVar11;
      param_2[2] = fVar25 - fVar2;
      return pfVar26;
    }
    iVar23 = (int)fVar11 + -1;
    local_22c = 0;
    if (0 < iVar23) {
      local_218 = unaff_ESI + 0x12;
      do {
        fVar25 = local_218[-2] - *unaff_ESI;
        fVar2 = local_218[-1] - unaff_ESI[1];
        local_118 = *local_218 - unaff_ESI[2];
        iVar24 = local_22c + 1;
        pfVar26 = local_218;
        for (local_19c[1] = iVar24; local_19c[1] < (int)fVar11; local_19c[1] = local_19c[1] + 1) {
          local_24c = pfVar26 + 4;
          fVar12 = pfVar26[2] - local_218[-2];
          fVar13 = pfVar26[3] - local_218[-1];
          local_f8 = *local_24c - *local_218;
          local_274 = -(fVar13 * fVar2 + local_f8 * local_118 + fVar12 * fVar25) /
                      (fVar13 * fVar13 + local_f8 * local_f8 + fVar12 * fVar12);
          if (0.0 <= local_274) {
            if (local_274 <= _K_ONE) {
              fVar4 = fVar2 * local_f8 - fVar13 * local_118;
              fVar3 = fVar12 * local_118 - fVar25 * local_f8;
              fVar5 = fVar25 * fVar13 - fVar12 * fVar2;
              *param_2 = fVar5 * fVar13 - fVar3 * local_f8;
              param_2[1] = fVar4 * local_f8 - fVar12 * fVar5;
              param_2[2] = fVar12 * fVar3 - fVar4 * fVar13;
            }
            else {
              local_274 = 1.0;
              fVar3 = pfVar26[3];
              fVar4 = unaff_ESI[1];
              fVar5 = *local_24c;
              fVar6 = unaff_ESI[2];
              *param_2 = pfVar26[2] - *unaff_ESI;
              param_2[2] = fVar5 - fVar6;
              param_2[1] = fVar3 - fVar4;
            }
          }
          else {
            local_274 = 0.0;
            fVar3 = local_218[-1];
            fVar4 = unaff_ESI[1];
            fVar5 = *local_218;
            fVar6 = unaff_ESI[2];
            local_108 = fVar5 - fVar6;
            *param_2 = local_218[-2] - *unaff_ESI;
            param_2[2] = fVar5 - fVar6;
            param_2[1] = fVar3 - fVar4;
          }
          local_248 = 0;
          iVar34 = 1;
          fVar3 = unaff_ESI[0x12] * param_2[2] +
                  *param_2 * unaff_ESI[0x10] + unaff_ESI[0x11] * param_2[1];
          if (3 < iVar23) {
            iVar31 = 4;
            pfVar26 = unaff_ESI + 0x15;
            do {
              fVar4 = param_2[1] * *pfVar26 + pfVar26[1] * param_2[2] + pfVar26[-1] * *param_2;
              if (fVar4 < fVar3) {
                fVar3 = fVar4;
                local_248 = iVar34;
              }
              fVar4 = pfVar26[3] * *param_2 + pfVar26[5] * param_2[2] + pfVar26[4] * param_2[1];
              if (fVar4 < fVar3) {
                local_248 = iVar31 + -2;
                fVar3 = fVar4;
              }
              fVar4 = pfVar26[7] * *param_2 + pfVar26[9] * param_2[2] + pfVar26[8] * param_2[1];
              if (fVar4 < fVar3) {
                local_248 = iVar31 + -1;
                fVar3 = fVar4;
              }
              fVar4 = pfVar26[0xb] * *param_2 +
                      pfVar26[0xd] * param_2[2] + pfVar26[0xc] * param_2[1];
              if (fVar4 < fVar3) {
                fVar3 = fVar4;
                local_248 = iVar31;
              }
              iVar31 = iVar31 + 4;
              iVar34 = iVar34 + 4;
              pfVar26 = pfVar26 + 0x10;
            } while (iVar31 < (int)fVar11);
          }
          if (iVar34 < (int)fVar11) {
            pfVar26 = unaff_ESI + iVar34 * 4 + 0x11;
            do {
              fVar4 = param_2[1] * *pfVar26 + pfVar26[1] * param_2[2] + pfVar26[-1] * *param_2;
              if (fVar4 < fVar3) {
                fVar3 = fVar4;
                local_248 = iVar34;
              }
              iVar34 = iVar34 + 1;
              pfVar26 = pfVar26 + 4;
            } while (iVar34 < (int)fVar11);
          }
          if (param_2[1] * unaff_ESI[1] + param_2[2] * unaff_ESI[2] + *param_2 * *unaff_ESI < fVar3)
          {
            unaff_ESI[0x20] = *unaff_ESI;
            unaff_ESI[0x21] = unaff_ESI[1];
            unaff_ESI[0x22] = unaff_ESI[2];
            local_140 = fVar12 * local_274;
            local_13c = fVar13 * local_274;
            fVar3 = local_218[-1];
            fVar4 = *local_218;
            unaff_ESI[0x24] = fVar12 * local_274 + local_218[-2];
            unaff_ESI[0x26] = fVar4 + local_f8 * local_274;
            unaff_ESI[0x25] = fVar3 + fVar13 * local_274;
            fVar12 = (unaff_ESI[0x24] - unaff_ESI[0x20]) * (unaff_ESI[0x24] - unaff_ESI[0x20]) +
                     (unaff_ESI[0x25] - unaff_ESI[0x21]) * (unaff_ESI[0x25] - unaff_ESI[0x21]) +
                     (unaff_ESI[0x26] - unaff_ESI[0x22]) * (unaff_ESI[0x26] - unaff_ESI[0x22]);
            if ((local_248 == local_22c) || (local_248 == local_19c[1])) {
              if (local_274 != 0.0) {
                if (local_274 != _K_ONE) {
                  unaff_ESI[0x35] = 2.8026e-45;
                  unaff_ESI[0x31] = unaff_ESI[local_22c + 0x31];
                  unaff_ESI[0x32] = unaff_ESI[local_19c[1] + 0x31];
                  local_22c = local_22c + 4;
                  fVar29 = unaff_ESI[local_22c * 4 + 1];
                  fVar11 = unaff_ESI[local_22c * 4 + 2];
                  unaff_ESI[0x10] = unaff_ESI[local_22c * 4];
                  unaff_ESI[0x11] = fVar29;
                  unaff_ESI[0x12] = fVar11;
                  pfVar26 = unaff_ESI + (local_19c[1] + 4) * 4;
                  fVar29 = pfVar26[1];
                  fVar11 = pfVar26[2];
                  pfVar26 = (float *)*pfVar26;
                  unaff_ESI[0x14] = (float)pfVar26;
                  unaff_ESI[0x15] = fVar29;
                  unaff_ESI[0x16] = fVar11;
                  return pfVar26;
                }
                unaff_ESI[0x35] = 1.4013e-45;
                unaff_ESI[0x31] = unaff_ESI[local_19c[1] + 0x31];
                local_22c = local_19c[1];
LAB_00470a76:
                local_22c = local_22c + 4;
                fVar29 = unaff_ESI[local_22c * 4 + 1];
                fVar11 = unaff_ESI[local_22c * 4 + 2];
                unaff_ESI[0x10] = unaff_ESI[local_22c * 4];
                unaff_ESI[0x11] = fVar29;
                unaff_ESI[0x12] = fVar11;
                return unaff_ESI + local_22c * 4;
              }
              unaff_ESI[0x35] = 1.4013e-45;
              fVar29 = unaff_ESI[local_22c + 0x31];
              local_248 = local_22c;
LAB_0047135f:
              local_248 = local_248 + 4;
              unaff_ESI[0x31] = fVar29;
              fVar29 = unaff_ESI[local_248 * 4 + 1];
              fVar11 = unaff_ESI[local_248 * 4 + 2];
              unaff_ESI[0x10] = unaff_ESI[local_248 * 4];
              unaff_ESI[0x11] = fVar29;
              unaff_ESI[0x12] = fVar11;
              return unaff_ESI + local_248 * 4;
            }
            if (fVar12 < local_1f4) {
              local_16c = unaff_ESI[0x21];
              local_160 = *param_2;
              local_168 = unaff_ESI[0x22];
              local_15c = param_2[1];
              local_14c = unaff_ESI[0x25];
              local_158 = param_2[2];
              local_148 = unaff_ESI[0x26];
              local_170 = unaff_ESI[0x20];
              local_150 = unaff_ESI[0x24];
              bVar22 = true;
              local_178 = 1.4013e-45;
              local_188[0] = 0;
              local_1f4 = fVar12;
              if (local_274 == 0.0) {
                local_18c = (float *)0x1;
                local_19c[0] = local_22c;
              }
              else if (local_274 == _K_ONE) {
                local_18c = (float *)0x1;
                local_19c[0] = local_19c[1];
              }
              else {
                local_18c = (float *)0x2;
                local_19c[0] = local_22c;
              }
            }
          }
          pfVar26 = local_24c;
        }
        local_218 = local_218 + 4;
        local_22c = iVar24;
      } while (iVar24 < iVar23);
    }
  }
  else if (fVar11 == 1.4013e-45) {
    iVar23 = (int)fVar29 + -1;
    local_214 = 0;
    if (0 < iVar23) {
      pfVar26 = unaff_ESI + 1;
      do {
        iVar24 = local_214 + 1;
        fVar25 = unaff_ESI[0x10] - pfVar26[-1];
        fVar2 = unaff_ESI[0x11] - *pfVar26;
        local_118 = unaff_ESI[0x12] - pfVar26[1];
        if (iVar24 < (int)fVar29) {
          pfVar35 = pfVar26 + 5;
          local_228 = iVar24;
          do {
            fVar12 = pfVar35[-2] - pfVar26[-1];
            fVar13 = pfVar35[-1] - *pfVar26;
            local_f8 = *pfVar35 - pfVar26[1];
            local_278 = (fVar13 * fVar2 + local_f8 * local_118 + fVar25 * fVar12) /
                        (fVar12 * fVar12 + fVar13 * fVar13 + local_f8 * local_f8);
            if (0.0 <= local_278) {
              if (local_278 <= _K_ONE) {
                fVar4 = fVar2 * local_f8 - fVar13 * local_118;
                fVar3 = local_118 * fVar12 - fVar25 * local_f8;
                fVar5 = fVar25 * fVar13 - fVar2 * fVar12;
                *param_2 = fVar5 * fVar13 - fVar3 * local_f8;
                param_2[1] = fVar4 * local_f8 - fVar5 * fVar12;
                param_2[2] = fVar3 * fVar12 - fVar4 * fVar13;
              }
              else {
                local_278 = 1.0;
                fVar3 = unaff_ESI[0x11];
                fVar4 = pfVar35[-1];
                fVar5 = unaff_ESI[0x12];
                fVar6 = *pfVar35;
                *param_2 = unaff_ESI[0x10] - pfVar35[-2];
                param_2[2] = fVar5 - fVar6;
                param_2[1] = fVar3 - fVar4;
              }
            }
            else {
              local_278 = 0.0;
              fVar3 = unaff_ESI[0x11];
              fVar4 = *pfVar26;
              fVar5 = unaff_ESI[0x12];
              fVar6 = pfVar26[1];
              local_108 = fVar5 - fVar6;
              *param_2 = unaff_ESI[0x10] - pfVar26[-1];
              param_2[2] = fVar5 - fVar6;
              param_2[1] = fVar3 - fVar4;
            }
            local_250 = 0;
            iVar34 = 1;
            fVar3 = param_2[1] * unaff_ESI[1] + param_2[2] * unaff_ESI[2] + *param_2 * *unaff_ESI;
            if (3 < iVar23) {
              iVar31 = 4;
              pfVar28 = unaff_ESI + 9;
              do {
                fVar4 = pfVar28[-4] * param_2[1] + pfVar28[-3] * param_2[2] + pfVar28[-5] * *param_2
                ;
                if (fVar3 < fVar4) {
                  fVar3 = fVar4;
                  local_250 = iVar34;
                }
                fVar4 = *pfVar28 * param_2[1] + pfVar28[1] * param_2[2] + pfVar28[-1] * *param_2;
                if (fVar3 < fVar4) {
                  local_250 = iVar31 + -2;
                  fVar3 = fVar4;
                }
                fVar4 = pfVar28[4] * param_2[1] + pfVar28[3] * *param_2 + pfVar28[5] * param_2[2];
                if (fVar3 < fVar4) {
                  local_250 = iVar31 + -1;
                  fVar3 = fVar4;
                }
                fVar4 = pfVar28[8] * param_2[1] + pfVar28[7] * *param_2 + pfVar28[9] * param_2[2];
                if (fVar3 < fVar4) {
                  fVar3 = fVar4;
                  local_250 = iVar31;
                }
                iVar31 = iVar31 + 4;
                iVar34 = iVar34 + 4;
                pfVar28 = pfVar28 + 0x10;
              } while (iVar31 < (int)fVar29);
            }
            if (iVar34 < (int)fVar29) {
              pfVar28 = unaff_ESI + iVar34 * 4 + 1;
              do {
                fVar4 = param_2[1] * *pfVar28 + pfVar28[1] * param_2[2] + pfVar28[-1] * *param_2;
                if (fVar3 < fVar4) {
                  fVar3 = fVar4;
                  local_250 = iVar34;
                }
                iVar34 = iVar34 + 1;
                pfVar28 = pfVar28 + 4;
              } while (iVar34 < (int)fVar29);
            }
            if (fVar3 < unaff_ESI[0x10] * *param_2 +
                        unaff_ESI[0x11] * param_2[1] + unaff_ESI[0x12] * param_2[2]) {
              local_140 = local_278 * fVar12;
              local_13c = local_278 * fVar13;
              fVar3 = *pfVar26;
              fVar4 = pfVar26[1];
              unaff_ESI[0x20] = local_278 * fVar12 + pfVar26[-1];
              unaff_ESI[0x22] = fVar4 + local_278 * local_f8;
              unaff_ESI[0x21] = fVar3 + local_278 * fVar13;
              unaff_ESI[0x24] = unaff_ESI[0x10];
              unaff_ESI[0x25] = unaff_ESI[0x11];
              unaff_ESI[0x26] = unaff_ESI[0x12];
              fVar12 = (unaff_ESI[0x24] - unaff_ESI[0x20]) * (unaff_ESI[0x24] - unaff_ESI[0x20]) +
                       (unaff_ESI[0x25] - unaff_ESI[0x21]) * (unaff_ESI[0x25] - unaff_ESI[0x21]) +
                       (unaff_ESI[0x26] - unaff_ESI[0x22]) * (unaff_ESI[0x26] - unaff_ESI[0x22]);
              if ((local_250 == local_214) || (local_250 == local_228)) {
                if (local_278 == 0.0) {
                  unaff_ESI[0x30] = 1.4013e-45;
                  pfVar26 = unaff_ESI + local_214 * 4;
                  unaff_ESI[0x2c] = unaff_ESI[local_214 + 0x2c];
                  fVar29 = pfVar26[1];
                  fVar11 = pfVar26[2];
                  *unaff_ESI = *pfVar26;
                  unaff_ESI[1] = fVar29;
                  unaff_ESI[2] = fVar11;
                  return (float *)CONCAT22((short)((uint)local_250 >> 0x10),
                                           (ushort)(local_278 < 0.0) << 8 |
                                           (ushort)NAN(local_278) << 10 |
                                           (ushort)(local_278 == 0.0) << 0xe);
                }
                if (local_278 != _K_ONE) {
                  unaff_ESI[0x30] = 2.8026e-45;
                  unaff_ESI[0x2c] = unaff_ESI[local_214 + 0x2c];
                  fVar29 = unaff_ESI[local_214 * 4 + 1];
                  fVar11 = unaff_ESI[local_214 * 4 + 2];
                  *unaff_ESI = unaff_ESI[local_214 * 4];
                  unaff_ESI[1] = fVar29;
                  unaff_ESI[2] = fVar11;
                  unaff_ESI[0x2d] = unaff_ESI[local_228 + 0x2c];
                  fVar29 = unaff_ESI[local_228 * 4 + 1];
                  pfVar26 = (float *)unaff_ESI[local_228 * 4];
                  fVar11 = unaff_ESI[local_228 * 4 + 2];
                  unaff_ESI[4] = (float)pfVar26;
                  unaff_ESI[5] = fVar29;
                  unaff_ESI[6] = fVar11;
                  return pfVar26;
                }
                unaff_ESI[0x30] = 1.4013e-45;
                pfVar26 = (float *)unaff_ESI[local_228 + 0x2c];
                pfVar35 = unaff_ESI + local_228 * 4;
                unaff_ESI[0x2c] = (float)pfVar26;
                fVar29 = pfVar35[1];
                fVar11 = pfVar35[2];
                *unaff_ESI = *pfVar35;
                unaff_ESI[1] = fVar29;
                unaff_ESI[2] = fVar11;
                return pfVar26;
              }
              if (fVar12 < local_1f4) {
                local_16c = unaff_ESI[0x21];
                local_160 = *param_2;
                local_168 = unaff_ESI[0x22];
                local_15c = param_2[1];
                local_14c = unaff_ESI[0x25];
                local_158 = param_2[2];
                local_148 = unaff_ESI[0x26];
                local_170 = unaff_ESI[0x20];
                local_150 = unaff_ESI[0x24];
                bVar22 = true;
                if (local_278 == 0.0) {
                  local_178 = 1.4013e-45;
LAB_0046f871:
                  local_188[0] = local_214;
                }
                else {
                  if (local_278 != _K_ONE) {
                    local_178 = 2.8026e-45;
                    local_188[1] = local_228;
                    goto LAB_0046f871;
                  }
                  local_178 = 1.4013e-45;
                  local_188[0] = local_228;
                }
                local_18c = (float *)0x1;
                local_19c[0] = 0;
                local_1f4 = fVar12;
              }
            }
            local_228 = local_228 + 1;
            pfVar35 = pfVar35 + 4;
          } while (local_228 < (int)fVar29);
        }
        pfVar26 = pfVar26 + 4;
        local_214 = iVar24;
      } while (iVar24 < iVar23);
    }
  }
  else {
    iVar23 = (int)fVar29 + -1;
    local_214 = 0;
    if (0 < iVar23) {
      do {
        iVar24 = local_214 + 1;
        if (iVar24 < (int)fVar29) {
          pfVar26 = unaff_ESI + local_214 * 4;
          iVar31 = (int)fVar11 + -1;
          iVar34 = iVar24;
          do {
            pfVar35 = unaff_ESI + iVar34 * 4;
            fVar25 = unaff_ESI[iVar34 * 4] - *pfVar26;
            fVar2 = pfVar35[1] - pfVar26[1];
            fVar12 = pfVar35[2] - pfVar26[2];
            local_18 = fVar12;
            local_22c = 0;
            local_174 = fVar25 * fVar25 + fVar2 * fVar2 + fVar12 * fVar12;
            if (0 < iVar31) {
              do {
                pfVar28 = unaff_ESI + (local_22c + 4) * 4;
                fVar13 = unaff_ESI[(local_22c + 4) * 4] - *pfVar26;
                fVar3 = pfVar28[1] - pfVar26[1];
                fVar4 = pfVar28[2] - pfVar26[2];
                local_28 = fVar4;
                iVar1 = local_22c + 1;
                local_124 = fVar2 * fVar3 + fVar12 * fVar4 + fVar13 * fVar25;
                for (iVar33 = iVar1; iVar33 < (int)fVar11; iVar33 = iVar33 + 1) {
                  pfVar27 = unaff_ESI + (iVar33 + 4) * 4;
                  fVar5 = unaff_ESI[(iVar33 + 4) * 4] - *pfVar28;
                  fVar6 = pfVar27[1] - pfVar28[1];
                  fVar14 = pfVar27[2] - pfVar28[2];
                  local_48 = fVar14;
                  fVar8 = fVar6 * fVar6 + fVar14 * fVar14 + fVar5 * fVar5;
                  fVar7 = fVar2 * fVar6 + fVar12 * fVar14 + fVar5 * fVar25;
                  fVar9 = fVar6 * fVar3 + fVar14 * fVar4 + fVar5 * fVar13;
                  local_278 = local_174 * fVar8 - fVar7 * fVar7;
                  if (ABS(local_278) <= _K_EPS_SPEED) {
                    local_278 = 0.0;
                  }
                  else {
                    local_278 = (local_124 * fVar8 - fVar7 * fVar9) / local_278;
                    if (0.0 <= local_278) {
                      if (_K_ONE < local_278) {
                        local_278 = 1.0;
                      }
                    }
                    else {
                      local_278 = 0.0;
                    }
                  }
                  fVar8 = (fVar7 * local_278 - fVar9) / fVar8;
                  if ((fVar8 <= 0.0) || (_K_ONE <= fVar8)) {
                    local_274 = 0.0;
                    if (fVar8 < 0.0 == (fVar8 == 0.0)) {
                      local_274 = 1.0;
                    }
                    fVar7 = (fVar7 * local_274 + local_124) / local_174;
                    if ((fVar7 <= 0.0) || (_K_ONE <= fVar7)) {
                      local_278 = 0.0;
                      if (fVar7 < 0.0 == (fVar7 == 0.0)) {
                        local_278 = 1.0;
                      }
                      fVar7 = pfVar26[1];
                      fVar8 = pfVar26[2];
                      fVar9 = pfVar28[1];
                      fVar10 = pfVar28[2];
                      *param_2 = (fVar5 * local_274 + *pfVar28) - (local_278 * fVar25 + *pfVar26);
                      param_2[1] = (fVar6 * local_274 + fVar9) - (local_278 * fVar2 + fVar7);
                      param_2[2] = (fVar14 * local_274 + fVar10) - (local_278 * fVar12 + fVar8);
                    }
                    else {
                      fVar8 = (fVar5 * local_274 + *pfVar28) - *pfVar26;
                      fVar9 = (fVar6 * local_274 + pfVar28[1]) - pfVar26[1];
                      fVar15 = (fVar14 * local_274 + pfVar28[2]) - pfVar26[2];
                      fVar10 = fVar9 * fVar12 - fVar15 * fVar2;
                      fVar15 = fVar15 * fVar25 - fVar8 * fVar12;
                      fVar8 = fVar8 * fVar2 - fVar9 * fVar25;
                      *param_2 = fVar2 * fVar8 - fVar12 * fVar15;
                      param_2[1] = fVar12 * fVar10 - fVar8 * fVar25;
                      param_2[2] = fVar15 * fVar25 - fVar2 * fVar10;
                      local_278 = fVar7;
                    }
                  }
                  else {
                    local_274 = fVar8;
                    if ((local_278 <= 0.0) || (_K_ONE <= local_278)) {
                      local_88 = local_278 * fVar12;
                      local_f0 = local_278 * fVar25;
                      local_140 = local_278 * fVar25 + *pfVar26;
                      local_13c = pfVar26[1] + local_278 * fVar2;
                      local_138 = pfVar26[2] + local_278 * fVar12;
                      fVar7 = *pfVar28 - local_140;
                      fVar8 = pfVar28[1] - local_13c;
                      local_d8 = pfVar28[2] - local_138;
                      fVar9 = fVar8 * fVar14 - local_d8 * fVar6;
                      fVar10 = fVar5 * local_d8 - fVar7 * fVar14;
                      fVar7 = fVar7 * fVar6 - fVar5 * fVar8;
                      *param_2 = fVar7 * fVar6 - fVar10 * fVar14;
                      param_2[1] = fVar9 * fVar14 - fVar7 * fVar5;
                      param_2[2] = fVar10 * fVar5 - fVar9 * fVar6;
                    }
                    else {
                      *param_2 = fVar2 * fVar14 - fVar12 * fVar6;
                      param_2[1] = fVar5 * fVar12 - fVar14 * fVar25;
                      param_2[2] = fVar6 * fVar25 - fVar5 * fVar2;
                      bNormalize3();
                      if (fVar13 * *extraout_EDX + fVar4 * extraout_EDX[2] + fVar3 * extraout_EDX[1]
                          < 0.0) {
                        local_c8 = -extraout_EDX[2];
                        extraout_EDX[2] = -extraout_EDX[2];
                        *extraout_EDX = -*extraout_EDX;
                        extraout_EDX[1] = -extraout_EDX[1];
                      }
                      local_68 = local_278 * fVar12;
                      local_b0 = local_278 * fVar25;
                      fVar7 = *pfVar28 - (local_278 * fVar25 + *pfVar26);
                      fVar9 = pfVar28[1] - (pfVar26[1] + local_278 * fVar2);
                      local_38 = pfVar28[2] - (pfVar26[2] + local_278 * fVar12);
                      fVar15 = fVar9 * fVar14 - local_38 * fVar6;
                      fVar10 = local_38 * fVar5 - fVar7 * fVar14;
                      fVar7 = fVar7 * fVar6 - fVar5 * fVar9;
                      fVar16 = fVar15 * fVar14 - fVar5 * fVar7;
                      fVar9 = fVar5 * fVar10 - fVar15 * fVar6;
                      fVar7 = fVar7 * fVar6 - fVar10 * fVar14;
                      fVar10 = (fVar5 * fVar8 + *pfVar28) - *pfVar26;
                      fVar15 = (fVar6 * fVar8 + pfVar28[1]) - pfVar26[1];
                      fVar8 = (fVar14 * fVar8 + pfVar28[2]) - pfVar26[2];
                      local_120 = fVar15 * fVar12 - fVar8 * fVar2;
                      fVar18 = fVar8 * fVar25 - fVar10 * fVar12;
                      fVar8 = fVar10 * fVar2 - fVar15 * fVar25;
                      fVar21 = local_120 * fVar12 - fVar8 * fVar25;
                      fVar20 = fVar18 * fVar25 - local_120 * fVar2;
                      fVar8 = fVar8 * fVar2 - fVar18 * fVar12;
                      fVar10 = *pfVar35 * *extraout_EDX +
                               pfVar35[1] * extraout_EDX[1] + pfVar35[2] * extraout_EDX[2];
                      fVar15 = *pfVar26 * *extraout_EDX +
                               pfVar26[1] * extraout_EDX[1] + pfVar26[2] * extraout_EDX[2];
                      if (fVar15 < fVar10) {
                        fVar10 = fVar15;
                      }
                      fVar15 = *extraout_EDX * *pfVar27 +
                               pfVar27[1] * extraout_EDX[1] + pfVar27[2] * extraout_EDX[2];
                      fVar18 = *pfVar28 * *extraout_EDX +
                               pfVar28[1] * extraout_EDX[1] + pfVar28[2] * extraout_EDX[2];
                      if (fVar18 < fVar15) {
                        fVar15 = fVar18;
                      }
                      fVar18 = fVar7 * *pfVar35 + fVar16 * pfVar35[1] + fVar9 * pfVar35[2];
                      fVar19 = fVar7 * *pfVar26 + fVar16 * pfVar26[1] + fVar9 * pfVar26[2];
                      if (fVar19 < fVar18) {
                        fVar18 = fVar19;
                      }
                      fVar19 = fVar7 * *pfVar27 + fVar16 * pfVar27[1] + fVar9 * pfVar27[2];
                      fVar17 = fVar7 * *pfVar28 + fVar16 * pfVar28[1] + fVar9 * pfVar28[2];
                      if (fVar17 < fVar19) {
                        fVar19 = fVar17;
                      }
                      fVar17 = fVar15 - fVar10;
                      if (fVar15 - fVar10 < fVar19 - fVar18) {
                        *extraout_EDX = fVar7;
                        extraout_EDX[1] = fVar16;
                        extraout_EDX[2] = fVar9;
                        fVar17 = fVar19 - fVar18;
                      }
                      fVar7 = fVar8 * *pfVar35 + fVar21 * pfVar35[1] + fVar20 * pfVar35[2];
                      fVar9 = fVar8 * *pfVar26 + fVar21 * pfVar26[1] + fVar20 * pfVar26[2];
                      if (fVar9 < fVar7) {
                        fVar7 = fVar9;
                      }
                      fVar10 = fVar8 * *pfVar27 + fVar21 * pfVar27[1] + fVar20 * pfVar27[2];
                      fVar9 = fVar8 * *pfVar28 + fVar21 * pfVar28[1] + fVar20 * pfVar28[2];
                      if (fVar9 < fVar10) {
                        fVar10 = fVar9;
                      }
                      param_2 = extraout_EDX;
                      if (fVar17 < fVar10 - fVar7) {
                        *extraout_EDX = fVar8;
                        extraout_EDX[1] = fVar21;
                        extraout_EDX[2] = fVar20;
                      }
                    }
                  }
                  local_250 = 0;
                  iVar36 = 1;
                  fVar7 = param_2[1] * unaff_ESI[1] +
                          param_2[2] * unaff_ESI[2] + *param_2 * *unaff_ESI;
                  if (3 < iVar23) {
                    iVar32 = 4;
                    pfVar27 = unaff_ESI + 9;
                    do {
                      fVar8 = pfVar27[-4] * param_2[1] +
                              pfVar27[-3] * param_2[2] + pfVar27[-5] * *param_2;
                      if (fVar7 < fVar8) {
                        fVar7 = fVar8;
                        local_250 = iVar36;
                      }
                      fVar8 = param_2[1] * *pfVar27 +
                              pfVar27[1] * param_2[2] + pfVar27[-1] * *param_2;
                      if (fVar7 < fVar8) {
                        local_250 = iVar32 + -2;
                        fVar7 = fVar8;
                      }
                      fVar8 = pfVar27[4] * param_2[1] +
                              pfVar27[3] * *param_2 + pfVar27[5] * param_2[2];
                      if (fVar7 < fVar8) {
                        local_250 = iVar32 + -1;
                        fVar7 = fVar8;
                      }
                      fVar8 = pfVar27[8] * param_2[1] +
                              pfVar27[7] * *param_2 + pfVar27[9] * param_2[2];
                      if (fVar7 < fVar8) {
                        fVar7 = fVar8;
                        local_250 = iVar32;
                      }
                      iVar32 = iVar32 + 4;
                      iVar36 = iVar36 + 4;
                      pfVar27 = pfVar27 + 0x10;
                    } while (iVar32 < (int)fVar29);
                  }
                  if (iVar36 < (int)fVar29) {
                    pfVar27 = unaff_ESI + iVar36 * 4 + 1;
                    do {
                      fVar8 = param_2[1] * *pfVar27 +
                              pfVar27[1] * param_2[2] + pfVar27[-1] * *param_2;
                      if (fVar7 < fVar8) {
                        fVar7 = fVar8;
                        local_250 = iVar36;
                      }
                      iVar36 = iVar36 + 1;
                      pfVar27 = pfVar27 + 4;
                    } while (iVar36 < (int)fVar29);
                  }
                  local_248 = 0;
                  iVar36 = 1;
                  fVar8 = unaff_ESI[0x12] * param_2[2] +
                          unaff_ESI[0x10] * *param_2 + unaff_ESI[0x11] * param_2[1];
                  if (3 < iVar31) {
                    iVar32 = 4;
                    pfVar27 = unaff_ESI + 0x15;
                    do {
                      fVar9 = param_2[1] * *pfVar27 +
                              pfVar27[1] * param_2[2] + pfVar27[-1] * *param_2;
                      if (fVar9 < fVar8) {
                        fVar8 = fVar9;
                        local_248 = iVar36;
                      }
                      fVar9 = pfVar27[4] * param_2[1] +
                              pfVar27[3] * *param_2 + pfVar27[5] * param_2[2];
                      if (fVar9 < fVar8) {
                        local_248 = iVar32 + -2;
                        fVar8 = fVar9;
                      }
                      fVar9 = pfVar27[8] * param_2[1] +
                              pfVar27[7] * *param_2 + pfVar27[9] * param_2[2];
                      if (fVar9 < fVar8) {
                        local_248 = iVar32 + -1;
                        fVar8 = fVar9;
                      }
                      fVar9 = pfVar27[0xc] * param_2[1] +
                              pfVar27[0xb] * *param_2 + pfVar27[0xd] * param_2[2];
                      if (fVar9 < fVar8) {
                        fVar8 = fVar9;
                        local_248 = iVar32;
                      }
                      iVar32 = iVar32 + 4;
                      iVar36 = iVar36 + 4;
                      pfVar27 = pfVar27 + 0x10;
                    } while (iVar32 < (int)fVar11);
                  }
                  if (iVar36 < (int)fVar11) {
                    pfVar27 = unaff_ESI + iVar36 * 4 + 0x11;
                    do {
                      fVar9 = *pfVar27 * param_2[1] +
                              pfVar27[1] * param_2[2] + pfVar27[-1] * *param_2;
                      if (fVar9 < fVar8) {
                        fVar8 = fVar9;
                        local_248 = iVar36;
                      }
                      iVar36 = iVar36 + 1;
                      pfVar27 = pfVar27 + 4;
                    } while (iVar36 < (int)fVar11);
                  }
                  if (fVar7 < fVar8) {
                    local_b8 = local_278 * fVar12;
                    local_110 = local_278 * fVar25;
                    local_10c = local_278 * fVar2;
                    fVar7 = pfVar26[1];
                    local_98 = pfVar26[2] + local_278 * fVar12;
                    unaff_ESI[0x20] = local_278 * fVar25 + *pfVar26;
                    unaff_ESI[0x22] = local_98;
                    unaff_ESI[0x21] = fVar7 + local_278 * fVar2;
                    local_78 = fVar14 * local_274;
                    local_100 = fVar5 * local_274;
                    local_fc = fVar6 * local_274;
                    fVar7 = pfVar28[1];
                    local_58 = pfVar28[2] + fVar14 * local_274;
                    unaff_ESI[0x24] = fVar5 * local_274 + *pfVar28;
                    unaff_ESI[0x26] = local_58;
                    unaff_ESI[0x25] = fVar7 + fVar6 * local_274;
                    fVar5 = (unaff_ESI[0x24] - unaff_ESI[0x20]) *
                            (unaff_ESI[0x24] - unaff_ESI[0x20]) +
                            (unaff_ESI[0x25] - unaff_ESI[0x21]) *
                            (unaff_ESI[0x25] - unaff_ESI[0x21]) +
                            (unaff_ESI[0x26] - unaff_ESI[0x22]) *
                            (unaff_ESI[0x26] - unaff_ESI[0x22]);
                    if (((local_250 == local_214) || (local_250 == iVar34)) &&
                       ((local_248 == local_22c || (local_248 == iVar33)))) {
                      if (local_278 == 0.0) {
                        unaff_ESI[0x30] = 1.4013e-45;
                        unaff_ESI[0x2c] = unaff_ESI[local_214 + 0x2c];
                        fVar29 = unaff_ESI[local_214 * 4 + 1];
                        fVar11 = (unaff_ESI + local_214 * 4)[2];
                        *unaff_ESI = unaff_ESI[local_214 * 4];
                        unaff_ESI[1] = fVar29;
                        unaff_ESI[2] = fVar11;
                      }
                      else if (local_278 == _K_ONE) {
                        unaff_ESI[0x30] = 1.4013e-45;
                        unaff_ESI[0x2c] = unaff_ESI[iVar34 + 0x2c];
                        fVar29 = unaff_ESI[iVar34 * 4 + 1];
                        fVar11 = unaff_ESI[iVar34 * 4 + 2];
                        *unaff_ESI = unaff_ESI[iVar34 * 4];
                        unaff_ESI[1] = fVar29;
                        unaff_ESI[2] = fVar11;
                      }
                      else {
                        unaff_ESI[0x30] = 2.8026e-45;
                        unaff_ESI[0x2c] = unaff_ESI[local_214 + 0x2c];
                        fVar29 = unaff_ESI[local_214 * 4 + 1];
                        fVar11 = (unaff_ESI + local_214 * 4)[2];
                        *unaff_ESI = unaff_ESI[local_214 * 4];
                        unaff_ESI[1] = fVar29;
                        unaff_ESI[2] = fVar11;
                        unaff_ESI[0x2d] = unaff_ESI[iVar34 + 0x2c];
                        fVar29 = unaff_ESI[iVar34 * 4 + 1];
                        fVar11 = unaff_ESI[iVar34 * 4 + 2];
                        unaff_ESI[4] = unaff_ESI[iVar34 * 4];
                        unaff_ESI[5] = fVar29;
                        unaff_ESI[6] = fVar11;
                      }
                      if (local_274 != 0.0) {
                        if (local_274 != _K_ONE) {
                          unaff_ESI[0x35] = 2.8026e-45;
                          unaff_ESI[0x31] = unaff_ESI[local_22c + 0x31];
                          unaff_ESI[0x32] = unaff_ESI[iVar33 + 0x31];
                          local_22c = local_22c + 4;
                          fVar29 = unaff_ESI[local_22c * 4 + 1];
                          fVar11 = unaff_ESI[local_22c * 4 + 2];
                          unaff_ESI[0x10] = unaff_ESI[local_22c * 4];
                          unaff_ESI[0x11] = fVar29;
                          iVar33 = iVar33 + 4;
                          unaff_ESI[0x12] = fVar11;
                          fVar29 = unaff_ESI[iVar33 * 4 + 1];
                          fVar11 = unaff_ESI[iVar33 * 4 + 2];
                          unaff_ESI[0x14] = unaff_ESI[iVar33 * 4];
                          unaff_ESI[0x15] = fVar29;
                          unaff_ESI[0x16] = fVar11;
                          return unaff_ESI + local_22c * 4;
                        }
                        unaff_ESI[0x35] = 1.4013e-45;
                        unaff_ESI[0x31] = unaff_ESI[iVar33 + 0x31];
                        fVar29 = unaff_ESI[(iVar33 + 4) * 4 + 1];
                        fVar11 = (unaff_ESI + (iVar33 + 4) * 4)[2];
                        pfVar26 = (float *)unaff_ESI[(iVar33 + 4) * 4];
                        unaff_ESI[0x10] = (float)pfVar26;
                        unaff_ESI[0x11] = fVar29;
                        unaff_ESI[0x12] = fVar11;
                        return pfVar26;
                      }
                      unaff_ESI[0x35] = 1.4013e-45;
                      unaff_ESI[0x31] = unaff_ESI[local_22c + 0x31];
                      goto LAB_00470a76;
                    }
                    if (fVar5 < local_1f4) {
                      local_16c = unaff_ESI[0x21];
                      local_160 = *param_2;
                      local_168 = unaff_ESI[0x22];
                      local_15c = param_2[1];
                      local_14c = unaff_ESI[0x25];
                      local_158 = param_2[2];
                      local_148 = unaff_ESI[0x26];
                      local_170 = unaff_ESI[0x20];
                      local_150 = unaff_ESI[0x24];
                      bVar22 = true;
                      if (local_278 == 0.0) {
                        local_178 = 1.4013e-45;
LAB_004708d0:
                        local_188[0] = local_214;
                      }
                      else {
                        if (local_278 != _K_ONE) {
                          local_178 = 2.8026e-45;
                          local_188[1] = iVar34;
                          goto LAB_004708d0;
                        }
                        local_178 = 1.4013e-45;
                        local_188[0] = iVar34;
                      }
                      local_1f4 = fVar5;
                      if (local_274 == 0.0) {
                        local_18c = (float *)0x1;
                        local_19c[0] = local_22c;
                      }
                      else if (local_274 == _K_ONE) {
                        local_18c = (float *)0x1;
                        local_19c[0] = iVar33;
                      }
                      else {
                        local_18c = (float *)0x2;
                        local_19c[0] = local_22c;
                        local_19c[1] = iVar33;
                      }
                    }
                  }
                }
                local_22c = iVar1;
              } while (iVar1 < iVar31);
            }
            iVar34 = iVar34 + 1;
          } while (iVar34 < (int)fVar29);
        }
        local_214 = iVar24;
      } while (iVar24 < iVar23);
    }
  }
  local_174 = (float)((int)fVar29 + -2);
  local_214 = 0;
  if (0 < (int)local_174) {
    local_254 = 5;
    pfVar26 = unaff_ESI;
    do {
      iVar23 = local_214 + 1;
      if (iVar23 < (int)fVar29 + -1) {
        local_278 = (float)(local_214 + 2);
        local_224 = local_254 - local_214;
        local_228 = iVar23;
        pfVar35 = pfVar26;
        do {
          local_24c = pfVar35 + 4;
          local_22c = (int)local_278;
          if ((int)local_278 < (int)fVar29) {
            local_1f8 = local_224 - (int)local_278;
            local_244 = pfVar35 + 10;
            local_1f0 = unaff_ESI + (local_214 + -1 + (int)local_278 * 2) * -4 + 0x19;
            do {
              local_58 = pfVar35[6] - pfVar26[2];
              local_78 = *local_244 - pfVar26[2];
              local_270 = local_78 * (pfVar35[5] - pfVar26[1]) -
                          (local_244[-1] - pfVar26[1]) * local_58;
              local_26c = (local_244[-2] - *pfVar26) * local_58 - (*local_24c - *pfVar26) * local_78
              ;
              fVar25 = (*local_24c - *pfVar26) * (local_244[-1] - pfVar26[1]) -
                       (local_244[-2] - *pfVar26) * (pfVar35[5] - pfVar26[1]);
              local_268 = SQRT(local_26c * local_26c + fVar25 * fVar25 + local_270 * local_270);
              if (local_268 == 0.0) {
                local_270 = 1.0;
                local_26c = 0.0;
                local_268 = 0.0;
              }
              else {
                local_268 = _K_ONE / local_268;
                local_270 = local_270 * local_268;
                local_26c = local_26c * local_268;
                local_268 = local_268 * fVar25;
              }
              if (0.0 <= (unaff_ESI[0x11] - pfVar26[1]) * local_26c +
                         (unaff_ESI[0x12] - pfVar26[2]) * local_268 +
                         (unaff_ESI[0x10] - *pfVar26) * local_270) {
                *param_2 = local_270;
                param_2[1] = local_26c;
                fVar25 = local_268;
              }
              else {
                local_98 = -local_268;
                *param_2 = -local_270;
                param_2[1] = -local_26c;
                fVar25 = -local_268;
              }
              param_2[2] = fVar25;
              local_250 = local_214;
              fVar25 = *pfVar26 * *param_2 + pfVar26[1] * param_2[1] + pfVar26[2] * param_2[2];
              local_1e8 = fVar25;
              if ((local_1f8 < (int)fVar29) &&
                 (fVar2 = *local_1f0 * param_2[1] +
                          local_1f0[1] * param_2[2] + local_1f0[-1] * *param_2, fVar25 < fVar2)) {
                local_250 = local_1f8;
                local_1e8 = fVar2;
              }
              local_248 = 0;
              iVar24 = 1;
              local_68 = unaff_ESI[0x10] * *param_2 +
                         unaff_ESI[0x12] * param_2[2] + unaff_ESI[0x11] * param_2[1];
              if (3 < (int)fVar11 + -1) {
                iVar34 = 4;
                pfVar28 = unaff_ESI + 0x15;
                do {
                  fVar2 = *pfVar28 * param_2[1] + pfVar28[1] * param_2[2] + pfVar28[-1] * *param_2;
                  if (fVar2 < local_68) {
                    local_68 = fVar2;
                    local_248 = iVar24;
                  }
                  fVar2 = pfVar28[3] * *param_2 + pfVar28[5] * param_2[2] + pfVar28[4] * param_2[1];
                  if (fVar2 < local_68) {
                    local_248 = iVar34 + -2;
                    local_68 = fVar2;
                  }
                  fVar2 = pfVar28[7] * *param_2 + pfVar28[9] * param_2[2] + pfVar28[8] * param_2[1];
                  if (fVar2 < local_68) {
                    local_248 = iVar34 + -1;
                    local_68 = fVar2;
                  }
                  fVar2 = pfVar28[0xb] * *param_2 +
                          pfVar28[0xd] * param_2[2] + pfVar28[0xc] * param_2[1];
                  if (fVar2 < local_68) {
                    local_68 = fVar2;
                    local_248 = iVar34;
                  }
                  iVar34 = iVar34 + 4;
                  iVar24 = iVar24 + 4;
                  pfVar28 = pfVar28 + 0x10;
                } while (iVar34 < (int)fVar11);
              }
              if (iVar24 < (int)fVar11) {
                pfVar28 = unaff_ESI + iVar24 * 4 + 0x11;
                do {
                  fVar2 = *pfVar28 * param_2[1] + pfVar28[1] * param_2[2] + pfVar28[-1] * *param_2;
                  if (fVar2 < local_68) {
                    local_68 = fVar2;
                    local_248 = iVar24;
                  }
                  iVar24 = iVar24 + 1;
                  pfVar28 = pfVar28 + 4;
                } while (iVar24 < (int)fVar11);
              }
              if (local_1e8 < local_68) {
                pfVar28 = unaff_ESI + (local_248 + 4) * 4;
                local_b8 = pfVar28[2] - pfVar26[2];
                local_d8 = pfVar35[6] - pfVar26[2];
                if (0.0 < ((*local_24c - *pfVar26) * local_268 - local_270 * local_d8) *
                          (pfVar28[1] - pfVar26[1]) +
                          (local_270 * (pfVar35[5] - pfVar26[1]) -
                          (*local_24c - *pfVar26) * local_26c) * (pfVar28[2] - pfVar26[2]) +
                          (local_26c * local_d8 - (pfVar35[5] - pfVar26[1]) * local_268) *
                          (unaff_ESI[(local_248 + 4) * 4] - *pfVar26)) {
                  local_e8 = pfVar28[2] - pfVar35[6];
                  local_88 = *local_244 - pfVar35[6];
                  if (0.0 < ((local_244[-2] - *local_24c) * local_268 - local_270 * local_88) *
                            (pfVar28[1] - pfVar35[5]) +
                            (local_270 * (local_244[-1] - pfVar35[5]) -
                            (local_244[-2] - *local_24c) * local_26c) * (pfVar28[2] - pfVar35[6]) +
                            (local_26c * local_88 - (local_244[-1] - pfVar35[5]) * local_268) *
                            (*pfVar28 - *local_24c)) {
                    local_38 = pfVar28[2] - *local_244;
                    local_a8 = pfVar26[2] - *local_244;
                    if (0.0 < ((*pfVar26 - local_244[-2]) * local_268 - local_270 * local_a8) *
                              (pfVar28[1] - local_244[-1]) +
                              (local_270 * (pfVar26[1] - local_244[-1]) -
                              (*pfVar26 - local_244[-2]) * local_26c) * (pfVar28[2] - *local_244) +
                              (local_26c * local_a8 - (pfVar26[1] - local_244[-1]) * local_268) *
                              (*pfVar28 - local_244[-2])) {
                      local_68 = local_68 - fVar25;
                      local_d0 = local_68 * *param_2;
                      fVar12 = local_68 * param_2[1];
                      local_68 = local_68 * param_2[2];
                      fVar25 = pfVar28[1];
                      fVar2 = pfVar28[2];
                      local_48 = fVar2 - local_68;
                      unaff_ESI[0x20] = *pfVar28 - local_d0;
                      unaff_ESI[0x21] = fVar25 - fVar12;
                      unaff_ESI[0x22] = fVar2 - local_68;
                      fVar25 = pfVar28[1];
                      fVar2 = pfVar28[2];
                      unaff_ESI[0x24] = *pfVar28;
                      unaff_ESI[0x25] = fVar25;
                      unaff_ESI[0x26] = fVar2;
                      fVar25 = local_d0 * local_d0 + fVar12 * fVar12 + local_68 * local_68;
                      if (local_250 == local_214) {
                        unaff_ESI[0x30] = 4.2039e-45;
                        unaff_ESI[0x2c] = unaff_ESI[local_214 + 0x2c];
                        fVar29 = unaff_ESI[local_214 * 4 + 1];
                        fVar11 = unaff_ESI[local_214 * 4 + 2];
                        *unaff_ESI = unaff_ESI[local_214 * 4];
                        unaff_ESI[1] = fVar29;
                        unaff_ESI[2] = fVar11;
                        unaff_ESI[0x2d] = unaff_ESI[local_228 + 0x2c];
                        fVar29 = unaff_ESI[local_228 * 4 + 1];
                        fVar11 = unaff_ESI[local_228 * 4 + 2];
                        unaff_ESI[4] = unaff_ESI[local_228 * 4];
                        unaff_ESI[5] = fVar29;
                        unaff_ESI[6] = fVar11;
                        unaff_ESI[0x2e] = unaff_ESI[local_22c + 0x2c];
                        fVar29 = unaff_ESI[local_22c * 4 + 1];
                        fVar11 = unaff_ESI[local_22c * 4 + 2];
                        unaff_ESI[8] = unaff_ESI[local_22c * 4];
                        unaff_ESI[9] = fVar29;
                        unaff_ESI[10] = fVar11;
                        unaff_ESI[0x35] = 1.4013e-45;
                        fVar29 = unaff_ESI[local_248 + 0x31];
                        goto LAB_0047135f;
                      }
                      if (fVar25 < local_1f4) {
                        local_170 = unaff_ESI[0x20];
                        local_16c = unaff_ESI[0x21];
                        local_150 = unaff_ESI[0x24];
                        local_168 = unaff_ESI[0x22];
                        local_160 = *param_2;
                        local_188[0] = local_214;
                        local_14c = unaff_ESI[0x25];
                        bVar22 = true;
                        local_15c = param_2[1];
                        local_188[1] = local_228;
                        local_18c = (float *)0x1;
                        local_148 = unaff_ESI[0x26];
                        local_158 = param_2[2];
                        local_178 = 4.2039e-45;
                        local_188[2] = local_22c;
                        local_19c[0] = local_248;
                        local_1f4 = fVar25;
                      }
                    }
                  }
                }
              }
              local_22c = local_22c + 1;
              local_1f0 = local_1f0 + -4;
              local_1f8 = local_1f8 + -1;
              local_244 = local_244 + 4;
            } while (local_22c < (int)fVar29);
          }
          local_228 = local_228 + 1;
          local_278 = (float)((int)local_278 + 1);
          local_224 = local_224 + -1;
          pfVar35 = local_24c;
        } while (local_228 < (int)fVar29 + -1);
      }
      local_254 = local_254 + -1;
      pfVar26 = pfVar26 + 4;
      local_214 = iVar23;
    } while (iVar23 < (int)local_174);
  }
  local_214 = 0;
  if (fVar11 != 2.8026e-45 && -1 < (int)fVar11 + -2) {
    pfVar26 = unaff_ESI + 0x10;
    local_1fc = 5;
    do {
      iVar23 = local_214 + 1;
      if (iVar23 < (int)fVar11 + -1) {
        iVar24 = local_214 + 2;
        local_1f8 = local_1fc - local_214;
        local_228 = iVar23;
        pfVar35 = pfVar26;
        do {
          pfVar28 = pfVar35 + 4;
          if (iVar24 < (int)fVar11) {
            local_224 = local_1f8 - iVar24;
            local_244 = pfVar35 + 10;
            pfVar27 = unaff_ESI + (local_214 + -1 + iVar24 * 2) * -4 + 0x29;
            local_22c = iVar24;
            do {
              local_58 = pfVar35[6] - pfVar26[2];
              local_78 = *local_244 - pfVar26[2];
              local_270 = local_78 * (pfVar35[5] - pfVar26[1]) -
                          (local_244[-1] - pfVar26[1]) * local_58;
              local_26c = (local_244[-2] - *pfVar26) * local_58 - (*pfVar28 - *pfVar26) * local_78;
              fVar25 = (*pfVar28 - *pfVar26) * (local_244[-1] - pfVar26[1]) -
                       (local_244[-2] - *pfVar26) * (pfVar35[5] - pfVar26[1]);
              local_268 = SQRT(local_26c * local_26c + fVar25 * fVar25 + local_270 * local_270);
              if (local_268 == 0.0) {
                local_270 = 1.0;
                local_26c = 0.0;
                local_268 = 0.0;
              }
              else {
                local_268 = _K_ONE / local_268;
                local_270 = local_270 * local_268;
                local_26c = local_26c * local_268;
                local_268 = local_268 * fVar25;
              }
              if (0.0 <= (*pfVar26 - *unaff_ESI) * local_270 +
                         (pfVar26[1] - unaff_ESI[1]) * local_26c +
                         local_268 * (pfVar26[2] - unaff_ESI[2])) {
                *param_2 = local_270;
                param_2[1] = local_26c;
                fVar25 = local_268;
              }
              else {
                local_98 = -local_268;
                *param_2 = -local_270;
                param_2[1] = -local_26c;
                fVar25 = -local_268;
              }
              param_2[2] = fVar25;
              local_248 = local_214;
              local_68 = param_2[2] * pfVar26[2] + pfVar26[1] * param_2[1] + *pfVar26 * *param_2;
              local_1e8 = local_68;
              if ((local_224 < (int)fVar11) &&
                 (fVar25 = *pfVar27 * param_2[1] + pfVar27[1] * param_2[2] + pfVar27[-1] * *param_2,
                 fVar25 < local_68)) {
                local_248 = local_224;
                local_1e8 = fVar25;
              }
              local_250 = 0;
              iVar34 = 1;
              fVar25 = param_2[1] * unaff_ESI[1] + param_2[2] * unaff_ESI[2] + *param_2 * *unaff_ESI
              ;
              if (3 < (int)fVar29 + -1) {
                iVar31 = 4;
                pfVar30 = unaff_ESI + 9;
                do {
                  fVar2 = pfVar30[-3] * param_2[2] +
                          pfVar30[-5] * *param_2 + pfVar30[-4] * param_2[1];
                  if (fVar25 < fVar2) {
                    fVar25 = fVar2;
                    local_250 = iVar34;
                  }
                  fVar2 = param_2[1] * *pfVar30 + pfVar30[1] * param_2[2] + pfVar30[-1] * *param_2;
                  if (fVar25 < fVar2) {
                    local_250 = iVar31 + -2;
                    fVar25 = fVar2;
                  }
                  fVar2 = pfVar30[3] * *param_2 + pfVar30[5] * param_2[2] + pfVar30[4] * param_2[1];
                  if (fVar25 < fVar2) {
                    local_250 = iVar31 + -1;
                    fVar25 = fVar2;
                  }
                  fVar2 = pfVar30[7] * *param_2 + pfVar30[9] * param_2[2] + pfVar30[8] * param_2[1];
                  if (fVar25 < fVar2) {
                    fVar25 = fVar2;
                    local_250 = iVar31;
                  }
                  iVar31 = iVar31 + 4;
                  iVar34 = iVar34 + 4;
                  pfVar30 = pfVar30 + 0x10;
                } while (iVar31 < (int)fVar29);
              }
              if (iVar34 < (int)fVar29) {
                pfVar30 = unaff_ESI + iVar34 * 4 + 1;
                do {
                  fVar2 = *pfVar30 * param_2[1] + pfVar30[1] * param_2[2] + pfVar30[-1] * *param_2;
                  if (fVar25 < fVar2) {
                    fVar25 = fVar2;
                    local_250 = iVar34;
                  }
                  iVar34 = iVar34 + 1;
                  pfVar30 = pfVar30 + 4;
                } while (iVar34 < (int)fVar29);
              }
              if (fVar25 < local_1e8) {
                pfVar30 = unaff_ESI + local_250 * 4;
                local_b8 = pfVar30[2] - pfVar26[2];
                local_d8 = pfVar35[6] - pfVar26[2];
                if (0.0 < ((*pfVar28 - *pfVar26) * local_268 - local_270 * local_d8) *
                          (pfVar30[1] - pfVar26[1]) +
                          (local_270 * (pfVar35[5] - pfVar26[1]) - (*pfVar28 - *pfVar26) * local_26c
                          ) * (pfVar30[2] - pfVar26[2]) +
                          (local_26c * local_d8 - (pfVar35[5] - pfVar26[1]) * local_268) *
                          (unaff_ESI[local_250 * 4] - *pfVar26)) {
                  local_e8 = pfVar30[2] - pfVar35[6];
                  local_88 = *local_244 - pfVar35[6];
                  if (0.0 < ((local_244[-2] - *pfVar28) * local_268 - local_270 * local_88) *
                            (pfVar30[1] - pfVar35[5]) +
                            (local_270 * (local_244[-1] - pfVar35[5]) -
                            (local_244[-2] - *pfVar28) * local_26c) * (pfVar30[2] - pfVar35[6]) +
                            (local_26c * local_88 - (local_244[-1] - pfVar35[5]) * local_268) *
                            (*pfVar30 - *pfVar28)) {
                    local_38 = pfVar30[2] - *local_244;
                    local_a8 = pfVar26[2] - *local_244;
                    if (0.0 < ((*pfVar26 - local_244[-2]) * local_268 - local_270 * local_a8) *
                              (pfVar30[1] - local_244[-1]) +
                              (local_270 * (pfVar26[1] - local_244[-1]) -
                              (*pfVar26 - local_244[-2]) * local_26c) * (pfVar30[2] - *local_244) +
                              (local_26c * local_a8 - (pfVar26[1] - local_244[-1]) * local_268) *
                              (*pfVar30 - local_244[-2])) {
                      local_68 = local_68 - fVar25;
                      local_d0 = local_68 * *param_2;
                      fVar12 = local_68 * param_2[1];
                      local_68 = local_68 * param_2[2];
                      fVar25 = pfVar30[1];
                      fVar2 = pfVar30[2];
                      unaff_ESI[0x20] = *pfVar30;
                      unaff_ESI[0x21] = fVar25;
                      unaff_ESI[0x22] = fVar2;
                      fVar25 = pfVar30[1];
                      fVar2 = pfVar30[2];
                      local_48 = fVar2 + local_68;
                      unaff_ESI[0x24] = local_d0 + *pfVar30;
                      unaff_ESI[0x25] = fVar25 + fVar12;
                      unaff_ESI[0x26] = fVar2 + local_68;
                      fVar25 = local_d0 * local_d0 + fVar12 * fVar12 + local_68 * local_68;
                      if (local_248 == local_214) {
                        unaff_ESI[0x30] = 1.4013e-45;
                        unaff_ESI[0x2c] = unaff_ESI[local_250 + 0x2c];
                        fVar29 = unaff_ESI[local_250 * 4 + 1];
                        fVar11 = (unaff_ESI + local_250 * 4)[2];
                        *unaff_ESI = unaff_ESI[local_250 * 4];
                        unaff_ESI[1] = fVar29;
                        iVar23 = local_214 + 4;
                        unaff_ESI[2] = fVar11;
                        unaff_ESI[0x35] = 4.2039e-45;
                        unaff_ESI[0x31] = unaff_ESI[local_214 + 0x31];
                        fVar29 = unaff_ESI[iVar23 * 4 + 1];
                        fVar11 = unaff_ESI[iVar23 * 4 + 2];
                        unaff_ESI[0x10] = unaff_ESI[iVar23 * 4];
                        unaff_ESI[0x11] = fVar29;
                        unaff_ESI[0x12] = fVar11;
                        unaff_ESI[0x32] = unaff_ESI[local_228 + 0x31];
                        local_228 = local_228 + 4;
                        fVar29 = unaff_ESI[local_228 * 4 + 1];
                        fVar11 = unaff_ESI[local_228 * 4 + 2];
                        unaff_ESI[0x14] = unaff_ESI[local_228 * 4];
                        unaff_ESI[0x15] = fVar29;
                        iVar23 = local_22c + 4;
                        unaff_ESI[0x16] = fVar11;
                        unaff_ESI[0x33] = unaff_ESI[local_22c + 0x31];
                        fVar29 = unaff_ESI[iVar23 * 4 + 1];
                        fVar11 = unaff_ESI[iVar23 * 4 + 2];
                        unaff_ESI[0x18] = unaff_ESI[iVar23 * 4];
                        unaff_ESI[0x19] = fVar29;
                        unaff_ESI[0x1a] = fVar11;
                        return unaff_ESI + iVar23 * 4;
                      }
                      if (fVar25 < local_1f4) {
                        local_170 = unaff_ESI[0x20];
                        local_16c = unaff_ESI[0x21];
                        local_150 = unaff_ESI[0x24];
                        local_168 = unaff_ESI[0x22];
                        bVar22 = true;
                        local_160 = *param_2;
                        local_178 = 1.4013e-45;
                        local_14c = unaff_ESI[0x25];
                        local_15c = param_2[1];
                        local_188[0] = local_250;
                        local_19c[0] = local_214;
                        local_148 = unaff_ESI[0x26];
                        local_158 = param_2[2];
                        local_18c = (float *)0x3;
                        local_19c[1] = local_228;
                        local_19c[2] = local_22c;
                        local_1f4 = fVar25;
                      }
                    }
                  }
                }
              }
              local_244 = local_244 + 4;
              local_22c = local_22c + 1;
              pfVar27 = pfVar27 + -4;
              local_224 = local_224 + -1;
            } while (local_22c < (int)fVar11);
          }
          local_228 = local_228 + 1;
          iVar24 = iVar24 + 1;
          local_1f8 = local_1f8 + -1;
          pfVar35 = pfVar28;
        } while (local_228 < (int)fVar11 + -1);
      }
      local_1fc = local_1fc + -1;
      pfVar26 = pfVar26 + 4;
      local_214 = iVar23;
    } while (iVar23 < (int)fVar11 + -2);
  }
  if (!bVar22) {
    return (float *)0x0;
  }
  unaff_ESI[0x20] = local_170;
  unaff_ESI[0x21] = local_16c;
  unaff_ESI[0x22] = local_168;
  unaff_ESI[0x24] = local_150;
  unaff_ESI[0x25] = local_14c;
  unaff_ESI[0x26] = local_148;
  *param_2 = local_160;
  param_2[1] = local_15c;
  param_2[2] = local_158;
  iVar23 = 0;
  unaff_ESI[0x30] = local_178;
  unaff_ESI[0x35] = (float)local_18c;
  if (0 < (int)local_178) {
    pfVar26 = unaff_ESI + 2;
    pfVar35 = unaff_ESI + 0x2c;
    do {
      iVar24 = local_188[iVar23];
      *pfVar35 = unaff_ESI[iVar24 + 0x2c];
      fVar29 = unaff_ESI[iVar24 * 4 + 1];
      fVar11 = unaff_ESI[iVar24 * 4 + 2];
      pfVar26[-2] = unaff_ESI[iVar24 * 4];
      pfVar26[-1] = fVar29;
      *pfVar26 = fVar11;
      iVar23 = iVar23 + 1;
      pfVar35 = pfVar35 + 1;
      pfVar26 = pfVar26 + 4;
    } while (iVar23 < (int)local_178);
  }
  iVar23 = 0;
  if (0 < (int)local_18c) {
    pfVar35 = unaff_ESI + 0x31;
    pfVar26 = unaff_ESI + 0x12;
    do {
      iVar24 = local_19c[iVar23] + 4;
      *pfVar35 = unaff_ESI[local_19c[iVar23] + 0x31];
      fVar29 = unaff_ESI[iVar24 * 4 + 1];
      fVar11 = unaff_ESI[iVar24 * 4 + 2];
      pfVar26[-2] = unaff_ESI[iVar24 * 4];
      pfVar26[-1] = fVar29;
      *pfVar26 = fVar11;
      iVar23 = iVar23 + 1;
      pfVar26 = pfVar26 + 4;
      pfVar35 = pfVar35 + 1;
    } while (iVar23 < (int)local_18c);
  }
  return local_18c;
}


