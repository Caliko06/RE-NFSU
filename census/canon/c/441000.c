// ==== 0x441030 FUN_00441030

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00441030(int param_1,int param_2,undefined4 param_3,float *param_4,float param_5,float param_6)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  char cVar5;
  float *unaff_ESI;
  float local_40;
  int *local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  local_30 = *unaff_ESI;
  local_2c = unaff_ESI[1];
  local_34 = unaff_ESI[2];
  local_28 = local_34;
  local_20 = local_30;
  local_1c = local_2c;
  local_18 = local_34;
  FUN_005677d0(param_5);
  local_40 = 999999.0;
  local_34 = 0.0;
  local_38 = 0.0;
  if (0 < *(int *)(param_1 + 0x2a0)) {
    local_3c = (int *)(param_1 + 0x20);
    do {
      iVar3 = *local_3c;
      cVar5 = FUN_00440560(&local_40,unaff_ESI,param_4,&local_20,&local_30,param_3);
      if (cVar5 != '\0') {
        local_34 = (float)iVar3;
      }
      local_38 = (float)((int)local_38 + 1);
      local_3c = local_3c + 1;
    } while ((int)local_38 < *(int *)(param_1 + 0x2a0));
  }
  local_30 = *param_4 - *unaff_ESI;
  local_2c = param_4[1] - unaff_ESI[1];
  local_28 = param_4[2] - unaff_ESI[2];
  local_38 = SQRT(local_28 * local_28 + local_30 * local_30 + local_2c * local_2c);
  if (local_38 <= local_40) {
    return 0;
  }
  if (param_2 == 0) {
    if ((*(byte *)((int)local_34 + 10) & 2) != 0) {
      local_34 = local_40 - param_5;
      FUN_005673e0(local_34);
      fVar4 = _K_ONE - local_34 / local_38;
      fVar1 = unaff_ESI[1];
      fVar2 = unaff_ESI[2];
      *param_4 = local_30 + *unaff_ESI;
      param_4[2] = fVar4 * param_6 + local_28 + fVar2;
      param_4[1] = local_2c + fVar1;
      return 1;
    }
    fVar1 = (-1.0 / *(float *)((int)local_34 + 0x78)) *
            ((*(float *)((int)local_34 + 0x70) * *param_4 +
             *(float *)((int)local_34 + 0x74) * param_4[1]) - *(float *)((int)local_34 + 0x7c));
    if ((*(byte *)((int)local_34 + 10) & 8) != 0) {
      param_4[2] = fVar1 - param_5;
      return 1;
    }
    param_4[2] = fVar1 + param_5;
  }
  else if (param_2 == 1) {
    FUN_005673e0(local_40 - param_5);
    fVar1 = unaff_ESI[1];
    fVar2 = unaff_ESI[2];
    *param_4 = local_30 + *unaff_ESI;
    param_4[2] = local_28 + fVar2;
    param_4[1] = local_2c + fVar1;
    return 1;
  }
  return 1;
}


// ==== 0x441270 FUN_00441270

void FUN_00441270(void)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  
  puVar1 = in_EAX + 0x14;
  *puVar1 = puVar1;
  in_EAX[0x15] = puVar1;
  *in_EAX = 0;
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  in_EAX[6] = 0;
  in_EAX[7] = 0;
  in_EAX[8] = 0;
  in_EAX[0xc] = 0;
  in_EAX[0xd] = 0;
  in_EAX[0xe] = 0;
  in_EAX[0x10] = 0;
  in_EAX[0x11] = 0;
  in_EAX[0x12] = 0;
  return;
}


// ==== 0x4412b0 TrackPolygonSlotPool::Init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] track high (hopper+ghidra) docs/re/track.md */

void TrackPolygonSlotPool__Init(void)

{
  uint uVar1;
  undefined4 *puVar2;
  
  DAT_00736184 = (undefined4 *)FUN_00566dc0(0x80,"TrackPolygonSlotPool",0);
  if ((DAT_00736184 != (undefined4 *)0x0) && (DAT_0073d814 == 1)) {
    *DAT_0073d81c = DAT_00736184;
    puVar2 = DAT_00736184;
    DAT_00736184[1] = DAT_0073d81c;
    DAT_0073d81c = puVar2;
    *DAT_00736184 = &DAT_0073d818;
  }
  uVar1 = DAT_00736184[5];
  DAT_00736184[5] = uVar1 & 0xfffffffe;
  DAT_00736184[5] = uVar1 & 0xfffffffc;
  _DAT_00736178 = 0;
  _DAT_0073617c = 0;
  return;
}


// ==== 0x441320 FUN_00441320

void FUN_00441320(void)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  int extraout_ECX;
  undefined4 *extraout_EDX;
  int *piVar3;
  
  if (DAT_00736184 != 0) {
    piVar3 = (int *)(in_EAX + 0x50);
    piVar1 = *(int **)(in_EAX + 0x50);
    while (piVar1 != piVar3) {
      iVar2 = *(int *)*piVar3;
      piVar1 = (int *)((int *)*piVar3)[1];
      *piVar1 = iVar2;
      *(int **)(iVar2 + 4) = piVar1;
      TrackPolyBody__DetachRow();
      iVar2 = *(int *)(extraout_ECX + 0x18);
      *extraout_EDX = *(undefined4 *)(extraout_ECX + 0x10);
      *(int *)(extraout_ECX + 0x18) = iVar2 + -1;
      *(undefined4 **)(extraout_ECX + 0x10) = extraout_EDX;
      piVar1 = (int *)*piVar3;
    }
    SlotPool__Destroy();
    DAT_00736184 = 0;
  }
  return;
}


// ==== 0x441380 TrackCollision_LoadChunk

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

undefined4 __fastcall TrackCollision_LoadChunk(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint *in_EAX;
  int iVar3;
  uint *puVar4;
  int iVar5;
  
  iVar5 = *param_1;
  if (iVar5 == 0x34130) {
    *in_EAX = (int)param_1 + 0x17U & 0xfffffff0;
    in_EAX[1] = (param_1[1] - ((int)param_1 + 0x17U & 0xfffffff0)) + 8 + (int)param_1 >> 3;
    return 1;
  }
  if (iVar5 == 0x34131) {
    in_EAX[2] = (int)param_1 + 0x17U & 0xfffffff0;
    in_EAX[3] = (param_1[1] - ((int)param_1 + 0x17U & 0xfffffff0)) + 8 + (int)param_1 >> 4;
    return 1;
  }
  if (iVar5 == 0x34132) {
    in_EAX[4] = (uint)(param_1 + 2);
    uVar2 = param_1[1];
    iVar5 = 0;
    in_EAX[5] = uVar2 >> 5;
    if (uVar2 >> 5 != 0) {
      iVar3 = 0;
      do {
        *(undefined2 *)(in_EAX[4] + 6 + iVar3) = 0xffff;
        iVar5 = iVar5 + 1;
        iVar3 = iVar3 + 0x20;
      } while (iVar5 < (int)in_EAX[5]);
    }
    return 1;
  }
  if (iVar5 != 0x34133) {
    if (iVar5 != 0x34134) {
      return 0;
    }
    puVar4 = (uint *)((int)param_1 + 0x17U & 0xfffffff0);
    uVar2 = puVar4[1];
    uVar1 = puVar4[2];
    in_EAX[0xc] = *puVar4;
    in_EAX[0xd] = uVar2;
    in_EAX[0xe] = uVar1;
    uVar2 = puVar4[5];
    uVar1 = puVar4[6];
    in_EAX[0x10] = puVar4[4];
    in_EAX[0x11] = uVar2;
    in_EAX[0x12] = uVar1;
    return 1;
  }
  in_EAX[6] = (uint)(param_1 + 2);
  in_EAX[7] = (uint)param_1[1] >> 1;
  return 1;
}


// ==== 0x441480 TrackCollision_Unload

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

undefined4 __fastcall TrackCollision_Unload(int *param_1)

{
  int iVar1;
  undefined4 *in_EAX;
  
  iVar1 = *param_1;
  if (iVar1 == 0x34130) {
    *in_EAX = 0;
    in_EAX[1] = 0;
    return 1;
  }
  if (iVar1 == 0x34131) {
    in_EAX[2] = 0;
    in_EAX[3] = 0;
    return 1;
  }
  if (iVar1 == 0x34132) {
    in_EAX[4] = 0;
    in_EAX[5] = 0;
    return 1;
  }
  if (iVar1 == 0x34133) {
    in_EAX[6] = 0;
    in_EAX[7] = 0;
    return 1;
  }
  if (iVar1 == 0x34134) {
    in_EAX[0xc] = 0;
    in_EAX[0xd] = 0;
    in_EAX[0xe] = 0;
    in_EAX[0x10] = 0;
    in_EAX[0x11] = 0;
    in_EAX[0x12] = 0;
    return 1;
  }
  return 0;
}


// ==== 0x441500 CollisionGrid::Floor32

/* [canon] track high (hopper+ghidra+capstone) docs/re/track.md */

float10 CollisionGrid__Floor32(void)

{
  uint uVar1;
  
  uVar1 = _ftol_nocw();
  return (float10)(int)(uVar1 & 0xffe00000) * (float10)1.5258789e-05;
}


// ==== 0x441530 CollisionQuadtree::FindCell

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] track high (hopper+ghidra) docs/re/track.md */

int CollisionQuadtree__FindCell(int *param_1,float param_2,float param_3,int param_4)

{
  ushort uVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  float local_c;
  float local_8;
  
  iVar4 = 10;
  local_8 = -16384.0;
  local_c = -16384.0;
  iVar6 = *param_1;
  while( true ) {
    fVar2 = (float)(1 << ((byte)iVar4 & 0x1f)) * 32.0 * _K_HALF;
    fVar3 = local_8 + fVar2;
    uVar5 = (uint)(fVar3 <= param_2);
    fVar2 = fVar2 + local_c;
    if (fVar2 <= param_3) {
      uVar5 = uVar5 + 2;
    }
    if ((uVar5 & 1) != 0) {
      local_8 = fVar3;
    }
    if ((uVar5 & 2) != 0) {
      local_c = fVar2;
    }
    uVar5 = (uint)*(ushort *)(iVar6 + uVar5 * 2);
    if (uVar5 == 0) {
      if (param_4 == 0) {
        return 0;
      }
      uVar5 = 0xffffffff;
      iVar7 = 0;
      fVar3 = ABS(local_8 - param_2) + ABS(local_c - param_3);
      fVar2 = 0.0;
      do {
        uVar1 = *(ushort *)(iVar6 + iVar7 * 2);
        if ((uVar1 != 0) && ((fVar3 < fVar2 || ((int)uVar5 < 0)))) {
          uVar5 = (uint)uVar1;
          fVar2 = fVar3;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < 4);
    }
    if (iVar4 == 1) break;
    iVar6 = *param_1 + uVar5 * 8;
    iVar4 = iVar4 + -1;
  }
  return uVar5 * 0x10 + param_1[2];
}


// ==== 0x441660 CollisionCell::CollectPolys

/* [canon] track high (hopper+ghidra) docs/re/track.md */

int __fastcall
CollisionCell__CollectPolys(int param_1,float *param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float fVar8;
  float *in_EAX;
  undefined1 *puVar9;
  int iVar10;
  ushort *puVar11;
  int iVar12;
  int iVar13;
  int local_10;
  int local_c;
  
  if (param_1 != 0) {
    iVar2 = *(int *)(param_3 + 0x18);
    fVar3 = *param_2;
    fVar4 = param_2[1];
    fVar5 = *in_EAX;
    fVar6 = in_EAX[1];
    local_10 = *(int *)(param_1 + 8);
    iVar7 = *(int *)(param_3 + 0x10);
    iVar12 = *(int *)(param_1 + 0xc) + local_10;
    iVar13 = 0;
    if (3 < iVar12 - local_10) {
      local_c = local_10 + 3;
      puVar11 = (ushort *)(iVar2 + 4 + local_10 * 2);
      do {
        puVar9 = (undefined1 *)((uint)puVar11[-2] * 0x20 + iVar7);
        if ((((*(char *)((uint)puVar11[-2] * 0x20 + iVar7) == '\0') &&
             (bVar1 = puVar9[1],
             fVar8 = (float)((int)*(short *)(puVar9 + (bVar1 & 3) * 2 + 8) << 0xd) * 1.5258789e-05,
             fVar8 < fVar5 != (fVar8 == fVar5))) &&
            (fVar8 = (float)((int)*(short *)(puVar9 + (bVar1 >> 2 & 3) * 2 + 0x10) << 0xd) *
                     1.5258789e-05, fVar8 < fVar6 != (fVar8 == fVar6))) &&
           (((fVar3 <= (float)((int)*(short *)(puVar9 + (bVar1 >> 4 & 3) * 2 + 8) << 0xd) *
                       1.5258789e-05 &&
             (fVar4 <= (float)((int)*(short *)(puVar9 + (uint)(bVar1 >> 6) * 2 + 0x10) << 0xd) *
                       1.5258789e-05)) && (iVar13 < param_5)))) {
          *(undefined1 **)(param_4 + iVar13 * 4) = puVar9;
          iVar13 = iVar13 + 1;
          *puVar9 = 1;
        }
        puVar9 = (undefined1 *)((uint)puVar11[-1] * 0x20 + iVar7);
        if (((*(char *)((uint)puVar11[-1] * 0x20 + iVar7) == '\0') &&
            (bVar1 = puVar9[1],
            fVar8 = (float)((int)*(short *)(puVar9 + (bVar1 & 3) * 2 + 8) << 0xd) * 1.5258789e-05,
            fVar8 < fVar5 != (fVar8 == fVar5))) &&
           ((fVar8 = (float)((int)*(short *)(puVar9 + (bVar1 >> 2 & 3) * 2 + 0x10) << 0xd) *
                     1.5258789e-05, fVar8 < fVar6 != (fVar8 == fVar6) &&
            (((fVar3 <= (float)((int)*(short *)(puVar9 + (bVar1 >> 4 & 3) * 2 + 8) << 0xd) *
                        1.5258789e-05 &&
              (fVar4 <= (float)((int)*(short *)(puVar9 + (uint)(bVar1 >> 6) * 2 + 0x10) << 0xd) *
                        1.5258789e-05)) && (iVar13 < param_5)))))) {
          *(undefined1 **)(param_4 + iVar13 * 4) = puVar9;
          iVar13 = iVar13 + 1;
          *puVar9 = 1;
        }
        puVar9 = (undefined1 *)((uint)*puVar11 * 0x20 + iVar7);
        if ((((*(char *)((uint)*puVar11 * 0x20 + iVar7) == '\0') &&
             (bVar1 = puVar9[1],
             fVar8 = (float)((int)*(short *)(puVar9 + (bVar1 & 3) * 2 + 8) << 0xd) * 1.5258789e-05,
             fVar8 < fVar5 != (fVar8 == fVar5))) &&
            ((fVar8 = (float)((int)*(short *)(puVar9 + (bVar1 >> 2 & 3) * 2 + 0x10) << 0xd) *
                      1.5258789e-05, fVar8 < fVar6 != (fVar8 == fVar6) &&
             ((fVar3 <= (float)((int)*(short *)(puVar9 + (bVar1 >> 4 & 3) * 2 + 8) << 0xd) *
                        1.5258789e-05 &&
              (fVar4 <= (float)((int)*(short *)(puVar9 + (uint)(bVar1 >> 6) * 2 + 0x10) << 0xd) *
                        1.5258789e-05)))))) && (iVar13 < param_5)) {
          *(undefined1 **)(param_4 + iVar13 * 4) = puVar9;
          iVar13 = iVar13 + 1;
          *puVar9 = 1;
        }
        puVar9 = (undefined1 *)((uint)puVar11[1] * 0x20 + iVar7);
        if (((((*(char *)((uint)puVar11[1] * 0x20 + iVar7) == '\0') &&
              (bVar1 = puVar9[1],
              fVar8 = (float)((int)*(short *)(puVar9 + (bVar1 & 3) * 2 + 8) << 0xd) * 1.5258789e-05,
              fVar8 < fVar5 != (fVar8 == fVar5))) &&
             (fVar8 = (float)((int)*(short *)(puVar9 + (bVar1 >> 2 & 3) * 2 + 0x10) << 0xd) *
                      1.5258789e-05, fVar8 < fVar6 != (fVar8 == fVar6))) &&
            ((fVar3 <= (float)((int)*(short *)(puVar9 + (bVar1 >> 4 & 3) * 2 + 8) << 0xd) *
                       1.5258789e-05 &&
             (fVar4 <= (float)((int)*(short *)(puVar9 + (uint)(bVar1 >> 6) * 2 + 0x10) << 0xd) *
                       1.5258789e-05)))) && (iVar13 < param_5)) {
          *(undefined1 **)(param_4 + iVar13 * 4) = puVar9;
          iVar13 = iVar13 + 1;
          *puVar9 = 1;
        }
        local_10 = local_10 + 4;
        local_c = local_c + 4;
        puVar11 = puVar11 + 4;
      } while (local_c < iVar12);
    }
    for (; local_10 < iVar12; local_10 = local_10 + 1) {
      iVar10 = (uint)*(ushort *)(iVar2 + local_10 * 2) * 0x20;
      puVar9 = (undefined1 *)(iVar10 + iVar7);
      if (((*(char *)(iVar10 + iVar7) == '\0') &&
          (bVar1 = puVar9[1],
          fVar8 = (float)((int)*(short *)(puVar9 + (bVar1 & 3) * 2 + 8) << 0xd) * 1.5258789e-05,
          fVar8 < fVar5 != (fVar8 == fVar5))) &&
         ((fVar8 = (float)((int)*(short *)(puVar9 + (bVar1 >> 2 & 3) * 2 + 0x10) << 0xd) *
                   1.5258789e-05, fVar8 < fVar6 != (fVar8 == fVar6) &&
          (((fVar3 <= (float)((int)*(short *)(puVar9 + (bVar1 >> 4 & 3) * 2 + 8) << 0xd) *
                      1.5258789e-05 &&
            (fVar4 <= (float)((int)*(short *)(puVar9 + (uint)(bVar1 >> 6) * 2 + 0x10) << 0xd) *
                      1.5258789e-05)) && (iVar13 < param_5)))))) {
        *(undefined1 **)(param_4 + iVar13 * 4) = puVar9;
        iVar13 = iVar13 + 1;
        *puVar9 = 1;
      }
    }
    return iVar13;
  }
  return 0;
}


// ==== 0x441b20 TrackPolyBody::ReleaseUnused

/* [canon] track high (hopper+ghidra) docs/re/track.md */

void TrackPolyBody__ReleaseUnused(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 *extraout_ECX;
  int *piVar3;
  int extraout_EDX;
  int iVar4;
  
  piVar3 = *(int **)(param_1 + 0x50);
  iVar4 = 0;
  if (piVar3 != (int *)(param_1 + 0x50)) {
    do {
      if ((char)piVar3[2] == '\0') {
        iVar1 = *piVar3;
        piVar3 = (int *)piVar3[1];
        *piVar3 = iVar1;
        *(int **)(iVar1 + 4) = piVar3;
        TrackPolyBody__DetachRow();
        iVar1 = *(int *)(extraout_EDX + 0x18);
        iVar4 = iVar4 + 1;
        *extraout_ECX = *(undefined4 *)(extraout_EDX + 0x10);
        *(int *)(extraout_EDX + 0x18) = iVar1 + -1;
        *(undefined4 **)(extraout_EDX + 0x10) = extraout_ECX;
        if (100 < iVar4) break;
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)(param_1 + 0x50));
    if (iVar4 != 0) {
      return;
    }
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}


// ==== 0x441b90 TrackPoly::AcquireBody

/* [canon] track high (hopper+ghidra) docs/re/track.md */

void TrackPoly__AcquireBody(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_EAX;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = DAT_00736184;
  if (*(short *)(in_EAX + 6) < 0) {
    if (*(int *)(DAT_00736184 + 0x18) == *(int *)(DAT_00736184 + 0x2c)) {
      TrackPolyBody__ReleaseUnused(param_1);
    }
    iVar3 = *(int *)(iVar5 + 0x18) + 1;
    if (*(undefined4 **)(iVar5 + 0x10) == (undefined4 *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      uVar1 = **(undefined4 **)(iVar5 + 0x10);
      if (*(int *)(iVar5 + 0x1c) < iVar3) {
        *(int *)(iVar5 + 0x1c) = iVar3;
      }
      *(int *)(iVar5 + 0x18) = iVar3;
      *(undefined4 *)(iVar5 + 0x10) = uVar1;
      piVar4 = (int *)TrackPolyBody__Build();
    }
    puVar2 = *(undefined4 **)(param_1 + 0x54);
    *puVar2 = piVar4;
    *(int **)(param_1 + 0x54) = piVar4;
    *piVar4 = param_1 + 0x50;
    piVar4[1] = (int)puVar2;
    *(char *)(piVar4 + 2) = (char)piVar4[2] + '\x01';
    return;
  }
  iVar5 = TrackPolyBody__FromSlotIndex(param_1);
  *(char *)(iVar5 + 8) = *(char *)(iVar5 + 8) + '\x01';
  return;
}


// ==== 0x441c10 TrackCollision::QueryBox

/* [canon] track high (hopper+ghidra) docs/re/track.md */

int TrackCollision__QueryBox(undefined4 param_1,undefined4 *param_2,int param_3,float *param_4)

{
  float *in_EAX;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  float10 fVar5;
  float local_288;
  float local_284;
  undefined4 local_280 [160];
  
  iVar4 = 0;
  if ((((-32768.0 < *in_EAX) && (*param_4 < 32767.0)) && (-32768.0 < in_EAX[1])) &&
     (param_4[1] < 32767.0)) {
    fVar5 = (float10)CollisionGrid__Floor32(param_1,in_EAX[1]);
    local_284 = (float)fVar5;
    if (fVar5 < (float10)param_4[1] != (fVar5 == (float10)param_4[1])) {
      do {
        uVar1 = _ftol_nocw();
        local_288 = (float)(int)(uVar1 & 0xffe00000) * 1.5258789e-05;
        if (local_288 < *param_4 != (local_288 == *param_4)) {
          do {
            iVar2 = CollisionQuadtree__FindCell(param_1,local_288,local_284,0);
            if (iVar2 != 0) {
              iVar2 = CollisionCell__CollectPolys(param_1,local_280 + iVar4,param_3 - iVar4);
              iVar4 = iVar4 + iVar2;
            }
            local_288 = local_288 + 32.0;
          } while (local_288 < *param_4 != (local_288 == *param_4));
        }
        local_284 = local_284 + 32.0;
      } while (local_284 < param_4[1] != (local_284 == param_4[1]));
    }
  }
  if (0 < iVar4) {
    iVar2 = (int)local_280 - (int)param_2;
    local_288 = (float)iVar4;
    do {
      **(undefined1 **)((int)param_2 + iVar2) = 0;
      uVar3 = TrackPoly__AcquireBody(param_1);
      *param_2 = uVar3;
      param_2 = param_2 + 1;
      local_288 = (float)((int)local_288 + -1);
    } while (local_288 != 0.0);
  }
  return iVar4;
}


// ==== 0x441d80 FUN_00441d80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00441d80(float param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *in_EAX;
  int iVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  float10 extraout_ST0;
  
  iVar8 = (int)param_1 * 0x94;
  fVar5 = *(float *)(&DAT_006ef2e8 + iVar8) * *in_EAX;
  fVar3 = in_EAX[1];
  fVar4 = *(float *)(&DAT_006ef2e8 + iVar8);
  fVar9 = (float10)FUN_004387e0(fVar5);
  param_1 = (float)fVar9;
  if ((float10)fVar5 < fVar9) {
    param_1 = param_1 - _K_ONE;
  }
  FUN_004387e0(fVar3 * fVar4);
  iVar6 = _ftol_nocw();
  iVar7 = _ftol_nocw();
  fVar5 = fVar5 - param_1;
  fVar9 = (float10)(fVar3 * fVar4) - extraout_ST0;
  iVar1 = iVar6 + 1;
  iVar2 = iVar7 + 1;
  return ((float10)*(float *)(&DAT_007009d8 +
                             (iVar1 * iVar2 * -5 + (iVar6 + 2) * (iVar7 + 2) * -3 & 0xfU) * 4) *
          fVar9 * (float10)fVar5 +
         (float10)*(float *)(&DAT_007009d8 +
                            (iVar2 * iVar6 * -5 + (iVar7 + 2) * iVar1 * -3 & 0xfU) * 4) *
         ((float10)_K_ONE - (float10)fVar5) * fVar9 +
         (float10)*(float *)(&DAT_007009d8 +
                            (iVar1 * iVar7 * -5 + (iVar6 + 2) * iVar2 * -3 & 0xfU) * 4) *
         ((float10)_K_ONE - fVar9) * (float10)fVar5 +
         (float10)*(float *)(&DAT_007009d8 +
                            (iVar7 * iVar6 * -5 + (iVar7 + 1) * iVar1 * -3 & 0xfU) * 4) *
         ((float10)_K_ONE - (float10)fVar5) * ((float10)_K_ONE - fVar9)) *
         (float10)*(float *)(&DAT_006ef2ec + iVar8);
}


// ==== 0x441ed0 TrackPositionMarker_Load

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

bool TrackPositionMarker_Load(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if (*param_1 == 0x34146) {
    puVar4 = (undefined4 *)((int)param_1 + 0x17U & 0xfffffff0);
    puVar1 = DAT_0077b194;
    for (uVar3 = ((param_1[1] - ((int)param_1 + 0x17U & 0xfffffff0)) + 8 + (int)param_1) / 0x30;
        uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar1 = puVar4;
      DAT_0077b194 = puVar4;
      puVar4[1] = puVar1;
      *puVar4 = &DAT_0077b190;
      puVar4 = puVar4 + 0xc;
      puVar1 = DAT_0077b194;
    }
    DAT_0077b194 = puVar1;
    return true;
  }
  iVar2 = TrackCollision_LoadChunk();
  return iVar2 != 0;
}


// ==== 0x441f40 TrackPositionMarker_Unload

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

bool TrackPositionMarker_Unload(int *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  if (*param_1 == 0x34146) {
    piVar4 = (int *)((int)param_1 + 0x17U & 0xfffffff0);
    for (uVar3 = ((param_1[1] - ((int)param_1 + 0x17U & 0xfffffff0)) + 8 + (int)param_1) / 0x30;
        uVar3 != 0; uVar3 = uVar3 - 1) {
      iVar2 = *piVar4;
      piVar1 = (int *)piVar4[1];
      piVar4 = piVar4 + 0xc;
      *piVar1 = iVar2;
      *(int **)(iVar2 + 4) = piVar1;
    }
    return true;
  }
  iVar2 = TrackCollision_Unload();
  return iVar2 != 0;
}


// ==== 0x441fa0 FUN_00441fa0

void FUN_00441fa0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int extraout_EDX;
  int *unaff_EDI;
  
  piVar1 = (int *)*unaff_EDI;
  while (piVar1 != unaff_EDI) {
    iVar2 = *piVar1;
    piVar1 = (int *)piVar1[1];
    *piVar1 = iVar2;
    *(int **)(iVar2 + 4) = piVar1;
    TrackPolyBody__DetachRow();
    iVar2 = *(int *)(extraout_EDX + 0x18);
    *extraout_ECX = *(undefined4 *)(extraout_EDX + 0x10);
    *(int *)(extraout_EDX + 0x18) = iVar2 + -1;
    *(undefined4 **)(extraout_EDX + 0x10) = extraout_ECX;
    piVar1 = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x441fe0 TrackRow_FindById

/* [canon] traffic high (G+C) docs/re/traffic.md */

int TrackRow_FindById(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar2 = 0;
  iVar1 = DAT_00736168;
  if (0 < DAT_0073616c) {
    do {
      if (*(short *)(iVar1 + 0x6c) == unaff_ESI) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0xfc;
    } while (iVar2 < DAT_0073616c);
  }
  return 0;
}


// ==== 0x442010 TrackInfo_GetRow

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

int TrackInfo_GetRow(void)

{
  int in_EAX;
  
  if (((DAT_00736168 != 0) && (-1 < in_EAX)) && (in_EAX < DAT_0073616c)) {
    return in_EAX * 0xfc + DAT_00736168;
  }
  return 0;
}


// ==== 0x442040 TrackInfoTable_Load

/* [canon] assets high (Hopper export has no block (inside another sub_); Ghidra export has no
   block; live Ghidra decompile + capstone) docs/re/assets.md */

undefined4 TrackInfoTable_Load(int *param_1)

{
  if (*param_1 == 0x34201) {
    DAT_00736168 = param_1 + 2;
    DAT_0073616c = (uint)param_1[1] / 0xfc;
    return 1;
  }
  return 0;
}


// ==== 0x442080 TrackInfoTable_Unload

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

bool TrackInfoTable_Unload(int *param_1)

{
  if (*param_1 == 0x34201) {
    DAT_00736168 = 0;
    DAT_0073616c = 0;
  }
  return *param_1 == 0x34201;
}


// ==== 0x4420a0 FUN_004420a0

uint FUN_004420a0(void)

{
  int in_EAX;
  
  return *(uint *)(in_EAX + 0x84) >> 0x19 & 1;
}


// ==== 0x4420b0 FUN_004420b0

uint __fastcall FUN_004420b0(char param_1)

{
  int in_EAX;
  
  if (param_1 != '\0') {
    return *(uint *)(in_EAX + 0x84) >> 0x19 & 1;
  }
  return *(uint *)(in_EAX + 0x84) >> 0x1a & 1;
}


// ==== 0x4420d0 FUN_004420d0

uint FUN_004420d0(void)

{
  int in_EAX;
  
  return *(uint *)(in_EAX + 0x84) >> 0x1a & 1;
}


// ==== 0x4420e0 FUN_004420e0

int __fastcall FUN_004420e0(int param_1)

{
  int in_EAX;
  
  return ((in_EAX - param_1) + -0x27c) / 0x88;
}


// ==== 0x442100 RoadIntersection_Get

/* [canon] traffic high (H+G) docs/re/traffic.md */

int RoadIntersection_Get(void)

{
  int in_EAX;
  
  return in_EAX * 0x170 + DAT_00736158;
}


// ==== 0x442110 FUN_00442110

/* WARNING: Removing unreachable block (ram,0x00442131) */

int __fastcall FUN_00442110(int param_1)

{
  return (uint)*(ushort *)(param_1 + 4) * 0x88 + 0x27c + (&DAT_0077af30)[*(byte *)(param_1 + 9)];
}


// ==== 0x442150 RoadEntries_FillDistances

/* WARNING: Removing unreachable block (ram,0x004421b9) */
/* [canon] traffic med (H) docs/re/traffic.md */

void RoadEntries_FillDistances(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  uVar3 = 0;
  if (DAT_00736154 != 0) {
    do {
      puVar1 = (undefined4 *)(iVar2 + DAT_00736150);
      TrackPath__UpdateCursor
                (&DAT_007372b0,
                 (uint)*(ushort *)((int)puVar1 + 6) * 0x88 + 0x27c +
                 (&DAT_0077af30)[*(byte *)((int)puVar1 + 10)]);
      *puVar1 = 0;
      uVar3 = uVar3 + 1;
      iVar2 = iVar2 + 0x20;
    } while (uVar3 < DAT_00736154);
  }
  return;
}


// ==== 0x442200 FUN_00442200

uint FUN_00442200(float param_1)

{
  uint uVar1;
  float *pfVar2;
  uint uVar3;
  
  uVar1 = 0;
  if (3 < (int)DAT_00736154) {
    uVar3 = 3;
    pfVar2 = (float *)(DAT_00736150 + 0x40);
    do {
      if (param_1 <= pfVar2[-0x10]) goto LAB_00442296;
      if (param_1 <= pfVar2[-8]) {
        uVar1 = uVar1 + 1;
        goto LAB_00442296;
      }
      if (param_1 <= *pfVar2) {
        uVar1 = uVar1 + 2;
        goto LAB_00442296;
      }
      if (param_1 <= pfVar2[8]) {
        uVar1 = uVar1 + 3;
        goto LAB_00442296;
      }
      uVar3 = uVar3 + 4;
      uVar1 = uVar1 + 4;
      pfVar2 = pfVar2 + 0x20;
    } while (uVar3 < DAT_00736154);
  }
  if (uVar1 < DAT_00736154) {
    pfVar2 = (float *)(uVar1 * 0x20 + DAT_00736150);
    while( true ) {
      if (param_1 <= *pfVar2) break;
      uVar1 = uVar1 + 1;
      pfVar2 = pfVar2 + 8;
      if (DAT_00736154 <= uVar1) {
        return 0;
      }
    }
LAB_00442296:
    if (uVar1 < DAT_00736154) {
      return uVar1;
    }
  }
  return 0;
}


// ==== 0x4422b0 FUN_004422b0

void __thiscall FUN_004422b0(float *param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *in_EAX;
  
  fVar6 = in_EAX[4];
  fVar1 = in_EAX[1];
  fVar2 = in_EAX[2];
  fVar3 = in_EAX[0xc];
  fVar4 = in_EAX[3];
  fVar5 = in_EAX[0xb];
  *param_1 = in_EAX[3] * param_2 + in_EAX[4] * param_3 + *in_EAX;
  param_1[1] = fVar6 * param_2 + -fVar4 * param_3 + fVar1;
  param_1[2] = fVar3 * param_2 + fVar5 * param_3 + fVar2;
  return;
}


// ==== 0x442330 FUN_00442330

void __thiscall FUN_00442330(float *param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *in_EAX;
  
  fVar6 = in_EAX[6];
  fVar1 = in_EAX[1];
  fVar2 = in_EAX[2];
  fVar3 = in_EAX[0xd];
  fVar4 = in_EAX[5];
  fVar5 = in_EAX[0xb];
  *param_1 = in_EAX[5] * param_2 + in_EAX[6] * param_3 + *in_EAX;
  param_1[1] = fVar6 * param_2 + -fVar4 * param_3 + fVar1;
  param_1[2] = fVar3 * param_2 + -fVar5 * param_3 + fVar2;
  return;
}


// ==== 0x4423b0 FUN_004423b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004423b0(float *param_1,float param_2)

{
  float fVar1;
  float *in_EAX;
  float10 fVar2;
  
  fVar1 = SQRT((*in_EAX - *param_1) * (*in_EAX - *param_1) +
               (in_EAX[1] - param_1[1]) * (in_EAX[1] - param_1[1]));
  fVar2 = (float10)in_EAX[0xe];
  if (DAT_007372b4 != 0) {
    fVar2 = (float10)DAT_007372b0 - fVar2;
  }
  fVar2 = fVar2 - (float10)param_2;
  if ((0 < DAT_007372b8) && (*(char *)(DAT_007372bc + 1) != '\0')) {
    if ((float10)DAT_007372b0 * (float10)-0.5 <= fVar2) {
      if ((float10)DAT_007372b0 * (float10)_K_HALF < fVar2) {
        fVar2 = fVar2 - (float10)DAT_007372b0;
      }
    }
    else {
      fVar2 = fVar2 + (float10)DAT_007372b0;
    }
  }
  fVar2 = ABS(fVar2) - (float10)24.0;
  if (fVar2 < (float10)fVar1) {
    fVar2 = (float10)fVar1;
  }
  return fVar2;
}


// ==== 0x442460 FUN_00442460

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00442460(float param_1)

{
  int in_EAX;
  float10 fVar1;
  
  fVar1 = (float10)*(float *)(in_EAX + 0x38);
  if (DAT_007372b4 != 0) {
    fVar1 = (float10)DAT_007372b0 - fVar1;
  }
  fVar1 = fVar1 - (float10)param_1;
  if ((0 < DAT_007372b8) && (*(char *)(DAT_007372bc + 1) != '\0')) {
    if (fVar1 < (float10)DAT_007372b0 * (float10)-0.5) {
      return fVar1 + (float10)DAT_007372b0;
    }
    if ((float10)DAT_007372b0 * (float10)_K_HALF < fVar1) {
      fVar1 = fVar1 - (float10)DAT_007372b0;
    }
  }
  return fVar1;
}


// ==== 0x4424d0 Node_IsDriveFwd

/* [canon] traffic med (G) docs/re/traffic.md */

char __fastcall Node_IsDriveFwd(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  cVar1 = '\0';
  iVar3 = 0;
  do {
    if (cVar1 != '\0') {
      return cVar1;
    }
    if (iVar3 == 0) {
      uVar2 = *(uint *)(param_1 + 0x84) >> 6;
LAB_00442504:
      if ((uVar2 & 1) == 0) goto LAB_0044250b;
      cVar1 = '\x01';
    }
    else {
      if (iVar3 == 1) {
        uVar2 = *(uint *)(param_1 + 0x84) >> 0x19;
        goto LAB_00442504;
      }
      if (iVar3 == 2) {
        uVar2 = *(uint *)(param_1 + 0x84) >> 0x1b;
        goto LAB_00442504;
      }
LAB_0044250b:
      cVar1 = '\0';
    }
    iVar3 = iVar3 + 1;
    if (2 < iVar3) {
      return cVar1;
    }
  } while( true );
}


// ==== 0x442520 Node_IsDriveBack

/* [canon] traffic med (G) docs/re/traffic.md */

char __fastcall Node_IsDriveBack(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  cVar1 = '\0';
  iVar3 = 0;
  do {
    if (cVar1 != '\0') {
      return cVar1;
    }
    if (iVar3 == 0) {
      uVar2 = *(uint *)(param_1 + 0x84) >> 0x13;
LAB_00442554:
      if ((uVar2 & 1) == 0) goto LAB_0044255b;
      cVar1 = '\x01';
    }
    else {
      if (iVar3 == 1) {
        uVar2 = *(uint *)(param_1 + 0x84) >> 0x1a;
        goto LAB_00442554;
      }
      if (iVar3 == 2) {
        uVar2 = *(uint *)(param_1 + 0x84) >> 0x1c;
        goto LAB_00442554;
      }
LAB_0044255b:
      cVar1 = '\0';
    }
    iVar3 = iVar3 + 1;
    if (2 < iVar3) {
      return cVar1;
    }
  } while( true );
}


// ==== 0x442570 FUN_00442570

float10 FUN_00442570(void)

{
  int in_EAX;
  float10 fVar1;
  
  fVar1 = (float10)*(float *)(in_EAX + 0x38);
  if (DAT_007372b4 != 0) {
    fVar1 = (float10)DAT_007372b0 - fVar1;
  }
  return fVar1;
}


// ==== 0x442590 FUN_00442590

float10 __fastcall FUN_00442590(int param_1)

{
  float *in_EAX;
  float10 fVar1;
  
  if (((param_1 < 0xb) || (0x10 < param_1)) && ((param_1 < 0 || (4 < param_1)))) {
    fVar1 = (float10)((int)*(short *)((int)in_EAX + param_1 * 2 + 0x3c) << 8) *
            (float10)1.5258789e-05;
    return (((float10)in_EAX[5] * (float10)0.0 + (float10)in_EAX[6] * fVar1 + (float10)*in_EAX) -
           (float10)*in_EAX) * (float10)in_EAX[4] -
           (((float10)in_EAX[6] * (float10)0.0 +
            (float10)(float)((float10)-in_EAX[5] * fVar1 + (float10)in_EAX[1])) - (float10)in_EAX[1]
           ) * (float10)in_EAX[3];
  }
  return (float10)((int)*(short *)((int)in_EAX + param_1 * 2 + 0x3c) << 8) * (float10)1.5258789e-05;
}


// ==== 0x442630 FUN_00442630

int __fastcall FUN_00442630(int param_1,char param_2)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = (in_EAX - param_1) + -0x27c;
  if (param_2 == '\0') {
    iVar1 = iVar1 / 0x88;
    if (iVar1 != 0) {
      return iVar1 * 0x88 + 500 + param_1;
    }
  }
  else {
    iVar1 = iVar1 / 0x88;
    if (iVar1 + 1 < (int)*(short *)(param_1 + 0x10)) {
      return iVar1 * 0x88 + 0x304 + param_1;
    }
  }
  return 0;
}


// ==== 0x442690 FUN_00442690

float * FUN_00442690(int param_1,float param_2,float *param_3,undefined4 param_4)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  float *extraout_EDX;
  float *pfVar4;
  float *unaff_ESI;
  int iVar5;
  float10 fVar6;
  
  uVar2 = (uint)param_3;
  if ((((*(float *)(param_1 + 0x20) - param_2 <= *unaff_ESI) &&
       (*unaff_ESI <= param_2 + *(float *)(param_1 + 0x28))) &&
      (*(float *)(param_1 + 0x24) - param_2 <= unaff_ESI[1])) &&
     (unaff_ESI[1] <= param_2 + *(float *)(param_1 + 0x2c))) {
    iVar5 = 0;
    param_3 = (float *)0x0;
    if (0 < *(short *)(param_1 + 0x10)) {
      do {
        pfVar4 = (float *)(iVar5 * 0x88 + 0x27c + param_1);
        if ((uVar2 & 0x20) == 0) {
          fVar6 = SQRT(((float10)*pfVar4 - (float10)*unaff_ESI) *
                       ((float10)*pfVar4 - (float10)*unaff_ESI) +
                       ((float10)pfVar4[1] - (float10)unaff_ESI[1]) *
                       ((float10)pfVar4[1] - (float10)unaff_ESI[1]));
        }
        else {
          fVar6 = (float10)FUN_004423b0(param_4);
          pfVar4 = extraout_EDX;
        }
        fVar1 = -((*unaff_ESI - *pfVar4) * pfVar4[3] + (unaff_ESI[1] - pfVar4[1]) * pfVar4[4]);
        if ((((((uVar2 & 1) == 0) || (0.1 < fVar1)) && (((uVar2 & 2) == 0 || (fVar1 < 0.1)))) &&
            ((fVar6 < (float10)param_2 && (((uVar2 & 4) == 0 || (((uint)pfVar4[0x21] & 0x40) != 0)))
             ))) && ((((uVar2 & 0x200) == 0 || (((uint)pfVar4[0x21] & 0x2000000) != 0)) &&
                     (((uVar2 & 0x400) == 0 || (((uint)pfVar4[0x21] & 0x8000000) != 0)))))) {
          param_2 = (float)fVar6;
          param_3 = pfVar4;
        }
        iVar3 = _ftol_nocw();
        if (0 < -2 - iVar3) {
          iVar5 = iVar5 + (-2 - iVar3);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(short *)(param_1 + 0x10));
    }
    return param_3;
  }
  return (float *)0x0;
}


// ==== 0x442820 FUN_00442820

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00442820(float param_1,float param_2,float param_3)

{
  float fVar1;
  short sVar2;
  int iVar3;
  int extraout_EDX;
  int extraout_EDX_00;
  int iVar4;
  int unaff_EDI;
  float10 fVar5;
  int local_8;
  
  sVar2 = *(short *)((int)param_1 + 0x10);
  iVar4 = 0;
  local_8 = 0;
  param_1 = 999999.0;
  iVar3 = 0;
  if (0 < sVar2) {
    do {
      if (unaff_EDI == 0) {
        fVar5 = (float10)FUN_00442460(param_2);
        iVar3 = extraout_EDX_00;
      }
      else {
        fVar5 = (float10)FUN_004423b0(param_2);
        iVar3 = extraout_EDX;
      }
      fVar5 = fVar5 - (float10)param_3;
      fVar1 = *(float *)(iVar3 + 0x38);
      if (DAT_007372b4 != 0) {
        fVar1 = DAT_007372b0 - fVar1;
      }
      fVar1 = fVar1 - param_2;
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
      if ((((float10)0.0 <= fVar5) && (fVar5 < (float10)param_1)) && (0.0 < fVar1)) {
        param_1 = (float)fVar5;
        local_8 = iVar3;
      }
      iVar3 = _ftol_nocw();
      if (0 < -2 - iVar3) {
        iVar4 = iVar4 + (-2 - iVar3);
      }
      iVar4 = iVar4 + 1;
      iVar3 = local_8;
    } while (iVar4 < sVar2);
  }
  return iVar3;
}


// ==== 0x442950 Section_HasLane

/* [canon] traffic high (G+H) docs/re/traffic.md */

undefined4 __fastcall Section_HasLane(undefined4 param_1,int param_2)

{
  char in_AL;
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(char *)((-(uint)(in_AL != '\0') & 0xfffffffa) + 0x276 + param_2 + iVar1) != '\0') {
      return 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  return 0;
}


// ==== 0x442980 FUN_00442980

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00442980(void)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int unaff_EDI;
  int local_44;
  float local_40;
  float local_38 [14];
  
  uVar5 = 0;
  fVar2 = _K_HALF * DAT_007372b0;
  local_38[2] = DAT_007372b0;
  local_38[0] = DAT_007372b0;
  local_38[3] = 0.0;
  local_38[1] = 0.0;
  bVar3 = false;
  local_38[4] = 0.0;
  local_38[5] = 0.0;
  local_38[6] = 0.0;
  local_38[7] = 0.0;
  local_38[8] = 0.0;
  local_38[9] = 0.0;
  local_38[10] = 1.0;
  local_38[0xb] = 0.0;
  local_38[0xc] = 0.0;
  local_38[0xd] = 0.0;
  TrackPath__UpdateCursor(&DAT_007372b0,unaff_EDI + 0x27c);
  iVar4 = 1;
  local_40 = local_38[9];
  if (1 < *(short *)(unaff_EDI + 0x10)) {
    local_44 = unaff_EDI + 0x304;
    do {
      TrackPath__UpdateCursor(&DAT_007372b0,local_44);
      fVar1 = local_38[9] - local_40;
      local_40 = local_38[9];
      if (fVar2 < ABS(fVar1)) {
        bVar3 = true;
        uVar5 = uVar5 ^ 1;
      }
      if (local_38[uVar5 * 2 + 1] < local_38[9]) {
        local_38[uVar5 * 2 + 1] = local_38[9];
      }
      if (local_38[9] < local_38[uVar5 * 2]) {
        local_38[uVar5 * 2] = local_38[9];
      }
      local_44 = local_44 + 0x88;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(short *)(unaff_EDI + 0x10));
    if (bVar3) {
      if (local_38[2] < local_38[0]) {
        local_38[2] = local_38[0];
      }
      *(float *)(unaff_EDI + 0x18) = local_38[2];
      if (local_38[3] <= local_38[1]) {
        *(float *)(unaff_EDI + 0x1c) = local_38[3];
        return;
      }
      *(float *)(unaff_EDI + 0x1c) = local_38[1];
      return;
    }
  }
  *(float *)(unaff_EDI + 0x18) = local_38[0];
  *(float *)(unaff_EDI + 0x1c) = local_38[1];
  return;
}


// ==== 0x442b00 FUN_00442b00

int __fastcall FUN_00442b00(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = param_2 + 8;
  *(int *)param_2 = param_2;
  *(int *)(param_2 + 4) = param_2;
  *(int *)iVar1 = iVar1;
  *(int *)(param_2 + 0xc) = iVar1;
  puVar2 = (undefined4 *)(param_2 + 0x10);
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return param_2;
}


// ==== 0x442b20 FUN_00442b20

void FUN_00442b20(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *unaff_EDI;
  
  RoadSections_Unload(0);
  piVar1 = (int *)unaff_EDI[2];
  while (piVar1 != unaff_EDI + 2) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(piVar1);
    piVar1 = (int *)unaff_EDI[2];
  }
  piVar1 = (int *)*unaff_EDI;
  while (piVar1 != unaff_EDI) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(piVar1);
    piVar1 = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x442b70 RoadSections_Parse

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

void __fastcall RoadSections_Parse(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = *(int *)(param_1 + 4);
  for (piVar1 = (int *)(param_1 + 8); piVar1 < (int *)(iVar2 + 8 + param_1);
      piVar1 = piVar1 + (short)piVar1[4] * 0x22 + 0x9f) {
    *(int **)(param_2 + 0x10 + *(short *)((int)piVar1 + 10) * 4) = piVar1;
    if (piVar1[3] == 0) {
      puVar3 = *(undefined4 **)(param_2 + 4);
      *puVar3 = piVar1;
      *(int **)(param_2 + 4) = piVar1;
      piVar1[1] = (int)puVar3;
      *piVar1 = param_2;
    }
    else if (piVar1[3] == 1) {
      puVar3 = *(undefined4 **)(param_2 + 0xc);
      *puVar3 = piVar1;
      *(int **)(param_2 + 0xc) = piVar1;
      piVar1[1] = (int)puVar3;
      *piVar1 = param_2 + 8;
    }
  }
  return;
}


// ==== 0x442bd0 RoadSections_Unload

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

void RoadSections_Unload(void)

{
  int *_Memory;
  int iVar1;
  int *piVar2;
  int in_EAX;
  undefined4 *puVar3;
  int iVar4;
  
  puVar3 = (undefined4 *)(in_EAX + 0x10);
  iVar4 = 0x80;
  do {
    _Memory = (int *)*puVar3;
    if (_Memory != (int *)0x0) {
      iVar1 = *_Memory;
      piVar2 = (int *)_Memory[1];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
      if ((char)_Memory[5] == '\0') {
        _free(_Memory);
      }
      *puVar3 = 0;
    }
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}


// ==== 0x442c20 FUN_00442c20

void FUN_00442c20(int param_1)

{
  int unaff_ESI;
  int *unaff_EDI;
  int local_4;
  
  local_4 = -1;
  if ((*(char *)(unaff_ESI + 0x3d) == '\0') && (*unaff_EDI != 0)) {
    local_4 = (int)*(short *)(*unaff_EDI + 10);
  }
  FUN_00571c20(unaff_ESI,&local_4,1,4,0);
  if (*(char *)(unaff_ESI + 0x3d) != '\0') {
    if (-1 < local_4) {
      *unaff_EDI = *(int *)(param_1 + 0x10 + local_4 * 4);
      return;
    }
    *unaff_EDI = 0;
  }
  return;
}


// ==== 0x442c80 FUN_00442c80

void FUN_00442c80(void)

{
  int unaff_EBX;
  int *unaff_ESI;
  int unaff_EDI;
  int local_4;
  
  local_4 = -1;
  if ((*unaff_ESI != 0) && (unaff_EBX != 0)) {
    local_4 = ((*unaff_ESI - unaff_EBX) + -0x27c) / 0x88;
  }
  FUN_00571c20(unaff_EDI,&local_4,2,4,0);
  if (((*(char *)(unaff_EDI + 0x3c) != '\0' || *(char *)(unaff_EDI + 0x3d) != '\0') &&
      (*unaff_ESI != 0)) && (local_4 == -1)) {
    *unaff_ESI = 0;
  }
  if (*(char *)(unaff_EDI + 0x3d) != '\0') {
    if (-1 < local_4) {
      *unaff_ESI = local_4 * 0x88 + 0x27c + unaff_EBX;
      return;
    }
    *unaff_ESI = 0;
  }
  return;
}


// ==== 0x442d10 FUN_00442d10

/* WARNING: Removing unreachable block (ram,0x00442d88) */

void FUN_00442d10(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_ESI;
  int *unaff_EDI;
  uint local_4;
  
  if (*(char *)(unaff_ESI + 0x3d) == '\0') {
    iVar2 = *unaff_EDI;
    local_4 = 0xffffffff;
    if (iVar2 != 0) {
      iVar1 = *(int *)(unaff_EBX + 0x10 + (uint)*(byte *)(iVar2 + 0x83) * 4);
      local_4 = ((iVar2 - iVar1) + -0x27c) / 0x88 + *(short *)(iVar1 + 10) * 0x10000;
    }
    FUN_00571c20(unaff_ESI,&local_4,4,4,1);
    return;
  }
  local_4 = 0;
  FUN_00571c20(unaff_ESI,&local_4,4,4,1);
  if (local_4 != 0xffffffff) {
    if ((int)local_4 >> 0x10 < 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(unaff_EBX + 0x10 + ((int)local_4 >> 0x10) * 4);
    }
    *unaff_EDI = (local_4 & 0xffff) * 0x88 + 0x27c + iVar2;
    return;
  }
  *unaff_EDI = 0;
  return;
}


// ==== 0x442dd0 RoadNetwork_Load

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 RoadNetwork_Load(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == 0x34121) {
    RoadSections_Parse();
    return 1;
  }
  if (iVar1 == 0x34122) {
    DAT_00736150 = param_1 + 2;
    DAT_00736154 = (uint)param_1[1] >> 5;
    return 1;
  }
  if (iVar1 == 0x34123) {
    DAT_00736158 = param_1 + 2;
    DAT_0073615c = (uint)param_1[1] / 0x170;
    return 1;
  }
  if (iVar1 == 0x34124) {
    DAT_00736160 = param_1 + 2;
    DAT_00736164 = (uint)param_1[1] / 0x108;
    return 1;
  }
  return 0;
}


// ==== 0x442e60 RoadNetwork_Unload

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 RoadNetwork_Unload(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == 0x34121) {
    RoadSections_Unload(param_1);
    return 1;
  }
  if (iVar1 == 0x34122) {
    DAT_00736150 = 0;
    DAT_00736154 = 0;
    return 1;
  }
  if (iVar1 == 0x34123) {
    DAT_00736158 = 0;
    DAT_0073615c = 0;
    return 1;
  }
  if (iVar1 == 0x34124) {
    DAT_00736160 = 0;
    DAT_00736164 = 0;
    return 1;
  }
  return 0;
}


// ==== 0x442ed0 RoadEntries_Sort

/* [canon] traffic med (H) docs/re/traffic.md */

void RoadEntries_Sort(undefined4 *param_1,uint param_2,code *param_3)

{
  int iVar1;
  int in_EAX;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  float10 fVar9;
  int local_18;
  int local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  if (in_EAX < 2) {
    return;
  }
  puVar2 = (undefined4 *)FUN_00565b60(param_2,0,0,0);
  iVar3 = in_EAX / 2 + 1;
  puVar5 = (undefined4 *)((in_EAX + -1) * param_2 + (int)param_1);
  local_8 = (undefined4 *)((in_EAX / 2) * param_2 + (int)param_1);
  local_18 = in_EAX;
  local_10 = iVar3;
  local_c = puVar5;
  do {
    if (iVar3 < 2) {
      puVar7 = puVar5;
      puVar8 = puVar2;
      for (uVar4 = param_2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      for (uVar4 = param_2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      puVar7 = param_1;
      puVar8 = puVar5;
      for (uVar4 = param_2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      for (uVar4 = param_2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      local_18 = local_18 + -1;
      puVar5 = (undefined4 *)((int)puVar5 + -param_2);
      local_c = puVar5;
      if (local_18 == 1) {
        for (uVar4 = param_2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *param_1 = *puVar2;
          puVar2 = puVar2 + 1;
          param_1 = param_1 + 1;
        }
        for (param_2 = param_2 & 3; param_2 != 0; param_2 = param_2 - 1) {
          *(undefined1 *)param_1 = *(undefined1 *)puVar2;
          puVar2 = (undefined4 *)((int)puVar2 + 1);
          param_1 = (undefined4 *)((int)param_1 + 1);
        }
        FUN_00565ce0();
        return;
      }
    }
    else {
      local_8 = (undefined4 *)((int)local_8 + -param_2);
      puVar7 = local_8;
      puVar8 = puVar2;
      for (uVar4 = param_2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      iVar3 = iVar3 + -1;
      for (uVar4 = param_2 & 3; local_10 = iVar3, uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
    }
    iVar1 = iVar3;
    iVar6 = iVar3 * 2;
    while (iVar6 <= local_18) {
      if ((iVar6 < local_18) &&
         (fVar9 = (float10)(*param_3)((undefined4 *)((iVar6 + -1) * param_2 + (int)param_1),
                                      (undefined4 *)(iVar6 * param_2 + (int)param_1)),
         fVar9 < (float10)0.0)) {
        iVar6 = iVar6 + 1;
      }
      puVar7 = (undefined4 *)((int)param_1 + (iVar6 + -1) * param_2);
      fVar9 = (float10)(*param_3)(puVar2,puVar7);
      iVar3 = local_10;
      puVar5 = local_c;
      if ((float10)0.0 <= fVar9) {
        iVar6 = local_18 + 1;
      }
      else {
        puVar8 = (undefined4 *)((iVar1 + -1) * param_2 + (int)param_1);
        for (uVar4 = param_2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        for (uVar4 = param_2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        }
        iVar1 = iVar6;
        iVar6 = iVar6 * 2;
      }
    }
    puVar7 = puVar2;
    puVar8 = (undefined4 *)((iVar1 + -1) * param_2 + (int)param_1);
    for (uVar4 = param_2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    for (uVar4 = param_2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
  } while( true );
}


// ==== 0x443090 FUN_00443090

float10 FUN_00443090(undefined4 *param_1,undefined4 *param_2)

{
  return (float10)*(float *)*param_1 - (float10)*(float *)*param_2;
}


// ==== 0x4430b0 RoadNetwork_PostLoad

/* WARNING: Removing unreachable block (ram,0x004430e6) */
/* [canon] traffic med (H) docs/re/traffic.md */

void RoadNetwork_PostLoad(void)

{
  void *_Memory;
  undefined4 *puVar1;
  byte *pbVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  byte abStack_100 [256];
  
  if (DAT_00736154 != 0) {
    pbVar2 = (byte *)((int)DAT_00736150 + 9);
    uVar6 = DAT_00736154;
    do {
      if (pbVar2[2] == 5) {
        if (pbVar2[4] == 1) {
          *(undefined1 *)((&DAT_0077af30)[*pbVar2] + 0x17) = 1;
        }
        else {
          *(undefined1 *)((&DAT_0077af30)[*pbVar2] + 0x16) = 1;
        }
      }
      pbVar2 = pbVar2 + 0x20;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  uVar6 = 0;
  do {
    if ((-1 < (int)uVar6) && (*(int *)((int)&DAT_0077af30 + uVar6) != 0)) {
      FUN_00442980();
    }
    uVar6 = uVar6 + 4;
  } while (uVar6 < 0x200);
  RoadEntries_FillDistances();
  _Memory = _malloc(DAT_00736154 << 3);
  uVar6 = DAT_00736154;
  uVar3 = 0;
  puVar1 = DAT_00736150;
  if (DAT_00736154 != 0) {
    do {
      *(undefined4 **)((int)_Memory + uVar3 * 8) = puVar1;
      *(uint *)((int)_Memory + uVar3 * 8 + 4) = uVar3;
      uVar3 = uVar3 + 1;
      puVar1 = puVar1 + 8;
    } while (uVar3 < uVar6);
  }
  RoadEntries_Sort(_Memory,8,FUN_00443090);
  uVar6 = DAT_00736154;
  uVar3 = 0;
  if (DAT_00736154 != 0) {
    piVar4 = (int *)((int)_Memory + 4);
    do {
      abStack_100[*piVar4] = (byte)uVar3;
      uVar3 = uVar3 + 1;
      piVar4 = piVar4 + 2;
    } while (uVar3 < DAT_00736154);
  }
  uVar3 = 0;
  do {
    if (((-1 < (int)uVar3) && (iVar5 = *(int *)((int)&DAT_0077af30 + uVar3), iVar5 != 0)) &&
       (iVar8 = 0, 0 < *(short *)(iVar5 + 0x10))) {
      pbVar2 = (byte *)(iVar5 + 0x2fe);
      do {
        if (pbVar2[-1] != 0xff) {
          pbVar2[-1] = abStack_100[pbVar2[-1]];
        }
        if (*pbVar2 != 0xff) {
          *pbVar2 = abStack_100[*pbVar2];
        }
        iVar8 = iVar8 + 1;
        pbVar2 = pbVar2 + 0x88;
      } while (iVar8 < *(short *)(iVar5 + 0x10));
    }
    uVar3 = uVar3 + 4;
  } while (uVar3 < 0x200);
  puVar1 = _malloc(uVar6 << 5);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar7 = puVar1;
    if (-1 < (int)(uVar6 - 1)) {
      do {
        puVar9 = puVar7;
        for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar9 = 0;
          puVar9 = puVar9 + 1;
        }
        *(undefined1 *)(puVar7 + 2) = 0;
        uVar6 = uVar6 - 1;
        puVar7 = puVar7 + 8;
      } while (uVar6 != 0);
    }
  }
  uVar6 = DAT_00736154;
  uVar3 = 0;
  puVar7 = puVar1;
  if (DAT_00736154 != 0) {
    do {
      iVar5 = uVar3 * 8;
      uVar3 = uVar3 + 1;
      puVar9 = *(undefined4 **)((int)_Memory + iVar5);
      puVar10 = puVar7;
      for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      puVar7 = puVar7 + 8;
    } while (uVar3 < uVar6);
  }
  puVar7 = puVar1;
  puVar9 = DAT_00736150;
  for (iVar5 = (uVar6 & 0x7ffffff) << 3; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar9 = puVar9 + 1;
  }
  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
    puVar9 = (undefined4 *)((int)puVar9 + 1);
  }
  _free(_Memory);
  _free(puVar1);
  return;
}


// ==== 0x4432a0 TrackPath::BuildSplines

/* [canon] assets high (Hopper sub_4432a0) docs/re/assets.md */

void TrackPath__BuildSplines(undefined4 *param_1)

{
  undefined4 uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_c;
  int local_8;
  
  *param_1 = *(undefined4 *)(param_1[3] + 0xc);
  local_c = 0;
  if (0 < (int)param_1[2]) {
    local_8 = 0;
    do {
      iVar9 = param_1[3] + local_8;
      if (*(int *)(param_1[3] + 0x24 + local_8) == 0) {
        iVar7 = 2;
        if (*(char *)(iVar9 + 1) != '\0') {
          iVar7 = 0;
        }
        puVar4 = _malloc(0x2c);
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          uVar2 = *(ushort *)(iVar9 + 6);
          *(ushort *)(puVar4 + 7) = uVar2;
          *puVar4 = 0;
          *(undefined1 *)((int)puVar4 + 0x19) = 1;
          pvVar5 = _malloc((uVar2 + 3) * 0x10);
          puVar4[8] = pvVar5;
          puVar4[1] = iVar7;
          puVar4[2] = 0;
          puVar4[10] = &DAT_007376b0;
          puVar4[9] = (int)pvVar5 + 0x10;
          *(undefined1 *)((int)puVar4 + 0x1a) = 2;
          if (iVar7 == 0) {
            *(undefined1 *)((int)puVar4 + 0x1a) = 3;
          }
          puVar4[5] = 0;
          *(undefined1 *)(puVar4 + 6) = 1;
          *(undefined2 *)((int)puVar4 + 0x1e) = 0;
          puVar4[3] = 0;
          puVar4[4] = 0;
          Spline__InitBasis();
        }
        *(undefined4 **)(iVar9 + 0x24) = puVar4;
        FUN_0059cb20();
        iVar7 = 0;
        if (0 < *(short *)(iVar9 + 6)) {
          iVar8 = 0;
          do {
            iVar3 = *(int *)(iVar9 + 0x24);
            puVar4 = (undefined4 *)(param_1[5] + (*(short *)(iVar9 + 2) + iVar7) * 0x14);
            puVar6 = (undefined4 *)(*(int *)(iVar3 + 0x24) + iVar8);
            uVar1 = puVar4[1];
            *puVar6 = *puVar4;
            puVar6[1] = uVar1;
            puVar6[2] = 0;
            puVar6[3] = 0;
            *(undefined1 *)(iVar3 + 0x18) = 1;
            iVar7 = iVar7 + 1;
            iVar8 = iVar8 + 0x10;
          } while (iVar7 < *(short *)(iVar9 + 6));
        }
        FUN_0059d9f0(0x10);
      }
      local_c = local_c + 1;
      local_8 = local_8 + 0x28;
    } while (local_c < (int)param_1[2]);
  }
  return;
}


// ==== 0x4433f0 TrackPath::FreeSplines

/* [canon] assets high (Hopper sub_4433f0) docs/re/assets.md */

void TrackPath__FreeSplines(void)

{
  int iVar1;
  void *_Memory;
  int unaff_EBX;
  int iVar2;
  undefined4 local_4;
  
  iVar2 = 0;
  local_4 = 0;
  if (0 < *(int *)(unaff_EBX + 8)) {
    do {
      iVar1 = *(int *)(unaff_EBX + 0xc);
      _Memory = *(void **)(iVar1 + 0x24 + iVar2);
      if (_Memory != (void *)0x0) {
        if (*(char *)((int)_Memory + 0x19) != '\0') {
          _free(*(void **)((int)_Memory + 0x20));
        }
        _free(_Memory);
        *(undefined4 *)(iVar1 + iVar2 + 0x24) = 0;
      }
      local_4 = local_4 + 1;
      iVar2 = iVar2 + 0x28;
    } while (local_4 < *(int *)(unaff_EBX + 8));
  }
  return;
}


// ==== 0x443450 TrackPath::Init

/* [canon] assets high (Hopper sub_443450 + capstone) docs/re/assets.md */

void __fastcall
TrackPath__Init(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  int in_EAX;
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  *(undefined4 *)(in_EAX + 8) = param_1;
  *(undefined4 *)(in_EAX + 0xc) = param_2;
  *(undefined4 *)(in_EAX + 0x10) = param_4;
  *(undefined4 *)(in_EAX + 0x14) = param_3;
  *(undefined4 *)(in_EAX + 0x18) = param_6;
  iVar1 = 0;
  *(undefined4 *)(in_EAX + 0x1c) = param_5;
  iVar3 = 0;
  piVar4 = (int *)(in_EAX + 0x20);
  do {
    if (iVar1 < *(int *)(in_EAX + 0x18)) {
      piVar2 = (int *)(iVar1 * 0xb4 + *(int *)(in_EAX + 0x1c));
      do {
        if (iVar3 <= *piVar2) break;
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 0x2d;
      } while (iVar1 < *(int *)(in_EAX + 0x18));
    }
    *piVar4 = iVar1;
    iVar3 = iVar3 + 1;
    piVar4 = piVar4 + 1;
    if (10 < iVar3) {
      *(undefined4 *)(in_EAX + 0x4c) = *(undefined4 *)(in_EAX + 0x18);
      TrackPath__BuildSplines(in_EAX);
      return;
    }
  } while( true );
}


// ==== 0x4434d0 TrackPath::Parse

/* [canon] assets high (Hopper sub_4434d0 + Ghidra FUN_004434d0: H+G agree) docs/re/assets.md */

undefined4 TrackPath__Parse(void)

{
  int iVar1;
  uint uVar2;
  int *in_EAX;
  
  if (*in_EAX == -0x7ffcbeb9) {
    iVar1 = in_EAX[3];
    uVar2 = *(uint *)((int)in_EAX + iVar1 + 0x14);
    TrackPath__Init((int)in_EAX + iVar1 + 0x18,uVar2 / 0x14,
                    (int)in_EAX + uVar2 + 0x10 + iVar1 + 0x10,
                    *(uint *)((int)in_EAX + uVar2 + 0xc + iVar1 + 0x10) / 0xb4);
    return 1;
  }
  return 0;
}


// ==== 0x443560 FUN_00443560

void FUN_00443560(undefined4 param_1)

{
  short sVar1;
  int unaff_ESI;
  int *unaff_EDI;
  int local_4;
  
  if (*unaff_EDI == 0) {
    local_4 = -1;
  }
  else {
    local_4 = (*unaff_EDI - *(int *)(unaff_ESI + 0x14)) / 0x14;
  }
  FUN_00571c20(param_1,&local_4,2,2,1);
  sVar1 = (short)local_4;
  if (sVar1 == -1) {
    *unaff_EDI = 0;
    return;
  }
  if (sVar1 < 0) {
    *unaff_EDI = 0;
    return;
  }
  *unaff_EDI = *(int *)(unaff_ESI + 0x14) + sVar1 * 0x14;
  return;
}


// ==== 0x4435e0 TrackPath::SetReverse

/* [canon] track med (ghidra) docs/re/track.md */

void __fastcall TrackPath__SetReverse(float *param_1)

{
  float *pfVar1;
  float in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  
  param_1[1] = in_EAX;
  if ((in_EAX != 0.0) && (iVar3 = 0, 0 < (int)param_1[6])) {
    iVar4 = 0;
    do {
      pfVar1 = (float *)((int)param_1[7] + 0x1c + iVar4);
      iVar2 = (int)param_1[7] + iVar4;
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0xb4;
      *(float *)(iVar2 + 0x1c) = *param_1 - *pfVar1;
      *(float *)(iVar2 + 0x20) = *param_1 - *(float *)(iVar2 + 0x20);
      *(float *)(iVar2 + 0x24) = *param_1 - *(float *)(iVar2 + 0x24);
    } while (iVar3 < (int)param_1[6]);
  }
  return;
}


// ==== 0x443630 TrackPath::FindNearestNode

/* [canon] track high (hopper+ghidra) docs/re/track.md */

float * TrackPath__FindNearestNode(int param_1)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  short *psVar5;
  float *pfVar6;
  float *unaff_EDI;
  float local_8;
  int local_4;
  
  local_4 = *(int *)(param_1 + 8);
  pfVar6 = (float *)0x0;
  local_8 = 0.0;
  if (0 < local_4) {
    psVar5 = (short *)(*(int *)(param_1 + 0xc) + 4);
    do {
      iVar2 = (int)psVar5[-1];
      if (iVar2 < *psVar5) {
        iVar4 = iVar2 * 0x14;
        iVar2 = *psVar5 - iVar2;
        do {
          if (iVar4 < 0) {
            pfVar3 = (float *)0x0;
          }
          else {
            pfVar3 = (float *)(*(int *)(param_1 + 0x14) + iVar4);
          }
          fVar1 = SQRT((*pfVar3 - *unaff_EDI) * (*pfVar3 - *unaff_EDI) +
                       (pfVar3[1] - unaff_EDI[1]) * (pfVar3[1] - unaff_EDI[1]));
          if ((pfVar6 == (float *)0x0) || (fVar1 < local_8)) {
            pfVar6 = pfVar3;
            local_8 = fVar1;
          }
          iVar4 = iVar4 + 0x14;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      psVar5 = psVar5 + 0x14;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return pfVar6;
}


// ==== 0x4436d0 Zone_Find

/* [canon] traffic med (G) docs/re/traffic.md */

int __fastcall Zone_Find(int param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  float *unaff_EDI;
  
  iVar1 = *(int *)(param_1 + 0x24 + param_2 * 4);
  iVar3 = *(int *)(param_1 + 0x20 + param_2 * 4);
  if (in_EAX != 0) {
    iVar3 = (in_EAX - *(int *)(param_1 + 0x1c)) / 0xb4 + 1;
  }
  if (iVar3 < iVar1) {
    iVar4 = iVar3 * 0xb4 + *(int *)(param_1 + 0x1c);
    do {
      if ((*(char *)(iVar4 + 0x18) == -1) || (*(char *)(iVar4 + 0x18) == param_3)) {
        if (*(float *)(iVar4 + 0x28) <= *unaff_EDI) {
          if (*unaff_EDI <= *(float *)(iVar4 + 0x30)) {
            if (*(float *)(iVar4 + 0x2c) <= unaff_EDI[1]) {
              if (unaff_EDI[1] <= *(float *)(iVar4 + 0x34)) {
                cVar2 = PointInPolygon2D(iVar4 + 0x3c,*(undefined4 *)(iVar4 + 0x38));
                if (cVar2 != '\0') {
                  return iVar4;
                }
              }
            }
          }
        }
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0xb4;
    } while (iVar3 < iVar1);
  }
  return 0;
}


// ==== 0x443790 ZoneManager::FindFromTypeMask

/* [canon] track high (hopper+ghidra) docs/re/track.md */

int ZoneManager__FindFromTypeMask(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int *in_EAX;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  if (in_EAX != (int *)0x0) {
    iVar4 = *in_EAX;
  }
  uVar1 = *(undefined4 *)(param_1 + 4);
  while( true ) {
    if ((10 < iVar4) || (uVar3 = param_3 >> ((byte)iVar4 & 0x1f), uVar3 == 0)) {
      return 0;
    }
    if (((uVar3 & 1) != 0) && (iVar2 = Zone_Find(uVar1), iVar2 != 0)) break;
    iVar4 = iVar4 + 1;
  }
  return iVar2;
}


// ==== 0x4437e0 FUN_004437e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_004437e0(float *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  int iVar6;
  float *pfVar7;
  short *psVar8;
  int iVar9;
  float *unaff_ESI;
  float local_c;
  float local_4;
  
  pfVar5 = param_1;
  if (unaff_ESI[1] != 0.0) {
    param_2 = *unaff_ESI - param_2;
  }
  fVar1 = unaff_ESI[2];
  param_1 = (float *)0x0;
  local_c = 0.0;
  pfVar7 = (float *)0x0;
  if (0 < (int)fVar1) {
    psVar8 = (short *)((int)unaff_ESI[3] + 4);
    local_4 = fVar1;
    do {
      iVar6 = (int)psVar8[-1];
      if (iVar6 < *psVar8) {
        iVar9 = iVar6 * 0x14;
        iVar6 = *psVar8 - iVar6;
        do {
          if (iVar9 < 0) {
            pfVar7 = (float *)0x0;
          }
          else {
            pfVar7 = (float *)((int)unaff_ESI[5] + iVar9);
          }
          fVar2 = *pfVar7 - *pfVar5;
          fVar3 = pfVar7[1] - pfVar5[1];
          fVar4 = pfVar7[4] - param_2;
          if ((0 < (int)fVar1) && (*(char *)((int)unaff_ESI[3] + 1) != '\0')) {
            if (*unaff_ESI * -0.5 <= fVar4) {
              if (*unaff_ESI * _K_HALF < fVar4) {
                fVar4 = fVar4 - *unaff_ESI;
              }
            }
            else {
              fVar4 = fVar4 + *unaff_ESI;
            }
          }
          fVar2 = ABS(fVar4 * 0.25) + SQRT(fVar2 * fVar2 + fVar3 * fVar3);
          if ((param_1 == (float *)0x0) || (fVar2 < local_c)) {
            param_1 = pfVar7;
            local_c = fVar2;
          }
          iVar9 = iVar9 + 0x14;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      psVar8 = psVar8 + 0x14;
      local_4 = (float)((int)local_4 + -1);
      pfVar7 = param_1;
    } while (local_4 != 0.0);
  }
  return pfVar7;
}


// ==== 0x443920 TrackPath::NeighbourNodes

/* [canon] track high (hopper+ghidra) docs/re/track.md */

float * __thiscall TrackPath__NeighbourNodes(int param_1,float *param_2)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  int iVar4;
  int in_EAX;
  int iVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  float local_10;
  int local_c [3];
  
  iVar1 = *(int *)(param_1 + 0x14);
  iVar6 = *(int *)(param_1 + 0xc) + *(char *)(in_EAX + 8) * 0x28;
  iVar4 = (in_EAX - iVar1) / 0x14;
  iVar5 = (int)*(short *)(iVar6 + 2);
  iVar7 = 1;
  if (iVar4 == iVar5) {
    if (*(char *)(iVar6 + 1) != '\0') {
      iVar7 = *(short *)(iVar6 + 4) + -1;
      if (iVar7 < 0) {
        local_c[1] = 0;
      }
      else {
        local_c[1] = iVar1 + iVar7 * 0x14;
      }
      goto LAB_0044397c;
    }
  }
  else {
    local_c[1] = in_EAX + -0x14;
LAB_0044397c:
    iVar7 = 2;
  }
  if (iVar4 == *(short *)(iVar6 + 4) + -1) {
    if (*(char *)(iVar6 + 1) == '\0') goto LAB_004439b5;
    if (iVar5 < 0) {
      local_c[iVar7] = 0;
    }
    else {
      local_c[iVar7] = iVar1 + iVar5 * 0x14;
    }
  }
  else {
    local_c[iVar7] = in_EAX + 0x14;
  }
  iVar7 = iVar7 + 1;
LAB_004439b5:
  pfVar8 = (float *)0x0;
  iVar6 = 0;
  local_10 = 0.0;
  if (iVar7 != 0) {
    do {
      pfVar2 = (float *)local_c[iVar6];
      fVar3 = SQRT((*param_2 - *pfVar2) * (*param_2 - *pfVar2) +
                   (param_2[1] - pfVar2[1]) * (param_2[1] - pfVar2[1]));
      if ((pfVar8 == (float *)0x0) || (fVar3 < local_10)) {
        pfVar8 = pfVar2;
        local_10 = fVar3;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar7);
  }
  return pfVar8;
}


// ==== 0x443a10 TrackPath::UpdateCursor

/* [canon] track med (hopper+ghidra) docs/re/track.md */

void TrackPath__UpdateCursor(float *param_1,float *param_2)

{
  float *pfVar1;
  short sVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  float *unaff_ESI;
  int iVar7;
  float10 fVar8;
  float local_2c;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  float local_14;
  
  fVar5 = unaff_ESI[2];
  if ((fVar5 == 0.0) ||
     (128.0 < SQRT((*param_2 - *unaff_ESI) * (*param_2 - *unaff_ESI) +
                   (param_2[1] - unaff_ESI[1]) * (param_2[1] - unaff_ESI[1])))) {
    fVar5 = (float)TrackPath__FindNearestNode(param_1);
  }
  if (fVar5 != 0.0) {
    pfVar6 = (float *)TrackPath__NeighbourNodes(param_2);
    iVar7 = 10;
    local_2c = SQRT((param_2[1] - pfVar6[1]) * (param_2[1] - pfVar6[1]) +
                    (*param_2 - *pfVar6) * (*param_2 - *pfVar6));
    do {
      if (((-1 < *(short *)(iVar7 + (int)pfVar6)) &&
          (pfVar1 = (float *)((int)param_1[5] + *(short *)(iVar7 + (int)pfVar6) * 0x14),
          pfVar1 != (float *)0x0)) &&
         (fVar5 = SQRT((param_2[1] - pfVar1[1]) * (param_2[1] - pfVar1[1]) +
                       (*param_2 - *pfVar1) * (*param_2 - *pfVar1)), fVar5 < local_2c)) {
        pfVar6 = pfVar1;
        local_2c = fVar5;
      }
      iVar7 = iVar7 + 2;
    } while (iVar7 < 0x10);
    iVar7 = (int)param_1[3] + *(char *)(pfVar6 + 2) * 0x28;
    local_2c = unaff_ESI[3];
    if (pfVar6 != (float *)unaff_ESI[2]) {
      fVar5 = param_1[5];
      sVar2 = *(short *)(iVar7 + 2);
      unaff_ESI[2] = (float)pfVar6;
      local_2c = (float)(((int)pfVar6 - (int)fVar5) / 0x14 - (int)sVar2);
    }
    local_20 = *param_2;
    local_1c = param_2[1];
    local_18 = 0;
    fVar8 = (float10)FUN_0059d540(&local_20,local_2c,0x3d4ccccd,0);
    fVar5 = (float)fVar8;
    FUN_0059d350(&local_20,fVar5,0);
    FUN_0059d350(&local_20,fVar5,1);
    fVar4 = local_1c;
    fVar3 = local_20;
    FUN_0059d350(&local_20,fVar5,0);
    local_24 = SQRT(fVar3 * fVar3 + fVar4 * fVar4);
    if (local_24 == 0.0) {
      local_24 = 0.0;
      fVar3 = 1.0;
    }
    else {
      local_24 = 1.0 / local_24;
      fVar3 = local_24 * fVar3;
      local_24 = local_24 * fVar4;
    }
    local_2c = local_14 * *(float *)(iVar7 + 0x10) + *(float *)(iVar7 + 8);
    if (param_1[1] != 0.0) {
      local_2c = *param_1 - local_2c;
      fVar3 = -fVar3;
      local_24 = -local_24;
    }
    unaff_ESI[3] = fVar5;
    fVar5 = *param_2;
    unaff_ESI[1] = param_2[1];
    *unaff_ESI = fVar5;
    unaff_ESI[6] = fVar3;
    unaff_ESI[7] = local_24;
    unaff_ESI[5] = local_2c;
    unaff_ESI[4] = local_2c / *param_1;
    return;
  }
  fVar5 = *param_2;
  unaff_ESI[1] = param_2[1];
  *unaff_ESI = fVar5;
  unaff_ESI[6] = 1.0;
  unaff_ESI[7] = 0.0;
  unaff_ESI[5] = 0.0;
  unaff_ESI[4] = 0.0;
  return;
}


// ==== 0x443c90 FUN_00443c90

void __thiscall FUN_00443c90(undefined4 *param_1,int param_2,undefined4 param_3,float param_4)

{
  int iVar1;
  float fVar2;
  int in_EAX;
  float10 fVar3;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  
  iVar1 = *(int *)(param_2 + 0xc) + in_EAX * 0x28;
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x24) != 0)) {
    fVar3 = (float10)FUN_0059d830(param_3);
    fVar2 = (float)fVar3;
    local_28 = fVar2;
    FUN_0059d350(&local_20,fVar2,0);
    local_24 = local_1c;
    local_28 = local_20;
    FUN_0059d350(&local_20,fVar2,1);
    local_28 = local_1c * param_4 + local_28;
    local_24 = -local_20 * param_4 + local_24;
    local_1c = -local_20;
    TrackPath__UpdateCursor(param_2,&local_28);
    return;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[7] = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[6] = 0x3f800000;
  return;
}


// ==== 0x443d60 TrackPath::WrapDistance

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] track med (hopper+ghidra) docs/re/track.md */

float10 __thiscall TrackPath__WrapDistance(float *param_1,float param_2,float param_3)

{
  float10 fVar1;
  
  fVar1 = (float10)param_2 - (float10)param_3;
  if ((0 < (int)param_1[2]) && (*(char *)((int)param_1[3] + 1) != '\0')) {
    if (fVar1 < (float10)*param_1 * (float10)-0.5) {
      return fVar1 + (float10)*param_1;
    }
    if ((float10)*param_1 * (float10)_K_HALF < fVar1) {
      fVar1 = fVar1 - (float10)*param_1;
    }
  }
  return fVar1;
}


// ==== 0x443db0 FUN_00443db0

float10 FUN_00443db0(float param_1,float param_2)

{
  int in_EAX;
  float10 fVar1;
  
  fVar1 = (float10)param_1 - (float10)param_2;
  if ((0 < *(int *)(in_EAX + 8)) && (*(char *)(*(int *)(in_EAX + 0xc) + 1) != '\0')) {
    if (fVar1 < (float10)-50.0) {
      return fVar1 + (float10)100.0;
    }
    if ((float10)50.0 < fVar1) {
      fVar1 = fVar1 - (float10)100.0;
    }
  }
  return fVar1;
}


// ==== 0x443e00 FUN_00443e00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00443e00(int param_1,float *param_2,float *param_3)

{
  float *pfVar1;
  float fVar2;
  bool bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  bool bVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  float local_28;
  float local_24;
  float local_1c;
  
  local_1c = param_3[1];
  fVar2 = *param_3;
  bVar7 = false;
  bNormalize2();
  iVar9 = *(int *)(param_1 + 0x38);
  if (0 < iVar9) {
    pfVar8 = (float *)(param_1 + 0x3c);
    iVar10 = 1;
    do {
      iVar9 = iVar10 % iVar9;
      fVar6 = *pfVar8 - *(float *)(param_1 + 0x3c + iVar9 * 8);
      fVar4 = pfVar8[1] - *(float *)(param_1 + 0x40 + iVar9 * 8);
      fVar5 = SQRT(fVar6 * fVar6 + fVar4 * fVar4);
      pfVar1 = (float *)(param_1 + 0x3c + iVar9 * 8);
      if (fVar5 == 0.0) {
        fVar4 = 0.0;
        fVar6 = _K_ONE;
      }
      else {
        fVar5 = _K_ONE / fVar5;
        fVar4 = fVar5 * fVar4;
        fVar6 = fVar6 * fVar5;
      }
      if (local_28 * fVar6 + local_24 * fVar4 == _K_ONE) {
        fVar2 = fVar2 - *pfVar8;
        local_1c = local_1c - pfVar8[1];
        fVar5 = SQRT(fVar2 * fVar2 + local_1c * local_1c);
        if (fVar5 == 0.0) {
          local_1c = 0.0;
          fVar2 = _K_ONE;
        }
        else {
          fVar5 = _K_ONE / fVar5;
          local_1c = fVar5 * local_1c;
          fVar2 = fVar2 * fVar5;
        }
        if (0.001 < ABS(fVar2 - fVar6)) {
          return 0;
        }
        if (0.001 < ABS(local_1c - fVar4)) {
          return 0;
        }
        fVar2 = *param_3;
        param_2[1] = param_3[1];
        *param_2 = fVar2;
        return 1;
      }
      fVar5 = local_28 * fVar4 - local_24 * fVar6;
      if (((0.001 <= fVar5) || (fVar5 <= -0.001)) &&
         (fVar5 = ((local_1c - pfVar8[1]) * fVar6 - (fVar2 - *pfVar8) * fVar4) / fVar5, 0.0 <= fVar5
         )) {
        fVar6 = local_28 * fVar5 + fVar2;
        fVar4 = fVar5 * local_24 + local_1c;
        if (((*pfVar1 - fVar6) * (*pfVar8 - fVar6) + (pfVar1[1] - fVar4) * (pfVar8[1] - fVar4) < 0.0
            ) && (!bVar7)) {
          param_2[1] = fVar4;
          bVar7 = true;
          *param_2 = fVar6;
        }
      }
      iVar9 = *(int *)(param_1 + 0x38);
      pfVar8 = pfVar8 + 2;
      bVar3 = iVar10 < iVar9;
      iVar10 = iVar10 + 1;
    } while (bVar3);
    if (bVar7) {
      return 1;
    }
  }
  return 0;
}


// ==== 0x4440c0 FUN_004440c0

void FUN_004440c0(undefined4 param_1)

{
  undefined4 *in_EAX;
  
  *in_EAX = 0;
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  in_EAX[7] = 0;
  in_EAX[8] = 0;
  in_EAX[9] = 0;
  in_EAX[6] = 0x3f800000;
  TrackPath__UpdateCursor(&DAT_007372b0,param_1);
  return;
}


// ==== 0x444100 FUN_00444100

void FUN_00444100(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"TrackPathCoordinate");
  FUN_00571c20(param_2,param_1,8,0xffffffff,0);
  FUN_00443560(param_2);
  FUN_00571c20(param_2,param_1 + 0xc,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x10,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x14,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x18,8,0xffffffff,0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x4441b0 FUN_004441b0

void FUN_004441b0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + 8) = 0;
  iVar1 = FUN_004437e0(param_1,param_2);
  if (iVar1 != 0) {
    TrackPath__UpdateCursor(&DAT_007372b0,iVar1);
  }
  TrackPath__UpdateCursor(&DAT_007372b0,param_1);
  return;
}


// ==== 0x4441f0 TrackPath::Loader

/* [canon] assets high (Hopper sub_4441f0 + Ghidra make FUN_004441f0: H+G agree) docs/re/assets.md
    */

void TrackPath__Loader(void)

{
  TrackPath__Parse(&DAT_007372b0);
  return;
}


// ==== 0x444200 TrackPath::Unloader

/* [canon] assets high (Hopper sub_444200 + Ghidra make FUN_00444200: H+G agree) docs/re/assets.md
    */

undefined4 TrackPath__Unloader(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (*param_1 == -0x7ffcbeb9) {
    TrackPath__FreeSplines();
    DAT_007372b8 = 0;
    DAT_007372bc = 0;
    DAT_007372c0 = 0;
    DAT_007372c4 = 0;
    DAT_007372c8 = 0;
    DAT_007372cc = 0;
    puVar2 = &DAT_007372d0;
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    DAT_007372b0 = 0;
    return 1;
  }
  return 0;
}


// ==== 0x444260 FUN_00444260

undefined4 __fastcall FUN_00444260(int param_1)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x7c + param_1 * 4);
}


// ==== 0x4442a0 StreamSections::Loader

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (Hopper sub_4442a0 + Ghidra make FUN_004442a0: H+G agree) docs/re/assets.md
    */

undefined4 StreamSections__Loader(int *param_1)

{
  if (*param_1 == 0x34107) {
    _DAT_0077a980 = param_1 + 2;
    _DAT_0077a984 = (uint)param_1[1] / 0x38;
    return 1;
  }
  if (*param_1 == 0x34108) {
    _DAT_0077a988 = param_1 + 2;
    return 1;
  }
  return 0;
}


// ==== 0x4442f0 StreamSections::Unloader

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (Hopper sub_4442f0 + Ghidra make FUN_004442f0: H+G agree) docs/re/assets.md
    */

undefined4 StreamSections__Unloader(int *param_1)

{
  if (*param_1 == 0x34107) {
    StreamSections__Shutdown();
    _DAT_0077a980 = 0;
    _DAT_0077a984 = 0;
    return 1;
  }
  if (*param_1 == 0x34108) {
    _DAT_0077a988 = 0;
    return 1;
  }
  return 0;
}


// ==== 0x444340 FUN_00444340

void FUN_00444340(void)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  int iVar2;
  
  puVar1 = in_EAX + 0x164;
  *puVar1 = puVar1;
  in_EAX[0x165] = puVar1;
  *in_EAX = 0;
  in_EAX[1] = 0;
  in_EAX[3] = 0;
  in_EAX[4] = 0;
  in_EAX[0x5f] = 0;
  in_EAX[0x5d] = 0;
  *(undefined1 *)(in_EAX + 0x5e) = 0;
  *(undefined1 *)((int)in_EAX + 0x179) = 0;
  iVar2 = StreamSections__ResetRound();
  *(undefined4 *)(iVar2 + 0xd4) = 0;
  *(undefined4 *)(iVar2 + 0xd8) = 0;
  *(undefined4 *)(iVar2 + 0xdc) = 0;
  *(undefined4 *)(iVar2 + 0xe0) = 0;
  *(undefined1 *)(iVar2 + 0xe4) = 0;
  *(undefined4 *)(iVar2 + 0x118) = 0;
  *(undefined4 *)(iVar2 + 0x11c) = 0;
  *(undefined4 *)(iVar2 + 0x120) = 0;
  *(undefined4 *)(iVar2 + 0x124) = 0;
  *(undefined1 *)(iVar2 + 0x128) = 0;
  *(undefined4 *)(iVar2 + 0x580) = 0;
  *(undefined4 *)(iVar2 + 0x584) = 0;
  *(undefined4 *)(iVar2 + 0x588) = 0;
  *(undefined4 *)(iVar2 + 0x58c) = 0;
  *(undefined4 *)(iVar2 + 0x598) = 0;
  return;
}


// ==== 0x4443e0 StreamSections::ResetRound

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] track high (hopper+ghidra+capstone) docs/re/track.md */

void StreamSections__ResetRound(void)

{
  int in_EAX;
  int iVar1;
  int *piVar2;
  
  *(undefined4 *)(in_EAX + 0xf0) = 0;
  *(undefined4 *)(in_EAX + 0xf4) = 0;
  *(undefined4 *)(in_EAX + 0x134) = 0;
  *(undefined4 *)(in_EAX + 0x138) = 0;
  *(undefined2 *)(in_EAX + 0xe6) = 0xffff;
  *(undefined2 *)(in_EAX + 0x12a) = 0xffff;
  iVar1 = 0;
  *(undefined1 *)(in_EAX + 0x15c) = 0;
  *(undefined1 *)(in_EAX + 0x160) = 0;
  _DAT_006f3dac = 1;
  *(undefined1 *)(in_EAX + 0x15d) = 0;
  *(undefined1 *)(in_EAX + 0x15e) = 0;
  *(undefined1 *)(in_EAX + 0x15f) = 0;
  *(undefined1 *)(in_EAX + 0x161) = 0;
  *(undefined4 *)(in_EAX + 0x16c) = 0;
  *(undefined4 *)(in_EAX + 0x170) = 0;
  if (0 < *(int *)(in_EAX + 0x17c)) {
    piVar2 = (int *)(in_EAX + 0x180);
    do {
      *(undefined1 *)(*piVar2 + 0xb) = 0;
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < *(int *)(in_EAX + 0x17c));
  }
  *(undefined4 *)(in_EAX + 0x17c) = 0;
  return;
}


// ==== 0x444480 StreamSections::Init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] track high (hopper+ghidra) docs/re/track.md */

void __fastcall StreamSections__Init(int param_1)

{
  undefined4 in_EAX;
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x584) = in_EAX;
  uVar1 = FUN_00565b60();
  *(undefined4 *)(param_1 + 0x580) = uVar1;
  DAT_007301d8 = &DAT_00730250;
  bInitMemoryPool(uVar1,"Track Streaming");
  DAT_007301d8[0x38] = 0;
  if (DAT_00736144 != 0) {
    _DAT_00736134 = 1;
  }
  return;
}


// ==== 0x4444f0 FUN_004444f0

void FUN_004444f0(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int unaff_EDI;
  
  puVar3 = (undefined4 *)(in_EAX + 0x590);
  for (puVar2 = *(undefined4 **)(in_EAX + 0x590); puVar2 != puVar3; puVar2 = (undefined4 *)*puVar2)
  {
    if (unaff_EDI == *(short *)(puVar2 + 2)) {
      return;
    }
  }
  puVar2 = _malloc(0xc);
  if (puVar2 == (undefined4 *)0x0) {
    puRam00000004 = *(undefined4 **)(in_EAX + 0x594);
    *puRam00000004 = 0;
    *(undefined4 *)(in_EAX + 0x594) = 0;
    puRam00000000 = puVar3;
    return;
  }
  *(short *)(puVar2 + 2) = (short)unaff_EDI;
  puVar1 = *(undefined4 **)(in_EAX + 0x594);
  *puVar1 = puVar2;
  *(undefined4 **)(in_EAX + 0x594) = puVar2;
  *puVar2 = puVar3;
  puVar2[1] = puVar1;
  return;
}


// ==== 0x444545 FUN_00444545

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00444545(void)

{
  _DAT_00736134 = 1;
  return;
}


// ==== 0x444548 FUN_00444548

void FUN_00444548(void)

{
  int *in_stack_0000001c;
  
  *in_stack_0000001c = (int)(*in_stack_0000001c + (int)in_stack_0000001c);
  *(char *)in_stack_0000001c = (char)*in_stack_0000001c + (char)in_stack_0000001c;
  return;
}


// ==== 0x444550 FUN_00444550

void __fastcall FUN_00444550(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *_Memory;
  
  _Memory = *(int **)(param_1 + 0x590);
  if (_Memory != (int *)(param_1 + 0x590)) {
    while (param_2 != (short)_Memory[2]) {
      _Memory = (int *)*_Memory;
      if (_Memory == (int *)(param_1 + 0x590)) {
        return;
      }
    }
    iVar1 = *_Memory;
    piVar2 = (int *)_Memory[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    _free(_Memory);
  }
  return;
}


// ==== 0x444590 FUN_00444590

void FUN_00444590(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int in_EAX;
  int *piVar4;
  
  piVar4 = (int *)(in_EAX + 0x590);
  piVar1 = *(int **)(in_EAX + 0x590);
  while (piVar1 != piVar4) {
    piVar1 = (int *)*piVar4;
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(piVar1);
    piVar1 = (int *)*piVar4;
  }
  return;
}


// ==== 0x4445c0 StreamSections::SetTrack

/* [canon] track high (hopper+ghidra) docs/re/track.md */

void __fastcall StreamSections__SetTrack(char *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  cVar2 = *param_2;
  pcVar1 = (char *)(in_EAX + 0x54);
  *pcVar1 = cVar2;
  if (cVar2 != '\0') {
    pcVar4 = pcVar1;
    do {
      cVar2 = pcVar4[(int)(param_2 + (1 - (int)pcVar1))];
      pcVar4 = pcVar4 + 1;
      *pcVar4 = cVar2;
    } while (cVar2 != '\0');
  }
  cVar2 = *param_1;
  pcVar1 = (char *)(in_EAX + 0x94);
  *pcVar1 = cVar2;
  if (cVar2 != '\0') {
    pcVar4 = pcVar1;
    do {
      cVar2 = pcVar4[(int)(param_1 + (1 - (int)pcVar1))];
      pcVar4 = pcVar4 + 1;
      *pcVar4 = cVar2;
    } while (cVar2 != '\0');
  }
  iVar9 = DAT_00736174;
  if (((DAT_00736174 != 0) && (0x44e < *(short *)(DAT_00736174 + 0x6c))) &&
     (*(short *)(DAT_00736174 + 0x6c) < 0x456)) {
    uVar5 = DAT_006f227c ^ 0x1d872b41;
    uVar7 = uVar5 >> 5 ^ uVar5;
    DAT_006f227c = uVar7 << 0x1b ^ uVar7 ^ uVar5;
  }
  *(undefined1 *)(in_EAX + 0x178) = 0;
  iVar3 = StreamSections__ResetRound();
  puVar6 = (undefined4 *)(iVar3 + 0xd8);
  iVar8 = 2;
  do {
    puVar6[-1] = 0;
    *puVar6 = 0;
    puVar6[1] = 0;
    puVar6[2] = 0;
    *(undefined1 *)(puVar6 + 3) = 0;
    puVar6 = puVar6 + 0x11;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  puVar6 = (undefined4 *)(iVar3 + 0xec);
  iVar8 = 2;
  do {
    *(undefined2 *)(puVar6 + -1) = 0;
    *puVar6 = 0;
    *(undefined1 *)(puVar6 + 3) = 0;
    puVar6[4] = 0;
    puVar6[5] = 0;
    puVar6[6] = 0;
    *(undefined1 *)(puVar6 + 7) = 0;
    puVar6[8] = 0;
    puVar6[9] = 0;
    puVar6[10] = 0;
    puVar6 = puVar6 + 0x11;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  puVar6 = DAT_0077a950;
  if (iVar9 == 0) {
    iVar9 = 0;
  }
  else {
    iVar9 = (int)*(short *)(iVar9 + 0x6c);
  }
  while( true ) {
    if ((undefined4 **)puVar6 == &DAT_0077a950) {
      *(undefined4 *)(iVar3 + 0x598) = 0;
      return;
    }
    if (puVar6[2] == iVar9) break;
    puVar6 = (undefined4 *)*puVar6;
  }
  *(undefined4 **)(iVar3 + 0x598) = puVar6;
  return;
}


// ==== 0x4446e0 StreamSections::IssueRead

/* [canon] track high (hopper+ghidra) docs/re/track.md */

void StreamSections__IssueRead(void)

{
  int in_EAX;
  int iVar1;
  int unaff_ESI;
  
  *(int *)(in_EAX + 0x10) = *(int *)(in_EAX + 0x10) + 1;
  *(undefined4 *)(unaff_ESI + 0xc) = 2;
  iVar1 = CreateResourceFile(*(int *)(unaff_ESI + 0x10) * 0x40 + 0x14 + in_EAX,4,0x20,
                             *(undefined4 *)(unaff_ESI + 0x14),*(undefined4 *)(unaff_ESI + 0x18));
  *(int *)(unaff_ESI + 0x28) = iVar1;
  DAT_00735554 = DAT_00735554 + 1;
  *(undefined4 *)(iVar1 + 0x9c) = *(undefined4 *)(unaff_ESI + 0x2c);
  FUN_00448070(unaff_ESI);
  ResourceFile__BeginLoading();
  return;
}


// ==== 0x444740 StreamSections::OnReadDone

/* [canon] track high (hopper+capstone) docs/re/track.md */

void StreamSections__OnReadDone(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 3;
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x9c);
  DAT_0077a990 = DAT_0077a990 + -1;
  DAT_0077a98c = DAT_0077a98c + 1;
  DAT_00735554 = DAT_00735554 + -1;
  return;
}


// ==== 0x444780 StreamSections::EvictOldest

/* [canon] track high (hopper+ghidra+capstone) docs/re/track.md */

undefined4 StreamSections__EvictOldest(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  if (0 < param_1[1]) {
    iVar3 = *param_1;
    iVar4 = param_1[1];
    do {
      if (((*(int *)(iVar3 + 0xc) == 3) && (*(char *)(iVar3 + 0xb) == '\0')) &&
         ((iVar5 == 0 || (*(int *)(iVar3 + 0x24) < *(int *)(iVar5 + 0x24))))) {
        iVar5 = iVar3;
      }
      iVar3 = iVar3 + 0x38;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if (iVar5 != 0) {
      piVar1 = *(int **)(iVar5 + 0x28);
      iVar3 = piVar1[0x24];
      while (iVar3 == 0) {
        ServiceResourceLoading();
        iVar3 = piVar1[0x24];
      }
      iVar3 = *piVar1;
      piVar2 = (int *)piVar1[1];
      *piVar2 = iVar3;
      *(int **)(iVar3 + 4) = piVar2;
      ResourceFile__UnloadChunks();
      iVar4 = DAT_007360f8;
      iVar3 = *(int *)(DAT_007360f8 + 0x18);
      *piVar1 = *(int *)(DAT_007360f8 + 0x10);
      *(int **)(iVar4 + 0x10) = piVar1;
      *(int *)(iVar4 + 0x18) = iVar3 + -1;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      *(undefined4 *)(iVar5 + 0xc) = 0;
      *(undefined4 *)(iVar5 + 0x2c) = 0;
      param_1[3] = param_1[3] + -1;
      return *(undefined4 *)(iVar5 + 0x18);
    }
  }
  return 0;
}


// ==== 0x444830 FUN_00444830

undefined4 FUN_00444830(void)

{
  return 0;
}


// ==== 0x444840 StreamSections::SeedViewer

/* [canon] track high (hopper+ghidra) docs/re/track.md */

void __fastcall StreamSections__SeedViewer(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_EAX;
  
  uVar2 = *param_1;
  *(undefined4 *)(in_EAX * 0x44 + 0xd8 + param_2) = param_1[1];
  puVar1 = (undefined4 *)(in_EAX * 0x44 + 0xd4 + param_2);
  *puVar1 = uVar2;
  puVar1[2] = 0;
  puVar1[3] = 0;
  *(undefined1 *)(puVar1 + 4) = 1;
  puVar1[6] = 0xffffffff;
  *(undefined2 *)(puVar1 + 5) = 0;
  return;
}


// ==== 0x444870 StreamSections::PredictBoundary

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] track high (hopper+ghidra+capstone) docs/re/track.md */

undefined4 StreamSections__PredictBoundary(int param_1,float *param_2)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  short *psVar9;
  int iVar10;
  float *pfVar11;
  int local_30;
  short asStack_28 [4];
  float local_20;
  float local_1c;
  float local_18 [6];
  
  fVar4 = SQRT(param_2[2] * param_2[2] + param_2[3] * param_2[3]);
  if (fVar4 <= 178.81091) {
    if (fVar4 * 1.5 <= 100.0) {
      fVar2 = param_2[2] * 1.5 + *param_2;
      fVar3 = 1.5;
    }
    else {
      fVar3 = 100.0 / fVar4;
      fVar2 = fVar3 * param_2[2] + *param_2;
    }
    fVar3 = fVar3 * param_2[3] + param_2[1];
  }
  else {
    fVar2 = *param_2;
    fVar3 = param_2[1];
  }
  local_20 = fVar2 - *param_2;
  local_30 = 0;
  pfVar11 = local_18;
  local_1c = fVar3 - param_2[1];
  do {
    asStack_28[local_30] = -1;
    *pfVar11 = local_20 * (float)local_30 * _K_HALF + *param_2;
    pfVar11[1] = local_1c * (float)local_30 * _K_HALF + param_2[1];
    if (17.88109 < fVar4) {
      iVar6 = Zone_Find(0);
      while (iVar6 != 0) {
        if (0.0 < local_20 * *(float *)(iVar6 + 0xc) + local_1c * *(float *)(iVar6 + 0x10)) {
          piVar7 = (int *)(iVar6 + 0x80);
          bVar5 = false;
          iVar10 = 1;
          if (*(int *)(iVar6 + 0x80) != 0) {
            do {
              if (0xd < iVar10) break;
              if (DAT_00736174 == 0) {
                iVar8 = 0;
              }
              else {
                iVar8 = (int)*(short *)(DAT_00736174 + 0x6c);
              }
              if (*piVar7 == iVar8) {
                bVar5 = true;
                break;
              }
              piVar1 = piVar7 + 1;
              piVar7 = piVar7 + 1;
              iVar10 = iVar10 + 1;
            } while (*piVar1 != 0);
            if ((iVar10 != 1) && (!bVar5)) goto LAB_004449dd;
          }
          asStack_28[local_30] = *(short *)(iVar6 + 0x7c);
          break;
        }
LAB_004449dd:
        iVar6 = Zone_Find(0);
      }
    }
    if ((asStack_28[local_30] == -1) &&
       (iVar6 = StreamBoundaries__FindContaining(pfVar11), iVar6 != 0)) {
      if ((local_30 == 0) || (iVar10 = *(int *)(param_1 + 0x598), iVar10 == 0)) {
LAB_00444a51:
        asStack_28[local_30] = *(short *)(iVar6 + 8);
      }
      else {
        iVar8 = 0;
        if (0 < *(int *)(iVar10 + 0xc)) {
          psVar9 = (short *)(iVar10 + 0x10);
          do {
            if (*psVar9 == *(short *)(iVar6 + 8)) goto LAB_00444a51;
            iVar8 = iVar8 + 1;
            psVar9 = psVar9 + 1;
          } while (iVar8 < *(int *)(iVar10 + 0xc));
        }
      }
    }
    local_30 = local_30 + 1;
    pfVar11 = pfVar11 + 2;
    if (2 < local_30) {
      iVar6 = 1;
      do {
        if (asStack_28[iVar6] == -1) {
          return CONCAT22((short)((uint)iVar6 >> 0x10),asStack_28[iVar6 + -1]);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < 3);
      return CONCAT22((short)((uint)iVar6 >> 0x10),asStack_28[2]);
    }
  } while( true );
}


// ==== 0x444ab0 FUN_00444ab0

void FUN_00444ab0(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0xd4) = 0;
  *(undefined4 *)(in_EAX + 0xd8) = 0;
  *(undefined4 *)(in_EAX + 0xdc) = 0;
  *(undefined4 *)(in_EAX + 0xe0) = 0;
  *(undefined1 *)(in_EAX + 0xe4) = 0;
  *(undefined4 *)(in_EAX + 0x118) = 0;
  *(undefined4 *)(in_EAX + 0x11c) = 0;
  *(undefined4 *)(in_EAX + 0x120) = 0;
  *(undefined4 *)(in_EAX + 0x124) = 0;
  *(undefined1 *)(in_EAX + 0x128) = 0;
  return;
}


// ==== 0x444af0 StreamSections::ComputePoolSize

/* [canon] track high (hopper+ghidra+capstone) docs/re/track.md */

int __fastcall StreamSections__ComputePoolSize(undefined4 param_1,int *param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = param_2[1];
  iVar6 = 0;
  iVar2 = 0;
  if (0 < iVar5) {
    psVar4 = (short *)(*param_2 + 8);
    do {
      if (((((char)psVar4[1] != '\0') || (sVar1 = *psVar4, sVar1 == 0x9c4)) || (sVar1 == 0x960)) ||
         ((sVar1 == 0xa28 || (sVar1 == 0x9c3)))) {
        iVar3 = *(int *)(psVar4 + 10);
        iVar6 = iVar6 + iVar3;
        if ((*(int *)(psVar4 + 8) != iVar3) &&
           (iVar3 = iVar3 + *(int *)(psVar4 + 8), iVar2 <= iVar3)) {
          iVar2 = iVar3;
        }
      }
      psVar4 = psVar4 + 0x1c;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    if (iVar2 < iVar6) {
      iVar2 = iVar6;
    }
  }
  return iVar2;
}


// ==== 0x444b50 StreamSections::BuildWantedSet

/* [canon] track high (hopper+ghidra+capstone) docs/re/track.md */

void StreamSections__BuildWantedSet(int *param_1)

{
  short sVar1;
  undefined4 *puVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  short *psVar12;
  int local_314;
  short *local_310;
  int local_30c;
  short local_308 [4];
  int local_300 [191];
  
  local_308[0] = 0x9c4;
  local_308[1] = 0x960;
  local_308[2] = 0xa28;
  local_308[3] = 0x9c3;
  local_314 = 4;
  if (DAT_00736174 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = (int)*(short *)(DAT_00736174 + 0x6c);
  }
  puVar2 = DAT_0077a958;
  if ((undefined4 **)DAT_0077a958 != &DAT_0077a958) {
    do {
      if (puVar2[2] == iVar5) {
        uVar7 = puVar2[3];
        if (0 < (int)uVar7) {
          piVar10 = puVar2 + 4;
          piVar11 = local_300;
          for (uVar6 = uVar7 >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
            *piVar11 = *piVar10;
            piVar10 = piVar10 + 1;
            piVar11 = piVar11 + 1;
          }
          local_314 = uVar7 + 4;
          for (uVar7 = (uint)((uVar7 & 1) != 0); uVar7 != 0; uVar7 = uVar7 - 1) {
            *(short *)piVar11 = (short)*piVar10;
            piVar10 = (int *)((int)piVar10 + 2);
            piVar11 = (int *)((int)piVar11 + 2);
          }
        }
        break;
      }
      puVar2 = (undefined4 *)*puVar2;
    } while ((undefined4 **)puVar2 != &DAT_0077a958);
  }
  if ((DAT_0073612c != 0) && (DAT_00736130 != 0)) {
    local_308[local_314] = (short)DAT_00736130;
    local_314 = local_314 + 1;
  }
  piVar10 = (int *)param_1[0x164];
  iVar5 = local_314;
  while (piVar10 != param_1 + 0x164) {
    piVar11 = piVar10 + 2;
    piVar10 = (int *)*piVar10;
    local_308[iVar5] = (short)*piVar11;
    iVar5 = iVar5 + 1;
  }
  local_310 = (short *)((int)param_1 + 0xe6);
  local_30c = 2;
  local_314 = iVar5;
  do {
    puVar2 = DAT_0077a940;
    if (0 < *local_310) {
      for (; (undefined4 **)puVar2 != &DAT_0077a940; puVar2 = (undefined4 *)*puVar2) {
        if (*(short *)(puVar2 + 2) == *local_310) goto LAB_00444c59;
      }
      puVar2 = (undefined4 *)0x0;
LAB_00444c59:
      uVar7 = puVar2[4];
      if (0 < (int)uVar7) {
        psVar3 = (short *)(puVar2 + 5);
        psVar12 = local_308 + iVar5;
        for (uVar6 = uVar7 >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)psVar12 = *(undefined4 *)psVar3;
          psVar3 = psVar3 + 2;
          psVar12 = psVar12 + 2;
        }
        iVar5 = local_314 + uVar7;
        for (uVar7 = (uint)((uVar7 & 1) != 0); local_314 = iVar5, uVar7 != 0; uVar7 = uVar7 - 1) {
          *psVar12 = *psVar3;
          psVar3 = psVar3 + 1;
          psVar12 = psVar12 + 1;
        }
      }
    }
    local_310 = local_310 + 0x22;
    local_30c = local_30c + -1;
  } while (local_30c != 0);
  if (((char)param_1[0x5e] == '\0') && (0 < param_1[1])) {
    iVar8 = param_1[1];
    psVar3 = (short *)(*param_1 + 8);
    do {
      if ((char)psVar3[1] != '\0') {
        local_308[iVar5] = *psVar3;
        iVar5 = iVar5 + 1;
      }
      psVar3 = psVar3 + 0x1c;
      iVar8 = iVar8 + -1;
      local_314 = iVar5;
    } while (iVar8 != 0);
  }
  if ((DAT_0078a320 == 2) && (iVar8 = 0, 0 < iVar5)) {
    do {
      sVar1 = local_308[iVar8];
      if (((char)((int)sVar1 / 100) == '\x19') && ((int)sVar1 % 100 < 0x32)) {
        local_308[iVar8] = sVar1 + 0x32;
      }
      iVar8 = iVar8 + 1;
      iVar5 = local_314;
    } while (iVar8 < local_314);
  }
  iVar8 = 0;
  param_1[0x5f] = 0;
  if (0 < iVar5) {
    do {
      iVar9 = 0;
      if (0 < param_1[1]) {
        iVar4 = *param_1;
        do {
          if (*(short *)(iVar4 + 8) == local_308[iVar8]) {
            *(undefined4 *)(iVar4 + 0x24) = DAT_006f0888;
            if (*(char *)(iVar4 + 0xb) == '\0') {
              *(undefined1 *)(iVar4 + 0xb) = 1;
              if (param_1[0x5f] == 0x100) {
                return;
              }
              param_1[param_1[0x5f] + 0x60] = iVar4;
              param_1[0x5f] = param_1[0x5f] + 1;
            }
            break;
          }
          iVar9 = iVar9 + 1;
          iVar4 = iVar4 + 0x38;
        } while (iVar9 < param_1[1]);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar5);
  }
  return;
}


// ==== 0x444d80 StreamSections::AllocateRow

/* [canon] track high (hopper+ghidra) docs/re/track.md */

int StreamSections__AllocateRow(int param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar6 = 0;
  local_8 = 0;
  local_4 = 0;
  if (0 < *(int *)(param_1 + 0x17c)) {
    iVar7 = 0x180;
    do {
      iVar1 = *(int *)(param_1 + iVar7);
      if (*(int *)(iVar1 + 0xc) == 0) {
        if (DAT_007301d8 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_00565810();
          iVar4 = iVar4 + -0x58;
          if (iVar4 < 0) {
            iVar4 = 0;
          }
        }
        iVar2 = *(int *)(iVar1 + 0x18);
        if (iVar4 < iVar2 + 0x400) {
          local_8 = local_8 + iVar2;
        }
        else {
          iVar4 = FUN_00565b60(iVar2,0,0,0x2011);
          if (iVar4 == 0) {
            pcVar3 = (code *)swi(3);
            iVar6 = (*pcVar3)();
            return iVar6;
          }
          *(int *)(iVar1 + 0x2c) = iVar4;
          *(undefined4 *)(iVar1 + 0xc) = 1;
          uVar5 = 0;
          if (DAT_007301d8 != 0) {
            uVar5 = bMemoryPool_TotalAllocated();
          }
          *(undefined4 *)(iVar1 + 0x30) = uVar5;
          if (DAT_007301d8 == 0) {
LAB_00444e27:
            iVar4 = 0;
          }
          else {
            iVar4 = FUN_00565810();
            iVar4 = iVar4 + -0x58;
            if (iVar4 < 0) goto LAB_00444e27;
          }
          *(int *)(iVar1 + 0x34) = iVar4;
          local_4 = local_4 + 1;
          if (1 < local_4) {
            *(undefined1 *)(param_1 + 0x15f) = 1;
            return local_8;
          }
        }
      }
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 4;
    } while (iVar6 < *(int *)(param_1 + 0x17c));
  }
  *(undefined1 *)(param_1 + 0x15f) = 0;
  return local_8;
}


// ==== 0x444e90 StreamSections::FreeUnreadBuffers

/* [canon] track high (hopper+ghidra+capstone) docs/re/track.md */

void StreamSections__FreeUnreadBuffers(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  if (0 < param_1[1]) {
    iVar3 = 0;
    do {
      iVar2 = *param_1 + iVar3;
      if (*(int *)(*param_1 + 0xc + iVar3) == 1) {
        FUN_00565ce0();
        *(undefined4 *)(iVar2 + 0x2c) = 0;
        *(undefined4 *)(iVar2 + 0xc) = 0;
      }
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < param_1[1]);
  }
  return;
}


// ==== 0x444ee0 StreamSections::AllocateRequested

/* [canon] track high (hopper+ghidra+capstone) docs/re/track.md */

uint StreamSections__AllocateRequested(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *unaff_ESI;
  
  iVar5 = 0;
  iVar4 = 0;
  StreamSections__FreeUnreadBuffers(unaff_ESI);
  uVar1 = StreamSections__AllocateRow(unaff_ESI);
  do {
    if (uVar1 == 0) {
LAB_00444f55:
      unaff_ESI[0x5c] = 0;
      iVar5 = 0;
      if (DAT_007301d8 != 0) {
        iVar5 = bMemoryPool_TotalAllocated();
      }
      iVar5 = iVar5 - uVar1;
      if (0 < unaff_ESI[1]) {
        iVar4 = unaff_ESI[1];
        piVar3 = (int *)(*unaff_ESI + 0xc);
        do {
          if ((*(char *)((int)piVar3 + -1) == '\0') && (*piVar3 != 0)) {
            iVar5 = iVar5 + piVar3[4];
          }
          piVar3 = piVar3 + 0xe;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      unaff_ESI[0x5c] = iVar5;
      return CONCAT31((int3)((uint)iVar5 >> 8),1);
    }
    if ((0x9c3c00 < iVar5) || (0x9c3c00 < iVar4)) {
      return uVar1 & 0xffffff00;
    }
    StreamSections__FreeUnreadBuffers(unaff_ESI);
    iVar2 = StreamSections__EvictOldest(unaff_ESI);
    iVar5 = iVar5 + iVar2;
    if (iVar2 < 1) {
      iVar2 = FUN_00444830(unaff_ESI);
      iVar4 = iVar4 + iVar2;
      if (iVar2 == 0) {
        *(undefined1 *)(unaff_ESI + 0x58) = 1;
        StreamSections__AllocateRow(unaff_ESI);
        goto LAB_00444f55;
      }
    }
    StreamSections__FreeUnreadBuffers(unaff_ESI);
    uVar1 = StreamSections__AllocateRow(unaff_ESI);
  } while( true );
}


// ==== 0x444fb0 StreamSections::UpdateViewerBoundaries

/* [canon] track high (hopper+ghidra+capstone) docs/re/track.md */

byte StreamSections__UpdateViewerBoundaries(int param_1,int param_2)

{
  short sVar1;
  byte bVar2;
  short sVar3;
  int *piVar4;
  int iVar5;
  
  bVar2 = 0;
  iVar5 = 0;
  piVar4 = (int *)(param_1 + 0xec);
  do {
    sVar3 = -1;
    if ((char)piVar4[-2] != '\0') {
      sVar3 = StreamSections__PredictBoundary(param_1,piVar4 + -6);
    }
    if (sVar3 == (short)piVar4[-1]) {
      *piVar4 = *piVar4 + 1;
    }
    else {
      *(short *)(piVar4 + -1) = sVar3;
      if (*piVar4 == -1) {
        *piVar4 = 1000;
      }
      else {
        *piVar4 = 1;
      }
    }
    sVar1 = *(short *)((int)piVar4 + -6);
    if (sVar3 != sVar1) {
      if (*piVar4 < 3) {
        sVar3 = sVar1;
      }
      if (sVar3 != sVar1) {
        bVar2 = 1;
      }
    }
    *(short *)(param_2 + iVar5 * 2) = sVar3;
    iVar5 = iVar5 + 1;
    piVar4 = piVar4 + 0x11;
  } while (iVar5 < 2);
  return *(byte *)(param_1 + 0x179) | bVar2;
}


// ==== 0x445050 StreamSections::Update

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] track high (hopper+ghidra) docs/re/track.md */

void StreamSections__Update(void)

{
  char cVar1;
  int in_EAX;
  LARGE_INTEGER local_10;
  char local_5;
  
  QueryPerformanceCounter(&local_10);
  local_5 = *(char *)(in_EAX + 0x15c) == '\0';
  cVar1 = StreamSections__Round();
  if ((cVar1 != '\0') && (*(code **)(in_EAX + 0x588) != (code *)0x0)) {
    (**(code **)(in_EAX + 0x588))(*(undefined4 *)(in_EAX + 0x58c));
    *(undefined4 *)(in_EAX + 0x588) = 0;
    *(undefined4 *)(in_EAX + 0x58c) = 0;
  }
  if ((local_5 == '\0') && (cVar1 != '\0')) {
    FUN_005715d0(0xbe43edbb);
    FUN_005715d0(0x72923c81);
    DAT_007360d0 = 0;
    DAT_007360d4 = 0;
    _DAT_007360d8 = 0;
    _DAT_007360dc = 0;
  }
  return;
}


// ==== 0x445100 StreamSections::WaitUntilIdle

/* [canon] track high (hopper+ghidra) docs/re/track.md */

undefined4 StreamSections__WaitUntilIdle(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined3 uVar3;
  uint uVar4;
  
  uVar4 = (uint)*(byte *)(param_1 + 0x15c);
  if (DAT_0073459c != 0) {
    uVar4 = FUN_0057c5a0(9);
  }
  uVar2 = 0;
  if (DAT_007345a0 != 0) {
    uVar2 = FUN_0057c3b0(uVar4,1,9);
  }
  bVar1 = *(byte *)(param_1 + 0x15c);
  uVar3 = (undefined3)((uint)uVar2 >> 8);
  if ((bVar1 & uVar4 == 0) != 0) {
    while (bVar1 != 0) {
      ServiceResourceLoading();
      uVar2 = StreamSections__Update();
      uVar3 = (undefined3)((uint)uVar2 >> 8);
      bVar1 = *(byte *)(param_1 + 0x15c);
    }
  }
  return CONCAT31(uVar3,uVar4 != 0);
}


// ==== 0x445180 StreamSections::Round

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] track high (hopper+ghidra+capstone) docs/re/track.md */

undefined4 StreamSections__Round(void)

{
  undefined4 *puVar1;
  short sVar2;
  int iVar3;
  bool bVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int unaff_EDI;
  float10 fVar12;
  short local_4 [2];
  
  if ((*(int *)(unaff_EDI + 0x580) == 0) ||
     ((cVar5 = StreamSections__UpdateViewerBoundaries(unaff_EDI,local_4),
      *(char *)(unaff_EDI + 0x15d) != '\0' && (cVar5 == '\0')))) {
    return 1;
  }
  if (2 < *(int *)(unaff_EDI + 0x10)) {
    return 0;
  }
  if (cVar5 != '\0') {
    if (0 < *(int *)(unaff_EDI + 0x10)) {
      return 0;
    }
    *(undefined1 *)(unaff_EDI + 0x179) = 0;
    StreamSections__FreeUnreadBuffers(unaff_EDI);
    StreamSections__ResetRound();
    *(undefined1 *)(unaff_EDI + 0x15c) = 1;
    *(undefined1 *)(unaff_EDI + 0x160) = 0;
    _DAT_006f3dac = 0;
    fVar12 = (float10)FUN_00585fa0();
    *(float *)(unaff_EDI + 0x16c) = (float)fVar12;
    *(undefined4 *)(unaff_EDI + 0x174) = DAT_006f0888;
    iVar9 = 0;
    do {
      sVar2 = local_4[iVar9];
      puVar1 = (undefined4 *)(iVar9 * 0x44 + 0xd4 + unaff_EDI);
      if (*(short *)((int)puVar1 + 0x12) != sVar2) {
        *(short *)((int)puVar1 + 0x12) = sVar2;
        puVar1[8] = puVar1[1];
        puVar1[7] = *puVar1;
      }
      if (iVar9 == 0) {
        FUN_00445730();
      }
      else if (0 < sVar2) {
        uVar6 = FUN_00445770();
        FUN_00565da0("%s - %s",unaff_EDI + 0x161,uVar6);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < 2);
    StreamSections__BuildWantedSet(unaff_EDI);
  }
  if (*(char *)(unaff_EDI + 0x15e) == '\0') {
    cVar5 = StreamSections__AllocateRequested();
    if (cVar5 == '\0') {
      return 0;
    }
    *(undefined1 *)(unaff_EDI + 0x15e) = 1;
  }
  iVar9 = *(int *)(unaff_EDI + 0x10);
  bVar4 = true;
  do {
    if ((2 < iVar9) || (!bVar4)) {
      if (*(int *)(unaff_EDI + 0x10) < 1) {
        if (*(char *)(unaff_EDI + 0x15f) == '\0') {
          *(undefined1 *)(unaff_EDI + 0x15d) = 1;
          *(undefined1 *)(unaff_EDI + 0x15c) = 0;
          _DAT_006f3dac = 1;
          *(undefined1 *)(unaff_EDI + 0x178) = 1;
          return 1;
        }
        *(undefined1 *)(unaff_EDI + 0x15e) = 0;
      }
      return 0;
    }
    iVar9 = *(int *)(unaff_EDI + 0x17c);
    iVar8 = -1;
    iVar11 = 0;
    if (iVar9 < 1) {
LAB_004452ed:
      bVar4 = false;
    }
    else {
      piVar10 = (int *)(unaff_EDI + 0x180);
      do {
        iVar3 = *piVar10;
        if (*(int *)(iVar3 + 0xc) == 1) {
          iVar7 = (int)*(short *)(iVar3 + 8);
          if (1000000 < *(int *)(iVar3 + 0x18)) {
            iVar7 = 0x7fffffff;
          }
          if (iVar8 < iVar7) {
            iVar8 = iVar7;
            iVar11 = iVar3;
          }
        }
        piVar10 = piVar10 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      if (iVar11 == 0) goto LAB_004452ed;
      StreamSections__IssueRead();
    }
    iVar9 = *(int *)(unaff_EDI + 0x10);
  } while( true );
}


// ==== 0x445350 StreamSections::Shutdown

/* [canon] assets high (Ghidra make FUN_00445350) docs/re/assets.md */

void StreamSections__Shutdown(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *_Memory;
  int iVar4;
  int *unaff_EBX;
  int iVar5;
  int local_8;
  int local_4;
  
  iVar5 = unaff_EBX[4];
  while (iVar5 != 0) {
    ServiceResourceLoading();
    iVar5 = unaff_EBX[4];
  }
  local_4 = 0;
  if (0 < unaff_EBX[1]) {
    local_8 = 0;
    do {
      iVar5 = *unaff_EBX + local_8;
      if (*(int *)(*unaff_EBX + 0xc + local_8) == 3) {
        piVar1 = *(int **)(iVar5 + 0x28);
        iVar2 = piVar1[0x24];
        while (iVar2 == 0) {
          ServiceResourceLoading();
          iVar2 = piVar1[0x24];
        }
        iVar2 = *piVar1;
        piVar3 = (int *)piVar1[1];
        *piVar3 = iVar2;
        *(int **)(iVar2 + 4) = piVar3;
        ResourceFile__UnloadChunks();
        iVar4 = DAT_007360f8;
        iVar2 = *(int *)(DAT_007360f8 + 0x18);
        *piVar1 = *(int *)(DAT_007360f8 + 0x10);
        *(int **)(iVar4 + 0x10) = piVar1;
        *(int *)(iVar4 + 0x18) = iVar2 + -1;
        *(undefined4 *)(iVar5 + 0x28) = 0;
        *(undefined4 *)(iVar5 + 0xc) = 0;
        *(undefined4 *)(iVar5 + 0x2c) = 0;
        unaff_EBX[3] = unaff_EBX[3] + -1;
      }
      local_4 = local_4 + 1;
      local_8 = local_8 + 0x38;
    } while (local_4 < unaff_EBX[1]);
  }
  piVar3 = (int *)unaff_EBX[0x164];
  piVar1 = unaff_EBX + 0x164;
  do {
    if (piVar3 == piVar1) {
      StreamSections__ResetRound();
      return;
    }
    _Memory = (int *)*piVar1;
    piVar3 = _Memory + 2;
    for (; _Memory != piVar1; _Memory = (int *)*_Memory) {
      if ((short)*piVar3 == (short)_Memory[2]) {
        iVar5 = *_Memory;
        piVar3 = (int *)_Memory[1];
        *piVar3 = iVar5;
        *(int **)(iVar5 + 4) = piVar3;
        _free(_Memory);
        break;
      }
    }
    piVar3 = (int *)*piVar1;
  } while( true );
}


// ==== 0x445450 FUN_00445450

void FUN_00445450(short param_1)

{
  int iVar1;
  int iVar2;
  int *unaff_EDI;
  
  iVar1 = unaff_EDI[4];
  while (iVar1 != 0) {
    ServiceResourceLoading();
    iVar1 = unaff_EDI[4];
  }
  iVar1 = 0;
  if (0 < unaff_EDI[1]) {
    iVar2 = *unaff_EDI;
    while (*(short *)(iVar2 + 8) != param_1) {
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x38;
      if (unaff_EDI[1] <= iVar1) {
        StreamSections__ResetRound();
        return;
      }
    }
    UnloadResourceFile();
    *(undefined4 *)(iVar2 + 0x28) = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(undefined4 *)(iVar2 + 0x2c) = 0;
    unaff_EDI[3] = unaff_EDI[3] + -1;
  }
  StreamSections__ResetRound();
  return;
}


// ==== 0x4454d0 FUN_004454d0

void FUN_004454d0(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 *unaff_EDI;
  
  unaff_EDI[3] = 0;
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


// ==== 0x445520 Placement::UnpackAabb

/* [canon] track high (hopper+ghidra) docs/re/track.md */

void __fastcall Placement__UnpackAabb(float *param_1,float *param_2)

{
  short sVar1;
  short sVar2;
  short *in_EAX;
  
  sVar1 = in_EAX[2];
  sVar2 = in_EAX[1];
  *param_2 = (float)(int)*in_EAX;
  param_2[1] = (float)(int)sVar2;
  param_2[2] = (float)(int)sVar1;
  sVar1 = in_EAX[5];
  sVar2 = in_EAX[4];
  *param_1 = (float)(int)in_EAX[3];
  param_1[1] = (float)(int)sVar2;
  param_1[2] = (float)(int)sVar1;
  return;
}


// ==== 0x445580 Placement::UnpackMatrix

/* [canon] track high (hopper+ghidra) docs/re/track.md */

void __fastcall Placement__UnpackMatrix(int param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  float *in_EAX;
  
  sVar1 = *(short *)(param_1 + 0x1e);
  sVar2 = *(short *)(param_1 + 0x20);
  sVar3 = *(short *)(param_1 + 0x1c);
  in_EAX[3] = 0.0;
  *in_EAX = (float)(int)sVar3 * 0.00012207031;
  in_EAX[1] = (float)(int)sVar1 * 0.00012207031;
  in_EAX[2] = (float)(int)sVar2 * 0.00012207031;
  sVar1 = *(short *)(param_1 + 0x24);
  sVar2 = *(short *)(param_1 + 0x26);
  sVar3 = *(short *)(param_1 + 0x22);
  in_EAX[7] = 0.0;
  in_EAX[4] = (float)(int)sVar3 * 0.00012207031;
  in_EAX[5] = (float)(int)sVar1 * 0.00012207031;
  in_EAX[6] = (float)(int)sVar2 * 0.00012207031;
  sVar1 = *(short *)(param_1 + 0x2a);
  sVar2 = *(short *)(param_1 + 0x2c);
  sVar3 = *(short *)(param_1 + 0x28);
  in_EAX[0xb] = 0.0;
  in_EAX[8] = (float)(int)sVar3 * 0.00012207031;
  in_EAX[9] = (float)(int)sVar1 * 0.00012207031;
  in_EAX[10] = (float)(int)sVar2 * 0.00012207031;
  return;
}


// ==== 0x445660 FUN_00445660

void FUN_00445660(void)

{
  undefined2 uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = _ftol_nocw();
  *(undefined2 *)(unaff_EDI + 0x1c) = uVar1;
  uVar1 = _ftol_nocw();
  *(undefined2 *)(unaff_EDI + 0x1e) = uVar1;
  uVar1 = _ftol_nocw();
  *(undefined2 *)(unaff_EDI + 0x20) = uVar1;
  uVar1 = _ftol_nocw();
  *(undefined2 *)(unaff_EDI + 0x22) = uVar1;
  uVar1 = _ftol_nocw();
  *(undefined2 *)(unaff_EDI + 0x24) = uVar1;
  uVar1 = _ftol_nocw();
  *(undefined2 *)(unaff_EDI + 0x26) = uVar1;
  uVar1 = _ftol_nocw();
  *(undefined2 *)(unaff_EDI + 0x28) = uVar1;
  uVar1 = _ftol_nocw();
  *(undefined2 *)(unaff_EDI + 0x2a) = uVar1;
  uVar1 = _ftol_nocw();
  *(undefined2 *)(unaff_EDI + 0x2c) = uVar1;
  *(undefined4 *)(unaff_EDI + 0x10) = *(undefined4 *)(unaff_ESI + 0x30);
  *(undefined4 *)(unaff_EDI + 0x14) = *(undefined4 *)(unaff_ESI + 0x34);
  *(undefined4 *)(unaff_EDI + 0x18) = *(undefined4 *)(unaff_ESI + 0x38);
  return;
}


// ==== 0x445720 bList::bList

/* [canon] runtime med (ghidra-canon) docs/re/runtime.md */

void bList__bList(void)

{
  FUN_00589260();
  return;
}


// ==== 0x445730 FUN_00445730

undefined1 * __fastcall FUN_00445730(undefined1 *param_1)

{
  int in_EAX;
  
  if (in_EAX < 1) {
    *param_1 = 0x2d;
    param_1[1] = 0x2d;
    param_1[2] = 0;
    return param_1;
  }
  FUN_00565da0(&DAT_006ca178,(int)(char)((char)(in_EAX / 100) + '@'),in_EAX % 100);
  return param_1;
}


// ==== 0x445770 FUN_00445770

undefined * FUN_00445770(void)

{
  int in_EAX;
  int iVar1;
  undefined *puVar2;
  
  iVar1 = (DAT_0078eb54 & 3) * 0x10;
  puVar2 = &DAT_0078ef40 + iVar1;
  DAT_0078eb54 = DAT_0078eb54 + 1;
  if (in_EAX < 1) {
    *puVar2 = 0x2d;
    (&DAT_0078ef41)[iVar1] = 0x2d;
    (&DAT_0078ef42)[iVar1] = 0;
    return puVar2;
  }
  FUN_00565da0(&DAT_006ca178,(int)(char)((char)(in_EAX / 100) + '@'),in_EAX % 100);
  return puVar2;
}


// ==== 0x4457c0 StreamSection_Load

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 StreamSection_Load(int *param_1)

{
  undefined4 *puVar1;
  ushort *puVar2;
  byte bVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined4 *puVar10;
  int *piVar11;
  int *piStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  if (*param_1 != -0x7ffcbf00) {
    return 0;
  }
  piVar9 = (int *)(param_1[1] + 8 + (int)param_1);
  puVar10 = (undefined4 *)0x0;
  piVar11 = param_1 + 2;
  param_1 = (undefined4 *)0x0;
  for (; piVar11 != piVar9; piVar11 = (int *)((int)piVar11 + piVar11[1] + 8)) {
    iVar8 = *piVar11;
    if (iVar8 == 0x34101) {
      puVar10 = (undefined4 *)((int)piVar11 + 0x17U & 0xfffffff0);
      *(undefined4 **)(&DAT_0072a008 + puVar10[3] * 4) = puVar10;
      puVar5 = DAT_0077a978;
      iVar8 = puVar10[3];
      param_1 = puVar10;
      if ((char)(((char)(iVar8 / 100) + (char)(iVar8 >> 0x1f)) -
                (char)((longlong)iVar8 * 0x51eb851f >> 0x3f)) == '\x1a') {
        puVar1 = DAT_0077a978 + 1;
        DAT_0077a978 = puVar10;
        *puVar1 = puVar10;
        puVar10[1] = &DAT_0077a978;
        *puVar10 = puVar5;
      }
      else {
        *DAT_0077a97c = puVar10;
        puVar5 = puVar10;
        puVar10[1] = DAT_0077a97c;
        DAT_0077a97c = puVar5;
        *puVar10 = &DAT_0077a978;
      }
    }
    else if (iVar8 == 0x34102) {
      puVar10[6] = piVar11 + 2;
      puVar10[7] = (uint)piVar11[1] / 0x48;
    }
    else if (iVar8 == 0x34103) {
      puVar10[8] = (int)piVar11 + 0x17U & 0xfffffff0;
      puVar10[9] = ((piVar11[1] - ((int)piVar11 + 0x17U & 0xfffffff0)) + 8 + (int)piVar11) / 0x30;
    }
    else if (iVar8 == 0x34104) {
      puVar10[10] = piVar11 + 2;
      puVar10[0xb] = (uint)piVar11[1] / 0x18;
    }
  }
  iStack_4 = 0;
  if (0 < (int)puVar10[7]) {
    iStack_c = 0;
    do {
      iVar8 = puVar10[6] + iStack_c;
      piStack_10 = (int *)0x0;
      iStack_8 = 0;
      do {
        iVar4 = DAT_0073557c;
        iVar7 = *(int *)(iVar8 + iStack_8 * 4);
        if (((iVar7 != 0) && (iVar7 != -0x41bc1245)) && (iVar7 != 0x72923c81)) {
          iVar6 = 0;
          if (0 < iStack_8) {
            piVar9 = (int *)(iVar8 + 0x24);
            do {
              if ((*piVar9 != 0) && (*(int *)(*piVar9 + 8) == iVar7)) {
                piVar9 = *(int **)(iVar8 + 0x24 + iVar6 * 4);
                if (piVar9 != (int *)0x0) goto LAB_00445a66;
                break;
              }
              iVar6 = iVar6 + 1;
              piVar9 = piVar9 + 1;
            } while (iVar6 < iStack_8);
          }
          piVar11 = (int *)(DAT_0073557c + 0x10);
          if ((*(int *)(DAT_0073557c + 0x10) == 0) && ((*(byte *)(DAT_0073557c + 0x14) & 1) != 0)) {
            FUN_00566e60();
          }
          piVar9 = (int *)*piVar11;
          iVar7 = *(int *)(iVar4 + 0x18) + 1;
          if (piVar9 == (int *)0x0) {
            piVar9 = (int *)0x0;
          }
          else {
            iVar6 = *piVar9;
            if (*(int *)(iVar4 + 0x1c) < iVar7) {
              *(int *)(iVar4 + 0x1c) = iVar7;
            }
            *(int *)(iVar4 + 0x18) = iVar7;
            bVar3 = *(byte *)(iVar4 + 0x14);
            *piVar11 = iVar6;
            if (((bVar3 & 2) != 0) &&
               (iVar7 = *(int *)(iVar4 + 0x28) >> 2, piVar11 = piVar9, 0 < iVar7)) {
              for (; iVar7 != 0; iVar7 = iVar7 + -1) {
                *piVar11 = 0;
                piVar11 = piVar11 + 1;
              }
            }
            iVar7 = *(int *)(iVar8 + iStack_8 * 4);
            piVar9[3] = 0;
            piVar9[2] = iVar7;
            piVar9[4] = 0;
            piVar9[5] = 0;
            if (iVar7 != 0) {
              *DAT_00743c74 = (int)piVar9;
              piVar11 = piVar9;
              piVar9[1] = (int)DAT_00743c74;
              DAT_00743c74 = piVar11;
              *piVar9 = (int)&DAT_00743c70;
            }
            if (((piVar9[2] != 0) && (iVar7 = Solid_FindInAllLists(), piVar9[2] != 0)) &&
               (iVar7 != piVar9[3])) {
              iVar4 = *piVar9;
              piVar11 = (int *)piVar9[1];
              *piVar11 = iVar4;
              *(int **)(iVar4 + 4) = piVar11;
              if (iVar7 == 0) {
                *DAT_00743c74 = (int)piVar9;
                piVar11 = piVar9;
                piVar9[1] = (int)DAT_00743c74;
                DAT_00743c74 = piVar11;
                *piVar9 = (int)&DAT_00743c70;
                piVar9[3] = 0;
              }
              else {
                puVar10 = *(undefined4 **)(iVar7 + 0x8c);
                *puVar10 = piVar9;
                *(int **)(iVar7 + 0x8c) = piVar9;
                piVar9[1] = (int)puVar10;
                piVar9[3] = iVar7;
                *piVar9 = iVar7 + 0x88;
              }
            }
          }
LAB_00445a66:
          *(int **)(iVar8 + 0x24 + iStack_8 * 4) = piVar9;
          if (iStack_8 < 4) {
            piStack_10 = piVar9;
          }
        }
        iStack_8 = iStack_8 + 1;
      } while (iStack_8 < 6);
      if (*(int *)(iVar8 + 0x38) == 0) {
        *(int **)(iVar8 + 0x38) = piStack_10;
      }
      if (*(int *)(iVar8 + 0x34) == 0) {
        *(int **)(iVar8 + 0x34) = piStack_10;
      }
      iStack_c = iStack_c + 0x48;
      iStack_4 = iStack_4 + 1;
      puVar10 = param_1;
    } while (iStack_4 < param_1[7]);
  }
  if ((DAT_0078a2fc == 1) && (puVar10[2] == 0)) {
    FUN_004462a0(puVar10);
  }
  if (0 < DAT_00734474) {
    piVar9 = (int *)(DAT_00734470 + 0xc);
    iVar8 = DAT_00734474;
    do {
      if ((int)(short)piVar9[-2] == param_1[3]) {
        if (*piVar9 == 0) {
          puVar2 = (ushort *)(*(short *)((int)piVar9 + -6) * 0x30 + param_1[8] + 0xe);
          *puVar2 = *puVar2 | 0x10;
        }
        else {
          puVar2 = (ushort *)(*(short *)(*(int *)(*piVar9 + 0x60) + 6) * 0x30 + param_1[8] + 0xe);
          *puVar2 = *puVar2 & 0xffef;
        }
      }
      piVar9 = piVar9 + 0x1c;
      iVar8 = iVar8 + -1;
      puVar10 = param_1;
    } while (iVar8 != 0);
  }
  puVar10[2] = 1;
  return 1;
}


// ==== 0x445b00 Section::SyncSmackableVisibility

/* [canon] props med (capstone) docs/re/props.md */

void __fastcall Section__SyncSmackableVisibility(int *param_1,int param_2)

{
  ushort *puVar1;
  ushort unaff_BX;
  undefined4 unaff_EBP;
  ushort unaff_DI;
  int in_stack_00000028;
  
  do {
    if ((int)(short)param_1[-2] == *(int *)(in_stack_00000028 + 0xc)) {
      if (*param_1 == 0) {
        puVar1 = (ushort *)
                 (*(short *)((int)param_1 + -6) * 0x30 + *(int *)(in_stack_00000028 + 0x20) + 0xe);
        *puVar1 = *puVar1 | unaff_DI;
      }
      else {
        puVar1 = (ushort *)
                 (*(short *)(*(int *)(*param_1 + 0x60) + 6) * 0x30 +
                  *(int *)(in_stack_00000028 + 0x20) + 0xe);
        *puVar1 = *puVar1 & unaff_BX;
      }
    }
    param_1 = param_1 + 0x1c;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  *(undefined4 *)(in_stack_00000028 + 8) = unaff_EBP;
  return;
}


// ==== 0x445b60 StreamSection_Unload

/* [canon] assets high (Hopper export has no block (inside another sub_); Ghidra export has no
   block; live Ghidra decompile + capstone) docs/re/assets.md */

undefined4 StreamSection_Unload(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iStack_8;
  int iStack_4;
  
  if (*param_1 != -0x7ffcbf00) {
    return 0;
  }
  piVar6 = (int *)((int)param_1 + 0x1fU & 0xfffffff0);
  *(undefined4 *)(&DAT_0072a008 + piVar6[3] * 4) = 0;
  iVar5 = *piVar6;
  piVar7 = (int *)piVar6[1];
  *piVar7 = iVar5;
  *(int **)(iVar5 + 4) = piVar7;
  iStack_4 = 0;
  if (0 < piVar6[7]) {
    param_1 = (int *)0x0;
    do {
      piVar7 = (int *)(piVar6[6] + (int)param_1 + 0x24);
      iStack_8 = 6;
      iVar5 = 1;
      do {
        if (*piVar7 != 0) {
          if (iVar5 < 6) {
            iVar4 = 6 - iVar5;
            piVar3 = piVar7;
            do {
              piVar3 = piVar3 + 1;
              if (*piVar3 == *piVar7) {
                *piVar3 = 0;
              }
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          puVar1 = (undefined4 *)*piVar7;
          if (puVar1 != (undefined4 *)0x0) {
            ListRef_Release();
            iVar2 = DAT_0073557c;
            iVar4 = *(int *)(DAT_0073557c + 0x18);
            *puVar1 = *(undefined4 *)(DAT_0073557c + 0x10);
            *(int *)(iVar2 + 0x18) = iVar4 + -1;
            *(undefined4 **)(iVar2 + 0x10) = puVar1;
          }
          *piVar7 = 0;
        }
        piVar7 = piVar7 + 1;
        iVar5 = iVar5 + 1;
        iStack_8 = iStack_8 + -1;
      } while (iStack_8 != 0);
      iStack_4 = iStack_4 + 1;
      param_1 = (int *)((int)param_1 + 0x48);
    } while (iStack_4 < piVar6[7]);
  }
  return 1;
}


// ==== 0x445c60 FUN_00445c60

int * FUN_00445c60(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int unaff_EDI;
  
  puVar1 = DAT_0077a978;
  puVar2 = (undefined4 *)NullUpdate_ret();
  do {
    if (puVar1 == puVar2) {
      return (int *)0x0;
    }
    iVar4 = 0;
    if (0 < (int)puVar1[7]) {
      piVar3 = (int *)puVar1[6];
      do {
        if (*piVar3 == unaff_EDI) {
          return piVar3;
        }
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 0x12;
      } while (iVar4 < (int)puVar1[7]);
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}


// ==== 0x445ca0 Sections::FindSectionBySolid

/* [canon] track med (hopper+ghidra) docs/re/track.md */

int Sections__FindSectionBySolid(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = DAT_0077a978;
  puVar2 = (undefined4 *)NullUpdate_ret();
  do {
    if (puVar1 == puVar2) {
      return 0;
    }
    iVar4 = 0;
    if (0 < (int)puVar1[9]) {
      iVar3 = puVar1[8];
      do {
        if (*(int *)(puVar1[6] + *(short *)(iVar3 + 0xc) * 0x48) == param_1) {
          return iVar3;
        }
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 0x30;
      } while (iVar4 < (int)puVar1[9]);
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}


// ==== 0x445d00 StreamBoundaries::DebugDump

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] track med (hopper+ghidra) docs/re/track.md */

void StreamBoundaries__DebugDump(void)

{
  char *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  char local_40;
  char local_3f [63];
  
  if (DAT_0073613c == 0) {
    iVar3 = FUN_00567160();
    if (iVar3 == 0) {
      DAT_0073613c = 0;
    }
    else {
      pcVar5 = "MARKER_BOUNDARY";
      do {
        pcVar1 = pcVar5 + 1;
        pcVar5 = pcVar5 + 1;
      } while (*pcVar1 != '\0');
      DAT_0073613c = FUN_004454d0();
    }
  }
  if (DAT_0073612c == 0) {
    pcVar5 = "Seeulator";
    do {
      pcVar1 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar1 != '\0');
    pcVar5 = "Seeulator";
    do {
      pcVar1 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar1 != '\0');
    DAT_0073612c = 0;
    _DAT_00736134 = 0;
    return;
  }
  FUN_00565da0("%s\\Gonkulator.hoo",DAT_00736174 + 0x20);
  puVar2 = DAT_0077a940;
  if (local_40 != '\0') {
    pcVar5 = &local_40;
    do {
      pcVar1 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar1 != '\0');
  }
  puVar4 = (undefined4 *)NullUpdate_ret();
  for (; puVar2 != puVar4; puVar2 = (undefined4 *)*puVar2) {
    FUN_00446bb0(1);
    FUN_00446c90();
    FUN_00446b70();
  }
  return;
}


// ==== 0x445e10 FUN_00445e10

undefined4 __thiscall FUN_00445e10(int param_1,float param_2)

{
  float *in_EAX;
  undefined4 uVar1;
  
  if ((*in_EAX - *(float *)(param_1 + 0xa0)) * *(float *)(param_1 + 0xb0) +
      (in_EAX[1] - *(float *)(param_1 + 0xa4)) * *(float *)(param_1 + 0xb4) +
      (in_EAX[2] - *(float *)(param_1 + 0xa8)) * *(float *)(param_1 + 0xb8) < -param_2) {
    return 0;
  }
  uVar1 = _ftol_nocw();
  return uVar1;
}


// ==== 0x445ec0 Section::DrawPlacement

/* [canon] track med (hopper+ghidra) docs/re/track.md */

void __thiscall Section__DrawPlacement(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  short *psVar7;
  int iVar8;
  int local_3c;
  int local_38;
  
  iVar8 = in_EAX * 0x30 + *(int *)(param_1 + 0x20);
  if ((*(byte *)(param_2 + 0x84) & ((byte)*(undefined2 *)(iVar8 + 0xe) ^ 0x60)) == 0) {
    iVar5 = *(int *)(param_1 + 0x18) + *(short *)(iVar8 + 0xc) * 0x48;
    if (param_3 == 1) {
      Placement__UnpackAabb();
      param_3 = AABB_ClassifyAgainstFrustum(*(undefined4 *)(param_2 + 0x80));
      if (param_3 == 0) {
        return;
      }
    }
    iVar3 = FUN_00445e10(*(float *)(iVar5 + 0x44) + 4.0);
    if (1 < iVar3) {
      local_38 = -1;
      local_3c = 0;
      if ((*(uint *)(param_2 + 0x84) & 0x800) == 0) {
        if ((*(uint *)(param_2 + 0x84) & 0x1000) == 0) {
          piVar6 = (int *)(iVar5 + 0x24);
          psVar7 = (short *)(iVar5 + 0x18);
          iVar4 = 0;
          do {
            if ((*psVar7 <= iVar3) && (*piVar6 != 0)) {
              local_3c = *(int *)(iVar5 + 0x24 + iVar4 * 4);
              local_38 = iVar4;
              break;
            }
            iVar4 = iVar4 + 1;
            psVar7 = psVar7 + 1;
            piVar6 = piVar6 + 1;
          } while (iVar4 < 4);
        }
        else if ((*(short *)(iVar5 + 0x22) <= iVar3) && (*(int *)(iVar5 + 0x38) != 0)) {
          local_38 = 5;
          local_3c = *(int *)(iVar5 + 0x38);
        }
      }
      else if ((*(short *)(iVar5 + 0x20) <= iVar3) && (*(int *)(iVar5 + 0x34) != 0)) {
        local_38 = 4;
        local_3c = *(int *)(iVar5 + 0x34);
      }
      iVar3 = local_3c;
      if (DAT_00736128 == 2) {
        if (local_38 == 0) {
          iVar4 = 1;
          piVar6 = (int *)(iVar5 + 0x28);
          do {
            if (*piVar6 != 0) {
              iVar3 = *(int *)(iVar5 + 0x24 + iVar4 * 4);
              break;
            }
            iVar4 = iVar4 + 1;
            piVar6 = piVar6 + 1;
          } while (iVar4 < 4);
        }
      }
      else if ((DAT_00736128 == 1) && (iVar3 = *(int *)(iVar5 + 0x38), *(int *)(iVar5 + 0x38) == 0))
      {
        iVar4 = 3;
        piVar6 = (int *)(iVar5 + 0x30);
        do {
          if (*piVar6 != 0) {
            iVar3 = *(int *)(iVar5 + 0x24 + iVar4 * 4);
            break;
          }
          iVar4 = iVar4 + -1;
          piVar6 = piVar6 + -1;
          iVar3 = local_3c;
        } while (-1 < iVar4);
      }
      local_3c = iVar3;
      if (local_3c != 0) {
        if ((*(ushort *)(iVar8 + 0xe) & 0x200) == 0) {
          iVar5 = ScratchAlloc64xN();
          if (iVar5 != 0) {
            Placement__UnpackMatrix();
            uVar1 = *(undefined4 *)(iVar8 + 0x18);
            uVar2 = *(undefined4 *)(iVar8 + 0x10);
            *(undefined4 *)(iVar5 + 0x34) = *(undefined4 *)(iVar8 + 0x14);
            *(undefined4 *)(iVar5 + 0x30) = uVar2;
            *(undefined4 *)(iVar5 + 0x3c) = 0x3f800000;
            *(undefined4 *)(iVar5 + 0x38) = uVar1;
            if (((uint)*(ushort *)(iVar8 + 0xe) & *(uint *)(param_2 + 0x84) & 0x100) != 0) {
              *(float *)(iVar5 + 0x38) = *(float *)(iVar5 + 0x38) + 2.0;
            }
            if ((*(uint *)(param_2 + 0x84) & 0x800) != 0) {
              *(float *)(iVar5 + 0x28) = -*(float *)(iVar5 + 0x28);
            }
            piVar6 = *(int **)(param_2 + 0x8c);
            if (piVar6 < *(int **)(param_2 + 0x90)) {
              *(int **)(param_2 + 0x8c) = piVar6 + 3;
              piVar6[1] = iVar5;
              *piVar6 = local_3c + param_3;
              piVar6[2] = iVar8;
            }
          }
        }
        else {
          piVar6 = *(int **)(param_2 + 0x8c);
          if (piVar6 < *(int **)(param_2 + 0x90)) {
            *(int **)(param_2 + 0x8c) = piVar6 + 3;
            piVar6[1] = 0;
            *piVar6 = local_3c + param_3;
            piVar6[2] = iVar8;
            return;
          }
        }
      }
    }
  }
  return;
}


// ==== 0x446140 Section::WalkBvh

/* [canon] track med (hopper+ghidra) docs/re/track.md */

void Section__WalkBvh(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int local_17c;
  short *local_178;
  char *local_174;
  char local_14f [63];
  int local_110 [67];
  
  local_110[0] = *(int *)(param_1 + 0x28);
  piVar3 = local_110 + 1;
  local_174 = local_14f;
  do {
    cVar2 = local_174[-1];
    iVar1 = piVar3[-1];
    piVar3 = piVar3 + -1;
    local_174 = local_174 + -1;
    if (cVar2 == '\x01') {
      cVar2 = AABB_ClassifyAgainstFrustum(*(undefined4 *)(param_2 + 0x80));
    }
    if ((cVar2 != '\0') && (local_17c = 0, 0 < *(short *)(iVar1 + 0xc))) {
      local_178 = (short *)(iVar1 + 0xe);
      do {
        if (*local_178 < 0) {
          *piVar3 = *(int *)(param_1 + 0x28) + *local_178 * -0x18;
          piVar3 = piVar3 + 1;
          *local_174 = cVar2;
          local_174 = local_174 + 1;
        }
        else {
          Section__DrawPlacement(param_2,cVar2);
        }
        local_178 = local_178 + 1;
        local_17c = local_17c + 1;
      } while (local_17c < *(short *)(iVar1 + 0xc));
    }
  } while (piVar3 != local_110);
  return;
}


// ==== 0x4462a0 FUN_004462a0

void FUN_004462a0(int param_1)

{
  int iVar1;
  int iVar2;
  int local_94;
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
  undefined1 local_50 [48];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = 0;
  local_94 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    do {
      iVar2 = *(int *)(param_1 + 0x20) + iVar1;
      if ((*(ushort *)(iVar2 + 0xe) & 0x400) != 0) {
        Placement__UnpackMatrix();
        local_20 = 0;
        local_1c = 0;
        local_18 = 0;
        local_14 = 0x3f800000;
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
        local_90 = 0xbf800000;
        D3DXMatrixMultiply(local_50,&local_90,local_50);
        local_1c = *(undefined4 *)(iVar2 + 0x14);
        local_20 = *(undefined4 *)(iVar2 + 0x10);
        local_18 = *(undefined4 *)(iVar2 + 0x18);
        local_14 = 0x3f800000;
        FUN_00445660();
      }
      local_94 = local_94 + 1;
      iVar1 = iVar1 + 0x30;
    } while (local_94 < *(int *)(param_1 + 0x24));
  }
  return;
}


// ==== 0x446400 StreamBoundaries::BuildDrawList

/* [canon] track high (hopper+ghidra+capstone) docs/re/track.md */

int StreamBoundaries__BuildDrawList(undefined4 param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  
  iVar3 = StreamBoundaries__FindContaining(*(int *)(*(int *)(param_4 + 0x80) + 0x40) + 0x40);
  puVar2 = DAT_0077a978;
  iVar7 = 0;
  if (iVar3 == 0) {
    puVar4 = (undefined4 *)NullUpdate_ret();
    for (; puVar2 != puVar4; puVar2 = (undefined4 *)*puVar2) {
      if (((int)puVar2[3] % 100 < 10) && (iVar7 < param_3)) {
        *(short *)(param_2 + iVar7 * 2) = (short)puVar2[3];
        iVar7 = iVar7 + 1;
      }
    }
  }
  else {
    iVar5 = 0xa28;
    do {
      if ((*(int *)(&DAT_0072a008 + iVar5 * 4) != 0) && (iVar7 < param_3)) {
        *(short *)(param_2 + iVar7 * 2) = (short)iVar5;
        iVar7 = iVar7 + 1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0xa8c);
    iVar5 = 0;
    if (0 < *(int *)(iVar3 + 0x10)) {
      psVar6 = (short *)(iVar3 + 0x14);
      do {
        sVar1 = *psVar6;
        if (((-1 < sVar1) && (*(int *)(&DAT_0072a008 + sVar1 * 4) != 0)) && (iVar7 < param_3)) {
          *(short *)(param_2 + iVar7 * 2) = sVar1;
          iVar7 = iVar7 + 1;
        }
        iVar5 = iVar5 + 1;
        psVar6 = psVar6 + 1;
      } while (iVar5 < *(int *)(iVar3 + 0x10));
    }
  }
  if (*(int *)(*(int *)(param_4 + 0x80) + 4) == 1) {
    iVar5 = -1;
    if (iVar3 != 0) {
      iVar5 = (int)*(short *)(iVar3 + 8);
    }
    if (iVar5 != DAT_00700960) {
      DAT_00700960 = iVar5;
    }
    if (DAT_0073612c != 0) {
      if ((DAT_00736130 != 0) && ((DAT_006f0888 / 5 & 1U) != 0)) {
        iVar3 = 0;
        if (iVar7 < 1) {
LAB_0044655f:
          param_3 = iVar7 % param_3;
          iVar7 = iVar7 + 1;
          *(short *)(param_2 + param_3 * 2) = (short)DAT_00736130;
        }
        else {
          do {
            if (*(short *)(param_2 + iVar3 * 2) == DAT_00736130) {
              if (iVar3 < 0) goto LAB_0044655f;
              *(undefined2 *)(param_2 + iVar3 * 2) = 0xffff;
              goto LAB_00446571;
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < iVar7);
          param_3 = iVar7 % param_3;
          iVar7 = iVar7 + 1;
          *(short *)(param_2 + param_3 * 2) = (short)DAT_00736130;
        }
      }
LAB_00446571:
      if (DAT_00736138 != 0) {
        DAT_0077aa6c = 0xffffffff;
        DAT_0077aab0 = 0xffffffff;
        DAT_0077aaf9 = 1;
        DAT_00736138 = 0;
        return iVar7;
      }
    }
  }
  return iVar7;
}


// ==== 0x4465b0 StreamSections::DrawVisible

/* [canon] track high (hopper+ghidra) docs/re/track.md */

void __thiscall StreamSections__DrawVisible(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short local_100 [128];
  
  iVar2 = StreamBoundaries__BuildDrawList(param_1,local_100,0x80,param_2);
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      if (((-1 < local_100[iVar3]) &&
          (iVar1 = *(int *)(&DAT_0072a008 + local_100[iVar3] * 4), iVar1 != 0)) &&
         (*(int *)(iVar1 + 0x28) != 0)) {
        Section__WalkBvh(iVar1,param_2);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  return;
}


// ==== 0x446620 FUN_00446620

void FUN_00446620(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int unaff_ESI;
  
  if (DAT_0071db20 == '\0') {
    *(undefined **)(unaff_ESI + 0x824) = &DAT_0071db28;
    *(undefined **)(unaff_ESI + 0x828) = &DAT_0071db28;
    iVar5 = 0;
    *(undefined **)(unaff_ESI + 0x82c) = &DAT_0072a008;
    if (0 < *(int *)(unaff_ESI + 0x820)) {
      puVar4 = (undefined4 *)(unaff_ESI + 0xa8);
      do {
        iVar3 = *(int *)(puVar4[-10] + 0x40);
        uVar1 = *(undefined4 *)(iVar3 + 0x44);
        uVar2 = *(undefined4 *)(iVar3 + 0x48);
        puVar4[-2] = *(undefined4 *)(iVar3 + 0x40);
        puVar4[-1] = uVar1;
        *puVar4 = uVar2;
        iVar3 = *(int *)(puVar4[-10] + 0x40);
        uVar1 = *(undefined4 *)(iVar3 + 0x54);
        uVar2 = *(undefined4 *)(iVar3 + 0x58);
        puVar4[2] = *(undefined4 *)(iVar3 + 0x50);
        puVar4[3] = uVar1;
        iVar5 = iVar5 + 1;
        puVar4[4] = uVar2;
        puVar4[6] = *(undefined4 *)(puVar4[-10] + 0xc);
        puVar4 = puVar4 + 0x34;
      } while (iVar5 < *(int *)(unaff_ESI + 0x820));
    }
    iVar5 = 0;
    if (0 < *(int *)(unaff_ESI + 0x820)) {
      puVar4 = (undefined4 *)(unaff_ESI + 0x8c);
      do {
        puVar4[-1] = *(undefined4 *)(unaff_ESI + 0x828);
        *puVar4 = *(undefined4 *)(unaff_ESI + 0x828);
        puVar4[1] = *(undefined4 *)(unaff_ESI + 0x82c);
        StreamSections__DrawVisible(puVar4 + -0x23);
        *(undefined4 *)(unaff_ESI + 0x828) = *puVar4;
        iVar5 = iVar5 + 1;
        puVar4 = puVar4 + 0x34;
      } while (iVar5 < *(int *)(unaff_ESI + 0x820));
    }
  }
  return;
}


// ==== 0x446730 WorldSections_QueueForView

/* [canon] render low (hopper+ghidra) docs/re/render.md */

void __fastcall WorldSections_QueueForView(undefined4 param_1,int param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  bool bVar6;
  undefined *puVar7;
  uint uVar8;
  
  iVar4 = 0;
  iVar3 = *(int *)(param_3 + 0x40);
  piVar1 = (int *)(param_2 + 0x820);
  if (0 < *piVar1) {
    while (*(int *)(param_2 + 0x80) != param_3) {
      iVar4 = iVar4 + 1;
      param_2 = param_2 + 0xd0;
      if (*piVar1 <= iVar4) {
        return;
      }
    }
    puVar5 = *(uint **)(param_2 + 0x88);
    if (puVar5 < *(uint **)(param_2 + 0x8c)) {
      do {
        uVar8 = DAT_007355b4;
        DAT_00736140 = *puVar5 & 0xfffffffc;
        puVar7 = (undefined *)puVar5[1];
        if (puVar7 == (undefined *)0x0) {
          uVar8 = *(uint *)(param_3 + 0x54);
          puVar7 = &DAT_0078bcc0;
LAB_0044685a:
          FUN_0040c910(param_3,DAT_00736140,puVar7,uVar8,0);
        }
        else {
          if ((*(int *)(DAT_00736140 + 0xc) == 0) ||
             ((*(byte *)(*(int *)(DAT_00736140 + 0xc) + 0xe) & 0x40) == 0)) {
            uVar8 = 0;
            goto LAB_0044685a;
          }
          uVar2 = DAT_007355b4 + 0x1c0;
          if (uVar2 < DAT_007355b8) {
            bVar6 = DAT_007355b4 != 0;
            DAT_007355b4 = uVar2;
            if (bVar6) {
              CarRender_LitBodyPathA(uVar8,puVar7,&DAT_0078ea40,iVar3 + 0x40,param_3);
              puVar7 = (undefined *)puVar5[1];
              goto LAB_0044685a;
            }
          }
          else {
            DAT_007355c8 = DAT_007355c8 + 0x1c0;
            DAT_007355c4 = 1;
          }
        }
        *(undefined2 *)(puVar5[2] + 0x2e) = 0;
        DAT_00736140 = 0;
        puVar5 = puVar5 + 3;
      } while (puVar5 < *(uint **)(param_2 + 0x8c));
    }
  }
  return;
}


// ==== 0x4468a0 FUN_004468a0

void __fastcall FUN_004468a0(undefined4 param_1,int param_2,code *param_3)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  
  piVar1 = (int *)(in_EAX + 0x820);
  iVar2 = 0;
  if (0 < *piVar1) {
    while (*(int *)(in_EAX + 0x80) != param_2) {
      iVar2 = iVar2 + 1;
      in_EAX = in_EAX + 0xd0;
      if (*piVar1 <= iVar2) {
        return;
      }
    }
    uVar3 = *(uint *)(in_EAX + 0x88);
    if (uVar3 < *(uint *)(in_EAX + 0x8c)) {
      do {
        (*param_3)(uVar3);
        uVar3 = uVar3 + 0xc;
      } while (uVar3 < *(uint *)(in_EAX + 0x8c));
    }
  }
  return;
}


// ==== 0x446900 FUN_00446900

void FUN_00446900(void)

{
  int iVar1;
  int in_EAX;
  
  *(int *)in_EAX = in_EAX;
  *(int *)(in_EAX + 4) = in_EAX;
  iVar1 = in_EAX + 8;
  *(int *)iVar1 = iVar1;
  *(int *)(in_EAX + 0xc) = iVar1;
  iVar1 = in_EAX + 0x10;
  *(int *)iVar1 = iVar1;
  *(int *)(in_EAX + 0x14) = iVar1;
  iVar1 = in_EAX + 0x18;
  *(int *)iVar1 = iVar1;
  *(int *)(in_EAX + 0x1c) = iVar1;
  iVar1 = in_EAX + 0x20;
  *(int *)iVar1 = iVar1;
  *(int *)(in_EAX + 0x24) = iVar1;
  iVar1 = in_EAX + 0x28;
  *(int *)iVar1 = iVar1;
  *(int *)(in_EAX + 0x2c) = iVar1;
  iVar1 = in_EAX + 0x30;
  *(int *)iVar1 = iVar1;
  *(int *)(in_EAX + 0x34) = iVar1;
  iVar1 = in_EAX + 0x38;
  *(int *)iVar1 = iVar1;
  *(int *)(in_EAX + 0x3c) = iVar1;
  iVar1 = in_EAX + 0x40;
  *(int *)iVar1 = iVar1;
  *(int *)(in_EAX + 0x44) = iVar1;
  return;
}


// ==== 0x446950 FUN_00446950

void FUN_00446950(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *unaff_EDI;
  
  piVar1 = (int *)unaff_EDI[0x10];
  while (piVar1 != unaff_EDI + 0x10) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(piVar1);
    piVar1 = (int *)unaff_EDI[0x10];
  }
  piVar1 = (int *)unaff_EDI[0xe];
  while (piVar1 != unaff_EDI + 0xe) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(piVar1);
    piVar1 = (int *)unaff_EDI[0xe];
  }
  piVar1 = (int *)unaff_EDI[0xc];
  while (piVar1 != unaff_EDI + 0xc) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(piVar1);
    piVar1 = (int *)unaff_EDI[0xc];
  }
  piVar1 = (int *)unaff_EDI[10];
  while (piVar1 != unaff_EDI + 10) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(piVar1);
    piVar1 = (int *)unaff_EDI[10];
  }
  piVar1 = (int *)unaff_EDI[8];
  while (piVar1 != unaff_EDI + 8) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(piVar1);
    piVar1 = (int *)unaff_EDI[8];
  }
  piVar1 = (int *)unaff_EDI[6];
  while (piVar1 != unaff_EDI + 6) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(piVar1);
    piVar1 = (int *)unaff_EDI[6];
  }
  piVar1 = (int *)unaff_EDI[4];
  while (piVar1 != unaff_EDI + 4) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(piVar1);
    piVar1 = (int *)unaff_EDI[4];
  }
  piVar1 = (int *)unaff_EDI[2];
  while (piVar1 != unaff_EDI + 2) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(piVar1);
    piVar1 = (int *)unaff_EDI[2];
  }
  piVar1 = (int *)*unaff_EDI;
  while (piVar1 != unaff_EDI) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    _free(piVar1);
    piVar1 = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x446aa0 StreamBoundaries_Load

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

void StreamBoundaries_Load(void)

{
  StreamBoundaries_LoadChunk(&DAT_0077a930);
  return;
}


// ==== 0x446ab0 StreamBoundaries_Unload

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 StreamBoundaries_Unload(int *param_1)

{
  if (*param_1 == -0x7ffcbeb0) {
    _DAT_0077a930 = &DAT_0077a930;
    _DAT_0077a934 = &DAT_0077a930;
    _DAT_0077a938 = &DAT_0077a938;
    _DAT_0077a93c = &DAT_0077a938;
    DAT_0077a940 = &DAT_0077a940;
    _DAT_0077a944 = &DAT_0077a940;
    DAT_0077a950 = &DAT_0077a950;
    _DAT_0077a954 = &DAT_0077a950;
    DAT_0077a958 = &DAT_0077a958;
    _DAT_0077a95c = &DAT_0077a958;
    return 1;
  }
  return 0;
}


// ==== 0x446b10 FUN_00446b10

void FUN_00446b10(void)

{
  int in_EAX;
  int iVar1;
  undefined2 *puVar2;
  short *psVar3;
  int unaff_EDI;
  
  iVar1 = 0;
  if (0 < *(int *)(in_EAX + 0x10)) {
    psVar3 = (short *)(in_EAX + 0x14);
    while (*psVar3 != unaff_EDI) {
      iVar1 = iVar1 + 1;
      psVar3 = psVar3 + 1;
      if (*(int *)(in_EAX + 0x10) <= iVar1) {
        return;
      }
    }
    if (iVar1 < *(int *)(in_EAX + 0x10) + -1) {
      puVar2 = (undefined2 *)(in_EAX + 0x14 + iVar1 * 2);
      do {
        *puVar2 = puVar2[1];
        iVar1 = iVar1 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar1 < *(int *)(in_EAX + 0x10) + -1);
    }
    iVar1 = *(int *)(in_EAX + 0x10) + -1;
    *(int *)(in_EAX + 0x10) = iVar1;
    *(undefined2 *)(in_EAX + 0x14 + iVar1 * 2) = 0;
  }
  return;
}


// ==== 0x446b70 FUN_00446b70

void FUN_00446b70(void)

{
  short sVar1;
  bool bVar2;
  short *psVar3;
  int iVar4;
  int unaff_EDI;
  
  do {
    bVar2 = false;
    iVar4 = 0;
    if (*(int *)(unaff_EDI + 0x10) == 1 || *(int *)(unaff_EDI + 0x10) + -1 < 0) {
      return;
    }
    psVar3 = (short *)(unaff_EDI + 0x14);
    do {
      sVar1 = psVar3[1];
      if (sVar1 < *psVar3) {
        psVar3[1] = *psVar3;
        *psVar3 = sVar1;
        bVar2 = true;
      }
      iVar4 = iVar4 + 1;
      psVar3 = psVar3 + 1;
    } while (iVar4 < *(int *)(unaff_EDI + 0x10) + -1);
  } while (bVar2);
  return;
}


// ==== 0x446bb0 FUN_00446bb0

void __thiscall FUN_00446bb0(int param_1,char param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  short *psVar6;
  int local_4;
  
  if (param_2 != '\0') {
    FUN_00446bb0(0);
  }
  local_4 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    psVar6 = (short *)(param_1 + 0x14);
    do {
      iVar4 = (int)*psVar6;
      cVar1 = (char)(iVar4 / 100) + '@';
      if (((('@' < cVar1) && (cVar1 < 'U')) && (0 < iVar4 % 100)) && (iVar4 % 100 < 10)) {
        iVar4 = iVar4 + 10;
        if (param_2 == '\0') {
          iVar3 = 0;
          if (0 < *(int *)(param_1 + 0x10)) {
            psVar5 = (short *)(param_1 + 0x14);
            do {
              if (*psVar5 == iVar4) {
                FUN_00446b10();
                local_4 = local_4 + -1;
                psVar6 = psVar6 + -1;
                break;
              }
              iVar3 = iVar3 + 1;
              psVar5 = psVar5 + 1;
            } while (iVar3 < *(int *)(param_1 + 0x10));
          }
        }
        else {
          iVar3 = *(int *)(param_1 + 0x10);
          if (iVar3 < 0x40) {
            iVar2 = 0;
            if (0 < iVar3) {
              psVar5 = (short *)(param_1 + 0x14);
              do {
                if (*psVar5 == iVar4) goto LAB_00446c6a;
                iVar2 = iVar2 + 1;
                psVar5 = psVar5 + 1;
              } while (iVar2 < *(int *)(param_1 + 0x10));
            }
            *(short *)(param_1 + 0x14 + iVar3 * 2) = (short)iVar4;
            *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
          }
        }
      }
LAB_00446c6a:
      local_4 = local_4 + 1;
      psVar6 = psVar6 + 1;
    } while (local_4 < *(int *)(param_1 + 0x10));
  }
  return;
}


// ==== 0x446c90 FUN_00446c90

void FUN_00446c90(void)

{
  char cVar1;
  short *psVar2;
  short sVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  int unaff_ESI;
  char local_5;
  int local_4;
  
  iVar6 = 0;
  if (0 < *(int *)(unaff_ESI + 0x10)) {
    psVar5 = (short *)(unaff_ESI + 0x14);
    do {
      iVar4 = (int)*psVar5 % 100;
      cVar1 = (char)((int)*psVar5 / 100) + '@';
      if ((('@' < cVar1) && (cVar1 < 'U')) && ((iVar4 == 0 || (iVar4 == 10)))) {
        FUN_00446b10();
        iVar6 = iVar6 + -1;
        psVar5 = psVar5 + -1;
      }
      iVar6 = iVar6 + 1;
      psVar5 = psVar5 + 1;
    } while (iVar6 < *(int *)(unaff_ESI + 0x10));
  }
  local_5 = 'A';
  do {
    local_4 = 0;
    if (0 < *(int *)(unaff_ESI + 0x10)) {
      psVar5 = (short *)(unaff_ESI + 0x14);
      do {
        cVar1 = (char)((int)*psVar5 / 100) + '@';
        if (cVar1 == local_5) {
          if ((int)*psVar5 % 100 < 10) {
            sVar3 = (cVar1 + -0x40) * 100;
            iVar6 = *(int *)(unaff_ESI + 0x10);
            if (iVar6 < 0x40) {
              iVar4 = 0;
              if (0 < iVar6) {
                psVar2 = (short *)(unaff_ESI + 0x14);
                do {
                  if (*psVar2 == sVar3) goto LAB_00446d7e;
                  iVar4 = iVar4 + 1;
                  psVar2 = psVar2 + 1;
                } while (iVar4 < *(int *)(unaff_ESI + 0x10));
              }
LAB_00446d76:
              *(short *)(unaff_ESI + 0x14 + iVar6 * 2) = sVar3;
              *(int *)(unaff_ESI + 0x10) = *(int *)(unaff_ESI + 0x10) + 1;
            }
          }
          else {
            iVar6 = *(int *)(unaff_ESI + 0x10);
            sVar3 = cVar1 * 100 + -0x18f6;
            if (iVar6 < 0x40) {
              iVar4 = 0;
              if (0 < iVar6) {
                psVar2 = (short *)(unaff_ESI + 0x14);
                do {
                  if (*psVar2 == sVar3) goto LAB_00446d7e;
                  iVar4 = iVar4 + 1;
                  psVar2 = psVar2 + 1;
                } while (iVar4 < *(int *)(unaff_ESI + 0x10));
              }
              goto LAB_00446d76;
            }
          }
        }
LAB_00446d7e:
        local_4 = local_4 + 1;
        psVar5 = psVar5 + 1;
      } while (local_4 < *(int *)(unaff_ESI + 0x10));
    }
    local_5 = local_5 + '\x01';
    if ('T' < local_5) {
      return;
    }
  } while( true );
}


// ==== 0x446db0 StreamBoundaries_LoadChunk

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

undefined4 StreamBoundaries_LoadChunk(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int *in_EAX;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint local_8;
  
  if (*in_EAX != -0x7ffcbeb0) {
    return 0;
  }
  iVar2 = in_EAX[1];
  piVar1 = in_EAX + 2;
  do {
    if ((int *)(iVar2 + 8 + (int)in_EAX) <= piVar1) {
      if (DAT_007360fc != 0) {
        StreamBoundaries__DebugDump();
        DAT_0077aaf9 = 1;
        DAT_0077aa6c = 0xffffffff;
        DAT_0077aab0 = 0xffffffff;
      }
      return 1;
    }
    iVar6 = *piVar1;
    if (iVar6 == 0x34151) {
      piVar5 = piVar1 + 2;
      for (uVar8 = (uint)piVar1[1] / 0x8c; uVar8 != 0; uVar8 = uVar8 - 1) {
        iVar6 = (int)(short)piVar5[2] % 100;
        cVar3 = (char)((int)(short)piVar5[2] / 100) + '@';
        if ((((cVar3 < 'A') || ('T' < cVar3)) || (iVar6 < 1)) || (9 < iVar6)) {
          puVar4 = (undefined4 *)param_1[3];
          *puVar4 = piVar5;
          param_1[3] = piVar5;
          piVar5[1] = (int)puVar4;
          *piVar5 = (int)(param_1 + 2);
        }
        else {
          puVar4 = (undefined4 *)param_1[1];
          *puVar4 = piVar5;
          param_1[1] = piVar5;
          piVar5[1] = (int)puVar4;
          *piVar5 = (int)param_1;
        }
        piVar5 = piVar5 + 0x23;
      }
    }
    else if (iVar6 == 0x34152) {
      local_8 = (uint)piVar1[1] / 0x94;
      piVar5 = piVar1 + 2;
      if (local_8 != 0) {
        puVar4 = (undefined4 *)NullUpdate_ret();
        do {
          puVar7 = (undefined4 *)param_1[5];
          *puVar7 = piVar5;
          param_1[5] = piVar5;
          piVar5[1] = (int)puVar7;
          *piVar5 = (int)(param_1 + 4);
          for (puVar7 = (undefined4 *)*param_1; puVar7 != puVar4; puVar7 = (undefined4 *)*puVar7) {
            if (*(short *)(puVar7 + 2) == (short)piVar5[2]) goto LAB_00446eec;
          }
          for (puVar7 = (undefined4 *)param_1[2]; puVar7 != param_1 + 2;
              puVar7 = (undefined4 *)*puVar7) {
            if (*(short *)(puVar7 + 2) == (short)piVar5[2]) goto LAB_00446eec;
          }
          puVar7 = (undefined4 *)0x0;
LAB_00446eec:
          piVar5[3] = (int)puVar7;
          piVar5 = piVar5 + 0x25;
          local_8 = local_8 - 1;
        } while (local_8 != 0);
      }
    }
    else if (iVar6 == 0x34153) {
      uVar8 = (uint)piVar1[1] / 0x110;
      piVar5 = piVar1 + 2;
      if (uVar8 != 0) {
        do {
          puVar4 = (undefined4 *)param_1[9];
          *puVar4 = piVar5;
          param_1[9] = piVar5;
          piVar5[1] = (int)puVar4;
          *piVar5 = (int)(param_1 + 8);
          piVar5 = piVar5 + 0x44;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
    }
    else if (iVar6 == 0x34154) {
      uVar8 = (uint)piVar1[1] >> 5;
      piVar5 = piVar1 + 2;
      if (uVar8 != 0) {
        do {
          puVar4 = (undefined4 *)param_1[0xb];
          *puVar4 = piVar5;
          param_1[0xb] = piVar5;
          piVar5[1] = (int)puVar4;
          *piVar5 = (int)(param_1 + 10);
          piVar5 = piVar5 + 8;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
    }
    piVar1 = (int *)((int)piVar1 + piVar1[1] + 8);
  } while( true );
}


// ==== 0x446fd0 StreamBoundaries::FindContaining

/* [canon] track high (hopper+ghidra) docs/re/track.md */

int * StreamBoundaries__FindContaining(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  int in_EAX;
  int *piVar5;
  
  piVar1 = *(int **)(in_EAX + 0x10);
  piVar5 = (int *)(in_EAX + 0x10);
  while( true ) {
    if (piVar1 == piVar5) {
      return (int *)0x0;
    }
    cVar4 = PointInPolygon2D(piVar1[3] + 0xc,(int)*(short *)(piVar1[3] + 10));
    if (cVar4 != '\0') break;
    piVar1 = (int *)*piVar1;
  }
  iVar2 = *piVar1;
  piVar3 = (int *)piVar1[1];
  *piVar3 = iVar2;
  *(int **)(iVar2 + 4) = piVar3;
  iVar2 = *piVar5;
  *piVar5 = (int)piVar1;
  *(int **)(iVar2 + 4) = piVar1;
  piVar1[1] = (int)piVar5;
  *piVar1 = iVar2;
  return piVar1;
}


// ==== 0x447030 FUN_00447030

void FUN_00447030(void)

{
  FUN_00565ce0();
  return;
}


// ==== 0x447040 FUN_00447040

void FUN_00447040(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (DAT_0073459c != 0) {
    DAT_0070095c = FUN_0057c5a0(1);
    FUN_00565b60(0x10,0,0,0);
    FUN_00565ce0();
    return;
  }
  iVar1 = bOpenFile();
  if (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 4);
    FUN_00594d40();
    if (iVar1 != -1) {
      puVar2 = (undefined4 *)FUN_00594e30(0);
      uVar3 = *puVar2;
      FUN_00565ce0();
      goto LAB_004470ae;
    }
  }
  uVar3 = 0xffffffff;
LAB_004470ae:
  DAT_0070095c = uVar3;
  if (DAT_007345a0 != 0) {
    FUN_0057c3b0(uVar3,0x20,1);
  }
  return;
}


// ==== 0x4470d0 FUN_004470d0

void FUN_004470d0(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  LARGE_INTEGER local_8;
  
  if (DAT_0073459c == 0) {
    QueryPerformanceCounter(&local_8);
    iVar2 = __allshr();
    uVar1 = iVar2 + 0x12345678;
    if (DAT_007345a0 != 0) {
      FUN_0057c3b0(uVar1,0x20,10);
    }
  }
  else {
    uVar1 = FUN_0057c5a0(10);
  }
  uVar1 = uVar1 ^ 0x1d872b41;
  uVar3 = uVar1 >> 5 ^ uVar1;
  DAT_006f227c = uVar3 << 0x1b ^ uVar3 ^ uVar1;
  return;
}


// ==== 0x447160 InitZDirArchive

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (hopper) docs/re/assets.md */

void InitZDirArchive(void)

{
  int iVar1;
  
  iVar1 = bOpenFile("NFSUNDER\\ZDIR.BIN",0,1);
  if (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 4);
    FUN_00594d40();
    if (iVar1 != -1) {
      FUN_00594970("NFSUNDER\\ZZDATA");
      return;
    }
  }
  _DAT_00736108 = 0;
  return;
}


// ==== 0x4471b0 GameFlow::InitSubsystems

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon med (hopper) docs/re/gameflow.md */

void GameFlow__InitSubsystems(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uStack_63;
  
  FUN_00401110();
  puVar2 = &uStack_63;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 2) = 0;
  FUN_00449f20(100);
  InitZDirArchive();
  _DAT_0078e950 = DAT_0073ad3c;
  DAT_0078e954 = DAT_0073ad3c;
  _DAT_0078e958 = 0xffffffff;
  _DAT_0078e966 = 0;
  _DAT_0078e968 = 0;
  _DAT_0078e96c = 10;
  _DAT_0078e96a = 1;
  _DAT_0078e96e = 0;
  FUN_005649f0();
  FUN_005649f0();
  FUN_0057c6d0();
  FUN_004470d0();
  FUN_00447040();
  FUN_0058ab50();
  FUN_0058dd50();
  FUN_0043a1a0();
  ViewMatrix_InitIdentity();
  Render_InitSubsystem();
  FUN_00402720();
  InitResourceFileSlotPool();
  InputEvents__Init();
  FUN_00520460();
  FEManager__Init();
  GameFlow__LoadGlobalA();
  GameFlow__LoadGlobalB();
  FUN_00569930();
  FUN_004ab2b0(&DAT_00748f70);
  DAT_00735ec4 = FUN_00565b60(0x59f0,0,0,0);
  _DAT_00735ec8 = 0;
  FUN_0058b110();
  FUN_0059dfe0();
  FUN_00577c30();
  FUN_00579430();
  DiscCheck_ModalFrameLoop(0);
  return;
}


// ==== 0x4472e0 GameFlow::Run

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (hopper+capstone) docs/re/gameflow.md */

void GameFlow__Run(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = FUN_00401a10("speed.exe",1);
  if (cVar1 != '\0') {
                    /* WARNING: Subroutine does not return */
    __exit(0);
  }
  GameFlow__InitSubsystems(param_1,param_2);
  if (DAT_0073465c == 0) {
    if (DAT_0077a918 != '\0') {
      DAT_0077a918 = '\0';
    }
    DAT_0077a904 = GameFlow__LoadingFrontEndPart1;
    _DAT_0077a90c = "LoadingFrontEnd";
  }
  else {
    QuickRace__LaunchFromSetupGlobals();
  }
  GameFlow__MainLoop();
  FUN_00411830();
                    /* WARNING: Subroutine does not return */
  __exit(0);
}


// ==== 0x447360 FUN_00447360

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00447360(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_8;
  
  local_8 = DAT_00736120 - _DAT_0073611c;
  if (local_8 < 0) {
    local_8 = 0;
  }
  fVar1 = (float)(1 << ((byte)DAT_007349c8 & 0x1f)) * (float)local_8 * _DAT_007301d0;
  if (fVar1 < 0.1) {
    fVar1 = 0.1;
  }
  if (((DAT_0078f1d0 ^ DAT_006f0888) & 8) != 0) {
    DAT_0078f1d0 = DAT_006f0888;
    _DAT_00736110 = 0x3dcccccd;
    _DAT_00736118 = 0x461c4000;
    _DAT_0073610c = fVar1;
    _DAT_00736114 = 1000.0 / fVar1;
  }
  if (DAT_00734964 != 0) {
    iVar4 = DAT_00734964;
    if ((DAT_007361f8 != 0) && (iVar6 = 0, 0 < *(int *)(DAT_007361f8 + 0x18))) {
      iVar5 = 0x28;
      iVar2 = DAT_007361f8;
      iVar3 = DAT_0073619c;
      do {
        if ((iVar4 != 0) || (DAT_007361dc != 0)) {
          if (DAT_006fbf14 == 0) {
            if (DAT_006fbf18 == *(short *)(*(int *)(iVar5 + iVar2) + 10)) {
LAB_00447460:
              if (iVar3 != 0) {
                FUN_00435b30(iVar3);
                iVar2 = DAT_007361f8;
                iVar3 = DAT_0073619c;
                iVar4 = DAT_00734964;
              }
            }
          }
          else if (*(short *)(*(int *)(iVar5 + iVar2) + 10) == 0) goto LAB_00447460;
        }
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + 4;
      } while (iVar6 < *(int *)(iVar2 + 0x18));
    }
    if (iVar4 != 0) {
      FUN_00448590();
      return;
    }
  }
  return;
}


// ==== 0x4474a0 FUN_004474a0

void FUN_004474a0(void)

{
  code *pcVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = 0;
  if (DAT_007361f8 != 0) {
    uVar7 = FUN_00421170(DAT_007361f8);
  }
  uVar6 = FUN_004f3e50();
  uVar4 = DAT_00734574;
  uVar3 = DAT_006f227c;
  uVar8 = DAT_00734574 + DAT_006f227c + uVar6 + uVar7;
  bVar2 = false;
  if (DAT_0073459c == 0) {
    if (DAT_007345a0 == 0) {
      return;
    }
    FUN_0057c3b0(uVar8 & 0xffff,0x10,4);
  }
  else {
    sVar5 = FUN_0057c5a0(4);
    if (sVar5 != (short)uVar8) {
      bVar2 = true;
    }
  }
  if (DAT_0073459c == 0) {
    if ((((DAT_007345a0 != 0) && (FUN_0057c3b0(uVar7 & 0xffff,0x10,4), DAT_007345a0 != 0)) &&
        (FUN_0057c3b0(uVar6 & 0xffff,0x10,4), DAT_007345a0 != 0)) &&
       (FUN_0057c3b0(uVar3 & 0xffff,0x10,4), DAT_007345a0 != 0)) {
      FUN_0057c3b0(uVar4 & 0xffff,0x10,4);
    }
  }
  else {
    FUN_0057c5a0(4);
    FUN_0057c5a0(4);
    FUN_0057c5a0(4);
    FUN_0057c5a0(4);
  }
  if (!bVar2) {
    return;
  }
  if (DAT_0073459c != 0) {
    DAT_007345a4 = 0;
    DAT_0073459c = 0;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== 0x447600 GameFlow::MainLoop

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (ghidra+capstone+hopper) docs/re/gameflow.md */

void GameFlow__MainLoop(void)

{
  int *piVar1;
  code *pcVar2;
  int *piVar3;
  float fVar4;
  char cVar5;
  int iVar6;
  code *pcVar7;
  undefined *puVar8;
  bool bVar9;
  float10 fVar10;
  undefined4 uVar11;
  int iStack_3c;
  LARGE_INTEGER local_30;
  LARGE_INTEGER local_28;
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [12];
  LARGE_INTEGER LStack_10;
  
  QueryPerformanceCounter(&local_30);
  __allshr();
  pcVar7 = QueryPerformanceCounter_exref;
  do {
    if (DAT_00736124 != 0) {
      QueryPerformanceCounter_exref = pcVar7;
      return;
    }
    QueryPerformanceCounter_exref = pcVar7;
    QueryPerformanceCounter(&local_28);
    _DAT_0073611c = __allshr();
    piVar3 = DAT_007345a8;
    _DAT_0078eb50 = DAT_00734560;
    iVar6 = 0;
    pcVar2 = DAT_0077a904;
    uVar11 = DAT_0077a908;
    if (DAT_00734598 != 0) {
      if ((DAT_007345a8 != (int *)0x0) &&
         (piVar1 = DAT_007345a8 + 3, 0 < *DAT_007345a8 - DAT_007345a8[3])) {
        FUN_00594ef0(DAT_007345a8 + 0x19);
        *piVar1 = *piVar3;
        piVar3[1] = 0;
      }
      DAT_00734598 = 0;
      iVar6 = DAT_00734598;
      pcVar2 = DAT_0077a904;
      uVar11 = DAT_0077a908;
      pcVar7 = QueryPerformanceCounter_exref;
    }
    do {
      DAT_00734598 = iVar6;
      DAT_0077a904 = pcVar2;
      DAT_0077a908 = uVar11;
      if (pcVar2 == (code *)0x0) break;
      DAT_0077a904 = (code *)0x0;
      DAT_0077a908 = 0;
      _DAT_0077a90c = 0;
      (*pcVar2)(uVar11);
      bVar9 = DAT_0077a904 != pcVar2;
      iVar6 = DAT_00734598;
      pcVar2 = DAT_0077a904;
      uVar11 = DAT_0077a908;
    } while (bVar9);
    if (DAT_0077a910 != (code *)0x0) {
      (*DAT_0077a910)();
    }
    pcVar2 = DAT_0077a904;
    uVar11 = DAT_0077a908;
    if (DAT_007361f0 != (int *)0x0) {
      Race__PumpFlowMessages(DAT_007361f0);
      FUN_00421bc0(3,0);
      pcVar2 = DAT_0077a904;
      uVar11 = DAT_0077a908;
    }
    do {
      DAT_0077a904 = pcVar2;
      DAT_0077a908 = uVar11;
      if (pcVar2 == (code *)0x0) break;
      DAT_0077a904 = (code *)0x0;
      DAT_0077a908 = 0;
      _DAT_0077a90c = 0;
      (*pcVar2)(uVar11);
      bVar9 = DAT_0077a904 != pcVar2;
      pcVar2 = DAT_0077a904;
      uVar11 = DAT_0077a908;
    } while (bVar9);
    if (DAT_0077a910 != (code *)0x0) {
      (*DAT_0077a910)();
    }
    if ((DAT_0077a920 != 6) || (*DAT_007361f0 == 1)) {
      FUN_004474a0();
    }
    iVar6 = 0;
    if (0 < DAT_007361c4) {
      do {
        Player__DetermineInputMode();
        iVar6 = iVar6 + 1;
      } while (iVar6 < DAT_007361c4);
    }
    if (DAT_007345d0 != 0) {
      FUN_00572800();
    }
    (*pcVar7)(auStack_20);
    uVar11 = DAT_007349c8;
    iVar6 = __allshr();
    iStack_3c = iVar6 - iStack_3c;
    if (iStack_3c < 0) {
      iStack_3c = 0;
    }
    FUN_00585b40((float)(1 << ((byte)uVar11 & 0x1f)) * (float)iStack_3c * _DAT_007301d0 * 0.001);
    (*pcVar7)(auStack_1c);
    __allshr();
    FUN_004829a0();
    uVar11 = 1;
    cVar5 = FUN_0043a2e0();
    if (((cVar5 == '\0') && (DAT_007361f0 != (int *)0x0)) &&
       ((*DAT_007361f0 == 7 || (*DAT_007361f0 == 0xb)))) {
      bVar9 = true;
    }
    else {
      bVar9 = false;
    }
    if (bVar9) {
      fVar10 = (float10)FUN_0043a8a0(0);
      DAT_0073457c = (float)fVar10;
LAB_0044798b:
      _DAT_006f08a8 = 0;
      InputEvents__Update();
    }
    else {
      if (DAT_007361f0 == (int *)0x0) {
        DAT_0073457c = DAT_0073ad38;
        goto LAB_0044798b;
      }
      FUN_004200a0();
      if (((0.0 < *(float *)(DAT_007361f8 + 0x2d4)) || (DAT_007361fc != 0)) ||
         (*(int *)(DAT_007361f8 + 0x2d8) != 0)) {
        fVar10 = (float10)FUN_0043a8a0(0);
        DAT_0073457c = (float)fVar10;
        _DAT_006f08a8 = 0;
        InputEvents__Update();
        FUN_00421740();
      }
      else {
        FUN_005721f0();
        if (*(int *)(DAT_007345d0 + 0x18) == 0) {
          fVar10 = (float10)FUN_00420110(DAT_007361f8);
          fVar10 = (float10)FUN_0043a8a0((float)fVar10);
          DAT_0073457c = (float)fVar10;
          _DAT_006f08a8 = 0;
          InputEvents__Update();
          FUN_0043a7f0();
          FUN_00420b40(DAT_007361f8,(float)fVar10);
          uVar11 = 0;
          FUN_005727b0();
        }
        else {
          fVar10 = (float10)FUN_0043a8a0(0);
          DAT_0073457c = (float)fVar10;
          _DAT_006f08a8 = 0;
          InputEvents__Update();
          FUN_005727b0();
        }
      }
    }
    FUN_0043a360(uVar11);
    FEManager__Update();
    Players__UpdateAll();
    FUN_0047dc40(DAT_0073ad38);
    Players__UpdateStreamViewers();
    if (DAT_007356a8 != 0) {
      EAXSound__Update(DAT_0073ad38);
    }
    fVar4 = DAT_0073ad38;
    puVar8 = &DAT_0073b158;
    do {
      iVar6 = 2;
      do {
        FUN_00574cf0(fVar4);
        puVar8 = puVar8 + 0x30;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    } while ((int)puVar8 < 0x73b218);
    FUN_00574eb0();
    StreamSections__Update();
    ServiceResourceLoading();
    RenderFrame();
    FUN_00585d70();
    FUN_00585e00();
    if ((char)iStack_3c == '\0') {
      FUN_0043a810();
    }
    QueryPerformanceCounter(&LStack_10);
    DAT_00736120 = __allshr();
    FUN_00447360();
    FUN_00411030();
    pcVar7 = QueryPerformanceCounter_exref;
  } while( true );
}


// ==== 0x447a90 FUN_00447a90

void __fastcall FUN_00447a90(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_007360f8;
  iVar1 = *(int *)(DAT_007360f8 + 0x18);
  *param_1 = *(undefined4 *)(DAT_007360f8 + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x447ab0 PaddingChunk::Loader

/* [canon] assets high (capstone) docs/re/assets.md */

bool PaddingChunk__Loader(int *param_1)

{
  return *param_1 == 0;
}


// ==== 0x447ac0 bChunkLoader::LoadChunks

/* [canon] assets high (hopper+ghidra) docs/re/assets.md */

void __thiscall bChunkLoader__LoadChunks(int param_1,int param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = param_1 + in_EAX;
  iVar5 = 0;
  iVar4 = 0;
  do {
    while( true ) {
      if (param_1 == iVar1) {
        return;
      }
      iVar3 = (**(code **)(param_2 + iVar4 * 4))(param_1);
      if (iVar3 == 0) break;
      param_1 = param_1 + 8 + *(int *)(param_1 + 4);
      iVar5 = 0;
    }
    iVar4 = iVar4 + 1;
    if (iVar4 == param_3) {
      iVar4 = 0;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 <= param_3);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}


// ==== 0x447b10 bChunkLoader::UnloadChunks

/* [canon] assets high (hopper+ghidra) docs/re/assets.md */

void bChunkLoader__UnloadChunks(int param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int in_EAX;
  int iVar4;
  int iVar5;
  LARGE_INTEGER local_18;
  LARGE_INTEGER LStack_10;
  
  iVar4 = param_1 + in_EAX;
  do {
    if (param_1 == iVar4) {
      return;
    }
    iVar5 = *(int *)(param_1 + 4) + 8 + param_1;
    iVar3 = param_1;
    while (iVar2 = iVar5, iVar2 != iVar4) {
      iVar3 = iVar2;
      iVar5 = iVar2 + 8 + *(int *)(iVar2 + 4);
    }
    iVar5 = 0;
    if (0 < param_3) {
      do {
        pcVar1 = *(code **)(param_2 + iVar5 * 4);
        QueryPerformanceCounter(&local_18);
        iVar4 = (*pcVar1)(iVar3);
        QueryPerformanceCounter(&LStack_10);
        if (iVar4 != 0) break;
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_3);
    }
    iVar4 = iVar3;
    if (iVar5 == param_3) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  } while( true );
}


// ==== 0x447bb0 FUN_00447bb0

void FUN_00447bb0(int *param_1,int *param_2)

{
  for (; param_1 < param_2; param_1 = (int *)((int)param_1 + param_1[1] + 8)) {
    if (*param_1 < 0) {
      DAT_007360f0 = DAT_007360f0 + 1;
      FUN_00447bb0(param_1 + 2,param_1[1] + 8 + (int)param_1);
      DAT_007360f0 = DAT_007360f0 + -1;
    }
  }
  return;
}


// ==== 0x447c00 PlaceChunks

/* [canon] assets high (hopper+ghidra) docs/re/assets.md */

void PlaceChunks(int *param_1,uint *param_2,uint *param_3,int param_4,int param_5,int param_6,
                int param_7)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  
  puVar3 = (uint *)(param_4 + (int)param_3);
  do {
    if (puVar3 <= param_3) {
      return;
    }
    uVar5 = *param_3;
    uVar7 = *param_2;
    puVar9 = (uint *)(uVar7 + param_7);
    uVar1 = param_3[1];
    puVar6 = (uint *)(*param_1 + param_6);
    if (uVar5 != 0xb3320000) {
      if ((uVar5 & 0x80000000) != 0) {
        if (param_6 != 0) {
          *puVar6 = *param_3;
          puVar6[1] = param_3[1];
        }
        *param_1 = *param_1 + 8;
        goto LAB_00447d30;
      }
      if (param_6 != 0) {
        puVar9 = param_3;
        for (uVar5 = uVar1 + 8 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar6 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar6 = puVar6 + 1;
        }
        for (uVar5 = uVar1 + 8 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(char *)puVar6 = (char)*puVar9;
          puVar9 = (uint *)((int)puVar9 + 1);
          puVar6 = (uint *)((int)puVar6 + 1);
        }
      }
      *param_1 = *param_1 + uVar1 + 8;
    }
    else {
      if ((uVar7 & 0x7f) != 0) {
        iVar2 = -(uVar7 + 8 & 0x7f);
        uVar7 = iVar2 + 0x80;
        if (param_7 != 0) {
          *puVar9 = 0;
          puVar9[1] = uVar7;
          puVar9 = puVar9 + 2;
          for (uVar4 = uVar7 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar9 = 0x11111111;
            puVar9 = puVar9 + 1;
          }
          for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
            *(undefined1 *)puVar9 = 0x11;
            puVar9 = (uint *)((int)puVar9 + 1);
          }
        }
        uVar7 = *param_2 + iVar2 + 0x88;
        *param_2 = uVar7;
        puVar9 = (uint *)(uVar7 + param_7);
      }
      if (param_7 != 0) {
        puVar8 = param_3;
        for (uVar7 = uVar1 + 8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar9 = puVar9 + 1;
        }
        for (uVar7 = uVar1 + 8 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(char *)puVar9 = (char)*puVar8;
          puVar8 = (uint *)((int)puVar8 + 1);
          puVar9 = (uint *)((int)puVar9 + 1);
        }
      }
      *param_2 = *param_2 + uVar1 + 8;
LAB_00447d30:
      if (((uVar5 & 0x80000000) != 0) && (uVar5 != 0xb3320000)) {
        iVar2 = *param_1;
        PlaceChunks(param_1,param_2,param_3 + 2,uVar1,param_5 + 1,param_6,param_7);
        if (param_6 != 0) {
          puVar6[1] = *param_1 - iVar2;
        }
      }
    }
    param_3 = (uint *)((int)param_3 + param_3[1] + 8);
  } while( true );
}


// ==== 0x447d90 LoadResourceChunks

/* WARNING: Type propagation algorithm not settling */
/* [canon] assets high (hopper+ghidra) docs/re/assets.md */

uint LoadResourceChunks(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_10;
  int local_c [3];
  
  iVar1 = *param_2;
  iVar2 = *param_1;
  if ((iVar2 != 0) && (iVar1 != 0)) {
    local_c[0] = 0;
    local_10 = 0;
    PlaceChunks(local_c,&local_10,iVar2,iVar1,0,0,0);
    if (local_10 != 0) {
      iVar3 = FUN_00565b60(local_c[0],0,0,param_3);
      iVar4 = FUN_00565b60(local_10,0,0,0x2000);
      local_c[2] = 0;
      local_c[1] = 0;
      PlaceChunks(local_c + 2,local_c + 1,iVar2,iVar1,0,iVar3,iVar4);
      FUN_00565ce0();
      if ((iVar4 != 0) && (local_10 != 0)) {
        bChunkLoader__LoadChunks(&PTR_PaddingChunk__Loader_007007e0,0x2f,param_4);
      }
      if ((iVar3 != 0) && (local_c[0] != 0)) {
        bChunkLoader__LoadChunks(&PTR_PaddingChunk__Loader_007007e0,0x2f,param_4);
      }
      if ((iVar4 != 0) && (local_10 != 0)) {
        bChunkLoader__UnloadChunks(iVar4,&PTR_PaddingChunk__Loader_007008a0,0x2f,param_4);
      }
      FUN_00565ce0();
      *param_2 = local_c[0];
      *param_1 = iVar3;
      DAT_007360f4 = DAT_007360f4 + local_10;
      return CONCAT31((int3)((uint)DAT_007360f4 >> 8),1);
    }
    param_1 = (int *)bChunkLoader__LoadChunks(&PTR_PaddingChunk__Loader_007007e0,0x2f,param_4);
  }
  return (uint)param_1 & 0xffffff00;
}


// ==== 0x447ee0 FUN_00447ee0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00447ee0(void)

{
  int iVar1;
  LARGE_INTEGER local_8;
  
  QueryPerformanceCounter(&local_8);
  iVar1 = DAT_0073556c;
  if (DAT_0073556c != 0) {
    FUN_00544790();
  }
  if ((DAT_00735564 == 0) && ((DAT_00735568 != 0 || (iVar1 != 0)))) {
    RVM_LookupTextures();
    DAT_00735568 = 0;
    DAT_0073556c = 0;
    _DAT_00735570 = 0;
  }
  return;
}


// ==== 0x447f40 InitResourceFileSlotPool

/* [canon] assets high (hopper) docs/re/assets.md */

void InitResourceFileSlotPool(void)

{
  undefined4 *puVar1;
  
  DAT_007360f8 = (undefined4 *)FUN_00566dc0(0xb4,"ResourceFileSlotPool",0);
  if (DAT_007360f8 == (undefined4 *)0x0) {
    return;
  }
  if (DAT_0073d814 == 1) {
    *DAT_0073d81c = DAT_007360f8;
    puVar1 = DAT_007360f8;
    DAT_007360f8[1] = DAT_0073d81c;
    DAT_0073d81c = puVar1;
    *DAT_007360f8 = &DAT_0073d818;
  }
  return;
}


// ==== 0x447f90 ResourceFile::ResourceFile

/* [canon] assets med (hopper) docs/re/assets.md */

void __fastcall
ResourceFile__ResourceFile(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4)

{
  char *pcVar1;
  char cVar2;
  undefined4 in_EAX;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + 8) = in_EAX;
  *(undefined4 *)(unaff_EDI + 0xc) = param_1;
  *(undefined4 *)(unaff_EDI + 0x10) = param_2;
  *(undefined4 *)(unaff_EDI + 0x14) = param_4;
  cVar2 = *param_3;
  pcVar1 = (char *)(unaff_EDI + 0x18);
  *pcVar1 = cVar2;
  if (cVar2 != '\0') {
    pcVar3 = pcVar1;
    do {
      cVar2 = pcVar3[(int)(param_3 + (1 - (int)pcVar1))];
      pcVar3 = pcVar3 + 1;
      *pcVar3 = cVar2;
    } while (cVar2 != '\0');
  }
  *(undefined1 *)(unaff_EDI + 0x40) = 0;
  *(undefined4 *)(unaff_EDI + 0x8c) = 0;
  *(undefined4 *)(unaff_EDI + 0x90) = 0;
  *(undefined4 *)(unaff_EDI + 0xac) = 0;
  *(undefined4 *)(unaff_EDI + 0xa4) = 0;
  *(undefined4 *)(unaff_EDI + 0xa8) = 0;
  *(undefined4 *)(unaff_EDI + 0xb0) = 0;
  *(undefined4 *)(unaff_EDI + 0x94) = 0;
  *(undefined4 *)(unaff_EDI + 0x98) = 0;
  FUN_00448070(param_3);
  *(undefined1 *)(unaff_EDI + 0x40) = 0;
  iVar4 = bOpenFile(pcVar1,1,1);
  if (iVar4 == 0) {
    uVar5 = 0xffffffff;
  }
  else {
    uVar5 = ((int)*(uint *)(iVar4 + 4) < 0) - 1 & *(uint *)(iVar4 + 4);
    FUN_00594d40();
  }
  *(uint *)(unaff_EDI + 0xa0) = uVar5;
  if ((int)uVar5 < 0) {
    *(undefined4 *)(unaff_EDI + 0xa0) = 0;
  }
  *(undefined4 *)(unaff_EDI + 0x9c) = 0;
  if ((*(int *)(unaff_EDI + 0xa0) != 0) && (*(int *)(unaff_EDI + 0x14) != 0)) {
    *(int *)(unaff_EDI + 0xa0) = *(int *)(unaff_EDI + 0x14);
  }
  return;
}


// ==== 0x448070 FUN_00448070

void __thiscall FUN_00448070(undefined4 param_1,int param_2)

{
  char cVar1;
  int in_EAX;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  
  pcVar2 = (char *)(in_EAX + 0x68);
  *(undefined4 *)(in_EAX + 0x88) = param_1;
  pcVar4 = pcVar2;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    pcVar4 = pcVar4 + 4;
  }
  iVar3 = 0x1f;
  param_2 = param_2 - (int)pcVar2;
  do {
    cVar1 = pcVar2[param_2];
    iVar3 = iVar3 + -1;
    *pcVar2 = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    pcVar2 = pcVar2 + 1;
  } while (iVar3 != 0);
  return;
}


// ==== 0x4480b0 FUN_004480b0

void FUN_004480b0(char param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0xa0) != 0) {
    uVar1 = *(uint *)(unaff_ESI + 0x88);
    if ((*(byte *)(unaff_ESI + 0xc) & 2) != 0) {
      uVar1 = uVar1 | 8;
    }
    if (param_1 != '\0') {
      uVar1 = uVar1 | 8;
    }
    uVar2 = FUN_00565b60(*(int *)(unaff_ESI + 0xa0),0,0,uVar1);
    *(undefined4 *)(unaff_ESI + 0x9c) = uVar2;
  }
  return;
}


// ==== 0x4480f0 FUN_004480f0

void FUN_004480f0(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x9c) != 0) {
    FUN_00565ce0();
    *(undefined4 *)(unaff_ESI + 0x9c) = 0;
  }
  return;
}


// ==== 0x448110 ResourceFile::BeginLoading

/* [canon] assets high (hopper) docs/re/assets.md */

void __fastcall ResourceFile__BeginLoading(undefined4 param_1,int param_2)

{
  undefined4 in_EAX;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined4 *)(param_2 + 0x98) = param_1;
  *(undefined4 *)(param_2 + 0x94) = in_EAX;
  DAT_007360e8 = DAT_007360e8 + 1;
  if (*(int *)(param_2 + 0x9c) == 0) {
    if (*(int *)(param_2 + 0xa0) != 0) {
      uVar3 = *(uint *)(param_2 + 0x88);
      if ((*(uint *)(param_2 + 0xc) & 2) != 0) {
        uVar3 = uVar3 | 8;
      }
      if ((*(uint *)(param_2 + 0xc) >> 3 & 1) != 0) {
        uVar3 = uVar3 | 8;
      }
      uVar1 = FUN_00565b60(*(int *)(param_2 + 0xa0),0,0,uVar3);
      *(undefined4 *)(param_2 + 0x9c) = uVar1;
    }
  }
  if (*(int *)(param_2 + 0xa0) != 0) {
    *(int *)(param_2 + 0x8c) = *(int *)(param_2 + 0x8c) + 1;
    FUN_0058aba0(*(undefined4 *)(param_2 + 0x9c),param_2 + 0x18,*(undefined4 *)(param_2 + 0x10),
                 *(int *)(param_2 + 0xa0),ResourceFile__OnReadDone,param_2);
    uVar3 = *(uint *)(param_2 + 0xc);
    iVar2 = FUN_0058ab00();
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x4c) = 5;
      *(undefined4 *)(iVar2 + 0x48) = 0x2000000;
      *(uint *)(iVar2 + 0x50) = uVar3 & 0x20;
    }
  }
  return;
}


// ==== 0x4481d0 ResourceFile::UnloadChunks

/* [canon] assets high (hopper) docs/re/assets.md */

void ResourceFile__UnloadChunks(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x9c) != 0) {
    if (*(int *)(unaff_ESI + 0xa0) != 0) {
      bChunkLoader__UnloadChunks
                (*(int *)(unaff_ESI + 0x9c),&PTR_PaddingChunk__Loader_007008a0,0x2f,unaff_ESI + 0x18
                );
    }
    if (*(int *)(unaff_ESI + 0x9c) != 0) {
      FUN_00565ce0();
      *(undefined4 *)(unaff_ESI + 0x9c) = 0;
    }
    FUN_00447ee0();
    return;
  }
  return;
}


// ==== 0x448220 ResourceFile::FinishLoading

/* [canon] assets high (hopper) docs/re/assets.md */

void ResourceFile__FinishLoading(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  
  if ((*(int *)(in_EAX + 0x90) == 0) && (*(int *)(in_EAX + 0x8c) == 0)) {
    if (((*(byte *)(in_EAX + 0xc) & 8) != 0) && (iVar1 = *(int *)(in_EAX + 0x9c), iVar1 != 0)) {
      iVar2 = IsCompressedBuffer();
      if (iVar2 != 0) {
        iVar1 = *(int *)(iVar1 + 8);
        *(int *)(in_EAX + 0xa0) = iVar1;
        *(undefined4 *)(in_EAX + 0x9c) = 0;
        if (iVar1 != 0) {
          FUN_004480b0(0);
          DecompressBuffer();
        }
        FUN_00565ce0();
      }
    }
    LoadResourceChunks((int *)(in_EAX + 0x9c),(undefined4 *)(in_EAX + 0xa0),
                       *(undefined4 *)(in_EAX + 0x88),in_EAX + 0x68);
    if ((*(byte *)(in_EAX + 0xc) & 4) != 0) {
      if (*(int *)(in_EAX + 0x9c) != 0) {
        FUN_004480f0();
      }
      *(undefined4 *)(in_EAX + 0xa0) = 0;
    }
    FUN_00447ee0();
    *(undefined4 *)(in_EAX + 0x90) = 1;
  }
  return;
}


// ==== 0x4482e0 ResourceFile::OnReadDone

/* [canon] assets high (hopper) docs/re/assets.md */

void ResourceFile__OnReadDone(int param_1)

{
  *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + -1;
  return;
}


// ==== 0x4482f0 CreateResourceFile

/* [canon] assets high (hopper+ghidra) docs/re/assets.md */

void CreateResourceFile(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 in_stack_00000014;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686648;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_00567160();
  puVar3 = (undefined4 *)0x0;
  local_4 = 0;
  if (iVar2 != 0) {
    puVar3 = (undefined4 *)ResourceFile__ResourceFile(param_1,in_stack_00000014);
  }
  *DAT_0077a928 = puVar3;
  puVar1 = puVar3;
  puVar3[1] = DAT_0077a928;
  DAT_0077a928 = puVar1;
  *puVar3 = &DAT_0077a924;
  ExceptionList = local_c;
  return;
}


// ==== 0x448370 UnloadResourceFile

/* [canon] assets high (hopper+ghidra) docs/re/assets.md */

void UnloadResourceFile(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *in_EAX;
  
  iVar1 = in_EAX[0x24];
  while (iVar1 == 0) {
    ServiceResourceLoading();
    iVar1 = in_EAX[0x24];
  }
  iVar1 = *in_EAX;
  piVar2 = (int *)in_EAX[1];
  *piVar2 = iVar1;
  *(int **)(iVar1 + 4) = piVar2;
  ResourceFile__UnloadChunks();
  iVar3 = DAT_007360f8;
  iVar1 = *(int *)(DAT_007360f8 + 0x18);
  *in_EAX = *(int *)(DAT_007360f8 + 0x10);
  *(int **)(iVar3 + 0x10) = in_EAX;
  *(int *)(iVar3 + 0x18) = iVar1 + -1;
  return;
}


// ==== 0x4483c0 ServiceResourceLoading

/* [canon] assets high (hopper+ghidra) docs/re/assets.md */

int ServiceResourceLoading(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  AsyncReadQueue__Pump();
  puVar1 = DAT_0077a924;
  if (DAT_007360e8 != 0) {
    puVar2 = (undefined4 *)NullUpdate_ret();
    for (; puVar1 != puVar2; puVar1 = (undefined4 *)*puVar1) {
      if (puVar1[0x24] == 0) {
        ResourceFile__FinishLoading();
        if (puVar1[0x24] != 0) {
          DAT_007360e8 = DAT_007360e8 + -1;
          if ((code *)puVar1[0x25] != (code *)0x0) {
            (*(code *)puVar1[0x25])(puVar1[0x26]);
          }
        }
        return DAT_007360e8;
      }
    }
  }
  return 0;
}


// ==== 0x448440 FindResourceFile

/* [canon] assets high (hopper+ghidra) docs/re/assets.md */

int FindResourceFile(char *param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  iVar3 = DAT_0077a928;
  iVar4 = NullUpdate_ret();
  do {
    if (iVar3 == iVar4) {
      return 0;
    }
    pcVar5 = param_1;
    do {
      cVar1 = pcVar5[(iVar3 - (int)param_1) + 0x18];
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      if ((cVar1 == '\0') || (cVar2 == '\0')) break;
    } while (cVar1 == cVar2);
    if (cVar1 == cVar2) {
      return iVar3;
    }
    iVar3 = *(int *)(iVar3 + 4);
  } while( true );
}


// ==== 0x4484b0 FUN_004484b0

void FUN_004484b0(void)

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
    ResourceFile__UnloadChunks();
    iVar4 = DAT_007360f8;
    iVar2 = *(int *)(DAT_007360f8 + 0x18);
    *piVar1 = *(int *)(DAT_007360f8 + 0x10);
    *(int *)(iVar4 + 0x18) = iVar2 + -1;
    *(int **)(iVar4 + 0x10) = piVar1;
    piVar1 = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x4484f0 FUN_004484f0

void FUN_004484f0(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = 0;
  DAT_00736174 = DAT_00736168;
  if (0 < DAT_0073616c) {
    do {
      if (*(short *)(DAT_00736174 + 0x6c) == unaff_ESI) {
        return;
      }
      iVar1 = iVar1 + 1;
      DAT_00736174 = DAT_00736174 + 0xfc;
    } while (iVar1 < DAT_0073616c);
  }
  DAT_00736174 = 0;
  return;
}


// ==== 0x448530 GameFlow::SetNextUnloadingFrontEnd

/* [canon] canon high (hopper+capstone) docs/re/gameflow.md */

void GameFlow__SetNextUnloadingFrontEnd(void)

{
  int *in_EAX;
  
  if (*in_EAX != 0) {
    *in_EAX = 0;
  }
  in_EAX[2] = (int)"UnloadingFrontEnd";
  *in_EAX = (int)GameFlow__UnloadingFrontEnd;
  if ((char)in_EAX[5] != '\0') {
    *(undefined1 *)(in_EAX + 5) = 0;
  }
  return;
}


// ==== 0x448560 GameFlow::SetNextLoadingTrackCommon

/* [canon] canon high (hopper+capstone) docs/re/gameflow.md */

void GameFlow__SetNextLoadingTrackCommon(void)

{
  int *in_EAX;
  
  if (*in_EAX != 0) {
    *in_EAX = 0;
  }
  in_EAX[2] = (int)"LoadingTrackCommon";
  *in_EAX = (int)GameFlow__LoadingTrackCommon;
  if ((char)in_EAX[5] != '\0') {
    *(undefined1 *)(in_EAX + 5) = 0;
  }
  return;
}


// ==== 0x448590 FUN_00448590

void FUN_00448590(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char local_1c [28];
  
  iVar4 = 0;
  do {
    if ((&DAT_007360d0)[iVar4] != 0) {
      if ((float)(&DAT_0072cbd8)[iVar4] == 0.0) {
        FUN_00585fa0();
      }
      if (iVar4 == 3) {
        iVar3 = 0x1a;
        pcVar2 = local_1c;
        do {
          cVar1 = pcVar2[(int)PTR_s_Change_Unknown_by_Unknown_006f21a8 - (int)local_1c];
          iVar3 = iVar3 + -1;
          *pcVar2 = cVar1;
          if (cVar1 == '\0') break;
          pcVar2 = pcVar2 + 1;
        } while (iVar3 != 0);
      }
    }
    iVar4 = iVar4 + 1;
    if (3 < iVar4) {
      return;
    }
  } while( true );
}


// ==== 0x448600 GameFlow::LoadGlobalA

/* [canon] assets high (hopper) docs/re/assets.md */

void GameFlow__LoadGlobalA(void)

{
  CreateResourceFile("GLOBAL\\GLOBALA.BUN",1,0,0,0);
  ResourceFile__BeginLoading();
  while (DAT_007360e8 != 0) {
    ServiceResourceLoading();
  }
  FUN_0059f660();
  return;
}


// ==== 0x448650 GameFlow::LoadGlobalB

/* [canon] assets high (hopper) docs/re/assets.md */

void GameFlow__LoadGlobalB(void)

{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  char *pcVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 local_4;
  
  iVar4 = CreateResourceFile("GLOBAL\\GLOBALB.LZC",1,9,0,0);
  ResourceFile__BeginLoading();
  pcVar5 = (char *)(iVar4 + 0x18);
  iVar4 = 0x27;
  iVar7 = (int)"GLOBAL\\GLOBALB.BUN" - (int)pcVar5;
  do {
    cVar1 = pcVar5[iVar7];
    iVar4 = iVar4 + -1;
    *pcVar5 = cVar1;
    if (cVar1 == '\0') break;
    pcVar5 = pcVar5 + 1;
  } while (iVar4 != 0);
  CreateResourceFile(PTR_s_CARS_EXHAUST_GEOMETRY_BIN_00700794,1,0,0,0);
  ResourceFile__BeginLoading();
  CreateResourceFile(PTR_s_CARS_BRAKES_GEOMETRY_BIN_00700798,1,0,0,0);
  ResourceFile__BeginLoading();
  CreateResourceFile(PTR_s_CARS_BRAKES_TEXTURES_BIN_0070079c,1,0,0,0);
  ResourceFile__BeginLoading();
  CreateResourceFile(PTR_s_CARS_PLATES_GEOMETRY_BIN_007007a0,1,0,0,0);
  ResourceFile__BeginLoading();
  CreateResourceFile(PTR_s_CARS_PLATES_TEXTURES_BIN_007007a4,1,0,0,0);
  ResourceFile__BeginLoading();
  while (DAT_007360e8 != 0) {
    ServiceResourceLoading();
  }
  FUN_0053eed0(&DAT_00740420,PTR_s_GLOBAL_DYNTEX_BIN_007007b0,0,0,0);
  puVar3 = PTR_s_GLOBAL_DYNTEX_BIN_007007b0;
  iVar4 = ResourceFileList_IsLoadedByName(&DAT_00740420,PTR_s_GLOBAL_DYNTEX_BIN_007007b0);
  while (iVar4 != 0) {
    ServiceResourceLoading();
    iVar4 = ResourceFileList_IsLoadedByName(&DAT_00740420,puVar3);
  }
  EAXSound__ChangeLanguage();
  iVar7 = Texture_FindByHash(0xab0e817d,0,0);
  iVar4 = DAT_0073578c;
  if (iVar7 == 0) {
    local_4 = 0xab0e817d;
    FUN_0053e9e0(&DAT_00740420,&local_4,1,0,0,0);
    iVar4 = DAT_0073578c;
  }
  while (DAT_0073578c = iVar4, DAT_007360e8 != 0) {
    ServiceResourceLoading();
    iVar4 = DAT_0073578c;
  }
  if (iVar4 != 0) {
    iVar2 = *(int *)(iVar4 + 8);
    iVar7 = iVar2 + 0xdc;
    if ((iVar7 == 0) || (iVar7 = FUN_004fd1e0(iVar7), iVar7 == 0)) {
      cFEng__PushPackage(iVar2,"PC_Loading.fng",0x10,0);
      iVar4 = DAT_0073578c;
    }
    if (((iVar4 != 0) && (iVar4 = FEPackageList__FindByName(&DAT_00746104), iVar4 != 0)) &&
       (*(int *)(iVar4 + 0x18) != 0)) {
      *(undefined1 *)(*(int *)(iVar4 + 0x18) + 0x15) = 1;
    }
  }
  iVar4 = FEPackageList__FindByName(&DAT_00746104);
  if (iVar4 != 0) {
    *(undefined2 *)(iVar4 + 0x1c) = 1;
  }
  if (DAT_0073578c != 0) {
    iVar7 = *(int *)(DAT_0073578c + 8);
    iVar4 = iVar7 + 0xdc;
    if ((iVar4 == 0) || (iVar4 = FUN_004fd1e0(iVar4), iVar4 == 0)) {
      cFEng__PushPackage(iVar7,"Chyron.fng",0x10,0);
    }
  }
  iVar4 = FEPackageList__FindByName(&DAT_00746104);
  if (iVar4 != 0) {
    *(undefined2 *)(iVar4 + 0x1c) = 1;
  }
  if (DAT_0073578c != 0) {
    iVar4 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar4 != 0) && (*(int *)(iVar4 + 0x18) != 0)) {
      *(undefined1 *)(*(int *)(iVar4 + 0x18) + 0x15) = 1;
    }
    iVar4 = DAT_0073578c;
    if (((DAT_0073578c != 0) && (iVar7 = FEPackageList__FindByName(&DAT_00746104), iVar7 != 0)) &&
       (*(int *)(iVar7 + 0x18) != 0)) {
      cFEng__PopPackage(*(undefined4 *)(iVar4 + 8),*(int *)(iVar7 + 0x18));
    }
  }
  RenderFrame();
  FUN_0053eed0(&DAT_00740420,PTR_s_GLOBAL_HUDTEX_BIN_007007b4,0,0,0);
  FUN_0053eed0(&DAT_00740420,PTR_s_CARS_TEXTURES_BIN_007007a8,0,0,0);
  FUN_0053eed0(&DAT_00740420,PTR_s_CARS_WHEELS_TEXTURES_BIN_007007ac,0,0,0);
  FUN_0053eed0(&DAT_00743c20,PTR_s_CARS_WHEELS_GEOMETRY_BIN_00700790,0,0,0);
  while (puVar6 = DAT_00740438, (undefined4 **)DAT_00740438 != &DAT_00740438) {
    while ((puVar6[0x24] != 0 && ((int)puVar6[0x29] < 1))) {
      puVar6 = (undefined4 *)*puVar6;
      if ((undefined4 **)puVar6 == &DAT_00740438) goto LAB_004489b0;
    }
    ServiceResourceLoading();
  }
LAB_004489b0:
  do {
    puVar6 = DAT_00743c38;
    if ((undefined4 **)DAT_00743c38 == &DAT_00743c38) {
joined_r0x004489e4:
      while (DAT_007360e8 != 0) {
        ServiceResourceLoading();
      }
      return;
    }
    while ((puVar6[0x24] != 0 && ((int)puVar6[0x29] < 1))) {
      puVar6 = (undefined4 *)*puVar6;
      if ((undefined4 **)puVar6 == &DAT_00743c38) goto joined_r0x004489e4;
    }
    ServiceResourceLoading();
  } while( true );
}


// ==== 0x448a10 GameFlow::EndLoadingFrontEnd

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (hopper+capstone) docs/re/gameflow.md */

void GameFlow__EndLoadingFrontEnd(void)

{
  _DAT_0077a90c = "EndGameFlowLoadingFrontEnd";
  DAT_0077a904 = GameFlow__EnterFrontEnd;
  if (DAT_0077a918 != '\0') {
    DAT_0077a918 = '\0';
  }
  return;
}


// ==== 0x448a40 GameFlow::LoadingFrontEndPart3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (hopper+capstone) docs/re/gameflow.md */

void GameFlow__LoadingFrontEndPart3(void)

{
  if (DAT_0077a904 != (code *)0x0) {
    DAT_0077a904 = (code *)0x0;
  }
  DAT_0077a918 = 1;
  _DAT_0077a91c = "GameFlowLoadingFrontEndPart3";
  if (DAT_006f1dd8 == 1) {
    EAXSound__LoadFrontEndSoundBanks(GameFlow__EndLoadingFrontEnd,0);
    FUN_00536690();
    return;
  }
  DAT_0077a918 = 0;
  DAT_0077a904 = GameFlow__EnterFrontEnd;
  _DAT_0077a90c = "EndGameFlowLoadingFrontEnd";
  return;
}


// ==== 0x448ac0 GameFlow::LoadingFrontEndPart2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon med (capstone) docs/re/gameflow.md */

void GameFlow__LoadingFrontEndPart2(void)

{
  if (DAT_0077a904 != 0) {
    DAT_0077a904 = 0;
  }
  DAT_0077a918 = 1;
  _DAT_0077a91c = "GameFlowLoadingFrontEndPart2";
  CreateResourceFile("FRONTEND\\ROAD_SEGMENT.BIN",2,1,0,0);
  ResourceFile__BeginLoading();
  return;
}


// ==== 0x448b10 GameFlow::LoadingFrontEndPart1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets med (hopper) docs/re/assets.md */

void GameFlow__LoadingFrontEndPart1(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  float10 fVar5;
  
  DAT_0077a920 = 1;
  _DAT_007360dc = &DAT_006c9d84;
  fVar5 = (float10)FUN_00585fa0();
  _DAT_0072cbd4 = (float)fVar5;
  _DAT_0072cbe4 = 0;
  FUN_00431df0();
  if (DAT_007301d4 == 0) {
    _DAT_007360c0 = 0;
  }
  else {
    _DAT_007360c0 = bMemoryPool_TotalAllocated();
  }
  _DAT_007360c4 = -(uint)(DAT_007301d4 != 0) & 0x6300000;
  _DAT_007360c8 = DAT_007349a4;
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar2 == 0) || (*(int *)(iVar2 + 0x18) == 0)) {
    FEManager__ShowPackage();
  }
  FUN_0059f7c0(1,1,0,0);
  CreateResourceFile("FRONTEND\\FRONTA.BUN",2,0,0,0);
  ResourceFile__BeginLoading();
  if (DAT_0077a904 != 0) {
    DAT_0077a904 = 0;
  }
  DAT_0077a918 = 1;
  _DAT_0077a91c = "GameFlowLoadingFrontEndPart1";
  iVar2 = CreateResourceFile("FRONTEND\\FRONTB.LZC",2,9,0,0);
  ResourceFile__BeginLoading();
  pcVar3 = (char *)(iVar2 + 0x18);
  iVar2 = 0x27;
  iVar4 = (int)"FRONTEND\\FRONTB.BUN" - (int)pcVar3;
  do {
    cVar1 = pcVar3[iVar4];
    iVar2 = iVar2 + -1;
    *pcVar3 = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    pcVar3 = pcVar3 + 1;
  } while (iVar2 != 0);
  return;
}


// ==== 0x448c40 GameFlow::EnterFrontEnd

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (hopper+capstone) docs/re/gameflow.md */

void GameFlow__EnterFrontEnd(void)

{
  int iVar1;
  int iVar2;
  
  DAT_00735564 = 0;
  if ((DAT_00735568 != 0) || (DAT_0073556c != 0)) {
    RVM_LookupTextures();
    DAT_00735568 = 0;
    DAT_0073556c = 0;
    _DAT_00735570 = 0;
  }
  _DAT_007360dc = 0;
  FUN_005697b0();
  FUN_004af4a0();
  iVar2 = DAT_0073578c;
  if (DAT_0073578c != 0) {
    iVar1 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) != 0)) {
      cFEng__PopPackage(*(undefined4 *)(iVar2 + 8),*(int *)(iVar1 + 0x18));
    }
  }
  if (DAT_00707018 != 0) {
    FUN_004de440();
    DAT_00707018 = 0;
  }
  iVar2 = bStrICmp();
  if (iVar2 != 0) {
    FEManager__ShowPackage();
  }
  DAT_0077a920 = 3;
  if (DAT_007363b4 != '\0') {
    ResumeThread(DAT_0070f460);
  }
  return;
}


// ==== 0x448d10 GameFlow::UnloadingFrontEnd

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (hopper+capstone) docs/re/gameflow.md */

void GameFlow__UnloadingFrontEnd(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  DAT_0077a920 = 2;
  if (DAT_0073578c != 0) {
    FUN_004f40c0(0);
    FEManager__RemoveJoyHandlers(DAT_0073578c);
  }
  GetGarageCarLoader();
  FUN_004af030();
  GetGarageCarLoader();
  FUN_004af030();
  FUN_0058c7c0();
  if (DAT_0073450c != 0) goto LAB_00448d91;
  if ((undefined4 **)DAT_00737bbc != &DAT_00737bbc) {
    while ((DAT_0073450c != 0 || ((undefined4 **)DAT_00737bbc != &DAT_00737bbc))) {
LAB_00448d91:
      AsyncReadQueue__Pump();
    }
  }
  SlotPool__Destroy();
  if (DAT_006f1dd8 == 1) {
    EAXSound__UnloadFrontEndSoundBanks(DAT_007356a8);
  }
  piVar4 = (int *)NullUpdate_ret();
  while (piVar6 = DAT_0077a928, DAT_0077a928 != piVar4) {
    while (piVar6[2] != 2) {
      piVar2 = piVar6 + 1;
      piVar6 = (int *)*piVar2;
      if ((int *)*piVar2 == piVar4) goto LAB_00448df0;
    }
    iVar5 = piVar6[0x24];
    while (iVar5 == 0) {
      ServiceResourceLoading();
      iVar5 = piVar6[0x24];
    }
    iVar5 = *piVar6;
    piVar2 = (int *)piVar6[1];
    *piVar2 = iVar5;
    *(int **)(iVar5 + 4) = piVar2;
    ResourceFile__UnloadChunks();
    iVar3 = DAT_007360f8;
    iVar5 = *(int *)(DAT_007360f8 + 0x18);
    *piVar6 = *(int *)(DAT_007360f8 + 0x10);
    *(int *)(iVar3 + 0x18) = iVar5 + -1;
    *(int **)(iVar3 + 0x10) = piVar6;
  }
LAB_00448df0:
  FUN_0059f7c0(1,0,0,0);
  FUN_00573240(&DAT_0073c17c);
  iVar5 = DAT_0073448c;
  for (puVar1 = DAT_0073d818; DAT_0073448c = iVar5, (undefined4 **)puVar1 != &DAT_0073d818;
      puVar1 = (undefined4 *)*puVar1) {
    FUN_00567000(puVar1);
    iVar5 = DAT_0073448c;
  }
  do {
    if (iVar5 != 0) {
      FUN_0063f0a0(0);
      FUN_00594870();
      iVar5 = DAT_0073448c;
    }
  } while (iVar5 != 0);
  if (DAT_0077a918 != '\0') {
    DAT_0077a918 = '\0';
  }
  DAT_0077a904 = GameFlow__LoadingTrackCommon;
  _DAT_0077a90c = "LoadingTrackCommon";
  if (DAT_007363b4 != '\0') {
    SuspendThread(DAT_0070f460);
  }
  return;
}


// ==== 0x448ee0 GameFlow::BeginLoadingTrackSpecific

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

void GameFlow__BeginLoadingTrackSpecific(void)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  if (DAT_0077a918 != '\0') {
    DAT_0077a918 = '\0';
  }
  FUN_0058c840(&DAT_00737b58);
  if (DAT_007301d4 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = bMemoryPool_TotalAllocated();
    if (DAT_007301d4 != 0) {
      iVar1 = FUN_00565a40(DAT_007301d4);
      goto LAB_00448f08;
    }
  }
  iVar1 = 0;
LAB_00448f08:
  DAT_0072cbe8 = DAT_0072cbe8 + (iVar1 - iVar2);
  fVar3 = (float10)FUN_00585fa0();
  DAT_0072cbd8 = (float)fVar3;
  _DAT_0077a90c = "BeginGameFlowLoadingTrackSpecific";
  DAT_0077a904 = GameFlow__LoadingTrackSpecific;
  if (DAT_0077a918 != '\0') {
    DAT_0077a918 = '\0';
  }
  return;
}


// ==== 0x448f70 GameFlow_CreateRides

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] traffic med (H) docs/re/traffic.md */

void GameFlow_CreateRides(void)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  int iStack_4;
  
  if (DAT_0077a918 != '\0') {
    DAT_0077a918 = '\0';
  }
  DAT_007360d0 = "Cars ";
  fVar10 = (float10)FUN_00585fa0();
  _DAT_0072cbc8 = (float)fVar10;
  _DAT_00737b68 = (uint)(DAT_0078a320 == 2);
  iVar7 = 0;
  DAT_0072cbd8 = 0;
  _DAT_00737b60 = 0;
  DAT_00737b64 = 0;
  _DAT_00737b70 = 0;
  iVar9 = DAT_0078a41c;
  if (0 < DAT_0078a41c) {
    iStack_4 = 0;
    do {
      iVar8 = iStack_4 + DAT_0078a418;
      if (*(char *)(iVar8 + 0x16) == '\0') {
        uVar2 = *(undefined1 *)(iVar8 + 0x17);
        if (*(int *)(*(int *)(iVar8 + 0x10) * 0xc90 + 0xc54 + DAT_00734588) == 2) {
          *(undefined1 *)(iVar8 + 0x17) = 0xff;
        }
        iVar9 = *(int *)(iVar8 + 4);
        piVar6 = (int *)CarLoader__AllocateRideInfo(&DAT_00737b58,iVar8 + 0x10);
        iVar3 = *piVar6;
        piVar4 = (int *)piVar6[1];
        *piVar4 = iVar3;
        *(int **)(iVar3 + 4) = piVar4;
        piVar4 = DAT_00737ba4;
        if (iVar9 == 1) {
          piVar1 = DAT_00737ba4 + 1;
          DAT_00737ba4 = piVar6;
          *piVar1 = (int)piVar6;
          piVar6[1] = (int)&DAT_00737ba4;
          *piVar6 = (int)piVar4;
        }
        else {
          *DAT_00737ba8 = (int)piVar6;
          piVar4 = piVar6;
          piVar6[1] = (int)DAT_00737ba8;
          DAT_00737ba8 = piVar4;
          *piVar6 = (int)&DAT_00737ba4;
        }
        *(undefined1 *)(iVar8 + 0x14) = 0;
        *(undefined1 *)(iVar8 + 0x17) = uVar2;
        iVar9 = DAT_0078a41c;
      }
      iVar7 = iVar7 + 1;
      iStack_4 = iStack_4 + 0x750;
    } while (iVar7 < iVar9);
  }
  iVar7 = 0;
  if (0 < iVar9) {
    iVar8 = 0;
    do {
      iVar3 = iVar8 + DAT_0078a418;
      if (*(char *)(iVar3 + 0x16) != '\0') {
        piVar6 = (int *)CarLoader__AllocateRideInfo(&DAT_00737b58,iVar3 + 0x10);
        iVar9 = *piVar6;
        piVar4 = (int *)piVar6[1];
        *piVar4 = iVar9;
        *(int **)(iVar9 + 4) = piVar4;
        *DAT_00737ba8 = (int)piVar6;
        piVar4 = piVar6;
        piVar6[1] = (int)DAT_00737ba8;
        DAT_00737ba8 = piVar4;
        *piVar6 = (int)&DAT_00737ba4;
        *(undefined1 *)(iVar3 + 0x14) = 0;
        iVar9 = DAT_0078a41c;
      }
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 0x750;
    } while (iVar7 < iVar9);
  }
  iVar7 = DAT_007301d4;
  iVar9 = 0;
  if (DAT_0077a904 != 0) {
    DAT_0077a904 = 0;
  }
  DAT_0077a918 = 1;
  _DAT_0077a91c = "GameFlowLoadingTrackCommonPart2";
  if (DAT_007301d4 != 0) {
    iVar8 = DAT_007301d4 + 0x3c;
    CriticalSection__Enter(iVar8);
    iVar9 = 0;
    for (puVar5 = *(undefined4 **)(iVar7 + 4); puVar5 != (undefined4 *)(iVar7 + 4);
        puVar5 = (undefined4 *)*puVar5) {
      iVar9 = iVar9 + puVar5[2];
    }
    CriticalSection__Leave(iVar8);
  }
  DAT_0072cbe8 = iVar9;
  if (DAT_00737b64 == 0) {
    FUN_0058c840(&DAT_00737b58);
  }
  _DAT_00737b58 = GameFlow__BeginLoadingTrackSpecific;
  _DAT_00737b5c = 0;
  if (DAT_00737b6c != 0) {
    return;
  }
  FUN_0058cbb0();
  return;
}


// ==== 0x4491a0 GameFlow::QueueRaceCars

/* [canon] canon med (ghidra+hopper) docs/re/gameflow.md */

void GameFlow__QueueRaceCars(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  undefined1 local_8 [8];
  
  iVar2 = (int)DAT_0078a3f5;
  if (-1 < DAT_0078a410) {
    pcVar1 = (char *)RaceStatus__FindEntrantById();
    if ((pcVar1 != (char *)0x0) && (*pcVar1 < '\x01')) goto LAB_004491e9;
  }
  if (DAT_0078a414 < 0) {
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = (char *)RaceStatus__FindEntrantById();
  }
LAB_004491e9:
  if (pcVar1[0x434] == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  if ((pcVar1 != (char *)0x0) && (*pcVar1 < '\x01')) {
    FUN_00432a30(*(undefined4 *)(pcVar1 + 0x10),iVar2,local_8);
    FUN_0053e9e0(&DAT_00740420,local_8,2,param_1,0,0);
  }
  return;
}


// ==== 0x449250 GameFlow::LoadingTrackCommon

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

void GameFlow__LoadingTrackCommon(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  float10 fVar5;
  
  DAT_0077a920 = 4;
  if (DAT_007301d4 == 0) {
    _DAT_007360c0 = 0;
  }
  else {
    _DAT_007360c0 = bMemoryPool_TotalAllocated();
  }
  _DAT_007360c4 = -(uint)(DAT_007301d4 != 0) & 0x6300000;
  _DAT_007360c8 = DAT_007349a4;
  DAT_00735564 = 1;
  _DAT_007360dc = "Total";
  fVar5 = (float10)FUN_00585fa0();
  _DAT_0072cbd4 = (float)fVar5;
  _DAT_0072cbe4 = 0;
  if (DAT_007183c8 == 0) {
    FEManager__ShowPackage();
  }
  CreateResourceFile("GLOBAL\\INGAMEA.BUN",3,0,0,0);
  ResourceFile__BeginLoading();
  _DAT_007360e0 = 1;
  while (DAT_007360e8 != 0) {
    ServiceResourceLoading();
  }
  FUN_0059f7c0(1,0,1,0);
  if (DAT_0077a904 != 0) {
    DAT_0077a904 = 0;
  }
  DAT_0077a918 = 1;
  _DAT_0077a91c = "GameFlowLoadingTrackCommonPart1";
  iVar2 = CreateResourceFile("GLOBAL\\INGAMEB.LZC",3,9,0,0);
  ResourceFile__BeginLoading();
  pcVar3 = (char *)(iVar2 + 0x18);
  iVar2 = 0x27;
  iVar4 = (int)"GLOBAL\\INGAMEB.BUN" - (int)pcVar3;
  do {
    cVar1 = pcVar3[iVar4];
    iVar2 = iVar2 + -1;
    *pcVar3 = cVar1;
    if (cVar1 == '\0') break;
    pcVar3 = pcVar3 + 1;
  } while (iVar2 != 0);
  FUN_00408760();
  return;
}


// ==== 0x4493a0 GameFlow::UnloadingTrackCommon

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (hopper+capstone) docs/re/gameflow.md */

void GameFlow__UnloadingTrackCommon(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  DAT_0077a920 = 8;
  piVar4 = (int *)NullUpdate_ret();
  while (piVar5 = DAT_0077a928, DAT_0077a928 != piVar4) {
    while (piVar5[2] != 3) {
      piVar2 = piVar5 + 1;
      piVar5 = (int *)*piVar2;
      if ((int *)*piVar2 == piVar4) goto LAB_004493dc;
    }
    iVar1 = piVar5[0x24];
    while (iVar1 == 0) {
      ServiceResourceLoading();
      iVar1 = piVar5[0x24];
    }
    iVar1 = *piVar5;
    piVar2 = (int *)piVar5[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
    ResourceFile__UnloadChunks();
    iVar3 = DAT_007360f8;
    iVar1 = *(int *)(DAT_007360f8 + 0x18);
    *piVar5 = *(int *)(DAT_007360f8 + 0x10);
    *(int *)(iVar3 + 0x18) = iVar1 + -1;
    *(int **)(iVar3 + 0x10) = piVar5;
  }
LAB_004493dc:
  FUN_0059f7c0(1,0,0,0);
  FUN_0058c7c0();
  DAT_0072cbe8 = 0;
  if (((DAT_00777b4c == 1) || (((DAT_00777b4c == 2 || (DAT_00777b4c == 4)) && (DAT_00777cc8 == 4))))
     && ((DAT_00778898 == 0 || (DAT_00778898 == 3)))) {
    if (DAT_0077a918 != '\0') {
      DAT_0077a918 = '\0';
    }
    DAT_0077a904 = GameFlow__LoadingTrackCommon;
    _DAT_0077a90c = "LoadingTrackCommon";
  }
  else {
    if (DAT_0077a918 != '\0') {
      DAT_0077a918 = '\0';
    }
    DAT_0077a904 = GameFlow__LoadingFrontEndPart1;
    _DAT_0077a90c = "LoadingFrontEnd";
  }
  if (DAT_00700e70 != 1) {
    FUN_004086b0(800);
    Device_HandleLost();
    return;
  }
  return;
}


// ==== 0x4494f0 GameFlow::EndLoadingTrackSpecific

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (hopper+capstone) docs/re/gameflow.md */

void GameFlow__EndLoadingTrackSpecific(void)

{
  _DAT_0077a90c = "EndGameFlowLoadingTrackSpecific";
  DAT_0077a904 = GameFlow__TrackWorldInit;
  if (DAT_0077a918 != '\0') {
    DAT_0077a918 = '\0';
  }
  return;
}


// ==== 0x449590 GameFlow::LoadingTrackSpecificCarsDone

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon med (capstone) docs/re/gameflow.md */

void GameFlow__LoadingTrackSpecificCarsDone(void)

{
  float10 fVar1;
  undefined1 auStack_20 [28];
  undefined4 uStack_4;
  
  if (DAT_0077a918 != '\0') {
    DAT_0077a918 = '\0';
  }
  uStack_4 = 0x4495a5;
  fVar1 = (float10)FUN_00585fa0();
  DAT_0072cbdc = (float)fVar1;
  if (DAT_0077a904 != 0) {
    DAT_0077a904 = 0;
  }
  DAT_0077a918 = 1;
  _DAT_0077a91c = "GameFlowLoadingTrackSpecificPart6";
  FUN_00565da0("TRACKS\\TEX%dTRACK.BIN",DAT_0078a2f0);
  CreateResourceFile(auStack_20,4,1,0,0);
  ResourceFile__BeginLoading();
  return;
}


// ==== 0x4495c0 GameFlow::LoadingTrackSpecificPart3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

void GameFlow__LoadingTrackSpecificPart3(void)

{
  code *pcStack00000004;
  
  if (DAT_0077a904 != 0) {
    DAT_0077a904 = 0;
  }
  DAT_0077a918 = 1;
  _DAT_0077a91c = "GameFlowLoadingTrackSpecificPart3";
  pcStack00000004 = GameFlow__LoadingTrackSpecificCarsDone;
  GameFlow__QueueRaceCars();
  return;
}


// ==== 0x4496a0 GameFlow::SetStreamPaths

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] track med (hopper) docs/re/track.md */

void GameFlow__SetStreamPaths(void)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  undefined1 auStack_80 [112];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  
  if (DAT_0077a918 != '\0') {
    DAT_0077a918 = '\0';
  }
  FUN_00565da0("TRACKS\\TRACKB%d.BUN",DAT_0078a2f0);
  iVar2 = FindResourceFile(auStack_80);
  iVar1 = *(int *)(iVar2 + 0x9c);
  _DAT_0072cbec = 0;
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar2 + 0xa0) + iVar1;
    for (; iVar1 != iVar2; iVar1 = iVar1 + 8 + *(int *)(iVar1 + 4)) {
      _DAT_0072cbec = _DAT_0072cbec + *(int *)(iVar1 + 4);
    }
  }
  FUN_00565da0("TRACKS\\STREAM%s.BUN",DAT_00736174 + 0x40);
  FUN_00565da0("TRACKS\\STREAM%s_%d.BUN",DAT_00736174 + 0x40,(int)*(short *)(DAT_00736174 + 0x6c));
  StreamSections__SetTrack();
  if (DAT_0073c17c != '\0') {
    pcStack_8 = (code *)0x449614;
    FUN_005731c0();
  }
  DAT_007360d4 = "Sound";
  fVar3 = (float10)FUN_00585fa0();
  _DAT_0072cbcc = (float)fVar3;
  DAT_0072cbdc = 0;
  if (DAT_0077a904 != 0) {
    DAT_0077a904 = 0;
  }
  DAT_0077a918 = 1;
  _DAT_0077a91c = "GameFlowLoadingTrackSpecificPart2";
  if (DAT_006f1dd8 != 1) {
    if (DAT_0077a904 != 0) {
      DAT_0077a904 = 0;
    }
    DAT_0077a918 = 1;
    _DAT_0077a91c = "GameFlowLoadingTrackSpecificPart3";
    pcStack_8 = (code *)0x44969e;
    GameFlow__QueueRaceCars();
    return;
  }
  pcStack_8 = GameFlow__LoadingTrackSpecificPart3;
  uStack_c = DAT_007356a8;
  uStack_10 = 0x449675;
  EAXSound__LoadInGameSoundBanks();
  return;
}


// ==== 0x449760 GameFlow::LoadingTrackSpecific

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (capstone+hopper) docs/re/gameflow.md */

void GameFlow__LoadingTrackSpecific(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char acStack_40 [64];
  
  uVar2 = DAT_0078a2f0;
  DAT_0077a920 = 5;
  if (DAT_00700eb0 == 0) {
    DAT_007364f4 = 2;
  }
  else {
    DAT_007364f4 = (uint)(DAT_00700eb0 == 1);
  }
  FUN_004484f0();
  DAT_00735564 = 1;
  if (DAT_0077a904 != 0) {
    DAT_0077a904 = 0;
  }
  DAT_0077a918 = 1;
  _DAT_0077a91c = "GameFlowLoadingTrackSpecificPart1";
  FUN_00565da0("TRACKS\\TRACKB%d.LZC",uVar2);
  iVar3 = CreateResourceFile(acStack_40,4,9,0,0);
  ResourceFile__BeginLoading();
  FUN_00565da0("TRACKS\\TRACKB%d.BUN",uVar2);
  pcVar4 = (char *)(iVar3 + 0x18);
  iVar5 = 0x27;
  iVar3 = -(int)pcVar4;
  do {
    cVar1 = pcVar4[(int)(acStack_40 + iVar3)];
    iVar5 = iVar5 + -1;
    *pcVar4 = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    pcVar4 = pcVar4 + 1;
  } while (iVar5 != 0);
  return;
}


// ==== 0x449765 GameFlow::LoadingTrackSpecificPart1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (hopper) docs/re/assets.md */

void GameFlow__LoadingTrackSpecificPart1(void)

{
  char cVar1;
  undefined4 uVar2;
  int in_EAX;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char acStack_40 [64];
  
  uVar2 = DAT_0078a2f0;
  DAT_0077a920 = 5;
  if (in_EAX == 0) {
    DAT_007364f4 = 2;
  }
  else {
    DAT_007364f4 = (uint)(in_EAX == 1);
  }
  FUN_004484f0();
  DAT_00735564 = 1;
  if (DAT_0077a904 != 0) {
    DAT_0077a904 = 0;
  }
  DAT_0077a918 = 1;
  _DAT_0077a91c = "GameFlowLoadingTrackSpecificPart1";
  FUN_00565da0("TRACKS\\TRACKB%d.LZC",uVar2);
  iVar3 = CreateResourceFile(acStack_40,4,9,0,0);
  ResourceFile__BeginLoading();
  FUN_00565da0("TRACKS\\TRACKB%d.BUN",uVar2);
  pcVar4 = (char *)(iVar3 + 0x18);
  iVar5 = 0x27;
  iVar3 = -(int)pcVar4;
  do {
    cVar1 = pcVar4[(int)(acStack_40 + iVar3)];
    iVar5 = iVar5 + -1;
    *pcVar4 = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    pcVar4 = pcVar4 + 1;
  } while (iVar5 != 0);
  return;
}


// ==== 0x449840 GameFlow::Racing

/* [canon] canon high (hopper+capstone) docs/re/gameflow.md */

void GameFlow__Racing(void)

{
  char cVar1;
  
  DAT_0077a920 = 6;
  cVar1 = FUN_0043a2e0();
  if (cVar1 != '\0') {
    FUN_0043ae40();
    return;
  }
  return;
}


// ==== 0x449870 GameFlow::TrackWorldInit

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] track med (hopper+ghidra) docs/re/track.md */

void GameFlow__TrackWorldInit(void)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  float10 fVar4;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  iVar1 = DAT_0073578c;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006897c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if ((DAT_007183c8 != 0) && (ExceptionList = &local_c, DAT_0073578c != 0)) {
    ExceptionList = &local_c;
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x18) != 0)) {
      cFEng__PopPackage(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
    }
  }
  DAT_00735564 = 0;
  if ((DAT_00735568 != 0) || (DAT_0073556c != 0)) {
    RVM_LookupTextures();
    DAT_00735568 = 0;
    DAT_0073556c = 0;
    _DAT_00735570 = 0;
  }
  FUN_004655f0();
  FUN_00466970();
  FUN_0046ac40();
  TrackPolygonSlotPool__Init(&DAT_0077b130);
  FUN_00576f80();
  FUN_004764e0();
  FUN_00546590();
  TrackPath__BuildSplines(&DAT_007372b0);
  TrackPath__SetReverse();
  RoadNetwork_PostLoad(DAT_0078a2fc != 1);
  FUN_00591d90();
  DAT_00735ee4 = 0;
  FUN_00455530();
  pvVar3 = _malloc(0xb0);
  local_4 = 1;
  if (pvVar3 == (void *)0x0) {
    DAT_007361f0 = 0;
  }
  else {
    DAT_007361f0 = FUN_00421c70(pvVar3);
  }
  local_4 = 0xffffffff;
  FUN_00480020(&DAT_007789f0);
  StreamSections__ComputePoolSize();
  StreamSections__Init();
  _DAT_007360d8 = "Track";
  fVar4 = (float10)FUN_00585fa0();
  _DAT_0072cbd0 = (float)fVar4;
  _DAT_0072cbe0 = 0;
  _DAT_0077a90c = "GameFlowBeginRacing";
  DAT_0077a904 = GameFlow__Racing;
  if (DAT_0077a918 != '\0') {
    DAT_0077a918 = '\0';
  }
  ExceptionList = local_c;
  return;
}


// ==== 0x449a10 GameFlow::UnloadingTrackSpecific

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] canon high (hopper+capstone) docs/re/gameflow.md */

void GameFlow__UnloadingTrackSpecific(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  void *pvVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  int *piVar9;
  
  DAT_0077a920 = 7;
  cVar5 = FUN_0043a2e0();
  if (cVar5 != '\0') {
    FUN_0043ac10(1);
  }
  DAT_00735564 = 1;
  DAT_00736550 = 1;
  if (DAT_0073578c != 0) {
    iVar1 = *(int *)(DAT_0073578c + 8);
    iVar6 = iVar1 + 0xdc;
    if ((iVar6 == 0) || (iVar6 = FUN_004fd1e0(iVar6), iVar6 == 0)) {
      cFEng__PushPackage(iVar1,"PC_Loading.fng",0x10,0);
    }
  }
  FEManager__Update();
  RenderFrame();
  pvVar4 = DAT_007361f0;
  if (DAT_007361f0 != (void *)0x0) {
    FUN_00421d60(DAT_007361f0);
    _free(pvVar4);
  }
  DAT_007361f0 = (void *)0x0;
  FUN_0053ed20(&DAT_00740420);
  FUN_0053ed20(&DAT_00740420);
  FUN_00455640();
  FUN_00591de0();
  pvVar4 = DAT_007344d0;
  if (DAT_007344d0 != (void *)0x0) {
    FUN_00591a40();
    _free(pvVar4);
    DAT_007344d0 = (void *)0x0;
  }
  FUN_00594ff0();
  DAT_00735518 = 0;
  _DAT_00740400 = 0;
  _DAT_00740404 = 0;
  _DAT_00740408 = 0;
  _DAT_00730138 = 0;
  _DAT_0073013c = 0;
  _DAT_00730140 = 0;
  _DAT_00730144 = 0;
  _DAT_00730148 = 0;
  FUN_005716b0();
  FUN_00476760();
  SlotPool__Destroy();
  SlotPool__Destroy();
  DAT_007306c8 = 0;
  DAT_007306cc = 0;
  FUN_00441320();
  TrackPath__FreeSplines();
  SlotPool__Destroy();
  DAT_00735fe4 = 0;
  FUN_00466bf0();
  SlotPool__Destroy();
  DAT_00736088 = 0;
  StreamSections__Shutdown();
  if (DAT_0077af00 != 0) {
    FUN_00565370(DAT_007301d8);
    DAT_007301d8 = 0;
    FUN_00565ce0();
    DAT_0077af00 = 0;
    _DAT_0077af04 = 0;
  }
  piVar7 = (int *)NullUpdate_ret();
  while (piVar9 = DAT_0077a928, DAT_0077a928 != piVar7) {
    while (piVar9[2] != 4) {
      piVar3 = piVar9 + 1;
      piVar9 = (int *)*piVar3;
      if ((int *)*piVar3 == piVar7) goto LAB_00449c20;
    }
    iVar6 = piVar9[0x24];
    while (iVar6 == 0) {
      ServiceResourceLoading();
      iVar6 = piVar9[0x24];
    }
    iVar6 = *piVar9;
    piVar3 = (int *)piVar9[1];
    *piVar3 = iVar6;
    *(int **)(iVar6 + 4) = piVar3;
    ResourceFile__UnloadChunks();
    iVar1 = DAT_007360f8;
    iVar6 = *(int *)(DAT_007360f8 + 0x18);
    *piVar9 = *(int *)(DAT_007360f8 + 0x10);
    *(int *)(iVar1 + 0x18) = iVar6 + -1;
    *(int **)(iVar1 + 0x10) = piVar9;
  }
LAB_00449c20:
  if (DAT_006f1dd8 == 1) {
    EAXSound__UnLoadInGameSoundBanks();
  }
  FUN_00573240(&DAT_0073c17c);
  FUN_004484f0();
  iVar6 = DAT_0073448c;
  for (puVar2 = DAT_0073d818; DAT_0073448c = iVar6, (undefined4 **)puVar2 != &DAT_0073d818;
      puVar2 = (undefined4 *)*puVar2) {
    FUN_00567000(puVar2);
    iVar6 = DAT_0073448c;
  }
  do {
    if (iVar6 != 0) {
      FUN_0063f0a0(0);
      FUN_00594870();
      iVar6 = DAT_0073448c;
    }
  } while (iVar6 != 0);
  DAT_007183c8 = 0;
  uVar8 = DAT_006f227c;
  if (DAT_0073459c != 0) {
    uVar8 = FUN_0057c5a0(10);
  }
  if (DAT_007345a0 != 0) {
    FUN_0057c3b0(uVar8,0x20,10);
  }
  DAT_006f227c = uVar8;
  if ((DAT_0078a308 == '\0') && (DAT_0078a309 == '\0')) {
    if (DAT_00734440 != 0) {
      FUN_0059e020();
    }
    FUN_0059e380();
  }
  if (DAT_0077a918 != '\0') {
    DAT_0077a918 = '\0';
  }
  DAT_0077a904 = GameFlow__UnloadingTrackCommon;
  _DAT_0077a90c = "BeginGameFlowUnloadingTrackCommon";
  DAT_00736550 = 0;
  return;
}


// ==== 0x449d80 GetLanguageCode

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

undefined1 * GetLanguageCode(void)

{
  switch(DAT_00734998) {
  case 0:
  case 5:
switchD_00449d8a_caseD_0:
    return &DAT_006c9af0;
  case 1:
    break;
  case 2:
    return &DAT_006bc4cc;
  case 3:
    return &DAT_006c9aec;
  case 4:
    return &DAT_006c9ae8;
  default:
switchD_00449d8a_default:
    return (undefined1 *)0x0;
  }
  switch(DAT_006ee6f0) {
  case 0:
    goto switchD_00449d8a_caseD_0;
  case 1:
    return &DAT_006c9ae4;
  case 2:
    return &DAT_006c9ae0;
  case 3:
    return &DAT_006c9adc;
  case 4:
    return &DAT_006c9ad8;
  case 5:
    return &DAT_006c9ad4;
  case 6:
    return &DAT_006c9ad0;
  default:
    goto switchD_00449d8a_default;
  }
}


// ==== 0x449e20 GetCountryCode

/* [canon] canon med (ghidra-canon) docs/re/canon.md */

undefined * GetCountryCode(void)

{
  switch(DAT_00734998) {
  case 0:
    return &DAT_006c9acc;
  case 1:
    switch(DAT_006ee6f0) {
    case 0:
      return &DAT_006c9ac4;
    case 1:
      return &DAT_006c9ae4;
    case 2:
      return &DAT_006c9ae0;
    case 3:
      return &DAT_006c9adc;
    case 4:
      return &DAT_006c9ad8;
    case 5:
      return &DAT_006c9ad4;
    case 6:
      return &DAT_006c9ac0;
    }
    break;
  case 2:
    return &DAT_006c9ac8;
  case 3:
    return &DAT_006bc4c8;
  case 4:
    return &DAT_006bc4c4;
  }
  return (undefined *)0x0;
}


// ==== 0x449ec0 FUN_00449ec0

/* WARNING: Removing unreachable block (ram,0x00449efb) */
/* WARNING: Removing unreachable block (ram,0x00449f03) */

void FUN_00449ec0(void)

{
  int iVar1;
  undefined1 *unaff_EBX;
  undefined4 *puVar2;
  undefined4 local_63;
  
  puVar2 = &local_63;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 2) = 0;
  FUN_00565da0("%d.%d",1,4);
  *unaff_EBX = 0;
  return;
}


// ==== 0x449f20 FUN_00449f20

/* WARNING: Removing unreachable block (ram,0x00449f61) */
/* WARNING: Removing unreachable block (ram,0x00449f70) */

void FUN_00449f20(void)

{
  int iVar1;
  undefined1 *unaff_EBX;
  undefined4 *puVar2;
  undefined4 local_63;
  
  puVar2 = &local_63;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 2) = 0;
  FUN_00565da0("%d.%d.%d",1,4,DAT_00734994);
  *unaff_EBX = 0;
  return;
}


// ==== 0x449f80 FUN_00449f80

float10 __fastcall FUN_00449f80(int param_1)

{
  float10 fVar1;
  
  if ((*(int *)(param_1 + 0x3bc) == 0) || (*(int *)(param_1 + 0x3bc) == 0x7fffffff)) {
    fVar1 = (float10)0.0;
  }
  else {
    fVar1 = (float10)DAT_0073ad34 * (float10)0.00025 -
            (float10)*(int *)(param_1 + 0x3bc) * (float10)0.00025;
  }
  if ((*(int *)(param_1 + 0x3b8) != 0) && (*(int *)(param_1 + 0x3b8) != 0x7fffffff)) {
    return (float10)*(int *)(param_1 + 0x3b8) * (float10)0.00025 - fVar1;
  }
  return (float10)0.0 - fVar1;
}


// ==== 0x449fe0 FUN_00449fe0

float10 __fastcall FUN_00449fe0(int param_1)

{
  int in_EAX;
  
  if (param_1 == 0) {
    return (float10)*(float *)(in_EAX + 0x1c);
  }
  return (float10)*(float *)(in_EAX + 0x20);
}


// ==== 0x449ff0 FUN_00449ff0

int FUN_00449ff0(void)

{
  int *in_EAX;
  
  if (*in_EAX != 0) {
    return (int)*(short *)(*in_EAX + 10);
  }
  return -1;
}


// ==== 0x44a000 FUN_0044a000

void __fastcall FUN_0044a000(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *in_EAX;
  
  iVar1 = param_1[2];
  iVar4 = param_1[3];
  iVar2 = param_1[1];
  iVar3 = *param_1;
  if (iVar3 == 1) {
    if (iVar2 != 0) {
      return;
    }
  }
  else {
    if ((iVar3 < 2) || (3 < iVar3)) {
      if (iVar3 != 0) {
        return;
      }
      *in_EAX = 0;
      in_EAX[2] = 0;
      *(undefined1 *)(in_EAX + 3) = 0;
      in_EAX[1] = 0;
      return;
    }
    if (iVar2 == 0) {
      return;
    }
  }
  *in_EAX = iVar3;
  *(char *)(in_EAX + 3) = (char)iVar4;
  in_EAX[2] = iVar1;
  in_EAX[1] = iVar2;
  return;
}


// ==== 0x44a060 FUN_0044a060

undefined4 FUN_0044a060(void)

{
  int *in_EAX;
  
  if ((1 < *in_EAX) && (*in_EAX < 4)) {
    return 1;
  }
  return 0;
}


// ==== 0x44a080 FUN_0044a080

void FUN_0044a080(float param_1)

{
  undefined4 uVar1;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = &PTR_FUN_006c97f4;
  unaff_ESI[2] = 0;
  *(bool *)(unaff_ESI + 1) = 0.0 <= param_1;
  unaff_ESI[3] = param_1;
  uVar1 = _ftol_nocw();
  unaff_ESI[2] = uVar1;
  return;
}


// ==== 0x44a0e0 FUN_0044a0e0

undefined4 __fastcall FUN_0044a0e0(int param_1)

{
  int iVar1;
  
  if ((((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x10), iVar1 != 1)) && (iVar1 != 2)) &&
     ((iVar1 != 3 || (*(char *)(param_1 + 4) == '\0')))) {
    return 0;
  }
  return 1;
}


// ==== 0x44a110 FUN_0044a110

undefined4 * __thiscall FUN_0044a110(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006c97f4;
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x44a130 FUN_0044a130

void __fastcall FUN_0044a130(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00736098;
  iVar1 = *(int *)(DAT_00736098 + 0x18);
  *param_1 = *(undefined4 *)(DAT_00736098 + 0x10);
  *(int *)(iVar2 + 0x18) = iVar1 + -1;
  *(undefined4 **)(iVar2 + 0x10) = param_1;
  return;
}


// ==== 0x44a150 FUN_0044a150

void FUN_0044a150(undefined4 param_1)

{
  undefined4 *in_EAX;
  
  FUN_0044a080(param_1);
  in_EAX[5] = 1;
  *in_EAX = &PTR_FUN_006c98d0;
  return;
}


// ==== 0x44a170 FUN_0044a170

void __fastcall FUN_0044a170(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006c97f4;
  return;
}


// ==== 0x44a180 FUN_0044a180

char * FUN_0044a180(void)

{
  return "Win road race";
}


// ==== 0x44a190 FUN_0044a190

void FUN_0044a190(undefined4 param_1)

{
  undefined4 *in_EAX;
  
  FUN_0044a080(param_1);
  in_EAX[5] = 2;
  *in_EAX = &PTR_FUN_006c98b0;
  return;
}


// ==== 0x44a1b0 FUN_0044a1b0

char * FUN_0044a1b0(void)

{
  return "Win drag race";
}


// ==== 0x44a1c0 FUN_0044a1c0

void FUN_0044a1c0(undefined4 param_1)

{
  undefined4 *in_EAX;
  
  FUN_0044a080(param_1);
  in_EAX[5] = 3;
  *in_EAX = &PTR_FUN_006c97fc;
  return;
}


// ==== 0x44a1e0 FUN_0044a1e0

char * FUN_0044a1e0(void)

{
  return "Steer player in drag race";
}


// ==== 0x44a1f0 FUN_0044a1f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0044a1f0(void)

{
  return (float10)TeleportSpeedFlip;
}


// ==== 0x44a200 FUN_0044a200

void FUN_0044a200(undefined4 param_1)

{
  undefined4 *in_EAX;
  
  FUN_0044a080(param_1);
  in_EAX[5] = 4;
  *in_EAX = &PTR_FUN_006c97d4;
  return;
}


// ==== 0x44a220 FUN_0044a220

char * FUN_0044a220(void)

{
  return "Be traffic car";
}


// ==== 0x44a230 FUN_0044a230

void FUN_0044a230(undefined4 param_1)

{
  undefined4 *in_EAX;
  
  FUN_0044a080(param_1);
  in_EAX[5] = 5;
  *in_EAX = &PTR_FUN_006c97b4;
  return;
}


// ==== 0x44a250 FUN_0044a250

char * FUN_0044a250(void)

{
  return "Be ambient traffic car";
}


// ==== 0x44a260 FUN_0044a260

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0044a260(void)

{
  return (float10)_TeleportSpeedFlip;
}


// ==== 0x44a270 FUN_0044a270

undefined4 * __thiscall FUN_0044a270(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_0044a170();
  iVar2 = DAT_0073609c;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_0073609c + 0x18);
    *param_1 = *(undefined4 *)(DAT_0073609c + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x44a2a0 FUN_0044a2a0

undefined4 __fastcall FUN_0044a2a0(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x5c);
  if (((cVar1 != -1) && (*(short *)(param_1 + 0x5e) != -1)) && (-1 < cVar1)) {
    return (&DAT_0077af30)[cVar1];
  }
  return 0;
}


// ==== 0x44a2c0 FUN_0044a2c0

int __fastcall FUN_0044a2c0(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *(char *)(param_1 + 0x5c);
  if ((cVar1 != -1) && (*(short *)(param_1 + 0x5e) != -1)) {
    if (cVar1 < 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (&DAT_0077af30)[cVar1];
    }
    return *(short *)(param_1 + 0x5e) * 0x88 + 0x27c + iVar2;
  }
  return 0;
}


// ==== 0x44a300 FUN_0044a300

void __fastcall FUN_0044a300(int param_1)

{
  *(undefined4 *)(param_1 + 0x34) = 0;
  return;
}


// ==== 0x44a310 FUN_0044a310

undefined4 __fastcall FUN_0044a310(int param_1)

{
  return *(undefined4 *)(param_1 + 0x3e4);
}


// ==== 0x44a320 FUN_0044a320

undefined4 FUN_0044a320(void)

{
  return DAT_0073615c;
}


// ==== 0x44a330 FUN_0044a330

undefined4 * FUN_0044a330(undefined4 *param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  void *local_1c;
  code *pcStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  pcStack_18 = FUN_0068662b;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  FUN_00458a50(param_2);
  *param_1 = &PTR_FUN_006c9820;
  local_14 = 0;
  FUN_0044cd30(param_1 + 0xb,param_2,DAT_0078a2fc);
  param_1[0x100] = 0;
  param_1[0x102] = 0;
  param_1[0x105] = 0;
  param_1[0x106] = 0;
  param_1[0x108] = 0;
  param_1[0x109] = 0;
  param_1[0x10a] = 0;
  param_1[0x10b] = 0;
  param_1[0x10f] = 0;
  param_1[0x110] = 0;
  param_1[0x11f] = 0;
  param_1[0x12a] = 0;
  param_1[299] = 0;
  param_1[300] = 0;
  *(undefined1 *)(param_1 + 0x12d) = 0;
  param_1[0x130] = 0;
  sVar1 = *(short *)(param_2 + 8);
  local_14 = CONCAT31(local_14._1_3_,1);
  param_1[0xff] = 0;
  param_1[0xfe] = 0;
  param_1[0xfd] = 0x14;
  *(undefined1 *)(param_1 + 0xfb) = 0xff;
  param_1[0xfc] = (float)(int)sVar1 * 0.1 * -0.033333335;
  FUN_0044ce60();
  param_1[0xf6] = param_1 + 0xee;
  param_1[0xf7] = param_1 + 0xf1;
  param_1[0xf8] = param_1 + 0xb;
  param_1[0xf9] = param_1[0xf5];
  param_1[0x100] = 0;
  param_1[0x101] = 0;
  param_1[0xfa] = 0;
  param_1[0x108] = 0;
  param_1[0x109] = 0;
  param_1[0x10a] = 0;
  param_1[0x10e] = 0;
  param_1[0x10f] = 0;
  param_1[0x110] = 0;
  param_1[0x111] = 0;
  uVar2 = _ftol_nocw();
  param_1[0x10b] = uVar2;
  puVar3 = _malloc(0x28);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)((int)puVar3 + 6) = 0;
    *(undefined1 *)((int)puVar3 + 7) = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    *(undefined1 *)(puVar3 + 1) = 4;
    *(undefined1 *)((int)puVar3 + 5) = 10;
    *puVar3 = &PTR_FUN_006b9694;
    puVar3[4] = puVar3 + 5;
    puVar4 = _malloc(0x28);
    puVar3[4] = puVar4;
    for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
  }
  param_1[0x10c] = puVar3;
  if (*(int *)(*(int *)(param_1[1] + 0x14) + 4) == 3) {
    param_1[0x120] = 0;
  }
  else {
    puVar3 = _malloc(0x28);
    if (puVar3 == (undefined4 *)0x0) {
      param_1[0x120] = 0;
    }
    else {
      *(undefined1 *)((int)puVar3 + 6) = 0;
      *(undefined1 *)((int)puVar3 + 7) = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      *(undefined1 *)(puVar3 + 1) = 4;
      *(undefined1 *)((int)puVar3 + 5) = 5;
      *puVar3 = &PTR_FUN_006b9694;
      puVar3[4] = puVar3 + 5;
      puVar3[5] = 0;
      puVar3[6] = 0;
      puVar3[7] = 0;
      puVar3[8] = 0;
      puVar3[9] = 0;
      param_1[0x120] = puVar3;
    }
  }
  param_1[0x124] = 0;
  param_1[0x125] = 0;
  param_1[0x126] = 0;
  param_1[0x127] = 0;
  param_1[0x11c] = 0;
  param_1[0x102] = 0;
  *(undefined1 *)(param_1 + 0x11b) = 1;
  param_1[0x103] = 0x4b189680;
  uVar2 = FUN_00442200(*(undefined4 *)(param_1[1] + 0x814));
  param_1[0x11d] = uVar2;
  param_1[0x11f] = 0;
  *(undefined1 *)(param_1 + 0x107) = 1;
  param_1[0x11e] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x129) = 0xff;
  param_1[0x12a] = 0;
  param_1[299] = 0;
  param_1[300] = 0;
  *(undefined1 *)(param_1 + 0x12d) = 0;
  param_1[0x128] = 0;
  *(undefined1 *)(param_1 + 0x104) = 0;
  *(undefined1 *)(param_1 + 0x12f) = 0;
  param_1[0x130] = 0;
  param_1[0x12e] = 0x3f800000;
  ExceptionList = local_1c;
  return param_1;
}


// ==== 0x44a640 FUN_0044a640

void * __thiscall FUN_0044a640(void *param_1,byte param_2)

{
  FUN_0044a660();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x44a660 FUN_0044a660

void __fastcall FUN_0044a660(undefined4 *param_1)

{
  void *pvStack_c;
  code *pcStack_8;
  uint local_4;
  
  pcStack_8 = FUN_00684ff5;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_006c9820;
  local_4 = 1;
  if ((undefined4 *)param_1[0xff] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xff])(1);
  }
  if ((undefined4 *)param_1[0xfe] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xfe])(1);
  }
  if ((undefined4 *)param_1[0x10c] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x10c])(1);
  }
  if ((undefined4 *)param_1[0x120] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x120])(1);
  }
  local_4 = local_4 & 0xffffff00;
  FUN_0044ce00(param_1 + 0xb);
  *param_1 = &PTR_FUN_006c8f08;
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x44a6f0 FUN_0044a6f0

void __thiscall FUN_0044a6f0(int param_1,int param_2)

{
  int iVar1;
  int unaff_EBX;
  char cVar2;
  
  FUN_00571ea0(0,"AICarController");
  (**(code **)(**(int **)(param_1 + 8) + 8))(param_2);
  FUN_00571c20(param_2,param_1 + 0xc,0x20,0xffffffff,0);
  FUN_0044ceb0();
  FUN_00571c20(param_2,param_1 + 0x3f4,1,4,1);
  FUN_00571c20(param_2,param_1 + 0x3ec,1,1,1);
  FUN_00571c20(param_2,param_1 + 0x3f0,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x4c0,4,0xffffffff,0);
  FUN_0044d760();
  FUN_0044e480(param_1 + 0x3f8);
  FUN_00571c20(param_2,param_1 + 0x400,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x404,4,4,1);
  FUN_00571c20(param_2,param_1 + 0x420,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x424,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x428,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x42c,4,0xffffffff,0);
  FUN_005840c0(*(undefined4 *)(*(int *)(param_1 + 0x430) + 0x10));
  FUN_005840c0(*(undefined4 *)(*(int *)(unaff_EBX + 0x480) + 0x10));
  FUN_00571c20(param_2,unaff_EBX + 0x490,0x10,0xffffffff,0);
  FUN_0041ff80(DAT_007361f8);
  FUN_00571c20(param_2,unaff_EBX + 0x43c,4,0xffffffff,0);
  FUN_00571c20(param_2,unaff_EBX + 0x440,4,0xffffffff,0);
  FUN_00571c20(param_2,unaff_EBX + 0x444,4,4,1);
  FUN_00571c20(param_2,unaff_EBX + 0x448,4,0xffffffff,0);
  FUN_00571c20(param_2,unaff_EBX + 0x40c,4,0xffffffff,0);
  cVar2 = -1;
  if (*(int *)(unaff_EBX + 0x470) != 0) {
    cVar2 = *(char *)(*(int *)(unaff_EBX + 0x470) + 0x10);
  }
  FUN_00571c20(param_2,&stack0x00000000,1,1,1);
  if (*(char *)(param_2 + 0x3d) != '\0') {
    if (cVar2 < '\0') {
      *(undefined4 *)(unaff_EBX + 0x470) = 0;
    }
    else {
      *(undefined4 *)(unaff_EBX + 0x470) = (&DAT_007361b4)[cVar2];
    }
  }
  FUN_00571c20(param_2,unaff_EBX + 0x474,4,4,1);
  FUN_00571c20(param_2,unaff_EBX + 0x46c,1,1,0);
  FUN_00571c20(param_2,unaff_EBX + 0x478,4,4,1);
  FUN_00571c20(param_2,unaff_EBX + 0x47c,4,0xffffffff,0);
  FUN_00571c20(param_2,unaff_EBX + 0x408,4,0xffffffff,0);
  FUN_00571c20(param_2,unaff_EBX + 0x4a0,4,0xffffffff,0);
  FUN_00571c20(param_2,unaff_EBX + 0x4a4,1,1,1);
  FUN_0045ac60();
  FUN_00571c20(param_2,unaff_EBX + 0x410,1,1,0);
  FUN_00571c20(param_2,unaff_EBX + 0x4b8,4,0xffffffff,0);
  FUN_00571c20(param_2,unaff_EBX + 0x4bc,1,1,0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10 + 0x4c + param_2;
  *(int *)(iVar1 + 0xc) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x44aa10 AIGoal::Create

/* [canon] rivals V (Ghidra+Hopper) docs/re/rivals.md */

void AIGoal__Create(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int unaff_EDI;
  
  if (*(undefined4 **)(unaff_EDI + 0x3fc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_EDI + 0x3fc))(1);
    *(undefined4 *)(unaff_EDI + 0x3fc) = 0;
  }
  switch(param_1) {
  case 1:
    iVar1 = FUN_00567160();
    if (iVar1 != 0) {
      uVar2 = FUN_0044a150(0xbf800000);
      *(undefined4 *)(unaff_EDI + 0x3fc) = uVar2;
      return;
    }
    break;
  case 2:
    iVar1 = FUN_00567160();
    if (iVar1 != 0) {
      uVar2 = FUN_0044a190(0xbf800000);
      *(undefined4 *)(unaff_EDI + 0x3fc) = uVar2;
      return;
    }
    break;
  case 3:
    iVar1 = FUN_00567160();
    if (iVar1 != 0) {
      uVar2 = FUN_0044a1c0(0xbf800000);
      *(undefined4 *)(unaff_EDI + 0x3fc) = uVar2;
      return;
    }
    break;
  case 4:
    iVar1 = FUN_00567160();
    if (iVar1 != 0) {
      uVar2 = FUN_0044a200(0xbf800000);
      *(undefined4 *)(unaff_EDI + 0x3fc) = uVar2;
      return;
    }
    break;
  case 5:
    iVar1 = FUN_00567160();
    if (iVar1 != 0) {
      uVar2 = FUN_0044a230(0xbf800000);
      *(undefined4 *)(unaff_EDI + 0x3fc) = uVar2;
      return;
    }
    break;
  default:
    puVar3 = (undefined4 *)FUN_00567160();
    if (puVar3 == (undefined4 *)0x0) {
      *(undefined4 *)(unaff_EDI + 0x3fc) = 0;
      return;
    }
    FUN_0044a080(0xbf800000);
    puVar3[5] = 5;
    *puVar3 = &PTR_FUN_006c97b4;
    *(undefined4 **)(unaff_EDI + 0x3fc) = puVar3;
    return;
  }
  *(undefined4 *)(unaff_EDI + 0x3fc) = 0;
  return;
}


// ==== 0x44ab50 FUN_0044ab50

void __thiscall FUN_0044ab50(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_3;
  iVar2 = param_2;
  if ((param_2 != 0) && (param_3 != 0)) {
    if (**(int **)(param_1 + 0x3d8) == 0) {
      *(undefined1 *)(param_1 + 0x3ec) = 0xff;
    }
    else {
      *(undefined1 *)(param_1 + 0x3ec) = *(undefined1 *)(**(int **)(param_1 + 0x3d8) + 10);
    }
    param_2 = 0;
    if (param_4 < 0) {
      FUN_0044baf0(param_1,iVar2,param_3,&param_2,0);
      param_4 = param_2;
    }
    piVar1 = *(int **)(param_1 + 0x3d8);
    *piVar1 = iVar2;
    piVar1[1] = iVar3;
    piVar1[2] = param_4;
  }
  return;
}


// ==== 0x44abc0 FUN_0044abc0

undefined4 __thiscall FUN_0044abc0(int *param_1,char param_2)

{
  if (param_2 == '\0') {
    return *(undefined4 *)param_1[0xf6];
  }
  if (*(int *)param_1[0xf6] == 0) {
    (**(code **)(*param_1 + 0x2c))(1);
    return *(undefined4 *)param_1[0xf6];
  }
  return *(undefined4 *)param_1[0xf6];
}


// ==== 0x44ac10 FUN_0044ac10

undefined4 __thiscall FUN_0044ac10(int *param_1,char param_2)

{
  if (param_2 == '\0') {
    return *(undefined4 *)(param_1[0xf6] + 4);
  }
  if (*(int *)param_1[0xf6] == 0) {
    (**(code **)(*param_1 + 0x2c))(1);
    return *(undefined4 *)(param_1[0xf6] + 4);
  }
  return *(undefined4 *)(param_1[0xf6] + 4);
}


// ==== 0x44ac60 FUN_0044ac60

undefined4 __thiscall FUN_0044ac60(int *param_1,char param_2)

{
  if (param_2 == '\0') {
    return *(undefined4 *)(param_1[0xf6] + 8);
  }
  if (*(int *)param_1[0xf6] == 0) {
    (**(code **)(*param_1 + 0x2c))(1);
    return *(undefined4 *)(param_1[0xf6] + 8);
  }
  return *(undefined4 *)(param_1[0xf6] + 8);
}


// ==== 0x44acb0 FUN_0044acb0

float10 __fastcall FUN_0044acb0(int param_1)

{
  float *pfVar1;
  float10 fVar2;
  
  if (**(int **)(param_1 + 0x3d8) == 0) {
    return (float10)0.0;
  }
  pfVar1 = (float *)(*(int **)(param_1 + 0x3d8))[1];
  fVar2 = ((float10)*(float *)(*(int *)(param_1 + 4) + 0x60) - (float10)*pfVar1) *
          (float10)pfVar1[4] -
          ((float10)*(float *)(*(int *)(param_1 + 4) + 100) - (float10)pfVar1[1]) *
          (float10)pfVar1[3];
  if ((float10)0.0 < fVar2) {
    return fVar2 - (float10)pfVar1[10];
  }
  return -(fVar2 + (float10)pfVar1[9]);
}


// ==== 0x44ad00 FUN_0044ad00

void __fastcall FUN_0044ad00(int param_1)

{
  undefined4 uVar1;
  
  *(float *)(param_1 + 0x3f0) =
       (float)(int)*(short *)(*(int *)(param_1 + 4) + 8) * 0.1 * -0.033333335;
  *(undefined4 *)(param_1 + 0x490) = 0;
  *(undefined4 *)(param_1 + 0x494) = 0;
  *(undefined4 *)(param_1 + 0x498) = 0;
  *(undefined4 *)(param_1 + 0x49c) = 0;
  (**(code **)(**(int **)(param_1 + 8) + 0x58))();
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffffe;
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffe;
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffffe;
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0xfffffffe;
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffe;
  *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) & 0xfffffffe;
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xfffffffe;
  *(undefined1 *)(param_1 + 0x410) = 0;
  uVar1 = FUN_00442200(*(undefined4 *)(*(int *)(param_1 + 4) + 0x814));
  *(undefined4 *)(param_1 + 0x474) = uVar1;
  return;
}


// ==== 0x44adc0 FUN_0044adc0

void FUN_0044adc0(int *param_1,int param_2,int param_3,char param_4,char param_5)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  bool bVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  int iVar11;
  float *pfVar12;
  int iVar13;
  undefined4 uStack_48;
  int iStack_44;
  float local_34;
  int local_30;
  float *local_2c;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  
  iVar1 = *(int *)param_1[0xf6];
  local_34 = 999999.0;
  fVar2 = *(float *)(param_1[1] + 0x814);
  iVar13 = 0;
  local_30 = 0;
  local_2c = (float *)0x0;
  iVar10 = (**(code **)(*param_1 + 0x40))();
  iVar3 = param_1[1];
  iVar4 = *(int *)(*(int *)(iVar3 + 0x14) + 4);
  uStack_48 = 1;
  if (iVar4 == 1) {
    uStack_48 = 0x401;
  }
  else if (iVar4 == 2) {
    uStack_48 = 5;
  }
  else if (iVar4 == 3) {
    uStack_48 = 0x201;
  }
  iStack_44 = 0;
  do {
    iVar4 = param_2;
    if (1 < iStack_44) {
      puVar5 = DAT_0077af20;
      if (iVar13 == 0) goto joined_r0x0044b02d;
      break;
    }
    for (; iVar4 <= param_3; iVar4 = iVar4 + 1) {
      if ((-1 < iVar4) && (iVar13 = (&DAT_0077af30)[iVar4], iVar13 != 0)) {
        if (iStack_44 < 1) {
          bVar6 = *(float *)(iVar13 + 0x18) <= fVar2;
          if (*(float *)(iVar13 + 0x1c) <= *(float *)(iVar13 + 0x18)) {
            if (bVar6) goto LAB_0044aee1;
          }
          else if (!bVar6) goto LAB_0044afd9;
          if (fVar2 < *(float *)(iVar13 + 0x1c) == (fVar2 == *(float *)(iVar13 + 0x1c)))
          goto LAB_0044afd9;
        }
LAB_0044aee1:
        if (param_4 == '\0') {
LAB_0044af11:
          pfVar12 = (float *)FUN_00442690(iVar13,0x497423f0,uStack_48,0);
          if (pfVar12 != (float *)0x0) {
            FUN_004422b0(0,0);
            fVar7 = *(float *)(iVar3 + 0x60) - fStack_20;
            fVar9 = *(float *)(iVar3 + 100) - fStack_1c;
            fVar8 = *(float *)(iVar3 + 0x68) - fStack_18;
            fVar7 = SQRT(fVar8 * fVar8 + fVar9 * fVar9 + fVar7 * fVar7);
            if (param_5 == '\0') {
              fVar8 = (*(float *)(iVar3 + 0x60) - *pfVar12) * pfVar12[4] -
                      (*(float *)(iVar3 + 100) - pfVar12[1]) * pfVar12[3];
              if (fVar8 <= 0.0) {
                fVar8 = -(fVar8 + pfVar12[9]);
              }
              else {
                fVar8 = fVar8 - pfVar12[10];
              }
              if (0.0 <= fVar8) goto LAB_0044afd9;
            }
            if ((fVar7 < local_34) && (iVar13 != iVar1)) {
              local_34 = fVar7;
              local_30 = iVar13;
              local_2c = pfVar12;
            }
          }
        }
        else {
          iVar11 = 0;
          do {
            if (*(char *)((-(uint)(iVar10 == 0) & 0xfffffffa) + 0x276 + iVar13 + iVar11) != '\0')
            goto LAB_0044af11;
            iVar11 = iVar11 + 1;
          } while (iVar11 < 6);
        }
      }
LAB_0044afd9:
      iVar13 = local_30;
    }
    iStack_44 = iStack_44 + 1;
  } while (iVar13 == 0);
  puVar5 = DAT_0077af20;
  if (local_2c != (float *)0x0) {
    (**(code **)(*param_1 + 0x10))(iVar13,local_2c,0xffffffff);
    return;
  }
joined_r0x0044b02d:
  for (; ((undefined4 **)puVar5 != &DAT_0077af20 && (puVar5 != (undefined4 *)0x0));
      puVar5 = (undefined4 *)*puVar5) {
  }
  puVar5 = (undefined4 *)param_1[0xf6];
  *puVar5 = 0;
  puVar5[1] = 0;
  puVar5[2] = 0xffffffff;
  return;
}


// ==== 0x44b060 FUN_0044b060

uint FUN_0044b060(int *param_1)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  undefined4 in_EAX;
  uint uVar4;
  undefined2 extraout_var;
  ushort uVar5;
  float10 fVar6;
  
  uVar4 = CONCAT31((int3)((uint)in_EAX >> 8),DAT_0078a344);
  if ((((DAT_0078a344 == '\0') && (uVar4 = DAT_007361a8, DAT_007361a8 == 0)) &&
      ((DAT_0078a2f0 != 1099 || ((DAT_00735fb0 == 0 || (uVar4 = DAT_00735fb0, DAT_00735fb8 != 4)))))
      ) && ((uVar4 = param_1[2], '\x02' < *(char *)(uVar4 + 0x10) &&
            ((*DAT_007361f0 != 9 && ((uVar4 = param_1[0x109], uVar4 == 0 || (uVar4 == 0x7fffffff))))
            )))) {
    uVar4 = SpecialCamCooldown();
    if (uVar4 == 0) {
      iVar2 = param_1[1];
      fVar1 = *(float *)(iVar2 + 0x3d0);
      uVar5 = (ushort)(fVar1 < 5.0) << 8 | (ushort)NAN(fVar1) << 10 | (ushort)(fVar1 == 5.0) << 0xe;
      uVar4 = (uint)uVar5;
      if (((((fVar1 >= 5.0) && (0 < *(int *)(iVar2 + 0x3cc))) &&
           (uVar4 = (uint)CONCAT11((char)(uVar5 >> 8),*(char *)(iVar2 + 0x828)),
           *(char *)(iVar2 + 0x828) == '\0')) &&
          ((uVar4 = 0, param_1[0xfe] != 0 && (uVar4 = *(uint *)(param_1[0xfe] + 0x1f8), uVar4 != 9))
          )) && (((uVar4 != 10 && ((uVar4 != 0xe && (uVar4 != 0xb)))) && (uVar4 != 0xc)))) {
        uVar4 = (**(code **)(*param_1 + 0x58))();
        if (uVar4 != 0xfffffffe) {
          fVar6 = (float10)FUN_00421400();
          fVar3 = (float10)120.0;
          uVar4 = CONCAT22(extraout_var,
                           (ushort)(fVar6 < fVar3) << 8 | (ushort)(NAN(fVar6) || NAN(fVar3)) << 10 |
                           (ushort)(fVar6 == fVar3) << 0xe);
          if (fVar6 >= fVar3) {
            fVar1 = (float)*(int *)(DAT_0073619c + 0x14) * 0.00025;
            uVar4 = CONCAT22((short)((uint)DAT_0073619c >> 0x10),
                             (ushort)(fVar1 < 30.0) << 8 | (ushort)NAN(fVar1) << 10 |
                             (ushort)(fVar1 == 30.0) << 0xe);
            if (fVar1 >= 30.0) {
              return CONCAT31((int3)(uVar4 >> 8),*(short *)(*(int *)(param_1[1] + 0x1c) + 0x10) == 0
                             );
            }
          }
        }
      }
    }
  }
  return uVar4 & 0xffffff00;
}


// ==== 0x44b1b0 FUN_0044b1b0

void __thiscall FUN_0044b1b0(int *param_1,float param_2)

{
  int *piVar1;
  float fVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  void *pvVar8;
  char extraout_DL;
  int *piVar9;
  bool bVar10;
  float10 fVar11;
  float10 extraout_ST1;
  undefined1 auStack_1e0 [436];
  void *pvStack_2c;
  void *pvStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  pcStack_18 = FUN_00687456;
  pvStack_1c = ExceptionList;
  if ((DAT_0078a344 != '\0') ||
     (piVar9 = DAT_0073619c, ExceptionList = &pvStack_1c, DAT_007361a8 != 0)) {
    ExceptionList = &pvStack_1c;
    if ((float)param_1[0x128] == 0.0) {
      ExceptionList = &pvStack_1c;
      uVar4 = (**(code **)(*param_1 + 0x58))();
      iVar5 = (uVar4 & ((int)uVar4 < 1) - 1) * 0x54;
      fVar11 = (float10)Random_NextFloat(*(float *)(&DAT_0077a018 + iVar5) -
                                         *(float *)(&DAT_0077a014 + iVar5));
      param_1[0x128] = (int)(float)(fVar11 + extraout_ST1 + (float10)0.001);
    }
    piVar9 = DAT_0073619c;
    if (0.0 <= (float)param_1[0x128]) {
      if ((DAT_0073619c[1] == 0) || (DAT_0073619c[1] == 0x7fffffff)) {
        fVar2 = -1.0;
      }
      else {
        fVar2 = (float)(DAT_0073ad34 - DAT_0073619c[1]) * 0.00025;
      }
      if (fVar2 < (float)param_1[0x128]) {
        (**(code **)(*(int *)param_1[2] + 0x38))(0,0,0,0);
        FUN_0044bcb0();
        ExceptionList = pvStack_2c;
        return;
      }
    }
    else {
      fVar11 = (float10)Countdown__GetSecondsRemaining();
      if ((fVar11 < -(float10)(float)param_1[0x128]) && (*piVar9 != 4)) {
        (**(code **)(*(int *)param_1[2] + 0x38))(0x42c80000,0,0,1);
        FUN_0044bcb0();
        ExceptionList = pvStack_2c;
        return;
      }
    }
  }
  if (((*piVar9 != 4) && (((DAT_0078a368 == 0 || (*piVar9 < 2)) && (DAT_0078a344 == '\0')))) &&
     (DAT_007361a8 == 0)) {
    (**(code **)(*(int *)param_1[2] + 0x38))(0,0,0,1);
    FUN_0044bcb0();
    iVar5 = _ftol_nocw();
    param_1[0x10a] = iVar5;
  }
  if (*(short *)(*(int *)(param_1[1] + 0x1c) + 0x10) == 0) {
    if ((param_1[0x10a] != 0) && (param_1[0x10a] != 0x7fffffff)) {
      iVar5 = FUN_00586640(param_2);
      if (iVar5 != 0) {
        iVar5 = *(int *)(param_1[1] + 0x28);
        goto joined_r0x0044b3e1;
      }
      if (*(int *)(param_1[1] + 0x3cc) < 4) {
        param_1[0x10a] = 4000;
        goto LAB_0044b3e8;
      }
      RacerNode__GetControlMode();
      goto LAB_0044b3e3;
    }
  }
  else {
    iVar5 = *(int *)(param_1[1] + 0x28);
joined_r0x0044b3e1:
    if (iVar5 != 1) {
LAB_0044b3e3:
      Car_SetMode();
    }
  }
LAB_0044b3e8:
  if (*DAT_0073619c != 4) {
    if (DAT_0078a368 == 0) {
      ExceptionList = pvStack_1c;
      return;
    }
    if (*DAT_0073619c < 2) {
      ExceptionList = pvStack_1c;
      return;
    }
  }
  if (((param_1[0xfe] != 0) && (*(int *)(param_1[0xfe] + 0x1f8) != 9)) &&
     (*(short *)(*(int *)(param_1[1] + 0x1c) + 0x10) == 0)) {
    iVar5 = SpecialCamCooldown();
    if ((iVar5 != 0) && (iVar5 = FUN_00586640(param_2), iVar5 == 0)) {
      FUN_00424cd0(param_1 + 0x10b,0x3fc00000);
      FUN_00584270(ABS(*(float *)(*(int *)(param_1[1] + 0x1c) + 0x18)) * DAT_007372b0);
      FUN_00421400();
      cVar3 = Car__IsResetGraceActive();
      if ((cVar3 == '\0') &&
         (((iVar5 = param_1[0x10c], *(char *)(iVar5 + 6) == *(char *)(iVar5 + 5) &&
           (*(float *)(iVar5 + 0xc) < 0.2)) && (extraout_DL == '\0')))) {
        FUN_00428080();
      }
    }
  }
  if ((param_1[0x109] != 0) && (param_1[0x109] != 0x7fffffff)) {
    if (*(int *)(param_1[1] + 0x28) == 4) {
      RacerNode__GetControlMode();
      Car_SetMode();
    }
    FUN_00586640(param_2);
  }
  FUN_00586640(param_2);
  FUN_00586640(param_2);
  FUN_00586640(param_2);
  iVar5 = param_1[0xf8];
  param_1[0xfc] = (int)((float)param_1[0xfc] - param_2);
  *(undefined4 *)(iVar5 + 4) = 0;
  *(undefined1 *)(iVar5 + 0x388) = 0xff;
  iVar5 = param_1[1];
  iVar6 = *(int *)(iVar5 + 0x14);
  if (*(int *)(iVar6 + 4) == 2) {
    uVar4 = DAT_006f08a4 & 0x80000007;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
    }
    if (((int)uVar4 < *(int *)(DAT_007361f8 + 0x20) - *(int *)(DAT_007361f8 + 0x1c)) &&
       (iVar5 == *(int *)(DAT_007361f8 + 0x28 + (*(int *)(DAT_007361f8 + 0x1c) + uVar4) * 4))) {
      bVar10 = true;
    }
    else {
      bVar10 = false;
    }
LAB_0044b6d9:
    if (((float)(DAT_0073ad34 - param_1[0x130]) * 0.00025 < 0.2) || (!bVar10)) {
LAB_0044b707:
      if (param_1[0xfe] != 0) {
        if ((((*(int *)(iVar6 + 4) == 2) && (cVar3 = CarState__IsNitrousOn(), cVar3 != '\0')) &&
            (cVar3 = FUN_0044cac0(param_1), cVar3 == '\0')) &&
           (cVar3 = (**(code **)(*param_1 + 0x8c))(), cVar3 != '\0')) {
          CarState__StopNitrous();
          (**(code **)(*param_1 + 0x80))();
        }
        if (*(int *)(param_1[1] + 0x28) == 4) {
          ExceptionList = pvStack_1c;
          return;
        }
        if (*(int *)(param_1[0xfe] + 0x1f8) == 5) {
          FUN_0044cf30(param_1 + 0xb,param_1);
          (**(code **)(*param_1 + 0x88))(param_1[0xfe]);
          RacerAI__UpdateDesiredSpeed(param_1);
        }
        else {
          cVar3 = FUN_0044a060();
          if (cVar3 == '\0') {
            ExceptionList = pvStack_1c;
            return;
          }
          cVar3 = FUN_0057a6b0();
          if (cVar3 == '\0') {
            ExceptionList = pvStack_1c;
            return;
          }
          FUN_00458d90();
          FUN_0044cf30(param_1 + 0xb,param_1);
          iVar5 = FUN_0057b520();
          if (iVar5 == 0) {
            ExceptionList = pvStack_1c;
            return;
          }
          FUN_0045ae10(param_1[0xf7],auStack_1e0,param_1 + 0xb,0,0);
          (**(code **)(*(int *)param_1[2] + 0x3c))(auStack_1e0);
        }
        goto LAB_0044bab2;
      }
    }
  }
  else if (*(int *)(iVar6 + 4) == 3) {
    if ((*(int *)(DAT_007361f8 + 0x18) - *(int *)(DAT_007361f8 + 0x24) <= (int)DAT_006f08a4 % 0x16)
       || (iVar5 != *(int *)(DAT_007361f8 + 0x28 +
                            (*(int *)(DAT_007361f8 + 0x24) + (int)DAT_006f08a4 % 0x16) * 4)))
    goto LAB_0044b707;
  }
  else if (*(int *)(iVar6 + 4) == 1) {
    if (*(int *)(iVar5 + 0x24) != 2) {
      uVar4 = DAT_006f08a4 & 0x80000007;
      if ((int)uVar4 < 0) {
        uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
      }
      bVar10 = uVar4 == (int)*(short *)(iVar5 + 10);
      goto LAB_0044b6d9;
    }
  }
  else if ((float)param_1[0xfc] < 0.0 == ((float)param_1[0xfc] == 0.0)) goto LAB_0044b707;
  param_1[0x130] = DAT_0073ad34;
  param_1[0xfc] = (int)((float)param_1[0xfc] + 0.1);
  iVar5 = (**(code **)(*param_1 + 0x40))();
  iVar6 = Zone_Find(iVar5);
  if ((iVar6 != 0) || (iVar6 = Zone_Find(iVar5), iVar6 != 0)) {
    Car__ApplyResetZone();
  }
  FUN_0044a000();
  if ((char)param_1[0x104] == '\0') {
    if (param_1[0xff] == 0) {
      (**(code **)(*param_1 + 0x60))();
    }
    if (param_1[0xfe] == 0) {
      iVar6 = (**(code **)(*(int *)param_1[0xff] + 0x18))();
      param_1[0xfe] = iVar6;
    }
    uVar7 = (**(code **)(*param_1 + 0x40))();
    FUN_00458cc0(uVar7);
    piVar9 = param_1 + 0xb;
    cVar3 = FUN_0044cf30(piVar9,param_1);
    if (cVar3 == '\0') {
      FUN_0044c9c0();
    }
    else {
      if ((((*(int *)(*(int *)(param_1[1] + 0x14) + 4) == 2) &&
           (cVar3 = CarState__IsNitrousOn(), cVar3 != '\0')) &&
          (cVar3 = (**(code **)(*param_1 + 0x78))(piVar9), cVar3 == '\0')) &&
         (cVar3 = (**(code **)(*param_1 + 0x8c))(), cVar3 != '\0')) {
        CarState__StopNitrous();
        (**(code **)(*param_1 + 0x80))();
      }
      if (DAT_00736090 == 0) {
        FUN_0044f700();
        piVar1 = (int *)param_1[0xfe];
        cVar3 = FUN_0044a0e0();
        if (cVar3 == '\0') {
          iVar5 = FUN_0044bc30();
          if (iVar5 != 0) {
            (**(code **)(*(int *)param_1[0xfe] + 0xc))(piVar9);
            if ((undefined4 *)param_1[0xfe] != (undefined4 *)0x0) {
              (*(code *)**(undefined4 **)param_1[0xfe])(1);
            }
            param_1[0xfe] = iVar5;
          }
        }
        else {
          (**(code **)(*piVar1 + 0xc))(piVar9);
          if ((undefined4 *)param_1[0xfe] != (undefined4 *)0x0) {
            (*(code *)**(undefined4 **)param_1[0xfe])(1);
          }
          param_1[0xfe] = 0;
          (**(code **)(*param_1 + 0x84))(&stack0xfffffe18,0x14);
          param_1[0xfe] = iVar5;
        }
        (**(code **)(*param_1 + 0x88))(param_1[0xfe]);
      }
      else {
        piVar1 = (int *)param_1[0xfe];
        if (piVar1 == (int *)0x0) {
          iVar5 = FUN_00567160();
          if (iVar5 == 0) {
            param_1[0xfe] = 0;
          }
          else {
            iVar5 = FUN_00450170(0xbf800000);
            param_1[0xfe] = iVar5;
          }
        }
        else if (piVar1[0x7e] == 7) {
          (*(code *)((undefined4 *)*piVar1)[2])(piVar9);
        }
        else {
          (**(code **)*piVar1)(1);
          param_1[0xfe] = 0;
          (**(code **)(*param_1 + 0x84))(param_1 + 0xfe,7);
        }
      }
      RacerAI__UpdateDesiredSpeed(param_1);
      if ((DAT_00700740 == 0) || (cVar3 = FUN_0044b060(param_1), cVar3 == '\0')) {
        if (*(int *)(param_1[1] + 0x28) == 4) {
          RacerNode__GetControlMode();
          Car_SetMode();
        }
      }
      else {
        iVar5 = param_1[1];
        if ((*(int *)(iVar5 + 0x28) != 4) && (*(int *)(iVar5 + 0x28) != 4)) {
          if (*(undefined4 **)(iVar5 + 0x34) != (undefined4 *)0x0) {
            (**(code **)**(undefined4 **)(iVar5 + 0x34))(1);
          }
          *(undefined4 *)(iVar5 + 0x34) = 0;
          *(undefined4 *)(iVar5 + 0x28) = 4;
          pvVar8 = _malloc(0x48);
          uStack_14 = 2;
          if (pvVar8 == (void *)0x0) {
            uVar7 = 0;
          }
          else {
            uVar7 = FUN_00463260(pvVar8);
          }
          *(undefined4 *)(iVar5 + 0x34) = uVar7;
          *(undefined4 *)(*(int *)(iVar5 + 0x3c) + 0x60) = 0;
          uStack_14 = 0xffffffff;
          CarCollisionBody__SetupPhysicsPointers();
          *(undefined4 *)(*(int *)(iVar5 + 0x34) + 4) = *(undefined4 *)(iVar5 + 0x30);
        }
        FUN_00463b30();
      }
    }
  }
  else {
    FUN_0044bcb0();
    (**(code **)(*(int *)param_1[2] + 0x38))(0,0,0,1);
    *(undefined1 *)(param_1 + 0x104) = 1;
  }
LAB_0044bab2:
  FUN_0044c940();
  ExceptionList = pvStack_1c;
  return;
}


// ==== 0x44bad0 Msg_ReadOnOffByType

/* [canon] car low (ghidra-canon) docs/re/car.md */

bool __fastcall Msg_ReadOnOffByType(int param_1,undefined1 *param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0xb);
  if (cVar1 == '\x02') {
    *param_2 = 1;
    return true;
  }
  if (cVar1 == '\x05') {
    *param_2 = 0;
  }
  return cVar1 == '\x05';
}


// ==== 0x44baf0 FUN_0044baf0

void FUN_0044baf0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  
  uVar3 = *(undefined4 *)(param_1 + 0x3c4);
  uVar4 = *(undefined4 *)(param_1 + 0x3c8);
  uVar5 = *(undefined4 *)(param_1 + 0x3cc);
  uVar6 = *(undefined4 *)(param_1 + 0x3d0);
  puVar1 = (undefined4 *)(param_1 + 0x3b8);
  uVar7 = *puVar1;
  uVar8 = *(undefined4 *)(param_1 + 0x3bc);
  uVar9 = *(undefined4 *)(param_1 + 0x3c0);
  iVar10 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (*(char *)(iVar10 + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  cVar2 = *(char *)(iVar10 + 0x424);
  *puVar1 = param_2;
  *(undefined4 *)(param_1 + 0x3bc) = param_3;
  *(int *)(param_1 + 0x3c0) = (int)cVar2;
  if (*(int **)(param_1 + 0x3f8) == (int *)0x0) {
    FUN_0044f070();
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x3f8) + 0x10))(param_1 + 0x2c);
  }
  *param_4 = *(undefined4 *)(param_1 + 0x3c0);
  *(undefined4 *)(param_1 + 0x3c4) = uVar3;
  *(undefined4 *)(param_1 + 0x3c8) = uVar4;
  *(undefined4 *)(param_1 + 0x3cc) = uVar5;
  *puVar1 = uVar7;
  *(undefined4 *)(param_1 + 0x3d0) = uVar6;
  *(undefined4 *)(param_1 + 0x3bc) = uVar8;
  *(undefined4 *)(param_1 + 0x3c0) = uVar9;
  return;
}


// ==== 0x44bbd0 FUN_0044bbd0

void __thiscall FUN_0044bbd0(int *param_1,int *param_2)

{
  int *piVar1;
  
  (**(code **)(*param_2 + 8))(param_1 + 0xb);
  if ((char)param_2[0x78] == '\0') {
    piVar1 = param_1 + 0xfe;
    if ((undefined4 *)param_1[0xfe] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xfe])(1);
    }
    *piVar1 = 0;
    (**(code **)(*param_1 + 0x84))(piVar1,4);
    (**(code **)(*(int *)*piVar1 + 8))(param_1 + 0xb);
  }
  return;
}


// ==== 0x44bc30 FUN_0044bc30

int FUN_0044bc30(void)

{
  int *in_EAX;
  int iVar1;
  undefined4 local_4;
  
  iVar1 = in_EAX[0xfd];
  local_4 = 0;
  if (iVar1 == 0x14) {
    (**(code **)(*in_EAX + 0x84))(&local_4);
    iVar1 = 0x14;
    if ((in_EAX[0xfe] == 0) || (iRam00000208 <= *(int *)(in_EAX[0xfe] + 500))) {
      (*(code *)*puRam00000014)(1);
      return 0;
    }
  }
  else {
    (**(code **)(*in_EAX + 0x84))(&local_4);
    in_EAX[0xfd] = 0x14;
  }
  return iVar1;
}


// ==== 0x44bcb0 FUN_0044bcb0

void FUN_0044bcb0(void)

{
  int extraout_EDX;
  int unaff_EDI;
  float10 fVar1;
  float local_10;
  float local_c;
  float local_8;
  
  fVar1 = (float10)FUN_00564b10();
  local_8 = (float)fVar1;
  fVar1 = (float10)FUN_00564b10();
  local_10 = *(float *)(extraout_EDX + 0x60) + local_8;
  local_c = (float)((float10)*(float *)(extraout_EDX + 100) + fVar1);
  (**(code **)(**(int **)(unaff_EDI + 8) + 0x40))(&local_10);
  return;
}


// ==== 0x44bd10 RacerAI::UpdateRubberBand

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] rivals V (Ghidra+Hopper+capstone) docs/re/rivals.md */

void RacerAI__UpdateRubberBand(void)

{
  bool bVar1;
  int *in_EAX;
  uint uVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  float10 fVar9;
  undefined *puVar10;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  int iStack_1c;
  float fStack_18;
  
  iVar5 = *(int *)(in_EAX[1] + 0x1c);
  if (iVar5 == 0) {
    return;
  }
  if ((char)in_EAX[0x11b] == '\0') {
    return;
  }
  if (*(int *)(in_EAX[1] + 0x18) != 0) {
    return;
  }
  if (DAT_0078a344 != '\0') {
    return;
  }
  if (DAT_007361a8 != 0) {
    return;
  }
  if ((in_EAX[0xfe] == 0) || (bVar1 = true, *(char *)(in_EAX[0xfe] + 0x1f2) == '\0')) {
    bVar1 = false;
  }
  uVar2 = (**(code **)(*in_EAX + 0x58))();
  iVar3 = *(int *)(DAT_0073619c + 0x14);
  fVar4 = *(float *)(&DAT_0077a044 + (uVar2 & ((int)uVar2 < 1) - 1) * 0x54);
  fStack_20 = (float)(DAT_0073ad34 - in_EAX[0x108]);
  if ((float)(int)fStack_20 * 0.00025 <= _DAT_0077a49c) {
    return;
  }
  bVar8 = DAT_007360ac == 0;
  in_EAX[0x108] = DAT_0073ad34;
  in_EAX[0x11c] = 0;
  fStack_28 = 1.0;
  if (((bVar8) && (*DAT_007361f0 != 9)) && (0 < DAT_0078a320)) {
    if (!bVar1) goto LAB_0044bfdf;
    if ((float)iVar3 * 0.00025 < fVar4) goto LAB_0044bf11;
    fStack_20 = 0.0;
    fStack_24 = 0.0;
    fVar4 = (float)DAT_007361bc;
    if (DAT_007361c4 == 1) {
LAB_0044beca:
      in_EAX[0x11c] = (int)fVar4;
    }
    else if (DAT_007361c4 == 2) {
      iVar3 = *(int *)(*(int *)(DAT_007361b4 + 4) + 0x1c);
      iVar7 = *(int *)(*(int *)(DAT_007361b8 + 4) + 0x1c);
      iStack_1c = DAT_007361b4;
      fStack_28 = (float)DAT_007361b8;
      fVar4 = (float)DAT_007361b4;
      iVar6 = iVar3;
      if (*(char *)(iVar7 + 10) < *(char *)(iVar3 + 10)) {
        fStack_28 = (float)DAT_007361b4;
        fVar4 = (float)DAT_007361b8;
        iVar6 = iVar7;
        iVar7 = iVar3;
      }
      iVar3 = DAT_0078a324 / 2;
      if (*(char *)(iVar6 + 10) <= iVar3) {
        iVar3 = iVar3 + 1;
      }
      if (*(char *)(iVar7 + 10) <= iVar3) {
        iVar3 = iVar3 + 1;
      }
      if (iVar3 < *(char *)(iVar5 + 10)) {
        fVar4 = fStack_28;
      }
      goto LAB_0044beca;
    }
    fStack_18 = *(float *)(&DAT_0078a404 + *(int *)(in_EAX[0x11c] + 0x10) * 4);
    RacerAI__GetCatchUpTerms
              (iVar5,*(undefined4 *)(*(int *)(in_EAX[0x11c] + 4) + 0x1c),&fStack_20,&fStack_24);
    fStack_28 = fStack_18 * fStack_24 + 1.0 + fStack_20;
  }
LAB_0044bf11:
  if ((bVar1) && (in_EAX[0x11c] != 0)) {
    uVar2 = (**(code **)(*in_EAX + 0x58))();
    fStack_20 = (float)(uVar2 & ((int)uVar2 < 1) - 1);
    fStack_18 = *(float *)(&DAT_0077a010 + (int)fStack_20 * 0x54);
    fVar4 = *(float *)(*(int *)(in_EAX[0x11c] + 0xa8) + 0xc);
    iVar5 = (int)*(char *)(*(int *)(*(int *)(in_EAX[0x11c] + 4) + 0x1c) + 10);
    if (fVar4 < _K_ONE) {
      puVar10 = &DAT_00779fd0 + iVar5 * 8;
    }
    else {
      puVar10 = &DAT_00779fb0 + iVar5 * 8;
    }
    LinearTable__Init(puVar10,0,0x41100000);
    fVar9 = (float10)FUN_00583ea0((float)(int)fStack_20);
    fVar9 = (float10)bMax_float((float)(((float10)fVar4 - (float10)_K_ONE) * fVar9 + (float10)_K_ONE
                                       ),fStack_18);
    fStack_28 = (float)(fVar9 * (float10)fStack_28);
  }
LAB_0044bfdf:
  fVar9 = (float10)bMax_float(fStack_28,0x3f800000);
  *(float *)(in_EAX[1] + 0x404) = (float)fVar9;
  in_EAX[0x12e] = (int)fStack_28;
  return;
}


// ==== 0x44c010 RacerAI::GetCatchUpTerms

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] rivals V (Ghidra+capstone) docs/re/rivals.md */

void RacerAI__GetCatchUpTerms(int *param_1,int *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *unaff_EDI;
  float10 fVar7;
  float10 fVar8;
  undefined4 *local_10;
  float local_c;
  undefined *local_8;
  undefined4 local_4;
  
  *param_3 = 0.0;
  *param_4 = 0.0;
  fVar2 = DAT_007372b0;
  if (DAT_0078a400 != 0) {
    fVar7 = (float10)(float)param_1[5] - (float10)(float)param_2[5];
    if ((DAT_0078a368 != 0) || ((DAT_0073465c != 0 && (DAT_0073466c != 0)))) {
      fVar1 = (float)(fVar7 + (float10)_K_HALF);
      fVar7 = (float10)FUN_004387e0(fVar1);
      if ((float10)fVar1 < fVar7) {
        fVar7 = fVar7 - (float10)_K_ONE;
      }
      fVar7 = ((float10)fVar1 - fVar7) - (float10)_K_HALF;
    }
    fVar7 = fVar7 * (float10)fVar2;
    fVar2 = (float)fVar7;
    if (fVar7 < (float10)_DAT_0077a4a0 != (fVar7 == (float10)_DAT_0077a4a0)) {
      iVar6 = 0;
      if (DAT_0078a318 == 0) {
        iVar4 = 1;
        do {
          iVar6 = iVar4;
          if ((int)(&DAT_0070077c)[iVar4] <= DAT_0078a31c) break;
          iVar4 = iVar4 + -1;
          iVar6 = 0;
        } while (-1 < iVar4);
      }
      iVar4 = 0;
      if ((DAT_0078a300 == 2) || (DAT_0078a300 == 3)) {
        iVar4 = 1;
      }
      iVar4 = iVar4 + iVar6 * 2;
      local_10 = &DAT_00779c78 + iVar4 * 0x16;
      local_8 = &DAT_00779dd8 + iVar4 * 0x58;
      local_c = 1.54143e-44;
      local_4 = 0xb;
      fVar7 = (float10)LinearTable__Lookup11(&local_10,fVar2);
      fVar8 = (float10)LinearTable__Lookup11(&local_8,fVar2);
      fVar8 = (fVar8 - (float10)(float)fVar7) * (float10)0.11111111;
      local_10 = (undefined4 *)(float)fVar8;
      local_c = (float)((float10)(float)fVar7 - fVar8 * (float10)0.0);
      uVar5 = (**(code **)(*unaff_EDI + 0x58))();
      fVar1 = (float)(int)(((int)uVar5 < 1) - 1 & uVar5);
      local_c = (float)local_10 * fVar1 + local_c;
      *param_3 = local_c;
      iVar6 = *param_1;
      if (*(int *)(iVar6 + 0x28) == 4) {
        fVar3 = *(float *)(iVar6 + 0x3d0);
      }
      else {
        fVar3 = *(float *)(iVar6 + 0x3d4);
      }
      fVar2 = ((fVar3 - *(float *)(*param_2 + 0x3d4)) * -0.005) / (fVar2 * 0.01 * fVar2 + _K_ONE);
      if (fVar2 <= -0.05) {
        fVar2 = -0.05;
      }
      if (0.05 < fVar2) {
        fVar2 = 0.05;
      }
      *param_3 = local_c + fVar2;
      iVar6 = (int)*(char *)((int)param_2 + 10) - (int)*(char *)((int)param_1 + 10);
      if (iVar6 < 0) {
        iVar6 = iVar6 + 8;
      }
      else {
        iVar6 = iVar6 + 7;
      }
      fVar2 = (*(float *)(&DAT_00779f78 + iVar6 * 4) - *(float *)(&DAT_00779f38 + iVar6 * 4)) *
              0.11111111;
      *param_4 = fVar1 * fVar2 + (*(float *)(&DAT_00779f38 + iVar6 * 4) - fVar2 * 0.0);
    }
  }
  return;
}


// ==== 0x44c250 FUN_0044c250

void __fastcall FUN_0044c250(int *param_1)

{
  undefined4 unaff_ESI;
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined1 auStack_c [4];
  undefined4 uStack_8;
  undefined1 auStack_4 [4];
  
  puVar2 = auStack_c;
  puVar1 = (undefined4 *)param_1[0xf6];
  puVar1[2] = 0xffffffff;
  *puVar1 = 0;
  puVar1[1] = 0;
  param_1[3] = param_1[3] & 0xfffffffe;
  param_1[4] = param_1[4] & 0xfffffffe;
  param_1[5] = param_1[5] & 0xfffffffe;
  param_1[6] = param_1[6] & 0xfffffffe;
  param_1[7] = param_1[7] & 0xfffffffe;
  param_1[8] = param_1[8] & 0xfffffffe;
  param_1[9] = param_1[9] & 0xfffffffe;
  auStack_c[0] = 0;
  param_1[10] = param_1[10] & 0xfffffffe;
  puVar1 = &uStack_8;
  (**(code **)(*param_1 + 0x54))(auStack_4,puVar1,auStack_c);
  FUN_0044adc0(param_1,unaff_ESI,puVar2,puVar1,uStack_8);
  *(undefined1 *)(param_1 + 0x129) = 0xff;
  param_1[0x11e] = -1;
  return;
}


// ==== 0x44c2e0 TrafficCar_HonkAtPlayer

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] traffic med (H) docs/re/traffic.md */

void TrafficCar_HonkAtPlayer(int param_1)

{
  bool bVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  undefined4 uStack00000008;
  undefined4 local_10;
  float local_c;
  
  iVar3 = FUN_00647b70();
  if ((((iVar3 != 6) ||
       (*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x1d4) + 0x90) + 0xc) + 0xc54) != 1)) &&
      ((iVar3 = FUN_00647b70(), iVar3 != 6 ||
       (*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x1d4) + 0x90) + 0x14) + 4) != 3)))) &&
     ((*DAT_007361f0 == 9 || (cVar2 = FUN_0057a6b0(), cVar2 != '\0')))) {
    iVar4 = FUN_0057b520();
    iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x24);
    if (iVar3 == 3) {
      cVar2 = FUN_00456780(iVar4);
      if (cVar2 == '\0') {
        return;
      }
    }
    else if (iVar3 != 4) {
      return;
    }
    local_10 = 0;
    fVar5 = (float10)Random_NextFloat(0x3ecccccd);
    fVar6 = (float10)Random_NextFloat(0x3e4ccccd);
    fVar7 = (float10)Random_NextFloat(0x3ecccccd);
    local_c = (float)((fVar7 + (float10)0.3) - (float10)0.2);
    fVar7 = (float10)Random_NextFloat(0x3f800000);
    bVar1 = fVar7 < (float10)_K_HALF;
    if (*(float *)(iVar4 + 4) <= 50.0) {
      if ((*(int *)(*(int *)(*(int *)(param_1 + 4) + 0x14) + 4) != 3) ||
         (-3.0 <= *(float *)(iVar4 + 4))) {
        FUN_0057a6b0();
      }
    }
    else {
      bVar1 = true;
      local_c = local_c + 0.6;
    }
    fVar7 = (float10)Random_NextFloat(0x3f800000);
    if (extraout_ST1 <= fVar7) {
      uStack00000008 = 0;
    }
    else {
      uStack00000008 = 1;
      fVar7 = (float10)Random_NextFloat(0x3f800000);
      local_10 = 1;
      if (extraout_ST1_00 <= fVar7) {
        local_10 = 0;
      }
    }
    Car__HonkAndOrBlinkHeadlights
              ((float)((fVar5 + (float10)0.3) - (float10)0.2),
               (float)((fVar6 + (float10)0.15) - (float10)0.1),local_c,local_10,uStack00000008,bVar1
              );
  }
  return;
}


// ==== 0x44c550 RacerAI::UpdateDesiredSpeed

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] rivals V (Ghidra+Hopper+capstone) docs/re/rivals.md */

void RacerAI__UpdateDesiredSpeed(int *param_1)

{
  byte bVar1;
  undefined1 uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  float10 fVar9;
  float10 extraout_ST0;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  
  (**(code **)(*(int *)param_1[2] + 0x3c))(param_1[0xfe] + 0x20);
  RacerAI__UpdateRubberBand();
  fVar9 = (float10)0.0;
  fStack_1c = (float)fVar9;
  uVar2 = 1;
  if (*(int *)param_1[0xf6] == 0) {
    fStack_24 = (float)fVar9;
  }
  else if (DAT_007360b8 == 0) {
    if (DAT_00736090 == 0) {
      iVar5 = param_1[0xfe];
      if (*(char *)(iVar5 + 0x1f0) == '\0') {
        fStack_24 = *(float *)(iVar5 + 0x1e4);
        fStack_20 = *(float *)(iVar5 + 0x1e8);
      }
      else {
        uVar4 = (**(code **)(*param_1 + 0x58))();
        if (param_1[0x11e] == -1) {
          iVar5 = SpecialCamCooldown();
          if (iVar5 == 0) {
            if (((-1 < (int)uVar4) && ((int)uVar4 < 10)) &&
               (_DAT_0077a498 < (float)(DAT_0073ad34 - param_1[0x100]) * 0.00025)) {
              bVar1 = (&DAT_0077a048)[uVar4 * 0x54];
              iVar5 = FUN_004216b0((bVar1 + 1) * 2);
              param_1[0x101] = iVar5 - (bVar1 + 1);
              param_1[0x100] = DAT_0073ad34;
            }
            iVar5 = *(int *)param_1[0xf6];
            iVar6 = FUN_004420e0();
            uVar8 = (int)*(short *)(iVar5 + 0x10) - 1;
            uVar7 = (iVar6 + param_1[0x101] < 1) - 1 & iVar6 + param_1[0x101];
            if ((int)uVar8 < (int)uVar7) {
              uVar7 = uVar8;
            }
            iVar6 = FUN_0059bb80();
            fStack_24 = (float)((uint)*(byte *)(uVar7 * 0x88 + iVar6 + 0x2e6 + iVar5) << 0x10) *
                        1.5258789e-05;
            iVar5 = bAlmostEqual_float(fStack_24,0,0x3a83126f);
            if (iVar5 != 0) {
              fStack_24 = 30.0;
            }
            fStack_24 = fStack_24 *
                        *(float *)(&DAT_0077a00c + (uVar4 & ((int)uVar4 < 1) - 1) * 0x54);
          }
          else {
            fStack_24 = 99999.0;
          }
        }
        else {
          iVar5 = FUN_00442110();
          fStack_24 = (float)((uint)*(byte *)(iVar5 + 0x6a + *(int *)(param_1[0xf6] + 8)) << 0x10) *
                      1.5258789e-05;
        }
        fStack_24 = fStack_24 * (float)param_1[0x12e];
        fStack_20 = 0.0;
      }
      uVar2 = *(undefined1 *)(param_1[0xfe] + 0x1f1);
      fStack_1c = *(float *)(param_1[0xfe] + 0x1ec);
      goto LAB_0044c7b7;
    }
    iVar5 = ((int *)param_1[0xf6])[1];
    iVar6 = FUN_0059bb80();
    fStack_24 = (float)((uint)*(byte *)(iVar6 + 0x6a + iVar5) << 0x10) * 1.5258789e-05;
    fVar9 = extraout_ST0;
  }
  else {
    fStack_24 = 15.0;
    fStack_1c = 10.0;
  }
  fStack_20 = (float)fVar9;
LAB_0044c7b7:
  fVar9 = (float10)(**(code **)(*(int *)param_1[0xff] + 0x10))();
  if (fVar9 < (float10)fStack_24) {
    fStack_24 = (float)fVar9;
  }
  (**(code **)(*(int *)param_1[2] + 0x38))(fStack_24,fStack_20,fStack_1c,uVar2);
  if ((param_1[0xfe] != 0) && (*(char *)(param_1[0xfe] + 499) != '\0')) {
    cVar3 = CarState__IsNitrousOn();
    if (cVar3 == '\0') {
      (**(code **)(*param_1 + 0x7c))();
    }
    FUN_004654f0();
  }
  if (*(char *)(param_1[0xfe] + 0x20) < '\x06') {
    FUN_00459ac0(param_1[0xfe] + 0x20,param_1[1],0);
  }
  FUN_00458f10(0,0);
  return;
}


// ==== 0x44c860 FUN_0044c860

void __thiscall FUN_0044c860(int param_1,int param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x28);
  if (iVar1 == 4) {
    uVar2 = _ftol_nocw();
    *(undefined4 *)(param_1 + 0x424) = uVar2;
  }
  if (((param_2 == 0) || (*(int *)(param_2 + 0x18) == 0)) && (param_3 == '\0')) {
    iVar3 = RacerNode__GetControlMode();
  }
  else {
    iVar3 = 1;
  }
  if (iVar3 != iVar1) {
    Car_SetMode();
  }
  if (iVar3 == 1) {
    uVar2 = _ftol_nocw();
    *(undefined4 *)(param_1 + 0x428) = uVar2;
  }
  return;
}


// ==== 0x44c8f0 FUN_0044c8f0

void __thiscall FUN_0044c8f0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 != 0) && (iVar1 != -0x40)) {
    *(undefined4 *)(iVar1 + 0x404) = param_2;
  }
  *(undefined1 *)(param_1 + 0x46c) = 0;
  return;
}


// ==== 0x44c920 FUN_0044c920

void __fastcall FUN_0044c920(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 != 0) && (iVar1 != -0x40)) {
    *(undefined4 *)(iVar1 + 0x404) = 0x3f800000;
  }
  *(undefined1 *)(param_1 + 0x46c) = 1;
  return;
}


// ==== 0x44c940 FUN_0044c940

void FUN_0044c940(void)

{
  int iVar1;
  int unaff_ESI;
  
  if (DAT_006fbf18 == *(short *)(*(int *)(unaff_ESI + 4) + 10)) {
    FUN_00455c50(&DAT_0077a4b0,*(int *)(unaff_ESI + 8) + 0x10);
    if (**(int **)(unaff_ESI + 0x3d8) == 0) {
      FUN_00455c20();
    }
    else {
      FUN_00455d60(&DAT_0077a6d8,*(undefined4 *)(unaff_ESI + 0x3e4),
                   (int)*(char *)(unaff_ESI + 0x4a4));
    }
  }
  iVar1 = *(int *)(unaff_ESI + 0x3e0);
  *(undefined4 *)(iVar1 + 4) = 0;
  *(undefined1 *)(iVar1 + 0x388) = 0xff;
  *(undefined1 *)(unaff_ESI + 0x4bc) = 0;
  return;
}


// ==== 0x44c9c0 FUN_0044c9c0

void __fastcall FUN_0044c9c0(int param_1)

{
  char in_AL;
  undefined4 *puVar1;
  
  if (((in_AL != '\0') && (*(char *)(param_1 + 0x410) == '\0')) &&
     (puVar1 = DAT_0077af20, (undefined4 **)DAT_0077af20 != &DAT_0077af20)) {
    do {
      if (puVar1 == (undefined4 *)0x0) break;
      puVar1 = (undefined4 *)*puVar1;
    } while ((undefined4 **)puVar1 != &DAT_0077af20);
  }
  FUN_0044bcb0();
  (**(code **)(**(int **)(param_1 + 8) + 0x38))(0,0,0,1);
  *(undefined1 *)(param_1 + 0x410) = 1;
  return;
}


// ==== 0x44ca10 Racer::GetSkillLevel

/* [canon] rivals V (capstone+Hopper) docs/re/rivals.md */

int __fastcall Racer__GetSkillLevel(int param_1)

{
  return (int)*(char *)(*(int *)(*(int *)(param_1 + 4) + 0x14) + 0x735);
}


// ==== 0x44ca20 FUN_0044ca20

float10 __fastcall FUN_0044ca20(undefined4 param_1,int param_2)

{
  float local_8;
  undefined1 local_4 [4];
  
  if ((*(int *)(*(int *)(param_2 + 0x3e4) + 4) != 0) && (**(int **)(param_2 + 0x3d8) != 0)) {
    local_8 = 0.0;
    FUN_005a6700(local_4,&local_8,(*(int **)(param_2 + 0x3d8))[2]);
    return (float10)local_8;
  }
  return (float10)0.0;
}


// ==== 0x44ca70 FUN_0044ca70

void FUN_0044ca70(void)

{
  int iVar1;
  int unaff_EBX;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = DAT_0073615c;
  iVar4 = DAT_00736158;
  if (0 < DAT_0073615c) {
    do {
      iVar1 = (int)*(short *)(*(int *)(unaff_EBX + 4) + 10);
      *(undefined1 *)((iVar1 + -0x31) * 0x10 + iVar4) = 0;
      iVar3 = 0;
      do {
        if (*(char *)(iVar4 + 6 + iVar3) == iVar1) {
          FUN_005aaea0();
          break;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 2);
      iVar2 = iVar2 + -1;
      iVar4 = iVar4 + 0x170;
    } while (iVar2 != 0);
  }
  return;
}


// ==== 0x44cac0 FUN_0044cac0

undefined1 FUN_0044cac0(int *param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = param_1[1];
  cVar2 = '\0';
  if (*(int *)(iVar1 + 0x3cc) == 4) {
    iVar4 = (int)*(char *)(*(int *)(iVar1 + 0x3c) + 0x1c);
    iVar5 = 0;
    if (0 < iVar4) {
      do {
        if (cVar2 != '\0') {
          return 0;
        }
        FUN_00468820(iVar5);
        cVar2 = FUN_00466500();
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar4);
      if (cVar2 != '\0') {
        return 0;
      }
    }
    cVar2 = FUN_0044cca0();
    if (cVar2 == '\0') {
      iVar1 = *(int *)(iVar1 + 0x3d8);
      if ((DAT_0078a344 != '\0') || (iVar4 = DAT_00700784, DAT_007361a8 != 0)) {
        uVar3 = (**(code **)(*param_1 + 0x58))();
        iVar4 = (byte)(&DAT_0077a049)[(uVar3 & ((int)uVar3 < 1) - 1) * 0x54] + 1;
      }
      if ((iVar4 <= iVar1) && (cVar2 = FUN_0044cb90(), cVar2 == '\0')) {
        return 1;
      }
    }
  }
  return 0;
}


// ==== 0x44cb90 FUN_0044cb90

uint FUN_0044cb90(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_EAX;
  uint uVar6;
  float local_8;
  
  iVar3 = *(int *)(in_EAX + 4);
  uVar6 = *(uint *)(iVar3 + 0x28);
  iVar4 = *(int *)(iVar3 + 0x3d8);
  if (uVar6 == 1) {
    iVar5 = *(int *)(*(int *)(iVar3 + 0x34) + 0x4c);
    local_8 = *(float *)(iVar5 + 0x7c) + *(float *)(iVar5 + 0xa4 + iVar4 * 4);
    fVar2 = *(float *)(iVar5 + 0x78) + *(float *)(iVar5 + 0x80 + iVar4 * 4);
    if ((DAT_0078a344 == '\0') && (DAT_007361a8 == 0)) {
      uVar6 = *(uint *)(*(int *)(iVar5 + 0x20) + 0x18);
      fVar1 = *(float *)(uVar6 + 4);
    }
    else {
      uVar6 = *(uint *)(*(int *)(iVar5 + 0x20) + 0x18);
      fVar1 = *(float *)(uVar6 + 8);
    }
    uVar6 = uVar6 & 0xffff0000;
    if (fVar1 < fVar2) {
      fVar2 = fVar1;
    }
  }
  else {
    if (uVar6 != 3) goto LAB_0044cc8c;
    uVar6 = *(uint *)(*(int *)(iVar3 + 0x34) + 0x24);
    local_8 = *(float *)(uVar6 + 0x1bc + iVar4 * 4);
    fVar2 = *(float *)(uVar6 + 0x198 + iVar4 * 4);
  }
  fVar2 = (fVar2 - local_8) * 0.95 + local_8;
  fVar1 = DAT_007000e4;
  if (DAT_007000e4 == 100.0) {
    fVar1 = *(float *)(iVar3 + 0x3e0);
  }
  if (local_8 < fVar1) {
    local_8 = fVar1;
  }
  if (fVar2 < local_8) {
    local_8 = fVar2;
  }
  uVar6 = CONCAT22((short)(uVar6 >> 0x10),
                   (ushort)(fVar1 < local_8) << 8 | (ushort)(NAN(fVar1) || NAN(local_8)) << 10 |
                   (ushort)(fVar1 == local_8) << 0xe);
  if (fVar1 != local_8) {
    return CONCAT31((int3)(uVar6 >> 8),1);
  }
LAB_0044cc8c:
  return uVar6 & 0xffffff00;
}


// ==== 0x44cca0 FUN_0044cca0

undefined4 FUN_0044cca0(void)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  int iVar3;
  float *pfVar4;
  int iVar5;
  bool bVar6;
  
  fVar2 = 0.0;
  fVar1 = *(float *)(*(int *)(*(int *)(in_EAX + 4) + 0x40) + 0x1c0);
  iVar5 = 0;
  iVar3 = 0;
  pfVar4 = (float *)(*(int *)(in_EAX + 4) + 0x374);
  do {
    if (fVar1 <= 0.9) {
      if ((fVar1 < 0.1) && (iVar3 != 1)) {
        bVar6 = iVar3 == 0;
        goto LAB_0044ccf0;
      }
LAB_0044ccf2:
      iVar5 = iVar5 + 1;
      fVar2 = ABS(*pfVar4) + fVar2;
    }
    else {
      if (iVar3 == 2) goto LAB_0044ccf2;
      bVar6 = iVar3 == 3;
LAB_0044ccf0:
      if (bVar6) goto LAB_0044ccf2;
    }
    iVar3 = iVar3 + 1;
    pfVar4 = pfVar4 + 2;
    if (3 < iVar3) {
      if (0 < iVar5) {
        fVar2 = fVar2 / (float)iVar5;
      }
      if (2.0 < fVar2) {
        return 1;
      }
      return 0;
    }
  } while( true );
}


// ==== 0x44cd30 FUN_0044cd30

undefined4 * FUN_0044cd30(undefined4 *param_1,undefined4 param_2)

{
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00684fc8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  eh_vector_constructor_iterator(param_1 + 2,0x38,0x10,FUN_0044a300,NullUpdate_ret);
  *param_1 = param_2;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 0xe2) = 0xff;
  param_1[0xe5] = 0xffffffff;
  param_1[0xe3] = 0;
  param_1[0xe4] = 0;
  param_1[0xe6] = 0;
  param_1[0xe7] = 0;
  param_1[0xe8] = 0;
  *(undefined1 *)(param_1 + 0xe9) = 0;
  local_4 = 0;
  param_1[0xea] = 0;
  FUN_00457060(param_1 + 0xea);
  FUN_0044ce60();
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x44cde0 FUN_0044cde0

void FUN_0044cde0(void)

{
  int in_EAX;
  
  eh_vector_destructor_iterator((void *)(in_EAX + 8),0x38,0x10,NullUpdate_ret);
  return;
}


// ==== 0x44ce00 FUN_0044ce00

void FUN_0044ce00(int param_1)

{
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_00684fc8;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  if (*(undefined4 **)(param_1 + 0x3a8) != (undefined4 *)0x0) {
    ExceptionList = &pvStack_c;
    (**(code **)**(undefined4 **)(param_1 + 0x3a8))(1);
  }
  local_4 = 0xffffffff;
  eh_vector_destructor_iterator((void *)(param_1 + 8),0x38,0x10,NullUpdate_ret);
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x44ce60 FUN_0044ce60

void FUN_0044ce60(void)

{
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + 4) = 0;
  *(undefined1 *)(unaff_EDI + 0x388) = 0xff;
  FUN_005a5340();
  *(undefined4 *)(unaff_EDI + 0x38c) = 0;
  *(undefined4 *)(unaff_EDI + 0x390) = 0;
  *(undefined4 *)(unaff_EDI + 0x394) = 0xffffffff;
  *(undefined4 *)(unaff_EDI + 0x398) = 0;
  *(undefined4 *)(unaff_EDI + 0x39c) = 0;
  *(undefined4 *)(unaff_EDI + 0x3a0) = 0;
  *(undefined1 *)(unaff_EDI + 0x3a4) = 0;
  return;
}


// ==== 0x44ceb0 FUN_0044ceb0

void FUN_0044ceb0(void)

{
  int iVar1;
  int in_EAX;
  char cVar2;
  int unaff_EDI;
  
  FUN_00571ea0(0,"DrivingInformation");
  if (*(char *)(in_EAX + 0x3d) != '\0' || *(char *)(in_EAX + 0x3c) != '\0') {
    *(undefined4 *)(unaff_EDI + 4) = 0;
    *(undefined1 *)(unaff_EDI + 0x388) = 0xff;
  }
  FUN_0059ba20(unaff_EDI + 0x38c,in_EAX);
  FUN_0045ac60();
  FUN_005a4f90();
  iVar1 = *(char *)(in_EAX + 0x40) * 0x10 + 0x4c + in_EAX;
  *(int *)(iVar1 + 0xc) = *(int *)(in_EAX + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(in_EAX + 0x40) + -1;
  *(char *)(in_EAX + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(in_EAX + 0x44)) {
    *(undefined4 *)(in_EAX + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x44cf30 FUN_0044cf30

undefined1 FUN_0044cf30(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  float fVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  float10 fVar10;
  undefined1 local_31;
  float local_2c;
  int *local_28;
  int local_24;
  float local_20;
  int local_1c;
  int local_18;
  float local_14;
  
  local_20 = *(float *)(*(int *)(*param_1 + 0x3c) + 0x104) -
             *(float *)(*(int *)(*param_1 + 0x3c) + 0xf4);
  local_28 = param_1 + 0xe3;
  iVar2 = param_2[1];
  local_31 = 1;
  if (param_1[0xe3] == 0) {
    local_24 = 0;
  }
  else {
    local_24 = param_1[0xe5];
  }
  if (*(int *)(param_1[0xea] + 4) == 0) {
    if (param_1[0xe3] != 0) {
      pfVar3 = (float *)param_1[0xe4];
      fVar1 = *(float *)(iVar2 + 100) - pfVar3[1];
      fVar4 = *(float *)(iVar2 + 0x60) - *pfVar3;
      local_14 = fVar4 * pfVar3[3] + fVar1 * pfVar3[4];
      fVar1 = fVar4 * pfVar3[4] - fVar1 * pfVar3[3];
      if (fVar1 <= 0.0) {
        fVar1 = -(fVar1 + pfVar3[9]);
      }
      else {
        fVar1 = fVar1 - pfVar3[10];
      }
      if ((fVar1 < local_20 != (fVar1 == local_20)) && (local_14 <= pfVar3[7])) {
        if (-pfVar3[8] < local_14 == (-pfVar3[8] == local_14)) {
          (**(code **)(*param_2 + 0x2c))(1);
        }
        goto LAB_0044d107;
      }
    }
  }
  else {
    local_2c = 0.0;
    local_1c = 0;
    FUN_005a6700(&local_2c,&local_1c,local_24);
    iVar8 = param_1[0xea];
    local_14 = (float)FUN_005a67d0(local_2c,0);
    local_18 = *(int *)(iVar8 + 8 + (int)local_14 * 4);
    if (*(int *)(iVar8 + 4) == 0) {
      fVar1 = 0.0;
    }
    else {
      fVar1 = *(float *)(*(int *)(iVar8 + 8) + 0x58);
    }
    if (fVar1 - 24.0 <= local_2c) {
      if (*(int *)(iVar8 + 4) == 0) {
        fVar1 = 0.0;
      }
      else {
        fVar1 = *(float *)(*(int *)(iVar8 + 4 + *(int *)(iVar8 + 4) * 4) + 0x58);
      }
      if ((local_2c < fVar1 != (local_2c == fVar1)) &&
         ((fVar10 = (float10)FUN_005a71f0(local_1c),
          fVar10 < (float10)local_20 != (fVar10 == (float10)local_20) ||
          (cVar5 = (**(code **)(*param_2 + 100))(), cVar5 != '\0')))) {
        iVar8 = param_1[0xe5];
        local_1c = FUN_0044a2c0();
        iVar6 = FUN_0044a2a0();
        *local_28 = iVar6;
        local_28[1] = local_1c;
        local_28[2] = iVar8;
        uVar9 = ((char)param_2[0x129] < 1) - 1 & (int)(char)param_2[0x129];
        if ((int)uVar9 <= (int)local_14) {
          local_18 = uVar9 * 4 + 8;
          do {
            if ((*(char *)(*(int *)(local_18 + param_1[0xea]) + 0x60) != '\0') && (8 < local_18)) {
              local_1c = *param_2;
              uVar7 = FUN_005a6d20();
              (**(code **)(local_1c + 0x4c))(uVar7);
            }
            uVar9 = uVar9 + 1;
            local_18 = local_18 + 4;
          } while ((int)uVar9 <= (int)local_14);
        }
        goto LAB_0044d107;
      }
    }
  }
  (**(code **)(*param_2 + 0x2c))(1);
LAB_0044d107:
  if (*local_28 == 0) {
    FUN_005a5340();
    local_31 = 0;
  }
  else {
    fVar10 = (float10)(**(code **)(*param_2 + 0x28))();
    if ((float10)local_20 < fVar10) {
      (**(code **)(*param_2 + 0x68))();
    }
    FUN_005a5730(local_28,iVar2);
    iVar8 = FUN_005a6150(param_1[0xea],iVar2 + 0x60,1);
    *(char *)(param_2 + 0x129) = (char)iVar8;
    if (iVar8 == -1) {
      if (*(char *)(*(int *)(iVar2 + 0x10) + 0x424) == -1) {
        RideInfo__RebuildPhysicsInfo(1);
      }
      FUN_005a5340();
    }
    else {
      cVar5 = FUN_005a75c0(iVar2);
      if (((cVar5 == '\0') && (10 < param_1[0xe5])) && (param_1[0xe5] < 0x17)) {
        local_2c = 1.4013e-45;
        do {
          iVar8 = param_1[0xe5] + (int)local_2c;
          cVar5 = FUN_005a75c0(iVar2);
          if (cVar5 != '\0') {
LAB_0044d337:
            param_1[0xe5] = iVar8;
            param_1[0xe6] = 1;
            param_1[0xe7] = 0;
            *(undefined1 *)(param_1 + 0xe9) = 0;
            param_1[0xe8] = 0;
            goto LAB_0044d2f4;
          }
          iVar8 = param_1[0xe5] - (int)local_2c;
          cVar5 = FUN_005a75c0(iVar2);
          if (cVar5 != '\0') goto LAB_0044d337;
          local_2c = (float)((int)local_2c + 1);
        } while ((int)local_2c < 6);
        uVar7 = (**(code **)(*(int *)param_1[0xea] + 4))(0xff,0xff);
        iVar8 = GetNearestTrafficLane(iVar2,uVar7);
        if (iVar8 != -1) {
          param_1[0xe5] = iVar8;
        }
      }
    }
  }
LAB_0044d2f4:
  if (*(int *)(param_1[0xea] + 4) == 0) {
    param_1[1] = 0;
    *(undefined1 *)(param_1 + 0xe2) = 0xff;
    local_31 = 0;
  }
  else {
    FUN_0057a910(param_1,param_1[0xea],param_1[0xe5]);
    iVar8 = *(int *)(param_1[0xea] + 4);
    if (iVar8 == 0) {
      fVar1 = 0.0;
    }
    else {
      fVar1 = *(float *)(*(int *)(param_1[0xea] + 4 + iVar8 * 4) + 0x58);
    }
    if (fVar1 < (float)param_1[(char)param_1[0xe2] * 0xe + 6]) {
      local_31 = 0;
    }
  }
  if (((DAT_0073608c != 0) && (*local_28 != 0)) &&
     ((*(int *)(*(int *)(iVar2 + 0x14) + 4) == 1 && (*(int *)(iVar2 + 0x24) == 2)))) {
    FUN_0045d920();
  }
  return local_31;
}


// ==== 0x44d3e0 FUN_0044d3e0

undefined4 __fastcall FUN_0044d3e0(int param_1)

{
  int in_EAX;
  
  if (in_EAX != 0) {
    return *(undefined4 *)(param_1 + 0x10 + (uint)*(byte *)(in_EAX + 0x83) * 4);
  }
  return 0;
}


// ==== 0x44d400 FUN_0044d400

undefined1 * FUN_0044d400(void)

{
  return &DAT_006b9172;
}


// ==== 0x44d410 FUN_0044d410

void FUN_0044d410(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = &PTR_FUN_006c97f4;
  return;
}


// ==== 0x44d420 FUN_0044d420

char * FUN_0044d420(void)

{
  return "Avoid Avoidable";
}


// ==== 0x44d430 FUN_0044d430

undefined * FUN_0044d430(void)

{
  return &DAT_006c979c;
}


// ==== 0x44d440 FUN_0044d440

char * FUN_0044d440(void)

{
  return "Just Drive";
}


// ==== 0x44d450 FUN_0044d450

char * FUN_0044d450(void)

{
  return "Pull over";
}


// ==== 0x44d460 FUN_0044d460

char * FUN_0044d460(void)

{
  return "Get Unstuck";
}


// ==== 0x44d470 FUN_0044d470

char * FUN_0044d470(void)

{
  return "I just got hit!";
}


// ==== 0x44d480 FUN_0044d480

char * FUN_0044d480(void)

{
  return "Accident recovery";
}


// ==== 0x44d490 FUN_0044d490

char * FUN_0044d490(void)

{
  return "Block";
}


// ==== 0x44d4a0 FUN_0044d4a0

char * FUN_0044d4a0(void)

{
  return "Drive Traffic Lane";
}


// ==== 0x44d4b0 FUN_0044d4b0

char * FUN_0044d4b0(void)

{
  return "Avoid cross traffic";
}


// ==== 0x44d4c0 FUN_0044d4c0

char * FUN_0044d4c0(void)

{
  return "Avoid Cars as a traffic car";
}


// ==== 0x44d4d0 FUN_0044d4d0

undefined4 * __thiscall FUN_0044d4d0(undefined4 *param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_0044d410();
  iVar2 = DAT_00736098;
  if ((param_2 & 1) != 0) {
    iVar1 = *(int *)(DAT_00736098 + 0x18);
    *param_1 = *(undefined4 *)(DAT_00736098 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = param_1;
  }
  return param_1;
}


// ==== 0x44d500 FUN_0044d500

char * FUN_0044d500(void)

{
  return "I just got hit (in a drag race)!";
}


// ==== 0x44d510 FUN_0044d510

char * FUN_0044d510(void)

{
  return "I just hit a wall (in a drag race)!";
}


// ==== 0x44d520 FUN_0044d520

char * FUN_0044d520(void)

{
  return "End of race";
}


// ==== 0x44d530 FUN_0044d530

void FUN_0044d530(void)

{
  FUN_0044f070();
  return;
}


// ==== 0x44d540 FUN_0044d540

char * FUN_0044d540(void)

{
  return "Obey traffic intersections";
}


// ==== 0x44d550 FUN_0044d550

void FUN_0044d550(void)

{
  FUN_0044f0d0();
  return;
}


// ==== 0x44d560 FUN_0044d560

char * FUN_0044d560(void)

{
  return "Pick route to avoid animation";
}


// ==== 0x44d570 Node_GetIntersection

/* [canon] traffic high (H+G+file) docs/re/traffic.md */

int __fastcall Node_GetIntersection(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *(char *)(param_1 + 0x5c);
  if ((cVar1 != -1) && (*(short *)(param_1 + 0x5e) != -1)) {
    if (cVar1 < 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (&DAT_0077af30)[cVar1];
    }
    return (*(uint *)(*(short *)(param_1 + 0x5e) * 0x88 + iVar2 + 0x300) >> 0x14 & 0x1f) * 0x170 +
           DAT_00736158;
  }
  return 0;
}


// ==== 0x44d5d0 FUN_0044d5d0

int FUN_0044d5d0(void)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(*(int *)(in_EAX + 0x1d4) + 0x1c);
  if (*(int *)(iVar1 + 0xe4) != 0) {
    FUN_005791c0();
  }
  return iVar1 + 0x40;
}


// ==== 0x44d5f0 FUN_0044d5f0

float10 FUN_0044d5f0(void)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(*(int *)(in_EAX + 0x1d4) + 0x1c);
  if (*(int *)(iVar1 + 0xe4) != 0) {
    FUN_005791c0();
  }
  return SQRT((float10)*(float *)(iVar1 + 0x98) * (float10)*(float *)(iVar1 + 0x98) +
              (float10)*(float *)(iVar1 + 0x94) * (float10)*(float *)(iVar1 + 0x94) +
              (float10)*(float *)(iVar1 + 0x90) * (float10)*(float *)(iVar1 + 0x90));
}


// ==== 0x44d640 FUN_0044d640

undefined4 FUN_0044d640(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x3d8);
}


// ==== 0x44d650 FUN_0044d650

void FUN_0044d650(void)

{
  int in_EAX;
  
                    /* WARNING: Could not recover jumptable at 0x0044d658. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_EAX + 0x3fc) + 0xc))();
  return;
}


// ==== 0x44d660 FUN_0044d660

undefined4 FUN_0044d660(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x4e0);
}


// ==== 0x44d670 FUN_0044d670

void __thiscall FUN_0044d670(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIPlan");
  FUN_00571c20(param_2,param_1 + 4,1,1,0);
  FUN_00571c20(param_2,param_1 + 8,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0xc,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x10,1,4,1);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x44d700 FUN_0044d700

void FUN_0044d700(int param_1)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIGoal");
  FUN_0044d670(param_1);
  iVar1 = *(char *)(param_1 + 0x40) * 0x10;
  *(int *)(iVar1 + param_1 + 0x58) = *(int *)(param_1 + 0x150) - *(int *)(iVar1 + 0x58 + param_1);
  cVar2 = *(char *)(param_1 + 0x40) + -1;
  *(char *)(param_1 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_1 + 0x44)) {
    *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x44d760 FUN_0044d760

void FUN_0044d760(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int *unaff_EBX;
  int unaff_EDI;
  char local_5;
  int local_4;
  
  FUN_00571ea0(0,"AIGoalPtr");
  piVar1 = (int *)*unaff_EBX;
  local_5 = piVar1 != (int *)0x0;
  FUN_00571c20(unaff_EDI,&local_5,1,1,1);
  if (local_5 == '\0') goto LAB_0044d857;
  if (piVar1 != (int *)0x0) {
    local_4 = piVar1[5];
  }
  FUN_00571c20(unaff_EDI,&local_4,1,4,1);
  if (*(char *)(unaff_EDI + 0x3d) != '\0') {
    switch(local_4) {
    case 1:
      iVar2 = FUN_00567160();
      if (iVar2 == 0) {
LAB_0044d845:
        piVar1 = (int *)0x0;
      }
      else {
        piVar1 = (int *)FUN_0044a150(0);
      }
      break;
    case 2:
      iVar2 = FUN_00567160();
      if (iVar2 == 0) goto LAB_0044d845;
      piVar1 = (int *)FUN_0044a190(0);
      break;
    case 3:
      iVar2 = FUN_00567160();
      if (iVar2 == 0) goto LAB_0044d845;
      piVar1 = (int *)FUN_0044a1c0(0);
      break;
    case 4:
      iVar2 = FUN_00567160();
      if (iVar2 == 0) goto LAB_0044d845;
      piVar1 = (int *)FUN_0044a200(0);
      break;
    case 5:
      iVar2 = FUN_00567160();
      if (iVar2 == 0) goto LAB_0044d845;
      piVar1 = (int *)FUN_0044a230(0);
    }
    *unaff_EBX = (int)piVar1;
  }
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
LAB_0044d857:
  iVar2 = *(char *)(unaff_EDI + 0x40) * 0x10;
  *(int *)(iVar2 + unaff_EDI + 0x58) =
       *(int *)(unaff_EDI + 0x150) - *(int *)(iVar2 + 0x58 + unaff_EDI);
  cVar3 = *(char *)(unaff_EDI + 0x40) + -1;
  *(char *)(unaff_EDI + 0x40) = cVar3;
  if ((int)cVar3 < *(int *)(unaff_EDI + 0x44)) {
    *(undefined4 *)(unaff_EDI + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x44d8b0 RaceGoal::SelectAction

/* [canon] rivals V (Ghidra+capstone) docs/re/rivals.md */

undefined4 __thiscall RaceGoal__SelectAction(int *param_1,int *param_2,int param_3,float param_4)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  float10 fVar7;
  undefined4 local_38;
  undefined4 local_34;
  int iStack_30;
  undefined4 local_2c;
  uint local_28;
  undefined4 local_24;
  int *local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar5 = (int)param_4;
  piVar2 = param_2;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_006865f8;
  pvStack_c = ExceptionList;
  piVar1 = *(int **)(*param_2 + 0x2c);
  local_38 = 0;
  local_2c = 0;
  local_24 = 0;
  param_2 = (int *)CONCAT31(param_2._1_3_,1);
  local_28 = local_28 & 0xffffff00;
  local_34 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = local_10 & 0xffffff00;
  ExceptionList = &pvStack_c;
  local_20 = param_1;
  if ((((param_3 == 10) || (ExceptionList = &pvStack_c, 500 < (int)param_4)) ||
      (ExceptionList = &pvStack_c, cVar3 = (**(code **)(*piVar1 + 0x6c))(), cVar3 == '\0')) ||
     (iVar4 = FUN_00451b00(piVar2), iVar5 = (int)param_4, iVar4 < 0)) {
    if (((param_3 == 0x13) || (600 < iVar5)) ||
       ((*(int *)(piVar2[0xea] + 0xc0) == -1 || (*(int *)(*(int *)(*piVar2 + 0x2c) + 0x4ec) == 0))))
    {
      if (((param_3 == 0xc) || (400 < iVar5)) ||
         (iVar4 = FUN_0044ed70(piVar2,0xbf800000,1), iVar4 == 0)) {
        if (((param_3 == 2) || (400 < iVar5)) ||
           (iStack_30 = FUN_00452b40(&local_34), iVar5 = (int)param_4, iStack_30 < 0)) {
          if (((param_3 != 1) && (iVar5 < 0x12d)) &&
             (iStack_30 = FUN_0044f8a0(&local_38,&local_1c,&local_34,&param_2,&local_28),
             uVar6 = local_38, -1 < iStack_30)) {
            TrafficCar_HonkAtPlayer(piVar1,piVar2);
            cVar3 = (**(code **)(*piVar1 + 0x74))(uVar6,local_34);
            iVar5 = (int)param_4;
            if (cVar3 != '\0') {
              piVar2[0xe6] = local_1c;
              piVar2[0xe7] = local_18;
              piVar2[0xe8] = local_14;
              piVar2[0xe9] = local_10;
              iVar5 = FUN_00567160();
              if (iVar5 == 0) {
                ExceptionList = pvStack_c;
                return 0;
              }
              param_4 = (float)((uint)param_2 & 0xff);
              uVar6 = FUN_0044f750(0xbf800000,uVar6,(float)(int)param_4,local_28,0);
              ExceptionList = pvStack_c;
              return uVar6;
            }
          }
          if (((param_3 == 0xe) || (500 < iVar5)) ||
             (iVar4 = FUN_00452630(), iVar5 = (int)param_4, iVar4 < 0)) {
            if (((param_3 == 5) ||
                (*(int *)(&DAT_0077a340 + *(char *)(*(int *)(piVar1[1] + 0x14) + 0x736) * 8) < iVar5
                )) || (iVar4 = FUN_00450ec0(&local_24), iVar5 = (int)param_4, iVar4 < 0)) {
              if (((param_3 == 0) || (200 < iVar5)) ||
                 ((iVar5 = FUN_00450730(&local_2c,&local_1c,&param_4), iVar5 < 0 ||
                  (cVar3 = (**(code **)(*piVar1 + 0x74))(local_2c,0xbf800000), cVar3 == '\0')))) {
                uVar6 = (**(code **)(*local_20 + 0x18))();
                ExceptionList = pvStack_c;
                return uVar6;
              }
              piVar2[0xe6] = local_1c;
              piVar2[0xe7] = local_18;
              piVar2[0xe8] = local_14;
              piVar2[0xe9] = local_10;
              iVar5 = FUN_00567160();
              if (iVar5 != 0) {
                uVar6 = FUN_00450660(0x40a00000,local_2c,0);
                ExceptionList = pvStack_c;
                return uVar6;
              }
            }
            else {
              iVar5 = FUN_00567160();
              if (iVar5 != 0) {
                uVar6 = FUN_00450e20(0xbf800000,local_24);
                ExceptionList = pvStack_c;
                return uVar6;
              }
            }
          }
          else {
            iVar5 = FUN_00567160();
            if (iVar5 != 0) {
              uVar6 = FUN_00452570(0xbf800000);
              ExceptionList = pvStack_c;
              return uVar6;
            }
          }
        }
        else {
          (**(code **)(**(int **)(*piVar2 + 0x2c) + 0x58))();
          TrafficCar_HonkAtPlayer(piVar1,piVar2);
          param_4 = (float)FUN_00567160();
          uStack_4 = 0;
          if (param_4 != 0.0) {
            uVar6 = FUN_00452990(param_4,0xbf800000,0x40000000,local_34);
            ExceptionList = pvStack_c;
            return uVar6;
          }
        }
      }
      else {
        uVar6 = *(undefined4 *)(iVar4 + 0x34);
        TrafficCar_HonkAtPlayer(piVar1,piVar2);
        iVar5 = FUN_00567160();
        if (iVar5 != 0) {
          uVar6 = FUN_004521c0(0xbf800000,uVar6);
          ExceptionList = pvStack_c;
          return uVar6;
        }
      }
    }
    else {
      iVar5 = FUN_00567160();
      if (iVar5 != 0) {
        uVar6 = FUN_00454930(0xbf800000);
        ExceptionList = pvStack_c;
        return uVar6;
      }
    }
  }
  else {
    fVar7 = (float10)(**(code **)(*piVar1 + 0x70))();
    param_4 = (float)fVar7;
    piVar1[0x102] = DAT_0073ad34;
    iVar5 = FUN_00567160();
    if (iVar5 != 0) {
      uVar6 = FUN_004519f0(0x40a00000,param_4);
      ExceptionList = pvStack_c;
      return uVar6;
    }
  }
  ExceptionList = pvStack_c;
  return 0;
}


// ==== 0x44dce0 FUN_0044dce0

undefined4 * FUN_0044dce0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00567160();
  if (puVar1 != (undefined4 *)0x0) {
    FUN_0044e2b0(7,0,0xbf800000);
    *puVar1 = &PTR_FUN_006c9374;
    puVar1[0x80] = 0;
    puVar1[0x80] = 0;
    return puVar1;
  }
  return (undefined4 *)0x0;
}


// ==== 0x44dd30 DragGoal::SelectAction

/* [canon] rivals I (Ghidra+capstone) docs/re/rivals.md */

undefined4 * DragGoal__SelectAction(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  float10 fVar7;
  undefined4 local_14;
  int *local_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_006865d8;
  pvStack_c = ExceptionList;
  piVar1 = *(int **)(*param_1 + 0x2c);
  local_14 = 0;
  ExceptionList = &pvStack_c;
  if ((((param_2 == 10) || (ExceptionList = &pvStack_c, 500 < param_3)) ||
      (ExceptionList = &pvStack_c, cVar3 = (**(code **)(*piVar1 + 0x6c))(), cVar3 == '\0')) ||
     (iVar4 = FUN_00451b00(param_1), iVar4 < 0)) {
    if ((*(int *)(param_1[0xea] + 0xc0) == -1) || (*(int *)(*(int *)(*param_1 + 0x2c) + 0x4ec) == 0)
       ) {
      iVar4 = FUN_004534f0();
      if (iVar4 < 0) {
        iVar4 = FUN_0044ed70(param_1,0x41055532,1);
        if (iVar4 == 0) {
          if (((param_2 == 2) || (400 < param_3)) || (iVar4 = FUN_00452b40(&local_14), iVar4 < 0)) {
            puVar5 = (undefined4 *)(**(code **)(*local_10 + 0x18))();
            ExceptionList = pvStack_c;
            return puVar5;
          }
          uVar6 = (**(code **)(**(int **)(*param_1 + 0x2c) + 0x58))();
          uVar2 = *(undefined4 *)(&DAT_0077a008 + (uVar6 & ((int)uVar6 < 1) - 1) * 0x54);
          TrafficCar_HonkAtPlayer(piVar1,param_1);
          iVar4 = FUN_00567160();
          uStack_4 = 0;
          if (iVar4 != 0) {
            puVar5 = (undefined4 *)FUN_00452990(iVar4,0xbf800000,uVar2,local_14);
            ExceptionList = pvStack_c;
            return puVar5;
          }
        }
        else {
          uVar2 = *(undefined4 *)(iVar4 + 0x34);
          iVar4 = FUN_00567160();
          if (iVar4 != 0) {
            puVar5 = (undefined4 *)FUN_00453090(0xbf800000,uVar2);
            ExceptionList = pvStack_c;
            return puVar5;
          }
        }
      }
      else {
        puVar5 = (undefined4 *)FUN_00567160();
        if (puVar5 != (undefined4 *)0x0) {
          FUN_0044e2b0(0x10,iVar4,0xbf800000);
          *puVar5 = &PTR_FUN_006c9194;
          ExceptionList = pvStack_c;
          return puVar5;
        }
      }
    }
    else {
      puVar5 = (undefined4 *)FUN_00567160();
      if (puVar5 != (undefined4 *)0x0) {
        FUN_0044e2b0(0x13,600,0xbf800000);
        *puVar5 = &PTR_FUN_006c91e4;
        *(undefined1 *)(puVar5 + 0x80) = 0;
        ExceptionList = pvStack_c;
        return puVar5;
      }
    }
  }
  else {
    fVar7 = (float10)(**(code **)(*piVar1 + 0x70))();
    piVar1[0x102] = DAT_0073ad34;
    iVar4 = FUN_00567160();
    if (iVar4 != 0) {
      puVar5 = (undefined4 *)FUN_004519f0(0x40a00000,(float)fVar7);
      ExceptionList = pvStack_c;
      return puVar5;
    }
  }
  ExceptionList = pvStack_c;
  return (undefined4 *)0x0;
}


// ==== 0x44df70 FUN_0044df70

undefined4 * __thiscall FUN_0044df70(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = FUN_004534f0();
  if (iVar2 < 0) {
    iVar2 = FUN_0044ed70(param_2,0x41055532,1);
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)(**(code **)(*param_1 + 0x18))();
      return puVar3;
    }
    uVar1 = *(undefined4 *)(iVar2 + 0x34);
    puVar3 = (undefined4 *)FUN_00567160();
    if (puVar3 != (undefined4 *)0x0) {
      FUN_0044e2b0(0xd,400,0xbf800000);
      puVar3[0x80] = uVar1;
      *puVar3 = &PTR_FUN_006c92fc;
      return puVar3;
    }
  }
  else {
    puVar3 = (undefined4 *)FUN_00567160();
    if (puVar3 != (undefined4 *)0x0) {
      FUN_0044e2b0(0x10,iVar2,0xbf800000);
      *puVar3 = &PTR_FUN_006c9194;
      return puVar3;
    }
  }
  return (undefined4 *)0x0;
}


// ==== 0x44e000 FUN_0044e000

undefined4 FUN_0044e000(void)

{
  return 0;
}


// ==== 0x44e020 TrafficGoal_Select_BeTraffic

/* [canon] traffic high (H+C) docs/re/traffic.md */

undefined4 __thiscall
TrafficGoal_Select_BeTraffic(int *param_1,int *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  int *piStack_4;
  
  uVar3 = *(undefined4 *)(*param_2 + 0x2c);
  uStack_10 = 0;
  uStack_8 = 0;
  uStack_c = 0;
  piStack_4 = param_1;
  if (((param_3 != 0x12) && (param_4 < 0x259)) && (iVar2 = Finder_ObeyIntersections(), -1 < iVar2))
  {
    iVar2 = FUN_00567160();
    if (iVar2 == 0) {
      return 0;
    }
    uVar3 = FUN_00454170(0xbf800000,0,0);
    return uVar3;
  }
  if (((param_3 != 3) && (param_4 < 0x12d)) &&
     (iVar2 = Finder_AvoidAsTraffic(&uStack_10,&uStack_8,&uStack_c), uVar1 = uStack_10, -1 < iVar2))
  {
    TrafficCar_HonkAtPlayer(uVar3,param_2);
    iVar2 = FUN_00567160();
    if (iVar2 == 0) {
      return 0;
    }
    uVar3 = FUN_00453860(0xbf800000,uVar1,uStack_8,uStack_c);
    return uVar3;
  }
  uVar3 = (**(code **)(*piStack_4 + 0x18))();
  return uVar3;
}


// ==== 0x44e140 TrafficGoal_Select_BeAmbient

/* [canon] traffic high (H+C) docs/re/traffic.md */

undefined4 __thiscall
TrafficGoal_Select_BeAmbient(int *param_1,int *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  int *piStack_4;
  
  uVar3 = *(undefined4 *)(*param_2 + 0x2c);
  uStack_10 = 0;
  uStack_8 = 0;
  uStack_c = 0;
  piStack_4 = param_1;
  if (((param_3 != 0x12) && (param_4 < 0x259)) && (iVar2 = Finder_ObeyIntersections(), -1 < iVar2))
  {
    iVar2 = FUN_00567160();
    if (iVar2 == 0) {
      return 0;
    }
    uVar3 = FUN_00454170(0xbf800000,0,0);
    return uVar3;
  }
  if (((param_3 != 3) && (param_4 < 0x12d)) &&
     (iVar2 = Finder_AvoidAsTraffic(&uStack_10,&uStack_8,&uStack_c), uVar1 = uStack_10, -1 < iVar2))
  {
    TrafficCar_HonkAtPlayer(uVar3,param_2);
    iVar2 = FUN_00567160();
    if (iVar2 == 0) {
      return 0;
    }
    uVar3 = FUN_00453860(0xbf800000,uVar1,uStack_8,uStack_c);
    return uVar3;
  }
  uVar3 = (**(code **)(*piStack_4 + 0x18))();
  return uVar3;
}


// ==== 0x44e260 FUN_0044e260

undefined4 * FUN_0044e260(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00567160();
  if (puVar1 != (undefined4 *)0x0) {
    FUN_0044e2b0(8,0,0xbf800000);
    *puVar1 = &PTR_FUN_006c920c;
    puVar1[0x80] = 0;
    puVar1[0x80] = 0;
    return puVar1;
  }
  return (undefined4 *)0x0;
}


// ==== 0x44e2b0 FUN_0044e2b0

void FUN_0044e2b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_EAX;
  int iVar1;
  undefined4 *puVar2;
  
  FUN_0044a080(param_3);
  *in_EAX = &PTR_FUN_006c91bc;
  in_EAX[0x71] = 0;
  in_EAX[0x72] = 0;
  puVar2 = in_EAX + 8;
  for (iVar1 = 0x70; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  FUN_00458f10(0,0);
  *(undefined1 *)(in_EAX + 0x7c) = 1;
  *(undefined1 *)((int)in_EAX + 0x1f2) = 1;
  *(undefined1 *)((int)in_EAX + 0x1f1) = 1;
  in_EAX[4] = 0;
  in_EAX[0x79] = 0;
  in_EAX[0x7b] = 0;
  in_EAX[0x7a] = 0;
  *(undefined1 *)((int)in_EAX + 499) = 0;
  in_EAX[0x7e] = param_1;
  in_EAX[0x7d] = param_2;
  return;
}


// ==== 0x44e340 FUN_0044e340

void FUN_0044e340(byte param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)FUN_0044a170();
  iVar2 = DAT_00736098;
  if ((param_1 & 1) != 0) {
    iVar1 = *(int *)(DAT_00736098 + 0x18);
    *puVar3 = *(undefined4 *)(DAT_00736098 + 0x10);
    *(int *)(iVar2 + 0x18) = iVar1 + -1;
    *(undefined4 **)(iVar2 + 0x10) = puVar3;
  }
  return;
}


// ==== 0x44e370 FUN_0044e370

void __thiscall FUN_0044e370(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIAction");
  FUN_00458dc0();
  FUN_00571c20(param_2,param_1 + 0x1e4,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x1ec,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x1e8,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x1f0,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x1f2,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x1e0,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x1f1,1,1,0);
  FUN_00571c20(param_2,param_1 + 499,1,1,0);
  FUN_00571c20(param_2,param_1 + 500,4,4,1);
  FUN_0044d670(param_2);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10 + 0x4c + param_2;
  *(int *)(iVar1 + 0xc) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x44e480 FUN_0044e480

void FUN_0044e480(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  int unaff_EBX;
  int local_14;
  int local_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  piVar1 = param_1;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006865b8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00571ea0(0,"AIActionPtr");
  piVar2 = (int *)*piVar1;
  param_1 = (int *)CONCAT31(param_1._1_3_,piVar2 != (int *)0x0);
  FUN_00571c20(unaff_EBX,&param_1,1,1,1);
  if ((char)param_1 == '\0') goto LAB_0044e7ba;
  if (piVar2 != (int *)0x0) {
    local_14 = piVar2[0x7e];
  }
  FUN_00571c20(unaff_EBX,&local_14,1,4,1);
  if (*(char *)(unaff_EBX + 0x3d) != '\0') {
    switch(local_14) {
    case 0:
      iVar3 = FUN_00567160();
      if (iVar3 == 0) {
LAB_0044e7a6:
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = (int *)FUN_00450660(0,0,0);
      }
      break;
    case 1:
      iVar3 = FUN_00567160();
      if (iVar3 == 0) goto LAB_0044e7a6;
      piVar2 = (int *)FUN_0044f750(0,0,0,0,0);
      break;
    case 2:
      local_10 = FUN_00567160();
      local_4 = 0;
      if (local_10 == 0) {
        piVar2 = (int *)0x0;
        local_4 = 0xffffffff;
      }
      else {
        piVar2 = (int *)FUN_00452990(local_10,0,0,0);
        local_4 = 0xffffffff;
      }
      break;
    case 3:
      iVar3 = FUN_00567160();
      if (iVar3 == 0) goto LAB_0044e7a6;
      piVar2 = (int *)FUN_00453860(0,0,0,0);
      break;
    case 4:
      iVar3 = FUN_00567160();
      if (iVar3 == 0) goto LAB_0044e7a6;
      piVar2 = (int *)FUN_00450400(0);
      break;
    case 5:
      iVar3 = FUN_00567160();
      if (iVar3 == 0) goto LAB_0044e7a6;
      piVar2 = (int *)FUN_00450e20(0,0);
      break;
    case 6:
      iVar3 = FUN_00567160();
      if (iVar3 == 0) goto LAB_0044e7a6;
      piVar2 = (int *)FUN_00450d20(0,0);
      break;
    case 7:
      iVar3 = FUN_00567160();
      if (iVar3 == 0) goto LAB_0044e7a6;
      piVar2 = (int *)FUN_00450170(0);
      break;
    case 8:
      iVar3 = FUN_00567160();
      if (iVar3 == 0) goto LAB_0044e7a6;
      piVar2 = (int *)FUN_004527d0(0);
      break;
    case 9:
      iVar3 = FUN_00567160();
      if (iVar3 == 0) goto LAB_0044e7a6;
      piVar2 = (int *)FUN_00451400(0,0);
      break;
    case 10:
      iVar3 = FUN_00567160();
      if (iVar3 == 0) goto LAB_0044e7a6;
      piVar2 = (int *)FUN_004519f0(0,0xbf800000);
      break;
    case 0xb:
    case 0xf:
      break;
    case 0xc:
      iVar3 = FUN_00567160();
      if (iVar3 == 0) goto LAB_0044e7a6;
      piVar2 = (int *)FUN_004521c0(0,0);
      break;
    case 0xd:
      iVar3 = FUN_00567160();
      if (iVar3 == 0) goto LAB_0044e7a6;
      piVar2 = (int *)FUN_00453090(0,0);
      break;
    case 0xe:
      iVar3 = FUN_00567160();
      if (iVar3 == 0) goto LAB_0044e7a6;
      piVar2 = (int *)FUN_00452570(0);
      break;
    case 0x10:
      iVar3 = FUN_00567160();
      if (iVar3 == 0) goto LAB_0044e7a6;
      piVar2 = (int *)FUN_00453470(0);
      break;
    case 0x11:
      iVar3 = FUN_00567160();
      if (iVar3 == 0) goto LAB_0044e7a6;
      piVar2 = (int *)FUN_00453730(0,0);
      break;
    case 0x12:
      iVar3 = FUN_00567160();
      if (iVar3 == 0) goto LAB_0044e7a6;
      piVar2 = (int *)FUN_00454170(0,0,0);
      break;
    case 0x13:
      iVar3 = FUN_00567160();
      if (iVar3 == 0) goto LAB_0044e7a6;
      piVar2 = (int *)FUN_00454930(0);
      break;
    default:
      goto switchD_0044e50d_default;
    }
switchD_0044e50d_default:
    *piVar1 = (int)piVar2;
  }
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))();
  }
LAB_0044e7ba:
  iVar3 = *(char *)(unaff_EBX + 0x40) * 0x10;
  *(int *)(iVar3 + unaff_EBX + 0x58) =
       *(int *)(unaff_EBX + 0x150) - *(int *)(iVar3 + 0x58 + unaff_EBX);
  cVar4 = *(char *)(unaff_EBX + 0x40) + -1;
  *(char *)(unaff_EBX + 0x40) = cVar4;
  if ((int)cVar4 < *(int *)(unaff_EBX + 0x44)) {
    *(undefined4 *)(unaff_EBX + 0x44) = 0xffffffff;
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== 0x44e850 FUN_0044e850

void FUN_0044e850(int param_1,float param_2)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int unaff_EBX;
  int unaff_EDI;
  
  cVar2 = *(char *)(unaff_EDI + 0x388);
  iVar3 = *(int *)(*(int *)(*(int *)(unaff_EBX + 0x34) + 0x1d4) + 0x1c);
  if (*(int *)(iVar3 + 0xe4) != 0) {
    FUN_005791c0();
  }
  *(float *)(param_1 + 0x1e4) =
       SQRT(*(float *)(iVar3 + 0x98) * *(float *)(iVar3 + 0x98) +
            *(float *)(iVar3 + 0x94) * *(float *)(iVar3 + 0x94) +
            *(float *)(iVar3 + 0x90) * *(float *)(iVar3 + 0x90)) - param_2;
  if (ABS(*(float *)(unaff_EBX + 4)) <= 0.01) {
    *(undefined4 *)(param_1 + 0x1e8) = 0x47c34f80;
  }
  else {
    *(float *)(param_1 + 0x1e8) =
         (((*(float *)(unaff_EBX + 0x10) -
           *(float *)(*(char *)(unaff_EDI + 0x388) * 0x38 + 0x18 + unaff_EDI)) -
          *(float *)(cVar2 * 0x38 + unaff_EDI + 0x14)) - *(float *)(unaff_EBX + 0xc)) /
         *(float *)(unaff_EBX + 4);
  }
  fVar1 = *(float *)(param_1 + 0x1e4);
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
  }
  *(float *)(param_1 + 0x1e4) = fVar1;
  if (0.1 < *(float *)(param_1 + 0x1e8)) {
    *(float *)(param_1 + 0x1e8) = *(float *)(param_1 + 0x1e8);
    return;
  }
  *(undefined4 *)(param_1 + 0x1e8) = 0x3dcccccd;
  return;
}


// ==== 0x44e950 FUN_0044e950

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0044e950(int param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  iVar3 = *(int *)(param_1 + 0x20);
  fVar4 = (*(float *)(iVar3 + 0x268) + *(float *)(iVar3 + 0x264)) * ABS(*(float *)(param_1 + 0x3d4))
          * _K_HALF;
  fVar6 = _DAT_007000ac * *(float *)(iVar3 + 0x110);
  fVar5 = (*(float *)(iVar3 + 0xfc) + *(float *)(iVar3 + 0xdc)) * _K_HALF;
  fVar1 = *(float *)(iVar3 + 0x110);
  fVar2 = *(float *)(param_1 + 0x3d4);
  *(float *)(param_2 + 0x1e8) = param_3;
  *(float *)(param_2 + 0x1e4) = -((fVar5 * (fVar6 + fVar4)) / fVar1) * param_3 + fVar2;
  return;
}


// ==== 0x44e9c0 FUN_0044e9c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0044e9c0(undefined4 param_1,int param_2,char param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  char cVar6;
  float *pfVar7;
  float *extraout_EDX;
  int unaff_EDI;
  float10 fVar8;
  float10 fVar9;
  float local_c;
  float local_8;
  float local_4;
  
  local_8 = *(float *)(unaff_EDI + 0x60);
  local_4 = *(float *)(unaff_EDI + 100);
  pfVar7 = *(float **)(param_2 + 4);
  if (ABS(*(float *)(unaff_EDI + 0x3d4)) <= _K_ONE) {
    fVar8 = (float10)FUN_00564b10();
    fVar9 = (float10)FUN_00564b10();
    fVar3 = (local_8 - *extraout_EDX) * extraout_EDX[4] -
            (local_4 - extraout_EDX[1]) * extraout_EDX[3];
    fVar8 = (((float10)(float)fVar8 + (float10)(float)fVar8 + (float10)local_8) -
            (float10)*extraout_EDX) * (float10)extraout_EDX[4] -
            ((fVar9 + fVar9 + (float10)local_4) - (float10)extraout_EDX[1]) *
            (float10)extraout_EDX[3];
    local_8 = fVar3 + extraout_EDX[9];
    fVar1 = (float)((float10)extraout_EDX[10] - fVar8);
    fVar2 = (float)(fVar8 + (float10)extraout_EDX[9]);
    if ((0.0 <= fVar1) || (0.0 <= fVar1 - (extraout_EDX[10] - fVar3))) {
      if (0.0 <= fVar2) {
        return 0;
      }
      if (0.0 <= fVar2 - local_8) {
        return 0;
      }
    }
  }
  else {
    fVar3 = (local_8 - *pfVar7) * pfVar7[4] - (local_4 - pfVar7[1]) * pfVar7[3];
    fVar1 = ((*(float *)(unaff_EDI + 0x70) * 0.1 + local_8) - *pfVar7) * pfVar7[4] -
            ((*(float *)(unaff_EDI + 0x74) * 0.1 + local_4) - pfVar7[1]) * pfVar7[3];
    fVar4 = pfVar7[10] - fVar3;
    fVar3 = fVar3 + pfVar7[9];
    local_8 = pfVar7[10] - fVar1;
    fVar1 = fVar1 + pfVar7[9];
    fVar2 = (fVar1 - fVar3) / 0.1;
    if (((fVar2 <= 0.001) || (fVar4 <= 0.0)) || (fVar3 <= 0.0)) {
      fVar5 = 99999.0;
      if (((0.001 < fVar2) && (fVar5 = 99999.0, 0.0 < fVar3)) && (fVar5 = 99999.0, 0.0 < fVar4)) {
        fVar5 = fVar3 / fVar2;
      }
    }
    else {
      fVar5 = fVar4 / fVar2;
    }
    if ((fVar5 < 1.0 == (fVar5 == 1.0)) && ((0.0 <= fVar4 || (fVar4 <= local_8)))) {
      if (0.0 <= fVar3) {
        return 0;
      }
      if (fVar3 <= fVar1) {
        return 0;
      }
    }
    if (*(float *)(unaff_EDI + 0x3d0) <= 0.0) {
      bNormalize2();
      bNormalize2();
      if (local_8 * fVar1 + local_4 * local_c <= 0.342) {
        return 2;
      }
      return 0;
    }
  }
  if (param_3 != '\0') {
    pfVar7 = (float *)(**(code **)(**(int **)(unaff_EDI + 0x30) + 0x7c))();
    local_8 = *pfVar7;
    local_4 = pfVar7[1];
    FUN_004650d0(&local_8);
    (**(code **)(**(int **)(unaff_EDI + 0x30) + 0x7c))(0x3f000000);
    cVar6 = FUN_004556d0();
    if (cVar6 != '\0') {
      return 0;
    }
  }
  return 1;
}


// ==== 0x44ecd0 FUN_0044ecd0

undefined4 __fastcall FUN_0044ecd0(int param_1)

{
  undefined4 uVar1;
  float local_38;
  float local_34;
  float local_2c;
  float local_1c;
  
  local_1c = *(float *)(*(int *)(param_1 + 0x3c) + 0xf4);
  local_2c = *(float *)(*(int *)(param_1 + 0x3c) + 0x104);
  FUN_004650d0(&local_38);
  if ((local_38 < local_2c * 0.95) && (local_1c * 0.95 < local_38)) {
    if (0.0 < local_34) {
      return 0;
    }
    return 1;
  }
  uVar1 = 3;
  if (local_38 <= 0.0) {
    uVar1 = 2;
  }
  return uVar1;
}


// ==== 0x44ed70 FUN_0044ed70

int * FUN_0044ed70(int *param_1,float param_2,char param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  int *local_10;
  int local_c;
  
  iVar1 = *(int *)(*param_1 + 0x3c);
  local_10 = (int *)0x0;
  local_c = 0;
  piVar6 = (int *)0x0;
  if ('\0' < *(char *)(iVar1 + 0x1c)) {
    do {
      iVar5 = FUN_00468820(local_c);
      if (param_2 <= *(float *)(iVar5 + 0x60)) {
        iVar5 = *(int *)(iVar5 + 100);
        cVar4 = *(char *)(*(int *)(iVar5 + 600) + 0x15);
        if ((cVar4 == '\0') && (*(char *)(*(int *)(iVar5 + 0x25c) + 0x15) == '\0')) {
          iVar7 = *(int *)(*(int *)(iVar5 + 600) + 0x140);
          if (iVar7 == *param_1) {
            iVar7 = *(int *)(*(int *)(iVar5 + 0x25c) + 0x140);
          }
          iVar5 = FUN_0057b4e0(iVar7);
          if (iVar5 != -1) {
            piVar6 = param_1 + iVar5 * 0xe + 2;
LAB_0044ee58:
            if (piVar6 != (int *)0x0) {
              if (param_3 != '\0') {
                iVar5 = piVar6[0xd];
                iVar7 = FUN_00647b70();
                if ((iVar7 != 6) || (*(int *)(*(int *)(*(int *)(iVar5 + 0x1d4) + 0x90) + 0x1c) == 0)
                   ) goto LAB_0044ef9e;
              }
              if (local_10 != (int *)0x0) {
                iVar5 = piVar6[0xd];
                iVar7 = FUN_00647b70();
                if (((iVar7 != 6) ||
                    (*(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 0x1d4) + 0x90) + 0x14) + 4) != 1))
                   || (cVar4 = FUN_0057a6b0(), cVar4 != '\0')) {
                  iVar5 = piVar6[0xd];
                  bVar8 = false;
                  iVar7 = FUN_00647b70();
                  if (iVar7 == 6) {
                    bVar8 = *(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 0x1d4) + 0x90) + 0x14) + 4)
                            == 1;
                  }
                  iVar5 = local_10[0xd];
                  bVar9 = false;
                  iVar7 = FUN_00647b70();
                  if (iVar7 == 6) {
                    bVar9 = *(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 0x1d4) + 0x90) + 0x14) + 4)
                            == 1;
                  }
                  if (bVar8 == bVar9) {
                    fVar2 = (float)local_10[4] - (float)param_1[(char)param_1[0xe2] * 0xe + 6];
                    fVar3 = (float)piVar6[4] - (float)param_1[(char)param_1[0xe2] * 0xe + 6];
                    if (((fVar2 < 0.0) && (0.0 < fVar3)) || (fVar3 < fVar2)) goto LAB_0044ef9a;
                  }
                  goto LAB_0044ef9e;
                }
              }
LAB_0044ef9a:
              local_10 = piVar6;
            }
          }
        }
        else {
          if (cVar4 == '\0') {
            bVar8 = *(char *)(*(int *)(iVar5 + 0x25c) + 0x15) == '\x04';
          }
          else {
            if (cVar4 != '\x04') goto LAB_0044ef9e;
            bVar8 = *(char *)(*(int *)(iVar5 + 0x25c) + 0x15) == '\0';
          }
          if (bVar8) {
            FUN_00466450();
            piVar6 = (int *)FUN_0057b550();
            goto LAB_0044ee58;
          }
        }
      }
LAB_0044ef9e:
      local_c = local_c + 1;
      piVar6 = local_10;
    } while (local_c < *(char *)(iVar1 + 0x1c));
  }
  return piVar6;
}


// ==== 0x44efd0 TrafficCar_IsIntersectionObstacle

/* [canon] traffic med (G) docs/re/traffic.md */

undefined4 TrafficCar_IsIntersectionObstacle(int param_1)

{
  int iVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  
  iVar1 = *(int *)(in_EAX + 0x3a8);
  iVar3 = FUN_00647b70();
  if ((((iVar3 == 6) &&
       (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x1d4) + 0x90) + 0x14) + 4) == 3)) &&
      (iVar3 = *(int *)(iVar1 + 0xb8), iVar3 != -1)) && (*(int *)(iVar1 + 8 + iVar3 * 4) != 0)) {
    Node_GetIntersection();
    FUN_00647b70();
    cVar2 = FUN_005aad10();
    if (cVar2 == '\0') {
      return 1;
    }
    return 0;
  }
  return 1;
}


// ==== 0x44f070 FUN_0044f070

undefined4 FUN_0044f070(void)

{
  int iVar1;
  int *unaff_ESI;
  
  iVar1 = *(int *)(*unaff_ESI + 0x10);
  if (*(char *)(iVar1 + 0x424) == -1) {
    RideInfo__RebuildPhysicsInfo(1);
  }
  iVar1 = (int)*(char *)(iVar1 + 0x424);
  unaff_ESI[0xe5] = iVar1;
  iVar1 = (iVar1 + 1) * 0x34;
  unaff_ESI[0xe6] = 1;
  unaff_ESI[0xe7] = 0;
  *(undefined1 *)(unaff_ESI + 0xe9) = 0;
  unaff_ESI[0xe8] = 0;
  return CONCAT31((int3)((uint)iVar1 >> 8),*(char *)(iVar1 + unaff_ESI[0xe3]) != '\0');
}


// ==== 0x44f0d0 FUN_0044f0d0

undefined4 FUN_0044f0d0(void)

{
  int *in_EAX;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_1d0 [105];
  undefined4 local_2c;
  undefined4 local_28;
  
  iVar2 = in_EAX[0xea];
  local_2c = 0;
  local_28 = 0;
  puVar4 = local_1d0;
  for (iVar3 = 0x70; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  FUN_00458f10(0,0);
  if ((*(int *)(iVar2 + 4) != 0) && (in_EAX[1] != 0)) {
    uVar1 = FUN_0045cff0(local_1d0,in_EAX,DAT_007006ec);
    return uVar1;
  }
  iVar2 = *in_EAX;
  uVar1 = (**(code **)(**(int **)(iVar2 + 0x2c) + 0x40))(0xff,0xff);
  iVar2 = GetNearestTrafficLane(iVar2,uVar1);
  if (iVar2 != -1) {
    in_EAX[0xe5] = iVar2;
    in_EAX[0xe7] = 0;
    *(undefined1 *)(in_EAX + 0xe9) = 0;
    in_EAX[0xe8] = 0;
    in_EAX[0xe6] = 1;
    return 1;
  }
  return 0xffffff00;
}


// ==== 0x44f1b0 FUN_0044f1b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044f1b0(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float10 fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  undefined4 *puVar9;
  int unaff_EDI;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  float fStack_48;
  float local_30;
  float local_2c;
  undefined4 local_28;
  float local_20;
  float local_1c;
  undefined4 local_18;
  
  *param_2 = 99999.0;
  *param_3 = 99999.0;
  iVar8 = *(int *)(param_1 + 0x3c);
  local_1c = *(float *)(iVar8 + 0xf4);
  local_30 = *(float *)(iVar8 + 0x100);
  local_20 = *(float *)(iVar8 + 0xf0);
  local_18 = *(undefined4 *)(iVar8 + 0xf8);
  local_2c = *(float *)(iVar8 + 0x104);
  local_28 = *(undefined4 *)(iVar8 + 0x108);
  fVar1 = (local_2c - local_1c) * _K_HALF;
  fVar2 = (local_30 - local_20) * _K_HALF;
  iVar8 = (**(code **)(**(int **)(unaff_EDI + 0x1d4) + 0x28))();
  if (iVar8 == 0) {
    fVar5 = 0.0;
    local_1c = 0.0;
    local_30 = 0.0;
    local_2c = 0.0;
  }
  else {
    FUN_00576f30();
    fVar5 = local_20;
  }
  fVar5 = (local_30 - fVar5) * _K_HALF;
  puVar9 = (undefined4 *)FUN_00578730();
  iVar8 = FUN_00578730();
  Atan2ToAngle16(*puVar9,*(undefined4 *)(iVar8 + 4));
  fVar10 = (float10)FUN_00564b10();
  fVar11 = (float10)local_2c;
  fVar4 = (float10)local_1c;
  fVar3 = (float10)_K_HALF;
  fVar12 = (float10)_K_ONE;
  if (*(int *)(*(int *)(*(int *)(unaff_EDI + 0x1d4) + 0x1c) + 0xe4) != 0) {
    FUN_005791c0();
  }
  FUN_004650d0(&local_30);
  fStack_48 = 99999.0;
  if ((0.0 <= local_2c) &&
     (ABS(local_30) <=
      (float)((fVar12 - fVar10 * fVar10) * (float10)fVar5 +
             (fVar11 - fVar4) * fVar3 * fVar10 * fVar10) + fVar1)) {
    fStack_48 = (local_2c - fVar5) - fVar2;
    if (fStack_48 <= 0.0) {
      fStack_48 = 0.0;
    }
    *param_2 = fStack_48;
  }
  if (0.1 < *(float *)(param_1 + 0x3d4)) {
    fVar1 = *(float *)(param_1 + 0x70);
    iVar8 = *(int *)(*(int *)(unaff_EDI + 0x1d4) + 0x1c);
    fVar2 = *(float *)(param_1 + 0x74);
    if (*(int *)(iVar8 + 0xe4) != 0) {
      FUN_005791c0();
    }
    fVar5 = ((*(float *)(iVar8 + 0x90) - fVar1) * fVar1 + fVar2 * (*(float *)(iVar8 + 0x94) - fVar2)
            ) / (fVar1 * fVar1 + fVar2 * fVar2);
    fVar6 = fVar1 * fVar5;
    fVar5 = fVar2 * fVar5;
    fVar7 = SQRT(fVar6 * fVar6 + fVar5 * fVar5);
    if ((fVar6 * fVar1 + fVar2 * fVar5 < 0.0) && (0.001 < fVar7)) {
      *param_3 = fStack_48 / fVar7;
    }
  }
  return;
}


// ==== 0x44f470 FUN_0044f470

float __thiscall
FUN_0044f470(int *param_1,int param_2,float param_3,float param_4,float *param_5,float *param_6)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  int local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  *param_5 = -1.0;
  iVar2 = (int)(char)param_1[0xe2];
  local_1c = *param_1;
  local_c = (float)param_1[iVar2 * 0xe + 4];
  local_4 = (float)param_1[iVar2 * 0xe + 5];
  local_8 = (float)param_1[iVar2 * 0xe + 6];
  iVar2 = iVar2 + -1;
  local_10 = 0.0;
  local_18 = 99999.0;
  local_14 = 99999.0;
  if (-1 < iVar2) {
    pfVar3 = (float *)(param_1 + iVar2 * 0xe + 4);
    do {
      if ((param_2 < 0) || (4 < param_2)) {
        if ((param_2 < 0xb) || (0x10 < param_2)) {
          fVar1 = 0.0;
        }
        else {
          fVar1 = pfVar3[param_2 + -7];
        }
      }
      else {
        fVar1 = pfVar3[3];
      }
      if (ABS(fVar1 - param_3) <= local_c + 0.5 + *pfVar3) {
        local_30 = ((pfVar3[2] - pfVar3[1]) - local_8) - local_4;
        if (local_30 <= 0.0) {
          local_30 = 0.0;
        }
        if (-0.01 <= pfVar3[-1]) {
          local_24 = 99999.0;
        }
        else {
          local_24 = local_30 / ABS(pfVar3[-1]);
        }
        local_2c = 99999.0;
        local_20 = 99999.0;
        FUN_0044f1b0(local_1c,&local_2c,&local_20);
        if (local_24 < local_20) {
          local_20 = local_24;
        }
        if (local_2c <= local_30) {
          local_28 = local_2c;
        }
        else {
          local_28 = local_30;
        }
        if (((local_30 < param_4 != (local_30 == param_4)) ||
            (local_2c < param_4 != (local_2c == param_4))) ||
           (((local_30 < 20.0 != (local_30 == 20.0) || (local_2c < 20.0 != (local_2c == 20.0))) &&
            (*(float *)(local_1c + 0x3d4) < 0.1)))) {
          local_20 = 0.0;
        }
        else if (99999.0 <= local_20) goto LAB_0044f668;
        local_10 = pfVar3[0xb];
        local_14 = local_28;
        local_18 = local_20;
        break;
      }
LAB_0044f668:
      iVar2 = iVar2 + -1;
      pfVar3 = pfVar3 + -0xe;
    } while (-1 < iVar2);
  }
  *param_5 = local_18;
  *param_6 = local_14;
  return local_10;
}


// ==== 0x44f6c0 FUN_0044f6c0

void FUN_0044f6c0(int param_1)

{
  int *piVar1;
  char cVar2;
  int *unaff_EDI;
  
  *(undefined1 *)(param_1 + 499) = 0;
  if (*(int *)(*(int *)(*unaff_EDI + 0x14) + 4) == 2) {
    piVar1 = *(int **)(*unaff_EDI + 0x2c);
    cVar2 = CarState__IsNitrousOn();
    if ((cVar2 == '\0') && (cVar2 = (**(code **)(*piVar1 + 0x78))(), cVar2 != '\0')) {
      *(undefined1 *)(param_1 + 499) = 1;
    }
  }
  return;
}


// ==== 0x44f700 FUN_0044f700

void FUN_0044f700(void)

{
  char cVar1;
  int *unaff_ESI;
  
  unaff_ESI[4] = 0;
  cVar1 = (**(code **)(*unaff_ESI + 0x24))();
  if (cVar1 != '\0') {
    unaff_ESI[4] = 3;
  }
  cVar1 = (**(code **)(*unaff_ESI + 0x20))();
  if (cVar1 != '\0') {
    unaff_ESI[4] = 2;
  }
  cVar1 = (**(code **)(*unaff_ESI + 0x1c))();
  if (cVar1 != '\0') {
    unaff_ESI[4] = 1;
  }
  return;
}


// ==== 0x44f750 FUN_0044f750

void __thiscall
FUN_0044f750(undefined4 param_1,undefined4 param_2,undefined4 param_3,float param_4,
            undefined1 param_5,undefined1 param_6)

{
  undefined4 *unaff_ESI;
  
  FUN_0044e2b0(1,param_1,param_2);
  *unaff_ESI = &PTR_FUN_006c9324;
  unaff_ESI[0x83] = 0;
  unaff_ESI[0x84] = 0;
  unaff_ESI[0x85] = param_4 + 2.0;
  unaff_ESI[0x80] = param_3;
  unaff_ESI[0x81] = param_4;
  *(undefined1 *)(unaff_ESI + 0x82) = param_5;
  *(undefined1 *)(unaff_ESI + 0x86) = param_6;
  unaff_ESI[0x83] = DAT_0073ad34;
  unaff_ESI[0x84] = DAT_0073ad34;
  return;
}


// ==== 0x44f7d0 FUN_0044f7d0

void __thiscall FUN_0044f7d0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIActionAvoidAvoidable");
  FUN_00571c20(param_2,param_1 + 0x204,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x208,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x218,1,1,0);
  FUN_00571c20(param_2,param_1 + 0x20c,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x210,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x214,4,0xffffffff,0);
  FUN_0044e370(param_2);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x44f8a0 FUN_0044f8a0

undefined4
FUN_0044f8a0(int *param_1,int *param_2,float *param_3,undefined1 *param_4,undefined1 *param_5)

{
  int *piVar1;
  int *piVar2;
  float fVar3;
  undefined1 uVar4;
  char cVar5;
  int *in_EAX;
  int iVar6;
  float *pfVar7;
  undefined4 *puVar8;
  float10 fVar9;
  float local_1dc;
  undefined4 local_1d8;
  float local_1d4;
  undefined4 local_1d0 [105];
  undefined4 local_2c;
  undefined4 local_28;
  
  local_2c = 0;
  local_28 = 0;
  puVar8 = local_1d0;
  for (iVar6 = 0x70; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  piVar1 = in_EAX + 0xe6;
  FUN_00458f10(0,0);
  FUN_00458f10(0,0);
  *param_4 = 0;
  *param_5 = 0;
  *param_3 = 99999.0;
  local_1d8 = 0xffffffff;
  local_1dc = 99999.0;
  iVar6 = FUN_00457590(&DAT_0077a4ac,*(int *)(*in_EAX + 0x30) + 0x10,in_EAX + 0xe3,DAT_007006ec,
                       &local_1dc);
  if ((iVar6 != 0) && (local_1dc < DAT_007006ec)) {
    *param_1 = iVar6;
    *param_3 = local_1dc;
    *param_2 = *piVar1;
    param_2[1] = in_EAX[0xe7];
    param_2[2] = in_EAX[0xe8];
    param_2[3] = in_EAX[0xe9];
    uVar4 = FUN_0045b150(param_2,local_1d0,in_EAX,DAT_007006ec,param_5,1);
    *param_4 = uVar4;
    return 300;
  }
  if ((1 < *piVar1) && (*piVar1 < 4)) {
    local_1dc = (float)in_EAX[0xe7];
    iVar6 = 0;
    if (0 < in_EAX[1]) {
      pfVar7 = (float *)(in_EAX + 0xf);
      while (*pfVar7 != local_1dc) {
        iVar6 = iVar6 + 1;
        pfVar7 = pfVar7 + 0xe;
        if (in_EAX[1] <= iVar6) {
          return local_1d8;
        }
      }
      if (((iVar6 != -1) && (piVar2 = in_EAX + iVar6 * 0xe + 2, piVar2 != (int *)0x0)) &&
         (cVar5 = FUN_00456780(piVar2), cVar5 != '\0')) {
        local_1d4 = 99999.0;
        if (ABS((float)piVar2[1]) <= 0.01) {
          FUN_0044d5d0();
          fVar9 = (float10)bDistance3();
          fVar3 = local_1d4;
          if (fVar9 < (float10)10.0) {
            fVar3 = DAT_007006ec;
          }
        }
        else {
          fVar3 = ((float)piVar2[4] - (float)in_EAX[(char)in_EAX[0xe2] * 0xe + 6]) /
                  (float)piVar2[1] + 0.3;
        }
        if (fVar3 < DAT_007006ec + 2.0 != (fVar3 == DAT_007006ec + 2.0)) {
          *param_1 = in_EAX[0xe7];
          *param_3 = fVar3;
          *param_2 = *piVar1;
          param_2[1] = in_EAX[0xe7];
          param_2[2] = in_EAX[0xe8];
          param_2[3] = in_EAX[0xe9];
          *param_4 = 1;
          uVar4 = FUN_0045d5e0();
          *param_5 = uVar4;
          return 300;
        }
      }
    }
  }
  return local_1d8;
}


// ==== 0x44faf0 FUN_0044faf0

int __fastcall FUN_0044faf0(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint3 uVar4;
  
  iVar3 = DAT_0073ad34 - *(int *)(param_1 + 0x210);
  fVar2 = (float)iVar3 * 0.00025;
  fVar1 = *(float *)(param_1 + 0x214);
  uVar4 = (uint3)(CONCAT22((short)((uint)iVar3 >> 0x10),
                           (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                           (ushort)(fVar2 == fVar1) << 0xe) >> 8);
  if (fVar2 < fVar1 != (fVar2 == fVar1)) {
    return (uint)uVar4 << 8;
  }
  return CONCAT31(uVar4,1);
}


// ==== 0x44fb30 FUN_0044fb30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0044fb30(int param_1,int *param_2)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  char cVar9;
  undefined1 uVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  float10 fVar17;
  undefined4 uVar18;
  int *piStack_1c;
  int *piStack_18;
  int iStack_10;
  int iStack_c;
  float fStack_8;
  float fStack_4;
  
  iStack_c = param_2[0xea];
  iVar12 = (int)(char)param_2[0xe2];
  iVar14 = param_2[1];
  piVar1 = param_2 + 0xe6;
  iVar11 = 0;
  if (0 < iVar14) {
    piVar13 = param_2 + 0xf;
    do {
      if (*piVar13 == param_2[0xe7]) {
        if (iVar11 != -1) {
          piStack_18 = param_2 + iVar11 * 0xe + 2;
          goto LAB_0044fb8d;
        }
        break;
      }
      iVar11 = iVar11 + 1;
      piVar13 = piVar13 + 0xe;
    } while (iVar11 < iVar14);
  }
  piStack_18 = (int *)0x0;
LAB_0044fb8d:
  iVar11 = 0;
  if (0 < iVar14) {
    piVar13 = param_2 + 0xf;
    do {
      if (*piVar13 == *(int *)(param_1 + 0x200)) {
        if (iVar11 != -1) {
          piStack_1c = param_2 + iVar11 * 0xe + 2;
          goto LAB_0044fbb8;
        }
        break;
      }
      iVar11 = iVar11 + 1;
      piVar13 = piVar13 + 0xe;
    } while (iVar11 < iVar14);
  }
  piStack_1c = (int *)0x0;
LAB_0044fbb8:
  puVar15 = (undefined4 *)(*(int *)(*param_2 + 0x30) + 0x10);
  puVar16 = (undefined4 *)(param_1 + 0x20);
  for (iVar14 = 0x70; iVar14 != 0; iVar14 = iVar14 + -1) {
    *puVar16 = *puVar15;
    puVar15 = puVar15 + 1;
    puVar16 = puVar16 + 1;
  }
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined1 *)(param_1 + 0x1f0) = 1;
  *(undefined1 *)(param_1 + 0x1f1) = 1;
  FUN_00456780(piStack_1c);
  FUN_00456780(piStack_18);
  bVar8 = false;
  if (piStack_1c != (int *)0x0) {
    if (*(float *)(*param_2 + 0x3d4) < 10.0) {
      fVar17 = (float10)FUN_0044d5f0();
      bVar8 = true;
      if (fVar17 < (float10)5.0) goto LAB_0044fc44;
    }
    bVar8 = false;
  }
LAB_0044fc44:
  bVar7 = false;
  cVar9 = RaceManager__IsInRaceStartWindow(DAT_0073619c,*param_2);
  if (cVar9 == '\0') {
LAB_0044fcc9:
    bVar6 = true;
  }
  else {
    iVar14 = *(int *)(param_1 + 0x200);
    iVar11 = FUN_00647b70();
    if ((iVar11 == 6) &&
       (*(int *)(*(int *)(*(int *)(*(int *)(iVar14 + 0x1d4) + 0x90) + 0x14) + 4) == 1))
    goto LAB_0044fcc9;
    bVar6 = false;
  }
  iStack_10 = DAT_0073ad34 - *(int *)(param_1 + 0x20c);
  if ((0.0 < (float)iStack_10 * 0.00025) && (bVar6)) {
    bVar7 = true;
    if ((*piVar1 == 1) && (bVar8)) {
      if (*(char *)(*(int *)(*param_2 + 0x10) + 0x424) == -1) {
        RideInfo__RebuildPhysicsInfo(1);
      }
      iVar14 = piStack_1c[0xd];
      if (iVar14 != 0) {
        *piVar1 = 2;
        param_2[0xe7] = iVar14;
        *(undefined1 *)(param_2 + 0xe9) = 0;
        param_2[0xe8] = 0;
      }
      cVar9 = FUN_0045b9f0();
      if ((cVar9 == '\0') && (iVar14 = piStack_1c[0xd], iVar14 != 0)) {
        *piVar1 = 3;
        param_2[0xe7] = iVar14;
        *(undefined1 *)(param_2 + 0xe9) = 0;
        param_2[0xe8] = 0;
      }
    }
    uVar18 = DAT_007006ec;
    *(undefined1 *)(param_1 + 0x218) = 0;
    uVar10 = FUN_0045b150(piVar1,param_1 + 0x20,param_2,uVar18,(undefined1 *)(param_1 + 0x218),1);
    *(undefined1 *)(param_1 + 0x208) = uVar10;
    *(int *)(param_1 + 0x20c) = DAT_0073ad34;
    if ((*(char *)(param_1 + 0x208) != '\0') || (20.0 < *(float *)(*param_2 + 0x3d4))) {
      iVar14 = *piVar1;
      if (iVar14 == 1) {
        piStack_18 = (int *)0x0;
      }
      else if ((1 < iVar14) && (iVar14 < 4)) {
        piStack_18 = (int *)FUN_0057b520();
      }
    }
    else {
      FUN_00458f10(0,0);
      *piVar1 = 1;
      param_2[0xe7] = 0;
      *(undefined1 *)(param_2 + 0xe9) = 0;
      param_2[0xe8] = 0;
      iVar14 = *(int *)(iStack_c + 8 + param_2[iVar12 * 0xe + 0xe] * 4);
      iVar11 = param_2[0xe5];
      if ((iVar11 < 0) || (4 < iVar11)) {
        if ((iVar11 < 0xb) || (0x10 < iVar11)) {
          fVar2 = 0.0;
        }
        else {
          fVar2 = *(float *)(iVar14 + -8 + iVar11 * 4);
        }
      }
      else {
        fVar2 = *(float *)(iVar14 + 0x20);
      }
      if ((iVar11 < 0) || (4 < iVar11)) {
        if ((iVar11 < 0xb) || (0x10 < iVar11)) {
          fVar3 = 0.0;
        }
        else {
          fVar3 = (float)param_2[iVar12 * 0xe + iVar11 + -3];
        }
      }
      else {
        fVar3 = (float)param_2[iVar12 * 0xe + 7];
      }
      if ((iVar11 < 0) || (4 < iVar11)) {
        if ((iVar11 < 0xb) || (0x10 < iVar11)) {
          fVar4 = 0.0;
        }
        else {
          fVar4 = *(float *)(iVar14 + 0x14 + iVar11 * 4);
        }
      }
      else {
        fVar4 = *(float *)(iVar14 + 0x3c);
      }
      if ((iVar11 < 0) || (4 < iVar11)) {
        if ((iVar11 < 0xb) || (0x10 < iVar11)) {
          fVar5 = 0.0;
        }
        else {
          fVar5 = (float)param_2[iVar12 * 0xe + iVar11 + -3];
        }
      }
      else {
        fVar5 = (float)param_2[iVar12 * 0xe + 7];
      }
      if (ABS(fVar4 - fVar5) <= ABS(fVar2 - fVar3)) {
        uVar18 = 4;
      }
      else {
        uVar18 = 3;
      }
      FUN_0045c370(param_1 + 0x20,param_2,0,uVar18,0,0x47c34f80);
      *(undefined1 *)(param_1 + 0x208) = 1;
    }
  }
  if (*(char *)(param_1 + 0x20) == '\0') {
LAB_0044ff16:
    if ((*piVar1 == 0) || (cVar9 = FUN_0045ad30(), cVar9 == '\0')) {
LAB_0044ff28:
      *(undefined1 *)(param_1 + 0x208) = 0;
      *piVar1 = 1;
      param_2[0xe7] = 0;
      *(undefined1 *)(param_2 + 0xe9) = 0;
      param_2[0xe8] = 0;
    }
    iStack_10 = -0x40800000;
    iStack_c = 0x47c34f80;
    uVar10 = FUN_0045b050(piVar1,*(undefined1 *)(param_1 + 0x218),&iStack_10,&fStack_8,&iStack_c,0,
                          DAT_007006ec);
    *(undefined1 *)(param_1 + 0x208) = uVar10;
    if (*(char *)(param_1 + 0x20) == '\0') {
      FUN_0045ae10(piVar1,param_1 + 0x20,param_2,0,2);
      *(undefined1 *)(param_1 + 0x208) = 0;
    }
  }
  else {
    if (*piVar1 == 0) goto LAB_0044ff28;
    if (!bVar7) goto LAB_0044ff16;
  }
  if (*(char *)(param_1 + 0x208) != '\0') goto LAB_00450123;
  cVar9 = FUN_00456780(piStack_1c);
  if ((cVar9 == '\0') && (cVar9 = FUN_00456780(piStack_18), cVar9 == '\0')) {
LAB_00450134:
    *(undefined1 *)(param_1 + 0x1e0) = 1;
    return;
  }
  if (piStack_1c == (int *)0x0) goto LAB_00450123;
  cVar9 = FUN_0057a8a0();
  if (cVar9 != '\0') goto LAB_00450134;
  fVar17 = (float10)FUN_0057b480();
  fStack_8 = (float)fVar17;
  fStack_4 = (float)piStack_1c[4] - (float)param_2[(char)param_2[0xe2] * 0xe + 6];
  cVar9 = FUN_0057a6b0();
  if (cVar9 == '\0') {
    if (0.0 < fStack_4) goto LAB_004500b5;
LAB_00450049:
    bVar7 = false;
  }
  else {
    if ((float)piStack_1c[1] * 0.1 + fStack_4 <= (float)param_2[iVar12 * 0xe + 5] * _K_HALF)
    goto LAB_00450049;
LAB_004500b5:
    bVar7 = true;
  }
  if (((float)piStack_1c[2] + (float)param_2[iVar12 * 0xe + 4] + _K_ONE <= ABS(fStack_8)) ||
     (!bVar7)) {
    *(undefined1 *)(param_1 + 0x1e0) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 0x1f0) = 0;
  if (bVar8) {
    *(undefined1 *)(param_1 + 0x1f0) = 1;
  }
  else {
    FUN_0044e850(param_1,0x3dcccccd,0x3dcccccd);
  }
  cVar9 = FUN_0057a720();
  if ((cVar9 != '\0') || (cVar9 = FUN_0057a760(), cVar9 != '\0')) {
    fVar2 = *(float *)(param_1 + 0x1e4);
    if (fVar2 <= 20.0) {
      fVar2 = 20.0;
    }
    *(float *)(param_1 + 0x1e4) = fVar2;
    *(undefined1 *)(param_1 + 0x1e0) = 1;
    return;
  }
LAB_00450123:
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  return;
}


// ==== 0x44fd40 FUN_0044fd40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044fd40(void)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  undefined4 uVar4;
  char cVar5;
  undefined1 uVar6;
  int in_EAX;
  int iVar7;
  int *unaff_EBX;
  int *unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  float10 fVar8;
  undefined4 in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000020;
  undefined4 in_stack_00000024;
  undefined4 in_stack_00000028;
  float in_stack_0000002c;
  float in_stack_00000030;
  char in_stack_00000038;
  
  unaff_EBP[1] = in_EAX;
  *(undefined1 *)(unaff_EBP + 3) = 0;
  unaff_EBP[2] = unaff_ESI;
  cVar5 = FUN_0045b9f0();
  if ((cVar5 == '\0') && (iVar2 = *(int *)(unaff_EDI + 0x34), iVar2 != unaff_ESI)) {
    *unaff_EBP = 3;
    unaff_EBP[1] = iVar2;
    *(undefined1 *)(unaff_EBP + 3) = 0;
    unaff_EBP[2] = unaff_ESI;
  }
  uVar4 = DAT_007006ec;
  *(undefined1 *)(in_stack_00000014 + 0x218) = 0;
  uVar6 = FUN_0045b150(unaff_EBP,in_stack_00000014 + 0x20,unaff_EBX,uVar4,
                       (undefined1 *)(in_stack_00000014 + 0x218),1);
  *(undefined1 *)(in_stack_00000014 + 0x208) = uVar6;
  *(undefined4 *)(in_stack_00000014 + 0x20c) = DAT_0073ad34;
  if ((*(char *)(in_stack_00000014 + 0x208) != '\0') || (20.0 < *(float *)(*unaff_EBX + 0x3d4))) {
    iVar2 = *unaff_EBP;
    iVar7 = unaff_ESI;
    if ((iVar2 != 1) && ((iVar7 = in_stack_0000001c, 1 < iVar2 && (iVar2 < 4)))) {
      iVar7 = FUN_0057b520();
      unaff_ESI = 0;
    }
  }
  else {
    FUN_00458f10(unaff_ESI,unaff_ESI);
    *unaff_EBP = 1;
    unaff_EBP[1] = unaff_ESI;
    *(undefined1 *)(unaff_EBP + 3) = 0;
    unaff_EBP[2] = unaff_ESI;
    FUN_0045c370(in_stack_00000014 + 0x20);
    *(undefined1 *)(in_stack_00000014 + 0x208) = 1;
    iVar7 = in_stack_0000001c;
  }
  in_stack_0000001c = iVar7;
  if (*(char *)(in_stack_00000014 + 0x20) == '\0') {
LAB_0044ff16:
    if ((*unaff_EBP == unaff_ESI) || (cVar5 = FUN_0045ad30(), cVar5 == '\0')) {
LAB_0044ff28:
      *(undefined1 *)(in_stack_00000014 + 0x208) = 0;
      *unaff_EBP = 1;
      unaff_EBP[1] = unaff_ESI;
      *(undefined1 *)(unaff_EBP + 3) = 0;
      unaff_EBP[2] = unaff_ESI;
    }
    in_stack_00000024 = 0xbf800000;
    in_stack_00000028 = 0x47c34f80;
    uVar6 = FUN_0045b050(unaff_EBP,*(undefined1 *)(in_stack_00000014 + 0x218),&stack0x00000024,
                         &stack0x0000002c,&stack0x00000028,0,DAT_007006ec);
    *(undefined1 *)(in_stack_00000014 + 0x208) = uVar6;
    if (*(char *)(in_stack_00000014 + 0x20) == '\0') {
      FUN_0045ae10(unaff_EBP,in_stack_00000014 + 0x20,unaff_EBX,0,2);
      *(undefined1 *)(in_stack_00000014 + 0x208) = 0;
    }
  }
  else {
    if (*unaff_EBP == unaff_ESI) goto LAB_0044ff28;
    if (in_stack_00000010._3_1_ == '\0') goto LAB_0044ff16;
  }
  if (*(char *)(in_stack_00000014 + 0x208) != '\0') goto LAB_00450123;
  cVar5 = FUN_00456780(in_stack_00000018);
  if ((cVar5 == '\0') && (cVar5 = FUN_00456780(in_stack_0000001c), cVar5 == '\0')) {
LAB_00450134:
    *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
    return;
  }
  if (in_stack_00000018 == 0) goto LAB_00450123;
  cVar5 = FUN_0057a8a0();
  if (cVar5 != '\0') goto LAB_00450134;
  fVar8 = (float10)FUN_0057b480();
  in_stack_0000002c = (float)fVar8;
  in_stack_00000030 =
       *(float *)(in_stack_00000018 + 0x10) - (float)unaff_EBX[(char)unaff_EBX[0xe2] * 0xe + 6];
  cVar5 = FUN_0057a6b0();
  if (cVar5 == '\0') {
    if (in_stack_00000030 <= 0.0) goto LAB_00450049;
LAB_004500b5:
    bVar3 = true;
  }
  else {
    if (*(float *)(in_stack_00000020 + 0xc) * _K_HALF <
        *(float *)(in_stack_00000018 + 4) * 0.1 + in_stack_00000030) goto LAB_004500b5;
LAB_00450049:
    bVar3 = false;
  }
  if ((*(float *)(in_stack_00000018 + 8) + *(float *)(in_stack_00000020 + 8) + _K_ONE <=
       ABS(in_stack_0000002c)) || (!bVar3)) {
    *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
    return;
  }
  *(undefined1 *)(in_stack_00000014 + 0x1f0) = 0;
  if (in_stack_00000038 == '\0') {
    FUN_0044e850(in_stack_00000014,0x3dcccccd,0x3dcccccd);
  }
  else {
    *(undefined1 *)(in_stack_00000014 + 0x1f0) = 1;
  }
  cVar5 = FUN_0057a720();
  if ((cVar5 != '\0') || (cVar5 = FUN_0057a760(), cVar5 != '\0')) {
    fVar1 = *(float *)(in_stack_00000014 + 0x1e4);
    if (fVar1 <= 20.0) {
      fVar1 = 20.0;
    }
    *(float *)(in_stack_00000014 + 0x1e4) = fVar1;
    *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
    return;
  }
LAB_00450123:
  *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
  return;
}


// ==== 0x450036 FUN_00450036

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00450036(void)

{
  float fVar1;
  bool bVar2;
  char cVar3;
  int unaff_EBP;
  bool in_ZF;
  int in_stack_00000014;
  int in_stack_00000020;
  float in_stack_0000002c;
  float in_stack_00000030;
  char in_stack_00000038;
  
  if (in_ZF) {
    if (0.0 < in_stack_00000030) {
LAB_004500b5:
      bVar2 = true;
      goto LAB_0045004b;
    }
  }
  else if (*(float *)(in_stack_00000020 + 0xc) * _K_HALF <
           *(float *)(unaff_EBP + 4) * 0.1 + in_stack_00000030) goto LAB_004500b5;
  bVar2 = false;
LAB_0045004b:
  if ((ABS(in_stack_0000002c) <
       *(float *)(unaff_EBP + 8) + *(float *)(in_stack_00000020 + 8) + _K_ONE) && (bVar2)) {
    *(undefined1 *)(in_stack_00000014 + 0x1f0) = 0;
    if (in_stack_00000038 == '\0') {
      FUN_0044e850(in_stack_00000014,0x3dcccccd,0x3dcccccd);
    }
    else {
      *(undefined1 *)(in_stack_00000014 + 0x1f0) = 1;
    }
    cVar3 = FUN_0057a720();
    if (cVar3 == '\0') {
      cVar3 = FUN_0057a760();
      if (cVar3 == '\0') {
        *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
        return;
      }
    }
    fVar1 = *(float *)(in_stack_00000014 + 0x1e4);
    if (fVar1 <= 20.0) {
      fVar1 = 20.0;
    }
    *(float *)(in_stack_00000014 + 0x1e4) = fVar1;
    *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
    return;
  }
  *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
  return;
}


// ==== 0x450038 FUN_00450038

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00450038(void)

{
  float fVar1;
  char cVar2;
  int unaff_EBP;
  int in_stack_00000014;
  int in_stack_00000020;
  float in_stack_0000002c;
  float in_stack_00000030;
  char in_stack_00000038;
  
  if ((*(float *)(unaff_EBP + 8) + *(float *)(in_stack_00000020 + 8) + _K_ONE <=
       ABS(in_stack_0000002c)) || (in_stack_00000030 <= 0.0)) {
    *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
    return;
  }
  *(undefined1 *)(in_stack_00000014 + 0x1f0) = 0;
  if (in_stack_00000038 == '\0') {
    FUN_0044e850(in_stack_00000014,0x3dcccccd,0x3dcccccd);
  }
  else {
    *(undefined1 *)(in_stack_00000014 + 0x1f0) = 1;
  }
  cVar2 = FUN_0057a720();
  if ((cVar2 == '\0') && (cVar2 = FUN_0057a760(), cVar2 == '\0')) {
    *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
    return;
  }
  fVar1 = *(float *)(in_stack_00000014 + 0x1e4);
  if (fVar1 <= 20.0) {
    fVar1 = 20.0;
  }
  *(float *)(in_stack_00000014 + 0x1e4) = fVar1;
  *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
  return;
}


// ==== 0x450044 FUN_00450044

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00450044(void)

{
  float fVar1;
  char cVar2;
  uint in_EAX;
  int unaff_EBP;
  int in_stack_00000014;
  int in_stack_00000020;
  float in_stack_0000002c;
  char in_stack_00000038;
  
  if ((*(float *)(unaff_EBP + 8) + *(float *)(in_stack_00000020 + 8) + _K_ONE <=
       ABS(in_stack_0000002c)) || ((in_EAX & 0x4100) != 0)) {
    *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
    return;
  }
  *(undefined1 *)(in_stack_00000014 + 0x1f0) = 0;
  if (in_stack_00000038 == '\0') {
    FUN_0044e850(in_stack_00000014,0x3dcccccd,0x3dcccccd);
  }
  else {
    *(undefined1 *)(in_stack_00000014 + 0x1f0) = 1;
  }
  cVar2 = FUN_0057a720();
  if ((cVar2 == '\0') && (cVar2 = FUN_0057a760(), cVar2 == '\0')) {
    *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
    return;
  }
  fVar1 = *(float *)(in_stack_00000014 + 0x1e4);
  if (fVar1 <= 20.0) {
    fVar1 = 20.0;
  }
  *(float *)(in_stack_00000014 + 0x1e4) = fVar1;
  *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
  return;
}


// ==== 0x450053 FUN_00450053

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00450053(char param_1)

{
  float fVar1;
  char cVar2;
  int in_EAX;
  int unaff_EBP;
  float10 in_ST0;
  int in_stack_00000014;
  char in_stack_00000038;
  
  if ((ABS(in_ST0) <
       (float10)*(float *)(unaff_EBP + 8) + (float10)*(float *)(in_EAX + 8) + (float10)_K_ONE) &&
     (param_1 != '\0')) {
    *(undefined1 *)(in_stack_00000014 + 0x1f0) = 0;
    if (in_stack_00000038 == '\0') {
      FUN_0044e850(in_stack_00000014,0x3dcccccd,0x3dcccccd);
    }
    else {
      *(undefined1 *)(in_stack_00000014 + 0x1f0) = 1;
    }
    cVar2 = FUN_0057a720();
    if (cVar2 == '\0') {
      cVar2 = FUN_0057a760();
      if (cVar2 == '\0') {
        *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
        return;
      }
    }
    fVar1 = *(float *)(in_stack_00000014 + 0x1e4);
    if (fVar1 <= 20.0) {
      fVar1 = 20.0;
    }
    *(float *)(in_stack_00000014 + 0x1e4) = fVar1;
    *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
    return;
  }
  *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
  return;
}


// ==== 0x450065 FUN_00450065

void __thiscall FUN_00450065(char param_1)

{
  float fVar1;
  char cVar2;
  uint in_EAX;
  int in_stack_00000014;
  char in_stack_00000038;
  
  if (((in_EAX & 0x4100) == 0) && (param_1 != '\0')) {
    *(undefined1 *)(in_stack_00000014 + 0x1f0) = 0;
    if (in_stack_00000038 == '\0') {
      FUN_0044e850(in_stack_00000014,0x3dcccccd,0x3dcccccd);
    }
    else {
      *(undefined1 *)(in_stack_00000014 + 0x1f0) = 1;
    }
    cVar2 = FUN_0057a720();
    if (cVar2 == '\0') {
      cVar2 = FUN_0057a760();
      if (cVar2 == '\0') {
        *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
        return;
      }
    }
    fVar1 = *(float *)(in_stack_00000014 + 0x1e4);
    if (fVar1 <= 20.0) {
      fVar1 = 20.0;
    }
    *(float *)(in_stack_00000014 + 0x1e4) = fVar1;
    *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
    return;
  }
  *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
  return;
}


// ==== 0x45006e FUN_0045006e

void __thiscall FUN_0045006e(char param_1)

{
  float fVar1;
  char cVar2;
  int in_stack_00000014;
  char in_stack_00000038;
  
  if (param_1 == '\0') {
    *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
    return;
  }
  *(undefined1 *)(in_stack_00000014 + 0x1f0) = 0;
  if (in_stack_00000038 == '\0') {
    FUN_0044e850(in_stack_00000014,0x3dcccccd,0x3dcccccd);
  }
  else {
    *(undefined1 *)(in_stack_00000014 + 0x1f0) = 1;
  }
  cVar2 = FUN_0057a720();
  if (cVar2 == '\0') {
    cVar2 = FUN_0057a760();
    if (cVar2 == '\0') {
      *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
      return;
    }
  }
  fVar1 = *(float *)(in_stack_00000014 + 0x1e4);
  if (fVar1 <= 20.0) {
    fVar1 = 20.0;
  }
  *(float *)(in_stack_00000014 + 0x1e4) = fVar1;
  *(undefined1 *)(in_stack_00000014 + 0x1e0) = 1;
  return;
}


// ==== 0x4500ed FUN_004500ed

void __fastcall FUN_004500ed(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x1e4);
  if (fVar1 <= 20.0) {
    fVar1 = 20.0;
  }
  *(float *)(param_1 + 0x1e4) = fVar1;
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  return;
}


// ==== 0x450100 FUN_00450100

void __fastcall FUN_00450100(int param_1)

{
  *(undefined4 *)(param_1 + 0x1e4) = 0x41a00000;
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  return;
}


// ==== 0x450160 FUN_00450160

void FUN_00450160(int *param_1)

{
  *(undefined1 *)(*param_1 + 0x88c) = 0;
  return;
}


// ==== 0x450170 FUN_00450170

void __thiscall FUN_00450170(undefined4 param_1,undefined4 param_2)

{
  undefined4 *unaff_ESI;
  
  FUN_0044e2b0(7,param_1,param_2);
  *unaff_ESI = &PTR_FUN_006c9374;
  unaff_ESI[0x80] = 0;
  unaff_ESI[0x80] = 0;
  return;
}


// ==== 0x4501a0 FUN_004501a0

void __thiscall FUN_004501a0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIActionJustDrive");
  FUN_0044e370(param_2);
  FUN_00571c20(param_2,param_1 + 0x200,4,0xffffffff,0);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10;
  *(int *)(iVar1 + param_2 + 0x58) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0x58 + param_2);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x450210 FUN_00450210

void __thiscall FUN_00450210(int param_1,int *param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iStack_1f0;
  int iStack_1ec;
  int iStack_1e8;
  int iStack_1e4;
  int iStack_1e0;
  uint uStack_1dc;
  undefined1 auStack_1d8 [4];
  undefined1 auStack_1d4 [4];
  undefined4 auStack_1d0 [105];
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  iStack_1f0 = DAT_0073ad34 - *(int *)(param_1 + 0x200);
  piVar1 = param_2 + 0xe6;
  iStack_1ec = param_1;
  if ((float)iStack_1f0 * 0.00025 < 3.0) {
LAB_0045033f:
    param_1 = iStack_1ec;
    if (*piVar1 != 1) {
      iStack_1f0 = *(int *)(*param_2 + 0x10);
      if (*(char *)(iStack_1f0 + 0x424) == -1) {
        RideInfo__RebuildPhysicsInfo(1);
      }
      param_2[0xe5] = (int)*(char *)(iStack_1f0 + 0x424);
      *piVar1 = 1;
      param_2[0xe7] = 0;
      *(undefined1 *)(param_2 + 0xe9) = 0;
      param_2[0xe8] = 0;
    }
  }
  else {
    *(int *)(param_1 + 0x200) = DAT_0073ad34;
    if (*piVar1 != 1) {
      uStack_2c = 0;
      uStack_28 = 0;
      puVar4 = auStack_1d0;
      for (iVar3 = 0x70; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      FUN_00458f10(0,0);
      iStack_1e4 = 0;
      iStack_1e0 = 0;
      iStack_1e8 = 1;
      uStack_1dc = uStack_1dc & 0xffffff00;
      iStack_1f0 = 0x47c34f80;
      cVar2 = FUN_0045b050(&iStack_1e8,0,auStack_1d4,auStack_1d8,&iStack_1f0,0,DAT_007006ec);
      if (cVar2 != '\0') {
        *piVar1 = iStack_1e8;
        param_2[0xe7] = iStack_1e4;
        param_2[0xe8] = iStack_1e0;
        param_2[0xe9] = uStack_1dc;
        iVar3 = *(int *)(*param_2 + 0x10);
        if (*(char *)(iVar3 + 0x424) == -1) {
          RideInfo__RebuildPhysicsInfo(1);
        }
        param_2[0xe5] = (int)*(char *)(iVar3 + 0x424);
        puVar4 = auStack_1d0;
        puVar5 = (undefined4 *)(iStack_1ec + 0x20);
        for (iVar3 = 0x70; param_1 = iStack_1ec, iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        goto LAB_00450393;
      }
      goto LAB_0045033f;
    }
  }
  FUN_0045ae10(piVar1,param_1 + 0x20,param_2,0,0);
LAB_00450393:
  *(undefined1 *)(param_1 + 499) = 0;
  if (*(int *)(*(int *)(*param_2 + 0x14) + 4) == 2) {
    piVar1 = *(int **)(*param_2 + 0x2c);
    cVar2 = CarState__IsNitrousOn();
    if ((cVar2 == '\0') && (cVar2 = (**(code **)(*piVar1 + 0x78))(param_2), cVar2 != '\0')) {
      *(undefined1 *)(param_1 + 499) = 1;
    }
  }
  *(undefined1 *)(param_1 + 0x1f0) = 1;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined1 *)(param_1 + 0x1f1) = 1;
  *(undefined1 *)(param_1 + 0x1f2) = 1;
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  return;
}


// ==== 0x450400 FUN_00450400

void __thiscall FUN_00450400(undefined4 param_1,undefined4 param_2)

{
  undefined4 *unaff_ESI;
  
  FUN_0044e2b0(4,param_1,param_2);
  *unaff_ESI = &PTR_FUN_006c9144;
  return;
}


// ==== 0x450420 FUN_00450420

void FUN_00450420(int param_1)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIActionDraft");
  FUN_0044e370(param_1);
  iVar1 = *(char *)(param_1 + 0x40) * 0x10;
  *(int *)(iVar1 + param_1 + 0x58) = *(int *)(param_1 + 0x150) - *(int *)(iVar1 + 0x58 + param_1);
  cVar2 = *(char *)(param_1 + 0x40) + -1;
  *(char *)(param_1 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_1 + 0x44)) {
    *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x450480 FUN_00450480

void __thiscall FUN_00450480(int param_1,int *param_2)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  
  iVar5 = param_2[0xe2];
  piVar1 = param_2 + 0xe6;
  if (*piVar1 != 1) {
    iVar4 = *(int *)(*param_2 + 0x10);
    if (*(char *)(iVar4 + 0x424) == -1) {
      RideInfo__RebuildPhysicsInfo(1);
    }
    param_2[0xe5] = (int)*(char *)(iVar4 + 0x424);
    *piVar1 = 1;
    param_2[0xe7] = 0;
    *(undefined1 *)(param_2 + 0xe9) = 0;
    param_2[0xe8] = 0;
  }
  FUN_0045ae10(piVar1,param_1 + 0x20,param_2,0,0);
  iVar4 = ((char)iVar5 * 0x38) / 0x38;
  *(undefined1 *)(param_1 + 0x1f0) = 1;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined1 *)(param_1 + 0x1f1) = 1;
  *(undefined1 *)(param_1 + 0x1f2) = 1;
  if (((0 < iVar4) && (iVar4 < param_2[1])) &&
     (piVar1 = param_2 + iVar4 * 0xe + -0xc, piVar1 != (int *)0x0)) {
    iVar4 = piVar1[0xd];
    iVar6 = FUN_00647b70();
    if ((iVar6 != 6) ||
       (*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 0x1d4) + 0x90) + 0x14) + 4) != 2)) {
      iVar4 = piVar1[0xd];
      iVar6 = FUN_00647b70();
      if ((iVar6 != 6) ||
         (*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 0x1d4) + 0x90) + 0x14) + 4) != 1))
      goto LAB_00450643;
    }
    fVar7 = (float10)FUN_0057b480();
    fVar2 = (float)piVar1[4];
    fVar3 = (float)param_2[(char)param_2[0xe2] * 0xe + 6];
    if ((ABS(fVar7) < (float10)(float)piVar1[2] + (float10)(float)param_2[(char)iVar5 * 0xe + 4]) &&
       (fVar2 - fVar3 < 6.0)) {
      fVar7 = (float10)FUN_0044d5f0();
      fVar7 = fVar7 - ((float10)20.0 - (float10)(fVar2 - fVar3));
      if (fVar7 < (float10)*(float *)(param_1 + 0x1e4)) {
        *(float *)(param_1 + 0x1e4) = (float)fVar7;
        *(undefined4 *)(param_1 + 0x1e8) = 0;
        *(undefined1 *)(param_1 + 0x1f0) = 0;
        *(undefined1 *)(param_1 + 0x1e0) = 1;
        return;
      }
    }
  }
LAB_00450643:
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  return;
}


// ==== 0x450660 FUN_00450660

void __thiscall
FUN_00450660(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *unaff_ESI;
  
  FUN_0044e2b0(0,param_1,param_2);
  *unaff_ESI = &PTR_FUN_006c9234;
  unaff_ESI[0x82] = 0;
  unaff_ESI[0x81] = param_4;
  unaff_ESI[0x82] = DAT_0073ad34;
  unaff_ESI[0x80] = param_3;
  return;
}


// ==== 0x4506b0 FUN_004506b0

void __thiscall FUN_004506b0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIActionPass");
  FUN_00571c20(param_2,param_1 + 0x208,4,0xffffffff,0);
  FUN_00571c20(param_2,param_1 + 0x204,4,0xffffffff,0);
  FUN_0044e370(param_2);
  iVar1 = *(char *)(param_2 + 0x40) * 0x10 + 0x4c + param_2;
  *(int *)(iVar1 + 0xc) = *(int *)(param_2 + 0x150) - *(int *)(iVar1 + 0xc);
  cVar2 = *(char *)(param_2 + 0x40) + -1;
  *(char *)(param_2 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_2 + 0x44)) {
    *(undefined4 *)(param_2 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x450730 FUN_00450730

undefined4 FUN_00450730(int *param_1,int *param_2)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int *unaff_EDI;
  float10 fVar4;
  int local_1e8;
  uint local_1e4;
  float local_1e0;
  float local_1d8;
  int local_1d4;
  undefined1 local_1d0 [460];
  
  bVar1 = false;
  if (((*(int *)(DAT_0073619c + 4) != 0) && (*(int *)(DAT_0073619c + 4) != 0x7fffffff)) &&
     (5.0 < (float)(DAT_0073ad34 - *(int *)(DAT_0073619c + 4)) * 0.00025)) {
    fVar4 = (float10)FUN_00456830(*unaff_EDI,*(undefined4 *)(*unaff_EDI + 0x3d4));
    local_1e0 = (float)fVar4;
    local_1d4 = (int)(char)unaff_EDI[0xe2];
    local_1e8 = 0;
    if (0 < local_1d4) {
      piVar3 = unaff_EDI + 0xf;
      do {
        if (bVar1) {
          return 200;
        }
        fVar4 = (float10)FUN_0057b480();
        local_1d8 = (float)piVar3[-9] - (float)unaff_EDI[(char)unaff_EDI[0xe2] * 0xe + 6];
        if (((0.0 < local_1d8) && (fVar4 < (float10)local_1d8 + (float10)local_1d8)) &&
           (cVar2 = FUN_004569b0(*unaff_EDI,local_1d8,piVar3[-0xc],local_1e0,1), cVar2 != '\0')) {
          FUN_00458d90();
          *param_2 = unaff_EDI[0xe6];
          param_2[1] = unaff_EDI[0xe7];
          param_2[2] = unaff_EDI[0xe8];
          param_2[3] = unaff_EDI[0xe9];
          local_1e4 = local_1e4 & 0xffffff00;
          cVar2 = FUN_0045bae0(param_2,local_1d0,&local_1e4,piVar3 + -0xd,unaff_EDI,0,DAT_007006ec,1
                              );
          if ((cVar2 != '\0') && (cVar2 = FUN_00450b40(param_2,local_1e4), cVar2 != '\0')) {
            *param_1 = *piVar3;
            bVar1 = true;
          }
        }
        local_1e8 = local_1e8 + 1;
        piVar3 = piVar3 + 0xe;
      } while (local_1e8 < local_1d4);
      if (bVar1) {
        return 200;
      }
    }
  }
  return 0xffffffff;
}


// ==== 0x4508f0 FUN_004508f0

int __thiscall FUN_004508f0(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  char cVar6;
  int iVar7;
  int *piVar8;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  uint local_4;
  
  iVar2 = param_2;
  puVar1 = (undefined4 *)(param_2 + 0x398);
  if ((0 < *(int *)(param_2 + 4)) && (*(int *)(param_2 + 0x3c) != *(int *)(param_1 + 0x200))) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = local_4 & 0xffffff00;
    param_2 = 0;
    iVar7 = FUN_00450730(&param_2,&local_10,&param_2);
    if ((-1 < iVar7) && (cVar6 = FUN_0045add0(), cVar6 == '\0')) {
      *puVar1 = local_10;
      *(undefined4 *)(iVar2 + 0x39c) = local_c;
      *(undefined4 *)(iVar2 + 0x3a0) = local_8;
      *(uint *)(iVar2 + 0x3a4) = local_4;
      *(int *)(param_1 + 0x200) = param_2;
      *(int *)(param_1 + 0x208) = DAT_0073ad34;
    }
  }
  fVar4 = (float)(DAT_0073ad34 - *(int *)(param_1 + 0x208)) * 0.00025;
  if (fVar4 < 3.0) {
    return CONCAT22((short)((uint)*(int *)(param_1 + 0x208) >> 0x10),
                    (ushort)(fVar4 < 3.0) << 8 | (ushort)NAN(fVar4) << 10 |
                    (ushort)(fVar4 == 3.0) << 0xe);
  }
  iVar7 = 0;
  if (0 < *(int *)(iVar2 + 4)) {
    piVar8 = (int *)(iVar2 + 0x3c);
    while (*piVar8 != *(int *)(param_1 + 0x200)) {
      iVar7 = iVar7 + 1;
      piVar8 = piVar8 + 0xe;
      if (*(int *)(iVar2 + 4) <= iVar7) {
        return CONCAT31((int3)((uint)iVar7 >> 8),1);
      }
    }
    if (iVar7 != -1) {
      iVar3 = iVar7 * 0x38 + 8 + iVar2;
      iVar7 = 0;
      if (iVar3 != 0) {
        iVar2 = *(char *)(iVar2 + 0x388) * 0x38 + iVar2;
        fVar4 = *(float *)(iVar3 + 0x10) - *(float *)(iVar2 + 0x18);
        fVar5 = -(*(float *)(iVar2 + 0x14) + *(float *)(iVar3 + 0xc) + 10.0);
        iVar7 = CONCAT22((short)((uint)iVar3 >> 0x10),
                         (ushort)(fVar5 < fVar4) << 8 | (ushort)(NAN(fVar5) || NAN(fVar4)) << 10 |
                         (ushort)(fVar5 == fVar4) << 0xe);
        if (fVar5 < fVar4 || (fVar5 == fVar4) != 0) {
          return iVar7;
        }
      }
    }
  }
  return CONCAT31((int3)((uint)iVar7 >> 8),1);
}


// ==== 0x450a30 FUN_00450a30

uint __fastcall FUN_00450a30(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = DAT_0073ad34 - *(int *)(param_1 + 8);
  fVar2 = (float)iVar3 * 0.00025;
  fVar1 = *(float *)(param_1 + 0xc);
  uVar4 = CONCAT22((short)((uint)iVar3 >> 0x10),
                   (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                   (ushort)(fVar2 == fVar1) << 0xe);
  if ((fVar2 < fVar1 != 0 || (fVar2 == fVar1) != 0) ||
     (uVar4 = CONCAT31((int3)(uVar4 >> 8),1), *(char *)(param_1 + 4) == '\0')) {
    uVar4 = uVar4 & 0xffffff00;
  }
  return uVar4;
}


// ==== 0x450a70 FUN_00450a70

undefined4 __thiscall FUN_00450a70(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = 0;
  if (0 < (int)param_2[1]) {
    piVar4 = param_2 + 0xf;
    while (*piVar4 != *(int *)(param_1 + 0x200)) {
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 0xe;
      if ((int)param_2[1] <= iVar3) {
        return 1;
      }
    }
    if ((iVar3 != -1) && (puVar1 = param_2 + iVar3 * 0xe + 2, puVar1 != (undefined4 *)0x0)) {
      if ((3.0 < (float)(DAT_0073ad34 - *(int *)(param_1 + 0x208)) * 0.00025) &&
         ((0.0 < (float)puVar1[4] - (float)param_2[*(char *)(param_2 + 0xe2) * 0xe + 6] &&
          (cVar2 = FUN_004569b0(*param_2,(float)puVar1[4] -
                                         (float)param_2[*(char *)(param_2 + 0xe2) * 0xe + 6],
                                puVar1[1],0xbf800000,0), cVar2 == '\0')))) {
        return 1;
      }
      return 0;
    }
  }
  return 1;
}


// ==== 0x450b40 FUN_00450b40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00450b40(int *param_1,char param_2)

{
  int iVar1;
  float10 fVar2;
  int in_EAX;
  int iVar3;
  undefined4 uVar4;
  undefined2 extraout_var;
  bool bVar5;
  float10 fVar6;
  
  iVar1 = *(int *)(in_EAX + 0x34);
  iVar3 = FUN_00647b70();
  if ((iVar3 != 6) ||
     (iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 0x1d4) + 0x90) + 0x14),
     bVar5 = *(int *)(iVar1 + 4) == 3, uVar4 = CONCAT31((int3)((uint)iVar1 >> 8),bVar5), !bVar5)) {
    fVar6 = (float10)FUN_0044d5f0();
    fVar2 = (float10)_DAT_00700674;
    uVar4 = CONCAT22(extraout_var,
                     (ushort)(fVar6 < fVar2) << 8 | (ushort)(NAN(fVar6) || NAN(fVar2)) << 10 |
                     (ushort)(fVar6 == fVar2) << 0xe);
    if (fVar6 < fVar2 == 0 && (fVar6 == fVar2) == 0) {
      if ((*param_1 != 1) && (param_2 == '\0')) {
        return 0;
      }
      return 1;
    }
  }
  return CONCAT31((int3)((uint)uVar4 >> 8),1);
}


// ==== 0x450bb0 FUN_00450bb0

void __thiscall FUN_00450bb0(int param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uStack_8;
  undefined1 auStack_4 [4];
  
  uVar2 = param_2;
  piVar1 = (int *)(param_2 + 0x398);
  FUN_00458f10(0,0);
  *(undefined1 *)(param_1 + 0x1f0) = 0;
  *(undefined1 *)(param_1 + 0x1f1) = 1;
  *(undefined1 *)(param_1 + 0x1f2) = 1;
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  iVar3 = 0;
  param_2 = param_2 & 0xffffff00;
  if (0 < *(int *)(uVar2 + 4)) {
    piVar4 = (int *)(uVar2 + 0x3c);
    do {
      if (*piVar4 == *(int *)(param_1 + 0x200)) {
        if ((iVar3 != -1) && (iVar3 = iVar3 * 0x38 + 8 + uVar2, iVar3 != 0)) {
          if (*(float *)(iVar3 + 0x10) - *(float *)(*(char *)(uVar2 + 0x388) * 0x38 + 0x18 + uVar2)
              <= 0.0) {
            if (*piVar1 != 1) {
              *piVar1 = 1;
              *(undefined4 *)(uVar2 + 0x39c) = 0;
              *(undefined1 *)(uVar2 + 0x3a4) = 0;
              *(undefined4 *)(uVar2 + 0x3a0) = 0;
            }
            uStack_8 = 0;
            param_2 = 0x47c34f80;
            FUN_0045b050(piVar1,0,&uStack_8,auStack_4,&param_2,0,DAT_007006ec);
            *(undefined1 *)(param_1 + 0x1f0) = 1;
            return;
          }
          FUN_0045bae0(piVar1,param_1 + 0x20,&param_2,iVar3,uVar2,0,DAT_007006ec,1);
          *(undefined1 *)(param_1 + 0x1f0) = 1;
          if (ABS(*(float *)(iVar3 + 4)) < 5.0 == (ABS(*(float *)(iVar3 + 4)) == 5.0)) {
            return;
          }
          FUN_0044f6c0(param_1);
          return;
        }
        break;
      }
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 0xe;
    } while (iVar3 < *(int *)(uVar2 + 4));
  }
  if (*piVar1 != 1) {
    *piVar1 = 1;
    *(undefined4 *)(uVar2 + 0x39c) = 0;
    *(undefined1 *)(uVar2 + 0x3a4) = 0;
    *(undefined4 *)(uVar2 + 0x3a0) = 0;
  }
  FUN_0045ae10(piVar1,param_1 + 0x20,uVar2,0,2);
  *(undefined1 *)(param_1 + 0x1e0) = 0;
  *(undefined1 *)(param_1 + 0x1f0) = 1;
  return;
}


// ==== 0x450d00 FUN_00450d00

void FUN_00450d00(void)

{
  int unaff_EBP;
  undefined4 uStack00000038;
  
  uStack00000038 = 0x47c34f80;
  FUN_0045b050();
  *(undefined1 *)(unaff_EBP + 0x1f0) = 1;
  return;
}


// ==== 0x450d20 FUN_00450d20

void __thiscall FUN_00450d20(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *unaff_ESI;
  
  FUN_0044e2b0(6,param_1,param_2);
  *unaff_ESI = &PTR_FUN_006c90f4;
  unaff_ESI[0x80] = param_3;
  return;
}


// ==== 0x450d50 FUN_00450d50

void FUN_00450d50(int param_1)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIActionNudgeAvoidable");
  FUN_0044e370(param_1);
  iVar1 = *(char *)(param_1 + 0x40) * 0x10;
  *(int *)(iVar1 + param_1 + 0x58) = *(int *)(param_1 + 0x150) - *(int *)(iVar1 + 0x58 + param_1);
  cVar2 = *(char *)(param_1 + 0x40) + -1;
  *(char *)(param_1 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_1 + 0x44)) {
    *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x450db0 FUN_00450db0

undefined1 FUN_00450db0(void)

{
  return 1;
}


// ==== 0x450dc0 FUN_00450dc0

undefined4 __fastcall FUN_00450dc0(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = DAT_0073ad34 - *(int *)(param_1 + 8);
  fVar2 = (float)iVar3 * 0.00025;
  fVar1 = *(float *)(param_1 + 0xc);
  if (fVar2 < fVar1 != (fVar2 == fVar1)) {
    return CONCAT22((short)((uint)iVar3 >> 0x10),
                    (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                    (ushort)(fVar2 == fVar1) << 0xe);
  }
  if ((*(char *)(param_1 + 0x1e0) == '\0') && (*(char *)(param_1 + 4) != '\0')) {
    return 1;
  }
  return 0;
}


// ==== 0x450e10 FUN_00450e10

void __fastcall FUN_00450e10(int param_1)

{
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  return;
}


// ==== 0x450e20 FUN_00450e20

void __thiscall FUN_00450e20(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *unaff_ESI;
  
  FUN_0044e2b0(5,param_1,param_2);
  *unaff_ESI = &PTR_FUN_006c9284;
  unaff_ESI[0x80] = param_3;
  return;
}


// ==== 0x450e50 FUN_00450e50

void FUN_00450e50(int param_1)

{
  int iVar1;
  char cVar2;
  
  FUN_00571ea0(0,"AIActionBlock");
  FUN_0041ff80(DAT_007361f8);
  FUN_0044e370(param_1);
  iVar1 = *(char *)(param_1 + 0x40) * 0x10;
  *(int *)(iVar1 + param_1 + 0x58) = *(int *)(param_1 + 0x150) - *(int *)(iVar1 + 0x58 + param_1);
  cVar2 = *(char *)(param_1 + 0x40) + -1;
  *(char *)(param_1 + 0x40) = cVar2;
  if ((int)cVar2 < *(int *)(param_1 + 0x44)) {
    *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
  }
  return;
}


// ==== 0x450ec0 FUN_00450ec0

undefined4 FUN_00450ec0(undefined4 *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  char cVar6;
  int *in_EAX;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  undefined4 uVar11;
  bool bVar12;
  float10 fVar13;
  float local_1c;
  int *local_14;
  int *local_4;
  
  *param_1 = 0;
  iVar8 = in_EAX[0xe2];
  iVar2 = in_EAX[0xea];
  iVar3 = *(int *)(*in_EAX + 0x2c);
  cVar6 = RaceManager__IsInRaceStartWindow(DAT_0073619c,*in_EAX);
  if (cVar6 == '\0') {
    local_14 = (int *)0x0;
    local_4 = (int *)0x0;
    iVar9 = (char)iVar8 + 1;
    if (iVar9 < in_EAX[1]) {
      piVar10 = in_EAX + iVar9 * 0xe + 2;
      do {
        iVar4 = piVar10[0xd];
        iVar7 = FUN_00647b70();
        if (((iVar7 == 6) && (*(int *)(*(int *)(*(int *)(iVar4 + 0x1d4) + 0x90) + 0x1c) != 0)) &&
           (fVar13 = (float10)FUN_0044d5f0(), (float10)10.0 <= fVar13)) {
          bVar12 = false;
          iVar9 = FUN_00647b70();
          if (iVar9 == 6) {
            bVar12 = *(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 0x1d4) + 0x90) + 0x14) + 4) == 1;
          }
          fVar1 = (float)piVar10[5];
          iVar9 = *(int *)(iVar2 + 8 + piVar10[0xc] * 4);
          if (fVar1 <= 0.0) {
            fVar1 = *(float *)(iVar9 + 0x20) - fVar1;
          }
          else {
            fVar1 = fVar1 - *(float *)(iVar9 + 0x3c);
          }
          fVar5 = (float)piVar10[1];
          local_1c = (float)piVar10[4] - (float)in_EAX[(char)in_EAX[0xe2] * 0xe + 6];
          if ((&DAT_0077a344)[*(char *)(*(int *)(*(int *)(iVar3 + 4) + 0x14) + 0x736) * 8] != '\0')
          {
            local_1c = local_1c - ((float)piVar10[3] + (float)in_EAX[(char)iVar8 * 0xe + 5]);
          }
          if (0.0 <= fVar1) {
            return 0xffffffff;
          }
          if (0.0 <= local_1c) {
            return 0xffffffff;
          }
          if (*(int *)(iVar2 + 4) == 0) {
            fVar1 = 0.0;
          }
          else {
            fVar1 = *(float *)(*(int *)(iVar2 + 8) + 0x58);
          }
          if (fVar1 < (float)piVar10[4]) {
            if (local_1c <= -50.0) {
              return 0xffffffff;
            }
            if (-5.0 < fVar5) {
              if (0.001 < fVar5) {
                fVar1 = ABS(local_1c / fVar5);
                if (bVar12) {
                  fVar5 = 30.0;
                }
                else {
                  fVar5 = 2.0;
                }
                if ((fVar1 < fVar5 != (fVar1 == fVar5)) && (fVar1 < 99999.0)) {
                  local_14 = piVar10;
                }
              }
              if ((!bVar12) || (local_1c <= -35.0)) {
                piVar10 = local_4;
              }
              if (local_14 == (int *)0x0) {
                if (piVar10 == (int *)0x0) {
                  return 0xffffffff;
                }
                iVar2 = piVar10[0xd];
                uVar11 = 0;
                iVar8 = FUN_00647b70();
                if (iVar8 == 6) {
                  uVar11 = *(undefined4 *)(*(int *)(iVar2 + 0x1d4) + 0x90);
                }
                *param_1 = uVar11;
              }
              else {
                iVar2 = local_14[0xd];
                uVar11 = 0;
                iVar8 = FUN_00647b70();
                if (iVar8 == 6) {
                  uVar11 = *(undefined4 *)(*(int *)(iVar2 + 0x1d4) + 0x90);
                }
                *param_1 = uVar11;
              }
              return *(undefined4 *)
                      (&DAT_0077a340 + *(char *)(*(int *)(*(int *)(iVar3 + 4) + 0x14) + 0x736) * 8);
            }
            return 0xffffffff;
          }
          return 0xffffffff;
        }
        iVar9 = iVar9 + 1;
        piVar10 = piVar10 + 0xe;
      } while (iVar9 < in_EAX[1]);
    }
  }
  return 0xffffffff;
}


