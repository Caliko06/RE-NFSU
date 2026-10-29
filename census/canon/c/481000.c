// ==== 0x481160 FUN_00481160

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00481160(int param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  float fStack_34;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar2 = *(int *)(param_1 + 0xcf8);
  *(undefined4 *)(iVar2 + 0x808) = 0;
  FUN_00443c90(&DAT_007372b0,param_2,0);
  local_1c = *(undefined4 *)(iVar2 + 0x804);
  local_20 = *(undefined4 *)(iVar2 + 0x800);
  local_18 = *(undefined4 *)(iVar2 + 0x68);
  uVar7 = Atan2ToAngle16(*(undefined4 *)(iVar2 + 0x818),*(undefined4 *)(iVar2 + 0x81c));
  fVar1 = *(float *)(iVar2 + 100);
  fVar3 = *(float *)(iVar2 + 0x60);
  FUN_00427c50(&local_20,0,uVar7);
  TrackPath__UpdateCursor(&DAT_007372b0,(float *)(iVar2 + 0x60));
  (**(code **)(**(int **)(iVar2 + 0x2c) + 0x2c))(1);
  (**(code **)(**(int **)(iVar2 + 0x2c) + 0x30))();
  *(undefined4 *)(iVar2 + 0x884) = 0;
  FUN_004278d0();
  fVar5 = _K_ONE / DAT_0073ad38;
  fVar6 = (*(float *)(iVar2 + 0x60) - fStack_34) * fVar5;
  fVar3 = (*(float *)(iVar2 + 100) - fVar3) * fVar5;
  iVar4 = *(int *)(param_1 + 0xcf8);
  fVar5 = (*(float *)(iVar2 + 0x68) - fVar1) * fVar5;
  *(float *)(iVar4 + 0x70) = fVar6;
  *(float *)(iVar4 + 0x74) = fVar3;
  *(float *)(iVar4 + 0x78) = fVar5;
  *(undefined1 *)(iVar4 + 0x460) = 0;
  *(float *)(iVar4 + 0x3d4) = SQRT(fVar6 * fVar6 + fVar3 * fVar3 + fVar5 * fVar5);
  return;
}


// ==== 0x4812b0 FUN_004812b0

void FUN_004812b0(int param_1,uint param_2,char param_3)

{
  byte *pbVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  undefined4 unaff_EBX;
  int iVar6;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 local_50 [76];
  
  if (param_3 == '\0') {
    iVar6 = param_2 * 0x4c + param_1;
    bVar3 = *(byte *)(param_2 * 0x4c + 0xd5 + param_1) ^ 1;
    *(byte *)(iVar6 + 0xd5) = bVar3;
    local_70 = *(undefined4 *)(iVar6 + 0xf4);
    local_6c = *(undefined4 *)(iVar6 + 0xf8);
    local_68 = *(undefined4 *)(iVar6 + 0xfc);
    local_60 = *(undefined4 *)(iVar6 + 0x100);
    local_5c = *(undefined4 *)(iVar6 + 0x104);
    local_58 = *(undefined4 *)(iVar6 + 0x108);
  }
  else {
    iVar6 = param_2 * 0x4c + param_1;
    pbVar1 = (byte *)(iVar6 + 0xd4);
    *pbVar1 = *pbVar1 ^ 1;
    bVar3 = *pbVar1;
    local_70 = *(undefined4 *)(iVar6 + 0xdc);
    local_6c = *(undefined4 *)(iVar6 + 0xe0);
    local_68 = *(undefined4 *)(iVar6 + 0xe4);
    local_60 = *(undefined4 *)(iVar6 + 0xe8);
    local_5c = *(undefined4 *)(iVar6 + 0xec);
    local_58 = *(undefined4 *)(iVar6 + 0xf0);
  }
  uVar2 = *(uint *)(param_1 + 0xcb0);
  uStack_78 = CONCAT13(bVar3 != 0,(undefined3)uStack_78);
  uVar5 = ((int)param_2 < 1) - 1 & param_2;
  uVar4 = uVar5;
  if ((int)uVar5 > (int)uVar2) {
    uVar4 = uVar2;
  }
  if (SBORROW4(uVar4,uVar2) == ((int)uVar5 <= (int)uVar2 && (int)(uVar5 - uVar2) < 0)) {
    local_74 = DAT_007372b0;
  }
  else {
    local_74 = *(undefined4 *)(uVar4 * 0x4c + 0xd8 + param_1);
  }
  FUN_00481160(param_1,local_74);
  bMatrix4_SetRotationAndTranslation();
  if (bVar3 != 0) {
    Matrix_InvertRigid();
  }
  D3DXVec3Transform(&local_70,&local_70,local_50);
  uVar2 = *(uint *)(param_1 + 0xcb0);
  uVar5 = param_2 + 1 & ((int)(param_2 + 1) < 1) - 1;
  uVar4 = uVar5;
  if ((int)uVar5 > (int)uVar2) {
    uVar4 = uVar2;
  }
  if (SBORROW4(uVar4,uVar2) == ((int)uVar5 <= (int)uVar2 && (int)(uVar5 - uVar2) < 0)) {
    uStack_80 = DAT_007372b0;
  }
  else {
    uStack_80 = *(undefined4 *)(uVar4 * 0x4c + 0xd8 + param_1);
  }
  FUN_00481160(param_1,uStack_80);
  bMatrix4_SetRotationAndTranslation();
  if (uStack_84._3_1_ != '\0') {
    Matrix_InvertRigid();
  }
  D3DXVec3Transform(&local_6c,&local_6c,&local_5c);
  if (param_3 == '\0') {
    *(undefined4 *)(iVar6 + 0xf4) = unaff_EBX;
    *(undefined4 *)(iVar6 + 0xf8) = uStack_84;
    *(undefined4 *)(iVar6 + 0xfc) = uStack_80;
    *(undefined4 *)(iVar6 + 0x100) = uStack_78;
    *(undefined4 *)(iVar6 + 0x104) = local_74;
    *(undefined4 *)(iVar6 + 0x108) = local_70;
  }
  else {
    *(undefined4 *)(iVar6 + 0xdc) = unaff_EBX;
    *(undefined4 *)((param_2 + 3) * 0x4c + param_1) = uStack_80;
    *(undefined4 *)(iVar6 + 0xe0) = uStack_84;
    *(undefined4 *)(iVar6 + 0xe8) = uStack_78;
    *(undefined4 *)(iVar6 + 0xec) = local_74;
    *(undefined4 *)(iVar6 + 0xf0) = local_70;
  }
  FUN_00481160(param_1,*(undefined4 *)(param_1 + 0xcc0));
  return;
}


// ==== 0x481510 FUN_00481510

void FUN_00481510(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  
  iVar4 = param_1;
  iVar5 = *(int *)(param_1 + 0x58);
  if (iVar5 == *(int *)(param_1 + 0x5c)) {
    return;
  }
  do {
    uVar3 = *(ushort *)(*(int *)(param_1 + 0x54) + 2 + iVar5);
    uVar8 = (uint)uVar3;
    puVar9 = (undefined4 *)(*(int *)(param_1 + 0x54) + iVar5);
    iVar5 = iVar5 + uVar8;
  } while (iVar5 != *(int *)(param_1 + 0x5c));
  uVar10 = (uint)*(byte *)((int)puVar9 + 1);
  pbVar6 = (byte *)((int)puVar9 + 1);
  switch(*(undefined1 *)puVar9) {
  case 0:
    FUN_00480a50(param_1,0);
  case 3:
    puVar11 = (undefined4 *)(uVar10 * 0x4c + 0xd0 + param_1);
    for (iVar5 = 0x13; puVar9 = puVar9 + 1, iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar11 = *puVar9;
      puVar11 = puVar11 + 1;
    }
    *(uint *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) - uVar8;
    return;
  case 1:
    FUN_00480660(param_1,uVar10);
    *(uint *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) - uVar8;
    return;
  case 2:
    *(undefined1 *)(uVar10 * 0x4c + 0xd0 + param_1) = *(undefined1 *)(puVar9 + 1);
    *(uint *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) - uVar8;
    return;
  case 4:
    uVar3 = uVar3 >> 3;
    uVar10 = (uint)uVar3;
    iVar5 = 0;
    param_1 = 0;
    if (3 < uVar3) {
      iVar7 = 3;
      do {
        *(undefined4 *)((uint)*pbVar6 * 0x4c + 0xd8 + iVar4) = *(undefined4 *)(pbVar6 + 3);
        *(undefined4 *)((uint)pbVar6[8] * 0x4c + 0xd8 + iVar4) = *(undefined4 *)(pbVar6 + 0xb);
        *(undefined4 *)((uint)pbVar6[0x10] * 0x4c + 0xd8 + iVar4) = *(undefined4 *)(pbVar6 + 0x13);
        *(undefined4 *)((uint)pbVar6[0x18] * 0x4c + 0xd8 + iVar4) = *(undefined4 *)(pbVar6 + 0x1b);
        iVar5 = param_1 + 4;
        iVar7 = iVar7 + 4;
        pbVar6 = pbVar6 + 0x20;
        param_1 = iVar5;
      } while (iVar7 < (int)uVar10);
    }
    if (iVar5 < (int)uVar10) {
      pbVar6 = (byte *)((int)puVar9 + iVar5 * 8 + 1);
      iVar5 = uVar10 - iVar5;
      do {
        bVar2 = *pbVar6;
        pbVar1 = pbVar6 + 3;
        pbVar6 = pbVar6 + 8;
        iVar5 = iVar5 + -1;
        *(undefined4 *)((uint)bVar2 * 0x4c + 0xd8 + iVar4) = *(undefined4 *)pbVar1;
      } while (iVar5 != 0);
      *(uint *)(iVar4 + 0x5c) = *(int *)(iVar4 + 0x5c) - uVar8;
      return;
    }
    goto switchD_00481555_default;
  case 5:
    FUN_004812b0(param_1,uVar10,1);
    *(uint *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) - uVar8;
    return;
  case 6:
    pbVar6 = (byte *)(uVar10 * 0x4c + 0xd2 + param_1);
    break;
  case 7:
    FUN_004812b0(param_1,uVar10,0);
    *(uint *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) - uVar8;
    return;
  case 8:
    pbVar6 = (byte *)(uVar10 * 0x4c + 0xd3 + param_1);
    break;
  case 9:
    pbVar6 = (byte *)(uVar10 * 0x4c + 0xd1 + param_1);
    break;
  case 10:
    pbVar6 = (byte *)(uVar10 * 0x4c + 0xd6 + param_1);
    break;
  case 0xb:
    pbVar6 = (byte *)(uVar10 * 0x4c + 0xd7 + param_1);
    break;
  default:
    goto switchD_00481555_default;
  }
  *pbVar6 = *pbVar6 ^ 1;
switchD_00481555_default:
  *(uint *)(iVar4 + 0x5c) = *(int *)(iVar4 + 0x5c) - uVar8;
  return;
}


// ==== 0x481720 DragCameraManager::AddUndo

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

void DragCameraManager__AddUndo(undefined4 *param_1,uint param_2)

{
  int in_EAX;
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(in_EAX + 0x5c) - *(int *)(in_EAX + 0x58);
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0x1000;
  }
  iVar1 = 0x1000 - iVar1;
  if (iVar1 < (int)param_2) {
    do {
      uVar2 = (uint)*(ushort *)(*(int *)(in_EAX + 0x54) + 2 + *(int *)(in_EAX + 0x58));
      iVar1 = iVar1 + uVar2;
      *(uint *)(in_EAX + 0x58) = *(int *)(in_EAX + 0x58) + uVar2;
    } while (iVar1 < (int)param_2);
  }
  puVar3 = (undefined4 *)(*(int *)(in_EAX + 0x54) + *(int *)(in_EAX + 0x5c));
  for (uVar2 = param_2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = *param_1;
    param_1 = param_1 + 1;
    puVar3 = puVar3 + 1;
  }
  for (uVar2 = param_2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar3 = *(undefined1 *)param_1;
    param_1 = (undefined4 *)((int)param_1 + 1);
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  *(uint *)(in_EAX + 0x5c) = *(int *)(in_EAX + 0x5c) + param_2;
  return;
}


// ==== 0x481790 FUN_00481790

uint FUN_00481790(undefined4 param_1,int param_2,float *param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 in_EAX;
  uint uVar5;
  int iVar6;
  int unaff_ESI;
  int unaff_EDI;
  float *local_4;
  
  iVar4 = (int)param_3;
  fVar2 = *(float *)(param_2 + 0x3c + unaff_EDI * 4);
  fVar3 = *(float *)((int)param_3 + 0x3c + unaff_ESI * 4);
  uVar5 = CONCAT22((short)((uint)in_EAX >> 0x10),
                   (ushort)(fVar2 < fVar3) << 8 | (ushort)(NAN(fVar2) || NAN(fVar3)) << 10 |
                   (ushort)(fVar2 == fVar3) << 0xe);
  if (((fVar2 == fVar3) &&
      (uVar5 = CONCAT31((int3)(uVar5 >> 8),*(char *)(param_2 + 4)),
      *(char *)(param_2 + 4) == *(char *)((int)param_3 + 4))) &&
     (*(char *)(param_2 + 5) == *(char *)((int)param_3 + 5))) {
    local_4 = (float *)((int)param_3 + (unaff_ESI * 3 + 3) * 4);
    param_3 = (float *)(param_2 + (unaff_EDI * 3 + 3) * 4);
    iVar6 = 0;
    while( true ) {
      fVar2 = *param_3;
      fVar3 = *local_4;
      if (fVar2 != fVar3) {
        return CONCAT22((short)((uint)param_3 >> 0x10),
                        (ushort)(fVar2 < fVar3) << 8 | (ushort)(NAN(fVar2) || NAN(fVar3)) << 10 |
                        (ushort)(fVar2 == fVar3) << 0xe);
      }
      iVar1 = iVar6 + (unaff_EDI + 3) * 3;
      fVar2 = *(float *)(param_2 + iVar1 * 4);
      fVar3 = *(float *)(iVar4 + (iVar6 + (unaff_ESI + 3) * 3) * 4);
      if (fVar2 != fVar3) break;
      iVar6 = iVar6 + 1;
      param_3 = param_3 + 1;
      local_4 = local_4 + 1;
      if (2 < iVar6) {
        return 1;
      }
    }
    return CONCAT22((short)((uint)iVar1 >> 0x10),
                    (ushort)(fVar2 < fVar3) << 8 | (ushort)(NAN(fVar2) || NAN(fVar3)) << 10 |
                    (ushort)(fVar2 == fVar3) << 0xe);
  }
  return uVar5 & 0xffffff00;
}


// ==== 0x481850 FUN_00481850

undefined2 FUN_00481850(void)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  int unaff_EDI;
  undefined1 local_8;
  undefined1 local_7;
  undefined2 local_6;
  undefined4 local_4;
  
  iVar4 = 0;
  iVar1 = 0;
  pfVar2 = (float *)(*(int *)(unaff_EDI + 0x4c) + 8);
  pfVar3 = (float *)(unaff_EDI + 0x124);
  do {
    if (pfVar2[-2] != pfVar3[-0x13]) {
      iVar4 = iVar4 + 1;
    }
    if (pfVar2[-1] != *pfVar3) {
      iVar4 = iVar4 + 1;
    }
    if (*pfVar2 != pfVar3[0x13]) {
      iVar4 = iVar4 + 1;
    }
    if (pfVar2[1] != pfVar3[0x26]) {
      iVar4 = iVar4 + 1;
    }
    iVar1 = iVar1 + 4;
    pfVar2 = pfVar2 + 4;
    pfVar3 = pfVar3 + 0x4c;
  } while (iVar1 < 0x25);
  if (iVar1 < 0x28) {
    pfVar2 = (float *)(*(int *)(unaff_EDI + 0x4c) + iVar1 * 4);
    pfVar3 = (float *)(iVar1 * 0x4c + 0xd8 + unaff_EDI);
    iVar1 = 0x28 - iVar1;
    do {
      if (*pfVar2 != *pfVar3) {
        iVar4 = iVar4 + 1;
      }
      pfVar2 = pfVar2 + 1;
      pfVar3 = pfVar3 + 0x13;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  if (iVar4 != 0) {
    iVar4 = iVar4 * 8;
    iVar1 = 0;
    pfVar2 = (float *)(unaff_EDI + 0xd8);
    do {
      if (*(float *)(*(int *)(unaff_EDI + 0x4c) + iVar1 * 4) != *pfVar2) {
        local_8 = 4;
        local_7 = (undefined1)iVar1;
        local_6 = (undefined2)iVar4;
        DragCameraManager__AddUndo(&local_8,4);
        local_4 = *(undefined4 *)(*(int *)(unaff_EDI + 0x4c) + iVar1 * 4);
        DragCameraManager__AddUndo(&local_4,4);
        iVar4 = iVar4 + -8;
      }
      iVar1 = iVar1 + 1;
      pfVar2 = pfVar2 + 0x13;
    } while (iVar1 < 0x28);
    return 1;
  }
  return 0;
}


// ==== 0x481970 FUN_00481970

undefined4 FUN_00481970(void)

{
  int *piVar1;
  char *in_EAX;
  undefined4 uVar2;
  uint uVar3;
  undefined1 local_4;
  undefined1 local_3 [3];
  
  piVar1 = (int *)(in_EAX + 0xcb4);
  uVar3 = 0;
  do {
    if (*in_EAX != in_EAX[*piVar1 * 0x4c + 0xd0]) {
      _local_4 = CONCAT31((uint3)*piVar1 & 0xff,3);
      _local_4 = CONCAT22(0x50,_local_4);
      uVar2 = DragCameraManager__AddUndo(&local_4,4);
      DragCameraManager__AddUndo(uVar2,0x4c);
      return 1;
    }
    uVar3 = uVar3 + 1;
    in_EAX = in_EAX + 1;
  } while (uVar3 < 0x4c);
  return 0;
}


// ==== 0x4819d0 DragCameraManager_LoadWorkingFromCurrentKey

/* [canon] camera low (ghidra-canon) docs/re/camera.md */

void DragCameraManager_LoadWorkingFromCurrentKey(void)

{
  undefined4 *in_EAX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = in_EAX + in_EAX[0x32d] * 0x13 + 0x34;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *in_EAX = *puVar2;
    puVar2 = puVar2 + 1;
    in_EAX = in_EAX + 1;
  }
  return;
}


// ==== 0x4819f0 DragCameraManager_StoreWorkingToCurrentKey

/* [canon] camera low (ghidra-canon) docs/re/camera.md */

void DragCameraManager_StoreWorkingToCurrentKey(void)

{
  undefined4 *in_EAX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = in_EAX + in_EAX[0x32d] * 0x13 + 0x34;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *in_EAX;
    in_EAX = in_EAX + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== 0x481a10 DragCameraManager::BackupDistance

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

void __fastcall DragCameraManager__BackupDistance(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0xc;
  puVar2 = (undefined4 *)(param_2 + 0x124);
  do {
    *(undefined4 *)(iVar1 + -0xc + *(int *)(param_2 + 0x4c)) = puVar2[-0x13];
    *(undefined4 *)(iVar1 + -8 + *(int *)(param_2 + 0x4c)) = *puVar2;
    *(undefined4 *)(*(int *)(param_2 + 0x4c) + -4 + iVar1) = puVar2[0x13];
    *(undefined4 *)(iVar1 + *(int *)(param_2 + 0x4c)) = puVar2[0x26];
    *(undefined4 *)(*(int *)(param_2 + 0x4c) + 4 + iVar1) = puVar2[0x39];
    *(undefined4 *)(*(int *)(param_2 + 0x4c) + 8 + iVar1) = puVar2[0x4c];
    *(undefined4 *)(*(int *)(param_2 + 0x4c) + 0xc + iVar1) = puVar2[0x5f];
    *(undefined4 *)(*(int *)(param_2 + 0x4c) + 0x10 + iVar1) = puVar2[0x72];
    *(undefined4 *)(*(int *)(param_2 + 0x4c) + 0x14 + iVar1) = puVar2[0x85];
    *(undefined4 *)(*(int *)(param_2 + 0x4c) + 0x18 + iVar1) = puVar2[0x98];
    iVar1 = iVar1 + 0x28;
    puVar2 = puVar2 + 0xbe;
  } while (iVar1 < 0xac);
  return;
}


// ==== 0x481ab0 FUN_00481ab0

void __thiscall FUN_00481ab0(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  void *pvVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  
  iVar9 = *(int *)(param_1 + 0xcb8);
  if (iVar9 == param_2) {
    return;
  }
  if (2 < iVar9) {
    *(undefined4 *)(param_1 + 0xcc0) = *(undefined4 *)(param_1 + 0xcc8);
  }
  switch(iVar9) {
  case 0:
    iVar9 = *(int *)(DAT_007361f8 + 0x28);
    *(int *)(param_1 + 0xcf8) = iVar9;
    uVar11 = *(undefined4 *)(iVar9 + 0x814);
    *(undefined4 *)(param_1 + 0xcc0) = uVar11;
    *(undefined4 *)(param_1 + 0xcc4) = uVar11;
    Car_SetMode();
    iVar9 = *(int *)(*(int *)(param_1 + 0xcf8) + 0x3c);
    *(char *)(iVar9 + 0x1b) = *(char *)(iVar9 + 0x1b) + '\x01';
    pvVar5 = _malloc(0x1000);
    *(void **)(param_1 + 0x54) = pvVar5;
    pvVar5 = _malloc(0xa0);
    *(void **)(param_1 + 0x4c) = pvVar5;
    pvVar5 = _malloc(0x430);
    if (pvVar5 == (void *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      puVar6 = (undefined4 *)FUN_00464860(*(undefined4 *)(*(int *)(param_1 + 0xcf8) + 0x20));
    }
    *(undefined4 **)(param_1 + 0x50) = puVar6;
    puVar10 = (undefined4 *)(*(int *)(param_1 + 0xcf8) + 0x40);
    for (iVar9 = 0x10c; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar6 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar6 = puVar6 + 1;
    }
    break;
  case 1:
    FUN_005740b0(0x60);
    FUN_005740b0(0x22);
    FUN_005740b0(0x23);
    FUN_005740b0(0x24);
    FUN_005740b0(0x25);
    FUN_005740b0(9);
    FUN_005740b0(10);
    FUN_005740b0(0xc);
    FUN_005740b0(0xb);
    FUN_005740b0(0x16);
    break;
  case 2:
    FUN_005740b0(0x22);
    FUN_005740b0(0x23);
    FUN_005740b0(0x24);
    FUN_005740b0(0x25);
    FUN_005740b0(9);
    FUN_005740b0(0xb);
    FUN_005740b0(0x16);
    break;
  case 3:
    FUN_00481850();
    FUN_005740b0(0x60);
    uVar11 = 0x24;
    goto LAB_00481c93;
  case 4:
    FUN_00481850();
    FUN_005740b0(0x60);
    uVar11 = 0x25;
LAB_00481c93:
    FUN_005740b0(uVar11);
    FUN_005740b0(10);
    FUN_005740b0(0xc);
    FUN_005740b0(9);
    FUN_005740b0(0x16);
    break;
  case 5:
  case 6:
    FUN_00481970();
    FUN_005740b0(9);
    FUN_005740b0(0xb);
    FUN_005740b0(0x23);
    FUN_005740b0(0x22);
    FUN_005740b0(0x24);
    FUN_005740b0(0x25);
    FUN_005740b0(0x53);
    FUN_005740b0(0x52);
    FUN_005740b0(0x58);
    FUN_005740b0(0x59);
    FUN_005740b0(0x5e);
    FUN_005740b0(0x5f);
    FUN_005740b0(0x60);
    FUN_005740b0(0x61);
    FUN_005740b0(0x16);
  }
  *(int *)(param_1 + 0xcb8) = param_2;
  if ((param_2 == 4) || (param_2 == 6)) {
    iVar9 = 1;
  }
  else {
    iVar9 = 0;
  }
  if (2 < param_2) {
    *(undefined4 *)(param_1 + 0xcc8) = *(undefined4 *)(param_1 + 0xcc0);
    if (iVar9 == 0) {
      fVar3 = 0.01;
    }
    else {
      fVar3 = -0.01;
    }
    uVar7 = *(int *)(param_1 + 0xcb4) + iVar9;
    uVar2 = *(uint *)(param_1 + 0xcb0);
    uVar7 = uVar7 & ((int)uVar7 < 1) - 1;
    uVar8 = uVar7;
    if ((int)uVar7 > (int)uVar2) {
      uVar8 = uVar2;
    }
    fVar4 = DAT_007372b0;
    if (SBORROW4(uVar8,uVar2) != ((int)uVar7 <= (int)uVar2 && (int)(uVar7 - uVar2) < 0)) {
      fVar4 = *(float *)(uVar8 * 0x4c + 0xd8 + param_1);
    }
    *(float *)(param_1 + 0xcc0) = fVar4 + fVar3;
  }
  switch(param_2) {
  case 0:
    Car_SetMode();
    iVar9 = *(int *)(*(int *)(param_1 + 0xcf8) + 0x3c);
    cVar1 = *(char *)(iVar9 + 0x1b);
    if (cVar1 != '\0') {
      *(char *)(iVar9 + 0x1b) = cVar1 + -1;
    }
    if (*(float *)(param_1 + 0xcc0) == *(float *)(param_1 + 0xcc4)) {
      FUN_00427e60(*(undefined4 *)(*(int *)(param_1 + 0x50) + 0x390),0);
      puVar6 = *(undefined4 **)(param_1 + 0x50);
      puVar10 = (undefined4 *)(*(int *)(param_1 + 0xcf8) + 0x40);
      for (iVar9 = 0x10c; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar10 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar10 = puVar10 + 1;
      }
    }
    _free(*(void **)(param_1 + 0x54));
    _free(*(void **)(param_1 + 0x4c));
    _free(*(void **)(param_1 + 0x50));
    *(undefined4 *)(param_1 + 0x54) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    return;
  case 1:
    InputEvents__AddSource(0x60,FUN_00482850,0);
    InputEvents__AddSource(0x22,FUN_00482850,0);
    InputEvents__AddSource(0x23,FUN_00482850,0);
    InputEvents__AddSource(0x24,FUN_00482850,0);
    InputEvents__AddSource(0x25,FUN_00482850,0);
    InputEvents__AddSource(9,FUN_00482850,0);
    InputEvents__AddSource(10,FUN_00482850,0);
    InputEvents__AddSource(0xc,FUN_00482850,0);
    InputEvents__AddSource(0xb,FUN_00482850,0);
    InputEvents__AddSource(0x16,0,0);
    return;
  case 2:
    InputEvents__AddSource(0x22,FUN_00482850,0);
    InputEvents__AddSource(0x23,FUN_00482850,0);
    InputEvents__AddSource(0x24,FUN_00482850,0);
    InputEvents__AddSource(0x25,FUN_00482850,0);
    InputEvents__AddSource(9,FUN_00482850,0);
    InputEvents__AddSource(0xb,FUN_00482850,0);
    InputEvents__AddSource(0x16,0,0);
    return;
  case 3:
    DragCameraManager__BackupDistance();
    InputEvents__AddSource(0x60,FUN_00482850,0);
    uVar11 = 0x24;
    break;
  case 4:
    DragCameraManager__BackupDistance();
    InputEvents__AddSource(0x60,FUN_00482850,0);
    uVar11 = 0x25;
    break;
  case 5:
  case 6:
    FUN_00480f10();
    DragCameraManager_LoadWorkingFromCurrentKey();
    DragCameraManager__ClearVelocities();
    *(undefined1 *)(param_1 + 0xd08) = 1;
    InputEvents__AddSource(9,FUN_00482850,0);
    InputEvents__AddSource(0xb,FUN_00482850,0);
    InputEvents__AddSource(0x23,0,0);
    InputEvents__AddSource(0x22,0,0);
    InputEvents__AddSource(0x24,0,0);
    InputEvents__AddSource(0x25,0,0);
    InputEvents__AddSource(0x53,0,0);
    InputEvents__AddSource(0x52,0,0);
    InputEvents__AddSource(0x58,0,0);
    InputEvents__AddSource(0x59,0,0);
    InputEvents__AddSource(0x5e,0,0);
    InputEvents__AddSource(0x5f,0,0);
    InputEvents__AddSource(0x60,0,0);
    InputEvents__AddSource(0x61,0,0);
    InputEvents__AddSource(0x16,FUN_00482850,0);
  default:
    return;
  }
  InputEvents__AddSource(uVar11,FUN_00482850,0);
  InputEvents__AddSource(10,FUN_00482850,0);
  InputEvents__AddSource(0xc,FUN_00482850,0);
  InputEvents__AddSource(9,FUN_00482850,0);
  InputEvents__AddSource(0x16,0,0);
  return;
}


// ==== 0x482230 FUN_00482230

void __fastcall FUN_00482230(undefined4 param_1,byte param_2,undefined4 param_3,uint param_4)

{
  int *piVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  float10 fVar7;
  
  iVar3 = *(int *)(in_EAX + 0xcb8);
  switch(iVar3) {
  case 1:
    switch(param_4) {
    case 9:
      FUN_00481ab0(2);
      return;
    case 10:
      puVar4 = (undefined4 *)(*(int *)(in_EAX + 0xcb4) * 0x4c + 0xd0 + in_EAX);
      puVar6 = (undefined4 *)(in_EAX + 0x84);
      for (iVar3 = 0x13; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      return;
    case 0xb:
      FUN_00481510(in_EAX);
      return;
    case 0xc:
      param_4._0_2_ = CONCAT11(*(undefined1 *)(in_EAX + 0xcb4),3);
      param_4 = CONCAT22(0x50,(undefined2)param_4);
      DragCameraManager__AddUndo(&param_4,4);
      DragCameraManager__AddUndo(*(int *)(in_EAX + 0xcb4) * 0x4c + 0xd0 + in_EAX,0x4c);
      DragCameraManager__Paste();
      return;
    case 0x22:
      if (param_2 != 0) {
        FUN_00480660(in_EAX,*(undefined4 *)(in_EAX + 0xcb4));
        return;
      }
      break;
    case 0x23:
      if (param_2 != 0) {
        FUN_00480a50(in_EAX,1);
        return;
      }
      break;
    case 0x24:
      if ((param_2 != 0) && (0 < *(int *)(in_EAX + 0xcb4))) {
        FUN_00481ab0(3);
        return;
      }
      break;
    case 0x25:
      if ((param_2 != 0) && (*(int *)(in_EAX + 0xcb4) < *(int *)(in_EAX + 0xcb0) + -1)) {
        FUN_00481ab0(4);
        return;
      }
      break;
    case 0x60:
      param_4 = (uint)param_2;
      fVar7 = (float10)FUN_00454f10(&PTR_DAT_00705de0,(float)param_4 - 128.0);
      *(float *)(in_EAX + 0xce4) = (float)fVar7;
      return;
    }
    break;
  case 2:
    if (param_2 != 0) {
      switch(param_4) {
      case 9:
        if (*(int *)(in_EAX + 0xcbc) == 8) {
          FUN_00482fc0();
          return;
        }
        break;
      case 0xb:
        goto switchD_004823c9_caseD_b;
      case 0x22:
        piVar1 = (int *)(in_EAX + 0xcbc);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 0) {
          *(undefined4 *)(in_EAX + 0xcbc) = 8;
          return;
        }
        break;
      case 0x23:
        iVar3 = *(int *)(in_EAX + 0xcbc) + 1;
        *(int *)(in_EAX + 0xcbc) = iVar3;
        if (8 < iVar3) {
          *(undefined4 *)(in_EAX + 0xcbc) = 0;
          return;
        }
        break;
      case 0x24:
      case 0x25:
        switch(*(undefined4 *)(in_EAX + 0xcbc)) {
        case 0:
          iVar3 = *(int *)(in_EAX + 0xcb4) * 0x4c;
          cVar2 = *(char *)(iVar3 + 0xd0 + in_EAX);
          *(byte *)(iVar3 + 0xd0 + in_EAX) = (cVar2 != '\0') - 1U & 0x14;
          param_4._0_2_ = CONCAT11(*(undefined1 *)(in_EAX + 0xcb4),2);
          param_4 = CONCAT22(8,(undefined2)param_4);
          DragCameraManager__AddUndo(&param_4,4);
          FUN_0047fca0(in_EAX,cVar2);
          return;
        case 1:
          iVar3 = *(int *)(in_EAX + 0xcb4) * 0x4c;
          *(byte *)(iVar3 + 0xd1 + in_EAX) = *(byte *)(iVar3 + 0xd1 + in_EAX) ^ 1;
          param_4._0_1_ = 9;
          break;
        case 2:
          FUN_004812b0(in_EAX,*(undefined4 *)(in_EAX + 0xcb4),1);
          param_4._0_1_ = 5;
          break;
        case 3:
          iVar3 = *(int *)(in_EAX + 0xcb4) * 0x4c;
          *(byte *)(iVar3 + 0xd2 + in_EAX) = *(byte *)(iVar3 + 0xd2 + in_EAX) ^ 1;
          param_4._0_1_ = 6;
          break;
        case 4:
          FUN_004812b0(in_EAX,*(undefined4 *)(in_EAX + 0xcb4),0);
          param_4._0_1_ = 7;
          break;
        case 5:
          iVar3 = *(int *)(in_EAX + 0xcb4) * 0x4c;
          *(byte *)(iVar3 + 0xd3 + in_EAX) = *(byte *)(iVar3 + 0xd3 + in_EAX) ^ 1;
          param_4._0_1_ = 8;
          break;
        case 6:
          iVar3 = *(int *)(in_EAX + 0xcb4) * 0x4c;
          *(byte *)(iVar3 + 0xd6 + in_EAX) = *(byte *)(iVar3 + 0xd6 + in_EAX) ^ 1;
          param_4._0_1_ = 10;
          break;
        case 7:
          iVar3 = *(int *)(in_EAX + 0xcb4) * 0x4c;
          *(byte *)(iVar3 + 0xd7 + in_EAX) = *(byte *)(iVar3 + 0xd7 + in_EAX) ^ 1;
          param_4._0_1_ = 0xb;
          break;
        default:
          goto switchD_004825cb_caseD_b;
        }
        param_4._0_2_ = CONCAT11(*(undefined1 *)(in_EAX + 0xcb4),(undefined1)param_4);
        param_4 = CONCAT22(4,(undefined2)param_4);
        DragCameraManager__AddUndo(&param_4,4);
        return;
      }
    }
    break;
  case 3:
  case 4:
    if ((iVar3 == 4) || (iVar3 == 6)) {
      iVar5 = 1;
    }
    else {
      iVar5 = 0;
    }
    switch(param_4) {
    case 9:
      if (*(char *)(*(int *)(in_EAX + 0xcb4) * 0x4c + 0xd0 + in_EAX) == '\x14') {
        FUN_00481ab0((iVar5 != 0) + '\x05');
        return;
      }
      break;
    case 10:
      FUN_00480750(*(undefined4 *)(in_EAX + 0xcb4));
      return;
    case 0xc:
      param_4._0_2_ = CONCAT11(*(undefined1 *)(in_EAX + 0xcb4),3);
      param_4 = CONCAT22(0x50,(undefined2)param_4);
      DragCameraManager__AddUndo(&param_4,4);
      DragCameraManager__AddUndo(*(int *)(in_EAX + 0xcb4) * 0x4c + 0xd0 + in_EAX,0x4c);
      FUN_00480930(*(undefined4 *)(in_EAX + 0xcb4),iVar5);
      return;
    case 0x24:
      if ((param_2 == 0) && (iVar3 == 3)) {
        FUN_00481ab0(1);
        return;
      }
      break;
    case 0x25:
      if ((param_2 == 0) && (iVar3 == 4)) {
        FUN_00481ab0(1);
        return;
      }
      break;
    case 0x60:
      param_4 = (uint)param_2;
      fVar7 = (float10)FUN_00454f10(&PTR_DAT_00705de0,(float)param_4 - 128.0);
      *(float *)(in_EAX + 0xce4) = (float)fVar7;
      return;
    }
    break;
  case 5:
  case 6:
    if (param_4 != 9) {
      if (param_4 != 0xb) break;
      DragCameraManager_StoreWorkingToCurrentKey();
    }
switchD_004823c9_caseD_b:
    FUN_00481ab0(1);
    break;
  default:
    goto switchD_0048224b_default;
  }
switchD_004825cb_caseD_b:
switchD_0048224b_default:
  return;
}


// ==== 0x482850 FUN_00482850

void FUN_00482850(undefined4 param_1,undefined4 param_2)

{
  FUN_00482230(param_1,param_2);
  return;
}


// ==== 0x482870 GetAnalogInput

/* [canon] camera med (ghidra-canon+nfsug) docs/re/camera.md */

float10 GetAnalogInput(void)

{
  int in_EAX;
  float local_4;
  
  local_4 = (float)(uint)(byte)(&DAT_0073b4a4)[in_EAX];
  Curve_Evaluate(&local_4,(float)(int)local_4 - 128.0);
  return (float10)local_4;
}


// ==== 0x4828a0 DragCameraManager::GetNewVelocity

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

float10 __fastcall
DragCameraManager__GetNewVelocity
          (undefined4 param_1,int param_2,undefined4 param_3,float param_4,float param_5,
          float param_6,float param_7)

{
  int in_EAX;
  float10 fVar1;
  float10 fVar2;
  
  if ((float)(byte)(&DAT_0073b4a4)[in_EAX] - (float)(byte)(&DAT_0073b4a4)[param_2] == 0.0) {
    if (0.0 <= param_4) {
      if (param_4 <= 0.0) {
        return (float10)0.0;
      }
      fVar1 = (float10)param_4 - (float10)DAT_0073ad38 * (float10)param_7;
      if (fVar1 < (float10)0.0) {
        return (float10)0.0;
      }
    }
    else {
      fVar1 = (float10)DAT_0073ad38 * (float10)param_7 + (float10)param_4;
      if ((float10)0.0 < fVar1) {
        return (float10)0.0;
      }
    }
  }
  else {
    fVar1 = -(float10)param_5;
    fVar2 = (float10)DAT_0073ad38 *
            (float10)((float)(byte)(&DAT_0073b4a4)[in_EAX] - (float)(byte)(&DAT_0073b4a4)[param_2])
            * (float10)param_6 + (float10)param_4;
    if (fVar1 < fVar2) {
      fVar1 = (float10)(float)fVar2;
    }
    if ((float10)param_5 < fVar1) {
      fVar1 = (float10)param_5;
    }
  }
  return fVar1;
}


// ==== 0x4829a0 FUN_004829a0

void FUN_004829a0(void)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  ushort uVar6;
  undefined2 uVar7;
  short sVar8;
  undefined4 uVar9;
  float fVar10;
  int iVar11;
  int unaff_EDI;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float local_60;
  float local_5c;
  undefined4 local_58;
  undefined1 local_50 [76];
  
  if (DAT_00735f50 != 0) {
    if (*(int *)(unaff_EDI + 0xcb8) == 0) {
      FUN_00481ab0(1);
    }
    if (DAT_00735f50 != 0) goto LAB_004829e3;
  }
  if (*(int *)(unaff_EDI + 0xcb8) != 0) {
    FUN_00481ab0(0);
  }
LAB_004829e3:
  iVar11 = *(int *)(unaff_EDI + 0xcb8);
  if (0 < iVar11) {
    switch(iVar11) {
    case 1:
      fVar12 = (float10)bClampF(DAT_0073ad38 * *(float *)(unaff_EDI + 0xce4) * 1000.0 +
                                *(float *)(unaff_EDI + 0xcc0),*(float *)(unaff_EDI + 0xccc) + -25.0,
                                *(float *)(unaff_EDI + 0xcd0) + 100.0);
      *(float *)(unaff_EDI + 0xcc0) = (float)fVar12;
      uVar9 = DragCameraManager__GetDragIndex((float)fVar12);
      *(undefined4 *)(unaff_EDI + 0xcb4) = uVar9;
      FUN_00481160(unaff_EDI,*(undefined4 *)(unaff_EDI + 0xcc0));
      return;
    case 3:
      FUN_00480ca0(*(float *)(unaff_EDI + 0xce4) * 400.0 * DAT_0073ad38);
      fVar12 = (float10)DragCameraManager__GetDistance();
      *(float *)(unaff_EDI + 0xcc0) = (float)(fVar12 + (float10)0.01);
      FUN_00481160(unaff_EDI,*(undefined4 *)(unaff_EDI + 0xcc0));
      return;
    case 4:
      FUN_00480ca0(*(float *)(unaff_EDI + 0xce4) * 400.0 * DAT_0073ad38);
      fVar12 = (float10)DragCameraManager__GetDistance();
      *(float *)(unaff_EDI + 0xcc0) = (float)(fVar12 - (float10)0.01);
      FUN_00481160(unaff_EDI,*(undefined4 *)(unaff_EDI + 0xcc0));
      return;
    case 5:
    case 6:
      if ((iVar11 == 4) || (iVar11 == 6)) {
        iVar11 = 1;
      }
      else {
        iVar11 = 0;
      }
      if (((*(char *)(unaff_EDI + 0xd08) != '\0') && (DAT_0073b4c8 == '\0')) &&
         (DAT_0073b4c9 == '\0')) {
        *(undefined1 *)(unaff_EDI + 0xd08) = 0;
      }
      fVar12 = (float10)DragCameraManager__GetNewVelocity
                                  (unaff_EDI,*(undefined4 *)(unaff_EDI + 0xcdc),0x42480000,
                                   0x42480000,0x42c80000);
      *(float *)(unaff_EDI + 0xcdc) = (float)fVar12;
      if (*(char *)(unaff_EDI + 0xd08) == '\0') {
        fVar13 = (float10)DragCameraManager__GetNewVelocity
                                    (unaff_EDI,*(undefined4 *)(unaff_EDI + 0xce0),0x42c80000,
                                     0x41200000,0x42c80000);
        *(float *)(unaff_EDI + 0xce0) = (float)fVar13;
      }
      fVar13 = (float10)DragCameraManager__GetNewVelocity
                                  (unaff_EDI,*(undefined4 *)(unaff_EDI + 0xce8),0x42480000,
                                   0x41c80000,0x42480000);
      *(float *)(unaff_EDI + 0xce8) = (float)fVar13;
      fVar14 = (float10)DragCameraManager__GetNewVelocity
                                  (unaff_EDI,*(undefined4 *)(unaff_EDI + 0xcec),0x42480000,
                                   0x41c80000,0x42480000);
      *(float *)(unaff_EDI + 0xcec) = (float)fVar14;
      fVar14 = (float10)GetAnalogInput();
      uVar6 = bDegreesToAngle16(0x42b40000);
      fVar4 = (float)uVar6 * (float)-fVar14 * DAT_0073ad38;
      fVar14 = (float10)GetAnalogInput();
      fVar2 = (float)(fVar14 * (float10)50.0 * (float10)DAT_0073ad38);
      fVar14 = (float10)GetAnalogInput();
      fVar3 = (float)(-fVar14 * (float10)50.0 * (float10)DAT_0073ad38);
      bDegreesToAngle16(0x42b40000);
      GetAnalogInput();
      uVar7 = _ftol_nocw();
      *(undefined2 *)(unaff_EDI + 0xcd4) = uVar7;
      sVar8 = bDegreesToAngle16(0x42aa0000);
      sVar8 = bDegreesToAngle16(0xc2aa0000,(float)(int)sVar8);
      fVar10 = (float)(int)*(short *)(unaff_EDI + 0xcd6);
      bClampF((float)(int)fVar10 + fVar4,(float)(int)sVar8);
      uVar7 = _ftol_nocw();
      fVar5 = (float)fVar13 * DAT_0073ad38;
      *(undefined2 *)(unaff_EDI + 0xcd6) = uVar7;
      fVar13 = (float10)bClampF(fVar5 + *(float *)(unaff_EDI + 0xcd8),0x3f000000,0x447a0000);
      *(float *)(unaff_EDI + 0xcd8) = (float)fVar13;
      pfVar1 = (float *)(unaff_EDI + 0x10c + (*(int *)(unaff_EDI + 0xcb4) * 0x13 + iVar11) * 4);
      fVar12 = (float10)bClampF((float)fVar12 * DAT_0073ad38 + *pfVar1,0x41200000,0x43160000);
      *pfVar1 = (float)fVar12;
      pfVar1 = (float *)(unaff_EDI + 0x114 + (*(int *)(unaff_EDI + 0xcb4) * 0x13 + iVar11) * 4);
      fVar12 = (float10)bClampF(DAT_0073ad38 * *(float *)(unaff_EDI + 0xce0) + *pfVar1,0x3dcccccd,
                                0x447a0000);
      *pfVar1 = (float)fVar12;
      pfVar1 = (float *)(unaff_EDI + *(int *)(unaff_EDI + 0xcb4) * 0x4c + (iVar11 * 3 + 0x3f) * 4);
      *pfVar1 = DAT_0073ad38 * *(float *)(unaff_EDI + 0xcec) + *pfVar1;
      Angle16SinCos();
      local_60 = -(fVar10 * fVar2) - fVar4 * fVar3;
      local_58 = 0;
      local_5c = fVar4 * fVar2 - fVar10 * fVar3;
      if (*(char *)(*(int *)(unaff_EDI + 0xcb4) * 0x4c + 0xd4 + unaff_EDI) != '\0') {
        Matrix_InvertRigid();
        D3DXVec3Transform(&local_60,&local_60,local_50);
      }
      pfVar1 = (float *)(*(int *)(unaff_EDI + 0xcb4) * 0x4c + iVar11 * 0xc + 0xf4 + unaff_EDI);
      *pfVar1 = local_60 + *pfVar1;
      pfVar1 = (float *)(*(int *)(unaff_EDI + 0xcb4) * 0x4c + iVar11 * 0xc + 0xf8 + unaff_EDI);
      *pfVar1 = local_5c + *pfVar1;
      FUN_00480ff0(unaff_EDI);
    }
    FUN_00481160(unaff_EDI,*(undefined4 *)(unaff_EDI + 0xcc0));
  }
  return;
}


// ==== 0x482f00 DragCameras::Parse

/* [canon] assets high (Ghidra make FUN_00482f00) docs/re/assets.md */

void __thiscall DragCameras__Parse(int *param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  uint uStack_4;
  
  iVar1 = 0;
  if (in_EAX < 1) {
    return;
  }
  uStack_4 = 0;
  if (*param_1 == 0x12345678) {
    uStack_4 = param_1[1];
    in_EAX = in_EAX + -8;
    if (4 < uStack_4) {
      iVar2 = 0;
      goto LAB_00482f51;
    }
  }
  switch(uStack_4) {
  default:
    iVar2 = 0x40;
    break;
  case 3:
    iVar2 = 0x48;
    break;
  case 4:
    iVar2 = 0x4c;
  }
LAB_00482f51:
  iVar2 = in_EAX / iVar2;
  if (iVar2 != 0) {
    if (0x27 < iVar2) {
      iVar2 = 0x28;
    }
    *(int *)(param_2 + 0xcb0) = iVar2;
    if (0 < iVar2) {
      do {
        DragCameraData__LoadFromVersion();
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_2 + 0xcb0));
    }
  }
  return;
}


// ==== 0x482f06 FUN_00482f06

void __thiscall FUN_00482f06(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int in_EAX;
  uint uVar1;
  uint unaff_EBX;
  bool in_ZF;
  char in_SF;
  char in_OF;
  
  if (in_ZF || in_OF != in_SF) {
    return;
  }
  uVar1 = unaff_EBX;
  if (*param_1 == 0x12345678) {
    uVar1 = param_1[1];
    if (4 < uVar1) {
      uVar1 = (in_EAX + -8) / 0;
      if (uVar1 == unaff_EBX) {
        return;
      }
      if (0x27 < (int)uVar1) {
        uVar1 = 0x28;
      }
      *(uint *)(param_4 + 0xcb0) = uVar1;
      if ((int)uVar1 <= (int)unaff_EBX) {
        return;
      }
      do {
        DragCameraData__LoadFromVersion();
        unaff_EBX = unaff_EBX + 1;
      } while ((int)unaff_EBX < *(int *)(param_4 + 0xcb0));
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00482f33. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&PTR_LAB_00482fa0)[uVar1])();
  return;
}


// ==== 0x482fc0 FUN_00482fc0

void FUN_00482fc0(void)

{
  int in_EAX;
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  size_t _Size;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 local_80 [128];
  
  _Size = *(int *)(in_EAX + 0xcb0) * 0x4c + 8;
  puVar1 = _malloc(_Size);
  *puVar1 = 0x12345678;
  puVar1[1] = 4;
  puVar5 = (undefined4 *)(in_EAX + 0xd0);
  puVar6 = puVar1 + 2;
  for (uVar2 = (uint)(*(int *)(in_EAX + 0xcb0) * 0x4c) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  FUN_00565da0("..\\..\\World\\Location1\\Track_%04d\\DragCameras.bin",DAT_0078a2f0);
  iVar3 = bOpenFile(local_80,1,6);
  if (iVar3 != 0) {
    FUN_0063c290(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8),puVar1,_Size,100);
    iVar4 = *(int *)(iVar3 + 8) + _Size;
    *(int *)(iVar3 + 8) = iVar4;
    if (*(int *)(iVar3 + 4) < iVar4) {
      *(int *)(iVar3 + 4) = iVar4;
    }
    FUN_00594d40();
  }
  return;
}


// ==== 0x483080 DragCameras::Loader

/* [canon] assets high (Ghidra make FUN_00483080 (Hopper export lacks it)) docs/re/assets.md */

undefined4 DragCameras__Loader(int *param_1)

{
  if (*param_1 == 0x3b200) {
    DragCameras__Parse(&DAT_007789f0);
    return 1;
  }
  return 0;
}


// ==== 0x4830b0 DragCameras::Unloader

/* [canon] assets high (Hopper sub_4830b0 + Ghidra make: H+G agree) docs/re/assets.md */

bool DragCameras__Unloader(int *param_1)

{
  return *param_1 == 0x3b200;
}


// ==== 0x4830d0 FUN_004830d0

undefined4 * __thiscall FUN_004830d0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006c7d78;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4830f0 FUN_004830f0

void __fastcall FUN_004830f0(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *in_EAX;
  undefined2 unaff_SI;
  
  uVar1 = *param_2;
  *(undefined2 *)((int)in_EAX + 0x2e) = unaff_SI;
  in_EAX[9] = uVar1;
  *in_EAX = 0;
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  *(undefined2 *)(in_EAX + 0xb) = 0;
  in_EAX[10] = param_3;
  uVar1 = param_2[1];
  in_EAX[0x16] = param_3;
  in_EAX[0x15] = uVar1;
  in_EAX[0xc] = 0;
  in_EAX[0xd] = 0;
  in_EAX[0xe] = 0;
  in_EAX[0xf] = 0;
  *(undefined2 *)(in_EAX + 0x17) = 0;
  *(undefined2 *)((int)in_EAX + 0x5e) = unaff_SI;
  in_EAX[0x21] = param_2[2];
  in_EAX[0x18] = 0;
  in_EAX[0x19] = 0;
  in_EAX[0x1a] = 0;
  in_EAX[0x1b] = 0;
  in_EAX[0x22] = param_3;
  *(undefined2 *)(in_EAX + 0x23) = 0;
  *(undefined2 *)((int)in_EAX + 0x8e) = unaff_SI;
  return;
}


// ==== 0x483160 FUN_00483160

void __thiscall FUN_00483160(float *param_1,float param_2,float param_3,float param_4)

{
  *param_1 = param_2;
  if (param_2 != param_1[2]) {
    *(undefined2 *)(param_1 + 0xb) = 2;
  }
  param_1[0xc] = param_3;
  if (param_3 != param_1[0xe]) {
    *(undefined2 *)(param_1 + 0x17) = 2;
  }
  param_1[0x18] = param_4;
  if (param_4 != param_1[0x1a]) {
    *(undefined2 *)(param_1 + 0x23) = 2;
  }
  return;
}


// ==== 0x4831c0 FUN_004831c0

void __thiscall FUN_004831c0(float *param_1,float param_2,float param_3,float param_4)

{
  param_1[2] = param_2;
  if (param_2 != *param_1) {
    *(undefined2 *)(param_1 + 0xb) = 2;
  }
  param_1[0xe] = param_3;
  if (param_3 != param_1[0xc]) {
    *(undefined2 *)(param_1 + 0x17) = 2;
  }
  param_1[0x1a] = param_4;
  if (param_4 != param_1[0x18]) {
    *(undefined2 *)(param_1 + 0x23) = 2;
  }
  return;
}


// ==== 0x483220 FUN_00483220

void FUN_00483220(void)

{
  float fVar1;
  float *in_EAX;
  
  fVar1 = in_EAX[2] - *in_EAX;
  in_EAX[6] = in_EAX[1];
  in_EAX[7] = *in_EAX;
  in_EAX[4] = (in_EAX[1] + in_EAX[3]) - (fVar1 + fVar1);
  in_EAX[5] = (fVar1 * 3.0 - in_EAX[3]) - (in_EAX[1] + in_EAX[1]);
  fVar1 = in_EAX[0xe] - in_EAX[0xc];
  in_EAX[0x12] = in_EAX[0xd];
  in_EAX[0x13] = in_EAX[0xc];
  in_EAX[0x10] = (in_EAX[0xd] + in_EAX[0xf]) - (fVar1 + fVar1);
  in_EAX[0x11] = (fVar1 * 3.0 - in_EAX[0xf]) - (in_EAX[0xd] + in_EAX[0xd]);
  fVar1 = in_EAX[0x1a] - in_EAX[0x18];
  in_EAX[0x1e] = in_EAX[0x19];
  in_EAX[0x1f] = in_EAX[0x18];
  in_EAX[0x1c] = (in_EAX[0x19] + in_EAX[0x1b]) - (fVar1 + fVar1);
  in_EAX[0x1d] = (fVar1 * 3.0 - in_EAX[0x1b]) - (in_EAX[0x19] + in_EAX[0x19]);
  return;
}


// ==== 0x4832c0 FUN_004832c0

int __fastcall FUN_004832c0(int param_1)

{
  return *(int *)(param_1 + 0x1c) + 0x60;
}


// ==== 0x4832d0 DriveCameraMover::SetPovType

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

void __thiscall DriveCameraMover__SetPovType(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x30) = param_2;
  return;
}


// ==== 0x4832e0 DriveCameraMover::SetLookBack

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

void __thiscall DriveCameraMover__SetLookBack(int param_1,char param_2)

{
  if (param_2 != '\0') {
    *(undefined4 *)(param_1 + 0x34) = 0x3f800000;
    return;
  }
  *(undefined4 *)(param_1 + 0x34) = 0;
  return;
}


// ==== 0x483300 FUN_00483300

void __thiscall FUN_00483300(int param_1,byte param_2)

{
  *(uint *)(param_1 + 0x32c) = (uint)param_2;
  return;
}


// ==== 0x483310 FUN_00483310

void __thiscall FUN_00483310(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x330) = param_2;
  return;
}


// ==== 0x483320 FUN_00483320

undefined2 __fastcall FUN_00483320(int param_1)

{
  return *(undefined2 *)(param_1 + 0x44);
}


// ==== 0x483330 FUN_00483330

undefined4 __fastcall FUN_00483330(int param_1)

{
  return *(undefined4 *)(param_1 + 0x2c);
}


// ==== 0x483340 FUN_00483340

undefined4 __fastcall FUN_00483340(int param_1)

{
  return *(undefined4 *)(param_1 + 0xb0);
}


// ==== 0x483350 FUN_00483350

undefined4 __fastcall FUN_00483350(int param_1)

{
  return *(undefined4 *)(param_1 + 0x198);
}


// ==== 0x483360 FUN_00483360

undefined4 __fastcall FUN_00483360(int param_1)

{
  return *(undefined4 *)(param_1 + 0x438);
}


// ==== 0x483370 FUN_00483370

void __thiscall FUN_00483370(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x45) = param_2;
  return;
}


// ==== 0x483380 FUN_00483380

void __thiscall FUN_00483380(int param_1,char param_2)

{
  *(bool *)(param_1 + 0x44) = param_2 == '\0';
  return;
}


// ==== 0x483390 FUN_00483390

uint __fastcall FUN_00483390(int param_1)

{
  return -(uint)(*(char *)(param_1 + 0x45) != '\0') & 0x8000;
}


// ==== 0x4833a0 FUN_004833a0

int __fastcall FUN_004833a0(byte param_1)

{
  int in_EAX;
  
  if ((*(uint *)(in_EAX + 0x530) & 1 << (param_1 & 0x1f)) != 0) {
    return in_EAX + 0x4e0;
  }
  return in_EAX + 0x90;
}


// ==== 0x4833c0 FUN_004833c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004833c0(float param_1,float param_2)

{
  short sVar1;
  short sVar2;
  
  sVar1 = Atan2ToAngle16(param_1,0x417f5c2a);
  sVar2 = Atan2ToAngle16(param_2 * 0.01 + param_1,0x417f5c2a);
  return (float10)((int)(short)(sVar2 << 1) - (int)(short)(sVar1 << 1)) * (float10)100.0;
}


// ==== 0x483430 FUN_00483430

float * __fastcall FUN_00483430(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *unaff_ESI;
  
  fVar1 = *unaff_ESI;
  if (*unaff_ESI < *param_1) {
    fVar1 = *param_1;
  }
  if (*param_2 < fVar1) {
    fVar1 = *param_2;
  }
  fVar2 = unaff_ESI[1];
  if (unaff_ESI[1] < param_1[1]) {
    fVar2 = param_1[1];
  }
  if (param_2[1] < fVar2) {
    fVar2 = param_2[1];
  }
  fVar3 = unaff_ESI[2];
  if (unaff_ESI[2] < param_1[2]) {
    fVar3 = param_1[2];
  }
  if (param_2[2] < fVar3) {
    fVar3 = param_2[2];
  }
  *param_1 = fVar1;
  param_1[1] = fVar2;
  param_1[2] = fVar3;
  return param_1;
}


// ==== 0x4834e0 CameraMover::ctor

/* [canon] camera I (M) docs/re/camera.md */

void __fastcall CameraMover__ctor(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_EAX;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_CameraMover__TrivialDtor_006c7c50;
  unaff_ESI[4] = in_EAX;
  unaff_ESI[5] = 0;
  unaff_ESI[3] = param_2;
  unaff_ESI[8] = 0;
  if (in_EAX == -1) {
    unaff_ESI[6] = 0;
    unaff_ESI[7] = 0;
    unaff_ESI[9] = 0;
    unaff_ESI[10] = 0;
    return;
  }
  unaff_ESI[6] = &DAT_00740460 + in_EAX * 0x18;
  iVar1 = (&DAT_007404a0)[in_EAX * 0x18];
  unaff_ESI[7] = iVar1;
  *(undefined4 *)(iVar1 + 0xc0) = 0x461c4000;
  unaff_ESI[9] = *(undefined4 *)(unaff_ESI[7] + 0x280);
  unaff_ESI[10] = *(undefined4 *)(unaff_ESI[7] + 0x284);
  FUN_004835a0();
  return;
}


// ==== 0x483550 FUN_00483550

void __fastcall FUN_00483550(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_CameraMover__TrivialDtor_006c7c50;
  if (param_1[5] != 0) {
    param_1[5] = 0;
    param_1[9] = *(undefined4 *)(param_1[7] + 0x280);
    param_1[10] = *(undefined4 *)(param_1[7] + 0x284);
    iVar1 = param_1[1];
    piVar2 = (int *)param_1[2];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    ViewList_UpdateViewCountKind();
    return;
  }
  return;
}


// ==== 0x483590 CameraMover::GetCarToFollow

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

undefined4 __fastcall CameraMover__GetCarToFollow(int param_1)

{
  if (*(int *)(param_1 + 0x20) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x20) + 4);
  }
  return 0;
}


// ==== 0x4835a0 FUN_004835a0

void __fastcall FUN_004835a0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int extraout_EDX;
  bool bVar4;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    bVar4 = DAT_00735f5c == 0;
    *(undefined4 *)(param_1 + 0x14) = 1;
    if (bVar4) {
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x280) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x284) = *(undefined4 *)(param_1 + 0x28);
    }
    piVar1 = (int *)(param_1 + 4);
    piVar3 = (int *)(*(int *)(param_1 + 0x18) + 0x44);
    iVar2 = *piVar3;
    *piVar3 = (int)piVar1;
    *(int **)(iVar2 + 4) = piVar1;
    *(int **)(param_1 + 8) = piVar3;
    *piVar1 = iVar2;
    ViewList_UpdateViewCountKind();
    *(undefined4 *)(*(int *)(extraout_EDX + 0x1c) + 0xbc) = 0x3f000000;
  }
  return;
}


// ==== 0x483600 FUN_00483600

void __fastcall FUN_00483600(int param_1)

{
  int iVar1;
  int *piVar2;
  
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


// ==== 0x483640 Camera::ApplyNoise

/* WARNING: Removing unreachable block (ram,0x004837d1) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera I (M+C) docs/re/camera.md */

void Camera__ApplyNoise(int param_1,undefined4 param_2,float *param_3,int param_4)

{
  float fVar1;
  int iVar2;
  char cVar3;
  short sVar4;
  int iVar5;
  float *pfVar6;
  undefined4 uStack_84;
  float fStack_7c;
  float local_78;
  float local_74;
  undefined1 local_70 [16];
  float local_60 [4];
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float fStack_28;
  float fStack_24;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  fVar1 = *(float *)(iVar2 + 0x1e0);
  Curve_Evaluate(&local_74,
                 SQRT(*(float *)(iVar2 + 0x1e8) * *(float *)(iVar2 + 0x1e8) +
                      *(float *)(iVar2 + 0x1e4) * *(float *)(iVar2 + 0x1e4) + fVar1 * fVar1));
  local_78 = local_74;
  pfVar6 = local_60;
  for (iVar5 = 0x13; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pfVar6 = *param_3;
    param_3 = param_3 + 1;
    pfVar6 = pfVar6 + 1;
  }
  if (((param_4 != 0) && (param_4 != -0x40)) && (cVar3 = CarState__IsNitrousOn(), cVar3 != '\0')) {
    local_78 = local_74 + 0.2;
    local_60[0] = local_60[0] * 1.8;
    local_50 = local_50 * 1.8;
    local_60[1] = local_60[1] * 1.8;
    local_4c = local_4c * 1.8;
    local_60[2] = local_60[2] * 1.8;
    local_48 = local_48 * 1.8;
    local_60[3] = local_60[3] * 1.8;
    local_44 = local_44 * 1.8;
  }
  if (0.0 < local_78) {
    D3DXVec3Transform(local_70,(float *)(iVar2 + 0x1e0),param_2);
    bNormalize3();
    sVar4 = FUN_00564cd0(ABS(local_74));
    fVar1 = (float)(ushort)(0x4000 - sVar4) * 6.1035156e-05;
    bScaleToLength2(0x3e999998);
    fStack_28 = (((ABS(fStack_7c) + 1.5) - _K_ONE) * fVar1 + _K_ONE) * fStack_28;
    fStack_24 = (((ABS(local_78) + 1.5) - _K_ONE) * fVar1 + _K_ONE) * fStack_24;
    Camera_SetShakeBasisFromMatrix();
    FUN_0047d940((float)DAT_0073ad34 * 0.00025,uStack_84);
  }
  return;
}


// ==== 0x483860 CameraMover::ComputeBankedUpVector

/* [canon] camera I (M) docs/re/camera.md */

void __thiscall CameraMover__ComputeBankedUpVector(float *param_1,undefined4 param_2)

{
  float *in_EAX;
  float local_60;
  float local_5c;
  float local_58;
  undefined1 local_50 [76];
  
  local_60 = *in_EAX - *param_1;
  local_5c = in_EAX[1] - param_1[1];
  local_58 = in_EAX[2] - param_1[2];
  bNormalize3();
  FUN_0040b6a0();
  local_60 = 0.0;
  local_5c = 0.0;
  local_58 = 1.0;
  D3DXVec3Transform(param_2,&local_60,local_50);
  return;
}


// ==== 0x4838d0 FUN_004838d0

float10 FUN_004838d0(void)

{
  return (float10)(float)0x3f333333;
}


// ==== 0x4838e0 CameraMover::EnforceMinGapToWalls

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera V (G+C) docs/re/camera.md */

void CameraMover__EnforceMinGapToWalls
               (int *param_1,int param_2,undefined4 param_3,float *param_4,float *param_5)

{
  int iVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  float10 fVar5;
  int local_50;
  float local_4c;
  int *local_48;
  int local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  local_30 = *param_4;
  local_2c = param_4[1];
  local_28 = param_4[2];
  FUN_00441030(param_2,1,1,&local_30,0x3c23d70a,0x3f800000);
  local_40 = local_30 - *param_4;
  local_44 = 0;
  local_3c = local_2c - param_4[1];
  local_38 = local_28 - param_4[2];
  do {
    iVar4 = 0;
    local_20 = local_40 + *param_4;
    local_50 = 0;
    local_30 = 0.0;
    local_2c = 0.0;
    local_1c = local_3c + param_4[1];
    local_28 = 0.0;
    local_18 = local_38 + param_4[2];
    if (*(int *)(param_2 + 0x2a0) < 1) break;
    local_48 = (int *)(param_2 + 0x20);
    do {
      iVar1 = *local_48;
      if (((&DAT_006ef2dd)[*(char *)(iVar1 + 0xb) * 0x94] == '\0') &&
         (cVar3 = TrackPolygon__PointInShaft(&local_4c), cVar3 != '\0')) {
        if ((*(byte *)(iVar1 + 10) & 2) == 0) {
          fVar5 = (float10)_CamWallPushOut;
        }
        else {
          fVar5 = (float10)(**(code **)(*param_1 + 0x2c))();
        }
        if ((0.0 <= local_4c) && ((float10)local_4c < fVar5)) {
          fVar5 = fVar5 - (float10)local_4c;
          local_50 = local_50 + 1;
          local_30 = (float)(fVar5 * (float10)*(float *)(iVar1 + 0x70) + (float10)local_30);
          local_2c = (float)(fVar5 * (float10)*(float *)(iVar1 + 0x74) + (float10)local_2c);
          local_28 = (float)(fVar5 * (float10)*(float *)(iVar1 + 0x78) + (float10)local_28);
        }
      }
      iVar4 = iVar4 + 1;
      local_48 = local_48 + 1;
    } while (iVar4 < *(int *)(param_2 + 0x2a0));
    if (local_50 == 0) break;
    local_44 = local_44 + 1;
    fVar2 = _K_ONE / (float)local_50;
    local_40 = local_30 * fVar2 + local_40;
    local_3c = local_2c * fVar2 + local_3c;
    local_38 = local_28 * fVar2 + local_38;
  } while (local_44 < 3);
  *param_5 = local_40;
  param_5[3] = 0.0;
  param_5[1] = local_3c;
  param_5[2] = local_38;
  return;
}


// ==== 0x483ad0 FUN_00483ad0

void FUN_00483ad0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_c0 [16];
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined1 local_90 [52];
  undefined1 auStack_5c [88];
  
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0x3f800000;
  Matrix4_BuildLookAt(&local_b0);
  Matrix_InvertRigid();
  D3DXVec3Transform(local_c0,param_3,local_90);
  D3DXVec3Transform(&local_ac,&stack0xffffff34,auStack_5c);
  Matrix4_BuildLookAt(&stack0xffffff38);
  return;
}


// ==== 0x483b90 CameraMover_ClipAgainstWorld

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera med (hopper+capstone) docs/re/misc.md */

void __thiscall
CameraMover_ClipAgainstWorld(float *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fStack_35c;
  float local_358;
  float local_350;
  float local_34c;
  float local_348;
  float fStack_344;
  float fStack_30c;
  float fStack_308;
  float fStack_304;
  float local_300;
  float local_2fc;
  float local_2f8;
  float fStack_2f4;
  undefined1 local_2f0 [4];
  undefined1 auStack_2ec [32];
  int aiStack_2cc [160];
  int iStack_4c;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_2c;
  void *local_28;
  undefined4 local_24;
  void *pvStack_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  pcStack_18 = FUN_0068600b;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  Matrix_InvertRigid();
  if (param_1 == (float *)0x0) {
    param_1 = (float *)(param_4 + 0x60);
  }
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_2c = 0;
  local_28 = (void *)0x0;
  local_24 = 0;
  local_350 = *param_1 * _K_HALF + local_300 * _K_HALF;
  local_34c = param_1[1] * _K_HALF + local_2fc * _K_HALF;
  local_348 = param_1[2] * _K_HALF + local_2f8 * _K_HALF;
  local_358 = (SQRT((*param_1 - local_300) * (*param_1 - local_300) +
                    (param_1[1] - local_2fc) * (param_1[1] - local_2fc) +
                    (param_1[2] - local_2f8) * (param_1[2] - local_2f8)) + _K_ONE) * _K_HALF;
  FUN_00440740();
  local_14 = 0;
  GroundQuery__RefillCache(&local_350,local_358,0);
  D3DXVec3Transform(local_2f0,param_1,param_3);
  fStack_35c = local_2fc * (_K_ONE / fStack_2f4);
  local_358 = (_K_ONE / fStack_2f4) * local_2f8;
  CameraMover__EnforceMinGapToWalls(param_2,auStack_2ec,param_1,&fStack_30c,&local_34c);
  fStack_30c = fStack_30c + local_34c;
  fStack_308 = fStack_308 + local_348;
  fStack_304 = fStack_304 + fStack_344;
  if (param_4 != 0) {
    fStack_344 = fStack_304 - param_1[2];
    fVar3 = (fStack_308 - param_1[1]) * (fStack_308 - param_1[1]);
    fVar2 = (fStack_30c - *param_1) * (fStack_30c - *param_1);
    local_34c = *(float *)(*(int *)(param_4 + 0x3c) + 0x100);
    fVar4 = ABS(*(float *)(*(int *)(param_4 + 0x3c) + 0xf0));
    if (fVar4 < local_34c) {
      fVar4 = local_34c;
    }
    fVar4 = fVar4 + 0.7;
    if (SQRT(fStack_344 * fStack_344 + fVar2 + fVar3) < fVar4) {
      fStack_304 = SQRT(fVar4 * fVar4 - (fVar2 + fVar3)) + param_1[2];
    }
  }
  FUN_00483ad0(param_2,param_3,param_1,&fStack_35c);
  iVar5 = 0;
  if (0 < iStack_4c) {
    do {
      piVar1 = aiStack_2cc + iVar5;
      iVar5 = iVar5 + 1;
      *(char *)(*piVar1 + 8) = *(char *)(*piVar1 + 8) + -1;
    } while (iVar5 < iStack_4c);
  }
  ExceptionList = local_28;
  return;
}


// ==== 0x483e30 FUN_00483e30

void __fastcall FUN_00483e30(float *param_1)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  
  fVar2 = (float)*(ushort *)(*(int *)(in_EAX + 0x1c) + 0x264);
  fVar1 = fVar2 * DAT_0073457c + (float)*(ushort *)(*(int *)(in_EAX + 0x1c) + 0xc4);
  fVar2 = fVar2 * param_1[9];
  *param_1 = fVar1;
  if (fVar1 != param_1[2]) {
    *(undefined2 *)(param_1 + 0xb) = 2;
  }
  param_1[1] = fVar2;
  if (fVar2 != param_1[3]) {
    *(undefined2 *)(param_1 + 0xb) = 2;
  }
  return;
}


// ==== 0x483ea0 FUN_00483ea0

void FUN_00483ea0(int param_1,float *param_2)

{
  int iVar1;
  int in_EAX;
  int unaff_EDI;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  undefined4 uStack_34;
  float local_30;
  float local_2c;
  float local_28;
  float fStack_18;
  
  iVar1 = *(int *)(in_EAX + 0x1c);
  local_2c = DAT_0073457c * *(float *)(iVar1 + 0x1e4) + *(float *)(iVar1 + 0x44);
  local_28 = DAT_0073457c * *(float *)(iVar1 + 0x1e8) + *(float *)(iVar1 + 0x48);
  local_30 = DAT_0073457c * *(float *)(iVar1 + 0x1e0) + *(float *)(iVar1 + 0x40);
  if (unaff_EDI != 0) {
    D3DXVec3Transform(&local_30,&local_30);
  }
  FUN_00483160(local_30,local_2c,local_28);
  iVar1 = *(int *)(in_EAX + 0x1c);
  fStack_40 = *(float *)(iVar1 + 0x1e0);
  fStack_3c = *(float *)(iVar1 + 0x1e4);
  fStack_18 = *(float *)(iVar1 + 0x1e8);
  if (param_2 != (float *)0x0) {
    fStack_40 = fStack_40 - *param_2;
    fStack_3c = fStack_3c - param_2[1];
    fStack_18 = fStack_18 - param_2[2];
  }
  fStack_38 = *(float *)(param_1 + 0x24);
  fStack_40 = fStack_40 * fStack_38;
  uStack_34 = 0;
  fStack_3c = fStack_3c * fStack_38;
  fStack_38 = fStack_18 * fStack_38;
  if (unaff_EDI != 0) {
    thunk_FUN_005ac436(&fStack_40,&fStack_40);
  }
  FUN_00593bc0(fStack_40,fStack_3c,fStack_38);
  return;
}


// ==== 0x483fb0 FUN_00483fb0

void FUN_00483fb0(int param_1,float *param_2)

{
  int iVar1;
  int in_EAX;
  int unaff_EDI;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  undefined4 uStack_34;
  float local_30;
  float local_2c;
  float local_28;
  float fStack_18;
  
  iVar1 = *(int *)(in_EAX + 0x1c);
  local_2c = DAT_0073457c * *(float *)(iVar1 + 0x204) + *(float *)(iVar1 + 100);
  local_28 = DAT_0073457c * *(float *)(iVar1 + 0x208) + *(float *)(iVar1 + 0x68);
  local_30 = DAT_0073457c * *(float *)(iVar1 + 0x200) + *(float *)(iVar1 + 0x60);
  if (unaff_EDI != 0) {
    D3DXVec3Transform(&local_30,&local_30);
  }
  FUN_00483160(local_30,local_2c,local_28);
  iVar1 = *(int *)(in_EAX + 0x1c);
  fStack_40 = *(float *)(iVar1 + 0x200);
  fStack_3c = *(float *)(iVar1 + 0x204);
  fStack_18 = *(float *)(iVar1 + 0x208);
  if (param_2 != (float *)0x0) {
    fStack_40 = fStack_40 - *param_2;
    fStack_3c = fStack_3c - param_2[1];
    fStack_18 = fStack_18 - param_2[2];
  }
  fStack_38 = *(float *)(param_1 + 0x24);
  fStack_40 = fStack_40 * fStack_38;
  uStack_34 = 0;
  fStack_3c = fStack_3c * fStack_38;
  fStack_38 = fStack_18 * fStack_38;
  if (unaff_EDI != 0) {
    thunk_FUN_005ac436(&fStack_40,&fStack_40);
  }
  FUN_00593bc0(fStack_40,fStack_3c,fStack_38);
  return;
}


// ==== 0x4840c0 OrbitCarCameraMover::ctor

/* [canon] camera V (G+C) docs/re/camera.md */

undefined4 *
OrbitCarCameraMover__ctor
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686878;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CameraMover__ctor();
  *(undefined2 *)((int)param_1 + 0x32) = 62000;
  *(undefined2 *)(param_1 + 0xd) = 62000;
  param_1[0x14] = 0x3f800000;
  param_1[0x16] = 0x3f800000;
  param_1[0x2c] = param_3;
  bVar1 = DAT_00735f5c == 0;
  param_1[0xb] = 0x40a00000;
  param_1[0x12] = 0x40a00000;
  local_4 = 0;
  *param_1 = &PTR_FUN_006c8018;
  *(undefined2 *)(param_1 + 0xc) = 26000;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x13] = 0x447a0000;
  *(undefined2 *)(param_1 + 0x15) = 51000;
  *(undefined2 *)((int)param_1 + 0x56) = 0xf8f4;
  param_1[0x17] = 0x3ecccccd;
  param_1[0x18] = 0x18;
  param_1[0x1a] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = param_4;
  param_1[0x19] = 0;
  if (bVar1) {
    *(undefined4 *)(param_1[7] + 0x280) = 0;
    *(undefined4 *)(param_1[7] + 0x284) = 0;
    *(undefined2 *)(param_1[7] + 0xc4) = DAT_006fbe34;
  }
  param_1[0x30] = 0;
  FUN_00484270();
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x4841c0 FUN_004841c0

void * __thiscall FUN_004841c0(void *param_1,byte param_2)

{
  FUN_004841e0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4841e0 FUN_004841e0

void __fastcall FUN_004841e0(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_006c8018;
  FUN_00484340();
  if (DAT_00735f5c == 0) {
    *(undefined4 *)(param_1[7] + 0xb4) = 0;
    *(undefined4 *)(param_1[7] + 0xb8) = 0;
  }
  *param_1 = &PTR_CameraMover__TrivialDtor_006c7c50;
  if (param_1[5] != 0) {
    param_1[5] = 0;
    param_1[9] = *(undefined4 *)(param_1[7] + 0x280);
    param_1[10] = *(undefined4 *)(param_1[7] + 0x284);
    iVar1 = param_1[1];
    piVar2 = (int *)param_1[2];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    ViewList_UpdateViewCountKind();
    return;
  }
  return;
}


// ==== 0x484250 FUN_00484250

int __fastcall FUN_00484250(int param_1)

{
  if (*(int *)(param_1 + 0xb0) != 0) {
    return *(int *)(param_1 + 0xb0) + 0x50;
  }
  return *(int *)(param_1 + 0x1c) + 0x60;
}


// ==== 0x484270 FUN_00484270

void __fastcall FUN_00484270(int param_1)

{
  if (*(int *)(param_1 + 0xc0) == 0) {
    InputEvents__AddSource(0x45,FUN_004847b0,param_1);
    InputEvents__AddSource(0x46,FUN_004847b0,param_1);
    InputEvents__AddSource(0x47,FUN_004847b0,param_1);
    InputEvents__AddSource(0x48,FUN_004847b0,param_1);
    InputEvents__AddSource(0x49,FUN_004847b0,param_1);
    InputEvents__AddSource(0x4a,FUN_004847b0,param_1);
    InputEvents__AddSource(0x4b,FUN_004847b0,param_1);
    InputEvents__AddSource(0x4c,FUN_004847b0,param_1);
    InputEvents__AddSource(0x4d,FUN_004847b0,param_1);
    *(undefined4 *)(param_1 + 0xc0) = 1;
  }
  return;
}


// ==== 0x484340 FUN_00484340

void __fastcall FUN_00484340(int param_1)

{
  if (*(int *)(param_1 + 0xc0) != 0) {
    FUN_005740b0(0x45);
    FUN_005740b0(0x46);
    FUN_005740b0(0x47);
    FUN_005740b0(0x48);
    FUN_005740b0(0x49);
    FUN_005740b0(0x4a);
    FUN_005740b0(0x4b);
    FUN_005740b0(0x4c);
    FUN_005740b0(0x4d);
    *(undefined4 *)(param_1 + 0xc0) = 0;
  }
  return;
}


// ==== 0x4843e0 FUN_004843e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004843e0(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  ushort uVar5;
  int iVar6;
  undefined1 auStack_11c [4];
  undefined1 auStack_118 [8];
  undefined1 local_110 [48];
  float fStack_e0;
  float fStack_dc;
  float local_d8;
  float fStack_d4;
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
  undefined4 local_94;
  undefined1 auStack_90 [56];
  undefined1 auStack_58 [8];
  undefined1 local_50 [76];
  
  cVar4 = FUN_0043a2e0();
  if (((cVar4 != '\0') || (DAT_007361f0 == (int *)0x0)) ||
     ((*DAT_007361f0 != 7 && (*DAT_007361f0 != 0xb)))) {
    iVar6 = *(int *)(param_1 + 0xb0);
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
    local_a0 = 0.0;
    local_9c = 0.0;
    local_98 = 0.0;
    local_94 = 0x3f800000;
    if (iVar6 == 0) {
      eIdentity();
      local_d8 = -_DAT_006fbe3c;
    }
    else {
      local_a0 = -*(float *)(iVar6 + 0x50);
      local_9c = -*(float *)(iVar6 + 0x54);
      local_98 = -*(float *)(iVar6 + 0x58) - _DAT_00735ef8;
      D3DXMatrixTranspose(local_50,iVar6 + 0x90);
      D3DXMatrixMultiply(auStack_118,&local_d8,auStack_58);
      fStack_e0 = fStack_e0 + _DAT_00736800;
      fStack_dc = fStack_dc + _DAT_00736804;
      local_d8 = _DAT_00736808 + local_d8;
      fStack_d4 = fStack_d4 + _DAT_0073680c;
    }
    if (*(int *)(param_1 + 0x58) != 0x3f800000) {
      *(float *)(param_1 + 0x48) = *(float *)(param_1 + 0x58) * *(float *)(param_1 + 0x48);
    }
    *(float *)(param_1 + 0x2c) = *(float *)(param_1 + 0x48);
    if (*(float *)(param_1 + 0x48) < *(float *)(param_1 + 0x50)) {
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x50);
    }
    if (*(float *)(param_1 + 0x4c) < *(float *)(param_1 + 0x2c)) {
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x4c);
    }
    if (*(float *)(param_1 + 0x48) < *(float *)(param_1 + 0x50)) {
      *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0x50);
    }
    if (*(float *)(param_1 + 0x4c) < *(float *)(param_1 + 0x48)) {
      *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0x4c);
    }
    iVar6 = *(int *)(param_1 + 0x40);
    iVar2 = *(int *)(param_1 + 0x38);
    iVar3 = *(int *)(param_1 + 0x60);
    if (iVar2 < iVar6) {
      if (iVar3 < iVar6 - iVar2) {
        iVar6 = iVar3 + iVar2;
      }
      *(int *)(param_1 + 0x38) = iVar6;
    }
    else {
      if (iVar3 < iVar2 - iVar6) {
        iVar6 = iVar2 - iVar3;
      }
      *(int *)(param_1 + 0x38) = iVar6;
    }
    iVar6 = *(int *)(param_1 + 0x44);
    iVar2 = *(int *)(param_1 + 0x3c);
    if (iVar2 < iVar6) {
      if (iVar3 < iVar6 - iVar2) {
        iVar6 = iVar2 + iVar3;
      }
      *(int *)(param_1 + 0x3c) = iVar6;
    }
    else {
      if (iVar3 < iVar2 - iVar6) {
        iVar6 = iVar2 - iVar3;
      }
      *(int *)(param_1 + 0x3c) = iVar6;
    }
    *(short *)(param_1 + 0x32) = *(short *)(param_1 + 0x32) + *(short *)(param_1 + 0x3c);
    uVar1 = *(ushort *)(param_1 + 0x32);
    if (*(int *)(param_1 + 0x68) != 0) {
      uVar5 = *(ushort *)(param_1 + 0x34);
      if (uVar1 < uVar5) {
        if (0x50 < (int)((uint)uVar5 - (uint)uVar1)) {
          uVar5 = uVar1 + 0x50;
        }
      }
      else if (0x50 < (int)((uint)uVar1 - (uint)uVar5)) {
        uVar5 = uVar1 - 0x50;
      }
      *(ushort *)(param_1 + 0x32) = uVar5;
    }
    *(short *)(param_1 + 0x30) = *(short *)(param_1 + 0x30) + *(short *)(param_1 + 0x38);
    if (DAT_00735ef4 == 0) {
      FUN_0040b930();
      D3DXMatrixMultiply(local_110,local_110,auStack_90);
      FUN_0040ba40(auStack_11c,auStack_11c);
    }
    else {
      FUN_0040b930();
      D3DXMatrixMultiply(local_110,local_110,auStack_90);
      FUN_0040ba40(auStack_11c,auStack_11c);
    }
    eTranslate(auStack_11c,auStack_11c);
    FUN_0040b990(auStack_11c,auStack_11c);
    FUN_0040ba40(auStack_11c,auStack_11c);
    if (DAT_00735f5c == 0) {
      *(undefined2 *)(*(int *)(param_1 + 0x1c) + 0xc4) = DAT_006fbe40;
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb0) = *(undefined4 *)(param_1 + 0x2c);
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb4) = *(undefined4 *)(param_1 + 0x2c);
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb8) = 0x41000000;
    }
    Camera__SetCameraMatrix(*(undefined4 *)(param_1 + 0x1c),auStack_11c,DAT_0073ad38);
  }
  return;
}


// ==== 0x4847b0 FUN_004847b0

void FUN_004847b0(undefined4 param_1,undefined4 param_2,char param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  iVar1 = *(int *)(param_4 + 100);
  uVar2 = (-(uint)(iVar1 != 0) & 0xffffff38) + 500;
  switch(param_2) {
  case 0x45:
    if (param_3 == '\0') {
      *(undefined4 *)(param_4 + 0x40) = 0;
      return;
    }
    *(uint *)(param_4 + 0x40) = -uVar2;
    return;
  case 0x46:
    *(uint *)(param_4 + 0x40) = -(uint)(param_3 != '\0') & uVar2;
    return;
  case 0x47:
    if (param_3 == '\0') {
      *(undefined4 *)(param_4 + 0x44) = 0;
      return;
    }
    *(uint *)(param_4 + 0x44) = -uVar2;
    return;
  case 0x48:
    *(uint *)(param_4 + 0x44) = -(uint)(param_3 != '\0') & uVar2;
    return;
  case 0x49:
    if (param_3 != '\0') {
      *(undefined4 *)(param_4 + 0x58) = 0x3f7d70a4;
      return;
    }
    goto LAB_0048483e;
  case 0x4a:
    if (param_3 != '\0') {
      *(undefined4 *)(param_4 + 0x58) = 0x3f8147ae;
      return;
    }
LAB_0048483e:
    *(undefined4 *)(param_4 + 0x58) = 0x3f800000;
    return;
  case 0x4b:
    if ((iVar1 == 0) && (param_3 != '\0')) {
      piVar3 = (int *)**(undefined4 **)(param_4 + 0xb0);
      if (piVar3 == DAT_007361f8) {
        piVar3 = (int *)*DAT_007361f8;
      }
      *(int **)(param_4 + 0xb0) = piVar3;
      return;
    }
    break;
  case 0x4c:
    if ((iVar1 == 0) && (param_3 != '\0')) {
      piVar3 = *(int **)(*(int *)(param_4 + 0xb0) + 4);
      if (piVar3 == DAT_007361f8) {
        piVar3 = (int *)DAT_007361f8[1];
      }
      *(int **)(param_4 + 0xb0) = piVar3;
      return;
    }
    break;
  case 0x4d:
    if (param_3 != '\0') {
      *(uint *)(param_4 + 0xb4) = (uint)(*(int *)(param_4 + 0xb4) == 0);
    }
  }
  return;
}


// ==== 0x48485a FUN_0048485a

void __thiscall FUN_0048485a(int param_1)

{
  int *piVar1;
  bool in_ZF;
  char in_stack_00000010;
  
  if ((in_ZF) && (in_stack_00000010 != '\0')) {
    piVar1 = (int *)**(undefined4 **)(param_1 + 0xb0);
    if (piVar1 == DAT_007361f8) {
      piVar1 = (int *)*DAT_007361f8;
    }
    *(int **)(param_1 + 0xb0) = piVar1;
    return;
  }
  return;
}


// ==== 0x4848f0 FUN_004848f0

undefined4 * FUN_004848f0(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  bool bVar5;
  
  CameraMover__ctor();
  *param_1 = &PTR_FUN_006c7f38;
  puVar4 = param_1 + 0xb;
  for (iVar3 = 0x29; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_3;
    param_3 = param_3 + 1;
    puVar4 = puVar4 + 1;
  }
  param_1[0x3a] = 0x4000;
  param_1[0x39] = 1;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x35] = 0;
  param_1[0x3f] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x34] = 100;
  param_1[0x46] = 0x4000;
  param_1[0x45] = 1;
  param_1[0x42] = 0;
  param_1[0x40] = 100;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x41] = 0;
  param_1[0x4b] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x4c] = 0;
  param_1[0x53] = 0x4000;
  param_1[0x52] = 1;
  param_1[0x4f] = 0;
  param_1[0x4d] = 100;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x4e] = 0;
  param_1[0x58] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  param_1[0x59] = 0;
  param_1[0x60] = 0x4000;
  param_1[0x5f] = 1;
  param_1[0x5c] = 0;
  param_1[0x5a] = 100;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5b] = 0;
  param_1[0x65] = 0;
  param_1[0x62] = 0;
  param_1[99] = 0;
  param_1[100] = 0;
  param_1[0x66] = param_2;
  param_1[0x10f] = 0;
  param_1[0x110] = 0;
  param_1[0x111] = 0;
  param_1[0x112] = 0;
  param_1[0x114] = 0;
  param_1[0x115] = 0;
  param_1[0x116] = 0;
  FUN_00440740();
  uVar1 = param_1[0x1a];
  if ((void *)param_1[0x5e] != (void *)0x0) {
    _free((void *)param_1[0x5e]);
    param_1[0x5e] = 0;
  }
  param_1[0x5d] = uVar1;
  param_1[0x5b] = 0x20;
  uVar1 = param_1[0x1f];
  uVar2 = param_1[0x20];
  if ((void *)param_1[0x38] != (void *)0x0) {
    _free((void *)param_1[0x38]);
    param_1[0x38] = 0;
  }
  param_1[0x37] = uVar2;
  param_1[0x35] = uVar1;
  uVar1 = param_1[0x1f];
  uVar2 = param_1[0x21];
  if ((void *)param_1[0x44] != (void *)0x0) {
    _free((void *)param_1[0x44]);
    param_1[0x44] = 0;
  }
  param_1[0x43] = uVar2;
  param_1[0x41] = uVar1;
  uVar1 = param_1[0x22];
  uVar2 = param_1[0x23];
  if ((void *)param_1[0x51] != (void *)0x0) {
    _free((void *)param_1[0x51]);
    param_1[0x51] = 0;
  }
  bVar5 = DAT_00735f5c == 0;
  param_1[0x50] = uVar2;
  param_1[0x4e] = uVar1;
  if (bVar5) {
    *(undefined4 *)(param_1[7] + 0x280) = 0;
    *(undefined4 *)(param_1[7] + 0x284) = 0;
    *(undefined2 *)(param_1[7] + 0xc4) = 0x32dc;
  }
  *(undefined4 *)(param_1[7] + 0xbc) = param_1[0x17];
  *(undefined4 *)(param_1[7] + 0xc0) = param_1[0x18];
  return param_1;
}


// ==== 0x484b80 FUN_00484b80

void * __thiscall FUN_00484b80(void *param_1,byte param_2)

{
  FUN_00484ba0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x484ba0 FUN_00484ba0

void __fastcall FUN_00484ba0(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  bool bVar4;
  
  bVar4 = DAT_00735f5c == 0;
  *param_1 = &PTR_FUN_006c7f38;
  if (bVar4) {
    *(undefined4 *)(param_1[7] + 0xb4) = 0;
    *(undefined4 *)(param_1[7] + 0xb8) = 0;
  }
  iVar3 = param_1[0x10f];
  if (0 < iVar3) {
    piVar2 = param_1 + 0x6f;
    do {
      iVar1 = *piVar2;
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + -1;
      *(char *)(iVar1 + 8) = *(char *)(iVar1 + 8) + -1;
    } while (iVar3 != 0);
  }
  if ((void *)param_1[0x5e] != (void *)0x0) {
    _free((void *)param_1[0x5e]);
  }
  if ((void *)param_1[0x65] != (void *)0x0) {
    _free((void *)param_1[0x65]);
  }
  if ((void *)param_1[0x51] != (void *)0x0) {
    _free((void *)param_1[0x51]);
  }
  if ((void *)param_1[0x58] != (void *)0x0) {
    _free((void *)param_1[0x58]);
  }
  if ((void *)param_1[0x44] != (void *)0x0) {
    _free((void *)param_1[0x44]);
  }
  if ((void *)param_1[0x4b] != (void *)0x0) {
    _free((void *)param_1[0x4b]);
  }
  if ((void *)param_1[0x38] != (void *)0x0) {
    _free((void *)param_1[0x38]);
  }
  if ((void *)param_1[0x3f] != (void *)0x0) {
    _free((void *)param_1[0x3f]);
  }
  *param_1 = &PTR_CameraMover__TrivialDtor_006c7c50;
  if (param_1[5] == 0) {
    return;
  }
  param_1[5] = 0;
  param_1[9] = *(undefined4 *)(param_1[7] + 0x280);
  param_1[10] = *(undefined4 *)(param_1[7] + 0x284);
  iVar3 = param_1[1];
  piVar2 = (int *)param_1[2];
  *piVar2 = iVar3;
  *(int **)(iVar3 + 4) = piVar2;
  ViewList_UpdateViewCountKind();
  return;
}


// ==== 0x484cd0 BumperCameraMover::IsFinished

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

undefined4 __fastcall BumperCameraMover__IsFinished(int param_1)

{
  float fVar1;
  bool bVar2;
  bool bVar3;
  
  bVar2 = false;
  if ((*(float *)(param_1 + 0x40) == 0.0) ||
     (fVar1 = (float)(*(int *)(param_1 + 0x7c) + -1),
     fVar1 < *(float *)(param_1 + 0x130) != (fVar1 == *(float *)(param_1 + 0x130)))) {
    bVar2 = true;
  }
  bVar3 = false;
  if ((*(float *)(param_1 + 0x44) == 0.0) ||
     (fVar1 = (float)(*(int *)(param_1 + 0x88) + -1),
     fVar1 < *(float *)(param_1 + 0x164) != (fVar1 == *(float *)(param_1 + 0x164)))) {
    bVar3 = true;
  }
  if ((bVar2) && (bVar3)) {
    return 1;
  }
  return 0;
}


// ==== 0x484d50 FUN_00484d50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00484d50(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  short sVar6;
  undefined2 uVar7;
  int iVar8;
  float unaff_EDI;
  float10 fVar9;
  float fStack_19c;
  float fVar10;
  float fStack_184;
  float local_180;
  float local_17c;
  float fStack_170;
  float fStack_16c;
  float fStack_168;
  undefined1 auStack_154 [12];
  undefined1 auStack_148 [8];
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  float local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  float local_110;
  float local_10c;
  float local_108;
  undefined4 local_104 [5];
  undefined1 auStack_f0 [12];
  undefined1 auStack_e4 [76];
  undefined1 auStack_98 [8];
  undefined1 local_90 [44];
  undefined1 auStack_64 [12];
  undefined1 auStack_58 [84];
  
  cVar5 = FUN_0043a2e0();
  if (((cVar5 != '\0') || (DAT_007361f0 == (int *)0x0)) ||
     ((*DAT_007361f0 != 7 && (*DAT_007361f0 != 0xb)))) {
    iVar8 = *(int *)(param_1 + 0x198);
    if (DAT_0078a2fc == 0) {
      local_17c = *(float *)(iVar8 + 0x810);
    }
    else {
      local_17c = (100.0 - *(float *)(iVar8 + 0x810) * 100.0) * 0.01;
    }
    fVar10 = (local_17c - *(float *)(param_1 + 0x54)) /
             (*(float *)(param_1 + 0x58) - *(float *)(param_1 + 0x54));
    if (fVar10 < 0.0) {
      fVar10 = 0.0;
    }
    if (*(int *)(param_1 + 0x4c) == 0) {
      fVar1 = CamBlend_Height_B * *(float *)(param_1 + 0x40) * DAT_0073457c +
              *(float *)(param_1 + 0x130);
    }
    else {
      fVar1 = (float)(*(int *)(param_1 + 0x7c) + -1) * fVar10;
    }
    *(float *)(param_1 + 0x130) = fVar1;
    fVar1 = (float)(*(int *)(param_1 + 0x7c) + -1);
    if (fVar1 < *(float *)(param_1 + 0x130)) {
      *(float *)(param_1 + 0x130) = fVar1;
    }
    if (*(int *)(param_1 + 0x50) == 0) {
      *(float *)(param_1 + 0x164) =
           CamBlend_Height_B * *(float *)(param_1 + 0x44) * DAT_0073457c +
           *(float *)(param_1 + 0x164);
    }
    else {
      *(float *)(param_1 + 0x164) = (float)(*(int *)(param_1 + 0x88) + -1) * fVar10;
    }
    local_180 = (float)(*(int *)(param_1 + 0x88) + -1);
    if ((float)(int)local_180 < *(float *)(param_1 + 0x164)) {
      *(float *)(param_1 + 0x164) = (float)(int)local_180;
    }
    local_140 = 0x3f800000;
    local_13c = 0;
    local_138 = 0;
    local_134 = 0;
    local_130 = 0;
    local_12c = 0x3f800000;
    local_128 = 0;
    local_124 = 0;
    local_120 = 0.0;
    local_11c = 0;
    local_118 = 0x3f800000;
    local_114 = 0;
    local_104[0] = 0x3f800000;
    local_110 = -*(float *)(iVar8 + 0x50);
    local_10c = -*(float *)(iVar8 + 0x54);
    local_108 = -*(float *)(iVar8 + 0x58);
    D3DXMatrixTranspose(local_90,iVar8 + 0x90);
    D3DXMatrixMultiply(auStack_58,auStack_148);
    FUN_005829e0(*(undefined4 *)(param_1 + 0x130));
    fVar1 = *(float *)(*(int *)(param_1 + 0x198) + 0x60);
    fVar2 = *(float *)(*(int *)(param_1 + 0x198) + 100);
    fVar9 = (float10)FUN_00441d80(8);
    fVar10 = (float)(fVar9 * (float10)0.877);
    fVar2 = fVar2 - _K_ONE;
    fVar9 = (float10)FUN_00441d80(8);
    fStack_168 = (float)(fVar9 * (float10)0.877);
    fVar2 = fVar2 + 2.0;
    fVar9 = (float10)FUN_00441d80(8);
    fStack_184 = fStack_184 + fVar10;
    local_180 = local_180 + fStack_168;
    local_17c = (float)(fVar9 * (float10)0.877 + (float10)local_17c);
    fVar9 = (float10)GroundQuery__FindSurfaceBelow(param_1 + 0x19c,&fStack_184,0,0,0);
    if ((float10)local_17c < fVar9 + (float10)0.7) {
      local_17c = (float)(fVar9 + (float10)0.7);
    }
    FUN_005829e0(*(undefined4 *)(param_1 + 0x164));
    FUN_005829e0(*(undefined4 *)(param_1 + 0x130));
    _ftol_nocw();
    CameraMover__ComputeBankedUpVector(local_104);
    Matrix4_BuildLookAt(local_104);
    D3DXMatrixMultiply(auStack_e4,auStack_64,auStack_154);
    fVar10 = ((float)auStack_98 - *(float *)(param_1 + 0x38)) /
             (*(float *)(param_1 + 0x3c) - *(float *)(param_1 + 0x38));
    if (0.0 <= fVar10) {
      if (_K_ONE < fVar10) {
        fVar10 = _K_ONE;
      }
    }
    else {
      fVar10 = 0.0;
    }
    FUN_005829e0(fVar10 * 31.0);
    iVar8 = DAT_00735f5c;
    if (*(int *)(param_1 + 0x34) == 0) {
      if (DAT_00735f5c == 0) {
        uVar7 = _ftol_nocw();
        *(undefined2 *)(*(int *)(param_1 + 0x1c) + 0xc4) = uVar7;
      }
    }
    else {
      iVar8 = *(int *)(param_1 + 0x198);
      fVar10 = unaff_EDI - *(float *)(iVar8 + 0x60);
      fVar4 = fVar1 - *(float *)(iVar8 + 100);
      fVar3 = fVar2 - *(float *)(iVar8 + 0x68);
      fStack_19c = SQRT(fVar10 * fVar10 + fVar4 * fVar4 + fVar3 * fVar3);
      if (fStack_19c < _K_ONE) {
        fStack_19c = 1.0;
      }
      sVar6 = Atan2ToAngle16(fStack_19c,local_120 * 0.25);
      iVar8 = DAT_00735f5c;
      if (DAT_00735f5c == 0) {
        *(short *)(*(int *)(param_1 + 0x1c) + 0xc4) = sVar6 << 1;
      }
    }
    fVar1 = fVar1 - fStack_16c;
    fVar2 = fVar2 - fStack_168;
    fVar10 = SQRT((unaff_EDI - fStack_170) * (unaff_EDI - fStack_170) +
                  fVar2 * fVar2 + fVar1 * fVar1);
    if (iVar8 == 0) {
      *(float *)(*(int *)(param_1 + 0x1c) + 0xb0) = fVar10;
    }
    if (fVar10 < 2.0) {
      fVar10 = 2.0;
    }
    if (iVar8 == 0) {
      *(float *)(*(int *)(param_1 + 0x1c) + 0xb4) = fVar10;
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb8) = 0x40f00000;
    }
    if (*DAT_0073619c == 4) {
      CameraMover_ClipAgainstWorld(param_1,auStack_f0,*(undefined4 *)(param_1 + 0x198));
    }
    Camera__SetCameraMatrix(*(undefined4 *)(param_1 + 0x1c),auStack_f0,DAT_0073ad38);
  }
  return;
}


// ==== 0x4852a0 RearViewMirrorCameraMover::ctor

/* [canon] camera V (C+D+M) docs/re/camera.md */

undefined4 * __fastcall RearViewMirrorCameraMover__ctor(undefined4 *param_1)

{
  undefined4 unaff_EDI;
  bool bVar1;
  
  CameraMover__ctor();
  bVar1 = DAT_00735f5c == 0;
  *param_1 = &PTR_CameraMover__TrivialDtor_006c7e10;
  param_1[0xb] = unaff_EDI;
  if (bVar1) {
    *(undefined4 *)(param_1[7] + 0x280) = unaff_EDI;
    *(undefined4 *)(param_1[7] + 0x284) = 0;
  }
  return param_1;
}


// ==== 0x4852e0 CameraMover::TrivialDtor

/* [canon] camera I (D) docs/re/camera.md */

void * __thiscall CameraMover__TrivialDtor(void *param_1,byte param_2)

{
  FUN_00483550();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x485300 RearViewMirrorCameraMover::Update

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera V (C+M) docs/re/camera.md */

void __fastcall RearViewMirrorCameraMover__Update(int param_1)

{
  int iVar1;
  int iStack_124;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  undefined4 local_d4;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  undefined1 auStack_a4 [12];
  undefined1 auStack_98 [8];
  undefined1 local_90 [56];
  undefined1 auStack_58 [84];
  
  iVar1 = *(int *)(param_1 + 0x2c);
  local_f0 = 0;
  local_ec = 0;
  local_e8 = 0x3f800000;
  local_e4 = 0;
  local_d4 = 0x3f800000;
  local_e0 = -*(float *)(iVar1 + 0x50);
  iStack_124 = iVar1 + 0x90;
  local_dc = -*(float *)(iVar1 + 0x54);
  local_d8 = -*(float *)(iVar1 + 0x58);
  D3DXMatrixTranspose(local_90);
  FUN_0040b990(auStack_98,auStack_98);
  FUN_0040ba40(auStack_98,auStack_98);
  FUN_0040b930();
  D3DXMatrixMultiply(auStack_98,auStack_98,auStack_58);
  D3DXMatrixMultiply(&local_e4,&iStack_124,auStack_a4);
  fStack_c0 = _DAT_00705b30 + fStack_c0;
  fStack_bc = _RearView_Offset_x + fStack_bc;
  fStack_b8 = _RearView_Offset_y + fStack_b8;
  if (DAT_00735f5c == 0) {
    *(undefined2 *)(*(int *)(param_1 + 0x1c) + 0xc4) = 20000;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xbc) = 0x3f400000;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xc0) = 0x43400000;
  ApplyCameraShake(*(undefined4 *)(param_1 + 0x10));
  Camera__SetCameraMatrix(*(undefined4 *)(param_1 + 0x1c),&local_f0,DAT_0073ad38);
  return;
}


// ==== 0x4854e0 TrackCarCameraMover::ctor

/* WARNING: Removing unreachable block (ram,0x00485828) */
/* WARNING: Removing unreachable block (ram,0x0048584e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera I (G+M) docs/re/camera.md */

undefined4 *
TrackCarCameraMover__ctor
          (undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
          undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  bool bVar11;
  
  CameraMover__ctor();
  *param_1 = &PTR_FUN_006c7d28;
  puVar9 = param_3;
  puVar10 = param_1 + 0x1a;
  for (iVar5 = 0x29; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar10 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar10 = puVar10 + 1;
  }
  CameraDataItems__CameraDataItems_copy();
  param_1[0xd2] = 0;
  param_1[0xd3] = 0;
  param_1[0xd4] = 0;
  param_1[0xd1] = 0;
  param_1[0xdb] = 0;
  param_1[0xd8] = 0;
  param_1[0xd9] = 0;
  param_1[0xda] = 0;
  param_1[0xd5] = 1;
  param_1[0xd0] = 100;
  param_1[0xd6] = 0x4000;
  param_1[0xe2] = 0x4000;
  param_1[0xdc] = 100;
  param_1[0xe1] = 1;
  param_1[0xde] = 0;
  param_1[0xdf] = 0;
  param_1[0xe0] = 0;
  param_1[0xdd] = 0;
  param_1[0xe7] = 0;
  param_1[0xe4] = 0;
  param_1[0xe5] = 0;
  param_1[0xe6] = 0;
  param_1[0xee] = 0x4000;
  param_1[0xe8] = 100;
  param_1[0xed] = 1;
  param_1[0xea] = 0;
  param_1[0xeb] = 0;
  param_1[0xec] = 0;
  param_1[0xe9] = 0;
  param_1[0xf3] = 0;
  param_1[0xf0] = 0;
  param_1[0xf1] = 0;
  param_1[0xf2] = 0;
  param_1[0xfa] = 0x4000;
  param_1[0xf4] = 100;
  param_1[0xf9] = 1;
  param_1[0xf6] = 0;
  param_1[0xf7] = 0;
  param_1[0xf8] = 0;
  param_1[0xf5] = 0;
  param_1[0xff] = 0;
  param_1[0xfc] = 0;
  param_1[0xfd] = 0;
  param_1[0xfe] = 0;
  param_1[0x10e] = param_2;
  param_1[0x100] = 0;
  param_1[0x101] = 0;
  param_1[0x10f] = 0;
  param_1[0x110] = 0;
  param_1[0x111] = 0;
  param_1[0x112] = 0;
  param_1[0x118] = 0x3f800000;
  param_1[0x119] = 0x3f800000;
  *(undefined2 *)(param_1 + 0x11a) = 0;
  *(undefined2 *)((int)param_1 + 0x46a) = 1;
  param_1[0x11b] = param_5;
  uVar1 = param_3[0xf];
  if ((void *)param_1[0xd4] != (void *)0x0) {
    _free((void *)param_1[0xd4]);
    param_1[0xd4] = 0;
  }
  param_1[0xd3] = uVar1;
  param_1[0xd1] = 0x20;
  uVar1 = param_3[0x14];
  uVar2 = param_3[0x15];
  if ((void *)param_1[0xe0] != (void *)0x0) {
    _free((void *)param_1[0xe0]);
    param_1[0xe0] = 0;
  }
  param_1[0xdf] = uVar2;
  param_1[0xdd] = uVar1;
  uVar1 = param_3[0x14];
  uVar2 = param_3[0x16];
  if ((void *)param_1[0xec] != (void *)0x0) {
    _free((void *)param_1[0xec]);
    param_1[0xec] = 0;
  }
  param_1[0xeb] = uVar2;
  param_1[0xe9] = uVar1;
  uVar1 = param_1[0x4e];
  if ((void *)param_1[0xf8] != (void *)0x0) {
    _free((void *)param_1[0xf8]);
    param_1[0xf8] = 0;
  }
  param_1[0xf7] = param_1 + 0x50;
  bVar11 = DAT_00735f5c == 0;
  param_1[0xf5] = uVar1;
  if (bVar11) {
    *(undefined4 *)(param_1[7] + 0x280) = 0;
    *(undefined4 *)(param_1[7] + 0x284) = 0;
  }
  iVar5 = param_1[0x10e];
  uVar1 = *(undefined4 *)(iVar5 + 100);
  uVar2 = *(undefined4 *)(iVar5 + 0x68);
  param_1[0xc] = *(undefined4 *)(iVar5 + 0x60);
  param_1[0xd] = uVar1;
  param_1[0xe] = uVar2;
  fVar4 = _DAT_00736818;
  fVar3 = _DAT_00736814;
  if (((DAT_00736810 == 0.0) && (_DAT_00736814 == 0.0)) && (_DAT_00736818 == 0.0)) {
    param_1[0x10] = param_1[0x33];
    param_1[0x11] = param_1[0x34];
    param_1[0x12] = param_1[0x34];
  }
  else {
    param_1[0x10] = DAT_00736810;
    param_1[0x11] = fVar3;
    param_1[0x12] = fVar4;
  }
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x18] = param_1[0x37];
  param_1[0x19] = param_1[0x36];
  puVar9 = (undefined4 *)param_1[0x2f];
  uVar1 = puVar9[1];
  uVar2 = puVar9[2];
  param_1[0x104] = *puVar9;
  param_1[0x105] = uVar1;
  param_1[0x106] = uVar2;
  uVar1 = *(undefined4 *)(param_1[0x2e] * 0x10 + -0xc + param_1[0x2f]);
  puVar9 = (undefined4 *)(param_1[0x2e] * 0x10 + -0x10 + param_1[0x2f]);
  uVar2 = puVar9[2];
  param_1[0x108] = *puVar9;
  param_1[0x109] = uVar1;
  param_1[0x10a] = uVar2;
  param_1[0x10c] = 0;
  param_1[0x10d] = 0x49742400;
  *(undefined4 *)(param_1[7] + 0xbc) = param_1[0x26];
  *(undefined4 *)(param_1[7] + 0xc0) = param_1[0x27];
  param_1[0x118] = 0x3ed70a3d;
  *(undefined2 *)((int)param_1 + 0x46a) = 1;
  uVar6 = DAT_006f227c ^ 0x1d872b41;
  uVar7 = uVar6 >> 5 ^ uVar6;
  uVar6 = uVar7 << 0x1b ^ uVar7 ^ uVar6;
  param_3 = (undefined4 *)(DAT_006f227c % 0x13 + 0x1a);
  uVar7 = uVar6 ^ 0x1d872b41;
  uVar8 = uVar7 >> 5 ^ uVar7;
  DAT_006f227c = uVar8 << 0x1b ^ uVar8 ^ uVar7;
  if ((uVar6 & 1) != 0) {
    param_3 = (undefined4 *)-(int)param_3;
  }
  param_1[0x10f] = (float)(int)param_3;
  if ((float)(int)param_3 != (float)param_1[0x111]) {
    *(undefined2 *)(param_1 + 0x11a) = 2;
  }
  param_1[0x111] = 0;
  if ((float)param_1[0x10f] != 0.0) {
    *(undefined2 *)(param_1 + 0x11a) = 2;
  }
  if ((param_1[0x11b] == 0) && (DAT_00735f5c == 0)) {
    *(undefined4 *)(param_1[7] + 0xb4) = 0;
    *(undefined4 *)(param_1[7] + 0xb8) = 0;
    return param_1;
  }
  return param_1;
}


// ==== 0x4859d0 FUN_004859d0

void * __thiscall FUN_004859d0(void *param_1,byte param_2)

{
  FUN_00485a50();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4859f0 CameraDataItems::CameraDataItems_copy

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

void __fastcall CameraDataItems__CameraDataItems_copy(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_EAX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar4 = param_2;
  puVar5 = in_EAX;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  in_EAX[8] = param_2[8];
  in_EAX[9] = param_2[9];
  in_EAX[10] = param_2[10];
  in_EAX[0xb] = param_2[0xb];
  iVar3 = 0x20;
  puVar4 = (undefined4 *)((int)(in_EAX + 0xc) + (8 - (int)in_EAX) + (int)param_2);
  puVar5 = in_EAX + 0xc;
  do {
    uVar1 = puVar4[-1];
    uVar2 = *puVar4;
    iVar3 = iVar3 + -1;
    *puVar5 = puVar4[-2];
    puVar5[1] = uVar1;
    *(undefined4 *)((int)in_EAX + (-0x10 - (int)param_2) + (int)(puVar4 + 4)) = uVar2;
    puVar4 = puVar4 + 4;
    puVar5 = puVar5 + 4;
  } while (iVar3 != 0);
  return;
}


// ==== 0x485a50 FUN_00485a50

void __fastcall FUN_00485a50(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  bool bVar4;
  
  bVar4 = DAT_00735f5c == 0;
  *param_1 = &PTR_FUN_006c7d28;
  if (bVar4) {
    *(undefined4 *)(param_1[7] + 0xb4) = 0;
    *(undefined4 *)(param_1[7] + 0xb8) = 0;
  }
  uVar3 = DAT_006f0888;
  iVar1 = param_1[7];
  *(undefined1 *)(iVar1 + 0x270) = 1;
  *(undefined4 *)(iVar1 + 0x27c) = uVar3;
  if ((void *)param_1[0xf8] != (void *)0x0) {
    _free((void *)param_1[0xf8]);
  }
  if ((void *)param_1[0xff] != (void *)0x0) {
    _free((void *)param_1[0xff]);
  }
  if ((void *)param_1[0xec] != (void *)0x0) {
    _free((void *)param_1[0xec]);
  }
  if ((void *)param_1[0xf3] != (void *)0x0) {
    _free((void *)param_1[0xf3]);
  }
  if ((void *)param_1[0xe0] != (void *)0x0) {
    _free((void *)param_1[0xe0]);
  }
  if ((void *)param_1[0xe7] != (void *)0x0) {
    _free((void *)param_1[0xe7]);
  }
  if ((void *)param_1[0xd4] != (void *)0x0) {
    _free((void *)param_1[0xd4]);
  }
  if ((void *)param_1[0xdb] != (void *)0x0) {
    _free((void *)param_1[0xdb]);
  }
  *param_1 = &PTR_CameraMover__TrivialDtor_006c7c50;
  if (param_1[5] != 0) {
    param_1[5] = 0;
    param_1[9] = *(undefined4 *)(param_1[7] + 0x280);
    param_1[10] = *(undefined4 *)(param_1[7] + 0x284);
    iVar1 = param_1[1];
    piVar2 = (int *)param_1[2];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    ViewList_UpdateViewCountKind();
    return;
  }
  return;
}


// ==== 0x485b70 FUN_00485b70

int __fastcall FUN_00485b70(int param_1)

{
  if (*(int *)(param_1 + 0x438) != 0) {
    return *(int *)(param_1 + 0x438) + 0x50;
  }
  return *(int *)(param_1 + 0x1c) + 0x60;
}


// ==== 0x485b90 FUN_00485b90

void __fastcall FUN_00485b90(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *in_EAX;
  int unaff_ESI;
  
  fVar1 = *(float *)(unaff_ESI + 100);
  fVar2 = in_EAX[1];
  fVar3 = in_EAX[2];
  fVar4 = *(float *)(unaff_ESI + 0x60);
  fVar5 = param_1[1];
  fVar6 = param_1[2];
  *param_2 = fVar4 * *param_1 + fVar1 * *in_EAX;
  param_2[1] = fVar5 * fVar4 + fVar2 * fVar1;
  param_2[2] = fVar6 * fVar4 + fVar3 * fVar1;
  return;
}


// ==== 0x485c00 TrackCarCameraMover::Update

/* WARNING: Removing unreachable block (ram,0x00486265) */
/* WARNING: Removing unreachable block (ram,0x00486135) */
/* WARNING: Removing unreachable block (ram,0x0048608b) */
/* WARNING: Removing unreachable block (ram,0x0048623d) */
/* WARNING: Removing unreachable block (ram,0x0048628e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera I (G+M) docs/re/camera.md */

void __fastcall TrackCarCameraMover__Update(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  char cVar10;
  int iVar11;
  float fVar12;
  float *pfVar13;
  float *extraout_ECX;
  float10 fVar14;
  float10 fVar15;
  float local_e4;
  float fStack_cc;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float fStack_b4;
  float local_ac;
  float local_a8;
  float fStack_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  float local_90;
  float local_8c;
  float local_88;
  float local_80;
  float local_7c;
  float local_70;
  undefined1 auStack_5c [88];
  
  cVar10 = FUN_0043a2e0();
  if (((cVar10 != '\0') || (DAT_007361f0 == (int *)0x0)) ||
     ((*DAT_007361f0 != 7 && (*DAT_007361f0 != 0xb)))) {
    iVar11 = *(int *)(param_1 + 0x438);
    fVar8 = *(float *)(iVar11 + 0x810);
    local_c4 = (fVar8 - *(float *)(param_1 + 0x90)) /
               (*(float *)(param_1 + 0x94) - *(float *)(param_1 + 0x90));
    if (local_c4 <= 0.0) {
      local_c4 = 0.0;
    }
    else if (_K_ONE < local_c4) {
      local_c4 = 1.0;
    }
    local_90 = 0.0;
    local_8c = 0.0;
    local_88 = 1.0;
    if (*(float *)(param_1 + 0x100) == 0.0) {
      if (*(int *)(param_1 + 0x88) == 0) {
        fVar4 = CamBlend_Height_B * *(float *)(param_1 + 0x7c) * DAT_0073457c +
                *(float *)(param_1 + 0x400);
      }
      else {
        fVar4 = (float)(*(int *)(param_1 + 0xb8) + -1) * local_c4;
      }
      *(float *)(param_1 + 0x400) = fVar4;
      fVar4 = (float)(*(int *)(param_1 + 0xb8) + -1);
      if (fVar4 < *(float *)(param_1 + 0x400)) {
        *(float *)(param_1 + 0x400) = fVar4;
      }
      FUN_005829e0(*(undefined4 *)(param_1 + 0x400));
    }
    else {
      if (*(int *)(param_1 + 0x430) == 0) {
        fVar4 = *(float *)(param_1 + 0x420) - *(float *)(param_1 + 0x410);
        fVar5 = *(float *)(param_1 + 0x424) - *(float *)(param_1 + 0x414);
        fVar12 = *(float *)(param_1 + 0x428) - *(float *)(param_1 + 0x418);
        fVar6 = ((*(float *)(iVar11 + 100) - *(float *)(param_1 + 0x414)) * fVar5 +
                (*(float *)(iVar11 + 0x68) - *(float *)(param_1 + 0x418)) * fVar12 +
                (*(float *)(iVar11 + 0x60) - *(float *)(param_1 + 0x410)) * fVar4) /
                (fVar5 * fVar5 + fVar12 * fVar12 + fVar4 * fVar4);
        fVar7 = _K_ONE;
        if ((fVar6 <= _K_ONE) && (fVar7 = fVar6, fVar6 < 0.0)) {
          fVar7 = 0.0;
        }
        local_ac = fVar5 * fVar7;
        fVar5 = *(float *)(param_1 + 0x410);
        fVar6 = *(float *)(param_1 + 0x414);
        fVar3 = *(float *)(param_1 + 0x418);
        FUN_005673e0(*(undefined4 *)(param_1 + 0x100));
        local_c0 = fVar4 * fVar7 + fVar4 * fVar7 + fVar5;
        local_bc = local_ac + fVar6 + local_ac;
        local_b8 = local_a8 + fVar3 + fVar7 * fVar12;
      }
      else {
        iVar9 = *(int *)(param_1 + 0x1c);
        local_bc = *(float *)(iVar9 + 0x44);
        local_c0 = *(float *)(iVar9 + 0x40);
        local_b8 = *(float *)(iVar9 + 0x48);
      }
      if (*(int *)(param_1 + 0x104) != 0) {
        fVar4 = *(float *)(iVar11 + 0x60) - local_c0;
        fVar5 = *(float *)(iVar11 + 100) - local_bc;
        fVar12 = *(float *)(iVar11 + 0x68) - local_b8;
        fVar4 = SQRT(fVar4 * fVar4 + fVar12 * fVar12 + fVar5 * fVar5);
        if (*(float *)(param_1 + 0x434) < fVar4) {
          *(undefined4 *)(param_1 + 0x430) = 1;
        }
        *(float *)(param_1 + 0x434) = fVar4;
      }
    }
    fVar8 = (fVar8 - *(float *)(param_1 + 0x74)) /
            (*(float *)(param_1 + 0x78) - *(float *)(param_1 + 0x74));
    if (0.0 <= fVar8) {
      if (_K_ONE < fVar8) {
        fVar8 = _K_ONE;
      }
    }
    else {
      fVar8 = 0.0;
    }
    FUN_005829e0(fVar8 * 31.0);
    iVar11 = *(int *)(param_1 + 0x438);
    fVar8 = local_c0 - *(float *)(iVar11 + 0x60);
    fVar4 = local_bc - *(float *)(iVar11 + 100);
    fVar5 = local_b8 - *(float *)(iVar11 + 0x68);
    local_e4 = SQRT(fVar8 * fVar8 + fVar4 * fVar4 + fVar5 * fVar5);
    if (local_e4 < _K_ONE) {
      local_e4 = 1.0;
    }
    if (*(int *)(param_1 + 0x70) == 0) {
      fVar12 = (float)_ftol_nocw();
    }
    else {
      iVar11 = Atan2ToAngle16(local_e4,local_70 * 0.25);
      fVar12 = (float)(iVar11 << 1);
    }
    if (DAT_00735f5c == 0) {
      *(short *)(*(int *)(param_1 + 0x1c) + 0xc4) = SUB42(fVar12,0);
    }
    fVar7 = DAT_0073457c * *(float *)(param_1 + 0x134) + *(float *)(param_1 + 0x404);
    *(float *)(param_1 + 0x404) = fVar7;
    fVar6 = (float)(*(int *)(param_1 + 0x138) + -1);
    if (fVar6 < fVar7) {
      *(float *)(param_1 + 0x404) = fVar6;
    }
    FUN_005829e0(*(undefined4 *)(param_1 + 0x404));
    iVar11 = *(int *)(param_1 + 0x438);
    uVar1 = *(undefined4 *)(iVar11 + 100);
    uVar2 = *(undefined4 *)(iVar11 + 0x68);
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(iVar11 + 0x60);
    *(undefined4 *)(param_1 + 0x34) = uVar1;
    *(undefined4 *)(param_1 + 0x38) = uVar2;
    if (*(int *)(param_1 + 0xfc) == 0) {
      fVar15 = (float10)FUN_00564b10();
      fVar14 = (float10)FUN_00564b10();
      fVar15 = ((float10)(float)fVar15 / fVar14) * (float10)*(float *)(param_1 + 0xec);
    }
    else {
      fVar6 = *(float *)(param_1 + 0xf4);
      fVar7 = *(float *)(param_1 + 0xec);
      fVar3 = *(float *)(param_1 + 0xec);
      fVar14 = (float10)FUN_00564b10();
      fVar15 = (float10)FUN_00564b10();
      fVar15 = fVar15 * (float10)(float)((float10)((fVar6 - fVar7) * local_c4 + fVar3) / fVar14);
    }
    *(float *)(param_1 + 0x38) =
         (float)((fVar15 * (float10)local_e4 - (float10)local_7c) +
                (float10)*(float *)(param_1 + 0x38));
    if (*(int *)(param_1 + 0xfc) == 0) {
      fVar15 = (float10)FUN_00564b10();
      fVar14 = (float10)FUN_00564b10();
      fVar15 = ((float10)(float)fVar15 / fVar14) * (float10)*(float *)(param_1 + 0xf0);
    }
    else {
      fVar6 = *(float *)(param_1 + 0xf8);
      fVar7 = *(float *)(param_1 + 0xf0);
      fVar3 = *(float *)(param_1 + 0xf0);
      fVar14 = (float10)FUN_00564b10();
      fVar15 = (float10)FUN_00564b10();
      fVar15 = fVar15 * (float10)(float)((float10)((fVar6 - fVar7) * local_c4 + fVar3) / fVar14);
    }
    fVar14 = (float10)_K_ONE / (float10)local_e4;
    fVar15 = (float10)local_80 + fVar15 * (float10)local_e4;
    *(float *)(param_1 + 0x30) =
         (float)((float10)(float)((float10)fVar4 * fVar14 * (float10)local_88 -
                                 (float10)(float)((float10)fVar5 * fVar14) * (float10)local_8c) *
                fVar15) + *(float *)(param_1 + 0x30);
    *(float *)(param_1 + 0x34) =
         (float)(((float10)(float)((float10)fVar5 * fVar14) * (float10)local_90 -
                 (float10)local_88 * (float10)fVar8 * fVar14) * fVar15 +
                (float10)*(float *)(param_1 + 0x34));
    local_a0 = *(undefined4 *)(param_1 + 0xe0);
    local_9c = *(undefined4 *)(param_1 + 0xe4);
    local_98 = *(undefined4 *)(param_1 + 0xe8);
    D3DXVec3Transform(&local_a0,&local_a0,*(int *)(param_1 + 0x438) + 0x90);
    *(float *)(param_1 + 0x30) = local_ac + *(float *)(param_1 + 0x30);
    *(float *)(param_1 + 0x34) = local_a8 + *(float *)(param_1 + 0x34);
    *(float *)(param_1 + 0x38) = fStack_a4 + *(float *)(param_1 + 0x38);
    fVar8 = *(float *)(param_1 + 0x30);
    fVar4 = *(float *)(param_1 + 0x34);
    fVar5 = *(float *)(param_1 + 0x38);
    bNormalize3();
    pfVar13 = (float *)FUN_00485b90();
    *pfVar13 = *pfVar13 - local_bc;
    pfVar13[1] = pfVar13[1] - local_b8;
    pfVar13[2] = pfVar13[2] - fStack_b4;
    fVar6 = pfVar13[1];
    fVar7 = pfVar13[2];
    *(float *)(param_1 + 0x50) = *pfVar13 + *(float *)(param_1 + 0x50);
    *(float *)(param_1 + 0x54) = fVar6 + *(float *)(param_1 + 0x54);
    *(float *)(param_1 + 0x58) = fVar7 + *(float *)(param_1 + 0x58);
    *(float *)(param_1 + 0x30) = (fVar8 - fStack_cc) + *(float *)(param_1 + 0x50) + fStack_cc;
    *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x54) + (fVar4 - fVar12) + fVar12;
    *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x58) + (fVar5 - local_c4) + local_c4;
    FUN_005829e0(*(undefined4 *)(param_1 + 0x400));
    _ftol_nocw();
    CameraMover__ComputeBankedUpVector(&local_9c);
    Matrix4_BuildLookAt(&local_9c);
    iVar9 = DAT_00735f5c;
    iVar11 = *(int *)(param_1 + 0x438);
    fVar8 = *(float *)(iVar11 + 0x60) - fStack_cc;
    fVar12 = *(float *)(iVar11 + 100) - fVar12;
    local_c4 = *(float *)(iVar11 + 0x68) - local_c4;
    fVar8 = SQRT(fVar8 * fVar8 + fVar12 * fVar12 + local_c4 * local_c4);
    if (DAT_00735f5c == 0) {
      *(float *)(*(int *)(param_1 + 0x1c) + 0xb0) = fVar8;
    }
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xbc) = 0x3f000000;
    *(float *)(param_1 + 0x448) = *(float *)(param_1 + 0x43c) * 6.27;
    FUN_00593ec0(DAT_0073457c,0,0);
    fVar8 = fVar8 + *extraout_ECX;
    if (fVar8 < 2.0) {
      fVar8 = 2.0;
    }
    if ((*(int *)(param_1 + 0x46c) != 0) && (iVar9 == 0)) {
      *(float *)(*(int *)(param_1 + 0x1c) + 0xb4) = fVar8 + *extraout_ECX;
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb8) = 0x40f00000;
    }
    Camera__SetCameraMatrix(*(undefined4 *)(param_1 + 0x1c),auStack_5c,DAT_0073ad38);
  }
  return;
}


// ==== 0x4864e0 FUN_004864e0

undefined4 * FUN_004864e0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  CameraMover__ctor();
  *param_1 = &PTR_FUN_006c7ef0;
  puVar4 = param_1 + 0xb;
  for (iVar3 = 0x29; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_2;
    param_2 = param_2 + 1;
    puVar4 = puVar4 + 1;
  }
  param_1[0x3a] = 0x4000;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x35] = 0;
  param_1[0x3f] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x39] = 1;
  param_1[0x34] = 100;
  param_1[0x46] = 0x4000;
  param_1[0x45] = 1;
  param_1[0x42] = 0;
  param_1[0x40] = 100;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x41] = 0;
  param_1[0x4b] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x52] = 0x4000;
  param_1[0x51] = 1;
  param_1[0x4e] = 0;
  param_1[0x4c] = 100;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x4d] = 0;
  param_1[0x57] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x5e] = 0x4000;
  param_1[0x5d] = 1;
  param_1[0x5a] = 0;
  param_1[0x58] = 100;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  param_1[0x59] = 0;
  param_1[99] = 0;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  uVar1 = param_1[0x1a];
  param_1[100] = 0;
  param_1[0x65] = 0;
  param_1[0x66] = param_3;
  if ((void *)param_1[0x5c] != (void *)0x0) {
    _free((void *)param_1[0x5c]);
    param_1[0x5c] = 0;
  }
  param_1[0x5b] = uVar1;
  param_1[0x59] = 0x20;
  uVar1 = param_1[0x1f];
  uVar2 = param_1[0x20];
  if ((void *)param_1[0x38] != (void *)0x0) {
    _free((void *)param_1[0x38]);
    param_1[0x38] = 0;
  }
  param_1[0x37] = uVar2;
  param_1[0x35] = uVar1;
  uVar1 = param_1[0x1f];
  uVar2 = param_1[0x21];
  if ((void *)param_1[0x44] != (void *)0x0) {
    _free((void *)param_1[0x44]);
    param_1[0x44] = 0;
  }
  param_1[0x43] = uVar2;
  param_1[0x41] = uVar1;
  uVar1 = param_1[0x22];
  uVar2 = param_1[0x23];
  if ((void *)param_1[0x50] != (void *)0x0) {
    _free((void *)param_1[0x50]);
    param_1[0x50] = 0;
  }
  param_1[0x4f] = uVar2;
  param_1[0x4d] = uVar1;
  *(undefined4 *)(param_1[7] + 0xbc) = param_1[0x17];
  *(undefined4 *)(param_1[7] + 0xc0) = param_1[0x18];
  return param_1;
}


// ==== 0x486720 FUN_00486720

void * __thiscall FUN_00486720(void *param_1,byte param_2)

{
  FUN_00486740();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x486740 FUN_00486740

void __fastcall FUN_00486740(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  bool bVar4;
  
  bVar4 = DAT_00735f5c == 0;
  *param_1 = &PTR_FUN_006c7ef0;
  if (bVar4) {
    *(undefined4 *)(param_1[7] + 0xb4) = 0;
    *(undefined4 *)(param_1[7] + 0xb8) = 0;
  }
  uVar3 = DAT_006f0888;
  iVar1 = param_1[7];
  *(undefined1 *)(iVar1 + 0x270) = 1;
  *(undefined4 *)(iVar1 + 0x27c) = uVar3;
  if ((void *)param_1[0x5c] != (void *)0x0) {
    _free((void *)param_1[0x5c]);
  }
  if ((void *)param_1[99] != (void *)0x0) {
    _free((void *)param_1[99]);
  }
  if ((void *)param_1[0x50] != (void *)0x0) {
    _free((void *)param_1[0x50]);
  }
  if ((void *)param_1[0x57] != (void *)0x0) {
    _free((void *)param_1[0x57]);
  }
  if ((void *)param_1[0x44] != (void *)0x0) {
    _free((void *)param_1[0x44]);
  }
  if ((void *)param_1[0x4b] != (void *)0x0) {
    _free((void *)param_1[0x4b]);
  }
  if ((void *)param_1[0x38] != (void *)0x0) {
    _free((void *)param_1[0x38]);
  }
  if ((void *)param_1[0x3f] != (void *)0x0) {
    _free((void *)param_1[0x3f]);
  }
  *param_1 = &PTR_CameraMover__TrivialDtor_006c7c50;
  if (param_1[5] != 0) {
    param_1[5] = 0;
    param_1[9] = *(undefined4 *)(param_1[7] + 0x280);
    param_1[10] = *(undefined4 *)(param_1[7] + 0x284);
    iVar1 = param_1[1];
    piVar2 = (int *)param_1[2];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    ViewList_UpdateViewCountKind();
    return;
  }
  return;
}


// ==== 0x486860 FUN_00486860

int __fastcall FUN_00486860(int param_1)

{
  if (*(int *)(param_1 + 0x198) != 0) {
    return *(int *)(param_1 + 0x198) + 0x50;
  }
  return *(int *)(param_1 + 0x1c) + 0x60;
}


// ==== 0x486880 FUN_00486880

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00486880(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  short sVar4;
  undefined2 uVar5;
  int iVar6;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_90;
  float local_8c;
  float local_88;
  float local_80;
  undefined1 local_70 [32];
  undefined1 local_50 [76];
  
  fVar1 = 0.0;
  iVar6 = *(int *)(param_1 + 0x198);
  if (iVar6 != 0) {
    fVar1 = *(float *)(iVar6 + 0x810);
    if (DAT_0078a2fc != 0) {
      fVar1 = (100.0 - fVar1 * 100.0) * 0.01;
    }
    fVar1 = (fVar1 - *(float *)(param_1 + 0x54)) /
            (*(float *)(param_1 + 0x58) - *(float *)(param_1 + 0x54));
    if (fVar1 < 0.0) {
      fVar1 = 0.0;
    }
  }
  if ((*(int *)(param_1 + 0x50) == 0) || (iVar6 == 0)) {
    fVar2 = CamBlend_Height_B * *(float *)(param_1 + 0x44) * DAT_0073457c +
            *(float *)(param_1 + 0x194);
  }
  else {
    fVar2 = (float)(*(int *)(param_1 + 0x88) + -1) * fVar1;
  }
  *(float *)(param_1 + 0x194) = fVar2;
  fVar2 = (float)(*(int *)(param_1 + 0x88) + -1);
  if (fVar2 < *(float *)(param_1 + 0x194)) {
    *(float *)(param_1 + 0x194) = fVar2;
  }
  if ((*(int *)(param_1 + 0x4c) == 0) || (iVar6 == 0)) {
    *(float *)(param_1 + 400) =
         CamBlend_Height_B * *(float *)(param_1 + 0x40) * DAT_0073457c + *(float *)(param_1 + 400);
  }
  else {
    *(float *)(param_1 + 400) = (float)(*(int *)(param_1 + 0x7c) + -1) * fVar1;
  }
  fVar1 = (float)(*(int *)(param_1 + 0x7c) + -1);
  if (fVar1 < *(float *)(param_1 + 400)) {
    *(float *)(param_1 + 400) = fVar1;
  }
  FUN_005829e0(*(undefined4 *)(param_1 + 400));
  FUN_005829e0(*(undefined4 *)(param_1 + 0x194));
  FUN_005829e0(*(undefined4 *)(param_1 + 400));
  _ftol_nocw();
  CameraMover__ComputeBankedUpVector(local_70);
  Matrix4_BuildLookAt(local_70);
  iVar6 = DAT_00735f5c;
  if (*(int *)(param_1 + 0x198) == 0) {
    if (DAT_00735f5c == 0) {
      *(undefined2 *)(*(int *)(param_1 + 0x1c) + 0xc4) = 0x32dc;
    }
  }
  else {
    fVar1 = *(float *)(*(int *)(param_1 + 0x198) + 0x810);
    if (DAT_0078a2fc != 0) {
      fVar1 = (100.0 - fVar1 * 100.0) * 0.01;
    }
    fVar1 = (fVar1 - *(float *)(param_1 + 0x38)) /
            (*(float *)(param_1 + 0x3c) - *(float *)(param_1 + 0x38));
    if (0.0 <= fVar1) {
      if (_K_ONE < fVar1) {
        fVar1 = _K_ONE;
      }
    }
    else {
      fVar1 = 0.0;
    }
    FUN_005829e0(fVar1 * 31.0);
    iVar6 = DAT_00735f5c;
    if (*(int *)(param_1 + 0x34) == 0) {
      if (DAT_00735f5c == 0) {
        uVar5 = _ftol_nocw();
        *(undefined2 *)(*(int *)(param_1 + 0x1c) + 0xc4) = uVar5;
      }
    }
    else {
      iVar6 = *(int *)(param_1 + 0x198);
      fVar1 = local_a0 - *(float *)(iVar6 + 0x60);
      fVar3 = local_9c - *(float *)(iVar6 + 100);
      fVar2 = local_98 - *(float *)(iVar6 + 0x68);
      local_a4 = SQRT(fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2);
      if (local_a4 < _K_ONE) {
        local_a4 = 1.0;
      }
      sVar4 = Atan2ToAngle16(local_a4,local_80 * 0.25);
      iVar6 = DAT_00735f5c;
      if (DAT_00735f5c == 0) {
        *(short *)(*(int *)(param_1 + 0x1c) + 0xc4) = sVar4 << 1;
      }
    }
  }
  fVar1 = SQRT((local_98 - local_88) * (local_98 - local_88) +
               (local_9c - local_8c) * (local_9c - local_8c) +
               (local_a0 - local_90) * (local_a0 - local_90));
  if (iVar6 == 0) {
    *(float *)(*(int *)(param_1 + 0x1c) + 0xb0) = fVar1;
  }
  if (fVar1 < 2.0) {
    fVar1 = 2.0;
  }
  if (iVar6 == 0) {
    *(float *)(*(int *)(param_1 + 0x1c) + 0xb4) = fVar1;
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb8) = 0x41f00000;
  }
  Camera__SetCameraMatrix(*(undefined4 *)(param_1 + 0x1c),local_50,DAT_0073ad38);
  return;
}


// ==== 0x486c00 FUN_00486c00

undefined4 __fastcall FUN_00486c00(int param_1)

{
  float fVar1;
  bool bVar2;
  bool bVar3;
  
  bVar2 = false;
  if ((*(float *)(param_1 + 0x40) == 0.0) ||
     (fVar1 = (float)(*(int *)(param_1 + 0x7c) + -1),
     fVar1 < *(float *)(param_1 + 400) != (fVar1 == *(float *)(param_1 + 400)))) {
    bVar2 = true;
  }
  bVar3 = false;
  if ((*(float *)(param_1 + 0x44) == 0.0) ||
     (fVar1 = (float)(*(int *)(param_1 + 0x88) + -1),
     fVar1 < *(float *)(param_1 + 0x194) != (fVar1 == *(float *)(param_1 + 0x194)))) {
    bVar3 = true;
  }
  if ((bVar2) && (bVar3)) {
    return 1;
  }
  return 0;
}


// ==== 0x486c80 SelectCarCameraMover::ctor

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera I (M) docs/re/camera.md */

undefined4 * __fastcall SelectCarCameraMover__ctor(undefined4 *param_1)

{
  CameraMover__ctor();
  *param_1 = &PTR_CameraMover__TrivialDtor_006c7c98;
  param_1[0xb] = 3;
  param_1[0xc] = 4;
  param_1[0x10] = 0x42ba0000;
  param_1[0x11] = 0x42e60000;
  param_1[0x12] = 0x40c00000;
  param_1[0x13] = 0;
  param_1[0x14] = 0x42340000;
  param_1[0xd] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0x3f400000;
  param_1[0x1a] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0x3f400000;
  param_1[0x20] = param_1[0x10];
  param_1[0x21] = param_1[0x11];
  param_1[0x22] = param_1[0x12];
  param_1[0x23] = param_1[0x13];
  param_1[0x24] = param_1[0x14];
  param_1[0x28] = param_1[0x18];
  param_1[0x29] = param_1[0x19];
  param_1[0x2a] = param_1[0x1a];
  param_1[0x2c] = param_1[0x1c];
  param_1[0x2d] = param_1[0x1d];
  param_1[0x2e] = param_1[0x1e];
  param_1[0x30] = param_1[0x10];
  param_1[0x31] = param_1[0x11];
  param_1[0x32] = param_1[0x12];
  param_1[0x33] = param_1[0x13];
  param_1[0x34] = param_1[0x14];
  param_1[0x38] = param_1[0x18];
  param_1[0x39] = param_1[0x19];
  param_1[0x3a] = param_1[0x1a];
  param_1[0x3c] = param_1[0x1c];
  param_1[0x3d] = param_1[0x1d];
  param_1[0x3e] = param_1[0x1e];
  param_1[0x40] = param_1[0x10];
  param_1[0x41] = param_1[0x11];
  param_1[0x42] = param_1[0x12];
  param_1[0x43] = param_1[0x13];
  param_1[0x44] = param_1[0x14];
  param_1[0x48] = param_1[0x18];
  param_1[0x49] = param_1[0x19];
  param_1[0x4a] = param_1[0x1a];
  param_1[0x4c] = param_1[0x1c];
  param_1[0x4d] = param_1[0x1d];
  param_1[0x4e] = param_1[0x1e];
  param_1[0x50] = param_1[0x10];
  param_1[0x51] = param_1[0x11];
  param_1[0x52] = param_1[0x12];
  param_1[0x53] = param_1[0x13];
  param_1[0x54] = param_1[0x14];
  param_1[0x58] = param_1[0x18];
  param_1[0x59] = param_1[0x19];
  param_1[0x5a] = param_1[0x1a];
  param_1[0x5c] = param_1[0x1c];
  param_1[0x5d] = param_1[0x1d];
  param_1[0x5e] = param_1[0x1e];
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  param_1[99] = 0;
  param_1[100] = 0x3f800000;
  param_1[0x65] = 0;
  _DAT_007788e0 = 0x42ae7a5e;
  _DAT_007788e4 = 0x435f1168;
  _DAT_007788e8 = 0x404c28f6;
  _DAT_007788ec = 0x40d40831;
  _DAT_007788f0 = 0x4288ee98;
  _DAT_00778900 = 0x3f3c6a7f;
  _DAT_00778904 = 0x3f6b851f;
  _DAT_00778908 = 0;
  _DAT_00778910 = 0;
  _DAT_00778914 = 0xbf6b851f;
  _DAT_00778918 = 0x3f5be76d;
  _DAT_00778920 = 0x42b74fdf;
  _DAT_00778924 = 0x42351aa0;
  _DAT_00778928 = 0x40858106;
  _DAT_0077892c = 0x40d40831;
  _DAT_00778930 = 0x41f75c29;
  _DAT_00778940 = 0x40096873;
  _DAT_00778944 = 0x3efb645a;
  _DAT_00778948 = 0x3f8d4fdf;
  _DAT_00778950 = 0;
  _DAT_00778954 = 0xbd79db23;
  _DAT_00778958 = 0x3f953f7d;
  _DAT_00778960 = 0x42ae7a5e;
  _DAT_00778964 = 0x43552106;
  _DAT_00778968 = 0x40896873;
  _DAT_0077896c = 0x40d40831;
  _DAT_00778970 = 0x41f75c29;
  _DAT_00778980 = 0x3feb851f;
  _DAT_00778984 = 0x3f0d4fdf;
  _DAT_007789ac = 0;
  _DAT_007789c0 = 0;
  _DAT_007789c8 = 0;
  _DAT_00778988 = 0x3fbc6a7f;
  _DAT_00778990 = 0x3f1ced91;
  _DAT_00778994 = 0xbdfbe76d;
  _DAT_00778998 = 0x3f3c6a7f;
  _DAT_007789a0 = 0x42b48a3d;
  _DAT_007789a4 = 0x42e35e35;
  _DAT_007789a8 = 0x40c00000;
  _DAT_007789b0 = 0x4224f3b6;
  _DAT_007789c4 = 0x3f400000;
  _DAT_007789d0 = 0xbf9a7efa;
  _DAT_007789d4 = 0xbf8ac083;
  _DAT_007789d8 = 0x3f4624dd;
  return param_1;
}


// ==== 0x487070 FUN_00487070

void __fastcall FUN_00487070(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_EAX;
  
  *in_EAX = *param_1;
  in_EAX[1] = param_1[1];
  in_EAX[2] = param_1[2];
  in_EAX[3] = param_1[3];
  in_EAX[4] = param_1[4];
  uVar1 = param_1[9];
  uVar2 = param_1[10];
  in_EAX[8] = param_1[8];
  in_EAX[9] = uVar1;
  in_EAX[10] = uVar2;
  uVar1 = param_1[0xd];
  uVar2 = param_1[0xe];
  in_EAX[0xc] = param_1[0xc];
  in_EAX[0xd] = uVar1;
  in_EAX[0xe] = uVar2;
  return;
}


// ==== 0x4870c0 FUN_004870c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004870c0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  float10 fVar6;
  float10 fVar7;
  float local_a8;
  float local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 local_50 [76];
  
  pfVar4 = (float *)(param_1 + 0x40);
  if (DAT_00735f0c == '\0') {
    iVar5 = *(int *)(param_1 + 0x2c);
    if (iVar5 == 3) {
      fVar1 = DAT_0073ad38 * 60.0;
      fVar3 = *(float *)(param_1 + 0x184) * 1.0 * fVar1 + *pfVar4;
      *pfVar4 = fVar3;
      fVar2 = *(float *)(param_1 + 0x188) * 1.0 * fVar1 + *(float *)(param_1 + 0x44);
      *(float *)(param_1 + 0x44) = fVar2;
      fVar1 = *(float *)(param_1 + 0x180) * 0.125 * fVar1 + *(float *)(param_1 + 0x48);
      *(float *)(param_1 + 0x48) = fVar1;
      if (360.0 < fVar2) {
        *(float *)(param_1 + 0x44) = fVar2 - 360.0;
      }
      if (*(float *)(param_1 + 0x44) < 0.0) {
        *(float *)(param_1 + 0x44) = *(float *)(param_1 + 0x44) + 360.0;
      }
      if (140.0 < fVar3) {
        *pfVar4 = 140.0;
      }
      if (*pfVar4 < 85.0) {
        *pfVar4 = 85.0;
      }
      if (6.0 < fVar1) {
        *(undefined4 *)(param_1 + 0x48) = 0x40c00000;
      }
      if (*(float *)(param_1 + 0x48) < 6.0) {
        *(undefined4 *)(param_1 + 0x48) = 0x40c00000;
      }
      FUN_00487f50();
    }
    else if (iVar5 == 1) {
      if (*(int *)(param_1 + 0x30) < 4) {
        pfVar4 = (float *)(&DAT_007788e0 + *(int *)(param_1 + 0x30) * 0x40);
      }
    }
    else if ((iVar5 == 0) || (iVar5 == 2)) {
      local_a8 = 1.0;
      fVar1 = DAT_0073ad38 + *(float *)(param_1 + 0x18c);
      *(float *)(param_1 + 0x18c) = fVar1;
      if ((0.0 < *(float *)(param_1 + 400)) && (fVar1 < *(float *)(param_1 + 400))) {
        local_a8 = fVar1 / *(float *)(param_1 + 400);
      }
      _ftol_nocw();
      fVar6 = (float10)FUN_00564b10();
      fVar6 = (fVar6 + (float10)_K_ONE) * (float10)0.5;
      fVar7 = (float10)_K_ONE - fVar6;
      *pfVar4 = (float)(fVar6 * (float10)*(float *)(param_1 + 0xc0) +
                       fVar7 * (float10)*(float *)(param_1 + 0x80));
      *(float *)(param_1 + 0x44) =
           (float)(fVar6 * (float10)*(float *)(param_1 + 0xc4) +
                  fVar7 * (float10)*(float *)(param_1 + 0x84));
      *(float *)(param_1 + 0x48) =
           (float)(fVar6 * (float10)*(float *)(param_1 + 200) +
                  fVar7 * (float10)*(float *)(param_1 + 0x88));
      *(float *)(param_1 + 0x4c) =
           (float)(fVar6 * (float10)*(float *)(param_1 + 0xcc) +
                  fVar7 * (float10)*(float *)(param_1 + 0x8c));
      *(float *)(param_1 + 0x50) =
           (float)(fVar6 * (float10)*(float *)(param_1 + 0xd0) +
                  fVar7 * (float10)*(float *)(param_1 + 0x90));
      *(float *)(param_1 + 0x60) =
           (float)(((float10)*(float *)(param_1 + 0xe0) - (float10)*(float *)(param_1 + 0xa0)) *
                  fVar6) + *(float *)(param_1 + 0xa0);
      *(float *)(param_1 + 0x68) =
           (float)((float10)*(float *)(param_1 + 0xa8) +
                  (float10)(*(float *)(param_1 + 0xe8) - *(float *)(param_1 + 0xa8)) * fVar6);
      *(float *)(param_1 + 100) =
           *(float *)(param_1 + 0xa4) +
           (float)(((float10)*(float *)(param_1 + 0xe4) - (float10)*(float *)(param_1 + 0xa4)) *
                  fVar6);
      *(float *)(param_1 + 0x70) =
           (float)(((float10)*(float *)(param_1 + 0xf0) - (float10)*(float *)(param_1 + 0xb0)) *
                  fVar6) + *(float *)(param_1 + 0xb0);
      *(float *)(param_1 + 0x78) =
           (float)((float10)*(float *)(param_1 + 0xb8) +
                  fVar6 * (float10)(*(float *)(param_1 + 0xf8) - *(float *)(param_1 + 0xb8)));
      *(float *)(param_1 + 0x74) =
           *(float *)(param_1 + 0xb4) +
           (float)(((float10)*(float *)(param_1 + 0xf4) - (float10)*(float *)(param_1 + 0xb4)) *
                  fVar6);
      if (360.0 < *(float *)(param_1 + 0x44)) {
        *(float *)(param_1 + 0x44) = *(float *)(param_1 + 0x44) - 360.0;
      }
      if (*(float *)(param_1 + 0x44) < 0.0) {
        *(float *)(param_1 + 0x44) = *(float *)(param_1 + 0x44) + 360.0;
      }
      if (360.0 < *(float *)(param_1 + 0x4c)) {
        *(float *)(param_1 + 0x4c) = *(float *)(param_1 + 0x4c) - 360.0;
      }
      if (*(float *)(param_1 + 0x4c) < 0.0) {
        *(float *)(param_1 + 0x4c) = *(float *)(param_1 + 0x4c) + 360.0;
      }
      if (*(int *)(param_1 + 0x2c) == 2) {
        *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x194);
      }
      if ((*(int *)(param_1 + 0x2c) == 0) && (_K_ONE <= local_a8)) {
        *(undefined4 *)(param_1 + 0x2c) = 4;
      }
    }
    else if ((iVar5 != 4) && (iVar5 == 5)) {
      pfVar4 = (float *)(param_1 + 0x140);
    }
  }
  else {
    local_90 = DAT_006fbe54;
    local_8c = DAT_006fbe58;
    local_88 = DAT_006fbe5c;
    local_84 = DAT_00735f10;
    local_80 = DAT_006fbe60;
    local_70 = DAT_00735f14;
    local_6c = DAT_006fbe64;
    local_68 = DAT_00735f18;
    local_60 = DAT_00735f1c;
    local_5c = DAT_00735f20;
    local_58 = DAT_006fbe68;
    pfVar4 = &local_90;
  }
  _DAT_00735f24 = pfVar4[0xc];
  _DAT_00735f28 = pfVar4[0xd];
  _DAT_00735f2c = pfVar4[0xe];
  CameraMover_BuildBankedFrame(local_50);
  if (DAT_00735f5c == 0) {
    iVar5 = _ftol_nocw();
    *(short *)(*(int *)(param_1 + 0x1c) + 0xc4) =
         (short)((ulonglong)((longlong)iVar5 * 0xb60b60b7) >> 0x28) -
         ((short)(char)((char)(iVar5 / 0x1680000) + (char)(iVar5 >> 0x1f)) >> 0xf);
    *(float *)(*(int *)(param_1 + 0x1c) + 0xb0) = pfVar4[2];
  }
  Camera__SetCameraMatrix(*(undefined4 *)(param_1 + 0x1c),local_50,DAT_0073ad38);
  return;
}


// ==== 0x487590 FUN_00487590

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00487590(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *unaff_ESI;
  undefined1 local_50 [48];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  if ((_DAT_0078f100 & 1) == 0) {
    _DAT_0078f100 = _DAT_0078f100 | 1;
  }
  if (DAT_0078eb3c == 0) {
    CameraMover_BuildBankedFrame(local_50,0x42ba0000,0x42e60000,0x40c00000,0,0x42340000);
    DAT_0078f0f0 = local_20;
    _DAT_0078f0f4 = local_1c;
    _DAT_0078f0f8 = local_18;
    DAT_0078eb3c = 1;
  }
  uVar2 = _DAT_0078f0f8;
  uVar1 = _DAT_0078f0f4;
  *unaff_ESI = DAT_0078f0f0;
  unaff_ESI[1] = uVar1;
  unaff_ESI[2] = uVar2;
  return;
}


// ==== 0x487680 CameraMover_BuildBankedFrame

/* [canon] camera med (hopper+capstone) docs/re/misc.md */

void CameraMover_BuildBankedFrame(undefined4 *param_1)

{
  undefined1 auStack_ac [92];
  undefined1 local_50 [76];
  
  *param_1 = 0x3f800000;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0x3f800000;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0x3f800000;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0x3f800000;
  _ftol_nocw();
  FUN_0040b930();
  D3DXMatrixMultiply(param_1,param_1,local_50);
  _ftol_nocw();
  FUN_0040b990(param_1,param_1);
  eTranslate(param_1,param_1);
  Matrix_InvertRigid();
  _ftol_nocw();
  CameraMover__ComputeBankedUpVector(auStack_ac);
  Matrix4_BuildLookAt(auStack_ac);
  return;
}


// ==== 0x4877d0 CameraMover_SetTransitionParamA

/* [canon] camera med (ghidra-canon+hopper) docs/re/runtime.md */

void __thiscall CameraMover_SetTransitionParamA(int param_1,undefined4 param_2)

{
  if ((*(int *)(param_1 + 0x2c) != 2) && (*(int *)(param_1 + 0x2c) != 0)) {
    *(undefined4 *)(param_1 + 0x2c) = 3;
    *(undefined4 *)(param_1 + 0x184) = param_2;
  }
  return;
}


// ==== 0x4877f0 CameraMover_SetTransitionParamB

/* [canon] camera med (ghidra-canon+hopper) docs/re/runtime.md */

void __thiscall CameraMover_SetTransitionParamB(int param_1,undefined4 param_2)

{
  if ((*(int *)(param_1 + 0x2c) != 2) && (*(int *)(param_1 + 0x2c) != 0)) {
    *(undefined4 *)(param_1 + 0x2c) = 3;
    *(undefined4 *)(param_1 + 0x188) = param_2;
  }
  return;
}


// ==== 0x487810 FUN_00487810

void __thiscall FUN_00487810(int param_1,undefined4 param_2)

{
  if ((*(int *)(param_1 + 0x2c) != 2) && (*(int *)(param_1 + 0x2c) != 0)) {
    *(undefined4 *)(param_1 + 0x2c) = 3;
    *(undefined4 *)(param_1 + 0x180) = param_2;
  }
  return;
}


// ==== 0x487830 FUN_00487830

void __thiscall
FUN_00487830(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  *(undefined4 *)(param_1 + 0x100) = param_2;
  *(undefined4 *)(param_1 + 0x104) = param_3;
  *(undefined4 *)(param_1 + 0x108) = param_4;
  *(undefined4 *)(param_1 + 0x10c) = param_5;
  *(undefined4 *)(param_1 + 0x110) = param_6;
  *(undefined4 *)(param_1 + 0x120) = param_7;
  *(undefined4 *)(param_1 + 0x124) = param_8;
  *(undefined4 *)(param_1 + 0x128) = param_9;
  *(undefined4 *)(param_1 + 0x130) = param_10;
  *(undefined4 *)(param_1 + 0x134) = param_11;
  *(undefined4 *)(param_1 + 0x138) = param_12;
  *(undefined4 *)(param_1 + 0x34) = 1;
  if (*(int *)(param_1 + 0x2c) != 2) {
    FUN_004878c0();
  }
  return;
}


// ==== 0x4878c0 FUN_004878c0

void __fastcall FUN_004878c0(int param_1)

{
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_00487980(*(undefined4 *)(param_1 + 0x100),*(undefined4 *)(param_1 + 0x104),
                 *(undefined4 *)(param_1 + 0x108),*(undefined4 *)(param_1 + 0x10c),
                 *(undefined4 *)(param_1 + 0x110),*(undefined4 *)(param_1 + 0x120),
                 *(undefined4 *)(param_1 + 0x124),*(undefined4 *)(param_1 + 0x128),
                 *(undefined4 *)(param_1 + 0x130),*(undefined4 *)(param_1 + 0x134),
                 *(undefined4 *)(param_1 + 0x138));
  }
  return;
}


// ==== 0x487920 FUN_00487920

void FUN_00487920(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x34) != 0) {
    FUN_00487980(0x42ba0000,*(undefined4 *)(unaff_ESI + 0x44),0x40c00000,0,0x42340000,0,0x3f400000,0
                 ,0,0,0x3f400000);
    *(undefined4 *)(unaff_ESI + 0x34) = 0;
  }
  return;
}


// ==== 0x487980 FUN_00487980

void __thiscall
FUN_00487980(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  float10 fVar1;
  
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0x78);
  *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(param_1 + 200) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)(param_1 + 0xf8) = *(undefined4 *)(param_1 + 0x78);
  *(undefined4 *)(param_1 + 0xc0) = param_2;
  *(undefined4 *)(param_1 + 0xc4) = param_3;
  *(undefined4 *)(param_1 + 200) = param_4;
  *(undefined4 *)(param_1 + 0xcc) = param_5;
  *(undefined4 *)(param_1 + 0xd0) = param_6;
  *(undefined4 *)(param_1 + 0xe0) = param_7;
  *(undefined4 *)(param_1 + 0xe4) = param_8;
  *(undefined4 *)(param_1 + 0xe8) = param_9;
  *(undefined4 *)(param_1 + 0xf0) = param_10;
  *(undefined4 *)(param_1 + 0xf8) = param_12;
  *(undefined4 *)(param_1 + 0xf4) = param_11;
  fVar1 = (float10)FUN_00488380(param_1,*(undefined4 *)(param_1 + 0x80),
                                *(undefined4 *)(param_1 + 0xc0));
  *(float *)(extraout_ECX + 0xc0) = (float)fVar1;
  fVar1 = (float10)FUN_00488380(extraout_ECX,*(undefined4 *)(extraout_ECX + 0x84),
                                *(undefined4 *)(extraout_ECX + 0xc4));
  *(float *)(extraout_ECX_00 + 0xc4) = (float)fVar1;
  fVar1 = (float10)FUN_00488380(extraout_ECX_00,*(undefined4 *)(extraout_ECX_00 + 0x8c),
                                *(undefined4 *)(extraout_ECX_00 + 0xcc));
  *(float *)(extraout_ECX_01 + 0xcc) = (float)fVar1;
  FUN_00487ee0();
  return;
}


// ==== 0x487b20 CameraMover_SetupSpline

/* [canon] camera med (ghidra-canon+hopper) docs/re/runtime.md */

void CameraMover_SetupSpline
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x140) = param_2;
  *(undefined4 *)(in_EAX + 0x144) = param_1;
  *(undefined4 *)(in_EAX + 0x148) = param_3;
  *(undefined4 *)(in_EAX + 0x14c) = param_7;
  *(undefined4 *)(in_EAX + 0x150) = param_8;
  *(undefined4 *)(in_EAX + 0x2c) = 5;
  *(undefined4 *)(in_EAX + 0x160) = param_4;
  *(undefined4 *)(in_EAX + 0x164) = param_5;
  *(undefined4 *)(in_EAX + 0x168) = param_6;
  *(undefined4 *)(in_EAX + 0x170) = param_9;
  *(undefined4 *)(in_EAX + 0x174) = param_10;
  *(undefined4 *)(in_EAX + 0x178) = param_11;
  return;
}


// ==== 0x487ba0 FUN_00487ba0

void FUN_00487ba0(void)

{
  float *pfVar1;
  int in_EAX;
  int unaff_ESI;
  float10 fVar2;
  
  if (in_EAX != 4) {
    *(undefined4 *)(unaff_ESI + 0x2c) = 1;
    *(int *)(unaff_ESI + 0x30) = in_EAX;
    return;
  }
  if (*(int *)(unaff_ESI + 0x2c) == 1) {
    *(undefined4 *)(unaff_ESI + 0x2c) = 0;
    if (*(int *)(unaff_ESI + 0x30) < 4) {
      FUN_00487070();
    }
    pfVar1 = (float *)(unaff_ESI + 0xc0);
    FUN_00487070();
    *pfVar1 = 93.0;
    *(undefined4 *)(unaff_ESI + 0xc4) = 0x42e60000;
    *(undefined4 *)(unaff_ESI + 0xcc) = 0;
    *(undefined4 *)(unaff_ESI + 200) = 0x40c00000;
    *(undefined4 *)(unaff_ESI + 0xd0) = 0x42340000;
    *(undefined4 *)(unaff_ESI + 0xe4) = 0x3f400000;
    *(undefined4 *)(unaff_ESI + 0xe0) = 0;
    *(undefined4 *)(unaff_ESI + 0xe8) = 0;
    *(undefined4 *)(unaff_ESI + 0xf4) = 0;
    *(undefined4 *)(unaff_ESI + 0xf0) = 0;
    *(undefined4 *)(unaff_ESI + 0xf8) = 0x3f400000;
    fVar2 = (float10)FUN_00488380(unaff_ESI,*(undefined4 *)(unaff_ESI + 0x80),*pfVar1);
    *pfVar1 = (float)fVar2;
    fVar2 = (float10)FUN_00488380(unaff_ESI,*(undefined4 *)(unaff_ESI + 0x84),
                                  *(undefined4 *)(unaff_ESI + 0xc4));
    *(float *)(unaff_ESI + 0xc4) = (float)fVar2;
    fVar2 = (float10)FUN_00488380(unaff_ESI,*(undefined4 *)(unaff_ESI + 0x8c),
                                  *(undefined4 *)(unaff_ESI + 0xcc));
    *(float *)(unaff_ESI + 0xcc) = (float)fVar2;
    FUN_00487ee0();
    *(undefined4 *)(unaff_ESI + 0x30) = 4;
  }
  return;
}


// ==== 0x487cc0 FUN_00487cc0

void FUN_00487cc0(void)

{
  int unaff_ESI;
  undefined4 local_4;
  
  if (*(int *)(unaff_ESI + 0x2c) != 1) {
    local_4 = 0x42be0000;
    if (95.0 < *(float *)(unaff_ESI + 0x40)) {
      local_4 = *(undefined4 *)(unaff_ESI + 0x40);
    }
    FUN_00487980(local_4,0x425c0000,0x40c00000,0,0x42340000,0,0x3f400000,0,0,0,0x3f400000);
    *(undefined4 *)(unaff_ESI + 0x184) = 0;
    *(undefined4 *)(unaff_ESI + 0x188) = 0;
    *(float *)(unaff_ESI + 400) = *(float *)(unaff_ESI + 400) * 2.0;
    *(undefined4 *)(unaff_ESI + 0x2c) = 2;
  }
  return;
}


// ==== 0x487d70 FUN_00487d70

undefined4 __fastcall FUN_00487d70(int param_1)

{
  if ((*(int *)(param_1 + 0x2c) != 1) &&
     ((*(int *)(param_1 + 0x2c) != 2 || (*(float *)(param_1 + 0x18c) < *(float *)(param_1 + 400)))))
  {
    return 0;
  }
  return 1;
}


// ==== 0x487da0 FUN_00487da0

void FUN_00487da0(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x2c) != 1) {
    FUN_00487980(0x42e60000,0,0x40c00000,0,0x42340000,0,0x3f400000,0,0,0,0x3f400000);
    *(undefined4 *)(unaff_ESI + 0x184) = 0;
    *(undefined4 *)(unaff_ESI + 0x188) = 0;
    *(float *)(unaff_ESI + 400) = *(float *)(unaff_ESI + 400) * 3.2;
    *(undefined4 *)(unaff_ESI + 0x2c) = 2;
  }
  return;
}


// ==== 0x487e20 FUN_00487e20

void FUN_00487e20(void)

{
  float fVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x2c) != 1) {
    FUN_00487980(0x42ba0000,0x42e60000,0x40c00000,0,0x42340000,0,0x3f400000,0,0,0,0x3f400000);
    fVar1 = *(float *)(unaff_ESI + 400) * 2.0;
    *(undefined4 *)(unaff_ESI + 0x184) = 0;
    *(undefined4 *)(unaff_ESI + 0x188) = 0;
    *(float *)(unaff_ESI + 400) = fVar1;
    *(undefined4 *)(unaff_ESI + 0x2c) = 2;
    *(float *)(unaff_ESI + 0x18c) = fVar1;
  }
  return;
}


// ==== 0x487eb0 FUN_00487eb0

void __fastcall FUN_00487eb0(int param_1)

{
  if (*(int *)(param_1 + 0x2c) != 1) {
    if (*(int *)(param_1 + 0x2c) == 2) {
      *(undefined4 *)(param_1 + 0x184) = 0;
      *(undefined4 *)(param_1 + 0x188) = 0;
      *(undefined4 *)(param_1 + 0x2c) = 3;
    }
    if (*(int *)(param_1 + 0x34) != 0) {
      FUN_004878c0();
      return;
    }
  }
  return;
}


// ==== 0x487ee0 FUN_00487ee0

void __fastcall FUN_00487ee0(int param_1)

{
  float fVar1;
  
  *(undefined4 *)(param_1 + 0x18c) = 0;
  fVar1 = (ABS(*(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xc0)) +
          ABS(*(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xc4)) +
          ABS(*(float *)(param_1 + 0x90) - *(float *)(param_1 + 0xd0)) * 2.0) * 0.0055;
  *(float *)(param_1 + 400) = fVar1;
  if (fVar1 < 0.3) {
    *(undefined4 *)(param_1 + 400) = 0x3e99999a;
  }
  return;
}


// ==== 0x487f50 FUN_00487f50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00487f50(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int unaff_ESI;
  float10 fVar5;
  float local_48;
  float local_44;
  
  fVar5 = (float10)FUN_00488380(unaff_ESI,*(undefined4 *)(unaff_ESI + 0x4c),0);
  fVar1 = (float)fVar5;
  if (*(float *)(unaff_ESI + 0x4c) == fVar1) {
    local_48 = 0.0;
  }
  else {
    local_48 = ABS(*(float *)(unaff_ESI + 0x4c) - fVar1);
    if (local_48 == 0.0) {
      local_48 = 0.0;
    }
    else {
      local_48 = local_48 / (DAT_0073ad38 * 75.0);
    }
  }
  if (*(float *)(unaff_ESI + 0x50) == 45.0) {
    local_44 = 0.0;
  }
  else {
    local_44 = ABS(*(float *)(unaff_ESI + 0x50) - 45.0);
    if (local_44 == 0.0) {
      local_44 = 0.0;
    }
    else {
      local_44 = local_44 / (DAT_0073ad38 * 50.0);
    }
  }
  fVar5 = (float10)FUN_00488190(unaff_ESI,DAT_0073ad38 * 2.2);
  fVar2 = (float)fVar5;
  fVar5 = (float10)FUN_00488190(unaff_ESI,DAT_0073ad38 * 2.2);
  fVar3 = (float)fVar5;
  fVar4 = local_48;
  if (local_48 < local_44) {
    fVar4 = local_44;
  }
  if (fVar4 < fVar2) {
    fVar4 = fVar2;
  }
  if (fVar4 < fVar3) {
    fVar4 = fVar3;
  }
  if (fVar4 == 0.0) {
    return;
  }
  fVar4 = _K_ONE / fVar4;
  FUN_00488220(unaff_ESI,fVar1,fVar4 * local_48 * DAT_0073ad38 * 75.0);
  FUN_00488220(unaff_ESI,0x42340000,fVar4 * local_44 * 50.0 * DAT_0073ad38);
  FUN_00488280(unaff_ESI,fVar4 * fVar2 * 2.2 * DAT_0073ad38);
  FUN_00488280(unaff_ESI,fVar4 * fVar3 * 2.2 * DAT_0073ad38);
  return;
}


// ==== 0x488190 FUN_00488190

float10 __fastcall FUN_00488190(float *param_1,float *param_2,undefined4 param_3,float param_4)

{
  if ((((0.001 < ABS(*param_2 - *param_1)) || (0.001 < ABS(param_2[1] - param_1[1]))) ||
      (0.001 < ABS(param_2[2] - param_1[2]))) && (param_4 != 0.0)) {
    return SQRT(((float10)param_1[1] - (float10)param_2[1]) *
                ((float10)param_1[1] - (float10)param_2[1]) +
                ((float10)param_1[2] - (float10)param_2[2]) *
                ((float10)param_1[2] - (float10)param_2[2]) +
                ((float10)*param_1 - (float10)*param_2) * ((float10)*param_1 - (float10)*param_2)) /
           (float10)param_4;
  }
  return (float10)0.0;
}


// ==== 0x488220 FUN_00488220

void __thiscall FUN_00488220(float *param_1,undefined4 param_2,float param_3,float param_4)

{
  float fVar1;
  
  if (param_3 <= *param_1) {
    if ((param_3 < *param_1) &&
       (fVar1 = *param_1, *param_1 = fVar1 - param_4, fVar1 - param_4 < param_3)) {
      *param_1 = param_3;
    }
  }
  else {
    fVar1 = *param_1;
    *param_1 = param_4 + fVar1;
    if (param_3 < param_4 + fVar1) {
      *param_1 = param_3;
      return;
    }
  }
  return;
}


// ==== 0x488280 FUN_00488280

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00488280(float *param_1,float *param_2,undefined4 param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  if (((0.001 < ABS(*param_1 - *param_2)) || (0.001 < ABS(param_1[1] - param_2[1]))) ||
     (0.001 < ABS(param_1[2] - param_2[2]))) {
    fVar1 = *param_2 - *param_1;
    fVar3 = param_2[1] - param_1[1];
    fVar2 = param_2[2] - param_1[2];
    fVar4 = SQRT(fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3);
    if (fVar4 < param_4) {
      fVar1 = param_2[1];
      fVar2 = param_2[2];
      *param_1 = *param_2;
      param_1[1] = fVar1;
      param_1[2] = fVar2;
      return;
    }
    fVar4 = _K_ONE / fVar4;
    *param_1 = fVar1 * fVar4 * param_4 + *param_1;
    param_1[2] = fVar4 * fVar2 * param_4 + param_1[2];
    param_1[1] = fVar3 * fVar4 * param_4 + param_1[1];
  }
  return;
}


// ==== 0x488380 FUN_00488380

float10 FUN_00488380(undefined4 param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  
  fVar1 = ABS(param_2 - (param_3 + 360.0));
  fVar2 = ABS(param_2 - (param_3 - 360.0));
  if ((fVar1 < ABS(param_2 - param_3)) && (fVar1 < fVar2)) {
    return (float10)(param_3 + 360.0);
  }
  if ((fVar2 < ABS(param_2 - param_3)) && (fVar2 < fVar1)) {
    return (float10)(param_3 - 360.0);
  }
  return (float10)param_3;
}


// ==== 0x488420 DebugWorldCameraMover::ctor

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera V (G+C) docs/re/camera.md */

undefined4 *
DebugWorldCameraMover__ctor
          (undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 *unaff_EDI;
  void *local_10;
  code *pcStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_00686ce8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  CameraMover__ctor();
  param_1[0x10] = param_4;
  *param_1 = &PTR_FUN_006c7d80;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  *(undefined2 *)(param_1 + 0xf) = 0;
  *(undefined2 *)((int)param_1 + 0x3e) = 0;
  uRam00705b44 = param_3[1];
  DAT_00705b48 = param_3[2];
  uRam00705b40 = *param_3;
                    /* WARNING: Read-only address (ram,0x00705b40) is written */
                    /* WARNING: Read-only address (ram,0x00705b44) is written */
  local_8 = 0;
  DAT_00735f30 = 0;
  _DAT_00736820 = *unaff_EDI;
  DAT_00736824 = unaff_EDI[1];
  DAT_00735f34 = 0;
  DAT_00736828 = unaff_EDI[2];
  DAT_00735f38 = 0;
  param_1[0x11] = 0x80000000;
  param_1[0x12] = 0;
  FUN_00488550();
  ExceptionList = local_10;
  return param_1;
}


// ==== 0x4884e0 FUN_004884e0

void * __thiscall FUN_004884e0(void *param_1,byte param_2)

{
  FUN_00488500();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x488500 FUN_00488500

void __fastcall FUN_00488500(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_006c7d80;
  FUN_004886c0();
  *param_1 = &PTR_CameraMover__TrivialDtor_006c7c50;
  if (param_1[5] != 0) {
    param_1[5] = 0;
    param_1[9] = *(undefined4 *)(param_1[7] + 0x280);
    param_1[10] = *(undefined4 *)(param_1[7] + 0x284);
    iVar1 = param_1[1];
    piVar2 = (int *)param_1[2];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    ViewList_UpdateViewCountKind();
    return;
  }
  return;
}


// ==== 0x488550 FUN_00488550

void __fastcall FUN_00488550(int param_1)

{
  if (*(int *)(param_1 + 0x48) == 0) {
    InputEvents__AddSource(0x4e,FUN_004887b0,param_1);
    InputEvents__AddSource(0x4f,FUN_004887b0,param_1);
    InputEvents__AddSource(0x50,FUN_004887b0,param_1);
    InputEvents__AddSource(0x51,FUN_004887b0,param_1);
    InputEvents__AddSource(0x52,FUN_004887b0,param_1);
    InputEvents__AddSource(0x53,FUN_004887b0,param_1);
    InputEvents__AddSource(0x54,FUN_004887b0,param_1);
    InputEvents__AddSource(0x55,FUN_004887b0,param_1);
    InputEvents__AddSource(0x56,FUN_004887b0,param_1);
    InputEvents__AddSource(0x57,FUN_004887b0,param_1);
    InputEvents__AddSource(0x58,FUN_004887b0,param_1);
    InputEvents__AddSource(0x59,FUN_004887b0,param_1);
    InputEvents__AddSource(0x5a,FUN_004887b0,param_1);
    InputEvents__AddSource(0x5b,FUN_004887b0,param_1);
    InputEvents__AddSource(0x5c,FUN_004887b0,param_1);
    InputEvents__AddSource(0x5d,FUN_004887b0,param_1);
    InputEvents__AddSource(0x5e,FUN_004887b0,param_1);
    InputEvents__AddSource(0x5f,FUN_004887b0,param_1);
    InputEvents__AddSource(0x60,FUN_004887b0,param_1);
    InputEvents__AddSource(0x61,FUN_004887b0,param_1);
    *(undefined4 *)(param_1 + 0x48) = 1;
  }
  return;
}


// ==== 0x4886c0 FUN_004886c0

void __fastcall FUN_004886c0(int param_1)

{
  if (*(int *)(param_1 + 0x48) != 0) {
    FUN_005740b0(0x4e);
    FUN_005740b0(0x4f);
    FUN_005740b0(0x50);
    FUN_005740b0(0x51);
    FUN_005740b0(0x52);
    FUN_005740b0(0x53);
    FUN_005740b0(0x54);
    FUN_005740b0(0x55);
    FUN_005740b0(0x56);
    FUN_005740b0(0x57);
    FUN_005740b0(0x58);
    FUN_005740b0(0x59);
    FUN_005740b0(0x5a);
    FUN_005740b0(0x5b);
    FUN_005740b0(0x5c);
    FUN_005740b0(0x5d);
    FUN_005740b0(0x5e);
    FUN_005740b0(0x5f);
    FUN_005740b0(0x60);
    FUN_005740b0(0x61);
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  return;
}


// ==== 0x4887b0 FUN_004887b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004887b0(undefined4 param_1,undefined4 param_2,byte param_3,int param_4)

{
  undefined2 uVar1;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  local_34 = (float)(uint)param_3;
  Curve_Evaluate(&local_34,(float)(int)local_34 - 128.0);
  switch(param_2) {
  case 0x4e:
    *(ushort *)(param_4 + 0x3c) = -(ushort)(param_3 != 0) & 11000;
    return;
  case 0x4f:
    *(ushort *)(param_4 + 0x3c) = -(ushort)(param_3 != 0) & 0xd508;
    return;
  case 0x50:
    *(ushort *)(param_4 + 0x3e) = -(ushort)(param_3 != 0) & 0xd508;
    return;
  case 0x51:
    *(ushort *)(param_4 + 0x3e) = -(ushort)(param_3 != 0) & 11000;
    return;
  case 0x52:
    if (param_3 == 0) {
      *(undefined4 *)(param_4 + 0x2c) = 0;
      return;
    }
    *(undefined4 *)(param_4 + 0x2c) = 0xc0f00000;
    return;
  case 0x53:
    if (param_3 == 0) {
      *(undefined4 *)(param_4 + 0x2c) = 0;
      return;
    }
    *(undefined4 *)(param_4 + 0x2c) = 0x40f00000;
    return;
  case 0x54:
    if (param_3 != 0) {
      *(undefined4 *)(param_4 + 0x34) = 0;
      *(undefined4 *)(param_4 + 0x30) = 0x41f00000;
      return;
    }
    break;
  case 0x55:
    if (param_3 != 0) {
      *(undefined4 *)(param_4 + 0x34) = 0;
      *(undefined4 *)(param_4 + 0x30) = 0xc1f00000;
      return;
    }
    break;
  case 0x56:
    if (param_3 == 0) {
      *(undefined4 *)(param_4 + 0x38) = 0;
      return;
    }
    *(undefined4 *)(param_4 + 0x38) = 0x41f00000;
    return;
  case 0x57:
    if (param_3 == 0) {
      *(undefined4 *)(param_4 + 0x38) = 0;
      return;
    }
    *(undefined4 *)(param_4 + 0x38) = 0xc1f00000;
    return;
  case 0x58:
    DAT_00735f30 = (uint)(param_3 != 0);
    return;
  case 0x59:
    DAT_00735f34 = (uint)(param_3 != 0);
    return;
  case 0x5a:
    DAT_00735f38 = (uint)(param_3 != 0);
    return;
  default:
    return;
  case 0x5d:
    if (DAT_007361b4 == 0) {
      return;
    }
    local_30 = _DAT_00736820 - 20.0;
    local_2c = DAT_00736824 - 20.0;
    local_28 = DAT_00736828 - DAT_00705b48;
    bNormalize3();
    local_20 = local_30 * 10.0 + 20.0;
    local_1c = local_2c * 10.0 + 20.0;
    local_18 = local_28 * 10.0 + DAT_00705b48;
    FUN_00427e60(0,0);
    return;
  case 0x5e:
    uVar1 = _ftol_nocw();
    *(undefined2 *)(param_4 + 0x3c) = uVar1;
    return;
  case 0x5f:
    uVar1 = _ftol_nocw();
    *(undefined2 *)(param_4 + 0x3e) = uVar1;
    return;
  case 0x60:
    *(float *)(param_4 + 0x38) = local_34 * -0.2;
    return;
  case 0x61:
    *(float *)(param_4 + 0x34) = local_34 * -0.2;
    return;
  }
  *(undefined4 *)(param_4 + 0x30) = 0;
  *(undefined4 *)(param_4 + 0x34) = 0;
  return;
}


// ==== 0x488ae0 FUN_00488ae0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00488ae0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined2 uVar4;
  float *pfVar5;
  int iVar6;
  int extraout_EDX;
  int extraout_EDX_00;
  float10 fVar7;
  float10 fVar8;
  float local_348;
  undefined1 local_330 [16];
  undefined1 local_320 [64];
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
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  pcStack_18 = FUN_0068600b;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  if (-1 < DAT_006fbe78) {
    ExceptionList = &local_1c;
    if ((((DAT_00734968 != 0) && (ExceptionList = &local_1c, DAT_007344d0 != 0)) &&
        (ExceptionList = &local_1c, DAT_006fbe78 < *(int *)(DAT_007344d0 + 0x2000))) &&
       (pfVar5 = (float *)(DAT_006fbe78 * 0x10 + DAT_007344d0), ExceptionList = &local_1c,
       pfVar5 != (float *)0x0)) {
      fVar2 = 20.0 - _DAT_00736820;
      fVar1 = 20.0 - DAT_00736824;
      fVar3 = DAT_00705b48 - DAT_00736828;
      ExceptionList = &local_1c;
      FUN_005673e0(0x41200000);
      fRam00705b40 = *pfVar5 + fVar2;
      fRam00705b44 = fVar1 + pfVar5[1];
      DAT_00705b48 = fVar3 + pfVar5[2];
                    /* WARNING: Read-only address (ram,0x00705b40) is written */
                    /* WARNING: Read-only address (ram,0x00705b44) is written */
      DAT_00736828 = pfVar5[2];
      _DAT_00736820 = *pfVar5;
      DAT_00736824 = pfVar5[1];
    }
    DAT_006fbe78 = -1;
  }
  if (DAT_00736834 != 0.0) {
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    FUN_00440740();
    fVar7 = (float10)GroundQuery__FindSurfaceBelow(local_2e0,&DAT_00736830,0,0,0);
    DAT_00736838 = (float)(fVar7 + (float10)3.0);
    fVar1 = 20.0 - _DAT_00736820;
    fVar2 = 20.0 - DAT_00736824;
    fVar3 = DAT_00705b48 - DAT_00736828;
    FUN_005673e0(0x41200000);
    fRam00705b40 = fVar1 + DAT_00736830;
    fRam00705b44 = fVar2 + DAT_00736834;
    DAT_00736824 = DAT_00736834;
    DAT_00705b48 = fVar3 + DAT_00736838;
                    /* WARNING: Read-only address (ram,0x00705b40) is written */
    DAT_00736828 = DAT_00736838;
                    /* WARNING: Read-only address (ram,0x00705b44) is written */
    iVar6 = 0;
    _DAT_00736820 = DAT_00736830;
    DAT_00736830 = 0.0;
    DAT_00736834 = 0.0;
    DAT_00736838 = 0.0;
    if (0 < local_40) {
      do {
        *(char *)(aiStack_2c0[iVar6] + 8) = *(char *)(aiStack_2c0[iVar6] + 8) + -1;
        iVar6 = iVar6 + 1;
      } while (iVar6 < local_40);
    }
  }
  _ftol_nocw();
  _ftol_nocw();
  FUN_00564fa0();
  if (((*(short *)(param_1 + 0x3c) != 0) || (*(short *)(param_1 + 0x3e) != 0)) ||
     (iVar6 = DAT_00735f34, *(float *)(param_1 + 0x2c) != 0.0)) {
    _ftol_nocw();
    _ftol_nocw();
    _ftol_nocw();
    FUN_00564fa0();
    _ftol_nocw();
    if (DAT_00735f34 == 0) {
      if (DAT_00735f30 == 0) {
        fVar1 = DAT_0073ad38 * *(float *)(param_1 + 0x2c);
      }
      else {
        fVar1 = _DAT_006fbe6c * *(float *)(param_1 + 0x2c) * DAT_0073ad38;
      }
    }
    else {
      fVar1 = _DAT_006fbe70 * *(float *)(param_1 + 0x2c) * DAT_0073ad38;
    }
    if (DAT_00735f38 != 0) {
      fVar1 = fVar1 * _DAT_006fbe74;
    }
    DAT_00705b48 = DAT_00705b48 + fVar1;
                    /* WARNING: Read-only address (ram,0x00705b44) is written */
    fRam00705b44 = 20.0;
                    /* WARNING: Read-only address (ram,0x00705b40) is written */
    fRam00705b40 = 20.0;
    fVar7 = (float10)FUN_00564b10();
    fVar8 = (float10)FUN_00564b10();
    _DAT_00736820 = (float)(fVar8 * (float10)(float)fVar7 * (float10)20.0 + (float10)20.0);
    fVar8 = (float10)FUN_00564b10();
    DAT_00736824 = (float)(fVar8 * (float10)(float)fVar7 * (float10)20.0 + (float10)20.0);
    fVar7 = (float10)FUN_00564b10();
    DAT_00736828 = (float)(fVar7 * (float10)20.0 + (float10)DAT_00705b48);
    iVar6 = extraout_EDX;
  }
  if (*(float *)(param_1 + 0x30) != 0.0) {
    if (iVar6 == 0) {
      if (DAT_00735f30 == 0) {
        local_348 = DAT_0073ad38 * *(float *)(param_1 + 0x30);
      }
      else {
        local_348 = _DAT_006fbe6c * *(float *)(param_1 + 0x30) * DAT_0073ad38;
      }
    }
    else {
      local_348 = _DAT_006fbe70 * *(float *)(param_1 + 0x30) * DAT_0073ad38;
    }
    if (DAT_00735f38 != 0) {
      local_348 = _DAT_006fbe74 * local_348;
    }
    fVar7 = (float10)FUN_00564b10();
    fVar8 = (float10)FUN_00564b10();
    fRam00705b40 = (float)(fVar7 * (float10)local_348) + 20.0;
                    /* WARNING: Read-only address (ram,0x00705b40) is written */
                    /* WARNING: Read-only address (ram,0x00705b44) is written */
    fRam00705b44 = (float)((float10)20.0 + fVar8 * (float10)local_348);
    _DAT_00736820 = (float)(fVar7 * (float10)local_348) + _DAT_00736820;
    DAT_00736824 = (float)(fVar8 * (float10)local_348 + (float10)DAT_00736824);
    iVar6 = extraout_EDX_00;
  }
  if (*(float *)(param_1 + 0x34) != 0.0) {
    if (iVar6 == 0) {
      if (DAT_00735f30 == 0) {
        local_348 = DAT_0073ad38 * *(float *)(param_1 + 0x34);
      }
      else {
        local_348 = _DAT_006fbe6c * *(float *)(param_1 + 0x34) * DAT_0073ad38;
      }
    }
    else {
      local_348 = _DAT_006fbe70 * *(float *)(param_1 + 0x34) * DAT_0073ad38;
    }
    if (DAT_00735f38 != 0) {
      local_348 = _DAT_006fbe74 * local_348;
    }
    fVar1 = _DAT_00736820 - 20.0;
    fVar2 = DAT_00736824 - 20.0;
    fVar3 = DAT_00736828 - DAT_00705b48;
    FUN_005673e0(local_348);
    fRam00705b40 = fVar1 + 20.0;
                    /* WARNING: Read-only address (ram,0x00705b40) is written */
    fRam00705b44 = fVar2 + 20.0;
                    /* WARNING: Read-only address (ram,0x00705b44) is written */
    DAT_00705b48 = fVar3 + DAT_00705b48;
    _DAT_00736820 = fVar1 + _DAT_00736820;
    DAT_00736824 = fVar2 + DAT_00736824;
    DAT_00736828 = fVar3 + DAT_00736828;
    iVar6 = DAT_00735f34;
  }
  if (*(float *)(param_1 + 0x38) != 0.0) {
    if (iVar6 == 0) {
      if (DAT_00735f30 == 0) {
        local_348 = DAT_0073ad38 * *(float *)(param_1 + 0x38);
      }
      else {
        local_348 = _DAT_006fbe6c * *(float *)(param_1 + 0x38) * DAT_0073ad38;
      }
    }
    else {
      local_348 = _DAT_006fbe70 * *(float *)(param_1 + 0x38) * DAT_0073ad38;
    }
    if (DAT_00735f38 != 0) {
      local_348 = _DAT_006fbe74 * local_348;
    }
    fVar7 = (float10)FUN_00564b10();
    fVar8 = (float10)FUN_00564b10();
    fRam00705b40 = (float)(fVar7 * (float10)local_348) + 20.0;
                    /* WARNING: Read-only address (ram,0x00705b40) is written */
                    /* WARNING: Read-only address (ram,0x00705b44) is written */
    fRam00705b44 = (float)((float10)20.0 + fVar8 * (float10)local_348);
    _DAT_00736820 = (float)(fVar7 * (float10)local_348) + _DAT_00736820;
    DAT_00736824 = (float)(fVar8 * (float10)local_348 + (float10)DAT_00736824);
  }
  _ftol_nocw();
  CameraMover__ComputeBankedUpVector(local_330);
  Matrix4_BuildLookAt(local_330);
  if (DAT_00735f5c == 0) {
    uVar4 = _ftol_nocw();
    *(undefined2 *)(*(int *)(param_1 + 0x1c) + 0xc4) = uVar4;
  }
  Camera__SetCameraMatrix(*(undefined4 *)(param_1 + 0x1c),local_320,DAT_0073ad38);
  ExceptionList = local_1c;
  return;
}


// ==== 0x4892c0 NullCameraMover::ctor

/* [canon] camera V (C+D) docs/re/camera.md */

undefined4 * __fastcall NullCameraMover__ctor(undefined4 *param_1)

{
  CameraMover__ctor();
  *param_1 = &PTR_CameraMover__TrivialDtor_006c7c50;
  return param_1;
}


// ==== 0x4892e0 FUN_004892e0

int __fastcall FUN_004892e0(int param_1)

{
  if (*(int *)(param_1 + 0x2c) != 0) {
    return *(int *)(param_1 + 0x2c) + 0x50;
  }
  return *(int *)(param_1 + 0x1c) + 0x60;
}


// ==== 0x489300 DriveCameraMover::GetCorrectionYaw

/* [canon] camera high (ghidra-canon+nfsug) docs/re/camera.md */

float10 DriveCameraMover__GetCorrectionYaw(void)

{
  ushort in_AX;
  ushort uVar1;
  uint uVar2;
  float10 fVar3;
  uint local_4;
  
  uVar2 = (uint)in_AX;
  if (0x7fff < in_AX) {
    uVar2 = uVar2 - 0x10000;
  }
  local_4 = uVar2;
  if ((int)uVar2 < 0) {
    local_4 = -uVar2;
  }
  uVar1 = Atan2ToAngle16(0x3f800000,(float)(int)local_4 * 0.000261);
  fVar3 = -((float10)uVar1 * (float10)1.9088);
  if ((int)uVar2 < 0) {
    fVar3 = -fVar3;
  }
  return fVar3;
}


// ==== 0x489360 DriveCameraMover::ctor

/* [canon] camera V (G+C) docs/re/camera.md */

undefined4 * __thiscall
DriveCameraMover__ctor
          (undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          int param_6,undefined4 param_7)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  bool bVar4;
  
  CameraMover__ctor();
  *param_1 = &PTR_FUN_006c7fc8;
  param_1[0xb] = param_2;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  *(undefined2 *)(param_1 + 0x11) = 0;
  param_1[0x12] = (uint)*(ushort *)(param_2 + 0x3b4);
  param_1[0x13] = 0;
  uVar1 = FUN_00564cd0(*(undefined4 *)(param_2 + 0x98));
  param_1[0x16] = 0;
  param_1[0x15] = uVar1 & 0xffff;
  param_1[0xc3] = 0;
  param_1[0xc4] = 0;
  param_1[0xc5] = 0;
  param_1[0xc6] = 0;
  param_1[200] = 0;
  param_1[0xc9] = 0;
  param_1[0xca] = 0;
  FUN_00440740();
  param_1[0xcb] = param_5;
  param_1[0xe6] = param_7;
  param_1[0xcc] = param_4;
  if (param_6 == 0) {
    param_1[0xd] = 0;
  }
  else {
    param_1[0xd] = 0x3f800000;
  }
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0xe1] = 0;
  param_1[0xe3] = 0;
  param_1[0xe2] = 0;
  puVar3 = param_1 + 0xcd;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  bVar4 = DAT_00735f5c == 0;
  param_1[0xe4] = 0;
  param_1[0xe5] = 0x3f800000;
  param_1[0x19] = *(undefined4 *)(param_2 + 0x3d0);
  if (bVar4) {
    *(undefined4 *)(param_1[7] + 0x280) = 0;
    *(undefined4 *)(param_1[7] + 0x284) = 0;
  }
  param_1[0xc] = param_3;
  param_1[0xe7] = 0;
  param_1[0x1a] = 0x3f800000;
  return param_1;
}


// ==== 0x489490 FUN_00489490

void * __thiscall FUN_00489490(void *param_1,byte param_2)

{
  FUN_004894b0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4894b0 FUN_004894b0

void __fastcall FUN_004894b0(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  bool bVar4;
  
  bVar4 = DAT_00735f5c == 0;
  *param_1 = &PTR_FUN_006c7fc8;
  if (bVar4) {
    *(undefined4 *)(param_1[7] + 0x280) = 0;
    *(undefined4 *)(param_1[7] + 0xb4) = 0;
    *(undefined4 *)(param_1[7] + 0xb8) = 0;
  }
  iVar3 = param_1[0xc3];
  if (0 < iVar3) {
    piVar2 = param_1 + 0x23;
    do {
      iVar1 = *piVar2;
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + -1;
      *(char *)(iVar1 + 8) = *(char *)(iVar1 + 8) + -1;
    } while (iVar3 != 0);
  }
  *param_1 = &PTR_CameraMover__TrivialDtor_006c7c50;
  if (param_1[5] == 0) {
    return;
  }
  param_1[5] = 0;
  param_1[9] = *(undefined4 *)(param_1[7] + 0x280);
  param_1[10] = *(undefined4 *)(param_1[7] + 0x284);
  iVar3 = param_1[1];
  piVar2 = (int *)param_1[2];
  *piVar2 = iVar3;
  *(int **)(iVar3 + 4) = piVar2;
  ViewList_UpdateViewCountKind();
  return;
}


// ==== 0x489540 FUN_00489540

void __fastcall FUN_00489540(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined2 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(uint *)(param_1 + 0x48) = (uint)*(ushort *)(*(int *)(param_1 + 0x2c) + 0x3b4);
  *(undefined4 *)(param_1 + 0x4c) = 0;
  uVar2 = FUN_00564cd0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x98));
  *(uint *)(param_1 + 0x54) = uVar2 & 0xffff;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 900) = 0;
  *(undefined4 *)(param_1 + 0x38c) = 0;
  *(undefined4 *)(param_1 + 0x388) = 0;
  puVar4 = (undefined4 *)(param_1 + 0x334);
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 *)(param_1 + 0x390) = 0;
  *(undefined4 *)(param_1 + 0x394) = 0x3f800000;
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x3d0);
  *(undefined4 *)(param_1 + 0x68) = 0x3f800000;
  *(undefined4 *)(param_1 + 100) = uVar1;
  return;
}


// ==== 0x4895d0 FUN_004895d0

undefined4 __fastcall FUN_004895d0(int param_1)

{
  if (((*(int *)(param_1 + 0x20) != 0) && (*(char *)(*(int *)(param_1 + 0x20) + 0x29) == '\0')) &&
     (0.0 < *(float *)(param_1 + 0x38))) {
    return 1;
  }
  return 0;
}


// ==== 0x489600 DriveCameraMover::OutsidePOV

/* [canon] camera I (C) docs/re/camera.md */

undefined4 __fastcall DriveCameraMover__OutsidePOV(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    bVar2 = false;
  }
  else {
    bVar2 = *(char *)(*(int *)(param_1 + 0x20) + 0x29) == '\0';
  }
  iVar1 = *(int *)(param_1 + 0x30);
  if ((((iVar1 != 1) && (iVar1 != 0)) && (iVar1 != 4)) &&
     ((!bVar2 || (*(float *)(param_1 + 0x38) <= 0.0)))) {
    return 0;
  }
  return 1;
}


// ==== 0x489650 DriveCameraMover::IsWallFlag

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera I (C) docs/re/camera.md */

float10 __fastcall DriveCameraMover__IsWallFlag(int param_1)

{
  float10 fVar1;
  
  if ((*(int *)(param_1 + 0x20) == 0) || (*(char *)(*(int *)(param_1 + 0x20) + 0x29) != '\0')) {
    fVar1 = (float10)0.0;
  }
  else {
    fVar1 = (float10)*(float *)(param_1 + 0x38);
  }
  return (float10)3.0 * fVar1 + ((float10)_K_ONE - fVar1) * (float10)(float)0x3f333333;
}


// ==== 0x489690 DriveCameraMover::Update

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera V (G+H+C) docs/re/camera.md */

void __fastcall DriveCameraMover__Update(int *param_1)

{
  float fVar1;
  float fVar2;
  char cVar3;
  short sVar4;
  undefined2 uVar5;
  ushort uVar6;
  float fVar7;
  int *piVar8;
  uint uVar9;
  undefined4 *puVar10;
  int iVar11;
  float *pfVar12;
  undefined4 unaff_EBX;
  int iVar13;
  short *psVar14;
  float fVar15;
  int iVar16;
  uint uVar17;
  float10 extraout_ST0;
  float10 fVar18;
  float10 fVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  short *psVar22;
  char cVar23;
  float fVar24;
  short *psStack_300;
  float fStack_2f8;
  undefined4 uStack_2f4;
  float fStack_2f0;
  short *local_2ec;
  float fStack_2e8;
  float fStack_2e4;
  short *psStack_2e0;
  float fStack_2dc;
  float fStack_2d8;
  float fStack_2d4;
  float fStack_2d0;
  int local_2cc;
  uint uStack_2c4;
  undefined4 uStack_2c0;
  undefined4 uStack_2bc;
  undefined4 uStack_2b8;
  float fStack_2b0;
  float fStack_2ac;
  undefined4 uStack_2a8;
  float fStack_2a4;
  float fStack_2a0;
  float fStack_29c;
  float fStack_298;
  float fStack_294;
  float fStack_290;
  float fStack_28c;
  float fStack_288;
  float fStack_284;
  undefined4 uStack_280;
  undefined4 uStack_27c;
  undefined4 uStack_278;
  undefined4 uStack_274;
  short *psStack_270;
  float fStack_26c;
  float fStack_268;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  undefined4 uStack_254;
  undefined4 uStack_250;
  undefined4 uStack_24c;
  undefined4 uStack_248;
  undefined4 uStack_244;
  undefined4 uStack_240;
  undefined4 uStack_23c;
  undefined4 uStack_238;
  undefined4 uStack_234;
  undefined4 uStack_230;
  undefined4 uStack_22c;
  float fStack_228;
  undefined4 uStack_224;
  float fStack_220;
  float fStack_214;
  undefined1 auStack_208 [8];
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 uStack_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  undefined4 uStack_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  float fStack_1c4;
  float fStack_1c0;
  float afStack_1bc [3];
  undefined1 auStack_1b0 [12];
  float afStack_1a4 [13];
  undefined1 auStack_170 [76];
  float fStack_124;
  float fStack_120;
  undefined1 auStack_f0 [48];
  undefined1 auStack_c0 [8];
  float fStack_b8;
  undefined1 auStack_b0 [12];
  undefined1 auStack_a4 [76];
  undefined1 auStack_58 [8];
  undefined1 local_50 [76];
  
  if (param_1[8] == 0) {
    uStack_2f4 = (float)(uint)(uint3)uStack_2f4;
  }
  else {
    uStack_2f4 = (float)CONCAT13(*(char *)(param_1[8] + 0x29) == '\0',(uint3)uStack_2f4);
  }
  if (DAT_006fbf14 == 0) {
    iVar16 = *(int *)(DAT_007361f8 + 0x18);
    iVar11 = 0;
    if (0 < iVar16) {
      puVar10 = (undefined4 *)(DAT_007361f8 + 0x28);
      do {
        local_2ec = (short *)*puVar10;
        if (local_2ec[5] == DAT_006fbf18) goto joined_r0x004896fe;
        iVar11 = iVar11 + 1;
        puVar10 = puVar10 + 1;
      } while (iVar11 < iVar16);
    }
    local_2ec = (short *)0x0;
joined_r0x004896fe:
    if (local_2ec == (short *)0x0) {
      if (DAT_006fbf18 < 0) {
        local_2ec = (short *)param_1[0xb];
        goto LAB_00489752;
      }
      DAT_006fbf18 = DAT_006fbf18 + -1;
      iVar11 = 0;
      if (0 < iVar16) {
        puVar10 = (undefined4 *)(DAT_007361f8 + 0x28);
        do {
          local_2ec = (short *)*puVar10;
          if (local_2ec[5] == DAT_006fbf18) goto joined_r0x004896fe;
          iVar11 = iVar11 + 1;
          puVar10 = puVar10 + 1;
        } while (iVar11 < iVar16);
      }
      local_2ec = (short *)0x0;
      goto joined_r0x004896fe;
    }
  }
  else {
    local_2ec = (short *)param_1[0xb];
  }
LAB_00489752:
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  if ((float)param_1[0xd] <= (float)param_1[0xe]) {
    if (((float)param_1[0xd] < (float)param_1[0xe]) &&
       (fVar24 = (float)param_1[0xe] - (float)param_1[0xcc] * DAT_0073457c,
       param_1[0xe] = (int)fVar24, fVar24 < (float)param_1[0xd])) {
      param_1[0xe] = param_1[0xd];
    }
  }
  else {
    fVar24 = (float)param_1[0xcc] * DAT_0073457c + (float)param_1[0xe];
    param_1[0xe] = (int)fVar24;
    if ((float)param_1[0xd] < fVar24) {
      param_1[0xe] = param_1[0xd];
    }
  }
  local_2cc = FindCameraRow();
  if (local_2cc == 0) {
    (**(code **)(*param_1 + 0x20))(0);
    local_2cc = FindCameraRow();
  }
  psVar14 = local_2ec;
  local_1fc = *(undefined4 *)(local_2ec + 0x42);
  local_200 = *(undefined4 *)(local_2ec + 0x40);
  local_1f8 = *(undefined4 *)(local_2ec + 0x44);
  psVar22 = local_2ec + 0x48;
  _DriveCam_Scale = 1.0;
  D3DXMatrixTranspose(local_50);
  puVar21 = auStack_58;
  puVar20 = auStack_208;
  D3DXVec3Transform(puVar20,auStack_208,puVar21);
  fVar24 = _DriveCam_K_0_045 * _DriveCam_Scale * fStack_214;
  fVar15 = _DriveCam_NegThreshold * _DriveCam_Scale;
  if (fVar15 <= fVar24) {
    fVar24 = _DriveCam_PitchLimitLo * _DriveCam_Scale * fStack_214;
    if (fVar24 <= _DriveCam_PitchLimitHi * _DriveCam_Scale) {
      iVar16 = 0;
      fVar24 = 0.0;
    }
    else {
      iVar16 = 1;
    }
  }
  else {
    iVar16 = -1;
  }
  fVar7 = (float)_ftol_nocw();
  cVar23 = (char)((uint)psVar22 >> 0x18);
  param_1[0xe4] = (int)(float)(extraout_ST0 - (float10)(int)fVar7);
  uStack_2f4 = fVar7;
  if (0 < (int)fVar7) {
    do {
      piVar8 = param_1 + 0xe0;
      iVar11 = 0x13;
      do {
        *piVar8 = piVar8[-1];
        piVar8 = piVar8 + -1;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      param_1[0xcd] = (int)fVar24;
      fVar2 = fVar24;
      if (iVar16 == -1) {
        if (0.0 <= (float)param_1[0xe1]) {
          iVar11 = -1;
          pfVar12 = (float *)(param_1 + 0xce);
          iVar13 = 9;
          do {
            fVar2 = fVar2 + *pfVar12;
            if (fVar15 < *pfVar12) {
              iVar11 = 0;
            }
            pfVar12 = pfVar12 + 1;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
          if (iVar11 != 0) {
            pfVar12 = (float *)(param_1 + 0xd7);
            iVar13 = 10;
            do {
              if (*pfVar12 < fVar15) {
                iVar11 = 0;
              }
              pfVar12 = pfVar12 + 1;
              iVar13 = iVar13 + -1;
            } while (iVar13 != 0);
LAB_00489ad5:
            if (iVar11 != 0) {
              param_1[0xe2] = (int)(fVar2 * 0.1);
              if (1.0 <= *(float *)(psStack_300 + 0x1e8)) {
                sVar4 = Atan2ToAngle16(*(undefined4 *)(psStack_300 + 0x38),
                                       *(undefined4 *)(psStack_300 + 0x3a));
                uStack_2f4 = (float)(uint)(ushort)(psStack_300[0x1da] - sVar4);
                fStack_2e4 = (float)(int)uStack_2f4 * 9.58738e-05;
                if (3.14159 < fStack_2e4) {
                  fStack_2e4 = fStack_2e4 - 6.28318;
                }
                fVar2 = fStack_2e4;
                if (fStack_2e4 < 0.0) {
                  fVar2 = -fStack_2e4;
                }
              }
              else {
                fVar2 = 0.0;
              }
              fVar2 = _K_ONE - fVar2 * _DriveCam_K_6;
              if (fVar2 < 0.0) {
                fVar2 = 0.0;
              }
              fVar1 = (float)param_1[0xe2];
              param_1[0xe2] = (int)(fVar2 * fVar1);
              fStack_2e8 = _DriveCam_K_6b * _DriveCam_Scale;
              if (fStack_2e8 < fVar2 * fVar1) {
                param_1[0xe2] = (int)fStack_2e8;
              }
              if ((float)param_1[0xe2] < _DriveCam_K_m1 * _DriveCam_Scale) {
                param_1[0xe2] = (int)(_DriveCam_K_m1 * _DriveCam_Scale);
              }
              param_1[0xe3] = 0;
              if ((param_1[0xcb] == 0) || (*(float *)(psStack_300 + 0x1e8) <= 5.0)) {
                param_1[0xe5] = 0x3f800000;
              }
              else {
                if (*(int *)(psStack_300 + 0x200) == 1) {
                  param_1[0xe2] = (int)((float)param_1[0xe2] * 0.75);
                }
                fVar2 = DAT_006fbf08 * (float)param_1[0xe2];
                param_1[0xe5] = (int)DAT_006fbf08;
                param_1[0xe2] = (int)fVar2;
              }
            }
          }
        }
      }
      else if (iVar16 == 0) {
        pfVar12 = (float *)(param_1 + 0xce);
        fVar2 = _DriveCam_PitchLimitHi * _DriveCam_Scale;
        iVar11 = 9;
        do {
          if ((*pfVar12 < fVar2) && (fVar15 < *pfVar12)) {
            param_1[0xe2] = 0;
          }
          pfVar12 = pfVar12 + 1;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
      }
      else if ((iVar16 == 1) && ((float)param_1[0xe1] <= 0.0)) {
        pfVar12 = (float *)(param_1 + 0xce);
        fStack_2e8 = _DriveCam_PitchLimitHi * _DriveCam_Scale;
        iVar13 = 9;
        iVar11 = 1;
        do {
          fVar2 = fVar2 + *pfVar12;
          if (*pfVar12 < fStack_2e8) {
            iVar11 = 0;
          }
          pfVar12 = pfVar12 + 1;
          iVar13 = iVar13 + -1;
        } while (iVar13 != 0);
        if (iVar11 != 0) {
          pfVar12 = (float *)(param_1 + 0xd7);
          iVar13 = 10;
          do {
            if (fStack_2e8 < *pfVar12) {
              iVar11 = 0;
            }
            pfVar12 = pfVar12 + 1;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
          goto LAB_00489ad5;
        }
      }
      cVar23 = (char)((uint)psVar22 >> 0x18);
      fVar7 = (float)((int)fVar7 - 1);
      psVar14 = psStack_300;
    } while (fVar7 != 0.0);
  }
  fVar24 = DAT_0073457c * 60.0;
  if ((float)param_1[0xe2] == 0.0) {
    fVar24 = _DriveCam_K_0_012 * (float)param_1[0xe5] * fVar24;
    if ((float)param_1[0xe1] <= _DriveCam_K_3) {
      if ((float)param_1[0xe1] <= 0.0) {
        if (0.0 <= (float)param_1[0xe1]) goto LAB_00489dcd;
        if ((float)param_1[0xe1] < -fVar24) goto LAB_00489dc1;
      }
      else if (fVar24 < (float)param_1[0xe1]) {
        fVar24 = (float)param_1[0xe1] - fVar24;
        goto LAB_00489dc7;
      }
      param_1[0xe1] = 0;
      goto LAB_00489dcd;
    }
    fVar24 = (float)param_1[0xe1] - (fVar24 + fVar24);
LAB_00489dc7:
    param_1[0xe1] = (int)fVar24;
  }
  else if ((float)param_1[0xe2] <= 0.0) {
    if (5.0 <= *(float *)(psVar14 + 0x1e8) * 2.237) {
      if ((float)param_1[0xe1] < (float)param_1[0xe2]) goto LAB_00489cf1;
      fVar24 = -(_DriveCam_K_0_03 * (float)param_1[0xe5]) * fVar24;
      goto LAB_00489dc1;
    }
    param_1[0xe2] = 0;
  }
  else {
    fVar15 = (float)param_1[0xe1] - (float)param_1[0xe2];
    if (fVar15 <= 0.0) {
      if (fVar15 <= -0.4) {
        fVar24 = _DriveCam_K_0_03 * (float)param_1[0xe5] * fVar24;
        if (-1.0 < fVar15) {
          fVar24 = fVar24 * 0.6;
        }
      }
      else {
        fVar24 = _DriveCam_K_0_03 * (float)param_1[0xe5] * fVar24 * 0.3;
      }
LAB_00489dc1:
      fVar24 = fVar24 + (float)param_1[0xe1];
      goto LAB_00489dc7;
    }
LAB_00489cf1:
    fVar24 = DAT_0073457c + (float)param_1[0xe3];
    param_1[0xe3] = (int)fVar24;
    if ((_DriveCam_K_2 < fVar24) || (iVar16 == 0)) {
      param_1[0xe2] = 0;
    }
  }
LAB_00489dcd:
  fVar24 = _DriveCam_K_500 - *(float *)(psVar14 + 0x1e8) * 2.237;
  if (fVar24 < 0.0) {
    fVar24 = 0.0;
  }
  if (param_1[0xcb] == 0) {
    fVar24 = (fVar24 / _DriveCam_K_500) * (float)param_1[0xe1] * _DriveCam_K_1a;
  }
  else {
    fVar24 = 0.0;
  }
  _ftol_nocw();
  FUN_00564b10();
  if (DAT_00735ee8 == 0) {
    sVar4 = *psStack_2e0;
    psVar22 = *(short **)(psStack_2e0 + 4);
    fStack_2e4 = *(float *)(psStack_2e0 + 6);
    fStack_2e8 = (float)CONCAT22(fStack_2e8._2_2_,psStack_2e0[1]);
    uStack_2b8 = 10000;
  }
  else {
    sVar4 = *psStack_2e0;
    fStack_2e8 = DAT_00735ef0;
    uStack_2b8 = DAT_006fbdf0;
    fStack_2e4 = (float)DAT_00735eec;
    psVar22 = DAT_006fbdec;
  }
  if ((((sVar4 == 1) || (sVar4 == 0)) || (sVar4 == 4)) && (fVar24 < 0.0)) {
    psVar22 = (short *)(fVar24 * _DriveCam_K_0_2 + (float)psVar22);
  }
  uStack_1f4 = 0x3f800000;
  uStack_1f0 = 0;
  uStack_1ec = 0;
  uStack_1e8 = 0;
  uStack_1e4 = 0;
  uStack_1e0 = 0x3f800000;
  uStack_1dc = 0;
  uStack_1d8 = 0;
  uStack_1d4 = 0;
  uStack_1d0 = 0;
  uStack_1cc = 0x3f800000;
  uStack_1c8 = 0;
  afStack_1bc[1] = 1.0;
  fStack_1c4 = -*(float *)(psStack_300 + 0x28);
  fStack_1c0 = -*(float *)(psStack_300 + 0x2a);
  afStack_1bc[0] = -*(float *)(psStack_300 + 0x2c);
  uVar5 = _ftol_nocw();
  *(undefined2 *)(param_1 + 0x11) = uVar5;
  uVar6 = 0;
  bMatrixCopy_b();
  sVar4 = *psStack_2e0;
  if (((sVar4 == 1) || (sVar4 == 0)) || (sVar4 == 4)) {
    fStack_2f0 = *(float *)(psStack_300 + 0x3a);
    uStack_2f4 = *(float *)(psStack_300 + 0x38);
    fVar24 = uStack_2f4 * fStack_124 + fStack_120 * fStack_2f0;
    if (fVar24 < 0.0) {
      fVar24 = fVar24 * -2.0;
      fStack_2d8 = fVar24 * fStack_120;
      uStack_2f4 = fStack_124 * fVar24 + uStack_2f4;
      fStack_2f0 = fStack_2d8 + fStack_2f0;
    }
    fVar24 = SQRT(uStack_2f4 * uStack_2f4 + fStack_2f0 * fStack_2f0);
    fVar18 = (float10)LinearTable__Lookup11(&PTR_DAT_00705b20,fVar24);
    fStack_2f8 = (float)fVar18;
    if (fVar24 / fStack_2f8 == 0.0) {
      fStack_2d8 = 0.0;
      fStack_2dc = _K_ONE;
    }
    else {
      fVar24 = _K_ONE / (fVar24 / fStack_2f8);
      fStack_2d8 = fVar24 * fStack_2f0;
      fStack_2dc = uStack_2f4 * fVar24;
    }
    fStack_2f0 = (_K_ONE - fStack_2f8) * fStack_120;
    fStack_2dc = fStack_124 * (_K_ONE - fStack_2f8) + fStack_2dc;
    fStack_2d8 = fStack_2f0 + fStack_2d8;
    uVar6 = Atan2ToAngle16(fStack_2dc,fStack_2d8);
    fVar18 = (float10)FUN_00564b10();
    fStack_2f8 = (float)fVar18;
    fVar18 = (float10)FUN_00564b10();
    fStack_2a0 = (float)fVar18;
    fStack_294 = (float)-fVar18;
    pfVar12 = &fStack_2a4;
    fStack_2a4 = fStack_2f8;
    fStack_290 = fStack_2f8;
    fStack_29c = 0.0;
    fStack_298 = 0.0;
    fStack_28c = 0.0;
    fStack_288 = 0.0;
    fStack_284 = 0.0;
    uStack_280 = 0;
    uStack_27c = 0x3f800000;
    uStack_278 = 0;
    uStack_274 = 0;
    psStack_270 = (short *)0x0;
    fStack_26c = 0.0;
    fStack_268 = 1.0;
  }
  else {
    D3DXMatrixTranspose(afStack_1a4,&fStack_124);
    if ((char)((uint)unaff_EBX >> 0x18) == '\0') {
      FUN_0040b930();
      D3DXMatrixMultiply(afStack_1a4,afStack_1a4,&fStack_2a4);
    }
    pfVar12 = afStack_1a4;
  }
  D3DXMatrixMultiply(auStack_a4,&uStack_1f4,pfVar12);
  uStack_260 = 0x3f800000;
  uStack_25c = 0;
  uStack_258 = 0;
  uStack_254 = 0;
  uStack_250 = 0;
  uStack_24c = 0x3f800000;
  uStack_248 = 0;
  uStack_244 = 0;
  uStack_240 = 0;
  uStack_23c = 0;
  uStack_238 = 0x3f800000;
  uStack_234 = 0;
  uStack_230 = 0;
  uStack_22c = 0;
  fStack_228 = 0.0;
  uStack_224 = 0x3f800000;
  cVar3 = (**(code **)(*param_1 + 0x24))();
  fVar15 = _K_ONE;
  sVar4 = *local_2ec;
  if (((sVar4 == 1) || (sVar4 == 0)) || (sVar4 == 4)) {
    fStack_2f8 = (float)(uint)uVar6;
    iVar16 = param_1[0x12];
    fVar7 = (float)(int)((uint)(2 < *(int *)((int)fVar24 + 0x3cc)) * 2 + -1);
    fVar2 = _CamAirborneRampStep * fVar7 + (float)param_1[0x1a];
    param_1[0x1a] = (int)fVar2;
    if (fVar2 <= fVar15) {
      if (fVar2 < 0.0) {
        param_1[0x1a] = 0;
      }
    }
    else {
      param_1[0x1a] = 0x3f800000;
    }
    DriveCameraMover__GetCorrectionYaw();
    iVar13 = _ftol_nocw();
    iVar11 = param_1[0x13];
    fVar18 = (float10)FUN_00564b10();
    fVar19 = (float10)FUN_00564b10();
    fStack_2ac = (float)fVar19;
    fStack_2a0 = (float)-fVar19;
    uStack_2a8 = 0;
    fStack_2a4 = 0.0;
    fStack_298 = 0.0;
    fStack_294 = 0.0;
    fStack_290 = 0.0;
    fStack_28c = 0.0;
    fStack_288 = 1.0;
    fStack_284 = 0.0;
    uStack_280 = 0;
    uStack_27c = 0;
    uStack_278 = 0;
    uStack_274 = 0x3f800000;
    fStack_2b0 = (float)fVar18;
    fStack_29c = (float)fVar18;
    D3DXMatrixMultiply(&uStack_260,&uStack_260,&fStack_2b0);
    param_1[0x12] = (int)fStack_2f8;
    param_1[0x13] = (uint)(ushort)((short)iVar11 + (uVar6 - (short)iVar16)) + iVar13 & 0xffff;
    uVar6 = FUN_00564cd0(*(undefined4 *)((int)fVar24 + 0x98));
    fVar15 = (float)(uint)uVar6;
    if ((short)param_1[0x11] == 0) {
      uVar6 = *(ushort *)(param_1 + 0x16);
    }
    else {
      uVar6 = *(ushort *)(param_1 + 0x16);
    }
    fStack_2f8 = fVar15;
    if (fVar7 == 0.0) {
      iVar16 = 0;
    }
    else {
      iVar16 = _ftol_nocw();
    }
    FUN_00441d80(8);
    uVar17 = (uint)uVar6 + iVar16 & 0xffff;
    _ftol_nocw();
    FUN_0040ba40(&uStack_260,&uStack_260);
    if (cVar23 == '\0') {
      FUN_0040b930();
      D3DXMatrixMultiply(&uStack_260,&uStack_260,auStack_1b0);
      fVar15 = fStack_2f8;
    }
    param_1[0x15] = (int)fVar15;
  }
  else {
    uVar17 = 0;
    param_1[0x12] = (uint)(ushort)psStack_300[0x1da];
    param_1[0x13] = 0;
    uVar9 = FUN_00564cd0(*(undefined4 *)(psStack_300 + 0x4c));
    param_1[0x15] = uVar9 & 0xffff;
  }
  param_1[0x16] = uVar17;
  if ((cVar23 != '\0') && (0.0 < (float)param_1[0xe])) {
    fVar15 = _CamBlend_Height_A;
    if (DAT_007364a0 == 3) {
      fVar15 = _CamBlend_Height_B;
    }
    puVar21 = (undefined1 *)
              ((_K_ONE - (float)param_1[0xe]) * (float)puVar21 + fVar15 * (float)param_1[0xe]);
    fVar15 = _CamBlend_Dist_A;
    if (DAT_007364a0 == 3) {
      fVar15 = _CamBlend_Dist_B;
    }
    fStack_2f8 = (float)((uint)uStack_2f4 & 0xffff);
    psVar22 = (short *)((_K_ONE - (float)param_1[0xe]) * (float)psVar22 +
                       fVar15 * (float)param_1[0xe]);
    _ftol_nocw();
    FUN_0040ba40(&uStack_260,&uStack_260);
  }
  fStack_2e8 = 0.0;
  fStack_2e4 = 0.0;
  uStack_2c0 = 0;
  uStack_2bc = 0;
  uStack_2b8 = 0;
  fVar15 = fStack_2f0;
  if (cVar3 != '\0') {
    fStack_2d8 = -(float)puVar21;
    fStack_2dc = fStack_2f0;
    psStack_2e0 = psVar22;
    eTranslate(auStack_1b0,&uStack_260);
    D3DXMatrixMultiply(auStack_1b0,auStack_b0,auStack_1b0);
    Matrix_InvertRigid();
    pfVar12 = (float *)(psVar22 + 0x30);
    local_2ec = (short *)((fStack_28c + *(float *)(psVar22 + 0x30)) * 0.5);
    fStack_2e8 = (*(float *)(psVar22 + 0x32) + fStack_288) * 0.5;
    fStack_2e4 = (*(float *)(psVar22 + 0x34) + fStack_284) * 0.5;
    psVar14 = psVar22;
    GroundQuery__RefillCache
              (&local_2ec,
               SQRT((*pfVar12 - fStack_28c) * (*pfVar12 - fStack_28c) +
                    (*(float *)(psVar22 + 0x32) - fStack_288) *
                    (*(float *)(psVar22 + 0x32) - fStack_288) +
                    (*(float *)(psVar22 + 0x34) - fStack_284) *
                    (*(float *)(psVar22 + 0x34) - fStack_284)) * 0.5 + _K_ONE,psVar22 + 0x38);
    D3DXVec3Transform(&uStack_1cc,pfVar12,afStack_1bc);
    fStack_2f8 = 0.0;
    uStack_2f4 = 0.0;
    fStack_2f0 = 0.0;
    local_2ec = (short *)0x0;
    CameraMover__EnforceMinGapToWalls(param_1,param_1 + 0x1b,pfVar12,&fStack_298,&fStack_2f8);
    fStack_2d8 = fStack_298 + fStack_2f8;
    fStack_2d4 = fStack_294 + uStack_2f4;
    fStack_2d0 = fStack_290 + fStack_2f0;
    fStack_220 = *(float *)(psVar22 + 0x34) - fStack_2d0;
    fVar7 = (*(float *)(psVar22 + 0x32) - fStack_2d4) * (*(float *)(psVar22 + 0x32) - fStack_2d4);
    fVar15 = (*pfVar12 - fStack_2d8) * (*pfVar12 - fStack_2d8);
    fStack_228 = *(float *)(*(int *)(puVar20 + 0x3c) + 0x100);
    fVar2 = ABS(*(float *)(*(int *)(puVar20 + 0x3c) + 0xf0));
    if (fVar2 < fStack_228) {
      fVar2 = fStack_228;
    }
    fVar2 = fVar2 + 0.7;
    if (SQRT(fStack_220 * fStack_220 + fVar15 + fVar7) < fVar2) {
      fVar15 = SQRT(fVar2 * fVar2 - (fVar15 + fVar7)) - (fStack_2d0 - *(float *)(puVar20 + 0x68));
      fStack_2f0 = fStack_2f0 + fVar15;
      fStack_2d0 = fStack_2d0 + fVar15;
    }
    thunk_FUN_005ac436(&fStack_288,&fStack_2f8,&uStack_1c8);
    puVar21 = (undefined1 *)(fStack_268 + fVar7);
    psVar22 = (short *)((float)psVar14 - (float)psStack_270);
    fVar15 = fStack_2f0 - fStack_26c;
  }
  fStack_268 = -(float)puVar21;
  psStack_270 = psVar22;
  fStack_26c = fVar15;
  eTranslate(&uStack_260,&uStack_260);
  uStack_2c4 = (uStack_2c4 & 0xffff) - ((uint)uStack_2f4 & 0xffff);
  _ftol_nocw();
  FUN_0040ba40(&uStack_260,&uStack_260);
  if (cVar3 == '\0') {
    D3DXMatrixMultiply(auStack_f0,auStack_b0,&uStack_260);
    Matrix_InvertRigid();
    fVar18 = (float10)GroundQuery__FindSurfaceBelow(param_1 + 0x1b,auStack_c0,0,0,0);
    if (fVar18 + (float10)_CamWallPushOut <= (float10)fStack_b8) {
      D3DXMatrixMultiply(auStack_170,auStack_b0,&uStack_260);
    }
    else {
      fStack_b8 = (float)(fVar18 + (float10)_CamWallPushOut);
      Matrix_InvertRigid();
    }
    FUN_0040b990(auStack_170,auStack_170);
    FUN_0040ba40(auStack_170,auStack_170);
  }
  else {
    FUN_00483ad0(param_1,auStack_170,(int)fVar24 + 0x60,&fStack_2e8);
  }
  iVar16 = DAT_00735f5c;
  if (DAT_00735f5c == 0) {
    *(undefined4 *)(param_1[7] + 0x284) = 0;
  }
  if (cVar3 == '\0') {
    if (iVar16 == 0) {
      *(float *)(param_1[7] + 0x280) = fVar24;
    }
    if ((*local_2ec == 3) && (param_1[0xd] != 0x3f800000)) {
      if (iVar16 != 0) goto LAB_0048acb3;
      *(undefined4 *)(param_1[7] + 0x284) = 1;
    }
    else if (iVar16 != 0) goto LAB_0048acb3;
  }
  else {
    if (iVar16 != 0) goto LAB_0048acb3;
    *(undefined4 *)(param_1[7] + 0x280) = 0;
  }
  *(undefined2 *)(param_1[7] + 0xc4) = *(undefined2 *)(CameraFOVTable + *local_2ec * 2);
LAB_0048acb3:
  if (*local_2ec == 3) {
    *(undefined4 *)(param_1[7] + 0xbc) = DAT_006fbf1c;
  }
  else {
    *(undefined4 *)(param_1[7] + 0xbc) = 0x3f000000;
  }
  ApplyCameraShake(param_1[4]);
  iVar11 = DAT_00735f5c;
  iVar16 = param_1[7];
  fVar15 = *(float *)(iVar16 + 0x40) - *(float *)((int)fVar24 + 0x60);
  fVar7 = *(float *)(iVar16 + 0x44) - *(float *)((int)fVar24 + 100);
  fVar24 = *(float *)(iVar16 + 0x48) - *(float *)((int)fVar24 + 0x68);
  if (DAT_00735f5c == 0) {
    *(float *)(iVar16 + 0xb0) = SQRT(fVar15 * fVar15 + fVar7 * fVar7 + fVar24 * fVar24);
  }
  if ((param_1[0xe6] == 0) && (iVar11 == 0)) {
    *(undefined4 *)(param_1[7] + 0xb4) = 0x41700000;
    *(undefined4 *)(param_1[7] + 0xb8) = 0x42820000;
  }
  Camera__SetCameraMatrix(param_1[7],auStack_170,DAT_0073ad38);
  if (cVar23 != '\0') {
    *(undefined2 *)(param_1 + 0x11) = 0;
  }
  return;
}


// ==== 0x48ad90 FUN_0048ad90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0048ad90(float *param_1,float *param_2,undefined4 param_3,float param_4)

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
  float *in_EAX;
  
  fVar23 = _K_ONE - param_4;
  fVar1 = in_EAX[1];
  fVar2 = param_1[1];
  fVar3 = in_EAX[2];
  fVar4 = param_1[2];
  fVar5 = *param_1;
  fVar6 = *in_EAX;
  param_2[3] = param_4 * param_1[3] + fVar23 * in_EAX[3];
  *param_2 = fVar23 * fVar6 + param_4 * fVar5;
  param_2[1] = param_4 * fVar2 + fVar23 * fVar1;
  param_2[2] = param_4 * fVar4 + fVar23 * fVar3;
  fVar1 = param_1[5];
  fVar2 = param_1[6];
  fVar3 = param_1[8];
  fVar4 = param_1[9];
  fVar5 = param_1[10];
  fVar6 = param_1[0xc];
  fVar7 = param_1[0xd];
  fVar8 = param_1[0xe];
  fVar9 = param_1[0x10];
  fVar10 = param_1[0x11];
  fVar11 = param_1[0x12];
  fVar12 = param_1[0x14];
  fVar13 = param_1[0x15];
  fVar14 = param_1[0x16];
  fVar15 = param_1[0x18];
  fVar16 = param_1[0x19];
  fVar17 = param_1[0x1a];
  fVar18 = param_1[0x1c];
  fVar19 = param_1[0x1d];
  fVar20 = param_1[0x1e];
  fVar21 = in_EAX[5];
  fVar22 = in_EAX[6];
  param_2[4] = fVar23 * in_EAX[4] + param_4 * param_1[4];
  param_2[5] = fVar23 * fVar21 + fVar1 * param_4;
  param_2[6] = fVar23 * fVar22 + fVar2 * param_4;
  fVar1 = in_EAX[9];
  fVar2 = in_EAX[10];
  param_2[8] = fVar23 * in_EAX[8] + param_4 * fVar3;
  param_2[9] = fVar23 * fVar1 + fVar4 * param_4;
  param_2[10] = fVar23 * fVar2 + fVar5 * param_4;
  fVar1 = in_EAX[0xd];
  fVar2 = in_EAX[0xe];
  param_2[0xc] = fVar23 * in_EAX[0xc] + param_4 * fVar6;
  param_2[0xd] = fVar23 * fVar1 + fVar7 * param_4;
  param_2[0xe] = fVar23 * fVar2 + fVar8 * param_4;
  fVar1 = in_EAX[0x11];
  fVar2 = in_EAX[0x12];
  param_2[0x10] = fVar23 * in_EAX[0x10] + param_4 * fVar9;
  param_2[0x11] = fVar23 * fVar1 + fVar10 * param_4;
  param_2[0x12] = fVar23 * fVar2 + fVar11 * param_4;
  fVar1 = in_EAX[0x15];
  fVar2 = in_EAX[0x16];
  param_2[0x14] = fVar23 * in_EAX[0x14] + param_4 * fVar12;
  param_2[0x15] = fVar23 * fVar1 + fVar13 * param_4;
  param_2[0x16] = fVar23 * fVar2 + fVar14 * param_4;
  fVar1 = in_EAX[0x19];
  fVar2 = in_EAX[0x1a];
  param_2[0x18] = fVar23 * in_EAX[0x18] + param_4 * fVar15;
  param_2[0x19] = fVar23 * fVar1 + fVar16 * param_4;
  param_2[0x1a] = fVar23 * fVar2 + fVar17 * param_4;
  fVar1 = in_EAX[0x1d];
  fVar2 = in_EAX[0x1e];
  param_2[0x1c] = fVar23 * in_EAX[0x1c] + param_4 * fVar18;
  param_2[0x1d] = fVar23 * fVar1 + fVar19 * param_4;
  param_2[0x1e] = fVar23 * fVar2 + fVar20 * param_4;
  return;
}


// ==== 0x48afd0 CubicCameraMover::ctor

/* [canon] camera V (G+C) docs/re/camera.md */

undefined4 *
CubicCameraMover__ctor
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,char param_5
          ,undefined1 param_6,undefined1 param_7)

{
  float *pfVar1;
  undefined4 *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 local_f0 [4];
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  float local_70;
  float local_6c;
  float local_60;
  float local_5c;
  float local_50;
  float local_4c;
  float local_40;
  float local_3c;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  undefined1 *puStack_20;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  pcStack_18 = FUN_0068602b;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  CameraMover__ctor();
  *(undefined1 *)((int)param_1 + 0x46) = 0;
  local_14 = 0;
  *(undefined1 *)((int)param_1 + 0x47) = param_7;
  param_1[0xb] = param_3;
  *(bool *)(param_1 + 0x11) = param_5 == '\0';
  param_1[0x10] = param_4;
  *param_1 = &PTR_FUN_006c7e58;
  *(undefined1 *)((int)param_1 + 0x45) = param_6;
  param_1[0x13] = DAT_0073ad34;
  *(undefined1 *)(param_1 + 0x12) = 1;
  FUN_0048ead0(0x3f000000);
  puVar2 = _malloc(0x30);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2[9] = local_e4;
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[10] = 0x41200000;
    *(undefined2 *)(puVar2 + 0xb) = 0;
    *(undefined2 *)((int)puVar2 + 0x2e) = 1;
  }
  param_1[0xc] = puVar2;
  pvVar3 = _malloc(0x90);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = CameraMoverBase_InitFields(local_ec,0x41200000);
  }
  param_1[0xd] = uVar4;
  pvVar3 = _malloc(0x90);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = CameraMoverBase_InitFields(local_e8,0x41200000);
  }
  param_1[0xe] = uVar4;
  pvVar3 = _malloc(0x90);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004830f0(0x41200000);
  }
  param_1[0xf] = uVar4;
  pvVar3 = _malloc(0x30);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_0048eb70();
  }
  param_1[0x14] = uVar4;
  iVar5 = FindCameraRow();
  if (iVar5 == 0) {
    iVar5 = FindCameraRow();
  }
  FUN_0048b8c0(iVar5,local_f0);
  Matrix_InvertRigid();
  if (*(char *)((int)param_1 + 0x45) != '\0') {
    local_70 = -local_70;
    local_6c = -local_6c;
    local_60 = -local_70;
    local_5c = -local_6c;
    local_50 = local_60;
    local_4c = local_5c;
    local_40 = local_60;
    local_3c = local_5c;
  }
  local_2c = param_1[0xd];
  iVar5 = param_1[0xb];
  local_24 = param_1[0xe];
  local_28 = iVar5 + 0x70;
  FUN_00483e30();
  FUN_00483ea0(local_2c,iVar5 + 0x70);
  FUN_00483fb0(local_24,local_28);
  pfVar1 = (float *)param_1[0xd];
  if (20.0 < SQRT((*pfVar1 - pfVar1[2]) * (*pfVar1 - pfVar1[2]) +
                  (pfVar1[0xc] - pfVar1[0xe]) * (pfVar1[0xc] - pfVar1[0xe]) +
                  (pfVar1[0x18] - pfVar1[0x1a]) * (pfVar1[0x18] - pfVar1[0x1a]))) {
    puVar2 = (undefined4 *)param_1[0xc];
    *puVar2 = puVar2[2];
    puVar2[1] = puVar2[3];
    *(undefined2 *)(puVar2 + 0xb) = 0;
    puVar2 = (undefined4 *)param_1[0xd];
    *puVar2 = puVar2[2];
    puVar2[1] = puVar2[3];
    *(undefined2 *)(puVar2 + 0xb) = 0;
    puVar2[0xc] = puVar2[0xe];
    puVar2[0xd] = puVar2[0xf];
    *(undefined2 *)(puVar2 + 0x17) = 0;
    puVar2[0x18] = puVar2[0x1a];
    puVar2[0x19] = puVar2[0x1b];
    *(undefined2 *)(puVar2 + 0x23) = 0;
    puVar2 = (undefined4 *)param_1[0xe];
    *puVar2 = puVar2[2];
    puVar2[1] = puVar2[3];
    *(undefined2 *)(puVar2 + 0xb) = 0;
    puVar2[0xc] = puVar2[0xe];
    puVar2[0xd] = puVar2[0xf];
    *(undefined2 *)(puVar2 + 0x17) = 0;
    puVar2[0x18] = puVar2[0x1a];
    puVar2[0x19] = puVar2[0x1b];
    *(undefined2 *)(puVar2 + 0x23) = 0;
  }
  ExceptionList = local_1c;
  return param_1;
}


// ==== 0x48b2f0 FUN_0048b2f0

void * __thiscall FUN_0048b2f0(void *param_1,byte param_2)

{
  FUN_0048b310();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x48b310 FUN_0048b310

void __fastcall FUN_0048b310(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685b98;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c7e58;
  local_4 = 0;
  _free((void *)param_1[0xc]);
  _free((void *)param_1[0xd]);
  _free((void *)param_1[0xe]);
  _free((void *)param_1[0xf]);
  if ((undefined4 *)param_1[0x14] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x14])(1);
  }
  *param_1 = &PTR_CameraMover__TrivialDtor_006c7c50;
  if (param_1[5] != 0) {
    param_1[5] = 0;
    param_1[9] = *(undefined4 *)(param_1[7] + 0x280);
    param_1[10] = *(undefined4 *)(param_1[7] + 0x284);
    iVar1 = param_1[1];
    piVar2 = (int *)param_1[2];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    ViewList_UpdateViewCountKind();
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x48b3c0 FUN_0048b3c0

undefined4 FUN_0048b3c0(void)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = (short *)FindCameraRow();
  if (psVar2 == (short *)0x0) {
    psVar2 = (short *)FindCameraRow();
  }
  sVar1 = *psVar2;
  if (((sVar1 != 1) && (sVar1 != 0)) && (sVar1 != 4)) {
    return 0;
  }
  return 1;
}


// ==== 0x48b410 FUN_0048b410

void __thiscall FUN_0048b410(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if (((iVar1 == 1) || (iVar1 == 0)) || (iVar1 == 4)) {
    bVar2 = 1;
  }
  else {
    bVar2 = 0;
  }
  if (((param_2 != 1) && (param_2 != 0)) && (param_2 != 4)) {
    *(int *)(param_1 + 0x40) = param_2;
    *(byte *)(param_1 + 0x46) = *(byte *)(param_1 + 0x46) | bVar2;
    return;
  }
  *(int *)(param_1 + 0x40) = param_2;
  *(byte *)(param_1 + 0x46) = *(byte *)(param_1 + 0x46) | bVar2 ^ 1;
  return;
}


// ==== 0x48b460 FUN_0048b460

void __fastcall FUN_0048b460(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 0x30);
  *puVar1 = puVar1[2];
  puVar1[1] = puVar1[3];
  *(undefined2 *)(puVar1 + 0xb) = 0;
  puVar1 = *(undefined4 **)(param_1 + 0x34);
  *puVar1 = puVar1[2];
  puVar1[1] = puVar1[3];
  *(undefined2 *)(puVar1 + 0xb) = 0;
  puVar1[0xc] = puVar1[0xe];
  puVar1[0xd] = puVar1[0xf];
  *(undefined2 *)(puVar1 + 0x17) = 0;
  puVar1[0x18] = puVar1[0x1a];
  puVar1[0x19] = puVar1[0x1b];
  *(undefined2 *)(puVar1 + 0x23) = 0;
  puVar1 = *(undefined4 **)(param_1 + 0x38);
  *puVar1 = puVar1[2];
  puVar1[1] = puVar1[3];
  *(undefined2 *)(puVar1 + 0xb) = 0;
  puVar1[0xc] = puVar1[0xe];
  puVar1[0xd] = puVar1[0xf];
  *(undefined2 *)(puVar1 + 0x17) = 0;
  puVar1[0x18] = puVar1[0x1a];
  puVar1[0x19] = puVar1[0x1b];
  *(undefined2 *)(puVar1 + 0x23) = 0;
  puVar1 = *(undefined4 **)(param_1 + 0x3c);
  *puVar1 = puVar1[2];
  puVar1[1] = puVar1[3];
  *(undefined2 *)(puVar1 + 0xb) = 0;
  puVar1[0xc] = puVar1[0xe];
  puVar1[0xd] = puVar1[0xf];
  *(undefined2 *)(puVar1 + 0x17) = 0;
  puVar1[0x18] = puVar1[0x1a];
  puVar1[0x19] = puVar1[0x1b];
  *(undefined2 *)(puVar1 + 0x23) = 0;
  uVar3 = DAT_006f0888;
  iVar2 = *(int *)(param_1 + 0x1c);
  *(undefined1 *)(iVar2 + 0x270) = 1;
  *(undefined4 *)(iVar2 + 0x27c) = uVar3;
  return;
}


// ==== 0x48b530 FUN_0048b530

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048b530(char param_1)

{
  float fVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  short *in_EAX;
  int *unaff_EDI;
  float10 fVar8;
  float local_20;
  float local_1c;
  float local_18;
  
  sVar2 = *in_EAX;
  if (((sVar2 == 1) || (sVar2 == 0)) || (sVar2 == 4)) {
    if (((param_1 != '\0') || (*(int *)(unaff_EDI[0xb] + 0x38) == 0)) ||
       ((2 < *(int *)(unaff_EDI[0xb] + 0x3cc) ||
        (cVar7 = (**(code **)(*unaff_EDI + 0x24))(), cVar7 == '\0')))) {
      iVar3 = unaff_EDI[0xb];
      local_1c = *(float *)(iVar3 + 0x74);
      local_20 = *(float *)(iVar3 + 0x70);
      local_18 = *(float *)(iVar3 + 0x78);
      fVar1 = local_18 * *(float *)(iVar3 + 0x98) +
              local_1c * *(float *)(iVar3 + 0x94) + local_20 * *(float *)(iVar3 + 0x90);
      if (fVar1 < 0.0) {
        fVar1 = fVar1 * -2.0;
        local_20 = fVar1 * *(float *)(iVar3 + 0x90) + local_20;
        local_1c = fVar1 * *(float *)(iVar3 + 0x94) + local_1c;
        local_18 = fVar1 * *(float *)(iVar3 + 0x98) + local_18;
      }
      fVar8 = (float10)LinearTable__Lookup11(&PTR_DAT_00705b20,*(undefined4 *)(iVar3 + 0x3d4));
      fVar1 = (float)fVar8;
      bNormalize3();
      fVar5 = _K_ONE - fVar1;
      fVar6 = _K_ONE - ((float)(DAT_0073ad34 - unaff_EDI[0x13]) * 0.00025) / 2.0;
      if (fVar6 <= 0.0) {
        fVar6 = 0.0;
      }
      else if (_K_ONE < fVar6) {
        fVar6 = _K_ONE;
      }
      FUN_004831c0(fVar5 * *(float *)(iVar3 + 0x90) + local_20 * fVar1,
                   fVar5 * *(float *)(iVar3 + 0x94) + local_1c * fVar1,
                   fVar6 * (fVar5 * *(float *)(iVar3 + 0x98) + local_18 * fVar1));
      if (param_1 != '\0') {
        puVar4 = (undefined4 *)unaff_EDI[0xf];
        *puVar4 = puVar4[2];
        puVar4[1] = puVar4[3];
        *(undefined2 *)(puVar4 + 0xb) = 0;
        puVar4[0xc] = puVar4[0xe];
        puVar4[0xd] = puVar4[0xf];
        *(undefined2 *)(puVar4 + 0x17) = 0;
        puVar4[0x18] = puVar4[0x1a];
        puVar4[0x19] = puVar4[0x1b];
        *(undefined2 *)(puVar4 + 0x23) = 0;
        return;
      }
    }
  }
  else {
    iVar3 = unaff_EDI[0xb];
    FUN_004831c0(*(undefined4 *)(iVar3 + 0x90),*(undefined4 *)(iVar3 + 0x94),
                 *(undefined4 *)(iVar3 + 0x98));
    puVar4 = (undefined4 *)unaff_EDI[0xf];
    *puVar4 = puVar4[2];
    puVar4[1] = puVar4[3];
    *(undefined2 *)(puVar4 + 0xb) = 0;
    puVar4[0xc] = puVar4[0xe];
    puVar4[0xd] = puVar4[0xf];
    *(undefined2 *)(puVar4 + 0x17) = 0;
    puVar4[0x18] = puVar4[0x1a];
    puVar4[0x19] = puVar4[0x1b];
    *(undefined2 *)(puVar4 + 0x23) = 0;
  }
  return;
}


// ==== 0x48b7a0 FUN_0048b7a0

int FUN_0048b7a0(void)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int *in_EAX;
  int iVar4;
  float *unaff_ESI;
  
  cVar3 = (**(code **)(*in_EAX + 0x24))();
  if (cVar3 != '\0') {
    *unaff_ESI = 1.0;
    unaff_ESI[1] = 0.0;
    unaff_ESI[2] = 0.0;
    unaff_ESI[3] = 0.0;
    unaff_ESI[4] = 0.0;
    unaff_ESI[5] = 1.0;
    unaff_ESI[6] = 0.0;
    unaff_ESI[7] = 0.0;
    unaff_ESI[8] = 0.0;
    unaff_ESI[9] = 0.0;
    unaff_ESI[10] = 1.0;
    unaff_ESI[0xb] = 0.0;
    unaff_ESI[0xc] = 0.0;
    unaff_ESI[0xd] = 0.0;
    unaff_ESI[0xe] = 0.0;
    unaff_ESI[0xf] = 1.0;
    bNormalize3();
    unaff_ESI[4] = unaff_ESI[9] * unaff_ESI[2] - unaff_ESI[1] * unaff_ESI[10];
    unaff_ESI[5] = unaff_ESI[10] * *unaff_ESI - unaff_ESI[8] * unaff_ESI[2];
    unaff_ESI[6] = unaff_ESI[1] * unaff_ESI[8] - unaff_ESI[9] * *unaff_ESI;
    unaff_ESI[8] = unaff_ESI[6] * unaff_ESI[1] - unaff_ESI[2] * unaff_ESI[5];
    unaff_ESI[9] = unaff_ESI[4] * unaff_ESI[2] - unaff_ESI[6] * *unaff_ESI;
    unaff_ESI[10] = *unaff_ESI * unaff_ESI[5] - unaff_ESI[1] * unaff_ESI[4];
    iVar4 = in_EAX[0xb];
    fVar1 = *(float *)(iVar4 + 0x54);
    fVar2 = *(float *)(iVar4 + 0x58);
    unaff_ESI[0xc] = *(float *)(iVar4 + 0x50);
    unaff_ESI[0xd] = fVar1;
    unaff_ESI[0xf] = 1.0;
    unaff_ESI[0xe] = fVar2;
    return iVar4 + 0x50;
  }
  iVar4 = bMatrix4_SetRotationAndTranslation();
  return iVar4;
}


// ==== 0x48b8c0 FUN_0048b8c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0048b8c0(undefined4 param_1,int *param_2,short *param_3,int param_4)

{
  short sVar1;
  ushort uVar2;
  float *pfVar3;
  undefined4 *puVar4;
  float fVar5;
  float fVar6;
  bool bVar7;
  char cVar8;
  undefined4 in_EAX;
  int iVar9;
  float10 fVar10;
  float fStack_88;
  float local_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  undefined1 local_50 [76];
  
  FUN_0048b530(in_EAX);
  FUN_0048b7a0();
  Matrix_InvertRigid();
  local_70 = 0.0;
  local_6c = 0.0;
  local_68 = 0.0;
  local_64 = 0;
  if ((char)param_2[0x11] != '\0') {
    iVar9 = param_2[0x14];
    local_6c = *(float *)(iVar9 + 0x24);
    local_70 = *(float *)(iVar9 + 0x20);
    local_68 = *(float *)(iVar9 + 0x28);
    local_64 = 0;
    thunk_FUN_005ac436(&local_70,&local_70,local_50);
  }
  if (1 < *(int *)(param_2[0xb] + 0x3cc)) {
    param_2[0x13] = DAT_0073ad34;
    GroundQuery__FindSurfaceBelow(param_2[0xb] + 0x540,param_2[0xb] + 0x60,&local_84,0,0);
    FUN_00441d80(local_84);
  }
  if ((DAT_0078a346 == '\0') && (DAT_007361a0 == 0)) {
    if (((*(char *)((int)param_2 + 0x45) == '\0') || (param_2[8] == 0)) ||
       (*(char *)(param_2[8] + 0x29) != '\0')) {
      fStack_80 = *(float *)(param_3 + 2);
      fStack_7c = *(float *)(param_3 + 6);
      fStack_78 = *(float *)(param_3 + 4);
    }
    else {
      iVar9 = (uint)(DAT_007364a0 == 3) * 0x10;
      fStack_7c = *(float *)(&DAT_00705af4 + iVar9);
      fStack_80 = *(float *)(&DAT_00705af0 + iVar9);
      fStack_78 = *(float *)(&DAT_00705af8 + iVar9);
    }
  }
  else {
    fStack_80 = DAT_00705c60;
    fStack_7c = DAT_00705c64;
    fStack_78 = DAT_00705c68;
  }
  _ftol_nocw();
  fVar10 = (float10)FUN_00564b10();
  local_84 = (float)fVar10;
  fVar10 = (float10)FUN_00564b10();
  sVar1 = *param_3;
  if (((sVar1 == 1) || (sVar1 == 0)) || (sVar1 == 4)) {
    bVar7 = true;
    fStack_88 = 0.0;
    fVar10 = ((float10)local_84 / fVar10) * (float10)fStack_80 + (float10)fStack_78;
  }
  else {
    bVar7 = false;
    fVar10 = (float10)fStack_78 - (float10)local_84 / fVar10;
    fStack_88 = fStack_80 + _K_ONE;
  }
  local_84 = (float)fVar10;
  fStack_60 = local_70 * *(float *)(param_4 + 0x10);
  fStack_5c = local_6c * *(float *)(param_4 + 0x14);
  fStack_58 = local_68 * *(float *)(param_4 + 0x18);
  FUN_00483430();
  fVar5 = fStack_80;
  fVar6 = fStack_7c;
  if (((*(int *)(param_2[0xb] + 0x38) != 0) && (*(int *)(param_2[0xb] + 0x3cc) < 3)) &&
     (cVar8 = (**(code **)(*param_2 + 0x24))(), fVar5 = fStack_80, fVar6 = fStack_7c, cVar8 != '\0')
     ) {
    fStack_78 = fStack_78 * 1.3;
    fVar5 = fStack_80 * 1.3;
    fVar6 = fStack_7c * 1.3;
  }
  fStack_60 = fStack_60 + fVar5;
  fStack_5c = fStack_5c + fVar6;
  fStack_58 = fStack_58 + fStack_78;
  FUN_004831c0(fStack_60,fStack_5c,fStack_58);
  fStack_60 = local_70 * *(float *)(param_4 + 0x40);
  fStack_5c = local_6c * *(float *)(param_4 + 0x44);
  fStack_58 = local_68 * *(float *)(param_4 + 0x48);
  FUN_00483430();
  fStack_60 = fStack_60 + fStack_88;
  fStack_58 = fStack_58 + local_84;
  FUN_004831c0(fStack_60,fStack_5c,fStack_58);
  uVar2 = *(ushort *)(CameraFOVTable + *param_3 * 2);
  pfVar3 = (float *)param_2[0xc];
  pfVar3[2] = (float)uVar2;
  if ((float)uVar2 != *pfVar3) {
    *(undefined2 *)(pfVar3 + 0xb) = 2;
  }
  if ((!bVar7) || (*(char *)((int)param_2 + 0x46) != '\0')) {
    puVar4 = (undefined4 *)param_2[0xc];
    *puVar4 = puVar4[2];
    puVar4[1] = puVar4[3];
    *(undefined2 *)(puVar4 + 0xb) = 0;
    puVar4 = (undefined4 *)param_2[0xd];
    *puVar4 = puVar4[2];
    puVar4[1] = puVar4[3];
    *(undefined2 *)(puVar4 + 0xb) = 0;
    puVar4[0xc] = puVar4[0xe];
    puVar4[0xd] = puVar4[0xf];
    *(undefined2 *)(puVar4 + 0x17) = 0;
    puVar4[0x18] = puVar4[0x1a];
    puVar4[0x19] = puVar4[0x1b];
    *(undefined2 *)(puVar4 + 0x23) = 0;
    puVar4 = (undefined4 *)param_2[0xe];
    *puVar4 = puVar4[2];
    puVar4[1] = puVar4[3];
    *(undefined2 *)(puVar4 + 0xb) = 0;
    puVar4[0xc] = puVar4[0xe];
    puVar4[0xd] = puVar4[0xf];
    *(undefined2 *)(puVar4 + 0x17) = 0;
    puVar4[0x18] = puVar4[0x1a];
    puVar4[0x19] = puVar4[0x1b];
    *(undefined2 *)(puVar4 + 0x23) = 0;
  }
  return;
}


// ==== 0x48bcb0 FUN_0048bcb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0048bcb0(int *param_1)

{
  short sVar1;
  int iVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  char cVar8;
  undefined2 uVar9;
  int iVar10;
  short *psVar11;
  int iVar12;
  undefined *puVar13;
  int *piVar14;
  undefined4 unaff_EDI;
  bool bVar15;
  undefined1 auStack_14c [4];
  undefined1 auStack_148 [3];
  char cStack_145;
  float fStack_144;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  undefined1 local_110 [4];
  float local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined1 auStack_a8 [8];
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined1 auStack_5c [12];
  undefined1 auStack_50 [76];
  
  cVar8 = FUN_0043a2e0();
  if ((((cVar8 == '\0') && (DAT_007361f0 != (int *)0x0)) &&
      ((*DAT_007361f0 == 7 || (*DAT_007361f0 == 0xb)))) && ((char)param_1[0x12] == '\0')) {
    return;
  }
  bVar15 = DAT_006fbf14 == 0;
  *(undefined1 *)(param_1 + 0x12) = 0;
  if (bVar15) {
    iVar10 = RaceManager__FindRacerById();
    param_1[0xb] = iVar10;
    while ((iVar10 == 0 && (-1 < DAT_006fbf18))) {
      DAT_006fbf18 = DAT_006fbf18 + -1;
      iVar12 = 0;
      if (0 < *(int *)(DAT_007361f8 + 0x18)) {
        piVar14 = (int *)(DAT_007361f8 + 0x28);
        do {
          iVar10 = *piVar14;
          if (*(short *)(iVar10 + 10) == DAT_006fbf18) goto LAB_0048bd5a;
          iVar12 = iVar12 + 1;
          piVar14 = piVar14 + 1;
        } while (iVar12 < *(int *)(DAT_007361f8 + 0x18));
      }
      iVar10 = 0;
LAB_0048bd5a:
      param_1[0xb] = iVar10;
    }
    if (param_1[0xb] != 0) goto LAB_0048bd85;
    if (param_1[8] != 0) {
      param_1[0xb] = *(int *)(param_1[8] + 4);
      goto LAB_0048bd85;
    }
    iVar10 = *(int *)(DAT_007361bc + 4);
  }
  else {
    if (param_1[8] == 0) goto LAB_0048bd85;
    iVar10 = *(int *)(param_1[8] + 4);
  }
  param_1[0xb] = iVar10;
LAB_0048bd85:
  FUN_0048ead0(0x3f000000);
  if ((((DAT_0078a345 != '\0') || (DAT_007361a4 != 0)) || (DAT_0078a346 != '\0')) ||
     (DAT_007361a0 != 0)) {
    local_100 = 0;
    local_fc = 0;
    local_f8 = 0;
  }
  FUN_0048ec00();
  *(undefined4 *)(param_1[0xc] + 0x24) = local_104;
  iVar10 = param_1[0xe];
  *(undefined4 *)(iVar10 + 0x24) = local_108;
  *(undefined4 *)(iVar10 + 0x84) = local_108;
  *(undefined4 *)(iVar10 + 0x54) = local_108;
  iVar10 = param_1[0xf];
  *(undefined4 *)(iVar10 + 0x24) = local_a0;
  *(undefined4 *)(iVar10 + 0x54) = local_9c;
  *(undefined4 *)(iVar10 + 0x84) = local_98;
  if (((*(int *)(param_1[0xb] + 0x38) == 0) || (2 < *(int *)(param_1[0xb] + 0x3cc))) ||
     (cVar8 = (**(code **)(*param_1 + 0x24))(), cVar8 == '\0')) {
    iVar10 = param_1[0xd];
    *(float *)(iVar10 + 0x24) = local_10c;
    *(float *)(iVar10 + 0x54) = local_10c;
    *(float *)(iVar10 + 0x84) = local_10c;
  }
  else {
    iVar10 = param_1[0xd];
    local_10c = local_10c / 1.3;
    *(float *)(iVar10 + 0x24) = local_10c;
    *(float *)(iVar10 + 0x54) = local_10c;
    *(float *)(iVar10 + 0x84) = local_10c;
  }
  FUN_00593d40(DAT_0073457c,0,0);
  fStack_144 = (float)DAT_0073457c;
  FUN_00593d40(DAT_0073457c,0,0);
  fVar4 = fStack_144;
  FUN_00593d40(fStack_144,0,0);
  FUN_00593d40(fVar4,0,0);
  fStack_144 = (float)DAT_0073457c;
  FUN_00593d40(DAT_0073457c,0,0);
  fVar4 = fStack_144;
  FUN_00593d40(fStack_144,0,0);
  FUN_00593d40(fVar4,0,0);
  fStack_144 = (float)DAT_0073457c;
  FUN_00593d40(DAT_0073457c,0,0);
  fVar4 = fStack_144;
  FUN_00593d40(fStack_144,0,0);
  FUN_00593d40(fVar4,0,0);
  psVar11 = (short *)FindCameraRow();
  if (psVar11 == (short *)0x0) {
    psVar11 = (short *)FindCameraRow();
  }
  iVar10 = DAT_00735f5c;
  sVar1 = *psVar11;
  if (((sVar1 == 1) || (sVar1 == 0)) || (sVar1 == 4)) {
    cStack_145 = '\x01';
    iVar12 = 0;
  }
  else {
    iVar12 = param_1[0xb];
    cStack_145 = '\0';
  }
  if (DAT_00735f5c == 0) {
    *(int *)(param_1[7] + 0x280) = iVar12;
    uVar9 = _ftol_nocw();
    *(undefined2 *)(param_1[7] + 0xc4) = uVar9;
  }
  uVar7 = _K_HALF;
  if (*psVar11 == 3) {
    uVar7 = DAT_006fbf1c;
  }
  *(undefined4 *)(param_1[7] + 0xbc) = uVar7;
  iVar12 = param_1[7];
  iVar2 = param_1[0xb];
  fVar4 = *(float *)(iVar12 + 0x40) - *(float *)(iVar2 + 0x60);
  fVar6 = *(float *)(iVar12 + 0x44) - *(float *)(iVar2 + 100);
  fVar5 = *(float *)(iVar12 + 0x48) - *(float *)(iVar2 + 0x68);
  if (iVar10 == 0) {
    *(float *)(iVar12 + 0xb0) = SQRT(fVar4 * fVar4 + fVar6 * fVar6 + fVar5 * fVar5);
  }
  if ((*(char *)((int)param_1 + 0x47) == '\0') && (iVar10 == 0)) {
    *(undefined4 *)(param_1[7] + 0xb4) = 0x41700000;
    *(undefined4 *)(param_1[7] + 0xb8) = 0x42820000;
  }
  FUN_0048b8c0(psVar11,local_110);
  *(undefined1 *)((int)param_1 + 0x46) = 0;
  if ((*(char *)((int)param_1 + 0x45) == '\0') ||
     ((param_1[8] != 0 && (*(char *)(param_1[8] + 0x29) == '\0')))) {
    fStack_144 = 1.0;
  }
  else {
    fStack_144 = -1.0;
  }
  uStack_130 = 0;
  uStack_12c = 0;
  uStack_128 = 0x3f800000;
  if (cStack_145 == '\0') {
    bMatrixCopy_b();
    uStack_e0 = 0;
    uStack_dc = 0;
    uStack_d8 = 0;
    uStack_d4 = 0x3f800000;
    D3DXVec3Transform(&uStack_130,&uStack_130,local_110);
  }
  pfVar3 = (float *)param_1[0xd];
  fStack_118 = pfVar3[0x18];
  fStack_11c = fStack_144 * pfVar3[0xc];
  fStack_120 = fStack_144 * *pfVar3;
  pfVar3 = (float *)param_1[0xe];
  fStack_138 = pfVar3[0x18];
  fStack_13c = fStack_144 * pfVar3[0xc];
  fStack_140 = fStack_144 * *pfVar3;
  D3DXVec3Transform(&fStack_120,&fStack_120,auStack_50);
  D3DXVec3Transform(auStack_14c,auStack_14c,auStack_5c);
  Matrix4_BuildLookAt(auStack_148);
  ApplyCameraShake(param_1[4]);
  if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
    puVar13 = &DAT_006b6eb8;
  }
  else {
    puVar13 = &DAT_006b6f08;
  }
  Camera__ApplyNoise(param_1,auStack_a8,puVar13,param_1[0xb]);
  if ((char)((uint)unaff_EDI >> 0x18) != '\0') {
    CameraMover_ClipAgainstWorld(param_1,auStack_a8,param_1[0xb]);
  }
  Camera__SetCameraMatrix(param_1[7],auStack_a8,DAT_0073457c);
  return;
}


// ==== 0x48c1f0 CameraMover_Type12::ctor

/* [canon] camera I (G+C) docs/re/camera.md */

undefined4 * __fastcall CameraMover_Type12__ctor(undefined4 *param_1)

{
  bool bVar1;
  
  CameraMover__ctor();
  bVar1 = DAT_00735f5c == 0;
  *param_1 = &PTR_CameraMover__TrivialDtor_006c7f80;
  if (bVar1) {
    *(undefined4 *)(param_1[7] + 0x280) = 0;
  }
  return param_1;
}


// ==== 0x48c220 FUN_0048c220

void __fastcall FUN_0048c220(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_0043a2e0();
  if (((cVar1 != '\0') || (DAT_007361f0 == (int *)0x0)) ||
     ((*DAT_007361f0 != 7 && (*DAT_007361f0 != 0xb)))) {
    if (DAT_00735f5c == 0) {
      *(undefined2 *)(*(int *)(param_1 + 0x1c) + 0xc4) =
           *(undefined2 *)(*(int *)(param_1 + 0x20) + 0x1c8);
    }
    Camera__SetCameraMatrix
              (*(undefined4 *)(param_1 + 0x1c),*(int *)(param_1 + 0x20) + 0x1f0,DAT_0073ad38);
  }
  return;
}


// ==== 0x48c280 DragRaceCameraMover::ctor

/* [canon] camera I (M+C) docs/re/camera.md */

undefined4 * __fastcall DragRaceCameraMover__ctor(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  bool bVar5;
  
  CameraMover__ctor();
  bVar5 = DAT_00735f5c == 0;
  *param_1 = &PTR_FUN_006c7ea8;
  if (bVar5) {
    *(undefined4 *)(param_1[7] + 0x280) = 0;
  }
  puVar2 = _malloc(0x30);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[9] = 0x3f333333;
    puVar2[10] = 0x41200000;
    *(undefined2 *)(puVar2 + 0xb) = 0;
    *(undefined2 *)((int)puVar2 + 0x2e) = 1;
  }
  param_1[0xb] = puVar2;
  pvVar3 = _malloc(0x90);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = CameraMoverBase_InitFields(0x3f000000,0x41200000);
  }
  param_1[0xc] = uVar4;
  pvVar3 = _malloc(0x90);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = CameraMoverBase_InitFields(0x3f000000,0x41200000);
  }
  uVar1 = param_1[0xc];
  param_1[0xd] = uVar4;
  FUN_00483e30();
  FUN_00483ea0(uVar1,0);
  FUN_00483fb0(uVar4,0);
  return param_1;
}


// ==== 0x48c370 FUN_0048c370

void * __thiscall FUN_0048c370(void *param_1,byte param_2)

{
  FUN_0048c390();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x48c390 FUN_0048c390

void __fastcall FUN_0048c390(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_006c7ea8;
  _free((void *)param_1[0xb]);
  _free((void *)param_1[0xc]);
  _free((void *)param_1[0xd]);
  *param_1 = &PTR_CameraMover__TrivialDtor_006c7c50;
  if (param_1[5] != 0) {
    param_1[5] = 0;
    param_1[9] = *(undefined4 *)(param_1[7] + 0x280);
    param_1[10] = *(undefined4 *)(param_1[7] + 0x284);
    iVar1 = param_1[1];
    piVar2 = (int *)param_1[2];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    ViewList_UpdateViewCountKind();
    return;
  }
  return;
}


// ==== 0x48c400 FUN_0048c400

void FUN_0048c400(void)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  ushort uVar8;
  int in_EAX;
  float unaff_ESI;
  uint uVar9;
  float10 fVar10;
  float fVar11;
  float fStack_a8;
  float fStack_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float fStack_94;
  undefined1 local_90 [4];
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float fStack_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar1 = *(int *)(in_EAX + 0x20);
  local_30 = 0.0;
  local_2c = 0.0;
  local_28 = 0.0;
  local_a0 = 0.0;
  local_9c = 0.0;
  local_98 = 0.0;
  if ((iVar1 != 0) && (iVar2 = *(int *)(iVar1 + 4), iVar2 != 0)) {
    local_2c = *(float *)(iVar2 + 0x74);
    local_30 = *(float *)(iVar2 + 0x70);
    local_a0 = *(float *)(iVar2 + 0x80);
    local_28 = *(float *)(iVar2 + 0x78);
    local_9c = *(float *)(iVar2 + 0x84);
    local_98 = *(float *)(iVar2 + 0x88);
  }
  local_80 = local_a0 * -0.1 + local_30 * 0.3 + *(float *)(iVar1 + 0x1a0);
  local_7c = local_9c * -0.1 + local_2c * 0.3 + *(float *)(iVar1 + 0x1a4);
  local_78 = local_98 * -0.1 + local_28 * 0.3 + *(float *)(iVar1 + 0x1a8);
  FUN_004831c0(local_80,local_7c,local_78);
  local_70 = 1.0;
  local_6c = 0.0;
  local_68 = 0.0;
  local_64 = 0;
  local_60 = 0.0;
  local_5c = 1.0;
  local_58 = 0.0;
  local_54 = 0;
  local_50 = 0.0;
  local_4c = 0.0;
  local_48 = 1.0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0.0;
  local_38 = 0.0;
  local_34 = 1.0;
  local_1c = *(undefined4 *)(*(int *)(in_EAX + 0x20) + 0x1b4);
  local_20 = *(undefined4 *)(*(int *)(in_EAX + 0x20) + 0x1b0);
  local_18 = 0;
  bNormalize3();
  local_60 = local_4c * local_68 - local_48 * local_6c;
  local_5c = local_48 * local_70 - local_68 * local_50;
  local_58 = local_6c * local_50 - local_4c * local_70;
  local_50 = local_58 * local_6c - local_5c * local_68;
  local_4c = local_68 * local_60 - local_58 * local_70;
  local_48 = local_5c * local_70 - local_6c * local_60;
  local_3c = *(float *)(iVar1 + 0x1a4);
  local_40 = *(undefined4 *)(iVar1 + 0x1a0);
  local_38 = *(float *)(iVar1 + 0x1a8);
  local_34 = 1.0;
  D3DXVec3Transform(local_90,&DAT_00705ce0,&local_70);
  uVar9 = DAT_007789e0;
  fVar5 = (unaff_ESI * -0.1 + local_3c * 0.3 + local_9c) - fStack_8c;
  fVar6 = (fStack_a8 * -0.1 + local_38 * 0.3 + local_98) - fStack_88;
  fVar7 = (fStack_a4 * -0.1 + local_34 * 0.3 + fStack_94) - fStack_84;
  fVar3 = *(float *)(*(int *)(in_EAX + 0x20) + 0x1ac);
  fVar10 = (float10)FUN_00564b10();
  fVar11 = (float)fVar10;
  fVar10 = (float10)FUN_00564b10();
  fVar10 = (float10)fVar3 / ((float10)fVar11 / fVar10);
  fVar11 = (float)fVar10;
  if ((float10)20.0 < fVar10) {
    uVar8 = Atan2ToAngle16(0x41a00000,fVar3);
    fVar11 = 20.0;
    uVar9 = (uint)uVar8 << 1;
  }
  FUN_005673e0(fVar11);
  fStack_24 = fVar7 + fStack_84;
  FUN_004831c0(fVar5 + fStack_8c,fVar6 + fStack_88,fStack_24);
  pfVar4 = *(float **)(in_EAX + 0x2c);
  pfVar4[2] = (float)(uVar9 & 0xffff);
  if ((float)(uVar9 & 0xffff) != *pfVar4) {
    *(undefined2 *)(pfVar4 + 0xb) = 2;
  }
  return;
}


// ==== 0x48c820 FUN_0048c820

void __fastcall FUN_0048c820(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char cVar3;
  undefined2 uVar4;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 local_50 [76];
  
  cVar3 = FUN_0043a2e0();
  if (((cVar3 != '\0') || (DAT_007361f0 == (int *)0x0)) ||
     ((*DAT_007361f0 != 7 && (*DAT_007361f0 != 0xb)))) {
    FUN_0048c400();
    FUN_00593d40(DAT_0073457c,0,0);
    uVar2 = DAT_0073457c;
    FUN_00593d40(DAT_0073457c,0,0);
    FUN_00593d40(uVar2,0,0);
    FUN_00593d40(uVar2,0,0);
    uVar2 = DAT_0073457c;
    FUN_00593d40(DAT_0073457c,0,0);
    FUN_00593d40(uVar2,0,0);
    FUN_00593d40(uVar2,0,0);
    if (DAT_00735f5c == 0) {
      uVar4 = _ftol_nocw();
      *(undefined2 *)(*(int *)(param_1 + 0x1c) + 0xc4) = uVar4;
    }
    puVar1 = *(undefined4 **)(param_1 + 0x30);
    local_5c = puVar1[0xc];
    local_60 = *puVar1;
    local_58 = puVar1[0x18];
    puVar1 = *(undefined4 **)(param_1 + 0x34);
    local_70 = *puVar1;
    local_6c = puVar1[0xc];
    local_68 = puVar1[0x18];
    local_80 = 0;
    local_7c = 0;
    local_78 = 0x3f800000;
    Matrix4_BuildLookAt(&local_80);
    CameraMover_ClipAgainstWorld(param_1,local_50,*(undefined4 *)(*(int *)(param_1 + 0x20) + 4));
    Camera__SetCameraMatrix(*(undefined4 *)(param_1 + 0x1c),local_50,DAT_0073457c);
  }
  return;
}


// ==== 0x48c990 DragRaceLeaderCameraMover::ctor

/* [canon] camera I (M+C) docs/re/camera.md */

void DragRaceLeaderCameraMover__ctor(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 *unaff_EDI;
  bool bVar5;
  
  CameraMover__ctor();
  unaff_EDI[0xb] = param_1;
  bVar5 = DAT_00735f5c == 0;
  *unaff_EDI = &PTR_FUN_006c7dc8;
  if (bVar5) {
    *(undefined4 *)(unaff_EDI[7] + 0x280) = 0;
  }
  uVar4 = DAT_006f0888;
  iVar1 = unaff_EDI[7];
  *(undefined1 *)(iVar1 + 0x270) = 1;
  *(undefined4 *)(iVar1 + 0x27c) = uVar4;
  puVar2 = _malloc(0x30);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[9] = 0x3f800000;
    puVar2[10] = 0x3f800000;
    *(undefined2 *)(puVar2 + 0xb) = 0;
    *(undefined2 *)((int)puVar2 + 0x2e) = 0;
  }
  unaff_EDI[0xc] = puVar2;
  pvVar3 = _malloc(0x90);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = CameraMoverBase_InitFields(0x3f800000,0x3f800000);
  }
  unaff_EDI[0xd] = uVar4;
  pvVar3 = _malloc(0x90);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = CameraMoverBase_InitFields(0x3f800000,0x3f800000);
  }
  unaff_EDI[0xe] = uVar4;
  pvVar3 = _malloc(0x90);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = CameraMoverBase_InitFields(0x3e4ccccd,0x3f800000);
  }
  unaff_EDI[0xf] = uVar4;
  puVar2 = _malloc(0x30);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[9] = 0x3f800000;
    puVar2[10] = 0x3f800000;
    *(undefined2 *)(puVar2 + 0xb) = 0;
    *(undefined2 *)((int)puVar2 + 0x2e) = 0;
  }
  unaff_EDI[0x10] = puVar2;
  pvVar3 = _malloc(0x30);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_0048eb70();
  }
  unaff_EDI[0x11] = uVar4;
  unaff_EDI[0x15] = 0;
  *(undefined1 *)(unaff_EDI + 0x14) = 1;
  *(undefined1 *)((int)unaff_EDI + 0x51) = 1;
  FUN_0048ce30(unaff_EDI,1);
  return;
}


// ==== 0x48cae0 FUN_0048cae0

void * __thiscall FUN_0048cae0(void *param_1,byte param_2)

{
  FUN_0048cb00();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x48cb00 FUN_0048cb00

void __fastcall FUN_0048cb00(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685b98;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c7dc8;
  local_4 = 0;
  _free((void *)param_1[0xc]);
  _free((void *)param_1[0xd]);
  _free((void *)param_1[0xe]);
  _free((void *)param_1[0xf]);
  _free((void *)param_1[0x10]);
  if ((undefined4 *)param_1[0x11] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x11])(1);
  }
  uVar3 = DAT_006f0888;
  iVar1 = param_1[7];
  *(undefined1 *)(iVar1 + 0x270) = 1;
  *(undefined4 *)(iVar1 + 0x27c) = uVar3;
  *param_1 = &PTR_CameraMover__TrivialDtor_006c7c50;
  if (param_1[5] != 0) {
    param_1[5] = 0;
    param_1[9] = *(undefined4 *)(param_1[7] + 0x280);
    param_1[10] = *(undefined4 *)(param_1[7] + 0x284);
    iVar1 = param_1[1];
    piVar2 = (int *)param_1[2];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    ViewList_UpdateViewCountKind();
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x48cbd0 FUN_0048cbd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048cbd0(char param_1)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  float fVar4;
  int unaff_EDI;
  float10 fVar5;
  float local_20;
  float local_1c;
  float local_18;
  
  iVar2 = *(int *)(unaff_EDI + 0x2c);
  local_1c = *(float *)(iVar2 + 0x74);
  local_20 = *(float *)(iVar2 + 0x70);
  local_18 = *(float *)(iVar2 + 0x78);
  fVar1 = local_1c * *(float *)(iVar2 + 0x94) +
          local_18 * *(float *)(iVar2 + 0x98) + local_20 * *(float *)(iVar2 + 0x90);
  if (fVar1 < 0.0) {
    fVar1 = fVar1 * -2.0;
    local_20 = fVar1 * *(float *)(iVar2 + 0x90) + local_20;
    local_1c = fVar1 * *(float *)(iVar2 + 0x94) + local_1c;
    local_18 = fVar1 * *(float *)(iVar2 + 0x98) + local_18;
  }
  fVar5 = (float10)LinearTable__Lookup11(&PTR_DAT_00705b20,*(undefined4 *)(iVar2 + 0x3d4));
  fVar1 = (float)fVar5;
  bNormalize3();
  fVar4 = _K_ONE - fVar1;
  FUN_004831c0(fVar4 * *(float *)(iVar2 + 0x90) + local_20 * fVar1,
               fVar4 * *(float *)(iVar2 + 0x94) + local_1c * fVar1,
               fVar4 * *(float *)(iVar2 + 0x98) + local_18 * fVar1);
  if (param_1 != '\0') {
    puVar3 = *(undefined4 **)(unaff_EDI + 0x3c);
    *puVar3 = puVar3[2];
    puVar3[1] = puVar3[3];
    *(undefined2 *)(puVar3 + 0xb) = 0;
    puVar3[0xc] = puVar3[0xe];
    puVar3[0xd] = puVar3[0xf];
    *(undefined2 *)(puVar3 + 0x17) = 0;
    puVar3[0x18] = puVar3[0x1a];
    puVar3[0x19] = puVar3[0x1b];
    *(undefined2 *)(puVar3 + 0x23) = 0;
  }
  return;
}


// ==== 0x48cd40 FUN_0048cd40

int FUN_0048cd40(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *unaff_ESI;
  int unaff_EDI;
  
  *unaff_ESI = 1.0;
  unaff_ESI[1] = 0.0;
  unaff_ESI[2] = 0.0;
  unaff_ESI[3] = 0.0;
  unaff_ESI[4] = 0.0;
  unaff_ESI[5] = 1.0;
  unaff_ESI[6] = 0.0;
  unaff_ESI[7] = 0.0;
  unaff_ESI[8] = 0.0;
  unaff_ESI[9] = 0.0;
  unaff_ESI[10] = 1.0;
  unaff_ESI[0xb] = 0.0;
  unaff_ESI[0xc] = 0.0;
  unaff_ESI[0xd] = 0.0;
  unaff_ESI[0xe] = 0.0;
  unaff_ESI[0xf] = 1.0;
  bNormalize3();
  unaff_ESI[4] = unaff_ESI[2] * unaff_ESI[9] - unaff_ESI[1] * unaff_ESI[10];
  unaff_ESI[5] = *unaff_ESI * unaff_ESI[10] - unaff_ESI[2] * unaff_ESI[8];
  unaff_ESI[6] = unaff_ESI[8] * unaff_ESI[1] - *unaff_ESI * unaff_ESI[9];
  unaff_ESI[8] = unaff_ESI[6] * unaff_ESI[1] - unaff_ESI[2] * unaff_ESI[5];
  unaff_ESI[9] = unaff_ESI[2] * unaff_ESI[4] - unaff_ESI[6] * *unaff_ESI;
  unaff_ESI[10] = unaff_ESI[5] * *unaff_ESI - unaff_ESI[4] * unaff_ESI[1];
  iVar3 = *(int *)(unaff_EDI + 0x2c);
  fVar1 = *(float *)(iVar3 + 0x54);
  fVar2 = *(float *)(iVar3 + 0x58);
  unaff_ESI[0xc] = *(float *)(iVar3 + 0x50);
  unaff_ESI[0xd] = fVar1;
  unaff_ESI[0xf] = 1.0;
  unaff_ESI[0xe] = fVar2;
  return iVar3 + 0x50;
}


// ==== 0x48ce30 FUN_0048ce30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048ce30(int param_1,char param_2)

{
  float fVar1;
  float *pfVar2;
  float fVar3;
  undefined4 in_EAX;
  int iVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  float10 fVar8;
  undefined4 local_1bc;
  undefined4 local_1b8;
  float local_1b4;
  float local_1b0;
  float local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_18c;
  undefined4 local_188;
  undefined2 local_184;
  undefined2 local_182;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_40;
  undefined4 local_3c;
  
  FUN_0048cbd0(in_EAX);
  iVar4 = KeyframeTrack_FindSegment(*(undefined4 *)(param_1 + 0x2c),param_1 + 0x48,param_1 + 0x4c);
  bVar7 = *(int *)(param_1 + 0x54) != iVar4;
  if ((param_2 != '\0') || (bVar7)) {
    *(int *)(param_1 + 0x54) = iVar4;
    *(bool *)(param_1 + 0x50) = *(char *)(iVar4 + 4) != '\0';
    *(bool *)(param_1 + 0x51) = *(char *)(iVar4 + 5) != '\0';
    FUN_00480310(&DAT_007789f0,&local_170,&local_1b0,&local_1bc,iVar4,0);
    FUN_00480310(&DAT_007789f0,&local_160,&local_1a0,&local_1b8,iVar4,1);
    fVar3 = CamWallPushOut * 12.0;
    local_1b4 = fVar3;
    uVar5 = Atan2ToAngle16(*(undefined4 *)(iVar4 + 0x3c),fVar3);
    pfVar2 = *(float **)(param_1 + 0x30);
    fVar1 = (float)((uVar5 & 0x7fff) << 1);
    *pfVar2 = fVar1;
    if (fVar1 != pfVar2[2]) {
      *(undefined2 *)(pfVar2 + 0xb) = 2;
    }
    fVar8 = (float10)FUN_004833c0(*(undefined4 *)(iVar4 + 0x3c),local_1bc);
    iVar6 = *(int *)(param_1 + 0x30);
    *(float *)(iVar6 + 4) = (float)fVar8;
    if (fVar8 != (float10)*(float *)(iVar6 + 0xc)) {
      *(undefined2 *)(iVar6 + 0x2c) = 2;
    }
    uVar5 = Atan2ToAngle16(*(undefined4 *)(iVar4 + 0x40),fVar3);
    pfVar2 = *(float **)(param_1 + 0x30);
    fVar1 = (float)((uVar5 & 0x7fff) << 1);
    pfVar2[2] = fVar1;
    if (fVar1 != *pfVar2) {
      *(undefined2 *)(pfVar2 + 0xb) = 2;
    }
    fVar8 = (float10)FUN_004833c0(*(undefined4 *)(iVar4 + 0x40),local_1b8);
    *(float *)(*(int *)(param_1 + 0x30) + 0xc) = (float)fVar8;
    FUN_00483160(*(undefined4 *)(iVar4 + 0xc),*(undefined4 *)(iVar4 + 0x10),
                 *(undefined4 *)(iVar4 + 0x14));
    FUN_00593bc0(local_170,local_16c,local_168);
    FUN_004831c0(*(undefined4 *)(iVar4 + 0x18),*(undefined4 *)(iVar4 + 0x1c),
                 *(undefined4 *)(iVar4 + 0x20));
    iVar6 = *(int *)(param_1 + 0x34);
    *(undefined4 *)(iVar6 + 0xc) = local_160;
    *(undefined4 *)(iVar6 + 0x3c) = local_15c;
    *(undefined4 *)(iVar6 + 0x6c) = local_158;
    FUN_00483160(*(undefined4 *)(iVar4 + 0x24),*(undefined4 *)(iVar4 + 0x28),
                 *(undefined4 *)(iVar4 + 0x2c));
    FUN_00593bc0(local_1b0,local_1ac,local_1a8);
    FUN_004831c0(*(undefined4 *)(iVar4 + 0x30),*(undefined4 *)(iVar4 + 0x34),
                 *(undefined4 *)(iVar4 + 0x38));
    iVar6 = *(int *)(param_1 + 0x38);
    *(undefined4 *)(iVar6 + 0xc) = local_1a0;
    *(undefined4 *)(iVar6 + 0x3c) = local_19c;
    *(undefined4 *)(iVar6 + 0x6c) = local_198;
    if ((bVar7) && (*(char *)(iVar4 + 1) != '\0')) {
      FUN_0048cd40();
      Matrix_InvertRigid();
      local_1b0 = 0.0;
      local_1ac = 0.0;
      local_1a8 = 0;
      local_1a4 = 0;
      local_18c = 0x3f800000;
      local_188 = 0x3f800000;
      local_184 = 0;
      local_182 = 1;
      CameraMoverBase_InitFields(0x3f800000,0x3f800000);
      CameraMoverBase_InitFields(0x3f800000,0x3f800000);
      FUN_00483e30();
      if (*(char *)(iVar4 + 4) == '\0') {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(param_1 + 0x2c) + 0x70;
      }
      FUN_00483ea0(&local_130,iVar6);
      if (*(char *)(iVar4 + 5) == '\0') {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(param_1 + 0x2c) + 0x70;
      }
      FUN_00483fb0(&local_a0,iVar6);
      fVar1 = _DAT_007796b0;
      if (DAT_007796a8 < 1) {
        fVar1 = *(float *)(*(int *)(param_1 + 0x2c) + 0x814);
      }
      pfVar2 = *(float **)(param_1 + 0x30);
      if (ABS(fVar1 - *(float *)(param_1 + 0x4c)) <= ABS(fVar1 - *(float *)(param_1 + 0x48))) {
        pfVar2[2] = local_1b0;
        if (local_1b0 != *pfVar2) {
          *(undefined2 *)(pfVar2 + 0xb) = 2;
        }
        *(float *)(*(int *)(param_1 + 0x30) + 0xc) = local_1ac;
        FUN_004831c0(local_130,local_100,local_d0);
        iVar6 = *(int *)(param_1 + 0x34);
        *(undefined4 *)(iVar6 + 0xc) = local_12c;
        *(undefined4 *)(iVar6 + 0x3c) = local_fc;
        *(undefined4 *)(iVar6 + 0x6c) = local_cc;
        FUN_004831c0(local_a0,local_70,local_40);
        iVar6 = *(int *)(param_1 + 0x38);
        *(undefined4 *)(iVar6 + 0xc) = local_9c;
        *(undefined4 *)(iVar6 + 0x3c) = local_6c;
        *(undefined4 *)(iVar6 + 0x6c) = local_3c;
      }
      else {
        *pfVar2 = local_1b0;
        if (local_1b0 != pfVar2[2]) {
          *(undefined2 *)(pfVar2 + 0xb) = 2;
        }
        iVar6 = *(int *)(param_1 + 0x30);
        *(float *)(iVar6 + 4) = local_1ac;
        if (local_1ac != *(float *)(iVar6 + 0xc)) {
          *(undefined2 *)(iVar6 + 0x2c) = 2;
        }
        FUN_00483160(local_130,local_100,local_d0);
        FUN_00593bc0(local_12c,local_fc,local_cc);
        FUN_00483160(local_a0,local_70,local_40);
        FUN_00593bc0(local_9c,local_6c,local_3c);
      }
    }
    pfVar2 = *(float **)(param_1 + 0x30);
    fVar1 = pfVar2[2] - *pfVar2;
    pfVar2[6] = pfVar2[1];
    pfVar2[7] = *pfVar2;
    pfVar2[4] = (pfVar2[1] + pfVar2[3]) - (fVar1 + fVar1);
    pfVar2[5] = (fVar1 * 3.0 - pfVar2[3]) - (pfVar2[1] + pfVar2[1]);
    FUN_00483220();
    FUN_00483220();
    fVar1 = *(float *)(iVar4 + 0x44);
    pfVar2 = *(float **)(param_1 + 0x40);
    *pfVar2 = fVar1;
    if (fVar1 != pfVar2[2]) {
      *(undefined2 *)(pfVar2 + 0xb) = 2;
    }
    fVar1 = *(float *)(iVar4 + 0x48);
    pfVar2 = *(float **)(param_1 + 0x40);
    pfVar2[2] = fVar1;
    if (fVar1 != *pfVar2) {
      *(undefined2 *)(pfVar2 + 0xb) = 2;
    }
    pfVar2 = *(float **)(param_1 + 0x40);
    fVar1 = pfVar2[2] - *pfVar2;
    pfVar2[6] = pfVar2[1];
    pfVar2[7] = *pfVar2;
    pfVar2[4] = (pfVar2[3] + pfVar2[1]) - (fVar1 + fVar1);
    pfVar2[5] = (fVar1 * 3.0 - pfVar2[3]) - (pfVar2[1] + pfVar2[1]);
  }
  return;
}


// ==== 0x48d3b0 FUN_0048d3b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0048d3b0(int param_1)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  undefined4 uVar4;
  char cVar5;
  undefined2 uVar6;
  float extraout_EDX;
  float fVar7;
  bool bVar8;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_98;
  undefined1 auStack_90 [64];
  undefined1 local_50 [76];
  
  cVar5 = FUN_0043a2e0();
  if (((cVar5 != '\0') || (DAT_007361f0 == (int *)0x0)) ||
     ((*DAT_007361f0 != 7 && (*DAT_007361f0 != 0xb)))) {
    FUN_0048ce30(param_1,1 < DAT_007796a8);
    iVar1 = *(int *)(param_1 + 0x3c);
    *(undefined4 *)(iVar1 + 0x24) = 0x3e4ccccd;
    *(undefined4 *)(iVar1 + 0x84) = 0x3e4ccccd;
    *(undefined4 *)(iVar1 + 0x54) = 0x3e4ccccd;
    uVar4 = DAT_0073457c;
    FUN_00593d40(DAT_0073457c,0,0);
    FUN_00593d40(uVar4,0,0);
    FUN_00593d40(uVar4,0,0);
    FUN_0048ec00();
    fVar3 = _DAT_007796b0;
    if (DAT_007796a8 < 1) {
      fVar3 = *(float *)(*(int *)(param_1 + 0x2c) + 0x814);
    }
    iVar1 = *(int *)(param_1 + 0x40);
    bVar8 = DAT_00735f5c == 0;
    fVar3 = (fVar3 - *(float *)(param_1 + 0x48)) /
            (*(float *)(param_1 + 0x4c) - *(float *)(param_1 + 0x48));
    *(float *)(*(int *)(param_1 + 0x1c) + 0xbc) =
         ((fVar3 * *(float *)(iVar1 + 0x10) + *(float *)(iVar1 + 0x14)) * fVar3 +
         *(float *)(iVar1 + 0x18)) * fVar3 + *(float *)(iVar1 + 0x1c);
    if (bVar8) {
      uVar6 = _ftol_nocw();
      *(undefined2 *)(*(int *)(param_1 + 0x1c) + 0xc4) = uVar6;
    }
    pfVar2 = *(float **)(param_1 + 0x34);
    if (*(char *)(*(int *)(param_1 + 0x54) + 2) == '\0') {
      local_98 = pfVar2[0x18];
      local_d0 = pfVar2[2];
      fVar7 = _K_ONE - fVar3;
      local_cc = pfVar2[0xe];
      local_c8 = pfVar2[0x1a];
      local_b0 = local_d0 * fVar3 + fVar7 * *pfVar2;
      local_ac = local_cc * fVar3 + pfVar2[0xc] * fVar7;
      local_a8 = local_c8 * fVar3 + local_98 * fVar7;
      fVar7 = fVar3;
    }
    else {
      FUN_00593e60(fVar3);
      fVar7 = extraout_EDX;
    }
    pfVar2 = *(float **)(param_1 + 0x38);
    if (*(char *)(*(int *)(param_1 + 0x54) + 3) == '\0') {
      local_98 = pfVar2[0x18];
      local_d0 = pfVar2[2];
      fVar7 = _K_ONE - fVar3;
      local_cc = pfVar2[0xe];
      local_c8 = pfVar2[0x1a];
      local_c0 = local_d0 * fVar3 + fVar7 * *pfVar2;
      local_bc = local_cc * fVar3 + pfVar2[0xc] * fVar7;
      local_b8 = local_c8 * fVar3 + local_98 * fVar7;
    }
    else {
      FUN_00593e60(fVar7);
    }
    FUN_0048cd40();
    if (*(char *)(param_1 + 0x50) != '\0') {
      D3DXVec3Transform(&local_b0,&local_b0,local_50);
    }
    if (*(char *)(param_1 + 0x51) != '\0') {
      D3DXVec3Transform(&local_c0,&local_c0,local_50);
    }
    local_d0 = 0.0;
    local_cc = 0.0;
    local_c8 = 1.0;
    Matrix4_BuildLookAt(&local_d0);
    ApplyCameraShake(*(undefined4 *)(param_1 + 0x10));
    iVar1 = DAT_007796a8;
    if (DAT_007796a8 == 0) {
      Camera__ApplyNoise(param_1,auStack_90,&DAT_006b6f08,*(undefined4 *)(param_1 + 0x2c));
    }
    if ((*(char *)(*(int *)(param_1 + 0x54) + 7) != '\0') && (iVar1 < 5)) {
      CameraMover_ClipAgainstWorld(param_1,auStack_90,0);
    }
    Camera__SetCameraMatrix(*(undefined4 *)(param_1 + 0x1c),auStack_90,DAT_0073457c);
  }
  return;
}


// ==== 0x48d6e0 DragRaceAheadCameraMover::ctor

/* [canon] camera I (M+C) docs/re/camera.md */

undefined4 *
DragRaceAheadCameraMover__ctor(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  bool bVar7;
  undefined1 local_110 [128];
  undefined4 local_90 [35];
  
  CameraMover__ctor();
  param_1[0xb] = param_2;
  bVar7 = DAT_00735f5c == 0;
  *param_1 = &PTR_FUN_006c7ce0;
  param_1[0x24] = param_3;
  if (bVar7) {
    *(undefined4 *)(param_1[7] + 0x280) = 0;
  }
  puVar2 = &DAT_006fc430;
  puVar6 = local_90;
  for (iVar5 = 0x20; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar6 = puVar6 + 1;
  }
  puVar2 = _malloc(0x30);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[9] = local_90[3];
    puVar2[10] = 0x41200000;
    *(undefined2 *)(puVar2 + 0xb) = 0;
    *(undefined2 *)((int)puVar2 + 0x2e) = 1;
  }
  param_1[0x20] = puVar2;
  pvVar3 = _malloc(0x90);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = CameraMoverBase_InitFields(local_90[1],0x41200000);
  }
  param_1[0x21] = uVar4;
  pvVar3 = _malloc(0x90);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = CameraMoverBase_InitFields(local_90[2],0x41200000);
  }
  param_1[0x22] = uVar4;
  pvVar3 = _malloc(0x90);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004830f0(0x41200000);
  }
  param_1[0x23] = uVar4;
  iVar5 = FindCameraRow();
  if (iVar5 == 0) {
    iVar5 = FindCameraRow();
  }
  FUN_0048dd00(local_110,iVar5,&DAT_006fc430);
  param_1[0x10] = 0x3f800000;
  param_1[0x15] = 0x3f800000;
  param_1[0x1a] = 0x3f800000;
  param_1[0x1f] = 0x3f800000;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  eTranslate(param_1 + 0x10,local_110);
  Matrix_InvertRigid();
  uVar4 = param_1[0x22];
  uVar1 = param_1[0x21];
  FUN_00483e30();
  FUN_00483ea0(uVar1,0);
  FUN_00483fb0(uVar4,0);
  puVar2 = (undefined4 *)param_1[0x20];
  *puVar2 = puVar2[2];
  puVar2[1] = puVar2[3];
  *(undefined2 *)(puVar2 + 0xb) = 0;
  puVar2 = (undefined4 *)param_1[0x21];
  *puVar2 = puVar2[2];
  puVar2[1] = puVar2[3];
  *(undefined2 *)(puVar2 + 0xb) = 0;
  puVar2[0xc] = puVar2[0xe];
  puVar2[0xd] = puVar2[0xf];
  *(undefined2 *)(puVar2 + 0x17) = 0;
  puVar2[0x18] = puVar2[0x1a];
  puVar2[0x19] = puVar2[0x1b];
  *(undefined2 *)(puVar2 + 0x23) = 0;
  puVar2 = (undefined4 *)param_1[0x22];
  *puVar2 = puVar2[2];
  puVar2[1] = puVar2[3];
  *(undefined2 *)(puVar2 + 0xb) = 0;
  *(undefined2 *)(puVar2 + 0x17) = 0;
  puVar2[0xc] = puVar2[0xe];
  puVar2[0xd] = puVar2[0xf];
  *(undefined2 *)(puVar2 + 0x23) = 0;
  puVar2[0x18] = puVar2[0x1a];
  puVar2[0x19] = puVar2[0x1b];
  return param_1;
}


// ==== 0x48d980 FUN_0048d980

void * __thiscall FUN_0048d980(void *param_1,byte param_2)

{
  FUN_0048d9a0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x48d9a0 FUN_0048d9a0

void __fastcall FUN_0048d9a0(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_006c7ce0;
  _free((void *)param_1[0x20]);
  _free((void *)param_1[0x21]);
  _free((void *)param_1[0x22]);
  _free((void *)param_1[0x23]);
  *param_1 = &PTR_CameraMover__TrivialDtor_006c7c50;
  if (param_1[5] != 0) {
    param_1[5] = 0;
    param_1[9] = *(undefined4 *)(param_1[7] + 0x280);
    param_1[10] = *(undefined4 *)(param_1[7] + 0x284);
    iVar1 = param_1[1];
    piVar2 = (int *)param_1[2];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    ViewList_UpdateViewCountKind();
    return;
  }
  return;
}


// ==== 0x48da20 FUN_0048da20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048da20(char param_1)

{
  float fVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  float fVar5;
  short *in_EAX;
  int unaff_EDI;
  float10 fVar6;
  float local_20;
  float local_1c;
  float local_18;
  
  sVar2 = *in_EAX;
  if (((sVar2 == 1) || (sVar2 == 0)) || (sVar2 == 4)) {
    iVar3 = *(int *)(unaff_EDI + 0x2c);
    local_1c = *(float *)(iVar3 + 0x74);
    local_20 = *(float *)(iVar3 + 0x70);
    local_18 = *(float *)(iVar3 + 0x78);
    fVar1 = local_1c * *(float *)(iVar3 + 0x94) +
            local_18 * *(float *)(iVar3 + 0x98) + local_20 * *(float *)(iVar3 + 0x90);
    if (fVar1 < 0.0) {
      fVar1 = fVar1 * -2.0;
      local_20 = fVar1 * *(float *)(iVar3 + 0x90) + local_20;
      local_1c = fVar1 * *(float *)(iVar3 + 0x94) + local_1c;
      local_18 = fVar1 * *(float *)(iVar3 + 0x98) + local_18;
    }
    fVar6 = (float10)LinearTable__Lookup11(&PTR_DAT_00705b20,*(undefined4 *)(iVar3 + 0x3d4));
    fVar1 = (float)fVar6;
    bNormalize3();
    fVar5 = _K_ONE - fVar1;
    FUN_004831c0(fVar5 * *(float *)(iVar3 + 0x90) + local_20 * fVar1,
                 fVar5 * *(float *)(iVar3 + 0x94) + local_1c * fVar1,
                 fVar5 * *(float *)(iVar3 + 0x98) + local_18 * fVar1);
    if (param_1 != '\0') {
      puVar4 = *(undefined4 **)(unaff_EDI + 0x8c);
      *puVar4 = puVar4[2];
      puVar4[1] = puVar4[3];
      *(undefined2 *)(puVar4 + 0xb) = 0;
      puVar4[0xc] = puVar4[0xe];
      puVar4[0xd] = puVar4[0xf];
      *(undefined2 *)(puVar4 + 0x17) = 0;
      puVar4[0x18] = puVar4[0x1a];
      puVar4[0x19] = puVar4[0x1b];
      *(undefined2 *)(puVar4 + 0x23) = 0;
      return;
    }
  }
  else {
    iVar3 = *(int *)(unaff_EDI + 0x2c);
    FUN_004831c0(*(undefined4 *)(iVar3 + 0x90),*(undefined4 *)(iVar3 + 0x94),
                 *(undefined4 *)(iVar3 + 0x98));
    puVar4 = *(undefined4 **)(unaff_EDI + 0x8c);
    *puVar4 = puVar4[2];
    puVar4[1] = puVar4[3];
    *(undefined2 *)(puVar4 + 0xb) = 0;
    puVar4[0xc] = puVar4[0xe];
    puVar4[0xd] = puVar4[0xf];
    *(undefined2 *)(puVar4 + 0x17) = 0;
    puVar4[0x18] = puVar4[0x1a];
    puVar4[0x19] = puVar4[0x1b];
    *(undefined2 *)(puVar4 + 0x23) = 0;
  }
  return;
}


// ==== 0x48dc10 FUN_0048dc10

int FUN_0048dc10(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *unaff_ESI;
  int unaff_EDI;
  
  *unaff_ESI = 1.0;
  unaff_ESI[1] = 0.0;
  unaff_ESI[2] = 0.0;
  unaff_ESI[3] = 0.0;
  unaff_ESI[4] = 0.0;
  unaff_ESI[5] = 1.0;
  unaff_ESI[6] = 0.0;
  unaff_ESI[7] = 0.0;
  unaff_ESI[8] = 0.0;
  unaff_ESI[9] = 0.0;
  unaff_ESI[10] = 1.0;
  unaff_ESI[0xb] = 0.0;
  unaff_ESI[0xc] = 0.0;
  unaff_ESI[0xd] = 0.0;
  unaff_ESI[0xe] = 0.0;
  unaff_ESI[0xf] = 1.0;
  bNormalize3();
  unaff_ESI[4] = unaff_ESI[2] * unaff_ESI[9] - unaff_ESI[1] * unaff_ESI[10];
  unaff_ESI[5] = *unaff_ESI * unaff_ESI[10] - unaff_ESI[2] * unaff_ESI[8];
  unaff_ESI[6] = unaff_ESI[8] * unaff_ESI[1] - *unaff_ESI * unaff_ESI[9];
  unaff_ESI[8] = unaff_ESI[6] * unaff_ESI[1] - unaff_ESI[2] * unaff_ESI[5];
  unaff_ESI[9] = unaff_ESI[2] * unaff_ESI[4] - unaff_ESI[6] * *unaff_ESI;
  unaff_ESI[10] = unaff_ESI[5] * *unaff_ESI - unaff_ESI[4] * unaff_ESI[1];
  iVar3 = *(int *)(unaff_EDI + 0x2c);
  fVar1 = *(float *)(iVar3 + 0x54);
  fVar2 = *(float *)(iVar3 + 0x58);
  unaff_ESI[0xc] = *(float *)(iVar3 + 0x50);
  unaff_ESI[0xd] = fVar1;
  unaff_ESI[0xf] = 1.0;
  unaff_ESI[0xe] = fVar2;
  return iVar3 + 0x50;
}


// ==== 0x48dd00 FUN_0048dd00

void __thiscall FUN_0048dd00(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  undefined4 *puVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined4 in_EAX;
  uint uVar12;
  
  FUN_0048da20(in_EAX);
  FUN_0048dc10();
  fVar11 = DAT_00736868;
  fVar10 = DAT_00736864;
  fVar9 = DAT_00736860;
  fVar8 = DAT_00705cf8;
  fVar7 = DAT_00705cf4;
  fVar6 = DAT_00705cf0;
  fVar1 = *(float *)(param_4 + 0x10);
  fVar2 = *(float *)(param_4 + 0x14);
  fVar3 = *(float *)(param_4 + 0x18);
  FUN_00483430();
  FUN_004831c0(fVar1 * 0.0 + fVar6,fVar2 * 0.0 + fVar7,fVar3 * 0.0 + fVar8);
  fVar1 = *(float *)(param_4 + 0x40);
  fVar2 = *(float *)(param_4 + 0x44);
  fVar3 = *(float *)(param_4 + 0x48);
  FUN_00483430();
  FUN_004831c0(fVar1 * 0.0 + fVar9,fVar2 * 0.0 + fVar10,fVar3 * 0.0 + fVar11);
  uVar12 = (uint)DAT_007788bc;
  pfVar4 = *(float **)(param_1 + 0x80);
  pfVar4[2] = (float)uVar12;
  if ((float)uVar12 != *pfVar4) {
    *(undefined2 *)(pfVar4 + 0xb) = 2;
  }
  puVar5 = *(undefined4 **)(param_1 + 0x80);
  puVar5[1] = puVar5[3];
  *puVar5 = puVar5[2];
  *(undefined2 *)(puVar5 + 0xb) = 0;
  puVar5 = *(undefined4 **)(param_1 + 0x84);
  *puVar5 = puVar5[2];
  puVar5[1] = puVar5[3];
  *(undefined2 *)(puVar5 + 0xb) = 0;
  puVar5[0xc] = puVar5[0xe];
  puVar5[0xd] = puVar5[0xf];
  *(undefined2 *)(puVar5 + 0x17) = 0;
  puVar5[0x18] = puVar5[0x1a];
  puVar5[0x19] = puVar5[0x1b];
  *(undefined2 *)(puVar5 + 0x23) = 0;
  puVar5 = *(undefined4 **)(param_1 + 0x88);
  *puVar5 = puVar5[2];
  puVar5[1] = puVar5[3];
  *(undefined2 *)(puVar5 + 0xb) = 0;
  puVar5[0xc] = puVar5[0xe];
  puVar5[0xd] = puVar5[0xf];
  *(undefined2 *)(puVar5 + 0x17) = 0;
  puVar5[0x18] = puVar5[0x1a];
  puVar5[0x19] = puVar5[0x1b];
  *(undefined2 *)(puVar5 + 0x23) = 0;
  return;
}


// ==== 0x48df00 FUN_0048df00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0048df00(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  char cVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 auStack_138 [2];
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 auStack_110 [26];
  undefined1 auStack_a8 [8];
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined1 auStack_5c [12];
  undefined1 auStack_50 [76];
  
  cVar5 = FUN_0043a2e0();
  if (((cVar5 != '\0') || (DAT_007361f0 == (int *)0x0)) ||
     ((*DAT_007361f0 != 7 && (*DAT_007361f0 != 0xb)))) {
    iVar7 = *(int *)(param_1 + 0x80);
    puVar9 = &DAT_006fc430;
    puVar10 = auStack_110;
    for (iVar8 = 0x20; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    *(undefined4 *)(iVar7 + 0x24) = auStack_110[3];
    iVar7 = *(int *)(param_1 + 0x84);
    *(undefined4 *)(iVar7 + 0x24) = auStack_110[1];
    *(undefined4 *)(iVar7 + 0x84) = auStack_110[1];
    *(undefined4 *)(iVar7 + 0x54) = auStack_110[1];
    iVar7 = *(int *)(param_1 + 0x88);
    *(undefined4 *)(iVar7 + 0x24) = auStack_110[2];
    *(undefined4 *)(iVar7 + 0x84) = auStack_110[2];
    *(undefined4 *)(iVar7 + 0x54) = auStack_110[2];
    iVar7 = *(int *)(param_1 + 0x8c);
    *(undefined4 *)(iVar7 + 0x24) = uStack_a0;
    *(undefined4 *)(iVar7 + 0x54) = uStack_9c;
    *(undefined4 *)(iVar7 + 0x84) = uStack_98;
    FUN_00593d40(DAT_0073457c,0,0);
    uVar4 = DAT_0073457c;
    FUN_00593d40(DAT_0073457c,0,0);
    FUN_00593d40(uVar4,0,0);
    FUN_00593d40(uVar4,0,0);
    uVar4 = DAT_0073457c;
    FUN_00593d40(DAT_0073457c,0,0);
    FUN_00593d40(uVar4,0,0);
    FUN_00593d40(uVar4,0,0);
    uVar4 = DAT_0073457c;
    FUN_00593d40(DAT_0073457c,0,0);
    FUN_00593d40(uVar4,0,0);
    FUN_00593d40(uVar4,0,0);
    if (DAT_00735f5c == 0) {
      uVar6 = _ftol_nocw();
      *(undefined2 *)(*(int *)(param_1 + 0x1c) + 0xc4) = uVar6;
    }
    iVar7 = FindCameraRow();
    if (iVar7 == 0) {
      iVar7 = FindCameraRow();
    }
    FUN_0048dd00(auStack_50,iVar7,&DAT_006fc430);
    fVar3 = DAT_00705d1c;
    fVar2 = DAT_00705d18;
    fVar1 = _DAT_00705d14;
    puVar9 = *(undefined4 **)(param_1 + 0x84);
    auStack_138[0] = puVar9[0x18];
    uStack_140 = *puVar9;
    uStack_13c = puVar9[0xc];
    puVar9 = *(undefined4 **)(param_1 + 0x88);
    uStack_128 = puVar9[0x18];
    uStack_12c = puVar9[0xc];
    uStack_130 = *puVar9;
    *(float *)(param_1 + 0x70) = _DAT_00705d10 + *(float *)(param_1 + 0x70);
    uStack_120 = 0;
    uStack_11c = 0;
    uStack_118 = 0x3f800000;
    *(float *)(param_1 + 0x74) = fVar1 + *(float *)(param_1 + 0x74);
    *(float *)(param_1 + 0x78) = fVar2 + *(float *)(param_1 + 0x78);
    *(float *)(param_1 + 0x7c) = fVar3 + *(float *)(param_1 + 0x7c);
    D3DXVec3Transform(&uStack_140,&uStack_140,param_1 + 0x40);
    D3DXVec3Transform(&uStack_13c,&uStack_13c,auStack_5c);
    Matrix4_BuildLookAt(auStack_138);
    ApplyCameraShake(*(undefined4 *)(param_1 + 0x10));
    Camera__ApplyNoise(param_1,auStack_a8,&DAT_006b6f08,*(undefined4 *)(param_1 + 0x2c));
    CameraMover_ClipAgainstWorld(param_1,auStack_a8,*(undefined4 *)(param_1 + 0x2c));
    Camera__SetCameraMatrix(*(undefined4 *)(param_1 + 0x1c),auStack_a8,DAT_0073457c);
  }
  return;
}


// ==== 0x48e210 AnimationControllerCameraMover::ctor

/* [canon] camera I (M+C) docs/re/camera.md */

undefined4 * AnimationControllerCameraMover__ctor(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  puVar2 = param_1;
  CameraMover__ctor();
  param_1[0xc] = param_2;
  *param_1 = &PTR_FUN_006c7c08;
  param_1[0xb] = 0;
  param_1[0xd] = 0;
  param_1[0xba] = 0;
  param_1[0xbb] = 0;
  param_1[0xbc] = 0;
  param_1[0xbd] = 0;
  param_1[0xbf] = 0;
  param_1[0xc0] = 0;
  param_1[0xc1] = 0;
  FUN_00440740();
  param_1[0xc2] = 0;
  param_1[0xc3] = 0;
  piVar1 = *(int **)param_1[0xc];
  param_1[0xb] = piVar1;
  if ((piVar1 == (int *)0x0) || (piVar1 == (int *)param_1[0xc])) {
    param_1[0xb] = 0;
  }
  else {
    piVar1[0xd] = piVar1[0xd] & 0xffffff7f;
  }
  pvVar3 = _malloc(0x50);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00473ea0();
  }
  param_1[0xd] = uVar4;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1 = (undefined4 *)0x0;
  if (0 < *(int *)(DAT_0073619c + 0x24)) {
    iVar7 = 0x520;
    iVar6 = DAT_0073619c;
    do {
      if (*(int *)(iVar7 + iVar6) != 0) {
        puVar5 = _malloc(0x250);
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          *puVar5 = &PTR_FUN_006c84d4;
          puVar5[0x4e] = 0;
        }
        *(undefined4 **)((int)puVar2 + iVar7 + -0x4e8) = puVar5;
        GJKWitness__Initialize();
        iVar6 = DAT_0073619c;
      }
      param_1 = (undefined4 *)((int)param_1 + 1);
      iVar7 = iVar7 + 4;
    } while ((int)param_1 < *(int *)(iVar6 + 0x24));
  }
  uVar4 = DAT_006f0888;
  iVar6 = puVar2[7];
  *(undefined1 *)(iVar6 + 0x270) = 1;
  *(undefined4 *)(iVar6 + 0x27c) = uVar4;
  return puVar2;
}


// ==== 0x48e360 FUN_0048e360

void * __thiscall FUN_0048e360(void *param_1,byte param_2)

{
  FUN_0048e380();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x48e380 FUN_0048e380

void __fastcall FUN_0048e380(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00685b83;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c7c08;
  local_4 = 1;
  if ((void *)param_1[0xd] != (void *)0x0) {
    _free((void *)param_1[0xd]);
    param_1[0xd] = 0;
  }
  piVar3 = param_1 + 0xe;
  iVar4 = 4;
  do {
    if ((undefined4 *)*piVar3 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar3)(1);
      *piVar3 = 0;
    }
    uVar2 = DAT_006f0888;
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = param_1[7];
  *(undefined1 *)(iVar4 + 0x270) = 1;
  *(undefined4 *)(iVar4 + 0x27c) = uVar2;
  iVar4 = param_1[0xba];
  if (0 < iVar4) {
    piVar3 = param_1 + 0x1a;
    do {
      iVar1 = *piVar3;
      piVar3 = piVar3 + 1;
      iVar4 = iVar4 + -1;
      *(char *)(iVar1 + 8) = *(char *)(iVar1 + 8) + -1;
    } while (iVar4 != 0);
  }
  *param_1 = &PTR_CameraMover__TrivialDtor_006c7c50;
  if (param_1[5] != 0) {
    param_1[5] = 0;
    param_1[9] = *(undefined4 *)(param_1[7] + 0x280);
    param_1[10] = *(undefined4 *)(param_1[7] + 0x284);
    iVar4 = param_1[1];
    piVar3 = (int *)param_1[2];
    *piVar3 = iVar4;
    *(int **)(iVar4 + 4) = piVar3;
    ViewList_UpdateViewCountKind();
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x48e470 FUN_0048e470

void __fastcall FUN_0048e470(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_006f0888;
  iVar1 = *(int *)(param_1 + 0x1c);
  *(undefined1 *)(iVar1 + 0x270) = 1;
  *(undefined4 *)(iVar1 + 0x27c) = uVar2;
  return;
}


// ==== 0x48e490 FUN_0048e490

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0048e490(float param_1)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  ushort uVar5;
  undefined2 uVar6;
  int unaff_EBX;
  int *piVar7;
  float unaff_ESI;
  float10 fVar8;
  int iVar9;
  float local_10c;
  float fStack_108;
  float fStack_104;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  undefined1 local_d0 [4];
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  undefined1 auStack_9c [64];
  undefined1 auStack_5c [88];
  
  local_10c = param_1;
  cVar4 = FUN_0043a2e0();
  if ((((cVar4 != '\0') || (DAT_007361f0 == (int *)0x0)) ||
      ((*DAT_007361f0 != 7 && (*DAT_007361f0 != 0xb)))) && (*(int *)((int)param_1 + 0x2c) != 0)) {
    if (DAT_00735f54 == 0) {
      FUN_0048e7b0(DAT_0073457c,0);
    }
    if (*(int *)((int)param_1 + 0x2c) != 0) {
      FUN_0047b3d0();
      bMatrixCopy_b();
      D3DXMatrixMultiply(local_d0,local_d0,&DAT_00779820);
      fVar8 = (float10)GroundQuery__FindSurfaceBelow((int)param_1 + 0x48,&fStack_ac,0,0,0);
      if (*(int *)((int)param_1 + 0x30c) == 0) {
        *(float *)((int)param_1 + 0x308) = (float)fVar8;
        *(undefined4 *)((int)param_1 + 0x30c) = 1;
      }
      else {
        *(float *)((int)param_1 + 0x308) =
             (float)((float10)0.03 * fVar8 +
                    ((float10)_K_ONE - (float10)0.03) * (float10)*(float *)((int)param_1 + 0x308));
      }
      fStack_104 = unaff_ESI + *(float *)((int)param_1 + 0x308);
      uStack_f8 = uStack_c8;
      fStack_108 = fStack_a8;
      uStack_f4 = uStack_c4;
      fStack_ec = fStack_ac - fStack_bc;
      uStack_fc = uStack_cc;
      fStack_e8 = fStack_a8 - fStack_b8;
      local_10c = fStack_ac;
      fStack_e4 = fStack_104 - fStack_b4;
      fStack_a4 = fStack_104;
      Matrix4_BuildLookAt(&uStack_fc);
      Camera__SetCameraMatrix(*(undefined4 *)((int)param_1 + 0x1c),auStack_9c,DAT_0073ad38);
      iVar9 = DAT_00735f5c;
      fVar1 = *(float *)(*(int *)(*(int *)((int)param_1 + 0x2c) + 0x14) + 0x30);
      if ((fVar1 < _K_ONE == (fVar1 == _K_ONE)) &&
         (uVar5 = Atan2ToAngle16(fVar1 + fVar1,0x42100a3d), iVar9 == 0)) {
        uVar6 = bDegreesToAngle16((float)uVar5 * 0.010986328);
        *(undefined2 *)(*(int *)((int)param_1 + 0x1c) + 0xc4) = uVar6;
      }
      eIdentity();
      if (iVar9 == 0) {
        *(undefined4 *)(*(int *)((int)param_1 + 0x1c) + 0x280) = 0;
      }
      iVar9 = 0;
      if (0 < *(int *)(DAT_0073619c + 0x24)) {
        piVar7 = (int *)((int)param_1 + 0x38);
        do {
          piVar2 = *(int **)((int)piVar7 + DAT_0073619c + (0x4e8 - unaff_EBX));
          if ((unaff_EBX != -0x38) && (piVar2 != (int *)0x0)) {
            iVar3 = *piVar2;
            FUN_00472830(iVar3 + 0x90,auStack_5c,&local_10c);
            FUN_00472950();
            if ((*(char *)(*piVar7 + 0x15) != '\0') && (DAT_00735f5c == 0)) {
              *(int *)(*(int *)(unaff_EBX + 0x1c) + 0x280) = iVar3;
            }
          }
          iVar9 = iVar9 + 1;
          piVar7 = piVar7 + 1;
        } while (iVar9 < *(int *)(DAT_0073619c + 0x24));
      }
    }
  }
  return;
}


// ==== 0x48e760 FUN_0048e760

void __fastcall FUN_0048e760(int *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)param_1[0xc];
  if (piVar1 != (int *)param_1[0xc]) {
    do {
      piVar1[0xd] = piVar1[0xd] | 0x20;
      piVar1[0x19] = 0;
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)param_1[0xc]);
  }
  piVar1 = *(int **)param_1[0xc];
  param_1[0xb] = (int)piVar1;
  if ((piVar1 == (int *)0x0) || (piVar1 == (int *)param_1[0xc])) {
    param_1[0xb] = 0;
  }
  else {
    piVar1[0xd] = piVar1[0xd] & 0xffffff7f;
  }
                    /* WARNING: Could not recover jumptable at 0x0048e7a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x34))();
  return;
}


// ==== 0x48e7b0 FUN_0048e7b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048e7b0(float param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *unaff_ESI;
  
  iVar3 = unaff_ESI[0xb];
  while ((iVar3 != 0 && (0.0 < param_1))) {
    iVar3 = unaff_ESI[0xb];
    fVar2 = *(float *)(iVar3 + 0x60) * (_K_ONE / DAT_006ffdbc) * *(float *)(iVar3 + 0x5c);
    fVar1 = (_K_ONE / DAT_006ffdbc) * *(float *)(iVar3 + 100) * *(float *)(iVar3 + 0x5c);
    if (param_1 + fVar1 <= fVar2) {
      if (param_2 != 0) {
        (**(code **)(*unaff_ESI + 0x34))();
      }
      iVar3 = CAnimCtrl__AdvanceAnimTime(param_1);
      if (iVar3 == 0x20) {
        (**(code **)(*unaff_ESI + 0x34))();
        iVar3 = *(int *)unaff_ESI[0xb];
        unaff_ESI[0xb] = iVar3;
        if (iVar3 == unaff_ESI[0xc]) {
          unaff_ESI[0xb] = 0;
        }
        else {
          *(uint *)(iVar3 + 0x34) = *(uint *)(iVar3 + 0x34) & 0xffffff7f;
        }
      }
      param_1 = 0.0;
    }
    else {
      *(uint *)(iVar3 + 0x34) = *(uint *)(iVar3 + 0x34) | 0x20;
      param_1 = param_1 - (fVar2 - fVar1);
      (**(code **)(*unaff_ESI + 0x34))();
      iVar3 = *(int *)unaff_ESI[0xb];
      unaff_ESI[0xb] = iVar3;
      if (iVar3 == unaff_ESI[0xc]) {
        unaff_ESI[0xb] = 0;
      }
      else {
        *(uint *)(iVar3 + 0x34) = *(uint *)(iVar3 + 0x34) & 0xffffff7f;
      }
    }
    iVar3 = unaff_ESI[0xb];
  }
  return;
}


// ==== 0x48e8b0 Players::UpdateStreamViewers

/* [canon] track med (hopper+ghidra) docs/re/track.md */

void Players__UpdateStreamViewers(void)

{
  char *pcVar1;
  undefined4 uVar2;
  bool bVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  puVar8 = &DAT_007404a4;
  do {
    if ((((puVar8 != (undefined4 *)0x44) && (puVar7 = (undefined4 *)*puVar8, puVar7 != puVar8)) &&
        (puVar7 != (undefined4 *)0x0)) && (puVar7 + -1 != (int *)0x0)) {
      (**(code **)(puVar7[-1] + 4))();
    }
    puVar8 = puVar8 + 0x18;
  } while ((int)puVar8 < 0x740a45);
  if (DAT_00735ee4 == 0) {
    pcVar4 = "JR2Server";
    do {
      pcVar1 = pcVar4 + 1;
      pcVar4 = pcVar4 + 1;
    } while (*pcVar1 != '\0');
    pcVar4 = "JR2Server";
    do {
      pcVar1 = pcVar4 + 1;
      pcVar4 = pcVar4 + 1;
    } while (*pcVar1 != '\0');
    DAT_00735ee0 = 0;
    DAT_00735ee4 = 1;
  }
  else if ((DAT_00735ee0 != 0) && (DAT_00740500 != 0)) {
    iVar5 = DAT_006f0884 - *(int *)(DAT_00740500 + 0x278);
    if (iVar5 < 0) {
      iVar5 = -iVar5;
    }
    if (0x10 < iVar5) {
      *(int *)(DAT_00740500 + 0x278) = DAT_006f0884;
      FUN_0047d630();
    }
  }
  if ((((undefined4 **)DAT_00740504 != &DAT_00740504) && (DAT_00740504 != (undefined4 *)0x0)) &&
     (DAT_00740504 != (undefined4 *)0x4)) {
    NullUpdate_ret(DAT_00740500 + 0x40);
  }
  bVar3 = false;
  puVar8 = &DAT_0077aa58;
  puVar7 = &DAT_00740504;
  do {
    if ((((*(char *)(puVar7 + -0xf) != '\0') && (puVar6 = (undefined4 *)*puVar7, puVar6 != puVar7))
        && (puVar6 != (undefined4 *)0x0)) && (puVar6 != (undefined4 *)0x4)) {
      if (!bVar3) {
        bVar3 = true;
        puVar6 = &DAT_0077aa58;
        do {
          puVar6[-1] = 0;
          *puVar6 = 0;
          puVar6[1] = 0;
          puVar6[2] = 0;
          *(undefined1 *)(puVar6 + 3) = 0;
          puVar6 = puVar6 + 0x11;
        } while ((int)puVar6 < 0x77aae0);
      }
      iVar5 = puVar7[-1];
      uVar2 = *(undefined4 *)(iVar5 + 0x40);
      *puVar8 = *(undefined4 *)(iVar5 + 0x44);
      puVar8[-1] = uVar2;
      uVar2 = *(undefined4 *)(iVar5 + 0x1e0);
      puVar8[2] = *(undefined4 *)(iVar5 + 0x1e4);
      puVar8[1] = uVar2;
      *(undefined1 *)(puVar8 + 3) = 1;
    }
    puVar7 = puVar7 + 0x18;
    puVar8 = puVar8 + 0x11;
  } while ((int)puVar7 < 0x7405c4);
  return;
}


// ==== 0x48ea10 FUN_0048ea10

undefined4 * __thiscall FUN_0048ea10(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006c8010;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x48ea30 FUN_0048ea30

void FUN_0048ea30(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *in_EAX;
  
  in_EAX[1] = param_1;
  in_EAX[2] = param_2;
  *in_EAX = &PTR_FUN_006c7ea0;
  in_EAX[3] = param_3;
  in_EAX[4] = param_4;
  return;
}


// ==== 0x48ea60 FUN_0048ea60

void * __thiscall FUN_0048ea60(void *param_1,byte param_2)

{
  FUN_0048ea80();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x48ea80 FUN_0048ea80

void __fastcall FUN_0048ea80(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c8010;
  return;
}


// ==== 0x48ea90 FUN_0048ea90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_0048ea90(int param_1)

{
  float10 fVar1;
  
  _ftol_nocw();
  fVar1 = (float10)FUN_00564b10();
  return ((float10)*(float *)(param_1 + 0x10) - (float10)*(float *)(param_1 + 0xc)) *
         (fVar1 - (float10)-1.0) * (float10)_K_HALF + (float10)*(float *)(param_1 + 0xc);
}


// ==== 0x48ead0 FUN_0048ead0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0048ead0(int *param_1,float param_2)

{
  float fVar1;
  undefined4 *in_EAX;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  float10 fVar5;
  
  iVar3 = *param_1;
  fVar1 = (param_2 - (float)param_1[1]) * (float)param_1[3];
  iVar2 = _ftol_nocw();
  if (iVar2 < 0) {
    puVar4 = (undefined4 *)param_1[4];
    for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
      *in_EAX = *puVar4;
      puVar4 = puVar4 + 1;
      in_EAX = in_EAX + 1;
    }
    return;
  }
  if (iVar3 + -1 <= iVar2) {
    puVar4 = (undefined4 *)(param_1[4] + -0x80 + iVar3 * 0x80);
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *in_EAX = *puVar4;
      puVar4 = puVar4 + 1;
      in_EAX = in_EAX + 1;
    }
    return;
  }
  fVar5 = (float10)FUN_004387e0(fVar1);
  if ((float10)fVar1 < fVar5) {
    fVar5 = fVar5 - (float10)_K_ONE;
  }
  FUN_0048ad90(param_1,(float)((float10)fVar1 - fVar5));
  return;
}


// ==== 0x48eb70 FUN_0048eb70

void FUN_0048eb70(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint in_EAX;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *unaff_ESI;
  
  *(char *)((int)unaff_ESI + 5) = (char)in_EAX;
  *(undefined1 *)(unaff_ESI + 1) = 0x10;
  *(undefined1 *)((int)unaff_ESI + 6) = 0;
  *(undefined1 *)((int)unaff_ESI + 7) = 0;
  *unaff_ESI = &PTR_FUN_006c7d70;
  puVar3 = _malloc(in_EAX << 4);
  unaff_ESI[2] = puVar3;
  for (iVar4 = (in_EAX & 0xfffffff) << 2; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)puVar3 = 0;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  puVar3 = (undefined4 *)unaff_ESI[2];
  uVar1 = puVar3[1];
  uVar2 = puVar3[2];
  unaff_ESI[8] = *puVar3;
  unaff_ESI[9] = uVar1;
  unaff_ESI[10] = uVar2;
  puVar3 = (undefined4 *)unaff_ESI[2];
  uVar1 = puVar3[1];
  uVar2 = puVar3[2];
  unaff_ESI[4] = *puVar3;
  unaff_ESI[5] = uVar1;
  unaff_ESI[6] = uVar2;
  return;
}


// ==== 0x48ebe0 FUN_0048ebe0

void FUN_0048ebe0(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_FUN_006c7d70;
  _free((void *)unaff_ESI[2]);
  *unaff_ESI = &PTR_FUN_006c7d78;
  return;
}


// ==== 0x48ec00 FUN_0048ec00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0048ec00(undefined4 param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  float *pfVar3;
  byte bVar4;
  
  if (*(byte *)(in_EAX + 6) < *(byte *)(in_EAX + 5)) {
    *(byte *)(in_EAX + 6) = *(byte *)(in_EAX + 6) + 1;
  }
  pfVar3 = (float *)((uint)*(byte *)(in_EAX + 7) * 0x10 + *(int *)(in_EAX + 8));
  fVar1 = pfVar3[1];
  fVar2 = pfVar3[2];
  *(float *)(in_EAX + 0x10) = *(float *)(in_EAX + 0x10) - *pfVar3;
  *(float *)(in_EAX + 0x14) = *(float *)(in_EAX + 0x14) - fVar1;
  *(float *)(in_EAX + 0x18) = *(float *)(in_EAX + 0x18) - fVar2;
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  *(float *)(in_EAX + 0x10) = *param_2 + *(float *)(in_EAX + 0x10);
  *(float *)(in_EAX + 0x14) = fVar1 + *(float *)(in_EAX + 0x14);
  *(float *)(in_EAX + 0x18) = fVar2 + *(float *)(in_EAX + 0x18);
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  pfVar3 = (float *)((uint)*(byte *)(in_EAX + 7) * 0x10 + *(int *)(in_EAX + 8));
  *pfVar3 = *param_2;
  pfVar3[1] = fVar1;
  pfVar3[2] = fVar2;
  fVar1 = _K_ONE / (float)*(byte *)(in_EAX + 6);
  *(float *)(in_EAX + 0x20) = fVar1 * *(float *)(in_EAX + 0x10);
  *(float *)(in_EAX + 0x24) = *(float *)(in_EAX + 0x14) * fVar1;
  *(float *)(in_EAX + 0x28) = *(float *)(in_EAX + 0x18) * fVar1;
  bVar4 = *(char *)(in_EAX + 7) + 1;
  *(byte *)(in_EAX + 7) = bVar4;
  if (*(byte *)(in_EAX + 5) <= bVar4) {
    *(undefined1 *)(in_EAX + 7) = 0;
  }
  return;
}


// ==== 0x48ece0 FUN_0048ece0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0048ece0(int param_1)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x10) * 0.0;
  *(float *)(param_1 + 0x14) = *(float *)(param_1 + 0x14) * 0.0;
  *(float *)(param_1 + 0x18) = *(float *)(param_1 + 0x18) * 0.0;
  if (*(char *)(param_1 + 6) != '\0') {
    iVar6 = 0;
    do {
      fVar1 = *(float *)(*(int *)(param_1 + 8) + 4 + iVar6);
      pfVar4 = (float *)(*(int *)(param_1 + 8) + iVar6);
      fVar2 = pfVar4[2];
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 0x10;
      *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x10) + *pfVar4;
      *(float *)(param_1 + 0x14) = fVar1 + *(float *)(param_1 + 0x14);
      *(float *)(param_1 + 0x18) = fVar2 + *(float *)(param_1 + 0x18);
    } while (iVar5 < (int)(uint)*(byte *)(param_1 + 6));
  }
  bVar3 = 1;
  if (*(byte *)(param_1 + 6) != 0) {
    bVar3 = *(byte *)(param_1 + 6);
  }
  fVar1 = _K_ONE / (float)bVar3;
  *(float *)(param_1 + 0x20) = fVar1 * *(float *)(param_1 + 0x10);
  *(float *)(param_1 + 0x24) = *(float *)(param_1 + 0x14) * fVar1;
  *(float *)(param_1 + 0x28) = *(float *)(param_1 + 0x18) * fVar1;
  return;
}


// ==== 0x48eda0 FUN_0048eda0

void * __thiscall FUN_0048eda0(void *param_1,byte param_2)

{
  FUN_0048ebe0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x48edc0 ZoneCamera_GetLetterboxSpan

/* [canon] camera low (ghidra-canon) docs/re/camera.md */

float10 __fastcall ZoneCamera_GetLetterboxSpan(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      return (float10)*(int *)(param_1 + 4);
    }
    if (iVar1 != 2) {
      return (float10)0.0;
    }
  }
  return (float10)(*(int *)(param_1 + 4) + -1);
}


// ==== 0x48edf0 FUN_0048edf0

void FUN_0048edf0(void)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  int in_EAX;
  
  _Memory = *(int **)(in_EAX + 8);
  while (_Memory != (int *)(in_EAX + 8)) {
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
    _Memory = *(int **)(in_EAX + 8);
  }
  return;
}


// ==== 0x48ee20 FUN_0048ee20

byte FUN_0048ee20(undefined4 param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int in_EAX;
  undefined4 unaff_EDI;
  bool bVar4;
  
  bVar4 = in_EAX == 1;
  bVar1 = FUN_00441030(param_1,0,bVar4,unaff_EDI,0x3f333333,0x3f800000);
  bVar2 = FUN_00441030(param_1,1,bVar4,unaff_EDI,0x3f333333,0x3f800000);
  bVar1 = bVar1 | bVar2;
  if (param_3 == 1) {
    bVar2 = FUN_00441030(param_1,0,bVar4,param_2,0x3f333333,0x3f800000);
    bVar3 = FUN_00441030(param_1,1,bVar4,param_2,0x3f333333,0x3f800000);
    bVar1 = bVar1 | bVar2 | bVar3;
  }
  return bVar1;
}


// ==== 0x48eed0 FUN_0048eed0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048eed0(undefined4 param_1,float *param_2,float *param_3,float *param_4)

{
  float *in_EAX;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_18;
  
  local_30 = (*param_4 - *in_EAX) * _K_HALF;
  local_2c = (param_4[1] - in_EAX[1]) * _K_HALF;
  local_28 = (param_4[2] - in_EAX[2]) * _K_HALF;
  local_34 = SQRT(local_30 * local_30 + local_28 * local_28 + local_2c * local_2c);
  if (15.0 < local_34) {
    local_34 = 15.0;
    local_30 = local_30 * 15.0;
    local_2c = local_2c * 15.0;
    local_28 = local_28 * 15.0;
  }
  local_30 = local_30 + *in_EAX;
  local_2c = local_2c + in_EAX[1];
  local_28 = local_28 + in_EAX[2];
  GroundQuery__RefillCache(&local_30,local_34,0);
  FUN_0048ee20(param_1,param_4,0);
  local_18 = param_2[2] - param_3[2];
  local_30 = (*param_2 - *param_3) * _K_HALF;
  local_2c = (param_2[1] - param_3[1]) * _K_HALF;
  local_28 = local_18 * _K_HALF;
  local_34 = SQRT(local_30 * local_30 + local_28 * local_28 + local_2c * local_2c);
  if (15.0 < local_34) {
    local_34 = 15.0;
    local_30 = local_30 * 15.0;
    local_2c = local_2c * 15.0;
    local_28 = local_28 * 15.0;
  }
  local_30 = local_30 + *param_3;
  local_2c = local_2c + param_3[1];
  local_28 = local_28 + param_3[2];
  GroundQuery__RefillCache(&local_30,local_34,0);
  FUN_0048ee20(param_1,param_2,0);
  return;
}


// ==== 0x48f090 ZoneFreezeCameraMover::ctor

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera V (G+C) docs/re/camera.md */

undefined4 *
ZoneFreezeCameraMover__ctor(undefined4 *param_1,undefined4 param_2,int param_3,int *param_4)

{
  float *pfVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  void *pvVar5;
  int iVar6;
  undefined4 *puVar7;
  float fVar8;
  bool bVar9;
  float10 fVar10;
  undefined1 local_1a0 [72];
  float local_158;
  undefined1 local_150 [16];
  float local_140;
  float local_13c;
  float local_138;
  undefined4 local_134;
  float local_130;
  float local_12c;
  float local_128;
  float local_120;
  float local_11c;
  float local_118;
  undefined1 local_110 [8];
  float local_108;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e0;
  float local_dc;
  float local_d8;
  undefined4 local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  undefined4 local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  undefined4 local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  undefined4 local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_90;
  float local_8c;
  float local_88;
  float local_80;
  float local_7c;
  float local_78;
  float local_68;
  undefined4 *local_64;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 *local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_28;
  float local_24;
  undefined1 *puStack_20;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  pcStack_18 = FUN_006863b7;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  CameraMover__ctor();
  local_44 = param_1 + 0x12;
  *param_1 = &PTR_FUN_006c7b98;
  param_1[0xb] = 0;
  local_14 = 0;
  param_1[0x17] = 1;
  param_1[0x14] = 2;
  *local_44 = 100;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x13] = 0;
  param_1[0x18] = 0x4000;
  param_1[0x1d] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  local_64 = param_1 + 0x1e;
  param_1[0x23] = 1;
  param_1[0x20] = 2;
  *local_64 = 100;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x1f] = 0;
  param_1[0x24] = 0x4000;
  param_1[0x29] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  puVar7 = param_1 + 0x2a;
  param_1[0xd2] = 0;
  param_1[0xd3] = 0;
  param_1[0xd4] = 0;
  param_1[0xd5] = 0;
  param_1[0xd7] = 0;
  param_1[0xd8] = 0;
  param_1[0xd9] = 0;
  FUN_00440740();
  local_14 = CONCAT31(local_14._1_3_,3);
  local_e0 = 1.0;
  local_dc = 0.0;
  local_d8 = 0.0;
  local_d4 = 0;
  local_d0 = 0.0;
  local_cc = 1.0;
  local_c8 = 0.0;
  local_c4 = 0;
  local_c0 = 0.0;
  local_bc = 0.0;
  local_b4 = 0;
  local_b0 = 0.0;
  local_ac = 0.0;
  local_a8 = 0.0;
  local_a4 = 0x3f800000;
  local_b8 = 1.0;
  if (*(float *)(param_3 + 0x3d4) <= 0.01) {
    fVar8 = ABS(_K_ONE - *(float *)(param_3 + 0x98));
    if (fVar8 < 0.001 == (fVar8 == 0.001)) {
      local_e0 = *(float *)(param_3 + 0x90);
      local_dc = *(float *)(param_3 + 0x94);
    }
    else {
      local_e0 = -*(float *)(param_3 + 0xb0);
      local_dc = -*(float *)(param_3 + 0xb4);
    }
  }
  bNormalize2();
  local_d0 = local_bc * local_d8 - local_dc * local_b8;
  local_cc = local_e0 * local_b8 - local_d8 * local_c0;
  local_c8 = local_c0 * local_dc - local_bc * local_e0;
  local_b0 = DAT_0073457c * *(float *)(param_3 + 0x70) + *(float *)(param_3 + 0x60);
  local_ac = DAT_0073457c * *(float *)(param_3 + 0x74) + *(float *)(param_3 + 100);
  local_a8 = DAT_0073457c * *(float *)(param_3 + 0x78) + *(float *)(param_3 + 0x68);
  iVar6 = param_1[7];
  local_ec = DAT_0073457c * *(float *)(iVar6 + 0x1e4) + *(float *)(iVar6 + 0x44);
  local_e8 = DAT_0073457c * *(float *)(iVar6 + 0x1e8) + *(float *)(iVar6 + 0x48);
  local_f0 = DAT_0073457c * *(float *)(iVar6 + 0x1e0) + *(float *)(iVar6 + 0x40);
  local_a0 = DAT_0073457c * *(float *)(iVar6 + 0x200) + *(float *)(iVar6 + 0x60);
  local_9c = DAT_0073457c * *(float *)(iVar6 + 0x204) + *(float *)(iVar6 + 100);
  local_98 = DAT_0073457c * *(float *)(iVar6 + 0x208) + *(float *)(iVar6 + 0x68);
  Matrix_InvertRigid();
  D3DXVec3Transform(&local_90,&local_f0,local_1a0);
  cVar3 = (**(code **)(*param_4 + 0x24))();
  local_24 = 1.0;
  if (cVar3 == '\0') {
    local_24 = -1.0;
  }
  local_90 = local_90 * local_24;
  iVar6 = param_1[7];
  local_8c = local_8c * local_24;
  local_88 = local_88 * local_24;
  local_140 = *(float *)(iVar6 + 0x1e0) - *(float *)(param_3 + 0x70);
  local_13c = *(float *)(iVar6 + 0x1e4) - *(float *)(param_3 + 0x74);
  local_158 = *(float *)(iVar6 + 0x1e8) - *(float *)(param_3 + 0x78);
  local_134 = 0;
  local_138 = local_158;
  thunk_FUN_005ac436(&local_140,&local_140,local_1a0);
  local_f4 = _K_ONE;
  if ((local_90 * local_b8 - local_88 * local_c0) * local_13c +
      (local_c0 * local_8c - local_bc * local_90) * local_138 +
      (local_88 * local_bc - local_8c * local_b8) * local_140 < 0.0) {
    local_f4 = -1.0;
  }
  local_f4 = local_f4 * local_24;
  uVar4 = Atan2ToAngle16(local_90,local_8c);
  local_68 = (float)(uVar4 & 0xffff);
  local_24 = 0.0;
  local_28 = local_f4 * 0.15 + (float)(int)local_68 * 1.5258789e-05;
  do {
    _ftol_nocw();
    fVar10 = (float10)FUN_00564b10();
    local_68 = (float)fVar10;
    fVar10 = (float10)FUN_00564b10();
    local_f8 = (float)fVar10;
    local_80 = (float)(fVar10 * (float10)0.1);
    local_78 = 1.2;
    local_7c = local_68 * 0.1;
    D3DXVec3Transform(local_150,&local_80,&local_e0);
    FUN_005825e0(local_64,local_150);
    local_80 = local_f8 * 8.0;
    local_78 = 2.0;
    local_7c = local_68 * 8.0;
    D3DXVec3Transform(local_110,&local_80,&local_e0);
    GroundQuery__RefillCache(local_150,0x410b3333,0);
    FUN_00441030(puVar7,0,1,local_110,0x3f333333,0x3f800000);
    FUN_00441030(puVar7,1,1,local_110,0x3f333333,0x3f800000);
    FUN_00441030(puVar7,0,1,local_150,0x3f333333,0x3f800000);
    FUN_00441030(puVar7,1,1,local_150,0x3f333333,0x3f800000);
    GroundQuery__RefillCache(local_110,0x41200000,0);
    fVar10 = (float10)GroundQuery__FindSurfaceBelow(puVar7,local_110,0,0,0);
    if ((fVar10 - (float10)1.0 < (float10)local_108) && ((float10)local_108 < fVar10 + (float10)1.0)
       ) {
      local_108 = (float)(fVar10 + (float10)1.0);
    }
    FUN_005825e0(local_44,local_110);
    puVar2 = local_44;
    local_24 = (float)((int)local_24 + 1);
  } while ((int)local_24 < 0x20);
  FUN_005829e0(0);
  FUN_00582a90(0);
  iVar6 = param_1[7];
  local_80 = *(float *)(iVar6 + 0x1e0) - *(float *)(param_3 + 0x70);
  local_7c = *(float *)(iVar6 + 0x1e4) - *(float *)(param_3 + 0x74);
  local_158 = *(float *)(iVar6 + 0x1e8) - *(float *)(param_3 + 0x78);
  iVar6 = puVar2[2];
  if (iVar6 == 0) {
LAB_0048f79c:
    local_28 = (float)(puVar2[1] + -1);
    fVar8 = (float)(int)local_28;
  }
  else if (iVar6 == 1) {
    fVar8 = (float)(int)puVar2[1];
  }
  else {
    if (iVar6 == 2) goto LAB_0048f79c;
    fVar8 = 0.0;
  }
  fVar8 = (fVar8 / 2.0) * 0.4;
  local_60 = local_60 * fVar8;
  local_5c = local_5c * fVar8;
  local_58 = local_58 * fVar8;
  local_40 = local_80 * 0.4;
  local_3c = local_7c * 0.4;
  local_38 = local_158 * 0.4;
  local_78 = local_158;
  pvVar5 = _malloc(0x90);
  if (pvVar5 == (void *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = CameraMoverBase_InitFields(0x3f800000,0x3f800000);
  }
  puVar7 = local_64;
  param_1[0xd] = iVar6;
  *(undefined4 *)(iVar6 + 0x24) = 0x3ecccccd;
  *(undefined4 *)(iVar6 + 0x84) = 0x3ecccccd;
  *(undefined4 *)(iVar6 + 0x54) = 0x3ecccccd;
  iVar6 = param_1[0xd];
  *(undefined2 *)(iVar6 + 0x2e) = 0;
  *(undefined2 *)(iVar6 + 0x5e) = 0;
  *(undefined2 *)(iVar6 + 0x8e) = 0;
  pfVar1 = (float *)param_1[0xd];
  *pfVar1 = local_f0;
  if (local_f0 != pfVar1[2]) {
    *(undefined2 *)(pfVar1 + 0xb) = 2;
  }
  pfVar1[0xc] = local_ec;
  if (local_ec != pfVar1[0xe]) {
    *(undefined2 *)(pfVar1 + 0x17) = 2;
  }
  pfVar1[0x18] = local_e8;
  if (local_e8 != pfVar1[0x1a]) {
    *(undefined2 *)(pfVar1 + 0x23) = 2;
  }
  iVar6 = param_1[0xd];
  *(float *)(iVar6 + 4) = local_40;
  if (local_40 != *(float *)(iVar6 + 0xc)) {
    *(undefined2 *)(iVar6 + 0x2c) = 2;
  }
  *(float *)(iVar6 + 0x34) = local_3c;
  if (local_3c != *(float *)(iVar6 + 0x3c)) {
    *(undefined2 *)(iVar6 + 0x5c) = 2;
  }
  *(float *)(iVar6 + 100) = local_38;
  if (local_38 != *(float *)(iVar6 + 0x6c)) {
    *(undefined2 *)(iVar6 + 0x8c) = 2;
  }
  pfVar1 = (float *)param_1[0xd];
  pfVar1[2] = local_120;
  if (local_120 != *pfVar1) {
    *(undefined2 *)(pfVar1 + 0xb) = 2;
  }
  pfVar1[0xe] = local_11c;
  if (local_11c != pfVar1[0xc]) {
    *(undefined2 *)(pfVar1 + 0x17) = 2;
  }
  pfVar1[0x1a] = local_118;
  if (local_118 != pfVar1[0x18]) {
    *(undefined2 *)(pfVar1 + 0x23) = 2;
  }
  iVar6 = param_1[0xd];
  *(float *)(iVar6 + 0x3c) = local_5c;
  *(float *)(iVar6 + 0x6c) = local_58;
  *(float *)(iVar6 + 0xc) = local_60;
  FUN_005829e0(0);
  FUN_00582a90(0);
  iVar6 = param_1[7];
  local_80 = *(float *)(iVar6 + 0x200) - *(float *)(param_3 + 0x70);
  local_7c = *(float *)(iVar6 + 0x204) - *(float *)(param_3 + 0x74);
  local_158 = *(float *)(iVar6 + 0x208) - *(float *)(param_3 + 0x78);
  iVar6 = puVar7[2];
  if (iVar6 == 0) {
LAB_0048f9b2:
    local_28 = (float)(puVar7[1] + -1);
    fVar8 = (float)(int)local_28;
  }
  else if (iVar6 == 1) {
    fVar8 = (float)(int)puVar7[1];
  }
  else {
    if (iVar6 == 2) goto LAB_0048f9b2;
    fVar8 = 0.0;
  }
  fVar8 = (fVar8 / 2.0) * 0.4;
  local_60 = local_60 * fVar8;
  local_5c = local_5c * fVar8;
  local_58 = local_58 * fVar8;
  local_40 = local_80 * 0.4;
  local_3c = local_7c * 0.4;
  local_38 = local_158 * 0.4;
  local_78 = local_158;
  pvVar5 = _malloc(0x90);
  if (pvVar5 == (void *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = CameraMoverBase_InitFields(0x3f800000,0x3f800000);
  }
  param_1[0xf] = iVar6;
  *(undefined4 *)(iVar6 + 0x24) = 0x3ecccccd;
  *(undefined4 *)(iVar6 + 0x84) = 0x3ecccccd;
  *(undefined4 *)(iVar6 + 0x54) = 0x3ecccccd;
  iVar6 = param_1[0xf];
  *(undefined2 *)(iVar6 + 0x2e) = 0;
  *(undefined2 *)(iVar6 + 0x5e) = 0;
  *(undefined2 *)(iVar6 + 0x8e) = 0;
  pfVar1 = (float *)param_1[0xf];
  *pfVar1 = local_a0;
  if (local_a0 != pfVar1[2]) {
    *(undefined2 *)(pfVar1 + 0xb) = 2;
  }
  pfVar1[0xc] = local_9c;
  if (local_9c != pfVar1[0xe]) {
    *(undefined2 *)(pfVar1 + 0x17) = 2;
  }
  pfVar1[0x18] = local_98;
  if (local_98 != pfVar1[0x1a]) {
    *(undefined2 *)(pfVar1 + 0x23) = 2;
  }
  iVar6 = param_1[0xf];
  *(float *)(iVar6 + 4) = local_40;
  if (local_40 != *(float *)(iVar6 + 0xc)) {
    *(undefined2 *)(iVar6 + 0x2c) = 2;
  }
  *(float *)(iVar6 + 0x34) = local_3c;
  if (local_3c != *(float *)(iVar6 + 0x3c)) {
    *(undefined2 *)(iVar6 + 0x5c) = 2;
  }
  *(float *)(iVar6 + 100) = local_38;
  if (local_38 != *(float *)(iVar6 + 0x6c)) {
    *(undefined2 *)(iVar6 + 0x8c) = 2;
  }
  pfVar1 = (float *)param_1[0xf];
  pfVar1[2] = local_120;
  if (local_120 != *pfVar1) {
    *(undefined2 *)(pfVar1 + 0xb) = 2;
  }
  pfVar1[0xe] = local_11c;
  if (local_11c != pfVar1[0xc]) {
    *(undefined2 *)(pfVar1 + 0x17) = 2;
  }
  pfVar1[0x1a] = local_118;
  if (local_118 != pfVar1[0x18]) {
    *(undefined2 *)(pfVar1 + 0x23) = 2;
  }
  iVar6 = param_1[0xf];
  *(float *)(iVar6 + 0x3c) = local_5c;
  *(float *)(iVar6 + 0xc) = local_60;
  *(float *)(iVar6 + 0x6c) = local_58;
  iVar6 = local_44[2];
  if (iVar6 == 0) {
LAB_0048fb81:
    fVar8 = (float)(local_44[1] + -1);
    local_28 = fVar8;
LAB_0048fb8b:
    local_24 = (float)(int)fVar8;
  }
  else {
    if (iVar6 == 1) {
      fVar8 = (float)local_44[1];
      goto LAB_0048fb8b;
    }
    if (iVar6 == 2) goto LAB_0048fb81;
    local_24 = 0.0;
  }
  FUN_005829e0(local_24);
  iVar6 = local_44[2];
  if (iVar6 == 0) {
LAB_0048fbbe:
    fVar8 = (float)(local_44[1] + -1);
    local_28 = fVar8;
LAB_0048fbc8:
    local_24 = (float)(int)fVar8;
  }
  else {
    if (iVar6 == 1) {
      fVar8 = (float)local_44[1];
      goto LAB_0048fbc8;
    }
    if (iVar6 == 2) goto LAB_0048fbbe;
    local_24 = 0.0;
  }
  FUN_00582a90(local_24);
  iVar6 = local_44[2];
  if (iVar6 == 0) {
LAB_0048fbf6:
    local_28 = (float)(local_44[1] + -1);
    fVar8 = (float)(int)local_28;
  }
  else if (iVar6 == 1) {
    fVar8 = (float)(int)local_44[1];
  }
  else {
    if (iVar6 == 2) goto LAB_0048fbf6;
    fVar8 = 0.0;
  }
  iVar6 = param_1[7];
  fVar8 = (fVar8 / 2.0) * 0.4;
  local_40 = local_40 * fVar8;
  local_3c = local_3c * fVar8;
  local_38 = local_38 * fVar8;
  local_60 = *(float *)(iVar6 + 0x1e0) * 0.6;
  local_5c = *(float *)(iVar6 + 0x1e4) * 0.6;
  local_58 = *(float *)(iVar6 + 0x1e8) * 0.6;
  pvVar5 = _malloc(0x90);
  if (pvVar5 == (void *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = CameraMoverBase_InitFields(0x3f800000,0x3f800000);
  }
  param_1[0xe] = iVar6;
  *(undefined4 *)(iVar6 + 0x24) = 0x3f19999a;
  *(undefined4 *)(iVar6 + 0x84) = 0x3f19999a;
  *(undefined4 *)(iVar6 + 0x54) = 0x3f19999a;
  iVar6 = param_1[0xe];
  *(undefined2 *)(iVar6 + 0x2e) = 0;
  *(undefined2 *)(iVar6 + 0x5e) = 0;
  *(undefined2 *)(iVar6 + 0x8e) = 0;
  pfVar1 = (float *)param_1[0xe];
  *pfVar1 = local_130;
  if (local_130 != pfVar1[2]) {
    *(undefined2 *)(pfVar1 + 0xb) = 2;
  }
  pfVar1[0xc] = local_12c;
  if (local_12c != pfVar1[0xe]) {
    *(undefined2 *)(pfVar1 + 0x17) = 2;
  }
  pfVar1[0x18] = local_128;
  if (local_128 != pfVar1[0x1a]) {
    *(undefined2 *)(pfVar1 + 0x23) = 2;
  }
  iVar6 = param_1[0xe];
  *(float *)(iVar6 + 4) = local_40;
  if (local_40 != *(float *)(iVar6 + 0xc)) {
    *(undefined2 *)(iVar6 + 0x2c) = 2;
  }
  *(float *)(iVar6 + 0x34) = local_3c;
  if (local_3c != *(float *)(iVar6 + 0x3c)) {
    *(undefined2 *)(iVar6 + 0x5c) = 2;
  }
  *(float *)(iVar6 + 100) = local_38;
  if (local_38 != *(float *)(iVar6 + 0x6c)) {
    *(undefined2 *)(iVar6 + 0x8c) = 2;
  }
  pfVar1 = (float *)param_1[0xe];
  pfVar1[2] = local_f0;
  if (local_f0 != *pfVar1) {
    *(undefined2 *)(pfVar1 + 0xb) = 2;
  }
  pfVar1[0xe] = local_ec;
  if (local_ec != pfVar1[0xc]) {
    *(undefined2 *)(pfVar1 + 0x17) = 2;
  }
  pfVar1[0x1a] = local_e8;
  if (local_e8 != pfVar1[0x18]) {
    *(undefined2 *)(pfVar1 + 0x23) = 2;
  }
  iVar6 = param_1[0xe];
  *(float *)(iVar6 + 0x3c) = local_5c;
  *(float *)(iVar6 + 0xc) = local_60;
  *(float *)(iVar6 + 0x6c) = local_58;
  iVar6 = local_64[2];
  if (iVar6 == 0) {
LAB_0048fdc5:
    fVar8 = (float)(local_64[1] + -1);
    local_28 = fVar8;
LAB_0048fdcf:
    local_24 = (float)(int)fVar8;
  }
  else {
    if (iVar6 == 1) {
      fVar8 = (float)local_64[1];
      goto LAB_0048fdcf;
    }
    if (iVar6 == 2) goto LAB_0048fdc5;
    local_24 = 0.0;
  }
  FUN_005829e0(local_24);
  iVar6 = local_64[2];
  if (iVar6 == 0) {
LAB_0048fe02:
    fVar8 = (float)(local_64[1] + -1);
    local_28 = fVar8;
LAB_0048fe0c:
    local_24 = (float)(int)fVar8;
  }
  else {
    if (iVar6 == 1) {
      fVar8 = (float)local_64[1];
      goto LAB_0048fe0c;
    }
    if (iVar6 == 2) goto LAB_0048fe02;
    local_24 = 0.0;
  }
  FUN_00582a90(local_24);
  iVar6 = local_64[2];
  if (iVar6 != 0) {
    if (iVar6 == 1) {
      fVar8 = (float)(int)local_64[1];
      goto LAB_0048fe44;
    }
    if (iVar6 != 2) {
      fVar8 = 0.0;
      goto LAB_0048fe44;
    }
  }
  local_28 = (float)(local_64[1] + -1);
  fVar8 = (float)(int)local_28;
LAB_0048fe44:
  iVar6 = param_1[7];
  fVar8 = (fVar8 / 2.0) * 0.4;
  local_40 = local_40 * fVar8;
  local_3c = local_3c * fVar8;
  local_38 = local_38 * fVar8;
  local_60 = *(float *)(iVar6 + 0x200) * 0.6;
  local_5c = *(float *)(iVar6 + 0x204) * 0.6;
  local_58 = *(float *)(iVar6 + 0x208) * 0.6;
  pvVar5 = _malloc(0x90);
  if (pvVar5 == (void *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = CameraMoverBase_InitFields(0x3f800000,0x3f800000);
  }
  param_1[0x10] = iVar6;
  *(undefined4 *)(iVar6 + 0x24) = 0x3f19999a;
  *(undefined4 *)(iVar6 + 0x84) = 0x3f19999a;
  *(undefined4 *)(iVar6 + 0x54) = 0x3f19999a;
  iVar6 = param_1[0x10];
  *(undefined2 *)(iVar6 + 0x2e) = 0;
  *(undefined2 *)(iVar6 + 0x5e) = 0;
  *(undefined2 *)(iVar6 + 0x8e) = 0;
  pfVar1 = (float *)param_1[0x10];
  *pfVar1 = local_130;
  if (local_130 != pfVar1[2]) {
    *(undefined2 *)(pfVar1 + 0xb) = 2;
  }
  pfVar1[0xc] = local_12c;
  if (local_12c != pfVar1[0xe]) {
    *(undefined2 *)(pfVar1 + 0x17) = 2;
  }
  pfVar1[0x18] = local_128;
  if (local_128 != pfVar1[0x1a]) {
    *(undefined2 *)(pfVar1 + 0x23) = 2;
  }
  iVar6 = param_1[0x10];
  *(float *)(iVar6 + 4) = local_40;
  if (local_40 != *(float *)(iVar6 + 0xc)) {
    *(undefined2 *)(iVar6 + 0x2c) = 2;
  }
  *(float *)(iVar6 + 0x34) = local_3c;
  if (local_3c != *(float *)(iVar6 + 0x3c)) {
    *(undefined2 *)(iVar6 + 0x5c) = 2;
  }
  *(float *)(iVar6 + 100) = local_38;
  if (local_38 != *(float *)(iVar6 + 0x6c)) {
    *(undefined2 *)(iVar6 + 0x8c) = 2;
  }
  pfVar1 = (float *)param_1[0x10];
  pfVar1[2] = local_a0;
  if (local_a0 != *pfVar1) {
    *(undefined2 *)(pfVar1 + 0xb) = 2;
  }
  pfVar1[0xe] = local_9c;
  if (local_9c != pfVar1[0xc]) {
    *(undefined2 *)(pfVar1 + 0x17) = 2;
  }
  pfVar1[0x1a] = local_98;
  if (local_98 != pfVar1[0x18]) {
    *(undefined2 *)(pfVar1 + 0x23) = 2;
  }
  iVar6 = param_1[0x10];
  *(float *)(iVar6 + 0x3c) = local_5c;
  *(float *)(iVar6 + 0xc) = local_60;
  *(float *)(iVar6 + 0x6c) = local_58;
  puVar7 = _malloc(0x30);
  if (puVar7 == (undefined4 *)0x0) {
    puVar7 = (undefined4 *)0x0;
  }
  else {
    *puVar7 = 0;
    puVar7[1] = 0;
    puVar7[2] = 0;
    puVar7[3] = 0;
    puVar7[9] = 0x3f800000;
    puVar7[10] = 0x3f800000;
    *(undefined2 *)(puVar7 + 0xb) = 0;
    *(undefined2 *)((int)puVar7 + 0x2e) = 1;
  }
  param_1[0x11] = puVar7;
  *(undefined2 *)((int)puVar7 + 0x2e) = 0;
  *(undefined4 *)(param_1[0x11] + 0x24) = 0x3ecccccd;
  puVar7 = (undefined4 *)param_1[0x11];
  *puVar7 = 0x3f800000;
  if (puVar7[2] != 0x3f800000) {
    *(undefined2 *)(puVar7 + 0xb) = 2;
  }
  pfVar1 = (float *)param_1[0x11];
  pfVar1[2] = 1.0;
  if (*pfVar1 != 1.0) {
    *(undefined2 *)(pfVar1 + 0xb) = 2;
  }
  iVar6 = param_1[7];
  fVar10 = (float10)FUN_00564b10();
  local_28 = (float)fVar10;
  fVar10 = (float10)FUN_00564b10();
  bVar9 = DAT_00735f5c == 0;
  param_1[0xc] = (float)((float10)local_28 / fVar10);
  if (bVar9) {
    *(undefined4 *)(iVar6 + 0x280) = 0;
    *(undefined4 *)(param_1[7] + 0x284) = 0;
  }
  ExceptionList = local_1c;
  return param_1;
}


// ==== 0x4900d0 FUN_004900d0

void * __thiscall FUN_004900d0(void *param_1,byte param_2)

{
  FUN_004900f0();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x4900f0 FUN_004900f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004900f0(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  *param_1 = &PTR_FUN_006c7b98;
  _gSpecialCameraActive = 0;
  _free((void *)param_1[0xd]);
  _free((void *)param_1[0xe]);
  _free((void *)param_1[0xf]);
  _free((void *)param_1[0x10]);
  _free((void *)param_1[0x11]);
  iVar3 = param_1[0xd2];
  if (0 < iVar3) {
    piVar2 = param_1 + 0x32;
    do {
      iVar1 = *piVar2;
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + -1;
      *(char *)(iVar1 + 8) = *(char *)(iVar1 + 8) + -1;
    } while (iVar3 != 0);
  }
  if ((void *)param_1[0x22] != (void *)0x0) {
    _free((void *)param_1[0x22]);
  }
  if ((void *)param_1[0x29] != (void *)0x0) {
    _free((void *)param_1[0x29]);
  }
  if ((void *)param_1[0x16] != (void *)0x0) {
    _free((void *)param_1[0x16]);
  }
  if ((void *)param_1[0x1d] != (void *)0x0) {
    _free((void *)param_1[0x1d]);
  }
  *param_1 = &PTR_CameraMover__TrivialDtor_006c7c50;
  if (param_1[5] == 0) {
    return;
  }
  param_1[5] = 0;
  param_1[9] = *(undefined4 *)(param_1[7] + 0x280);
  param_1[10] = *(undefined4 *)(param_1[7] + 0x284);
  iVar3 = param_1[1];
  piVar2 = (int *)param_1[2];
  *piVar2 = iVar3;
  *(int **)(iVar3 + 4) = piVar2;
  ViewList_UpdateViewCountKind();
  return;
}


// ==== 0x4901e0 FUN_004901e0

void __fastcall FUN_004901e0(int param_1)

{
  float fVar1;
  float *pfVar2;
  int *piVar3;
  float fVar4;
  char cVar5;
  undefined2 uVar6;
  float fVar7;
  float10 fVar8;
  float local_90;
  float local_8c;
  float local_88;
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
  
  cVar5 = FUN_0043a2e0();
  if (((cVar5 != '\0') || (DAT_007361f0 == (int *)0x0)) ||
     ((*DAT_007361f0 != 7 && (*DAT_007361f0 != 0xb)))) {
    fVar1 = *(float *)(param_1 + 0x2c);
    local_60 = 0;
    local_5c = 0;
    fVar4 = DAT_0073ad38 + *(float *)(param_1 + 0x2c);
    local_58 = 0x3f800000;
    *(float *)(param_1 + 0x2c) = fVar4;
    fVar7 = DAT_0073ad38;
    if (0.4 <= fVar4) {
      if (fVar4 <= 2.4) {
        fVar1 = (fVar4 - 0.4) / 2.0;
        fVar8 = (float10)ZoneCamera_GetLetterboxSpan();
        FUN_005829e0((float)(fVar8 * (float10)fVar1));
        fVar8 = (float10)ZoneCamera_GetLetterboxSpan();
        FUN_005829e0((float)(fVar8 * (float10)fVar1));
        fVar7 = DAT_0073ad38;
      }
      else {
        if (fVar1 < 2.4 != (fVar1 == 2.4)) {
          *(float *)(*(int *)(param_1 + 0x44) + 0x24) = 3.0 - fVar4;
          piVar3 = *(int **)(param_1 + 0x44);
          piVar3[2] = 0x3f800000;
          if (*piVar3 != 0x3f800000) {
            *(undefined2 *)(piVar3 + 0xb) = 2;
          }
        }
        fVar1 = DAT_0073ad38;
        FUN_00593fc0(DAT_0073ad38);
        FUN_00593fc0(fVar1);
        pfVar2 = *(float **)(param_1 + 0x38);
        local_90 = *pfVar2;
        local_8c = pfVar2[0xc];
        local_88 = pfVar2[0x18];
        pfVar2 = *(float **)(param_1 + 0x40);
        local_80 = *pfVar2;
        local_7c = pfVar2[0xc];
        local_78 = pfVar2[0x18];
        FUN_0048ee20(param_1 + 0xa8,&local_80,0);
        fVar7 = DAT_0073ad38;
      }
    }
    else {
      FUN_00593ec0(DAT_0073ad38,0,0);
      FUN_00593ec0(fVar7,0,0);
      FUN_00593ec0(fVar7,0,0);
      FUN_00593ec0(fVar7,0,0);
      FUN_00593ec0(fVar7,0,0);
      FUN_00593ec0(fVar7,0,0);
      pfVar2 = *(float **)(param_1 + 0x34);
      local_90 = *pfVar2;
      local_8c = pfVar2[0xc];
      local_88 = pfVar2[0x18];
      pfVar2 = *(float **)(param_1 + 0x3c);
      local_80 = *pfVar2;
      local_7c = pfVar2[0xc];
      local_78 = pfVar2[0x18];
      FUN_0048ee20(param_1 + 0xa8,&local_80,0);
    }
    FUN_00593ec0(fVar7,0,0);
    fVar1 = **(float **)(param_1 + 0x44);
    local_70 = (local_90 - local_80) * fVar1;
    local_6c = (local_8c - local_7c) * fVar1;
    local_68 = (local_88 - local_78) * fVar1 + local_78;
    uVar6 = Atan2ToAngle16(**(float **)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x30));
    if (DAT_00735f5c == 0) {
      *(undefined2 *)(*(int *)(param_1 + 0x1c) + 0xc4) = uVar6;
    }
    Matrix4_BuildLookAt(&local_60);
    Camera__SetCameraMatrix(*(undefined4 *)(param_1 + 0x1c),local_50,DAT_0073ad38);
  }
  return;
}


// ==== 0x4904f0 FUN_004904f0

void FUN_004904f0(undefined4 param_1)

{
  int in_EAX;
  undefined4 *unaff_ESI;
  
  unaff_ESI[8] = *(undefined4 *)(in_EAX + 0x20);
  unaff_ESI[7] = in_EAX + 0x24;
  unaff_ESI[10] = *(undefined4 *)(in_EAX + 0x4c);
  unaff_ESI[9] = in_EAX + 0x50;
  unaff_ESI[0xc] = *(undefined4 *)(in_EAX + 0x78);
  unaff_ESI[0xb] = in_EAX + 0x7c;
  *unaff_ESI = 0;
  unaff_ESI[1] = param_1;
  FUN_00490560(unaff_ESI,in_EAX);
  return;
}


// ==== 0x490530 FUN_00490530

void FUN_00490530(void)

{
  void *pvVar1;
  int extraout_EDX;
  
  FUN_00490730();
  pvVar1 = *(void **)(extraout_EDX + 0xc);
  if (pvVar1 != (void *)0x0) {
    eh_vector_destructor_iterator(pvVar1,0xc0,*(int *)((int)pvVar1 + -0x10),FUN_00401db0);
    _free((void *)((int)pvVar1 + -0x10));
  }
  return;
}


// ==== 0x490560 FUN_00490560

void FUN_00490560(int param_1,int *param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  byte *pbVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int *piVar10;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006854a3;
  local_c = ExceptionList;
  puVar7 = (undefined4 *)0x0;
  ExceptionList = &local_c;
  *(int **)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (*param_2 != 0) {
    do {
      pbVar5 = (byte *)*param_2;
      bVar1 = *pbVar5;
      iVar9 = -1;
      if (bVar1 != 0) {
        do {
          iVar9 = iVar9 * 0x21 + (uint)bVar1;
          bVar1 = pbVar5[1];
          pbVar5 = pbVar5 + 1;
        } while (bVar1 != 0);
        if (iVar9 == 0) break;
      }
      puVar8 = DAT_0078e974;
      if (puVar7 != (undefined4 *)0x0) {
        puVar8 = (undefined4 *)*puVar7;
      }
      puVar2 = (undefined4 *)NullUpdate_ret();
      puVar7 = puVar8;
      while( true ) {
        if (puVar7 == puVar2) goto LAB_004905db;
        if (puVar7[4] == iVar9) break;
        puVar7 = (undefined4 *)*puVar7;
      }
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    } while( true );
  }
LAB_004905db:
  iVar9 = *(int *)(param_1 + 0x10);
  if (iVar9 != 0) {
    piVar3 = _malloc(iVar9 * 0xc0 + 0x10);
    iVar6 = 0;
    local_4 = 0;
    if (piVar3 == (int *)0x0) {
      piVar10 = (int *)0x0;
    }
    else {
      piVar10 = piVar3 + 4;
      *piVar3 = iVar9;
      eh_vector_constructor_iterator(piVar10,0xc0,iVar9,FUN_00401d90,FUN_00401db0);
    }
    *(int **)(param_1 + 0xc) = piVar10;
    puVar7 = (undefined4 *)0x0;
    do {
      pbVar5 = (byte *)**(undefined4 **)(param_1 + 8);
      bVar1 = *pbVar5;
      iVar9 = -1;
      if (bVar1 != 0) {
        do {
          iVar9 = iVar9 * 0x21 + (uint)bVar1;
          bVar1 = pbVar5[1];
          pbVar5 = pbVar5 + 1;
        } while (bVar1 != 0);
        if (iVar9 == 0) break;
      }
      puVar8 = DAT_0078e974;
      if (puVar7 != (undefined4 *)0x0) {
        puVar8 = (undefined4 *)*puVar7;
      }
      puVar2 = (undefined4 *)NullUpdate_ret();
      puVar7 = puVar8;
      while( true ) {
        if (puVar7 == puVar2) goto LAB_0049067b;
        if (puVar7[4] == iVar9) break;
        puVar7 = (undefined4 *)*puVar7;
      }
      *(undefined4 **)(*(int *)(param_1 + 0xc) + 0x1c + iVar6) = puVar7;
      *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10 + iVar6) = 1;
      iVar6 = iVar6 + 0xc0;
    } while( true );
  }
LAB_0049067b:
  *(undefined1 *)(param_1 + 0x14) = 0;
  FUN_004906d0(param_1);
  uVar4 = Texture_FindByHash(*(undefined4 *)(*(int *)(param_1 + 8) + 0xc),1,0);
  *(undefined4 *)(param_1 + 0x18) = uVar4;
  ExceptionList = local_c;
  return;
}


// ==== 0x4906d0 FUN_004906d0

void FUN_004906d0(int param_1)

{
  undefined4 local_8;
  
  if (*(char *)(param_1 + 0x14) == '\0') {
    local_8 = 0;
    if (0 < *(int *)(param_1 + 0x10)) {
      do {
        ParticleEmitter_Queue();
        local_8 = local_8 + 1;
      } while (local_8 < *(int *)(param_1 + 0x10));
    }
    *(undefined1 *)(param_1 + 0x14) = 1;
  }
  return;
}


// ==== 0x490730 FUN_00490730

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00490730(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (*(char *)(param_2 + 0x14) != '\0') {
    iVar3 = 0;
    if (0 < *(int *)(param_2 + 0x10)) {
      iVar4 = 0;
      do {
        iVar1 = *(int *)(*(int *)(param_2 + 0xc) + iVar4);
        piVar2 = *(int **)(*(int *)(param_2 + 0xc) + iVar4 + 4);
        *piVar2 = iVar1;
        *(int **)(iVar1 + 4) = piVar2;
        _DAT_0078e9d0 = _DAT_0078e9d0 + -1;
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0xc0;
      } while (iVar3 < *(int *)(param_2 + 0x10));
    }
    *(undefined1 *)(param_2 + 0x14) = 0;
  }
  return;
}


// ==== 0x490770 FUN_00490770

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00490770(int *param_1,undefined4 param_2,float param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  int iVar13;
  bool bVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  float10 fVar18;
  uint local_1b4;
  float local_190;
  float local_18c;
  float local_188;
  int local_170;
  uint local_168;
  float local_160;
  float local_15c;
  float local_158;
  float local_130;
  float local_12c;
  float local_128;
  float local_120;
  float local_11c;
  float local_118;
  undefined4 local_114;
  float local_110;
  float local_10c;
  float local_108;
  undefined4 local_104;
  float local_100;
  float local_fc;
  float local_f8;
  undefined4 local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  undefined4 local_e4;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float afStack_a0 [17];
  float afStack_5c [11];
  undefined1 auStack_30 [44];
  
  puVar9 = DAT_007355b4;
  puVar1 = DAT_007355b4 + 0x10;
  if (DAT_007355b8 <= puVar1) {
    DAT_007355c4 = 1;
    DAT_007355c8 = DAT_007355c8 + 0x40;
    return;
  }
  bVar14 = DAT_007355b4 != (undefined4 *)0x0;
  DAT_007355b4 = puVar1;
  if (bVar14) {
    ePoly__ePoly();
    local_1b4 = 0;
    local_168 = 1;
    if (param_4 == 0) {
      *puVar9 = 0x3f800000;
      puVar9[1] = 0;
      puVar9[2] = 0;
      puVar9[3] = 0;
      puVar9[4] = 0;
      puVar9[5] = 0x3f800000;
      puVar9[6] = 0;
      puVar9[7] = 0;
      puVar9[8] = 0;
      puVar9[9] = 0;
      puVar9[10] = 0x3f800000;
      puVar9[0xb] = 0;
      puVar9[0xc] = 0;
      puVar9[0xd] = 0;
      puVar9[0xe] = 0;
      puVar9[0xf] = 0x3f800000;
    }
    else {
      bMatrixCopy_b();
    }
    fVar15 = (float10)LinearTable__Lookup11(param_1 + 9,param_3);
    fVar16 = (float10)LinearTable__Lookup11(param_1 + 0xb,param_3);
    iVar2 = *(int *)(param_1[2] + 4);
    fVar5 = param_3 * *(float *)(param_1[2] + 8);
    fVar17 = (float10)FUN_004387e0(fVar5);
    if ((float10)fVar5 < fVar17) {
      fVar17 = fVar17 - (float10)_K_ONE;
    }
    local_170 = 0;
    if (-1 < *(int *)(param_1[2] + 4)) {
      do {
        uVar10 = local_1b4;
        iVar13 = *param_1;
        if (iVar13 == 0) {
          fVar3 = *(float *)(param_1[1] + 0xc);
        }
        else {
          iVar4 = *(int *)(iVar13 + 8);
          if (iVar4 == 0) {
LAB_004908d1:
            fVar3 = (float)(*(int *)(iVar13 + 4) + -1);
          }
          else if (iVar4 == 1) {
            fVar3 = (float)*(int *)(iVar13 + 4);
          }
          else {
            if (iVar4 == 2) goto LAB_004908d1;
            fVar3 = 0.0;
          }
        }
        fVar3 = ((float)local_170 * (float)((fVar16 - (float10)(float)fVar15) / (float10)iVar2) +
                (float)fVar15) * fVar3;
        if (iVar13 == 0) {
          FUN_0059d350(&fStack_d0,fVar3,0);
          local_160 = fStack_d0;
          local_15c = fStack_cc;
          local_158 = fStack_c8;
          FUN_0059d350(&fStack_e0,fVar3,1);
          local_190 = fStack_e0;
          local_18c = fStack_dc;
          local_188 = fStack_d8;
          FUN_0059d350(&fStack_c0,fVar3,2);
          local_130 = fStack_c0;
          local_12c = fStack_bc;
          local_128 = fStack_b8;
        }
        else {
          FUN_005829e0(fVar3);
          FUN_00582a90(fVar3);
          FUN_00582b50(fVar3);
        }
        local_158 = local_158 + *(float *)(param_1[2] + 0x18);
        bNormalize3();
        fVar3 = local_188 * 0.0 - local_18c;
        fVar6 = local_190 - local_188 * 0.0;
        fVar7 = local_18c * 0.0 - local_190 * 0.0;
        bNormalize3();
        fVar8 = (local_130 * fVar3 + local_12c * fVar6 + local_128 * fVar7) *
                *(float *)(param_1[2] + 0x1c);
        fVar3 = fVar3 * fVar8;
        fVar6 = fVar8 * fVar6;
        fVar7 = fVar8 * fVar7 + _K_ONE;
        fVar8 = local_188 * fVar6 - local_18c * fVar7;
        fVar7 = local_190 * fVar7 - local_188 * fVar3;
        fVar3 = local_18c * fVar3 - local_190 * fVar6;
        bNormalize3();
        bNormalize3();
        if (local_170 == 0) {
          local_100 = local_190;
          local_fc = local_18c;
          local_f0 = local_160;
          local_ec = local_15c;
          local_f8 = local_188;
          local_114 = 0;
          local_104 = 0;
          local_f4 = 0;
          local_e4 = 0x3f800000;
          local_120 = fVar8;
          local_11c = fVar7;
          local_118 = fVar3;
          local_110 = local_18c * fVar3 - local_188 * fVar7;
          local_10c = local_188 * fVar8 - local_190 * fVar3;
          local_108 = local_190 * fVar7 - local_18c * fVar8;
          local_e8 = local_158;
          D3DXMatrixMultiply(&local_120,&local_120,puVar9);
          iVar13 = 0;
          local_1b4 = 0;
          if (0 < param_1[4]) {
            do {
              if (*(int *)(param_1[3] + iVar13 + 0x10) == 1) {
                if (*(float *)(param_1[2] + 0x58) <= param_3) {
                  *(undefined4 *)(param_1[3] + iVar13 + 0x10) = 0;
                }
                else {
                  bMatrixCopy_b();
                }
              }
              local_1b4 = local_1b4 + 1;
              iVar13 = iVar13 + 0xc0;
            } while ((int)local_1b4 < param_1[4]);
          }
        }
        iVar13 = param_1[2];
        fVar6 = (float)local_170 / (float)*(int *)(iVar13 + 4);
        fVar18 = (float10)LinearTable__Lookup11(param_1 + 7,fVar6);
        fVar18 = fVar18 * (float10)*(float *)(iVar13 + 0x10) * (float10)_K_HALF;
        afStack_a0[uVar10 * 4] = (float)((float10)local_160 + (float10)fVar8 * fVar18);
        afStack_a0[uVar10 * 4 + 1] = local_15c + (float)(fVar18 * (float10)fVar7);
        afStack_a0[uVar10 * 4 + 2] =
             (float)(fVar18 * (float10)fVar3) + *(float *)(iVar13 + 0x14) + local_158;
        afStack_a0[local_168 * 4] = (float)((float10)local_160 - (float10)fVar8 * fVar18);
        afStack_a0[local_168 * 4 + 1] = local_15c - (float)(fVar18 * (float10)fVar7);
        afStack_a0[local_168 * 4 + 2] =
             (local_158 - (float)(fVar18 * (float10)fVar3)) + *(float *)(iVar13 + 0x14);
        fVar6 = fVar6 + (float)((float10)fVar5 - fVar17);
        afStack_5c[uVar10 * 3] = fVar6;
        afStack_5c[local_168 * 3] = fVar6;
        uVar11 = _ftol_nocw();
        auStack_30[uVar10 * 4] = uVar11;
        uVar12 = _ftol_nocw();
        auStack_30[uVar10 * 4 + 1] = uVar12;
        uVar12 = _ftol_nocw();
        auStack_30[uVar10 * 4 + 2] = uVar12;
        uVar12 = _ftol_nocw();
        auStack_30[uVar10 * 4 + 3] = uVar12;
        auStack_30[local_168 * 4] = uVar11;
        auStack_30[local_168 * 4 + 1] = auStack_30[uVar10 * 4 + 1];
        auStack_30[local_168 * 4 + 2] = auStack_30[uVar10 * 4 + 2];
        auStack_30[local_168 * 4 + 3] = auStack_30[uVar10 * 4 + 3];
        local_1b4 = uVar10 ^ 3;
        local_168 = local_168 ^ 3;
        if (0 < local_170) {
          FUN_0040c300(param_1[6],puVar9,0);
        }
        local_170 = local_170 + 2;
      } while (local_170 <= *(int *)(param_1[2] + 4));
    }
  }
  return;
}


// ==== 0x490ea0 ZonePreviewCameraMover::ctor

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] camera V (G+C) docs/re/camera.md */

undefined4 * ZonePreviewCameraMover__ctor(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  float *pfVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int iVar11;
  float *pfVar12;
  float *pfVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  void *pvVar21;
  int iVar22;
  undefined4 *puVar23;
  bool bVar24;
  float10 fVar25;
  float10 fVar26;
  float local_80;
  float local_7c;
  float local_78;
  float local_70;
  float local_6c;
  float local_68;
  float local_60;
  float local_5c;
  float local_58;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  pcStack_18 = FUN_0068636d;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  CameraMover__ctor();
  puVar23 = param_1 + 0x1b;
  *param_1 = &PTR_FUN_006c7b50;
  param_1[0x12] = 0;
  param_1[0x16] = 0;
  param_1[0x20] = 1;
  param_1[0x1d] = 2;
  *puVar23 = 100;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x1c] = 0;
  param_1[0x21] = 0x4000;
  param_1[0x26] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x2c] = 1;
  param_1[0x29] = 2;
  param_1[0x27] = 100;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x28] = 0;
  param_1[0x2d] = 0x4000;
  param_1[0x32] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  puVar1 = param_1 + 0x33;
  param_1[0x38] = 1;
  param_1[0x35] = 2;
  *puVar1 = 100;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x34] = 0;
  param_1[0x39] = 0x4000;
  param_1[0x3e] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x44] = 1;
  param_1[0x41] = 2;
  param_1[0x3f] = 100;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x40] = 0;
  param_1[0x45] = 0x4000;
  param_1[0x4a] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  pfVar13 = (float *)(param_1 + 0x4b);
  *pfVar13 = 0.0;
  param_1[0x4c] = 0;
  pfVar2 = (float *)(param_1 + 0x4d);
  *pfVar2 = 0.0;
  param_1[0x4e] = 0;
  uVar3 = DAT_006fbae0;
  local_14._0_1_ = 4;
  local_14._1_3_ = 0;
  param_1[0x56] = &DAT_006fbae4;
  param_1[0x57] = uVar3;
  uVar3 = DAT_006fbb0c;
  param_1[0x58] = &DAT_006fbb10;
  param_1[0x59] = uVar3;
  uVar3 = DAT_006fbb38;
  param_1[0x5a] = &DAT_006fbb3c;
  param_1[0x5b] = uVar3;
  param_1[0x4f] = puVar23;
  param_1[0x50] = 0;
  FUN_00490560(param_1 + 0x4f,&PTR_s_ZONE_PREVIEW_006fbac0);
  param_1[0x104] = 0;
  param_1[0x105] = 0;
  param_1[0x106] = 0;
  param_1[0x107] = 0;
  param_1[0x109] = 0;
  param_1[0x10a] = 0;
  param_1[0x10b] = 0;
  FUN_00440740();
  fVar8 = _K_ONE / 300.0;
  local_14 = CONCAT31(local_14._1_3_,6);
  param_1[0x14] = fVar8 * 3.0 * *(float *)(param_3 + 0x10);
  param_1[0x15] = fVar8 * 1.0 * *(float *)(param_3 + 0x10);
  fVar8 = 0.25 / ((float)param_1[0x14] + 0.25);
  fVar10 = 20.0 / *(float *)(param_3 + 0x10);
  fVar9 = (_K_ONE - fVar10) - fVar8;
  *pfVar13 = fVar9;
  param_1[0x4c] = fVar8 - fVar9 * 0.0;
  fVar10 = fVar10 + fVar8;
  fVar8 = _K_ONE - fVar10;
  *pfVar2 = fVar8;
  param_1[0x4e] = fVar10 - fVar8 * 0.0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  FUN_00494180(param_1 + 0x5c,puVar23,puVar1,param_1 + 0x3f,pfVar13);
  FUN_00493c70(param_3,param_1 + 0x5c,puVar1,puVar23,param_1 + 0x27,pfVar13,pfVar2,param_1 + 0x17,4)
  ;
  iVar22 = param_1[7];
  uVar3 = *(undefined4 *)(iVar22 + 100);
  uVar4 = *(undefined4 *)(iVar22 + 0x68);
  param_1[0x110] = *(undefined4 *)(iVar22 + 0x60);
  param_1[0x111] = uVar3;
  param_1[0x112] = uVar4;
  iVar22 = param_1[7];
  uVar3 = *(undefined4 *)(iVar22 + 0x44);
  uVar4 = *(undefined4 *)(iVar22 + 0x48);
  param_1[0x10c] = *(undefined4 *)(iVar22 + 0x40);
  param_1[0x10d] = uVar3;
  param_1[0x10e] = uVar4;
  iVar22 = param_1[7];
  iVar11 = param_1[0x35];
  fVar8 = DAT_0073457c * *(float *)(iVar22 + 0x1e0) + *(float *)(iVar22 + 0x40);
  fVar9 = DAT_0073457c * *(float *)(iVar22 + 0x1e4) + *(float *)(iVar22 + 0x44);
  fVar10 = DAT_0073457c * *(float *)(iVar22 + 0x1e8) + *(float *)(iVar22 + 0x48);
  fVar18 = DAT_0073457c * *(float *)(iVar22 + 0x200) + *(float *)(iVar22 + 0x60);
  fVar19 = DAT_0073457c * *(float *)(iVar22 + 0x204) + *(float *)(iVar22 + 100);
  fVar20 = DAT_0073457c * *(float *)(iVar22 + 0x208) + *(float *)(iVar22 + 0x68);
  if (iVar11 == 0) {
LAB_00491218:
    fVar5 = (float)(param_1[0x34] + -1);
  }
  else if (iVar11 == 1) {
    fVar5 = (float)(int)param_1[0x34];
  }
  else {
    if (iVar11 == 2) goto LAB_00491218;
    fVar5 = 0.0;
  }
  FUN_005829e0((*pfVar13 * 0.0 + (float)param_1[0x4c]) * fVar5);
  iVar22 = param_1[0x35];
  if (iVar22 == 0) {
LAB_00491261:
    fVar5 = (float)(param_1[0x34] + -1);
  }
  else if (iVar22 == 1) {
    fVar5 = (float)(int)param_1[0x34];
  }
  else {
    if (iVar22 == 2) goto LAB_00491261;
    fVar5 = 0.0;
  }
  FUN_00582a90((*pfVar13 * 0.0 + (float)param_1[0x4c]) * fVar5);
  iVar22 = param_1[0x35];
  if (iVar22 == 0) {
LAB_004912a8:
    fVar5 = (float)(param_1[0x34] + -1);
  }
  else if (iVar22 == 1) {
    fVar5 = (float)(int)param_1[0x34];
  }
  else {
    if (iVar22 == 2) goto LAB_004912a8;
    fVar5 = 0.0;
  }
  iVar22 = param_1[7];
  fVar14 = *(float *)(iVar22 + 0x1e0) * 0.25;
  fVar6 = *(float *)(iVar22 + 0x1e4) * 0.25;
  fVar7 = *(float *)(iVar22 + 0x1e8) * 0.25;
  fVar5 = ((((float)param_1[0x4c] + *pfVar13) - (*pfVar13 * 0.0 + (float)param_1[0x4c])) /
          (float)param_1[0x14]) * fVar5 * 0.25;
  pvVar21 = _malloc(0x90);
  if (pvVar21 == (void *)0x0) {
    iVar22 = 0;
  }
  else {
    iVar22 = CameraMoverBase_InitFields(0x3f800000,0x3f800000);
  }
  param_1[0xb] = iVar22;
  *(undefined4 *)(iVar22 + 0x24) = 0x3e800000;
  *(undefined4 *)(iVar22 + 0x84) = 0x3e800000;
  *(undefined4 *)(iVar22 + 0x54) = 0x3e800000;
  iVar22 = param_1[0xb];
  *(undefined2 *)(iVar22 + 0x2e) = 0;
  *(undefined2 *)(iVar22 + 0x5e) = 0;
  *(undefined2 *)(iVar22 + 0x8e) = 0;
  pfVar12 = (float *)param_1[0xb];
  *pfVar12 = fVar8;
  if (fVar8 != pfVar12[2]) {
    *(undefined2 *)(pfVar12 + 0xb) = 2;
  }
  pfVar12[0xc] = fVar9;
  if (fVar9 != pfVar12[0xe]) {
    *(undefined2 *)(pfVar12 + 0x17) = 2;
  }
  pfVar12[0x18] = fVar10;
  if (fVar10 != pfVar12[0x1a]) {
    *(undefined2 *)(pfVar12 + 0x23) = 2;
  }
  iVar22 = param_1[0xb];
  *(float *)(iVar22 + 4) = fVar14;
  if (fVar14 != *(float *)(iVar22 + 0xc)) {
    *(undefined2 *)(iVar22 + 0x2c) = 2;
  }
  *(float *)(iVar22 + 0x34) = fVar6;
  if (fVar6 != *(float *)(iVar22 + 0x3c)) {
    *(undefined2 *)(iVar22 + 0x5c) = 2;
  }
  *(float *)(iVar22 + 100) = fVar7;
  if (fVar7 != *(float *)(iVar22 + 0x6c)) {
    *(undefined2 *)(iVar22 + 0x8c) = 2;
  }
  pfVar12 = (float *)param_1[0xb];
  pfVar12[2] = local_70;
  if (local_70 != *pfVar12) {
    *(undefined2 *)(pfVar12 + 0xb) = 2;
  }
  pfVar12[0xe] = local_6c;
  if (local_6c != pfVar12[0xc]) {
    *(undefined2 *)(pfVar12 + 0x17) = 2;
  }
  pfVar12[0x1a] = local_68;
  if (local_68 != pfVar12[0x18]) {
    *(undefined2 *)(pfVar12 + 0x23) = 2;
  }
  iVar22 = param_1[0xb];
  *(float *)(iVar22 + 0x3c) = local_5c * fVar5;
  *(float *)(iVar22 + 0xc) = local_60 * fVar5;
  *(float *)(iVar22 + 0x6c) = local_58 * fVar5;
  iVar22 = param_1[0x29];
  if (iVar22 == 0) {
LAB_0049147b:
    fVar6 = (float)(param_1[0x28] + -1);
  }
  else if (iVar22 == 1) {
    fVar6 = (float)(int)param_1[0x28];
  }
  else {
    if (iVar22 == 2) goto LAB_0049147b;
    fVar6 = 0.0;
  }
  FUN_005829e0((*pfVar2 * 0.0 + (float)param_1[0x4e]) * fVar6);
  iVar22 = param_1[0x29];
  if (iVar22 == 0) {
LAB_004914c3:
    fVar6 = (float)(param_1[0x28] + -1);
  }
  else if (iVar22 == 1) {
    fVar6 = (float)(int)param_1[0x28];
  }
  else {
    if (iVar22 == 2) goto LAB_004914c3;
    fVar6 = 0.0;
  }
  FUN_00582a90((*pfVar2 * 0.0 + (float)param_1[0x4e]) * fVar6);
  iVar22 = param_1[0x29];
  if (iVar22 == 0) {
LAB_0049150a:
    fVar6 = (float)(param_1[0x28] + -1);
  }
  else if (iVar22 == 1) {
    fVar6 = (float)(int)param_1[0x28];
  }
  else {
    if (iVar22 == 2) goto LAB_0049150a;
    fVar6 = 0.0;
  }
  iVar22 = param_1[7];
  fVar17 = *(float *)(iVar22 + 0x200) * 0.25;
  fVar15 = *(float *)(iVar22 + 0x204) * 0.25;
  fVar16 = *(float *)(iVar22 + 0x208) * 0.25;
  fVar6 = ((((float)param_1[0x4e] + *pfVar2) - (*pfVar2 * 0.0 + (float)param_1[0x4e])) /
          (float)param_1[0x14]) * fVar6 * 0.25;
  fVar7 = local_60 * fVar5 * fVar6;
  fVar14 = local_5c * fVar5 * fVar6;
  fVar6 = local_58 * fVar5 * fVar6;
  pvVar21 = _malloc(0x90);
  if (pvVar21 == (void *)0x0) {
    iVar22 = 0;
  }
  else {
    iVar22 = CameraMoverBase_InitFields(0x3f800000,0x3f800000);
  }
  param_1[0xc] = iVar22;
  *(undefined4 *)(iVar22 + 0x24) = 0x3e800000;
  *(undefined4 *)(iVar22 + 0x84) = 0x3e800000;
  *(undefined4 *)(iVar22 + 0x54) = 0x3e800000;
  iVar22 = param_1[0xc];
  *(undefined2 *)(iVar22 + 0x2e) = 0;
  *(undefined2 *)(iVar22 + 0x5e) = 0;
  *(undefined2 *)(iVar22 + 0x8e) = 0;
  pfVar12 = (float *)param_1[0xc];
  *pfVar12 = fVar18;
  if (fVar18 != pfVar12[2]) {
    *(undefined2 *)(pfVar12 + 0xb) = 2;
  }
  pfVar12[0xc] = fVar19;
  if (fVar19 != pfVar12[0xe]) {
    *(undefined2 *)(pfVar12 + 0x17) = 2;
  }
  pfVar12[0x18] = fVar20;
  if (fVar20 != pfVar12[0x1a]) {
    *(undefined2 *)(pfVar12 + 0x23) = 2;
  }
  iVar22 = param_1[0xc];
  *(float *)(iVar22 + 4) = fVar17;
  if (fVar17 != *(float *)(iVar22 + 0xc)) {
    *(undefined2 *)(iVar22 + 0x2c) = 2;
  }
  *(float *)(iVar22 + 0x34) = fVar15;
  if (fVar15 != *(float *)(iVar22 + 0x3c)) {
    *(undefined2 *)(iVar22 + 0x5c) = 2;
  }
  *(float *)(iVar22 + 100) = fVar16;
  if (fVar16 != *(float *)(iVar22 + 0x6c)) {
    *(undefined2 *)(iVar22 + 0x8c) = 2;
  }
  pfVar12 = (float *)param_1[0xc];
  pfVar12[2] = local_70;
  if (local_70 != *pfVar12) {
    *(undefined2 *)(pfVar12 + 0xb) = 2;
  }
  pfVar12[0xe] = local_6c;
  if (local_6c != pfVar12[0xc]) {
    *(undefined2 *)(pfVar12 + 0x17) = 2;
  }
  pfVar12[0x1a] = local_68;
  if (local_68 != pfVar12[0x18]) {
    *(undefined2 *)(pfVar12 + 0x23) = 2;
  }
  iVar22 = param_1[0xc];
  *(float *)(iVar22 + 0x3c) = fVar14;
  *(float *)(iVar22 + 0xc) = fVar7;
  *(float *)(iVar22 + 0x6c) = fVar6;
  iVar22 = param_1[0x35];
  if (iVar22 == 0) {
LAB_004916ef:
    fVar5 = (float)(param_1[0x34] + -1);
  }
  else if (iVar22 == 1) {
    fVar5 = (float)(int)param_1[0x34];
  }
  else {
    if (iVar22 == 2) goto LAB_004916ef;
    fVar5 = 0.0;
  }
  FUN_005829e0(((float)param_1[0x4c] + *pfVar13) * fVar5);
  iVar22 = param_1[0x35];
  if (iVar22 == 0) {
LAB_00491731:
    fVar5 = (float)(param_1[0x34] + -1);
  }
  else if (iVar22 == 1) {
    fVar5 = (float)(int)param_1[0x34];
  }
  else {
    if (iVar22 == 2) goto LAB_00491731;
    fVar5 = 0.0;
  }
  FUN_00582a90(((float)param_1[0x4c] + *pfVar13) * fVar5);
  iVar22 = param_1[0x35];
  if (iVar22 == 0) {
LAB_00491771:
    fVar5 = (float)(param_1[0x34] + -1);
  }
  else if (iVar22 == 1) {
    fVar5 = (float)(int)param_1[0x34];
  }
  else {
    if (iVar22 == 2) goto LAB_00491771;
    fVar5 = 0.0;
  }
  iVar22 = param_1[0x41];
  fVar5 = ((((float)param_1[0x4c] + *pfVar13) - (*pfVar13 * 0.0 + (float)param_1[0x4c])) /
          (float)param_1[0x14]) * fVar5 * 0.4;
  fVar17 = fVar17 * fVar5;
  fVar15 = fVar15 * fVar5;
  fVar16 = fVar16 * fVar5;
  if (iVar22 == 0) {
LAB_004917d6:
    fVar5 = (float)(param_1[0x40] + -1);
  }
  else if (iVar22 == 1) {
    fVar5 = (float)(int)param_1[0x40];
  }
  else {
    if (iVar22 == 2) goto LAB_004917d6;
    fVar5 = 0.0;
  }
  FUN_005829e0(((float)param_1[0x4c] + *pfVar13) * fVar5);
  iVar22 = param_1[0x41];
  if (iVar22 == 0) {
LAB_00491813:
    fVar5 = (float)(param_1[0x40] + -1);
  }
  else if (iVar22 == 1) {
    fVar5 = (float)(int)param_1[0x40];
  }
  else {
    if (iVar22 == 2) goto LAB_00491813;
    fVar5 = 0.0;
  }
  FUN_00582a90(((float)param_1[0x4c] + *pfVar13) * fVar5);
  iVar22 = param_1[0x41];
  if (iVar22 == 0) {
LAB_00491854:
    fVar5 = (float)(param_1[0x40] + -1);
  }
  else if (iVar22 == 1) {
    fVar5 = (float)(int)param_1[0x40];
  }
  else {
    if (iVar22 == 2) goto LAB_00491854;
    fVar5 = 0.0;
  }
  fVar5 = (-1.0 / (float)param_1[0x15]) *
          (((float)param_1[0x4c] + *pfVar13) - (*pfVar13 * 0.0 + (float)param_1[0x4c])) * fVar5 *
          0.4;
  fVar7 = fVar7 * fVar5;
  fVar14 = fVar14 * fVar5;
  fVar6 = fVar6 * fVar5;
  pvVar21 = _malloc(0x90);
  if (pvVar21 == (void *)0x0) {
    iVar22 = 0;
  }
  else {
    iVar22 = CameraMoverBase_InitFields(0x3f800000,0x3f800000);
  }
  param_1[0xd] = iVar22;
  *(undefined4 *)(iVar22 + 0x24) = 0x3ecccccd;
  *(undefined4 *)(iVar22 + 0x84) = 0x3ecccccd;
  *(undefined4 *)(iVar22 + 0x54) = 0x3ecccccd;
  iVar22 = param_1[0xd];
  *(undefined2 *)(iVar22 + 0x2e) = 0;
  *(undefined2 *)(iVar22 + 0x5e) = 0;
  *(undefined2 *)(iVar22 + 0x8e) = 0;
  pfVar12 = (float *)param_1[0xd];
  *pfVar12 = local_80;
  if (local_80 != pfVar12[2]) {
    *(undefined2 *)(pfVar12 + 0xb) = 2;
  }
  pfVar12[0xc] = local_7c;
  if (local_7c != pfVar12[0xe]) {
    *(undefined2 *)(pfVar12 + 0x17) = 2;
  }
  pfVar12[0x18] = local_78;
  if (local_78 != pfVar12[0x1a]) {
    *(undefined2 *)(pfVar12 + 0x23) = 2;
  }
  iVar22 = param_1[0xd];
  *(float *)(iVar22 + 4) = fVar17;
  if (fVar17 != *(float *)(iVar22 + 0xc)) {
    *(undefined2 *)(iVar22 + 0x2c) = 2;
  }
  *(float *)(iVar22 + 0x34) = fVar15;
  if (fVar15 != *(float *)(iVar22 + 0x3c)) {
    *(undefined2 *)(iVar22 + 0x5c) = 2;
  }
  *(float *)(iVar22 + 100) = fVar16;
  if (fVar16 != *(float *)(iVar22 + 0x6c)) {
    *(undefined2 *)(iVar22 + 0x8c) = 2;
  }
  pfVar12 = (float *)param_1[0xd];
  pfVar12[2] = local_70;
  if (local_70 != *pfVar12) {
    *(undefined2 *)(pfVar12 + 0xb) = 2;
  }
  pfVar12[0xe] = local_6c;
  if (local_6c != pfVar12[0xc]) {
    *(undefined2 *)(pfVar12 + 0x17) = 2;
  }
  pfVar12[0x1a] = local_68;
  if (local_68 != pfVar12[0x18]) {
    *(undefined2 *)(pfVar12 + 0x23) = 2;
  }
  iVar22 = param_1[0xd];
  *(float *)(iVar22 + 0x3c) = fVar14;
  *(float *)(iVar22 + 0xc) = fVar7;
  *(float *)(iVar22 + 0x6c) = fVar6;
  iVar22 = param_1[0x1d];
  if (iVar22 == 0) {
LAB_004919f9:
    fVar5 = (float)(param_1[0x1c] + -1);
  }
  else if (iVar22 == 1) {
    fVar5 = (float)(int)param_1[0x1c];
  }
  else {
    if (iVar22 == 2) goto LAB_004919f9;
    fVar5 = 0.0;
  }
  FUN_005829e0(((float)param_1[0x4e] + *pfVar2) * fVar5);
  iVar22 = param_1[0x1d];
  if (iVar22 == 0) {
LAB_00491a3c:
    fVar5 = (float)(param_1[0x1c] + -1);
  }
  else if (iVar22 == 1) {
    fVar5 = (float)(int)param_1[0x1c];
  }
  else {
    if (iVar22 == 2) goto LAB_00491a3c;
    fVar5 = 0.0;
  }
  FUN_005829e0(((float)param_1[0x4e] + *pfVar2) * fVar5);
  iVar22 = param_1[0x1d];
  if (iVar22 == 0) {
LAB_00491a7c:
    fVar5 = (float)(param_1[0x1c] + -1);
  }
  else if (iVar22 == 1) {
    fVar5 = (float)(int)param_1[0x1c];
  }
  else {
    if (iVar22 == 2) goto LAB_00491a7c;
    fVar5 = 0.0;
  }
  FUN_00582a90(((float)param_1[0x4e] + *pfVar2) * fVar5);
  iVar22 = param_1[0x1d];
  if (iVar22 == 0) {
LAB_00491abf:
    fVar5 = (float)(param_1[0x1c] + -1);
  }
  else if (iVar22 == 1) {
    fVar5 = (float)(int)param_1[0x1c];
  }
  else {
    if (iVar22 == 2) goto LAB_00491abf;
    fVar5 = 0.0;
  }
  FUN_00582a90(((float)param_1[0x4e] + *pfVar2) * fVar5);
  iVar22 = param_1[0x29];
  if (iVar22 == 0) {
LAB_00491b00:
    fVar5 = (float)(param_1[0x28] + -1);
  }
  else if (iVar22 == 1) {
    fVar5 = (float)(int)param_1[0x28];
  }
  else {
    if (iVar22 == 2) goto LAB_00491b00;
    fVar5 = 0.0;
  }
  iVar22 = param_1[0x1d];
  fVar5 = ((((float)param_1[0x4e] + *pfVar2) - (*pfVar2 * 0.0 + (float)param_1[0x4e])) /
          (float)param_1[0x14]) * fVar5 * 0.4;
  fVar17 = fVar17 * fVar5;
  fVar15 = fVar15 * fVar5;
  fVar16 = fVar16 * fVar5;
  if (iVar22 == 0) {
LAB_00491b64:
    fVar5 = (float)(param_1[0x1c] + -1);
  }
  else if (iVar22 == 1) {
    fVar5 = (float)(int)param_1[0x1c];
  }
  else {
    if (iVar22 == 2) goto LAB_00491b64;
    fVar5 = 0.0;
  }
  fVar5 = (-1.0 / (float)param_1[0x15]) *
          (((float)param_1[0x4e] + *pfVar2) - (*pfVar2 * 0.0 + (float)param_1[0x4e])) * fVar5 * 0.4;
  pvVar21 = _malloc(0x90);
  if (pvVar21 == (void *)0x0) {
    iVar22 = 0;
  }
  else {
    iVar22 = CameraMoverBase_InitFields(0x3f800000,0x3f800000);
  }
  param_1[0xe] = iVar22;
  *(undefined4 *)(iVar22 + 0x24) = 0x3ecccccd;
  *(undefined4 *)(iVar22 + 0x84) = 0x3ecccccd;
  *(undefined4 *)(iVar22 + 0x54) = 0x3ecccccd;
  iVar22 = param_1[0xe];
  *(undefined2 *)(iVar22 + 0x2e) = 0;
  *(undefined2 *)(iVar22 + 0x5e) = 0;
  *(undefined2 *)(iVar22 + 0x8e) = 0;
  pfVar12 = (float *)param_1[0xe];
  *pfVar12 = local_80;
  if (local_80 != pfVar12[2]) {
    *(undefined2 *)(pfVar12 + 0xb) = 2;
  }
  pfVar12[0xc] = local_7c;
  if (local_7c != pfVar12[0xe]) {
    *(undefined2 *)(pfVar12 + 0x17) = 2;
  }
  pfVar12[0x18] = local_78;
  if (local_78 != pfVar12[0x1a]) {
    *(undefined2 *)(pfVar12 + 0x23) = 2;
  }
  iVar22 = param_1[0xe];
  *(float *)(iVar22 + 4) = fVar17;
  if (fVar17 != *(float *)(iVar22 + 0xc)) {
    *(undefined2 *)(iVar22 + 0x2c) = 2;
  }
  *(float *)(iVar22 + 0x34) = fVar15;
  if (fVar15 != *(float *)(iVar22 + 0x3c)) {
    *(undefined2 *)(iVar22 + 0x5c) = 2;
  }
  *(float *)(iVar22 + 100) = fVar16;
  if (fVar16 != *(float *)(iVar22 + 0x6c)) {
    *(undefined2 *)(iVar22 + 0x8c) = 2;
  }
  pfVar12 = (float *)param_1[0xe];
  pfVar12[2] = local_70;
  if (local_70 != *pfVar12) {
    *(undefined2 *)(pfVar12 + 0xb) = 2;
  }
  pfVar12[0xe] = local_6c;
  if (local_6c != pfVar12[0xc]) {
    *(undefined2 *)(pfVar12 + 0x17) = 2;
  }
  pfVar12[0x1a] = local_68;
  if (local_68 != pfVar12[0x18]) {
    *(undefined2 *)(pfVar12 + 0x23) = 2;
  }
  iVar22 = param_1[0xe];
  *(float *)(iVar22 + 0x3c) = fVar14 * fVar5;
  *(float *)(iVar22 + 0xc) = fVar7 * fVar5;
  *(float *)(iVar22 + 0x6c) = fVar6 * fVar5;
  iVar22 = param_1[0x41];
  if (iVar22 == 0) {
LAB_00491d03:
    fVar5 = (float)(param_1[0x40] + -1);
  }
  else if (iVar22 == 1) {
    fVar5 = (float)(int)param_1[0x40];
  }
  else {
    if (iVar22 == 2) goto LAB_00491d03;
    fVar5 = 0.0;
  }
  FUN_005829e0((*pfVar13 * 0.0 + (float)param_1[0x4c]) * fVar5);
  iVar22 = param_1[0x41];
  if (iVar22 == 0) {
LAB_00491d4b:
    fVar5 = (float)(param_1[0x40] + -1);
  }
  else if (iVar22 == 1) {
    fVar5 = (float)(int)param_1[0x40];
  }
  else {
    if (iVar22 == 2) goto LAB_00491d4b;
    fVar5 = 0.0;
  }
  FUN_00582a90((*pfVar13 * 0.0 + (float)param_1[0x4c]) * fVar5);
  iVar22 = param_1[0x41];
  if (iVar22 == 0) {
LAB_00491d92:
    fVar5 = (float)(param_1[0x40] + -1);
  }
  else if (iVar22 == 1) {
    fVar5 = (float)(int)param_1[0x40];
  }
  else {
    if (iVar22 == 2) goto LAB_00491d92;
    fVar5 = 0.0;
  }
  iVar22 = param_1[7];
  fVar5 = (-1.0 / (float)param_1[0x15]) *
          (((float)param_1[0x4c] + *pfVar13) - (*pfVar13 * 0.0 + (float)param_1[0x4c])) * fVar5 *
          0.6;
  fVar17 = fVar17 * fVar5;
  fVar15 = fVar15 * fVar5;
  fVar16 = fVar16 * fVar5;
  fVar5 = *(float *)(iVar22 + 0x1e4);
  fVar6 = *(float *)(iVar22 + 0x1e8);
  fVar7 = *(float *)(iVar22 + 0x1e0);
  pvVar21 = _malloc(0x90);
  if (pvVar21 == (void *)0x0) {
    iVar22 = 0;
  }
  else {
    iVar22 = CameraMoverBase_InitFields(0x3f800000,0x3f800000);
  }
  param_1[0xf] = iVar22;
  *(undefined4 *)(iVar22 + 0x24) = 0x3f19999a;
  *(undefined4 *)(iVar22 + 0x84) = 0x3f19999a;
  *(undefined4 *)(iVar22 + 0x54) = 0x3f19999a;
  iVar22 = param_1[0xf];
  *(undefined2 *)(iVar22 + 0x2e) = 0;
  *(undefined2 *)(iVar22 + 0x5e) = 0;
  *(undefined2 *)(iVar22 + 0x8e) = 0;
  pfVar13 = (float *)param_1[0xf];
  *pfVar13 = local_80;
  if (local_80 != pfVar13[2]) {
    *(undefined2 *)(pfVar13 + 0xb) = 2;
  }
  pfVar13[0xc] = local_7c;
  if (local_7c != pfVar13[0xe]) {
    *(undefined2 *)(pfVar13 + 0x17) = 2;
  }
  pfVar13[0x18] = local_78;
  if (local_78 != pfVar13[0x1a]) {
    *(undefined2 *)(pfVar13 + 0x23) = 2;
  }
  iVar22 = param_1[0xf];
  *(float *)(iVar22 + 4) = fVar17;
  if (fVar17 != *(float *)(iVar22 + 0xc)) {
    *(undefined2 *)(iVar22 + 0x2c) = 2;
  }
  *(float *)(iVar22 + 0x34) = fVar15;
  if (fVar15 != *(float *)(iVar22 + 0x3c)) {
    *(undefined2 *)(iVar22 + 0x5c) = 2;
  }
  *(float *)(iVar22 + 100) = fVar16;
  if (fVar16 != *(float *)(iVar22 + 0x6c)) {
    *(undefined2 *)(iVar22 + 0x8c) = 2;
  }
  pfVar13 = (float *)param_1[0xf];
  pfVar13[2] = fVar8;
  if (fVar8 != *pfVar13) {
    *(undefined2 *)(pfVar13 + 0xb) = 2;
  }
  pfVar13[0xe] = fVar9;
  if (fVar9 != pfVar13[0xc]) {
    *(undefined2 *)(pfVar13 + 0x17) = 2;
  }
  pfVar13[0x1a] = fVar10;
  if (fVar10 != pfVar13[0x18]) {
    *(undefined2 *)(pfVar13 + 0x23) = 2;
  }
  iVar22 = param_1[0xf];
  *(float *)(iVar22 + 0x3c) = fVar5 * 0.6;
  *(float *)(iVar22 + 0xc) = fVar7 * 0.6;
  *(float *)(iVar22 + 0x6c) = fVar6 * 0.6;
  iVar22 = param_1[0x1d];
  if (iVar22 == 0) {
LAB_00491f6a:
    fVar8 = (float)(param_1[0x1c] + -1);
  }
  else if (iVar22 == 1) {
    fVar8 = (float)(int)param_1[0x1c];
  }
  else {
    if (iVar22 == 2) goto LAB_00491f6a;
    fVar8 = 0.0;
  }
  FUN_005829e0((*pfVar2 * 0.0 + (float)param_1[0x4e]) * fVar8);
  iVar22 = param_1[0x1d];
  if (iVar22 == 0) {
LAB_00491fb2:
    fVar8 = (float)(param_1[0x1c] + -1);
  }
  else if (iVar22 == 1) {
    fVar8 = (float)(int)param_1[0x1c];
  }
  else {
    if (iVar22 == 2) goto LAB_00491fb2;
    fVar8 = 0.0;
  }
  FUN_00582a90((*pfVar2 * 0.0 + (float)param_1[0x4e]) * fVar8);
  iVar22 = param_1[0x1d];
  if (iVar22 != 0) {
    if (iVar22 == 1) {
      fVar8 = (float)(int)param_1[0x1c];
      goto LAB_00492003;
    }
    if (iVar22 != 2) {
      fVar8 = 0.0;
      goto LAB_00492003;
    }
  }
  fVar8 = (float)(param_1[0x1c] + -1);
LAB_00492003:
  iVar22 = param_1[7];
  fVar5 = (-1.0 / (float)param_1[0x15]) *
          (((float)param_1[0x4e] + *pfVar2) - (*pfVar2 * 0.0 + (float)param_1[0x4e])) * fVar8 * 0.6;
  fVar8 = *(float *)(iVar22 + 0x204);
  fVar9 = *(float *)(iVar22 + 0x208);
  fVar10 = *(float *)(iVar22 + 0x200);
  pvVar21 = _malloc(0x90);
  if (pvVar21 == (void *)0x0) {
    iVar22 = 0;
  }
  else {
    iVar22 = CameraMoverBase_InitFields(0x3f800000,0x3f800000);
  }
  param_1[0x10] = iVar22;
  *(undefined4 *)(iVar22 + 0x24) = 0x3f19999a;
  *(undefined4 *)(iVar22 + 0x84) = 0x3f19999a;
  *(undefined4 *)(iVar22 + 0x54) = 0x3f19999a;
  iVar22 = param_1[0x10];
  *(undefined2 *)(iVar22 + 0x2e) = 0;
  *(undefined2 *)(iVar22 + 0x5e) = 0;
  *(undefined2 *)(iVar22 + 0x8e) = 0;
  pfVar13 = (float *)param_1[0x10];
  *pfVar13 = local_80;
  if (local_80 != pfVar13[2]) {
    *(undefined2 *)(pfVar13 + 0xb) = 2;
  }
  pfVar13[0xc] = local_7c;
  if (local_7c != pfVar13[0xe]) {
    *(undefined2 *)(pfVar13 + 0x17) = 2;
  }
  pfVar13[0x18] = local_78;
  if (local_78 != pfVar13[0x1a]) {
    *(undefined2 *)(pfVar13 + 0x23) = 2;
  }
  iVar22 = param_1[0x10];
  *(float *)(iVar22 + 4) = fVar17 * fVar5;
  if (fVar17 * fVar5 != *(float *)(iVar22 + 0xc)) {
    *(undefined2 *)(iVar22 + 0x2c) = 2;
  }
  *(float *)(iVar22 + 0x34) = fVar15 * fVar5;
  if (fVar15 * fVar5 != *(float *)(iVar22 + 0x3c)) {
    *(undefined2 *)(iVar22 + 0x5c) = 2;
  }
  *(float *)(iVar22 + 100) = fVar16 * fVar5;
  if (fVar16 * fVar5 != *(float *)(iVar22 + 0x6c)) {
    *(undefined2 *)(iVar22 + 0x8c) = 2;
  }
  pfVar13 = (float *)param_1[0x10];
  pfVar13[2] = fVar18;
  if (fVar18 != *pfVar13) {
    *(undefined2 *)(pfVar13 + 0xb) = 2;
  }
  pfVar13[0xe] = fVar19;
  if (fVar19 != pfVar13[0xc]) {
    *(undefined2 *)(pfVar13 + 0x17) = 2;
  }
  pfVar13[0x1a] = fVar20;
  if (fVar20 != pfVar13[0x18]) {
    *(undefined2 *)(pfVar13 + 0x23) = 2;
  }
  iVar22 = param_1[0x10];
  *(float *)(iVar22 + 0x3c) = fVar8 * 0.6;
  *(float *)(iVar22 + 0xc) = fVar10 * 0.6;
  *(float *)(iVar22 + 0x6c) = fVar9 * 0.6;
  puVar23 = _malloc(0x30);
  if (puVar23 == (undefined4 *)0x0) {
    puVar23 = (undefined4 *)0x0;
  }
  else {
    *puVar23 = 0;
    puVar23[1] = 0;
    puVar23[2] = 0;
    puVar23[3] = 0;
    puVar23[9] = 0x3f800000;
    puVar23[10] = 0x3f800000;
    *(undefined2 *)(puVar23 + 0xb) = 0;
    *(undefined2 *)((int)puVar23 + 0x2e) = 1;
  }
  param_1[0x11] = puVar23;
  *(undefined2 *)((int)puVar23 + 0x2e) = 0;
  *(undefined4 *)(param_1[0x11] + 0x24) = 0x3e800000;
  puVar23 = (undefined4 *)param_1[0x11];
  *puVar23 = 0x3f800000;
  if (puVar23[2] != 0x3f800000) {
    *(undefined2 *)(puVar23 + 0xb) = 2;
  }
  pfVar13 = (float *)param_1[0x11];
  pfVar13[2] = 1.0;
  if (*pfVar13 != 1.0) {
    *(undefined2 *)(pfVar13 + 0xb) = 2;
  }
  iVar22 = param_1[7];
  fVar25 = (float10)FUN_00564b10();
  fVar26 = (float10)FUN_00564b10();
  bVar24 = DAT_00735f5c == 0;
  param_1[0x13] = (float)((float10)(float)fVar25 / fVar26);
  if (bVar24) {
    *(undefined4 *)(iVar22 + 0x280) = 0;
    *(undefined4 *)(param_1[7] + 0x284) = 0;
  }
  ExceptionList = local_1c;
  return param_1;
}


