// ==== 0x5410b0 LightPack_Unload

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 LightPack_Unload(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 0x135200) {
    if (param_1[6] == 3) {
      iVar1 = param_1[3];
      piVar2 = (int *)param_1[4];
      *piVar2 = iVar1;
      *(int **)(iVar1 + 4) = piVar2;
      if (param_1[5] == 0x2c420d64) {
        PTR_DAT_006f3df0 = (undefined *)&DAT_00740a70;
      }
    }
    return 1;
  }
  if (iVar1 == -0x7fecaf00) {
    piVar2 = param_1 + 2;
    param_1 = (int *)(param_1[1] + 8 + (int)param_1);
    if (piVar2 == param_1) {
      return 1;
    }
    while (*piVar2 != 0x135101) {
      piVar2 = (int *)((int)piVar2 + piVar2[1] + 8);
      if (piVar2 == param_1) {
        return 1;
      }
    }
  }
  else {
    if (iVar1 != -0x7fecb000) {
      return 0;
    }
    piVar2 = param_1 + 2;
    if (piVar2 == (int *)(param_1[1] + 8 + (int)param_1)) {
      return 1;
    }
    do {
    } while (*piVar2 != 0x135001);
  }
  piVar2 = (int *)((int)piVar2 + 0x17U & 0xfffffff0);
  if (piVar2[2] == 3) {
    iVar1 = *piVar2;
    piVar2 = (int *)piVar2[1];
    *piVar2 = iVar1;
    *(int **)(iVar1 + 4) = piVar2;
  }
  return 1;
}


// ==== 0x541160 FUN_00541160

undefined4 FUN_00541160(void)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  
  if (in_EAX == (undefined4 *)0x0) {
    return 0;
  }
  *DAT_00743c14 = in_EAX;
  puVar1 = in_EAX;
  in_EAX[1] = DAT_00743c14;
  DAT_00743c14 = puVar1;
  *in_EAX = &DAT_00743c10;
  return 1;
}


// ==== 0x541190 FUN_00541190

undefined4 __fastcall FUN_00541190(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar1 = *param_1;
  piVar2 = (int *)param_1[1];
  *piVar2 = iVar1;
  *(int **)(iVar1 + 4) = piVar2;
  return 1;
}


// ==== 0x5411b0 FUN_005411b0

/* WARNING: Removing unreachable block (ram,0x00541291) */
/* WARNING: Removing unreachable block (ram,0x00541274) */
/* WARNING: Removing unreachable block (ram,0x005412af) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005411b0(int param_1,int param_2,float param_3,float param_4,float param_5)

{
  char cVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int in_EAX;
  float local_14;
  
  if (*(char *)(param_2 + 7) == '\x01') {
    cVar1 = *(char *)(param_2 + 4);
    fVar4 = ABS(param_3 - *(float *)(param_2 + 0x10));
    fVar5 = ABS(param_4 - *(float *)(param_2 + 0x14));
    fVar3 = ABS(param_5 - *(float *)(param_2 + 0x18));
    fVar6 = *(float *)(param_2 + 0x1c) * *(float *)(param_2 + 0x1c);
    fVar4 = fVar4 * fVar4 + fVar5 * fVar5 + fVar3 * fVar3;
    if (fVar4 < fVar6) {
      local_14 = 1.0;
      fVar3 = *(float *)(param_2 + 0x30) * *(float *)(param_2 + 0x30);
      if (fVar3 < fVar4) {
        local_14 = _K_ONE - (fVar4 - fVar3) / (fVar6 - fVar3);
      }
      if (cVar1 == '\0') {
        uVar2 = *(uint *)(param_2 + 0xc);
        fVar5 = (float)(uVar2 >> 8 & 0xff);
        fVar6 = (float)(uVar2 >> 0x10 & 0xff);
        fVar3 = *(float *)(param_2 + 0x2c);
        if (*(char *)(param_2 + 5) == '\x02') {
          if (*(float **)(param_1 + 0xb4) < *(float **)(param_1 + 0xb8)) {
            **(float **)(param_1 + 0xb4) = (float)(uVar2 & 0xff) * local_14;
            *(float *)(*(int *)(param_1 + 0xb4) + 4) = fVar5 * local_14;
            *(float *)(*(int *)(param_1 + 0xb4) + 8) = fVar6 * local_14;
            *(float *)(*(int *)(param_1 + 0xb4) + 0xc) = fVar3 * local_14;
            if (0.0 < local_14) {
              *(float *)(param_1 + 0xbc) = local_14 + *(float *)(param_1 + 0xbc);
              *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + 0x10;
              return;
            }
          }
        }
        else if (fVar4 < *(float *)(param_1 + 0xc0)) {
          **(float **)(param_1 + 0xb0) = (float)(uVar2 & 0xff);
          *(float *)(*(int *)(param_1 + 0xb0) + 4) = fVar5;
          *(float *)(*(int *)(param_1 + 0xb0) + 8) = fVar6;
          *(float *)(*(int *)(param_1 + 0xb0) + 0xc) = fVar3;
          *(float *)(param_1 + 0xc0) = fVar4;
          return;
        }
      }
      else if ((cVar1 == '\x02') || (cVar1 == '\x03')) {
        *(int *)(in_EAX + *(int *)(param_1 + 200) * 4) = param_2;
        *(float *)(in_EAX + 0x28 + *(int *)(param_1 + 200) * 4) = local_14;
        *(int *)(param_1 + 200) = *(int *)(param_1 + 200) + 1;
        return;
      }
    }
  }
  return;
}


// ==== 0x5413e0 LightTree_Query

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets med (Hopper export + Ghidra export) docs/re/assets.md */

int LightTree_Query(undefined4 *param_1)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  float fVar6;
  float fVar7;
  undefined4 *in_EAX;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  float **ppfVar11;
  int extraout_ECX;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  float *local_d0 [2];
  float *local_c8 [38];
  float *local_30;
  float **local_2c;
  float **local_28;
  float local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  
  *param_1 = 0;
  param_1[10] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  puVar10 = DAT_00740a68;
  uVar2 = *in_EAX;
  uVar3 = in_EAX[1];
  uVar4 = in_EAX[2];
  local_28 = &local_30;
  local_30 = &local_e0;
  local_24 = 0.0;
  local_20 = 0x7f7fffff;
  local_1c = 0;
  local_18 = 0;
  local_e0 = 0.0;
  local_dc = 0;
  local_d8 = 0;
  local_d4 = 0x3f800000;
  local_2c = local_d0;
  puVar8 = (undefined4 *)NullUpdate_ret();
  ppfVar11 = local_d0;
  puVar5 = DAT_00743c10;
  do {
    DAT_00743c10 = puVar5;
    if (((puVar10 == puVar8) || (9 < local_18)) || (local_28 <= ppfVar11)) {
      puVar10 = (undefined4 *)NullUpdate_ret();
      local_f8 = local_24;
      for (; puVar5 != puVar10; puVar5 = (undefined4 *)*puVar5) {
        local_24 = local_f8;
        if (puVar5[10] != 0) {
          for (puVar8 = (undefined4 *)puVar5[0xb];
              (puVar8 != (undefined4 *)0x0 && (puVar8 != puVar5 + 0xb));
              puVar8 = (undefined4 *)*puVar8) {
            FUN_005411b0(uVar2,uVar3,uVar4);
          }
        }
        ppfVar11 = local_2c;
        local_f8 = local_24;
      }
      local_f4 = _K_ONE - local_f8;
      if (_K_ONE < local_f8) {
        local_f4 = 0.0;
        local_f8 = _K_ONE / local_f8;
      }
      fVar6 = local_f4 * *local_30;
      fVar7 = local_f4 * local_30[1];
      local_f0 = local_f4 * local_30[2];
      local_ec = local_f4 * local_30[3];
      if (local_d0 < ppfVar11) {
        iVar9 = ((uint)((int)ppfVar11 + (-1 - (int)local_d0)) >> 4) + 1;
        ppfVar11 = local_d0 + 2;
        do {
          iVar9 = iVar9 + -1;
          fVar6 = local_f8 * (float)ppfVar11[-2] + fVar6;
          fVar7 = local_f8 * (float)ppfVar11[-1] + fVar7;
          local_f0 = local_f8 * (float)*ppfVar11 + local_f0;
          local_ec = local_f8 * (float)ppfVar11[1] + local_ec;
          ppfVar11 = ppfVar11 + 4;
        } while (iVar9 != 0);
      }
      param_1[0x14] = fVar6;
      param_1[0x17] = local_ec;
      param_1[0x15] = fVar7;
      param_1[0x16] = local_f0;
      return local_18;
    }
    if ((*(int *)puVar10[3] != 0) && (iVar9 = FUN_0058dc50(uVar2,uVar3,uVar4), iVar9 != 0)) {
      iVar9 = extraout_ECX;
      if (0 < *(short *)(extraout_ECX + 0xe)) {
        iVar9 = WorldZone_NodeWalk(extraout_ECX,uVar2,uVar3,uVar4);
      }
      if (iVar9 != 0) {
        sVar1 = *(short *)(iVar9 + 0xe);
        iVar9 = 0;
        if (0 < -(int)sVar1) {
          do {
            if (9 < local_18) break;
            FUN_005411b0(uVar2,uVar3,uVar4);
            iVar9 = iVar9 + 1;
          } while (iVar9 < -(int)sVar1);
        }
      }
    }
    puVar10 = (undefined4 *)*puVar10;
    ppfVar11 = local_2c;
    puVar5 = DAT_00743c10;
  } while( true );
}


// ==== 0x5416e0 FUN_005416e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005416e0(float *param_1,float param_2,float param_3,float param_4,float param_5)

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
  float *in_EAX;
  
  fVar2 = param_1[2];
  fVar1 = param_1[1];
  fVar3 = param_1[3];
  fVar10 = param_5 * param_5 * 3.0 - _K_ONE;
  fVar8 = param_3 * param_3 - param_4 * param_4;
  fVar4 = *param_1 * param_2;
  fVar7 = fVar4 * 0.488603;
  fVar6 = param_3 * fVar4 * 1.092548;
  fVar5 = fVar4 * 0.315392 * fVar10;
  *in_EAX = (fVar4 * 0.282095 * 0.886227 - fVar5 * 0.247708) + *in_EAX;
  fVar9 = fVar4 * 0.546274 * fVar8 * 0.429043;
  in_EAX[4] = fVar9 + in_EAX[4];
  in_EAX[8] = in_EAX[8] - fVar9;
  in_EAX[0xc] = fVar5 * 0.743125 + in_EAX[0xc];
  in_EAX[0x10] = param_4 * fVar6 * 0.858086 + in_EAX[0x10];
  in_EAX[0x14] = fVar6 * param_5 * 0.858086 + in_EAX[0x14];
  in_EAX[0x18] = fVar4 * 1.092548 * param_4 * param_5 * 0.429043 + in_EAX[0x18];
  in_EAX[0x1c] = fVar7 * param_3 * 1.023328 + in_EAX[0x1c];
  in_EAX[0x20] = param_4 * fVar7 * 1.023328 + in_EAX[0x20];
  in_EAX[0x24] = param_5 * fVar7 * 1.023328 + in_EAX[0x24];
  fVar1 = fVar1 * param_2;
  fVar6 = fVar1 * 0.488603;
  fVar5 = param_3 * fVar1 * 1.092548;
  fVar4 = fVar1 * 0.315392 * fVar10;
  in_EAX[1] = (fVar1 * 0.282095 * 0.886227 - fVar4 * 0.247708) + in_EAX[1];
  fVar7 = fVar1 * 0.546274 * fVar8 * 0.429043;
  in_EAX[5] = fVar7 + in_EAX[5];
  in_EAX[9] = in_EAX[9] - fVar7;
  in_EAX[0xd] = fVar4 * 0.743125 + in_EAX[0xd];
  in_EAX[0x11] = param_4 * fVar5 * 0.858086 + in_EAX[0x11];
  in_EAX[0x15] = fVar5 * param_5 * 0.858086 + in_EAX[0x15];
  in_EAX[0x19] = fVar1 * 1.092548 * param_4 * param_5 * 0.429043 + in_EAX[0x19];
  in_EAX[0x1d] = fVar6 * param_3 * 1.023328 + in_EAX[0x1d];
  in_EAX[0x21] = param_4 * fVar6 * 1.023328 + in_EAX[0x21];
  in_EAX[0x25] = param_5 * fVar6 * 1.023328 + in_EAX[0x25];
  fVar2 = fVar2 * param_2;
  fVar5 = fVar2 * 0.488603;
  fVar4 = param_3 * fVar2 * 1.092548;
  fVar1 = fVar2 * 0.315392 * fVar10;
  in_EAX[2] = (fVar2 * 0.282095 * 0.886227 - fVar1 * 0.247708) + in_EAX[2];
  fVar6 = fVar2 * 0.546274 * fVar8 * 0.429043;
  in_EAX[6] = fVar6 + in_EAX[6];
  in_EAX[10] = in_EAX[10] - fVar6;
  in_EAX[0xe] = fVar1 * 0.743125 + in_EAX[0xe];
  in_EAX[0x12] = param_4 * fVar4 * 0.858086 + in_EAX[0x12];
  in_EAX[0x16] = fVar4 * param_5 * 0.858086 + in_EAX[0x16];
  in_EAX[0x1a] = fVar2 * 1.092548 * param_4 * param_5 * 0.429043 + in_EAX[0x1a];
  in_EAX[0x1e] = fVar5 * param_3 * 1.023328 + in_EAX[0x1e];
  in_EAX[0x22] = param_4 * fVar5 * 1.023328 + in_EAX[0x22];
  in_EAX[0x26] = param_5 * fVar5 * 1.023328 + in_EAX[0x26];
  fVar3 = fVar3 * param_2;
  fVar2 = fVar3 * 0.488603;
  fVar1 = param_3 * fVar3 * 1.092548;
  fVar10 = fVar3 * 0.315392 * fVar10;
  in_EAX[3] = (fVar3 * 0.282095 * 0.886227 - fVar10 * 0.247708) + in_EAX[3];
  fVar4 = fVar3 * 0.546274 * fVar8 * 0.429043;
  in_EAX[7] = fVar4 + in_EAX[7];
  in_EAX[0xb] = in_EAX[0xb] - fVar4;
  in_EAX[0xf] = fVar10 * 0.743125 + in_EAX[0xf];
  in_EAX[0x13] = param_4 * fVar1 * 0.858086 + in_EAX[0x13];
  in_EAX[0x17] = fVar1 * param_5 * 0.858086 + in_EAX[0x17];
  in_EAX[0x1b] = fVar3 * 1.092548 * param_4 * param_5 * 0.429043 + in_EAX[0x1b];
  in_EAX[0x1f] = fVar2 * param_3 * 1.023328 + in_EAX[0x1f];
  in_EAX[0x23] = param_4 * fVar2 * 1.023328 + in_EAX[0x23];
  in_EAX[0x27] = param_5 * fVar2 * 1.023328 + in_EAX[0x27];
  return;
}


// ==== 0x541bf0 FUN_00541bf0

void __fastcall FUN_00541bf0(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *param_1;
  fVar2 = param_1[1];
  fVar3 = param_1[2];
  FUN_005416e0(0x3f800000,fVar1,fVar2,fVar3);
  FUN_005416e0(0x3f800000,-fVar1,-fVar2,-fVar3);
  return;
}


// ==== 0x541c90 FUN_00541c90

void FUN_00541c90(int param_1)

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
  float *in_EAX;
  float *pfVar26;
  int iVar27;
  
  fVar4 = *in_EAX;
  fVar5 = in_EAX[4];
  fVar6 = in_EAX[8];
  fVar7 = in_EAX[1];
  fVar8 = in_EAX[5];
  fVar9 = in_EAX[9];
  fVar10 = in_EAX[2];
  fVar11 = in_EAX[6];
  fVar12 = in_EAX[10];
  iVar27 = 4;
  pfVar26 = (float *)(param_1 + 0x20);
  do {
    fVar13 = pfVar26[8];
    fVar1 = pfVar26[-4];
    fVar2 = *pfVar26;
    fVar14 = pfVar26[0xc];
    fVar3 = pfVar26[4];
    fVar15 = pfVar26[0x10];
    fVar16 = pfVar26[0x14];
    fVar17 = pfVar26[0x18];
    fVar18 = pfVar26[0x1c];
    pfVar26[-8] = pfVar26[-8];
    pfVar26[-4] = fVar1 * fVar4 * fVar4 +
                  (fVar13 * fVar4 + fVar2 * fVar5) * fVar5 +
                  (fVar14 * fVar4 + fVar3 * fVar6 + fVar15 * fVar5) * fVar6;
    *pfVar26 = fVar1 * fVar7 * fVar7 +
               (fVar13 * fVar7 + fVar2 * fVar8) * fVar8 +
               (fVar14 * fVar7 + fVar9 * fVar3 + fVar15 * fVar8) * fVar9;
    fVar23 = fVar15 * fVar11;
    fVar21 = fVar3 * fVar12;
    fVar24 = fVar14 * fVar10;
    fVar20 = fVar2 * fVar11;
    fVar22 = fVar13 * fVar10;
    fVar19 = fVar1 * fVar10;
    pfVar26[4] = fVar19 * fVar10 + (fVar22 + fVar20) * fVar11 + (fVar24 + fVar21 + fVar23) * fVar12;
    fVar25 = fVar1 * fVar7 * fVar4;
    fVar2 = fVar2 * fVar8 * fVar5;
    fVar1 = fVar9 * fVar3 * fVar6;
    pfVar26[8] = fVar15 * fVar8 * fVar6 +
                 fVar1 + fVar1 +
                 fVar14 * fVar7 * fVar6 +
                 fVar2 + fVar2 +
                 fVar13 * fVar7 * fVar5 +
                 fVar25 + fVar25 +
                 fVar13 * fVar8 * fVar4 + fVar14 * fVar9 * fVar4 + fVar15 * fVar9 * fVar5;
    iVar27 = iVar27 + -1;
    pfVar26[0xc] = fVar23 * fVar6 +
                   fVar21 * fVar6 + fVar21 * fVar6 +
                   fVar24 * fVar6 +
                   fVar20 * fVar5 + fVar20 * fVar5 +
                   fVar22 * fVar5 +
                   fVar19 * fVar4 + fVar19 * fVar4 +
                   fVar15 * fVar12 * fVar5 + (fVar13 * fVar11 + fVar14 * fVar12) * fVar4;
    pfVar26[0x10] =
         fVar23 * fVar9 +
         fVar21 * fVar9 + fVar21 * fVar9 +
         fVar24 * fVar9 +
         fVar20 * fVar8 + fVar20 * fVar8 +
         fVar22 * fVar8 +
         fVar19 * fVar7 + fVar19 * fVar7 +
         fVar15 * fVar12 * fVar8 + (fVar13 * fVar11 + fVar14 * fVar12) * fVar7;
    pfVar26[0x14] = fVar16 * fVar4 + fVar17 * fVar5 + fVar18 * fVar6;
    pfVar26[0x18] = fVar16 * fVar7 + fVar17 * fVar8 + fVar18 * fVar9;
    pfVar26[0x1c] = fVar16 * fVar10 + fVar17 * fVar11 + fVar18 * fVar12;
    pfVar26 = pfVar26 + 1;
  } while (iVar27 != 0);
  return;
}


// ==== 0x541fc0 FUN_00541fc0

void __thiscall FUN_00541fc0(float *param_1,float param_2,int param_3,float param_4)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  float *pfVar3;
  int iVar4;
  
  if (in_EAX != 0) {
    fVar2 = param_1[4] * param_1[4] +
            param_1[0x24] * param_1[0x24] +
            *param_1 * *param_1 +
            param_1[0x20] * param_1[0x20] +
            param_1[0x1c] * param_1[0x1c] +
            param_1[0x18] * param_1[0x18] +
            param_1[0x14] * param_1[0x14] +
            param_1[0x10] * param_1[0x10] + param_1[0xc] * param_1[0xc] + param_1[8] * param_1[8];
    fVar1 = 0.0;
    if (0.0 < fVar2) {
      fVar1 = fVar2;
    }
    fVar2 = param_1[0x25] * param_1[0x25] +
            param_1[0x21] * param_1[0x21] +
            param_1[0x1d] * param_1[0x1d] +
            param_1[0x19] * param_1[0x19] +
            param_1[0x15] * param_1[0x15] +
            param_1[0x11] * param_1[0x11] +
            param_1[0xd] * param_1[0xd] +
            param_1[9] * param_1[9] + param_1[5] * param_1[5] + param_1[1] * param_1[1];
    if (fVar1 < fVar2) {
      fVar1 = fVar2;
    }
    fVar2 = param_1[0x26] * param_1[0x26] +
            param_1[0x22] * param_1[0x22] +
            param_1[0x1e] * param_1[0x1e] +
            param_1[0x1a] * param_1[0x1a] +
            param_1[0x16] * param_1[0x16] +
            param_1[0x12] * param_1[0x12] +
            param_1[0xe] * param_1[0xe] +
            param_1[10] * param_1[10] + param_1[6] * param_1[6] + param_1[2] * param_1[2];
    if (fVar1 < fVar2) {
      fVar1 = fVar2;
    }
    if (0.0 < SQRT(fVar1)) {
      param_2 = param_2 / SQRT(fVar1);
      iVar4 = 3;
      pfVar3 = param_1 + 8;
      do {
        iVar4 = iVar4 + -1;
        pfVar3[-8] = param_2 * pfVar3[-8];
        pfVar3[-4] = param_2 * pfVar3[-4];
        *pfVar3 = param_2 * *pfVar3;
        pfVar3[4] = param_2 * pfVar3[4];
        pfVar3[8] = param_2 * pfVar3[8];
        pfVar3[0xc] = param_2 * pfVar3[0xc];
        pfVar3[0x10] = param_2 * pfVar3[0x10];
        pfVar3[0x14] = param_2 * pfVar3[0x14];
        pfVar3[0x18] = param_2 * pfVar3[0x18];
        pfVar3[0x1c] = param_2 * pfVar3[0x1c];
        pfVar3 = pfVar3 + 1;
      } while (iVar4 != 0);
    }
  }
  if ((param_3 != 0) &&
     (fVar1 = SQRT(param_1[0x27] * param_1[0x27] +
                   param_1[0x23] * param_1[0x23] +
                   param_1[0x1f] * param_1[0x1f] +
                   param_1[0x1b] * param_1[0x1b] +
                   param_1[0x17] * param_1[0x17] +
                   param_1[0x13] * param_1[0x13] +
                   param_1[0xf] * param_1[0xf] +
                   param_1[0xb] * param_1[0xb] + param_1[7] * param_1[7] + param_1[3] * param_1[3]),
     0.0 < fVar1)) {
    param_4 = param_4 / fVar1;
    param_1[3] = param_4 * param_1[3];
    param_1[7] = param_4 * param_1[7];
    param_1[0xb] = param_4 * param_1[0xb];
    param_1[0xf] = param_4 * param_1[0xf];
    param_1[0x13] = param_4 * param_1[0x13];
    param_1[0x17] = param_4 * param_1[0x17];
    param_1[0x1b] = param_4 * param_1[0x1b];
    param_1[0x1f] = param_4 * param_1[0x1f];
    param_1[0x23] = param_4 * param_1[0x23];
    param_1[0x27] = param_4 * param_1[0x27];
    return;
  }
  return;
}


// ==== 0x542360 FUN_00542360

void FUN_00542360(float param_1,float param_2,float param_3)

{
  float *unaff_ESI;
  float local_8;
  float local_4;
  
  _ftol_nocw();
  Angle16SinCos();
  _ftol_nocw();
  Angle16SinCos();
  *unaff_ESI = param_1 * local_8 * param_3;
  unaff_ESI[1] = param_1 * local_4 * param_3;
  unaff_ESI[2] = param_2 * param_3;
  return;
}


// ==== 0x542400 FUN_00542400

void __thiscall FUN_00542400(int param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 *puVar1;
  int iVar2;
  undefined4 unaff_ESI;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 local_f0 [7];
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
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined1 auStack_70 [12];
  undefined1 auStack_64 [12];
  undefined1 auStack_58 [8];
  undefined1 local_50 [4];
  undefined4 uStack_4c;
  undefined4 uStack_3c;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  puVar1 = local_f0 + 2;
  iVar2 = 10;
  do {
    puVar1[1] = 0;
    *puVar1 = 0;
    puVar1[-1] = 0;
    puVar1[-2] = 0;
    puVar1 = puVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_00542940();
  D3DXMatrixTranspose();
  uStack_128 = *(undefined4 *)(in_EAX + 0x40);
  uStack_124 = *(undefined4 *)(in_EAX + 0x50);
  uStack_120 = *(undefined4 *)(in_EAX + 0x60);
  uStack_118 = *(undefined4 *)(in_EAX + 0x44);
  uStack_114 = *(undefined4 *)(in_EAX + 0x54);
  uStack_110 = *(undefined4 *)(in_EAX + 100);
  uStack_108 = *(undefined4 *)(in_EAX + 0x48);
  uStack_104 = *(undefined4 *)(in_EAX + 0x58);
  uStack_100 = *(undefined4 *)(in_EAX + 0x68);
  puVar1 = &uStack_128;
  uStack_4c = 0;
  uStack_3c = 0;
  uStack_2c = 0;
  uStack_1c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_11c = 0;
  uStack_10c = 0;
  uStack_fc = 0;
  thunk_FUN_005ac436(puVar1,&uStack_128);
  thunk_FUN_005ac436(&uStack_124);
  thunk_FUN_005ac436(&uStack_120,&uStack_120,auStack_70);
  *(undefined4 **)(param_1 + 0x40) = &uStack_124;
  *(undefined1 **)(param_1 + 0x50) = auStack_64;
  *(undefined4 **)(param_1 + 0x60) = puVar1;
  *(undefined1 **)(param_1 + 0x44) = auStack_58;
  *(undefined1 **)(param_1 + 0x54) = local_50;
  *(undefined4 *)(param_1 + 100) = param_2;
  *(undefined4 *)(param_1 + 0x48) = unaff_ESI;
  *(undefined4 *)(param_1 + 0x58) = uStack_128;
  *(undefined4 *)(param_1 + 0x68) = uStack_124;
  uStack_11c = *(undefined4 *)(in_EAX + 0x120);
  uStack_118 = *(undefined4 *)(in_EAX + 0x124);
  uStack_114 = *(undefined4 *)(in_EAX + 0x128);
  uStack_110 = *(undefined4 *)(in_EAX + 300);
  uStack_10c = *(undefined4 *)(in_EAX + 0x130);
  uStack_108 = *(undefined4 *)(in_EAX + 0x134);
  uStack_104 = *(undefined4 *)(in_EAX + 0x138);
  uStack_100 = *(undefined4 *)(in_EAX + 0x13c);
  uStack_f4 = *(undefined4 *)(in_EAX + 0x148);
  uStack_fc = *(undefined4 *)(in_EAX + 0x140);
  uStack_f8 = *(undefined4 *)(in_EAX + 0x144);
  local_f0[2] = *(undefined4 *)(in_EAX + 0x154);
  local_f0[0] = *(undefined4 *)(in_EAX + 0x14c);
  local_f0[1] = *(undefined4 *)(in_EAX + 0x150);
  local_f0[5] = *(undefined4 *)(in_EAX + 0x160);
  local_f0[3] = *(undefined4 *)(in_EAX + 0x158);
  local_f0[4] = *(undefined4 *)(in_EAX + 0x15c);
  uStack_d0 = *(undefined4 *)(in_EAX + 0x16c);
  local_f0[6] = *(undefined4 *)(in_EAX + 0x164);
  uStack_d4 = *(undefined4 *)(in_EAX + 0x168);
  uStack_c4 = *(undefined4 *)(in_EAX + 0x178);
  uStack_cc = *(undefined4 *)(in_EAX + 0x170);
  uStack_c8 = *(undefined4 *)(in_EAX + 0x174);
  uStack_b8 = *(undefined4 *)(in_EAX + 0x184);
  uStack_c0 = *(undefined4 *)(in_EAX + 0x17c);
  uStack_bc = *(undefined4 *)(in_EAX + 0x180);
  uStack_ac = *(undefined4 *)(in_EAX + 400);
  uStack_b4 = *(undefined4 *)(in_EAX + 0x188);
  uStack_b0 = *(undefined4 *)(in_EAX + 0x18c);
  uStack_a0 = *(undefined4 *)(in_EAX + 0x19c);
  uStack_a8 = *(undefined4 *)(in_EAX + 0x194);
  uStack_a4 = *(undefined4 *)(in_EAX + 0x198);
  uStack_94 = *(undefined4 *)(in_EAX + 0x1a8);
  uStack_9c = *(undefined4 *)(in_EAX + 0x1a0);
  uStack_98 = *(undefined4 *)(in_EAX + 0x1a4);
  uStack_88 = *(undefined4 *)(in_EAX + 0x1b4);
  uStack_90 = *(undefined4 *)(in_EAX + 0x1ac);
  uStack_8c = *(undefined4 *)(in_EAX + 0x1b0);
  uStack_84 = *(undefined4 *)(in_EAX + 0x1b8);
  uStack_80 = *(undefined4 *)(in_EAX + 0x1bc);
  FUN_00541c90(&uStack_11c);
  *(undefined4 *)(param_1 + 0x120) = uStack_11c;
  *(undefined4 *)(param_1 + 0x124) = uStack_118;
  *(undefined4 *)(param_1 + 0x128) = uStack_114;
  *(undefined4 *)(param_1 + 300) = uStack_110;
  *(undefined4 *)(param_1 + 0x130) = uStack_10c;
  *(undefined4 *)(param_1 + 0x134) = uStack_108;
  *(undefined4 *)(param_1 + 0x138) = uStack_104;
  *(undefined4 *)(param_1 + 0x13c) = uStack_100;
  *(undefined4 *)(param_1 + 0x140) = uStack_fc;
  *(undefined4 *)(param_1 + 0x144) = uStack_f8;
  *(undefined4 *)(param_1 + 0x148) = uStack_f4;
  *(undefined4 *)(param_1 + 0x14c) = local_f0[0];
  *(undefined4 *)(param_1 + 0x150) = local_f0[1];
  *(undefined4 *)(param_1 + 0x154) = local_f0[2];
  *(undefined4 *)(param_1 + 0x158) = local_f0[3];
  *(undefined4 *)(param_1 + 0x15c) = local_f0[4];
  *(undefined4 *)(param_1 + 0x160) = local_f0[5];
  *(undefined4 *)(param_1 + 0x164) = local_f0[6];
  *(undefined4 *)(param_1 + 0x168) = uStack_d4;
  *(undefined4 *)(param_1 + 0x16c) = uStack_d0;
  *(undefined4 *)(param_1 + 0x170) = uStack_cc;
  *(undefined4 *)(param_1 + 0x174) = uStack_c8;
  *(undefined4 *)(param_1 + 0x178) = uStack_c4;
  *(undefined4 *)(param_1 + 0x17c) = uStack_c0;
  *(undefined4 *)(param_1 + 0x180) = uStack_bc;
  *(undefined4 *)(param_1 + 0x184) = uStack_b8;
  *(undefined4 *)(param_1 + 0x188) = uStack_b4;
  *(undefined4 *)(param_1 + 0x18c) = uStack_b0;
  *(undefined4 *)(param_1 + 400) = uStack_ac;
  *(undefined4 *)(param_1 + 0x194) = uStack_a8;
  *(undefined4 *)(param_1 + 0x198) = uStack_a4;
  *(undefined4 *)(param_1 + 0x19c) = uStack_a0;
  *(undefined4 *)(param_1 + 0x1a0) = uStack_9c;
  *(undefined4 *)(param_1 + 0x1a4) = uStack_98;
  *(undefined4 *)(param_1 + 0x1a8) = uStack_94;
  *(undefined4 *)(param_1 + 0x1ac) = uStack_90;
  *(undefined4 *)(param_1 + 0x1b0) = uStack_8c;
  *(undefined4 *)(param_1 + 0x1b4) = uStack_88;
  *(undefined4 *)(param_1 + 0x1b8) = uStack_84;
  *(undefined4 *)(param_1 + 0x1bc) = uStack_80;
  return;
}


// ==== 0x542940 FUN_00542940

void __fastcall FUN_00542940(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int unaff_ESI;
  int unaff_EDI;
  
  bMatrixCopy_b(param_1);
  bMatrixCopy_b();
  bMatrixCopy_b();
  uVar1 = *(undefined4 *)(unaff_EDI + 200);
  uVar2 = *(undefined4 *)(unaff_EDI + 0xcc);
  uVar3 = *(undefined4 *)(unaff_EDI + 0xc0);
  *(undefined4 *)(unaff_ESI + 0xc4) = *(undefined4 *)(unaff_EDI + 0xc4);
  *(undefined4 *)(unaff_ESI + 0xc0) = uVar3;
  *(undefined4 *)(unaff_ESI + 200) = uVar1;
  *(undefined4 *)(unaff_ESI + 0xcc) = uVar2;
  *(undefined4 *)(unaff_ESI + 0xd0) = *(undefined4 *)(unaff_EDI + 0xd0);
  *(undefined4 *)(unaff_ESI + 0xd4) = *(undefined4 *)(unaff_EDI + 0xd4);
  *(undefined4 *)(unaff_ESI + 0xd8) = *(undefined4 *)(unaff_EDI + 0xd8);
  *(undefined4 *)(unaff_ESI + 0xdc) = *(undefined4 *)(unaff_EDI + 0xdc);
  bMatrixCopy_b(uVar2);
  uVar1 = *(undefined4 *)(unaff_EDI + 0x128);
  uVar2 = *(undefined4 *)(unaff_EDI + 300);
  uVar3 = *(undefined4 *)(unaff_EDI + 0x120);
  *(undefined4 *)(unaff_ESI + 0x124) = *(undefined4 *)(unaff_EDI + 0x124);
  *(undefined4 *)(unaff_ESI + 0x120) = uVar3;
  *(undefined4 *)(unaff_ESI + 0x128) = uVar1;
  *(undefined4 *)(unaff_ESI + 300) = uVar2;
  uVar2 = *(undefined4 *)(unaff_EDI + 0x130);
  uVar1 = *(undefined4 *)(unaff_EDI + 0x138);
  uVar3 = *(undefined4 *)(unaff_EDI + 0x13c);
  *(undefined4 *)(unaff_ESI + 0x134) = *(undefined4 *)(unaff_EDI + 0x134);
  *(undefined4 *)(unaff_ESI + 0x130) = uVar2;
  *(undefined4 *)(unaff_ESI + 0x138) = uVar1;
  *(undefined4 *)(unaff_ESI + 0x13c) = uVar3;
  uVar2 = *(undefined4 *)(unaff_EDI + 0x140);
  uVar1 = *(undefined4 *)(unaff_EDI + 0x148);
  uVar3 = *(undefined4 *)(unaff_EDI + 0x14c);
  *(undefined4 *)(unaff_ESI + 0x144) = *(undefined4 *)(unaff_EDI + 0x144);
  *(undefined4 *)(unaff_ESI + 0x140) = uVar2;
  *(undefined4 *)(unaff_ESI + 0x148) = uVar1;
  *(undefined4 *)(unaff_ESI + 0x14c) = uVar3;
  uVar2 = *(undefined4 *)(unaff_EDI + 0x150);
  uVar1 = *(undefined4 *)(unaff_EDI + 0x158);
  uVar3 = *(undefined4 *)(unaff_EDI + 0x15c);
  *(undefined4 *)(unaff_ESI + 0x154) = *(undefined4 *)(unaff_EDI + 0x154);
  *(undefined4 *)(unaff_ESI + 0x150) = uVar2;
  *(undefined4 *)(unaff_ESI + 0x158) = uVar1;
  *(undefined4 *)(unaff_ESI + 0x15c) = uVar3;
  uVar1 = *(undefined4 *)(unaff_EDI + 0x164);
  uVar2 = *(undefined4 *)(unaff_EDI + 0x168);
  uVar3 = *(undefined4 *)(unaff_EDI + 0x16c);
  *(undefined4 *)(unaff_ESI + 0x160) = *(undefined4 *)(unaff_EDI + 0x160);
  *(undefined4 *)(unaff_ESI + 0x164) = uVar1;
  *(undefined4 *)(unaff_ESI + 0x16c) = uVar3;
  *(undefined4 *)(unaff_ESI + 0x168) = uVar2;
  uVar3 = *(undefined4 *)(unaff_EDI + 0x17c);
  uVar1 = *(undefined4 *)(unaff_EDI + 0x174);
  uVar2 = *(undefined4 *)(unaff_EDI + 0x178);
  *(undefined4 *)(unaff_ESI + 0x170) = *(undefined4 *)(unaff_EDI + 0x170);
  *(undefined4 *)(unaff_ESI + 0x174) = uVar1;
  *(undefined4 *)(unaff_ESI + 0x17c) = uVar3;
  *(undefined4 *)(unaff_ESI + 0x178) = uVar2;
  uVar3 = *(undefined4 *)(unaff_EDI + 0x18c);
  uVar1 = *(undefined4 *)(unaff_EDI + 0x184);
  uVar2 = *(undefined4 *)(unaff_EDI + 0x188);
  *(undefined4 *)(unaff_ESI + 0x180) = *(undefined4 *)(unaff_EDI + 0x180);
  *(undefined4 *)(unaff_ESI + 0x184) = uVar1;
  *(undefined4 *)(unaff_ESI + 0x18c) = uVar3;
  *(undefined4 *)(unaff_ESI + 0x188) = uVar2;
  uVar3 = *(undefined4 *)(unaff_EDI + 0x19c);
  uVar1 = *(undefined4 *)(unaff_EDI + 0x194);
  uVar2 = *(undefined4 *)(unaff_EDI + 0x198);
  *(undefined4 *)(unaff_ESI + 400) = *(undefined4 *)(unaff_EDI + 400);
  *(undefined4 *)(unaff_ESI + 0x194) = uVar1;
  *(undefined4 *)(unaff_ESI + 0x19c) = uVar3;
  *(undefined4 *)(unaff_ESI + 0x198) = uVar2;
  uVar3 = *(undefined4 *)(unaff_EDI + 0x1ac);
  uVar1 = *(undefined4 *)(unaff_EDI + 0x1a4);
  uVar2 = *(undefined4 *)(unaff_EDI + 0x1a8);
  *(undefined4 *)(unaff_ESI + 0x1a0) = *(undefined4 *)(unaff_EDI + 0x1a0);
  *(undefined4 *)(unaff_ESI + 0x1a4) = uVar1;
  *(undefined4 *)(unaff_ESI + 0x1ac) = uVar3;
  *(undefined4 *)(unaff_ESI + 0x1a8) = uVar2;
  uVar1 = *(undefined4 *)(unaff_EDI + 0x1b4);
  uVar3 = *(undefined4 *)(unaff_EDI + 0x1b0);
  uVar2 = *(undefined4 *)(unaff_EDI + 0x1b8);
  *(undefined4 *)(unaff_ESI + 0x1bc) = *(undefined4 *)(unaff_EDI + 0x1bc);
  *(undefined4 *)(unaff_ESI + 0x1b4) = uVar1;
  *(undefined4 *)(unaff_ESI + 0x1b0) = uVar3;
  *(undefined4 *)(unaff_ESI + 0x1b8) = uVar2;
  return;
}


// ==== 0x542c20 FUN_00542c20

undefined4 FUN_00542c20(int param_1,int param_2)

{
  float *in_EAX;
  int unaff_EDI;
  float fVar1;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  undefined1 auStack_58 [8];
  undefined1 local_50 [4];
  undefined4 uStack_4c;
  undefined4 uStack_3c;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  D3DXMatrixTranspose(local_50,param_1);
  uStack_4c = 0;
  uStack_3c = 0;
  uStack_2c = 0;
  uStack_1c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  if (in_EAX != (float *)0x0) {
    fStack_68 = *in_EAX - *(float *)(param_1 + 0x30);
    fStack_64 = in_EAX[1] - *(float *)(param_1 + 0x34);
    fStack_5c = 1.0;
    fStack_60 = in_EAX[2] - *(float *)(param_1 + 0x38);
    thunk_FUN_005ac436(&fStack_68,&fStack_68,auStack_58);
    fVar1 = SQRT(fStack_68 * fStack_68 + fStack_64 * fStack_64 + fStack_60 * fStack_60 + fStack_5c +
                 fStack_5c);
    if (2.78 <= fVar1) {
      if (2.78 < fVar1) {
        fVar1 = 2.78;
      }
    }
    else {
      fVar1 = 2.78;
    }
    fStack_5c = 0.0;
    Vec3Normalize();
    *(undefined4 *)(unaff_EDI + 0xcc) = 0x3f800000;
    fStack_60 = fVar1 * fStack_60;
    *(float *)(unaff_EDI + 200) = fStack_60;
    *(float *)(unaff_EDI + 0xc0) = fVar1 * fStack_68;
    *(float *)(unaff_EDI + 0xc4) = fVar1 * fStack_64;
  }
  if ((param_2 != 0) && (in_EAX != (float *)0x0)) {
    D3DXMatrixMultiply(unaff_EDI + 0xe0,param_1,param_2);
    *(undefined4 *)(unaff_EDI + 0xec) = 0;
    *(undefined4 *)(unaff_EDI + 0xfc) = 0;
    *(undefined4 *)(unaff_EDI + 0x10c) = 0;
    *(undefined4 *)(unaff_EDI + 0x110) = *(undefined4 *)(unaff_EDI + 0xc0);
    *(undefined4 *)(unaff_EDI + 0x114) = *(undefined4 *)(unaff_EDI + 0xc4);
    *(undefined4 *)(unaff_EDI + 0x118) = *(undefined4 *)(unaff_EDI + 200);
    *(undefined4 *)(unaff_EDI + 0x11c) = 0;
  }
  return 1;
}


// ==== 0x542dc0 FUN_00542dc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00542dc0(float param_1)

{
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  
  fVar1 = (float10)param_1 * (float10)param_1 * (float10)param_1;
  fVar2 = fVar1 * (float10)param_1;
  fVar3 = (float10)(float)fVar2 * (float10)param_1;
  fVar1 = fVar3 * (float10)param_1 * (float10)6.906e-07 +
          (float10)5.4302e-06 * fVar3 +
          fVar2 * (float10)0.000171562 +
          (float10)0.0025913713 * fVar1 +
          (float10)(float)((float10)0.031257585 * (float10)param_1 * (float10)param_1 +
                          (float10)param_1 * (float10)0.24999869 + (float10)_K_ONE);
  return (float10)_K_ONE / (fVar1 * fVar1 * fVar1 * fVar1);
}


// ==== 0x542e40 CarRender_LitBodyPathB

/* WARNING: Removing unreachable block (ram,0x00543099) */
/* WARNING: Removing unreachable block (ram,0x00543078) */
/* WARNING: Removing unreachable block (ram,0x005430b7) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render med (hopper+capstone) docs/re/misc.md */

undefined4 CarRender_LitBodyPathB(float *param_1,float *param_2,int param_3,int param_4)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  float fVar6;
  int in_EAX;
  float *pfVar7;
  int iVar8;
  undefined *puVar9;
  undefined4 *puVar10;
  int iVar11;
  float10 fVar12;
  float10 extraout_ST0;
  float fVar13;
  int iStack_4b0;
  float fStack_4a8;
  float fStack_4a4;
  float fStack_4a0;
  undefined4 uStack_49c;
  float fStack_494;
  float fStack_490;
  float fStack_48c;
  float afStack_488 [7];
  float fStack_46c;
  float fStack_468;
  float fStack_464;
  float afStack_460 [7];
  float fStack_444;
  float fStack_440;
  float fStack_43c;
  float fStack_438;
  float fStack_434;
  float fStack_430;
  float fStack_42c;
  float fStack_428;
  float fStack_424;
  float fStack_420;
  float fStack_41c;
  float fStack_418;
  float fStack_414;
  float fStack_410;
  float fStack_40c;
  float fStack_408;
  float fStack_404;
  float fStack_400;
  float fStack_3fc;
  float fStack_3f8;
  float fStack_3f4;
  float fStack_3f0;
  float fStack_3ec;
  undefined1 auStack_3e8 [8];
  undefined1 local_3e0 [4];
  undefined4 uStack_3dc;
  undefined4 uStack_3cc;
  undefined4 uStack_3bc;
  undefined4 uStack_3b8;
  undefined4 uStack_3b4;
  undefined4 uStack_3b0;
  undefined4 uStack_3ac;
  float afStack_3a8 [76];
  float afStack_278 [76];
  float afStack_148 [6];
  float fStack_130;
  float fStack_128;
  float fStack_124;
  float fStack_120;
  
  if (param_1 == (float *)0x0) {
    return 0xffffffff;
  }
  if ((in_EAX != 0) && (*(int *)(in_EAX + 0x40) != 0)) {
    param_4 = *(int *)(in_EAX + 0x40);
  }
  D3DXMatrixTranspose(local_3e0,param_4);
  pfVar7 = afStack_278;
  for (iVar8 = 0x4c; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pfVar7 = 0.0;
    pfVar7 = pfVar7 + 1;
  }
  pfVar7 = afStack_148;
  for (iVar8 = 0x4c; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pfVar7 = 0.0;
    pfVar7 = pfVar7 + 1;
  }
  pfVar7 = afStack_3a8;
  for (iVar8 = 0x4c; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pfVar7 = 0.0;
    pfVar7 = pfVar7 + 1;
  }
  uStack_3dc = 0;
  uStack_3cc = 0;
  uStack_3bc = 0;
  uStack_3ac = 0;
  uStack_3b8 = 0;
  uStack_3b4 = 0;
  uStack_3b0 = 0;
  puVar9 = &DAT_006f3e18;
  if (DAT_0077a920 != 3) {
    puVar9 = &DAT_006f3e78;
  }
  puVar10 = (undefined4 *)(puVar9 + 0x14);
  iVar8 = 0;
  do {
    pfVar7 = (float *)((int)afStack_278 + iVar8);
    FUN_00542360((float)puVar10[-2] + 180.0,90.0 - (float)puVar10[-1],0x3f800000);
    fStack_4a0 = *pfVar7;
    *pfVar7 = -*(float *)((int)afStack_278 + iVar8 + 4);
    fStack_4a8 = *pfVar7;
    *(float *)((int)afStack_278 + iVar8 + 4) = -*(float *)((int)afStack_278 + iVar8 + 8);
    fStack_4a4 = *(float *)((int)afStack_278 + iVar8 + 4);
    *(float *)((int)afStack_278 + iVar8 + 8) = fStack_4a0;
    uStack_49c = 0;
    thunk_FUN_005ac436(&fStack_4a8,&fStack_4a8,auStack_3e8);
    *(float *)((int)afStack_278 + iVar8 + 4) = fStack_4a4;
    *(float *)((int)afStack_278 + iVar8 + 8) = fStack_4a0;
    *pfVar7 = fStack_4a8;
    uVar2 = *puVar10;
    *(undefined4 *)((int)afStack_3a8 + iVar8) = uVar2;
    *(undefined4 *)((int)afStack_3a8 + iVar8 + 4) = uVar2;
    *(undefined4 *)((int)afStack_3a8 + iVar8 + 8) = uVar2;
    *(undefined4 *)((int)afStack_3a8 + iVar8 + 0xc) = 0;
    iVar8 = iVar8 + 0x10;
    puVar10 = puVar10 + 3;
  } while (iVar8 < 0x70);
  iStack_4b0 = LightTree_Query(afStack_488);
  if (0x13 < iStack_4b0 + 8) {
    iStack_4b0 = 0xb;
  }
  fVar13 = param_2[2];
  fStack_48c = *param_2;
  fVar3 = param_2[1];
  iVar8 = 0;
  if (0 < iStack_4b0) {
    iVar11 = 0;
    do {
      fVar4 = afStack_488[iVar8];
      *(float *)((int)afStack_278 + iVar11 + 0x70) = *(float *)((int)fVar4 + 0x10) - fStack_48c;
      *(float *)((int)afStack_278 + iVar11 + 0x74) = *(float *)((int)fVar4 + 0x14) - fVar3;
      *(float *)((int)afStack_278 + iVar11 + 0x78) = *(float *)((int)fVar4 + 0x18) - fVar13;
      uVar5 = *(uint *)((int)fVar4 + 0xc);
      fStack_494 = (float)(uVar5 & 0xff);
      fStack_490 = (float)(uVar5 >> 8 & 0xff);
      fVar6 = (float)(uVar5 >> 0x10 & 0xff);
      if (*(char *)((int)fVar4 + 4) == '\x03') {
        _ftol_nocw();
        fVar12 = (float10)FUN_00564b10();
        fVar1 = (float)fVar12;
        fStack_4a8 = *param_2 - *(float *)((int)fVar4 + 0x10);
        fStack_4a4 = param_2[1] - *(float *)((int)fVar4 + 0x14);
        fStack_4a0 = param_2[2] - *(float *)((int)fVar4 + 0x18);
        bNormalize3();
        fVar4 = fStack_4a8 * *(float *)((int)fVar4 + 0x20) +
                fStack_4a4 * *(float *)((int)fVar4 + 0x24) +
                fStack_4a0 * *(float *)((int)fVar4 + 0x28);
        if (fVar4 <= fVar1) {
          fVar4 = 0.0;
        }
        else {
          fVar4 = (fVar4 - fVar1) / (_K_ONE - fVar1);
        }
        fVar4 = fVar4 * afStack_460[iVar8];
        *(float *)((int)afStack_3a8 + iVar11 + 0x70) = fStack_494 * fVar4 * 1.5;
        *(float *)((int)afStack_3a8 + iVar11 + 0x74) = fStack_490 * fVar4 * 1.5;
        fVar4 = fVar4 * fVar6 * 1.5;
      }
      else {
        *(float *)((int)afStack_3a8 + iVar11 + 0x70) = fStack_494 * 1.5 * afStack_460[iVar8];
        *(float *)((int)afStack_3a8 + iVar11 + 0x74) = fStack_490 * 1.5 * afStack_460[iVar8];
        fVar4 = fVar6 * 1.5 * afStack_460[iVar8];
      }
      *(float *)((int)afStack_3a8 + iVar11 + 0x78) = fVar4;
      iVar8 = iVar8 + 1;
      iVar11 = iVar11 + 0x10;
    } while (iVar8 < iStack_4b0);
  }
  if (param_3 != 0) {
    D3DXMatrixTranspose(afStack_488,param_3);
    iVar8 = iStack_4b0 + 8;
    afStack_488[3] = 0.0;
    fStack_46c = 0.0;
    afStack_460[1] = 0.0;
    afStack_460[5] = 0.0;
    afStack_460[2] = 0.0;
    afStack_460[3] = 0.0;
    afStack_460[4] = 0.0;
    if (0 < iVar8) {
      pfVar7 = afStack_278;
      do {
        D3DXVec3Transform(pfVar7,pfVar7,afStack_488);
        pfVar7 = pfVar7 + 4;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
  }
  iStack_4b0 = iStack_4b0 + 8;
  if (0 < iStack_4b0) {
    iVar11 = 0;
    iVar8 = iStack_4b0;
    do {
      fVar13 = *(float *)((int)afStack_278 + iVar11 + 8);
      fVar3 = *(float *)((int)afStack_278 + iVar11 + 4);
      fVar13 = SQRT(fVar13 * fVar13 +
                    *(float *)((int)afStack_278 + iVar11) * *(float *)((int)afStack_278 + iVar11) +
                    fVar3 * fVar3);
      if (fVar13 == 0.0) {
        *(undefined4 *)((int)afStack_148 + iVar11) = 0x3f800000;
        *(undefined4 *)((int)afStack_148 + iVar11 + 4) = 0;
        *(undefined4 *)((int)afStack_148 + iVar11 + 8) = 0;
      }
      else {
        fVar13 = _K_ONE / fVar13;
        *(float *)((int)afStack_148 + iVar11) = fVar13 * *(float *)((int)afStack_278 + iVar11);
        *(float *)((int)afStack_148 + iVar11 + 4) =
             fVar13 * *(float *)((int)afStack_278 + iVar11 + 4);
        *(float *)((int)afStack_148 + iVar11 + 8) =
             fVar13 * *(float *)((int)afStack_278 + iVar11 + 8);
      }
      iVar11 = iVar11 + 0x10;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  fVar13 = 0.0;
  if (0 < iStack_4b0) {
    pfVar7 = afStack_3a8 + 2;
    iVar8 = iStack_4b0;
    fVar13 = 0.0;
    do {
      iVar8 = iVar8 + -1;
      pfVar7[-2] = pfVar7[-2] * _K_BLUR_MIN_T;
      pfVar7[-1] = pfVar7[-1] * _K_BLUR_MIN_T;
      *pfVar7 = *pfVar7 * _K_BLUR_MIN_T;
      pfVar7[1] = pfVar7[1] * _K_BLUR_MIN_T;
      fVar3 = *pfVar7 * 0.17 + pfVar7[-2] * 0.29 + pfVar7[-1] * 0.54;
      pfVar7[1] = fVar3;
      fVar13 = fVar3 + fVar13;
      pfVar7 = pfVar7 + 4;
    } while (iVar8 != 0);
  }
  fVar12 = (float10)FUN_00542dc0(fVar13 * _DAT_006f3ee0);
  fVar12 = (float10)_K_ONE - fVar12;
  if (_DAT_006f3ee4 < fVar13) {
    fVar12 = (float10)_DAT_006f3ee4 / (float10)fVar13;
  }
  if (0 < iStack_4b0) {
    pfVar7 = afStack_3a8 + 2;
    iVar8 = iStack_4b0;
    do {
      iVar8 = iVar8 + -1;
      pfVar7[-2] = (float)(fVar12 * (float10)pfVar7[-2]);
      pfVar7[-1] = (float)((float10)pfVar7[-1] * fVar12);
      *pfVar7 = (float)((float10)*pfVar7 * fVar12);
      pfVar7[1] = (float)((float10)pfVar7[1] * fVar12);
      pfVar7 = pfVar7 + 4;
    } while (iVar8 != 0);
  }
  pfVar7 = afStack_488 + 2;
  iVar8 = 10;
  do {
    pfVar7[1] = 0.0;
    *pfVar7 = 0.0;
    pfVar7[-1] = 0.0;
    pfVar7[-2] = 0.0;
    pfVar7 = pfVar7 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if (0 < iStack_4b0) {
    do {
      FUN_00541bf0();
      iStack_4b0 = iStack_4b0 + -1;
    } while (iStack_4b0 != 0);
  }
  FUN_00541fc0(DAT_006f3e04,DAT_006f3e08,DAT_006f3e0c);
  param_1[0x48] = afStack_488[0];
  param_1[0x49] = afStack_488[1];
  param_1[0x4a] = afStack_488[2];
  param_1[0x4b] = afStack_488[3];
  param_1[0x4c] = afStack_488[4];
  param_1[0x4d] = afStack_488[5];
  param_1[0x4e] = afStack_488[6];
  param_1[0x4f] = fStack_46c;
  param_1[0x50] = fStack_468;
  param_1[0x51] = fStack_464;
  param_1[0x52] = afStack_460[0];
  param_1[0x53] = afStack_460[1];
  param_1[0x54] = afStack_460[2];
  param_1[0x55] = afStack_460[3];
  param_1[0x56] = afStack_460[4];
  param_1[0x57] = afStack_460[5];
  param_1[0x58] = afStack_460[6];
  param_1[0x59] = fStack_444;
  param_1[0x5a] = fStack_440;
  param_1[0x5b] = fStack_43c;
  param_1[0x5c] = fStack_438;
  param_1[0x5d] = fStack_434;
  param_1[0x5e] = fStack_430;
  param_1[0x5f] = fStack_42c;
  param_1[0x60] = fStack_428;
  param_1[0x61] = fStack_424;
  param_1[0x62] = fStack_420;
  param_1[99] = fStack_41c;
  param_1[100] = fStack_418;
  param_1[0x65] = fStack_414;
  param_1[0x66] = fStack_410;
  param_1[0x67] = fStack_40c;
  param_1[0x68] = fStack_408;
  param_1[0x69] = fStack_404;
  param_1[0x6a] = fStack_400;
  afStack_3a8[0] = afStack_3a8[0] * fRam006cc974;
  param_1[0x6b] = fStack_3fc;
  param_1[0x6c] = fStack_3f8;
  param_1[0x6d] = fStack_3f4;
  param_1[0x6e] = fStack_3f0;
  param_1[0x6f] = fStack_3ec;
  *param_1 = afStack_3a8[0];
  afStack_3a8[1] = afStack_3a8[1] * fRam006cc974;
  param_1[0x10] = afStack_148[0];
  param_1[1] = afStack_3a8[1];
  param_1[0x14] = afStack_148[1];
  afStack_3a8[2] = afStack_3a8[2] * fRam006cc974;
  param_1[0x18] = afStack_148[2];
  param_1[2] = afStack_3a8[2];
  param_1[0x11] = afStack_148[4];
  afStack_3a8[4] = afStack_3a8[4] * fRam006cc974;
  param_1[0x15] = afStack_148[5];
  param_1[0x19] = fStack_130;
  param_1[4] = afStack_3a8[4];
  param_1[0x12] = fStack_128;
  afStack_3a8[5] = afStack_3a8[5] * fRam006cc974;
  param_1[0x16] = fStack_124;
  param_1[0x1a] = fStack_120;
  param_1[5] = afStack_3a8[5];
  param_1[6] = afStack_3a8[6] * fRam006cc974;
  param_1[8] = afStack_3a8[8] * fRam006cc974;
  param_1[9] = afStack_3a8[9] * fRam006cc974;
  param_1[10] = afStack_3a8[10] * fRam006cc974;
  iVar8 = _ftol_nocw();
  fVar13 = (float)iVar8;
  if (iVar8 < 0) {
    fVar13 = fVar13 + 4.2949673e+09;
  }
  param_1[0xc] = fVar13;
  iVar8 = _ftol_nocw();
  fVar13 = (float)iVar8;
  if (iVar8 < 0) {
    fVar13 = fVar13 + 4.2949673e+09;
  }
  param_1[0xd] = fVar13;
  iVar8 = _ftol_nocw();
  fVar3 = (float)iVar8;
  if (iVar8 < 0) {
    fVar3 = fVar3 + 4.2949673e+09;
  }
  param_1[0xe] = fVar3;
  if ((float10)fRam006cc974 < extraout_ST0) {
    param_1[0xc] = 255.0;
  }
  if (fRam006cc974 < fVar13) {
    param_1[0xd] = 255.0;
  }
  if (fRam006cc974 < fVar3) {
    param_1[0xe] = 255.0;
  }
  return 1;
}


// ==== 0x5437f0 CarRender_LitBodyPathA

/* WARNING: Removing unreachable block (ram,0x00543d08) */
/* WARNING: Removing unreachable block (ram,0x00543ce7) */
/* WARNING: Removing unreachable block (ram,0x00543d26) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render med (hopper+capstone) docs/re/misc.md */

undefined4 CarRender_LitBodyPathA(float *param_1,int param_2,int param_3,float *param_4,int param_5)

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
  undefined4 uVar12;
  uint uVar13;
  undefined4 *puVar14;
  float *pfVar15;
  int iVar16;
  int iVar17;
  float10 fVar18;
  float10 extraout_ST0;
  float fVar19;
  int iStack_598;
  undefined *puStack_594;
  float afStack_57c [7];
  float fStack_560;
  float fStack_55c;
  float fStack_558;
  float afStack_554 [4];
  float fStack_544;
  float fStack_540;
  float fStack_53c;
  float fStack_538;
  float fStack_534;
  float fStack_530;
  float fStack_52c;
  float fStack_528;
  float fStack_524;
  float fStack_520;
  float fStack_51c;
  float fStack_518;
  float fStack_514;
  float fStack_510;
  float fStack_50c;
  float fStack_508;
  float fStack_504;
  float fStack_500;
  float fStack_4fc;
  float fStack_4f8;
  float fStack_4f4;
  float fStack_4f0;
  float fStack_4ec;
  float fStack_4e8;
  float fStack_4e4;
  float fStack_4e0;
  float fStack_4dc;
  float fStack_4d8;
  float fStack_4d4;
  undefined4 uStack_4cc;
  undefined4 uStack_4c8;
  undefined4 uStack_4c4;
  undefined1 auStack_4bc [12];
  undefined1 auStack_4b0 [16];
  undefined1 local_4a0 [4];
  undefined4 uStack_49c;
  undefined4 uStack_48c;
  undefined4 uStack_47c;
  undefined4 uStack_478;
  undefined4 uStack_474;
  undefined4 uStack_470;
  undefined4 uStack_46c;
  undefined1 auStack_468 [4];
  undefined4 uStack_464;
  undefined4 uStack_454;
  undefined4 uStack_444;
  undefined4 uStack_440;
  float afStack_43c [76];
  float afStack_30c [76];
  undefined1 auStack_1dc [64];
  float afStack_19c [4];
  float fStack_18c;
  float fStack_188;
  float fStack_184;
  float fStack_17c;
  float fStack_178;
  float fStack_174;
  undefined1 auStack_60 [92];
  
  if ((param_1 != (float *)0x0) && (param_2 != 0)) {
    iVar16 = 0x70;
    pfVar15 = param_1;
    if (DAT_006f3edc != 0) {
      for (; iVar16 != 0; iVar16 = iVar16 + -1) {
        *pfVar15 = 0.0;
        pfVar15 = pfVar15 + 1;
      }
      FUN_00542c20(param_2,param_3);
      CarRender_LitBodyPathB(param_1,param_2 + 0x30,param_2,param_3);
      return 1;
    }
    for (; iVar16 != 0; iVar16 = iVar16 + -1) {
      *pfVar15 = 0.0;
      pfVar15 = pfVar15 + 1;
    }
    iVar16 = param_3;
    if ((param_5 != 0) && (*(int *)(param_5 + 0x40) != 0)) {
      iVar16 = *(int *)(param_5 + 0x40);
    }
    D3DXMatrixTranspose(local_4a0,param_2);
    uStack_49c = 0;
    uStack_48c = 0;
    uStack_47c = 0;
    uStack_46c = 0;
    uStack_478 = 0;
    uStack_474 = 0;
    uStack_470 = 0;
    D3DXMatrixTranspose(auStack_468,iVar16);
    uStack_464 = 0;
    uStack_454 = 0;
    uStack_444 = 0;
    afStack_43c[2] = 0.0;
    uStack_440 = 0;
    afStack_43c[0] = 0.0;
    afStack_43c[1] = 0.0;
    D3DXMatrixMultiply(auStack_60,&uStack_470,auStack_4b0);
    if (param_4 != (float *)0x0) {
      fVar1 = *param_4;
      fVar2 = *(float *)(param_2 + 0x30);
      fVar3 = param_4[1];
      fVar4 = *(float *)(param_2 + 0x34);
      fVar5 = param_4[2];
      fVar6 = *(float *)(param_2 + 0x38);
      thunk_FUN_005ac436(&stack0xfffffa54,&stack0xfffffa54,auStack_4bc);
      fVar18 = (float10)FUN_00540830();
      fVar19 = (float)fVar18;
      if ((float10)2.78 <= fVar18) {
        if (2.78 < fVar19) {
          fVar19 = 2.78;
        }
      }
      else {
        fVar19 = 2.78;
      }
      Vec3Normalize();
      bVector4Scale(fVar19);
      param_1[0x30] = fVar1 - fVar2;
      param_1[0x31] = fVar3 - fVar4;
      param_1[0x32] = fVar5 - fVar6;
      param_1[0x33] = 1.0;
    }
    CallNTimes(afStack_30c,0x10,0x13,FUN_004ad8d0);
    CallNTimes(afStack_19c,0x10,0x13,FUN_004ad8d0);
    CallNTimes(afStack_43c,0x10,0x13,FUN_004ad8d0);
    pfVar15 = afStack_30c;
    for (iVar16 = 0x4c; iVar16 != 0; iVar16 = iVar16 + -1) {
      *pfVar15 = 0.0;
      pfVar15 = pfVar15 + 1;
    }
    pfVar15 = afStack_19c;
    for (iVar16 = 0x4c; iVar16 != 0; iVar16 = iVar16 + -1) {
      *pfVar15 = 0.0;
      pfVar15 = pfVar15 + 1;
    }
    pfVar15 = afStack_43c;
    for (iVar16 = 0x4c; iVar16 != 0; iVar16 = iVar16 + -1) {
      *pfVar15 = 0.0;
      pfVar15 = pfVar15 + 1;
    }
    puStack_594 = &DAT_006f3e18;
    if (DAT_0077a920 != 3) {
      puStack_594 = &DAT_006f3e78;
    }
    if (DAT_006f3ed8 == 0) {
      fStack_4d8 = param_4[1];
      fStack_4dc = *param_4;
      uStack_4cc = *(undefined4 *)(param_2 + 0x30);
      fStack_4d4 = param_4[2];
      uStack_4c8 = *(undefined4 *)(param_2 + 0x34);
      uStack_4c4 = *(undefined4 *)(param_2 + 0x38);
      Matrix4_BuildLookAt(&stack0xfffffa54);
      eInvertRotationMatrix();
      puVar14 = (undefined4 *)(puStack_594 + 0x14);
      iVar16 = 0;
    }
    else {
      bMatrixCopy_b();
      puVar14 = (undefined4 *)(puStack_594 + 0x14);
      iVar16 = 0;
    }
    do {
      pfVar15 = (float *)((int)afStack_30c + iVar16);
      FUN_00542360((float)puVar14[-2] + 180.0,90.0 - (float)puVar14[-1],0x3f800000);
      fVar1 = *pfVar15;
      *pfVar15 = -*(float *)((int)afStack_30c + iVar16 + 4);
      fVar2 = *pfVar15;
      *(float *)((int)afStack_30c + iVar16 + 4) = -*(float *)((int)afStack_30c + iVar16 + 8);
      uVar12 = *(undefined4 *)((int)afStack_30c + iVar16 + 4);
      *(float *)((int)afStack_30c + iVar16 + 8) = fVar1;
      thunk_FUN_005ac436(&stack0xfffffa54,&stack0xfffffa54,auStack_1dc);
      *pfVar15 = fVar2;
      *(undefined4 *)((int)afStack_30c + iVar16 + 4) = uVar12;
      *(float *)((int)afStack_30c + iVar16 + 8) = fVar1;
      *(undefined4 *)((int)afStack_43c + iVar16) = *puVar14;
      *(undefined4 *)((int)afStack_43c + iVar16 + 4) = *puVar14;
      *(undefined4 *)((int)afStack_43c + iVar16 + 8) = *puVar14;
      *(undefined4 *)((int)afStack_43c + iVar16 + 0xc) = 0;
      puVar14 = puVar14 + 3;
      iVar16 = iVar16 + 0x10;
    } while (iVar16 < 0x70);
    iVar16 = LightTree_Query(afStack_57c);
    if (0x13 < iVar16 + 8) {
      iVar16 = 0xb;
    }
    fVar1 = *(float *)(param_2 + 0x30);
    fVar2 = *(float *)(param_2 + 0x34);
    fVar3 = *(float *)(param_2 + 0x38);
    puStack_594 = (undefined *)0x0;
    iStack_598 = iVar16;
    if (0 < iVar16) {
      iVar17 = 0;
      do {
        fVar4 = afStack_57c[(int)puStack_594];
        *(float *)((int)afStack_30c + iVar17 + 0x70) = *(float *)((int)fVar4 + 0x10) - fVar1;
        *(float *)((int)afStack_30c + iVar17 + 0x74) = *(float *)((int)fVar4 + 0x14) - fVar2;
        *(float *)((int)afStack_30c + iVar17 + 0x78) = *(float *)((int)fVar4 + 0x18) - fVar3;
        uVar13 = *(uint *)((int)fVar4 + 0xc);
        fVar5 = (float)(uVar13 >> 8 & 0xff);
        if (*(char *)((int)fVar4 + 4) == '\x03') {
          _ftol_nocw();
          fVar18 = (float10)FUN_00564b10();
          fVar6 = (float)fVar18;
          fVar19 = *(float *)(param_2 + 0x30);
          fVar7 = *(float *)((int)fVar4 + 0x10);
          fVar8 = *(float *)(param_2 + 0x34);
          fVar9 = *(float *)((int)fVar4 + 0x14);
          fVar10 = *(float *)(param_2 + 0x38);
          fVar11 = *(float *)((int)fVar4 + 0x18);
          bNormalize3();
          fVar4 = (fVar19 - fVar7) * *(float *)((int)fVar4 + 0x20) +
                  (fVar8 - fVar9) * *(float *)((int)fVar4 + 0x24) +
                  (fVar10 - fVar11) * *(float *)((int)fVar4 + 0x28);
          if (fVar4 <= fVar6) {
            fVar4 = 0.0;
          }
          else {
            fVar4 = (fVar4 - fVar6) / (_K_ONE - fVar6);
          }
          fVar4 = fVar4 * afStack_554[(int)puStack_594];
          *(float *)((int)afStack_43c + iVar17 + 0x70) = (float)(uVar13 & 0xff) * fVar4 * 1.5;
          *(float *)((int)afStack_43c + iVar17 + 0x74) = fVar5 * fVar4 * 1.5;
        }
        else {
          *(float *)((int)afStack_43c + iVar17 + 0x70) =
               (float)(uVar13 & 0xff) * afStack_554[(int)puStack_594] * 1.5;
          *(float *)((int)afStack_43c + iVar17 + 0x74) = fVar5 * afStack_554[(int)puStack_594] * 1.5
          ;
          fVar4 = afStack_554[(int)puStack_594];
        }
        puStack_594 = (undefined *)((int)puStack_594 + 1);
        *(float *)((int)afStack_43c + iVar17 + 0x78) = (float)(uVar13 >> 0x10 & 0xff) * fVar4 * 1.5;
        iVar17 = iVar17 + 0x10;
      } while ((int)puStack_594 < iVar16);
      iStack_598 = iVar16;
      if (0 < iVar16) {
        pfVar15 = afStack_30c + 0x1c;
        do {
          D3DXVec3Transform(pfVar15,pfVar15,auStack_4bc);
          pfVar15 = pfVar15 + 4;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
      }
    }
    iStack_598 = iStack_598 + 8;
    iVar16 = iStack_598;
    if (0 < iStack_598) {
      do {
        bNormalize3();
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
    }
    pfVar15 = afStack_57c + 2;
    iVar16 = 10;
    iVar17 = 0;
    do {
      pfVar15[1] = 0.0;
      *pfVar15 = 0.0;
      pfVar15[-1] = 0.0;
      pfVar15[-2] = 0.0;
      pfVar15 = pfVar15 + 4;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
    if (0 < iStack_598) {
      do {
        pfVar15 = (float *)((int)afStack_43c + iVar17);
        *pfVar15 = *pfVar15 * _K_BLUR_MIN_T;
        *(float *)((int)afStack_43c + iVar17 + 4) =
             *(float *)((int)afStack_43c + iVar17 + 4) * _K_BLUR_MIN_T;
        *(float *)((int)afStack_43c + iVar17 + 8) =
             *(float *)((int)afStack_43c + iVar17 + 8) * _K_BLUR_MIN_T;
        *(float *)((int)afStack_43c + iVar17 + 0xc) =
             *(float *)((int)afStack_43c + iVar17 + 0xc) * _K_BLUR_MIN_T;
        *(float *)((int)afStack_43c + iVar17 + 0xc) =
             *(float *)((int)afStack_43c + iVar17 + 8) * 0.17 +
             *pfVar15 * 0.29 + *(float *)((int)afStack_43c + iVar17 + 4) * 0.54;
        FUN_00541bf0();
        iVar17 = iVar17 + 0x10;
        iStack_598 = iStack_598 + -1;
      } while (iStack_598 != 0);
    }
    FUN_00541fc0(DAT_006f3e04,DAT_006f3e08,DAT_006f3e0c);
    param_1[0x48] = afStack_57c[0];
    param_1[0x49] = afStack_57c[1];
    param_1[0x4a] = afStack_57c[2];
    param_1[0x4b] = afStack_57c[3];
    param_1[0x4c] = afStack_57c[4];
    param_1[0x4d] = afStack_57c[5];
    param_1[0x4e] = afStack_57c[6];
    param_1[0x4f] = fStack_560;
    param_1[0x50] = fStack_55c;
    param_1[0x51] = fStack_558;
    param_1[0x52] = afStack_554[0];
    param_1[0x53] = afStack_554[1];
    param_1[0x54] = afStack_554[2];
    param_1[0x55] = afStack_554[3];
    param_1[0x56] = fStack_544;
    param_1[0x57] = fStack_540;
    param_1[0x58] = fStack_53c;
    param_1[0x59] = fStack_538;
    param_1[0x5a] = fStack_534;
    param_1[0x5b] = fStack_530;
    param_1[0x5c] = fStack_52c;
    param_1[0x5d] = fStack_528;
    param_1[0x5e] = fStack_524;
    param_1[0x5f] = fStack_520;
    param_1[0x60] = fStack_51c;
    param_1[0x61] = fStack_518;
    param_1[0x62] = fStack_514;
    param_1[99] = fStack_510;
    param_1[100] = fStack_50c;
    param_1[0x65] = fStack_508;
    param_1[0x66] = fStack_504;
    param_1[0x67] = fStack_500;
    param_1[0x68] = fStack_4fc;
    param_1[0x69] = fStack_4f8;
    param_1[0x6a] = fStack_4f4;
    param_1[0x6b] = fStack_4f0;
    param_1[0x6c] = fStack_4ec;
    param_1[0x6f] = fStack_4e0;
    param_1[0x6d] = fStack_4e8;
    param_1[0x6e] = fStack_4e4;
    if ((param_3 != 0) && (param_4 != (float *)0x0)) {
      D3DXMatrixMultiply(param_1 + 0x38,param_2,param_3);
      param_1[0x3b] = 0.0;
      param_1[0x3f] = 0.0;
      param_1[0x43] = 0.0;
      param_1[0x44] = param_1[0x30];
      param_1[0x45] = param_1[0x31];
      param_1[0x46] = param_1[0x32];
      param_1[0x47] = 0.0;
    }
    fVar1 = afStack_43c[0] * fRam006cc974;
    param_1[0x10] = afStack_19c[0];
    *param_1 = fVar1;
    param_1[0x14] = afStack_19c[1];
    fVar1 = afStack_43c[1] * fRam006cc974;
    param_1[0x18] = afStack_19c[2];
    param_1[1] = fVar1;
    param_1[0x11] = fStack_18c;
    fVar1 = afStack_43c[2] * fRam006cc974;
    param_1[0x15] = fStack_188;
    param_1[0x19] = fStack_184;
    param_1[2] = fVar1;
    param_1[0x12] = fStack_17c;
    afStack_43c[4] = afStack_43c[4] * fRam006cc974;
    param_1[0x16] = fStack_178;
    param_1[0x1a] = fStack_174;
    param_1[4] = afStack_43c[4];
    param_1[5] = afStack_43c[5] * fRam006cc974;
    param_1[6] = afStack_43c[6] * fRam006cc974;
    param_1[8] = afStack_43c[8] * fRam006cc974;
    param_1[9] = afStack_43c[9] * fRam006cc974;
    param_1[10] = afStack_43c[10] * fRam006cc974;
    iVar16 = _ftol_nocw();
    fVar1 = (float)iVar16;
    if (iVar16 < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    param_1[0xc] = fVar1;
    iVar16 = _ftol_nocw();
    fVar1 = (float)iVar16;
    if (iVar16 < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    param_1[0xd] = fVar1;
    iVar16 = _ftol_nocw();
    fVar2 = (float)iVar16;
    if (iVar16 < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    param_1[0xe] = fVar2;
    if ((float10)fRam006cc974 < extraout_ST0) {
      param_1[0xc] = 255.0;
    }
    if (fRam006cc974 < fVar1) {
      param_1[0xd] = 255.0;
    }
    if (fRam006cc974 < fVar2) {
      param_1[0xe] = 255.0;
    }
    return 1;
  }
  return 0xffffffff;
}


// ==== 0x544390 FUN_00544390

undefined4 FUN_00544390(void)

{
  if (DAT_0073554c != 0) {
    CarRender_LitBodyPathA();
    return 1;
  }
  FUN_00542400();
  FUN_00542c20();
  return 1;
}


// ==== 0x5443f0 FUN_005443f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005443f0(void)

{
  int iVar1;
  float *unaff_ESI;
  float10 fVar2;
  float in_stack_00000018;
  
  iVar1 = (&DAT_0072fa14)[(int)unaff_ESI[0xe]];
  if (iVar1 != 0) {
    fVar2 = (float10)FUN_00673890();
    fVar2 = fVar2 * (float10)in_stack_00000018;
    if ((float10)_K_ONE < fVar2) {
      fVar2 = (float10)_K_ONE;
    }
    fVar2 = ((float10)unaff_ESI[1] - (float10)*unaff_ESI) * fVar2 + (float10)*unaff_ESI;
    if (fVar2 < (float10)0.0 == (fVar2 == (float10)0.0)) {
      ePoly__ePoly();
      _ftol_nocw();
      _ftol_nocw();
      _ftol_nocw();
      _ftol_nocw();
      FUN_0040c300(iVar1,&DAT_0078bcc0,0);
      return;
    }
  }
  return;
}


// ==== 0x544790 FUN_00544790

void FUN_00544790(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = Texture_FindByHash(*(undefined4 *)((int)&DAT_006f3ee8 + uVar2),0,0);
    *(undefined4 *)((int)&DAT_0072fa14 + uVar2) = uVar1;
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0xc);
  return;
}


// ==== 0x5447c0 FUN_005447c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005447c0(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int in_EAX;
  int iVar4;
  undefined4 *puVar5;
  float *pfVar6;
  undefined4 *puVar7;
  int iVar8;
  float10 fVar9;
  undefined4 local_3e0;
  undefined4 local_3dc;
  float local_3d8;
  float local_3d4;
  float local_3d0;
  undefined4 local_3cc;
  int local_3c8;
  float local_3b8;
  float local_3b4;
  undefined4 local_3b0;
  int local_3ac;
  undefined4 local_3a8;
  float local_3a4;
  float local_3a0;
  undefined4 local_39c;
  undefined4 local_398;
  undefined4 local_394;
  undefined4 local_390;
  undefined4 local_38c;
  undefined4 local_388;
  undefined4 local_380;
  undefined4 local_37c;
  undefined4 local_378;
  undefined4 local_374;
  undefined4 local_370;
  undefined4 local_36c;
  undefined4 local_368;
  int local_354;
  undefined1 local_350 [128];
  undefined1 local_2d0 [716];
  
  if ((((DAT_006f41a0 != 0) && (puVar7 = *(undefined4 **)(param_1 + 0x40), param_2 != 0)) &&
      (in_EAX != 0)) && ((puVar7 != (undefined4 *)0x0 && (*(char *)(param_2 + 0xc) != '\0')))) {
    local_354 = (int)*(char *)(param_2 + 0xd);
    local_3b8 = (float)(int)*(short *)(param_2 + 0xe);
    if (param_6 == 0.0) {
      if ((*(int *)(param_2 + 0x1c) == 0x4479c000) || (param_4 == 1)) {
        FUN_004406d0();
        local_3dc = *(undefined4 *)(param_2 + 0x14);
        local_3e0 = *(undefined4 *)(param_2 + 0x10);
        local_3d8 = *(float *)(param_2 + 0x18);
        D3DXVec3Transform(&local_3e0,&local_3e0);
        fVar9 = (float10)GroundQuery__FindSurfaceBelow(local_2d0,&local_3e0,0,0,0);
        *(float *)(param_2 + 0x1c) = (float)fVar9;
        if ((float10)0.05 <= ABS(fVar9 - (float10)*(float *)(param_2 + 0x18))) {
          *(float *)(param_2 + 0x1c) = (float)(fVar9 - ((float10)local_3d8 - fVar9));
        }
        else {
          *(undefined4 *)(param_2 + 0x1c) = 0x461c3c00;
        }
        RefArray_DecrementAll();
      }
    }
    else {
      *(float *)(param_2 + 0x1c) = param_6;
    }
    local_3dc = *(undefined4 *)(param_2 + 0x14);
    local_3d8 = *(float *)(param_2 + 0x18);
    local_3e0 = *(undefined4 *)(param_2 + 0x10);
    FUN_00540b40();
    FUN_00540ae0(local_3e0,local_3dc,local_3d8,local_3d4);
    local_3a0 = 0.0;
    local_39c = 0;
    local_398 = 0;
    if (param_5 == 2) {
      local_3ac = *(int *)(param_2 + 0x1c);
      if ((local_3ac != 0x4479c000) && (local_3ac != 0x461c3c00)) {
        FUN_00567710();
        FUN_005677d0(DAT_006f3df4);
        iVar4 = AABB_ClassifyAgainstFrustum(param_1);
        if (iVar4 != 0) {
          FUN_00540a30();
          FUN_00540990();
          iVar4 = FUN_00540be0();
          local_398 = *(undefined4 *)(iVar4 + 8);
          local_3d4 = *(float *)(iVar4 + 0xc);
          goto LAB_00544a80;
        }
      }
    }
    else if (param_5 == 1) {
      FUN_00567710();
      FUN_005677d0(DAT_006f41a8);
      iVar4 = AABB_ClassifyAgainstFrustum(param_1);
      if (iVar4 != 0) {
LAB_00544a80:
        local_390 = 0;
        local_38c = 0;
        local_388 = 0;
        local_3e0 = 0;
        local_3dc = 0;
        local_3d8 = 0.0;
        local_380 = 0;
        local_37c = 0;
        local_378 = 0;
        FUN_00540a30();
        fVar3 = local_3b4;
        puVar5 = (undefined4 *)Vec4_SubXYZ(local_3b4,local_3b0,local_3ac,local_3a8);
        Vec4_SetXYZ(*puVar5,puVar5[1],puVar5[2],puVar5[3]);
        Vec4_DotPack(local_380,local_37c,local_378,local_374);
        fVar1 = 32000.0;
        fVar2 = 40000.0;
        local_3a4 = 1.0;
        if (param_5 == 1) {
          fVar1 = 3900.0;
          fVar2 = 4000.0;
        }
        else if (param_5 == 2) {
          fVar1 = 32000.0;
          fVar2 = 40000.0;
        }
        if (local_3d0 <= fVar2) {
          if (fVar1 < local_3d0) {
            local_3a4 = _K_ONE - (local_3d0 - fVar1) / (fVar2 - fVar1);
          }
          puVar5 = (undefined4 *)FUN_00540a60(local_350,local_3a0,local_39c,local_398,local_394);
          Vec4_SetXYZ(*puVar5,puVar5[1],puVar5[2],puVar5[3]);
          puVar5 = (undefined4 *)FUN_005409c0();
          Vec4_SetXYZ(*puVar5,puVar5[1],puVar5[2],puVar5[3]);
          pfVar6 = (float *)Vec4_DotPack(local_3e0,local_3dc,local_3d8,local_3d4);
          local_3a0 = *pfVar6;
          local_3d4 = pfVar6[3];
          if (((uint)local_3b8 & 1) == 0) {
            if (local_3a0 < 0.0) {
              local_3a0 = 0.0;
            }
          }
          else {
            local_3a0 = ABS(local_3a0);
          }
          local_36c = puVar7[4];
          local_368 = puVar7[8];
          local_370 = *puVar7;
          local_3dc = puVar7[5];
          local_3d8 = (float)puVar7[9];
          local_3e0 = puVar7[1];
          FUN_00540b40();
          local_3b8 = *(float *)(param_1 + 0xc);
          local_390 = 0;
          local_38c = 0;
          local_388 = 0;
          puVar7 = (undefined4 *)FUN_00540ae0(fVar3,local_3b0,local_3ac,local_3a8);
          Vec4_SetXYZ(*puVar7,puVar7[1],puVar7[2],puVar7[3]);
          iVar8 = FUN_00540990();
          iVar4 = local_354;
          local_3b8 = *(float *)(iVar8 + 8) / local_3b8;
          local_3d0 = local_3b4;
          local_3cc = local_3b0;
          local_3c8 = local_3ac;
          local_390 = local_380;
          local_38c = local_37c;
          local_388 = local_378;
          if ((&PTR_DAT_006f4150)[local_354 * 2] != (undefined *)0x0) {
            FUN_005443f0(param_1,&local_3d0,&local_390,&local_370,&local_3e0,param_3,local_3a0,
                         local_3b8,local_3a4,param_5);
          }
          if ((&PTR_DAT_006f4154)[iVar4 * 2] != (undefined *)0x0) {
            FUN_005443f0(param_1,&local_3d0,&local_390,&local_370,&local_3e0,param_3,local_3a0,
                         local_3b8,local_3a4,param_5);
          }
          return 1;
        }
        return 0;
      }
    }
    else {
      iVar4 = eView_IsPointInFrustum(0);
      if (iVar4 != 0) {
        FUN_00540a30();
        goto LAB_00544a80;
      }
    }
  }
  return 0;
}


// ==== 0x544e90 FUN_00544e90

int FUN_00544e90(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 *puVar3;
  
  if (9 < in_EAX % 100) {
    return 0;
  }
  iVar1 = in_EAX % 100 + (in_EAX / 100) * 10;
  if (((&DAT_00740b58)[iVar1 * 0xc] != 0) && ((&DAT_00740b50)[iVar1 * 0xc] != 1)) {
    (&DAT_00740b50)[iVar1 * 0xc] = 1;
    iVar2 = AABB_ClassifyAgainstFrustum(param_1);
    if (iVar2 != 0) {
      iVar2 = 0;
      puVar3 = (undefined4 *)(&DAT_00740b5c)[iVar1 * 0xc];
      if (0 < (int)(&DAT_00740b58)[iVar1 * 0xc]) {
        do {
          iVar2 = iVar2 + 1;
          FUN_005447c0(param_1,puVar3,0x3f800000,0,param_4,0);
          puVar3 = (undefined4 *)*puVar3;
        } while (iVar2 < (int)(&DAT_00740b58)[iVar1 * 0xc]);
      }
      return iVar2;
    }
  }
  return 0;
}


// ==== 0x544f30 LampFlares_Draw

/* [canon] assets med (Hopper export + Ghidra export) docs/re/assets.md */

void LampFlares_Draw(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *local_8;
  
  piVar1 = DAT_00740a60;
  if (((DAT_006f41a0 != 0) && (DAT_0077a920 == 6)) && (*DAT_007361f0 != 1)) {
    if (DAT_00735550 == 0) {
      iVar2 = StreamBoundaries__FindContaining(*(int *)(param_1 + 0x40) + 0x40);
      FUN_00540c70();
      if ((iVar2 != 0) && (local_8 = (int *)0x0, 0 < *(int *)(iVar2 + 0x10))) {
        do {
          FUN_00544e90(param_1,&DAT_0078bcc0,0x3f800000,param_2);
          local_8 = (int *)((int)local_8 + 1);
        } while ((int)local_8 < *(int *)(iVar2 + 0x10));
      }
    }
    else {
      local_8 = DAT_00740a60;
      piVar3 = (int *)NullUpdate_ret();
      if (piVar1 != piVar3) {
        do {
          for (piVar1 = (int *)local_8[0xe]; piVar1 != local_8 + 0xe; piVar1 = (int *)*piVar1) {
            FUN_005447c0(param_1,piVar1,0x3f800000,0,param_2,0);
          }
          local_8 = (int *)*local_8;
        } while (local_8 != piVar3);
        return;
      }
    }
  }
  return;
}


// ==== 0x545060 FUN_00545060

void FUN_00545060(void)

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
    FUN_00540c20();
    _free(_Memory);
    _Memory = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x545090 FUN_00545090

void FUN_00545090(void)

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
    if (piVar1 + -1 != (int *)0x0) {
      _free(piVar1 + -1);
    }
    piVar1 = (int *)*unaff_ESI;
  }
  return;
}


// ==== 0x5450c0 FUN_005450c0

void FUN_005450c0(void)

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
    IList_FreeNodes_Member2C();
    _free(_Memory);
    _Memory = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x5450f0 FUN_005450f0

undefined4 * __fastcall FUN_005450f0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = param_1 + 0x11;
  *puVar1 = puVar1;
  param_1[0x12] = puVar1;
  puVar3 = param_1;
  for (iVar2 = 0x18; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *puVar1 = puVar1;
  param_1[0x12] = puVar1;
  param_1[6] = 0x3f800000;
  param_1[1] = (int)(param_1 + -0x1d0118) / 0x60;
  *param_1 = &DAT_0078aa40 + ((int)(param_1 + -0x1d0118) / 0x60) * 0x120;
  return param_1;
}


// ==== 0x545150 FUN_00545150

void __fastcall FUN_00545150(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = *(int **)(param_1 + 0x44);
  while (piVar1 != (int *)(param_1 + 0x44)) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    if (piVar1 + -1 != (int *)0x0) {
      (**(code **)piVar1[-1])(1);
    }
    piVar1 = *(int **)(param_1 + 0x44);
  }
  return;
}


// ==== 0x545180 eView::CalcSphereScreenSize

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render med (ghidra-canon) docs/re/canon.md */

undefined4 __fastcall eView__CalcSphereScreenSize(float *param_1,int param_2,float param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  
  iVar1 = *(int *)(param_2 + 0x40);
  fVar2 = *param_1 - *(float *)(iVar1 + 0x40);
  fVar4 = param_1[1] - *(float *)(iVar1 + 0x44);
  fVar3 = param_1[2] - *(float *)(iVar1 + 0x48);
  if (fVar2 * *(float *)(iVar1 + 0x50) +
      fVar4 * *(float *)(iVar1 + 0x54) + fVar3 * *(float *)(iVar1 + 0x58) < -param_3) {
    return 0;
  }
  if (param_3 * _K_HALF < SQRT(fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3) - param_3) {
    uVar5 = _ftol_nocw();
    return uVar5;
  }
  uVar5 = _ftol_nocw();
  return uVar5;
}


// ==== 0x545210 eView::CalcBoxScreenSize

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] render med (ghidra-canon) docs/re/canon.md */

undefined4 __fastcall eView__CalcBoxScreenSize(float *param_1,float *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0x40);
  if (((*param_2 + *param_1) * _K_HALF - *(float *)(iVar1 + 0x40)) * *(float *)(iVar1 + 0x50) +
      ((param_2[1] + param_1[1]) * _K_HALF - *(float *)(iVar1 + 0x44)) * *(float *)(iVar1 + 0x54) +
      ((param_2[2] + param_1[2]) * _K_HALF - *(float *)(iVar1 + 0x48)) * *(float *)(iVar1 + 0x58) <
      -(SQRT((*param_2 - *param_1) * (*param_2 - *param_1) +
             (param_2[1] - param_1[1]) * (param_2[1] - param_1[1]) +
             (param_2[2] - param_1[2]) * (param_2[2] - param_1[2])) * _K_HALF)) {
    return 0;
  }
  uVar2 = _ftol_nocw();
  return uVar2;
}


// ==== 0x5452f0 Car_ScaleMatrixTowardCamera

/* [canon] render med (ghidra-canon) docs/re/canon.md */

void __fastcall Car_ScaleMatrixTowardCamera(int param_1)

{
  int in_EAX;
  
  if (*(int *)(param_1 + 0x40) != 0) {
    *(undefined4 *)(in_EAX + 0x30) = 0;
    *(undefined4 *)(in_EAX + 0x34) = 0;
    *(undefined4 *)(in_EAX + 0x38) = 0;
    *(undefined4 *)(in_EAX + 0x3c) = 0x3f800000;
    D3DXMatrixMultiply();
  }
  return;
}


// ==== 0x5453d0 TexturePack_LoadIndex

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

int * TexturePack_LoadIndex(uint param_1)

{
  int *piVar1;
  int *piVar2;
  void *pvVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int *local_18;
  uint local_14;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pvVar3 = ExceptionList;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0068572c;
  local_c = ExceptionList;
  piVar4 = (int *)0x0;
  piVar1 = (int *)(param_1 + 8);
  piVar2 = (int *)(*(int *)(param_1 + 4) + 8 + param_1);
  piVar5 = (int *)0x0;
  local_18 = (int *)0x0;
  param_1 = 0;
  local_14 = 0;
  ExceptionList = &local_c;
  for (; piVar1 != piVar2; piVar1 = (int *)((int)piVar1 + piVar1[1] + 8)) {
    iVar6 = *piVar1;
    if (iVar6 == 0x33310001) {
      piVar4 = piVar1 + 2;
    }
    else if (iVar6 == 0x33310002) {
      piVar4[0x1d] = (int)(piVar1 + 2);
    }
    else if (iVar6 == 0x33310003) {
      piVar4[0x1e] = (int)(piVar1 + 2);
    }
    else if (iVar6 == 0x33310004) {
      param_1 = (uint)piVar1[1] / 0x7c;
      piVar5 = piVar1 + 2;
    }
    else if (iVar6 == 0x33310005) {
      local_18 = piVar1 + 2;
      local_14 = (uint)piVar1[1] >> 5;
    }
  }
  piVar4[0x1b] = 1;
  if (((piVar5 != (int *)0x0) && (local_18 != (int *)0x0)) && (param_1 == local_14)) {
    pvVar3 = _malloc(0x84);
    iVar6 = 0;
    local_4 = 0;
    if (pvVar3 != (void *)0x0) {
      iVar6 = TexturePack_Register(piVar4);
    }
    local_4 = 0xffffffff;
    piVar4[0x1c] = iVar6;
    TexturePack_FixEntries();
    ExceptionList = local_c;
    return piVar4;
  }
  ExceptionList = pvVar3;
  return (int *)0x0;
}


// ==== 0x545520 TexturePack_Remove

/* [canon] assets med (Hopper export has no block (inside another sub_); Ghidra export block;
   capstone only) docs/re/assets.md */

void __fastcall TexturePack_Remove(int param_1)

{
  int *piVar1;
  void *_Memory;
  int *piVar2;
  
  piVar2 = (int *)0x0;
  for (piVar1 = (int *)(param_1 + 8); piVar1 != (int *)(*(int *)(param_1 + 4) + 8 + param_1);
      piVar1 = (int *)((int)piVar1 + piVar1[1] + 8)) {
    if (*piVar1 == 0x33310001) {
      piVar2 = piVar1 + 2;
    }
  }
  TexturePackHandle__UnmapData(piVar2[0x1c],0,*(undefined4 *)(piVar2[0x1c] + 0x80));
  if (piVar2[0x1c] != 0) {
    bList__Remove();
    _free(_Memory);
  }
  piVar2[0x1c] = 0;
  return;
}


// ==== 0x545580 TexturePack_BindPixels

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

void TexturePack_BindPixels(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_EAX;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(*(int *)(in_EAX + 0xc) + 0x14 + in_EAX);
  puVar3 = (undefined4 *)(in_EAX + 0x10);
  if (*(int *)(in_EAX + 0x20) == 0) {
    *(undefined4 *)(in_EAX + 0x20) = 1;
  }
  *(int *)(in_EAX + 0x24) = iVar1 + *(int *)(in_EAX + 0xc) + 0x18 + in_EAX;
  *DAT_0074045c = puVar3;
  puVar2 = puVar3;
  *(undefined4 **)(in_EAX + 0x14) = DAT_0074045c;
  DAT_0074045c = puVar2;
  *puVar3 = &DAT_00740458;
  return;
}


// ==== 0x5455c0 TexturePack_Load

/* [canon] assets high (Hopper export has no block (inside another sub_); Ghidra export has no
   block; live Ghidra decompile + capstone) docs/re/assets.md */

undefined4 TexturePack_Load(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  
  iVar5 = *param_1;
  if (iVar5 == -0x4cd00000) {
    iVar5 = param_1[1];
    iVar7 = 0;
    piVar8 = DAT_00740458;
    for (piVar3 = param_1 + 2; DAT_00740458 = piVar8, piVar3 != (int *)(iVar5 + 8 + (int)param_1);
        piVar3 = (int *)((int)piVar3 + piVar3[1] + 8)) {
      if (*piVar3 == -0x4ccf0000) {
        iVar7 = TexturePack_LoadIndex(piVar3,0);
      }
      else if (*piVar3 == -0x4cce0000) {
        iVar1 = *(int *)(piVar3[3] + 0x14 + (int)piVar3);
        piVar8 = piVar3 + 4;
        if (piVar3[8] == 0) {
          piVar3[8] = 1;
        }
        piVar3[9] = (int)piVar3 + iVar1 + piVar3[3] + 0x18;
        *DAT_0074045c = (int)piVar8;
        piVar2 = piVar8;
        piVar3[5] = (int)DAT_0074045c;
        DAT_0074045c = piVar2;
        *piVar8 = (int)&DAT_00740458;
      }
      piVar8 = DAT_00740458;
    }
    piVar3 = (int *)NullUpdate_ret();
    if (piVar8 != piVar3) {
      while (piVar8[3] != *(int *)(iVar7 + 0x60)) {
        piVar8 = (int *)*piVar8;
        if (piVar8 == piVar3) {
          return 1;
        }
      }
      iVar5 = piVar8[5];
      iVar7 = *(int *)(iVar7 + 0x70);
      uVar6 = iVar5 + 0x87U & 0xffffff80;
      iVar5 = (*(int *)(iVar5 + 4) - uVar6) + 8 + iVar5;
      TexturePack_AttachPixels(uVar6,0,iVar5);
      *(int *)(iVar7 + 0x80) = iVar5;
      iVar5 = *piVar8;
      piVar3 = (int *)piVar8[1];
      *piVar3 = iVar5;
      *(int **)(iVar5 + 4) = piVar3;
    }
    return 1;
  }
  if (iVar5 == -0x4cce0000) {
    TexturePack_BindPixels();
    return 1;
  }
  if (iVar5 != -0x4fcfff00) {
    return 0;
  }
  iVar5 = param_1[3];
  if (param_1[4] == 1) {
    uVar6 = *(uint *)((int)param_1 + *(int *)(iVar5 + 0x14 + (int)param_1) + iVar5 + 0x1c);
    pvVar4 = _malloc(0x18);
    if (pvVar4 == (void *)0x0) {
      param_1[5] = 0;
      TexAnim__ResolveFrames();
      param_1[6] = 1;
      return 1;
    }
    iVar5 = TexAnim_Register((int)param_1 + iVar5 + 0x18,uVar6 >> 4);
    param_1[5] = iVar5;
    TexAnim__ResolveFrames();
    param_1[6] = 1;
    return 1;
  }
  param_1[5] = 0;
  param_1[6] = 1;
  return 1;
}


// ==== 0x545770 TexturePack_Unload

/* [canon] assets high (Hopper export has no block (inside another sub_); Ghidra export has no
   block; live Ghidra decompile + capstone) docs/re/assets.md */

undefined4 TexturePack_Unload(int *param_1)

{
  int *piVar1;
  int iVar2;
  void *_Memory;
  
  iVar2 = *param_1;
  if (iVar2 == -0x4cd00000) {
    iVar2 = param_1[1];
    for (piVar1 = param_1 + 2; piVar1 != (int *)(iVar2 + 8 + (int)param_1);
        piVar1 = (int *)((int)piVar1 + piVar1[1] + 8)) {
      if (*piVar1 == -0x4ccf0000) {
        TexturePack_Remove();
      }
    }
    return 1;
  }
  if (iVar2 != -0x4cce0000) {
    if (iVar2 != -0x4fcfff00) {
      return 0;
    }
    if ((param_1[4] == 1) && (_Memory = (void *)param_1[5], _Memory != (void *)0x0)) {
      TexAnim__Unregister();
      _free(_Memory);
    }
  }
  return 1;
}


// ==== 0x5457f0 TexturePack_Register

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

void __fastcall TexturePack_Register(undefined4 param_1,char *param_2,int param_3)

{
  byte *pbVar1;
  char *pcVar2;
  byte *pbVar3;
  byte bVar4;
  char cVar5;
  undefined4 *puVar6;
  char *in_EAX;
  byte *pbVar7;
  char *pcVar8;
  int iVar9;
  undefined4 *unaff_EDI;
  
  if (((byte *)in_EAX == (byte *)0x0) && (param_3 != 0)) {
    in_EAX = (char *)(param_3 + 4);
  }
  if ((param_2 == (char *)0x0) && (param_3 != 0)) {
    param_2 = (char *)(param_3 + 0x20);
  }
  if ((byte *)in_EAX == (byte *)0x0) {
    in_EAX = "<null>";
  }
  if (param_2 == (char *)0x0) {
    param_2 = "<null>";
  }
  bVar4 = *in_EAX;
  pbVar1 = (byte *)(unaff_EDI + 2);
  *pbVar1 = bVar4;
  if (bVar4 != 0) {
    pbVar7 = pbVar1;
    do {
      bVar4 = pbVar7[(int)(in_EAX + (1 - (int)pbVar1))];
      pbVar7 = pbVar7 + 1;
      *pbVar7 = bVar4;
    } while (bVar4 != 0);
  }
  pcVar2 = (char *)(unaff_EDI + 10);
  *pcVar2 = '\0';
  if ((param_2 != (char *)0x0) && (cVar5 = *param_2, *pcVar2 = cVar5, cVar5 != '\0')) {
    pcVar8 = pcVar2;
    do {
      cVar5 = pcVar8[(int)(param_2 + (1 - (int)pcVar2))];
      pcVar8 = pcVar8 + 1;
      *pcVar8 = cVar5;
    } while (cVar5 != '\0');
  }
  unaff_EDI[0x1c] = param_3;
  iVar9 = -1;
  bVar4 = *pbVar1;
  pbVar7 = pbVar1;
  while (bVar4 != 0) {
    iVar9 = iVar9 * 0x21 + (uint)bVar4;
    pbVar3 = pbVar7 + 1;
    pbVar7 = pbVar7 + 1;
    bVar4 = *pbVar3;
  }
  unaff_EDI[0x1a] = iVar9;
  unaff_EDI[0x1d] = 0;
  unaff_EDI[0x1e] = 0;
  unaff_EDI[0x1f] = 0;
  if (param_3 != 0) {
    *(undefined4 *)(param_3 + 0x6c) = 0;
  }
  *DAT_0074041c = unaff_EDI;
  puVar6 = unaff_EDI;
  unaff_EDI[1] = DAT_0074041c;
  DAT_0074041c = puVar6;
  *unaff_EDI = &DAT_00740418;
  FUN_00565da0("TexturePack,%s",pbVar1);
  unaff_EDI[0x1b] = 0;
  return;
}


// ==== 0x5458f0 bList::Remove

/* [canon] runtime med (ghidra-canon) docs/re/canon.md */

void __fastcall bList__Remove(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  piVar2 = (int *)param_1[1];
  *piVar2 = iVar1;
  *(int **)(iVar1 + 4) = piVar2;
  return;
}


// ==== 0x545900 TexturePack_FixEntries

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

void __fastcall TexturePack_FixEntries(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int *piVar4;
  int iVar5;
  int unaff_ESI;
  int local_10;
  int local_8;
  
  *(int *)(unaff_ESI + 0x74) = param_2;
  *(int *)(unaff_ESI + 0x78) = param_1;
  *(int *)(unaff_ESI + 0x7c) = in_EAX;
  if (0 < in_EAX) {
    piVar4 = (int *)(param_2 + 0x2c);
    local_10 = param_1;
    local_8 = in_EAX;
    do {
      iVar2 = *piVar4;
      piVar1 = piVar4 + -0xb;
      if (iVar2 == 0) {
        piVar4[0x10] = (int)piVar1;
      }
      else {
        iVar5 = *(int *)(unaff_ESI + 0x7c);
        iVar3 = BinarySearch_Hash(iVar2,*(undefined4 *)(unaff_ESI + 0x74),0x24);
        if (iVar3 == 0) {
          if (0 < iVar5) {
            iVar5 = *(int *)(unaff_ESI + 0x74);
            iVar3 = 0;
            do {
              if (*(int *)(iVar5 + 0x24) == iVar2) {
                piVar4[0x10] = iVar5;
                goto LAB_00545991;
              }
              iVar3 = iVar3 + 1;
              iVar5 = iVar5 + 0x7c;
            } while (iVar3 < *(int *)(unaff_ESI + 0x7c));
          }
          iVar3 = 0;
        }
        piVar4[0x10] = iVar3;
      }
LAB_00545991:
      *piVar1 = local_10;
      piVar4[0xf] = unaff_ESI;
      piVar4[0x11] = 0;
      piVar4[0x12] = 0;
      if (piVar4[-2] == 0x66994f4a) {
        DAT_0073551c = piVar1;
      }
      piVar4 = piVar4 + 0x1f;
      local_10 = local_10 + 0x20;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  DAT_0073556c = 1;
  return;
}


// ==== 0x5459f0 TexturePack_AttachPixels

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

void TexturePack_AttachPixels(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar2 = param_2;
  local_4 = 0;
  if (0 < *(int *)(in_EAX + 0x7c)) {
    param_2 = 0;
    do {
      iVar4 = *(int *)(in_EAX + 0x74) + param_2;
      bVar1 = false;
      if (((*(int *)(*(int *)(in_EAX + 0x74) + 0x38 + param_2) != 0) &&
          (iVar3 = *(int *)(iVar4 + 0x30), iVar2 <= iVar3)) && (iVar3 < param_3 + iVar2)) {
        *(int *)(iVar4 + 0x70) = (iVar3 - iVar2) + param_1;
        bVar1 = true;
      }
      if (((*(int *)(iVar4 + 0x3c) == 0) || (iVar3 = *(int *)(iVar4 + 0x34), iVar3 < iVar2)) ||
         (param_3 + iVar2 <= iVar3)) {
        if (bVar1) goto LAB_00545a6a;
      }
      else {
        *(int *)(iVar4 + 0x74) = (iVar3 - iVar2) + param_1;
LAB_00545a6a:
        if (*(int *)(iVar4 + 0x70) != 0) {
          Texture__CreateD3D();
          if (((*(int *)(in_EAX + 0x70) != 0) &&
              (iVar3 = *(int *)(*(int *)(in_EAX + 0x70) + 0x74), iVar3 != 0)) &&
             (iVar3 = BinarySearch_Hash(*(undefined4 *)(iVar4 + 0x24),iVar3,0), iVar3 != 0)) {
            *(int *)(iVar3 + 4) = iVar4;
          }
        }
      }
      local_4 = local_4 + 1;
      param_2 = param_2 + 0x7c;
    } while (local_4 < *(int *)(in_EAX + 0x7c));
  }
  FUN_0040caa0(1);
  Particle_ResolveTextures(1);
  FEngFont_ResolveTextures();
  DAT_0073556c = 1;
  return;
}


// ==== 0x545af0 TexturePackHandle::UnmapData

/* [canon] assets high (Hopper sub_545af0 + Ghidra FUN_00545af0: H+G agree) docs/re/assets.md */

void TexturePackHandle__UnmapData(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar2 = param_1;
  local_4 = 0;
  if (0 < *(int *)(param_1 + 0x7c)) {
    param_1 = 0;
    do {
      iVar4 = *(int *)(iVar2 + 0x74) + param_1;
      bVar1 = false;
      if (((*(int *)(*(int *)(iVar2 + 0x74) + 0x38 + param_1) != 0) &&
          (param_2 <= *(int *)(iVar4 + 0x30))) && (*(int *)(iVar4 + 0x30) < param_3 + param_2)) {
        bVar1 = true;
        *(undefined4 *)(iVar4 + 0x70) = 0;
      }
      if (((*(int *)(iVar4 + 0x3c) != 0) && (param_2 <= *(int *)(iVar4 + 0x34))) &&
         (*(int *)(iVar4 + 0x34) < param_2 + param_3)) {
        bVar1 = true;
        *(undefined4 *)(iVar4 + 0x74) = 0;
      }
      if ((*(int *)(iVar4 + 0x70) == 0) && (bVar1)) {
        Texture__ReleaseD3D();
        if ((*(int *)(iVar2 + 0x70) != 0) &&
           ((iVar3 = *(int *)(*(int *)(iVar2 + 0x70) + 0x74), iVar3 != 0 &&
            (iVar3 = BinarySearch_Hash(*(undefined4 *)(iVar4 + 0x24),iVar3,0), iVar3 != 0)))) {
          *(undefined4 *)(iVar3 + 4) = 0;
        }
        iVar3 = *(int *)(iVar4 + 0x24);
        if (((iVar3 == 0x530b82b0) || (iVar3 == 0x530b82b1)) || (iVar3 == 0x530b82b2)) {
          FUN_005a8500();
        }
      }
      if (iVar4 == DAT_0073551c) {
        DAT_0073551c = 0;
      }
      local_4 = local_4 + 1;
      param_1 = param_1 + 0x7c;
    } while (local_4 < *(int *)(iVar2 + 0x7c));
  }
  FUN_0040caa0(0);
  Particle_ResolveTextures(0);
  FEngFont_ResolveTextures(iVar2,0);
  DAT_0073556c = 1;
  return;
}


// ==== 0x545c10 TexturePackHandle::FindRecordByHash

/* [canon] assets high (Ghidra FUN_00545c10 + Hopper sub_545c10) docs/re/assets.md */

int TexturePackHandle__FindRecordByHash(int param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(in_EAX + 0x74);
  iVar1 = *(int *)(in_EAX + 0x7c);
  iVar2 = BinarySearch_Hash(param_1,iVar3,0x24);
  if (iVar2 == 0) {
    if (0 < iVar1) {
      iVar2 = 0;
      do {
        if (*(int *)(iVar3 + 0x24) == param_1) {
          return iVar3;
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x7c;
      } while (iVar2 < iVar1);
    }
    iVar2 = 0;
  }
  return iVar2;
}


// ==== 0x545c60 TexAnim_Register

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

void __fastcall TexAnim_Register(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *in_EAX;
  int iVar3;
  
  in_EAX[2] = param_3;
  in_EAX[3] = param_2;
  in_EAX[4] = param_1;
  in_EAX[5] = param_4;
  if (0 < param_1) {
    iVar3 = 0;
    do {
      iVar1 = in_EAX[2];
      *(int *)(iVar1 + iVar3 + 0x28) = param_2;
      param_2 = param_2 + *(int *)(iVar1 + iVar3 + 0x1c) * 0x10;
      iVar3 = iVar3 + 0x34;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  *DAT_00740414 = in_EAX;
  puVar2 = in_EAX;
  in_EAX[1] = DAT_00740414;
  DAT_00740414 = puVar2;
  *in_EAX = &DAT_00740410;
  return;
}


// ==== 0x545cc0 TexAnim::Unregister

/* [canon] assets high (Ghidra FUN_00545cc0) docs/re/assets.md */

void TexAnim__Unregister(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_EAX;
  undefined4 *puVar5;
  int iVar6;
  int local_8;
  int local_4;
  
  iVar3 = DAT_007364f0;
  local_4 = 0;
  if (0 < in_EAX[4]) {
    local_8 = 0;
    do {
      iVar6 = *(int *)(in_EAX[2] + local_8 + 0x1c);
      if (0 < iVar6) {
        puVar5 = (undefined4 *)(*(int *)(in_EAX[2] + 0x28 + local_8) + 8);
        do {
          puVar1 = (undefined4 *)*puVar5;
          iVar2 = *(int *)(iVar3 + 0x18);
          *puVar1 = *(undefined4 *)(iVar3 + 0x10);
          puVar5 = puVar5 + 4;
          iVar6 = iVar6 + -1;
          *(int *)(iVar3 + 0x18) = iVar2 + -1;
          *(undefined4 **)(iVar3 + 0x10) = puVar1;
        } while (iVar6 != 0);
      }
      local_4 = local_4 + 1;
      local_8 = local_8 + 0x34;
    } while (local_4 < in_EAX[4]);
  }
  iVar3 = *in_EAX;
  piVar4 = (int *)in_EAX[1];
  *piVar4 = iVar3;
  *(int **)(iVar3 + 4) = piVar4;
  return;
}


// ==== 0x545d50 TexAnim::ResolveFrames

/* [canon] assets high (Ghidra FUN_00545d50) docs/re/assets.md */

void TexAnim__ResolveFrames(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_EAX;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  int local_14;
  int local_10;
  int local_8;
  
  local_8 = *(int *)(in_EAX + 0x10);
  if (0 < local_8) {
    piVar8 = (int *)(*(int *)(in_EAX + 8) + 0x1c);
    do {
      local_14 = *piVar8;
      local_10 = 1;
      if (0 < local_14) {
        puVar7 = (undefined4 *)(piVar8[3] + 8);
        do {
          if (((((undefined4 **)DAT_00740418 == &DAT_00740418) ||
               (*(int *)(DAT_0074041c + 0x70) == 0)) ||
              (iVar6 = *(int *)(*(int *)(DAT_0074041c + 0x70) + 0x74), iVar6 == 0)) ||
             ((iVar4 = BinarySearch_Hash(puVar7[-2],iVar6,0), iVar6 = DAT_007364f0, iVar4 == 0 ||
              (piVar1 = *(int **)(iVar4 + 4), piVar1 == (int *)0x0)))) {
            puVar7[-1] = 0;
            *puVar7 = 0;
            local_10 = 0;
          }
          else {
            puVar7[-1] = piVar1;
            iVar4 = *piVar1;
            if ((*(int *)(iVar6 + 0x10) == 0) && ((*(byte *)(iVar6 + 0x14) & 1) != 0)) {
              FUN_00566e60();
            }
            puVar2 = *(undefined4 **)(iVar6 + 0x10);
            iVar5 = *(int *)(iVar6 + 0x18) + 1;
            if (puVar2 != (undefined4 *)0x0) {
              uVar3 = *puVar2;
              if (*(int *)(iVar6 + 0x1c) < iVar5) {
                *(int *)(iVar6 + 0x1c) = iVar5;
              }
              *(int *)(iVar6 + 0x18) = iVar5;
              *(undefined4 *)(iVar6 + 0x10) = uVar3;
              if (((*(byte *)(iVar6 + 0x14) & 2) != 0) &&
                 (iVar6 = *(int *)(iVar6 + 0x28) >> 2, puVar9 = puVar2, 0 < iVar6)) {
                for (; iVar6 != 0; iVar6 = iVar6 + -1) {
                  *puVar9 = 0;
                  puVar9 = puVar9 + 1;
                }
              }
            }
            *puVar2 = *(undefined4 *)(iVar4 + 0x18);
            *puVar7 = puVar2;
          }
          puVar7 = puVar7 + 4;
          local_14 = local_14 + -1;
        } while (local_14 != 0);
      }
      piVar8[4] = local_10;
      piVar8[5] = 0;
      piVar8 = piVar8 + 0xd;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  return;
}


// ==== 0x545ea0 TexAnim::Update

/* [canon] assets high (Ghidra FUN_00545ea0 (called from 0x40a752)) docs/re/assets.md */

void TexAnim__Update(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_14;
  
  puVar3 = DAT_00740410;
  puVar4 = (undefined4 *)NullUpdate_ret();
  for (; puVar3 != puVar4; puVar3 = (undefined4 *)*puVar3) {
    local_14 = puVar3[4];
    if (0 < local_14) {
      iVar7 = puVar3[2] + 0x24;
      do {
        if (*(int *)(iVar7 + 8) != 0) {
          iVar1 = *(int *)(iVar7 + -8);
          iVar5 = _ftol_nocw();
          iVar5 = iVar5 % iVar1;
          if (iVar5 != *(int *)(iVar7 + 0xc)) {
            iVar2 = *(int *)(iVar7 + 4);
            iVar6 = 0;
            *(int *)(iVar7 + 0xc) = iVar5;
            if (0 < iVar1) {
              puVar8 = (undefined4 *)(iVar2 + 4);
              do {
                if (DAT_00700ea4 != 0) {
                  *(undefined4 *)(*(int *)*puVar8 + 0x18) =
                       **(undefined4 **)(((iVar6 + iVar5) % iVar1) * 0x10 + 8 + iVar2);
                }
                puVar8 = puVar8 + 4;
                iVar6 = iVar6 + 1;
              } while (iVar6 < iVar1);
            }
          }
        }
        iVar7 = iVar7 + 0x34;
        local_14 = local_14 + -1;
      } while (local_14 != 0);
    }
  }
  return;
}


// ==== 0x545fb0 TexturePack::SectionMap

/* [canon] assets med (capstone asm (no decompile in either export)) docs/re/assets.md */

void TexturePack__SectionMap(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = Texture_FindByHash(*param_2,0,1);
  iVar1 = *(int *)(iVar2 + 0x30);
  if (*(int *)(iVar2 + 0x34) != -1) {
    TexturePack_AttachPixels
              (param_1,iVar1,(*(int *)(iVar2 + 0x3c) + *(int *)(iVar2 + 0x34)) - iVar1);
    return;
  }
  TexturePack_AttachPixels(param_1,iVar1,*(undefined4 *)(iVar2 + 0x38));
  return;
}


// ==== 0x546010 TexturePack::SectionUnmap

/* [canon] assets med (capstone asm) docs/re/assets.md */

void TexturePack__SectionUnmap(undefined4 param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = *(undefined4 *)(*(int *)(param_3 + 0xb8) + 0x70);
  iVar3 = Texture_FindByHash(*param_2,0,1);
  iVar2 = *(int *)(iVar3 + 0x30);
  if (*(int *)(iVar3 + 0x34) != -1) {
    TexturePackHandle__UnmapData
              (uVar1,iVar2,(*(int *)(iVar3 + 0x3c) + *(int *)(iVar3 + 0x34)) - iVar2);
    return;
  }
  TexturePackHandle__UnmapData(uVar1,iVar2,*(undefined4 *)(iVar3 + 0x38));
  return;
}


// ==== 0x546060 FUN_00546060

void FUN_00546060(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  
  if ((((in_EAX != 0) && (iVar1 = SolidListSet_FindListByHash(&DAT_00740420,in_EAX), iVar1 != 0)) &&
      (*(char *)(iVar1 + 0x8b) == '\0')) &&
     (((*(int *)(iVar1 + 0x9c) != 0 && (iVar2 = BinarySearch_Hash(), iVar2 != 0)) &&
      (*(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1, *(short *)(iVar2 + 0xe) == 0)))) {
    if ((*(byte *)(iVar2 + 0xd) & 0x10) != 0) {
      *(byte *)(iVar2 + 0xd) = *(byte *)(iVar2 + 0xd) | 0x20;
      return;
    }
    FUN_0053ebc0(iVar1);
  }
  return;
}


// ==== 0x5460e0 TexturePack::SectionHeader

/* [canon] assets med (capstone asm) docs/re/assets.md */

void TexturePack__SectionHeader(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 4);
  FUN_00447bb0(iVar3 + 8,*(int *)(iVar3 + 4) + 8 + iVar3);
  sVar1 = *(short *)(*(int *)(param_1 + 0xc) + 0x88);
  iVar4 = 0;
  if (sVar1 == 0) goto LAB_0054614a;
  if ((&DAT_007301d4)[sVar1] == 0) {
LAB_0054613f:
    *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x8a) = 0;
  }
  else {
    if (sVar1 != 0) {
      iVar2 = FUN_00565810();
      if ((iVar2 + -0x58 < 0) || (iVar2 + -0x58 < 0x105)) goto LAB_0054613f;
    }
    iVar4 = (int)*(short *)(*(int *)(param_1 + 0xc) + 0x88);
  }
LAB_0054614a:
  iVar3 = TexturePack_LoadIndex(iVar3,iVar4);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar3 + 0x78);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(*(int *)(iVar3 + 0x70) + 0x7c);
  *(int *)(param_1 + 0x1c) = iVar3;
  return;
}


// ==== 0x546170 FUN_00546170

void FUN_00546170(void)

{
  TexturePack_Remove();
  return;
}


// ==== 0x546180 FUN_00546180

float10 FUN_00546180(void)

{
  int in_EAX;
  int iVar1;
  float10 extraout_ST0;
  
  if (in_EAX == 0) {
    return (float10)0.0;
  }
  if (in_EAX == 2) {
    _ftol_nocw();
  }
  iVar1 = _ftol_nocw();
  return extraout_ST0 - (float10)iVar1;
}


// ==== 0x5461c0 Texture_FindByHash

/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

int Texture_FindByHash(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  piVar1 = DAT_00740418;
  if (param_1 != 0) {
    piVar5 = (int *)NullUpdate_ret();
    for (; piVar1 != piVar5; piVar1 = (int *)*piVar1) {
      if (param_3 == 0) {
        if (((piVar1[0x1c] != 0) && (iVar6 = *(int *)(piVar1[0x1c] + 0x74), iVar6 != 0)) &&
           (iVar6 = BinarySearch_Hash(param_1,iVar6,0), iVar6 != 0)) {
          iVar6 = *(int *)(iVar6 + 4);
          goto LAB_0054621d;
        }
      }
      else {
        iVar6 = TexturePackHandle__FindRecordByHash(param_1);
LAB_0054621d:
        if (iVar6 != 0) {
          iVar2 = *piVar1;
          piVar5 = (int *)piVar1[1];
          *piVar5 = iVar2;
          *(int **)(iVar2 + 4) = piVar5;
          piVar4 = DAT_00740418;
          piVar5 = DAT_00740418 + 1;
          DAT_00740418 = piVar1;
          *piVar5 = (int)piVar1;
          piVar1[1] = (int)&DAT_00740418;
          *piVar1 = (int)piVar4;
          *(undefined1 *)(iVar6 + 0x53) = 1;
          return iVar6;
        }
      }
    }
  }
  if (param_2 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = DAT_0073551c;
    if (DAT_0073551c == 0) {
      pcVar3 = (code *)swi(3);
      iVar6 = (*pcVar3)();
      return iVar6;
    }
  }
  return iVar6;
}


// ==== 0x546270 FUN_00546270

void FUN_00546270(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  void *_Memory;
  int *unaff_ESI;
  
  piVar1 = (int *)*unaff_ESI;
  while (piVar1 != unaff_ESI) {
    piVar2 = (int *)piVar1[1];
    iVar3 = *piVar1;
    *piVar2 = iVar3;
    *(int **)(iVar3 + 4) = piVar2;
    bList__Remove();
    _free(_Memory);
    piVar1 = (int *)*unaff_ESI;
  }
  return;
}


// ==== 0x5462a0 FUN_005462a0

void FUN_005462a0(void)

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
    TexAnim__Unregister();
    _free(_Memory);
    _Memory = (int *)*unaff_EDI;
  }
  return;
}


// ==== 0x5462d0 TrackSkyInfo_Load

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

undefined4 TrackSkyInfo_Load(int *param_1)

{
  if (*param_1 != 0x34202) {
    return 0;
  }
  DAT_00735510 = (int)param_1 + 0x17U & 0xfffffff0;
  DAT_00735514 = ((param_1[1] - ((int)param_1 + 0x17U & 0xfffffff0)) + 8 + (int)param_1) / 0x110;
  return 1;
}


// ==== 0x546310 TrackSkyInfo_Select

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] assets high (Hopper export + Ghidra export) docs/re/assets.md */

void TrackSkyInfo_Select(void)

{
  int in_EAX;
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  
  piVar2 = (int *)0x0;
  DAT_00735518 = (int *)0x0;
  if ((in_EAX != 0) && (piVar1 = DAT_00735510, iVar3 = DAT_00735514, 0 < DAT_00735514)) {
    do {
      if (piVar1[1] == in_EAX) {
        piVar2 = piVar1;
      }
      iVar3 = iVar3 + -1;
      piVar1 = piVar1 + 0x44;
    } while (iVar3 != 0);
    DAT_00735518 = piVar2;
    if (piVar2 != (int *)0x0) {
      if (*piVar2 == 2) {
        _DAT_00740400 = piVar2[8];
        _DAT_00740404 = piVar2[9];
        _DAT_00740408 = piVar2[10];
      }
      else {
        DAT_00735518 = (int *)0x0;
        _DAT_00740400 = 0;
        _DAT_00740404 = 0;
        _DAT_00740408 = 0;
      }
      puVar4 = &DAT_00730028;
      for (iVar3 = 0x44; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      _DAT_00730048 = 0;
      _DAT_0073004c = 0;
      _DAT_00730050 = 0;
      _DAT_00730054 = 0;
      _DAT_00730058 = 0;
      _DAT_0073005c = 0;
      _DAT_00730070 = 0;
      _DAT_00730074 = 0;
      _DAT_00730060 = 0;
      _DAT_0073007c = 0;
      _DAT_00730084 = 0;
      _DAT_007300a0 = 0;
      _DAT_007300c4 = 0;
      DAT_00730028 = 2;
      _DAT_00730064 = 1;
      _DAT_00730068 = 0x3f800000;
      _DAT_0073006c = 0x42700000;
      DAT_00730078 = 0xff;
      DAT_00730079 = 200;
      DAT_0073007a = 100;
      DAT_0073007b = 0x80;
      _DAT_00730080 = 0;
      _DAT_00730088 = 1;
      _DAT_0073008c = 0x3f000000;
      _DAT_00730090 = 0x43a00000;
      _DAT_00730094 = 0;
      _DAT_00730098 = 0;
      DAT_0073009c = 0x82;
      DAT_0073009d = 0x9f;
      DAT_0073009e = 0x7a;
      DAT_0073009f = 0x80;
      _DAT_007300a4 = 0;
      _DAT_007300a8 = 2;
      _DAT_007300ac = 1;
      _DAT_007300b0 = 0x3f333333;
      _DAT_007300b4 = 0x44480000;
      _DAT_007300b8 = 0xc1100000;
      _DAT_007300bc = 0x41e00000;
      DAT_007300c0 = 0x9f;
      DAT_007300c1 = 0x7a;
      DAT_007300c2 = 0x4b;
      DAT_007300c3 = 0x80;
      _DAT_007300c8 = 0x3e4ccccd;
      _DAT_007300cc = 2;
      _DAT_007300d0 = 1;
      _DAT_007300d4 = 0x3e99999a;
      _DAT_007300d8 = 0x44480000;
      _DAT_007300dc = 0x41e00000;
      _DAT_007300e0 = 0x41100000;
      DAT_007300e4 = 0xa6;
      DAT_007300e5 = 0x77;
      DAT_007300e6 = 0x48;
      DAT_007300e7 = 0x80;
      _DAT_007300e8 = 0x4000;
      _DAT_007300ec = 0x3e4ccccd;
      return;
    }
  }
  _DAT_00740400 = 0;
  _DAT_00740404 = 0;
  _DAT_00740408 = 0;
  return;
}


// ==== 0x546570 TrackSkyInfo_Unload

/* [canon] assets high (Hopper export block; Ghidra export has no block; live Ghidra decompile +
   capstone) docs/re/assets.md */

bool TrackSkyInfo_Unload(int *param_1)

{
  if (*param_1 == 0x34202) {
    DAT_00735510 = 0;
    DAT_00735514 = 0;
  }
  return *param_1 == 0x34202;
}


// ==== 0x546590 FUN_00546590

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00546590(void)

{
  TrackSkyInfo_Select();
  _DAT_00730138 = Texture_FindByHash(0x47beb4b6,1,0);
  _DAT_0073013c = Texture_FindByHash(0xd4d26c59,1,0);
  _DAT_00730140 = Texture_FindByHash(0x1744b82d,1,0);
  _DAT_00730144 = Texture_FindByHash(0xad3c5239,1,0);
  _DAT_00730148 = Texture_FindByHash(0xd4d80a65,1,0);
  return;
}


// ==== 0x546600 FUN_00546600

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00546600(void)

{
  FUN_00548cc0();
  _DAT_007402a8 = DAT_0073ad3c;
  DAT_006f3da4 = 1;
  FUN_00549140(0);
  if (DAT_007346c8 != 0) {
    FUN_005468a0();
    DAT_0073550c = 1;
    return;
  }
  FUN_00547a70();
  _DAT_0073de20 = FUN_006626d0(s_0_0_0_0_006f1e10);
  _DAT_0073de24 = (undefined2)_DAT_006f1f3c;
  FUN_0054e1e0(_DAT_0073de20,_DAT_006f1f3c);
  DAT_0073550c = 1;
  return;
}


// ==== 0x546680 FUN_00546680

void FUN_00546680(void)

{
  char cVar1;
  
  cVar1 = Counter_7354e0_IsPositive();
  if (cVar1 != '\0') {
    FUN_00547ae0();
  }
  cVar1 = Counter_735500_IsPositive();
  if (cVar1 != '\0') {
    cVar1 = Counter_735500_IsPositive();
    if (cVar1 != '\0') {
      FUN_00547390();
      FUN_00548fa0();
      DAT_006f3da0 = 0xffffffff;
      DAT_00735508 = 0;
      FUN_0054e2f0();
      DAT_00735500 = 0;
    }
  }
  DAT_0073550c = 0;
  return;
}


// ==== 0x5466e0 FUN_005466e0

undefined1 FUN_005466e0(void)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = Counter_7354e0_IsPositive();
  if (cVar1 != '\0') {
    uVar2 = Counter_7354e0_IsPositive();
    return uVar2;
  }
  cVar1 = Counter_735500_IsPositive();
  if (cVar1 != '\0') {
    uVar2 = Counter_735500_IsPositive();
    return uVar2;
  }
  return 0;
}


// ==== 0x546710 FUN_00546710

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00546710(void)

{
  char cVar1;
  
  if (DAT_006f3da4 != '\0') {
    cVar1 = Counter_7354e0_IsPositive();
    if (cVar1 != '\0') {
      FUN_0054e020();
    }
    cVar1 = Counter_735500_IsPositive();
    if (cVar1 != '\0') {
      FUN_0054e370();
      cVar1 = Counter_735500_IsPositive();
      if (cVar1 != '\0') {
        FUN_00546980();
      }
    }
    _DAT_007402a8 = DAT_0073ad3c;
  }
  return;
}


// ==== 0x546750 FUN_00546750

void FUN_00546750(void)

{
  char cVar1;
  
  if (DAT_006f3da4 != '\0') {
    cVar1 = Counter_7354e0_IsPositive();
    if (cVar1 != '\0') {
      FUN_00547ba0();
    }
    cVar1 = Counter_735500_IsPositive();
    if (cVar1 != '\0') {
      FUN_00546c40();
      return;
    }
  }
  return;
}


// ==== 0x546780 FUN_00546780

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00546780(void)

{
  char cVar1;
  
  if (DAT_0073550c != '\0') {
    cVar1 = Counter_7354e0_IsPositive();
    if ((cVar1 != '\0') && (DAT_00734964 != 0)) {
      Counter_7354e0_IsPositive();
    }
    cVar1 = Counter_735500_IsPositive();
    if ((cVar1 != '\0') && (DAT_00734964 != 0)) {
      Counter_735500_IsPositive();
    }
    cVar1 = Counter_7354e0_IsPositive();
    if ((cVar1 == '\0') && (cVar1 = Counter_735500_IsPositive(), cVar1 == '\0')) {
      return;
    }
    if ((DAT_00734964 != 0) && (cVar1 = FUN_0043d760(), cVar1 != '\0')) {
      _DAT_0078ea98 = _DAT_0078ea98 + 1;
    }
  }
  return;
}


// ==== 0x5467f0 FUN_005467f0

void FUN_005467f0(void)

{
  char cVar1;
  
  cVar1 = Counter_735500_IsPositive();
  if (cVar1 != '\0') {
    FUN_00547560();
    return;
  }
  FUN_00548400();
  return;
}


// ==== 0x546810 FUN_00546810

void FUN_00546810(void)

{
  char cVar1;
  
  cVar1 = Counter_735500_IsPositive();
  if (cVar1 != '\0') {
    FUN_005475c0();
    return;
  }
  FUN_00548460();
  return;
}


// ==== 0x546830 FUN_00546830

void FUN_00546830(void)

{
  char cVar1;
  
  cVar1 = Counter_735500_IsPositive();
  if (cVar1 != '\0') {
    FUN_00547620();
    return;
  }
  FUN_005484c0();
  return;
}


// ==== 0x546850 FUN_00546850

void FUN_00546850(void)

{
  char cVar1;
  
  cVar1 = Counter_735500_IsPositive();
  if (cVar1 != '\0') {
    FUN_00547690();
    return;
  }
  FUN_00548530();
  return;
}


// ==== 0x546870 thunk_FUN_00547770

void thunk_FUN_00547770(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_40c [1036];
  
  FUN_004392a0();
  FUN_004389b0(6);
  DAT_00735508 = DAT_00735508 + 1;
  FUN_00548840(DAT_00735508);
  iVar1 = FUN_004388d0();
  iVar2 = FUN_006497c0();
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      FUN_004389b0(*(undefined1 *)(iVar3 + iVar2));
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  FUN_00547910(6,auStack_40c,0);
  return;
}


// ==== 0x546880 FUN_00546880

void FUN_00546880(void)

{
  char cVar1;
  
  cVar1 = Counter_735500_IsPositive();
  if (cVar1 != '\0') {
    FUN_00547700();
    return;
  }
  FUN_005485a0();
  return;
}


// ==== 0x5468a0 FUN_005468a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005468a0(void)

{
  undefined1 local_40c [1036];
  
  DAT_007402a0 = DAT_0073ad3c;
  FUN_00548ee0();
  _DAT_00730170 = _DAT_006f1f3c & 0xffff;
  _DAT_0073de24 = (undefined2)_DAT_006f1f3c;
  DAT_00730164 = 0;
  DAT_0073017c = 0;
  DAT_00730174 = 10000;
  DAT_00730180 = FUN_00546d10;
  DAT_00730168 = FUN_00546d70;
  DAT_0073016c = FUN_00546e00;
  DAT_00730178 = FUN_00546e60;
  _DAT_0073de20 = FUN_00662a90(0x61646472,0,0);
  DAT_00735500 = 1;
  FUN_004392a0();
  FUN_004389b0(0xd);
  FUN_00548840(DAT_00735500);
  FUN_00547910(0xd,local_40c,1);
  DAT_006f3da0 = FUN_00546cb0();
  return;
}


// ==== 0x546980 FUN_00546980

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00546980(void)

{
  undefined4 uVar1;
  float fVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined1 local_40c [1036];
  
  if (DAT_00735500 == 1) {
    iVar6 = 0;
    puVar5 = &DAT_0073ddc0;
    do {
      if (((puVar5[1] != -1) && (puVar5 != (undefined4 *)0x0)) && (2 < (int)puVar5[4])) {
        iVar6 = iVar6 + 1;
      }
      puVar5 = puVar5 + 8;
    } while ((int)puVar5 < 0x73de20);
    if ((iVar6 == DAT_006f1e08) && (0 < DAT_006f1e08)) {
      Race__RequestStartOrRestart();
      DAT_00735500 = 2;
      FUN_004392a0();
      FUN_004389b0(0xd);
      FUN_00548840(DAT_00735500);
      FUN_00547910(0xd,local_40c,1);
      FUN_0054e440();
    }
  }
  else {
    if (DAT_00735500 == 4) {
      iVar6 = 0;
      puVar5 = &DAT_0073ddc0;
      do {
        if (((puVar5[1] != -1) && (puVar5 != (undefined4 *)0x0)) && (5 < (int)puVar5[4])) {
          iVar6 = iVar6 + 1;
        }
        puVar5 = puVar5 + 8;
      } while ((int)puVar5 < 0x73de20);
      if (iVar6 != DAT_007354d0) goto LAB_00546b8f;
      _DAT_007402a4 = DAT_0073ad3c;
      DAT_00735500 = 5;
      FUN_004392a0();
      FUN_004389b0(0xd);
      iVar6 = DAT_00735500;
    }
    else {
      if ((DAT_00735500 != 5) || ((float)(DAT_0073ad3c - _DAT_007402a4) * 0.00025 < 2.0))
      goto LAB_00546b8f;
      fVar2 = 0.0;
      puVar5 = &DAT_0073ddc0;
      do {
        if (((puVar5[1] != -1) && (puVar5 != (undefined4 *)0x0)) &&
           (fVar2 < (float)*(ushort *)((int)puVar5 + 0xe))) {
          fVar2 = (float)*(ushort *)((int)puVar5 + 0xe);
        }
        puVar5 = puVar5 + 8;
      } while ((int)puVar5 < 0x73de20);
      FUN_0043af50(fVar2 * 0.004 + (float)DAT_0073ad34 * 0.00025 + 0.25);
      DAT_00735500 = 6;
      FUN_004392a0();
      FUN_004389b0(0xd);
      FUN_00548840(DAT_00735500);
      iVar6 = DAT_0077b25c;
    }
    FUN_00548840(iVar6);
    FUN_00547910(0xd,local_40c,1);
  }
LAB_00546b8f:
  cVar3 = Counter_735500_IsPositive();
  if (cVar3 != '\0') {
    puVar5 = &DAT_0073ddc0;
    do {
      if (((puVar5[1] != -1) && (puVar5 != (undefined4 *)0x0)) &&
         (20.0 <= (float)(DAT_0073ad3c - puVar5[7]) * 0.00025)) {
        iVar6 = puVar5[1];
        DAT_006f1e08 = DAT_006f1e08 + -1;
        puVar4 = &DAT_0073ddc0;
        do {
          puVar7 = puVar4;
          if (puVar4[1] == iVar6) break;
          puVar4 = puVar4 + 8;
          puVar7 = (undefined4 *)0x0;
        } while ((int)puVar4 < 0x73de20);
        uVar1 = *puVar7;
        FUN_005490a0();
        FUN_0054e530();
        FUN_0043ba60(uVar1,1);
        FUN_005473e0(iVar6,uVar1,1);
      }
      puVar5 = puVar5 + 8;
    } while ((int)puVar5 < 0x73de20);
  }
  return;
}


// ==== 0x546c40 FUN_00546c40

void FUN_00546c40(void)

{
  int iVar1;
  
  iVar1 = _ftol_nocw(DAT_0073ad3c - DAT_007402a0);
  if (1000.0 < (float)iVar1 != ((float)iVar1 == 1000.0)) {
    FUN_005479a0(8);
    DAT_007402a0 = DAT_0073ad3c;
  }
  return;
}


// ==== 0x546cb0 FUN_00546cb0

void FUN_00546cb0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  do {
    do {
      uVar2 = DAT_006f227c ^ 0x1d872b41;
      uVar3 = uVar2 >> 5 ^ uVar2;
      uVar1 = DAT_006f227c & 3;
      DAT_006f227c = uVar2 ^ uVar3 << 0x1b ^ uVar3;
    } while (uVar1 == DAT_006f3da0);
    puVar4 = &DAT_0073ddc0;
    while ((puVar4[1] == 0xffffffff || (*puVar4 != uVar1))) {
      puVar4 = puVar4 + 8;
      if (0x73de1f < (int)puVar4) {
        return;
      }
    }
  } while( true );
}


// ==== 0x546d10 FUN_00546d10

void FUN_00546d10(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_00549060(param_1);
  uVar2 = FUN_00546cb0();
  *puVar1 = uVar2;
  FUN_005472f0();
  FUN_00547870(param_1);
  puVar1 = &DAT_0073ddc0;
  do {
    if (((puVar1[1] != -1) && (puVar1 != (undefined4 *)0x0)) && (2 < (int)puVar1[4])) {
      FUN_00547870(param_1);
    }
    puVar1 = puVar1 + 8;
  } while ((int)puVar1 < 0x73de20);
  return;
}


// ==== 0x546d70 FUN_00546d70

void FUN_00546d70(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  DAT_006f1e08 = DAT_006f1e08 + -1;
  puVar3 = &DAT_0073ddc0;
  do {
    puVar4 = puVar3;
    if (puVar3[1] == param_1) break;
    puVar3 = puVar3 + 8;
    puVar4 = (undefined4 *)0x0;
  } while ((int)puVar3 < 0x73de20);
  uVar1 = *puVar4;
  FUN_005490a0();
  FUN_0043ba60(uVar1,0);
  FUN_005473e0(param_1,uVar1,0);
  if ((DAT_006f1e08 == 0) && (cVar2 = Counter_735500_IsPositive(), cVar2 != '\0')) {
    FUN_00547390();
    FUN_00548fa0();
    DAT_006f3da0 = 0xffffffff;
    DAT_00735508 = 0;
    FUN_0054e2f0();
    DAT_00735500 = 0;
  }
  return;
}


// ==== 0x546e00 FUN_00546e00

void FUN_00546e00(void)

{
  char cVar1;
  
  DAT_006f1e08 = DAT_006f1e08 + -1;
  if (DAT_006f1e08 == 0) {
    if ((DAT_007301cc != (code *)0x0) && ((*DAT_007301cc)(), DAT_006f1e08 != 0)) {
      return;
    }
    cVar1 = Counter_735500_IsPositive();
    if (cVar1 != '\0') {
      FUN_00547390();
      FUN_00548fa0();
      DAT_006f3da0 = 0xffffffff;
      DAT_00735508 = 0;
      FUN_0054e2f0();
      DAT_00735500 = 0;
    }
  }
  return;
}


// ==== 0x546e60 FUN_00546e60

void FUN_00546e60(undefined4 param_1,undefined4 *param_2,uint param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 auStack_40c [256];
  int iStack_c;
  undefined1 uStack_4;
  
  FUN_004392a0();
  puVar3 = auStack_40c;
  for (uVar2 = param_3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = *param_2;
    param_2 = param_2 + 1;
    puVar3 = puVar3 + 1;
  }
  for (uVar2 = param_3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  iStack_c = param_3 << 3;
  uStack_4 = 0;
  bVar1 = FUN_004389e0();
  if (bVar1 < 0xf) {
    FUN_004388d0(param_4);
    FUN_00548dd0(bVar1);
    switch(bVar1) {
    case 1:
      FUN_00547210();
      return;
    case 2:
      FUN_00547020(param_1);
      return;
    case 3:
      FUN_00547130();
      return;
    case 5:
      FUN_005471b0(param_1);
      return;
    case 7:
      FUN_005477f0(param_1);
      return;
    case 8:
      FUN_00547270();
      return;
    case 9:
      FUN_005472a0();
      return;
    case 0xc:
      FUN_00547820();
      return;
    case 0xe:
      FUN_005471e0(param_1);
    }
  }
  return;
}


// ==== 0x547020 FUN_00547020

void FUN_00547020(int param_1)

{
  undefined4 uVar1;
  undefined4 in_EAX;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar2 = &DAT_0073ddc0;
  do {
    puVar4 = puVar2;
    if (puVar2[1] == param_1) break;
    puVar2 = puVar2 + 8;
    puVar4 = (undefined4 *)0x0;
  } while ((int)puVar2 < 0x73de20);
  if ((2 < DAT_00735500) && (puVar4 != (undefined4 *)0x0)) {
    FUN_005488d0(0x20);
    FUN_00438980(&DAT_007402b0);
    FUN_005488d0(0x20);
    uVar1 = *puVar4;
    iVar3 = Race__GetPlayer(uVar1);
    if ((iVar3 != 0) && (*(float *)(iVar3 + 0x1a4) < 0.0)) {
      *(undefined4 *)(iVar3 + 0x1a4) = 0;
      FUN_0043d2d0(uVar1,in_EAX,0);
      puVar2 = &DAT_0073ddc0;
      do {
        iVar3 = puVar2[1];
        if ((((iVar3 != -1) && (puVar2 != (undefined4 *)0x0)) && (iVar3 != param_1)) &&
           (4 < (int)puVar2[4])) {
          FUN_005479e0(iVar3,2,0);
        }
        puVar2 = puVar2 + 8;
      } while ((int)puVar2 < 0x73de20);
      FUN_00547450(param_1,0);
    }
  }
  return;
}


// ==== 0x547130 FUN_00547130

void FUN_00547130(void)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int unaff_EBX;
  
  FUN_005488d0(0x20);
  uVar1 = _ftol_nocw();
  puVar2 = &DAT_0073ddc0;
  do {
    puVar3 = puVar2;
    if (puVar2[1] == unaff_EBX) break;
    puVar2 = puVar2 + 8;
    puVar3 = (undefined4 *)0x0;
  } while ((int)puVar2 < 0x73de20);
  if ((float)puVar3[6] < 0.0) {
    puVar3[6] = 0;
    *(undefined2 *)((int)puVar3 + 0xe) = uVar1;
  }
  return;
}


// ==== 0x5471b0 FUN_005471b0

void FUN_005471b0(undefined4 param_1)

{
  undefined4 unaff_ESI;
  
  FUN_0043bc90(unaff_ESI);
  FUN_005478d0(param_1,5);
  return;
}


// ==== 0x5471e0 FUN_005471e0

void FUN_005471e0(undefined4 param_1)

{
  undefined4 unaff_ESI;
  
  FUN_0043d6e0(unaff_ESI);
  FUN_005478d0(param_1,0xe);
  return;
}


// ==== 0x547210 FUN_00547210

void __fastcall FUN_00547210(undefined4 param_1)

{
  int in_EAX;
  int *piVar1;
  
  FUN_005488d0(0x20);
  piVar1 = &DAT_0073ddc4;
  do {
    if (*piVar1 == in_EAX) break;
    piVar1 = piVar1 + 8;
  } while ((int)piVar1 < 0x73de24);
  FUN_0043b400(0,param_1);
  FUN_005478d0();
  return;
}


// ==== 0x547270 FUN_00547270

void __fastcall FUN_00547270(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_0073ddc0;
  do {
    if (puVar1[1] == param_1) {
      if (puVar1 != (undefined4 *)0x0) {
        puVar1[7] = DAT_0073ad3c;
      }
      return;
    }
    puVar1 = puVar1 + 8;
  } while ((int)puVar1 < 0x73de20);
  return;
}


// ==== 0x5472a0 FUN_005472a0

void FUN_005472a0(void)

{
  undefined4 uVar1;
  int in_EAX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 unaff_EBX;
  
  DAT_006f1e08 = DAT_006f1e08 + -1;
  puVar2 = &DAT_0073ddc0;
  do {
    puVar3 = puVar2;
    if (puVar2[1] == in_EAX) break;
    puVar2 = puVar2 + 8;
    puVar3 = (undefined4 *)0x0;
  } while ((int)puVar2 < 0x73de20);
  uVar1 = *puVar3;
  FUN_005490a0();
  if ((char)unaff_EBX != '\0') {
    FUN_0054e530();
  }
  FUN_0043ba60(uVar1,unaff_EBX);
  FUN_005473e0();
  return;
}


// ==== 0x5472f0 FUN_005472f0

void FUN_005472f0(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int unaff_EBX;
  undefined1 local_40c [1036];
  
  puVar2 = &DAT_0073ddc0;
  do {
    puVar3 = puVar2;
    if (puVar2[1] == unaff_EBX) break;
    puVar2 = puVar2 + 8;
    puVar3 = (undefined4 *)0x0;
  } while ((int)puVar2 < 0x73de20);
  uVar1 = *puVar3;
  FUN_004392a0();
  FUN_004389b0(0);
  FUN_00548840(unaff_EBX);
  FUN_00548840(uVar1);
  uVar1 = DAT_006f3da0;
  FUN_00548840(DAT_006f3da0);
  FUN_0043b210(uVar1,local_40c);
  FUN_005479e0();
  return;
}


// ==== 0x547390 FUN_00547390

void FUN_00547390(void)

{
  undefined1 local_40c [1036];
  
  FUN_004392a0();
  FUN_004389b0(10);
  FUN_00548840(DAT_00735504);
  FUN_00547910(10,local_40c,1);
  return;
}


// ==== 0x5473e0 FUN_005473e0

void FUN_005473e0(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  FUN_004392a0();
  FUN_004389b0(0xb);
  FUN_00548840(param_2);
  FUN_00548840(param_3);
  FUN_005478d0(param_1,0xb);
  return;
}


// ==== 0x547450 FUN_00547450

void FUN_00547450(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined1 local_40c [1036];
  
  if (DAT_007361f8 != 0) {
    cVar2 = Race__HasPlayer(DAT_006f3da0);
    if (cVar2 != '\0') {
      FUN_004392a0();
      FUN_004389b0(4);
      FUN_00548840(param_2);
      FUN_00548840((float)DAT_0073ad34 * 0.00025);
      iVar1 = DAT_006f3da0;
      iVar3 = DAT_006f3da0;
      if (DAT_006f3da0 < DAT_007403e0) {
        iVar3 = DAT_007403e0;
      }
      if (DAT_007403e4 < iVar3) {
        iVar3 = DAT_007403e4;
      }
      FUN_00548840(iVar3 - DAT_007403e0);
      FUN_00548840((float)DAT_0073ad3c * 0.00025);
      FUN_0043d3d0(iVar1,local_40c);
      FUN_005479e0(param_1,4,0);
    }
  }
  return;
}


// ==== 0x547560 FUN_00547560

void FUN_00547560(void)

{
  undefined1 local_40c [1036];
  
  DAT_00735500 = 3;
  FUN_004392a0();
  FUN_004389b0(0xd);
  FUN_00548840(DAT_00735500);
  FUN_00547910(0xd,local_40c,1);
  return;
}


// ==== 0x5475c0 FUN_005475c0

void FUN_005475c0(void)

{
  undefined1 local_40c [1036];
  
  DAT_00735500 = 4;
  FUN_004392a0();
  FUN_004389b0(0xd);
  FUN_00548840(DAT_00735500);
  FUN_00547910(0xd,local_40c,1);
  return;
}


// ==== 0x547620 FUN_00547620

void FUN_00547620(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_40c [1036];
  
  FUN_004392a0();
  FUN_004389b0(7);
  iVar1 = FUN_004388d0();
  iVar2 = FUN_006497c0();
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      FUN_004389b0(*(undefined1 *)(iVar3 + iVar2));
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  FUN_00547910(7,local_40c,1);
  return;
}


// ==== 0x547690 FUN_00547690

void FUN_00547690(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_40c [1036];
  
  FUN_004392a0();
  FUN_004389b0(5);
  iVar1 = FUN_004388d0();
  iVar2 = FUN_006497c0();
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      FUN_004389b0(*(undefined1 *)(iVar3 + iVar2));
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  FUN_00547910(5,local_40c,0);
  return;
}


// ==== 0x547700 FUN_00547700

void FUN_00547700(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_40c [1036];
  
  FUN_004392a0();
  FUN_004389b0(0xe);
  iVar1 = FUN_004388d0();
  iVar2 = FUN_006497c0();
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      FUN_004389b0(*(undefined1 *)(iVar3 + iVar2));
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  FUN_00547910(0xe,local_40c,1);
  return;
}


// ==== 0x547770 FUN_00547770

void FUN_00547770(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_40c [1036];
  
  FUN_004392a0();
  FUN_004389b0(6);
  DAT_00735508 = DAT_00735508 + 1;
  FUN_00548840(DAT_00735508);
  iVar1 = FUN_004388d0();
  iVar2 = FUN_006497c0();
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      FUN_004389b0(*(undefined1 *)(iVar3 + iVar2));
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  FUN_00547910(6,local_40c,0);
  return;
}


// ==== 0x5477f0 FUN_005477f0

void FUN_005477f0(undefined4 param_1)

{
  undefined4 unaff_ESI;
  
  FUN_0043bc30(unaff_ESI);
  FUN_005478d0(param_1,7);
  return;
}


// ==== 0x547820 FUN_00547820

void FUN_00547820(void)

{
  undefined4 *puVar1;
  int unaff_EBX;
  
  FUN_005488d0(0x20);
  puVar1 = &DAT_0073ddc0;
  do {
    if (puVar1[1] == unaff_EBX) {
      puVar1[4] = 0;
      return;
    }
    puVar1 = puVar1 + 8;
  } while ((int)puVar1 < 0x73de20);
  uRam00000010 = 0;
  return;
}


// ==== 0x547870 FUN_00547870

void FUN_00547870(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined1 local_40c [1036];
  
  FUN_004392a0();
  FUN_004389b0(1);
  FUN_00548840(in_EAX);
  FUN_0043b4e0(in_EAX,local_40c);
  FUN_005479e0(param_1,1,1);
  return;
}


// ==== 0x5478d0 FUN_005478d0

void FUN_005478d0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_0073ddc0;
  do {
    iVar1 = puVar2[1];
    if (((iVar1 != -1) && (puVar2 != (undefined4 *)0x0)) && (iVar1 != param_1)) {
      FUN_005479e0(iVar1,param_2);
    }
    puVar2 = puVar2 + 8;
  } while ((int)puVar2 < 0x73de20);
  return;
}


// ==== 0x547910 FUN_00547910

void FUN_00547910(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = &DAT_0073ddc0;
  do {
    iVar2 = puVar3[1];
    if ((iVar2 != -1) && (puVar3 != (undefined4 *)0x0)) {
      FUN_004388d0(param_3);
      uVar1 = FUN_006497c0();
      iVar2 = FUN_0054e480(iVar2,uVar1);
      if (iVar2 != 0) {
        if (2 < DAT_006f3d88) {
          FUN_004388d0();
          FUN_006497c0();
        }
        FUN_004388d0(param_3);
        FUN_00548d70(param_1);
      }
    }
    puVar3 = puVar3 + 8;
  } while ((int)puVar3 < 0x73de20);
  return;
}


// ==== 0x5479a0 FUN_005479a0

void FUN_005479a0(undefined4 param_1)

{
  undefined1 local_40c [1036];
  
  FUN_004392a0();
  FUN_004389b0(param_1);
  FUN_00547910(param_1,local_40c,1);
  return;
}


// ==== 0x5479e0 FUN_005479e0

void FUN_005479e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_004388d0(param_3);
  uVar1 = FUN_006497c0();
  iVar2 = FUN_0054e480(param_1,uVar1);
  if (iVar2 != 0) {
    if (2 < DAT_006f3d88) {
      FUN_004388d0();
      FUN_006497c0();
    }
    FUN_004388d0(param_3);
    FUN_00548d70(param_2);
  }
  return;
}


// ==== 0x547a40 FUN_00547a40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00547a40(void)

{
  _DAT_0073ddbc = _ftol_nocw();
  DAT_0073014c = 1;
  return;
}


// ==== 0x547a70 FUN_00547a70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00547a70(void)

{
  _DAT_00740294 = DAT_0073ad3c;
  DAT_00740298 = DAT_0073ad3c;
  DAT_00730150 = 10000;
  DAT_0073d864 = 0;
  _DAT_00730158 = FUN_00547d90;
  DAT_00730154 = FUN_00547db0;
  _DAT_00730160 = FUN_00547dc0;
  DAT_0073015c = FUN_00547e00;
  _DAT_007354d8 = FUN_00662a90(0x61646472,0,0);
  DAT_007354e0 = 1;
  return;
}


// ==== 0x547ae0 FUN_00547ae0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00547ae0(void)

{
  char cVar1;
  
  cVar1 = Counter_7354e0_IsPositive();
  if (cVar1 != '\0') {
    if (DAT_007354e4 != '\0') {
      FUN_00548780(9);
      if (DAT_007354e4 != '\0') {
        FUN_0054e5b0();
      }
    }
    if (DAT_00734f7c != 0) {
      FUN_006640b0(DAT_00734f7c);
    }
    if (DAT_00734f74 != 0) {
      FUN_00663960(DAT_00734f74);
    }
    DAT_00734f74 = 0;
    DAT_00734f7c = 0;
    DAT_007354e4 = '\0';
    _DAT_007354d8 = 0;
    _DAT_007354dc = 0;
    DAT_007354e8 = 0;
    DAT_007354ec = 0;
    DAT_007354f0 = 0;
    DAT_007354fc = 0;
    DAT_007354e0 = 0;
    _DAT_006f3d90 = 0xffffffff;
    DAT_006f3d94 = 0xffffffff;
    DAT_006f3d9c = 0xffffffff;
    _DAT_006f3d98 = 0xbf800000;
    _DAT_007354f8 = 0;
  }
  return;
}


// ==== 0x547ba0 FUN_00547ba0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00547ba0(void)

{
  int iVar1;
  
  if (DAT_007354e4 != '\0') {
    FUN_00547c60();
    iVar1 = _ftol_nocw();
    if (1000.0 < (float)iVar1 != ((float)iVar1 == 1000.0)) {
      FUN_00548780(8);
      DAT_00740298 = DAT_0073ad3c;
    }
    iVar1 = _ftol_nocw();
    if (20000.0 < (float)iVar1 != ((float)iVar1 == 20000.0)) {
      FUN_00547dc0();
      return;
    }
  }
  return;
}


// ==== 0x547c60 FUN_00547c60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00547c60(void)

{
  float fVar1;
  int iVar2;
  char cVar3;
  undefined1 local_40c [1036];
  
  if ((((-1 < DAT_006f3d94) && (4 < DAT_007354e0)) && (2 < DAT_007354f4)) &&
     ((0 < DAT_006f3d8c &&
      (fVar1 = (float)(DAT_0073ad3c - _DAT_00740294) * 0.00025,
      _K_ONE / (float)DAT_006f3d8c < fVar1 != (_K_ONE / (float)DAT_006f3d8c == fVar1))))) {
    cVar3 = Race__HasPlayer(DAT_006f3d94);
    if (cVar3 != '\0') {
      FUN_004392a0();
      FUN_004389b0(2);
      FUN_00548840((float)DAT_0073ad34 * 0.00025);
      iVar2 = DAT_006f3d94;
      FUN_00436e60();
      FUN_00548840((float)DAT_0073ad3c * 0.00025);
      FUN_0043d3d0(iVar2,local_40c);
      FUN_005487c0(2,0);
    }
    _DAT_00740294 = DAT_0073ad3c;
  }
  return;
}


// ==== 0x547d90 FUN_00547d90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00547d90(void)

{
  DAT_007354e4 = 1;
  _DAT_0074029c = DAT_0073ad3c;
  DAT_007354e0 = 2;
  return;
}


// ==== 0x547db0 FUN_00547db0

void FUN_00547db0(void)

{
  if (DAT_007301cc != (code *)0x0) {
    (*DAT_007301cc)();
  }
  FUN_00547ae0();
  return;
}


// ==== 0x547dc0 FUN_00547dc0

void FUN_00547dc0(void)

{
  if (DAT_006f3d9c == -1) {
    if (DAT_007301cc != (code *)0x0) {
      (*DAT_007301cc)();
      DAT_007354e4 = 0;
      FUN_00547ae0();
      return;
    }
  }
  else {
    FUN_0043ba60(DAT_006f3d9c,0);
  }
  DAT_007354e4 = 0;
  FUN_00547ae0();
  return;
}


// ==== 0x547e00 FUN_00547e00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00547e00(undefined4 *param_1,uint param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 auStack_40c [256];
  int iStack_c;
  undefined1 uStack_4;
  
  FUN_004392a0();
  puVar3 = auStack_40c;
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
  iStack_c = param_2 << 3;
  uStack_4 = 0;
  bVar1 = FUN_004389e0();
  if (bVar1 < 0xf) {
    FUN_004388d0(param_3);
    FUN_00548dd0(bVar1);
    switch(bVar1) {
    case 0:
      FUN_00548250();
      return;
    case 1:
      FUN_00548310();
      return;
    case 2:
      FUN_00547fd0();
      return;
    case 4:
      FUN_00548090();
      return;
    case 5:
      FUN_0043bc90(auStack_40c);
      return;
    case 6:
      FUN_00548210();
      return;
    case 7:
      FUN_0043bc30(auStack_40c);
      return;
    case 8:
      _DAT_0074029c = DAT_0073ad3c;
      return;
    case 10:
      FUN_00548610();
      return;
    case 0xb:
      FUN_00548650();
      return;
    case 0xd:
      FUN_005486a0();
      return;
    case 0xe:
      FUN_0043d6e0(auStack_40c);
    }
  }
  return;
}


// ==== 0x547fd0 FUN_00547fd0

void FUN_00547fd0(void)

{
  FUN_005488d0(0x20);
  FUN_00548000(0);
  return;
}


// ==== 0x548000 FUN_00548000

void FUN_00548000(undefined4 param_1)

{
  undefined4 in_EAX;
  int iVar1;
  int iVar2;
  
  if (DAT_007361f8 != 0) {
    iVar1 = FUN_00438980(&DAT_007402b0);
    FUN_005488d0(0x20);
    iVar2 = Race__GetPlayer(iVar1);
    if ((iVar2 != 0) && (*(float *)(iVar2 + 0x1a4) < 0.0)) {
      *(undefined4 *)(iVar2 + 0x1a4) = 0;
      FUN_0043d2d0(iVar1,in_EAX,param_1);
      if (iVar1 == DAT_006f3d9c) {
        FUN_005483a0(0);
      }
    }
  }
  return;
}


// ==== 0x548090 FUN_00548090

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00548090(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float10 extraout_ST0;
  
  FUN_005488d0(0x20);
  FUN_005488d0(0x20);
  iVar3 = DAT_007354f0;
  if (0.0 < _DAT_006f3d98 == (_DAT_006f3d98 == 0.0)) {
    _DAT_006f3d98 = 0.0;
    FUN_00548000(0);
    _DAT_007354dc = _ftol_nocw();
    fVar2 = (float)(extraout_ST0 + (float10)0.0) - (float)DAT_0073ad34 * 0.00025;
    Flag_73014c_Get();
    fVar1 = ABS(fVar2);
    if (0.25 < fVar1) {
      _DAT_0073ddbc = _ftol_nocw();
      DAT_007354ec = 0;
      DAT_0073014c = 1;
      return;
    }
    if (fVar2 <= 0.0) {
      iVar3 = -1;
    }
    else {
      iVar3 = 1;
    }
    if ((iVar3 == DAT_007354f0) && (fVar1 < 0.001 == (fVar1 == 0.001))) {
      DAT_007354ec = DAT_007354ec + 1;
      if (4 < DAT_007354ec) {
        FUN_00547a40((float)(extraout_ST0 + (float10)0.0));
        DAT_007354f0 = iVar3;
        DAT_007354ec = 0;
        DAT_007354e8 = DAT_007354e8 + 1;
        return;
      }
    }
    else {
      DAT_007354ec = 0;
    }
  }
  DAT_007354f0 = iVar3;
  return;
}


// ==== 0x548210 FUN_00548210

/* WARNING: Removing unreachable block (ram,0x00548234) */

void FUN_00548210(void)

{
  FUN_005488d0(0x20);
  return;
}


// ==== 0x548250 FUN_00548250

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00548250(void)

{
  undefined4 in_EAX;
  
  FUN_005488d0(0x20);
  _DAT_006f3d90 = 0;
  FUN_005488d0(0x20);
  DAT_006f3d94 = 0;
  FUN_005488d0(0x20);
  DAT_006f3d9c = 0;
  FUN_0043b090(0,0,in_EAX);
  FUN_00548340();
  DAT_007354e0 = 3;
  FUN_004392a0();
  FUN_004389b0(0xc);
  FUN_00548840(DAT_007354e0);
  FUN_005487c0(0xc,1);
  return;
}


// ==== 0x548310 FUN_00548310

void FUN_00548310(void)

{
  undefined4 in_EAX;
  
  FUN_005488d0(0x20);
  FUN_0043b400(0,in_EAX);
  return;
}


// ==== 0x548340 FUN_00548340

void FUN_00548340(void)

{
  undefined4 uVar1;
  undefined1 local_40c [1036];
  
  FUN_004392a0();
  FUN_004389b0(1);
  uVar1 = DAT_006f3d94;
  FUN_00548840(DAT_006f3d94);
  FUN_0043b4e0(uVar1,local_40c);
  FUN_005487c0(1,1);
  return;
}


// ==== 0x5483a0 FUN_005483a0

void FUN_005483a0(undefined4 param_1)

{
  FUN_004392a0();
  FUN_004389b0(3);
  FUN_00548840(param_1);
  FUN_005487c0(3,0);
  return;
}


// ==== 0x548400 FUN_00548400

void FUN_00548400(void)

{
  DAT_007354e0 = 5;
  FUN_004392a0();
  FUN_004389b0(0xc);
  FUN_00548840(DAT_007354e0);
  FUN_005487c0(0xc,1);
  return;
}


// ==== 0x548460 FUN_00548460

void FUN_00548460(void)

{
  DAT_007354e0 = 6;
  FUN_004392a0();
  FUN_004389b0(0xc);
  FUN_00548840(DAT_007354e0);
  FUN_005487c0(0xc,1);
  return;
}


// ==== 0x5484c0 FUN_005484c0

void FUN_005484c0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_004392a0();
  FUN_004389b0(7);
  iVar1 = FUN_004388d0();
  iVar2 = FUN_006497c0();
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      FUN_004389b0(*(undefined1 *)(iVar3 + iVar2));
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  FUN_005487c0(7,1);
  return;
}


// ==== 0x548530 FUN_00548530

void FUN_00548530(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_004392a0();
  FUN_004389b0(5);
  iVar1 = FUN_004388d0();
  iVar2 = FUN_006497c0();
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      FUN_004389b0(*(undefined1 *)(iVar3 + iVar2));
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  FUN_005487c0(5,0);
  return;
}


// ==== 0x5485a0 FUN_005485a0

void FUN_005485a0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_004392a0();
  FUN_004389b0(0xe);
  iVar1 = FUN_004388d0();
  iVar2 = FUN_006497c0();
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      FUN_004389b0(*(undefined1 *)(iVar3 + iVar2));
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  FUN_005487c0(0xe,1);
  return;
}


// ==== 0x548610 FUN_00548610

void FUN_00548610(void)

{
  FUN_005488d0(1);
  DAT_007354e4 = 0;
  FUN_0043ba60(DAT_006f3d9c,1);
  FUN_00547ae0();
  return;
}


// ==== 0x548650 FUN_00548650

void FUN_00548650(void)

{
  uint uVar1;
  
  FUN_005488d0(0x20);
  uVar1 = FUN_005488d0(1);
  FUN_0043ba60(0,uVar1 & 0xffffff00);
  return;
}


// ==== 0x5486a0 FUN_005486a0

/* WARNING: Removing unreachable block (ram,0x005486d4) */
/* WARNING: Removing unreachable block (ram,0x0054871c) */
/* WARNING: Removing unreachable block (ram,0x0054874b) */

void FUN_005486a0(void)

{
  FUN_005488d0(0x20);
  DAT_007354f4 = 0;
  return;
}


// ==== 0x548780 FUN_00548780

void FUN_00548780(undefined4 param_1)

{
  FUN_004392a0();
  FUN_004389b0(param_1);
  FUN_005487c0(param_1,1);
  return;
}


// ==== 0x5487c0 FUN_005487c0

void FUN_005487c0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_004388d0(param_2);
  uVar1 = FUN_006497c0();
  iVar2 = FUN_0054e260(uVar1);
  if (iVar2 != 0) {
    if (2 < DAT_006f3d88) {
      FUN_004388d0();
      FUN_006497c0();
    }
    FUN_004388d0(param_2);
    FUN_00548d70(param_1);
  }
  return;
}


// ==== 0x548820 FUN_00548820

void FUN_00548820(void)

{
  undefined1 *in_EAX;
  
  *in_EAX = 0;
  *(undefined4 *)(in_EAX + 0x400) = 0;
  *(undefined4 *)(in_EAX + 0x404) = 0;
  in_EAX[0x408] = 1;
  return;
}


// ==== 0x548840 FUN_00548840

void FUN_00548840(int param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int unaff_EDI;
  
  uVar6 = *(uint *)(unaff_EDI + 0x400);
  *(uint *)(unaff_EDI + 0x400) = uVar6 + in_EAX;
  uVar4 = uVar6 & 7;
  iVar1 = (int)uVar6 >> 3;
  uVar5 = param_1 << (0x20U - (char)in_EAX & 0x1f);
  uVar6 = uVar5;
  if (uVar4 != 0) {
    iVar2 = 8 - uVar4;
    if (in_EAX < (int)(8 - uVar4)) {
      iVar2 = in_EAX;
    }
    in_EAX = in_EAX - iVar2;
    uVar6 = uVar5 << ((byte)iVar2 & 0x1f);
    *(byte *)(iVar1 + unaff_EDI) =
         *(byte *)(iVar1 + unaff_EDI) | (byte)(uVar5 >> (char)uVar4 + 0x18);
    iVar1 = iVar1 + 1;
  }
  if (in_EAX < 9) {
    *(char *)(iVar1 + unaff_EDI) = (char)(uVar6 >> 0x18);
  }
  else if (0 < in_EAX) {
    puVar3 = (undefined1 *)(iVar1 + unaff_EDI);
    iVar1 = (in_EAX - 1U >> 3) + 1;
    do {
      *puVar3 = (char)(uVar6 >> 0x18);
      puVar3 = puVar3 + 1;
      uVar6 = uVar6 << 8;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    return;
  }
  return;
}


// ==== 0x5488d0 FUN_005488d0

void FUN_005488d0(int param_1)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint *unaff_ESI;
  int unaff_EDI;
  
  uVar2 = *(uint *)(unaff_EDI + 0x404);
  iVar3 = (int)(uVar2 + ((int)uVar2 >> 0x1f & 7U)) >> 3;
  uVar6 = uVar2 & 0x80000007;
  if ((int)uVar6 < 0) {
    uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;
  }
  *(uint *)(unaff_EDI + 0x404) = uVar2 + param_1;
  iVar8 = 8 - uVar6;
  if (param_1 < (int)(8 - uVar6)) {
    iVar8 = param_1;
  }
  iVar7 = -iVar8 + 0x18;
  iVar4 = iVar3 + 1;
  iVar9 = param_1 - iVar8;
  *unaff_ESI = (uint)*(byte *)(iVar3 + unaff_EDI) << ((char)uVar6 + 0x18U & 0x1f);
  if (0 < iVar7) {
    iVar9 = iVar9 + (-8 - (-iVar8 + 0x17U & 0xfffffff8));
    do {
      pbVar1 = (byte *)(iVar4 + unaff_EDI);
      bVar5 = (byte)iVar7;
      iVar7 = iVar7 + -8;
      iVar4 = iVar4 + 1;
      *unaff_ESI = *unaff_ESI | (uint)*pbVar1 << (bVar5 & 0x1f);
    } while (0 < iVar7);
  }
  if (0 < iVar9) {
    *unaff_ESI = *unaff_ESI | (uint)(*(byte *)(iVar4 + unaff_EDI) >> (-(char)iVar7 & 0x1fU));
  }
  *unaff_ESI = *unaff_ESI >> (0x20U - (char)param_1 & 0x1f);
  return;
}


// ==== 0x548980 FUN_00548980

void FUN_00548980(undefined4 param_1,int param_2)

{
  int iVar1;
  int unaff_EDI;
  
  FUN_00438a00(unaff_EDI);
  iVar1 = 0;
  if (0 < unaff_EDI) {
    do {
      FUN_004389b0(*(undefined1 *)(iVar1 + param_2));
      iVar1 = iVar1 + 1;
    } while (iVar1 < unaff_EDI);
  }
  return;
}


// ==== 0x5489c0 FUN_005489c0

/* WARNING: Removing unreachable block (ram,0x005489e8) */

undefined4 FUN_005489c0(void)

{
  FUN_005488d0(0x10);
  return 0;
}


// ==== 0x548a00 FUN_00548a00

void FUN_00548a00(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  char *in_EAX;
  int iVar3;
  
  iVar3 = 0;
  if (in_EAX != (char *)0x0) {
    cVar2 = *in_EAX;
    while (cVar2 != '\0') {
      iVar1 = iVar3 + 1;
      iVar3 = iVar3 + 1;
      cVar2 = in_EAX[iVar1];
    }
  }
  FUN_00548980(param_1,in_EAX);
  return;
}


// ==== 0x548a30 FUN_00548a30

void FUN_00548a30(void)

{
  undefined4 in_EAX;
  int iVar1;
  int unaff_ESI;
  
  iVar1 = FUN_005489c0(unaff_ESI,in_EAX);
  *(undefined1 *)(iVar1 + unaff_ESI) = 0;
  return;
}


// ==== 0x548a50 FUN_00548a50

void FUN_00548a50(undefined4 param_1,int param_2)

{
  int iVar1;
  int unaff_EDI;
  
  iVar1 = 0;
  if (0 < unaff_EDI) {
    do {
      FUN_004389b0(*(undefined1 *)(iVar1 + param_2));
      iVar1 = iVar1 + 1;
    } while (iVar1 < unaff_EDI);
  }
  return;
}


// ==== 0x548a80 FUN_00548a80

void FUN_00548a80(void)

{
  FUN_00548840();
  return;
}


// ==== 0x548a90 FUN_00548a90

void FUN_00548a90(void)

{
  undefined1 *in_EAX;
  
  *(undefined4 *)(in_EAX + 300) = 0;
  *(undefined4 *)(in_EAX + 0x130) = 0;
  *(undefined4 *)(in_EAX + 0x134) = 0;
  *(undefined4 *)(in_EAX + 0x138) = 0;
  *(undefined4 *)(in_EAX + 0x13c) = 0;
  *(undefined4 *)(in_EAX + 0x140) = 0;
  *(undefined4 *)(in_EAX + 0x144) = 0;
  in_EAX[0x148] = 0;
  *in_EAX = 0;
  return;
}


// ==== 0x548ad0 FUN_00548ad0

void __fastcall
FUN_00548ad0(undefined4 param_1,char *param_2,float param_3,float param_4,float param_5)

{
  char cVar1;
  float fVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *unaff_ESI;
  
  cVar1 = *param_2;
  *unaff_ESI = cVar1;
  if (cVar1 != '\0') {
    pcVar3 = unaff_ESI;
    do {
      cVar1 = pcVar3[(int)(param_2 + (1 - (int)unaff_ESI))];
      pcVar3 = pcVar3 + 1;
      *pcVar3 = cVar1;
    } while (cVar1 != '\0');
  }
  *(float *)(unaff_ESI + 0x130) = param_3;
  *(float *)(unaff_ESI + 0x13c) = param_5 + param_5;
  *(float *)(unaff_ESI + 0x134) = param_4;
  *(float *)(unaff_ESI + 0x138) = param_5;
  iVar4 = _ftol_nocw();
  unaff_ESI[300] = '\0';
  unaff_ESI[0x12d] = '\0';
  unaff_ESI[0x12e] = '\0';
  unaff_ESI[0x12f] = '\0';
  uVar6 = 0;
  if (iVar4 != -1) {
    iVar5 = 0;
    do {
      iVar5 = iVar5 + 1;
      uVar6 = 1 << ((byte)iVar5 & 0x1f);
    } while (uVar6 < iVar4 + 1U);
    *(int *)(unaff_ESI + 300) = iVar5;
  }
  fVar2 = (float)(int)(uVar6 - 1);
  if ((int)(uVar6 - 1) < 0) {
    fVar2 = fVar2 + 4.2949673e+09;
  }
  fVar2 = (param_4 - param_3) / fVar2;
  unaff_ESI[0x140] = -1;
  unaff_ESI[0x141] = -1;
  unaff_ESI[0x142] = '\x7f';
  unaff_ESI[0x143] = '\x7f';
  unaff_ESI[0x144] = -1;
  unaff_ESI[0x145] = -1;
  unaff_ESI[0x146] = '\x7f';
  unaff_ESI[0x147] = -1;
  unaff_ESI[0x148] = '\x01';
  *(float *)(unaff_ESI + 0x13c) = fVar2;
  *(float *)(unaff_ESI + 0x138) = fVar2 * 0.5;
  return;
}


// ==== 0x548ba0 FUN_00548ba0

void __fastcall FUN_00548ba0(undefined4 param_1,char *param_2,float param_3,float param_4)

{
  char cVar1;
  float fVar2;
  char *in_EAX;
  char *pcVar3;
  int iVar4;
  
  cVar1 = *param_2;
  *in_EAX = cVar1;
  if (cVar1 != '\0') {
    pcVar3 = in_EAX;
    do {
      cVar1 = pcVar3[(int)(param_2 + (1 - (int)in_EAX))];
      pcVar3 = pcVar3 + 1;
      *pcVar3 = cVar1;
    } while (cVar1 != '\0');
  }
  *(float *)(in_EAX + 0x130) = param_3;
  *(float *)(in_EAX + 0x134) = param_4;
  *(undefined4 *)(in_EAX + 300) = param_1;
  iVar4 = (1 << ((byte)param_1 & 0x1f)) + -1;
  fVar2 = (float)iVar4;
  if (iVar4 < 0) {
    fVar2 = fVar2 + 4.2949673e+09;
  }
  fVar2 = (param_4 - param_3) / fVar2;
  in_EAX[0x140] = -1;
  in_EAX[0x141] = -1;
  in_EAX[0x142] = '\x7f';
  in_EAX[0x143] = '\x7f';
  in_EAX[0x144] = -1;
  in_EAX[0x145] = -1;
  in_EAX[0x146] = '\x7f';
  in_EAX[0x147] = -1;
  in_EAX[0x148] = '\x01';
  *(float *)(in_EAX + 0x13c) = fVar2;
  *(float *)(in_EAX + 0x138) = fVar2 * 0.5;
  return;
}


// ==== 0x548c30 FUN_00548c30

float10 __fastcall FUN_00548c30(int param_1)

{
  int in_EAX;
  float10 fVar1;
  
  fVar1 = (float10)in_EAX;
  if (in_EAX < 0) {
    fVar1 = fVar1 + (float10)4.2949673e+09;
  }
  fVar1 = fVar1 * (float10)*(float *)(param_1 + 0x13c) + (float10)*(float *)(param_1 + 0x130);
  if (fVar1 < (float10)*(float *)(param_1 + 0x130)) {
    fVar1 = (float10)*(float *)(param_1 + 0x130);
  }
  if ((float10)*(float *)(param_1 + 0x134) < fVar1) {
    fVar1 = (float10)*(float *)(param_1 + 0x134);
  }
  return fVar1;
}


// ==== 0x548c80 FUN_00548c80

void __fastcall FUN_00548c80(undefined4 *param_1)

{
  param_1[7] = 0;
  param_1[1] = 0xffffffff;
  *param_1 = 0xffffffff;
  param_1[2] = 0;
  *(undefined2 *)(param_1 + 3) = 0;
  *(undefined2 *)((int)param_1 + 0xe) = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0xbf800000;
  param_1[7] = DAT_0073ad3c;
  return;
}


// ==== 0x548cc0 FUN_00548cc0

void FUN_00548cc0(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined8 uVar5;
  
  DAT_0073fe88 = 0x72;
  iVar2 = 0;
  do {
    cVar1 = "reliable"[iVar2 + 1];
    (&DAT_0073fe89)[iVar2] = cVar1;
    iVar2 = iVar2 + 1;
  } while (cVar1 != '\0');
  DAT_00740090 = 0x75;
  iVar2 = 0;
  do {
    cVar1 = "unreliable"[iVar2 + 1];
    (&DAT_00740091)[iVar2] = cVar1;
    iVar2 = iVar2 + 1;
  } while (cVar1 != '\0');
  DAT_0073fc80 = 0x43;
  iVar2 = 0;
  do {
    cVar1 = "Combined"[iVar2 + 1];
    (&DAT_0073fc81)[iVar2] = cVar1;
    iVar2 = iVar2 + 1;
  } while (cVar1 != '\0');
  do {
    uVar5 = FUN_00548e30();
    pcVar4 = (char *)((ulonglong)uVar5 >> 0x20);
    cVar1 = *(char *)uVar5;
    *pcVar4 = cVar1;
    if (cVar1 != '\0') {
      pcVar3 = pcVar4;
      do {
        cVar1 = pcVar3[(int)((char *)uVar5 + (1 - (int)pcVar4))];
        pcVar3 = pcVar3 + 1;
        *pcVar3 = cVar1;
      } while (cVar1 != '\0');
    }
  } while ((int)(pcVar4 + 0x204) < 0x73fc7c);
  return;
}


// ==== 0x548d70 FUN_00548d70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00548d70(int param_1,byte param_2,char param_3)

{
  uint uVar1;
  
  _DAT_0073fe74 = _DAT_0073fe74 + 1;
  _DAT_0073fe78 = _DAT_0073fe78 + param_1;
  if (param_3 == '\0') {
    _DAT_00740284 = _DAT_00740284 + 1;
    _DAT_00740288 = _DAT_00740288 + param_1;
  }
  else {
    _DAT_0074007c = _DAT_0074007c + 1;
    _DAT_00740080 = _DAT_00740080 + param_1;
  }
  uVar1 = (uint)param_2;
  (&DAT_0073e034)[uVar1 * 0x81] = (&DAT_0073e034)[uVar1 * 0x81] + 1;
  (&DAT_0073e038)[uVar1 * 0x81] = (&DAT_0073e038)[uVar1 * 0x81] + param_1;
  return;
}


// ==== 0x548dd0 FUN_00548dd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00548dd0(int param_1,byte param_2,char param_3)

{
  uint uVar1;
  
  _DAT_0073fe7c = _DAT_0073fe7c + 1;
  _DAT_0073fe80 = _DAT_0073fe80 + param_1;
  if (param_3 == '\0') {
    _DAT_0074028c = _DAT_0074028c + 1;
    _DAT_00740290 = _DAT_00740290 + param_1;
  }
  else {
    _DAT_00740084 = _DAT_00740084 + 1;
    _DAT_00740088 = _DAT_00740088 + param_1;
  }
  uVar1 = (uint)param_2;
  (&DAT_0073e03c)[uVar1 * 0x81] = (&DAT_0073e03c)[uVar1 * 0x81] + 1;
  (&DAT_0073e040)[uVar1 * 0x81] = (&DAT_0073e040)[uVar1 * 0x81] + param_1;
  return;
}


// ==== 0x548e30 FUN_00548e30

char * FUN_00548e30(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0:
    return "R_SC_WELCOME";
  case 1:
    return "R_BI_CARDESCRIPTION";
  case 2:
    return "U_BI_CARSPAM";
  case 3:
    return "U_CS_CLOCKSYNC";
  case 4:
    return "U_SC_CARSPAMCLOCKSYNC";
  case 5:
    return "U_BI_SCORE";
  case 6:
    return "U_SC_SYNCANIMATION";
  case 7:
    return "R_BI_DRIVERFINISH";
  case 8:
    return "R_BI_KEEPALIVE";
  case 9:
    return "R_CS_CLIENTQUIT";
  case 10:
    return "R_SC_SERVERQUIT";
  case 0xb:
    return "R_SC_CLIENTLEFT";
  case 0xc:
    return "R_CS_CSTATECHANGE";
  case 0xd:
    return "R_SC_SSTATECHANGE";
  case 0xe:
    return "R_BI_DATACRC";
  default:
    return "Unknown";
  }
}


// ==== 0x548ee0 FUN_00548ee0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00548ee0(void)

{
  DAT_0073ddc4 = 0xffffffff;
  DAT_0073ddc0 = 0xffffffff;
  _DAT_0073ddc8 = 0;
  _DAT_0073ddcc = 0;
  DAT_0073ddce = 0;
  DAT_0073ddd0 = 0;
  _DAT_0073ddd4 = 0;
  _DAT_0073ddd8 = 0xbf800000;
  DAT_0073dddc = DAT_0073ad3c;
  DAT_0073dde4 = 0xffffffff;
  DAT_0073dde0 = 0xffffffff;
  DAT_0073dde8 = 0;
  DAT_0073ddec = 0;
  DAT_0073ddee = 0;
  DAT_0073ddf0 = 0;
  DAT_0073ddf4 = 0;
  DAT_0073ddf8 = 0xbf800000;
  DAT_0073ddfc = DAT_0073ad3c;
  _DAT_0073de04 = 0xffffffff;
  _DAT_0073de00 = 0xffffffff;
  _DAT_0073de08 = 0;
  _DAT_0073de0c = 0;
  _DAT_0073de0e = 0;
  _DAT_0073de10 = 0;
  _DAT_0073de14 = 0;
  _DAT_0073de18 = 0xbf800000;
  _DAT_0073de1c = DAT_0073ad3c;
  return;
}


// ==== 0x548fa0 FUN_00548fa0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00548fa0(void)

{
  DAT_0073ddc4 = 0xffffffff;
  DAT_0073ddc0 = 0xffffffff;
  _DAT_0073ddc8 = 0;
  _DAT_0073ddcc = 0;
  DAT_0073ddce = 0;
  DAT_0073ddd0 = 0;
  _DAT_0073ddd4 = 0;
  _DAT_0073ddd8 = 0xbf800000;
  DAT_0073dddc = DAT_0073ad3c;
  DAT_0073dde4 = 0xffffffff;
  DAT_0073dde0 = 0xffffffff;
  DAT_0073dde8 = 0;
  DAT_0073ddec = 0;
  DAT_0073ddee = 0;
  DAT_0073ddf0 = 0;
  DAT_0073ddf4 = 0;
  DAT_0073ddf8 = 0xbf800000;
  DAT_0073ddfc = DAT_0073ad3c;
  _DAT_0073de04 = 0xffffffff;
  _DAT_0073de00 = 0xffffffff;
  _DAT_0073de08 = 0;
  _DAT_0073de0c = 0;
  _DAT_0073de0e = 0;
  _DAT_0073de10 = 0;
  _DAT_0073de14 = 0;
  _DAT_0073de18 = 0xbf800000;
  _DAT_0073de1c = DAT_0073ad3c;
  DAT_007354d0 = 0;
  return;
}


// ==== 0x549060 FUN_00549060

undefined4 * FUN_00549060(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &DAT_0073ddc4;
  do {
    if (*piVar2 == -1) {
      (&DAT_0073ddc4)[iVar1 * 8] = param_1;
      DAT_007354d0 = DAT_007354d0 + 1;
      return &DAT_0073ddc0 + iVar1 * 8;
    }
    piVar2 = piVar2 + 8;
    iVar1 = iVar1 + 1;
  } while ((int)piVar2 < 0x73de24);
  return (undefined4 *)0x0;
}


// ==== 0x5490a0 FUN_005490a0

void FUN_005490a0(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int unaff_ESI;
  
  uVar1 = DAT_0073ad3c;
  iVar2 = 0;
  piVar4 = &DAT_0073ddc4;
  do {
    if (*piVar4 == unaff_ESI) {
      iVar3 = iVar2 * 0x20;
      (&DAT_0073ddc4)[iVar2 * 8] = 0xffffffff;
      (&DAT_0073ddc0)[iVar2 * 8] = 0xffffffff;
      *(undefined4 *)(&DAT_0073ddc8 + iVar3) = 0;
      *(undefined2 *)(&DAT_0073ddcc + iVar3) = 0;
      (&DAT_0073ddce)[iVar2 * 0x10] = 0;
      (&DAT_0073ddd0)[iVar2 * 8] = 0;
      *(undefined4 *)(&DAT_0073ddd4 + iVar3) = 0;
      *(undefined4 *)(&DAT_0073ddd8 + iVar3) = 0xbf800000;
      (&DAT_0073dddc)[iVar2 * 8] = uVar1;
      DAT_007354d0 = DAT_007354d0 + -1;
      return;
    }
    piVar4 = piVar4 + 8;
    iVar2 = iVar2 + 1;
  } while ((int)piVar4 < 0x73de24);
  return;
}


// ==== 0x549100 FUN_00549100

void FUN_00549100(void)

{
  undefined1 *in_EAX;
  
  *(undefined4 *)(in_EAX + 300) = 0;
  *(undefined4 *)(in_EAX + 0x130) = 0;
  *(undefined4 *)(in_EAX + 0x134) = 0;
  *(undefined4 *)(in_EAX + 0x138) = 0;
  *(undefined4 *)(in_EAX + 0x13c) = 0;
  in_EAX[0x140] = 0;
  *in_EAX = 0;
  return;
}


// ==== 0x549130 EAXMod::NopArg1__ret_4_stub_shared_by__200_slots_

/* [canon] audio V (ghidra) docs/re/sound.md */

void EAXMod__NopArg1__ret_4_stub_shared_by__200_slots_(void)

{
  return;
}


// ==== 0x549140 FUN_00549140

void __fastcall FUN_00549140(int param_1,char *param_2,int param_3)

{
  char cVar1;
  char *in_EAX;
  char *pcVar2;
  int iVar3;
  
  cVar1 = *param_2;
  *in_EAX = cVar1;
  if (cVar1 != '\0') {
    pcVar2 = in_EAX;
    do {
      cVar1 = pcVar2[(int)(param_2 + (1 - (int)in_EAX))];
      pcVar2 = pcVar2 + 1;
      *pcVar2 = cVar1;
    } while (cVar1 != '\0');
  }
  iVar3 = 0;
  *(int *)(in_EAX + 0x130) = param_3;
  *(int *)(in_EAX + 0x134) = param_1;
  in_EAX[300] = '\0';
  in_EAX[0x12d] = '\0';
  in_EAX[0x12e] = '\0';
  in_EAX[0x12f] = '\0';
  if (param_1 - param_3 != -1) {
    do {
      iVar3 = iVar3 + 1;
    } while ((uint)(1 << ((byte)iVar3 & 0x1f)) < (param_1 - param_3) + 1U);
    *(int *)(in_EAX + 300) = iVar3;
  }
  *(int *)(in_EAX + 0x138) = param_1 + 1;
  *(int *)(in_EAX + 0x13c) = param_3 + -1;
  in_EAX[0x140] = '\x01';
  return;
}


// ==== 0x5491b0 FUN_005491b0

int __fastcall FUN_005491b0(int param_1)

{
  int in_EAX;
  
  return *(int *)(in_EAX + 0x130) + param_1;
}


// ==== 0x5491c0 FUN_005491c0

void FUN_005491c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  DAT_007346e0 = DAT_00735474;
  puVar2 = &DAT_007346d8;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_007346f8;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  DAT_007346d8 = DAT_0073546c;
  DAT_007346dc = DAT_00735470;
  DAT_007346e4 = DAT_00735478;
  DAT_007346f8 = DAT_0073547c;
  DAT_007346fc = DAT_00735480;
  DAT_00734700 = DAT_00735484;
  DAT_00734704 = DAT_00735488;
  DAT_007354cc = 1;
  return;
}


// ==== 0x549240 FUN_00549240

void FUN_00549240(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  DAT_00735474 = DAT_007346e0;
  puVar2 = &DAT_00735468;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  DAT_0073546c = DAT_007346d8;
  DAT_00735470 = DAT_007346dc;
  DAT_00735478 = DAT_007346e4;
  DAT_0073547c = DAT_007346f8;
  DAT_00735484 = DAT_00734700;
  DAT_00735480 = DAT_007346fc;
  DAT_00735488 = DAT_00734704;
  ProBlob__Write(&DAT_0078a478,&DAT_00735468);
  return;
}


// ==== 0x5492c0 FUN_005492c0

undefined4 FUN_005492c0(void)

{
  undefined2 local_20;
  undefined2 local_1e;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10 [4];
  undefined1 uStack_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  
  FUN_00662bc0();
  local_1e = 0;
  local_18 = 0;
  local_14 = 0;
  local_20 = 2;
  local_1c = 0x1010118;
  FUN_00663190(local_10,0x10,&local_20,0x10);
  DAT_007346d0 = CONCAT31(CONCAT21(CONCAT11(uStack_c,uStack_b),uStack_a),uStack_9);
  return 1;
}


// ==== 0x549340 FUN_00549340

int FUN_00549340(undefined4 param_1,undefined2 param_2,char param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_20;
  undefined4 local_1f;
  
  local_20 = 0;
  puVar3 = &local_1f;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  uVar1 = FUN_00662670(param_1,param_2,param_2);
  _sprintf(&local_20,"%s:%u:%u",uVar1);
  iVar2 = FUN_00663540();
  if (iVar2 == 0) {
    return 0;
  }
  if (param_3 != '\0') {
    FUN_006635d0(iVar2,0x101,&local_20);
    return iVar2;
  }
  FUN_006635d0(iVar2,0x102,&local_20);
  return iVar2;
}


// ==== 0x5493d0 FUN_005493d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005493d0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_006637b0();
  if (iVar1 != 0) {
    uVar2 = FUN_00663fe0(iVar1,0,0x2000);
    return uVar2;
  }
  if (DAT_007346d4 != 0) {
    _DAT_0078ea94 = _DAT_0078ea94 + 1;
  }
  return 0;
}


// ==== 0x549410 FUN_00549410

void __fastcall FUN_00549410(char param_1,undefined4 *param_2,undefined4 param_3)

{
  uint in_EAX;
  uint uVar1;
  undefined4 *puVar2;
  undefined1 local_220 [4];
  undefined2 local_21c;
  char local_21a;
  undefined4 local_218 [133];
  
  local_21a = (param_1 == '\0') + '\x05';
  puVar2 = local_218;
  for (uVar1 = in_EAX >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  for (uVar1 = in_EAX & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)puVar2 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  local_21c = (undefined2)in_EAX;
  FUN_00664160(param_3,local_220,1);
  return;
}


// ==== 0x549460 FUN_00549460

void FUN_00549460(undefined4 param_1)

{
  FUN_00565b60(param_1,0,0,0);
  return;
}


// ==== 0x549480 FUN_00549480

undefined4 FUN_00549480(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x2ed44);
}


// ==== 0x549490 FUN_00549490

int FUN_00549490(void)

{
  int in_EAX;
  
  return in_EAX + 0x78;
}


// ==== 0x5494a0 FUN_005494a0

undefined4 FUN_005494a0(void)

{
  int in_EAX;
  
  return *(undefined4 *)(in_EAX + 0x538);
}


// ==== 0x5494b0 FUN_005494b0

undefined4 FUN_005494b0(void)

{
  int in_EAX;
  undefined4 uVar1;
  
  if (*(int *)(in_EAX + 0x68) == 0) {
    return 0;
  }
  uVar1 = FUN_0064c660(*(undefined4 *)(in_EAX + 0x6c));
  return uVar1;
}


// ==== 0x5494d0 FUN_005494d0

uint FUN_005494d0(void)

{
  int in_EAX;
  
  return *(uint *)(in_EAX + 100) & 1;
}


// ==== 0x5494e0 FUN_005494e0

uint FUN_005494e0(void)

{
  int in_EAX;
  
  return *(uint *)(in_EAX + 100) >> 1 & 1;
}


// ==== 0x5494f0 FUN_005494f0

bool __fastcall FUN_005494f0(int param_1)

{
  return *(int *)(param_1 + 0x294) != -1;
}


// ==== 0x549500 FUN_00549500

void FUN_00549500(uint param_1)

{
  int iVar1;
  byte bVar2;
  byte *unaff_ESI;
  
  iVar1 = _isgraph((uint)param_1._3_1_);
  bVar2 = param_1._3_1_;
  if (iVar1 == 0) {
    bVar2 = 0x2d;
  }
  *unaff_ESI = bVar2;
  iVar1 = _isgraph((uint)param_1._2_1_);
  bVar2 = param_1._2_1_;
  if (iVar1 == 0) {
    bVar2 = 0x2d;
  }
  unaff_ESI[1] = bVar2;
  iVar1 = _isgraph(param_1 >> 8 & 0xff);
  bVar2 = (byte)(param_1 >> 8);
  if (iVar1 == 0) {
    bVar2 = 0x2d;
  }
  unaff_ESI[2] = bVar2;
  iVar1 = _isgraph(param_1 & 0xff);
  unaff_ESI[4] = 0;
  if (iVar1 != 0) {
    unaff_ESI[3] = (byte)param_1;
    return;
  }
  unaff_ESI[3] = 0x2d;
  return;
}


// ==== 0x549580 FUN_00549580

undefined * FUN_00549580(void)

{
  uint in_EAX;
  undefined1 local_10 [16];
  
  local_10[0] = 0x30;
  local_10[1] = 0x31;
  local_10[2] = 0x32;
  local_10[3] = 0x33;
  local_10[4] = 0x34;
  local_10[5] = 0x35;
  local_10[6] = 0x36;
  local_10[7] = 0x37;
  local_10[8] = 0x38;
  local_10[9] = 0x39;
  local_10[10] = 0x41;
  local_10[0xb] = 0x42;
  local_10[0xc] = 0x43;
  local_10[0xd] = 0x44;
  local_10[0xe] = 0x45;
  local_10[0xf] = 0x46;
  DAT_0078eba1 = local_10[in_EAX & 0xf];
  DAT_0078eba0 = local_10[(in_EAX & 0xff) >> 4];
  DAT_0078eba2 = 0;
  return &DAT_0078eba0;
}


// ==== 0x549610 FUN_00549610

undefined1 * __fastcall FUN_00549610(undefined4 param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined4 *)(param_2 + 0x34) = 0;
  *(undefined4 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x3c) = 0;
  *(undefined4 *)(param_2 + 0x40) = 0;
  *(undefined4 *)(param_2 + 0x44) = 0;
  *(undefined4 *)(param_2 + 0x48) = 0;
  *(undefined4 *)(param_2 + 0x4c) = 0;
  *(undefined4 *)(param_2 + 0x50) = 0;
  param_2[0x58] = 0;
  *(undefined4 *)(param_2 + 0x5c) = 0;
  *(undefined4 *)(param_2 + 0x60) = 0;
  *(undefined4 *)(param_2 + 100) = 0;
  *(undefined4 *)(param_2 + 0x68) = 0;
  *(undefined4 *)(param_2 + 0x6c) = 0;
  *(undefined4 *)(param_2 + 0x70) = 0;
  *(undefined4 *)(param_2 + 0x74) = 0;
  *(undefined4 *)(param_2 + 0x54) = 0xffffffff;
  puVar1 = param_2 + 0x284;
  *(undefined1 **)puVar1 = puVar1;
  *(undefined1 **)(param_2 + 0x288) = puVar1;
  *(undefined4 *)(param_2 + 0x28c) = 0;
  *(undefined4 *)(param_2 + 0x290) = 0;
  *(undefined4 *)(param_2 + 0x538) = 0x18;
  *(undefined4 *)(param_2 + 0x53c) = 0x18;
  *(undefined4 *)(param_2 + 0x540) = 0;
  *(undefined4 *)(param_2 + 0x544) = 0;
  *(undefined4 *)(param_2 + 0x548) = 0;
  *(undefined4 *)(param_2 + 0x54c) = 0;
  param_2[0x550] = 0;
  *param_2 = 0;
  param_2[0xd] = 0;
  *(undefined4 *)(param_2 + 0x78) = 0;
  *(undefined4 *)(param_2 + 0x7c) = 0;
  *(undefined4 *)(param_2 + 0x80) = 0;
  param_2[0x84] = 0;
  *(undefined4 *)(param_2 + 0x534) = 0xffffffff;
  puVar3 = (undefined4 *)(param_2 + 0x294);
  for (iVar2 = 0xa8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(param_2 + 0x294) = 0xffffffff;
  return param_2;
}


// ==== 0x549700 FUN_00549700

undefined4 FUN_00549700(void)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_208;
  undefined4 local_207;
  
  FUN_00549980();
  local_208 = 0;
  puVar3 = &local_207;
  for (iVar2 = 0x7f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  FUN_0054dd30(0x200);
  uVar1 = FUN_006687e0(0x4b);
  *(undefined4 *)(in_EAX + 0x28c) = uVar1;
  uVar1 = _ftol_nocw();
  *(undefined4 *)(in_EAX + 0x290) = uVar1;
  iVar2 = FUN_006655c0(&local_208,0,NullUpdate_ret);
  *(int *)(in_EAX + 0x68) = iVar2;
  if (iVar2 != 0) {
    iVar2 = FUN_00664c00(iVar2,0,FUN_0054d020,&DAT_0073d868);
    *(int *)(in_EAX + 0x6c) = iVar2;
    if (iVar2 != 0) {
      FUN_00666f60(iVar2,0,1,FUN_0054b980);
      iVar2 = FUN_00664c00(*(undefined4 *)(in_EAX + 0x68),1,FUN_0054d0b0,&DAT_0073d868);
      *(int *)(in_EAX + 0x70) = iVar2;
      if (iVar2 != 0) {
        FUN_00666f60(iVar2,0,0,FUN_0054ba10);
        FUN_00666f90(*(undefined4 *)(in_EAX + 0x70),0,0,FUN_0054bc50);
        puVar3 = (undefined4 *)(in_EAX + 0x294);
        for (iVar2 = 0xa8; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        }
        *(undefined4 *)(in_EAX + 0x294) = 0xffffffff;
        *(undefined4 *)(in_EAX + 0x534) = 0xffffffff;
        iVar2 = FUN_00664c00(*(undefined4 *)(in_EAX + 0x68),5,FUN_0054d320,&DAT_0073d868);
        *(int *)(in_EAX + 0x74) = iVar2;
        if (iVar2 != 0) {
          FUN_00666f60(iVar2,0,0,FUN_0054bc20);
          FUN_00666f90(*(undefined4 *)(in_EAX + 0x74),0,0,FUN_0054bd60);
          FUN_00664aa0(*(undefined4 *)(in_EAX + 0x68),0,FUN_0054bda0,&DAT_0073d868);
          FUN_00664aa0(*(undefined4 *)(in_EAX + 0x68),1,FUN_0054be20,&DAT_0073d868);
          FUN_00664aa0(*(undefined4 *)(in_EAX + 0x68),3,FUN_0054c5b0,&DAT_0073d868);
          FUN_00664aa0(*(undefined4 *)(in_EAX + 0x68),4,FUN_0054c5f0,&DAT_0073d868);
          *(undefined4 *)(in_EAX + 0x78) = 0;
          *(undefined4 *)(in_EAX + 0x7c) = 0;
          *(undefined4 *)(in_EAX + 0x80) = 0;
          *(undefined1 *)(in_EAX + 0x84) = 0;
          *(undefined4 *)(in_EAX + 0x54c) = 0;
          *(undefined1 *)(in_EAX + 0x550) = 0;
          *(undefined4 *)(in_EAX + 0x53c) = *(undefined4 *)(in_EAX + 0x538);
          *(undefined4 *)(in_EAX + 0x538) = 0;
          return 0;
        }
      }
    }
  }
  FUN_00549980();
  return 0xffffffff;
}


// ==== 0x5498f0 FUN_005498f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005498f0(void)

{
  undefined4 in_EAX;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x540) = 1;
  *(undefined4 *)(unaff_ESI + 0x544) = in_EAX;
  DAT_007346cc = FUN_00668c50(s_ps2nfs04_ea_com_006f1f40,10000);
  if (DAT_007346cc == 0) {
    _DAT_0073dda4 = DAT_0073dda0;
    DAT_0073dda0 = 0x18;
    *(undefined4 *)(unaff_ESI + 0x78) = 2;
  }
  else {
    _DAT_0073dda4 = DAT_0073dda0;
    DAT_0073dda0 = 2;
    *(undefined4 *)(unaff_ESI + 0x78) = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x7c) = 0;
  *(undefined4 *)(unaff_ESI + 0x80) = 0;
  *(undefined1 *)(unaff_ESI + 0x84) = 0;
  if (*(code **)(unaff_ESI + 0x544) != (code *)0x0) {
    (**(code **)(unaff_ESI + 0x544))();
  }
  *(undefined4 *)(unaff_ESI + 0x540) = 0;
  *(undefined4 *)(unaff_ESI + 0x544) = 0;
  return;
}


// ==== 0x549980 FUN_00549980

void FUN_00549980(void)

{
  int unaff_ESI;
  
  DAT_00734fd0 = 0;
  if (*(int *)(unaff_ESI + 0x68) != 0) {
    FUN_00664990(*(int *)(unaff_ESI + 0x68));
    if (*(int *)(unaff_ESI + 0x6c) != 0) {
      FUN_00664c70(*(undefined4 *)(unaff_ESI + 0x68),0,*(int *)(unaff_ESI + 0x6c));
      *(undefined4 *)(unaff_ESI + 0x6c) = 0;
    }
    if (*(int *)(unaff_ESI + 0x70) != 0) {
      FUN_00664c70(*(undefined4 *)(unaff_ESI + 0x68),1,*(int *)(unaff_ESI + 0x70));
      *(undefined4 *)(unaff_ESI + 0x70) = 0;
    }
    if (*(int *)(unaff_ESI + 0x74) != 0) {
      FUN_00664c70(*(undefined4 *)(unaff_ESI + 0x68),5,*(int *)(unaff_ESI + 0x74));
      *(undefined4 *)(unaff_ESI + 0x74) = 0;
    }
    if (*(int *)(unaff_ESI + 0x68) != 0) {
      if (*(int *)(unaff_ESI + 0x40) != 0) {
        FUN_00664c70(*(int *)(unaff_ESI + 0x68),6,*(int *)(unaff_ESI + 0x40));
        *(undefined4 *)(unaff_ESI + 0x40) = 0;
      }
      *(undefined4 *)(unaff_ESI + 0x54) = 0xffffffff;
      *(undefined1 *)(unaff_ESI + 0x58) = 0;
      *(undefined4 *)(unaff_ESI + 0x44) = 0;
      *(undefined4 *)(unaff_ESI + 0x48) = 0;
      *(undefined4 *)(unaff_ESI + 0x4c) = 0;
      *(undefined4 *)(unaff_ESI + 0x50) = 0;
    }
    *(undefined4 *)(unaff_ESI + 0x30) = 0;
    *(undefined4 *)(unaff_ESI + 0x34) = 0;
    *(undefined4 *)(unaff_ESI + 0x38) = 0;
    *(undefined4 *)(unaff_ESI + 0x3c) = 0;
    FUN_00664a40(*(undefined4 *)(unaff_ESI + 0x68));
    *(undefined4 *)(unaff_ESI + 0x68) = 0;
    FUN_00668870(*(undefined4 *)(unaff_ESI + 0x28c));
    *(undefined4 *)(unaff_ESI + 0x28c) = 0;
  }
  DAT_0073d875 = 0;
  DAT_0073d868 = 0;
  DAT_0073dda8 = 0;
  DAT_0073ddac = 0;
  DAT_0073ddb0 = 0;
  DAT_0073ddb8 = 0;
  DAT_0073d8cc = 0;
  DAT_0073dd9c = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x53c) = *(undefined4 *)(unaff_ESI + 0x538);
  *(undefined4 *)(unaff_ESI + 0x538) = 0x18;
  return;
}


// ==== 0x549aa0 FUN_00549aa0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00549aa0(void)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  
  if (*(int *)(in_EAX + 0x68) != 0) {
    FUN_00665660(*(int *)(in_EAX + 0x68));
    FUN_006688b0(*(undefined4 *)(in_EAX + 0x28c));
    FUN_00549ff0(0x41f00000);
    iVar2 = FUN_00665120(*(undefined4 *)(in_EAX + 0x68));
    if (iVar2 == 0x400) {
      FUN_0054b1c0(in_EAX);
      return;
    }
    if (*(int *)(in_EAX + 0x538) != 0x15) {
      piVar1 = (int *)(in_EAX + 0x78);
      if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
        FUN_00549500(*(undefined4 *)(in_EAX + 0x7c));
        FUN_00549500(*piVar1);
        if (*(int *)(in_EAX + 0x7c) == 0x64697363) {
          FUN_0054b1c0(in_EAX);
          return;
        }
        if (*(int *)(in_EAX + 0x540) == 0) {
          *piVar1 = 0;
          *(undefined4 *)(in_EAX + 0x7c) = 0;
          *(undefined4 *)(in_EAX + 0x80) = 0;
          *(undefined1 *)(in_EAX + 0x84) = 0;
        }
      }
      if (DAT_00706fd0 != *(int *)(in_EAX + 0x538)) {
        DAT_00706fd0 = *(int *)(in_EAX + 0x538);
      }
      switch(DAT_0073dda0) {
      case 4:
        FUN_0054b1a0(0x73656c65);
        FUN_00665660(DAT_0073d8d0);
        FUN_0054b370();
        return;
      case 6:
        FUN_0054b410();
        return;
      case 8:
        FUN_0054b4e0(&DAT_0073d868);
        return;
      case 10:
        _DAT_0073dda4 = DAT_0073dda0;
        DAT_0073dda0 = 0xd;
        break;
      case 0xc:
        FUN_0054b690();
        return;
      }
    }
  }
  return;
}


// ==== 0x549c40 FUN_00549c40

int FUN_00549c40(void)

{
  int iVar1;
  char *pcVar2;
  char *unaff_EBX;
  int iVar3;
  int iVar4;
  int unaff_EDI;
  
  iVar3 = 0;
  iVar4 = 0;
  do {
    if (*(int *)(unaff_EDI + 0x68) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_0064c660(*(undefined4 *)(unaff_EDI + 0x6c));
    }
    if (iVar1 <= iVar4) {
      return iVar3;
    }
    if (*(int *)(unaff_EDI + 0x68) == 0) {
LAB_00549c81:
      pcVar2 = "";
    }
    else {
      iVar1 = FUN_00666f30(DAT_0073d8d4,iVar4);
      if (iVar1 == 0) goto LAB_00549c81;
      pcVar2 = (char *)(iVar1 + 0x1c);
    }
    if ((*unaff_EBX == *pcVar2) && (unaff_EBX[1] == pcVar2[1])) {
      iVar3 = iVar3 + 1;
    }
    iVar4 = iVar4 + 1;
  } while( true );
}


// ==== 0x549ca0 FUN_00549ca0

char * FUN_00549ca0(char *param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x68) == 0) {
    return "";
  }
  iVar3 = 0;
  iVar4 = 0;
  while( true ) {
    if (*(int *)(unaff_EDI + 0x68) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_0064c660(*(undefined4 *)(unaff_EDI + 0x6c));
    }
    if (iVar1 <= iVar4) break;
    if ((*(int *)(unaff_EDI + 0x68) == 0) || (iVar1 = FUN_00666f30(DAT_0073d8d4,iVar4), iVar1 == 0))
    {
      pcVar2 = "";
    }
    else {
      pcVar2 = (char *)(iVar1 + 0x1c);
    }
    if ((*param_1 == *pcVar2) && (param_1[1] == pcVar2[1])) {
      if (iVar3 == param_2) {
        return pcVar2;
      }
      iVar3 = iVar3 + 1;
    }
    iVar4 = iVar4 + 1;
  }
  return "";
}


// ==== 0x549d30 FUN_00549d30

void FUN_00549d30(char *param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int unaff_EBX;
  int iVar2;
  int iVar3;
  
  if (*(int *)(unaff_EBX + 0x68) != 0) {
    iVar2 = 0;
    iVar3 = 0;
    while( true ) {
      if (*(int *)(unaff_EBX + 0x68) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_0064c660(*(undefined4 *)(unaff_EBX + 0x6c));
      }
      if (iVar1 <= iVar3) break;
      iVar1 = FUN_00666f30(DAT_0073d8d4,iVar3);
      if (iVar1 != 0) {
        if (*(int *)(unaff_EBX + 0x68) != 0) {
          FUN_00666f30(DAT_0073d8d4,iVar3);
        }
        if ((*param_1 == *(char *)(iVar1 + 0x1c)) && (param_1[1] == *(char *)(iVar1 + 0x1d))) {
          if (iVar2 == param_2) {
            *param_3 = *(undefined4 *)(iVar1 + 0x10);
            *param_4 = *(undefined4 *)(iVar1 + 0xc);
          }
          iVar2 = iVar2 + 1;
        }
      }
      iVar3 = iVar3 + 1;
    }
  }
  return;
}


// ==== 0x549dc0 FUN_00549dc0

undefined * __fastcall FUN_00549dc0(int param_1)

{
  int in_EAX;
  int iVar1;
  undefined1 local_8c [44];
  int local_60;
  int local_44;
  int local_28;
  int local_c;
  
  if ((*(int *)(in_EAX + 0x68) != 0) && (iVar1 = FUN_0054a140(in_EAX,local_8c), iVar1 == 0)) {
    if ((((param_1 == 0) || (local_60 = local_44, param_1 == 1)) ||
        (local_60 = local_c, param_1 == 2)) || (local_60 = local_28, param_1 == 3)) {
      if (local_60 == 0) {
        local_60 = 100;
      }
      FUN_00565da0(&DAT_006ca778,local_60);
    }
    return &DAT_0078ee30;
  }
  return &DAT_006ca910;
}


// ==== 0x549e50 FUN_00549e50

int FUN_00549e50(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  int local_730 [459];
  
  if (in_EAX != 0) {
    RideInfo__Init();
    iVar1 = FUN_00549ed0(param_1,local_730);
    if (iVar1 != 0) {
      return local_730[0] * 0xc90 + DAT_00734588;
    }
  }
  return 0;
}


// ==== 0x549ea0 FUN_00549ea0

undefined4 __thiscall FUN_00549ea0(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 uVar1;
  
  if (*(int *)(in_EAX + 0x68) == 0) {
    return 0;
  }
  FUN_0054b700(in_EAX,param_1);
  uVar1 = FUN_00549ed0(in_EAX,param_2);
  return uVar1;
}


// ==== 0x549ed0 FUN_00549ed0

undefined4 FUN_00549ed0(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  char cVar5;
  int unaff_ESI;
  byte local_50d;
  undefined1 local_50c [256];
  undefined1 local_40c [1036];
  
  if (unaff_ESI != 0) {
    cVar2 = *(char *)(unaff_ESI + 0xf8);
    cVar5 = '\0';
    local_50d = 0;
    if (cVar2 != '\0') {
      bVar1 = cVar2 - 0x30;
      if (9 < bVar1) {
        bVar1 = cVar2 - 0x37;
      }
      cVar2 = *(char *)(unaff_ESI + 0xf9);
      cVar5 = bVar1 << 4;
      if ((cVar2 != '\0') && (local_50d = cVar2 - 0x30, 9 < local_50d)) {
        local_50d = cVar2 - 0x37;
      }
    }
    cVar2 = GetNetModeCode();
    if ((byte)(local_50d + cVar5) == cVar2) {
      pcVar3 = (char *)(unaff_ESI + 0xfa);
      do {
        cVar2 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar2 != '\0');
      iVar4 = FUN_005ab3e0((int)pcVar3 - (unaff_ESI + 0xfb),local_50c,0x100);
      if (iVar4 != 0) {
        FUN_004392a0();
        FUN_00548a50(local_40c,local_50c);
        FUN_0043ccf0(param_2,local_40c,0x2a);
        return param_2;
      }
    }
  }
  return 0;
}


// ==== 0x549fc0 FUN_00549fc0

undefined4 FUN_00549fc0(void)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_ESI;
  
  iVar1 = FUN_0054b700(unaff_ESI,in_EAX);
  if (iVar1 != 0) {
    iVar1 = FUN_00549e50(unaff_ESI);
    if (iVar1 != 0) {
      uVar2 = GetCarModelNameHash();
      return uVar2;
    }
  }
  return 0;
}


// ==== 0x549ff0 FUN_00549ff0

void FUN_00549ff0(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x290) < DAT_0073ad3c) {
    iVar3 = 0;
    while( true ) {
      if (*(int *)(unaff_EDI + 0x68) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_0064c660(*(undefined4 *)(unaff_EDI + 0x70));
      }
      if (iVar1 <= iVar3) break;
      iVar1 = FUN_00666f30(DAT_0073d8d8,iVar3);
      FUN_00668bc0(*(undefined4 *)(unaff_EDI + 0x28c),*(undefined4 *)(iVar1 + 0x30));
      iVar3 = iVar3 + 1;
    }
    uVar2 = _ftol_nocw();
    *(undefined4 *)(unaff_EDI + 0x290) = uVar2;
  }
  return;
}


// ==== 0x54a070 FUN_0054a070

long __fastcall FUN_0054a070(int param_1,int param_2,char param_3)

{
  long lVar1;
  
  lVar1 = -1;
  if ((*(int *)(param_2 + 0x68) != 0) && (param_1 != 0)) {
    if (param_3 == '\0') {
      lVar1 = FUN_00668b40(DAT_0073daf4,*(undefined4 *)(param_1 + 0x30),0,0);
      return lVar1;
    }
    lVar1 = _atoi((char *)(param_1 + 0x28));
  }
  return lVar1;
}


// ==== 0x54a0c0 FUN_0054a0c0

undefined1 * __thiscall FUN_0054a0c0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x68) != 0) {
    if (param_1 == -1) {
      param_1 = *(int *)(unaff_ESI + 0x294);
    }
    uVar1 = FUN_00664d40(*(int *)(unaff_ESI + 0x68),5,param_1);
    iVar2 = FUN_00666ea0(*(undefined4 *)(unaff_ESI + 0x74),uVar1);
    if (iVar2 != 0) {
      if (*(int *)(unaff_ESI + 0x68) == 0) {
        puVar3 = (undefined1 *)FUN_00549dc0();
        return puVar3;
      }
      uVar1 = FUN_00664d40(*(int *)(unaff_ESI + 0x68),1,*(undefined4 *)(iVar2 + 0x184 + param_2 * 4)
                          );
      FUN_00666ea0(*(undefined4 *)(unaff_ESI + 0x70),uVar1);
      puVar3 = (undefined1 *)FUN_00549dc0();
      return puVar3;
    }
  }
  return &DAT_006b9172;
}


// ==== 0x54a140 FUN_0054a140

undefined4 __fastcall
FUN_0054a140(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar2 = 0;
  puVar4 = param_4;
  for (iVar3 = 0x23; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  if (param_2 != 0) {
    pcVar1 = (char *)(param_2 + 0x38);
    if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
      do {
        iVar3 = iVar2 + 1;
        iVar2 = iVar2 + 1;
      } while (pcVar1[iVar3] != '\0');
      if (0 < iVar2) {
        FUN_006682f0(pcVar1,param_4,0x8c,&DAT_006bd444);
        return 0;
      }
    }
    puVar4 = &DAT_006f3cd0;
    for (iVar2 = 0x23; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_4 = *puVar4;
      puVar4 = puVar4 + 1;
      param_4 = param_4 + 1;
    }
    return 0;
  }
  return 0xffffffff;
}


// ==== 0x54a1b0 FUN_0054a1b0

void __fastcall FUN_0054a1b0(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_ESI;
  
  FUN_0054b700(unaff_ESI,param_1);
  FUN_0054a140(unaff_ESI,in_EAX);
  return;
}


// ==== 0x54a1d0 FUN_0054a1d0

undefined4 __thiscall FUN_0054a1d0(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x68) != 0) {
    if (param_1 == -1) {
      param_1 = *(int *)(unaff_ESI + 0x294);
    }
    uVar1 = FUN_00664d40(*(int *)(unaff_ESI + 0x68),5,param_1);
    iVar2 = FUN_00666ea0(*(undefined4 *)(unaff_ESI + 0x74),uVar1);
    if (iVar2 != 0) {
      if (*(int *)(unaff_ESI + 0x68) == 0) {
        uVar1 = FUN_0054a070(param_3);
        return uVar1;
      }
      uVar1 = FUN_00664d40(*(int *)(unaff_ESI + 0x68),1,*(undefined4 *)(iVar2 + 0x184 + param_2 * 4)
                          );
      FUN_00666ea0(*(undefined4 *)(unaff_ESI + 0x70),uVar1);
      uVar1 = FUN_0054a070(param_3);
      return uVar1;
    }
  }
  return 0xffffffff;
}


// ==== 0x54a260 FUN_0054a260

undefined1 * __fastcall FUN_0054a260(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x68) != 0) {
    if (param_1 == -1) {
      param_1 = *(int *)(unaff_ESI + 0x294);
    }
    uVar1 = FUN_00664d40(*(int *)(unaff_ESI + 0x68),5,param_1);
    iVar2 = FUN_00666ea0(*(undefined4 *)(unaff_ESI + 0x74),uVar1);
    if (iVar2 != 0) {
      return (undefined1 *)(iVar2 + 4);
    }
  }
  return &DAT_006b9172;
}


// ==== 0x54a2a0 FUN_0054a2a0

int FUN_0054a2a0(void)

{
  int iVar1;
  int unaff_EBX;
  int iVar2;
  int unaff_EDI;
  
  if (unaff_EBX == 0) {
    return -1;
  }
  iVar2 = 0;
  iVar1 = FUN_00666f30(*(undefined4 *)(unaff_EDI + 0x40),0);
  while( true ) {
    if (iVar1 == 0) {
      return -1;
    }
    if (iVar1 == unaff_EBX) break;
    iVar2 = iVar2 + 1;
    iVar1 = FUN_00666f30(*(undefined4 *)(unaff_EDI + 0x40),iVar2);
  }
  return iVar2;
}


// ==== 0x54a2e0 FUN_0054a2e0

undefined4 __fastcall
FUN_0054a2e0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  char *in_EAX;
  int iVar2;
  undefined1 local_18 [24];
  
  if ((in_EAX != (char *)0x0) && (*in_EAX != '\0')) {
    iVar2 = 0;
    do {
      iVar1 = iVar2 + 1;
      iVar2 = iVar2 + 1;
    } while (in_EAX[iVar1] != '\0');
    if ((iVar2 < 0xd) && (*(int *)(param_2 + 0x68) != 0)) {
      *(undefined4 *)(param_2 + 0x30) = param_3;
      *(undefined4 *)(param_2 + 0x34) = param_4;
      local_18[0] = 0;
      FUN_00667d70(local_18,0x18,"PERS=%s");
      if (DAT_0073d8d0 != 0) {
        FUN_00664e00(DAT_0073d8d0,0x75736572,local_18,FUN_0054c350,0);
      }
      return 0;
    }
  }
  return 0xffffffff;
}


// ==== 0x54a370 FUN_0054a370

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall
FUN_0054a370(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int unaff_EBX;
  uint uVar6;
  undefined1 local_2a4 [36];
  undefined1 local_280 [128];
  undefined1 local_200 [512];
  
  if (*(int *)(in_EAX + 0x68) != 0) {
    *(undefined4 *)(in_EAX + 0x544) = param_4;
    *(undefined4 *)(in_EAX + 0x540) = 8;
    DAT_0073ddb0 = param_2;
    *(uint *)(in_EAX + 100) = *(uint *)(in_EAX + 100) | 1;
    DAT_007346c8 = 1;
    local_200[0] = 0;
    iVar2 = RaceOptions_Get();
    uVar6 = 0;
    cVar1 = Obj_GetByte19();
    if (cVar1 != '\0') {
      uVar6 = 0x40000;
    }
    if (unaff_EBX == 0) {
      uVar6 = uVar6 | 2;
    }
    uVar5 = DAT_006f227c % 1000;
    uVar4 = DAT_006f227c ^ 0x1d872b41;
    uVar3 = uVar4 >> 5 ^ uVar4;
    DAT_006f227c = uVar3 << 0x1b ^ uVar3 ^ uVar4;
    FUN_00565da0("%04d_%s",uVar5,param_3);
    local_280[0] = 0;
    FUN_00667d70(local_280,0x80,"TRACK=%d DIR=%d LAPS=%d MYIP=%d",*(undefined4 *)(iVar2 + 8),
                 *(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 0x10),DAT_007346d0);
    FUN_00667d70(local_200,0x200,"NAME=%s ROOM=%s MAXSIZE=%d MINSIZE=2 SYSFLAGS=%d PARAMS=%s",
                 local_2a4,&DAT_00777c70,(unaff_EBX != 0) * '\x02' + '\x02',uVar6,local_280);
    if (DAT_0073d8d0 != 0) {
      FUN_00664e00(DAT_0073d8d0,0x67637265,local_200,FUN_0054cb30,0);
    }
    _DAT_0073dda4 = DAT_0073dda0;
    DAT_0073dda0 = 0x12;
  }
  return;
}


// ==== 0x54a4e0 FUN_0054a4e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0054a4e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined1 local_40 [64];
  
  if (*(int *)(in_EAX + 0x68) == 0) {
    return;
  }
  *(undefined4 *)(in_EAX + 0x540) = 9;
  *(undefined4 *)(in_EAX + 0x544) = param_3;
  DAT_007346c8 = 0;
  DAT_0073ddb0 = param_2;
  iVar1 = FUN_0054b7b0(&DAT_0073d868);
  if ((iVar1 != 0) && (iVar2 = bStrCmp(), iVar2 == 0)) {
    FUN_00667d70(local_40,0x40,"NAME=%s",iVar1 + 4);
    if (DAT_0073d8d0 != 0) {
      FUN_00664e00(DAT_0073d8d0,0x676a6f69,local_40,FUN_0054cb30,0);
    }
    _DAT_0073dda4 = DAT_0073dda0;
    DAT_0073dda0 = 0x13;
    return;
  }
  FUN_0054cf80();
  if (DAT_0073ddac != (code *)0x0) {
    (*DAT_0073ddac)();
  }
  DAT_0073dda8 = 0;
  DAT_0073ddac = (code *)0x0;
  return;
}


// ==== 0x54a5e0 FUN_0054a5e0

void __thiscall FUN_0054a5e0(char *param_1,undefined4 param_2)

{
  int in_EAX;
  undefined1 local_80 [128];
  
  if (((*(int *)(in_EAX + 0x68) != 0) && (param_1 != (char *)0x0)) && (*param_1 != '\0')) {
    *(undefined4 *)(in_EAX + 0x540) = 5;
    *(undefined4 *)(in_EAX + 0x544) = param_2;
    local_80[0] = 0;
    FUN_00667d70(local_80,0x80,"NAME=%s",param_1);
    if (DAT_0073d8d0 != 0) {
      FUN_00664e00(DAT_0073d8d0,0x726f6f6d,local_80,FUN_0054c9e0,0);
    }
  }
  return;
}


// ==== 0x54a660 FUN_0054a660

void __fastcall FUN_0054a660(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int unaff_ESI;
  undefined1 local_200 [512];
  
  if (((*(int *)(unaff_ESI + 0x68) != 0) && (DAT_007346c8 != 0)) &&
     (*(int *)(unaff_ESI + 0x294) != -1)) {
    *(undefined4 *)(unaff_ESI + 0x540) = 0x11;
    *(undefined4 *)(unaff_ESI + 0x544) = param_2;
    uVar1 = FUN_00664d40(*(int *)(unaff_ESI + 0x68),5,*(int *)(unaff_ESI + 0x294));
    iVar2 = FUN_00666ea0(*(undefined4 *)(unaff_ESI + 0x74),uVar1);
    if (iVar2 == 0) {
      puVar3 = &DAT_006b9172;
    }
    else {
      puVar3 = (undefined1 *)(iVar2 + 4);
    }
    FUN_00667d70(local_200,0x200,"NAME=%s",puVar3);
    if (DAT_0073d8d0 != 0) {
      FUN_00664e00(DAT_0073d8d0,0x67737461,local_200,FUN_0054c480,0);
    }
  }
  return;
}


// ==== 0x54a700 FUN_0054a700

void FUN_0054a700(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined1 local_40 [64];
  
  if (*(int *)(in_EAX + 0x68) != 0) {
    *(undefined4 *)(in_EAX + 0x540) = 0xf;
    *(undefined4 *)(in_EAX + 0x544) = param_1;
    iVar1 = FUN_0054b7b0(&DAT_0073d868);
    if ((iVar1 == 0) || (iVar2 = bStrCmp(), iVar2 != 0)) {
      FUN_0054cf80();
      if (DAT_0073ddac != (code *)0x0) {
        (*DAT_0073ddac)();
      }
      DAT_0073dda8 = 0;
      DAT_0073ddac = (code *)0x0;
      return;
    }
    FUN_00667d70(local_40,0x40,"NAME=%s",iVar1 + 4);
    if (DAT_0073d8d0 != 0) {
      FUN_00664e00(DAT_0073d8d0,0x67676574,local_40,FUN_0054cc10,0);
    }
  }
  return;
}


// ==== 0x54a7e0 FUN_0054a7e0

void FUN_0054a7e0(char param_1)

{
  int iVar1;
  char *in_EAX;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  code *unaff_EDI;
  undefined1 local_80 [128];
  
  iVar3 = *(int *)(in_EAX + 0x68);
  if (iVar3 == 0) {
    return;
  }
  iVar1 = *(int *)(in_EAX + 0x294);
  if (iVar1 == -1) {
    if ((DAT_00777b54 == 0) && (iVar3 = 0, *in_EAX != '\0')) {
      do {
        iVar1 = iVar3 + 1;
        iVar3 = iVar3 + 1;
      } while (in_EAX[iVar1] != '\0');
      if (0 < iVar3) {
        FUN_0054b8e0(1);
        goto LAB_0054a9f7;
      }
    }
    in_EAX[0x78] = '\0';
    in_EAX[0x79] = '\0';
    in_EAX[0x7a] = '\0';
    in_EAX[0x7b] = '\0';
    in_EAX[0x7c] = '\0';
    in_EAX[0x7d] = '\0';
    in_EAX[0x7e] = '\0';
    in_EAX[0x7f] = '\0';
    in_EAX[0x80] = '\0';
    in_EAX[0x81] = '\0';
    in_EAX[0x82] = '\0';
    in_EAX[0x83] = '\0';
    in_EAX[0x84] = '\0';
    in_EAX[0x540] = '\x12';
    in_EAX[0x541] = '\0';
    in_EAX[0x542] = '\0';
    in_EAX[0x543] = '\0';
    *(code **)(in_EAX + 0x544) = unaff_EDI;
    if (unaff_EDI != (code *)0x0) {
      (*unaff_EDI)();
    }
    in_EAX[0x540] = '\0';
    in_EAX[0x541] = '\0';
    in_EAX[0x542] = '\0';
    in_EAX[0x543] = '\0';
    in_EAX[0x544] = '\0';
    in_EAX[0x545] = '\0';
    in_EAX[0x546] = '\0';
    in_EAX[0x547] = '\0';
  }
  else if ((in_EAX[100] & 1U) == 0) {
    in_EAX[0x540] = '\x12';
    in_EAX[0x541] = '\0';
    in_EAX[0x542] = '\0';
    in_EAX[0x543] = '\0';
    *(code **)(in_EAX + 0x544) = unaff_EDI;
    local_80[0] = 0;
    if (param_1 == '\0') {
      uVar2 = FUN_00664d40(iVar3,5,iVar1);
      iVar3 = FUN_00666ea0(*(undefined4 *)(in_EAX + 0x74),uVar2);
      if (iVar3 == 0) {
        puVar4 = &DAT_006b9172;
      }
      else {
        puVar4 = (undefined1 *)(iVar3 + 4);
      }
      FUN_00667950(local_80,0x80,&DAT_006bd3bc,puVar4);
      if (DAT_0073d8d0 == 0) {
        return;
      }
      FUN_00664e00(DAT_0073d8d0,0x676c6561,local_80,FUN_0054ce70,0);
      return;
    }
    FUN_00667950(local_80,0x80,&DAT_006bd3c4,&DAT_006bd3cc);
    if (DAT_0073d8d0 != 0) {
      FUN_00664e00(DAT_0073d8d0,0x6368616c,local_80,FUN_0054ce70,0);
    }
  }
  else {
    uVar2 = FUN_00664d40(iVar3,5,iVar1);
    iVar3 = FUN_00666ea0(*(undefined4 *)(in_EAX + 0x74),uVar2);
    if ((iVar3 != 0) && (*(char *)(iVar3 + 4) != '\0')) {
      in_EAX[0x540] = '\x13';
      in_EAX[0x541] = '\0';
      in_EAX[0x542] = '\0';
      in_EAX[0x543] = '\0';
      *(code **)(in_EAX + 0x544) = unaff_EDI;
      local_80[0] = 0;
      if (param_1 == '\0') {
        uVar2 = FUN_0054a260();
        FUN_00667950(local_80,0x80,&DAT_006bd3bc,uVar2);
        FUN_0054b1a0(0x6764656c);
        return;
      }
      FUN_00667950(local_80,0x80,&DAT_006bd3c4,&DAT_006bd3cc);
      FUN_0054b1a0(0x6368616c);
    }
  }
LAB_0054a9f7:
  if (param_1 != '\0') {
    FUN_00666f90(DAT_0073d8dc,0,0,FUN_0054bd60);
  }
  return;
}


// ==== 0x54aa30 FUN_0054aa30

void FUN_0054aa30(void)

{
  DAT_0073dd9c = 0xffffffff;
  DAT_0073d875 = 0;
  DAT_0073d868 = 0;
  DAT_0073dda8 = 0;
  DAT_0073ddac = 0;
  DAT_0073ddb0 = 0;
  DAT_0073ddb8 = 0;
  DAT_0073d8cc = 0;
  return;
}


// ==== 0x54aa70 FUN_0054aa70

void FUN_0054aa70(void)

{
  int in_EAX;
  undefined4 uVar1;
  undefined1 local_dc0 [2];
  undefined1 local_dbe [254];
  undefined1 local_cc0 [384];
  undefined1 local_b40 [1040];
  undefined1 local_730 [1836];
  
  if (*(int *)(in_EAX + 0x68) != 0) {
    FUN_004392a0();
    RideInfo__Init();
    cFrontendDatabase__BuildRideForCarHandle(local_730);
    FUN_0043cb60(local_730,local_b40,1);
    GetNetModeCode();
    uVar1 = FUN_00549580();
    FUN_00565da0(uVar1);
    uVar1 = FUN_004388d0(local_dbe,0xfe,1);
    uVar1 = FUN_006497c0(uVar1);
    FUN_005ab2b0(uVar1);
    local_cc0[0] = 0;
    FUN_00667d70(local_cc0,0x180,"TEXT=%s",local_dc0);
    if (DAT_0073d8d0 != 0) {
      FUN_00664e00(DAT_0073d8d0,0x61757869,local_cc0,FUN_0054cf40,0);
    }
  }
  return;
}


// ==== 0x54ab80 FUN_0054ab80

void __thiscall FUN_0054ab80(undefined4 param_1,undefined4 param_2)

{
  int unaff_ESI;
  undefined1 local_40 [64];
  
  if (*(int *)(unaff_ESI + 0x68) != 0) {
    *(undefined4 *)(unaff_ESI + 0x540) = 6;
    *(undefined4 *)(unaff_ESI + 0x544) = param_2;
    local_40[0] = 0;
    FUN_00667950(local_40,0x40,&DAT_006bd3bc,param_1);
    if (DAT_0073d8d0 != 0) {
      FUN_00664e00(DAT_0073d8d0,0x6d6f7665,local_40,FUN_0054c9e0,0);
    }
    *(undefined4 *)(unaff_ESI + 0x53c) = *(undefined4 *)(unaff_ESI + 0x538);
    *(undefined4 *)(unaff_ESI + 0x538) = 0xe;
  }
  return;
}


// ==== 0x54ac00 FUN_0054ac00

void FUN_0054ac00(undefined4 param_1)

{
  int unaff_ESI;
  undefined1 local_40 [64];
  
  if (*(int *)(unaff_ESI + 0x68) != 0) {
    *(undefined4 *)(unaff_ESI + 0x540) = 7;
    *(undefined4 *)(unaff_ESI + 0x544) = param_1;
    local_40[0] = 0;
    FUN_00667950(local_40,0x40,&DAT_006bd3bc,&DAT_006b9172);
    if (DAT_0073d8d0 != 0) {
      FUN_00664e00(DAT_0073d8d0,0x6d6f7665,local_40,FUN_0054c9e0,0);
    }
    *(undefined4 *)(unaff_ESI + 0x53c) = *(undefined4 *)(unaff_ESI + 0x538);
    *(undefined4 *)(unaff_ESI + 0x538) = 0x10;
  }
  return;
}


// ==== 0x54ac80 FUN_0054ac80

void __thiscall FUN_0054ac80(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  undefined1 local_300 [256];
  undefined1 local_200 [512];
  
  *(undefined4 *)(in_EAX + 0x540) = 10;
  *(undefined4 *)(in_EAX + 0x544) = param_1;
  local_300[0] = 0;
  FUN_00667d70(local_300,0x100,"GAME=%d PARAMS=%s",DAT_0073dafc,&DAT_0073dcc0);
  local_200[0] = 0;
  FUN_00667d70(local_200,0x200,"PRIV=%s ATTR=%f TEXT=%s",param_2,0x8000020,local_300);
  if (DAT_0073d8d0 != 0) {
    FUN_00664e00(DAT_0073d8d0,0x6d657367,local_200,FUN_0054cac0,0);
  }
  return;
}


// ==== 0x54ad20 FUN_0054ad20

void __fastcall FUN_0054ad20(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *unaff_EDI;
  
  iVar3 = 0xc;
  pcVar2 = unaff_EDI;
  do {
    cVar1 = pcVar2[param_1 - (int)unaff_EDI];
    iVar3 = iVar3 + -1;
    *pcVar2 = cVar1;
    if (cVar1 == '\0') break;
    pcVar2 = pcVar2 + 1;
  } while (iVar3 != 0);
  *(uint *)(unaff_EDI + 100) = *(uint *)(unaff_EDI + 100) | 1;
  return;
}


// ==== 0x54ad50 FUN_0054ad50

void __fastcall FUN_0054ad50(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  undefined1 local_200 [512];
  
  if (*(int *)(in_EAX + 0x68) != 0) {
    *(undefined4 *)(in_EAX + 0x540) = 0x15;
    *(undefined4 *)(in_EAX + 0x544) = param_3;
    local_200[0] = 0;
    FUN_00667950(local_200,0x200,&DAT_006bd3c4,param_2);
    iVar1 = GetCountryCode();
    if (iVar1 != 0) {
      uVar2 = GetCountryCode();
      FUN_00667950(local_200,0x200,&DAT_006bd380,uVar2);
    }
    iVar1 = GetLanguageCode();
    if (iVar1 != 0) {
      uVar2 = GetLanguageCode();
      FUN_00667950(local_200,0x200,&DAT_006bd378,uVar2);
    }
    if (DAT_0073d8d0 != 0) {
      FUN_00664e00(DAT_0073d8d0,0x72657074,local_200,FUN_0054cbd0,0);
    }
  }
  return;
}


// ==== 0x54ae10 FUN_0054ae10

undefined4 FUN_0054ae10(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  undefined1 local_40 [64];
  
  if (*(int *)(unaff_ESI + 0x68) != 0) {
    if (*(int *)(unaff_ESI + 0x40) != 0) {
      FUN_00664c70(*(int *)(unaff_ESI + 0x68),6,*(int *)(unaff_ESI + 0x40));
      *(undefined4 *)(unaff_ESI + 0x40) = 0;
    }
    *(undefined4 *)(unaff_ESI + 0x54) = 0xffffffff;
    *(undefined1 *)(unaff_ESI + 0x58) = 0;
    *(undefined4 *)(unaff_ESI + 0x44) = 0;
    *(undefined4 *)(unaff_ESI + 0x48) = 0;
    *(undefined4 *)(unaff_ESI + 0x4c) = 0;
    *(undefined4 *)(unaff_ESI + 0x50) = 0;
    if ((0 < unaff_EDI) && (unaff_EDI < 0x24)) {
      iVar1 = FUN_00664c00(*(undefined4 *)(unaff_ESI + 0x68),6,FUN_0054c4c0,&DAT_0073d868);
      *(int *)(unaff_ESI + 0x40) = iVar1;
      if (iVar1 != 0) {
        FUN_00666f60(iVar1,0,0,FUN_0054bc40);
        *(undefined4 *)(unaff_ESI + 0x44) = param_1;
        *(undefined4 *)(unaff_ESI + 0x48) = param_2;
        *(int *)(unaff_ESI + 0x54) = unaff_EDI;
        local_40[0] = 0;
        FUN_00667690(local_40,0x40,"INDEX");
        FUN_00667690(local_40,0x40,&DAT_006bd368,6);
        FUN_00667690(local_40,0x40,"START",0);
        FUN_00667690(local_40,0x40,"RANGE",100);
        if (DAT_0073d8d0 != 0) {
          FUN_00664e00(DAT_0073d8d0,0x736e6170,local_40,FUN_0054c1f0,0);
        }
        FUN_00665660(*(undefined4 *)(unaff_ESI + 0x68));
        return 0;
      }
    }
  }
  return 0xffffffff;
}


// ==== 0x54af40 FUN_0054af40

void FUN_0054af40(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x68) != 0) {
    if (*(int *)(unaff_ESI + 0x40) != 0) {
      FUN_00664c70(*(int *)(unaff_ESI + 0x68),6,*(int *)(unaff_ESI + 0x40));
      *(undefined4 *)(unaff_ESI + 0x40) = 0;
    }
    *(undefined4 *)(unaff_ESI + 0x54) = 0xffffffff;
    *(undefined1 *)(unaff_ESI + 0x58) = 0;
    *(undefined4 *)(unaff_ESI + 0x44) = 0;
    *(undefined4 *)(unaff_ESI + 0x48) = 0;
    *(undefined4 *)(unaff_ESI + 0x4c) = 0;
    *(undefined4 *)(unaff_ESI + 0x50) = 0;
  }
  return;
}


// ==== 0x54af80 FUN_0054af80

void __thiscall FUN_0054af80(int param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined1 local_8 [8];
  
  if ((param_1 != 0) && (*(int *)(in_EAX + 0x68) != 0)) {
    *(int *)(in_EAX + 0x38) = param_1;
    *(undefined4 *)(in_EAX + 0x3c) = param_2;
    uVar5 = 0;
    iVar3 = GetLanguageCode();
    pcVar4 = "EN";
    do {
      cVar1 = pcVar4[iVar3 + -0x6c9af0];
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      if ((cVar1 == '\0') || (cVar2 == '\0')) break;
    } while (cVar1 == cVar2);
    if (cVar1 == cVar2) {
      uVar5 = 0;
    }
    else {
      iVar3 = bStrCmp();
      if (iVar3 == 0) {
        uVar5 = 1;
      }
      else {
        iVar3 = bStrCmp();
        if (iVar3 == 0) {
          uVar5 = 2;
        }
        else {
          iVar3 = bStrCmp();
          if (iVar3 == 0) {
            uVar5 = 3;
          }
          else {
            iVar3 = bStrCmp();
            if (iVar3 == 0) {
              uVar5 = 4;
            }
            else {
              iVar3 = bStrCmp();
              if (iVar3 == 0) {
                uVar5 = 5;
              }
              else {
                iVar3 = bStrCmp();
                if (iVar3 == 0) {
                  uVar5 = 6;
                }
                else {
                  iVar3 = bStrCmp();
                  if (iVar3 == 0) {
                    uVar5 = 7;
                  }
                  else {
                    iVar3 = bStrCmp();
                    if (iVar3 == 0) {
                      uVar5 = 8;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    FUN_00565da0("NAME=%d",uVar5);
    if (DAT_0073d8d0 != 0) {
      FUN_00664e00(DAT_0073d8d0,0x6e657773,local_8,FUN_0054c2f0,0);
    }
  }
  return;
}


// ==== 0x54b0e0 FUN_0054b0e0

void __fastcall FUN_0054b0e0(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  int unaff_ESI;
  undefined1 local_400 [1024];
  
  *(undefined4 *)(in_EAX + 0x540) = 0xc;
  *(undefined4 *)(in_EAX + 0x544) = param_1;
  local_400[0] = 0;
  FUN_00667950(local_400,0x400,&DAT_006bd350,param_2);
  if (unaff_ESI != 0) {
    FUN_00667950(local_400,0x400,&DAT_006bd348);
    FUN_00667750(local_400,0x400,&DAT_006bd340,0x20);
  }
  if (DAT_0073d8d0 != 0) {
    FUN_00664e00(DAT_0073d8d0,0x6d657367,local_400,FUN_0054cac0,0);
  }
  return;
}


// ==== 0x54b170 FUN_0054b170

void __fastcall FUN_0054b170(undefined4 param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  if ((param_2 != (char *)0x0) && (DAT_0073505d = *param_2, DAT_0073505d != '\0')) {
    pcVar2 = &DAT_0073505d;
    do {
      cVar1 = (param_2 + -0x73505c)[(int)pcVar2];
      pcVar2 = pcVar2 + 1;
      *pcVar2 = cVar1;
    } while (cVar1 != '\0');
  }
  return;
}


// ==== 0x54b1a0 FUN_0054b1a0

undefined4 __fastcall FUN_0054b1a0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (DAT_0073d8d0 == 0) {
    return 0xffffffff;
  }
  uVar1 = FUN_00664e00(DAT_0073d8d0,param_3,param_2,param_1,0);
  return uVar1;
}


// ==== 0x54b1c0 FUN_0054b1c0

void FUN_0054b1c0(void)

{
  int iVar1;
  undefined4 in_EAX;
  int iVar2;
  int iVar3;
  undefined4 extraout_ECX;
  
  DAT_00735e80 = in_EAX;
  if (*(int *)(DAT_0073578c + 8) != 0) {
    for (iVar1 = *(int *)(*(int *)(DAT_0073578c + 8) + 0xe4); iVar1 != 0;
        iVar1 = *(int *)(iVar1 + 4)) {
      iVar2 = FUN_00672970(*(undefined4 *)(iVar1 + 0x2c),"MU_Online");
      if (iVar2 != 0) {
        _strrchr(*(char **)(iVar1 + 0x2c),0x5c);
        iVar2 = DAT_0073578c;
        if (*(int *)(iVar1 + 0x30) == 0) {
          if (((DAT_0073578c != 0) && (iVar3 = FEPackageList__FindByName(&DAT_00746104), iVar3 != 0)
              ) && (*(int *)(iVar3 + 0x18) != 0)) {
            FUN_004f0800(*(undefined4 *)(iVar2 + 8),*(int *)(iVar3 + 0x18));
          }
        }
        else if (((DAT_0073578c != 0) &&
                 (iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0)) &&
                (*(int *)(iVar2 + 0x18) != 0)) {
          FUN_004f09b0(*(int *)(iVar2 + 0x18));
        }
      }
      iVar2 = FUN_00672970(*(undefined4 *)(iVar1 + 0x2c),"HELP_Generic.fng");
      if (((iVar2 != 0) &&
          (NullChunk__Loader("Send message[%x] to package [%s]\n",0x911ab364,"HELP_Generic.fng"),
          DAT_0073578c != 0)) &&
         ((*(int *)(DAT_0073578c + 8) != 0 &&
          ((iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0 &&
           (*(int *)(iVar2 + 0x18) != 0)))))) {
        NullChunk__Loader("Message was queued\n");
        FUN_004f0700(0x911ab364,0,extraout_ECX,0xffffffff,0);
      }
    }
  }
  FUN_0043a220(0);
  FUN_00549980();
  return;
}


// ==== 0x54b310 FUN_0054b310

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0054b310(void)

{
  int iVar1;
  
  if (DAT_0073d8d0 == 0) {
    return -1;
  }
  FUN_00664990(DAT_0073d8d0);
  iVar1 = FUN_00664ac0(DAT_0073d8d0,DAT_007346cc,DAT_006f1f60,FUN_0054c9a0,&DAT_0073d868);
  if (-1 < iVar1) {
    _DAT_0073dda4 = DAT_0073dda0;
    DAT_0073dda0 = 3;
    iVar1 = 0;
  }
  return iVar1;
}


// ==== 0x54b370 FUN_0054b370

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0054b370(void)

{
  int iVar1;
  int unaff_EBX;
  undefined4 *puVar2;
  undefined1 local_208;
  undefined4 local_207;
  
  if (*(int *)(unaff_EBX + 0x68) == 0) {
    return 0xffffffff;
  }
  local_208 = 0;
  puVar2 = &local_207;
  for (iVar1 = 0x7f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 2) = 0;
  FUN_0054de70(&DAT_007346f8);
  if (DAT_0073d8d0 != 0) {
    FUN_00664e00(DAT_0073d8d0,0x61757468,&local_208,FUN_0054c3c0,0);
  }
  FUN_00665660(*(undefined4 *)(unaff_EBX + 0x68));
  _DAT_0073dda4 = DAT_0073dda0;
  DAT_0073dda0 = 5;
  return 0;
}


// ==== 0x54b410 FUN_0054b410

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0054b410(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 *puVar3;
  undefined1 local_108;
  undefined4 local_107;
  
  if (*(int *)(unaff_ESI + 0x68) == 0) {
    return 0xffffffff;
  }
  puVar3 = &local_107;
  for (iVar2 = 0x3f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  local_108 = 0;
  FUN_00667950(&local_108,0x100,&DAT_006bd3bc,&DAT_007346d8);
  FUN_00667950(&local_108,0x100,&DAT_006bd3c4,&DAT_00734718);
  uVar1 = FUN_00662960();
  FUN_00667950(&local_108,0x100,&DAT_006bd330,uVar1);
  if (DAT_0073d8d0 != 0) {
    FUN_00664e00(DAT_0073d8d0,0x70657273,&local_108,FUN_0054c400,0);
  }
  FUN_00665660(*(undefined4 *)(unaff_ESI + 0x68));
  _DAT_0073dda4 = DAT_0073dda0;
  DAT_0073dda0 = 7;
  return 0;
}


// ==== 0x54b4e0 FUN_0054b4e0

undefined4 FUN_0054b4e0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined1 auStack_808 [8];
  undefined1 local_800 [2048];
  
  if (*(int *)(param_1 + 0x68) == 0) {
    return 0xffffffff;
  }
  iVar2 = 0;
  if (DAT_0073505d != '\0') {
    do {
      pcVar4 = &DAT_0073505e + iVar2;
      iVar2 = iVar2 + 1;
    } while (*pcVar4 != '\0');
    if (0 < iVar2) {
      local_800[0] = 0;
      FUN_00667950(local_800,0x800,&DAT_006bd328,&DAT_00734fd8);
      FUN_00667c40(local_800,0x800,&DAT_006bd320,DAT_00735018);
      FUN_00667950(local_800,0x800,&DAT_006bd318,&DAT_0073501c);
      iVar2 = 0;
      pcVar4 = &DAT_00735029;
      do {
        iVar3 = 0;
        if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) break;
        do {
          iVar1 = iVar3 + 1;
          iVar3 = iVar3 + 1;
        } while (pcVar4[iVar1] != '\0');
        if (iVar3 < 1) break;
        FUN_00565da0("NAME%d",iVar2);
        FUN_00667950(local_800,0x800,auStack_808,pcVar4);
        pcVar4 = pcVar4 + 0xd;
        iVar2 = iVar2 + 1;
      } while ((int)pcVar4 < 0x73505d);
      iVar2 = 0;
      if (DAT_0073505d != '\0') {
        do {
          pcVar4 = &DAT_0073505e + iVar2;
          iVar2 = iVar2 + 1;
        } while (*pcVar4 != '\0');
        if (0 < iVar2) {
          FUN_00667950(local_800,0x800,&DAT_006bd308,&DAT_0073505d);
        }
      }
      if (DAT_0073d8d0 != 0) {
        FUN_00664e00(DAT_0073d8d0,0x72616e6b,local_800,FUN_0054c440,0);
      }
      *(undefined4 *)(param_1 + 0x53c) = *(undefined4 *)(param_1 + 0x538);
      *(undefined4 *)(param_1 + 0x538) = 0xb;
      return 0;
    }
  }
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined1 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x53c) = *(undefined4 *)(param_1 + 0x538);
  *(undefined4 *)(param_1 + 0x538) = 0xc;
  return 0;
}


// ==== 0x54b690 FUN_0054b690

undefined4 FUN_0054b690(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x68) == 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(in_EAX + 0x78) = 0;
  *(undefined4 *)(in_EAX + 0x7c) = 0;
  *(undefined4 *)(in_EAX + 0x80) = 0;
  *(undefined1 *)(in_EAX + 0x84) = 0;
  *(undefined4 *)(in_EAX + 0x53c) = *(undefined4 *)(in_EAX + 0x538);
  *(undefined4 *)(in_EAX + 0x538) = 10;
  return 0;
}


// ==== 0x54b6d0 FUN_0054b6d0

undefined4 FUN_0054b6d0(void)

{
  int in_EAX;
  undefined4 uVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x68) == 0) {
    return 0;
  }
  if (in_EAX == -1) {
    in_EAX = *(int *)(unaff_ESI + 0x294);
  }
  uVar1 = FUN_00664d40(*(int *)(unaff_ESI + 0x68),5,in_EAX);
  uVar1 = FUN_00666ea0(*(undefined4 *)(unaff_ESI + 0x74),uVar1);
  return uVar1;
}


// ==== 0x54b700 FUN_0054b700

undefined4 FUN_0054b700(int param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  int iVar7;
  
  if (*(int *)(param_1 + 0x68) == 0) {
    return 0;
  }
  iVar7 = 0;
  do {
    if (*(int *)(param_1 + 0x68) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_0064c660(*(undefined4 *)(param_1 + 0x70));
    }
    if (iVar3 <= iVar7) {
      return 0;
    }
    if (*(int *)(param_1 + 0x68) == 0) {
LAB_0054b759:
      puVar6 = &DAT_006b9172;
    }
    else {
      iVar3 = FUN_00666f30(DAT_0073d8d8,iVar7);
      puVar6 = (undefined1 *)(iVar3 + 8);
      if (iVar3 == 0) goto LAB_0054b759;
    }
    pcVar4 = param_2;
    do {
      cVar1 = pcVar4[(int)puVar6 - (int)param_2];
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      if ((cVar1 == '\0') || (cVar2 == '\0')) break;
    } while (cVar1 == cVar2);
    if (cVar1 == cVar2) {
      uVar5 = FUN_00666f30(DAT_0073d8d8,iVar7);
      return uVar5;
    }
    iVar7 = iVar7 + 1;
  } while( true );
}


// ==== 0x54b7b0 FUN_0054b7b0

int FUN_0054b7b0(void)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0054b700(&DAT_0073d868,in_EAX);
  if (((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0x1f8), iVar1 != 0)) && (DAT_0073d8d0 != 0)) {
    if (iVar1 == -1) {
      iVar1 = DAT_0073dafc;
    }
    uVar2 = FUN_00664d40(DAT_0073d8d0,5,iVar1);
    iVar1 = FUN_00666ea0(DAT_0073d8dc,uVar2);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  return 0;
}


// ==== 0x54b800 FUN_0054b800

undefined4 FUN_0054b800(int param_1)

{
  char cVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *unaff_EBX;
  int iVar6;
  undefined **ppuVar7;
  
  iVar6 = 0;
  do {
    iVar3 = __stricmp(unaff_EBX,(&PTR_s_has_entered_the_room_006f3d5c)[iVar6]);
    if (iVar3 == 0) {
      if (iVar6 == 6) {
        *(undefined4 *)(in_EAX + 0x54c) = 3;
        return 1;
      }
      if (iVar6 != 7) {
        return 1;
      }
      *(undefined4 *)(in_EAX + 0x54c) = 4;
      return 1;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 8);
  ppuVar7 = &PTR_s_You_have_been_kicked_out_of_the_r_006f3d7c;
  do {
    pcVar5 = *ppuVar7;
    pcVar4 = pcVar5;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    iVar6 = __strnicmp(unaff_EBX,pcVar5,(int)pcVar4 - (int)(pcVar5 + 1));
    if ((iVar6 == 0) &&
       (iVar6 = _strchr(unaff_EBX + ((int)pcVar4 - (int)(pcVar5 + 1)),0x20), iVar6 == 0)) {
      return 1;
    }
    ppuVar7 = ppuVar7 + 1;
  } while ((int)ppuVar7 < 0x6f3d84);
  if (param_1 != 0) {
    pcVar5 = "Server";
    do {
      cVar1 = pcVar5[param_1 + -0x6bd300];
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      if ((cVar1 == '\0') || (cVar2 == '\0')) break;
    } while (cVar1 == cVar2);
    if (cVar1 == cVar2) {
      return 1;
    }
  }
  return 0;
}


// ==== 0x54b8e0 FUN_0054b8e0

void __fastcall FUN_0054b8e0(undefined4 param_1,int param_2,char param_3)

{
  int in_EAX;
  undefined1 local_80 [128];
  
  if (in_EAX != 0) {
    *(undefined4 *)(param_2 + 0x540) = 0xb;
    *(int *)(param_2 + 0x544) = in_EAX;
  }
  local_80[0] = 0;
  FUN_00667d70(local_80,0x80,"PRIV=%s ATTR=%f TEXT=%s",param_1,0x10000020,param_1);
  if (DAT_0073d8d0 != 0) {
    FUN_00664e00(DAT_0073d8d0,0x6d657367,local_80,FUN_0054cac0,0);
  }
  if (param_3 == '\x01') {
    DAT_0073d8cc = DAT_0073d8cc & 0xfffffffd;
    DAT_0073dd9c = 0xffffffff;
    DAT_0073d868 = 0;
  }
  return;
}


// ==== 0x54b980 FUN_0054b980

int FUN_0054b980(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  if (param_2 == 0) {
    return (*(uint *)(param_3 + 8) & 0x10000) - (*(uint *)(param_4 + 8) & 0x10000);
  }
  if (param_2 == 1) {
    iVar1 = bStrICmp();
    return iVar1;
  }
  if (param_2 == 2) {
    iVar1 = bStrICmp();
    return iVar1;
  }
  if (param_2 == 3) {
    lVar2 = _atoi((char *)(param_3 + 0x5c));
    lVar3 = _atoi((char *)(param_4 + 0x5c));
    return lVar2 - lVar3;
  }
  return 0;
}


// ==== 0x54ba10 FUN_0054ba10

int FUN_0054ba10(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined1 auStack_118 [44];
  int iStack_ec;
  int iStack_d0;
  int iStack_b4;
  int iStack_98;
  undefined1 auStack_8c [44];
  int iStack_60;
  int iStack_44;
  int iStack_28;
  int iStack_c;
  
  switch(param_2) {
  case 1:
    FUN_006682f0(param_3 + 0x38,auStack_118,0x8c,&DAT_006bd444);
    if (iStack_ec == 0) {
      iStack_ec = 100;
    }
    FUN_006682f0(param_4 + 0x38,auStack_8c,0x8c,&DAT_006bd444);
    iStack_c = iStack_60;
    break;
  case 2:
    FUN_006682f0(param_3 + 0x38,auStack_118,0x8c,&DAT_006bd444);
    if (iStack_d0 == 0) {
      iStack_d0 = 100;
    }
    FUN_006682f0(param_4 + 0x38,auStack_8c,0x8c,&DAT_006bd444);
    if (iStack_44 == 0) {
      iStack_44 = 100;
    }
    return iStack_44 - iStack_d0;
  case 3:
    FUN_006682f0(param_3 + 0x38,auStack_118,0x8c,&DAT_006bd444);
    if (iStack_98 == 0) {
      iStack_98 = 100;
    }
    FUN_006682f0(param_4 + 0x38,auStack_8c,0x8c,&DAT_006bd444);
    break;
  case 4:
    FUN_006682f0(param_3 + 0x38,auStack_118,0x8c,&DAT_006bd444);
    if (iStack_b4 == 0) {
      iStack_b4 = 100;
    }
    FUN_006682f0(param_4 + 0x38,auStack_8c,0x8c,&DAT_006bd444);
    if (iStack_28 == 0) {
      iStack_28 = 100;
    }
    return iStack_28 - iStack_b4;
  default:
    iVar1 = bStrICmp();
    return iVar1;
  }
  if (iStack_c == 0) {
    iStack_c = 100;
  }
  return iStack_c - iStack_ec;
}


// ==== 0x54bc20 FUN_0054bc20

void FUN_0054bc20(void)

{
  bStrICmp();
  return;
}


// ==== 0x54bc40 FUN_0054bc40

int FUN_0054bc40(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  return *param_4 - *param_3;
}


// ==== 0x54bc50 FUN_0054bc50

bool FUN_0054bc50(undefined4 param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  char cVar4;
  
  cVar4 = *(char *)(param_3 + 0xf8);
  bVar3 = 0;
  cVar2 = '\0';
  if (cVar4 != '\0') {
    bVar1 = cVar4 - 0x30;
    if (9 < bVar1) {
      bVar1 = cVar4 - 0x37;
    }
    cVar2 = bVar1 << 4;
    cVar4 = *(char *)(param_3 + 0xf9);
    if ((cVar4 != '\0') && (bVar3 = cVar4 - 0x30, 9 < bVar3)) {
      bVar3 = cVar4 - 0x37;
    }
  }
  cVar4 = GetNetModeCode();
  return (byte)(bVar3 + cVar2) == cVar4;
}


// ==== 0x54bca0 FUN_0054bca0

void FUN_0054bca0(int param_1)

{
  char cVar1;
  int *piVar2;
  char *in_EAX;
  int *piVar3;
  int *piVar4;
  
  piVar3 = (int *)FUN_00565b60(0x18,0,0,3);
  if (piVar3 != (int *)0x0) {
    cVar1 = *in_EAX;
    piVar2 = piVar3 + 2;
    *(char *)piVar2 = cVar1;
    if (cVar1 != '\0') {
      piVar4 = piVar2;
      do {
        cVar1 = (in_EAX + (1 - (int)piVar2))[(int)piVar4];
        piVar4 = (int *)((int)piVar4 + 1);
        *(char *)piVar4 = cVar1;
      } while (cVar1 != '\0');
    }
    piVar2 = *(int **)(param_1 + 0x288);
    *piVar2 = (int)piVar3;
    *(int **)(param_1 + 0x288) = piVar3;
    piVar3[1] = (int)piVar2;
    *piVar3 = param_1 + 0x284;
  }
  return;
}


// ==== 0x54bcf0 FUN_0054bcf0

undefined1 FUN_0054bcf0(int param_1)

{
  char cVar1;
  char cVar2;
  undefined1 uVar3;
  char *in_EAX;
  char *pcVar4;
  int *piVar5;
  int *piVar6;
  
  piVar5 = (int *)(param_1 + 0x284);
  piVar6 = (int *)*piVar5;
  uVar3 = 0;
  if (piVar6 == piVar5) {
    return 0;
  }
  do {
    pcVar4 = in_EAX;
    do {
      cVar1 = pcVar4[(int)piVar6 + (8 - (int)in_EAX)];
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      if ((cVar1 == '\0') || (cVar2 == '\0')) break;
    } while (cVar1 == cVar2);
    if (cVar1 == cVar2) {
      uVar3 = 1;
    }
    piVar6 = (int *)*piVar6;
    if (piVar6 == piVar5) {
      return uVar3;
    }
  } while( true );
}


// ==== 0x54bd60 FUN_0054bd60

undefined4 FUN_0054bd60(undefined4 param_1,undefined4 param_2,int *param_3)

{
  if (((param_3[0x92] & 0x80000U) == 0) &&
     (((param_3[0x95] != 2 || (DAT_0073dafc == *param_3)) || (DAT_0073dd9c == *param_3)))) {
    return 1;
  }
  return 0;
}


// ==== 0x54bda0 FUN_0054bda0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054bda0(undefined4 param_1,int param_2)

{
  if ((param_2 != 0) && (DAT_007346d4 != 0)) {
    if ((*(int *)(param_2 + 8) != DAT_0078ea90) || (*(int *)(param_2 + 4) != 0)) {
      _DAT_00706fcc = *(undefined4 *)(param_2 + 4);
      DAT_0078ea90 = *(int *)(param_2 + 8);
      FUN_00549500(_DAT_00706fcc);
      FUN_00549500(*(undefined4 *)(param_2 + 8));
    }
    if (*(int *)(param_2 + 8) != 0) {
      FUN_0054cfe0();
    }
    FUN_00665140(param_1,param_2);
  }
  return;
}


// ==== 0x54be20 FUN_0054be20

void FUN_0054be20(undefined4 param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  char *pcVar10;
  undefined4 local_6cc;
  undefined1 local_6c8 [64];
  undefined1 local_688;
  undefined4 local_687;
  char local_588;
  char local_587 [255];
  undefined1 local_488 [64];
  undefined1 local_448 [64];
  undefined1 local_408 [1028];
  
  if (param_2 == 0) {
    return;
  }
  local_688 = 0;
  puVar6 = &local_687;
  for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)puVar6 = 0;
  *(undefined1 *)((int)puVar6 + 2) = 0;
  local_588 = '\0';
  pcVar10 = local_587;
  for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {
    pcVar10[0] = '\0';
    pcVar10[1] = '\0';
    pcVar10[2] = '\0';
    pcVar10[3] = '\0';
    pcVar10 = pcVar10 + 4;
  }
  uVar3 = *(undefined4 *)(param_2 + 0xc);
  pcVar10[0] = '\0';
  pcVar10[1] = '\0';
  pcVar10[2] = '\0';
  local_6cc = 0;
  bVar9 = false;
  uVar3 = FUN_00667530(uVar3,&DAT_006bd2ec,local_6c8,0x40,&DAT_006b9172);
  FUN_00668130(uVar3);
  uVar3 = FUN_00667530(*(undefined4 *)(param_2 + 0xc),&DAT_006bd2e8,local_408,0x400,&DAT_006b9172);
  FUN_00668130(uVar3);
  iVar5 = *(int *)(param_2 + 4);
  if (iVar5 == 0x63617374) {
    pcVar10 = "%s: *broadcast* %s";
  }
  else {
    if (iVar5 != 0x63686174) {
      if (iVar5 == 0x70726976) {
        uVar1 = *(uint *)(param_2 + 8);
        if ((uVar1 & 0x8000000) == 0) {
          if ((uVar1 & 0x10000000) == 0) {
            FUN_00565da0("%s%s: %s",local_6c8,&local_688,local_408);
            local_6cc = 1;
          }
          else if ((uVar1 & 0x200000) == 0) {
            FEngQueueMessageToPackage();
          }
          goto LAB_0054c150;
        }
        if ((uVar1 & 0x200000) != 0) goto LAB_0054c150;
        uVar3 = FUN_00667530(local_408,&DAT_006bd2e0,0xffffffff);
        FUN_00667ec0(uVar3);
        iVar5 = FUN_0054b6d0();
        if ((iVar5 != 0) && (DAT_0073dafc == -1)) {
          if ((DAT_0073d8cc >> 1 & 1) != 0) {
            uVar3 = 0;
            goto LAB_0054bfc0;
          }
          iVar4 = FEngFindPackage();
          if ((((iVar4 != 0) && (iVar4 = FEngFindPackage(), iVar4 == 0)) &&
              (iVar4 = FEngFindPackage(), iVar4 == 0)) &&
             (((iVar4 = FEngFindPackage(), iVar4 == 0 && (iVar4 = FEngFindPackage(), iVar4 == 0)) &&
              ((iVar4 = FEngFindPackage(), iVar4 == 0 &&
               ((DAT_007301c8 == '\0' && (cVar2 = FUN_0054bcf0(&DAT_0073d868), cVar2 == '\0'))))))))
          {
            uVar3 = FUN_00667530(local_408,"PARAMS",local_448,0x40,&DAT_006b9172);
            FUN_00668130(uVar3);
            FUN_00667d70(local_488,0x40,"NAME=%s",iVar5 + 4);
            FUN_0054b1a0(0x67676574);
            goto LAB_0054c150;
          }
        }
        uVar3 = 1;
LAB_0054bfc0:
        FUN_0054b8e0(uVar3);
        return;
      }
      goto LAB_0054c150;
    }
    uVar1 = *(uint *)(param_2 + 8);
    bVar7 = (uVar1 & 0x100) != 0;
    if (bVar7) {
      bStrCat2(" (host)");
    }
    bVar8 = (uVar1 & 2) != 0;
    if (bVar8) {
      bStrCat2(" (admin)");
    }
    bVar9 = (uVar1 & 0x2000) != 0;
    if (bVar9) {
      bStrCat2(" (mod)");
    }
    bVar9 = bVar9 || (bVar8 || bVar7);
    if ((uVar1 & 0x8000000) == 0) {
      FUN_00565da0("%s%s: %s",local_6c8,&local_688,local_408);
      goto LAB_0054c150;
    }
    pcVar10 = "%s %s";
  }
  FUN_00565da0(pcVar10,local_6c8,local_408);
LAB_0054c150:
  cVar2 = FUN_0054b800(local_6c8);
  if ((cVar2 == '\0') && (iVar5 = 0, local_588 != '\0')) {
    do {
      pcVar10 = local_587 + iVar5;
      iVar5 = iVar5 + 1;
    } while (*pcVar10 != '\0');
    if (((0 < iVar5) && (DAT_0073d8c4 != (code *)0x0)) && (DAT_0073d8c8 != 0)) {
      (*DAT_0073d8c4)(DAT_0073d8c8,&local_588,local_6cc,bVar9,
                      *(uint *)(param_2 + 8) >> 0x15 & 0xffffff01);
    }
  }
  FUN_00665140(param_1,param_2);
  return;
}


// ==== 0x54c1f0 FUN_0054c1f0

void FUN_0054c1f0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((param_2 != 0) && (*(int *)(param_2 + 4) == 0x736e6170)) {
    FUN_0054cf80();
    if (DAT_0073d8ac != (code *)0x0) {
      if (*(int *)(param_2 + 8) == 0) {
        uVar1 = FUN_00667530(*(undefined4 *)(param_2 + 0xc),"INDEX",0xffffffff);
        iVar2 = FUN_00667ec0(uVar1);
        if ((iVar2 != -1) && (iVar2 == DAT_0073d8bc)) {
          uVar1 = FUN_00667530(*(undefined4 *)(param_2 + 0xc),"START",0);
          iVar2 = FUN_00667ec0(uVar1);
          uVar1 = FUN_00667530(*(undefined4 *)(param_2 + 0xc),"RANGE",0);
          iVar3 = FUN_00667ec0(uVar1);
          DAT_0073d8b4 = iVar3 - iVar2;
          DAT_0073d8b8 = DAT_0073d8b4;
          if (DAT_0073d8b4 == 0) {
            (*DAT_0073d8ac)(0,0,DAT_0073d8b0);
            FUN_0054af40();
            return;
          }
          DAT_0073d8c0 = 1;
          return;
        }
      }
      else {
        (*DAT_0073d8ac)(0,0,DAT_0073d8b0);
        FUN_0054af40();
      }
    }
  }
  return;
}


// ==== 0x54c2f0 FUN_0054c2f0

void FUN_0054c2f0(undefined4 param_1,int param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined1 *extraout_ECX;
  undefined1 *puVar3;
  undefined4 uVar4;
  
  pcVar1 = DAT_0073d8a0;
  if (((param_2 == 0) || (*(int *)(param_2 + 4) == 0x6e657773)) && (DAT_0073d8a0 != (code *)0x0)) {
    uVar4 = DAT_0073d8a4;
    if ((param_2 == 0) || (*(int *)(param_2 + 0xc) == 0)) {
      uVar2 = 0;
      puVar3 = &DAT_006b9172;
    }
    else {
      uVar2 = bStrLen(DAT_0073d8a4);
      puVar3 = extraout_ECX;
    }
    (*pcVar1)(puVar3,uVar2,uVar4);
    DAT_0073d8a0 = (code *)0x0;
    DAT_0073d8a4 = 0;
  }
  return;
}


// ==== 0x54c350 FUN_0054c350

void FUN_0054c350(undefined4 param_1,int param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined1 *extraout_ECX;
  undefined1 *puVar3;
  undefined4 uVar4;
  
  if (((param_2 != 0) && (*(int *)(param_2 + 4) == 0x75736572)) &&
     (FUN_0054cf80(), pcVar1 = DAT_0073d898, DAT_0073d898 != (code *)0x0)) {
    uVar4 = DAT_0073d89c;
    if (*(int *)(param_2 + 8) == 0) {
      uVar2 = bStrLen(DAT_0073d89c);
      puVar3 = extraout_ECX;
    }
    else {
      uVar2 = 0;
      puVar3 = &DAT_006b9172;
    }
    (*pcVar1)(puVar3,uVar2,uVar4);
    DAT_0073d898 = (code *)0x0;
    DAT_0073d89c = 0;
  }
  return;
}


// ==== 0x54c3c0 FUN_0054c3c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054c3c0(undefined4 param_1,int param_2)

{
  if ((param_2 != 0) && (*(int *)(param_2 + 4) == 0x61757468)) {
    FUN_0054cf80();
    if (*(int *)(param_2 + 8) == 0) {
      _DAT_0073dda4 = DAT_0073dda0;
      DAT_0073dda0 = 6;
    }
  }
  return;
}


// ==== 0x54c400 FUN_0054c400

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054c400(undefined4 param_1,int param_2)

{
  if ((param_2 != 0) && (*(int *)(param_2 + 4) == 0x70657273)) {
    FUN_0054cf80();
    if (*(int *)(param_2 + 8) == 0) {
      _DAT_0073dda4 = DAT_0073dda0;
      DAT_0073dda0 = 8;
    }
  }
  return;
}


// ==== 0x54c440 FUN_0054c440

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054c440(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((param_2 != 0) && (*(int *)(param_2 + 4) == 0x72616e6b)) {
    FUN_0054cf80();
    _DAT_0073dda4 = DAT_0073dda0;
    puVar2 = &DAT_00734fd8;
    for (iVar1 = 0x122; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    DAT_0073dda0 = 0xc;
  }
  return;
}


// ==== 0x54c480 FUN_0054c480

void FUN_0054c480(undefined4 param_1,int param_2)

{
  if ((param_2 != 0) && (*(int *)(param_2 + 4) == 0x67737461)) {
    FUN_0054cf80();
    if (DAT_0073ddac != (code *)0x0) {
      (*DAT_0073ddac)();
    }
    DAT_0073dda8 = 0;
    DAT_0073ddac = (code *)0x0;
  }
  return;
}


// ==== 0x54c4c0 FUN_0054c4c0

void FUN_0054c4c0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_0073d8c0 == '\x01') {
    if (DAT_0073d8b4 != 0) {
      if (DAT_0073d8d0 == 0) {
        iVar1 = 0;
      }
      else if (DAT_0073d8a8 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_0064c670(DAT_0073d8a8);
      }
      DAT_0073d8b4 = DAT_0073d8b8 - iVar1;
      if (DAT_0073d8ac != (code *)0x0) {
        if (DAT_0073d8d0 == 0) {
          uVar2 = 0;
        }
        else if (DAT_0073d8a8 == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = FUN_0064c670(DAT_0073d8a8);
        }
        (*DAT_0073d8ac)(uVar2,DAT_0073d8b8,DAT_0073d8b0);
      }
    }
    if ((DAT_0073d8b4 == 0) && (DAT_0073d8ac != (code *)0x0)) {
      if ((DAT_0073d8d0 == 0) || (DAT_0073d8a8 == 0)) {
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_0064c670(DAT_0073d8a8);
      }
      (*DAT_0073d8ac)(uVar2,DAT_0073d8b8,DAT_0073d8b0);
      DAT_0073d8b0 = 0;
      DAT_0073d8ac = (code *)0x0;
    }
  }
  return;
}


// ==== 0x54c5b0 FUN_0054c5b0

void FUN_0054c5b0(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    FUN_0054cf80();
    FUN_00549500(*(undefined4 *)(param_2 + 4));
    if (*(int *)(param_2 + 8) != 0) {
      FUN_0054cfe0();
    }
  }
  return;
}


// ==== 0x54c5f0 FUN_0054c5f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054c5f0(undefined4 param_1,int param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  byte bVar13;
  int iVar14;
  int iVar15;
  int iStack_40;
  char acStack_34 [52];
  
  iVar14 = 0;
  if (param_2 != 0) {
    FUN_0054cf80();
    DAT_0073dda8 = 0;
    DAT_0073ddac = 0;
    FUN_00549500(*(undefined4 *)(param_2 + 4));
    if ((DAT_0073dda0 == 0x14) && (*(int *)(param_2 + 4) == 0x706c6179)) {
      iVar5 = FUN_00664d80(param_1,0x706c6179);
      puVar7 = &DAT_00734fd8;
      for (iVar8 = 0x122; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      DAT_00734fd8._0_1_ = *(char *)(iVar5 + 0x260);
      iVar8 = iVar5 + 0x260;
      if ((char)DAT_00734fd8 != '\0') {
        pcVar10 = (char *)&DAT_00734fd8;
        do {
          cVar1 = *(char *)(iVar8 + 1);
          iVar8 = iVar8 + 1;
          pcVar10 = pcVar10 + 1;
          *pcVar10 = cVar1;
        } while (cVar1 != '\0');
      }
      DAT_00735018 = *(undefined4 *)(iVar5 + 0x25c);
      pcVar10 = (char *)(iVar5 + 0x24);
      DAT_0073501c = *pcVar10;
      if (DAT_0073501c != '\0') {
        pcVar11 = &DAT_0073501c;
        do {
          cVar1 = pcVar10[1];
          pcVar10 = pcVar10 + 1;
          pcVar11 = pcVar11 + 1;
          *pcVar11 = cVar1;
        } while (cVar1 != '\0');
      }
      DAT_006f1e08 = *(int *)(iVar5 + 0x24c) + -1;
      if (0 < *(int *)(iVar5 + 0x24c)) {
        pcVar11 = &DAT_00735029;
        pcVar10 = (char *)(iVar5 + 0x84);
        do {
          cVar1 = *pcVar10;
          *pcVar11 = cVar1;
          pcVar12 = pcVar11;
          pcVar9 = pcVar10;
          while (cVar1 != '\0') {
            cVar1 = pcVar9[1];
            pcVar9 = pcVar9 + 1;
            pcVar12 = pcVar12 + 1;
            *pcVar12 = cVar1;
          }
          iVar14 = iVar14 + 1;
          pcVar11 = pcVar11 + 0xd;
          pcVar10 = pcVar10 + 0x20;
        } while (iVar14 < *(int *)(iVar5 + 0x24c));
      }
      pcVar10 = (char *)(iVar5 + 0x24);
      iVar14 = (iVar5 + 0x44) - (int)pcVar10;
      do {
        cVar1 = pcVar10[iVar14];
        cVar2 = *pcVar10;
        pcVar10 = pcVar10 + 1;
        if ((cVar1 == '\0') || (cVar2 == '\0')) break;
      } while (cVar1 == cVar2);
      if (cVar1 != cVar2) {
        iVar14 = *(int *)(iVar5 + 0x24c);
        iVar8 = 0;
        iStack_40 = 0;
        if (0 < iVar14) {
          iVar15 = 0x60;
          do {
            pcVar10 = (char *)(iVar5 + 0x24);
            do {
              cVar3 = pcVar10[iVar15];
              cVar4 = *pcVar10;
              pcVar10 = pcVar10 + 1;
              if ((cVar3 == '\0') || (cVar4 == '\0')) break;
            } while (cVar3 == cVar4);
            if (cVar3 == cVar4) {
              iStack_40 = *(int *)(iVar5 + 0x1a4 + iVar8 * 4);
              break;
            }
            iVar8 = iVar8 + 1;
            iVar15 = iVar15 + 0x20;
          } while (iVar8 < iVar14);
        }
        iVar8 = 0;
        if (0 < iVar14) {
          iVar15 = 0x40;
LAB_0054c7b0:
          pcVar10 = (char *)(iVar5 + 0x44);
          do {
            cVar3 = pcVar10[iVar15];
            cVar4 = *pcVar10;
            pcVar10 = pcVar10 + 1;
            if ((cVar3 == '\0') || (cVar4 == '\0')) break;
          } while (cVar3 == cVar4);
          if (cVar3 != cVar4) goto code_r0x0054c7cf;
          pcVar10 = (char *)FUN_00662670(*(undefined4 *)(iVar5 + 0x1a4 + iVar8 * 4));
          s_0_0_0_0_006f1e10[0] = *pcVar10;
          if (s_0_0_0_0_006f1e10[0] != '\0') {
            pcVar11 = s_0_0_0_0_006f1e10;
            do {
              cVar3 = (pcVar10 + -0x6f1e0f)[(int)pcVar11];
              pcVar11 = pcVar11 + 1;
              *pcVar11 = cVar3;
            } while (cVar3 != '\0');
          }
          if ((*(int *)(iVar5 + 0x1a4 + iVar8 * 4) == iStack_40) && (DAT_00734fd4 != 0)) {
            pcVar10 = (char *)FUN_00662670(DAT_00734fd4);
            s_0_0_0_0_006f1e10[0] = *pcVar10;
            if (s_0_0_0_0_006f1e10[0] != '\0') {
              pcVar11 = s_0_0_0_0_006f1e10;
              do {
                cVar3 = (pcVar10 + -0x6f1e0f)[(int)pcVar11];
                pcVar11 = pcVar11 + 1;
                *pcVar11 = cVar3;
              } while (cVar3 != '\0');
            }
          }
        }
      }
LAB_0054c84b:
      pcVar10 = acStack_34;
      for (iVar14 = 0xd; iVar14 != 0; iVar14 = iVar14 + -1) {
        pcVar10[0] = '\0';
        pcVar10[1] = '\0';
        pcVar10[2] = '\0';
        pcVar10[3] = '\0';
        pcVar10 = pcVar10 + 4;
      }
      bVar13 = 0;
      if (0 < *(int *)(iVar5 + 0x24c)) {
        uVar6 = 0;
        do {
          pcVar10 = acStack_34 + uVar6 * 0xd;
          pcVar11 = (char *)(uVar6 * 0x20 + 0x84 + iVar5);
          cVar3 = *pcVar11;
          *pcVar10 = cVar3;
          while (cVar3 != '\0') {
            cVar3 = pcVar11[1];
            pcVar11 = pcVar11 + 1;
            pcVar10 = pcVar10 + 1;
            *pcVar10 = cVar3;
          }
          bVar13 = bVar13 + 1;
          uVar6 = (uint)bVar13;
        } while ((int)uVar6 < *(int *)(iVar5 + 0x24c));
      }
      FUN_0043d1f0(acStack_34);
      puVar7 = &DAT_0073d828;
      uVar6 = 0;
      do {
        puVar7[1] = 0xffffffff;
        *puVar7 = 0;
        puVar7[2] = 0;
        puVar7[3] = 0;
        puVar7[4] = 0;
        puVar7 = puVar7 + 5;
      } while ((int)puVar7 < 0x73d864);
      if ((cVar1 == cVar2) && (bVar13 = 0, 0 < *(int *)(iVar5 + 0x24c))) {
        do {
          pcVar10 = (char *)(iVar5 + 0x24);
          iVar14 = uVar6 * 0x20 - (int)pcVar10;
          do {
            cVar1 = pcVar10[iVar14 + 0x84 + iVar5];
            cVar2 = *pcVar10;
            pcVar10 = pcVar10 + 1;
            if ((cVar1 == '\0') || (cVar2 == '\0')) break;
          } while (cVar1 == cVar2);
          if (cVar1 != cVar2) {
            FUN_0054e3d0(*(undefined4 *)(iVar5 + 0x1a4 + uVar6 * 4),DAT_006f1f3c);
          }
          bVar13 = bVar13 + 1;
          uVar6 = (uint)bVar13;
        } while ((int)uVar6 < *(int *)(iVar5 + 0x24c));
      }
      _DAT_0073dda4 = DAT_0073dda0;
      DAT_0073dda0 = 0x15;
      DAT_00734fd0 = 1;
      if (DAT_0073ddb0 != (code *)0x0) {
        (*DAT_0073ddb0)(1);
        DAT_0073ddb0 = (code *)0x0;
      }
      DAT_0073d875 = 0;
      DAT_0073dd9c = 0xffffffff;
    }
  }
  return;
code_r0x0054c7cf:
  iVar8 = iVar8 + 1;
  iVar15 = iVar15 + 0x20;
  if (iVar14 <= iVar8) goto LAB_0054c84b;
  goto LAB_0054c7b0;
}


// ==== 0x54c9a0 FUN_0054c9a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054c9a0(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    FUN_0054cf80();
    if (*(int *)(param_2 + 8) == 0) {
      _DAT_0073dda4 = DAT_0073dda0;
      DAT_0073dda0 = 4;
    }
  }
  return;
}


// ==== 0x54c9e0 FUN_0054c9e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054c9e0(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  if ((param_2 != 0) &&
     ((*(int *)(param_2 + 4) == 0x6d6f7665 || (*(int *)(param_2 + 4) == 0x726f6f6d)))) {
    FUN_0054cf80();
    if (*(int *)(param_2 + 8) == 0) {
      iVar2 = FUN_00667530(*(undefined4 *)(param_2 + 0xc),"LIDENT");
      if (iVar2 == 0) {
        _DAT_0073dda4 = DAT_0073dda0;
        DAT_0073dda0 = 0xf;
        cVar1 = Obj_GetByte19();
        if (cVar1 == '\0') {
          FUN_00666f60(DAT_0073d8d8,0,0,FUN_0054ba10);
        }
        else {
          FUN_00666f60(DAT_0073d8d8,0,DAT_00777cb4 + 1,FUN_0054ba10);
        }
      }
      else {
        _DAT_0073dda4 = DAT_0073dda0;
        DAT_0073dda0 = 0x11;
      }
    }
    if (DAT_0073ddac != (code *)0x0) {
      (*DAT_0073ddac)();
    }
    DAT_0073dda8 = 0;
    DAT_0073ddac = (code *)0x0;
  }
  return;
}


// ==== 0x54cac0 FUN_0054cac0

void FUN_0054cac0(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    FUN_0054cf80();
    if (DAT_007346d4 != 0) {
      FUN_00549500(*(undefined4 *)(param_2 + 4));
      if (*(int *)(param_2 + 8) != 0) {
        FUN_0054cfe0();
      }
    }
    if (DAT_0073ddac != (code *)0x0) {
      (*DAT_0073ddac)();
    }
    DAT_0073dda8 = 0;
    DAT_0073ddac = (code *)0x0;
  }
  return;
}


// ==== 0x54cb30 FUN_0054cb30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054cb30(undefined4 param_1,int param_2)

{
  if ((param_2 != 0) &&
     ((*(int *)(param_2 + 4) == 0x67637265 || (*(int *)(param_2 + 4) == 0x676a6f69)))) {
    FUN_0054cf80();
    if (*(int *)(param_2 + 8) == 0) {
      FUN_006652f0(&DAT_0073dafc,*(undefined4 *)(param_2 + 0xc));
      _DAT_0073dda4 = DAT_0073dda0;
      DAT_0073dda0 = 0x14;
      if (*(int *)(param_2 + 4) != 0x676a6f69) {
        DAT_0073d875 = 0;
        DAT_0073dd9c = 0xffffffff;
      }
      DAT_0073ddb8 = 1;
      return;
    }
    if (DAT_0073ddac != (code *)0x0) {
      (*DAT_0073ddac)();
    }
    DAT_0073dda8 = 0;
    DAT_0073ddac = (code *)0x0;
  }
  return;
}


// ==== 0x54cbd0 FUN_0054cbd0

void FUN_0054cbd0(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    FUN_0054cf80();
    if (DAT_0073ddac != (code *)0x0) {
      (*DAT_0073ddac)();
    }
    DAT_0073dda8 = 0;
    DAT_0073ddac = (code *)0x0;
  }
  return;
}


// ==== 0x54cc10 FUN_0054cc10

void FUN_0054cc10(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  char acStack_a0 [32];
  undefined1 auStack_80 [64];
  undefined1 auStack_40 [32];
  undefined1 auStack_20 [32];
  
  if ((param_2 != 0) && (*(int *)(param_2 + 4) == 0x67676574)) {
    FUN_0054cf80();
    if (DAT_0073ddac != (code *)0x0) {
      (*DAT_0073ddac)();
    }
    DAT_0073dda8 = 0;
    DAT_0073ddac = (code *)0x0;
    FUN_00665140(param_1,param_2);
    if (*(int *)(param_2 + 8) != 0) {
      FUN_0054cfe0();
      return;
    }
    uVar1 = FUN_00667530(*(undefined4 *)(param_2 + 0xc),&DAT_006bd3bc,auStack_40,0x20,&DAT_006b9172)
    ;
    FUN_00668130(uVar1);
    uVar1 = FUN_00667530(*(undefined4 *)(param_2 + 0xc),&DAT_006bd28c,auStack_20,0x20,&DAT_006b9172)
    ;
    FUN_00668130(uVar1);
    uVar1 = FUN_00667530(*(undefined4 *)(param_2 + 0xc),"PARAMS",auStack_80,0x40,&DAT_006b9172);
    FUN_00668130(uVar1);
    iVar2 = RaceOptions_Get();
    uVar1 = FUN_00667530(auStack_80,"TRACK",acStack_a0,0x20,&DAT_006b9172);
    FUN_00668130(uVar1);
    lVar3 = _atoi(acStack_a0);
    *(long *)(iVar2 + 8) = lVar3;
    uVar1 = FUN_00667530(auStack_80,&DAT_006bd280,acStack_a0,0x20,&DAT_006b9172);
    FUN_00668130(uVar1);
    lVar3 = _atoi(acStack_a0);
    *(long *)(iVar2 + 0xc) = lVar3;
    uVar1 = FUN_00667530(auStack_80,&DAT_006bd278,acStack_a0,0x20,&DAT_006b9172);
    FUN_00668130(uVar1);
    lVar3 = _atoi(acStack_a0);
    *(long *)(iVar2 + 0x10) = lVar3;
    DAT_00734fd4 = 0;
    uVar1 = FUN_00667530(auStack_80,&DAT_006bd270,acStack_a0,0x20,&DAT_006b9172);
    FUN_00668130(uVar1);
    DAT_00734fd4 = _atoi(acStack_a0);
    if (DAT_00777b54 == 0) {
      bStrCpy();
      bStrCpy();
      DAT_0073d8cc = DAT_0073d8cc | 2;
      uVar1 = FUN_00667530(*(undefined4 *)(param_2 + 0xc),"IDENT",0xffffffff);
      DAT_0073dd9c = FUN_00667ec0(uVar1);
      FUN_00666f90(DAT_0073d8dc,0,0,FUN_0054bd60);
      FEngQueueMessageToPackage();
    }
  }
  return;
}


// ==== 0x54ce70 FUN_0054ce70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054ce70(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_2 != 0) {
    FUN_0054cf80();
    if (DAT_007346d4 != 0) {
      FUN_00665140(param_1,param_2);
    }
    DAT_0073ddb0 = 0;
    if (DAT_0073ddac != (code *)0x0) {
      (*DAT_0073ddac)();
    }
    DAT_0073dda8 = 0;
    DAT_0073ddac = (code *)0x0;
    if (*(int *)(param_2 + 8) != 0) {
      FUN_0054cfe0();
      return;
    }
    DAT_0073dd9c = 0xffffffff;
    DAT_0073d875 = 0;
    DAT_0073d868 = 0;
    DAT_0073dda8 = 0;
    DAT_0073ddac = (code *)0x0;
    DAT_0073ddb0 = 0;
    DAT_0073ddb8 = 0;
    DAT_0073d8cc = 0;
    puVar2 = &DAT_0073dafc;
    for (iVar1 = 0xa8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    DAT_0073dafc = 0xffffffff;
    _DAT_0073dda4 = DAT_0073dda0;
    DAT_0073dda0 = 0xd;
  }
  return;
}


// ==== 0x54cf40 FUN_0054cf40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054cf40(undefined4 param_1,int param_2)

{
  if ((param_2 != 0) && (*(int *)(param_2 + 4) == 0x61757869)) {
    FUN_0054cf80();
    if (*(int *)(param_2 + 8) == 0) {
      _DAT_0073dda4 = DAT_0073dda0;
      DAT_0073dda0 = 10;
    }
  }
  return;
}


// ==== 0x54cf80 FUN_0054cf80

void __fastcall FUN_0054cf80(int param_1,undefined4 *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  pcVar2 = (char *)(param_1 + 0x84);
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *pcVar2 = '\0';
  if (param_2 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x78) = param_2[2];
    *(undefined4 *)(param_1 + 0x7c) = param_2[1];
    *(undefined4 *)(param_1 + 0x80) = *param_2;
    if (param_2[3] != 0) {
      iVar3 = 0x200;
      iVar4 = param_2[3] - (int)pcVar2;
      do {
        cVar1 = pcVar2[iVar4];
        iVar3 = iVar3 + -1;
        *pcVar2 = cVar1;
        if (cVar1 == '\0') {
          return;
        }
        pcVar2 = pcVar2 + 1;
      } while (iVar3 != 0);
    }
  }
  return;
}


// ==== 0x54cfe0 FUN_0054cfe0

void FUN_0054cfe0(void)

{
  int iVar1;
  char *pcVar2;
  int unaff_EDI;
  
  FUN_00549500();
  if (s_tsmiInvalid_master_account_name_006f2f38._0_4_ != -1) {
    pcVar2 = s_tsmiInvalid_master_account_name_006f2f38;
    iVar1 = s_tsmiInvalid_master_account_name_006f2f38._0_4_;
    do {
      if (iVar1 == unaff_EDI) {
        return;
      }
      iVar1 = *(int *)(pcVar2 + 0x2c);
      pcVar2 = pcVar2 + 0x2c;
    } while (iVar1 != -1);
  }
  return;
}


// ==== 0x54d020 FUN_0054d020

void FUN_0054d020(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  FUN_0054cf80();
  iVar1 = FUN_0064c660(*(undefined4 *)(param_3 + 0x6c));
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = FUN_00666f30(*(undefined4 *)(param_3 + 0x6c),iVar3);
      if (*(int *)(iVar2 + 0x10) < *(int *)(iVar2 + 0xc)) {
        pcVar4 = "%3s %3s %-12s %12s";
      }
      else {
        pcVar4 = "%2s# %3s %-12s %12s";
      }
      FUN_00565da0(pcVar4,iVar2 + 0x14,iVar2 + 0x18,iVar2 + 0x1c,iVar2 + 0x3c);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return;
}


// ==== 0x54d0b0 FUN_0054d0b0

void FUN_0054d0b0(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  undefined4 *puVar10;
  undefined1 auStack_490 [4];
  char acStack_48c [4];
  char acStack_488 [1020];
  undefined1 auStack_8c [140];
  
  FUN_0054cf80();
  if (DAT_007346d4 != 0) {
    uVar2 = *(undefined4 *)(param_2 + 0xc);
    iVar8 = 0;
    auStack_490 = (undefined1  [4])FUN_0064c660(uVar2);
    if (0 < (int)auStack_490) {
      do {
        iVar6 = FUN_00666f30(uVar2,iVar8);
        pcVar7 = (char *)(iVar6 + 8);
        iVar4 = -(int)pcVar7;
        do {
          cVar1 = *pcVar7;
          pcVar7[(int)(acStack_48c + iVar4)] = cVar1;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        uVar3 = *(uint *)(iVar6 + 4);
        if ((uVar3 & 0x100) != 0) {
          pcVar7 = auStack_490 + 3;
          do {
            pcVar9 = pcVar7;
            pcVar7 = pcVar9 + 1;
          } while (pcVar9[1] != '\0');
          builtin_strncpy(pcVar9 + 1," (host)",8);
        }
        if ((uVar3 & 0x400000) != 0) {
          puVar5 = (undefined4 *)(auStack_490 + 3);
          do {
            puVar10 = puVar5;
            puVar5 = (undefined4 *)((int)puVar10 + 1);
          } while (*(char *)((int)puVar10 + 1) != '\0');
          *(undefined4 *)((int)puVar10 + 1) = 0x69762820;
          *(undefined4 *)((int)puVar10 + 5) = 0x296563;
        }
        if ((uVar3 & 2) != 0) {
          pcVar7 = auStack_490 + 3;
          do {
            pcVar9 = pcVar7;
            pcVar7 = pcVar9 + 1;
          } while (pcVar9[1] != '\0');
          builtin_strncpy(pcVar9 + 1," (admin)",9);
        }
        if ((uVar3 & 0x2000) != 0) {
          pcVar7 = auStack_490 + 3;
          do {
            pcVar9 = pcVar7;
            pcVar7 = pcVar9 + 1;
          } while (pcVar9[1] != '\0');
          builtin_strncpy(pcVar9 + 1," (mod)",7);
        }
        if ((uVar3 & 0x200000) != 0) {
          puVar5 = (undefined4 *)(auStack_490 + 3);
          do {
            puVar10 = puVar5;
            puVar5 = (undefined4 *)((int)puVar10 + 1);
          } while (*(char *)((int)puVar10 + 1) != '\0');
          *(undefined4 *)((int)puVar10 + 1) = 0x656d2820;
          *(undefined2 *)((int)puVar10 + 5) = 0x29;
        }
        if ((uVar3 & 8) != 0) {
          pcVar7 = auStack_490 + 3;
          do {
            pcVar9 = pcVar7;
            pcVar7 = pcVar9 + 1;
          } while (pcVar9[1] != '\0');
          builtin_strncpy(pcVar9 + 1," (online)",10);
        }
        if ((char)uVar3 < '\0') {
          pcVar7 = auStack_490 + 3;
          do {
            pcVar9 = pcVar7;
            pcVar7 = pcVar9 + 1;
          } while (pcVar9[1] != '\0');
          builtin_strncpy(pcVar9 + 1," (gaming)",10);
        }
        if ((uVar3 & 0x8000000) != 0) {
          puVar5 = (undefined4 *)(auStack_490 + 3);
          do {
            puVar10 = puVar5;
            puVar5 = (undefined4 *)((int)puVar10 + 1);
          } while (*(char *)((int)puVar10 + 1) != '\0');
          *(undefined4 *)((int)puVar10 + 1) = 0x29302820;
          *(undefined1 *)((int)puVar10 + 5) = 0;
        }
        if ((uVar3 & 0x10000000) != 0) {
          puVar5 = (undefined4 *)(auStack_490 + 3);
          do {
            puVar10 = puVar5;
            puVar5 = (undefined4 *)((int)puVar10 + 1);
          } while (*(char *)((int)puVar10 + 1) != '\0');
          *(undefined4 *)((int)puVar10 + 1) = 0x29312820;
          *(undefined1 *)((int)puVar10 + 5) = 0;
        }
        if ((uVar3 & 0x20000000) != 0) {
          puVar5 = (undefined4 *)(auStack_490 + 3);
          do {
            puVar10 = puVar5;
            puVar5 = (undefined4 *)((int)puVar10 + 1);
          } while (*(char *)((int)puVar10 + 1) != '\0');
          *(undefined4 *)((int)puVar10 + 1) = 0x29322820;
          *(undefined1 *)((int)puVar10 + 5) = 0;
        }
        if ((uVar3 & 0x40000000) != 0) {
          puVar5 = (undefined4 *)(auStack_490 + 3);
          do {
            puVar10 = puVar5;
            puVar5 = (undefined4 *)((int)puVar10 + 1);
          } while (*(char *)((int)puVar10 + 1) != '\0');
          *(undefined4 *)((int)puVar10 + 1) = 0x29332820;
          *(undefined1 *)((int)puVar10 + 5) = 0;
        }
        FUN_006682f0(iVar6 + 0x38,auStack_8c,0x8c,&DAT_006bd444);
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)auStack_490);
    }
  }
  return;
}


// ==== 0x54d320 FUN_0054d320

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054d320(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_2 != 0) {
    FUN_0054cf80();
    if (DAT_0073dafc != -1) {
      if (DAT_0073d8d0 != 0) {
        uVar1 = FUN_00664d40(DAT_0073d8d0,5,DAT_0073dafc);
        puVar2 = (undefined4 *)FUN_00666ea0(DAT_0073d8dc,uVar1);
        if (puVar2 != (undefined4 *)0x0) {
          uVar1 = FUN_00667530(*(undefined4 *)(param_2 + 0xc),"IDENT",0xffffffff);
          iVar3 = FUN_00667ec0(uVar1);
          if (iVar3 == DAT_0073dafc) {
            puVar4 = &DAT_0073dafc;
            for (iVar3 = 0xa8; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar4 = *puVar2;
              puVar2 = puVar2 + 1;
              puVar4 = puVar4 + 1;
            }
          }
          if (DAT_0073ddb8 != '\x01') {
            return;
          }
          if (DAT_0073dda8 == 0) {
            return;
          }
          DAT_0073ddb8 = 0;
          FUN_0054d470();
          return;
        }
      }
      if (DAT_0073ddb0 != (code *)0x0) {
        (*DAT_0073ddb0)(0);
      }
      DAT_0073d875 = 0;
      DAT_0073d868 = 0;
      DAT_0073dda8 = 0;
      DAT_0073ddac = 0;
      DAT_0073ddb0 = (code *)0x0;
      DAT_0073ddb8 = 0;
      DAT_0073d8cc = 0;
      DAT_0073dd9c = 0xffffffff;
      puVar2 = &DAT_0073dafc;
      for (iVar3 = 0xa8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
      DAT_0073dafc = 0xffffffff;
      _DAT_0073dda4 = DAT_0073dda0;
      DAT_0073dda0 = 0xd;
      return;
    }
    if ((DAT_0073dd9c != -1) && (iVar3 = FUN_0054b6d0(), iVar3 == 0)) {
      FUN_0054aa30(&DAT_0073d868);
    }
  }
  return;
}


// ==== 0x54d470 FUN_0054d470

undefined4 FUN_0054d470(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  if (*(code **)(unaff_ESI + 0x544) != (code *)0x0) {
    (**(code **)(unaff_ESI + 0x544))();
  }
  uVar1 = *(undefined4 *)(unaff_ESI + 0x544);
  *(undefined4 *)(unaff_ESI + 0x540) = 0;
  *(undefined4 *)(unaff_ESI + 0x544) = 0;
  return uVar1;
}


// ==== 0x54d4a0 FUN_0054d4a0

void FUN_0054d4a0(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    FUN_00565da0("%c%c%c%c",param_2 >> 0x18,(int)(char)((uint)param_2 >> 0x10),
                 (int)(char)((uint)param_2 >> 8),(int)(char)param_2);
  }
  return;
}


// ==== 0x54d4e0 FUN_0054d4e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0054d4e0(void)

{
  undefined4 uVar1;
  undefined4 in_EAX;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_208;
  undefined4 local_207;
  
  local_208 = 0;
  puVar3 = &local_207;
  for (iVar2 = 0x7f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  _DAT_00734fcc = in_EAX;
  FUN_0054dd30(0x200);
  DAT_00734f80 = FUN_006655c0(&local_208,0,0);
  iVar2 = FUN_00668c50(s_ps2nfs04_ea_com_006f1f40,10000);
  uVar1 = DAT_006f1f60;
  if (iVar2 == 0) {
    return 0;
  }
  FUN_00664aa0(DAT_00734f80,3,FUN_0054dc10,0);
  FUN_00664ac0(DAT_00734f80,iVar2,uVar1,FUN_0054dc10,0);
  return 1;
}


// ==== 0x54d590 FUN_0054d590

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054d590(void)

{
  undefined1 *puVar1;
  
  if (DAT_00734f80 != 0) {
    FUN_00664a40(DAT_00734f80);
    DAT_00734f80 = 0;
  }
  DAT_00734f84 = 0;
  DAT_00734f88 = 0;
  DAT_00734f8c = 0;
  DAT_00734fc4 = 0;
  DAT_00734fc8 = 0;
  _DAT_00734fcc = 0;
  puVar1 = &DAT_00734f90;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 0xd;
  } while ((int)puVar1 < 0x734fc4);
  return;
}


// ==== 0x54d5f0 FUN_0054d5f0

int FUN_0054d5f0(void)

{
  char cVar1;
  char *in_EAX;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 1;
  if (*in_EAX == '-') {
    iVar2 = -1;
    in_EAX = in_EAX + 1;
  }
  cVar1 = *in_EAX;
  while (((cVar1 != '\0' && ('/' < cVar1)) && (cVar1 < ':'))) {
    in_EAX = in_EAX + 1;
    iVar3 = cVar1 + -0x30 + iVar3 * 10;
    cVar1 = *in_EAX;
  }
  return iVar2 * iVar3;
}


// ==== 0x54d630 FUN_0054d630

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054d630(void)

{
  int iVar1;
  
  if ((DAT_00734f80 != 0) && (DAT_00734f88 == 0)) {
    FUN_00665660(DAT_00734f80);
    if (DAT_00734f80 != 0) {
      iVar1 = FUN_00665120(DAT_00734f80);
      if (iVar1 == 0x400) {
        DAT_00734f88 = 2;
        DAT_00734f8c = 0;
        iVar1 = FUN_00664d80(DAT_00734f80,0x646f776e);
        if (iVar1 != 0) {
          iVar1 = bStrLen();
          if (0 < iVar1) {
            DAT_00734f8c = FUN_0054d5f0();
          }
        }
                    /* WARNING: Could not recover jumptable at 0x0054d6a7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*_DAT_00734fcc)();
        return;
      }
    }
  }
  return;
}


// ==== 0x54d6b0 FUN_0054d6b0

void __fastcall
FUN_0054d6b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int param_6,undefined4 param_7,char param_8,char param_9,
            char param_10,undefined4 param_11)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_420;
  undefined1 local_41f;
  undefined1 local_41c;
  undefined2 local_41b;
  undefined1 local_418;
  undefined4 local_417;
  undefined4 local_413;
  undefined4 local_40f;
  undefined2 local_40b;
  undefined1 local_409;
  undefined1 local_408;
  undefined4 local_407;
  
  local_417 = 0;
  local_413 = 0;
  local_40f = 0;
  local_40b = 0;
  local_409 = 0;
  local_418 = 0;
  FUN_00565da0("%04d%02d%02d",param_7,param_2,param_1);
  local_420 = 0;
  local_41f = 0;
  FUN_00565da0(&DAT_006c7408,(int)(char)(((param_8 == '\0') - 1U & 7) + 0x46));
  local_41c = 0;
  local_41b = 0;
  FUN_00565da0(&DAT_006bd1d4,(int)(char)(((param_9 == '\0') - 1U & 0xb) + 0x4e),
               (int)(char)(((param_10 == '\0') - 1U & 0xb) + 0x4e));
  puVar3 = &local_407;
  for (iVar2 = 0xff; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  local_408 = 0;
  FUN_00667950(&local_408,0x400,&DAT_006bd3bc,param_3);
  FUN_00667950(&local_408,0x400,&DAT_006bd1cc,param_4);
  FUN_00667950(&local_408,0x400,&DAT_006bd1c4,param_5);
  FUN_00667950(&local_408,0x400,&DAT_006bd1bc,&local_418);
  FUN_00667950(&local_408,0x400,&DAT_006bd1b4,&local_420);
  FUN_00667950(&local_408,0x400,&DAT_006bd1ac,&local_41c);
  iVar2 = GetCountryCode();
  if (iVar2 != 0) {
    uVar1 = GetCountryCode();
    FUN_00667950(&local_408,0x400,&DAT_006bd380,uVar1);
  }
  iVar2 = GetLanguageCode();
  if (iVar2 != 0) {
    uVar1 = GetLanguageCode();
    FUN_00667950(&local_408,0x400,&DAT_006bd378,uVar1);
  }
  if (param_6 != 0) {
    FUN_00667950(&local_408,0x400,"PMAIL",param_6);
  }
  FUN_0054df00(&local_408,0x400);
  FUN_00664e00(DAT_00734f80,0x61636374,&local_408,FUN_0054dc50,0);
  DAT_00734fc8 = param_11;
  return;
}


// ==== 0x54d8b0 FUN_0054d8b0

void FUN_0054d8b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_208;
  undefined4 local_207;
  
  local_208 = 0;
  puVar2 = &local_207;
  for (iVar1 = 0x7f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 2) = 0;
  FUN_0054de70(param_2);
  FUN_00664e00(DAT_00734f80,0x61757468,&local_208,FUN_0054dc70,0);
  DAT_00734fc8 = param_3;
  return;
}


// ==== 0x54d920 FUN_0054d920

void FUN_0054d920(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_88;
  undefined4 local_87;
  
  puVar2 = &local_87;
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 2) = 0;
  local_88 = 0;
  FUN_00667950(&local_88,0x80,&DAT_006bd3c4,param_1);
  FUN_00664e00(DAT_00734f80,0x63706572,&local_88,FUN_0054dc50,0);
  DAT_00734fc8 = param_2;
  return;
}


// ==== 0x54d990 FUN_0054d990

void FUN_0054d990(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_88;
  undefined4 local_87;
  
  puVar2 = &local_87;
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 2) = 0;
  local_88 = 0;
  FUN_00667950(&local_88,0x80,&DAT_006bd3c4,param_1);
  FUN_00664e00(DAT_00734f80,0x64706572,&local_88,FUN_0054dc50,0);
  DAT_00734fc8 = param_2;
  return;
}


// ==== 0x54da00 FUN_0054da00

void FUN_0054da00(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_108;
  undefined4 local_107;
  
  puVar3 = &local_107;
  for (iVar2 = 0x3f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  local_108 = 0;
  FUN_00667950(&local_108,0x100,&DAT_006bd3c4,param_1);
  uVar1 = FUN_00662960();
  FUN_00667950(&local_108,0x100,&DAT_006bd330,uVar1);
  FUN_00664e00(DAT_00734f80,0x70657273,&local_108,FUN_0054dce0,0);
  DAT_00734fc8 = param_2;
  return;
}


// ==== 0x54da90 FUN_0054da90

void FUN_0054da90(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_208;
  undefined4 local_207;
  
  puVar3 = &local_207;
  for (iVar2 = 0x7f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  local_208 = 0;
  FUN_00667950(&local_208,0x200,&DAT_006bd3bc,param_1);
  iVar2 = GetCountryCode();
  if (iVar2 != 0) {
    uVar1 = GetCountryCode();
    FUN_00667950(&local_208,0x200,&DAT_006bd380,uVar1);
  }
  iVar2 = GetLanguageCode();
  if (iVar2 != 0) {
    uVar1 = GetLanguageCode();
    FUN_00667950(&local_208,0x200,&DAT_006bd378,uVar1);
  }
  FUN_00664e00(DAT_00734f80,0x6c6f7374,&local_208,FUN_0054dc50,0);
  DAT_00734fc8 = param_2;
  return;
}


// ==== 0x54db50 FUN_0054db50

void FUN_0054db50(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_208;
  undefined4 local_207;
  
  puVar3 = &local_207;
  for (iVar2 = 0x7f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  local_208 = 0;
  FUN_00667950(&local_208,0x200,&DAT_006bd1c4,param_1);
  iVar2 = GetCountryCode();
  if (iVar2 != 0) {
    uVar1 = GetCountryCode();
    FUN_00667950(&local_208,0x200,&DAT_006bd380,uVar1);
  }
  iVar2 = GetLanguageCode();
  if (iVar2 != 0) {
    uVar1 = GetLanguageCode();
    FUN_00667950(&local_208,0x200,&DAT_006bd378,uVar1);
  }
  FUN_00664e00(DAT_00734f80,0x6c6f7374,&local_208,FUN_0054dc50,0);
  DAT_00734fc8 = param_2;
  return;
}


// ==== 0x54dc10 FUN_0054dc10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054dc10(undefined4 param_1,int param_2)

{
  DAT_00734f84 = *(int *)(param_2 + 8);
  if (DAT_00734f84 == 0) {
    DAT_00734fc4 = 1;
  }
  if (*(int *)(param_2 + 4) == 0x64697363) {
    FUN_00664990(param_1);
    DAT_00734f88 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x0054dc4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00734fcc)();
  return;
}


// ==== 0x54dc50 FUN_0054dc50

void FUN_0054dc50(undefined4 param_1,int param_2)

{
  DAT_00734f84 = *(undefined4 *)(param_2 + 8);
  (*DAT_00734fc8)();
  DAT_00734fc8 = (code *)0x0;
  return;
}


// ==== 0x54dc70 FUN_0054dc70

void FUN_0054dc70(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  
  DAT_00734f84 = *(int *)(param_2 + 8);
  if (DAT_00734f84 == 0) {
    DAT_00734fc4 = 2;
    iVar4 = 0;
    puVar3 = &DAT_00734f90;
    do {
      uVar1 = FUN_00667530(*(undefined4 *)(param_2 + 0xc),"PERSONAS",puVar3,0xd,&DAT_006b9172,iVar4,
                           0x2c);
      iVar2 = FUN_00667fa0(uVar1);
      if (iVar2 < 1) break;
      puVar3 = puVar3 + 0xd;
      iVar4 = iVar4 + 1;
    } while ((int)puVar3 < 0x734fc4);
  }
  (*DAT_00734fc8)();
  DAT_00734fc8 = (code *)0x0;
  return;
}


// ==== 0x54dce0 FUN_0054dce0

void FUN_0054dce0(undefined4 param_1,int param_2)

{
  DAT_00734f84 = *(int *)(param_2 + 8);
  if (DAT_00734f84 == 0) {
    DAT_00734fc4 = 3;
  }
  (*DAT_00734fc8)();
  DAT_00734fc8 = (code *)0x0;
  return;
}


// ==== 0x54dd10 FUN_0054dd10

void __fastcall FUN_0054dd10(undefined4 param_1,char *param_2)

{
  char cVar1;
  int in_EAX;
  char *pcVar2;
  char *pcVar3;
  
  cVar1 = *param_2;
  pcVar2 = &DAT_00734f90 + in_EAX * 0xd;
  *pcVar2 = cVar1;
  if (cVar1 != '\0') {
    pcVar3 = pcVar2;
    do {
      cVar1 = pcVar3[(int)(param_2 + (1 - (int)pcVar2))];
      pcVar3 = pcVar3 + 1;
      *pcVar3 = cVar1;
    } while (cVar1 != '\0');
  }
  return;
}


// ==== 0x54dd30 FUN_0054dd30

void FUN_0054dd30(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *unaff_EBX;
  undefined4 *puVar3;
  undefined4 uStack_107;
  
  *unaff_EBX = 0;
  FUN_0054df00();
  iVar2 = GetCountryCode();
  if (iVar2 != 0) {
    GetCountryCode();
    FUN_00667950();
  }
  iVar2 = GetLanguageCode();
  if (iVar2 != 0) {
    GetLanguageCode();
    FUN_00667950();
  }
  switch(DAT_00734998) {
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
    goto switchD_0054dda0_default;
  }
  bStrCpy();
switchD_0054dda0_default:
  FUN_00667950();
  puVar3 = &uStack_107;
  for (iVar2 = 0x3f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  FUN_00565da0(&DAT_006ca778,DAT_00734994);
  FUN_00667950();
  uVar1 = GetNetModeCode();
  FUN_00565da0(&DAT_006ca778,uVar1);
  FUN_00667950();
  return;
}


// ==== 0x54de70 FUN_0054de70

void FUN_0054de70(void)

{
  int iVar1;
  undefined1 *unaff_ESI;
  
  *unaff_ESI = 0;
  FUN_00667950();
  FUN_00667950();
  FUN_00667690();
  FUN_00662960();
  FUN_00667950();
  iVar1 = GetCountryCode();
  if (iVar1 != 0) {
    GetCountryCode();
    FUN_00667950();
  }
  iVar1 = GetLanguageCode();
  if (iVar1 != 0) {
    GetLanguageCode();
    FUN_00667950();
  }
  FUN_0054df00();
  return;
}


// ==== 0x54df00 FUN_0054df00

void FUN_0054df00(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined1 uStack_238;
  undefined4 uStack_237;
  char cStack_1d0;
  char acStack_1cf [199];
  undefined1 local_108;
  undefined4 local_107;
  
  local_108 = 0;
  puVar5 = &local_107;
  for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  *(undefined1 *)((int)puVar5 + 2) = 0;
  FUN_00565da0("%s-%s-%s",&PTR_DAT_006bd178,&DAT_006bd174,&DAT_006bd16c);
  FUN_00667950(param_1,param_2,&DAT_006bd158,&local_108);
  uStack_238 = 0;
  puVar5 = &uStack_237;
  for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  *(undefined1 *)((int)puVar5 + 2) = 0;
  FUN_00449ec0(100);
  FUN_00565da0("%s/%s-%s",&DAT_006bd174,&uStack_238,"Jan 15 2004");
  FUN_00667950(param_1,param_2,&DAT_006bd138,&local_108);
  cStack_1d0 = '\0';
  pcVar2 = acStack_1cf;
  for (iVar3 = 0x31; iVar3 != 0; iVar3 = iVar3 + -1) {
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    pcVar2 = pcVar2 + 4;
  }
  pcVar2[0] = '\0';
  pcVar2[1] = '\0';
  pcVar2[2] = '\0';
  pcVar2 = (char *)GetSkuString();
  cStack_1d0 = *pcVar2;
  if (*pcVar2 != '\0') {
    pcVar4 = &cStack_1d0;
    do {
      cVar1 = pcVar4[(int)(pcVar2 + (1 - (int)&cStack_1d0))];
      pcVar4 = pcVar4 + 1;
      *pcVar4 = cVar1;
    } while (cVar1 != '\0');
  }
  FUN_00667950(param_1,param_2,&DAT_006bd130,&cStack_1d0);
  return;
}


// ==== 0x54e020 FUN_0054e020

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054e020(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  bool bVar5;
  undefined1 local_218 [4];
  ushort local_214;
  char local_212;
  undefined1 local_210 [528];
  
  if (DAT_00734f7c == 0) {
    if (DAT_00734f74 != 0) {
      if ((DAT_0073d864 == 0) || (DAT_0073d864 == 0x7fffffff)) {
        DAT_0073d864 = _ftol_nocw();
      }
      DAT_00734f7c = FUN_005493d0();
      if (DAT_00734f7c != 0) {
                    /* WARNING: Could not recover jumptable at 0x0054e1a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*_DAT_00730158)();
        return;
      }
      if (((DAT_0073d864 != 0) && (DAT_0073d864 != 0x7fffffff)) && (DAT_0073d864 < DAT_0073ad3c)) {
        (*DAT_00730154)(0);
      }
    }
  }
  else {
    iVar2 = FUN_00664100(DAT_00734f7c);
    if ((*(char *)(iVar2 + 0x45) != '\0') && (DAT_00734f7c != 0)) {
      while( true ) {
        iVar2 = FUN_006641f0(DAT_00734f7c,local_218,1);
        if (iVar2 == 0) break;
        uVar4 = (uint)local_214;
        bVar5 = local_212 == '\x05';
        iVar2 = _ftol_nocw();
        uVar1 = DAT_00704b78;
        if (DAT_00704b70 <= -iVar2 - DAT_00704b74) {
          iVar2 = (-iVar2 - DAT_00704b74) / DAT_00704b70;
          DAT_00704b74 = DAT_00704b74 + DAT_00704b70 * iVar2;
          DAT_00704b78 = 0;
          _DAT_00704b7c = (iVar2 != 1) - 1 & uVar1;
        }
        DAT_00704b78 = DAT_00704b78 + uVar4;
        (*DAT_0073015c)(local_210,uVar4,bVar5);
        if (DAT_00734f7c == 0) {
          return;
        }
      }
      if (DAT_00734f7c != 0) {
        piVar3 = (int *)FUN_00664100(DAT_00734f7c);
        if (DAT_00730150 < (uint)(*piVar3 - piVar3[8])) {
                    /* WARNING: Could not recover jumptable at 0x0054e13b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*_DAT_00730160)();
          return;
        }
      }
    }
  }
  return;
}


// ==== 0x54e1e0 FUN_0054e1e0

bool FUN_0054e1e0(undefined4 param_1,undefined2 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_20;
  undefined4 local_1f;
  
  DAT_00734f74 = FUN_00663540();
  if (DAT_00734f74 == 0) {
    return false;
  }
  local_20 = 0;
  puVar3 = &local_1f;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  uVar1 = FUN_00662670(param_1,param_2,param_2);
  _sprintf(&local_20,"%s:%u:%u",uVar1);
  FUN_006635d0(DAT_00734f74,0x102,&local_20);
  return DAT_00734f74 != 0;
}


// ==== 0x54e260 FUN_0054e260

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054e260(void)

{
  uint uVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar2 = _ftol_nocw();
  uVar1 = DAT_00704b88;
  if (DAT_00704b80 <= -iVar2 - DAT_00704b84) {
    iVar2 = (-iVar2 - DAT_00704b84) / DAT_00704b80;
    DAT_00704b84 = DAT_00704b84 + DAT_00704b80 * iVar2;
    DAT_00704b88 = 0;
    _DAT_00704b8c = (iVar2 != 1) - 1 & uVar1;
  }
  DAT_00704b88 = DAT_00704b88 + unaff_EDI;
  FUN_00549410(DAT_00734f7c);
  return;
}


// ==== 0x54e2f0 FUN_0054e2f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054e2f0(void)

{
  int *piVar1;
  
  FUN_0054e5b0();
  DAT_00730180 = 0;
  DAT_00730168 = 0;
  DAT_0073016c = 0;
  DAT_00730178 = 0;
  DAT_0073017c = 0;
  DAT_00730164 = 0;
  _DAT_00730170 = 0;
  piVar1 = &DAT_0073d830;
  do {
    piVar1[-1] = -1;
    piVar1[-2] = 0;
    piVar1[2] = 0;
    if (piVar1[1] != 0) {
      FUN_006640b0(piVar1[1]);
    }
    if (*piVar1 != 0) {
      FUN_00663960(*piVar1);
    }
    *piVar1 = 0;
    piVar1[1] = 0;
    piVar1 = piVar1 + 5;
  } while ((int)piVar1 < 0x73d86c);
  return;
}


// ==== 0x54e370 FUN_0054e370

void FUN_0054e370(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_0073d828;
  do {
    switch(*puVar1) {
    case 1:
      FUN_0054e650();
      break;
    case 2:
      FUN_0054e6b0();
      break;
    case 3:
      FUN_0054e740();
      break;
    case 4:
      FUN_0054e530();
    }
    puVar1 = puVar1 + 5;
  } while ((int)puVar1 < 0x73d864);
  return;
}


// ==== 0x54e3d0 FUN_0054e3d0

void FUN_0054e3d0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar1 = &DAT_0073d828;
  do {
    if (*piVar1 == 0) {
      if (&DAT_0073d828 + iVar3 * 5 != (undefined4 *)0x0) {
        uVar2 = FUN_00549340(param_1,param_2,1);
        (&DAT_0073d830)[iVar3 * 5] = uVar2;
        (&DAT_0073d828)[iVar3 * 5] = 2;
        uVar2 = _ftol_nocw();
        (&DAT_0073d838)[iVar3 * 5] = uVar2;
      }
      return;
    }
    piVar1 = piVar1 + 5;
    iVar3 = iVar3 + 1;
  } while ((int)piVar1 < 0x73d864);
  return;
}


// ==== 0x54e440 FUN_0054e440

void FUN_0054e440(void)

{
  int *piVar1;
  
  piVar1 = &DAT_0073d830;
  do {
    if (piVar1[-2] == 2) {
      piVar1[-2] = 0;
      if (*piVar1 != 0) {
        FUN_00663960(*piVar1);
      }
      *piVar1 = 0;
      piVar1[2] = 0;
    }
    piVar1 = piVar1 + 5;
  } while ((int)piVar1 < 0x73d86c);
  return;
}


// ==== 0x54e480 FUN_0054e480

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054e480(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int unaff_EDI;
  
  iVar2 = _ftol_nocw();
  uVar1 = DAT_00704b68;
  if (DAT_00704b60 <= -iVar2 - DAT_00704b64) {
    iVar2 = (-iVar2 - DAT_00704b64) / DAT_00704b60;
    DAT_00704b64 = DAT_00704b64 + DAT_00704b60 * iVar2;
    DAT_00704b68 = 0;
    _DAT_00704b6c = (iVar2 != 1) - 1 & uVar1;
  }
  DAT_00704b68 = DAT_00704b68 + unaff_EDI;
  iVar2 = 0;
  piVar3 = &DAT_0073d82c;
  do {
    if (*piVar3 == param_1) {
      puVar4 = &DAT_0073d828 + iVar2 * 5;
      goto LAB_0054e501;
    }
    piVar3 = piVar3 + 5;
    iVar2 = iVar2 + 1;
  } while ((int)piVar3 < 0x73d868);
  puVar4 = (undefined4 *)0x0;
LAB_0054e501:
  FUN_00549410(puVar4[3]);
  return;
}


// ==== 0x54e530 FUN_0054e530

void __fastcall FUN_0054e530(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  piVar1 = &DAT_0073d82c;
  do {
    if (*piVar1 == param_2) {
      puVar3 = &DAT_0073d828 + iVar2 * 5;
      goto LAB_0054e549;
    }
    piVar1 = piVar1 + 5;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x73d868);
  puVar3 = (undefined4 *)0x0;
LAB_0054e549:
  puVar3[1] = 0xffffffff;
  *puVar3 = 0;
  puVar3[4] = 0;
  if (puVar3[3] != 0) {
    FUN_006640b0(puVar3[3]);
  }
  if (puVar3[2] != 0) {
    FUN_00663960(puVar3[2]);
  }
  puVar3[2] = 0;
  puVar3[3] = 0;
  DAT_0073017c = DAT_0073017c + -1;
  return;
}


// ==== 0x54e5b0 FUN_0054e5b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054e5b0(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_14;
  LARGE_INTEGER local_10;
  LARGE_INTEGER local_8;
  
  QueryPerformanceCounter(&local_10);
  iVar2 = __allshr();
  iVar3 = 0;
  do {
    FUN_00411030();
    QueryPerformanceCounter(&local_8);
    uVar1 = DAT_007349c8;
    local_14 = __allshr();
    local_14 = local_14 - iVar2;
    if (local_14 < 0) {
      local_14 = 0;
    }
    iVar3 = iVar3 + 1;
  } while ((iVar3 < 0xf4241) &&
          (local_10.s.LowPart = 1 << ((byte)uVar1 & 0x1f),
          (float)(int)local_10.s.LowPart * (float)local_14 * _DAT_007301d0 * 0.001 <= _K_ONE));
  return;
}


// ==== 0x54e650 FUN_0054e650

void FUN_0054e650(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_ESI;
  bool bVar3;
  
  iVar1 = FUN_00549340(0,DAT_00730170,1);
  bVar3 = DAT_007346d4 == 0;
  unaff_ESI[2] = iVar1;
  if ((bVar3) || (iVar1 != 0)) {
    *unaff_ESI = 2;
    uVar2 = _ftol_nocw();
    unaff_ESI[4] = uVar2;
  }
  return;
}


// ==== 0x54e6b0 FUN_0054e6b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054e6b0(void)

{
  int iVar1;
  undefined4 *unaff_ESI;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = FUN_006637b0(unaff_ESI[2]);
  if (iVar1 == 0) {
    if (DAT_007346d4 != 0) {
      _DAT_0078ea94 = _DAT_0078ea94 + 1;
    }
  }
  else {
    iVar2 = FUN_00663fe0(iVar1,0,0x2000);
  }
  unaff_ESI[3] = iVar2;
  if (iVar2 != 0) {
    unaff_ESI[1] = DAT_00730164;
    DAT_00730164 = DAT_00730164 + 1;
    DAT_0073017c = DAT_0073017c + 1;
    *unaff_ESI = 3;
    (*DAT_00730180)(unaff_ESI[1]);
    unaff_ESI[4] = 0;
    return;
  }
  if ((int)unaff_ESI[4] < DAT_0073ad3c) {
    (*DAT_0073016c)();
    unaff_ESI[4] = 0;
  }
  return;
}


// ==== 0x54e740 FUN_0054e740

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054e740(void)

{
  uint uVar1;
  int *in_EAX;
  int iVar2;
  int *piVar3;
  uint uVar4;
  bool bVar5;
  undefined1 local_218 [4];
  ushort local_214;
  char local_212;
  undefined1 local_210 [528];
  
  iVar2 = FUN_00664100(in_EAX[3]);
  if ((*(char *)(iVar2 + 0x45) != '\0') && (*in_EAX == 3)) {
    while ((in_EAX[3] != 0 && (iVar2 = FUN_006641f0(in_EAX[3],local_218,1), iVar2 != 0))) {
      uVar4 = (uint)local_214;
      bVar5 = local_212 == '\x05';
      iVar2 = _ftol_nocw();
      uVar1 = DAT_00704b58;
      if (DAT_00704b50 <= -iVar2 - DAT_00704b54) {
        iVar2 = (-iVar2 - DAT_00704b54) / DAT_00704b50;
        DAT_00704b54 = DAT_00704b54 + DAT_00704b50 * iVar2;
        DAT_00704b58 = 0;
        _DAT_00704b5c = (iVar2 != 1) - 1 & uVar1;
      }
      DAT_00704b58 = DAT_00704b58 + uVar4;
      (*DAT_00730178)(in_EAX[1],local_210,uVar4,bVar5);
      if (*in_EAX != 3) {
        return;
      }
    }
    if ((*in_EAX == 3) &&
       (piVar3 = (int *)FUN_00664100(in_EAX[3]), DAT_00730174 < (uint)(*piVar3 - piVar3[8]))) {
      iVar2 = in_EAX[1];
      FUN_0054e530();
      (*DAT_00730168)(iVar2);
    }
  }
  return;
}


// ==== 0x54e880 FUN_0054e880

void __fastcall FUN_0054e880(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bd0cc;
  FUN_004f7b50();
  return;
}


// ==== 0x54e890 FUN_0054e890

undefined4 FUN_0054e890(void)

{
  undefined4 in_stack_00000014;
  
  return in_stack_00000014;
}


// ==== 0x54e8a0 FUN_0054e8a0

void * __thiscall FUN_0054e8a0(void *param_1,byte param_2)

{
  FUN_0054e880();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x54e8c0 FUN_0054e8c0

undefined4 FUN_0054e8c0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006878f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x1c0);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0054e920(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x54e920 FUN_0054e920

/* WARNING: Removing unreachable block (ram,0x0054eb8f) */

undefined4 * FUN_0054e920(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006878d0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FEScreen__FEScreen(param_1,param_2);
  *param_1 = &PTR_FUN_006bd0cc;
  local_4 = 0;
  param_1[0x16] = 0xfa;
  param_1[0x15] = 10;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x18] = 0;
  iVar2 = FUN_004f9f30();
  DAT_00777cb4 = 0;
  DAT_00777cc8 = 0;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  *(undefined4 *)(iVar2 + 0x18) = 0;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  FUN_004f9f30();
  puVar3 = param_1 + 0x1f;
  iVar2 = 10;
  do {
    *(undefined1 *)puVar3 = 0;
    puVar3 = puVar3 + 8;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1[0x1d] = 0;
  iVar2 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar2 == 0) || (iVar2 = *(int *)(iVar2 + 0x18), iVar2 == 0)) {
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar1 = *(int *)(DAT_0073578c + 8);
      if (iVar1 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004fd1e0(iVar1 + 0xdc);
        if (iVar2 == 0) {
          iVar2 = FUN_004fd1e0(iVar1 + 0xec);
        }
      }
    }
  }
  param_1[0x1e] = iVar2;
  *(undefined1 *)(param_1 + 8) = 1;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  if (param_1[3] == 0) {
LAB_0054eacb:
    if (DAT_0073578c == 0) goto LAB_0054eae5;
    uVar4 = FUN_004ef050(0xaa68bfd4);
  }
  else {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0x18), iVar2 != 0)) {
LAB_0054ea94:
      local_4._0_1_ = 1;
      FUN_004ffb00(iVar2);
      local_4 = (uint)local_4._1_3_ << 8;
      goto LAB_0054eacb;
    }
    if (DAT_0073578c != 0) {
      if ((*(int *)(DAT_0073578c + 8) == 0) ||
         ((iVar2 = FUN_004fd1e0(*(int *)(DAT_0073578c + 8) + 0xdc), iVar2 == 0 &&
          (iVar2 = FUN_004fd1e0(*(int *)(DAT_0073578c + 8) + 0xec), iVar2 == 0))))
      goto LAB_0054eacb;
      goto LAB_0054ea94;
    }
LAB_0054eae5:
    uVar4 = 0;
  }
  param_1[0x10] = uVar4;
  if (param_1[3] == 0) {
LAB_0054eb95:
    if (DAT_0073578c == 0) goto LAB_0054ebaf;
    uVar4 = FUN_004ef050(0xaa68bfce);
  }
  else {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0x18), iVar2 != 0)) {
LAB_0054eb58:
      local_4._0_1_ = 2;
      FUN_004ffb00(iVar2);
      local_4 = (uint)local_4._1_3_ << 8;
      goto LAB_0054eb95;
    }
    if (DAT_0073578c != 0) {
      iVar1 = *(int *)(DAT_0073578c + 8);
      if ((iVar1 == 0) ||
         (((iVar2 = FUN_004fd1e0(iVar1 + 0xdc), iVar2 == 0 &&
           (iVar2 = FUN_004fd1e0(iVar1 + 0xec), iVar2 == 0)) || (iVar2 == 0)))) goto LAB_0054eb95;
      goto LAB_0054eb58;
    }
LAB_0054ebaf:
    uVar4 = 0;
  }
  param_1[0x11] = uVar4;
  if (param_1[3] == 0) {
LAB_0054ec4f:
    if (DAT_0073578c == 0) goto LAB_0054ec69;
    uVar4 = FUN_004ef050(0xaa68bfd7);
  }
  else {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0x18), iVar2 != 0)) {
LAB_0054ec18:
      local_4._0_1_ = 3;
      FUN_004ffb00(iVar2);
      local_4 = (uint)local_4._1_3_ << 8;
      goto LAB_0054ec4f;
    }
    if (DAT_0073578c != 0) {
      iVar1 = *(int *)(DAT_0073578c + 8);
      if ((iVar1 == 0) ||
         ((iVar2 = FUN_004fd1e0(iVar1 + 0xdc), iVar2 == 0 &&
          (iVar2 = FUN_004fd1e0(iVar1 + 0xec), iVar2 == 0)))) goto LAB_0054ec4f;
      goto LAB_0054ec18;
    }
LAB_0054ec69:
    uVar4 = 0;
  }
  param_1[0x12] = uVar4;
  if (param_1[3] == 0) {
LAB_0054ed0f:
    if (DAT_0073578c == 0) goto LAB_0054ed29;
    uVar4 = FUN_004ef050(0xaa68bfc6);
  }
  else {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0x18), iVar2 != 0)) {
LAB_0054ecd8:
      local_4._0_1_ = 4;
      FUN_004ffb00(iVar2);
      local_4 = (uint)local_4._1_3_ << 8;
      goto LAB_0054ed0f;
    }
    if (DAT_0073578c != 0) {
      iVar1 = *(int *)(DAT_0073578c + 8);
      if ((iVar1 == 0) ||
         ((iVar2 = FUN_004fd1e0(iVar1 + 0xdc), iVar2 == 0 &&
          (iVar2 = FUN_004fd1e0(iVar1 + 0xec), iVar2 == 0)))) goto LAB_0054ed0f;
      goto LAB_0054ecd8;
    }
LAB_0054ed29:
    uVar4 = 0;
  }
  param_1[0x13] = uVar4;
  if (param_1[3] == 0) {
LAB_0054edcf:
    if (DAT_0073578c != 0) {
      uVar4 = FUN_004ef050(0x925c868a);
      goto LAB_0054edeb;
    }
  }
  else {
    iVar2 = FEPackageList__FindByName(&DAT_00746104);
    if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0x18), iVar2 != 0)) {
LAB_0054ed98:
      local_4._0_1_ = 5;
      FUN_004ffb00(iVar2);
      local_4 = (uint)local_4._1_3_ << 8;
      goto LAB_0054edcf;
    }
    if (DAT_0073578c != 0) {
      iVar1 = *(int *)(DAT_0073578c + 8);
      if ((iVar1 == 0) ||
         ((iVar2 = FUN_004fd1e0(iVar1 + 0xdc), iVar2 == 0 &&
          (iVar2 = FUN_004fd1e0(iVar1 + 0xec), iVar2 == 0)))) goto LAB_0054edcf;
      goto LAB_0054ed98;
    }
  }
  uVar4 = 0;
LAB_0054edeb:
  param_1[0x14] = uVar4;
  param_1[0x6f] = 0;
  DAT_00734f70 = param_1;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x54ee20 FUN_0054ee20

undefined4 __fastcall FUN_0054ee20(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  switch(param_1) {
  case 0:
    return 0;
  case 1:
    return 1;
  case 2:
    return 6;
  case 3:
    uVar1 = 5;
  }
  return uVar1;
}


// ==== 0x54ee60 FUN_0054ee60

void __thiscall FUN_0054ee60(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  undefined1 *puVar7;
  char acStack_48 [36];
  undefined1 auStack_24 [36];
  
  if (param_2 < 0x9120409f) {
    if (param_2 != 0x9120409e) {
      if (0x911ab364 < param_2) {
        if (param_2 != 0x911c0a4b) {
          return;
        }
        FUN_004f9ed0();
        return;
      }
      if (param_2 == 0x911ab364) {
        FEngSwitchPackages(*(undefined4 *)(param_1 + 0xc));
        return;
      }
      if (param_2 == 0xc407210) {
        iVar2 = FEngFindPackage();
        if (iVar2 != 0) {
          *(undefined4 *)(iVar2 + 0x1c) = 0;
        }
        pcVar4 = (char *)(*(int *)(param_1 + 100) * 0x20 + 0x7c + param_1);
        pcVar5 = &DAT_00730188;
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
          *pcVar5 = cVar1;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        FUN_0054ab80(FUN_0054f860);
        return;
      }
      if (param_2 != 0x72619778) {
        return;
      }
      FUN_004f9ed0();
      return;
    }
    if (0 < DAT_00777cb4) {
      DAT_00777cb4 = DAT_00777cb4 + -1;
    }
  }
  else {
    if (param_2 != 0xb5971bf1) {
      if (param_2 != 0xc519bfbf) {
        if (param_2 != 0xc98356ba) {
          return;
        }
        *(int *)(param_1 + 0x1bc) = *(int *)(param_1 + 0x1bc) + 1;
        FUN_0054f200(param_1);
        FUN_0054f050();
        return;
      }
      iVar2 = FEngFindPackage();
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x1c) = 0;
      }
      iVar2 = LanguageStrings__FindByHash();
      if (iVar2 == 0) {
        iVar2 = LanguageStrings__FindByHash();
      }
      iVar6 = 0x21;
      pcVar4 = acStack_48;
      do {
        cVar1 = pcVar4[iVar2 - (int)acStack_48];
        iVar6 = iVar6 + -1;
        *pcVar4 = cVar1;
        if (cVar1 == '\0') break;
        pcVar4 = pcVar4 + 1;
      } while (iVar6 != 0);
      bSPrintf_regdst(0x21,acStack_48,&DAT_00734718);
      puVar7 = auStack_24;
      uVar3 = FE_GetSlotPrefix(&DAT_00748f70);
      bSPrintf_regdst(0x40,&DAT_006cc578,uVar3,puVar7);
      FUN_0054a5e0(FUN_0054f7a0);
      return;
    }
    if (DAT_00777cb4 < 3) {
      DAT_00777cb4 = DAT_00777cb4 + 1;
    }
  }
  DAT_00777cc8 = FUN_0054ee20();
  return;
}


// ==== 0x54f050 FUN_0054f050

void FUN_0054f050(void)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int unaff_EBX;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int local_8;
  
  piVar5 = (int *)(unaff_EBX + 0x40);
  local_8 = 5;
  do {
    if ((*piVar5 != 0) && (DAT_007064b2 != '\0')) {
      cVar2 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0));
      if (cVar2 != '\0') {
        uVar6 = *(undefined4 *)(*piVar5 + 0x10);
        if (*(int *)(unaff_EBX + 0xc) == 0) {
LAB_0054f0de:
          if (DAT_0073578c != 0) {
            iVar3 = FUN_004ef050(uVar6);
            goto LAB_0054f0f2;
          }
        }
        else {
          iVar3 = FEngFindPackage();
          if (iVar3 == 0) goto LAB_0054f0de;
          iVar3 = FUN_004ffb70();
          if (iVar3 == 0) goto LAB_0054f0de;
LAB_0054f0f2:
          if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
            FUN_004f0700(0xc407210,*piVar5,*(undefined4 *)(unaff_EBX + 0x78),iVar3,0);
          }
        }
        uVar1 = *(uint *)(*piVar5 + 0x10);
        if (uVar1 < 0xaa68bfcf) {
          if (uVar1 == 0xaa68bfce) {
            iVar3 = FEPackageList__FindByName(&DAT_00746104);
            if (((iVar3 != 0) && (iVar7 = *(int *)(iVar3 + 0x18), iVar7 != 0)) &&
               (piVar4 = *(int **)(iVar3 + 0x14), piVar4 != (int *)0x0)) {
              uVar6 = 0x9120409e;
LAB_0054f1d4:
              (**(code **)(*piVar4 + 8))(uVar6,0,0,iVar7);
            }
          }
          else if (uVar1 == 0x925c868a) {
            FUN_004c96c0(0xc519bfbf);
          }
          else if (uVar1 == 0xaa68bfc6) {
            FUN_004c96c0(0x911c0a4b);
          }
        }
        else if (uVar1 == 0xaa68bfd4) {
          iVar3 = FEPackageList__FindByName(&DAT_00746104);
          if (((iVar3 != 0) && (iVar7 = *(int *)(iVar3 + 0x18), iVar7 != 0)) &&
             (piVar4 = *(int **)(iVar3 + 0x14), piVar4 != (int *)0x0)) {
            uVar6 = 0xb5971bf1;
            goto LAB_0054f1d4;
          }
        }
        else if (uVar1 == 0xaa68bfd7) {
          FUN_004c96c0(0x72619778);
        }
      }
    }
    piVar5 = piVar5 + 1;
    local_8 = local_8 + -1;
    if (local_8 == 0) {
      return;
    }
  } while( true );
}


// ==== 0x54f200 FUN_0054f200

void FUN_0054f200(int param_1)

{
  byte *pbVar1;
  char *pcVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  undefined4 uVar10;
  byte *pbVar11;
  char *pcVar12;
  undefined1 *puVar13;
  char *pcVar14;
  int local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  byte local_20;
  byte local_1f [31];
  
  switch(DAT_00777cb4) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
  }
  iVar5 = LanguageStrings__FindByHash();
  if (iVar5 == 0) {
    iVar5 = LanguageStrings__FindByHash();
  }
  FEngPrintf(&DAT_006cc568,iVar5);
  uVar6 = FE_GetSlotPrefix(&DAT_00748f70);
  FUN_00549c40();
  FUN_004f9f30();
  local_2c = FUN_00549c40();
  iVar5 = 0;
  if (0 < local_2c) {
    do {
      if ((*(int *)(param_1 + 0x6c) <= iVar5) && (iVar5 < *(int *)(param_1 + 0x70))) {
        iVar7 = (iVar5 - *(int *)(param_1 + 0x6c)) + 1;
        if (iVar7 < 10) {
          pcVar14 = "%s0%d";
        }
        else {
          pcVar14 = "%s%d";
        }
        bSPrintf_regdst(0x20,pcVar14,"RoomName_DATA",iVar7);
        iVar7 = -1;
        pbVar11 = &local_20;
        bVar3 = local_20;
        while (bVar3 != 0) {
          if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
            bVar3 = bVar3 - 0x20;
          }
          iVar7 = iVar7 * 0x21 + (uint)bVar3;
          pbVar1 = pbVar11 + 1;
          pbVar11 = pbVar11 + 1;
          bVar3 = *pbVar1;
        }
        if (((((*(int *)(param_1 + 0xc) != 0) && (iVar8 = FEngFindPackage(), iVar8 != 0)) &&
             (iVar8 = FUN_004ffb70(), iVar8 != 0)) ||
            ((DAT_0073578c != 0 && (iVar7 = FUN_004ef050(iVar7), iVar7 != 0)))) &&
           (cVar4 = FUN_004f7660((float)(DAT_0070649c + -0x140),(float)(DAT_007064a0 + -0xf0)),
           cVar4 != '\0')) {
          FUN_004f9ed0();
          break;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < local_2c);
  }
  if (*(int *)(param_1 + 0x1bc) < 0x65) goto LAB_0054f51b;
  *(undefined4 *)(param_1 + 0x1bc) = 0x65;
  if (*(int *)(param_1 + 0x74) == *(int *)(param_1 + 100)) goto LAB_0054f51b;
  iVar5 = *(int *)(param_1 + 0x74) + 1;
  if (iVar5 < 10) {
    pcVar14 = "%s0%d";
  }
  else {
    pcVar14 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar14,"RoomName_DATA",iVar5);
  iVar5 = -1;
  pbVar11 = &local_20;
  bVar3 = local_20;
  while (bVar3 != 0) {
    if (('`' < (char)bVar3) && ((char)bVar3 < '{')) {
      bVar3 = bVar3 - 0x20;
    }
    iVar5 = iVar5 * 0x21 + (uint)bVar3;
    pbVar1 = pbVar11 + 1;
    pbVar11 = pbVar11 + 1;
    bVar3 = *pbVar1;
  }
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar7 = FEngFindPackage(), iVar7 == 0)) ||
     (iVar7 = FUN_004ffb70(), iVar7 == 0)) {
    if (DAT_0073578c != 0) {
      iVar7 = FUN_004ef050(iVar5);
      goto LAB_0054f44a;
    }
  }
  else {
LAB_0054f44a:
    if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
      FUN_004f0700(0x55d1e635,iVar7,*(undefined4 *)(param_1 + 0x78),iVar7,0);
    }
  }
  iVar5 = *(int *)(param_1 + 100) + 1;
  if (iVar5 < 10) {
    pcVar14 = "%s0%d";
  }
  else {
    pcVar14 = "%s%d";
  }
  bSPrintf_regdst(0x20,pcVar14,"RoomName_DATA",iVar5);
  iVar5 = -1;
  pbVar11 = &local_20;
  while (local_20 != 0) {
    if (('`' < (char)local_20) && ((char)local_20 < '{')) {
      local_20 = local_20 - 0x20;
    }
    pbVar1 = pbVar11 + 1;
    iVar5 = iVar5 * 0x21 + (uint)local_20;
    pbVar11 = pbVar11 + 1;
    local_20 = *pbVar1;
  }
  if (((*(int *)(param_1 + 0xc) == 0) || (iVar7 = FEngFindPackage(), iVar7 == 0)) ||
     (iVar7 = FUN_004ffb70(), iVar7 == 0)) {
    if (DAT_0073578c != 0) {
      iVar7 = FUN_004ef050(iVar5);
      goto LAB_0054f4f2;
    }
  }
  else {
LAB_0054f4f2:
    if ((DAT_0073578c != 0) && (*(int *)(DAT_0073578c + 8) != 0)) {
      FUN_004f0700(0xabc08912,iVar7,*(undefined4 *)(param_1 + 0x78),iVar7,0);
    }
  }
  *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 100);
LAB_0054f51b:
  iVar5 = FUN_00549c40();
  local_30 = 0;
  local_24 = iVar5;
  if (0 < iVar5) {
    do {
      if ((*(int *)(param_1 + 0x6c) <= local_30) && (local_30 < *(int *)(param_1 + 0x70))) {
        iVar5 = (local_30 - *(int *)(param_1 + 0x6c)) + 1;
        if (iVar5 < 10) {
          pcVar14 = "%s0%d";
        }
        else {
          pcVar14 = "%s%d";
        }
        bSPrintf_regdst(0x20,pcVar14,"RoomName_DATA",iVar5);
        pcVar9 = (char *)FUN_00549ca0(uVar6,local_30);
        pcVar14 = (char *)(iVar5 * 0x20 + 0x5c + param_1);
        pcVar12 = pcVar9;
        do {
          pcVar2 = pcVar12 + ((int)pcVar14 - (int)pcVar9);
          cVar4 = *pcVar12;
          pcVar12 = pcVar12 + 1;
          if ((*pcVar2 == '\0') || (cVar4 == '\0')) break;
        } while (*pcVar2 == cVar4);
        cVar4 = *pcVar9;
        *pcVar14 = cVar4;
        if (cVar4 != '\0') {
          pcVar12 = pcVar14;
          do {
            cVar4 = pcVar12[(int)(pcVar9 + (1 - (int)pcVar14))];
            pcVar12 = pcVar12 + 1;
            *pcVar12 = cVar4;
          } while (cVar4 != '\0');
        }
        uVar10 = LanguageStrings_FindByRegionName(&DAT_00748f70);
        FEngPrintf(&DAT_006cc568,uVar10);
        FUN_00549d30(uVar6,local_30,&local_28,&local_2c);
        if (iVar5 < 10) {
          pcVar14 = "%s0%d";
        }
        else {
          pcVar14 = "%s%d";
        }
        bSPrintf_regdst(0x20,pcVar14,"PlayersRoom_DATA",iVar5);
        FEngPrintf("%d/%d",local_28,local_2c);
        iVar5 = local_24;
      }
      local_30 = local_30 + 1;
    } while (local_30 < iVar5);
  }
  iVar5 = *(int *)(param_1 + 0x60);
  if (iVar5 < 10) {
    iVar7 = iVar5 + 1;
    puVar13 = (undefined1 *)(iVar5 * 0x20 + 0x7c + param_1);
    do {
      *puVar13 = 0;
      if (iVar7 < 10) {
        pcVar14 = "%s0%d";
      }
      else {
        pcVar14 = "%s%d";
      }
      bSPrintf_regdst(0x20,pcVar14,"RoomName_DATA",iVar7);
      FEngPrintf(&DAT_006b9172);
      if (iVar7 < 10) {
        pcVar14 = "%s0%d";
      }
      else {
        pcVar14 = "%s%d";
      }
      bSPrintf_regdst(0x20,pcVar14,"PlayersRoom_DATA",iVar7);
      FEngPrintf(&DAT_006b9172);
      puVar13 = puVar13 + 0x20;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0xb);
  }
  return;
}


// ==== 0x54f720 FUN_0054f720

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0054f720(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  _DAT_0073dda4 = DAT_0073dda0;
  DAT_0073dda0 = 0xd;
  DAT_00777c70 = DAT_00730188;
  if (DAT_00730188 != '\0') {
    iVar2 = 0;
    do {
      pcVar1 = &DAT_00730189 + iVar2;
      (&DAT_00777c71)[iVar2] = *pcVar1;
      iVar2 = iVar2 + 1;
    } while (*pcVar1 != '\0');
  }
  iVar2 = DAT_0073578c;
  uVar4 = *(undefined4 *)(DAT_00734f70 + 0xc);
  if (DAT_0073578c != 0) {
    iVar3 = FEPackageList__FindByName(&DAT_00746104);
    uVar4 = 0;
    if (iVar3 != 0) {
      uVar4 = 0;
      if (*(int *)(iVar3 + 0x18) != 0) {
        uVar4 = FUN_004f0800(*(undefined4 *)(iVar2 + 8),*(int *)(iVar3 + 0x18));
      }
    }
  }
  return uVar4;
}


// ==== 0x54f7a0 FUN_0054f7a0

void FUN_0054f7a0(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0073d8e0;
  iVar2 = FEngFindPackage();
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x1c) = 0xff;
  }
  if (iVar1 == 0) {
    FUN_0054f720(DAT_00734f70);
    return;
  }
  if (iVar1 < 0x66756c6d) {
    if ((iVar1 == 0x66756c6c) || ((iVar1 == 0x6475706c || (iVar1 == 0x66696c74))))
    goto LAB_0054f835;
  }
  else if ((iVar1 == 0x70726976) || (iVar1 == 0x74696d65)) goto LAB_0054f835;
  FUN_0054d4a0(&DAT_0073d868,DAT_0073d8e0);
LAB_0054f835:
  FUN_004eba00(0,0);
  return;
}


// ==== 0x54f860 FUN_0054f860

void FUN_0054f860(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0073d8e0;
  iVar2 = FEngFindPackage();
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x1c) = 0xff;
  }
  if (iVar1 == 0) {
    FUN_0054f720(DAT_00734f70);
    return;
  }
  if (iVar1 < 0x70617374) {
    if ((iVar1 == 0x70617373) ||
       (((iVar1 == 0x64657465 || (iVar1 == 0x66756c6c)) || (iVar1 == 0x6b69636b))))
    goto LAB_0054f8fe;
  }
  else if ((iVar1 == 0x74696d65) || (iVar1 == 0x75726f6d)) goto LAB_0054f8fe;
  FUN_0054d4a0(&DAT_0073d868,iVar1);
LAB_0054f8fe:
  FUN_004eba00(0,0);
  return;
}


// ==== 0x54f920 FUN_0054f920

void __fastcall FUN_0054f920(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006bd05c;
  FUN_004f7b50();
  return;
}


// ==== 0x54f930 FUN_0054f930

void * __thiscall FUN_0054f930(void *param_1,byte param_2)

{
  FUN_0054f920();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x54f950 FUN_0054f950

undefined4 FUN_0054f950(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687893;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x68);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0054f9b0(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x54f9b0 FUN_0054f9b0

undefined4 * FUN_0054f9b0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
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
  *param_1 = &PTR_FUN_006bd05c;
  param_1[0x10] = "MU_ONLINE_WAITING.fng";
  uVar1 = FEng__HashName();
  iVar2 = FEngFindPackage();
  if (iVar2 == 0) {
LAB_0054fa1a:
    if (DAT_0073578c != 0) {
      iVar2 = FUN_004ef050(uVar1);
      if (iVar2 != 0) goto LAB_0054fa35;
    }
LAB_0054fa3a:
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_0054fa1a;
LAB_0054fa35:
    if (*(int *)(iVar2 + 0x18) != 2) goto LAB_0054fa3a;
  }
  param_1[0x19] = iVar2;
  FEObject__SetVisible(iVar2);
  uVar1 = FEng__HashName();
  if (param_1[0x10] == 0) {
LAB_0054fa73:
    if (DAT_0073578c != 0) {
      iVar2 = FUN_004ef050(uVar1);
      if (iVar2 != 0) goto LAB_0054fa8b;
    }
LAB_0054fa90:
    iVar2 = 0;
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_0054fa73;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_0054fa73;
LAB_0054fa8b:
    if (*(int *)(iVar2 + 0x18) != 2) goto LAB_0054fa90;
  }
  param_1[0x11] = iVar2;
  uVar1 = FEng__HashName();
  if (param_1[0x10] == 0) {
LAB_0054fac0:
    if (DAT_0073578c != 0) {
      iVar2 = FUN_004ef050(uVar1);
      if (iVar2 != 0) goto LAB_0054fad8;
    }
LAB_0054fadd:
    iVar2 = 0;
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_0054fac0;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_0054fac0;
LAB_0054fad8:
    if (*(int *)(iVar2 + 0x18) != 2) goto LAB_0054fadd;
  }
  param_1[0x12] = iVar2;
  uVar1 = FEng__HashName();
  if (param_1[0x10] == 0) {
LAB_0054fb0d:
    if (DAT_0073578c != 0) {
      iVar2 = FUN_004ef050(uVar1);
      if (iVar2 != 0) goto LAB_0054fb25;
    }
LAB_0054fb2a:
    iVar2 = 0;
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_0054fb0d;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_0054fb0d;
LAB_0054fb25:
    if (*(int *)(iVar2 + 0x18) != 2) goto LAB_0054fb2a;
  }
  param_1[0x13] = iVar2;
  uVar1 = FEng__HashName();
  if (param_1[0x10] == 0) {
LAB_0054fb5a:
    if (DAT_0073578c != 0) {
      iVar2 = FUN_004ef050(uVar1);
      if (iVar2 != 0) goto LAB_0054fb72;
    }
LAB_0054fb77:
    iVar2 = 0;
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_0054fb5a;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_0054fb5a;
LAB_0054fb72:
    if (*(int *)(iVar2 + 0x18) != 2) goto LAB_0054fb77;
  }
  param_1[0x14] = iVar2;
  uVar1 = FEng__HashName();
  if (param_1[0x10] == 0) {
LAB_0054fba7:
    if (DAT_0073578c != 0) {
      iVar2 = FUN_004ef050(uVar1);
      if (iVar2 != 0) goto LAB_0054fbbf;
    }
LAB_0054fbc4:
    iVar2 = 0;
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_0054fba7;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_0054fba7;
LAB_0054fbbf:
    if (*(int *)(iVar2 + 0x18) != 2) goto LAB_0054fbc4;
  }
  piVar3 = param_1 + 0x15;
  *piVar3 = iVar2;
  uVar1 = FEng__HashName();
  if (param_1[0x10] == 0) {
LAB_0054fbf6:
    if (DAT_0073578c != 0) {
      iVar2 = FUN_004ef050(uVar1);
      if (iVar2 != 0) goto LAB_0054fc10;
    }
LAB_0054fc16:
    iVar2 = 0;
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_0054fbf6;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_0054fbf6;
LAB_0054fc10:
    if (*(int *)(iVar2 + 0x18) != 2) goto LAB_0054fc16;
  }
  param_1[0x16] = iVar2;
  uVar1 = FEng__HashName();
  if (param_1[0x10] == 0) {
LAB_0054fc46:
    if (DAT_0073578c != 0) {
      iVar2 = FUN_004ef050(uVar1);
      if (iVar2 != 0) goto LAB_0054fc5e;
    }
LAB_0054fc64:
    iVar2 = 0;
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_0054fc46;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_0054fc46;
LAB_0054fc5e:
    if (*(int *)(iVar2 + 0x18) != 2) goto LAB_0054fc64;
  }
  param_1[0x17] = iVar2;
  uVar1 = FEng__HashName();
  if (param_1[0x10] == 0) {
LAB_0054fc94:
    if (DAT_0073578c != 0) {
      iVar2 = FUN_004ef050(uVar1);
      if (iVar2 != 0) goto LAB_0054fcae;
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_0054fc94;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_0054fc94;
LAB_0054fcae:
    if (*(int *)(iVar2 + 0x18) == 2) goto LAB_0054fcb6;
  }
  iVar2 = 0;
LAB_0054fcb6:
  param_1[0x18] = iVar2;
  iVar2 = 4;
  do {
    FEObject__SetInvisible(piVar3[-4]);
    FEObject__SetInvisible(*piVar3);
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_0054fd50(param_1);
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x54fd00 FUN_0054fd00

void FUN_0054fd00(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0073578c;
  if (((param_1 == -0x367ca946) &&
      (((DAT_0077b240 == 0 || ((5 < DAT_0077b240 && (DAT_0077b240 < 8)))) && (DAT_0073578c != 0))))
     && ((iVar2 = FEPackageList__FindByName(&DAT_00746104), iVar2 != 0 &&
         (*(int *)(iVar2 + 0x18) != 0)))) {
    cFEng__PopPackage(*(undefined4 *)(iVar1 + 8),*(int *)(iVar2 + 0x18));
  }
  return;
}


// ==== 0x54fd50 FUN_0054fd50

void FUN_0054fd50(int param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int extraout_EDX;
  undefined4 *puVar9;
  bool bVar10;
  
  iVar3 = param_1;
  cVar2 = Obj_GetByte19();
  if (cVar2 == '\0') {
    iVar4 = *(int *)(param_1 + 100);
    if (iVar4 != 0) {
      *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 0x400000;
      puVar9 = DAT_00735710;
      bVar10 = DAT_00735710 != (undefined4 *)0x0;
      *(undefined4 *)(iVar4 + 0x5c) = 0xf4ca33b4;
      if (bVar10) {
        (**(code **)*puVar9)(iVar4);
      }
      *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffd | 0x400000;
    }
    iVar4 = DAT_0077b244;
    FUN_00439130();
    param_1 = 0;
    iVar5 = 1;
    puVar9 = (undefined4 *)(iVar3 + 0x44);
    do {
      iVar3 = Race__GetPlayer(param_1);
      if (iVar3 != 0) {
        FUN_00439130();
        if (iVar4 == iVar3) {
          FEObject__SetFormattedText("%d) %s",iVar5,iVar3 + 0x19);
        }
        else {
          FUN_005808e0();
          iVar6 = LanguageStrings__FindByHash();
          if (iVar6 == 0) {
            iVar6 = LanguageStrings__FindByHash();
          }
          FEObject__SetFormattedText("%d) %s (%s)",iVar5,iVar3 + 0x19,iVar6);
        }
        uVar8 = GetCarModelNameHash();
        iVar3 = puVar9[4];
        if (iVar3 != 0) {
          *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | 0x400000;
          puVar1 = DAT_00735710;
          bVar10 = DAT_00735710 != (undefined4 *)0x0;
          *(undefined4 *)(iVar3 + 0x5c) = uVar8;
          if (bVar10) {
            (**(code **)*puVar1)(iVar3);
          }
          *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) & 0xfffffffd | 0x400000;
        }
        FEObject__SetVisible(*puVar9);
        FEObject__SetVisible(puVar9[4]);
        puVar9 = puVar9 + 1;
        iVar5 = iVar5 + 1;
      }
      param_1 = param_1 + 1;
    } while (param_1 < 4);
  }
  else {
    iVar3 = FUN_00647b70();
    iVar4 = FUN_0043da30();
    iVar5 = LanguageStrings__FindByHash();
    if (iVar5 == 0) {
      iVar5 = LanguageStrings__FindByHash();
    }
    FEObject__SetFormattedText(iVar5,iVar4 - iVar3);
    iVar5 = 1;
    iVar4 = FUN_0043b7f0();
    if (0 < iVar4) {
      do {
        iVar4 = iVar5;
        cVar2 = FUN_00438a40(iVar5);
        iVar4 = FUN_0043d8c0((int)cVar2,iVar4);
        iVar4 = iVar4 - iVar3;
        if (iVar4 < 1) {
          if (iVar4 != 0) {
            iVar6 = LanguageStrings__FindByHash();
            if (iVar6 == 0) {
              iVar6 = LanguageStrings__FindByHash();
            }
            iVar7 = LanguageStrings__FindByHash();
            if (iVar7 == 0) {
              iVar7 = LanguageStrings__FindByHash();
            }
            iVar4 = -iVar4;
            goto LAB_0054fef7;
          }
          iVar4 = LanguageStrings__FindByHash();
          if (iVar4 == 0) {
            iVar4 = LanguageStrings__FindByHash();
          }
          iVar6 = LanguageStrings__FindByHash();
          if (iVar6 == 0) {
            iVar6 = LanguageStrings__FindByHash();
          }
          FEObject__SetFormattedText(iVar6,iVar5,iVar4);
        }
        else {
          iVar6 = LanguageStrings__FindByHash();
          if (iVar6 == 0) {
            iVar6 = LanguageStrings__FindByHash();
          }
          iVar7 = LanguageStrings__FindByHash();
          if (iVar7 == 0) {
            iVar7 = LanguageStrings__FindByHash();
          }
LAB_0054fef7:
          FEObject__SetFormattedText(iVar7,iVar5,iVar6,iVar4);
        }
        iVar4 = *(int *)(param_1 + 0x40 + iVar5 * 4);
        if ((iVar4 != 0) &&
           (*(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & 0xfffffffe | 0x400000,
           *(int *)(iVar4 + 0x18) == 5)) {
          uVar8 = *(undefined4 *)(iVar4 + 0x60);
          iVar4 = *(int *)(iVar4 + 0x5c);
          if (0 < iVar4) {
            do {
              FEObject__SetVisible(uVar8);
              uVar8 = *(undefined4 *)(extraout_EDX + 4);
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
        }
        iVar5 = iVar5 + 1;
        iVar4 = FUN_0043b7f0();
        if (iVar4 < iVar5) {
          return;
        }
      } while( true );
    }
  }
  return;
}


// ==== 0x5500a0 FUN_005500a0

int FUN_005500a0(void)

{
  int in_EAX;
  
  return in_EAX + 0x2ed20;
}


// ==== 0x5500b0 FUN_005500b0

void __thiscall FUN_005500b0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  int *unaff_EBX;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00686f83;
  local_c = ExceptionList;
  param_2 = param_2 + 1;
  ExceptionList = &local_c;
  unaff_EBX[8] = param_1;
  *(undefined1 *)(unaff_EBX + 9) = 1;
  bSPrintf_regdst(0x20,"Rep_DATA_0%d",param_2);
  uVar1 = FEng__HashName();
  if (param_1 == 0) {
LAB_00550114:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(uVar1);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_00550114;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_00550114;
  }
  *unaff_EBX = iVar2;
  bSPrintf_regdst(0x20,"PlayersName_DATA_0%d",param_2);
  uVar1 = FEng__HashName();
  if (param_1 == 0) {
LAB_00550169:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(uVar1);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_00550169;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_00550169;
  }
  unaff_EBX[1] = iVar2;
  bSPrintf_regdst(0x20,"CarName_DATA_0%d",param_2);
  uVar1 = FEng__HashName();
  if (param_1 == 0) {
LAB_005501bf:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(uVar1);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_005501bf;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_005501bf;
  }
  unaff_EBX[2] = iVar2;
  bSPrintf_regdst(0x20,"Generic_DATA_0%d",param_2);
  uVar1 = FEng__HashName();
  if (param_1 == 0) {
LAB_00550215:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(uVar1);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_00550215;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_00550215;
  }
  unaff_EBX[3] = iVar2;
  bSPrintf_regdst(0x20,"Ping_Group_0%d",param_2);
  pvVar3 = _malloc(0x18);
  iVar2 = 0;
  local_4 = 0;
  if (pvVar3 != (void *)0x0) {
    iVar2 = FUN_0055e900();
  }
  local_4 = 0xffffffff;
  unaff_EBX[4] = iVar2;
  bSPrintf_regdst(0x20,"NumberOfPlayers_DATA_0%d",param_2);
  uVar1 = FEng__HashName();
  if (param_1 == 0) {
LAB_005502aa:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(uVar1);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_005502aa;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_005502aa;
  }
  unaff_EBX[5] = iVar2;
  bSPrintf_regdst(0x20,"Disc_DATA_0%d",param_2);
  uVar1 = FEng__HashName();
  if (param_1 == 0) {
LAB_00550300:
    if (DAT_0073578c == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ef050(uVar1);
    }
  }
  else {
    iVar2 = FEngFindPackage();
    if (iVar2 == 0) goto LAB_00550300;
    iVar2 = FUN_004ffb70();
    if (iVar2 == 0) goto LAB_00550300;
  }
  unaff_EBX[6] = iVar2;
  bSPrintf_regdst(0x20,"HighLight_0%d",param_2);
  uVar1 = FEng__HashName();
  if (param_1 != 0) {
    iVar2 = FEngFindPackage();
    if (iVar2 != 0) {
      iVar2 = FUN_004ffb70();
      if (iVar2 != 0) goto LAB_0055036e;
    }
  }
  if (DAT_0073578c == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_004ef050(uVar1);
  }
LAB_0055036e:
  unaff_EBX[7] = iVar2;
  ExceptionList = local_c;
  return;
}


// ==== 0x550390 FUN_00550390

void __fastcall FUN_00550390(char param_1,char param_2,char param_3,char param_4)

{
  int iVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  int *unaff_ESI;
  int unaff_EDI;
  bool bVar6;
  
  bVar6 = (char)unaff_ESI[9] == param_3;
  if (((param_2 == '\0') && (param_1 == '\0')) && (bVar6)) {
    return;
  }
  *(char *)(unaff_ESI + 9) = param_3;
  if (bVar6) {
    if (param_1 == '\0') goto LAB_0055041a;
LAB_005503eb:
    if ((param_3 != '\0') && (param_4 == '\0')) goto LAB_0055041a;
  }
  else {
    if (param_3 == '\0') {
      FEObject__SetInvisible(unaff_ESI[1]);
    }
    else {
      FEObject__SetVisible();
    }
    if (param_3 != '\0') {
      FEObject__SetVisible();
      goto LAB_005503eb;
    }
    FEObject__SetInvisible(unaff_ESI[7]);
  }
  iVar1 = unaff_ESI[4];
  *(undefined4 *)(iVar1 + 0x10) = 0xffffffff;
  iVar2 = *(int *)(*(int *)(iVar1 + 0x14) + 0x5c);
  iVar5 = -1;
  if (iVar2 < -1) {
    iVar5 = iVar2;
  }
  if (*(int *)(iVar1 + 4) != iVar5) {
    *(int *)(iVar1 + 4) = iVar5;
    FUN_0055ea40(iVar1);
  }
LAB_0055041a:
  if ((param_3 == '\0') || (param_4 == '\0')) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  iVar1 = unaff_ESI[3];
  if ((iVar1 == 0) || ((*(byte *)(iVar1 + 0x1c) & 1) != 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (cVar3 != cVar4) {
    if (cVar3 == '\0') {
      FEObject__SetInvisible(iVar1);
    }
    else {
      FEObject__SetVisible();
    }
  }
  iVar1 = unaff_ESI[6];
  if ((iVar1 == 0) || ((*(byte *)(iVar1 + 0x1c) & 1) != 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (cVar3 != cVar4) {
    if (cVar3 == '\0') {
      FEObject__SetInvisible(iVar1);
    }
    else {
      FEObject__SetVisible();
    }
  }
  if (((param_3 == '\0') || (unaff_EDI != 0)) || (cVar3 = Obj_GetByte19(), cVar3 == '\0')) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  iVar1 = *unaff_ESI;
  if ((iVar1 == 0) || ((*(byte *)(iVar1 + 0x1c) & 1) != 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (cVar3 != cVar4) {
    if (cVar3 == '\0') {
      FEObject__SetInvisible(iVar1);
    }
    else {
      FEObject__SetVisible();
    }
  }
  if (((param_3 == '\0') || (unaff_EDI != 0)) || (param_4 != '\0')) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  iVar1 = unaff_ESI[2];
  if ((iVar1 == 0) || ((*(byte *)(iVar1 + 0x1c) & 1) != 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (cVar3 != cVar4) {
    if (cVar3 == '\0') {
      FEObject__SetInvisible(iVar1);
    }
    else {
      FEObject__SetVisible();
    }
  }
  if (((param_3 == '\0') || (unaff_EDI != 1)) || (param_4 != '\0')) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  iVar1 = unaff_ESI[5];
  if ((iVar1 == 0) || ((*(byte *)(iVar1 + 0x1c) & 1) != 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (cVar3 != cVar4) {
    if (cVar3 != '\0') {
      FEObject__SetVisible();
      return;
    }
    FEObject__SetInvisible(iVar1);
  }
  return;
}


// ==== 0x550570 FUN_00550570

void FUN_00550570(void)

{
  int iVar1;
  int unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_ESI == 0) {
LAB_0055058f:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xeb769347);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_0055058f;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_0055058f;
  }
  *unaff_EDI = iVar1;
  if (unaff_ESI == 0) {
LAB_005505cc:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xc55d996e);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_005505cc;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_005505cc;
  }
  unaff_EDI[1] = iVar1;
  if (unaff_ESI == 0) {
LAB_0055060a:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x31dfedb7);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_0055060a;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_0055060a;
  }
  unaff_EDI[2] = iVar1;
  if (unaff_ESI == 0) {
LAB_00550648:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x6a9f4e1d);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_00550648;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_00550648;
  }
  unaff_EDI[3] = iVar1;
  if (unaff_ESI == 0) {
LAB_00550686:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0x22b29770);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_00550686;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_00550686;
  }
  unaff_EDI[4] = iVar1;
  if (unaff_ESI == 0) {
LAB_005506c4:
    if (DAT_0073578c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_004ef050(0xf76c2f69);
    }
  }
  else {
    iVar1 = FEngFindPackage();
    if (iVar1 == 0) goto LAB_005506c4;
    iVar1 = FUN_004ffb70();
    if (iVar1 == 0) goto LAB_005506c4;
  }
  unaff_EDI[5] = iVar1;
  if (unaff_ESI != 0) {
    iVar1 = FEngFindPackage();
    if (iVar1 != 0) {
      iVar1 = FUN_004ffb70();
      if (iVar1 != 0) goto LAB_00550722;
    }
  }
  if (DAT_0073578c != 0) {
    iVar1 = FUN_004ef050(0x67779163);
    unaff_EDI[6] = iVar1;
    return;
  }
  iVar1 = 0;
LAB_00550722:
  unaff_EDI[6] = iVar1;
  return;
}


// ==== 0x550730 FUN_00550730

void __fastcall FUN_00550730(undefined4 *param_1)

{
  bool bVar1;
  char cVar2;
  undefined4 in_EAX;
  
  param_1[7] = in_EAX;
  cVar2 = Obj_GetByte19();
  if ((cVar2 == '\0') || (bVar1 = true, param_1[7] == 1)) {
    bVar1 = false;
  }
  if (bVar1) {
    FEObject__SetVisible();
    FUN_00550780();
    return;
  }
  FEObject__SetInvisible(*param_1);
  FUN_00550780();
  return;
}


// ==== 0x550780 FUN_00550780

void FUN_00550780(void)

{
  bool bVar1;
  char in_AL;
  int unaff_ESI;
  
  *(char *)(unaff_ESI + 0x20) = in_AL;
  if ((*(int *)(unaff_ESI + 0x1c) == 1) && (in_AL == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FEObject__SetVisible();
  }
  else {
    FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0x14));
  }
  if ((*(int *)(unaff_ESI + 0x1c) == 1) || (*(char *)(unaff_ESI + 0x20) != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    FEObject__SetVisible();
  }
  else {
    FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 8));
  }
  if (*(char *)(unaff_ESI + 0x20) == '\0') {
    FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0xc));
  }
  else {
    FEObject__SetVisible();
  }
  if (*(char *)(unaff_ESI + 0x20) == '\0') {
    FEObject__SetVisible();
  }
  else {
    FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0x10));
  }
  if (*(char *)(unaff_ESI + 0x20) != '\0') {
    FEObject__SetVisible();
    return;
  }
  FEObject__SetInvisible(*(undefined4 *)(unaff_ESI + 0x18));
  return;
}


// ==== 0x550830 FUN_00550830

/* WARNING: Removing unreachable block (ram,0x00550a20) */

undefined4 * FUN_00550830(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00687876;
  local_c = ExceptionList;
  piVar1 = param_1 + 5;
  ExceptionList = &local_c;
  param_1[6] = 0x32;
  *piVar1 = 6;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[8] = 0;
  FUN_004f9f30();
  param_1[1] = param_2;
  pvVar3 = _malloc(0x24);
  local_4 = 0;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00550570();
  }
  iVar7 = 0;
  param_1[0xd] = uVar4;
  puVar6 = param_1 + 0xe;
  do {
    pvVar3 = _malloc(0x28);
    local_4 = 1;
    if (pvVar3 == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_005500b0(iVar7);
    }
    *puVar6 = uVar4;
    iVar7 = iVar7 + 1;
    puVar6 = puVar6 + 1;
    local_4 = 0xffffffff;
  } while (iVar7 < 6);
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[8] = 0;
  iVar7 = 0;
  if ((int)param_1[6] < 0) {
    iVar7 = param_1[6];
  }
  param_1[7] = iVar7;
  if (iVar7 < 0) {
    param_1[0xc] = iVar7;
    param_1[0xb] = iVar7 - *piVar1;
    if (iVar7 - *piVar1 < 0) {
      param_1[0xb] = 0;
    }
  }
  iVar5 = *piVar1;
  if (iVar7 < iVar5) {
    param_1[0xc] = iVar7;
LAB_00550942:
    param_1[0xb] = 0;
  }
  else if ((int)(param_1[0xc] - param_1[0xb]) < iVar5) {
    param_1[0xc] = iVar5;
    goto LAB_00550942;
  }
  if (iVar7 + -1 < 0) {
    param_1[10] = iVar7 + -1;
  }
  iVar7 = param_1[0xb];
  if ((int)param_1[10] < iVar7) {
    param_1[10] = iVar7;
  }
  iVar2 = param_1[0xc];
  if (iVar2 < (int)param_1[10]) {
    param_1[10] = iVar2;
  }
  param_1[8] = iVar2 - iVar7;
  param_1[9] = param_1[10] - iVar7;
  if (iVar5 <= param_1[10] - iVar7) {
    param_1[9] = iVar5 + -1;
  }
  if (param_2 == 0) {
LAB_00550a28:
    local_4 = 0xffffffff;
    iVar7 = DAT_0073578c;
LAB_00550a2e:
    iVar5 = 0;
    if (iVar7 == 0) goto LAB_00550a49;
    uVar4 = FUN_004ef050(0xda928c86);
    iVar5 = DAT_0073578c;
  }
  else {
    iVar5 = FEPackageList__FindByName(&DAT_00746104);
    iVar7 = DAT_0073578c;
    if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0x18), iVar5 != 0)) {
LAB_005509de:
      local_4 = 2;
      FUN_004ffb00(iVar5);
      goto LAB_00550a28;
    }
    iVar5 = DAT_0073578c;
    if (DAT_0073578c != 0) {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if ((iVar2 != 0) &&
         ((iVar5 = FUN_004fd1e0(iVar2 + 0xdc), iVar5 != 0 ||
          (iVar5 = FUN_004fd1e0(iVar2 + 0xec), iVar5 != 0)))) goto LAB_005509de;
      goto LAB_00550a2e;
    }
LAB_00550a49:
    uVar4 = 0;
  }
  param_1[0x14] = uVar4;
  if (param_2 == 0) {
LAB_00550afc:
    if (iVar5 != 0) {
      uVar4 = FUN_004ef050(0xda9bdef7);
      goto LAB_00550b13;
    }
  }
  else {
    iVar7 = FEPackageList__FindByName(&DAT_00746104);
    iVar5 = DAT_0073578c;
    if ((iVar7 != 0) && (iVar7 = *(int *)(iVar7 + 0x18), iVar7 != 0)) {
LAB_00550ab4:
      local_4 = 3;
      FUN_004ffb00(iVar7);
      local_4 = 0xffffffff;
      iVar5 = DAT_0073578c;
      goto LAB_00550afc;
    }
    if (DAT_0073578c != 0) {
      iVar2 = *(int *)(DAT_0073578c + 8);
      if ((iVar2 == 0) ||
         ((iVar7 = FUN_004fd1e0(iVar2 + 0xdc), iVar7 == 0 &&
          (iVar7 = FUN_004fd1e0(iVar2 + 0xec), iVar7 == 0)))) goto LAB_00550afc;
      goto LAB_00550ab4;
    }
  }
  uVar4 = 0;
LAB_00550b13:
  param_1[0x15] = uVar4;
  *param_1 = 0xffffffff;
  param_1[4] = 0xffffffff;
  ExceptionList = local_c;
  return param_1;
}


// ==== 0x550b40 FUN_00550b40

void FUN_00550b40(void)

{
  void *_Memory;
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  
  _free(*(void **)(in_EAX + 0x34));
  *(undefined4 *)(in_EAX + 0x34) = 0;
  puVar2 = (undefined4 *)(in_EAX + 0x38);
  iVar1 = 6;
  do {
    _Memory = (void *)*puVar2;
    if (_Memory != (void *)0x0) {
      if (*(void **)((int)_Memory + 0x10) != (void *)0x0) {
        _free(*(void **)((int)_Memory + 0x10));
      }
      *(undefined4 *)((int)_Memory + 0x10) = 0;
      _free(_Memory);
    }
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


// ==== 0x550ba0 FUN_00550ba0

void FUN_00550ba0(void)

{
  int in_EAX;
  
  FUN_004f9ed0();
  if ((**(int **)(in_EAX + 0x38 + *(int *)(in_EAX + 0x24) * 4) != 0) && (DAT_0073578c != 0)) {
    cFEng__SetCurrentButton(DAT_0073578c);
  }
  return;
}


// ==== 0x550bd0 FUN_00550bd0

void FUN_00550bd0(int *param_1,int param_2)

{
  int iVar1;
  
  FUN_004f9f30();
  iVar1 = 0;
  do {
    FUN_00550390(iVar1 < param_1[8],*(undefined1 *)((int)param_1 + 0xd));
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  iVar1 = param_1[9];
  if (((*param_1 != iVar1) && (*param_1 = iVar1, *(int *)param_1[iVar1 + 0xe] != 0)) &&
     (DAT_0073578c != 0)) {
    cFEng__SetCurrentButton(DAT_0073578c);
  }
  if (param_1[4] != param_2) {
    param_1[4] = param_2;
    if (param_2 < 7) {
      FEObject__SetInvisible(param_1[0x14]);
    }
    else {
      FEObject__SetVisible();
    }
    if (6 < param_2) {
      FEObject__SetVisible();
      return;
    }
    FEObject__SetInvisible(param_1[0x15]);
  }
  return;
}


// ==== 0x550ca0 FUN_00550ca0

undefined4 FUN_00550ca0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_006887c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = _malloc(0x7b0);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_00550d00(pvVar1,param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


// ==== 0x550d00 FUN_00550d00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00550d00(undefined4 *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int *piVar6;
  void *local_10;
  code *pcStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  pcStack_c = FUN_0068879b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FEScreen__FEScreen(param_1,param_2);
  local_8 = 0;
  *param_1 = &PTR_FUN_006bce70;
  RideInfo__Init();
  param_1[0x1ea] = 0x9d5e09c9;
  DAT_00777b54 = 0;
  param_1[0x1b] = 0;
  *(undefined1 *)(param_1 + 0x1c) = 0;
  cFrontendDatabase__BuildRideForCarHandle(param_1 + 0x20);
  iVar3 = FUN_004b2330();
  RideInfo__operator_(&DAT_00748850,param_1 + 0x20);
  _DAT_0072cc80 = 1;
  if (iVar3 != 0) {
    GarageMainScreen__SetRideInfo(iVar3,&DAT_00748850,1);
  }
  FUN_004b2480();
  pvVar4 = _malloc(0x58);
  local_8._0_1_ = 1;
  if (pvVar4 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_00550830(pvVar4,*(undefined4 *)(*(int *)(param_2 + 4) + 0xc),0);
  }
  iVar2 = param_1[0x1b];
  param_1[0x1e8] = iVar3;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00550730();
  if (*(int *)(iVar3 + 8) != iVar2) {
    *(int *)(iVar3 + 8) = iVar2;
    *(undefined1 *)(iVar3 + 0xc) = 1;
  }
  FUN_005530e0();
  FUN_00553300();
  if (param_1[0x1b] == 0) {
    FUN_00552610(param_1,1);
  }
  else {
    FUN_00552bb0(param_1,1);
  }
  iVar3 = param_1[0x1e8];
  cVar1 = *(char *)(param_1 + 0x1c);
  FUN_00550780();
  if (*(char *)(iVar3 + 0xd) != cVar1) {
    *(char *)(iVar3 + 0xd) = cVar1;
    *(undefined1 *)(iVar3 + 0xe) = 1;
  }
  uVar5 = FUN_00553360();
  param_1[0x1e9] = uVar5;
  FUN_005534a0(uVar5);
  *(undefined1 *)(param_1 + 8) = 1;
  piVar6 = param_1 + 0x10;
  for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar6 = 0;
    piVar6 = piVar6 + 1;
  }
  if (((param_1[3] == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xda9bdef8);
    }
  }
  param_1[0x10] = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xda928c87);
    }
  }
  param_1[0x11] = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xda9bdef7);
    }
  }
  param_1[0x12] = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xda928c86);
    }
  }
  param_1[0x13] = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xaa68bfce);
    }
  }
  param_1[0x14] = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xaa68bfd4);
    }
  }
  param_1[0x15] = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0x925c868a);
    }
  }
  param_1[0x16] = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xea9e6302);
    }
  }
  param_1[0x17] = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xda96ef8f);
    }
  }
  param_1[0x18] = iVar3;
  if (((param_1[3] == 0) || (iVar3 = FEngFindPackage(), iVar3 == 0)) ||
     (iVar3 = FUN_004ffb70(), iVar3 == 0)) {
    if (DAT_0073578c == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004ef050(0xda9a39d5);
    }
  }
  param_1[0x19] = iVar3;
  DAT_007363b3 = 1;
  iVar3 = FEPackageList__FindByName(&DAT_00746104);
  if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0)) {
    if ((DAT_0073578c == 0) || (iVar2 = *(int *)(DAT_0073578c + 8), iVar2 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004fd1e0(iVar2 + 0xdc);
      if (iVar3 == 0) {
        iVar3 = FUN_004fd1e0(iVar2 + 0xec);
      }
    }
  }
  param_1[0x1a] = iVar3;
  DAT_00734f64 = param_1;
  DAT_00734f68 = 0;
  ExceptionList = local_10;
  return param_1;
}


