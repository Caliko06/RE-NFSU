// ==== 0x5117b0 FUN_005117b0

void FUN_005117b0(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  int unaff_EDI;
  
  piVar2 = _malloc(0x14);
  piVar2[2] = param_1;
  piVar2[4] = param_2;
  puVar1 = *(undefined4 **)(in_EAX + 0x48);
  *puVar1 = piVar2;
  *(int **)(in_EAX + 0x48) = piVar2;
  *piVar2 = in_EAX + 0x44;
  piVar2[1] = (int)puVar1;
  iVar3 = FUN_004f8730(in_EAX + 0x4c,piVar2[2],param_3,1);
  if (((unaff_EDI != 0) && (iVar3 != 0)) && (*(int *)(iVar3 + 0x24) != unaff_EDI)) {
    *(int *)(iVar3 + 0x24) = unaff_EDI;
    *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | 0x400000;
  }
  return;
}


// ==== 0x511810 FUN_00511810

void FUN_00511810(void)

{
  int iVar1;
  int in_EAX;
  int unaff_EDI;
  
  iVar1 = *(int *)(in_EAX + 0x40);
  if (unaff_EDI == -0x6edfbf62) {
    if ((iVar1 != *(int *)(in_EAX + 0x44)) && (*(int *)(in_EAX + 0x44) != in_EAX + 0x44)) {
      *(undefined4 *)(in_EAX + 0x40) = *(undefined4 *)(iVar1 + 4);
    }
  }
  else if (((unaff_EDI == -0x4a68e40f) &&
           (*(undefined4 **)(in_EAX + 0x40) != *(undefined4 **)(in_EAX + 0x48))) &&
          (*(int *)(in_EAX + 0x44) != in_EAX + 0x44)) {
    *(undefined4 *)(in_EAX + 0x40) = **(undefined4 **)(in_EAX + 0x40);
  }
  if (iVar1 != *(int *)(in_EAX + 0x40)) {
    FUN_004f8910();
    FUN_005118b0();
    if (unaff_EDI == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(in_EAX + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(in_EAX + 0xc));
  }
  return;
}


// ==== 0x5118b0 FUN_005118b0

void FUN_005118b0(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBX;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int **)(iVar1 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x14) + 8))(0x50fe8c15,0,0,*(int *)(iVar1 + 0x18));
  }
  iVar1 = *(int *)(unaff_EBX + 0x40);
  uVar2 = 0;
  switch(DAT_00735748) {
  case 0:
    uVar2 = 0x1cdd513b;
    break;
  case 1:
    uVar2 = 0x45956ec9;
    break;
  case 2:
    uVar2 = 0x27579dc6;
    break;
  case 3:
    uVar2 = 0x43651cb9;
    break;
  case 4:
    if (DAT_0073574c == 0) {
      uVar2 = 0xd71d9e40;
    }
    else if (DAT_0073574c == 1) {
      uVar2 = 0xd71d9e41;
    }
    break;
  case 5:
    if (DAT_0073574c == 0) {
      uVar2 = 0xa5e5c4f3;
    }
    else if (DAT_0073574c == 1) {
      uVar2 = 0xa5e5c4f4;
    }
    break;
  case 6:
    if (DAT_0073574c == 0) {
      uVar2 = 0x80e2fbe;
    }
    else if (DAT_0073574c == 1) {
      uVar2 = 0x7c8aa0bf;
    }
  }
  FUN_00495f00(uVar2);
  FUN_00495f00(*(undefined4 *)(iVar1 + 0x10));
  return;
}


// ==== 0x5119b0 FUN_005119b0

void __thiscall FUN_005119b0(int param_1,uint param_2)

{
  if (param_2 < 0x9120409f) {
    if (param_2 != 0x9120409e) {
      if (param_2 == 0xc407210) {
        if (*(char *)(*(int *)(param_1 + 0x58) + 0x18) != '\0') {
          return;
        }
        DAT_00735750 = *(undefined4 *)(*(int *)(param_1 + 0x40) + 8);
        GarageManager__PushScreen(*(undefined4 *)(param_1 + 0xc));
        FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 != 0x911ab364) {
        return;
      }
      GarageCategoryVisual__MoveBackPackage(param_1);
      return;
    }
  }
  else if (param_2 != 0xb5971bf1) {
    if (param_2 != 0xc98356ba) {
      return;
    }
    FUN_004f89d0();
    DAT_00735e84 = 1;
    DAT_006fb02c = 0;
    DAT_0074810c = DAT_0073ad3c;
    FUN_004f7d30();
    return;
  }
  FUN_00511810();
  return;
}


// ==== 0x511a70 FUN_00511a70

void __fastcall FUN_00511a70(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c0274;
  return;
}


// ==== 0x511a80 FUN_00511a80

void * __thiscall FUN_00511a80(void *param_1,byte param_2)

{
  FUN_00511a70();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x511aa0 CreateDecalBrandChooseScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 CreateDecalBrandChooseScreen(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688e23;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x94);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GarageDecalsBrand__GarageDecalsBrand(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x511b00 IsBlackDecal

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

bool IsBlackDecal(void)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int unaff_ESI;
  
  pcVar5 = "EXTREMEDIMENSION";
  iVar3 = -1;
  uVar2 = 0x45;
  do {
    iVar3 = iVar3 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  iVar4 = *(int *)(unaff_ESI + 0xc);
  if (iVar4 == iVar3) {
    pcVar5 = "EXTRDIMENSION_BLACK_DECAL";
    iVar3 = -1;
    uVar2 = 0x45;
    do {
      iVar3 = iVar3 * 0x21 + uVar2;
      pbVar1 = (byte *)(pcVar5 + 1);
      uVar2 = (uint)*pbVar1;
      pcVar5 = pcVar5 + 1;
    } while (*pbVar1 != 0);
    return *(int *)(unaff_ESI + 8) == iVar3;
  }
  pcVar5 = "_BLACK_DECAL";
  uVar2 = 0x5f;
  do {
    iVar4 = iVar4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar5 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar5 = pcVar5 + 1;
  } while (*pbVar1 != 0);
  return *(int *)(unaff_ESI + 8) == iVar4;
}


// ==== 0x511b70 IsWhiteDecal

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

bool IsWhiteDecal(void)

{
  byte *pbVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int unaff_EDI;
  
  pcVar6 = "EXTREMEDIMENSION";
  iVar4 = -1;
  uVar2 = 0x45;
  do {
    iVar4 = iVar4 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar6 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar6 = pcVar6 + 1;
  } while (*pbVar1 != 0);
  iVar5 = *(int *)(unaff_EDI + 0xc);
  if (iVar5 == iVar4) {
    pcVar6 = "EXTRDIMENSION_WHITE_DECAL";
    iVar4 = -1;
    uVar2 = 0x45;
    do {
      iVar4 = iVar4 * 0x21 + uVar2;
      pbVar1 = (byte *)(pcVar6 + 1);
      uVar2 = (uint)*pbVar1;
      pcVar6 = pcVar6 + 1;
    } while (*pbVar1 != 0);
    return *(int *)(unaff_EDI + 8) == iVar4;
  }
  puVar3 = &DAT_006c88a0;
  do {
    pcVar6 = puVar3 + 1;
    puVar3 = puVar3 + 1;
  } while (*pcVar6 != '\0');
  pcVar6 = "_WHITE_DECAL";
  uVar2 = 0x5f;
  do {
    iVar5 = iVar5 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar6 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar6 = pcVar6 + 1;
  } while (*pbVar1 != 0);
  return *(int *)(unaff_EDI + 8) == iVar5;
}


// ==== 0x511bf0 BuildDecalList

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void BuildDecalList(int *param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  puVar5 = DAT_0073ad40;
  puVar3 = (undefined4 *)NullUpdate_ret();
  for (; puVar5 != puVar3; puVar5 = (undefined4 *)*puVar5) {
    uVar7 = puVar5[3];
    uVar6 = puVar5[4] * 0x30 + uVar7;
    for (; uVar7 < uVar6; uVar7 = uVar7 + 0x30) {
      if (*(char *)(uVar7 + 0x10) == ':') goto LAB_00511c37;
    }
  }
  uVar7 = 0;
LAB_00511c37:
  if (uVar7 != 0) {
    iVar4 = Ptr_BaseAdjustMinus4();
    do {
      if (*param_1 == 0) {
        iVar8 = 0;
      }
      else {
        iVar8 = *param_1 + -4;
      }
      if (iVar8 != iVar4) {
        do {
          if (*(int *)(iVar8 + 0x10) == *(int *)(uVar7 + 0xc)) {
            if (*(int *)(iVar8 + 0x18) == 0) {
              cVar2 = IsBlackDecal();
              if ((cVar2 == '\0') && (cVar2 = IsWhiteDecal(), cVar2 != '\0')) {
                *(uint *)(iVar8 + 0x18) = uVar7;
              }
            }
            else if ((*(int *)(iVar8 + 0x14) == 0) && (cVar2 = IsBlackDecal(), cVar2 != '\0')) {
              *(uint *)(iVar8 + 0x14) = uVar7;
            }
            goto LAB_00511d14;
          }
          if (*(int *)(iVar8 + 4) == 0) {
            iVar8 = 0;
          }
          else {
            iVar8 = *(int *)(iVar8 + 4) + -4;
          }
        } while (iVar8 != iVar4);
      }
      puVar5 = _malloc(0x1c);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        *puVar5 = &PTR_FUN_006c0274;
        puVar5[5] = 0;
        puVar5[6] = 0;
        puVar5[4] = 0;
        *(undefined1 *)(puVar5 + 3) = 0;
      }
      puVar5[4] = *(undefined4 *)(uVar7 + 0xc);
      cVar2 = IsBlackDecal();
      if (cVar2 == '\0') {
        cVar2 = IsWhiteDecal();
        if (cVar2 != '\0') {
          puVar5[6] = uVar7;
        }
      }
      else {
        puVar5[5] = uVar7;
      }
      piVar1 = (int *)param_1[1];
      puVar3 = puVar5 + 1;
      *piVar1 = (int)puVar3;
      param_1[1] = (int)puVar3;
      puVar5[2] = piVar1;
      *puVar3 = param_1;
LAB_00511d14:
      uVar7 = CarPartDatabase__GetCarPart(0,0x3a,0,uVar7,0xffffffff);
    } while (uVar7 != 0);
  }
  return;
}


// ==== 0x511d40 FUN_00511d40

undefined4 * __fastcall FUN_00511d40(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &DAT_007066a0;
  do {
    if (*piVar2 == param_2) {
      return &DAT_007066a0 + iVar1 * 8;
    }
    piVar2 = piVar2 + 8;
    iVar1 = iVar1 + 1;
  } while ((int)piVar2 < 0x706780);
  return (undefined4 *)0x0;
}


// ==== 0x511d70 FUN_00511d70

undefined4
FUN_00511d70(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_8c [16];
  undefined4 local_4c [16];
  int local_c;
  char local_5;
  
  local_5 = GarageCategoryVisual__IsWidebodyInstalled();
  iVar1 = DAT_00735748;
  iVar3 = 0;
  piVar2 = &DAT_007066a0;
  do {
    if (*piVar2 == DAT_00735748) {
      puVar4 = &DAT_007066a0 + iVar3 * 8;
      goto LAB_00511da4;
    }
    piVar2 = piVar2 + 8;
    iVar3 = iVar3 + 1;
  } while ((int)piVar2 < 0x706780);
  puVar4 = (undefined4 *)0x0;
LAB_00511da4:
  *param_1 = puVar4[1];
  *param_2 = puVar4[3];
  local_c = FECarConfig__GetCarType();
  param_1 = (undefined4 *)0x0;
  param_2 = (undefined4 *)0x0;
  puVar4 = local_4c;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = local_8c;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  switch(iVar1) {
  case 2:
  case 3:
    if (local_5 != '\0') {
      if (local_5 == '\x01') {
        bStrCpy();
        break;
      }
      bStrCpy();
    }
  case 0:
  case 1:
    break;
  case 4:
  case 5:
    if (local_5 != '\0') {
      bStrCpy();
    }
    break;
  case 6:
    break;
  default:
    goto switchD_00511de9_default;
  }
  bStrCpy();
switchD_00511de9_default:
  iVar3 = local_c * 0xc90;
  iVar1 = iVar3 + DAT_00734588;
  if (iVar1 != 0) {
    param_1 = (undefined4 *)FUN_004f42f0(local_4c,iVar1);
  }
  iVar3 = DAT_00734588 + iVar3;
  if (iVar3 != 0) {
    param_2 = (undefined4 *)FUN_004f42f0(local_8c,iVar3);
  }
  *param_3 = param_1;
  *param_4 = param_2;
  return 1;
}


// ==== 0x511f00 FUN_00511f00

void __fastcall
FUN_00511f00(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,char param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined4 local_8;
  
  iVar2 = 0;
  piVar1 = &DAT_007066a0;
  do {
    if (*piVar1 == param_2) {
      puVar4 = &DAT_007066a0 + iVar2 * 8;
      goto LAB_00511f21;
    }
    piVar1 = piVar1 + 8;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x706780);
  puVar4 = (undefined4 *)0x0;
LAB_00511f21:
  local_8 = 0;
  FUN_00511d70(local_14,local_10,&local_8,local_c);
  iVar2 = FECarConfig__GetCarType();
  uVar3 = 0;
  if (iVar2 != 0x23) {
    if (iVar2 * 0xc90 + DAT_00734588 == 0) {
      iVar2 = 0;
      goto LAB_00511f93;
    }
    uVar3 = bStringHash();
  }
  iVar2 = CarPartDatabase__GetCarPart(uVar3,puVar4[1],local_8,0,0xffffffff);
LAB_00511f93:
  if (iVar2 != (&DAT_00745b6c)[puVar4[1]]) {
    GarageManager__InstallPart(iVar2,0);
  }
  if (param_5 != '\0') {
    GarageManager__InstallPart(param_3,0);
    return;
  }
  GarageManager__PreviewPart();
  return;
}


// ==== 0x511ff0 GarageDecalsBrand::GarageDecalsBrand

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 * GarageDecalsBrand__GarageDecalsBrand(undefined4 *param_1,int param_2)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  int ****ppppiVar4;
  int ****ppppiVar5;
  bool bVar6;
  undefined1 uVar7;
  char cVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  undefined4 uVar12;
  uint uVar13;
  char *pcVar14;
  uint uVar15;
  undefined1 *puVar16;
  undefined4 *puVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  int ****local_24;
  int ****local_20;
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  int local_14;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_00688e04;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  puVar17 = param_1 + 0x11;
  *param_1 = &PTR_FUN_006c019c;
  *puVar17 = puVar17;
  param_1[0x12] = puVar17;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_004f8370(param_1 + 0x13,"master_thumb","thumb");
  puVar17 = param_1 + 0x22;
  *puVar17 = puVar17;
  param_1[0x23] = puVar17;
  local_8 = CONCAT31(local_8._1_3_,3);
  param_2 = 0;
  local_14 = 0;
  *(undefined1 *)((int)param_1 + 0x93) = 0;
  FUN_00511d70(&param_2,&local_14,local_1c,local_18);
  if (((&DAT_00745b6c)[param_2] == 0) || ((&DAT_00745b6c)[DAT_00735750 + local_14] == 0)) {
    uVar7 = 0;
  }
  else {
    uVar7 = 1;
  }
  *(undefined1 *)((int)param_1 + 0x91) = uVar7;
  *(undefined1 *)(param_1 + 0x24) = 0;
  *(undefined1 *)((int)param_1 + 0x92) = 0;
  iVar9 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar9 != 0) && (*(int *)(iVar9 + 0x18) != 0)) && (*(int **)(iVar9 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar9 + 0x14) + 8))(0xe8e61aab,0,0,*(int *)(iVar9 + 0x18));
  }
  iVar9 = FECarConfig__GetCarType();
  puVar17 = DAT_0073ad40;
  param_2 = iVar9 * 0xc90 + DAT_00734588;
  puVar10 = (undefined4 *)NullUpdate_ret();
  for (; puVar17 != puVar10; puVar17 = (undefined4 *)*puVar17) {
    uVar15 = puVar17[3];
    uVar13 = puVar17[4] * 0x30 + uVar15;
    for (; uVar15 < uVar13; uVar15 = uVar15 + 0x30) {
      if (*(char *)(uVar15 + 0x10) == ':') goto LAB_00512145;
    }
  }
LAB_00512145:
  local_24 = (int ****)&local_24;
  local_20 = (int ****)&local_24;
  local_8 = CONCAT31(local_8._1_3_,4);
  pcVar14 = "GENERIC_REMOVE";
  do {
    pcVar1 = pcVar14 + 1;
    pcVar14 = pcVar14 + 1;
  } while (*pcVar1 != '\0');
  puVar16 = &DAT_006b8d20;
  iVar9 = -1;
  uVar15 = 0x4e;
  do {
    iVar9 = iVar9 * 0x21 + uVar15;
    pbVar2 = puVar16 + 1;
    uVar15 = (uint)*pbVar2;
    puVar16 = puVar16 + 1;
  } while (*pbVar2 != 0);
  FUN_00512580(iVar9,0x7a45b5c5,0,0,0);
  BuildDecalList(param_1 + 0x22);
  bVar3 = *(byte *)(param_2 + 0xc0);
  iVar9 = param_2 + 0xc0;
  param_2 = -1;
  while (bVar3 != 0) {
    param_2 = param_2 * 0x21 + (uint)bVar3;
    pbVar2 = (byte *)(iVar9 + 1);
    iVar9 = iVar9 + 1;
    bVar3 = *pbVar2;
  }
  if (param_1[0x22] == 0) goto LAB_005121f7;
  puVar17 = (undefined4 *)(param_1[0x22] + -4);
  while( true ) {
    if (param_1 == (undefined4 *)0xffffff78) {
      puVar10 = (undefined4 *)0x0;
    }
    else {
      puVar10 = param_1 + 0x21;
    }
    if (puVar17 == puVar10) break;
    iVar9 = puVar17[4];
    if ((iVar9 == param_2) || (DAT_007677ac != 0)) {
LAB_0051223a:
      bVar6 = true;
    }
    else {
      cVar8 = FUN_0051beb0(&DAT_0074435c);
      bVar6 = false;
      if (cVar8 != '\0') goto LAB_0051223a;
    }
    if (DAT_00745e40 == 2) {
      if ((bVar6) || (DAT_00735758 != '\0')) {
        piVar11 = &DAT_00744368;
        while ((piVar11[-1] != iVar9 && (*piVar11 != iVar9))) {
          if ((piVar11[1] == iVar9) || (piVar11 = piVar11 + 6, 0x7449c7 < (int)piVar11)) break;
        }
LAB_005122bb:
        FUN_00512580(iVar9,0,*(undefined4 *)puVar17[5],puVar17,0);
      }
    }
    else if ((bVar6) || (DAT_00735758 != '\0')) {
      piVar11 = &DAT_00744368;
      do {
        if (((piVar11[-1] == iVar9) || (*piVar11 == iVar9)) || (piVar11[1] == iVar9)) break;
        piVar11 = piVar11 + 6;
      } while ((int)piVar11 < 0x7449c8);
      goto LAB_005122bb;
    }
    if (puVar17[1] == 0) {
LAB_005121f7:
      puVar17 = (undefined4 *)0x0;
    }
    else {
      puVar17 = (undefined4 *)(puVar17[1] + -4);
    }
  }
  puVar17 = (undefined4 *)param_1[0x11];
  do {
    if (puVar17 == param_1 + 0x11) {
      param_1[0x10] = (undefined4 *)param_1[0x11];
LAB_00512305:
      iVar9 = param_1[0x10];
      FUN_004f8960();
      GarageDecalsBrand__RedrawHeading(param_1);
      iVar9 = *(int *)(iVar9 + 0x10);
      if (iVar9 != 0) {
        if (*(char *)(iVar9 + 0xc) == '\0') {
          uVar12 = *(undefined4 *)(*(int *)(iVar9 + 0x18) + 8);
        }
        else {
          uVar12 = *(undefined4 *)(*(int *)(iVar9 + 0x14) + 8);
        }
        uVar19 = 0;
        uVar18 = DAT_0073574c;
        uVar12 = CarPartDatabase__GetCarPart(0,0x3a,uVar12,0,0xffffffff);
        FUN_00511f00(uVar12,uVar18,uVar19);
      }
      *(undefined1 *)(param_1 + 8) = 1;
      if ((int *****)local_24 != &local_24) {
        do {
          ppppiVar4 = (int ****)*local_24;
          ppppiVar5 = (int ****)local_24[1];
          *ppppiVar5 = (int ***)ppppiVar4;
          ppppiVar4[1] = (int ***)ppppiVar5;
          _free(local_24);
        } while ((int *****)local_24 != &local_24);
      }
      ExceptionList = local_10;
      return param_1;
    }
    if (puVar17[2] == DAT_00735754) {
      param_1[0x10] = puVar17;
      goto LAB_00512305;
    }
    puVar17 = (undefined4 *)*puVar17;
  } while( true );
}


// ==== 0x5123c0 FUN_005123c0

void * __thiscall FUN_005123c0(void *param_1,byte param_2)

{
  FUN_005123e0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5123e0 FUN_005123e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005123e0(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00688bdc;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c019c;
  local_4 = 3;
  if (*(char *)(param_1 + 0x24) != '\0') {
    FUN_00511f00(0,DAT_0073574c,*(char *)(param_1 + 0x24));
  }
  RideInfo__operator_(&DAT_00745000,&DAT_00745720);
  iVar3 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,&DAT_00745720);
  _DAT_0072cc80 = 2;
  if (iVar3 != 0) {
    GarageMainScreen__SetRideInfo(iVar3,&DAT_00748850,2);
  }
  piVar1 = (int *)param_1[0x22];
  local_4 = CONCAT31(local_4._1_3_,2);
  while (piVar1 != param_1 + 0x22) {
    iVar3 = *piVar1;
    piVar2 = (int *)piVar1[1];
    *piVar2 = iVar3;
    *(int **)(iVar3 + 4) = piVar2;
    if (piVar1 + -1 != (int *)0x0) {
      (**(code **)piVar1[-1])(1);
    }
    piVar1 = (int *)param_1[0x22];
  }
  FUN_004f84d0();
  piVar1 = (int *)param_1[0x11];
  while (piVar1 != param_1 + 0x11) {
    iVar3 = *piVar1;
    piVar2 = (int *)piVar1[1];
    *piVar2 = iVar3;
    *(int **)(iVar3 + 4) = piVar2;
    _free(piVar1);
    piVar1 = (int *)param_1[0x11];
  }
  local_4 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x512500 FUN_00512500

void __fastcall FUN_00512500(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (in_EAX != 0) {
    if (*(char *)(in_EAX + 0xc) == '\0') {
      uVar1 = *(undefined4 *)(*(int *)(in_EAX + 0x18) + 8);
    }
    else {
      uVar1 = *(undefined4 *)(*(int *)(in_EAX + 0x14) + 8);
    }
    uVar2 = DAT_0073574c;
    uVar1 = CarPartDatabase__GetCarPart(0,0x3a,uVar1,0,0xffffffff);
    FUN_00511f00(uVar1,uVar2,param_2);
  }
  return;
}


// ==== 0x512550 FUN_00512550

void FUN_00512550(void)

{
  FUN_00511f00(0,DAT_0073574c);
  return;
}


// ==== 0x512580 FUN_00512580

void FUN_00512580(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  int unaff_EDI;
  
  piVar2 = _malloc(0x18);
  piVar2[2] = param_1;
  piVar2[3] = param_3;
  piVar2[4] = param_4;
  piVar2[5] = param_2;
  puVar1 = *(undefined4 **)(in_EAX + 0x48);
  *puVar1 = piVar2;
  *(int **)(in_EAX + 0x48) = piVar2;
  *piVar2 = in_EAX + 0x44;
  piVar2[1] = (int)puVar1;
  iVar3 = FUN_004f8730(in_EAX + 0x4c,piVar2[2],param_5,1);
  if (((unaff_EDI != 0) && (iVar3 != 0)) && (*(int *)(iVar3 + 0x24) != unaff_EDI)) {
    *(int *)(iVar3 + 0x24) = unaff_EDI;
    *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | 0x400000;
  }
  return;
}


// ==== 0x5125f0 FUN_005125f0

void FUN_005125f0(void)

{
  int iVar1;
  int unaff_EBX;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x40);
  if (unaff_EBX == -0x6edfbf62) {
    if ((iVar1 != *(int *)(unaff_EDI + 0x44)) && (*(int *)(unaff_EDI + 0x44) != unaff_EDI + 0x44)) {
      *(undefined4 *)(unaff_EDI + 0x40) = *(undefined4 *)(iVar1 + 4);
    }
  }
  else if (((unaff_EBX == -0x4a68e40f) &&
           (*(undefined4 **)(unaff_EDI + 0x40) != *(undefined4 **)(unaff_EDI + 0x48))) &&
          (*(int *)(unaff_EDI + 0x44) != unaff_EDI + 0x44)) {
    *(undefined4 *)(unaff_EDI + 0x40) = **(undefined4 **)(unaff_EDI + 0x40);
  }
  if (iVar1 != *(int *)(unaff_EDI + 0x40)) {
    FUN_004f8910();
    GarageDecalsBrand__RedrawHeading(unaff_EDI);
    FUN_004f8340(*(undefined4 *)(unaff_EDI + 0xc));
    *(undefined1 *)(unaff_EDI + 0x93) = 1;
    DAT_0073575c = 0;
  }
  return;
}


// ==== 0x512690 GarageDecalsBrand::RedrawHeading

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

void GarageDecalsBrand__RedrawHeading(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 local_24 [8];
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int **)(iVar1 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x14) + 8))(0x50fe8c15,0,0,*(int *)(iVar1 + 0x18));
  }
  iVar1 = *(int *)(param_1 + 0x40);
  iVar2 = LanguageStrings__FindByHash();
  if (iVar2 == 0) {
    iVar2 = LanguageStrings__FindByHash();
  }
  puVar5 = local_24;
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  if (*(int *)(iVar1 + 0x14) == 0) {
    iVar4 = 0;
    piVar3 = &DAT_007066a0;
    do {
      if (*piVar3 == DAT_00735748) {
        puVar5 = &DAT_007066a0 + iVar4 * 8;
        goto LAB_00512737;
      }
      piVar3 = piVar3 + 8;
      iVar4 = iVar4 + 1;
    } while ((int)piVar3 < 0x706780);
    puVar5 = (undefined4 *)0x0;
LAB_00512737:
    iVar4 = *(int *)(iVar1 + 0x10);
    if (*(char *)(iVar4 + 0xc) == '\0') {
      iVar4 = *(int *)(iVar4 + 0x18);
    }
    else {
      iVar4 = *(int *)(iVar4 + 0x14);
    }
    if ((&DAT_00745b6c)[puVar5[3] + DAT_00735750] == iVar4) {
      FUN_00565da0(" (%s)",iVar2);
      puVar5 = local_24;
    }
    else {
      puVar5 = (undefined4 *)&DAT_006b9172;
    }
    FUN_004f6850(&DAT_006cc578,*(undefined4 *)(iVar1 + 0xc),puVar5);
  }
  else {
    FUN_00495f00(*(int *)(iVar1 + 0x14));
  }
  if (*(int *)(param_1 + 0xc) == 0) {
LAB_005127c3:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0x5b32ee7c);
    }
  }
  else {
    iVar2 = FUN_004f65d0();
    if (iVar2 == 0) goto LAB_005127c3;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_005127c3;
  }
  FEObject__SetInvisible(iVar2);
  if (*(int *)(param_1 + 0xc) == 0) {
LAB_0051280d:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(0xaab7ee36);
    }
  }
  else {
    iVar2 = FUN_004f65d0();
    if (iVar2 == 0) goto LAB_0051280d;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_0051280d;
  }
  FEObject__SetInvisible(iVar2);
  if (*(int *)(iVar1 + 0x10) == 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar2 == 0) || (iVar4 = *(int *)(iVar2 + 0x18), iVar4 == 0)) ||
       (piVar3 = *(int **)(iVar2 + 0x14), piVar3 == (int *)0x0)) goto LAB_0051288e;
    uVar6 = 0x4c71900a;
  }
  else {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if (((iVar2 == 0) || (iVar4 = *(int *)(iVar2 + 0x18), iVar4 == 0)) ||
       (piVar3 = *(int **)(iVar2 + 0x14), piVar3 == (int *)0x0)) goto LAB_0051288e;
    uVar6 = 0x4c71910b;
  }
  (**(code **)(*piVar3 + 8))(uVar6,0,0,iVar4);
LAB_0051288e:
  if (*(int *)(iVar1 + 0x10) != 0) {
    if (*(char *)(*(int *)(iVar1 + 0x10) + 0xc) == '\0') {
      uVar6 = 0x4c75717a;
    }
    else {
      uVar6 = 0x54c56cbe;
    }
    FUN_004c96c0(uVar6);
    if (*(char *)(*(int *)(iVar1 + 0x10) + 0xc) != '\0') {
      FUN_00495f00(0xa39f11f8);
      return;
    }
    FUN_00495f00(0x3cc939b4);
  }
  return;
}


// ==== 0x512900 FUN_00512900

void __thiscall FUN_00512900(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
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
  undefined4 local_10;
  undefined4 local_c;
  
  if (param_2 < 0x9120409f) {
    if (param_2 == 0x9120409e) {
LAB_00512aeb:
      FUN_005125f0();
      return;
    }
    if (param_2 < 0x7a45b5c6) {
      if (param_2 == 0x7a45b5c5) {
        *(undefined1 *)(param_1 + 0x90) = 1;
        *(undefined1 *)(param_1 + 0x92) = 1;
        return;
      }
      if (param_2 == 0xc407210) {
        iVar3 = *(int *)(param_1 + 0x40);
        if (*(char *)(*(int *)(param_1 + 0x58) + 0x18) == '\0') {
          iVar1 = *(int *)(iVar3 + 8);
          if (iVar1 == DAT_00744b88) {
            uVar4 = *(undefined4 *)(param_1 + 0xc);
            local_38 = 0x7a45b5c5;
            local_30 = 0x7a45b5c5;
          }
          else {
            iVar2 = FUN_00511d40();
            iVar3 = *(int *)(iVar3 + 0x10);
            if (*(char *)(iVar3 + 0xc) == '\0') {
              iVar3 = *(int *)(iVar3 + 0x18);
            }
            else {
              iVar3 = *(int *)(iVar3 + 0x14);
            }
            uVar4 = *(undefined4 *)(param_1 + 0xc);
            if ((&DAT_00745b6c)[*(int *)(iVar2 + 0xc) + DAT_00735750] == iVar3) {
              local_10 = 0x639;
              local_14 = 0x368294c0;
              local_c = 0;
              FUN_004dcbe0(&local_14,"GenericOKDialog.fng",uVar4);
              return;
            }
            local_38 = 0x76d94941;
            local_30 = 0x5583d1ce;
            DAT_00735754 = iVar1;
          }
          local_1c = 0;
          local_18 = 0;
          local_34 = 0x639;
          local_28 = 0;
          local_2c = 0x541389e5;
          local_24 = 0;
          local_20 = 0xb8a7c6cc;
          FUN_004dc6e0(&local_38,"GenericDialog.fng",uVar4);
          return;
        }
      }
      else if (param_2 == 0x5583d1ce) {
        FUN_00512500(param_1);
        *(undefined1 *)(param_1 + 0x91) = 1;
        *(undefined1 *)(param_1 + 0x92) = 1;
        return;
      }
    }
    else if (param_2 == 0x911ab364) {
      GarageCategoryVisual__MoveBackPackage(param_1);
      return;
    }
  }
  else if (param_2 < 0xc98356bb) {
    if (param_2 == 0xc98356ba) {
      FUN_004f89d0();
      DAT_00735e84 = 1;
      DAT_006fb02c = 0;
      DAT_0074810c = DAT_0073ad3c;
      GarageDecalsBrand__RedrawHeading(param_1);
      FUN_004f7d30();
      if (*(char *)(param_1 + 0x92) != '\0') {
        GarageCategoryVisual__MoveBackPackage(param_1);
      }
      DAT_0073575c = DAT_0073575c + 1;
      if ((*(char *)(param_1 + 0x93) != '\0') && (0xf < DAT_0073575c)) {
        if (*(int *)(*(int *)(param_1 + 0x40) + 0x10) != 0) {
          FUN_00512500(param_1);
          *(undefined1 *)(param_1 + 0x93) = 0;
          DAT_0073575c = 0;
          return;
        }
        FUN_00512550(param_1);
        *(undefined1 *)(param_1 + 0x93) = 0;
        DAT_0073575c = 0;
        return;
      }
    }
    else {
      if (param_2 == 0xb5971bf1) goto LAB_00512aeb;
      if (param_2 == 0xc519bfc0) {
        iVar3 = *(int *)(param_1 + 0x40);
        iVar1 = *(int *)(iVar3 + 0x10);
        if (iVar1 != 0) {
          *(bool *)(iVar1 + 0xc) = *(char *)(iVar1 + 0xc) == '\0';
          if (*(char *)(*(int *)(iVar3 + 0x10) + 0xc) == '\0') {
            uVar4 = 0x4c75717a;
          }
          else {
            uVar4 = 0x54c56cbe;
          }
          FUN_004c96c0(uVar4);
          FUN_00512500(param_1);
          return;
        }
      }
    }
  }
  else if (param_2 == 0xe148eaa6) {
    GarageManager__InstallPart(0,0);
    GarageManager__InstallPart(0,0);
    GarageManager__InstallPart(0,0);
    GarageManager__InstallPart(0,0);
    GarageManager__InstallPart(0,0);
    GarageManager__InstallPart(0,0);
  }
  return;
}


// ==== 0x512c40 GarageChooseAccessoryCategoryScreen::_GarageChooseAccessoryCategoryScreen

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void __fastcall
GarageChooseAccessoryCategoryScreen___GarageChooseAccessoryCategoryScreen(undefined4 *param_1)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_006c018c;
  FUN_004f84d0();
  _Memory = (int *)param_1[0x11];
  while (_Memory != param_1 + 0x11) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = (int *)param_1[0x11];
  }
  FUN_004f7b50();
  return;
}


// ==== 0x512c90 FUN_00512c90

void * __thiscall FUN_00512c90(void *param_1,byte param_2)

{
  GarageChooseAccessoryCategoryScreen___GarageChooseAccessoryCategoryScreen();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x512cb0 CreateGarageAccessoryCategoryScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 CreateGarageAccessoryCategoryScreen(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688dc3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x8c);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = GarageChooseAccessoryCategoryScreen__GarageChooseAccessoryCategoryScreen(pvVar1,param_1)
    ;
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x512d10 GarageChooseAccessoryCategoryScreen::GarageChooseAccessoryCategoryScreen

/* [canon] car high (ghidra+hopper) docs/re/tuning.md */

undefined4 *
GarageChooseAccessoryCategoryScreen__GarageChooseAccessoryCategoryScreen
          (undefined4 *param_1,undefined4 param_2)

{
  byte *pbVar1;
  undefined4 *puVar2;
  char *pcVar3;
  byte bVar4;
  undefined4 *puVar5;
  char cVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  undefined4 *puVar13;
  char *pcVar14;
  bool bVar15;
  uint local_20;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_0068906e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  puVar13 = param_1 + 0x11;
  *param_1 = &PTR_FUN_006c018c;
  *puVar13 = puVar13;
  param_1[0x12] = puVar13;
  puVar13 = param_1 + 0x13;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_004f8370(puVar13,"master_thumb","thumb");
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar7 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar7 != 0) && (*(int *)(iVar7 + 0x18) != 0)) && (*(int **)(iVar7 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar7 + 0x14) + 8))(0xe8e61aab,0,0,*(int *)(iVar7 + 0x18));
  }
  iVar7 = FECarConfig__GetCarType();
  pbVar8 = (byte *)(iVar7 * 0xc90 + DAT_00734588);
  iVar7 = -1;
  bVar4 = *pbVar8;
  while (bVar4 != 0) {
    iVar7 = iVar7 * 0x21 + (uint)bVar4;
    pbVar1 = pbVar8 + 1;
    pbVar8 = pbVar8 + 1;
    bVar4 = *pbVar1;
  }
  param_1[0x22] = iVar7;
  bVar15 = DAT_007677ac != 0;
  if (DAT_00745e40 == 1) {
    param_2._3_1_ = (byte)(DAT_00760284 >> 0x13) & 1;
    uVar11 = DAT_00760284 >> 0xb;
    uVar12 = DAT_00760284 >> 0xf;
    uVar9 = DAT_00760284 >> 9;
    local_20 = DAT_00760284 >> 7 & 1;
    iVar7 = FUN_004f8730(puVar13,0,0,1);
    if ((iVar7 != 0) && (*(int *)(iVar7 + 0x24) != 0x2929058)) {
      *(undefined4 *)(iVar7 + 0x24) = 0x2929058;
      *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | 0x400000;
    }
    piVar10 = _malloc(0x18);
    puVar2 = param_1 + 0x11;
    piVar10[2] = 0;
    piVar10[3] = 0x19dd0f;
    piVar10[4] = (int)"MU_GaragePartsBrowser.fng";
    *(byte *)(piVar10 + 5) = param_2._3_1_;
    puVar5 = (undefined4 *)param_1[0x12];
    *puVar5 = piVar10;
    param_1[0x12] = piVar10;
    piVar10[1] = (int)puVar5;
    *piVar10 = (int)puVar2;
    iVar7 = FUN_004f8730(puVar13,1,0,1);
    if ((iVar7 != 0) && (*(int *)(iVar7 + 0x24) != -0x9653c7c)) {
      *(undefined4 *)(iVar7 + 0x24) = 0xf69ac384;
      *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | 0x400000;
    }
    piVar10 = _malloc(0x18);
    piVar10[2] = 1;
    piVar10[3] = 0x483bc5b;
    piVar10[4] = (int)"MU_GaragePartsBrowser.fng";
    *(byte *)(piVar10 + 5) = (byte)uVar11 & 1;
    puVar5 = (undefined4 *)param_1[0x12];
    *puVar5 = piVar10;
    param_1[0x12] = piVar10;
    piVar10[1] = (int)puVar5;
    *piVar10 = (int)puVar2;
    iVar7 = FUN_004f8730(puVar13,2,0,1);
    if ((iVar7 != 0) && (*(int *)(iVar7 + 0x24) != 0x2cbb2d1c)) {
      *(undefined4 *)(iVar7 + 0x24) = 0x2cbb2d1c;
      *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | 0x400000;
    }
    piVar10 = _malloc(0x18);
    piVar10[2] = 2;
    piVar10[3] = 0x3aa425f3;
    piVar10[4] = (int)"MU_GaragePartsBrowser.fng";
    *(byte *)(piVar10 + 5) = (byte)uVar12 & 1;
    puVar5 = (undefined4 *)param_1[0x12];
    *puVar5 = piVar10;
    param_1[0x12] = piVar10;
    *piVar10 = (int)puVar2;
    piVar10[1] = (int)puVar5;
    pcVar14 = "VISUAL_PART_MUFFLERTIP";
    do {
      pcVar3 = pcVar14 + 1;
      pcVar14 = pcVar14 + 1;
    } while (*pcVar3 != '\0');
    GarageChooseAccessoryCategoryScreen__AddCategory
              (0x3b3a1f8d,"MU_GaragePartsBrowser.fng",local_20);
    iVar7 = FUN_004f8730(puVar13,4,0,1);
    if ((iVar7 != 0) && (*(int *)(iVar7 + 0x24) != 0x3f23165c)) {
      *(undefined4 *)(iVar7 + 0x24) = 0x3f23165c;
      *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | 0x400000;
    }
    piVar10 = _malloc(0x18);
    piVar10[2] = 4;
    piVar10[3] = 0x1b088f15;
    piVar10[4] = (int)"MU_GaragePartsBrowser.fng";
    *(byte *)(piVar10 + 5) = (byte)uVar9 & 1;
    puVar13 = (undefined4 *)param_1[0x12];
    *puVar13 = piVar10;
    param_1[0x12] = piVar10;
    *piVar10 = (int)puVar2;
    goto LAB_005131ae;
  }
  iVar7 = FUN_004f8730(puVar13,0,0,1);
  if ((iVar7 != 0) && (*(int *)(iVar7 + 0x24) != 0x2929058)) {
    *(undefined4 *)(iVar7 + 0x24) = 0x2929058;
    *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | 0x400000;
  }
  piVar10 = _malloc(0x18);
  puVar2 = param_1 + 0x11;
  piVar10[2] = 0;
  piVar10[3] = 0x19dd0f;
  piVar10[4] = (int)"MU_GaragePartsBrowser.fng";
  *(undefined1 *)(piVar10 + 5) = 0;
  puVar5 = (undefined4 *)param_1[0x12];
  *puVar5 = piVar10;
  param_1[0x12] = piVar10;
  piVar10[1] = (int)puVar5;
  *piVar10 = (int)puVar2;
  if ((bVar15) || (cVar6 = AnyPartOwnedInCategory(0xd), cVar6 != '\0')) {
    iVar7 = FUN_004f8730(puVar13,1,0,1);
    if ((iVar7 != 0) && (*(int *)(iVar7 + 0x24) != -0x9653c7c)) {
      *(undefined4 *)(iVar7 + 0x24) = 0xf69ac384;
      *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | 0x400000;
    }
    piVar10 = _malloc(0x18);
    piVar10[2] = 1;
    piVar10[3] = 0x483bc5b;
    piVar10[4] = (int)"MU_GaragePartsBrowser.fng";
    *(undefined1 *)(piVar10 + 5) = 0;
    puVar5 = (undefined4 *)param_1[0x12];
    *puVar5 = piVar10;
    param_1[0x12] = piVar10;
    piVar10[1] = (int)puVar5;
    *piVar10 = (int)puVar2;
    if (!bVar15) goto LAB_0051309e;
LAB_005130ac:
    iVar7 = FUN_004f8730(puVar13,2,0,1);
    if ((iVar7 != 0) && (*(int *)(iVar7 + 0x24) != 0x2cbb2d1c)) {
      *(undefined4 *)(iVar7 + 0x24) = 0x2cbb2d1c;
      *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | 0x400000;
    }
    piVar10 = _malloc(0x18);
    piVar10[2] = 2;
    piVar10[3] = 0x3aa425f3;
    piVar10[4] = (int)"MU_GaragePartsBrowser.fng";
    *(undefined1 *)(piVar10 + 5) = 0;
    puVar5 = (undefined4 *)param_1[0x12];
    *puVar5 = piVar10;
    param_1[0x12] = piVar10;
    piVar10[1] = (int)puVar5;
    *piVar10 = (int)puVar2;
    if (!bVar15) goto LAB_0051310c;
LAB_0051311a:
    pcVar14 = "VISUAL_PART_MUFFLERTIP";
    do {
      pcVar3 = pcVar14 + 1;
      pcVar14 = pcVar14 + 1;
    } while (*pcVar3 != '\0');
    GarageChooseAccessoryCategoryScreen__AddCategory(0x3b3a1f8d,"MU_GaragePartsBrowser.fng",0);
  }
  else {
LAB_0051309e:
    cVar6 = AnyPartOwnedInCategory(0xe);
    if (cVar6 != '\0') goto LAB_005130ac;
LAB_0051310c:
    cVar6 = AnyPartOwnedInCategory(0xf);
    if (cVar6 != '\0') goto LAB_0051311a;
  }
  iVar7 = FUN_004f8730(puVar13,4,0,1);
  if ((iVar7 != 0) && (*(int *)(iVar7 + 0x24) != 0x3f23165c)) {
    *(undefined4 *)(iVar7 + 0x24) = 0x3f23165c;
    *(uint *)(iVar7 + 0x1c) = *(uint *)(iVar7 + 0x1c) | 0x400000;
  }
  piVar10 = _malloc(0x18);
  piVar10[2] = 4;
  piVar10[3] = 0x1b088f15;
  piVar10[4] = (int)"MU_GaragePartsBrowser.fng";
  *(undefined1 *)(piVar10 + 5) = 0;
  puVar13 = (undefined4 *)param_1[0x12];
  *puVar13 = piVar10;
  param_1[0x12] = piVar10;
  *piVar10 = (int)puVar2;
LAB_005131ae:
  piVar10[1] = (int)puVar13;
  puVar13 = (undefined4 *)param_1[0x11];
  do {
    if (puVar13 == param_1 + 0x11) {
      param_1[0x10] = (undefined4 *)param_1[0x11];
LAB_005131d4:
      FUN_004f8960();
      GarageChooseAccessoryCategoryScreen__RedrawHeader();
      *(undefined1 *)(param_1 + 8) = 1;
      ExceptionList = local_10;
      return param_1;
    }
    if (puVar13[2] == DAT_00735764) {
      param_1[0x10] = puVar13;
      goto LAB_005131d4;
    }
    puVar13 = (undefined4 *)*puVar13;
  } while( true );
}


// ==== 0x513210 GarageChooseAccessoryCategoryScreen::AddCategory

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void GarageChooseAccessoryCategoryScreen__AddCategory(int param_1,int param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar2 = FUN_004f8730(unaff_EDI + 0x4c,unaff_ESI,0,1);
  if (((unaff_EBX != 0) && (iVar2 != 0)) && (*(int *)(iVar2 + 0x24) != unaff_EBX)) {
    *(int *)(iVar2 + 0x24) = unaff_EBX;
    *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) | 0x400000;
  }
  piVar3 = _malloc(0x18);
  piVar3[3] = param_1;
  *(undefined1 *)(piVar3 + 5) = param_3;
  piVar3[2] = unaff_ESI;
  piVar3[4] = param_2;
  puVar1 = *(undefined4 **)(unaff_EDI + 0x48);
  *puVar1 = piVar3;
  *(int **)(unaff_EDI + 0x48) = piVar3;
  piVar3[1] = (int)puVar1;
  *piVar3 = unaff_EDI + 0x44;
  return;
}


// ==== 0x513270 FUN_00513270

void FUN_00513270(void)

{
  int iVar1;
  int in_EAX;
  int unaff_EDI;
  
  FUN_004af5d0();
  iVar1 = *(int *)(in_EAX + 0x40);
  if (unaff_EDI == -0x6edfbf62) {
    if ((iVar1 != *(int *)(in_EAX + 0x44)) && (*(int *)(in_EAX + 0x44) != in_EAX + 0x44)) {
      *(undefined4 *)(in_EAX + 0x40) = *(undefined4 *)(iVar1 + 4);
    }
  }
  else if (((unaff_EDI == -0x4a68e40f) &&
           (*(undefined4 **)(in_EAX + 0x40) != *(undefined4 **)(in_EAX + 0x48))) &&
          (*(int *)(in_EAX + 0x44) != in_EAX + 0x44)) {
    *(undefined4 *)(in_EAX + 0x40) = **(undefined4 **)(in_EAX + 0x40);
  }
  if (*(int *)(in_EAX + 0x40) != iVar1) {
    FUN_004f8910();
    GarageChooseAccessoryCategoryScreen__RedrawHeader();
    if (unaff_EDI == -0x6edfbf62) {
      FUN_004f8340(*(undefined4 *)(in_EAX + 0xc));
      return;
    }
    FUN_004f8340(*(undefined4 *)(in_EAX + 0xc));
  }
  return;
}


// ==== 0x513310 GarageChooseAccessoryCategoryScreen::RedrawHeader

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

void GarageChooseAccessoryCategoryScreen__RedrawHeader(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBX;
  
  iVar1 = FEPackageList__FindByName(&DAT_00746104);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) && (*(int **)(iVar1 + 0x14) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x14) + 8))(0x50fe8c15,0,0,*(int *)(iVar1 + 0x18));
  }
  iVar1 = *(int *)(unaff_EBX + 0x40);
  ShowHideNewlyUnlockedMarker_int_(&DAT_00744ff0);
  FUN_00495f00(*(undefined4 *)(iVar1 + 0xc));
  if (((*(int *)(unaff_EBX + 0xc) == 0) || (iVar1 = FUN_004f65d0(), iVar1 == 0)) ||
     (iVar1 = FUN_004ffb70(), iVar1 == 0)) {
    if (DAT_0073578c != 0) {
      uVar2 = FUN_004ef050(0xa8a3681a);
      FEObject__SetInvisible(uVar2);
      return;
    }
    iVar1 = 0;
  }
  FEObject__SetInvisible(iVar1);
  return;
}


// ==== 0x5133d0 FUN_005133d0

int FUN_005133d0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x40) + 8);
  switch(iVar2) {
  case 0:
    DAT_00735714 = 10;
    DAT_00735724 = 10;
    break;
  case 1:
    DAT_00735714 = 5;
    DAT_00735724 = 5;
    break;
  case 2:
    DAT_00735714 = 6;
    DAT_00735724 = 6;
    break;
  case 3:
    DAT_00735714 = 0xb;
    DAT_00735724 = 0xb;
    break;
  case 4:
    DAT_00735714 = 9;
    DAT_00735724 = 9;
  }
  iVar4 = DAT_00735714;
  iVar1 = *(int *)(*(int *)(param_1 + 0x40) + 0x10);
  DAT_00735764 = iVar2;
  if (iVar1 != 0) {
    iVar2 = GarageCategoryVisual__GetNumPartsAvailable(param_1);
    if (0 < iVar2) {
      iVar2 = *(int *)(param_1 + 0x88);
      DAT_00735720 = iVar2;
      DAT_00735724 = iVar4;
    }
    if (iVar1 != 0) {
      piVar3 = &DAT_00706530;
      do {
        if (*piVar3 == iVar4) break;
        piVar3 = piVar3 + 7;
      } while ((int)piVar3 < 0x70669c);
      iVar2 = FUN_004b2330();
      if (iVar2 != 0) {
        FUN_004b0150();
      }
      GarageManager__PushScreen(*(undefined4 *)(param_1 + 0xc));
      iVar1 = DAT_0073578c;
      iVar2 = *(int *)(param_1 + 0xc);
      if (DAT_0073578c != 0) {
        iVar4 = FEPackageList__FindByName(&DAT_00746104);
        iVar2 = 0;
        if (iVar4 != 0) {
          iVar2 = 0;
          if (*(int *)(iVar4 + 0x18) != 0) {
            iVar2 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar4 + 0x18));
          }
        }
      }
    }
  }
  return iVar2;
}


// ==== 0x513530 FUN_00513530

undefined4 FUN_00513530(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  GarageManager__PopScreen();
  iVar1 = DAT_0073578c;
  DAT_00735714 = 10;
  DAT_00735724 = 10;
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  DAT_00735764 = 0;
  if (DAT_0073578c != 0) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    uVar3 = 0;
    if (iVar2 != 0) {
      uVar3 = 0;
      if (*(int *)(iVar2 + 0x18) != 0) {
        uVar3 = FUN_004f0800(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
      }
    }
  }
  return uVar3;
}


// ==== 0x5135a0 FUN_005135a0

void __thiscall FUN_005135a0(undefined4 param_1,uint param_2,undefined4 param_3)

{
  if (param_2 < 0x9120409f) {
    if (param_2 != 0x9120409e) {
      if (param_2 == 0xc407210) {
        FUN_005133d0(param_1);
        return;
      }
      if (param_2 != 0x911ab364) {
        return;
      }
      FUN_00513530(param_1);
      return;
    }
  }
  else if (param_2 != 0xb5971bf1) {
    if (param_2 != 0xc98356ba) {
      return;
    }
    FUN_004f89d0();
    FUN_004f7d30();
    return;
  }
  FUN_00513270(param_3);
  return;
}


// ==== 0x513610 FUN_00513610

undefined4 FUN_00513610(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00688803;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x44);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_00513780(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x513670 FUN_00513670

void FUN_00513670(undefined4 param_1)

{
  if (DAT_007449cc != 0) {
    FUN_00546060();
  }
  if (DAT_007449d0 != 0) {
    FUN_00546060();
  }
  if (DAT_007449d4 != 0) {
    FUN_00546060();
  }
  DAT_007449cc = 0;
  DAT_007449d0 = 0;
  DAT_007449d4 = 0;
  DAT_007449c8 = 0;
  Career__AnnounceReward(param_1,&DAT_00744b90);
  DAT_0073576c = &DAT_00744b90;
  FUN_0051bc80(DAT_00744eec,DAT_00744efc);
  return;
}


// ==== 0x5136f0 FUN_005136f0

uint __fastcall
FUN_005136f0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  uint in_EAX;
  undefined4 *unaff_ESI;
  
  uVar1 = DAT_0073576c;
  if ((((param_1 != (undefined4 *)0x0) && (param_2 != (undefined4 *)0x0)) &&
      (in_EAX = DAT_0073576c, DAT_0073576c != 0)) && (*(int *)(DAT_0073576c + 0x378) != 0)) {
    *param_1 = *(undefined4 *)(DAT_0073576c + 0x37c);
    param_1[1] = *(undefined4 *)(uVar1 + 0x380);
    param_1[2] = *(undefined4 *)(uVar1 + 900);
    *param_2 = *(undefined4 *)(uVar1 + 0x388);
    param_2[1] = *(undefined4 *)(uVar1 + 0x38c);
    param_2[2] = *(undefined4 *)(uVar1 + 0x390);
    *param_3 = *(undefined4 *)(uVar1 + 0x398);
    *param_4 = *(undefined4 *)(uVar1 + 0x394);
    *unaff_ESI = *(undefined4 *)(uVar1 + 0x39c);
    unaff_ESI[1] = *(undefined4 *)(uVar1 + 0x3a0);
    unaff_ESI[2] = *(undefined4 *)(uVar1 + 0x3a4);
    return CONCAT31((int3)(uVar1 >> 8),1);
  }
  return in_EAX & 0xffffff00;
}


// ==== 0x513780 FUN_00513780

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00513780(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int extraout_ECX;
  undefined *puVar4;
  undefined1 local_740 [16];
  undefined4 local_730;
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
  local_14 = 0;
  *param_1 = &PTR_FUN_006c01ac;
  param_1[0x10] = DAT_006fb038;
  DAT_006fb038 = 0;
  FUN_004b2520();
  DAT_0073576c = (char *)0x0;
  FUN_0051bad0(&DAT_007449c8);
  if (DAT_00735e5c != '\0') {
    iVar2 = FUN_004f65d0();
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x1c) = 0xff;
    }
    DAT_00735770 = DAT_00735e50;
  }
  FUN_0051ae90();
  iVar2 = 0;
  do {
    if ((&DAT_00744ab0)[iVar2 * 2] == extraout_ECX) {
      iVar2 = *(int *)(&DAT_00744ab4 + iVar2 * 8);
      goto LAB_00513841;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x1b);
  iVar2 = 0;
LAB_00513841:
  iVar2 = (&DAT_006f88f8)[iVar2];
  if ((0 < iVar2) && (*(int *)(DAT_007356a8 + 0x104) != 0)) {
    puVar4 = (undefined *)0x0;
    if (0 < iVar2) {
      puVar4 = (&PTR_s_Ghetto_Fabolous_006f872c)[iVar2 * 2];
    }
    piVar1 = *(int **)(*(int *)(DAT_007356a8 + 0x104) + 0x24);
    if (puVar4 == (undefined *)0xffffffff) {
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x90))(0x59);
      }
    }
    else if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x98))(0x59,puVar4);
    }
    if ((0.2 < *(float *)(*(int *)(DAT_007356a8 + 8) + 4)) && (DAT_007356ac != 0)) {
      EAXMix_SetupAllTypes(0xbf800000);
    }
  }
  if ((DAT_0073576c != (char *)0x0) && (*DAT_0073576c != '\0')) {
    FUN_0051bc80(*(undefined4 *)(DAT_0073576c + 0x35c),*(undefined4 *)(DAT_0073576c + 0x36c));
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x14);
    }
    *(undefined4 *)(iVar2 + 0x9c) = 1;
    RideInfo__Init();
    FECarConfig__BuildRide(DAT_0073576c + 4,0,local_740);
    if (((DAT_0073576c[0x450] & 1U) != 0) && (iVar2 = FindPartWithLevel(0xc,local_730), iVar2 != 0))
    {
      FUN_0057ea50();
      local_24 = iVar2;
      RideInfo__UpdatePartsEnabled(local_740);
    }
    iVar2 = FUN_004b2330();
    RideInfo__operator_(&DAT_00748850,local_740);
    _DAT_0072cc80 = 2;
    if (iVar2 != 0) {
      GarageMainScreen__SetRideInfo(iVar2,&DAT_00748850,2);
    }
  }
  DAT_00735768 = 1;
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  iVar2 = DAT_0073578c;
  if ((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) {
    if (DAT_0073578c == 0) {
      ExceptionList = local_1c;
      return param_1;
    }
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 0x18) != 0)) {
      cFEng__PopPackage(*(undefined4 *)(iVar2 + 8),*(int *)(iVar3 + 0x18));
    }
  }
  if (DAT_0073578c != 0) {
    iVar3 = *(int *)(DAT_0073578c + 8);
    iVar2 = iVar3 + 0xdc;
    if ((iVar2 == 0) || (iVar2 = FUN_004fd1e0(iVar2), iVar2 == 0)) {
      cFEng__PushPackage(iVar3,"DummyMagazineBack.fng",0x10,0);
    }
  }
  ExceptionList = local_1c;
  return param_1;
}


// ==== 0x513a80 FUN_00513a80

void * __thiscall FUN_00513a80(void *param_1,byte param_2)

{
  FUN_00513aa0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x513aa0 FUN_00513aa0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00513aa0(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 local_740 [1828];
  void *pvStack_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  pcStack_18 = FUN_00689387;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  *param_1 = &PTR_FUN_006c01ac;
  local_14._1_3_ = 0;
  if ((DAT_00792fa0 & 1) == 0) {
    DAT_00792fa0 = DAT_00792fa0 | 1;
    local_14._0_1_ = 1;
    local_14._1_3_ = 0;
    eh_vector_constructor_iterator(&DAT_0078f620,0x1cc0,2,FUN_004aefa0,FUN_004af020);
    _atexit(FUN_006964a0);
  }
  local_14._0_1_ = 0;
  FUN_004af030();
  if ((DAT_00792fa0 & 1) == 0) {
    DAT_00792fa0 = DAT_00792fa0 | 1;
    local_14._0_1_ = 2;
    eh_vector_constructor_iterator(&DAT_0078f620,0x1cc0,2,FUN_004aefa0,FUN_004af020);
    _atexit(FUN_006964a0);
    local_14._0_1_ = 0;
  }
  FUN_004af030();
  FUN_004b2480();
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(iVar2 + 0x14);
  }
  *(undefined4 *)(iVar2 + 0x9c) = 0;
  DAT_006fb038 = param_1[0x10];
  DAT_00735768 = 0;
  FUN_004b2520();
  RideInfo__Init();
  FECarConfig__BuildRide(&DAT_0075eef8,0,local_740);
  iVar2 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,local_740);
  _DAT_0072cc80 = 2;
  if (iVar2 != 0) {
    GarageMainScreen__SetRideInfo(iVar2,&DAT_00748850,2);
  }
  if (DAT_00735e5c == '\0') {
    if (DAT_0073576c != 0) {
      FUN_0051a860(DAT_0073576c);
    }
  }
  else {
    if ((*(int *)(DAT_007356a8 + 0x104) != 0) &&
       (piVar1 = *(int **)(*(int *)(DAT_007356a8 + 0x104) + 0x24), piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0xa0))();
    }
    FUN_0051bb50();
    DAT_00735e5c = '\0';
    DAT_00735e50 = 0;
  }
  local_14 = 0xffffffff;
  FUN_004f7b50();
  ExceptionList = pvStack_1c;
  return;
}


// ==== 0x513c90 FUN_00513c90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00513c90(int param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  bool bVar7;
  int iVar8;
  undefined4 uVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  int iStack_114;
  undefined4 auStack_100 [64];
  
  iVar13 = DAT_0073578c;
  if (param_2 < 0x911ab365) {
    if (param_2 != 0x911ab364) {
      if (param_2 == 0x14141414) {
        if (DAT_00735e5c == '\0') {
          FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
          return;
        }
        if (DAT_00735e54 != '\0') {
          FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
          return;
        }
        FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 != 0x406415e3) {
        return;
      }
    }
    if (((DAT_0073578c != 0) && (iVar8 = FEPackageList__FindByName(&DAT_00746104), iVar8 != 0)) &&
       (*(int *)(iVar8 + 0x18) != 0)) {
      cFEng__PopPackage(*(undefined4 *)(iVar13 + 8),*(int *)(iVar8 + 0x18));
    }
    if (DAT_00735e5c != '\0') {
      if (DAT_00735e54 == '\0') {
        _DAT_006fae18 = 0xffffffff;
        _DAT_006fae1c = 0xffffffff;
        _DAT_006fae20 = 0xffffffff;
        _DAT_006fae24 = 0xffffffff;
        DAT_00735e58 = 0;
        FUN_004c96f0(0x14141414,2);
        return;
      }
      FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
      return;
    }
    FUN_004f6360(*(undefined4 *)(param_1 + 0xc));
    return;
  }
  if (param_2 == 0xc98356ba) {
    if (DAT_00735774 != '\0') {
      bVar7 = false;
      iStack_114 = 0;
      do {
        if (DAT_0072ce20 <= iStack_114) break;
        for (iVar13 = 0; (!bVar7 && (iVar13 < DAT_0072ce24)); iVar13 = iVar13 + 1) {
          for (iVar8 = 0; (!bVar7 && (iVar8 < DAT_0072ce28)); iVar8 = iVar8 + 1) {
            for (iVar12 = 0; (!bVar7 && (iVar12 < DAT_0072ce30)); iVar12 = iVar12 + 1) {
              for (iVar11 = 0; (!bVar7 && (iVar11 < DAT_0072ce2c)); iVar11 = iVar11 + 1) {
                if (((iStack_114 == DAT_0072ce3c) &&
                    (((iVar13 == DAT_0072ce40 && (iVar8 == DAT_0072ce44)) &&
                     (iVar12 == DAT_0072ce4c)))) && (iVar11 == DAT_0072ce48)) {
                  bVar7 = true;
                }
              }
            }
          }
        }
        iStack_114 = iStack_114 + 1;
      } while (!bVar7);
    }
    if (DAT_00735775 != '\0') {
      uVar9 = DAT_00735770;
      if (DAT_00735700 != '\0') {
        iVar13 = 0;
        do {
          if ((&DAT_007449d8)[iVar13 * 2] == 0) {
            uVar9 = *(undefined4 *)(&DAT_007449dc + iVar13 * 8);
            goto LAB_00513f13;
          }
          iVar13 = iVar13 + 1;
        } while (iVar13 < 0x1b);
        uVar9 = 0;
      }
LAB_00513f13:
      FUN_00513670(uVar9);
      DAT_00735775 = '\0';
    }
    iVar13 = *(int *)(param_1 + 0xc);
    if (((DAT_0073576c != 0) && (DAT_007449c8 != 0)) && (iVar8 = FUN_004af540(), iVar8 != 0)) {
      FUN_004af5a0();
      if (DAT_007449d0 != 0) {
        FUN_004b91e0();
        FUN_00414a60();
      }
      if (DAT_007449d4 != 0) {
        FUN_004b91e0();
        FUN_00414a60();
      }
      iVar13 = DAT_0073576c;
      puVar14 = auStack_100;
      for (iVar8 = 0x40; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar14 = 0;
        puVar14 = puVar14 + 1;
      }
      if (*(int *)(DAT_0073576c + 0x434) == 0) {
        bStrCpy();
      }
      else {
        bStrCpy();
        pcVar10 = (char *)GetCarTypeInfo();
        if (pcVar10 == (char *)0x0) {
          pcVar10 = "ERROR";
        }
        bStrCat2(pcVar10);
        if (*(int *)(iVar13 + 0x438) != 0) {
          bStrCat2(iVar13 + 0x3f0);
        }
      }
      FUN_004f6670();
      uVar9 = *(undefined4 *)(DAT_0073576c + 0x444);
      bVar4 = *(byte *)(DAT_0073576c + 0x44e);
      bVar5 = *(byte *)(DAT_0073576c + 0x44d);
      uVar1 = *(undefined4 *)(DAT_0073576c + 0x448);
      uVar2 = *(undefined4 *)(DAT_0073576c + 0x43c);
      uVar3 = *(undefined4 *)(DAT_0073576c + 0x440);
      bVar6 = *(byte *)(DAT_0073576c + 0x44c);
      FUN_00495fc0();
      FUN_004f7430(uVar9);
      FUN_004f74f0(uVar1);
      FUN_004f7000(uVar2,uVar3);
      FUN_00415510(((bVar4 | 0xffffff00) << 8 | (uint)bVar5) << 8 | (uint)bVar6);
      FUN_004f6850(auStack_100);
      return;
    }
    iVar8 = FEPackageList__FindByName(&DAT_00746104);
    if (iVar8 == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = *(int *)(iVar8 + 0x14);
    }
    *(undefined4 *)(iVar8 + 0x9c) = 1;
    FUN_00414a10();
    FUN_00414a10();
    if (((iVar13 == 0) || (iVar13 = FUN_004f65d0(), iVar13 == 0)) ||
       (iVar13 = FUN_004ffb70(), iVar13 == 0)) {
      if (DAT_0073578c == 0) {
        iVar13 = 0;
      }
      else {
        iVar13 = FUN_004ef050(0xb6676a90);
      }
    }
    FEObject__SetInvisible(iVar13);
  }
  return;
}


// ==== 0x514150 FUN_00514150

undefined4 FUN_00514150(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687913;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x40);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_005141b0(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x5141b0 FUN_005141b0

undefined4 * FUN_005141b0(undefined4 *param_1,undefined4 param_2)

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
  local_4 = 0;
  *param_1 = &PTR_FUN_006c01dc;
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  iVar1 = DAT_0073578c;
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) && (DAT_0073578c != 0)) {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) {
      cFEng__PopPackage(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
    }
  }
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x514250 FUN_00514250

void * __thiscall FUN_00514250(void *param_1,byte param_2)

{
  FUN_00514270();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x514270 FUN_00514270

void __fastcall FUN_00514270(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c01dc;
  FUN_004f7b50();
  return;
}


// ==== 0x514280 FUN_00514280

void FUN_00514280(int param_1)

{
  int iVar1;
  
  if (param_1 == -0x367ca946) {
    if (((DAT_0073576c != 0) && (DAT_007449cc != 0)) && (DAT_007449c8 != 0)) {
      iVar1 = FUN_004af540();
      if (iVar1 != 0) {
        FUN_004b91e0();
        FUN_00414a60();
        return;
      }
    }
    FUN_00414a10();
  }
  return;
}


// ==== 0x5142e0 FUN_005142e0

undefined4 FUN_005142e0(void)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((DAT_00745e40 != 1) && (DAT_00777b4c != 1)) {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x514300 FUN_00514300

int __fastcall FUN_00514300(int param_1)

{
  int in_EAX;
  
  if (in_EAX != 0) {
    if (in_EAX == *(int *)(param_1 + 8)) {
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(in_EAX + 4);
    }
    if (in_EAX == *(int *)(param_1 + 0xc)) {
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(in_EAX + 8);
    }
    if (*(int *)(in_EAX + 8) != 0) {
      *(undefined4 *)(*(int *)(in_EAX + 8) + 4) = *(undefined4 *)(in_EAX + 4);
    }
    if (*(int *)(in_EAX + 4) != 0) {
      *(undefined4 *)(*(int *)(in_EAX + 4) + 8) = *(undefined4 *)(in_EAX + 8);
    }
    *(undefined4 *)(in_EAX + 4) = 0xabadcafe;
    *(undefined4 *)(in_EAX + 8) = 0xabadcafe;
    return in_EAX;
  }
  return 0;
}


// ==== 0x514350 FUN_00514350

undefined4 * FUN_00514350(undefined4 *param_1,int param_2,undefined4 param_3)

{
  short *psVar1;
  int iVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685d33;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004fec30(param_1,param_2,param_3);
  param_1[0x16] = 0;
  *param_1 = &PTR_FUN_006c17c8;
  local_4 = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  FUN_00504020();
  psVar1 = (short *)param_1[0x18];
  iVar2 = 0;
  if ((psVar1 != (short *)0x0) && (*psVar1 != 0)) {
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
    } while (psVar1[iVar2] != 0);
  }
  param_1[0x19] = iVar2;
  param_1[0x1a] = *(undefined4 *)(param_2 + 0x68);
  param_1[0x1b] = *(undefined4 *)(param_2 + 0x6c);
  param_1[0x1c] = *(undefined4 *)(param_2 + 0x70);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00514410();
  WString_Grow();
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x514410 FUN_00514410

void FUN_00514410(void)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  undefined4 uVar4;
  int unaff_ESI;
  char *unaff_EDI;
  bool bVar5;
  
  _free(*(void **)(unaff_ESI + 0x58));
  *(undefined4 *)(unaff_ESI + 0x58) = 0;
  if (unaff_EDI != (char *)0x0) {
    pcVar3 = unaff_EDI;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar3 = _malloc((size_t)(pcVar3 + (1 - (int)(unaff_EDI + 1))));
    *(char **)(unaff_ESI + 0x58) = pcVar3;
    do {
      cVar1 = *unaff_EDI;
      unaff_EDI = unaff_EDI + 1;
      *pcVar3 = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
  }
  uVar4 = FEng__HashName();
  *(uint *)(unaff_ESI + 0x1c) = *(uint *)(unaff_ESI + 0x1c) | 0x400000;
  puVar2 = DAT_00735710;
  bVar5 = DAT_00735710 != (undefined4 *)0x0;
  *(undefined4 *)(unaff_ESI + 0x5c) = uVar4;
  if (bVar5) {
    (**(code **)*puVar2)();
  }
  return;
}


// ==== 0x514480 FUN_00514480

void FUN_00514480(void)

{
  undefined4 *puVar1;
  
  DAT_00735704 = (undefined4 *)FUN_00566dc0(0x60,"FERenderObjectSlotPool",0);
  if ((DAT_00735704 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_00735704;
    puVar1 = DAT_00735704;
    DAT_00735704[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_00735704 = &DAT_0073d818;
  }
  DAT_00735708 = (undefined4 *)FUN_00566dc0(0xc0,"FEEPolySlotPool",0);
  if (DAT_00735708 == (undefined4 *)0x0) {
    return;
  }
  if (DAT_0073d814 == 1) {
    *DAT_0073d81c = DAT_00735708;
    puVar1 = DAT_00735708;
    DAT_00735708[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_00735708 = &DAT_0073d818;
  }
  return;
}


// ==== 0x514510 FUN_00514510

void FUN_00514510(void)

{
  undefined4 unaff_ESI;
  
  FUN_00514bf0(unaff_ESI);
  FUN_0051a690();
  return;
}


// ==== 0x514530 FUN_00514530

int * FUN_00514530(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_EAX;
  int *piVar5;
  int iVar6;
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  int iVar7;
  
  iVar7 = DAT_00735708;
  if (*(int *)(DAT_00735708 + 0x18) == *(int *)(DAT_00735708 + 0x2c)) {
    if (DAT_0073570c == 0) {
      DAT_0078eaf0 = DAT_0078eaf0 + 1;
      return (int *)0x0;
    }
  }
  else if (DAT_0073570c == 0) {
    piVar5 = *(int **)(DAT_00735708 + 0x10);
    iVar6 = *(int *)(DAT_00735708 + 0x18) + 1;
    if (piVar5 != (int *)0x0) {
      iVar3 = *piVar5;
      if (*(int *)(DAT_00735708 + 0x1c) < iVar6) {
        *(int *)(DAT_00735708 + 0x1c) = iVar6;
      }
      *(int *)(iVar7 + 0x18) = iVar6;
      *(int *)(iVar7 + 0x10) = iVar3;
    }
    goto LAB_00514589;
  }
  piVar5 = (int *)FUN_00567160();
LAB_00514589:
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    ePoly__ePoly();
  }
  piVar5[0x2c] = 0;
  puVar4 = *(undefined4 **)(in_EAX + 0x1c);
  *puVar4 = piVar5;
  *(int **)(in_EAX + 0x1c) = piVar5;
  piVar5[1] = (int)puVar4;
  *piVar5 = in_EAX + 0x18;
  piVar1 = piVar5 + 8;
  *piVar1 = param_1;
  piVar5[9] = param_2;
  piVar5[10] = param_5;
  piVar5[0xc] = param_3;
  piVar5[0xd] = param_2;
  piVar5[0xe] = param_5;
  piVar2 = piVar5 + 0x10;
  *piVar2 = param_3;
  piVar5[0x11] = param_4;
  iVar7 = in_EAX + 0x20;
  piVar5[0x12] = param_5;
  piVar5[0x14] = param_1;
  piVar5[0x15] = param_4;
  piVar5[0x16] = param_5;
  D3DXVec3Transform();
  D3DXVec3Transform(piVar5 + 0xc,piVar5 + 0xc,iVar7);
  D3DXVec3Transform(piVar2,piVar2,iVar7);
  D3DXVec3Transform(piVar5 + 0x14,piVar5 + 0x14,iVar7);
  piVar5[0xe] = (int)piVar1;
  piVar5[10] = (int)piVar1;
  piVar5[0x12] = (int)piVar1;
  piVar5[0x16] = (int)piVar1;
  piVar5[0x18] = (int)piVar1;
  piVar5[0x19] = iVar7;
  piVar5[0x1b] = unaff_EBP;
  piVar5[0x1c] = iVar7;
  piVar5[0x1e] = unaff_EBP;
  piVar5[0x1a] = 0x3f800000;
  piVar5[0x1d] = 0x3f800000;
  piVar5[0x20] = 0x3f800000;
  piVar5[0x23] = 0x3f800000;
  piVar5[0x1f] = unaff_EDI;
  piVar5[0x21] = (int)piVar1;
  piVar5[0x22] = unaff_EDI;
  piVar5[0x24] = *unaff_ESI;
  piVar5[0x25] = unaff_ESI[1];
  piVar5[0x26] = unaff_ESI[2];
  piVar5[0x27] = unaff_ESI[3];
  *(undefined1 *)((int)piVar5 + 0xa5) = 1;
  return piVar5;
}


// ==== 0x5146d0 FUN_005146d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005146d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,int param_7,int param_8,undefined4 *param_9,
                 int param_10,int param_11,int param_12)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined1 uVar7;
  byte *pbVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  float *pfVar12;
  int iVar13;
  undefined1 *puVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int *piVar18;
  int *piVar19;
  int *piVar20;
  int iStack_2c0;
  undefined4 *apuStack_2bc [3];
  undefined4 *local_280;
  int local_27c;
  int local_278;
  int local_274;
  int aiStack_268 [6];
  undefined4 local_250;
  undefined4 local_24c;
  undefined4 local_248;
  undefined1 auStack_244 [4];
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_220;
  undefined4 local_21c;
  undefined4 local_218;
  undefined4 uStack_200;
  int aiStack_1fc [13];
  float local_1c8;
  float local_1c4;
  undefined1 auStack_140 [48];
  float local_110 [20];
  undefined1 auStack_c0 [188];
  
  if (param_12 == 0) {
    apuStack_2bc[2] = (undefined4 *)param_11;
    apuStack_2bc[1] = (undefined4 *)param_10;
    apuStack_2bc[0] = param_9;
    iStack_2c0 = param_8;
    FUN_00514530(param_2,param_3,param_4,param_5,param_6,param_7);
    return;
  }
  local_250 = param_2;
  local_24c = param_3;
  local_248 = param_6;
  local_240 = param_4;
  local_23c = param_3;
  local_238 = param_6;
  local_230 = param_4;
  local_22c = param_5;
  local_228 = param_6;
  local_220 = param_2;
  local_21c = param_5;
  local_218 = param_6;
  local_280 = param_9;
  local_27c = param_10;
  local_278 = param_7;
  local_274 = param_10;
  pbVar8 = (byte *)(param_11 + 2);
  iVar13 = 4;
  pfVar12 = local_110 + 2;
  do {
    bVar1 = pbVar8[-2];
    bVar2 = pbVar8[-1];
    bVar3 = *pbVar8;
    bVar4 = pbVar8[1];
    pbVar8 = pbVar8 + 4;
    local_1c8 = (float)bVar3 * _K_BLUR_MIN_T;
    iVar13 = iVar13 + -1;
    *pfVar12 = local_1c8;
    local_1c4 = (float)bVar4 * _K_BLUR_MIN_T;
    pfVar12[-2] = (float)bVar1 * _K_BLUR_MIN_T;
    pfVar12[1] = local_1c4;
    pfVar12[-1] = (float)bVar2 * _K_BLUR_MIN_T;
    pfVar12 = pfVar12 + 4;
  } while (iVar13 != 0);
  iVar13 = param_1 + 0x20;
  apuStack_2bc[1] = &local_250;
  apuStack_2bc[0] = &local_250;
  iStack_2c0 = 0x514853;
  apuStack_2bc[2] = (undefined4 *)iVar13;
  D3DXVec3Transform();
  iStack_2c0 = iVar13;
  D3DXVec3Transform(&local_24c,&local_24c);
  D3DXVec3Transform(&local_248,&local_248,iVar13);
  D3DXVec3Transform(auStack_244,auStack_244,iVar13);
  if ((*(byte *)(param_12 + 0x50) & 1) == 0) {
    iVar13 = FUN_00514c80(param_1,param_12,&local_280,&iStack_2c0,auStack_140,auStack_c0,&uStack_200
                         );
  }
  else {
    iVar13 = FUN_0051a5f0(param_1,param_12,&local_280,&iStack_2c0,auStack_140,auStack_c0);
  }
  if (iVar13 != 0) {
    puVar14 = (undefined1 *)((int)&uStack_200 + 2);
    iVar17 = iVar13;
    do {
      uVar7 = _ftol_nocw();
      puVar14[-2] = uVar7;
      uVar7 = _ftol_nocw();
      puVar14[-1] = uVar7;
      uVar7 = _ftol_nocw();
      *puVar14 = uVar7;
      uVar7 = _ftol_nocw();
      puVar14[1] = uVar7;
      puVar14 = puVar14 + 4;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    uVar9 = iVar17 - 2;
    if (uVar9 != 0) {
      uVar15 = 0;
      iVar13 = DAT_00735708;
      piVar19 = aiStack_268;
      while (*(int *)(iVar13 + 0x18) != *(int *)(iVar13 + 0x2c)) {
        iVar17 = iVar13;
        if (DAT_0073570c == 0) {
          piVar11 = *(int **)(iVar13 + 0x10);
          iVar10 = *(int *)(iVar13 + 0x18) + 1;
          if (piVar11 != (int *)0x0) {
            iVar5 = *piVar11;
            if (*(int *)(iVar13 + 0x1c) < iVar10) {
              *(int *)(iVar13 + 0x1c) = iVar10;
            }
            *(int *)(iVar13 + 0x18) = iVar10;
            *(int *)(iVar13 + 0x10) = iVar5;
          }
        }
        else {
          piVar18 = (int *)(iVar13 + 0x10);
          piVar20 = piVar19;
          if ((*(int *)(iVar13 + 0x10) == 0) && ((*(byte *)(iVar13 + 0x14) & 1) != 0)) {
            FUN_00566e60();
            iVar17 = DAT_00735708;
          }
          piVar11 = (int *)*piVar18;
          iVar10 = *(int *)(iVar13 + 0x18) + 1;
          if (piVar11 != (int *)0x0) {
            iVar5 = *piVar11;
            if (*(int *)(iVar13 + 0x1c) < iVar10) {
              *(int *)(iVar13 + 0x1c) = iVar10;
            }
            *(int *)(iVar13 + 0x18) = iVar10;
            *piVar18 = iVar5;
            if (((*(byte *)(iVar13 + 0x14) & 2) != 0) &&
               (iVar13 = *(int *)(iVar13 + 0x28) >> 2, piVar18 = piVar11, 0 < iVar13)) {
              for (; piVar19 = piVar20, iVar13 != 0; iVar13 = iVar13 + -1) {
                *piVar18 = 0;
                piVar18 = piVar18 + 1;
              }
            }
          }
        }
        if (piVar11 == (int *)0x0) {
          piVar11 = (int *)0x0;
        }
        else {
          ePoly__ePoly();
        }
        piVar11[0x2c] = 0;
        puVar6 = *(undefined4 **)(param_1 + 0x1c);
        *puVar6 = piVar11;
        *(int **)(param_1 + 0x1c) = piVar11;
        piVar11[1] = (int)puVar6;
        *piVar11 = param_1 + 0x18;
        piVar11[8] = (int)local_280;
        piVar11[9] = local_27c;
        uVar16 = uVar15 + 1;
        piVar11[10] = local_278;
        piVar11[0x18] = iStack_2c0;
        piVar11[0x24] = uStack_200;
        piVar11[0x19] = (int)apuStack_2bc[0];
        iVar5 = (&iStack_2c0)[uVar16 * 2];
        piVar11[0x1a] = 0x3f800000;
        iVar13 = piVar19[-1];
        iVar10 = *piVar19;
        piVar11[0xc] = piVar19[-2];
        piVar11[0xd] = iVar13;
        piVar11[0xe] = iVar10;
        piVar11[0x1b] = iVar5;
        piVar11[0x1c] = (int)apuStack_2bc[uVar16 * 2];
        piVar11[0x25] = aiStack_1fc[uVar15];
        puVar6 = apuStack_2bc[uVar16 * 2 + 1];
        piVar11[0x1d] = 0x3f800000;
        iVar13 = piVar19[3];
        iVar10 = piVar19[4];
        piVar11[0x10] = piVar19[2];
        piVar11[0x11] = iVar13;
        piVar11[0x12] = iVar10;
        piVar11[0x1e] = (int)puVar6;
        puVar6 = apuStack_2bc[uVar16 * 2 + 2];
        piVar11[0x20] = 0x3f800000;
        iVar13 = aiStack_1fc[uVar16];
        piVar11[0x1f] = (int)puVar6;
        piVar11[0x26] = iVar13;
        piVar11[0x14] = piVar11[0x10];
        piVar11[0x15] = piVar11[0x11];
        piVar11[0x16] = piVar11[0x12];
        piVar11[0x21] = piVar11[0x1e];
        piVar11[0x22] = piVar11[0x1f];
        piVar11[0x23] = piVar11[0x20];
        piVar11[0x27] = iVar13;
        *(undefined1 *)((int)piVar11 + 0xa5) = 1;
        uVar15 = uVar16;
        iVar13 = iVar17;
        piVar19 = piVar19 + 4;
        if (uVar9 <= uVar16) {
          return;
        }
      }
      _DAT_0078eaec = _DAT_0078eaec + 1;
    }
  }
  return;
}


// ==== 0x514b90 FUN_00514b90

void FUN_00514b90(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x18);
  if (piVar1 != (int *)(param_1 + 0x18)) {
    do {
      FUN_0040bef0();
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)(param_1 + 0x18));
  }
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 2;
  return;
}


// ==== 0x514bf0 FUN_00514bf0

void FUN_00514bf0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  iVar6 = DAT_00735708;
  piVar1 = (int *)(param_1 + 0x18);
  piVar2 = *(int **)(param_1 + 0x18);
  while (piVar2 != piVar1) {
    piVar2 = (int *)*piVar1;
    iVar3 = *piVar2;
    piVar4 = (int *)piVar2[1];
    *piVar4 = iVar3;
    *(int **)(iVar3 + 4) = piVar4;
    piVar4 = (int *)piVar2[0x28];
    if (piVar4 != (int *)0x0) {
      iVar3 = *piVar4;
      piVar5 = (int *)piVar4[1];
      *piVar5 = iVar3;
      *(int **)(iVar3 + 4) = piVar5;
      *DAT_00743c7c = (int)piVar4;
      piVar5 = piVar4;
      piVar4[1] = (int)DAT_00743c7c;
      DAT_00743c7c = piVar5;
      *piVar4 = (int)&DAT_00743c78;
      piVar2[0x28] = 0;
    }
    iVar3 = *(int *)(iVar6 + 0x18);
    *piVar2 = *(int *)(iVar6 + 0x10);
    *(int *)(iVar6 + 0x18) = iVar3 + -1;
    *(int **)(iVar6 + 0x10) = piVar2;
    piVar2 = (int *)*piVar1;
  }
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffffd;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


// ==== 0x514c80 FUN_00514c80

uint FUN_00514c80(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 *param_6,undefined4 *param_7)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
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
  undefined4 *in_EAX;
  int iVar18;
  float fVar19;
  float *pfVar20;
  undefined4 *puVar21;
  float *pfVar22;
  float *pfVar23;
  float *pfVar24;
  float *pfVar25;
  undefined4 *puVar26;
  undefined4 *puVar27;
  float *pfVar28;
  float *pfVar29;
  int iVar30;
  bool bVar31;
  float *local_148;
  uint local_144;
  undefined4 *local_128;
  float *local_120;
  undefined4 *local_11c;
  float *local_118;
  uint local_114;
  uint local_104;
  uint local_f4;
  int local_cc;
  undefined4 *local_c4;
  float *local_6c;
  int local_5c;
  int local_48;
  int local_44;
  
  local_c4 = param_6;
  local_5c = -(int)param_3;
  local_44 = -(int)param_6;
  local_128 = param_7;
  local_6c = (float *)(param_2 + 0x40);
  pfVar28 = (float *)(param_2 + 8);
  local_11c = param_5;
  local_f4 = 4;
  local_48 = 0;
  do {
    puVar27 = param_4;
    puVar26 = param_3;
    puVar21 = in_EAX;
    iVar17 = local_44;
    if (local_f4 == 0) {
      return 0;
    }
    fVar1 = pfVar28[-2];
    fVar2 = pfVar28[-1];
    fVar14 = *pfVar28;
    fVar15 = *local_6c;
    local_118 = (float *)(local_f4 - 1);
    local_120 = (float *)((int)local_118 * 0x10);
    bVar31 = -0.5 < fVar1 * (float)puVar26[(int)local_118 * 4] +
                    fVar2 * (float)puVar26[(int)local_118 * 4 + 1] +
                    fVar14 * (float)puVar26[(int)local_118 * 4 + 2] + fVar15;
    if (bVar31) {
      uVar3 = puVar26[(int)local_118 * 4 + 1];
      uVar4 = puVar26[(int)local_118 * 4 + 2];
      *local_c4 = puVar26[(int)local_118 * 4];
      local_c4[1] = uVar3;
      local_c4[2] = uVar4;
      uVar3 = puVar27[(int)local_118 * 2 + 1];
      *local_128 = puVar27[(int)local_118 * 2];
      local_128[1] = uVar3;
      uVar3 = local_11c[(int)local_118 * 4 + 1];
      uVar4 = local_11c[(int)local_118 * 4 + 2];
      uVar5 = local_11c[(int)local_118 * 4 + 3];
      *puVar21 = local_11c[(int)local_118 * 4];
      puVar21[1] = uVar3;
      puVar21[3] = uVar5;
      puVar21[2] = uVar4;
    }
    local_144 = (uint)bVar31;
    local_114 = 0;
    if (3 < (int)local_f4) {
      local_cc = (int)local_118 * 8;
      pfVar24 = (float *)(puVar21 + local_144 * 4);
      pfVar23 = (float *)(local_c4 + local_144 * 4);
      iVar18 = (int)local_11c - (int)puVar26;
      local_148 = (float *)(puVar27 + 3);
      pfVar20 = (float *)(local_11c + 7);
      pfVar25 = (float *)(puVar26 + 6);
      local_104 = 3;
      do {
        if (fVar1 * pfVar25[-6] + fVar2 * pfVar25[-5] + fVar14 * pfVar25[-4] + fVar15 <= -0.5) {
          if (bVar31) {
            fVar6 = *(float *)((int)local_120 + 4 + (int)puVar26);
            fVar7 = pfVar25[-5];
            fVar8 = *(float *)((int)local_120 + 8 + (int)puVar26);
            fVar9 = pfVar25[-4];
            *pfVar23 = pfVar25[-6] - *(float *)((int)local_120 + (int)puVar26);
            pfVar23[2] = fVar9 - fVar8;
            pfVar23[1] = fVar7 - fVar6;
            fVar16 = -((fVar1 * *(float *)((int)local_120 + (int)puVar26) +
                        fVar2 * *(float *)((int)local_120 + 4 + (int)puVar26) +
                        fVar14 * *(float *)((int)local_120 + 8 + (int)puVar26) + fVar15) /
                      (fVar2 * pfVar23[1] + fVar14 * pfVar23[2] + fVar1 * *pfVar23));
            *pfVar23 = fVar16 * *pfVar23;
            pfVar23[1] = fVar16 * pfVar23[1];
            pfVar23[2] = fVar16 * pfVar23[2];
            fVar6 = *(float *)((int)local_120 + 4 + (int)puVar26);
            fVar7 = *(float *)((int)local_120 + 8 + (int)puVar26);
            *pfVar23 = *(float *)((int)local_120 + (int)puVar26) + *pfVar23;
            pfVar23[1] = fVar6 + pfVar23[1];
            pfVar23[2] = fVar7 + pfVar23[2];
            fVar6 = local_148[-2];
            fVar7 = *(float *)(local_cc + 4 + (int)puVar27);
            pfVar23 = pfVar23 + 4;
            fVar8 = *(float *)(local_cc + 4 + (int)puVar27);
            local_128[local_144 * 2] =
                 (local_148[-3] - *(float *)(local_cc + (int)puVar27)) * fVar16 +
                 *(float *)(local_cc + (int)puVar27);
            bVar31 = false;
            local_128[local_144 * 2 + 1] = fVar8 + (fVar6 - fVar7) * fVar16;
            fVar6 = pfVar20[-7];
            fVar7 = *(float *)((int)local_120 + (int)local_11c);
            fVar8 = pfVar20[-6];
            fVar9 = *(float *)((int)local_120 + 4 + (int)local_11c);
            fVar10 = pfVar20[-4];
            fVar11 = *(float *)((int)local_120 + 0xc + (int)local_11c);
            fVar19 = *(float *)((int)local_120 + (int)local_11c);
            fVar12 = *(float *)((int)local_120 + 4 + (int)local_11c);
            fVar13 = *(float *)((int)local_120 + 0xc + (int)local_11c);
            pfVar24[2] = *(float *)((int)local_120 + 8 + (int)local_11c) +
                         (pfVar20[-5] - *(float *)((int)local_120 + 8 + (int)local_11c)) * fVar16;
            local_144 = local_144 + 1;
            *pfVar24 = (fVar6 - fVar7) * fVar16 + fVar19;
            pfVar24[3] = fVar13 + fVar16 * (fVar10 - fVar11);
            pfVar24[1] = fVar12 + (fVar8 - fVar9) * fVar16;
            pfVar24 = pfVar24 + 4;
          }
        }
        else {
          pfVar22 = pfVar23;
          pfVar29 = pfVar24;
          if (!bVar31) {
            fVar6 = *(float *)((int)local_120 + 4 + (int)puVar26);
            fVar7 = pfVar25[-5];
            fVar8 = *(float *)((int)local_120 + 8 + (int)puVar26);
            fVar9 = pfVar25[-4];
            *pfVar23 = pfVar25[-6] - *(float *)((int)local_120 + (int)puVar26);
            pfVar23[2] = fVar9 - fVar8;
            pfVar23[1] = fVar7 - fVar6;
            fVar16 = -((fVar1 * *(float *)((int)local_120 + (int)puVar26) +
                        fVar2 * *(float *)((int)local_120 + 4 + (int)puVar26) +
                        fVar14 * *(float *)((int)local_120 + 8 + (int)puVar26) + fVar15) /
                      (fVar2 * pfVar23[1] + fVar14 * pfVar23[2] + fVar1 * *pfVar23));
            *pfVar23 = fVar16 * *pfVar23;
            pfVar23[1] = fVar16 * pfVar23[1];
            pfVar23[2] = fVar16 * pfVar23[2];
            fVar6 = *(float *)((int)local_120 + 4 + (int)puVar26);
            fVar7 = *(float *)((int)local_120 + 8 + (int)puVar26);
            *pfVar23 = *(float *)((int)local_120 + (int)puVar26) + *pfVar23;
            pfVar23[1] = fVar6 + pfVar23[1];
            pfVar23[2] = fVar7 + pfVar23[2];
            fVar6 = local_148[-2];
            fVar7 = *(float *)(local_cc + 4 + (int)puVar27);
            fVar8 = *(float *)(local_cc + 4 + (int)puVar27);
            local_128[local_144 * 2] =
                 (local_148[-3] - *(float *)(local_cc + (int)puVar27)) * fVar16 +
                 *(float *)(local_cc + (int)puVar27);
            bVar31 = true;
            local_128[local_144 * 2 + 1] = fVar8 + (fVar6 - fVar7) * fVar16;
            fVar6 = pfVar20[-7];
            fVar7 = *(float *)((int)local_120 + (int)local_11c);
            fVar8 = pfVar20[-6];
            fVar9 = *(float *)((int)local_120 + 4 + (int)local_11c);
            fVar10 = pfVar20[-4];
            fVar11 = *(float *)((int)local_120 + 0xc + (int)local_11c);
            fVar19 = *(float *)((int)local_120 + (int)local_11c);
            fVar12 = *(float *)((int)local_120 + 4 + (int)local_11c);
            fVar13 = *(float *)((int)local_120 + 0xc + (int)local_11c);
            pfVar24[2] = *(float *)((int)local_120 + 8 + (int)local_11c) +
                         (pfVar20[-5] - *(float *)((int)local_120 + 8 + (int)local_11c)) * fVar16;
            local_144 = local_144 + 1;
            *pfVar24 = (fVar6 - fVar7) * fVar16 + fVar19;
            pfVar24[3] = fVar13 + fVar16 * (fVar10 - fVar11);
            pfVar24[1] = fVar12 + (fVar8 - fVar9) * fVar16;
            pfVar22 = pfVar23 + 4;
            pfVar29 = pfVar24 + 4;
          }
          fVar6 = pfVar25[-5];
          fVar7 = pfVar25[-4];
          *pfVar22 = pfVar25[-6];
          pfVar22[1] = fVar6;
          local_144 = local_144 + 1;
          pfVar23 = pfVar22 + 4;
          pfVar22[2] = fVar7;
          fVar6 = local_148[-2];
          pfVar24 = pfVar29 + 4;
          local_128[local_144 * 2 + -2] = local_148[-3];
          local_128[local_144 * 2 + -1] = fVar6;
          fVar6 = pfVar20[-6];
          fVar7 = pfVar20[-5];
          fVar8 = pfVar20[-7];
          pfVar29[3] = pfVar20[-4];
          *pfVar29 = fVar8;
          pfVar29[1] = fVar6;
          pfVar29[2] = fVar7;
        }
        if (fVar2 * pfVar25[-1] + fVar14 * *pfVar25 + fVar1 * pfVar25[-2] + fVar15 <= -0.5) {
          if (bVar31) {
            fVar6 = pfVar25[-1];
            fVar7 = pfVar25[-5];
            fVar8 = *pfVar25;
            fVar9 = pfVar25[-4];
            *pfVar23 = pfVar25[-2] - pfVar25[-6];
            pfVar23[2] = fVar8 - fVar9;
            pfVar23[1] = fVar6 - fVar7;
            fVar12 = -((fVar1 * pfVar25[-6] + fVar2 * pfVar25[-5] + fVar14 * pfVar25[-4] + fVar15) /
                      (fVar2 * pfVar23[1] + fVar14 * pfVar23[2] + fVar1 * *pfVar23));
            *pfVar23 = fVar12 * *pfVar23;
            pfVar23[1] = fVar12 * pfVar23[1];
            pfVar23[2] = fVar12 * pfVar23[2];
            fVar6 = pfVar25[-5];
            fVar7 = pfVar25[-4];
            *pfVar23 = pfVar25[-6] + *pfVar23;
            pfVar23[1] = fVar6 + pfVar23[1];
            pfVar23[2] = fVar7 + pfVar23[2];
            fVar6 = *local_148;
            fVar7 = local_148[-2];
            fVar8 = local_148[-2];
            local_128[local_144 * 2] = (local_148[-1] - local_148[-3]) * fVar12 + local_148[-3];
            local_128[local_144 * 2 + 1] = (fVar6 - fVar7) * fVar12 + fVar8;
            fVar6 = pfVar20[-3];
            fVar7 = pfVar20[-7];
            fVar8 = pfVar20[-2];
            bVar31 = false;
            fVar9 = pfVar20[-6];
            fVar10 = pfVar20[-7];
            fVar11 = pfVar20[-6];
            fVar19 = fVar12 * (*pfVar20 - pfVar20[-4]) + pfVar20[-4];
            pfVar24[2] = (*(float *)((int)pfVar25 + iVar18) - pfVar20[-5]) * fVar12 + pfVar20[-5];
            *pfVar24 = (fVar6 - fVar7) * fVar12 + fVar10;
            pfVar24[1] = (fVar8 - fVar9) * fVar12 + fVar11;
            goto LAB_005155fb;
          }
        }
        else {
          pfVar22 = pfVar24;
          if (!bVar31) {
            fVar6 = pfVar25[-1];
            fVar7 = pfVar25[-5];
            fVar8 = *pfVar25;
            fVar9 = pfVar25[-4];
            *pfVar23 = pfVar25[-2] - pfVar25[-6];
            pfVar23[2] = fVar8 - fVar9;
            pfVar23[1] = fVar6 - fVar7;
            fVar16 = -((fVar1 * pfVar25[-6] + fVar2 * pfVar25[-5] + fVar14 * pfVar25[-4] + fVar15) /
                      (fVar2 * pfVar23[1] + fVar14 * pfVar23[2] + fVar1 * *pfVar23));
            *pfVar23 = fVar16 * *pfVar23;
            pfVar23[1] = fVar16 * pfVar23[1];
            pfVar23[2] = fVar16 * pfVar23[2];
            fVar6 = pfVar25[-5];
            fVar7 = pfVar25[-4];
            *pfVar23 = pfVar25[-6] + *pfVar23;
            pfVar23[1] = fVar6 + pfVar23[1];
            pfVar23[2] = fVar7 + pfVar23[2];
            fVar6 = *local_148;
            fVar7 = local_148[-2];
            fVar8 = local_148[-2];
            local_128[local_144 * 2] = (local_148[-1] - local_148[-3]) * fVar16 + local_148[-3];
            local_128[local_144 * 2 + 1] = (fVar6 - fVar7) * fVar16 + fVar8;
            fVar6 = pfVar20[-3];
            fVar7 = pfVar20[-7];
            fVar8 = pfVar20[-2];
            local_144 = local_144 + 1;
            fVar9 = pfVar20[-6];
            pfVar23 = pfVar23 + 4;
            fVar10 = *pfVar20;
            pfVar22 = pfVar24 + 4;
            fVar11 = pfVar20[-4];
            bVar31 = true;
            fVar19 = pfVar20[-7];
            fVar12 = pfVar20[-6];
            fVar13 = pfVar20[-4];
            pfVar24[2] = (*(float *)((int)pfVar25 + iVar18) - pfVar20[-5]) * fVar16 + pfVar20[-5];
            *pfVar24 = (fVar6 - fVar7) * fVar16 + fVar19;
            pfVar24[3] = fVar16 * (fVar10 - fVar11) + fVar13;
            pfVar24[1] = (fVar8 - fVar9) * fVar16 + fVar12;
          }
          fVar6 = pfVar25[-1];
          fVar7 = *pfVar25;
          *pfVar23 = pfVar25[-2];
          pfVar23[1] = fVar6;
          pfVar23[2] = fVar7;
          fVar6 = *local_148;
          local_128[local_144 * 2] = local_148[-1];
          local_128[local_144 * 2 + 1] = fVar6;
          fVar6 = pfVar20[-2];
          fVar7 = *(float *)((int)pfVar25 + iVar18);
          fVar19 = *pfVar20;
          *pfVar22 = pfVar20[-3];
          pfVar22[1] = fVar6;
          pfVar22[2] = fVar7;
          pfVar24 = pfVar22;
LAB_005155fb:
          local_144 = local_144 + 1;
          pfVar24[3] = fVar19;
          pfVar23 = pfVar23 + 4;
          pfVar24 = pfVar24 + 4;
        }
        if (fVar1 * pfVar25[2] + fVar2 * pfVar25[3] + fVar14 * pfVar25[4] + fVar15 <= -0.5) {
          if (bVar31) {
            fVar6 = pfVar25[3];
            fVar7 = pfVar25[-1];
            fVar8 = pfVar25[4];
            fVar9 = *pfVar25;
            *pfVar23 = pfVar25[2] - pfVar25[-2];
            pfVar23[2] = fVar8 - fVar9;
            pfVar23[1] = fVar6 - fVar7;
            fVar12 = -((fVar2 * pfVar25[-1] + fVar14 * *pfVar25 + fVar1 * pfVar25[-2] + fVar15) /
                      (fVar2 * pfVar23[1] + fVar14 * pfVar23[2] + fVar1 * *pfVar23));
            *pfVar23 = fVar12 * *pfVar23;
            pfVar23[1] = fVar12 * pfVar23[1];
            pfVar23[2] = fVar12 * pfVar23[2];
            fVar6 = pfVar25[-1];
            fVar7 = *pfVar25;
            *pfVar23 = pfVar25[-2] + *pfVar23;
            pfVar23[1] = fVar6 + pfVar23[1];
            pfVar23[2] = fVar7 + pfVar23[2];
            fVar6 = local_148[2];
            fVar7 = *local_148;
            fVar8 = *local_148;
            local_128[local_144 * 2] = (local_148[1] - local_148[-1]) * fVar12 + local_148[-1];
            local_128[local_144 * 2 + 1] = (fVar6 - fVar7) * fVar12 + fVar8;
            fVar6 = pfVar20[1];
            fVar7 = pfVar20[-3];
            fVar8 = pfVar20[2];
            bVar31 = false;
            fVar9 = pfVar20[-2];
            fVar10 = pfVar20[-3];
            fVar11 = pfVar20[-2];
            fVar19 = fVar12 * (pfVar20[4] - *pfVar20) + *pfVar20;
            pfVar24[2] = (pfVar20[3] - *(float *)((int)pfVar25 + iVar18)) * fVar12 +
                         *(float *)((int)pfVar25 + iVar18);
            *pfVar24 = (fVar6 - fVar7) * fVar12 + fVar10;
            pfVar24[1] = (fVar8 - fVar9) * fVar12 + fVar11;
            goto LAB_00515959;
          }
        }
        else {
          pfVar22 = pfVar24;
          if (!bVar31) {
            fVar6 = pfVar25[3];
            fVar7 = pfVar25[-1];
            fVar8 = pfVar25[4];
            fVar9 = *pfVar25;
            *pfVar23 = pfVar25[2] - pfVar25[-2];
            pfVar23[2] = fVar8 - fVar9;
            pfVar23[1] = fVar6 - fVar7;
            fVar16 = -((fVar2 * pfVar25[-1] + fVar14 * *pfVar25 + fVar1 * pfVar25[-2] + fVar15) /
                      (fVar2 * pfVar23[1] + fVar14 * pfVar23[2] + fVar1 * *pfVar23));
            *pfVar23 = fVar16 * *pfVar23;
            pfVar23[1] = fVar16 * pfVar23[1];
            pfVar23[2] = fVar16 * pfVar23[2];
            fVar6 = pfVar25[-1];
            fVar7 = *pfVar25;
            *pfVar23 = pfVar25[-2] + *pfVar23;
            pfVar23[1] = fVar6 + pfVar23[1];
            pfVar23[2] = fVar7 + pfVar23[2];
            fVar6 = local_148[2];
            fVar7 = *local_148;
            fVar8 = *local_148;
            local_128[local_144 * 2] = (local_148[1] - local_148[-1]) * fVar16 + local_148[-1];
            local_128[local_144 * 2 + 1] = (fVar6 - fVar7) * fVar16 + fVar8;
            fVar6 = pfVar20[1];
            fVar7 = pfVar20[-3];
            fVar8 = pfVar20[2];
            local_144 = local_144 + 1;
            fVar9 = pfVar20[-2];
            pfVar23 = pfVar23 + 4;
            fVar10 = pfVar20[4];
            pfVar22 = pfVar24 + 4;
            fVar11 = *pfVar20;
            bVar31 = true;
            fVar19 = pfVar20[-3];
            fVar12 = pfVar20[-2];
            fVar13 = *pfVar20;
            pfVar24[2] = (pfVar20[3] - *(float *)((int)pfVar25 + iVar18)) * fVar16 +
                         *(float *)((int)pfVar25 + iVar18);
            *pfVar24 = (fVar6 - fVar7) * fVar16 + fVar19;
            pfVar24[3] = fVar16 * (fVar10 - fVar11) + fVar13;
            pfVar24[1] = (fVar8 - fVar9) * fVar16 + fVar12;
          }
          fVar6 = pfVar25[3];
          fVar7 = pfVar25[4];
          *pfVar23 = pfVar25[2];
          pfVar23[1] = fVar6;
          pfVar23[2] = fVar7;
          fVar6 = local_148[2];
          local_128[local_144 * 2] = local_148[1];
          local_128[local_144 * 2 + 1] = fVar6;
          fVar19 = pfVar20[4];
          fVar6 = pfVar20[2];
          fVar7 = pfVar20[3];
          *pfVar22 = pfVar20[1];
          pfVar22[1] = fVar6;
          pfVar22[2] = fVar7;
          pfVar24 = pfVar22;
LAB_00515959:
          local_144 = local_144 + 1;
          pfVar24[3] = fVar19;
          pfVar23 = pfVar23 + 4;
          pfVar24 = pfVar24 + 4;
        }
        if (fVar1 * pfVar25[6] + fVar2 * pfVar25[7] + fVar14 * pfVar25[8] + fVar15 <= -0.5) {
          if (bVar31) {
            fVar6 = pfVar25[7];
            fVar7 = pfVar25[3];
            fVar8 = pfVar25[8];
            fVar9 = pfVar25[4];
            *pfVar23 = pfVar25[6] - pfVar25[2];
            pfVar23[2] = fVar8 - fVar9;
            pfVar23[1] = fVar6 - fVar7;
            fVar12 = -((fVar1 * pfVar25[2] + fVar2 * pfVar25[3] + fVar14 * pfVar25[4] + fVar15) /
                      (fVar2 * pfVar23[1] + fVar14 * pfVar23[2] + fVar1 * *pfVar23));
            *pfVar23 = fVar12 * *pfVar23;
            pfVar23[1] = fVar12 * pfVar23[1];
            pfVar23[2] = fVar12 * pfVar23[2];
            fVar6 = pfVar25[3];
            fVar7 = pfVar25[4];
            *pfVar23 = pfVar25[2] + *pfVar23;
            pfVar23[1] = fVar6 + pfVar23[1];
            pfVar23[2] = fVar7 + pfVar23[2];
            fVar6 = local_148[4];
            fVar7 = local_148[2];
            fVar8 = local_148[2];
            local_128[local_144 * 2] = (local_148[3] - local_148[1]) * fVar12 + local_148[1];
            local_128[local_144 * 2 + 1] = (fVar6 - fVar7) * fVar12 + fVar8;
            fVar6 = pfVar20[5];
            fVar7 = pfVar20[1];
            fVar8 = pfVar20[6];
            bVar31 = false;
            fVar9 = pfVar20[2];
            fVar10 = pfVar20[1];
            fVar11 = pfVar20[2];
            fVar19 = fVar12 * (pfVar20[8] - pfVar20[4]) + pfVar20[4];
            pfVar24[2] = (pfVar20[7] - pfVar20[3]) * fVar12 + pfVar20[3];
            *pfVar24 = (fVar6 - fVar7) * fVar12 + fVar10;
            pfVar24[1] = (fVar8 - fVar9) * fVar12 + fVar11;
            goto LAB_00515cbd;
          }
        }
        else {
          pfVar22 = pfVar24;
          if (!bVar31) {
            fVar6 = pfVar25[7];
            fVar7 = pfVar25[3];
            fVar8 = pfVar25[8];
            fVar9 = pfVar25[4];
            *pfVar23 = pfVar25[6] - pfVar25[2];
            pfVar23[2] = fVar8 - fVar9;
            pfVar23[1] = fVar6 - fVar7;
            fVar16 = -((fVar1 * pfVar25[2] + fVar2 * pfVar25[3] + fVar14 * pfVar25[4] + fVar15) /
                      (fVar2 * pfVar23[1] + fVar14 * pfVar23[2] + fVar1 * *pfVar23));
            *pfVar23 = fVar16 * *pfVar23;
            pfVar23[1] = fVar16 * pfVar23[1];
            pfVar23[2] = fVar16 * pfVar23[2];
            fVar6 = pfVar25[3];
            fVar7 = pfVar25[4];
            *pfVar23 = pfVar25[2] + *pfVar23;
            pfVar23[1] = fVar6 + pfVar23[1];
            pfVar23[2] = fVar7 + pfVar23[2];
            fVar6 = local_148[4];
            fVar7 = local_148[2];
            fVar8 = local_148[2];
            local_128[local_144 * 2] = (local_148[3] - local_148[1]) * fVar16 + local_148[1];
            local_128[local_144 * 2 + 1] = (fVar6 - fVar7) * fVar16 + fVar8;
            fVar6 = pfVar20[5];
            fVar7 = pfVar20[1];
            fVar8 = pfVar20[6];
            local_144 = local_144 + 1;
            fVar9 = pfVar20[2];
            pfVar23 = pfVar23 + 4;
            fVar10 = pfVar20[8];
            pfVar22 = pfVar24 + 4;
            fVar11 = pfVar20[4];
            bVar31 = true;
            fVar19 = pfVar20[1];
            fVar12 = pfVar20[2];
            fVar13 = pfVar20[4];
            pfVar24[2] = (pfVar20[7] - pfVar20[3]) * fVar16 + pfVar20[3];
            *pfVar24 = (fVar6 - fVar7) * fVar16 + fVar19;
            pfVar24[3] = fVar16 * (fVar10 - fVar11) + fVar13;
            pfVar24[1] = (fVar8 - fVar9) * fVar16 + fVar12;
          }
          fVar6 = pfVar25[7];
          fVar7 = pfVar25[8];
          *pfVar23 = pfVar25[6];
          pfVar23[1] = fVar6;
          pfVar23[2] = fVar7;
          fVar6 = local_148[4];
          local_128[local_144 * 2] = local_148[3];
          local_128[local_144 * 2 + 1] = fVar6;
          fVar19 = pfVar20[8];
          fVar6 = pfVar20[6];
          fVar7 = pfVar20[7];
          *pfVar22 = pfVar20[5];
          pfVar22[1] = fVar6;
          pfVar22[2] = fVar7;
          pfVar24 = pfVar22;
LAB_00515cbd:
          local_144 = local_144 + 1;
          pfVar24[3] = fVar19;
          pfVar23 = pfVar23 + 4;
          pfVar24 = pfVar24 + 4;
        }
        local_118 = (float *)local_104;
        local_cc = (0xc - (int)puVar27) + (int)local_148;
        local_120 = (float *)((0x18 - (int)puVar26) + (int)pfVar25);
        local_148 = local_148 + 8;
        local_114 = local_114 + 4;
        local_104 = local_104 + 4;
        pfVar25 = pfVar25 + 0x10;
        pfVar20 = pfVar20 + 0x10;
      } while (local_104 < local_f4);
    }
    if (local_114 < local_f4) {
      local_104 = (int)local_118 << 3;
      pfVar25 = (float *)(puVar21 + local_144 * 4);
      pfVar24 = (float *)(local_c4 + local_144 * 4);
      local_120 = (float *)(local_11c + local_114 * 4 + 3);
      iVar18 = (int)local_118 << 4;
      iVar30 = (int)local_11c - (int)puVar26;
      pfVar20 = (float *)(puVar26 + local_114 * 4 + 2);
      local_118 = pfVar25;
      do {
        if (fVar1 * pfVar20[-2] + fVar14 * *pfVar20 + fVar2 * pfVar20[-1] + fVar15 <= -0.5) {
          if (bVar31) {
            fVar6 = *(float *)(iVar18 + 4 + (int)puVar26);
            fVar7 = pfVar20[-1];
            fVar8 = *(float *)(iVar18 + 8 + (int)puVar26);
            fVar9 = *pfVar20;
            *pfVar24 = pfVar20[-2] - *(float *)(iVar18 + (int)puVar26);
            pfVar24[2] = fVar9 - fVar8;
            pfVar24[1] = fVar7 - fVar6;
            fVar12 = -((fVar1 * *(float *)(iVar18 + (int)puVar26) +
                        fVar2 * *(float *)(iVar18 + 4 + (int)puVar26) +
                        fVar14 * *(float *)(iVar18 + 8 + (int)puVar26) + fVar15) /
                      (fVar2 * pfVar24[1] + fVar14 * pfVar24[2] + fVar1 * *pfVar24));
            *pfVar24 = fVar12 * *pfVar24;
            pfVar24[1] = fVar12 * pfVar24[1];
            pfVar24[2] = fVar12 * pfVar24[2];
            fVar6 = *(float *)(iVar18 + 4 + (int)puVar26);
            fVar7 = *(float *)(iVar18 + 8 + (int)puVar26);
            *pfVar24 = *(float *)(iVar18 + (int)puVar26) + *pfVar24;
            pfVar24[1] = fVar6 + pfVar24[1];
            pfVar24[2] = fVar7 + pfVar24[2];
            fVar6 = (float)puVar27[local_114 * 2 + 1];
            fVar7 = *(float *)(local_104 + 4 + (int)puVar27);
            fVar8 = *(float *)(local_104 + 4 + (int)puVar27);
            local_128[local_144 * 2] =
                 ((float)puVar27[local_114 * 2] - *(float *)(local_104 + (int)puVar27)) * fVar12 +
                 *(float *)(local_104 + (int)puVar27);
            bVar31 = false;
            local_128[local_144 * 2 + 1] = fVar8 + (fVar6 - fVar7) * fVar12;
            fVar6 = local_120[-3];
            fVar7 = *(float *)(iVar18 + (int)local_11c);
            fVar8 = local_120[-2];
            fVar9 = *(float *)(iVar18 + 4 + (int)local_11c);
            fVar10 = *(float *)(iVar18 + (int)local_11c);
            fVar11 = *(float *)(iVar18 + 4 + (int)local_11c);
            fVar19 = *(float *)(iVar18 + 0xc + (int)local_11c) +
                     fVar12 * (*local_120 - *(float *)(iVar18 + 0xc + (int)local_11c));
            local_118[2] = *(float *)(iVar18 + 8 + (int)local_11c) +
                           (*(float *)((int)pfVar20 + iVar30) -
                           *(float *)(iVar18 + 8 + (int)local_11c)) * fVar12;
            *local_118 = (fVar6 - fVar7) * fVar12 + fVar10;
            local_118[1] = fVar11 + (fVar8 - fVar9) * fVar12;
            goto LAB_00516197;
          }
        }
        else {
          if (!bVar31) {
            fVar6 = *(float *)(iVar18 + 4 + (int)puVar26);
            fVar7 = pfVar20[-1];
            fVar8 = *(float *)(iVar18 + 8 + (int)puVar26);
            fVar9 = *pfVar20;
            *pfVar24 = pfVar20[-2] - *(float *)(iVar18 + (int)puVar26);
            pfVar24[2] = fVar9 - fVar8;
            pfVar24[1] = fVar7 - fVar6;
            fVar16 = -((fVar1 * *(float *)(iVar18 + (int)puVar26) +
                        fVar2 * *(float *)(iVar18 + 4 + (int)puVar26) +
                        fVar14 * *(float *)(iVar18 + 8 + (int)puVar26) + fVar15) /
                      (fVar2 * pfVar24[1] + fVar14 * pfVar24[2] + fVar1 * *pfVar24));
            *pfVar24 = fVar16 * *pfVar24;
            pfVar24[1] = fVar16 * pfVar24[1];
            pfVar24[2] = fVar16 * pfVar24[2];
            fVar6 = *(float *)(iVar18 + 4 + (int)puVar26);
            fVar7 = *(float *)(iVar18 + 8 + (int)puVar26);
            *pfVar24 = *(float *)(iVar18 + (int)puVar26) + *pfVar24;
            pfVar24[1] = fVar6 + pfVar24[1];
            pfVar24[2] = fVar7 + pfVar24[2];
            fVar6 = (float)puVar27[local_114 * 2 + 1];
            fVar7 = *(float *)(local_104 + 4 + (int)puVar27);
            fVar8 = *(float *)(local_104 + 4 + (int)puVar27);
            local_128[local_144 * 2] =
                 ((float)puVar27[local_114 * 2] - *(float *)(local_104 + (int)puVar27)) * fVar16 +
                 *(float *)(local_104 + (int)puVar27);
            pfVar24 = pfVar24 + 4;
            bVar31 = true;
            local_128[local_144 * 2 + 1] = fVar8 + (fVar6 - fVar7) * fVar16;
            fVar6 = local_120[-3];
            fVar7 = *(float *)(iVar18 + (int)local_11c);
            fVar8 = local_120[-2];
            fVar9 = *(float *)(iVar18 + 4 + (int)local_11c);
            fVar10 = *(float *)(iVar18 + 0xc + (int)local_11c);
            fVar11 = *local_120;
            fVar19 = *(float *)(iVar18 + (int)local_11c);
            fVar12 = *(float *)(iVar18 + 4 + (int)local_11c);
            fVar13 = *(float *)(iVar18 + 0xc + (int)local_11c);
            local_118[2] = *(float *)(iVar18 + 8 + (int)local_11c) +
                           (*(float *)((int)pfVar20 + iVar30) -
                           *(float *)(iVar18 + 8 + (int)local_11c)) * fVar16;
            local_118[3] = fVar13 + fVar16 * (fVar11 - fVar10);
            *local_118 = (fVar6 - fVar7) * fVar16 + fVar19;
            local_144 = local_144 + 1;
            local_118[1] = fVar12 + (fVar8 - fVar9) * fVar16;
            pfVar25 = local_118 + 4;
          }
          local_118 = pfVar25;
          fVar6 = pfVar20[-1];
          fVar7 = *pfVar20;
          *pfVar24 = pfVar20[-2];
          pfVar24[1] = fVar6;
          pfVar24[2] = fVar7;
          uVar3 = puVar27[local_114 * 2 + 1];
          local_128[local_144 * 2] = puVar27[local_114 * 2];
          local_128[local_144 * 2 + 1] = uVar3;
          fVar6 = local_120[-2];
          fVar7 = *(float *)((int)pfVar20 + iVar30);
          fVar19 = *local_120;
          *local_118 = local_120[-3];
          local_118[1] = fVar6;
          local_118[2] = fVar7;
LAB_00516197:
          local_118[3] = fVar19;
          pfVar24 = pfVar24 + 4;
          local_144 = local_144 + 1;
          pfVar25 = local_118 + 4;
          local_118 = pfVar25;
        }
        local_104 = local_114 * 8;
        iVar18 = local_5c + -8 + (int)pfVar20;
        local_114 = local_114 + 1;
        pfVar20 = pfVar20 + 4;
        local_120 = local_120 + 4;
      } while (local_114 < local_f4);
    }
    local_44 = local_5c;
    local_5c = iVar17;
    local_f4 = local_144;
    local_48 = local_48 + 1;
    local_6c = local_6c + 1;
    pfVar28 = pfVar28 + 4;
    in_EAX = local_11c;
    param_3 = local_c4;
    param_4 = local_128;
    local_128 = puVar27;
    local_11c = puVar21;
    local_c4 = puVar26;
    if (3 < local_48) {
      return local_144;
    }
  } while( true );
}


// ==== 0x5162d0 FUN_005162d0

uint FUN_005162d0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,int param_4,
                 int param_5,int param_6,uint param_7,float param_8)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  bool bVar12;
  float fVar13;
  uint uVar14;
  float fVar15;
  float *pfVar16;
  float *pfVar17;
  float *pfVar18;
  int iVar19;
  int iVar20;
  float *pfVar21;
  float *pfVar22;
  float *pfVar23;
  uint local_e0;
  float *local_dc;
  float *local_d8;
  uint local_d4;
  uint local_d0;
  float *local_bc;
  
  local_d0 = param_7 - 1;
  local_d8 = (float *)(local_d0 * 0x10);
  bVar12 = param_8 <= *(float *)((int)local_d8 + param_4);
  if (bVar12) {
    uVar1 = *(undefined4 *)((int)local_d8 + 4 + param_4);
    uVar2 = *(undefined4 *)((int)local_d8 + 8 + param_4);
    *param_1 = *(undefined4 *)((int)local_d8 + param_4);
    param_1[1] = uVar1;
    param_1[2] = uVar2;
    uVar1 = *(undefined4 *)(param_5 + local_d0 * 8);
    param_2[1] = *(undefined4 *)(param_5 + 4 + local_d0 * 8);
    *param_2 = uVar1;
    uVar1 = *(undefined4 *)((int)local_d8 + 4 + param_6);
    uVar2 = *(undefined4 *)((int)local_d8 + 8 + param_6);
    uVar3 = *(undefined4 *)((int)local_d8 + 0xc + param_6);
    *param_3 = *(undefined4 *)((int)local_d8 + param_6);
    param_3[1] = uVar1;
    param_3[3] = uVar3;
    param_3[2] = uVar2;
  }
  local_e0 = (uint)bVar12;
  local_d4 = 0;
  if (3 < (int)param_7) {
    local_bc = (float *)(local_d0 * 8);
    pfVar23 = (float *)(param_3 + local_e0 * 4);
    pfVar17 = (float *)(param_1 + local_e0 * 4);
    pfVar18 = (float *)(param_6 + 0x1c);
    iVar20 = param_6 - param_4;
    local_dc = (float *)(param_5 + 0xc);
    pfVar21 = (float *)(param_4 + 0x18);
    local_d0 = 3;
    uVar14 = local_d0;
    do {
      local_d0 = uVar14;
      if (pfVar21[-6] < param_8) {
        if (bVar12) {
          fVar4 = pfVar21[-5];
          fVar5 = *(float *)((int)local_d8 + 4 + param_4);
          fVar6 = pfVar21[-4];
          fVar7 = *(float *)((int)local_d8 + 8 + param_4);
          *pfVar17 = pfVar21[-6] - *(float *)((int)local_d8 + param_4);
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar13 = (param_8 - *(float *)((int)local_d8 + param_4)) / *pfVar17;
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar4 = *(float *)((int)local_d8 + 4 + param_4);
          fVar5 = *(float *)((int)local_d8 + 8 + param_4);
          *pfVar17 = *(float *)((int)local_d8 + param_4) + *pfVar17;
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = local_dc[-2];
          fVar5 = *(float *)((int)local_bc + 4 + param_5);
          fVar6 = *(float *)((int)local_bc + 4 + param_5);
          param_2[local_e0 * 2] =
               (local_dc[-3] - *(float *)((int)local_bc + param_5)) * fVar13 +
               *(float *)((int)local_bc + param_5);
          param_2[local_e0 * 2 + 1] = fVar6 + (fVar4 - fVar5) * fVar13;
          fVar4 = pfVar18[-7];
          fVar5 = *(float *)((int)local_d8 + param_6);
          fVar6 = pfVar18[-6];
          pfVar17 = pfVar17 + 4;
          fVar7 = *(float *)((int)local_d8 + 4 + param_6);
          fVar8 = pfVar18[-4];
          fVar9 = *(float *)((int)local_d8 + 0xc + param_6);
          bVar12 = false;
          fVar15 = *(float *)((int)local_d8 + param_6);
          fVar10 = *(float *)((int)local_d8 + 4 + param_6);
          fVar11 = *(float *)((int)local_d8 + 0xc + param_6);
          pfVar23[2] = *(float *)((int)local_d8 + 8 + param_6) +
                       (pfVar18[-5] - *(float *)((int)local_d8 + 8 + param_6)) * fVar13;
          local_e0 = local_e0 + 1;
          *pfVar23 = (fVar4 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar11 + fVar13 * (fVar8 - fVar9);
          pfVar23[1] = fVar10 + (fVar6 - fVar7) * fVar13;
          pfVar23 = pfVar23 + 4;
        }
      }
      else {
        pfVar16 = pfVar17;
        pfVar22 = pfVar23;
        if (!bVar12) {
          fVar4 = pfVar21[-5];
          fVar5 = *(float *)((int)local_d8 + 4 + param_4);
          fVar6 = pfVar21[-4];
          fVar7 = *(float *)((int)local_d8 + 8 + param_4);
          *pfVar17 = pfVar21[-6] - *(float *)((int)local_d8 + param_4);
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar13 = (param_8 - *(float *)((int)local_d8 + param_4)) / *pfVar17;
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar4 = *(float *)((int)local_d8 + 4 + param_4);
          fVar5 = *(float *)((int)local_d8 + 8 + param_4);
          *pfVar17 = *pfVar17 + *(float *)((int)local_d8 + param_4);
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = local_dc[-2];
          fVar5 = *(float *)((int)local_bc + 4 + param_5);
          fVar6 = *(float *)((int)local_bc + 4 + param_5);
          param_2[local_e0 * 2] =
               (local_dc[-3] - *(float *)((int)local_bc + param_5)) * fVar13 +
               *(float *)((int)local_bc + param_5);
          param_2[local_e0 * 2 + 1] = fVar6 + (fVar4 - fVar5) * fVar13;
          fVar4 = pfVar18[-7];
          fVar5 = *(float *)((int)local_d8 + param_6);
          fVar6 = pfVar18[-6];
          fVar7 = *(float *)((int)local_d8 + 4 + param_6);
          fVar8 = pfVar18[-4];
          fVar9 = *(float *)((int)local_d8 + 0xc + param_6);
          bVar12 = true;
          fVar15 = *(float *)((int)local_d8 + param_6);
          fVar10 = *(float *)((int)local_d8 + 4 + param_6);
          fVar11 = *(float *)((int)local_d8 + 0xc + param_6);
          pfVar23[2] = *(float *)((int)local_d8 + 8 + param_6) +
                       (pfVar18[-5] - *(float *)((int)local_d8 + 8 + param_6)) * fVar13;
          local_e0 = local_e0 + 1;
          *pfVar23 = (fVar4 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar11 + fVar13 * (fVar8 - fVar9);
          pfVar23[1] = fVar10 + (fVar6 - fVar7) * fVar13;
          pfVar16 = pfVar17 + 4;
          pfVar22 = pfVar23 + 4;
        }
        fVar4 = pfVar21[-5];
        fVar5 = pfVar21[-4];
        *pfVar16 = pfVar21[-6];
        pfVar16[1] = fVar4;
        local_e0 = local_e0 + 1;
        pfVar17 = pfVar16 + 4;
        pfVar16[2] = fVar5;
        fVar4 = local_dc[-2];
        pfVar23 = pfVar22 + 4;
        param_2[local_e0 * 2 + -2] = local_dc[-3];
        param_2[local_e0 * 2 + -1] = fVar4;
        fVar4 = pfVar18[-6];
        fVar5 = pfVar18[-5];
        fVar6 = pfVar18[-7];
        pfVar22[3] = pfVar18[-4];
        *pfVar22 = fVar6;
        pfVar22[1] = fVar4;
        pfVar22[2] = fVar5;
      }
      if (pfVar21[-2] < param_8) {
        if (bVar12) {
          fVar4 = pfVar21[-1];
          fVar5 = pfVar21[-5];
          fVar6 = *pfVar21;
          fVar7 = pfVar21[-4];
          *pfVar17 = pfVar21[-2] - pfVar21[-6];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar10 = (param_8 - pfVar21[-6]) / *pfVar17;
          *pfVar17 = fVar10 * *pfVar17;
          pfVar17[1] = fVar10 * pfVar17[1];
          pfVar17[2] = fVar10 * pfVar17[2];
          fVar4 = pfVar21[-5];
          fVar5 = pfVar21[-4];
          *pfVar17 = pfVar21[-6] + *pfVar17;
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = *local_dc;
          fVar5 = local_dc[-2];
          fVar6 = local_dc[-2];
          param_2[local_e0 * 2] = (local_dc[-1] - local_dc[-3]) * fVar10 + local_dc[-3];
          param_2[local_e0 * 2 + 1] = (fVar4 - fVar5) * fVar10 + fVar6;
          fVar4 = pfVar18[-3];
          fVar5 = pfVar18[-7];
          fVar6 = pfVar18[-2];
          fVar7 = pfVar18[-6];
          bVar12 = false;
          fVar8 = pfVar18[-7];
          fVar9 = pfVar18[-6];
          fVar15 = fVar10 * (*pfVar18 - pfVar18[-4]) + pfVar18[-4];
          pfVar23[2] = (*(float *)(iVar20 + (int)pfVar21) - pfVar18[-5]) * fVar10 + pfVar18[-5];
          *pfVar23 = (fVar4 - fVar5) * fVar10 + fVar8;
          pfVar23[1] = (fVar6 - fVar7) * fVar10 + fVar9;
          goto LAB_005169c6;
        }
      }
      else {
        pfVar16 = pfVar23;
        if (!bVar12) {
          fVar4 = pfVar21[-1];
          fVar5 = pfVar21[-5];
          fVar6 = *pfVar21;
          fVar7 = pfVar21[-4];
          *pfVar17 = pfVar21[-2] - pfVar21[-6];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar13 = (param_8 - pfVar21[-6]) / *pfVar17;
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar4 = pfVar21[-5];
          fVar5 = pfVar21[-4];
          *pfVar17 = pfVar21[-6] + *pfVar17;
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = *local_dc;
          fVar5 = local_dc[-2];
          fVar6 = local_dc[-2];
          param_2[local_e0 * 2] = (local_dc[-1] - local_dc[-3]) * fVar13 + local_dc[-3];
          param_2[local_e0 * 2 + 1] = (fVar4 - fVar5) * fVar13 + fVar6;
          fVar4 = pfVar18[-3];
          fVar5 = pfVar18[-7];
          fVar6 = pfVar18[-2];
          fVar7 = pfVar18[-6];
          fVar8 = *pfVar18;
          fVar9 = pfVar18[-4];
          local_e0 = local_e0 + 1;
          pfVar17 = pfVar17 + 4;
          pfVar16 = pfVar23 + 4;
          bVar12 = true;
          fVar15 = pfVar18[-7];
          fVar10 = pfVar18[-6];
          fVar11 = pfVar18[-4];
          pfVar23[2] = (*(float *)(iVar20 + (int)pfVar21) - pfVar18[-5]) * fVar13 + pfVar18[-5];
          *pfVar23 = (fVar4 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar13 * (fVar8 - fVar9) + fVar11;
          pfVar23[1] = (fVar6 - fVar7) * fVar13 + fVar10;
        }
        fVar4 = pfVar21[-1];
        fVar5 = *pfVar21;
        *pfVar17 = pfVar21[-2];
        pfVar17[1] = fVar4;
        pfVar17[2] = fVar5;
        fVar4 = *local_dc;
        param_2[local_e0 * 2] = local_dc[-1];
        param_2[local_e0 * 2 + 1] = fVar4;
        fVar4 = pfVar18[-2];
        fVar5 = *(float *)(iVar20 + (int)pfVar21);
        fVar15 = *pfVar18;
        *pfVar16 = pfVar18[-3];
        pfVar16[1] = fVar4;
        pfVar16[2] = fVar5;
        pfVar23 = pfVar16;
LAB_005169c6:
        local_e0 = local_e0 + 1;
        pfVar23[3] = fVar15;
        pfVar17 = pfVar17 + 4;
        pfVar23 = pfVar23 + 4;
      }
      if (pfVar21[2] < param_8) {
        if (bVar12) {
          fVar4 = pfVar21[3];
          fVar5 = pfVar21[-1];
          fVar6 = pfVar21[4];
          fVar7 = *pfVar21;
          *pfVar17 = pfVar21[2] - pfVar21[-2];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar10 = (param_8 - pfVar21[-2]) / *pfVar17;
          *pfVar17 = fVar10 * *pfVar17;
          pfVar17[1] = fVar10 * pfVar17[1];
          pfVar17[2] = fVar10 * pfVar17[2];
          fVar4 = pfVar21[-1];
          fVar5 = *pfVar21;
          *pfVar17 = *pfVar17 + pfVar21[-2];
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = local_dc[2];
          fVar5 = *local_dc;
          fVar6 = *local_dc;
          param_2[local_e0 * 2] = (local_dc[1] - local_dc[-1]) * fVar10 + local_dc[-1];
          param_2[local_e0 * 2 + 1] = (fVar4 - fVar5) * fVar10 + fVar6;
          fVar4 = pfVar18[1];
          fVar5 = pfVar18[-3];
          fVar6 = pfVar18[2];
          fVar7 = pfVar18[-2];
          bVar12 = false;
          fVar8 = pfVar18[-3];
          fVar9 = pfVar18[-2];
          fVar15 = fVar10 * (pfVar18[4] - *pfVar18) + *pfVar18;
          pfVar23[2] = (pfVar18[3] - *(float *)(iVar20 + (int)pfVar21)) * fVar10 +
                       *(float *)(iVar20 + (int)pfVar21);
          *pfVar23 = (fVar4 - fVar5) * fVar10 + fVar8;
          pfVar23[1] = (fVar6 - fVar7) * fVar10 + fVar9;
          goto LAB_00516c7a;
        }
      }
      else {
        pfVar16 = pfVar23;
        if (!bVar12) {
          fVar4 = pfVar21[3];
          fVar5 = pfVar21[-1];
          fVar6 = pfVar21[4];
          fVar7 = *pfVar21;
          *pfVar17 = pfVar21[2] - pfVar21[-2];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar13 = (param_8 - pfVar21[-2]) / *pfVar17;
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar4 = pfVar21[-1];
          fVar5 = *pfVar21;
          *pfVar17 = *pfVar17 + pfVar21[-2];
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = local_dc[2];
          fVar5 = *local_dc;
          fVar6 = *local_dc;
          param_2[local_e0 * 2] = (local_dc[1] - local_dc[-1]) * fVar13 + local_dc[-1];
          param_2[local_e0 * 2 + 1] = (fVar4 - fVar5) * fVar13 + fVar6;
          fVar4 = pfVar18[1];
          fVar5 = pfVar18[-3];
          fVar6 = pfVar18[2];
          fVar7 = pfVar18[-2];
          fVar8 = pfVar18[4];
          fVar9 = *pfVar18;
          local_e0 = local_e0 + 1;
          pfVar17 = pfVar17 + 4;
          pfVar16 = pfVar23 + 4;
          bVar12 = true;
          fVar15 = pfVar18[-3];
          fVar10 = pfVar18[-2];
          fVar11 = *pfVar18;
          pfVar23[2] = (pfVar18[3] - *(float *)(iVar20 + (int)pfVar21)) * fVar13 +
                       *(float *)(iVar20 + (int)pfVar21);
          *pfVar23 = (fVar4 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar13 * (fVar8 - fVar9) + fVar11;
          pfVar23[1] = (fVar6 - fVar7) * fVar13 + fVar10;
        }
        fVar4 = pfVar21[3];
        fVar5 = pfVar21[4];
        *pfVar17 = pfVar21[2];
        pfVar17[1] = fVar4;
        pfVar17[2] = fVar5;
        fVar4 = local_dc[2];
        param_2[local_e0 * 2] = local_dc[1];
        param_2[local_e0 * 2 + 1] = fVar4;
        fVar15 = pfVar18[4];
        fVar4 = pfVar18[2];
        fVar5 = pfVar18[3];
        *pfVar16 = pfVar18[1];
        pfVar16[1] = fVar4;
        pfVar16[2] = fVar5;
        pfVar23 = pfVar16;
LAB_00516c7a:
        local_e0 = local_e0 + 1;
        pfVar23[3] = fVar15;
        pfVar17 = pfVar17 + 4;
        pfVar23 = pfVar23 + 4;
      }
      if (pfVar21[6] < param_8) {
        if (bVar12) {
          fVar4 = pfVar21[7];
          fVar5 = pfVar21[3];
          fVar6 = pfVar21[8];
          fVar7 = pfVar21[4];
          *pfVar17 = pfVar21[6] - pfVar21[2];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar10 = (param_8 - pfVar21[2]) / *pfVar17;
          *pfVar17 = fVar10 * *pfVar17;
          pfVar17[1] = fVar10 * pfVar17[1];
          pfVar17[2] = fVar10 * pfVar17[2];
          fVar4 = pfVar21[3];
          fVar5 = pfVar21[4];
          *pfVar17 = pfVar21[2] + *pfVar17;
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = local_dc[4];
          fVar5 = local_dc[2];
          fVar6 = local_dc[2];
          param_2[local_e0 * 2] = (local_dc[3] - local_dc[1]) * fVar10 + local_dc[1];
          param_2[local_e0 * 2 + 1] = (fVar4 - fVar5) * fVar10 + fVar6;
          fVar4 = pfVar18[5];
          fVar5 = pfVar18[1];
          fVar6 = pfVar18[6];
          fVar7 = pfVar18[2];
          bVar12 = false;
          fVar8 = pfVar18[1];
          fVar9 = pfVar18[2];
          fVar15 = fVar10 * (pfVar18[8] - pfVar18[4]) + pfVar18[4];
          pfVar23[2] = (pfVar18[7] - pfVar18[3]) * fVar10 + pfVar18[3];
          *pfVar23 = (fVar4 - fVar5) * fVar10 + fVar8;
          pfVar23[1] = (fVar6 - fVar7) * fVar10 + fVar9;
          goto LAB_00516f32;
        }
      }
      else {
        pfVar16 = pfVar23;
        if (!bVar12) {
          fVar4 = pfVar21[7];
          fVar5 = pfVar21[3];
          fVar6 = pfVar21[8];
          fVar7 = pfVar21[4];
          *pfVar17 = pfVar21[6] - pfVar21[2];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar13 = (param_8 - pfVar21[2]) / *pfVar17;
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar4 = pfVar21[3];
          fVar5 = pfVar21[4];
          *pfVar17 = pfVar21[2] + *pfVar17;
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = local_dc[4];
          fVar5 = local_dc[2];
          fVar6 = local_dc[2];
          param_2[local_e0 * 2] = (local_dc[3] - local_dc[1]) * fVar13 + local_dc[1];
          param_2[local_e0 * 2 + 1] = (fVar4 - fVar5) * fVar13 + fVar6;
          fVar4 = pfVar18[5];
          fVar5 = pfVar18[1];
          fVar6 = pfVar18[6];
          fVar7 = pfVar18[2];
          fVar8 = pfVar18[8];
          fVar9 = pfVar18[4];
          local_e0 = local_e0 + 1;
          pfVar17 = pfVar17 + 4;
          pfVar16 = pfVar23 + 4;
          bVar12 = true;
          fVar15 = pfVar18[1];
          fVar10 = pfVar18[2];
          fVar11 = pfVar18[4];
          pfVar23[2] = (pfVar18[7] - pfVar18[3]) * fVar13 + pfVar18[3];
          *pfVar23 = (fVar4 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar13 * (fVar8 - fVar9) + fVar11;
          pfVar23[1] = (fVar6 - fVar7) * fVar13 + fVar10;
        }
        fVar4 = pfVar21[7];
        fVar5 = pfVar21[8];
        *pfVar17 = pfVar21[6];
        pfVar17[1] = fVar4;
        pfVar17[2] = fVar5;
        fVar4 = local_dc[4];
        param_2[local_e0 * 2] = local_dc[3];
        param_2[local_e0 * 2 + 1] = fVar4;
        fVar15 = pfVar18[8];
        fVar4 = pfVar18[6];
        fVar5 = pfVar18[7];
        *pfVar16 = pfVar18[5];
        pfVar16[1] = fVar4;
        pfVar16[2] = fVar5;
        pfVar23 = pfVar16;
LAB_00516f32:
        local_e0 = local_e0 + 1;
        pfVar23[3] = fVar15;
        pfVar17 = pfVar17 + 4;
        pfVar23 = pfVar23 + 4;
      }
      local_bc = (float *)((0xc - param_5) + (int)local_dc);
      local_d8 = (float *)((0x18 - param_4) + (int)pfVar21);
      local_dc = local_dc + 8;
      local_d4 = local_d4 + 4;
      pfVar21 = pfVar21 + 0x10;
      pfVar18 = pfVar18 + 0x10;
      uVar14 = local_d0 + 4;
    } while (local_d0 + 4 < param_7);
  }
  if (local_d4 < param_7) {
    pfVar18 = (float *)(param_3 + local_e0 * 4);
    pfVar17 = (float *)(param_1 + local_e0 * 4);
    local_d8 = (float *)(local_d4 * 0x10 + 0xc + param_6);
    local_dc = (float *)(local_d4 * 0x10 + 8 + param_4);
    iVar20 = param_6 - param_4;
    iVar19 = local_d0 << 4;
    local_d0 = local_d0 << 3;
    local_bc = pfVar18;
    do {
      if (local_dc[-2] < param_8) {
        if (bVar12) {
          fVar4 = local_dc[-1];
          fVar5 = *(float *)(iVar19 + 4 + param_4);
          fVar6 = *(float *)(iVar19 + 8 + param_4);
          fVar7 = *local_dc;
          *pfVar17 = local_dc[-2] - *(float *)(iVar19 + param_4);
          pfVar17[2] = fVar7 - fVar6;
          pfVar17[1] = fVar4 - fVar5;
          fVar10 = (param_8 - *(float *)(iVar19 + param_4)) / *pfVar17;
          *pfVar17 = fVar10 * *pfVar17;
          pfVar17[1] = fVar10 * pfVar17[1];
          pfVar17[2] = fVar10 * pfVar17[2];
          fVar4 = *(float *)(iVar19 + 4 + param_4);
          fVar5 = *(float *)(iVar19 + 8 + param_4);
          *pfVar17 = *(float *)(iVar19 + param_4) + *pfVar17;
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = *(float *)(param_5 + 4 + local_d4 * 8);
          fVar5 = *(float *)(local_d0 + 4 + param_5);
          fVar6 = *(float *)(local_d0 + 4 + param_5);
          param_2[local_e0 * 2] =
               (*(float *)(param_5 + local_d4 * 8) - *(float *)(local_d0 + param_5)) * fVar10 +
               *(float *)(local_d0 + param_5);
          param_2[local_e0 * 2 + 1] = fVar6 + (fVar4 - fVar5) * fVar10;
          fVar4 = local_d8[-3];
          fVar5 = *(float *)(iVar19 + param_6);
          fVar6 = local_d8[-2];
          fVar7 = *(float *)(iVar19 + 4 + param_6);
          bVar12 = false;
          fVar8 = *(float *)(iVar19 + param_6);
          fVar9 = *(float *)(iVar19 + 4 + param_6);
          fVar15 = *(float *)(iVar19 + 0xc + param_6) +
                   fVar10 * (*local_d8 - *(float *)(iVar19 + 0xc + param_6));
          local_bc[2] = *(float *)(iVar19 + 8 + param_6) +
                        (*(float *)((int)local_dc + iVar20) - *(float *)(iVar19 + 8 + param_6)) *
                        fVar10;
          *local_bc = (fVar4 - fVar5) * fVar10 + fVar8;
          local_bc[1] = fVar9 + (fVar6 - fVar7) * fVar10;
          goto LAB_00517336;
        }
      }
      else {
        if (!bVar12) {
          fVar4 = local_dc[-1];
          fVar5 = *(float *)(iVar19 + 4 + param_4);
          fVar6 = *(float *)(iVar19 + 8 + param_4);
          fVar7 = *local_dc;
          *pfVar17 = local_dc[-2] - *(float *)(iVar19 + param_4);
          pfVar17[2] = fVar7 - fVar6;
          pfVar17[1] = fVar4 - fVar5;
          fVar13 = (param_8 - *(float *)(iVar19 + param_4)) / *pfVar17;
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar4 = *(float *)(iVar19 + 4 + param_4);
          fVar5 = *(float *)(iVar19 + 8 + param_4);
          *pfVar17 = *pfVar17 + *(float *)(iVar19 + param_4);
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = *(float *)(param_5 + 4 + local_d4 * 8);
          fVar5 = *(float *)(local_d0 + 4 + param_5);
          fVar6 = *(float *)(local_d0 + 4 + param_5);
          param_2[local_e0 * 2] =
               (*(float *)(param_5 + local_d4 * 8) - *(float *)(local_d0 + param_5)) * fVar13 +
               *(float *)(local_d0 + param_5);
          param_2[local_e0 * 2 + 1] = fVar6 + (fVar4 - fVar5) * fVar13;
          fVar4 = local_d8[-3];
          fVar5 = *(float *)(iVar19 + param_6);
          fVar6 = local_d8[-2];
          fVar7 = *(float *)(iVar19 + 4 + param_6);
          pfVar17 = pfVar17 + 4;
          fVar8 = *(float *)(iVar19 + 0xc + param_6);
          bVar12 = true;
          fVar9 = *local_d8;
          fVar15 = *(float *)(iVar19 + param_6);
          fVar10 = *(float *)(iVar19 + 4 + param_6);
          fVar11 = *(float *)(iVar19 + 0xc + param_6);
          local_bc[2] = *(float *)(iVar19 + 8 + param_6) +
                        (*(float *)((int)local_dc + iVar20) - *(float *)(iVar19 + 8 + param_6)) *
                        fVar13;
          *local_bc = (fVar4 - fVar5) * fVar13 + fVar15;
          local_bc[3] = fVar11 + fVar13 * (fVar9 - fVar8);
          local_bc[1] = fVar10 + (fVar6 - fVar7) * fVar13;
          local_e0 = local_e0 + 1;
          pfVar18 = local_bc + 4;
        }
        local_bc = pfVar18;
        fVar4 = local_dc[-1];
        fVar5 = *local_dc;
        *pfVar17 = local_dc[-2];
        pfVar17[1] = fVar4;
        pfVar17[2] = fVar5;
        uVar1 = *(undefined4 *)(param_5 + 4 + local_d4 * 8);
        param_2[local_e0 * 2] = *(undefined4 *)(param_5 + local_d4 * 8);
        param_2[local_e0 * 2 + 1] = uVar1;
        fVar4 = local_d8[-2];
        fVar5 = *(float *)((int)local_dc + iVar20);
        fVar15 = *local_d8;
        *local_bc = local_d8[-3];
        local_bc[1] = fVar4;
        local_bc[2] = fVar5;
LAB_00517336:
        local_bc[3] = fVar15;
        pfVar17 = pfVar17 + 4;
        local_e0 = local_e0 + 1;
        pfVar18 = local_bc + 4;
        local_bc = pfVar18;
      }
      local_d0 = local_d4 * 8;
      iVar19 = (-8 - param_4) + (int)local_dc;
      local_d4 = local_d4 + 1;
      local_dc = local_dc + 4;
      local_d8 = local_d8 + 4;
    } while (local_d4 < param_7);
  }
  return local_e0;
}


// ==== 0x517390 FUN_00517390

uint FUN_00517390(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,int param_4,
                 int param_5,int param_6,uint param_7,float param_8)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  bool bVar12;
  float fVar13;
  uint uVar14;
  float fVar15;
  float *pfVar16;
  float *pfVar17;
  float *pfVar18;
  int iVar19;
  int iVar20;
  float *pfVar21;
  float *pfVar22;
  float *pfVar23;
  uint local_e0;
  float *local_dc;
  float *local_d8;
  uint local_d4;
  uint local_d0;
  float *local_bc;
  
  local_d0 = param_7 - 1;
  local_d8 = (float *)(local_d0 * 0x10);
  bVar12 = param_8 <= *(float *)((int)local_d8 + 4 + param_4);
  if (bVar12) {
    uVar1 = *(undefined4 *)((int)local_d8 + 4 + param_4);
    uVar2 = *(undefined4 *)((int)local_d8 + 8 + param_4);
    *param_1 = *(undefined4 *)((int)local_d8 + param_4);
    param_1[1] = uVar1;
    param_1[2] = uVar2;
    uVar1 = *(undefined4 *)(param_5 + local_d0 * 8);
    param_2[1] = *(undefined4 *)(param_5 + 4 + local_d0 * 8);
    *param_2 = uVar1;
    uVar1 = *(undefined4 *)((int)local_d8 + 4 + param_6);
    uVar2 = *(undefined4 *)((int)local_d8 + 8 + param_6);
    uVar3 = *(undefined4 *)((int)local_d8 + 0xc + param_6);
    *param_3 = *(undefined4 *)((int)local_d8 + param_6);
    param_3[1] = uVar1;
    param_3[3] = uVar3;
    param_3[2] = uVar2;
  }
  local_e0 = (uint)bVar12;
  local_d4 = 0;
  if (3 < (int)param_7) {
    local_bc = (float *)(local_d0 * 8);
    pfVar23 = (float *)(param_3 + local_e0 * 4);
    pfVar17 = (float *)(param_1 + local_e0 * 4);
    pfVar18 = (float *)(param_6 + 0x1c);
    iVar20 = param_6 - param_4;
    local_dc = (float *)(param_5 + 0xc);
    pfVar21 = (float *)(param_4 + 0x18);
    local_d0 = 3;
    uVar14 = local_d0;
    do {
      local_d0 = uVar14;
      if (pfVar21[-5] < param_8) {
        if (bVar12) {
          fVar4 = *(float *)((int)local_d8 + 4 + param_4);
          fVar5 = pfVar21[-5];
          fVar6 = pfVar21[-4];
          fVar7 = *(float *)((int)local_d8 + 8 + param_4);
          *pfVar17 = pfVar21[-6] - *(float *)((int)local_d8 + param_4);
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar5 - fVar4;
          fVar13 = (param_8 - *(float *)((int)local_d8 + 4 + param_4)) / pfVar17[1];
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar4 = *(float *)((int)local_d8 + 4 + param_4);
          fVar5 = *(float *)((int)local_d8 + 8 + param_4);
          *pfVar17 = *(float *)((int)local_d8 + param_4) + *pfVar17;
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = local_dc[-2];
          fVar5 = *(float *)((int)local_bc + 4 + param_5);
          fVar6 = *(float *)((int)local_bc + 4 + param_5);
          param_2[local_e0 * 2] =
               (local_dc[-3] - *(float *)((int)local_bc + param_5)) * fVar13 +
               *(float *)((int)local_bc + param_5);
          param_2[local_e0 * 2 + 1] = fVar6 + (fVar4 - fVar5) * fVar13;
          fVar4 = pfVar18[-7];
          fVar5 = *(float *)((int)local_d8 + param_6);
          fVar6 = pfVar18[-6];
          pfVar17 = pfVar17 + 4;
          fVar7 = *(float *)((int)local_d8 + 4 + param_6);
          fVar8 = pfVar18[-4];
          fVar9 = *(float *)((int)local_d8 + 0xc + param_6);
          bVar12 = false;
          fVar15 = *(float *)((int)local_d8 + param_6);
          fVar10 = *(float *)((int)local_d8 + 4 + param_6);
          fVar11 = *(float *)((int)local_d8 + 0xc + param_6);
          pfVar23[2] = *(float *)((int)local_d8 + 8 + param_6) +
                       (pfVar18[-5] - *(float *)((int)local_d8 + 8 + param_6)) * fVar13;
          local_e0 = local_e0 + 1;
          *pfVar23 = (fVar4 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar11 + fVar13 * (fVar8 - fVar9);
          pfVar23[1] = fVar10 + (fVar6 - fVar7) * fVar13;
          pfVar23 = pfVar23 + 4;
        }
      }
      else {
        pfVar16 = pfVar17;
        pfVar22 = pfVar23;
        if (!bVar12) {
          fVar4 = *(float *)((int)local_d8 + 4 + param_4);
          fVar5 = pfVar21[-5];
          fVar6 = pfVar21[-4];
          fVar7 = *(float *)((int)local_d8 + 8 + param_4);
          *pfVar17 = pfVar21[-6] - *(float *)((int)local_d8 + param_4);
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar5 - fVar4;
          fVar13 = (param_8 - *(float *)((int)local_d8 + 4 + param_4)) / pfVar17[1];
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar4 = *(float *)((int)local_d8 + 4 + param_4);
          fVar5 = *(float *)((int)local_d8 + 8 + param_4);
          *pfVar17 = *pfVar17 + *(float *)((int)local_d8 + param_4);
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = local_dc[-2];
          fVar5 = *(float *)((int)local_bc + 4 + param_5);
          fVar6 = *(float *)((int)local_bc + 4 + param_5);
          param_2[local_e0 * 2] =
               (local_dc[-3] - *(float *)((int)local_bc + param_5)) * fVar13 +
               *(float *)((int)local_bc + param_5);
          param_2[local_e0 * 2 + 1] = fVar6 + (fVar4 - fVar5) * fVar13;
          fVar4 = pfVar18[-7];
          fVar5 = *(float *)((int)local_d8 + param_6);
          fVar6 = pfVar18[-6];
          fVar7 = *(float *)((int)local_d8 + 4 + param_6);
          fVar8 = pfVar18[-4];
          fVar9 = *(float *)((int)local_d8 + 0xc + param_6);
          bVar12 = true;
          fVar15 = *(float *)((int)local_d8 + param_6);
          fVar10 = *(float *)((int)local_d8 + 4 + param_6);
          fVar11 = *(float *)((int)local_d8 + 0xc + param_6);
          pfVar23[2] = *(float *)((int)local_d8 + 8 + param_6) +
                       (pfVar18[-5] - *(float *)((int)local_d8 + 8 + param_6)) * fVar13;
          local_e0 = local_e0 + 1;
          *pfVar23 = (fVar4 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar11 + fVar13 * (fVar8 - fVar9);
          pfVar23[1] = fVar10 + (fVar6 - fVar7) * fVar13;
          pfVar16 = pfVar17 + 4;
          pfVar22 = pfVar23 + 4;
        }
        fVar4 = pfVar21[-5];
        fVar5 = pfVar21[-4];
        local_e0 = local_e0 + 1;
        pfVar17 = pfVar16 + 4;
        *pfVar16 = pfVar21[-6];
        pfVar16[1] = fVar4;
        pfVar23 = pfVar22 + 4;
        pfVar16[2] = fVar5;
        fVar4 = local_dc[-2];
        param_2[local_e0 * 2 + -2] = local_dc[-3];
        param_2[local_e0 * 2 + -1] = fVar4;
        fVar4 = pfVar18[-6];
        fVar5 = pfVar18[-5];
        fVar6 = pfVar18[-7];
        pfVar22[3] = pfVar18[-4];
        *pfVar22 = fVar6;
        pfVar22[1] = fVar4;
        pfVar22[2] = fVar5;
      }
      if (pfVar21[-1] < param_8) {
        if (bVar12) {
          fVar4 = pfVar21[-1];
          fVar5 = pfVar21[-5];
          fVar6 = *pfVar21;
          fVar7 = pfVar21[-4];
          *pfVar17 = pfVar21[-2] - pfVar21[-6];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar10 = (param_8 - pfVar21[-5]) / pfVar17[1];
          *pfVar17 = fVar10 * *pfVar17;
          pfVar17[1] = fVar10 * pfVar17[1];
          pfVar17[2] = fVar10 * pfVar17[2];
          fVar4 = pfVar21[-5];
          fVar5 = pfVar21[-4];
          *pfVar17 = *pfVar17 + pfVar21[-6];
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = *local_dc;
          fVar5 = local_dc[-2];
          fVar6 = local_dc[-2];
          param_2[local_e0 * 2] = (local_dc[-1] - local_dc[-3]) * fVar10 + local_dc[-3];
          param_2[local_e0 * 2 + 1] = (fVar4 - fVar5) * fVar10 + fVar6;
          fVar4 = pfVar18[-3];
          fVar5 = pfVar18[-7];
          fVar6 = pfVar18[-2];
          fVar7 = pfVar18[-6];
          bVar12 = false;
          fVar8 = pfVar18[-7];
          fVar9 = pfVar18[-6];
          fVar15 = fVar10 * (*pfVar18 - pfVar18[-4]) + pfVar18[-4];
          pfVar23[2] = (*(float *)(iVar20 + (int)pfVar21) - pfVar18[-5]) * fVar10 + pfVar18[-5];
          *pfVar23 = (fVar4 - fVar5) * fVar10 + fVar8;
          pfVar23[1] = (fVar6 - fVar7) * fVar10 + fVar9;
          goto LAB_00517a8e;
        }
      }
      else {
        pfVar16 = pfVar23;
        if (!bVar12) {
          fVar4 = pfVar21[-1];
          fVar5 = pfVar21[-5];
          fVar6 = *pfVar21;
          fVar7 = pfVar21[-4];
          *pfVar17 = pfVar21[-2] - pfVar21[-6];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar13 = (param_8 - pfVar21[-5]) / pfVar17[1];
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar4 = pfVar21[-5];
          fVar5 = pfVar21[-4];
          *pfVar17 = *pfVar17 + pfVar21[-6];
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = *local_dc;
          fVar5 = local_dc[-2];
          fVar6 = local_dc[-2];
          param_2[local_e0 * 2] = (local_dc[-1] - local_dc[-3]) * fVar13 + local_dc[-3];
          param_2[local_e0 * 2 + 1] = (fVar4 - fVar5) * fVar13 + fVar6;
          fVar4 = pfVar18[-3];
          fVar5 = pfVar18[-7];
          fVar6 = pfVar18[-2];
          fVar7 = pfVar18[-6];
          fVar8 = *pfVar18;
          fVar9 = pfVar18[-4];
          local_e0 = local_e0 + 1;
          pfVar17 = pfVar17 + 4;
          pfVar16 = pfVar23 + 4;
          bVar12 = true;
          fVar15 = pfVar18[-7];
          fVar10 = pfVar18[-6];
          fVar11 = pfVar18[-4];
          pfVar23[2] = (*(float *)(iVar20 + (int)pfVar21) - pfVar18[-5]) * fVar13 + pfVar18[-5];
          *pfVar23 = (fVar4 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar13 * (fVar8 - fVar9) + fVar11;
          pfVar23[1] = (fVar6 - fVar7) * fVar13 + fVar10;
        }
        fVar4 = pfVar21[-1];
        fVar5 = *pfVar21;
        *pfVar17 = pfVar21[-2];
        pfVar17[1] = fVar4;
        pfVar17[2] = fVar5;
        fVar4 = *local_dc;
        param_2[local_e0 * 2] = local_dc[-1];
        param_2[local_e0 * 2 + 1] = fVar4;
        fVar4 = pfVar18[-2];
        fVar5 = *(float *)(iVar20 + (int)pfVar21);
        fVar15 = *pfVar18;
        *pfVar16 = pfVar18[-3];
        pfVar16[1] = fVar4;
        pfVar16[2] = fVar5;
        pfVar23 = pfVar16;
LAB_00517a8e:
        local_e0 = local_e0 + 1;
        pfVar23[3] = fVar15;
        pfVar17 = pfVar17 + 4;
        pfVar23 = pfVar23 + 4;
      }
      if (pfVar21[3] < param_8) {
        if (bVar12) {
          fVar4 = pfVar21[3];
          fVar5 = pfVar21[-1];
          fVar6 = pfVar21[4];
          fVar7 = *pfVar21;
          *pfVar17 = pfVar21[2] - pfVar21[-2];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar10 = (param_8 - pfVar21[-1]) / pfVar17[1];
          *pfVar17 = fVar10 * *pfVar17;
          pfVar17[1] = fVar10 * pfVar17[1];
          pfVar17[2] = fVar10 * pfVar17[2];
          fVar4 = pfVar21[-1];
          fVar5 = *pfVar21;
          *pfVar17 = *pfVar17 + pfVar21[-2];
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = local_dc[2];
          fVar5 = *local_dc;
          fVar6 = *local_dc;
          param_2[local_e0 * 2] = (local_dc[1] - local_dc[-1]) * fVar10 + local_dc[-1];
          param_2[local_e0 * 2 + 1] = (fVar4 - fVar5) * fVar10 + fVar6;
          fVar4 = pfVar18[1];
          fVar5 = pfVar18[-3];
          fVar6 = pfVar18[2];
          fVar7 = pfVar18[-2];
          bVar12 = false;
          fVar8 = pfVar18[-3];
          fVar9 = pfVar18[-2];
          fVar15 = fVar10 * (pfVar18[4] - *pfVar18) + *pfVar18;
          pfVar23[2] = (pfVar18[3] - *(float *)(iVar20 + (int)pfVar21)) * fVar10 +
                       *(float *)(iVar20 + (int)pfVar21);
          *pfVar23 = (fVar4 - fVar5) * fVar10 + fVar8;
          pfVar23[1] = (fVar6 - fVar7) * fVar10 + fVar9;
          goto LAB_00517d44;
        }
      }
      else {
        pfVar16 = pfVar23;
        if (!bVar12) {
          fVar4 = pfVar21[3];
          fVar5 = pfVar21[-1];
          fVar6 = pfVar21[4];
          fVar7 = *pfVar21;
          *pfVar17 = pfVar21[2] - pfVar21[-2];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar13 = (param_8 - pfVar21[-1]) / pfVar17[1];
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar4 = pfVar21[-1];
          fVar5 = *pfVar21;
          *pfVar17 = *pfVar17 + pfVar21[-2];
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = local_dc[2];
          fVar5 = *local_dc;
          fVar6 = *local_dc;
          param_2[local_e0 * 2] = (local_dc[1] - local_dc[-1]) * fVar13 + local_dc[-1];
          param_2[local_e0 * 2 + 1] = (fVar4 - fVar5) * fVar13 + fVar6;
          fVar4 = pfVar18[1];
          fVar5 = pfVar18[-3];
          fVar6 = pfVar18[2];
          fVar7 = pfVar18[-2];
          fVar8 = pfVar18[4];
          fVar9 = *pfVar18;
          local_e0 = local_e0 + 1;
          pfVar17 = pfVar17 + 4;
          pfVar16 = pfVar23 + 4;
          bVar12 = true;
          fVar15 = pfVar18[-3];
          fVar10 = pfVar18[-2];
          fVar11 = *pfVar18;
          pfVar23[2] = (pfVar18[3] - *(float *)(iVar20 + (int)pfVar21)) * fVar13 +
                       *(float *)(iVar20 + (int)pfVar21);
          *pfVar23 = (fVar4 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar13 * (fVar8 - fVar9) + fVar11;
          pfVar23[1] = (fVar6 - fVar7) * fVar13 + fVar10;
        }
        fVar4 = pfVar21[3];
        fVar5 = pfVar21[4];
        *pfVar17 = pfVar21[2];
        pfVar17[1] = fVar4;
        pfVar17[2] = fVar5;
        fVar4 = local_dc[2];
        param_2[local_e0 * 2] = local_dc[1];
        param_2[local_e0 * 2 + 1] = fVar4;
        fVar15 = pfVar18[4];
        fVar4 = pfVar18[2];
        fVar5 = pfVar18[3];
        *pfVar16 = pfVar18[1];
        pfVar16[1] = fVar4;
        pfVar16[2] = fVar5;
        pfVar23 = pfVar16;
LAB_00517d44:
        local_e0 = local_e0 + 1;
        pfVar23[3] = fVar15;
        pfVar17 = pfVar17 + 4;
        pfVar23 = pfVar23 + 4;
      }
      if (pfVar21[7] < param_8) {
        if (bVar12) {
          fVar4 = pfVar21[7];
          fVar5 = pfVar21[3];
          fVar6 = pfVar21[8];
          fVar7 = pfVar21[4];
          *pfVar17 = pfVar21[6] - pfVar21[2];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar10 = (param_8 - pfVar21[3]) / pfVar17[1];
          *pfVar17 = fVar10 * *pfVar17;
          pfVar17[1] = fVar10 * pfVar17[1];
          pfVar17[2] = fVar10 * pfVar17[2];
          fVar4 = pfVar21[3];
          fVar5 = pfVar21[4];
          *pfVar17 = *pfVar17 + pfVar21[2];
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = local_dc[4];
          fVar5 = local_dc[2];
          fVar6 = local_dc[2];
          param_2[local_e0 * 2] = (local_dc[3] - local_dc[1]) * fVar10 + local_dc[1];
          param_2[local_e0 * 2 + 1] = (fVar4 - fVar5) * fVar10 + fVar6;
          fVar4 = pfVar18[5];
          fVar5 = pfVar18[1];
          fVar6 = pfVar18[6];
          fVar7 = pfVar18[2];
          bVar12 = false;
          fVar8 = pfVar18[1];
          fVar9 = pfVar18[2];
          fVar15 = fVar10 * (pfVar18[8] - pfVar18[4]) + pfVar18[4];
          pfVar23[2] = (pfVar18[7] - pfVar18[3]) * fVar10 + pfVar18[3];
          *pfVar23 = (fVar4 - fVar5) * fVar10 + fVar8;
          pfVar23[1] = (fVar6 - fVar7) * fVar10 + fVar9;
          goto LAB_00517ffe;
        }
      }
      else {
        pfVar16 = pfVar23;
        if (!bVar12) {
          fVar4 = pfVar21[7];
          fVar5 = pfVar21[3];
          fVar6 = pfVar21[8];
          fVar7 = pfVar21[4];
          *pfVar17 = pfVar21[6] - pfVar21[2];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar13 = (param_8 - pfVar21[3]) / pfVar17[1];
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar4 = pfVar21[3];
          fVar5 = pfVar21[4];
          *pfVar17 = *pfVar17 + pfVar21[2];
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = local_dc[4];
          fVar5 = local_dc[2];
          fVar6 = local_dc[2];
          param_2[local_e0 * 2] = (local_dc[3] - local_dc[1]) * fVar13 + local_dc[1];
          param_2[local_e0 * 2 + 1] = (fVar4 - fVar5) * fVar13 + fVar6;
          fVar4 = pfVar18[5];
          fVar5 = pfVar18[1];
          fVar6 = pfVar18[6];
          fVar7 = pfVar18[2];
          fVar8 = pfVar18[8];
          fVar9 = pfVar18[4];
          local_e0 = local_e0 + 1;
          pfVar17 = pfVar17 + 4;
          pfVar16 = pfVar23 + 4;
          bVar12 = true;
          fVar15 = pfVar18[1];
          fVar10 = pfVar18[2];
          fVar11 = pfVar18[4];
          pfVar23[2] = (pfVar18[7] - pfVar18[3]) * fVar13 + pfVar18[3];
          *pfVar23 = (fVar4 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar13 * (fVar8 - fVar9) + fVar11;
          pfVar23[1] = (fVar6 - fVar7) * fVar13 + fVar10;
        }
        fVar4 = pfVar21[7];
        fVar5 = pfVar21[8];
        *pfVar17 = pfVar21[6];
        pfVar17[1] = fVar4;
        pfVar17[2] = fVar5;
        fVar4 = local_dc[4];
        param_2[local_e0 * 2] = local_dc[3];
        param_2[local_e0 * 2 + 1] = fVar4;
        fVar15 = pfVar18[8];
        fVar4 = pfVar18[6];
        fVar5 = pfVar18[7];
        *pfVar16 = pfVar18[5];
        pfVar16[1] = fVar4;
        pfVar16[2] = fVar5;
        pfVar23 = pfVar16;
LAB_00517ffe:
        local_e0 = local_e0 + 1;
        pfVar23[3] = fVar15;
        pfVar17 = pfVar17 + 4;
        pfVar23 = pfVar23 + 4;
      }
      local_bc = (float *)((0xc - param_5) + (int)local_dc);
      local_d8 = (float *)((0x18 - param_4) + (int)pfVar21);
      local_dc = local_dc + 8;
      local_d4 = local_d4 + 4;
      pfVar18 = pfVar18 + 0x10;
      pfVar21 = pfVar21 + 0x10;
      uVar14 = local_d0 + 4;
    } while (local_d0 + 4 < param_7);
  }
  if (local_d4 < param_7) {
    pfVar18 = (float *)(param_3 + local_e0 * 4);
    pfVar17 = (float *)(param_1 + local_e0 * 4);
    local_d8 = (float *)(local_d4 * 0x10 + 0xc + param_6);
    local_dc = (float *)(local_d4 * 0x10 + 4 + param_4);
    iVar20 = param_6 - param_4;
    iVar19 = local_d0 << 4;
    local_d0 = local_d0 << 3;
    local_bc = pfVar18;
    do {
      if (*local_dc < param_8) {
        if (bVar12) {
          fVar4 = *(float *)(iVar19 + 4 + param_4);
          fVar5 = *local_dc;
          fVar6 = local_dc[1];
          fVar7 = *(float *)(iVar19 + 8 + param_4);
          *pfVar17 = local_dc[-1] - *(float *)(iVar19 + param_4);
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar5 - fVar4;
          fVar10 = (param_8 - *(float *)(iVar19 + 4 + param_4)) / pfVar17[1];
          *pfVar17 = fVar10 * *pfVar17;
          pfVar17[1] = fVar10 * pfVar17[1];
          pfVar17[2] = fVar10 * pfVar17[2];
          fVar4 = *(float *)(iVar19 + 4 + param_4);
          fVar5 = *(float *)(iVar19 + 8 + param_4);
          *pfVar17 = *(float *)(iVar19 + param_4) + *pfVar17;
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = *(float *)(param_5 + 4 + local_d4 * 8);
          fVar5 = *(float *)(local_d0 + 4 + param_5);
          fVar6 = *(float *)(local_d0 + 4 + param_5);
          param_2[local_e0 * 2] =
               (*(float *)(param_5 + local_d4 * 8) - *(float *)(local_d0 + param_5)) * fVar10 +
               *(float *)(local_d0 + param_5);
          param_2[local_e0 * 2 + 1] = fVar6 + (fVar4 - fVar5) * fVar10;
          fVar4 = local_d8[-3];
          fVar5 = *(float *)(iVar19 + param_6);
          fVar6 = *(float *)((int)local_dc + iVar20);
          fVar7 = *(float *)(iVar19 + 4 + param_6);
          bVar12 = false;
          fVar8 = *(float *)(iVar19 + param_6);
          fVar9 = *(float *)(iVar19 + 4 + param_6);
          fVar15 = *(float *)(iVar19 + 0xc + param_6) +
                   fVar10 * (*local_d8 - *(float *)(iVar19 + 0xc + param_6));
          local_bc[2] = *(float *)(iVar19 + 8 + param_6) +
                        (local_d8[-1] - *(float *)(iVar19 + 8 + param_6)) * fVar10;
          *local_bc = (fVar4 - fVar5) * fVar10 + fVar8;
          local_bc[1] = fVar9 + (fVar6 - fVar7) * fVar10;
          goto LAB_00518403;
        }
      }
      else {
        if (!bVar12) {
          fVar4 = *(float *)(iVar19 + 4 + param_4);
          fVar5 = *local_dc;
          fVar6 = local_dc[1];
          fVar7 = *(float *)(iVar19 + 8 + param_4);
          *pfVar17 = local_dc[-1] - *(float *)(iVar19 + param_4);
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar5 - fVar4;
          fVar13 = (param_8 - *(float *)(iVar19 + 4 + param_4)) / pfVar17[1];
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar4 = *(float *)(iVar19 + 4 + param_4);
          fVar5 = *(float *)(iVar19 + 8 + param_4);
          *pfVar17 = *pfVar17 + *(float *)(iVar19 + param_4);
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = *(float *)(param_5 + 4 + local_d4 * 8);
          fVar5 = *(float *)(local_d0 + 4 + param_5);
          fVar6 = *(float *)(local_d0 + 4 + param_5);
          param_2[local_e0 * 2] =
               (*(float *)(param_5 + local_d4 * 8) - *(float *)(local_d0 + param_5)) * fVar13 +
               *(float *)(local_d0 + param_5);
          param_2[local_e0 * 2 + 1] = fVar6 + (fVar4 - fVar5) * fVar13;
          fVar4 = local_d8[-3];
          fVar5 = *(float *)(iVar19 + param_6);
          fVar6 = *(float *)((int)local_dc + iVar20);
          fVar7 = *(float *)(iVar19 + 4 + param_6);
          pfVar17 = pfVar17 + 4;
          fVar8 = *(float *)(iVar19 + 0xc + param_6);
          fVar9 = *local_d8;
          bVar12 = true;
          fVar15 = *(float *)(iVar19 + param_6);
          fVar10 = *(float *)(iVar19 + 4 + param_6);
          fVar11 = *(float *)(iVar19 + 0xc + param_6);
          local_bc[2] = *(float *)(iVar19 + 8 + param_6) +
                        (local_d8[-1] - *(float *)(iVar19 + 8 + param_6)) * fVar13;
          *local_bc = (fVar4 - fVar5) * fVar13 + fVar15;
          local_bc[3] = fVar11 + fVar13 * (fVar9 - fVar8);
          local_bc[1] = fVar10 + (fVar6 - fVar7) * fVar13;
          local_e0 = local_e0 + 1;
          pfVar18 = local_bc + 4;
        }
        local_bc = pfVar18;
        fVar4 = *local_dc;
        fVar5 = local_dc[1];
        *pfVar17 = local_dc[-1];
        pfVar17[1] = fVar4;
        pfVar17[2] = fVar5;
        uVar1 = *(undefined4 *)(param_5 + 4 + local_d4 * 8);
        param_2[local_e0 * 2] = *(undefined4 *)(param_5 + local_d4 * 8);
        param_2[local_e0 * 2 + 1] = uVar1;
        fVar4 = *(float *)((int)local_dc + iVar20);
        fVar5 = local_d8[-1];
        fVar15 = *local_d8;
        *local_bc = local_d8[-3];
        local_bc[1] = fVar4;
        local_bc[2] = fVar5;
LAB_00518403:
        local_bc[3] = fVar15;
        pfVar17 = pfVar17 + 4;
        local_e0 = local_e0 + 1;
        pfVar18 = local_bc + 4;
        local_bc = pfVar18;
      }
      local_d0 = local_d4 * 8;
      iVar19 = (-4 - param_4) + (int)local_dc;
      local_d4 = local_d4 + 1;
      local_dc = local_dc + 4;
      local_d8 = local_d8 + 4;
    } while (local_d4 < param_7);
  }
  return local_e0;
}


// ==== 0x518460 FUN_00518460

uint FUN_00518460(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,int param_4,
                 int param_5,int param_6,uint param_7,float param_8)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  bool bVar12;
  float fVar13;
  uint uVar14;
  float fVar15;
  float *pfVar16;
  float *pfVar17;
  float *pfVar18;
  int iVar19;
  int iVar20;
  float *pfVar21;
  float *pfVar22;
  float *pfVar23;
  uint local_e0;
  float *local_dc;
  float *local_d8;
  uint local_d4;
  uint local_d0;
  float *local_bc;
  
  local_d0 = param_7 - 1;
  local_d8 = (float *)(local_d0 * 0x10);
  bVar12 = *(float *)((int)local_d8 + param_4) < param_8 !=
           (*(float *)((int)local_d8 + param_4) == param_8);
  if (bVar12) {
    uVar1 = *(undefined4 *)((int)local_d8 + 4 + param_4);
    uVar2 = *(undefined4 *)((int)local_d8 + 8 + param_4);
    *param_1 = *(undefined4 *)((int)local_d8 + param_4);
    param_1[1] = uVar1;
    param_1[2] = uVar2;
    uVar1 = *(undefined4 *)(param_5 + local_d0 * 8);
    param_2[1] = *(undefined4 *)(param_5 + 4 + local_d0 * 8);
    *param_2 = uVar1;
    uVar1 = *(undefined4 *)((int)local_d8 + 4 + param_6);
    uVar2 = *(undefined4 *)((int)local_d8 + 8 + param_6);
    uVar3 = *(undefined4 *)((int)local_d8 + 0xc + param_6);
    *param_3 = *(undefined4 *)((int)local_d8 + param_6);
    param_3[1] = uVar1;
    param_3[3] = uVar3;
    param_3[2] = uVar2;
  }
  local_e0 = (uint)bVar12;
  local_d4 = 0;
  if (3 < (int)param_7) {
    local_bc = (float *)(local_d0 * 8);
    pfVar23 = (float *)(param_3 + local_e0 * 4);
    pfVar17 = (float *)(param_1 + local_e0 * 4);
    pfVar18 = (float *)(param_6 + 0x1c);
    iVar20 = param_6 - param_4;
    local_dc = (float *)(param_5 + 0xc);
    pfVar21 = (float *)(param_4 + 0x18);
    local_d0 = 3;
    uVar14 = local_d0;
    do {
      local_d0 = uVar14;
      if (pfVar21[-6] < param_8 == (pfVar21[-6] == param_8)) {
        if (bVar12) {
          fVar4 = pfVar21[-5];
          fVar5 = *(float *)((int)local_d8 + 4 + param_4);
          fVar6 = pfVar21[-4];
          fVar7 = *(float *)((int)local_d8 + 8 + param_4);
          *pfVar17 = pfVar21[-6] - *(float *)((int)local_d8 + param_4);
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar13 = (param_8 - *(float *)((int)local_d8 + param_4)) / *pfVar17;
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar4 = *(float *)((int)local_d8 + 4 + param_4);
          fVar5 = *(float *)((int)local_d8 + 8 + param_4);
          *pfVar17 = *(float *)((int)local_d8 + param_4) + *pfVar17;
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = local_dc[-2];
          fVar5 = *(float *)((int)local_bc + 4 + param_5);
          fVar6 = *(float *)((int)local_bc + 4 + param_5);
          param_2[local_e0 * 2] =
               (local_dc[-3] - *(float *)((int)local_bc + param_5)) * fVar13 +
               *(float *)((int)local_bc + param_5);
          param_2[local_e0 * 2 + 1] = fVar6 + (fVar4 - fVar5) * fVar13;
          fVar4 = pfVar18[-7];
          fVar5 = *(float *)((int)local_d8 + param_6);
          fVar6 = pfVar18[-6];
          pfVar17 = pfVar17 + 4;
          fVar7 = *(float *)((int)local_d8 + 4 + param_6);
          fVar8 = pfVar18[-4];
          fVar9 = *(float *)((int)local_d8 + 0xc + param_6);
          bVar12 = false;
          fVar15 = *(float *)((int)local_d8 + param_6);
          fVar10 = *(float *)((int)local_d8 + 4 + param_6);
          fVar11 = *(float *)((int)local_d8 + 0xc + param_6);
          pfVar23[2] = *(float *)((int)local_d8 + 8 + param_6) +
                       (pfVar18[-5] - *(float *)((int)local_d8 + 8 + param_6)) * fVar13;
          local_e0 = local_e0 + 1;
          *pfVar23 = (fVar4 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar11 + fVar13 * (fVar8 - fVar9);
          pfVar23[1] = fVar10 + (fVar6 - fVar7) * fVar13;
          pfVar23 = pfVar23 + 4;
        }
      }
      else {
        pfVar16 = pfVar17;
        pfVar22 = pfVar23;
        if (!bVar12) {
          fVar4 = pfVar21[-5];
          fVar5 = *(float *)((int)local_d8 + 4 + param_4);
          fVar6 = pfVar21[-4];
          fVar7 = *(float *)((int)local_d8 + 8 + param_4);
          *pfVar17 = pfVar21[-6] - *(float *)((int)local_d8 + param_4);
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar13 = (param_8 - *(float *)((int)local_d8 + param_4)) / *pfVar17;
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar4 = *(float *)((int)local_d8 + 4 + param_4);
          fVar5 = *(float *)((int)local_d8 + 8 + param_4);
          *pfVar17 = *pfVar17 + *(float *)((int)local_d8 + param_4);
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = local_dc[-2];
          fVar5 = *(float *)((int)local_bc + 4 + param_5);
          fVar6 = *(float *)((int)local_bc + 4 + param_5);
          param_2[local_e0 * 2] =
               (local_dc[-3] - *(float *)((int)local_bc + param_5)) * fVar13 +
               *(float *)((int)local_bc + param_5);
          param_2[local_e0 * 2 + 1] = fVar6 + (fVar4 - fVar5) * fVar13;
          fVar4 = pfVar18[-7];
          fVar5 = *(float *)((int)local_d8 + param_6);
          fVar6 = pfVar18[-6];
          fVar7 = *(float *)((int)local_d8 + 4 + param_6);
          fVar8 = pfVar18[-4];
          fVar9 = *(float *)((int)local_d8 + 0xc + param_6);
          bVar12 = true;
          fVar15 = *(float *)((int)local_d8 + param_6);
          fVar10 = *(float *)((int)local_d8 + 4 + param_6);
          fVar11 = *(float *)((int)local_d8 + 0xc + param_6);
          pfVar23[2] = *(float *)((int)local_d8 + 8 + param_6) +
                       (pfVar18[-5] - *(float *)((int)local_d8 + 8 + param_6)) * fVar13;
          local_e0 = local_e0 + 1;
          *pfVar23 = (fVar4 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar11 + fVar13 * (fVar8 - fVar9);
          pfVar23[1] = fVar10 + (fVar6 - fVar7) * fVar13;
          pfVar16 = pfVar17 + 4;
          pfVar22 = pfVar23 + 4;
        }
        fVar4 = pfVar21[-5];
        fVar5 = pfVar21[-4];
        *pfVar16 = pfVar21[-6];
        pfVar16[1] = fVar4;
        local_e0 = local_e0 + 1;
        pfVar17 = pfVar16 + 4;
        pfVar16[2] = fVar5;
        fVar4 = local_dc[-2];
        pfVar23 = pfVar22 + 4;
        param_2[local_e0 * 2 + -2] = local_dc[-3];
        param_2[local_e0 * 2 + -1] = fVar4;
        fVar4 = pfVar18[-6];
        fVar5 = pfVar18[-5];
        fVar6 = pfVar18[-7];
        pfVar22[3] = pfVar18[-4];
        *pfVar22 = fVar6;
        pfVar22[1] = fVar4;
        pfVar22[2] = fVar5;
      }
      if (pfVar21[-2] < param_8 == (pfVar21[-2] == param_8)) {
        if (bVar12) {
          fVar4 = pfVar21[-1];
          fVar5 = pfVar21[-5];
          fVar6 = *pfVar21;
          fVar7 = pfVar21[-4];
          *pfVar17 = pfVar21[-2] - pfVar21[-6];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar10 = (param_8 - pfVar21[-6]) / *pfVar17;
          *pfVar17 = fVar10 * *pfVar17;
          pfVar17[1] = fVar10 * pfVar17[1];
          pfVar17[2] = fVar10 * pfVar17[2];
          fVar4 = pfVar21[-5];
          fVar5 = pfVar21[-4];
          *pfVar17 = pfVar21[-6] + *pfVar17;
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = *local_dc;
          fVar5 = local_dc[-2];
          fVar6 = local_dc[-2];
          param_2[local_e0 * 2] = (local_dc[-1] - local_dc[-3]) * fVar10 + local_dc[-3];
          param_2[local_e0 * 2 + 1] = (fVar4 - fVar5) * fVar10 + fVar6;
          fVar4 = pfVar18[-3];
          fVar5 = pfVar18[-7];
          fVar6 = pfVar18[-2];
          fVar7 = pfVar18[-6];
          bVar12 = false;
          fVar8 = pfVar18[-7];
          fVar9 = pfVar18[-6];
          fVar15 = fVar10 * (*pfVar18 - pfVar18[-4]) + pfVar18[-4];
          pfVar23[2] = (*(float *)(iVar20 + (int)pfVar21) - pfVar18[-5]) * fVar10 + pfVar18[-5];
          *pfVar23 = (fVar4 - fVar5) * fVar10 + fVar8;
          pfVar23[1] = (fVar6 - fVar7) * fVar10 + fVar9;
          goto LAB_00518b56;
        }
      }
      else {
        pfVar16 = pfVar23;
        if (!bVar12) {
          fVar4 = pfVar21[-1];
          fVar5 = pfVar21[-5];
          fVar6 = *pfVar21;
          fVar7 = pfVar21[-4];
          *pfVar17 = pfVar21[-2] - pfVar21[-6];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar13 = (param_8 - pfVar21[-6]) / *pfVar17;
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar4 = pfVar21[-5];
          fVar5 = pfVar21[-4];
          *pfVar17 = pfVar21[-6] + *pfVar17;
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = *local_dc;
          fVar5 = local_dc[-2];
          fVar6 = local_dc[-2];
          param_2[local_e0 * 2] = (local_dc[-1] - local_dc[-3]) * fVar13 + local_dc[-3];
          param_2[local_e0 * 2 + 1] = (fVar4 - fVar5) * fVar13 + fVar6;
          fVar4 = pfVar18[-3];
          fVar5 = pfVar18[-7];
          fVar6 = pfVar18[-2];
          fVar7 = pfVar18[-6];
          fVar8 = *pfVar18;
          fVar9 = pfVar18[-4];
          local_e0 = local_e0 + 1;
          pfVar17 = pfVar17 + 4;
          pfVar16 = pfVar23 + 4;
          bVar12 = true;
          fVar15 = pfVar18[-7];
          fVar10 = pfVar18[-6];
          fVar11 = pfVar18[-4];
          pfVar23[2] = (*(float *)(iVar20 + (int)pfVar21) - pfVar18[-5]) * fVar13 + pfVar18[-5];
          *pfVar23 = (fVar4 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar13 * (fVar8 - fVar9) + fVar11;
          pfVar23[1] = (fVar6 - fVar7) * fVar13 + fVar10;
        }
        fVar4 = pfVar21[-1];
        fVar5 = *pfVar21;
        *pfVar17 = pfVar21[-2];
        pfVar17[1] = fVar4;
        pfVar17[2] = fVar5;
        fVar4 = *local_dc;
        param_2[local_e0 * 2] = local_dc[-1];
        param_2[local_e0 * 2 + 1] = fVar4;
        fVar4 = pfVar18[-2];
        fVar5 = *(float *)(iVar20 + (int)pfVar21);
        fVar15 = *pfVar18;
        *pfVar16 = pfVar18[-3];
        pfVar16[1] = fVar4;
        pfVar16[2] = fVar5;
        pfVar23 = pfVar16;
LAB_00518b56:
        local_e0 = local_e0 + 1;
        pfVar23[3] = fVar15;
        pfVar17 = pfVar17 + 4;
        pfVar23 = pfVar23 + 4;
      }
      if (pfVar21[2] < param_8 == (pfVar21[2] == param_8)) {
        if (bVar12) {
          fVar4 = pfVar21[3];
          fVar5 = pfVar21[-1];
          fVar6 = pfVar21[4];
          fVar7 = *pfVar21;
          *pfVar17 = pfVar21[2] - pfVar21[-2];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar10 = (param_8 - pfVar21[-2]) / *pfVar17;
          *pfVar17 = fVar10 * *pfVar17;
          pfVar17[1] = fVar10 * pfVar17[1];
          pfVar17[2] = fVar10 * pfVar17[2];
          fVar4 = pfVar21[-1];
          fVar5 = *pfVar21;
          *pfVar17 = *pfVar17 + pfVar21[-2];
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = local_dc[2];
          fVar5 = *local_dc;
          fVar6 = *local_dc;
          param_2[local_e0 * 2] = (local_dc[1] - local_dc[-1]) * fVar10 + local_dc[-1];
          param_2[local_e0 * 2 + 1] = (fVar4 - fVar5) * fVar10 + fVar6;
          fVar4 = pfVar18[1];
          fVar5 = pfVar18[-3];
          fVar6 = pfVar18[2];
          fVar7 = pfVar18[-2];
          bVar12 = false;
          fVar8 = pfVar18[-3];
          fVar9 = pfVar18[-2];
          fVar15 = fVar10 * (pfVar18[4] - *pfVar18) + *pfVar18;
          pfVar23[2] = (pfVar18[3] - *(float *)(iVar20 + (int)pfVar21)) * fVar10 +
                       *(float *)(iVar20 + (int)pfVar21);
          *pfVar23 = (fVar4 - fVar5) * fVar10 + fVar8;
          pfVar23[1] = (fVar6 - fVar7) * fVar10 + fVar9;
          goto LAB_00518e0a;
        }
      }
      else {
        pfVar16 = pfVar23;
        if (!bVar12) {
          fVar4 = pfVar21[3];
          fVar5 = pfVar21[-1];
          fVar6 = pfVar21[4];
          fVar7 = *pfVar21;
          *pfVar17 = pfVar21[2] - pfVar21[-2];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar13 = (param_8 - pfVar21[-2]) / *pfVar17;
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar4 = pfVar21[-1];
          fVar5 = *pfVar21;
          *pfVar17 = *pfVar17 + pfVar21[-2];
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = local_dc[2];
          fVar5 = *local_dc;
          fVar6 = *local_dc;
          param_2[local_e0 * 2] = (local_dc[1] - local_dc[-1]) * fVar13 + local_dc[-1];
          param_2[local_e0 * 2 + 1] = (fVar4 - fVar5) * fVar13 + fVar6;
          fVar4 = pfVar18[1];
          fVar5 = pfVar18[-3];
          fVar6 = pfVar18[2];
          fVar7 = pfVar18[-2];
          fVar8 = pfVar18[4];
          fVar9 = *pfVar18;
          local_e0 = local_e0 + 1;
          pfVar17 = pfVar17 + 4;
          pfVar16 = pfVar23 + 4;
          bVar12 = true;
          fVar15 = pfVar18[-3];
          fVar10 = pfVar18[-2];
          fVar11 = *pfVar18;
          pfVar23[2] = (pfVar18[3] - *(float *)(iVar20 + (int)pfVar21)) * fVar13 +
                       *(float *)(iVar20 + (int)pfVar21);
          *pfVar23 = (fVar4 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar13 * (fVar8 - fVar9) + fVar11;
          pfVar23[1] = (fVar6 - fVar7) * fVar13 + fVar10;
        }
        fVar4 = pfVar21[3];
        fVar5 = pfVar21[4];
        *pfVar17 = pfVar21[2];
        pfVar17[1] = fVar4;
        pfVar17[2] = fVar5;
        fVar4 = local_dc[2];
        param_2[local_e0 * 2] = local_dc[1];
        param_2[local_e0 * 2 + 1] = fVar4;
        fVar15 = pfVar18[4];
        fVar4 = pfVar18[2];
        fVar5 = pfVar18[3];
        *pfVar16 = pfVar18[1];
        pfVar16[1] = fVar4;
        pfVar16[2] = fVar5;
        pfVar23 = pfVar16;
LAB_00518e0a:
        local_e0 = local_e0 + 1;
        pfVar23[3] = fVar15;
        pfVar17 = pfVar17 + 4;
        pfVar23 = pfVar23 + 4;
      }
      if (pfVar21[6] < param_8 == (pfVar21[6] == param_8)) {
        if (bVar12) {
          fVar4 = pfVar21[7];
          fVar5 = pfVar21[3];
          fVar6 = pfVar21[8];
          fVar7 = pfVar21[4];
          *pfVar17 = pfVar21[6] - pfVar21[2];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar10 = (param_8 - pfVar21[2]) / *pfVar17;
          *pfVar17 = fVar10 * *pfVar17;
          pfVar17[1] = fVar10 * pfVar17[1];
          pfVar17[2] = fVar10 * pfVar17[2];
          fVar4 = pfVar21[3];
          fVar5 = pfVar21[4];
          *pfVar17 = pfVar21[2] + *pfVar17;
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = local_dc[4];
          fVar5 = local_dc[2];
          fVar6 = local_dc[2];
          param_2[local_e0 * 2] = (local_dc[3] - local_dc[1]) * fVar10 + local_dc[1];
          param_2[local_e0 * 2 + 1] = (fVar4 - fVar5) * fVar10 + fVar6;
          fVar4 = pfVar18[5];
          fVar5 = pfVar18[1];
          fVar6 = pfVar18[6];
          fVar7 = pfVar18[2];
          bVar12 = false;
          fVar8 = pfVar18[1];
          fVar9 = pfVar18[2];
          fVar15 = fVar10 * (pfVar18[8] - pfVar18[4]) + pfVar18[4];
          pfVar23[2] = (pfVar18[7] - pfVar18[3]) * fVar10 + pfVar18[3];
          *pfVar23 = (fVar4 - fVar5) * fVar10 + fVar8;
          pfVar23[1] = (fVar6 - fVar7) * fVar10 + fVar9;
          goto LAB_005190c2;
        }
      }
      else {
        pfVar16 = pfVar23;
        if (!bVar12) {
          fVar4 = pfVar21[7];
          fVar5 = pfVar21[3];
          fVar6 = pfVar21[8];
          fVar7 = pfVar21[4];
          *pfVar17 = pfVar21[6] - pfVar21[2];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar4 - fVar5;
          fVar13 = (param_8 - pfVar21[2]) / *pfVar17;
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar4 = pfVar21[3];
          fVar5 = pfVar21[4];
          *pfVar17 = pfVar21[2] + *pfVar17;
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = local_dc[4];
          fVar5 = local_dc[2];
          fVar6 = local_dc[2];
          param_2[local_e0 * 2] = (local_dc[3] - local_dc[1]) * fVar13 + local_dc[1];
          param_2[local_e0 * 2 + 1] = (fVar4 - fVar5) * fVar13 + fVar6;
          fVar4 = pfVar18[5];
          fVar5 = pfVar18[1];
          fVar6 = pfVar18[6];
          fVar7 = pfVar18[2];
          fVar8 = pfVar18[8];
          fVar9 = pfVar18[4];
          local_e0 = local_e0 + 1;
          pfVar17 = pfVar17 + 4;
          pfVar16 = pfVar23 + 4;
          bVar12 = true;
          fVar15 = pfVar18[1];
          fVar10 = pfVar18[2];
          fVar11 = pfVar18[4];
          pfVar23[2] = (pfVar18[7] - pfVar18[3]) * fVar13 + pfVar18[3];
          *pfVar23 = (fVar4 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar13 * (fVar8 - fVar9) + fVar11;
          pfVar23[1] = (fVar6 - fVar7) * fVar13 + fVar10;
        }
        fVar4 = pfVar21[7];
        fVar5 = pfVar21[8];
        *pfVar17 = pfVar21[6];
        pfVar17[1] = fVar4;
        pfVar17[2] = fVar5;
        fVar4 = local_dc[4];
        param_2[local_e0 * 2] = local_dc[3];
        param_2[local_e0 * 2 + 1] = fVar4;
        fVar15 = pfVar18[8];
        fVar4 = pfVar18[6];
        fVar5 = pfVar18[7];
        *pfVar16 = pfVar18[5];
        pfVar16[1] = fVar4;
        pfVar16[2] = fVar5;
        pfVar23 = pfVar16;
LAB_005190c2:
        local_e0 = local_e0 + 1;
        pfVar23[3] = fVar15;
        pfVar17 = pfVar17 + 4;
        pfVar23 = pfVar23 + 4;
      }
      local_bc = (float *)((0xc - param_5) + (int)local_dc);
      local_d8 = (float *)((0x18 - param_4) + (int)pfVar21);
      local_dc = local_dc + 8;
      local_d4 = local_d4 + 4;
      pfVar21 = pfVar21 + 0x10;
      pfVar18 = pfVar18 + 0x10;
      uVar14 = local_d0 + 4;
    } while (local_d0 + 4 < param_7);
  }
  if (local_d4 < param_7) {
    pfVar18 = (float *)(param_3 + local_e0 * 4);
    pfVar17 = (float *)(param_1 + local_e0 * 4);
    local_d8 = (float *)(local_d4 * 0x10 + 0xc + param_6);
    local_dc = (float *)(local_d4 * 0x10 + 8 + param_4);
    iVar20 = param_6 - param_4;
    iVar19 = local_d0 << 4;
    local_d0 = local_d0 << 3;
    local_bc = pfVar18;
    do {
      if (local_dc[-2] < param_8 == (local_dc[-2] == param_8)) {
        if (bVar12) {
          fVar4 = local_dc[-1];
          fVar5 = *(float *)(iVar19 + 4 + param_4);
          fVar6 = *(float *)(iVar19 + 8 + param_4);
          fVar7 = *local_dc;
          *pfVar17 = local_dc[-2] - *(float *)(iVar19 + param_4);
          pfVar17[2] = fVar7 - fVar6;
          pfVar17[1] = fVar4 - fVar5;
          fVar10 = (param_8 - *(float *)(iVar19 + param_4)) / *pfVar17;
          *pfVar17 = fVar10 * *pfVar17;
          pfVar17[1] = fVar10 * pfVar17[1];
          pfVar17[2] = fVar10 * pfVar17[2];
          fVar4 = *(float *)(iVar19 + 4 + param_4);
          fVar5 = *(float *)(iVar19 + 8 + param_4);
          *pfVar17 = *(float *)(iVar19 + param_4) + *pfVar17;
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = *(float *)(param_5 + 4 + local_d4 * 8);
          fVar5 = *(float *)(local_d0 + 4 + param_5);
          fVar6 = *(float *)(local_d0 + 4 + param_5);
          param_2[local_e0 * 2] =
               (*(float *)(param_5 + local_d4 * 8) - *(float *)(local_d0 + param_5)) * fVar10 +
               *(float *)(local_d0 + param_5);
          param_2[local_e0 * 2 + 1] = fVar6 + (fVar4 - fVar5) * fVar10;
          fVar4 = local_d8[-3];
          fVar5 = *(float *)(iVar19 + param_6);
          fVar6 = local_d8[-2];
          fVar7 = *(float *)(iVar19 + 4 + param_6);
          bVar12 = false;
          fVar8 = *(float *)(iVar19 + param_6);
          fVar9 = *(float *)(iVar19 + 4 + param_6);
          fVar15 = *(float *)(iVar19 + 0xc + param_6) +
                   fVar10 * (*local_d8 - *(float *)(iVar19 + 0xc + param_6));
          local_bc[2] = *(float *)(iVar19 + 8 + param_6) +
                        (*(float *)((int)local_dc + iVar20) - *(float *)(iVar19 + 8 + param_6)) *
                        fVar10;
          *local_bc = (fVar4 - fVar5) * fVar10 + fVar8;
          local_bc[1] = fVar9 + (fVar6 - fVar7) * fVar10;
          goto LAB_005194c6;
        }
      }
      else {
        if (!bVar12) {
          fVar4 = local_dc[-1];
          fVar5 = *(float *)(iVar19 + 4 + param_4);
          fVar6 = *(float *)(iVar19 + 8 + param_4);
          fVar7 = *local_dc;
          *pfVar17 = local_dc[-2] - *(float *)(iVar19 + param_4);
          pfVar17[2] = fVar7 - fVar6;
          pfVar17[1] = fVar4 - fVar5;
          fVar13 = (param_8 - *(float *)(iVar19 + param_4)) / *pfVar17;
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar4 = *(float *)(iVar19 + 4 + param_4);
          fVar5 = *(float *)(iVar19 + 8 + param_4);
          *pfVar17 = *pfVar17 + *(float *)(iVar19 + param_4);
          pfVar17[1] = fVar4 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar4 = *(float *)(param_5 + 4 + local_d4 * 8);
          fVar5 = *(float *)(local_d0 + 4 + param_5);
          fVar6 = *(float *)(local_d0 + 4 + param_5);
          param_2[local_e0 * 2] =
               (*(float *)(param_5 + local_d4 * 8) - *(float *)(local_d0 + param_5)) * fVar13 +
               *(float *)(local_d0 + param_5);
          param_2[local_e0 * 2 + 1] = fVar6 + (fVar4 - fVar5) * fVar13;
          fVar4 = local_d8[-3];
          fVar5 = *(float *)(iVar19 + param_6);
          fVar6 = local_d8[-2];
          fVar7 = *(float *)(iVar19 + 4 + param_6);
          pfVar17 = pfVar17 + 4;
          fVar8 = *(float *)(iVar19 + 0xc + param_6);
          bVar12 = true;
          fVar9 = *local_d8;
          fVar15 = *(float *)(iVar19 + param_6);
          fVar10 = *(float *)(iVar19 + 4 + param_6);
          fVar11 = *(float *)(iVar19 + 0xc + param_6);
          local_bc[2] = *(float *)(iVar19 + 8 + param_6) +
                        (*(float *)((int)local_dc + iVar20) - *(float *)(iVar19 + 8 + param_6)) *
                        fVar13;
          *local_bc = (fVar4 - fVar5) * fVar13 + fVar15;
          local_bc[3] = fVar11 + fVar13 * (fVar9 - fVar8);
          local_bc[1] = fVar10 + (fVar6 - fVar7) * fVar13;
          local_e0 = local_e0 + 1;
          pfVar18 = local_bc + 4;
        }
        local_bc = pfVar18;
        fVar4 = local_dc[-1];
        fVar5 = *local_dc;
        *pfVar17 = local_dc[-2];
        pfVar17[1] = fVar4;
        pfVar17[2] = fVar5;
        uVar1 = *(undefined4 *)(param_5 + 4 + local_d4 * 8);
        param_2[local_e0 * 2] = *(undefined4 *)(param_5 + local_d4 * 8);
        param_2[local_e0 * 2 + 1] = uVar1;
        fVar4 = local_d8[-2];
        fVar5 = *(float *)((int)local_dc + iVar20);
        fVar15 = *local_d8;
        *local_bc = local_d8[-3];
        local_bc[1] = fVar4;
        local_bc[2] = fVar5;
LAB_005194c6:
        local_bc[3] = fVar15;
        pfVar17 = pfVar17 + 4;
        local_e0 = local_e0 + 1;
        pfVar18 = local_bc + 4;
        local_bc = pfVar18;
      }
      local_d0 = local_d4 * 8;
      iVar19 = (-8 - param_4) + (int)local_dc;
      local_d4 = local_d4 + 1;
      local_dc = local_dc + 4;
      local_d8 = local_d8 + 4;
    } while (local_d4 < param_7);
  }
  return local_e0;
}


// ==== 0x519520 FUN_00519520

uint FUN_00519520(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,int param_4,
                 int param_5,int param_6,uint param_7,float param_8)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  bool bVar12;
  float fVar13;
  uint uVar14;
  float fVar15;
  float *pfVar16;
  float *pfVar17;
  float *pfVar18;
  int iVar19;
  int iVar20;
  float *pfVar21;
  float *pfVar22;
  float *pfVar23;
  uint local_e0;
  float *local_dc;
  float *local_d8;
  uint local_d4;
  uint local_d0;
  float *local_bc;
  
  local_d0 = param_7 - 1;
  local_d8 = (float *)(local_d0 * 0x10);
  fVar1 = *(float *)((int)local_d8 + 4 + param_4);
  bVar12 = fVar1 < param_8 != (fVar1 == param_8);
  if (bVar12) {
    uVar2 = *(undefined4 *)((int)local_d8 + 4 + param_4);
    uVar3 = *(undefined4 *)((int)local_d8 + 8 + param_4);
    *param_1 = *(undefined4 *)((int)local_d8 + param_4);
    param_1[1] = uVar2;
    param_1[2] = uVar3;
    uVar2 = *(undefined4 *)(param_5 + local_d0 * 8);
    param_2[1] = *(undefined4 *)(param_5 + 4 + local_d0 * 8);
    *param_2 = uVar2;
    uVar2 = *(undefined4 *)((int)local_d8 + 4 + param_6);
    uVar3 = *(undefined4 *)((int)local_d8 + 8 + param_6);
    uVar4 = *(undefined4 *)((int)local_d8 + 0xc + param_6);
    *param_3 = *(undefined4 *)((int)local_d8 + param_6);
    param_3[1] = uVar2;
    param_3[3] = uVar4;
    param_3[2] = uVar3;
  }
  local_e0 = (uint)bVar12;
  local_d4 = 0;
  if (3 < (int)param_7) {
    local_bc = (float *)(local_d0 * 8);
    pfVar23 = (float *)(param_3 + local_e0 * 4);
    pfVar17 = (float *)(param_1 + local_e0 * 4);
    pfVar18 = (float *)(param_6 + 0x1c);
    iVar20 = param_6 - param_4;
    local_dc = (float *)(param_5 + 0xc);
    pfVar21 = (float *)(param_4 + 0x18);
    local_d0 = 3;
    uVar14 = local_d0;
    do {
      local_d0 = uVar14;
      if (pfVar21[-5] < param_8 == (pfVar21[-5] == param_8)) {
        if (bVar12) {
          fVar1 = *(float *)((int)local_d8 + 4 + param_4);
          fVar5 = pfVar21[-5];
          fVar6 = pfVar21[-4];
          fVar7 = *(float *)((int)local_d8 + 8 + param_4);
          *pfVar17 = pfVar21[-6] - *(float *)((int)local_d8 + param_4);
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar5 - fVar1;
          fVar13 = (param_8 - *(float *)((int)local_d8 + 4 + param_4)) / pfVar17[1];
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar1 = *(float *)((int)local_d8 + 4 + param_4);
          fVar5 = *(float *)((int)local_d8 + 8 + param_4);
          *pfVar17 = *(float *)((int)local_d8 + param_4) + *pfVar17;
          pfVar17[1] = fVar1 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar1 = local_dc[-2];
          fVar5 = *(float *)((int)local_bc + 4 + param_5);
          fVar6 = *(float *)((int)local_bc + 4 + param_5);
          param_2[local_e0 * 2] =
               (local_dc[-3] - *(float *)((int)local_bc + param_5)) * fVar13 +
               *(float *)((int)local_bc + param_5);
          param_2[local_e0 * 2 + 1] = fVar6 + (fVar1 - fVar5) * fVar13;
          fVar1 = pfVar18[-7];
          fVar5 = *(float *)((int)local_d8 + param_6);
          fVar6 = pfVar18[-6];
          pfVar17 = pfVar17 + 4;
          fVar7 = *(float *)((int)local_d8 + 4 + param_6);
          fVar8 = pfVar18[-4];
          fVar9 = *(float *)((int)local_d8 + 0xc + param_6);
          bVar12 = false;
          fVar15 = *(float *)((int)local_d8 + param_6);
          fVar10 = *(float *)((int)local_d8 + 4 + param_6);
          fVar11 = *(float *)((int)local_d8 + 0xc + param_6);
          pfVar23[2] = *(float *)((int)local_d8 + 8 + param_6) +
                       (pfVar18[-5] - *(float *)((int)local_d8 + 8 + param_6)) * fVar13;
          local_e0 = local_e0 + 1;
          *pfVar23 = (fVar1 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar11 + fVar13 * (fVar8 - fVar9);
          pfVar23[1] = fVar10 + (fVar6 - fVar7) * fVar13;
          pfVar23 = pfVar23 + 4;
        }
      }
      else {
        pfVar16 = pfVar17;
        pfVar22 = pfVar23;
        if (!bVar12) {
          fVar1 = *(float *)((int)local_d8 + 4 + param_4);
          fVar5 = pfVar21[-5];
          fVar6 = pfVar21[-4];
          fVar7 = *(float *)((int)local_d8 + 8 + param_4);
          *pfVar17 = pfVar21[-6] - *(float *)((int)local_d8 + param_4);
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar5 - fVar1;
          fVar13 = (param_8 - *(float *)((int)local_d8 + 4 + param_4)) / pfVar17[1];
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar1 = *(float *)((int)local_d8 + 4 + param_4);
          fVar5 = *(float *)((int)local_d8 + 8 + param_4);
          *pfVar17 = *pfVar17 + *(float *)((int)local_d8 + param_4);
          pfVar17[1] = fVar1 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar1 = local_dc[-2];
          fVar5 = *(float *)((int)local_bc + 4 + param_5);
          fVar6 = *(float *)((int)local_bc + 4 + param_5);
          param_2[local_e0 * 2] =
               (local_dc[-3] - *(float *)((int)local_bc + param_5)) * fVar13 +
               *(float *)((int)local_bc + param_5);
          param_2[local_e0 * 2 + 1] = fVar6 + (fVar1 - fVar5) * fVar13;
          fVar1 = pfVar18[-7];
          fVar5 = *(float *)((int)local_d8 + param_6);
          fVar6 = pfVar18[-6];
          fVar7 = *(float *)((int)local_d8 + 4 + param_6);
          fVar8 = pfVar18[-4];
          fVar9 = *(float *)((int)local_d8 + 0xc + param_6);
          bVar12 = true;
          fVar15 = *(float *)((int)local_d8 + param_6);
          fVar10 = *(float *)((int)local_d8 + 4 + param_6);
          fVar11 = *(float *)((int)local_d8 + 0xc + param_6);
          pfVar23[2] = *(float *)((int)local_d8 + 8 + param_6) +
                       (pfVar18[-5] - *(float *)((int)local_d8 + 8 + param_6)) * fVar13;
          local_e0 = local_e0 + 1;
          *pfVar23 = (fVar1 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar11 + fVar13 * (fVar8 - fVar9);
          pfVar23[1] = fVar10 + (fVar6 - fVar7) * fVar13;
          pfVar16 = pfVar17 + 4;
          pfVar22 = pfVar23 + 4;
        }
        fVar1 = pfVar21[-5];
        fVar5 = pfVar21[-4];
        local_e0 = local_e0 + 1;
        pfVar17 = pfVar16 + 4;
        *pfVar16 = pfVar21[-6];
        pfVar16[1] = fVar1;
        pfVar23 = pfVar22 + 4;
        pfVar16[2] = fVar5;
        fVar1 = local_dc[-2];
        param_2[local_e0 * 2 + -2] = local_dc[-3];
        param_2[local_e0 * 2 + -1] = fVar1;
        fVar1 = pfVar18[-6];
        fVar5 = pfVar18[-5];
        fVar6 = pfVar18[-7];
        pfVar22[3] = pfVar18[-4];
        *pfVar22 = fVar6;
        pfVar22[1] = fVar1;
        pfVar22[2] = fVar5;
      }
      if (pfVar21[-1] < param_8 == (pfVar21[-1] == param_8)) {
        if (bVar12) {
          fVar1 = pfVar21[-1];
          fVar5 = pfVar21[-5];
          fVar6 = *pfVar21;
          fVar7 = pfVar21[-4];
          *pfVar17 = pfVar21[-2] - pfVar21[-6];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar1 - fVar5;
          fVar10 = (param_8 - pfVar21[-5]) / pfVar17[1];
          *pfVar17 = fVar10 * *pfVar17;
          pfVar17[1] = fVar10 * pfVar17[1];
          pfVar17[2] = fVar10 * pfVar17[2];
          fVar1 = pfVar21[-5];
          fVar5 = pfVar21[-4];
          *pfVar17 = *pfVar17 + pfVar21[-6];
          pfVar17[1] = fVar1 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar1 = *local_dc;
          fVar5 = local_dc[-2];
          fVar6 = local_dc[-2];
          param_2[local_e0 * 2] = (local_dc[-1] - local_dc[-3]) * fVar10 + local_dc[-3];
          param_2[local_e0 * 2 + 1] = (fVar1 - fVar5) * fVar10 + fVar6;
          fVar1 = pfVar18[-3];
          fVar5 = pfVar18[-7];
          fVar6 = pfVar18[-2];
          fVar7 = pfVar18[-6];
          bVar12 = false;
          fVar8 = pfVar18[-7];
          fVar9 = pfVar18[-6];
          fVar15 = fVar10 * (*pfVar18 - pfVar18[-4]) + pfVar18[-4];
          pfVar23[2] = (*(float *)(iVar20 + (int)pfVar21) - pfVar18[-5]) * fVar10 + pfVar18[-5];
          *pfVar23 = (fVar1 - fVar5) * fVar10 + fVar8;
          pfVar23[1] = (fVar6 - fVar7) * fVar10 + fVar9;
          goto LAB_00519c1e;
        }
      }
      else {
        pfVar16 = pfVar23;
        if (!bVar12) {
          fVar1 = pfVar21[-1];
          fVar5 = pfVar21[-5];
          fVar6 = *pfVar21;
          fVar7 = pfVar21[-4];
          *pfVar17 = pfVar21[-2] - pfVar21[-6];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar1 - fVar5;
          fVar13 = (param_8 - pfVar21[-5]) / pfVar17[1];
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar1 = pfVar21[-5];
          fVar5 = pfVar21[-4];
          *pfVar17 = *pfVar17 + pfVar21[-6];
          pfVar17[1] = fVar1 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar1 = *local_dc;
          fVar5 = local_dc[-2];
          fVar6 = local_dc[-2];
          param_2[local_e0 * 2] = (local_dc[-1] - local_dc[-3]) * fVar13 + local_dc[-3];
          param_2[local_e0 * 2 + 1] = (fVar1 - fVar5) * fVar13 + fVar6;
          fVar1 = pfVar18[-3];
          fVar5 = pfVar18[-7];
          fVar6 = pfVar18[-2];
          fVar7 = pfVar18[-6];
          fVar8 = *pfVar18;
          fVar9 = pfVar18[-4];
          local_e0 = local_e0 + 1;
          pfVar17 = pfVar17 + 4;
          pfVar16 = pfVar23 + 4;
          bVar12 = true;
          fVar15 = pfVar18[-7];
          fVar10 = pfVar18[-6];
          fVar11 = pfVar18[-4];
          pfVar23[2] = (*(float *)(iVar20 + (int)pfVar21) - pfVar18[-5]) * fVar13 + pfVar18[-5];
          *pfVar23 = (fVar1 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar13 * (fVar8 - fVar9) + fVar11;
          pfVar23[1] = (fVar6 - fVar7) * fVar13 + fVar10;
        }
        fVar1 = pfVar21[-1];
        fVar5 = *pfVar21;
        *pfVar17 = pfVar21[-2];
        pfVar17[1] = fVar1;
        pfVar17[2] = fVar5;
        fVar1 = *local_dc;
        param_2[local_e0 * 2] = local_dc[-1];
        param_2[local_e0 * 2 + 1] = fVar1;
        fVar1 = pfVar18[-2];
        fVar5 = *(float *)(iVar20 + (int)pfVar21);
        fVar15 = *pfVar18;
        *pfVar16 = pfVar18[-3];
        pfVar16[1] = fVar1;
        pfVar16[2] = fVar5;
        pfVar23 = pfVar16;
LAB_00519c1e:
        local_e0 = local_e0 + 1;
        pfVar23[3] = fVar15;
        pfVar17 = pfVar17 + 4;
        pfVar23 = pfVar23 + 4;
      }
      if (pfVar21[3] < param_8 == (pfVar21[3] == param_8)) {
        if (bVar12) {
          fVar1 = pfVar21[3];
          fVar5 = pfVar21[-1];
          fVar6 = pfVar21[4];
          fVar7 = *pfVar21;
          *pfVar17 = pfVar21[2] - pfVar21[-2];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar1 - fVar5;
          fVar10 = (param_8 - pfVar21[-1]) / pfVar17[1];
          *pfVar17 = fVar10 * *pfVar17;
          pfVar17[1] = fVar10 * pfVar17[1];
          pfVar17[2] = fVar10 * pfVar17[2];
          fVar1 = pfVar21[-1];
          fVar5 = *pfVar21;
          *pfVar17 = *pfVar17 + pfVar21[-2];
          pfVar17[1] = fVar1 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar1 = local_dc[2];
          fVar5 = *local_dc;
          fVar6 = *local_dc;
          param_2[local_e0 * 2] = (local_dc[1] - local_dc[-1]) * fVar10 + local_dc[-1];
          param_2[local_e0 * 2 + 1] = (fVar1 - fVar5) * fVar10 + fVar6;
          fVar1 = pfVar18[1];
          fVar5 = pfVar18[-3];
          fVar6 = pfVar18[2];
          fVar7 = pfVar18[-2];
          bVar12 = false;
          fVar8 = pfVar18[-3];
          fVar9 = pfVar18[-2];
          fVar15 = fVar10 * (pfVar18[4] - *pfVar18) + *pfVar18;
          pfVar23[2] = (pfVar18[3] - *(float *)(iVar20 + (int)pfVar21)) * fVar10 +
                       *(float *)(iVar20 + (int)pfVar21);
          *pfVar23 = (fVar1 - fVar5) * fVar10 + fVar8;
          pfVar23[1] = (fVar6 - fVar7) * fVar10 + fVar9;
          goto LAB_00519ed4;
        }
      }
      else {
        pfVar16 = pfVar23;
        if (!bVar12) {
          fVar1 = pfVar21[3];
          fVar5 = pfVar21[-1];
          fVar6 = pfVar21[4];
          fVar7 = *pfVar21;
          *pfVar17 = pfVar21[2] - pfVar21[-2];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar1 - fVar5;
          fVar13 = (param_8 - pfVar21[-1]) / pfVar17[1];
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar1 = pfVar21[-1];
          fVar5 = *pfVar21;
          *pfVar17 = *pfVar17 + pfVar21[-2];
          pfVar17[1] = fVar1 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar1 = local_dc[2];
          fVar5 = *local_dc;
          fVar6 = *local_dc;
          param_2[local_e0 * 2] = (local_dc[1] - local_dc[-1]) * fVar13 + local_dc[-1];
          param_2[local_e0 * 2 + 1] = (fVar1 - fVar5) * fVar13 + fVar6;
          fVar1 = pfVar18[1];
          fVar5 = pfVar18[-3];
          fVar6 = pfVar18[2];
          fVar7 = pfVar18[-2];
          fVar8 = pfVar18[4];
          fVar9 = *pfVar18;
          local_e0 = local_e0 + 1;
          pfVar17 = pfVar17 + 4;
          pfVar16 = pfVar23 + 4;
          bVar12 = true;
          fVar15 = pfVar18[-3];
          fVar10 = pfVar18[-2];
          fVar11 = *pfVar18;
          pfVar23[2] = (pfVar18[3] - *(float *)(iVar20 + (int)pfVar21)) * fVar13 +
                       *(float *)(iVar20 + (int)pfVar21);
          *pfVar23 = (fVar1 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar13 * (fVar8 - fVar9) + fVar11;
          pfVar23[1] = (fVar6 - fVar7) * fVar13 + fVar10;
        }
        fVar1 = pfVar21[3];
        fVar5 = pfVar21[4];
        *pfVar17 = pfVar21[2];
        pfVar17[1] = fVar1;
        pfVar17[2] = fVar5;
        fVar1 = local_dc[2];
        param_2[local_e0 * 2] = local_dc[1];
        param_2[local_e0 * 2 + 1] = fVar1;
        fVar15 = pfVar18[4];
        fVar1 = pfVar18[2];
        fVar5 = pfVar18[3];
        *pfVar16 = pfVar18[1];
        pfVar16[1] = fVar1;
        pfVar16[2] = fVar5;
        pfVar23 = pfVar16;
LAB_00519ed4:
        local_e0 = local_e0 + 1;
        pfVar23[3] = fVar15;
        pfVar17 = pfVar17 + 4;
        pfVar23 = pfVar23 + 4;
      }
      if (pfVar21[7] < param_8 == (pfVar21[7] == param_8)) {
        if (bVar12) {
          fVar1 = pfVar21[7];
          fVar5 = pfVar21[3];
          fVar6 = pfVar21[8];
          fVar7 = pfVar21[4];
          *pfVar17 = pfVar21[6] - pfVar21[2];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar1 - fVar5;
          fVar10 = (param_8 - pfVar21[3]) / pfVar17[1];
          *pfVar17 = fVar10 * *pfVar17;
          pfVar17[1] = fVar10 * pfVar17[1];
          pfVar17[2] = fVar10 * pfVar17[2];
          fVar1 = pfVar21[3];
          fVar5 = pfVar21[4];
          *pfVar17 = *pfVar17 + pfVar21[2];
          pfVar17[1] = fVar1 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar1 = local_dc[4];
          fVar5 = local_dc[2];
          fVar6 = local_dc[2];
          param_2[local_e0 * 2] = (local_dc[3] - local_dc[1]) * fVar10 + local_dc[1];
          param_2[local_e0 * 2 + 1] = (fVar1 - fVar5) * fVar10 + fVar6;
          fVar1 = pfVar18[5];
          fVar5 = pfVar18[1];
          fVar6 = pfVar18[6];
          fVar7 = pfVar18[2];
          bVar12 = false;
          fVar8 = pfVar18[1];
          fVar9 = pfVar18[2];
          fVar15 = fVar10 * (pfVar18[8] - pfVar18[4]) + pfVar18[4];
          pfVar23[2] = (pfVar18[7] - pfVar18[3]) * fVar10 + pfVar18[3];
          *pfVar23 = (fVar1 - fVar5) * fVar10 + fVar8;
          pfVar23[1] = (fVar6 - fVar7) * fVar10 + fVar9;
          goto LAB_0051a18e;
        }
      }
      else {
        pfVar16 = pfVar23;
        if (!bVar12) {
          fVar1 = pfVar21[7];
          fVar5 = pfVar21[3];
          fVar6 = pfVar21[8];
          fVar7 = pfVar21[4];
          *pfVar17 = pfVar21[6] - pfVar21[2];
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar1 - fVar5;
          fVar13 = (param_8 - pfVar21[3]) / pfVar17[1];
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar1 = pfVar21[3];
          fVar5 = pfVar21[4];
          *pfVar17 = *pfVar17 + pfVar21[2];
          pfVar17[1] = fVar1 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar1 = local_dc[4];
          fVar5 = local_dc[2];
          fVar6 = local_dc[2];
          param_2[local_e0 * 2] = (local_dc[3] - local_dc[1]) * fVar13 + local_dc[1];
          param_2[local_e0 * 2 + 1] = (fVar1 - fVar5) * fVar13 + fVar6;
          fVar1 = pfVar18[5];
          fVar5 = pfVar18[1];
          fVar6 = pfVar18[6];
          fVar7 = pfVar18[2];
          fVar8 = pfVar18[8];
          fVar9 = pfVar18[4];
          local_e0 = local_e0 + 1;
          pfVar17 = pfVar17 + 4;
          pfVar16 = pfVar23 + 4;
          bVar12 = true;
          fVar15 = pfVar18[1];
          fVar10 = pfVar18[2];
          fVar11 = pfVar18[4];
          pfVar23[2] = (pfVar18[7] - pfVar18[3]) * fVar13 + pfVar18[3];
          *pfVar23 = (fVar1 - fVar5) * fVar13 + fVar15;
          pfVar23[3] = fVar13 * (fVar8 - fVar9) + fVar11;
          pfVar23[1] = (fVar6 - fVar7) * fVar13 + fVar10;
        }
        fVar1 = pfVar21[7];
        fVar5 = pfVar21[8];
        *pfVar17 = pfVar21[6];
        pfVar17[1] = fVar1;
        pfVar17[2] = fVar5;
        fVar1 = local_dc[4];
        param_2[local_e0 * 2] = local_dc[3];
        param_2[local_e0 * 2 + 1] = fVar1;
        fVar15 = pfVar18[8];
        fVar1 = pfVar18[6];
        fVar5 = pfVar18[7];
        *pfVar16 = pfVar18[5];
        pfVar16[1] = fVar1;
        pfVar16[2] = fVar5;
        pfVar23 = pfVar16;
LAB_0051a18e:
        local_e0 = local_e0 + 1;
        pfVar23[3] = fVar15;
        pfVar17 = pfVar17 + 4;
        pfVar23 = pfVar23 + 4;
      }
      local_bc = (float *)((0xc - param_5) + (int)local_dc);
      local_d8 = (float *)((0x18 - param_4) + (int)pfVar21);
      local_dc = local_dc + 8;
      local_d4 = local_d4 + 4;
      pfVar18 = pfVar18 + 0x10;
      pfVar21 = pfVar21 + 0x10;
      uVar14 = local_d0 + 4;
    } while (local_d0 + 4 < param_7);
  }
  if (local_d4 < param_7) {
    pfVar18 = (float *)(param_3 + local_e0 * 4);
    pfVar17 = (float *)(param_1 + local_e0 * 4);
    local_d8 = (float *)(local_d4 * 0x10 + 0xc + param_6);
    local_dc = (float *)(local_d4 * 0x10 + 4 + param_4);
    iVar20 = param_6 - param_4;
    iVar19 = local_d0 << 4;
    local_d0 = local_d0 << 3;
    local_bc = pfVar18;
    do {
      if (*local_dc < param_8 == (*local_dc == param_8)) {
        if (bVar12) {
          fVar1 = *(float *)(iVar19 + 4 + param_4);
          fVar5 = *local_dc;
          fVar6 = local_dc[1];
          fVar7 = *(float *)(iVar19 + 8 + param_4);
          *pfVar17 = local_dc[-1] - *(float *)(iVar19 + param_4);
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar5 - fVar1;
          fVar10 = (param_8 - *(float *)(iVar19 + 4 + param_4)) / pfVar17[1];
          *pfVar17 = fVar10 * *pfVar17;
          pfVar17[1] = fVar10 * pfVar17[1];
          pfVar17[2] = fVar10 * pfVar17[2];
          fVar1 = *(float *)(iVar19 + 4 + param_4);
          fVar5 = *(float *)(iVar19 + 8 + param_4);
          *pfVar17 = *(float *)(iVar19 + param_4) + *pfVar17;
          pfVar17[1] = fVar1 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar1 = *(float *)(param_5 + 4 + local_d4 * 8);
          fVar5 = *(float *)(local_d0 + 4 + param_5);
          fVar6 = *(float *)(local_d0 + 4 + param_5);
          param_2[local_e0 * 2] =
               (*(float *)(param_5 + local_d4 * 8) - *(float *)(local_d0 + param_5)) * fVar10 +
               *(float *)(local_d0 + param_5);
          param_2[local_e0 * 2 + 1] = fVar6 + (fVar1 - fVar5) * fVar10;
          fVar1 = local_d8[-3];
          fVar5 = *(float *)(iVar19 + param_6);
          fVar6 = *(float *)((int)local_dc + iVar20);
          fVar7 = *(float *)(iVar19 + 4 + param_6);
          bVar12 = false;
          fVar8 = *(float *)(iVar19 + param_6);
          fVar9 = *(float *)(iVar19 + 4 + param_6);
          fVar15 = *(float *)(iVar19 + 0xc + param_6) +
                   fVar10 * (*local_d8 - *(float *)(iVar19 + 0xc + param_6));
          local_bc[2] = *(float *)(iVar19 + 8 + param_6) +
                        (local_d8[-1] - *(float *)(iVar19 + 8 + param_6)) * fVar10;
          *local_bc = (fVar1 - fVar5) * fVar10 + fVar8;
          local_bc[1] = fVar9 + (fVar6 - fVar7) * fVar10;
          goto LAB_0051a593;
        }
      }
      else {
        if (!bVar12) {
          fVar1 = *(float *)(iVar19 + 4 + param_4);
          fVar5 = *local_dc;
          fVar6 = local_dc[1];
          fVar7 = *(float *)(iVar19 + 8 + param_4);
          *pfVar17 = local_dc[-1] - *(float *)(iVar19 + param_4);
          pfVar17[2] = fVar6 - fVar7;
          pfVar17[1] = fVar5 - fVar1;
          fVar13 = (param_8 - *(float *)(iVar19 + 4 + param_4)) / pfVar17[1];
          *pfVar17 = fVar13 * *pfVar17;
          pfVar17[1] = fVar13 * pfVar17[1];
          pfVar17[2] = fVar13 * pfVar17[2];
          fVar1 = *(float *)(iVar19 + 4 + param_4);
          fVar5 = *(float *)(iVar19 + 8 + param_4);
          *pfVar17 = *pfVar17 + *(float *)(iVar19 + param_4);
          pfVar17[1] = fVar1 + pfVar17[1];
          pfVar17[2] = fVar5 + pfVar17[2];
          fVar1 = *(float *)(param_5 + 4 + local_d4 * 8);
          fVar5 = *(float *)(local_d0 + 4 + param_5);
          fVar6 = *(float *)(local_d0 + 4 + param_5);
          param_2[local_e0 * 2] =
               (*(float *)(param_5 + local_d4 * 8) - *(float *)(local_d0 + param_5)) * fVar13 +
               *(float *)(local_d0 + param_5);
          param_2[local_e0 * 2 + 1] = fVar6 + (fVar1 - fVar5) * fVar13;
          fVar1 = local_d8[-3];
          fVar5 = *(float *)(iVar19 + param_6);
          fVar6 = *(float *)((int)local_dc + iVar20);
          fVar7 = *(float *)(iVar19 + 4 + param_6);
          pfVar17 = pfVar17 + 4;
          fVar8 = *(float *)(iVar19 + 0xc + param_6);
          fVar9 = *local_d8;
          bVar12 = true;
          fVar15 = *(float *)(iVar19 + param_6);
          fVar10 = *(float *)(iVar19 + 4 + param_6);
          fVar11 = *(float *)(iVar19 + 0xc + param_6);
          local_bc[2] = *(float *)(iVar19 + 8 + param_6) +
                        (local_d8[-1] - *(float *)(iVar19 + 8 + param_6)) * fVar13;
          *local_bc = (fVar1 - fVar5) * fVar13 + fVar15;
          local_bc[3] = fVar11 + fVar13 * (fVar9 - fVar8);
          local_bc[1] = fVar10 + (fVar6 - fVar7) * fVar13;
          local_e0 = local_e0 + 1;
          pfVar18 = local_bc + 4;
        }
        local_bc = pfVar18;
        fVar1 = *local_dc;
        fVar5 = local_dc[1];
        *pfVar17 = local_dc[-1];
        pfVar17[1] = fVar1;
        pfVar17[2] = fVar5;
        uVar2 = *(undefined4 *)(param_5 + 4 + local_d4 * 8);
        param_2[local_e0 * 2] = *(undefined4 *)(param_5 + local_d4 * 8);
        param_2[local_e0 * 2 + 1] = uVar2;
        fVar1 = *(float *)((int)local_dc + iVar20);
        fVar5 = local_d8[-1];
        fVar15 = *local_d8;
        *local_bc = local_d8[-3];
        local_bc[1] = fVar1;
        local_bc[2] = fVar5;
LAB_0051a593:
        local_bc[3] = fVar15;
        pfVar17 = pfVar17 + 4;
        local_e0 = local_e0 + 1;
        pfVar18 = local_bc + 4;
        local_bc = pfVar18;
      }
      local_d0 = local_d4 * 8;
      iVar19 = (-4 - param_4) + (int)local_dc;
      local_d4 = local_d4 + 1;
      local_dc = local_dc + 4;
      local_d8 = local_d8 + 4;
    } while (local_d4 < param_7);
  }
  return local_e0;
}


// ==== 0x51a5f0 FUN_0051a5f0

undefined4
FUN_0051a5f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_005162d0(param_6);
  if (iVar1 != 0) {
    iVar1 = FUN_00517390(param_3,param_4,param_5,param_6);
    if (iVar1 != 0) {
      iVar1 = FUN_00518460(param_6);
      if (iVar1 != 0) {
        uVar2 = FUN_00519520(param_3,param_4,param_5,param_6);
        return uVar2;
      }
    }
  }
  return 0;
}


// ==== 0x51a690 FUN_0051a690

void FUN_0051a690(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar4 = DAT_00735708;
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


// ==== 0x51a6d0 FUN_0051a6d0

void __fastcall FUN_0051a6d0(short *param_1)

{
  int *in_EAX;
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  int *piVar4;
  int unaff_EDI;
  
  if (((int)*param_1 == *in_EAX) && ((int)param_1[1] == in_EAX[1])) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  *(undefined1 *)((int)in_EAX + 0x1d) = uVar2;
  *in_EAX = (int)*param_1;
  in_EAX[1] = (int)param_1[1];
  in_EAX[2] = (int)param_1[2];
  *(undefined2 *)(in_EAX + 3) = *(undefined2 *)((int)in_EAX + 0xe);
  *(short *)((int)in_EAX + 0xe) = param_1[3];
  iVar1 = 0;
  piVar4 = in_EAX + 4;
  do {
    uVar3 = 1 << ((byte)iVar1 & 0x1f);
    if ((uVar3 & *(ushort *)((int)in_EAX + 0xe)) != 0) {
      if ((uVar3 & *(ushort *)(in_EAX + 3)) == 0) {
        *piVar4 = 0;
      }
      else {
        *piVar4 = *piVar4 + unaff_EDI;
      }
    }
    iVar1 = iVar1 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar1 < 3);
  return;
}


// ==== 0x51a750 FUN_0051a750

void __fastcall FUN_0051a750(int param_1)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint unaff_EDI;
  uint uVar6;
  
  uVar3 = 0xffffffff;
  uVar6 = unaff_EDI & 0xffff;
  puVar5 = (uint *)(param_1 + 0x14);
  iVar4 = 2;
  do {
    bVar2 = (byte)iVar4;
    if (((uVar6 & 1 << (bVar2 - 2 & 0x1f)) != 0) && (puVar5[-1] <= uVar3)) {
      uVar3 = puVar5[-1];
    }
    if (((uVar6 & 1 << (bVar2 - 1 & 0x1f)) != 0) && (*puVar5 <= uVar3)) {
      uVar3 = *puVar5;
    }
    if (((uVar6 & 1 << (bVar2 & 0x1f)) != 0) && (puVar5[1] <= uVar3)) {
      uVar3 = puVar5[1];
    }
    if (((uVar6 & 1 << (bVar2 + 1 & 0x1f)) != 0) && (puVar5[2] <= uVar3)) {
      uVar3 = puVar5[2];
    }
    if (((uVar6 & 1 << (bVar2 + 2 & 0x1f)) != 0) && (puVar5[3] <= uVar3)) {
      uVar3 = puVar5[3];
    }
    if (((uVar6 & 1 << (bVar2 + 3 & 0x1f)) != 0) && (puVar5[4] <= uVar3)) {
      uVar3 = puVar5[4];
    }
    if (((uVar6 & 1 << (bVar2 + 4 & 0x1f)) != 0) && (puVar5[5] <= uVar3)) {
      uVar3 = puVar5[5];
    }
    if (((uVar6 & 1 << (bVar2 + 5 & 0x1f)) != 0) && (puVar5[6] <= uVar3)) {
      uVar3 = puVar5[6];
    }
    iVar1 = iVar4 + 6;
    puVar5 = puVar5 + 8;
    iVar4 = iVar4 + 8;
  } while (iVar1 < 0x20);
  return;
}


// ==== 0x51a830 FUN_0051a830

void * __thiscall FUN_0051a830(void *param_1,byte param_2)

{
  FUN_0051a850();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x51a850 FUN_0051a850

void __fastcall FUN_0051a850(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c0130;
  return;
}


// ==== 0x51a860 FUN_0051a860

void FUN_0051a860(void)

{
  if (DAT_007449cc != 0) {
    FUN_00546060();
  }
  if (DAT_007449d0 != 0) {
    FUN_00546060();
  }
  if (DAT_007449d4 != 0) {
    FUN_00546060();
  }
  DAT_007449cc = 0;
  DAT_007449d0 = 0;
  DAT_007449d4 = 0;
  DAT_007449c8 = 0;
  return;
}


// ==== 0x51a8b0 FUN_0051a8b0

undefined4 __fastcall FUN_0051a8b0(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_00744ab0)[iVar1 * 2] == param_1) {
      return *(undefined4 *)(&DAT_00744ab4 + iVar1 * 8);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x1b);
  return 0;
}


// ==== 0x51a8d0 FUN_0051a8d0

undefined4 * FUN_0051a8d0(int param_1)

{
  int *****pppppiVar1;
  int ****ppppiVar2;
  int ****ppppiVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_EAX;
  int *****pppppiVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint uVar12;
  undefined4 *puVar13;
  int *****_Memory;
  int iVar14;
  int *local_18;
  int *local_14;
  int local_10;
  int *local_c;
  int ****local_8;
  int ****local_4;
  
  local_8 = (int ****)&local_8;
  local_4 = (int ****)&local_8;
  local_14 = (int *)0x0;
  local_18 = (int *)0x0;
  local_10 = FUN_0051c480(&DAT_00744238,param_1,&local_c,&local_18,&local_8,&local_14,0xffffffff);
  _Memory = (int *****)local_8;
  if (in_EAX != 0) {
    iVar14 = 0;
    *(int **)(in_EAX + 0xc) = local_14;
    *(undefined4 *)(in_EAX + 4) = 0;
    *(undefined4 *)(in_EAX + 8) = 0;
    pppppiVar6 = (int *****)NullUpdate_ret();
    for (pppppiVar1 = _Memory; pppppiVar1 != pppppiVar6; pppppiVar1 = (int *****)*pppppiVar1) {
      *(int *)(in_EAX + 4) = *(int *)(in_EAX + 4) + (int)pppppiVar1[2];
      if (iVar14 < (int)local_18) {
        *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + (int)pppppiVar1[2];
      }
      iVar14 = iVar14 + 1;
    }
  }
  if (local_10 == 0) {
    if (_Memory != &local_8) {
      do {
        ppppiVar2 = *_Memory;
        ppppiVar3 = _Memory[1];
        *ppppiVar3 = (int ***)ppppiVar2;
        ppppiVar2[1] = (int ***)ppppiVar3;
        _free(_Memory);
        _Memory = (int *****)local_8;
      } while ((int *****)local_8 != &local_8);
    }
    return (undefined4 *)0x0;
  }
  if (in_EAX != 0) {
    iVar14 = 0;
    do {
      if ((&DAT_00744ab0)[iVar14 * 2] == param_1) {
        uVar7 = *(undefined4 *)(&DAT_00744ab4 + iVar14 * 8);
        goto LAB_0051a9b6;
      }
      iVar14 = iVar14 + 1;
    } while (iVar14 < 0x1b);
    uVar7 = 0;
LAB_0051a9b6:
    *(undefined4 *)(in_EAX + 0x24) = uVar7;
  }
  uVar12 = *(uint *)(local_10 + 0x10);
  if (in_EAX != 0) {
    *(uint *)(in_EAX + 0x10) = uVar12;
  }
  if (uVar12 == 0) {
    uVar12 = 0;
  }
  else {
    uVar12 = DAT_006f227c % uVar12;
    uVar11 = DAT_006f227c ^ 0x1d872b41;
    uVar8 = uVar11 >> 5 ^ uVar11;
    DAT_006f227c = uVar8 << 0x1b ^ uVar8 ^ uVar11;
  }
  iVar14 = *(int *)(local_10 + 0x28 + uVar12 * 4);
  if (in_EAX != 0) {
    *(uint *)(in_EAX + 0x2c) = uVar12;
  }
  local_18 = DAT_00744244;
  for (iVar9 = 0; (local_18 != (int *)0x0 && (iVar9 < iVar14)); iVar9 = iVar9 + 1) {
    local_18 = (int *)*local_18;
  }
  uVar12 = *(uint *)(local_10 + 0x14);
  if (in_EAX != 0) {
    *(uint *)(in_EAX + 0x14) = uVar12;
  }
  if (uVar12 == 0) {
    uVar12 = 0;
  }
  else {
    uVar12 = DAT_006f227c % uVar12;
    uVar11 = DAT_006f227c ^ 0x1d872b41;
    uVar8 = uVar11 >> 5 ^ uVar11;
    DAT_006f227c = uVar11 ^ uVar8 << 0x1b ^ uVar8;
  }
  iVar14 = *(int *)(local_10 + 0x68 + uVar12 * 4);
  if (in_EAX != 0) {
    *(uint *)(in_EAX + 0x30) = uVar12;
  }
  local_14 = DAT_0074424c;
  for (iVar9 = 0; (local_14 != (int *)0x0 && (iVar9 < iVar14)); iVar9 = iVar9 + 1) {
    local_14 = (int *)*local_14;
  }
  uVar12 = *(uint *)(local_10 + 0x18);
  if (in_EAX != 0) {
    *(uint *)(in_EAX + 0x20) = uVar12;
  }
  if (uVar12 == 0) {
    uVar12 = 0;
  }
  else {
    uVar12 = DAT_006f227c % uVar12;
    uVar11 = DAT_006f227c ^ 0x1d872b41;
    uVar8 = uVar11 >> 5 ^ uVar11;
    DAT_006f227c = uVar11 ^ uVar8 << 0x1b ^ uVar8;
  }
  iVar14 = *(int *)(local_10 + 0xa8 + uVar12 * 4);
  if (in_EAX != 0) {
    *(uint *)(in_EAX + 0x3c) = uVar12;
  }
  if (iVar14 == -1) {
    local_c = (int *)0x0;
  }
  else {
    local_c = DAT_00744254;
    for (iVar9 = 0; (local_c != (int *)0x0 && (iVar9 < iVar14)); iVar9 = iVar9 + 1) {
      local_c = (int *)*local_c;
    }
  }
  uVar12 = *(uint *)(local_10 + 0x1c);
  if (in_EAX != 0) {
    *(uint *)(in_EAX + 0x18) = uVar12;
  }
  if (uVar12 == 0) {
    uVar12 = 0;
  }
  else {
    uVar12 = DAT_006f227c % uVar12;
    uVar11 = DAT_006f227c ^ 0x1d872b41;
    uVar8 = uVar11 >> 5 ^ uVar11;
    DAT_006f227c = uVar11 ^ uVar8 << 0x1b ^ uVar8;
  }
  iVar14 = *(int *)(local_10 + 0xe8 + uVar12 * 4);
  if (in_EAX != 0) {
    *(uint *)(in_EAX + 0x34) = uVar12;
  }
  puVar4 = DAT_0074425c;
  for (iVar9 = 0; (puVar4 != (undefined4 *)0x0 && (iVar9 < iVar14)); iVar9 = iVar9 + 1) {
    puVar4 = (undefined4 *)*puVar4;
  }
  uVar12 = *(uint *)(local_10 + 0x20);
  if (in_EAX != 0) {
    *(uint *)(in_EAX + 0x1c) = uVar12;
  }
  if (uVar12 == 0) {
    uVar12 = 0;
  }
  else {
    uVar12 = DAT_006f227c % uVar12;
    uVar11 = DAT_006f227c ^ 0x1d872b41;
    uVar8 = uVar11 >> 5 ^ uVar11;
    DAT_006f227c = uVar8 << 0x1b ^ uVar8 ^ uVar11;
  }
  iVar14 = *(int *)(local_10 + 0x128 + uVar12 * 4);
  if (in_EAX != 0) {
    *(uint *)(in_EAX + 0x38) = uVar12;
  }
  puVar5 = DAT_00744264;
  for (iVar9 = 0; (puVar5 != (undefined4 *)0x0 && (iVar9 < iVar14)); iVar9 = iVar9 + 1) {
    puVar5 = (undefined4 *)*puVar5;
  }
  puVar10 = _malloc(0x28);
  if (puVar10 == (undefined4 *)0x0) {
    puVar10 = (undefined4 *)0x0;
  }
  else {
    iVar14 = 0;
    puVar13 = DAT_0074423c;
    if ((undefined4 **)DAT_0074423c != &DAT_0074423c) {
      do {
        if (puVar13[2] == param_1) goto LAB_0051ac24;
        puVar13 = (undefined4 *)*puVar13;
        iVar14 = iVar14 + 1;
      } while ((undefined4 **)puVar13 != &DAT_0074423c);
    }
    iVar14 = -1;
LAB_0051ac24:
    puVar13 = DAT_0074423c;
    for (iVar9 = 0; (puVar13 != (undefined4 *)0x0 && (iVar9 < iVar14)); iVar9 = iVar9 + 1) {
      puVar13 = (undefined4 *)*puVar13;
    }
    puVar10[3] = puVar13;
    puVar10[4] = local_18;
    puVar10[5] = local_14;
    puVar10[8] = puVar5;
    *puVar10 = &PTR_FUN_006c0130;
    puVar10[6] = puVar4;
    puVar10[7] = local_c;
    puVar10[9] = local_10;
  }
  if ((int *****)local_8 != &local_8) {
    do {
      ppppiVar2 = (int ****)*local_8;
      ppppiVar3 = (int ****)local_8[1];
      *ppppiVar3 = (int ***)ppppiVar2;
      ppppiVar2[1] = (int ***)ppppiVar3;
      _free(local_8);
    } while ((int *****)local_8 != &local_8);
  }
  return puVar10;
}


// ==== 0x51acb0 FUN_0051acb0

undefined4 FUN_0051acb0(void)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int unaff_ESI;
  
  pcVar4 = "MAGAZINE_TASK_16";
  iVar3 = -1;
  uVar2 = 0x4d;
  do {
    iVar3 = iVar3 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  if (unaff_ESI != iVar3) {
    pcVar4 = "MAGAZINE_TASK_15";
    iVar3 = -1;
    uVar2 = 0x4d;
    do {
      iVar3 = iVar3 * 0x21 + uVar2;
      pbVar1 = (byte *)(pcVar4 + 1);
      uVar2 = (uint)*pbVar1;
      pcVar4 = pcVar4 + 1;
    } while (*pbVar1 != 0);
    if (unaff_ESI != iVar3) {
      pcVar4 = "MAGAZINE_TASK_14";
      iVar3 = -1;
      uVar2 = 0x4d;
      do {
        iVar3 = iVar3 * 0x21 + uVar2;
        pbVar1 = (byte *)(pcVar4 + 1);
        uVar2 = (uint)*pbVar1;
        pcVar4 = pcVar4 + 1;
      } while (*pbVar1 != 0);
      if (unaff_ESI != iVar3) {
        iVar3 = bStringHash();
        if (unaff_ESI != iVar3) {
          return 0;
        }
      }
    }
  }
  return 1;
}


// ==== 0x51ad30 Career::AnnounceReward

/* [canon] canon low (ghidra+capstone) docs/re/canon.md */

void Career__AnnounceReward(undefined4 param_1,undefined1 *param_2)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  undefined1 local_730 [1564];
  uint local_114;
  char local_90;
  
  *param_2 = 1;
  RideInfo__Init();
  cVar3 = FUN_0051acb0();
  if (cVar3 == '\0') {
    puVar6 = &DAT_0075eef8;
    puVar5 = (undefined4 *)(param_2 + 4);
    for (iVar4 = 0xce; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar5 = puVar5 + 1;
    }
    FECarConfig__BuildRide(param_2 + 4,1,local_730);
  }
  else {
    iVar4 = FUN_00439130();
    RideInfo__operator_(local_730,*(undefined4 *)(iVar4 + 0x10));
    FECarConfig__FillFromRide(param_2 + 4,local_730);
  }
  uVar1 = local_114;
  puVar6 = DAT_0073ad40;
  uVar2 = local_114;
  if ((local_114 != 0) && (*(char *)(local_114 + 0x11) == '\x03')) {
    puVar5 = (undefined4 *)NullUpdate_ret();
    for (; uVar2 = local_114, puVar6 != puVar5; puVar6 = (undefined4 *)*puVar6) {
      uVar8 = puVar6[3];
      uVar7 = puVar6[4] * 0x30 + uVar8;
      for (; uVar8 < uVar7; uVar8 = uVar8 + 0x30) {
        if (*(char *)(uVar8 + 0x10) == 't') goto joined_r0x0051adf9;
      }
    }
    uVar8 = 0;
joined_r0x0051adf9:
    do {
      local_114 = uVar8;
      if (local_114 == 0) break;
      if ((*(byte *)(local_114 + 0x11) < 3) &&
         (*(char *)(local_114 + 0x12) == *(char *)(uVar1 + 0x12))) {
        local_90 = local_90 + '\x01';
        RideInfo__UpdatePartsEnabled(local_730);
        FECarConfig__FillFromRide(param_2 + 4,local_730);
        uVar2 = local_114;
        break;
      }
      uVar8 = CarPartDatabase__GetCarPart(0,0x74,0,local_114,0xffffffff);
      local_114 = uVar2;
      uVar2 = local_114;
    } while( true );
  }
  local_114 = uVar2;
  puVar6 = (undefined4 *)FUN_0051a8d0(param_1);
  if (puVar6 != (undefined4 *)0x0) {
    FUN_005a0bd0(puVar6);
    (**(code **)*puVar6)(1);
  }
  return;
}


// ==== 0x51ae90 FUN_0051ae90

void __fastcall FUN_0051ae90(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_00744ab0)[iVar1 * 2] == param_1) {
      DAT_0073576c = &DAT_007602a0 + *(int *)(&DAT_00744ab4 + iVar1 * 8) * 0x454;
      return;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x1b);
  DAT_0073576c = &DAT_007602a0;
  return;
}


// ==== 0x51aed0 FUN_0051aed0

void FUN_0051aed0(void)

{
  byte *pbVar1;
  bool bVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  
  if (DAT_00767798 == '\0') {
    bVar2 = true;
    piVar3 = &DAT_0075f1d8;
LAB_0051aee0:
    if ((int)piVar3 < 0x75f204) goto code_r0x0051aee7;
    if (!bVar2) goto LAB_0051af43;
    pcVar7 = "MAGAZINE_TASK_1";
    iVar6 = -1;
    uVar4 = 0x4d;
    do {
      iVar6 = iVar6 * 0x21 + uVar4;
      pbVar1 = (byte *)(pcVar7 + 1);
      uVar4 = (uint)*pbVar1;
      pcVar7 = pcVar7 + 1;
    } while (*pbVar1 != 0);
    iVar5 = 0;
    do {
      if ((&DAT_00744ab0)[iVar5 * 2] == iVar6) {
        iVar6 = *(int *)(&DAT_00744ab4 + iVar5 * 8);
        goto LAB_0051af36;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x1b);
    iVar6 = 0;
LAB_0051af36:
    (&DAT_007602a1)[iVar6 * 0x454] = 1;
  }
LAB_0051af43:
  if (DAT_00767799 != '\0') {
LAB_0051afc0:
    if (DAT_0076779a == '\0') {
      bVar2 = true;
      piVar3 = &DAT_0075f1d8;
      while ((int)piVar3 < 0x75f204) {
        if (((piVar3 != (int *)&DAT_0075f200) && (piVar3 != (int *)&DAT_0075f1fc)) && (*piVar3 < 3))
        {
          bVar2 = false;
        }
        piVar3 = piVar3 + 1;
        if (!bVar2) {
          return;
        }
      }
      if (bVar2) {
        pcVar7 = "MAGAZINE_TASK_1";
        iVar6 = -1;
        uVar4 = 0x4d;
        do {
          iVar6 = iVar6 * 0x21 + uVar4;
          pbVar1 = (byte *)(pcVar7 + 1);
          uVar4 = (uint)*pbVar1;
          pcVar7 = pcVar7 + 1;
        } while (*pbVar1 != 0);
        iVar5 = 0;
        do {
          if ((&DAT_00744ab0)[iVar5 * 2] == iVar6) {
            (&DAT_00760b49)[*(int *)(&DAT_00744ab4 + iVar5 * 8) * 0x454] = 1;
            return;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < 0x1b);
        DAT_00760b49 = 1;
      }
    }
    return;
  }
  bVar2 = true;
  piVar3 = &DAT_0075f1d8;
  while ((int)piVar3 < 0x75f204) {
    if (((piVar3 != (int *)&DAT_0075f200) && (piVar3 != (int *)&DAT_0075f1fc)) && (*piVar3 < 2)) {
      bVar2 = false;
    }
    piVar3 = piVar3 + 1;
    if (!bVar2) goto LAB_0051afc0;
  }
  if (!bVar2) goto LAB_0051afc0;
  pcVar7 = "MAGAZINE_TASK_1";
  iVar6 = -1;
  uVar4 = 0x4d;
  do {
    iVar6 = iVar6 * 0x21 + uVar4;
    pbVar1 = (byte *)(pcVar7 + 1);
    uVar4 = (uint)*pbVar1;
    pcVar7 = pcVar7 + 1;
  } while (*pbVar1 != 0);
  iVar5 = 0;
  do {
    if ((&DAT_00744ab0)[iVar5 * 2] == iVar6) {
      iVar6 = *(int *)(&DAT_00744ab4 + iVar5 * 8);
      goto LAB_0051afb3;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x1b);
  iVar6 = 0;
LAB_0051afb3:
  (&DAT_007606f5)[iVar6 * 0x454] = 1;
  goto LAB_0051afc0;
code_r0x0051aee7:
  if (((piVar3 != (int *)&DAT_0075f200) && (piVar3 != (int *)&DAT_0075f1fc)) && (*piVar3 < 1)) {
    bVar2 = false;
  }
  piVar3 = piVar3 + 1;
  if (!bVar2) goto LAB_0051af43;
  goto LAB_0051aee0;
}


// ==== 0x51b060 FUN_0051b060

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0051b060(void)

{
  byte *pbVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  char *pcVar7;
  byte bVar8;
  float10 fVar9;
  byte local_73e;
  byte local_73d;
  byte local_73c;
  byte local_73b;
  byte local_73a;
  byte local_739;
  byte local_738;
  byte local_737;
  byte local_736;
  byte local_735;
  byte local_734;
  byte local_733;
  byte local_732;
  byte local_731;
  undefined1 local_730 [1104];
  int local_2e0;
  int local_2dc;
  int local_2cc;
  int local_2c8;
  int local_2c4;
  int local_2bc;
  int local_2b8;
  int local_2b0;
  int local_2ac;
  int local_2a8;
  int local_2a0;
  int local_26c;
  int local_268;
  int local_264;
  int local_260;
  int local_25c;
  int local_1f8;
  int local_1f4;
  int local_1f0;
  int local_1ec;
  int local_1e8;
  int local_1e4;
  int local_1e0;
  int local_1dc;
  int local_1d8 [16];
  int local_198 [32];
  int local_118;
  int local_114;
  
  RideInfo__Init();
  FECarConfig__BuildRide(&DAT_0075eef8,0,local_730);
  if (local_2e0 == 0) {
    local_73d = 0;
  }
  else {
    local_73d = *(byte *)(local_2e0 + 0x11);
  }
  if (local_2dc == 0) {
    local_73c = 0;
  }
  else {
    local_73c = *(byte *)(local_2dc + 0x11);
  }
  if (local_2bc == 0) {
    local_73b = 0;
  }
  else {
    local_73b = *(byte *)(local_2bc + 0x11);
  }
  if (local_2b8 == 0) {
    local_739 = 0;
  }
  else {
    local_739 = *(byte *)(local_2b8 + 0x11);
  }
  if (local_2c4 == 0) {
    local_738 = 0;
  }
  else {
    local_738 = *(byte *)(local_2c4 + 0x11);
  }
  if (local_2b0 == 0) {
    local_732 = 0;
  }
  else {
    local_732 = *(byte *)(local_2b0 + 0x11);
  }
  if (local_2ac == 0) {
    local_731 = 0;
  }
  else {
    local_731 = *(byte *)(local_2ac + 0x11);
  }
  if (local_2a0 == 0) {
    local_737 = 0;
  }
  else {
    local_737 = *(byte *)(local_2a0 + 0x11);
  }
  bVar8 = 0;
  if (local_1f8 != 0) {
    bVar8 = 3;
  }
  if (local_1f4 != 0) {
    bVar8 = 3;
  }
  if (local_1f0 != 0) {
    bVar8 = 3;
  }
  if (local_1ec != 0) {
    bVar8 = 3;
  }
  if (local_1e8 != 0) {
    bVar8 = 3;
  }
  if (local_1e4 != 0) {
    bVar8 = 3;
  }
  if (local_1e0 != 0) {
    bVar8 = 3;
  }
  if (local_1dc == 0) {
    if (bVar8 == 0) {
      piVar2 = local_198 + 1;
      iVar6 = 4;
      do {
        if (piVar2[-1] != 0) {
          bVar8 = 2;
        }
        if (*piVar2 != 0) {
          bVar8 = 2;
        }
        if (piVar2[1] != 0) {
          bVar8 = 2;
        }
        if (piVar2[2] != 0) {
          bVar8 = 2;
        }
        if (piVar2[3] != 0) {
          bVar8 = 2;
        }
        if (piVar2[4] != 0) {
          bVar8 = 2;
        }
        if (piVar2[5] != 0) {
          bVar8 = 2;
        }
        if (piVar2[6] != 0) {
          bVar8 = 2;
        }
        piVar2 = piVar2 + 8;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      if (bVar8 == 0) {
        piVar2 = local_1d8 + 1;
        iVar6 = 2;
        do {
          if (piVar2[-1] != 0) {
            bVar8 = 1;
          }
          if (*piVar2 != 0) {
            bVar8 = 1;
          }
          if (piVar2[1] != 0) {
            bVar8 = 1;
          }
          if (piVar2[2] != 0) {
            bVar8 = 1;
          }
          if (piVar2[3] != 0) {
            bVar8 = 1;
          }
          if (piVar2[4] != 0) {
            bVar8 = 1;
          }
          if (piVar2[5] != 0) {
            bVar8 = 1;
          }
          if (piVar2[6] != 0) {
            bVar8 = 1;
          }
          piVar2 = piVar2 + 8;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
    }
  }
  else {
    bVar8 = 3;
  }
  local_73e = 0;
  if ((local_268 != 0) && (*(byte *)(local_268 + 0x11) != 0)) {
    local_73e = *(byte *)(local_268 + 0x11);
  }
  if ((local_264 != 0) && (local_73e < *(byte *)(local_264 + 0x11))) {
    local_73e = *(byte *)(local_264 + 0x11);
  }
  if ((local_260 != 0) && (local_73e < *(byte *)(local_260 + 0x11))) {
    local_73e = *(byte *)(local_260 + 0x11);
  }
  if ((local_25c != 0) && (local_73e < *(byte *)(local_25c + 0x11))) {
    local_73e = *(byte *)(local_25c + 0x11);
  }
  if (local_2c8 == 0) {
    local_735 = 0;
  }
  else {
    local_735 = *(byte *)(local_2c8 + 0x11);
  }
  if (local_118 == 0) {
    local_73a = 0;
  }
  else {
    local_73a = *(byte *)(local_118 + 0x11);
  }
  if (local_114 == 0) {
    local_736 = 0;
  }
  else {
    local_736 = *(byte *)(local_114 + 0x11);
  }
  if (local_2a8 == 0) {
    local_734 = 0;
  }
  else {
    local_734 = *(byte *)(local_2a8 + 0x11);
  }
  if (local_2cc == 0) {
    cVar5 = '\0';
  }
  else {
    cVar5 = *(char *)(local_2cc + 0x11);
  }
  if (local_26c == 0) {
    local_733 = 0;
  }
  else {
    local_733 = *(byte *)(local_26c + 0x11);
  }
  if (cVar5 == '\x04') {
    local_73d = 4;
    local_73c = 4;
    local_73b = 4;
  }
  if ((DAT_0076779b == '\0') &&
     (fVar9 = (float10)CalculateRideReputationPoints(), (float10)_K_ONE <= fVar9)) {
    pcVar7 = "MAGAZINE_TASK_1";
    iVar6 = -1;
    uVar3 = 0x4d;
    do {
      iVar6 = iVar6 * 0x21 + uVar3;
      pbVar1 = (byte *)(pcVar7 + 1);
      uVar3 = (uint)*pbVar1;
      pcVar7 = pcVar7 + 1;
    } while (*pbVar1 != 0);
    iVar4 = 0;
    do {
      if ((&DAT_00744ab0)[iVar4 * 2] == iVar6) {
        iVar6 = *(int *)(&DAT_00744ab4 + iVar4 * 8);
        goto LAB_0051b3d7;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x1b);
    iVar6 = 0;
LAB_0051b3d7:
    (&DAT_00760f9d)[iVar6 * 0x454] = 1;
  }
  if ((((((DAT_0076779c == '\0') && (local_73d != 0)) && (local_73c != 0)) &&
       ((local_73b != 0 && (local_739 != 0)))) && (local_738 != 0)) &&
     (((local_737 != 0 && (bVar8 != 0)) &&
      ((local_73e != 0 && ((local_73a != 0 && (local_736 != 0)))))))) {
    pcVar7 = "MAGAZINE_TASK_1";
    iVar6 = -1;
    uVar3 = 0x4d;
    do {
      iVar6 = iVar6 * 0x21 + uVar3;
      pbVar1 = (byte *)(pcVar7 + 1);
      uVar3 = (uint)*pbVar1;
      pcVar7 = pcVar7 + 1;
    } while (*pbVar1 != 0);
    iVar4 = 0;
    do {
      if ((&DAT_00744ab0)[iVar4 * 2] == iVar6) {
        iVar6 = *(int *)(&DAT_00744ab4 + iVar4 * 8);
        goto LAB_0051b477;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x1b);
    iVar6 = 0;
LAB_0051b477:
    (&DAT_007613f1)[iVar6 * 0x454] = 1;
  }
  if (((((((DAT_0076779d == '\0') && (1 < local_73d)) && (1 < local_73c)) &&
        ((1 < local_73b && (1 < local_739)))) &&
       ((1 < local_738 && ((1 < local_737 && (1 < bVar8)))))) && (1 < local_73e)) &&
     ((((1 < local_735 && (1 < local_73a)) && (1 < local_736)) &&
      ((1 < local_734 && (1 < local_733)))))) {
    pcVar7 = "MAGAZINE_TASK_1";
    iVar6 = -1;
    uVar3 = 0x4d;
    do {
      iVar6 = iVar6 * 0x21 + uVar3;
      pbVar1 = (byte *)(pcVar7 + 1);
      uVar3 = (uint)*pbVar1;
      pcVar7 = pcVar7 + 1;
    } while (*pbVar1 != 0);
    iVar4 = 0;
    do {
      if ((&DAT_00744ab0)[iVar4 * 2] == iVar6) {
        iVar6 = *(int *)(&DAT_00744ab4 + iVar4 * 8);
        goto LAB_0051b535;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x1b);
    iVar6 = 0;
LAB_0051b535:
    (&DAT_00761845)[iVar6 * 0x454] = 1;
  }
  if (((((DAT_0076779e == '\0') && (2 < local_73d)) &&
       ((2 < local_73c &&
        ((((2 < local_73b && (2 < local_739)) && (2 < local_732)) &&
         ((2 < local_731 && (2 < local_737)))))))) && ((2 < bVar8 || (2 < local_738)))) &&
     (((2 < local_73e && (2 < local_735)) &&
      ((2 < local_73a && (((2 < local_736 && (2 < local_734)) && (2 < local_733)))))))) {
    pcVar7 = "MAGAZINE_TASK_1";
    iVar6 = -1;
    uVar3 = 0x4d;
    do {
      iVar6 = iVar6 * 0x21 + uVar3;
      pbVar1 = (byte *)(pcVar7 + 1);
      uVar3 = (uint)*pbVar1;
      pcVar7 = pcVar7 + 1;
    } while (*pbVar1 != 0);
    iVar4 = 0;
    do {
      if ((&DAT_00744ab0)[iVar4 * 2] == iVar6) {
        iVar6 = *(int *)(&DAT_00744ab4 + iVar4 * 8);
        goto LAB_0051b607;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x1b);
    iVar6 = 0;
LAB_0051b607:
    (&DAT_00761c99)[iVar6 * 0x454] = 1;
  }
  if ((((DAT_0076779f == '\0') && (3 < local_738)) &&
      ((3 < local_737 && ((3 < local_739 && (3 < local_73e)))))) &&
     ((((2 < local_73d && (((2 < local_73c && (2 < local_73b)) && (local_732 == 3)))) &&
       ((local_731 == 3 && (local_735 == 3)))) &&
      (((local_73a == 3 && ((local_736 == 3 && (local_734 == 3)))) && (local_733 == 3)))))) {
    pcVar7 = "MAGAZINE_TASK_1";
    iVar6 = -1;
    uVar3 = 0x4d;
    do {
      iVar6 = iVar6 * 0x21 + uVar3;
      pbVar1 = (byte *)(pcVar7 + 1);
      uVar3 = (uint)*pbVar1;
      pcVar7 = pcVar7 + 1;
    } while (*pbVar1 != 0);
    iVar4 = 0;
    do {
      if ((&DAT_00744ab0)[iVar4 * 2] == iVar6) {
        (&DAT_007620ed)[*(int *)(&DAT_00744ab4 + iVar4 * 8) * 0x454] = 1;
        return;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x1b);
    DAT_007620ed = 1;
  }
  return;
}


// ==== 0x51b720 FUN_0051b720

undefined4 FUN_0051b720(void)

{
  byte *pbVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  
  cVar2 = FUN_0043a2e0();
  if ((cVar2 == '\0') || (cVar2 = Obj_GetByte19(), cVar2 == '\0')) {
    return 0;
  }
  FUN_00647b70();
  uVar8 = 0;
  cVar2 = FUN_00438a40(0);
  uVar3 = FUN_0043d8c0((int)cVar2,uVar8);
  uVar8 = 0;
  if ((499 < uVar3) && (DAT_007677a4 == '\0')) {
    pcVar7 = "MAGAZINE_TASK_1";
    uVar4 = 0x4d;
    iVar6 = -1;
    do {
      iVar6 = iVar6 * 0x21 + uVar4;
      pbVar1 = (byte *)(pcVar7 + 1);
      uVar4 = (uint)*pbVar1;
      pcVar7 = pcVar7 + 1;
    } while (*pbVar1 != 0);
    iVar5 = 0;
    do {
      if ((&DAT_00744ab0)[iVar5 * 2] == iVar6) {
        iVar6 = *(int *)(&DAT_00744ab4 + iVar5 * 8);
        goto LAB_0051b7b7;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x1b);
    iVar6 = 0;
LAB_0051b7b7:
    iVar6 = (iVar6 + 0xc) * 0x454;
    (&DAT_007602a1)[iVar6] = 1;
    uVar8 = FUN_004f42f0("MAGAZINE_TASK_%d",0xd,&DAT_007602a0 + iVar6);
    Career__AnnounceReward(uVar8);
    uVar8 = 1;
  }
  if ((999 < uVar3) && (DAT_007677a5 == '\0')) {
    pcVar7 = "MAGAZINE_TASK_1";
    iVar6 = -1;
    uVar4 = 0x4d;
    do {
      iVar6 = iVar6 * 0x21 + uVar4;
      pbVar1 = (byte *)(pcVar7 + 1);
      uVar4 = (uint)*pbVar1;
      pcVar7 = pcVar7 + 1;
    } while (*pbVar1 != 0);
    iVar5 = 0;
    do {
      if ((&DAT_00744ab0)[iVar5 * 2] == iVar6) {
        iVar6 = *(int *)(&DAT_00744ab4 + iVar5 * 8);
        goto LAB_0051b837;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x1b);
    iVar6 = 0;
LAB_0051b837:
    iVar6 = (iVar6 + 0xd) * 0x454;
    (&DAT_007602a1)[iVar6] = 1;
    uVar8 = FUN_004f42f0("MAGAZINE_TASK_%d",0xe,&DAT_007602a0 + iVar6);
    Career__AnnounceReward(uVar8);
    uVar8 = 1;
  }
  if ((0x9c3 < uVar3) && (DAT_007677a6 == '\0')) {
    FUN_005a0b40(&DAT_0075eef8);
    uVar8 = 1;
  }
  if (uVar3 < 5000) {
    return uVar8;
  }
  if (DAT_007677a7 != '\0') {
    return uVar8;
  }
  FUN_005a0b40(&DAT_0075eef8);
  return 1;
}


// ==== 0x51b8d0 FUN_0051b8d0

void __thiscall FUN_0051b8d0(int param_1,float param_2,float param_3)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  if (param_2 < param_3) {
    if (0x4b0 < param_1) {
      pcVar5 = "MAGAZINE_TASK_1";
      iVar4 = -1;
      uVar2 = 0x4d;
      do {
        iVar4 = iVar4 * 0x21 + uVar2;
        pbVar1 = (byte *)(pcVar5 + 1);
        uVar2 = (uint)*pbVar1;
        pcVar5 = pcVar5 + 1;
      } while (*pbVar1 != 0);
      iVar3 = 0;
      do {
        if ((&DAT_00744ab0)[iVar3 * 2] == iVar4) {
          (&DAT_00762541)[*(int *)(&DAT_00744ab4 + iVar3 * 8) * 0x454] = 1;
          return;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x1b);
      DAT_00762541 = 1;
      return;
    }
    if (0x44c < param_1) {
      pcVar5 = "MAGAZINE_TASK_1";
      uVar2 = 0x4d;
      iVar4 = -1;
      do {
        iVar4 = iVar4 * 0x21 + uVar2;
        pbVar1 = (byte *)(pcVar5 + 1);
        uVar2 = (uint)*pbVar1;
        pcVar5 = pcVar5 + 1;
      } while (*pbVar1 != 0);
      iVar3 = 0;
      do {
        if ((&DAT_00744ab0)[iVar3 * 2] == iVar4) {
          (&DAT_0076323d)[*(int *)(&DAT_00744ab4 + iVar3 * 8) * 0x454] = 1;
          return;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x1b);
      DAT_0076323d = 1;
      return;
    }
    if (1000 < param_1) {
      pcVar5 = "MAGAZINE_TASK_1";
      iVar4 = -1;
      uVar2 = 0x4d;
      do {
        iVar4 = iVar4 * 0x21 + uVar2;
        pbVar1 = (byte *)(pcVar5 + 1);
        uVar2 = (uint)*pbVar1;
        pcVar5 = pcVar5 + 1;
      } while (*pbVar1 != 0);
      iVar3 = 0;
      do {
        if ((&DAT_00744ab0)[iVar3 * 2] == iVar4) {
          (&DAT_00762995)[*(int *)(&DAT_00744ab4 + iVar3 * 8) * 0x454] = 1;
          return;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x1b);
      DAT_00762995 = 1;
    }
  }
  return;
}


// ==== 0x51ba00 FUN_0051ba00

void __thiscall FUN_0051ba00(int param_1,int param_2,int param_3)

{
  byte *pbVar1;
  int in_EAX;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  if (((0 < param_1) && ((int)(param_3 + (param_3 >> 0x1f & 3U)) >> 2 < in_EAX / param_1)) &&
     (0x514 < param_2)) {
    pcVar5 = "MAGAZINE_TASK_1";
    iVar4 = -1;
    uVar2 = 0x4d;
    do {
      iVar4 = iVar4 * 0x21 + uVar2;
      pbVar1 = (byte *)(pcVar5 + 1);
      uVar2 = (uint)*pbVar1;
      pcVar5 = pcVar5 + 1;
    } while (*pbVar1 != 0);
    iVar3 = 0;
    do {
      if ((&DAT_00744ab0)[iVar3 * 2] == iVar4) {
        (&DAT_00762de9)[*(int *)(&DAT_00744ab4 + iVar3 * 8) * 0x454] = 1;
        return;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x1b);
    DAT_00762de9 = 1;
  }
  return;
}


// ==== 0x51ba80 FUN_0051ba80

uint FUN_0051ba80(void)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = 0xb;
  pcVar1 = &DAT_0076323d;
  while ((*pcVar1 == '\0' || ((&DAT_0076777c)[iVar2] != '\0'))) {
    pcVar1 = pcVar1 + 0x454;
    iVar2 = iVar2 + 1;
    if (0x76777c < (int)pcVar1) {
      return (uint)pcVar1 & 0xffffff00;
    }
  }
  return CONCAT31((int3)((uint)pcVar1 >> 8),1);
}


// ==== 0x51bac0 FUN_0051bac0

void FUN_0051bac0(void)

{
  FUN_0051bc00();
  return;
}


// ==== 0x51bad0 FUN_0051bad0

void FUN_0051bad0(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_s_FRONTEND_MAGAZINE_TEXTURES_BIN_006f8860;
  iVar2 = StringList_Find(&DAT_00740420,PTR_s_FRONTEND_MAGAZINE_TEXTURES_BIN_006f8860);
  if (iVar2 == 0) {
    FUN_0053eed0(&DAT_00740420,puVar1,0,0,0);
    puVar1 = PTR_s_FRONTEND_MAGAZINE_TEXTURES_BIN_006f8860;
    iVar2 = ResourceFileList_IsLoadedByName
                      (&DAT_00740420,PTR_s_FRONTEND_MAGAZINE_TEXTURES_BIN_006f8860);
    while (iVar2 != 0) {
      ServiceResourceLoading();
      iVar2 = ResourceFileList_IsLoadedByName(&DAT_00740420,puVar1);
    }
    while (DAT_007360e8 != 0) {
      ServiceResourceLoading();
    }
  }
  return;
}


// ==== 0x51bb50 FUN_0051bb50

void FUN_0051bb50(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *in_EAX;
  int iVar3;
  
  if (in_EAX[1] != 0) {
    FUN_00546060();
  }
  if (in_EAX[2] != 0) {
    FUN_00546060();
  }
  if (in_EAX[3] != 0) {
    FUN_00546060();
  }
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  *in_EAX = 0;
  puVar2 = PTR_s_FRONTEND_MAGAZINE_TEXTURES_BIN_006f8860;
  iVar3 = ResourceFileList_IsLoadedByName
                    (&DAT_00740420,PTR_s_FRONTEND_MAGAZINE_TEXTURES_BIN_006f8860);
  puVar1 = puVar2;
  while (iVar3 != 0) {
    ServiceResourceLoading();
    iVar3 = ResourceFileList_IsLoadedByName(&DAT_00740420,puVar2);
    puVar1 = PTR_s_FRONTEND_MAGAZINE_TEXTURES_BIN_006f8860;
  }
  iVar3 = StringList_Find(&DAT_00740420,puVar1);
  if (iVar3 != 0) {
    ResourceFileList_Remove(puVar1,0,0);
    while (DAT_007360e8 != 0) {
      ServiceResourceLoading();
    }
  }
  return;
}


// ==== 0x51bc00 FUN_0051bc00

void FUN_0051bc00(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *unaff_EDI;
  
  uVar1 = unaff_EDI[1];
  if (((uVar1 != 0) || (unaff_EDI[2] != 0)) || (unaff_EDI[3] != 0)) {
    uVar3 = 1;
    if (uVar1 != 0) {
      iVar2 = Texture_FindByHash(uVar1,0,0);
      uVar3 = (uint)(iVar2 != 0);
    }
    if (unaff_EDI[2] != 0) {
      iVar2 = Texture_FindByHash(unaff_EDI[2],0,0);
      uVar3 = uVar3 & iVar2 != 0;
    }
    if (unaff_EDI[3] != 0) {
      iVar2 = Texture_FindByHash(unaff_EDI[3],0,0);
      uVar3 = uVar3 & iVar2 != 0;
    }
    *unaff_EDI = uVar3;
  }
  return;
}


// ==== 0x51bc80 FUN_0051bc80

void FUN_0051bc80(int param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined4 *unaff_ESI;
  
  iVar2 = param_2;
  FUN_0051bad0(unaff_ESI);
  if (in_EAX != 0) {
    iVar1 = Texture_FindByHash();
    if (iVar1 == 0) {
      in_EAX = 0;
    }
  }
  if (param_1 != 0) {
    iVar1 = Texture_FindByHash(param_1,0,1);
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  if (iVar2 != 0) {
    iVar1 = Texture_FindByHash(iVar2,0,1);
    if (iVar1 == 0) {
      iVar2 = 0;
    }
  }
  if (((in_EAX == 0) && (param_1 == 0)) && (iVar2 == 0)) {
    *unaff_ESI = 1;
    return;
  }
  unaff_ESI[1] = in_EAX;
  unaff_ESI[2] = param_1;
  unaff_ESI[3] = iVar2;
  if (in_EAX != 0) {
    param_2 = in_EAX;
    FUN_0053e9e0(&DAT_00740420,&param_2,1,FUN_0051bac0,unaff_ESI,0);
  }
  if (param_1 != 0) {
    param_2 = param_1;
    FUN_0053e9e0(&DAT_00740420,&param_2,1,FUN_0051bac0,unaff_ESI,0);
  }
  if (iVar2 != 0) {
    param_2 = iVar2;
    FUN_0053e9e0(&DAT_00740420,&param_2,1,FUN_0051bac0,unaff_ESI,0);
  }
  return;
}


// ==== 0x51bd70 CarDecalSlots::Loader

/* [canon] assets high (Hopper sub_51bd70 + Ghidra make FUN_0051bd70: H+G agree) docs/re/assets.md
    */

undefined4 CarDecalSlots__Loader(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*param_1 != 0x30240) {
    return 0;
  }
  iVar2 = param_1[2];
  param_1 = param_1 + 3;
  if (0 < iVar2) {
    do {
      *DAT_007449c4 = (int)param_1;
      piVar1 = param_1;
      param_1[1] = (int)DAT_007449c4;
      DAT_007449c4 = piVar1;
      *param_1 = (int)&DAT_007449c0;
      param_1 = param_1 + 7;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return 1;
}


// ==== 0x51bdc0 CarDecalSlots::Unloader

/* [canon] assets high (Hopper sub_51bdc0 + Ghidra make FUN_0051bdc0: H+G agree) docs/re/assets.md
    */

undefined4 CarDecalSlots__Unloader(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (*param_1 == 0x30240) {
    while ((int **)DAT_007449c0 != &DAT_007449c0) {
      iVar1 = *DAT_007449c0;
      piVar2 = (int *)DAT_007449c0[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
    }
    return 1;
  }
  return 0;
}


// ==== 0x51be00 FUN_0051be00

undefined1 FUN_0051be00(char param_1)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  int unaff_EDI;
  
  puVar1 = (undefined4 *)*in_EAX;
  puVar2 = (undefined4 *)NullUpdate_ret();
  while( true ) {
    if (puVar1 == puVar2) {
      return 0;
    }
    if (puVar1[2] == unaff_EDI) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  if (param_1 != '\0') {
    return *(undefined1 *)(puVar1 + 3);
  }
  return *(undefined1 *)((int)puVar1 + 0xd);
}


// ==== 0x51be40 FUN_0051be40

undefined1 FUN_0051be40(char param_1)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  int unaff_EDI;
  
  puVar1 = (undefined4 *)*in_EAX;
  puVar2 = (undefined4 *)NullUpdate_ret();
  while( true ) {
    if (puVar1 == puVar2) {
      return 0;
    }
    if (puVar1[2] == unaff_EDI) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  if (param_1 != '\0') {
    return *(undefined1 *)((int)puVar1 + 0xe);
  }
  return *(undefined1 *)((int)puVar1 + 0xf);
}


// ==== 0x51be80 GarageRimsBrandBrowser::_GarageRimsBrandBrowser

/* [canon] car med (ghidra+hopper) docs/re/tuning.md */

undefined4 __fastcall GarageRimsBrandBrowser___GarageRimsBrandBrowser(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_00744368;
  while (((piVar1[-1] != param_1 && (*piVar1 != param_1)) && (piVar1[1] != param_1))) {
    piVar1 = piVar1 + 6;
    iVar2 = iVar2 + 1;
    if (0x7449c7 < (int)piVar1) {
      return 0xffffffff;
    }
  }
  return *(undefined4 *)(iVar2 * 0x18 + 0x744360);
}


// ==== 0x51beb0 FUN_0051beb0

bool FUN_0051beb0(void)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int unaff_ESI;
  
  uVar2 = 0x41;
  iVar3 = -1;
  pcVar4 = "ALPINE";
  do {
    iVar3 = iVar3 * 0x21 + uVar2;
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar2 = (uint)*pbVar1;
    pcVar4 = pcVar4 + 1;
  } while (*pbVar1 != 0);
  if (unaff_ESI != iVar3) {
    uVar2 = 0x41;
    iVar3 = -1;
    pcVar4 = "AUDIOBAHN";
    do {
      iVar3 = iVar3 * 0x21 + uVar2;
      pbVar1 = (byte *)(pcVar4 + 1);
      uVar2 = (uint)*pbVar1;
      pcVar4 = pcVar4 + 1;
    } while (*pbVar1 != 0);
    if (unaff_ESI != iVar3) {
      uVar2 = 0x4b;
      iVar3 = -1;
      pcVar4 = "KENWOOD";
      do {
        iVar3 = iVar3 * 0x21 + uVar2;
        pbVar1 = (byte *)(pcVar4 + 1);
        uVar2 = (uint)*pbVar1;
        pcVar4 = pcVar4 + 1;
      } while (*pbVar1 != 0);
      if ((((((unaff_ESI != iVar3) && (iVar3 = bStringHash(), unaff_ESI != iVar3)) &&
            (iVar3 = bStringHash(), unaff_ESI != iVar3)) &&
           ((iVar3 = bStringHash(), unaff_ESI != iVar3 &&
            (iVar3 = bStringHash(), unaff_ESI != iVar3)))) &&
          ((iVar3 = bStringHash(), unaff_ESI != iVar3 &&
           ((iVar3 = bStringHash(), unaff_ESI != iVar3 &&
            (iVar3 = bStringHash(), unaff_ESI != iVar3)))))) &&
         (iVar3 = bStringHash(), unaff_ESI != iVar3)) {
        iVar3 = GarageRimsBrandBrowser___GarageRimsBrandBrowser();
        if (iVar3 != -1) {
          return ((&DAT_00760158)[iVar3 * 4] & 3) != 0;
        }
        return false;
      }
    }
  }
  return true;
}


// ==== 0x51bfd0 FUN_0051bfd0

void FUN_0051bfd0(void)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006bf634;
  puVar1 = in_EAX + 1;
  *puVar1 = puVar1;
  in_EAX[2] = puVar1;
  puVar1 = in_EAX + 3;
  *puVar1 = puVar1;
  in_EAX[4] = puVar1;
  puVar1 = in_EAX + 5;
  *puVar1 = puVar1;
  in_EAX[6] = puVar1;
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
  return;
}


// ==== 0x51c020 FUN_0051c020

void __fastcall FUN_0051c020(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  piVar4 = param_1 + 0xf;
  *param_1 = &PTR_FUN_006bf634;
  piVar1 = (int *)*piVar4;
  while (piVar1 != piVar4) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(piVar1);
    piVar1 = (int *)*piVar4;
  }
  piVar4 = (int *)param_1[0xd];
  while (piVar4 != param_1 + 0xd) {
    iVar2 = *piVar4;
    piVar1 = (int *)piVar4[1];
    *piVar1 = iVar2;
    *(int **)(iVar2 + 4) = piVar1;
    _free(piVar4);
    piVar4 = (int *)param_1[0xd];
  }
  piVar4 = (int *)param_1[0xb];
  while (piVar4 != param_1 + 0xb) {
    iVar2 = *piVar4;
    piVar1 = (int *)piVar4[1];
    *piVar1 = iVar2;
    *(int **)(iVar2 + 4) = piVar1;
    _free(piVar4);
    piVar4 = (int *)param_1[0xb];
  }
  piVar4 = (int *)param_1[9];
  while (piVar4 != param_1 + 9) {
    iVar2 = *piVar4;
    piVar1 = (int *)piVar4[1];
    *piVar1 = iVar2;
    *(int **)(iVar2 + 4) = piVar1;
    _free(piVar4);
    piVar4 = (int *)param_1[9];
  }
  piVar4 = (int *)param_1[7];
  while (piVar4 != param_1 + 7) {
    iVar2 = *piVar4;
    piVar1 = (int *)piVar4[1];
    *piVar1 = iVar2;
    *(int **)(iVar2 + 4) = piVar1;
    _free(piVar4);
    piVar4 = (int *)param_1[7];
  }
  piVar4 = (int *)param_1[5];
  while (piVar4 != param_1 + 5) {
    iVar2 = *piVar4;
    piVar1 = (int *)piVar4[1];
    *piVar1 = iVar2;
    *(int **)(iVar2 + 4) = piVar1;
    _free(piVar4);
    piVar4 = (int *)param_1[5];
  }
  piVar4 = (int *)param_1[3];
  while (piVar4 != param_1 + 3) {
    iVar2 = *piVar4;
    piVar1 = (int *)piVar4[1];
    *piVar1 = iVar2;
    *(int **)(iVar2 + 4) = piVar1;
    _free(piVar4);
    piVar4 = (int *)param_1[3];
  }
  piVar4 = (int *)param_1[1];
  while (piVar4 != param_1 + 1) {
    iVar2 = *piVar4;
    piVar1 = (int *)piVar4[1];
    *piVar1 = iVar2;
    *(int **)(iVar2 + 4) = piVar1;
    _free(piVar4);
    piVar4 = (int *)param_1[1];
  }
  return;
}


// ==== 0x51c160 FUN_0051c160

void * __thiscall FUN_0051c160(void *param_1,byte param_2)

{
  FUN_0051c020();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x51c180 MagazineTables::Loader

/* [canon] assets high (Hopper sub_51c180 + Ghidra make FUN_0051c180: H+G agree) docs/re/assets.md
    */

undefined4 MagazineTables__Loader(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  if (*param_1 != 0x30230) {
    return 0;
  }
  iVar4 = param_1[3];
  iVar6 = param_1[5];
  iVar7 = param_1[6];
  iVar5 = param_1[4];
  iVar8 = param_1[7];
  iVar9 = param_1[8];
  iVar10 = param_1[9];
  piVar3 = param_1 + 10;
  piVar1 = DAT_00744240;
  for (iVar11 = param_1[2]; DAT_00744240 = piVar1, piVar2 = DAT_00744248, iVar11 != 0;
      iVar11 = iVar11 + -1) {
    *piVar1 = (int)piVar3;
    DAT_00744240 = piVar3;
    piVar3[1] = (int)piVar1;
    *piVar3 = (int)&DAT_0074423c;
    piVar3 = piVar3 + 3;
    piVar1 = DAT_00744240;
  }
  for (; DAT_00744248 = piVar2, piVar1 = DAT_00744250, iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar2 = (int)piVar3;
    DAT_00744248 = piVar3;
    piVar3[1] = (int)piVar2;
    *piVar3 = (int)&DAT_00744244;
    piVar3 = piVar3 + 4;
    piVar2 = DAT_00744248;
  }
  for (; DAT_00744250 = piVar1, piVar2 = DAT_00744258, iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar1 = (int)piVar3;
    DAT_00744250 = piVar3;
    piVar3[1] = (int)piVar1;
    *piVar3 = (int)&DAT_0074424c;
    piVar3 = piVar3 + 0x2a;
    piVar1 = DAT_00744250;
  }
  for (; DAT_00744258 = piVar2, piVar1 = DAT_00744260, iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar2 = (int)piVar3;
    DAT_00744258 = piVar3;
    piVar3[1] = (int)piVar2;
    *piVar3 = (int)&DAT_00744254;
    piVar3 = piVar3 + 4;
    piVar2 = DAT_00744258;
  }
  for (; DAT_00744260 = piVar1, piVar2 = DAT_00744268, iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar1 = (int)piVar3;
    DAT_00744260 = piVar3;
    piVar3[1] = (int)piVar1;
    *piVar3 = (int)&DAT_0074425c;
    piVar3 = piVar3 + 5;
    piVar1 = DAT_00744260;
  }
  for (; DAT_00744268 = piVar2, piVar1 = DAT_00744270, iVar8 != 0; iVar8 = iVar8 + -1) {
    *piVar2 = (int)piVar3;
    DAT_00744268 = piVar3;
    piVar3[1] = (int)piVar2;
    *piVar3 = (int)&DAT_00744264;
    piVar3 = piVar3 + 0xe;
    piVar2 = DAT_00744268;
  }
  for (; DAT_00744270 = piVar1, piVar2 = DAT_00744278, iVar9 != 0; iVar9 = iVar9 + -1) {
    *piVar1 = (int)piVar3;
    DAT_00744270 = piVar3;
    piVar3[1] = (int)piVar1;
    *piVar3 = (int)&DAT_0074426c;
    piVar3 = piVar3 + 0x5a;
    piVar1 = DAT_00744270;
  }
  for (; iVar10 != 0; iVar10 = iVar10 + -1) {
    *piVar2 = (int)piVar3;
    DAT_00744278 = piVar3;
    piVar3[1] = (int)piVar2;
    *piVar3 = (int)&DAT_00744274;
    piVar3 = piVar3 + 0x14;
    piVar2 = DAT_00744278;
  }
  DAT_00744278 = piVar2;
  return 1;
}


// ==== 0x51c340 MagazineTables::Unloader

/* [canon] assets high (Hopper sub_51c340 + Ghidra make FUN_0051c340: H+G agree) docs/re/assets.md
    */

undefined4 MagazineTables__Unloader(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (*param_1 == 0x30230) {
    if ((int **)DAT_0074423c != &DAT_0074423c) {
      do {
        iVar1 = *DAT_0074423c;
        piVar2 = (int *)DAT_0074423c[1];
        *piVar2 = iVar1;
        *(int **)(iVar1 + 4) = piVar2;
      } while ((int **)DAT_0074423c != &DAT_0074423c);
    }
    while ((int **)DAT_00744244 != &DAT_00744244) {
      iVar1 = *DAT_00744244;
      piVar2 = (int *)DAT_00744244[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
    }
    DAT_00744244 = (int *)&DAT_00744244;
    while ((int **)DAT_0074424c != &DAT_0074424c) {
      iVar1 = *DAT_0074424c;
      piVar2 = (int *)DAT_0074424c[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
    }
    DAT_0074424c = (int *)&DAT_0074424c;
    while ((int **)DAT_00744254 != &DAT_00744254) {
      iVar1 = *DAT_00744254;
      piVar2 = (int *)DAT_00744254[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
    }
    DAT_00744254 = (int *)&DAT_00744254;
    while ((int **)DAT_0074425c != &DAT_0074425c) {
      iVar1 = *DAT_0074425c;
      piVar2 = (int *)DAT_0074425c[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
    }
    DAT_0074425c = (int *)&DAT_0074425c;
    if ((int **)DAT_00744264 != &DAT_00744264) {
      do {
        iVar1 = *DAT_00744264;
        piVar2 = (int *)DAT_00744264[1];
        *piVar2 = iVar1;
        *(int **)(iVar1 + 4) = piVar2;
      } while ((int **)DAT_00744264 != &DAT_00744264);
    }
    while ((int **)DAT_0074426c != &DAT_0074426c) {
      iVar1 = *DAT_0074426c;
      piVar2 = (int *)DAT_0074426c[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
    }
    DAT_0074426c = (int *)&DAT_0074426c;
    while ((int **)DAT_00744274 != &DAT_00744274) {
      iVar1 = *DAT_00744274;
      piVar2 = (int *)DAT_00744274[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
    }
    return 1;
  }
  return 0;
}


// ==== 0x51c480 FUN_0051c480

undefined4 *
FUN_0051c480(int param_1,int param_2,int *param_3,uint *param_4,int param_5,uint *param_6,
            uint param_7)

{
  int *in_EAX;
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  undefined4 *puVar9;
  
  puVar9 = (undefined4 *)0x0;
  iVar6 = 0;
  puVar1 = *(undefined4 **)(param_1 + 0x3c);
  do {
    if (puVar1 == (undefined4 *)(param_1 + 0x3c)) {
      if (puVar9 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
      break;
    }
    if ((puVar1[2] == param_2) && (puVar9 = puVar1, in_EAX != (int *)0x0)) {
      *in_EAX = iVar6;
    }
    puVar1 = (undefined4 *)*puVar1;
    iVar6 = iVar6 + 1;
  } while (puVar9 == (undefined4 *)0x0);
  iVar6 = 0;
  if (0 < (int)puVar9[3]) {
    piVar8 = puVar9 + 4;
    do {
      puVar1 = *(undefined4 **)(param_1 + 0x34);
      for (iVar2 = 0; (puVar1 != (undefined4 *)0x0 && (iVar2 < *piVar8)); iVar2 = iVar2 + 1) {
        puVar1 = (undefined4 *)*puVar1;
      }
      piVar3 = _malloc(0xc);
      piVar3[2] = puVar1[8] * puVar1[7] * puVar1[6] * puVar1[5] * puVar1[4];
      puVar1 = *(undefined4 **)(param_5 + 4);
      *puVar1 = piVar3;
      *(int **)(param_5 + 4) = piVar3;
      piVar3[1] = (int)puVar1;
      *piVar3 = param_5;
      iVar6 = iVar6 + 1;
      piVar8 = piVar8 + 1;
    } while (iVar6 < (int)puVar9[3]);
  }
  uVar7 = puVar9[3];
  if (param_6 != (uint *)0x0) {
    *param_6 = uVar7;
  }
  if (uVar7 == 1) {
    iVar6 = puVar9[4];
    if (param_4 != (uint *)0x0) {
      *param_4 = 0;
    }
  }
  else if (((int)param_7 < 1) || ((int)uVar7 <= (int)param_7)) {
    uVar5 = DAT_006f227c ^ 0x1d872b41;
    uVar7 = DAT_006f227c % uVar7;
    uVar4 = uVar5 >> 5 ^ uVar5;
    DAT_006f227c = uVar4 << 0x1b ^ uVar4 ^ uVar5;
    if (param_4 != (uint *)0x0) {
      *param_4 = uVar7;
    }
    iVar6 = puVar9[uVar7 + 4];
  }
  else {
    iVar6 = puVar9[param_7 + 4];
    if (param_4 != (uint *)0x0) {
      *param_4 = param_7;
    }
  }
  if (param_3 != (int *)0x0) {
    *param_3 = iVar6;
  }
  puVar1 = *(undefined4 **)(param_1 + 0x34);
  for (iVar2 = 0; (puVar1 != (undefined4 *)0x0 && (iVar2 < iVar6)); iVar2 = iVar2 + 1) {
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1;
}


// ==== 0x51c5d0 FUN_0051c5d0

void __fastcall FUN_0051c5d0(int param_1)

{
  int in_EAX;
  
  if (in_EAX < 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    return;
  }
  if (0x7fff < in_EAX) {
    in_EAX = 0x7fff;
  }
  *(int *)(param_1 + 8) = in_EAX;
  return;
}


// ==== 0x51c5f0 EAXSound::ReloadLanguageSpeechBank__called_by_ChangeLanguage_0x59fa20_

/* [canon] audio med (ghidra) docs/re/sound.md */

void EAXSound__ReloadLanguageSpeechBank__called_by_ChangeLanguage_0x59fa20_(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int unaff_EDI;
  
  if ((DAT_006f1ddc != 0) &&
     (*(int *)(*(int *)(unaff_EDI + 0x56c) * 0x1c + 0x1e8 + unaff_EDI) != -1)) {
    FUN_00522220(0xffffffff);
    FUN_0064c620();
    switch(param_1) {
    case 1:
      uVar2 = 5;
      break;
    case 2:
      uVar2 = 6;
      break;
    case 3:
      uVar2 = 7;
      break;
    case 4:
      uVar2 = 8;
      break;
    default:
      uVar2 = 4;
      break;
    case 9:
      uVar2 = 9;
    }
    EAXAemsManager__ResetLoadQueue(*(undefined4 *)(unaff_EDI + 0xb4));
    *(undefined4 *)(*(int *)(unaff_EDI + 0x56c) * 0x1c + 0x1f0 + unaff_EDI) = uVar2;
    DAT_0073568c = 0;
    DAT_00735690 = 0;
    EAXAemsManager__LoadAemsBank(0xffffffff,0,1,9);
    do {
      if (DAT_00735678 == 0) {
        piVar1 = &DAT_0072ce58;
        while (((*piVar1 != 1 && (*piVar1 != 2)) && (piVar1[-1] != 1))) {
          piVar1 = piVar1 + 3;
          if (0x72cfd7 < (int)piVar1) {
            *(undefined4 *)(unaff_EDI + 0x568) = uVar2;
            return;
          }
        }
      }
      FUN_005219c0(*(undefined4 *)(unaff_EDI + 0xb4));
      AsyncReadQueue__Pump();
    } while( true );
  }
  return;
}


// ==== 0x51c720 FUN_0051c720

void __fastcall FUN_0051c720(undefined4 param_1,int param_2,int param_3)

{
  int *piVar1;
  
  if ((DAT_006f1dd8 != 0) && (*(int *)(param_3 + 0x104) != 0)) {
    piVar1 = *(int **)(*(int *)(param_3 + 0x104) + 0x14);
    if (param_2 == -1) {
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x98))(0,0xffffffff);
        return;
      }
    }
    else if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x98))(0,param_2);
    }
  }
  return;
}


// ==== 0x51c770 EAXSound::PlayUISoundFX

/* [canon] audio med (ghidra-canon+nfsug) docs/re/sound.md */

void __fastcall EAXSound__PlayUISoundFX(undefined4 param_1,int param_2)

{
  int in_EAX;
  
  if (DAT_006f1dd8 != 0) {
    if (param_2 < 0x12) {
      if (*(int **)(in_EAX + 0xc0) != (int *)0x0) {
        (**(code **)(**(int **)(in_EAX + 0xc0) + 0x14))(param_2);
        return;
      }
    }
    else if ((param_2 < 0x53) && (*(int **)(in_EAX + 0xbc) != (int *)0x0)) {
      (**(code **)(**(int **)(in_EAX + 0xbc) + 0x14))(param_2 + -0x12);
    }
  }
  return;
}


// ==== 0x51c7b0 EAXSound::GetNewSongInfo

/* [canon] audio med (ghidra-canon+nfsug) docs/re/sound.md */

void __fastcall EAXSound__GetNewSongInfo(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x104) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x104) + 0x2ac);
    if ((-1 < iVar1) && (iVar1 < 0x1a)) {
      *(undefined ***)(param_1 + 0xa8) = &PTR_s__Doomsday__006f4d08 + iVar1 * 4;
      return;
    }
    *(undefined4 *)(param_1 + 0xa8) = 0;
  }
  return;
}


// ==== 0x51c7f0 EAXSound::UpdateSongInfo

/* [canon] audio med (ghidra-canon+nfsug) docs/re/sound.md */

char EAXSound__UpdateSongInfo(void)

{
  int iVar1;
  char cVar2;
  int in_EAX;
  char cVar3;
  
  iVar1 = *(int *)(in_EAX + 0x104);
  if (iVar1 != 0) {
    cVar2 = (**(code **)(**(int **)(iVar1 + 0x24) + 0x80))(0);
    cVar3 = cVar2 != '\0';
    cVar2 = (**(code **)(**(int **)(iVar1 + 0x24) + 0x80))(1);
    if (cVar2 != '\0') {
      cVar3 = cVar3 + '\x01';
    }
    return cVar3;
  }
  return '\0';
}


// ==== 0x51c830 EAXSound::PlaySpeechStream

/* [canon] audio med (ghidra) docs/re/sound.md */

void __fastcall EAXSound__PlaySpeechStream(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int in_EAX;
  undefined *puVar3;
  
  iVar1 = *(int *)(in_EAX + 0x104);
  if (iVar1 != 0) {
    if (param_1 == 0x59) {
      puVar3 = (undefined *)0x0;
      if (((0 < param_3) && (-1 < param_2)) && (param_2 < 2)) {
        puVar3 = (&PTR_s_Fabolous_006f8728)[param_2 + param_3 * 2];
      }
      piVar2 = *(int **)(iVar1 + 0x24);
      if (puVar3 == (undefined *)0xffffffff) {
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 0x90))(0x59);
        }
      }
      else if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x98))(0x59,puVar3);
      }
    }
    else if (*(int **)(iVar1 + 0x24) != (int *)0x0) {
      (**(code **)(**(int **)(iVar1 + 0x24) + 0x90))(param_1);
    }
    if ((0.2 < *(float *)(*(int *)(DAT_007356a8 + 8) + 4)) && (DAT_007356ac != 0)) {
      EAXMix_SetupAllTypes(0xbf800000);
    }
  }
  return;
}


// ==== 0x51c8e0 EAXSound::EAXSound

/* [canon] audio high (ghidra-canon+nfsug) docs/re/sound.md */

undefined4 * __fastcall EAXSound__EAXSound(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  *param_2 = &PTR_FUN_006bf5a4;
  puVar1 = param_2 + 3;
  iVar2 = 4;
  do {
    *puVar1 = 0;
    *(undefined1 *)(puVar1 + 1) = 0;
    *(undefined1 *)((int)puVar1 + 5) = 0;
    puVar1 = puVar1 + 5;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = param_2 + 0x39;
  *puVar1 = puVar1;
  param_2[0x3a] = puVar1;
  param_2[0x3e] = 1;
  *(undefined1 *)(param_2 + 1) = 1;
  *(undefined1 *)(param_2 + 0x27) = 0;
  param_2[0x3b] = 0;
  param_2[0x31] = 0;
  param_2[0x32] = 0;
  param_2[0x33] = 0;
  param_2[0x34] = 0;
  param_2[0x35] = 0;
  param_2[0x36] = 0;
  param_2[0x37] = 0;
  param_2[0x38] = 0;
  param_2[0x41] = 0;
  param_2[0x3c] = 0;
  *(undefined1 *)(param_2 + 0x21) = 0;
  param_2[2] = 0;
  param_2[0x28] = 0;
  param_2[0x23] = 0;
  param_2[0x24] = 0;
  param_2[0x1f] = 0;
  param_2[0x1e] = 0;
  param_2[0x15b] = 0;
  param_2[0x29] = "SOUND";
  param_2[0x2a] = 0;
  puVar1 = &DAT_0072f568;
  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  *(undefined1 *)(param_2 + 0x1c) = 0;
  *(undefined1 *)((int)param_2 + 0x71) = 0;
  *(undefined1 *)((int)param_2 + 0x73) = 0;
  puVar1 = param_2 + 0x7a;
  iVar2 = 0x20;
  do {
    puVar1[1] = 0xffffffff;
    *puVar1 = 0xffffffff;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0xffffffff;
    puVar1 = puVar1 + 7;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_2[0x1a] = 0;
  param_2[0x1b] = 0;
  *(undefined1 *)(param_2 + 0x19) = 0;
  param_2[0x18] = 0;
  param_2[0x17] = 0;
  *(undefined1 *)((int)param_2 + 5) = 0;
  param_2[0x30] = 0;
  param_2[0x2f] = 0;
  param_2[0x20] = 0;
  param_2[0x2d] = 0;
  return param_2;
}


// ==== 0x51ca10 FUN_0051ca10

void * __thiscall FUN_0051ca10(void *param_1,byte param_2)

{
  FUN_0051ca30();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x51ca30 FUN_0051ca30

void __fastcall FUN_0051ca30(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  void *_Memory;
  int *piStack_14;
  undefined4 *local_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0068535e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006bf5a4;
  local_4 = 0;
  local_10 = param_1;
  if ((undefined4 *)param_1[0x28] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x28])(1);
    param_1[0x28] = 0;
  }
  _Memory = DAT_007356ac;
  if (DAT_007356ac != (void *)0x0) {
    FUN_00536570(DAT_007356ac);
    _free(_Memory);
    DAT_007356ac = (void *)0x0;
  }
  if ((undefined4 *)param_1[0x30] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x30])(1);
    param_1[0x30] = 0;
  }
  if ((undefined4 *)param_1[0x2f] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x2f])(1);
    param_1[0x2f] = 0;
  }
  if ((undefined4 *)param_1[0x40] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x40])(1);
    param_1[0x40] = 0;
  }
  piVar1 = (int *)param_1[0x23];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&piStack_14);
    Mutex__Lock();
    (**(code **)(*piStack_14 + 4))(piVar1);
    Mutex__Unlock();
    param_1[0x23] = 0;
  }
  piVar1 = (int *)param_1[0x39];
  local_4 = 0xffffffff;
  while (piVar1 != param_1 + 0x39) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    if (piVar1 + -0x9c != (int *)0x0) {
      (**(code **)piVar1[-0x9c])(1);
    }
    piVar1 = (int *)param_1[0x39];
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x51cb70 EAXSound::GetMasterVolume

/* [canon] audio high (ghidra-canon+nfsug) docs/re/sound.md */

undefined4 __fastcall EAXSound__GetMasterVolume(undefined4 param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case 0:
    uVar1 = _ftol_nocw();
    return uVar1;
  case 1:
    uVar1 = _ftol_nocw();
    return uVar1;
  case 2:
    uVar1 = _ftol_nocw();
    return uVar1;
  case 3:
    uVar1 = _ftol_nocw();
    return uVar1;
  case 4:
    uVar1 = _ftol_nocw();
    return uVar1;
  case 5:
    uVar1 = _ftol_nocw();
    return uVar1;
  default:
    return 0x7fff;
  }
}


// ==== 0x51cc10 FUN_0051cc10

void FUN_0051cc10(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (DAT_006f1dd8 != 0) {
    if (*(int *)(param_1 + 0x104) != 0) {
      FUN_00538e20();
    }
    if (DAT_007356ac != 0) {
      FUN_005365e0();
    }
    if (*(int *)(param_1 + 0xbc) != 0) {
      (**(code **)(*(int *)(*(int *)(param_1 + 0xbc) + 0x20) + 0x24))();
    }
    if (*(int *)(param_1 + 0xc0) != 0) {
      (**(code **)(*(int *)(*(int *)(param_1 + 0xc0) + 0x20) + 0x24))();
    }
    iVar2 = 0;
    piVar1 = (int *)(param_1 + 0xd0);
    do {
      if ((iVar2 < 2) && (piVar1[-3] != 0)) {
        (**(code **)(*(int *)(piVar1[-3] + 0x20) + 0x24))();
      }
      if (*piVar1 != 0) {
        (**(code **)(*(int *)(*piVar1 + 0x20) + 0x24))();
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 4);
    if (*(int *)(param_1 + 0x80) != 0) {
      FUN_0052fa30();
    }
    EAXSound__UpdateCarMasterVolumes();
    if (*(int *)(param_1 + 0xc0) != 0) {
      (**(code **)(*(int *)(*(int *)(param_1 + 0xc0) + 0x20) + 0x24))();
    }
    if (*(int *)(param_1 + 0xbc) != 0) {
      (**(code **)(*(int *)(*(int *)(param_1 + 0xbc) + 0x20) + 0x24))();
    }
    FUN_005330b0();
  }
  return;
}


// ==== 0x51ccf0 FUN_0051ccf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0051ccf0(void)

{
  int in_EAX;
  int unaff_ESI;
  
  *(int *)(in_EAX + 8) = unaff_ESI;
  FUN_0051cc10(in_EAX);
  _DAT_006f8718 = *(undefined4 *)(unaff_ESI + 0x18);
  _DAT_006f871c = _ftol_nocw();
  return;
}


// ==== 0x51cd20 EAXSound::Random

/* [canon] audio high (ghidra-canon+nfsug) docs/re/sound.md */

uint EAXSound__Random(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  param_2 = DAT_007356d8 % param_2;
  uVar1 = DAT_007356d8 ^ 0x1d872b41;
  uVar2 = uVar1 >> 5 ^ uVar1;
  DAT_007356d8 = uVar2 << 0x1b ^ uVar2 ^ uVar1;
  return param_2;
}


// ==== 0x51cd60 EAXSound::InitializeDriver

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXSound__InitializeDriver(void)

{
  char cVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int unaff_EDI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = EAXSND8Wrapper__EAXSND8Wrapper__SEH_unwind_funclet__not_the_ctor_;
  local_c = ExceptionList;
  if (DAT_006f1dd8 != 0) {
    ExceptionList = &local_c;
    puVar2 = _malloc(0x1c);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_EAXSND8Wrapper__scalar_deleting_destructor_006be4fc;
      puVar2[1] = 0;
      puVar2[2] = 0;
      DAT_0072d558 = 0;
      DAT_0072f560 = 0x100;
    }
    *(undefined4 **)(unaff_EDI + 0x100) = puVar2;
    cVar1 = EAXSND8Wrapper__Initialize();
    if (cVar1 == '\0') {
      DAT_006f1dd8 = 0;
      ExceptionList = local_c;
      return;
    }
    puVar2 = _malloc(0x14);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_EAXSound_base_class_scalar_deleting_destructor__vtable_0x6bf5a8__006bf5a8;
      puVar2[1] = 0;
      *(undefined1 *)(puVar2 + 4) = 0;
      puVar2[2] = 0;
    }
    *(undefined4 **)(unaff_EDI + 0xa0) = puVar2;
    pvVar3 = _malloc(0x3e24);
    local_4 = 0;
    if (pvVar3 == (void *)0x0) {
      DAT_007356ac = 0;
    }
    else {
      DAT_007356ac = EAXMixMgr__EAXMixMgr(pvVar3);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x51ce40 EAXSound::InitializeInGame

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXSound__InitializeInGame(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int unaff_EDI;
  
  DiscCheck_ModalFrameLoop(0);
  puVar1 = _malloc(0x250);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar2 = (undefined4 *)EAXS_3DMixer__EAXS_3DMixer();
    *puVar1 = &PTR_FUN_006bf398;
    *puVar2 = &PTR_FUN_006bf36c;
  }
  *(undefined4 **)(unaff_EDI + 0xc0) = puVar1;
  pvVar3 = _malloc(0x4c);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = EAXCollision__EAXCollision();
  }
  *(undefined4 *)(unaff_EDI + 0x80) = uVar4;
  if (DAT_007356ac != 0) {
    FUN_005366e0(DAT_007356ac);
  }
  uVar5 = DAT_006f227c ^ 0x1d872b41;
  uVar6 = uVar5 >> 5 ^ uVar5;
  DAT_007356d8 = DAT_006f227c;
  DAT_006f227c = uVar6 << 0x1b ^ uVar6 ^ uVar5;
  puVar1 = _malloc(0x167c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_006bf4a4;
    DAT_0073567c = 0;
    _DAT_00735680 = 0;
    DAT_0073568c = 0;
    DAT_00735694 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
  }
  *(undefined4 **)(unaff_EDI + 0xb4) = puVar1;
  EAXAemsManager__Initialize(puVar1);
  *(undefined4 *)(unaff_EDI + 0x78) = 0;
  *(undefined4 *)(unaff_EDI + 0x7c) = 0;
  return;
}


// ==== 0x51cf40 EAXSound::InitializeFrontEnd

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXSound__InitializeFrontEnd(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int unaff_EDI;
  bool bVar8;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006895f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  DiscCheck_ModalFrameLoop(0);
  if (DAT_006f1dd8 != 0) {
    puVar2 = _malloc(0x167c);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_006bf4a4;
      DAT_0073567c = 0;
      _DAT_00735680 = 0;
      DAT_0073568c = 0;
      DAT_00735694 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = 0;
      puVar2[5] = 0;
      puVar2[6] = 0;
      puVar2[7] = 0;
      puVar2[8] = 0;
      puVar2[9] = 0;
    }
    *(undefined4 **)(unaff_EDI + 0xb4) = puVar2;
    EAXAemsManager__Initialize(puVar2);
    puVar2 = _malloc(0x250);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2[3] = 0;
      puVar2[4] = 0;
      puVar3 = (undefined4 *)EAXS_3DMixer__EAXS_3DMixer();
      *puVar2 = &PTR_FUN_006bf398;
      *puVar3 = &PTR_FUN_006bf36c;
    }
    *(undefined4 **)(unaff_EDI + 0xc0) = puVar2;
    pvVar4 = _malloc(0x5b0);
    local_4 = 0;
    if (pvVar4 == (void *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_00522600(pvVar4);
    }
    *(undefined4 *)(unaff_EDI + 0xbc) = uVar5;
    iVar1 = DAT_007356ac;
    uVar6 = DAT_006f227c ^ 0x1d872b41;
    uVar7 = uVar6 >> 5 ^ uVar6;
    bVar8 = DAT_007356ac != 0;
    DAT_007356d8 = DAT_006f227c;
    DAT_006f227c = uVar7 << 0x1b ^ uVar7 ^ uVar6;
    *(undefined4 **)(unaff_EDI + 8) = &DAT_007588fc;
    if (bVar8) {
      FUN_005366e0(iVar1);
    }
    *(undefined4 *)(unaff_EDI + 0x78) = 0;
    *(undefined4 *)(unaff_EDI + 0x7c) = 0;
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x51d080 FUN_0051d080

void FUN_0051d080(void)

{
  int iVar1;
  void *_Memory;
  int in_EAX;
  
  if (DAT_0077a920 == 3) {
    EAXSound__UnloadFrontEndSoundBanks(in_EAX);
  }
  else if (DAT_0077a920 == 6) {
    EAXSound__UnLoadInGameSoundBanks();
  }
  if (*(int **)(in_EAX + 0xa0) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0xa0) + 0xc))();
    if (*(undefined4 **)(in_EAX + 0xa0) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_EAX + 0xa0))(1);
    }
    *(undefined4 *)(in_EAX + 0xa0) = 0;
  }
  iVar1 = *(int *)(in_EAX + 0x100);
  if (iVar1 != 0) {
    FUN_0064e8e0();
    if (*(void **)(iVar1 + 4) != (void *)0x0) {
      _free(*(void **)(iVar1 + 4));
      *(undefined4 *)(iVar1 + 4) = 0;
    }
    if (*(void **)(iVar1 + 8) != (void *)0x0) {
      _free(*(void **)(iVar1 + 8));
      *(undefined4 *)(iVar1 + 8) = 0;
    }
  }
  _Memory = DAT_007356ac;
  if (DAT_007356ac != (void *)0x0) {
    FUN_00536570(DAT_007356ac);
    _free(_Memory);
    DAT_007356ac = (void *)0x0;
  }
  if (*(undefined4 **)(in_EAX + 0xc0) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_EAX + 0xc0))(1);
    *(undefined4 *)(in_EAX + 0xc0) = 0;
  }
  if (*(undefined4 **)(in_EAX + 0xbc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_EAX + 0xbc))(1);
    *(undefined4 *)(in_EAX + 0xbc) = 0;
  }
  if (*(undefined4 **)(in_EAX + 0x100) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_EAX + 0x100))(1);
    *(undefined4 *)(in_EAX + 0x100) = 0;
  }
  if (*(undefined4 **)(in_EAX + 0x80) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_EAX + 0x80))(1);
    *(undefined4 *)(in_EAX + 0x80) = 0;
  }
  if (*(undefined4 **)(in_EAX + 0x104) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_EAX + 0x104))(1);
    *(undefined4 *)(in_EAX + 0x104) = 0;
  }
  if (*(undefined4 **)(in_EAX + 0xb4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_EAX + 0xb4))(1);
    *(undefined4 *)(in_EAX + 0xb4) = 0;
  }
  return;
}


// ==== 0x51d1b0 EAXSound::UpdateQueuedEngines

/* [canon] audio high (ghidra-canon+nfsug) docs/re/sound.md */

void EAXSound__UpdateQueuedEngines(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x60) != 0) {
    if (*(char *)(unaff_EDI + 100) != '\0') {
      piVar2 = (int *)(unaff_EDI + 0x48);
      iVar3 = 4;
      do {
        if ((((char)piVar2[1] != '\0') && ((int *)*piVar2 != (int *)0x0)) &&
           (*(char *)((int)piVar2 + 5) != '\0')) {
          cVar1 = (**(code **)(*(int *)*piVar2 + 0x58))();
          if (cVar1 != '\0') {
            *(undefined1 *)(unaff_EDI + 100) = 0;
            *(undefined1 *)((int)piVar2 + 5) = 0;
            *(int *)(unaff_EDI + 0x60) = *(int *)(unaff_EDI + 0x60) + -1;
          }
        }
        piVar2 = piVar2 + -5;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      return;
    }
    iVar3 = 3;
    piVar2 = (int *)(unaff_EDI + 0x48);
    while (((char)piVar2[1] != '\0' || (*piVar2 == 0))) {
      iVar3 = iVar3 + -1;
      piVar2 = piVar2 + -5;
      if (iVar3 < 0) {
        return;
      }
    }
    iVar3 = unaff_EDI + iVar3 * 0x14;
    (**(code **)(**(int **)(iVar3 + 0xc) + 0x54))();
    *(undefined1 *)(iVar3 + 0x10) = 1;
    *(undefined1 *)(iVar3 + 0x11) = 1;
    *(undefined1 *)(unaff_EDI + 100) = 1;
    *(undefined4 *)(unaff_EDI + 0x5c) = 0x1e;
  }
  return;
}


// ==== 0x51d240 EAXSound::Update

/* [canon] audio high (ghidra+hopper) docs/re/sound.md */

void EAXSound__Update(undefined4 param_1)

{
  char cVar1;
  int in_EAX;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  char cVar7;
  
  if (DAT_006f1dd8 == 0) {
    return;
  }
  FUN_00520790();
  FUN_00521850();
  FUN_00536800(DAT_007356ac,param_1);
  if (*(int **)(in_EAX + 0xbc) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0xbc) + 0x20))(0);
  }
  if ((*(int *)(in_EAX + 0x104) != 0) && (FUN_005384e0(), *(int *)(in_EAX + 0xf8) == 1)) {
    iVar4 = *(int *)(in_EAX + 0x104);
    *(undefined4 *)(iVar4 + 0x1c8) = 0;
    *(undefined4 *)(iVar4 + 0x1cc) = 0;
    *(undefined4 *)(iVar4 + 0x264) = 0;
    *(undefined4 *)(iVar4 + 0x268) = 0;
    *(undefined4 *)(iVar4 + 0x26c) = 0;
    *(undefined4 *)(iVar4 + 0x270) = 0;
    puVar2 = (undefined4 *)(iVar4 + 0x98);
    iVar4 = 8;
    do {
      *puVar2 = 0xbf800000;
      puVar2 = puVar2 + 8;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  if (*(int *)(in_EAX + 0x7c) < *(int *)(in_EAX + 0x78)) {
    do {
      iVar4 = *(int *)(*(int *)(in_EAX + 0x7c) * 0x1c + 0x1fc + in_EAX);
      if (iVar4 != -1) {
        *(int *)(*(int *)(in_EAX + 0xb4) + 0x44) = iVar4;
      }
      iVar4 = *(int *)(in_EAX + 0x7c);
      DAT_0073568c = *(undefined4 *)(iVar4 * 0x1c + 500 + in_EAX);
      DAT_00735690 = *(undefined4 *)((iVar4 + 0x12) * 0x1c + in_EAX);
      EAXAemsManager__LoadAemsBank(*(undefined4 *)(iVar4 * 0x1c + in_EAX + 0x1ec),0,1,iVar4 + 9);
      iVar4 = *(int *)(in_EAX + 0x7c) + 1;
      *(int *)(in_EAX + 0x7c) = iVar4;
    } while (iVar4 < *(int *)(in_EAX + 0x78));
  }
  if (*(char *)(DAT_007356a8 + 0x84) != '\0') {
    param_1 = 0;
  }
  if (*(int *)(in_EAX + 0x60) != 0) {
    EAXSound__UpdateQueuedEngines();
  }
  iVar4 = 0;
  if (0 < *(int *)(in_EAX + 0xcc)) {
    piVar5 = (int *)(in_EAX + 0xc4);
    do {
      if ((int *)*piVar5 != (int *)0x0) {
        (**(code **)(*(int *)*piVar5 + 0x30))(param_1);
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar4 < *(int *)(in_EAX + 0xcc));
  }
  iVar4 = 0;
  if (0 < *(int *)(in_EAX + 0xe0)) {
    piVar5 = (int *)(in_EAX + 0xd0);
    do {
      if ((int *)*piVar5 != (int *)0x0) {
        (**(code **)(*(int *)*piVar5 + 0x30))(param_1);
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar4 < *(int *)(in_EAX + 0xe0));
  }
  piVar5 = (int *)(in_EAX + 0xe4);
  for (piVar6 = *(int **)(in_EAX + 0xe4); (piVar6 != piVar5 && (piVar6 != (int *)0x0));
      piVar6 = (int *)*piVar6) {
  }
  if (*piVar5 == 0) goto LAB_0051d40f;
  piVar6 = (int *)(*piVar5 + -0x270);
  while( true ) {
    if (piVar5 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)(in_EAX + -0x18c);
    }
    if (piVar6 == piVar3) break;
    (**(code **)(*piVar6 + 0x30))(param_1);
    if (piVar6[0x9c] == 0) {
LAB_0051d40f:
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = (int *)(piVar6[0x9c] + -0x270);
    }
  }
  FUN_00533060();
  if (*(int **)(in_EAX + 0xc0) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0xc0) + 0x20))(0);
  }
  if (*(int *)(in_EAX + 0x90) != 0) {
    EAXSound__UpdateLoopedMusic__FE_looped_music_Csis_class_FEDriveOn_();
  }
  if (((DAT_006f1dd8 != 0) && (DAT_007356ac != 0)) && (*(int *)(DAT_007356ac + 0x3494) == 9)) {
    iVar4 = *(int *)(in_EAX + 0x104);
    if (iVar4 != 0) {
      cVar1 = (**(code **)(**(int **)(iVar4 + 0x24) + 0x80))(0);
      cVar7 = cVar1 != '\0';
      cVar1 = (**(code **)(**(int **)(iVar4 + 0x24) + 0x80))(1);
      if (cVar1 != '\0') {
        cVar7 = cVar7 + '\x01';
      }
      if (cVar7 != '\0') goto LAB_0051d4e4;
    }
    iVar4 = DAT_007356ac;
    EAXMixMgr__EndMixType(DAT_007356ac,9,0);
    EAXMixMgr__EndMixType(iVar4,9,1);
    EAXMixMgr__EndMixType(iVar4,9,2);
    EAXMixMgr__EndMixType(iVar4,9,3);
  }
LAB_0051d4e4:
  if (*(int **)(in_EAX + 0x80) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0x80) + 0xc))(param_1);
  }
  FUN_0063f0a0(0);
  return;
}


// ==== 0x51d510 FUN_0051d510

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0051d510(undefined4 param_1)

{
  void *pvVar1;
  int *piVar2;
  int unaff_ESI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685866;
  local_c = ExceptionList;
  if ((DAT_006f1dd8 != 0) && (*(int *)(unaff_ESI + 0xcc) < 2)) {
    if (*(int *)(unaff_ESI + 0xcc) == 0) {
      ExceptionList = &local_c;
      pvVar1 = _malloc(0x1fa0);
      local_4 = 0;
      if (pvVar1 == (void *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = (int *)FUN_00525c10(pvVar1);
      }
      pvVar1 = (void *)(*(int *)(unaff_ESI + 0xe0) + *(int *)(unaff_ESI + 0xcc));
      *(int **)(unaff_ESI + 0xc4) = piVar2;
      local_4 = 0xffffffff;
      (**(code **)(*piVar2 + 0x2c))(param_1);
      DAT_007356b0 = *(int *)(unaff_ESI + 0xe0) + *(int *)(unaff_ESI + 0xcc);
      (**(code **)(*(int *)(*(int *)(unaff_ESI + 0xc4) + 0x20) + 0x10))(&DAT_006f41f0);
      (**(code **)(*(int *)(*(int *)(unaff_ESI + 0xc4) + 0x20) + 0x24))();
      *(undefined4 *)(unaff_ESI + 0xcc) = 1;
      (**(code **)(**(int **)(unaff_ESI + 0xc4) + 0x34))();
      ExceptionList = pvVar1;
      return *(undefined4 *)(unaff_ESI + 0xc4);
    }
    ExceptionList = &local_c;
    pvVar1 = _malloc(0x1fa0);
    local_4 = 1;
    if (pvVar1 == (void *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)FUN_00525c10(pvVar1);
    }
    pvVar1 = (void *)(*(int *)(unaff_ESI + 0xe0) + *(int *)(unaff_ESI + 0xcc));
    *(int **)(unaff_ESI + 200) = piVar2;
    local_4 = 0xffffffff;
    (**(code **)(*piVar2 + 0x2c))(param_1);
    _DAT_007356b4 = *(int *)(unaff_ESI + 0xe0) + *(int *)(unaff_ESI + 0xcc);
    (**(code **)(*(int *)(*(int *)(unaff_ESI + 200) + 0x20) + 0x10))(&DAT_006f41f0);
    (**(code **)(*(int *)(*(int *)(unaff_ESI + 200) + 0x20) + 0x24))();
    *(undefined4 *)(unaff_ESI + 0xcc) = 2;
    (**(code **)(**(int **)(unaff_ESI + 200) + 0x34))();
    ExceptionList = pvVar1;
    return *(undefined4 *)(unaff_ESI + 200);
  }
  return 0;
}


// ==== 0x51d6b0 FUN_0051d6b0

undefined4 FUN_0051d6b0(undefined4 param_1)

{
  void *pvVar1;
  int *piVar2;
  undefined4 uVar3;
  int unaff_EDI;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00685836;
  local_c = ExceptionList;
  if (((DAT_006f1dd8 != 0) && (DAT_006f1df0 != 0)) && (*(int *)(unaff_EDI + 0xe0) < 4)) {
    if (*(int *)(unaff_EDI + 0xe0) == 0) {
      ExceptionList = &local_c;
      pvVar1 = _malloc(0x1fe0);
      local_4 = 0;
      if (pvVar1 == (void *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = (int *)FUN_00523420();
      }
      pvVar1 = (void *)(*(int *)(unaff_EDI + 0xcc) + *(int *)(unaff_EDI + 0xe0));
      *(int **)(unaff_EDI + 0xd0) = piVar2;
      local_4 = 0xffffffff;
      (**(code **)(*piVar2 + 0x2c))(param_1);
      (**(code **)(*(int *)(*(int *)(unaff_EDI + 0xd0) + 0x20) + 0x10))(&DAT_006f4260);
      (**(code **)(*(int *)(*(int *)(unaff_EDI + 0xd0) + 0x20) + 0x24))();
      *(undefined4 *)(unaff_EDI + 0xe0) = 1;
      (**(code **)(**(int **)(unaff_EDI + 0xd0) + 0x34))();
      ExceptionList = pvVar1;
      return *(undefined4 *)(unaff_EDI + 0xd0);
    }
    ExceptionList = &local_c;
    pvVar1 = _malloc(0x1fe0);
    local_4 = 1;
    if (pvVar1 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_00523420();
    }
    *(undefined4 *)(unaff_EDI + 0xd0 + *(int *)(unaff_EDI + 0xe0) * 4) = uVar3;
    pvVar1 = (void *)(*(int *)(unaff_EDI + 0xcc) + *(int *)(unaff_EDI + 0xe0));
    local_4 = 0xffffffff;
    (**(code **)(**(int **)(unaff_EDI + 0xd0 + *(int *)(unaff_EDI + 0xe0) * 4) + 0x2c))(param_1);
    (**(code **)(*(int *)(*(int *)(unaff_EDI + 0xd0 + *(int *)(unaff_EDI + 0xe0) * 4) + 0x20) + 0x10
                ))(&DAT_006f4260);
    (**(code **)(*(int *)(*(int *)(unaff_EDI + 0xd0 + *(int *)(unaff_EDI + 0xe0) * 4) + 0x20) + 0x24
                ))();
    (**(code **)(**(int **)(unaff_EDI + 0xd0 + *(int *)(unaff_EDI + 0xe0) * 4) + 0x34))();
    uVar3 = *(undefined4 *)(unaff_EDI + 0xd0 + *(int *)(unaff_EDI + 0xe0) * 4);
    *(int *)(unaff_EDI + 0xe0) = *(int *)(unaff_EDI + 0xe0) + 1;
    ExceptionList = pvVar1;
    return uVar3;
  }
  return 0;
}


// ==== 0x51d860 EAXSound::UpdateCarMasterVolumes

/* [canon] audio med (ghidra-canon) docs/re/sound.md */

void EAXSound__UpdateCarMasterVolumes(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  
  if (*(int *)(in_EAX + 0xe4) == 0) goto LAB_0051d87c;
  iVar2 = *(int *)(in_EAX + 0xe4) + -0x270;
  while( true ) {
    if (in_EAX == -0xe4) {
      iVar1 = 0;
    }
    else {
      iVar1 = in_EAX + -0x18c;
    }
    if (iVar2 == iVar1) break;
    if (iVar2 != 0) {
      (**(code **)(*(int *)(iVar2 + 0x20) + 0x24))();
    }
    if (*(int *)(iVar2 + 0x270) == 0) {
LAB_0051d87c:
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x270) + -0x270;
    }
  }
  return;
}


// ==== 0x51d8c0 FUN_0051d8c0

int * FUN_0051d8c0(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  void *pvVar4;
  int *piVar5;
  int iVar6;
  
  pvVar4 = _malloc(0x330);
  if (pvVar4 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_00524970();
  }
  iVar6 = 0;
  for (puVar2 = *(undefined4 **)(param_1 + 0xe4);
      (puVar2 != (undefined4 *)(param_1 + 0xe4) && (iVar6 = iVar6 + 1, puVar2 != (undefined4 *)0x0))
      ; puVar2 = (undefined4 *)*puVar2) {
  }
  (**(code **)(*piVar5 + 0x2c))(param_2,iVar6);
  (**(code **)(piVar5[8] + 0x10))(&DAT_006f4340);
  piVar3 = *(int **)(param_1 + 0xe8);
  piVar1 = piVar5 + 0x9c;
  *piVar3 = (int)piVar1;
  *(int **)(param_1 + 0xe8) = piVar1;
  piVar5[0x9d] = (int)piVar3;
  *piVar1 = param_1 + 0xe4;
  (**(code **)(piVar5[8] + 0x24))();
  return piVar5;
}


// ==== 0x51d950 FUN_0051d950

void FUN_0051d950(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int unaff_ESI;
  int iVar4;
  
  iVar4 = 0;
  piVar1 = (int *)(unaff_ESI + 0xc4);
  while ((*piVar1 == 0 || (*(int *)(*piVar1 + 0x234) != param_1))) {
    iVar4 = iVar4 + 1;
    piVar1 = piVar1 + 1;
    if (1 < iVar4) {
      iVar4 = 0;
      piVar1 = (int *)(unaff_ESI + 0xd0);
      while ((*piVar1 == 0 || (*(int *)(*piVar1 + 0x234) != param_1))) {
        iVar4 = iVar4 + 1;
        piVar1 = piVar1 + 1;
        if (3 < iVar4) {
          if (*(int *)(unaff_ESI + 0xe0) < 0) {
            *(undefined4 *)(unaff_ESI + 0xe0) = 0;
          }
          if (*(int *)(unaff_ESI + 0xcc) < 0) {
            *(undefined4 *)(unaff_ESI + 0xe0) = 0;
          }
          iVar4 = *(int *)(unaff_ESI + 0xe4);
          if ((iVar4 != 0) && (iVar4 != 0x270)) {
            if (iVar4 == 0) goto LAB_0051da40;
            puVar3 = (undefined4 *)(iVar4 + -0x270);
            while( true ) {
              if (unaff_ESI == -0xe4) {
                puVar2 = (undefined4 *)0x0;
              }
              else {
                puVar2 = (undefined4 *)(unaff_ESI + -0x18c);
              }
              if (puVar3 == puVar2) break;
              if (puVar3[0x8d] == param_1) {
                iVar4 = puVar3[0x9c];
                piVar1 = (int *)puVar3[0x9d];
                *piVar1 = iVar4;
                *(int **)(iVar4 + 4) = piVar1;
                    /* WARNING: Could not recover jumptable at 0x0051da8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                (**(code **)*puVar3)();
                return;
              }
              if (puVar3[0x9c] == 0) {
LAB_0051da40:
                puVar3 = (undefined4 *)0x0;
              }
              else {
                puVar3 = (undefined4 *)(puVar3[0x9c] + -0x270);
              }
            }
          }
          return;
        }
      }
      (**(code **)(**(int **)(unaff_ESI + 0xd0 + iVar4 * 4) + 0xc))();
      puVar3 = *(undefined4 **)(unaff_ESI + 0xd0 + iVar4 * 4);
      if (puVar3 != (undefined4 *)0x0) {
        (**(code **)*puVar3)(1);
      }
      *(undefined4 *)(unaff_ESI + 0xd0 + iVar4 * 4) = 0;
      *(int *)(unaff_ESI + 0xe0) = *(int *)(unaff_ESI + 0xe0) + -1;
      return;
    }
  }
  (**(code **)(**(int **)(unaff_ESI + 0xc4 + iVar4 * 4) + 0xc))();
  puVar3 = *(undefined4 **)(unaff_ESI + 0xc4 + iVar4 * 4);
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  *(undefined4 *)(unaff_ESI + 0xc4 + iVar4 * 4) = 0;
  *(int *)(unaff_ESI + 0xcc) = *(int *)(unaff_ESI + 0xcc) + -1;
  return;
}


// ==== 0x51da90 EAXSound::LoadFrontEndSoundBanks

/* [canon] audio high (ghidra+hopper) docs/re/sound.md */

void EAXSound__LoadFrontEndSoundBanks(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int unaff_EBX;
  int iVar3;
  
  if (DAT_006f1dd8 != 0) {
    EAXSound_InitMixerBanks();
    FUN_0063f0a0(0);
    EAXSound__InitializeFrontEnd();
    *(undefined4 *)(unaff_EBX + 0x78) = 0;
    *(undefined4 *)(unaff_EBX + 0x7c) = 0;
    (**(code **)(**(int **)(unaff_EBX + 0xc0) + 8))();
    (**(code **)(**(int **)(unaff_EBX + 0xbc) + 8))();
    *(undefined4 *)(*(int *)(unaff_EBX + 0x78) * 0x1c + 0x1e8 + unaff_EBX) = 0;
    *(undefined4 *)(*(int *)(unaff_EBX + 0x78) * 0x1c + 0x1f0 + unaff_EBX) = 0;
    *(undefined4 *)(*(int *)(unaff_EBX + 0x78) * 0x1c + 0x1ec + unaff_EBX) = 0xffffffff;
    *(undefined4 *)(*(int *)(unaff_EBX + 0x78) * 0x1c + 500 + unaff_EBX) = 0;
    *(undefined4 *)((*(int *)(unaff_EBX + 0x78) + 0x12) * 0x1c + unaff_EBX) = 0;
    *(undefined4 *)(*(int *)(unaff_EBX + 0x78) * 0x1c + 0x1fc + unaff_EBX) = 0xffffffff;
    iVar3 = *(int *)(unaff_EBX + 0x78) + 1;
    *(int *)(unaff_EBX + 0x78) = iVar3;
    *(undefined4 *)(iVar3 * 0x1c + 0x1e8 + unaff_EBX) = 0;
    *(undefined4 *)(*(int *)(unaff_EBX + 0x78) * 0x1c + 0x1f0 + unaff_EBX) = 1;
    *(undefined4 *)(*(int *)(unaff_EBX + 0x78) * 0x1c + 0x1ec + unaff_EBX) = 0xffffffff;
    *(undefined4 *)(*(int *)(unaff_EBX + 0x78) * 0x1c + 500 + unaff_EBX) = 0;
    *(undefined4 *)((*(int *)(unaff_EBX + 0x78) + 0x12) * 0x1c + unaff_EBX) = 0;
    iVar3 = DAT_006f1ddc;
    *(undefined4 *)(*(int *)(unaff_EBX + 0x78) * 0x1c + 0x1fc + unaff_EBX) = 0xffffffff;
    *(int *)(unaff_EBX + 0x78) = *(int *)(unaff_EBX + 0x78) + 1;
    if (iVar3 != 0) {
      pvVar1 = _malloc(0x2d0);
      if (pvVar1 == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_00537930();
      }
      *(undefined4 *)(unaff_EBX + 0x104) = uVar2;
      *(undefined4 *)(*(int *)(unaff_EBX + 0x78) * 0x1c + 0x1e8 + unaff_EBX) = 1;
      *(undefined4 *)(*(int *)(unaff_EBX + 0x78) * 0x1c + 0x1f0 + unaff_EBX) = 0;
      *(undefined4 *)(*(int *)(unaff_EBX + 0x78) * 0x1c + 0x1ec + unaff_EBX) = 0xffffffff;
      *(undefined4 *)(*(int *)(unaff_EBX + 0x78) * 0x1c + 500 + unaff_EBX) = 0;
      *(undefined4 *)((*(int *)(unaff_EBX + 0x78) + 0x12) * 0x1c + unaff_EBX) = 0;
      *(undefined4 *)(*(int *)(unaff_EBX + 0x78) * 0x1c + 0x1fc + unaff_EBX) = 0xffffffff;
      uVar2 = DAT_006ee6f0;
      iVar3 = *(int *)(unaff_EBX + 0x78) + 1;
      *(int *)(unaff_EBX + 0x78) = iVar3;
      switch(uVar2) {
      case 1:
        uVar2 = 5;
        break;
      case 2:
        uVar2 = 6;
        break;
      case 3:
        uVar2 = 7;
        break;
      case 4:
        uVar2 = 8;
        break;
      default:
        uVar2 = 4;
        break;
      case 9:
        uVar2 = 9;
      }
      *(int *)(unaff_EBX + 0x56c) = iVar3;
      *(undefined4 *)(unaff_EBX + 0x568) = uVar2;
      *(undefined4 *)(iVar3 * 0x1c + 0x1e8 + unaff_EBX) = 1;
      *(undefined4 *)(*(int *)(unaff_EBX + 0x78) * 0x1c + 0x1f0 + unaff_EBX) = uVar2;
      *(undefined4 *)(*(int *)(unaff_EBX + 0x78) * 0x1c + 0x1ec + unaff_EBX) = 0xffffffff;
      *(undefined4 *)(*(int *)(unaff_EBX + 0x78) * 0x1c + 500 + unaff_EBX) = 0;
      *(undefined4 *)((*(int *)(unaff_EBX + 0x78) + 0x12) * 0x1c + unaff_EBX) = 0;
      *(undefined4 *)(*(int *)(unaff_EBX + 0x78) * 0x1c + 0x1fc + unaff_EBX) = 0xffffffff;
      *(int *)(unaff_EBX + 0x78) = *(int *)(unaff_EBX + 0x78) + 1;
      FUN_00537a60(0,1,(&PTR_DAT_006f6fdc)[*(int *)(unaff_EBX + 0xf0)],
                   (&PTR_DAT_006f6f9c)[*(int *)(unaff_EBX + 0xf0)]);
      FUN_00537a60(4,0x5f,PTR_DAT_006f6d44,(&PTR_DAT_006f6f9c)[*(int *)(unaff_EBX + 0xf0)]);
      FUN_0051cc10(unaff_EBX);
    }
    iVar3 = *(int *)(unaff_EBX + 0x78) + -1;
    *(int *)(unaff_EBX + 0x78) = iVar3;
    *(undefined4 *)(iVar3 * 0x1c + 500 + unaff_EBX) = param_1;
    *(undefined4 *)((*(int *)(unaff_EBX + 0x78) + 0x12) * 0x1c + unaff_EBX) = param_2;
    *(int *)(unaff_EBX + 0x78) = *(int *)(unaff_EBX + 0x78) + 1;
    FUN_0051cc10(unaff_EBX);
    FUN_0063f0a0(0);
    *(undefined4 *)(DAT_007356a8 + 0xf8) = 1;
  }
  return;
}


// ==== 0x51dd70 EAXSound::UnloadFrontEndSoundBanks

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXSound__UnloadFrontEndSoundBanks(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = param_1;
  if (DAT_006f1dd8 != 0) {
    if (*(int *)(param_1 + 0xbc) != 0) {
      FUN_00523060(*(int *)(param_1 + 0xbc));
    }
    if (*(int *)(param_1 + 0x104) != 0) {
      FUN_005379c0();
      FUN_0063f0a0(0);
    }
    piVar5 = (int *)(param_1 + 0x78);
    param_1 = 0;
    if (0 < *piVar5) {
      piVar5 = (int *)(iVar4 + 0x1e8);
      do {
        if ((*piVar5 == 1) && (*(int *)(iVar4 + 0x104) != 0)) {
          FUN_00537a00();
        }
        iVar1 = *(int *)(iVar4 + 0xb4);
        if (DAT_006f1dd8 == 1) {
          *(int *)(iVar1 + 0x40) = piVar5[1];
          EAXAemsManager__SetCurrentFullBankIndex();
          iVar3 = DAT_00735684;
          iVar2 = *(int *)(iVar1 + 0x200 + DAT_00735684 * 4);
          if (iVar2 < 2) {
            *(undefined4 *)(iVar1 + 0x200 + DAT_00735684 * 4) = 0;
            if (0 < iVar2) {
              SNDAEMS_removemodulebank(*(undefined4 *)(DAT_0072cfd0 + 0x48 + iVar3 * 4));
              FUN_00522280(iVar1);
            }
          }
          else {
            *(int *)(iVar1 + 0x200 + DAT_00735684 * 4) = iVar2 + -1;
          }
        }
        param_1 = param_1 + 1;
        piVar5 = piVar5 + 7;
      } while (param_1 < *(int *)(iVar4 + 0x78));
    }
    if (*(undefined4 **)(iVar4 + 0x104) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(iVar4 + 0x104))(1);
      *(undefined4 *)(iVar4 + 0x104) = 0;
    }
    if (*(undefined4 **)(iVar4 + 0xbc) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(iVar4 + 0xbc))(1);
      *(undefined4 *)(iVar4 + 0xbc) = 0;
    }
    if (*(undefined4 **)(iVar4 + 0xc0) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(iVar4 + 0xc0))(1);
      *(undefined4 *)(iVar4 + 0xc0) = 0;
    }
    if (*(undefined4 **)(iVar4 + 0xb4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(iVar4 + 0xb4))(1);
      *(undefined4 *)(iVar4 + 0xb4) = 0;
    }
    FUN_0063f0a0(0);
  }
  return;
}


// ==== 0x51dec0 EAXSound::LoadInGameSoundBanks

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXSound__LoadInGameSoundBanks(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int extraout_ECX;
  int extraout_ECX_00;
  char *pcVar10;
  undefined4 uVar11;
  int iVar12;
  int *piVar13;
  bool bVar14;
  undefined8 uVar15;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  void *local_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar3 = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00689633;
  local_c = ExceptionList;
  if (DAT_006f1dd8 == 0) {
    return;
  }
  ExceptionList = &local_c;
  *(undefined4 **)(param_1 + 8) = &DAT_007588fc;
  if (*(undefined4 **)(param_1 + 0xb4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0xb4))(1);
  }
  EAXSound_InitMixerBanks();
  EAXSound__InitializeInGame();
  (**(code **)(**(int **)(param_1 + 0xc0) + 8))();
  *(undefined4 *)(*(int *)(param_1 + 0x78) * 0x1c + 0x1e8 + param_1) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x78) * 0x1c + 0x1f0 + param_1) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x78) * 0x1c + 0x1ec + param_1) = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x78) * 0x1c + 500 + param_1) = 0;
  *(undefined4 *)((*(int *)(param_1 + 0x78) + 0x12) * 0x1c + param_1) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x78) * 0x1c + 0x1fc + param_1) = 0xffffffff;
  iVar12 = DAT_007356a8;
  *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + 1;
  *(undefined4 *)(iVar12 + 0xf8) = 5;
  DAT_007356c4 = 0;
  DAT_007356c0 = 0;
  _DAT_007356dc = 0;
  if ((DAT_0078a344 != '\0') || (DAT_007361a8 != 0)) {
    *(undefined4 *)(iVar12 + 0xf8) = 2;
  }
  if ((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) {
    *(undefined4 *)(iVar12 + 0xf8) = 3;
  }
  if ((DAT_0078a346 != '\0') || (DAT_007361a0 != 0)) {
    *(undefined4 *)(iVar12 + 0xf8) = 4;
  }
  iVar12 = DAT_0078a328 + DAT_0078a32c + DAT_0078a324 + DAT_0078a320;
  param_1 = 0;
  iStack_28 = 0;
  iStack_20 = 0;
  iStack_24 = 0;
  if (0 < iVar12) {
    iStack_18 = 0;
    iStack_14 = iVar12;
    do {
      iVar9 = DAT_0078a418 + iStack_18;
      uVar15 = FUN_00520320(iVar3);
      iVar8 = (int)((ulonglong)uVar15 >> 0x20);
      iVar4 = *(int *)(&DAT_006f8100 + (int)uVar15 * 4);
      if ((*(int *)(iVar9 + 4) == 1) && (*(char *)(iVar9 + 0x734) == '\0')) {
        if (DAT_00734658 == 0) {
          iStack_28 = *(int *)(iVar9 + 0x20);
          iVar7 = *(int *)(iVar9 + 0x24);
          if (*(int *)(iVar9 + 0x24) < iStack_20) {
            iVar7 = iStack_20;
          }
          iStack_1c = *(int *)(iVar9 + 0x28);
          if (*(int *)(iVar9 + 0x28) < iVar8) {
            iStack_1c = iVar8;
          }
          iVar8 = *(int *)(iVar9 + 0x34);
          iStack_20 = iVar7;
          if (*(int *)(iVar9 + 0x34) < iStack_24) {
            iVar8 = iStack_24;
          }
        }
        else {
          iStack_28 = 3;
          iStack_20 = 3;
          iStack_1c = 3;
          iStack_24 = 3;
          iVar8 = iStack_24;
        }
        iStack_24 = iVar8;
        if (param_1 == 1) {
          if ((*(int *)(*(int *)(iVar3 + 0x68) + 8) == iVar4) &&
             (*(int *)(*(int *)(iVar3 + 0x68) + 4) == iStack_28)) goto LAB_0051e3c4;
LAB_0051e0df:
          *(int *)(iVar3 + 0x68 + param_1 * 4) = *(int *)(iVar3 + 0x78) * 0x1c + 0x1e8 + iVar3;
        }
        else if (param_1 < 2) goto LAB_0051e0df;
        *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1e8 + iVar3) = 0xc;
        *(int *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = iVar4;
        *(int *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = iStack_28;
        *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
        *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
        *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = 0xffffffff;
        iVar8 = *(int *)(iVar3 + 0x78) + 1;
        *(int *)(iVar3 + 0x78) = iVar8;
        *(undefined4 *)(iVar8 * 0x1c + 0x1e8 + iVar3) = 0xd;
        *(int *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = iVar4;
        *(int *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = iStack_28;
        *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
        *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
        *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = DAT_007356fc;
        iVar4 = *(int *)(iVar3 + 0x78) + 1;
        param_1 = param_1 + 1;
        *(int *)(iVar3 + 0x78) = iVar4;
        if (param_1 < 2) {
          *(undefined4 *)(iVar4 * 0x1c + 0x1e8 + iVar3) = 8;
          *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = 2;
          *(int *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = iStack_28;
          *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
          *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
          *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = 0xffffffff;
          iVar4 = *(int *)(iVar3 + 0x78) + 1;
          *(int *)(iVar3 + 0x78) = iVar4;
          *(undefined4 *)(iVar4 * 0x1c + 0x1e8 + iVar3) = 8;
          *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = 1;
          *(int *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = iStack_28;
          *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
          *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
          *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = 0xffffffff;
          iVar4 = *(int *)(iVar3 + 0x78) + 1;
          *(int *)(iVar3 + 0x78) = iVar4;
          if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
            bVar1 = 0;
          }
          else {
            bVar1 = 1;
          }
          *(undefined4 *)(iVar4 * 0x1c + 0x1e8 + iVar3) = 7;
          *(uint *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = (uint)bVar1;
          *(int *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = iStack_24;
          *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
          *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
          *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = 0xffffffff;
          iVar4 = *(int *)(iVar3 + 0x78) + 1;
          *(int *)(iVar3 + 0x78) = iVar4;
          iVar9 = (int)*(char *)(iVar9 + 0x435);
          if (iVar9 < 1) {
            iVar9 = 0;
          }
          else if (3 < iVar9) {
            iVar9 = 3;
          }
          *(undefined4 *)(iVar4 * 0x1c + 0x1e8 + iVar3) = 0xe;
          *(int *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = iVar9;
          *(int *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = iStack_20;
          *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
          *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
          *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = 0xffffffff;
          iVar9 = *(int *)(iVar3 + 0x78) + 1;
          *(int *)(iVar3 + 0x78) = iVar9;
          *(undefined4 *)(iVar9 * 0x1c + 0x1e8 + iVar3) = 8;
          *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = 0;
          *(int *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = iStack_1c;
          *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
          *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
          *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = 0xffffffff;
          *(int *)(iVar3 + 0x78) = *(int *)(iVar3 + 0x78) + 1;
        }
      }
LAB_0051e3c4:
      iStack_18 = iStack_18 + 0x750;
      iStack_14 = iStack_14 + -1;
    } while (iStack_14 != 0);
    if (1 < param_1) goto LAB_0051e5c5;
  }
  iVar9 = -1;
  iStack_24 = -1;
  iStack_18 = 0;
  if (iVar12 < 1) {
LAB_0051e47b:
    iVar9 = -1;
    iVar4 = 0;
    iStack_24 = -1;
    if (iVar12 < 1) goto LAB_0051e5c5;
    piVar13 = (int *)(DAT_0078a418 + 0x20);
    do {
      if (piVar13[-7] == 2) {
        iVar8 = 3;
        if (DAT_00734658 == 0) {
          iVar8 = *piVar13;
        }
        if (iStack_24 < iVar8) {
          iVar9 = iVar4;
          iStack_24 = iVar8;
        }
      }
      iVar4 = iVar4 + 1;
      piVar13 = piVar13 + 0x1d4;
    } while (iVar4 < iVar12);
    if (iVar9 == -1) goto LAB_0051e5c5;
  }
  else {
    pcVar10 = (char *)(DAT_0078a418 + 0x734);
    do {
      if ((*(int *)(pcVar10 + -0x730) != 1) || (*pcVar10 != '\0')) {
        uVar15 = FUN_00520320(iVar3);
        pcVar10 = (char *)((ulonglong)uVar15 >> 0x20);
        iVar4 = 3;
        if (DAT_00734658 == 0) {
          iVar4 = *(int *)(pcVar10 + -0x714);
        }
        iVar9 = extraout_ECX;
        if (((iStack_24 < iVar4) && (iVar9 = extraout_ECX, 0 < param_1)) &&
           (iVar9 = extraout_ECX,
           *(int *)(&DAT_006f8100 + (int)uVar15 * 4) != *(int *)(*(int *)(iVar3 + 0x68) + 8))) {
          iVar9 = iStack_18;
          iStack_24 = iVar4;
        }
      }
      iStack_18 = iStack_18 + 1;
      pcVar10 = pcVar10 + 0x750;
    } while (iStack_18 < iVar12);
    if (iVar9 == -1) goto LAB_0051e47b;
  }
  iVar12 = FUN_00520320(iVar3);
  uVar6 = *(undefined4 *)(&DAT_006f8100 + iVar12 * 4);
  uVar11 = 3;
  if (DAT_00734658 == 0) {
    uVar11 = *(undefined4 *)(extraout_ECX_00 + 0x20);
  }
  *(int *)(iVar3 + 0x68 + param_1 * 4) = *(int *)(iVar3 + 0x78) * 0x1c + 0x1e8 + iVar3;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1e8 + iVar3) = 0xc;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = uVar6;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = uVar11;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
  *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = 0xffffffff;
  iVar12 = *(int *)(iVar3 + 0x78) + 1;
  *(int *)(iVar3 + 0x78) = iVar12;
  *(undefined4 *)(iVar12 * 0x1c + 0x1e8 + iVar3) = 0xd;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = uVar6;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = uVar11;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
  uVar6 = DAT_007356fc;
  *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = uVar6;
  *(int *)(iVar3 + 0x78) = *(int *)(iVar3 + 0x78) + 1;
LAB_0051e5c5:
  if ((DAT_0078a345 == '\0') && (DAT_007361a4 == 0)) {
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1e8 + iVar3) = 3;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = 1;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = 0xffffffff;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
    *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = 0xffffffff;
    iVar12 = *(int *)(iVar3 + 0x78) + 1;
    *(int *)(iVar3 + 0x78) = iVar12;
    *(undefined4 *)(iVar12 * 0x1c + 0x1e8 + iVar3) = 3;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = 0;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = 0xffffffff;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
    *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = 0xffffffff;
    *(int *)(iVar3 + 0x78) = *(int *)(iVar3 + 0x78) + 1;
  }
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1e8 + iVar3) = 6;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = 0;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = 0xffffffff;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
  *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = 0xffffffff;
  iVar12 = *(int *)(iVar3 + 0x78) + 1;
  *(int *)(iVar3 + 0x78) = iVar12;
  *(undefined4 *)(iVar12 * 0x1c + 0x1e8 + iVar3) = 7;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = 2;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = 0;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
  *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = 0xffffffff;
  iVar12 = *(int *)(iVar3 + 0x78) + 1;
  *(int *)(iVar3 + 0x78) = iVar12;
  *(undefined4 *)(iVar12 * 0x1c + 0x1e8 + iVar3) = 6;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = 1;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = 0xffffffff;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
  *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = 0xffffffff;
  iVar12 = *(int *)(iVar3 + 0x78) + 1;
  *(int *)(iVar3 + 0x78) = iVar12;
  *(undefined4 *)(iVar12 * 0x1c + 0x1e8 + iVar3) = 3;
  if (iStack_28 < 2) {
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = 2;
  }
  else {
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = 3;
  }
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = 0xffffffff;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
  *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
  *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = 0xffffffff;
  *(int *)(iVar3 + 0x78) = *(int *)(iVar3 + 0x78) + 1;
  iVar12 = DAT_0078a2f0;
  if (DAT_006f1ddc != 0) {
    pvVar5 = _malloc(0x2d0);
    if (pvVar5 == (void *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_00537930();
    }
    *(undefined4 *)(iVar3 + 0x104) = uVar6;
    *(undefined4 *)(iVar3 + 0xf0) = 0;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1e8 + iVar3) = 1;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = 0;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = 0xffffffff;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
    *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = 0xffffffff;
    iVar9 = *(int *)(iVar3 + 0x78) + 1;
    *(int *)(iVar3 + 0x78) = iVar9;
    *(undefined4 *)(iVar9 * 0x1c + 0x1e8 + iVar3) = 1;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = 1;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = 0xffffffff;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
    *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = 0xffffffff;
    iVar9 = *(int *)(iVar3 + 0x78) + 1;
    *(int *)(iVar3 + 0x78) = iVar9;
    *(undefined4 *)(iVar9 * 0x1c + 0x1e8 + iVar3) = 1;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = 2;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = 0xffffffff;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
    *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = 0xffffffff;
    iVar9 = *(int *)(iVar3 + 0x78) + 1;
    *(int *)(iVar3 + 0x78) = iVar9;
    *(undefined4 *)(iVar9 * 0x1c + 0x1e8 + iVar3) = 1;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = 3;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = 0xffffffff;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
    *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
    uVar6 = DAT_006ee6f0;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = 0xffffffff;
    iVar9 = *(int *)(iVar3 + 0x78) + 1;
    *(int *)(iVar3 + 0x78) = iVar9;
    switch(uVar6) {
    case 1:
      uVar6 = 5;
      break;
    case 2:
      uVar6 = 6;
      break;
    case 3:
      uVar6 = 7;
      break;
    case 4:
      uVar6 = 8;
      break;
    default:
      uVar6 = 4;
      break;
    case 9:
      uVar6 = 9;
    }
    *(int *)(iVar3 + 0x56c) = iVar9;
    *(undefined4 *)(iVar3 + 0x568) = uVar6;
    *(undefined4 *)(iVar9 * 0x1c + 0x1e8 + iVar3) = 1;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1f0 + iVar3) = uVar6;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1ec + iVar3) = 0xffffffff;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 500 + iVar3) = 0;
    *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = 0;
    *(undefined4 *)(*(int *)(iVar3 + 0x78) * 0x1c + 0x1fc + iVar3) = 0xffffffff;
    bVar14 = DAT_006f1de8 == 1;
    *(int *)(iVar3 + 0x78) = *(int *)(iVar3 + 0x78) + 1;
    if (bVar14) {
      FUN_00537a60(0,1,(&PTR_DAT_006f6fdc)[*(int *)(iVar3 + 0xf0)],
                   (&PTR_DAT_006f6f9c)[*(int *)(iVar3 + 0xf0)]);
    }
    puVar2 = PTR_DAT_006f6fa0;
    if (((DAT_006f1de4 == 1) && (iVar9 = *(int *)(iVar3 + 0x104), *(int *)(iVar9 + 0x8c) < 6)) &&
       (*(int *)(iVar9 + 0x18) == 0)) {
      pvVar5 = _malloc(0x610);
      uStack_4 = 1;
      if (pvVar5 == (void *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = EAXS_AmbStereoStream__EAXS_AmbStereoStream(pvVar5);
      }
      *(undefined4 *)(iVar9 + 0x18) = uVar6;
      *(undefined4 *)(iVar9 + 0x2c) = 1;
      uStack_4 = 0xffffffff;
      (**(code **)(**(int **)(iVar9 + 0x18) + 0x1c))(1,4,1,0x1f,0x6400,&DAT_006f4f78,puVar2);
      *(int *)(iVar9 + 0x8c) = *(int *)(iVar9 + 0x8c) + 1;
      (**(code **)(**(int **)(iVar9 + 0x18) + 0xc))(0);
      (**(code **)(**(int **)(iVar9 + 0x18) + 8))(0);
      (**(code **)(**(int **)(iVar9 + 0x18) + 0x14))(iVar9 + 0x1b0);
    }
    if (DAT_006f1de0 == 1) {
      FUN_00537a60(2,0x16,&DAT_006f65b0,PTR_DAT_006f6fa4);
    }
    FUN_00537a60(3,9,&DAT_006f6b48,PTR_DAT_006f6fd4);
    FUN_00537a60(4,0x5f,PTR_DAT_006f6d44,PTR_DAT_006f6fa0);
    piVar13 = *(int **)(*(int *)(iVar3 + 0x104) + 0x18);
    if (piVar13 != (int *)0x0) {
      (**(code **)(*piVar13 + 0x20))(0x3ffe);
    }
    piVar13 = *(int **)(*(int *)(iVar3 + 0x104) + 0x1c);
    if (piVar13 != (int *)0x0) {
      (**(code **)(*piVar13 + 0x20))(0x7ffe);
    }
    piVar13 = *(int **)(*(int *)(iVar3 + 0x104) + 0x20);
    if (piVar13 != (int *)0x0) {
      (**(code **)(*piVar13 + 0x20))(0x7ffe);
    }
    if (iVar12 == 0x4b1) {
      *(undefined1 *)(iVar3 + 0x70) = 0;
    }
  }
  iVar12 = *(int *)(iVar3 + 0x78) + -1;
  *(int *)(iVar3 + 0x78) = iVar12;
  *(undefined4 *)(iVar12 * 0x1c + 500 + iVar3) = param_2;
  *(undefined4 *)((*(int *)(iVar3 + 0x78) + 0x12) * 0x1c + iVar3) = param_3;
  *(int *)(iVar3 + 0x78) = *(int *)(iVar3 + 0x78) + 1;
  *(undefined4 *)(DAT_007356a8 + 0xfc) = DAT_0078a41c;
  FUN_0051cc10(iVar3);
  if (*(int **)(iVar3 + 0xa0) != (int *)0x0) {
    (**(code **)(**(int **)(iVar3 + 0xa0) + 8))();
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x51ec40 EAXSound::UnLoadInGameSoundBanks

/* [canon] audio high (ghidra) docs/re/sound.md */

void EAXSound__UnLoadInGameSoundBanks(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_EDI;
  undefined4 uStack_4;
  
  if (DAT_006f1dd8 != 0) {
    if (*(int **)(unaff_EDI + 0xa0) != (int *)0x0) {
      (**(code **)(**(int **)(unaff_EDI + 0xa0) + 0xc))();
    }
    iVar4 = *(int *)(unaff_EDI + 0x104);
    if (*(int **)(iVar4 + 0x14) != (int *)0x0) {
      (**(code **)(**(int **)(iVar4 + 0x14) + 0x28))();
      if (*(undefined4 **)(iVar4 + 0x14) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(iVar4 + 0x14))(1);
      }
      *(undefined4 *)(iVar4 + 0x14) = 0;
    }
    iVar4 = *(int *)(unaff_EDI + 0x104);
    if (*(int **)(iVar4 + 0x18) != (int *)0x0) {
      (**(code **)(**(int **)(iVar4 + 0x18) + 0x28))();
      if (*(undefined4 **)(iVar4 + 0x18) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(iVar4 + 0x18))(1);
      }
      *(undefined4 *)(iVar4 + 0x18) = 0;
    }
    iVar4 = *(int *)(unaff_EDI + 0x104);
    if (*(int **)(iVar4 + 0x1c) != (int *)0x0) {
      (**(code **)(**(int **)(iVar4 + 0x1c) + 0x28))();
      if (*(undefined4 **)(iVar4 + 0x1c) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(iVar4 + 0x1c))(1);
      }
      *(undefined4 *)(iVar4 + 0x1c) = 0;
    }
    iVar4 = *(int *)(unaff_EDI + 0x104);
    if (*(int **)(iVar4 + 0x20) != (int *)0x0) {
      (**(code **)(**(int **)(iVar4 + 0x20) + 0x28))();
      if (*(undefined4 **)(iVar4 + 0x20) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(iVar4 + 0x20))(1);
      }
      *(undefined4 *)(iVar4 + 0x20) = 0;
    }
    iVar4 = *(int *)(unaff_EDI + 0x104);
    if (*(int **)(iVar4 + 0x24) != (int *)0x0) {
      (**(code **)(**(int **)(iVar4 + 0x24) + 0x28))();
      if (*(undefined4 **)(iVar4 + 0x24) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(iVar4 + 0x24))(1);
      }
      *(undefined4 *)(iVar4 + 0x24) = 0;
    }
    FUN_0063f0a0(0);
    *(undefined1 *)(unaff_EDI + 0x70) = 0;
    *(undefined1 *)(unaff_EDI + 0x72) = 0;
    *(undefined1 *)(unaff_EDI + 0x73) = 0;
    (**(code **)(**(int **)(unaff_EDI + 0x80) + 8))();
    FUN_00533100();
    uStack_4 = 0;
    if (0 < *(int *)(unaff_EDI + 0x78)) {
      iVar4 = unaff_EDI + 0x1e8;
      do {
        iVar1 = *(int *)(unaff_EDI + 0xb4);
        if (DAT_006f1dd8 == 1) {
          *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(iVar4 + 4);
          EAXAemsManager__SetCurrentFullBankIndex();
          iVar3 = DAT_00735684;
          iVar2 = *(int *)(iVar1 + 0x200 + DAT_00735684 * 4);
          if (iVar2 < 2) {
            *(undefined4 *)(iVar1 + 0x200 + DAT_00735684 * 4) = 0;
            if (0 < iVar2) {
              SNDAEMS_removemodulebank(*(undefined4 *)(DAT_0072cfd0 + 0x48 + iVar3 * 4));
              FUN_00522280(iVar1);
            }
          }
          else {
            *(int *)(iVar1 + 0x200 + DAT_00735684 * 4) = iVar2 + -1;
          }
        }
        uStack_4 = uStack_4 + 1;
        iVar4 = iVar4 + 0x1c;
      } while (uStack_4 < *(int *)(unaff_EDI + 0x78));
    }
    if (*(undefined4 **)(unaff_EDI + 0x104) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(unaff_EDI + 0x104))(1);
      *(undefined4 *)(unaff_EDI + 0x104) = 0;
    }
    if (*(undefined4 **)(unaff_EDI + 0xb4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(unaff_EDI + 0xb4))(1);
      *(undefined4 *)(unaff_EDI + 0xb4) = 0;
    }
    if (*(undefined4 **)(unaff_EDI + 0xc0) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(unaff_EDI + 0xc0))(1);
      *(undefined4 *)(unaff_EDI + 0xc0) = 0;
    }
    if (*(undefined4 **)(unaff_EDI + 0x80) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(unaff_EDI + 0x80))(1);
      *(undefined4 *)(unaff_EDI + 0x80) = 0;
    }
    FUN_0063f0a0(0);
  }
  return;
}


// ==== 0x51ee20 EAXSound::EnterPauseMenu

/* [canon] audio med (ghidra) docs/re/sound.md */

void EAXSound__EnterPauseMenu(void)

{
  int iVar1;
  int unaff_EDI;
  
  FUN_00532fc0();
  iVar1 = *(int *)(unaff_EDI + 0x104);
  if (iVar1 != 0) {
    *(undefined4 *)(unaff_EDI + 0xac) = *(undefined4 *)(iVar1 + 0x1c4);
    if (DAT_006f1dd8 != 0) {
      *(undefined4 *)(iVar1 + 0x1c4) = 4;
      FUN_00537cc0();
    }
    *(undefined1 *)(unaff_EDI + 0x9c) = 1;
  }
  if ((*(int *)(unaff_EDI + 0x104) != 0) && (DAT_006f1dd8 != 0)) {
    *(undefined4 *)(*(int *)(unaff_EDI + 0x104) + 0x1c4) = 4;
    FUN_00537cc0();
  }
  iVar1 = DAT_007356ac;
  if (DAT_007356ac != 0) {
    EAXMixMgr__SetMixType(DAT_007356ac,8,0xbf800000,0);
    EAXMixMgr__SetMixType(iVar1,8,0xbf800000,1);
    EAXMixMgr__SetMixType(iVar1,8,0xbf800000,2);
    EAXMixMgr__SetMixType(iVar1,8,0xbf800000,3);
  }
  *(undefined1 *)(unaff_EDI + 0x84) = 1;
  *(undefined1 *)(unaff_EDI + 0x9c) = 1;
  return;
}


// ==== 0x51eee0 FUN_0051eee0

void FUN_0051eee0(int param_1)

{
  int iVar1;
  int in_EAX;
  undefined4 *puVar2;
  int iVar3;
  
  FUN_00533010();
  iVar3 = DAT_007356ac;
  if (DAT_007356ac != 0) {
    EAXMixMgr__EndMixType(DAT_007356ac,8,0);
    EAXMixMgr__EndMixType(iVar3,8,1);
    EAXMixMgr__EndMixType(iVar3,8,2);
    EAXMixMgr__EndMixType(iVar3,8,3);
  }
  *(undefined1 *)(param_1 + 0x84) = 0;
  *(undefined1 *)(param_1 + 0x9c) = 0;
  if (in_EAX == -1) {
    if ((DAT_0077a920 == 3) || (DAT_007361f0 == (int *)0x0)) {
      in_EAX = 0;
    }
    else if (*DAT_007361f0 == 4) {
      in_EAX = 1;
    }
  }
  iVar3 = *(int *)(param_1 + 0x104);
  if (iVar3 == 0) {
    return;
  }
  if (in_EAX != 1) {
    if (in_EAX == 3) {
      FUN_005379c0();
      FUN_0063f0a0(0);
      return;
    }
    if (in_EAX != 2) {
      if (DAT_00733f74 != 0) {
        return;
      }
      *(undefined4 *)(iVar3 + 0x1c8) = 0;
      *(undefined4 *)(iVar3 + 0x1cc) = 0;
      *(undefined4 *)(iVar3 + 0x264) = 0;
      *(undefined4 *)(iVar3 + 0x268) = 0;
      *(undefined4 *)(iVar3 + 0x26c) = 0;
      *(undefined4 *)(iVar3 + 0x270) = 0;
      puVar2 = (undefined4 *)(iVar3 + 0x98);
      iVar3 = 8;
      do {
        *puVar2 = 0xbf800000;
        puVar2 = puVar2 + 8;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      FUN_00537ca0(2);
      return;
    }
    FUN_00538df0();
    DAT_007355d4 = 0;
    return;
  }
  iVar1 = *(int *)(param_1 + 0xf8);
  if (iVar1 != 5) {
    if (iVar1 != 2) {
      if (iVar1 == 3) {
        *(undefined4 *)(iVar3 + 0x1c8) = 0x1a;
        *(undefined4 *)(iVar3 + 0x1cc) = 0x1a;
        *(undefined **)(iVar3 + 0x264) = &DAT_006f5660;
        *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
        *(undefined4 *)(iVar3 + 0x26c) = 0xb;
        *(undefined4 *)(iVar3 + 0x270) = 10;
        puVar2 = (undefined4 *)(iVar3 + 0x98);
        iVar3 = 8;
        do {
          *puVar2 = 0xbf800000;
          puVar2 = puVar2 + 8;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      FUN_00537ca0(2);
      return;
    }
    switch(DAT_0078a2f0) {
    case 0x4b1:
      *(undefined4 *)(iVar3 + 0x1c8) = 0x13;
      *(undefined4 *)(iVar3 + 0x1cc) = 0x13;
      *(undefined **)(iVar3 + 0x264) = &DAT_006f6268;
      *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
      *(undefined4 *)(iVar3 + 0x26c) = 3;
      *(undefined4 *)(iVar3 + 0x270) = 10;
      puVar2 = (undefined4 *)(iVar3 + 0x98);
      iVar3 = 8;
      do {
        *puVar2 = 0xbf800000;
        puVar2 = puVar2 + 8;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      FUN_00537ca0(2);
      return;
    case 0x4b2:
      *(undefined4 *)(iVar3 + 0x1c8) = 0x14;
      *(undefined4 *)(iVar3 + 0x1cc) = 0x14;
      *(undefined **)(iVar3 + 0x264) = &DAT_006f62e0;
      *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
      *(undefined4 *)(iVar3 + 0x26c) = 3;
      *(undefined4 *)(iVar3 + 0x270) = 10;
      puVar2 = (undefined4 *)(iVar3 + 0x98);
      iVar3 = 8;
      do {
        *puVar2 = 0xbf800000;
        puVar2 = puVar2 + 8;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      FUN_00537ca0(2);
      return;
    default:
      *(undefined4 *)(iVar3 + 0x1c8) = 0x19;
      *(undefined4 *)(iVar3 + 0x1cc) = 0x19;
      *(undefined4 *)(iVar3 + 0x264) = 0;
      *(undefined4 *)(iVar3 + 0x268) = 0;
      *(undefined4 *)(iVar3 + 0x26c) = 0;
      *(undefined4 *)(iVar3 + 0x270) = 0;
      puVar2 = (undefined4 *)(iVar3 + 0x98);
      iVar3 = 8;
      do {
        *puVar2 = 0xbf800000;
        puVar2 = puVar2 + 8;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      FUN_00537ca0(2);
      return;
    case 0x4b6:
      *(undefined4 *)(iVar3 + 0x1c8) = 0x15;
      *(undefined4 *)(iVar3 + 0x1cc) = 0x15;
      *(undefined **)(iVar3 + 0x264) = &DAT_006f63d0;
      *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
      *(undefined4 *)(iVar3 + 0x26c) = 3;
      *(undefined4 *)(iVar3 + 0x270) = 10;
      puVar2 = (undefined4 *)(iVar3 + 0x98);
      iVar3 = 8;
      break;
    case 0x4b7:
      *(undefined4 *)(iVar3 + 0x1c8) = 0x16;
      *(undefined4 *)(iVar3 + 0x1cc) = 0x16;
      *(undefined **)(iVar3 + 0x264) = &DAT_006f6448;
      *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
      *(undefined4 *)(iVar3 + 0x26c) = 3;
      *(undefined4 *)(iVar3 + 0x270) = 10;
      puVar2 = (undefined4 *)(iVar3 + 0x98);
      iVar3 = 8;
      do {
        *puVar2 = 0xbf800000;
        puVar2 = puVar2 + 8;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      FUN_00537ca0(2);
      return;
    case 0x4ba:
      *(undefined4 *)(iVar3 + 0x1c8) = 0x17;
      *(undefined4 *)(iVar3 + 0x1cc) = 0x17;
      *(undefined **)(iVar3 + 0x264) = &DAT_006f64c0;
      *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
      *(undefined4 *)(iVar3 + 0x26c) = 3;
      *(undefined4 *)(iVar3 + 0x270) = 10;
      puVar2 = (undefined4 *)(iVar3 + 0x98);
      iVar3 = 8;
      do {
        *puVar2 = 0xbf800000;
        puVar2 = puVar2 + 8;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      FUN_00537ca0(2);
      return;
    case 0x4be:
      *(undefined4 *)(iVar3 + 0x1c8) = 0x18;
      *(undefined4 *)(iVar3 + 0x1cc) = 0x18;
      *(undefined **)(iVar3 + 0x264) = &DAT_006f6538;
      *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
      *(undefined4 *)(iVar3 + 0x26c) = 3;
      *(undefined4 *)(iVar3 + 0x270) = 10;
      puVar2 = (undefined4 *)(iVar3 + 0x98);
      iVar3 = 8;
      do {
        *puVar2 = 0xbf800000;
        puVar2 = puVar2 + 8;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      FUN_00537ca0(2);
      return;
    }
    do {
      *puVar2 = 0xbf800000;
      puVar2 = puVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    FUN_00537ca0(2);
    return;
  }
  switch(DAT_0078a2f0) {
  default:
    goto LAB_0051f3d3;
  case 0x3ea:
    goto LAB_0051f3d3;
  case 0x3eb:
LAB_0051f3d3:
    FUN_00538890();
    break;
  case 0x3ec:
    *(undefined4 *)(iVar3 + 0x1c8) = 4;
    *(undefined4 *)(iVar3 + 0x1cc) = 4;
    *(undefined **)(iVar3 + 0x264) = &DAT_006f51d8;
    *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
    *(undefined4 *)(iVar3 + 0x26c) = 4;
    *(undefined4 *)(iVar3 + 0x270) = 10;
    puVar2 = (undefined4 *)(iVar3 + 0x98);
    iVar3 = 8;
    do {
      *puVar2 = 0xbf800000;
      puVar2 = puVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    break;
  case 0x3ed:
    *(undefined4 *)(iVar3 + 0x1c8) = 5;
    *(undefined4 *)(iVar3 + 0x1cc) = 5;
    *(undefined **)(iVar3 + 0x264) = &DAT_006f5278;
    *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
    *(undefined4 *)(iVar3 + 0x26c) = 4;
    *(undefined4 *)(iVar3 + 0x270) = 10;
    puVar2 = (undefined4 *)(iVar3 + 0x98);
    iVar3 = 8;
    do {
      *puVar2 = 0xbf800000;
      puVar2 = puVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    break;
  case 0x3ee:
    *(undefined4 *)(iVar3 + 0x26c) = 5;
    *(undefined4 *)(iVar3 + 0x1c8) = 6;
    *(undefined4 *)(iVar3 + 0x1cc) = 6;
    *(undefined **)(iVar3 + 0x264) = &DAT_006f5318;
    *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
    *(undefined4 *)(iVar3 + 0x270) = 10;
    puVar2 = (undefined4 *)(iVar3 + 0x98);
    iVar3 = 8;
    do {
      *puVar2 = 0xbf800000;
      puVar2 = puVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    break;
  case 0x3ef:
    *(undefined4 *)(iVar3 + 0x1c8) = 7;
    *(undefined4 *)(iVar3 + 0x1cc) = 7;
    *(undefined **)(iVar3 + 0x264) = &DAT_006f53e0;
    *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
    *(undefined4 *)(iVar3 + 0x26c) = 4;
    *(undefined4 *)(iVar3 + 0x270) = 10;
    puVar2 = (undefined4 *)(iVar3 + 0x98);
    iVar3 = 8;
    do {
      *puVar2 = 0xbf800000;
      puVar2 = puVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    break;
  case 0x3f0:
    *(undefined4 *)(iVar3 + 0x1c8) = 8;
    *(undefined4 *)(iVar3 + 0x1cc) = 8;
    *(undefined **)(iVar3 + 0x264) = &DAT_006f5480;
    *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
    *(undefined4 *)(iVar3 + 0x26c) = 6;
    *(undefined4 *)(iVar3 + 0x270) = 10;
    puVar2 = (undefined4 *)(iVar3 + 0x98);
    iVar3 = 8;
    do {
      *puVar2 = 0xbf800000;
      puVar2 = puVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    break;
  case 0x44e:
    *(undefined4 *)(iVar3 + 0x26c) = 5;
    *(undefined4 *)(iVar3 + 0x1c8) = 0xb;
    *(undefined4 *)(iVar3 + 0x1cc) = 0xb;
    *(undefined **)(iVar3 + 0x264) = &DAT_006f5818;
    *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
    *(undefined4 *)(iVar3 + 0x270) = 10;
    puVar2 = (undefined4 *)(iVar3 + 0x98);
    iVar3 = 8;
    do {
      *puVar2 = 0xbf800000;
      puVar2 = puVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    break;
  case 0x44f:
    *(undefined4 *)(iVar3 + 0x1c8) = 0xc;
    *(undefined4 *)(iVar3 + 0x1cc) = 0xc;
    *(undefined **)(iVar3 + 0x264) = &DAT_006f58e0;
    *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
    *(undefined4 *)(iVar3 + 0x26c) = 9;
    *(undefined4 *)(iVar3 + 0x270) = 10;
    puVar2 = (undefined4 *)(iVar3 + 0x98);
    iVar3 = 8;
    do {
      *puVar2 = 0xbf800000;
      puVar2 = puVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    break;
  case 0x450:
    *(undefined4 *)(iVar3 + 0x1c8) = 0xd;
    *(undefined4 *)(iVar3 + 0x1cc) = 0xd;
    *(undefined **)(iVar3 + 0x264) = &DAT_006f5a48;
    *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
    *(undefined4 *)(iVar3 + 0x26c) = 8;
    *(undefined4 *)(iVar3 + 0x270) = 10;
    puVar2 = (undefined4 *)(iVar3 + 0x98);
    iVar3 = 8;
    do {
      *puVar2 = 0xbf800000;
      puVar2 = puVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    break;
  case 0x451:
    *(undefined4 *)(iVar3 + 0x1c8) = 0xe;
    *(undefined4 *)(iVar3 + 0x1cc) = 0xe;
    *(undefined4 *)(iVar3 + 0x26c) = 10;
    *(undefined4 *)(iVar3 + 0x270) = 10;
    *(undefined **)(iVar3 + 0x264) = &DAT_006f5b88;
    *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
    puVar2 = (undefined4 *)(iVar3 + 0x98);
    iVar3 = 8;
    do {
      *puVar2 = 0xbf800000;
      puVar2 = puVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    break;
  case 0x452:
    *(undefined4 *)(iVar3 + 0x1c8) = 0xf;
    *(undefined4 *)(iVar3 + 0x1cc) = 0xf;
    *(undefined **)(iVar3 + 0x264) = &DAT_006f5d18;
    *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
    *(undefined4 *)(iVar3 + 0x26c) = 9;
    *(undefined4 *)(iVar3 + 0x270) = 10;
    puVar2 = (undefined4 *)(iVar3 + 0x98);
    iVar3 = 8;
    do {
      *puVar2 = 0xbf800000;
      puVar2 = puVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    break;
  case 0x453:
    *(undefined4 *)(iVar3 + 0x1c8) = 0x10;
    *(undefined4 *)(iVar3 + 0x1cc) = 0x10;
    *(undefined4 *)(iVar3 + 0x26c) = 10;
    *(undefined4 *)(iVar3 + 0x270) = 10;
    *(undefined **)(iVar3 + 0x264) = &DAT_006f5e80;
    *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
    puVar2 = (undefined4 *)(iVar3 + 0x98);
    iVar3 = 8;
    do {
      *puVar2 = 0xbf800000;
      puVar2 = puVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    break;
  case 0x454:
    *(undefined4 *)(iVar3 + 0x1c8) = 0x11;
    *(undefined4 *)(iVar3 + 0x1cc) = 0x11;
    *(undefined **)(iVar3 + 0x264) = &DAT_006f6010;
    *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
    *(undefined4 *)(iVar3 + 0x26c) = 8;
    *(undefined4 *)(iVar3 + 0x270) = 10;
    puVar2 = (undefined4 *)(iVar3 + 0x98);
    iVar3 = 8;
    do {
      *puVar2 = 0xbf800000;
      puVar2 = puVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    break;
  case 0x455:
    *(undefined4 *)(iVar3 + 0x1c8) = 0x12;
    *(undefined4 *)(iVar3 + 0x1cc) = 0x12;
    *(undefined **)(iVar3 + 0x264) = &DAT_006f6150;
    *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
    *(undefined4 *)(iVar3 + 0x26c) = 7;
    *(undefined4 *)(iVar3 + 0x270) = 10;
    puVar2 = (undefined4 *)(iVar3 + 0x98);
    iVar3 = 8;
    do {
      *puVar2 = 0xbf800000;
      puVar2 = puVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  if (DAT_006f1dd8 == 0) {
    return;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x1c4) = 2;
  FUN_00537cc0();
  return;
}


// ==== 0x51f8a0 FUN_0051f8a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0051f8a0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (DAT_006f1dd8 != 0) {
    if (*(int **)(param_1 + 0xa0) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0xa0) + 4))();
    }
    (**(code **)(**(int **)(param_1 + 0x80) + 8))();
    if (DAT_007356ac != 0) {
      FUN_00536690();
    }
    iVar3 = *(int *)(param_1 + 0x104);
    _DAT_007356dc = 0;
    if (iVar3 != 0) {
      iVar1 = (**(code **)(**(int **)(DAT_007356a8 + 0xc4) + 0x44))();
      if (iVar1 < 2) {
        iVar1 = 0;
      }
      else {
        iVar1 = iVar1 + -1;
      }
      *(int *)(iVar3 + 0x284) = iVar1;
      iVar3 = *(int *)(param_1 + 0xf8);
      if (iVar3 == 5) {
        switch(DAT_0078a2f0) {
        default:
          FUN_00538890();
          break;
        case 0x3ea:
          FUN_00538890();
          break;
        case 0x3eb:
          FUN_00538890();
          break;
        case 0x3ec:
          iVar3 = *(int *)(param_1 + 0x104);
          *(undefined4 *)(iVar3 + 0x1c8) = 4;
          *(undefined4 *)(iVar3 + 0x1cc) = 4;
          *(undefined4 *)(iVar3 + 0x26c) = 4;
          *(undefined **)(iVar3 + 0x264) = &DAT_006f51d8;
          *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
          *(undefined4 *)(iVar3 + 0x270) = 10;
          puVar2 = (undefined4 *)(iVar3 + 0x98);
          iVar3 = 8;
          do {
            *puVar2 = 0xbf800000;
            puVar2 = puVar2 + 8;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          break;
        case 0x3ed:
          iVar3 = *(int *)(param_1 + 0x104);
          *(undefined4 *)(iVar3 + 0x1c8) = 5;
          *(undefined4 *)(iVar3 + 0x1cc) = 5;
          *(undefined **)(iVar3 + 0x264) = &DAT_006f5278;
          *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
          *(undefined4 *)(iVar3 + 0x26c) = 4;
          *(undefined4 *)(iVar3 + 0x270) = 10;
          puVar2 = (undefined4 *)(iVar3 + 0x98);
          iVar3 = 8;
          do {
            *puVar2 = 0xbf800000;
            puVar2 = puVar2 + 8;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          break;
        case 0x3ee:
          iVar3 = *(int *)(param_1 + 0x104);
          *(undefined4 *)(iVar3 + 0x26c) = 5;
          *(undefined4 *)(iVar3 + 0x1c8) = 6;
          *(undefined4 *)(iVar3 + 0x1cc) = 6;
          *(undefined **)(iVar3 + 0x264) = &DAT_006f5318;
          *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
          *(undefined4 *)(iVar3 + 0x270) = 10;
          puVar2 = (undefined4 *)(iVar3 + 0x98);
          iVar3 = 8;
          do {
            *puVar2 = 0xbf800000;
            puVar2 = puVar2 + 8;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          break;
        case 0x3ef:
          iVar3 = *(int *)(param_1 + 0x104);
          *(undefined4 *)(iVar3 + 0x1c8) = 7;
          *(undefined4 *)(iVar3 + 0x1cc) = 7;
          *(undefined **)(iVar3 + 0x264) = &DAT_006f53e0;
          *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
          *(undefined4 *)(iVar3 + 0x26c) = 4;
          *(undefined4 *)(iVar3 + 0x270) = 10;
          puVar2 = (undefined4 *)(iVar3 + 0x98);
          iVar3 = 8;
          do {
            *puVar2 = 0xbf800000;
            puVar2 = puVar2 + 8;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          break;
        case 0x3f0:
          iVar3 = *(int *)(param_1 + 0x104);
          iVar1 = 8;
          *(undefined4 *)(iVar3 + 0x1c8) = 8;
          *(undefined4 *)(iVar3 + 0x1cc) = 8;
          *(undefined **)(iVar3 + 0x264) = &DAT_006f5480;
          *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
          *(undefined4 *)(iVar3 + 0x26c) = 6;
          *(undefined4 *)(iVar3 + 0x270) = 10;
          puVar2 = (undefined4 *)(iVar3 + 0x98);
          do {
            *puVar2 = 0xbf800000;
            puVar2 = puVar2 + 8;
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
          break;
        case 0x44e:
          iVar3 = *(int *)(param_1 + 0x104);
          *(undefined4 *)(iVar3 + 0x26c) = 5;
          *(undefined4 *)(iVar3 + 0x1c8) = 0xb;
          *(undefined4 *)(iVar3 + 0x1cc) = 0xb;
          *(undefined **)(iVar3 + 0x264) = &DAT_006f5818;
          *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
          *(undefined4 *)(iVar3 + 0x270) = 10;
          puVar2 = (undefined4 *)(iVar3 + 0x98);
          iVar3 = 8;
          do {
            *puVar2 = 0xbf800000;
            puVar2 = puVar2 + 8;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          break;
        case 0x44f:
          iVar3 = *(int *)(param_1 + 0x104);
          *(undefined4 *)(iVar3 + 0x1c8) = 0xc;
          *(undefined4 *)(iVar3 + 0x1cc) = 0xc;
          *(undefined **)(iVar3 + 0x264) = &DAT_006f58e0;
          *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
          *(undefined4 *)(iVar3 + 0x26c) = 9;
          *(undefined4 *)(iVar3 + 0x270) = 10;
          puVar2 = (undefined4 *)(iVar3 + 0x98);
          iVar3 = 8;
          do {
            *puVar2 = 0xbf800000;
            puVar2 = puVar2 + 8;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          break;
        case 0x450:
          iVar3 = *(int *)(param_1 + 0x104);
          *(undefined4 *)(iVar3 + 0x1c8) = 0xd;
          *(undefined4 *)(iVar3 + 0x1cc) = 0xd;
          iVar1 = 8;
          *(undefined **)(iVar3 + 0x264) = &DAT_006f5a48;
          *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
          *(undefined4 *)(iVar3 + 0x26c) = 8;
          *(undefined4 *)(iVar3 + 0x270) = 10;
          puVar2 = (undefined4 *)(iVar3 + 0x98);
          do {
            *puVar2 = 0xbf800000;
            puVar2 = puVar2 + 8;
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
          break;
        case 0x451:
          iVar3 = *(int *)(param_1 + 0x104);
          *(undefined4 *)(iVar3 + 0x1c8) = 0xe;
          *(undefined4 *)(iVar3 + 0x1cc) = 0xe;
          *(undefined4 *)(iVar3 + 0x26c) = 10;
          *(undefined4 *)(iVar3 + 0x270) = 10;
          *(undefined **)(iVar3 + 0x264) = &DAT_006f5b88;
          *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
          puVar2 = (undefined4 *)(iVar3 + 0x98);
          iVar3 = 8;
          do {
            *puVar2 = 0xbf800000;
            puVar2 = puVar2 + 8;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          break;
        case 0x452:
          iVar3 = *(int *)(param_1 + 0x104);
          *(undefined4 *)(iVar3 + 0x1c8) = 0xf;
          *(undefined4 *)(iVar3 + 0x1cc) = 0xf;
          *(undefined **)(iVar3 + 0x264) = &DAT_006f5d18;
          *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
          *(undefined4 *)(iVar3 + 0x26c) = 9;
          *(undefined4 *)(iVar3 + 0x270) = 10;
          puVar2 = (undefined4 *)(iVar3 + 0x98);
          iVar3 = 8;
          do {
            *puVar2 = 0xbf800000;
            puVar2 = puVar2 + 8;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          break;
        case 0x453:
          iVar3 = *(int *)(param_1 + 0x104);
          *(undefined4 *)(iVar3 + 0x1c8) = 0x10;
          *(undefined4 *)(iVar3 + 0x1cc) = 0x10;
          *(undefined4 *)(iVar3 + 0x26c) = 10;
          *(undefined4 *)(iVar3 + 0x270) = 10;
          *(undefined **)(iVar3 + 0x264) = &DAT_006f5e80;
          *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
          puVar2 = (undefined4 *)(iVar3 + 0x98);
          iVar3 = 8;
          do {
            *puVar2 = 0xbf800000;
            puVar2 = puVar2 + 8;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          break;
        case 0x454:
          iVar3 = *(int *)(param_1 + 0x104);
          *(undefined4 *)(iVar3 + 0x1c8) = 0x11;
          *(undefined4 *)(iVar3 + 0x1cc) = 0x11;
          iVar1 = 8;
          *(undefined **)(iVar3 + 0x264) = &DAT_006f6010;
          *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
          *(undefined4 *)(iVar3 + 0x26c) = 8;
          *(undefined4 *)(iVar3 + 0x270) = 10;
          puVar2 = (undefined4 *)(iVar3 + 0x98);
          do {
            *puVar2 = 0xbf800000;
            puVar2 = puVar2 + 8;
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
          break;
        case 0x455:
          iVar3 = *(int *)(param_1 + 0x104);
          *(undefined4 *)(iVar3 + 0x1c8) = 0x12;
          *(undefined4 *)(iVar3 + 0x1cc) = 0x12;
          *(undefined **)(iVar3 + 0x264) = &DAT_006f6150;
          *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
          *(undefined4 *)(iVar3 + 0x26c) = 7;
          *(undefined4 *)(iVar3 + 0x270) = 10;
          puVar2 = (undefined4 *)(iVar3 + 0x98);
          iVar3 = 8;
          do {
            *puVar2 = 0xbf800000;
            puVar2 = puVar2 + 8;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
      }
      else {
        if (((iVar3 == 2) && (0x4af < DAT_0078a2f0)) && (DAT_0078a2f0 < 0x514)) {
          *(undefined1 *)(param_1 + 0x71) = 0;
          switch(DAT_0078a2f0) {
          case 0x4b1:
            iVar3 = *(int *)(param_1 + 0x104);
            *(undefined4 *)(iVar3 + 0x1c8) = 0x13;
            *(undefined4 *)(iVar3 + 0x1cc) = 0x13;
            *(undefined **)(iVar3 + 0x264) = &DAT_006f6268;
            *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
            *(undefined4 *)(iVar3 + 0x26c) = 3;
            *(undefined4 *)(iVar3 + 0x270) = 10;
            puVar2 = (undefined4 *)(iVar3 + 0x98);
            iVar3 = 8;
            do {
              *puVar2 = 0xbf800000;
              puVar2 = puVar2 + 8;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
            FUN_00537ca0(2);
            FUN_00533140();
            return;
          case 0x4b2:
            iVar3 = *(int *)(param_1 + 0x104);
            *(undefined4 *)(iVar3 + 0x1c8) = 0x14;
            *(undefined4 *)(iVar3 + 0x1cc) = 0x14;
            *(undefined **)(iVar3 + 0x264) = &DAT_006f62e0;
            *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
            *(undefined4 *)(iVar3 + 0x26c) = 3;
            *(undefined4 *)(iVar3 + 0x270) = 10;
            puVar2 = (undefined4 *)(iVar3 + 0x98);
            iVar3 = 8;
            do {
              *puVar2 = 0xbf800000;
              puVar2 = puVar2 + 8;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
            FUN_00537ca0(2);
            FUN_00533140();
            return;
          default:
            iVar3 = *(int *)(param_1 + 0x104);
            *(undefined4 *)(iVar3 + 0x1c8) = 0x19;
            *(undefined4 *)(iVar3 + 0x1cc) = 0x19;
            *(undefined4 *)(iVar3 + 0x264) = 0;
            *(undefined4 *)(iVar3 + 0x268) = 0;
            *(undefined4 *)(iVar3 + 0x26c) = 0;
            *(undefined4 *)(iVar3 + 0x270) = 0;
            puVar2 = (undefined4 *)(iVar3 + 0x98);
            iVar3 = 8;
            do {
              *puVar2 = 0xbf800000;
              puVar2 = puVar2 + 8;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
            FUN_00537ca0(2);
            FUN_00533140();
            return;
          case 0x4b6:
            iVar3 = *(int *)(param_1 + 0x104);
            *(undefined4 *)(iVar3 + 0x1c8) = 0x15;
            *(undefined4 *)(iVar3 + 0x1cc) = 0x15;
            *(undefined **)(iVar3 + 0x264) = &DAT_006f63d0;
            *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
            *(undefined4 *)(iVar3 + 0x26c) = 3;
            *(undefined4 *)(iVar3 + 0x270) = 10;
            puVar2 = (undefined4 *)(iVar3 + 0x98);
            iVar3 = 8;
            break;
          case 0x4b7:
            iVar3 = *(int *)(param_1 + 0x104);
            *(undefined4 *)(iVar3 + 0x1c8) = 0x16;
            *(undefined4 *)(iVar3 + 0x1cc) = 0x16;
            *(undefined **)(iVar3 + 0x264) = &DAT_006f6448;
            *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
            *(undefined4 *)(iVar3 + 0x26c) = 3;
            *(undefined4 *)(iVar3 + 0x270) = 10;
            puVar2 = (undefined4 *)(iVar3 + 0x98);
            iVar3 = 8;
            do {
              *puVar2 = 0xbf800000;
              puVar2 = puVar2 + 8;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
            FUN_00537ca0(2);
            FUN_00533140();
            return;
          case 0x4ba:
            iVar3 = *(int *)(param_1 + 0x104);
            *(undefined4 *)(iVar3 + 0x1c8) = 0x17;
            *(undefined4 *)(iVar3 + 0x1cc) = 0x17;
            *(undefined **)(iVar3 + 0x264) = &DAT_006f64c0;
            *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
            *(undefined4 *)(iVar3 + 0x26c) = 3;
            *(undefined4 *)(iVar3 + 0x270) = 10;
            puVar2 = (undefined4 *)(iVar3 + 0x98);
            iVar3 = 8;
            do {
              *puVar2 = 0xbf800000;
              puVar2 = puVar2 + 8;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
            FUN_00537ca0(2);
            FUN_00533140();
            return;
          case 0x4be:
            iVar3 = *(int *)(param_1 + 0x104);
            *(undefined4 *)(iVar3 + 0x1c8) = 0x18;
            *(undefined4 *)(iVar3 + 0x1cc) = 0x18;
            *(undefined **)(iVar3 + 0x264) = &DAT_006f6538;
            *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
            *(undefined4 *)(iVar3 + 0x26c) = 3;
            *(undefined4 *)(iVar3 + 0x270) = 10;
            puVar2 = (undefined4 *)(iVar3 + 0x98);
            iVar3 = 8;
            do {
              *puVar2 = 0xbf800000;
              puVar2 = puVar2 + 8;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
            FUN_00537ca0(2);
            FUN_00533140();
            return;
          }
          do {
            *puVar2 = 0xbf800000;
            puVar2 = puVar2 + 8;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          FUN_00537ca0(2);
          FUN_00533140();
          return;
        }
        if (iVar3 == 3) {
          iVar3 = *(int *)(param_1 + 0x104);
          *(undefined4 *)(iVar3 + 0x1c8) = 0x1a;
          *(undefined4 *)(iVar3 + 0x1cc) = 0x1a;
          *(undefined **)(iVar3 + 0x264) = &DAT_006f5660;
          *(undefined **)(iVar3 + 0x268) = &DAT_006f6918;
          *(undefined4 *)(iVar3 + 0x26c) = 0xb;
          *(undefined4 *)(iVar3 + 0x270) = 10;
          puVar2 = (undefined4 *)(iVar3 + 0x98);
          iVar3 = 8;
          do {
            *puVar2 = 0xbf800000;
            puVar2 = puVar2 + 8;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
      }
      if (DAT_006f1dd8 != 0) {
        *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x1c4) = 2;
        FUN_00537cc0();
      }
    }
    FUN_00533140();
  }
  return;
}


// ==== 0x520320 FUN_00520320

undefined4 FUN_00520320(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0:
    return 0xf;
  case 1:
    return 5;
  case 2:
    return 0x11;
  case 3:
    return 6;
  case 4:
    return 10;
  case 5:
    return 0xe;
  case 6:
    return 4;
  case 7:
    return 1;
  case 8:
    return 0xd;
  case 9:
    return 0;
  case 10:
    return 2;
  case 0xb:
    return 3;
  case 0xc:
    return 7;
  case 0xd:
    return 8;
  case 0xe:
    return 9;
  case 0xf:
    return 0xb;
  case 0x10:
    return 0xc;
  case 0x11:
    return 0x10;
  case 0x12:
    return 0x12;
  case 0x13:
    return 0x13;
  default:
    return 0xffffffff;
  }
}


// ==== 0x520430 EAXSound::SetTrainObjectPositions

/* [canon] audio med (ghidra-canon+nfsug) docs/re/sound.md */

void __fastcall EAXSound__SetTrainObjectPositions(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_EAX;
  
  iVar3 = *(int *)(in_EAX + 0x104);
  if (iVar3 != 0) {
    uVar1 = param_1[1];
    uVar2 = param_1[2];
    *(undefined4 *)(iVar3 + 0x230) = *param_1;
    *(undefined4 *)(iVar3 + 0x234) = uVar1;
    *(undefined4 *)(iVar3 + 0x238) = uVar2;
  }
  return;
}


// ==== 0x520460 FUN_00520460

void FUN_00520460(void)

{
  void *pvVar1;
  
  pvVar1 = _malloc(0x570);
  if (pvVar1 != (void *)0x0) {
    DAT_007356a8 = EAXSound__EAXSound();
    EAXSound__InitializeDriver();
    return;
  }
  DAT_007356a8 = 0;
  EAXSound__InitializeDriver();
  return;
}


// ==== 0x5204a0 EAXSound_base_class_scalar_deleting_destructor__vtable_0x6bf5a8_

/* [canon] audio med (ghidra-canon) docs/re/sound.md */

undefined4 * __thiscall
EAXSound_base_class_scalar_deleting_destructor__vtable_0x6bf5a8_(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_EAXSound_base_class_scalar_deleting_destructor__vtable_0x6bf5a8__006bf5a8;
  if ((void *)param_1[1] != (void *)0x0) {
    _free((void *)param_1[1]);
    param_1[1] = 0;
  }
  *(undefined1 *)(param_1 + 4) = 0;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5204e0 EAXSound::FreeRacerSlotBuffer

/* [canon] audio low (ghidra-canon) docs/re/sound.md */

void __fastcall EAXSound__FreeRacerSlotBuffer(int param_1)

{
  *(undefined1 *)(param_1 + 0x10) = 0;
  if (*(void **)(param_1 + 4) != (void *)0x0) {
    _free(*(void **)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}


// ==== 0x520500 EAXSound::AllocRacerSlotBuffer

/* [canon] audio low (ghidra-canon) docs/re/sound.md */

void __fastcall EAXSound__AllocRacerSlotBuffer(int param_1)

{
  void *pvVar1;
  
  pvVar1 = _malloc(400);
  *(void **)(param_1 + 4) = pvVar1;
  *(undefined4 *)((int)pvVar1 + 0x68) = 0;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x70) = 0;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0xf0) = 0;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x168) = 0;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x6c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x74) = 0;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0xf4) = 0;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x16c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0xf8) = 0;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x170) = 0;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0xfc) = 0;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x174) = 0;
  return;
}


// ==== 0x520580 EAXSound::BuildRacerSlots

/* [canon] audio low (ghidra-canon) docs/re/runtime.md */

void __fastcall EAXSound__BuildRacerSlots(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  float10 fVar5;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  LARGE_INTEGER LStack_8;
  
  if (DAT_006f1dd8 != 0) {
    iStack_10 = 0;
    iStack_14 = 0;
    iVar2 = 0;
    LStack_8.s.LowPart = 0x140;
    iStack_c = 0x168;
    iVar4 = 0x104;
    do {
      iVar1 = *(int *)(DAT_007356a8 + -0x7c + LStack_8.s.LowPart);
      if ((((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0x234), iVar1 != 0)) &&
          (*(int *)(*(int *)(iVar1 + 0x14) + 4) == 1)) &&
         (*(char *)(*(int *)(iVar1 + 0x14) + 0x734) == '\0')) {
        *(int *)(iStack_c + *(int *)(param_1 + 4)) = iVar1;
        iStack_14 = iStack_14 + 1;
        iStack_c = iStack_c + 4;
        *(undefined4 *)(iVar2 + 0x100 + *(int *)(param_1 + 4)) = 0;
        *(undefined4 *)(iVar2 + 0x120 + *(int *)(param_1 + 4)) = 0;
        *(undefined4 *)(iVar2 + 0x104 + *(int *)(param_1 + 4)) = 0;
        *(undefined4 *)(iVar2 + 0x124 + *(int *)(param_1 + 4)) = 0;
        *(undefined4 *)(LStack_8.s.LowPart + *(int *)(param_1 + 4)) = 0;
      }
      *(undefined4 *)(iVar4 + -4 + *(int *)(param_1 + 4)) = 0;
      *(undefined4 *)(iVar4 + *(int *)(param_1 + 4)) = 0;
      LStack_8.s.LowPart = LStack_8.s.LowPart + 4;
      iVar4 = iVar4 + 8;
      iVar2 = iVar2 + 8;
    } while (iVar4 < 0x114);
    if (iStack_14 == 2) {
      *(undefined4 *)(*(int *)(param_1 + 4) + 0x188) = 1;
    }
    else {
      *(undefined4 *)(*(int *)(param_1 + 4) + 0x188) = 0;
    }
    iVar4 = 0;
    LStack_8.s.LowPart = 0x140;
    iVar2 = 0x104;
    do {
      iVar1 = *(int *)(DAT_007356a8 + -0x70 + LStack_8.s.LowPart);
      if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0x234), iVar1 != 0)) {
        if ((*(int *)(*(int *)(iVar1 + 0x14) + 4) != 1) ||
           (*(char *)(*(int *)(iVar1 + 0x14) + 0x734) != '\0')) {
          *(int *)(*(int *)(param_1 + 4) + 0x168 + (iStack_14 + iStack_10) * 4) = iVar1;
          iStack_10 = iStack_10 + 1;
        }
        *(undefined4 *)(*(int *)(param_1 + 4) + 0x100 + iVar4) = 0;
        *(undefined4 *)(iVar4 + 0x120 + *(int *)(param_1 + 4)) = 0;
        *(undefined4 *)(iVar4 + 0x104 + *(int *)(param_1 + 4)) = 0;
        *(undefined4 *)(iVar4 + 0x124 + *(int *)(param_1 + 4)) = 0;
        *(undefined4 *)(LStack_8.s.LowPart + *(int *)(param_1 + 4)) = 0;
      }
      *(undefined4 *)(iVar2 + -4 + *(int *)(param_1 + 4)) = 0;
      *(undefined4 *)(iVar2 + *(int *)(param_1 + 4)) = 0;
      LStack_8.s.LowPart = LStack_8.s.LowPart + 4;
      iVar2 = iVar2 + 8;
      iVar4 = iVar4 + 8;
    } while (iVar2 < 0x124);
    iVar2 = 0x168;
    do {
      if (*(int *)(iVar2 + *(int *)(param_1 + 4)) != 0) {
        fVar5 = (float10)RideInfo__GetTheoreticalTopSpeed();
        *(float *)(*(int *)(param_1 + 4) + -0x78 + iVar2) = (float)fVar5;
      }
      iVar2 = iVar2 + 4;
    } while (iVar2 < 0x178);
    *(undefined4 *)(*(int *)(param_1 + 4) + 0x178) = 0;
    QueryPerformanceCounter(&LStack_8);
    uVar3 = __allshr();
    *(undefined4 *)(*(int *)(param_1 + 4) + 0x17c) = uVar3;
    *(undefined1 *)(param_1 + 0x10) = 1;
  }
  return;
}


// ==== 0x52058d FUN_0052058d

void __fastcall FUN_0052058d(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int unaff_EBX;
  int iVar6;
  bool in_ZF;
  float10 fVar7;
  int iStack0000000c;
  undefined4 uStack00000010;
  
  if (!in_ZF) {
    iVar2 = 0;
    uStack00000010 = 0x140;
    iStack0000000c = 0x168;
    iVar4 = 0x104;
    iVar6 = unaff_EBX;
    do {
      iVar5 = *(int *)(DAT_007356a8 + -0x7c + uStack00000010);
      if ((((iVar5 != unaff_EBX) && (iVar5 = *(int *)(iVar5 + 0x234), iVar5 != unaff_EBX)) &&
          (*(int *)(*(int *)(iVar5 + 0x14) + 4) == 1)) &&
         (*(char *)(*(int *)(iVar5 + 0x14) + 0x734) == (char)unaff_EBX)) {
        *(int *)(iStack0000000c + *(int *)(param_1 + 4)) = iVar5;
        iVar6 = iVar6 + 1;
        iStack0000000c = iStack0000000c + 4;
        *(int *)(iVar2 + 0x100 + *(int *)(param_1 + 4)) = unaff_EBX;
        *(int *)(iVar2 + 0x120 + *(int *)(param_1 + 4)) = unaff_EBX;
        *(int *)(iVar2 + 0x104 + *(int *)(param_1 + 4)) = unaff_EBX;
        *(int *)(iVar2 + 0x124 + *(int *)(param_1 + 4)) = unaff_EBX;
        *(int *)(uStack00000010 + *(int *)(param_1 + 4)) = unaff_EBX;
      }
      *(int *)(iVar4 + -4 + *(int *)(param_1 + 4)) = unaff_EBX;
      *(int *)(iVar4 + *(int *)(param_1 + 4)) = unaff_EBX;
      uStack00000010 = uStack00000010 + 4;
      iVar4 = iVar4 + 8;
      iVar2 = iVar2 + 8;
    } while (iVar4 < 0x114);
    if (iVar6 == 2) {
      *(undefined4 *)(*(int *)(param_1 + 4) + 0x188) = 1;
    }
    else {
      *(int *)(*(int *)(param_1 + 4) + 0x188) = unaff_EBX;
    }
    iVar5 = 0;
    uStack00000010 = 0x140;
    iVar4 = 0x104;
    iVar2 = unaff_EBX;
    do {
      iVar1 = *(int *)(DAT_007356a8 + -0x70 + uStack00000010);
      if ((iVar1 != unaff_EBX) && (iVar1 = *(int *)(iVar1 + 0x234), iVar1 != unaff_EBX)) {
        if ((*(int *)(*(int *)(iVar1 + 0x14) + 4) != 1) ||
           (*(char *)(*(int *)(iVar1 + 0x14) + 0x734) != (char)unaff_EBX)) {
          *(int *)(*(int *)(param_1 + 4) + 0x168 + (iVar6 + iVar2) * 4) = iVar1;
          iVar2 = iVar2 + 1;
        }
        *(int *)(*(int *)(param_1 + 4) + 0x100 + iVar5) = unaff_EBX;
        *(int *)(iVar5 + 0x120 + *(int *)(param_1 + 4)) = unaff_EBX;
        *(int *)(iVar5 + 0x104 + *(int *)(param_1 + 4)) = unaff_EBX;
        *(int *)(iVar5 + 0x124 + *(int *)(param_1 + 4)) = unaff_EBX;
        *(int *)(uStack00000010 + *(int *)(param_1 + 4)) = unaff_EBX;
      }
      *(int *)(iVar4 + -4 + *(int *)(param_1 + 4)) = unaff_EBX;
      *(int *)(iVar4 + *(int *)(param_1 + 4)) = unaff_EBX;
      uStack00000010 = uStack00000010 + 4;
      iVar4 = iVar4 + 8;
      iVar5 = iVar5 + 8;
    } while (iVar4 < 0x124);
    iVar6 = 0x168;
    do {
      if (*(int *)(iVar6 + *(int *)(param_1 + 4)) != unaff_EBX) {
        fVar7 = (float10)RideInfo__GetTheoreticalTopSpeed();
        *(float *)(*(int *)(param_1 + 4) + -0x78 + iVar6) = (float)fVar7;
      }
      iVar6 = iVar6 + 4;
    } while (iVar6 < 0x178);
    *(int *)(*(int *)(param_1 + 4) + 0x178) = unaff_EBX;
    QueryPerformanceCounter((LARGE_INTEGER *)&stack0x00000010);
    uVar3 = __allshr();
    *(undefined4 *)(*(int *)(param_1 + 4) + 0x17c) = uVar3;
    *(undefined1 *)(param_1 + 0x10) = 1;
  }
  return;
}


// ==== 0x520790 FUN_00520790

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00520790(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int in_EAX;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  float10 fVar11;
  
  if (DAT_006f1dd8 == 0) {
    return;
  }
  if (*(char *)(in_EAX + 0x10) == '\0') {
    return;
  }
  iVar10 = *(int *)(in_EAX + 4);
  if (*(int *)(iVar10 + 0x168) == 0) {
    return;
  }
  FUN_005648c0();
  fVar11 = (float10)FUN_005648f0();
  *(float *)(iVar10 + 0x178) = (float)fVar11;
  uVar7 = FUN_005648c0();
  *(undefined4 *)(*(int *)(in_EAX + 4) + 0x17c) = uVar7;
  iVar10 = *(int *)(in_EAX + 4);
  if ((*(int *)(iVar10 + 0x168) != 0) &&
     (iVar2 = *(int *)(*(int *)(iVar10 + 0x168) + 0x18), iVar2 != 0)) {
    iVar2 = *(int *)(iVar2 + 0x27c);
    if (iVar2 == 0) {
      *(undefined4 *)(iVar10 + 0x60) = DAT_00740500;
    }
    else {
      *(undefined4 *)(iVar10 + 0x60) = *(undefined4 *)(iVar2 + 0x1c);
    }
    iVar10 = *(int *)(in_EAX + 4);
    iVar2 = *(int *)(iVar10 + 0x60);
    uVar7 = *(undefined4 *)(iVar2 + 0x44);
    uVar1 = *(undefined4 *)(iVar2 + 0x48);
    *(undefined4 *)(iVar10 + 0xd0) = *(undefined4 *)(iVar2 + 0x40);
    *(undefined4 *)(iVar10 + 0xd4) = uVar7;
    *(undefined4 *)(iVar10 + 0xd8) = uVar1;
  }
  *(undefined4 *)(in_EAX + 8) = 0;
  iVar10 = 0;
  do {
    iVar2 = *(int *)(*(int *)(in_EAX + 4) + 0x168 + iVar10 * 4);
    if (iVar2 != 0) {
      iVar2 = *(int *)(iVar2 + 0x1c);
      if (iVar2 != 0) {
        *(int *)(*(int *)(in_EAX + 4) + 0x158 + iVar10 * 4) = (int)*(char *)(iVar2 + 10);
      }
      iVar2 = *(int *)(in_EAX + 4);
      iVar3 = *(int *)(iVar2 + 0x168 + iVar10 * 4);
      uVar7 = *(undefined4 *)(iVar3 + 0x68);
      uVar1 = *(undefined4 *)(iVar3 + 0x60);
      iVar8 = (iVar10 + 9) * 0x10;
      *(undefined4 *)(iVar8 + 4 + iVar2) = *(undefined4 *)(iVar3 + 100);
      puVar9 = (undefined4 *)(iVar8 + iVar2);
      *puVar9 = uVar1;
      puVar9[2] = uVar7;
      iVar2 = *(int *)(in_EAX + 4);
      *(float *)(iVar2 + 0x140 + iVar10 * 4) =
           *(float *)(*(int *)(iVar2 + 0x168 + iVar10 * 4) + 0x3d4) /
           *(float *)(iVar2 + 0xf0 + iVar10 * 4);
    }
    if (_K_ONE < *(float *)(*(int *)(in_EAX + 4) + 0x140 + iVar10 * 4)) {
      *(undefined4 *)(*(int *)(in_EAX + 4) + 0x140 + iVar10 * 4) = 0x3f800000;
    }
    if (iVar10 == 0) {
      *(undefined4 *)(*(int *)(in_EAX + 4) + 0x100) = 0;
      *(undefined4 *)(*(int *)(in_EAX + 4) + 0x120) = 0;
    }
    else {
      iVar2 = *(int *)(in_EAX + 4);
      iVar3 = *(int *)(iVar2 + 0x168 + iVar10 * 4);
      if (iVar3 == 0) {
        *(undefined4 *)(iVar2 + 0x100 + iVar10 * 8) = 0x51ba43b7;
        *(undefined4 *)(*(int *)(in_EAX + 4) + 0x120 + iVar10 * 8) = 0;
      }
      else {
        iVar8 = *(int *)(iVar2 + 0x168);
        fVar4 = *(float *)(iVar8 + 0x60) - *(float *)(iVar3 + 0x60);
        fVar6 = *(float *)(iVar8 + 100) - *(float *)(iVar3 + 100);
        fVar5 = *(float *)(iVar8 + 0x68) - *(float *)(iVar3 + 0x68);
        *(float *)(iVar2 + 0x100 + iVar10 * 8) = SQRT(fVar5 * fVar5 + fVar6 * fVar6 + fVar4 * fVar4)
        ;
        iVar2 = *(int *)(in_EAX + 4);
        *(float *)(iVar2 + 0x120 + iVar10 * 8) =
             *(float *)(*(int *)(iVar2 + 0x168) + 0x3d4) -
             *(float *)(*(int *)(iVar2 + 0x168 + iVar10 * 4) + 0x3d4);
      }
    }
    iVar10 = iVar10 + 1;
  } while (iVar10 < 4);
  iVar10 = *(int *)(in_EAX + 4);
  if (*(int *)(iVar10 + 0x188) == 1) {
    if (*(int *)(iVar10 + 0x15c) < *(int *)(iVar10 + 0x158)) {
      *(undefined4 *)(in_EAX + 8) = 1;
    }
    iVar2 = *(int *)(*(int *)(*(int *)(iVar10 + 0x16c) + 0x18) + 0x27c);
    if (iVar2 == 0) {
      *(undefined4 *)(iVar10 + 100) = DAT_00740560;
    }
    else {
      *(undefined4 *)(iVar10 + 100) = *(undefined4 *)(iVar2 + 0x1c);
    }
    iVar10 = *(int *)(in_EAX + 4);
    iVar2 = *(int *)(iVar10 + 100);
    uVar7 = *(undefined4 *)(iVar2 + 0x44);
    uVar1 = *(undefined4 *)(iVar2 + 0x48);
    *(undefined4 *)(iVar10 + 0xe0) = *(undefined4 *)(iVar2 + 0x40);
    *(undefined4 *)(iVar10 + 0xe4) = uVar7;
    *(undefined4 *)(iVar10 + 0xe8) = uVar1;
    iVar10 = 0;
    do {
      if (iVar10 == 1) {
        *(undefined4 *)(*(int *)(in_EAX + 4) + 0x10c) = 0;
        *(undefined4 *)(*(int *)(in_EAX + 4) + 300) = 0;
      }
      else {
        iVar2 = *(int *)(in_EAX + 4);
        iVar3 = *(int *)(iVar2 + 0x168 + iVar10 * 4);
        if (iVar3 == 0) {
          *(undefined4 *)(iVar2 + 0x104 + iVar10 * 8) = 0xd1ba43b7;
        }
        else {
          iVar8 = *(int *)(iVar2 + 0x16c);
          fVar4 = *(float *)(iVar8 + 0x60) - *(float *)(iVar3 + 0x60);
          fVar6 = *(float *)(iVar8 + 100) - *(float *)(iVar3 + 100);
          fVar5 = *(float *)(iVar8 + 0x68) - *(float *)(iVar3 + 0x68);
          *(float *)(iVar2 + 0x104 + iVar10 * 8) =
               SQRT(fVar5 * fVar5 + fVar6 * fVar6 + fVar4 * fVar4);
          iVar2 = *(int *)(in_EAX + 4);
          *(float *)(iVar2 + 0x124 + iVar10 * 8) =
               *(float *)(*(int *)(iVar2 + 0x16c) + 0x3d4) -
               *(float *)(*(int *)(iVar2 + 0x168 + iVar10 * 4) + 0x3d4);
        }
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < 4);
    iVar10 = *(int *)(in_EAX + 4);
    if (*(int *)(iVar10 + 0x15c) <= *(int *)(iVar10 + 0x158)) {
      *(undefined4 *)(iVar10 + 0x7c) = *(undefined4 *)(iVar10 + 100);
      goto LAB_00520aa4;
    }
  }
  *(undefined4 *)(iVar10 + 0x7c) = *(undefined4 *)(iVar10 + 0x60);
LAB_00520aa4:
  iVar10 = *(int *)(in_EAX + 4);
  if (*(int *)(iVar10 + 0x7c) != *(int *)(iVar10 + 0x78)) {
    iVar2 = *(int *)(*(int *)(iVar10 + 0x168 + *(int *)(in_EAX + 8) * 4) + 0x18);
    if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0x27c), iVar2 != 0)) {
      *(undefined4 *)(iVar10 + 0x84) = *(undefined4 *)(iVar2 + 0xc);
    }
    *(undefined4 *)(*(int *)(in_EAX + 4) + 0x78) = *(undefined4 *)(*(int *)(in_EAX + 4) + 0x7c);
  }
  return;
}


// ==== 0x520ae0 FUN_00520ae0

void FUN_00520ae0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int unaff_ESI;
  LARGE_INTEGER local_8;
  
  QueryPerformanceCounter(&local_8);
  uVar2 = __allshr();
  *(undefined4 *)(unaff_ESI + 0x94) = uVar2;
  *(undefined4 *)(unaff_ESI + 0x90) = 1;
  local_8.s.LowPart = _ftol_nocw();
  uVar2 = _ftol_nocw();
  piVar1 = *(int **)(unaff_ESI + 0x8c);
  *(undefined4 *)(unaff_ESI + 0x98) = uVar2;
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_8);
    Mutex__Lock();
    (**(code **)(*(int *)local_8.s.LowPart + 4))(piVar1);
    Mutex__Unlock();
    *(undefined4 *)(unaff_ESI + 0x8c) = 0;
  }
  return;
}


// ==== 0x520b90 EAXSound::UpdateLoopedMusic__FE_looped_music_Csis_class_FEDriveOn_

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] audio med (ghidra) docs/re/sound.md */

void __fastcall EAXSound__UpdateLoopedMusic__FE_looped_music_Csis_class_FEDriveOn_(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *local_18;
  LARGE_INTEGER local_14;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684e2b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  QueryPerformanceCounter(&local_14);
  uVar2 = DAT_007349c8;
  iVar3 = __allshr();
  local_18 = (int *)(iVar3 - *(int *)(param_1 + 0x94));
  if ((int)local_18 < 0) {
    local_18 = (int *)0x0;
  }
  local_14.s.LowPart = 1 << ((byte)uVar2 & 0x1f);
  local_18 = (int *)((float)(int)local_14.s.LowPart * (float)(int)local_18 * _DAT_007301d0);
  if (*(int *)(param_1 + 0x90) == 1) {
    if ((float)local_18 < 3160.0) {
      ExceptionList = local_c;
      return;
    }
    iVar3 = *(int *)(param_1 + 0x8c);
    if (iVar3 == 0) {
      piVar4 = (int *)FUN_005256f0(0x14);
      local_4 = 0;
      local_14.s.LowPart = (DWORD)piVar4;
      if (piVar4 == (int *)0x0) {
        local_4 = 0xffffffff;
        *(undefined4 *)(param_1 + 0x8c) = 0;
      }
      else {
        iVar3 = *(int *)(param_1 + 0x98);
        piVar1 = piVar4 + 1;
        *piVar1 = 0x32;
        if (iVar3 < 0) {
          iVar3 = 0;
        }
        else if (0x7fff < iVar3) {
          iVar3 = 0x7fff;
        }
        piVar4[2] = iVar3;
        piVar4[3] = 0x1000;
        piVar4[4] = 0;
        iVar3 = Csis__Class__CreateInstance(&DAT_007441f8,piVar1,piVar4);
        if (iVar3 < 0) {
          Csis__ClassHandle__Set(&PTR_s_FEDriveOn_006f81a8);
          Csis__Class__CreateInstance(&DAT_007441f8,piVar1,piVar4);
        }
        local_4 = 0xffffffff;
        *(int **)(param_1 + 0x8c) = piVar4;
      }
    }
    else {
      if (*(char *)(DAT_007356a8 + 0x84) == '\0') {
        iVar5 = *(int *)(param_1 + 0x98);
        if (iVar5 < 0) {
          iVar5 = 0;
        }
        else if (0x7fff < iVar5) {
          iVar5 = 0x7fff;
        }
        *(int *)(iVar3 + 8) = iVar5;
      }
      else {
        *(undefined4 *)(iVar3 + 8) = 0;
      }
      if (**(int **)(param_1 + 0x8c) != 0) {
        FUN_0064bc30(*(int **)(param_1 + 0x8c) + 1);
      }
    }
  }
  if (*(int *)(param_1 + 0x90) != 2) {
    ExceptionList = local_c;
    return;
  }
  piVar4 = *(int **)(param_1 + 0x8c);
  if ((piVar4 != (int *)0x0) && (*(char *)(DAT_007356a8 + 0x84) != '\0')) {
    piVar4[2] = 0;
    if (**(int **)(param_1 + 0x8c) == 0) {
      ExceptionList = local_c;
      return;
    }
    FUN_0064bc30(*(int **)(param_1 + 0x8c) + 1);
    ExceptionList = local_c;
    return;
  }
  if ((float)local_18 < 3000.0) {
    ExceptionList = local_c;
    return;
  }
  if (6316.0 <= (float)local_18) {
    if (piVar4 == (int *)0x0) goto LAB_00520e72;
    if (*piVar4 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_18);
    Mutex__Lock();
    (**(code **)(*local_18 + 4))(piVar4);
  }
  else {
    iVar3 = _ftol_nocw();
    if (0 < iVar3) {
      if (piVar4 == (int *)0x0) {
        ExceptionList = local_c;
        return;
      }
      piVar4[1] = 0x32;
      *(undefined4 *)(*(int *)(param_1 + 0x8c) + 0x10) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x8c) + 0xc) = 0x1000;
      FUN_0051c5d0();
      if (**(int **)(param_1 + 0x8c) == 0) {
        ExceptionList = local_c;
        return;
      }
      FUN_0064bc30(*(int **)(param_1 + 0x8c) + 1);
      ExceptionList = local_c;
      return;
    }
    if (piVar4 == (int *)0x0) goto LAB_00520e72;
    if (*piVar4 != 0) {
      FUN_0064bbd0();
    }
    Csis__System__GetAllocator(&local_14);
    Mutex__Lock();
    (**(code **)(*(int *)local_14.s.LowPart + 4))(piVar4);
  }
  Mutex__Unlock();
LAB_00520e72:
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  ExceptionList = local_c;
  return;
}


// ==== 0x520e90 EAXSound::InitEATraxMasks

/* [canon] audio med (ghidra) docs/re/sound.md */

void EAXSound__InitEATraxMasks(undefined4 param_1,uint *param_2,int param_3)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint *unaff_EBX;
  uint uVar5;
  uint uVar6;
  
  uVar5 = 0;
  uVar6 = 0;
  puVar4 = &DAT_00758b58;
  do {
    cVar1 = *(char *)(puVar4 + 1);
    cVar2 = (char)*puVar4;
    if (cVar1 == '\x01') {
      uVar5 = uVar5 | 1 << (cVar2 + 1U & 0x1f);
    }
    else if (cVar1 == '\x02') {
      uVar6 = uVar6 | 1 << (cVar2 + 1U & 0x1f);
    }
    else if (cVar1 == '\x03') {
      uVar3 = 1 << (cVar2 + 1U & 0x1f);
      uVar5 = uVar5 | uVar3;
      uVar6 = uVar6 | uVar3;
    }
    puVar4 = puVar4 + 2;
  } while ((int)puVar4 < 0x758c28);
  if (unaff_EBX != (uint *)0x0) {
    *unaff_EBX = uVar5;
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = uVar6;
  }
  if ((DAT_00758930 == 0) || (DAT_007356b8 != uVar5)) {
    DAT_007356b8 = uVar5;
    DAT_00758930 = uVar5;
  }
  if ((DAT_00758934 == 0) || (DAT_007356bc != uVar6)) {
    DAT_007356bc = uVar6;
    DAT_00758934 = uVar6;
  }
  if (param_3 == 1) {
    DAT_007356b8 = uVar5;
    DAT_007356bc = uVar6;
    DAT_00758930 = uVar5;
    DAT_00758934 = uVar6;
  }
  return;
}


// ==== 0x520f50 FUN_00520f50

void FUN_00520f50(void)

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
    if (piVar1 + -0x9c != (int *)0x0) {
      (**(code **)piVar1[-0x9c])(1);
    }
    piVar1 = (int *)*unaff_ESI;
  }
  return;
}


// ==== 0x520f80 EAXAemsManager::BindFXClassHandles

/* [canon] audio med (ghidra-canon) docs/re/sound.md */

uint EAXAemsManager__BindFXClassHandles(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = Csis__ClassHandle__Set(&PTR_s_FX_NITROUS_01_006f2238);
  uVar2 = Csis__ClassHandle__Set(&PTR_s_FX_SHIFTING_01_006f2240);
  uVar3 = Csis__ClassHandle__Set(&PTR_s_FX_SPARKCHATTER_006f2248);
  uVar4 = Csis__ClassHandle__Set(&PTR_s_FX_SKID_006f2250);
  return uVar4 | uVar1 | uVar2 | uVar3;
}


// ==== 0x520fd0 EAXAemsManager::BindCarClassHandles

/* [canon] audio med (ghidra-canon) docs/re/sound.md */

uint EAXAemsManager__BindCarClassHandles(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = Csis__ClassHandle__Set(&PTR_s_PLAYER_CAR_006f8158);
  uVar2 = Csis__ClassHandle__Set(&PTR_s_AI_CAR_006f8160);
  uVar3 = Csis__ClassHandle__Set(&PTR_s_DYNAMIC_LOAD_006f8168);
  return uVar3 | uVar1 | uVar2;
}


