// ==== 0x581b30 MakeAccelerationTable

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void MakeAccelerationTable(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int in_EAX;
  float *pfVar7;
  int iVar8;
  undefined4 *puVar9;
  float10 fVar10;
  int local_60;
  float local_5c;
  float local_24 [9];
  
  fVar1 = *(float *)(in_EAX + 0x1c0);
  fVar5 = _K_ONE - fVar1;
  fVar4 = *(float *)(in_EAX + 0x110);
  fVar2 = *(float *)(in_EAX + 0x80);
  fVar3 = *(float *)(in_EAX + 0x20);
  fVar6 = fVar1 * *(float *)(in_EAX + 0x1bc) + fVar5 * *(float *)(in_EAX + 0x1b8);
  FUN_0046d1c0(in_EAX + 0x1b0,local_24);
  local_60 = 0;
  local_5c = 0.0;
  pfVar7 = (float *)(in_EAX + 0x1d8);
  fVar1 = _K_ONE / (fVar5 * fVar3 + fVar1 * fVar2);
  iVar8 = 2;
  do {
    fVar2 = fVar1 * local_5c * *pfVar7 * fVar6 * 9.549304;
    if (local_24[iVar8] <= fVar2) {
      iVar8 = iVar8 + 1;
      pfVar7 = pfVar7 + 1;
      if (*(int *)(in_EAX + 0x1c8) + 2 <= iVar8) break;
    }
    fVar10 = (float10)FUN_00583ea0(fVar2);
    local_60 = local_60 + 1;
    *(float *)(&DAT_0078efb4 + local_60 * 4) =
         (float)((fVar10 * (float10)*pfVar7 * (float10)fVar6 * (float10)fVar1) / (float10)fVar4);
    local_5c = local_5c + 1.3410819;
  } while (local_60 < 0x4b);
  *(float *)(param_2 + 0x42c) = local_5c;
  local_60 = local_60 + -1;
  if (local_60 < 0x4b) {
    puVar9 = (undefined4 *)(&DAT_0078efb8 + local_60 * 4);
    for (iVar8 = 0x4b - local_60; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
  }
  local_60 = 0;
  if (0 < *param_1) {
    do {
      fVar10 = (float10)FUN_00583ea0(((float)local_60 * 98.346) / (float)(*param_1 + -1));
      *(float *)(param_1[4] + local_60 * 4) = (float)fVar10;
      local_60 = local_60 + 1;
    } while (local_60 < *param_1);
  }
  param_1[2] = 0x42c4b127;
  param_1[1] = 0;
  param_1[3] = (int)((float)(*param_1 + -1) / 98.346);
  return;
}


// ==== 0x581d30 FUN_00581d30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00581d30(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float local_18;
  
  fVar1 = (*(float *)(param_1 + 0x180) + *(float *)(param_1 + 0x174) +
          *(float *)(param_1 + 0x1a0) + *(float *)(param_1 + 0x194)) * 0.5 * 0.5;
  if (_DAT_006f0d30 < fVar1) {
    fVar1 = _DAT_006f0d30;
  }
  fVar2 = (*(float *)(param_1 + 0x180) + *(float *)(param_1 + 0x174) +
          *(float *)(param_1 + 0x1a0) + *(float *)(param_1 + 0x194)) * 0.5 * 0.5;
  if (fVar2 < _DAT_006f0d34) {
    fVar2 = _DAT_006f0d34;
  }
  fVar3 = (*(float *)(param_1 + 0xe0) + *(float *)(param_1 + 0xdc) +
          *(float *)(param_1 + 0x100) + *(float *)(param_1 + 0xfc)) * 0.5 * 0.5;
  if (_DAT_006f0d38 < fVar3) {
    fVar3 = _DAT_006f0d38;
  }
  fVar4 = (*(float *)(param_1 + 0xe0) + *(float *)(param_1 + 0xdc) +
          *(float *)(param_1 + 0x100) + *(float *)(param_1 + 0xfc)) * 0.5 * 0.5;
  if (fVar4 < _DAT_006f0d3c) {
    fVar4 = _DAT_006f0d3c;
  }
  fVar5 = *(float *)(param_1 + 0x274) * 0.65 + *(float *)(param_1 + 0x278) * 0.35;
  if (_DAT_006f0d40 < fVar5) {
    fVar5 = _DAT_006f0d40;
  }
  fVar6 = *(float *)(param_1 + 0x274) * 0.65 + *(float *)(param_1 + 0x278) * 0.35;
  if (fVar6 < _DAT_006f0d44) {
    fVar6 = _DAT_006f0d44;
  }
  fVar7 = *(float *)(param_1 + 0x110);
  if (_DAT_006f0d48 < *(float *)(param_1 + 0x110)) {
    fVar7 = _DAT_006f0d48;
  }
  fVar8 = *(float *)(param_1 + 0x110);
  if (*(float *)(param_1 + 0x110) < _DAT_006f0d4c) {
    fVar8 = _DAT_006f0d4c;
  }
  _DAT_006f0d34 =
       (*(float *)(param_1 + 0x740) + *(float *)(param_1 + 0x734) +
       *(float *)(param_1 + 0x760) + *(float *)(param_1 + 0x754)) * 0.5 * 0.5;
  local_18 = _DAT_006f0d34;
  if (fVar1 < _DAT_006f0d34) {
    local_18 = fVar1;
  }
  if (_DAT_006f0d34 < fVar2) {
    _DAT_006f0d34 = fVar2;
  }
  fVar1 = (*(float *)(param_1 + 0x790) + *(float *)(param_1 + 0x784) +
          *(float *)(param_1 + 0x7b0) + *(float *)(param_1 + 0x7a4)) * 0.5 * 0.5;
  if (fVar1 <= local_18) {
    local_18 = fVar1;
  }
  if (_DAT_006f0d34 <= fVar1) {
    _DAT_006f0d34 = fVar1;
  }
  fVar1 = (*(float *)(param_1 + 0x7e0) + *(float *)(param_1 + 0x7d4) +
          *(float *)(param_1 + 0x800) + *(float *)(param_1 + 0x7f4)) * 0.5 * 0.5;
  if (fVar1 <= local_18) {
    local_18 = fVar1;
  }
  _DAT_006f0d30 = local_18;
  if (_DAT_006f0d34 <= fVar1) {
    _DAT_006f0d34 = fVar1;
  }
  _DAT_006f0d3c =
       (*(float *)(param_1 + 0x5c0) + *(float *)(param_1 + 0x5bc) + *(float *)(param_1 + 0x830) +
        *(float *)(param_1 + 0x838) +
       *(float *)(param_1 + 0x5e0) + *(float *)(param_1 + 0x5dc) + *(float *)(param_1 + 0x834) +
       *(float *)(param_1 + 0x83c)) * 0.5 * 0.5;
  local_18 = _DAT_006f0d3c;
  if (fVar3 < _DAT_006f0d3c) {
    local_18 = fVar3;
  }
  if (_DAT_006f0d3c < fVar4) {
    _DAT_006f0d3c = fVar4;
  }
  fVar1 = (*(float *)(param_1 + 0x600) + *(float *)(param_1 + 0x5fc) + *(float *)(param_1 + 0x830) +
           *(float *)(param_1 + 0x838) +
          *(float *)(param_1 + 0x620) + *(float *)(param_1 + 0x61c) + *(float *)(param_1 + 0x834) +
          *(float *)(param_1 + 0x83c)) * 0.5 * 0.5;
  if (fVar1 <= local_18) {
    local_18 = fVar1;
  }
  if (_DAT_006f0d3c <= fVar1) {
    _DAT_006f0d3c = fVar1;
  }
  fVar1 = (*(float *)(param_1 + 0x640) + *(float *)(param_1 + 0x63c) + *(float *)(param_1 + 0x830) +
           *(float *)(param_1 + 0x838) +
          *(float *)(param_1 + 0x660) + *(float *)(param_1 + 0x65c) + *(float *)(param_1 + 0x834) +
          *(float *)(param_1 + 0x83c)) * 0.5 * 0.5;
  if (fVar1 <= local_18) {
    local_18 = fVar1;
  }
  _DAT_006f0d38 = local_18;
  if (_DAT_006f0d3c <= fVar1) {
    _DAT_006f0d3c = fVar1;
  }
  _DAT_006f0d44 =
       *(float *)(param_1 + 0x704) * 0.35 +
       (*(float *)(param_1 + 0x700) + *(float *)(param_1 + 0x82c)) * 0.65;
  local_18 = _DAT_006f0d44;
  if (fVar5 < _DAT_006f0d44) {
    local_18 = fVar5;
  }
  if (_DAT_006f0d44 < fVar6) {
    _DAT_006f0d44 = fVar6;
  }
  fVar1 = *(float *)(param_1 + 0x714) * 0.35 +
          (*(float *)(param_1 + 0x710) + *(float *)(param_1 + 0x82c)) * 0.65;
  if (fVar1 <= local_18) {
    local_18 = fVar1;
  }
  if (_DAT_006f0d44 <= fVar1) {
    _DAT_006f0d44 = fVar1;
  }
  fVar1 = *(float *)(param_1 + 0x724) * 0.35 +
          (*(float *)(param_1 + 0x720) + *(float *)(param_1 + 0x82c)) * 0.65;
  if (fVar1 <= local_18) {
    local_18 = fVar1;
  }
  _DAT_006f0d40 = local_18;
  if (_DAT_006f0d44 <= fVar1) {
    _DAT_006f0d44 = fVar1;
  }
  fVar1 = (*(float *)(param_1 + 0x2b0) - *(float *)(param_1 + 0x820)) * *(float *)(param_1 + 0x110);
  local_18 = fVar1;
  if (fVar7 < fVar1) {
    local_18 = fVar7;
  }
  if (fVar8 <= fVar1) {
    fVar8 = fVar1;
  }
  fVar1 = (*(float *)(param_1 + 0x2c0) - *(float *)(param_1 + 0x820)) * *(float *)(param_1 + 0x110);
  if (fVar1 <= local_18) {
    local_18 = fVar1;
  }
  if (fVar8 <= fVar1) {
    fVar8 = fVar1;
  }
  fVar1 = (*(float *)(param_1 + 0x2d0) - *(float *)(param_1 + 0x820)) * *(float *)(param_1 + 0x110);
  if (fVar1 <= local_18) {
    local_18 = fVar1;
  }
  _DAT_006f0d48 = local_18;
  if (fVar8 <= fVar1) {
    fVar8 = fVar1;
  }
  _DAT_006f0d4c = fVar8;
  local_18 = (*(float *)(param_1 + 0x67c) + *(float *)(param_1 + 0x828)) *
             *(float *)(param_1 + 0x670);
  _DAT_006f0d50 = local_18;
  if (0.0 < local_18) {
    _DAT_006f0d50 = 0.0;
  }
  if (local_18 < DAT_006f0d54) {
    local_18 = DAT_006f0d54;
  }
  fVar1 = (*(float *)(param_1 + 0x68c) + *(float *)(param_1 + 0x828)) * *(float *)(param_1 + 0x680);
  if (fVar1 <= _DAT_006f0d50) {
    _DAT_006f0d50 = fVar1;
  }
  if (local_18 <= fVar1) {
    local_18 = fVar1;
  }
  DAT_006f0d54 = (*(float *)(param_1 + 0x69c) + *(float *)(param_1 + 0x828)) *
                 *(float *)(param_1 + 0x690);
  if (DAT_006f0d54 <= _DAT_006f0d50) {
    _DAT_006f0d50 = DAT_006f0d54;
  }
  if (DAT_006f0d54 < local_18) {
    DAT_006f0d54 = local_18;
    _K_HALF = 0x3f000000;
    return;
  }
  _K_HALF = 0x3f000000;
  return;
}


// ==== 0x5824b0 FUN_005824b0

void FUN_005824b0(int param_1)

{
  float fVar1;
  char cVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined4 *puVar8;
  int *piVar9;
  int local_58 [22];
  
  cVar2 = *(char *)(param_1 + 0x424);
  piVar9 = (int *)(param_1 + 8);
  piVar6 = piVar9;
  piVar7 = local_58;
  for (iVar4 = 0x16; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar7 = *piVar6;
    piVar6 = piVar6 + 1;
    piVar7 = piVar7 + 1;
  }
  if (cVar2 == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  fVar3 = (*(float *)(param_1 + 0x418) - *(float *)(param_1 + 0x414)) * 0.03125;
  for (fVar1 = *(float *)(param_1 + 0x414); fVar1 < *(float *)(param_1 + 0x418);
      fVar1 = fVar1 + fVar3) {
  }
  for (fVar1 = *(float *)(param_1 + 0x414); fVar1 < *(float *)(param_1 + 0x418);
      fVar1 = fVar1 + fVar3) {
  }
  puVar8 = (undefined4 *)(param_1 + 0x34);
  for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  iVar4 = 0;
  do {
    piVar6 = piVar9;
    for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar6 = iVar4;
      piVar6 = piVar6 + 1;
    }
    RideInfo__RebuildPhysicsInfo(1);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  puVar8 = (undefined4 *)(param_1 + 0x34);
  for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = 1;
    puVar8 = puVar8 + 1;
  }
  RideInfo__RebuildPhysicsInfo(1);
  piVar6 = local_58;
  for (iVar4 = 0x16; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar9 = *piVar6;
    piVar6 = piVar6 + 1;
    piVar9 = piVar9 + 1;
  }
  RideInfo__RebuildPhysicsInfo(1);
  return;
}


// ==== 0x5825c0 FUN_005825c0

void FUN_005825c0(void)

{
  int unaff_ESI;
  
  if (*(void **)(unaff_ESI + 0x10) != (void *)0x0) {
    _free(*(void **)(unaff_ESI + 0x10));
  }
  if (*(void **)(unaff_ESI + 0x2c) != (void *)0x0) {
    _free(*(void **)(unaff_ESI + 0x2c));
  }
  return;
}


// ==== 0x5825e0 FUN_005825e0

void FUN_005825e0(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684b68;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[5] = 1;
  if (param_1[3] != 0) {
    if (param_1[1] != *param_1) goto LAB_0058267b;
    if (param_1[3] != 0) {
      *param_1 = *param_1 << 1;
    }
  }
  iVar5 = *param_1;
  puVar3 = _malloc(iVar5 << 4);
  local_4 = 0;
  puVar4 = (undefined4 *)0x0;
  if (puVar3 != (undefined4 *)0x0) {
    CallNTimes(puVar3,0x10,iVar5,FUN_004ad8d0);
    puVar4 = puVar3;
  }
  puVar3 = (undefined4 *)param_1[3];
  puVar6 = puVar4;
  for (iVar5 = (param_1[1] & 0xfffffffU) << 2; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar6 = puVar6 + 1;
  }
  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)puVar6 = *(undefined1 *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  if ((void *)param_1[4] != (void *)0x0) {
    _free((void *)param_1[4]);
  }
  param_1[3] = (int)puVar4;
  param_1[4] = (int)puVar4;
LAB_0058267b:
  puVar4 = (undefined4 *)(param_1[1] * 0x10 + param_1[3]);
  param_1[1] = param_1[1] + 1;
  uVar1 = param_2[2];
  uVar2 = *param_2;
  puVar4[1] = param_2[1];
  *puVar4 = uVar2;
  puVar4[2] = uVar1;
  ExceptionList = local_c;
  return;
}


// ==== 0x5826c0 FUN_005826c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_005826c0(float param_1)

{
  float *pfVar1;
  int in_EAX;
  int iVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  float local_24;
  
  if ((_DAT_0078efb0 & 1) == 0) {
    _DAT_0078efb0 = _DAT_0078efb0 | 1;
  }
  iVar4 = *(int *)(in_EAX + 8);
  if (iVar4 == 0) {
LAB_00582700:
    iVar2 = *(int *)(in_EAX + 4) + -1;
  }
  else {
    if (iVar4 != 1) {
      if (iVar4 != 2) {
        local_24 = 0.0;
        goto LAB_00582710;
      }
      goto LAB_00582700;
    }
    iVar2 = *(int *)(in_EAX + 4);
  }
  local_24 = (float)iVar2;
LAB_00582710:
  if (iVar4 != 0) {
    if (iVar4 == 1) {
      FUN_00564ad0(param_1,local_24);
    }
    else if (iVar4 == 2) {
      if (param_1 < 0.0) {
        pfVar1 = *(float **)(in_EAX + 0xc);
        pfVar3 = *(float **)(in_EAX + 0xc);
        _DAT_0078efa0 = (pfVar1[4] - *pfVar1) * param_1 + *pfVar3;
        _DAT_0078efa4 = pfVar3[1] + (pfVar1[5] - pfVar1[1]) * param_1;
        _DAT_0078efa8 = pfVar3[2] + (pfVar1[6] - pfVar1[2]) * param_1;
        return &DAT_0078efa0;
      }
      if (local_24 < param_1) {
        iVar2 = *(int *)(in_EAX + 0xc);
        pfVar3 = (float *)((*(int *)(in_EAX + 4) + -2) * 0x10 + iVar2);
        iVar5 = *(int *)(in_EAX + 4) * 0x10;
        iVar4 = iVar5 + -0x10 + iVar2;
        param_1 = param_1 - local_24;
        pfVar1 = (float *)(*(int *)(in_EAX + 4) * 0x10 + -0x10 + *(int *)(in_EAX + 0xc));
        _DAT_0078efa0 = (*(float *)(iVar5 + -0x10 + iVar2) - *pfVar3) * param_1 + *pfVar1;
        _DAT_0078efa4 = pfVar1[1] + param_1 * (*(float *)(iVar4 + 4) - pfVar3[1]);
        _DAT_0078efa8 = pfVar1[2] + param_1 * (*(float *)(iVar4 + 8) - pfVar3[2]);
        return &DAT_0078efa0;
      }
    }
  }
  iVar4 = _ftol_nocw();
  return (undefined *)(iVar4 * 0x10 + *(int *)(in_EAX + 0xc));
}


// ==== 0x5828e0 FUN_005828e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005828e0(float param_1,float param_2,float param_3,float param_4,float param_5)

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
  float *pfVar12;
  float *unaff_ESI;
  
  pfVar12 = (float *)FUN_005826c0(param_1 - _K_ONE);
  fVar1 = *pfVar12;
  fVar2 = pfVar12[1];
  fVar3 = pfVar12[2];
  pfVar12 = (float *)FUN_005826c0(param_1);
  fVar4 = *pfVar12;
  fVar5 = pfVar12[1];
  fVar6 = pfVar12[2];
  pfVar12 = (float *)FUN_005826c0(param_1 + _K_ONE);
  fVar7 = *pfVar12;
  fVar8 = pfVar12[1];
  fVar9 = pfVar12[2];
  pfVar12 = (float *)FUN_005826c0(param_1 + 2.0);
  fVar10 = pfVar12[1];
  fVar11 = pfVar12[2];
  *unaff_ESI = param_5 * *pfVar12 + param_4 * fVar7 + param_3 * fVar4 + fVar1 * param_2;
  unaff_ESI[1] = param_5 * fVar10 + param_4 * fVar8 + param_3 * fVar5 + fVar2 * param_2;
  unaff_ESI[2] = param_5 * fVar11 + param_4 * fVar9 + param_3 * fVar6 + fVar3 * param_2;
  return;
}


// ==== 0x5829e0 FUN_005829e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005829e0(undefined4 param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float fVar4;
  
  fVar3 = (float10)FUN_004387e0(param_2,param_1);
  fVar4 = (float)fVar3;
  if ((float10)param_2 < fVar3) {
    fVar4 = fVar4 - _K_ONE;
  }
  param_2 = param_2 - fVar4;
  fVar1 = param_2 * param_2;
  fVar2 = fVar1 * param_2;
  FUN_005828e0(fVar4,(((fVar1 + fVar1) - fVar2) - param_2) * _K_HALF,
               ((fVar2 * 3.0 - fVar1 * 5.0) + 2.0) * _K_HALF,
               ((fVar1 * 4.0 - fVar2 * 3.0) + param_2) * _K_HALF,(fVar2 - fVar1) * _K_HALF);
  return;
}


// ==== 0x582a90 FUN_00582a90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00582a90(undefined4 param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float fVar4;
  
  fVar3 = (float10)FUN_004387e0(param_2,param_1);
  fVar4 = (float)fVar3;
  if ((float10)param_2 < fVar3) {
    fVar4 = fVar4 - _K_ONE;
  }
  param_2 = param_2 - fVar4;
  fVar2 = param_2 * param_2 * 3.0;
  fVar1 = param_2 * param_2 * 9.0;
  FUN_005828e0(fVar4,((param_2 * 4.0 - fVar2) - _K_ONE) * _K_HALF,(fVar1 - param_2 * 10.0) * _K_HALF
               ,((param_2 * fRam006cc7c0 - fVar1) + _K_ONE) * _K_HALF,
               (fVar2 - (param_2 + param_2)) * _K_HALF);
  return;
}


// ==== 0x582b50 FUN_00582b50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00582b50(undefined4 param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float fVar4;
  
  fVar3 = (float10)FUN_004387e0(param_2,param_1);
  fVar4 = (float)fVar3;
  if ((float10)param_2 < fVar3) {
    fVar4 = fVar4 - _K_ONE;
  }
  fVar1 = (param_2 - fVar4) * 6.0;
  fVar2 = (param_2 - fVar4) * 18.0;
  FUN_005828e0(fVar4,(4.0 - fVar1) * _K_HALF,(fVar2 - 10.0) * _K_HALF,
               (fRam006cc7c0 - fVar2) * _K_HALF,(fVar1 - 2.0) * _K_HALF);
  return;
}


// ==== 0x582bf0 FUN_00582bf0

float10 __fastcall FUN_00582bf0(int param_1)

{
  float fVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    iVar4 = 1;
    *(undefined4 *)(param_1 + 0x20) = 0;
    if (1 < *(int *)(param_1 + 4)) {
      pfVar3 = *(float **)(param_1 + 0xc);
      pfVar2 = pfVar3 + 2;
      do {
        pfVar3 = pfVar3 + 4;
        iVar4 = iVar4 + 1;
        fVar1 = pfVar2[4] - *pfVar2;
        *(float *)(param_1 + 0x20) =
             SQRT((*pfVar3 - pfVar2[-2]) * (*pfVar3 - pfVar2[-2]) +
                  (pfVar2[3] - pfVar2[-1]) * (pfVar2[3] - pfVar2[-1]) + fVar1 * fVar1) +
             *(float *)(param_1 + 0x20);
        pfVar2 = pfVar2 + 4;
      } while (iVar4 < *(int *)(param_1 + 4));
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return (float10)*(float *)(param_1 + 0x20);
}


// ==== 0x582c60 FUN_00582c60

float10 FUN_00582c60(float *param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  FUN_005829e0(param_2);
  FUN_00582a90(param_2);
  fVar1 = *param_1;
  fVar2 = param_1[1];
  fVar3 = param_1[2];
  bNormalize3();
  bNormalize3();
  return (float10)local_1c * (float10)(local_2c - fVar2) +
         (float10)local_18 * (float10)(local_28 - fVar3) +
         (float10)(local_30 - fVar1) * (float10)local_20;
}


// ==== 0x582cf0 FUN_00582cf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00582cf0(float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float fVar5;
  int iVar6;
  float *unaff_ESI;
  int unaff_EDI;
  float10 fVar7;
  float local_38;
  int local_34;
  float local_30;
  float local_28;
  float local_24;
  
  fVar7 = (float10)FUN_00582c60(unaff_ESI,0);
  fVar5 = 0.0;
  local_30 = (float)(fVar7 - (float10)param_1);
  local_28 = 0.0;
  local_38 = 1.4013e-45;
  if (1 < *(int *)(unaff_EDI + 4)) {
    local_34 = 0x10;
    do {
      fVar7 = (float10)FUN_00582c60(unaff_ESI,(float)(int)local_38);
      fVar7 = fVar7 - (float10)param_1;
      local_24 = (float)fVar7;
      if ((float10)local_30 * fVar7 < (float10)0.0) {
        pfVar4 = (float *)(*(int *)(unaff_EDI + 0xc) + local_34);
        fVar1 = *unaff_ESI -
                (*pfVar4 * _K_HALF +
                *(float *)(*(int *)(unaff_EDI + 0xc) + -0x10 + local_34) * _K_HALF);
        fVar2 = unaff_ESI[1] - (pfVar4[1] * _K_HALF + pfVar4[-3] * _K_HALF);
        fVar3 = unaff_ESI[2] - (pfVar4[2] * _K_HALF + pfVar4[-2] * _K_HALF);
        fVar1 = SQRT(fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3);
        if ((fVar5 == 0.0) || (fVar1 < local_28)) {
          fVar5 = local_38;
          local_28 = fVar1;
        }
      }
      local_30 = (float)fVar7;
      local_38 = (float)((int)local_38 + 1);
      local_34 = local_34 + 0x10;
    } while ((int)local_38 < *(int *)(unaff_EDI + 4));
    if (fVar5 != 0.0) {
      local_38 = (float)((int)fVar5 + -1);
      iVar6 = 0;
      local_28 = (float)(int)fVar5;
      fVar7 = (float10)FUN_00582c60(unaff_ESI,local_38);
      local_30 = local_38;
      if ((float10)param_2 < ABS(fVar7 - (float10)param_1)) {
        do {
          if (9 < iVar6) break;
          local_38 = (local_28 + local_30) * _K_HALF;
          fVar7 = (float10)FUN_00582c60(unaff_ESI,local_38);
          fVar7 = fVar7 - (float10)param_1;
          iVar6 = iVar6 + 1;
          fVar5 = local_38;
          if ((float10)0.0 <= (float10)local_24 * fVar7) {
            local_24 = (float)fVar7;
            fVar5 = local_30;
            local_28 = local_38;
          }
          local_30 = fVar5;
        } while ((float10)param_2 < ABS(fVar7));
      }
      return (float10)local_38;
    }
  }
  if (0.0 <= local_30) {
    return (float10)-1.0;
  }
  iVar6 = *(int *)(unaff_EDI + 8);
  if (iVar6 != 0) {
    if (iVar6 == 1) {
      return (float10)*(int *)(unaff_EDI + 4) + (float10)_K_ONE;
    }
    if (iVar6 != 2) {
      return (float10)0.0 + (float10)_K_ONE;
    }
  }
  return (float10)(*(int *)(unaff_EDI + 4) + -1) + (float10)_K_ONE;
}


// ==== 0x582f40 FUN_00582f40

int __fastcall FUN_00582f40(int param_1)

{
  return (int)*(char *)(param_1 + 0x4d8);
}


// ==== 0x582f50 FUN_00582f50

undefined4 __fastcall FUN_00582f50(int param_1)

{
  return *(undefined4 *)(param_1 + 0x4d4);
}


// ==== 0x582f60 FUN_00582f60

undefined1 FUN_00582f60(void)

{
  return 1;
}


// ==== 0x582f70 FUN_00582f70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_00582f70(int param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)*(float *)(param_1 + 0x4dc);
  if ((float10)_TeleportSpeedFlip <= fVar1) {
    fVar1 = (float10)_TeleportSpeedFlip;
  }
  return fVar1;
}


// ==== 0x582f90 TrafficAI::ctor

/* [canon] traffic med (C+H) docs/re/traffic.md */

undefined4 * __thiscall TrafficAI__ctor(int param_1,undefined4 *param_2)

{
  short sVar1;
  int *piVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  void *pvStack_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006866fb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0044a330(param_2,param_1);
  *param_2 = &PTR_FUN_006b96b0;
  local_4 = 0;
  param_2[0x139] = 0;
  pvVar3 = _malloc(0x250);
  local_4._0_1_ = 1;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_0045dbb0(pvVar3,param_1);
  }
  param_2[2] = uVar4;
  sVar1 = *(short *)(param_1 + 8);
  param_2[0xfe] = 0;
  param_2[0xfd] = 0x14;
  param_2[0x135] = 0;
  *(undefined1 *)(param_2 + 0x134) = 0;
  *(undefined1 *)((int)param_2 + 0x4d1) = 0;
  *(undefined1 *)((int)param_2 + 0x4d2) = 0;
  *(undefined1 *)(param_2 + 0x136) = 0xff;
  param_2[0x137] = 0x41c4b127;
  param_2[0x138] = 0;
  param_2[0xfc] = (float)(int)sVar1 * 0.2 * -0.033333335;
  param_2[0x139] = 0;
  piVar2 = (int *)param_2[0xf5];
  local_4 = (uint)local_4._1_3_ << 8;
  if (piVar2 != (int *)0x0) {
    iVar5 = (**(code **)(*piVar2 + 4))();
    if (iVar5 == 0) {
      ExceptionList = pvStack_c;
      return param_2;
    }
    (**(code **)*piVar2)(1);
  }
  iVar5 = FUN_00567160();
  if (iVar5 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00455270();
  }
  param_2[0xf5] = uVar4;
  ExceptionList = pvStack_c;
  return param_2;
}


// ==== 0x5830b0 FUN_005830b0

void * __thiscall FUN_005830b0(void *param_1,byte param_2)

{
  FUN_005830d0(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5830d0 FUN_005830d0

void FUN_005830d0(undefined4 *param_1)

{
  char *pcVar1;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006850e8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006b96b0;
  local_4 = 0;
  if (param_1[0x138] != 0) {
    pcVar1 = (char *)(param_1[0x138] + 0x100);
    *pcVar1 = *pcVar1 + -1;
  }
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[2])(1);
  }
  local_4 = 0xffffffff;
  FUN_0044a660();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x583140 FUN_00583140

void __thiscall FUN_00583140(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"TrafficController");
  FUN_00571c20(param_2,param_1 + 0x4d4,1,4,1);
  FUN_00571c20(param_2,param_1 + 0x4d0,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x4d1,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x4d2,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x4d8,1,1,1);
  FUN_00571c20(param_2,param_1 + 0x4dc,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x4e4,4,0xffffffff,0);
  FUN_0059b840(param_2,param_1 + 0x4e0);
  FUN_0044a6f0(param_2);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10 + 0x4c + param_2;
  *(int *)(iVar1 + 0xc) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x583230 FUN_00583230

void FUN_00583230(void)

{
  AIGoal__Create(4);
  return;
}


// ==== 0x583240 FUN_00583240

float10 FUN_00583240(void)

{
  return (float10)4.0;
}


// ==== 0x583250 FUN_00583250

void __fastcall FUN_00583250(undefined4 param_1)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x4d4) = param_1;
  FUN_00457060(in_EAX + 0x3d4);
  return;
}


// ==== 0x583270 FUN_00583270

void __fastcall FUN_00583270(int param_1,int param_2)

{
  char *pcVar1;
  
  if (*(int *)(param_2 + 0x4e0) != 0) {
    pcVar1 = (char *)(*(int *)(param_2 + 0x4e0) + 0x100);
    *pcVar1 = *pcVar1 + -1;
  }
  *(int *)(param_2 + 0x4e0) = param_1;
  if (param_1 != 0) {
    *(char *)(param_1 + 0x100) = *(char *)(param_1 + 0x100) + '\x01';
  }
  return;
}


// ==== 0x5832a0 TrafficCar_Park

/* [canon] traffic high (G+C) docs/re/traffic.md */

void TrafficCar_Park(void)

{
  char *pcVar1;
  int unaff_EDI;
  
  if (*(char *)(unaff_EDI + 0x4d2) == '\0') {
    pcVar1 = (char *)(*(int *)(*(int *)(unaff_EDI + 4) + 0x3c) + 0x1b);
    *pcVar1 = *pcVar1 + '\x01';
    *(undefined1 *)(*(int *)(unaff_EDI + 4) + 0x4d0) = 0;
    Car_SetMode();
    *(undefined1 *)(unaff_EDI + 0x4d2) = 1;
  }
  return;
}


// ==== 0x5832e0 FUN_005832e0

void FUN_005832e0(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EDI;
  
  if (*(char *)(unaff_EDI + 0x4d2) != '\0') {
    piVar1 = *(int **)(*(int *)(unaff_EDI + 4) + 0x3c);
    if (*(char *)((int)piVar1 + 0x1b) != '\0') {
      *(char *)((int)piVar1 + 0x1b) = *(char *)((int)piVar1 + 0x1b) + -1;
    }
    iVar2 = (**(code **)(*piVar1 + 0x50))();
    if (iVar2 != 0) {
      *(undefined1 *)(*(int *)(unaff_EDI + 4) + 0x4d0) = 1;
      Car_SetMode();
      *(undefined1 *)(unaff_EDI + 0x4d2) = 0;
      return;
    }
    *(undefined1 *)(*(int *)(unaff_EDI + 4) + 0x4d0) = 0;
    Car_SetMode();
    *(undefined1 *)(unaff_EDI + 0x4d2) = 0;
  }
  return;
}


// ==== 0x583350 TrafficAI::Update

/* [canon] traffic high (H+G) docs/re/traffic.md */

int __thiscall TrafficAI__Update(int *param_1,float param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  FUN_00583da0();
  param_2 = (float)param_1[0xfc] - param_2;
  param_1[0xfc] = (int)param_2;
  if (*(int *)(*(int *)(param_1[1] + 0x14) + 4) == 3) {
    iVar5 = *(int *)(DAT_007361f8 + 0x18) - *(int *)(DAT_007361f8 + 0x24);
    iVar7 = iVar5 * 2;
    iVar2 = DAT_006f08a4 / iVar7;
    uVar6 = DAT_006f08a4 % iVar7;
    if ((uVar6 & 1) == 0) {
      return iVar2;
    }
    iVar7 = (int)uVar6 >> 1;
    if (iVar5 <= iVar7) {
      return iVar2;
    }
    if (param_1[1] != *(int *)(DAT_007361f8 + 0x28 + (*(int *)(DAT_007361f8 + 0x24) + iVar7) * 4)) {
      return param_1[1];
    }
  }
  else if (param_2 < 0.0 == (param_2 == 0.0)) {
    return CONCAT22((short)((uint)param_1[1] >> 0x10),
                    (ushort)(param_2 < 0.0) << 8 | (ushort)NAN(param_2) << 10 |
                    (ushort)(param_2 == 0.0) << 0xe);
  }
  param_1[0xfc] = (int)(param_2 + 0.2);
  FUN_0044ca70();
  if ((char)param_1[0x104] != '\0') {
    FUN_0044bcb0();
    (**(code **)(*(int *)param_1[2] + 0x38))(0,0,0,1);
    *(undefined1 *)(param_1 + 0x104) = 1;
    iVar7 = FUN_0044c940();
    return iVar7;
  }
  uVar3 = (**(code **)(*param_1 + 0x40))();
  FUN_00458cc0(uVar3);
  cVar1 = FUN_0044cf30(param_1 + 0xb,param_1);
  if (cVar1 == '\0') {
    TrafficCar_Park();
    FUN_0044bcb0();
    (**(code **)(*(int *)param_1[2] + 0x38))(0,0,0,1);
    *(undefined1 *)(param_1 + 0x104) = 1;
    *(undefined1 *)((int)param_1 + 0x4d1) = 1;
    iVar7 = FUN_0044c940();
    return iVar7;
  }
  FUN_00583c80(param_1);
  cVar1 = FUN_005a6ce0(*(undefined4 *)
                        (*(char *)(param_1[0xf8] + 0x388) * 0x38 + 0x18 + param_1[0xf8]));
  if (cVar1 == '\0') {
    cVar1 = FUN_005835f0();
    if (cVar1 != '\0') {
      *(undefined1 *)(param_1 + 0x134) = 1;
    }
  }
  else {
    *(undefined1 *)((int)param_1 + 0x4d1) = 1;
  }
  if (*(char *)((int)param_1 + 0x4d1) != '\0') {
    TrafficCar_Park();
    (**(code **)(*(int *)param_1[2] + 0x38))(0,0,0,1);
    FUN_0044bcb0();
    iVar7 = FUN_0044c940();
    return iVar7;
  }
  if (param_1[0xff] == 0) {
    (**(code **)(*param_1 + 0x60))();
  }
  iVar7 = -1;
  if (param_1[0xfe] == 0) {
    puVar4 = (undefined4 *)(**(code **)(*(int *)param_1[0xff] + 0x18))();
  }
  else {
    FUN_0044f700();
    iVar2 = param_1[0xfe];
    cVar1 = FUN_0044a0e0();
    if (cVar1 == '\0') {
      uVar3 = *(undefined4 *)(iVar2 + 0x1f8);
      iVar7 = *(int *)(iVar2 + 500);
    }
    else {
      uVar3 = 0x14;
    }
    puVar4 = (undefined4 *)(**(code **)(*(int *)param_1[0xff] + 0x14))(param_1 + 0xb,uVar3,iVar7);
    if ((int)puVar4[0x7d] <= iVar7) {
      (**(code **)*puVar4)(1);
      goto LAB_005835d4;
    }
  }
  if (puVar4 != (undefined4 *)0x0) {
    if ((int *)param_1[0xfe] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0xfe] + 0xc))(param_1 + 0xb);
      if ((undefined4 *)param_1[0xfe] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)param_1[0xfe])(1);
      }
    }
    param_1[0xfe] = (int)puVar4;
    iVar7 = puVar4[0x7e];
    if ((((iVar7 == 9) || (iVar7 == 1)) || (iVar7 == 3)) && (*(int *)(param_1[1] + 0x28) == 2)) {
      Car_SetMode();
    }
  }
LAB_005835d4:
  FUN_00583850();
  iVar7 = FUN_0044c940();
  return iVar7;
}


// ==== 0x5835f0 FUN_005835f0

uint __fastcall FUN_005835f0(int *param_1)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  int *unaff_EDI;
  
  if (unaff_EDI != (int *)0x0) {
    in_EAX = (int *)param_1[0xf6];
    if (*in_EAX == 0) {
      iVar2 = -1;
    }
    else {
      iVar2 = (int)*(short *)(*in_EAX + 10);
    }
    if (iVar2 == *unaff_EDI) {
      if (*in_EAX == 0) {
        iVar2 = -1;
      }
      else {
        iVar2 = ((in_EAX[1] - *in_EAX) + -0x27c) / 0x88;
      }
      iVar1 = (**(code **)(*param_1 + 0x40))();
      if (iVar1 == 0) {
        iVar1 = (int)*(short *)((int)unaff_EDI + 6);
        if (iVar1 == -1) {
          if (*unaff_EDI < 0) {
            iVar1 = 0;
          }
          else {
            iVar1 = (&DAT_0077af30)[*unaff_EDI];
          }
          iVar1 = *(short *)(iVar1 + 0x10) + -2;
        }
        return CONCAT31((int3)((uint)iVar1 >> 8),iVar1 < iVar2);
      }
      iVar1 = (int)(short)unaff_EDI[1];
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      return CONCAT31((int3)((uint)iVar1 >> 8),iVar2 < iVar1);
    }
  }
  return (uint)in_EAX & 0xffffff00;
}


// ==== 0x583690 FUN_00583690

void __thiscall
FUN_00583690(int param_1,undefined4 *param_2,undefined4 *param_3,undefined1 *param_4)

{
  char cVar1;
  
  if (*(undefined4 **)(param_1 + 0x4e0) != (undefined4 *)0x0) {
    *param_2 = **(undefined4 **)(param_1 + 0x4e0);
    *param_3 = **(undefined4 **)(param_1 + 0x4e0);
    *param_4 = 1;
    return;
  }
  cVar1 = (**(code **)(**(int **)(param_1 + 0x3fc) + 0xc))();
  if (cVar1 != '\0') {
    *param_2 = 100;
    *param_3 = 0x77;
    *param_4 = 1;
    return;
  }
  *param_2 = 0;
  *param_3 = 99;
  *param_4 = 1;
  return;
}


// ==== 0x583700 TrafficAI::Reset

/* [canon] traffic med (H) docs/re/traffic.md */

void __fastcall TrafficAI__Reset(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  
  *(undefined1 *)(param_1 + 0x410) = 0;
  iVar2 = 0xc;
  do {
    *(uint *)(iVar2 + param_1) = *(uint *)(iVar2 + param_1) & 0xfffffffe;
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x2c);
  FUN_005a5340();
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x1dc) = 0;
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x1e4) = 0;
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x1e0) = 0;
  FUN_005832e0();
  *(undefined1 *)(param_1 + 0x4d0) = 0;
  *(undefined1 *)(param_1 + 0x4d1) = 0;
  if (*(undefined4 **)(param_1 + 0x3f8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x3f8))(1);
  }
  puVar3 = (undefined4 *)FUN_00567160();
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_0044e2b0(8,0,0xbf800000);
    *puVar3 = &PTR_FUN_006c920c;
    puVar3[0x80] = 0;
    puVar3[0x80] = 0;
  }
  *(undefined4 **)(param_1 + 0x3f8) = puVar3;
  cVar1 = FUN_0044cf30(param_1 + 0x2c,param_1);
  if (cVar1 != '\0') {
    FUN_00583850();
    FUN_0044c940();
    return;
  }
  if ((*(char *)(param_1 + 0x410) == '\0') &&
     (puVar3 = DAT_0077af20, (undefined4 **)DAT_0077af20 != &DAT_0077af20)) {
    do {
      if (puVar3 == (undefined4 *)0x0) break;
      puVar3 = (undefined4 *)*puVar3;
    } while ((undefined4 **)puVar3 != &DAT_0077af20);
  }
  FUN_0044bcb0();
  iVar2 = 1;
  (**(code **)(**(int **)(param_1 + 8) + 0x38))(0,0,0);
  *(undefined1 *)(iVar2 + 0x410) = 1;
  FUN_0044c940();
  return;
}


// ==== 0x583850 FUN_00583850

void FUN_00583850(void)

{
  int in_EAX;
  undefined4 unaff_EDI;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  (**(code **)(**(int **)(in_EAX + 0x3f8) + 8))(in_EAX + 0x2c);
  if (DAT_006fbf18 == *(short *)(*(int *)(in_EAX + 4) + 10)) {
    FUN_00455c50(&DAT_0077a4b0,*(int *)(in_EAX + 0x3f8) + 0x20);
  }
  uStack_8 = 0;
  uStack_c = 0;
  FUN_00583910(&uStack_c,&stack0xfffffff0);
  (**(code **)(**(int **)(in_EAX + 8) + 0x3c))(*(int *)(in_EAX + 0x3f8) + 0x20);
  (**(code **)(**(int **)(in_EAX + 8) + 0x38))
            (uStack_c,0,unaff_EDI,*(undefined1 *)(*(int *)(in_EAX + 0x3f8) + 0x1f1));
  FUN_00458f10(0,0);
  return;
}


// ==== 0x583910 FUN_00583910

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00583910(undefined4 *param_1,undefined4 *param_2)

{
  float fVar1;
  undefined4 *puVar2;
  int *unaff_ESI;
  float *unaff_EDI;
  float10 fVar3;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  puVar2 = param_2;
  *unaff_EDI = 0.0;
  *param_1 = 0;
  *param_2 = 0;
  fVar3 = (float10)(**(code **)(*unaff_ESI + 0x5c))();
  param_2 = (undefined4 *)(float)fVar3;
  fStack_c = *(float *)(unaff_ESI[1] + 0x3d4) * 1.3;
  if (fStack_c <= 20.0) {
    fStack_c = 20.0;
  }
  fStack_8 = 99999.0;
  fVar3 = (float10)FUN_005a6bc0(unaff_ESI[0xf9],fStack_c,&fStack_8);
  if (fVar3 < (float10)-0.1) {
    Curve_Evaluate(&fStack_4,fStack_8);
    param_2 = (undefined4 *)((_K_ONE - fStack_4) * ((float)param_2 - 10.0) + 10.0);
  }
  fVar1 = *(float *)(*(char *)(unaff_ESI[0xf8] + 0x388) * 0x38 + 0x18 + unaff_ESI[0xf8]);
  fStack_8 = *(float *)(unaff_ESI[1] + 0x3d4) * 1.3;
  if (fStack_8 < 8.0) {
    fStack_8 = 8.0;
  }
  fVar3 = (float10)FUN_005a6b00(fVar1);
  fStack_4 = (float)fVar3;
  fVar3 = (float10)FUN_005a6b00(fStack_8 + fVar1);
  if ((float)param_2 < fStack_4) {
    fStack_4 = (float)param_2;
  }
  if ((float)fVar3 <= fStack_4) {
    fStack_4 = (float)fVar3;
  }
  if (*(char *)((int)unaff_ESI + 0x4d1) != '\0') {
    fStack_4 = 0.0;
  }
  if (*(char *)(unaff_ESI[0xfe] + 0x1f0) == '\0') {
    *unaff_EDI = *(float *)(unaff_ESI[0xfe] + 0x1e4);
    *param_1 = *(undefined4 *)(unaff_ESI[0xfe] + 0x1e8);
    *puVar2 = *(undefined4 *)(unaff_ESI[0xfe] + 0x1ec);
  }
  else {
    *unaff_EDI = fStack_4;
    *param_1 = 0;
    *puVar2 = 0;
  }
  if (fStack_4 <= *unaff_EDI) {
    *unaff_EDI = fStack_4;
    return;
  }
  *unaff_EDI = *unaff_EDI;
  return;
}


// ==== 0x583b20 FUN_00583b20

void __thiscall FUN_00583b20(int *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    if (param_1[0xee] == 0) {
      *(undefined1 *)(param_1 + 0xfb) = 0xff;
    }
    else {
      *(undefined1 *)(param_1 + 0xfb) = *(undefined1 *)(param_1[0xee] + 10);
    }
    if (param_4 == -1) {
      uVar1 = (**(code **)(*param_1 + 0x40))(0xff,0xff);
      param_4 = GetNearestTrafficLane(param_1[1],uVar1);
      if (param_4 < 1) {
        param_4 = 0;
      }
    }
    param_1[0xee] = param_2;
    param_1[0xef] = param_3;
    param_1[0xf0] = param_4;
  }
  return;
}


// ==== 0x583bb0 FUN_00583bb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00583bb0(int param_1)

{
  char cVar1;
  float10 fVar2;
  ushort in_AX;
  ushort uVar3;
  float10 fVar4;
  
  cVar1 = *(char *)(param_1 + 0xc);
  uVar3 = in_AX & 0xff00;
  if (cVar1 != '\x02') {
    if (((cVar1 != '\x05') && (cVar1 != '\a')) && (cVar1 == '\x04')) {
      fVar4 = (float10)Random_NextFloat(0x3f800000);
      fVar2 = (float10)_K_HALF;
      uVar3 = (ushort)(fVar4 < fVar2) << 8 | (ushort)(NAN(fVar4) || NAN(fVar2)) << 10 |
              (ushort)(fVar4 == fVar2) << 0xe;
      if (fVar4 < fVar2) goto LAB_00583bbe;
    }
    return uVar3;
  }
LAB_00583bbe:
  return CONCAT11((char)(uVar3 >> 8),1);
}


// ==== 0x583c00 FUN_00583c00

void __fastcall FUN_00583c00(int param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(**(int **)(param_1 + 0x3fc) + 0xc))();
  if (cVar1 != '\0') {
    FUN_0044bcb0();
    (**(code **)(**(int **)(param_1 + 8) + 0x38))(0,0,0,1);
    *(undefined1 *)(param_1 + 0x410) = 1;
  }
  return;
}


// ==== 0x583c30 FUN_00583c30

undefined4 __fastcall FUN_00583c30(int param_1)

{
  if (2.0 < (float)(DAT_0073ad34 - *(int *)(param_1 + 0x408)) * 0.00025) {
    return 1;
  }
  return 0;
}


// ==== 0x583c70 FUN_00583c70

float10 FUN_00583c70(void)

{
  return (float10)5.0;
}


// ==== 0x583c80 FUN_00583c80

void FUN_00583c80(float param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float10 fVar5;
  
  iVar2 = *(int *)((int)param_1 + 0x3e4);
  if ((((*(int *)(iVar2 + 4) != 0) &&
       (iVar3 = *(int *)((int)param_1 + 0x3e0), *(int *)(iVar3 + 4) != 0)) &&
      (*(int *)(iVar2 + 0xb8) != -1)) && (*(int *)(iVar2 + 8 + *(int *)(iVar2 + 0xb8) * 4) != 0)) {
    Node_GetIntersection();
    fVar5 = (float10)FUN_005a6e10(iVar2,*(char *)(iVar3 + 0x388) * 0x38 + 8 + iVar3);
    fVar4 = *(float *)(*(int *)((int)param_1 + 4) + 0x3d0);
    fVar1 = (float)fVar5;
    if (fVar1 <= 0.0) {
      param_1 = 0.0;
    }
    else if (fVar4 <= 0.001) {
      param_1 = 99999.0;
    }
    else {
      fVar5 = (float10)FUN_00401c40(fVar1 / fVar4,0);
      param_1 = (float)fVar5;
    }
    FUN_005aadf0(fVar1,param_1);
  }
  return;
}


// ==== 0x583d70 FUN_00583d70

void __fastcall FUN_00583d70(int param_1)

{
  *(undefined4 *)(param_1 + 0x4e4) = DAT_0073ad34;
  return;
}


// ==== 0x583d80 FUN_00583d80

float10 __fastcall FUN_00583d80(int param_1)

{
  return (float10)(DAT_0073ad34 - *(int *)(param_1 + 0x4e4)) * (float10)0.00025;
}


// ==== 0x583da0 FUN_00583da0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00583da0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  float10 fVar4;
  float local_8;
  
  iVar1 = *(int *)(*(int *)(unaff_ESI + 4) + 0x3c);
  iVar3 = 0;
  local_8 = -1.0;
  if ('\0' < *(char *)(iVar1 + 0x1c)) {
    do {
      iVar2 = FUN_00468820(iVar3);
      FUN_0044ecd0();
      if (local_8 <= *(float *)(iVar2 + 0x60)) {
        local_8 = *(float *)(iVar2 + 0x60);
      }
      if (30.0 < *(float *)(iVar2 + 0x60)) {
        FUN_0044bcb0();
        (**(code **)(**(int **)(unaff_ESI + 8) + 0x38))(0,0,0,1);
        *(undefined1 *)(unaff_ESI + 0x410) = 1;
        break;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(char *)(iVar1 + 0x1c));
    if ((*(float *)(*(int *)(unaff_ESI + 4) + 0x3d4) < _K_ONE) &&
       (fVar4 = (float10)(**(code **)(**(int **)(*(int *)(unaff_ESI + 4) + 0x30) + 0x70))(),
       (float10)_K_ONE < fVar4)) {
      FUN_0044bcb0();
      (**(code **)(**(int **)(unaff_ESI + 8) + 0x38))(0,0,0,1);
      *(undefined1 *)(unaff_ESI + 0x410) = 1;
    }
  }
  return;
}


// ==== 0x583e80 FUN_00583e80

void FUN_00583e80(void)

{
  Car_SetMode();
  return;
}


// ==== 0x583ea0 FUN_00583ea0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00583ea0(float param_1)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int *unaff_ESI;
  float10 fVar5;
  
  iVar2 = *unaff_ESI;
  fVar3 = (param_1 - (float)unaff_ESI[1]) * (float)unaff_ESI[3];
  iVar4 = _ftol_nocw();
  if (iVar4 < 0) {
    return (float10)*(float *)unaff_ESI[4];
  }
  if (iVar2 + -1 <= iVar4) {
    return (float10)*(float *)(unaff_ESI[4] + -4 + iVar2 * 4);
  }
  fVar5 = (float10)FUN_004387e0(fVar3);
  if ((float10)fVar3 < fVar5) {
    fVar5 = fVar5 - (float10)_K_ONE;
  }
  pfVar1 = (float *)(unaff_ESI[4] + iVar4 * 4);
  return ((float10)fVar3 - fVar5) * (float10)pfVar1[1] +
         ((float10)_K_ONE - ((float10)fVar3 - fVar5)) * (float10)*pfVar1;
}


// ==== 0x583f20 LinearTable::Lookup11

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] rivals V (Ghidra+capstone) docs/re/rivals.md */

float10 LinearTable__Lookup11(int *param_1,float param_2)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  
  iVar1 = param_1[1];
  if (1 < iVar1) {
    pfVar2 = (float *)*param_1;
    if (param_2 < *pfVar2 != (param_2 == *pfVar2)) {
      return (float10)pfVar2[1];
    }
    if (pfVar2[iVar1 * 2 + -2] <= param_2) {
      return (float10)pfVar2[iVar1 * 2 + -1];
    }
    iVar3 = 0;
    pfVar4 = pfVar2;
    if (0 < iVar1 + -1) {
      do {
        if ((*pfVar4 <= param_2) && (param_2 < pfVar4[2])) {
          pfVar4 = pfVar2 + iVar3 * 2 + 1;
          if (ABS((float10)pfVar2[iVar3 * 2 + 2] - (float10)pfVar2[iVar3 * 2]) <= (float10)1e-06) {
            return ((float10)pfVar2[iVar3 * 2 + 3] - (float10)*pfVar4) * (float10)_K_HALF +
                   (float10)*pfVar4;
          }
          return (((float10)param_2 - (float10)pfVar2[iVar3 * 2]) /
                 ((float10)pfVar2[iVar3 * 2 + 2] - (float10)pfVar2[iVar3 * 2])) *
                 ((float10)pfVar2[iVar3 * 2 + 3] - (float10)*pfVar4) + (float10)*pfVar4;
        }
        iVar3 = iVar3 + 1;
        pfVar4 = pfVar4 + 2;
      } while (iVar3 < iVar1 + -1);
    }
  }
  return (float10)*(float *)(*param_1 + 4);
}


// ==== 0x583ff0 FUN_00583ff0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00583ff0(undefined4 *param_1,float param_2)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  
  iVar1 = param_1[1];
  if (1 < iVar1) {
    pfVar2 = (float *)*param_1;
    if (param_2 < pfVar2[1] != (param_2 == pfVar2[1])) {
      return (float10)*pfVar2;
    }
    if (pfVar2[iVar1 * 2 + -1] <= param_2) {
      return (float10)pfVar2[iVar1 * 2 + -2];
    }
    iVar3 = 0;
    if (0 < iVar1 + -1) {
      pfVar4 = pfVar2 + 3;
      do {
        if ((pfVar4[-2] <= param_2) && (param_2 < *pfVar4)) {
          if ((float10)1e-06 < ABS((float10)pfVar2[iVar3 * 2 + 3] - (float10)pfVar2[iVar3 * 2 + 1]))
          {
            return (((float10)param_2 - (float10)pfVar2[iVar3 * 2 + 1]) /
                   ((float10)pfVar2[iVar3 * 2 + 3] - (float10)pfVar2[iVar3 * 2 + 1])) *
                   ((float10)pfVar2[iVar3 * 2 + 2] - (float10)pfVar2[iVar3 * 2]) +
                   (float10)pfVar2[iVar3 * 2];
          }
          return ((float10)pfVar2[iVar3 * 2 + 2] - (float10)pfVar2[iVar3 * 2]) * (float10)_K_HALF +
                 (float10)pfVar2[iVar3 * 2];
        }
        iVar3 = iVar3 + 1;
        pfVar4 = pfVar4 + 2;
      } while (iVar3 < iVar1 + -1);
    }
  }
  return (float10)*(float *)*param_1;
}


// ==== 0x5840c0 FUN_005840c0

void FUN_005840c0(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  int unaff_ESI;
  int *unaff_EDI;
  
  FUN_00571ea0(0,"Average");
  FUN_00571c20(unaff_ESI,unaff_EDI + 1,1,1,0);
  FUN_00571c20(unaff_ESI,(byte *)((int)unaff_EDI + 5),1,1,0);
  FUN_00571c20(unaff_ESI,(int)unaff_EDI + 6,1,1,0);
  FUN_00571c20(unaff_ESI,(int)unaff_EDI + 7,1,1,0);
  FUN_00571c20(unaff_ESI,param_1,
               (uint)*(byte *)((int)unaff_EDI + 5) * (uint)*(byte *)(unaff_EDI + 1),0xffffffff,0);
  if ((*(char *)(unaff_ESI + 0x3d) != '\0') || (*(char *)(unaff_ESI + 0x3c) != '\0')) {
    (**(code **)(*unaff_EDI + 4))();
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


// ==== 0x584180 FUN_00584180

void FUN_00584180(int param_1)

{
  void *pvVar1;
  undefined4 *unaff_ESI;
  undefined4 *puVar2;
  
  *(undefined1 *)((int)unaff_ESI + 6) = 0;
  *(undefined1 *)((int)unaff_ESI + 7) = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  *(undefined1 *)(unaff_ESI + 1) = 4;
  *(char *)((int)unaff_ESI + 5) = (char)param_1;
  *unaff_ESI = &PTR_FUN_006b9694;
  unaff_ESI[4] = unaff_ESI + 5;
  if (5 < param_1) {
    pvVar1 = _malloc(param_1 * 4);
    unaff_ESI[4] = pvVar1;
  }
  puVar2 = (undefined4 *)unaff_ESI[4];
  for (; param_1 != 0; param_1 = param_1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== 0x5841d0 FUN_005841d0

void * __thiscall FUN_005841d0(void *param_1,byte param_2)

{
  FUN_005841f0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5841f0 FUN_005841f0

void FUN_005841f0(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_FUN_006b9694;
  if ((undefined4 *)unaff_ESI[4] != unaff_ESI + 5) {
    _free((undefined4 *)unaff_ESI[4]);
  }
  *unaff_ESI = &PTR_FUN_006c7d78;
  return;
}


// ==== 0x584210 FUN_00584210

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00584210(int param_1)

{
  float fVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  float *pfVar5;
  
  bVar2 = *(byte *)(param_1 + 6);
  iVar4 = 0;
  *(float *)(param_1 + 8) = *(float *)(param_1 + 8) * 0.0;
  if (bVar2 != 0) {
    pfVar5 = *(float **)(param_1 + 0x10);
    do {
      fVar1 = *pfVar5;
      iVar4 = iVar4 + 1;
      pfVar5 = pfVar5 + 1;
      *(float *)(param_1 + 8) = fVar1 + *(float *)(param_1 + 8);
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 6));
  }
  bVar3 = 1;
  if (bVar2 != 0) {
    bVar3 = bVar2;
  }
  *(float *)(param_1 + 0xc) = (_K_ONE / (float)bVar3) * *(float *)(param_1 + 8);
  return;
}


// ==== 0x584270 FUN_00584270

void FUN_00584270(float param_1)

{
  float *pfVar1;
  float fVar2;
  int in_EAX;
  byte bVar3;
  
  if (*(byte *)(in_EAX + 6) < *(byte *)(in_EAX + 5)) {
    *(byte *)(in_EAX + 6) = *(byte *)(in_EAX + 6) + 1;
  }
  fVar2 = param_1 + *(float *)(in_EAX + 8);
  pfVar1 = (float *)(*(int *)(in_EAX + 0x10) + (uint)*(byte *)(in_EAX + 7) * 4);
  *(float *)(in_EAX + 8) = fVar2;
  *(float *)(in_EAX + 8) = fVar2 - *pfVar1;
  *pfVar1 = param_1;
  bVar3 = *(char *)(in_EAX + 7) + 1;
  *(byte *)(in_EAX + 7) = bVar3;
  *(float *)(in_EAX + 0xc) = *(float *)(in_EAX + 8) / (float)*(byte *)(in_EAX + 6);
  if (*(byte *)(in_EAX + 5) <= bVar3) {
    *(undefined1 *)(in_EAX + 7) = 0;
  }
  return;
}


// ==== 0x5842d0 FUN_005842d0

void FUN_005842d0(float param_1)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = 0;
  if (*(char *)(in_EAX + 5) != '\0') {
    do {
      *(float *)(*(int *)(in_EAX + 0x10) + iVar1 * 4) = param_1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)(uint)*(byte *)(in_EAX + 5));
  }
  *(undefined1 *)(in_EAX + 6) = 0;
  *(float *)(in_EAX + 8) = (float)*(byte *)(in_EAX + 5) * param_1;
  return;
}


// ==== 0x584310 FUN_00584310

void FUN_00584310(float param_1)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = 0;
  if (*(char *)(in_EAX + 5) != '\0') {
    do {
      *(float *)(*(int *)(in_EAX + 0x10) + iVar1 * 4) = param_1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)(uint)*(byte *)(in_EAX + 5));
  }
  *(byte *)(in_EAX + 6) = *(byte *)(in_EAX + 5);
  *(float *)(in_EAX + 0xc) = param_1;
  *(float *)(in_EAX + 8) = (float)*(byte *)(in_EAX + 5) * param_1;
  return;
}


// ==== 0x584360 FUN_00584360

void FUN_00584360(undefined4 param_1)

{
  undefined4 *in_EAX;
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = _ftol_nocw();
  FUN_00584180(uVar1);
  in_EAX[10] = param_1;
  *in_EAX = &PTR_FUN_006b968c;
  in_EAX[0xb] = 0;
  puVar2 = _malloc((uint)*(byte *)((int)in_EAX + 5) << 2);
  in_EAX[0xc] = puVar2;
  for (uVar3 = (uint)*(byte *)((int)in_EAX + 5); uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  return;
}


// ==== 0x5843d0 FUN_005843d0

void * __thiscall FUN_005843d0(void *param_1,byte param_2)

{
  FUN_005843f0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5843f0 FUN_005843f0

void FUN_005843f0(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_FUN_006b968c;
  _free((void *)unaff_ESI[0xc]);
  *unaff_ESI = &PTR_FUN_006b9694;
  if ((undefined4 *)unaff_ESI[4] != unaff_ESI + 5) {
    _free((undefined4 *)unaff_ESI[4]);
  }
  *unaff_ESI = &PTR_FUN_006c7d78;
  return;
}


// ==== 0x584430 FUN_00584430

void __fastcall FUN_00584430(int param_1)

{
  int in_EAX;
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"Average");
  FUN_00571c20(in_EAX,param_1 + 0x2c,4,4,0);
  FUN_00571c20(in_EAX,*(undefined4 *)(param_1 + 0x30),(uint)*(byte *)(param_1 + 5) << 2,0xffffffff,0
              );
  iVar1 = *(char *)(in_EAX + 0x40) * 0x10;
  *(int *)(iVar1 + in_EAX + 0x58) = *(int *)(in_EAX + 0x150) - *(int *)(iVar1 + 0x58 + in_EAX);
  cVar2 = *(char *)(in_EAX + 0x40) + -1;
  *(char *)(in_EAX + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(in_EAX + 0x44)) {
    *(undefined4 *)(in_EAX + 0x44) = 0xffffffff;
  }
  FUN_005840c0(*(undefined4 *)(param_1 + 0x10));
  return;
}


// ==== 0x5844b0 FUN_005844b0

void FUN_005844b0(float param_1)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = 0;
  if (*(char *)(in_EAX + 5) != '\0') {
    do {
      *(float *)(*(int *)(in_EAX + 0x10) + iVar1 * 4) = param_1;
      *(undefined4 *)(*(int *)(in_EAX + 0x30) + iVar1 * 4) = 0;
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)(uint)*(byte *)(in_EAX + 5));
  }
  *(undefined1 *)(in_EAX + 6) = 0;
  *(undefined4 *)(in_EAX + 0x2c) = 0;
  *(undefined1 *)(in_EAX + 7) = 0;
  *(float *)(in_EAX + 8) = (float)*(byte *)(in_EAX + 5) * param_1;
  return;
}


// ==== 0x584500 FUN_00584500

void __thiscall FUN_00584500(int param_1,float param_2,float param_3)

{
  float fVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  
  if (*(byte *)(param_1 + 6) < *(byte *)(param_1 + 5)) {
    *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) + 1;
  }
  fVar1 = param_2 + *(float *)(param_1 + 8);
  iVar2 = (uint)*(byte *)(param_1 + 7) * 4;
  *(float *)(param_1 + 8) = fVar1;
  uVar5 = 0;
  *(float *)(param_1 + 8) = fVar1 - *(float *)(iVar2 + *(int *)(param_1 + 0x10));
  *(float *)(iVar2 + *(int *)(param_1 + 0x30)) = param_3;
  *(float *)(*(int *)(param_1 + 0x10) + (uint)*(byte *)(param_1 + 7) * 4) = param_2;
  if (*(float *)(param_1 + 0x28) <
      param_3 - *(float *)(*(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x2c) * 4)) {
    uVar4 = (uint)*(byte *)(param_1 + 5);
    uVar5 = 0;
    do {
      if ((int)uVar4 <= (int)uVar5) break;
      iVar2 = *(int *)(param_1 + 0x2c) * 4;
      if (0.0 < *(float *)(iVar2 + *(int *)(param_1 + 0x30))) {
        *(float *)(param_1 + 8) =
             *(float *)(param_1 + 8) - *(float *)(*(int *)(param_1 + 0x10) + iVar2);
        *(undefined4 *)(*(int *)(param_1 + 0x10) + iVar2) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x2c) * 4) = 0;
        iVar2 = *(int *)(param_1 + 0x2c) + 1;
        *(int *)(param_1 + 0x2c) = iVar2;
        uVar4 = (uint)*(byte *)(param_1 + 5);
        if ((int)uVar4 <= iVar2) {
          *(undefined4 *)(param_1 + 0x2c) = 0;
        }
        *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + -1;
      }
      uVar5 = uVar5 + 1;
    } while (*(float *)(param_1 + 0x28) <
             param_3 - *(float *)(*(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x2c) * 4));
  }
  if (uVar5 != *(byte *)(param_1 + 5)) {
    bVar3 = *(char *)(param_1 + 7) + 1;
    *(byte *)(param_1 + 7) = bVar3;
    *(float *)(param_1 + 0xc) = *(float *)(param_1 + 8) / (float)*(byte *)(param_1 + 6);
    if (*(byte *)(param_1 + 5) <= bVar3) {
      *(undefined1 *)(param_1 + 7) = 0;
    }
    return;
  }
  FUN_005844b0(0);
  return;
}


// ==== 0x584610 FUN_00584610

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00584610(float param_1,float param_2,char param_3,char param_4)

{
  float fVar1;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x80) = *(undefined4 *)(unaff_ESI + 0x7c);
  fVar1 = param_1 - *(float *)(unaff_ESI + 0x80);
  *(float *)(unaff_ESI + 0x7c) = param_1;
  if (param_4 == '\0') {
    _param_4 = (_K_HALF * fVar1 + *(float *)(unaff_ESI + 0x80)) * param_2;
  }
  else {
    _param_4 = 0.0;
  }
  if (param_3 == '\0') {
    _param_3 = fVar1 / param_2;
  }
  else {
    _param_3 = 0.0;
  }
  FUN_00584270(param_2);
  FUN_00584270(_param_4);
  FUN_00584270(_param_3);
  return;
}


// ==== 0x5846a0 FUN_005846a0

void __fastcall FUN_005846a0(int param_1)

{
  int iVar1;
  int in_EAX;
  char cVar2;
  
  FUN_00571ea0(0,"PidError");
  FUN_005840c0(*(undefined4 *)(param_1 + 0x10));
  FUN_005840c0(*(undefined4 *)(param_1 + 0x38));
  FUN_005840c0(*(undefined4 *)(param_1 + 0x60));
  FUN_00571c20(in_EAX,param_1 + 0x78,4,0xffffffff,0);
  FUN_00571c20(in_EAX,param_1 + 0x7c,4,0xffffffff,0);
  FUN_00571c20(in_EAX,param_1 + 0x80,4,0xffffffff,0);
  iVar1 = *(char *)(in_EAX + 0x40) * 0x10 + 0x4c + in_EAX;
  *(int *)(iVar1 + 0xc) = *(int *)(in_EAX + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(in_EAX + 0x40) + -1;
  *(char *)(in_EAX + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(in_EAX + 0x44)) {
    *(undefined4 *)(in_EAX + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x584740 FUN_00584740

undefined4 FUN_00584740(void)

{
  return 0x20;
}


// ==== 0x584750 FUN_00584750

int __fastcall FUN_00584750(int param_1)

{
  return param_1 + 0x20;
}


// ==== 0x584760 FUN_00584760

void FUN_00584760(void)

{
  FUN_005847b0();
  return;
}


// ==== 0x584780 FUN_00584780

void FUN_00584780(void)

{
  FUN_005847b0();
  return;
}


// ==== 0x5847a0 FUN_005847a0

undefined * FUN_005847a0(void)

{
  return &DAT_006f08ac;
}


// ==== 0x5847b0 FUN_005847b0

void FUN_005847b0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  uVar1 = unaff_EDI[1];
  uVar2 = unaff_EDI[2];
  *unaff_ESI = *unaff_EDI;
  unaff_ESI[1] = uVar1;
  unaff_ESI[2] = uVar2;
  bMatrixCopy_b();
  uVar1 = unaff_EDI[0x15];
  uVar2 = unaff_EDI[0x16];
  unaff_ESI[0x14] = unaff_EDI[0x14];
  unaff_ESI[0x15] = uVar1;
  unaff_ESI[0x16] = uVar2;
  uVar1 = unaff_EDI[0x19];
  uVar2 = unaff_EDI[0x1a];
  unaff_ESI[0x18] = unaff_EDI[0x18];
  unaff_ESI[0x19] = uVar1;
  unaff_ESI[0x1a] = uVar2;
  unaff_ESI[0x1c] = unaff_EDI[0x1c];
  return;
}


// ==== 0x584800 FUN_00584800

undefined4 * __fastcall FUN_00584800(undefined4 *param_1)

{
  char *pcVar1;
  char cVar2;
  undefined4 in_EAX;
  char *pcVar3;
  
  param_1[5] = in_EAX;
  *param_1 = &PTR_FUN_006b9654;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0xc] = 0x3f800000;
  param_1[0x11] = 0x3f800000;
  param_1[0x16] = 0x3f800000;
  param_1[0x1b] = 0x3f800000;
  param_1[0x7a] = 0x3f800000;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x24] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x78] = 0;
  param_1[0x79] = 0;
  param_1[0x4f] = 0;
  param_1[0x4c] = 1;
  param_1[0x4d] = 1;
  param_1[0x4e] = 0;
  param_1[0x50] = 1;
  RigidBody__SetMassInertia();
  pcVar1 = (char *)(param_1 + 3);
  *pcVar1 = 'R';
  pcVar3 = pcVar1;
  do {
    cVar2 = pcVar3[(int)("Rigid" + (1 - (int)pcVar1))];
    pcVar3 = pcVar3 + 1;
    *pcVar3 = cVar2;
  } while (cVar2 != '\0');
  return param_1;
}


// ==== 0x584920 FUN_00584920

undefined4 * __thiscall FUN_00584920(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_00584950();
  iVar2 = DAT_00735f6c;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00735f6c + 0x18);
    *param_1 = *(undefined4 *)(DAT_00735f6c + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x584950 FUN_00584950

void FUN_00584950(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006c8584;
  return;
}


// ==== 0x584960 FUN_00584960

void FUN_00584960(void)

{
  int iVar1;
  char cVar2;
  int *unaff_ESI;
  int unaff_EDI;
  char local_1;
  
  FUN_00571ea0(0,"RigidBody");
  FUN_00571c20(unaff_EDI,unaff_ESI + 8,0xc,0xffffffff,0);
  FUN_00571c20(unaff_EDI,unaff_ESI + 0xc,0xc,0xffffffff,0);
  FUN_00571c20(unaff_EDI,unaff_ESI + 0x10,0xc,0xffffffff,0);
  FUN_00571c20(unaff_EDI,unaff_ESI + 0x14,0xc,0xffffffff,0);
  if (*(char *)(unaff_EDI + 0x3c) != '\0' || *(char *)(unaff_EDI + 0x3d) != '\0') {
    unaff_ESI[0xf] = 0;
    unaff_ESI[0x13] = 0;
    unaff_ESI[0x17] = 0;
    unaff_ESI[0x18] = 0;
    unaff_ESI[0x19] = 0;
    unaff_ESI[0x1a] = 0;
    unaff_ESI[0x1b] = 0x3f800000;
    unaff_ESI[0x4c] = 1;
    unaff_ESI[0x4d] = 1;
    unaff_ESI[0x4e] = 0;
  }
  FUN_00571c20(unaff_EDI,unaff_ESI + 0x24,4,0xffffffff,0);
  if (((((float)unaff_ESI[0x1c] != 0.0) || ((float)unaff_ESI[0x1d] != 0.0)) ||
      ((float)unaff_ESI[0x1e] != 0.0)) ||
     ((((float)unaff_ESI[0x20] != 0.0 || ((float)unaff_ESI[0x21] != 0.0)) ||
      (local_1 = '\x01', (float)unaff_ESI[0x22] != 0.0)))) {
    local_1 = '\0';
  }
  FUN_00571c20(unaff_EDI,&local_1,1,1,0);
  if (local_1 == '\0') {
    FUN_00571c20(unaff_EDI,unaff_ESI + 0x1c,0xc,0xffffffff,0);
    FUN_00571c20(unaff_EDI,unaff_ESI + 0x20,0xc,0xffffffff,0);
  }
  else if (*(char *)(unaff_EDI + 0x3c) != '\0' || *(char *)(unaff_EDI + 0x3d) != '\0') {
    unaff_ESI[0x1c] = 0;
    unaff_ESI[0x1d] = 0;
    unaff_ESI[0x1e] = 0;
    unaff_ESI[0x20] = 0;
    unaff_ESI[0x21] = 0;
    unaff_ESI[0x22] = 0;
  }
  if (*(char *)(unaff_EDI + 0x3c) != '\0' || *(char *)(unaff_EDI + 0x3d) != '\0') {
    (**(code **)(*unaff_ESI + 0x1c))();
  }
  iVar1 = *(char *)(unaff_EDI + 0x40) * 0x10;
  *(int *)(iVar1 + unaff_EDI + 0x58) =
       *(int *)(unaff_EDI + 0x150) - *(int *)(iVar1 + 0x58 + unaff_EDI);
  cVar2 = *(char *)(unaff_EDI + 0x40) + -1;
  *(char *)(unaff_EDI + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(unaff_EDI + 0x44)) {
    *(undefined4 *)(unaff_EDI + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x584b10 RigidBody::SetMassInertia

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] props high (hopper+ghidra) docs/re/props.md */

void RigidBody__SetMassInertia(void)

{
  float fVar1;
  int unaff_ESI;
  
  fVar1 = **(float **)(unaff_ESI + 0x14);
  *(float *)(unaff_ESI + 0x144) = fVar1;
  *(float *)(unaff_ESI + 0x148) = _K_ONE / fVar1;
  FUN_00565060();
  bMatrixCopy_b();
  FUN_00565060();
  return;
}


// ==== 0x584b80 FUN_00584b80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00584b80(undefined4 param_1,int param_2,float *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  float fVar5;
  undefined4 *in_EAX;
  float local_110 [6];
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  float local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined1 local_d0 [52];
  undefined1 auStack_9c [52];
  undefined1 auStack_68 [12];
  undefined1 auStack_5c [88];
  
  uVar1 = in_EAX[2];
  uVar4 = *in_EAX;
  *(undefined4 *)(param_2 + 0x24) = in_EAX[1];
  *(undefined4 *)(param_2 + 0x20) = uVar4;
  *(undefined4 *)(param_2 + 0x28) = uVar1;
  bMatrixCopy_b();
  fVar2 = *(float *)(param_2 + 0x144);
  fVar3 = param_3[1];
  fVar5 = param_3[2];
  local_110[1] = 0.0;
  *(float *)(param_2 + 0x70) = fVar2 * *param_3;
  local_110[2] = 0.0;
  local_110[3] = 0.0;
  local_110[4] = 0.0;
  local_f8 = 0;
  local_f4 = 0;
  *(float *)(param_2 + 0x74) = fVar3 * fVar2;
  local_f0 = 0;
  local_ec = 0;
  local_e4 = 0;
  local_e0 = 0;
  local_dc = 0;
  *(float *)(param_2 + 0x78) = fVar5 * fVar2;
  local_d8 = 0;
  local_d4 = 0x3f800000;
  local_110[0] = _K_ONE / *(float *)(param_2 + 0x150);
  local_110[5] = _K_ONE / *(float *)(param_2 + 0x164);
  local_e8 = _K_ONE / *(float *)(param_2 + 0x178);
  bMatrixCopy();
  D3DXMatrixMultiply(local_d0,local_110,param_2 + 0x30);
  D3DXMatrixMultiply(auStack_5c,auStack_9c,&local_dc);
  D3DXVec3Transform(param_2 + 0x80,param_4,auStack_68);
  return;
}


// ==== 0x584cd0 FUN_00584cd0

void __fastcall FUN_00584cd0(float *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *unaff_ESI;
  float local_18;
  
  fVar1 = *param_1;
  local_18 = param_1[2];
  fVar2 = param_1[1];
  fVar3 = SQRT(*param_1 * *param_1 + param_1[1] * param_1[1] + param_1[2] * param_1[2]);
  if (1200.0 < fVar3) {
    fVar3 = 1200.0 / fVar3;
    fVar1 = fVar1 * fVar3;
    fVar2 = fVar2 * fVar3;
    local_18 = local_18 * fVar3;
  }
  *(float *)(param_2 + 0x110) = fVar1 + *(float *)(param_2 + 0x110);
  *(float *)(param_2 + 0x114) = fVar2 + *(float *)(param_2 + 0x114);
  *(float *)(param_2 + 0x118) = local_18 + *(float *)(param_2 + 0x118);
  fVar1 = param_1[2] * unaff_ESI[1] - param_1[1] * unaff_ESI[2];
  fVar2 = *param_1 * unaff_ESI[2] - param_1[2] * *unaff_ESI;
  local_18 = param_1[1] * *unaff_ESI - *param_1 * unaff_ESI[1];
  fVar3 = SQRT(fVar1 * fVar1 + local_18 * local_18 + fVar2 * fVar2);
  if (100.0 < fVar3) {
    fVar3 = 100.0 / fVar3;
    fVar1 = fVar1 * fVar3;
    fVar2 = fVar2 * fVar3;
    local_18 = local_18 * fVar3;
  }
  *(float *)(param_2 + 0x120) = fVar1 + *(float *)(param_2 + 0x120);
  *(float *)(param_2 + 0x124) = fVar2 + *(float *)(param_2 + 0x124);
  *(float *)(param_2 + 0x128) = local_18 + *(float *)(param_2 + 0x128);
  return;
}


// ==== 0x584e00 FUN_00584e00

void __fastcall FUN_00584e00(float *param_1)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  
  fVar1 = param_1[1];
  fVar2 = param_1[2];
  *(float *)(in_EAX + 0x120) = *(float *)(in_EAX + 0x120) + *param_1;
  *(float *)(in_EAX + 0x124) = fVar1 + *(float *)(in_EAX + 0x124);
  *(float *)(in_EAX + 0x128) = fVar2 + *(float *)(in_EAX + 0x128);
  return;
}


// ==== 0x584e30 FUN_00584e30

void __fastcall FUN_00584e30(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *in_EAX;
  float local_20;
  float local_1c;
  float local_18;
  
  local_1c = in_EAX[1];
  local_20 = *in_EAX;
  local_18 = in_EAX[2];
  fVar1 = SQRT(local_20 * local_20 + local_18 * local_18 + local_1c * local_1c);
  if (1000.0 < fVar1) {
    fVar1 = 1000.0 / fVar1;
    local_20 = local_20 * fVar1;
    local_1c = local_1c * fVar1;
    local_18 = local_18 * fVar1;
  }
  *(float *)(param_1 + 0x70) = local_20 + *(float *)(param_1 + 0x70);
  *(float *)(param_1 + 0x74) = local_1c + *(float *)(param_1 + 0x74);
  *(float *)(param_1 + 0x78) = local_18 + *(float *)(param_1 + 0x78);
  fVar1 = local_18 * param_2[1] - local_1c * param_2[2];
  fVar2 = local_20 * param_2[2] - local_18 * *param_2;
  local_18 = local_1c * *param_2 - local_20 * param_2[1];
  fVar3 = SQRT(fVar1 * fVar1 + local_18 * local_18 + fVar2 * fVar2);
  if (10.0 < fVar3) {
    fVar3 = 10.0 / fVar3;
    fVar1 = fVar1 * fVar3;
    fVar2 = fVar2 * fVar3;
    local_18 = local_18 * fVar3;
  }
  *(float *)(param_1 + 0x80) = fVar1 + *(float *)(param_1 + 0x80);
  *(float *)(param_1 + 0x84) = fVar2 + *(float *)(param_1 + 0x84);
  *(float *)(param_1 + 0x88) = local_18 + *(float *)(param_1 + 0x88);
  return;
}


// ==== 0x584f60 FUN_00584f60

void __fastcall FUN_00584f60(int param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *in_EAX;
  float local_20;
  float local_1c;
  float local_18;
  
  local_1c = in_EAX[1];
  local_20 = *in_EAX;
  local_18 = in_EAX[2];
  fVar1 = SQRT(local_20 * local_20 + local_1c * local_1c + local_18 * local_18);
  if (1000.0 < fVar1) {
    fVar1 = 1000.0 / fVar1;
    local_20 = local_20 * fVar1;
    local_1c = local_1c * fVar1;
    local_18 = local_18 * fVar1;
  }
  *(float *)(param_1 + 0x70) = local_20 + *(float *)(param_1 + 0x70);
  *(float *)(param_1 + 0x74) = local_1c + *(float *)(param_1 + 0x74);
  *(float *)(param_1 + 0x78) = local_18 + *(float *)(param_1 + 0x78);
  fVar1 = local_18 * param_2[1] - local_1c * param_2[2];
  fVar2 = local_20 * param_2[2] - local_18 * *param_2;
  local_18 = local_1c * *param_2 - local_20 * param_2[1];
  fVar3 = SQRT(fVar1 * fVar1 + local_18 * local_18 + fVar2 * fVar2);
  if (10.0 < fVar3) {
    fVar3 = 10.0 / fVar3;
    fVar1 = fVar1 * fVar3;
    fVar2 = fVar2 * fVar3;
    local_18 = local_18 * fVar3;
  }
  *(float *)(param_1 + 0x80) = fVar1 * param_3 + *(float *)(param_1 + 0x80);
  *(float *)(param_1 + 0x84) = fVar2 * param_3 + *(float *)(param_1 + 0x84);
  *(float *)(param_1 + 0x88) = local_18 * param_3 + *(float *)(param_1 + 0x88);
  return;
}


// ==== 0x5850a0 FUN_005850a0

void __fastcall FUN_005850a0(float *param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *in_EAX;
  int unaff_ESI;
  int iStack_118;
  int iStack_114;
  undefined1 auStack_dc [4];
  float local_d8;
  undefined1 local_d0 [52];
  undefined1 auStack_9c [52];
  undefined1 auStack_68 [12];
  undefined1 auStack_5c [88];
  
  fVar1 = *(float *)(unaff_ESI + 0x74);
  fVar2 = in_EAX[1];
  fVar3 = *(float *)(unaff_ESI + 0x78);
  fVar4 = in_EAX[2];
  local_d8 = *param_1 * in_EAX[1] - *in_EAX * param_1[1];
  *param_2 = (*(float *)(unaff_ESI + 0x70) + *in_EAX) * *(float *)(unaff_ESI + 0x148);
  param_2[1] = (fVar1 + fVar2) * *(float *)(unaff_ESI + 0x148);
  param_2[2] = (fVar3 + fVar4) * *(float *)(unaff_ESI + 0x148);
  iStack_114 = 0x585145;
  bMatrixCopy();
  iStack_118 = unaff_ESI + 400;
  if (*(int *)(unaff_ESI + 0x138) == 0) {
    iStack_118 = unaff_ESI + 0x150;
  }
  iStack_114 = unaff_ESI + 0x30;
  D3DXMatrixMultiply(local_d0);
  D3DXMatrixMultiply(auStack_5c,auStack_9c,auStack_dc);
  D3DXVec3Transform(param_3,&iStack_118,auStack_68);
  return;
}


// ==== 0x5851a0 FUN_005851a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_005851a0(void)

{
  int in_EAX;
  
  return ((float10)*(float *)(in_EAX + 0x80) * (float10)*(float *)(in_EAX + 0xc0) +
         (float10)*(float *)(in_EAX + 0x84) * (float10)*(float *)(in_EAX + 0xc4) +
         (float10)*(float *)(in_EAX + 0x88) * (float10)*(float *)(in_EAX + 200)) * (float10)_K_HALF
         + ((float10)*(float *)(in_EAX + 0x70) * (float10)*(float *)(in_EAX + 0xa0) +
           (float10)*(float *)(in_EAX + 0x74) * (float10)*(float *)(in_EAX + 0xa4) +
           (float10)*(float *)(in_EAX + 0x78) * (float10)*(float *)(in_EAX + 0xa8)) *
           (float10)_K_HALF;
}


// ==== 0x585200 FUN_00585200

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_00585200(float *param_1)

{
  float *in_EAX;
  int iVar1;
  int unaff_ESI;
  float unaff_EDI;
  undefined1 *puVar2;
  float fStack_11c;
  undefined1 auStack_118 [4];
  float fStack_114;
  float local_110;
  float local_10c;
  float local_108;
  float fStack_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_e8;
  float local_e0;
  float local_dc;
  float local_d8;
  undefined1 local_d0 [52];
  undefined1 auStack_9c [52];
  undefined1 auStack_68 [12];
  undefined1 auStack_5c [88];
  
  local_110 = *in_EAX + *(float *)(unaff_ESI + 0x70);
  local_10c = *(float *)(unaff_ESI + 0x74) + in_EAX[1];
  local_108 = *(float *)(unaff_ESI + 0x78) + in_EAX[2];
  local_e8 = *param_1 * in_EAX[1] - *in_EAX * param_1[1];
  local_100 = (in_EAX[2] * param_1[1] - param_1[2] * in_EAX[1]) + *(float *)(unaff_ESI + 0x80);
  local_fc = *(float *)(unaff_ESI + 0x84) + (param_1[2] * *in_EAX - in_EAX[2] * *param_1);
  local_f8 = *(float *)(unaff_ESI + 0x88) + local_e8;
  local_d8 = *(float *)(unaff_ESI + 0x148);
  local_e0 = local_110 * local_d8;
  local_dc = local_10c * local_d8;
  local_d8 = local_108 * local_d8;
  bMatrixCopy();
  iVar1 = unaff_ESI + 400;
  if (*(int *)(unaff_ESI + 0x138) == 0) {
    iVar1 = unaff_ESI + 0x150;
  }
  puVar2 = local_d0;
  D3DXMatrixMultiply(puVar2,iVar1);
  D3DXMatrixMultiply(auStack_5c);
  D3DXVec3Transform(&local_108,auStack_118,auStack_68);
  return ((float10)(float)(unaff_ESI + 0x30) * (float10)fStack_114 +
         (float10)local_110 * (float10)unaff_EDI + (float10)local_10c * (float10)fStack_11c) *
         (float10)_K_HALF +
         ((float10)local_100 * (float10)(float)&local_dc +
         (float10)fStack_104 * (float10)(float)auStack_9c +
         (float10)local_fc * (float10)(float)puVar2) * (float10)_K_HALF;
}


// ==== 0x585353 FUN_00585353

/* WARNING: Control flow encountered bad instruction data */

void FUN_00585353(void)

{
  char *in_EAX;
  
  *in_EAX = *in_EAX + (char)in_EAX;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== 0x585360 FUN_00585360

void __fastcall FUN_00585360(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *in_EAX;
  
  *param_2 = in_EAX[2] * param_1[1] - param_1[2] * in_EAX[1];
  param_2[4] = in_EAX[6] * param_1[1] - param_1[2] * in_EAX[5];
  fVar1 = in_EAX[10];
  fVar2 = param_1[1];
  fVar3 = in_EAX[9];
  fVar4 = param_1[2];
  param_2[0xc] = 0.0;
  param_2[8] = fVar1 * fVar2 - fVar3 * fVar4;
  param_2[1] = param_1[2] * *in_EAX - in_EAX[2] * *param_1;
  param_2[5] = param_1[2] * in_EAX[4] - *param_1 * in_EAX[6];
  fVar1 = param_1[2];
  fVar2 = in_EAX[8];
  fVar3 = in_EAX[10];
  fVar4 = *param_1;
  param_2[0xd] = 0.0;
  param_2[9] = fVar1 * fVar2 - fVar3 * fVar4;
  param_2[2] = *param_1 * in_EAX[1] - *in_EAX * param_1[1];
  param_2[6] = *param_1 * in_EAX[5] - in_EAX[4] * param_1[1];
  fVar1 = in_EAX[9];
  fVar2 = *param_1;
  fVar3 = in_EAX[8];
  fVar4 = param_1[1];
  param_2[0xe] = 0.0;
  param_2[3] = 0.0;
  param_2[7] = 0.0;
  param_2[0xb] = 0.0;
  param_2[0xf] = 1.0;
  param_2[10] = fVar1 * fVar2 - fVar3 * fVar4;
  return;
}


// ==== 0x585410 FUN_00585410

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_00585410(int param_1,undefined4 *param_2)

{
  float *pfVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *extraout_ECX;
  float10 fVar7;
  float fStack_84;
  undefined1 auStack_7c [4];
  float local_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  undefined1 local_60 [16];
  undefined1 local_50 [76];
  
  if (*(float *)(param_1 + 0x1e4) != 0.0) {
    fVar4 = *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0x1e4) + 1.9;
    if (*(int *)(param_1 + 0x13c) != 0) {
      fVar4 = fVar4 * 1.03;
    }
    local_78 = *(float *)(param_1 + 0x38);
    if (local_78 <= 0.0) {
      local_78 = -local_78;
      if (0.3 < local_78) {
        local_78 = 0.3;
      }
      fVar5 = ((1.1 - _K_ONE) / 0.3) * local_78 + _K_ONE;
    }
    else {
      if (0.3 < local_78) {
        local_78 = 0.3;
      }
      fVar5 = _K_ONE - ((_K_ONE - 0.9) / 0.3) * local_78;
    }
    if (fVar5 * fVar4 <
        SQRT(*(float *)(param_1 + 0xa4) * *(float *)(param_1 + 0xa4) +
             *(float *)(param_1 + 0xa0) * *(float *)(param_1 + 0xa0)) * 2.2360249) {
      pfVar1 = (float *)(param_1 + 0x110);
      if (0.0 < *(float *)(param_1 + 0x30) * *pfVar1 +
                *(float *)(param_1 + 0x34) * *(float *)(param_1 + 0x114) +
                *(float *)(param_1 + 0x38) * *(float *)(param_1 + 0x118)) {
        bMatrixCopy();
        D3DXVec3Transform(local_60,pfVar1,local_50);
        fStack_6c = -(fStack_84 * 5.0);
        if (-0.5 < fStack_6c) {
          fStack_6c = -0.5;
        }
        D3DXVec3Transform(auStack_7c,&fStack_6c,(float *)(param_1 + 0x30));
        *pfVar1 = fStack_70;
        *(float *)(param_1 + 0x114) = fStack_6c;
        *(float *)(param_1 + 0x118) = fStack_68;
      }
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0xa4);
  uVar3 = *(undefined4 *)(param_1 + 0xa8);
  *param_2 = *(undefined4 *)(param_1 + 0xa0);
  param_2[1] = uVar2;
  param_2[2] = uVar3;
  FUN_00585360();
  uVar2 = *(undefined4 *)(param_1 + 0x114);
  uVar3 = *(undefined4 *)(param_1 + 0x118);
  param_2[0x14] = *(undefined4 *)(param_1 + 0x110);
  param_2[0x15] = uVar2;
  param_2[0x16] = uVar3;
  uVar2 = *(undefined4 *)(param_1 + 0x124);
  uVar3 = *(undefined4 *)(param_1 + 0x128);
  param_2[0x18] = *(undefined4 *)(param_1 + 0x120);
  param_2[0x19] = uVar2;
  param_2[0x1a] = uVar3;
  fStack_74 = SQRT(extraout_ECX[2] * extraout_ECX[2] +
                   extraout_ECX[1] * extraout_ECX[1] + *extraout_ECX * *extraout_ECX);
  if (*(int *)(param_1 + 0x134) != 0) {
    fVar7 = (float10)FUN_00583ea0(fStack_74);
    fVar7 = -fVar7;
    fStack_6c = (float)((float10)*(float *)(param_1 + 0x84) * fVar7);
    fStack_68 = (float)((float10)*(float *)(param_1 + 0x88) * fVar7);
    param_2[0x18] =
         (float)(fVar7 * (float10)*(float *)(param_1 + 0x80) + (float10)(float)param_2[0x18]);
    param_2[0x19] = fStack_6c + (float)param_2[0x19];
    param_2[0x1a] = fStack_68 + (float)param_2[0x1a];
  }
  local_78 = SQRT(*(float *)(param_1 + 0xa8) * *(float *)(param_1 + 0xa8) +
                  *(float *)(param_1 + 0xa4) * *(float *)(param_1 + 0xa4) +
                  *(float *)(param_1 + 0xa0) * *(float *)(param_1 + 0xa0)) / 4.0;
  if (local_78 < fStack_74 / 2.0) {
    local_78 = fStack_74 / 2.0;
  }
  fVar7 = (float10)FUN_00583ea0(local_78);
  if (fVar7 <= (float10)*(float *)(param_1 + 0x90)) {
    param_2[0x1c] = 0xc1200000;
  }
  else {
    param_2[0x1c] = 0x3dcccccd;
  }
  if (*(int *)(param_1 + 0x130) != 0) {
    fVar6 = -(*(float *)(param_1 + 0x90) * 2.0);
    fVar4 = *(float *)(param_1 + 0x84);
    fVar5 = *(float *)(param_1 + 0x88);
    param_2[0x18] = fVar6 * *(float *)(param_1 + 0x80) + (float)param_2[0x18];
    param_2[0x19] = fVar4 * fVar6 + (float)param_2[0x19];
    param_2[0x1a] = fVar5 * fVar6 + (float)param_2[0x1a];
    fVar6 = -(*(float *)(param_1 + 0x90) * 8.0);
    fVar4 = *(float *)(param_1 + 0x74);
    fVar5 = *(float *)(param_1 + 0x78);
    param_2[0x14] = fVar6 * *(float *)(param_1 + 0x70) + (float)param_2[0x14];
    param_2[0x15] = fVar4 * fVar6 + (float)param_2[0x15];
    param_2[0x16] = fVar5 * fVar6 + (float)param_2[0x16];
  }
  if (*(float *)(param_1 + 0x1e0) != 0.0) {
    if (*(float *)(param_1 + 0x128) <= *(float *)(param_1 + 0x1e0)) {
      if (-*(float *)(param_1 + 0x1e0) <= *(float *)(param_1 + 0x128)) {
        return param_2;
      }
      param_2[0x1a] = -*(float *)(param_1 + 0x1e0);
      return param_2;
    }
    param_2[0x1a] = *(undefined4 *)(param_1 + 0x1e0);
  }
  return param_2;
}


// ==== 0x585810 FUN_00585810

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00585810(int param_1)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  undefined1 auStack_dc [12];
  undefined1 local_d0 [52];
  undefined1 auStack_9c [52];
  undefined1 auStack_68 [12];
  undefined1 auStack_5c [88];
  
  fVar2 = *(float *)(param_1 + 0x148);
  *(float *)(param_1 + 0xa0) = fVar2 * *(float *)(param_1 + 0x70);
  *(float *)(param_1 + 0xa4) = *(float *)(param_1 + 0x74) * fVar2;
  *(float *)(param_1 + 0xa8) = *(float *)(param_1 + 0x78) * fVar2;
  fVar2 = SQRT(*(float *)(param_1 + 0xa8) * *(float *)(param_1 + 0xa8) +
               *(float *)(param_1 + 0xa4) * *(float *)(param_1 + 0xa4) +
               *(float *)(param_1 + 0xa0) * *(float *)(param_1 + 0xa0));
  if ((DAT_006f0904 < fVar2) && (0.7 < *(float *)(param_1 + 0x144))) {
    fVar2 = DAT_006f0904 / fVar2;
    *(float *)(param_1 + 0x70) = fVar2 * *(float *)(param_1 + 0x70);
    *(float *)(param_1 + 0x74) = fVar2 * *(float *)(param_1 + 0x74);
    *(float *)(param_1 + 0x78) = fVar2 * *(float *)(param_1 + 0x78);
    fVar2 = *(float *)(param_1 + 0x148);
    *(float *)(param_1 + 0xa0) = fVar2 * *(float *)(param_1 + 0x70);
    *(float *)(param_1 + 0xa4) = *(float *)(param_1 + 0x74) * fVar2;
    *(float *)(param_1 + 0xa8) = *(float *)(param_1 + 0x78) * fVar2;
  }
  fVar2 = *(float *)(param_1 + 0x148) * 0.10204081;
  *(float *)(param_1 + 0xb0) = fVar2 * *(float *)(param_1 + 0x110);
  *(float *)(param_1 + 0xb4) = *(float *)(param_1 + 0x114) * fVar2;
  *(float *)(param_1 + 0xb8) = *(float *)(param_1 + 0x118) * fVar2;
  bMatrixCopy();
  iVar3 = param_1 + 400;
  if (*(int *)(param_1 + 0x138) == 0) {
    iVar3 = param_1 + 0x150;
  }
  D3DXMatrixMultiply(local_d0,iVar3,(undefined4 *)(param_1 + 0x30));
  D3DXMatrixMultiply(auStack_5c,auStack_9c,auStack_dc);
  pfVar1 = (float *)(param_1 + 0xc0);
  D3DXVec3Transform(pfVar1,param_1 + 0x80,auStack_68);
  fVar2 = SQRT(*(float *)(param_1 + 200) * *(float *)(param_1 + 200) +
               *(float *)(param_1 + 0xc4) * *(float *)(param_1 + 0xc4) + *pfVar1 * *pfVar1);
  if (250.0 < fVar2) {
    fVar2 = 250.0 / fVar2;
    *pfVar1 = fVar2 * *pfVar1;
    *(float *)(param_1 + 0xc4) = *(float *)(param_1 + 0xc4) * fVar2;
    *(float *)(param_1 + 200) = *(float *)(param_1 + 200) * fVar2;
  }
  if (*(float *)(param_1 + 0x90) < 0.0) {
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  *(undefined4 *)(param_1 + 0xdc) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(param_1 + 0xfc) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0xf8) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 0x10c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x114);
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x118);
  if (*(int *)(param_1 + 0x140) != 0) {
    FUN_00584cd0();
  }
  return;
}


// ==== 0x585b40 FUN_00585b40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00585b40(float param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  float10 extraout_ST0;
  int local_18;
  LARGE_INTEGER local_8;
  
  uVar6 = DAT_00734574 & 0xf;
  if (DAT_0073459c == 0) {
    fVar1 = _DAT_006f0890 - param_1;
    iVar4 = ((int)DAT_00734574 % 100) * 0x10;
    *(float *)(&DAT_00730ad8 + iVar4) = param_1;
    if ((0.0 < fVar1) && (fVar1 < 0.033333335)) {
      iVar5 = FUN_005648c0();
      do {
        QueryPerformanceCounter(&local_8);
        uVar2 = DAT_007349c8;
        local_18 = __allshr();
        local_18 = local_18 - iVar5;
        if (local_18 < 0) {
          local_18 = 0;
        }
      } while ((float)(1 << ((byte)uVar2 & 0x1f)) * (float)local_18 * _DAT_007301d0 < fVar1 * 1000.0
              );
      param_1 = fVar1 + param_1;
    }
    uVar3 = DAT_0073ad38;
    uVar2 = DAT_006f088c;
    *(float *)(&DAT_00730adc + iVar4) = param_1;
    *(undefined4 *)(&DAT_00730ae0 + iVar4) = uVar2;
    *(undefined4 *)(&DAT_00730ae4 + iVar4) = uVar3;
    iVar4 = _ftol_nocw();
    iVar5 = _ftol_nocw();
    _DAT_00734570 = (float)(extraout_ST0 - (float10)iVar5 * (float10)0.00025);
    if ((DAT_007345a0 != 0) && (FUN_0057c3b0(iVar4,8,3), DAT_007345a0 != 0)) {
      FUN_0057c3b0(uVar6,4,5);
    }
  }
  else {
    iVar4 = FUN_0057c5a0(3);
    FUN_0057c5a0(5);
  }
  DAT_00734568 = iVar4;
  DAT_0073ad38 = (float)iVar4 * 0.00027777778;
  return;
}


// ==== 0x585d70 FUN_00585d70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00585d70(undefined4 param_1)

{
  int iVar1;
  float10 extraout_ST0;
  
  DAT_006f088c = _ftol_nocw(param_1);
  _DAT_0073456c = (float)(extraout_ST0 - (float10)DAT_006f088c * (float10)0.016666668);
  if (DAT_006f088c == 0) {
    DAT_006f088c = 1;
  }
  DAT_006f0884 = DAT_006f0888 + DAT_006f088c;
  DAT_006f0888 = DAT_006f0884;
  iVar1 = _ftol_nocw();
  DAT_0073ad3c = DAT_0073ad3c + iVar1;
  DAT_00734574 = DAT_00734574 + 1;
  return;
}


// ==== 0x585e00 FUN_00585e00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00585e00(undefined4 param_1)

{
  int iVar1;
  float10 extraout_ST0;
  
  _DAT_006f08a8 = 1;
  if (DAT_0073457c != 0.0) {
    _DAT_00734578 = _ftol_nocw(param_1);
    DAT_006f089c = DAT_006f08a0 + _DAT_00734578;
    _DAT_00734580 = (float)(extraout_ST0 - (float10)_DAT_00734578 * (float10)0.016666668);
    DAT_006f08a0 = DAT_006f089c;
    iVar1 = _ftol_nocw();
    DAT_0073ad34 = DAT_0073ad34 + iVar1;
    DAT_006f08a4 = DAT_006f08a4 + 1;
    DAT_0073457c = 0.0;
    _DAT_006f0898 = (float)DAT_0073ad34 * 0.00025;
  }
  return;
}


// ==== 0x585ec0 FUN_00585ec0

void FUN_00585ec0(void)

{
  int iVar1;
  char cVar2;
  int unaff_ESI;
  
  FUN_00571ea0(0,"WorldTime");
  FUN_00571c20(unaff_ESI,&DAT_0073ad34,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,&DAT_006f0898,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,&DAT_006f08a4,4,4,1);
  FUN_00571c20(unaff_ESI,&DAT_006f08a0,4,4,1);
  FUN_00571c20(unaff_ESI,&DAT_00734578,4,4,1);
  FUN_00571c20(unaff_ESI,&DAT_006f089c,4,4,1);
  if ((*(char *)(unaff_ESI + 0x3e) != '\0') || (*(char *)(unaff_ESI + 0x3f) != '\0')) {
    FUN_00571c20(unaff_ESI,&DAT_0073457c,4,0xffffffff,0);
  }
  FUN_00571c20(unaff_ESI,&DAT_00734580,4,0xffffffff,0);
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


// ==== 0x585fa0 FUN_00585fa0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00585fa0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  int local_10;
  LARGE_INTEGER local_8;
  
  if (DAT_006f0880 == 0) {
    fVar1 = 0.02;
  }
  else {
    fVar1 = 0.016666668;
  }
  fVar1 = (float)DAT_00734560 * fVar1;
  if (DAT_00734564 == 0) {
    return (float10)fVar1;
  }
  QueryPerformanceCounter(&local_8);
  uVar5 = DAT_007349c8;
  iVar4 = DAT_00734564;
  local_10 = __allshr();
  local_10 = local_10 - iVar4;
  if (local_10 < 0) {
    local_10 = 0;
  }
  fVar3 = (float)(1 << ((byte)uVar5 & 0x1f)) * (float)local_10 * _DAT_007301d0 * 0.001;
  if (DAT_006f0880 == 0) {
    fVar2 = 0.02;
  }
  else {
    fVar2 = 0.016666668;
  }
  if (fVar2 < fVar3) {
    return (float10)fVar2 + (float10)fVar1;
  }
  return (float10)fVar3 + (float10)fVar1;
}


// ==== 0x586090 FUN_00586090

void FUN_00586090(char *param_1,uint param_2,int param_3,int param_4,int param_5,int param_6)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  
  iVar2 = DAT_006ee6f0 + -1;
  if (param_3 == 0) {
    if (param_4 == 0) {
      if (param_5 == 0) {
        switch(iVar2) {
        case 0:
        case 2:
          break;
        case 1:
        case 3:
        case 5:
          break;
        default:
        }
        bStrCpy();
        iVar2 = 2;
        if ((param_2 & 4) == 0) {
          pcVar4 = param_1 + 7;
          do {
            *pcVar4 = (char)(param_6 % 10) + '0';
            pcVar4 = pcVar4 + -1;
            iVar2 = iVar2 + -1;
            param_6 = param_6 / 10;
          } while (iVar2 != 0);
        }
        else {
          param_1[1] = '0';
          pcVar4 = param_1 + 4;
          iVar5 = 0;
          do {
            *pcVar4 = (char)(iVar5 % 10) + '0';
            pcVar4 = pcVar4 + -1;
            iVar2 = iVar2 + -1;
            iVar5 = iVar5 / 10;
          } while (iVar2 != 0);
          pcVar4 = param_1 + 7;
          iVar2 = 2;
          do {
            *pcVar4 = (char)(param_6 % 10) + '0';
            pcVar4 = pcVar4 + -1;
            iVar2 = iVar2 + -1;
            param_6 = param_6 / 10;
          } while (iVar2 != 0);
        }
      }
      else {
        switch(iVar2) {
        case 0:
        case 2:
          break;
        case 1:
        case 3:
        case 5:
          break;
        default:
        }
        bStrCpy();
        if ((param_2 & 4) == 0) {
          pcVar4 = param_1 + 4;
          iVar2 = 2;
          do {
            if ((param_5 % 10 == 0) && (param_5 < 10)) {
              *pcVar4 = ' ';
            }
            else {
              *pcVar4 = (char)(param_5 % 10) + '0';
            }
            pcVar4 = pcVar4 + -1;
            iVar2 = iVar2 + -1;
            param_5 = param_5 / 10;
          } while (iVar2 != 0);
          pcVar4 = param_1 + 7;
          iVar2 = 2;
          do {
            *pcVar4 = (char)(param_6 % 10) + '0';
            pcVar4 = pcVar4 + -1;
            iVar2 = iVar2 + -1;
            param_6 = param_6 / 10;
          } while (iVar2 != 0);
        }
        else {
          param_1[1] = '0';
          pcVar4 = param_1 + 4;
          iVar2 = 2;
          do {
            *pcVar4 = (char)(param_5 % 10) + '0';
            pcVar4 = pcVar4 + -1;
            iVar2 = iVar2 + -1;
            param_5 = param_5 / 10;
          } while (iVar2 != 0);
          pcVar4 = param_1 + 7;
          iVar2 = 2;
          do {
            *pcVar4 = (char)(param_6 % 10) + '0';
            pcVar4 = pcVar4 + -1;
            iVar2 = iVar2 + -1;
            param_6 = param_6 / 10;
          } while (iVar2 != 0);
        }
      }
      goto LAB_00586461;
    }
    switch(iVar2) {
    case 0:
    case 2:
      if ((param_2 & 4) == 0) {
        pcVar4 = "--\'--\"--";
      }
      else {
        pcVar4 = "00\'00\"00";
      }
      break;
    case 1:
    case 3:
    case 5:
      if ((param_2 & 4) == 0) {
        pcVar4 = "--:--:--";
      }
      else {
        pcVar4 = "00:00:00";
      }
      break;
    default:
      pcVar4 = "00:00.00";
      if ((param_2 & 4) == 0) {
        pcVar4 = "--:--.--";
      }
    }
    cVar1 = *pcVar4;
    *param_1 = cVar1;
    if (cVar1 != '\0') {
      pcVar3 = param_1;
      do {
        cVar1 = pcVar3[(int)(pcVar4 + (1 - (int)param_1))];
        pcVar3 = pcVar3 + 1;
        *pcVar3 = cVar1;
      } while (cVar1 != '\0');
    }
    pcVar4 = param_1 + 1;
    iVar5 = 2;
    iVar2 = param_4;
    do {
      if ((iVar2 % 10 == 0) && (iVar2 < 10)) {
        *pcVar4 = ' ';
      }
      else {
        *pcVar4 = (char)(iVar2 % 10) + '0';
      }
      pcVar4 = pcVar4 + -1;
      iVar5 = iVar5 + -1;
      iVar2 = iVar2 / 10;
    } while (iVar5 != 0);
    pcVar4 = param_1 + 4;
    iVar2 = 2;
    do {
      *pcVar4 = (char)(param_5 % 10) + '0';
      pcVar4 = pcVar4 + -1;
      iVar2 = iVar2 + -1;
      param_5 = param_5 / 10;
    } while (iVar2 != 0);
    pcVar4 = param_1 + 7;
    iVar2 = 2;
    do {
      *pcVar4 = (char)(param_6 % 10) + '0';
      pcVar4 = pcVar4 + -1;
      iVar2 = iVar2 + -1;
      param_6 = param_6 / 10;
    } while (iVar2 != 0);
    if (((param_2 & 3) == 0) || (param_4 < 10)) goto LAB_00586461;
    bStrLen();
  }
  else {
    switch(iVar2) {
    case 0:
    case 2:
      if ((param_2 & 4) == 0) {
        pcVar4 = "--h:--\'--\"";
      }
      else {
        pcVar4 = "00h:00\'00\"";
      }
      break;
    default:
      pcVar4 = "00h:00:00";
      if ((param_2 & 4) == 0) {
        pcVar4 = "--h:--:--";
      }
    }
    cVar1 = *pcVar4;
    *param_1 = cVar1;
    if (cVar1 != '\0') {
      pcVar3 = param_1;
      do {
        cVar1 = pcVar3[(int)(pcVar4 + (1 - (int)param_1))];
        pcVar3 = pcVar3 + 1;
        *pcVar3 = cVar1;
      } while (cVar1 != '\0');
    }
    pcVar4 = param_1 + 1;
    iVar5 = 2;
    iVar2 = param_3;
    do {
      if ((iVar2 % 10 == 0) && (iVar2 < 10)) {
        *pcVar4 = ' ';
      }
      else {
        *pcVar4 = (char)(iVar2 % 10) + '0';
      }
      pcVar4 = pcVar4 + -1;
      iVar5 = iVar5 + -1;
      iVar2 = iVar2 / 10;
    } while (iVar5 != 0);
    pcVar4 = param_1 + 5;
    iVar2 = 2;
    do {
      *pcVar4 = (char)(param_4 % 10) + '0';
      pcVar4 = pcVar4 + -1;
      iVar2 = iVar2 + -1;
      param_4 = param_4 / 10;
    } while (iVar2 != 0);
    pcVar4 = param_1 + 8;
    iVar2 = 2;
    do {
      *pcVar4 = (char)(param_5 % 10) + '0';
      pcVar4 = pcVar4 + -1;
      iVar2 = iVar2 + -1;
      param_5 = param_5 / 10;
    } while (iVar2 != 0);
    if (((param_2 & 3) == 0) || (param_3 < 10)) goto LAB_00586461;
    iVar2 = 0;
    cVar1 = *param_1;
    while (cVar1 != '\0') {
      iVar5 = iVar2 + 1;
      iVar2 = iVar2 + 1;
      cVar1 = param_1[iVar5];
    }
  }
  FUN_00567d00();
  FUN_00567d00();
LAB_00586461:
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) != 0) {
      *param_1 = '+';
    }
    return;
  }
  *param_1 = '-';
  return;
}


// ==== 0x5864f0 FUN_005864f0

void FUN_005864f0(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  
  iVar1 = *in_EAX;
  iVar2 = iVar1 / 4000;
  *param_1 = iVar2 / 0xe10;
  iVar2 = iVar2 % 0xe10;
  *param_2 = iVar2 / 0x3c;
  *param_3 = iVar2 % 0x3c;
  *param_4 = ((iVar1 % 4000) * 1000) / 4000;
  return;
}


// ==== 0x586580 FUN_00586580

void FUN_00586580(int param_1)

{
  int iVar1;
  int iVar2;
  uint in_EAX;
  int *unaff_EDI;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = param_1;
  iVar1 = *unaff_EDI;
  if ((iVar1 != 0) && (iVar1 != 0x7fffffff)) {
    if (iVar1 < 0) {
      *unaff_EDI = -iVar1;
      FUN_005864f0(&local_4,&local_8,&local_c,&param_1);
      *unaff_EDI = iVar1;
    }
    else {
      FUN_005864f0(&local_4,&local_8,&local_c,&param_1);
    }
    if (*unaff_EDI < 0) {
      in_EAX = in_EAX | 1;
    }
    FUN_00586090(iVar2,in_EAX,local_4,local_8,local_c,param_1 / 10);
    return;
  }
  FUN_00586090(param_1);
  return;
}


// ==== 0x586640 FUN_00586640

undefined4 FUN_00586640(void)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  
  iVar1 = *in_EAX;
  if (iVar1 != 0) {
    if (iVar1 != 0x7fffffff) {
      iVar2 = _ftol_nocw();
      *in_EAX = iVar1 - iVar2;
      if (iVar1 - iVar2 < 0) {
        *in_EAX = 0;
        return 0;
      }
    }
    if ((*in_EAX != 0) && (*in_EAX != 0x7fffffff)) {
      return 1;
    }
  }
  return 0;
}


// ==== 0x586690 FUN_00586690

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00586690(float param_1)

{
  float fVar1;
  int *in_EAX;
  float10 fVar2;
  undefined4 local_4;
  
  fVar1 = ((float)*in_EAX * 0.00025) / param_1;
  fVar2 = (float10)FUN_004387e0(fVar1);
  if ((float10)fVar1 < fVar2) {
    fVar2 = fVar2 - (float10)_K_ONE;
  }
  local_4 = (float)fVar2;
  if (_K_HALF <= fVar1 - local_4) {
    fVar2 = (float10)local_4 + (float10)_K_ONE;
  }
  fVar2 = (float10)bCeil((float)(fVar2 * (float10)param_1 * (float10)4000.0));
  return fVar2 * (float10)0.00025;
}


// ==== 0x586710 FUN_00586710

undefined4 FUN_00586710(void)

{
  return 2;
}


// ==== 0x586720 FUN_00586720

int __fastcall FUN_00586720(int param_1)

{
  return param_1 + 0x24;
}


// ==== 0x586730 FUN_00586730

void __thiscall FUN_00586730(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x24);
  param_2[1] = *(undefined4 *)(param_1 + 0x28);
  return;
}


// ==== 0x586750 FUN_00586750

void __thiscall FUN_00586750(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x24) = *param_2;
  *(undefined4 *)(param_1 + 0x28) = param_2[1];
  return;
}


// ==== 0x586770 FUN_00586770

void __fastcall FUN_00586770(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *in_EAX;
  
  uVar2 = in_EAX[3];
  uVar1 = in_EAX[2];
  uVar3 = *in_EAX;
  *(undefined4 *)(param_1 + 0x74) = in_EAX[1];
  *(undefined4 *)(param_1 + 0x70) = uVar3;
  *(undefined4 *)(param_1 + 0x78) = uVar1;
  *(undefined4 *)(param_1 + 0x7c) = uVar2;
  uVar2 = in_EAX[7];
  uVar1 = in_EAX[6];
  uVar3 = in_EAX[4];
  *(undefined4 *)(param_1 + 0x84) = in_EAX[5];
  *(undefined4 *)(param_1 + 0x80) = uVar3;
  *(undefined4 *)(param_1 + 0x88) = uVar1;
  *(undefined4 *)(param_1 + 0x8c) = uVar2;
  uVar2 = in_EAX[0xb];
  uVar1 = in_EAX[10];
  uVar3 = in_EAX[8];
  *(undefined4 *)(param_1 + 0x94) = in_EAX[9];
  *(undefined4 *)(param_1 + 0x90) = uVar3;
  *(undefined4 *)(param_1 + 0x98) = uVar1;
  *(undefined4 *)(param_1 + 0x9c) = uVar2;
  uVar2 = in_EAX[0xf];
  uVar1 = in_EAX[0xe];
  uVar3 = in_EAX[0xc];
  *(undefined4 *)(param_1 + 0xa4) = in_EAX[0xd];
  *(undefined4 *)(param_1 + 0xa0) = uVar3;
  *(undefined4 *)(param_1 + 0xac) = uVar2;
  *(undefined4 *)(param_1 + 0xa8) = uVar1;
  return;
}


// ==== 0x586820 FUN_00586820

void __fastcall FUN_00586820(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *in_EAX;
  
  uVar2 = in_EAX[3];
  uVar1 = in_EAX[2];
  uVar3 = *in_EAX;
  *(undefined4 *)(param_1 + 0xb4) = in_EAX[1];
  *(undefined4 *)(param_1 + 0xb0) = uVar3;
  *(undefined4 *)(param_1 + 0xb8) = uVar1;
  *(undefined4 *)(param_1 + 0xbc) = uVar2;
  uVar2 = in_EAX[7];
  uVar1 = in_EAX[6];
  uVar3 = in_EAX[4];
  *(undefined4 *)(param_1 + 0xc4) = in_EAX[5];
  *(undefined4 *)(param_1 + 0xc0) = uVar3;
  *(undefined4 *)(param_1 + 200) = uVar1;
  *(undefined4 *)(param_1 + 0xcc) = uVar2;
  uVar2 = in_EAX[0xb];
  uVar1 = in_EAX[10];
  uVar3 = in_EAX[8];
  *(undefined4 *)(param_1 + 0xd4) = in_EAX[9];
  *(undefined4 *)(param_1 + 0xd0) = uVar3;
  *(undefined4 *)(param_1 + 0xd8) = uVar1;
  *(undefined4 *)(param_1 + 0xdc) = uVar2;
  uVar2 = in_EAX[0xf];
  uVar1 = in_EAX[0xe];
  uVar3 = in_EAX[0xc];
  *(undefined4 *)(param_1 + 0xe4) = in_EAX[0xd];
  *(undefined4 *)(param_1 + 0xe0) = uVar3;
  *(undefined4 *)(param_1 + 0xec) = uVar2;
  *(undefined4 *)(param_1 + 0xe8) = uVar1;
  return;
}


// ==== 0x5868e0 FUN_005868e0

void __thiscall
FUN_005868e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  char cVar2;
  undefined4 *in_EAX;
  char *pcVar3;
  
  *in_EAX = &PTR_FUN_006b9544;
  in_EAX[0x61] = 0;
  in_EAX[8] = param_1;
  in_EAX[5] = param_2;
  in_EAX[6] = param_3;
  in_EAX[7] = param_4;
  in_EAX[0x5e] = 0x3f800000;
  in_EAX[0x5f] = 0x3f800000;
  in_EAX[0x60] = 0x3f800000;
  pcVar1 = (char *)(in_EAX + 3);
  in_EAX[0x44] = 1;
  *(undefined2 *)((int)in_EAX + 0x156) = 0;
  in_EAX[0x59] = 0;
  in_EAX[0x57] = 0;
  in_EAX[0x45] = 0;
  *pcVar1 = 'W';
  pcVar3 = pcVar1;
  do {
    cVar2 = pcVar3[(int)("Wheel" + (1 - (int)pcVar1))];
    pcVar3 = pcVar3 + 1;
    *pcVar3 = cVar2;
  } while (cVar2 != '\0');
  return;
}


// ==== 0x586960 FUN_00586960

undefined4 * __thiscall FUN_00586960(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_00586990();
  iVar2 = DAT_00735f74;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00735f74 + 0x18);
    *param_1 = *(undefined4 *)(DAT_00735f74 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x586990 FUN_00586990

void __fastcall FUN_00586990(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = param_2[0x61];
  if ((iVar1 != 0) && (*(undefined4 **)(iVar1 + 0x34) != (undefined4 *)0x0)) {
    **(undefined4 **)(iVar1 + 0x34) = 0;
    *(undefined4 *)(iVar1 + 0x34) = 0;
  }
  *param_2 = &PTR_FUN_006c8584;
  return;
}


// ==== 0x5869c0 FUN_005869c0

void FUN_005869c0(void)

{
  int in_EAX;
  int iVar1;
  char cVar2;
  int unaff_EBX;
  undefined4 *puVar3;
  
  FUN_00571ea0(0,"Wheel");
  FUN_00571c20(unaff_EBX,in_EAX + 0x24,4,0xffffffff,0);
  FUN_00571c20(unaff_EBX,in_EAX + 0x28,4,0xffffffff,0);
  FUN_00571c20(unaff_EBX,in_EAX + 0x110,4,4,1);
  FUN_00571c20(unaff_EBX,in_EAX + 0x180,4,0xffffffff,0);
  if (*(char *)(unaff_EBX + 0x3d) != '\0' || *(char *)(unaff_EBX + 0x3c) != '\0') {
    puVar3 = (undefined4 *)(in_EAX + 0x30);
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    puVar3 = (undefined4 *)(in_EAX + 0x70);
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    puVar3 = (undefined4 *)(in_EAX + 0xb0);
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    *(undefined4 *)(in_EAX + 0xf0) = 0;
    *(undefined4 *)(in_EAX + 0xf4) = 0;
    *(undefined4 *)(in_EAX + 0xf8) = 0;
    *(undefined4 *)(in_EAX + 0xfc) = 0;
    *(undefined4 *)(in_EAX + 0x100) = 0;
    *(undefined4 *)(in_EAX + 0x104) = 0;
    *(undefined4 *)(in_EAX + 0x108) = 0;
    *(undefined4 *)(in_EAX + 0x10c) = 0;
    *(undefined4 *)(in_EAX + 0x118) = 0;
    *(undefined4 *)(in_EAX + 0x11c) = 0;
    *(undefined4 *)(in_EAX + 0x120) = 0;
    *(undefined4 *)(in_EAX + 0x124) = 0;
    *(undefined4 *)(in_EAX + 0x128) = 0;
    *(undefined4 *)(in_EAX + 300) = 0;
    *(undefined4 *)(in_EAX + 0x130) = 0;
    *(undefined4 *)(in_EAX + 0x134) = 0;
    *(undefined4 *)(in_EAX + 0x138) = 0;
    *(undefined4 *)(in_EAX + 0x13c) = 0;
    *(undefined4 *)(in_EAX + 0x140) = 0;
    *(undefined4 *)(in_EAX + 0x144) = 0;
    *(undefined4 *)(in_EAX + 0x148) = 0;
    *(undefined4 *)(in_EAX + 0x14c) = 0;
    *(undefined4 *)(in_EAX + 0x150) = 0;
    *(undefined1 *)(in_EAX + 0x154) = 0;
    *(undefined1 *)(in_EAX + 0x155) = 0;
    *(undefined2 *)(in_EAX + 0x156) = 0;
    *(undefined4 *)(in_EAX + 0x158) = 0;
    *(undefined4 *)(in_EAX + 0x160) = 0;
    *(undefined4 *)(in_EAX + 0x164) = 0;
    *(undefined4 *)(in_EAX + 0x168) = 0;
    *(undefined4 *)(in_EAX + 0x170) = 0;
    *(undefined4 *)(in_EAX + 0x174) = 0;
    *(undefined4 *)(in_EAX + 0x178) = 0;
    *(undefined4 *)(in_EAX + 0x17c) = 0;
    *(undefined4 *)(in_EAX + 0x16c) = 0;
  }
  iVar1 = *(char *)(unaff_EBX + 0x40) * 0x10;
  *(int *)(iVar1 + unaff_EBX + 0x58) =
       *(int *)(unaff_EBX + 0x150) - *(int *)(iVar1 + 0x58 + unaff_EBX);
  cVar2 = *(char *)(unaff_EBX + 0x40) + -1;
  *(char *)(unaff_EBX + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(unaff_EBX + 0x44)) {
    *(undefined4 *)(unaff_EBX + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x586bb0 FUN_00586bb0

void FUN_00586bb0(undefined4 param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  float10 fVar11;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined1 local_90 [36];
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  undefined1 local_50 [48];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar8 = *(int *)(*(int *)(unaff_EDI + 0x14) + 0x18);
  *(undefined4 *)(unaff_EDI + 0x24) = param_1;
  *(undefined4 *)(unaff_EDI + 0x28) = param_2;
  *(undefined2 *)(unaff_ESI + 0x376) = param_3;
  *(undefined4 *)(unaff_ESI + 0x2b0 + iVar8 * 4) = param_2;
  *(undefined4 *)(unaff_ESI + 0x2c0 + iVar8 * 4) = param_1;
  *(undefined4 *)(unaff_ESI + 0x300 + iVar8 * 4) = param_4;
  FUN_00465150(unaff_ESI);
  bMatrixCopy_b();
  local_1c = *(undefined4 *)(unaff_ESI + 0x24);
  local_20 = *(undefined4 *)(unaff_ESI + 0x20);
  local_18 = *(undefined4 *)(unaff_ESI + 0x28);
  local_14 = 0x3f800000;
  D3DXMatrixMultiply(local_90,iVar8 * 0x40 + 0xb0 + unaff_ESI,local_50);
  FUN_00586820();
  FUN_00586770();
  fVar9 = fStack_6c - *(float *)(unaff_ESI + 0x20);
  fVar10 = fStack_68 - *(float *)(unaff_ESI + 0x24);
  fStack_64 = fStack_64 - *(float *)(unaff_ESI + 0x28);
  fVar1 = *(float *)(unaff_ESI + 0x90);
  fVar2 = *(float *)(unaff_ESI + 0x98);
  fVar3 = *(float *)(unaff_ESI + 0x94);
  fVar4 = *(float *)(unaff_ESI + 0x90);
  fVar5 = *(float *)(unaff_ESI + 0x34);
  fVar6 = *(float *)(unaff_ESI + 0x38);
  *(float *)(unaff_EDI + 0xf0) =
       (fVar10 * *(float *)(unaff_ESI + 0x98) - fStack_64 * *(float *)(unaff_ESI + 0x94)) +
       *(float *)(unaff_ESI + 0x30);
  *(float *)(unaff_EDI + 0xf4) = fVar5 + (fStack_64 * fVar1 - fVar9 * fVar2);
  *(float *)(unaff_EDI + 0xf8) = fVar6 + (fVar9 * fVar3 - fVar10 * fVar4);
  fVar11 = (float10)GroundQuery__FindSurfaceBelow
                              (*(undefined4 *)(unaff_ESI + 4),&fStack_6c,&stack0xffffff40,&uStack_ac
                               ,0);
  cVar7 = *(char *)(iVar8 + 0x310 + unaff_ESI);
  *(undefined1 *)(iVar8 + 0x310 + unaff_ESI) = 1;
  if (cVar7 == '\0') {
    *(int *)(unaff_ESI + 0x38c) = *(int *)(unaff_ESI + 0x38c) + 1;
  }
  *(int *)(unaff_ESI + 0x314 + iVar8 * 4) = unaff_EBX;
  if (*(int *)(unaff_ESI + 0x324 + iVar8 * 4) < unaff_EBX) {
    *(int *)(unaff_ESI + 0x324 + iVar8 * 4) = unaff_EBX;
  }
  *(float *)(unaff_EDI + 0x138) = (float)fVar11;
  *(float *)(unaff_EDI + 0x130) = fStack_6c;
  *(float *)(unaff_EDI + 0x134) = fStack_68;
  *(undefined4 *)(unaff_EDI + 0x140) = uStack_ac;
  *(undefined4 *)(unaff_EDI + 0x144) = uStack_a8;
  *(undefined4 *)(unaff_EDI + 0x148) = uStack_a4;
  *(undefined1 *)(unaff_EDI + 0x155) = 1;
  *(int *)(unaff_EDI + 0x150) = unaff_EBX;
  return;
}


// ==== 0x586da0 FUN_00586da0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00586da0(int param_1)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  
  *(undefined4 *)(param_1 + 0x30) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x44) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x58) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x6c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  _ftol_nocw();
  fVar2 = (float10)FUN_00564b10();
  _ftol_nocw();
  fVar3 = (float10)FUN_00564b10();
  *(float *)(param_1 + 0x50) = (float)fVar3;
  *(float *)(param_1 + 0x38) = (float)-fVar3;
  *(float *)(param_1 + 0x30) = (float)fVar2;
  *(float *)(param_1 + 0x58) = (float)fVar2;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  if (*(float *)(param_1 + 0x24) <= 628.318) {
    if ((*(float *)(param_1 + 0x24) < -628.318) &&
       (fVar1 = *(float *)(param_1 + 0x24) + 628.318, *(float *)(param_1 + 0x24) = fVar1,
       fVar1 < -6283.18)) goto LAB_00586e8a;
  }
  else {
    fVar1 = *(float *)(param_1 + 0x24) - 628.318;
    *(float *)(param_1 + 0x24) = fVar1;
    if (6283.18 < fVar1) {
LAB_00586e8a:
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  if (*(int *)(param_1 + 0x110) == 0) {
    if (0.0 <= *(float *)(param_1 + 0x28)) goto LAB_00586ec1;
  }
  else if ((*(int *)(param_1 + 0x110) != 2) || (*(float *)(param_1 + 0x28) <= 0.0))
  goto LAB_00586ec1;
  *(undefined4 *)(param_1 + 0x28) = 0;
LAB_00586ec1:
  if (_K_EPS_SPEED < *(float *)(param_1 + 0x28)) {
    *(undefined4 *)(param_1 + 0x110) = 0;
    return;
  }
  if (-1e-05 <= *(float *)(param_1 + 0x28)) {
    *(undefined4 *)(param_1 + 0x110) = 1;
    return;
  }
  *(undefined4 *)(param_1 + 0x110) = 2;
  return;
}


// ==== 0x586f10 FUN_00586f10

void __thiscall FUN_00586f10(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int in_EAX;
  
  *(char *)(param_1 + 0x155) = (char)in_EAX;
  if (in_EAX != 0) {
    fVar1 = -*(float *)(*(int *)(param_1 + 0x14) + 0x10);
    *(float *)(param_1 + 0x130) = fVar1 * *(float *)(param_1 + 0x140) + *(float *)(param_1 + 0xa0);
    *(float *)(param_1 + 0x134) = fVar1 * *(float *)(param_1 + 0x144) + *(float *)(param_1 + 0xa4);
    *(float *)(param_1 + 0x138) = fVar1 * *(float *)(param_1 + 0x148) + *(float *)(param_1 + 0xa8);
  }
  if (0.0 < param_2) {
    fVar1 = *(float *)(param_1 + 0x148) * *(float *)(param_1 + 0x84) -
            *(float *)(param_1 + 0x88) * *(float *)(param_1 + 0x144);
    fVar3 = *(float *)(param_1 + 0x88) * *(float *)(param_1 + 0x140) -
            *(float *)(param_1 + 0x148) * *(float *)(param_1 + 0x80);
    fVar2 = *(float *)(param_1 + 0x144) * *(float *)(param_1 + 0x80) -
            *(float *)(param_1 + 0x84) * *(float *)(param_1 + 0x140);
    fVar1 = ((fVar3 * *(float *)(param_1 + 0x88) - fVar2 * *(float *)(param_1 + 0x84)) *
             *(float *)(param_1 + 0x140) +
            (fVar2 * *(float *)(param_1 + 0x80) - fVar1 * *(float *)(param_1 + 0x88)) *
            *(float *)(param_1 + 0x144) +
            (fVar1 * *(float *)(param_1 + 0x84) - fVar3 * *(float *)(param_1 + 0x80)) *
            *(float *)(param_1 + 0x148)) * 4.0 - 3.0;
    if (fVar1 < 0.3) {
      fVar1 = 0.3;
    }
    *(float *)(param_1 + 0x158) = fVar1 * param_2;
    return;
  }
  *(undefined4 *)(param_1 + 0x158) = 0;
  return;
}


// ==== 0x587070 FUN_00587070

float10 FUN_00587070(int param_1,undefined4 *param_2,int param_3)

{
  float *unaff_ESI;
  float *unaff_EDI;
  float10 fVar1;
  float10 fVar2;
  char local_25;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  
  fVar1 = (float10)GroundQuery__FindSurfaceBelow
                             (*(undefined4 *)(*(int *)(param_1 + 0x20) + 4),unaff_EDI,param_2,
                              unaff_ESI,&local_25);
  local_24 = (float)fVar1;
  fVar1 = (float10)FUN_00577060(*(undefined4 *)(*(int *)(param_1 + 0x20) + 8),
                                *(undefined4 *)(*(int *)(param_1 + 0x20) + 4),local_24,unaff_EDI,
                                param_2,unaff_ESI,&local_25);
  local_24 = (float)fVar1;
  if (local_25 == '\0') {
    local_24 = -10000.0;
  }
  local_20 = *unaff_EDI;
  local_1c = unaff_EDI[1];
  local_18 = local_24;
  fVar1 = (float10)FUN_00441d80(*param_2);
  *(float *)(param_1 + 0x15c) = (float)fVar1;
  fVar2 = (float10)*unaff_ESI * (float10)*(float *)(param_3 + 0x20) +
          (float10)*(float *)(param_3 + 0x28) * (float10)unaff_ESI[2] +
          (float10)*(float *)(param_3 + 0x24) * (float10)unaff_ESI[1];
  if (fVar2 < (float10)0.001) {
    *param_2 = 0;
    return (float10)-100.0;
  }
  return (((float10)(float)(fVar1 + (float10)local_24) - (float10)unaff_EDI[2]) *
          (float10)unaff_ESI[2] +
         ((float10)local_20 - (float10)*unaff_EDI) * (float10)*unaff_ESI +
         ((float10)local_1c - (float10)unaff_EDI[1]) * (float10)unaff_ESI[1]) / fVar2;
}


// ==== 0x587170 FUN_00587170

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00587170(int param_1,undefined4 *param_2)

{
  float fVar1;
  
  *param_2 = *(undefined4 *)(param_1 + 0x28);
  fVar1 = ((*(float *)(param_1 + 0x108) -
           *(float *)(*(int *)(param_1 + 0x14) + 0x10) * *(float *)(param_1 + 0x118)) +
          *(float *)(param_1 + 0x114)) * _K_HALF;
  *(float *)(param_1 + 0x114) = fVar1;
  param_2[1] = ((fVar1 - *(float *)(&DAT_006ef2fc + *(int *)(param_1 + 0x150) * 0x94) * 0.002 *
                         *(float *)(param_1 + 0x28)) -
               *(float *)(param_1 + 0x16c) * 0.1 * *(float *)(param_1 + 0x28)) /
               *(float *)(param_1 + 0x2c);
  if (*(int *)(param_1 + 0x10c) != 0) {
    param_2[1] = 0;
  }
  if ((*(char *)(param_1 + 0x154) == '\0') && (0.001 < _DAT_006f0738)) {
    param_2[1] = (float)param_2[1] -
                 *(float *)(param_1 + 0x160) /
                 (*(float *)(*(int *)(param_1 + 0x14) + 0x10) * _DAT_006f0738);
  }
  return 0;
}


// ==== 0x587220 FUN_00587220

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00587220(int param_1,float param_2)

{
  float fVar1;
  
  fVar1 = (*(float *)(*(int *)(param_1 + 0x1c) + 4) * *(float *)(param_1 + 0x170) * _DAT_006f0784 +
          *(float *)(*(int *)(param_1 + 0x1c) + 8) * *(float *)(param_1 + 0x174) * _DAT_006f0788) *
          _DAT_006f078c;
  if (fVar1 <= *(float *)(*(int *)(param_1 + 0x14) + 0x10) * param_2 +
               ABS(*(float *)(param_1 + 0x28)) * _DAT_006f0790) {
    *(undefined4 *)(param_1 + 0x10c) = 0;
    return;
  }
  if (_K_ONE < fVar1) {
    *(undefined4 *)(param_1 + 0x10c) = 1;
    *(undefined4 *)(param_1 + 0x28) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0x10c) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return;
}


// ==== 0x5872b0 FUN_005872b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_005872b0(int param_1)

{
  float10 fVar1;
  
  if (((*(int *)(param_1 + 0x10c) == 0) && (0.0 <= *(float *)(param_1 + 0x28))) &&
     (1 < *(int *)(*(int *)(param_1 + 0x14) + 0x18))) {
    fVar1 = ((float10)*(float *)(*(int *)(param_1 + 0x20) + 0x390) - (float10)13.410818) *
            (float10)0.11185;
    if (fVar1 <= (float10)_K_ONE) {
      if (fVar1 < (float10)0.0) {
        fVar1 = (float10)0.0;
      }
    }
    else {
      fVar1 = (float10)_K_ONE;
    }
    return ((float10)_K_ONE - (float10)_DAT_006f0798) * fVar1 + (float10)_DAT_006f0798;
  }
  return (float10)_K_ONE;
}


// ==== 0x587330 FUN_00587330

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00587330(undefined4 param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  ushort uVar4;
  int unaff_ESI;
  float10 fVar5;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_68;
  undefined1 local_60 [16];
  undefined1 local_50 [12];
  undefined4 local_44;
  undefined4 local_34;
  undefined4 local_24;
  
  fVar1 = *(float *)(*(int *)(unaff_ESI + 0x1c) + 4) * *(float *)(unaff_ESI + 0x170) * _DAT_006f0784
  ;
  fVar3 = *(float *)(*(int *)(unaff_ESI + 0x1c) + 8) * *(float *)(unaff_ESI + 0x174) * _DAT_006f0788
  ;
  if (0.0 < *(float *)(unaff_ESI + 0x28)) {
    fVar1 = -fVar1;
  }
  if (*(int *)(unaff_ESI + 0x10c) == 0) {
    *(float *)(unaff_ESI + 0x108) = fVar1 + *(float *)(unaff_ESI + 0x108);
  }
  fVar1 = fVar3;
  if (0.0 < *(float *)(unaff_ESI + 0x28)) {
    fVar1 = -fVar3;
  }
  if (*(int *)(unaff_ESI + 0x10c) == 0) {
    *(float *)(unaff_ESI + 0x108) = fVar1 + *(float *)(unaff_ESI + 0x108);
  }
  bMatrixCopy();
  local_44 = 0;
  local_34 = 0;
  local_24 = 0;
  D3DXVec3Transform(local_60,unaff_ESI + 0xf0,local_50);
  uVar4 = Atan2ToAngle16(fVar3,fStack_68);
  fStack_80 = (float)uVar4 * 9.58738e-05;
  if (3.14159 < fStack_80) {
    fStack_80 = fStack_80 - 6.28318;
  }
  if ((fVar3 < 0.0) && (fStack_80 = fStack_80 + 3.14159, 3.14159 < fStack_80)) {
    fStack_80 = fStack_80 - 6.28318;
  }
  fVar1 = *(float *)(*(int *)(unaff_ESI + 0x14) + 0x10) * *(float *)(unaff_ESI + 0x28) - fVar3;
  *(float *)(unaff_ESI + 0x160) = fVar1;
  *(float *)(unaff_ESI + 0x164) = fVar1;
  if ((((*(float *)(unaff_ESI + 0x160) < -_DAT_006f0780) && (*(float *)(unaff_ESI + 0x108) < 0.0))
      && (fStack_78 == 0.0)) && (param_2 == 0)) {
    *(float *)(unaff_ESI + 0x108) = *(float *)(unaff_ESI + 0x108) * 0.15;
  }
  fVar1 = *(float *)(unaff_ESI + 0x160);
  fVar2 = SQRT(fVar1 * fVar1 + fStack_68 * fStack_68);
  if ((fVar2 != 0.0) && ((fStack_68 != 0.0 || (fVar3 != 0.0)))) {
    fStack_7c = *(float *)(&DAT_006ef2f8 + *(int *)(unaff_ESI + 0x150) * 0x94) *
                *(float *)(*(int *)(unaff_ESI + 0x18) + 0x10) * *(float *)(unaff_ESI + 0x180) *
                *(float *)(unaff_ESI + 0x17c) * *(float *)(unaff_ESI + 0x178);
    if (*(int *)(*(int *)(unaff_ESI + 0x20) + 0x3c0) == 1) {
      fVar5 = (float10)FUN_005872b0();
      fStack_7c = (float)(fVar5 * (float10)fStack_7c);
    }
    fVar2 = (_DAT_006f0794 / fVar2) * fStack_7c * *(float *)(unaff_ESI + 0x158);
    FUN_00587220(ABS(fVar3) *
                 (_DAT_006f0794 / SQRT(fVar3 * fVar3 + fStack_68 * fStack_68)) * fStack_7c *
                 *(float *)(unaff_ESI + 0x158));
    if (((_DAT_006f0780 < ABS(fVar1)) || (**(float **)(unaff_ESI + 0x18) < ABS(fStack_80))) ||
       (*(int *)(unaff_ESI + 0x10c) != 0)) {
      fVar3 = fVar1 * fVar2;
      *(undefined1 *)(unaff_ESI + 0x154) = 1;
      *(float *)(unaff_ESI + 0x118) = fVar3;
      fVar2 = -(fVar2 * fStack_68);
      *(float *)(unaff_ESI + 0x11c) = fVar2;
      if ((*(float *)(*(int *)(unaff_ESI + 0x20) + 0x390) * 2.237 < _K_ONE) && (0.1 < fStack_7c)) {
        fStack_7c = _K_ONE / fStack_7c;
        *(float *)(unaff_ESI + 0x118) = fVar3 * fStack_7c;
        *(float *)(unaff_ESI + 0x11c) = fStack_7c * fVar2;
      }
      *(float *)(unaff_ESI + 0x100) = fVar1;
      *(float *)(unaff_ESI + 0x104) = fStack_68;
      return;
    }
  }
  *(undefined1 *)(unaff_ESI + 0x154) = 0;
  fStack_74 = 1.0;
  *(float *)(unaff_ESI + 0x118) =
       *(float *)(unaff_ESI + 0x108) / *(float *)(*(int *)(unaff_ESI + 0x14) + 0x10);
  if (fVar3 <= 0.0) {
    fStack_74 = -1.0;
  }
  fStack_70 = -1.0;
  if (fStack_80 <= 0.0) {
    fStack_70 = 1.0;
  }
  fVar5 = (float10)FUN_00587740(unaff_ESI,_DAT_006f0794 * *(float *)(unaff_ESI + 0x158),
                                ABS(fStack_80));
  *(undefined4 *)(unaff_ESI + 0x100) = 0;
  *(undefined4 *)(unaff_ESI + 0x104) = 0;
  *(float *)(unaff_ESI + 0x11c) = (float)(fVar5 * (float10)fStack_70 * (float10)fStack_74);
  return;
}


// ==== 0x587740 FUN_00587740

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00587740(int param_1,float param_2,float param_3)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float10 fVar5;
  float10 fVar6;
  
  if (DAT_006f0868 == 0) {
    fVar5 = (float10)FUN_00583ea0(param_3);
    return fVar5 * (float10)*(float *)(param_1 + 0x158) * (float10)_DAT_006f0794 *
           (float10)_DAT_006f07b8;
  }
  pfVar1 = *(float **)(param_1 + 0x18);
  fVar2 = ((param_3 * 57.295776) / *pfVar1) * 12.0 * _K_HALF;
  iVar4 = _ftol_nocw();
  fVar3 = (_DAT_006f0870 * param_2) / pfVar1[1];
  if (5 < iVar4) {
    fVar5 = (float10)FUN_00583ea0(fVar3);
    return fVar5 * (float10)*(float *)(*(int *)(param_1 + 0x18) + 8) * (float10)_DAT_006f086c;
  }
  fVar5 = (float10)FUN_00583ea0(fVar3);
  fVar6 = (float10)FUN_00583ea0(fVar3);
  return ((fVar6 - (float10)(float)fVar5) * ((float10)fVar2 - (float10)iVar4) +
         (float10)(float)fVar5) * (float10)*(float *)(*(int *)(param_1 + 0x18) + 8) *
         (float10)_DAT_006f086c;
}


// ==== 0x587830 FUN_00587830

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00587830(void)

{
  float fVar1;
  int in_EAX;
  char extraout_DL;
  char cVar2;
  float10 fVar3;
  float local_b4;
  float fStack_7c;
  undefined4 uStack_78;
  undefined1 local_70 [4];
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 local_50 [12];
  undefined4 local_44;
  undefined4 local_34;
  undefined4 local_24;
  
  cVar2 = '\0';
  if ((0.0 < *(float *)(in_EAX + 0x108)) && (*(int *)(in_EAX + 0x10c) == 0)) {
    cVar2 = '\x01';
    *(float *)(in_EAX + 0x118) = _DAT_006f0878 * *(float *)(in_EAX + 0x118);
  }
  fVar1 = SQRT(*(float *)(in_EAX + 0x118) * *(float *)(in_EAX + 0x118) +
               *(float *)(in_EAX + 0x11c) * *(float *)(in_EAX + 0x11c));
  local_b4 = *(float *)(&DAT_006ef2f4 + *(int *)(in_EAX + 0x150) * 0x94) *
             *(float *)(*(int *)(in_EAX + 0x18) + 0xc) * *(float *)(in_EAX + 0x180) *
             *(float *)(in_EAX + 0x17c) * *(float *)(in_EAX + 0x178) * *(float *)(in_EAX + 0x158) *
             _DAT_006f0794;
  if (*(int *)(*(int *)(in_EAX + 0x20) + 0x3c0) == 1) {
    fVar3 = (float10)FUN_005872b0();
    local_b4 = (float)(fVar3 * (float10)local_b4);
    cVar2 = extraout_DL;
  }
  if ((fVar1 <= local_b4) || (fVar1 <= 0.001)) {
    if (cVar2 != '\0') {
      *(float *)(in_EAX + 0x118) = *(float *)(in_EAX + 0x118) / _DAT_006f0878;
    }
  }
  else {
    *(float *)(in_EAX + 0x118) = (local_b4 / fVar1) * *(float *)(in_EAX + 0x118);
    *(float *)(in_EAX + 0x11c) = *(float *)(in_EAX + 0x11c) * (local_b4 / fVar1);
  }
  if ((local_b4 <= 0.001) ||
     (*(float *)(in_EAX + 0x168) = fVar1 / local_b4, _K_ONE < fVar1 / local_b4)) {
    *(undefined4 *)(in_EAX + 0x168) = 0x3f800000;
  }
  if ((*(char *)(in_EAX + 0x154) != '\0') || (*(int *)(in_EAX + 0x10c) != 0)) {
    *(undefined4 *)(in_EAX + 0x168) = 0x3f800000;
  }
  if (*(char *)(in_EAX + 0x155) == '\0') {
    *(undefined4 *)(in_EAX + 0x168) = 0;
  }
  bMatrixCopy();
  local_44 = 0;
  local_34 = 0;
  local_24 = 0;
  D3DXVec3Transform(local_70,in_EAX + 0xf0,local_50);
  Atan2ToAngle16(fStack_7c,uStack_78);
  _ftol_nocw();
  fVar3 = (float10)FUN_00564b10();
  if (_K_ONE < ABS(fStack_7c)) {
    *(float *)(in_EAX + 0x118) =
         (float)((float10)*(float *)(in_EAX + 0x118) -
                fVar3 * (float10)*(float *)(in_EAX + 0x11c) * (float10)_K_HALF);
  }
  if (((DAT_006f0874 != 1) && (DAT_006f0874 != 2)) && (DAT_006f0874 == 3)) {
    bNormalize3();
  }
  uStack_6c = *(undefined4 *)(in_EAX + 0x118);
  uStack_68 = *(undefined4 *)(in_EAX + 0x11c);
  uStack_64 = *(undefined4 *)(in_EAX + 0x158);
  D3DXVec3Transform(in_EAX + 0x120,&uStack_6c,&stack0xffffff44);
  return;
}


// ==== 0x587de0 FUN_00587de0

void __fastcall FUN_00587de0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float *in_EAX;
  
  fVar1 = *(float *)(param_1 + 0xc4);
  fVar2 = *(float *)(param_1 + 0x11c);
  fVar3 = *(float *)(param_1 + 0xb4);
  fVar4 = *(float *)(param_1 + 0x118);
  fVar5 = *(float *)(param_1 + 200);
  fVar6 = *(float *)(param_1 + 0x11c);
  fVar7 = *(float *)(param_1 + 0xb8);
  fVar8 = *(float *)(param_1 + 0x118);
  *in_EAX = *(float *)(param_1 + 0x118) * *(float *)(param_1 + 0xb0) +
            *(float *)(param_1 + 0xc0) * *(float *)(param_1 + 0x11c);
  in_EAX[1] = fVar3 * fVar4 + fVar1 * fVar2;
  in_EAX[2] = fVar7 * fVar8 + fVar5 * fVar6;
  return;
}


// ==== 0x587e40 FUN_00587e40

void __fastcall FUN_00587e40(float *param_1,float *param_2)

{
  float *in_EAX;
  
  *param_2 = *param_1 * *in_EAX + param_1[4] * in_EAX[1] + param_1[8] * in_EAX[2];
  param_2[1] = param_1[5] * in_EAX[1] + param_1[1] * *in_EAX + param_1[9] * in_EAX[2];
  param_2[2] = param_1[6] * in_EAX[1] + param_1[2] * *in_EAX + param_1[10] * in_EAX[2];
  return;
}


// ==== 0x587e90 FUN_00587e90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00587e90(undefined4 param_1,int param_2)

{
  int iVar1;
  float fVar2;
  int in_EAX;
  float10 fVar3;
  float10 fVar4;
  float local_48;
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  iVar1 = *(int *)(in_EAX + 0x14);
  local_38 = (float)(1 << ((byte)*(undefined4 *)(iVar1 + 0x18) & 0x1f) &
                    (int)*(char *)(param_2 + 0x86c));
  if ((((*(char *)(in_EAX + 0x154) != '\0') ||
       (K_ONE < *(float *)(in_EAX + 0x168) * *(float *)(in_EAX + 0x158))) &&
      (*(char *)(in_EAX + 0x155) != '\0')) &&
     ((local_38 == 0.0 &&
      (_K_ONE < SQRT(*(float *)(in_EAX + 0xf0) * *(float *)(in_EAX + 0xf0) +
                     *(float *)(in_EAX + 0xf4) * *(float *)(in_EAX + 0xf4)))))) {
    local_3c = *(float *)(in_EAX + 0xf0);
    local_40 = -*(float *)(in_EAX + 0xf4);
    bNormalize3();
    local_30 = 0.0;
    local_2c = 1.0;
    local_28 = 0.0;
    FUN_00587e40();
    local_48 = ABS(local_20 * local_40 + local_1c * local_3c + local_18 * local_38);
    fVar2 = local_48;
    if (local_48 < 0.5) {
      fVar2 = 0.5;
    }
    fVar2 = *(float *)(iVar1 + 0x14) * *(float *)(&DAT_006ef2e4 + *(int *)(in_EAX + 0x150) * 0x94) *
            fVar2 * _K_HALF;
    FUN_005673e0(fVar2);
    local_20 = local_40 + *(float *)(in_EAX + 0xa0);
    local_1c = *(float *)(in_EAX + 0xa4) + local_3c;
    local_18 = *(float *)(in_EAX + 0xa8) + local_38;
    local_30 = *(float *)(in_EAX + 0xa0) - local_40;
    local_2c = *(float *)(in_EAX + 0xa4) - local_3c;
    local_28 = *(float *)(in_EAX + 0xa8) - local_38;
    fVar3 = (float10)GroundQuery__FindSurfaceBelow
                               (*(undefined4 *)(*(int *)(in_EAX + 0x20) + 4),&local_20,0,0,0);
    fVar4 = (float10)GroundQuery__FindSurfaceBelow
                               (*(undefined4 *)(*(int *)(in_EAX + 0x20) + 4),&local_30,0,0,0);
    local_1c = *(float *)(in_EAX + 0xa4);
    local_20 = *(float *)(in_EAX + 0xa0);
    local_18 = (float)(((float10)(float)fVar3 + fVar4) * (float10)_K_HALF);
    local_38 = (float)((float10)(float)fVar3 * (float10)_K_HALF - fVar4 * (float10)_K_HALF);
    FUN_005673e0(fVar2);
    if (*(char *)(in_EAX + 0x154) == '\0') {
      local_48 = local_48 * 0.33333334;
    }
    if (*(int *)(in_EAX + 0x150) == 0xd) {
      local_48 = 0.0;
    }
    else if (local_48 < 0.3) {
      local_48 = 0.3;
    }
    FUN_00589a30(param_2,&local_20,&local_40,*(int *)(in_EAX + 0x150),local_48);
    return;
  }
  iVar1 = *(int *)(in_EAX + 0x184);
  if ((iVar1 != 0) && (*(undefined4 **)(iVar1 + 0x34) != (undefined4 *)0x0)) {
    **(undefined4 **)(iVar1 + 0x34) = 0;
    *(undefined4 *)(iVar1 + 0x34) = 0;
  }
  return;
}


// ==== 0x588170 FUN_00588170

int __fastcall FUN_00588170(int param_1)

{
  return param_1 + 0x1c;
}


// ==== 0x588180 FUN_00588180

void __thiscall FUN_00588180(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x1c);
  param_2[1] = *(undefined4 *)(param_1 + 0x20);
  return;
}


// ==== 0x5881a0 FUN_005881a0

void __thiscall FUN_005881a0(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = *param_2;
  *(undefined4 *)(param_1 + 0x20) = param_2[1];
  return;
}


// ==== 0x5881c0 FUN_005881c0

void __thiscall FUN_005881c0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"TwoWheelAckermanSteering");
  FUN_00571d90();
  FUN_00571d90();
  FUN_00571c20(param_2,param_1 + 0x90,2,2,0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x588240 FUN_00588240

void __thiscall FUN_00588240(int param_1,undefined2 param_2)

{
  float10 fVar1;
  float10 fVar2;
  
  *(undefined2 *)(param_1 + 0x90) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0x3f800000;
  _ftol_nocw();
  fVar1 = (float10)FUN_00564b10();
  _ftol_nocw();
  fVar2 = (float10)FUN_00564b10();
  *(float *)(param_1 + 0x20) = (float)-fVar2;
  *(float *)(param_1 + 0x10) = (float)fVar1;
  *(float *)(param_1 + 0x14) = (float)fVar2;
  *(float *)(param_1 + 0x24) = (float)fVar1;
  *(undefined4 *)(param_1 + 0x50) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0x3f800000;
  _ftol_nocw();
  fVar1 = (float10)FUN_00564b10();
  _ftol_nocw();
  fVar2 = (float10)FUN_00564b10();
  *(float *)(param_1 + 0x60) = (float)-fVar2;
  *(float *)(param_1 + 0x54) = (float)fVar2;
  *(float *)(param_1 + 0x50) = (float)fVar1;
  *(float *)(param_1 + 100) = (float)fVar1;
  return;
}


// ==== 0x5883e0 FUN_005883e0

void __fastcall
FUN_005883e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  char *pcVar1;
  char cVar2;
  undefined4 *in_EAX;
  char *pcVar3;
  
  in_EAX[0x2b] = param_1;
  in_EAX[0x28] = param_3;
  in_EAX[0x29] = param_2;
  in_EAX[5] = param_5;
  pcVar1 = (char *)(in_EAX + 3);
  *in_EAX = &PTR_FUN_006b94f0;
  in_EAX[0x2a] = param_4;
  in_EAX[6] = 0;
  *pcVar1 = 'S';
  pcVar3 = pcVar1;
  do {
    cVar2 = pcVar3[(int)("Suspnsn" + (1 - (int)pcVar1))];
    pcVar3 = pcVar3 + 1;
    *pcVar3 = cVar2;
  } while (cVar2 != '\0');
  return;
}


// ==== 0x588440 FUN_00588440

undefined4 * __thiscall FUN_00588440(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_00584950();
  iVar2 = DAT_00735f84;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00735f84 + 0x18);
    *param_1 = *(undefined4 *)(DAT_00735f84 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x588470 FUN_00588470

void FUN_00588470(void)

{
  int in_EAX;
  int iVar1;
  char cVar2;
  int unaff_ESI;
  undefined4 *puVar3;
  
  FUN_00571ea0(0,"Suspension");
  FUN_00571c20(unaff_ESI,in_EAX + 0x1c,4,0xffffffff,0);
  FUN_00571c20(unaff_ESI,in_EAX + 0x20,4,0xffffffff,0);
  if (*(char *)(unaff_ESI + 0x3d) != '\0' || *(char *)(unaff_ESI + 0x3c) != '\0') {
    *(undefined4 *)(in_EAX + 0x24) = 0;
    *(undefined4 *)(in_EAX + 0x30) = 0;
    *(undefined4 *)(in_EAX + 0x34) = 0;
    *(undefined4 *)(in_EAX + 0x38) = 0;
    *(undefined4 *)(in_EAX + 0x3c) = 0;
    puVar3 = (undefined4 *)(in_EAX + 0x40);
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    *(undefined4 *)(in_EAX + 0x80) = 0;
    *(undefined4 *)(in_EAX + 0xb0) = 0;
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


// ==== 0x588520 FUN_00588520

void FUN_00588520(undefined4 param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  int iVar6;
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x88) = param_1;
  pfVar5 = *(float **)(*(int *)(in_EAX + 0xa0) + 0x14);
  iVar6 = *(int *)(in_EAX + 0xa4);
  fVar1 = pfVar5[1];
  fVar2 = *(float *)(iVar6 + 0x1d4);
  fVar3 = pfVar5[2];
  fVar4 = *(float *)(iVar6 + 0x1d8);
  *(float *)(in_EAX + 0x90) = *pfVar5 - *(float *)(iVar6 + 0x1d0);
  *(float *)(in_EAX + 0x98) = fVar3 - fVar4;
  *(float *)(in_EAX + 0x94) = fVar1 - fVar2;
  return;
}


// ==== 0x588580 FUN_00588580

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00588580(int param_1)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  float *pfVar7;
  float10 fVar8;
  float10 fVar9;
  float *pfVar10;
  float fStack_d4;
  float local_d0 [2];
  undefined1 auStack_c8 [4];
  float fStack_c4;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  undefined1 auStack_7c [16];
  float fStack_6c;
  float fStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  float fStack_5c;
  float fStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  float fStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  
  pfVar10 = local_d0;
  D3DXVec3Transform(pfVar10,param_1 + 0x90,*(int *)(param_1 + 0xa4) + 0x30);
  fStack_c4 = *(float *)(*(int *)(param_1 + 0xa4) + 0x28) + fStack_d4;
  fVar8 = (float10)FUN_00587070(*(int *)(param_1 + 0xa0),*(int *)(param_1 + 0xa0) + 0x150,
                                *(int *)(param_1 + 0xa4) + 0x30);
  fVar8 = fVar8 + (float10)*(float *)(*(int *)(*(int *)(param_1 + 0xa0) + 0x14) + 0x10);
  iVar4 = *(int *)(param_1 + 0x14);
  fVar5 = *(float *)(param_1 + 0x1c);
  if (fVar8 <= (float10)*(float *)(iVar4 + 0x14)) {
    if ((float10)*(float *)(iVar4 + 0x18) <= fVar8) {
      *(float *)(param_1 + 0x1c) = (float)fVar8;
      *(undefined4 *)(param_1 + 0x80) = 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar4 + 0x18);
      *(undefined4 *)(param_1 + 0x80) = 0;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar4 + 0x14);
    *(undefined4 *)(param_1 + 0x80) = 1;
  }
  if (0.0001 < _DAT_006f0738) {
    *(float *)(param_1 + 0x20) = (*(float *)(param_1 + 0x1c) - fVar5) / _DAT_006f0738;
  }
  puVar1 = (undefined4 *)(param_1 + 0x30);
  *puVar1 = *(undefined4 *)(param_1 + 0x90);
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x94);
  uStack_bc = 0x3f800000;
  uStack_b8 = 0;
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x98);
  uStack_b4 = 0;
  uStack_b0 = 0;
  uStack_ac = 0;
  uStack_a8 = 0x3f800000;
  *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x38) + *(float *)(param_1 + 0x1c);
  uStack_a4 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  uStack_98 = 0;
  uStack_94 = 0x3f800000;
  uStack_90 = 0;
  uStack_8c = 0;
  fStack_88 = 0.0;
  fStack_84 = 0.0;
  fStack_80 = 1.0;
  if (*(float *)(*(int *)(param_1 + 0xa0) + 0x16c) != 0.0) {
    fStack_6c = 1.0;
    fStack_68 = 0.0;
    uStack_64 = 0;
    uStack_60 = 0;
    fStack_5c = 0.0;
    fStack_58 = 1.0;
    uStack_54 = 0;
    uStack_50 = 0;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_44 = 0x3f800000;
    uStack_40 = 0;
    uStack_3c = 0;
    fStack_38 = 0.0;
    uStack_34 = 0;
    uStack_30 = 0x3f800000;
    _ftol_nocw();
    FUN_00564b10();
    _ftol_nocw();
    fVar8 = (float10)FUN_00564b10();
    _ftol_nocw();
    fVar9 = (float10)FUN_00564b10();
    fStack_5c = (float)-fVar9;
    fStack_68 = (float)fVar9;
    fStack_6c = (float)fVar8;
    fStack_58 = (float)fVar8;
    D3DXMatrixMultiply(&uStack_bc,&fStack_6c,&uStack_bc);
  }
  fStack_88 = *(float *)(param_1 + 0x34);
  uStack_8c = *puVar1;
  fStack_84 = *(float *)(param_1 + 0x38);
  fStack_80 = 1.0;
  bMatrixCopy_b();
  if (*(int *)(param_1 + 0xa8) != 0) {
    D3DXMatrixMultiply(&uStack_bc,
                       *(int *)(param_1 + 0xac) * 0x40 + *(int *)(*(int *)(param_1 + 0xa8) + 8),
                       &uStack_bc);
  }
  FUN_00586820();
  D3DXVec3Transform(auStack_7c,puVar1,*(int *)(param_1 + 0xa4) + 0x30);
  iVar4 = *(int *)(param_1 + 0xa4);
  fVar5 = *(float *)(iVar4 + 200);
  fVar2 = *(float *)(iVar4 + 0xc0);
  fStack_38 = (fStack_80 * *(float *)(iVar4 + 0xc4) - fStack_84 * *(float *)(iVar4 + 200)) +
              *(float *)(iVar4 + 0xa0);
  fVar3 = *(float *)(iVar4 + 0xa4);
  iVar6 = *(int *)(param_1 + 0xa0);
  local_d0[0] = *(float *)(iVar4 + 0xa8) +
                (fStack_84 * *(float *)(iVar4 + 0xc0) - fStack_88 * *(float *)(iVar4 + 0xc4));
  *(float *)(iVar6 + 0xf0) = fStack_38;
  *(float *)(iVar6 + 0xf4) = fVar3 + (fStack_88 * fVar5 - fStack_80 * fVar2);
  *(float *)(iVar6 + 0xf8) = local_d0[0];
  D3DXMatrixMultiply(auStack_c8,auStack_c8,*(int *)(param_1 + 0xa4) + 0xd0);
  FUN_00586770();
  if (*(int *)(param_1 + 0x80) != 0) {
    if (*(float *)(param_1 + 0x1c) <= 0.0) {
      fVar5 = 0.0;
    }
    else {
      fVar5 = *(float *)(param_1 + 0x1c);
    }
    pfVar7 = *(float **)(param_1 + 0x14);
    fVar5 = (fVar5 * *pfVar7 + _K_ONE) * pfVar7[1] * *(float *)(param_1 + 0x1c) +
            pfVar7[(*(float *)(param_1 + 0x20) <= 0.0) + 2] * *(float *)(param_1 + 0x20) +
            *(float *)(param_1 + 0x88);
    *(float *)(param_1 + 0x24) = fVar5;
    fVar5 = _DAT_00734538 * (float)pfVar10 +
            (*(float *)(param_1 + 0x1c) - *(float *)(*(int *)(param_1 + 0x18) + 0x1c)) * pfVar7[4] +
            fVar5;
    *(float *)(param_1 + 0x24) = fVar5;
    if (0.0 <= fVar5) {
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// ==== 0x588a90 FUN_00588a90

void FUN_00588a90(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return;
}


// ==== 0x588ab0 FUN_00588ab0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00588ab0(void)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int unaff_ESI;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  undefined1 local_40 [4];
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_2c;
  
  D3DXVec3Transform(local_40,unaff_ESI + 0x30,*(int *)(unaff_ESI + 0xa4) + 0x30);
  iVar1 = *(int *)(unaff_ESI + 0xa4);
  iVar2 = *(int *)(unaff_ESI + 0xa0);
  fStack_2c = (fStack_44 * *(float *)(iVar1 + 0xc4) - fStack_48 * *(float *)(iVar1 + 200)) +
              *(float *)(iVar1 + 0xa0);
  fVar3 = -(*(float *)(iVar2 + 0x140) * fStack_2c +
           *(float *)(iVar2 + 0x144) *
           (*(float *)(iVar1 + 0xa4) +
           (fStack_4c * *(float *)(iVar1 + 200) - fStack_44 * *(float *)(iVar1 + 0xc0))) +
           *(float *)(iVar2 + 0x148) *
           (*(float *)(iVar1 + 0xa8) +
           (fStack_48 * *(float *)(iVar1 + 0xc0) - fStack_4c * *(float *)(iVar1 + 0xc4))));
  if (fVar3 < 0.0) {
    return (float10)0.0;
  }
  fVar3 = _DAT_006f073c * fVar3 * *(float *)(iVar1 + 0x144);
  fStack_3c = *(float *)(iVar2 + 0x140) * fVar3;
  fStack_38 = *(float *)(iVar2 + 0x144) * fVar3;
  fStack_34 = *(float *)(iVar2 + 0x148) * fVar3;
  if (DAT_00734540 == 0) {
    FUN_00584e30();
  }
  return (float10)fVar3;
}


// ==== 0x588c00 FUN_00588c00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00588c00(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  
  puVar11 = DAT_0073ad10;
  iVar13 = 0;
  DAT_00734534 = 1;
  _DAT_0073ac60 = 0;
  _DAT_0073ac64 = 0;
  DAT_0073ac68 = 0;
  _DAT_0073ac6c = 0;
  puVar12 = (undefined4 *)NullUpdate_ret();
  for (; puVar11 != puVar12; puVar11 = (undefined4 *)*puVar11) {
    if (puVar11[0x12] == 1) {
      uVar1 = puVar11[0x16];
      uVar2 = puVar11[0x17];
      uVar6 = puVar11[0x24];
      uVar7 = puVar11[0x14];
      uVar3 = puVar11[0x18];
      uVar8 = puVar11[0x22];
      uVar4 = puVar11[0x1b];
      uVar9 = puVar11[0x23];
      uVar5 = puVar11[0x19];
      uVar10 = puVar11[0x13];
      if (iVar13 != 0x95) {
        DAT_0073ac68 = iVar13 + 1;
        (&DAT_00737c14)[iVar13 * 0x14] = puVar11[0x1a];
        (&DAT_00737c10)[iVar13 * 0x14] = uVar10;
        (&DAT_00737c1c)[iVar13 * 0x14] = uVar5;
        (&DAT_00737c20)[iVar13 * 0x14] = uVar4;
        (&DAT_00737c34)[iVar13 * 0x14] = uVar2;
        (&DAT_00737c38)[iVar13 * 0x14] = uVar3;
        (&DAT_00737c30)[iVar13 * 0x14] = uVar1;
        (&DAT_00737c40)[iVar13 * 0x14] = uVar8;
        (&DAT_00737c44)[iVar13 * 0x14] = uVar9;
        (&DAT_00737c48)[iVar13 * 0x14] = uVar6;
        (&DAT_00737c18)[iVar13 * 0x14] = uVar7;
        iVar13 = DAT_0073ac68;
      }
    }
  }
  return;
}


// ==== 0x588d10 TriggerVolume::Loader

/* [canon] assets high (Hopper sub_588d10 + Ghidra make FUN_00588d10: H+G agree) docs/re/assets.md
    */

undefined4 TriggerVolume__Loader(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  
  if (*param_1 == 0x34250) {
    uVar4 = (int)param_1 + 0x17U & 0xfffffff0;
    if (*(int *)(uVar4 + 8) == 2) {
      puVar3 = (undefined4 *)(uVar4 + 0x10);
      iVar5 = *(int *)(uVar4 + 0xc);
      if (0 < iVar5) {
        do {
          iVar1 = puVar3[0x12];
          if ((-1 < iVar1) && (iVar1 < 5)) {
            puVar2 = *(undefined4 **)(&DAT_0073ad0c + iVar1 * 8);
            *puVar2 = puVar3;
            *(undefined4 **)(&DAT_0073ad0c + iVar1 * 8) = puVar3;
            puVar3[1] = puVar2;
            *puVar3 = &DAT_0073ad08 + iVar1 * 8;
          }
          puVar3 = puVar3 + 0x3a;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
    }
    return 1;
  }
  return 0;
}


// ==== 0x588d70 TriggerVolume::Unloader

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (Hopper sub_588d70 + Ghidra make FUN_00588d70: H+G agree) docs/re/assets.md
    */

undefined4 TriggerVolume__Unloader(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  
  _DAT_0073ac60 = 0;
  _DAT_0073ac64 = 0;
  DAT_0073ac68 = 0;
  _DAT_0073ac6c = 0;
  DAT_00734534 = 0;
  if (*param_1 == 0x34250) {
    uVar4 = (int)param_1 + 0x17U & 0xfffffff0;
    if (*(int *)(uVar4 + 8) == 2) {
      piVar3 = (int *)(uVar4 + 0x10);
      iVar5 = *(int *)(uVar4 + 0xc);
      if (0 < iVar5) {
        do {
          iVar1 = *piVar3;
          piVar2 = (int *)piVar3[1];
          piVar3 = piVar3 + 0x3a;
          iVar5 = iVar5 + -1;
          *piVar2 = iVar1;
          *(int **)(iVar1 + 4) = piVar2;
        } while (iVar5 != 0);
      }
    }
    return 1;
  }
  return 0;
}


// ==== 0x588de0 FUN_00588de0

void __fastcall FUN_00588de0(int *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  
  _Memory = (int *)*param_1;
  while (_Memory != param_1) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)*param_1;
  }
  return;
}


// ==== 0x588e10 FUN_00588e10

void FUN_00588e10(void)

{
  FUN_00588ec0(DAT_006f0714,((DAT_0073452c | 0xffff8000) << 8 | DAT_00734528) << 8 | DAT_00734524,
               DAT_006f071c,DAT_006f0720,DAT_006f0708,DAT_006f070c,DAT_006f0710,DAT_006f0718);
  return;
}


// ==== 0x588ec0 FUN_00588ec0

undefined4 * __fastcall
FUN_00588ec0(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_ESI;
  
  iVar3 = *(int *)(unaff_ESI + 0x3078);
  if (iVar3 == 0x95) {
    return (undefined4 *)0x0;
  }
  puVar1 = (undefined4 *)(iVar3 * 0x50 + 0x20 + unaff_ESI);
  *(int *)(unaff_ESI + 0x3078) = iVar3 + 1;
  *puVar1 = param_4;
  puVar1[1] = param_3;
  puVar1[3] = param_5;
  puVar1[4] = param_6;
  uVar2 = param_2[2];
  uVar4 = *param_2;
  puVar1[9] = param_2[1];
  puVar1[8] = uVar4;
  puVar1[10] = uVar2;
  puVar1[0xc] = param_7;
  puVar1[0xd] = param_8;
  puVar1[0xe] = param_9;
  puVar1[2] = param_10;
  return puVar1;
}


// ==== 0x588f40 FUN_00588f40

/* WARNING: Removing unreachable block (ram,0x0058919c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00588f40(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int in_EAX;
  uint uVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  float *unaff_EDI;
  uint local_30;
  uint local_2c;
  uint local_28;
  
  fVar2 = *(float *)(*(int *)(in_EAX + 0x40) + 0x40);
  fVar1 = *(float *)(*(int *)(in_EAX + 0x40) + 0x44);
  local_28 = 0;
  local_2c = 0;
  local_30 = 0;
  if (param_1 != 0) {
    FUN_00588e10(unaff_EDI);
  }
  uVar9 = DAT_006f06fc;
  fVar4 = DAT_006f06f0;
  fVar3 = DAT_006f06ec;
  if (DAT_00734520 != 0) {
    *unaff_EDI = DAT_006f06e8;
    unaff_EDI[4] = DAT_006f06f4;
    uVar5 = DAT_006f0704 << 8;
    unaff_EDI[1] = fVar3;
    fVar1 = DAT_006f06f8;
    uVar5 = uVar5 | _DAT_006f0700;
    unaff_EDI[2] = fVar4;
    unaff_EDI[3] = fVar1;
    unaff_EDI[5] = (float)((uVar5 << 8 | uVar9) & 0xffffff | 0x80000000);
    return;
  }
  iVar7 = 0;
  unaff_EDI[3] = 0.0;
  unaff_EDI[4] = 0.0;
  *unaff_EDI = 0.0;
  unaff_EDI[1] = 0.0;
  unaff_EDI[2] = 0.0;
  if (0 < (int)unaff_EDI[0xc1e]) {
    pfVar6 = unaff_EDI + 0x11;
    do {
      iVar7 = iVar7 + 1;
      fVar3 = pfVar6[-1] - fVar2;
      fVar4 = *pfVar6 - fVar1;
      pfVar6[6] = SQRT(fVar3 * fVar3 + fVar4 * fVar4);
      pfVar6 = pfVar6 + 0x14;
    } while (iVar7 < (int)unaff_EDI[0xc1e]);
  }
  fVar1 = 9999999.0;
  iVar7 = -1;
  iVar8 = 0;
  _DAT_006f0724 = -1;
  if (0 < (int)unaff_EDI[0xc1e]) {
    pfVar6 = unaff_EDI + 0xc;
    do {
      if (pfVar6[-1] <= pfVar6[0xb]) {
        pfVar6[0xc] = 5.60519e-45;
        pfVar6[0xd] = 0.0;
      }
      else {
        if (*pfVar6 <= pfVar6[0xb]) {
          fVar2 = (pfVar6[0xb] - *pfVar6) / (pfVar6[-1] - *pfVar6);
        }
        else {
          fVar2 = 0.0;
        }
        pfVar6[0xd] = _K_ONE - fVar2;
        if (fVar2 == 0.0) {
          pfVar6[0xc] = 1.4013e-45;
          pfVar6[0xd] = 1.0;
          if (pfVar6[-1] < fVar1) {
            fVar1 = pfVar6[-1];
            iVar7 = iVar8;
          }
        }
        else {
          pfVar6[0xc] = 2.8026e-45;
        }
      }
      iVar8 = iVar8 + 1;
      pfVar6 = pfVar6 + 0x14;
    } while (iVar8 < (int)unaff_EDI[0xc1e]);
    _DAT_006f0724 = iVar7;
    if (iVar7 != -1) {
      iVar8 = 0;
      if (0 < (int)unaff_EDI[0xc1e]) {
        pfVar6 = unaff_EDI + 0x19;
        do {
          if ((iVar8 != iVar7) && (pfVar6[-1] == 1.4013e-45)) {
            *pfVar6 = 0.0;
          }
          if (pfVar6[-1] == 2.8026e-45) {
            unaff_EDI[iVar7 * 0x14 + 0x19] = (_K_ONE - *pfVar6) * unaff_EDI[iVar7 * 0x14 + 0x19];
          }
          iVar8 = iVar8 + 1;
          pfVar6 = pfVar6 + 0x14;
        } while (iVar8 < (int)unaff_EDI[0xc1e]);
      }
    }
  }
  iVar7 = 0;
  uVar9 = 0;
  if (0 < (int)unaff_EDI[0xc1e]) {
    pfVar6 = unaff_EDI + 0x19;
    do {
      if (*pfVar6 != 0.0) {
        *unaff_EDI = pfVar6[-5] * *pfVar6 + *unaff_EDI;
        unaff_EDI[1] = pfVar6[-4] * *pfVar6 + unaff_EDI[1];
        unaff_EDI[2] = pfVar6[-3] * *pfVar6 + unaff_EDI[2];
        unaff_EDI[3] = pfVar6[-0xf] * *pfVar6 + unaff_EDI[3];
        unaff_EDI[4] = pfVar6[-0x10] * *pfVar6 + unaff_EDI[4];
        iVar8 = _ftol_nocw();
        local_28 = local_28 + iVar8;
        iVar8 = _ftol_nocw();
        local_2c = local_2c + iVar8;
        iVar8 = _ftol_nocw();
        local_30 = local_30 + iVar8;
      }
      iVar7 = iVar7 + 1;
      pfVar6 = pfVar6 + 0x14;
      uVar9 = local_30;
    } while (iVar7 < (int)unaff_EDI[0xc1e]);
  }
  unaff_EDI[5] = (float)(((uVar9 | 0xffff8000) << 8 | local_2c) << 8 | local_28);
  if (param_1 != 0) {
    unaff_EDI[0xc1c] = 0.0;
    unaff_EDI[0xc1d] = 0.0;
    unaff_EDI[0xc1e] = 0.0;
    unaff_EDI[0xc1f] = 0.0;
  }
  return;
}


// ==== 0x589240 FUN_00589240

void __fastcall FUN_00589240(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00734514;
  iVar1 = *(int *)(DAT_00734514 + 0x18);
  *param_1 = *(undefined4 *)(DAT_00734514 + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x589260 FUN_00589260

void FUN_00589260(void)

{
  int in_EAX;
  
  *(int *)in_EAX = in_EAX;
  *(int *)(in_EAX + 4) = in_EAX;
  return;
}


// ==== 0x589270 FUN_00589270

void FUN_00589270(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined4 *unaff_ESI;
  float10 extraout_ST0;
  float10 extraout_ST1;
  
  uVar2 = _ftol_nocw();
  uVar3 = _ftol_nocw();
  uVar4 = _ftol_nocw();
  uVar1 = *param_1;
  unaff_ESI[1] = (float)extraout_ST1;
  unaff_ESI[2] = (float)extraout_ST0;
  *(undefined1 *)(unaff_ESI + 3) = uVar2;
  *unaff_ESI = uVar1;
  *(undefined1 *)((int)unaff_ESI + 0xd) = uVar3;
  *(undefined1 *)((int)unaff_ESI + 0xe) = uVar4;
  return;
}


// ==== 0x5892d0 FUN_005892d0

void __fastcall FUN_005892d0(undefined4 *param_1,float *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  undefined4 *in_EAX;
  
  uVar1 = in_EAX[1];
  uVar2 = in_EAX[2];
  cVar3 = *(char *)(in_EAX + 3);
  cVar4 = *(char *)((int)in_EAX + 0xd);
  cVar5 = *(char *)((int)in_EAX + 0xe);
  *param_1 = *in_EAX;
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  if (param_2 != (float *)0x0) {
    *param_2 = (float)(int)cVar3 * 0.015625;
    param_2[1] = (float)(int)cVar4 * 0.015625;
    param_2[2] = (float)(int)cVar5 * 0.015625;
  }
  return;
}


// ==== 0x589350 FUN_00589350

void __fastcall FUN_00589350(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  char cVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *in_EAX;
  
  fVar1 = *in_EAX;
  fVar4 = in_EAX[2];
  fVar2 = in_EAX[1];
  cVar3 = *(char *)(in_EAX + 3);
  fVar5 = (float)(int)*(char *)((int)in_EAX + 0xd) * 0.015625;
  fVar6 = (float)(int)*(char *)((int)in_EAX + 0xe) * 0.015625;
  *param_2 = (float)(int)cVar3 * 0.015625 + fVar1;
  param_2[1] = fVar5 + fVar2;
  param_2[2] = fVar6 + fVar4;
  *param_1 = fVar1 - (float)(int)cVar3 * 0.015625;
  param_1[1] = fVar2 - fVar5;
  param_1[2] = fVar4 - fVar6;
  return;
}


// ==== 0x5893e0 FUN_005893e0

void __fastcall
FUN_005893e0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_EAX;
  undefined4 uVar3;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + 0x38) = param_1;
  *(undefined4 *)(unaff_EDI + 0xf0) = 0;
  *(undefined4 *)(unaff_EDI + 0x34) = param_2;
  *(int *)(unaff_EDI + 0x24) = in_EAX;
  if (((*(uint *)(in_EAX + 0x534) & 2) == 0) || ((*(uint *)(in_EAX + 0x534) & 4) == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  *(undefined4 *)(unaff_EDI + 0x28) = uVar3;
  uVar3 = param_3[1];
  uVar1 = param_3[2];
  *(undefined4 *)(unaff_EDI + 0x40) = *param_3;
  *(undefined4 *)(unaff_EDI + 0x44) = uVar3;
  *(undefined4 *)(unaff_EDI + 0x48) = uVar1;
  uVar3 = *param_3;
  uVar1 = param_3[1];
  uVar2 = param_3[2];
  *(undefined4 *)(unaff_EDI + 0x60) = uVar3;
  *(undefined4 *)(unaff_EDI + 100) = uVar1;
  *(undefined4 *)(unaff_EDI + 0x68) = uVar2;
  *(undefined4 *)(unaff_EDI + 0x58) = uVar2;
  *(undefined4 *)(unaff_EDI + 0x50) = uVar3;
  *(undefined4 *)(unaff_EDI + 0x54) = uVar1;
  uVar3 = param_3[1];
  uVar1 = param_3[2];
  *(undefined4 *)(unaff_EDI + 0x100) = *param_3;
  *(undefined4 *)(unaff_EDI + 0x104) = uVar3;
  *(undefined4 *)(unaff_EDI + 0x108) = uVar1;
  uVar3 = FUN_0058a0a0(param_3);
  *(undefined4 *)(unaff_EDI + 0x2c) = uVar3;
  uVar3 = HudWidget__RegisterObject(unaff_EDI);
  *(undefined4 *)(unaff_EDI + 0x30) = uVar3;
  FUN_005894e0(unaff_EDI,param_3,param_4,0,param_5);
  return;
}


// ==== 0x5894a0 FUN_005894a0

void __fastcall FUN_005894a0(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (((*(int **)(param_2 + 0x34) != (int *)0x0) && (iVar1 = **(int **)(param_2 + 0x34), iVar1 != 0)
      ) && (*(undefined4 **)(iVar1 + 0x34) != (undefined4 *)0x0)) {
    **(undefined4 **)(iVar1 + 0x34) = 0;
    *(undefined4 *)(iVar1 + 0x34) = 0;
  }
  iVar1 = **(int **)(param_2 + 0x30);
  piVar2 = (int *)(*(int **)(param_2 + 0x30))[1];
  *piVar2 = iVar1;
  *(int **)(iVar1 + 4) = piVar2;
  FUN_0041f570();
  return;
}


// ==== 0x5894e0 FUN_005894e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005894e0(int param_1,float *param_2,undefined4 param_3,char param_4)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  float local_7c;
  float local_60;
  float local_5c;
  float local_58;
  
  iVar7 = *(int *)(param_1 + 0xf0);
  local_7c = 0.0;
  if (0 < iVar7) {
    iVar5 = (iVar7 + 6) * 0x10;
    fVar2 = *param_2 - *(float *)(iVar5 + param_1);
    iVar5 = iVar5 + param_1;
    fVar3 = param_2[1] - *(float *)(iVar5 + 4);
    local_58 = param_2[2] - *(float *)(iVar5 + 8);
    local_7c = SQRT(local_58 * local_58 + fVar2 * fVar2 + fVar3 * fVar3);
    bNormalize3();
  }
  if (1 < iVar7) {
    fVar3 = _K_ONE - (local_60 * *(float *)(param_1 + 0x10) +
                     local_58 * *(float *)(param_1 + 0x18) + local_5c * *(float *)(param_1 + 0x14));
    fVar2 = local_7c + *(float *)(param_1 + 0x20);
    if (0.2 < fVar3) {
      if (*(undefined4 **)(param_1 + 0x34) == (undefined4 *)0x0) {
        return 0;
      }
      **(undefined4 **)(param_1 + 0x34) = 0;
      *(undefined4 *)(param_1 + 0x34) = 0;
      return 0;
    }
    if ((fVar2 <= 3.0) && (fVar3 < 0.002 || fVar2 < 0.25)) {
      iVar5 = iVar7 + 6;
      *(float *)(param_1 + 0x20) = fVar2;
      goto LAB_0058965d;
    }
  }
  if (iVar7 == 8) {
    return 1;
  }
  iVar5 = iVar7 + 7;
  *(int *)(param_1 + 0xf0) = iVar7 + 1;
  if (1 < iVar7 + 1) {
    *(float *)(param_1 + 0x10) = local_60;
    *(float *)(param_1 + 0x14) = local_5c;
    *(float *)(param_1 + 0x18) = local_58;
  }
  *(float *)(param_1 + 0x20) = local_7c;
LAB_0058965d:
  FUN_00589270(param_2);
  uVar4 = _ftol_nocw();
  *(undefined1 *)(iVar5 * 0x10 + param_1 + 0xf) = uVar4;
  FUN_005677d0(local_7c);
  FUN_00567890();
  *(float *)(param_1 + 0x100) = *(float *)(param_1 + 0x60) + *(float *)(param_1 + 0x50);
  *(float *)(param_1 + 0x104) = *(float *)(param_1 + 0x54) + *(float *)(param_1 + 100);
  *(float *)(param_1 + 0x108) = *(float *)(param_1 + 0x58) + *(float *)(param_1 + 0x68);
  *(float *)(param_1 + 0x100) = *(float *)(param_1 + 0x100) * _K_HALF;
  *(float *)(param_1 + 0x104) = *(float *)(param_1 + 0x104) * _K_HALF;
  *(float *)(param_1 + 0x108) = *(float *)(param_1 + 0x108) * _K_HALF;
  puVar1 = DAT_00737bd4;
  if (param_4 != '\0') {
    puVar6 = (undefined4 *)NullUpdate_ret();
    for (; puVar1 != puVar6; puVar1 = (undefined4 *)*puVar1) {
      iVar7 = FUN_00402a70(puVar1);
      if (iVar7 != 0) {
        *(undefined4 *)(iVar7 + 0x10) = 1;
        bMatrixCopy_b();
        ParticleEmitter_Queue();
        FUN_00589f70(iVar7);
      }
    }
  }
  return 0;
}


// ==== 0x589810 FUN_00589810

void FUN_00589810(void)

{
  int iVar1;
  int unaff_EDI;
  
  if (((&DAT_00731120)[*(int *)(unaff_EDI + 0x38)] != 0) &&
     (FUN_0040be70(), *(int *)(unaff_EDI + 0xf0) != 1 && -1 < *(int *)(unaff_EDI + 0xf0) + -1)) {
    iVar1 = 0;
    do {
      FUN_00589350();
      FUN_00589350();
      FUN_0040c300((&DAT_00731120)[*(int *)(unaff_EDI + 0x38)],&DAT_0078bcc0,0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(unaff_EDI + 0xf0) + -1);
  }
  return;
}


// ==== 0x589930 FUN_00589930

void FUN_00589930(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  piVar5 = DAT_00737be0;
  local_14 = 0xffffffff;
  pcStack_18 = FUN_00688018;
  local_1c = ExceptionList;
  iVar4 = DAT_00734514;
  ExceptionList = &local_1c;
  if (*(int *)(DAT_00734514 + 0x18) == *(int *)(DAT_00734514 + 0x2c)) {
    iVar4 = *DAT_00737be0;
    piVar1 = (int *)DAT_00737be0[1];
    ExceptionList = &local_1c;
    *piVar1 = iVar4;
    *(int **)(iVar4 + 4) = piVar1;
    if ((((int *)piVar5[0xd] != (int *)0x0) && (iVar4 = *(int *)piVar5[0xd], iVar4 != 0)) &&
       (*(undefined4 **)(iVar4 + 0x34) != (undefined4 *)0x0)) {
      **(undefined4 **)(iVar4 + 0x34) = 0;
      *(undefined4 *)(iVar4 + 0x34) = 0;
    }
    iVar4 = *(int *)piVar5[0xc];
    piVar1 = (int *)((int *)piVar5[0xc])[1];
    *piVar1 = iVar4;
    *(int **)(iVar4 + 4) = piVar1;
    FUN_0041f570();
    iVar4 = DAT_00734514;
    iVar6 = *(int *)(DAT_00734514 + 0x18);
    *piVar5 = *(int *)(DAT_00734514 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar6 + -1;
    *(int **)(iVar4 + 0x10) = piVar5;
  }
  puVar2 = *(undefined4 **)(iVar4 + 0x10);
  iVar6 = *(int *)(iVar4 + 0x18) + 1;
  if (puVar2 != (undefined4 *)0x0) {
    uVar3 = *puVar2;
    if (*(int *)(iVar4 + 0x1c) < iVar6) {
      *(int *)(iVar4 + 0x1c) = iVar6;
    }
    *(int *)(iVar4 + 0x18) = iVar6;
    *(undefined4 *)(iVar4 + 0x10) = uVar3;
  }
  local_14 = 0;
  if (puVar2 == (undefined4 *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_005893e0(param_3,param_4,param_6);
  }
  iVar4 = (int)DAT_00737bdc;
  puVar2 = (undefined4 *)((int)DAT_00737bdc + 4);
  DAT_00737bdc = piVar5;
  *puVar2 = piVar5;
  *piVar5 = iVar4;
  piVar5[1] = (int)&DAT_00737bdc;
  ExceptionList = local_1c;
  return;
}


// ==== 0x589a30 FUN_00589a30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00589a30(int param_1,float *param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  float *extraout_EDX;
  float *pfVar8;
  int *unaff_EDI;
  undefined4 local_38;
  
  if ((param_1 == 0) ||
     (fVar2 = *(float *)(param_1 + 0x50) - *param_2, fVar4 = *(float *)(param_1 + 0x54) - param_2[1]
     , fVar3 = *(float *)(param_1 + 0x58) - param_2[2],
     SQRT(fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3) <= 4.0)) {
    local_38 = 0;
    pfVar8 = param_2;
    if ((*(int *)(param_1 + 0x18) != 0) &&
       (cVar5 = Player__CheckDriftTimeout(), pfVar8 = extraout_EDX, cVar5 != '\0')) {
      local_38 = 1;
    }
    iVar6 = *unaff_EDI;
    if (iVar6 == 0) {
      iVar6 = FUN_00589930();
      *unaff_EDI = iVar6;
      return;
    }
    if (((*(uint *)(param_1 + 0x534) & 2) == 0) || ((*(uint *)(param_1 + 0x534) & 4) == 0)) {
      iVar7 = 0;
    }
    else {
      iVar7 = 1;
    }
    if (((iVar7 == *(int *)(iVar6 + 0x28)) && (*(int *)(iVar6 + 0x38) == param_4)) &&
       (iVar6 = FUN_005894e0(iVar6,pfVar8,param_3,local_38,param_5), iVar6 == 0)) {
      return;
    }
    iVar6 = *unaff_EDI;
    FUN_005892d0();
    puVar1 = *(undefined4 **)(iVar6 + 0x34);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = 0;
      *(undefined4 *)(iVar6 + 0x34) = 0;
    }
    iVar6 = FUN_00589930();
    FUN_005894e0(iVar6,param_2,param_3,local_38,param_5);
    *unaff_EDI = iVar6;
  }
  return;
}


// ==== 0x589ba0 FUN_00589ba0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00589ba0(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  if (DAT_00734514 == (undefined4 *)0x0) {
    DAT_00734514 = (undefined4 *)FUN_00566dc0(0x110,"SkidSetSlotPool",0);
    if ((DAT_00734514 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
      *DAT_0073d81c = DAT_00734514;
      puVar8 = DAT_00734514;
      DAT_00734514[1] = DAT_0073d81c;
      DAT_0073d81c = puVar8;
      *DAT_00734514 = &DAT_0073d818;
    }
    DAT_00734514[5] = DAT_00734514[5] & 0xfffffffe;
  }
  puVar8 = &DAT_00731120;
  puVar9 = &DAT_006ef2e0;
  do {
    pbVar5 = (byte *)*puVar9;
    *puVar8 = 0;
    if (pbVar5 != (byte *)0x0) {
      iVar6 = -1;
      bVar2 = *pbVar5;
      while (bVar2 != 0) {
        iVar6 = iVar6 * 0x21 + (uint)bVar2;
        pbVar1 = pbVar5 + 1;
        pbVar5 = pbVar5 + 1;
        bVar2 = *pbVar1;
      }
      uVar3 = Texture_FindByHash(iVar6,1,0);
      *puVar8 = uVar3;
    }
    puVar9 = puVar9 + 0x25;
    puVar8 = puVar8 + 1;
  } while ((int)puVar9 < 0x6f03a4);
  _DAT_00734518 = 0;
  _DAT_0073451c = 0;
  pcVar7 = "XEM_TIREFIRE";
  iVar6 = -1;
  uVar4 = 0x58;
  do {
    iVar6 = iVar6 * 0x21 + uVar4;
    pbVar5 = (byte *)(pcVar7 + 1);
    uVar4 = (uint)*pbVar5;
    pcVar7 = pcVar7 + 1;
  } while (*pbVar5 != 0);
  FUN_00402ad0(iVar6);
  return;
}


// ==== 0x589c90 FUN_00589c90

void __fastcall FUN_00589c90(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int *_Memory;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  bool bVar8;
  
  if (DAT_00734514 != 0) {
    SlotPool__Destroy(param_1);
    DAT_00734514 = 0;
  }
  piVar6 = DAT_00737bcc;
  puVar7 = &DAT_00731120;
  for (iVar5 = 0x1d; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  piVar4 = (int *)NullUpdate_ret();
  piVar1 = DAT_00737bd4;
  if (piVar6 != piVar4) {
    do {
      iVar3 = DAT_007349b4;
      piVar1 = (int *)piVar6[1];
      piVar2 = (int *)*piVar6;
      _Memory = (int *)piVar6[2];
      *piVar1 = (int)piVar2;
      piVar2[1] = (int)piVar1;
      iVar5 = *(int *)(iVar3 + 0x18);
      *piVar6 = *(int *)(iVar3 + 0x10);
      *(int *)(iVar3 + 0x18) = iVar5 + -1;
      bVar8 = DAT_007349b8 != 0;
      *(int **)(iVar3 + 0x10) = piVar6;
      if (bVar8) {
        if (*(int *)(iVar3 + 0x18) == 0) {
          SlotPool__Destroy();
          DAT_007349b4 = 0;
        }
        else {
          DAT_007349b8 = 1;
        }
      }
      piVar6 = (int *)_Memory[1];
      iVar5 = *_Memory;
      *piVar6 = iVar5;
      *(int **)(iVar5 + 4) = piVar6;
      DAT_0078ea30 = DAT_0078ea30 + -1;
      FUN_00401db0();
      _free(_Memory);
      piVar6 = piVar2;
      piVar1 = DAT_00737bd4;
    } while (piVar2 != piVar4);
  }
  while ((int **)piVar1 != &DAT_00737bd4) {
    iVar5 = *piVar1;
    piVar6 = (int *)piVar1[1];
    DAT_00737bd4 = piVar1;
    *piVar6 = iVar5;
    *(int **)(iVar5 + 4) = piVar6;
    FUN_00401db0();
    _free(piVar1);
    piVar1 = DAT_00737bd4;
  }
  DAT_00737bd4 = piVar1;
  return;
}


// ==== 0x589da0 FUN_00589da0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00589da0(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined1 uVar5;
  int iVar6;
  int unaff_ESI;
  
  if (*(char *)(unaff_ESI + 10) == '\0') {
    for (puVar1 = *(undefined4 **)(param_1 + 8); puVar1 != (undefined4 *)(param_1 + 8);
        puVar1 = (undefined4 *)*puVar1) {
      piVar2 = (int *)puVar1[2];
      if (((piVar2[9] == 0) ||
          ((*(uint *)(piVar2[9] + 0x534) & 1 << ((byte)*(undefined4 *)(unaff_ESI + 4) & 0x1f)) != 0)
          ) && (iVar6 = FUN_0040db20(unaff_ESI), iVar6 != 0)) {
        iVar6 = _ftol_nocw();
        if (4.0 < (float)iVar6) {
          if ((float)iVar6 <= 10.0) {
            uVar5 = _ftol_nocw();
          }
          else {
            uVar5 = 0;
          }
          FUN_00589810(unaff_ESI,uVar5);
          iVar6 = *piVar2;
          piVar3 = (int *)piVar2[1];
          *piVar3 = iVar6;
          *(int **)(iVar6 + 4) = piVar3;
          piVar4 = DAT_00737bdc;
          piVar3 = DAT_00737bdc + 1;
          DAT_00737bdc = piVar2;
          *piVar3 = (int)piVar2;
          piVar2[1] = (int)&DAT_00737bdc;
          *piVar2 = (int)piVar4;
        }
      }
    }
  }
  return;
}


// ==== 0x589f00 FUN_00589f00

void FUN_00589f00(void)

{
  int *_Memory;
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = DAT_00737bcc;
  piVar4 = (int *)NullUpdate_ret();
  while (piVar2 = piVar1, piVar2 != piVar4) {
    _Memory = (int *)piVar2[2];
    piVar1 = (int *)*piVar2;
    if (_Memory[4] != 1) {
      piVar2 = (int *)piVar2[1];
      *piVar2 = (int)piVar1;
      piVar1[1] = (int)piVar2;
      FUN_0041f570();
      piVar2 = (int *)_Memory[1];
      iVar3 = *_Memory;
      *piVar2 = iVar3;
      *(int **)(iVar3 + 4) = piVar2;
      DAT_0078ea30 = DAT_0078ea30 + -1;
      FUN_00401db0();
      _free(_Memory);
    }
  }
  return;
}


// ==== 0x589f70 FUN_00589f70

void FUN_00589f70(int param_1)

{
  int iVar1;
  int *piVar2;
  int *unaff_ESI;
  
  if (DAT_007349b4 == 0) {
    FUN_005649f0();
  }
  piVar2 = (int *)FUN_00567160();
  if (piVar2 != (int *)0x0) {
    piVar2[2] = param_1;
    iVar1 = *unaff_ESI;
    *unaff_ESI = (int)piVar2;
    *(int **)(iVar1 + 4) = piVar2;
    piVar2[1] = (int)unaff_ESI;
    *piVar2 = iVar1;
    return;
  }
  iRam00000000 = *unaff_ESI;
  *unaff_ESI = 0;
  *(undefined4 *)(iRam00000000 + 4) = 0;
  piRam00000004 = unaff_ESI;
  return;
}


// ==== 0x589fc0 FUN_00589fc0

void FUN_00589fc0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  piVar1 = (int *)*unaff_EDI;
  while (piVar1 != unaff_EDI) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    FUN_005894a0();
    iVar4 = DAT_00734514;
    iVar2 = *(int *)(DAT_00734514 + 0x18);
    *piVar1 = *(int *)(DAT_00734514 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x58a000 FUN_0058a000

void FUN_0058a000(void)

{
  undefined4 *puVar1;
  
  if (DAT_00734510 == (undefined4 *)0x0) {
    DAT_00734510 = (undefined4 *)FUN_00566dc0(0x50,"ClanSlotPool",0);
    if (DAT_00734510 == (undefined4 *)0x0) {
      return;
    }
    if (DAT_0073d814 == 1) {
      *DAT_0073d81c = DAT_00734510;
      puVar1 = DAT_00734510;
      DAT_00734510[1] = DAT_0073d81c;
      DAT_0073d81c = puVar1;
      *DAT_00734510 = &DAT_0073d818;
    }
  }
  return;
}


// ==== 0x58a050 FUN_0058a050

void FUN_0058a050(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  if ((int **)DAT_00737bc4 != &DAT_00737bc4) {
    do {
      piVar4 = DAT_00737bc4;
      iVar1 = *DAT_00737bc4;
      piVar2 = (int *)DAT_00737bc4[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
      FUN_0058a2e0(piVar4);
      iVar3 = DAT_00734510;
      iVar1 = *(int *)(DAT_00734510 + 0x18);
      *piVar4 = *(int *)(DAT_00734510 + 0x10);
      *(int *)(iVar3 + 0x18) = iVar1 + -1;
      *(int **)(iVar3 + 0x10) = piVar4;
    } while ((int **)DAT_00737bc4 != &DAT_00737bc4);
  }
  return;
}


// ==== 0x58a0a0 FUN_0058a0a0

int * FUN_0058a0a0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  
  iVar2 = _ftol_nocw();
  iVar3 = _ftol_nocw();
  piVar6 = DAT_00737bc4;
  iVar2 = (iVar2 >> 0x16 & 0xffffU) + (iVar3 >> 0x16) * 0x10000;
  piVar4 = (int *)NullUpdate_ret();
  piVar7 = DAT_00737bc8;
  for (; (piVar6 != piVar4 && (piVar6[4] != iVar2)); piVar6 = (int *)*piVar6) {
  }
  if ((int **)piVar6 != &DAT_00737bc4) {
    piVar7 = (int *)piVar6[1];
    piVar6[5] = DAT_006f089c;
    iVar2 = *piVar6;
    *piVar7 = iVar2;
    *(int **)(iVar2 + 4) = piVar7;
    piVar4 = DAT_00737bc4;
    piVar7 = DAT_00737bc4 + 1;
    DAT_00737bc4 = piVar6;
    *piVar7 = (int)piVar6;
    *piVar6 = (int)piVar4;
    piVar6[1] = (int)&DAT_00737bc4;
    return piVar6;
  }
  iVar3 = DAT_00734510;
  if (*(int *)(DAT_00734510 + 0x18) == *(int *)(DAT_00734510 + 0x2c)) {
    iVar3 = *DAT_00737bc8;
    piVar6 = (int *)DAT_00737bc8[1];
    *piVar6 = iVar3;
    *(int **)(iVar3 + 4) = piVar6;
    FUN_0058a2e0(piVar7);
    iVar3 = DAT_00734510;
    iVar5 = *(int *)(DAT_00734510 + 0x18);
    *piVar7 = *(int *)(DAT_00734510 + 0x10);
    *(int *)(iVar3 + 0x18) = iVar5 + -1;
    *(int **)(iVar3 + 0x10) = piVar7;
  }
  if ((*(int *)(iVar3 + 0x10) == 0) && ((*(byte *)(iVar3 + 0x14) & 1) != 0)) {
    FUN_00566e60();
  }
  piVar6 = *(int **)(iVar3 + 0x10);
  iVar5 = *(int *)(iVar3 + 0x18) + 1;
  if (piVar6 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    iVar1 = *piVar6;
    if (*(int *)(iVar3 + 0x1c) < iVar5) {
      *(int *)(iVar3 + 0x1c) = iVar5;
    }
    *(int *)(iVar3 + 0x18) = iVar5;
    *(int *)(iVar3 + 0x10) = iVar1;
    if (((*(byte *)(iVar3 + 0x14) & 2) != 0) &&
       (iVar3 = *(int *)(iVar3 + 0x28) >> 2, piVar7 = piVar6, 0 < iVar3)) {
      for (; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar7 = 0;
        piVar7 = piVar7 + 1;
      }
    }
    piVar7 = piVar6 + 2;
    *piVar7 = (int)piVar7;
    piVar6[3] = (int)piVar7;
    iVar3 = param_1[1];
    iVar5 = param_1[2];
    piVar6[8] = *param_1;
    piVar6[9] = iVar3;
    piVar6[10] = iVar5;
    piVar6[4] = iVar2;
    iVar2 = *param_1;
    iVar3 = param_1[1];
    iVar5 = param_1[2];
    piVar6[0xc] = iVar2;
    piVar6[0xd] = iVar3;
    piVar6[0xe] = iVar5;
    piVar6[0x12] = iVar5;
    piVar6[0x10] = iVar2;
    piVar6[0x11] = iVar3;
  }
  piVar4 = DAT_00737bc4;
  piVar7 = DAT_00737bc4 + 1;
  DAT_00737bc4 = piVar6;
  *piVar7 = (int)piVar6;
  piVar6[1] = (int)&DAT_00737bc4;
  *piVar6 = (int)piVar4;
  return piVar6;
}


// ==== 0x58a240 FUN_0058a240

void FUN_0058a240(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined4 in_EAX;
  int *piVar5;
  int iVar6;
  
  piVar1 = DAT_00737bc4;
  piVar5 = (int *)NullUpdate_ret();
  while (piVar3 = piVar1, piVar3 != piVar5) {
    piVar1 = (int *)*piVar3;
    iVar6 = FUN_00545210();
    if ((10 < iVar6) && (iVar6 = FUN_0040db20(in_EAX), iVar6 != 0)) {
      if (300 < DAT_006f089c - piVar3[5]) {
        piVar2 = (int *)piVar3[1];
        piVar3[5] = DAT_006f089c;
        iVar6 = *piVar3;
        *piVar2 = iVar6;
        *(int **)(iVar6 + 4) = piVar2;
        piVar4 = DAT_00737bc4;
        piVar2 = DAT_00737bc4 + 1;
        DAT_00737bc4 = piVar3;
        *piVar2 = (int)piVar3;
        piVar3[1] = (int)&DAT_00737bc4;
        *piVar3 = (int)piVar4;
      }
      FUN_00589da0(piVar3);
    }
  }
  return;
}


// ==== 0x58a2e0 FUN_0058a2e0

void FUN_0058a2e0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  pcStack_18 = FUN_00686e3e;
  piVar1 = *(int **)(param_1 + 8);
  piVar5 = (int *)(param_1 + 8);
  local_14 = 0;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  while (piVar1 != piVar5) {
    piVar1 = *(int **)(*piVar5 + 8);
    iVar4 = *piVar1;
    piVar2 = (int *)piVar1[1];
    *piVar2 = iVar4;
    *(int **)(iVar4 + 4) = piVar2;
    if ((((int *)piVar1[0xd] != (int *)0x0) && (iVar4 = *(int *)piVar1[0xd], iVar4 != 0)) &&
       (*(undefined4 **)(iVar4 + 0x34) != (undefined4 *)0x0)) {
      **(undefined4 **)(iVar4 + 0x34) = 0;
      *(undefined4 *)(iVar4 + 0x34) = 0;
    }
    iVar4 = *(int *)piVar1[0xc];
    piVar2 = (int *)((int *)piVar1[0xc])[1];
    *piVar2 = iVar4;
    *(int **)(iVar4 + 4) = piVar2;
    FUN_005671c0();
    if ((DAT_007349b8 != 0) && (DAT_007349b4 != 0)) {
      iVar4 = FUN_00564930();
      if (iVar4 == 0) {
        DAT_007349b8 = 1;
      }
      else {
        FUN_00566db0();
        DAT_007349b4 = 0;
      }
    }
    iVar3 = DAT_00734514;
    iVar4 = *(int *)(DAT_00734514 + 0x18);
    *piVar1 = *(int *)(DAT_00734514 + 0x10);
    *(int *)(iVar3 + 0x18) = iVar4 + -1;
    *(int **)(iVar3 + 0x10) = piVar1;
    piVar1 = (int *)*piVar5;
  }
  local_14 = 0xffffffff;
  FUN_00421900();
  ExceptionList = local_1c;
  return;
}


// ==== 0x58a400 FUN_0058a400

void FUN_0058a400(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  piVar1 = (int *)*unaff_EDI;
  while (piVar1 != unaff_EDI) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    FUN_0058a2e0(piVar1);
    iVar4 = DAT_00734510;
    iVar2 = *(int *)(DAT_00734510 + 0x18);
    *piVar1 = *(int *)(DAT_00734510 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x58a440 FUN_0058a440

void __fastcall FUN_0058a440(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00734508;
  iVar1 = *(int *)(DAT_00734508 + 0x18);
  *param_1 = *(undefined4 *)(DAT_00734508 + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x58a460 FUN_0058a460

void __fastcall FUN_0058a460(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int in_EAX;
  
  pcVar1 = *(code **)(in_EAX + 0x54);
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(in_EAX + 0x60) != 0) {
      (*pcVar1)(*(undefined4 *)(in_EAX + 0x58),param_2,*(undefined4 *)(in_EAX + 0x5c));
      return;
    }
    (*pcVar1)(*(undefined4 *)(in_EAX + 0x58),param_2);
  }
  return;
}


// ==== 0x58a490 FUN_0058a490

bool FUN_0058a490(int param_1,int param_2)

{
  return *(int *)(param_1 + 0x4c) <= *(int *)(param_2 + 0x4c);
}


// ==== 0x58a4b0 FUN_0058a4b0

void FUN_0058a4b0(undefined4 param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x68) = 2;
  return;
}


// ==== 0x58a4c0 FUN_0058a4c0

void __fastcall
FUN_0058a4c0(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  char *pcVar1;
  char cVar2;
  int in_EAX;
  char *pcVar3;
  
  *(undefined4 *)(in_EAX + 8) = param_1;
  *(undefined4 *)(in_EAX + 0x3c) = param_2;
  *(undefined4 *)(in_EAX + 0x40) = param_4;
  *(undefined4 *)(in_EAX + 0x44) = 0;
  *(undefined4 *)(in_EAX + 0x48) = 0x100000;
  *(undefined4 *)(in_EAX + 0x4c) = 5;
  *(undefined4 *)(in_EAX + 0x50) = 0;
  cVar2 = *param_3;
  pcVar1 = (char *)(in_EAX + 0xc);
  *pcVar1 = cVar2;
  if (cVar2 != '\0') {
    pcVar3 = pcVar1;
    do {
      cVar2 = pcVar3[(int)(param_3 + (1 - (int)pcVar1))];
      pcVar3 = pcVar3 + 1;
      *pcVar3 = cVar2;
    } while (cVar2 != '\0');
  }
  *(undefined4 *)(in_EAX + 0x58) = param_6;
  *(int *)(in_EAX + 100) = DAT_006f06e4;
  DAT_006f06e4 = DAT_006f06e4 + 1;
  *(undefined4 *)(in_EAX + 0x5c) = 0;
  *(undefined4 *)(in_EAX + 0x60) = 0;
  *(undefined4 *)(in_EAX + 0x68) = 0;
  *(undefined4 *)(in_EAX + 0x6c) = 0;
  *(undefined4 *)(in_EAX + 0x70) = 0;
  *(undefined4 *)(in_EAX + 0x54) = param_5;
  if (100000 < DAT_006f06e4) {
    DAT_006f06e4 = 1;
  }
  return;
}


// ==== 0x58a550 FUN_0058a550

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058a550(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  float10 fVar4;
  
  fVar4 = (float10)FUN_00585fa0();
  *(float *)(unaff_EDI + 0x70) = (float)(fVar4 - (float10)_DAT_00734504);
  if (*(int *)(unaff_EDI + 0x40) == 0) {
    *(undefined4 *)(unaff_EDI + 0x68) = 2;
    return;
  }
  iVar2 = bOpenFile(unaff_EDI + 0xc,1,1);
  if (iVar2 == 0) {
    *(undefined4 *)(unaff_EDI + 0x68) = 3;
    return;
  }
  iVar3 = *(int *)(unaff_EDI + 0x40) - *(int *)(unaff_EDI + 0x44);
  if (*(int *)(unaff_EDI + 0x48) < iVar3) {
    iVar3 = *(int *)(unaff_EDI + 0x48);
  }
  iVar1 = *(int *)(unaff_EDI + 0x3c) + *(int *)(unaff_EDI + 0x44);
  if ((int)(((int)*(uint *)(iVar2 + 4) < 0) - 1 & *(uint *)(iVar2 + 4)) < iVar1 + iVar3) {
    *(undefined4 *)(unaff_EDI + 0x68) = 3;
    FUN_00594d40();
    return;
  }
  *(undefined4 *)(unaff_EDI + 0x68) = 1;
  *(int *)(iVar2 + 8) = iVar1;
  if (-1 < *(int *)(iVar2 + 4)) {
    FUN_00594750(*(int *)(unaff_EDI + 8) + *(int *)(unaff_EDI + 0x44),iVar3,FUN_0058a4b0,unaff_EDI);
  }
  *(int *)(unaff_EDI + 0x44) = *(int *)(unaff_EDI + 0x44) + iVar3;
  FUN_00594d40();
  return;
}


// ==== 0x58a600 FUN_0058a600

void FUN_0058a600(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_0058a790(param_1,param_2);
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      FUN_00565ce0();
    }
    iVar2 = DAT_00734508;
    iVar1 = *(int *)(DAT_00734508 + 0x18);
    *param_1 = *(int *)(DAT_00734508 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(int **)(iVar2 + 0x10) = param_1;
  }
  return;
}


// ==== 0x58a640 FUN_0058a640

uint FUN_0058a640(void)

{
  uint in_EAX;
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar2 = *(int *)(unaff_ESI + 0x10);
  if ((iVar2 < 0x10) && (in_EAX = *(uint *)(unaff_EDI + 0x44), in_EAX == 0)) {
    if (0 < iVar2) {
      in_EAX = bStrCmp();
      if ((in_EAX != 0) || (in_EAX = *(uint *)(unaff_EDI + 0x50), in_EAX != 0)) goto LAB_0058a66e;
    }
    iVar5 = *(int *)(unaff_EDI + 0x40) + *(uint *)(unaff_EDI + 0x3c);
    uVar1 = *(uint *)(unaff_EDI + 0x3c) & 0xfffff800;
    iVar3 = *(int *)(unaff_ESI + 0xc) + *(int *)(unaff_EDI + 0x40);
    if (0 < iVar2) {
      if ((int)*(uint *)(unaff_ESI + 4) < (int)uVar1) {
        uVar1 = *(uint *)(unaff_ESI + 4);
      }
      if (iVar5 < *(int *)(unaff_ESI + 8)) {
        iVar5 = *(int *)(unaff_ESI + 8);
      }
    }
    iVar4 = iVar5 - uVar1;
    if (((iVar4 < 0x40001) && (iVar4 - iVar3 < 0x8001)) &&
       (iVar4 <= (int)((-(uint)(DAT_007301d4 != 0) & 0x6300000) - 0x40000))) {
      *(uint *)(unaff_ESI + 4) = uVar1;
      *(int *)(unaff_ESI + 8) = iVar5;
      *(int *)(unaff_ESI + 0xc) = iVar3;
      *(int *)(unaff_ESI + 0x14 + iVar2 * 4) = unaff_EDI;
      iVar2 = *(int *)(unaff_ESI + 0x10) + 1;
      *(int *)(unaff_ESI + 0x10) = iVar2;
      return CONCAT31((int3)((uint)iVar2 >> 8),1);
    }
    return uVar1 & 0xffffff00;
  }
LAB_0058a66e:
  return in_EAX & 0xffffff00;
}


// ==== 0x58a700 FUN_0058a700

undefined4 * FUN_0058a700(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *in_EAX;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar4 = in_EAX[2];
  iVar1 = in_EAX[1];
  uVar3 = FUN_00565b60(iVar4 - iVar1,0,0,8);
  *in_EAX = uVar3;
  iVar4 = FUN_0058aba0(uVar3,in_EAX[5] + 0xc,in_EAX[1],iVar4 - iVar1,FUN_0058a600);
  puVar6 = DAT_00737bb4;
  puVar5 = (undefined4 *)NullUpdate_ret();
  puVar2 = DAT_00737bbc;
  for (; puVar6 != puVar5; puVar6 = (undefined4 *)*puVar6) {
    if (puVar6[0x19] == iVar4) {
      return puVar6;
    }
  }
  puVar6 = (undefined4 *)NullUpdate_ret();
  while( true ) {
    if (puVar2 == puVar6) {
      return (undefined4 *)0x0;
    }
    if (puVar2[0x19] == iVar4) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  return puVar2;
}


// ==== 0x58a790 FUN_0058a790

void FUN_0058a790(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int local_4;
  
  piVar4 = param_1;
  local_4 = 0;
  if (0 < param_1[4]) {
    param_1 = param_1 + 5;
    iVar5 = DAT_00734508;
    do {
      puVar1 = (undefined4 *)*param_1;
      uVar7 = puVar1[0x10];
      puVar8 = (undefined4 *)((puVar1[0xf] - piVar4[1]) + *piVar4);
      puVar9 = (undefined4 *)puVar1[2];
      for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      pcVar2 = (code *)puVar1[0x15];
      if (pcVar2 != (code *)0x0) {
        if (puVar1[0x18] == 0) {
          (*pcVar2)(puVar1[0x16],param_2);
          iVar5 = DAT_00734508;
        }
        else {
          (*pcVar2)(puVar1[0x16],param_2,puVar1[0x17]);
          iVar5 = DAT_00734508;
        }
      }
      iVar3 = *(int *)(iVar5 + 0x18);
      *puVar1 = *(undefined4 *)(iVar5 + 0x10);
      *(int *)(iVar5 + 0x18) = iVar3 + -1;
      *(undefined4 **)(iVar5 + 0x10) = puVar1;
      local_4 = local_4 + 1;
      param_1 = param_1 + 1;
    } while (local_4 < piVar4[4]);
  }
  return;
}


// ==== 0x58a850 AsyncReadQueue::Pump

/* [canon] track med (hopper+ghidra) docs/re/track.md */

void AsyncReadQueue__Pump(void)

{
  char cVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int extraout_EDX;
  int *piVar9;
  
  if (DAT_0073448c != 0) {
    FUN_0063f0a0(0);
    FUN_00594870();
  }
  piVar9 = DAT_00737bb4;
  if (DAT_0073450c == 0) goto joined_r0x0058a97b;
  iVar4 = DAT_00737bb4[0x1a];
  if (DAT_00737bb4[0x14] == 0) {
    if (DAT_0073459c == 0) {
      if (DAT_007345a0 != 0) {
        FUN_0057c3b0(iVar4,4,6);
      }
    }
    else {
      iVar4 = FUN_0057c480(4,6);
      if (DAT_007345a4[4] <= *DAT_007345a4) {
        FUN_0057c580();
        iVar4 = extraout_EDX;
      }
      if (iVar4 != 1) {
        iVar2 = piVar9[0x1a];
        while (iVar2 == 1) {
          if (DAT_0073448c != 0) {
            FUN_0063f0a0(0);
            FUN_00594870();
          }
          iVar2 = piVar9[0x1a];
        }
      }
    }
  }
  if (iVar4 == 2) {
    iVar4 = *piVar9;
    piVar6 = (int *)piVar9[1];
    *piVar6 = iVar4;
    *(int **)(iVar4 + 4) = piVar6;
    DAT_0073450c = DAT_0073450c + -1;
    if (piVar9[0x1b] == 0) {
      if (piVar9[0x11] != piVar9[0x10]) {
        piVar9[0x1a] = 0;
        piVar6 = DAT_00737bc0;
        *DAT_00737bc0 = (int)piVar9;
        DAT_00737bc0 = piVar9;
        piVar9[1] = (int)piVar6;
        *piVar9 = (int)&DAT_00737bbc;
        goto joined_r0x0058a97b;
      }
      goto LAB_0058a959;
    }
  }
  else {
    if (iVar4 != 3) goto joined_r0x0058a97b;
    iVar4 = *piVar9;
    piVar6 = (int *)piVar9[1];
    *piVar6 = iVar4;
    *(int **)(iVar4 + 4) = piVar6;
    DAT_0073450c = DAT_0073450c + -1;
LAB_0058a959:
    FUN_0058a460();
  }
  iVar2 = DAT_00734508;
  iVar4 = *(int *)(DAT_00734508 + 0x18);
  *piVar9 = *(int *)(DAT_00734508 + 0x10);
  *(int *)(iVar2 + 0x18) = iVar4 + -1;
  *(int **)(iVar2 + 0x10) = piVar9;
joined_r0x0058a97b:
  do {
    if ((2 < DAT_0073450c) || ((int **)DAT_00737bbc == &DAT_00737bbc)) {
      return;
    }
    bList__Sort(&DAT_00737bbc,FUN_0058a490);
    if (0 < DAT_0073450c) {
      pcVar5 = &DAT_00731198;
      do {
        cVar3 = *(char *)((int)(DAT_00737bbc + -0x1cc463) + (int)pcVar5);
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        if ((cVar3 == '\0') || (cVar1 == '\0')) break;
      } while (cVar3 == cVar1);
      if (cVar3 != cVar1) {
        return;
      }
    }
    piVar6 = (int *)FUN_00567160();
    piVar9 = (int *)0x0;
    if (piVar6 != (int *)0x0) {
      *piVar6 = 0;
      piVar6[1] = 0;
      piVar6[2] = 0;
      piVar6[3] = 0;
      piVar6[4] = 0;
      piVar9 = piVar6;
    }
    piVar6 = DAT_00737bbc;
    piVar7 = (int *)NullUpdate_ret();
    while ((piVar6 != piVar7 && (cVar3 = FUN_0058a640(), cVar3 != '\0'))) {
      piVar6 = (int *)*piVar6;
    }
    if (piVar9[4] < 2) {
      if (*piVar9 != 0) {
        FUN_00565ce0();
      }
      iVar2 = DAT_00734508;
      iVar4 = *(int *)(DAT_00734508 + 0x18);
      *piVar9 = *(int *)(DAT_00734508 + 0x10);
      *(int *)(iVar2 + 0x18) = iVar4 + -1;
      *(int **)(iVar2 + 0x10) = piVar9;
    }
    else {
      piVar8 = (int *)FUN_0058a700();
      iVar4 = *piVar8;
      piVar6 = (int *)piVar8[1];
      *piVar6 = iVar4;
      *(int **)(iVar4 + 4) = piVar6;
      piVar7 = DAT_00737bbc;
      piVar6 = DAT_00737bbc + 1;
      DAT_00737bbc = piVar8;
      *piVar6 = (int)piVar8;
      piVar8[1] = (int)&DAT_00737bbc;
      *piVar8 = (int)piVar7;
      iVar4 = 0;
      if (0 < piVar9[4]) {
        piVar6 = piVar9 + 5;
        do {
          iVar2 = *(int *)*piVar6;
          piVar7 = (int *)((int *)*piVar6)[1];
          *piVar7 = iVar2;
          *(int **)(iVar2 + 4) = piVar7;
          iVar4 = iVar4 + 1;
          piVar6 = piVar6 + 1;
        } while (iVar4 < piVar9[4]);
      }
    }
    piVar7 = DAT_00737bbc;
    iVar4 = *DAT_00737bbc;
    piVar6 = (int *)DAT_00737bbc[1];
    piVar9 = DAT_00737bbc + 1;
    *piVar6 = iVar4;
    *(int **)(iVar4 + 4) = piVar6;
    DAT_00731198 = (char)piVar7[3];
    piVar6 = piVar7 + 3;
    if (DAT_00731198 != '\0') {
      pcVar5 = &DAT_00731198;
      do {
        cVar3 = *(char *)((int)piVar6 + 1);
        piVar6 = (int *)((int)piVar6 + 1);
        pcVar5 = pcVar5 + 1;
        *pcVar5 = cVar3;
      } while (cVar3 != '\0');
    }
    FUN_0058a550();
    piVar6 = DAT_00737bb8;
    *DAT_00737bb8 = (int)piVar7;
    DAT_00737bb8 = piVar7;
    *piVar9 = (int)piVar6;
    DAT_0073450c = DAT_0073450c + 1;
    *piVar7 = (int)&DAT_00737bb4;
  } while( true );
}


// ==== 0x58ab00 FUN_0058ab00

undefined4 * FUN_0058ab00(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int unaff_EDI;
  
  puVar3 = DAT_00737bb4;
  puVar2 = (undefined4 *)NullUpdate_ret();
  puVar1 = DAT_00737bbc;
  for (; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
    if (puVar3[0x19] == unaff_EDI) {
      return puVar3;
    }
  }
  puVar3 = (undefined4 *)NullUpdate_ret();
  while( true ) {
    if (puVar1 == puVar3) {
      return (undefined4 *)0x0;
    }
    if (puVar1[0x19] == unaff_EDI) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1;
}


// ==== 0x58ab50 FUN_0058ab50

void FUN_0058ab50(void)

{
  undefined4 *puVar1;
  
  DAT_00734508 = (undefined4 *)FUN_00566dc0(0x74,"QueuedFileSlotPool",0);
  if (DAT_00734508 == (undefined4 *)0x0) {
    return;
  }
  if (DAT_0073d814 == 1) {
    *DAT_0073d81c = DAT_00734508;
    puVar1 = DAT_00734508;
    DAT_00734508[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_00734508 = &DAT_0073d818;
  }
  return;
}


// ==== 0x58aba0 FUN_0058aba0

undefined4 __thiscall
FUN_0058aba0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006866c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_00567160(param_1);
  local_4 = 0;
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_0058a4c0(param_3,param_5,param_6,param_7);
  }
  *DAT_00737bc0 = puVar3;
  puVar1 = puVar3;
  puVar3[1] = DAT_00737bc0;
  DAT_00737bc0 = puVar1;
  *puVar3 = &DAT_00737bbc;
  ExceptionList = local_c;
  return puVar3[0x19];
}


// ==== 0x58ac20 FUN_0058ac20

undefined4 __thiscall
FUN_0058ac20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006866c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_00567160(param_1);
  local_4 = 0;
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_0058a4c0(param_3,param_5,param_6,param_7);
  }
  puVar3[0x17] = param_8;
  puVar3[0x18] = 1;
  *DAT_00737bc0 = puVar3;
  puVar1 = puVar3;
  puVar3[1] = DAT_00737bc0;
  DAT_00737bc0 = puVar1;
  *puVar3 = &DAT_00737bbc;
  ExceptionList = local_c;
  return puVar3[0x19];
}


// ==== 0x58acb0 FUN_0058acb0

void FUN_0058acb0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = DAT_00734508;
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


// ==== 0x58acf0 FUN_0058acf0

void FUN_0058acf0(int param_1)

{
  int *piVar1;
  int iVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068626c;
  local_c = ExceptionList;
  local_4 = 3;
  ExceptionList = &local_c;
  FUN_0058cfd0();
  FUN_0058cf90();
  piVar1 = *(int **)(param_1 + 0x3c);
  while (piVar1 != (int *)(param_1 + 0x3c)) {
    iVar2 = *piVar1;
    piVar1 = (int *)piVar1[1];
    *piVar1 = iVar2;
    *(int **)(iVar2 + 4) = piVar1;
    FUN_00565ce0();
    piVar1 = *(int **)(param_1 + 0x3c);
  }
  FUN_0058cf50();
  FUN_0058cf10();
  FUN_0058ced0();
  FUN_0058ce90();
  ExceptionList = local_c;
  return;
}


// ==== 0x58ad80 FUN_0058ad80

void __fastcall FUN_0058ad80(char *param_1)

{
  char *pcVar1;
  char cVar2;
  int in_EAX;
  char *pcVar3;
  
  cVar2 = *param_1;
  pcVar1 = (char *)(in_EAX + 8);
  *pcVar1 = cVar2;
  if (cVar2 != '\0') {
    pcVar3 = pcVar1;
    do {
      cVar2 = pcVar3[(int)(param_1 + (1 - (int)pcVar1))];
      pcVar3 = pcVar3 + 1;
      *pcVar3 = cVar2;
    } while (cVar2 != '\0');
  }
  *(undefined2 *)(in_EAX + 0x50) = 0;
  *(undefined1 *)(in_EAX + 0x52) = 0;
  *(undefined1 *)(in_EAX + 0x53) = 0;
  *(undefined4 *)(in_EAX + 0x54) = 0;
  return;
}


// ==== 0x58adb0 FUN_0058adb0

void __fastcall FUN_0058adb0(char *param_1)

{
  char *pcVar1;
  char cVar2;
  int in_EAX;
  char *pcVar3;
  
  cVar2 = *param_1;
  pcVar1 = (char *)(in_EAX + 8);
  *pcVar1 = cVar2;
  if (cVar2 != '\0') {
    pcVar3 = pcVar1;
    do {
      cVar2 = pcVar3[(int)(param_1 + (1 - (int)pcVar1))];
      pcVar3 = pcVar3 + 1;
      *pcVar3 = cVar2;
    } while (cVar2 != '\0');
  }
  *(undefined4 *)(in_EAX + 0x50) = 0;
  *(undefined4 *)(in_EAX + 0x54) = 0;
  *(undefined2 *)(in_EAX + 0x58) = 0;
  *(undefined1 *)(in_EAX + 0x5a) = 0;
  *(undefined1 *)(in_EAX + 0x5b) = 0;
  return;
}


// ==== 0x58adf0 FUN_0058adf0

void FUN_0058adf0(void)

{
  int iVar1;
  
  if (DAT_007301e4 != 0) {
    iVar1 = FUN_00565810();
    if ((-1 < iVar1 + -0x58) && (0xf80 < iVar1 + -0x58)) {
      FUN_00565b60(0xf80,0,0,4);
      return;
    }
  }
  FUN_00565b60(0xf80,0,0,0);
  return;
}


// ==== 0x58ae40 FUN_0058ae40

void FUN_0058ae40(void)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  int in_EAX;
  
  if (in_EAX != 0) {
    if (((DAT_007349a0 != 0) && (DAT_007349a4 % DAT_007349a0 == 0)) &&
       ((&DAT_007301d4)[*(byte *)(in_EAX + -0x10)] != 0)) {
      bMemoryPool_Validate((&DAT_007301d4)[*(byte *)(in_EAX + -0x10)],1);
    }
    if (*(short *)(in_EAX + -0xe) != 0x2222) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    bVar1 = *(byte *)(in_EAX + -0xf);
    piVar2 = *(int **)(in_EAX + -0x14);
    *(undefined2 *)(in_EAX + -0xe) = 0;
    iVar3 = *(int *)(in_EAX + -0x18);
    *piVar2 = iVar3;
    *(int **)(iVar3 + 4) = piVar2;
    FUN_005653c0((in_EAX + -0x18) - (uint)bVar1,*(undefined4 *)(in_EAX + -0xc));
    if ((DAT_007349b0 == 0) || (*(int *)(DAT_007301d4 + 0x1c) == 0)) {
      FUN_00565b30();
      return;
    }
  }
  return;
}


// ==== 0x58ae50 FUN_0058ae50

undefined4 FUN_0058ae50(void)

{
  int in_EAX;
  
  if (((*(char *)(in_EAX + 0xba1) == '\x02') && (*(char *)(in_EAX + 0xba2) == '\x02')) &&
     (*(char *)(in_EAX + 0xba3) != '\0')) {
    return 1;
  }
  return 0;
}


// ==== 0x58ae80 LoadedSkin::LoadedSkin

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void LoadedSkin__LoadedSkin(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int unaff_ESI;
  undefined4 *puVar2;
  
  RideInfo__Init();
  RideInfo__operator_(unaff_ESI + 0x480,param_1);
  *(undefined1 *)(unaff_ESI + 0xba0) = 0;
  *(undefined1 *)(unaff_ESI + 0xba1) = 0;
  *(undefined1 *)(unaff_ESI + 0xba2) = 0;
  *(undefined1 *)(unaff_ESI + 0xba3) = 0;
  GetUsedCarTextureInfo(unaff_ESI + 8,unaff_ESI + 0x480,param_2);
  *(undefined4 *)(unaff_ESI + 0xba4) = 0;
  *(undefined4 *)(unaff_ESI + 0xba8) = 0;
  *(undefined4 *)(unaff_ESI + 0xbac) = 0;
  puVar2 = (undefined4 *)(unaff_ESI + 0xbb0);
  for (iVar1 = 0x78; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(unaff_ESI + 0xd90) = 0;
  puVar2 = (undefined4 *)(unaff_ESI + 0xd94);
  for (iVar1 = 0x78; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== 0x58af10 LoadedWheel::LoadedWheel

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void LoadedWheel__LoadedWheel(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  int in_EAX;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  char *pcVar8;
  
  *(undefined1 *)(in_EAX + 8) = 0;
  *(undefined1 *)(in_EAX + 9) = 0;
  *(undefined1 *)(in_EAX + 10) = 0;
  *(undefined1 *)(in_EAX + 0xb) = 0;
  *(undefined4 *)(in_EAX + 0xc) = 0;
  *(undefined4 *)(in_EAX + 0x10) = 0;
  *(undefined4 *)(in_EAX + 0x14) = 0;
  *(undefined4 *)(in_EAX + 0x18) = 0;
  *(undefined4 *)(in_EAX + 0x1c) = 0;
  *(undefined4 *)(in_EAX + 0x20) = 0;
  *(undefined4 *)(in_EAX + 0x24) = 0;
  *(undefined4 *)(in_EAX + 0x28) = 0;
  *(undefined4 *)(in_EAX + 0x2c) = 0;
  *(undefined4 *)(in_EAX + 0x30) = 0;
  *(undefined4 *)(in_EAX + 0x34) = 0;
  *(undefined4 *)(in_EAX + 0x38) = 0;
  *(undefined4 *)(in_EAX + 0x3c) = 0;
  *(undefined4 *)(in_EAX + 0x40) = 0;
  *(undefined4 *)(in_EAX + 0x44) = 0;
  *(undefined4 *)(in_EAX + 0x48) = 0;
  *(undefined4 *)(in_EAX + 0x4c) = 0;
  *(undefined4 *)(in_EAX + 0x50) = 0;
  *(undefined4 *)(in_EAX + 0x54) = 0;
  *(undefined4 *)(in_EAX + 0x58) = 0;
  *(undefined4 *)(in_EAX + 0x5c) = 0;
  *(undefined4 *)(in_EAX + 0x60) = 0;
  *(undefined4 *)(in_EAX + 100) = 0;
  iVar6 = *(int *)(param_1 + 0x490);
  if (iVar6 == 0) {
    *(undefined1 *)(in_EAX + 9) = 2;
    *(undefined1 *)(in_EAX + 10) = 2;
    *(undefined1 *)(in_EAX + 0xb) = 2;
    return;
  }
  *(int *)(in_EAX + 0x14) = iVar6;
  *(undefined4 *)(in_EAX + 0xc) = *(undefined4 *)(iVar6 + 8);
  piVar4 = *(int **)(iVar6 + 0x14);
  piVar2 = piVar4 + *(short *)(iVar6 + 0x1c) * 2;
  if (piVar4 != (int *)0x0) {
    for (; piVar4 < piVar2; piVar4 = piVar4 + 2) {
      if (*piVar4 == 0x10c98090) {
        if (piVar4 != (int *)0x0) {
          iVar5 = piVar4[1];
          goto LAB_0058afb7;
        }
        break;
      }
    }
  }
  iVar5 = 0;
LAB_0058afb7:
  *(int *)(in_EAX + 0x10) = iVar5;
  pcVar8 = "WHEELS";
  iVar5 = -1;
  uVar3 = 0x57;
  do {
    iVar5 = iVar5 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar8 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar8 = pcVar8 + 1;
  } while (*pbVar1 != 0);
  if (*(int *)(iVar6 + 4) == iVar5) {
    *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(iVar6 + 0x20);
    *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(iVar6 + 0x24);
    *(undefined4 *)(in_EAX + 0x20) = *(undefined4 *)(iVar6 + 0x28);
    *(undefined4 *)(in_EAX + 0x24) = *(undefined4 *)(iVar6 + 0x2c);
    iVar6 = *(int *)(in_EAX + 0x10);
    if (iVar6 != 0) {
      puVar7 = &DAT_006ba148;
      uVar3 = 0x5f;
      do {
        iVar6 = iVar6 * 0x21 + uVar3;
        pbVar1 = puVar7 + 1;
        uVar3 = (uint)*pbVar1;
        puVar7 = puVar7 + 1;
      } while (*pbVar1 != 0);
      *(int *)(in_EAX + 0x28) = iVar6;
      return;
    }
  }
  else {
    *(undefined1 *)(in_EAX + 9) = 2;
    *(undefined1 *)(in_EAX + 10) = 2;
    *(undefined1 *)(in_EAX + 0xb) = 2;
  }
  return;
}


// ==== 0x58b050 LoadedCar::LoadedCar

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

int __fastcall
LoadedCar__LoadedCar
          (undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  
  *(undefined1 *)(param_3 + 0xc) = 0;
  *(undefined1 *)(param_3 + 0xd) = 0;
  *(undefined4 *)(param_3 + 8) = *param_2;
  *(undefined4 *)(param_3 + 0x10) = 0;
  puVar4 = (undefined4 *)(param_3 + 0x14);
  for (iVar3 = 0x78; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  piVar5 = param_2 + 0x113;
  puVar4 = (undefined4 *)(param_3 + 0x18);
  iVar3 = 0x1e;
  do {
    iVar1 = *piVar5;
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(iVar1 + 0x20);
    }
    puVar4[-1] = uVar2;
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(iVar1 + 0x24);
    }
    *puVar4 = uVar2;
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(iVar1 + 0x28);
    }
    puVar4[1] = uVar2;
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(iVar1 + 0x2c);
    }
    puVar4[2] = uVar2;
    puVar4 = puVar4 + 4;
    piVar5 = piVar5 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (param_5 != 0) {
    iVar3 = 0;
    puVar4 = (undefined4 *)(param_3 + 0x14);
    do {
      if ((DAT_006f06e0 != iVar3) && (DAT_006f06dc != iVar3 && DAT_006f06d8 != iVar3)) {
        *puVar4 = 0;
      }
      iVar3 = iVar3 + 1;
      puVar4 = puVar4 + 4;
    } while (iVar3 < 0x1e);
  }
  return param_3;
}


// ==== 0x58b110 FUN_0058b110

void FUN_0058b110(void)

{
  undefined4 *puVar1;
  
  DAT_007344ec = (undefined4 *)FUN_00566dc0(0x58,"LoadedTexturePackSlotPool",0);
  if ((DAT_007344ec != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_007344ec;
    puVar1 = DAT_007344ec;
    DAT_007344ec[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_007344ec = &DAT_0073d818;
  }
  DAT_007344f0 = (undefined4 *)FUN_00566dc0(0x5c,"LoadedSolidPackSlotPool",0);
  if ((DAT_007344f0 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_007344f0;
    puVar1 = DAT_007344f0;
    DAT_007344f0[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_007344f0 = &DAT_0073d818;
  }
  DAT_007344f4 = (undefined4 *)FUN_00566dc0(0x10,"LoadedSkinLayerSlotPool",0);
  if ((DAT_007344f4 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_007344f4;
    puVar1 = DAT_007344f4;
    DAT_007344f4[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_007344f4 = &DAT_0073d818;
  }
  DAT_007344f8 = (undefined4 *)FUN_00566dc0(0x68,"LoadedWheelSlotPool",0);
  if ((DAT_007344f8 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_007344f8;
    puVar1 = DAT_007344f8;
    DAT_007344f8[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_007344f8 = &DAT_0073d818;
  }
  DAT_007344fc = (undefined4 *)FUN_00566dc0(500,"LoadedCarSlotPool",0);
  if ((DAT_007344fc != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_007344fc;
    puVar1 = DAT_007344fc;
    DAT_007344fc[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_007344fc = &DAT_0073d818;
  }
  DAT_00734500 = (undefined4 *)FUN_00566dc0(0x1c,"LoadedRideInfoSlotPool",0);
  if ((DAT_00734500 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_00734500;
    puVar1 = DAT_00734500;
    DAT_00734500[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_00734500 = &DAT_0073d818;
  }
  DAT_007344e8 = FUN_00565b60(FUN_004e2000,0,0,0x2000);
  DAT_007301e4 = &DAT_00730358;
  bInitMemoryPool(DAT_007344e8,&DAT_006b9418);
  return;
}


// ==== 0x58b2d0 FUN_0058b2d0

void FUN_0058b2d0(void)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  
  puVar1 = in_EAX + 7;
  *puVar1 = puVar1;
  in_EAX[8] = puVar1;
  puVar1 = in_EAX + 9;
  *puVar1 = puVar1;
  in_EAX[10] = puVar1;
  puVar1 = in_EAX + 0xb;
  *puVar1 = puVar1;
  in_EAX[0xc] = puVar1;
  puVar1 = in_EAX + 0xd;
  *puVar1 = puVar1;
  in_EAX[0xe] = puVar1;
  puVar1 = in_EAX + 0xf;
  *puVar1 = puVar1;
  in_EAX[0x10] = puVar1;
  puVar1 = in_EAX + 0x11;
  *puVar1 = puVar1;
  in_EAX[0x12] = puVar1;
  puVar1 = in_EAX + 0x13;
  *puVar1 = puVar1;
  in_EAX[0x14] = puVar1;
  in_EAX[5] = 0;
  in_EAX[2] = 1;
  in_EAX[3] = 0;
  in_EAX[4] = 0;
  in_EAX[6] = 0;
  *in_EAX = 0;
  in_EAX[0x15] = 0;
  in_EAX[0x16] = 0;
  return;
}


// ==== 0x58b330 ResourceFile_OpenAndStart

/* [canon] assets med (hopper+capstone) docs/re/misc.md */

void ResourceFile_OpenAndStart(int param_1)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int unaff_EDI;
  
  if (in_EAX != 0) {
    FUN_0058cac0(param_1,0x20000,0);
    *(undefined1 *)(unaff_EDI + 0x5a) = 1;
    *(undefined4 *)(param_1 + 0x14) = 1;
    FUN_0053eed0(&DAT_00743c20,unaff_EDI + 8,FUN_0058cdc0,unaff_EDI,4);
    uVar2 = StringList_Find(&DAT_00743c20,unaff_EDI + 8);
    *(undefined4 *)(unaff_EDI + 0x50) = uVar2;
    return;
  }
  iVar1 = unaff_EDI + 8;
  uVar2 = CreateResourceFile(iVar1,6,0,0,0);
  *(undefined4 *)(unaff_EDI + 0x54) = uVar2;
  iVar3 = bOpenFile(iVar1,1,1);
  if (iVar3 == 0) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = ((int)*(uint *)(iVar3 + 4) < 0) - 1 & *(uint *)(iVar3 + 4);
    FUN_00594d40();
  }
  *(undefined1 *)(unaff_EDI + 0x5b) = 0;
  iVar3 = FUN_0058cac0(param_1,uVar4,0);
  if (iVar3 != 0) {
    *(undefined1 *)(unaff_EDI + 0x5b) = 1;
  }
  FUN_00448070(iVar1);
  *(undefined1 *)(unaff_EDI + 0x5a) = 1;
  *(undefined4 *)(param_1 + 0x14) = 1;
  ResourceFile__BeginLoading();
  return;
}


// ==== 0x58b420 FUN_0058b420

undefined4 FUN_0058b420(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *unaff_ESI;
  
  if (((short)unaff_ESI[0x16] == 0) && (*(char *)((int)unaff_ESI + 0x5a) != '\x01')) {
    if (*(char *)((int)unaff_ESI + 0x5a) == '\x02') {
      if (unaff_ESI[0x15] == 0) {
        ResourceFileList_Remove(unaff_ESI + 2,0,0);
      }
      else {
        UnloadResourceFile();
        unaff_ESI[0x15] = 0;
      }
    }
    iVar1 = *unaff_ESI;
    piVar2 = (int *)unaff_ESI[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    iVar3 = DAT_007344f0;
    iVar1 = *(int *)(DAT_007344f0 + 0x18);
    *unaff_ESI = *(int *)(DAT_007344f0 + 0x10);
    *(int *)(iVar3 + 0x18) = iVar1 + -1;
    *(int **)(iVar3 + 0x10) = unaff_ESI;
    return 1;
  }
  return 0;
}


// ==== 0x58b490 FUN_0058b490

void FUN_0058b490(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int unaff_ESI;
  
  piVar2 = (int *)FUN_0058c270(unaff_ESI);
  if (piVar2 == (int *)0x0) {
    iVar3 = FUN_00567160();
    if (iVar3 == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)FUN_0058ad80();
    }
    puVar1 = *(undefined4 **)(unaff_ESI + 0x28);
    *puVar1 = piVar2;
    *(int **)(unaff_ESI + 0x28) = piVar2;
    piVar2[1] = (int)puVar1;
    *piVar2 = unaff_ESI + 0x24;
  }
  *(short *)(piVar2 + 0x14) = (short)piVar2[0x14] + 1;
  return;
}


// ==== 0x58b4d0 FUN_0058b4d0

void __fastcall FUN_0058b4d0(int param_1)

{
  int in_EAX;
  undefined4 uVar1;
  int unaff_ESI;
  
  uVar1 = 0;
  if (in_EAX != 0) {
    uVar1 = 4;
    FUN_0058cac0(param_1,0x40000,0);
  }
  *(undefined4 *)(param_1 + 0x14) = 1;
  *(undefined1 *)(unaff_ESI + 0x52) = 1;
  FUN_0053eed0(&DAT_00740420,unaff_ESI + 8,FUN_0058cdf0,unaff_ESI,uVar1);
  uVar1 = StringList_Find(&DAT_00740420,unaff_ESI + 8);
  *(undefined4 *)(unaff_ESI + 0x54) = uVar1;
  return;
}


// ==== 0x58b520 FUN_0058b520

undefined4 FUN_0058b520(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *unaff_ESI;
  
  if (((short)unaff_ESI[0x14] == 0) && (*(char *)((int)unaff_ESI + 0x52) != '\x01')) {
    if (*(char *)((int)unaff_ESI + 0x52) == '\x02') {
      ResourceFileList_Remove(unaff_ESI + 2,0,0);
    }
    iVar1 = *unaff_ESI;
    piVar2 = (int *)unaff_ESI[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    iVar3 = DAT_007344ec;
    iVar1 = *(int *)(DAT_007344ec + 0x18);
    *unaff_ESI = *(int *)(DAT_007344ec + 0x10);
    *(int *)(iVar3 + 0x18) = iVar1 + -1;
    *(int **)(iVar3 + 0x10) = unaff_ESI;
    return 1;
  }
  return 0;
}


// ==== 0x58b580 FUN_0058b580

int * FUN_0058b580(int param_1)

{
  undefined4 *puVar1;
  undefined4 in_EAX;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar2 = (int *)FUN_0058c2c0(in_EAX);
  if (piVar2 == (int *)0x0) {
    iVar3 = FUN_00567160();
    if (iVar3 == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)LoadedCar__LoadedCar
                                (iVar3,*(undefined4 *)(param_1 + 0xc),
                                 *(undefined4 *)(param_1 + 0x10));
    }
    puVar1 = *(undefined4 **)(param_1 + 0x48);
    *puVar1 = piVar2;
    *(int **)(param_1 + 0x48) = piVar2;
    *piVar2 = param_1 + 0x44;
    piVar2[1] = (int)puVar1;
    piVar4 = (int *)FUN_0058c220(param_1);
    if (piVar4 == (int *)0x0) {
      iVar3 = FUN_00567160();
      if (iVar3 == 0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)FUN_0058adb0();
      }
      puVar1 = *(undefined4 **)(param_1 + 0x20);
      *puVar1 = piVar4;
      *(int **)(param_1 + 0x20) = piVar4;
      piVar4[1] = (int)puVar1;
      *piVar4 = param_1 + 0x1c;
    }
    *(short *)(piVar4 + 0x16) = (short)piVar4[0x16] + 1;
    piVar2[4] = (int)piVar4;
  }
  *(char *)(piVar2 + 3) = (char)piVar2[3] + '\x01';
  return piVar2;
}


// ==== 0x58b630 FUN_0058b630

undefined4 FUN_0058b630(int param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  if (*(int *)(*(int *)(unaff_EDI + 8) * 0xc90 + 0xc54 + DAT_00734588) != 2) {
    iVar1 = unaff_EDI + 0x14;
    iVar2 = FUN_0053ede0(&DAT_00743c20,iVar1,0x78,4);
    while ((iVar2 != 0 && (iVar2 = FUN_0058ca20(param_1), iVar2 != 0))) {
      iVar2 = FUN_0053ede0(&DAT_00743c20,iVar1,0x78,4);
    }
    *(undefined1 *)(unaff_EDI + 0xd) = 1;
    *(undefined4 *)(param_1 + 0x14) = 1;
    FUN_0053e9e0(&DAT_00743c20,iVar1,0x78,FUN_0058ce20,unaff_EDI,4);
    return 1;
  }
  *(undefined1 *)(unaff_EDI + 0xd) = 2;
  return 0;
}


// ==== 0x58b6c0 FUN_0058b6c0

undefined4 FUN_0058b6c0(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *unaff_EDI;
  
  if (((char)unaff_EDI[3] == '\0') && (*(char *)((int)unaff_EDI + 0xd) != '\x01')) {
    if ((*(char *)((int)unaff_EDI + 0xd) == '\x02') &&
       (*(int *)(unaff_EDI[2] * 0xc90 + 0xc54 + DAT_00734588) != 2)) {
      FUN_0053ec90(&DAT_00743c20,unaff_EDI + 5,0x78);
    }
    *(short *)(unaff_EDI[4] + 0x58) = *(short *)(unaff_EDI[4] + 0x58) + -1;
    FUN_0058b420(param_1);
    iVar1 = *unaff_EDI;
    piVar2 = (int *)unaff_EDI[1];
    unaff_EDI[4] = 0;
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    iVar3 = DAT_007344fc;
    iVar1 = *(int *)(DAT_007344fc + 0x18);
    *unaff_EDI = *(int *)(DAT_007344fc + 0x10);
    *(int *)(iVar3 + 0x18) = iVar1 + -1;
    *(int **)(iVar3 + 0x10) = unaff_EDI;
    return 1;
  }
  return 0;
}


// ==== 0x58b750 CarLoader::AllocateWheel

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

int * CarLoader__AllocateWheel(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int in_EAX;
  int iVar3;
  int *piVar4;
  
  piVar1 = (int *)(param_1 + 0x34);
  piVar4 = (int *)*piVar1;
  while( true ) {
    if (piVar4 == piVar1) {
      iVar3 = FUN_00567160();
      if (iVar3 == 0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)LoadedWheel__LoadedWheel(in_EAX);
      }
      puVar2 = *(undefined4 **)(param_1 + 0x38);
      *puVar2 = piVar4;
      *(int **)(param_1 + 0x38) = piVar4;
      piVar4[1] = (int)puVar2;
      *piVar4 = (int)piVar1;
      FUN_0058c0d0(param_1,piVar4 + 10,4);
      *(char *)(piVar4 + 2) = (char)piVar4[2] + '\x01';
      return piVar4;
    }
    if (piVar4[5] == *(int *)(in_EAX + 0x490)) break;
    piVar4 = (int *)*piVar4;
  }
  *(char *)(piVar4 + 2) = (char)piVar4[2] + '\x01';
  return piVar4;
}


// ==== 0x58b7d0 FUN_0058b7d0

undefined4 FUN_0058b7d0(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EDI;
  int local_200 [128];
  
  piVar1 = *(int **)(unaff_EDI + 0x34);
  iVar2 = 0;
  if (piVar1 != (int *)(unaff_EDI + 0x34)) {
    do {
      if (*(char *)((int)piVar1 + 9) == '\0') {
        *(undefined1 *)((int)piVar1 + 9) = 1;
        if (piVar1[6] != 0) {
          local_200[iVar2] = piVar1[6];
          iVar2 = iVar2 + 1;
        }
        if (piVar1[7] != 0) {
          local_200[iVar2] = piVar1[7];
          iVar2 = iVar2 + 1;
        }
        if (piVar1[8] != 0) {
          local_200[iVar2] = piVar1[8];
          iVar2 = iVar2 + 1;
        }
        if (piVar1[9] != 0) {
          local_200[iVar2] = piVar1[9];
          iVar2 = iVar2 + 1;
        }
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)(unaff_EDI + 0x34));
    if (0 < iVar2) {
      *(undefined4 *)(unaff_EDI + 0x14) = 1;
      FUN_0053e9e0(&DAT_00743c20,local_200,iVar2,FUN_0058ce50,0,4);
      return 1;
    }
  }
  return 0;
}


// ==== 0x58b860 FUN_0058b860

void FUN_0058b860(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x34);
  while (puVar2 != (undefined4 *)(param_1 + 0x34)) {
    puVar1 = (undefined4 *)*puVar2;
    if (*(char *)((int)puVar2 + 9) == '\x01') {
      *(undefined1 *)((int)puVar2 + 9) = 2;
    }
    FUN_0058ba80(param_1);
    puVar2 = puVar1;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  FUN_0058cbb0();
  return;
}


// ==== 0x58b8a0 FUN_0058b8a0

undefined4 FUN_0058b8a0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 local_200 [128];
  
  piVar3 = *(int **)(param_1 + 0x34);
  iVar4 = 0;
  if (piVar3 != (int *)(param_1 + 0x34)) {
    do {
      if (*(char *)((int)piVar3 + 10) == '\0') {
        iVar1 = piVar3[0x12];
        iVar2 = 0;
        if ((iVar1 != 0) && (*(char *)(iVar1 + 0xe) == '\0')) {
          local_200[iVar4] = *(undefined4 *)(iVar1 + 8);
          *(undefined1 *)(iVar1 + 0xe) = 1;
          iVar2 = 1;
        }
        iVar1 = piVar3[0x13];
        if ((iVar1 != 0) && (*(char *)(iVar1 + 0xe) == '\0')) {
          *(undefined1 *)(iVar1 + 0xe) = 1;
          local_200[iVar2 + iVar4] = *(undefined4 *)(iVar1 + 8);
          iVar2 = iVar2 + 1;
        }
        iVar1 = piVar3[0x14];
        if ((iVar1 != 0) && (*(char *)(iVar1 + 0xe) == '\0')) {
          *(undefined1 *)(iVar1 + 0xe) = 1;
          local_200[iVar2 + iVar4] = *(undefined4 *)(iVar1 + 8);
          iVar2 = iVar2 + 1;
        }
        iVar1 = piVar3[0x15];
        if ((iVar1 != 0) && (*(char *)(iVar1 + 0xe) == '\0')) {
          *(undefined1 *)(iVar1 + 0xe) = 1;
          local_200[iVar2 + iVar4] = *(undefined4 *)(iVar1 + 8);
          iVar2 = iVar2 + 1;
        }
        *(char *)((int)piVar3 + 10) = (iVar2 == 0) + '\x01';
        iVar4 = iVar4 + iVar2;
      }
      if (*(char *)((int)piVar3 + 0xb) == '\0') {
        *(undefined1 *)((int)piVar3 + 0xb) = 2;
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)(param_1 + 0x34));
    if (0 < iVar4) {
      *(undefined4 *)(param_1 + 0x14) = 1;
      FUN_0053e9e0(&DAT_00740420,local_200,iVar4,FUN_0058ce60,0,0);
      return 1;
    }
  }
  return 0;
}


// ==== 0x58b9a0 FUN_0058b9a0

void FUN_0058b9a0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 0x34);
  while (puVar3 != (undefined4 *)(param_1 + 0x34)) {
    puVar1 = (undefined4 *)*puVar3;
    if (*(char *)((int)puVar3 + 10) == '\x01') {
      *(undefined1 *)((int)puVar3 + 10) = 2;
      iVar2 = puVar3[0x12];
      if ((iVar2 != 0) && (*(char *)(iVar2 + 0xe) == '\x01')) {
        *(undefined1 *)(iVar2 + 0xe) = 2;
      }
      iVar2 = puVar3[0x13];
      if ((iVar2 != 0) && (*(char *)(iVar2 + 0xe) == '\x01')) {
        *(undefined1 *)(iVar2 + 0xe) = 2;
      }
      iVar2 = puVar3[0x14];
      if ((iVar2 != 0) && (*(char *)(iVar2 + 0xe) == '\x01')) {
        *(undefined1 *)(iVar2 + 0xe) = 2;
      }
      iVar2 = puVar3[0x15];
      if ((iVar2 != 0) && (*(char *)(iVar2 + 0xe) == '\x01')) {
        *(undefined1 *)(iVar2 + 0xe) = 2;
      }
    }
    if (*(char *)((int)puVar3 + 0xb) == '\x01') {
      *(undefined1 *)((int)puVar3 + 0xb) = 2;
      iVar2 = puVar3[0x16];
      if ((iVar2 != 0) && (*(char *)(iVar2 + 0xe) == '\x01')) {
        *(undefined1 *)(iVar2 + 0xe) = 2;
      }
      iVar2 = puVar3[0x17];
      if ((iVar2 != 0) && (*(char *)(iVar2 + 0xe) == '\x01')) {
        *(undefined1 *)(iVar2 + 0xe) = 2;
      }
      iVar2 = puVar3[0x18];
      if ((iVar2 != 0) && (*(char *)(iVar2 + 0xe) == '\x01')) {
        *(undefined1 *)(iVar2 + 0xe) = 2;
      }
      iVar2 = puVar3[0x19];
      if ((iVar2 != 0) && (*(char *)(iVar2 + 0xe) == '\x01')) {
        *(undefined1 *)(iVar2 + 0xe) = 2;
      }
    }
    FUN_0058ba80(param_1);
    puVar3 = puVar1;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  FUN_0058cbb0();
  return;
}


// ==== 0x58ba80 FUN_0058ba80

undefined4 FUN_0058ba80(undefined4 param_1)

{
  short *psVar1;
  int iVar2;
  int *piVar3;
  int *unaff_ESI;
  int iVar4;
  undefined1 local_200 [512];
  
  if (((((char)unaff_ESI[2] == '\0') && (*(char *)((int)unaff_ESI + 9) != '\x01')) &&
      (*(char *)((int)unaff_ESI + 10) != '\x01')) && (*(char *)((int)unaff_ESI + 0xb) != '\x01')) {
    iVar4 = 4;
    piVar3 = unaff_ESI + 0x12;
    do {
      if (*piVar3 != 0) {
        psVar1 = (short *)(*piVar3 + 0xc);
        *psVar1 = *psVar1 + -1;
      }
      piVar3 = piVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar4 = FUN_0058c1c0(param_1,local_200,0x80,unaff_ESI + 0x12);
    if (iVar4 != 0) {
      FUN_0053ec90(&DAT_00740420,local_200,iVar4);
    }
    if (*(char *)((int)unaff_ESI + 9) == '\x02') {
      FUN_0053ec90(&DAT_00743c20,unaff_ESI + 6,4);
    }
    iVar4 = *unaff_ESI;
    piVar3 = (int *)unaff_ESI[1];
    *piVar3 = iVar4;
    *(int **)(iVar4 + 4) = piVar3;
    iVar2 = DAT_007344f8;
    iVar4 = *(int *)(DAT_007344f8 + 0x18);
    *unaff_ESI = *(int *)(DAT_007344f8 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar4 + -1;
    *(int **)(iVar2 + 0x10) = unaff_ESI;
    return 1;
  }
  return 0;
}


// ==== 0x58bb50 CarLoader::AllocateSkin

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

int * CarLoader__AllocateSkin(int param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined1 local_9c [144];
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686b1b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_0058adf0(0xf80);
  piVar4 = (int *)0x0;
  local_4 = 0;
  if (iVar2 != 0) {
    piVar4 = (int *)LoadedSkin__LoadedSkin(param_2,*(undefined4 *)(param_1 + 0xc));
  }
  puVar1 = *(undefined4 **)(param_1 + 0x40);
  *puVar1 = piVar4;
  *(int **)(param_1 + 0x40) = piVar4;
  *piVar4 = param_1 + 0x3c;
  piVar4[1] = (int)puVar1;
  iVar2 = *param_2 * 0xc90 + DAT_00734588;
  local_4 = 0xffffffff;
  if (piVar4[0x2e9] == 0) {
    FUN_00565da0("CARS\\%s\\TEXTURES.BIN",iVar2);
    iVar3 = FUN_0058b490();
    piVar4[0x2e9] = iVar3;
  }
  if ((piVar4[0x2ea] == 0) && (*(int *)(piVar4[0x120] * 0xc90 + 0xc54 + DAT_00734588) != 2)) {
    FUN_00565da0("CARS\\%s\\VINYLS.BIN",iVar2);
    iVar2 = bOpenFile(local_9c,0,1);
    if (iVar2 != 0) {
      iVar2 = *(int *)(iVar2 + 4);
      FUN_00594d40();
      if (iVar2 != -1) {
        iVar2 = FUN_0058b490();
        piVar4[0x2ea] = iVar2;
      }
    }
  }
  piVar4[0x2eb] = piVar4[0xf2];
  FUN_0058c0d0(param_1,piVar4 + 2,piVar4[0xf2]);
  piVar4[0x364] = piVar4[0xf3];
  FUN_0058c0d0(param_1,piVar4 + 0x7a,piVar4[0xf3]);
  *(char *)(piVar4 + 0x2e8) = (char)piVar4[0x2e8] + '\x01';
  ExceptionList = local_c;
  return piVar4;
}


// ==== 0x58bce0 FUN_0058bce0

undefined4 FUN_0058bce0(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_1e0 [480];
  
  if (param_3 == 0) {
    iVar1 = FUN_0058c180(param_1,local_1e0,0x78);
    *(char *)(param_2 + 0xba2) = (iVar1 == 0) + '\x01';
  }
  else {
    iVar1 = FUN_0058c180(param_1,local_1e0,0x78);
    *(char *)(param_2 + 0xba1) = (iVar1 == 0) + '\x01';
  }
  if (0 < iVar1) {
    uVar2 = 0;
    if ((param_3 != 0) || (*(int *)(param_1 + 0xc) != 0)) {
      uVar2 = 4;
      FUN_0058cac0(param_1,0x8c000,0x8c000);
    }
    *(undefined4 *)(param_1 + 0x14) = 1;
    FUN_0053e9e0(&DAT_00740420,local_1e0,iVar1,FUN_0058ce70,param_2,uVar2);
    return 1;
  }
  return 0;
}


// ==== 0x58bdc0 FUN_0058bdc0

void FUN_0058bdc0(void)

{
  int iVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  int unaff_EDI;
  
  if (*(char *)(in_EAX + 0xba1) == '\x01') {
    iVar3 = *(int *)(in_EAX + 0xbac);
    *(undefined1 *)(in_EAX + 0xba1) = 2;
    if (0 < iVar3) {
      piVar2 = (int *)(in_EAX + 0xbb0);
      do {
        iVar1 = *piVar2;
        if ((iVar1 != 0) && (*(char *)(iVar1 + 0xe) == '\x01')) {
          *(undefined1 *)(iVar1 + 0xe) = 2;
        }
        piVar2 = piVar2 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  if (*(char *)(in_EAX + 0xba2) == '\x01') {
    iVar3 = *(int *)(in_EAX + 0xd90);
    *(undefined1 *)(in_EAX + 0xba2) = 2;
    if (0 < iVar3) {
      piVar2 = (int *)(in_EAX + 0xd94);
      do {
        iVar1 = *piVar2;
        if ((iVar1 != 0) && (*(char *)(iVar1 + 0xe) == '\x01')) {
          *(undefined1 *)(iVar1 + 0xe) = 2;
        }
        piVar2 = piVar2 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  FUN_0058bf40(unaff_EDI);
  *(undefined4 *)(unaff_EDI + 0x14) = 0;
  FUN_0058cbb0();
  return;
}


// ==== 0x58be50 FUN_0058be50

void FUN_0058be50(void)

{
  int unaff_ESI;
  
  CompositeSkin(unaff_ESI + 0x480);
  *(undefined1 *)(unaff_ESI + 0xba3) = 1;
  return;
}


// ==== 0x58be70 FUN_0058be70

char FUN_0058be70(int param_1)

{
  short *psVar1;
  undefined4 in_EAX;
  int *piVar2;
  int iVar3;
  int unaff_EDI;
  char cVar4;
  undefined1 local_1e0 [480];
  
  if (((*(char *)(unaff_EDI + 0xba2) != '\x02') || (*(char *)(unaff_EDI + 0xba3) == '\0')) &&
     (param_1 == 0)) {
    return '\0';
  }
  iVar3 = *(int *)(unaff_EDI + 0xd90);
  if (0 < iVar3) {
    piVar2 = (int *)(unaff_EDI + 0xd94);
    do {
      if (*piVar2 != 0) {
        psVar1 = (short *)(*piVar2 + 0xc);
        *psVar1 = *psVar1 + -1;
      }
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  iVar3 = FUN_0058c1c0(in_EAX,local_1e0,0x78,unaff_EDI + 0xd94);
  cVar4 = iVar3 != 0;
  *(undefined4 *)(unaff_EDI + 0xd90) = 0;
  if ((bool)cVar4) {
    FUN_0053ec90(&DAT_00740420,local_1e0,iVar3);
  }
  if (*(int *)(unaff_EDI + 0xba8) != 0) {
    psVar1 = (short *)(*(int *)(unaff_EDI + 0xba8) + 0x50);
    *psVar1 = *psVar1 + -1;
    FUN_0058b520(in_EAX);
    *(undefined4 *)(unaff_EDI + 0xba8) = 0;
    cVar4 = cVar4 + '\x01';
  }
  return cVar4;
}


// ==== 0x58bf40 FUN_0058bf40

undefined4 FUN_0058bf40(undefined4 param_1)

{
  int *piVar1;
  int *in_EAX;
  int iVar2;
  undefined4 extraout_EDX;
  undefined1 local_1e0 [480];
  
  if ((((char)in_EAX[0x2e8] == '\0') && (*(char *)((int)in_EAX + 0xba1) != '\x01')) &&
     (*(char *)((int)in_EAX + 0xba2) != '\x01')) {
    FUN_0058be70(1);
    FUN_0058c160(param_1);
    iVar2 = FUN_0058c1c0(param_1,local_1e0,0x78,extraout_EDX);
    if (iVar2 != 0) {
      FUN_0053ec90(&DAT_00740420,local_1e0,iVar2);
    }
    *(short *)(in_EAX[0x2e9] + 0x50) = *(short *)(in_EAX[0x2e9] + 0x50) + -1;
    FUN_0058b520(param_1);
    iVar2 = *in_EAX;
    piVar1 = (int *)in_EAX[1];
    in_EAX[0x2e9] = 0;
    *piVar1 = iVar2;
    *(int **)(iVar2 + 4) = piVar1;
    FUN_00565ce0();
    return 1;
  }
  return 0;
}


// ==== 0x58c010 FUN_0058c010

undefined4 FUN_0058c010(void)

{
  int iVar1;
  code *pcVar2;
  code *pcVar3;
  code *in_EAX;
  int iVar4;
  int iVar5;
  code *pcVar6;
  
  pcVar3 = DAT_007344e8;
  if (((in_EAX[0xba1] != (code)0x2) || (in_EAX[0xba2] != (code)0x2)) || (in_EAX[0xba3] == (code)0x0)
     ) {
    return 0;
  }
  if (((DAT_007344e8 != (code *)0x0) && (DAT_007344e8 <= in_EAX)) &&
     ((in_EAX < FUN_004e2000 + (int)DAT_007344e8 &&
      ((*(int *)(*(int *)(in_EAX + 0xba4) + 0x54) != 0 &&
       (*(char *)(*(int *)(*(int *)(in_EAX + 0xba4) + 0x54) + 0x8a) != '\0')))))) {
    iVar1 = *(int *)(in_EAX + 0xbac);
    iVar5 = 0;
    if (0 < iVar1) {
      pcVar6 = in_EAX + 0xbb0;
      do {
        if (*(char *)(*(int *)pcVar6 + 0xe) != '\x02') {
          return 0;
        }
        iVar4 = FUN_0053e620(&DAT_00740420,*(undefined4 *)(*(int *)pcVar6 + 8));
        if ((iVar4 != 0) && (pcVar2 = *(code **)(iVar4 + 0x10), pcVar2 != (code *)0x0)) {
          if (pcVar2 < pcVar3) {
            return 0;
          }
          if (FUN_004e2000 + (int)pcVar3 <= pcVar2) {
            return 0;
          }
        }
        iVar5 = iVar5 + 1;
        pcVar6 = pcVar6 + 4;
      } while (iVar5 < iVar1);
    }
    return 1;
  }
  return 0;
}


// ==== 0x58c0d0 FUN_0058c0d0

void __thiscall FUN_0058c0d0(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *in_EAX;
  undefined4 *puVar3;
  int iVar4;
  
  if (0 < param_1) {
    iVar4 = param_3 - (int)in_EAX;
    param_3 = param_1;
    do {
      iVar1 = *(int *)(iVar4 + (int)in_EAX);
      if (iVar1 != 0) {
        for (puVar3 = *(undefined4 **)(param_2 + 0x2c); puVar3 != (undefined4 *)(param_2 + 0x2c);
            puVar3 = (undefined4 *)*puVar3) {
          if (puVar3[2] == iVar1) goto LAB_0058c13b;
        }
        puVar3 = (undefined4 *)FUN_00567160();
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          puVar3[2] = iVar1;
          *(undefined2 *)(puVar3 + 3) = 0;
          *(undefined1 *)((int)puVar3 + 0xe) = 0;
          *(undefined1 *)((int)puVar3 + 0xf) = 0;
        }
        puVar2 = *(undefined4 **)(param_2 + 0x30);
        *puVar2 = puVar3;
        *(undefined4 **)(param_2 + 0x30) = puVar3;
        puVar3[1] = puVar2;
        *puVar3 = (undefined4 *)(param_2 + 0x2c);
LAB_0058c13b:
        *(short *)(puVar3 + 3) = *(short *)(puVar3 + 3) + 1;
        *in_EAX = puVar3;
      }
      in_EAX = in_EAX + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}


// ==== 0x58c160 FUN_0058c160

void __fastcall FUN_0058c160(undefined4 param_1,int param_2)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  
  iVar3 = 0;
  if (0 < unaff_ESI) {
    do {
      iVar2 = *(int *)(param_2 + iVar3 * 4);
      if (iVar2 != 0) {
        psVar1 = (short *)(iVar2 + 0xc);
        *psVar1 = *psVar1 + -1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < unaff_ESI);
  }
  return;
}


// ==== 0x58c180 FUN_0058c180

void FUN_0058c180(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar2 = 0;
  iVar3 = 0;
  if (0 < unaff_ESI) {
    do {
      iVar1 = *(int *)(unaff_EDI + iVar3 * 4);
      if ((iVar1 != 0) && (*(char *)(iVar1 + 0xe) == '\0')) {
        *(undefined1 *)(iVar1 + 0xe) = 1;
        *(undefined4 *)(param_2 + iVar2 * 4) = *(undefined4 *)(iVar1 + 8);
        iVar2 = iVar2 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < unaff_ESI);
  }
  return;
}


// ==== 0x58c1c0 FUN_0058c1c0

int FUN_0058c1c0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int in_EAX;
  int iVar5;
  int iVar6;
  
  iVar4 = DAT_007344f4;
  iVar6 = 0;
  iVar5 = 0;
  if (0 < in_EAX) {
    do {
      piVar1 = *(int **)(param_4 + iVar5 * 4);
      if ((piVar1 != (int *)0x0) && ((short)piVar1[3] == 0)) {
        if (*(char *)((int)piVar1 + 0xe) == '\x02') {
          *(int *)(param_2 + iVar6 * 4) = piVar1[2];
          iVar6 = iVar6 + 1;
        }
        iVar2 = *piVar1;
        piVar3 = (int *)piVar1[1];
        *piVar3 = iVar2;
        *(int **)(iVar2 + 4) = piVar3;
        iVar2 = *(int *)(iVar4 + 0x18);
        *piVar1 = *(int *)(iVar4 + 0x10);
        *(int *)(iVar4 + 0x18) = iVar2 + -1;
        *(int **)(iVar4 + 0x10) = piVar1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < in_EAX);
  }
  return iVar6;
}


// ==== 0x58c220 FUN_0058c220

undefined4 * FUN_0058c220(int param_1)

{
  char cVar1;
  char cVar2;
  undefined4 *puVar3;
  char *pcVar4;
  char *unaff_EDI;
  
  puVar3 = *(undefined4 **)(param_1 + 0x1c);
  do {
    if (puVar3 == (undefined4 *)(param_1 + 0x1c)) {
      return (undefined4 *)0x0;
    }
    pcVar4 = unaff_EDI;
    do {
      cVar1 = pcVar4[(int)puVar3 + (8 - (int)unaff_EDI)];
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      if ((cVar1 == '\0') || (cVar2 == '\0')) break;
    } while (cVar1 == cVar2);
    if (cVar1 == cVar2) {
      return puVar3;
    }
    puVar3 = (undefined4 *)*puVar3;
  } while( true );
}


// ==== 0x58c270 FUN_0058c270

undefined4 * FUN_0058c270(int param_1)

{
  char cVar1;
  char cVar2;
  undefined4 *puVar3;
  char *pcVar4;
  char *unaff_EDI;
  
  puVar3 = *(undefined4 **)(param_1 + 0x24);
  do {
    if (puVar3 == (undefined4 *)(param_1 + 0x24)) {
      return (undefined4 *)0x0;
    }
    pcVar4 = unaff_EDI;
    do {
      cVar1 = pcVar4[(int)puVar3 + (8 - (int)unaff_EDI)];
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      if ((cVar1 == '\0') || (cVar2 == '\0')) break;
    } while (cVar1 == cVar2);
    if (cVar1 == cVar2) {
      return puVar3;
    }
    puVar3 = (undefined4 *)*puVar3;
  } while( true );
}


// ==== 0x58c2c0 FUN_0058c2c0

undefined4 * FUN_0058c2c0(void)

{
  undefined4 *puVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  bool bVar4;
  undefined1 local_1f4 [8];
  int local_1ec;
  int aiStack_1e0 [120];
  
  LoadedCar__LoadedCar(local_1f4,*(undefined4 *)(in_EAX + 0xc),*(undefined4 *)(in_EAX + 0x10));
  puVar1 = *(undefined4 **)(in_EAX + 0x44);
  do {
    if (puVar1 == (undefined4 *)(in_EAX + 0x44)) {
      return (undefined4 *)0x0;
    }
    if (puVar1[2] == local_1ec) {
      if (*(int *)(puVar1[2] * 0xc90 + 0xc54 + DAT_00734588) == 2) {
        return puVar1;
      }
      bVar4 = false;
      iVar3 = 0;
      do {
        if (0x77 < iVar3) {
          if (!bVar4) {
            return puVar1;
          }
          break;
        }
        for (iVar2 = 0; (!bVar4 && (iVar2 < 4)); iVar2 = iVar2 + 1) {
          bVar4 = aiStack_1e0[iVar3 + iVar2] != puVar1[iVar3 + iVar2 + 5];
        }
        iVar3 = iVar3 + 4;
      } while (!bVar4);
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}


// ==== 0x58c370 FUN_0058c370

undefined4 __fastcall FUN_0058c370(int param_1)

{
  int iVar1;
  
  if ((((*(int *)(param_1 + 0x10) != 0) && (*(char *)(*(int *)(param_1 + 0x10) + 0xd) == '\x02')) &&
      (*(int *)(param_1 + 0x14) != 0)) &&
     ((*(char *)(*(int *)(param_1 + 0x14) + 9) == '\x02' && (*(int *)(param_1 + 0x18) != 0)))) {
    iVar1 = FUN_0058ae50();
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// ==== 0x58c3b0 CarLoader::AllocateRideInfo

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

int * CarLoader__AllocateRideInfo(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  
  iVar4 = 1000;
  iVar3 = DAT_00734500;
  if (*(int *)(DAT_00734500 + 0x18) != *(int *)(DAT_00734500 + 0x2c)) {
LAB_0058c412:
    if ((*(int *)(iVar3 + 0x10) == 0) && ((*(byte *)(iVar3 + 0x14) & 1) != 0)) {
      FUN_00566e60();
    }
    piVar5 = *(int **)(iVar3 + 0x10);
    iVar4 = *(int *)(iVar3 + 0x18) + 1;
    if (piVar5 == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      iVar1 = *piVar5;
      if (*(int *)(iVar3 + 0x1c) < iVar4) {
        *(int *)(iVar3 + 0x1c) = iVar4;
      }
      *(int *)(iVar3 + 0x18) = iVar4;
      *(int *)(iVar3 + 0x10) = iVar1;
      if (((*(byte *)(iVar3 + 0x14) & 2) != 0) &&
         (iVar3 = *(int *)(iVar3 + 0x28) >> 2, piVar6 = piVar5, 0 < iVar3)) {
        for (; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar6 = 0;
          piVar6 = piVar6 + 1;
        }
      }
      piVar5[2] = 0;
      piVar5[3] = *param_2 * 0xc90 + DAT_00734588;
      piVar5[4] = 0;
      piVar5[5] = 0;
      piVar5[6] = 0;
    }
    puVar2 = *(undefined4 **)(param_1 + 0x50);
    *puVar2 = piVar5;
    *(int **)(param_1 + 0x50) = piVar5;
    piVar5[1] = (int)puVar2;
    *piVar5 = param_1 + 0x4c;
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
    if (piVar5[2] == 0) {
      *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
      if (piVar5[4] == 0) {
        iVar3 = FUN_0058b580(param_1);
        piVar5[4] = iVar3;
      }
      if (piVar5[5] == 0) {
        iVar3 = CarLoader__AllocateWheel(param_1);
        piVar5[5] = iVar3;
      }
      if (piVar5[6] == 0) {
        iVar3 = CarLoader__AllocateSkin(param_1,param_2);
        piVar5[6] = iVar3;
      }
    }
    piVar5[2] = piVar5[2] + 1;
    return piVar5;
  }
LAB_0058c3d0:
  iVar4 = iVar4 + -1;
  if (iVar4 != 0) {
    for (iVar1 = *(int *)(param_1 + 0x50); iVar1 != param_1 + 0x4c; iVar1 = *(int *)(iVar1 + 4)) {
      if (*(int *)(iVar1 + 8) == 0) goto LAB_0058c3f0;
    }
    goto LAB_0058c40a;
  }
  goto LAB_0058c412;
LAB_0058c3f0:
  do {
    iVar3 = CarLoader__UnloadRideInfo(param_1,iVar1,0);
  } while (iVar3 != 0);
  CarLoader__DeleteUnusedRideInfos();
  iVar3 = DAT_00734500;
LAB_0058c40a:
  if (*(int *)(iVar3 + 0x18) != *(int *)(iVar3 + 0x2c)) goto LAB_0058c412;
  goto LAB_0058c3d0;
}


// ==== 0x58c500 FUN_0058c500

undefined4 FUN_0058c500(int param_1)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  
  piVar1 = (int *)(param_1 + 8);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    *(int *)(in_EAX + 0x58) = *(int *)(in_EAX + 0x58) + -1;
    iVar2 = *(int *)(param_1 + 0x18);
    if (((iVar2 != 0) && (*(char *)(iVar2 + 0xba1) == '\0')) && (*(char *)(iVar2 + 0xba2) == '\0'))
    {
      *(char *)(iVar2 + 0xba0) = *(char *)(iVar2 + 0xba0) + -1;
      FUN_0058bf40(in_EAX);
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    iVar2 = *(int *)(param_1 + 0x14);
    if ((iVar2 != 0) && (*(char *)(iVar2 + 9) == '\0')) {
      *(char *)(iVar2 + 8) = *(char *)(iVar2 + 8) + -1;
      FUN_0058ba80(in_EAX);
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
    iVar2 = *(int *)(param_1 + 0x10);
    if ((iVar2 != 0) && (*(char *)(iVar2 + 0xd) == '\0')) {
      *(char *)(iVar2 + 0xc) = *(char *)(iVar2 + 0xc) + -1;
      FUN_0058b6c0(in_EAX);
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    return 1;
  }
  return 0;
}


// ==== 0x58c5a0 CarLoader::UnloadRideInfo

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

undefined4 CarLoader__UnloadRideInfo(undefined4 param_1,int param_2,int param_3)

{
  short *psVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  char cVar6;
  undefined1 local_1e0 [480];
  
  iVar3 = *(int *)(param_2 + 0x18);
  if (((((iVar3 != 0) && (*(char *)(iVar3 + 0xba1) == '\x02')) &&
       (*(char *)(iVar3 + 0xba2) == '\x02')) &&
      ((*(char *)(iVar3 + 0xba3) != '\0' && (*(char *)(iVar3 + 0xba2) == '\x02')))) &&
     (*(char *)(iVar3 + 0xba3) != '\0')) {
    iVar5 = *(int *)(iVar3 + 0xd90);
    if (0 < iVar5) {
      piVar4 = (int *)(iVar3 + 0xd94);
      do {
        if (*piVar4 != 0) {
          psVar1 = (short *)(*piVar4 + 0xc);
          *psVar1 = *psVar1 + -1;
        }
        piVar4 = piVar4 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    iVar5 = FUN_0058c1c0(param_1,local_1e0,0x78,iVar3 + 0xd94);
    cVar6 = iVar5 != 0;
    *(undefined4 *)(iVar3 + 0xd90) = 0;
    if ((bool)cVar6) {
      FUN_0053ec90(&DAT_00740420,local_1e0,iVar5);
    }
    if (*(int *)(iVar3 + 0xba8) != 0) {
      psVar1 = (short *)(*(int *)(iVar3 + 0xba8) + 0x50);
      *psVar1 = *psVar1 + -1;
      FUN_0058b520(param_1);
      *(undefined4 *)(iVar3 + 0xba8) = 0;
      cVar6 = cVar6 + '\x01';
    }
    if (cVar6 != '\0') {
      return 1;
    }
  }
  if (*(int *)(param_2 + 8) == 0) {
    iVar3 = *(int *)(param_2 + 0x18);
    if ((iVar3 != 0) && ((param_3 == 0 || (iVar5 = FUN_0058c010(param_1), iVar5 == 0)))) {
      pcVar2 = (char *)(iVar3 + 0xba0);
      *pcVar2 = *pcVar2 + -1;
      FUN_0058bf40(param_1);
      *(undefined4 *)(param_2 + 0x18) = 0;
      return 1;
    }
    if (*(int *)(param_2 + 0x14) != 0) {
      pcVar2 = (char *)(*(int *)(param_2 + 0x14) + 8);
      *pcVar2 = *pcVar2 + -1;
      FUN_0058ba80(param_1);
      *(undefined4 *)(param_2 + 0x14) = 0;
      return 1;
    }
    iVar3 = *(int *)(param_2 + 0x10);
    if (iVar3 != 0) {
      if ((param_3 != 0) && (iVar5 = FUN_0058c970(param_1), iVar5 != 0)) {
        return 0;
      }
      pcVar2 = (char *)(iVar3 + 0xc);
      *pcVar2 = *pcVar2 + -1;
      FUN_0058b6c0(param_1);
      *(undefined4 *)(param_2 + 0x10) = 0;
      return 1;
    }
  }
  return 0;
}


// ==== 0x58c760 CarLoader::DeleteUnusedRideInfos

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void CarLoader__DeleteUnusedRideInfos(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int unaff_EDI;
  
  iVar5 = DAT_00734500;
  piVar1 = *(int **)(unaff_EDI + 0x4c);
  while (piVar4 = piVar1, piVar4 != (int *)(unaff_EDI + 0x4c)) {
    piVar1 = (int *)*piVar4;
    if ((((piVar4[2] == 0) && (piVar4[4] == 0)) && (piVar4[5] == 0)) && (piVar4[6] == 0)) {
      piVar2 = (int *)piVar4[1];
      *piVar2 = (int)piVar1;
      piVar1[1] = (int)piVar2;
      iVar3 = *(int *)(iVar5 + 0x18);
      *piVar4 = *(int *)(iVar5 + 0x10);
      *(int **)(iVar5 + 0x10) = piVar4;
      *(int *)(iVar5 + 0x18) = iVar3 + -1;
      *(int *)(unaff_EDI + 0x54) = *(int *)(unaff_EDI + 0x54) + -1;
    }
  }
  return;
}


// ==== 0x58c7c0 FUN_0058c7c0

void FUN_0058c7c0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0xc) == 0) {
    uVar3 = DAT_006f227c ^ 0x1d872b41;
    uVar5 = uVar3 >> 5 ^ uVar3;
    DAT_006f227c = uVar5 << 0x1b ^ uVar5 ^ uVar3;
  }
  puVar1 = (undefined4 *)(unaff_EDI + 0x4c);
  for (puVar2 = *(undefined4 **)(unaff_EDI + 0x4c); puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2
      ) {
    puVar2[2] = 0;
  }
  iVar4 = *(int *)(unaff_EDI + 0x14);
  *(undefined4 *)(unaff_EDI + 0x58) = 0;
  while (iVar4 != 0) {
    ServiceResourceLoading();
    iVar4 = *(int *)(unaff_EDI + 0x14);
  }
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    iVar4 = CarLoader__UnloadRideInfo(unaff_EDI,puVar2,1);
    while (iVar4 != 0) {
      iVar4 = CarLoader__UnloadRideInfo(unaff_EDI,puVar2,1);
    }
  }
  return;
}


// ==== 0x58c840 FUN_0058c840

void FUN_0058c840(int param_1)

{
  short *psVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined1 local_1e0 [480];
  
  piVar5 = *(int **)(param_1 + 0x3c);
  iVar6 = DAT_007344ec;
  if (piVar5 != (int *)(param_1 + 0x3c)) {
    do {
      if ((*(char *)((int)piVar5 + 0xba2) == '\x02') && (*(char *)((int)piVar5 + 0xba3) != '\0')) {
        iVar4 = piVar5[0x364];
        if (0 < iVar4) {
          piVar3 = piVar5 + 0x365;
          do {
            if (*piVar3 != 0) {
              psVar1 = (short *)(*piVar3 + 0xc);
              *psVar1 = *psVar1 + -1;
            }
            piVar3 = piVar3 + 1;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        iVar4 = FUN_0058c1c0(param_1,local_1e0,0x78,piVar5 + 0x365);
        piVar5[0x364] = 0;
        if (iVar4 != 0) {
          FUN_0053ec90(&DAT_00740420,local_1e0,iVar4);
          iVar6 = DAT_007344ec;
        }
        if (piVar5[0x2ea] != 0) {
          psVar1 = (short *)(piVar5[0x2ea] + 0x50);
          *psVar1 = *psVar1 + -1;
          piVar3 = (int *)piVar5[0x2ea];
          if (((short)piVar3[0x14] == 0) && (*(char *)((int)piVar3 + 0x52) != '\x01')) {
            if (*(char *)((int)piVar3 + 0x52) == '\x02') {
              ResourceFileList_Remove(piVar3 + 2,0,0);
              iVar6 = DAT_007344ec;
            }
            iVar4 = *piVar3;
            piVar2 = (int *)piVar3[1];
            *piVar2 = iVar4;
            *(int **)(iVar4 + 4) = piVar2;
            iVar4 = *(int *)(iVar6 + 0x18);
            *piVar3 = *(int *)(iVar6 + 0x10);
            *(int *)(iVar6 + 0x18) = iVar4 + -1;
            *(int **)(iVar6 + 0x10) = piVar3;
          }
          piVar5[0x2ea] = 0;
        }
      }
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)(param_1 + 0x3c));
  }
  return;
}


// ==== 0x58c970 FUN_0058c970

undefined4 __fastcall FUN_0058c970(undefined4 param_1,int param_2)

{
  char cVar1;
  code *pcVar2;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int local_4;
  
  pcVar3 = DAT_007344e8;
  if (*(char *)(param_2 + 0xd) == '\x02') {
    iVar7 = *(int *)(param_2 + 0x10);
    if (*(int *)(iVar7 + 0x50) == 0) {
      if (*(int *)(iVar7 + 0x54) == 0) {
        return 0;
      }
      cVar1 = *(char *)(iVar7 + 0x5b);
    }
    else {
      cVar1 = *(char *)(*(int *)(iVar7 + 0x50) + 0x8a);
    }
    if (cVar1 != '\0') {
      local_4 = 0;
      piVar5 = (int *)(param_2 + 0x14);
      do {
        iVar7 = 0;
        piVar6 = piVar5;
        do {
          if ((((*piVar6 != 0) && (iVar4 = FUN_0053e620(&DAT_00743c20,*piVar6), iVar4 != 0)) &&
              (pcVar2 = *(code **)(iVar4 + 0x10), pcVar2 != (code *)0x0)) &&
             (((pcVar3 == (code *)0x0 || (pcVar2 < pcVar3)) ||
              (FUN_004e2000 + (int)pcVar3 <= pcVar2)))) {
            return 0;
          }
          iVar7 = iVar7 + 1;
          piVar6 = piVar6 + 1;
        } while (iVar7 < 4);
        local_4 = local_4 + 1;
        piVar5 = piVar5 + 4;
        if (0x1d < local_4) {
          return 1;
        }
      } while( true );
    }
  }
  return 0;
}


// ==== 0x58ca20 FUN_0058ca20

undefined4 FUN_0058ca20(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if ((DAT_007301e4 != 0) && (bMemoryPool_TotalAllocated(), DAT_007301e4 != 0)) {
    FUN_00565810();
  }
  puVar2 = *(undefined4 **)(param_1 + 0x4c);
  while( true ) {
    if (puVar2 == (undefined4 *)(param_1 + 0x4c)) {
      return 0;
    }
    iVar3 = CarLoader__UnloadRideInfo(param_1,puVar2,0);
    if (iVar3 != 0) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  CarLoader__DeleteUnusedRideInfos();
  iVar3 = DAT_007301e4;
  if (DAT_007301e4 != 0) {
    iVar1 = DAT_007301e4 + 0x3c;
    CriticalSection__Enter(iVar1);
    for (puVar2 = *(undefined4 **)(iVar3 + 4); puVar2 != (undefined4 *)(iVar3 + 4);
        puVar2 = (undefined4 *)*puVar2) {
    }
    CriticalSection__Leave(iVar1);
    if (DAT_007301e4 != 0) {
      FUN_00565810();
    }
  }
  return 1;
}


// ==== 0x58cac0 FUN_0058cac0

undefined4 FUN_0058cac0(undefined4 param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_3 == 0) {
    param_3 = param_2;
  }
  if (DAT_007301e4 == 0) {
    iVar4 = 0;
    iVar5 = 0;
  }
  else {
    iVar4 = bMemoryPool_TotalAllocated();
    iVar5 = 0;
    if (DAT_007301e4 != 0) {
      iVar5 = FUN_00565810();
      iVar5 = iVar5 + -0x58;
      if (iVar5 < 0) {
        iVar5 = 0;
      }
    }
  }
  if ((iVar4 < param_3) || (iVar5 < param_2)) {
    iVar3 = FUN_0058ca20(param_1);
    iVar2 = DAT_007301e4;
    while (DAT_007301e4 = iVar2, iVar3 != 0) {
      if (iVar2 == 0) {
        iVar4 = 0;
        iVar5 = 0;
      }
      else {
        CriticalSection__Enter(iVar2 + 0x3c);
        iVar4 = 0;
        for (puVar1 = *(undefined4 **)(iVar2 + 4); puVar1 != (undefined4 *)(iVar2 + 4);
            puVar1 = (undefined4 *)*puVar1) {
          iVar4 = iVar4 + puVar1[2];
        }
        CriticalSection__Leave(iVar2 + 0x3c);
        iVar5 = 0;
        if (DAT_007301e4 != 0) {
          iVar5 = FUN_00565810();
          iVar5 = iVar5 + -0x58;
          if (iVar5 < 0) {
            iVar5 = 0;
          }
        }
      }
      if ((param_3 <= iVar4) && (param_2 <= iVar5)) break;
      iVar3 = FUN_0058ca20(param_1);
      iVar2 = DAT_007301e4;
    }
  }
  if ((param_3 <= iVar4) && (param_2 <= iVar5)) {
    return 1;
  }
  return 0;
}


// ==== 0x58cbb0 FUN_0058cbb0

void __fastcall FUN_0058cbb0(undefined4 *param_1)

{
  short *psVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined1 local_1e0 [480];
  
  iVar3 = FUN_0058b7d0();
  if ((iVar3 == 0) && (iVar3 = FUN_0058b8a0(param_1), iVar3 == 0)) {
    puVar6 = (undefined4 *)param_1[0x13];
    if (puVar6 != param_1 + 0x13) {
      do {
        if (0 < (int)puVar6[2]) {
          if (*(char *)(*(int *)(puVar6[4] + 0x10) + 0x5a) == '\0') {
            ResourceFile_OpenAndStart(param_1);
            return;
          }
          if ((*(char *)(puVar6[4] + 0xd) == '\0') && (iVar3 = FUN_0058b630(param_1), iVar3 != 0)) {
            return;
          }
          iVar3 = puVar6[6];
          if (*(char *)(iVar3 + 0xba1) == '\0') {
            if (*(char *)(*(int *)(iVar3 + 0xba4) + 0x52) == '\0') {
              FUN_0058b4d0();
              return;
            }
            iVar4 = FUN_0058bce0(param_1,iVar3,1);
            if (iVar4 != 0) {
              return;
            }
          }
          if (*(char *)(iVar3 + 0xba2) == '\0') {
            if ((*(int *)(iVar3 + 0xba8) != 0) &&
               (*(char *)(*(int *)(iVar3 + 0xba8) + 0x52) == '\0')) {
              FUN_0058b4d0();
              return;
            }
            iVar4 = FUN_0058bce0(param_1,iVar3,0);
            if (iVar4 != 0) {
              return;
            }
          }
          if ((((*(char *)(iVar3 + 0xba3) == '\0') && (FUN_0058be50(param_1), param_1[3] == 0)) &&
              (*(char *)(iVar3 + 0xba2) == '\x02')) && (*(char *)(iVar3 + 0xba3) != '\0')) {
            iVar4 = *(int *)(iVar3 + 0xd90);
            if (0 < iVar4) {
              piVar5 = (int *)(iVar3 + 0xd94);
              do {
                if (*piVar5 != 0) {
                  psVar1 = (short *)(*piVar5 + 0xc);
                  *psVar1 = *psVar1 + -1;
                }
                piVar5 = piVar5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            iVar4 = FUN_0058c1c0(param_1,local_1e0,0x78,iVar3 + 0xd94);
            *(undefined4 *)(iVar3 + 0xd90) = 0;
            if (iVar4 != 0) {
              FUN_0053ec90(&DAT_00740420,local_1e0,iVar4);
            }
            if (*(int *)(iVar3 + 0xba8) != 0) {
              psVar1 = (short *)(*(int *)(iVar3 + 0xba8) + 0x50);
              *psVar1 = *psVar1 + -1;
              FUN_0058b520(param_1);
              *(undefined4 *)(iVar3 + 0xba8) = 0;
            }
          }
        }
        puVar6 = (undefined4 *)*puVar6;
      } while (puVar6 != param_1 + 0x13);
    }
    if (param_1[3] == 0) {
      FUN_0058c840(param_1);
    }
    pcVar2 = (code *)*param_1;
    if (pcVar2 != (code *)0x0) {
      *param_1 = 0;
      (*pcVar2)(param_1[1]);
    }
  }
  return;
}


// ==== 0x58cdc0 FUN_0058cdc0

void FUN_0058cdc0(int param_1)

{
  *(undefined1 *)(param_1 + 0x5a) = 2;
  FUN_0058b420(&DAT_00737b58);
  DAT_00737b6c = 0;
  FUN_0058cbb0();
  return;
}


// ==== 0x58cdf0 FUN_0058cdf0

void FUN_0058cdf0(int param_1)

{
  *(undefined1 *)(param_1 + 0x52) = 2;
  FUN_0058b520(&DAT_00737b58);
  DAT_00737b6c = 0;
  FUN_0058cbb0();
  return;
}


// ==== 0x58ce20 FUN_0058ce20

void FUN_0058ce20(int param_1)

{
  *(undefined1 *)(param_1 + 0xd) = 2;
  FUN_0058b6c0(&DAT_00737b58);
  DAT_00737b6c = 0;
  FUN_0058cbb0();
  return;
}


// ==== 0x58ce50 FUN_0058ce50

void FUN_0058ce50(void)

{
  FUN_0058b860(&DAT_00737b58);
  return;
}


// ==== 0x58ce60 FUN_0058ce60

void FUN_0058ce60(void)

{
  FUN_0058b9a0(&DAT_00737b58);
  return;
}


// ==== 0x58ce70 FUN_0058ce70

void FUN_0058ce70(void)

{
  FUN_0058bdc0();
  return;
}


// ==== 0x58ce90 FUN_0058ce90

void FUN_0058ce90(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = DAT_007344f0;
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


// ==== 0x58ced0 FUN_0058ced0

void FUN_0058ced0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = DAT_007344ec;
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


// ==== 0x58cf10 FUN_0058cf10

void FUN_0058cf10(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = DAT_007344f4;
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


// ==== 0x58cf50 FUN_0058cf50

void FUN_0058cf50(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = DAT_007344f8;
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


// ==== 0x58cf90 FUN_0058cf90

void FUN_0058cf90(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = DAT_007344fc;
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


// ==== 0x58cfd0 FUN_0058cfd0

void FUN_0058cfd0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = DAT_00734500;
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


// ==== 0x58d010 FUN_0058d010

int FUN_0058d010(int param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006855e8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  eh_vector_constructor_iterator((void *)(param_1 + 0xe0),0x18,2,ListRef_Init,ListRef_Release);
  local_4 = 0;
  eh_vector_constructor_iterator((void *)(param_1 + 0x110),0x18,2,ListRef_Init,ListRef_Release);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x58d0d0 FUN_0058d0d0

void FUN_0058d0d0(int param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006855e8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  eh_vector_destructor_iterator((void *)(param_1 + 0x110),0x18,2,ListRef_Release);
  local_4 = 0xffffffff;
  eh_vector_destructor_iterator((void *)(param_1 + 0xe0),0x18,2,ListRef_Release);
  ExceptionList = local_c;
  return;
}


// ==== 0x58d140 Chunk37010::Accept

/* [canon] assets high (Ghidra make FUN_0058d140 (H export lacks it; capstone agrees))
   docs/re/assets.md */

bool Chunk37010__Accept(int *param_1)

{
  return *param_1 == 0x37010;
}


// ==== 0x58d160 FUN_0058d160

void FUN_0058d160(void)

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
    FUN_0058d0d0(_Memory);
    _free(_Memory);
    _Memory = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x58d190 FUN_0058d190

int __fastcall FUN_0058d190(undefined4 param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  byte *in_EAX;
  int iVar4;
  byte *pbVar5;
  ushort uVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  
  if ((*param_2 == 0x5a4c444a) && ((char)param_2[1] == '\x02')) {
    pbVar8 = in_EAX + param_2[2];
    pbVar5 = (byte *)((int)param_2 + 0x12);
    uVar3 = *(byte *)(param_2 + 4) | 0x100;
    uVar6 = *(byte *)((int)param_2 + 0x11) | 0x100;
    iVar7 = param_2[3] + -0x12;
    while (iVar7 != 0) {
      if ((uVar3 & 1) == 0) {
        if (in_EAX < pbVar8) {
          *in_EAX = *pbVar5;
          in_EAX = in_EAX + 1;
          pbVar5 = pbVar5 + 1;
        }
        iVar9 = -1;
      }
      else {
        bVar1 = pbVar5[1];
        if ((uVar6 & 1) == 0) {
          bVar2 = *pbVar5;
          iVar4 = (bVar2 & 0x1f) + 3;
          iVar9 = 0;
          do {
            in_EAX[iVar9] = in_EAX[iVar9 - (((bVar2 & 0xffffffe0) << 3 | (uint)bVar1) + 0x11)];
            iVar9 = iVar9 + 1;
          } while (iVar9 < iVar4);
        }
        else {
          bVar2 = *pbVar5;
          iVar4 = ((bVar2 & 0xfffffff0) << 4 | (uint)bVar1) + 3;
          iVar9 = 0;
          do {
            in_EAX[iVar9] = in_EAX[iVar9 - ((bVar2 & 0xf) + 1)];
            iVar9 = iVar9 + 1;
          } while (iVar9 < iVar4);
        }
        uVar6 = (short)uVar6 >> 1;
        pbVar5 = pbVar5 + 2;
        iVar9 = -2;
        in_EAX = in_EAX + iVar4;
      }
      iVar7 = iVar7 + iVar9;
      uVar3 = (short)uVar3 >> 1;
      if (uVar3 == 1) {
        uVar3 = *pbVar5 | 0x100;
        pbVar5 = pbVar5 + 1;
        iVar7 = iVar7 + -1;
      }
      if (uVar6 == 1) {
        uVar6 = *pbVar5 | 0x100;
        pbVar5 = pbVar5 + 1;
        iVar7 = iVar7 + -1;
      }
    }
    return param_2[2];
  }
  return 0;
}


// ==== 0x58d2c0 DecompressCOMP

/* [canon] assets med (hopper) docs/re/assets.md */

int __thiscall DecompressCOMP(int *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  
  if (((param_1 != (int *)0x0) && (param_2 != (byte *)0x0)) &&
     (iVar2 = param_1[3], *param_1 == 0x504d4f43)) {
    uVar5 = 1;
    pbVar7 = (byte *)(param_1 + 4);
    pbVar3 = param_2;
    if (*(short *)((int)param_1 + 6) != 1) {
      while (pbVar7 != (byte *)((int)param_1 + iVar2)) {
        if (uVar5 == 1) {
          uVar5 = *pbVar7 | 0x10000 | (uint)pbVar7[1] << 8;
          pbVar7 = pbVar7 + 2;
        }
        iVar8 = (-(uint)((byte *)((int)param_1 + iVar2) + -0x20 < pbVar7) & 0xfffffff1) + 0x10;
        do {
          if ((uVar5 & 1) == 0) {
            *pbVar3 = *pbVar7;
            pbVar3 = pbVar3 + 1;
            pbVar7 = pbVar7 + 1;
          }
          else {
            bVar1 = *pbVar7;
            pbVar4 = pbVar3 + -((bVar1 & 0xf0) << 4 | (uint)pbVar7[1]);
            pbVar7 = pbVar7 + 2;
            *pbVar3 = *pbVar4;
            pbVar3[1] = pbVar4[1];
            pbVar3[2] = pbVar4[2];
            pbVar3 = pbVar3 + 3;
            pbVar4 = pbVar4 + 3;
            uVar6 = bVar1 & 0xf;
            if ((bVar1 & 0xf) != 0) {
              do {
                *pbVar3 = *pbVar4;
                pbVar3 = pbVar3 + 1;
                pbVar4 = pbVar4 + 1;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
          }
          uVar5 = uVar5 >> 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      return (int)pbVar3 - (int)param_2;
    }
    for (uVar5 = iVar2 - 0x10U >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)param_2 = *(undefined4 *)pbVar7;
      pbVar7 = pbVar7 + 4;
      param_2 = param_2 + 4;
    }
    for (uVar5 = iVar2 - 0x10U & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *param_2 = *pbVar7;
      pbVar7 = pbVar7 + 1;
      param_2 = param_2 + 1;
    }
    return iVar2 + -0x10;
  }
  return 0;
}


// ==== 0x58d3c0 IsCompressedBuffer

/* [canon] assets high (hopper+ghidra) docs/re/assets.md */

bool __fastcall IsCompressedBuffer(int *param_1)

{
  if (*param_1 == 0x504d4f43) {
    return (char)param_1[1] == '\x01';
  }
  if (*param_1 == 0x5a4c444a) {
    return (char)param_1[1] == '\x02';
  }
  return false;
}


// ==== 0x58d3f0 DecompressBuffer

/* [canon] assets high (hopper+data) docs/re/assets.md */

undefined4 __fastcall DecompressBuffer(int *param_1)

{
  int in_EAX;
  undefined4 uVar1;
  
  if ((param_1 != (int *)0x0) && (in_EAX != 0)) {
    if (*param_1 == 0x504d4f43) {
      uVar1 = DecompressCOMP();
      return uVar1;
    }
    if (*param_1 == 0x5a4c444a) {
      uVar1 = FUN_0058d190();
      return uVar1;
    }
  }
  return 0;
}


// ==== 0x58d420 FUN_0058d420

int FUN_0058d420(void)

{
  int iVar1;
  int iVar2;
  float10 extraout_ST0;
  float10 extraout_ST1;
  
  iVar1 = _ftol_nocw();
  iVar2 = _ftol_nocw();
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else if (7 < iVar1) {
    iVar1 = 7;
  }
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  else if (7 < iVar2) {
    iVar2 = 7;
  }
  if (extraout_ST0 < extraout_ST1) {
    if ((float10)_K_ONE - extraout_ST0 < extraout_ST1) {
      return 8 - iVar2;
    }
    return 0x10 - iVar1;
  }
  iVar1 = iVar1 + 0x18;
  if (extraout_ST1 <= (float10)_K_ONE - extraout_ST0) {
    iVar1 = iVar2 + 0x10;
  }
  return iVar1;
}


// ==== 0x58d4c0 Unused34030_Load

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 Unused34030_Load(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  if (*param_1 == 0x34030) {
    piVar2 = param_1 + 2;
    *DAT_00737b4c = (int)piVar2;
    piVar1 = piVar2;
    param_1[3] = (int)DAT_00737b4c;
    DAT_00737b4c = piVar1;
    *piVar2 = (int)&DAT_00737b48;
    param_1[0x15] = (int)(param_1 + 0x17);
    param_1[0x16] = 0;
    return 1;
  }
  return 0;
}


// ==== 0x58d500 Unused34030_Unload

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 Unused34030_Unload(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (*param_1 == 0x34030) {
    iVar1 = param_1[2];
    piVar2 = (int *)param_1[3];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    return 1;
  }
  return 0;
}


// ==== 0x58d520 FUN_0058d520

void __fastcall FUN_0058d520(undefined4 param_1,int param_2)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  int *extraout_EDX;
  
  pbVar2 = (byte *)(param_2 + 8);
  iVar3 = 0x20;
  do {
    *(short *)(param_2 + 0x28) = *(short *)(param_2 + 0x28) - (ushort)*pbVar2;
    *pbVar2 = 0;
    pbVar2 = pbVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined2 *)(param_2 + 0x28) = 0;
  FUN_0058d620();
  iVar3 = *extraout_EDX;
  piVar1 = (int *)extraout_EDX[1];
  *piVar1 = iVar3;
  *(int **)(iVar3 + 4) = piVar1;
  return;
}


// ==== 0x58d560 FUN_0058d560

void FUN_0058d560(void)

{
  int iVar1;
  char cVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  FUN_00571ea0(0,"BodyDamage");
  FUN_00571c20(unaff_ESI,unaff_EDI + 8,0x20,0x20,0);
  FUN_00571c20(unaff_ESI,unaff_EDI + 0x28,2,2,0);
  if (*(char *)(unaff_ESI + 0x3d) != '\0') {
    FUN_0058d620();
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


// ==== 0x58d5d0 FUN_0058d5d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058d5d0(void)

{
  short sVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  sVar1 = _ftol_nocw();
  *(short *)(unaff_ESI + 0x28) =
       *(short *)(unaff_ESI + 0x28) + (sVar1 - (ushort)*(byte *)(unaff_EDI + 8 + unaff_ESI));
  *(char *)(unaff_EDI + 8 + unaff_ESI) = (char)sVar1;
  return;
}


// ==== 0x58d620 FUN_0058d620

void __fastcall FUN_0058d620(undefined4 param_1,int param_2)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  ushort uVar4;
  int iVar5;
  short sVar6;
  
  if (DAT_0078a336 == '\0') {
    fVar1 = 0.0;
  }
  else {
    fVar1 = (float)*(ushort *)(param_2 + 0x28) * 0.00024414062;
  }
  fVar2 = (float)*(ushort *)(param_2 + 0x4a) * 0.00024414062;
  if (fVar1 != fVar2) {
    if (DAT_0078a336 == '\0') {
      fVar1 = 0.0;
    }
    else {
      fVar1 = (float)*(ushort *)(param_2 + 0x28) * 0.00024414062;
    }
    if (((0.02 < ABS(fVar1 - fVar2)) || (DAT_0078a336 == '\0')) ||
       ((float)*(ushort *)(param_2 + 0x28) * 0.00024414062 == 0.0)) {
      if (0 < *(int *)(param_2 + 0x5c)) {
        puVar3 = (undefined4 *)(param_2 + 0x74);
        iVar5 = 0;
        do {
          if (puVar3[-3] != 0) {
            *puVar3 = 0;
            puVar3[1] = 0;
          }
          iVar5 = iVar5 + 1;
          puVar3 = puVar3 + 7;
        } while (iVar5 < *(int *)(param_2 + 0x5c));
      }
      sVar6 = 0;
      iVar5 = 0;
      do {
        if (DAT_0078a336 == '\0') {
          uVar4 = 0;
        }
        else {
          uVar4 = (ushort)*(byte *)(iVar5 + 8 + param_2);
        }
        sVar6 = sVar6 + uVar4;
        *(char *)(param_2 + 0x2a + iVar5) = (char)uVar4;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0x20);
      *(short *)(param_2 + 0x4a) = sVar6;
    }
  }
  return;
}


// ==== 0x58d720 FUN_0058d720

void FUN_0058d720(void)

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
    FUN_0058d520();
    _free(_Memory);
    _Memory = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x58d750 FUN_0058d750

void FUN_0058d750(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *unaff_ESI;
  int *piVar6;
  undefined4 *puVar7;
  
  piVar6 = unaff_ESI + 3;
  *DAT_00737b44 = (int)piVar6;
  piVar3 = piVar6;
  unaff_ESI[4] = (int)DAT_00737b44;
  DAT_00737b44 = piVar3;
  *piVar6 = (int)&DAT_00737b40;
  piVar6 = unaff_ESI + 5;
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar6 = 0;
    piVar6 = piVar6 + 1;
  }
  puVar7 = (undefined4 *)((int)unaff_ESI + 0x36);
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)(unaff_ESI + 0xd) = 0;
  *(undefined2 *)((int)unaff_ESI + 0x56) = 0;
  unaff_ESI[0x1a] = 0;
  unaff_ESI[0x37] = 0;
  unaff_ESI[0x38] = 0;
  unaff_ESI[0x39] = 0;
  *unaff_ESI = param_1;
  iVar4 = *(int *)(param_1 + 0xc) + 0x20;
  iVar5 = -1;
  bVar2 = *(byte *)(*(int *)(param_1 + 0xc) + 0x20);
  while (bVar2 != 0) {
    iVar5 = iVar5 * 0x21 + (uint)bVar2;
    pbVar1 = (byte *)(iVar4 + 1);
    iVar4 = iVar4 + 1;
    bVar2 = *pbVar1;
  }
  unaff_ESI[1] = iVar5;
  unaff_ESI[0x3a] = -1;
  unaff_ESI[0x3b] = -1;
  unaff_ESI[0x3c] = -1;
  *(undefined2 *)(unaff_ESI + 0x3d) = 0xffff;
  *(undefined1 *)((int)unaff_ESI + 0xf6) = 0xff;
  *(undefined1 *)(unaff_ESI + 2) = 0;
  return;
}


// ==== 0x58d800 FUN_0058d800

void FUN_0058d800(int param_1,int param_2)

{
  undefined1 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = (int *)0x0;
  do {
    iVar4 = *(int *)(param_2 + 0xc);
    if (iVar4 == 0) {
      return;
    }
    piVar3 = *(int **)(iVar4 + 0x80);
    if ((piVar3 == (int *)0x0) || (*(char *)(iVar4 + 0x1b) == 0)) {
LAB_0058d844:
      piVar3 = (int *)0x0;
    }
    else if (piVar5 != (int *)0x0) {
      if ((piVar5 < piVar3) || (piVar3 + (*(char *)(iVar4 + 0x1b) * 5 + -5) * 4 <= piVar5))
      goto LAB_0058d844;
      piVar3 = piVar5 + 0x14;
    }
    if (piVar3 == (int *)0x0) {
      return;
    }
    iVar4 = 0;
    piVar2 = &DAT_006f0404;
    do {
      piVar5 = piVar3;
      if (*piVar2 == *piVar3) {
        uVar1 = FUN_0058d420();
        *(undefined1 *)(iVar4 + 0xe8 + param_1) = uVar1;
        break;
      }
      piVar2 = piVar2 + 9;
      iVar4 = iVar4 + 1;
    } while ((int)piVar2 < 0x6f0620);
  } while( true );
}


// ==== 0x58d8a0 FUN_0058d8a0

void FUN_0058d8a0(int param_1)

{
  int in_EAX;
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(param_1,"CarDamage");
  FUN_0058d560();
  FUN_00571c20(in_EAX,param_1 + 0xe0,4,4,0);
  if (*(char *)(in_EAX + 0x3d) != '\0') {
    FUN_0058db20();
  }
  FUN_00571c20(in_EAX,param_1 + 8,1,1,1);
  iVar1 = *(char *)(in_EAX + 0x40) * 0x10;
  *(int *)(iVar1 + in_EAX + 0x58) = *(int *)(in_EAX + 0x150) - *(int *)(iVar1 + 0x58 + in_EAX);
  cVar2 = *(char *)(in_EAX + 0x40) + -1;
  *(char *)(in_EAX + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(in_EAX + 0x44)) {
    *(undefined4 *)(in_EAX + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x58d930 FUN_0058d930

void FUN_0058d930(float param_1)

{
  undefined4 in_EAX;
  int iVar1;
  float local_8;
  
  if (((DAT_0078a336 != '\0') && (0.05 <= param_1)) && (iVar1 = FUN_0058d420(), -1 < iVar1)) {
    local_8 = param_1;
    FUN_0058da60(in_EAX,param_1,param_1);
    iVar1 = 1;
    do {
      local_8 = local_8 * 0.5;
      FUN_0058da60(in_EAX,local_8,param_1);
      FUN_0058da60(in_EAX,local_8,param_1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 5);
    FUN_0058db20();
  }
  return;
}


// ==== 0x58d9e0 FUN_0058d9e0

uint FUN_0058d9e0(int param_1)

{
  float fVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  float *pfVar6;
  float *pfVar7;
  
  uVar4 = 0;
  bVar2 = 0;
  pcVar5 = (char *)(param_1 + 0xe8);
  pfVar7 = (float *)&DAT_006f0414;
  do {
    if (-1 < *pcVar5) {
      if (DAT_0078a336 == '\0') {
        fVar1 = 0.0;
      }
      else {
        fVar1 = (float)*(byte *)(*pcVar5 + 0x14 + param_1) * 0.0078125;
      }
      iVar3 = 3;
      pfVar6 = pfVar7;
      do {
        if (*pfVar6 <= fVar1) break;
        iVar3 = iVar3 + -1;
        pfVar6 = pfVar6 + -1;
      } while (0 < iVar3);
      uVar4 = uVar4 | iVar3 << (bVar2 & 0x1f);
    }
    pfVar7 = pfVar7 + 9;
    pcVar5 = pcVar5 + 1;
    bVar2 = bVar2 + 2;
    if (0x6f062f < (int)pfVar7) {
      return uVar4;
    }
  } while( true );
}


// ==== 0x58da60 FUN_0058da60

void FUN_0058da60(float param_1,float param_2,float param_3)

{
  float fVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  
  iVar2 = (int)param_1;
  fVar1 = (float)*(byte *)(in_EAX + 0x14 + (int)param_1) * 0.0078125;
  param_1 = param_2 + fVar1;
  if (param_1 <= 0.0) {
    param_1 = 0.0;
  }
  else if (1.0 < param_1) {
    param_1 = 1.0;
  }
  if (fVar1 != param_1) {
    FUN_0058d5d0(param_1);
    iVar3 = FUN_0058d9e0(iVar2);
    if (iVar3 != *(int *)(iVar2 + 0xe0)) {
      if (param_3 < 0.2) {
        FUN_0058d5d0(fVar1);
        return;
      }
      *(int *)(iVar2 + 0xe0) = iVar3;
    }
  }
  return;
}


// ==== 0x58db20 FUN_0058db20

void FUN_0058db20(void)

{
  int iVar1;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  int *unaff_EDI;
  
  if ((char)unaff_EDI[2] != '\0') {
    FUN_0058d620();
    iVar1 = FUN_0058d9e0(unaff_EDI);
    unaff_EDI[0x38] = iVar1;
    if (iVar1 != unaff_EDI[0x39]) {
      bVar2 = 0;
      piVar3 = &DAT_006f041c;
      do {
        uVar4 = (uint)unaff_EDI[0x38] >> (bVar2 & 0x1f) & 3;
        if (uVar4 != ((uint)unaff_EDI[0x39] >> (bVar2 & 0x1f) & 3)) {
          if ((*piVar3 != 0) && (uVar4 != 0)) {
            FUN_00569a00(*unaff_EDI,*(undefined4 *)(&DAT_006f061c + uVar4 * 4),0,0);
          }
          unaff_EDI[0x39] = ~(3 << (bVar2 & 0x1f)) & unaff_EDI[0x39] | uVar4 << (bVar2 & 0x1f);
        }
        piVar3 = piVar3 + 9;
        bVar2 = bVar2 + 2;
      } while ((int)piVar3 < 0x6f0638);
      FUN_0056ca60(*(undefined4 *)(*unaff_EDI + 0x4d4));
    }
  }
  return;
}


// ==== 0x58dbe0 FUN_0058dbe0

void FUN_0058dbe0(void)

{
  undefined4 in_EAX;
  int iVar1;
  
  iVar1 = 0;
  do {
    FUN_0058da60(in_EAX,0x3f800000,0x461c3c00);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x20);
  FUN_0058db20();
  return;
}


// ==== 0x58dc10 FUN_0058dc10

void FUN_0058dc10(void)

{
  int in_EAX;
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = (byte *)(in_EAX + 0x14);
  iVar2 = 0x20;
  do {
    *(short *)(in_EAX + 0x34) = *(short *)(in_EAX + 0x34) - (ushort)*pbVar1;
    *pbVar1 = 0;
    pbVar1 = pbVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined2 *)(in_EAX + 0x34) = 0;
  FUN_0058d620();
  FUN_0058db20();
  return;
}


// ==== 0x58dc50 FUN_0058dc50

undefined4 __thiscall FUN_0058dc50(float *param_1,float param_2,float param_3,float param_4)

{
  if (((param_1[4] < ABS(param_2 - *param_1) == (param_1[4] == ABS(param_2 - *param_1))) &&
      (param_1[5] < ABS(param_3 - param_1[1]) == (param_1[5] == ABS(param_3 - param_1[1])))) &&
     (param_1[6] < ABS(param_4 - param_1[2]) == (param_1[6] == ABS(param_4 - param_1[2])))) {
    return 1;
  }
  return 0;
}


// ==== 0x58dca0 WorldZone_NodeWalk

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

float * __thiscall
WorldZone_NodeWalk(int *param_1,int param_2,float param_3,float param_4,float param_5)

{
  short sVar1;
  float *pfVar2;
  int iVar3;
  short *psVar4;
  
  sVar1 = *(short *)(param_2 + 0xe);
  iVar3 = 0;
  if (0 < sVar1) {
    psVar4 = (short *)(param_2 + 0x1c);
    do {
      pfVar2 = (float *)(*psVar4 * 0x30 + *param_1);
      if (((pfVar2[4] < ABS(param_3 - *pfVar2) == (pfVar2[4] == ABS(param_3 - *pfVar2))) &&
          (pfVar2[5] < ABS(param_4 - pfVar2[1]) == (pfVar2[5] == ABS(param_4 - pfVar2[1])))) &&
         (pfVar2[6] < ABS(param_5 - pfVar2[2]) == (pfVar2[6] == ABS(param_5 - pfVar2[2])))) {
        if (*(short *)((int)pfVar2 + 0xe) < 1) {
          return pfVar2;
        }
        pfVar2 = (float *)WorldZone_NodeWalk(pfVar2,param_3,param_4,param_5);
        if (pfVar2 != (float *)0x0) {
          return pfVar2;
        }
      }
      iVar3 = iVar3 + 1;
      psVar4 = psVar4 + 1;
    } while (iVar3 < sVar1);
  }
  return (float *)0x0;
}


// ==== 0x58dd50 FUN_0058dd50

void FUN_0058dd50(void)

{
  undefined4 *puVar1;
  
  DAT_007344d4 = (undefined4 *)FUN_00566dc0(0x24,"EventSlotPool",0);
  if ((DAT_007344d4 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_007344d4;
    puVar1 = DAT_007344d4;
    DAT_007344d4[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_007344d4 = &DAT_0073d818;
  }
  DAT_007344d8 = (undefined4 *)FUN_00566dc0(0x18,"EventHandlerSlotPool",0);
  if (DAT_007344d8 == (undefined4 *)0x0) {
    return;
  }
  if (DAT_0073d814 == 1) {
    *DAT_0073d81c = DAT_007344d8;
    puVar1 = DAT_007344d8;
    DAT_007344d8[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_007344d8 = &DAT_0073d818;
  }
  return;
}


// ==== 0x58dde0 WorldZone_Load

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 WorldZone_Load(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  
  if (*param_1 != -0x7ffca000) {
    return 0;
  }
  piVar6 = param_1 + 2;
  param_1 = (int *)(param_1[1] + 8 + (int)param_1);
  puVar5 = (undefined4 *)0x0;
  uVar4 = 1;
  if (piVar6 != param_1) {
    do {
      iVar1 = *piVar6;
      if (iVar1 == 0x36001) {
        puVar5 = (undefined4 *)((int)piVar6 + 0x17U & 0xfffffff0);
        if (puVar5[2] != 1) {
          return uVar4;
        }
      }
      else if (iVar1 == 0x36002) {
        if (puVar5 != (undefined4 *)0x0) {
          piVar7 = (int *)((int)piVar6 + 0x17U & 0xfffffff0);
          puVar5[4] = piVar7;
          *piVar7 = (int)(piVar7 + 4);
        }
      }
      else if ((iVar1 == 0x36003) && (puVar5 != (undefined4 *)0x0)) {
        puVar5[5] = (int)piVar6 + 0x17U & 0xfffffff0;
      }
      puVar3 = DAT_00737b3c;
      puVar2 = DAT_00737b24;
      piVar6 = (int *)((int)piVar6 + piVar6[1] + 8);
    } while (piVar6 != param_1);
    if (puVar5 != (undefined4 *)0x0) {
      if (((puVar5[3] != 0) && (puVar5[4] != 0)) && (puVar5[5] != 0)) {
        *DAT_00737b24 = puVar5;
        DAT_00737b24 = puVar5;
        *puVar5 = &DAT_00737b20;
        puVar5[1] = puVar2;
        return uVar4;
      }
      *DAT_00737b3c = puVar5;
      DAT_00737b3c = puVar5;
      *puVar5 = &DAT_00737b38;
      puVar5[1] = puVar3;
    }
  }
  return uVar4;
}


// ==== 0x58de10 WorldZone_Unload_Impl

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

void __fastcall WorldZone_Unload_Impl(undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_EAX;
  int *piVar4;
  int *unaff_EDI;
  
  do {
    iVar1 = *param_2;
    if (iVar1 == 0x36001) {
      param_1 = (undefined4 *)((int)param_2 + 0x17U & 0xfffffff0);
      if (param_1[2] != in_EAX) {
        return;
      }
    }
    else if (iVar1 == 0x36002) {
      if (param_1 != (undefined4 *)0x0) {
        piVar4 = (int *)((int)param_2 + 0x17U & 0xfffffff0);
        param_1[4] = piVar4;
        *piVar4 = (int)(piVar4 + 4);
      }
    }
    else if ((iVar1 == 0x36003) && (param_1 != (undefined4 *)0x0)) {
      param_1[5] = (int)param_2 + 0x17U & 0xfffffff0;
    }
    puVar3 = DAT_00737b3c;
    puVar2 = DAT_00737b24;
    param_2 = (int *)((int)param_2 + param_2[1] + 8);
  } while (param_2 != unaff_EDI);
  if (param_1 != (undefined4 *)0x0) {
    if (((param_1[3] != 0) && (param_1[4] != 0)) && (param_1[5] != 0)) {
      *DAT_00737b24 = param_1;
      DAT_00737b24 = param_1;
      *param_1 = &DAT_00737b20;
      param_1[1] = puVar2;
      return;
    }
    *DAT_00737b3c = param_1;
    DAT_00737b3c = param_1;
    *param_1 = &DAT_00737b38;
    param_1[1] = puVar3;
  }
  return;
}


// ==== 0x58deb0 WorldZone_Unload

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 WorldZone_Unload(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (*param_1 != -0x7ffca000) {
    return 0;
  }
  if (param_1 + 2 != (int *)(param_1[1] + 8 + (int)param_1)) {
    do {
    } while (param_1[2] != 0x36001);
    piVar2 = (int *)((int)param_1 + 0x1fU & 0xfffffff0);
    if (piVar2[2] == 1) {
      iVar1 = *piVar2;
      piVar2 = (int *)piVar2[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
    }
  }
  return 1;
}


// ==== 0x58df00 FUN_0058df00

undefined4 FUN_0058df00(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EDI;
  
  puVar2 = DAT_00737b28;
  if ((unaff_EDI != 0) && (param_1 != 0)) {
    puVar1 = (undefined4 *)NullUpdate_ret();
    for (; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      if (puVar2[2] == unaff_EDI) {
        puVar2[4] = puVar2[4] + 1;
        return 1;
      }
    }
    puVar2 = (undefined4 *)FUN_00567160();
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[2] = unaff_EDI;
      puVar2[3] = param_1;
      puVar2[4] = 1;
      *DAT_00737b2c = puVar2;
      puVar1 = puVar2;
      puVar2[1] = DAT_00737b2c;
      DAT_00737b2c = puVar1;
      *puVar2 = &DAT_00737b28;
      DAT_0073131c = DAT_0073131c + 1;
      if (DAT_00731328 < DAT_0073131c) {
        DAT_00731328 = DAT_0073131c;
      }
      return 1;
    }
  }
  return 0;
}


// ==== 0x58dfa0 FUN_0058dfa0

void FUN_0058dfa0(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int unaff_EDI;
  
  piVar4 = DAT_00737b28;
  piVar3 = (int *)NullUpdate_ret();
  if (piVar4 != piVar3) {
    while (piVar4[2] != unaff_EDI) {
      piVar4 = (int *)*piVar4;
      if (piVar4 == piVar3) {
        return;
      }
    }
    piVar3 = piVar4 + 4;
    *piVar3 = *piVar3 + -1;
    if (*piVar3 == 0) {
      iVar1 = *piVar4;
      piVar3 = (int *)piVar4[1];
      *piVar3 = iVar1;
      *(int **)(iVar1 + 4) = piVar3;
      iVar2 = DAT_007344d8;
      iVar1 = *(int *)(DAT_007344d8 + 0x18);
      *piVar4 = *(int *)(DAT_007344d8 + 0x10);
      *(int *)(iVar2 + 0x18) = iVar1 + -1;
      *(int **)(iVar2 + 0x10) = piVar4;
      DAT_0073131c = DAT_0073131c + -1;
    }
  }
  return;
}


// ==== 0x58dff0 WorldZone_CreateObject

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets med (Hopper export + Ghidra export) docs/re/assets.md */

undefined4 * WorldZone_CreateObject(undefined4 param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar2 = (undefined4 *)FUN_00567160();
  puVar3 = (undefined4 *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    puVar3 = puVar2;
    for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    puVar2[2] = 0;
    puVar2[3] = param_1;
    puVar1 = PTR_DAT_006f03f8;
    puVar3 = *(undefined4 **)(PTR_DAT_006f03f8 + 4);
    *puVar3 = puVar2;
    *(undefined4 **)(puVar1 + 4) = puVar2;
    *puVar2 = puVar1;
    puVar2[1] = puVar3;
    _DAT_00731318 = _DAT_00731318 + 1;
    puVar3 = puVar2;
  }
  return puVar3;
}


// ==== 0x58e040 FUN_0058e040

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058e040(void)

{
  int ***pppiVar1;
  undefined4 *puVar2;
  int ***pppiVar3;
  undefined4 uVar4;
  int ****ppppiVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int ****ppppiVar9;
  int ****ppppiVar10;
  int ****ppppiVar11;
  int iStack_50;
  int ***local_38;
  int ***local_34;
  int ***local_30;
  int ***local_2c;
  LARGE_INTEGER local_28;
  LARGE_INTEGER LStack_20;
  void *pvStack_14;
  code *pcStack_10;
  undefined4 local_c;
  
  ppppiVar9 = DAT_00737b30;
  pcStack_10 = FUN_006850d0;
  pvStack_14 = ExceptionList;
  ppppiVar11 = &local_30;
  local_2c = (int ***)&local_30;
  ppppiVar10 = &local_38;
  local_34 = (int ***)&local_38;
  PTR_DAT_006f03f8 = (undefined *)&local_30;
  local_c = 1;
  ExceptionList = &pvStack_14;
  local_38 = (int ***)ppppiVar10;
  local_30 = (int ***)ppppiVar11;
  ppppiVar5 = (int ****)NullUpdate_ret();
  iVar8 = DAT_007344d4;
  if (ppppiVar9 != ppppiVar5) {
    puVar6 = (undefined4 *)NullUpdate_ret();
    iVar8 = DAT_007344d4;
    do {
      ppppiVar11 = (int ****)*ppppiVar9;
      pppiVar1 = ppppiVar9[3];
      DAT_007344dc = ppppiVar9;
      ppppiVar10 = (int ****)local_34;
      for (puVar2 = DAT_00737b28; local_34 = (int ***)ppppiVar10, puVar2 != puVar6;
          puVar2 = (undefined4 *)*puVar2) {
        if ((puVar2[3] & (uint)pppiVar1) != 0) {
          QueryPerformanceCounter(&local_28);
          iVar7 = __allshr();
          (*(code *)puVar2[2])(ppppiVar9);
          QueryPerformanceCounter(&LStack_20);
          uVar4 = DAT_007349c8;
          iStack_50 = __allshr();
          iVar8 = DAT_007344d4;
          iStack_50 = iStack_50 - iVar7;
          if (iStack_50 < 0) {
            iStack_50 = 0;
          }
          puVar2[5] = (float)(1 << ((byte)uVar4 & 0x1f)) * (float)iStack_50 * _DAT_007301d0 +
                      (float)puVar2[5];
        }
        ppppiVar10 = (int ****)local_34;
      }
      pppiVar1 = *ppppiVar9;
      pppiVar3 = ppppiVar9[1];
      *pppiVar3 = (int **)pppiVar1;
      pppiVar1[1] = (int **)pppiVar3;
      DAT_007344dc = (int ****)0x0;
      if (ppppiVar9[2] == (int ***)0x0) {
        iVar7 = *(int *)(iVar8 + 0x18);
        *ppppiVar9 = *(int ****)(iVar8 + 0x10);
        *(int *)(iVar8 + 0x18) = iVar7 + -1;
        *(int *****)(iVar8 + 0x10) = ppppiVar9;
      }
      else {
        *ppppiVar10 = (int ***)ppppiVar9;
        local_34 = (int ***)ppppiVar9;
        ppppiVar9[1] = (int ***)ppppiVar10;
        *ppppiVar9 = (int ***)&local_38;
      }
      ppppiVar9 = ppppiVar11;
    } while (ppppiVar11 != ppppiVar5);
    while ((int ****)local_38 != &local_38) {
      pppiVar1 = (int ***)*local_38;
      pppiVar3 = (int ***)local_38[1];
      *pppiVar3 = (int **)pppiVar1;
      pppiVar1[1] = (int **)pppiVar3;
      *DAT_00737b34 = local_38;
      *local_38 = (int **)&DAT_00737b30;
      local_38[1] = (int **)DAT_00737b34;
      DAT_00737b34 = (int ****)local_38;
    }
    while (ppppiVar10 = (int ****)local_38, ppppiVar11 = (int ****)local_30,
          (int ****)local_30 != &local_30) {
      pppiVar1 = (int ***)*local_30;
      pppiVar3 = (int ***)local_30[1];
      *pppiVar3 = (int **)pppiVar1;
      pppiVar1[1] = (int **)pppiVar3;
      *DAT_00737b34 = local_30;
      *local_30 = (int **)&DAT_00737b30;
      local_30[1] = (int **)DAT_00737b34;
      DAT_00737b34 = (int ****)local_30;
    }
  }
  PTR_DAT_006f03f8 = (undefined *)&DAT_00737b30;
  if (ppppiVar10 != &local_38) {
    do {
      pppiVar1 = *ppppiVar10;
      pppiVar3 = ppppiVar10[1];
      *pppiVar3 = (int **)pppiVar1;
      pppiVar1[1] = (int **)pppiVar3;
      iVar7 = *(int *)(iVar8 + 0x18);
      *ppppiVar10 = *(int ****)(iVar8 + 0x10);
      *(int *****)(iVar8 + 0x10) = ppppiVar10;
      *(int *)(iVar8 + 0x18) = iVar7 + -1;
      ppppiVar10 = (int ****)local_38;
      ppppiVar11 = (int ****)local_30;
    } while ((int ****)local_38 != &local_38);
  }
  if (ppppiVar11 != &local_30) {
    do {
      pppiVar1 = *ppppiVar11;
      pppiVar3 = ppppiVar11[1];
      *pppiVar3 = (int **)pppiVar1;
      pppiVar1[1] = (int **)pppiVar3;
      iVar7 = *(int *)(iVar8 + 0x18);
      *ppppiVar11 = *(int ****)(iVar8 + 0x10);
      *(int *****)(iVar8 + 0x10) = ppppiVar11;
      *(int *)(iVar8 + 0x18) = iVar7 + -1;
      ppppiVar11 = (int ****)local_30;
    } while ((int ****)local_30 != &local_30);
  }
  ExceptionList = pvStack_14;
  return;
}


// ==== 0x58e2e0 WorldZone_Query

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

undefined4 * WorldZone_Query(byte param_1)

{
  short sVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int *piVar9;
  float *in_EAX;
  int *piVar10;
  int iVar11;
  int iVar12;
  float *pfVar13;
  int *piVar14;
  int iVar15;
  int *local_1c;
  int *local_18;
  
  piVar9 = DAT_00737b20;
  fVar2 = *in_EAX;
  fVar3 = in_EAX[1];
  fVar4 = in_EAX[2];
  piVar14 = &DAT_00731330;
  local_1c = &DAT_00731330;
  local_18 = DAT_00737b20;
  piVar10 = (int *)NullUpdate_ret();
  if (piVar9 != piVar10) {
    do {
      if (&DAT_007313d0 <= piVar14) break;
      pfVar13 = *(float **)local_18[4];
      if ((((pfVar13 != (float *)0x0) &&
           (pfVar13[4] < ABS(fVar2 - *pfVar13) == (pfVar13[4] == ABS(fVar2 - *pfVar13)))) &&
          (pfVar13[5] < ABS(fVar3 - pfVar13[1]) == (pfVar13[5] == ABS(fVar3 - pfVar13[1])))) &&
         (pfVar13[6] < ABS(fVar4 - pfVar13[2]) == (pfVar13[6] == ABS(fVar4 - pfVar13[2])))) {
        if (0 < *(short *)((int)pfVar13 + 0xe)) {
          pfVar13 = (float *)WorldZone_NodeWalk(pfVar13,fVar2,fVar3,fVar4);
        }
        if (pfVar13 != (float *)0x0) {
          sVar1 = *(short *)((int)pfVar13 + 0xe);
          iVar5 = local_18[5];
          iVar12 = 0;
          if (0 < -(int)sVar1) {
            pfVar13 = pfVar13 + 7;
            do {
              if ((int *)0x7313cf < piVar14) break;
              iVar15 = *(short *)pfVar13 * 0x20 + iVar5;
              fVar6 = ABS(fVar2 - *(float *)(iVar15 + 0x10));
              fVar8 = ABS(fVar3 - *(float *)(iVar15 + 0x14));
              fVar7 = ABS(fVar4 - *(float *)(iVar15 + 0x18));
              if ((fVar6 * fVar6 + fVar8 * fVar8 + fVar7 * fVar7 <
                   *(float *)(iVar15 + 0x1c) * *(float *)(iVar15 + 0x1c)) &&
                 ((1 << (param_1 & 0x1f) & *(uint *)(iVar15 + 0xc)) != 0)) {
                iVar11 = WorldZone_CreateObject(*(undefined4 *)(iVar15 + 4));
                *(int *)(iVar11 + 0x10) = iVar15;
                *local_1c = iVar11;
                local_1c = local_1c + 1;
              }
              iVar12 = iVar12 + 1;
              pfVar13 = (float *)((int)pfVar13 + 2);
              piVar14 = local_1c;
            } while (iVar12 < -(int)sVar1);
          }
        }
      }
      local_18 = (int *)*local_18;
    } while (local_18 != piVar10);
    if (piVar14 != &DAT_00731330) {
      *piVar14 = 0;
      return &DAT_00731330;
    }
  }
  return (undefined4 *)0x0;
}


// ==== 0x58e4c0 FUN_0058e4c0

void FUN_0058e4c0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = DAT_007344d8;
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


// ==== 0x58e500 FUN_0058e500

void FUN_0058e500(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = DAT_007344d4;
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


// ==== 0x58e540 TrackMap::TrackMap

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] hud high (ghidra+hopper+capstone) docs/re/hud_input.md */

void TrackMap__TrackMap(int param_1,int param_2,int param_3)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *unaff_EBX;
  
  unaff_EBX[4] = 0;
  unaff_EBX[0x2f] = 1;
  if (((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) {
    TrackMap__InitModeTable(unaff_EBX);
    unaff_EBX[0x18] = 0;
    unaff_EBX[0x19] = 0;
    if (*(int *)(param_3 + 0x95c) != 0) {
      uVar2 = FUN_00494cb0();
      unaff_EBX[0x18] = uVar2;
    }
    if (unaff_EBX[0x18] != 0) {
      iVar3 = *(int *)(unaff_EBX[0x18] + 0x2c);
      fVar1 = *(float *)(iVar3 + 0x20);
      unaff_EBX[0x1a] = *(float *)(iVar3 + 0x1c) + 320.0;
      unaff_EBX[0x1b] = fVar1 + 240.0;
      fVar1 = *(float *)(iVar3 + 0x3c) * _K_HALF;
      unaff_EBX[0x1c] = *(float *)(iVar3 + 0x38) * _K_HALF;
      unaff_EBX[0x1d] = fVar1;
      unaff_EBX[0x27] = param_2;
      unaff_EBX[0x29] = param_1;
      unaff_EBX[0x2a] = 0;
      unaff_EBX[0x30] = 6;
      unaff_EBX[0x31] = 6;
      *unaff_EBX = 0;
      unaff_EBX[1] = 0;
      unaff_EBX[0x28] = param_3;
      unaff_EBX[4] = DAT_0073ad34;
      unaff_EBX[2] = 0;
      unaff_EBX[3] = 0;
      FUN_00565da0("TRACK%d_MAP",(int)*(short *)(unaff_EBX[0x29] + 0x6c));
      uVar2 = FUN_00567c70(0,0);
      iVar3 = Texture_FindByHash(uVar2);
      unaff_EBX[0x1e] = iVar3;
      if (iVar3 == 0) {
        unaff_EBX[0x2f] = 0;
      }
      uVar2 = FUN_00567c70(1,0);
      uVar2 = Texture_FindByHash(uVar2);
      unaff_EBX[0x1f] = uVar2;
      uVar2 = FUN_00567c70(1,0);
      uVar2 = Texture_FindByHash(uVar2);
      unaff_EBX[0x20] = uVar2;
      uVar2 = FUN_00567c70(1,0);
      uVar2 = Texture_FindByHash(uVar2);
      unaff_EBX[0x21] = uVar2;
      uVar2 = FUN_00567c70(1,0);
      uVar2 = Texture_FindByHash(uVar2);
      unaff_EBX[0x22] = uVar2;
      uVar2 = FUN_00567c70(1,0);
      uVar2 = Texture_FindByHash(uVar2);
      unaff_EBX[0x25] = uVar2;
      uVar2 = FUN_00567c70(1,0);
      uVar2 = Texture_FindByHash(uVar2);
      unaff_EBX[0x26] = uVar2;
      if (((unaff_EBX[0x1f] == 0) || (unaff_EBX[0x20] == 0)) ||
         ((unaff_EBX[0x21] == 0 || (unaff_EBX[0x22] == 0)))) {
        unaff_EBX[0x2f] = 0;
      }
      if ((DAT_0078a318 == 0) && (unaff_EBX[0x25] == 0)) {
        unaff_EBX[0x2f] = 0;
      }
      uVar2 = FUN_00565020();
      FUN_0040baf0(uVar2,uVar2);
      if (unaff_EBX[0x2f] == 0) {
        return;
      }
      TrackMap__WorldToMap();
      TrackMap__WorldToMap();
      unaff_EBX[0x2d] = 0;
      unaff_EBX[0x2e] = 0;
      return;
    }
  }
  unaff_EBX[0x2f] = 0;
  return;
}


// ==== 0x58e810 TrackMap::Draw

/* [canon] hud high (ghidra+hopper+capstone) docs/re/hud_input.md */

void TrackMap__Draw(undefined4 param_1)

{
  undefined *puVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined4 uVar8;
  int local_60;
  undefined4 local_5c;
  undefined *local_58;
  undefined *local_54;
  undefined *local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 local_30 [44];
  
  if (*(int *)(in_EAX + 0xbc) == 0) {
    return;
  }
  if (DAT_007361f8 == 0) {
    return;
  }
  if (DAT_0073619c == 0) {
    return;
  }
  *(undefined4 *)(in_EAX + 0xc4) = *(undefined4 *)(in_EAX + 0xc0);
  *(undefined4 *)(in_EAX + 0xa8) = 0;
  CallNTimes(local_30,8,4,FUN_004ad8d0);
  local_48 = 0;
  local_44 = 0;
  iVar2 = FUN_0058efb0(&local_58);
  if (iVar2 == 0) {
    return;
  }
  TrackMap__DrawBackdrop(param_1,*(undefined4 *)(in_EAX + 0x88),0xf);
  puVar4 = local_58;
  TrackMap__DrawMapQuad(in_EAX,param_1,&local_48,local_30,local_58);
  if (*(int *)(in_EAX + 0xc4) != 0xb) {
    local_40 = *(undefined4 *)(DAT_0073619c + 0x554);
    local_3c = *(undefined4 *)(DAT_0073619c + 0x558);
    iVar2 = *(int *)(in_EAX + 0xa4);
    local_38 = 0;
    iVar3 = (uint)(ushort)(*(short *)(iVar2 + 0x9a) - (short)puVar4) +
            (uint)*(ushort *)(iVar2 + 0x98);
    iVar5 = (uint)(ushort)(*(short *)(iVar2 + 0x9c) - (short)puVar4) +
            (uint)*(ushort *)(iVar2 + 0x98);
    iVar2 = iVar3;
    if ((DAT_0078a2fc == 1) && (DAT_0078a318 != 0)) {
      iVar2 = iVar5;
      iVar5 = iVar3;
    }
    iVar3 = *(int *)(in_EAX + 0xc4) * 0x3c;
    TrackMap__DrawIcon(in_EAX,param_1,&local_40,&local_48,puVar4,local_30,&DAT_007313e6,0xd,
                       *(undefined4 *)(in_EAX + 0x94),iVar2,*(undefined4 *)(&DAT_00737878 + iVar3),
                       *(undefined4 *)(&DAT_0073787c + iVar3));
    if (DAT_0078a318 != 0) {
      local_40 = *(undefined4 *)(DAT_0073619c + 0x55c);
      local_3c = *(undefined4 *)(DAT_0073619c + 0x560);
      iVar2 = *(int *)(in_EAX + 0xc4) * 0x3c;
      local_38 = 0;
      TrackMap__DrawIcon(in_EAX,param_1,&local_40,&local_48,puVar4,local_30,&DAT_007313e6,0xd,
                         *(undefined4 *)(in_EAX + 0x94),iVar5,*(undefined4 *)(&DAT_00737878 + iVar2)
                         ,*(undefined4 *)(&DAT_0073787c + iVar2));
    }
  }
  local_5c = *(undefined4 *)(in_EAX + 0x7c);
  if ((&DAT_00737882)[*(int *)(in_EAX + 0xc4) * 0x3c] != '\0') {
    local_5c = *(undefined4 *)(in_EAX + 0x80);
  }
  iVar2 = *(int *)(DAT_007361f8 + 0x1c);
  local_60 = 0;
  iVar5 = DAT_007361f8;
  if (0 < *(int *)(DAT_007361f8 + 0x20) - iVar2) {
    do {
      iVar2 = *(int *)(iVar5 + 0x28 + (iVar2 + local_60) * 4);
      if ((*(char *)(iVar2 + 0x4d0) != '\0') && (*(char *)(iVar2 + 0x8a9) != '\0')) {
        iVar3 = *(int *)(in_EAX + 0xc4) * 0x3c;
        iVar5 = 0;
        if ((&DAT_00737882)[iVar3] != '\0') {
          iVar5 = bDegreesToAngle16(0x42b40000);
          iVar5 = iVar5 + ((uint)(ushort)(*(short *)(*(int *)(in_EAX + 0xa4) + 0x98) -
                                         *(short *)(iVar2 + 0x3b4)) - (int)local_58);
        }
        puVar4 = &DAT_007313dd;
        local_50 = (undefined *)0x5;
        if (*(int *)(in_EAX + 0xa8) == iVar2) {
          puVar4 = &DAT_007313e9;
          local_50 = (undefined *)0x3;
        }
        TrackMap__DrawIcon(in_EAX,param_1,iVar2 + 0x60,&local_48,local_58,local_30,puVar4,local_50,
                           local_5c,iVar5,*(undefined4 *)(&DAT_00737874 + iVar3),
                           *(undefined4 *)(&DAT_00737874 + iVar3));
        iVar5 = DAT_007361f8;
        puVar4 = local_58;
      }
      iVar2 = *(int *)(iVar5 + 0x1c);
      local_60 = local_60 + 1;
    } while (local_60 < *(int *)(iVar5 + 0x20) - iVar2);
  }
  iVar2 = *(int *)(iVar5 + 0x20);
  local_60 = 0;
  if (*(int *)(iVar5 + 0x24) != iVar2 && -1 < *(int *)(iVar5 + 0x24) - iVar2) {
    do {
      iVar2 = *(int *)(iVar5 + 0x28 + (iVar2 + local_60) * 4);
      if ((*(char *)(iVar2 + 0x4d0) != '\0') && (*(char *)(iVar2 + 0x8a9) != '\0')) {
        iVar3 = *(int *)(in_EAX + 0xc4) * 0x3c;
        iVar5 = 0;
        if ((&DAT_00737882)[iVar3] != '\0') {
          iVar5 = ((uint)(ushort)(*(short *)(*(int *)(in_EAX + 0xa4) + 0x98) -
                                 *(short *)(iVar2 + 0x3b4)) - (int)puVar4) + 0x4000;
        }
        TrackMap__DrawIcon(in_EAX,param_1,iVar2 + 0x60,&local_48,puVar4,local_30,&DAT_007313e0,6,
                           local_5c,iVar5,*(undefined4 *)(&DAT_00737874 + iVar3),
                           *(undefined4 *)(&DAT_00737874 + iVar3));
        iVar5 = DAT_007361f8;
      }
      iVar2 = *(int *)(iVar5 + 0x20);
      local_60 = local_60 + 1;
    } while (local_60 < *(int *)(iVar5 + 0x24) - iVar2);
  }
  if (DAT_007361c4 == 1) {
    if ((((DAT_007361bc == 0) ||
         (local_50 = *(undefined **)(DAT_007361bc + 4), local_50 == (undefined *)0x0)) ||
        (local_50[0x4d0] == '\0')) || (local_50[0x8a9] == '\0')) goto LAB_0058ee82;
    local_58 = &DAT_007313d4;
    local_54 = (undefined *)0x1;
    if (*(undefined **)(in_EAX + 0xa8) == local_50) {
      local_58 = &DAT_007313e9;
      local_54 = (undefined *)0x3;
    }
    else if (*(int *)(*(int *)(local_50 + 0xc) + 0xc54) == 1) {
      local_58 = &DAT_007313da;
    }
    iVar5 = *(int *)(in_EAX + 0xc4) * 0x3c;
    iVar2 = 0;
    if ((&DAT_00737882)[iVar5] != '\0') {
      iVar2 = bDegreesToAngle16(0x42b40000);
      iVar2 = iVar2 + ((uint)(ushort)(*(short *)(*(int *)(in_EAX + 0xa4) + 0x98) -
                                     *(short *)(local_50 + 0x3b4)) - (int)puVar4);
    }
    uVar8 = *(undefined4 *)(&DAT_00737874 + iVar5);
    puVar6 = local_58;
    puVar7 = local_54;
    puVar1 = local_50;
  }
  else {
    if (DAT_007361c4 != 2) goto LAB_0058ee82;
    local_4c = *(int *)(DAT_007361b4 + 4);
    local_58 = *(undefined **)(DAT_007361b8 + 4);
    local_60 = 1;
    local_50 = (undefined *)0x2;
    if (*(char *)(*(int *)(local_58 + 0x1c) + 10) < *(char *)(*(int *)(local_4c + 0x1c) + 10)) {
      local_60 = 2;
      local_50 = (undefined *)0x1;
    }
    if ((*(char *)(local_4c + 0x4d0) != '\0') && (*(char *)(local_4c + 0x8a9) != '\0')) {
      local_54 = &DAT_007313d4;
      if (*(int *)(in_EAX + 0xa8) == local_4c) {
        local_54 = &DAT_007313e9;
        local_60 = 3;
      }
      else if (*(int *)(*(int *)(local_4c + 0xc) + 0xc54) == 1) {
        local_54 = &DAT_007313da;
      }
      iVar5 = *(int *)(in_EAX + 0xc4) * 0x3c;
      iVar2 = 0;
      if ((&DAT_00737882)[iVar5] != '\0') {
        iVar2 = bDegreesToAngle16(0x42b40000);
        iVar2 = iVar2 + ((uint)(ushort)(*(short *)(*(int *)(in_EAX + 0xa4) + 0x98) -
                                       *(short *)(local_4c + 0x3b4)) - (int)puVar4);
      }
      TrackMap__DrawIcon(in_EAX,param_1,local_4c + 0x60,&local_48,puVar4,local_30,local_54,local_60,
                         local_5c,iVar2,*(undefined4 *)(&DAT_00737874 + iVar5),
                         *(undefined4 *)(&DAT_00737874 + iVar5));
      iVar5 = DAT_007361f8;
    }
    if ((local_58[0x4d0] == '\0') || (local_58[0x8a9] == '\0')) goto LAB_0058ee82;
    local_54 = &DAT_007313d7;
    if (*(undefined **)(in_EAX + 0xa8) == local_58) {
      local_54 = &DAT_007313e9;
      local_50 = (undefined *)0x3;
    }
    else if (*(int *)(*(int *)(local_58 + 0xc) + 0xc54) == 1) {
      local_54 = &DAT_007313da;
    }
    iVar5 = *(int *)(in_EAX + 0xc4) * 0x3c;
    iVar2 = 0;
    if ((&DAT_00737882)[iVar5] != '\0') {
      iVar2 = bDegreesToAngle16(0x42b40000);
      iVar2 = iVar2 + ((uint)(ushort)(*(short *)(*(int *)(in_EAX + 0xa4) + 0x98) -
                                     *(short *)(local_58 + 0x3b4)) - (int)puVar4);
    }
    uVar8 = *(undefined4 *)(&DAT_00737874 + iVar5);
    puVar6 = local_54;
    puVar7 = local_50;
    puVar1 = local_58;
  }
  TrackMap__DrawIcon(in_EAX,param_1,puVar1 + 0x60,&local_48,puVar4,local_30,puVar6,puVar7,local_5c,
                     iVar2,uVar8,uVar8);
  iVar5 = DAT_007361f8;
LAB_0058ee82:
  local_60 = 0;
  if (0 < *(int *)(iVar5 + 0x1c)) {
    local_50 = (undefined *)0x28;
    do {
      iVar2 = *(int *)(local_50 + iVar5);
      if (((*(int *)(*(int *)(iVar2 + 0x14) + 4) == 1) &&
          (*(char *)(*(int *)(iVar2 + 0x14) + 0x734) != '\0')) &&
         ((*(char *)(iVar2 + 0x4d0) != '\0' && (*(char *)(iVar2 + 0x8a9) != '\0')))) {
        iVar3 = *(int *)(in_EAX + 0xc4) * 0x3c;
        iVar5 = 0;
        if ((&DAT_00737882)[iVar3] != '\0') {
          iVar5 = ((uint)(ushort)(*(short *)(*(int *)(in_EAX + 0xa4) + 0x98) -
                                 *(short *)(iVar2 + 0x3b4)) - (int)puVar4) + 0x4000;
        }
        local_54 = &DAT_007313ef;
        local_4c = 5;
        if (*(int *)(in_EAX + 0xa8) == iVar2) {
          local_54 = &DAT_007313e9;
          local_4c = 3;
        }
        TrackMap__DrawIcon(in_EAX,param_1,iVar2 + 0x60,&local_48,puVar4,local_30,local_54,local_4c,
                           local_5c,iVar5,*(undefined4 *)(&DAT_00737874 + iVar3),
                           *(undefined4 *)(&DAT_00737874 + iVar3));
        iVar5 = DAT_007361f8;
      }
      local_60 = local_60 + 1;
      local_50 = local_50 + 4;
    } while (local_60 < *(int *)(iVar5 + 0x1c));
  }
  TrackMap__DrawBackdrop(param_1,*(undefined4 *)(in_EAX + 0x84),0);
  return;
}


// ==== 0x58efb0 FUN_0058efb0

undefined4 FUN_0058efb0(short *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  undefined4 extraout_EDX;
  undefined4 *unaff_ESI;
  undefined4 local_20;
  undefined4 local_1c;
  
  if ((&DAT_00737880)[unaff_ESI[0x31] * 0x3c] == '\0') {
    *param_1 = -0x8000;
    return 1;
  }
  iVar4 = FUN_005910f0(unaff_ESI);
  if (iVar4 == 0) {
    return 0;
  }
  uVar1 = *unaff_ESI;
  uVar2 = unaff_ESI[1];
  FUN_005919d0(local_20,(float)(DAT_0073ad34 - unaff_ESI[4]) * 0.9 * 0.00025);
  FUN_005919d0(local_1c,extraout_EDX);
  *unaff_ESI = uVar1;
  unaff_ESI[1] = uVar2;
  unaff_ESI[4] = DAT_0073ad34;
  sVar3 = Atan2ToAngle16(uVar2,uVar1);
  *param_1 = sVar3 + -0x8000;
  return 1;
}


// ==== 0x58f090 TrackMap::DrawMapQuad

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] hud high (ghidra+hopper+capstone) docs/re/hud_input.md */

void TrackMap__DrawMapQuad(int param_1,undefined4 param_2,float *param_3,undefined4 *param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float local_11c;
  undefined4 local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c0;
  float local_bc;
  float local_b8;
  undefined1 local_b0 [80];
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  undefined1 local_2d;
  undefined1 local_29;
  undefined1 local_25;
  undefined1 local_21;
  
  if (DAT_0078a320 == 2) {
    FUN_00414a10();
    FUN_00414a10();
  }
  if ((&DAT_00737888)[*(int *)(param_1 + 0xc4) * 0x3c] == '\0') {
    if ((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) {
      if (DAT_0078a320 == 1) {
        FUN_00414a10();
        FUN_00414a10();
        return;
      }
      if (DAT_0078a320 == 2) {
        FUN_00414a10();
        FUN_00414a10();
        return;
      }
    }
  }
  else {
    if ((*(int *)(param_1 + 0xc4) == 0xb) && ((DAT_0078a344 != '\0' || (DAT_007361a8 != 0)))) {
      if (DAT_0078a320 == 1) {
        FUN_00414a60();
      }
      else {
        FUN_00414a60();
      }
      FUN_00414a60();
    }
    FUN_0040be70();
    local_118 = 0;
    local_114 = 0.0;
    TrackMap__WorldToMap();
    local_54 = _K_ONE;
    iVar4 = *(int *)(param_1 + 0xc4) * 0x3c;
    if ((&DAT_00737881)[iVar4] == '\0') {
      *param_4 = 0;
      local_110 = 0.0;
      param_4[1] = 0;
      local_10c = 0.0;
      param_4[2] = 0x3f800000;
      param_4[3] = 0;
      local_104 = 0.0;
      param_4[4] = 0x3f800000;
      local_100 = 1.0;
      param_4[5] = 0x3f800000;
      local_fc = 1.0;
      param_4[6] = 0;
      local_f8 = 0.0;
      param_4[7] = 0x3f800000;
      local_f4 = 1.0;
    }
    else {
      if (((&DAT_00737870)[iVar4] == '\0') || (iVar3 = *(int *)(param_1 + 0xa8), iVar3 == 0)) {
        fVar2 = *(float *)(&DAT_00737868 + iVar4);
        fVar1 = *(float *)(&DAT_0073786c + iVar4);
        local_11c = (*(float *)(&DAT_00737868 + iVar4) + *(float *)(&DAT_0073786c + iVar4)) *
                    _K_HALF;
      }
      else {
        fVar2 = *(float *)(*(int *)(param_1 + 0x9c) + 0x60) - *(float *)(iVar3 + 0x60);
        fVar1 = *(float *)(*(int *)(param_1 + 0x9c) + 100) - *(float *)(iVar3 + 100);
        fVar2 = ((*(float *)(&DAT_00737860 + iVar4) + *(float *)(param_1 + 0x70)) /
                *(float *)(param_1 + 0x70)) *
                (SQRT(fVar2 * fVar2 + fVar1 * fVar1) / *(float *)(*(int *)(param_1 + 0xa4) + 0x94))
                + 0.1;
        fVar1 = fVar2;
        local_11c = fVar2;
      }
      *(float *)(param_1 + 0xac) = fVar2;
      *(float *)(param_1 + 0xb0) = fVar1;
      FUN_00590b50(param_1,&local_118,fVar2,fVar1,local_11c,local_11c);
      FUN_00590b50(param_1,&local_118,fVar2 * 1.2,fVar1 * 1.2,local_11c * 1.2,local_11c * 1.2);
      local_54 = local_108;
    }
    local_5c = local_10c;
    local_44 = local_fc;
    local_60 = local_110;
    local_50 = local_104;
    local_48 = local_100;
    local_3c = local_f8;
    local_38 = local_f4;
    local_e8 = 0.0;
    local_c8 = 0.0;
    local_b8 = 0.0;
    local_d8 = 0.0;
    local_114 = (local_f4 + local_fc + local_10c) * 0.33333334;
    *param_3 = ((local_f8 + local_100 + local_110) * 0.33333334 +
               (local_54 + local_100 + local_110) * 0.33333334) * _K_HALF;
    param_3[1] = (local_114 + (local_fc + local_104 + local_10c) * 0.33333334) * _K_HALF;
    iVar4 = *(int *)(param_1 + 0xc4) * 0x3c;
    local_d0 = *(float *)(&DAT_00737860 + iVar4) + *(float *)(param_1 + 0x70);
    local_dc = *(float *)(&DAT_00737864 + iVar4) + *(float *)(param_1 + 0x74);
    local_f0 = -local_d0;
    local_ec = -local_dc;
    local_e0 = local_f0;
    local_cc = local_ec;
    local_c0 = local_d0;
    local_bc = local_dc;
    FUN_00590dd0(param_1,&local_d0,&local_c0,&local_e0);
    iVar4 = *(int *)(param_1 + 0xc4);
    local_2d = _ftol_nocw();
    local_29 = _ftol_nocw();
    local_25 = _ftol_nocw();
    local_21 = _ftol_nocw();
    fVar2 = *(float *)(&DAT_00737854 + iVar4 * 0x3c);
    fVar1 = _K_ONE / (local_e8 + fVar2);
    local_60 = local_60 * fVar1;
    local_5c = local_5c * fVar1;
    local_58 = local_58 * fVar1;
    fVar1 = _K_ONE / (local_c8 + fVar2);
    local_54 = local_54 * fVar1;
    local_50 = local_50 * fVar1;
    local_4c = local_4c * fVar1;
    fVar1 = _K_ONE / (local_b8 + fVar2);
    local_48 = local_48 * fVar1;
    local_44 = local_44 * fVar1;
    local_40 = local_40 * fVar1;
    fVar2 = _K_ONE / (fVar2 + local_d8);
    local_3c = local_3c * fVar2;
    local_38 = local_38 * fVar2;
    local_34 = local_34 * fVar2;
    Poly2D__ClipToRect(param_2,local_b0,*(undefined4 *)(param_1 + 0x78),0xe);
  }
  return;
}


// ==== 0x58f640 TrackMap::DrawIcon

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void TrackMap__DrawIcon(int param_1,undefined4 param_2,undefined4 param_3,float *param_4,
                       undefined4 param_5,undefined4 param_6,undefined1 *param_7,undefined4 param_8,
                       undefined4 param_9,undefined4 param_10,float param_11,float param_12)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  float fStack_1c4;
  float fStack_1c0;
  float fStack_1bc;
  float local_1b8;
  undefined4 local_1b4;
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
  undefined1 auStack_17c [12];
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
  float local_148;
  float local_144;
  undefined4 local_140;
  undefined4 local_13c;
  float local_138;
  float local_134;
  undefined4 uStack_130;
  float fStack_128;
  float fStack_124;
  undefined4 uStack_120;
  float fStack_118;
  float fStack_114;
  undefined4 uStack_110;
  undefined1 auStack_108 [16];
  float fStack_f8;
  float fStack_f4;
  float fStack_e8;
  float fStack_e4;
  float fStack_d8;
  float fStack_d4;
  float fStack_c8;
  float fStack_c4;
  undefined1 uStack_88;
  undefined1 uStack_87;
  undefined1 uStack_86;
  undefined1 uStack_84;
  undefined1 uStack_83;
  undefined1 uStack_82;
  undefined1 uStack_80;
  undefined1 uStack_7f;
  undefined1 uStack_7e;
  undefined1 uStack_7c;
  undefined1 uStack_7b;
  undefined1 uStack_7a;
  undefined1 local_50 [76];
  
  if ((&DAT_00737888)[*(int *)(param_1 + 0xc4) * 0x3c] != '\0') {
    local_1b8 = 0.0;
    local_1b4 = 0;
    TrackMap__WorldToMap();
    cVar3 = PointInPolygon2D(param_6,4);
    if (cVar3 != '\0') {
      FUN_0040be70();
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
      local_148 = 1.0;
      local_144 = 0.0;
      local_140 = 0;
      local_13c = 0;
      local_138 = 0.0;
      local_134 = 1.0;
      FUN_0040b930();
      D3DXMatrixMultiply(&local_170,&local_170,local_50);
      fStack_1bc = fStack_1c4 - *param_4;
      local_1b4 = 0;
      local_1b8 = fStack_1c0 - param_4[1];
      D3DXVec3Transform(&fStack_1bc,&fStack_1bc,auStack_17c);
      CallNTimes(&fStack_1a8,8,4,FUN_004ad8d0);
      fStack_1ac = param_11 * _K_HALF;
      fStack_1b0 = param_12 * _K_HALF;
      FUN_00590b50(param_1,&stack0xfffffe30,fStack_1b0,fStack_1b0,fStack_1ac,fStack_1ac);
      iVar4 = *(int *)(param_1 + 0xc4) * 0x3c;
      uStack_120 = 0;
      uStack_130 = 0;
      fVar1 = *(float *)(&DAT_00737860 + iVar4) + *(float *)(param_1 + 0x70);
      fVar1 = fVar1 + fVar1;
      fVar2 = *(float *)(&DAT_00737864 + iVar4) + *(float *)(param_1 + 0x74);
      fVar2 = fVar2 + fVar2;
      fStack_128 = -(fStack_1a8 * fVar1);
      fStack_124 = -(fStack_1a4 * fVar2);
      local_138 = -(fStack_1a0 * fVar1);
      local_134 = -(fStack_19c * fVar2);
      local_148 = -(fStack_198 * fVar1);
      local_144 = -(fStack_194 * fVar2);
      fStack_118 = -(fStack_190 * fVar1);
      fStack_114 = -(fStack_18c * fVar2);
      local_140 = 0;
      uStack_110 = 0;
      fStack_f8 = fStack_128;
      fStack_f4 = fStack_124;
      fStack_e8 = local_138;
      fStack_e4 = local_134;
      fStack_d8 = local_148;
      fStack_d4 = local_144;
      fStack_c8 = fStack_118;
      fStack_c4 = fStack_114;
      FUN_00590dd0(param_1,&local_138,&local_148,&fStack_118);
      uStack_86 = param_7[2];
      uStack_88 = *param_7;
      uStack_87 = param_7[1];
      uStack_84 = uStack_88;
      uStack_83 = uStack_87;
      uStack_82 = uStack_86;
      uStack_80 = uStack_88;
      uStack_7f = uStack_87;
      uStack_7e = uStack_86;
      uStack_7c = uStack_88;
      uStack_7b = uStack_87;
      uStack_7a = uStack_86;
      Poly2D__ClipToRect(param_2,auStack_108,param_9,param_8);
    }
  }
  return;
}


// ==== 0x58fa50 TrackMap::DrawBackdrop

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void TrackMap__DrawBackdrop(void)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = *(int *)(in_EAX + 0xc4) * 0x3c;
  if ((&DAT_00737889)[iVar1] != '\0') {
    FUN_0040be70();
    if ((&DAT_00737888)[iVar1] != '\0') {
      FUN_0040bef0();
    }
  }
  return;
}


// ==== 0x58fb10 Poly2D::ClipToRect

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void Poly2D__ClipToRect(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  byte bVar9;
  byte bVar10;
  undefined1 uVar11;
  float fVar12;
  float fVar13;
  undefined1 uVar14;
  int in_EAX;
  int iVar15;
  int iVar16;
  undefined1 *puVar17;
  float *pfVar18;
  uint uVar19;
  int iVar20;
  float *pfVar21;
  undefined1 *puVar22;
  uint uVar23;
  float **ppfVar24;
  int iVar25;
  float *pfVar26;
  undefined4 *puVar27;
  float *local_22c;
  int local_228;
  int local_224;
  undefined1 *local_220;
  int local_21c;
  int local_218;
  undefined1 *local_210;
  int local_20c;
  float local_208 [5];
  float local_1f4;
  float local_1f0;
  float local_1ec;
  undefined4 local_1e8;
  undefined1 auStack_1e4 [4];
  float local_1e0;
  float local_1dc;
  float local_1d8;
  float *local_1c4 [4];
  int local_1b4;
  float local_1b0 [16];
  float local_170 [16];
  undefined4 local_130;
  float local_12c [5];
  float local_118 [3];
  float local_10c [11];
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d0 [8];
  undefined1 local_b0;
  undefined1 local_af;
  undefined1 local_ae;
  undefined1 local_ad;
  undefined1 local_ac [17];
  undefined1 local_9b;
  float local_90 [35];
  
  local_208[0] = *(float *)(in_EAX + 0x68) - *(float *)(in_EAX + 0x70);
  local_210 = (undefined1 *)(param_2 + 0x83);
  local_208[1] = *(float *)(in_EAX + 0x6c) - *(float *)(in_EAX + 0x74);
  pfVar21 = (float *)(param_2 + 0x54);
  pfVar26 = local_12c;
  local_208[2] = *(float *)(in_EAX + 0x68) + *(float *)(in_EAX + 0x70);
  local_208[3] = local_208[1];
  local_208[4] = local_208[2];
  local_1f4 = *(float *)(in_EAX + 0x6c) + *(float *)(in_EAX + 0x74);
  iVar15 = 0;
  pfVar18 = (float *)(param_2 + 0x14);
  local_1f0 = local_208[0];
  local_1ec = local_1f4;
  do {
    local_170[iVar15 * 2] = pfVar18[-1];
    local_170[iVar15 * 2 + 1] = *pfVar18;
    pfVar26[-1] = pfVar21[-1];
    *pfVar26 = *pfVar21;
    pfVar26[1] = pfVar21[1];
    auStack_1e4[iVar15 + -4] = *local_210;
    iVar15 = iVar15 + 1;
    local_210 = local_210 + 4;
    pfVar21 = pfVar21 + 3;
    pfVar18 = pfVar18 + 4;
    pfVar26 = pfVar26 + 4;
  } while (iVar15 < 4);
  local_210 = (undefined1 *)0x4;
  local_21c = 0;
  local_224 = 0x18;
  do {
    uVar23 = 0;
    puVar17 = (undefined1 *)((int)local_210 - 1);
    local_220 = (undefined1 *)0x0;
    if (3 < (int)local_210) {
      local_20c = (int)puVar17 * 0x10;
      local_22c = local_90;
      local_1c4[2] = (float *)(0x30 - (int)local_118);
      pfVar21 = local_170 + 5;
      pfVar26 = local_118;
      local_1c4[3] = (float *)(3 - (int)&local_1e8);
      do {
        fVar2 = -(*(float *)((int)local_208 + local_224) - *(float *)((int)local_208 + local_21c)) *
                (pfVar21[-4] - *(float *)((int)local_208 + local_21c + 4)) +
                (pfVar21[-5] - *(float *)((int)local_208 + local_21c)) *
                (*(float *)((int)local_208 + local_224 + 4) -
                *(float *)((int)local_208 + local_21c + 4));
        if (fVar2 <= 0.0) {
          if (0.0 <= fVar2) {
            iVar15 = 0;
          }
          else {
            iVar15 = -1;
          }
        }
        else {
          iVar15 = 1;
        }
        fVar2 = -(*(float *)((int)local_208 + local_224) - *(float *)((int)local_208 + local_21c)) *
                (local_170[(int)puVar17 * 2 + 1] - *(float *)((int)local_208 + local_21c + 4)) +
                (local_170[(int)puVar17 * 2] - *(float *)((int)local_208 + local_21c)) *
                (*(float *)((int)local_208 + local_224 + 4) -
                *(float *)((int)local_208 + local_21c + 4));
        if (fVar2 <= 0.0) {
          if (0.0 <= fVar2) {
            iVar16 = 0;
          }
          else {
            iVar16 = -1;
          }
        }
        else {
          iVar16 = 1;
        }
        if (iVar16 != -1) {
          fVar2 = local_170[(int)puVar17 * 2 + 1];
          fVar12 = *(float *)((int)&local_130 + local_20c);
          local_1b0[uVar23 * 2] = local_170[(int)puVar17 * 2];
          *local_22c = fVar12;
          local_1b0[uVar23 * 2 + 1] = fVar2;
          local_22c[1] = *(float *)((int)local_12c + local_20c);
          uVar14 = auStack_1e4[(int)(puVar17 + -4)];
          local_22c[2] = *(float *)((int)local_12c + local_20c + 4);
          *(undefined1 *)((int)local_1c4 + uVar23) = uVar14;
          local_22c = local_22c + 4;
          uVar23 = uVar23 + 1;
        }
        if ((iVar15 != -1) != (iVar16 != -1)) {
          fVar2 = local_170[(int)puVar17 * 2];
          fVar12 = pfVar21[-5];
          fVar5 = *(float *)((int)local_208 + local_224 + 4) -
                  *(float *)((int)local_208 + local_21c + 4);
          fVar3 = local_170[(int)puVar17 * 2 + 1];
          fVar4 = pfVar21[-4];
          fVar6 = *(float *)((int)local_208 + local_224) - *(float *)((int)local_208 + local_21c);
          fVar13 = ((pfVar21[-4] - *(float *)((int)local_208 + local_21c + 4)) * fVar6 -
                   (pfVar21[-5] - *(float *)((int)local_208 + local_21c)) * fVar5) /
                   ((fVar2 - fVar12) * fVar5 - (fVar3 - fVar4) * fVar6);
          fVar5 = pfVar21[-5];
          fVar6 = pfVar21[-4];
          local_1e0 = (*(float *)((int)&local_130 + local_20c) - pfVar26[-6]) * fVar13 + pfVar26[-6]
          ;
          local_1dc = (*(float *)((int)local_12c + local_20c) - pfVar26[-5]) * fVar13 + pfVar26[-5];
          fVar7 = *(float *)((int)local_12c + local_20c + 4);
          fVar8 = pfVar26[-4];
          *local_22c = local_1e0;
          local_22c[1] = local_1dc;
          local_1d8 = (fVar7 - fVar8) * fVar13 + pfVar26[-4];
          local_22c[2] = local_1d8;
          local_1b0[uVar23 * 2] = (fVar2 - fVar12) * fVar13 + fVar5;
          local_1b0[uVar23 * 2 + 1] = (fVar3 - fVar4) * fVar13 + fVar6;
          uVar14 = _ftol_nocw();
          *(undefined1 *)((int)local_1c4 + uVar23) = uVar14;
          uVar23 = uVar23 + 1;
          local_22c = local_22c + 4;
        }
        fVar2 = -(*(float *)((int)local_208 + local_224) - *(float *)((int)local_208 + local_21c)) *
                (pfVar21[-2] - *(float *)((int)local_208 + local_21c + 4)) +
                (pfVar21[-3] - *(float *)((int)local_208 + local_21c)) *
                (*(float *)((int)local_208 + local_224 + 4) -
                *(float *)((int)local_208 + local_21c + 4));
        if (fVar2 <= 0.0) {
          if (0.0 <= fVar2) {
            iVar15 = 0;
          }
          else {
            iVar15 = -1;
          }
        }
        else {
          iVar15 = 1;
        }
        fVar2 = -(*(float *)((int)local_208 + local_224) - *(float *)((int)local_208 + local_21c)) *
                (pfVar21[-4] - *(float *)((int)local_208 + local_21c + 4)) +
                (pfVar21[-5] - *(float *)((int)local_208 + local_21c)) *
                (*(float *)((int)local_208 + local_224 + 4) -
                *(float *)((int)local_208 + local_21c + 4));
        if (fVar2 <= 0.0) {
          if (0.0 <= fVar2) {
            iVar16 = 0;
          }
          else {
            iVar16 = -1;
          }
        }
        else {
          iVar16 = 1;
        }
        if (iVar16 != -1) {
          fVar2 = pfVar26[-6];
          fVar12 = pfVar21[-5];
          local_1b0[uVar23 * 2 + 1] = pfVar21[-4];
          *local_22c = fVar2;
          fVar2 = pfVar26[-5];
          local_1b0[uVar23 * 2] = fVar12;
          uVar14 = auStack_1e4[(int)(local_220 + -4)];
          local_22c[1] = fVar2;
          fVar2 = pfVar26[-4];
          *(undefined1 *)((int)local_1c4 + uVar23) = uVar14;
          local_22c[2] = fVar2;
          uVar23 = uVar23 + 1;
          local_22c = local_22c + 4;
        }
        if ((iVar15 != -1) != (iVar16 != -1)) {
          fVar2 = pfVar21[-5];
          fVar12 = pfVar21[-3];
          fVar5 = *(float *)((int)local_208 + local_224 + 4) -
                  *(float *)((int)local_208 + local_21c + 4);
          fVar3 = pfVar21[-4];
          fVar4 = pfVar21[-2];
          fVar6 = *(float *)((int)local_208 + local_224) - *(float *)((int)local_208 + local_21c);
          fVar8 = ((pfVar21[-2] - *(float *)((int)local_208 + local_21c + 4)) * fVar6 -
                  (pfVar21[-3] - *(float *)((int)local_208 + local_21c)) * fVar5) /
                  ((fVar2 - fVar12) * fVar5 - (fVar3 - fVar4) * fVar6);
          fVar5 = pfVar21[-3];
          fVar6 = pfVar21[-2];
          local_1e0 = (pfVar26[-6] - pfVar26[-2]) * fVar8 + pfVar26[-2];
          fVar7 = pfVar26[-5];
          *local_22c = local_1e0;
          local_1dc = (fVar7 - pfVar26[-1]) * fVar8 + pfVar26[-1];
          fVar7 = pfVar26[-4];
          local_22c[1] = local_1dc;
          local_1d8 = (fVar7 - *pfVar26) * fVar8 + *pfVar26;
          local_22c[2] = local_1d8;
          local_1b0[uVar23 * 2] = (fVar2 - fVar12) * fVar8 + fVar5;
          local_1b0[uVar23 * 2 + 1] = (fVar3 - fVar4) * fVar8 + fVar6;
          uVar14 = _ftol_nocw();
          *(undefined1 *)((int)local_1c4 + uVar23) = uVar14;
          uVar23 = uVar23 + 1;
          local_22c = local_22c + 4;
        }
        fVar2 = -(*(float *)((int)local_208 + local_224) - *(float *)((int)local_208 + local_21c)) *
                (*pfVar21 - *(float *)((int)local_208 + local_21c + 4)) +
                (pfVar21[-1] - *(float *)((int)local_208 + local_21c)) *
                (*(float *)((int)local_208 + local_224 + 4) -
                *(float *)((int)local_208 + local_21c + 4));
        if (fVar2 <= 0.0) {
          if (0.0 <= fVar2) {
            iVar15 = 0;
          }
          else {
            iVar15 = -1;
          }
        }
        else {
          iVar15 = 1;
        }
        fVar2 = -(*(float *)((int)local_208 + local_224) - *(float *)((int)local_208 + local_21c)) *
                (pfVar21[-2] - *(float *)((int)local_208 + local_21c + 4)) +
                (pfVar21[-3] - *(float *)((int)local_208 + local_21c)) *
                (*(float *)((int)local_208 + local_224 + 4) -
                *(float *)((int)local_208 + local_21c + 4));
        if (fVar2 <= 0.0) {
          if (0.0 <= fVar2) {
            iVar16 = 0;
          }
          else {
            iVar16 = -1;
          }
        }
        else {
          iVar16 = 1;
        }
        if (iVar16 != -1) {
          fVar2 = pfVar26[-2];
          fVar12 = pfVar21[-2];
          local_1b0[uVar23 * 2] = pfVar21[-3];
          local_1b0[uVar23 * 2 + 1] = fVar12;
          local_22c[2] = *pfVar26;
          uVar14 = auStack_1e4[(int)(local_220 + -3)];
          *local_22c = fVar2;
          fVar2 = pfVar26[-1];
          *(undefined1 *)((int)local_1c4 + uVar23) = uVar14;
          local_22c[1] = fVar2;
          uVar23 = uVar23 + 1;
          local_22c = local_22c + 4;
        }
        if ((iVar15 != -1) != (iVar16 != -1)) {
          fVar2 = pfVar21[-3];
          fVar12 = pfVar21[-1];
          fVar5 = *(float *)((int)local_208 + local_224 + 4) -
                  *(float *)((int)local_208 + local_21c + 4);
          fVar3 = pfVar21[-2];
          fVar4 = *pfVar21;
          fVar6 = *(float *)((int)local_208 + local_224) - *(float *)((int)local_208 + local_21c);
          fVar8 = ((*pfVar21 - *(float *)((int)local_208 + local_21c + 4)) * fVar6 -
                  (pfVar21[-1] - *(float *)((int)local_208 + local_21c)) * fVar5) /
                  (fVar5 * (fVar2 - fVar12) - fVar6 * (fVar3 - fVar4));
          fVar5 = pfVar21[-1];
          fVar6 = *pfVar21;
          local_1e0 = (pfVar26[-2] - pfVar26[2]) * fVar8 + pfVar26[2];
          fVar7 = pfVar26[-1];
          *local_22c = local_1e0;
          local_1dc = (fVar7 - pfVar26[3]) * fVar8 + pfVar26[3];
          fVar7 = *pfVar26;
          local_22c[1] = local_1dc;
          local_1d8 = (fVar7 - pfVar26[4]) * fVar8 + pfVar26[4];
          local_22c[2] = local_1d8;
          local_1b0[uVar23 * 2] = fVar8 * (fVar2 - fVar12) + fVar5;
          local_1b0[uVar23 * 2 + 1] = fVar8 * (fVar3 - fVar4) + fVar6;
          uVar14 = _ftol_nocw();
          *(undefined1 *)((int)local_1c4 + uVar23) = uVar14;
          uVar23 = uVar23 + 1;
          local_22c = local_22c + 4;
        }
        fVar2 = -(*(float *)((int)local_208 + local_224) - *(float *)((int)local_208 + local_21c)) *
                (pfVar21[2] - *(float *)((int)local_208 + local_21c + 4)) +
                (pfVar21[1] - *(float *)((int)local_208 + local_21c)) *
                (*(float *)((int)local_208 + local_224 + 4) -
                *(float *)((int)local_208 + local_21c + 4));
        if (fVar2 <= 0.0) {
          if (0.0 <= fVar2) {
            iVar15 = 0;
          }
          else {
            iVar15 = -1;
          }
        }
        else {
          iVar15 = 1;
        }
        fVar2 = -(*(float *)((int)local_208 + local_224) - *(float *)((int)local_208 + local_21c)) *
                (*pfVar21 - *(float *)((int)local_208 + local_21c + 4)) +
                (pfVar21[-1] - *(float *)((int)local_208 + local_21c)) *
                (*(float *)((int)local_208 + local_224 + 4) -
                *(float *)((int)local_208 + local_21c + 4));
        if (fVar2 <= 0.0) {
          if (0.0 <= fVar2) {
            iVar16 = 0;
          }
          else {
            iVar16 = -1;
          }
        }
        else {
          iVar16 = 1;
        }
        if (iVar16 != -1) {
          fVar2 = pfVar26[2];
          fVar12 = *pfVar21;
          local_1b0[uVar23 * 2] = pfVar21[-1];
          *local_22c = fVar2;
          fVar2 = pfVar26[3];
          local_1b0[uVar23 * 2 + 1] = fVar12;
          uVar14 = auStack_1e4[(int)(local_220 + -2)];
          local_22c[1] = fVar2;
          fVar2 = pfVar26[4];
          *(undefined1 *)((int)local_1c4 + uVar23) = uVar14;
          local_22c[2] = fVar2;
          uVar23 = uVar23 + 1;
          local_22c = local_22c + 4;
        }
        if ((iVar15 != -1) != (iVar16 != -1)) {
          fVar2 = pfVar21[-1];
          fVar12 = pfVar21[1];
          fVar5 = *(float *)((int)local_208 + local_224 + 4) -
                  *(float *)((int)local_208 + local_21c + 4);
          fVar3 = *pfVar21;
          fVar4 = pfVar21[2];
          fVar6 = *(float *)((int)local_208 + local_224) - *(float *)((int)local_208 + local_21c);
          fVar8 = ((pfVar21[2] - *(float *)((int)local_208 + local_21c + 4)) * fVar6 -
                  (pfVar21[1] - *(float *)((int)local_208 + local_21c)) * fVar5) /
                  (fVar5 * (fVar2 - fVar12) - fVar6 * (fVar3 - fVar4));
          fVar5 = pfVar21[1];
          fVar6 = pfVar21[2];
          local_1e0 = (pfVar26[2] - pfVar26[6]) * fVar8 + pfVar26[6];
          fVar7 = pfVar26[3];
          *local_22c = local_1e0;
          local_1dc = (fVar7 - pfVar26[7]) * fVar8 + pfVar26[7];
          fVar7 = pfVar26[4];
          local_22c[1] = local_1dc;
          local_1d8 = (fVar7 - pfVar26[8]) * fVar8 + pfVar26[8];
          local_22c[2] = local_1d8;
          local_1b0[uVar23 * 2] = (fVar2 - fVar12) * fVar8 + fVar5;
          local_1b0[uVar23 * 2 + 1] = (fVar3 - fVar4) * fVar8 + fVar6;
          uVar14 = _ftol_nocw();
          *(undefined1 *)((int)local_1c4 + uVar23) = uVar14;
          uVar23 = uVar23 + 1;
          local_22c = local_22c + 4;
        }
        local_20c = (int)local_1c4[2] + (int)pfVar26;
        puVar22 = local_220 + 4;
        puVar17 = auStack_1e4 + (int)(local_220 + (int)local_1c4[3] + -4);
        pfVar21 = pfVar21 + 8;
        pfVar26 = pfVar26 + 0x10;
        local_220 = puVar22;
      } while ((int)(auStack_1e4 + (int)(puVar22 + (int)local_1c4[3] + -4)) < (int)local_210);
    }
    if ((int)local_220 < (int)local_210) {
      pfVar21 = (float *)((int)local_208 + local_224);
      local_22c = (float *)((int)local_220 << 4);
      local_228 = (int)puVar17 << 4;
      pfVar26 = (float *)((int)local_208 + local_21c);
      pfVar18 = local_90 + uVar23 * 4;
      do {
        pfVar1 = local_170 + (int)local_220 * 2;
        fVar2 = -(*pfVar21 - *pfVar26) *
                (local_170[(int)local_220 * 2 + 1] - *(float *)((int)local_208 + local_21c + 4)) +
                (*pfVar1 - *pfVar26) *
                (*(float *)((int)local_208 + local_224 + 4) -
                *(float *)((int)local_208 + local_21c + 4));
        if (fVar2 <= 0.0) {
          if (0.0 <= fVar2) {
            iVar15 = 0;
          }
          else {
            iVar15 = -1;
          }
        }
        else {
          iVar15 = 1;
        }
        fVar2 = -(*pfVar21 - *pfVar26) *
                (local_170[(int)puVar17 * 2 + 1] - *(float *)((int)local_208 + local_21c + 4)) +
                (local_170[(int)puVar17 * 2] - *pfVar26) *
                (*(float *)((int)local_208 + local_224 + 4) -
                *(float *)((int)local_208 + local_21c + 4));
        if (fVar2 <= 0.0) {
          if (0.0 <= fVar2) {
            iVar16 = 0;
          }
          else {
            iVar16 = -1;
          }
        }
        else {
          iVar16 = 1;
        }
        if (iVar16 != -1) {
          fVar12 = local_170[(int)puVar17 * 2];
          local_1b0[uVar23 * 2 + 1] = local_170[(int)puVar17 * 2 + 1];
          fVar2 = *(float *)((int)local_12c + local_228);
          local_1b0[uVar23 * 2] = fVar12;
          fVar12 = *(float *)((int)&local_130 + local_228);
          pfVar18[1] = fVar2;
          fVar2 = *(float *)((int)local_12c + local_228 + 4);
          *(undefined1 *)((int)local_1c4 + uVar23) = auStack_1e4[(int)(puVar17 + -4)];
          pfVar18[2] = fVar2;
          *pfVar18 = fVar12;
          uVar23 = uVar23 + 1;
          pfVar18 = pfVar18 + 4;
        }
        if ((iVar15 != -1) != (iVar16 != -1)) {
          fVar2 = local_170[(int)puVar17 * 2];
          fVar12 = *pfVar1;
          fVar5 = *(float *)((int)local_208 + local_224 + 4) -
                  *(float *)((int)local_208 + local_21c + 4);
          fVar3 = local_170[(int)puVar17 * 2 + 1];
          bVar9 = auStack_1e4[(int)(puVar17 + -4)];
          fVar4 = local_170[(int)local_220 * 2 + 1];
          fVar13 = ((local_170[(int)local_220 * 2 + 1] - *(float *)((int)local_208 + local_21c + 4))
                    * (*pfVar21 - *pfVar26) - (*pfVar1 - *pfVar26) * fVar5) /
                   (fVar5 * (fVar2 - fVar12) - (*pfVar21 - *pfVar26) * (fVar3 - fVar4));
          fVar5 = *pfVar1;
          fVar6 = local_170[(int)local_220 * 2 + 1];
          local_1e0 = (*(float *)((int)&local_130 + local_228) -
                      *(float *)((int)&local_130 + (int)local_22c)) * fVar13 +
                      *(float *)((int)&local_130 + (int)local_22c);
          local_1dc = (*(float *)((int)local_12c + local_228) -
                      *(float *)((int)local_12c + (int)local_22c)) * fVar13 +
                      *(float *)((int)local_12c + (int)local_22c);
          fVar7 = *(float *)((int)local_12c + local_228 + 4);
          fVar8 = *(float *)((int)local_12c + (int)local_22c + 4);
          *pfVar18 = local_1e0;
          local_1d8 = (fVar7 - fVar8) * fVar13 + *(float *)((int)local_12c + (int)local_22c + 4);
          pfVar18[1] = local_1dc;
          pfVar18[2] = local_1d8;
          local_1b0[uVar23 * 2] = (fVar2 - fVar12) * fVar13 + fVar5;
          bVar10 = auStack_1e4[(int)(local_220 + -4)];
          local_1b0[uVar23 * 2 + 1] = fVar13 * (fVar3 - fVar4) + fVar6;
          local_1c4[2] = (float *)((uint)bVar9 - (uint)bVar10);
          uVar14 = _ftol_nocw();
          *(undefined1 *)((int)local_1c4 + uVar23) = uVar14;
          uVar23 = uVar23 + 1;
          pfVar18 = pfVar18 + 4;
        }
        local_228 = (int)local_22c;
        local_22c = (float *)((int)local_22c + 0x10);
        puVar22 = local_220 + 1;
        puVar17 = local_220;
        local_220 = puVar22;
      } while ((int)puVar22 < (int)local_210);
    }
    pfVar21 = local_1b0;
    pfVar26 = local_170;
    for (iVar15 = uVar23 * 2; iVar15 != 0; iVar15 = iVar15 + -1) {
      *pfVar26 = *pfVar21;
      pfVar21 = pfVar21 + 1;
      pfVar26 = pfVar26 + 1;
    }
    local_224 = local_21c;
    pfVar21 = local_90;
    pfVar26 = (float *)&local_130;
    for (iVar15 = (uVar23 & 0xfffffff) << 2; iVar15 != 0; iVar15 = iVar15 + -1) {
      *pfVar26 = *pfVar21;
      pfVar21 = pfVar21 + 1;
      pfVar26 = pfVar26 + 1;
    }
    for (iVar15 = 0; iVar15 != 0; iVar15 = iVar15 + -1) {
      *(undefined1 *)pfVar26 = *(undefined1 *)pfVar21;
      pfVar21 = (float *)((int)pfVar21 + 1);
      pfVar26 = (float *)((int)pfVar26 + 1);
    }
    ppfVar24 = local_1c4;
    puVar27 = &local_1e8;
    for (uVar19 = uVar23 >> 2; uVar19 != 0; uVar19 = uVar19 - 1) {
      *puVar27 = *ppfVar24;
      ppfVar24 = ppfVar24 + 1;
      puVar27 = puVar27 + 1;
    }
    for (uVar19 = uVar23 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {
      *(undefined1 *)puVar27 = *(undefined1 *)ppfVar24;
      ppfVar24 = (float **)((int)ppfVar24 + 1);
      puVar27 = (undefined4 *)((int)puVar27 + 1);
    }
    local_21c = local_21c + 8;
    local_210 = (undefined1 *)uVar23;
  } while (local_21c < 0x20);
  iVar15 = 0;
  iVar16 = 1;
  local_228 = 0;
  if (1 < (int)uVar23) {
    iVar25 = 0;
    iVar20 = 8;
    do {
      if ((*(float *)((int)local_1b0 + iVar20 + 4) < *(float *)((int)local_1b0 + iVar25 + 4)) ||
         ((fVar2 = ABS(*(float *)((int)local_1b0 + iVar20 + 4) -
                       *(float *)((int)local_1b0 + iVar25 + 4)), fVar2 < 0.001 != (fVar2 == 0.001)
          && (*(float *)((int)local_1b0 + iVar20) < *(float *)((int)local_1b0 + iVar25))))) {
        iVar25 = iVar20;
        iVar15 = iVar16;
      }
      iVar16 = iVar16 + 1;
      iVar20 = iVar20 + 8;
      local_228 = iVar15;
    } while (iVar16 < (int)uVar23);
  }
  local_218 = 1;
  if (1 < (int)(uVar23 - 1)) {
    local_1c4[3] = local_90 + local_228 * 4 + 1;
    local_1c4[2] = local_90 + local_228 * 4;
    uVar14 = *(undefined1 *)((int)local_1c4 + local_228);
    local_1b4 = (int)&local_130 + (1 - param_2);
    local_1e8 = (int)&local_130 + (2 - param_2);
    do {
      FUN_0040be70();
      local_12c[3] = local_1b0[local_228 * 2];
      local_12c[4] = local_1b0[local_228 * 2 + 1];
      local_118[0] = (float)param_4;
      local_e0 = *local_1c4[2];
      local_dc = *local_1c4[3];
      local_d8 = local_90[local_228 * 4 + 2];
      local_af = *(undefined1 *)(param_2 + 0x81);
      local_210 = local_ac;
      local_b0 = *(undefined1 *)(param_2 + 0x80);
      local_ae = *(undefined1 *)(param_2 + 0x82);
      pfVar21 = local_10c;
      local_ad = uVar14;
      local_9b = 1;
      pfVar26 = local_d0;
      local_21c = 3;
      puVar17 = (undefined1 *)(param_2 + 0x85);
      do {
        iVar15 = local_218;
        if ((int)uVar23 <= local_218) {
          iVar15 = uVar23 - 1;
        }
        iVar16 = iVar15 + local_228;
        if ((int)uVar23 <= iVar16) {
          iVar16 = iVar16 - uVar23;
        }
        pfVar21[-1] = local_1b0[iVar16 * 2];
        *pfVar21 = local_1b0[iVar16 * 2 + 1];
        pfVar21[1] = (float)param_4;
        pfVar26[-1] = local_90[iVar16 * 4];
        fVar2 = local_90[iVar16 * 4 + 2];
        *pfVar26 = local_90[iVar16 * 4 + 1];
        uVar11 = puVar17[-1];
        pfVar26[1] = fVar2;
        *local_210 = uVar11;
        puVar17[(int)&local_130 - param_2] = *puVar17;
        puVar17[local_1b4] = puVar17[1];
        puVar17[local_1e8] = *(undefined1 *)((int)local_1c4 + iVar16);
        local_210 = local_210 + 4;
        local_218 = local_218 + 1;
        pfVar21 = pfVar21 + 4;
        pfVar26 = pfVar26 + 3;
        puVar17 = puVar17 + 4;
        local_21c = local_21c + -1;
      } while (local_21c != 0);
      FUN_0040bef0();
      local_218 = iVar15;
    } while (iVar15 < (int)(uVar23 - 1));
  }
  return;
}


// ==== 0x590ad0 TrackMap::WorldToMap

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void TrackMap__WorldToMap(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 *in_EAX;
  float *unaff_ESI;
  int unaff_EDI;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_20;
  float local_1c;
  undefined4 local_18;
  
  puVar5 = &local_20;
  local_20 = *in_EAX;
  local_1c = -(float)in_EAX[1];
  puVar4 = &local_20;
  local_18 = 0x3f800000;
  D3DXVec3Transform(puVar4,&local_20,unaff_EDI + 0x20);
  iVar3 = *(int *)(unaff_EDI + 0xa4);
  fVar1 = *(float *)(iVar3 + 0x90);
  fVar2 = *(float *)(iVar3 + 0x94);
  *unaff_ESI = ((float)puVar4 - *(float *)(iVar3 + 0x8c)) / *(float *)(iVar3 + 0x94);
  unaff_ESI[1] = ((float)puVar5 + fVar1) / fVar2;
  return;
}


// ==== 0x590b50 FUN_00590b50

/* WARNING: Type propagation algorithm not settling */

void FUN_00590b50(undefined4 param_1,undefined4 *param_2,undefined4 param_3,float param_4,
                 float param_5,int param_6)

{
  int *unaff_EDI;
  float *pfStack_14c;
  undefined4 *puStack_148;
  int *piStack_144;
  int *piStack_140;
  undefined1 *puStack_13c;
  undefined4 *puStack_138;
  undefined1 *puStack_134;
  undefined4 *puStack_130;
  undefined4 *puStack_12c;
  undefined4 *puStack_128;
  undefined1 *puStack_124;
  int iStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined1 auStack_10c [4];
  float fStack_108;
  float afStack_104 [3];
  float fStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined1 auStack_e8 [12];
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined1 auStack_9c [12];
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
  undefined4 local_58;
  undefined4 local_54;
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
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0x3f800000;
  puStack_124 = (undefined1 *)0x590c1c;
  FUN_0040b930();
  puStack_124 = local_50;
  puStack_128 = &local_90;
  puStack_12c = &local_90;
  puStack_130 = (undefined4 *)0x590c39;
  D3DXMatrixMultiply();
  uStack_ac = *param_2;
  uStack_a8 = param_2[1];
  puStack_130 = &uStack_dc;
  puStack_134 = auStack_9c;
  puStack_138 = &uStack_dc;
  uStack_dc = 0x3f800000;
  uStack_d8 = 0;
  uStack_d4 = 0;
  uStack_d0 = 0;
  uStack_cc = 0;
  uStack_c8 = 0x3f800000;
  uStack_c4 = 0;
  uStack_c0 = 0;
  uStack_bc = 0;
  uStack_b8 = 0;
  uStack_b4 = 0x3f800000;
  uStack_b0 = 0;
  uStack_a4 = 0;
  uStack_a0 = 0x3f800000;
  puStack_13c = (undefined1 *)0x590ce4;
  D3DXMatrixMultiply();
  fStack_108 = -param_5;
  uStack_114 = param_3;
  puStack_13c = auStack_e8;
  puStack_124 = (undefined1 *)-param_4;
  uStack_f4 = param_3;
  piStack_140 = &iStack_118;
  iStack_118 = param_6;
  puStack_128 = (undefined4 *)param_6;
  piStack_144 = &iStack_118;
  uStack_110 = 0;
  uStack_f0 = 0;
  afStack_104[1] = 0.0;
  puStack_148 = (undefined4 *)0x590d4a;
  afStack_104[0] = (float)puStack_124;
  fStack_f8 = fStack_108;
  D3DXVec3Transform();
  puStack_148 = &uStack_f4;
  pfStack_14c = afStack_104;
  D3DXVec3Transform(afStack_104);
  D3DXVec3Transform(&stack0xfffffee0);
  D3DXVec3Transform(&pfStack_14c,&pfStack_14c,auStack_10c);
  *unaff_EDI = (int)puStack_148;
  unaff_EDI[1] = (int)piStack_144;
  unaff_EDI[2] = (int)puStack_128;
  unaff_EDI[3] = (int)puStack_124;
  unaff_EDI[4] = (int)puStack_138;
  unaff_EDI[5] = (int)puStack_134;
  unaff_EDI[6] = (int)&stack0xfffffee0;
  unaff_EDI[7] = (int)(afStack_104 + 1);
  return;
}


// ==== 0x590dd0 FUN_00590dd0

void FUN_00590dd0(int param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  undefined1 uVar2;
  float *in_EAX;
  int unaff_ESI;
  float *pfVar3;
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
  undefined4 local_58;
  undefined4 local_54;
  
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
  local_58 = 0;
  local_54 = 0x3f800000;
  FUN_0040b990(&local_90,&local_90);
  bMatrixCopy_b();
  D3DXVec3Transform();
  D3DXVec3Transform(param_2,param_2,&local_5c);
  pfVar3 = param_3;
  D3DXVec3Transform(param_3,param_3,&local_68);
  D3DXVec3Transform(param_4,param_4);
  fVar1 = *(float *)(&DAT_00737854 + *(int *)(param_1 + 0xc4) * 0x3c);
  *(float *)(unaff_ESI + 0x10) = (fVar1 * *in_EAX) / (fVar1 + in_EAX[2]) + (float)&local_74;
  *(float *)(unaff_ESI + 0x14) = (fVar1 * in_EAX[1]) / (fVar1 + in_EAX[2]) + (float)pfVar3;
  *(float *)(unaff_ESI + 0x20) = (fVar1 * *param_2) / (fVar1 + param_2[2]) + (float)&local_74;
  *(float *)(unaff_ESI + 0x24) = (fVar1 * param_2[1]) / (fVar1 + param_2[2]) + (float)pfVar3;
  *(float *)(unaff_ESI + 0x30) = (fVar1 * *param_3) / (fVar1 + param_3[2]) + (float)&local_74;
  *(float *)(unaff_ESI + 0x34) = (fVar1 * param_3[1]) / (fVar1 + param_3[2]) + (float)pfVar3;
  *(float *)(unaff_ESI + 0x40) = (fVar1 * *param_4) / (fVar1 + param_4[2]) + (float)&local_74;
  *(float *)(unaff_ESI + 0x44) = (fVar1 * param_4[1]) / (fVar1 + param_4[2]) + (float)pfVar3;
  if (in_EAX[2] <= 0.0) {
    uVar2 = 0x80;
  }
  else {
    uVar2 = _ftol_nocw();
  }
  *(undefined1 *)(unaff_ESI + 0x83) = uVar2;
  if (param_2[2] <= 0.0) {
    uVar2 = 0x80;
  }
  else {
    uVar2 = _ftol_nocw();
  }
  *(undefined1 *)(unaff_ESI + 0x87) = uVar2;
  if (param_3[2] <= 0.0) {
    uVar2 = 0x80;
  }
  else {
    uVar2 = _ftol_nocw();
  }
  *(undefined1 *)(unaff_ESI + 0x8b) = uVar2;
  if (0.0 < param_4[2]) {
    uVar2 = _ftol_nocw();
    *(undefined1 *)(unaff_ESI + 0x8f) = uVar2;
    return;
  }
  *(undefined1 *)(unaff_ESI + 0x8f) = 0x80;
  return;
}


