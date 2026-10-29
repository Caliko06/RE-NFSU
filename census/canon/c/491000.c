// ==== 0x4922a0 FUN_004922a0

void * __thiscall FUN_004922a0(void *param_1,byte param_2)

{
  FUN_004922c0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4922c0 FUN_004922c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004922c0(undefined4 *param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  int extraout_EDX;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685b5d;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c7b50;
  local_4 = 4;
  if (param_1[8] != 0) {
    _gSpecialCameraActive = 0;
  }
  _free((void *)param_1[0xb]);
  _free((void *)param_1[0xd]);
  _free((void *)param_1[0xf]);
  _free((void *)param_1[0xc]);
  _free((void *)param_1[0xe]);
  _free((void *)param_1[0x10]);
  _free((void *)param_1[0x11]);
  iVar3 = param_1[0x104];
  if (0 < iVar3) {
    piVar2 = param_1 + 100;
    do {
      *(char *)(*piVar2 + 8) = *(char *)(*piVar2 + 8) + -1;
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  PreviewComet__DisableEmitters();
  pvVar1 = *(void **)(extraout_EDX + 0xc);
  if (pvVar1 != (void *)0x0) {
    eh_vector_destructor_iterator(pvVar1,0xc0,*(int *)((int)pvVar1 + -0x10),FUN_00401db0);
    _free((void *)((int)pvVar1 + -0x10));
  }
  if ((void *)param_1[0x43] != (void *)0x0) {
    _free((void *)param_1[0x43]);
  }
  if ((void *)param_1[0x4a] != (void *)0x0) {
    _free((void *)param_1[0x4a]);
  }
  if ((void *)param_1[0x37] != (void *)0x0) {
    _free((void *)param_1[0x37]);
  }
  if ((void *)param_1[0x3e] != (void *)0x0) {
    _free((void *)param_1[0x3e]);
  }
  if ((void *)param_1[0x2b] != (void *)0x0) {
    _free((void *)param_1[0x2b]);
  }
  if ((void *)param_1[0x32] != (void *)0x0) {
    _free((void *)param_1[0x32]);
  }
  if ((void *)param_1[0x1f] != (void *)0x0) {
    _free((void *)param_1[0x1f]);
  }
  if ((void *)param_1[0x26] != (void *)0x0) {
    _free((void *)param_1[0x26]);
  }
  *param_1 = &PTR_CameraMover__TrivialDtor_006c7c50;
  if (param_1[5] != 0) {
    param_1[5] = 0;
    param_1[9] = *(undefined4 *)(param_1[7] + 0x280);
    param_1[10] = *(undefined4 *)(param_1[7] + 0x284);
    iVar3 = param_1[1];
    piVar2 = (int *)param_1[2];
    *piVar2 = iVar3;
    *(int **)(iVar3 + 4) = piVar2;
    ViewList_UpdateViewCountKind();
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x492470 FUN_00492470

int * FUN_00492470(void)

{
  void *pvVar1;
  int *_Memory;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684ceb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x18);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    _Memory = (int *)0x0;
  }
  else {
    _Memory = (int *)FUN_00492e70(pvVar1,0x42200000,0x43a00000);
  }
  local_4 = 0xffffffff;
  if (*_Memory != 0) {
    if (3 < _Memory[1]) {
      ExceptionList = local_c;
      return _Memory;
    }
    if (*_Memory != 0) {
      FUN_00565ce0();
    }
  }
  _free(_Memory);
  ExceptionList = local_c;
  return (int *)0x0;
}


// ==== 0x492520 FUN_00492520

void __thiscall FUN_00492520(int param_1,undefined4 param_2)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x50) + 0.25;
  if (*(float *)(param_1 + 0x48) <= fVar1) {
    FUN_00490770(param_1 + 0x13c,param_2,*(float *)(param_1 + 0x48) / fVar1,0);
    return;
  }
  return;
}


// ==== 0x492560 FUN_00492560

float10 __fastcall FUN_00492560(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float10 fVar4;
  
  iVar1 = *(int *)(param_1 + 0x74);
  fVar4 = (float10)0.0;
  if (iVar1 == 0) {
LAB_00492584:
    fVar2 = (float)(*(int *)(param_1 + 0x70) + -1);
  }
  else if (iVar1 == 1) {
    fVar2 = (float)*(int *)(param_1 + 0x70);
  }
  else {
    if (iVar1 == 2) goto LAB_00492584;
    fVar2 = 0.0;
  }
  iVar1 = *(int *)(param_1 + 0x74);
  fVar2 = (*(float *)(param_1 + 0x134) * 0.0 + *(float *)(param_1 + 0x138)) * fVar2;
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      fVar3 = (float)*(int *)(param_1 + 0x70);
      goto LAB_004925d1;
    }
    if (iVar1 != 2) {
      fVar3 = 0.0;
      goto LAB_004925d1;
    }
  }
  fVar3 = (float)(*(int *)(param_1 + 0x70) + -1);
LAB_004925d1:
  fVar3 = (*(float *)(param_1 + 0x138) + *(float *)(param_1 + 0x134)) * fVar3;
  if ((fVar2 < *(float *)(param_1 + 0x5c)) && (*(float *)(param_1 + 0x5c) < fVar3)) {
    fVar4 = (float10)0.8;
  }
  if ((fVar2 < *(float *)(param_1 + 0x60)) && (*(float *)(param_1 + 0x60) < fVar3)) {
    fVar4 = fVar4 + (float10)0.8;
  }
  if ((fVar2 < *(float *)(param_1 + 100)) && (*(float *)(param_1 + 100) < fVar3)) {
    fVar4 = fVar4 + (float10)0.8;
  }
  if ((fVar2 < *(float *)(param_1 + 0x68)) && (*(float *)(param_1 + 0x68) < fVar3)) {
    fVar4 = fVar4 + (float10)0.8;
  }
  return (float10)*(float *)(param_1 + 0x54) + (float10)*(float *)(param_1 + 0x50) + (float10)0.6 +
         (float10)0.4 + (float10)0.25 + fVar4;
}


// ==== 0x492690 FUN_00492690

void __fastcall FUN_00492690(int param_1)

{
  CameraMover__Enable();
  PreviewComet__EnableEmitters(param_1 + 0x13c);
  return;
}


// ==== 0x4926b0 FUN_004926b0

void __fastcall FUN_004926b0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  PreviewComet__DisableEmitters();
  if (*(int *)(param_1 + 0x14) != 0) {
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x280);
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x284);
    iVar1 = *(int *)(param_1 + 4);
    piVar2 = *(int **)(param_1 + 8);
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    ViewList_UpdateViewCountKind();
    return;
  }
  return;
}


// ==== 0x492700 FUN_00492700

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00492700(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  char cVar6;
  undefined2 uVar7;
  int iVar8;
  float *pfVar9;
  float fVar10;
  float10 fVar11;
  float10 fVar12;
  float local_a0;
  float local_9c;
  float local_98;
  float local_80;
  float local_7c;
  float local_78;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 local_50 [76];
  
  cVar6 = FUN_0043a2e0();
  if (((cVar6 != '\0') || (DAT_007361f0 == (int *)0x0)) ||
     ((*DAT_007361f0 != 7 && (*DAT_007361f0 != 0xb)))) {
    fVar4 = *(float *)(param_1 + 0x48);
    local_60 = 0;
    local_5c = 0;
    local_58 = 0x3f800000;
    if (*(float *)(param_1 + 0x58) <= 0.0) {
      *(float *)(param_1 + 0x48) = DAT_0073ad38 + *(float *)(param_1 + 0x48);
    }
    else {
      *(float *)(param_1 + 0x58) = *(float *)(param_1 + 0x58) - DAT_0073ad38;
    }
    fVar10 = DAT_0073ad38;
    if (0.25 <= *(float *)(param_1 + 0x48)) {
      fVar1 = *(float *)(param_1 + 0x50) + 0.25;
      if (fVar1 <= *(float *)(param_1 + 0x48)) {
        fVar2 = *(float *)(param_1 + 0x50) + 0.4 + 0.25;
        if (fVar2 <= *(float *)(param_1 + 0x48)) {
          if (*(float *)(param_1 + 0x50) + *(float *)(param_1 + 0x54) + 0.4 + 0.25 <=
              *(float *)(param_1 + 0x48)) {
            FUN_00593fc0(DAT_0073ad38);
            FUN_00593fc0(fVar10);
            pfVar9 = *(float **)(param_1 + 0x3c);
            local_80 = *pfVar9;
            local_7c = pfVar9[0xc];
            local_78 = pfVar9[0x18];
            pfVar9 = *(float **)(param_1 + 0x40);
            local_a0 = *pfVar9;
            local_9c = pfVar9[0xc];
            local_98 = pfVar9[0x18];
            EnsureTopology(param_1 + 0x170,param_1 + 0x430,&local_80,param_1 + 0x440);
          }
          else {
            if (fVar4 < fVar2) {
              _gSpecialCameraActive = 0;
            }
            fVar4 = _K_ONE - (((*(float *)(param_1 + 0x48) - 0.25) - *(float *)(param_1 + 0x50)) -
                             0.4) / *(float *)(param_1 + 0x54);
            fVar11 = (float10)ZoneCamera_GetLetterboxSpan();
            FUN_005829e0((float)(((float10)fVar4 * (float10)*(float *)(param_1 + 300) +
                                 (float10)*(float *)(param_1 + 0x130)) * fVar11));
            fVar11 = (float10)ZoneCamera_GetLetterboxSpan();
            FUN_005829e0((float)(((float10)fVar4 * (float10)*(float *)(param_1 + 0x134) +
                                 (float10)*(float *)(param_1 + 0x138)) * fVar11));
            fVar10 = DAT_0073ad38;
          }
        }
        else {
          if (fVar4 < fVar1) {
            *(undefined4 *)(*(int *)(param_1 + 0x44) + 0x24) = 0x3ecccccd;
            FUN_0042acf0(0x3f800000);
          }
          fVar10 = DAT_0073ad38;
          FUN_00593fc0(DAT_0073ad38);
          FUN_00593fc0(fVar10);
          pfVar9 = *(float **)(param_1 + 0x34);
          local_80 = *pfVar9;
          local_7c = pfVar9[0xc];
          local_78 = pfVar9[0x18];
          pfVar9 = *(float **)(param_1 + 0x38);
          local_a0 = *pfVar9;
          local_9c = pfVar9[0xc];
          local_98 = pfVar9[0x18];
        }
      }
      else {
        fVar5 = _K_ONE / *(float *)(param_1 + 0x50);
        fVar10 = (*(float *)(param_1 + 0x48) - 0.25) * fVar5;
        fVar11 = (float10)ZoneCamera_GetLetterboxSpan();
        fVar1 = (float)(((float10)fVar10 * (float10)*(float *)(param_1 + 0x134) +
                        (float10)*(float *)(param_1 + 0x138)) * fVar11);
        fVar11 = (float10)ZoneCamera_GetLetterboxSpan();
        fVar2 = *(float *)(param_1 + 0x134);
        fVar3 = *(float *)(param_1 + 0x138);
        fVar12 = (float10)ZoneCamera_GetLetterboxSpan();
        FUN_005829e0((float)(((float10)fVar10 * (float10)*(float *)(param_1 + 300) +
                             (float10)*(float *)(param_1 + 0x130)) * fVar12));
        FUN_005829e0(fVar1);
        fVar10 = DAT_0073ad38;
        iVar8 = 0;
        pfVar9 = (float *)(param_1 + 0x5c);
        do {
          if (((float)((((float10)fVar4 - (float10)0.25) * (float10)fVar5 * (float10)fVar2 +
                       (float10)fVar3) * fVar11) < *pfVar9) && (*pfVar9 <= fVar1)) {
            *(undefined4 *)(param_1 + 0x58) = 0x3f4ccccd;
            _gSpecialCameraActive = 0;
            goto LAB_00492b2d;
          }
          iVar8 = iVar8 + 1;
          pfVar9 = pfVar9 + 1;
        } while (iVar8 < 4);
        _gSpecialCameraActive = 1;
      }
    }
    else {
      FUN_00593ec0(DAT_0073ad38,0,0);
      FUN_00593ec0(fVar10,0,0);
      FUN_00593ec0(fVar10,0,0);
      FUN_00593ec0(fVar10,0,0);
      FUN_00593ec0(fVar10,0,0);
      FUN_00593ec0(fVar10,0,0);
      pfVar9 = *(float **)(param_1 + 0x2c);
      local_80 = *pfVar9;
      local_7c = pfVar9[0xc];
      local_78 = pfVar9[0x18];
      pfVar9 = *(float **)(param_1 + 0x30);
      local_a0 = *pfVar9;
      local_9c = pfVar9[0xc];
      local_98 = pfVar9[0x18];
      EnsureTopology(param_1 + 0x170,param_1 + 0x430,&local_80,param_1 + 0x440);
    }
LAB_00492b2d:
    FUN_00593ec0(fVar10,0,0);
    fVar4 = **(float **)(param_1 + 0x44);
    local_70 = (local_80 - local_a0) * fVar4;
    local_6c = (local_7c - local_9c) * fVar4;
    local_80 = local_70 + local_a0;
    local_7c = local_6c + local_9c;
    local_78 = (local_78 - local_98) * fVar4 + local_98;
    local_68 = local_78;
    uVar7 = Atan2ToAngle16(**(float **)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x4c));
    if (DAT_00735f5c == 0) {
      *(undefined2 *)(*(int *)(param_1 + 0x1c) + 0xc4) = uVar7;
    }
    Matrix4_BuildLookAt(&local_60);
    Camera__SetCameraMatrix(*(undefined4 *)(param_1 + 0x1c),local_50,DAT_0073ad38);
  }
  return;
}


// ==== 0x492c00 FUN_00492c00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall FUN_00492c00(int param_1)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  float10 fVar11;
  float local_32c;
  float local_320;
  float local_31c;
  float local_318;
  float local_308;
  int local_304;
  float afStack_300 [8];
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
  iVar9 = *(int *)(param_1 + 0x74);
  if (iVar9 == 0) {
LAB_00492c47:
    iVar9 = *(int *)(param_1 + 0x70) + -1;
  }
  else {
    if (iVar9 != 1) {
      if (iVar9 != 2) {
        local_32c = 0.0;
        goto LAB_00492c57;
      }
      goto LAB_00492c47;
    }
    iVar9 = *(int *)(param_1 + 0x70);
  }
  local_32c = (float)iVar9;
LAB_00492c57:
  ExceptionList = &local_1c;
  local_304 = param_1 + 0x6c;
  fVar11 = (float10)FUN_00582bf0();
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_308 = (float)((float10)10.0 * ((float10)local_32c / fVar11));
  FUN_00440740();
  fVar3 = 0.0;
  local_14 = 0;
  local_32c = 0.0;
  iVar9 = param_1 + 0x6c;
  do {
    iVar2 = *(int *)(iVar9 + 8);
    if (iVar2 == 0) {
LAB_00492cd9:
      fVar4 = (float)(*(int *)(iVar9 + 4) + -1);
    }
    else if (iVar2 == 1) {
      fVar4 = (float)*(int *)(iVar9 + 4);
    }
    else {
      if (iVar2 == 2) goto LAB_00492cd9;
      fVar4 = 0.0;
    }
    if (fVar3 < fVar4 == (fVar3 == fVar4)) {
      uVar8 = 0;
      if (0 < local_40) {
        do {
          piVar1 = aiStack_2c0 + uVar8;
          uVar8 = uVar8 + 1;
          *(char *)(*piVar1 + 8) = *(char *)(*piVar1 + 8) + -1;
        } while ((int)uVar8 < local_40);
      }
      ExceptionList = local_1c;
      return uVar8 & 0xffffff00;
    }
    uVar8 = (uint)local_32c & 1;
    uVar10 = uVar8 ^ 1;
    FUN_005829e0(fVar3);
    if (0 < (int)local_32c) {
      fVar4 = (afStack_300[uVar8 * 4] - afStack_300[uVar10 * 4]) * _K_HALF;
      fVar5 = (afStack_300[uVar8 * 4 + 1] - afStack_300[uVar10 * 4 + 1]) * _K_HALF;
      fVar6 = (afStack_300[uVar8 * 4 + 2] - afStack_300[uVar10 * 4 + 2]) * _K_HALF;
      local_320 = fVar4 + afStack_300[uVar10 * 4];
      local_31c = afStack_300[uVar10 * 4 + 1] + fVar5;
      local_318 = afStack_300[uVar10 * 4 + 2] + fVar6;
      GroundQuery__RefillCache
                (&local_320,SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar6 * fVar6) + _K_HALF,0);
      cVar7 = FUN_00441030(local_2e0,1,1,afStack_300 + uVar8 * 4,0x3f000000,0x3f800000);
      if (cVar7 != '\0') {
        iVar9 = 0;
        if (0 < local_40) {
          do {
            piVar1 = aiStack_2c0 + iVar9;
            iVar9 = iVar9 + 1;
            *(char *)(*piVar1 + 8) = *(char *)(*piVar1 + 8) + -1;
          } while (iVar9 < local_40);
        }
        ExceptionList = local_1c;
        return CONCAT31((int3)((uint)iVar9 >> 8),1);
      }
    }
    fVar3 = fVar3 + local_308;
    local_32c = (float)((int)local_32c + 1);
    iVar9 = local_304;
  } while( true );
}


// ==== 0x492e70 FUN_00492e70

int * FUN_00492e70(int *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  float *pfVar2;
  int *piVar3;
  char cVar4;
  int in_EAX;
  int iVar5;
  int iVar6;
  float fVar7;
  undefined4 unaff_EBX;
  float10 fVar8;
  float10 fVar9;
  float unaff_retaddr;
  
  piVar3 = param_1;
  *param_1 = 0;
  param_1[4] = param_3;
  iVar5 = _ftol_nocw();
  param_1[1] = iVar5;
  iVar5 = FUN_00565b60(iVar5 * 0x18,0,0,0);
  *param_1 = iVar5;
  if (in_EAX == -0x800) {
    param_1[2] = 0x3f800000;
    param_1[3] = 0;
  }
  else {
    iVar5 = *(int *)(in_EAX + 0x818);
    param_1[3] = *(int *)(in_EAX + 0x81c);
    param_1[2] = iVar5;
  }
  iVar5 = *(int *)(in_EAX + 0x10);
  if (*(char *)(iVar5 + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  fVar7 = (float)(int)*(char *)(iVar5 + 0x424);
  iVar5 = (**(code **)(**(int **)(in_EAX + 0x2c) + 0x14))(1);
  iVar6 = (**(code **)(**(int **)(in_EAX + 0x2c) + 0x18))(1);
  if ((iVar5 == 0) || (iVar6 == 0)) {
    cVar4 = FUN_004932e0(param_1,in_EAX + 0x60,unaff_retaddr,unaff_EBX,0,0);
    if (cVar4 != '\0') goto LAB_00492f7a;
  }
  else {
    fVar8 = (float10)FUN_00493190(param_1,*param_1,iVar5,in_EAX + 0x60,unaff_EBX);
    if (fVar8 < (float10)unaff_retaddr != (fVar8 == (float10)unaff_retaddr)) {
LAB_00492f7a:
      pfVar2 = *(float **)(*param_1 + 4);
      iVar5 = 1;
      piVar1 = param_1 + 1;
      param_1[5] = (int)((*(float *)(in_EAX + 0x60) - *pfVar2) * pfVar2[4] -
                        (*(float *)(in_EAX + 100) - pfVar2[1]) * pfVar2[3]);
      param_1 = (int *)fVar7;
      if (1 < *piVar1) {
        iVar6 = 0x18;
        do {
          fVar9 = (float10)FUN_00492ff0(piVar3,iVar5,unaff_retaddr,unaff_EBX);
          fVar8 = (float10)(float)param_1;
          param_1 = (int *)(float)(fVar9 + fVar8);
          if (((float10)(float)piVar3[4] < fVar9 + fVar8) || (*(int *)(iVar6 + 4 + *piVar3) == 0))
          break;
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + 0x18;
        } while (iVar5 < piVar3[1]);
      }
      piVar3[1] = iVar5;
      piVar3[4] = (int)param_1;
      return piVar3;
    }
  }
  FUN_00565ce0();
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}


// ==== 0x492ff0 FUN_00492ff0

float10 FUN_00492ff0(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float fVar6;
  int iVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  iVar1 = *param_1;
  iVar10 = (param_2 * 3 + -3) * 8;
  pfVar2 = *(float **)(iVar1 + 4 + iVar10);
  iVar3 = *(int *)(iVar1 + iVar10);
  iVar4 = *(int *)(iVar1 + 0x10 + iVar10);
  FUN_004422b0(0,*(undefined4 *)(iVar1 + 0xc + iVar10));
  iVar7 = ((int)pfVar2 + (-0x27c - iVar3)) / 0x88;
  if (iVar7 + 1 < (int)*(short *)(iVar3 + 0x10)) {
    iVar9 = param_2 * 0x18;
    *(int *)(iVar9 + iVar1) = iVar3;
    *(int *)(iVar9 + 4 + *param_1) = iVar7 * 0x88 + 0x304 + iVar3;
    *(int *)(iVar9 + 0x10 + *param_1) = iVar4;
    if (iVar4 == -1) {
      fVar6 = 0.0;
    }
    else {
      fVar6 = (float)((int)*(short *)(*(int *)(iVar9 + 4 + *param_1) + 0x3c + iVar4 * 2) << 8) *
              1.5258789e-05;
    }
    *(float *)(iVar9 + 0xc + *param_1) = fVar6;
    *(undefined4 *)(iVar9 + 0x14 + *param_1) = 0;
  }
  else {
    cVar8 = FUN_004932e0(param_1,&local_30,param_3,param_4,param_2,pfVar2);
    if (cVar8 == '\0') {
      return (float10)0.0;
    }
    iVar1 = param_2 * 0x18 + *param_1;
    pfVar5 = *(float **)(iVar1 + 4);
    *(float *)(iVar1 + 0x14) = (*pfVar2 - *pfVar5) * pfVar5[4] - (pfVar2[1] - pfVar5[1]) * pfVar5[3]
    ;
  }
  iVar1 = *param_1;
  FUN_004422b0(0,*(undefined4 *)(param_2 * 0x18 + 0xc + iVar1));
  *(float *)(iVar1 + 8 + iVar10) =
       SQRT((local_1c - local_2c) * (local_1c - local_2c) +
            (local_18 - local_28) * (local_18 - local_28) +
            (local_20 - local_30) * (local_20 - local_30));
  return (float10)*(float *)(iVar10 + 8 + *param_1);
}


// ==== 0x493190 FUN_00493190

float10 FUN_00493190(int param_1,int *param_2,int param_3,float *param_4,int param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float *unaff_ESI;
  int iVar9;
  float local_14;
  float local_10;
  
  bVar4 = false;
  local_14 = 1e+06;
  local_10 = 0.0;
  iVar9 = 0;
  iVar8 = -1;
  do {
    if (iVar9 == 1) {
      iVar7 = iVar8;
      if ((bVar4) ||
         (pfVar5 = (float *)FUN_00424f40(),
         *pfVar5 * *(float *)(param_1 + 8) + pfVar5[1] * *(float *)(param_1 + 0xc) < 0.0)) break;
      fVar1 = 0.0;
      iVar7 = -1;
LAB_0049322f:
      fVar2 = *param_4 - (unaff_ESI[3] * 0.0 + unaff_ESI[4] * fVar1 + *unaff_ESI);
      fVar3 = param_4[1] - (unaff_ESI[4] * 0.0 + -unaff_ESI[3] * fVar1 + unaff_ESI[1]);
      fVar2 = SQRT(fVar3 * fVar3 + fVar2 * fVar2);
      if ((fVar2 < local_14) && (iVar8 = iVar7, local_14 = fVar2, local_10 = fVar1, bVar4)) break;
    }
    else {
      iVar7 = iVar9 + param_5;
      iVar6 = param_3 + iVar7 * 0x34;
      if ((*(char *)(iVar6 + 0x34) != '\0') || (*(char *)(iVar6 + 0x35) != '\0')) {
        bVar4 = true;
        fVar1 = (float)((int)*(short *)((int)unaff_ESI + iVar7 * 2 + 0x3c) << 8) * 1.5258789e-05;
        goto LAB_0049322f;
      }
    }
    iVar7 = iVar8;
    iVar9 = iVar9 + 1;
    iVar8 = iVar7;
  } while (iVar9 < 2);
  param_2[4] = iVar7;
  *param_2 = param_3;
  param_2[1] = (int)unaff_ESI;
  param_2[3] = (int)local_10;
  return (float10)local_14;
}


// ==== 0x4932e0 FUN_004932e0

uint FUN_004932e0(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
                 ,int param_6)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  float10 fVar10;
  float local_38;
  int local_30 [12];
  
  puVar3 = DAT_0077af20;
  iVar7 = 0;
  local_30[10] = 0xffffffff;
  local_30[4] = 0xffffffff;
  local_38 = 1e+06;
  local_30[6] = 0;
  local_30[7] = 0;
  local_30[8] = 0;
  local_30[9] = 0;
  local_30[0xb] = 0;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[5] = 0;
  puVar4 = (undefined4 *)NullUpdate_ret();
  for (; puVar3 != puVar4; puVar3 = (undefined4 *)*puVar3) {
    iVar7 = FUN_00442690(puVar3,param_3,1,0);
    if (((iVar7 != 0) && (param_6 != iVar7)) &&
       (fVar10 = (float10)FUN_00493190(param_1,local_30 + 6,puVar3,param_2,param_4),
       fVar10 < (float10)local_38)) {
      local_38 = (float)fVar10;
      piVar8 = local_30 + 6;
      piVar9 = local_30;
      for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar9 = *piVar8;
        piVar8 = piVar8 + 1;
        piVar9 = piVar9 + 1;
      }
    }
  }
  uVar5 = *param_1;
  piVar8 = local_30;
  piVar9 = (int *)(uVar5 + param_5 * 0x18);
  for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar9 = *piVar8;
    piVar8 = piVar8 + 1;
    piVar9 = piVar9 + 1;
  }
  if ((iVar7 != 0) && (local_30[1] != 0)) {
    uVar5 = 0;
    if (DAT_0078a318 == 0) {
LAB_0049340c:
      return CONCAT31((int3)(uVar5 >> 8),1);
    }
    uVar5 = 0;
    if (param_6 != 0) {
      fVar1 = *(float *)(param_6 + 0x38);
      if (DAT_007372b4 == 0) {
        fVar2 = *(float *)(local_30[1] + 0x38);
      }
      else {
        fVar1 = DAT_007372b0 - fVar1;
        fVar2 = DAT_007372b0 - *(float *)(local_30[1] + 0x38);
      }
      uVar5 = CONCAT22((short)((uint)param_6 >> 0x10),
                       (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                       (ushort)(fVar2 == fVar1) << 0xe);
      if (fVar2 >= fVar1) goto LAB_0049340c;
    }
  }
  return uVar5 & 0xffffff00;
}


// ==== 0x493420 FUN_00493420

void FUN_00493420(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  float fVar3;
  int iVar4;
  int in_EAX;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_44;
  float local_40;
  int local_38;
  float local_28;
  float local_18;
  
  if (in_EAX < *(int *)(param_2 + 4) / 2) {
    iVar7 = in_EAX + 2;
    local_44 = 0;
  }
  else {
    local_44 = in_EAX + -2;
    iVar7 = *(int *)(param_2 + 4) + -1;
  }
  local_40 = 1000.0;
  for (iVar5 = local_44; iVar5 <= iVar7; iVar5 = iVar5 + 1) {
    FUN_005829e0((float)iVar5);
    FUN_005829e0((float)iVar5);
    if (local_28 - local_18 < local_40) {
      local_40 = local_28 - local_18;
    }
  }
  if (3 < (iVar7 - local_44) + 1) {
    iVar6 = local_44 << 4;
    iVar5 = local_44 + 2;
    local_38 = local_44;
    do {
      if ((1 < iVar5) && (local_38 < *(int *)(param_2 + 4))) {
        iVar4 = *(int *)(param_2 + 0xc);
        uVar2 = *(undefined4 *)(iVar4 + iVar6);
        puVar1 = (undefined4 *)(iVar4 + iVar6);
        fVar3 = *(float *)(*(int *)(param_1 + 0xc) + 8 + iVar6);
        if (local_40 < (float)puVar1[2] - fVar3) {
          puVar1[1] = *(undefined4 *)(iVar4 + 4 + iVar6);
          *puVar1 = uVar2;
          puVar1[2] = fVar3 + local_40;
        }
      }
      if ((-1 < iVar5 + -1) && (iVar5 + -1 < *(int *)(param_2 + 4))) {
        iVar4 = *(int *)(param_2 + 0xc);
        uVar2 = *(undefined4 *)(iVar4 + 0x10 + iVar6);
        puVar1 = (undefined4 *)(iVar4 + 0x10 + iVar6);
        fVar3 = *(float *)(*(int *)(param_1 + 0xc) + 0x18 + iVar6);
        if (local_40 < (float)puVar1[2] - fVar3) {
          puVar1[1] = *(undefined4 *)(iVar4 + 0x14 + iVar6);
          *puVar1 = uVar2;
          puVar1[2] = fVar3 + local_40;
        }
      }
      if ((-1 < iVar5) && (iVar5 < *(int *)(param_2 + 4))) {
        iVar4 = *(int *)(param_2 + 0xc);
        uVar2 = *(undefined4 *)(iVar4 + 0x20 + iVar6);
        puVar1 = (undefined4 *)(iVar4 + 0x20 + iVar6);
        fVar3 = *(float *)(*(int *)(param_1 + 0xc) + 0x28 + iVar6);
        if (local_40 < (float)puVar1[2] - fVar3) {
          puVar1[1] = *(undefined4 *)(iVar4 + 0x24 + iVar6);
          *puVar1 = uVar2;
          puVar1[2] = fVar3 + local_40;
        }
      }
      if ((-1 < iVar5 + 1) && (iVar5 + 1 < *(int *)(param_2 + 4))) {
        iVar4 = *(int *)(param_2 + 0xc);
        uVar2 = *(undefined4 *)(iVar4 + 0x30 + iVar6);
        puVar1 = (undefined4 *)(iVar4 + 0x30 + iVar6);
        fVar3 = *(float *)(*(int *)(param_1 + 0xc) + 0x38 + iVar6);
        if (local_40 < (float)puVar1[2] - fVar3) {
          puVar1[1] = *(undefined4 *)(iVar4 + 0x34 + iVar6);
          *puVar1 = uVar2;
          puVar1[2] = fVar3 + local_40;
        }
      }
      local_44 = local_38 + 4;
      iVar4 = iVar5 + 5;
      iVar6 = iVar6 + 0x40;
      iVar5 = iVar5 + 4;
      local_38 = local_44;
    } while (iVar4 < iVar7);
  }
  if (local_44 <= iVar7) {
    iVar5 = local_44 << 4;
    do {
      if ((-1 < iVar5) && (local_44 < *(int *)(param_2 + 4))) {
        uVar2 = *(undefined4 *)(*(int *)(param_2 + 0xc) + iVar5);
        puVar1 = (undefined4 *)(*(int *)(param_2 + 0xc) + iVar5);
        fVar3 = *(float *)(*(int *)(param_1 + 0xc) + 8 + iVar5);
        if (local_40 < (float)puVar1[2] - fVar3) {
          puVar1[1] = puVar1[1];
          *puVar1 = uVar2;
          puVar1[2] = fVar3 + local_40;
        }
      }
      local_44 = local_44 + 1;
      iVar5 = iVar5 + 0x10;
    } while (local_44 <= iVar7);
  }
  return;
}


// ==== 0x4936e0 FUN_004936e0

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004936e0(int param_1,float param_2,int param_3,int param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  float10 fVar6;
  int local_10b8;
  int local_10b4;
  float *local_10b0;
  int local_10ac;
  float local_10a8;
  int local_10a4;
  undefined4 local_10a0;
  undefined4 local_109c;
  int local_1090;
  int local_108c;
  undefined4 local_1088;
  undefined1 *local_1084;
  undefined4 local_1080;
  undefined4 local_107c;
  undefined4 local_1078;
  undefined4 local_1070;
  undefined4 local_1064;
  undefined4 local_1058;
  float local_1048 [10];
  undefined1 local_1020 [4092];
  undefined4 uStack_24;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  pcStack_18 = FUN_00685b0b;
  local_1c = ExceptionList;
  uStack_24 = 0x493706;
  ExceptionList = &local_1c;
  bCeil((float)*(int *)(param_1 + 4) * param_2);
  iVar3 = _ftol_nocw();
  local_1048[0] = 0.0;
  local_1048[1] = 0.0;
  if (((param_3 != 0) && (param_4 != 0)) && (iVar5 = 0, 0 < param_4)) {
    do {
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 == 0) {
LAB_0049378f:
        fVar1 = (float)(*(int *)(param_1 + 4) + -1);
      }
      else if (iVar2 == 1) {
        fVar1 = (float)*(int *)(param_1 + 4);
      }
      else {
        if (iVar2 == 2) goto LAB_0049378f;
        fVar1 = 0.0;
      }
      fVar1 = (*(float *)(param_3 + iVar5 * 4) / fVar1) * (float)(iVar3 + -1);
      fVar6 = (float10)Float_Truncate(fVar1);
      if ((float10)fVar1 < fVar6) {
        fVar6 = fVar6 - (float10)_K_ONE;
      }
      if ((float10)_K_HALF <= (float10)fVar1 - fVar6) {
        fVar6 = (float10)bCeil(fVar1);
      }
      else {
        fVar6 = (float10)Float_Truncate();
        if ((float10)fVar1 < fVar6) {
          fVar6 = fVar6 - (float10)_K_ONE;
        }
      }
      fVar1 = *(float *)(param_3 + iVar5 * 4);
      iVar5 = iVar5 + 1;
      local_1048[iVar5 * 2] = (float)fVar6;
      local_1048[iVar5 * 2 + 1] = fVar1;
    } while (iVar5 < param_4);
  }
  iVar5 = *(int *)(param_1 + 8);
  if (iVar5 != 0) {
    if (iVar5 == 1) {
      fVar1 = (float)*(int *)(param_1 + 4);
      goto LAB_0049384f;
    }
    if (iVar5 != 2) {
      fVar1 = 0.0;
      goto LAB_0049384f;
    }
  }
  fVar1 = (float)(*(int *)(param_1 + 4) + -1);
LAB_0049384f:
  local_1048[param_4 * 2 + 3] = fVar1;
  local_1048[param_4 * 2 + 2] = (float)(iVar3 + -1);
  local_10ac = param_4 + 2;
  local_10b0 = local_1048;
  local_10b8 = 0;
  if (0 < iVar3) {
    do {
      fVar6 = (float10)LinearTable__Lookup11(&local_10b0,(float)local_10b8);
      FUN_005829e0((float)fVar6);
      local_10b8 = local_10b8 + 1;
    } while (local_10b8 < iVar3);
  }
  local_1084 = local_1020;
  local_1088 = 2;
  local_1070 = 0;
  local_107c = 1;
  local_1078 = 0;
  local_1064 = 0;
  local_1080 = 0;
  local_10a4 = *(int *)(param_1 + 4);
  local_14 = 0;
  local_10b4 = 0;
  if (0 < local_10a4) {
    local_10a8 = (float)(local_10a4 + -1);
    local_10b8 = 0;
    local_1090 = iVar3;
    local_108c = iVar3;
    do {
      iVar3 = *(int *)(param_1 + 8);
      if (iVar3 == 0) {
LAB_0049393d:
        fVar1 = (float)(*(int *)(param_1 + 4) + -1);
      }
      else if (iVar3 == 1) {
        fVar1 = (float)*(int *)(param_1 + 4);
      }
      else {
        if (iVar3 == 2) goto LAB_0049393d;
        fVar1 = 0.0;
      }
      fVar1 = ((float)local_10b4 * fVar1) / local_10a8;
      fVar6 = (float10)FUN_00583ff0(&local_10b0,fVar1);
      FUN_005829e0((float)fVar6);
      FUN_005829e0(fVar1);
      puVar4 = (undefined4 *)(*(int *)(param_1 + 0xc) + local_10b8);
      puVar4[1] = local_109c;
      local_10b8 = local_10b8 + 0x10;
      *puVar4 = local_10a0;
      puVar4[2] = local_1058;
      local_10b4 = local_10b4 + 1;
    } while (local_10b4 < local_10a4);
  }
  ExceptionList = local_1c;
  return;
}


// ==== 0x4939e0 FUN_004939e0

void FUN_004939e0(float param_1)

{
  float fVar1;
  float *pfVar2;
  int in_EAX;
  float *pfVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(in_EAX + 4) + -1;
  pfVar3 = *(float **)(in_EAX + 0xc);
  iVar5 = iVar4;
  pfVar2 = pfVar3;
  if (0 < iVar4) {
    do {
      fVar1 = pfVar2[4] - *pfVar2;
      fVar1 = SQRT(fVar1 * fVar1 + (pfVar2[5] - pfVar2[1]) * (pfVar2[5] - pfVar2[1])) * param_1 +
              pfVar2[2];
      if (fVar1 < pfVar2[6]) {
        pfVar2[6] = fVar1;
      }
      iVar5 = iVar5 + -1;
      pfVar2 = pfVar2 + 4;
    } while (iVar5 != 0);
    if (0 < iVar4) {
      pfVar3 = pfVar3 + iVar4 * 4 + -4;
      do {
        fVar1 = SQRT((*pfVar3 - pfVar3[4]) * (*pfVar3 - pfVar3[4]) +
                     (pfVar3[1] - pfVar3[5]) * (pfVar3[1] - pfVar3[5])) * param_1 + pfVar3[6];
        if (fVar1 < pfVar3[2]) {
          pfVar3[2] = fVar1;
        }
        pfVar3 = pfVar3 + -4;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  return;
}


// ==== 0x493a90 FUN_00493a90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00493a90(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  float *unaff_ESI;
  int local_24;
  float local_18;
  
  piVar4 = *(int **)(param_1 + 8);
  fVar1 = 0.0;
  fVar2 = 0.0;
  fVar3 = 0.0;
  local_24 = 0;
  local_18 = 0.0;
  if (piVar4 == (int *)(param_1 + 8)) {
    fVar2 = 0.0;
    fVar1 = 0.0;
  }
  else {
    do {
      local_24 = local_24 + 1;
      fVar1 = fVar1 + (float)piVar4[4];
      fVar2 = (float)piVar4[5] + fVar2;
      fVar3 = fVar3 + (float)piVar4[6];
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)(param_1 + 8));
    local_18 = fVar3;
    if (0 < local_24) goto LAB_00493ae3;
  }
  local_24 = 1;
LAB_00493ae3:
  fVar3 = _K_ONE / (float)local_24;
  *unaff_ESI = fVar1 * fVar3;
  unaff_ESI[1] = fVar2 * fVar3;
  unaff_ESI[2] = local_18 * fVar3;
  return;
}


// ==== 0x493b20 FUN_00493b20

undefined2 FUN_00493b20(char param_1)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  int in_EAX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float *unaff_EDI;
  
  puVar5 = (undefined4 *)(in_EAX + 8);
  for (puVar4 = *(undefined4 **)(in_EAX + 8); puVar4 != puVar5; puVar4 = (undefined4 *)*puVar4) {
    if (20.0 < SQRT((*unaff_EDI - (float)puVar4[4]) * (*unaff_EDI - (float)puVar4[4]) +
                    (unaff_EDI[1] - (float)puVar4[5]) * (unaff_EDI[1] - (float)puVar4[5]) +
                    (unaff_EDI[2] - (float)puVar4[6]) * (unaff_EDI[2] - (float)puVar4[6]))) {
      return 0;
    }
  }
  if (param_1 != '\0') {
    puVar4 = _malloc(0x20);
    if (puVar4 != (undefined4 *)0x0) {
      fVar1 = unaff_EDI[1];
      fVar2 = unaff_EDI[2];
      puVar4[4] = *unaff_EDI;
      puVar4[5] = fVar1;
      puVar4[6] = fVar2;
      puVar3 = *(undefined4 **)(in_EAX + 0xc);
      *puVar3 = puVar4;
      *(undefined4 **)(in_EAX + 0xc) = puVar4;
      *puVar4 = puVar5;
      puVar4[1] = puVar3;
      return 1;
    }
    puRam00000004 = *(undefined4 **)(in_EAX + 0xc);
    *puRam00000004 = 0;
    *(undefined4 *)(in_EAX + 0xc) = 0;
    puRam00000000 = puVar5;
  }
  return 1;
}


// ==== 0x493bd0 FUN_00493bd0

void FUN_00493bd0(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)*param_2;
  puVar2 = (undefined4 *)NullUpdate_ret();
  for (; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
    cVar1 = FUN_00493b20(param_3);
    if (cVar1 != '\0') {
      return;
    }
  }
  puVar3 = _malloc(0x10);
  if (puVar3 == (undefined4 *)0x0) {
    puRam00000004 = (undefined4 *)param_2[1];
    *puRam00000004 = 0;
    param_2[1] = 0;
    puRam00000000 = param_2;
    return;
  }
  puVar2 = puVar3 + 2;
  *puVar2 = puVar2;
  puVar3[3] = puVar2;
  FUN_00493b20(1);
  puVar2 = (undefined4 *)param_2[1];
  *puVar2 = puVar3;
  param_2[1] = puVar3;
  *puVar3 = param_2;
  puVar3[1] = puVar2;
  return;
}


// ==== 0x493c60 FUN_00493c60

float10 FUN_00493c60(float *param_1,float *param_2)

{
  return (float10)*param_1 - (float10)*param_2;
}


// ==== 0x493c70 FUN_00493c70

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
FUN_00493c70(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            undefined4 param_6,float *param_7,float *param_8,int param_9,int param_10)

{
  int ****ppppiVar1;
  int ***pppiVar2;
  int ***pppiVar3;
  int ****_Memory;
  float fVar4;
  int ***_Memory_00;
  float *pfVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  char *pcVar11;
  undefined1 *puVar12;
  float fVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  float10 fVar17;
  float local_2174;
  int ***local_2170;
  int ***local_216c;
  int ***local_2168;
  float local_2164;
  int local_2160;
  float *local_215c;
  uint local_2158;
  int local_2154;
  float local_2150;
  float local_214c;
  float local_2148;
  int ***local_2134;
  float local_2130;
  float local_212c;
  float local_2128;
  char cStack_2121;
  undefined4 local_2120 [64];
  undefined4 local_2020 [4];
  undefined1 local_2010 [8];
  float local_2008 [2041];
  undefined4 uStack_24;
  undefined4 uStack_20;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  pcStack_18 = FUN_0068614b;
  local_1c = ExceptionList;
  uStack_24 = 0x493c96;
  local_216c = (int ***)&local_216c;
  local_2168 = (int ***)&local_216c;
  iVar14 = 0;
  iVar7 = *(int *)(DAT_007361f8 + 0x20) - *(int *)(DAT_007361f8 + 0x1c);
  local_14 = 0;
  ExceptionList = &local_1c;
  uStack_20 = param_1;
  if (0 < iVar7) {
    piVar16 = (int *)(DAT_007361f8 + 0x28 + *(int *)(DAT_007361f8 + 0x1c) * 4);
    do {
      if (*(char *)(*(int *)(*piVar16 + 0x1c) + 10) == '\x01') {
        ExceptionList = &local_1c;
        FUN_00493bd0(param_2,&local_216c,0);
        break;
      }
      iVar14 = iVar14 + 1;
      piVar16 = piVar16 + 1;
      ExceptionList = &local_1c;
    } while (iVar14 < iVar7);
  }
  iVar7 = *(int *)(DAT_007361f8 + 0x1c);
  iVar15 = 0;
  iVar14 = DAT_007361f8;
  if (*(int *)(DAT_007361f8 + 0x20) != iVar7 && -1 < *(int *)(DAT_007361f8 + 0x20) - iVar7) {
    do {
      iVar7 = *(int *)(iVar14 + 0x28 + (iVar7 + iVar15) * 4);
      if ((*(char *)(*(int *)(iVar7 + 0x1c) + 10) == '\x02') || (*(int *)(iVar7 + 0x3cc) == 0)) {
        FUN_00493bd0(param_2,&local_216c,0);
        iVar14 = DAT_007361f8;
      }
      iVar7 = *(int *)(iVar14 + 0x1c);
      iVar15 = iVar15 + 1;
    } while (iVar15 < *(int *)(iVar14 + 0x20) - iVar7);
  }
  piVar16 = *(int **)(iVar14 + 0x10);
  if (piVar16 != (int *)(iVar14 + 0x10)) {
    do {
      if ((*(char *)(*(int *)(piVar16[0x19] + 600) + 0x15) == '\0') &&
         (*(char *)(*(int *)(piVar16[0x19] + 0x25c) + 0x15) == '\0')) {
        FUN_00493bd0(param_2,&local_216c,0);
        iVar14 = DAT_007361f8;
      }
      piVar16 = (int *)*piVar16;
    } while (piVar16 != (int *)(iVar14 + 0x10));
  }
  uVar10 = *(int *)(param_5 + 4) - 1;
  puVar9 = local_2120;
  for (uVar8 = uVar10 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  for (uVar8 = uVar10 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined1 *)puVar9 = 0;
    puVar9 = (undefined4 *)((int)puVar9 + 1);
  }
  local_2160 = 0;
  local_2170 = local_216c;
  fVar13 = (float)0;
  local_2158 = uVar10;
  if (0 < param_10) {
    local_2134 = (int ***)NullUpdate_ret();
    local_215c = local_2008;
    do {
      if (local_2170 == local_2134) break;
      FUN_00493a90();
      fVar17 = (float10)FUN_00582cf0(0xbf19999a,0x3c23d70a);
      local_2164 = (float)fVar17;
      iVar7 = *(int *)(param_4 + 8);
      if (iVar7 == 0) {
LAB_00493e3c:
        fVar13 = (float)(*(int *)(param_4 + 4) + -1);
      }
      else if (iVar7 == 1) {
        fVar13 = (float)*(int *)(param_4 + 4);
      }
      else {
        if (iVar7 == 2) goto LAB_00493e3c;
        fVar13 = 0.0;
      }
      if (ABS(*param_7) < 0.001 == (ABS(*param_7) == 0.001)) {
        fVar13 = (local_2164 / fVar13 - param_7[1]) / *param_7;
      }
      else {
        fVar13 = param_7[1];
      }
      iVar7 = *(int *)(param_5 + 8);
      if (iVar7 == 0) {
LAB_00493e8a:
        fVar4 = (float)(*(int *)(param_5 + 4) + -1);
      }
      else if (iVar7 == 1) {
        fVar4 = (float)*(int *)(param_5 + 4);
      }
      else {
        if (iVar7 == 2) goto LAB_00493e8a;
        fVar4 = 0.0;
      }
      fVar4 = (fVar13 * *param_8 + param_8[1]) * fVar4;
      fVar17 = (float10)Float_Truncate(fVar4);
      if ((float10)fVar4 < fVar17) {
        fVar17 = fVar17 - (float10)_K_ONE;
      }
      local_2174 = (float)fVar17;
      iVar7 = _ftol_nocw();
      if (((iVar7 < 0) || ((int)uVar10 <= iVar7)) ||
         (pcVar11 = (char *)((int)local_2120 + iVar7), uVar10 = local_2158,
         *(char *)((int)local_2120 + iVar7) != '\0')) {
        iVar14 = iVar7 + -1;
        if (((-1 < iVar14) && (iVar14 < (int)uVar10)) &&
           (pcVar11 = (char *)((int)local_2120 + iVar7 + -1), uVar10 = local_2158, *pcVar11 == '\0')
           ) {
          local_2174 = (float)iVar14;
          goto LAB_00493f0f;
        }
      }
      else {
LAB_00493f0f:
        iVar7 = *(int *)(param_5 + 8);
        if (iVar7 == 0) {
LAB_00493f2f:
          local_2154 = *(int *)(param_5 + 4) + -1;
          fVar13 = (float)local_2154;
        }
        else if (iVar7 == 1) {
          fVar13 = (float)*(int *)(param_5 + 4);
        }
        else {
          if (iVar7 == 2) goto LAB_00493f2f;
          fVar13 = 0.0;
        }
        fVar13 = (*param_8 * 0.0 + param_8[1]) * fVar13;
        uVar10 = local_2158;
        if (local_2174 < fVar13 == (local_2174 == fVar13)) {
          if (iVar7 == 0) {
LAB_00493f78:
            local_2154 = *(int *)(param_5 + 4) + -1;
            fVar13 = (float)local_2154;
          }
          else if (iVar7 == 1) {
            fVar13 = (float)*(int *)(param_5 + 4);
          }
          else {
            if (iVar7 == 2) goto LAB_00493f78;
            fVar13 = 0.0;
          }
          if (local_2174 < (param_8[1] + *param_8) * fVar13) {
            FUN_005829e0(local_2164);
            cVar6 = GroundQuery__SweepSegment(&local_2130);
            uVar10 = local_2158;
            if ((cVar6 == '\0') &&
               (SQRT((local_2150 - local_2130) * (local_2150 - local_2130) +
                     (local_214c - local_212c) * (local_214c - local_212c) +
                     (local_2148 - local_2128) * (local_2148 - local_2128)) < 60.0)) {
              local_215c[-6] = local_2174;
              local_215c[-1] = local_214c;
              local_215c[-2] = local_2150;
              local_2160 = local_2160 + 1;
              *local_215c = local_2148;
              local_215c = local_215c + 8;
              *pcVar11 = '\x01';
            }
          }
        }
      }
      local_2170 = (int ***)*local_2170;
      fVar13 = (float)local_2160;
    } while (local_2160 < param_10);
  }
  local_2164 = fVar13;
  RoadEntries_Sort(local_2020,0x20,FUN_00493c60);
  iVar7 = 0;
  if (0 < (int)fVar13) {
    puVar9 = local_2020;
    do {
      *(undefined4 *)(param_9 + iVar7 * 4) = *puVar9;
      iVar7 = iVar7 + 1;
      puVar9 = puVar9 + 8;
    } while (iVar7 < (int)fVar13);
  }
  local_2170 = *(int ****)(param_5 + 0xc);
  iVar7 = 0;
  local_215c = (float *)0x0;
  if (0 < *(int *)(param_5 + 4)) {
    puVar12 = local_2010;
    do {
      pfVar5 = local_215c;
      if ((iVar7 < (int)local_2164) && ((float)(int)local_215c == *(float *)(param_9 + iVar7 * 4)))
      {
        FUN_005825e0(param_6,puVar12);
        iVar7 = iVar7 + 1;
        puVar12 = puVar12 + 0x20;
      }
      else {
        FUN_005825e0(param_6,local_2170);
      }
      local_2170 = (int ***)((int)local_2170 + 0x10);
      local_215c = (float *)((int)pfVar5 + 1);
      fVar13 = local_2164;
    } while ((int)local_215c < *(int *)(param_5 + 4));
  }
  FUN_004936e0(param_6,0x3eaaa64c,param_9,fVar13);
  if ((int ****)local_216c != &local_216c) {
    do {
      _Memory_00 = local_216c;
      pppiVar2 = (int ***)*local_216c;
      pppiVar3 = (int ***)local_216c[1];
      *pppiVar3 = (int **)pppiVar2;
      ppppiVar1 = (int ****)(local_216c + 2);
      pppiVar2[1] = (int **)pppiVar3;
      _Memory = (int ****)*ppppiVar1;
      while (_Memory != ppppiVar1) {
        pppiVar2 = *_Memory;
        pppiVar3 = _Memory[1];
        *pppiVar3 = (int **)pppiVar2;
        pppiVar2[1] = (int **)pppiVar3;
        _free(_Memory);
        _Memory = (int ****)*ppppiVar1;
      }
      _free(_Memory_00);
    } while ((int ****)local_216c != &local_216c);
  }
  ExceptionList = local_1c;
  return (int)fVar13;
}


// ==== 0x494180 FUN_00494180

void FUN_00494180(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  float fVar5;
  int *in_EAX;
  int iVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  int local_850;
  float local_84c;
  float local_848;
  float local_844;
  undefined4 local_840;
  undefined4 local_83c;
  float local_838;
  undefined4 local_830;
  undefined4 local_82c;
  float local_828;
  undefined4 local_81c;
  float afStack_810 [255];
  float afStack_414 [260];
  
  if (*in_EAX == 0) {
    return;
  }
  fVar2 = 0.0;
  local_844 = 0.0;
  local_848 = 0.0;
  local_850 = 0;
  if (in_EAX[1] != 1 && -1 < in_EAX[1] + -1) {
    do {
      if ((float)in_EAX[4] <= local_848) break;
      FUN_004422b0(local_844,in_EAX[5]);
      GroundQuery__RefillCache(&local_840,0x41400000,0);
      fVar9 = (float10)GroundQuery__FindSurfaceBelow(param_1,&local_840,0,0,0);
      local_838 = (float)(fVar9 + (float10)1.5);
      if (param_2 != 0) {
        FUN_005825e0(param_2,&local_840);
      }
      if (param_3 != 0) {
        local_828 = local_838 + 0.5;
        local_830 = local_840;
        local_82c = local_83c;
        FUN_005825e0(param_3,&local_830);
      }
      if (param_4 != 0) {
        local_828 = local_838 + 10.0;
        local_830 = local_840;
        local_82c = local_83c;
        FUN_005825e0(param_4,&local_830);
      }
      local_844 = local_844 + 10.0;
      fVar5 = local_848 + 10.0;
      if (fVar5 < (float)in_EAX[4]) {
        iVar8 = local_850 * 0x18;
        do {
          if ((in_EAX[1] + -1 <= local_850) ||
             (iVar6 = *in_EAX, local_844 <= *(float *)(iVar8 + 8 + iVar6))) break;
          local_844 = local_844 - *(float *)(iVar8 + 8 + iVar6);
          local_850 = local_850 + 1;
          in_EAX[5] = (int)(*(float *)(iVar8 + 0x2c + iVar6) + (float)in_EAX[5]);
          iVar8 = iVar8 + 0x18;
        } while (fVar5 < (float)in_EAX[4]);
      }
      local_84c = 4.0;
      fVar2 = *(float *)(*in_EAX + 0xc + local_850 * 0x18);
      fVar3 = (float)in_EAX[5];
      if (ABS(fVar2 - fVar3) <= 4.0) {
        local_84c = ABS(fVar2 - fVar3);
      }
      if (fVar3 <= fVar2) {
        if (fVar3 < fVar2) {
          fVar3 = fVar3 + local_84c;
        }
      }
      else {
        fVar3 = fVar3 - local_84c;
      }
      in_EAX[5] = (int)fVar3;
      fVar2 = local_848;
      local_848 = fVar5;
    } while (local_850 < in_EAX[1] + -1);
  }
  in_EAX[4] = (int)fVar2;
  if (((param_2 != 0) && (param_3 != 0)) && (param_4 != 0)) {
    local_850 = 0;
    do {
      iVar8 = *(int *)(param_2 + 8);
      if (iVar8 == 0) {
LAB_004943de:
        fVar2 = (float)(*(int *)(param_2 + 4) + -1);
      }
      else if (iVar8 == 1) {
        fVar2 = (float)*(int *)(param_2 + 4);
      }
      else {
        if (iVar8 == 2) goto LAB_004943de;
        fVar2 = 0.0;
      }
      fVar2 = (float)local_850 * fVar2 * 0.01010101;
      FUN_005829e0(fVar2);
      GroundQuery__RefillCache(&local_840,0x412b3333,0);
      fVar9 = (float10)GroundQuery__FindSurfaceBelow(param_1,&local_840,0,0,0);
      local_838 = (float)(fVar9 + (float10)1.5);
      FUN_005829e0(fVar2);
      local_828 = local_838 + 0.5;
      FUN_00441030(param_1,0,0,&local_830,0x3f333333,0x3f800000);
      FUN_00441030(param_1,1,0,&local_830,0x3f333333,0x3f800000);
      FUN_00441030(param_1,0,0,&local_840,0x3f333333,0x3f800000);
      FUN_00441030(param_1,1,0,&local_840,0x3f333333,0x3f800000);
      afStack_810[local_850] = local_828 - local_838;
      FUN_005829e0(fVar2);
      local_828 = local_838 + 10.0;
      FUN_00441030(param_1,0,0,&local_830,0x3f333333,0x3f800000);
      FUN_00441030(param_1,1,0,&local_830,0x3f333333,0x3f800000);
      FUN_00441030(param_1,0,0,&local_840,0x3f333333,0x3f800000);
      FUN_00441030(param_1,1,0,&local_840,0x3f333333,0x3f800000);
      local_850 = local_850 + 1;
      afStack_414[local_850] = local_828 - local_838;
    } while (local_850 < 100);
    local_850 = 0;
    do {
      iVar6 = _ftol_nocw();
      iVar8 = iVar6 + -1;
      if (iVar8 < iVar6 + 3) {
        fVar2 = afStack_810[local_850];
        iVar7 = iVar8 * 0x10;
        do {
          if ((-1 < iVar7) && (iVar8 < *(int *)(param_3 + 4))) {
            uVar4 = *(undefined4 *)(*(int *)(param_3 + 0xc) + iVar7);
            puVar1 = (undefined4 *)(*(int *)(param_3 + 0xc) + iVar7);
            local_81c = puVar1[1];
            fVar5 = *(float *)(*(int *)(param_2 + 0xc) + 8 + iVar7);
            if (fVar2 < (float)puVar1[2] - fVar5) {
              puVar1[1] = local_81c;
              *puVar1 = uVar4;
              puVar1[2] = fVar5 + fVar2;
            }
          }
          iVar8 = iVar8 + 1;
          iVar7 = iVar7 + 0x10;
        } while (iVar8 < iVar6 + 3);
      }
      local_850 = local_850 + 1;
    } while (local_850 < 100);
    local_850 = 0;
    do {
      iVar6 = _ftol_nocw();
      iVar8 = iVar6 + -1;
      if (iVar8 < iVar6 + 3) {
        fVar2 = afStack_414[local_850 + 1];
        iVar7 = iVar8 * 0x10;
        do {
          if ((-1 < iVar7) && (iVar8 < *(int *)(param_4 + 4))) {
            uVar4 = *(undefined4 *)(*(int *)(param_4 + 0xc) + iVar7);
            puVar1 = (undefined4 *)(*(int *)(param_4 + 0xc) + iVar7);
            local_81c = puVar1[1];
            fVar5 = *(float *)(*(int *)(param_2 + 0xc) + 8 + iVar7);
            if (fVar2 < (float)puVar1[2] - fVar5) {
              puVar1[1] = local_81c;
              *puVar1 = uVar4;
              puVar1[2] = fVar5 + fVar2;
            }
          }
          iVar8 = iVar8 + 1;
          iVar7 = iVar7 + 0x10;
        } while (iVar8 < iVar6 + 3);
      }
      local_850 = local_850 + 1;
    } while (local_850 < 100);
  }
  if ((param_5 != 0) && (param_2 != 0)) {
    if (param_3 == 0) goto LAB_00494827;
    _ftol_nocw();
    _ftol_nocw();
    FUN_00493420(param_2,param_3);
    FUN_00493420(param_2,param_3);
    if (param_4 != 0) {
      FUN_00493420(param_2,param_4);
      FUN_00493420(param_2,param_4);
    }
  }
  if (param_3 != 0) {
    FUN_004939e0(0x3ecccccd);
  }
LAB_00494827:
  if (param_4 != 0) {
    FUN_004939e0(0x3ecccccd);
  }
  if (param_2 != 0) {
    FUN_004936e0(param_2,0x3eaaa64c,0,0);
  }
  if (param_3 != 0) {
    FUN_004936e0(param_3,0x3eaaa64c,0,0);
  }
  if (param_4 != 0) {
    FUN_004936e0(param_4,0x3eaaa64c,0,0);
  }
  return;
}


// ==== 0x494890 FUN_00494890

void FUN_00494890(void)

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
    bTList___bTList();
    _free(_Memory);
    _Memory = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x4948c0 Screen_Options::ItemList::_ItemList

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

void __fastcall Screen_Options__ItemList___ItemList(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = param_1 + 1;
  *param_1 = &PTR_FUN_006c7ad4;
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


// ==== 0x4948f0 FUN_004948f0

void * __thiscall FUN_004948f0(void *param_1,byte param_2)

{
  Screen_Options__ItemList___ItemList();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x494910 Screen_Options::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_Options__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687413;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x58);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_Options__Screen_Options(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x494970 Screen_Options::Screen_Options

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_Options__Screen_Options(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_006c7ad8;
  FUN_004f81a0(param_1 + 0x10,"font_a(22)");
  puVar1 = _malloc(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_006c186c;
    puVar1[3] = 0;
    puVar1[4] = "Option 1 a";
    piVar3 = puVar1 + 1;
  }
  puVar2 = (undefined4 *)param_1[0x12];
  puVar1 = param_1 + 0x11;
  *puVar2 = piVar3;
  param_1[0x12] = piVar3;
  piVar3[1] = (int)puVar2;
  *piVar3 = (int)puVar1;
  puVar2 = _malloc(0x14);
  if (puVar2 == (undefined4 *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_006c186c;
    puVar2[3] = 1;
    puVar2[4] = "Option 1 b";
    piVar3 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)param_1[0x12];
  *puVar2 = piVar3;
  param_1[0x12] = piVar3;
  piVar3[1] = (int)puVar2;
  *piVar3 = (int)puVar1;
  puVar2 = _malloc(0x14);
  if (puVar2 == (undefined4 *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_006c186c;
    puVar2[3] = 2;
    puVar2[4] = "Option 1 c";
    piVar3 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)param_1[0x12];
  *puVar2 = piVar3;
  param_1[0x12] = piVar3;
  piVar3[1] = (int)puVar2;
  *piVar3 = (int)puVar1;
  puVar2 = _malloc(0x14);
  if (puVar2 == (undefined4 *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_006c186c;
    puVar2[3] = 3;
    puVar2[4] = "Option 1 d";
    piVar3 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)param_1[0x12];
  *puVar2 = piVar3;
  param_1[0x12] = piVar3;
  piVar3[1] = (int)puVar2;
  *piVar3 = (int)puVar1;
  puVar2 = _malloc(0x14);
  if (puVar2 == (undefined4 *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_006c186c;
    puVar2[3] = 4;
    puVar2[4] = "Option 1 e";
    piVar3 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)param_1[0x12];
  *puVar2 = piVar3;
  param_1[0x12] = piVar3;
  *piVar3 = (int)puVar1;
  piVar3[1] = (int)puVar2;
  FUN_004f8240();
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x494af0 FUN_00494af0

void * __thiscall FUN_00494af0(void *param_1,byte param_2)

{
  FUN_00494b10(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x494b10 FUN_00494b10

void FUN_00494b10(undefined4 *param_1)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c7ad8;
  local_4 = 0;
  Screen_Options__ItemList___ItemList();
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x494b70 FUN_00494b70

void FUN_00494b70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_004f8290(param_3,param_4);
  return;
}


// ==== 0x494b90 FUN_00494b90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00494b90(void)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_0073619c;
  iVar2 = *in_EAX;
  if (iVar2 == 0) {
    iVar2 = in_EAX[3];
    *(int *)(DAT_0073619c + 0x534) = in_EAX[2];
    *(int *)(iVar1 + 0x538) = iVar2;
    return 1;
  }
  if (iVar2 == 1) {
    iVar2 = (&DAT_007361b4)[in_EAX[2]];
    _DAT_0078a338 = in_EAX[3];
    *(int *)(*(int *)(iVar2 + 4) + 0x400) = _DAT_0078a338;
    *(char *)(iVar2 + 0x22) = (char)_DAT_0078a338;
    FUN_00456ba0();
    return 1;
  }
  if (iVar2 == 2) {
    DAT_0078a336 = in_EAX[2] != 0;
    iVar2 = 0;
    if (0 < *(int *)(DAT_007361f8 + 0x18)) {
      iVar3 = 0x28;
      iVar1 = DAT_007361f8;
      do {
        if (*(int *)(*(int *)(iVar3 + iVar1) + 0x868) != 0) {
          FUN_0058db20();
          iVar1 = DAT_007361f8;
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 4;
      } while (iVar2 < *(int *)(iVar1 + 0x18));
    }
    return 1;
  }
  if (iVar2 != 3) {
    if (iVar2 == 4) {
      DAT_0078a3fa = (char)in_EAX[2];
      return 1;
    }
    if (iVar2 != 5) {
      if (iVar2 != 6) {
        return 0;
      }
      DAT_007360b8 = in_EAX[2];
      return 1;
    }
    DAT_0078a3fb = (char)in_EAX[2];
    return 1;
  }
  iVar2 = (&DAT_007361b4)[in_EAX[2]];
  iVar1 = in_EAX[3];
  *(char *)(iVar2 + 0x23) = (char)iVar1;
  (&DAT_0078a387)[*(int *)(iVar2 + 0x10) * 0x38] = (char)iVar1;
  RealDriver__SetManualTransmission();
  return 1;
}


// ==== 0x494cb0 FUN_00494cb0

int FUN_00494cb0(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EDI;
  
  uVar1 = FEng__HashName();
  if (((((unaff_EDI != 0) && (iVar2 = FEngFindPackage(), iVar2 != 0)) &&
       (iVar2 = FUN_004ffb70(), iVar2 != 0)) ||
      ((DAT_0073578c != 0 && (iVar2 = FUN_004ef050(uVar1), iVar2 != 0)))) &&
     (*(int *)(iVar2 + 0x18) == 1)) {
    return iVar2;
  }
  return 0;
}


// ==== 0x494d00 tPreRaceScreenManager::tPreRaceScreenManager

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

undefined1 * tPreRaceScreenManager__tPreRaceScreenManager(undefined1 *param_1)

{
  undefined4 *puVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00688bfb;
  local_c = ExceptionList;
  puVar1 = (undefined4 *)(param_1 + 4);
  ExceptionList = &local_c;
  *puVar1 = puVar1;
  *(undefined4 **)(param_1 + 8) = puVar1;
  local_4 = 0;
  *param_1 = 0;
  param_1[1] = 0;
  HudWidget__RegisterObject(PTR_s_PreRaceStats_fng_006fbaa4);
  *(undefined4 *)(param_1 + 0xc) = *puVar1;
  FEManager__ShowPackage();
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x494d60 FUN_00494d60

void FUN_00494d60(void)

{
  int iVar1;
  int iVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  iVar1 = DAT_0073578c;
  pcStack_8 = FUN_00688bfb;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  if (DAT_0073578c != 0) {
    ExceptionList = &local_c;
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) {
      cFEng__PopPackage(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
    }
  }
  local_4 = 0xffffffff;
  FUN_00421900();
  ExceptionList = local_c;
  return;
}


// ==== 0x494de0 Screen_PreRaceStats::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_PreRaceStats__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687f43;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0xdc);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_PreRaceStats__Screen_PreRaceStats(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x494e40 Screen_PreRaceStats::Screen_PreRaceStats

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_PreRaceStats__Screen_PreRaceStats(undefined4 *param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int local_a0;
  byte local_98;
  byte local_97 [31];
  undefined **local_78;
  int local_74;
  int local_70;
  undefined **local_6c;
  int local_68;
  int local_64;
  undefined **local_60;
  int local_5c;
  int local_58;
  undefined **local_54;
  int local_50;
  int local_4c;
  undefined **local_48;
  int local_44;
  int local_40;
  undefined **local_3c;
  int local_38;
  int local_34;
  undefined **local_30;
  int local_2c;
  int local_28;
  undefined **local_24;
  int local_20;
  int local_1c;
  undefined **local_18;
  int local_14;
  int local_10;
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687f20;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_006c7a00;
  iVar4 = FEngFindPackage();
  if (iVar4 != 0) {
    *(undefined4 *)(iVar4 + 0x18) = 0;
  }
  iVar4 = *(int *)(DAT_0073619c + 0x24);
  param_1[0x34] = iVar4;
  if (4 < iVar4) {
    param_1[0x34] = 4;
  }
  local_a0 = 0;
  do {
    iVar5 = local_a0 + 1;
    bSPrintf_regdst(0x20,"CarModel_%d",iVar5);
    iVar4 = -1;
    pbVar7 = &local_98;
    bVar3 = local_98;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar7 + 1;
      pbVar7 = pbVar7 + 1;
      bVar3 = *pbVar1;
    }
    if (param_1[3] == 0) {
LAB_00494faa:
      if ((DAT_0073578c == 0) || (iVar6 = FUN_004ef050(iVar4), iVar6 == 0)) goto LAB_00494fc8;
LAB_00494fc2:
      if (*(int *)(iVar6 + 0x18) != 2) goto LAB_00494fc8;
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_00494f6c:
        local_54 = &PTR_FUN_006c1800;
        local_4._0_1_ = 1;
        local_4c = 0;
        local_50 = iVar4;
        FUN_004ffb00(iVar6);
        local_4 = (uint)local_4._1_3_ << 8;
        local_54 = &PTR_FUN_006c2c5c;
        iVar6 = local_4c;
        if (local_4c == 0) goto LAB_00494faa;
        goto LAB_00494fc2;
      }
      if (DAT_0073578c != 0) {
        iVar2 = *(int *)(DAT_0073578c + 8);
        if ((iVar2 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar2 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar2 + 0xec), iVar6 == 0)))) goto LAB_00494faa;
        goto LAB_00494f6c;
      }
LAB_00494fc8:
      iVar6 = 0;
    }
    param_1[local_a0 + 0x10] = iVar6;
    bSPrintf_regdst(0x20,"Driver_%d",iVar5);
    iVar4 = -1;
    pbVar7 = &local_98;
    bVar3 = local_98;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar7 + 1;
      pbVar7 = pbVar7 + 1;
      bVar3 = *pbVar1;
    }
    if (param_1[3] == 0) {
LAB_004950d4:
      if ((DAT_0073578c == 0) || (iVar6 = FUN_004ef050(iVar4), iVar6 == 0)) goto LAB_004950f4;
LAB_004950ee:
      if (*(int *)(iVar6 + 0x18) != 2) goto LAB_004950f4;
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_00495084:
        local_18 = &PTR_FUN_006c1800;
        local_4._0_1_ = 2;
        local_10 = 0;
        local_14 = iVar4;
        FUN_004ffb00(iVar6);
        local_4 = (uint)local_4._1_3_ << 8;
        local_18 = &PTR_FUN_006c2c5c;
        iVar6 = local_10;
        if (local_10 == 0) goto LAB_004950d4;
        goto LAB_004950ee;
      }
      if (DAT_0073578c != 0) {
        iVar2 = *(int *)(DAT_0073578c + 8);
        if ((iVar2 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar2 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar2 + 0xec), iVar6 == 0)))) goto LAB_004950d4;
        goto LAB_00495084;
      }
LAB_004950f4:
      iVar6 = 0;
    }
    param_1[local_a0 + 0x14] = iVar6;
    bSPrintf_regdst(0x20,"Taunt_%d",iVar5);
    iVar4 = -1;
    pbVar7 = &local_98;
    bVar3 = local_98;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar7 + 1;
      pbVar7 = pbVar7 + 1;
      bVar3 = *pbVar1;
    }
    if (param_1[3] == 0) {
LAB_004951ee:
      if ((DAT_0073578c == 0) || (iVar6 = FUN_004ef050(iVar4), iVar6 == 0)) goto LAB_0049520e;
LAB_00495208:
      if (*(int *)(iVar6 + 0x18) != 2) goto LAB_0049520e;
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_004951ad:
        local_3c = &PTR_FUN_006c1800;
        local_4._0_1_ = 3;
        local_34 = 0;
        local_38 = iVar4;
        FUN_004ffb00(iVar6);
        local_4 = (uint)local_4._1_3_ << 8;
        local_3c = &PTR_FUN_006c2c5c;
        iVar6 = local_34;
        if (local_34 == 0) goto LAB_004951ee;
        goto LAB_00495208;
      }
      if (DAT_0073578c != 0) {
        iVar2 = *(int *)(DAT_0073578c + 8);
        if ((iVar2 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar2 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar2 + 0xec), iVar6 == 0)))) goto LAB_004951ee;
        goto LAB_004951ad;
      }
LAB_0049520e:
      iVar6 = 0;
    }
    param_1[local_a0 + 0x18] = iVar6;
    bSPrintf_regdst(0x20,"Bet_%d",iVar5);
    iVar4 = -1;
    pbVar7 = &local_98;
    bVar3 = local_98;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar7 + 1;
      pbVar7 = pbVar7 + 1;
      bVar3 = *pbVar1;
    }
    if (param_1[3] == 0) {
LAB_0049530a:
      if ((DAT_0073578c == 0) || (iVar6 = FUN_004ef050(iVar4), iVar6 == 0)) goto LAB_00495328;
LAB_00495322:
      if (*(int *)(iVar6 + 0x18) != 1) goto LAB_00495328;
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_004952cc:
        local_78 = &PTR_FUN_006c1800;
        local_4._0_1_ = 4;
        local_70 = 0;
        local_74 = iVar4;
        FUN_004ffb00(iVar6);
        local_4 = (uint)local_4._1_3_ << 8;
        local_78 = &PTR_FUN_006c2c5c;
        iVar6 = local_70;
        if (local_70 == 0) goto LAB_0049530a;
        goto LAB_00495322;
      }
      if (DAT_0073578c != 0) {
        iVar2 = *(int *)(DAT_0073578c + 8);
        if ((iVar2 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar2 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar2 + 0xec), iVar6 == 0)))) goto LAB_0049530a;
        goto LAB_004952cc;
      }
LAB_00495328:
      iVar6 = 0;
    }
    param_1[local_a0 + 0x1c] = iVar6;
    bSPrintf_regdst(0x20,"Position_%d",iVar5);
    iVar4 = -1;
    pbVar7 = &local_98;
    bVar3 = local_98;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar7 + 1;
      pbVar7 = pbVar7 + 1;
      bVar3 = *pbVar1;
    }
    if (param_1[3] == 0) {
LAB_00495430:
      if ((DAT_0073578c == 0) || (iVar6 = FUN_004ef050(iVar4), iVar6 == 0)) goto LAB_00495450;
LAB_0049544a:
      if (*(int *)(iVar6 + 0x18) != 1) goto LAB_00495450;
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_004953e0:
        local_24 = &PTR_FUN_006c1800;
        local_4._0_1_ = 5;
        local_1c = 0;
        local_20 = iVar4;
        FUN_004ffb00(iVar6);
        local_4 = (uint)local_4._1_3_ << 8;
        local_24 = &PTR_FUN_006c2c5c;
        iVar6 = local_1c;
        if (local_1c == 0) goto LAB_00495430;
        goto LAB_0049544a;
      }
      if (DAT_0073578c != 0) {
        iVar2 = *(int *)(DAT_0073578c + 8);
        if ((iVar2 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar2 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar2 + 0xec), iVar6 == 0)))) goto LAB_00495430;
        goto LAB_004953e0;
      }
LAB_00495450:
      iVar6 = 0;
    }
    param_1[local_a0 + 0x20] = iVar6;
    bSPrintf_regdst(0x20,"RacerColor_%d",iVar5);
    iVar4 = -1;
    pbVar7 = &local_98;
    bVar3 = local_98;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar7 + 1;
      pbVar7 = pbVar7 + 1;
      bVar3 = *pbVar1;
    }
    if (param_1[3] == 0) {
LAB_0049554b:
      if ((DAT_0073578c == 0) || (iVar6 = FUN_004ef050(iVar4), iVar6 == 0)) goto LAB_0049556b;
LAB_00495565:
      if (*(int *)(iVar6 + 0x18) != 1) goto LAB_0049556b;
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_0049550d:
        local_6c = &PTR_FUN_006c1800;
        local_4._0_1_ = 6;
        local_64 = 0;
        local_68 = iVar4;
        FUN_004ffb00(iVar6);
        local_4 = (uint)local_4._1_3_ << 8;
        local_6c = &PTR_FUN_006c2c5c;
        iVar6 = local_64;
        if (local_64 == 0) goto LAB_0049554b;
        goto LAB_00495565;
      }
      if (DAT_0073578c != 0) {
        iVar2 = *(int *)(DAT_0073578c + 8);
        if ((iVar2 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar2 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar2 + 0xec), iVar6 == 0)))) goto LAB_0049554b;
        goto LAB_0049550d;
      }
LAB_0049556b:
      iVar6 = 0;
    }
    param_1[local_a0 + 0x24] = iVar6;
    bSPrintf_regdst(0x20,"BottomBacking_%d",iVar5);
    iVar4 = -1;
    pbVar7 = &local_98;
    bVar3 = local_98;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar7 + 1;
      pbVar7 = pbVar7 + 1;
      bVar3 = *pbVar1;
    }
    if (param_1[3] == 0) {
LAB_0049566b:
      if ((DAT_0073578c == 0) || (iVar6 = FUN_004ef050(iVar4), iVar6 == 0)) goto LAB_0049568b;
LAB_00495685:
      if (*(int *)(iVar6 + 0x18) != 1) goto LAB_0049568b;
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_0049562d:
        local_60 = &PTR_FUN_006c1800;
        local_4._0_1_ = 7;
        local_58 = 0;
        local_5c = iVar4;
        FUN_004ffb00(iVar6);
        local_4 = (uint)local_4._1_3_ << 8;
        local_60 = &PTR_FUN_006c2c5c;
        iVar6 = local_58;
        if (local_58 == 0) goto LAB_0049566b;
        goto LAB_00495685;
      }
      if (DAT_0073578c != 0) {
        iVar2 = *(int *)(DAT_0073578c + 8);
        if ((iVar2 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar2 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar2 + 0xec), iVar6 == 0)))) goto LAB_0049566b;
        goto LAB_0049562d;
      }
LAB_0049568b:
      iVar6 = 0;
    }
    param_1[local_a0 + 0x28] = iVar6;
    bSPrintf_regdst(0x20,"Coner_%d",iVar5);
    iVar4 = -1;
    pbVar7 = &local_98;
    bVar3 = local_98;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar7 + 1;
      pbVar7 = pbVar7 + 1;
      bVar3 = *pbVar1;
    }
    if (param_1[3] == 0) {
LAB_0049578b:
      if ((DAT_0073578c == 0) || (iVar6 = FUN_004ef050(iVar4), iVar6 == 0)) goto LAB_004957ab;
LAB_004957a5:
      if (*(int *)(iVar6 + 0x18) != 1) goto LAB_004957ab;
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_0049574d:
        local_48 = &PTR_FUN_006c1800;
        local_4._0_1_ = 8;
        local_40 = 0;
        local_44 = iVar4;
        FUN_004ffb00(iVar6);
        local_4 = (uint)local_4._1_3_ << 8;
        local_48 = &PTR_FUN_006c2c5c;
        iVar6 = local_40;
        if (local_40 == 0) goto LAB_0049578b;
        goto LAB_004957a5;
      }
      if (DAT_0073578c != 0) {
        iVar2 = *(int *)(DAT_0073578c + 8);
        if ((iVar2 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar2 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar2 + 0xec), iVar6 == 0)))) goto LAB_0049578b;
        goto LAB_0049574d;
      }
LAB_004957ab:
      iVar6 = 0;
    }
    param_1[local_a0 + 0x2c] = iVar6;
    bSPrintf_regdst(0x20,"CarColor_%d",iVar5);
    iVar4 = -1;
    pbVar7 = &local_98;
    bVar3 = local_98;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar7 + 1;
      pbVar7 = pbVar7 + 1;
      bVar3 = *pbVar1;
    }
    if (param_1[3] == 0) {
LAB_004958bd:
      if ((DAT_0073578c == 0) || (iVar6 = FUN_004ef050(iVar4), iVar6 == 0)) goto LAB_004958dd;
LAB_004958d7:
      if (*(int *)(iVar6 + 0x18) != 1) goto LAB_004958dd;
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_0049586d:
        local_30 = &PTR_FUN_006c1800;
        local_4._0_1_ = 9;
        local_28 = 0;
        local_2c = iVar4;
        FUN_004ffb00(iVar6);
        local_4 = (uint)local_4._1_3_ << 8;
        local_30 = &PTR_FUN_006c2c5c;
        iVar6 = local_28;
        if (local_28 == 0) goto LAB_004958bd;
        goto LAB_004958d7;
      }
      if (DAT_0073578c != 0) {
        iVar2 = *(int *)(DAT_0073578c + 8);
        if ((iVar2 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar2 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar2 + 0xec), iVar6 == 0)))) goto LAB_004958bd;
        goto LAB_0049586d;
      }
LAB_004958dd:
      iVar6 = 0;
    }
    param_1[local_a0 + 0x30] = iVar6;
    local_a0 = iVar5;
    if (3 < iVar5) {
      *(undefined1 *)(param_1 + 0x35) = 0;
      *(undefined1 *)((int)param_1 + 0xd5) = 0;
      *(undefined1 *)((int)param_1 + 0xd6) = 0;
      FUN_004959d0(param_1);
      ExceptionList = local_c;
      return param_1;
    }
  } while( true );
}


// ==== 0x495940 FUN_00495940

void * __thiscall FUN_00495940(void *param_1,byte param_2)

{
  FUN_00495960();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x495960 FUN_00495960

void __fastcall FUN_00495960(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c7a00;
  FUN_004f7b50();
  return;
}


// ==== 0x495970 FUN_00495970

void __thiscall FUN_00495970(int param_1,int param_2)

{
  char *pcVar1;
  
  pcVar1 = DAT_00735ed8;
  if (param_2 == -0x4a50db9f) {
    FUN_00421c00(DAT_007361f0,4,0);
  }
  else if (param_2 == -0x367ca946) {
    if (*(char *)(param_1 + 0xd4) != '\0') {
      *DAT_00735ed8 = '\x01';
    }
    if (*pcVar1 != '\0') {
      FUN_00495e90();
      return;
    }
  }
  else if (param_2 == -0x2796deef) {
    *(undefined1 *)(param_1 + 0xd4) = 1;
    return;
  }
  return;
}


// ==== 0x4959d0 FUN_004959d0

void FUN_004959d0(int param_1)

{
  char in_AL;
  int iVar1;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  int extraout_EDX_03;
  int extraout_EDX_04;
  int extraout_EDX_05;
  undefined4 uVar2;
  int extraout_EDX_06;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = param_1;
  *(char *)(param_1 + 0xd8) = in_AL;
  if (in_AL == '\0') {
    puVar3 = (undefined4 *)(param_1 + 0x50);
    iVar5 = 4;
    do {
      FEObject__SetInvisible(puVar3[-4]);
      FEObject__SetInvisible(*puVar3);
      FEObject__SetInvisible(puVar3[4]);
      FEObject__SetInvisible(puVar3[8]);
      FEObject__SetInvisible(puVar3[0xc]);
      FEObject__SetInvisible(puVar3[0x10]);
      FEObject__SetInvisible(puVar3[0x14]);
      FEObject__SetInvisible(puVar3[0x18]);
      FEObject__SetInvisible(puVar3[0x1c]);
      puVar3 = puVar3 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    return;
  }
  piVar4 = (int *)(param_1 + 0xd0);
  iVar1 = 0;
  param_1 = 0;
  if (0 < *piVar4) {
    piVar4 = (int *)(iVar5 + 0x50);
    do {
      iVar1 = piVar4[-4];
      if ((iVar1 != 0) &&
         (*(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffe | 0x400000,
         *(int *)(iVar1 + 0x18) == 5)) {
        uVar2 = *(undefined4 *)(iVar1 + 0x60);
        iVar1 = *(int *)(iVar1 + 0x5c);
        if (0 < iVar1) {
          do {
            FEObject__SetVisible(uVar2);
            uVar2 = *(undefined4 *)(extraout_EDX + 4);
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
        }
      }
      iVar1 = *piVar4;
      if ((iVar1 != 0) &&
         (*(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffe | 0x400000,
         *(int *)(iVar1 + 0x18) == 5)) {
        uVar2 = *(undefined4 *)(iVar1 + 0x60);
        iVar1 = *(int *)(iVar1 + 0x5c);
        if (0 < iVar1) {
          do {
            FEObject__SetVisible(uVar2);
            uVar2 = *(undefined4 *)(extraout_EDX_00 + 4);
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
        }
      }
      iVar1 = piVar4[4];
      if ((iVar1 != 0) &&
         (*(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffe | 0x400000,
         *(int *)(iVar1 + 0x18) == 5)) {
        uVar2 = *(undefined4 *)(iVar1 + 0x60);
        iVar1 = *(int *)(iVar1 + 0x5c);
        if (0 < iVar1) {
          do {
            FEObject__SetVisible(uVar2);
            uVar2 = *(undefined4 *)(extraout_EDX_01 + 4);
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
        }
      }
      iVar1 = piVar4[0xc];
      if ((iVar1 != 0) &&
         (*(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffe | 0x400000,
         *(int *)(iVar1 + 0x18) == 5)) {
        uVar2 = *(undefined4 *)(iVar1 + 0x60);
        iVar1 = *(int *)(iVar1 + 0x5c);
        if (0 < iVar1) {
          do {
            FEObject__SetVisible(uVar2);
            uVar2 = *(undefined4 *)(extraout_EDX_02 + 4);
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
        }
      }
      iVar1 = piVar4[0x10];
      if ((iVar1 != 0) &&
         (*(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffe | 0x400000,
         *(int *)(iVar1 + 0x18) == 5)) {
        uVar2 = *(undefined4 *)(iVar1 + 0x60);
        iVar1 = *(int *)(iVar1 + 0x5c);
        if (0 < iVar1) {
          do {
            FEObject__SetVisible(uVar2);
            uVar2 = *(undefined4 *)(extraout_EDX_03 + 4);
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
        }
      }
      iVar1 = piVar4[0x14];
      if ((iVar1 != 0) &&
         (*(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffe | 0x400000,
         *(int *)(iVar1 + 0x18) == 5)) {
        uVar2 = *(undefined4 *)(iVar1 + 0x60);
        iVar1 = *(int *)(iVar1 + 0x5c);
        if (0 < iVar1) {
          do {
            FEObject__SetVisible(uVar2);
            uVar2 = *(undefined4 *)(extraout_EDX_04 + 4);
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
        }
      }
      iVar1 = piVar4[0x18];
      if ((iVar1 != 0) &&
         (*(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffe | 0x400000,
         *(int *)(iVar1 + 0x18) == 5)) {
        uVar2 = *(undefined4 *)(iVar1 + 0x60);
        iVar1 = *(int *)(iVar1 + 0x5c);
        if (0 < iVar1) {
          do {
            FEObject__SetVisible(uVar2);
            uVar2 = *(undefined4 *)(extraout_EDX_05 + 4);
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
        }
      }
      iVar1 = piVar4[0x1c];
      if ((iVar1 != 0) &&
         (*(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffe | 0x400000,
         *(int *)(iVar1 + 0x18) == 5)) {
        uVar2 = *(undefined4 *)(iVar1 + 0x60);
        iVar1 = *(int *)(iVar1 + 0x5c);
        if (0 < iVar1) {
          do {
            FEObject__SetVisible(uVar2);
            uVar2 = *(undefined4 *)(extraout_EDX_06 + 4);
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
        }
      }
      iVar1 = param_1 + 1;
      piVar4 = piVar4 + 1;
      param_1 = iVar1;
    } while (iVar1 < *(int *)(iVar5 + 0xd0));
    if (3 < iVar1) goto LAB_00495c42;
  }
  puVar3 = (undefined4 *)(iVar5 + 0x50 + iVar1 * 4);
  iVar1 = 4 - iVar1;
  do {
    FEObject__SetInvisible(puVar3[-4]);
    FEObject__SetInvisible(*puVar3);
    FEObject__SetInvisible(puVar3[4]);
    FEObject__SetInvisible(puVar3[0xc]);
    FEObject__SetInvisible(puVar3[0x10]);
    FEObject__SetInvisible(puVar3[0x14]);
    FEObject__SetInvisible(puVar3[0x18]);
    FEObject__SetInvisible(puVar3[0x1c]);
    puVar3 = puVar3 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
LAB_00495c42:
  iVar1 = 0;
  if (*(int *)(iVar5 + 0xd0) < 1) {
    return;
  }
  puVar3 = (undefined4 *)(iVar5 + 0x70);
  do {
    FEObject__SetInvisible(*puVar3);
    iVar1 = iVar1 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar1 < *(int *)(iVar5 + 0xd0));
  return;
}


// ==== 0x495ce0 FUN_00495ce0

int * FUN_00495ce0(int *param_1)

{
  byte *pbVar1;
  int *piVar2;
  int in_EAX;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  char *pcVar9;
  int local_4;
  
  if (in_EAX == 0) {
    param_1[3] = 0;
    param_1[2] = 0;
    param_1[1] = 0;
    *param_1 = 0;
    return param_1;
  }
  puVar8 = &DAT_006c7a38;
  iVar5 = -1;
  uVar3 = 0x52;
  do {
    iVar5 = iVar5 * 0x21 + uVar3;
    pbVar1 = puVar8 + 1;
    uVar3 = (uint)*pbVar1;
    puVar8 = puVar8 + 1;
  } while (*pbVar1 != 0);
  piVar4 = *(int **)(in_EAX + 0x14);
  iVar7 = (int)*(short *)(in_EAX + 0x1c);
  piVar2 = piVar4;
  if (piVar4 != (int *)0x0) {
    for (; piVar2 < piVar4 + iVar7 * 2; piVar2 = piVar2 + 2) {
      if ((iVar5 == 0) || (*piVar2 == iVar5)) {
        if (piVar2 != (int *)0x0) {
          local_4 = piVar2[1];
          goto LAB_00495d42;
        }
        break;
      }
    }
  }
  local_4 = 0;
LAB_00495d42:
  pcVar9 = "GREEN";
  iVar5 = -1;
  uVar3 = 0x47;
  do {
    iVar5 = iVar5 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar9 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar9 = pcVar9 + 1;
  } while (*pbVar1 != 0);
  piVar2 = piVar4;
  if (piVar4 != (int *)0x0) {
    for (; piVar2 < piVar4 + iVar7 * 2; piVar2 = piVar2 + 2) {
      if ((iVar5 == 0) || (*piVar2 == iVar5)) {
        if (piVar2 != (int *)0x0) {
          iVar5 = piVar2[1];
          goto LAB_00495d85;
        }
        break;
      }
    }
  }
  iVar5 = 0;
LAB_00495d85:
  puVar8 = &DAT_006c7a28;
  iVar6 = -1;
  uVar3 = 0x42;
  do {
    iVar6 = iVar6 * 0x21 + uVar3;
    pbVar1 = puVar8 + 1;
    uVar3 = (uint)*pbVar1;
    puVar8 = puVar8 + 1;
  } while (*pbVar1 != 0);
  piVar2 = piVar4 + iVar7 * 2;
  if (piVar4 != (int *)0x0) {
    for (; piVar4 < piVar2; piVar4 = piVar4 + 2) {
      if ((iVar6 == 0) || (*piVar4 == iVar6)) {
        if (piVar4 != (int *)0x0) {
          iVar7 = piVar4[1];
          goto LAB_00495dc1;
        }
        break;
      }
    }
  }
  iVar7 = 0;
LAB_00495dc1:
  *param_1 = iVar7;
  param_1[1] = iVar5;
  param_1[2] = local_4;
  param_1[3] = 0xff;
  return param_1;
}


// ==== 0x495e20 FUN_00495e20

void FUN_00495e20(void)

{
  void *pvVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688d33;
  local_c = ExceptionList;
  if (DAT_00735ed8 == 0) {
    ExceptionList = &local_c;
    pvVar1 = _malloc(0x10);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      DAT_00735ed8 = tPreRaceScreenManager__tPreRaceScreenManager(pvVar1);
      ExceptionList = local_c;
      return;
    }
    DAT_00735ed8 = 0;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x495e90 FUN_00495e90

void FUN_00495e90(void)

{
  void *_Memory;
  
  _Memory = DAT_00735ed8;
  if (DAT_00735ed8 != (void *)0x0) {
    FUN_00494d60(DAT_00735ed8);
    _free(_Memory);
  }
  DAT_00735ed8 = (void *)0x0;
  return;
}


// ==== 0x495ec0 tPreRaceScreenManager::RequestStatsScreen

/* [canon] canon med (ghidra-canon+hopper) docs/re/canon.md */

void tPreRaceScreenManager__RequestStatsScreen(void)

{
  if ((((DAT_00735ed8 != 0) && (DAT_0078a345 == '\0')) && (DAT_007361a4 == 0)) &&
     ((DAT_0078a346 == '\0' && (DAT_007361a0 == 0)))) {
    *(undefined1 *)(DAT_00735ed8 + 1) = 1;
  }
  return;
}


// ==== 0x495f00 FUN_00495f00

void FUN_00495f00(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_EAX;
  int iVar2;
  undefined4 unaff_EDI;
  bool bVar3;
  
  if (((in_EAX == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      return;
    }
    iVar2 = FUN_004ef050(unaff_EDI);
  }
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x18) == 2)) {
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
    puVar1 = DAT_00735710;
    bVar3 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar2 + 0x5c) = param_1;
    if (bVar3) {
      (**(code **)*puVar1)(iVar2);
    }
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xfffffffd | 0x400000;
  }
  return;
}


// ==== 0x495f70 FUN_00495f70

void FUN_00495f70(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  undefined4 unaff_EDI;
  
  if (unaff_ESI != 0) {
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_00495faa;
    }
  }
  if (DAT_0073578c != 0) {
    uVar2 = FUN_004ef050(unaff_EDI);
    FEObject__SetInvisible(uVar2);
    return;
  }
  iVar1 = 0;
LAB_00495faa:
  FEObject__SetInvisible(iVar1);
  return;
}


// ==== 0x495fc0 FUN_00495fc0

void FUN_00495fc0(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  undefined4 unaff_EDI;
  
  if (unaff_ESI != 0) {
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_00495ffa;
    }
  }
  if (DAT_0073578c != 0) {
    uVar2 = FUN_004ef050(unaff_EDI);
    FEObject__SetVisible(uVar2);
    return;
  }
  iVar1 = 0;
LAB_00495ffa:
  FEObject__SetVisible(iVar1);
  return;
}


// ==== 0x496010 FUN_00496010

void FUN_00496010(undefined4 param_1)

{
  undefined4 local_8;
  undefined1 local_4 [4];
  
  FUN_004f6d10(local_4,&local_8);
  FUN_004f7000(param_1,local_8);
  return;
}


// ==== 0x496040 FUN_00496040

void FUN_00496040(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  undefined4 local_8;
  undefined1 local_4 [4];
  
  FUN_004f7350(local_4,&local_8);
  if (in_EAX != 0) {
    iVar1 = *(int *)(in_EAX + 0x18);
    iVar2 = *(int *)(in_EAX + 0x2c);
    if (((iVar1 == 1) || (iVar1 == 7)) || (iVar1 == 9)) {
      *(undefined4 *)(iVar2 + 0x38) = param_1;
      *(undefined4 *)(iVar2 + 0x3c) = local_8;
    }
    *(undefined4 *)(iVar2 + 0x3c) = local_8;
    *(undefined4 *)(iVar2 + 0x38) = param_1;
    *(uint *)(in_EAX + 0x1c) = *(uint *)(in_EAX + 0x1c) | 0x400000;
  }
  return;
}


// ==== 0x4960a0 FUN_004960a0

float10 FUN_004960a0(void)

{
  int iVar1;
  int unaff_ESI;
  float10 extraout_ST0;
  
  Float_Truncate(*(undefined4 *)(unaff_ESI + 0xc0));
  iVar1 = _ftol_nocw();
  return extraout_ST0 * (float10)iVar1;
}


// ==== 0x4960e0 PostRaceRewardList::_PostRaceRewardList

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void __fastcall PostRaceRewardList___PostRaceRewardList(undefined4 *param_1)

{
  int *piVar1;
  int *_Memory;
  int iVar2;
  int *piVar3;
  
  piVar1 = param_1 + 1;
  *param_1 = &PTR_FUN_006c75c8;
  _Memory = (int *)*piVar1;
  while (_Memory != piVar1) {
    iVar2 = *_Memory;
    piVar3 = (int *)_Memory[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(_Memory);
    _Memory = (int *)*piVar1;
  }
  return;
}


// ==== 0x496110 FUN_00496110

void * __thiscall FUN_00496110(void *param_1,byte param_2)

{
  PostRaceRewardList___PostRaceRewardList();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x496130 PostRaceRewardList::SetFlag46

/* [canon] hud med (ghidra-canon+hopper) docs/re/canon.md */

void __fastcall PostRaceRewardList__SetFlag46(int param_1)

{
  if (*(char *)(param_1 + 0x41) == '\0') {
    *(undefined1 *)(param_1 + 0x46) = 1;
  }
  return;
}


// ==== 0x496140 Screen_PostRaceMenu::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_PostRaceMenu__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688553;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0xb8);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_PostRaceMenu__Screen_PostRaceMenu(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4961a0 Screen_PostRaceMenu::Screen_PostRaceMenu

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_PostRaceMenu__Screen_PostRaceMenu(undefined4 *param_1,undefined4 param_2)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_PostRaceMenuScreen___PostRaceMenuScreen_006c7588;
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined1 *)((int)param_1 + 0x41) = 0;
  *(undefined1 *)((int)param_1 + 0x42) = 0;
  *(undefined1 *)((int)param_1 + 0x43) = 0;
  *(undefined1 *)(param_1 + 0x11) = 0;
  *(undefined1 *)((int)param_1 + 0x45) = 0;
  *(undefined1 *)((int)param_1 + 0x46) = 0;
  *(undefined1 *)((int)param_1 + 0x47) = 0;
  *(undefined1 *)(param_1 + 0x12) = 0;
  PostRaceMenuScreen__Setup(param_1);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x496210 PostRaceMenuScreen::_PostRaceMenuScreen

/* [canon] hud med (ghidra-canon+nfsug) docs/re/canon.md */

void * __thiscall PostRaceMenuScreen___PostRaceMenuScreen(void *param_1,byte param_2)

{
  PostRaceMenuScreen___PostRaceMenuScreen();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x496230 PostRaceMenuScreen::_PostRaceMenuScreen

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void __fastcall PostRaceMenuScreen___PostRaceMenuScreen(undefined4 *param_1)

{
  *param_1 = &PTR_PostRaceMenuScreen___PostRaceMenuScreen_006c7588;
  FUN_004f7b50();
  return;
}


// ==== 0x496240 PostRaceMenuScreen::Setup

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceMenuScreen__Setup(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  byte *pbVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  code **ppcVar11;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  code *local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  code *local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  code *local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  code *local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  code *local_48 [8];
  int local_28;
  int local_24;
  byte local_20;
  byte local_1f [31];
  
  local_28 = 1;
  local_24 = 6;
  do {
    bSPrintf_regdst(0x20,"Button%d",local_28);
    iVar8 = -1;
    pbVar5 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar5 + 1;
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      pbVar5 = pbVar5 + 1;
      bVar2 = *pbVar1;
    }
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049631c:
      if (DAT_0073578c == 0) {
LAB_00496332:
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar4 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
        if (DAT_0073578c != 0) {
          iVar7 = *(int *)(DAT_0073578c + 8);
          if ((iVar7 == 0) ||
             ((iVar4 = FUN_004fd1e0(iVar7 + 0xdc), iVar4 == 0 &&
              (iVar4 = FUN_004fd1e0(iVar7 + 0xec), iVar4 == 0)))) goto LAB_0049631c;
          goto LAB_0049630b;
        }
        goto LAB_00496332;
      }
LAB_0049630b:
      if ((iVar4 == 0) || (iVar4 = FUN_004ffb70(), iVar4 == 0)) goto LAB_0049631c;
    }
    FEObject__SetInvisible(iVar4);
    iVar8 = -1;
    pbVar5 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar5 + 1;
      pbVar5 = pbVar5 + 1;
      bVar2 = *pbVar1;
    }
    if (((DAT_0073578c != 0) && (iVar4 = FEPackageList__FindByName(&DAT_00746104), iVar4 != 0)) &&
       (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
      iVar7 = *(int *)(iVar4 + 0x88);
      iVar10 = 0;
      if (iVar7 != 0) {
        piVar6 = *(int **)(iVar4 + 0x84);
        do {
          if (*(int *)(*piVar6 + 0x10) == iVar8) {
            iVar10 = *piVar6;
          }
          piVar6 = piVar6 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        if (iVar10 != 0) {
          *(uint *)(iVar10 + 0x1c) = *(uint *)(iVar10 + 0x1c) | 0x4000000;
        }
      }
    }
    bSPrintf_regdst(0x20,"Button_%d",local_28);
    iVar8 = -1;
    pbVar5 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar5 + 1;
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      pbVar5 = pbVar5 + 1;
      bVar2 = *pbVar1;
    }
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049647c:
      if (DAT_0073578c == 0) {
LAB_00496492:
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar4 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
        if (DAT_0073578c != 0) {
          iVar7 = *(int *)(DAT_0073578c + 8);
          if ((iVar7 == 0) ||
             ((iVar4 = FUN_004fd1e0(iVar7 + 0xdc), iVar4 == 0 &&
              (iVar4 = FUN_004fd1e0(iVar7 + 0xec), iVar4 == 0)))) goto LAB_0049647c;
          goto LAB_0049646b;
        }
        goto LAB_00496492;
      }
LAB_0049646b:
      if ((iVar4 == 0) || (iVar4 = FUN_004ffb70(), iVar4 == 0)) goto LAB_0049647c;
    }
    FEObject__SetInvisible(iVar4);
    piVar6 = DAT_00777ccc;
    iVar8 = DAT_00777b4c;
    local_28 = local_28 + 1;
    local_24 = local_24 + -1;
  } while (local_24 != 0);
  switch(DAT_00777b4c) {
  case 1:
    uVar9 = 0x2e4350c6;
    if (DAT_00777ccc == (int *)0x0) {
LAB_00496658:
      local_68 = PostRaceMenuScreen__RestartRace;
      local_58 = (code *)0x0;
      local_a8 = 3;
      local_9c = 0x80833fc2;
      local_98 = 0;
      local_4c = 0xffffffff;
      local_a4 = uVar9;
    }
    else {
      cVar3 = Race__DidPlayerWin(DAT_00777ccc,0);
      if ((cVar3 != '\0') &&
         ((((piVar6[0x1629] == 2 || (piVar6[0x1629] == 3)) ||
           (cVar3 = FERaceEvent__HasMagazineReward(), cVar3 != '\0')) ||
          ((cVar3 = FUN_0051ba80(), cVar3 != '\0' && (iVar8 != 8)))))) {
        uVar9 = 0x3d82312b;
      }
      if (piVar6[0x1629] != 1) goto LAB_00496658;
      if (((piVar6 != (int *)0x0) && (cVar3 = (**(code **)(*piVar6 + 4))(), cVar3 != '\0')) &&
         ((DAT_00777ccc == (int *)0x0 || (cVar3 = FUN_005a2ba0(), cVar3 != '\0')))) {
        local_68 = PostRaceMenuScreen__RestartEvent;
        local_58 = PostRaceMenuScreen__RestartRace;
        local_a8 = 5;
        local_a4 = 0x5fca71b2;
        local_9c = 0x1269c0d9;
        local_98 = 0x4888e03e;
        local_94 = 0x1c8dfaf9;
        local_4c = 0;
        local_48[0] = PostRaceMenuScreen__ContinueEvent;
        local_48[3] = (code *)0x0;
        goto LAB_004966e7;
      }
      local_4c = 0;
      local_68 = PostRaceMenuScreen__RestartEvent;
      local_a8 = 4;
      local_9c = 0x1269c0d9;
      local_98 = 0x4888e03e;
      local_58 = PostRaceMenuScreen__RestartRace;
      local_a4 = uVar9;
    }
    local_48[0] = (code *)0x0;
    local_94 = 0;
    local_48[3] = (code *)0xffffffff;
LAB_004966e7:
    local_50 = 0;
    local_54 = 0;
    local_5c = 0;
    local_60 = 0;
    local_64 = 0;
    local_6c = 0;
    local_70 = 0;
    local_74 = 0;
    local_78 = PostRaceRewardList__SetFlag46;
    local_7c = 0;
    local_80 = 0;
    local_84 = 0;
    local_88 = PostRaceMenuScreen__Quit;
    local_8c = 0;
    local_a0 = 0x3b7f8ae;
    local_48[4] = (code *)0x0;
    local_48[1] = (code *)0x0;
    local_48[2] = (code *)0x0;
    local_48[5] = (code *)0x0;
    local_48[6] = (code *)0x0;
    local_48[7] = (code *)0x0;
    PostRaceMenuScreen__Setup(param_1,&local_a8);
    return;
  case 2:
  case 4:
    if ((DAT_00777ccc == (int *)0x0) || (DAT_00777ccc[0x1629] != 1)) {
      local_68 = PostRaceMenuScreen__RestartRace;
      local_58 = (code *)0x0;
      local_a8 = 3;
      local_9c = 0x80833fc2;
      local_98 = 0;
      local_4c = 0xffffffff;
LAB_00496896:
      local_48[0] = (code *)0x0;
      local_a4 = 0xbc92e0f8;
      local_94 = 0;
      local_48[3] = (code *)0xffffffff;
    }
    else {
      if ((DAT_00777ccc == (int *)0x0) ||
         (cVar3 = (**(code **)(*DAT_00777ccc + 4))(), cVar3 == '\0')) {
        local_4c = 0;
        local_68 = PostRaceMenuScreen__RestartEvent;
        local_a8 = 4;
        local_9c = 0x1269c0d9;
        local_98 = 0x4888e03e;
        local_58 = PostRaceMenuScreen__RestartRace;
        goto LAB_00496896;
      }
      local_68 = PostRaceMenuScreen__RestartEvent;
      local_4c = 0;
      local_58 = PostRaceMenuScreen__RestartRace;
      local_a8 = 5;
      local_a4 = 0x5fca71b2;
      local_9c = 0x1269c0d9;
      local_98 = 0x4888e03e;
      local_94 = 0x1c8dfaf9;
      local_48[0] = PostRaceMenuScreen__ContinueEvent;
      local_48[3] = (code *)0x0;
    }
    local_48[2] = (code *)0x0;
    local_5c = 0;
    local_48[1] = (code *)0x0;
    local_48[4] = (code *)0x0;
    local_48[5] = (code *)0x0;
    local_48[6] = (code *)0x0;
    local_48[7] = (code *)0x0;
    break;
  default:
    goto switchD_004964d3_caseD_3;
  case 8:
    local_90 = 0;
    local_a8 = 2;
    local_a4 = 0xe1ad6e1b;
    local_9c = 0;
    local_98 = 0;
    local_68 = (code *)0x0;
    local_5c = 0xffffffff;
    local_58 = (code *)0x0;
    local_4c = 0xffffffff;
    ppcVar11 = local_48;
    for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
      *ppcVar11 = (code *)0x0;
      ppcVar11 = ppcVar11 + 1;
    }
  }
  local_50 = 0;
  local_54 = 0;
  local_60 = 0;
  local_64 = 0;
  local_6c = 0;
  local_70 = 0;
  local_74 = 0;
  local_78 = PostRaceRewardList__SetFlag46;
  local_7c = 0;
  local_80 = 0;
  local_84 = 0;
  local_88 = PostRaceMenuScreen__Quit;
  local_8c = 0;
  local_a0 = 0x3b7f8ae;
  PostRaceMenuScreen__Setup(param_1,&local_a8);
switchD_004964d3_caseD_3:
  return;
}


// ==== 0x4969e0 PostRaceMenuScreen::Setup

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceMenuScreen__Setup(int param_1,int *param_2)

{
  byte *pbVar1;
  int iVar2;
  bool bVar3;
  byte bVar4;
  int iVar5;
  byte *pbVar6;
  int *piVar7;
  char *pcVar8;
  int extraout_EDX;
  int iVar9;
  undefined4 uVar10;
  int extraout_EDX_00;
  int iVar11;
  int local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  byte local_20;
  byte local_1f [31];
  
  if (0 < *param_2) {
    local_24 = (int *)(param_1 + 0x58);
    local_28 = param_2 + 8;
    local_30 = 1;
    local_2c = param_2;
    do {
      local_2c = local_2c + 1;
      bSPrintf_regdst(0x20,"Button%d",local_30);
      iVar11 = -1;
      pbVar6 = &local_20;
      bVar4 = local_20;
      while (bVar4 != 0) {
        if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
          bVar4 = bVar4 - 0x20;
        }
        pbVar1 = pbVar6 + 1;
        iVar11 = iVar11 * 0x21 + (uint)bVar4;
        pbVar6 = pbVar6 + 1;
        bVar4 = *pbVar1;
      }
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_00496ac4:
        if ((DAT_0073578c != 0) && (iVar5 = FUN_004ef050(iVar11), iVar5 != 0)) {
LAB_00496ade:
          *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
          if (*(int *)(iVar5 + 0x18) == 5) {
            uVar10 = *(undefined4 *)(iVar5 + 0x60);
            iVar11 = *(int *)(iVar5 + 0x5c);
            if (0 < iVar11) {
              do {
                FEObject__SetVisible(uVar10);
                uVar10 = *(undefined4 *)(extraout_EDX + 4);
                iVar11 = iVar11 + -1;
              } while (iVar11 != 0);
            }
          }
        }
      }
      else {
        iVar5 = FEPackageList__FindByName(&DAT_00746104);
        if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_00496ab3:
          if ((iVar5 == 0) || (iVar5 = FUN_004ffb70(), iVar5 == 0)) goto LAB_00496ac4;
          goto LAB_00496ade;
        }
        if (DAT_0073578c != 0) {
          iVar9 = *(int *)(DAT_0073578c + 8);
          if ((iVar9 == 0) ||
             ((iVar5 = FUN_004fd1e0(iVar9 + 0xdc), iVar5 == 0 &&
              (iVar5 = FUN_004fd1e0(iVar9 + 0xec), iVar5 == 0)))) goto LAB_00496ac4;
          goto LAB_00496ab3;
        }
      }
      iVar11 = -1;
      pbVar6 = &local_20;
      bVar4 = local_20;
      while (bVar4 != 0) {
        if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
          bVar4 = bVar4 - 0x20;
        }
        pbVar1 = pbVar6 + 1;
        iVar11 = iVar11 * 0x21 + (uint)bVar4;
        pbVar6 = pbVar6 + 1;
        bVar4 = *pbVar1;
      }
      if ((((DAT_0073578c != 0) && (iVar5 = FEPackageList__FindByName(&DAT_00746104), iVar5 != 0))
          && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) &&
         (iVar9 = *(int *)(iVar5 + 0x88), iVar9 != 0)) {
        piVar7 = *(int **)(iVar5 + 0x84);
        iVar5 = 0;
        do {
          if (*(int *)(*piVar7 + 0x10) == iVar11) {
            iVar5 = *piVar7;
          }
          piVar7 = piVar7 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        if (iVar5 != 0) {
          *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfbffffff;
        }
      }
      FUN_00416bb0(*local_2c);
      bSPrintf_regdst(0x20,"Button_%d",local_30);
      iVar11 = -1;
      pbVar6 = &local_20;
      bVar4 = local_20;
      while (bVar4 != 0) {
        if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
          bVar4 = bVar4 - 0x20;
        }
        iVar11 = iVar11 * 0x21 + (uint)bVar4;
        pbVar1 = pbVar6 + 1;
        pbVar6 = pbVar6 + 1;
        bVar4 = *pbVar1;
      }
      iVar5 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_00496c4e:
        if ((iVar5 != 0) && (iVar9 = FUN_004ef050(iVar11), iVar9 != 0)) {
LAB_00496c61:
          *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) & 0xfffffffe | 0x400000;
          if (*(int *)(iVar9 + 0x18) == 5) {
            uVar10 = *(undefined4 *)(iVar9 + 0x60);
            iVar11 = *(int *)(iVar9 + 0x5c);
            if (0 < iVar11) {
              do {
                FEObject__SetVisible(uVar10);
                uVar10 = *(undefined4 *)(extraout_EDX_00 + 4);
                iVar11 = iVar11 + -1;
              } while (iVar11 != 0);
            }
          }
        }
      }
      else {
        iVar9 = FEPackageList__FindByName(&DAT_00746104);
        iVar5 = DAT_0073578c;
        if ((iVar9 != 0) && (iVar9 = *(int *)(iVar9 + 0x18), iVar9 != 0)) {
LAB_00496c37:
          if ((iVar9 == 0) || (iVar9 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar9 == 0))
          goto LAB_00496c4e;
          goto LAB_00496c61;
        }
        if (DAT_0073578c != 0) {
          iVar2 = *(int *)(DAT_0073578c + 8);
          if ((iVar2 == 0) ||
             ((iVar9 = FUN_004fd1e0(iVar2 + 0xdc), iVar9 == 0 &&
              (iVar9 = FUN_004fd1e0(iVar2 + 0xec), iVar9 == 0)))) goto LAB_00496c4e;
          goto LAB_00496c37;
        }
      }
      *local_24 = *local_28;
      local_24[1] = local_28[1];
      local_24[2] = local_28[2];
      local_24[3] = local_28[3];
      local_28 = local_28 + 4;
      local_24 = local_24 + 4;
      bVar3 = local_30 < *param_2;
      local_30 = local_30 + 1;
    } while (bVar3);
  }
  if (3 < *param_2) {
    bSPrintf_regdst(0x20,"Init0%d",*param_2);
    pcVar8 = "TopBacking";
    iVar11 = -1;
    bVar4 = 0x54;
    do {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      iVar11 = iVar11 * 0x21 + (uint)bVar4;
      bVar4 = pcVar8[1];
      pcVar8 = pcVar8 + 1;
    } while (bVar4 != 0);
    if (((*(int *)(param_1 + 0xc) == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
       (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
      if (DAT_0073578c == 0) goto LAB_00496ddd;
      iVar5 = FUN_004ef050(iVar11);
    }
    if (iVar5 != 0) {
      iVar11 = -1;
      pbVar6 = &local_20;
      while (local_20 != 0) {
        if (('`' < (char)local_20) && ((char)local_20 < '{')) {
          local_20 = local_20 - 0x20;
        }
        iVar11 = iVar11 * 0x21 + (uint)local_20;
        pbVar1 = pbVar6 + 1;
        pbVar6 = pbVar6 + 1;
        local_20 = *pbVar1;
      }
      iVar9 = *(int *)(iVar5 + 0x4c);
      if (iVar9 != 0) {
        while (*(int *)(iVar9 + 0x30) != iVar11) {
          iVar9 = *(int *)(iVar9 + 4);
          if (iVar9 == 0) {
            *(int *)(param_1 + 0x4c) = *param_2;
            return;
          }
        }
        if (iVar9 != 0) {
          if (iVar9 != *(int *)(iVar5 + 0x54)) {
            *(int *)(iVar5 + 0x54) = iVar9;
            FUN_004ff030(iVar5);
            *(undefined4 *)(*(int *)(iVar5 + 0x54) + 0x10) = 0;
          }
          *(undefined4 *)(iVar9 + 0x10) = 0;
        }
      }
    }
  }
LAB_00496ddd:
  *(int *)(param_1 + 0x4c) = *param_2;
  return;
}


// ==== 0x496e00 PostRaceMenuScreen::Quit

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void __fastcall PostRaceMenuScreen__Quit(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = DAT_00777ccc;
  if (*(char *)(param_1 + 0x41) != '\0') {
    return;
  }
  uStack_8 = 0;
  uStack_4 = 0;
  uVar3 = 0x79dee3e5;
  if (DAT_00777b4c != 1) {
    if (((DAT_00777cc8 == 4) && (DAT_00777ccc != 0)) &&
       (cVar2 = Race__DidPlayerWin(DAT_00777ccc,0), cVar2 == '\0')) {
      uVar3 = 0x6108e9f;
    }
    goto LAB_00496ea9;
  }
  if ((DAT_00777ccc == 0) || (*(int *)(DAT_00777ccc + 0x58a4) != 1)) {
LAB_00496e5a:
    uVar3 = 0xfa1fe73b;
  }
  else {
    cVar2 = Race__DidPlayerWin(DAT_00777ccc,0);
    uVar3 = 0xa1048ab;
    if (cVar2 != '\0') goto LAB_00496e5a;
  }
  if (((iVar1 != 0) && (cVar2 = Race__DidPlayerWin(iVar1,0), cVar2 != '\0')) &&
     ((*(int *)(iVar1 + 0x58a4) == 2 || (*(int *)(iVar1 + 0x58a4) == 3)))) {
    uVar3 = 0x91e8b718;
  }
LAB_00496ea9:
  uStack_1c = 0x7e9ccc8f;
  uStack_20 = 0x639;
  uStack_14 = 0;
  uStack_18 = 0x541389e5;
  uStack_10 = 1;
  uStack_c = 0xb8a7c6cd;
  uStack_24 = uVar3;
  FUN_004dc6e0(&uStack_24,"MU_PostRaceConfirm.fng",*(undefined4 *)(param_1 + 0xc));
  return;
}


// ==== 0x496f00 PostRaceMenuScreen::DoQuitRace

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceMenuScreen__DoQuitRace(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  float10 extraout_ST0;
  
  if ((DAT_00777b4c != 4) && (iVar4 = 0, 0 < DAT_0078a320)) {
    piVar6 = &DAT_00758ad4;
    do {
      iVar2 = 0;
      if (0 < DAT_007787b0) {
        piVar3 = &DAT_00777cd4;
        do {
          if (*piVar3 == (&DAT_0078a410)[iVar4]) {
            puVar5 = &DAT_00777cd0 + iVar2 * 0x57;
            goto LAB_00496f5d;
          }
          iVar2 = iVar2 + 1;
          piVar3 = piVar3 + 0x57;
        } while (iVar2 < DAT_007787b0);
      }
      puVar5 = (undefined4 *)0x0;
LAB_00496f5d:
      Float_Truncate(puVar5[0x30]);
      iVar2 = _ftol_nocw();
      if (((float10)0.0 < (float10)iVar2 * extraout_ST0) || (DAT_00735ec0 != '\0')) {
        Float_Truncate(puVar5[0x30]);
        _ftol_nocw();
        iVar2 = _ftol_nocw();
        *piVar6 = *piVar6 + iVar2;
        if (*piVar6 < 0) {
          *piVar6 = 0;
        }
        ThresholdTable_MarkReached(piVar6 + -0x84,*piVar6);
      }
      iVar4 = iVar4 + 1;
      piVar6 = piVar6 + 0x3e51;
    } while (iVar4 < DAT_0078a320);
  }
  DAT_00735790 = cFrontendDatabase__CalculateFirstFrontendScreenToSeeAfterQuitRace(&DAT_00748f70);
  FUN_004dfdc0();
  DAT_00778898 = 1;
  if (DAT_00777ccc != (int *)0x0) {
    (**(code **)(*DAT_00777ccc + 0x14))();
    piVar6 = DAT_00777ccc;
    if (DAT_00777b4c == 1) {
      cVar1 = Race__DidPlayerWin(DAT_00777ccc,1);
      if (cVar1 != '\0') {
        Career__WinEvent(piVar6[0x1628]);
        return;
      }
      Career__QuitEvent();
      return;
    }
    if (((DAT_00777b4c == 2) || (DAT_00777b4c == 4)) && (DAT_00777cc8 == 4)) {
      if (DAT_00777ccc != (int *)0x0) {
        (**(code **)*DAT_00777ccc)(1);
      }
      DAT_00777ccc = (int *)0x0;
    }
  }
  return;
}


// ==== 0x4970f0 PostRaceMenuScreen::EnterFrontendAfterQuit

/* [canon] hud low (ghidra-canon) docs/re/canon.md */

void PostRaceMenuScreen__EnterFrontendAfterQuit(void)

{
  DAT_00735ed4 = 0;
  FUN_00421c00(DAT_007361f0,10,0);
  return;
}


// ==== 0x497110 PostRaceMenuScreen::RestartRace

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void __fastcall PostRaceMenuScreen__RestartRace(int param_1)

{
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(char *)(param_1 + 0x41) == '\0') {
    uStack_8 = 0;
    uStack_4 = 0;
    uStack_14 = 0;
    uStack_24 = 0xb6583410;
    uStack_1c = 0xe1a57d51;
    uStack_20 = 0x639;
    uStack_18 = 0x541389e5;
    uStack_10 = 1;
    uStack_c = 0xb8a7c6cd;
    FUN_004dc6e0(&uStack_24,"MU_PostRaceConfirm.fng",*(undefined4 *)(param_1 + 0xc));
  }
  return;
}


// ==== 0x497180 PostRaceMenuScreen::RestartEvent

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void __fastcall PostRaceMenuScreen__RestartEvent(int param_1)

{
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(char *)(param_1 + 0x41) == '\0') {
    uStack_8 = 0;
    uStack_4 = 0;
    uStack_14 = 0;
    uStack_24 = 0x5a1cd15d;
    uStack_1c = 0x36e77d12;
    uStack_20 = 0x639;
    uStack_18 = 0x541389e5;
    uStack_10 = 1;
    uStack_c = 0xb8a7c6cd;
    FUN_004dc6e0(&uStack_24,"MU_PostRaceConfirm.fng",*(undefined4 *)(param_1 + 0xc));
  }
  return;
}


// ==== 0x4971f0 PostRaceMenuScreen::ContinueEvent

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void __fastcall PostRaceMenuScreen__ContinueEvent(int param_1)

{
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(char *)(param_1 + 0x41) == '\0') {
    uStack_8 = 0;
    uStack_4 = 0;
    uStack_14 = 0;
    uStack_24 = 0x5ddb911d;
    uStack_1c = 0x64bf64d2;
    uStack_20 = 0x639;
    uStack_18 = 0x541389e5;
    uStack_10 = 1;
    uStack_c = 0xb8a7c6cd;
    FUN_004dc6e0(&uStack_24,"MU_PostRaceConfirm.fng",*(undefined4 *)(param_1 + 0xc));
  }
  return;
}


// ==== 0x497260 PostRaceMenuScreen::DoRestartRace

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceMenuScreen__DoRestartRace(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  float10 extraout_ST0;
  
  DAT_00735ed4 = 0;
  DAT_00778898 = 2;
  if (DAT_00777ccc != (int *)0x0) {
    (**(code **)(*DAT_00777ccc + 0xc))();
  }
  if ((DAT_00777b4c != 4) && (iVar3 = 0, 0 < DAT_0078a320)) {
    piVar5 = &DAT_00758ad4;
    do {
      iVar1 = 0;
      if (0 < DAT_007787b0) {
        piVar2 = &DAT_00777cd4;
        do {
          if (*piVar2 == (&DAT_0078a410)[iVar3]) {
            puVar4 = &DAT_00777cd0 + iVar1 * 0x57;
            goto LAB_004972dd;
          }
          iVar1 = iVar1 + 1;
          piVar2 = piVar2 + 0x57;
        } while (iVar1 < DAT_007787b0);
      }
      puVar4 = (undefined4 *)0x0;
LAB_004972dd:
      Float_Truncate(puVar4[0x30]);
      iVar1 = _ftol_nocw();
      if (((float10)0.0 < (float10)iVar1 * extraout_ST0) || (DAT_00735ec0 != '\0')) {
        Float_Truncate(puVar4[0x30]);
        _ftol_nocw();
        iVar1 = _ftol_nocw();
        *piVar5 = *piVar5 + iVar1;
        if (*piVar5 < 0) {
          *piVar5 = 0;
        }
        ThresholdTable_MarkReached(piVar5 + -0x84,*piVar5);
      }
      iVar3 = iVar3 + 1;
      piVar5 = piVar5 + 0x3e51;
    } while (iVar3 < DAT_0078a320);
  }
  FUN_00421c00(DAT_007361f0,8,0);
  return;
}


// ==== 0x4973d0 PostRaceMenuScreen::DoRestartEvent

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceMenuScreen__DoRestartEvent(void)

{
  DAT_00735ed4 = 0;
  DAT_00778898 = 3;
  if (DAT_00777ccc != (int *)0x0) {
    (**(code **)(*DAT_00777ccc + 0x10))();
    cFrontendDatabase__NotifyChangeToNextRace();
  }
  FUN_00421c00(DAT_007361f0,9,0);
  return;
}


// ==== 0x497410 PostRaceMenuScreen::DoNextRaceInEvent

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceMenuScreen__DoNextRaceInEvent(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  float10 extraout_ST0;
  
  DAT_00735ed4 = 0;
  if ((DAT_00777b4c != 4) && (iVar3 = 0, 0 < DAT_0078a320)) {
    piVar5 = &DAT_00758ad4;
    do {
      iVar1 = 0;
      if (0 < DAT_007787b0) {
        piVar2 = &DAT_00777cd4;
        do {
          if (*piVar2 == (&DAT_0078a410)[iVar3]) {
            puVar4 = &DAT_00777cd0 + iVar1 * 0x57;
            goto LAB_0049746d;
          }
          iVar1 = iVar1 + 1;
          piVar2 = piVar2 + 0x57;
        } while (iVar1 < DAT_007787b0);
      }
      puVar4 = (undefined4 *)0x0;
LAB_0049746d:
      Float_Truncate(puVar4[0x30]);
      iVar1 = _ftol_nocw();
      if (((float10)0.0 < (float10)iVar1 * extraout_ST0) || (DAT_00735ec0 != '\0')) {
        Float_Truncate(puVar4[0x30]);
        _ftol_nocw();
        iVar1 = _ftol_nocw();
        *piVar5 = *piVar5 + iVar1;
        if (*piVar5 < 0) {
          *piVar5 = 0;
        }
        ThresholdTable_MarkReached(piVar5 + -0x84,*piVar5);
      }
      iVar3 = iVar3 + 1;
      piVar5 = piVar5 + 0x3e51;
    } while (iVar3 < DAT_0078a320);
  }
  DAT_00778898 = 0;
  if (DAT_00777ccc != (int *)0x0) {
    (**(code **)(*DAT_00777ccc + 0x18))();
    cFrontendDatabase__NotifyChangeToNextRace();
  }
  FUN_00421c00(DAT_007361f0,9,0);
  return;
}


// ==== 0x497590 PostRaceResults::NextScreenIsNotGiveth

/* [canon] canon med (ghidra-canon+hopper) docs/re/canon.md */

undefined4 PostRaceResults__NextScreenIsNotGiveth(void)

{
  int iVar1;
  
  iVar1 = bStrICmp();
  if (iVar1 != 0) {
    iVar1 = bStrICmp();
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// ==== 0x4975c0 PostRaceMenuScreen::NotificationMessage

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall
PostRaceMenuScreen__NotificationMessage
          (int param_1,uint param_2,int param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  
  if (*(char *)(param_1 + 0x40) != '\0') {
    if (param_2 == 0x12347770) {
      bVar3 = DAT_00735e4c != '\0';
      *(undefined1 *)(param_1 + 0x40) = 0;
      if (bVar3) {
        *(undefined1 *)(param_1 + 0x48) = 1;
        return;
      }
      DAT_00735ed4 = 0;
      FUN_00421c00(DAT_007361f0,10,0);
      return;
    }
    if (param_2 == 0x12347780) {
      DAT_006fb988 = 1;
      FEngQueuePackagePop("DemoDisc_Marketing.fng");
      DAT_00735ed4 = 0;
      FUN_00421c00(DAT_007361f0,10,0);
      return;
    }
  }
  if (param_2 < 0x7e9ccc90) {
    if (param_2 == 0x7e9ccc8f) {
      *(undefined1 *)(param_1 + 0x42) = 1;
      *(undefined4 *)(param_1 + 0x50) = 0;
      return;
    }
    if (param_2 < 0x36e77d13) {
      if (param_2 == 0x36e77d12) {
        *(undefined1 *)(param_1 + 0x45) = 1;
        return;
      }
      if (param_2 == 0xc407210) {
        switch(*(undefined4 *)(param_3 + 0x10)) {
        case 0xb8a7c6cc:
          (**(code **)(param_1 + 0x58))();
          return;
        case 0xb8a7c6cd:
          (**(code **)(param_1 + 0x68))();
          return;
        case 0xb8a7c6ce:
          (**(code **)(param_1 + 0x78))();
          return;
        case 0xb8a7c6cf:
          (**(code **)(param_1 + 0x88))();
          return;
        case 0xb8a7c6d0:
          (**(code **)(param_1 + 0x98))();
          return;
        }
      }
      else if (param_2 == 0x35f8620b) {
        bSPrintf_regdst(0x20,"Button%d",*(undefined4 *)(param_1 + 0x4c));
        FEng__HashName();
        FEngSetCurrentButton(*(undefined4 *)(param_1 + 0xc));
        return;
      }
    }
    else if (param_2 == 0x64bf64d2) {
      *(undefined1 *)(param_1 + 0x44) = 1;
      return;
    }
  }
  else if (param_2 == 0x911ab364) {
    *(undefined1 *)(param_1 + 0x41) = 1;
  }
  else if (param_2 == 0xc98356ba) {
    if (((*(char *)(param_1 + 0x40) == '\0') || (*(char *)(param_1 + 0x42) != '\0')) &&
       (cVar1 = FEngIsPackagePushed(), cVar1 == '\0')) {
      FEManager__PushPackageChecked(0x32,0);
    }
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar2 == 0) || (*(int *)(iVar2 + 0x18) == 0)) &&
       ((cVar1 = FEngIsPackagePushed(), cVar1 == '\0' &&
        ((cVar1 = FEngIsPackagePushed(), cVar1 == '\0' && (*(int *)(param_5 + 0x1c) == 0)))))) {
      *(undefined4 *)(param_5 + 0x1c) = 0xff;
    }
    if (*(char *)(param_1 + 0x42) == '\0') {
      if (*(char *)(param_1 + 0x43) == '\0') {
        if (*(char *)(param_1 + 0x44) == '\0') {
          if (*(char *)(param_1 + 0x45) == '\0') {
            if (*(char *)(param_1 + 0x46) == '\0') {
              if (*(char *)(param_1 + 0x41) != '\0') {
                if (*(char *)(param_1 + 0x47) == '\0') goto LAB_0049798c;
                cVar1 = FUN_004f6c80("FadeOut");
                if (cVar1 == '\0') {
                  cPostRaceScreenManager__ChangeToPrevScreen();
                  return;
                }
              }
            }
            else {
              if (*(char *)(param_1 + 0x47) == '\0') goto LAB_0049798c;
              cVar1 = FUN_004f6c80("FadeOut");
              if (cVar1 == '\0') {
                FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
                return;
              }
            }
          }
          else {
            if (*(char *)(param_1 + 0x47) == '\0') goto LAB_0049798c;
            cVar1 = FUN_004f6c80("FadeOut");
            if (cVar1 == '\0') {
              PostRaceMenuScreen__DoRestartEvent(param_1);
              return;
            }
          }
        }
        else {
          if (*(char *)(param_1 + 0x47) == '\0') goto LAB_0049798c;
          cVar1 = FUN_004f6c80("FadeOut");
          if (cVar1 == '\0') {
            PostRaceMenuScreen__DoNextRaceInEvent(param_1);
            return;
          }
        }
      }
      else {
        if (*(char *)(param_1 + 0x47) == '\0') goto LAB_0049798c;
        cVar1 = FUN_004f6c80("FadeOut");
        if (cVar1 == '\0') {
          PostRaceMenuScreen__DoRestartRace(param_1);
          return;
        }
      }
    }
    else {
      if (*(char *)(param_1 + 0x47) == '\0') {
LAB_0049798c:
        *(undefined1 *)(param_1 + 0x47) = 1;
        FUN_004f6c30("FadeOut",1);
        return;
      }
      cVar1 = FUN_004f6c80("FadeOut");
      if (cVar1 == '\0') {
        *(undefined1 *)(param_1 + 0x42) = 0;
        *(undefined1 *)(param_1 + 0x40) = 1;
        if (*(char *)(param_1 + 0x48) == '\0') {
          PostRaceMenuScreen__DoQuitRace(param_1);
          *(undefined1 *)(param_1 + 0x48) = 1;
        }
        cVar1 = PostRaceResults__NextScreenIsNotGiveth();
        if (cVar1 == '\0') {
          *(undefined1 *)(param_1 + 0x40) = 0;
          PostRaceMenuScreen__EnterFrontendAfterQuit(param_1);
          return;
        }
        FUN_004c96f0(0x12347770,2);
        return;
      }
    }
  }
  else if (param_2 == 0xe1a57d51) {
    *(undefined1 *)(param_1 + 0x43) = 1;
    return;
  }
  return;
}


// ==== 0x497a00 PostRaceStatsScreen::SetupRepWonLoss

/* [canon] hud med (ghidra-canon) docs/re/canon.md */

void __fastcall PostRaceStatsScreen__SetupRepWonLoss(int param_1)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 in_EAX;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  uVar3 = FEng__HashName();
  if (((((param_1 == 0) || (iVar4 = FEngFindPackage(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) &&
      ((DAT_0073578c == 0 || (iVar4 = FUN_004ef050(uVar3), iVar4 == 0)))) ||
     (*(int *)(iVar4 + 0x18) != 2)) {
    iVar4 = 0;
  }
  uVar3 = FEng__HashName();
  if (((((param_1 == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
       (iVar5 = FUN_004ffb70(), iVar5 == 0)) &&
      ((DAT_0073578c == 0 || (iVar5 = FUN_004ef050(uVar3), iVar5 == 0)))) ||
     (*(int *)(iVar5 + 0x18) != 2)) {
    iVar5 = 0;
  }
  FEObject__SetInvisible(iVar4);
  FEObject__SetInvisible(iVar5);
  cVar2 = FUN_0043a2e0();
  if (cVar2 != '\0') {
    cVar2 = Obj_GetByte19();
    if (cVar2 != '\0') {
      FEObject__SetVisible(iVar4);
      FEObject__SetVisible(iVar5);
      Race__GetPlayer(in_EAX);
      iVar4 = FUN_00647b70();
      iVar6 = FUN_0043d8c0(in_EAX,0);
      iVar6 = iVar6 - iVar4;
      iVar4 = iVar6;
      if (iVar6 < 0) {
        iVar4 = -iVar6;
      }
      FEObject__SetFormattedText(&DAT_006ca778,iVar4);
      if (iVar6 < 1) {
        if (iVar6 != 0) {
          FEString__SetLabelHash();
          return;
        }
        FEString__SetLabelHash();
        FEObject__SetInvisible(iVar5);
        return;
      }
      FEString__SetLabelHash();
      return;
    }
    if (iVar4 != 0) {
      *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
      puVar1 = DAT_00735710;
      bVar7 = DAT_00735710 != (undefined4 *)0x0;
      *(undefined4 *)(iVar4 + 0x5c) = 0xf4ca33b4;
      if (bVar7) {
        (**(code **)*puVar1)(iVar4);
      }
      *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffd | 0x400000;
    }
    FEObject__SetVisible(iVar4);
  }
  return;
}


// ==== 0x497ba0 Screen_PostRaceResults::NotifySoundMessage

/* [canon] canon high (ghidra-canon+nfsug) docs/re/canon.md */

int Screen_PostRaceResults__NotifySoundMessage(void)

{
  int in_stack_00000014;
  
  if ((in_stack_00000014 == 6) &&
     (((DAT_00777ccc == 0 || (*(int *)(DAT_00777ccc + 0x58a4) != 1)) && (DAT_00735ed4 == '\0')))) {
switchD_00497bce_default:
    return 0;
  }
  switch(in_stack_00000014) {
  case 1:
  case 2:
  case 3:
  case 4:
    goto switchD_00497bce_default;
  default:
    return in_stack_00000014;
  }
}


// ==== 0x497bf0 Screen_PostRaceResults::Create

/* [canon] canon med (capstone) docs/re/gameflow.md */

undefined4 Screen_PostRaceResults__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688513;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x44);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_PostRaceResults__Screen_PostRaceResults(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x497c50 Screen_PostRaceResults::Screen_PostRaceResults

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_PostRaceResults__Screen_PostRaceResults(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_PostRaceResultsScreen___PostRaceResultsScreen_006c75b8;
  *(undefined1 *)((int)param_1 + 0x42) = 0;
  cVar2 = FUN_0043a2e0();
  if (cVar2 == '\0') {
    iVar3 = 4;
  }
  else {
    iVar3 = DAT_0078a328 + DAT_0078a32c + DAT_0078a324 + DAT_0078a320;
  }
  if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
    PostRaceResultsScreen__SetupRacers(param_1,4);
  }
  else {
    PostRaceResultsScreen__SetupRacers(param_1,4,iVar3);
  }
  piVar1 = DAT_00777ccc;
  if (DAT_00777b4c == 1) {
    if ((DAT_00777ccc != (int *)0x0) && (DAT_00777ccc[0x1629] == 1)) {
joined_r0x00497d69:
      if (DAT_00735ed4 != '\0') {
        if (DAT_00735ed4 == '\x03') {
          DAT_00735ed4 = '\x02';
          cVar2 = (**(code **)(*DAT_00777ccc + 4))();
          if (cVar2 != '\0') {
            DAT_00735ed4 = DAT_00735ed4 + -1;
          }
        }
        if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
          iVar3 = DAT_0078a32c + DAT_0078a328 + DAT_0078a324 + DAT_0078a320;
        }
        if (DAT_00735ed4 == '\x01') {
          PostRaceResultsScreen__SetupTourneyPoints(param_1,4,iVar3,piVar1);
        }
        else if (DAT_00735ed4 == '\x02') {
          PostRaceResultsScreen__SetupTourneyPoints(param_1,4,iVar3,piVar1);
        }
        goto LAB_00497df5;
      }
    }
  }
  else if (DAT_00777cc8 == 4) goto joined_r0x00497d69;
  if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
    PostRaceResultsScreen__SetupRaceTimes
              (param_1,4,DAT_0078a328 + DAT_0078a32c + DAT_0078a324 + DAT_0078a320);
  }
  else {
    PostRaceResultsScreen__SetupRaceTimes(param_1,4,iVar3);
  }
LAB_00497df5:
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined1 *)((int)param_1 + 0x41) = 0;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x497e20 PostRaceResultsScreen::_PostRaceResultsScreen

/* [canon] hud med (ghidra-canon+nfsug) docs/re/canon.md */

void * __thiscall PostRaceResultsScreen___PostRaceResultsScreen(void *param_1,byte param_2)

{
  PostRaceResultsScreen___PostRaceResultsScreen(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x497e40 PostRaceResultsScreen::_PostRaceResultsScreen

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceResultsScreen___PostRaceResultsScreen(undefined4 *param_1)

{
  int *piVar1;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = __CxxFrameHandler_wrapper;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_PostRaceResultsScreen___PostRaceResultsScreen_006c75b8;
  local_4 = 0;
  if ((*(int *)(DAT_007356a8 + 0x104) != 0) &&
     (piVar1 = *(int **)(*(int *)(DAT_007356a8 + 0x104) + 0x24), piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0xa0))();
  }
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x497eb0 PostRaceResultsScreen::SetupRacers

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceResultsScreen__SetupRacers(int param_1,int param_2)

{
  byte *pbVar1;
  undefined4 *puVar2;
  char cVar3;
  byte bVar4;
  int in_EAX;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  int iVar11;
  bool bVar12;
  undefined4 *local_a8;
  int local_a4;
  int local_a0;
  byte local_9c;
  byte local_9b [31];
  int local_7c;
  int local_78;
  undefined4 local_74;
  byte local_70;
  byte local_6f [31];
  undefined1 local_50 [16];
  byte local_40;
  byte local_3f [63];
  
  local_a0 = 0;
  iVar9 = DAT_0073578c;
  iVar11 = local_7c;
  if (0 < in_EAX) {
    local_a4 = 1;
    local_a8 = &DAT_00777cd0;
    local_7c = in_EAX;
    do {
      iVar9 = 0;
      if (0 < *(int *)(DAT_007361f8 + 0x18)) {
        piVar5 = (int *)(DAT_007361f8 + 0x28);
        do {
          iVar11 = *piVar5;
          if ((int)*(short *)(iVar11 + 10) == local_a8[1]) goto LAB_00497f20;
          iVar9 = iVar9 + 1;
          piVar5 = piVar5 + 1;
        } while (iVar9 < *(int *)(DAT_007361f8 + 0x18));
      }
      iVar11 = 0;
LAB_00497f20:
      local_74 = *(undefined4 *)(iVar11 + 0x10);
      iVar9 = *(int *)(iVar11 + 0x14);
      local_78 = iVar11;
      bSPrintf_regdst(0x20,"Pos%d",local_a4);
      FEngPrintf(&PTR_FUN_006c7968,*local_a8);
      bSPrintf_regdst(0x20,"Name%d",local_a4);
      if ((*(int *)(*(int *)(iVar11 + 0x14) + 4) == 1) &&
         (*(char *)(*(int *)(iVar11 + 0x14) + 0x734) == '\0')) {
        iVar11 = *(int *)(iVar11 + 0x18);
        cVar3 = FUN_0043a2e0();
        if (cVar3 == '\0') {
          iVar11 = iVar11 + 0x34;
        }
        else {
          iVar11 = DAT_0077b244 + 0x19;
        }
      }
      else {
        cVar3 = FUN_0043a2e0();
        if (cVar3 == '\0') {
          iVar11 = iVar9 + 0x73c;
        }
        else {
          iVar11 = Race__GetPlayer(local_a8[1]);
          iVar11 = iVar11 + 0x19;
        }
      }
      FEngPrintf(&DAT_006cc568,iVar11);
      bSPrintf_regdst(0x20,"Rep_%d",local_a4);
      if ((DAT_00777b4c == 1) && (*(int *)(iVar9 + 4) == 1)) {
        iVar9 = -1;
        pbVar10 = &local_70;
        bVar4 = local_70;
        while (bVar4 != 0) {
          if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
            bVar4 = bVar4 - 0x20;
          }
          pbVar1 = pbVar10 + 1;
          iVar9 = iVar9 * 0x21 + (uint)bVar4;
          pbVar10 = pbVar10 + 1;
          bVar4 = *pbVar1;
        }
        if (((*(int *)(param_1 + 0xc) == 0) || (iVar11 = FEngFindPackage(), iVar11 == 0)) ||
           (iVar11 = FUN_004ffb70(), iVar11 == 0)) {
          if (DAT_0073578c != 0) {
            uVar6 = FUN_004ef050(iVar9);
            FEObject__SetVisible(uVar6);
            goto LAB_004980f4;
          }
          iVar11 = 0;
        }
        FEObject__SetVisible(iVar11);
      }
      else {
        iVar9 = -1;
        pbVar10 = &local_70;
        bVar4 = local_70;
        while (bVar4 != 0) {
          if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
            bVar4 = bVar4 - 0x20;
          }
          iVar9 = iVar9 * 0x21 + (uint)bVar4;
          pbVar1 = pbVar10 + 1;
          pbVar10 = pbVar10 + 1;
          bVar4 = *pbVar1;
        }
        if (((*(int *)(param_1 + 0xc) == 0) || (iVar11 = FEngFindPackage(), iVar11 == 0)) ||
           (iVar11 = FUN_004ffb70(), iVar11 == 0)) {
          if (DAT_0073578c == 0) {
            iVar11 = 0;
          }
          else {
            iVar11 = FUN_004ef050(iVar9);
          }
        }
        FEObject__SetInvisible(iVar11);
      }
LAB_004980f4:
      bSPrintf_regdst(0x20,"CarColor_%d",local_a4);
      iVar9 = -1;
      pbVar10 = &local_40;
      bVar4 = local_40;
      while (bVar4 != 0) {
        if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
          bVar4 = bVar4 - 0x20;
        }
        pbVar1 = pbVar10 + 1;
        iVar9 = iVar9 * 0x21 + (uint)bVar4;
        pbVar10 = pbVar10 + 1;
        bVar4 = *pbVar1;
      }
      iVar11 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_004981ba:
        if (iVar11 != 0) {
          iVar7 = FUN_004ef050(iVar9);
LAB_004981c9:
          if ((iVar7 != 0) && (FUN_00495ce0(local_50), *(int *)(iVar7 + 0x18) < 0x100)) {
            cVar3 = FEColor_NearlyEqual();
            if (cVar3 == '\0') {
              *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | 0x400000;
            }
            FUN_004ff2f0(iVar7,0,0);
          }
        }
      }
      else {
        iVar7 = FEPackageList__FindByName(&DAT_00746104);
        iVar11 = DAT_0073578c;
        if ((iVar7 != 0) && (iVar7 = *(int *)(iVar7 + 0x18), iVar7 != 0)) {
LAB_0049819a:
          if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar11 = DAT_0073578c, iVar7 == 0))
          goto LAB_004981ba;
          goto LAB_004981c9;
        }
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_004981ba;
          goto LAB_0049819a;
        }
      }
      bSPrintf_regdst(0x20,"CarModel_%d",local_a4);
      uVar6 = GetCarModelNameHash();
      FUN_00416bb0(uVar6);
      local_a8 = local_a8 + 0x57;
      local_a4 = local_a4 + 1;
      local_7c = local_7c + -1;
      iVar9 = DAT_0073578c;
      local_a0 = in_EAX;
      iVar11 = 0;
    } while (local_7c != 0);
  }
  while (local_7c = iVar11, local_a0 < param_2) {
    local_a0 = local_a0 + 1;
    bSPrintf_regdst(0x20,"Name%d",local_a0);
    iVar9 = -1;
    pbVar10 = &local_9c;
    bVar4 = local_9c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      pbVar1 = pbVar10 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar4;
      pbVar10 = pbVar10 + 1;
      bVar4 = *pbVar1;
    }
    iVar11 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_00498343:
      if (iVar11 == 0) {
LAB_00498354:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar9);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar11 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_00498343;
          goto LAB_0049832c;
        }
        goto LAB_00498354;
      }
LAB_0049832c:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar11 = DAT_0073578c, iVar7 == 0))
      goto LAB_00498343;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"RacerColor_%d",local_a0);
    iVar9 = -1;
    pbVar10 = &local_9c;
    bVar4 = local_9c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      pbVar1 = pbVar10 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar4;
      pbVar10 = pbVar10 + 1;
      bVar4 = *pbVar1;
    }
    iVar11 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_00498413:
      if (iVar11 == 0) {
LAB_00498424:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar9);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar11 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_00498413;
          goto LAB_004983fc;
        }
        goto LAB_00498424;
      }
LAB_004983fc:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar11 = DAT_0073578c, iVar7 == 0))
      goto LAB_00498413;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"CarColor_%d",local_a0);
    iVar9 = -1;
    pbVar10 = &local_9c;
    bVar4 = local_9c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      pbVar1 = pbVar10 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar4;
      pbVar10 = pbVar10 + 1;
      bVar4 = *pbVar1;
    }
    iVar11 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004984e3:
      if (iVar11 == 0) {
LAB_004984f4:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar9);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar11 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_004984e3;
          goto LAB_004984cc;
        }
        goto LAB_004984f4;
      }
LAB_004984cc:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar11 = DAT_0073578c, iVar7 == 0))
      goto LAB_004984e3;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"Pos%d",local_a0);
    iVar9 = -1;
    pbVar10 = &local_9c;
    bVar4 = local_9c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      pbVar1 = pbVar10 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar4;
      pbVar10 = pbVar10 + 1;
      bVar4 = *pbVar1;
    }
    iVar11 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004985b3:
      if (iVar11 == 0) {
LAB_004985c4:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar9);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar11 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_004985b3;
          goto LAB_0049859c;
        }
        goto LAB_004985c4;
      }
LAB_0049859c:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar11 = DAT_0073578c, iVar7 == 0))
      goto LAB_004985b3;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"Position_%d",local_a0);
    iVar9 = -1;
    pbVar10 = &local_9c;
    bVar4 = local_9c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      pbVar1 = pbVar10 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar4;
      pbVar10 = pbVar10 + 1;
      bVar4 = *pbVar1;
    }
    iVar11 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_00498683:
      if (iVar11 == 0) {
LAB_00498694:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar9);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar11 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_00498683;
          goto LAB_0049866c;
        }
        goto LAB_00498694;
      }
LAB_0049866c:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar11 = DAT_0073578c, iVar7 == 0))
      goto LAB_00498683;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"CarModel_%d",local_a0);
    iVar9 = -1;
    pbVar10 = &local_9c;
    bVar4 = local_9c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      pbVar1 = pbVar10 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar4;
      pbVar10 = pbVar10 + 1;
      bVar4 = *pbVar1;
    }
    iVar11 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_00498753:
      if (iVar11 == 0) {
LAB_00498764:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar9);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar11 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_00498753;
          goto LAB_0049873c;
        }
        goto LAB_00498764;
      }
LAB_0049873c:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar11 = DAT_0073578c, iVar7 == 0))
      goto LAB_00498753;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"Rep_%d",local_a0);
    iVar9 = -1;
    pbVar10 = &local_9c;
    bVar4 = local_9c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      pbVar1 = pbVar10 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar4;
      pbVar10 = pbVar10 + 1;
      bVar4 = *pbVar1;
    }
    iVar11 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_00498823:
      if (iVar11 == 0) {
LAB_00498834:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar9);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar11 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_00498823;
          goto LAB_0049880c;
        }
        goto LAB_00498834;
      }
LAB_0049880c:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar11 = DAT_0073578c, iVar7 == 0))
      goto LAB_00498823;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"Lead%d",local_a0);
    iVar9 = -1;
    pbVar10 = &local_9c;
    bVar4 = local_9c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      pbVar1 = pbVar10 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar4;
      pbVar10 = pbVar10 + 1;
      bVar4 = *pbVar1;
    }
    iVar11 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004988f3:
      if (iVar11 == 0) {
LAB_00498904:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar9);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar11 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_004988f3;
          goto LAB_004988dc;
        }
        goto LAB_00498904;
      }
LAB_004988dc:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar11 = DAT_0073578c, iVar7 == 0))
      goto LAB_004988f3;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"Back_%d",local_a0);
    iVar9 = -1;
    pbVar10 = &local_9c;
    bVar4 = local_9c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      pbVar1 = pbVar10 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar4;
      pbVar10 = pbVar10 + 1;
      bVar4 = *pbVar1;
    }
    iVar11 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004989c3:
      if (iVar11 == 0) {
LAB_004989d4:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar9);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar11 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_004989c3;
          goto LAB_004989ac;
        }
        goto LAB_004989d4;
      }
LAB_004989ac:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar11 = DAT_0073578c, iVar7 == 0))
      goto LAB_004989c3;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"Corner_%d",local_a0);
    iVar9 = -1;
    pbVar10 = &local_9c;
    bVar4 = local_9c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      pbVar1 = pbVar10 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar4;
      pbVar10 = pbVar10 + 1;
      bVar4 = *pbVar1;
    }
    iVar11 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_00498a93:
      if (iVar11 == 0) {
LAB_00498aa4:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar9);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar11 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_00498a93;
          goto LAB_00498a7c;
        }
        goto LAB_00498aa4;
      }
LAB_00498a7c:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar11 = DAT_0073578c, iVar7 == 0))
      goto LAB_00498a93;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"PointEarned_%d",local_a0);
    iVar9 = -1;
    pbVar10 = &local_9c;
    bVar4 = local_9c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      pbVar1 = pbVar10 + 1;
      iVar9 = iVar9 * 0x21 + (uint)bVar4;
      pbVar10 = pbVar10 + 1;
      bVar4 = *pbVar1;
    }
    iVar11 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_00498b63:
      if (iVar11 == 0) {
LAB_00498b74:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar9);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar11 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_00498b63;
          goto LAB_00498b4c;
        }
        goto LAB_00498b74;
      }
LAB_00498b4c:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar11 = DAT_0073578c, iVar7 == 0))
      goto LAB_00498b63;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"TotalPoints_%d",local_a0);
    iVar11 = -1;
    pbVar10 = &local_9c;
    bVar4 = local_9c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      pbVar1 = pbVar10 + 1;
      iVar11 = iVar11 * 0x21 + (uint)bVar4;
      pbVar10 = pbVar10 + 1;
      bVar4 = *pbVar1;
    }
    iVar7 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_00498c3e:
      iVar9 = 0;
      if (iVar7 == 0) {
LAB_00498c55:
        iVar8 = 0;
      }
      else {
        iVar8 = FUN_004ef050(iVar11);
        iVar9 = DAT_0073578c;
      }
    }
    else {
      iVar9 = FEPackageList__FindByName(&DAT_00746104);
      iVar7 = DAT_0073578c;
      if ((iVar9 == 0) || (iVar9 = *(int *)(iVar9 + 0x18), iVar9 == 0)) {
        iVar9 = DAT_0073578c;
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar9 = FUN_004fd1e0(iVar8 + 0xdc), iVar9 == 0 &&
              (iVar9 = FUN_004fd1e0(iVar8 + 0xec), iVar9 == 0)))) goto LAB_00498c3e;
          goto LAB_00498c1f;
        }
        goto LAB_00498c55;
      }
LAB_00498c1f:
      if ((iVar9 == 0) ||
         (iVar8 = FUN_004ffb70(), iVar9 = DAT_0073578c, iVar7 = DAT_0073578c, iVar8 == 0))
      goto LAB_00498c3e;
    }
    FEObject__SetInvisible(iVar8);
    iVar11 = local_7c;
  }
  if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
    FUN_00495f00(0x70445b0c);
    return;
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    iVar11 = FEPackageList__FindByName(&DAT_00746104);
    iVar9 = DAT_0073578c;
    if ((iVar11 == 0) || (iVar11 = *(int *)(iVar11 + 0x18), iVar11 == 0)) {
      if (DAT_0073578c == 0) {
        return;
      }
      iVar7 = *(int *)(DAT_0073578c + 8);
      if ((iVar7 == 0) ||
         ((iVar11 = FUN_004fd1e0(iVar7 + 0xdc), iVar11 == 0 &&
          (iVar11 = FUN_004fd1e0(iVar7 + 0xec), iVar11 == 0)))) goto LAB_00498d0f;
    }
    if ((iVar11 != 0) && (iVar11 = FUN_004ffb70(), iVar9 = DAT_0073578c, iVar11 != 0))
    goto LAB_00498d22;
  }
LAB_00498d0f:
  if (iVar9 == 0) {
    return;
  }
  iVar11 = FUN_004ef050(0x6e6c46c);
LAB_00498d22:
  if ((iVar11 != 0) && (*(int *)(iVar11 + 0x18) == 2)) {
    *(uint *)(iVar11 + 0x1c) = *(uint *)(iVar11 + 0x1c) | 0x400000;
    puVar2 = DAT_00735710;
    bVar12 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar11 + 0x5c) = 0x4f6b0d68;
    if (bVar12) {
      (**(code **)*puVar2)(iVar11);
    }
    *(uint *)(iVar11 + 0x1c) = *(uint *)(iVar11 + 0x1c) & 0xfffffffd | 0x400000;
    return;
  }
  return;
}


// ==== 0x498d90 PostRaceResultsScreen::SetupRacers

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceResultsScreen__SetupRacers(int param_1,int param_2,int param_3)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  int local_64;
  byte local_60;
  byte local_5f [95];
  
  iVar11 = 0;
  iVar4 = DAT_0073578c;
  if (0 < param_3) {
    iVar12 = 1;
    iVar11 = 0;
    do {
      bSPrintf_regdst(0x20,"Pos%d",iVar12);
      FEngPrintf(&PTR_FUN_006c7968,iVar12);
      local_64 = 0;
      cVar2 = FUN_0043a2e0();
      if (cVar2 == '\0') {
        puVar5 = DAT_0077b198;
        if ((undefined4 **)DAT_0077b198 != &DAT_0077b198) {
          iVar4 = 0;
          do {
            if (iVar4 == iVar11) break;
            puVar5 = (undefined4 *)*puVar5;
            iVar4 = iVar4 + 1;
          } while ((undefined4 **)puVar5 != &DAT_0077b198);
        }
        local_64 = puVar5[6];
        puVar5 = DAT_0077b198;
        for (iVar4 = 0; ((undefined4 **)puVar5 != &DAT_0077b198 && (iVar4 != iVar11));
            iVar4 = iVar4 + 1) {
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        iVar4 = 0;
        if (0 < DAT_007787b0) {
          piVar9 = &DAT_00777cd0;
          do {
            if (*piVar9 == iVar12) {
              puVar5 = &DAT_00777cd0 + iVar4 * 0x57;
              goto LAB_00498e18;
            }
            iVar4 = iVar4 + 1;
            piVar9 = piVar9 + 0x57;
          } while (iVar4 < DAT_007787b0);
        }
        puVar5 = (undefined4 *)0x0;
LAB_00498e18:
        iVar4 = Race__GetPlayer(puVar5[1]);
        if (iVar4 != 0) {
          local_64 = iVar4 + 0x19;
          Race__FindRacerById();
        }
      }
      bSPrintf_regdst(0x20,"Name%d",iVar12);
      FEngPrintf(&DAT_006cc568,local_64);
      bSPrintf_regdst(0x20,"CarModel_%d",iVar12);
      uVar6 = GetCarModelNameHash();
      FUN_00416bb0(uVar6);
      iVar11 = iVar11 + 1;
      iVar12 = iVar12 + 1;
      iVar4 = DAT_0073578c;
    } while (iVar11 < param_3);
  }
  while (iVar11 < param_2) {
    iVar11 = iVar11 + 1;
    bSPrintf_regdst(0x20,"Name%d",iVar11);
    iVar4 = -1;
    pbVar10 = &local_60;
    bVar3 = local_60;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar10 + 1;
      pbVar10 = pbVar10 + 1;
      bVar3 = *pbVar1;
    }
    iVar12 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_00498fc8:
      if (iVar12 == 0) {
LAB_00498fd9:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar4);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar12 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_00498fc8;
          goto LAB_00498fb1;
        }
        goto LAB_00498fd9;
      }
LAB_00498fb1:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar12 = DAT_0073578c, iVar7 == 0))
      goto LAB_00498fc8;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"RacerColor_%d",iVar11);
    iVar4 = -1;
    pbVar10 = &local_60;
    bVar3 = local_60;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar10 + 1;
      pbVar10 = pbVar10 + 1;
      bVar3 = *pbVar1;
    }
    iVar12 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_00499098:
      if (iVar12 == 0) {
LAB_004990a9:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar4);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar12 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_00499098;
          goto LAB_00499081;
        }
        goto LAB_004990a9;
      }
LAB_00499081:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar12 = DAT_0073578c, iVar7 == 0))
      goto LAB_00499098;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"CarColor_%d",iVar11);
    iVar4 = -1;
    pbVar10 = &local_60;
    bVar3 = local_60;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar10 + 1;
      pbVar10 = pbVar10 + 1;
      bVar3 = *pbVar1;
    }
    iVar12 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_00499168:
      if (iVar12 == 0) {
LAB_00499179:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar4);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar12 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_00499168;
          goto LAB_00499151;
        }
        goto LAB_00499179;
      }
LAB_00499151:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar12 = DAT_0073578c, iVar7 == 0))
      goto LAB_00499168;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"Pos%d",iVar11);
    iVar4 = -1;
    pbVar10 = &local_60;
    bVar3 = local_60;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar10 + 1;
      pbVar10 = pbVar10 + 1;
      bVar3 = *pbVar1;
    }
    iVar12 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_00499238:
      if (iVar12 == 0) {
LAB_00499249:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar4);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar12 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_00499238;
          goto LAB_00499221;
        }
        goto LAB_00499249;
      }
LAB_00499221:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar12 = DAT_0073578c, iVar7 == 0))
      goto LAB_00499238;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"Position_%d",iVar11);
    iVar4 = -1;
    pbVar10 = &local_60;
    bVar3 = local_60;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar10 + 1;
      pbVar10 = pbVar10 + 1;
      bVar3 = *pbVar1;
    }
    iVar12 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_00499308:
      if (iVar12 == 0) {
LAB_00499319:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar4);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar12 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_00499308;
          goto LAB_004992f1;
        }
        goto LAB_00499319;
      }
LAB_004992f1:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar12 = DAT_0073578c, iVar7 == 0))
      goto LAB_00499308;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"CarModel_%d",iVar11);
    iVar4 = -1;
    pbVar10 = &local_60;
    bVar3 = local_60;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar10 + 1;
      pbVar10 = pbVar10 + 1;
      bVar3 = *pbVar1;
    }
    iVar12 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004993d8:
      if (iVar12 == 0) {
LAB_004993e9:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar4);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar12 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_004993d8;
          goto LAB_004993c1;
        }
        goto LAB_004993e9;
      }
LAB_004993c1:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar12 = DAT_0073578c, iVar7 == 0))
      goto LAB_004993d8;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"Rep_%d",iVar11);
    iVar4 = -1;
    pbVar10 = &local_60;
    bVar3 = local_60;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar10 + 1;
      pbVar10 = pbVar10 + 1;
      bVar3 = *pbVar1;
    }
    iVar12 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004994a8:
      if (iVar12 == 0) {
LAB_004994b9:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar4);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar12 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_004994a8;
          goto LAB_00499491;
        }
        goto LAB_004994b9;
      }
LAB_00499491:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar12 = DAT_0073578c, iVar7 == 0))
      goto LAB_004994a8;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"Lead%d",iVar11);
    iVar4 = -1;
    pbVar10 = &local_60;
    bVar3 = local_60;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar10 + 1;
      pbVar10 = pbVar10 + 1;
      bVar3 = *pbVar1;
    }
    iVar12 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_00499578:
      if (iVar12 == 0) {
LAB_00499589:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar4);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar12 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_00499578;
          goto LAB_00499561;
        }
        goto LAB_00499589;
      }
LAB_00499561:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar12 = DAT_0073578c, iVar7 == 0))
      goto LAB_00499578;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"Back_%d",iVar11);
    iVar4 = -1;
    pbVar10 = &local_60;
    bVar3 = local_60;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar10 + 1;
      pbVar10 = pbVar10 + 1;
      bVar3 = *pbVar1;
    }
    iVar12 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_00499648:
      if (iVar12 == 0) {
LAB_00499659:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar4);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar12 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_00499648;
          goto LAB_00499631;
        }
        goto LAB_00499659;
      }
LAB_00499631:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar12 = DAT_0073578c, iVar7 == 0))
      goto LAB_00499648;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"Corner_%d",iVar11);
    iVar4 = -1;
    pbVar10 = &local_60;
    bVar3 = local_60;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar10 + 1;
      pbVar10 = pbVar10 + 1;
      bVar3 = *pbVar1;
    }
    iVar12 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_00499718:
      if (iVar12 == 0) {
LAB_00499729:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar4);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar12 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_00499718;
          goto LAB_00499701;
        }
        goto LAB_00499729;
      }
LAB_00499701:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar12 = DAT_0073578c, iVar7 == 0))
      goto LAB_00499718;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"Rep_%d",iVar11);
    iVar4 = -1;
    pbVar10 = &local_60;
    bVar3 = local_60;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar10 + 1;
      pbVar10 = pbVar10 + 1;
      bVar3 = *pbVar1;
    }
    iVar12 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004997e8:
      if (iVar12 == 0) {
LAB_004997f9:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar4);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar12 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_004997e8;
          goto LAB_004997d1;
        }
        goto LAB_004997f9;
      }
LAB_004997d1:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar12 = DAT_0073578c, iVar7 == 0))
      goto LAB_004997e8;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"PointEarned_%d",iVar11);
    iVar4 = -1;
    pbVar10 = &local_60;
    bVar3 = local_60;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar4 = iVar4 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar10 + 1;
      pbVar10 = pbVar10 + 1;
      bVar3 = *pbVar1;
    }
    iVar12 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004998b8:
      if (iVar12 == 0) {
LAB_004998c9:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar4);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar12 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar8 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar8 + 0xec), iVar7 == 0)))) goto LAB_004998b8;
          goto LAB_004998a1;
        }
        goto LAB_004998c9;
      }
LAB_004998a1:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar12 = DAT_0073578c, iVar7 == 0))
      goto LAB_004998b8;
    }
    FEObject__SetInvisible(iVar7);
    bSPrintf_regdst(0x20,"TotalPoints_%d",iVar11);
    iVar12 = -1;
    pbVar10 = &local_60;
    bVar3 = local_60;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar12 = iVar12 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar10 + 1;
      pbVar10 = pbVar10 + 1;
      bVar3 = *pbVar1;
    }
    iVar7 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_00499990:
      iVar4 = 0;
      if (iVar7 == 0) {
LAB_004999a7:
        iVar8 = 0;
      }
      else {
        iVar8 = FUN_004ef050(iVar12);
        iVar4 = DAT_0073578c;
      }
    }
    else {
      iVar4 = FEPackageList__FindByName(&DAT_00746104);
      iVar7 = DAT_0073578c;
      if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
        iVar4 = DAT_0073578c;
        if (DAT_0073578c != 0) {
          iVar8 = *(int *)(DAT_0073578c + 8);
          if ((iVar8 == 0) ||
             ((iVar4 = FUN_004fd1e0(iVar8 + 0xdc), iVar4 == 0 &&
              (iVar4 = FUN_004fd1e0(iVar8 + 0xec), iVar4 == 0)))) goto LAB_00499990;
          goto LAB_00499971;
        }
        goto LAB_004999a7;
      }
LAB_00499971:
      if ((iVar4 == 0) ||
         (iVar8 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar7 = DAT_0073578c, iVar8 == 0))
      goto LAB_00499990;
    }
    FEObject__SetInvisible(iVar8);
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    iVar11 = FEPackageList__FindByName(&DAT_00746104);
    iVar4 = DAT_0073578c;
    if ((iVar11 == 0) || (iVar11 = *(int *)(iVar11 + 0x18), iVar11 == 0)) {
      if (DAT_0073578c == 0) {
        return;
      }
      iVar12 = *(int *)(DAT_0073578c + 8);
      if ((iVar12 == 0) ||
         ((iVar11 = FUN_004fd1e0(iVar12 + 0xdc), iVar11 == 0 &&
          (iVar11 = FUN_004fd1e0(iVar12 + 0xec), iVar11 == 0)))) goto LAB_00499a47;
    }
    if ((iVar11 != 0) && (iVar11 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar11 != 0))
    goto LAB_00499a5a;
  }
LAB_00499a47:
  if (iVar4 == 0) {
    return;
  }
  iVar11 = FUN_004ef050(0x6e6c46c);
LAB_00499a5a:
  if ((iVar11 != 0) && (*(int *)(iVar11 + 0x18) == 2)) {
    *(uint *)(iVar11 + 0x1c) = *(uint *)(iVar11 + 0x1c) | 0x400000;
    puVar5 = DAT_00735710;
    bVar13 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar11 + 0x5c) = 0x70445b0c;
    if (bVar13) {
      (**(code **)*puVar5)(iVar11);
    }
    *(uint *)(iVar11 + 0x1c) = *(uint *)(iVar11 + 0x1c) & 0xfffffffd | 0x400000;
  }
  return;
}


// ==== 0x499aa0 PostRaceResultsScreen::SetupRaceTimes

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceResultsScreen__SetupRaceTimes(int param_1,undefined4 param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int *piVar8;
  int extraout_EDX_02;
  int iVar9;
  int iVar10;
  char *pcVar11;
  undefined4 uVar12;
  int local_50;
  byte local_40;
  byte local_3f [31];
  undefined1 local_20 [32];
  
  iVar3 = DAT_00777cdc;
  local_50 = 0;
  if (0 < param_3) {
    do {
      iVar5 = local_50 + 1;
      bSPrintf_regdst(0x20,"PointEarned_%d",iVar5);
      iVar9 = -1;
      pbVar7 = &local_40;
      bVar4 = local_40;
      while (bVar4 != 0) {
        if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
          bVar4 = bVar4 - 0x20;
        }
        pbVar1 = pbVar7 + 1;
        iVar9 = iVar9 * 0x21 + (uint)bVar4;
        pbVar7 = pbVar7 + 1;
        bVar4 = *pbVar1;
      }
      iVar10 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_00499b7a:
        if (iVar10 == 0) {
LAB_00499b8b:
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_004ef050(iVar9);
        }
      }
      else {
        iVar6 = FEPackageList__FindByName(&DAT_00746104);
        iVar10 = DAT_0073578c;
        if ((iVar6 == 0) || (iVar6 = *(int *)(iVar6 + 0x18), iVar6 == 0)) {
          if (DAT_0073578c != 0) {
            iVar2 = *(int *)(DAT_0073578c + 8);
            if ((iVar2 == 0) ||
               ((iVar6 = FUN_004fd1e0(iVar2 + 0xdc), iVar6 == 0 &&
                (iVar6 = FUN_004fd1e0(iVar2 + 0xec), iVar6 == 0)))) goto LAB_00499b7a;
            goto LAB_00499b63;
          }
          goto LAB_00499b8b;
        }
LAB_00499b63:
        if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar10 = DAT_0073578c, iVar6 == 0))
        goto LAB_00499b7a;
      }
      FEObject__SetInvisible(iVar6);
      bSPrintf_regdst(0x20,"TotalPoints_%d",iVar5);
      iVar9 = -1;
      pbVar7 = &local_40;
      bVar4 = local_40;
      while (bVar4 != 0) {
        if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
          bVar4 = bVar4 - 0x20;
        }
        pbVar1 = pbVar7 + 1;
        iVar9 = iVar9 * 0x21 + (uint)bVar4;
        pbVar7 = pbVar7 + 1;
        bVar4 = *pbVar1;
      }
      iVar10 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_00499c44:
        if (iVar10 == 0) {
LAB_00499c55:
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_004ef050(iVar9);
        }
      }
      else {
        iVar6 = FEPackageList__FindByName(&DAT_00746104);
        iVar10 = DAT_0073578c;
        if ((iVar6 == 0) || (iVar6 = *(int *)(iVar6 + 0x18), iVar6 == 0)) {
          if (DAT_0073578c != 0) {
            iVar2 = *(int *)(DAT_0073578c + 8);
            if ((iVar2 == 0) ||
               ((iVar6 = FUN_004fd1e0(iVar2 + 0xdc), iVar6 == 0 &&
                (iVar6 = FUN_004fd1e0(iVar2 + 0xec), iVar6 == 0)))) goto LAB_00499c44;
            goto LAB_00499c2d;
          }
          goto LAB_00499c55;
        }
LAB_00499c2d:
        if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar10 = DAT_0073578c, iVar6 == 0))
        goto LAB_00499c44;
      }
      FEObject__SetInvisible(iVar6);
      bSPrintf_regdst(0x20,"PointEarned_%d",iVar5);
      iVar9 = -1;
      pbVar7 = &local_40;
      bVar4 = local_40;
      while (bVar4 != 0) {
        if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
          bVar4 = bVar4 - 0x20;
        }
        pbVar1 = pbVar7 + 1;
        iVar9 = iVar9 * 0x21 + (uint)bVar4;
        pbVar7 = pbVar7 + 1;
        bVar4 = *pbVar1;
      }
      iVar10 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_00499d13:
        if (iVar10 == 0) {
LAB_00499d24:
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_004ef050(iVar9);
        }
      }
      else {
        iVar6 = FEPackageList__FindByName(&DAT_00746104);
        iVar10 = DAT_0073578c;
        if ((iVar6 == 0) || (iVar6 = *(int *)(iVar6 + 0x18), iVar6 == 0)) {
          if (DAT_0073578c != 0) {
            iVar2 = *(int *)(DAT_0073578c + 8);
            if ((iVar2 == 0) ||
               ((iVar6 = FUN_004fd1e0(iVar2 + 0xdc), iVar6 == 0 &&
                (iVar6 = FUN_004fd1e0(iVar2 + 0xec), iVar6 == 0)))) goto LAB_00499d13;
            goto LAB_00499cfc;
          }
          goto LAB_00499d24;
        }
LAB_00499cfc:
        if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar10 = DAT_0073578c, iVar6 == 0))
        goto LAB_00499d13;
      }
      FEObject__SetInvisible(iVar6);
      bSPrintf_regdst(0x20,"TotalPoints_%d",iVar5);
      iVar9 = -1;
      pbVar7 = &local_40;
      bVar4 = local_40;
      while (bVar4 != 0) {
        if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
          bVar4 = bVar4 - 0x20;
        }
        pbVar1 = pbVar7 + 1;
        iVar9 = iVar9 * 0x21 + (uint)bVar4;
        pbVar7 = pbVar7 + 1;
        bVar4 = *pbVar1;
      }
      iVar10 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_00499de3:
        if (iVar10 == 0) {
LAB_00499df4:
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_004ef050(iVar9);
        }
      }
      else {
        iVar6 = FEPackageList__FindByName(&DAT_00746104);
        iVar10 = DAT_0073578c;
        if ((iVar6 == 0) || (iVar6 = *(int *)(iVar6 + 0x18), iVar6 == 0)) {
          if (DAT_0073578c != 0) {
            iVar2 = *(int *)(DAT_0073578c + 8);
            if ((iVar2 == 0) ||
               ((iVar6 = FUN_004fd1e0(iVar2 + 0xdc), iVar6 == 0 &&
                (iVar6 = FUN_004fd1e0(iVar2 + 0xec), iVar6 == 0)))) goto LAB_00499de3;
            goto LAB_00499dcc;
          }
          goto LAB_00499df4;
        }
LAB_00499dcc:
        if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar10 = DAT_0073578c, iVar6 == 0))
        goto LAB_00499de3;
      }
      FEObject__SetInvisible(iVar6);
      bSPrintf_regdst(0x20,"Lead%d",iVar5);
      iVar9 = -1;
      pbVar7 = &local_40;
      bVar4 = local_40;
      while (bVar4 != 0) {
        if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
          bVar4 = bVar4 - 0x20;
        }
        pbVar1 = pbVar7 + 1;
        iVar9 = iVar9 * 0x21 + (uint)bVar4;
        pbVar7 = pbVar7 + 1;
        bVar4 = *pbVar1;
      }
      iVar10 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_00499eb7:
        if ((iVar10 != 0) && (iVar6 = FUN_004ef050(iVar9), iVar6 != 0)) {
LAB_00499eca:
          *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) & 0xfffffffe | 0x400000;
          if (*(int *)(iVar6 + 0x18) == 5) {
            uVar12 = *(undefined4 *)(iVar6 + 0x60);
            iVar9 = *(int *)(iVar6 + 0x5c);
            if (0 < iVar9) {
              do {
                FEObject__SetVisible(uVar12);
                uVar12 = *(undefined4 *)(extraout_EDX + 4);
                iVar9 = iVar9 + -1;
              } while (iVar9 != 0);
            }
          }
        }
      }
      else {
        iVar6 = FEPackageList__FindByName(&DAT_00746104);
        iVar10 = DAT_0073578c;
        if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_00499ea0:
          if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar10 = DAT_0073578c, iVar6 == 0))
          goto LAB_00499eb7;
          goto LAB_00499eca;
        }
        if (DAT_0073578c != 0) {
          iVar2 = *(int *)(DAT_0073578c + 8);
          if ((iVar2 == 0) ||
             ((iVar6 = FUN_004fd1e0(iVar2 + 0xdc), iVar6 == 0 &&
              (iVar6 = FUN_004fd1e0(iVar2 + 0xec), iVar6 == 0)))) goto LAB_00499eb7;
          goto LAB_00499ea0;
        }
      }
      bSPrintf_regdst(0x20,"Time%d",iVar5);
      iVar9 = -1;
      pbVar7 = &local_40;
      bVar4 = local_40;
      while (bVar4 != 0) {
        if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
          bVar4 = bVar4 - 0x20;
        }
        pbVar1 = pbVar7 + 1;
        iVar9 = iVar9 * 0x21 + (uint)bVar4;
        pbVar7 = pbVar7 + 1;
        bVar4 = *pbVar1;
      }
      iVar10 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_00499fb7:
        if ((iVar10 != 0) && (iVar6 = FUN_004ef050(iVar9), iVar6 != 0)) {
LAB_00499fca:
          *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) & 0xfffffffe | 0x400000;
          if (*(int *)(iVar6 + 0x18) == 5) {
            uVar12 = *(undefined4 *)(iVar6 + 0x60);
            iVar9 = *(int *)(iVar6 + 0x5c);
            if (0 < iVar9) {
              do {
                FEObject__SetVisible(uVar12);
                uVar12 = *(undefined4 *)(extraout_EDX_00 + 4);
                iVar9 = iVar9 + -1;
              } while (iVar9 != 0);
            }
          }
        }
      }
      else {
        iVar6 = FEPackageList__FindByName(&DAT_00746104);
        iVar10 = DAT_0073578c;
        if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_00499fa0:
          if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar10 = DAT_0073578c, iVar6 == 0))
          goto LAB_00499fb7;
          goto LAB_00499fca;
        }
        if (DAT_0073578c != 0) {
          iVar2 = *(int *)(DAT_0073578c + 8);
          if ((iVar2 == 0) ||
             ((iVar6 = FUN_004fd1e0(iVar2 + 0xdc), iVar6 == 0 &&
              (iVar6 = FUN_004fd1e0(iVar2 + 0xec), iVar6 == 0)))) goto LAB_00499fb7;
          goto LAB_00499fa0;
        }
      }
      bSPrintf_regdst(0x20,"BestLap_%d",iVar5);
      iVar9 = -1;
      pbVar7 = &local_40;
      bVar4 = local_40;
      while (bVar4 != 0) {
        if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
          bVar4 = bVar4 - 0x20;
        }
        pbVar1 = pbVar7 + 1;
        iVar9 = iVar9 * 0x21 + (uint)bVar4;
        pbVar7 = pbVar7 + 1;
        bVar4 = *pbVar1;
      }
      iVar10 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049a0ba:
        if ((iVar10 != 0) && (iVar6 = FUN_004ef050(iVar9), iVar6 != 0)) {
LAB_0049a0cd:
          *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) & 0xfffffffe | 0x400000;
          if (*(int *)(iVar6 + 0x18) == 5) {
            uVar12 = *(undefined4 *)(iVar6 + 0x60);
            iVar9 = *(int *)(iVar6 + 0x5c);
            if (0 < iVar9) {
              do {
                FEObject__SetVisible(uVar12);
                uVar12 = *(undefined4 *)(extraout_EDX_01 + 4);
                iVar9 = iVar9 + -1;
              } while (iVar9 != 0);
            }
          }
        }
      }
      else {
        iVar6 = FEPackageList__FindByName(&DAT_00746104);
        iVar10 = DAT_0073578c;
        if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_0049a0a3:
          if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar10 = DAT_0073578c, iVar6 == 0))
          goto LAB_0049a0ba;
          goto LAB_0049a0cd;
        }
        if (DAT_0073578c != 0) {
          iVar2 = *(int *)(DAT_0073578c + 8);
          if ((iVar2 == 0) ||
             ((iVar6 = FUN_004fd1e0(iVar2 + 0xdc), iVar6 == 0 &&
              (iVar6 = FUN_004fd1e0(iVar2 + 0xec), iVar6 == 0)))) goto LAB_0049a0ba;
          goto LAB_0049a0a3;
        }
      }
      iVar9 = 0;
      if (0 < *(int *)(DAT_007361f8 + 0x18)) {
        piVar8 = (int *)(DAT_007361f8 + 0x28);
        do {
          if ((int)*(short *)(*piVar8 + 10) == (&DAT_00777cd4)[local_50 * 0x57]) break;
          iVar9 = iVar9 + 1;
          piVar8 = piVar8 + 1;
        } while (iVar9 < *(int *)(DAT_007361f8 + 0x18));
      }
      iVar9 = (&DAT_00777cdc)[local_50 * 0x57];
      bSPrintf_regdst(0x20,"BestLap_%d",iVar5);
      if (DAT_00777b4c == 1) {
        iVar10 = -1;
        pbVar7 = &local_40;
        bVar4 = local_40;
        while (bVar4 != 0) {
          if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
            bVar4 = bVar4 - 0x20;
          }
          iVar10 = iVar10 * 0x21 + (uint)bVar4;
          pbVar1 = pbVar7 + 1;
          pbVar7 = pbVar7 + 1;
          bVar4 = *pbVar1;
        }
        if (((*(int *)(param_1 + 0xc) == 0) || (iVar6 = FEngFindPackage(), iVar6 == 0)) ||
           (iVar6 = FUN_004ffb70(), iVar6 == 0)) {
          if (DAT_0073578c == 0) {
            iVar6 = 0;
          }
          else {
            iVar6 = FUN_004ef050(iVar10);
          }
        }
        FEObject__SetInvisible(iVar6);
      }
      else {
        FUN_00586580(local_20);
        iVar10 = -1;
        pbVar7 = &local_40;
        bVar4 = local_40;
        while (bVar4 != 0) {
          if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
            bVar4 = bVar4 - 0x20;
          }
          pbVar1 = pbVar7 + 1;
          iVar10 = iVar10 * 0x21 + (uint)bVar4;
          pbVar7 = pbVar7 + 1;
          bVar4 = *pbVar1;
        }
        if (((((*(int *)(param_1 + 0xc) != 0) && (iVar6 = FEngFindPackage(), iVar6 != 0)) &&
             (iVar6 = FUN_004ffb70(), iVar6 != 0)) ||
            ((DAT_0073578c != 0 && (iVar6 = FUN_004ef050(iVar10), iVar6 != 0)))) &&
           (*(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) & 0xfffffffe | 0x400000,
           *(int *)(iVar6 + 0x18) == 5)) {
          uVar12 = *(undefined4 *)(iVar6 + 0x60);
          iVar10 = *(int *)(iVar6 + 0x5c);
          if (0 < iVar10) {
            do {
              FEObject__SetVisible(uVar12);
              uVar12 = *(undefined4 *)(extraout_EDX_02 + 4);
              iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
          }
        }
        FEngPrintf(local_20);
      }
      if (local_50 == 0) {
        pcVar11 = "Time%d";
        iVar10 = 1;
      }
      else {
        pcVar11 = "Lead%d";
        iVar10 = iVar5;
      }
      bSPrintf_regdst(0x20,pcVar11,iVar10);
      if ((&DAT_00777cd8)[local_50 * 0x57] == 1) {
        if (local_50 == 0) {
          FUN_00586580(local_20);
          FEngPrintf(&DAT_006cc568,local_20);
        }
        else {
          if ((float)(iVar9 - iVar3) * 0.00025 < 0.0) {
            uVar12 = 0x61c9b7a2;
            goto LAB_0049a386;
          }
          FUN_00586580(local_20);
          FEngPrintf(&DAT_006cc568,local_20);
        }
      }
      else {
        switch((&DAT_00777cd8)[local_50 * 0x57]) {
        case 3:
          uVar12 = 0x5d82dba2;
          break;
        default:
          uVar12 = 0xd4293449;
          break;
        case 6:
          uVar12 = 0x1e66364;
          break;
        case 7:
          uVar12 = 0xb7b75185;
          break;
        case 9:
          uVar12 = 0x1ce129e0;
          break;
        case 10:
          uVar12 = 0xa7db717f;
        }
LAB_0049a386:
        FUN_00416bb0(uVar12);
      }
      local_50 = iVar5;
    } while (iVar5 < param_3);
  }
  return;
}


// ==== 0x49a3e0 PostRaceResultsScreen::SetupRaceTimes

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceResultsScreen__SetupRaceTimes(int param_1,undefined4 param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  byte *pbVar8;
  int extraout_EDX;
  int extraout_EDX_00;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int local_2c;
  byte local_20;
  byte local_1f [31];
  
  local_2c = 0;
  if (0 < param_3) {
    do {
      iVar7 = local_2c + 1;
      bSPrintf_regdst(0x20,"PointEarned_%d",iVar7);
      iVar10 = -1;
      pbVar8 = &local_20;
      bVar3 = local_20;
      while (bVar3 != 0) {
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 - 0x20;
        }
        pbVar1 = pbVar8 + 1;
        iVar10 = iVar10 * 0x21 + (uint)bVar3;
        pbVar8 = pbVar8 + 1;
        bVar3 = *pbVar1;
      }
      iVar9 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049a4c3:
        if (iVar9 == 0) {
LAB_0049a4d4:
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_004ef050(iVar10);
        }
      }
      else {
        iVar5 = FEPackageList__FindByName(&DAT_00746104);
        iVar9 = DAT_0073578c;
        if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) {
          if (DAT_0073578c != 0) {
            iVar2 = *(int *)(DAT_0073578c + 8);
            if ((iVar2 == 0) ||
               ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
                (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_0049a4c3;
            goto LAB_0049a4ac;
          }
          goto LAB_0049a4d4;
        }
LAB_0049a4ac:
        if ((iVar5 == 0) || (iVar5 = FUN_004ffb70(), iVar9 = DAT_0073578c, iVar5 == 0))
        goto LAB_0049a4c3;
      }
      FEObject__SetInvisible(iVar5);
      bSPrintf_regdst(0x20,"TotalPoints_%d",iVar7);
      iVar10 = -1;
      pbVar8 = &local_20;
      bVar3 = local_20;
      while (bVar3 != 0) {
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 - 0x20;
        }
        pbVar1 = pbVar8 + 1;
        iVar10 = iVar10 * 0x21 + (uint)bVar3;
        pbVar8 = pbVar8 + 1;
        bVar3 = *pbVar1;
      }
      iVar9 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049a593:
        if (iVar9 == 0) {
LAB_0049a5a4:
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_004ef050(iVar10);
        }
      }
      else {
        iVar5 = FEPackageList__FindByName(&DAT_00746104);
        iVar9 = DAT_0073578c;
        if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) {
          if (DAT_0073578c != 0) {
            iVar2 = *(int *)(DAT_0073578c + 8);
            if ((iVar2 == 0) ||
               ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
                (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_0049a593;
            goto LAB_0049a57c;
          }
          goto LAB_0049a5a4;
        }
LAB_0049a57c:
        if ((iVar5 == 0) || (iVar5 = FUN_004ffb70(), iVar9 = DAT_0073578c, iVar5 == 0))
        goto LAB_0049a593;
      }
      FEObject__SetInvisible(iVar5);
      bSPrintf_regdst(0x20,"BestLap_%d",iVar7);
      iVar10 = -1;
      pbVar8 = &local_20;
      bVar3 = local_20;
      while (bVar3 != 0) {
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 - 0x20;
        }
        pbVar1 = pbVar8 + 1;
        iVar10 = iVar10 * 0x21 + (uint)bVar3;
        pbVar8 = pbVar8 + 1;
        bVar3 = *pbVar1;
      }
      iVar9 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049a663:
        if (iVar9 == 0) {
LAB_0049a674:
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_004ef050(iVar10);
        }
      }
      else {
        iVar5 = FEPackageList__FindByName(&DAT_00746104);
        iVar9 = DAT_0073578c;
        if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) {
          if (DAT_0073578c != 0) {
            iVar2 = *(int *)(DAT_0073578c + 8);
            if ((iVar2 == 0) ||
               ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
                (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_0049a663;
            goto LAB_0049a64c;
          }
          goto LAB_0049a674;
        }
LAB_0049a64c:
        if ((iVar5 == 0) || (iVar5 = FUN_004ffb70(), iVar9 = DAT_0073578c, iVar5 == 0))
        goto LAB_0049a663;
      }
      FEObject__SetInvisible(iVar5);
      bSPrintf_regdst(0x20,"PointEarned_%d",iVar7);
      iVar10 = -1;
      pbVar8 = &local_20;
      bVar3 = local_20;
      while (bVar3 != 0) {
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 - 0x20;
        }
        pbVar1 = pbVar8 + 1;
        iVar10 = iVar10 * 0x21 + (uint)bVar3;
        pbVar8 = pbVar8 + 1;
        bVar3 = *pbVar1;
      }
      iVar9 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049a733:
        if (iVar9 == 0) {
LAB_0049a744:
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_004ef050(iVar10);
        }
      }
      else {
        iVar5 = FEPackageList__FindByName(&DAT_00746104);
        iVar9 = DAT_0073578c;
        if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) {
          if (DAT_0073578c != 0) {
            iVar2 = *(int *)(DAT_0073578c + 8);
            if ((iVar2 == 0) ||
               ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
                (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_0049a733;
            goto LAB_0049a71c;
          }
          goto LAB_0049a744;
        }
LAB_0049a71c:
        if ((iVar5 == 0) || (iVar5 = FUN_004ffb70(), iVar9 = DAT_0073578c, iVar5 == 0))
        goto LAB_0049a733;
      }
      FEObject__SetInvisible(iVar5);
      bSPrintf_regdst(0x20,"TotalPoints_%d",iVar7);
      iVar10 = -1;
      pbVar8 = &local_20;
      bVar3 = local_20;
      while (bVar3 != 0) {
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 - 0x20;
        }
        pbVar1 = pbVar8 + 1;
        iVar10 = iVar10 * 0x21 + (uint)bVar3;
        pbVar8 = pbVar8 + 1;
        bVar3 = *pbVar1;
      }
      iVar9 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049a803:
        if (iVar9 == 0) {
LAB_0049a814:
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_004ef050(iVar10);
        }
      }
      else {
        iVar5 = FEPackageList__FindByName(&DAT_00746104);
        iVar9 = DAT_0073578c;
        if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) {
          if (DAT_0073578c != 0) {
            iVar2 = *(int *)(DAT_0073578c + 8);
            if ((iVar2 == 0) ||
               ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
                (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_0049a803;
            goto LAB_0049a7ec;
          }
          goto LAB_0049a814;
        }
LAB_0049a7ec:
        if ((iVar5 == 0) || (iVar5 = FUN_004ffb70(), iVar9 = DAT_0073578c, iVar5 == 0))
        goto LAB_0049a803;
      }
      FEObject__SetInvisible(iVar5);
      bSPrintf_regdst(0x20,"Lead%d",iVar7);
      iVar10 = -1;
      pbVar8 = &local_20;
      bVar3 = local_20;
      while (bVar3 != 0) {
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 - 0x20;
        }
        pbVar1 = pbVar8 + 1;
        iVar10 = iVar10 * 0x21 + (uint)bVar3;
        pbVar8 = pbVar8 + 1;
        bVar3 = *pbVar1;
      }
      iVar9 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049a8d7:
        if ((iVar9 != 0) && (iVar5 = FUN_004ef050(iVar10), iVar5 != 0)) {
LAB_0049a8ea:
          *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
          if (*(int *)(iVar5 + 0x18) == 5) {
            uVar11 = *(undefined4 *)(iVar5 + 0x60);
            iVar10 = *(int *)(iVar5 + 0x5c);
            if (0 < iVar10) {
              do {
                FEObject__SetVisible(uVar11);
                uVar11 = *(undefined4 *)(extraout_EDX + 4);
                iVar10 = iVar10 + -1;
              } while (iVar10 != 0);
            }
          }
        }
      }
      else {
        iVar5 = FEPackageList__FindByName(&DAT_00746104);
        iVar9 = DAT_0073578c;
        if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_0049a8c0:
          if ((iVar5 == 0) || (iVar5 = FUN_004ffb70(), iVar9 = DAT_0073578c, iVar5 == 0))
          goto LAB_0049a8d7;
          goto LAB_0049a8ea;
        }
        if (DAT_0073578c != 0) {
          iVar2 = *(int *)(DAT_0073578c + 8);
          if ((iVar2 == 0) ||
             ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
              (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_0049a8d7;
          goto LAB_0049a8c0;
        }
      }
      bSPrintf_regdst(0x20,"Time%d",iVar7);
      iVar10 = -1;
      pbVar8 = &local_20;
      bVar3 = local_20;
      while (bVar3 != 0) {
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 - 0x20;
        }
        pbVar1 = pbVar8 + 1;
        iVar10 = iVar10 * 0x21 + (uint)bVar3;
        pbVar8 = pbVar8 + 1;
        bVar3 = *pbVar1;
      }
      iVar9 = DAT_0073578c;
      if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049a9da:
        if ((iVar9 != 0) && (iVar5 = FUN_004ef050(iVar10), iVar5 != 0)) {
LAB_0049a9ed:
          *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
          if (*(int *)(iVar5 + 0x18) == 5) {
            uVar11 = *(undefined4 *)(iVar5 + 0x60);
            iVar10 = *(int *)(iVar5 + 0x5c);
            if (0 < iVar10) {
              do {
                FEObject__SetVisible(uVar11);
                uVar11 = *(undefined4 *)(extraout_EDX_00 + 4);
                iVar10 = iVar10 + -1;
              } while (iVar10 != 0);
            }
          }
        }
      }
      else {
        iVar5 = FEPackageList__FindByName(&DAT_00746104);
        iVar9 = DAT_0073578c;
        if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_0049a9c3:
          if ((iVar5 == 0) || (iVar5 = FUN_004ffb70(), iVar9 = DAT_0073578c, iVar5 == 0))
          goto LAB_0049a9da;
          goto LAB_0049a9ed;
        }
        if (DAT_0073578c != 0) {
          iVar2 = *(int *)(DAT_0073578c + 8);
          if ((iVar2 == 0) ||
             ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
              (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_0049a9da;
          goto LAB_0049a9c3;
        }
      }
      cVar4 = FUN_0043a2e0();
      if ((cVar4 == '\0') &&
         (iVar10 = 0, puVar6 = DAT_0077b198, (undefined4 **)DAT_0077b198 != &DAT_0077b198)) {
        do {
          if (iVar10 == local_2c) break;
          puVar6 = (undefined4 *)*puVar6;
          iVar10 = iVar10 + 1;
        } while ((undefined4 **)puVar6 != &DAT_0077b198);
      }
      cVar4 = FUN_0043a2e0();
      if (cVar4 == '\0') {
LAB_0049aadd:
        bSPrintf_regdst(0x20,"Time%d",iVar7);
        uVar11 = _ftol_nocw();
        FEngPrintf(&DAT_006ca778,uVar11);
        bSPrintf_regdst(0x20,"Lead%d",iVar7);
        FEngPrintf(&DAT_006ca778,uVar11);
      }
      else {
        if ((&DAT_00777cd8)[local_2c * 0x57] == 9) {
          uVar11 = 0x1ce129e0;
        }
        else {
          if ((&DAT_00777cd8)[local_2c * 0x57] != 10) goto LAB_0049aadd;
          uVar11 = 0xa7db717f;
        }
        bSPrintf_regdst(0x20,"Time%d",iVar7);
        FUN_00416bb0(uVar11);
        bSPrintf_regdst(0x20,"Lead%d",iVar7);
        FUN_00416bb0(uVar11);
      }
      local_2c = iVar7;
    } while (iVar7 < param_3);
  }
  return;
}


// ==== 0x49ab60 PostRaceResultsScreen::SetupTourneyPoints

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceResultsScreen__SetupTourneyPoints(int param_1,int param_2,int param_3,int param_4)

{
  byte *pbVar1;
  undefined4 uVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int *piVar12;
  int local_2c;
  int local_28;
  byte local_20;
  byte local_1f [31];
  
  if ((param_4 != 0) && (local_2c = 0, 0 < param_3)) {
    local_28 = param_4 + 0x586c;
    do {
      if (param_2 <= local_2c) {
        return;
      }
      iVar9 = local_2c + 1;
      bSPrintf_regdst(0x20,"Lead%d",iVar9);
      iVar11 = -1;
      pbVar6 = &local_20;
      bVar3 = local_20;
      while (bVar3 != 0) {
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 - 0x20;
        }
        pbVar1 = pbVar6 + 1;
        iVar11 = iVar11 * 0x21 + (uint)bVar3;
        pbVar6 = pbVar6 + 1;
        bVar3 = *pbVar1;
      }
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FEngFindPackage(), iVar4 == 0)) ||
         (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
        if (DAT_0073578c == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_004ef050(iVar11);
        }
      }
      FEObject__SetInvisible(iVar4);
      bSPrintf_regdst(0x20,"Time%d",iVar9);
      iVar11 = -1;
      pbVar6 = &local_20;
      bVar3 = local_20;
      while (bVar3 != 0) {
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 - 0x20;
        }
        iVar11 = iVar11 * 0x21 + (uint)bVar3;
        pbVar1 = pbVar6 + 1;
        pbVar6 = pbVar6 + 1;
        bVar3 = *pbVar1;
      }
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FEngFindPackage(), iVar4 == 0)) ||
         (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
        if (DAT_0073578c == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_004ef050(iVar11);
        }
      }
      FEObject__SetInvisible(iVar4);
      bSPrintf_regdst(0x20,"BestLap_%d",iVar9);
      iVar11 = -1;
      pbVar6 = &local_20;
      bVar3 = local_20;
      while (bVar3 != 0) {
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 - 0x20;
        }
        pbVar1 = pbVar6 + 1;
        iVar11 = iVar11 * 0x21 + (uint)bVar3;
        pbVar6 = pbVar6 + 1;
        bVar3 = *pbVar1;
      }
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FEngFindPackage(), iVar4 == 0)) ||
         (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
        if (DAT_0073578c == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_004ef050(iVar11);
        }
      }
      FEObject__SetInvisible(iVar4);
      iVar11 = *(int *)(param_4 + 0x5864);
      if ((local_2c < 0) || (iVar4 = local_28, *(int *)(param_4 + 0x589c) <= local_2c)) {
        iVar4 = 0;
      }
      iVar7 = 0;
      if (0 < *(int *)(iVar11 + 0xb08)) {
        piVar12 = (int *)(iVar11 + 0x2c);
        do {
          if (*piVar12 == *(int *)(iVar4 + 4)) {
            puVar8 = (undefined4 *)(iVar7 * 0x15c + iVar11 + 0x28);
            goto LAB_0049ad81;
          }
          iVar7 = iVar7 + 1;
          piVar12 = piVar12 + 0x57;
        } while (iVar7 < *(int *)(iVar11 + 0xb08));
      }
      puVar8 = (undefined4 *)0x0;
LAB_0049ad81:
      uVar2 = *puVar8;
      if ((local_2c < 0) || (iVar4 = local_28, *(int *)(param_4 + 0x589c) <= local_2c)) {
        iVar4 = 0;
      }
      uVar10 = 0;
      if ((iVar4 != 0) && (iVar11 != 0)) {
        iVar11 = FUN_005a28f0();
        if (iVar11 == 0) {
          iVar11 = 1;
        }
        uVar10 = *(undefined4 *)(&DAT_006ee3c4 + iVar11 * 4);
      }
      uVar5 = FUN_005a29c0();
      bSPrintf_regdst(0x20,"PointEarned_%d",uVar2);
      iVar11 = -1;
      pbVar6 = &local_20;
      bVar3 = local_20;
      while (bVar3 != 0) {
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 - 0x20;
        }
        iVar11 = iVar11 * 0x21 + (uint)bVar3;
        pbVar1 = pbVar6 + 1;
        pbVar6 = pbVar6 + 1;
        bVar3 = *pbVar1;
      }
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FEngFindPackage(), iVar4 == 0)) ||
         (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
        if (DAT_0073578c == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_004ef050(iVar11);
        }
      }
      FEObject__SetVisible(iVar4);
      iVar11 = LanguageStrings__FindByHash();
      if (iVar11 == 0) {
        iVar11 = LanguageStrings__FindByHash();
      }
      FEngPrintf("%s %d",iVar11,uVar10);
      bSPrintf_regdst(0x20,"TotalPoints_%d",uVar2);
      iVar11 = -1;
      pbVar6 = &local_20;
      bVar3 = local_20;
      while (bVar3 != 0) {
        if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
          bVar3 = bVar3 - 0x20;
        }
        pbVar1 = pbVar6 + 1;
        iVar11 = iVar11 * 0x21 + (uint)bVar3;
        pbVar6 = pbVar6 + 1;
        bVar3 = *pbVar1;
      }
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar4 = FEngFindPackage(), iVar4 == 0)) ||
         (iVar4 = FUN_004ffb70(), iVar4 == 0)) {
        if (DAT_0073578c == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_004ef050(iVar11);
        }
      }
      FEObject__SetVisible(iVar4);
      iVar11 = LanguageStrings__FindByHash();
      if (iVar11 == 0) {
        iVar11 = LanguageStrings__FindByHash();
      }
      FEngPrintf("%s %d",iVar11,uVar5);
      local_28 = local_28 + 0xc;
      local_2c = iVar9;
    } while (iVar9 < param_3);
  }
  return;
}


// ==== 0x49af70 Screen_PostRaceStats::CompareByScoreDesc

/* [canon] canon low (ghidra-canon) docs/re/canon.md */

bool Screen_PostRaceStats__CompareByScoreDesc(int param_1,int param_2)

{
  return *(int *)(param_2 + 0x14) <= *(int *)(param_1 + 0x14);
}


// ==== 0x49af90 PostRaceResultsScreen::SetupTourneyPoints

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceResultsScreen__SetupTourneyPoints(int param_1,int param_2,int param_3,int param_4)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  int ***pppiVar7;
  int ****ppppiVar8;
  undefined4 *puVar9;
  int ***pppiVar10;
  int iVar11;
  byte *pbVar12;
  undefined4 uVar13;
  int extraout_EDX;
  int ****ppppiVar14;
  int iVar15;
  int local_ac;
  int ***local_a8;
  int ***local_a4;
  int ***local_a0;
  int local_9c;
  byte local_98;
  byte abStack_97 [31];
  undefined **local_78;
  int local_74;
  int local_70;
  undefined **local_6c;
  int local_68;
  int local_64;
  undefined **local_60;
  int local_5c;
  int local_58;
  undefined **local_54;
  int local_50;
  int local_4c;
  undefined **local_48;
  int local_44;
  int local_40;
  undefined1 local_3c [16];
  byte local_2c;
  byte local_2b [31];
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_006884f3;
  local_c = ExceptionList;
  if (param_4 != 0) {
    iVar15 = param_3;
    if (((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) &&
       (iVar15 = *(int *)(param_4 + 0x589c), *(int *)(param_4 + 0x589c) < param_3)) {
      iVar15 = param_3;
    }
    param_3 = iVar15;
    local_a8 = (int ***)&local_a8;
    local_a4 = (int ***)&local_a8;
    local_4 = 0;
    local_a0 = (int ***)0x0;
    ExceptionList = &local_c;
    if (0 < param_3) {
      local_ac = param_4 + 0x586c;
      ExceptionList = &local_c;
      do {
        ppppiVar14 = (int ****)local_a0;
        iVar15 = *(int *)(param_4 + 0x5864);
        if (((int)local_a0 < 0) || (iVar11 = local_ac, *(int *)(param_4 + 0x589c) <= (int)local_a0))
        {
          iVar11 = 0;
        }
        iVar5 = 0;
        if (0 < *(int *)(iVar15 + 0xb08)) {
          piVar6 = (int *)(iVar15 + 0x2c);
          do {
            if (*piVar6 == *(int *)(iVar11 + 4)) {
              piVar6 = (int *)(iVar5 * 0x15c + iVar15 + 0x28);
              goto LAB_0049b061;
            }
            iVar5 = iVar5 + 1;
            piVar6 = piVar6 + 0x57;
          } while (iVar5 < *(int *)(iVar15 + 0xb08));
        }
        piVar6 = (int *)0x0;
LAB_0049b061:
        iVar15 = *piVar6;
        pppiVar7 = (int ***)FUN_005a29c0();
        ppppiVar8 = _malloc(0x18);
        if (ppppiVar8 == (int ****)0x0) {
          ppppiVar8 = (int ****)0x0;
        }
        else {
          ppppiVar8[2] = (int ***)(&DAT_00777b74 + iVar15 * 0x15c);
          ppppiVar8[5] = pppiVar7;
        }
        *local_a4 = (int **)ppppiVar8;
        ppppiVar8[1] = local_a4;
        *ppppiVar8 = (int ***)&local_a8;
        local_a4 = (int ***)ppppiVar8;
        if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
          iVar11 = 0;
          if (0 < *(int *)(DAT_007361f8 + 0x18)) {
            piVar6 = (int *)(DAT_007361f8 + 0x28);
            do {
              iVar5 = *piVar6;
              ppppiVar14 = (int ****)local_a0;
              if ((int)*(short *)(iVar5 + 10) == (&DAT_00777b78)[iVar15 * 0x57]) goto LAB_0049b156;
              iVar11 = iVar11 + 1;
              piVar6 = piVar6 + 1;
            } while (iVar11 < *(int *)(DAT_007361f8 + 0x18));
          }
          iVar5 = 0;
LAB_0049b156:
          if ((*(int *)(*(int *)(iVar5 + 0x14) + 4) == 1) &&
             (*(char *)(*(int *)(iVar5 + 0x14) + 0x734) == '\0')) {
            iVar15 = *(int *)(iVar5 + 0x18);
            cVar4 = FUN_0043a2e0();
            if (cVar4 == '\0') {
              pppiVar7 = (int ***)(iVar15 + 0x34);
            }
            else {
              pppiVar7 = (int ***)(DAT_0077b244 + 0x19);
            }
          }
          else {
            cVar4 = FUN_0043a2e0();
            if (cVar4 != '\0') {
              iVar15 = Race__GetPlayer((&DAT_00777b78)[iVar15 * 0x57]);
              local_a4[3] = (int **)(iVar15 + 0x19);
              goto LAB_0049b1d2;
            }
            pppiVar7 = (int ***)(*(int *)(iVar5 + 0x14) + 0x73c);
          }
          local_a4[3] = (int **)pppiVar7;
        }
        else {
          iVar11 = 0;
          puVar9 = DAT_0077b198;
          if ((undefined4 **)DAT_0077b198 != &DAT_0077b198) {
            do {
              if (iVar11 == iVar15 + -1) break;
              puVar9 = (undefined4 *)*puVar9;
              iVar11 = iVar11 + 1;
            } while ((undefined4 **)puVar9 != &DAT_0077b198);
          }
          ppppiVar8[3] = (int ***)puVar9[6];
          iVar11 = 0;
          if ((undefined4 **)DAT_0077b198 != &DAT_0077b198) {
            puVar9 = DAT_0077b198;
            do {
              if (iVar11 == iVar15 + -1) break;
              puVar9 = (undefined4 *)*puVar9;
              iVar11 = iVar11 + 1;
            } while ((undefined4 **)puVar9 != &DAT_0077b198);
          }
        }
LAB_0049b1d2:
        pppiVar7 = local_a4;
        pppiVar10 = (int ***)GetCarModelNameHash();
        pppiVar7[4] = (int **)pppiVar10;
        local_a0 = (int ***)((int)ppppiVar14 + 1);
        local_ac = local_ac + 0xc;
      } while ((int)local_a0 < param_3);
    }
    bList__Sort(&local_a8,Screen_PostRaceStats__CompareByScoreDesc);
    local_9c = 0;
    if (0 < param_3) {
      do {
        if (param_2 <= local_9c) break;
        iVar11 = local_9c + 1;
        bSPrintf_regdst(0x20,"Lead%d",iVar11);
        iVar15 = -1;
        pbVar12 = &local_98;
        bVar3 = local_98;
        while (bVar3 != 0) {
          if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
            bVar3 = bVar3 - 0x20;
          }
          iVar15 = iVar15 * 0x21 + (uint)bVar3;
          pbVar1 = pbVar12 + 1;
          pbVar12 = pbVar12 + 1;
          bVar3 = *pbVar1;
        }
        if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049b329:
          if (DAT_0073578c == 0) {
LAB_0049b33f:
            iVar5 = 0;
          }
          else {
            iVar5 = FUN_004ef050(iVar15);
          }
        }
        else {
          iVar5 = FEPackageList__FindByName(&DAT_00746104);
          if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) {
            if (DAT_0073578c != 0) {
              iVar2 = *(int *)(DAT_0073578c + 8);
              if ((iVar2 == 0) ||
                 ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
                  (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_0049b329;
              goto LAB_0049b2eb;
            }
            goto LAB_0049b33f;
          }
LAB_0049b2eb:
          local_54 = &PTR_FUN_006c1800;
          local_4._0_1_ = 1;
          local_4c = 0;
          local_50 = iVar15;
          FUN_004ffb00(iVar5);
          local_4 = (uint)local_4._1_3_ << 8;
          local_54 = &PTR_FUN_006c2c5c;
          iVar5 = local_4c;
          if (local_4c == 0) goto LAB_0049b329;
        }
        FEObject__SetInvisible(iVar5);
        bSPrintf_regdst(0x20,"Time%d",iVar11);
        iVar15 = -1;
        pbVar12 = &local_98;
        bVar3 = local_98;
        while (bVar3 != 0) {
          if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
            bVar3 = bVar3 - 0x20;
          }
          iVar15 = iVar15 * 0x21 + (uint)bVar3;
          pbVar1 = pbVar12 + 1;
          pbVar12 = pbVar12 + 1;
          bVar3 = *pbVar1;
        }
        if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049b432:
          if (DAT_0073578c == 0) {
LAB_0049b448:
            iVar5 = 0;
          }
          else {
            iVar5 = FUN_004ef050(iVar15);
          }
        }
        else {
          iVar5 = FEPackageList__FindByName(&DAT_00746104);
          if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) {
            if (DAT_0073578c != 0) {
              iVar2 = *(int *)(DAT_0073578c + 8);
              if ((iVar2 == 0) ||
                 ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
                  (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_0049b432;
              goto LAB_0049b3f4;
            }
            goto LAB_0049b448;
          }
LAB_0049b3f4:
          local_78 = &PTR_FUN_006c1800;
          local_4._0_1_ = 2;
          local_70 = 0;
          local_74 = iVar15;
          FUN_004ffb00(iVar5);
          local_4 = (uint)local_4._1_3_ << 8;
          local_78 = &PTR_FUN_006c2c5c;
          iVar5 = local_70;
          if (local_70 == 0) goto LAB_0049b432;
        }
        FEObject__SetInvisible(iVar5);
        bSPrintf_regdst(0x20,"BestLap_%d",iVar11);
        iVar15 = -1;
        pbVar12 = &local_98;
        bVar3 = local_98;
        while (bVar3 != 0) {
          if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
            bVar3 = bVar3 - 0x20;
          }
          iVar15 = iVar15 * 0x21 + (uint)bVar3;
          pbVar1 = pbVar12 + 1;
          pbVar12 = pbVar12 + 1;
          bVar3 = *pbVar1;
        }
        if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049b53b:
          if (DAT_0073578c == 0) {
LAB_0049b551:
            iVar5 = 0;
          }
          else {
            iVar5 = FUN_004ef050(iVar15);
          }
        }
        else {
          iVar5 = FEPackageList__FindByName(&DAT_00746104);
          if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) {
            if (DAT_0073578c != 0) {
              iVar2 = *(int *)(DAT_0073578c + 8);
              if ((iVar2 == 0) ||
                 ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
                  (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_0049b53b;
              goto LAB_0049b4fd;
            }
            goto LAB_0049b551;
          }
LAB_0049b4fd:
          local_60 = &PTR_FUN_006c1800;
          local_4._0_1_ = 3;
          local_58 = 0;
          local_5c = iVar15;
          FUN_004ffb00(iVar5);
          local_4 = (uint)local_4._1_3_ << 8;
          local_60 = &PTR_FUN_006c2c5c;
          iVar5 = local_58;
          if (local_58 == 0) goto LAB_0049b53b;
        }
        FEObject__SetInvisible(iVar5);
        bSPrintf_regdst(0x20,"PointEarned_%d",iVar11);
        iVar15 = -1;
        pbVar12 = &local_98;
        bVar3 = local_98;
        while (bVar3 != 0) {
          if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
            bVar3 = bVar3 - 0x20;
          }
          iVar15 = iVar15 * 0x21 + (uint)bVar3;
          pbVar1 = pbVar12 + 1;
          pbVar12 = pbVar12 + 1;
          bVar3 = *pbVar1;
        }
        if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049b64d:
          if (DAT_0073578c == 0) {
LAB_0049b663:
            iVar5 = 0;
          }
          else {
            iVar5 = FUN_004ef050(iVar15);
          }
        }
        else {
          iVar5 = FEPackageList__FindByName(&DAT_00746104);
          if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + 0x18), iVar5 == 0)) {
            if (DAT_0073578c != 0) {
              iVar2 = *(int *)(DAT_0073578c + 8);
              if ((iVar2 == 0) ||
                 ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
                  (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_0049b64d;
              goto LAB_0049b60c;
            }
            goto LAB_0049b663;
          }
LAB_0049b60c:
          local_48 = &PTR_FUN_006c1800;
          local_4._0_1_ = 4;
          local_40 = 0;
          local_44 = iVar15;
          FUN_004ffb00(iVar5);
          local_4 = (uint)local_4._1_3_ << 8;
          local_48 = &PTR_FUN_006c2c5c;
          iVar5 = local_40;
          if (local_40 == 0) goto LAB_0049b64d;
        }
        FEObject__SetInvisible(iVar5);
        iVar15 = 0;
        ppppiVar14 = (int ****)local_a8;
        if ((int ****)local_a8 != &local_a8) {
          do {
            if (iVar15 == local_9c) break;
            ppppiVar14 = (int ****)*ppppiVar14;
            iVar15 = iVar15 + 1;
          } while (ppppiVar14 != &local_a8);
        }
        local_a0 = (int ***)ppppiVar14;
        bSPrintf_regdst(0x20,"Pos%d",iVar11);
        FEngPrintf(&PTR_FUN_006c7968,iVar11);
        bSPrintf_regdst(0x20,"Name%d",iVar11);
        FEngPrintf(&DAT_006cc568,ppppiVar14[3]);
        if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
          iVar15 = 0;
          if (0 < *(int *)(DAT_007361f8 + 0x18)) {
            piVar6 = (int *)(DAT_007361f8 + 0x28);
            do {
              if ((int **)(int)*(short *)(*piVar6 + 10) == ppppiVar14[2][1]) break;
              iVar15 = iVar15 + 1;
              piVar6 = piVar6 + 1;
            } while (iVar15 < *(int *)(DAT_007361f8 + 0x18));
          }
          bSPrintf_regdst(0x20,"CarColor_%d",iVar11);
          iVar15 = -1;
          pbVar12 = &local_2c;
          bVar3 = local_2c;
          while (bVar3 != 0) {
            if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
              bVar3 = bVar3 - 0x20;
            }
            iVar15 = iVar15 * 0x21 + (uint)bVar3;
            pbVar1 = pbVar12 + 1;
            pbVar12 = pbVar12 + 1;
            bVar3 = *pbVar1;
          }
          if (((*(int *)(param_1 + 0xc) == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
             (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
            if (DAT_0073578c == 0) goto LAB_0049b80e;
            iVar5 = FUN_004ef050(iVar15);
          }
          if ((iVar5 != 0) && (FUN_00495ce0(local_3c), *(int *)(iVar5 + 0x18) < 0x100)) {
            cVar4 = FEColor_NearlyEqual();
            if (cVar4 == '\0') {
              *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 0x400000;
            }
            FUN_004ff2f0(iVar5,0,0);
          }
        }
LAB_0049b80e:
        bSPrintf_regdst(0x20,"CarModel_%d",iVar11);
        FUN_00416bb0(local_a0[4]);
        bSPrintf_regdst(0x20,"TotalPoints_%d",iVar11);
        iVar15 = -1;
        pbVar12 = &local_98;
        bVar3 = local_98;
        while (bVar3 != 0) {
          if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
            bVar3 = bVar3 - 0x20;
          }
          pbVar1 = pbVar12 + 1;
          iVar15 = iVar15 * 0x21 + (uint)bVar3;
          pbVar12 = pbVar12 + 1;
          bVar3 = *pbVar1;
        }
        if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049b91d:
          if ((DAT_0073578c != 0) && (iVar5 = FUN_004ef050(iVar15), iVar5 != 0)) {
LAB_0049b937:
            *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
            if (*(int *)(iVar5 + 0x18) == 5) {
              uVar13 = *(undefined4 *)(iVar5 + 0x60);
              iVar15 = *(int *)(iVar5 + 0x5c);
              if (0 < iVar15) {
                do {
                  FEObject__SetVisible(uVar13);
                  uVar13 = *(undefined4 *)(extraout_EDX + 4);
                  iVar15 = iVar15 + -1;
                } while (iVar15 != 0);
              }
            }
          }
        }
        else {
          iVar5 = FEPackageList__FindByName(&DAT_00746104);
          if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_0049b8df:
            local_6c = &PTR_FUN_006c1800;
            local_4._0_1_ = 5;
            local_64 = 0;
            local_68 = iVar15;
            FUN_004ffb00(iVar5);
            local_4 = (uint)local_4._1_3_ << 8;
            local_6c = &PTR_FUN_006c2c5c;
            iVar5 = local_64;
            if (local_64 == 0) goto LAB_0049b91d;
            goto LAB_0049b937;
          }
          if (DAT_0073578c != 0) {
            iVar2 = *(int *)(DAT_0073578c + 8);
            if ((iVar2 == 0) ||
               ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 == 0 &&
                (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 == 0)))) goto LAB_0049b91d;
            goto LAB_0049b8df;
          }
        }
        iVar15 = LanguageStrings__FindByHash();
        if (iVar15 == 0) {
          iVar15 = LanguageStrings__FindByHash();
        }
        FEngPrintf("%s %d",iVar15,local_a0[5]);
        local_9c = iVar11;
      } while (iVar11 < param_3);
    }
    if ((int ****)local_a8 != &local_a8) {
      do {
        pppiVar7 = (int ***)*local_a8;
        pppiVar10 = (int ***)local_a8[1];
        *pppiVar10 = (int **)pppiVar7;
        pppiVar7[1] = (int **)pppiVar10;
        _free(local_a8);
      } while ((int ****)local_a8 != &local_a8);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x49ba10 PostRaceResultsScreen::NotificationMessage

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void __thiscall PostRaceResultsScreen__NotificationMessage(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  
  if (param_2 == -0x6ee54c9c) {
    cVar1 = FUN_004f6c80("FadeOut");
    piVar3 = DAT_00777ccc;
    if (((cVar1 == '\0') && (DAT_00777ccc != (int *)0x0)) && (DAT_00777ccc[0x1629] == 1)) {
      if (DAT_00735ed4 != '\0') {
        DAT_00735ed4 = DAT_00735ed4 + -1;
      }
      if (DAT_00735ed4 == '\0') {
        cVar1 = FUN_0043a2e0();
        if (cVar1 == '\0') {
          iVar2 = 4;
        }
        else {
          iVar2 = DAT_0078a328 + DAT_0078a32c + DAT_0078a324 + DAT_0078a320;
        }
        cVar1 = IsDriftMode();
        if (cVar1 != '\0') {
          PostRaceResultsScreen__SetupRacers(param_1,4,iVar2);
          PostRaceResultsScreen__SetupRaceTimes(param_1,4,iVar2);
          return;
        }
        PostRaceResultsScreen__SetupRacers(param_1,4);
        PostRaceResultsScreen__SetupRaceTimes
                  (param_1,4,DAT_0078a328 + DAT_0078a32c + DAT_0078a324 + DAT_0078a320);
      }
      else {
        if (DAT_00735ed4 == '\x01') {
          cVar1 = FUN_0043a2e0();
          if (cVar1 == '\0') {
            iVar2 = 4;
          }
          else {
            iVar2 = DAT_0078a328 + DAT_0078a32c + DAT_0078a324 + DAT_0078a320;
          }
          cVar1 = IsDriftMode();
          if (cVar1 != '\0') {
            PostRaceResultsScreen__SetupRacers(param_1,4,iVar2);
            PostRaceResultsScreen__SetupTourneyPoints(param_1,4,iVar2,piVar3);
            return;
          }
          PostRaceResultsScreen__SetupRacers(param_1,4);
          PostRaceResultsScreen__SetupTourneyPoints
                    (param_1,4,DAT_0078a328 + DAT_0078a32c + DAT_0078a324 + DAT_0078a320,piVar3);
          return;
        }
        if (DAT_00735ed4 == '\x02') {
LAB_0049bcc6:
          PostRaceResultsScreen__SetupTourneyPoints
                    (param_1,4,DAT_0078a328 + DAT_0078a32c + DAT_0078a324 + DAT_0078a320,piVar3);
          return;
        }
      }
    }
  }
  else if (param_2 == -0x4a50db9f) {
    cVar1 = FUN_004f6c80("FadeOut");
    piVar3 = DAT_00777ccc;
    if (cVar1 == '\0') {
      if ((DAT_00777ccc != (int *)0x0) && (DAT_00777ccc[0x1629] == 1)) {
        DAT_00735ed4 = DAT_00735ed4 + '\x01';
        if (DAT_00735ed4 == '\x01') {
          cVar1 = FUN_0043a2e0();
          if (cVar1 == '\0') {
            iVar2 = 4;
          }
          else {
            iVar2 = DAT_0078a328 + DAT_0078a32c + DAT_0078a324 + DAT_0078a320;
          }
          cVar1 = IsDriftMode();
          if (cVar1 != '\0') {
            PostRaceResultsScreen__SetupRacers(param_1,4,iVar2);
            PostRaceResultsScreen__SetupTourneyPoints(param_1,4,iVar2,piVar3);
            return;
          }
          PostRaceResultsScreen__SetupRacers(param_1,4);
          PostRaceResultsScreen__SetupTourneyPoints
                    (param_1,4,DAT_0078a328 + DAT_0078a32c + DAT_0078a324 + DAT_0078a320,piVar3);
          return;
        }
        if (DAT_00735ed4 == '\x02') {
          cVar1 = FUN_0043a2e0();
          if (cVar1 == '\0') {
            iVar2 = 4;
          }
          else {
            iVar2 = DAT_0078a328 + DAT_0078a32c + DAT_0078a324 + DAT_0078a320;
          }
          cVar1 = (**(code **)(*piVar3 + 4))();
          if (cVar1 != '\0') {
            *(undefined1 *)(param_1 + 0x40) = 1;
            DAT_00735ed4 = DAT_00735ed4 + '\x01';
            return;
          }
          cVar1 = IsDriftMode();
          if (cVar1 != '\0') {
            PostRaceResultsScreen__SetupTourneyPoints(param_1,4,iVar2,piVar3);
            return;
          }
          goto LAB_0049bcc6;
        }
        if (DAT_00735ed4 != '\x03') {
          return;
        }
      }
      *(undefined1 *)(param_1 + 0x40) = 1;
      return;
    }
  }
  else if (param_2 == -0x367ca946) {
    if (*(char *)(param_1 + 0x40) != '\0') {
      if (*(char *)(param_1 + 0x41) == '\0') {
        *(undefined1 *)(param_1 + 0x41) = 1;
        FUN_004f6c30("FadeOut",1);
      }
      else {
        cVar1 = FUN_004f6c80("FadeOut");
        if (cVar1 == '\0') {
          cPostRaceScreenManager__ChangeToNextScreen();
        }
      }
    }
    if (((*(char *)(param_1 + 0x42) == '\0') && (cVar1 = FEngIsPackagePushed(), cVar1 == '\0')) &&
       ((DAT_00777b4c == 1 &&
        ((DAT_007677a8 != 0 && (cVar1 = Race__DidPlayerWin(DAT_007677a8,0), cVar1 != '\0')))))) {
      FUN_004cd3e0();
      *(undefined1 *)(param_1 + 0x42) = 1;
      return;
    }
  }
  return;
}


// ==== 0x49be50 PostRaceStatsScreen::_PostRaceStatsScreen

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void __fastcall PostRaceStatsScreen___PostRaceStatsScreen(undefined4 *param_1)

{
  *param_1 = &PTR_PostRaceStatsScreen___PostRaceStatsScreen_006c75a8;
  FUN_004f7b50();
  return;
}


// ==== 0x49be60 PostRaceStatsScreen::_PostRaceStatsScreen

/* [canon] hud med (ghidra-canon+nfsug) docs/re/canon.md */

void * __thiscall PostRaceStatsScreen___PostRaceStatsScreen(void *param_1,byte param_2)

{
  PostRaceStatsScreen___PostRaceStatsScreen();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x49be80 Screen_PostRaceStats::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_PostRaceStats__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006884b3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x140);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_PostRaceStats__Screen_PostRaceStats(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x49bee0 Screen_PostRaceStats::Screen_PostRaceStats

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_PostRaceStats__Screen_PostRaceStats(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  *param_1 = &PTR_PostRaceStatsScreen___PostRaceStatsScreen_006c75a8;
  local_4 = 0;
  if (DAT_007361b4 == 0) {
    param_1[0x4f] = 1;
  }
  else {
    param_1[0x4f] = (int)*(char *)(*(int *)(*(int *)(DAT_007361b4 + 4) + 0x1c) + 0xc);
  }
  PostRaceStatsScreen__Init(param_1);
  PostRaceStatsScreen__Setup(param_1,param_1[0x4f]);
  *(undefined1 *)(param_1 + 8) = 1;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  if (param_1[3] == 0) {
LAB_0049bf7f:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0xaa68bfd4);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_0049bf7f;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_0049bf7f;
  }
  param_1[0x10] = iVar2;
  if (param_1[3] != 0) {
    iVar2 = FEngFindPackage();
    if (iVar2 != 0) {
      iVar2 = FUN_004ffb70();
      if (iVar2 != 0) goto LAB_0049bfdb;
    }
  }
  if (DAT_0073578c == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_004ef050(0xaa68bfce);
  }
LAB_0049bfdb:
  param_1[0x11] = iVar2;
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar2 == 0) || (iVar2 = *(int *)(iVar2 + 0x18), iVar2 == 0)) {
    if ((DAT_0073578c == 0) || (iVar1 = *(int *)(DAT_0073578c + 8), iVar1 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004fd1e0(iVar1 + 0xdc);
      if (iVar2 == 0) {
        iVar2 = FUN_004fd1e0(iVar1 + 0xec);
      }
    }
  }
  param_1[0x12] = iVar2;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x49c050 PostRaceStatsScreen::NotificationMessage

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__NotificationMessage(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0073578c;
  if (param_1 < 0x9120409f) {
    if (param_1 != 0x9120409e) {
      if ((param_1 != 0xc407210) && (param_1 != 0x911ab364)) {
        return;
      }
      if (DAT_0073578c == 0) {
        return;
      }
      iVar2 = FEPackageList__FindByName(&DAT_00746104);
      if (iVar2 == 0) {
        return;
      }
      if (*(int *)(iVar2 + 0x18) == 0) {
        return;
      }
      FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
      return;
    }
  }
  else if (param_1 != 0xb5971bf1) {
    if (param_1 != 0xc98356ba) {
      return;
    }
    FUN_00563cb0();
    return;
  }
  PostRaceStatsScreen__Scroll();
  return;
}


// ==== 0x49c0e0 PostRaceStatsScreen::Init

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__Init(int param_1)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  int *local_2c;
  int *local_28;
  int *local_24;
  byte local_20;
  byte local_1f [31];
  
  iVar5 = *(int *)(param_1 + 0xc);
  uVar4 = FEng__HashName();
  if (((((iVar5 == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
       (iVar5 = FUN_004ffb70(), iVar5 == 0)) &&
      ((DAT_0073578c == 0 || (iVar5 = FUN_004ef050(uVar4), iVar5 == 0)))) ||
     (*(int *)(iVar5 + 0x18) != 2)) {
    iVar5 = 0;
  }
  iVar9 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0x4c) = iVar5;
  uVar4 = FEng__HashName();
  if (((((iVar9 == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
       (iVar5 = FUN_004ffb70(), iVar5 == 0)) &&
      ((DAT_0073578c == 0 || (iVar5 = FUN_004ef050(uVar4), iVar5 == 0)))) ||
     (*(int *)(iVar5 + 0x18) != 2)) {
    iVar5 = 0;
  }
  iVar9 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0x50) = iVar5;
  uVar4 = FEng__HashName();
  if (((((iVar9 == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
       (iVar5 = FUN_004ffb70(), iVar5 == 0)) &&
      ((DAT_0073578c == 0 || (iVar5 = FUN_004ef050(uVar4), iVar5 == 0)))) ||
     (*(int *)(iVar5 + 0x18) != 2)) {
    iVar5 = 0;
  }
  iVar9 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0x54) = iVar5;
  uVar4 = FEng__HashName();
  if (((((iVar9 == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
       (iVar5 = FUN_004ffb70(), iVar5 == 0)) &&
      ((DAT_0073578c == 0 || (iVar5 = FUN_004ef050(uVar4), iVar5 == 0)))) ||
     (*(int *)(iVar5 + 0x18) != 2)) {
    iVar5 = 0;
  }
  iVar9 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0x120) = iVar5;
  uVar4 = FEng__HashName();
  if (((((iVar9 == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
       (iVar5 = FUN_004ffb70(), iVar5 == 0)) &&
      ((DAT_0073578c == 0 || (iVar5 = FUN_004ef050(uVar4), iVar5 == 0)))) ||
     (*(int *)(iVar5 + 0x18) != 2)) {
    iVar5 = 0;
  }
  *(int *)(param_1 + 0x124) = iVar5;
  local_28 = (int *)(param_1 + 0x80);
  local_2c = (int *)0x1;
  local_24 = (int *)0xa;
  do {
    bSPrintf_regdst(0x20,"LapNumber_%d",local_2c);
    iVar5 = -1;
    pbVar8 = &local_20;
    bVar3 = local_20;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      pbVar1 = pbVar8 + 1;
      iVar5 = iVar5 * 0x21 + (uint)bVar3;
      pbVar8 = pbVar8 + 1;
      bVar3 = *pbVar1;
    }
    iVar9 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049c343:
      if ((iVar9 == 0) || (iVar6 = FUN_004ef050(iVar5), iVar6 == 0)) goto LAB_0049c35c;
LAB_0049c356:
      if (*(int *)(iVar6 + 0x18) != 2) goto LAB_0049c35c;
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      iVar9 = DAT_0073578c;
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_0049c32c:
        if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar9 = DAT_0073578c, iVar6 == 0))
        goto LAB_0049c343;
        goto LAB_0049c356;
      }
      if (DAT_0073578c != 0) {
        iVar7 = *(int *)(DAT_0073578c + 8);
        if ((iVar7 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar7 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar7 + 0xec), iVar6 == 0)))) goto LAB_0049c343;
        goto LAB_0049c32c;
      }
LAB_0049c35c:
      iVar6 = 0;
    }
    local_28[-10] = iVar6;
    bSPrintf_regdst(0x20,"AllLapTimes_%d",local_2c);
    iVar5 = -1;
    pbVar8 = &local_20;
    bVar3 = local_20;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      pbVar1 = pbVar8 + 1;
      iVar5 = iVar5 * 0x21 + (uint)bVar3;
      pbVar8 = pbVar8 + 1;
      bVar3 = *pbVar1;
    }
    iVar9 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049c416:
      if ((iVar9 == 0) || (iVar6 = FUN_004ef050(iVar5), iVar6 == 0)) goto LAB_0049c42f;
LAB_0049c429:
      if (*(int *)(iVar6 + 0x18) != 2) goto LAB_0049c42f;
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      iVar9 = DAT_0073578c;
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_0049c3ff:
        if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar9 = DAT_0073578c, iVar6 == 0))
        goto LAB_0049c416;
        goto LAB_0049c429;
      }
      if (DAT_0073578c != 0) {
        iVar7 = *(int *)(DAT_0073578c + 8);
        if ((iVar7 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar7 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar7 + 0xec), iVar6 == 0)))) goto LAB_0049c416;
        goto LAB_0049c3ff;
      }
LAB_0049c42f:
      iVar6 = 0;
    }
    *local_28 = iVar6;
    bSPrintf_regdst(0x20,"PositionAfterEachLap_%d",local_2c);
    iVar5 = -1;
    pbVar8 = &local_20;
    bVar3 = local_20;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      pbVar1 = pbVar8 + 1;
      iVar5 = iVar5 * 0x21 + (uint)bVar3;
      pbVar8 = pbVar8 + 1;
      bVar3 = *pbVar1;
    }
    iVar9 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049c4e8:
      if ((iVar9 == 0) || (iVar6 = FUN_004ef050(iVar5), iVar6 == 0)) goto LAB_0049c501;
LAB_0049c4fb:
      if (*(int *)(iVar6 + 0x18) != 2) goto LAB_0049c501;
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      iVar9 = DAT_0073578c;
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_0049c4d1:
        if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar9 = DAT_0073578c, iVar6 == 0))
        goto LAB_0049c4e8;
        goto LAB_0049c4fb;
      }
      if (DAT_0073578c != 0) {
        iVar7 = *(int *)(DAT_0073578c + 8);
        if ((iVar7 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar7 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar7 + 0xec), iVar6 == 0)))) goto LAB_0049c4e8;
        goto LAB_0049c4d1;
      }
LAB_0049c501:
      iVar6 = 0;
    }
    local_28[10] = iVar6;
    local_28 = local_28 + 1;
    local_2c = (int *)((int)local_2c + 1);
    local_24 = (int *)((int)local_24 + -1);
  } while (local_24 != (int *)0x0);
  local_2c = (int *)(param_1 + 0xf8);
  local_28 = (int *)0x1;
  local_24 = (int *)0x9;
  do {
    bSPrintf_regdst(0x20,"DataName_%d",local_28);
    iVar5 = -1;
    pbVar8 = &local_20;
    bVar3 = local_20;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar5 = iVar5 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar8 + 1;
      pbVar8 = pbVar8 + 1;
      bVar3 = *pbVar1;
    }
    iVar9 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049c5f7:
      if ((iVar9 == 0) || (iVar6 = FUN_004ef050(iVar5), iVar6 == 0)) goto LAB_0049c610;
LAB_0049c60a:
      if (*(int *)(iVar6 + 0x18) != 2) goto LAB_0049c610;
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      iVar9 = DAT_0073578c;
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_0049c5e0:
        if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar9 = DAT_0073578c, iVar6 == 0))
        goto LAB_0049c5f7;
        goto LAB_0049c60a;
      }
      if (DAT_0073578c != 0) {
        iVar7 = *(int *)(DAT_0073578c + 8);
        if ((iVar7 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar7 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar7 + 0xec), iVar6 == 0)))) goto LAB_0049c5f7;
        goto LAB_0049c5e0;
      }
LAB_0049c610:
      iVar6 = 0;
    }
    local_2c[-10] = iVar6;
    bSPrintf_regdst(0x20,"Data_%d",local_28);
    iVar5 = -1;
    pbVar8 = &local_20;
    bVar3 = local_20;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      pbVar1 = pbVar8 + 1;
      iVar5 = iVar5 * 0x21 + (uint)bVar3;
      pbVar8 = pbVar8 + 1;
      bVar3 = *pbVar1;
    }
    iVar9 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049c6ca:
      if ((iVar9 == 0) || (iVar6 = FUN_004ef050(iVar5), iVar6 == 0)) goto LAB_0049c6e3;
LAB_0049c6dd:
      if (*(int *)(iVar6 + 0x18) != 2) goto LAB_0049c6e3;
    }
    else {
      iVar6 = FEPackageList__FindByName(&DAT_00746104);
      iVar9 = DAT_0073578c;
      if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
LAB_0049c6b3:
        if ((iVar6 == 0) || (iVar6 = FUN_004ffb70(), iVar9 = DAT_0073578c, iVar6 == 0))
        goto LAB_0049c6ca;
        goto LAB_0049c6dd;
      }
      if (DAT_0073578c != 0) {
        iVar7 = *(int *)(DAT_0073578c + 8);
        if ((iVar7 == 0) ||
           ((iVar6 = FUN_004fd1e0(iVar7 + 0xdc), iVar6 == 0 &&
            (iVar6 = FUN_004fd1e0(iVar7 + 0xec), iVar6 == 0)))) goto LAB_0049c6ca;
        goto LAB_0049c6b3;
      }
LAB_0049c6e3:
      iVar6 = 0;
    }
    *local_2c = iVar6;
    local_2c = local_2c + 1;
    local_28 = (int *)((int)local_28 + 1);
    local_24 = (int *)((int)local_24 + -1);
  } while (local_24 != (int *)0x0);
  iVar5 = 0;
  local_24 = (int *)(param_1 + 0x128);
  do {
    iVar5 = iVar5 + 1;
    bSPrintf_regdst(0x20,"TextBack_%d",iVar5);
    iVar9 = -1;
    pbVar8 = &local_20;
    bVar3 = local_20;
    while (bVar3 != 0) {
      if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
        bVar3 = bVar3 - 0x20;
      }
      iVar9 = iVar9 * 0x21 + (uint)bVar3;
      pbVar1 = pbVar8 + 1;
      pbVar8 = pbVar8 + 1;
      bVar3 = *pbVar1;
    }
    iVar6 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049c7d6:
      if ((iVar6 == 0) || (iVar7 = FUN_004ef050(iVar9), iVar7 == 0)) goto LAB_0049c7ef;
LAB_0049c7e9:
      if (*(int *)(iVar7 + 0x18) != 1) goto LAB_0049c7ef;
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar6 = DAT_0073578c;
      if ((iVar7 != 0) && (iVar7 = *(int *)(iVar7 + 0x18), iVar7 != 0)) {
LAB_0049c7bf:
        if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar6 = DAT_0073578c, iVar7 == 0))
        goto LAB_0049c7d6;
        goto LAB_0049c7e9;
      }
      if (DAT_0073578c != 0) {
        iVar2 = *(int *)(DAT_0073578c + 8);
        if ((iVar2 == 0) ||
           ((iVar7 = FUN_004fd1e0(iVar2 + 0xdc), iVar7 == 0 &&
            (iVar7 = FUN_004fd1e0(iVar2 + 0xec), iVar7 == 0)))) goto LAB_0049c7d6;
        goto LAB_0049c7bf;
      }
LAB_0049c7ef:
      iVar7 = 0;
    }
    *local_24 = iVar7;
    local_24 = local_24 + 1;
    if (4 < iVar5) {
      return;
    }
  } while( true );
}


// ==== 0x49c820 PostRaceStatsScreen::Setup

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__Setup(int param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  char *pcVar8;
  uint uVar9;
  int extraout_EDX;
  int extraout_EDX_00;
  undefined4 *puVar10;
  int iVar11;
  
  PostRaceStatsScreen__HideLaps();
  puVar10 = (undefined4 *)(param_1 + 0xf8);
  iVar11 = 9;
  do {
    FEObject__SetInvisible(puVar10[-10]);
    FEObject__SetInvisible(*puVar10);
    puVar10 = puVar10 + 1;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  if (*(int *)(DAT_0073619c + 0x24) < param_2) {
    uVar7 = 0;
  }
  else {
    uVar7 = *(undefined4 *)(DAT_0073619c + 0x51c + param_2 * 4);
  }
  if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
    if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
      PostRaceStatsScreen__SetupCircuit(param_1,uVar7);
    }
    else {
      PostRaceStatsScreen__SetupDrift(uVar7);
    }
  }
  else {
    PostRaceStatsScreen__SetupDrag(param_1,uVar7);
  }
  pcVar8 = "mouse_over_L";
  iVar11 = -1;
  bVar2 = 0x6d;
  do {
    if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
      bVar2 = bVar2 - 0x20;
    }
    uVar9 = (uint)bVar2;
    bVar2 = pcVar8[1];
    iVar11 = iVar11 * 0x21 + uVar9;
    pcVar8 = pcVar8 + 1;
  } while (bVar2 != 0);
  iVar6 = DAT_0073578c;
  if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049c947:
    iVar4 = 0;
    if ((iVar6 != 0) && (iVar5 = FUN_004ef050(iVar11), iVar4 = DAT_0073578c, iVar5 != 0)) {
LAB_0049c95a:
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
      iVar4 = DAT_0073578c;
      if (*(int *)(iVar5 + 0x18) == 5) {
        uVar7 = *(undefined4 *)(iVar5 + 0x60);
        iVar11 = *(int *)(iVar5 + 0x5c);
        if (0 < iVar11) {
          do {
            FEObject__SetVisible(uVar7);
            uVar7 = *(undefined4 *)(extraout_EDX + 4);
            iVar11 = iVar11 + -1;
            iVar4 = DAT_0073578c;
          } while (iVar11 != 0);
        }
      }
    }
  }
  else {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    iVar6 = DAT_0073578c;
    if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x18), iVar4 != 0)) {
LAB_0049c930:
      if ((iVar4 == 0) || (iVar5 = FUN_004ffb70(), iVar6 = DAT_0073578c, iVar5 == 0))
      goto LAB_0049c947;
      goto LAB_0049c95a;
    }
    iVar4 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar5 = *(int *)(DAT_0073578c + 8);
      if ((iVar5 == 0) ||
         ((iVar4 = FUN_004fd1e0(iVar5 + 0xdc), iVar4 == 0 &&
          (iVar4 = FUN_004fd1e0(iVar5 + 0xec), iVar4 == 0)))) goto LAB_0049c947;
      goto LAB_0049c930;
    }
  }
  pcVar8 = "mouse_over_R";
  iVar11 = -1;
  bVar2 = 0x6d;
  do {
    if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
      bVar2 = bVar2 - 0x20;
    }
    iVar11 = iVar11 * 0x21 + (uint)bVar2;
    bVar2 = pcVar8[1];
    pcVar8 = pcVar8 + 1;
  } while (bVar2 != 0);
  if (*(int *)(param_1 + 0xc) == 0) {
LAB_0049ca30:
    iVar6 = 0;
    if ((iVar4 == 0) || (iVar5 = FUN_004ef050(iVar11), iVar6 = DAT_0073578c, iVar5 == 0))
    goto LAB_0049ca79;
  }
  else {
    iVar6 = FEPackageList__FindByName(&DAT_00746104);
    iVar4 = DAT_0073578c;
    if ((iVar6 == 0) || (iVar6 = *(int *)(iVar6 + 0x18), iVar6 == 0)) {
      iVar6 = DAT_0073578c;
      if (DAT_0073578c == 0) goto LAB_0049ca79;
      iVar5 = *(int *)(DAT_0073578c + 8);
      if ((iVar5 == 0) ||
         ((iVar6 = FUN_004fd1e0(iVar5 + 0xdc), iVar6 == 0 &&
          (iVar6 = FUN_004fd1e0(iVar5 + 0xec), iVar6 == 0)))) goto LAB_0049ca30;
    }
    if ((iVar6 == 0) || (iVar5 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar5 == 0))
    goto LAB_0049ca30;
  }
  *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000;
  iVar6 = DAT_0073578c;
  if (*(int *)(iVar5 + 0x18) == 5) {
    uVar7 = *(undefined4 *)(iVar5 + 0x60);
    iVar11 = *(int *)(iVar5 + 0x5c);
    if (0 < iVar11) {
      do {
        FEObject__SetVisible(uVar7);
        uVar7 = *(undefined4 *)(extraout_EDX_00 + 4);
        iVar11 = iVar11 + -1;
        iVar6 = DAT_0073578c;
      } while (iVar11 != 0);
    }
  }
LAB_0049ca79:
  if (param_2 == 1) {
    pcVar8 = "mouse_over_L";
    iVar11 = -1;
    bVar2 = 0x6d;
    do {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      uVar9 = (uint)bVar2;
      bVar2 = pcVar8[1];
      iVar11 = iVar11 * 0x21 + uVar9;
      pcVar8 = pcVar8 + 1;
    } while (bVar2 != 0);
    if (((*(int *)(param_1 + 0xc) == 0) ||
        (iVar4 = FEngFindPackage(), iVar6 = DAT_0073578c, iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar6 = DAT_0073578c, iVar4 == 0)) {
      if (iVar6 == 0) {
        iVar4 = 0;
        iVar6 = 0;
      }
      else {
        iVar4 = FUN_004ef050(iVar11);
        iVar6 = DAT_0073578c;
      }
    }
    FEObject__SetInvisible(iVar4);
    if (*(int *)(DAT_0073619c + 0x24) != 1) {
      return;
    }
    iVar11 = *(int *)(param_1 + 0xc);
    pcVar8 = "mouse_over_R";
    iVar4 = -1;
    bVar2 = 0x6d;
    do {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      uVar9 = (uint)bVar2;
      bVar2 = pcVar8[1];
      iVar4 = iVar4 * 0x21 + uVar9;
      pcVar8 = pcVar8 + 1;
    } while (bVar2 != 0);
  }
  else {
    if (param_2 != *(int *)(DAT_0073619c + 0x24)) {
      return;
    }
    iVar11 = *(int *)(param_1 + 0xc);
    pcVar8 = "mouse_over_R";
    iVar4 = -1;
    uVar9 = 0x6d;
    do {
      cVar3 = (char)uVar9;
      if (('`' < cVar3) && (cVar3 < '{')) {
        uVar9 = (uint)(byte)(cVar3 - 0x20);
      }
      iVar4 = iVar4 * 0x21 + uVar9;
      pbVar1 = (byte *)(pcVar8 + 1);
      uVar9 = (uint)*pbVar1;
      pcVar8 = pcVar8 + 1;
    } while (*pbVar1 != 0);
  }
  if (((iVar11 == 0) || (iVar11 = FEngFindPackage(), iVar6 = DAT_0073578c, iVar11 == 0)) ||
     (iVar11 = FUN_004ffb70(), iVar6 = DAT_0073578c, iVar11 == 0)) {
    if (iVar6 != 0) {
      uVar7 = FUN_004ef050(iVar4);
      FEObject__SetInvisible(uVar7);
      return;
    }
    iVar11 = 0;
  }
  FEObject__SetInvisible(iVar11);
  return;
}


// ==== 0x49cbd0 PostRaceStatsScreen::Scroll

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__Scroll(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_ESI;
  
  iVar1 = *(int *)(DAT_0073619c + 0x24);
  iVar2 = *(int *)(unaff_ESI + 0x13c);
  if (unaff_EBX == -0x6edfbf62) {
    *(int *)(unaff_ESI + 0x13c) = iVar2 + -1;
    if (iVar2 + -1 < 1) {
      *(undefined4 *)(unaff_ESI + 0x13c) = 1;
    }
  }
  else if ((unaff_EBX == -0x4a68e40f) &&
          (*(int *)(unaff_ESI + 0x13c) = iVar2 + 1, iVar1 < iVar2 + 1)) {
    *(int *)(unaff_ESI + 0x13c) = iVar1;
  }
  PostRaceStatsScreen__Setup(unaff_ESI,*(undefined4 *)(unaff_ESI + 0x13c));
  if (iVar2 != *(int *)(unaff_ESI + 0x13c)) {
    if (unaff_EBX == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(unaff_ESI + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(unaff_ESI + 0xc));
  }
  return;
}


// ==== 0x49cc70 PostRaceStatsScreen::SetupDrag

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__SetupDrag(int param_1,undefined4 param_2)

{
  int iVar1;
  int extraout_EDX;
  undefined4 uVar2;
  int extraout_EDX_00;
  int iVar3;
  int *piVar4;
  
  iVar1 = param_1;
  PostRaceStatsScreen__DrawRacerName(param_1);
  FEObject__SetFormattedText(&PTR_FUN_006c7804,*(undefined4 *)(param_1 + 0x13c));
  PostRaceStatsScreen__HideLaps();
  piVar4 = (int *)(param_1 + 0xf8);
  param_1 = 5;
  do {
    iVar3 = piVar4[-10];
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
    iVar3 = *piVar4;
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
    piVar4 = piVar4 + 1;
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  PostRaceStatsScreen__DrawFinishTime(iVar1,param_2);
  PostRaceStatsScreen__DrawTimeBehind(iVar1);
  PostRaceStatsScreen__DrawMaxSpeed(param_2);
  PostRaceStatsScreen__DrawNumLapsLed(param_2);
  PostRaceStatsScreen__DrawPercentage(param_2);
  PostRaceStatsScreen__SetupRepWonLoss();
  return;
}


// ==== 0x49cd90 PostRaceStatsScreen::SetupDrift

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__SetupDrift(int param_1)

{
  undefined4 *puVar1;
  int in_EAX;
  int extraout_EDX;
  undefined4 uVar2;
  int extraout_EDX_00;
  int iVar3;
  int *piVar4;
  bool bVar5;
  int local_4;
  
  PostRaceStatsScreen__DrawRacerName(in_EAX);
  FEObject__SetFormattedText(&PTR_FUN_006c7804,*(undefined4 *)(in_EAX + 0x13c));
  piVar4 = (int *)(in_EAX + 0xf8);
  local_4 = 2;
  do {
    iVar3 = piVar4[-10];
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
    iVar3 = *piVar4;
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
    piVar4 = piVar4 + 1;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  PostRaceStatsScreen__ShowLaps(in_EAX);
  PostRaceStatsScreen__DrawLapScores(in_EAX);
  iVar3 = *(int *)(in_EAX + 0xd0);
  if (iVar3 != 0) {
    *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | 0x400000;
    puVar1 = DAT_00735710;
    bVar5 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar3 + 0x5c) = 0xd7d8ca79;
    if (bVar5) {
      (**(code **)*puVar1)(iVar3);
    }
    *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) & 0xfffffffd | 0x400000;
  }
  FEObject__SetFormattedText
            (&DAT_006ca778,*(undefined4 *)(&DAT_00777cbc + *(char *)(param_1 + 10) * 0x15c));
  PostRaceStatsScreen__DrawLongestDrift(param_1);
  PostRaceStatsScreen__SetupRepWonLoss();
  return;
}


// ==== 0x49cee0 PostRaceStatsScreen::SetupCircuit

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__SetupCircuit(int param_1,int param_2)

{
  undefined4 *puVar1;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  int extraout_EDX_03;
  undefined4 uVar2;
  int extraout_EDX_04;
  int *piVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  PostRaceStatsScreen__DrawRacerName(param_1);
  FEObject__SetFormattedText(&PTR_FUN_006c7804,*(undefined4 *)(param_1 + 0x13c));
  piVar3 = (int *)(param_1 + 0xf8);
  iVar4 = 5;
  do {
    iVar5 = piVar3[-10];
    if ((iVar5 != 0) &&
       (*(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar5 + 0x18) == 5)) {
      uVar2 = *(undefined4 *)(iVar5 + 0x60);
      iVar5 = *(int *)(iVar5 + 0x5c);
      if (0 < iVar5) {
        do {
          FEObject__SetVisible(uVar2);
          uVar2 = *(undefined4 *)(extraout_EDX + 4);
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
    }
    iVar5 = *piVar3;
    if ((iVar5 != 0) &&
       (*(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar5 + 0x18) == 5)) {
      uVar2 = *(undefined4 *)(iVar5 + 0x60);
      iVar5 = *(int *)(iVar5 + 0x5c);
      if (0 < iVar5) {
        do {
          FEObject__SetVisible(uVar2);
          uVar2 = *(undefined4 *)(extraout_EDX_00 + 4);
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
    }
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  PostRaceStatsScreen__ShowLaps(param_1);
  PostRaceStatsScreen__DrawLapTimes(param_1);
  iVar5 = 0;
  iVar4 = DAT_00736168;
  if (0 < DAT_0073616c) {
    do {
      if (*(short *)(iVar4 + 0x6c) == DAT_0078a2f0) {
        if ((*(byte *)(iVar4 + 0x74) & 4) != 0) {
          PostRaceStatsScreen__DrawFinishTime(param_1,param_2);
          PostRaceStatsScreen__DrawTimeBehind(param_1);
          PostRaceStatsScreen__DrawMaxSpeed(param_2);
          PostRaceStatsScreen__DrawAverageSpeed(param_2);
          PostRaceStatsScreen__DrawOdometer(param_2);
          goto LAB_0049d176;
        }
        break;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0xfc;
    } while (iVar5 < DAT_0073616c);
  }
  iVar4 = *(int *)(param_1 + 0xe4);
  if ((iVar4 != 0) &&
     (*(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffe | 0x400000,
     *(int *)(iVar4 + 0x18) == 5)) {
    uVar2 = *(undefined4 *)(iVar4 + 0x60);
    iVar4 = *(int *)(iVar4 + 0x5c);
    if (0 < iVar4) {
      do {
        FEObject__SetVisible(uVar2);
        uVar2 = *(undefined4 *)(extraout_EDX_01 + 4);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  iVar4 = *(int *)(param_1 + 0x10c);
  if ((iVar4 != 0) &&
     (*(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffe | 0x400000,
     *(int *)(iVar4 + 0x18) == 5)) {
    uVar2 = *(undefined4 *)(iVar4 + 0x60);
    iVar4 = *(int *)(iVar4 + 0x5c);
    if (0 < iVar4) {
      do {
        FEObject__SetVisible(uVar2);
        uVar2 = *(undefined4 *)(extraout_EDX_02 + 4);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  iVar4 = *(int *)(param_1 + 0xe8);
  if ((iVar4 != 0) &&
     (*(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffe | 0x400000,
     *(int *)(iVar4 + 0x18) == 5)) {
    uVar2 = *(undefined4 *)(iVar4 + 0x60);
    iVar4 = *(int *)(iVar4 + 0x5c);
    if (0 < iVar4) {
      do {
        FEObject__SetVisible(uVar2);
        uVar2 = *(undefined4 *)(extraout_EDX_03 + 4);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  iVar4 = *(int *)(param_1 + 0x110);
  if ((iVar4 != 0) &&
     (*(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffe | 0x400000,
     *(int *)(iVar4 + 0x18) == 5)) {
    uVar2 = *(undefined4 *)(iVar4 + 0x60);
    iVar4 = *(int *)(iVar4 + 0x5c);
    if (0 < iVar4) {
      do {
        FEObject__SetVisible(uVar2);
        uVar2 = *(undefined4 *)(extraout_EDX_04 + 4);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  PostRaceStatsScreen__DrawFinishTime(param_1,param_2);
  PostRaceStatsScreen__DrawTimeBehind(param_1);
  PostRaceStatsScreen__DrawBestLapTime(param_1,param_2);
  PostRaceStatsScreen__DrawMaxSpeed(param_2);
  PostRaceStatsScreen__DrawAverageSpeed(param_2);
  PostRaceStatsScreen__DrawOdometer(param_2);
  iVar4 = *(int *)(param_1 + 0xe8);
  if (iVar4 != 0) {
    *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
    puVar1 = DAT_00735710;
    bVar6 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar4 + 0x5c) = 0xadbfd917;
    if (bVar6) {
      (**(code **)*puVar1)(iVar4);
    }
    *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffd | 0x400000;
  }
  FEObject__SetFormattedText
            (&PTR_FUN_006c7968,*(undefined4 *)(&DAT_00777c1c + *(char *)(param_2 + 10) * 0x15c));
LAB_0049d176:
  PostRaceStatsScreen__SetupRepWonLoss();
  return;
}


// ==== 0x49d1d0 PostRaceStatsScreen::ShowLaps

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__ShowLaps(int param_1)

{
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  int extraout_EDX_03;
  undefined4 uVar1;
  int extraout_EDX_04;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = (int *)(param_1 + 0x80);
  iVar2 = 10;
  do {
    iVar3 = piVar4[-10];
    if ((iVar3 != 0) &&
       (*(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar3 + 0x18) == 5)) {
      uVar1 = *(undefined4 *)(iVar3 + 0x60);
      iVar3 = *(int *)(iVar3 + 0x5c);
      if (0 < iVar3) {
        do {
          FEObject__SetVisible(uVar1);
          uVar1 = *(undefined4 *)(extraout_EDX + 4);
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
    iVar3 = *piVar4;
    if ((iVar3 != 0) &&
       (*(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar3 + 0x18) == 5)) {
      uVar1 = *(undefined4 *)(iVar3 + 0x60);
      iVar3 = *(int *)(iVar3 + 0x5c);
      if (0 < iVar3) {
        do {
          FEObject__SetVisible(uVar1);
          uVar1 = *(undefined4 *)(extraout_EDX_00 + 4);
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
    iVar3 = piVar4[10];
    if ((iVar3 != 0) &&
       (*(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar3 + 0x18) == 5)) {
      uVar1 = *(undefined4 *)(iVar3 + 0x60);
      iVar3 = *(int *)(iVar3 + 0x5c);
      if (0 < iVar3) {
        do {
          FEObject__SetVisible(uVar1);
          uVar1 = *(undefined4 *)(extraout_EDX_01 + 4);
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
    piVar4 = piVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  piVar4 = (int *)(param_1 + 0x128);
  iVar2 = 5;
  do {
    iVar3 = *piVar4;
    if ((iVar3 != 0) &&
       (*(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) & 0xfffffffe | 0x400000,
       *(int *)(iVar3 + 0x18) == 5)) {
      uVar1 = *(undefined4 *)(iVar3 + 0x60);
      iVar3 = *(int *)(iVar3 + 0x5c);
      if (0 < iVar3) {
        do {
          FEObject__SetVisible(uVar1);
          uVar1 = *(undefined4 *)(extraout_EDX_02 + 4);
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
    piVar4 = piVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = *(int *)(param_1 + 0x120);
  if ((iVar2 != 0) &&
     (*(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xfffffffe | 0x400000,
     *(int *)(iVar2 + 0x18) == 5)) {
    uVar1 = *(undefined4 *)(iVar2 + 0x60);
    iVar2 = *(int *)(iVar2 + 0x5c);
    if (0 < iVar2) {
      do {
        FEObject__SetVisible(uVar1);
        uVar1 = *(undefined4 *)(extraout_EDX_03 + 4);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  iVar2 = *(int *)(param_1 + 0x124);
  if ((iVar2 != 0) &&
     (*(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xfffffffe | 0x400000,
     *(int *)(iVar2 + 0x18) == 5)) {
    uVar1 = *(undefined4 *)(iVar2 + 0x60);
    iVar2 = *(int *)(iVar2 + 0x5c);
    if (0 < iVar2) {
      do {
        FEObject__SetVisible(uVar1);
        uVar1 = *(undefined4 *)(extraout_EDX_04 + 4);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  return;
}


// ==== 0x49d370 PostRaceStatsScreen::HideLaps

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__HideLaps(void)

{
  int unaff_EBX;
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(unaff_EBX + 0x80);
  iVar2 = 10;
  do {
    FEObject__SetInvisible(puVar1[-10]);
    FEObject__SetInvisible(*puVar1);
    FEObject__SetInvisible(puVar1[10]);
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined4 *)(unaff_EBX + 0x128);
  iVar2 = 5;
  do {
    FEObject__SetInvisible(*puVar1);
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FEObject__SetInvisible(*(undefined4 *)(unaff_EBX + 0x120));
  FEObject__SetInvisible(*(undefined4 *)(unaff_EBX + 0x124));
  return;
}


// ==== 0x49d3e0 PostRaceStatsScreen::DrawRacerName

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__DrawRacerName(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int *unaff_EDI;
  char local_20 [32];
  
  iVar1 = *unaff_EDI;
  GetCarModelNameHash();
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  iVar5 = 0x20;
  pcVar4 = local_20;
  do {
    cVar2 = pcVar4[iVar3 - (int)local_20];
    iVar5 = iVar5 + -1;
    *pcVar4 = cVar2;
    if (cVar2 == '\0') break;
    pcVar4 = pcVar4 + 1;
  } while (iVar5 != 0);
  if ((*unaff_EDI == 0) || (iVar3 = *(int *)(*unaff_EDI + 0x18), iVar3 == 0)) {
    cVar2 = FUN_0043a2e0();
    if (cVar2 == '\0') {
      iVar3 = *(int *)(iVar1 + 0x14) + 0x73c;
    }
    else {
      iVar3 = Race__GetPlayer((int)*(short *)(*unaff_EDI + 10));
      iVar3 = iVar3 + 0x19;
    }
  }
  else {
    cVar2 = FUN_0043a2e0();
    if (cVar2 == '\0') {
      iVar3 = iVar3 + 0x34;
    }
    else {
      iVar3 = DAT_0077b244 + 0x19;
    }
  }
  FEObject__SetFormattedText("%s - %s",iVar3,local_20);
  return;
}


// ==== 0x49d4c0 PostRaceStatsScreen::DrawFinishTime

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__DrawFinishTime(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int unaff_EBX;
  bool bVar3;
  undefined1 local_20 [32];
  
  iVar1 = *(int *)(param_1 + 0xd0 + unaff_EBX * 4);
  puVar2 = DAT_00735710;
  if (iVar1 != 0) {
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
    puVar2 = DAT_00735710;
    bVar3 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar1 + 0x5c) = 0xf9d7f4c2;
    if (bVar3) {
      (**(code **)*puVar2)(iVar1);
      puVar2 = DAT_00735710;
    }
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffd | 0x400000;
  }
  if ((float)*(int *)(&DAT_00777b80 + *(char *)(param_2 + 10) * 0x15c) * 0.00025 <= 0.0) {
    iVar1 = *(int *)(param_1 + 0xf8 + unaff_EBX * 4);
    if (iVar1 != 0) {
      *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
      *(undefined4 *)(iVar1 + 0x5c) = 0x61c9b7a2;
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)*puVar2)(iVar1);
      }
      *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffd | 0x400000;
    }
    return;
  }
  FUN_00586580(local_20);
  FEObject__SetFormattedText(local_20);
  return;
}


// ==== 0x49d5b0 PostRaceStatsScreen::DrawTimeBehind

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__DrawTimeBehind(int param_1)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  undefined4 *puVar3;
  int unaff_EBX;
  bool bVar4;
  undefined1 auStack_20 [32];
  
  iVar1 = *(int *)(param_1 + 0xd0 + unaff_EBX * 4);
  puVar3 = DAT_00735710;
  if (iVar1 != 0) {
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
    puVar3 = DAT_00735710;
    bVar4 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar1 + 0x5c) = 0xab44ed8b;
    if (bVar4) {
      (**(code **)*puVar3)(iVar1);
      puVar3 = DAT_00735710;
    }
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffd | 0x400000;
  }
  if (*(short *)(in_EAX + 0x10) == 1) {
    if ((in_EAX != *(int *)(DAT_0073619c + 0x520)) &&
       ((float)*(int *)(&DAT_00777b80 + *(char *)(in_EAX + 10) * 0x15c) * 0.00025 < 0.0 ==
        ((float)*(int *)(&DAT_00777b80 + *(char *)(in_EAX + 10) * 0x15c) * 0.00025 == 0.0))) {
      FUN_00586580(auStack_20);
      FEObject__SetFormattedText(auStack_20);
      return;
    }
    iVar1 = *(int *)(param_1 + 0xf8 + unaff_EBX * 4);
    if (iVar1 != 0) {
      *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
      *(undefined4 *)(iVar1 + 0x5c) = 0x61c9b7a2;
      if (puVar3 != (undefined4 *)0x0) {
        (**(code **)*puVar3)(iVar1);
      }
      *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffd | 0x400000;
    }
  }
  else {
    switch(*(short *)(in_EAX + 0x10)) {
    case 3:
      uVar2 = 0x5d82dba2;
      break;
    default:
      uVar2 = 0xd4293449;
      break;
    case 6:
      uVar2 = 0x1e66364;
      break;
    case 7:
      uVar2 = 0xb7b75185;
      break;
    case 9:
      uVar2 = 0x1ce129e0;
      break;
    case 10:
      uVar2 = 0xa7db717f;
    }
    iVar1 = *(int *)(param_1 + 0xf8 + unaff_EBX * 4);
    if (iVar1 != 0) {
      *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
      *(undefined4 *)(iVar1 + 0x5c) = uVar2;
      if (puVar3 != (undefined4 *)0x0) {
        (**(code **)*puVar3)(iVar1);
      }
      *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffd | 0x400000;
      return;
    }
  }
  return;
}


// ==== 0x49d760 PostRaceStatsScreen::DrawLapTimes

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__DrawLapTimes(int param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  bool bVar6;
  int local_2c;
  undefined1 local_20 [32];
  
  iVar4 = *(char *)(in_EAX + 10) * 0x15c;
  iVar3 = 0;
  iVar1 = 0;
  iVar2 = DAT_00736168;
  if (0 < DAT_0073616c) {
    do {
      if (*(short *)(iVar2 + 0x6c) == DAT_0078a2f0) {
        if ((*(byte *)(iVar2 + 0x74) & 4) != 0) {
          iVar2 = *(int *)(param_1 + 0x120);
          iVar3 = 1;
          if (iVar2 != 0) {
            *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
            puVar5 = DAT_00735710;
            bVar6 = DAT_00735710 != (undefined4 *)0x0;
            *(undefined4 *)(iVar2 + 0x5c) = 0x174cc8dc;
            if (bVar6) {
              (**(code **)*puVar5)(iVar2);
            }
            *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xfffffffd | 0x400000;
          }
          FUN_00586580(local_20);
          FEObject__SetFormattedText(local_20);
          FEObject__SetFormattedText(&PTR_FUN_006c7968,*(undefined4 *)(&DAT_00777bf4 + iVar4));
          goto LAB_0049d8ec;
        }
        break;
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0xfc;
    } while (iVar1 < DAT_0073616c);
  }
  if (*(int *)(&DAT_00777b7c + iVar4) == 1) {
    local_2c = DAT_0078a31c;
  }
  else {
    local_2c = *(int *)(&DAT_00777bec + iVar4);
  }
  if (0 < local_2c) {
    puVar5 = (undefined4 *)(&DAT_00777bf4 + iVar4);
    do {
      iVar3 = iVar3 + 1;
      FEObject__SetFormattedText(&PTR_FUN_006c7968,iVar3);
      FUN_00586580(local_20);
      FEObject__SetFormattedText(local_20);
      FEObject__SetFormattedText(&PTR_FUN_006c7968,*puVar5);
      puVar5 = puVar5 + 1;
    } while (iVar3 < local_2c);
    if (9 < iVar3) {
      return;
    }
  }
LAB_0049d8ec:
  puVar5 = (undefined4 *)(param_1 + 0x80 + iVar3 * 4);
  do {
    FEObject__SetInvisible(puVar5[-10]);
    FEObject__SetInvisible(*puVar5);
    FEObject__SetInvisible(puVar5[10]);
    FEObject__SetInvisible(*(undefined4 *)(param_1 + 0x128 + (iVar3 / 2) * 4));
    iVar3 = iVar3 + 1;
    puVar5 = puVar5 + 1;
  } while (iVar3 < 10);
  return;
}


// ==== 0x49d940 PostRaceStatsScreen::DrawLapScores

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__DrawLapScores(int param_1)

{
  char cVar1;
  int in_EAX;
  undefined4 *puVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = *(int *)(param_1 + 0x120);
  cVar1 = *(char *)(in_EAX + 10);
  if (iVar3 != 0) {
    *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | 0x400000;
    puVar2 = DAT_00735710;
    bVar4 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar3 + 0x5c) = 0xf0952942;
    if (bVar4) {
      (**(code **)*puVar2)(iVar3);
    }
    *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) & 0xfffffffd | 0x400000;
  }
  FEObject__SetInvisible(*(undefined4 *)(param_1 + 0x124));
  iVar3 = 0;
  if (0 < DAT_0078a31c) {
    puVar2 = (undefined4 *)(&DAT_00777c94 + cVar1 * 0x15c);
    do {
      iVar3 = iVar3 + 1;
      FEObject__SetFormattedText(&PTR_FUN_006c7968,iVar3);
      FEObject__SetFormattedText(&DAT_006ca778,puVar2[-0x15]);
      FEObject__SetFormattedText(&DAT_006ca778,*puVar2);
      puVar2 = puVar2 + 1;
    } while (iVar3 < DAT_0078a31c);
    if (9 < iVar3) {
      return;
    }
  }
  puVar2 = (undefined4 *)(param_1 + 0x80 + iVar3 * 4);
  do {
    FEObject__SetInvisible(puVar2[-10]);
    FEObject__SetInvisible(*puVar2);
    FEObject__SetInvisible(puVar2[10]);
    FEObject__SetInvisible(*(undefined4 *)(param_1 + 0x128 + (iVar3 / 2) * 4));
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar3 < 10);
  return;
}


// ==== 0x49da50 PostRaceStatsScreen::DrawBestLapTime

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__DrawBestLapTime(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int unaff_EBX;
  bool bVar3;
  undefined1 local_20 [32];
  
  iVar1 = *(int *)(param_1 + 0xd0 + unaff_EBX * 4);
  puVar2 = DAT_00735710;
  if (iVar1 != 0) {
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
    puVar2 = DAT_00735710;
    bVar3 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar1 + 0x5c) = 0xae280d3d;
    if (bVar3) {
      (**(code **)*puVar2)(iVar1);
      puVar2 = DAT_00735710;
    }
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffd | 0x400000;
  }
  if ((float)*(int *)(&DAT_00777b84 + *(char *)(param_2 + 10) * 0x15c) * 0.00025 <= 0.0) {
    iVar1 = *(int *)(param_1 + 0xf8 + unaff_EBX * 4);
    if (iVar1 != 0) {
      *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
      *(undefined4 *)(iVar1 + 0x5c) = 0x61c9b7a2;
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)*puVar2)(iVar1);
      }
      *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffd | 0x400000;
    }
    return;
  }
  FUN_00586580(local_20);
  FEObject__SetFormattedText(local_20);
  return;
}


// ==== 0x49db30 PostRaceStatsScreen::DrawMaxSpeed

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__DrawMaxSpeed(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_EDI;
  bool bVar3;
  undefined1 local_8 [8];
  
  iVar2 = *(int *)(unaff_EBX + 0xd0 + unaff_EDI * 4);
  if (iVar2 != 0) {
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
    puVar1 = DAT_00735710;
    bVar3 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar2 + 0x5c) = 0x5d304669;
    if (bVar3) {
      (**(code **)*puVar1)(iVar2);
    }
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xfffffffd | 0x400000;
  }
  if (DAT_0078a3f5 == '\x01') {
    FUN_0059fc90(*(float *)(&DAT_00777b8c + *(char *)(param_1 + 10) * 0x15c) * 3.6);
    iVar2 = LanguageStrings__FindByHash();
    if (iVar2 == 0) {
      iVar2 = LanguageStrings__FindByHash();
    }
  }
  else {
    FUN_0059fc90(*(float *)(&DAT_00777b8c + *(char *)(param_1 + 10) * 0x15c) * 2.237);
    iVar2 = LanguageStrings__FindByHash();
    if (iVar2 == 0) {
      iVar2 = LanguageStrings__FindByHash();
    }
  }
  FEObject__SetFormattedText("%s %s",local_8,iVar2);
  return;
}


// ==== 0x49dc20 PostRaceStatsScreen::DrawAverageSpeed

/* [canon] hud med (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__DrawAverageSpeed(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_EDI;
  bool bVar3;
  undefined1 local_8 [8];
  
  iVar2 = *(int *)(unaff_EBX + 0xd0 + unaff_EDI * 4);
  if (iVar2 != 0) {
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
    puVar1 = DAT_00735710;
    bVar3 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar2 + 0x5c) = 0x5f38e63e;
    if (bVar3) {
      (**(code **)*puVar1)(iVar2);
    }
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xfffffffd | 0x400000;
  }
  if (DAT_0078a3f5 == '\x01') {
    FUN_0059fc90(*(float *)(&DAT_00777b90 + *(char *)(param_1 + 10) * 0x15c) * 3.6);
    iVar2 = LanguageStrings__FindByHash();
    if (iVar2 == 0) {
      iVar2 = LanguageStrings__FindByHash();
    }
  }
  else {
    FUN_0059fc90(*(float *)(&DAT_00777b90 + *(char *)(param_1 + 10) * 0x15c) * 2.237);
    iVar2 = LanguageStrings__FindByHash();
    if (iVar2 == 0) {
      iVar2 = LanguageStrings__FindByHash();
    }
  }
  FEObject__SetFormattedText("%s %s",local_8,iVar2);
  return;
}


// ==== 0x49dd10 PostRaceStatsScreen::DrawOdometer

/* [canon] hud med (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__DrawOdometer(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_EDI;
  bool bVar3;
  undefined1 local_8 [8];
  
  iVar2 = *(int *)(unaff_EBX + 0xd0 + unaff_EDI * 4);
  if (iVar2 != 0) {
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
    puVar1 = DAT_00735710;
    bVar3 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar2 + 0x5c) = 0x96dd344f;
    if (bVar3) {
      (**(code **)*puVar1)(iVar2);
    }
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xfffffffd | 0x400000;
  }
  if (DAT_0078a3f5 == '\x01') {
    FUN_0059fc90(*(float *)(&DAT_00777c20 + *(char *)(param_1 + 10) * 0x15c) * 0.001);
    iVar2 = LanguageStrings__FindByHash();
    if (iVar2 == 0) {
      iVar2 = LanguageStrings__FindByHash();
    }
  }
  else {
    FUN_0059fc90(*(float *)(&DAT_00777c20 + *(char *)(param_1 + 10) * 0x15c) * 0.000625);
    iVar2 = LanguageStrings__FindByHash();
    if (iVar2 == 0) {
      iVar2 = LanguageStrings__FindByHash();
    }
  }
  FEObject__SetFormattedText("%s %s",local_8,iVar2);
  return;
}


// ==== 0x49de00 PostRaceStatsScreen::DrawNumLapsLed

/* [canon] hud high (ghidra-canon+nfsug) docs/re/runtime.md */

void PostRaceStatsScreen__DrawNumLapsLed(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int unaff_EBX;
  int unaff_EDI;
  bool bVar3;
  
  iVar1 = *(int *)(unaff_EBX + 0xd0 + unaff_EDI * 4);
  if (iVar1 != 0) {
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
    puVar2 = DAT_00735710;
    bVar3 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar1 + 0x5c) = 0x680ac597;
    if (bVar3) {
      (**(code **)*puVar2)(iVar1);
    }
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffd | 0x400000;
  }
  FEObject__SetFormattedText
            ("%d/%d",(&DAT_00777cc4)[*(char *)(param_1 + 10) * 0x57],
             (&DAT_00777cc8)[*(char *)(param_1 + 10) * 0x57]);
  return;
}


// ==== 0x49de80 PostRaceStatsScreen::DrawPercentage

/* [canon] hud med (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__DrawPercentage(float param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_EBX;
  int unaff_EDI;
  bool bVar4;
  undefined1 auStack_8 [8];
  
  iVar2 = *(int *)(unaff_EBX + 0xd0 + unaff_EDI * 4);
  if (iVar2 != 0) {
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
    puVar3 = DAT_00735710;
    bVar4 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar2 + 0x5c) = 0x50b14e9;
    if (bVar4) {
      (**(code **)*puVar3)(iVar2);
    }
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xfffffffd | 0x400000;
  }
  pcVar1 = (char *)((int)param_1 + 10);
  param_1 = 0.0;
  if (0 < (int)(&DAT_00777cc8)[*pcVar1 * 0x57]) {
    param_1 = ((float)(int)(&DAT_00777cc4)[*pcVar1 * 0x57] /
              (float)(int)(&DAT_00777cc8)[*pcVar1 * 0x57]) * 100.0;
  }
  FUN_0059fc90(param_1);
  FEObject__SetFormattedText(&DAT_006c77e4,auStack_8);
  return;
}


// ==== 0x49df30 PostRaceStatsScreen::DrawLongestDrift

/* [canon] hud med (ghidra-canon+nfsug) docs/re/canon.md */

void PostRaceStatsScreen__DrawLongestDrift(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_EDI;
  bool bVar3;
  undefined1 local_8 [8];
  
  iVar2 = *(int *)(unaff_EBX + 0xd0 + unaff_EDI * 4);
  if (iVar2 != 0) {
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
    puVar1 = DAT_00735710;
    bVar3 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar2 + 0x5c) = 0x5c17ec47;
    if (bVar3) {
      (**(code **)*puVar1)(iVar2);
    }
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xfffffffd | 0x400000;
  }
  FUN_0059fc90(*(undefined4 *)(&DAT_00777cc0 + *(char *)(param_1 + 10) * 0x15c));
  iVar2 = LanguageStrings__FindByHash();
  if (iVar2 == 0) {
    iVar2 = LanguageStrings__FindByHash();
  }
  FEObject__SetFormattedText("%s %s",local_8,iVar2);
  return;
}


// ==== 0x49dfd0 cPostRaceScreenManager::ChangeToNextScreen

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void cPostRaceScreenManager__ChangeToNextScreen(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int in_EAX;
  int iVar4;
  
  puVar1 = *(undefined4 **)(in_EAX + 0xc);
  if (*(undefined4 **)(in_EAX + 8) != puVar1) {
    uVar2 = puVar1[2];
    *(undefined4 *)(in_EAX + 0xc) = *puVar1;
    iVar4 = bStrICmp();
    iVar3 = DAT_0073578c;
    if (iVar4 == 0) {
      cPostRaceScreenManager__ShowRewardPopup(in_EAX + 0x10,uVar2);
      return;
    }
    if (((DAT_0073578c != 0) && (iVar4 = FEPackageList__FindByName(&DAT_00746104), iVar4 != 0)) &&
       (*(int *)(iVar4 + 0x18) != 0)) {
      FUN_004f0800(*(undefined4 *)(iVar3 + 8),*(int *)(iVar4 + 0x18));
    }
  }
  return;
}


// ==== 0x49e040 cPostRaceScreenManager::ChangeToPrevScreen

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void cPostRaceScreenManager__ChangeToPrevScreen(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_EAX;
  int iVar3;
  
  iVar1 = *(int *)(in_EAX + 0xc);
  if (*(int *)(in_EAX + 4) != iVar1) {
    uVar2 = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(in_EAX + 0xc) = *(undefined4 *)(iVar1 + 4);
    iVar3 = bStrICmp();
    iVar1 = DAT_0073578c;
    if (iVar3 == 0) {
      cPostRaceScreenManager__ShowRewardPopup(in_EAX + 0x10,uVar2);
      return;
    }
    if (((DAT_0073578c != 0) && (iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 != 0)) &&
       (*(int *)(iVar3 + 0x18) != 0)) {
      FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar3 + 0x18));
    }
  }
  return;
}


// ==== 0x49e0b0 cPostRaceScreenManager::NeedToSeePostRaceStyle

/* [canon] hud med (ghidra-canon+nfsug) docs/re/canon.md */

bool cPostRaceScreenManager__NeedToSeePostRaceStyle(void)

{
  int iVar1;
  
  if (DAT_00777b4c == 1) {
    if (*(int *)(DAT_007677a8 + 0x58a0) == 0) {
      return false;
    }
  }
  else if (DAT_00777b4c == 4) {
    return false;
  }
  RacingCars_FindByKey();
  iVar1 = _ftol_nocw();
  return iVar1 != 0;
}


// ==== 0x49e100 cPostRaceScreenManager::cPostRaceScreenManager

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

undefined4 * cPostRaceScreenManager__cPostRaceScreenManager(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00686cd6;
  local_c = ExceptionList;
  piVar1 = param_1 + 1;
  ExceptionList = &local_c;
  *param_1 = &PTR_cPostRaceScreenManager___cPostRaceScreenManager_006c7584;
  *piVar1 = (int)piVar1;
  param_1[2] = piVar1;
  local_4 = 0;
  PostRaceRewardList__PostRaceRewardList(param_1 + 4);
  local_4 = CONCAT31(local_4._1_3_,1);
  if ((DAT_00777b4c != 1) || (*(int *)(DAT_007677a8 + 0x58a0) != 0)) {
    HudWidget__RegisterObject(PTR_s_PostRaceResults_fng_006fb98c);
  }
  iVar5 = DAT_007677a8;
  cVar3 = cPostRaceScreenManager__NeedToSeePostRaceStyle(param_1);
  if (cVar3 != '\0') {
    HudWidget__RegisterObject(PTR_s_StyleAnimator_fng_006fb994);
    iVar5 = DAT_007677a8;
  }
  if (((DAT_00777b4c == 1) && (*(int *)(iVar5 + 0x58a0) == 0)) &&
     (cVar3 = Race__DidPlayerWin(iVar5,0), cVar3 != '\0')) {
LAB_0049e1ce:
    cVar3 = Race__DidPlayerWin(iVar5,0);
    if ((cVar3 != '\0') && (*(int *)(iVar5 + 0x58a0) == 0)) goto LAB_0049e1f0;
  }
  else {
    if ((undefined4 *)param_1[5] != param_1 + 5) {
      HudWidget__RegisterObject(PTR_s_RewardPopup_fng_006fb990);
      iVar5 = DAT_007677a8;
    }
    if (DAT_00777b4c == 1) goto LAB_0049e1ce;
  }
  HudWidget__RegisterObject(PTR_s_PostRaceMenu_fng_006fb998);
LAB_0049e1f0:
  if ((int *)*piVar1 == piVar1) {
    DAT_006fb988 = 0;
    DAT_00735790 = cFrontendDatabase__CalculateFirstFrontendScreenToSeeAfterQuitRace(&DAT_00748f70);
    cFrontendDatabase__NotifyExitRaceToFrontend(1);
    iVar5 = DAT_007361f0;
    piVar4 = (int *)FUN_00567160();
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4[2] = 10;
      piVar4[3] = 0;
    }
    puVar2 = *(undefined4 **)(iVar5 + 0xc);
    *puVar2 = piVar4;
    *(int **)(iVar5 + 0xc) = piVar4;
    piVar4[1] = (int)puVar2;
    *piVar4 = iVar5 + 8;
  }
  piVar4 = (int *)*piVar1;
  param_1[3] = piVar4;
  for (; piVar4 != piVar1; piVar4 = (int *)*piVar4) {
    if (((DAT_0073578c != 0) && (iVar5 = FEPackageList__FindByName(&DAT_00746104), iVar5 != 0)) &&
       (*(int *)(iVar5 + 0x18) != 0)) {
      *(undefined1 *)(*(int *)(iVar5 + 0x18) + 0x15) = 1;
    }
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x49e2b0 cPostRaceScreenManager::_cPostRaceScreenManager

/* [canon] hud med (ghidra-canon+nfsug) docs/re/canon.md */

void * __thiscall cPostRaceScreenManager___cPostRaceScreenManager(void *param_1,byte param_2)

{
  cPostRaceScreenManager___cPostRaceScreenManager();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x49e2d0 cPostRaceScreenManager::_cPostRaceScreenManager

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void __fastcall cPostRaceScreenManager___cPostRaceScreenManager(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *_Memory;
  int *piVar3;
  int iVar4;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = ExceptionList;
  pcStack_8 = FUN_00686cb6;
  ExceptionList = &local_c;
  *param_1 = &PTR_cPostRaceScreenManager___cPostRaceScreenManager_006c7584;
  puVar2 = (undefined4 *)param_1[1];
  local_4 = 1;
  for (; puVar2 != param_1 + 1; puVar2 = (undefined4 *)*puVar2) {
    if (((DAT_0073578c != 0) && (iVar4 = FEPackageList__FindByName(&DAT_00746104), iVar4 != 0)) &&
       (*(int *)(iVar4 + 0x18) != 0)) {
      *(undefined1 *)(*(int *)(iVar4 + 0x18) + 0x15) = 0;
    }
  }
  piVar1 = param_1 + 5;
  param_1[4] = &PTR_FUN_006c75c8;
  _Memory = (int *)*piVar1;
  while (_Memory != piVar1) {
    iVar4 = *_Memory;
    piVar3 = (int *)_Memory[1];
    *piVar3 = iVar4;
    *(int **)(iVar4 + 4) = piVar3;
    _free(_Memory);
    _Memory = (int *)*piVar1;
  }
  local_4 = 0xffffffff;
  FUN_00421900();
  ExceptionList = local_c;
  return;
}


// ==== 0x49e390 cPostRaceScreenManager::CreateInstance

/* [canon] hud med (ghidra-canon) docs/re/canon.md */

void cPostRaceScreenManager__CreateInstance(void)

{
  void *pvVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006873f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x20);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    DAT_00735ed0 = 0;
  }
  else {
    DAT_00735ed0 = cPostRaceScreenManager__cPostRaceScreenManager(pvVar1);
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x49e3e0 cPostRaceScreenManager::EndInteraction

/* [canon] hud low (ghidra-canon) docs/re/canon.md */

void cPostRaceScreenManager__EndInteraction(void)

{
  if (DAT_00735ed0 != 0) {
    FEngStopInteraction();
  }
  return;
}


// ==== 0x49e400 PostRaceRewardList::GetItemLabelHash

/* [canon] canon med (ghidra-canon+hopper) docs/re/canon.md */

undefined4 __fastcall PostRaceRewardList__GetItemLabelHash(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_006fba08)[iVar1 * 2] == param_1) {
      return *(undefined4 *)(iVar1 * 8 + 0x6fba0c);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xb);
  return 0;
}


// ==== 0x49e420 PostRaceRewardList::AddRewardItem

/* [canon] hud med (ghidra-canon) docs/re/canon.md */

void PostRaceRewardList__AddRewardItem(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *in_EAX;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  char local_200 [256];
  char local_100 [256];
  
  switch(*in_EAX) {
  case 0:
    FUN_004f42f0("EVENT_REWARD_%s_LEVEL_%d",(&PTR_s_PAINT_006fb9a0)[in_EAX[1]],in_EAX[2]);
    break;
  case 1:
    PostRaceRewardList__GetItemLabelHash();
    break;
  case 2:
    pcVar6 = (char *)GetCarTypeInfo();
    pcVar5 = "";
    if (*(int *)(pcVar6 + 0xc50) == 0xf) {
      pcVar6 = "HYUNDAI";
      if (DAT_00734998 == 0) {
LAB_0049e56f:
        pcVar5 = "_USA";
LAB_0049e574:
        pcVar8 = "EVENT_REWARD_CAR_%s%s";
      }
      else if (DAT_00734998 == 2) {
        pcVar5 = "_KOREA";
        pcVar6 = "HYUNDAI";
        pcVar8 = "EVENT_REWARD_CAR_%s%s";
      }
      else if (DAT_00734998 == 1) {
        pcVar5 = "_EUROPE";
        pcVar6 = "HYUNDAI";
        pcVar8 = "EVENT_REWARD_CAR_%s%s";
      }
      else if (DAT_00734998 == 5) {
        pcVar5 = "_EUROPE";
        pcVar6 = "HYUNDAI";
        pcVar8 = "EVENT_REWARD_CAR_%s%s";
      }
      else {
        if (DAT_00734998 != 4) goto LAB_0049e574;
        pcVar5 = "_EUROPE";
        pcVar6 = "HYUNDAI";
        pcVar8 = "EVENT_REWARD_CAR_%s%s";
      }
    }
    else {
      if (*(int *)(pcVar6 + 0xc50) != 0xe) goto LAB_0049e574;
      if (DAT_00734998 == 1) {
        pcVar5 = "_EUROPE";
        pcVar8 = "EVENT_REWARD_CAR_%s%s";
      }
      else if (DAT_00734998 == 5) {
        pcVar5 = "_EUROPE";
        pcVar8 = "EVENT_REWARD_CAR_%s%s";
      }
      else {
        if (DAT_00734998 != 4) {
          pcVar5 = "_EUROPE";
          if (DAT_00734998 != 2) goto LAB_0049e56f;
          goto LAB_0049e574;
        }
        pcVar5 = "_EUROPE";
        pcVar8 = "EVENT_REWARD_CAR_%s%s";
      }
    }
    goto LAB_0049e5a4;
  case 3:
    pcVar6 = (char *)in_EAX[1];
    pcVar5 = "";
    if (in_EAX[2] == 1) {
      pcVar5 = "_BACKWARD";
    }
    else if (in_EAX[2] == 0) {
      pcVar5 = "_FORWARD";
    }
    pcVar8 = "EVENT_REWARD_TRACK_%d%s";
LAB_0049e5a4:
    FUN_004f42f0(pcVar8,pcVar6,pcVar5);
    break;
  case 4:
    goto switchD_0049e438_caseD_4;
  }
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  iVar7 = 0x100;
  pcVar6 = local_100;
  do {
    cVar1 = pcVar6[iVar3 - (int)local_100];
    iVar7 = iVar7 + -1;
    *pcVar6 = cVar1;
    if (cVar1 == '\0') break;
    pcVar6 = pcVar6 + 1;
  } while (iVar7 != 0);
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  iVar7 = 0x100;
  pcVar6 = local_200;
  do {
    cVar1 = pcVar6[iVar3 - (int)local_200];
    iVar7 = iVar7 + -1;
    *pcVar6 = cVar1;
    if (cVar1 == '\0') break;
    pcVar6 = pcVar6 + 1;
  } while (iVar7 != 0);
  piVar4 = _malloc(0x108);
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4[2] = 0x2ccb70aa;
  }
  bSPrintf_regdst(0xfc,local_100,local_200);
  puVar2 = *(undefined4 **)(param_1 + 8);
  *puVar2 = piVar4;
  *(int **)(param_1 + 8) = piVar4;
  piVar4[1] = (int)puVar2;
  *piVar4 = param_1 + 4;
switchD_0049e438_caseD_4:
  return;
}


// ==== 0x49e6a0 PostRaceRewardList::AddValueMessage

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void PostRaceRewardList__AddValueMessage(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  char local_100 [256];
  
  pcVar5 = local_100;
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  iVar6 = 0x100;
  do {
    cVar1 = pcVar5[iVar3 - (int)local_100];
    iVar6 = iVar6 + -1;
    *pcVar5 = cVar1;
    if (cVar1 == '\0') break;
    pcVar5 = pcVar5 + 1;
  } while (iVar6 != 0);
  piVar4 = _malloc(0x108);
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4[2] = 0x2ccb70aa;
  }
  bSPrintf_regdst(0xfc,local_100,param_2);
  puVar2 = *(undefined4 **)(param_1 + 8);
  *puVar2 = piVar4;
  *(int **)(param_1 + 8) = piVar4;
  piVar4[1] = (int)puVar2;
  *piVar4 = param_1 + 4;
  return;
}


// ==== 0x49e740 PostRaceRewardList::AddMessage

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void PostRaceRewardList__AddMessage(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  char local_100 [256];
  
  pcVar5 = local_100;
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  iVar6 = 0x100;
  do {
    cVar1 = pcVar5[iVar3 - (int)local_100];
    iVar6 = iVar6 + -1;
    *pcVar5 = cVar1;
    if (cVar1 == '\0') break;
    pcVar5 = pcVar5 + 1;
  } while (iVar6 != 0);
  piVar4 = _malloc(0x108);
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4[2] = 0x2ccb70aa;
  }
  bSPrintf_regdst(0xfc,local_100);
  puVar2 = *(undefined4 **)(param_1 + 8);
  *puVar2 = piVar4;
  *(int **)(param_1 + 8) = piVar4;
  piVar4[1] = (int)puVar2;
  *piVar4 = param_1 + 4;
  return;
}


// ==== 0x49e7e0 PostRaceRewardList::AddUniqueEventReward

/* [canon] hud med (ghidra-canon) docs/re/canon.md */

void PostRaceRewardList__AddUniqueEventReward(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  char local_100 [256];
  
  FUN_004f42f0("EVENT_REWARD_EVENT_%d_UNIQUE");
  pcVar5 = local_100;
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  iVar6 = 0x100;
  do {
    cVar1 = pcVar5[iVar3 - (int)local_100];
    iVar6 = iVar6 + -1;
    *pcVar5 = cVar1;
    if (cVar1 == '\0') break;
    pcVar5 = pcVar5 + 1;
  } while (iVar6 != 0);
  piVar4 = _malloc(0x108);
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4[2] = 0x2ccb70aa;
  }
  bSPrintf_regdst(0xfc,local_100);
  puVar2 = *(undefined4 **)(param_1 + 8);
  *puVar2 = piVar4;
  *(int **)(param_1 + 8) = piVar4;
  piVar4[1] = (int)puVar2;
  *piVar4 = param_1 + 4;
  return;
}


// ==== 0x49e890 PostRaceRewardList::AddMessageWith2Strings

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void PostRaceRewardList__AddMessageWith2Strings(int param_1)

{
  char cVar1;
  short sVar2;
  undefined4 *puVar3;
  int in_EAX;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char local_180 [128];
  char local_100 [256];
  
  sVar2 = *(short *)(in_EAX + 2);
  iVar4 = LanguageStrings__FindByHash();
  if (iVar4 == 0) {
    iVar4 = LanguageStrings__FindByHash();
  }
  iVar7 = 0x100;
  pcVar6 = local_100;
  do {
    cVar1 = pcVar6[iVar4 - (int)local_100];
    iVar7 = iVar7 + -1;
    *pcVar6 = cVar1;
    if (cVar1 == '\0') break;
    pcVar6 = pcVar6 + 1;
  } while (iVar7 != 0);
  iVar4 = LanguageStrings__FindByHash();
  if (iVar4 == 0) {
    iVar4 = LanguageStrings__FindByHash();
  }
  iVar7 = 0x80;
  pcVar6 = local_180;
  do {
    cVar1 = pcVar6[iVar4 - (int)local_180];
    iVar7 = iVar7 + -1;
    *pcVar6 = cVar1;
    if (cVar1 == '\0') break;
    pcVar6 = pcVar6 + 1;
  } while (iVar7 != 0);
  pcVar6 = (char *)LanguageStrings__FindByHash();
  if (pcVar6 == (char *)0x0) {
    pcVar6 = (char *)LanguageStrings__FindByHash();
  }
  piVar5 = _malloc(0x108);
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5[2] = 0x2ccb70aa;
  }
  if (DAT_006ee6f0 == 7) {
    pcVar8 = local_180;
    pcVar9 = (char *)(int)sVar2;
    pcVar10 = pcVar6;
  }
  else {
    pcVar10 = local_180;
    pcVar8 = (char *)(int)sVar2;
    pcVar9 = pcVar6;
  }
  bSPrintf_regdst(0xfc,local_100,pcVar8,pcVar9,pcVar10);
  puVar3 = *(undefined4 **)(param_1 + 8);
  *puVar3 = piVar5;
  *(int **)(param_1 + 8) = piVar5;
  piVar5[1] = (int)puVar3;
  *piVar5 = param_1 + 4;
  return;
}


// ==== 0x49e9d0 PostRaceRewardList::AddNewlyUnlockedMessages

/* [canon] hud med (ghidra-canon) docs/re/canon.md */

void PostRaceRewardList__AddNewlyUnlockedMessages(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_208;
  int local_204;
  char local_200 [128];
  char local_180 [128];
  char local_100 [256];
  
  iVar7 = DAT_00758ad4;
  iVar2 = 0;
  if (0 < DAT_007787b0) {
    piVar3 = &DAT_00777cd4;
    do {
      if (*piVar3 == DAT_0078a410) {
        puVar6 = &DAT_00777cd0 + iVar2 * 0x57;
        goto LAB_0049ea06;
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 0x57;
    } while (iVar2 < DAT_007787b0);
  }
  puVar6 = (undefined4 *)0x0;
LAB_0049ea06:
  Float_Truncate(puVar6[0x30]);
  puVar6 = &DAT_00758ad8;
  pcVar4 = local_180;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pcVar4 = *puVar6;
    puVar6 = puVar6 + 1;
    pcVar4 = pcVar4 + 4;
  }
  puVar6 = &DAT_00758ad8;
  pcVar4 = local_200;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pcVar4 = *puVar6;
    puVar6 = puVar6 + 1;
    pcVar4 = pcVar4 + 4;
  }
  _ftol_nocw();
  iVar2 = _ftol_nocw();
  ThresholdTable_MarkReached(&DAT_007588c4,iVar2 + iVar7);
  DAT_00760288 = 0;
  DAT_0076028c = 0;
  DAT_00760290 = 0;
  DAT_00760294 = 0;
  DAT_00760298 = 0;
  local_208 = 0;
  local_204 = 0;
  do {
    if (local_180[local_208] != local_200[local_208]) {
      if ((local_204 < 0) || (DAT_007343fc <= local_208)) {
        iVar7 = 0;
      }
      else {
        iVar7 = local_204 + DAT_007343f8;
      }
      iVar2 = LanguageStrings__FindByHash();
      if (iVar2 == 0) {
        iVar2 = LanguageStrings__FindByHash();
      }
      iVar5 = 0x100;
      pcVar4 = local_100;
      do {
        cVar1 = pcVar4[iVar2 - (int)local_100];
        iVar5 = iVar5 + -1;
        *pcVar4 = cVar1;
        if (cVar1 == '\0') break;
        pcVar4 = pcVar4 + 1;
      } while (iVar5 != 0);
      piVar3 = _malloc(0x108);
      if (piVar3 == (int *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3[2] = 0x6a765215;
      }
      iVar2 = LanguageStrings__FindByHash();
      if (iVar2 == 0) {
        iVar2 = LanguageStrings__FindByHash();
      }
      bSPrintf_regdst(0xfc,local_100,iVar2);
      puVar6 = *(undefined4 **)(param_1 + 8);
      *puVar6 = piVar3;
      *(int **)(param_1 + 8) = piVar3;
      *piVar3 = param_1 + 4;
      piVar3[1] = (int)puVar6;
      if (*(short *)(iVar7 + 4) == 0) {
        UnlockTeller__SetVinylGroupNewlyStyleUnlocked(*(undefined1 *)(iVar7 + 7));
      }
      else if (*(short *)(iVar7 + 4) == 2) {
        UnlockTeller__SetSingleVinylNewlyStyleUnlocked();
      }
    }
    local_204 = local_204 + 0x20;
    local_208 = local_208 + 1;
    if (0xfff < local_204) {
      return;
    }
  } while( true );
}


// ==== 0x49ebf0 PostRaceRewardList::AddCareerUnlockMessages

/* [canon] hud low (ghidra-canon) docs/re/canon.md */

void __thiscall PostRaceRewardList__AddCareerUnlockMessages(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  
  if (((DAT_00777b4c == 1) || (DAT_00777b4c == 8)) && (cVar2 = FUN_0051ba80(param_1), cVar2 != '\0')
     ) {
    iVar5 = 0xb;
    pcVar7 = &DAT_0076323d;
    puVar6 = &DAT_006fba60;
    do {
      if ((*pcVar7 != '\0') && ((&DAT_0076777c)[iVar5] == '\0')) {
        piVar3 = _malloc(0x108);
        if (piVar3 == (int *)0x0) {
          piVar3 = (int *)0x0;
        }
        else {
          piVar3[2] = 0x6a765215;
        }
        iVar4 = LanguageStrings__FindByHash();
        if (iVar4 == 0) {
          iVar4 = LanguageStrings__FindByHash();
        }
        bSPrintf_regdst(0xfc,iVar4);
        if (((puVar6 == (undefined4 *)&DAT_006fba90) || (puVar6 == (undefined4 *)&DAT_006fba94)) ||
           ((puVar6 == (undefined4 *)&DAT_006fba98 || (puVar6 == (undefined4 *)&DAT_006fba9c)))) {
          (&DAT_0076777c)[iVar5] = 1;
        }
        puVar1 = *(undefined4 **)(param_2 + 8);
        *puVar1 = piVar3;
        *(int **)(param_2 + 8) = piVar3;
        piVar3[1] = (int)puVar1;
        *piVar3 = param_2 + 4;
      }
      puVar6 = puVar6 + 1;
      pcVar7 = pcVar7 + 0x454;
      iVar5 = iVar5 + 1;
    } while ((int)puVar6 < 0x6fbaa0);
  }
  return;
}


// ==== 0x49ed00 PostRaceRewardList::PostRaceRewardList

/* [canon] hud med (ghidra-canon) docs/re/canon.md */

undefined4 * PostRaceRewardList__PostRaceRewardList(undefined4 *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  bool bVar8;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685aeb;
  local_c = ExceptionList;
  puVar1 = param_1 + 1;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c75c8;
  *puVar1 = puVar1;
  param_1[2] = puVar1;
  iVar6 = 0;
  local_4 = 0;
  if (DAT_00777b4c != 4) {
    PostRaceRewardList__AddNewlyUnlockedMessages(param_1);
  }
  piVar5 = DAT_007677a8;
  if (DAT_00777b4c == 1) {
    if ((DAT_007677a8 != (int *)0x0) && (cVar2 = Race__DidPlayerWin(DAT_007677a8,0), cVar2 != '\0'))
    {
      cVar2 = (**(code **)(*piVar5 + 4))();
      bVar8 = cVar2 == '\0';
LAB_0049ede4:
      if (bVar8) {
        PostRaceRewardList__AddCareerUnlockMessages(param_1);
      }
      goto LAB_0049edec;
    }
  }
  else {
    if (DAT_00777b4c == 8) {
      iVar3 = 0;
      if (0 < DAT_007787b0) {
        piVar5 = &DAT_00777cd0;
        do {
          if (*piVar5 == 1) {
            if ((iVar3 * 0x15c != -0x777cd0) && (DAT_0077b244 != 0)) {
              cVar2 = Obj_GetByte4();
              iVar3 = FUN_004ad2a0();
              bVar8 = *(int *)(iVar3 + 4) == (int)cVar2;
              goto LAB_0049ede4;
            }
            break;
          }
          iVar3 = iVar3 + 1;
          piVar5 = piVar5 + 0x57;
        } while (iVar3 < DAT_007787b0);
      }
      goto LAB_0049eeaf;
    }
LAB_0049edec:
    piVar5 = DAT_007677a8;
    if (DAT_00777b4c != 1) goto LAB_0049eeaf;
  }
  cVar2 = Race__DidPlayerWin(piVar5,0);
  if ((cVar2 == '\0') || (cVar2 = (**(code **)(*piVar5 + 4))(), cVar2 != '\0')) {
    cVar2 = FUN_005a3340();
    if (cVar2 != '\0') {
      PostRaceRewardList__AddMessage(param_1);
    }
  }
  else if ((char)piVar5[0x167b] == '\0') {
    uVar4 = _ftol_nocw();
    PostRaceRewardList__AddValueMessage(param_1,uVar4);
    bVar8 = false;
    if (0 < piVar5[0x1645]) {
      piVar7 = piVar5 + 0x1636;
      bVar8 = false;
      do {
        if ((*piVar7 == 0) && (piVar7[2] == 4)) {
          bVar8 = true;
        }
        else {
          PostRaceRewardList__AddRewardItem(param_1);
        }
        iVar6 = iVar6 + 1;
        piVar7 = piVar7 + 3;
      } while (iVar6 < piVar5[0x1645]);
    }
    if (piVar5[0x1629] == 6) {
      PostRaceRewardList__AddMessageWith2Strings(param_1);
    }
    if (bVar8) {
      PostRaceRewardList__AddUniqueEventReward(param_1);
    }
  }
LAB_0049eeaf:
  param_1[3] = param_1[1];
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x49eee0 cPostRaceScreenManager::ShowRewardPopup

/* [canon] hud low (ghidra-canon) docs/re/canon.md */

void cPostRaceScreenManager__ShowRewardPopup(void)

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


// ==== 0x49ef20 FUN_0049ef20

void __fastcall FUN_0049ef20(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c7574;
  FUN_004f7b50();
  return;
}


// ==== 0x49ef30 FUN_0049ef30

void * __thiscall FUN_0049ef30(void *param_1,byte param_2)

{
  FUN_0049ef20();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x49ef50 Screen_RewardPopup::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_RewardPopup__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687ec3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x40);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_RewardPopup__Screen_RewardPopup(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x49efb0 Screen_RewardPopup::Screen_RewardPopup

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_RewardPopup__Screen_RewardPopup(undefined4 *param_1,undefined4 param_2)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_006c7574;
  FUN_0049f000(param_1);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x49f000 FUN_0049f000

void FUN_0049f000(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) goto LAB_0049f08b;
    iVar2 = FUN_004ef050(0x7c34f6db);
  }
  if (iVar2 != 0) {
    for (iVar1 = *(int *)(iVar2 + 0x4c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
      iVar3 = FEng__HashName();
      if (*(int *)(iVar1 + 0x30) == iVar3) {
        if (iVar1 != 0) {
          if (iVar1 != *(int *)(iVar2 + 0x54)) {
            *(int *)(iVar2 + 0x54) = iVar1;
            FUN_004ff030(iVar2);
            *(undefined4 *)(*(int *)(iVar2 + 0x54) + 0x10) = 0;
          }
          *(undefined4 *)(iVar1 + 0x10) = 0;
        }
        break;
      }
    }
  }
LAB_0049f08b:
  iVar2 = *(int *)(DAT_00735ed0 + 0x1c);
  FEngPrintf(iVar2 + 0xc);
  FUN_00495f00(*(undefined4 *)(iVar2 + 8));
  return;
}


// ==== 0x49f0c0 FUN_0049f0c0

void __thiscall FUN_0049f0c0(undefined4 param_1,int param_2)

{
  if (param_2 == 0x406415e3) {
    if (*(undefined4 **)(DAT_00735ed0 + 0x1c) != *(undefined4 **)(DAT_00735ed0 + 0x18)) {
      *(undefined4 *)(DAT_00735ed0 + 0x1c) = **(undefined4 **)(DAT_00735ed0 + 0x1c);
      FUN_0049f000(param_1);
      return;
    }
    cPostRaceScreenManager__ChangeToNextScreen();
    return;
  }
  if (param_2 == -0x6ee54c9c) {
    if (*(int *)(DAT_00735ed0 + 0x1c) == *(int *)(DAT_00735ed0 + 0x14)) {
      cPostRaceScreenManager__ChangeToPrevScreen();
      return;
    }
    *(undefined4 *)(DAT_00735ed0 + 0x1c) = *(undefined4 *)(*(int *)(DAT_00735ed0 + 0x1c) + 4);
    FUN_0049f000(param_1);
  }
  return;
}


// ==== 0x49f120 FUN_0049f120

void __fastcall FUN_0049f120(int param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 8) = DAT_0073ad3c;
  if (((in_EAX == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) {
      return;
    }
    iVar1 = FUN_004ef050(0xb0116b0e);
  }
  if ((iVar1 != 0) && (iVar3 = *(int *)(iVar1 + 0x4c), iVar3 != 0)) {
    while (iVar2 = FEng__HashName(), *(int *)(iVar3 + 0x30) != iVar2) {
      iVar3 = *(int *)(iVar3 + 4);
      if (iVar3 == 0) {
        return;
      }
    }
    if (iVar3 != 0) {
      if (iVar3 != *(int *)(iVar1 + 0x54)) {
        *(int *)(iVar1 + 0x54) = iVar3;
        FUN_004ff030(iVar1);
        *(undefined4 *)(*(int *)(iVar1 + 0x54) + 0x10) = 0;
      }
      *(undefined4 *)(iVar3 + 0x10) = 0;
    }
  }
  return;
}


// ==== 0x49f1b0 FUN_0049f1b0

undefined4 __fastcall FUN_0049f1b0(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  
  fVar1 = (float)(DAT_0073ad3c - *(int *)(param_1 + 8)) * 0.00025;
  if ((0.0 < fVar1) && (fVar1 < 0.5)) {
    FUN_00565da0(&DAT_006b9172);
    return 0;
  }
  if ((0.5 < fVar1) && (fVar1 < 1.75)) {
    uVar2 = _ftol_nocw();
    FUN_00565da0(&DAT_006ca778,uVar2);
    return uVar2;
  }
  if ((1.75 < fVar1) && (fVar1 < 2.55)) {
    FUN_00565da0(&DAT_006ca778,*(undefined4 *)(param_1 + 0x4c));
    return *(undefined4 *)(param_1 + 0x4c);
  }
  FUN_00565da0(&DAT_006ca778,*(undefined4 *)(param_1 + 0x4c));
  return 0;
}


// ==== 0x49f2b0 Screen_RewardPopup::HasDisplayTimeElapsed

/* [canon] canon med (ghidra-canon+hopper) docs/re/canon.md */

undefined4 __fastcall Screen_RewardPopup__HasDisplayTimeElapsed(int param_1)

{
  if (2.55 < (float)(DAT_0073ad3c - *(int *)(param_1 + 8)) * 0.00025) {
    return 1;
  }
  return 0;
}


// ==== 0x49f2e0 FUN_0049f2e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049f2e0(void)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int extraout_EDX;
  int unaff_EBX;
  undefined1 local_20 [32];
  
  switch(*(undefined4 *)(unaff_EBX + 8)) {
  case 0:
    iVar3 = FUN_0049f1b0();
    cVar2 = Screen_RewardPopup__HasDisplayTimeElapsed();
    if (cVar2 != '\0') {
      *(int *)(unaff_EBX + 0x28) = *(int *)(unaff_EBX + 0x28) + *(int *)(extraout_EDX + 0x4c);
      if (*(undefined4 **)(unaff_EBX + 0xc) == *(undefined4 **)(unaff_EBX + 4)) {
        *(undefined4 *)(unaff_EBX + 8) = 1;
        *(int *)(unaff_EBX + 0x1c) = DAT_0073ad3c;
        FUN_004f6c30("Flashy",1);
      }
      else {
        *(undefined4 *)(unaff_EBX + 0xc) = **(undefined4 **)(unaff_EBX + 0xc);
        FUN_0049f120();
        FUN_004f6c30("Flashy",1);
      }
      FUN_004f6c30("Flashy",1);
    }
    FEngPrintf(&DAT_006cc568,*(int *)(unaff_EBX + 0xc) + 0xc);
    FEngPrintf(&DAT_006cc568,local_20);
    FEngPrintf(&DAT_006ca778,*(int *)(unaff_EBX + 0x28) + iVar3);
    FUN_00495f70();
    FUN_00495f70();
    FUN_0049f690(unaff_EBX,*(undefined4 *)(unaff_EBX + 0x34));
    return;
  case 1:
    FUN_00495fc0();
    FUN_00495f70();
    FEngPrintf(&DAT_006ca778,*(undefined4 *)(unaff_EBX + 0x24));
    if (_K_HALF < (float)(DAT_0073ad3c - *(int *)(unaff_EBX + 0x1c)) * 0.00025) {
      *(int *)(unaff_EBX + 0x20) = DAT_0073ad3c;
      *(undefined4 *)(unaff_EBX + 8) = 2;
      FUN_004f6c30("Flashy",1);
    }
    FUN_0049f690(unaff_EBX,*(undefined4 *)(unaff_EBX + 0x34));
    return;
  case 2:
    FUN_00495fc0();
    fVar1 = (float)(DAT_0073ad3c - *(int *)(unaff_EBX + 0x20)) * 0.00025;
    if ((fVar1 <= 0.0) || (_K_HALF <= fVar1)) {
      if ((fVar1 <= _K_HALF) || (3.0 <= fVar1)) {
        FUN_00565da0(&DAT_006ca778,*(int *)(unaff_EBX + 0x24) * *(int *)(unaff_EBX + 0x30));
        *(undefined4 *)(unaff_EBX + 8) = 3;
        FUN_0049f690(unaff_EBX,
                     *(int *)(unaff_EBX + 0x24) * *(int *)(unaff_EBX + 0x30) +
                     *(int *)(unaff_EBX + 0x34));
        FUN_004f6c30("Flashy",1);
      }
      else {
        iVar3 = _ftol_nocw();
        FUN_00565da0(&DAT_006ca778,iVar3);
        FUN_0049f690(unaff_EBX,*(int *)(unaff_EBX + 0x34) + iVar3);
      }
    }
    else {
      FUN_00565da0(&DAT_006ca778,*(undefined4 *)(unaff_EBX + 0x28));
    }
    FEngPrintf(&DAT_006cc568,local_20);
    return;
  case 3:
    FUN_00495fc0();
    FUN_00495fc0();
    FEngPrintf(&DAT_006cc568,*(int *)(unaff_EBX + 0xc) + 0xc);
    FEngPrintf(&DAT_006ca778,*(undefined4 *)(*(int *)(unaff_EBX + 0xc) + 0x4c));
    FEngPrintf(&DAT_006ca778,*(undefined4 *)(unaff_EBX + 0x30));
    FEngPrintf(&DAT_006ca778,*(undefined4 *)(unaff_EBX + 0x24));
    FEngPrintf(&DAT_006ca778,*(int *)(unaff_EBX + 0x24) * *(int *)(unaff_EBX + 0x30));
    FUN_0049f690(unaff_EBX,
                 *(int *)(unaff_EBX + 0x24) * *(int *)(unaff_EBX + 0x30) +
                 *(int *)(unaff_EBX + 0x34));
  }
  return;
}


// ==== 0x49f690 FUN_0049f690

/* WARNING: Removing unreachable block (ram,0x0049f6cc) */

void FUN_0049f690(int param_1,float param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *local_4;
  
  local_4 = (int *)0x0;
  FUN_005a0160(param_2,&local_4);
  if (local_4 == (int *)0x0) {
    param_2 = 1.0;
  }
  else {
    param_2 = (float)(int)param_2 / (float)*local_4;
    if (param_2 < 0.0) {
      param_2 = 0.0;
    }
  }
  if ((((*(int *)(param_1 + 0x10) == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
      (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
    FUN_004ef050(0x282d2c0a);
  }
  FUN_00496040(param_2 * *(float *)(param_1 + 0x14));
  uVar1 = *(undefined4 *)(param_1 + 0x18);
  FUN_004f6d10(&local_4,&param_2);
  FUN_004f7000(uVar1,param_2);
  return;
}


// ==== 0x49f7a0 FUN_0049f7a0

void FUN_0049f7a0(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  int iVar3;
  
  *(undefined4 *)(unaff_EBX + 8) = 3;
  if (((*(int *)(unaff_EBX + 0x10) == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) goto LAB_0049f826;
    iVar1 = FUN_004ef050(0x11bbe03f);
  }
  if (iVar1 != 0) {
    for (iVar3 = *(int *)(iVar1 + 0x4c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
      iVar2 = FEng__HashName();
      if (*(int *)(iVar3 + 0x30) == iVar2) {
        if (iVar3 != 0) {
          if (iVar3 != *(int *)(iVar1 + 0x54)) {
            *(int *)(iVar1 + 0x54) = iVar3;
            FUN_004ff030(iVar1);
            *(undefined4 *)(*(int *)(iVar1 + 0x54) + 0x10) = 0;
          }
          *(undefined4 *)(iVar3 + 0x10) = 0;
        }
        break;
      }
    }
  }
LAB_0049f826:
  if (((*(int *)(unaff_EBX + 0x10) == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) {
      return;
    }
    iVar1 = FUN_004ef050(0x618eb2d7);
  }
  if ((iVar1 != 0) && (iVar3 = *(int *)(iVar1 + 0x4c), iVar3 != 0)) {
    while (iVar2 = FEng__HashName(), *(int *)(iVar3 + 0x30) != iVar2) {
      iVar3 = *(int *)(iVar3 + 4);
      if (iVar3 == 0) {
        return;
      }
    }
    if (iVar3 != 0) {
      if (iVar3 != *(int *)(iVar1 + 0x54)) {
        *(int *)(iVar1 + 0x54) = iVar3;
        FUN_004ff030(iVar1);
        *(undefined4 *)(*(int *)(iVar1 + 0x54) + 0x10) = 0;
      }
      *(undefined4 *)(iVar3 + 0x10) = 0;
    }
  }
  return;
}


// ==== 0x49f8b0 FUN_0049f8b0

undefined4 * FUN_0049f8b0(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  undefined4 *puVar9;
  int iVar10;
  int local_14;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00687e98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = param_1;
  param_1[1] = param_1;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[4] = param_2;
  uVar3 = DAT_00758ad4;
  iVar6 = DAT_007361b4;
  iVar4 = 0;
  local_4 = 0;
  if (0 < DAT_007787b0) {
    piVar7 = &DAT_00777cd4;
    do {
      if (*piVar7 == DAT_0078a410) {
        puVar9 = &DAT_00777cd0 + iVar4 * 0x57;
        goto LAB_0049f91a;
      }
      iVar4 = iVar4 + 1;
      piVar7 = piVar7 + 0x57;
    } while (iVar4 < DAT_007787b0);
  }
  puVar9 = (undefined4 *)0x0;
LAB_0049f91a:
  uVar5 = _ftol_nocw();
  param_1[9] = uVar5;
  Float_Truncate(puVar9[0x30]);
  piVar7 = (int *)(iVar6 + 0x960);
  param_1[0xc] = 0;
  local_14 = 0x1f;
  do {
    if (*(char *)(*piVar7 + 0x14) != '\0') {
      iVar6 = _ftol_nocw();
      if (iVar6 != 0) {
        iVar4 = LanguageStrings__FindByHash();
        if (iVar4 == 0) {
          iVar4 = LanguageStrings__FindByHash();
        }
        puVar9 = _malloc(0x50);
        if (puVar9 == (undefined4 *)0x0) {
          puVar9 = (undefined4 *)0x0;
        }
        else {
          pcVar8 = (char *)(puVar9 + 3);
          puVar9[2] = 0;
          iVar10 = 0x40;
          iVar4 = iVar4 - (int)pcVar8;
          do {
            cVar1 = pcVar8[iVar4];
            iVar10 = iVar10 + -1;
            *pcVar8 = cVar1;
            if (cVar1 == '\0') break;
            pcVar8 = pcVar8 + 1;
          } while (iVar10 != 0);
          puVar9[0x13] = iVar6;
        }
        puVar2 = (undefined4 *)param_1[1];
        *puVar2 = puVar9;
        param_1[1] = puVar9;
        puVar9[1] = puVar2;
        *puVar9 = param_1;
        param_1[0xc] = param_1[0xc] + iVar6;
      }
    }
    piVar7 = piVar7 + 1;
    local_14 = local_14 + -1;
    if (local_14 == 0) {
      param_1[2] = 0;
      param_1[3] = *param_1;
      FUN_0049f120();
      param_1[10] = 0;
      param_1[0xd] = uVar3;
      param_1[5] = 0x43cb0000;
      param_1[6] = 0xc3340000;
      ExceptionList = local_c;
      return param_1;
    }
  } while( true );
}


// ==== 0x49fa60 FUN_0049fa60

void FUN_0049fa60(void)

{
  int *piVar1;
  int *_Memory;
  int iVar2;
  int *piVar3;
  undefined4 *unaff_EDI;
  
  piVar1 = unaff_EDI + 0x10;
  *unaff_EDI = &PTR_FUN_006c7598;
  _Memory = (int *)*piVar1;
  while (_Memory != piVar1) {
    iVar2 = *_Memory;
    piVar3 = (int *)_Memory[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(_Memory);
    _Memory = (int *)*piVar1;
  }
  FUN_004f7b50();
  return;
}


// ==== 0x49faa0 FUN_0049faa0

void * __thiscall FUN_0049faa0(void *param_1,byte param_2)

{
  FUN_0049fa60();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x49fac0 Screen_StyleAnimator::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_StyleAnimator__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688493;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x78);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_StyleAnimator__Screen_StyleAnimator(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x49fb20 Screen_StyleAnimator::Screen_StyleAnimator

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_StyleAnimator__Screen_StyleAnimator(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688473;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_006c7598;
  FUN_0049f8b0(param_1 + 0x10,param_1[3]);
  iVar2 = DAT_007361b4;
  local_4 = CONCAT31(local_4._1_3_,1);
  cVar1 = FUN_0043a2e0();
  if (cVar1 == '\0') {
    iVar2 = iVar2 + 0x34;
  }
  else {
    iVar2 = DAT_0077b244 + 0x19;
  }
  FEngPrintf(&DAT_006cc568,iVar2);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x49fbc0 FUN_0049fbc0

void __thiscall
FUN_0049fbc0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  
  if (param_2 == 0x406415e3) {
    if (*(int *)(param_1 + 0x48) != 3) {
      FUN_0049f7a0();
      return;
    }
    cPostRaceScreenManager__ChangeToNextScreen();
  }
  else {
    if (param_2 == -0x6ee54c9c) {
      cPostRaceScreenManager__ChangeToPrevScreen();
      return;
    }
    if (param_2 == -0x367ca946) {
      iVar1 = FEPackageList__FindByName(&DAT_00746104);
      if (((iVar1 == 0) || (*(int *)(iVar1 + 0x18) == 0)) && (*(int *)(param_5 + 0x1c) == 0)) {
        *(undefined4 *)(param_5 + 0x1c) = 0xff;
      }
      FUN_0049f2e0();
      return;
    }
  }
  return;
}


// ==== 0x49fc50 FUN_0049fc50

float10 __fastcall FUN_0049fc50(int param_1)

{
  if ((*(int *)(param_1 + 0x114) != 0) && (*(int *)(param_1 + 0x114) != 0x7fffffff)) {
    return (float10)(DAT_0073ad34 - *(int *)(param_1 + 0x114)) * (float10)0.00025;
  }
  return (float10)-1.0;
}


// ==== 0x49fc90 GetHudObjectColor

/* [canon] hud med (ghidra-canon) docs/re/canon.md */

void GetHudObjectColor(void)

{
  undefined4 *puVar1;
  int in_EAX;
  
  if (in_EAX != 0) {
    puVar1 = *(undefined4 **)(in_EAX + 0x2c);
    FEColor__operator_unsigned_long(*puVar1,puVar1[1],puVar1[2],puVar1[3]);
    return;
  }
  FEColor__operator_unsigned_long(0,0,0,0);
  return;
}


// ==== 0x49fcf0 GetHudCar

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

int GetHudCar(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  
  iVar1 = *(int *)(in_EAX + 4);
  if (((DAT_006fbf14 == 0) && (*(int *)(in_EAX + 0x10) == 0)) &&
     (iVar2 = RaceManager__FindRacerById(), iVar2 != 0)) {
    return iVar2;
  }
  return iVar1;
}


// ==== 0x49fd20 IntervalMapClipped

/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

float10 IntervalMapClipped(float param_1,float param_2,float param_3,float param_4,float param_5)

{
  if ((param_1 < param_5) && (param_5 < param_2)) {
    return ((float10)param_4 - (float10)param_3) *
           (((float10)param_5 - (float10)param_1) / ((float10)param_2 - (float10)param_1)) +
           (float10)param_3;
  }
  if ((param_5 < param_1 == (param_5 == param_1)) && (param_2 <= param_5)) {
    return (float10)param_4;
  }
  return (float10)param_3;
}


// ==== 0x49fd90 FUN_0049fd90

void __fastcall FUN_0049fd90(int param_1)

{
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  return;
}


// ==== 0x49fda0 HudElement::_HudElement

/* [canon] hud low (ghidra-canon) docs/re/canon.md */

void HudElement___HudElement(void)

{
  FUN_00421900();
  return;
}


// ==== 0x49fdb0 HudWidget::RegisterString

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

int __fastcall HudWidget__RegisterString(int param_1)

{
  undefined4 in_EAX;
  int iVar1;
  
  if (((*(int *)(param_1 + 8) == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) {
      return 0;
    }
    iVar1 = FUN_004ef050(in_EAX);
  }
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) == 2)) {
    HudWidget__RegisterObject(iVar1);
    return iVar1;
  }
  return 0;
}


// ==== 0x49fe10 HudElement::RegisterImage

/* [canon] hud med (ghidra+hopper) docs/re/tuning.md */

int __fastcall HudElement__RegisterImage(int param_1)

{
  undefined4 in_EAX;
  int iVar1;
  
  if (((*(int *)(param_1 + 8) == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) {
      return 0;
    }
    iVar1 = FUN_004ef050(in_EAX);
  }
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) == 1)) {
    HudWidget__RegisterObject(iVar1);
    return iVar1;
  }
  return 0;
}


// ==== 0x49fe70 HudWidget::RegisterObjectByHash

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void HudWidget__RegisterObjectByHash(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  
  if (((*(int *)(in_EAX + 8) == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c == 0) {
      return;
    }
    iVar1 = FUN_004ef050(param_1);
    if (iVar1 == 0) {
      return;
    }
  }
  HudWidget__RegisterObject(iVar1);
  return;
}


// ==== 0x49fec0 HudWidget::SetVisible

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void HudWidget__SetVisible(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *in_EAX;
  undefined4 *puVar4;
  undefined4 uVar5;
  int extraout_EDX;
  int iVar6;
  
  uVar1 = in_EAX[4];
  in_EAX[6] = param_1;
  uVar2 = in_EAX[5];
  in_EAX[7] = param_2;
  puVar3 = (undefined4 *)*in_EAX;
  puVar4 = (undefined4 *)NullUpdate_ret();
  for (; puVar3 != puVar4; puVar3 = (undefined4 *)*puVar3) {
    iVar6 = puVar3[2];
    if ((uVar1 & param_1) == 0 && (uVar2 & param_2) == 0) {
      FEObject__SetInvisible(iVar6);
    }
    else if ((iVar6 != 0) &&
            (*(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) & 0xfffffffe | 0x400000,
            *(int *)(iVar6 + 0x18) == 5)) {
      uVar5 = *(undefined4 *)(iVar6 + 0x60);
      iVar6 = *(int *)(iVar6 + 0x5c);
      if (0 < iVar6) {
        do {
          FEObject__SetVisible(uVar5);
          uVar5 = *(undefined4 *)(extraout_EDX + 4);
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
    }
  }
  return;
}


// ==== 0x49ff50 HudElement::SetVerticalBarValue

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

void HudElement__SetVerticalBarValue
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,float param_4,float param_5
               )

{
  short sVar1;
  int iVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  char cVar6;
  int iVar7;
  int unaff_ESI;
  float10 fVar8;
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  iVar2 = *(int *)(unaff_ESI + 0x2c);
  iVar7 = Texture_FindByHash(*(undefined4 *)(unaff_ESI + 0x24),1,0);
  sVar1 = *(short *)(iVar7 + 0x46);
  fVar4 = (float)(int)sVar1;
  fVar5 = _K_ONE / fVar4;
  fVar8 = (float10)IntervalMapClipped(0,param_3,(fVar4 - param_4) * fVar5,param_5 * fVar5,param_2);
  *(float *)(iVar2 + 0x48) = (float)fVar8;
  local_c = *(undefined4 *)(iVar2 + 0x1c);
  local_4 = *(undefined4 *)(iVar2 + 0x24);
  fVar8 = ((float10)_K_ONE - fVar8) * (float10)(int)sVar1;
  local_18 = *(undefined4 *)(iVar2 + 0x38);
  local_10 = *(undefined4 *)(iVar2 + 0x40);
  uVar3 = *(uint *)(unaff_ESI + 0x1c);
  local_14 = (float)fVar8;
  local_8 = (float)(((float10)*(float *)(iVar2 + 0x3c) - fVar8) * (float10)_K_HALF +
                   (float10)*(float *)(iVar2 + 0x20));
  *(uint *)(unaff_ESI + 0x1c) = uVar3 | 0x400000;
  if (*(int *)(unaff_ESI + 0x18) < 0x100) {
    cVar6 = FUN_004feab0();
    if (cVar6 == '\0') {
      *(uint *)(unaff_ESI + 0x1c) = uVar3 | 0x400000;
    }
    FUN_004ff1f0(unaff_ESI,4,&local_18,0);
  }
  if (*(int *)(unaff_ESI + 0x18) < 0x100) {
    cVar6 = FEVector3__operator__();
    if (cVar6 == '\0') {
      *(uint *)(unaff_ESI + 0x1c) = *(uint *)(unaff_ESI + 0x1c) | 0x400000;
    }
    FUN_004ff1f0(unaff_ESI,2,&local_c,0);
  }
  return;
}


// ==== 0x4a0080 Hud_PackColorFromFloats

/* [canon] hud med (ghidra-canon) docs/re/canon.md */

uint Hud_PackColorFromFloats(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = _ftol_nocw();
  uVar2 = _ftol_nocw();
  uVar3 = _ftol_nocw();
  uVar4 = _ftol_nocw();
  return uVar4 | ((iVar1 << 8 | uVar2) << 8 | uVar3) << 8;
}


// ==== 0x4a00c0 HudPosition::HudPosition

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

int HudPosition__HudPosition(int param_1,undefined4 param_2)

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
  *(undefined4 *)(param_1 + 0x10) = 0x200;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  local_4 = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  FEng__HashName();
  uVar1 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  FEng__HashName();
  uVar1 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  FEng__HashName();
  uVar1 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  FEng__HashName();
  uVar1 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  uVar1 = FEng__HashName();
  HudWidget__RegisterObjectByHash(uVar1);
  FEng__HashName();
  uVar1 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4a01a0 HudPosition::Update

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void HudPosition__Update(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int unaff_ESI;
  undefined1 local_20 [32];
  
  if ((*(uint *)(unaff_ESI + 0x18) & *(uint *)(unaff_ESI + 0x10)) != 0 ||
      (*(uint *)(unaff_ESI + 0x1c) & *(uint *)(unaff_ESI + 0x14)) != 0) {
    iVar4 = *(int *)(param_1 + 4);
    if (((DAT_006fbf14 == 0) && (*(int *)(param_1 + 0x10) == 0)) &&
       (iVar2 = RaceManager__FindRacerById(), iVar2 != 0)) {
      iVar4 = iVar2;
    }
    if ((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) {
      cVar1 = FUN_0043a2e0();
      if (cVar1 == '\0') {
        iVar2 = 4;
      }
      else {
        iVar2 = DAT_0078a32c + DAT_0078a328 + DAT_0078a324 + DAT_0078a320;
      }
      FEObject__SetFormattedText(&PTR_FUN_006c7520,iVar2);
      uVar3 = RaceManager__GetRacerRank((int)*(short *)(iVar4 + 10));
      iVar4 = LanguageStrings__FindByHash();
      if (iVar4 == 0) {
        iVar4 = LanguageStrings__FindByHash();
      }
      FEObject__SetFormattedText(&DAT_006cc568,iVar4);
      FEObject__SetFormattedText(&DAT_006ca778,uVar3);
      return;
    }
    if (*(int *)(iVar4 + 0x1c) != 0) {
      iVar2 = *(int *)(DAT_0073619c + 0x24);
      iVar6 = iVar2;
      if (0 < iVar2) {
        piVar5 = (int *)(DAT_0073619c + 0x520);
        do {
          if ((*piVar5 != 0) && (*(short *)(*piVar5 + 0x10) == 3)) {
            iVar6 = iVar6 + -1;
          }
          piVar5 = piVar5 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      iVar2 = (int)*(char *)(*(int *)(iVar4 + 0x1c) + 10);
      FEObject__SetFormattedText(&DAT_006ca778,iVar2);
      iVar4 = LanguageStrings__FindByHash();
      if (iVar4 == 0) {
        iVar4 = LanguageStrings__FindByHash();
      }
      FEObject__SetFormattedText(&DAT_006cc568,iVar4);
      FEObject__SetFormattedText(&PTR_FUN_006c7520,iVar6);
      if (iVar2 != *(int *)(unaff_ESI + 0x24)) {
        *(int *)(unaff_ESI + 0x24) = iVar2;
      }
      if (*(char *)(*(int *)(*(int *)(param_1 + 4) + 0x1c) + 0xd) != '\0') {
        *(int *)(unaff_ESI + 0x40) = DAT_0073ad34;
      }
      if (3.0 <= (float)(DAT_0073ad34 - *(int *)(unaff_ESI + 0x40)) * 0.00025) {
        *(undefined4 *)(unaff_ESI + 0x44) = *(undefined4 *)(DAT_0073619c + 0x14);
      }
      FUN_00586580(local_20);
      FEObject__SetFormattedText(&DAT_006cc568,local_20);
    }
  }
  return;
}


// ==== 0x4a03d0 HudTach::HudTach

/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

int HudTach__HudTach(int param_1,int *param_2,int param_3)

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
  undefined *puVar11;
  char *pcVar12;
  int *piVar13;
  int local_40;
  int local_3c;
  undefined **local_38;
  int local_34;
  int local_30;
  byte local_2c;
  byte local_2b [31];
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_00687e60;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(int **)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0x10000060;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  local_4 = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  FEng__HashName();
  uVar5 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x30) = uVar5;
  FEng__HashName();
  uVar5 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x68) = uVar5;
  FEng__HashName();
  uVar5 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x6c) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x70) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x74) = uVar5;
  FEng__HashName();
  uVar5 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x78) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x7c) = uVar5;
  FEng__HashName();
  uVar5 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x80) = uVar5;
  FEng__HashName();
  uVar5 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x84) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x88) = uVar5;
  FEng__HashName();
  uVar5 = HudWidget__RegisterString();
  *(undefined4 *)(param_1 + 0x8c) = uVar5;
  FEng__HashName();
  uVar5 = HudElement__RegisterImage();
  *(undefined4 *)(param_1 + 0x94) = uVar5;
  if (DAT_0078a320 < 2) {
    FEng__HashName();
    uVar5 = HudElement__RegisterImage();
    *(undefined4 *)(param_1 + 0x90) = uVar5;
  }
  else {
    FEng__HashName();
    iVar6 = HudElement__RegisterImage();
    *(int *)(param_1 + 0x90) = iVar6;
    if (iVar6 != 0) {
      for (iVar8 = *(int *)(iVar6 + 0x4c); iVar8 != 0; iVar8 = *(int *)(iVar8 + 4)) {
        iVar7 = FEng__HashName();
        if (*(int *)(iVar8 + 0x30) == iVar7) {
          if (iVar8 != 0) {
            if (iVar8 != *(int *)(iVar6 + 0x54)) {
              *(int *)(iVar6 + 0x54) = iVar8;
              FUN_004ff030(iVar6);
              *(undefined4 *)(*(int *)(iVar6 + 0x54) + 0x10) = 0;
            }
            *(undefined4 *)(iVar8 + 0x10) = 0;
          }
          break;
        }
      }
    }
  }
  local_40 = 0;
  param_2 = (int *)(param_1 + 0x34);
  do {
    local_40 = local_40 + 1;
    bSPrintf_regdst(0x20,"RPM_%d",local_40);
    iVar6 = -1;
    pbVar10 = &local_2c;
    bVar4 = local_2c;
    while (bVar4 != 0) {
      if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
        bVar4 = bVar4 - 0x20;
      }
      pbVar1 = pbVar10 + 1;
      iVar6 = iVar6 * 0x21 + (uint)bVar4;
      pbVar10 = pbVar10 + 1;
      bVar4 = *pbVar1;
    }
    if (*(int *)(param_1 + 8) == 0) goto LAB_004a0680;
    iVar8 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar8 != 0) && (iVar8 = *(int *)(iVar8 + 0x18), iVar8 != 0)) goto LAB_004a0648;
    if (DAT_0073578c == 0) {
LAB_004a0724:
      iVar8 = 0;
    }
    else {
      iVar7 = *(int *)(DAT_0073578c + 8);
      if (iVar7 == 0) {
LAB_004a0680:
        if (DAT_0073578c == 0) goto LAB_004a0724;
        iVar8 = FUN_004ef050(iVar6);
      }
      else {
        FUN_004ee660();
        iVar8 = FUN_004fd1e0(iVar7 + 0xdc);
        if (iVar8 == 0) {
          FUN_004ee660();
          iVar8 = FUN_004fd1e0(iVar7 + 0xec);
          if (iVar8 == 0) goto LAB_004a0680;
        }
LAB_004a0648:
        local_38 = &PTR_FUN_006c1800;
        local_4._0_1_ = 1;
        local_30 = 0;
        local_34 = iVar6;
        FUN_004ffb00(iVar8);
        local_4 = (uint)local_4._1_3_ << 8;
        local_38 = &PTR_FUN_006c2c5c;
        iVar8 = local_30;
        if (local_30 == 0) goto LAB_004a0680;
      }
      if ((iVar8 == 0) || (*(int *)(iVar8 + 0x18) != 1)) goto LAB_004a0724;
      if (DAT_007349b4 == 0) {
        FUN_005649f0();
      }
      iVar6 = DAT_007349b4;
      piVar13 = (int *)(DAT_007349b4 + 0x10);
      if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
        FUN_00566e60();
      }
      piVar9 = (int *)*piVar13;
      iVar7 = *(int *)(iVar6 + 0x18) + 1;
      if (piVar9 == (int *)0x0) {
        piVar9 = (int *)0x0;
      }
      else {
        iVar2 = *piVar9;
        if (*(int *)(iVar6 + 0x1c) < iVar7) {
          *(int *)(iVar6 + 0x1c) = iVar7;
        }
        *(int *)(iVar6 + 0x18) = iVar7;
        bVar4 = *(byte *)(iVar6 + 0x14);
        *piVar13 = iVar2;
        if (((bVar4 & 2) != 0) && (iVar6 = *(int *)(iVar6 + 0x28) >> 2, piVar13 = piVar9, 0 < iVar6)
           ) {
          for (; iVar6 != 0; iVar6 = iVar6 + -1) {
            *piVar13 = 0;
            piVar13 = piVar13 + 1;
          }
        }
        piVar9[2] = iVar8;
      }
      puVar3 = *(undefined4 **)(param_1 + 4);
      *puVar3 = piVar9;
      *(int **)(param_1 + 4) = piVar9;
      piVar9[1] = (int)puVar3;
      *piVar9 = param_1;
    }
    *param_2 = iVar8;
    param_2 = param_2 + 1;
  } while (local_40 < 10);
  puVar11 = &DAT_006c744c;
  iVar6 = -1;
  bVar4 = 0x52;
  do {
    if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
      bVar4 = bVar4 - 0x20;
    }
    iVar6 = iVar6 * 0x21 + (uint)bVar4;
    bVar4 = puVar11[1];
    puVar11 = puVar11 + 1;
  } while (bVar4 != 0);
  if (*(int *)(param_1 + 8) == 0) goto LAB_004a0822;
  iVar8 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar8 != 0) && (iVar8 = *(int *)(iVar8 + 0x18), iVar8 != 0)) goto LAB_004a07ea;
  if (DAT_0073578c == 0) {
LAB_004a08c6:
    iVar8 = 0;
  }
  else {
    iVar7 = *(int *)(DAT_0073578c + 8);
    if (iVar7 == 0) {
LAB_004a0822:
      if (DAT_0073578c == 0) goto LAB_004a08c6;
      iVar8 = FUN_004ef050(iVar6);
    }
    else {
      FUN_004ee660();
      iVar8 = FUN_004fd1e0(iVar7 + 0xdc);
      if (iVar8 == 0) {
        FUN_004ee660();
        iVar8 = FUN_004fd1e0(iVar7 + 0xec);
        if (iVar8 == 0) goto LAB_004a0822;
      }
LAB_004a07ea:
      local_38 = &PTR_FUN_006c1800;
      local_4._0_1_ = 2;
      local_30 = 0;
      local_34 = iVar6;
      FUN_004ffb00(iVar8);
      local_4 = (uint)local_4._1_3_ << 8;
      local_38 = &PTR_FUN_006c2c5c;
      iVar8 = local_30;
      if (local_30 == 0) goto LAB_004a0822;
    }
    if ((iVar8 == 0) || (*(int *)(iVar8 + 0x18) != 1)) goto LAB_004a08c6;
    if (DAT_007349b4 == 0) {
      FUN_005649f0();
    }
    iVar6 = DAT_007349b4;
    piVar13 = (int *)(DAT_007349b4 + 0x10);
    if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
      FUN_00566e60();
    }
    piVar9 = (int *)*piVar13;
    iVar7 = *(int *)(iVar6 + 0x18) + 1;
    if (piVar9 == (int *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      iVar2 = *piVar9;
      if (*(int *)(iVar6 + 0x1c) < iVar7) {
        *(int *)(iVar6 + 0x1c) = iVar7;
      }
      *(int *)(iVar6 + 0x18) = iVar7;
      bVar4 = *(byte *)(iVar6 + 0x14);
      *piVar13 = iVar2;
      if (((bVar4 & 2) != 0) && (iVar6 = *(int *)(iVar6 + 0x28) >> 2, piVar13 = piVar9, 0 < iVar6))
      {
        for (; iVar6 != 0; iVar6 = iVar6 + -1) {
          *piVar13 = 0;
          piVar13 = piVar13 + 1;
        }
      }
      piVar9[2] = iVar8;
    }
    puVar3 = *(undefined4 **)(param_1 + 4);
    *puVar3 = piVar9;
    *(int **)(param_1 + 4) = piVar9;
    piVar9[1] = (int)puVar3;
    *piVar9 = param_1;
  }
  *(int *)(param_1 + 0x5c) = iVar8;
  pcVar12 = "RPM45Corner_Left";
  iVar6 = -1;
  bVar4 = 0x52;
  do {
    if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
      bVar4 = bVar4 - 0x20;
    }
    iVar6 = iVar6 * 0x21 + (uint)bVar4;
    bVar4 = pcVar12[1];
    pcVar12 = pcVar12 + 1;
  } while (bVar4 != 0);
  if (*(int *)(param_1 + 8) == 0) goto LAB_004a09b2;
  iVar8 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar8 != 0) && (iVar8 = *(int *)(iVar8 + 0x18), iVar8 != 0)) goto LAB_004a097a;
  if (DAT_0073578c == 0) {
LAB_004a0a56:
    iVar8 = 0;
  }
  else {
    iVar7 = *(int *)(DAT_0073578c + 8);
    if (iVar7 == 0) {
LAB_004a09b2:
      if (DAT_0073578c == 0) goto LAB_004a0a56;
      iVar8 = FUN_004ef050(iVar6);
    }
    else {
      FUN_004ee660();
      iVar8 = FUN_004fd1e0(iVar7 + 0xdc);
      if (iVar8 == 0) {
        FUN_004ee660();
        iVar8 = FUN_004fd1e0(iVar7 + 0xec);
        if (iVar8 == 0) goto LAB_004a09b2;
      }
LAB_004a097a:
      local_38 = &PTR_FUN_006c1800;
      local_4._0_1_ = 3;
      local_30 = 0;
      local_34 = iVar6;
      FUN_004ffb00(iVar8);
      local_4 = (uint)local_4._1_3_ << 8;
      local_38 = &PTR_FUN_006c2c5c;
      iVar8 = local_30;
      if (local_30 == 0) goto LAB_004a09b2;
    }
    if ((iVar8 == 0) || (*(int *)(iVar8 + 0x18) != 1)) goto LAB_004a0a56;
    if (DAT_007349b4 == 0) {
      FUN_005649f0();
    }
    iVar6 = DAT_007349b4;
    piVar13 = (int *)(DAT_007349b4 + 0x10);
    if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
      FUN_00566e60();
    }
    piVar9 = (int *)*piVar13;
    iVar7 = *(int *)(iVar6 + 0x18) + 1;
    if (piVar9 == (int *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      iVar2 = *piVar9;
      if (*(int *)(iVar6 + 0x1c) < iVar7) {
        *(int *)(iVar6 + 0x1c) = iVar7;
      }
      *(int *)(iVar6 + 0x18) = iVar7;
      bVar4 = *(byte *)(iVar6 + 0x14);
      *piVar13 = iVar2;
      if (((bVar4 & 2) != 0) && (iVar6 = *(int *)(iVar6 + 0x28) >> 2, piVar13 = piVar9, 0 < iVar6))
      {
        for (; iVar6 != 0; iVar6 = iVar6 + -1) {
          *piVar13 = 0;
          piVar13 = piVar13 + 1;
        }
      }
      piVar9[2] = iVar8;
    }
    puVar3 = *(undefined4 **)(param_1 + 4);
    *puVar3 = piVar9;
    *(int **)(param_1 + 4) = piVar9;
    piVar9[1] = (int)puVar3;
    *piVar9 = param_1;
  }
  *(int *)(param_1 + 0x60) = iVar8;
  pcVar12 = "RPM45Corner_Right";
  iVar6 = -1;
  bVar4 = 0x52;
  do {
    if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
      bVar4 = bVar4 - 0x20;
    }
    iVar6 = iVar6 * 0x21 + (uint)bVar4;
    bVar4 = pcVar12[1];
    pcVar12 = pcVar12 + 1;
  } while (bVar4 != 0);
  if (*(int *)(param_1 + 8) == 0) goto LAB_004a0b42;
  iVar8 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar8 != 0) && (iVar8 = *(int *)(iVar8 + 0x18), iVar8 != 0)) goto LAB_004a0b0a;
  if (DAT_0073578c == 0) {
LAB_004a0be6:
    iVar8 = 0;
  }
  else {
    iVar7 = *(int *)(DAT_0073578c + 8);
    if (iVar7 == 0) {
LAB_004a0b42:
      if (DAT_0073578c == 0) goto LAB_004a0be6;
      iVar8 = FUN_004ef050(iVar6);
    }
    else {
      FUN_004ee660();
      iVar8 = FUN_004fd1e0(iVar7 + 0xdc);
      if (iVar8 == 0) {
        FUN_004ee660();
        iVar8 = FUN_004fd1e0(iVar7 + 0xec);
        if (iVar8 == 0) goto LAB_004a0b42;
      }
LAB_004a0b0a:
      local_38 = &PTR_FUN_006c1800;
      local_4._0_1_ = 4;
      local_30 = 0;
      local_34 = iVar6;
      FUN_004ffb00(iVar8);
      local_4 = (uint)local_4._1_3_ << 8;
      local_38 = &PTR_FUN_006c2c5c;
      iVar8 = local_30;
      if (local_30 == 0) goto LAB_004a0b42;
    }
    if ((iVar8 == 0) || (*(int *)(iVar8 + 0x18) != 1)) goto LAB_004a0be6;
    if (DAT_007349b4 == 0) {
      FUN_005649f0();
    }
    iVar6 = DAT_007349b4;
    piVar13 = (int *)(DAT_007349b4 + 0x10);
    if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
      FUN_00566e60();
    }
    piVar9 = (int *)*piVar13;
    iVar7 = *(int *)(iVar6 + 0x18) + 1;
    if (piVar9 == (int *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      iVar2 = *piVar9;
      if (*(int *)(iVar6 + 0x1c) < iVar7) {
        *(int *)(iVar6 + 0x1c) = iVar7;
      }
      *(int *)(iVar6 + 0x18) = iVar7;
      bVar4 = *(byte *)(iVar6 + 0x14);
      *piVar13 = iVar2;
      if (((bVar4 & 2) != 0) && (iVar6 = *(int *)(iVar6 + 0x28) >> 2, piVar13 = piVar9, 0 < iVar6))
      {
        for (; iVar6 != 0; iVar6 = iVar6 + -1) {
          *piVar13 = 0;
          piVar13 = piVar13 + 1;
        }
      }
      piVar9[2] = iVar8;
    }
    puVar3 = *(undefined4 **)(param_1 + 4);
    *puVar3 = piVar9;
    *(int **)(param_1 + 4) = piVar9;
    piVar9[1] = (int)puVar3;
    *piVar9 = param_1;
  }
  *(int *)(param_1 + 100) = iVar8;
  pcVar12 = "Shift_light_back";
  iVar6 = -1;
  bVar4 = 0x53;
  do {
    if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
      bVar4 = bVar4 - 0x20;
    }
    iVar6 = iVar6 * 0x21 + (uint)bVar4;
    bVar4 = pcVar12[1];
    pcVar12 = pcVar12 + 1;
  } while (bVar4 != 0);
  if (*(int *)(param_1 + 8) == 0) goto LAB_004a0cd2;
  iVar8 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar8 != 0) && (iVar8 = *(int *)(iVar8 + 0x18), iVar8 != 0)) goto LAB_004a0c9a;
  if (DAT_0073578c == 0) goto LAB_004a0d87;
  iVar7 = *(int *)(DAT_0073578c + 8);
  if (iVar7 == 0) {
LAB_004a0cd2:
    if (DAT_0073578c == 0) goto LAB_004a0d87;
    iVar8 = FUN_004ef050(iVar6);
  }
  else {
    FUN_004ee660();
    iVar8 = FUN_004fd1e0(iVar7 + 0xdc);
    if (iVar8 == 0) {
      FUN_004ee660();
      iVar8 = FUN_004fd1e0(iVar7 + 0xec);
      if (iVar8 == 0) goto LAB_004a0cd2;
    }
LAB_004a0c9a:
    local_38 = &PTR_FUN_006c1800;
    local_4._0_1_ = 5;
    local_30 = 0;
    local_34 = iVar6;
    FUN_004ffb00(iVar8);
    local_4 = (uint)local_4._1_3_ << 8;
    local_38 = &PTR_FUN_006c2c5c;
    iVar8 = local_30;
    if (local_30 == 0) goto LAB_004a0cd2;
  }
  if ((iVar8 != 0) && (*(int *)(iVar8 + 0x18) == 1)) {
    if (DAT_007349b4 == 0) {
      FUN_005649f0();
    }
    iVar6 = DAT_007349b4;
    piVar13 = (int *)(DAT_007349b4 + 0x10);
    if ((*(int *)(DAT_007349b4 + 0x10) == 0) && ((*(byte *)(DAT_007349b4 + 0x14) & 1) != 0)) {
      FUN_00566e60();
    }
    piVar9 = (int *)*piVar13;
    iVar7 = *(int *)(iVar6 + 0x18) + 1;
    if (piVar9 == (int *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      iVar2 = *piVar9;
      if (*(int *)(iVar6 + 0x1c) < iVar7) {
        *(int *)(iVar6 + 0x1c) = iVar7;
      }
      *(int *)(iVar6 + 0x18) = iVar7;
      bVar4 = *(byte *)(iVar6 + 0x14);
      *piVar13 = iVar2;
      if (((bVar4 & 2) != 0) && (iVar6 = *(int *)(iVar6 + 0x28) >> 2, piVar13 = piVar9, 0 < iVar6))
      {
        for (; iVar6 != 0; iVar6 = iVar6 + -1) {
          *piVar13 = 0;
          piVar13 = piVar13 + 1;
        }
      }
      piVar9[2] = iVar8;
    }
    puVar3 = *(undefined4 **)(param_1 + 4);
    *puVar3 = piVar9;
    *(int **)(param_1 + 4) = piVar9;
    piVar9[1] = (int)puVar3;
    *piVar9 = param_1;
  }
LAB_004a0d87:
  *(undefined1 *)(param_1 + 0x98) = 0;
  if ((int)(&DAT_0078a410)[param_3] < 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = 0;
    if (0 < DAT_0078a41c) {
      pcVar12 = (char *)(DAT_0078a418 + 1);
      do {
        if ((&DAT_0078a410)[param_3] == (int)*pcVar12) {
          iVar6 = iVar6 * 0x750 + DAT_0078a418;
          goto LAB_004a0ddd;
        }
        iVar6 = iVar6 + 1;
        pcVar12 = pcVar12 + 0x750;
      } while (iVar6 < DAT_0078a41c);
    }
    iVar6 = 0;
  }
LAB_004a0ddd:
  if ((iVar6 != 0) && ((undefined4 *)(iVar6 + 0x10) != (undefined4 *)0x0)) {
    if (*(char *)(iVar6 + 0x434) == -1) {
      RideInfo__RebuildPhysicsInfo(1);
    }
    if ((iVar6 != -0x70) && (iVar6 != -0x260)) {
      HudTach_PickFaceHashes(*(undefined4 *)(iVar6 + 0x10),(int)DAT_0078a3f5,&local_40);
      iVar6 = local_40;
      iVar8 = Texture_FindByHash(local_40,0,0);
      if (iVar8 == 0) {
        *(undefined1 *)(param_1 + 0x98) = 1;
      }
      else {
        iVar8 = *(int *)(param_1 + 0x68);
        if ((iVar8 != 0) && (*(int *)(iVar8 + 0x24) != iVar6)) {
          *(int *)(iVar8 + 0x24) = iVar6;
          *(uint *)(iVar8 + 0x1c) = *(uint *)(iVar8 + 0x1c) | 0x400000;
        }
      }
      iVar6 = *(int *)(param_1 + 0x94);
      if ((iVar6 != 0) && (*(int *)(iVar6 + 0x24) != local_3c)) {
        *(int *)(iVar6 + 0x24) = local_3c;
        *(uint *)(iVar6 + 0x1c) = *(uint *)(iVar6 + 0x1c) | 0x400000;
      }
    }
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4a0ea0 CalcAngleForRPM

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] hud high (ghidra-canon+nfsug) docs/re/canon.md */

float10 __thiscall CalcAngleForRPM(int param_1,float param_2)

{
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  
  fVar1 = (float10)param_2 / (float10)*(float *)(param_1 + 8);
  if ((float10)0.0 <= fVar1) {
    if ((float10)_K_ONE < fVar1) {
      fVar1 = (float10)_K_ONE;
    }
  }
  else {
    fVar1 = (float10)0.0;
  }
  fVar2 = (float10)44.0;
  fVar3 = (float10)215.0;
  if (*(float *)(param_1 + 8) < 10000.0) {
    if (9000.0 <= *(float *)(param_1 + 8)) {
      fVar2 = (float10)50.0;
      fVar3 = (float10)210.0;
    }
  }
  else {
    fVar2 = (float10)45.0;
    fVar3 = (float10)225.0;
  }
  fVar2 = fVar2 + (fVar3 - fVar2) * fVar1;
  if ((float10)360.0 < fVar2) {
    fVar2 = fVar2 - (float10)360.0;
  }
  if (fVar2 < (float10)0.0) {
    fVar2 = (float10)360.0 - fVar2;
  }
  return fVar2;
}


// ==== 0x4a0f50 HudTach::Update

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] hud med (ghidra+hopper) docs/re/hud_input.md */

void HudTach__Update(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  char cVar8;
  uint uVar9;
  int unaff_EBX;
  int iVar10;
  float10 fVar11;
  float local_14;
  float local_10;
  float local_c;
  undefined4 local_8;
  undefined1 local_4 [4];
  
  iVar10 = *(int *)(param_1 + 4);
  if (((DAT_006fbf14 == 0) && (*(int *)(param_1 + 0x10) == 0)) &&
     (iVar5 = RaceManager__FindRacerById(), iVar5 != 0)) {
    iVar10 = iVar5;
  }
  iVar5 = *(int *)(iVar10 + 0xc);
  iVar3 = *(int *)(iVar10 + 0x20);
  if (DAT_007000e4 == 100.0) {
    local_14 = *(float *)(iVar10 + 0x3e0);
  }
  else {
    local_14 = DAT_007000e4;
  }
  if ((*(uint *)(unaff_EBX + 0x18) & *(uint *)(unaff_EBX + 0x10)) != 0 ||
      (*(uint *)(unaff_EBX + 0x1c) & *(uint *)(unaff_EBX + 0x14)) != 0) {
    if (DAT_0078a3f5 == '\x01') {
      local_c = ABS(*(float *)(iVar10 + 0x3d4)) * 3.6;
    }
    else {
      local_c = ABS(*(float *)(iVar10 + 0x3d4)) * 2.237;
    }
    iVar6 = LanguageStrings__FindByHash();
    if (iVar6 == 0) {
      iVar6 = LanguageStrings__FindByHash();
    }
    FEObject__SetFormattedText(iVar6);
    uVar7 = _ftol_nocw();
    FEObject__SetFormattedText(&DAT_006c740c,uVar7);
    if (DAT_0078a320 == 1) {
      fVar11 = (float10)CalcAngleForRPM(local_14,iVar5 + 0xc00);
      FEngSetRotationZ((float)fVar11);
    }
    else {
      FUN_004f6d10(&local_10,&local_8);
      FUN_004f7350(&local_c,&local_8);
      local_c = local_c + local_10;
      local_10 = ((251.0 - local_c) / *(float *)(iVar3 + 500)) * local_14;
      if (280.0 < local_10) {
        local_10 = 280.0;
      }
      FUN_00496040(local_10);
      FUN_004f6d10(local_4,&local_8);
      FUN_004f7000(local_c,local_8);
      FUN_004f6d10(local_4,&local_8);
      FUN_004f7000(local_10 + local_c,local_8);
    }
    if (*(int *)(unaff_EBX + 0x7c) != 0) {
      iVar5 = *(int *)(iVar10 + 1000);
      uVar9 = 0;
      do {
        if (*(int *)(iVar10 + 0x3d8) == (int)(char)(&DAT_006fb7b0)[uVar9 * 2]) {
          cVar8 = *(char *)(uVar9 * 2 + 0x6fb7b1);
          goto LAB_004a1146;
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < 10);
      cVar8 = 'X';
LAB_004a1146:
      FEObject__SetFormattedText(&DAT_006c7408,(int)cVar8);
      if (iVar5 == 0) {
        uVar7 = 0xffff8040;
      }
      else {
        uVar7 = 0xff0080c0;
      }
      FUN_004f75b0(uVar7);
    }
    if ((*(char *)(param_1 + 0x23) == '\x01') ||
       (bVar4 = false, *(char *)(param_1 + 0x23) == '\x03')) {
      bVar4 = true;
    }
    iVar5 = *(int *)(iVar10 + 0x10);
    if (*(char *)(iVar5 + 0x424) == -1) {
      RideInfo__RebuildPhysicsInfo(1);
    }
    iVar3 = *(int *)(iVar10 + 0x3d8);
    fVar1 = *(float *)(&DAT_006fff60 + (iVar3 + *(char *)(iVar5 + 0x424) * 9) * 4);
    if (*(int *)(iVar10 + 0x28) == 1) {
      iVar5 = *(int *)(*(int *)(iVar10 + 0x34) + 0x4c);
      iVar6 = *(int *)(iVar5 + 0xe0);
      fVar1 = *(float *)(&DAT_006fff60 + (iVar6 + iVar3 + iVar6 * 8) * 4) * *(float *)(iVar5 + 0xd8)
      ;
      fVar2 = *(float *)(*(int *)(*(int *)(iVar10 + 0x34) + 0x4c) + 0x80 + iVar3 * 4);
    }
    else if (*(int *)(iVar10 + 0x28) == 3) {
      fVar2 = *(float *)(*(int *)(*(int *)(iVar10 + 0x34) + 0x24) + 0x198 + iVar3 * 4);
    }
    else {
      fVar2 = 0.0;
    }
    if ((local_14 <= fVar2 - _DAT_006fff58 * fVar1) || (!bVar4)) {
      FEObject__SetInvisible(*(undefined4 *)(unaff_EBX + 0x90));
    }
    else {
      FEObject__SetVisible(*(undefined4 *)(unaff_EBX + 0x90));
    }
  }
  if (*(char *)(unaff_EBX + 0x98) != '\0') {
    FEObject__SetInvisible(*(undefined4 *)(unaff_EBX + 0x68));
    FEObject__SetInvisible(*(undefined4 *)(unaff_EBX + 0x94));
  }
  return;
}


