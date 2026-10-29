// ==== 0x4b14e0 FUN_004b14e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004b14e0(int param_1)

{
  int in_EAX;
  
  _DAT_00746de0 = 0x41a00000;
  *(int *)(param_1 + 0x124) = in_EAX;
  if (in_EAX == 0) {
    _DAT_00746de0 = 0x42480000;
  }
  *(int *)(param_1 + 0x8c) = in_EAX;
  SelectCarCameraMover__SetDramaticMode();
  DAT_006fb02c = 0;
  DAT_00735e84 = 0;
  DAT_0074810c = DAT_0073ad3c;
  return;
}


// ==== 0x4b1530 GarageMainScreen::SetCarType

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GarageMainScreen__SetCarType(void)

{
  byte *pbVar1;
  byte bVar2;
  int in_EAX;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  
  pbVar3 = (byte *)(in_EAX * 0xc90 + DAT_00734588);
  if (pbVar3 != (byte *)0x0) {
    pcVar6 = "SECONDARY_LOGO_";
    iVar5 = -1;
    uVar4 = 0x53;
    do {
      iVar5 = iVar5 * 0x21 + uVar4;
      pbVar1 = (byte *)(pcVar6 + 1);
      uVar4 = (uint)*pbVar1;
      pcVar6 = pcVar6 + 1;
    } while (*pbVar1 != 0);
    bVar2 = *pbVar3;
    while (bVar2 != 0) {
      iVar5 = iVar5 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar3 + 1;
      pbVar3 = pbVar3 + 1;
      bVar2 = *pbVar1;
    }
    FUN_004ad7b0(iVar5);
  }
  return;
}


// ==== 0x4b1590 GarageMainScreen::CarLoadingHasStarted

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GarageMainScreen__CarLoadingHasStarted(int param_1,int *param_2)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (in_EAX != 1) {
    if ((in_EAX == 0) || (in_EAX == 2)) {
      FUN_00495fc0();
      FUN_00495f70();
      FEngPrintf("Loading...");
    }
    return;
  }
  bSPrintf_regdst(0x20,"BLUEPRINT_%s",*param_2 * 0xc90 + DAT_00734588);
  uVar2 = FEng__HashName();
  FUN_004ad7b0(uVar2);
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) goto LAB_004b166b;
    iVar3 = FUN_004ef050(0x5d75c3b4);
  }
  if (iVar3 != 0) {
    for (iVar1 = *(int *)(iVar3 + 0x4c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
      iVar4 = FEng__HashName();
      if (*(int *)(iVar1 + 0x30) == iVar4) {
        if (iVar1 != 0) {
          if (iVar1 != *(int *)(iVar3 + 0x54)) {
            *(int *)(iVar3 + 0x54) = iVar1;
            FUN_004ff030(iVar3);
            *(undefined4 *)(*(int *)(iVar3 + 0x54) + 0x10) = 0;
          }
          *(undefined4 *)(iVar1 + 0x10) = 0;
        }
        break;
      }
    }
  }
LAB_004b166b:
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x5d75c3b4);
    }
  }
  FEObject__SetVisible(iVar3);
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c != 0) {
      uVar2 = FUN_004ef050(0xd719922f);
      FEObject__SetInvisible(uVar2);
      return;
    }
    iVar3 = 0;
  }
  FEObject__SetInvisible(iVar3);
  return;
}


// ==== 0x4b1760 FUN_004b1760

void FUN_004b1760(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float10 fVar3;
  float fVar4;
  short sVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float fStack_2e4;
  undefined1 local_2d0 [4];
  float local_2cc;
  float local_2a8 [3];
  undefined4 auStack_29c [64];
  undefined4 auStack_19c [64];
  undefined1 auStack_9c [12];
  undefined1 local_90 [40];
  undefined1 auStack_68 [100];
  
  iVar6 = *(int *)(param_1 + 0x114);
  if (*(int *)(iVar6 + 0x1ca8) != 0) {
    if ((((undefined4 *)(iVar6 + 0x1570) != (undefined4 *)0x0) && (*(int *)(param_1 + 0x90) == 0))
       && (*(int *)(param_1 + 0x9c) == 0)) {
      *(undefined4 *)(param_2 + 0x994) = 1;
      if (DAT_0073458c != 0) {
        RideInfo__RebuildPhysicsInfo(1);
        DAT_0073458c = 0;
      }
      if (*(char *)(iVar6 + 0x1994) == -1) {
        RideInfo__RebuildPhysicsInfo(1);
      }
      fVar4 = (*(float *)(iVar6 + 0x15f0) - *(float *)(iVar6 + 0x15e8)) + DAT_006f1ad4;
      if (param_3 != 0) {
        fVar4 = -fVar4;
      }
      *(undefined4 *)(param_2 + 0x9a0) = 0;
      *(undefined4 *)(param_2 + 0x9a4) = 0;
      uVar2 = *(undefined4 *)(param_1 + 0xf0);
      *(float *)(param_2 + 0x748) = fVar4;
      *(undefined4 *)(param_2 + 0x740) = uVar2;
      *(undefined4 *)(param_2 + 0x744) = 0;
      eIdentity();
      if (param_3 != 0) {
        local_2cc = -local_2cc;
        local_2a8[0] = -local_2a8[0];
      }
      FUN_0040b930();
      D3DXMatrixMultiply(local_2d0,local_2d0,local_90);
      bMatrixCopy_b();
      CallNTimes(auStack_29c,0x40,4,FUN_004ad8d0);
      CallNTimes(auStack_19c,0x40,4,FUN_004ad8d0);
      _ftol_nocw();
      fStack_2e4 = 0.0;
      if (*(int *)(param_1 + 0x10c) != 0) {
        sVar5 = _ftol_nocw();
        fVar3 = (float10)DAT_0073ad38;
        *(short *)(param_1 + 0x108) = *(short *)(param_1 + 0x108) + sVar5;
        fStack_2e4 = (float)((extraout_ST1 / fVar3) / extraout_ST0);
      }
      puVar7 = (undefined4 *)(iVar6 + 0x1570);
      iVar6 = 0;
      do {
        *(undefined4 *)((int)auStack_29c + iVar6) = 0x3f800000;
        *(undefined4 *)((int)auStack_29c + iVar6 + 4) = 0;
        *(undefined4 *)((int)auStack_29c + iVar6 + 8) = 0;
        *(undefined4 *)((int)auStack_29c + iVar6 + 0xc) = 0;
        *(undefined4 *)((int)auStack_29c + iVar6 + 0x10) = 0;
        *(undefined4 *)((int)auStack_29c + iVar6 + 0x14) = 0x3f800000;
        *(undefined4 *)((int)auStack_29c + iVar6 + 0x18) = 0;
        *(undefined4 *)((int)auStack_29c + iVar6 + 0x1c) = 0;
        *(undefined4 *)((int)auStack_29c + iVar6 + 0x20) = 0;
        *(undefined4 *)((int)auStack_29c + iVar6 + 0x24) = 0;
        *(undefined4 *)((int)auStack_29c + iVar6 + 0x28) = 0x3f800000;
        *(undefined4 *)((int)auStack_29c + iVar6 + 0x2c) = 0;
        *(undefined4 *)((int)auStack_29c + iVar6 + 0x30) = 0;
        *(undefined4 *)((int)auStack_29c + iVar6 + 0x34) = 0;
        *(undefined4 *)((int)auStack_29c + iVar6 + 0x38) = 0;
        *(undefined4 *)((int)auStack_29c + iVar6 + 0x3c) = 0x3f800000;
        *(undefined4 *)((int)auStack_19c + iVar6) = 0x3f800000;
        *(undefined4 *)((int)auStack_19c + iVar6 + 4) = 0;
        *(undefined4 *)((int)auStack_19c + iVar6 + 8) = 0;
        *(undefined4 *)((int)auStack_19c + iVar6 + 0xc) = 0;
        *(undefined4 *)((int)auStack_19c + iVar6 + 0x10) = 0;
        *(undefined4 *)((int)auStack_19c + iVar6 + 0x14) = 0x3f800000;
        *(undefined4 *)((int)auStack_19c + iVar6 + 0x18) = 0;
        *(undefined4 *)((int)auStack_19c + iVar6 + 0x1c) = 0;
        *(undefined4 *)((int)auStack_19c + iVar6 + 0x20) = 0;
        *(undefined4 *)((int)auStack_19c + iVar6 + 0x24) = 0;
        *(undefined4 *)((int)auStack_19c + iVar6 + 0x28) = 0x3f800000;
        *(undefined4 *)((int)auStack_19c + iVar6 + 0x2c) = 0;
        *(undefined4 *)((int)auStack_19c + iVar6 + 0x30) = 0;
        *(undefined4 *)((int)auStack_19c + iVar6 + 0x34) = 0;
        *(undefined4 *)((int)auStack_19c + iVar6 + 0x38) = 0;
        *(undefined4 *)((int)auStack_19c + iVar6 + 0x3c) = 0x3f800000;
        FUN_0040ba40();
        if (iVar6 < 0x41) {
          FUN_0040b930();
          D3DXMatrixMultiply((int)auStack_19c + iVar6,(int)auStack_19c + iVar6,auStack_9c);
          FUN_0040b930();
          D3DXMatrixMultiply((int)local_2a8 + iVar6,(int)local_2a8 + iVar6,auStack_68);
        }
        uVar2 = puVar7[-1];
        uVar1 = *puVar7;
        *(undefined4 *)((int)auStack_29c + iVar6 + 0x30) = puVar7[-2];
        *(undefined4 *)((int)auStack_29c + iVar6 + 0x34) = uVar2;
        *(undefined4 *)((int)auStack_29c + iVar6 + 0x3c) = 0x3f800000;
        *(undefined4 *)((int)auStack_29c + iVar6 + 0x38) = uVar1;
        uVar2 = puVar7[-1];
        iVar8 = iVar6 + 0x40;
        uVar1 = *puVar7;
        *(undefined4 *)((int)auStack_19c + iVar6 + 0x30) = puVar7[-2];
        *(undefined4 *)((int)auStack_19c + iVar6 + 0x34) = uVar2;
        *(undefined4 *)((int)auStack_19c + iVar6 + 0x3c) = 0x3f800000;
        *(undefined4 *)((int)auStack_19c + iVar6 + 0x38) = uVar1;
        puVar7 = puVar7 + 0xc;
        iVar6 = iVar8;
      } while (iVar8 < 0x100);
      iVar6 = 4;
      do {
        bMatrixCopy_b();
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      iVar6 = 4;
      do {
        bMatrixCopy_b();
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      *(float *)(param_2 + 0x9a8) = fStack_2e4;
      return;
    }
  }
  *(undefined4 *)(param_2 + 0x994) = 0;
  return;
}


// ==== 0x4b1b70 FUN_004b1b70

void FUN_004b1b70(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((DAT_006f1dfc != 0) && (*(int *)(param_1 + 0x90) == 0)) {
    iVar1 = *(int *)(param_1 + 0x110);
    iVar2 = ScratchAlloc64xN();
    if ((DAT_00735768 == '\0') && (iVar2 != 0)) {
      eIdentity();
      *(undefined4 *)(iVar2 + 0x30) = 0;
      *(undefined4 *)(iVar2 + 0x34) = 0;
      *(undefined4 *)(iVar2 + 0x38) = 0;
      bDegreesToAngle16(0);
      FUN_0040baf0(iVar2,iVar2);
      bDegreesToAngle16(0);
      FUN_0040b990(iVar2,iVar2);
      bDegreesToAngle16(0);
      FUN_0040ba40(iVar2,iVar2);
      if (DAT_006fb038 == 0) {
        FUN_0040c910(&DAT_00740460 + iVar1 * 0x18,param_1 + 0x48,iVar2,0,0);
      }
    }
  }
  return;
}


// ==== 0x4b1c50 FUN_004b1c50

void FUN_004b1c50(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(in_EAX + 0xc) != 0) {
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004b1c9a;
    }
  }
  if (DAT_0073578c != 0) {
    uVar2 = FUN_004ef050(0x3b7f8ae);
    FEObject__SetInvisible(uVar2);
    return;
  }
  iVar1 = 0;
LAB_004b1c9a:
  FEObject__SetInvisible(iVar1);
  return;
}


// ==== 0x4b1cb0 FUN_004b1cb0

void FUN_004b1cb0(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(in_EAX + 0x94) != 0) {
    return;
  }
  if (((*(int *)(in_EAX + 0xc) == 0) || (iVar1 = FEngFindPackage(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c != 0) {
      uVar2 = FUN_004ef050(0x3b7f8ae);
      FEObject__SetVisible(uVar2);
      return;
    }
    iVar1 = 0;
  }
  FEObject__SetVisible(iVar1);
  return;
}


// ==== 0x4b1d20 FUN_004b1d20

void FUN_004b1d20(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(in_EAX + 0xa0) == 0) {
    if (*(int *)(in_EAX + 0xc) != 0) {
      iVar1 = FEngFindPackage();
      if (iVar1 != 0) {
        iVar1 = FUN_004ffb70();
        if (iVar1 != 0) goto LAB_004b1dc1;
      }
    }
    if (DAT_0073578c != 0) {
      uVar2 = FUN_004ef050(0xf80dbcae);
      FEObject__SetVisible(uVar2);
      return;
    }
    iVar1 = 0;
LAB_004b1dc1:
    FEObject__SetVisible(iVar1);
    return;
  }
  if (*(int *)(in_EAX + 0xc) != 0) {
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004b1d72;
    }
  }
  if (DAT_0073578c != 0) {
    uVar2 = FUN_004ef050(0xf80dbcae);
    FEObject__SetInvisible(uVar2);
    return;
  }
  iVar1 = 0;
LAB_004b1d72:
  FEObject__SetInvisible(iVar1);
  return;
}


// ==== 0x4b1dd0 FUN_004b1dd0

void __thiscall FUN_004b1dd0(int param_1,uint param_2)

{
  if (param_2 < 0x56aa7e47) {
    if (param_2 == 0x56aa7e46) {
      *(undefined4 *)(param_1 + 0xa0) = 0;
      FUN_004b1d20();
      return;
    }
    if (param_2 < 0x18883f76) {
      if (param_2 == 0x18883f75) {
        *(undefined4 *)(param_1 + 0x90) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x994) = 1;
        *(undefined4 *)(*(int *)(param_1 + 0x44) + 0x994) = 1;
        return;
      }
      if (param_2 == 0xb7fc3e) {
        *(undefined4 *)(param_1 + 0x98) = 0;
        return;
      }
      if (param_2 == 0xad4bbdc) {
        *(undefined4 *)(param_1 + 0x90) = 1;
        *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x994) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x44) + 0x994) = 0;
        return;
      }
    }
    else {
      if (param_2 == 0x2401cd38) {
        *(undefined4 *)(param_1 + 0x94) = 1;
        FUN_004b1c50(0x2401cd38);
        return;
      }
      if (param_2 == 0x32c72d8f) {
        FUN_004b1b70(param_1,0x32c72d8f);
        return;
      }
    }
  }
  else if (param_2 < 0x8efaa778) {
    if (param_2 == 0x8efaa777) {
      *(undefined4 *)(param_1 + 0x98) = 1;
      return;
    }
    if (param_2 == 0x645e01df) {
      *(undefined4 *)(param_1 + 0xa0) = 1;
      FUN_004b1d20();
      return;
    }
    if (param_2 == 0x6c6603df) {
      *(undefined4 *)(param_1 + 0x94) = 0;
      FUN_004b1cb0(0x6c6603df);
      return;
    }
  }
  else if (param_2 == 0xc98356ba) {
    FUN_004b0340(0xc98356ba);
    FUN_004b0c00();
  }
  return;
}


// ==== 0x4b1f10 Screen_background::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_background__Create(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006873a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x40);
  local_4 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FEScreen__FEScreen(puVar1,param_1);
    *puVar1 = &PTR_FUN_006c6200;
    puVar2 = puVar1;
  }
  ExceptionList = local_c;
  return puVar2;
}


// ==== 0x4b1f70 FUN_004b1f70

void * __thiscall FUN_004b1f70(void *param_1,byte param_2)

{
  FUN_004b1f90();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4b1f90 FUN_004b1f90

void __fastcall FUN_004b1f90(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c6200;
  FUN_004f7b50();
  return;
}


// ==== 0x4b1fa0 FUN_004b1fa0

undefined4 FUN_004b1fa0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689553;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x48);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_004b2070(pvVar1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4b2000 FUN_004b2000

undefined4 FUN_004b2000(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_00689533;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = _malloc(0x128);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GarageMainScreen__GarageMainScreen(pvVar1,param_1,1,&DAT_00748850,0,0xfffffffe);
    ExceptionList = local_10;
    return uVar2;
  }
  ExceptionList = local_10;
  return 0;
}


// ==== 0x4b2070 FUN_004b2070

undefined4 * __thiscall FUN_004b2070(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 uVar4;
  void *local_10;
  code *pcStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_0068950a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_2,param_1);
  uVar2 = DAT_00792fa0 & 1;
  local_8._1_3_ = 0;
  *param_2 = &PTR_FUN_006c61f0;
  if (uVar2 == 0) {
    DAT_00792fa0 = DAT_00792fa0 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    eh_vector_constructor_iterator(&DAT_0078f620,0x1cc0,2,FUN_004aefa0,FUN_004af020);
    _atexit(FUN_006964a0);
  }
  local_8._0_1_ = 0;
  FUN_004af030();
  if ((DAT_00792fa0 & 1) == 0) {
    DAT_00792fa0 = DAT_00792fa0 | 1;
    local_8._0_1_ = 2;
    eh_vector_constructor_iterator(&DAT_0078f620,0x1cc0,2,FUN_004aefa0,FUN_004af020);
    _atexit(FUN_006964a0);
    local_8._0_1_ = 0;
  }
  FUN_004af030();
  pvVar3 = _malloc(0x128);
  local_8._0_1_ = 3;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = GarageMainScreen__GarageMainScreen(pvVar3,param_1,1,&DAT_00748850,0,DAT_00748f78);
  }
  param_2[0x10] = uVar4;
  pvVar3 = _malloc(0x128);
  local_8._0_1_ = 4;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = GarageMainScreen__GarageMainScreen(pvVar3,param_1,2,&DAT_00748120,1,DAT_00748f7c);
  }
  iVar1 = param_2[0x10];
  param_2[0x11] = uVar4;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_004ae9a0();
  *(undefined4 *)(iVar1 + 0x84) = 1;
  iVar1 = param_2[0x11];
  FUN_004ae9a0();
  *(undefined4 *)(iVar1 + 0x84) = 1;
  ExceptionList = local_10;
  return param_2;
}


// ==== 0x4b2200 FUN_004b2200

void * __thiscall FUN_004b2200(void *param_1,byte param_2)

{
  FUN_004b2280();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4b2220 FUN_004b2220

void FUN_004b2220(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0x14), iVar2 != 0)) {
    iVar1 = *(int *)(iVar2 + 0x40);
    FUN_004ae9a0();
    *(undefined4 *)(iVar1 + 0x84) = 1;
    iVar2 = *(int *)(iVar2 + 0x44);
    FUN_004ae9a0();
    *(undefined4 *)(iVar2 + 0x84) = 1;
  }
  return;
}


// ==== 0x4b2280 FUN_004b2280

void __fastcall FUN_004b2280(undefined4 *param_1)

{
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_006879f8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c61f0;
  local_4 = 0;
  if ((undefined4 *)param_1[0x10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x10])(1);
  }
  if ((undefined4 *)param_1[0x11] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x11])(1);
  }
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4b22f0 FUN_004b22f0

void __thiscall
FUN_004b22f0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 unaff_ESI;
  
  (**(code **)(**(int **)(param_1 + 0x40) + 8))(param_2,param_3,param_4,param_5);
  (**(code **)(**(int **)(param_1 + 0x44) + 8))(unaff_ESI,param_3,param_4,param_5);
  return;
}


// ==== 0x4b2330 FUN_004b2330

undefined4 FUN_004b2330(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x18) == 0)) {
    iVar1 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) {
      iVar1 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0x14), iVar1 != 0)) {
        if (unaff_ESI == 0) {
          return *(undefined4 *)(iVar1 + 0x40);
        }
        if (unaff_ESI == 1) {
          return *(undefined4 *)(iVar1 + 0x44);
        }
      }
    }
  }
  else {
    iVar1 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar1 != 0) {
      return *(undefined4 *)(iVar1 + 0x14);
    }
  }
  return 0;
}


// ==== 0x4b23b0 FUN_004b23b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b23b0(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_004b2330();
  puVar2 = (undefined4 *)&DAT_00748120;
  if (in_EAX != 1) {
    puVar2 = &DAT_00748850;
  }
  RideInfo__operator_(puVar2,param_1);
  if (puVar2 == &DAT_00748850) {
    _DAT_0072cc80 = param_2;
  }
  else if (puVar2 == (undefined4 *)&DAT_00748120) {
    _DAT_0072cc7c = param_2;
  }
  if (iVar1 != 0) {
    GarageMainScreen__SetRideInfo(iVar1,puVar2,param_2);
  }
  return;
}


// ==== 0x4b2410 FUN_004b2410

void FUN_004b2410(void)

{
  int iVar1;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int **)(iVar1 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x14) + 8))(0xad4bbdc,0,0,*(int *)(iVar1 + 0x18));
  }
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int **)(iVar1 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x14) + 8))(0xad4bbdc,0,0,*(int *)(iVar1 + 0x18));
  }
  return;
}


// ==== 0x4b2480 FUN_004b2480

void FUN_004b2480(void)

{
  int iVar1;
  
  iVar1 = FUN_004b2330();
  if (iVar1 != 0) {
    FUN_004b14e0();
  }
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x18) == 0)) {
    iVar1 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar1 == 0) {
      return;
    }
    if (*(int *)(iVar1 + 0x18) == 0) {
      return;
    }
    iVar1 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar1 == 0) {
      return;
    }
    if (*(int *)(iVar1 + 0x14) == 0) {
      return;
    }
    iVar1 = *(int *)(*(int *)(iVar1 + 0x14) + 0x44);
  }
  else {
    iVar1 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x14);
    }
  }
  if (iVar1 == 0) {
    return;
  }
  FUN_004b14e0();
  return;
}


// ==== 0x4b2520 FUN_004b2520

void FUN_004b2520(void)

{
  int iVar1;
  undefined4 unaff_EDI;
  
  iVar1 = FUN_004b2330();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10c) = unaff_EDI;
  }
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x18) == 0)) {
    iVar1 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar1 == 0) {
      return;
    }
    if (*(int *)(iVar1 + 0x18) == 0) {
      return;
    }
    iVar1 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar1 == 0) {
      return;
    }
    if (*(int *)(iVar1 + 0x14) == 0) {
      return;
    }
    iVar1 = *(int *)(*(int *)(iVar1 + 0x14) + 0x44);
  }
  else {
    iVar1 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x14);
    }
  }
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10c) = unaff_EDI;
  }
  return;
}


// ==== 0x4b25b0 PresetRide::Loader

/* [canon] assets high (Hopper sub_4b25b0 + Ghidra make FUN_004b25b0: H+G agree) docs/re/assets.md
    */

undefined4 PresetRide__Loader(int *param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  
  if (*param_1 == 0x30220) {
    piVar2 = param_1 + 2;
    piVar1 = DAT_00748848;
    for (uVar3 = (uint)param_1[1] / 0x408; uVar3 != 0; uVar3 = uVar3 - 1) {
      *piVar1 = (int)piVar2;
      DAT_00748848 = piVar2;
      piVar2[1] = (int)piVar1;
      *piVar2 = (int)&DAT_00748844;
      piVar2 = piVar2 + 0x102;
      piVar1 = DAT_00748848;
    }
    DAT_00748848 = piVar1;
    return 1;
  }
  return 0;
}


// ==== 0x4b2600 PresetRide::Unloader

/* [canon] assets high (Ghidra make FUN_004b2600 (Hopper export lacks it)) docs/re/assets.md */

undefined4 PresetRide__Unloader(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (*param_1 == 0x30220) {
    while ((int **)DAT_00748844 != &DAT_00748844) {
      iVar1 = *DAT_00748844;
      piVar2 = (int *)DAT_00748844[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
    }
    return 1;
  }
  return 0;
}


// ==== 0x4b2640 PresetRide::FindByKeyHash

/* [canon] rivals I (capstone) docs/re/rivals.md */

undefined4 * PresetRide__FindByKeyHash(int param_1)

{
  byte *pbVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  byte bVar4;
  int iVar5;
  byte *pbVar6;
  
  puVar2 = DAT_00748844;
  puVar3 = (undefined4 *)NullUpdate_ret();
  while( true ) {
    if (puVar2 == puVar3) {
      return (undefined4 *)0x0;
    }
    pbVar6 = (byte *)(puVar2 + 10);
    iVar5 = -1;
    if (pbVar6 != (byte *)0x0) {
      bVar4 = *pbVar6;
      while (bVar4 != 0) {
        if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
          bVar4 = bVar4 - 0x20;
        }
        iVar5 = iVar5 * 0x21 + (uint)bVar4;
        pbVar1 = pbVar6 + 1;
        pbVar6 = pbVar6 + 1;
        bVar4 = *pbVar1;
      }
    }
    if (param_1 == iVar5) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  return puVar2;
}


// ==== 0x4b26b0 FUN_004b26b0

undefined4 FUN_004b26b0(void)

{
  int in_EAX;
  
  if ((0x1e < in_EAX) && (in_EAX < 0x23)) {
    return 1;
  }
  return 0;
}


// ==== 0x4b26d0 FUN_004b26d0

undefined4 FUN_004b26d0(void)

{
  int in_EAX;
  
  if ((0x3a < in_EAX) && (in_EAX < 0x73)) {
    return 1;
  }
  return 0;
}


// ==== 0x4b26f0 PresetRide::ApplyToRide

/* [canon] rivals V (Ghidra+Hopper+capstone) docs/re/rivals.md */

void PresetRide__ApplyToRide(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int extraout_EDX;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int local_8;
  
  iVar4 = PresetRide__FindByKeyHash();
  if (iVar4 != 0) {
    iVar7 = iVar4 + 8;
    iVar11 = -1;
    bVar2 = *(byte *)(iVar4 + 8);
    while (bVar2 != 0) {
      pbVar1 = (byte *)(iVar7 + 1);
      iVar11 = iVar11 * 0x21 + (uint)bVar2;
      iVar7 = iVar7 + 1;
      bVar2 = *pbVar1;
    }
    iVar7 = GetCarTypeInfo();
    if (iVar7 != 0) {
      uVar14 = *(undefined4 *)(param_1 + 0x448);
      uVar15 = *(undefined4 *)(param_1 + 0x444);
      Ride_Init(*(undefined4 *)(iVar7 + 0xc74),0,0);
      piVar9 = (int *)(iVar4 + 0x4c);
      *(undefined4 *)(extraout_EDX + 0x444) = uVar15;
      *(undefined4 *)(extraout_EDX + 0x448) = uVar14;
      local_8 = 0x78;
      do {
        iVar4 = piVar9[-1];
        iVar7 = *piVar9;
        uVar10 = 0;
        if ((((((((iVar4 == 0x1e) || (iVar4 == 0x2a)) || (iVar4 == 0x2b)) ||
               ((iVar4 == 0x2c || (iVar4 == 0x2d)))) || (iVar4 == 0x2e)) ||
             (((iVar4 == 0x2f || (iVar4 == 0x30)) ||
              ((iVar4 == 0x31 || (((iVar4 == 0x32 || (iVar4 == 0x33)) || (iVar4 == 0x34)))))))) ||
            ((iVar4 == 0x35 || (iVar4 == 0x36)))) ||
           ((iVar4 == 0x37 ||
            (((iVar4 == 0x38 || (iVar4 == 0x39)) ||
             ((iVar4 == 0x29 || (((iVar4 == 0x28 || (iVar4 == 0x26)) || (iVar4 == 0x27)))))))))) {
          if (iVar7 == 0) {
            uVar10 = 0;
          }
          else {
            uVar10 = CarPartDatabase__GetCarPart(0,0x1e,iVar7,0,0xffffffff);
          }
LAB_004b2a4b:
          if (((iVar4 != 0x13) && (-1 < iVar4)) && (iVar4 < 0x79)) goto LAB_004b2a59;
        }
        else {
          cVar3 = FUN_004b26b0();
          if (cVar3 != '\0') {
            uVar10 = FUN_004bc790();
            goto LAB_004b2a4b;
          }
          cVar3 = FUN_004b26d0();
          piVar8 = DAT_0073ad40;
          if (cVar3 != '\0') {
            if (iVar7 != 0) {
              uVar10 = CarPartDatabase__GetCarPart(0,0x3a,iVar7,0,0xffffffff);
            }
            goto LAB_004b2a4b;
          }
          if (iVar4 == 0x12) {
            piVar5 = (int *)NullUpdate_ret();
            if (piVar8 != piVar5) {
              while( true ) {
                iVar12 = piVar8[4];
                iVar13 = piVar8[3];
                uVar10 = BinarySearch_Hash(0x7326cf08,iVar13,4);
                if (uVar10 == 0) break;
                for (; uVar10 < (uint)(iVar12 * 0x30 + iVar13); uVar10 = uVar10 + 0x30) {
                  if (*(int *)(uVar10 + 4) != 0x7326cf08) goto LAB_004b290a;
                  if ((*(char *)(uVar10 + 0x10) == '\x12') &&
                     ((iVar7 == 0 || (*(int *)(uVar10 + 8) == iVar7)))) goto LAB_004b2a59;
                }
                piVar8 = (int *)*piVar8;
                if (piVar8 == piVar5) break;
              }
            }
LAB_004b290a:
            uVar10 = 0;
          }
          else if (iVar4 == 6) {
            if (iVar7 != 0) {
              uVar10 = CarPartDatabase__GetCarPart(iVar11,6,iVar7,0,0xffffffff);
            }
          }
          else {
            uVar15 = 0xffffffff;
            uVar14 = 0;
            if (iVar4 == 0x11) {
              iVar12 = iVar4;
              iVar13 = iVar7;
              uVar6 = bStringHash(0x11);
              uVar10 = CarPartDatabase__GetCarPart(uVar6,iVar12,iVar13,uVar14,uVar15);
              if (uVar10 == 0) {
                uVar10 = CarPartDatabase__GetCarPart(iVar11,0x11,iVar7,0,0xffffffff);
              }
            }
            else {
              if (iVar4 == 0xf) {
                uVar10 = CarPartDatabase__GetCarPart(iVar11,0xf,iVar7,0,0xffffffff);
              }
              else if (iVar4 == 0x73) {
                uVar10 = CarPartDatabase__GetCarPart(iVar11,0x73,iVar7,0,0xffffffff);
              }
              else if (iVar4 == 0x10) {
                uVar10 = CarPartDatabase__GetCarPart(iVar11,0x10,iVar7,0,0xffffffff);
              }
              else {
                if (iVar4 != 0x74) {
                  uVar10 = CarPartDatabase__GetCarPart(iVar11,iVar4,iVar7,0,0xffffffff);
                  goto LAB_004b2a4b;
                }
                uVar10 = CarPartDatabase__GetCarPart(iVar11,0x74,iVar7,0,0xffffffff);
              }
              if (uVar10 == 0) {
                uVar15 = 0;
                uVar6 = 0xffffffff;
                iVar12 = iVar4;
                uVar14 = bStringHash(iVar4,iVar7,0,0xffffffff);
                uVar10 = CarPartDatabase__GetCarPart(uVar14,iVar12,iVar7,uVar15,uVar6);
              }
            }
          }
LAB_004b2a59:
          *(uint *)(param_1 + 0x44c + iVar4 * 4) = uVar10;
          *(char *)(iVar4 + 0x62c + param_1) = *(char *)(iVar4 + 0x62c + param_1) + '\x01';
          RideInfo__UpdatePartsEnabled(param_1);
        }
        piVar9 = piVar9 + 2;
        local_8 = local_8 + -1;
      } while (local_8 != 0);
    }
  }
  return;
}


// ==== 0x4b2aa0 Career::IsEventWon

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

uint __fastcall Career__IsEventWon(uint param_1,int param_2)

{
  char *pcVar1;
  uint *puVar2;
  
  if (((0xff < param_1) || ((&DAT_00733ff8)[param_1] == 0)) &&
     ((*(int *)(param_2 + 0x88b0) == 0 ||
      ((puVar2 = (uint *)(*(int *)(param_2 + 0x88b0) + 0x58a0), puVar2 == (uint *)0x0 ||
       (param_1 != *puVar2)))))) {
    return (uint)(cRam00000000 == '\x02');
  }
  pcVar1 = (char *)(param_1 + 0x34c + param_2);
  return CONCAT31((int3)((uint)pcVar1 >> 8),*pcVar1 == '\x02');
}


// ==== 0x4b2af0 Career::IsFinalEventWon

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

uint __fastcall Career__IsFinalEventWon(int param_1)

{
  int *piVar1;
  
  if ((DAT_007341bc == 0) &&
     (((*(int *)(param_1 + 0x88b0) == 0 ||
       (piVar1 = (int *)(*(int *)(param_1 + 0x88b0) + 0x58a0), piVar1 == (int *)0x0)) ||
      (*piVar1 != 0x71)))) {
    return (uint)(cRam00000000 == '\x02');
  }
  return CONCAT31((int3)((uint)(param_1 + 0x3bd) >> 8),*(char *)(param_1 + 0x3bd) == '\x02');
}


// ==== 0x4b2b40 FUN_004b2b40

void __fastcall FUN_004b2b40(undefined4 param_1,int param_2)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 8 + param_2 * 4) = param_1;
  return;
}


// ==== 0x4b2b50 Screen_MU_Main_PC::OnInputActivity

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void Screen_MU_Main_PC__OnInputActivity(void)

{
  int in_stack_00000010;
  
  if (in_stack_00000010 != 0) {
    *(undefined4 *)(in_stack_00000010 + 0x44) = DAT_0073ad3c;
  }
  return;
}


// ==== 0x4b2b70 Screen_MU_Main_PC::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_Main_PC__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689303;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x4c);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_Main_PC__Screen_MU_Main_PC(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4b2bd0 FUN_004b2bd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004b2bd0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c614c;
  FUN_005740b0(0x2f);
  FUN_005740b0(0x2f);
  DAT_00737660 = 0;
  DAT_00737661 = 0;
  _DAT_00737664 = 0;
  _DAT_00737690 = 0;
  FUN_004f7b50();
  return;
}


// ==== 0x4b2c10 FUN_004b2c10

void * __thiscall FUN_004b2c10(void *param_1,byte param_2)

{
  FUN_004b2bd0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4b2c30 Screen_MU_Main_PC::Screen_MU_Main_PC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon low (capstone) docs/re/gameflow.md */

void Screen_MU_Main_PC__Screen_MU_Main_PC(undefined4 *param_1,undefined4 param_2)

{
  byte *pbVar1;
  char *pcVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  byte *pbVar8;
  char *pcVar9;
  undefined1 local_770 [1092];
  int local_32c;
  int local_328;
  byte local_44;
  byte local_43 [31];
  int local_24;
  undefined1 *puStack_20;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  pcStack_18 = FUN_006887db;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  FEScreen__FEScreen(param_1,param_2);
  *param_1 = &PTR_FUN_006c614c;
  param_1[0x11] = 0;
  local_14 = 0;
  DAT_00735e78 = 0;
  param_1[0x11] = DAT_0073ad3c;
  InputEvents__AddSource(0x2f,Screen_MU_Main_PC__OnInputActivity,param_1);
  InputEvents__AddSource(0x2f,Screen_MU_Main_PC__OnInputActivity,param_1);
  iVar4 = param_1[3];
  local_24 = FEng__HashName();
  if (((((iVar4 == 0) || (iVar4 = FEngFindPackage(), iVar4 == 0)) ||
       (iVar4 = FUN_004ffb70(), iVar4 == 0)) &&
      ((DAT_0073578c == 0 || (iVar4 = FUN_004ef050(local_24), iVar4 == 0)))) ||
     (*(int *)(iVar4 + 0x18) != 2)) {
    iVar4 = 0;
  }
  param_1[0x10] = iVar4;
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  iVar4 = DAT_0073578c;
  if (((iVar5 != 0) && (*(int *)(iVar5 + 0x18) != 0)) &&
     ((DAT_0073578c != 0 &&
      ((iVar5 = FEPackageList__FindByName(&DAT_00746104), iVar5 != 0 &&
       (*(int *)(iVar5 + 0x18) != 0)))))) {
    cFEng__PopPackage(*(undefined4 *)(iVar4 + 8),*(int *)(iVar5 + 0x18));
  }
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  iVar4 = DAT_0073578c;
  if ((((iVar5 != 0) && (*(int *)(iVar5 + 0x18) != 0)) && (DAT_0073578c != 0)) &&
     ((iVar5 = FEPackageList__FindByName(&DAT_00746104), iVar5 != 0 && (*(int *)(iVar5 + 0x18) != 0)
      ))) {
    cFEng__PopPackage(*(undefined4 *)(iVar4 + 8),*(int *)(iVar5 + 0x18));
  }
  if (DAT_0078eb10 == 0) {
    DAT_0078eb10 = 1;
    FUN_00565da0("DUMMY_SKIN%d",1);
    pbVar8 = &local_44;
    local_24 = -1;
    bVar3 = local_44;
    while (bVar3 != 0) {
      uVar6 = (uint)bVar3;
      bVar3 = pbVar8[1];
      pbVar8 = pbVar8 + 1;
      local_24 = local_24 * 0x21 + uVar6;
    }
    FUN_00565da0("DUMMY_WHEEL%d",1);
    iVar4 = -1;
    pbVar8 = &local_44;
    while (local_44 != 0) {
      pbVar1 = pbVar8 + 1;
      iVar4 = iVar4 * 0x21 + (uint)local_44;
      pbVar8 = pbVar8 + 1;
      local_44 = *pbVar1;
    }
    RideInfo__Init();
    Ride_BuildFromPartDatabase();
    pcVar9 = "FE_SKYLINE";
    do {
      pcVar2 = pcVar9 + 1;
      pcVar9 = pcVar9 + 1;
    } while (*pcVar2 != '\0');
    PresetRide__ApplyToRide(local_770);
    local_32c = local_24;
    local_328 = iVar4;
    iVar4 = FUN_004b2330();
    RideInfo__operator_(&DAT_00748850,local_770);
    _DAT_0072cc80 = 1;
    if (iVar4 != 0) {
      GarageMainScreen__SetRideInfo(iVar4,&DAT_00748850,1);
    }
  }
  iVar4 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar4 == 0) || (*(int *)(iVar4 + 0x18) == 0)) {
    FEngPushGarageMainPackage();
  }
  iVar4 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar4 != 0) && (*(int *)(iVar4 + 0x18) != 0)) && (*(int **)(iVar4 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar4 + 0x14) + 8))(0x18883f75,0,0,*(int *)(iVar4 + 0x18));
  }
  FUN_004b2480();
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  iVar4 = DAT_0073578c;
  if (((iVar5 != 0) && (*(int *)(iVar5 + 0x18) != 0)) &&
     ((DAT_0073578c != 0 &&
      ((iVar5 = FEPackageList__FindByName(&DAT_00746104), iVar5 != 0 &&
       (*(int *)(iVar5 + 0x18) != 0)))))) {
    cFEng__PopPackage(*(undefined4 *)(iVar4 + 8),*(int *)(iVar5 + 0x18));
  }
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  iVar4 = DAT_0073578c;
  if ((((iVar5 != 0) && (*(int *)(iVar5 + 0x18) != 0)) && (DAT_0073578c != 0)) &&
     ((iVar5 = FEPackageList__FindByName(&DAT_00746104), iVar5 != 0 && (*(int *)(iVar5 + 0x18) != 0)
      ))) {
    cFEng__PopPackage(*(undefined4 *)(iVar4 + 8),*(int *)(iVar5 + 0x18));
  }
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  iVar4 = DAT_0073578c;
  if (((iVar5 != 0) && (*(int *)(iVar5 + 0x18) != 0)) &&
     ((DAT_0073578c != 0 &&
      ((iVar5 = FEPackageList__FindByName(&DAT_00746104), iVar5 != 0 &&
       (*(int *)(iVar5 + 0x18) != 0)))))) {
    cFEng__PopPackage(*(undefined4 *)(iVar4 + 8),*(int *)(iVar5 + 0x18));
  }
  iVar4 = param_1[3];
  uVar7 = Screen_MU_Main_PC__MenuBitToObjectHash(param_1);
  if (((((iVar4 != 0) && (iVar4 = FEngFindPackage(), iVar4 != 0)) &&
       (iVar4 = FUN_004ffb70(), iVar4 != 0)) ||
      ((DAT_0073578c != 0 && (iVar4 = FUN_004ef050(uVar7), iVar4 != 0)))) &&
     ((*(int *)(iVar4 + 0x18) == 2 && (DAT_0073578c != 0)))) {
    cFEng__SetCurrentButton(DAT_0073578c);
  }
  iVar4 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar4 != 0) && (*(int *)(iVar4 + 0x18) != 0)) && (*(int **)(iVar4 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar4 + 0x14) + 8))(0x2401cd38,0,0,*(int *)(iVar4 + 0x18));
  }
  DAT_00737660 = 1;
  DAT_00737661 = 0;
  _DAT_00737664 = 0;
  _DAT_00737690 = 0;
  *(undefined1 *)(param_1 + 0x12) = 0;
  DAT_00748f75 = 0;
  ExceptionList = local_1c;
  return;
}


// ==== 0x4b30b0 Screen_MU_Main_PC::MenuBitToObjectHash

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

undefined4 Screen_MU_Main_PC__MenuBitToObjectHash(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  default:
    return 0xd7ba6011;
  case 2:
    return 0xde511657;
  case 4:
    return 0x11793157;
  case 8:
    return 0x70fbb1e4;
  case 0x10:
    return 0x95ad096b;
  case 0x20:
    return 0xa936c3a2;
  case 0x40:
    return 0x14d83e4e;
  case 0x80:
    return 0xf20e404a;
  }
}


// ==== 0x4b31b0 Screen_MU_Main_PC::ObjectHashToTextHash

/* [canon] canon med (ghidra-canon+hopper) docs/re/canon.md */

undefined4 Screen_MU_Main_PC__ObjectHashToTextHash(void)

{
  uint in_EAX;
  
  if (in_EAX < 0xa936c3a3) {
    if (in_EAX == 0xa936c3a2) {
      return 0x1e01ba04;
    }
    if (in_EAX < 0x70fbb1e5) {
      if (in_EAX == 0x70fbb1e4) {
        return 0x38b97386;
      }
      if (in_EAX == 0x11793157) {
        return 0xe4db4839;
      }
      if (in_EAX == 0x14d83e4e) {
        return 0x547d3170;
      }
    }
    else if (in_EAX == 0x95ad096b) {
      return 0x5522ff4d;
    }
  }
  else {
    if (in_EAX == 0xd7ba6011) {
      return 0x17f9deae;
    }
    if (in_EAX == 0xde511657) {
      return 0x531c0cb9;
    }
    if (in_EAX == 0xf20e404a) {
      return 0x76421903;
    }
  }
  return 0;
}


// ==== 0x4b3240 FUN_004b3240

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b3240(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  bool bVar7;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  bVar7 = true;
  if ((*(char *)(param_1 + 0x48) == '\x01') &&
     ((iVar5 = FEPackageList__FindByName(&DAT_00746104), iVar5 == 0 || (*(int *)(iVar5 + 0x18) == 0)
      ))) {
    uStack_8 = 0;
    uStack_4 = 0;
    uStack_24 = 0xa79504bc;
    uStack_20 = 0xc6ca43b1;
    uStack_1c = 0xfedcba02;
    uStack_18 = 0x6a9b74bd;
    uStack_14 = 0xfedcba03;
    uStack_10 = 0xfedcba06;
    uStack_c = 0xb8a7c6cd;
    FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
    *(undefined1 *)(param_1 + 0x48) = 0;
  }
  if (param_2 < 0x911ab365) {
    if (param_2 == 0x911ab364) {
      uStack_8 = 0;
      uStack_4 = 0;
      uStack_24 = 0xea9cda09;
      uStack_20 = 0x639;
      uStack_1c = 0x12345678;
      uStack_18 = 0x541389e5;
      uStack_14 = 0;
      uStack_10 = 0;
      uStack_c = 0xb8a7c6cd;
      FUN_004dc6e0(&uStack_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
      return;
    }
    if (param_2 == 0xc407210) {
      if (DAT_00748f75 == '\0') {
        uVar1 = *(uint *)(param_3 + 0x10);
        if (uVar1 < 0xa936c3a3) {
          if (uVar1 == 0xa936c3a2) {
            DAT_00777b4c = 0x20;
            FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
            return;
          }
          if (uVar1 == 0x14d83e4e) {
            DAT_00777b4c = 0x40;
            FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
            return;
          }
          if (uVar1 == 0x70fbb1e4) {
            if (DAT_007346c4 != 0) {
              DAT_00777b4c = 8;
              DAT_00735e78 = 1;
              FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
              return;
            }
          }
          else if (uVar1 == 0x95ad096b) {
            DAT_00777b4c = 0x10;
            FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
            return;
          }
        }
        else {
          if (uVar1 == 0xd7ba6011) {
            DAT_00777b4c = 1;
            cVar3 = Career__IsFinalEventWon();
            cVar4 = Career__IsEventWon();
            if ((cVar4 != '\0') && (cVar3 == '\0')) {
              FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
              return;
            }
            if (DAT_00735e7c != 0) {
              Career__Reset();
              Career__StartEvent();
              Career__WinEvent(0);
              FUN_005a2540();
              FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
              return;
            }
            if (cVar3 != '\0') {
              FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
              return;
            }
            FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
            return;
          }
          if (uVar1 == 0xde511657) {
            DAT_00777b4c = 2;
            FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
            return;
          }
          if (uVar1 == 0xf20e404a) {
            DAT_00777b4c = 0x80;
            FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
            return;
          }
        }
      }
    }
    else {
      if (param_2 == 0x12345678) {
        iVar5 = FEngFindPackage();
        if (iVar5 != 0) {
          *(undefined4 *)(iVar5 + 0x1c) = 0xff;
        }
        FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 == 0x35f8620b) {
        FUN_004f6c30(&DAT_006c619c,1);
        FUN_004f6c30(&DAT_006c619c,1);
        FUN_004f6c30(&DAT_006c619c,1);
        FUN_004f6c30(&DAT_006c619c,1);
        FUN_004f6c30(&DAT_006c619c,1);
        FUN_004f6c30(&DAT_006c619c,1);
        FEngGetCurrentButton(*(undefined4 *)(param_1 + 0xc));
        FEObject__SetScript("Highlight",1);
        return;
      }
    }
  }
  else if (param_2 == 0xabc08912) {
    uVar6 = Screen_MU_Main_PC__ObjectHashToTextHash(param_1);
    iVar5 = *(int *)(param_1 + 0x40);
    if (iVar5 != 0) {
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 0x400000;
      puVar2 = DAT_00735710;
      bVar7 = DAT_00735710 != (undefined4 *)0x0;
      *(undefined4 *)(iVar5 + 0x5c) = uVar6;
      if (bVar7) {
        (**(code **)*puVar2)(iVar5);
      }
      *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffd | 0x400000;
    }
    FEObject__SetScript("FadeIn",1);
  }
  else if (param_2 == 0xc98356ba) {
    cVar3 = cFEng__IsAnyJoyInputActive();
    if (((cVar3 != '\0') || (cVar3 = FEngIsPackagePushed(), cVar3 != '\0')) ||
       (cVar3 = FEngIsPackagePushed(), cVar3 != '\0')) {
      bVar7 = false;
    }
    if (DAT_007357a8 != '\0') {
      bVar7 = false;
    }
    if ((DAT_00748f75 == '\0') && (bVar7)) {
      if (_DAT_006fb028 < (float)(DAT_0073ad3c - *(int *)(param_1 + 0x44)) * 0.00025) {
        DAT_00735e04 = 1;
        FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
      }
    }
    else {
      *(int *)(param_1 + 0x44) = DAT_0073ad3c;
    }
    if (DAT_00735e80 != 0) {
      DAT_00735e80 = 0;
      FUN_004ee3a0(0,0);
      return;
    }
  }
  return;
}


// ==== 0x4b3780 Screen_MU_Main_PC::NotifySoundMessage

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

int Screen_MU_Main_PC__NotifySoundMessage(void)

{
  int in_stack_00000014;
  
  if (((in_stack_00000014 != 6) && (in_stack_00000014 != 1)) && (in_stack_00000014 != 2)) {
    return in_stack_00000014;
  }
  return 0;
}


// ==== 0x4b37a0 FUN_004b37a0

void __fastcall FUN_004b37a0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c615c;
  FUN_004f7b50();
  return;
}


// ==== 0x4b37b0 FUN_004b37b0

void * __thiscall FUN_004b37b0(void *param_1,byte param_2)

{
  FUN_004b37a0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4b37d0 FUN_004b37d0

int __thiscall FUN_004b37d0(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_0073578c;
  if (param_2 == 0xc407210) {
    if (*(int *)(param_3 + 0x10) == -0x28d0ffd6) {
      FUN_004dfd70();
      Career__Reset();
      Career__StartEvent();
      iVar1 = DAT_0073578c;
      if (((DAT_0073578c != 0) && (iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 != 0)) &&
         (*(int *)(iVar3 + 0x18) != 0)) {
        FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar3 + 0x18));
      }
      if ((param_4 & 1) != 0) {
        DAT_00748f78 = 0;
        return 0;
      }
      if ((param_4 & 2) != 0) {
        DAT_00748f78 = 1;
        return 1;
      }
      if ((param_4 & 4) == 0) {
        DAT_00748f78 = (-(uint)((param_4 & 8) != 0) & 4) - 1;
        return DAT_00748f78;
      }
      DAT_00748f78 = 2;
      return 2;
    }
  }
  else if (param_2 != -0x6ee54c9c) {
    return param_2;
  }
  iVar3 = *(int *)(param_1 + 0xc);
  if (DAT_0073578c != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    iVar3 = 0;
    if (iVar2 != 0) {
      iVar3 = 0;
      if (*(int *)(iVar2 + 0x18) != 0) {
        iVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
      }
    }
  }
  return iVar3;
}


// ==== 0x4b3800 FUN_004b3800

void FUN_004b3800(void)

{
  int in_EAX;
  int unaff_ESI;
  
  if ((in_EAX != 0) && (*(int *)(in_EAX + 0x18) != 0)) {
    FUN_004f0800(*(undefined4 *)(unaff_ESI + 8),*(int *)(in_EAX + 0x18));
  }
  return;
}


// ==== 0x4b38d0 Screen_MU_UG_Explained::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 * Screen_MU_UG_Explained__Create(undefined4 param_1)

{
  undefined4 *puVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687cf3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = _malloc(0x44);
  local_4 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    FEScreen__FEScreen(puVar1,param_1);
    *puVar1 = &PTR_FUN_006c615c;
    puVar1[0x10] = 0;
    ExceptionList = local_c;
    return puVar1;
  }
  ExceptionList = local_c;
  return (undefined4 *)0x0;
}


// ==== 0x4b3940 FUN_004b3940

void __thiscall
FUN_004b3940(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0x23) {
    if (param_1 * 0xc90 + DAT_00734588 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = bStringHash();
    }
  }
  CarPartDatabase__GetCarPart(uVar1,param_4,param_5,param_3,param_6);
  return;
}


// ==== 0x4b3990 RaceSubObject586c::RaceSubObject586c

/* [canon] canon med (ghidra-canon+hopper) docs/re/canon.md */

void __fastcall RaceSubObject586c__RaceSubObject586c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c5fb8;
  return;
}


// ==== 0x4b39a0 FUN_004b39a0

void __fastcall FUN_004b39a0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c5fb8;
  return;
}


// ==== 0x4b39b0 FUN_004b39b0

undefined4 * __thiscall FUN_004b39b0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006c5fb8;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4b39d0 FUN_004b39d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b39d0(void)

{
  _DAT_00735ec8 = 0;
  return;
}


// ==== 0x4b39e0 FUN_004b39e0

undefined4 FUN_004b39e0(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0:
  case 1:
  case 3:
  case 5:
  case 6:
    return 1;
  case 2:
    return 3;
  case 4:
    return 5;
  default:
    return 0;
  }
}


// ==== 0x4b3a20 Race::PickOpponentNames

/* [canon] rivals V (capstone+Ghidra) docs/re/rivals.md */

void Race__PickOpponentNames(int param_1)

{
  undefined4 *_Memory;
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  _Memory = _malloc(0xc0);
  puVar6 = _Memory;
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  iVar2 = 0;
  do {
    *(undefined **)(param_1 + iVar2 * 4) = PTR_DAT_006faf08;
    iVar5 = 0;
    do {
      uVar4 = DAT_006f227c % 0x30;
      uVar1 = DAT_006f227c ^ 0x1d872b41;
      uVar3 = uVar1 >> 5 ^ uVar1;
      DAT_006f227c = uVar3 << 0x1b ^ uVar3 ^ uVar1;
      if (_Memory[uVar4] == 0) {
        *(undefined **)(param_1 + iVar2 * 4) = (&PTR_DAT_006faf08)[uVar4];
        _Memory[uVar4] = 1;
        break;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 100);
    iVar2 = iVar2 + 1;
    if (3 < iVar2) {
      _free(_Memory);
      return;
    }
  } while( true );
}


// ==== 0x4b3ac0 Race::SpawnTraffic

/* [canon] rivals I (Ghidra+Hopper) docs/re/rivals.md */

void Race__SpawnTraffic(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int local_e8c;
  int local_e88;
  int local_e84;
  undefined1 local_e80 [3708];
  
  iVar8 = DAT_0078a300;
  if (DAT_0078a347 == '\0') {
    if (DAT_0078a300 == 0) {
      local_e8c = 0;
    }
    else {
      iVar2 = TrackRow_FindById();
      local_e8c = (int)*(char *)(DAT_0078a2fc + iVar2 + 0xc0 + iVar8 * 2);
    }
    local_e88 = 0;
    if (0 < local_e8c) {
      do {
        iVar8 = DAT_0078a41c;
        local_e84 = 0;
        while ((iVar2 = TrafficCar_PickType(), iVar2 != -1 &&
               (iVar5 = 0, pcVar3 = DAT_0078a418, 0 < iVar8))) {
          while ((*pcVar3 != '\0' || (*(int *)(pcVar3 + 0x10) != iVar2))) {
            iVar5 = iVar5 + 1;
            pcVar3 = pcVar3 + 0x750;
            if (iVar8 <= iVar5) goto LAB_004b3b74;
          }
          local_e84 = local_e84 + 1;
          if (99 < local_e84) break;
        }
LAB_004b3b74:
        RideInfo__Init();
        iVar8 = iVar2 * 0xc90 + DAT_00734588;
        if (*(int *)(iVar2 * 0xc90 + 0xc54 + DAT_00734588) == 1) {
          iVar8 = (DAT_006ee6f0 != 0) + 1;
        }
        else {
          cVar1 = *(char *)(iVar8 + 0xd9);
          if (cVar1 == '\0') {
            iVar8 = 0;
          }
          else {
            uVar7 = DAT_006f227c % (uint)(int)cVar1;
            uVar6 = DAT_006f227c ^ 0x1d872b41;
            uVar4 = uVar6 >> 5 ^ uVar6;
            DAT_006f227c = uVar4 << 0x1b ^ uVar4 ^ uVar6;
            iVar8 = (int)*(char *)(uVar7 + 0xc80 + iVar8);
          }
        }
        Ride_Init(iVar8,0,0);
        FUN_0057d340(local_e80);
        FUN_0057e9a0(local_e80);
        DriverInfo__DriverInfo(local_e88 + 0x32,3,local_e80,&DAT_006b9172,0xffffffff,0,0);
        RaceStatus__AddEntrant(&DAT_0078a2f0);
        local_e88 = local_e88 + 1;
      } while (local_e88 < local_e8c);
    }
  }
  return;
}


// ==== 0x4b3c60 Race::BuildRandomOpponentRide

/* [canon] rivals V (Ghidra+Hopper+capstone) docs/re/rivals.md */

void Race__BuildRandomOpponentRide(int param_1,undefined4 param_2,char param_3,int *param_4)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 *puVar3;
  float fVar4;
  int in_EAX;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  int *piVar14;
  undefined *puVar15;
  float local_98;
  byte local_90;
  byte local_8f [63];
  int local_50 [20];
  
  if (param_4 == (int *)0x0) {
    param_4 = (int *)(DAT_0078a418 + 0x10);
  }
  if ((DAT_006f1db8 == -1) &&
     ((((iVar5 = DAT_006f1dbc, in_EAX != 100 && (iVar5 = DAT_006f1dc0, in_EAX != 0x65)) &&
       (iVar5 = DAT_006f1dc4, in_EAX != 0x66)) || (iVar5 == -1)))) {
    if ((DAT_0073494c == 0) || (DAT_00734950 == 0)) {
      piVar14 = local_50;
      for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
        *piVar14 = 0;
        piVar14 = piVar14 + 1;
      }
      puVar15 = &DAT_006fafc8;
      do {
        uVar13 = DAT_006f227c % 0x14;
        uVar7 = DAT_006f227c ^ 0x1d872b41;
        uVar9 = uVar7 >> 5 ^ uVar7;
        DAT_006f227c = uVar7 ^ uVar9 << 0x1b ^ uVar9;
        iVar5 = local_50[uVar13];
        while (iVar5 != 0) {
          uVar10 = DAT_006f227c % 100;
          uVar9 = DAT_006f227c ^ 0x1d872b41;
          uVar7 = uVar9 >> 5 ^ uVar9;
          DAT_006f227c = uVar7 << 0x1b ^ uVar7 ^ uVar9;
          uVar13 = uVar13 + ((-(uint)(0x32 < uVar10) & 2) - 1);
          if ((int)uVar13 < 0x14) {
            if ((int)uVar13 < 0) {
              uVar13 = 0x13;
            }
          }
          else {
            uVar13 = 0;
          }
          iVar5 = local_50[uVar13];
        }
        local_50[uVar13] = (int)puVar15;
        puVar15 = puVar15 + 4;
      } while ((int)puVar15 < 0x6fb018);
      local_98 = 7.5;
      do {
        iVar5 = 0;
        local_98 = local_98 + local_98;
        do {
          if ((param_3 != '\0') || (*(int *)local_50[iVar5] != *param_4)) {
            Ride_Init(1,0,0);
            if (*(char *)(param_1 + 0x424) == -1) {
              RideInfo__RebuildPhysicsInfo(1);
            }
            fVar4 = *(float *)(param_1 + 0x428);
            if ((char)param_4[0x109] == -1) {
              RideInfo__RebuildPhysicsInfo(1);
            }
            if (fVar4 <= (float)param_4[0x10a] + local_98) goto LAB_004b3cac;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < 0x14);
      } while( true );
    }
    RandomInt(4);
  }
LAB_004b3cac:
  uVar13 = 0;
  Ride_Init(1,0,0);
  FUN_0057d340(param_1);
  FUN_00565da0("DUMMY_SKIN%d",param_2);
  iVar5 = -1;
  pbVar11 = &local_90;
  bVar2 = local_90;
  while (bVar2 != 0) {
    iVar5 = iVar5 * 0x21 + (uint)bVar2;
    pbVar1 = pbVar11 + 1;
    pbVar11 = pbVar11 + 1;
    bVar2 = *pbVar1;
  }
  *(int *)(param_1 + 0x444) = iVar5;
  FUN_00565da0("DUMMY_WHEEL%d",param_2);
  iVar5 = -1;
  pbVar11 = &local_90;
  while (local_90 != 0) {
    iVar5 = iVar5 * 0x21 + (uint)local_90;
    pbVar1 = pbVar11 + 1;
    pbVar11 = pbVar11 + 1;
    local_90 = *pbVar1;
  }
  *(int *)(param_1 + 0x448) = iVar5;
  uVar9 = param_4[0x131];
  local_98 = 0.0;
  for (iVar5 = CarPartDatabase__GetCarPart(0,0x1e,0,0,0xffffffff); iVar5 != 0;
      iVar5 = CarPartDatabase__GetCarPart(0,0x1e,0,iVar5,0xffffffff)) {
    uVar13 = uVar13 + 1;
  }
  if (uVar13 != 0) {
    puVar6 = (undefined4 *)NullUpdate_ret();
    uVar7 = DAT_006f227c;
    do {
      uVar12 = uVar7 % uVar13;
      uVar7 = uVar7 ^ 0x1d872b41;
      uVar10 = uVar7 >> 5 ^ uVar7;
      uVar7 = uVar10 << 0x1b ^ uVar10 ^ uVar7;
      for (puVar3 = DAT_0073ad40; puVar3 != puVar6; puVar3 = (undefined4 *)*puVar3) {
        uVar10 = puVar3[3];
        uVar8 = puVar3[4] * 0x30 + uVar10;
        for (; uVar10 < uVar8; uVar10 = uVar10 + 0x30) {
          if (*(char *)(uVar10 + 0x10) == '\x1e') goto LAB_004b3dfc;
        }
      }
      uVar10 = 0;
LAB_004b3dfc:
      DAT_006f227c = uVar7;
      if (0 < (int)uVar12) {
        do {
          uVar10 = CarPartDatabase__GetCarPart(0,0x1e,0,uVar10,0xffffffff);
          uVar12 = uVar12 - 1;
        } while (uVar12 != 0);
      }
      if (uVar10 != uVar9) {
        local_98 = (float)uVar10;
      }
    } while (local_98 == 0.0);
    *(float *)(param_1 + 0x4c4) = local_98;
    *(char *)(param_1 + 0x64a) = *(char *)(param_1 + 0x64a) + '\x01';
    RideInfo__UpdatePartsEnabled(param_1);
  }
  return;
}


// ==== 0x4b4010 FUN_004b4010

void __thiscall FUN_004b4010(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_EAX;
  
  if ((in_EAX != 0) && (*(int *)(in_EAX + 0xc) != 0)) {
    PresetRide__ApplyToRide(param_1);
    return;
  }
  Race__BuildRandomOpponentRide(param_1,param_3,1,0);
  return;
}


// ==== 0x4b4040 Race::SpawnOpponents

/* [canon] canon high (ghidra) docs/re/canon.md */

void Race__SpawnOpponents(int param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined4 extraout_ECX;
  uint uVar8;
  undefined3 uVar9;
  uint uVar10;
  int iVar11;
  byte *pbVar12;
  int iVar13;
  undefined4 uVar14;
  int *piVar15;
  int local_ee4;
  int *local_ee0;
  int local_ed8;
  int local_ed0 [4];
  byte local_ec0;
  byte local_ebf [63];
  int local_e80 [273];
  int local_a3c;
  int local_a38;
  
  if (DAT_0078a347 == '\0') {
    Race__PickOpponentNames(local_ed0);
    iVar5 = DAT_0078a418;
    piVar7 = (int *)(DAT_0078a418 + 0x10);
    bVar4 = false;
    if (0 < param_1) {
      local_ee0 = local_ed0;
      local_ee4 = 0;
      iVar11 = 2;
      do {
        RideInfo__Init();
        FUN_00565da0("DUMMY_SKIN%d",iVar11);
        local_a3c = -1;
        pbVar12 = &local_ec0;
        bVar2 = local_ec0;
        while (bVar2 != 0) {
          local_a3c = local_a3c * 0x21 + (uint)bVar2;
          pbVar1 = pbVar12 + 1;
          pbVar12 = pbVar12 + 1;
          bVar2 = *pbVar1;
        }
        FUN_00565da0("DUMMY_WHEEL%d",iVar11);
        uVar8 = CONCAT31((int3)((uint)extraout_ECX >> 8),local_ec0);
        local_a38 = -1;
        pbVar12 = &local_ec0;
        bVar2 = local_ec0;
        while (uVar9 = (undefined3)(uVar8 >> 8), bVar2 != 0) {
          uVar10 = uVar8 & 0xff;
          bVar2 = pbVar12[1];
          uVar8 = CONCAT31(uVar9,bVar2);
          local_a38 = local_a38 * 0x21 + uVar10;
          pbVar12 = pbVar12 + 1;
        }
        if ((param_2 == 0) || (DAT_0078a33c == '\0')) {
          uVar14 = CONCAT31(uVar9,!bVar4);
          piVar15 = piVar7;
LAB_004b4183:
          Race__BuildRandomOpponentRide(local_e80,iVar11,uVar14,piVar15);
        }
        else {
          if ((((iVar11 + -2 < 0) || (*(int *)(param_2 + 0x59c8) <= iVar11 + -2)) ||
              (iVar13 = local_ee4 + 0x5974 + param_2, iVar13 == 0)) || (*(int *)(iVar13 + 0xc) == 0)
             ) {
            uVar14 = 1;
            piVar15 = (int *)0x0;
            goto LAB_004b4183;
          }
          PresetRide__ApplyToRide(local_e80);
        }
        if ((bVar4) || (bVar4 = false, local_e80[0] == *piVar7)) {
          bVar4 = true;
        }
        if ((DAT_0078a33c == '\0') || (param_2 == 0)) {
          local_ed8 = Race__RollOpponentSkill();
          iVar13 = *local_ee0;
          cVar3 = '\x01';
        }
        else {
          if ((iVar11 + -2 < 0) || (*(int *)(param_2 + 0x59c8) <= iVar11 + -2)) {
            iVar13 = 0;
          }
          else {
            iVar13 = local_ee4 + 0x5974 + param_2;
          }
          local_ed8 = (int)*(short *)(iVar13 + 0x10 + DAT_0078a3fc * 2);
          if ((local_ed8 < 0) || (9 < local_ed8)) {
            local_ed8 = -1;
          }
          cVar3 = *(char *)(iVar13 + 0x18);
          if ((cVar3 < '\0') || ('\x02' < cVar3)) {
            cVar3 = '\x01';
          }
          if (*(short *)(iVar13 + 0x16) == -1) {
            if (*(char *)(iVar5 + 0x434) == -1) {
              RideInfo__RebuildPhysicsInfo(1);
            }
            RideInfo__MatchPerformance_RideInfo__other______
                      (local_e80,piVar7,*(undefined4 *)(iVar5 + 0x28),(int)*(char *)(iVar5 + 0x434),
                       1,0x40a00000);
          }
          else {
            RideInfo__MatchPerformance_float_target______
                      ((float)(int)*(short *)(iVar13 + 0x16),*(undefined4 *)(iVar5 + 0x28),1,
                       0x40a00000);
          }
        }
        if ((param_2 != 0) && (iVar6 = *(int *)(param_2 + 0x589c), iVar6 < 4)) {
          *(int *)(param_2 + 0x589c) = iVar6 + 1;
          if ((iVar6 < 0) || (iVar6 + 1 <= iVar6)) {
            iVar6 = 0;
          }
          else {
            iVar6 = param_2 + 0x586c + iVar6 * 0xc;
          }
          *(int *)(iVar6 + 4) = iVar11 + 0x62;
          *(undefined4 *)(iVar6 + 8) = 1;
        }
        DriverInfo__DriverInfo(iVar11 + 0x62,2,local_e80,iVar13,local_ed8,(int)cVar3,iVar11 + -1);
        RaceStatus__AddEntrant(&DAT_0078a2f0);
        local_ee4 = local_ee4 + 0x1c;
        local_ee0 = local_ee0 + 1;
        iVar13 = iVar11 + -1;
        iVar11 = iVar11 + 1;
      } while (iVar13 < param_1);
    }
    if (DAT_0078a33c == '\0') {
      Race__MatchOpponentRatings();
    }
  }
  return;
}


// ==== 0x4b4380 Race::MatchOpponentRatings

/* [canon] rivals I (Ghidra+Hopper+capstone) docs/re/rivals.md */

void Race__MatchOpponentRatings(void)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_8;
  int local_4;
  
  iVar5 = 0;
  iVar6 = 0;
  local_8 = 0;
  iVar4 = DAT_0078a418;
  if (0 < DAT_0078a41c) {
    do {
      iVar3 = iVar6;
      if ((*(int *)(iVar5 + 4 + iVar4) == 1) &&
         (iVar1 = iVar5 + 0x10 + iVar4, iVar3 = iVar1, iVar6 != 0)) {
        iVar7 = iVar6;
        if (DAT_0078a320 < 2) break;
        if (*(char *)(iVar6 + 0x424) == -1) {
          RideInfo__RebuildPhysicsInfo(1);
          iVar4 = DAT_0078a418;
        }
        fVar2 = *(float *)(iVar6 + 0x428);
        if (*(char *)(iVar1 + 0x424) == -1) {
          RideInfo__RebuildPhysicsInfo(1);
          iVar4 = DAT_0078a418;
        }
        iVar7 = iVar1;
        iVar3 = iVar6;
        if (fVar2 < *(float *)(iVar1 + 0x428)) break;
      }
      iVar7 = iVar3;
      local_8 = local_8 + 1;
      iVar5 = iVar5 + 0x750;
      iVar6 = iVar7;
    } while (local_8 < DAT_0078a41c);
    if (iVar7 != 0) {
      iVar6 = 1;
      local_8 = 0;
      if (0 < DAT_0078a41c) {
        local_4 = 0;
        do {
          if (*(int *)(local_4 + 4 + iVar4) == 2) {
            iVar4 = local_4 + 0x10 + iVar4;
            if (DAT_006f1dc8 <= -1.0) {
              if ((DAT_006f1dcc <= -1.0) || (iVar6 != 1)) {
                if ((DAT_006f1dd0 <= -1.0) || (iVar6 != 2)) {
                  if ((DAT_006f1dd4 <= -1.0) || (iVar6 != 3)) {
                    if (*(char *)(iVar7 + 0x424) == -1) {
                      RideInfo__RebuildPhysicsInfo(1);
                    }
                    RideInfo__MatchPerformance_RideInfo__other______
                              (iVar4,iVar7,*(undefined4 *)(iVar7 + 0x18),
                               (int)*(char *)(iVar7 + 0x424),1,0x40a00000);
                  }
                  else {
                    RideInfo__MatchPerformance_float_target______
                              (DAT_006f1dd4,0xffffffff,0,0x40a00000);
                  }
                }
                else {
                  RideInfo__MatchPerformance_float_target______
                            (DAT_006f1dd0,0xffffffff,0,0x40a00000);
                }
              }
              else {
                RideInfo__MatchPerformance_float_target______(DAT_006f1dcc,0xffffffff,0,0x40a00000);
              }
            }
            else {
              RideInfo__MatchPerformance_float_target______(DAT_006f1dc8,0xffffffff,0,0x40a00000);
            }
            RideInfo__SyncPartsToPhysicsForAI(iVar4);
            iVar6 = iVar6 + 1;
            iVar4 = DAT_0078a418;
          }
          local_8 = local_8 + 1;
          local_4 = local_4 + 0x750;
        } while (local_8 < DAT_0078a41c);
      }
    }
  }
  return;
}


// ==== 0x4b4590 Race::RollOpponentSkill

/* WARNING: Removing unreachable block (ram,0x004b45cb) */
/* [canon] rivals V (capstone+Ghidra) docs/re/rivals.md */

int Race__RollOpponentSkill(void)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  float *pfVar6;
  int unaff_ESI;
  
  uVar5 = DAT_006f227c % 0x7fffffff;
  uVar3 = DAT_006f227c ^ 0x1d872b41;
  uVar2 = uVar3 >> 5 ^ uVar3;
  DAT_006f227c = uVar2 << 0x1b ^ uVar2 ^ uVar3;
  fVar1 = (float)uVar5 * 4.656613e-10;
  iVar4 = 0;
  pfVar6 = (float *)(&DAT_0077a400 + unaff_ESI * 0x28);
  do {
    if (fVar1 < *pfVar6 != (fVar1 == *pfVar6)) {
      if (iVar4 != -1) {
        return iVar4;
      }
      return 0;
    }
    iVar4 = iVar4 + 1;
    pfVar6 = pfVar6 + 1;
  } while (iVar4 < 10);
  return 0;
}


// ==== 0x4b4610 Race::ShuffleGrid

/* [canon] rivals V (Ghidra+Hopper) docs/re/rivals.md */

void Race__ShuffleGrid(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  
  if (DAT_0078a320 == 1) {
    if (DAT_0078a324 != 0) {
      uVar7 = DAT_006f227c % (DAT_0078a324 + 1U);
      uVar6 = DAT_006f227c ^ 0x1d872b41;
      uVar5 = uVar6 >> 5 ^ uVar6;
      DAT_006f227c = uVar5 << 0x1b ^ uVar5 ^ uVar6;
      uVar1 = *(undefined1 *)(DAT_0078a418 + 3);
      iVar8 = uVar7 * 0x750;
      iVar9 = iVar8 + DAT_0078a418;
      *(undefined1 *)(DAT_0078a418 + 3) = *(undefined1 *)(iVar8 + 3 + DAT_0078a418);
      *(undefined1 *)(iVar9 + 3) = uVar1;
      return;
    }
  }
  else if (DAT_0078a320 == 2) {
    uVar5 = DAT_006f227c ^ 0x1d872b41;
    uVar6 = uVar5 >> 5 ^ uVar5;
    uVar5 = uVar6 << 0x1b ^ uVar6 ^ uVar5;
    bVar14 = (DAT_006f227c & 1) == 0;
    uVar7 = uVar5 % (DAT_0078a324 + 1U);
    uVar5 = uVar5 ^ 0x1d872b41;
    uVar6 = uVar5 >> 5 ^ uVar5;
    DAT_006f227c = uVar6 << 0x1b ^ uVar6 ^ uVar5;
    cVar4 = '\0';
    cVar3 = '\x01';
    if (uVar7 == 0) {
      cVar4 = '\x01';
      cVar3 = '\x02';
    }
    else if (uVar7 == 1) {
      cVar4 = '\x03';
      cVar3 = '\x01';
    }
    else if (uVar7 == 2) {
      cVar4 = '\x02';
      cVar3 = '\x04';
    }
    iVar11 = (uint)!bVar14 * 0x750 + DAT_0078a418;
    iVar8 = DAT_0078a324 + 2;
    iVar13 = (uint)bVar14 * 0x750 + DAT_0078a418;
    iVar12 = 0;
    iVar10 = 0;
    iVar9 = DAT_0078a418;
    if (0 < iVar8) {
      do {
        if (*(char *)(iVar9 + 3) == cVar4) {
          iVar12 = iVar9;
        }
        if (*(char *)(iVar9 + 3) == cVar3) {
          iVar10 = iVar9;
        }
        iVar9 = iVar9 + 0x750;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      if ((iVar12 != 0) && (iVar10 != 0)) {
        uVar1 = *(undefined1 *)(iVar11 + 3);
        uVar2 = *(undefined1 *)(iVar13 + 3);
        *(undefined1 *)(iVar11 + 3) = *(undefined1 *)(iVar12 + 3);
        *(undefined1 *)(iVar13 + 3) = *(undefined1 *)(iVar10 + 3);
        *(undefined1 *)(iVar12 + 3) = uVar1;
        *(undefined1 *)(iVar10 + 3) = uVar2;
      }
    }
  }
  return;
}


// ==== 0x4b47a0 ApplyOptionsToPlayerSettings

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera V (G+C) docs/re/camera.md */

void ApplyOptionsToPlayerSettings(void)

{
  int in_EAX;
  uint uVar1;
  
  if (in_EAX == 0) {
    DAT_0078a387 = (undefined1)DAT_00758954;
    DAT_0078a386 = (undefined1)DAT_00758964;
    DAT_0078a3f5 = (undefined1)DAT_007588f0;
    DAT_0078a3f6 = (undefined1)DAT_007588ec;
    DAT_0078a3f4 = DAT_007588d4;
    DAT_0078a385 = DAT_00758970;
    DAT_0078a3fa = DAT_00758951;
    DAT_0078a38a = DAT_007588e4;
    if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
      if (DAT_00758948 == 3) {
        DAT_00758948 = 0;
      }
      DAT_0078a388 = (&DAT_00758938)[DAT_00758948 * 4];
    }
    else {
      DAT_0078a388 = DAT_00758944;
    }
    DAT_0078a390 = DAT_00758938;
    DAT_0078a392 = DAT_00758940;
    DAT_0078a391 = DAT_0075893c;
    DAT_0078a393 = DAT_00758944;
    if (DAT_007588d6 == '\x01') {
      uVar1 = DAT_0078a394 | 0x40;
    }
    else {
      uVar1 = DAT_0078a394 & 0xffffffbf;
    }
    if (DAT_007588da == '\x01') {
      uVar1 = uVar1 | 0x100;
    }
    else {
      uVar1 = uVar1 & 0xfffffeff;
    }
    if (DAT_007588d8 == '\x01') {
      uVar1 = uVar1 | 0x10;
    }
    else {
      uVar1 = uVar1 & 0xffffffef;
    }
    if (DAT_007588dc == 1) {
      uVar1 = uVar1 | 0x400;
    }
    else {
      uVar1 = uVar1 & 0xfffffbff;
    }
    _DAT_0078a3b4 = (uint)DAT_007588dc;
    if (DAT_007588d5 == '\x01') {
      DAT_0078a394 = uVar1 | 0x200;
      return;
    }
    DAT_0078a394 = uVar1 & 0xfffffdff;
    return;
  }
  if (in_EAX == 1) {
    DAT_0078a3bf = DAT_00758958;
    DAT_0078a3be = (undefined1)DAT_00758964;
    DAT_0078a3bd = DAT_00758978;
    DAT_0078a3c2 = DAT_007588e8;
    if (DAT_00777cc8 == 6) {
      DAT_0078a3c0 = DAT_00758944;
    }
    else {
      if (DAT_0075894c == 3) {
        DAT_0075894c = 0;
      }
      DAT_0078a3c0 = (&DAT_00758938)[DAT_0075894c * 4];
    }
    DAT_0078a3c8 = DAT_00758938;
    DAT_0078a3c9 = DAT_0075893c;
    DAT_0078a3ca = DAT_00758940;
    DAT_0078a3cb = DAT_00758944;
    if (DAT_007588d7 == '\x01') {
      uVar1 = DAT_0078a3cc | 0x40;
    }
    else {
      uVar1 = DAT_0078a3cc & 0xffffffbf;
    }
    if (DAT_007588db == '\x01') {
      uVar1 = uVar1 | 0x100;
    }
    else {
      uVar1 = uVar1 & 0xfffffeff;
    }
    if (DAT_007588d9 == '\x01') {
      uVar1 = uVar1 | 0x10;
    }
    else {
      uVar1 = uVar1 & 0xffffffef;
    }
    if (DAT_007588dd == 1) {
      DAT_0078a3cc = uVar1 | 0x400;
      _DAT_0078a3ec = 1;
      return;
    }
    _DAT_0078a3ec = (uint)DAT_007588dd;
    DAT_0078a3cc = uVar1 & 0xfffffbff;
  }
  return;
}


// ==== 0x4b49e0 RaceSetup_Circuit

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] traffic med (H) docs/re/traffic.md */

void RaceSetup_Circuit(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  undefined1 *local_e84;
  undefined1 local_e80 [3672];
  float local_28;
  
  piVar1 = (int *)RaceOptions_Get();
  DAT_0078a320 = DAT_00748f70;
  if (DAT_00748f70 == 1) {
    DAT_0078a324 = *piVar1 + -1;
  }
  else {
    DAT_0078a324 = 0;
  }
  DAT_0078a350 = 0;
  DAT_0078a300 = piVar1[6];
  DAT_0078a335 = 3;
  _TrafficSameSideProb = 0x3f000000;
  DAT_0078a334 = 4;
  DAT_0078a400 = (uint)*(byte *)((int)piVar1 + 0x1f);
  DAT_0078a3fc = piVar1[5];
  _DAT_0078a330 = 0;
  DAT_0078a336 = DAT_0075896c;
  DAT_0078a337 = 0;
  DAT_0078a31c = piVar1[4];
  DAT_0078a2f0 = piVar1[2];
  DAT_0078a2fc = piVar1[3];
  iVar2 = 0;
  iVar3 = DAT_00736168;
  if (0 < DAT_0073616c) {
    do {
      if (*(short *)(iVar3 + 0x6c) == DAT_0078a2f0) goto LAB_004b4ac5;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xfc;
    } while (iVar2 < DAT_0073616c);
  }
  iVar3 = 0;
LAB_004b4ac5:
  DAT_0078a318 = (int)*(char *)(iVar3 + 0x69);
  DAT_0078a30c = 1;
  DAT_0078a33c = 0;
  _DAT_0078a380 = 0x3f800000;
  DAT_0078a40c = 2;
  DAT_0078a41c = 0;
  ApplyOptionsToPlayerSettings();
  if (DAT_00777b4c == 4) {
    ApplyOptionsToPlayerSettings();
  }
  iVar3 = 0;
  if (0 < DAT_0078a320) {
    do {
      (&DAT_0078a348)[iVar3] = (&DAT_00748f78)[iVar3];
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_0078a320);
  }
  iVar3 = 0;
  if (0 < DAT_0078a320) {
    local_e84 = &DAT_007588c4;
    do {
      RideInfo__Init();
      cFrontendDatabase__BuildRideForCarHandle(local_e80);
      DriverInfo__DriverInfo
                (iVar3,1,local_e80,local_e84,0xfffffffe,0,(int)(char)(&DAT_0078a334)[iVar3]);
      fVar4 = (float10)CalculateRideReputationPoints();
      local_28 = (float)fVar4;
      RaceStatus__AddEntrant(&DAT_0078a2f0);
      iVar3 = iVar3 + 1;
      local_e84 = local_e84 + 0xf944;
    } while (iVar3 < DAT_0078a320);
  }
  Race__SpawnOpponents(DAT_0078a324,0);
  Race__SpawnTraffic();
  Race__ShuffleGrid();
  return;
}


// ==== 0x4b4c30 FUN_004b4c30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b4c30(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  undefined1 *local_e84;
  undefined1 local_e80 [3672];
  float local_28;
  
  piVar1 = (int *)RaceOptions_Get();
  DAT_0078a320 = DAT_00748f70;
  if (DAT_00748f70 == 1) {
    DAT_0078a324 = *piVar1 + -1;
  }
  else {
    DAT_0078a324 = 0;
  }
  iVar2 = 0;
  DAT_0078a350 = 0;
  DAT_0078a300 = piVar1[6];
  DAT_0078a334 = 4;
  DAT_0078a335 = 3;
  _TrafficSameSideProb = 0x3f000000;
  DAT_0078a400 = (uint)*(byte *)((int)piVar1 + 0x1f);
  DAT_0078a3fc = piVar1[5];
  _DAT_0078a330 = 0;
  DAT_0078a336 = DAT_0075896c;
  DAT_0078a337 = 0;
  DAT_0078a31c = 1;
  DAT_0078a2f0 = piVar1[2];
  iVar3 = DAT_00736168;
  if (0 < DAT_0073616c) {
    do {
      if (*(short *)(iVar3 + 0x6c) == DAT_0078a2f0) goto LAB_004b4d05;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xfc;
    } while (iVar2 < DAT_0073616c);
  }
  iVar3 = 0;
LAB_004b4d05:
  DAT_0078a318 = (int)*(char *)(iVar3 + 0x69);
  DAT_0078a2fc = piVar1[3];
  iVar3 = 0;
  DAT_0078a30c = 1;
  DAT_0078a33c = 0;
  _DAT_0078a380 = 0x3f800000;
  DAT_0078a40c = 2;
  DAT_0078a41c = 0;
  ApplyOptionsToPlayerSettings();
  if (DAT_00777b4c == 4) {
    ApplyOptionsToPlayerSettings();
  }
  iVar2 = 0;
  if (0 < DAT_0078a320) {
    do {
      (&DAT_0078a348)[iVar2] = (&DAT_00748f78)[iVar2];
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_0078a320);
  }
  if (0 < DAT_0078a320) {
    local_e84 = &DAT_007588c4;
    do {
      RideInfo__Init();
      cFrontendDatabase__BuildRideForCarHandle(local_e80);
      DriverInfo__DriverInfo
                (iVar3,1,local_e80,local_e84,0xfffffffe,0,(int)(char)(&DAT_0078a334)[iVar3]);
      fVar4 = (float10)CalculateRideReputationPoints();
      local_28 = (float)fVar4;
      RaceStatus__AddEntrant(&DAT_0078a2f0);
      iVar3 = iVar3 + 1;
      local_e84 = local_e84 + 0xf944;
    } while (iVar3 < DAT_0078a320);
  }
  Race__SpawnOpponents(DAT_0078a324,0);
  Race__SpawnTraffic();
  Race__ShuffleGrid();
  return;
}


// ==== 0x4b4e60 FUN_004b4e60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b4e60(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  undefined1 *local_e84;
  undefined1 local_e80 [3672];
  float local_28;
  
  piVar1 = (int *)RaceOptions_Get();
  DAT_0078a320 = DAT_00748f70;
  if (DAT_00748f70 == 1) {
    DAT_0078a324 = *piVar1 + -1;
  }
  else {
    DAT_0078a324 = 0;
  }
  iVar2 = 0;
  DAT_0078a350 = 0;
  DAT_0078a300 = piVar1[6];
  DAT_0078a334 = 4;
  DAT_0078a335 = 3;
  _TrafficSameSideProb = 0x3f000000;
  DAT_0078a400 = (uint)*(byte *)((int)piVar1 + 0x1f);
  DAT_0078a3fc = piVar1[5];
  _DAT_0078a330 = 0;
  DAT_0078a336 = DAT_0075896c;
  DAT_0078a337 = 0;
  DAT_0078a31c = 3;
  DAT_0078a2f0 = piVar1[2];
  iVar3 = DAT_00736168;
  if (0 < DAT_0073616c) {
    do {
      if (*(short *)(iVar3 + 0x6c) == DAT_0078a2f0) goto LAB_004b4f35;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xfc;
    } while (iVar2 < DAT_0073616c);
  }
  iVar3 = 0;
LAB_004b4f35:
  DAT_0078a318 = (int)*(char *)(iVar3 + 0x69);
  DAT_0078a2fc = piVar1[3];
  iVar3 = 0;
  DAT_0078a30c = 3;
  DAT_0078a33c = 0;
  _DAT_0078a380 = 0x3f800000;
  DAT_0078a40c = 2;
  DAT_0078a41c = 0;
  ApplyOptionsToPlayerSettings();
  if (DAT_00777b4c == 4) {
    ApplyOptionsToPlayerSettings();
  }
  iVar2 = 0;
  if (0 < DAT_0078a320) {
    do {
      (&DAT_0078a348)[iVar2] = (&DAT_00748f78)[iVar2];
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_0078a320);
  }
  if (0 < DAT_0078a320) {
    local_e84 = &DAT_007588c4;
    do {
      RideInfo__Init();
      cFrontendDatabase__BuildRideForCarHandle(local_e80);
      DriverInfo__DriverInfo
                (iVar3,1,local_e80,local_e84,0xfffffffe,0,(int)(char)(&DAT_0078a334)[iVar3]);
      fVar4 = (float10)CalculateRideReputationPoints();
      local_28 = (float)fVar4;
      RaceStatus__AddEntrant(&DAT_0078a2f0);
      iVar3 = iVar3 + 1;
      local_e84 = local_e84 + 0xf944;
    } while (iVar3 < DAT_0078a320);
  }
  Race__SpawnOpponents(DAT_0078a324,0);
  Race__SpawnTraffic();
  return;
}


// ==== 0x4b5090 RaceStarter::SetupFreeRun

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (ghidra-canon+nfsug) docs/re/canon.md */

void RaceStarter__SetupFreeRun(void)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  float10 fVar7;
  undefined1 local_e80 [1092];
  int local_a3c;
  int local_a38;
  float local_28;
  
  iVar2 = RaceOptions_Get();
  DAT_0078a320 = 1;
  DAT_0078a350 = 0;
  DAT_0078a324 = 0;
  DAT_0078a300 = *(undefined4 *)(iVar2 + 0x18);
  DAT_0078a334 = '\x02';
  DAT_0078a335 = 1;
  _TrafficSameSideProb = 0x3f000000;
  DAT_0078a400 = (uint)*(byte *)(iVar2 + 0x1f);
  DAT_0078a3fc = *(undefined4 *)(iVar2 + 0x14);
  _DAT_0078a330 = 0;
  DAT_0078a336 = DAT_0075896c;
  DAT_0078a337 = *(undefined1 *)(iVar2 + 0x20);
  DAT_0078a31c = 0;
  DAT_0078a368 = 0;
  DAT_0078a2f0 = *(int *)(iVar2 + 8);
  if (0 < DAT_0073616c) {
    iVar4 = 0;
    iVar5 = DAT_00736168;
    do {
      if (*(short *)(iVar5 + 0x6c) == DAT_0078a2f0) goto LAB_004b515b;
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0xfc;
    } while (iVar4 < DAT_0073616c);
  }
  iVar5 = 0;
LAB_004b515b:
  DAT_0078a318 = (int)*(char *)(iVar5 + 0x69);
  DAT_0078a2fc = *(undefined4 *)(iVar2 + 0xc);
  DAT_0078a30c = 1;
  DAT_0078a33c = 0;
  _DAT_0078a380 = 0x3f800000;
  DAT_0078a40c = 2;
  DAT_0078a41c = 0;
  ApplyOptionsToPlayerSettings();
  if (DAT_00777b4c == 4) {
    ApplyOptionsToPlayerSettings();
  }
  iVar2 = 0;
  if (0 < DAT_0078a320) {
    do {
      (&DAT_0078a348)[iVar2] = (&DAT_00748f78)[iVar2];
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_0078a320);
  }
  RideInfo__Init();
  cFrontendDatabase__BuildRideForCarHandle(local_e80);
  pcVar6 = "DUMMY_SKIN1";
  local_a3c = -1;
  uVar3 = 0x44;
  do {
    local_a3c = local_a3c * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar6 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar6 = pcVar6 + 1;
  } while (*pbVar1 != 0);
  pcVar6 = "DUMMY_WHEEL1";
  local_a38 = -1;
  uVar3 = 0x44;
  do {
    local_a38 = local_a38 * 0x21 + uVar3;
    pbVar1 = (byte *)(pcVar6 + 1);
    uVar3 = (uint)*pbVar1;
    pcVar6 = pcVar6 + 1;
  } while (*pbVar1 != 0);
  DriverInfo__DriverInfo(0,1,local_e80,&DAT_007588c4,0xfffffffe,0,(int)DAT_0078a334);
  fVar7 = (float10)CalculateRideReputationPoints();
  local_28 = (float)fVar7;
  RaceStatus__AddEntrant(&DAT_0078a2f0);
  Race__SpawnTraffic();
  return;
}


// ==== 0x4b52a0 FUN_004b52a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b52a0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  undefined1 *local_e98;
  int local_e94;
  undefined1 local_e90 [3672];
  float local_38;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  pcStack_18 = FUN_006862ee;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  piVar1 = (int *)RaceOptions_Get();
  _DAT_00735ec8 = 1;
  local_14 = 0;
  if (DAT_00735ec4 == 0) {
    local_e94 = 0;
  }
  else {
    local_e94 = FUN_005a2930();
  }
  local_14 = 0xffffffff;
  DAT_00777ccc = local_e94;
  FUN_005a3380();
  DAT_0078a320 = DAT_00748f70;
  DAT_0078a350 = 0;
  DAT_0078a324 = *piVar1 - DAT_00748f70;
  DAT_0078a300 = piVar1[6];
  DAT_0078a334 = 4;
  DAT_0078a335 = 3;
  _TrafficSameSideProb = 0x3f000000;
  DAT_0078a3fc = piVar1[5];
  _DAT_0078a330 = 0;
  DAT_0078a336 = DAT_0075896c;
  DAT_0078a337 = 0;
  piVar1 = *(int **)(local_e94 + 0x5864);
  iVar2 = 0;
  iVar3 = DAT_00736168;
  if (0 < DAT_0073616c) {
    do {
      if ((int)*(short *)(iVar3 + 0x6c) == *piVar1) goto LAB_004b53c7;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xfc;
    } while (iVar2 < DAT_0073616c);
  }
  iVar3 = 0;
LAB_004b53c7:
  DAT_0078a2f0 = (int)*(short *)(iVar3 + 0x6c);
  DAT_0078a318 = (int)*(char *)(iVar3 + 0x69);
  DAT_0078a2fc = piVar1[1];
  DAT_0078a31c = piVar1[2];
  iVar3 = 0;
  DAT_0078a30c = 1;
  DAT_0078a33c = 0;
  DAT_0078a344 = 0;
  DAT_0078a345 = 0;
  DAT_0078a346 = 0;
  DAT_0078a400 = 1;
  _DAT_0078a404 = 0x3f800000;
  _DAT_0078a380 = 0x3f800000;
  DAT_0078a40c = 2;
  DAT_0078a41c = 0;
  ApplyOptionsToPlayerSettings();
  if (DAT_00777b4c == 4) {
    ApplyOptionsToPlayerSettings();
  }
  iVar2 = 0;
  if (0 < DAT_0078a320) {
    do {
      (&DAT_0078a348)[iVar2] = (&DAT_00748f78)[iVar2];
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_0078a320);
    if (0 < DAT_0078a320) {
      local_e98 = &DAT_007588c4;
      do {
        RideInfo__Init();
        cFrontendDatabase__BuildRideForCarHandle(local_e90);
        DriverInfo__DriverInfo
                  (iVar3,1,local_e90,local_e98,0xfffffffe,0,(int)(char)(&DAT_0078a334)[iVar3]);
        fVar4 = (float10)CalculateRideReputationPoints();
        local_38 = (float)fVar4;
        RaceStatus__AddEntrant(&DAT_0078a2f0);
        iVar2 = *(int *)(local_e94 + 0x589c);
        if (iVar2 < 4) {
          *(int *)(local_e94 + 0x589c) = iVar2 + 1;
          if ((iVar2 < 0) || (iVar2 + 1 <= iVar2)) {
            iVar2 = 0;
          }
          else {
            iVar2 = local_e94 + 0x586c + iVar2 * 0xc;
          }
          *(int *)(iVar2 + 4) = iVar3;
          *(undefined4 *)(iVar2 + 8) = 1;
        }
        iVar3 = iVar3 + 1;
        local_e98 = local_e98 + 0xf944;
      } while (iVar3 < DAT_0078a320);
    }
  }
  Race__SpawnOpponents(DAT_0078a324,local_e94);
  Race__SpawnTraffic();
  ExceptionList = local_1c;
  return;
}


// ==== 0x4b55b0 FUN_004b55b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b55b0(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  float10 fVar5;
  undefined1 *local_e84;
  undefined1 local_e80 [3672];
  float local_28;
  
  piVar1 = (int *)RaceOptions_Get();
  _DAT_007000cc = 0x3f000000;
  DAT_0078a344 = 1;
  DAT_0078a320 = DAT_00748f70;
  if (DAT_00748f70 == 1) {
    DAT_0078a324 = *piVar1 + -1;
  }
  else {
    DAT_0078a324 = 0;
  }
  DAT_0078a350 = 0;
  DAT_0078a300 = piVar1[6];
  DAT_0078a334 = 4;
  DAT_0078a335 = 3;
  _TrafficSameSideProb = 0x3f000000;
  DAT_0078a400 = (uint)*(byte *)((int)piVar1 + 0x1f);
  DAT_0078a3fc = piVar1[5];
  _DAT_0078a330 = 0;
  DAT_0078a336 = DAT_0075896c;
  DAT_0078a337 = 0;
  DAT_0078a340 = piVar1[8];
  DAT_0078a3fa = DAT_00758951;
  DAT_0078a3f5 = (undefined1)DAT_007588f0;
  DAT_0078a3f4 = DAT_007588d4;
  DAT_0078a3f6 = 6;
  DAT_0078a3f7 = 6;
  DAT_007361ac = DAT_00758968;
  DAT_0078a387 = 1;
  _DAT_0078a3b8 = (float)piVar1[9];
  DAT_0078a386 = (undefined1)DAT_00758964;
  DAT_0078a388 = (&DAT_00758938)[DAT_00758948 * 4];
  DAT_0078a38a = DAT_007588e4;
  DAT_0078a385 = DAT_00758970;
  if (DAT_007588d6 == '\0') {
    uVar3 = DAT_0078a394 & 0xffffffbf;
  }
  else {
    uVar3 = DAT_0078a394 | 0x40;
  }
  if (DAT_007588d8 == '\0') {
    uVar3 = uVar3 & 0xfffffeef;
  }
  else {
    uVar3 = uVar3 & 0xfffffeff | 0x10;
  }
  if (DAT_007588dc == '\0') {
    DAT_0078a394 = uVar3 ^ 0x400;
  }
  else {
    DAT_0078a394 = uVar3 | 0x400;
  }
  DAT_0078a392 = DAT_00758940;
  DAT_0078a390 = DAT_00758938;
  DAT_0078a391 = DAT_0075893c;
  DAT_0078a393 = DAT_00758944;
  if (DAT_00777b4c == 4) {
    DAT_0078a3be = (undefined1)DAT_00758964;
    DAT_0078a3c0 = (&DAT_00758938)[DAT_0075894c * 4];
    DAT_0078a3c8 = DAT_00758938;
    DAT_0078a3cb = DAT_00758944;
    DAT_0078a3bd = DAT_00758978;
    DAT_0078a3c9 = DAT_0075893c;
    DAT_0078a3bf = 1;
    DAT_0078a3c2 = DAT_007588e8;
    DAT_0078a3ca = DAT_00758940;
    if (DAT_007588d7 == '\0') {
      uVar3 = DAT_0078a3cc & 0xffffffbf;
    }
    else {
      uVar3 = DAT_0078a3cc | 0x40;
    }
    if (DAT_007588d9 == '\0') {
      uVar3 = uVar3 & 0xfffffeef;
    }
    else {
      uVar3 = uVar3 & 0xfffffeff | 0x10;
    }
    if (DAT_007588dd == '\0') {
      DAT_0078a3cc = uVar3 ^ 0x400;
    }
    else {
      DAT_0078a3cc = uVar3 | 0x400;
    }
  }
  DAT_0078a2f0 = piVar1[2];
  DAT_0078a2fc = piVar1[3];
  iVar2 = 0;
  iVar4 = DAT_00736168;
  if (0 < DAT_0073616c) {
    do {
      if (*(short *)(iVar4 + 0x6c) == DAT_0078a2f0) goto LAB_004b585b;
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 0xfc;
    } while (iVar2 < DAT_0073616c);
  }
  iVar4 = 0;
LAB_004b585b:
  DAT_0078a318 = (int)*(char *)(iVar4 + 0x69);
  iVar2 = 0;
  iVar4 = 0;
  DAT_0078a30c = 1;
  DAT_0078a33c = 0;
  DAT_0078a41c = 0;
  _DAT_0078a380 = 0x3f800000;
  if (0 < DAT_00748f70) {
    do {
      (&DAT_0078a348)[iVar4] = (&DAT_00748f78)[iVar4];
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_0078a320);
  }
  DAT_0078a40c = 2;
  if (0 < DAT_0078a320) {
    local_e84 = &DAT_007588c4;
    do {
      RideInfo__Init();
      cFrontendDatabase__BuildRideForCarHandle(local_e80);
      DriverInfo__DriverInfo
                (iVar2,1,local_e80,local_e84,0xfffffffe,0,(int)(char)(&DAT_0078a334)[iVar2]);
      fVar5 = (float10)CalculateRideReputationPoints();
      local_28 = (float)fVar5;
      RaceStatus__AddEntrant(&DAT_0078a2f0);
      if (DAT_0078a3fc == 0) {
        DAT_0078a40c = DAT_0078a3fc;
      }
      else if (DAT_0078a3fc == 1) {
        DAT_0078a40c = DAT_0078a3fc;
      }
      iVar2 = iVar2 + 1;
      local_e84 = local_e84 + 0xf944;
    } while (iVar2 < DAT_0078a320);
  }
  Race__SpawnOpponents(DAT_0078a324,0);
  Race__SpawnTraffic();
  Race__ShuffleGrid();
  return;
}


// ==== 0x4b59b0 FUN_004b59b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b59b0(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  undefined1 *local_e84;
  undefined1 local_e80 [3672];
  float local_28;
  
  piVar2 = (int *)RaceOptions_Get();
  DAT_0078a320 = DAT_00748f70;
  if (DAT_00748f70 == 1) {
    DAT_0078a324 = *piVar2 + -1;
  }
  else {
    DAT_0078a324 = 0;
  }
  DAT_0078a350 = 0;
  DAT_0078a300 = 0;
  DAT_0078a334 = 1;
  DAT_0078a335 = 2;
  _TrafficSameSideProb = 0x3f000000;
  DAT_0078a400 = (uint)*(byte *)((int)piVar2 + 0x1f);
  DAT_0078a3fc = piVar2[5];
  _DAT_0078a330 = 0;
  DAT_0078a336 = DAT_0075896c;
  DAT_0078a337 = 0;
  DAT_0078a31c = piVar2[4];
  DAT_0078a2f0 = piVar2[2];
  iVar3 = 0;
  iVar4 = DAT_00736168;
  if (0 < DAT_0073616c) {
    do {
      if (*(short *)(iVar4 + 0x6c) == DAT_0078a2f0) goto LAB_004b5a8b;
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0xfc;
    } while (iVar3 < DAT_0073616c);
  }
  iVar4 = 0;
LAB_004b5a8b:
  iVar3 = 0;
  DAT_0078a318 = (int)*(char *)(iVar4 + 0x69);
  DAT_0078a2fc = piVar2[3];
  DAT_0078a30c = 1;
  DAT_0078a33c = 0;
  DAT_0078a41c = 0;
  DAT_0078a345 = 1;
  _DAT_0078a380 = 0x3f800000;
  DAT_0078a40c = 2;
  ApplyOptionsToPlayerSettings();
  if (DAT_00777b4c == 4) {
    ApplyOptionsToPlayerSettings();
  }
  iVar4 = 0;
  if (0 < DAT_0078a320) {
    do {
      (&DAT_0078a348)[iVar4] = (&DAT_00748f78)[iVar4];
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_0078a320);
  }
  if (0 < DAT_0078a320) {
    local_e84 = &DAT_007588c4;
    do {
      RideInfo__Init();
      cFrontendDatabase__BuildRideForCarHandle(local_e80);
      DriverInfo__DriverInfo
                (iVar3,1,local_e80,local_e84,0xfffffffe,0,(int)(char)(&DAT_0078a334)[iVar3]);
      fVar5 = (float10)CalculateRideReputationPoints();
      local_28 = (float)fVar5;
      RaceStatus__AddEntrant(&DAT_0078a2f0);
      iVar3 = iVar3 + 1;
      local_e84 = local_e84 + 0xf944;
    } while (iVar3 < DAT_0078a320);
  }
  cVar1 = FUN_0043a2e0();
  if (cVar1 == '\0') {
    DriftManager__BuildLeaderBoard(0);
  }
  Race__ShuffleGrid();
  return;
}


// ==== 0x4b5c00 QuickRace::StartRaceByMode

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (hopper+capstone) docs/re/gameflow.md */

void QuickRace__StartRaceByMode(void)

{
  int iVar1;
  bool bVar2;
  undefined4 local_14 [5];
  
  DAT_00777ccc = 0;
  FUN_00431df0();
  DAT_0078a347 = 0;
  switch(DAT_00777cc8) {
  case 0:
    RaceSetup_Circuit();
    break;
  case 1:
    FUN_004b4c30();
    break;
  case 2:
    FUN_004b4e60();
    break;
  case 3:
    RaceStarter__SetupFreeRun();
    break;
  case 4:
    FUN_004b52a0();
    break;
  case 5:
    FUN_004b55b0();
    break;
  case 6:
    FUN_004b59b0();
  }
  FUN_004df790();
  iVar1 = DAT_00748f78;
  FUN_005748c0(5);
  bVar2 = DAT_0078a320 == 2;
  *(undefined4 *)(&DAT_0073b3e8 + iVar1 * 0x18c) = local_14[DAT_00758974];
  iVar1 = DAT_00748f7c;
  if (bVar2) {
    FUN_005748c0(5);
    *(undefined4 *)(&DAT_0073b3e8 + iVar1 * 0x18c) = local_14[DAT_0075897c];
  }
  _DAT_0077a90c = "UnloadingFrontEnd";
  DAT_0077a904 = GameFlow__UnloadingFrontEnd;
  if (DAT_0077a918 != '\0') {
    DAT_0077a918 = '\0';
  }
  return;
}


// ==== 0x4b5d20 FUN_004b5d20

void FUN_004b5d20(void)

{
  int iVar1;
  undefined4 local_14 [5];
  
  DAT_00777ccc = 0;
  FUN_00431df0();
  DAT_0078a347 = 1;
  switch(DAT_00777cc8) {
  case 0:
    RaceSetup_Circuit();
    break;
  case 1:
    FUN_004b4c30();
    break;
  case 2:
    FUN_004b4e60();
    break;
  case 3:
    RaceStarter__SetupFreeRun();
    break;
  case 4:
    FUN_004b52a0();
    break;
  case 5:
    FUN_004b55b0();
    break;
  case 6:
    FUN_004b59b0();
  }
  DAT_0078a324 = 0;
  DAT_0078a300 = 0;
  FUN_004df790();
  iVar1 = DAT_00748f78;
  FUN_005748c0(5);
  *(undefined4 *)(&DAT_0073b3e8 + iVar1 * 0x18c) = local_14[DAT_00758974];
  return;
}


// ==== 0x4b5df0 Career::StartRaceFromEvent

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (ghidra+capstone) docs/re/canon.md */

void Career__StartRaceFromEvent(void)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int unaff_EBX;
  char *pcVar6;
  undefined4 *puVar7;
  float10 fVar8;
  undefined **local_eb0 [5];
  undefined **local_e9c;
  undefined4 local_e98;
  undefined4 local_e94;
  undefined1 local_e90 [8];
  undefined4 local_e88 [271];
  int local_a4c;
  int local_a48;
  float local_38;
  void *local_1c;
  code *pcStack_18;
  int local_14;
  
  local_14 = 0xffffffff;
  pcStack_18 = FUN_006897e6;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  FUN_00431df0();
  DAT_0078a347 = 0;
  DAT_0078a320 = 1;
  FUN_005748c0(5);
  *(undefined ***)(&DAT_0073b3e8 + DAT_00748f78 * 0x18c) = local_eb0[DAT_00758974];
  switch(*(undefined4 *)(unaff_EBX + 0x59d4)) {
  default:
    DAT_0078a300 = 0;
    break;
  case 1:
    DAT_0078a300 = 1;
    break;
  case 2:
    DAT_0078a300 = 2;
    break;
  case 3:
    DAT_0078a300 = 3;
  }
  iVar3 = 0;
  DAT_0078a3fc = DAT_0075f240;
  DAT_0078a334 = '\x04';
  DAT_0078a335 = 3;
  _TrafficSameSideProb = 0x3f000000;
  _DAT_0078a330 = 0;
  piVar2 = *(int **)(unaff_EBX + 0x5864);
  iVar4 = DAT_00736168;
  if (0 < DAT_0073616c) {
    do {
      if ((int)*(short *)(iVar4 + 0x6c) == *piVar2) goto LAB_004b5efb;
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0xfc;
    } while (iVar3 < DAT_0073616c);
  }
  iVar4 = 0;
LAB_004b5efb:
  DAT_0078a2f0 = (int)*(short *)(iVar4 + 0x6c);
  DAT_0078a318 = (int)*(char *)(iVar4 + 0x69);
  DAT_0078a2fc = piVar2[1];
  DAT_0078a31c = piVar2[2];
  DAT_0078a30c = 1;
  DAT_0078a33c = 1;
  DAT_0078a344 = 0;
  DAT_0078a345 = '\0';
  DAT_0078a346 = 0;
  DAT_0078a400 = 1;
  _DAT_0078a404 = *(undefined4 *)(unaff_EBX + 0x59cc);
  iVar4 = 0;
  _DAT_0078a380 = *(undefined4 *)(unaff_EBX + 0x59dc + DAT_0075f240 * 4);
  DAT_0078a40c = *(undefined4 *)(unaff_EBX + 0x59e8);
  DAT_0078a324 = 3;
  do {
    (&DAT_0078a348)[iVar4] = (&DAT_00748f78)[iVar4];
    iVar4 = iVar4 + 1;
  } while (iVar4 < DAT_0078a320);
  switch(*(undefined4 *)(unaff_EBX + 0x58a8)) {
  case 1:
    DAT_0078a344 = 1;
    break;
  case 3:
    DAT_0078a345 = '\x01';
    break;
  case 4:
    DAT_0078a30c = 2;
    DAT_0078a310 = _ftol_nocw();
    break;
  case 5:
    DAT_0078a30c = 3;
  }
  DAT_0078a324 = *(undefined4 *)(unaff_EBX + 0x59c8);
  if (*(int *)(unaff_EBX + 0x58a8) == 3) {
    DAT_0078a324 = 0;
  }
  DAT_0078a350 = 0;
  DAT_0078a336 = DAT_0075896c;
  DAT_0078a337 = 0;
  ApplyOptionsToPlayerSettings();
  if (*(int *)(unaff_EBX + 0x58a8) == 1) {
    DAT_0078a387 = 1;
  }
  DAT_0078a41c = 0;
  RideInfo__Init();
  iVar4 = (int)DAT_0078a334;
  if (*(int *)(unaff_EBX + 0x5970) == 0) {
    FECarConfig__BuildRide(&DAT_0075eef8,0,local_e90);
  }
  else {
    pcVar6 = "DUMMY_SKIN1";
    local_a4c = -1;
    uVar5 = 0x44;
    do {
      local_a4c = local_a4c * 0x21 + uVar5;
      pbVar1 = (byte *)(pcVar6 + 1);
      uVar5 = (uint)*pbVar1;
      pcVar6 = pcVar6 + 1;
    } while (*pbVar1 != 0);
    pcVar6 = "DUMMY_WHEEL1";
    local_a48 = -1;
    uVar5 = 0x44;
    do {
      local_a48 = local_a48 * 0x21 + uVar5;
      pbVar1 = (byte *)(pcVar6 + 1);
      uVar5 = (uint)*pbVar1;
      pcVar6 = pcVar6 + 1;
    } while (*pbVar1 != 0);
    PresetRide__ApplyToRide(local_e90);
  }
  if (*(int *)(unaff_EBX + 0x58a0) == 0) {
    puVar7 = local_e88;
    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = 1;
      puVar7 = puVar7 + 1;
    }
  }
  DriverInfo__DriverInfo(0,1,local_e90,&DAT_007588c4,0xfffffffe,0,iVar4);
  fVar8 = (float10)CalculateRideReputationPoints();
  local_38 = (float)fVar8;
  RaceStatus__AddEntrant(&DAT_0078a2f0);
  local_e9c = &PTR_FUN_006c5fb8;
  iVar4 = *(int *)(unaff_EBX + 0x589c);
  local_14 = 0;
  local_e98 = 0;
  local_e94 = 1;
  if (iVar4 < 4) {
    *(int *)(unaff_EBX + 0x589c) = iVar4 + 1;
    if ((iVar4 < 0) || (iVar4 + 1 <= iVar4)) {
      iVar4 = 0;
    }
    else {
      iVar4 = unaff_EBX + 0x586c + iVar4 * 0xc;
    }
    *(undefined4 *)(iVar4 + 4) = 0;
    *(undefined4 *)(iVar4 + 8) = 1;
  }
  if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
    Race__SpawnOpponents(DAT_0078a324);
  }
  else {
    local_eb0[0] = &PTR_FUN_006c5fb8;
    iVar4 = *(int *)(unaff_EBX + 0x589c);
    local_14._0_1_ = 1;
    local_14._1_3_ = 0;
    if (iVar4 < 4) {
      *(int *)(unaff_EBX + 0x589c) = iVar4 + 1;
      if ((iVar4 < 0) || (iVar4 + 1 <= iVar4)) {
        iVar4 = 0;
      }
      else {
        iVar4 = unaff_EBX + 0x586c + iVar4 * 0xc;
      }
      *(undefined4 *)(iVar4 + 4) = 100;
      *(undefined4 *)(iVar4 + 8) = 1;
    }
    iVar4 = *(int *)(unaff_EBX + 0x589c);
    if (iVar4 < 4) {
      *(int *)(unaff_EBX + 0x589c) = iVar4 + 1;
      if ((iVar4 < 0) || (iVar4 + 1 <= iVar4)) {
        iVar4 = 0;
      }
      else {
        iVar4 = unaff_EBX + 0x586c + iVar4 * 0xc;
      }
      *(undefined4 *)(iVar4 + 4) = 0x65;
      *(undefined4 *)(iVar4 + 8) = 1;
    }
    iVar4 = *(int *)(unaff_EBX + 0x589c);
    local_eb0[1] = (undefined **)0x66;
    local_eb0[2] = (undefined **)0x1;
    if (iVar4 < 4) {
      *(int *)(unaff_EBX + 0x589c) = iVar4 + 1;
      if ((iVar4 < 0) || (iVar4 + 1 <= iVar4)) {
        iVar4 = 0;
      }
      else {
        iVar4 = unaff_EBX + 0x586c + iVar4 * 0xc;
      }
      *(undefined4 *)(iVar4 + 4) = 0x66;
      *(undefined4 *)(iVar4 + 8) = 1;
    }
    DriftManager__BuildLeaderBoard();
    local_14 = (uint)local_14._1_3_ << 8;
  }
  Race__SpawnTraffic();
  Race__SetPlayerGridSlot(*(undefined4 *)(unaff_EBX + 23000));
  DAT_00777ccc = unaff_EBX;
  _DAT_0077a90c = "UnloadingFrontEnd";
  DAT_0077a904 = GameFlow__UnloadingFrontEnd;
  if (DAT_0077a918 != '\0') {
    DAT_0077a918 = '\0';
  }
  ExceptionList = local_1c;
  return;
}


// ==== 0x4b6300 Race::SetPlayerGridSlot

/* [canon] canon med (ghidra) docs/re/canon.md */

void Race__SetPlayerGridSlot(int param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  iVar1 = in_EAX * 0x750 + DAT_0078a418;
  if ((iVar1 == 0) || (iVar4 = 0, DAT_0078a324 < 1)) {
    return;
  }
  do {
    iVar2 = 0;
    if (0 < DAT_0078a41c) {
      pcVar3 = (char *)(DAT_0078a418 + 1);
      do {
        if (iVar4 + 100 == (int)*pcVar3) {
          iVar2 = iVar2 * 0x750 + DAT_0078a418;
          goto LAB_004b6354;
        }
        iVar2 = iVar2 + 1;
        pcVar3 = pcVar3 + 0x750;
      } while (iVar2 < DAT_0078a41c);
    }
    iVar2 = 0;
LAB_004b6354:
    if (*(char *)(iVar2 + 3) == param_1) {
      *(undefined1 *)(iVar2 + 3) = *(undefined1 *)(iVar1 + 3);
      *(char *)(iVar1 + 3) = (char)param_1;
      return;
    }
    iVar4 = iVar4 + 1;
    if (DAT_0078a324 <= iVar4) {
      return;
    }
  } while( true );
}


// ==== 0x4b6390 QuickRace::LaunchFromSetupGlobals

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (ghidra+capstone+hopper) docs/re/gameflow.md */

void QuickRace__LaunchFromSetupGlobals(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int aiStack_e68 [456];
  undefined4 local_748;
  undefined1 local_730 [1836];
  
  uVar1 = DAT_00734660;
  iVar4 = DAT_006f1d64;
  iVar3 = DAT_006f1d58;
  DAT_0078a2f0 = DAT_0070095c;
  if (DAT_0070095c == -1) {
    if ((DAT_00736168 == 0) || (iVar2 = DAT_00736168, DAT_0073616c < 1)) {
      iVar2 = 0;
    }
    DAT_0078a2f0 = (int)*(short *)(iVar2 + 0x6c);
  }
  if (DAT_007346c4 != 0) {
    DAT_0078a347 = 1;
  }
  DAT_0078a2fc = DAT_00734664;
  DAT_0078a30c = DAT_006f1d7c;
  _TrafficSameSideProb = DAT_006f1d78;
  DAT_0078a320 = DAT_006f1d48;
  DAT_0078a31c = DAT_006f1d4c;
  _DAT_0078a360 = DAT_006f1d5c;
  _DAT_0078a354 = DAT_006f1d54;
  DAT_0078a300 = DAT_00734674;
  DAT_0078a336 = DAT_006f1da0 != 0;
  DAT_0078a387 = DAT_00734684;
  DAT_0078a318 = DAT_00734680;
  DAT_0078a386 = DAT_006f1d90;
  DAT_0078a350 = DAT_00734668;
  DAT_0078a344 = DAT_00734678 != 0;
  _DAT_0078a35c = DAT_006f1d60;
  DAT_0078a3bf = DAT_00734688;
  _DAT_0078a2f4 = 0;
  _DAT_0078a2f8 = 3;
  DAT_0078a33c = 0;
  DAT_0078a324 = DAT_00734660;
  _DAT_0078a358 = DAT_006f1d58;
  _DAT_0078a364 = DAT_006f1d64;
  DAT_0078a368 = DAT_0073466c;
  DAT_0078a3be = DAT_006f1d94;
  if (!(bool)DAT_0078a344) {
    DAT_0078a345 = DAT_0073467c != 0;
  }
  if (DAT_0073466c != 0) {
    DAT_0078a310 = 1200000;
  }
  if ((DAT_0078a346 != '\0') || (DAT_007361a0 != 0)) {
    DAT_0078a314 = _ftol_nocw();
  }
  _DAT_0078a378 = -(uint)(iVar4 != 0) & 3;
  DAT_0078a3fc = DAT_006f1d84;
  _DAT_0078a37c = DAT_006f1d84;
  _DAT_0078a374 = -(uint)(iVar3 != 0) & 3;
  DAT_0078a334 = (char)uVar1 + '\x01';
  DAT_0078a335 = (char)uVar1 + '\x02';
  DAT_0078a391 = DAT_006f1d68;
  DAT_0078a3c9 = DAT_006f1d68;
  DAT_0078a388 = DAT_00734670;
  DAT_0078a3c0 = DAT_00734670;
  DAT_0078a390 = DAT_00734670;
  DAT_0078a3c8 = DAT_00734670;
  iVar3 = 0;
  DAT_0078a392 = DAT_006f1d6c;
  DAT_0078a393 = DAT_006f1d70;
  DAT_0078a3ca = DAT_006f1d6c;
  DAT_0078a3cb = DAT_006f1d70;
  if (0 < DAT_006f1d48) {
    do {
      (&DAT_0078a348)[iVar3] = (&DAT_00748f78)[iVar3];
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_0078a320);
  }
  iVar3 = 0;
  _DAT_0078a404 = 0x3f800000;
  _DAT_0078a408 = 0x3f800000;
  if (0 < DAT_0078a320) {
    do {
      RideInfo__Init();
      cFrontendDatabase__BuildRideForCarHandle(local_730);
      DriverInfo__DriverInfo(iVar3,1,local_730,"SkipFE",0xfffffffe,0,(int)(&DAT_0078a334)[iVar3]);
      iVar4 = 0;
      do {
        if ((DAT_006f1e04 < 0) || (3 < DAT_006f1e04)) {
          *(undefined4 *)((int)aiStack_e68 + iVar4) = *(undefined4 *)((int)&DAT_00734698 + iVar4);
        }
        else {
          *(int *)((int)aiStack_e68 + iVar4) = DAT_006f1e04;
        }
        iVar4 = iVar4 + 4;
      } while (iVar4 < 0x2c);
      local_748 = 0x3f800000;
      RaceStatus__AddEntrant(&DAT_0078a2f0);
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_0078a320);
  }
  if (DAT_007346c4 == 0) {
    if ((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) {
      DriftManager__BuildLeaderBoard(0);
    }
    Race__SpawnOpponents(DAT_0078a324,0);
    Race__SpawnTraffic();
    if (DAT_006f1d98 != -1) {
      Race__SetPlayerGridSlot(DAT_006f1d98);
    }
    if (DAT_006f1d9c != -1) {
      Race__SetPlayerGridSlot(DAT_006f1d9c);
    }
    if (DAT_0077a920 != 3) {
      if (DAT_0077a918 != '\0') {
        DAT_0077a918 = '\0';
      }
      DAT_0077a904 = GameFlow__LoadingTrackCommon;
      _DAT_0077a90c = "LoadingTrackCommon";
      return;
    }
    if (DAT_0077a918 != '\0') {
      DAT_0077a918 = '\0';
    }
    DAT_0077a904 = GameFlow__UnloadingFrontEnd;
    _DAT_0077a90c = "UnloadingFrontEnd";
    return;
  }
  FUN_0043ab70();
  return;
}


// ==== 0x4b67c0 FUN_004b67c0

void __fastcall FUN_004b67c0(undefined4 *param_1)

{
  int *piVar1;
  int *_Memory;
  int iVar2;
  int *piVar3;
  
  piVar1 = param_1 + 0x10;
  *param_1 = &PTR_FUN_006c5ecc;
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


// ==== 0x4b6800 FUN_004b6800

void * __thiscall FUN_004b6800(void *param_1,byte param_2)

{
  FUN_004b67c0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4b6820 Screen_MU_QuickRaceModeSelect::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_QuickRaceModeSelect__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006892e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(100);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_QuickRaceModeSelect__Screen_MU_QuickRaceModeSelect(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4b6880 Screen_MU_QuickRaceModeSelect::Screen_MU_QuickRaceModeSelect

/* WARNING: Removing unreachable block (ram,0x004b6e51) */
/* [canon] canon low (capstone) docs/re/gameflow.md */

undefined4 *
Screen_MU_QuickRaceModeSelect__Screen_MU_QuickRaceModeSelect(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  byte *pbVar2;
  undefined1 uVar3;
  byte bVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  int extraout_EDX;
  int iVar10;
  int iVar11;
  bool bVar12;
  byte local_2c;
  byte local_2b [31];
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006892bb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FEScreen__FEScreen(param_1,param_2);
  puVar1 = param_1 + 0x10;
  iVar10 = 0;
  *param_1 = &PTR_FUN_006c5ecc;
  *puVar1 = puVar1;
  param_1[0x11] = puVar1;
  local_4 = 1;
  param_1[0x18] = 0;
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  iVar11 = DAT_0073578c;
  if ((((iVar5 != 0) && (*(int *)(iVar5 + 0x18) != 0)) && (DAT_0073578c != 0)) &&
     ((iVar5 = FEPackageList__FindByName(&DAT_00746104), iVar5 != 0 && (*(int *)(iVar5 + 0x18) != 0)
      ))) {
    cFEng__PopPackage(*(undefined4 *)(iVar11 + 8),*(int *)(iVar5 + 0x18));
  }
  iVar5 = FEPackageList__FindByName(&DAT_00746104);
  iVar11 = DAT_0073578c;
  if (((iVar5 != 0) && (*(int *)(iVar5 + 0x18) != 0)) &&
     ((DAT_0073578c != 0 &&
      ((iVar5 = FEPackageList__FindByName(&DAT_00746104), iVar5 != 0 &&
       (*(int *)(iVar5 + 0x18) != 0)))))) {
    cFEng__PopPackage(*(undefined4 *)(iVar11 + 8),*(int *)(iVar5 + 0x18));
  }
  if (DAT_00777b4c == 4) {
    do {
      bSPrintf_regdst(0x20,"split_screen_%d",iVar10);
      iVar11 = -1;
      pbVar8 = &local_2c;
      bVar4 = local_2c;
      while (bVar4 != 0) {
        if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
          bVar4 = bVar4 - 0x20;
        }
        pbVar2 = pbVar8 + 1;
        iVar11 = iVar11 * 0x21 + (uint)bVar4;
        pbVar8 = pbVar8 + 1;
        bVar4 = *pbVar2;
      }
      if (((((param_1[3] != 0) && (iVar5 = FEngFindPackage(), iVar5 != 0)) &&
           (iVar5 = FUN_004ffb70(), iVar5 != 0)) ||
          ((DAT_0073578c != 0 && (iVar5 = FUN_004ef050(iVar11), iVar5 != 0)))) &&
         (*(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) & 0xfffffffe | 0x400000,
         *(int *)(iVar5 + 0x18) == 5)) {
        uVar7 = *(undefined4 *)(iVar5 + 0x60);
        iVar11 = *(int *)(iVar5 + 0x5c);
        if (0 < iVar11) {
          do {
            FEObject__SetVisible(uVar7);
            uVar7 = *(undefined4 *)(extraout_EDX + 4);
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
        }
      }
      uVar3 = DAT_007588d1;
      iVar10 = iVar10 + 1;
    } while (iVar10 < 3);
    if ((DAT_00777cc8 == 3) || (DAT_00777cc8 == 2)) {
      DAT_00777cc8 = 0;
    }
    if (DAT_00748f76 == '\0') {
      FUN_00565b60(0xf660,0,0,0);
      Ugd__PackBlock(&DAT_007588c4,0xf660);
      Ugd__UnpackBlock(1);
      DAT_00748f8d = uVar3;
      FUN_00565ce0();
      DAT_00748f76 = '\x01';
    }
  }
  else {
    do {
      bSPrintf_regdst(0x20,"split_screen_%d",iVar10);
      iVar11 = -1;
      pbVar8 = &local_2c;
      bVar4 = local_2c;
      while (bVar4 != 0) {
        if (('`' < (char)bVar4) && ((char)bVar4 < '{')) {
          bVar4 = bVar4 - 0x20;
        }
        pbVar2 = pbVar8 + 1;
        iVar11 = iVar11 * 0x21 + (uint)bVar4;
        pbVar8 = pbVar8 + 1;
        bVar4 = *pbVar2;
      }
      if (((param_1[3] == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
         (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
        if (DAT_0073578c == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_004ef050(iVar11);
        }
      }
      FEObject__SetInvisible(iVar5);
      iVar10 = iVar10 + 1;
    } while (iVar10 < 3);
  }
  iVar11 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar11 == 0) || (*(int *)(iVar11 + 0x18) == 0)) && (DAT_0073578c != 0)) {
    iVar5 = *(int *)(DAT_0073578c + 8);
    iVar11 = iVar5 + 0xdc;
    if ((iVar11 == 0) || (iVar11 = FUN_004fd1e0(iVar11), iVar11 == 0)) {
      cFEng__PushPackage(iVar5,"GarageMain.fng",0x10,0);
    }
  }
  iVar11 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar11 != 0) && (*(int *)(iVar11 + 0x18) != 0)) && (*(int **)(iVar11 + 0x14) != (int *)0x0))
  {
    (**(code **)(**(int **)(iVar11 + 0x14) + 8))(0x18883f75,0,0,*(int *)(iVar11 + 0x18));
  }
  FUN_004b2480();
  iVar11 = DAT_0073578c;
  if (param_1[3] == 0) {
LAB_004b6c77:
    if (((iVar11 == 0) || (iVar11 = FUN_004ef050(0x446044e3), iVar11 == 0)) ||
       (*(int *)(iVar11 + 0x18) != 2)) goto LAB_004b6c9e;
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    iVar11 = DAT_0073578c;
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_004b6c35:
      local_4._0_1_ = 2;
      FUN_004ffb00(iVar5);
      local_4 = CONCAT31(local_4._1_3_,1);
      iVar11 = DAT_0073578c;
      goto LAB_004b6c77;
    }
    if (DAT_0073578c != 0) {
      iVar10 = *(int *)(DAT_0073578c + 8);
      if ((iVar10 == 0) ||
         (((iVar5 = FUN_004fd1e0(iVar10 + 0xdc), iVar5 == 0 &&
           (iVar5 = FUN_004fd1e0(iVar10 + 0xec), iVar5 == 0)) || (iVar5 == 0)))) goto LAB_004b6c77;
      goto LAB_004b6c35;
    }
LAB_004b6c9e:
    iVar11 = 0;
  }
  param_1[0x16] = iVar11;
  *(undefined1 *)(param_1 + 0x15) = 0;
  FUN_004b70c0(param_1);
  puVar1 = param_1 + 0x10;
  puVar6 = (undefined4 *)param_1[0x10];
  for (puVar9 = puVar6; (puVar9 != puVar1 && (puVar9[2] != DAT_00777cc8));
      puVar9 = (undefined4 *)*puVar9) {
  }
  for (; puVar6 != puVar1; puVar6 = (undefined4 *)*puVar6) {
    if (puVar6[2] == DAT_00777cc8) goto LAB_004b6ce4;
  }
  puVar6 = (undefined4 *)0x0;
LAB_004b6ce4:
  iVar11 = param_1[0x16];
  uVar7 = puVar6[5];
  if (iVar11 != 0) {
    *(uint *)(iVar11 + 0x1c) = *(uint *)(iVar11 + 0x1c) | 0x400000;
    puVar9 = DAT_00735710;
    bVar12 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar11 + 0x5c) = uVar7;
    if (bVar12) {
      (**(code **)*puVar9)(iVar11);
    }
    *(uint *)(iVar11 + 0x1c) = *(uint *)(iVar11 + 0x1c) & 0xfffffffd | 0x400000;
  }
  for (puVar9 = (undefined4 *)*puVar1; puVar9 != puVar1; puVar9 = (undefined4 *)*puVar9) {
    if (puVar9[2] == DAT_00777cc8) goto LAB_004b6d33;
  }
  puVar9 = (undefined4 *)0x0;
LAB_004b6d33:
  FUN_00495f00(puVar9[5]);
  if (DAT_0073578c != 0) {
    cFEng__SetCurrentButton(DAT_0073578c);
  }
  iVar11 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar11 != 0) && (*(int *)(iVar11 + 0x18) != 0)) && (*(int **)(iVar11 + 0x14) != (int *)0x0))
  {
    (**(code **)(**(int **)(iVar11 + 0x14) + 8))(0x2401cd38,0,0,*(int *)(iVar11 + 0x18));
  }
  *(undefined1 *)(param_1 + 8) = 1;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  iVar11 = DAT_0073578c;
  if (param_1[3] == 0) {
LAB_004b6e6d:
    if (iVar11 == 0) {
      iVar11 = 0;
      goto LAB_004b6e90;
    }
    uVar7 = FUN_004ef050(0x842a3642);
    iVar11 = DAT_0073578c;
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    iVar11 = DAT_0073578c;
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_004b6e15:
      local_4._0_1_ = 3;
      FUN_004ffb00(iVar5);
      local_4 = CONCAT31(local_4._1_3_,1);
      iVar11 = DAT_0073578c;
      goto LAB_004b6e6d;
    }
    if (DAT_0073578c != 0) {
      iVar10 = *(int *)(DAT_0073578c + 8);
      if (((iVar10 == 0) ||
          ((iVar5 = FUN_004fd1e0(iVar10 + 0xdc), iVar5 == 0 &&
           (iVar5 = FUN_004fd1e0(iVar10 + 0xec), iVar5 == 0)))) || (iVar5 == 0)) goto LAB_004b6e6d;
      goto LAB_004b6e15;
    }
LAB_004b6e90:
    uVar7 = 0;
  }
  param_1[0x12] = uVar7;
  if (param_1[3] == 0) {
LAB_004b6f47:
    if (iVar11 != 0) {
      uVar7 = FUN_004ef050(0x842a3643);
      goto LAB_004b6f66;
    }
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    iVar11 = DAT_0073578c;
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_004b6f05:
      local_4._0_1_ = 4;
      FUN_004ffb00(iVar5);
      local_4 = CONCAT31(local_4._1_3_,1);
      iVar11 = DAT_0073578c;
      goto LAB_004b6f47;
    }
    if (DAT_0073578c != 0) {
      iVar10 = *(int *)(DAT_0073578c + 8);
      if ((iVar10 == 0) ||
         (((iVar5 = FUN_004fd1e0(iVar10 + 0xdc), iVar5 == 0 &&
           (iVar5 = FUN_004fd1e0(iVar10 + 0xec), iVar5 == 0)) || (iVar5 == 0)))) goto LAB_004b6f47;
      goto LAB_004b6f05;
    }
  }
  uVar7 = 0;
LAB_004b6f66:
  param_1[0x13] = uVar7;
  iVar11 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar11 == 0) || (iVar11 = *(int *)(iVar11 + 0x18), iVar11 == 0)) {
    if ((DAT_0073578c == 0) || (iVar5 = *(int *)(DAT_0073578c + 8), iVar5 == 0)) {
      iVar11 = 0;
    }
    else {
      iVar11 = FUN_004fd1e0(iVar5 + 0xdc);
      if (iVar11 == 0) {
        iVar11 = FUN_004fd1e0(iVar5 + 0xec);
      }
    }
  }
  param_1[0x14] = iVar11;
  ExceptionList = pvStack_c;
  return param_1;
}


// ==== 0x4b6fe0 FUN_004b6fe0

void FUN_004b6fe0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int unaff_EBX;
  int unaff_ESI;
  bool bVar4;
  
  iVar2 = cFrontendDatabase__GetNumTracksAvailableForRaceType(&DAT_00748f70);
  if (iVar2 == 0) {
    param_2 = 1;
    FUN_004f75b0(0xff606060);
    if (DAT_0073578c != 0) {
      cFEng__SetButtonState(DAT_0073578c,0);
    }
  }
  if (unaff_ESI != 0) {
    *(uint *)(unaff_ESI + 0x1c) = *(uint *)(unaff_ESI + 0x1c) | 0x400000;
    puVar1 = DAT_00735710;
    bVar4 = DAT_00735710 != (undefined4 *)0x0;
    *(int *)(unaff_ESI + 0x5c) = param_5;
    if (bVar4) {
      (**(code **)*puVar1)();
    }
    *(uint *)(unaff_ESI + 0x1c) = *(uint *)(unaff_ESI + 0x1c) & 0xfffffffd | 0x400000;
  }
  piVar3 = _malloc(0x20);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3[3] = param_2;
    piVar3[2] = unaff_EBX;
    piVar3[4] = param_3;
    piVar3[5] = param_4;
    piVar3[6] = param_5;
    piVar3[7] = unaff_ESI;
  }
  puVar1 = *(undefined4 **)(param_1 + 0x44);
  *puVar1 = piVar3;
  *(int **)(param_1 + 0x44) = piVar3;
  piVar3[1] = (int)puVar1;
  *piVar3 = param_1 + 0x40;
  return;
}


// ==== 0x4b70a0 Screen_MU_QuickRaceModeSelect::FindRaceMode_ByObject

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

undefined4 * __fastcall
Screen_MU_QuickRaceModeSelect__FindRaceMode_ByObject(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x40);
  while( true ) {
    if (puVar1 == (undefined4 *)(param_1 + 0x40)) {
      return (undefined4 *)0x0;
    }
    if (puVar1[7] == param_2) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1;
}


// ==== 0x4b70c0 FUN_004b70c0

void FUN_004b70c0(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  char *pcVar8;
  int *piVar9;
  int extraout_EDX;
  uint uVar10;
  int extraout_EDX_00;
  int extraout_EDX_01;
  undefined *puVar11;
  int extraout_EDX_02;
  undefined4 uVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int local_28;
  byte local_20;
  byte local_1f [31];
  
  iVar3 = 0;
  local_28 = 0;
  do {
    iVar3 = iVar3 + 1;
    bSPrintf_regdst(0x20,"Mode_%d",iVar3);
    iVar13 = -1;
    pbVar7 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar13 = iVar13 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar7 + 1;
      pbVar7 = pbVar7 + 1;
      bVar2 = *pbVar1;
    }
    iVar6 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004b7198:
      iVar4 = 0;
      if (iVar6 == 0) {
LAB_004b71af:
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_004ef050(iVar13);
        iVar4 = DAT_0073578c;
      }
    }
    else {
      iVar4 = FEPackageList__FindByName(&DAT_00746104);
      iVar6 = DAT_0073578c;
      if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
        iVar4 = DAT_0073578c;
        if (DAT_0073578c != 0) {
          iVar5 = *(int *)(DAT_0073578c + 8);
          if ((iVar5 == 0) ||
             ((iVar4 = FUN_004fd1e0(iVar5 + 0xdc), iVar4 == 0 &&
              (iVar4 = FUN_004fd1e0(iVar5 + 0xec), iVar4 == 0)))) goto LAB_004b7198;
          goto LAB_004b7173;
        }
        goto LAB_004b71af;
      }
LAB_004b7173:
      if ((iVar4 == 0) ||
         (iVar5 = FUN_004ffb70(), iVar4 = DAT_0073578c, iVar6 = DAT_0073578c, iVar5 == 0))
      goto LAB_004b7198;
    }
    FEObject__SetInvisible(iVar5);
    iVar13 = -1;
    pbVar7 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar7 + 1;
      iVar13 = iVar13 * 0x21 + (uint)bVar2;
      pbVar7 = pbVar7 + 1;
      bVar2 = *pbVar1;
    }
    if (((iVar4 != 0) && (iVar6 = FEPackageList__FindByName(&DAT_00746104), iVar6 != 0)) &&
       (iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0)) {
      iVar4 = *(int *)(iVar6 + 0x88);
      iVar5 = 0;
      if (iVar4 != 0) {
        piVar9 = *(int **)(iVar6 + 0x84);
        do {
          if (*(int *)(*piVar9 + 0x10) == iVar13) {
            iVar5 = *piVar9;
          }
          piVar9 = piVar9 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        if (iVar5 != 0) {
          *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 0x4000000;
        }
      }
    }
    if (7 < iVar3) {
      if (DAT_0075899e != '\0') {
        local_28 = 1;
        bSPrintf_regdst(0x20,"Mode_%d",1);
        iVar3 = -1;
        pbVar7 = &local_20;
        bVar2 = local_20;
        while (bVar2 != 0) {
          if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
            bVar2 = bVar2 - 0x20;
          }
          iVar3 = iVar3 * 0x21 + (uint)bVar2;
          pbVar1 = pbVar7 + 1;
          pbVar7 = pbVar7 + 1;
          bVar2 = *pbVar1;
        }
        if (((((*(int *)(param_1 + 0xc) == 0) || (iVar13 = FEngFindPackage(), iVar13 == 0)) ||
             (iVar13 = FUN_004ffb70(), iVar13 == 0)) &&
            ((DAT_0073578c == 0 || (iVar13 = FUN_004ef050(iVar3), iVar13 == 0)))) ||
           (*(int *)(iVar13 + 0x18) != 2)) {
          iVar13 = 0;
        }
        if ((iVar13 != 0) &&
           (*(uint *)(iVar13 + 0x1c) = *(uint *)(iVar13 + 0x1c) & 0xfffffffe | 0x400000,
           *(int *)(iVar13 + 0x18) == 5)) {
          iVar3 = *(int *)(iVar13 + 0x5c);
          uVar12 = *(undefined4 *)(iVar13 + 0x60);
          if (0 < iVar3) {
            do {
              FEObject__SetVisible(uVar12);
              uVar12 = *(undefined4 *)(extraout_EDX + 4);
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
        }
        iVar3 = -1;
        pbVar7 = &local_20;
        if (local_20 != 0) {
          iVar3 = -1;
          bVar2 = local_20;
          do {
            if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
              bVar2 = bVar2 - 0x20;
            }
            uVar10 = (uint)bVar2;
            bVar2 = pbVar7[1];
            iVar3 = iVar3 * 0x21 + uVar10;
            pbVar7 = pbVar7 + 1;
          } while (bVar2 != 0);
        }
        if (((DAT_0073578c != 0) && (iVar13 = FEPackageList__FindByName(&DAT_00746104), iVar13 != 0)
            ) && (iVar13 = *(int *)(iVar13 + 0x18), iVar13 != 0)) {
          iVar6 = *(int *)(iVar13 + 0x88);
          iVar4 = 0;
          if (iVar6 != 0) {
            piVar9 = *(int **)(iVar13 + 0x84);
            do {
              if (*(int *)(*piVar9 + 0x10) == iVar3) {
                iVar4 = *piVar9;
              }
              piVar9 = piVar9 + 1;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            if (iVar4 != 0) {
              *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfbffffff;
            }
          }
        }
        uVar12 = 0xf167c5b0;
        if (DAT_00777b4c == 4) {
          uVar12 = 0x644a0367;
        }
        pcVar8 = "MODE_CIRCUIT";
        iVar3 = -1;
        uVar10 = 0x4d;
        do {
          iVar3 = iVar3 * 0x21 + uVar10;
          pbVar7 = (byte *)(pcVar8 + 1);
          uVar10 = (uint)*pbVar7;
          pcVar8 = pcVar8 + 1;
        } while (*pbVar7 != 0);
        pcVar8 = "QR_circuit";
        bVar2 = 0x51;
        iVar13 = -1;
        do {
          if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
            bVar2 = bVar2 - 0x20;
          }
          iVar13 = iVar13 * 0x21 + (uint)bVar2;
          bVar2 = pcVar8[1];
          pcVar8 = pcVar8 + 1;
        } while (bVar2 != 0);
        FUN_004b6fe0(param_1,0,iVar13,uVar12,0xd14b7fcd,iVar3);
      }
      if (DAT_007589be != '\0') {
        local_28 = local_28 + 1;
        bSPrintf_regdst(0x20,"Mode_%d",local_28);
        iVar3 = -1;
        pbVar7 = &local_20;
        bVar2 = local_20;
        while (bVar2 != 0) {
          if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
            bVar2 = bVar2 - 0x20;
          }
          pbVar1 = pbVar7 + 1;
          iVar3 = iVar3 * 0x21 + (uint)bVar2;
          pbVar7 = pbVar7 + 1;
          bVar2 = *pbVar1;
        }
        if (((((*(int *)(param_1 + 0xc) == 0) || (iVar13 = FEngFindPackage(), iVar13 == 0)) ||
             (iVar13 = FUN_004ffb70(), iVar13 == 0)) &&
            ((DAT_0073578c == 0 || (iVar13 = FUN_004ef050(iVar3), iVar13 == 0)))) ||
           (*(int *)(iVar13 + 0x18) != 2)) {
          iVar13 = 0;
        }
        FEObject__SetVisible(iVar13);
        pbVar7 = &local_20;
        bVar2 = local_20;
        while (bVar2 != 0) {
          pbVar1 = pbVar7 + 1;
          pbVar7 = pbVar7 + 1;
          bVar2 = *pbVar1;
        }
        if (extraout_EDX_00 != 0) {
          cFEng__SetButtonState(extraout_EDX_00,1);
        }
        pcVar8 = "MODE_SPRINT";
        iVar3 = -1;
        uVar10 = 0x4d;
        do {
          pbVar7 = (byte *)(pcVar8 + 1);
          iVar3 = iVar3 * 0x21 + uVar10;
          pcVar8 = pcVar8 + 1;
          uVar10 = (uint)*pbVar7;
        } while (*pbVar7 != 0);
        pcVar8 = "QR_sprint";
        bVar2 = 0x51;
        iVar13 = -1;
        do {
          if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
            bVar2 = bVar2 - 0x20;
          }
          iVar13 = iVar13 * 0x21 + (uint)bVar2;
          bVar2 = pcVar8[1];
          pcVar8 = pcVar8 + 1;
        } while (bVar2 != 0);
        FUN_004b6fe0(param_1,0,iVar13,0x4467d81d,0x817e429a,iVar3);
      }
      if (DAT_00758aa6 != '\0') {
        local_28 = local_28 + 1;
        bSPrintf_regdst(0x20,"Mode_%d",local_28);
        iVar3 = -1;
        pbVar7 = &local_20;
        bVar2 = local_20;
        while (bVar2 != 0) {
          if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
            bVar2 = bVar2 - 0x20;
          }
          pbVar1 = pbVar7 + 1;
          iVar3 = iVar3 * 0x21 + (uint)bVar2;
          pbVar7 = pbVar7 + 1;
          bVar2 = *pbVar1;
        }
        if (((((*(int *)(param_1 + 0xc) == 0) || (iVar13 = FEngFindPackage(), iVar13 == 0)) ||
             (iVar13 = FUN_004ffb70(), iVar13 == 0)) &&
            ((DAT_0073578c == 0 || (iVar13 = FUN_004ef050(iVar3), iVar13 == 0)))) ||
           (*(int *)(iVar13 + 0x18) != 2)) {
          iVar13 = 0;
        }
        if ((iVar13 != 0) &&
           (*(uint *)(iVar13 + 0x1c) = *(uint *)(iVar13 + 0x1c) & 0xfffffffe | 0x400000,
           *(int *)(iVar13 + 0x18) == 5)) {
          iVar3 = *(int *)(iVar13 + 0x5c);
          uVar12 = *(undefined4 *)(iVar13 + 0x60);
          if (0 < iVar3) {
            do {
              FEObject__SetVisible(uVar12);
              uVar12 = *(undefined4 *)(extraout_EDX_01 + 4);
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
        }
        iVar3 = -1;
        pbVar7 = &local_20;
        bVar2 = local_20;
        while (bVar2 != 0) {
          if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
            bVar2 = bVar2 - 0x20;
          }
          pbVar1 = pbVar7 + 1;
          iVar3 = iVar3 * 0x21 + (uint)bVar2;
          pbVar7 = pbVar7 + 1;
          bVar2 = *pbVar1;
        }
        if (((DAT_0073578c != 0) && (iVar13 = FEPackageList__FindByName(&DAT_00746104), iVar13 != 0)
            ) && (iVar13 = *(int *)(iVar13 + 0x18), iVar13 != 0)) {
          iVar6 = *(int *)(iVar13 + 0x88);
          iVar4 = 0;
          if (iVar6 != 0) {
            piVar9 = *(int **)(iVar13 + 0x84);
            do {
              if (*(int *)(*piVar9 + 0x10) == iVar3) {
                iVar4 = *piVar9;
              }
              piVar9 = piVar9 + 1;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            if (iVar4 != 0) {
              *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfbffffff;
            }
          }
        }
        pcVar8 = "MODE_RACE_DRAG";
        iVar3 = -1;
        uVar10 = 0x4d;
        do {
          iVar3 = iVar3 * 0x21 + uVar10;
          pbVar7 = (byte *)(pcVar8 + 1);
          uVar10 = (uint)*pbVar7;
          pcVar8 = pcVar8 + 1;
        } while (*pbVar7 != 0);
        puVar11 = &DAT_006c5f18;
        iVar13 = -1;
        bVar2 = 0x51;
        do {
          if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
            bVar2 = bVar2 - 0x20;
          }
          iVar13 = iVar13 * 0x21 + (uint)bVar2;
          bVar2 = puVar11[1];
          puVar11 = puVar11 + 1;
        } while (bVar2 != 0);
        FUN_004b6fe0(param_1,0,iVar13,0x330aef9b,0x8d9a96d8,iVar3);
      }
      if (DAT_00758ad2 != '\0') {
        local_28 = local_28 + 1;
        bSPrintf_regdst(0x20,"Mode_%d",local_28);
        iVar3 = -1;
        pbVar7 = &local_20;
        bVar2 = local_20;
        while (bVar2 != 0) {
          if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
            bVar2 = bVar2 - 0x20;
          }
          pbVar1 = pbVar7 + 1;
          iVar3 = iVar3 * 0x21 + (uint)bVar2;
          pbVar7 = pbVar7 + 1;
          bVar2 = *pbVar1;
        }
        if (((((*(int *)(param_1 + 0xc) == 0) || (iVar13 = FEngFindPackage(), iVar13 == 0)) ||
             (iVar13 = FUN_004ffb70(), iVar13 == 0)) &&
            ((DAT_0073578c == 0 || (iVar13 = FUN_004ef050(iVar3), iVar13 == 0)))) ||
           (*(int *)(iVar13 + 0x18) != 2)) {
          iVar13 = 0;
        }
        FEObject__SetVisible(iVar13);
        pbVar7 = &local_20;
        while (local_20 != 0) {
          pbVar1 = pbVar7 + 1;
          pbVar7 = pbVar7 + 1;
          local_20 = *pbVar1;
        }
        if (extraout_EDX_02 != 0) {
          cFEng__SetButtonState(extraout_EDX_02,1);
        }
        pcVar8 = "GENERICPLACEHOLDER";
        iVar3 = -1;
        uVar10 = 0x47;
        do {
          pbVar7 = (byte *)(pcVar8 + 1);
          iVar3 = iVar3 * 0x21 + uVar10;
          pcVar8 = pcVar8 + 1;
          uVar10 = (uint)*pbVar7;
        } while (*pbVar7 != 0);
        pcVar8 = "QR_drift";
        iVar13 = -1;
        bVar2 = 0x51;
        do {
          if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
            bVar2 = bVar2 - 0x20;
          }
          iVar13 = iVar13 * 0x21 + (uint)bVar2;
          bVar2 = pcVar8[1];
          pcVar8 = pcVar8 + 1;
        } while (bVar2 != 0);
        FUN_004b6fe0(param_1,0,iVar13,0x94690536,0x40ed9413,iVar3);
      }
      if ((DAT_007589de != '\0') && (DAT_00777b4c != 4)) {
        local_28 = local_28 + 1;
        bSPrintf_regdst(0x20,"Mode_%d",local_28);
        iVar3 = *(int *)(param_1 + 0xc);
        uVar12 = FEng__HashName();
        if ((((iVar3 == 0) ||
             ((iVar3 = FEngFindPackage(), iVar3 == 0 || (iVar3 = FUN_004ffb70(), iVar3 == 0)))) &&
            ((DAT_0073578c == 0 || (iVar3 = FUN_004ef050(uVar12), iVar3 == 0)))) ||
           (*(int *)(iVar3 + 0x18) != 2)) {
          iVar3 = 0;
        }
        iVar13 = DAT_0073578c;
        FEObject__SetVisible(iVar3);
        if (iVar13 != 0) {
          uVar12 = 1;
          FEng__HashName(1);
          cFEng__SetButtonState(iVar13,uVar12);
        }
        pcVar8 = "GENERICPLACEHOLDER";
        iVar3 = -1;
        uVar10 = 0x47;
        do {
          iVar3 = iVar3 * 0x21 + uVar10;
          pbVar7 = (byte *)(pcVar8 + 1);
          uVar10 = (uint)*pbVar7;
          pcVar8 = pcVar8 + 1;
        } while (*pbVar7 != 0);
        uVar15 = 0x7019fb10;
        uVar14 = 0x33039093;
        uVar12 = FEng__HashName(0x33039093,0x7019fb10,iVar3);
        FUN_004b6fe0(param_1,0,uVar12,uVar14,uVar15,iVar3);
      }
      if ((DAT_007589fe != '\0') && (DAT_00777b4c != 4)) {
        bSPrintf_regdst(0x20,"Mode_%d",local_28 + 1);
        iVar3 = *(int *)(param_1 + 0xc);
        uVar12 = FEng__HashName();
        if ((((iVar3 == 0) ||
             ((iVar3 = FEngFindPackage(), iVar3 == 0 || (iVar3 = FUN_004ffb70(), iVar3 == 0)))) &&
            ((DAT_0073578c == 0 || (iVar3 = FUN_004ef050(uVar12), iVar3 == 0)))) ||
           (*(int *)(iVar3 + 0x18) != 2)) {
          iVar3 = 0;
        }
        iVar13 = DAT_0073578c;
        FEObject__SetVisible(iVar3);
        if (iVar13 != 0) {
          uVar12 = 1;
          FEng__HashName(1);
          cFEng__SetButtonState(iVar13,uVar12);
        }
        pcVar8 = "GENERICPLACEHOLDER";
        iVar3 = -1;
        uVar10 = 0x47;
        do {
          iVar3 = iVar3 * 0x21 + uVar10;
          pbVar7 = (byte *)(pcVar8 + 1);
          uVar10 = (uint)*pbVar7;
          pcVar8 = pcVar8 + 1;
        } while (*pbVar7 != 0);
        uVar15 = 0xcc4e72b1;
        uVar14 = 0x79c8e073;
        uVar12 = FEng__HashName(0x79c8e073,0xcc4e72b1,iVar3);
        FUN_004b6fe0(param_1,0,uVar12,uVar14,uVar15,iVar3);
      }
      return;
    }
  } while( true );
}


// ==== 0x4b7a30 Screen_MU_QuickRaceModeSelect::DrawRaceMode

/* [canon] canon high (ghidra-canon+nfsug) docs/re/canon.md */

void __fastcall Screen_MU_QuickRaceModeSelect__DrawRaceMode(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  bool bVar4;
  
  for (puVar3 = *(undefined4 **)(param_2 + 0x40); puVar3 != (undefined4 *)(param_2 + 0x40);
      puVar3 = (undefined4 *)*puVar3) {
    if (puVar3[2] == DAT_00777cc8) goto LAB_004b7a4e;
  }
  puVar3 = (undefined4 *)0x0;
LAB_004b7a4e:
  iVar1 = *(int *)(param_2 + 0x58);
  uVar2 = puVar3[5];
  if (iVar1 != 0) {
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400000;
    puVar3 = DAT_00735710;
    bVar4 = DAT_00735710 != (undefined4 *)0x0;
    *(undefined4 *)(iVar1 + 0x5c) = uVar2;
    if (bVar4) {
      (**(code **)*puVar3)(iVar1);
    }
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xfffffffd | 0x400000;
  }
  return;
}


// ==== 0x4b7a90 FUN_004b7a90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_004b7a90(int param_1,uint param_2,int param_3)

{
  float fVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  if (param_2 < 0x911ab365) {
    if (param_2 == 0x911ab364) {
      if (DAT_00777b4c == 4) {
        FUN_00565b60(0xf660,0,0,0);
        Ugd__PackBlock(&DAT_00748f80,0xf660);
        uVar2 = DAT_00748f8d;
        Ugd__UnpackBlock(1);
        DAT_007588d1 = uVar2;
        FUN_00565ce0();
      }
      iVar3 = DAT_0073578c;
      param_2 = *(uint *)(param_1 + 0xc);
      if (DAT_0073578c != 0) {
        iVar5 = FEPackageList__FindByName(&DAT_00746104);
        param_2 = 0;
        if (iVar5 != 0) {
          param_2 = 0;
          if (*(int *)(iVar5 + 0x18) != 0) {
            uVar4 = FUN_004f0800(*(undefined4 *)(iVar3 + 8),*(int *)(iVar5 + 0x18));
            return uVar4;
          }
        }
      }
    }
    else if (param_2 == 0xc407210) {
      param_2 = Screen_MU_QuickRaceModeSelect__FindRaceMode_ByObject();
      DAT_00777cc8 = *(undefined4 *)(param_2 + 8);
      if (*(int *)(param_2 + 0xc) == 0) goto LAB_004b7b99;
    }
    else {
      if (param_2 == 0x35f8620b) {
        iVar3 = 0;
        do {
          iVar3 = iVar3 + 1;
          bSPrintf_regdst(0x20,"Mode_%d",iVar3);
          FEngSetScript(&DAT_006c619c,1);
        } while (iVar3 < 8);
        if (DAT_0073578c != 0) {
          FEPackageList__FindByName(&DAT_00746104);
        }
        uVar4 = FEObject__SetScript("Highlight",1);
        return uVar4;
      }
      if (param_2 == 0x9089192b) {
        FEngQueuePackagePop("MU_QuickRaceOptions_PC.fng");
        iVar3 = FEngFindPackage();
        if (iVar3 != 0) {
          *(undefined4 *)(iVar3 + 0x1c) = 0xff;
        }
        FEngFindPackage();
LAB_004b7b99:
        if (DAT_00777b4c != 4) {
          uVar4 = FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
          return uVar4;
        }
        uVar4 = FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return uVar4;
      }
    }
  }
  else if (param_2 == 0xabc08912) {
    for (puVar6 = *(undefined4 **)(param_1 + 0x40); puVar6 != (undefined4 *)(param_1 + 0x40);
        puVar6 = (undefined4 *)*puVar6) {
      if (puVar6[7] == param_3) goto LAB_004b7d9d;
    }
    puVar6 = (undefined4 *)0x0;
LAB_004b7d9d:
    DAT_00777cc8 = puVar6[2];
    FUN_00414a60();
    FUN_00414a60();
    param_2 = Screen_MU_QuickRaceModeSelect__DrawRaceMode();
  }
  else if (param_2 == 0xc519bfc8) {
    param_2 = FEPackageList__FindByName(&DAT_00746104);
    if (((param_2 == 0) || (*(int *)(param_2 + 0x18) == 0)) &&
       (param_2 = FEngIsPackagePushed(), (char)param_2 == '\0')) {
      FEngGetCurrentButton(*(undefined4 *)(param_1 + 0xc));
      iVar3 = Screen_MU_QuickRaceModeSelect__FindRaceMode_ByObject();
      param_2 = *(uint *)(iVar3 + 8);
      if (param_2 == 5) {
        DAT_006faefc = param_2;
        uVar4 = FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return uVar4;
      }
      if (param_2 == 6) {
        DAT_006faefc = param_2;
        uVar4 = FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return uVar4;
      }
    }
  }
  else if (param_2 == 0xc98356ba) {
    FUN_004b7dd0();
    iVar3 = DAT_0073ad3c - *(int *)(param_1 + 0x60);
    fVar1 = (float)iVar3 * 0.00025;
    param_2 = CONCAT22((short)((uint)iVar3 >> 0x10),
                       (ushort)(fVar1 < _K_HALF) << 8 | (ushort)(NAN(fVar1) || NAN(_K_HALF)) << 10 |
                       (ushort)(fVar1 == _K_HALF) << 0xe);
    if ((fVar1 >= _K_HALF && (fVar1 == _K_HALF) == 0) &&
       (param_2 = CONCAT31((int3)(param_2 >> 8),*(char *)(param_1 + 0x54)),
       *(char *)(param_1 + 0x54) != '\0')) {
      FUN_004b7ea0();
      uVar4 = FEObject__SetScript("FadeIn",1);
      *(undefined1 *)(param_1 + 0x54) = 0;
      return uVar4;
    }
  }
  return param_2;
}


// ==== 0x4b7dd0 FUN_004b7dd0

void FUN_004b7dd0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int *piVar4;
  
  piVar4 = (int *)(unaff_ESI + 0x48);
  iVar3 = 2;
  do {
    if ((*piVar4 != 0) && (DAT_007064b2 != '\0')) {
      cVar1 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0));
      if ((cVar1 != '\0') &&
         ((*(int *)(*piVar4 + 0x10) == -0x7bd5c9be || (*(int *)(*piVar4 + 0x10) == -0x7bd5c9bd)))) {
        iVar2 = FEPackageList__FindByName(&DAT_00746104);
        if ((iVar2 != 0) &&
           ((*(int *)(iVar2 + 0x18) != 0 && (*(int **)(iVar2 + 0x14) != (int *)0x0)))) {
          (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0xc519bfc8,0,0,*(int *)(iVar2 + 0x18));
        }
      }
    }
    piVar4 = piVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


// ==== 0x4b7e80 Screen_MU_QuickRaceModeSelect::NotifySoundMessage

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

undefined4 Screen_MU_QuickRaceModeSelect__NotifySoundMessage(int param_1)

{
  undefined4 uVar1;
  undefined4 in_stack_00000014;
  
  uVar1 = 5;
  if (param_1 != -0x3ae64040) {
    uVar1 = in_stack_00000014;
  }
  return uVar1;
}


// ==== 0x4b7ea0 FUN_004b7ea0

void FUN_004b7ea0(void)

{
  undefined4 *puVar1;
  int unaff_ESI;
  
  for (puVar1 = *(undefined4 **)(unaff_ESI + 0x40); puVar1 != (undefined4 *)(unaff_ESI + 0x40);
      puVar1 = (undefined4 *)*puVar1) {
    if (puVar1[2] == DAT_00777cc8) goto LAB_004b7ebe;
  }
  puVar1 = (undefined4 *)0x0;
LAB_004b7ebe:
  FUN_00495f00(puVar1[5]);
  return;
}


// ==== 0x4b7ee0 Screen_MU_QuickRaceOptions_PC::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_QuickRaceOptions_PC__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689283;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0xa4);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_QuickRaceOptions_PC__Screen_MU_QuickRaceOptions_PC(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4b7f40 Screen_MU_QuickRaceOptions_PC::Screen_MU_QuickRaceOptions_PC

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 *
Screen_MU_QuickRaceOptions_PC__Screen_MU_QuickRaceOptions_PC(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_006c5dcc;
  if (param_1[3] == 0) {
LAB_004b7f96:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xa9464188);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_004b7f96;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004b7f96;
  }
  FEObject__SetInvisible(iVar1);
  if (param_1[3] != 0) {
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004b7ff9;
    }
  }
  if (DAT_0073578c == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004ef050(0x13dccc51);
  }
LAB_004b7ff9:
  FEObject__SetInvisible(iVar1);
  FUN_004b8750(param_1,0);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4b8020 FUN_004b8020

void * __thiscall FUN_004b8020(void *param_1,byte param_2)

{
  FUN_004b8040();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4b8040 FUN_004b8040

void __fastcall FUN_004b8040(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c5dcc;
  FUN_004f7b50();
  return;
}


// ==== 0x4b8050 FUN_004b8050

void __thiscall FUN_004b8050(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  if (param_2 < 0xabc08913) {
    if (param_2 == 0xabc08912) {
      if (*(int *)(param_3 + 0x10) != 0x5b9d88b9) {
        FUN_004c96c0(0x1122aacc);
        return;
      }
      FUN_004c96c0(0x1122aabb);
      return;
    }
    if (param_2 == 0xc407210) {
      QuickRace__StartRaceByMode();
      return;
    }
    if (param_2 == 0x911ab364) {
      FUN_004c96c0(0x1122aabb);
      FEngQueuePackagePop(*(undefined4 *)(param_1 + 0xc));
      return;
    }
    if (param_2 != 0x9120409e) {
      return;
    }
  }
  else if (param_2 != 0xb5971bf1) {
    if (param_2 != 0xc98356ba) {
      return;
    }
    FUN_004b8c30(param_1);
    return;
  }
  uVar1 = *(uint *)(param_3 + 0x10);
  if (uVar1 < 0x4caa28d3) {
    if (uVar1 == 0x4caa28d2) {
      (**(code **)(param_1 + 0x70))(param_2);
      return;
    }
    if (uVar1 < 0x4c85f7d1) {
      if (uVar1 == 0x4c85f7d0) {
        (**(code **)(param_1 + 0x68))(param_2);
        return;
      }
      if (uVar1 == 0x4c61c6ce) {
        (**(code **)(param_1 + 0x60))(param_2);
        return;
      }
      if (uVar1 == 0x4c73df4f) {
        (**(code **)(param_1 + 100))(param_2);
        return;
      }
    }
    else if (uVar1 == 0x4c981051) {
      (**(code **)(param_1 + 0x6c))(param_2);
      return;
    }
  }
  else if (uVar1 < 0x4ce07256) {
    if (uVar1 == 0x4ce07255) {
      (**(code **)(param_1 + 0x7c))(param_2);
      return;
    }
    if (uVar1 == 0x4cbc4153) {
      (**(code **)(param_1 + 0x74))(param_2);
      return;
    }
    if (uVar1 == 0x4cce59d4) {
      (**(code **)(param_1 + 0x78))(param_2);
      return;
    }
  }
  else if (uVar1 == 0x4cf28ad6) {
    (**(code **)(param_1 + 0x80))(param_2);
  }
  return;
}


// ==== 0x4b81c0 Screen_MU_QuickRaceOptions_PC::NotifySoundMessage

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

undefined4 Screen_MU_QuickRaceOptions_PC__NotifySoundMessage(int param_1)

{
  undefined4 in_stack_00000014;
  
  if (param_1 == -0x6edfbf62) {
    return 1;
  }
  if (param_1 != -0x4a68e40f) {
    return in_stack_00000014;
  }
  return 2;
}


// ==== 0x4b81f0 FUN_004b81f0

void __fastcall FUN_004b81f0(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"Option%1dTextString",*(undefined4 *)(param_1 + 0x84));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  bSPrintf_regdst(0x20,"Option%1dData",*(undefined4 *)(param_1 + 0x84));
  iVar1 = RaceOptions_Get();
  FEngPrintf(&DAT_006ca778,*(undefined4 *)(iVar1 + 0x10));
  return;
}


// ==== 0x4b8280 FUN_004b8280

void __fastcall FUN_004b8280(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"Option%1dTextString",*(undefined4 *)(param_1 + 0x90));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  bSPrintf_regdst(0x20,"Option%1dData",*(undefined4 *)(param_1 + 0x90));
  iVar1 = RaceOptions_Get();
  FEngPrintf(&DAT_006ca778,*(undefined4 *)(iVar1 + 0x20));
  return;
}


// ==== 0x4b8310 FUN_004b8310

void __fastcall FUN_004b8310(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"Option%1dTextString",*(undefined4 *)(param_1 + 0x98));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  bSPrintf_regdst(0x20,"Option%1dData",*(undefined4 *)(param_1 + 0x98));
  RaceOptions_Get();
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  return;
}


// ==== 0x4b83c0 FUN_004b83c0

void __fastcall FUN_004b83c0(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"Option%1dTextString",*(undefined4 *)(param_1 + 0x9c));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  bSPrintf_regdst(0x20,"Option%1dData",*(undefined4 *)(param_1 + 0x9c));
  iVar1 = RaceOptions_Get();
  switch(*(undefined4 *)(iVar1 + 0x18)) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    goto switchD_004b8438_default;
  }
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
switchD_004b8438_default:
  return;
}


// ==== 0x4b84a0 FUN_004b84a0

void __fastcall FUN_004b84a0(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"Option%1dTextString",*(undefined4 *)(param_1 + 0xa0));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  bSPrintf_regdst(0x20,"Option%1dData",*(undefined4 *)(param_1 + 0xa0));
  iVar1 = RaceOptions_Get();
  iVar1 = *(int *)(iVar1 + 0x14);
  if (((iVar1 == 0) || (iVar1 == 1)) || (iVar1 == 2)) {
    iVar1 = LanguageStrings__FindByHash();
    if (iVar1 == 0) {
      iVar1 = LanguageStrings__FindByHash();
    }
    FEngPrintf(iVar1);
  }
  return;
}


// ==== 0x4b8560 FUN_004b8560

void FUN_004b8560(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = RaceOptions_Get();
  piVar1 = (int *)(iVar2 + 0x10);
  iVar2 = *piVar1;
  if (param_1 == -0x6edfbf62) {
    iVar2 = iVar2 + -1;
    if (iVar2 < 1) {
      *piVar1 = 10;
      FUN_004b81f0();
      return;
    }
  }
  else if ((param_1 == -0x4a68e40f) && (iVar2 = iVar2 + 1, 10 < iVar2)) {
    iVar2 = 1;
  }
  *piVar1 = iVar2;
  FUN_004b81f0();
  return;
}


// ==== 0x4b85c0 FUN_004b85c0

void FUN_004b85c0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RaceOptions_Get();
  iVar2 = *(int *)(iVar1 + 0x20);
  if (param_1 == -0x6edfbf62) {
    iVar2 = iVar2 + -1;
    if (iVar2 < 3) {
      iVar2 = 8;
    }
  }
  else if ((param_1 == -0x4a68e40f) && (iVar2 = iVar2 + 1, 8 < iVar2)) {
    iVar2 = 3;
  }
  *(int *)(iVar1 + 0x20) = iVar2;
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x828bb152,0,0,*(int *)(iVar2 + 0x18));
  }
  FUN_004b8280();
  return;
}


// ==== 0x4b8650 FUN_004b8650

void FUN_004b8650(int param_1)

{
  int iVar1;
  
  if ((param_1 == -0x6edfbf62) || (param_1 == -0x4a68e40f)) {
    iVar1 = RaceOptions_Get();
    *(bool *)(iVar1 + 0x1f) = *(char *)(iVar1 + 0x1f) == '\0';
  }
  FUN_004b8310();
  return;
}


// ==== 0x4b8690 FUN_004b8690

void FUN_004b8690(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = RaceOptions_Get();
  piVar1 = (int *)(iVar2 + 0x18);
  iVar2 = *piVar1;
  if (param_1 == -0x6edfbf62) {
    iVar2 = iVar2 + -1;
    if (iVar2 < 0) {
      *piVar1 = 3;
      FUN_004b83c0();
      return;
    }
  }
  else if ((param_1 == -0x4a68e40f) && (iVar2 = iVar2 + 1, 3 < iVar2)) {
    iVar2 = 0;
  }
  *piVar1 = iVar2;
  FUN_004b83c0();
  return;
}


// ==== 0x4b86f0 FUN_004b86f0

void FUN_004b86f0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = RaceOptions_Get();
  piVar1 = (int *)(iVar2 + 0x14);
  iVar2 = *piVar1;
  if (param_1 == -0x6edfbf62) {
    iVar2 = iVar2 + -1;
    if (iVar2 < 0) {
      *piVar1 = 2;
      FUN_004b84a0();
      return;
    }
  }
  else if ((param_1 == -0x4a68e40f) && (iVar2 = iVar2 + 1, 2 < iVar2)) {
    iVar2 = 0;
  }
  *piVar1 = iVar2;
  FUN_004b84a0();
  return;
}


// ==== 0x4b8750 FUN_004b8750

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b8750(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_4c;
  int *local_48;
  int local_44;
  byte local_40;
  byte local_3f [31];
  byte local_20;
  byte local_1f [31];
  
  local_4c = 1;
  local_48 = (int *)0x9;
  do {
    bSPrintf_regdst(0x20,"Option%dText",local_4c);
    iVar8 = -1;
    pbVar5 = &local_40;
    bVar2 = local_40;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar5 + 1;
      pbVar5 = pbVar5 + 1;
      bVar2 = *pbVar1;
    }
    if (((DAT_0073578c != 0) && (iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 != 0)) &&
       (iVar3 = *(int *)(iVar3 + 0x18), iVar3 != 0)) {
      iVar7 = *(int *)(iVar3 + 0x88);
      iVar9 = 0;
      if (iVar7 != 0) {
        piVar6 = *(int **)(iVar3 + 0x84);
        do {
          if (*(int *)(*piVar6 + 0x10) == iVar8) {
            iVar9 = *piVar6;
          }
          piVar6 = piVar6 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        if (iVar9 != 0) {
          *(uint *)(iVar9 + 0x1c) = *(uint *)(iVar9 + 0x1c) | 0x4000000;
        }
      }
    }
    iVar8 = -1;
    pbVar5 = &local_40;
    bVar2 = local_40;
    while (bVar2 != 0) {
      uVar4 = (uint)bVar2;
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        uVar4 = (uint)(byte)(bVar2 - 0x20);
      }
      pbVar1 = pbVar5 + 1;
      iVar8 = iVar8 * 0x21 + uVar4;
      pbVar5 = pbVar5 + 1;
      bVar2 = *pbVar1;
    }
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004b889c:
      if (DAT_0073578c == 0) {
LAB_004b88b2:
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
        if (DAT_0073578c != 0) {
          iVar7 = *(int *)(DAT_0073578c + 8);
          if ((iVar7 == 0) ||
             ((iVar3 = FUN_004fd1e0(iVar7 + 0xdc), iVar3 == 0 &&
              (iVar3 = FUN_004fd1e0(iVar7 + 0xec), iVar3 == 0)))) goto LAB_004b889c;
          goto LAB_004b888b;
        }
        goto LAB_004b88b2;
      }
LAB_004b888b:
      if ((iVar3 == 0) || (iVar3 = FUN_004ffb70(), iVar3 == 0)) goto LAB_004b889c;
    }
    FEObject__SetInvisible(iVar3);
    bSPrintf_regdst(0x20,"Option%dData",local_4c);
    iVar8 = -1;
    pbVar5 = &local_40;
    bVar2 = local_40;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar5 + 1;
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      pbVar5 = pbVar5 + 1;
      bVar2 = *pbVar1;
    }
    iVar3 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004b896a:
      if (iVar3 == 0) {
LAB_004b897b:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar3 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar9 = *(int *)(DAT_0073578c + 8);
          if ((iVar9 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar9 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar9 + 0xec), iVar7 == 0)))) goto LAB_004b896a;
          goto LAB_004b8953;
        }
        goto LAB_004b897b;
      }
LAB_004b8953:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar3 = DAT_0073578c, iVar7 == 0))
      goto LAB_004b896a;
    }
    FEObject__SetInvisible(iVar7);
    local_4c = local_4c + 1;
    local_48 = (int *)((int)local_48 + -1);
  } while (local_48 != (int *)0x0);
  switch(DAT_00777cc8) {
  case 0:
    FUN_004b8e60();
    break;
  case 1:
    FUN_004b8f40();
    break;
  case 2:
    FUN_004b8fe0();
    break;
  case 3:
    if (DAT_00777b4c == 4) {
      _DAT_007589f8 = 0;
    }
    FUN_004b8d50(1);
    *(undefined4 *)(param_1 + 0x9c) = 1;
    *(code **)(param_1 + 0x60) = FUN_004b8690;
    FUN_004b83c0();
    break;
  case 4:
    FUN_004b9070();
    break;
  case 5:
    FUN_004b9130();
    break;
  case 6:
    FUN_004b9190();
  }
  local_48 = (int *)(param_1 + 0x50);
  local_4c = 1;
  local_44 = 4;
  do {
    bSPrintf_regdst(0x20,"option%d_arrow_L_button",local_4c);
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
    iVar3 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004b8af3:
      if (iVar3 == 0) {
LAB_004b8b04:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar3 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar9 = *(int *)(DAT_0073578c + 8);
          if ((iVar9 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar9 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar9 + 0xec), iVar7 == 0)))) goto LAB_004b8af3;
          goto LAB_004b8adc;
        }
        goto LAB_004b8b04;
      }
LAB_004b8adc:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar3 = DAT_0073578c, iVar7 == 0))
      goto LAB_004b8af3;
    }
    local_48[-4] = iVar7;
    bSPrintf_regdst(0x20,"option%d_arrow_R_button",local_4c);
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
    iVar3 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004b8bc3:
      if (iVar3 == 0) {
LAB_004b8bd4:
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar7 = FEPackageList__FindByName(&DAT_00746104);
      iVar3 = DAT_0073578c;
      if ((iVar7 == 0) || (iVar7 = *(int *)(iVar7 + 0x18), iVar7 == 0)) {
        if (DAT_0073578c != 0) {
          iVar9 = *(int *)(DAT_0073578c + 8);
          if ((iVar9 == 0) ||
             ((iVar7 = FUN_004fd1e0(iVar9 + 0xdc), iVar7 == 0 &&
              (iVar7 = FUN_004fd1e0(iVar9 + 0xec), iVar7 == 0)))) goto LAB_004b8bc3;
          goto LAB_004b8bac;
        }
        goto LAB_004b8bd4;
      }
LAB_004b8bac:
      if ((iVar7 == 0) || (iVar7 = FUN_004ffb70(), iVar3 = DAT_0073578c, iVar7 == 0))
      goto LAB_004b8bc3;
    }
    *local_48 = iVar7;
    local_48 = local_48 + 1;
    local_4c = local_4c + 1;
    local_44 = local_44 + -1;
    if (local_44 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x4b8c30 FUN_004b8c30

void FUN_004b8c30(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = (int *)(param_1 + 0x50);
  iVar3 = 4;
  do {
    if ((piVar4[-4] != 0) && (DAT_007064b2 != '\0')) {
      cVar1 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0));
      if ((cVar1 != '\0') && ((*(byte *)(piVar4[-4] + 0x1c) & 1) == 0)) {
        uVar2 = FEngFindPackage();
        if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
          FUN_004f0700(0xc407210,piVar4[-4],uVar2,piVar4[-4],0);
        }
      }
    }
    if ((*piVar4 != 0) && (DAT_007064b2 != '\0')) {
      cVar1 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0));
      if ((cVar1 != '\0') && ((*(byte *)(*piVar4 + 0x1c) & 1) == 0)) {
        uVar2 = FEngFindPackage();
        if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
          FUN_004f0700(0xc407210,*piVar4,uVar2,*piVar4,0);
        }
      }
    }
    piVar4 = piVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


// ==== 0x4b8d50 FUN_004b8d50

void FUN_004b8d50(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  bSPrintf_regdst(0x20,"Option%dText",param_1);
  iVar1 = DAT_0073578c;
  if (DAT_0073578c != 0) {
    uVar2 = 1;
    FEng__HashName(1);
    cFEng__SetButtonState(iVar1,uVar2);
  }
  FUN_00414a60();
  bSPrintf_regdst(0x20,"Option%dData",param_1);
  FUN_00414a60();
  bSPrintf_regdst(0x20,"Option%dTextString",param_1);
  FUN_00414a60();
  bSPrintf_regdst(0x20,"Option%d_Arrow_L",param_1);
  FUN_00414a60();
  bSPrintf_regdst(0x20,"Option%d_arrow_r",param_1);
  FUN_00414a60();
  bSPrintf_regdst(0x20,"Option%d_Arrow_L_Button",param_1);
  FUN_00414a60();
  bSPrintf_regdst(0x20,"Option%d_Arrow_R_Button",param_1);
  FUN_00414a60();
  return;
}


// ==== 0x4b8e60 FUN_004b8e60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b8e60(void)

{
  int in_EAX;
  int iVar1;
  
  if (DAT_00777b4c == 4) {
    iVar1 = 0;
    _DAT_00758998 = 0;
    do {
      iVar1 = iVar1 + 1;
      FUN_004b8d50(iVar1);
    } while (iVar1 < 2);
    *(undefined4 *)(in_EAX + 0x84) = 1;
    *(code **)(in_EAX + 0x60) = FUN_004b8560;
    FUN_004b81f0();
    *(undefined4 *)(in_EAX + 0x9c) = 2;
    *(code **)(in_EAX + 100) = FUN_004b8690;
    FUN_004b83c0();
    return;
  }
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    FUN_004b8d50(iVar1);
  } while (iVar1 < 4);
  *(undefined4 *)(in_EAX + 0x84) = 1;
  *(code **)(in_EAX + 0x60) = FUN_004b8560;
  FUN_004b81f0();
  *(undefined4 *)(in_EAX + 0x98) = 2;
  *(code **)(in_EAX + 100) = FUN_004b8650;
  FUN_004b8310();
  *(undefined4 *)(in_EAX + 0x9c) = 3;
  *(code **)(in_EAX + 0x68) = FUN_004b8690;
  FUN_004b83c0();
  *(undefined4 *)(in_EAX + 0xa0) = 4;
  *(code **)(in_EAX + 0x6c) = FUN_004b86f0;
  FUN_004b84a0();
  return;
}


// ==== 0x4b8f40 FUN_004b8f40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b8f40(void)

{
  int in_EAX;
  int iVar1;
  
  if (DAT_00777b4c == 4) {
    _DAT_007589b8 = 0;
    FUN_004b8d50(1);
    *(undefined4 *)(in_EAX + 0x9c) = 1;
    *(code **)(in_EAX + 0x60) = FUN_004b8690;
    FUN_004b83c0();
    return;
  }
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    FUN_004b8d50(iVar1);
  } while (iVar1 < 3);
  *(undefined4 *)(in_EAX + 0x98) = 1;
  *(code **)(in_EAX + 0x60) = FUN_004b8650;
  FUN_004b8310();
  *(undefined4 *)(in_EAX + 0x9c) = 2;
  *(code **)(in_EAX + 100) = FUN_004b8690;
  FUN_004b83c0();
  *(undefined4 *)(in_EAX + 0xa0) = 3;
  *(code **)(in_EAX + 0x68) = FUN_004b86f0;
  FUN_004b84a0();
  return;
}


// ==== 0x4b8fe0 FUN_004b8fe0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b8fe0(void)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_00777b4c == 4) {
    _DAT_007589d8 = 0;
  }
  do {
    iVar1 = iVar1 + 1;
    FUN_004b8d50(iVar1);
  } while (iVar1 < 2);
  *(undefined4 *)(in_EAX + 0x98) = 1;
  *(code **)(in_EAX + 0x60) = FUN_004b8650;
  FUN_004b8310();
  *(undefined4 *)(in_EAX + 0x9c) = 2;
  *(code **)(in_EAX + 100) = FUN_004b8690;
  FUN_004b83c0();
  if (DAT_00777b4c != 4) {
    *(undefined4 *)(in_EAX + 0xa0) = 3;
    *(code **)(in_EAX + 0x68) = FUN_004b86f0;
    FUN_004b84a0();
    FUN_004b8d50(3);
  }
  return;
}


// ==== 0x4b9070 FUN_004b9070

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b9070(void)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_00777b4c == 4) {
    _DAT_00758a1c = 0;
  }
  do {
    iVar1 = iVar1 + 1;
    FUN_004b8d50(iVar1);
  } while (iVar1 < 4);
  *(undefined4 *)(in_EAX + 0x84) = 1;
  *(code **)(in_EAX + 0x60) = FUN_004b8560;
  FUN_004b81f0();
  *(undefined4 *)(in_EAX + 0x90) = 2;
  *(code **)(in_EAX + 100) = FUN_004b85c0;
  FUN_004b8280();
  *(undefined4 *)(in_EAX + 0x98) = 3;
  *(code **)(in_EAX + 0x68) = FUN_004b8650;
  FUN_004b8310();
  *(undefined4 *)(in_EAX + 0x9c) = 4;
  *(code **)(in_EAX + 0x6c) = FUN_004b8690;
  FUN_004b83c0();
  if (DAT_00777b4c != 4) {
    *(undefined4 *)(in_EAX + 0xa0) = 5;
    *(code **)(in_EAX + 0x70) = FUN_004b86f0;
    FUN_004b84a0();
    FUN_004b8d50(5);
  }
  return;
}


// ==== 0x4b9130 FUN_004b9130

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b9130(void)

{
  int in_EAX;
  
  if (DAT_00777b4c == 4) {
    _DAT_00758aa0 = 0;
  }
  FUN_004b8d50(1);
  *(undefined4 *)(in_EAX + 0x9c) = 1;
  *(code **)(in_EAX + 0x60) = FUN_004b8690;
  FUN_004b83c0();
  if (DAT_00777b4c != 4) {
    *(undefined4 *)(in_EAX + 0xa0) = 2;
    *(code **)(in_EAX + 100) = FUN_004b86f0;
    FUN_004b84a0();
    FUN_004b8d50(2);
  }
  return;
}


// ==== 0x4b9190 FUN_004b9190

void FUN_004b9190(void)

{
  int in_EAX;
  
  FUN_004b8d50(1);
  *(undefined4 *)(in_EAX + 0x84) = 1;
  *(code **)(in_EAX + 0x60) = FUN_004b8560;
  FUN_004b81f0();
  if (DAT_00777b4c != 4) {
    *(undefined4 *)(in_EAX + 0xa0) = 2;
    *(code **)(in_EAX + 100) = FUN_004b86f0;
    FUN_004b84a0();
    FUN_004b8d50(2);
  }
  return;
}


// ==== 0x4b91e0 FUN_004b91e0

void FUN_004b91e0(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_EDI;
  
  uVar1 = FEng__HashName();
  if (((unaff_EDI == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      return;
    }
    iVar2 = FUN_004ef050(uVar1);
    if (iVar2 == 0) {
      return;
    }
  }
  if ((*(int *)(iVar2 + 0x18) == 1) && (*(int *)(iVar2 + 0x24) != unaff_EBX)) {
    *(int *)(iVar2 + 0x24) = unaff_EBX;
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
  }
  return;
}


// ==== 0x4b9240 GenericDialogData::GenericDialogData

/* [canon] canon med (ghidra-canon+hopper) docs/re/canon.md */

undefined4 * __fastcall GenericDialogData__GenericDialogData(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  *param_2 = 0;
  puVar2 = param_2;
  for (iVar1 = 8; puVar2 = puVar2 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
  }
  param_2[10] = 0;
  param_2[0xb] = 0;
  param_2[0xc] = 0;
  *(undefined1 *)(param_2 + 0xd) = 0;
  param_2[9] = 1;
  return param_2;
}


// ==== 0x4b9270 FUN_004b9270

void __fastcall FUN_004b9270(undefined4 *param_1)

{
  *param_1 = &PTR_SelectableTrack__scalar_deleting_destructor_006c5bbc;
  return;
}


// ==== 0x4b9280 SelectableTrack::scalar_deleting_destructor

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void * __thiscall SelectableTrack__scalar_deleting_destructor(void *param_1,byte param_2)

{
  FUN_004b9270();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4b92a0 FUN_004b92a0

undefined4 FUN_004b92a0(void)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int unaff_EDI;
  
  sVar1 = *(short *)(*(int *)(unaff_EDI + 0xc) + 0x6c);
  if (sVar1 < 0x44c) {
    uVar2 = FUN_004f42f0("TRACK_%d",(int)sVar1);
    return uVar2;
  }
  if (sVar1 < 0x4b0) {
    uVar2 = FUN_004f42f0("SPRINT_TRACKS_BACK");
    uVar3 = FUN_004f42f0("SPRINT_TRACKS_BACK2");
    switch(*(undefined2 *)(*(int *)(unaff_EDI + 0xc) + 0x6c)) {
    case 0x44d:
    case 0x44e:
    case 0x452:
    case 0x453:
    case 0x454:
    case 0x455:
      return uVar3;
    case 0x44f:
    case 0x450:
    case 0x451:
      return uVar2;
    }
  }
  else {
    if (sVar1 < 0x514) {
      uVar2 = FUN_004f42f0("TRACK_%d",(int)sVar1);
      return uVar2;
    }
    if (sVar1 < 0x519) {
      uVar2 = FUN_004f42f0("DRIFT_TRACKS_BACK");
      return uVar2;
    }
    uVar2 = FUN_004f42f0("DRIFT_TRACKS_BACK2");
  }
  return uVar2;
}


// ==== 0x4b9370 TournamentTrackList::_TournamentTrackList

/* [canon] canon med (ghidra-canon+hopper) docs/re/canon.md */

void __fastcall TournamentTrackList___TournamentTrackList(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = param_1 + 1;
  *param_1 = &PTR_FUN_006c5bb8;
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


// ==== 0x4b93a0 TournamentTrackList::IsFull

/* [canon] canon med (ghidra-canon+hopper) docs/re/canon.md */

bool TournamentTrackList__IsFull(void)

{
  undefined4 *puVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar2 = 0;
  for (puVar1 = *(undefined4 **)(unaff_ESI + 4);
      (puVar1 != (undefined4 *)(unaff_ESI + 4) && (iVar2 = iVar2 + 1, puVar1 != (undefined4 *)0x0));
      puVar1 = (undefined4 *)*puVar1) {
  }
  return iVar2 == *(int *)(unaff_ESI + 0x10);
}


// ==== 0x4b93d0 TournamentTrackList::IsEmpty

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

bool __fastcall TournamentTrackList__IsEmpty(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  for (puVar1 = *(undefined4 **)(param_1 + 4);
      (puVar1 != (undefined4 *)(param_1 + 4) && (iVar2 = iVar2 + 1, puVar1 != (undefined4 *)0x0));
      puVar1 = (undefined4 *)*puVar1) {
  }
  return iVar2 == 0;
}


// ==== 0x4b9400 FUN_004b9400

void * __thiscall FUN_004b9400(void *param_1,byte param_2)

{
  TournamentTrackList___TournamentTrackList();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4b9420 FUN_004b9420

undefined4 * __thiscall FUN_004b9420(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068683b;
  local_c = ExceptionList;
  puVar1 = param_2 + 1;
  ExceptionList = &local_c;
  *param_2 = &PTR_FUN_006c5bb8;
  *puVar1 = puVar1;
  param_2[2] = puVar1;
  param_2[3] = param_1;
  param_2[5] = 0;
  local_4 = 0;
  if (DAT_00777cc8 == 4) {
    iVar2 = RaceOptions_Get();
    param_2[4] = *(undefined4 *)(iVar2 + 0x20);
    FUN_004b9900();
    FUN_004b99c0(param_2);
    ExceptionList = local_c;
    return param_2;
  }
  param_2[4] = 0;
  FUN_004b9960();
  ExceptionList = local_c;
  return param_2;
}


// ==== 0x4b94c0 FUN_004b94c0

void FUN_004b94c0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_EDI;
  
  if (unaff_EDI < *(int *)(unaff_EBX + 0x10)) {
    while( true ) {
      iVar2 = 0;
      for (puVar1 = *(undefined4 **)(unaff_EBX + 4);
          (puVar1 != (undefined4 *)(unaff_EBX + 4) &&
          (iVar2 = iVar2 + 1, puVar1 != (undefined4 *)0x0)); puVar1 = (undefined4 *)*puVar1) {
      }
      if (iVar2 <= unaff_EDI) break;
      FUN_004b9750(unaff_EBX);
    }
  }
  *(int *)(unaff_EBX + 0x10) = unaff_EDI;
  return;
}


// ==== 0x4b9500 FUN_004b9500

void FUN_004b9500(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int in_EAX;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  puVar4 = _malloc(0x1c);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    *puVar4 = &PTR_SelectableTrack__scalar_deleting_destructor_006c5bbc;
    puVar4[3] = *(undefined4 *)(in_EAX + 0xc);
    puVar4[5] = *(undefined4 *)(in_EAX + 0x14);
    puVar4[6] = *(undefined4 *)(in_EAX + 0x18);
  }
  puVar1 = (undefined4 *)(param_1 + 4);
  puVar4[5] = param_2;
  iVar7 = 0;
  for (puVar3 = (undefined4 *)*puVar1;
      (puVar3 != puVar1 && (iVar7 = iVar7 + 1, puVar3 != (undefined4 *)0x0));
      puVar3 = (undefined4 *)*puVar3) {
  }
  bSPrintf_regdst(0x20,"MultiTrack_%d",iVar7 + 1);
  iVar7 = *(int *)(param_1 + 0xc);
  uVar5 = FEng__HashName();
  if (((iVar7 == 0) || (iVar7 = FEngFindPackage(), iVar7 == 0)) ||
     (iVar7 = FUN_004ffb70(), iVar7 == 0)) {
    if (DAT_0073578c != 0) {
      iVar7 = FUN_004ef050(uVar5);
      goto LAB_004b95ae;
    }
  }
  else {
LAB_004b95ae:
    if (iVar7 != 0) {
      for (iVar8 = *(int *)(iVar7 + 0x4c); iVar8 != 0; iVar8 = *(int *)(iVar8 + 4)) {
        iVar6 = FEng__HashName();
        if (*(int *)(iVar8 + 0x30) == iVar6) {
          if (iVar8 != 0) {
            if (iVar8 != *(int *)(iVar7 + 0x54)) {
              *(int *)(iVar7 + 0x54) = iVar8;
              FUN_004ff030(iVar7);
              *(undefined4 *)(*(int *)(iVar7 + 0x54) + 0x10) = 0;
            }
            *(undefined4 *)(iVar8 + 0x10) = 0;
          }
          break;
        }
      }
    }
  }
  puVar3 = *(undefined4 **)(param_1 + 8);
  piVar2 = puVar4 + 1;
  *puVar3 = piVar2;
  *(int **)(param_1 + 8) = piVar2;
  puVar4[2] = puVar3;
  *piVar2 = (int)puVar1;
  iVar7 = 0;
  for (puVar4 = (undefined4 *)*puVar1;
      (puVar4 != puVar1 && (iVar7 = iVar7 + 1, puVar4 != (undefined4 *)0x0));
      puVar4 = (undefined4 *)*puVar4) {
  }
  bSPrintf_regdst(0x20,"MultiTrack_%d",iVar7 + 1);
  iVar7 = *(int *)(param_1 + 0xc);
  uVar5 = FEng__HashName();
  if (((iVar7 == 0) || (iVar7 = FEngFindPackage(), iVar7 == 0)) ||
     (iVar7 = FUN_004ffb70(), iVar7 == 0)) {
    if (DAT_0073578c == 0) goto LAB_004b96c9;
    iVar7 = FUN_004ef050(uVar5);
  }
  if ((iVar7 != 0) && (iVar8 = *(int *)(iVar7 + 0x4c), iVar8 != 0)) {
    while (iVar6 = FEng__HashName(), *(int *)(iVar8 + 0x30) != iVar6) {
      iVar8 = *(int *)(iVar8 + 4);
      if (iVar8 == 0) {
        FUN_004b99c0(param_1);
        return;
      }
    }
    if (iVar8 != 0) {
      if (iVar8 != *(int *)(iVar7 + 0x54)) {
        *(int *)(iVar7 + 0x54) = iVar8;
        FUN_004ff030(iVar7);
        *(undefined4 *)(*(int *)(iVar7 + 0x54) + 0x10) = 0;
      }
      *(undefined4 *)(iVar8 + 0x10) = 0;
    }
  }
LAB_004b96c9:
  FUN_004b99c0(param_1);
  return;
}


// ==== 0x4b96e0 TournamentTrackList::CopyToRaceSetup

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void TournamentTrackList__CopyToRaceSetup(void)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (*(int *)(in_EAX + 4) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(in_EAX + 4) + -4;
  }
  puVar2 = &DAT_00758a2c;
  while( true ) {
    iVar3 = in_EAX;
    if (in_EAX == -4) {
      iVar3 = 0;
    }
    if (iVar1 == iVar3) break;
    if ((int)puVar2 < 0x758a8c) {
      puVar2[-1] = (int)*(short *)(*(int *)(iVar1 + 0xc) + 0x6c);
      *puVar2 = *(undefined4 *)(iVar1 + 0x18);
      puVar2[1] = *(undefined4 *)(iVar1 + 0x14);
      puVar2 = puVar2 + 3;
    }
    if (*(int *)(iVar1 + 4) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 4) + -4;
    }
  }
  return;
}


// ==== 0x4b9750 FUN_004b9750

void FUN_004b9750(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  puVar1 = (undefined4 *)(param_1 + 4);
  iVar7 = 0;
  for (puVar2 = *(undefined4 **)(param_1 + 4);
      (puVar2 != puVar1 && (iVar7 = iVar7 + 1, puVar2 != (undefined4 *)0x0));
      puVar2 = (undefined4 *)*puVar2) {
  }
  bSPrintf_regdst(0x20,"MultiTrack_%d",iVar7 + 1);
  iVar7 = *(int *)(param_1 + 0xc);
  uVar5 = FEng__HashName();
  if (((iVar7 == 0) || (iVar7 = FEngFindPackage(), iVar7 == 0)) ||
     (iVar7 = FUN_004ffb70(), iVar7 == 0)) {
    if (DAT_0073578c != 0) {
      iVar7 = FUN_004ef050(uVar5);
      goto LAB_004b97c5;
    }
  }
  else {
LAB_004b97c5:
    if (iVar7 != 0) {
      for (iVar8 = *(int *)(iVar7 + 0x4c); iVar8 != 0; iVar8 = *(int *)(iVar8 + 4)) {
        iVar6 = FEng__HashName();
        if (*(int *)(iVar8 + 0x30) == iVar6) {
          if (iVar8 != 0) {
            if (iVar8 != *(int *)(iVar7 + 0x54)) {
              *(int *)(iVar7 + 0x54) = iVar8;
              FUN_004ff030(iVar7);
              *(undefined4 *)(*(int *)(iVar7 + 0x54) + 0x10) = 0;
            }
            *(undefined4 *)(iVar8 + 0x10) = 0;
          }
          break;
        }
      }
    }
  }
  piVar3 = *(int **)(param_1 + 8);
  iVar7 = *piVar3;
  piVar4 = (int *)piVar3[1];
  *piVar4 = iVar7;
  *(int **)(iVar7 + 4) = piVar4;
  if (piVar3 + -1 != (int *)0x0) {
    (**(code **)piVar3[-1])(1);
  }
  iVar7 = 0;
  for (puVar2 = (undefined4 *)*puVar1;
      (puVar2 != puVar1 && (iVar7 = iVar7 + 1, puVar2 != (undefined4 *)0x0));
      puVar2 = (undefined4 *)*puVar2) {
  }
  bSPrintf_regdst(0x20,"MultiTrack_%d",iVar7 + 1);
  iVar7 = *(int *)(param_1 + 0xc);
  uVar5 = FEng__HashName();
  if (((iVar7 == 0) || (iVar7 = FEngFindPackage(), iVar7 == 0)) ||
     (iVar7 = FUN_004ffb70(), iVar7 == 0)) {
    if (DAT_0073578c == 0) goto LAB_004b98e6;
    iVar7 = FUN_004ef050(uVar5);
  }
  if ((iVar7 != 0) && (iVar8 = *(int *)(iVar7 + 0x4c), iVar8 != 0)) {
    while (iVar6 = FEng__HashName(), *(int *)(iVar8 + 0x30) != iVar6) {
      iVar8 = *(int *)(iVar8 + 4);
      if (iVar8 == 0) {
        FUN_004b99c0(param_1);
        return;
      }
    }
    if (iVar8 != 0) {
      if (iVar8 != *(int *)(iVar7 + 0x54)) {
        *(int *)(iVar7 + 0x54) = iVar8;
        FUN_004ff030(iVar7);
        *(undefined4 *)(*(int *)(iVar7 + 0x54) + 0x10) = 0;
      }
      *(undefined4 *)(iVar8 + 0x10) = 0;
    }
  }
LAB_004b98e6:
  FUN_004b99c0(param_1);
  return;
}


// ==== 0x4b9900 FUN_004b9900

void FUN_004b9900(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(in_EAX + 0xc) != 0) {
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004b9948;
    }
  }
  if (DAT_0073578c != 0) {
    uVar2 = FUN_004ef050(0xb2189b5f);
    FEObject__SetVisible(uVar2);
    return;
  }
  iVar1 = 0;
LAB_004b9948:
  FEObject__SetVisible(iVar1);
  return;
}


// ==== 0x4b9960 FUN_004b9960

void FUN_004b9960(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(in_EAX + 0xc) != 0) {
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004b99a8;
    }
  }
  if (DAT_0073578c != 0) {
    uVar2 = FUN_004ef050(0xb2189b5f);
    FEObject__SetInvisible(uVar2);
    return;
  }
  iVar1 = 0;
LAB_004b99a8:
  FEObject__SetInvisible(iVar1);
  return;
}


// ==== 0x4b99c0 FUN_004b99c0

void FUN_004b99c0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 4);
  iVar1 = 0;
  while( true ) {
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = iVar4 + -4;
    }
    iVar3 = param_1;
    if (param_1 == -4) {
      iVar3 = 0;
    }
    if (iVar4 == iVar3) break;
    iVar1 = iVar1 + 1;
    FUN_004f42f0("MULTITRACK_%d",iVar1);
    uVar2 = FUN_004ad6d0(*(undefined4 *)(iVar4 + 0x18));
    FUN_00495f00(uVar2);
    iVar4 = *(int *)(iVar4 + 4);
  }
  iVar4 = *(int *)(param_1 + 0x14);
  if (iVar4 != 0) {
    if (*(int *)(param_1 + 0x10) <= iVar1) goto LAB_004b9aa9;
    iVar1 = iVar1 + 1;
    FUN_004f42f0("MULTITRACK_%d",iVar1);
    uVar2 = FUN_004ad6d0(*(undefined4 *)(iVar4 + 0x18));
    FUN_00495f00(uVar2);
  }
  if (iVar1 < *(int *)(param_1 + 0x10)) {
    do {
      iVar1 = iVar1 + 1;
      FUN_004f42f0("MULTITRACK_%d",iVar1);
      FEngPrintf("<empty>");
    } while (iVar1 < *(int *)(param_1 + 0x10));
  }
LAB_004b9aa9:
  if (iVar1 < 8) {
    iVar1 = iVar1 + 1;
    do {
      FUN_004f42f0("MULTITRACK_%d",iVar1);
      FEngPrintf(&DAT_006b9172);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 9);
  }
  return;
}


// ==== 0x4b9ae0 Screen_MU_QuickRaceTrackSelect::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_QuickRaceTrackSelect__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689263;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0xb0);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_QuickRaceTrackSelect__Screen_MU_QuickRaceTrackSelect(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4b9b40 Screen_MU_QuickRaceTrackSelect::Screen_MU_QuickRaceTrackSelect

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 *
Screen_MU_QuickRaceTrackSelect__Screen_MU_QuickRaceTrackSelect
          (undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0068737c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  puVar1 = param_1 + 0x10;
  *param_1 = &PTR_FUN_006c5ba8;
  *puVar1 = puVar1;
  param_1[0x11] = puVar1;
  local_4._0_1_ = 1;
  local_4._1_3_ = 0;
  FUN_004f8370(param_1 + 0x13,"track_thumb_master","track_thumb");
  local_4._0_1_ = 2;
  FUN_004b9420(param_1 + 0x22);
  param_1[0x2b] = 0;
  local_4 = CONCAT31(local_4._1_3_,3);
  DAT_00735e74 = 0;
  *(undefined1 *)((int)param_1 + 0xa5) = 0;
  if (((param_1[3] == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0xa9464188);
    }
  }
  FEObject__SetInvisible(iVar2);
  if (((param_1[3] == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0x13dccc51);
    }
  }
  FEObject__SetInvisible(iVar2);
  if (DAT_00777b4c != 4) {
    FUN_00414a10();
  }
  if (DAT_0073578c != 0) {
    iVar3 = *(int *)(DAT_0073578c + 8);
    iVar2 = iVar3 + 0xdc;
    if ((iVar2 == 0) || (iVar2 = FUN_004fd1e0(iVar2), iVar2 == 0)) {
      cFEng__PushPackage(iVar3,"MU_TrackMapScroller.fng",0xf,0);
    }
  }
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  iVar2 = DAT_0073578c;
  if ((((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (DAT_0073578c != 0)) &&
     ((iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 != 0 && (*(int *)(iVar3 + 0x18) != 0)
      ))) {
    cFEng__PopPackage(*(undefined4 *)(iVar2 + 8),*(int *)(iVar3 + 0x18));
  }
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  iVar2 = DAT_0073578c;
  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) &&
     ((DAT_0073578c != 0 &&
      ((iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 != 0 &&
       (*(int *)(iVar3 + 0x18) != 0)))))) {
    cFEng__PopPackage(*(undefined4 *)(iVar2 + 8),*(int *)(iVar3 + 0x18));
  }
  param_1[0x28] = 0;
  FUN_004ba100(param_1);
  iVar2 = RaceOptions_Get();
  *(int *)(iVar2 + 8) = (int)*(short *)(*(int *)(param_1[0x12] + 0xc) + 0x6c);
  *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(param_1[0x12] + 0x18);
  iVar2 = param_1[3];
  *(undefined1 *)((int)param_1 + 0xa6) = 0;
  param_1[0x2b] = 0;
  uVar4 = FEng__HashName();
  if ((((iVar2 == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
      (iVar2 = FUN_004ffb70(), iVar2 == 0)) && (DAT_0073578c != 0)) {
    FUN_004ef050(uVar4);
  }
  uVar4 = GetHudObjectColor();
  param_1[0x2a] = uVar4;
  switch(DAT_006ee6f0) {
  case 1:
  case 3:
  case 4:
    break;
  default:
    goto switchD_004b9dc7_caseD_2;
  case 5:
  case 6:
  }
  FEng__HashName();
  FUN_004b91e0();
switchD_004b9dc7_caseD_2:
  FUN_004ba530(param_1);
  *(undefined1 *)(param_1 + 0x29) = 0;
  if (DAT_00777cc8 == 4) {
    pcVar5 = "Highlight";
  }
  else {
    pcVar5 = "Hide";
  }
  FEngSetScript(pcVar5,1);
  FUN_004b2410();
  *(undefined1 *)(param_1 + 8) = 1;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4b9e60 FUN_004b9e60

void * __thiscall FUN_004b9e60(void *param_1,byte param_2)

{
  FUN_004b9e80(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4b9e80 FUN_004b9e80

void FUN_004b9e80(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  void *pvStack_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_0068737c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c5ba8;
  iVar2 = DAT_0073578c;
  local_4 = 3;
  if (((DAT_0073578c != 0) && (iVar4 = FEPackageList__FindByName(&DAT_00746104), iVar4 != 0)) &&
     (*(int *)(iVar4 + 0x18) != 0)) {
    cFEng__PopPackage(*(undefined4 *)(iVar2 + 8),*(int *)(iVar4 + 0x18));
  }
  local_4._0_1_ = 2;
  TournamentTrackList___TournamentTrackList();
  FUN_004f84d0();
  piVar1 = (int *)param_1[0x10];
  local_4 = (uint)local_4._1_3_ << 8;
  while (piVar1 != param_1 + 0x10) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    if (piVar1 + -1 != (int *)0x0) {
      (**(code **)piVar1[-1])(1);
    }
    piVar1 = (int *)param_1[0x10];
  }
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4b9f40 Screen_MU_QuickRaceTrackSelect::AddTrack

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void __fastcall Screen_MU_QuickRaceTrackSelect__AddTrack(undefined4 param_1)

{
  char cVar1;
  undefined4 in_EAX;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  int unaff_ESI;
  
  puVar2 = _malloc(0x1c);
  puVar4 = (undefined4 *)0x0;
  if (puVar2 == (undefined4 *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    puVar2[5] = 0;
    *puVar2 = &PTR_SelectableTrack__scalar_deleting_destructor_006c5bbc;
    puVar2[3] = param_1;
    puVar2[6] = in_EAX;
    piVar3 = puVar2 + 1;
    puVar4 = puVar2;
  }
  puVar2 = *(undefined4 **)(unaff_ESI + 0x44);
  *puVar2 = piVar3;
  *(int **)(unaff_ESI + 0x44) = piVar3;
  piVar3[1] = (int)puVar2;
  *piVar3 = unaff_ESI + 0x40;
  *(int *)(unaff_ESI + 0xa0) = *(int *)(unaff_ESI + 0xa0) + 1;
  cVar1 = Career__IsTrackUnlocked(&DAT_0075eef8);
  *(char *)(puVar4 + 4) = '\x01' - (cVar1 != '\0');
  return;
}


// ==== 0x4b9fa0 FUN_004b9fa0

undefined1 FUN_004b9fa0(void)

{
  char cVar1;
  int unaff_ESI;
  
  if (DAT_00735e74 == 0) {
    cVar1 = FUN_0059e510(*(undefined4 *)(unaff_ESI + 0x18));
    if (cVar1 == '\0') {
      return *(undefined1 *)(unaff_ESI + 0x10);
    }
  }
  return 0;
}


// ==== 0x4b9fd0 Screen_MU_QuickRaceTrackSelect::SortTracks

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

void Screen_MU_QuickRaceTrackSelect__SortTracks(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int local_8;
  
  iVar4 = Ptr_BaseAdjustMinus4();
  do {
    local_8 = 0;
    if (*param_1 == 0) {
      iVar9 = 0;
    }
    else {
      iVar9 = *param_1 + -4;
    }
    if (*(int *)(iVar9 + 4) == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = *(int *)(iVar9 + 4) + -4;
    }
    if (iVar9 == iVar4) {
      return;
    }
    do {
      if (iVar7 == iVar4) break;
      iVar1 = *(int *)(*(int *)(iVar9 + 0xc) + 0xa0);
      uVar5 = 0;
      uVar8 = 0;
      if (iVar1 == 1) {
        uVar5 = 2;
      }
      else if (iVar1 == 2) {
        uVar5 = 4;
      }
      iVar1 = *(int *)(*(int *)(iVar7 + 0xc) + 0xa0);
      if (iVar1 == 1) {
        uVar8 = 2;
      }
      else if (iVar1 == 2) {
        uVar8 = 4;
      }
      if (*(int *)(iVar9 + 0x18) == 1) {
        uVar5 = uVar5 + 8;
      }
      if (*(int *)(iVar7 + 0x18) == 1) {
        uVar8 = uVar8 + 8;
      }
      if (uVar8 < uVar5) {
        iVar1 = *(int *)(iVar7 + 4);
        piVar2 = *(int **)(iVar7 + 8);
        piVar6 = (int *)(iVar7 + 4);
        *piVar2 = iVar1;
        *(int **)(iVar1 + 4) = piVar2;
        puVar3 = *(undefined4 **)(iVar9 + 8);
        *puVar3 = piVar6;
        *(int **)(iVar9 + 8) = piVar6;
        *(undefined4 **)(iVar7 + 8) = puVar3;
        *piVar6 = iVar9 + 4;
        iVar7 = *(int *)(iVar9 + 4);
        if (iVar7 == 0) {
          iVar7 = 0;
          local_8 = local_8 + 1;
        }
        else {
          local_8 = local_8 + 1;
          iVar7 = iVar7 + -4;
        }
      }
      else {
        iVar9 = iVar7;
        if (*(int *)(iVar7 + 4) == 0) {
          iVar7 = 0;
        }
        else {
          iVar7 = *(int *)(iVar7 + 4) + -4;
        }
      }
    } while (iVar9 != iVar4);
    if (local_8 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x4ba100 FUN_004ba100

void FUN_004ba100(int param_1)

{
  byte *pbVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined *puVar8;
  int iVar9;
  int *piVar10;
  char *pcVar11;
  int local_8;
  int local_4;
  
  FUN_004f85b0();
  local_8 = 0;
  if (0 < DAT_0073616c) {
    local_4 = 0;
    do {
      if (((DAT_00736168 == 0) || (local_4 < 0)) || (DAT_0073616c <= local_8)) {
        iVar9 = 0;
      }
      else {
        iVar9 = local_4 + DAT_00736168;
      }
      sVar2 = *(short *)(iVar9 + 0x6c);
      iVar9 = cFrontendDatabase__IsTrackAvailableForRaceType(&DAT_00748f70);
      if ((iVar9 != 0) && ((DAT_0073494c == 0 || (sVar2 != 1099)))) {
        Screen_MU_QuickRaceTrackSelect__AddTrack();
      }
      local_8 = local_8 + 1;
      local_4 = local_4 + 0xfc;
    } while (local_8 < DAT_0073616c);
  }
  local_4 = 0;
  if (0 < DAT_0073616c) {
    local_8 = 0;
    do {
      if (((DAT_00736168 == 0) || (local_8 < 0)) || (DAT_0073616c <= local_4)) {
        iVar9 = 0;
      }
      else {
        iVar9 = local_8 + DAT_00736168;
      }
      sVar2 = *(short *)(iVar9 + 0x6c);
      iVar3 = cFrontendDatabase__IsTrackAvailableForRaceType(&DAT_00748f70);
      if (((iVar3 != 0) && ((*(uint *)(iVar9 + 0x74) & 8) == 0)) &&
         ((DAT_0073494c == 0 || ((sVar2 != 1099 && ((*(uint *)(iVar9 + 0x74) & 6) == 0)))))) {
        Screen_MU_QuickRaceTrackSelect__AddTrack();
      }
      local_4 = local_4 + 1;
      local_8 = local_8 + 0xfc;
    } while (local_4 < DAT_0073616c);
  }
  piVar10 = (int *)(param_1 + 0x40);
  Screen_MU_QuickRaceTrackSelect__SortTracks(piVar10);
  if (*piVar10 == 0) {
    iVar9 = 0;
  }
  else {
    iVar9 = *piVar10 + -4;
  }
  while( true ) {
    if (piVar10 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = param_1 + 0x3c;
    }
    if (iVar9 == iVar3) break;
    if (*(int *)(iVar9 + 0x18) == 0) {
      sVar2 = *(short *)(*(int *)(iVar9 + 0xc) + 0x6c);
      pcVar11 = "TRACK_IMAGE_%d";
    }
    else {
      sVar2 = *(short *)(*(int *)(iVar9 + 0xc) + 0x6c);
      pcVar11 = "REVERSE_TRACK_IMAGE_%d";
    }
    uVar4 = FUN_004f42f0(pcVar11,(int)sVar2);
    iVar3 = FUN_004f8730(param_1 + 0x4c,uVar4,0,1);
    if (*(int *)(iVar9 + 0x18) == 0) {
      sVar2 = *(short *)(*(int *)(iVar9 + 0xc) + 0x6c);
      pcVar11 = "TRACK_%d_ICON";
    }
    else {
      sVar2 = *(short *)(*(int *)(iVar9 + 0xc) + 0x6c);
      pcVar11 = "REVERSE_TRACK_%d_ICON";
    }
    iVar5 = FUN_004f42f0(pcVar11,(int)sVar2);
    iVar6 = Texture_FindByHash(iVar5,0,0);
    if (iVar6 == 0) {
      pcVar11 = "GENERICPLACEHOLDER";
      iVar5 = -1;
      uVar7 = 0x47;
      do {
        iVar5 = iVar5 * 0x21 + uVar7;
        pbVar1 = (byte *)(pcVar11 + 1);
        uVar7 = (uint)*pbVar1;
        pcVar11 = pcVar11 + 1;
      } while (*pbVar1 != 0);
    }
    if ((iVar3 != 0) && (*(int *)(iVar3 + 0x24) != iVar5)) {
      *(int *)(iVar3 + 0x24) = iVar5;
      *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | 0x400000;
    }
    if (*(int *)(iVar9 + 4) == 0) {
      iVar9 = 0;
    }
    else {
      iVar9 = *(int *)(iVar9 + 4) + -4;
    }
  }
  puVar8 = (undefined *)0x0;
  switch(DAT_00777cc8) {
  case 0:
    puVar8 = &DAT_00758980;
    break;
  case 1:
    puVar8 = &DAT_007589a0;
    break;
  case 2:
    puVar8 = &DAT_007589c0;
    break;
  case 3:
    puVar8 = &DAT_007589e0;
    break;
  case 4:
    puVar8 = &DAT_00758a04;
    break;
  case 5:
    puVar8 = &DAT_00758a88;
    break;
  case 6:
    puVar8 = &DAT_00758ab4;
  }
  if (*(int *)(puVar8 + 8) == -1) {
    iVar9 = *piVar10;
    if (iVar9 == 0) goto LAB_004ba3bc;
    iVar3 = iVar9 + -4;
    while( true ) {
      if (piVar10 == (int *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = param_1 + 0x3c;
      }
      if (iVar3 == iVar5) break;
      if (*(char *)(iVar3 + 0x10) == '\0') goto LAB_004ba3e4;
      if (*(int *)(iVar3 + 4) == 0) {
LAB_004ba3bc:
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(iVar3 + 4) + -4;
      }
    }
    iVar3 = 0;
LAB_004ba3e4:
    *(int *)(param_1 + 0x48) = iVar3;
    if (iVar3 == 0) {
      if (iVar9 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = iVar9 + -4;
      }
      *(int *)(param_1 + 0x48) = iVar9;
    }
    *(int *)(puVar8 + 8) = (int)*(short *)(*(int *)(*(int *)(param_1 + 0x48) + 0xc) + 0x6c);
    *(undefined4 *)(puVar8 + 0xc) = 0;
  }
  else {
    iVar9 = *piVar10;
    if (iVar9 == 0) goto LAB_004ba425;
    iVar3 = iVar9 + -4;
    while( true ) {
      if (piVar10 == (int *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = param_1 + 0x3c;
      }
      if (iVar3 == iVar5) break;
      if (((int)*(short *)(*(int *)(iVar3 + 0xc) + 0x6c) == *(int *)(puVar8 + 8)) &&
         (*(int *)(iVar3 + 0x18) == *(int *)(puVar8 + 0xc))) goto LAB_004ba454;
      if (*(int *)(iVar3 + 4) == 0) {
LAB_004ba425:
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(iVar3 + 4) + -4;
      }
    }
    iVar3 = 0;
LAB_004ba454:
    *(int *)(param_1 + 0x48) = iVar3;
    if (iVar3 == 0) {
      if (iVar9 == 0) goto LAB_004ba468;
      iVar3 = iVar9 + -4;
      while( true ) {
        if (piVar10 == (int *)0x0) {
          iVar5 = 0;
        }
        else {
          iVar5 = param_1 + 0x3c;
        }
        if (iVar3 == iVar5) break;
        if (*(char *)(iVar3 + 0x10) == '\0') goto LAB_004ba494;
        if (*(int *)(iVar3 + 4) == 0) {
LAB_004ba468:
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(iVar3 + 4) + -4;
        }
      }
      iVar3 = 0;
LAB_004ba494:
      *(int *)(param_1 + 0x48) = iVar3;
      if (iVar3 == 0) {
        if (iVar9 == 0) {
          iVar9 = 0;
        }
        else {
          iVar9 = iVar9 + -4;
        }
        *(int *)(param_1 + 0x48) = iVar9;
      }
    }
  }
  iVar9 = *(int *)(param_1 + 0x48);
  if (*(int *)(iVar9 + 0x18) == 0) {
    sVar2 = *(short *)(*(int *)(iVar9 + 0xc) + 0x6c);
    pcVar11 = "TRACK_IMAGE_%d";
  }
  else {
    sVar2 = *(short *)(*(int *)(iVar9 + 0xc) + 0x6c);
    pcVar11 = "REVERSE_TRACK_IMAGE_%d";
  }
  FUN_004f42f0(pcVar11,(int)sVar2);
  FUN_004f8960();
  if (DAT_00777cc8 != 4) {
    return;
  }
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x48);
  FUN_004b99c0();
  return;
}


// ==== 0x4ba530 FUN_004ba530

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ba530(int param_1)

{
  char *pcVar1;
  float fVar2;
  short sVar3;
  float *pfVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  undefined8 uVar13;
  char local_9c [8];
  char local_94 [8];
  char local_8c [32];
  undefined4 local_6c;
  undefined1 local_40;
  undefined4 local_3f;
  
  FUN_004bbc90();
  uVar6 = FUN_004ad6d0(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x18));
  FUN_00495f00(uVar6);
  if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x48) + 0xc) + 0x74) & 4) == 0) {
    iVar7 = 0;
    do {
      iVar7 = iVar7 + 1;
      bSPrintf_regdst(0x20,"Sprint_BG_%d",iVar7);
      puVar9 = &local_6c;
      cVar5 = (char)local_6c;
      while (cVar5 != '\0') {
        pcVar10 = (char *)((int)puVar9 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        cVar5 = *pcVar10;
      }
      if ((((*(int *)(param_1 + 0xc) == 0) || (iVar8 = FEngFindPackage(), iVar8 == 0)) ||
          (iVar8 = FUN_004ffb70(), iVar8 == 0)) && (DAT_0073578c != 0)) {
        FUN_004ef050();
      }
      FEObject__SetInvisible();
    } while (iVar7 < 5);
    pcVar10 = "TrackLength";
    do {
      pcVar1 = pcVar10 + 1;
      pcVar10 = pcVar10 + 1;
    } while (*pcVar1 != '\0');
    if ((((*(int *)(param_1 + 0xc) == 0) || (iVar7 = FEngFindPackage(), iVar7 == 0)) ||
        (iVar7 = FUN_004ffb70(), iVar7 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050();
    }
    FEObject__SetInvisible();
  }
  else {
    iVar7 = 0;
    do {
      iVar7 = iVar7 + 1;
      bSPrintf_regdst(0x20,"Sprint_BG_%d",iVar7);
      puVar9 = &local_6c;
      cVar5 = (char)local_6c;
      while (cVar5 != '\0') {
        pcVar10 = (char *)((int)puVar9 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        cVar5 = *pcVar10;
      }
      if (((((*(int *)(param_1 + 0xc) != 0) && (iVar8 = FEngFindPackage(), iVar8 != 0)) &&
           (iVar8 = FUN_004ffb70(), iVar8 != 0)) ||
          ((DAT_0073578c != 0 && (iVar8 = FUN_004ef050(), iVar8 != 0)))) &&
         ((*(uint *)(iVar8 + 0x1c) = *(uint *)(iVar8 + 0x1c) & 0xfffffffe | 0x400000,
          *(int *)(iVar8 + 0x18) == 5 && (iVar8 = *(int *)(iVar8 + 0x5c), 0 < iVar8)))) {
        do {
          FEObject__SetVisible();
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
    } while (iVar7 < 5);
    pcVar10 = "TrackLength";
    do {
      pcVar1 = pcVar10 + 1;
      pcVar10 = pcVar10 + 1;
    } while (*pcVar1 != '\0');
    if (((((*(int *)(param_1 + 0xc) != 0) && (iVar7 = FEngFindPackage(), iVar7 != 0)) &&
         (iVar7 = FUN_004ffb70(), iVar7 != 0)) ||
        ((DAT_0073578c != 0 && (iVar7 = FUN_004ef050(), iVar7 != 0)))) &&
       ((*(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) & 0xfffffffe | 0x400000,
        *(int *)(iVar7 + 0x18) == 5 && (iVar7 = *(int *)(iVar7 + 0x5c), 0 < iVar7)))) {
      do {
        FEObject__SetVisible();
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    if (DAT_007588f0 == 1) {
      iVar7 = LanguageStrings__FindByHash();
      if (iVar7 == 0) {
        iVar7 = LanguageStrings__FindByHash();
      }
      iVar8 = 8;
      pcVar10 = local_9c;
      do {
        cVar5 = pcVar10[iVar7 - (int)local_9c];
        iVar8 = iVar8 + -1;
        *pcVar10 = cVar5;
        if (cVar5 == '\0') break;
        pcVar10 = pcVar10 + 1;
      } while (iVar8 != 0);
      iVar7 = *(int *)(*(int *)(param_1 + 0x48) + 0xc);
      fVar2 = (float)*(int *)(iVar7 + 0x78);
      if (*(int *)(iVar7 + 0x78) < 0) {
        fVar2 = fVar2 + 4.2949673e+09;
      }
      fVar2 = fVar2 * 0.001;
    }
    else {
      iVar7 = LanguageStrings__FindByHash();
      if (iVar7 == 0) {
        iVar7 = LanguageStrings__FindByHash();
      }
      iVar8 = 8;
      pcVar10 = local_9c;
      do {
        cVar5 = pcVar10[iVar7 - (int)local_9c];
        iVar8 = iVar8 + -1;
        *pcVar10 = cVar5;
        if (cVar5 == '\0') break;
        pcVar10 = pcVar10 + 1;
      } while (iVar8 != 0);
      iVar7 = *(int *)(*(int *)(param_1 + 0x48) + 0xc);
      fVar2 = (float)*(int *)(iVar7 + 0x78);
      if (*(int *)(iVar7 + 0x78) < 0) {
        fVar2 = fVar2 + 4.2949673e+09;
      }
      fVar2 = fVar2 * 0.000625;
    }
    bSPrintf_regdst(8,"%3.1f",(double)fVar2);
    pcVar10 = local_94;
    if ((DAT_006ee6f0 != 0) && (DAT_006ee6f0 != 7)) {
      while (local_94[0] != '\0') {
        if (*pcVar10 == '.') {
          *pcVar10 = ',';
        }
        pcVar1 = pcVar10 + 1;
        pcVar10 = pcVar10 + 1;
        local_94[0] = *pcVar1;
      }
    }
    iVar7 = LanguageStrings__FindByHash();
    if (iVar7 == 0) {
      iVar7 = LanguageStrings__FindByHash();
    }
    FEngPrintf("%s %s %s",iVar7,local_94,local_9c);
  }
  iVar7 = *(int *)(param_1 + 0x48);
  if (*(int *)(iVar7 + 0x18) == 0) {
    uVar13 = CONCAT44((int)*(short *)(*(int *)(iVar7 + 0xc) + 0x6c),"TRACK_IMAGE_%d");
  }
  else {
    uVar13 = CONCAT44((int)*(short *)(*(int *)(iVar7 + 0xc) + 0x6c),"REVERSE_TRACK_IMAGE_%d");
  }
  iVar7 = FUN_004f42f0(uVar13);
  for (puVar9 = *(undefined4 **)(param_1 + 0x50); puVar9 != (undefined4 *)(param_1 + 0x50);
      puVar9 = (undefined4 *)*puVar9) {
    if (iVar7 == puVar9[2]) {
      if (puVar9 != *(undefined4 **)(param_1 + 0x58)) {
        *(undefined4 **)(param_1 + 0x58) = puVar9;
        fVar2 = (float)puVar9[4];
        pfVar4 = *(float **)(param_1 + 0x5c);
        pfVar4[2] = -fVar2;
        if (-fVar2 != *pfVar4) {
          *(undefined2 *)(pfVar4 + 0xb) = 2;
        }
      }
      FUN_004f87f0();
      _DAT_007460f8 = DAT_0073ad3c;
      break;
    }
  }
  pcVar10 = "Track_Reverse";
  if (*(int *)(*(int *)(param_1 + 0x48) + 0x18) == 1) {
    do {
      pcVar1 = pcVar10 + 1;
      pcVar10 = pcVar10 + 1;
    } while (*pcVar1 != '\0');
    if (((((*(int *)(param_1 + 0xc) != 0) && (iVar7 = FEngFindPackage(), iVar7 != 0)) &&
         (iVar7 = FUN_004ffb70(), iVar7 != 0)) ||
        ((DAT_0073578c != 0 && (iVar7 = FUN_004ef050(), iVar7 != 0)))) &&
       ((*(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) & 0xfffffffe | 0x400000,
        *(int *)(iVar7 + 0x18) == 5 && (iVar7 = *(int *)(iVar7 + 0x5c), 0 < iVar7)))) {
      do {
        FEObject__SetVisible();
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
  }
  else {
    do {
      pcVar1 = pcVar10 + 1;
      pcVar10 = pcVar10 + 1;
    } while (*pcVar1 != '\0');
    if ((((*(int *)(param_1 + 0xc) == 0) || (iVar7 = FEngFindPackage(), iVar7 == 0)) ||
        (iVar7 = FUN_004ffb70(), iVar7 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050();
    }
    FEObject__SetInvisible();
  }
  iVar7 = *(int *)(param_1 + 0x48);
  if (((DAT_00735e74 == 0) && (cVar5 = FUN_0059e510(), cVar5 == '\0')) &&
     (*(char *)(iVar7 + 0x10) != '\0')) {
    if (((((*(int *)(param_1 + 0xc) != 0) && (iVar7 = FEngFindPackage(), iVar7 != 0)) &&
         (iVar7 = FUN_004ffb70(), iVar7 != 0)) ||
        ((DAT_0073578c != 0 && (iVar7 = FUN_004ef050(), iVar7 != 0)))) &&
       ((*(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) & 0xfffffffe | 0x400000,
        *(int *)(iVar7 + 0x18) == 5 && (iVar7 = *(int *)(iVar7 + 0x5c), 0 < iVar7)))) {
      do {
        FEObject__SetVisible();
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
  }
  else {
    if ((((*(int *)(param_1 + 0xc) == 0) || (iVar7 = FEngFindPackage(), iVar7 == 0)) ||
        (iVar7 = FUN_004ffb70(), iVar7 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050();
    }
    FEObject__SetInvisible();
  }
  iVar7 = *(int *)(param_1 + 0x48);
  sVar3 = *(short *)(*(int *)(iVar7 + 0xc) + 0x6c);
  iVar8 = 0;
  do {
    iVar11 = 0;
    pcVar10 = (char *)((int)&DAT_007677b8 + 2);
    do {
      if (((*(short *)(pcVar10 + -2) == sVar3) && ((int)pcVar10[1] == *(int *)(iVar7 + 0x18))) &&
         (*pcVar10 == iVar8)) {
        puVar9 = &DAT_007677b8 + iVar11 * 2;
        goto LAB_004babce;
      }
      pcVar10 = pcVar10 + 8;
      iVar11 = iVar11 + 1;
    } while ((int)pcVar10 < 0x7681ba);
    puVar9 = (undefined4 *)0x0;
LAB_004babce:
    (&local_6c)[iVar8] = puVar9;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 0xb);
  iVar8 = 0;
  iVar11 = 0;
  do {
    if ((&local_6c)[iVar11] != 0) {
      iVar8 = (&local_6c)[iVar11];
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 < 0xb);
  local_40 = 0;
  puVar9 = &local_3f;
  for (iVar11 = 0xf; iVar11 != 0; iVar11 = iVar11 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  *(undefined2 *)puVar9 = 0;
  *(undefined1 *)((int)puVar9 + 2) = 0;
  if (iVar8 == 0) {
    iVar8 = *(int *)(iVar7 + 0xc);
    if ((*(byte *)(iVar8 + 0x74) & 8) == 0) {
      _ftol_nocw();
      goto LAB_004badca;
    }
    iVar11 = LanguageStrings__FindByHash();
    if (iVar11 == 0) {
      iVar11 = LanguageStrings__FindByHash();
    }
    iVar12 = 0x20;
    pcVar10 = local_8c;
    do {
      cVar5 = pcVar10[iVar11 - (int)local_8c];
      iVar12 = iVar12 + -1;
      *pcVar10 = cVar5;
      if (cVar5 == '\0') break;
      pcVar10 = pcVar10 + 1;
    } while (iVar12 != 0);
    if (*(int *)(iVar7 + 0x18) == 0) {
      iVar7 = LanguageStrings__FindByHash();
      if (iVar7 == 0) {
        iVar7 = LanguageStrings__FindByHash();
      }
      uVar6 = *(undefined4 *)(iVar8 + 0x84);
    }
    else {
      iVar7 = LanguageStrings__FindByHash();
      if (iVar7 == 0) {
        iVar7 = LanguageStrings__FindByHash();
      }
      uVar6 = *(undefined4 *)(iVar8 + 0x88);
    }
    bSPrintf_regdst(0x40,"%s %d (%d %s)",iVar7,uVar6,4,local_8c);
  }
  else if ((*(byte *)(*(int *)(iVar7 + 0xc) + 0x74) & 8) == 0) {
LAB_004badca:
    FUN_00586580();
    iVar7 = LanguageStrings__FindByHash();
    if (iVar7 == 0) {
      iVar7 = LanguageStrings__FindByHash();
    }
    bSPrintf_regdst(0x40,"%s %s",iVar7,&local_6c);
  }
  else {
    if (*(char *)(iVar8 + 2) == '\x01') {
      iVar7 = LanguageStrings__FindByHash();
      if (iVar7 == 0) {
        iVar7 = LanguageStrings__FindByHash();
      }
      iVar11 = 0x20;
      pcVar10 = local_8c;
      do {
        cVar5 = pcVar10[iVar7 - (int)local_8c];
        iVar11 = iVar11 + -1;
        *pcVar10 = cVar5;
        if (cVar5 == '\0') break;
        pcVar10 = pcVar10 + 1;
      } while (iVar11 != 0);
    }
    else {
      iVar7 = LanguageStrings__FindByHash();
      if (iVar7 == 0) {
        iVar7 = LanguageStrings__FindByHash();
      }
      iVar11 = 0x20;
      pcVar10 = local_8c;
      do {
        cVar5 = pcVar10[iVar7 - (int)local_8c];
        iVar11 = iVar11 + -1;
        *pcVar10 = cVar5;
        if (cVar5 == '\0') break;
        pcVar10 = pcVar10 + 1;
      } while (iVar11 != 0);
    }
    iVar7 = LanguageStrings__FindByHash();
    if (iVar7 == 0) {
      iVar7 = LanguageStrings__FindByHash();
    }
    bSPrintf_regdst(0x40,"%s %d (%d %s)",iVar7,*(undefined4 *)(iVar8 + 4),(int)*(char *)(iVar8 + 2),
                    local_8c);
  }
  iVar7 = *(int *)(param_1 + 0x48);
  if (((DAT_00735e74 == 0) && (cVar5 = FUN_0059e510(), cVar5 == '\0')) &&
     (*(char *)(iVar7 + 0x10) != '\0')) {
    iVar7 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) != 0) {
      iVar8 = FEPackageList__FindByName();
      iVar7 = DAT_0073578c;
      if ((iVar8 == 0) || (iVar8 = *(int *)(iVar8 + 0x18), iVar8 == 0)) {
        if (DAT_0073578c == 0) goto LAB_004baee4;
        if ((*(int *)(DAT_0073578c + 8) == 0) ||
           ((iVar8 = FUN_004fd1e0(), iVar8 == 0 && (iVar8 = FUN_004fd1e0(), iVar8 == 0))))
        goto LAB_004baeb9;
      }
      if ((iVar8 != 0) && (iVar8 = FUN_004ffb70(), iVar7 = DAT_0073578c, iVar8 != 0))
      goto LAB_004baee4;
    }
LAB_004baeb9:
    if (iVar7 != 0) {
      FUN_004ef050();
      FEObject__SetInvisible();
      return;
    }
LAB_004baee4:
    FEObject__SetInvisible();
    return;
  }
  iVar7 = DAT_0073578c;
  if (*(int *)(param_1 + 0xc) == 0) {
LAB_004baf6d:
    if ((iVar7 == 0) || (iVar8 = FUN_004ef050(), iVar8 == 0)) goto LAB_004bafb4;
  }
  else {
    iVar8 = FEPackageList__FindByName();
    iVar7 = DAT_0073578c;
    if ((iVar8 == 0) || (iVar8 = *(int *)(iVar8 + 0x18), iVar8 == 0)) {
      if (DAT_0073578c == 0) goto LAB_004bafb4;
      if ((*(int *)(DAT_0073578c + 8) == 0) ||
         ((iVar8 = FUN_004fd1e0(), iVar8 == 0 && (iVar8 = FUN_004fd1e0(), iVar8 == 0))))
      goto LAB_004baf6d;
    }
    if ((iVar8 == 0) || (iVar8 = FUN_004ffb70(), iVar7 = DAT_0073578c, iVar8 == 0))
    goto LAB_004baf6d;
  }
  *(uint *)(iVar8 + 0x1c) = *(uint *)(iVar8 + 0x1c) & 0xfffffffe | 0x400000;
  if ((*(int *)(iVar8 + 0x18) == 5) && (iVar7 = *(int *)(iVar8 + 0x5c), 0 < iVar7)) {
    do {
      FEObject__SetVisible();
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
LAB_004bafb4:
  FEngPrintf();
  return;
}


// ==== 0x4bafe0 FUN_004bafe0

void __fastcall FUN_004bafe0(undefined4 param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  
  iVar1 = *(int *)(in_EAX + 0x48);
  if (param_2 == -0x6edfbf62) {
    if (*(int *)(in_EAX + 0x40) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(in_EAX + 0x40) + -4;
    }
    if (iVar1 == iVar3) goto LAB_004bb037;
    if (*(int *)(iVar1 + 8) == 0) {
LAB_004bb032:
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar1 + 8) + -4;
    }
  }
  else {
    if (param_2 != -0x4a68e40f) goto LAB_004bb037;
    if (*(int *)(in_EAX + 0x44) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(in_EAX + 0x44) + -4;
    }
    if (iVar1 == iVar3) goto LAB_004bb037;
    if (*(int *)(iVar1 + 4) == 0) goto LAB_004bb032;
    iVar3 = *(int *)(iVar1 + 4) + -4;
  }
  *(int *)(in_EAX + 0x48) = iVar3;
LAB_004bb037:
  if (*(int *)(in_EAX + 0x48) != iVar1) {
    FUN_004f8340(*(undefined4 *)(in_EAX + 0xc));
    FUN_004bb0d0();
    iVar1 = *(int *)(in_EAX + 0x48);
    if (((DAT_00735e74 != 0) || (cVar2 = FUN_0059e510(*(undefined4 *)(iVar1 + 0x18)), cVar2 != '\0')
        ) || (*(char *)(iVar1 + 0x10) == '\0')) {
      iVar3 = RaceOptions_Get();
      *(int *)(iVar3 + 8) = (int)*(short *)(*(int *)(iVar1 + 0xc) + 0x6c);
      *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(*(int *)(in_EAX + 0x48) + 0x18);
    }
    FUN_004ba530(in_EAX);
  }
  return;
}


// ==== 0x4bb0d0 FUN_004bb0d0

void FUN_004bb0d0(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EDI;
  
  if (*(char *)(unaff_EDI + 0xa6) == '\0') {
    uVar1 = *(uint *)(unaff_EDI + 0xa8);
    iVar3 = *(int *)(unaff_EDI + 0xc);
    *(undefined1 *)(unaff_EDI + 0xa6) = 1;
    uVar2 = FEng__HashName();
    if ((((iVar3 == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
        (iVar3 = FUN_004ffb70(), iVar3 == 0)) && (DAT_0073578c != 0)) {
      FUN_004ef050(uVar2);
    }
    FUN_004f75b0(uVar1 >> 1);
    *(undefined4 *)(unaff_EDI + 0xac) = DAT_0073ad3c;
    return;
  }
  *(undefined4 *)(unaff_EDI + 0xac) = DAT_0073ad3c;
  return;
}


// ==== 0x4bb160 FUN_004bb160

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bb160(void)

{
  int unaff_ESI;
  
  if ((_K_HALF < (float)(DAT_0073ad3c - *(int *)(unaff_ESI + 0xac)) * 0.00025) &&
     (*(char *)(unaff_ESI + 0xa6) != '\0')) {
    *(undefined1 *)(unaff_ESI + 0xa6) = 0;
    FEng_FindObjectByHash2();
    FUN_004f75b0(*(undefined4 *)(unaff_ESI + 0xa8));
  }
  return;
}


// ==== 0x4bb1c0 FUN_004bb1c0

void __fastcall FUN_004bb1c0(int param_1)

{
  char cVar1;
  uint in_EAX;
  
  if (in_EAX < 0x78451235) {
    if (in_EAX == 0x78451234) {
      FUN_004b9750(param_1 + 0x88);
      *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x48);
      FUN_004b99c0(param_1 + 0x88);
      return;
    }
    if ((in_EAX != 0xc407210) && (in_EAX != 0x406415e3)) {
      return;
    }
    cVar1 = TournamentTrackList__IsFull();
    if (cVar1 != '\0') goto LAB_004bb244;
  }
  else {
    if (in_EAX == 0x911ab364) {
      if (DAT_00777cc8 != 4) {
        return;
      }
      cVar1 = TournamentTrackList__IsEmpty();
      if (cVar1 != '\0') {
        if (DAT_00777b4c != 4) {
          FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
          return;
        }
        FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      FUN_004b9750(param_1 + 0x88);
      return;
    }
    if (in_EAX != 0xaa3f4777) {
      return;
    }
  }
  FUN_004b9500(param_1 + 0x88,DAT_00758a14);
  cVar1 = TournamentTrackList__IsFull();
  if (cVar1 == '\0') {
    return;
  }
LAB_004bb244:
  *(undefined1 *)(param_1 + 0xa5) = 1;
  return;
}


// ==== 0x4bb2b0 FUN_004bb2b0

void __thiscall FUN_004bb2b0(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uStack_38;
  int aiStack_34 [12];
  undefined1 uStack_4;
  
  if (*(char *)(param_1 + 0xa5) == '\0') {
    if (param_2 < 0x9120409f) {
      if (param_2 != 0x9120409e) {
        if (param_2 < 0x7e9d0308) {
          if (param_2 == 0x7e9d0307) {
            if (DAT_00777cc8 == 4) {
              TournamentTrackList__CopyToRaceSetup();
            }
            QuickRace__StartRaceByMode();
            return;
          }
          if (param_2 == 0xc407210) {
            cVar1 = FUN_004b9fa0(param_1);
            if (cVar1 != '\0') {
              return;
            }
            if (DAT_00777cc8 != 4) {
              FEngQueuePackagePush(0xff);
              return;
            }
            FUN_004bb1c0(param_4);
            return;
          }
          if (param_2 != 0x78451234) {
            return;
          }
LAB_004bb36d:
          if (DAT_00777cc8 != 4) {
            return;
          }
          FUN_004bb1c0(1);
          return;
        }
        if (param_2 != 0x828bb152) {
          if (param_2 != 0x911ab364) {
            return;
          }
          if (DAT_00777cc8 != 4) {
            if (DAT_00777b4c != 4) {
              FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
              return;
            }
            FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
            return;
          }
          FUN_004bb1c0(param_4);
          return;
        }
        FUN_004b94c0();
        FUN_004b99c0(param_1 + 0x88);
      }
    }
    else {
      if (0xc519bfc3 < param_2) {
        if (param_2 != 0xc98356ba) {
          return;
        }
        goto LAB_004bb568;
      }
      if (param_2 == 0xc519bfc3) {
        piVar3 = aiStack_34;
        for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar3 = 0;
          piVar3 = piVar3 + 1;
        }
        aiStack_34[0] = ((DAT_00777cc8 == 4) - 1 & 0x379243f5) + 0xc2dbce3c;
        uStack_4 = 0;
        aiStack_34[8] = 1;
        uStack_38 = 0x169268;
        aiStack_34[10] = 0;
        aiStack_34[0xb] = 0;
        aiStack_34[9] = 0x639;
        InfoDialog__OpenModalDialog(&uStack_38,*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 == 0xaa3f4777) goto LAB_004bb36d;
      if (param_2 != 0xb5971bf1) {
        return;
      }
    }
    FUN_004bafe0();
    if (DAT_00777cc8 == 4) {
      *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x48);
      FUN_004b99c0(param_1 + 0x88);
      return;
    }
  }
  else {
    if (param_2 != 0xc98356ba) {
      return;
    }
    aiStack_34[3] = 0x78451234;
    aiStack_34[4] = 0x78451234;
    *(undefined1 *)(param_1 + 0xa5) = 0;
    aiStack_34[6] = 0;
    aiStack_34[7] = 0;
    uStack_38 = 0xc95eec85;
    aiStack_34[1] = 0x7e9d0307;
    aiStack_34[0] = 0x639;
    aiStack_34[2] = 0x541389e5;
    aiStack_34[5] = 0xb8a7c6cd;
    FUN_004dc6e0(&uStack_38,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
LAB_004bb568:
    FEPackageList__FindByName(&DAT_00746104);
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar2 == 0) || (*(int *)(iVar2 + 0x18) == 0)) {
      FEManager__PushPackageChecked(0x32,0);
    }
    FUN_004f89d0();
    FUN_004f7d30();
    FUN_004bb160();
  }
  return;
}


// ==== 0x4bb5c0 FUN_004bb5c0

void FUN_004bb5c0(void)

{
  FUN_004bb980();
  return;
}


// ==== 0x4bb5d0 Screen_MU_TrackMapScroller::Screen_MU_TrackMapScroller

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 *
Screen_MU_TrackMapScroller__Screen_MU_TrackMapScroller(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
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
  *param_1 = &PTR_FUN_006c5bc0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  *(undefined1 *)(param_1 + 0x12) = 0;
  param_1[0x15] = 0;
  if (((param_1[3] == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0xf4734a97);
    }
  }
  FEObject__SetInvisible(iVar2);
  if (((param_1[3] == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0x790c04e1);
    }
  }
  FEObject__SetInvisible(iVar2);
  if (((param_1[3] == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0x3b8ed302);
    }
  }
  FEObject__SetInvisible(iVar2);
  if (((param_1[3] == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0xa3989aac);
    }
  }
  FEObject__SetInvisible(iVar2);
  if (((param_1[3] == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) goto LAB_004bb7b3;
    iVar2 = FUN_004ef050(0x790c04e1);
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
LAB_004bb7b3:
  if (((param_1[3] == 0) || (iVar2 = FEngFindPackage(), iVar2 == 0)) ||
     (iVar2 = FUN_004ffb70(), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      ExceptionList = local_c;
      return param_1;
    }
    iVar2 = FUN_004ef050(0xa3989aac);
  }
  if (iVar2 != 0) {
    for (iVar1 = *(int *)(iVar2 + 0x4c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
      iVar3 = FEng__HashName();
      if (*(int *)(iVar1 + 0x30) == iVar3) {
        if (iVar1 == 0) {
          ExceptionList = local_c;
          return param_1;
        }
        if (iVar1 != *(int *)(iVar2 + 0x54)) {
          *(int *)(iVar2 + 0x54) = iVar1;
          FUN_004ff030(iVar2);
          *(undefined4 *)(*(int *)(iVar2 + 0x54) + 0x10) = 0;
        }
        *(undefined4 *)(iVar1 + 0x10) = 0;
        ExceptionList = local_c;
        return param_1;
      }
    }
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4bb850 FUN_004bb850

void * __thiscall FUN_004bb850(void *param_1,byte param_2)

{
  FUN_004bb870();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4bb870 FUN_004bb870

void __fastcall FUN_004bb870(undefined4 *param_1)

{
  int iVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = ExceptionList;
  pcStack_8 = FUN_006879f8;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_006c5bc0;
  iVar1 = param_1[0x15];
  local_4 = 0;
  while (iVar1 != 0) {
    AsyncReadQueue__Pump();
    iVar1 = param_1[0x15];
  }
  if (param_1[0x10] != 0) {
    FUN_00546060();
  }
  if (param_1[0x11] != 0) {
    FUN_00546060();
  }
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = local_c;
  return;
}


// ==== 0x4bb8f0 FUN_004bb8f0

void __thiscall FUN_004bb8f0(int param_1,int param_2)

{
  if (((param_2 == -0x367ca946) && (*(int *)(param_1 + 0x4c) != 0)) &&
     (*(int *)(param_1 + 0x50) != 0)) {
    if (*(char *)(param_1 + 0x48) != '\0') {
      FUN_00495fc0();
      FUN_00495f70();
      FUN_00495fc0();
      FUN_00495f70();
      return;
    }
    FUN_00495f70();
    FUN_00495fc0();
    FUN_00495f70();
    FUN_00495fc0();
  }
  return;
}


// ==== 0x4bb980 FUN_004bb980

void FUN_004bb980(void)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  *(int *)(unaff_EDI + 0x54) = *(int *)(unaff_EDI + 0x54) + -1;
  iVar1 = Texture_FindByHash(*(undefined4 *)(unaff_EDI + 0x44),0,0);
  iVar2 = Texture_FindByHash(*(undefined4 *)(unaff_EDI + 0x40),0,0);
  if (((iVar1 == 0) || (*(int *)(iVar1 + 0x70) == 0)) ||
     ((*(int *)(iVar1 + 0x3c) != 0 && (*(int *)(iVar1 + 0x74) == 0)))) {
    *(undefined4 *)(unaff_EDI + 0x50) = 0;
  }
  else {
    *(undefined4 *)(unaff_EDI + 0x50) = 1;
  }
  if (((iVar2 == 0) || (*(int *)(iVar2 + 0x70) == 0)) ||
     ((*(int *)(iVar2 + 0x3c) != 0 && (*(int *)(iVar2 + 0x74) == 0)))) {
    *(undefined4 *)(unaff_EDI + 0x4c) = 0;
  }
  else {
    *(undefined4 *)(unaff_EDI + 0x4c) = 1;
  }
  if ((*(int *)(unaff_EDI + 0x4c) != 0) && (*(int *)(unaff_EDI + 0x50) != 0)) {
    FUN_004f6c30("PULSE",1);
    FUN_004f6c30("PULSE",1);
  }
  return;
}


// ==== 0x4bba40 FUN_004bba40

void FUN_004bba40(undefined4 param_1,undefined4 param_2)

{
  undefined1 in_AL;
  int iVar1;
  int unaff_EBX;
  
  *(undefined1 *)(unaff_EBX + 0x48) = in_AL;
  if (*(int *)(unaff_EBX + 0xc) == 0) {
LAB_004bba66:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xf4734a97);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_004bba66;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004bba66;
  }
  FEObject__SetInvisible(iVar1);
  if (*(int *)(unaff_EBX + 0xc) == 0) {
LAB_004bbaad:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x3b8ed302);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_004bbaad;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004bbaad;
  }
  FEObject__SetInvisible(iVar1);
  if (*(int *)(unaff_EBX + 0xc) == 0) {
LAB_004bbaf4:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x790c04e1);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_004bbaf4;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_004bbaf4;
  }
  FEObject__SetInvisible(iVar1);
  if (*(int *)(unaff_EBX + 0xc) != 0) {
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_004bbb57;
    }
  }
  if (DAT_0073578c == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004ef050(0xa3989aac);
  }
LAB_004bbb57:
  FEObject__SetInvisible(iVar1);
  FUN_004ad7b0(param_1);
  FUN_004ad7b0(param_1);
  FUN_004ad7b0(param_2);
  FUN_004ad7b0(param_2);
  *(undefined4 *)(unaff_EBX + 0x4c) = 0;
  *(undefined4 *)(unaff_EBX + 0x50) = 0;
  if (*(int *)(unaff_EBX + 0x40) != 0) {
    FUN_00546060();
  }
  if (*(int *)(unaff_EBX + 0x44) != 0) {
    FUN_00546060();
  }
  *(undefined4 *)(unaff_EBX + 0x44) = param_2;
  *(undefined4 *)(unaff_EBX + 0x40) = param_1;
  *(int *)(unaff_EBX + 0x54) = *(int *)(unaff_EBX + 0x54) + 1;
  FUN_0053e9e0(&DAT_00740420,&param_2,1,FUN_004bb5c0,unaff_EBX,0);
  *(int *)(unaff_EBX + 0x54) = *(int *)(unaff_EBX + 0x54) + 1;
  param_2 = *(undefined4 *)(unaff_EBX + 0x40);
  FUN_0053e9e0(&DAT_00740420,&param_2,1,FUN_004bb5c0,unaff_EBX,0);
  return;
}


// ==== 0x4bbc30 Screen_MU_TrackMapScroller::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_TrackMapScroller__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687cd3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x58);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_TrackMapScroller__Screen_MU_TrackMapScroller(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4bbc90 FUN_004bbc90

void __fastcall FUN_004bbc90(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006882e8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x14) != 0)) &&
     (iVar2 = 0, iVar1 = DAT_00736168, 0 < DAT_0073616c)) {
    while (*(short *)(iVar1 + 0x6c) != param_1) {
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0xfc;
      if (DAT_0073616c <= iVar2) {
        ExceptionList = local_c;
        return;
      }
    }
    local_4 = 0;
    uVar3 = FUN_004b92a0();
    uVar4 = FUN_004f42f0("TRACK_%d_SPLINE",(int)*(short *)(iVar1 + 0x6c));
    FUN_004bba40(uVar3,uVar4);
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x4bbd70 CarPart::GetNameAttribute

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

int __fastcall CarPart__GetNameAttribute(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x14);
  piVar1 = piVar2 + *(short *)(param_1 + 0x1c) * 2;
  if (piVar2 != (int *)0x0) {
    for (; piVar2 < piVar1; piVar2 = piVar2 + 2) {
      if (*piVar2 == 0x10c98090) {
        if (piVar2 == (int *)0x0) {
          return 0;
        }
        return piVar2[1];
      }
    }
  }
  return 0;
}


// ==== 0x4bbda0 Screen_MU_QuickRaceCarSelect::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_QuickRaceCarSelect__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00689243;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0xa8);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_QuickRaceCarSelect__Screen_MU_QuickRaceCarSelect(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4bbe00 Screen_MU_QuickRaceCarSelect::Screen_MU_QuickRaceCarSelect

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 *
Screen_MU_QuickRaceCarSelect__Screen_MU_QuickRaceCarSelect(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0068921e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FEScreen__FEScreen(param_1,param_2);
  puVar1 = param_1 + 0x10;
  *param_1 = &PTR_FUN_006c5b60;
  *puVar1 = puVar1;
  param_1[0x11] = puVar1;
  local_4._0_1_ = 1;
  local_4._1_3_ = 0;
  FUN_004f8370(param_1 + 0x14,"car_thumb3","car_thumb");
  iVar3 = DAT_0073578c;
  bVar4 = DAT_0073578c != 0;
  param_1[0x24] = 0;
  local_4 = CONCAT31(local_4._1_3_,2);
  param_1[0x24] = 0;
  if (bVar4) {
    iVar2 = *(int *)(iVar3 + 8);
    iVar3 = iVar2 + 0xdc;
    if (iVar3 != 0) {
      iVar3 = FUN_004fd1e0(iVar3);
      if (iVar3 != 0) goto LAB_004bbea4;
    }
    cFEng__PushPackage(iVar2,"MU_HorizontalBrowserBack.fng",0x11,0);
  }
LAB_004bbea4:
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0x1c2d8258,0,0,*(int *)(iVar3 + 0x18));
  }
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0x50fe8c15,0,0,*(int *)(iVar3 + 0x18));
  }
  FUN_004bc170(param_1);
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar3 == 0) || (*(int *)(iVar3 + 0x18) == 0)) && (DAT_00777b4c != 4)) {
    FEngPushGarageMainPackage();
  }
  DAT_00748f70 = 1;
  GetCarManufacturerNameHash();
  if (DAT_00777b4c == 4) {
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0))
    {
      (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0x18883f75,0,0,*(int *)(iVar3 + 0x18));
    }
  }
  else {
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0))
    {
      (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0x18883f75,0,0,*(int *)(iVar3 + 0x18));
    }
  }
  FUN_004b2480();
  *(undefined1 *)(param_1 + 8) = 1;
  *(undefined1 *)(param_1 + 0x25) = 0;
  *(undefined1 *)((int)param_1 + 0x95) = 0;
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0x6c6603df,0,0,*(int *)(iVar3 + 0x18));
  }
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) && (*(int **)(iVar3 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar3 + 0x14) + 8))(0x56aa7e46,0,0,*(int *)(iVar3 + 0x18));
  }
  if (DAT_00777b4c == 8) {
    FUN_00495f00(0xfec88958);
    param_1[0x28] = 0x6c40847c;
  }
  else {
    FUN_00495f00(0x5aca5feb);
    param_1[0x28] = 0x4a9c06b2;
  }
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar3 != 0) && (*(int *)(iVar3 + 0x14) != 0)) {
    FUN_004f8000(param_1);
    FUN_004e6ac0();
  }
  *(undefined1 *)(param_1 + 0x29) = 0;
  ExceptionList = pvStack_c;
  return param_1;
}


// ==== 0x4bc0a0 FUN_004bc0a0

void * __thiscall FUN_004bc0a0(void *param_1,byte param_2)

{
  FUN_004bc0c0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4bc0c0 FUN_004bc0c0

void __fastcall FUN_004bc0c0(undefined4 *param_1)

{
  int *_Memory;
  int *piVar1;
  int iVar2;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00688cee;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c5b60;
  local_4 = 2;
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (*(int **)(iVar2 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar2 + 0x14) + 8))(0x645e01df,0,0,*(int *)(iVar2 + 0x18));
  }
  FUN_004f84d0();
  _Memory = (int *)param_1[0x10];
  while (_Memory != param_1 + 0x10) {
    iVar2 = *_Memory;
    piVar1 = (int *)_Memory[1];
    *piVar1 = iVar2;
    *(int **)(iVar2 + 4) = piVar1;
    _free(_Memory);
    _Memory = (int *)param_1[0x10];
  }
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x4bc170 FUN_004bc170

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bc170(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  bool bVar5;
  char cVar6;
  undefined *puVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  byte *pbVar12;
  int *piVar13;
  char *pcVar14;
  int iVar15;
  undefined4 *puVar16;
  float10 fVar17;
  int local_10;
  undefined *local_c;
  int *local_8;
  
  local_10 = 0;
  if (0 < DAT_0075ee00) {
    local_c = &DAT_0075ac60;
    do {
      if (((int)local_c < 0x75ac60) || (puVar7 = local_c, 0x75edff < (int)local_c)) {
        puVar7 = (undefined *)0x0;
      }
      iVar8 = 0;
      piVar10 = (int *)(DAT_00734588 + 0xd0);
      do {
        if (*piVar10 == *(int *)(puVar7 + 8)) {
          iVar8 = iVar8 * 0xc90 + DAT_00734588;
          goto LAB_004bc1d2;
        }
        iVar8 = iVar8 + 1;
        piVar10 = piVar10 + 0x324;
      } while (iVar8 < 0x23);
      iVar8 = 0;
LAB_004bc1d2:
      iVar8 = *(int *)(iVar8 + 0xc50) * 0xc90 + DAT_00734588;
      if (iVar8 != 0) {
        _DAT_00735e70 = 0;
        if (*(short *)(iVar8 + 0xc58) != 0) {
          uVar9 = 0;
          if (DAT_0073766c != 0) {
            piVar10 = (int *)(DAT_00737668 + 0x24);
            do {
              if ((piVar10[-1] == 0) && (*piVar10 == *(int *)(iVar8 + 0xc50))) {
                if (*(char *)(uVar9 * 0x34 + 0x30 + DAT_00737668) != '\0') goto LAB_004bc254;
                break;
              }
              uVar9 = uVar9 + 1;
              piVar10 = piVar10 + 0xd;
            } while (uVar9 < DAT_0073766c);
          }
          cVar6 = Career__IsCarUnlocked();
          if (cVar6 == '\0') goto LAB_004bc2bf;
        }
LAB_004bc254:
        piVar10 = _malloc(0x740);
        if (piVar10 == (int *)0x0) {
          piVar10 = (int *)0x0;
        }
        else {
          iVar15 = *(int *)(puVar7 + 0x344);
          iVar3 = *(int *)(puVar7 + 0x338);
          RideInfo__Init();
          piVar10[0x1cc] = iVar8;
          piVar10[0x1cd] = iVar3;
          piVar10[0x1ce] = iVar15;
        }
        FECarConfig__BuildRide(puVar7,0,piVar10 + 4);
        puVar4 = *(undefined4 **)(param_1 + 0x44);
        *puVar4 = piVar10;
        *(int **)(param_1 + 0x44) = piVar10;
        piVar10[1] = (int)puVar4;
        *piVar10 = param_1 + 0x40;
      }
LAB_004bc2bf:
      local_10 = local_10 + 1;
      local_c = local_c + 0x348;
    } while (local_10 < DAT_0075ee00);
  }
  bList__Sort(param_1 + 0x40,FUN_004c2bc0);
  local_10 = 0;
  if (0 < DAT_0075eef4) {
    local_8 = &DAT_0075ee10;
    uVar9 = DAT_0073766c;
    do {
      iVar8 = *local_8;
      _DAT_00735e70 = 0;
      if (iVar8 < 1) {
        if ((local_8[-1] & DAT_00777b4c) != 0) {
LAB_004bc3a9:
          iVar8 = PresetRide__FindByKeyHash(local_8[-2]);
          if (iVar8 != 0) {
            pbVar12 = (byte *)(iVar8 + 8);
            iVar8 = -1;
            bVar2 = *pbVar12;
            while (bVar2 != 0) {
              iVar8 = iVar8 * 0x21 + (uint)bVar2;
              pbVar1 = pbVar12 + 1;
              pbVar12 = pbVar12 + 1;
              bVar2 = *pbVar1;
            }
            iVar15 = 0;
            piVar10 = (int *)(DAT_00734588 + 0xd0);
            do {
              if (*piVar10 == iVar8) {
                iVar8 = iVar15 * 0xc90 + DAT_00734588;
                goto LAB_004bc402;
              }
              iVar15 = iVar15 + 1;
              piVar10 = piVar10 + 0x324;
            } while (iVar15 < 0x23);
            iVar8 = 0;
LAB_004bc402:
            iVar8 = *(int *)(iVar8 + 0xc50);
            if (iVar8 != -1) {
              iVar15 = iVar8 * 0xc90 + DAT_00734588;
              piVar10 = _malloc(0x740);
              if (piVar10 == (int *)0x0) {
                piVar10 = (int *)0x0;
              }
              else {
                iVar3 = local_8[-3];
                fVar17 = (float10)GetStockPerformanceMeasure();
                RideInfo__Init();
                piVar10[0x1cc] = iVar15;
                piVar10[0x1cd] = (int)(float)fVar17;
                piVar10[0x1ce] = iVar3;
              }
              cFrontendDatabase__BuildRideForCarHandle(piVar10 + 4);
              FUN_004bc830(iVar8);
              piVar13 = (int *)(param_1 + 0x40);
              if (local_8[-1] == 8) {
                iVar8 = *piVar13;
                *piVar13 = (int)piVar10;
                *(int **)(iVar8 + 4) = piVar10;
                piVar10[1] = (int)piVar13;
                *piVar10 = iVar8;
                uVar9 = DAT_0073766c;
              }
              else {
                puVar4 = *(undefined4 **)(param_1 + 0x44);
                *puVar4 = piVar10;
                *(int **)(param_1 + 0x44) = piVar10;
                piVar10[1] = (int)puVar4;
                *piVar10 = (int)piVar13;
                uVar9 = DAT_0073766c;
              }
            }
          }
        }
      }
      else if ((local_8[-1] & DAT_00777b4c) != 0) {
        if ((iVar8 < 0) || (DAT_007343fc <= iVar8)) {
          iVar15 = 0;
        }
        else {
          iVar15 = iVar8 * 0x20 + DAT_007343f8;
        }
        if (*(char *)((int)&DAT_00758ad8 + iVar8) != '\0') goto LAB_004bc3a9;
        uVar11 = 0;
        if (uVar9 != 0) {
          piVar10 = (int *)(DAT_00737668 + 0x24);
          do {
            if ((piVar10[-1] == 6) && (*piVar10 == *(int *)(iVar15 + 8))) {
              if (*(char *)(uVar11 * 0x34 + 0x30 + DAT_00737668) != '\0') goto LAB_004bc3a9;
              break;
            }
            uVar11 = uVar11 + 1;
            piVar10 = piVar10 + 0xd;
          } while (uVar11 < uVar9);
        }
      }
      local_10 = local_10 + 1;
      local_8 = local_8 + 4;
    } while (local_10 < DAT_0075eef4);
  }
  if (DAT_0076027c != 0) {
    iVar8 = 0;
    piVar10 = (int *)(DAT_00734588 + 0xd0);
    do {
      if (*piVar10 == DAT_0075ef00) {
        iVar8 = iVar8 * 0xc90 + DAT_00734588;
        goto LAB_004bc522;
      }
      iVar8 = iVar8 + 1;
      piVar10 = piVar10 + 0x324;
    } while (iVar8 < 0x23);
    iVar8 = 0;
LAB_004bc522:
    iVar15 = *(int *)(iVar8 + 0xc50) * 0xc90 + DAT_00734588;
    piVar10 = _malloc(0x740);
    iVar8 = DAT_0075f23c;
    if (piVar10 == (int *)0x0) {
      piVar10 = (int *)0x0;
    }
    else {
      fVar17 = (float10)GetStockPerformanceMeasure();
      RideInfo__Init();
      piVar10[0x1cc] = iVar15;
      piVar10[0x1cd] = (int)(float)fVar17;
      piVar10[0x1ce] = iVar8;
    }
    FECarConfig__BuildRide(&DAT_0075eef8,0,piVar10 + 4);
    puVar4 = *(undefined4 **)(param_1 + 0x44);
    *puVar4 = piVar10;
    *(int **)(param_1 + 0x44) = piVar10;
    piVar10[1] = (int)puVar4;
    *piVar10 = param_1 + 0x40;
  }
  puVar16 = (undefined4 *)(param_1 + 0x40);
  for (puVar4 = *(undefined4 **)(param_1 + 0x40); puVar4 != puVar16; puVar4 = (undefined4 *)*puVar4)
  {
    iVar8 = *(int *)(puVar4[0x1cc] + 0xc50);
    if ((((iVar8 == 0x13) || (iVar8 == 0x11)) || (iVar8 == 0x12)) || (iVar8 == 0x10)) {
      bVar5 = true;
    }
    else {
      bVar5 = false;
    }
    iVar8 = FUN_004f8730(param_1 + 0x50,puVar4[0x1ce],0,!bVar5);
    iVar15 = *(int *)(puVar4[0x1cc] + 0xc50) * 0xc90 + DAT_00734588;
    pcVar14 = (char *)(iVar15 + 0xc0);
    if ((DAT_00734998 != 0) && (*(int *)(iVar15 + 0xc50) == 0xe)) {
      pcVar14 = "HONDA";
    }
    iVar15 = FUN_004f42f0("CARSELECT_MANUFACTURER_%s",pcVar14);
    if ((iVar8 != 0) && (*(int *)(iVar8 + 0x24) != iVar15)) {
      *(int *)(iVar8 + 0x24) = iVar15;
      *(uint *)(iVar8 + 0x1c) = *(uint *)(iVar8 + 0x1c) | 0x400000;
    }
  }
  iVar8 = DAT_00758c2c;
  if (DAT_00777b4c != 8) {
    iVar8 = DAT_00758c28;
  }
  puVar4 = (undefined4 *)*puVar16;
  *(undefined4 **)(param_1 + 0x48) = puVar4;
  for (; puVar4 != puVar16; puVar4 = (undefined4 *)*puVar4) {
    if (puVar4[0x1ce] == iVar8) {
      *(undefined4 **)(param_1 + 0x48) = puVar4;
    }
  }
  FUN_004bd0f0(0);
  iVar8 = *(int *)(*(int *)(param_1 + 0x48) + 0x738);
  iVar15 = iVar8;
  if (DAT_00777b4c == 8) {
    iVar15 = DAT_00758c28;
    DAT_00758c2c = iVar8;
  }
  DAT_00758c28 = iVar15;
  iVar8 = *(int *)(param_1 + 0x48);
  *(int *)(param_1 + 0x4c) = iVar8;
  iVar15 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar15 == 0) || (*(int *)(iVar15 + 0x18) == 0)) {
    iVar15 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar15 == 0) ||
       (((*(int *)(iVar15 + 0x18) == 0 ||
         (iVar15 = FEPackageList__FindByName(&DAT_00746104), iVar15 == 0)) ||
        (*(int *)(iVar15 + 0x14) == 0)))) {
      iVar15 = 0;
    }
    else {
      iVar15 = *(int *)(*(int *)(iVar15 + 0x14) + 0x40);
    }
  }
  else {
    iVar15 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar15 == 0) {
      iVar15 = 0;
    }
    else {
      iVar15 = *(int *)(iVar15 + 0x14);
    }
  }
  RideInfo__operator_(&DAT_00748850,iVar8 + 0x10);
  _DAT_0072cc80 = 1;
  if (iVar15 != 0) {
    GarageMainScreen__SetRideInfo(iVar15,&DAT_00748850,1);
  }
  FUN_004f8960();
  return;
}


// ==== 0x4bc790 FUN_004bc790

uint FUN_004bc790(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int unaff_EDI;
  
  puVar2 = DAT_0073ad40;
  puVar3 = (undefined4 *)NullUpdate_ret();
  for (; puVar2 != puVar3; puVar2 = (undefined4 *)*puVar2) {
    uVar7 = puVar2[3];
    uVar4 = puVar2[4] * 0x30 + uVar7;
    for (; uVar7 < uVar4; uVar7 = uVar7 + 0x30) {
      if (*(char *)(uVar7 + 0x10) == '\x1f') goto joined_r0x004bc7d8;
    }
  }
  uVar7 = 0;
joined_r0x004bc7d8:
  do {
    if (uVar7 == 0) {
      return 0;
    }
    piVar5 = *(int **)(uVar7 + 0x14);
    piVar1 = piVar5 + *(short *)(uVar7 + 0x1c) * 2;
    if (piVar5 != (int *)0x0) {
      for (; piVar5 < piVar1; piVar5 = piVar5 + 2) {
        if (*piVar5 == 0x10c98090) {
          if (piVar5 != (int *)0x0) {
            iVar6 = piVar5[1];
            goto LAB_004bc803;
          }
          break;
        }
      }
    }
    iVar6 = 0;
LAB_004bc803:
    if (iVar6 == unaff_EDI) {
      return uVar7;
    }
    uVar7 = CarPartDatabase__GetCarPart(0,0x1f,0,uVar7,0xffffffff);
  } while( true );
}


// ==== 0x4bc830 FUN_004bc830

void FUN_004bc830(int param_1)

{
  int in_EAX;
  int *piVar1;
  int local_d8 [54];
  
  piVar1 = local_d8;
  local_d8[0x34] = 8;
  local_d8[0x10] = 8;
  local_d8[0x22] = 8;
  local_d8[0x24] = 0;
  local_d8[0x25] = 2;
  local_d8[0x26] = 1;
  local_d8[0x27] = 2;
  local_d8[0x28] = 2;
  local_d8[0x29] = 2;
  local_d8[0x2a] = 3;
  local_d8[0x2b] = 2;
  local_d8[0x2c] = 4;
  local_d8[0x2d] = 2;
  local_d8[0x2e] = 5;
  local_d8[0x2f] = 2;
  local_d8[0x30] = 6;
  local_d8[0x31] = 2;
  local_d8[0x32] = 7;
  local_d8[0x33] = 2;
  local_d8[0x35] = 2;
  local_d8[0] = 0;
  local_d8[1] = 2;
  local_d8[2] = 1;
  local_d8[3] = 2;
  local_d8[4] = 2;
  local_d8[5] = 2;
  local_d8[6] = 3;
  local_d8[7] = 2;
  local_d8[8] = 4;
  local_d8[9] = 2;
  local_d8[10] = 5;
  local_d8[0xb] = 2;
  local_d8[0xc] = 6;
  local_d8[0xd] = 2;
  local_d8[0xe] = 7;
  local_d8[0xf] = 2;
  local_d8[0x11] = 2;
  local_d8[0x12] = 0;
  local_d8[0x13] = 2;
  local_d8[0x14] = 1;
  local_d8[0x15] = 2;
  local_d8[0x16] = 2;
  local_d8[0x17] = 2;
  local_d8[0x18] = 3;
  local_d8[0x19] = 2;
  local_d8[0x1a] = 4;
  local_d8[0x1b] = 2;
  local_d8[0x1c] = 5;
  local_d8[0x1d] = 2;
  local_d8[0x1e] = 6;
  local_d8[0x1f] = 2;
  local_d8[0x20] = 7;
  local_d8[0x21] = 2;
  local_d8[0x23] = 2;
  if (param_1 == 3) {
    piVar1 = local_d8 + 0x24;
  }
  else if (param_1 != 6) {
    if (param_1 != 8) {
      return;
    }
    piVar1 = local_d8 + 0x12;
  }
  *(int *)(in_EAX + 8 + *piVar1 * 4) = piVar1[1];
  *(int *)(in_EAX + 8 + piVar1[2] * 4) = piVar1[3];
  *(int *)(in_EAX + 8 + piVar1[4] * 4) = piVar1[5];
  *(int *)(in_EAX + 8 + piVar1[6] * 4) = piVar1[7];
  *(int *)(in_EAX + 8 + piVar1[8] * 4) = piVar1[9];
  *(int *)(in_EAX + 8 + piVar1[10] * 4) = piVar1[0xb];
  *(int *)(in_EAX + 8 + piVar1[0xc] * 4) = piVar1[0xd];
  *(int *)(in_EAX + 8 + piVar1[0xe] * 4) = piVar1[0xf];
  *(int *)(in_EAX + 8 + piVar1[0x10] * 4) = piVar1[0x11];
  RideInfo__RebuildPhysicsInfo(1);
  return;
}


// ==== 0x4bca40 Ride_BuildFromPartDatabase

/* [canon] car med (hopper+capstone) docs/re/misc.md */

void Ride_BuildFromPartDatabase(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *unaff_EDI;
  undefined1 local_730 [1092];
  int local_2ec;
  int local_2e8;
  int local_26c;
  char local_e6;
  
  iVar3 = unaff_EDI[0x112];
  iVar1 = unaff_EDI[0x111];
  iVar2 = *unaff_EDI;
  RideInfo__Init();
  Ride_Init(1,0,0);
  local_2ec = iVar1;
  local_2e8 = iVar3;
  FUN_0057d340(local_730);
  FUN_0057e9a0(local_730);
  iVar3 = CarPartDatabase__GetCarPart
                    (0,0x1e,*(undefined4 *)(iVar2 * 0xc90 + 0xc5c + DAT_00734588),0,0xffffffff);
  if (iVar3 != 0) {
    local_e6 = local_e6 + '\x01';
    local_26c = iVar3;
    RideInfo__UpdatePartsEnabled(local_730);
  }
  RideInfo__operator_(unaff_EDI,local_730);
  return;
}


// ==== 0x4bcb00 Screen_MU_QuickRaceCarSelect::MaskButtonFlags

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

uint __thiscall Screen_MU_QuickRaceCarSelect__MaskButtonFlags(int param_1,uint param_2)

{
  int *piVar1;
  
  piVar1 = &DAT_0075afa4;
  do {
    if (*(int *)(*(int *)(param_1 + 0x48) + 0x738) == *piVar1) {
      return param_2;
    }
    piVar1 = piVar1 + 0xd2;
  } while ((int)piVar1 < 0x75f144);
  return param_2 & 0xfffffffb;
}


// ==== 0x4bcb40 FUN_004bcb40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004bcb40(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  bool bVar4;
  undefined4 uStack_38;
  undefined4 auStack_34 [12];
  undefined1 uStack_4;
  
  if (0xa1c41aef < param_2) {
    if (param_2 < 0xc519bfc1) {
      if (param_2 == 0xc519bfc0) {
        cVar1 = Screen_MU_QuickRaceCarSelect__IsSelectedCarInGarage();
        if (cVar1 != '\0') {
          iVar2 = SpecialCamCooldown();
          if (iVar2 != 0) {
            FUN_004b23b0(*(int *)(param_1 + 0x48) + 0x10,1);
          }
          FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
          FUN_004bd0c0(param_1);
          return;
        }
      }
      else if ((param_2 != 0xaaccddbb) && (param_2 == 0xb5971bf1)) goto LAB_004bce42;
    }
    else if (param_2 == 0xc519bfc3) {
      puVar3 = auStack_34;
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
      auStack_34[0] = *(undefined4 *)(param_1 + 0xa0);
      uStack_4 = 0;
      auStack_34[8] = 1;
      uStack_38 = 0x169268;
      auStack_34[10] = 0;
      auStack_34[0xb] = 0;
      auStack_34[9] = 0x639;
      InfoDialog__OpenModalDialog(&uStack_38,*(undefined4 *)(param_1 + 0xc));
    }
    else {
      if (param_2 == 0xc98356ba) {
        FUN_004f89d0();
        iVar2 = *(int *)(param_1 + 0x90);
        if (((iVar2 != 0) && (iVar2 != 0x7fffffff)) &&
           (_DAT_006faf00 <= (float)(DAT_0073ad3c - iVar2) * 0.00025)) {
          FUN_004b23b0(*(int *)(param_1 + 0x48) + 0x10,1);
          *(undefined4 *)(param_1 + 0x90) = 0;
        }
        FUN_004f7d30();
        return;
      }
      if (param_2 == 0xed5a2448) {
        FUN_00416f00();
        _DAT_0075895c = 3;
        iVar2 = FEngFindPackage();
        bVar4 = iVar2 == 0;
        goto LAB_004bcede;
      }
    }
    return;
  }
  if (param_2 == 0xa1c41aef) {
    FUN_00416f00();
    return;
  }
  if (0x43211243 < param_2) {
    if (param_2 != 0x5f5e3886) {
      if (param_2 == 0x911ab364) {
        DAT_00748f74 = 0;
        if (DAT_00777b4c != 8) {
          FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
          return;
        }
        DAT_00758c2c = *(undefined4 *)(*(int *)(param_1 + 0x4c) + 0x738);
        FUN_004b23b0(*(int *)(param_1 + 0x4c) + 0x10,1);
        if (*(int *)(param_1 + 0x9c) < 3) {
          DAT_00748f74 = 1;
        }
        FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 != 0x9120409e) {
        return;
      }
LAB_004bce42:
      FUN_004bd0f0(param_2);
      return;
    }
    if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xbc) != (int *)0x0)) {
      (**(code **)(**(int **)(DAT_007356a8 + 0xbc) + 0x14))(0x1d);
    }
    DAT_00735e34 = DAT_00735e34 & 0xfb;
    if (DAT_00777cc8 == 5) {
      _DAT_0075895c = 1;
      iVar2 = FEngFindPackage();
      bVar4 = iVar2 == 0;
    }
    else {
      DAT_00758954 = 1;
      iVar2 = FEngFindPackage();
      bVar4 = iVar2 == 0;
    }
LAB_004bcede:
    if (!bVar4) {
      *(undefined4 *)(iVar2 + 0x1c) = 0xff;
    }
    FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
    return;
  }
  if (param_2 == 0x43211243) {
    FUN_00416f00();
    FUN_00495fc0();
    return;
  }
  if (param_2 != 0xc407210) {
    if (param_2 == 0x12345678) {
      if (DAT_00777b4c != 8) {
        return;
      }
      DAT_00758c2c = *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x738);
      iVar2 = FEngFindPackage();
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x1c) = 0xff;
      }
      FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
      return;
    }
    if (param_2 != 0x1a2826e1) {
      return;
    }
    if ((DAT_006f1dd8 != 0) && (*(int **)(DAT_007356a8 + 0xbc) != (int *)0x0)) {
      (**(code **)(**(int **)(DAT_007356a8 + 0xbc) + 0x14))(0x1d);
    }
    DAT_00735e34 = DAT_00735e34 & 0xfb;
    DAT_00758954 = 0;
    iVar2 = FEngFindPackage();
    bVar4 = iVar2 == 0;
    goto LAB_004bcede;
  }
  if (DAT_00777b4c != 8) {
    if (DAT_00777cc8 != 5) {
      FUN_004bd000(param_1);
      return;
    }
    FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
    return;
  }
  auStack_34[6] = 0;
  auStack_34[7] = 0;
  cVar1 = FEPlayerCarDB__HasCarHandle();
  if (cVar1 != '\0') {
    iVar2 = FUN_004ac1f0();
    uStack_38 = 0x84c276d9;
    if (*(int *)(iVar2 + 8) == 8) goto LAB_004bcc6b;
  }
  uStack_38 = 0x9a67c1ae;
LAB_004bcc6b:
  auStack_34[0] = 0xf770;
  auStack_34[1] = 0x12345678;
  auStack_34[2] = 0x61c;
  auStack_34[3] = 0;
  auStack_34[4] = 0;
  auStack_34[5] = 0xb8a7c6cc;
  FUN_004dc6e0(&uStack_38,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
  return;
}


// ==== 0x4bcfd0 Screen_MU_QuickRaceCarSelect::IsSelectedCarInGarage

/* [canon] canon med (ghidra-canon+hopper) docs/re/canon.md */

uint Screen_MU_QuickRaceCarSelect__IsSelectedCarInGarage(void)

{
  int in_EAX;
  int *piVar1;
  
  piVar1 = &DAT_0075afa4;
  do {
    if (*(int *)(*(int *)(in_EAX + 0x48) + 0x738) == *piVar1) {
      return CONCAT31((int3)((uint)piVar1 >> 8),1);
    }
    piVar1 = piVar1 + 0xd2;
  } while ((int)piVar1 < 0x75f144);
  return (uint)piVar1 & 0xffffff00;
}


// ==== 0x4bd000 FUN_004bd000

void FUN_004bd000(int param_1)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  DAT_00735e34 = DAT_00735e34 | 4;
  local_c = (DAT_00758954 != 0) + 0xb8a7c6cc;
  local_8 = 0;
  local_4 = 0;
  local_24 = 0x30003d27;
  local_1c = 0x1a2826e1;
  local_20 = 0x61cb0720;
  local_14 = 0x5f5e3886;
  local_18 = 0x1b3a2485;
  local_10 = 0xa1c41aef;
  FUN_004dc6e0(&local_24,"GenericDialog.fng",*(undefined4 *)(param_1 + 0xc));
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int **)(iVar1 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x14) + 8))(0x5a7b4438,0,0,*(int *)(iVar1 + 0x18));
  }
  return;
}


// ==== 0x4bd0c0 FUN_004bd0c0

void FUN_004bd0c0(void)

{
  FUN_004ac060("MU_Garage.fng",0);
  LaunchPartsBrowser(2);
  return;
}


// ==== 0x4bd0f0 FUN_004bd0f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bd0f0(int param_1)

{
  byte *pbVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  int unaff_EBX;
  undefined1 local_730 [1092];
  int local_2ec;
  int local_2e8;
  
  puVar2 = *(undefined4 **)(unaff_EBX + 0x48);
  if (param_1 == -0x6edfbf62) {
    if (puVar2 != *(undefined4 **)(unaff_EBX + 0x40)) {
      *(undefined4 *)(unaff_EBX + 0x48) = puVar2[1];
    }
  }
  else if ((param_1 == -0x4a68e40f) && (puVar2 != *(undefined4 **)(unaff_EBX + 0x44))) {
    *(undefined4 *)(unaff_EBX + 0x48) = *puVar2;
  }
  piVar5 = &DAT_0075afa4;
  do {
    if (*(int *)(*(int *)(unaff_EBX + 0x48) + 0x738) == *piVar5) {
      FUN_00414a60();
      FUN_00414a60();
      goto LAB_004bd161;
    }
    piVar5 = piVar5 + 0xd2;
  } while ((int)piVar5 < 0x75f144);
  FUN_00414a10();
  FUN_00414a10();
LAB_004bd161:
  if (puVar2 != *(undefined4 **)(unaff_EBX + 0x48)) {
    FUN_004f8340(*(undefined4 *)(unaff_EBX + 0xc));
    if (*(int *)(*(int *)(*(int *)(unaff_EBX + 0x48) + 0x730) + 0xc54) == 0) {
      uVar3 = *(undefined4 *)(*(int *)(unaff_EBX + 0x48) + 0x738);
      uVar4 = uVar3;
      if (DAT_00777b4c == 8) {
        uVar4 = DAT_00758c28;
        DAT_00758c2c = uVar3;
      }
      DAT_00758c28 = uVar4;
      iVar6 = FUN_004b2330();
      if (iVar6 != 0) {
        GarageMainScreen__SetCarType(iVar6);
      }
      *(undefined4 *)(unaff_EBX + 0x90) = DAT_0073ad3c;
    }
    else {
      RideInfo__Init();
      Ride_Init(1,0,0);
      pcVar8 = "DUMMY_SKIN1";
      local_2ec = -1;
      uVar7 = 0x44;
      do {
        local_2ec = local_2ec * 0x21 + uVar7;
        pbVar1 = (byte *)(pcVar8 + 1);
        uVar7 = (uint)*pbVar1;
        pcVar8 = pcVar8 + 1;
      } while (*pbVar1 != 0);
      pcVar8 = "DUMMY_WHEEL1";
      local_2e8 = -1;
      uVar7 = 0x44;
      do {
        local_2e8 = local_2e8 * 0x21 + uVar7;
        pbVar1 = (byte *)(pcVar8 + 1);
        uVar7 = (uint)*pbVar1;
        pcVar8 = pcVar8 + 1;
      } while (*pbVar1 != 0);
      FUN_0057d340(local_730);
      FUN_0057e9a0(local_730);
      iVar6 = FUN_004b2330();
      RideInfo__operator_(&DAT_00748850,local_730);
      _DAT_0072cc80 = 1;
      if (iVar6 != 0) {
        GarageMainScreen__SetRideInfo(iVar6,&DAT_00748850,1);
      }
    }
    GetCarManufacturerNameHash();
    FUN_004f8910();
  }
  iVar6 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar6 != 0) && (*(int *)(iVar6 + 0x14) != 0)) {
    FUN_004f8000(unaff_EBX);
    FUN_004e6ac0();
  }
  return;
}


// ==== 0x4bd310 Screen_MU_QuickRaceLapPopup_PC::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_QuickRaceLapPopup_PC__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687cb3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x48);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_QuickRaceLapPopup_PC__Screen_MU_QuickRaceLapPopup_PC(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4bd370 Screen_MU_QuickRaceLapPopup_PC::Screen_MU_QuickRaceLapPopup_PC

/* [canon] canon med (capstone+hopper) docs/re/gameflow.md */

undefined4 *
Screen_MU_QuickRaceLapPopup_PC__Screen_MU_QuickRaceLapPopup_PC
          (undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = __CxxFrameHandler_wrapper;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  *param_1 = &PTR_FUN_006c5b04;
  local_4 = 0;
  if (DAT_00777cc8 == 5) {
    FUN_004bd5e0();
  }
  else {
    FUN_004bd580();
  }
  iVar3 = param_1[3];
  uVar2 = FEng__HashName();
  if (iVar3 == 0) {
LAB_004bd3e5:
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(uVar2);
    }
  }
  else {
    iVar3 = FEngFindPackage();
    if (iVar3 == 0) goto LAB_004bd3e5;
    iVar3 = FUN_004ffb70();
    if (iVar3 == 0) goto LAB_004bd3e5;
  }
  iVar1 = param_1[3];
  param_1[0x10] = iVar3;
  uVar2 = FEng__HashName();
  if (iVar1 != 0) {
    iVar3 = FEngFindPackage();
    if (iVar3 != 0) {
      iVar3 = FUN_004ffb70();
      if (iVar3 != 0) goto LAB_004bd443;
    }
  }
  if (DAT_0073578c == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_004ef050(uVar2);
  }
LAB_004bd443:
  param_1[0x11] = iVar3;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4bd460 FUN_004bd460

void * __thiscall FUN_004bd460(void *param_1,byte param_2)

{
  FUN_004bd480();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4bd480 FUN_004bd480

void __fastcall FUN_004bd480(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c5b04;
  FUN_004f7b50();
  return;
}


// ==== 0x4bd490 FUN_004bd490

void FUN_004bd490(void)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  
  iVar2 = RaceOptions_Get();
  piVar1 = (int *)(iVar2 + 0x10);
  iVar2 = *piVar1;
  if (in_EAX == -0x6edfbf62) {
    iVar2 = iVar2 + -1;
    if (iVar2 < 1) {
      *piVar1 = 10;
      FUN_004bd580();
      return;
    }
  }
  else if ((in_EAX == -0x4a68e40f) && (iVar2 = iVar2 + 1, 10 < iVar2)) {
    iVar2 = 1;
  }
  *piVar1 = iVar2;
  FUN_004bd580();
  return;
}


// ==== 0x4bd4f0 FUN_004bd4f0

void FUN_004bd4f0(void)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  
  iVar2 = RaceOptions_Get();
  piVar1 = (int *)(iVar2 + 0x20);
  iVar2 = *piVar1;
  if (in_EAX == -0x4a68e40f) {
    iVar3 = iVar2 + -1;
    if (iVar3 < 1) {
      *piVar1 = 5;
      FUN_004bd5e0();
      return;
    }
    if ((iVar3 == 2) || (iVar3 == 4)) {
      *piVar1 = iVar2 + -2;
      FUN_004bd5e0();
      return;
    }
  }
  else {
    iVar3 = iVar2;
    if (in_EAX == -0x6edfbf62) {
      iVar3 = iVar2 + 1;
      if (5 < iVar3) {
        *piVar1 = 1;
        FUN_004bd5e0();
        return;
      }
      if ((iVar3 == 2) || (iVar3 == 4)) {
        iVar3 = iVar2 + 2;
      }
    }
  }
  *piVar1 = iVar3;
  FUN_004bd5e0();
  return;
}


// ==== 0x4bd580 FUN_004bd580

void FUN_004bd580(void)

{
  int iVar1;
  
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(&DAT_006cc568,iVar1);
  iVar1 = RaceOptions_Get();
  FEngPrintf(&PTR_FUN_006c7968,*(undefined4 *)(iVar1 + 0x10));
  return;
}


// ==== 0x4bd5e0 FUN_004bd5e0

void FUN_004bd5e0(void)

{
  int iVar1;
  
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  iVar1 = RaceOptions_Get();
  iVar1 = *(int *)(iVar1 + 0x20);
  if (((iVar1 == 1) || (iVar1 == 3)) || (iVar1 == 5)) {
    iVar1 = LanguageStrings__FindByHash();
    if (iVar1 == 0) {
      iVar1 = LanguageStrings__FindByHash();
    }
    FEngPrintf(iVar1);
  }
  return;
}


// ==== 0x4bd670 FUN_004bd670

void FUN_004bd670(void)

{
  uint in_EAX;
  int iVar1;
  
  if (DAT_00777b4c == 2) {
    if ((in_EAX & 1) == 0) {
      if ((in_EAX & 2) == 0) {
        if ((in_EAX & 4) == 0) {
          DAT_00748f78 = (-(uint)((in_EAX & 8) != 0) & 4) - 1;
        }
        else {
          DAT_00748f78 = 2;
        }
      }
      else {
        DAT_00748f78 = 1;
      }
    }
    else {
      DAT_00748f78 = 0;
    }
  }
  if (((DAT_0073578c != 0) && (iVar1 = FEPackageList__FindByName(&DAT_00746104), iVar1 != 0)) &&
     (*(int *)(iVar1 + 0x18) != 0)) {
    FUN_004f09b0(*(int *)(iVar1 + 0x18));
  }
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int **)(iVar1 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x14) + 8))(0xaa3f4777,0,0,*(int *)(iVar1 + 0x18));
  }
  return;
}


// ==== 0x4bd710 FUN_004bd710

void __thiscall FUN_004bd710(int param_1,uint param_2)

{
  undefined4 uVar1;
  char cVar2;
  
  if (param_2 < 0x9120409f) {
    if (param_2 != 0x9120409e) {
      if (param_2 == 0xc407210) {
        if (DAT_00777cc8 != 4) {
          QuickRace__StartRaceByMode();
          return;
        }
        FUN_004bd670();
        return;
      }
      if (param_2 != 0x911ab364) {
        return;
      }
      FEngQueuePackagePop(*(undefined4 *)(param_1 + 0xc));
      return;
    }
  }
  else if (param_2 != 0xb5971bf1) {
    if (param_2 != 0xc98356ba) {
      return;
    }
    cVar2 = FUN_004f7eb0(param_1);
    if (cVar2 != '\0') {
      uVar1 = *(undefined4 *)(param_1 + 0x40);
      FEngFindPackage();
      FEngSendMessageToObject(0x9120409e,uVar1);
      FUN_004c96c0(0x9120409e);
    }
    cVar2 = FUN_004f7eb0(param_1);
    if (cVar2 == '\0') {
      return;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x44);
    FEngFindPackage();
    FEngSendMessageToObject(0xb5971bf1,uVar1);
    FUN_004c96c0(0xb5971bf1);
    return;
  }
  if (DAT_00777cc8 != 5) {
    FUN_004bd490(param_1);
    return;
  }
  FUN_004bd4f0(param_1);
  return;
}


// ==== 0x4bd810 Screen_MU_QuickRaceLapPopup_PC::NotifySoundMessage

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

undefined4 Screen_MU_QuickRaceLapPopup_PC__NotifySoundMessage(uint param_1)

{
  undefined4 in_stack_00000014;
  
  if (param_1 < 0x9120409f) {
    if (param_1 == 0x9120409e) {
      return 1;
    }
    if ((param_1 == 0x72619778) || (param_1 == 0x911c0a4b)) {
      return 0;
    }
  }
  else if (param_1 == 0xb5971bf1) {
    return 2;
  }
  return in_stack_00000014;
}


// ==== 0x4bd850 FUN_004bd850

void __fastcall FUN_004bd850(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c56c8;
  param_1[0x4c] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  param_1[0x40] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  param_1[0x34] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  param_1[0x28] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  param_1[0x1c] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  FUN_004f7b50();
  return;
}


// ==== 0x4bd880 FUN_004bd880

void * __thiscall FUN_004bd880(void *param_1,byte param_2)

{
  FUN_004bd850();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4bd8a0 Screen_MU_PauseOptions_PC::Create

/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

undefined4 Screen_MU_PauseOptions_PC__Create(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688b13;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x2b8);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = Screen_MU_PauseOptions_PC__Screen_MU_PauseOptions_PC(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x4bd900 Screen_MU_PauseOptions_PC::Screen_MU_PauseOptions_PC

/* [canon] canon low (capstone) docs/re/gameflow.md */

undefined4 * Screen_MU_PauseOptions_PC__Screen_MU_PauseOptions_PC(undefined4 *param_1,uint param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 *puVar6;
  char *local_30;
  char *local_2c;
  char *local_28;
  undefined1 *local_24;
  void *local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688aeb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  *param_1 = &PTR_FUN_006c56c8;
  param_1[0x1c] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  param_1[0x1d] = &DAT_006b9172;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  param_1[0x29] = &DAT_006b9172;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  param_1[0x35] = &DAT_006b9172;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  param_1[0x41] = &DAT_006b9172;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = &PTR_Slider__scalar_deleting_destructor_006cbe74;
  param_1[0x4d] = &DAT_006b9172;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  iVar4 = *(int *)(DAT_007361f0 + 0x1c);
  local_4 = 5;
  if (iVar4 == 0) {
    param_2 = 1;
  }
  else if (iVar4 == 1) {
    param_2 = 2;
  }
  else if (iVar4 == 2) {
    param_2 = 4;
  }
  else {
    param_2 = (iVar4 != 3) - 1 & 8;
  }
  iVar4 = FEngFindPackage();
  if (iVar4 != 0) {
    *(uint *)(iVar4 + 0x1c) = param_2;
  }
  local_30 = (char *)param_1[3];
  local_18 = (float)DAT_0078a3fb;
  local_2c = "SliderBase_2";
  local_28 = "Slider_2";
  local_24 = &DAT_006b9172;
  local_14 = 0x42800000;
  local_10 = 0x41200000;
  local_1c = 255.0;
  local_20 = (void *)0x0;
  (**(code **)(param_1[0x28] + 8))(&local_30);
  local_1c = (float)DAT_0078a3fa;
  local_30 = "SliderBase_1";
  local_2c = "Slider_1";
  (**(code **)(param_1[0x1c] + 8))(&stack0xffffffcc);
  local_20 = DAT_007588fc;
  local_30 = "Slider_4";
  local_2c = "";
  local_1c = 0.1;
  local_18 = 10.0;
  local_24 = (undefined1 *)0x3f800000;
  local_28 = (char *)0x0;
  (**(code **)(param_1[0x34] + 8))(&stack0xffffffc8);
  local_24 = (undefined1 *)DAT_00758904;
  (**(code **)(param_1[0x40] + 8))(&stack0xffffffc4);
  local_28 = (char *)DAT_00758900;
  (**(code **)(param_1[0x4c] + 8))(&stack0xffffffc0);
  pcVar1 = (char *)((int)param_1 + 0x21d);
  *pcVar1 = 'O';
  pcVar5 = pcVar1;
  do {
    cVar2 = pcVar5[(int)("OptionNametext_" + (1 - (int)pcVar1))];
    pcVar5 = pcVar5 + 1;
    *pcVar5 = cVar2;
  } while (cVar2 != '\0');
  *(bool *)(param_1 + 0x10) = DAT_0078a3f6 == '\x05';
  iVar4 = (int)DAT_0078a3f6;
  param_1[0x7b] = 1;
  param_1[0x58] = 1;
  param_1[0x11] = iVar4;
  *(undefined1 *)(param_1 + 0x87) = 0;
  puVar6 = param_1 + 0x8d;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  iVar4 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x18), iVar4 == 0)) {
    if ((DAT_0073578c == 0) || (iVar3 = *(int *)(DAT_0073578c + 8), iVar3 == 0)) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_004fd1e0(iVar3 + 0xdc);
      if (iVar4 == 0) {
        iVar4 = FUN_004fd1e0(iVar3 + 0xec);
      }
    }
  }
  param_1[0xad] = iVar4;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  FUN_004c0b60(param_1);
  ExceptionList = local_20;
  return param_1;
}


// ==== 0x4bdd10 FUN_004bdd10

void __thiscall FUN_004bdd10(int param_1,uint param_2,int param_3)

{
  int iVar1;
  
  if (param_2 < 0xb5971bf2) {
    if (param_2 != 0xb5971bf1) {
      if (param_2 == 0x3b00ff0) {
        FUN_004c0b60(param_1);
        return;
      }
      if ((param_2 != 0xc407210) && (param_2 != 0x9120409e)) {
        return;
      }
    }
    if ((&DAT_007306c4)[*(int *)(DAT_007361f0 + 0x1c)] != -1) {
      switch(*(undefined4 *)(param_3 + 0x10)) {
      case 0x1aec7d09:
        if (*(code **)(param_1 + 0x48) != (code *)0x0) {
          (**(code **)(param_1 + 0x48))(param_2);
          return;
        }
        break;
      case 0x1aec7d0a:
        if (*(code **)(param_1 + 0x4c) != (code *)0x0) {
          (**(code **)(param_1 + 0x4c))(param_2);
          return;
        }
        break;
      case 0x1aec7d0b:
        if (*(code **)(param_1 + 0x50) != (code *)0x0) {
          (**(code **)(param_1 + 0x50))(param_2);
          return;
        }
        break;
      case 0x1aec7d0c:
        if (*(code **)(param_1 + 0x54) != (code *)0x0) {
          (**(code **)(param_1 + 0x54))(param_2);
          return;
        }
        break;
      case 0x1aec7d0d:
        if (*(code **)(param_1 + 0x58) != (code *)0x0) {
          (**(code **)(param_1 + 0x58))(param_2);
          return;
        }
        break;
      case 0x1aec7d0e:
        if (*(code **)(param_1 + 0x5c) != (code *)0x0) {
          (**(code **)(param_1 + 0x5c))(param_2);
          return;
        }
        break;
      case 0x1aec7d0f:
        if (*(code **)(param_1 + 0x60) != (code *)0x0) {
          (**(code **)(param_1 + 0x60))(param_2);
          return;
        }
        break;
      case 0x1aec7d10:
        if (*(code **)(param_1 + 100) != (code *)0x0) {
          (**(code **)(param_1 + 100))(param_2);
          return;
        }
      }
    }
  }
  else if (param_2 == 0xb5af2461) {
    if ((&DAT_007306c4)[*(int *)(DAT_007361f0 + 0x1c)] != -1) {
      FEngQueuePackagePop(*(undefined4 *)(param_1 + 0xc));
      FEngQueuePackagePop("MU_PauseOptionsSelector.fng");
      FUN_00421c00(DAT_007361f0,6,1);
    }
  }
  else {
    if (param_2 == 0xc98356ba) {
      iVar1 = FEPackageList__FindByName(&DAT_00746104);
      if ((iVar1 == 0) || (*(int *)(iVar1 + 0x18) == 0)) {
        FEManager__PushPackageChecked(0x32,0);
      }
      (**(code **)(*(int *)(param_1 + 0xa0) + 0x10))();
      (**(code **)(*(int *)(param_1 + 0x70) + 0x10))();
      FUN_004c19e0(param_1);
      return;
    }
    if (param_2 == 0xf2d0d887) {
      iVar1 = FEngFindPackage();
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x1c) = 0;
      }
      FEngQueueMessageToPackage();
      FEngQueuePackagePop(*(undefined4 *)(param_1 + 0xc));
      return;
    }
  }
  return;
}


// ==== 0x4bdf20 Screen_MU_PauseOptions_PC::NotifySoundMessage

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

int Screen_MU_PauseOptions_PC__NotifySoundMessage(void)

{
  int in_stack_00000014;
  
  if (((in_stack_00000014 != 5) && (in_stack_00000014 != 1)) && (in_stack_00000014 != 2)) {
    return in_stack_00000014;
  }
  return 0;
}


// ==== 0x4bdf40 FUN_004bdf40

void __fastcall FUN_004bdf40(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x164));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  (**(code **)(*(int *)(param_1 + 0x100) + 0x10))();
  return;
}


// ==== 0x4bdfb0 FUN_004bdfb0

void __fastcall FUN_004bdfb0(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x168));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  (**(code **)(*(int *)(param_1 + 0xd0) + 0x10))();
  return;
}


// ==== 0x4be020 FUN_004be020

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004be020(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x178));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  iVar1 = DAT_007356a8;
  if (DAT_007356a8 != 0) {
    *(undefined4 **)(DAT_007356a8 + 8) = &DAT_007588fc;
    FUN_0051cc10(iVar1);
    _DAT_006f8718 = DAT_00758914;
    _DAT_006f871c = _ftol_nocw();
  }
  (**(code **)(*(int *)(param_1 + 0x130) + 0x10))();
  return;
}


// ==== 0x4be0c0 FUN_004be0c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004be0c0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  if ((param_2 == -0x6edfbf62) || (param_2 == -0x4a68e40f)) {
    fVar1 = *(float *)(param_1 + 0x11c);
    if (param_2 == -0x6edfbf62) {
      fVar2 = *(float *)(param_1 + 0x11c) - *(float *)(param_1 + 0x124);
      *(float *)(param_1 + 0x11c) = fVar2;
      if (*(float *)(param_1 + 0x114) < fVar2) {
        *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(param_1 + 0x114);
      }
      if (*(float *)(param_1 + 0x11c) < *(float *)(param_1 + 0x118)) {
        *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(param_1 + 0x118);
      }
    }
    else if (param_2 == -0x4a68e40f) {
      fVar2 = *(float *)(param_1 + 0x124) + *(float *)(param_1 + 0x11c);
      *(float *)(param_1 + 0x11c) = fVar2;
      if (*(float *)(param_1 + 0x114) < fVar2) {
        *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(param_1 + 0x114);
      }
      if (*(float *)(param_1 + 0x11c) < *(float *)(param_1 + 0x118)) {
        *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(param_1 + 0x118);
      }
    }
    iVar3 = DAT_007356a8;
    DAT_00758904 = *(undefined4 *)(param_1 + 0x11c);
    if (DAT_007356a8 != 0) {
      *(undefined4 **)(DAT_007356a8 + 8) = &DAT_007588fc;
      FUN_0051cc10(iVar3);
      _DAT_006f8718 = DAT_00758914;
      _DAT_006f871c = _ftol_nocw();
    }
    FUN_004bdf40();
    if (fVar1 != *(float *)(param_1 + 0x11c)) {
      if (param_2 == -0x6edfbf62) {
        FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
    }
  }
  return;
}


// ==== 0x4be230 FUN_004be230

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004be230(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  if ((param_2 == -0x6edfbf62) || (param_2 == -0x4a68e40f)) {
    fVar1 = *(float *)(param_1 + 0xec);
    if (param_2 == -0x6edfbf62) {
      fVar2 = *(float *)(param_1 + 0xec) - *(float *)(param_1 + 0xf4);
      *(float *)(param_1 + 0xec) = fVar2;
      if (*(float *)(param_1 + 0xe4) < fVar2) {
        *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 0xe4);
      }
      if (*(float *)(param_1 + 0xec) < *(float *)(param_1 + 0xe8)) {
        *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 0xe8);
      }
    }
    else if (param_2 == -0x4a68e40f) {
      fVar2 = *(float *)(param_1 + 0xf4) + *(float *)(param_1 + 0xec);
      *(float *)(param_1 + 0xec) = fVar2;
      if (*(float *)(param_1 + 0xe4) < fVar2) {
        *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 0xe4);
      }
      if (*(float *)(param_1 + 0xec) < *(float *)(param_1 + 0xe8)) {
        *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 0xe8);
      }
    }
    iVar3 = DAT_007356a8;
    DAT_007588fc = *(undefined4 *)(param_1 + 0xec);
    if (DAT_007356a8 != 0) {
      *(undefined4 **)(DAT_007356a8 + 8) = &DAT_007588fc;
      FUN_0051cc10(iVar3);
      _DAT_006f8718 = DAT_00758914;
      _DAT_006f871c = _ftol_nocw();
    }
    FUN_004bdfb0();
    if (fVar1 != *(float *)(param_1 + 0xec)) {
      if (param_2 == -0x6edfbf62) {
        FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
    }
  }
  return;
}


// ==== 0x4be3a0 FUN_004be3a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004be3a0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  if ((param_2 == -0x6edfbf62) || (param_2 == -0x4a68e40f)) {
    fVar1 = *(float *)(param_1 + 0x14c);
    if (param_2 == -0x6edfbf62) {
      fVar2 = *(float *)(param_1 + 0x14c) - *(float *)(param_1 + 0x154);
      *(float *)(param_1 + 0x14c) = fVar2;
      if (*(float *)(param_1 + 0x144) < fVar2) {
        *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_1 + 0x144);
      }
      if (*(float *)(param_1 + 0x14c) < *(float *)(param_1 + 0x148)) {
        *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_1 + 0x148);
      }
    }
    else if (param_2 == -0x4a68e40f) {
      fVar2 = *(float *)(param_1 + 0x154) + *(float *)(param_1 + 0x14c);
      *(float *)(param_1 + 0x14c) = fVar2;
      if (*(float *)(param_1 + 0x144) < fVar2) {
        *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_1 + 0x144);
      }
      if (*(float *)(param_1 + 0x14c) < *(float *)(param_1 + 0x148)) {
        *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_1 + 0x148);
      }
    }
    iVar3 = DAT_007356a8;
    DAT_00758900 = *(undefined4 *)(param_1 + 0x14c);
    if (DAT_007356a8 != 0) {
      *(undefined4 **)(DAT_007356a8 + 8) = &DAT_007588fc;
      FUN_0051cc10(iVar3);
      _DAT_006f8718 = DAT_00758914;
      _DAT_006f871c = _ftol_nocw();
    }
    FUN_004be020();
    if (fVar1 != *(float *)(param_1 + 0x14c)) {
      if (param_2 == -0x6edfbf62) {
        FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
    }
  }
  return;
}


// ==== 0x4be510 FUN_004be510

void __fastcall FUN_004be510(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_007361b4 == 0) {
    iVar4 = -1;
  }
  else {
    iVar4 = *(int *)(DAT_007361b4 + 8);
  }
  if (*(int *)(DAT_007361f0 + 0x1c) == iVar4) {
    uVar2 = 0;
  }
  else {
    if (DAT_007361b8 == 0) {
      iVar4 = -1;
    }
    else {
      iVar4 = *(int *)(DAT_007361b8 + 8);
    }
    uVar2 = (uint)(*(int *)(DAT_007361f0 + 0x1c) == iVar4);
  }
  iVar4 = (&DAT_007361b4)[uVar2];
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x180));
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar3);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x180));
  cVar1 = *(char *)(iVar4 + 0x24);
  if ((((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) || (DAT_00700b5c != 0)) &&
     (((cVar1 != '\0' && (cVar1 != '\x01')) && ((cVar1 != '\x02' && (cVar1 != '\x04')))))) {
    FEngPrintf("NOT DRAWING ANYTHING");
    return;
  }
  iVar4 = LanguageStrings__FindByHash();
  if (iVar4 == 0) {
    iVar4 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar4);
  return;
}


// ==== 0x4be660 FUN_004be660

void __fastcall FUN_004be660(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x184));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  (**(code **)(*(int *)(param_1 + 0x70) + 0x10))();
  return;
}


// ==== 0x4be6c0 OptionsCameraUI

/* [canon] camera I (C) docs/re/camera.md */

void OptionsCameraUI(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  
  if ((param_1 == -0x6edfbf62) || (param_1 == -0x4a68e40f)) {
    iVar2 = FUN_004cd610();
    cVar1 = DAT_0078a344;
    iVar3 = DAT_007361a8;
    iVar2 = (&DAT_007361b4)[iVar2];
    if (((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) || (DAT_00700b5c != 0)) {
      iVar5 = FUN_004cd610();
      iVar5 = (&DAT_00758948)[iVar5];
    }
    else {
      iVar5 = -1;
    }
    if (param_1 == -0x6edfbf62) {
      iVar5 = iVar5 + -1;
      if ((cVar1 == '\0') && (iVar3 == 0)) {
        if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
          if (iVar5 < 0) {
            iVar5 = 2;
          }
        }
        else if (iVar5 < 0) {
          iVar5 = 3;
        }
      }
      else if (iVar5 < -1) {
        iVar5 = 2;
      }
    }
    else if (param_1 == -0x4a68e40f) {
      iVar5 = iVar5 + 1;
      if ((cVar1 == '\0') && (iVar3 == 0)) {
        if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
          bVar8 = SBORROW4(iVar5,2);
          iVar3 = -2;
          bVar7 = iVar5 == 2;
        }
        else {
          bVar8 = SBORROW4(iVar5,3);
          iVar3 = -3;
          bVar7 = iVar5 == 3;
        }
        if (!bVar7 && bVar8 == iVar5 + iVar3 < 0) {
          iVar5 = 0;
        }
      }
      else if (2 < iVar5) {
        iVar5 = -1;
      }
    }
    iVar3 = FUN_004cd610();
    (&DAT_0078a388)[iVar3 * 0x38] = *(undefined1 *)(iVar5 + 0x2c + iVar2);
    *(undefined1 *)(iVar2 + 0x24) = *(undefined1 *)(iVar5 + 0x2c + iVar2);
    if (iVar5 != -1) {
      iVar2 = FUN_004cd610();
      (&DAT_00758948)[iVar2] = iVar5;
      DAT_00700b5c = 1;
      iVar2 = FindCameraRow();
      if (iVar2 != 0) {
        Player__NotifyCameraMovers();
      }
    }
    DAT_00758950 = DAT_00700b5c == 0;
    FUN_004be510();
    if (param_1 == -0x6edfbf62) {
      uVar6 = 10;
    }
    else {
      uVar6 = (param_1 != -0x4a68e40f) - 1 & 0xb;
    }
    if ((&DAT_006f8a48)[uVar6 * 2] != uVar6) {
      uVar4 = 0;
      do {
        if (*(uint *)((int)&DAT_006f8a48 + uVar4) == uVar6) break;
        uVar4 = uVar4 + 8;
      } while (uVar4 < 0x70);
    }
    FUN_004cd180(0);
  }
  return;
}


// ==== 0x4be860 FUN_004be860

void __thiscall FUN_004be860(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  
  if ((param_2 == -0x6edfbf62) || (param_2 == -0x4a68e40f)) {
    fVar1 = *(float *)(param_1 + 0x8c);
    if (param_2 == -0x6edfbf62) {
      fVar2 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 0x94);
      *(float *)(param_1 + 0x8c) = fVar2;
      if (*(float *)(param_1 + 0x84) < fVar2) {
        *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x84);
      }
      if (*(float *)(param_1 + 0x8c) < *(float *)(param_1 + 0x88)) {
        *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x88);
      }
    }
    else if (param_2 == -0x4a68e40f) {
      fVar2 = *(float *)(param_1 + 0x94) + *(float *)(param_1 + 0x8c);
      *(float *)(param_1 + 0x8c) = fVar2;
      if (*(float *)(param_1 + 0x84) < fVar2) {
        *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x84);
      }
      if (*(float *)(param_1 + 0x8c) < *(float *)(param_1 + 0x88)) {
        *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x88);
      }
    }
    DAT_00758951 = _ftol_nocw();
    DAT_0078a3fa = DAT_00758951;
    FUN_004be660();
    if (fVar1 != *(float *)(param_1 + 0x8c)) {
      if (param_2 == -0x6edfbf62) {
        FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      FUN_004f8340(*(undefined4 *)(param_1 + 0xc));
    }
  }
  return;
}


// ==== 0x4be9a0 FUN_004be9a0

void __fastcall FUN_004be9a0(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 400));
  iVar2 = LanguageStrings__FindByHash();
  if (iVar2 == 0) {
    iVar2 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar2);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 400));
  if (DAT_007361b4 == 0) {
    iVar2 = -1;
  }
  else {
    iVar2 = *(int *)(DAT_007361b4 + 8);
  }
  if (*(int *)(DAT_007361f0 + 0x1c) == iVar2) {
    uVar3 = 0;
  }
  else {
    if (DAT_007361b8 == 0) {
      iVar2 = -1;
    }
    else {
      iVar2 = *(int *)(DAT_007361b8 + 8);
    }
    uVar3 = (uint)(*(int *)(DAT_007361f0 + 0x1c) == iVar2);
  }
  cVar1 = *(char *)((&DAT_007361b4)[uVar3] + 0x23);
  if (((cVar1 == '\x01') || (cVar1 == '\x03')) || (cVar1 == '\0')) {
    iVar2 = LanguageStrings__FindByHash();
    if (iVar2 == 0) {
      iVar2 = LanguageStrings__FindByHash();
    }
    FEngPrintf(iVar2);
  }
  return;
}


// ==== 0x4bead0 FUN_004bead0

void __fastcall FUN_004bead0(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x194));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x194));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  return;
}


// ==== 0x4beb80 FUN_004beb80

void __fastcall FUN_004beb80(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x198));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x198));
  if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
    iVar1 = FUN_004cd610();
    if (((&DAT_0078a386)[iVar1 * 0x38] != '\0') &&
       (iVar1 = FUN_004cd610(), (&DAT_0078a386)[iVar1 * 0x38] != '\x01')) {
      return;
    }
  }
  else if ((DAT_007361ac != 2) && ((DAT_007361ac != 1 && (DAT_007361ac != 0)))) {
    return;
  }
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  return;
}


// ==== 0x4beca0 FUN_004beca0

void FUN_004beca0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_1 == -0x6edfbf62) || (param_1 == -0x4a68e40f)) {
    FUN_004cd610();
    RealDriver__SetManualTransmission();
    FUN_004cd610();
    FUN_00494b90();
    FUN_004be9a0();
    if (param_1 == -0x6edfbf62) {
      uVar2 = 10;
    }
    else {
      uVar2 = (param_1 != -0x4a68e40f) - 1 & 0xb;
    }
    if ((&DAT_006f8a48)[uVar2 * 2] != uVar2) {
      uVar1 = 0;
      do {
        if (*(uint *)((int)&DAT_006f8a48 + uVar1) == uVar2) break;
        uVar1 = uVar1 + 8;
      } while (uVar1 < 0x70);
    }
    FUN_004cd180(0);
  }
  return;
}


// ==== 0x4bedb0 FUN_004bedb0

void FUN_004bedb0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  
  if ((param_1 == -0x6edfbf62) || (param_1 == -0x4a68e40f)) {
    bVar6 = DAT_0078a336 == '\0';
    iVar3 = 0;
    DAT_0078a336 = bVar6;
    if (0 < *(int *)(DAT_007361f8 + 0x18)) {
      iVar4 = 0x28;
      iVar1 = DAT_007361f8;
      do {
        if (*(int *)(*(int *)(iVar4 + iVar1) + 0x868) != 0) {
          FUN_0058db20();
          iVar1 = DAT_007361f8;
        }
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 4;
      } while (iVar3 < *(int *)(iVar1 + 0x18));
    }
    FUN_00494b90();
    DAT_0075896c = bVar6;
    FUN_004bead0();
    if (param_1 == -0x6edfbf62) {
      uVar5 = 10;
    }
    else {
      uVar5 = (param_1 != -0x4a68e40f) - 1 & 0xb;
    }
    if ((&DAT_006f8a48)[uVar5 * 2] != uVar5) {
      uVar2 = 0;
      do {
        if (*(uint *)((int)&DAT_006f8a48 + uVar2) == uVar5) break;
        uVar2 = uVar2 + 8;
      } while (uVar2 < 0x70);
    }
    FUN_004cd180(0);
  }
  return;
}


// ==== 0x4beec0 FUN_004beec0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004beec0(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_1 == -0x6edfbf62) || (param_1 == -0x4a68e40f)) {
    if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
      iVar2 = FUN_004cd610();
      uVar4 = (uint)((&DAT_0078a386)[iVar2 * 0x38] == '\0');
      if ((((&DAT_007361b4)[iVar2] != 0) &&
          (iVar1 = *(int *)((&DAT_007361b4)[iVar2] + 4), iVar1 != 0)) && (iVar1 != -0x40)) {
        (&DAT_0078a386)[iVar2 * 0x38] = (&DAT_0078a386)[iVar2 * 0x38] == '\0';
        *(undefined4 *)(iVar1 + 0x400) = 1;
        _DAT_0078a338 = uVar4;
        FUN_00456ba0();
      }
    }
    else {
      uVar4 = DAT_00758964;
      if (DAT_007361ac == 0) {
        DAT_007361ac = 1;
        DAT_00758968 = 1;
      }
      else {
        DAT_00758968 = DAT_007361ac;
        if (DAT_007361ac == 1) {
          DAT_007361ac = 0;
          DAT_00758968 = DAT_007361ac;
        }
      }
    }
    DAT_00758964 = uVar4;
    FUN_004beb80();
    if (param_1 == -0x6edfbf62) {
      uVar4 = 10;
    }
    else {
      uVar4 = (param_1 != -0x4a68e40f) - 1 & 0xb;
    }
    if ((&DAT_006f8a48)[uVar4 * 2] != uVar4) {
      uVar3 = 0;
      do {
        if (*(uint *)((int)&DAT_006f8a48 + uVar3) == uVar4) break;
        uVar3 = uVar3 + 8;
      } while (uVar3 < 0x70);
    }
    FUN_004cd180(0);
  }
  return;
}


// ==== 0x4befd0 FUN_004befd0

void __fastcall FUN_004befd0(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x19c));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x19c));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  return;
}


// ==== 0x4bf0c0 FUN_004bf0c0

void FUN_004bf0c0(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  if ((param_1 == -0x6edfbf62) || (param_1 == -0x4a68e40f)) {
    iVar2 = FUN_004cd610();
    iVar1 = (&DAT_007361b4)[iVar2];
    bVar5 = *(char *)(iVar1 + 0x21) == '\0';
    *(bool *)(iVar1 + 0x21) = bVar5;
    (&DAT_0078a385)[iVar2 * 0x38] = bVar5;
    iVar2 = FUN_004cd610();
    if (iVar2 == 0) {
      DAT_00758970 = *(char *)(iVar1 + 0x21) != '\0';
    }
    else {
      DAT_00758978 = *(char *)(iVar1 + 0x21) != '\0';
    }
    FUN_004befd0();
    if (param_1 == -0x6edfbf62) {
      uVar4 = 10;
    }
    else {
      uVar4 = (param_1 != -0x4a68e40f) - 1 & 0xb;
    }
    if ((&DAT_006f8a48)[uVar4 * 2] != uVar4) {
      uVar3 = 0;
      do {
        if (*(uint *)((int)&DAT_006f8a48 + uVar3) == uVar4) break;
        uVar3 = uVar3 + 8;
      } while (uVar3 < 0x70);
    }
    FUN_004cd180(0);
  }
  return;
}


// ==== 0x4bf180 FUN_004bf180

void __fastcall FUN_004bf180(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x1a4));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x1a4));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  return;
}


// ==== 0x4bf270 FUN_004bf270

void __fastcall FUN_004bf270(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x1a8));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  return;
}


// ==== 0x4bf2d0 FUN_004bf2d0

void __fastcall FUN_004bf2d0(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x1b0));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x1b0));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  return;
}


// ==== 0x4bf380 FUN_004bf380

void __fastcall FUN_004bf380(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x1b4));
  iVar2 = LanguageStrings__FindByHash();
  if (iVar2 == 0) {
    iVar2 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar2);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x1b4));
  cVar1 = DAT_0078a3f6;
  if (DAT_0078a320 != 1) {
    cVar1 = DAT_0078a3f7;
  }
  if (cVar1 == '\x05') {
    pcVar3 = "<DEBUG> FULLSCREEN";
  }
  else {
    switch(cVar1) {
    case '\x01':
      break;
    default:
      goto switchD_004bf42b_caseD_2;
    case '\x03':
    case '\a':
      break;
    case '\x06':
      break;
    case '\v':
    }
    pcVar3 = (char *)LanguageStrings__FindByHash();
    if (pcVar3 == (char *)0x0) {
      pcVar3 = (char *)LanguageStrings__FindByHash();
    }
  }
  FEngPrintf(pcVar3);
switchD_004bf42b_caseD_2:
  return;
}


// ==== 0x4bf4a0 FUN_004bf4a0

void FUN_004bf4a0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if ((param_1 == -0x6edfbf62) || (param_1 == -0x4a68e40f)) {
    iVar1 = FUN_004cd610();
    iVar1 = (&DAT_007361b4)[iVar1];
    uVar2 = *(uint *)(iVar1 + 0x30);
    if ((uVar2 & 0x40) == 0) {
      uVar2 = uVar2 | 0x40;
    }
    else {
      uVar2 = uVar2 & 0xffffffbf;
    }
    *(uint *)(iVar1 + 0x30) = uVar2;
    uVar2 = (&DAT_0078a394)[*(int *)(iVar1 + 0x10) * 0xe];
    if ((uVar2 & 0x40) == 0) {
      uVar2 = uVar2 | 0x40;
    }
    else {
      uVar2 = uVar2 & 0xffffffbf;
    }
    (&DAT_0078a394)[*(int *)(iVar1 + 0x10) * 0xe] = uVar2;
    iVar3 = FUN_004cd610();
    if (iVar3 == 0) {
      DAT_007588d6 = (byte)(*(uint *)(iVar1 + 0x30) >> 6) & 1;
    }
    else {
      DAT_007588d7 = (byte)(*(uint *)(iVar1 + 0x30) >> 6) & 1;
    }
    FUN_004bf180();
    if (param_1 == -0x6edfbf62) {
      uVar2 = 10;
    }
    else {
      uVar2 = (param_1 != -0x4a68e40f) - 1 & 0xb;
    }
    if ((&DAT_006f8a48)[uVar2 * 2] != uVar2) {
      uVar4 = 0;
      do {
        if (*(uint *)((int)&DAT_006f8a48 + uVar4) == uVar2) break;
        uVar4 = uVar4 + 8;
      } while (uVar4 < 0x70);
    }
    FUN_004cd180(0);
  }
  return;
}


// ==== 0x4bf580 FUN_004bf580

void FUN_004bf580(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_1 == -0x6edfbf62) || (param_1 == -0x4a68e40f)) {
    DAT_007588d4 = DAT_0078a3f4 == '\0';
    DAT_0078a3f4 = DAT_007588d4;
    FUN_004bf2d0();
    if (param_1 == -0x6edfbf62) {
      uVar2 = 10;
    }
    else {
      uVar2 = (param_1 != -0x4a68e40f) - 1 & 0xb;
    }
    if ((&DAT_006f8a48)[uVar2 * 2] != uVar2) {
      uVar1 = 0;
      do {
        if (*(uint *)((int)&DAT_006f8a48 + uVar1) == uVar2) break;
        uVar1 = uVar1 + 8;
      } while (uVar1 < 0x70);
    }
    FUN_004cd180(0);
  }
  return;
}


// ==== 0x4bf610 FUN_004bf610

void __thiscall FUN_004bf610(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_2 != -0x6edfbf62) && (param_2 != -0x4a68e40f)) {
    return;
  }
  if (DAT_0078a320 != 1) {
    if ((DAT_0078a3f7 != '\x05') && ((param_2 == -0x6edfbf62 || (param_2 == -0x4a68e40f)))) {
      if (DAT_0078a3f7 == '\a') {
        DAT_0078a3f7 = '\x06';
      }
      else if (DAT_0078a3f7 == '\x06') {
        DAT_0078a3f7 = '\a';
      }
    }
    goto LAB_004bf718;
  }
  iVar1 = (int)DAT_0078a3f6;
  if (iVar1 == 5) goto LAB_004bf718;
  if (param_2 == -0x6edfbf62) {
    if (iVar1 == 1) {
LAB_004bf6cd:
      iVar1 = 3;
    }
    else {
      if (iVar1 == 3) {
        *(undefined4 *)(param_1 + 0x44) = 6;
        DAT_0078a3f6 = '\x06';
        DAT_007588ec = 6;
        goto LAB_004bf718;
      }
      if (iVar1 == 6) {
        *(undefined4 *)(param_1 + 0x44) = 1;
        DAT_0078a3f6 = '\x01';
        DAT_007588ec = 1;
        goto LAB_004bf718;
      }
    }
  }
  else if (param_2 == -0x4a68e40f) {
    if (iVar1 == 1) {
      *(undefined4 *)(param_1 + 0x44) = 6;
      DAT_0078a3f6 = '\x06';
      DAT_007588ec = 6;
      goto LAB_004bf718;
    }
    if (iVar1 == 3) {
      *(undefined4 *)(param_1 + 0x44) = 1;
      DAT_0078a3f6 = '\x01';
      DAT_007588ec = 1;
      goto LAB_004bf718;
    }
    if (iVar1 == 6) goto LAB_004bf6cd;
  }
  *(int *)(param_1 + 0x44) = iVar1;
  DAT_0078a3f6 = (char)iVar1;
  DAT_007588ec = iVar1;
LAB_004bf718:
  FUN_004bf380();
  if (param_2 == -0x6edfbf62) {
    uVar3 = 10;
  }
  else {
    uVar3 = (param_2 != -0x4a68e40f) - 1 & 0xb;
  }
  if ((&DAT_006f8a48)[uVar3 * 2] != uVar3) {
    uVar2 = 0;
    do {
      if (*(uint *)((int)&DAT_006f8a48 + uVar2) == uVar3) break;
      uVar2 = uVar2 + 8;
    } while (uVar2 < 0x70);
  }
  FUN_004cd180(0);
  return;
}


// ==== 0x4bf770 FUN_004bf770

void FUN_004bf770(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FEngFindPackage();
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x1c) = 0;
  }
  if (DAT_0073578c != 0) {
    iVar1 = *(int *)(DAT_0073578c + 8);
    iVar2 = iVar1 + 0xdc;
    if ((iVar2 == 0) || (iVar2 = FUN_004fd1e0(iVar2), iVar2 == 0)) {
      cFEng__PushPackage(iVar1,"PC_Customize_Graphics.fng",0x42,0xff);
    }
  }
  return;
}


// ==== 0x4bf7d0 FUN_004bf7d0

void __fastcall FUN_004bf7d0(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x1b8));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x1b8));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  return;
}


// ==== 0x4bf8c0 FUN_004bf8c0

void __fastcall FUN_004bf8c0(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x1bc));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x1bc));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  return;
}


// ==== 0x4bf9b0 FUN_004bf9b0

void __fastcall FUN_004bf9b0(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x1c0));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x1c0));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  return;
}


// ==== 0x4bfaa0 FUN_004bfaa0

void __fastcall FUN_004bfaa0(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_007361b4 == 0) {
    iVar2 = -1;
  }
  else {
    iVar2 = *(int *)(DAT_007361b4 + 8);
  }
  if (*(int *)(DAT_007361f0 + 0x1c) == iVar2) {
    uVar1 = 0;
  }
  else {
    if (DAT_007361b8 == 0) {
      iVar2 = -1;
    }
    else {
      iVar2 = *(int *)(DAT_007361b8 + 8);
    }
    uVar1 = (uint)(*(int *)(DAT_007361f0 + 0x1c) == iVar2);
  }
  iVar2 = (&DAT_007361b4)[uVar1];
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x1c4));
  iVar3 = LanguageStrings__FindByHash();
  if (iVar3 == 0) {
    iVar3 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar3);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x1c4));
  switch(*(undefined1 *)(iVar2 + 0x26)) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  default:
    goto switchD_004bfb55_default;
  }
  iVar2 = LanguageStrings__FindByHash();
  if (iVar2 == 0) {
    iVar2 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar2);
switchD_004bfb55_default:
  return;
}


// ==== 0x4bfbc0 FUN_004bfbc0

void __fastcall FUN_004bfbc0(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x1c8));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x1c8));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  return;
}


// ==== 0x4bfcb0 FUN_004bfcb0

void FUN_004bfcb0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if ((param_1 == -0x6edfbf62) || (param_1 == -0x4a68e40f)) {
    iVar1 = FUN_004cd610();
    iVar1 = (&DAT_007361b4)[iVar1];
    uVar2 = *(uint *)(iVar1 + 0x30);
    if ((uVar2 & 0x10) == 0) {
      uVar2 = uVar2 | 0x10;
    }
    else {
      uVar2 = uVar2 & 0xffffffef;
    }
    *(uint *)(iVar1 + 0x30) = uVar2;
    uVar2 = (&DAT_0078a394)[*(int *)(iVar1 + 0x10) * 0xe];
    if ((uVar2 & 0x10) == 0) {
      uVar2 = uVar2 | 0x10;
    }
    else {
      uVar2 = uVar2 & 0xffffffef;
    }
    (&DAT_0078a394)[*(int *)(iVar1 + 0x10) * 0xe] = uVar2;
    iVar3 = FUN_004cd610();
    if (iVar3 == 0) {
      DAT_007588d8 = (byte)(*(uint *)(iVar1 + 0x30) >> 4) & 1;
    }
    else {
      DAT_007588d9 = (byte)(*(uint *)(iVar1 + 0x30) >> 4) & 1;
    }
    FUN_004bf7d0();
    if (param_1 == -0x6edfbf62) {
      uVar2 = 10;
    }
    else {
      uVar2 = (param_1 != -0x4a68e40f) - 1 & 0xb;
    }
    if ((&DAT_006f8a48)[uVar2 * 2] != uVar2) {
      uVar4 = 0;
      do {
        if (*(uint *)((int)&DAT_006f8a48 + uVar4) == uVar2) break;
        uVar4 = uVar4 + 8;
      } while (uVar4 < 0x70);
    }
    FUN_004cd180(0);
  }
  return;
}


// ==== 0x4bfd90 FUN_004bfd90

void FUN_004bfd90(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if ((param_1 == -0x6edfbf62) || (param_1 == -0x4a68e40f)) {
    iVar1 = FUN_004cd610();
    iVar1 = (&DAT_007361b4)[iVar1];
    uVar2 = *(uint *)(iVar1 + 0x30);
    if ((uVar2 & 0x100) == 0) {
      uVar2 = uVar2 | 0x100;
    }
    else {
      uVar2 = uVar2 & 0xfffffeff;
    }
    *(uint *)(iVar1 + 0x30) = uVar2;
    uVar2 = (&DAT_0078a394)[*(int *)(iVar1 + 0x10) * 0xe];
    if ((uVar2 & 0x100) == 0) {
      uVar2 = uVar2 | 0x100;
    }
    else {
      uVar2 = uVar2 & 0xfffffeff;
    }
    (&DAT_0078a394)[*(int *)(iVar1 + 0x10) * 0xe] = uVar2;
    iVar3 = FUN_004cd610();
    if (iVar3 == 0) {
      DAT_007588da = (byte)((uint)*(undefined4 *)(iVar1 + 0x30) >> 8) & 1;
    }
    else {
      DAT_007588db = (byte)((uint)*(undefined4 *)(iVar1 + 0x30) >> 8) & 1;
    }
    FUN_004bf8c0();
    if (param_1 == -0x6edfbf62) {
      uVar2 = 10;
    }
    else {
      uVar2 = (param_1 != -0x4a68e40f) - 1 & 0xb;
    }
    if ((&DAT_006f8a48)[uVar2 * 2] != uVar2) {
      uVar4 = 0;
      do {
        if (*(uint *)((int)&DAT_006f8a48 + uVar4) == uVar2) break;
        uVar4 = uVar4 + 8;
      } while (uVar4 < 0x70);
    }
    FUN_004cd180(0);
  }
  return;
}


// ==== 0x4bfe70 FUN_004bfe70

void FUN_004bfe70(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_1 == -0x6edfbf62) || (param_1 == -0x4a68e40f)) {
    iVar1 = FUN_004cd610();
    iVar1 = (&DAT_007361b4)[iVar1];
    if (iVar1 != 0) {
      uVar3 = *(uint *)(iVar1 + 0x30);
      if ((uVar3 & 0x200) == 0) {
        uVar3 = uVar3 | 0x200;
      }
      else {
        uVar3 = uVar3 & 0xfffffdff;
      }
      *(uint *)(iVar1 + 0x30) = uVar3;
      uVar3 = (&DAT_0078a394)[*(int *)(iVar1 + 0x10) * 0xe];
      if ((uVar3 & 0x200) == 0) {
        uVar3 = uVar3 | 0x200;
      }
      else {
        uVar3 = uVar3 & 0xfffffdff;
      }
      (&DAT_0078a394)[*(int *)(iVar1 + 0x10) * 0xe] = uVar3;
    }
    DAT_007588d5 = (byte)(*(uint *)(iVar1 + 0x30) >> 9) & 1;
    FUN_004bf9b0();
    if (param_1 == -0x6edfbf62) {
      uVar3 = 10;
    }
    else {
      uVar3 = (param_1 != -0x4a68e40f) - 1 & 0xb;
    }
    if ((&DAT_006f8a48)[uVar3 * 2] != uVar3) {
      uVar2 = 0;
      do {
        if (*(uint *)((int)&DAT_006f8a48 + uVar2) == uVar3) break;
        uVar2 = uVar2 + 8;
      } while (uVar2 < 0x70);
    }
    FUN_004cd180(0);
  }
  return;
}


// ==== 0x4bff40 FUN_004bff40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bff40(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if ((param_1 != -0x6edfbf62) && (param_1 != -0x4a68e40f)) {
    return;
  }
  iVar1 = FUN_004cd610();
  iVar1 = (&DAT_007361b4)[iVar1];
  if (param_1 == -0x6edfbf62) {
    iVar2 = *(char *)(iVar1 + 0x26) + -1;
    if (iVar2 < 0) {
      iVar2 = 4;
    }
    else if (4 < iVar2) {
      iVar2 = 0;
    }
    *(char *)(iVar1 + 0x26) = (char)iVar2;
    if ((char)iVar2 == '\x04') {
      uVar3 = *(uint *)(iVar1 + 0x30) & 0xfffffffb;
    }
    else {
      uVar3 = *(uint *)(iVar1 + 0x30) | 4;
    }
    *(uint *)(iVar1 + 0x30) = uVar3;
    iVar2 = *(int *)(iVar1 + 0x10) * 0x38;
    iVar5 = (char)(&DAT_0078a38a)[iVar2] + -1;
  }
  else {
    if (param_1 != -0x4a68e40f) goto LAB_004c001c;
    iVar2 = *(char *)(iVar1 + 0x26) + 1;
    if (iVar2 < 0) {
      iVar2 = 4;
    }
    else if (4 < iVar2) {
      iVar2 = 0;
    }
    *(char *)(iVar1 + 0x26) = (char)iVar2;
    if ((char)iVar2 == '\x04') {
      uVar3 = *(uint *)(iVar1 + 0x30) & 0xfffffffb;
    }
    else {
      uVar3 = *(uint *)(iVar1 + 0x30) | 4;
    }
    *(uint *)(iVar1 + 0x30) = uVar3;
    iVar2 = *(int *)(iVar1 + 0x10) * 0x38;
    iVar5 = (char)(&DAT_0078a38a)[iVar2] + 1;
  }
  if (iVar5 < 0) {
    iVar5 = 4;
  }
  else if (4 < iVar5) {
    iVar5 = 0;
  }
  (&DAT_0078a38a)[iVar2] = (char)iVar5;
  if ((char)iVar5 == '\x04') {
    uVar3 = *(uint *)((int)&DAT_0078a394 + iVar2) & 0xfffffffb;
  }
  else {
    uVar3 = *(uint *)((int)&DAT_0078a394 + iVar2) | 4;
  }
  *(uint *)((int)&DAT_0078a394 + iVar2) = uVar3;
LAB_004c001c:
  iVar2 = FUN_004cd610();
  if (iVar2 == 0) {
    _DAT_007588e4 = (int)*(char *)(iVar1 + 0x26);
  }
  else {
    _DAT_007588e8 = (int)*(char *)(iVar1 + 0x26);
  }
  FUN_004bfaa0();
  if (param_1 == -0x6edfbf62) {
    uVar3 = 10;
  }
  else {
    uVar3 = (param_1 != -0x4a68e40f) - 1 & 0xb;
  }
  if ((&DAT_006f8a48)[uVar3 * 2] != uVar3) {
    uVar4 = 0;
    do {
      if (*(uint *)((int)&DAT_006f8a48 + uVar4) == uVar3) break;
      uVar4 = uVar4 + 8;
    } while (uVar4 < 0x70);
  }
  FUN_004cd180(0);
  return;
}


// ==== 0x4c0000 FUN_004c0000

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004c0000(int param_1,uint param_2)

{
  int in_EAX;
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  int unaff_EDI;
  uint uVar3;
  
  if (4 < param_1) {
    param_1 = 0;
  }
  *(char *)(in_EAX + 6) = (char)param_1;
  if ((char)param_1 == '\x04') {
    param_2 = *(uint *)(in_EAX + 0x10) & param_2;
  }
  else {
    param_2 = *(uint *)(in_EAX + 0x10) | 4;
  }
  *(uint *)(in_EAX + 0x10) = param_2;
  iVar1 = FUN_004cd610();
  if (iVar1 == 0) {
    _DAT_007588e4 = (int)*(char *)(unaff_ESI + 0x26);
  }
  else {
    _DAT_007588e8 = (int)*(char *)(unaff_ESI + 0x26);
  }
  FUN_004bfaa0();
  if (unaff_EDI == -0x6edfbf62) {
    uVar3 = 10;
  }
  else {
    uVar3 = (unaff_EDI != -0x4a68e40f) - 1 & 0xb;
  }
  if ((&DAT_006f8a48)[uVar3 * 2] != uVar3) {
    uVar2 = 0;
    do {
      if (*(uint *)((int)&DAT_006f8a48 + uVar2) == uVar3) break;
      uVar2 = uVar2 + 8;
    } while (uVar2 < 0x70);
  }
  FUN_004cd180();
  return;
}


// ==== 0x4c005d FUN_004c005d

void __fastcall FUN_004c005d(undefined4 param_1,uint param_2)

{
  uint uVar1;
  
  param_2 = param_2 & 0xb;
  if ((&DAT_006f8a48)[param_2 * 2] != param_2) {
    uVar1 = 0;
    do {
      if (*(uint *)((int)&DAT_006f8a48 + uVar1) == param_2) break;
      uVar1 = uVar1 + 8;
    } while (uVar1 < 0x70);
  }
  FUN_004cd180(0);
  return;
}


// ==== 0x4c006c FUN_004c006c

void FUN_004c006c(void)

{
  uint uVar1;
  int unaff_EDI;
  bool in_ZF;
  
  if (!in_ZF) {
    uVar1 = 0;
    do {
      if (*(int *)((int)&DAT_006f8a48 + uVar1) == unaff_EDI) break;
      uVar1 = uVar1 + 8;
    } while (uVar1 < 0x70);
  }
  FUN_004cd180(0);
  return;
}


// ==== 0x4c0090 FUN_004c0090

void FUN_004c0090(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  if ((param_1 == -0x6edfbf62) || (param_1 == -0x4a68e40f)) {
    iVar2 = FUN_004cd610();
    iVar2 = (&DAT_007361b4)[iVar2];
    uVar3 = (uint)(*(int *)(iVar2 + 0x50) == 0);
    *(uint *)(iVar2 + 0x50) = uVar3;
    if (uVar3 == 0) {
      uVar3 = *(uint *)(iVar2 + 0x30) ^ 0x400;
    }
    else {
      uVar3 = *(uint *)(iVar2 + 0x30) | 0x400;
    }
    *(uint *)(iVar2 + 0x30) = uVar3;
    iVar4 = *(int *)(iVar2 + 0x10);
    iVar1 = *(int *)(&DAT_0078a3b4 + iVar4 * 0x38);
    *(uint *)(&DAT_0078a3b4 + iVar4 * 0x38) = (uint)(iVar1 == 0);
    if ((iVar1 == 0) == 0) {
      uVar3 = (&DAT_0078a394)[iVar4 * 0xe] ^ 0x400;
    }
    else {
      uVar3 = (&DAT_0078a394)[iVar4 * 0xe] | 0x400;
    }
    (&DAT_0078a394)[iVar4 * 0xe] = uVar3;
    iVar4 = FUN_004cd610();
    if (iVar4 == 0) {
      DAT_007588dc = *(int *)(iVar2 + 0x50) != 0;
    }
    else {
      DAT_007588dd = *(int *)(iVar2 + 0x50) != 0;
    }
    FUN_004bfbc0();
    if (param_1 == -0x6edfbf62) {
      uVar3 = 10;
    }
    else {
      uVar3 = (param_1 != -0x4a68e40f) - 1 & 0xb;
    }
    if ((&DAT_006f8a48)[uVar3 * 2] != uVar3) {
      uVar5 = 0;
      do {
        if (*(uint *)((int)&DAT_006f8a48 + uVar5) == uVar3) break;
        uVar5 = uVar5 + 8;
      } while (uVar5 < 0x70);
    }
    FUN_004cd180(0);
  }
  return;
}


// ==== 0x4c0180 FUN_004c0180

void __fastcall FUN_004c0180(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  if (DAT_007361b4 == 0) {
    iVar3 = -1;
  }
  else {
    iVar3 = *(int *)(DAT_007361b4 + 8);
  }
  if (*(int *)(DAT_007361f0 + 0x1c) == iVar3) {
    uVar2 = 0;
  }
  else {
    if (DAT_007361b8 == 0) {
      iVar3 = -1;
    }
    else {
      iVar3 = *(int *)(DAT_007361b8 + 8);
    }
    uVar2 = (uint)(*(int *)(DAT_007361f0 + 0x1c) == iVar3);
  }
  uVar1 = *(undefined4 *)(*(int *)(*(int *)((&DAT_007361b4)[uVar2] + 4) + 0x10) + 0x18);
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x1cc));
  FEngPrintf("NOS Level (requires race restart):");
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x1cc));
  switch(uVar1) {
  case 0:
    puVar4 = &DAT_006ca910;
    break;
  case 1:
    puVar4 = &DAT_006c59e8;
    break;
  case 2:
    puVar4 = &DAT_006c59e4;
    break;
  case 3:
    puVar4 = &DAT_006c59e0;
    break;
  default:
    goto switchD_004c0221_default;
  }
  FEngPrintf(puVar4);
switchD_004c0221_default:
  return;
}


// ==== 0x4c0270 FUN_004c0270

void __fastcall FUN_004c0270(int param_1)

{
  int iVar1;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x1b4));
  FEngPrintf("Fullscreen TrackMap");
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x1b4));
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  return;
}


// ==== 0x4c0300 FUN_004c0300

void __fastcall FUN_004c0300(int param_1)

{
  char *pcVar1;
  
  if ((DAT_0073619c == (int *)0x0) || (*DAT_0073619c != 4)) {
    bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x1d4));
    pcVar1 = "Please Wait for Race Start!";
  }
  else {
    bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x1d4));
    pcVar1 = "Force Race Finish";
  }
  FEngPrintf(pcVar1);
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x1d4));
  FEngPrintf(&DAT_006ca778,*(undefined4 *)(param_1 + 0x1ec));
  return;
}


// ==== 0x4c03b0 FUN_004c03b0

void __fastcall FUN_004c03b0(int param_1)

{
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x1d8));
  FEngPrintf("Display Debug Info");
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x1d8));
  FEngPrintf(&DAT_006ca778,DAT_00734964);
  return;
}


// ==== 0x4c0420 FUN_004c0420

void __fastcall FUN_004c0420(int param_1)

{
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x1dc));
  FEngPrintf("Debug Cameras");
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x1dc));
  FEngPrintf(&DAT_006ca778,DAT_0073495c);
  return;
}


// ==== 0x4c0490 FUN_004c0490

void __fastcall FUN_004c0490(int param_1)

{
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x1e0));
  FEngPrintf("Super Easy AI");
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x1e0));
  FEngPrintf(&DAT_006ca778,DAT_007360b8);
  return;
}


// ==== 0x4c0500 FUN_004c0500

void __fastcall FUN_004c0500(int param_1)

{
  uint uVar1;
  int iVar2;
  
  bSPrintf_regdst(0x20,"%s%1d",param_1 + 0x21d,*(undefined4 *)(param_1 + 0x1e4));
  FEngPrintf("Set Lap");
  if (DAT_007361b4 == 0) {
    iVar2 = -1;
  }
  else {
    iVar2 = *(int *)(DAT_007361b4 + 8);
  }
  if (*(int *)(DAT_007361f0 + 0x1c) == iVar2) {
    uVar1 = 0;
  }
  else {
    if (DAT_007361b8 == 0) {
      iVar2 = -1;
    }
    else {
      iVar2 = *(int *)(DAT_007361b8 + 8);
    }
    uVar1 = (uint)(*(int *)(DAT_007361f0 + 0x1c) == iVar2);
  }
  iVar2 = *(int *)(*(int *)((&DAT_007361b4)[uVar1] + 4) + 0x1c);
  if ((DAT_0073619c != (int *)0x0) && (*DAT_0073619c == 4)) {
    if (DAT_0073619c[0x14c] + -1 < *(int *)(param_1 + 0x1e8)) {
      *(int *)(param_1 + 0x1e8) = DAT_0073619c[0x14c] + -1;
    }
    iVar2 = (int)*(char *)(iVar2 + 9);
    if (*(int *)(param_1 + 0x1e8) < iVar2) {
      *(int *)(param_1 + 0x1e8) = iVar2;
    }
  }
  bSPrintf_regdst(0x20,"OptionData_%1d",*(undefined4 *)(param_1 + 0x1e4));
  FEngPrintf(&DAT_006ca778,*(int *)(param_1 + 0x1e8) + 1);
  return;
}


// ==== 0x4c0600 FUN_004c0600

void FUN_004c0600(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_1 == -0x6edfbf62) || (param_1 == -0x4a68e40f)) {
    iVar1 = FUN_004cd610();
    iVar1 = *(int *)(*(int *)((&DAT_007361b4)[iVar1] + 4) + 0x10);
    iVar2 = *(int *)(iVar1 + 0x18);
    if (param_1 == -0x6edfbf62) {
      iVar2 = iVar2 + -1;
      if (iVar2 < 0) {
        iVar2 = 3;
      }
    }
    else if ((param_1 == -0x4a68e40f) && (iVar2 = iVar2 + 1, 3 < iVar2)) {
      iVar2 = 0;
    }
    *(int *)(iVar1 + 0x18) = iVar2;
    FUN_004c0180();
    if (param_1 == -0x6edfbf62) {
      uVar4 = 10;
    }
    else {
      uVar4 = (param_1 != -0x4a68e40f) - 1 & 0xb;
    }
    if ((&DAT_006f8a48)[uVar4 * 2] != uVar4) {
      uVar3 = 0;
      do {
        if (*(uint *)((int)&DAT_006f8a48 + uVar3) == uVar4) break;
        uVar3 = uVar3 + 8;
      } while (uVar3 < 0x70);
    }
    FUN_004cd180(0);
  }
  return;
}


// ==== 0x4c06b0 FUN_004c06b0

void __thiscall FUN_004c06b0(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  if ((param_2 == -0x6edfbf62) || (param_2 == -0x4a68e40f)) {
    bVar3 = *(char *)(param_1 + 0x40) == '\0';
    *(bool *)(param_1 + 0x40) = bVar3;
    if (bVar3) {
      DAT_0078a3f6 = 5;
    }
    else {
      DAT_0078a3f6 = *(undefined1 *)(param_1 + 0x44);
    }
    FUN_004c0270();
    if (param_2 == -0x6edfbf62) {
      uVar2 = 10;
    }
    else {
      uVar2 = (param_2 != -0x4a68e40f) - 1 & 0xb;
    }
    if ((&DAT_006f8a48)[uVar2 * 2] != uVar2) {
      uVar1 = 0;
      do {
        if (*(uint *)((int)&DAT_006f8a48 + uVar1) == uVar2) break;
        uVar1 = uVar1 + 8;
      } while (uVar1 < 0x70);
    }
    FUN_004cd180(0);
  }
  return;
}


// ==== 0x4c0740 FUN_004c0740

void FUN_004c0740(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_1 == -0x6edfbf62) || (param_1 == -0x4a68e40f)) {
    DAT_00734964 = (uint)(DAT_00734964 == 0);
    FUN_004c03b0();
    if (param_1 == -0x6edfbf62) {
      uVar2 = 10;
    }
    else {
      uVar2 = (param_1 != -0x4a68e40f) - 1 & 0xb;
    }
    if ((&DAT_006f8a48)[uVar2 * 2] != uVar2) {
      uVar1 = 0;
      do {
        if (*(uint *)((int)&DAT_006f8a48 + uVar1) == uVar2) break;
        uVar1 = uVar1 + 8;
      } while (uVar1 < 0x70);
    }
    FUN_004cd180(0);
  }
  return;
}


// ==== 0x4c07c0 FUN_004c07c0

void FUN_004c07c0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_1 == -0x6edfbf62) || (param_1 == -0x4a68e40f)) {
    DAT_0073495c = (uint)(DAT_0073495c == 0);
    FUN_004c0420();
    if (param_1 == -0x6edfbf62) {
      uVar2 = 10;
    }
    else {
      uVar2 = (param_1 != -0x4a68e40f) - 1 & 0xb;
    }
    if ((&DAT_006f8a48)[uVar2 * 2] != uVar2) {
      uVar1 = 0;
      do {
        if (*(uint *)((int)&DAT_006f8a48 + uVar1) == uVar2) break;
        uVar1 = uVar1 + 8;
      } while (uVar1 < 0x70);
    }
    FUN_004cd180(0);
  }
  return;
}


// ==== 0x4c0840 FUN_004c0840

void FUN_004c0840(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_1 == -0x6edfbf62) || (param_1 == -0x4a68e40f)) {
    DAT_007360b8 = (uint)(DAT_007360b8 == 0);
    FUN_004c0490();
    if (param_1 == -0x6edfbf62) {
      uVar2 = 10;
    }
    else {
      uVar2 = (param_1 != -0x4a68e40f) - 1 & 0xb;
    }
    if ((&DAT_006f8a48)[uVar2 * 2] != uVar2) {
      uVar1 = 0;
      do {
        if (*(uint *)((int)&DAT_006f8a48 + uVar1) == uVar2) break;
        uVar1 = uVar1 + 8;
      } while (uVar1 < 0x70);
    }
    FUN_004cd180(0);
  }
  return;
}


// ==== 0x4c08c0 FUN_004c08c0

void __thiscall FUN_004c08c0(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = DAT_0073619c;
  if (DAT_007361b4 == 0) {
    iVar3 = -1;
  }
  else {
    iVar3 = *(int *)(DAT_007361b4 + 8);
  }
  if (*(int *)(DAT_007361f0 + 0x1c) == iVar3) {
    uVar2 = 0;
  }
  else {
    if (DAT_007361b8 == 0) {
      iVar3 = -1;
    }
    else {
      iVar3 = *(int *)(DAT_007361b8 + 8);
    }
    uVar2 = (uint)(*(int *)(DAT_007361f0 + 0x1c) == iVar3);
  }
  iVar3 = *(int *)(*(int *)((&DAT_007361b4)[uVar2] + 4) + 0x1c);
  if ((DAT_0073619c != (int *)0x0) && (*DAT_0073619c == 4)) {
    if (param_2 == -0x6edfbf62) {
      iVar4 = *(int *)(param_1 + 0x1e8) + -1;
      *(int *)(param_1 + 0x1e8) = iVar4;
      if (iVar4 < *(char *)(iVar3 + 9)) {
        *(int *)(param_1 + 0x1e8) = piVar1[0x14c] + -1;
        FUN_004c0500();
        return;
      }
    }
    else if (param_2 == -0x4a68e40f) {
      iVar4 = *(int *)(param_1 + 0x1e8) + 1;
      *(int *)(param_1 + 0x1e8) = iVar4;
      if (piVar1[0x14c] + -1 < iVar4) {
        *(int *)(param_1 + 0x1e8) = (int)*(char *)(iVar3 + 9);
        FUN_004c0500();
        return;
      }
    }
    else if (param_2 == 0xc407210) {
      HudMeter__SetLevel(*(undefined4 *)(param_1 + 0x1e8));
    }
  }
  FUN_004c0500();
  return;
}


// ==== 0x4c09b0 FUN_004c09b0

void __thiscall FUN_004c09b0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((DAT_0073619c != (int *)0x0) && (*DAT_0073619c == 4)) {
    iVar1 = DAT_0073619c[9];
    if ((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) {
      iVar1 = 4;
    }
    if (param_2 == -0x6edfbf62) {
      iVar3 = *(int *)(param_1 + 0x1ec) + -1;
      *(int *)(param_1 + 0x1ec) = iVar3;
      if (iVar3 < 1) {
        *(int *)(param_1 + 0x1ec) = iVar1;
        FUN_004c0300();
        return;
      }
    }
    else if (param_2 == -0x4a68e40f) {
      iVar3 = *(int *)(param_1 + 0x1ec) + 1;
      *(int *)(param_1 + 0x1ec) = iVar3;
      if (iVar1 < iVar3) {
        *(undefined4 *)(param_1 + 0x1ec) = 1;
        FUN_004c0300();
        return;
      }
    }
    else if (param_2 == 0xc407210) {
      uVar2 = FUN_004cd610();
      FUN_00572a90(DAT_007345d0,uVar2);
      FEngQueuePackagePop(*(undefined4 *)(param_1 + 0xc));
      FEngQueuePackagePop("MU_PauseOptionsSelector.fng");
      FUN_00421c00(DAT_007361f0,6,1);
    }
    FUN_004c0300();
  }
  return;
}


// ==== 0x4c0aa0 FUN_004c0aa0

void FUN_004c0aa0(void)

{
  int iVar1;
  char *pcVar2;
  
  switch(DAT_00777cb8) {
  case 0:
    pcVar2 = "MU_PAUSE_AUDIO";
    break;
  case 1:
    pcVar2 = "MU_PAUSE_CAMERA";
    break;
  case 2:
    pcVar2 = "MU_PAUSE_CAR";
    break;
  case 3:
    pcVar2 = "MU_PAUSE_CONTROLLER";
    break;
  case 4:
    pcVar2 = "MU_PAUSE_DISPLAY";
    break;
  case 5:
    pcVar2 = "MU_PAUSE_HUD";
    break;
  case 6:
    pcVar2 = "MU_PAUSE_TRAX";
    break;
  case 7:
    pcVar2 = "MU_PAUSE_DEBUG";
    break;
  default:
    pcVar2 = "LANGUAGE_MU_PAUSE_";
  }
  bSPrintf_regdst(0x20,pcVar2);
  FEng__HashName();
  iVar1 = LanguageStrings__FindByHash();
  if (iVar1 == 0) {
    iVar1 = LanguageStrings__FindByHash();
  }
  FEngPrintf(iVar1);
  return;
}


// ==== 0x4c0b60 FUN_004c0b60

void FUN_004c0b60(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int *piVar7;
  int iVar8;
  int local_24;
  byte local_20;
  byte local_1f [31];
  
  local_24 = 1;
  do {
    bSPrintf_regdst(0x20,"OptionData_%d",local_24);
    iVar8 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004c0c23:
      if (iVar5 == 0) {
LAB_004c0c34:
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
        if (DAT_0073578c != 0) {
          iVar4 = *(int *)(DAT_0073578c + 8);
          if ((iVar4 == 0) ||
             ((iVar3 = FUN_004fd1e0(iVar4 + 0xdc), iVar3 == 0 &&
              (iVar3 = FUN_004fd1e0(iVar4 + 0xec), iVar3 == 0)))) goto LAB_004c0c23;
          goto LAB_004c0c0c;
        }
        goto LAB_004c0c34;
      }
LAB_004c0c0c:
      if ((iVar3 == 0) || (iVar3 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar3 == 0))
      goto LAB_004c0c23;
    }
    FEObject__SetInvisible(iVar3);
    bSPrintf_regdst(0x20,"OptionName_%d",local_24);
    iVar8 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004c0cfb:
      iVar3 = 0;
      if (iVar5 == 0) {
LAB_004c0d12:
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004ef050(iVar8);
        iVar3 = DAT_0073578c;
      }
    }
    else {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
        iVar3 = DAT_0073578c;
        if (DAT_0073578c != 0) {
          iVar4 = *(int *)(DAT_0073578c + 8);
          if ((iVar4 == 0) ||
             ((iVar3 = FUN_004fd1e0(iVar4 + 0xdc), iVar3 == 0 &&
              (iVar3 = FUN_004fd1e0(iVar4 + 0xec), iVar3 == 0)))) goto LAB_004c0cfb;
          goto LAB_004c0cdc;
        }
        goto LAB_004c0d12;
      }
LAB_004c0cdc:
      if ((iVar3 == 0) ||
         (iVar4 = FUN_004ffb70(), iVar3 = DAT_0073578c, iVar5 = DAT_0073578c, iVar4 == 0))
      goto LAB_004c0cfb;
    }
    FEObject__SetInvisible(iVar4);
    iVar8 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    if (((iVar3 != 0) && (iVar5 = FEPackageList__FindByName(&DAT_00746104), iVar5 != 0)) &&
       (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
      iVar3 = *(int *)(iVar5 + 0x88);
      iVar4 = 0;
      if (iVar3 != 0) {
        piVar7 = *(int **)(iVar5 + 0x84);
        do {
          if (*(int *)(*piVar7 + 0x10) == iVar8) {
            iVar4 = *piVar7;
          }
          piVar7 = piVar7 + 1;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
        if (iVar4 != 0) {
          *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x4000000;
        }
      }
    }
    bSPrintf_regdst(0x20,"LeftArrow_%d",local_24);
    iVar8 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004c0e47:
      if (iVar5 == 0) {
LAB_004c0e58:
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
        if (DAT_0073578c != 0) {
          iVar4 = *(int *)(DAT_0073578c + 8);
          if ((iVar4 == 0) ||
             ((iVar3 = FUN_004fd1e0(iVar4 + 0xdc), iVar3 == 0 &&
              (iVar3 = FUN_004fd1e0(iVar4 + 0xec), iVar3 == 0)))) goto LAB_004c0e47;
          goto LAB_004c0e30;
        }
        goto LAB_004c0e58;
      }
LAB_004c0e30:
      if ((iVar3 == 0) || (iVar3 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar3 == 0))
      goto LAB_004c0e47;
    }
    FEObject__SetInvisible(iVar3);
    bSPrintf_regdst(0x20,"RightArrow_%d",local_24);
    iVar8 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004c0f13:
      if (iVar5 == 0) {
LAB_004c0f24:
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
        if (DAT_0073578c != 0) {
          iVar4 = *(int *)(DAT_0073578c + 8);
          if ((iVar4 == 0) ||
             ((iVar3 = FUN_004fd1e0(iVar4 + 0xdc), iVar3 == 0 &&
              (iVar3 = FUN_004fd1e0(iVar4 + 0xec), iVar3 == 0)))) goto LAB_004c0f13;
          goto LAB_004c0efc;
        }
        goto LAB_004c0f24;
      }
LAB_004c0efc:
      if ((iVar3 == 0) || (iVar3 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar3 == 0))
      goto LAB_004c0f13;
    }
    FEObject__SetInvisible(iVar3);
    bSPrintf_regdst(0x20,"OptionNametext_%d",local_24);
    iVar8 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004c0fe3:
      if (iVar5 == 0) {
LAB_004c0ff4:
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
        if (DAT_0073578c != 0) {
          iVar4 = *(int *)(DAT_0073578c + 8);
          if ((iVar4 == 0) ||
             ((iVar3 = FUN_004fd1e0(iVar4 + 0xdc), iVar3 == 0 &&
              (iVar3 = FUN_004fd1e0(iVar4 + 0xec), iVar3 == 0)))) goto LAB_004c0fe3;
          goto LAB_004c0fcc;
        }
        goto LAB_004c0ff4;
      }
LAB_004c0fcc:
      if ((iVar3 == 0) || (iVar3 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar3 == 0))
      goto LAB_004c0fe3;
    }
    FEObject__SetInvisible(iVar3);
    bSPrintf_regdst(0x20,"option_buttonR_%02d",local_24);
    iVar8 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004c10b3:
      if (iVar5 == 0) {
LAB_004c10c4:
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
        if (DAT_0073578c != 0) {
          iVar4 = *(int *)(DAT_0073578c + 8);
          if ((iVar4 == 0) ||
             ((iVar3 = FUN_004fd1e0(iVar4 + 0xdc), iVar3 == 0 &&
              (iVar3 = FUN_004fd1e0(iVar4 + 0xec), iVar3 == 0)))) goto LAB_004c10b3;
          goto LAB_004c109c;
        }
        goto LAB_004c10c4;
      }
LAB_004c109c:
      if ((iVar3 == 0) || (iVar3 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar3 == 0))
      goto LAB_004c10b3;
    }
    FEObject__SetInvisible(iVar3);
    bSPrintf_regdst(0x20,"option_buttonL_%02d",local_24);
    iVar8 = -1;
    pbVar6 = &local_20;
    bVar2 = local_20;
    while (bVar2 != 0) {
      if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
        bVar2 = bVar2 - 0x20;
      }
      pbVar1 = pbVar6 + 1;
      iVar8 = iVar8 * 0x21 + (uint)bVar2;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
    }
    iVar5 = DAT_0073578c;
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_004c1186:
      if (iVar5 == 0) {
LAB_004c1197:
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004ef050(iVar8);
      }
    }
    else {
      iVar3 = FEPackageList__FindByName(&DAT_00746104);
      iVar5 = DAT_0073578c;
      if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
        if (DAT_0073578c != 0) {
          iVar4 = *(int *)(DAT_0073578c + 8);
          if ((iVar4 == 0) ||
             ((iVar3 = FUN_004fd1e0(iVar4 + 0xdc), iVar3 == 0 &&
              (iVar3 = FUN_004fd1e0(iVar4 + 0xec), iVar3 == 0)))) goto LAB_004c1186;
          goto LAB_004c116f;
        }
        goto LAB_004c1197;
      }
LAB_004c116f:
      if ((iVar3 == 0) || (iVar3 = FUN_004ffb70(), iVar5 = DAT_0073578c, iVar3 == 0))
      goto LAB_004c1186;
    }
    FEObject__SetInvisible(iVar3);
    if (local_24 < 4) {
      bSPrintf_regdst(0x20,"minus_%02d",local_24);
      iVar8 = -1;
      pbVar6 = &local_20;
      bVar2 = local_20;
      while (bVar2 != 0) {
        if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
          bVar2 = bVar2 - 0x20;
        }
        iVar8 = iVar8 * 0x21 + (uint)bVar2;
        pbVar1 = pbVar6 + 1;
        pbVar6 = pbVar6 + 1;
        bVar2 = *pbVar1;
      }
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
         (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
        if (DAT_0073578c == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_004ef050(iVar8);
        }
      }
      FEObject__SetInvisible(iVar5);
      bSPrintf_regdst(0x20,"plus_%02d",local_24);
      iVar8 = -1;
      pbVar6 = &local_20;
      bVar2 = local_20;
      while (bVar2 != 0) {
        if (('`' < (char)bVar2) && ((char)bVar2 < '{')) {
          bVar2 = bVar2 - 0x20;
        }
        pbVar1 = pbVar6 + 1;
        iVar8 = iVar8 * 0x21 + (uint)bVar2;
        pbVar6 = pbVar6 + 1;
        bVar2 = *pbVar1;
      }
      if (((*(int *)(param_1 + 0xc) == 0) || (iVar5 = FEngFindPackage(), iVar5 == 0)) ||
         (iVar5 = FUN_004ffb70(), iVar5 == 0)) {
        if (DAT_0073578c == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_004ef050(iVar8);
        }
      }
      FEObject__SetInvisible(iVar5);
    }
    local_24 = local_24 + 1;
    if (10 < local_24) {
      (**(code **)(*(int *)(param_1 + 0x70) + 0xc))(0);
      (**(code **)(*(int *)(param_1 + 0xa0) + 0xc))(0);
      (**(code **)(*(int *)(param_1 + 0x100) + 0xc))(0);
      (**(code **)(*(int *)(param_1 + 0xd0) + 0xc))(0);
      (**(code **)(*(int *)(param_1 + 0x130) + 0xc))(0);
      switch(DAT_00777cb8) {
      case 0:
        FUN_004c1b50();
        break;
      case 1:
        FUN_004c1ca0();
        break;
      case 2:
        FUN_004c1dc0();
        break;
      case 3:
        FUN_004c1e80();
        break;
      case 4:
        FUN_004c1ed0();
        break;
      case 5:
        FUN_004c2000();
        break;
      case 6:
        DAT_00777cb8 = 6;
        *(undefined1 *)(param_1 + 0x21c) = 1;
        break;
      case 7:
        FUN_004c24c0();
      }
      FUN_004c0aa0(param_1);
      FUN_004c1500();
      return;
    }
  } while( true );
}


