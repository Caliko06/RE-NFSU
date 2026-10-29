// ==== 0x631180 FUN_00631180

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00631180(ushort *param_1,float *param_2)

{
  *param_2 = (float)*param_1 * 3.0518044e-05 - _K_ONE;
  param_2[1] = (float)param_1[1] * 3.0518044e-05 - _K_ONE;
  param_2[2] = (float)param_1[2] * 3.0518044e-05 - _K_ONE;
  param_2[3] = (float)param_1[3] * 3.0518044e-05;
  param_2[4] = (float)param_1[4] * 3.0518044e-05;
  param_2[5] = (float)param_1[5] * 3.0518044e-05;
  return;
}


// ==== 0x631210 FUN_00631210

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00631210(int param_1,float *param_2)

{
  float fVar1;
  
  fVar1 = param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2;
  if (_K_ONE < fVar1) {
    param_2[3] = 0.0;
    fVar1 = _K_ONE / SQRT(fVar1);
    *param_2 = fVar1 * *param_2;
    param_2[1] = fVar1 * param_2[1];
    param_2[2] = fVar1 * param_2[2];
    return;
  }
  fVar1 = _K_ONE - fVar1;
  param_2[3] = SQRT(fVar1);
  if (0 < param_1) {
    param_2[3] = -SQRT(fVar1);
    return;
  }
  return;
}


// ==== 0x631280 FUN_00631280

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00631280(ushort *param_1,float *param_2)

{
  *param_2 = (float)(*param_1 >> 1) * 6.103702e-05 - _K_ONE;
  param_2[1] = (float)param_1[1] * 3.0518044e-05 - _K_ONE;
  param_2[2] = (float)param_1[2] * 3.0518044e-05 - _K_ONE;
  FUN_00631210((byte)*param_1 & 1,param_2);
  return;
}


// ==== 0x631300 FUN_00631300

uint __fastcall FUN_00631300(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (uint)*(byte *)(param_1 + 6);
  uVar4 = 1 << (*(byte *)(param_1 + 0x10) & 0x1f);
  uVar2 = (uint)*(ushort *)(param_1 + 4) % uVar4;
  iVar1 = param_1 + ((uVar4 + 1) * uVar3 * 3 + 1 & 0xfffffffe) * (*(ushort *)(param_1 + 4) / uVar4)
          + 0x12 + uVar3 * 0xc;
  if (0 < (int)uVar2) {
    iVar1 = iVar1 + (uVar2 + 1) * uVar3 * 3;
  }
  return *(byte *)(param_1 + 7) + 1 + iVar1 & 0xfffffffe;
}


// ==== 0x631360 FUN_00631360

undefined4 * __fastcall FUN_00631360(undefined4 *param_1)

{
  FUN_00628eb0();
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  *param_1 = &PTR_FUN_006a8388;
  param_1[6] = 0xffffffff;
  param_1[7] = 0xffffffff;
  param_1[2] = 0x11;
  return param_1;
}


// ==== 0x6313a0 FUN_006313a0

undefined4 __thiscall FUN_006313a0(int param_1,float *param_2)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar2 + 8) == 0) {
    uVar1 = *(ushort *)(iVar2 + 4);
    *param_2 = (float)uVar1;
    return CONCAT31((uint3)(byte)(uVar1 >> 8),1);
  }
  iVar2 = *(ushort *)(*(int *)(iVar2 + 8) + -4 + (uint)*(ushort *)(iVar2 + 4) * 2) + 1;
  *param_2 = (float)iVar2;
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}


// ==== 0x6313f0 FUN_006313f0

void __thiscall FUN_006313f0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(*param_1 + 0x48))(param_3,0,param_4);
  return;
}


// ==== 0x631410 FUN_00631410

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00631410(float *param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *in_EAX;
  
  fVar2 = (*param_2 - *in_EAX) * param_3 + *in_EAX;
  fVar5 = (param_2[1] - in_EAX[1]) * param_3 + in_EAX[1];
  fVar1 = (param_2[2] - in_EAX[2]) * param_3 + in_EAX[2];
  fVar4 = (param_2[3] - in_EAX[3]) * param_3 + in_EAX[3];
  fVar3 = _K_ONE / SQRT(fVar2 * fVar2 + fVar5 * fVar5 + fVar1 * fVar1 + fVar4 * fVar4);
  *param_1 = fVar3 * fVar2;
  param_1[1] = fVar3 * fVar5;
  param_1[2] = fVar3 * fVar1;
  param_1[3] = fVar3 * fVar4;
  return;
}


// ==== 0x6314c0 FUN_006314c0

void __thiscall FUN_006314c0(int param_1,int *param_2,int *param_3,int *param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  *param_2 = param_1 + 0x12;
  *param_3 = param_1 + 0x12 + (uint)*(byte *)(param_1 + 6) * 0xc;
  uVar4 = (uint)*(byte *)(param_1 + 6);
  uVar5 = 1 << (*(byte *)(param_1 + 0x10) & 0x1f);
  uVar3 = (uint)*(ushort *)(param_1 + 4) % uVar5;
  iVar2 = param_1 + ((uVar5 + 1) * uVar4 * 3 + 1 & 0xfffffffe) * (*(ushort *)(param_1 + 4) / uVar5)
          + 0x12 + uVar4 * 0xc;
  if (0 < (int)uVar3) {
    iVar2 = iVar2 + (uVar3 + 1) * uVar4 * 3;
  }
  *param_4 = iVar2;
  uVar1 = FUN_00631300();
  *param_5 = uVar1;
  return;
}


// ==== 0x631540 FUN_00631540

undefined4 * __thiscall FUN_00631540(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a8388;
  if (param_1[8] != 0) {
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[8]);
  }
  FUN_00628ed0();
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x30);
  }
  return param_1;
}


// ==== 0x631580 FUN_00631580

void __fastcall FUN_00631580(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_ESI;
  int local_4;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar1 = *(int *)(param_1 + 0xc);
    local_4 = param_1;
    FUN_006314c0(&local_4,param_1 + 0x14,param_1 + 0x28,param_1 + 0x2c);
    *(uint *)(param_1 + 0x18) =
         ((1 << (*(byte *)(iVar1 + 0x10) & 0x1f)) + 1) * (uint)*(byte *)(iVar1 + 6) * 3 + 1 &
         0xfffffffe;
    if (*(byte *)(iVar1 + 6) != 0) {
      uVar2 = (**(code **)(*DAT_0070d364 + 0x14))((uint)*(byte *)(iVar1 + 6) << 4);
      *(undefined4 *)(param_1 + 0x20) = uVar2;
      *(undefined4 *)(param_1 + 0x24) = uVar2;
      *(undefined4 *)(param_1 + 0x10) = unaff_ESI;
    }
  }
  return;
}


// ==== 0x6315f0 FUN_006315f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_006315f0(int *param_1,float param_2,int param_3,byte *param_4)

{
  byte *pbVar1;
  undefined4 *puVar2;
  float fVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  int iVar8;
  ushort *puVar9;
  bool bVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  float *pfVar14;
  ushort *puVar15;
  int iVar16;
  uint uVar17;
  byte *pbVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  undefined4 *puVar22;
  int iStack_4c;
  int iStack_48;
  int iStack_40;
  uint uStack_3c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (param_4 != (byte *)0x0) {
    uVar11 = (**(code **)(*param_1 + 0x48))(param_2,param_4,param_3);
    return uVar11;
  }
  uVar11 = FUN_00631580();
  iVar8 = param_1[3];
  pbVar18 = (byte *)CONCAT31((int3)((uint)uVar11 >> 8),*(char *)(iVar8 + 6));
  if (*(char *)(iVar8 + 6) == '\0') goto LAB_00631dbd;
  uVar12 = FUN_00629350(param_2);
  puVar9 = *(ushort **)(iVar8 + 8);
  if (puVar9 == (ushort *)0x0) {
    if ((int)uVar12 < 0) {
      param_4 = (byte *)0x0;
    }
    else {
      param_4 = (byte *)uVar12;
      if ((int)(uint)*(ushort *)(iVar8 + 4) <= (int)uVar12) {
        param_4 = (byte *)(*(ushort *)(iVar8 + 4) - 1);
      }
    }
  }
  else if ((int)uVar12 < (int)(uint)*puVar9) {
    param_4 = (byte *)0x0;
  }
  else {
    if (param_1[7] < 1) {
      iVar19 = 0;
    }
    else {
      iVar19 = param_1[7] + -1;
    }
    puVar15 = puVar9 + iVar19;
    if ((int)uVar12 < (int)(uint)puVar9[iVar19]) {
      for (; (0 < iVar19 && ((int)uVar12 < (int)(uint)*puVar15)); puVar15 = puVar15 + -1) {
        iVar19 = iVar19 + -1;
      }
    }
    else {
      while ((iVar19 < (int)(*(ushort *)(iVar8 + 4) - 2) &&
             (puVar15 = puVar15 + 1, (int)(uint)*puVar15 <= (int)uVar12))) {
        iVar19 = iVar19 + 1;
      }
    }
    param_4 = (byte *)(iVar19 + 1);
  }
  bVar4 = *(byte *)(iVar8 + 0x10);
  uVar17 = 0x7fffffff >> (0x1f - bVar4 & 0x1f);
  iVar16 = (int)param_4 >> (bVar4 & 0x1f);
  uVar13 = uVar17 & (uint)param_4;
  uStack_3c = param_1[7];
  iVar20 = param_1[6] * iVar16 + param_1[5];
  iVar19 = *(int *)(iVar8 + 0xc);
  if (((int)param_4 < (int)uStack_3c) && (DAT_006e58d8 == '\0')) {
    bVar10 = true;
  }
  else {
    bVar10 = false;
  }
  if ((((uStack_3c == 0xffffffff) || (iVar16 != (int)uStack_3c >> (bVar4 & 0x1f))) || (uVar13 == 0))
     || (bVar10)) {
    iStack_40 = 0;
    if (*(char *)(iVar8 + 6) != '\0') {
      iVar21 = 0;
      do {
        FUN_00631280(param_1[9] + iVar21);
        iStack_40 = iStack_40 + 1;
        iVar21 = iVar21 + 0x10;
      } while (iStack_40 < (int)(uint)*(byte *)(iVar8 + 6));
    }
    uStack_3c = 0;
  }
  else {
    uStack_3c = uStack_3c & uVar17;
  }
  if ((int)uStack_3c < (int)uVar13) {
    uVar17 = (uint)*(byte *)(iVar8 + 6);
    pbVar18 = (byte *)(iVar20 + (uStack_3c + 2) * uVar17 * 3);
    uStack_3c = uVar13 - uStack_3c;
    do {
      iStack_40 = 0;
      if (uVar17 != 0) {
        iVar21 = 0;
        do {
          FUN_00631180(&fStack_18);
          bVar5 = *pbVar18;
          bVar6 = pbVar18[1];
          pbVar1 = pbVar18 + 2;
          pbVar18 = pbVar18 + 3;
          iStack_40 = iStack_40 + 1;
          fStack_20 = (float)*pbVar1 * fStack_4 * 0.003921569 + fStack_10;
          *(float *)(iVar21 + param_1[9]) =
               (float)(bVar5 >> 1) * fStack_c * 0.007874016 + fStack_18 +
               *(float *)(iVar21 + param_1[9]);
          pfVar14 = (float *)(iVar21 + 4 + param_1[9]);
          *pfVar14 = (float)bVar6 * fStack_8 * 0.003921569 + fStack_14 + *pfVar14;
          pfVar14 = (float *)(iVar21 + 8 + param_1[9]);
          iVar21 = iVar21 + 0x10;
          *pfVar14 = fStack_20 + *pfVar14;
          uVar17 = (uint)*(byte *)(iVar8 + 6);
        } while (iStack_40 < (int)uVar17);
      }
      uStack_3c = uStack_3c + -1;
    } while (uStack_3c != 0);
    pbVar18 = (byte *)(iVar20 + (uVar13 + 1) * (uint)*(byte *)(iVar8 + 6) * 3);
    iVar20 = 0;
    if (*(byte *)(iVar8 + 6) != 0) {
      iVar21 = 0;
      do {
        fVar3 = *(float *)(param_1[9] + 8 + iVar21);
        pfVar14 = (float *)(param_1[9] + iVar21);
        bVar5 = *pbVar18;
        fVar3 = fVar3 * fVar3 + pfVar14[1] * pfVar14[1] + *pfVar14 * *pfVar14;
        if (fVar3 <= _K_ONE) {
          fVar3 = _K_ONE - fVar3;
          pfVar14[3] = SQRT(fVar3);
          if ((bVar5 & 1) != 0) {
            pfVar14[3] = -SQRT(fVar3);
          }
        }
        else {
          pfVar14[3] = 0.0;
          fVar3 = _K_ONE / SQRT(fVar3);
          *pfVar14 = fVar3 * *pfVar14;
          pfVar14[1] = fVar3 * pfVar14[1];
          pfVar14[2] = fVar3 * pfVar14[2];
        }
        pbVar18 = pbVar18 + 3;
        iVar20 = iVar20 + 1;
        iVar21 = iVar21 + 0x10;
      } while (iVar20 < (int)(uint)*(byte *)(iVar8 + 6));
    }
  }
  else if ((int)uVar13 < (int)uStack_3c) {
    pbVar18 = (byte *)((uStack_3c + 2) * (uint)*(byte *)(iVar8 + 6) * 3 + -3 + iVar20);
    if ((int)uVar13 <= (int)(uStack_3c - 1)) {
      iStack_40 = ((uStack_3c - 1) - uVar13) + 1;
      do {
        uStack_3c = (uint)*(byte *)(iVar8 + 6);
        if (-1 < (int)(uStack_3c - 1)) {
          iVar21 = (uStack_3c - 1) * 0x10;
          do {
            FUN_00631180(&fStack_18);
            bVar5 = *pbVar18;
            bVar6 = pbVar18[1];
            pbVar1 = pbVar18 + 2;
            pbVar18 = pbVar18 + -3;
            fStack_20 = (float)*pbVar1 * fStack_4 * 0.003921569 + fStack_10;
            *(float *)(iVar21 + param_1[9]) =
                 *(float *)(iVar21 + param_1[9]) -
                 ((float)(bVar5 >> 1) * fStack_c * 0.007874016 + fStack_18);
            *(float *)(iVar21 + 4 + param_1[9]) =
                 *(float *)(iVar21 + 4 + param_1[9]) -
                 ((float)bVar6 * fStack_8 * 0.003921569 + fStack_14);
            pfVar14 = (float *)(iVar21 + 8 + param_1[9]);
            iVar21 = iVar21 + -0x10;
            *pfVar14 = *pfVar14 - fStack_20;
            uStack_3c = uStack_3c - 1;
          } while (uStack_3c != 0);
        }
        iStack_40 = iStack_40 + -1;
      } while (iStack_40 != 0);
    }
    pbVar18 = (byte *)(iVar20 + (uVar13 + 1) * (uint)*(byte *)(iVar8 + 6) * 3);
    iVar20 = 0;
    if (*(byte *)(iVar8 + 6) != 0) {
      iStack_48 = 0;
      do {
        FUN_00631210(*pbVar18 & 1,param_1[9] + iStack_48);
        pbVar18 = pbVar18 + 3;
        iVar20 = iVar20 + 1;
        iStack_48 = iStack_48 + 0x10;
      } while (iVar20 < (int)(uint)*(byte *)(iVar8 + 6));
    }
  }
  param_1[7] = (int)param_4;
  puVar9 = *(ushort **)(iVar8 + 8);
  iVar20 = 0;
  if (puVar9 == (ushort *)0x0) {
    if (param_2 != (float)(int)uVar12) {
      param_2 = param_2 - (float)(int)uVar12;
      goto LAB_00631b59;
    }
  }
  else if (param_4 == (byte *)0x0) {
    if (param_2 != 0.0) {
      param_2 = param_2 / (float)*puVar9;
LAB_00631b59:
      if ((int)param_4 < (int)(*(ushort *)(iVar8 + 4) - 1)) {
        iVar19 = (int)((int)param_4 + 1U) >> (bVar4 & 0x1f);
        if (iVar19 == iVar16) {
          pbVar18 = (byte *)(param_1[6] * iVar19 + param_1[5] +
                            (uVar13 + 2) * (uint)*(byte *)(iVar8 + 6) * 3);
          if (*(byte *)(iVar8 + 6) != 0) {
            iStack_4c = 0;
            param_4 = pbVar18;
            do {
              FUN_00631180(&fStack_18);
              pfVar14 = (float *)(iStack_4c + param_1[9]);
              fStack_28 = (float)(*param_4 >> 1) * fStack_c * 0.007874016 + fStack_18 + *pfVar14;
              fStack_24 = (float)param_4[1] * fStack_8 * 0.003921569 + fStack_14 + pfVar14[1];
              fStack_20 = (float)param_4[2] * fStack_4 * 0.003921569 + fStack_10 + pfVar14[2];
              fVar3 = fStack_28 * fStack_28 + fStack_24 * fStack_24 + fStack_20 * fStack_20;
              if (fVar3 <= _K_ONE) {
                fStack_1c = SQRT(_K_ONE - fVar3);
                if ((*param_4 & 1) != 0) {
                  fStack_1c = -fStack_1c;
                }
              }
              else {
                fStack_1c = 0.0;
                fVar3 = _K_ONE / SQRT(fVar3);
                fStack_28 = fStack_28 * fVar3;
                fStack_24 = fStack_24 * fVar3;
                fStack_20 = fVar3 * fStack_20;
              }
              FUN_00631410(param_2);
              pbVar18 = (byte *)(uint)*(byte *)(iVar8 + 6);
              param_4 = param_4 + 3;
              iVar20 = iVar20 + 1;
              iStack_4c = iStack_4c + 0x10;
            } while (iVar20 < (int)pbVar18);
          }
        }
        else {
          pbVar18 = (byte *)CONCAT31((int3)((uint)iVar19 >> 8),*(char *)(iVar8 + 6));
          if (*(char *)(iVar8 + 6) != '\0') {
            do {
              FUN_00631280(&fStack_28);
              FUN_00631410(param_2);
              pbVar18 = (byte *)(uint)*(byte *)(iVar8 + 6);
              iVar20 = iVar20 + 1;
            } while (iVar20 < (int)pbVar18);
          }
        }
        goto LAB_00631dbd;
      }
    }
  }
  else {
    fVar3 = (float)puVar9[(int)param_4 - 1];
    if (param_2 != fVar3) {
      param_2 = (param_2 - fVar3) / ((float)puVar9[(int)param_4] - fVar3);
      goto LAB_00631b59;
    }
  }
  pbVar18 = (byte *)0x0;
  if (*(char *)(iVar8 + 6) != '\0') {
    iVar16 = 0;
    do {
      puVar22 = (undefined4 *)(param_1[9] + iVar16);
      puVar2 = (undefined4 *)((uint)pbVar18[iVar19] * 0x30 + 0x10 + param_3);
      *puVar2 = *puVar22;
      puVar2[1] = puVar22[1];
      puVar2[2] = puVar22[2];
      puVar2[3] = puVar22[3];
      pbVar18 = pbVar18 + 1;
      iVar16 = iVar16 + 0x10;
    } while ((int)pbVar18 < (int)(uint)*(byte *)(iVar8 + 6));
  }
LAB_00631dbd:
  cVar7 = *(char *)(iVar8 + 7);
  uVar12 = CONCAT31((int3)((uint)pbVar18 >> 8),cVar7);
  if ((cVar7 != '\0') && (iVar19 = 0, cVar7 != '\0')) {
    do {
      FUN_00631280((uint)*(byte *)(param_1[10] + iVar19) * 0x30 + 0x10 + param_3);
      uVar12 = (uint)*(byte *)(iVar8 + 7);
      iVar19 = iVar19 + 1;
    } while (iVar19 < (int)uVar12);
  }
  return CONCAT31((int3)(uVar12 >> 8),1);
}


// ==== 0x631e10 FUN_00631e10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00631e10(int param_1,float param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  float fVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  ushort *puVar7;
  bool bVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  float *pfVar14;
  undefined4 *puVar15;
  ushort *puVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  byte *pbVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int local_44;
  int local_3c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  FUN_00631580();
  iVar6 = *(int *)(param_1 + 0xc);
  iVar23 = iVar6;
  if (*(char *)(iVar6 + 6) == '\0') goto LAB_0063269a;
  uVar9 = FUN_00629350(param_2);
  puVar7 = *(ushort **)(iVar6 + 8);
  if (puVar7 == (ushort *)0x0) {
    if ((int)uVar9 < 0) {
      uVar19 = 0;
    }
    else {
      uVar19 = uVar9;
      if ((int)(uint)*(ushort *)(iVar6 + 4) <= (int)uVar9) {
        uVar19 = *(ushort *)(iVar6 + 4) - 1;
      }
    }
  }
  else if ((int)uVar9 < (int)(uint)*puVar7) {
    uVar19 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x1c) < 1) {
      iVar12 = 0;
    }
    else {
      iVar12 = *(int *)(param_1 + 0x1c) + -1;
    }
    puVar16 = puVar7 + iVar12;
    if ((int)uVar9 < (int)(uint)puVar7[iVar12]) {
      for (; (0 < iVar12 && ((int)uVar9 < (int)(uint)*puVar16)); puVar16 = puVar16 + -1) {
        iVar12 = iVar12 + -1;
      }
    }
    else {
      while ((iVar12 < (int)(*(ushort *)(iVar6 + 4) - 2) &&
             (puVar16 = puVar16 + 1, (int)(uint)*puVar16 <= (int)uVar9))) {
        iVar12 = iVar12 + 1;
      }
    }
    uVar19 = iVar12 + 1;
  }
  bVar3 = *(byte *)(iVar6 + 0x10);
  uVar17 = 0x7fffffff >> (0x1f - bVar3 & 0x1f);
  uVar10 = uVar17 & uVar19;
  iVar21 = (int)uVar19 >> (bVar3 & 0x1f);
  uVar11 = *(uint *)(param_1 + 0x1c);
  iVar13 = *(int *)(param_1 + 0x18) * iVar21 + *(int *)(param_1 + 0x14);
  iVar12 = *(int *)(iVar6 + 0xc);
  if (((int)uVar19 < (int)uVar11) && (DAT_006e58d8 == '\0')) {
    bVar8 = true;
  }
  else {
    bVar8 = false;
  }
  if ((((uVar11 == 0xffffffff) || (iVar21 != (int)uVar11 >> (bVar3 & 0x1f))) || (uVar10 == 0)) ||
     (bVar8)) {
    iVar18 = 0;
    if (*(char *)(iVar6 + 6) != '\0') {
      iVar22 = 0;
      do {
        if ((*(uint *)(param_3 + ((int)(uint)*(byte *)(iVar18 + iVar12) >> 5) * 4) &
            1 << (*(byte *)(iVar18 + iVar12) & 0x1f)) != 0) {
          FUN_00631280(*(int *)(param_1 + 0x24) + iVar22);
        }
        iVar18 = iVar18 + 1;
        iVar22 = iVar22 + 0x10;
      } while (iVar18 < (int)(uint)*(byte *)(iVar6 + 6));
    }
    uVar11 = 0;
  }
  else {
    uVar11 = uVar11 & uVar17;
  }
  if ((int)uVar11 < (int)uVar10) {
    uVar17 = (uint)*(byte *)(iVar6 + 6);
    pbVar20 = (byte *)(iVar13 + (uVar11 + 2) * uVar17 * 3);
    local_3c = uVar10 - uVar11;
    do {
      iVar18 = 0;
      if (uVar17 != 0) {
        iVar22 = 0;
        do {
          if ((*(uint *)(param_3 + ((int)(uint)*(byte *)(iVar18 + iVar12) >> 5) * 4) &
              1 << (*(byte *)(iVar18 + iVar12) & 0x1f)) != 0) {
            FUN_00631180(&local_18);
            bVar4 = pbVar20[1];
            pfVar14 = (float *)(iVar22 + *(int *)(param_1 + 0x24));
            local_20 = (float)pbVar20[2] * local_4 * 0.003921569 + local_10;
            *pfVar14 = (float)(*pbVar20 >> 1) * local_c * 0.007874016 + local_18 + *pfVar14;
            pfVar14 = (float *)(iVar22 + 4 + *(int *)(param_1 + 0x24));
            *pfVar14 = (float)bVar4 * local_8 * 0.003921569 + local_14 + *pfVar14;
            pfVar14 = (float *)(iVar22 + 8 + *(int *)(param_1 + 0x24));
            *pfVar14 = local_20 + *pfVar14;
          }
          uVar17 = (uint)*(byte *)(iVar6 + 6);
          pbVar20 = pbVar20 + 3;
          iVar18 = iVar18 + 1;
          iVar22 = iVar22 + 0x10;
        } while (iVar18 < (int)uVar17);
      }
      local_3c = local_3c + -1;
    } while (local_3c != 0);
    pbVar20 = (byte *)(iVar13 + (uVar10 + 1) * (uint)*(byte *)(iVar6 + 6) * 3);
    iVar13 = 0;
    if (*(byte *)(iVar6 + 6) != 0) {
      iVar18 = 0;
      do {
        if ((*(uint *)(param_3 + ((int)(uint)*(byte *)(iVar13 + iVar12) >> 5) * 4) &
            1 << (*(byte *)(iVar13 + iVar12) & 0x1f)) != 0) {
          fVar2 = *(float *)(*(int *)(param_1 + 0x24) + 8 + iVar18);
          pfVar14 = (float *)(*(int *)(param_1 + 0x24) + iVar18);
          bVar4 = *pbVar20;
          fVar2 = fVar2 * fVar2 + pfVar14[1] * pfVar14[1] + *pfVar14 * *pfVar14;
          if (fVar2 <= _K_ONE) {
            fVar2 = _K_ONE - fVar2;
            pfVar14[3] = SQRT(fVar2);
            if ((bVar4 & 1) != 0) {
              pfVar14[3] = -SQRT(fVar2);
            }
          }
          else {
            pfVar14[3] = 0.0;
            fVar2 = _K_ONE / SQRT(fVar2);
            *pfVar14 = fVar2 * *pfVar14;
            pfVar14[1] = fVar2 * pfVar14[1];
            pfVar14[2] = fVar2 * pfVar14[2];
          }
        }
        pbVar20 = pbVar20 + 3;
        iVar13 = iVar13 + 1;
        iVar18 = iVar18 + 0x10;
      } while (iVar13 < (int)(uint)*(byte *)(iVar6 + 6));
    }
  }
  else if ((int)uVar10 < (int)uVar11) {
    pbVar20 = (byte *)((uVar11 + 2) * (uint)*(byte *)(iVar6 + 6) * 3 + -3 + iVar13);
    if ((int)uVar10 <= (int)(uVar11 - 1)) {
      local_3c = ((uVar11 - 1) - uVar10) + 1;
      do {
        iVar18 = *(byte *)(iVar6 + 6) - 1;
        if (-1 < iVar18) {
          iVar22 = iVar18 * 0x10;
          do {
            if ((*(uint *)(param_3 + ((int)(uint)*(byte *)(iVar12 + iVar18) >> 5) * 4) &
                1 << (*(byte *)(iVar12 + iVar18) & 0x1f)) != 0) {
              FUN_00631180(&local_18);
              bVar4 = pbVar20[1];
              pfVar14 = (float *)(iVar22 + *(int *)(param_1 + 0x24));
              local_20 = (float)pbVar20[2] * local_4 * 0.003921569 + local_10;
              *pfVar14 = *pfVar14 - ((float)(*pbVar20 >> 1) * local_c * 0.007874016 + local_18);
              *(float *)(iVar22 + 4 + *(int *)(param_1 + 0x24)) =
                   *(float *)(iVar22 + 4 + *(int *)(param_1 + 0x24)) -
                   ((float)bVar4 * local_8 * 0.003921569 + local_14);
              pfVar14 = (float *)(iVar22 + 8 + *(int *)(param_1 + 0x24));
              *pfVar14 = *pfVar14 - local_20;
            }
            pbVar20 = pbVar20 + -3;
            iVar18 = iVar18 + -1;
            iVar22 = iVar22 + -0x10;
          } while (-1 < iVar18);
        }
        local_3c = local_3c + -1;
      } while (local_3c != 0);
    }
    pbVar20 = (byte *)(iVar13 + (uVar10 + 1) * (uint)*(byte *)(iVar6 + 6) * 3);
    iVar13 = 0;
    if (*(byte *)(iVar6 + 6) != 0) {
      iVar18 = 0;
      do {
        if ((*(uint *)(param_3 + ((int)(uint)*(byte *)(iVar13 + iVar12) >> 5) * 4) &
            1 << (*(byte *)(iVar13 + iVar12) & 0x1f)) != 0) {
          FUN_00631210(*pbVar20 & 1,*(int *)(param_1 + 0x24) + iVar18);
        }
        pbVar20 = pbVar20 + 3;
        iVar13 = iVar13 + 1;
        iVar18 = iVar18 + 0x10;
      } while (iVar13 < (int)(uint)*(byte *)(iVar6 + 6));
    }
  }
  *(uint *)(param_1 + 0x1c) = uVar19;
  puVar7 = *(ushort **)(iVar6 + 8);
  iVar13 = 0;
  if (puVar7 == (ushort *)0x0) {
    if (param_2 != (float)(int)uVar9) {
      param_2 = param_2 - (float)(int)uVar9;
      goto LAB_006323d6;
    }
  }
  else if (uVar19 == 0) {
    if (param_2 != 0.0) {
      param_2 = param_2 / (float)*puVar7;
LAB_006323d6:
      if ((int)uVar19 < (int)(*(ushort *)(iVar6 + 4) - 1)) {
        iVar23 = (int)(uVar19 + 1) >> (bVar3 & 0x1f);
        if (iVar23 == iVar21) {
          pbVar20 = (byte *)(*(int *)(param_1 + 0x18) * iVar23 + *(int *)(param_1 + 0x14) +
                            (uVar10 + 2) * (uint)*(byte *)(iVar6 + 6) * 3);
          local_3c = 0;
          iVar23 = 0;
          if (*(byte *)(iVar6 + 6) != 0) {
            local_44 = 0;
            do {
              if ((*(uint *)(param_3 + ((int)(uint)*(byte *)(local_3c + iVar12) >> 5) * 4) &
                  1 << (*(byte *)(local_3c + iVar12) & 0x1f)) != 0) {
                FUN_00631180(&local_18);
                pfVar14 = (float *)(*(int *)(param_1 + 0x24) + local_44);
                local_28 = (float)(*pbVar20 >> 1) * local_c * 0.007874016 + local_18 + *pfVar14;
                local_24 = (float)pbVar20[1] * local_8 * 0.003921569 + local_14 + pfVar14[1];
                local_20 = (float)pbVar20[2] * local_4 * 0.003921569 + local_10 + pfVar14[2];
                fVar2 = local_28 * local_28 + local_24 * local_24 + local_20 * local_20;
                if (fVar2 <= _K_ONE) {
                  local_1c = SQRT(_K_ONE - fVar2);
                  if ((*pbVar20 & 1) != 0) {
                    local_1c = -local_1c;
                  }
                }
                else {
                  local_1c = 0.0;
                  fVar2 = _K_ONE / SQRT(fVar2);
                  local_28 = local_28 * fVar2;
                  local_24 = local_24 * fVar2;
                  local_20 = fVar2 * local_20;
                }
                FUN_00631410(param_2);
              }
              local_44 = local_44 + 0x10;
              pbVar20 = pbVar20 + 3;
              local_3c = local_3c + 1;
              iVar23 = local_3c;
            } while (local_3c < (int)(uint)*(byte *)(iVar6 + 6));
          }
        }
        else {
          iVar13 = 0;
          iVar23 = CONCAT31((int3)((uint)iVar21 >> 8),*(char *)(iVar6 + 6));
          if (*(char *)(iVar6 + 6) != '\0') {
            do {
              if ((*(uint *)(param_3 + ((int)(uint)*(byte *)(iVar13 + iVar12) >> 5) * 4) &
                  1 << (*(byte *)(iVar13 + iVar12) & 0x1f)) != 0) {
                FUN_00631280(&local_28);
                FUN_00631410(param_2);
              }
              iVar13 = iVar13 + 1;
              iVar23 = iVar6;
            } while (iVar13 < (int)(uint)*(byte *)(iVar6 + 6));
          }
        }
        goto LAB_0063269a;
      }
    }
  }
  else {
    fVar2 = (float)puVar7[uVar19 - 1];
    if (param_2 != fVar2) {
      param_2 = (param_2 - fVar2) / ((float)puVar7[uVar19] - fVar2);
      goto LAB_006323d6;
    }
  }
  if (*(char *)(iVar6 + 6) != '\0') {
    iVar21 = 0;
    do {
      bVar3 = *(byte *)(iVar13 + iVar12);
      if ((*(uint *)(param_3 + ((int)(uint)bVar3 >> 5) * 4) & 1 << (bVar3 & 0x1f)) != 0) {
        puVar15 = (undefined4 *)(*(int *)(param_1 + 0x24) + iVar21);
        puVar1 = (undefined4 *)((uint)bVar3 * 0x30 + 0x10 + param_4);
        *puVar1 = *puVar15;
        puVar1[1] = puVar15[1];
        puVar1[2] = puVar15[2];
        puVar1[3] = puVar15[3];
      }
      iVar13 = iVar13 + 1;
      iVar21 = iVar21 + 0x10;
    } while (iVar13 < (int)(uint)*(byte *)(iVar6 + 6));
  }
LAB_0063269a:
  cVar5 = *(char *)(iVar6 + 7);
  iVar23 = CONCAT31((int3)((uint)iVar23 >> 8),cVar5);
  if (cVar5 != '\0') {
    iVar12 = *(int *)(iVar6 + 0xc);
    iVar13 = 0;
    if (cVar5 != '\0') {
      do {
        bVar3 = *(byte *)(iVar13 + iVar12);
        if ((*(uint *)(param_3 + ((int)(uint)bVar3 >> 5) * 4) & 1 << (bVar3 & 0x1f)) != 0) {
          FUN_00631280((uint)*(byte *)(*(int *)(param_1 + 0x28) + iVar13) * 0x30 + 0x10 + param_4);
        }
        iVar13 = iVar13 + 1;
        iVar23 = iVar6;
      } while (iVar13 < (int)(uint)*(byte *)(iVar6 + 7));
    }
  }
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  return CONCAT31((int3)((uint)iVar23 >> 8),1);
}


// ==== 0x632710 FUN_00632710

void FUN_00632710(float *param_1,float *param_2,float *param_3)

{
  *param_3 = param_1[3] * *param_2 +
             param_2[1] * param_1[2] + (*param_1 * param_2[3] - param_2[2] * param_1[1]);
  param_3[1] = param_2[1] * param_1[3] +
               ((param_2[2] * *param_1 + param_1[1] * param_2[3]) - param_1[2] * *param_2);
  param_3[2] = param_1[1] * *param_2 +
               ((param_1[2] * param_2[3] + param_2[2] * param_1[3]) - param_2[1] * *param_1);
  param_3[3] = param_1[3] * param_2[3] -
               (param_2[2] * param_1[2] + param_2[1] * param_1[1] + *param_1 * *param_2);
  return;
}


// ==== 0x6327a0 FUN_006327a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006327a0(float *param_1,float *param_2,float *param_3)

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
  
  fVar8 = *param_1 + *param_1;
  fVar11 = param_1[1] + param_1[1];
  fVar10 = param_1[2] + param_1[2];
  fVar9 = fVar8 * param_1[3];
  fVar1 = param_1[3];
  fVar2 = param_1[3];
  fVar8 = fVar8 * *param_1;
  fVar3 = *param_1;
  fVar4 = *param_1;
  fVar5 = param_1[1];
  fVar6 = param_1[1];
  fVar7 = param_1[2];
  *param_3 = (fVar11 * fVar3 - fVar10 * fVar2) * param_2[1] +
             (fVar10 * fVar4 + fVar11 * fVar1) * param_2[2] +
             (_K_ONE - (fVar10 * fVar7 + fVar11 * fVar5)) * *param_2;
  param_3[1] = (fVar10 * fVar6 - fVar9) * param_2[2] +
               (fVar11 * fVar3 + fVar10 * fVar2) * *param_2 +
               (_K_ONE - (fVar10 * fVar7 + fVar8)) * param_2[1];
  fVar7 = _K_ONE - (fVar11 * fVar5 + fVar8);
  fVar2 = param_2[2];
  fVar3 = *param_2;
  fVar5 = param_2[1];
  param_3[3] = 1.0;
  param_3[2] = (fVar10 * fVar6 + fVar9) * fVar5 +
               (fVar10 * fVar4 - fVar11 * fVar1) * fVar3 + fVar7 * fVar2;
  return;
}


// ==== 0x632890 FUN_00632890

void __fastcall FUN_00632890(undefined4 *param_1)

{
  param_1[1] = 0;
  *param_1 = &PTR_FUN_006a83ec;
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0xffffff9c;
  param_1[0xe] = 0x3f800000;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0xffffff9c;
  *(undefined1 *)(param_1 + 0x16) = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[2] = 9;
  return;
}


// ==== 0x6328d0 FUN_006328d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_006328d0(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  char cVar3;
  float unaff_ESI;
  undefined4 unaff_retaddr;
  undefined1 local_10 [12];
  float *pfStack_4;
  
  cVar3 = (**(code **)(**(int **)(param_1 + 0x10) + 0x20))();
  if (cVar3 != '\0') {
    if (*(float *)(param_1 + 0x18) == 0.0) {
      *(undefined1 **)param_2 = local_10;
      *(float *)((int)param_2 + 4) = unaff_ESI;
      return 1;
    }
    cVar3 = (**(code **)(**(int **)(param_1 + 0x14) + 0x20))(unaff_retaddr);
    if (cVar3 != '\0') {
      fVar1 = _K_ONE - *(float *)(param_1 + 0x18);
      *pfStack_4 = (float)local_10 * fVar1 + (float)local_10 * *(float *)(param_1 + 0x18);
      fVar2 = param_2 * fVar1 + unaff_ESI * *(float *)(param_1 + 0x18);
      pfStack_4[1] = fVar2;
      fVar2 = SQRT(fVar2 * fVar2 + *pfStack_4 * *pfStack_4);
      if (fVar2 != 0.0) {
        fVar2 = (SQRT((float)local_10 * (float)local_10 + unaff_ESI * unaff_ESI) *
                 *(float *)(param_1 + 0x18) +
                SQRT((float)local_10 * (float)local_10 + param_2 * param_2) * fVar1) / fVar2;
        *pfStack_4 = fVar2 * *pfStack_4;
        pfStack_4[1] = fVar2 * pfStack_4[1];
        return 1;
      }
      return 1;
    }
  }
  return 0;
}


// ==== 0x6329f0 FUN_006329f0

void __thiscall FUN_006329f0(int param_1,undefined4 *param_2)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10 [2];
  undefined4 local_8;
  
  local_20 = *param_2;
  local_18 = param_2[1];
  local_1c = 0;
  local_14 = 0x3f800000;
  FUN_006327a0(param_1 + 0x48,&local_20,local_10);
  *param_2 = local_10[0];
  param_2[1] = local_8;
  return;
}


// ==== 0x632a40 FUN_00632a40

undefined4 __thiscall FUN_00632a40(int param_1,float *param_2)

{
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  float local_40 [2];
  float local_38;
  undefined1 local_30 [16];
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  FUN_00633720();
  FUN_00633720();
  FUN_00629140(*(undefined4 *)(param_1 + 0x18),local_20,local_30,local_10);
  local_50 = 0;
  local_4c = 0x3f800000;
  local_48 = 0;
  local_44 = 0x3f800000;
  FUN_006327a0(local_10,&local_50,local_40);
  *param_2 = local_40[0];
  param_2[1] = local_38;
  _printf_67147f("Facing: %g %g\n",(double)local_40[0],(double)local_38);
  return 1;
}


// ==== 0x632af0 FUN_00632af0

undefined4 __thiscall FUN_00632af0(int param_1,float *param_2)

{
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  float local_40 [2];
  float local_38;
  undefined1 local_30 [16];
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  FUN_00633740();
  FUN_00633740();
  FUN_00629140(*(undefined4 *)(param_1 + 0x18),local_20,local_30,local_10);
  local_50 = 0;
  local_4c = 0x3f800000;
  local_48 = 0;
  local_44 = 0x3f800000;
  FUN_006327a0(local_10,&local_50,local_40);
  *param_2 = local_40[0];
  param_2[1] = local_38;
  _printf_67147f("Facing: %g %g\n",(double)local_40[0],(double)local_38);
  return 1;
}


// ==== 0x632ba0 FUN_00632ba0

undefined4 * __thiscall FUN_00632ba0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a83ec;
  if (param_1[7] != 0) {
    FUN_00634150(1);
    FUN_00634120();
  }
  if (param_1[3] != 0) {
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[3]);
  }
  *param_1 = &PTR_FUN_006a7a94;
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x5c);
  }
  return param_1;
}


// ==== 0x632c00 FUN_00632c00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00632c00(int param_1,float param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  float10 fVar4;
  undefined4 local_8;
  
  if (param_2 < 0.0) {
    fVar1 = param_2 + 0.499999;
  }
  else {
    fVar1 = param_2 - 0.499999;
  }
  local_8 = (int)ROUND(fVar1);
  if (local_8 < 0) {
    local_8 = 0;
  }
  if (*(int *)(param_1 + 0x1c) + -1 <= local_8) {
    local_8 = *(int *)(param_1 + 0x1c) + -2;
  }
  *(float *)(param_1 + 0x18) = param_2 - (float)local_8;
  iVar2 = *(int *)(param_1 + 0x20);
  if (local_8 == iVar2) {
    fVar1 = *(float *)(param_1 + 0x38);
    *(float *)(param_1 + 0x38) =
         *(float *)(param_1 + 0x18) / *(float *)(param_1 + 0x2c) +
         (_K_ONE - *(float *)(param_1 + 0x18)) / *(float *)(param_1 + 0x28);
    goto LAB_00632d5c;
  }
  if (local_8 == iVar2 + 1) {
    uVar3 = *(undefined4 *)(param_1 + 0x14);
LAB_00632ccf:
    *(undefined4 *)(param_1 + 0x10) = uVar3;
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 4 + local_8 * 4);
  }
  else {
    if (local_8 != iVar2 + -1) {
      uVar3 = *(undefined4 *)(*(int *)(param_1 + 0xc) + local_8 * 4);
      goto LAB_00632ccf;
    }
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0xc) + local_8 * 4);
  }
  *(int *)(param_1 + 0x20) = local_8;
  iVar2 = *(int *)(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x20) * 4);
  fVar4 = (float10)FUN_00633630();
  *(float *)(param_1 + 0x28) = (float)((float10)_K_ONE / fVar4);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(iVar2 + 0x50);
  iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 4 + *(int *)(param_1 + 0x20) * 4);
  fVar4 = (float10)FUN_00633630();
  *(float *)(param_1 + 0x2c) = (float)((float10)_K_ONE / fVar4);
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(iVar2 + 0x50);
  fVar1 = *(float *)(param_1 + 0x38);
  *(float *)(param_1 + 0x38) =
       *(float *)(param_1 + 0x18) / *(float *)(param_1 + 0x2c) +
       (_K_ONE - *(float *)(param_1 + 0x18)) / *(float *)(param_1 + 0x28);
LAB_00632d5c:
  *(float *)(param_1 + 0x40) =
       ((*(float *)(param_1 + 0x40) + *(float *)(param_1 + 0x3c)) / *(float *)(param_1 + 0x38)) *
       fVar1 - *(float *)(param_1 + 0x3c);
  return;
}


// ==== 0x632d80 FUN_00632d80

int FUN_00632d80(float param_1,float param_2,float param_3)

{
  int iVar1;
  
  if (param_1 < param_2) {
    iVar1 = FUN_00629350((param_2 - param_1) / (param_3 - param_2));
    return iVar1;
  }
  if (param_3 <= param_1) {
    iVar1 = FUN_00629350((param_1 - param_3) / (param_3 - param_2));
    return iVar1 + 1;
  }
  return 0;
}


// ==== 0x632df0 FUN_00632df0

void __thiscall FUN_00632df0(int param_1,int param_2)

{
  int iVar1;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (*(char *)(param_1 + 0x58) == '\0') {
    *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x54) = 0x3f800000;
    *(undefined1 *)(param_1 + 0x58) = 1;
    return;
  }
  if (*(int *)(param_1 + 0x44) != param_2) {
    FUN_00632a40();
    FUN_00632af0();
    FUN_006332d0();
    FUN_00632710();
    *(float *)(param_1 + 0x48) = local_28;
    *(undefined4 *)(param_1 + 0x4c) = local_24;
    *(undefined4 *)(param_1 + 0x50) = local_20;
    iVar1 = DAT_0070d600;
    *(undefined4 *)(param_1 + 0x54) = local_1c;
    DAT_0070d600 = DAT_0070d600 + 1;
    *(int *)(param_1 + 0x44) = param_2;
    _printf_67147f("turn align[%d] Q: %g %g %g %g\n\n",iVar1,(double)*(float *)(param_1 + 0x48),
                   (double)*(float *)(param_1 + 0x4c),(double)*(float *)(param_1 + 0x50),
                   (double)*(float *)(param_1 + 0x54));
  }
  return;
}


// ==== 0x632ef0 FUN_00632ef0

undefined1 __thiscall FUN_00632ef0(int param_1,float param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  char cVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  float10 fVar8;
  undefined4 uStack_10;
  undefined4 uStack_8;
  
  *(float *)(param_1 + 0x3c) = param_2;
  if (*(int *)(param_1 + 0x10) == 0) {
    FUN_00632c00(0);
  }
  param_2 = param_2 + *(float *)(param_1 + 0x40);
  uVar6 = FUN_00632d80(param_2,0,2.0 / *(float *)(param_1 + 0x38));
  fVar1 = *(float *)(param_1 + 0x38);
  fVar2 = *(float *)(param_1 + 0x2c);
  fVar8 = (float10)FUN_00633ae0(*(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x38) * param_2,0,
                                *(float *)(param_1 + 0x28) + *(float *)(param_1 + 0x28));
  fVar3 = (float)(fVar8 - (float10)*(float *)(param_1 + 0x30));
  FUN_00633ae0(param_2 * fVar1 * fVar2,0,*(float *)(param_1 + 0x2c) + *(float *)(param_1 + 0x2c));
  FUN_00628c90(param_3,0);
  cVar5 = (**(code **)(**(int **)(param_1 + 0x10) + 0x18))(fVar3,param_3,0);
  if (cVar5 == '\0') {
    return 0;
  }
  if (*(float *)(param_1 + 0x18) != 0.0) {
    puVar7 = (undefined4 *)FUN_00634150(1);
    uVar4 = *puVar7;
    FUN_00628c90(uVar4,0);
    cVar5 = (**(code **)(**(int **)(param_1 + 0x14) + 0x18))(uStack_8,uVar4,0);
    if (cVar5 == '\0') {
      return 0;
    }
    FUN_0062a3e0(*(undefined4 *)(*(int *)(param_1 + 0x24) + 8),*(undefined4 *)(param_1 + 0x18),
                 param_3,uVar4,param_3,0);
  }
  FUN_00632df0(uVar6);
  FUN_00632710((undefined4 *)(param_3 + 0x10),param_1 + 0x48,&stack0xffffffe4);
  *(undefined4 *)(param_3 + 0x10) = unaff_EBP;
  *(undefined4 *)(param_3 + 0x14) = unaff_EBX;
  *(float *)(param_3 + 0x18) = fVar3;
  *(undefined4 *)(param_3 + 0x1c) = uStack_10;
  return 1;
}


// ==== 0x633060 FUN_00633060

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_00633060(int param_1,float param_2)

{
  char cVar1;
  
  *(float *)(param_1 + 0x3c) = param_2;
  if (*(int *)(param_1 + 0x10) == 0) {
    FUN_00632c00();
  }
  param_2 = param_2 + *(float *)(param_1 + 0x40);
  FUN_00632d80();
  _printf_67147f("currTime: %g  offset: %g   cycle: %g\n",(double)param_2,
                 (double)*(float *)(param_1 + 0x40),(double)(_K_ONE / *(float *)(param_1 + 0x38)));
  _printf_67147f("offset0: %g  offset1: %g\n",(double)*(float *)(param_1 + 0x30),
                 (double)*(float *)(param_1 + 0x34));
  _printf_67147f("cycle0: %g  cycle1: %g\n",(double)*(float *)(param_1 + 0x28),
                 (double)*(float *)(param_1 + 0x2c));
  _printf_67147f("before offset t0: %g  t1: %g\n",
                 (double)(*(float *)(param_1 + 0x38) * *(float *)(param_1 + 0x28) * param_2),
                 (double)(*(float *)(param_1 + 0x38) * *(float *)(param_1 + 0x2c) * param_2));
  FUN_00633ae0();
  FUN_00633ae0();
  cVar1 = FUN_006328d0();
  if (cVar1 == '\0') {
    return 0;
  }
  FUN_00632df0();
  FUN_006329f0();
  return 1;
}


// ==== 0x633063 FUN_00633063

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __fastcall FUN_00633063(int param_1)

{
  char cVar1;
  int unaff_EBP;
  
  *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(unaff_EBP + 8);
  if (*(int *)(param_1 + 0x10) == 0) {
    FUN_00632c00();
  }
  *(float *)(unaff_EBP + 8) = *(float *)(unaff_EBP + 8) + *(float *)(param_1 + 0x40);
  FUN_00632d80();
  _printf_67147f("currTime: %g  offset: %g   cycle: %g\n",(double)*(float *)(unaff_EBP + 8),
                 (double)*(float *)(param_1 + 0x40),(double)(_K_ONE / *(float *)(param_1 + 0x38)));
  _printf_67147f("offset0: %g  offset1: %g\n",(double)*(float *)(param_1 + 0x30),
                 (double)*(float *)(param_1 + 0x34));
  _printf_67147f("cycle0: %g  cycle1: %g\n",(double)*(float *)(param_1 + 0x28),
                 (double)*(float *)(param_1 + 0x2c));
  _printf_67147f("before offset t0: %g  t1: %g\n",
                 (double)(*(float *)(param_1 + 0x38) * *(float *)(param_1 + 0x28) *
                         *(float *)(unaff_EBP + 8)),
                 (double)(*(float *)(param_1 + 0x38) * *(float *)(param_1 + 0x2c) *
                         *(float *)(unaff_EBP + 8)));
  FUN_00633ae0();
  FUN_00633ae0();
  cVar1 = FUN_006328d0();
  if (cVar1 == '\0') {
    return 0;
  }
  FUN_00632df0();
  FUN_006329f0();
  return 1;
}


// ==== 0x6331b0 FUN_006331b0

void __fastcall FUN_006331b0(undefined4 *param_1)

{
  param_1[1] = 0;
  *param_1 = &PTR_FUN_006a84ec;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0xffffff9c;
  param_1[0x12] = 0x3f800000;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0xffffff9c;
  *(undefined1 *)(param_1 + 0x1a) = 0;
  param_1[0x1f] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[2] = 8;
  return;
}


// ==== 0x633200 FUN_00633200

void __fastcall FUN_00633200(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a84ec;
  if (param_1[6] != 0) {
    (**(code **)(*DAT_0070d364 + 0x2c))(param_1[6]);
  }
  if (param_1[7] != 0) {
    (**(code **)(*DAT_0070d364 + 0x2c))(param_1[7]);
  }
  if (param_1[8] != 0) {
    (**(code **)(*DAT_0070d364 + 0x2c))(param_1[8]);
  }
  if (param_1[9] != 0) {
    (**(code **)(*DAT_0070d364 + 0x2c))(param_1[9]);
  }
  if (param_1[0xb] != 0) {
    FUN_00634150(0);
    FUN_00634120();
  }
  if (param_1[3] != 0) {
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[3]);
  }
  if (param_1[4] != 0) {
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[4]);
  }
  if (param_1[5] != 0) {
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[5]);
  }
  if (param_1[0x1f] != 0) {
    (**(code **)(*DAT_0070d364 + 0x18))(param_1[0x1f]);
  }
  *param_1 = &PTR_FUN_006a7a94;
  return;
}


// ==== 0x6332d0 FUN_006332d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006332d0(float *param_1,float *param_2,undefined4 *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar7 = param_2[1];
  fVar1 = param_1[1];
  fVar8 = *param_2;
  fVar2 = *param_1;
  fVar3 = param_1[1];
  fVar4 = param_2[1];
  fVar5 = *param_1;
  fVar6 = *param_2;
  *param_3 = 0;
  param_3[2] = 0;
  fVar1 = ((fVar5 * fVar6 + fVar3 * fVar4) /
           (SQRT(fVar7 * fVar7 + fVar8 * fVar8) * SQRT(fVar1 * fVar1 + fVar2 * fVar2)) + _K_ONE) *
          _K_HALF;
  fVar2 = SQRT(_K_ONE - fVar1);
  param_3[1] = fVar2;
  param_3[3] = SQRT(fVar1);
  if (0.0 < *param_1 * param_2[1] - param_1[1] * *param_2) {
    param_3[1] = fVar2 * -1.0;
  }
  return;
}


// ==== 0x633390 FUN_00633390

void __thiscall FUN_00633390(int param_1,undefined4 *param_2)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10 [2];
  undefined4 local_8;
  
  local_20 = *param_2;
  local_18 = param_2[1];
  local_1c = 0;
  local_14 = 0x3f800000;
  FUN_006327a0(param_1 + 0x58,&local_20,local_10);
  *param_2 = local_10[0];
  param_2[1] = local_8;
  return;
}


// ==== 0x6333e0 FUN_006333e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_006333e0(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  char cVar3;
  float unaff_ESI;
  undefined4 unaff_retaddr;
  undefined1 local_10 [12];
  float *pfStack_4;
  
  cVar3 = (**(code **)(**(int **)(param_1 + 0x20) + 0x20))();
  if (cVar3 != '\0') {
    if (*(float *)(param_1 + 0x28) == 0.0) {
      *(undefined1 **)param_2 = local_10;
      *(float *)((int)param_2 + 4) = unaff_ESI;
      return 1;
    }
    cVar3 = (**(code **)(**(int **)(param_1 + 0x24) + 0x20))(unaff_retaddr);
    if (cVar3 != '\0') {
      fVar1 = _K_ONE - *(float *)(param_1 + 0x28);
      *pfStack_4 = (float)local_10 * fVar1 + (float)local_10 * *(float *)(param_1 + 0x28);
      fVar2 = param_2 * fVar1 + unaff_ESI * *(float *)(param_1 + 0x28);
      pfStack_4[1] = fVar2;
      fVar2 = SQRT(fVar2 * fVar2 + *pfStack_4 * *pfStack_4);
      if (fVar2 != 0.0) {
        fVar2 = (SQRT((float)local_10 * (float)local_10 + unaff_ESI * unaff_ESI) *
                 *(float *)(param_1 + 0x28) +
                SQRT((float)local_10 * (float)local_10 + param_2 * param_2) * fVar1) / fVar2;
        *pfStack_4 = fVar2 * *pfStack_4;
        pfStack_4[1] = fVar2 * pfStack_4[1];
        return 1;
      }
      return 1;
    }
  }
  return 0;
}


// ==== 0x633500 FUN_00633500

undefined1 __thiscall FUN_00633500(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  undefined4 *unaff_retaddr;
  undefined4 uStack_3c;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_4;
  
  uStack_3c = 0;
  piVar4 = (int *)FUN_00634150();
  iVar2 = *piVar4;
  uStack_3c = 0;
  cVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 0x18))(param_2,iVar2);
  if (cVar3 == '\0') {
    return 0;
  }
  puVar1 = (undefined4 *)(iVar2 + 0x10);
  uStack_1c = *puVar1;
  uStack_18 = *(undefined4 *)(iVar2 + 0x14);
  uStack_14 = *(undefined4 *)(iVar2 + 0x18);
  uStack_10 = *(undefined4 *)(iVar2 + 0x1c);
  if (*(float *)(param_1 + 0x28) == 0.0) {
    uStack_3c = *puVar1;
  }
  else {
    FUN_00628c90(iVar2,0);
    cVar3 = (**(code **)(**(int **)(param_1 + 0x1c) + 0x18))(uStack_4,iVar2,0);
    if (cVar3 == '\0') {
      return 0;
    }
    uStack_28 = *(undefined4 *)(iVar2 + 0x14);
    uStack_2c = *puVar1;
    uStack_24 = *(undefined4 *)(iVar2 + 0x18);
    uStack_20 = *(undefined4 *)(iVar2 + 0x1c);
    FUN_00629140(*(undefined4 *)(param_1 + 0x28),&uStack_1c,&uStack_2c,&uStack_3c);
  }
  uStack_1c = 0;
  uStack_18 = 0x3f800000;
  uStack_14 = 0;
  uStack_10 = 0x3f800000;
  FUN_006327a0(&uStack_3c,&uStack_1c,&uStack_2c);
  *unaff_retaddr = uStack_2c;
  unaff_retaddr[1] = uStack_24;
  return 1;
}


// ==== 0x633630 FUN_00633630

float10 __fastcall FUN_00633630(int param_1)

{
  return (float10)*(float *)(param_1 + 0x48);
}


// ==== 0x633640 FUN_00633640

void __fastcall FUN_00633640(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char cVar5;
  int *piVar6;
  undefined4 *unaff_retaddr;
  undefined4 uStack_c;
  undefined4 uStack_4;
  
  piVar6 = (int *)FUN_00634150();
  iVar1 = *piVar6;
  cVar5 = (**(code **)(**(int **)(param_1 + 0x18) + 0x18))();
  if (cVar5 != '\0') {
    uVar2 = *(undefined4 *)(iVar1 + 0x14);
    uVar3 = *(undefined4 *)(iVar1 + 0x18);
    uVar4 = *(undefined4 *)(iVar1 + 0x1c);
    if (*(float *)(param_1 + 0x28) == 0.0) {
      *unaff_retaddr = *(undefined4 *)(iVar1 + 0x10);
      unaff_retaddr[1] = uVar2;
      unaff_retaddr[2] = uVar3;
      unaff_retaddr[3] = uVar4;
    }
    else {
      FUN_00628c90(iVar1,0);
      cVar5 = (**(code **)(**(int **)(param_1 + 0x1c) + 0x18))(uStack_4,iVar1,0);
      if (cVar5 != '\0') {
        FUN_00629140(*(undefined4 *)(param_1 + 0x28),&stack0xffffffc8,&stack0xffffffd8,uStack_c);
        return;
      }
    }
  }
  return;
}


// ==== 0x633720 FUN_00633720

void FUN_00633720(undefined4 param_1)

{
  FUN_00633640(0,0,param_1);
  return;
}


// ==== 0x633740 FUN_00633740

void __thiscall FUN_00633740(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x30) * 4);
  FUN_00633640((float)(int)(*(ushort *)(*piVar1 + 4) - 1),
               (float)(int)(*(ushort *)(piVar1[1] + 4) - 1),param_2);
  return;
}


// ==== 0x633780 FUN_00633780

undefined4 __thiscall FUN_00633780(undefined4 param_1,byte param_2)

{
  FUN_00633200();
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x80);
  }
  return param_1;
}


// ==== 0x6337b0 FUN_006337b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_006337b0(int param_1,float param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int unaff_ESI;
  int local_8;
  
  if (param_2 < 0.0) {
    fVar1 = param_2 + 0.499999;
  }
  else {
    fVar1 = param_2 - 0.499999;
  }
  local_8 = (int)ROUND(fVar1);
  if (local_8 < 0) {
    local_8 = 0;
  }
  if (*(int *)(param_1 + 0x2c) + -1 <= local_8) {
    local_8 = *(int *)(param_1 + 0x2c) + -2;
  }
  *(float *)(param_1 + 0x28) = param_2 - (float)local_8;
  iVar2 = *(int *)(param_1 + 0x30);
  if (local_8 == iVar2) goto LAB_00633aa1;
  if (local_8 == iVar2 + 1) {
    (**(code **)(*DAT_0070d364 + 0x2c))(*(undefined4 *)(param_1 + 0x18));
    *(undefined4 *)(unaff_ESI + 0x18) = *(undefined4 *)(unaff_ESI + 0x1c);
LAB_006338e1:
    uVar3 = (**(code **)(*DAT_0070d364 + 0x24))
                      (*(undefined4 *)(*(int *)(unaff_ESI + 0xc) + 4 + local_8 * 4));
    *(undefined4 *)(param_1 + 0x1c) = uVar3;
  }
  else {
    if (local_8 != iVar2 + -1) {
      if (*(int *)(param_1 + 0x18) != 0) {
        (**(code **)(*DAT_0070d364 + 0x2c))(*(int *)(param_1 + 0x18));
      }
      if (*(int *)(param_1 + 0x1c) != 0) {
        (**(code **)(*DAT_0070d364 + 0x2c))(*(int *)(param_1 + 0x1c));
      }
      uVar3 = (**(code **)(*DAT_0070d364 + 0x24))
                        (*(undefined4 *)(*(int *)(param_1 + 0xc) + local_8 * 4));
      *(undefined4 *)(unaff_ESI + 0x18) = uVar3;
      goto LAB_006338e1;
    }
    (**(code **)(*DAT_0070d364 + 0x2c))(*(undefined4 *)(param_1 + 0x1c));
    *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(unaff_ESI + 0x18);
    uVar3 = (**(code **)(*DAT_0070d364 + 0x24))
                      (*(undefined4 *)(*(int *)(unaff_ESI + 0xc) + local_8 * 4));
    *(undefined4 *)(param_1 + 0x18) = uVar3;
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    if (local_8 == *(int *)(param_1 + 0x30) + 1) {
      (**(code **)(*DAT_0070d364 + 0x2c))(*(undefined4 *)(param_1 + 0x20));
      *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(unaff_ESI + 0x24);
    }
    else {
      if (local_8 == *(int *)(param_1 + 0x30) + -1) {
        (**(code **)(*DAT_0070d364 + 0x2c))(*(undefined4 *)(param_1 + 0x24));
        *(undefined4 *)(unaff_ESI + 0x24) = *(undefined4 *)(unaff_ESI + 0x20);
        uVar3 = (**(code **)(*DAT_0070d364 + 0x24))
                          (*(undefined4 *)(*(int *)(unaff_ESI + 0x14) + local_8 * 4));
        *(undefined4 *)(param_1 + 0x20) = uVar3;
        goto LAB_006339d3;
      }
      if (*(int *)(param_1 + 0x20) != 0) {
        FUN_0047b020(*(int *)(param_1 + 0x20));
      }
      if (*(int *)(param_1 + 0x24) != 0) {
        FUN_0047b020(*(int *)(param_1 + 0x24));
      }
      uVar3 = (**(code **)(*DAT_0070d364 + 0x24))
                        (*(undefined4 *)(*(int *)(param_1 + 0x14) + local_8 * 4));
      *(undefined4 *)(unaff_ESI + 0x20) = uVar3;
    }
    uVar3 = (**(code **)(*DAT_0070d364 + 0x24))
                      (*(undefined4 *)(*(int *)(unaff_ESI + 0x14) + 4 + local_8 * 4));
    *(undefined4 *)(param_1 + 0x24) = uVar3;
  }
LAB_006339d3:
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + local_8 * 4);
  if ((*(byte *)(iVar2 + 8) & 1) == 0) {
    uVar4 = (uint)*(byte *)(iVar2 + 10) + (uint)*(ushort *)(iVar2 + 6);
  }
  else {
    uVar4 = (uint)*(ushort *)(iVar2 + 6);
  }
  *(float *)(param_1 + 0x38) = (float)uVar4;
  *(float *)(param_1 + 0x3c) =
       (float)*(ushort *)(*(int *)(*(int *)(param_1 + 0x10) + 4 + local_8 * 4) + 6);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 4 + local_8 * 4);
  if ((*(byte *)(iVar2 + 8) & 1) == 0) {
    *(float *)(param_1 + 0x3c) = (float)*(byte *)(iVar2 + 10) + *(float *)(param_1 + 0x3c);
  }
  *(int *)(param_1 + 0x30) = local_8;
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x30) * 4);
  *(float *)(param_1 + 0x40) =
       (float)((uint)*(byte *)(iVar2 + 0xb) + (uint)*(byte *)(iVar2 + 10)) * _K_HALF;
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 4 + *(int *)(param_1 + 0x30) * 4);
  *(float *)(param_1 + 0x44) =
       (float)((uint)*(byte *)(iVar2 + 0xb) + (uint)*(byte *)(iVar2 + 10)) * _K_HALF;
LAB_00633aa1:
  fVar1 = *(float *)(param_1 + 0x48);
  *(float *)(param_1 + 0x48) =
       *(float *)(param_1 + 0x28) / *(float *)(param_1 + 0x44) +
       (_K_ONE - *(float *)(param_1 + 0x28)) / *(float *)(param_1 + 0x40);
  *(float *)(param_1 + 0x50) =
       ((*(float *)(param_1 + 0x50) + *(float *)(param_1 + 0x4c)) / *(float *)(param_1 + 0x48)) *
       fVar1 - *(float *)(param_1 + 0x4c);
  return;
}


// ==== 0x633ae0 FUN_00633ae0

float10 FUN_00633ae0(float param_1,float param_2,float param_3)

{
  float fVar1;
  int iVar2;
  
  fVar1 = param_3 - param_2;
  if (param_1 < param_2) {
    iVar2 = FUN_00629350((param_2 - param_1) / fVar1);
    return (float10)param_3 - ((float10)(param_2 - param_1) - (float10)iVar2 * (float10)fVar1);
  }
  if (param_3 <= param_1) {
    iVar2 = FUN_00629350((param_1 - param_3) / fVar1);
    return ((float10)(param_1 - param_3) - (float10)iVar2 * (float10)fVar1) + (float10)param_2;
  }
  return (float10)param_1;
}


// ==== 0x633b80 FUN_00633b80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00633b80(int *param_1,undefined4 *param_2)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  float unaff_ESI;
  float fVar4;
  float *unaff_retaddr;
  float fVar5;
  float afStack_20 [2];
  float fStack_18;
  int *piStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  undefined4 uStack_4;
  
  afStack_20[0] = 0.0;
  fStack_8 = ((float)param_1[0x11] - (float)param_1[0x10]) * (float)param_1[10] +
             (float)param_1[0x10];
  fStack_8 = fStack_8 + fStack_8;
  if (fStack_8 < 0.0) {
    fStack_8 = fStack_8 + 0.499999;
  }
  else {
    fStack_8 = fStack_8 - 0.499999;
  }
  fStack_c = (float)(int)ROUND(fStack_8);
  fStack_18 = (float)*param_2;
  uStack_4 = param_2[1];
  fStack_10 = fStack_c;
  fVar4 = fStack_c;
  piStack_14 = param_1;
  if ((0.0 < (float)param_2[2]) && ((float)param_2[2] < (float)(int)fStack_c)) {
    iVar3 = FUN_00629350(param_2[2]);
    fVar4 = (float)(iVar3 + 1);
  }
  (**(code **)(*param_1 + 0x1c))(0,afStack_20);
  fVar5 = afStack_20[0] - unaff_ESI;
  if (fVar5 < 0.0) {
    fVar5 = fVar5 * -1.0;
  }
  fStack_10 = 0.0;
  piStack_14 = (int *)0x1;
  if (1 < (int)fVar4) {
    do {
      piVar2 = piStack_14;
      fStack_18 = unaff_ESI;
      (**(code **)(*param_1 + 0x1c))((float)(int)piStack_14,&stack0xffffffd8);
      if (((fStack_18 < afStack_20[0]) && (afStack_20[0] < unaff_ESI)) &&
         (fVar1 = unaff_ESI - fStack_18, 0.0 <= fStack_c * fVar1)) {
        if (fVar1 == 0.0) {
          *unaff_retaddr = (float)((int)piVar2 + -1) + _K_HALF;
          return 1;
        }
        *unaff_retaddr = (afStack_20[0] - fStack_18) / fVar1 + (float)((int)piVar2 + -1);
        return 1;
      }
      fVar1 = afStack_20[0] - unaff_ESI;
      if (fVar1 < 0.0) {
        fVar1 = fVar1 * -1.0;
      }
      if (fVar1 < fVar5) {
        fVar5 = fVar1;
        fStack_10 = (float)piVar2;
      }
      piStack_14 = (int *)((int)piVar2 + 1);
    } while ((int)piStack_14 < (int)fVar4);
  }
  *unaff_retaddr = (float)(int)fStack_10;
  return 1;
}


// ==== 0x633d70 FUN_00633d70

void __thiscall FUN_00633d70(int param_1,int param_2)

{
  int *piVar1;
  undefined1 local_28 [8];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10 [4];
  float local_c;
  
  if (*(char *)(param_1 + 0x68) == '\0') {
    *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x58) = 0;
    *(undefined4 *)(param_1 + 0x5c) = 0;
    *(undefined4 *)(param_1 + 0x60) = 0;
    *(undefined4 *)(param_1 + 100) = 0x3f800000;
    *(undefined1 *)(param_1 + 0x68) = 1;
    return;
  }
  if (*(int *)(param_1 + 0x54) != param_2) {
    FUN_00633500(0,0,&local_20);
    piVar1 = (int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x30) * 4);
    FUN_00633500((float)(int)(*(ushort *)(*piVar1 + 4) - 1),
                 (float)(int)(*(ushort *)(piVar1[1] + 4) - 1),local_28);
    FUN_006332d0(&local_20,local_28,local_10);
    if (*(int *)(param_1 + 0x54) + -1 == param_2) {
      local_c = local_c * -1.0;
    }
    FUN_00632710((undefined4 *)(param_1 + 0x58),local_10,&local_20);
    *(undefined4 *)(param_1 + 0x58) = local_20;
    *(undefined4 *)(param_1 + 0x5c) = local_1c;
    *(undefined4 *)(param_1 + 0x60) = local_18;
    *(undefined4 *)(param_1 + 100) = local_14;
    *(int *)(param_1 + 0x54) = param_2;
  }
  return;
}


// ==== 0x633e70 FUN_00633e70

undefined4 __thiscall FUN_00633e70(int param_1,float param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 unaff_EBP;
  undefined4 unaff_EDI;
  float10 fVar10;
  float10 fVar11;
  undefined4 uStack_10;
  
  *(float *)(param_1 + 0x4c) = param_2;
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_006337b0(0);
  }
  param_2 = param_2 + *(float *)(param_1 + 0x50);
  fVar4 = *(float *)(param_1 + 0x40) * *(float *)(param_1 + 0x48) * param_2 +
          *(float *)(param_1 + 0x38);
  fVar1 = *(float *)(param_1 + 0x44);
  fVar2 = *(float *)(param_1 + 0x48);
  fVar3 = *(float *)(param_1 + 0x3c);
  uVar5 = FUN_00632d80(fVar4,0,(float)(int)(*(ushort *)
                                             (*(int *)(*(int *)(param_1 + 0x10) +
                                                      *(int *)(param_1 + 0x30) * 4) + 4) - 1));
  fVar10 = (float10)FUN_00633ae0(fVar4,0,(float)(int)(*(ushort *)
                                                       (*(int *)(*(int *)(param_1 + 0x10) +
                                                                *(int *)(param_1 + 0x30) * 4) + 4) -
                                                     1));
  iVar6 = *(ushort *)(*(int *)(*(int *)(param_1 + 0x10) + 4 + *(int *)(param_1 + 0x30) * 4) + 4) - 1
  ;
  fVar11 = (float10)FUN_00633ae0(fVar1 * fVar2 * param_2 + fVar3,0,(float)iVar6);
  FUN_00628c90(param_3,0);
  uVar7 = (**(code **)(**(int **)(param_1 + 0x18) + 0x18))((float)fVar10,param_3,0);
  if ((char)uVar7 == '\0') {
    return uVar7;
  }
  if (*(float *)(param_1 + 0x28) != 0.0) {
    puVar8 = (undefined4 *)FUN_00634150(0);
    uVar7 = *puVar8;
    FUN_00628c90(uVar7,0);
    uVar9 = (**(code **)(**(int **)(param_1 + 0x1c) + 0x18))(unaff_EDI,uVar7,0);
    if ((char)uVar9 == '\0') {
      return uVar9;
    }
    FUN_0062a3e0(*(undefined4 *)(*(int *)(param_1 + 0x34) + 8),*(undefined4 *)(param_1 + 0x28),
                 param_3,uVar7,param_3,0);
  }
  FUN_00633d70(uVar5);
  FUN_00632710((undefined4 *)(param_3 + 0x10),param_1 + 0x58,&stack0xffffffe4);
  *(undefined4 *)(param_3 + 0x10) = unaff_EBP;
  *(float *)(param_3 + 0x14) = (float)fVar11;
  *(int *)(param_3 + 0x18) = iVar6;
  *(undefined4 *)(param_3 + 0x1c) = uStack_10;
  return CONCAT31((int3)((uint)(float)fVar11 >> 8),1);
}


// ==== 0x634010 FUN_00634010

undefined4 __thiscall FUN_00634010(int param_1,float param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  undefined4 uVar6;
  float10 fVar7;
  float10 fVar8;
  
  *(float *)(param_1 + 0x4c) = param_2;
  if (*(int *)(param_1 + 0x14) != 0) {
    if (*(int *)(param_1 + 0x20) == 0) {
      FUN_006337b0(0);
    }
    param_2 = param_2 + *(float *)(param_1 + 0x50);
    fVar4 = *(float *)(param_1 + 0x40) * *(float *)(param_1 + 0x48) * param_2 +
            *(float *)(param_1 + 0x38);
    fVar1 = *(float *)(param_1 + 0x44);
    fVar2 = *(float *)(param_1 + 0x48);
    fVar3 = *(float *)(param_1 + 0x3c);
    uVar6 = FUN_00632d80(fVar4,0,(float)(int)(*(ushort *)
                                               (*(int *)(*(int *)(param_1 + 0x10) +
                                                        *(int *)(param_1 + 0x30) * 4) + 4) - 1));
    fVar7 = (float10)FUN_00633ae0(fVar4,0,(float)(int)(*(ushort *)
                                                        (*(int *)(*(int *)(param_1 + 0x10) +
                                                                 *(int *)(param_1 + 0x30) * 4) + 4)
                                                      - 1));
    fVar8 = (float10)FUN_00633ae0(fVar1 * fVar2 * param_2 + fVar3,0,
                                  (float)(int)(*(ushort *)
                                                (*(int *)(*(int *)(param_1 + 0x10) + 4 +
                                                         *(int *)(param_1 + 0x30) * 4) + 4) - 1));
    cVar5 = FUN_006333e0((float)fVar7,(float)fVar8,param_3);
    if (cVar5 != '\0') {
      FUN_00633d70(uVar6);
      FUN_00633390(param_3);
      return 1;
    }
  }
  return 0;
}


// ==== 0x634120 FUN_00634120

void __fastcall FUN_00634120(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2];
  param_1[2] = iVar1 + -1;
  if ((*param_1 != 0) && (iVar1 + -1 < 1)) {
    (*(code *)PTR_FUN_006dfaa0)(*param_1,param_1[1]);
    *param_1 = 0;
  }
  return;
}


// ==== 0x634150 FUN_00634150

undefined4 * FUN_00634150(int param_1)

{
  return &DAT_0070d638 + param_1 * 3;
}


// ==== 0x634160 FUN_00634160

void FUN_00634160(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  D3DXMatrixMultiply(param_1,param_3,param_2);
  return;
}


// ==== 0x634180 FUN_00634180

void __thiscall
FUN_00634180(ushort *param_1,uint param_2,uint param_3,int param_4,int param_5,float *param_6,
            float *param_7)

{
  float *pfVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  float fVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  ushort *puVar9;
  byte *pbVar10;
  float *pfVar11;
  uint uVar12;
  int iVar13;
  byte *pbVar14;
  
  if (param_5 != param_4) {
    pfVar1 = (float *)(param_1 + param_2 * 6 + 2);
    if (((param_5 < param_4) || (param_5 == 0)) || (param_4 == -1)) {
      iVar13 = 0;
      if (0 < (int)param_3) {
        pfVar11 = pfVar1 + 2;
        do {
          fVar5 = *pfVar11;
          pfVar11 = pfVar11 + 3;
          param_7[iVar13] = fVar5;
          iVar13 = iVar13 + 1;
        } while (iVar13 < (int)param_3);
      }
      param_4 = 0;
    }
    else {
      uVar12 = param_3;
      pfVar11 = param_7;
      if (param_7 != param_6) {
        for (; uVar12 != 0; uVar12 = uVar12 - 1) {
          *pfVar11 = *param_6;
          param_6 = param_6 + 1;
          pfVar11 = pfVar11 + 1;
        }
      }
    }
    if (param_5 != 0) {
      uVar12 = (uint)*param_1;
      iVar13 = uVar12 * 0xc + 4;
      cVar2 = (char)param_1[1];
      if (cVar2 == '\x04') {
        pbVar14 = (byte *)((int)param_1 + param_2 + ((int)(uVar12 + 1) >> 1) * param_4 + iVar13);
        uVar12 = param_3 - 1;
        if ((param_2 & 1) == 0) {
          if (param_4 < param_5) {
            param_4 = param_5 - param_4;
            do {
              iVar13 = 0;
              iVar8 = iVar13;
              pfVar11 = pfVar1;
              pfVar6 = pfVar1;
              if (0 < (int)uVar12) {
                do {
                  bVar3 = *pbVar14;
                  pbVar14 = pbVar14 + 1;
                  iVar8 = iVar13 + 2;
                  pfVar6 = pfVar11 + 6;
                  param_7[iVar13] = (float)(bVar3 & 0xf) * pfVar11[1] + param_7[iVar13] + *pfVar11;
                  param_7[iVar13 + 1] =
                       (float)(bVar3 >> 4) * pfVar11[4] + param_7[iVar13 + 1] + pfVar11[3];
                  iVar13 = iVar8;
                  pfVar11 = pfVar6;
                } while (iVar8 < (int)uVar12);
              }
              if ((param_3 & 1) != 0) {
                bVar3 = *pbVar14;
                pbVar14 = pbVar14 + 1;
                param_7[iVar8] = (float)(bVar3 & 0xf) * pfVar6[1] + param_7[iVar8] + *pfVar6;
              }
              param_4 = param_4 + -1;
            } while (param_4 != 0);
            return;
          }
        }
        else if (param_4 < param_5) {
          param_4 = param_5 - param_4;
          do {
            iVar13 = 0;
            pfVar11 = pfVar1;
            if (0 < (int)uVar12) {
              bVar3 = *pbVar14;
              iVar13 = 1;
              pbVar14 = pbVar14 + 1;
              pfVar11 = pfVar1 + 3;
              *param_7 = (float)(bVar3 >> 4) * pfVar1[1] + *param_7 + *pfVar1;
              iVar8 = iVar13;
              pfVar6 = pfVar11;
              if (1 < (int)uVar12) {
                do {
                  bVar3 = *pbVar14;
                  pbVar14 = pbVar14 + 1;
                  iVar13 = iVar8 + 2;
                  pfVar11 = pfVar6 + 6;
                  param_7[iVar8] = (float)(bVar3 & 0xf) * pfVar6[1] + param_7[iVar8] + *pfVar6;
                  param_7[iVar8 + 1] =
                       (float)(bVar3 >> 4) * pfVar6[4] + param_7[iVar8 + 1] + pfVar6[3];
                  iVar8 = iVar13;
                  pfVar6 = pfVar11;
                } while (iVar13 < (int)uVar12);
              }
            }
            if ((uVar12 & 1) != 0) {
              bVar3 = *pbVar14;
              pbVar14 = pbVar14 + 1;
              param_7[iVar13] = (float)(bVar3 & 0xf) * pfVar11[1] + param_7[iVar13] + *pfVar11;
            }
            param_4 = param_4 + -1;
          } while (param_4 != 0);
        }
      }
      else if (cVar2 == '\b') {
        pbVar14 = (byte *)((int)param_1 + param_2 + uVar12 * param_4 + iVar13);
        if (param_4 < param_5) {
          param_4 = param_5 - param_4;
          do {
            iVar13 = 0;
            pfVar11 = pfVar1;
            if (3 < (int)param_3) {
              iVar8 = 3;
              pfVar6 = pfVar1;
              pfVar7 = param_7 + 2;
              pbVar10 = pbVar14;
              do {
                iVar8 = iVar8 + 4;
                pbVar14 = pbVar10 + 4;
                iVar13 = iVar13 + 4;
                pfVar11 = pfVar6 + 0xc;
                pfVar7[-2] = (float)*pbVar10 * pfVar6[1] + pfVar7[-2] + *pfVar6;
                pfVar7[-1] = (float)pbVar10[1] * pfVar6[4] + pfVar6[3] + pfVar7[-1];
                *pfVar7 = (float)pbVar10[2] * pfVar6[7] + pfVar6[6] + *pfVar7;
                pfVar7[1] = (float)pbVar10[3] * pfVar6[10] + pfVar6[9] + pfVar7[1];
                pfVar6 = pfVar11;
                pfVar7 = pfVar7 + 4;
                pbVar10 = pbVar14;
              } while (iVar8 < (int)param_3);
            }
            for (; iVar13 < (int)param_3; iVar13 = iVar13 + 1) {
              bVar3 = *pbVar14;
              pbVar14 = pbVar14 + 1;
              param_7[iVar13] = (float)bVar3 * pfVar11[1] + param_7[iVar13] + *pfVar11;
              pfVar11 = pfVar11 + 3;
            }
            param_4 = param_4 + -1;
          } while (param_4 != 0);
          return;
        }
      }
      else if ((cVar2 == '\x10') &&
              (param_1 = param_1 + uVar12 * 6 + uVar12 * param_4 + param_2 + 2, param_4 < param_5))
      {
        param_4 = param_5 - param_4;
        do {
          iVar13 = 0;
          pfVar11 = pfVar1;
          if (3 < (int)param_3) {
            iVar8 = 3;
            pfVar6 = pfVar1;
            pfVar7 = param_7 + 2;
            puVar9 = param_1;
            do {
              iVar8 = iVar8 + 4;
              param_1 = puVar9 + 4;
              iVar13 = iVar13 + 4;
              pfVar11 = pfVar6 + 0xc;
              pfVar7[-2] = (float)*puVar9 * pfVar6[1] + pfVar7[-2] + *pfVar6;
              pfVar7[-1] = (float)puVar9[1] * pfVar6[4] + pfVar6[3] + pfVar7[-1];
              *pfVar7 = (float)puVar9[2] * pfVar6[7] + pfVar6[6] + *pfVar7;
              pfVar7[1] = (float)puVar9[3] * pfVar6[10] + pfVar6[9] + pfVar7[1];
              pfVar6 = pfVar11;
              pfVar7 = pfVar7 + 4;
              puVar9 = param_1;
            } while (iVar8 < (int)param_3);
          }
          for (; iVar13 < (int)param_3; iVar13 = iVar13 + 1) {
            uVar4 = *param_1;
            param_1 = param_1 + 1;
            param_7[iVar13] = (float)uVar4 * pfVar11[1] + param_7[iVar13] + *pfVar11;
            pfVar11 = pfVar11 + 3;
          }
          param_4 = param_4 + -1;
        } while (param_4 != 0);
        return;
      }
    }
  }
  return;
}


// ==== 0x6345a0 FUN_006345a0

void __thiscall
FUN_006345a0(ushort *param_1,uint param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,int param_9,float param_10)

{
  float *pfVar1;
  ushort uVar2;
  char cVar3;
  undefined4 *puVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  uint uVar9;
  ushort *puVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte bVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  
  iVar15 = param_8;
  iVar16 = param_4;
  if (param_5 != param_4) {
    pfVar1 = (float *)(param_1 + param_2 * 6 + 2);
    param_3 = param_3 / param_8;
    if (((param_5 == 0) || (param_4 == -1)) || (param_5 < param_4)) {
      iVar16 = 0;
      pfVar6 = pfVar1;
      if (0 < param_3) {
        do {
          if (0 < param_8) {
            pfVar5 = (float *)(param_7 + (uint)*(ushort *)(param_9 + iVar16 * 2) * 4);
            iVar8 = param_8;
            do {
              *pfVar5 = pfVar6[2];
              pfVar6 = pfVar6 + 3;
              pfVar5 = pfVar5 + 1;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
          iVar16 = iVar16 + 1;
        } while (iVar16 < param_3);
      }
      iVar16 = 0;
    }
    else {
      iVar8 = 0;
      param_4 = 0;
      if (0 < param_3) {
        do {
          if (0 < param_8) {
            puVar4 = (undefined4 *)(param_7 + (uint)*(ushort *)(param_9 + param_4 * 2) * 4);
            iVar14 = param_8;
            do {
              *puVar4 = *(undefined4 *)(param_6 + iVar8 * 4);
              iVar8 = iVar8 + 1;
              puVar4 = puVar4 + 1;
              iVar14 = iVar14 + -1;
            } while (iVar14 != 0);
          }
          param_4 = param_4 + 1;
        } while (param_4 < param_3);
      }
    }
    if (param_5 != 0) {
      uVar9 = (uint)*param_1;
      iVar8 = uVar9 * 0xc + 4;
      cVar3 = (char)param_1[1];
      if (cVar3 == '\x04') {
        pbVar11 = (byte *)((int)param_1 + ((uVar9 + 1) / 2) * iVar16 + iVar8);
        cVar3 = '\x01' - ((param_2 & 0xfffffffe) != 0);
        if (iVar16 < param_5) {
          param_8 = param_5 - iVar16;
          do {
            param_4 = 0;
            pfVar6 = pfVar1;
            if (0 < param_3) {
              do {
                uVar9 = (uint)*(ushort *)(param_9 + param_4 * 2);
                param_5 = 0;
                if (3 < iVar15) {
                  iVar16 = 3;
                  pfVar5 = pfVar6;
                  pfVar7 = (float *)(param_7 + uVar9 * 4);
                  do {
                    if (cVar3 == '\0') {
                      bVar13 = *pbVar11 >> 4;
                      pbVar11 = pbVar11 + 1;
                    }
                    else {
                      bVar13 = *pbVar11 & 0xf;
                    }
                    cVar3 = cVar3 != '\0';
                    *pfVar7 = ((float)bVar13 * pfVar5[1] + *pfVar5) * param_10 + *pfVar7;
                    if ((bool)cVar3) {
                      bVar13 = *pbVar11 >> 4;
                      pbVar11 = pbVar11 + 1;
                    }
                    else {
                      bVar13 = *pbVar11 & 0xf;
                    }
                    pfVar7[1] = ((float)bVar13 * pfVar5[4] + pfVar5[3]) * param_10 + pfVar7[1];
                    if ((bool)cVar3) {
                      bVar13 = *pbVar11 & 0xf;
                    }
                    else {
                      bVar13 = *pbVar11 >> 4;
                      pbVar11 = pbVar11 + 1;
                    }
                    pfVar7[2] = ((float)bVar13 * pfVar5[7] + pfVar5[6]) * param_10 + pfVar7[2];
                    if ((bool)cVar3) {
                      bVar13 = *pbVar11 >> 4;
                      pbVar11 = pbVar11 + 1;
                    }
                    else {
                      bVar13 = *pbVar11 & 0xf;
                    }
                    param_5 = param_5 + 4;
                    iVar16 = iVar16 + 4;
                    pfVar6 = pfVar5 + 0xc;
                    pfVar7[3] = ((float)bVar13 * pfVar5[10] + pfVar5[9]) * param_10 + pfVar7[3];
                    pfVar5 = pfVar6;
                    pfVar7 = pfVar7 + 4;
                  } while (iVar16 < iVar15);
                }
                if (param_5 < iVar15) {
                  iVar16 = iVar15 - param_5;
                  pfVar5 = pfVar6;
                  pfVar7 = (float *)(param_7 + (uVar9 + param_5) * 4);
                  do {
                    if (cVar3 == '\0') {
                      bVar13 = *pbVar11 >> 4;
                      pbVar11 = pbVar11 + 1;
                    }
                    else {
                      bVar13 = *pbVar11 & 0xf;
                    }
                    cVar3 = cVar3 == '\0';
                    pfVar6 = pfVar5 + 3;
                    iVar16 = iVar16 + -1;
                    *pfVar7 = ((float)bVar13 * pfVar5[1] + *pfVar5) * param_10 + *pfVar7;
                    pfVar5 = pfVar6;
                    pfVar7 = pfVar7 + 1;
                  } while (iVar16 != 0);
                }
                param_4 = param_4 + 1;
              } while (param_4 < param_3);
            }
            if (cVar3 == '\0') {
              pbVar11 = pbVar11 + 1;
              cVar3 = '\x01';
            }
            param_8 = param_8 + -1;
          } while (param_8 != 0);
        }
      }
      else if (cVar3 == '\b') {
        pbVar11 = (byte *)((int)param_1 + uVar9 * iVar16 + iVar8);
        if (iVar16 < param_5) {
          param_5 = param_5 - iVar16;
          do {
            param_4 = 0;
            pfVar6 = pfVar1;
            if (0 < param_3) {
              do {
                uVar9 = (uint)*(ushort *)(param_9 + param_4 * 2);
                iVar16 = 0;
                if (3 < param_8) {
                  iVar15 = 3;
                  pfVar5 = pfVar6;
                  pfVar7 = (float *)(param_7 + uVar9 * 4);
                  pbVar12 = pbVar11;
                  do {
                    pfVar6 = pfVar5 + 0xc;
                    iVar15 = iVar15 + 4;
                    pbVar11 = pbVar12 + 4;
                    iVar16 = iVar16 + 4;
                    *pfVar7 = ((float)*pbVar12 * pfVar5[1] + *pfVar5) * param_10 + *pfVar7;
                    pfVar7[1] = ((float)pbVar12[1] * pfVar5[4] + pfVar5[3]) * param_10 + pfVar7[1];
                    pfVar7[2] = ((float)pbVar12[2] * pfVar5[7] + pfVar5[6]) * param_10 + pfVar7[2];
                    pfVar7[3] = ((float)pbVar12[3] * pfVar5[10] + pfVar5[9]) * param_10 + pfVar7[3];
                    pfVar5 = pfVar6;
                    pfVar7 = pfVar7 + 4;
                    pbVar12 = pbVar11;
                  } while (iVar15 < param_8);
                }
                if (iVar16 < param_8) {
                  iVar15 = param_8 - iVar16;
                  pfVar5 = pfVar6;
                  pfVar7 = (float *)(param_7 + (uVar9 + iVar16) * 4);
                  do {
                    bVar13 = *pbVar11;
                    pfVar6 = pfVar5 + 3;
                    pbVar11 = pbVar11 + 1;
                    iVar15 = iVar15 + -1;
                    *pfVar7 = ((float)bVar13 * pfVar5[1] + *pfVar5) * param_10 + *pfVar7;
                    pfVar5 = pfVar6;
                    pfVar7 = pfVar7 + 1;
                  } while (iVar15 != 0);
                }
                param_4 = param_4 + 1;
              } while (param_4 < param_3);
            }
            param_5 = param_5 + -1;
          } while (param_5 != 0);
          return;
        }
      }
      else if ((cVar3 == '\x10') &&
              (param_1 = param_1 + uVar9 * 6 + uVar9 * iVar16 + 2, iVar16 < param_5)) {
        param_5 = param_5 - iVar16;
        do {
          param_4 = 0;
          pfVar6 = pfVar1;
          if (0 < param_3) {
            do {
              uVar9 = (uint)*(ushort *)(param_9 + param_4 * 2);
              iVar16 = 0;
              if (3 < param_8) {
                iVar15 = 3;
                pfVar5 = pfVar6;
                pfVar7 = (float *)(param_7 + uVar9 * 4);
                puVar10 = param_1;
                do {
                  iVar15 = iVar15 + 4;
                  pfVar6 = pfVar5 + 0xc;
                  param_1 = puVar10 + 4;
                  iVar16 = iVar16 + 4;
                  *pfVar7 = ((float)*puVar10 * pfVar5[1] + *pfVar5) * param_10 + *pfVar7;
                  pfVar7[1] = ((float)puVar10[1] * pfVar5[4] + pfVar5[3]) * param_10 + pfVar7[1];
                  pfVar7[2] = ((float)puVar10[2] * pfVar5[7] + pfVar5[6]) * param_10 + pfVar7[2];
                  pfVar7[3] = ((float)puVar10[3] * pfVar5[10] + pfVar5[9]) * param_10 + pfVar7[3];
                  pfVar5 = pfVar6;
                  pfVar7 = pfVar7 + 4;
                  puVar10 = param_1;
                } while (iVar15 < param_8);
              }
              if (iVar16 < param_8) {
                iVar15 = param_8 - iVar16;
                pfVar5 = pfVar6;
                pfVar7 = (float *)(param_7 + (uVar9 + iVar16) * 4);
                do {
                  uVar2 = *param_1;
                  pfVar6 = pfVar5 + 3;
                  param_1 = param_1 + 1;
                  iVar15 = iVar15 + -1;
                  *pfVar7 = ((float)uVar2 * pfVar5[1] + *pfVar5) * param_10 + *pfVar7;
                  pfVar5 = pfVar6;
                  pfVar7 = pfVar7 + 1;
                } while (iVar15 != 0);
              }
              param_4 = param_4 + 1;
            } while (param_4 < param_3);
          }
          param_5 = param_5 + -1;
        } while (param_5 != 0);
        return;
      }
    }
  }
  return;
}


// ==== 0x634b20 FUN_00634b20

void __thiscall
FUN_00634b20(ushort *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7
            ,int param_8)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  undefined4 *puVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  byte *pbVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  ushort *puVar15;
  ushort *puVar16;
  
  iVar4 = param_2;
  if (param_4 != param_3) {
    if (((param_4 < param_3) || (param_4 == 0)) || (param_3 == -1)) {
      iVar13 = 0;
      if (0 < param_7) {
        do {
          iVar11 = (uint)*(ushort *)(param_8 + iVar13 * 2) * param_2;
          puVar16 = param_1 + iVar11 * 6;
          if (0 < param_2) {
            puVar5 = (undefined4 *)(param_6 + iVar11 * 4);
            iVar11 = param_2;
            do {
              puVar16 = puVar16 + 6;
              *puVar5 = *(undefined4 *)puVar16;
              puVar5 = puVar5 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
          }
          iVar13 = iVar13 + 1;
        } while (iVar13 < param_7);
      }
      param_3 = 0;
    }
    else if ((param_6 != param_5) && (param_2 = 0, 0 < param_7)) {
      do {
        if (0 < iVar4) {
          puVar5 = (undefined4 *)(param_6 + (uint)*(ushort *)(param_8 + param_2 * 2) * iVar4 * 4);
          iVar13 = iVar4;
          do {
            *puVar5 = *(undefined4 *)((param_5 - param_6) + (int)puVar5);
            puVar5 = puVar5 + 1;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
        }
        param_2 = param_2 + 1;
      } while (param_2 < param_7);
    }
    if (param_4 != 0) {
      uVar2 = *param_1;
      iVar13 = param_3;
      if ((char)param_1[1] == '\b') {
        for (; iVar13 < param_4; iVar13 = iVar13 + 1) {
          param_2 = 0;
          if (0 < param_7) {
            do {
              iVar11 = (uint)*(ushort *)(param_8 + param_2 * 2) * iVar4;
              pfVar7 = (float *)(param_1 + iVar11 * 6 + 2);
              pbVar9 = (byte *)((int)param_1 +
                               iVar11 + (uint)*param_1 * iVar13 + (uint)uVar2 * 0xc + 4);
              iVar14 = 0;
              if (3 < iVar4) {
                param_3 = 3;
                pfVar6 = pfVar7;
                pbVar10 = pbVar9;
                pfVar8 = (float *)(param_6 + iVar11 * 4);
                do {
                  iVar14 = iVar14 + 4;
                  pfVar7 = pfVar6 + 0xc;
                  pbVar9 = pbVar10 + 4;
                  *pfVar8 = (float)*pbVar10 * pfVar6[1] + *pfVar6 + *pfVar8;
                  pfVar8[1] = (float)pbVar10[1] * pfVar6[4] + pfVar6[3] + pfVar8[1];
                  pfVar8[2] = (float)pbVar10[2] * pfVar6[7] + pfVar6[6] + pfVar8[2];
                  param_3 = param_3 + 4;
                  pfVar8[3] = (float)pbVar10[3] * pfVar6[10] + pfVar6[9] + pfVar8[3];
                  pfVar6 = pfVar7;
                  pbVar10 = pbVar9;
                  pfVar8 = pfVar8 + 4;
                } while (param_3 < iVar4);
              }
              if (iVar14 < iVar4) {
                iVar12 = iVar4 - iVar14;
                pfVar6 = (float *)(param_6 + (iVar11 + iVar14) * 4);
                do {
                  bVar1 = *pbVar9;
                  pbVar9 = pbVar9 + 1;
                  iVar12 = iVar12 + -1;
                  *pfVar6 = (float)bVar1 * pfVar7[1] + *pfVar7 + *pfVar6;
                  pfVar7 = pfVar7 + 3;
                  pfVar6 = pfVar6 + 1;
                } while (iVar12 != 0);
              }
              param_2 = param_2 + 1;
            } while (param_2 < param_7);
          }
        }
      }
      else if (((char)param_1[1] == '\x10') && (param_5 = param_3, param_3 < param_4)) {
        do {
          param_2 = 0;
          if (0 < param_7) {
            do {
              iVar11 = (uint)*(ushort *)(param_8 + param_2 * 2) * iVar4;
              pfVar7 = (float *)(param_1 + iVar11 * 6 + 2);
              puVar16 = param_1 + (uint)uVar2 * 6 + (uint)*param_1 * param_5 + iVar11 + 2;
              iVar13 = 0;
              param_3 = 0;
              if (3 < iVar4) {
                iVar14 = 3;
                pfVar6 = pfVar7;
                pfVar8 = (float *)(param_6 + iVar11 * 4);
                puVar15 = puVar16;
                do {
                  iVar14 = iVar14 + 4;
                  pfVar7 = pfVar6 + 0xc;
                  puVar16 = puVar15 + 4;
                  *pfVar8 = (float)*puVar15 * pfVar6[1] + *pfVar6 + *pfVar8;
                  pfVar8[1] = (float)puVar15[1] * pfVar6[4] + pfVar6[3] + pfVar8[1];
                  pfVar8[2] = (float)puVar15[2] * pfVar6[7] + pfVar6[6] + pfVar8[2];
                  iVar13 = param_3 + 4;
                  pfVar8[3] = (float)puVar15[3] * pfVar6[10] + pfVar6[9] + pfVar8[3];
                  pfVar6 = pfVar7;
                  pfVar8 = pfVar8 + 4;
                  puVar15 = puVar16;
                  param_3 = iVar13;
                } while (iVar14 < iVar4);
              }
              if (iVar13 < iVar4) {
                iVar14 = iVar4 - iVar13;
                pfVar6 = (float *)(param_6 + (iVar13 + iVar11) * 4);
                do {
                  uVar3 = *puVar16;
                  puVar16 = puVar16 + 1;
                  iVar14 = iVar14 + -1;
                  *pfVar6 = (float)uVar3 * pfVar7[1] + *pfVar6 + *pfVar7;
                  pfVar7 = pfVar7 + 3;
                  pfVar6 = pfVar6 + 1;
                } while (iVar14 != 0);
              }
              param_2 = param_2 + 1;
            } while (param_2 < param_7);
          }
          param_5 = param_5 + 1;
        } while (param_5 < param_4);
        return;
      }
    }
  }
  return;
}


// ==== 0x634ed0 FUN_00634ed0

void __thiscall
FUN_00634ed0(ushort *param_1,int param_2,int param_3,int param_4,int param_5,uint param_6,
            int param_7,float param_8,int param_9,ushort *param_10)

{
  int iVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  float *pfVar8;
  float *pfVar9;
  ushort *puVar10;
  float *pfVar11;
  byte *pbVar12;
  byte *pbVar13;
  uint uVar14;
  ushort *puVar15;
  int iVar16;
  int local_c;
  
  iVar5 = param_6;
  if (param_3 != param_2) {
    if (((param_3 == 0) || (param_2 == -1)) || (param_3 < param_2)) {
      iVar6 = 0;
      if (0 < param_9) {
        do {
          puVar10 = param_1 + param_10[iVar6] * param_6 * 6;
          if (0 < (int)param_6) {
            puVar7 = (undefined4 *)
                     (param_5 + (uint)*(ushort *)(param_7 + (uint)param_10[iVar6] * 2) * 4);
            iVar16 = param_6;
            do {
              puVar10 = puVar10 + 6;
              *puVar7 = *(undefined4 *)puVar10;
              puVar7 = puVar7 + 1;
              iVar16 = iVar16 + -1;
            } while (iVar16 != 0);
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < param_9);
      }
      param_2 = 0;
    }
    else if (0 < param_9) {
      local_c = param_9;
      puVar10 = param_10;
      do {
        param_6 = (uint)*(ushort *)(param_7 + (uint)*puVar10 * 2);
        iVar6 = 0;
        if (3 < iVar5) {
          puVar7 = (undefined4 *)(param_5 + 8 + param_6 * 4);
          iVar16 = iVar6;
          do {
            puVar7[-2] = *(undefined4 *)(param_4 + ((uint)*puVar10 * iVar5 + iVar16) * 4);
            puVar7[-1] = *(undefined4 *)(param_4 + 4 + ((uint)*puVar10 * iVar5 + iVar16) * 4);
            *puVar7 = *(undefined4 *)(param_4 + 8 + ((uint)*puVar10 * iVar5 + iVar16) * 4);
            puVar7[1] = *(undefined4 *)(param_4 + 0xc + ((uint)*puVar10 * iVar5 + iVar16) * 4);
            param_6 = param_6 + 4;
            iVar6 = iVar16 + 4;
            iVar1 = iVar16 + 7;
            puVar7 = puVar7 + 4;
            iVar16 = iVar6;
          } while (iVar1 < iVar5);
        }
        if (iVar6 < iVar5) {
          puVar7 = (undefined4 *)(param_5 + param_6 * 4);
          do {
            *puVar7 = *(undefined4 *)(param_4 + ((uint)*puVar10 * iVar5 + iVar6) * 4);
            puVar7 = puVar7 + 1;
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar5);
        }
        puVar10 = puVar10 + 1;
        local_c = local_c + -1;
      } while (local_c != 0);
    }
    if (param_3 != 0) {
      uVar3 = *param_1;
      iVar6 = param_2;
      if ((char)param_1[1] == '\b') {
        for (; iVar6 < param_3; iVar6 = iVar6 + 1) {
          param_6 = 0;
          if (0 < param_9) {
            do {
              iVar16 = (uint)param_10[param_6] * iVar5;
              pbVar12 = (byte *)((int)param_1 +
                                iVar16 + (uint)*param_1 * iVar6 + (uint)uVar3 * 0xc + 4);
              uVar14 = (uint)*(ushort *)(param_7 + (uint)param_10[param_6] * 2);
              pfVar9 = (float *)(param_1 + iVar16 * 6 + 2);
              param_2 = 0;
              if (3 < iVar5) {
                iVar16 = 3;
                pfVar8 = pfVar9;
                pbVar13 = pbVar12;
                pfVar11 = (float *)(param_5 + 8 + uVar14 * 4);
                do {
                  iVar16 = iVar16 + 4;
                  uVar14 = uVar14 + 4;
                  pfVar9 = pfVar8 + 0xc;
                  pbVar12 = pbVar13 + 4;
                  pfVar11[-2] = ((float)*pbVar13 * pfVar8[1] + *pfVar8) * param_8 + pfVar11[-2];
                  pfVar11[-1] = ((float)pbVar13[1] * pfVar8[4] + pfVar8[3]) * param_8 + pfVar11[-1];
                  *pfVar11 = ((float)pbVar13[2] * pfVar8[7] + pfVar8[6]) * param_8 + *pfVar11;
                  param_2 = param_2 + 4;
                  pfVar11[1] = ((float)pbVar13[3] * pfVar8[10] + pfVar8[9]) * param_8 + pfVar11[1];
                  pfVar8 = pfVar9;
                  pbVar13 = pbVar12;
                  pfVar11 = pfVar11 + 4;
                } while (iVar16 < iVar5);
              }
              if (param_2 < iVar5) {
                param_2 = iVar5 - param_2;
                pfVar8 = (float *)(param_5 + uVar14 * 4);
                do {
                  bVar2 = *pbVar12;
                  pbVar12 = pbVar12 + 1;
                  param_2 = param_2 + -1;
                  *pfVar8 = ((float)bVar2 * pfVar9[1] + *pfVar9) * param_8 + *pfVar8;
                  pfVar9 = pfVar9 + 3;
                  pfVar8 = pfVar8 + 1;
                } while (param_2 != 0);
              }
              param_6 = param_6 + 1;
            } while ((int)param_6 < param_9);
          }
        }
      }
      else if (((char)param_1[1] == '\x10') && (param_4 = param_2, param_2 < param_3)) {
        do {
          param_6 = 0;
          if (0 < param_9) {
            do {
              iVar6 = (uint)param_10[param_6] * iVar5;
              puVar10 = param_1 + (uint)uVar3 * 6 + (uint)*param_1 * param_4 + iVar6 + 2;
              uVar14 = (uint)*(ushort *)(param_7 + (uint)param_10[param_6] * 2);
              pfVar9 = (float *)(param_1 + iVar6 * 6 + 2);
              param_2 = 0;
              if (3 < iVar5) {
                iVar6 = 3;
                pfVar8 = pfVar9;
                pfVar11 = (float *)(param_5 + 8 + uVar14 * 4);
                puVar15 = puVar10;
                do {
                  iVar6 = iVar6 + 4;
                  uVar14 = uVar14 + 4;
                  pfVar9 = pfVar8 + 0xc;
                  puVar10 = puVar15 + 4;
                  pfVar11[-2] = ((float)*puVar15 * pfVar8[1] + *pfVar8) * param_8 + pfVar11[-2];
                  pfVar11[-1] = ((float)puVar15[1] * pfVar8[4] + pfVar8[3]) * param_8 + pfVar11[-1];
                  *pfVar11 = ((float)puVar15[2] * pfVar8[7] + pfVar8[6]) * param_8 + *pfVar11;
                  param_2 = param_2 + 4;
                  pfVar11[1] = ((float)puVar15[3] * pfVar8[10] + pfVar8[9]) * param_8 + pfVar11[1];
                  pfVar8 = pfVar9;
                  pfVar11 = pfVar11 + 4;
                  puVar15 = puVar10;
                } while (iVar6 < iVar5);
              }
              if (param_2 < iVar5) {
                param_2 = iVar5 - param_2;
                pfVar8 = (float *)(param_5 + uVar14 * 4);
                do {
                  uVar4 = *puVar10;
                  puVar10 = puVar10 + 1;
                  param_2 = param_2 + -1;
                  *pfVar8 = ((float)uVar4 * pfVar9[1] + *pfVar9) * param_8 + *pfVar8;
                  pfVar9 = pfVar9 + 3;
                  pfVar8 = pfVar8 + 1;
                } while (param_2 != 0);
              }
              param_6 = param_6 + 1;
            } while ((int)param_6 < param_9);
          }
          param_4 = param_4 + 1;
        } while (param_4 < param_3);
        return;
      }
    }
  }
  return;
}


// ==== 0x635360 FUN_00635360

int * __thiscall FUN_00635360(int *param_1,ushort param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_1 + -1;
  if (-1 < iVar2) {
    iVar3 = 0;
    do {
      iVar1 = iVar2 + iVar3 >> 1;
      if (*(ushort *)(param_1 + iVar1 * 2 + 1) < param_2) {
        iVar3 = iVar1 + 1;
      }
      else {
        if (*(ushort *)(param_1 + iVar1 * 2 + 1) <= param_2) {
          return param_1 + iVar1 * 2 + 1;
        }
        iVar2 = iVar1 + -1;
      }
    } while (iVar3 <= iVar2);
  }
  return (int *)0x0;
}


// ==== 0x6353a0 FUN_006353a0

undefined4 FUN_006353a0(undefined2 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = FUN_00635360(param_1);
  if (iVar2 != 0) {
    uVar1 = *(undefined4 *)(iVar2 + 4);
    *param_2 = uVar1;
    return CONCAT31((int3)((uint)uVar1 >> 8),1);
  }
  return 0;
}


// ==== 0x6353d0 FUN_006353d0

undefined4 * __fastcall FUN_006353d0(undefined4 *param_1)

{
  FUN_00628eb0();
  *param_1 = &PTR_FUN_006a8590;
  param_1[2] = 0x17;
  return param_1;
}


// ==== 0x6353f0 FUN_006353f0

void __fastcall FUN_006353f0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a8590;
  FUN_00628ed0();
  return;
}


// ==== 0x635400 FUN_00635400

undefined4 __thiscall FUN_00635400(int param_1,float *param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar1 + 8) == 0) {
    uVar2 = CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0x10));
  }
  else {
    uVar2 = (uint)(ushort)(*(short *)(*(int *)(iVar1 + 8) + -4 + (uint)*(ushort *)(iVar1 + 0x10) * 2
                                     ) + 1);
  }
  *param_2 = (float)(uVar2 & 0xffff);
  return CONCAT31((int3)(uVar2 >> 8),1);
}


// ==== 0x635440 FUN_00635440

undefined4 __thiscall
FUN_00635440(int param_1,undefined4 param_2,int param_3,int param_4,char param_5,int param_6,
            float param_7)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  byte bVar6;
  ushort uVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  float *pfVar17;
  uint uVar18;
  uint uVar19;
  short *psVar20;
  short *psVar21;
  int iVar22;
  int iVar23;
  short *psVar24;
  float *pfVar25;
  ushort *local_ac;
  int local_a8;
  float *local_a4;
  byte abStack_78 [120];
  
  if (param_4 != *(int *)(param_1 + 0x14)) {
    *(int *)(param_1 + 0x14) = param_4;
  }
  iVar14 = *(int *)(param_1 + 0xc);
  uVar19 = (uint)*(byte *)(iVar14 + 0x12);
  iVar15 = *(int *)(iVar14 + 0xc);
  iVar22 = uVar19 * 0x20 + 0x18 + iVar14;
  iVar16 = uVar19 * param_6 * 3;
  iVar23 = 0;
  psVar21 = (short *)(iVar22 + uVar19 * param_6 * 6);
  if (uVar19 != 0) {
    do {
      uVar7 = *(ushort *)(iVar15 + iVar23 * 2);
      iVar16 = (uint)uVar7 * -0x55555555;
      abStack_78[iVar23] = (byte)(uVar7 / 0xc);
      iVar23 = iVar23 + 1;
    } while (iVar23 < (int)uVar19);
  }
  pfVar17 = (float *)CONCAT31((int3)((uint)iVar16 >> 8),param_5);
  if (param_5 == '\0') {
    iVar16 = 0;
    if (3 < uVar19) {
      local_ac = (ushort *)(iVar15 + 4);
      pfVar17 = (float *)(iVar14 + 0x30);
      iVar23 = iVar16;
      do {
        psVar20 = psVar21;
        if ((*(uint *)(param_4 + ((int)(uint)abStack_78[iVar23] >> 5) * 4) &
            1 << (abStack_78[iVar23] & 0x1f)) != 0) {
          uVar18 = (uint)local_ac[-2];
          psVar20 = psVar21 + 3;
          *(float *)(param_3 + uVar18 * 4) = (float)(int)*psVar21 * pfVar17[-2];
          *(float *)(param_3 + 4 + uVar18 * 4) = (float)(int)psVar21[1] * pfVar17[-1];
          *(float *)(param_3 + 8 + uVar18 * 4) = (float)(int)psVar21[2] * *pfVar17;
        }
        psVar21 = psVar20;
        if ((*(uint *)(param_4 + ((int)(uint)abStack_78[iVar23 + 1] >> 5) * 4) &
            1 << (abStack_78[iVar23 + 1] & 0x1f)) != 0) {
          uVar18 = (uint)local_ac[-1];
          psVar21 = psVar20 + 3;
          *(float *)(param_3 + uVar18 * 4) = (float)(int)*psVar20 * pfVar17[6];
          *(float *)(param_3 + 4 + uVar18 * 4) = (float)(int)psVar20[1] * pfVar17[7];
          *(float *)(param_3 + 8 + uVar18 * 4) = (float)(int)psVar20[2] * pfVar17[8];
        }
        psVar20 = psVar21;
        if ((*(uint *)(param_4 + ((int)(uint)abStack_78[iVar23 + 2] >> 5) * 4) &
            1 << (abStack_78[iVar23 + 2] & 0x1f)) != 0) {
          uVar18 = (uint)*local_ac;
          psVar20 = psVar21 + 3;
          *(float *)(param_3 + uVar18 * 4) = (float)(int)*psVar21 * pfVar17[0xe];
          *(float *)(param_3 + 4 + uVar18 * 4) = (float)(int)psVar21[1] * pfVar17[0xf];
          *(float *)(param_3 + 8 + uVar18 * 4) = (float)(int)psVar21[2] * pfVar17[0x10];
        }
        psVar21 = psVar20;
        if ((*(uint *)(param_4 + ((int)(uint)abStack_78[iVar23 + 3] >> 5) * 4) &
            1 << (abStack_78[iVar23 + 3] & 0x1f)) != 0) {
          uVar18 = (uint)local_ac[1];
          psVar21 = psVar20 + 3;
          *(float *)(param_3 + uVar18 * 4) = (float)(int)*psVar20 * pfVar17[0x16];
          *(float *)(param_3 + 4 + uVar18 * 4) = (float)(int)psVar20[1] * pfVar17[0x17];
          *(float *)(param_3 + 8 + uVar18 * 4) = (float)(int)psVar20[2] * pfVar17[0x18];
        }
        iVar16 = iVar23 + 4;
        local_ac = local_ac + 4;
        iVar1 = iVar23 + 7;
        pfVar17 = pfVar17 + 0x20;
        iVar23 = iVar16;
      } while (iVar1 < (int)uVar19);
    }
    if (iVar16 < (int)uVar19) {
      local_a4 = (float *)(iVar16 * 0x20 + 0x30 + iVar14);
      do {
        pfVar17 = (float *)((int)(uint)abStack_78[iVar16] >> 5);
        if ((*(uint *)(param_4 + (int)pfVar17 * 4) & 1 << (abStack_78[iVar16] & 0x1f)) != 0) {
          pfVar17 = (float *)(uint)*(ushort *)(iVar15 + iVar16 * 2);
          *(float *)(param_3 + (int)pfVar17 * 4) = (float)(int)*psVar21 * local_a4[-2];
          *(float *)(param_3 + 4 + (int)pfVar17 * 4) = (float)(int)psVar21[1] * local_a4[-1];
          *(float *)(param_3 + 8 + (int)pfVar17 * 4) = (float)(int)psVar21[2] * *local_a4;
          psVar21 = psVar21 + 3;
        }
        iVar16 = iVar16 + 1;
        local_a4 = local_a4 + 8;
      } while (iVar16 < (int)uVar19);
    }
  }
  else {
    iVar16 = (param_6 + 1) * uVar19;
    pfVar17 = (float *)(iVar16 * 3);
    psVar20 = (short *)(iVar22 + iVar16 * 6);
    local_a8 = 0;
    if (3 < uVar19) {
      local_ac = (ushort *)(iVar15 + 4);
      pfVar17 = (float *)(iVar14 + 0x4c);
      do {
        psVar24 = psVar20;
        if ((*(uint *)(param_4 + ((int)(uint)abStack_78[local_a8] >> 5) * 4) &
            1 << (abStack_78[local_a8] & 0x1f)) != 0) {
          sVar8 = *psVar21;
          sVar9 = psVar21[1];
          sVar10 = psVar21[2];
          fVar2 = pfVar17[-8];
          sVar11 = psVar20[1];
          fVar3 = pfVar17[-7];
          psVar21 = psVar21 + 3;
          psVar24 = psVar20 + 3;
          sVar12 = psVar20[2];
          uVar18 = (uint)local_ac[-2];
          fVar4 = pfVar17[-8];
          fVar5 = pfVar17[-7];
          *(float *)(param_3 + uVar18 * 4) =
               ((float)(int)*psVar20 * pfVar17[-9] - (float)(int)sVar8 * pfVar17[-9]) * param_7 +
               (float)(int)sVar8 * pfVar17[-9];
          *(float *)(param_3 + 4 + uVar18 * 4) =
               ((float)(int)sVar11 * fVar4 - (float)(int)sVar9 * fVar2) * param_7 +
               (float)(int)sVar9 * fVar2;
          *(float *)(param_3 + 8 + uVar18 * 4) =
               ((float)(int)sVar12 * fVar5 - (float)(int)sVar10 * fVar3) * param_7 +
               (float)(int)sVar10 * fVar3;
        }
        psVar20 = psVar24;
        if ((*(uint *)(param_4 + ((int)(uint)abStack_78[local_a8 + 1] >> 5) * 4) &
            1 << (abStack_78[local_a8 + 1] & 0x1f)) != 0) {
          sVar8 = *psVar21;
          sVar9 = psVar21[1];
          sVar10 = psVar21[2];
          fVar2 = *pfVar17;
          sVar11 = psVar24[1];
          fVar3 = pfVar17[1];
          psVar21 = psVar21 + 3;
          psVar20 = psVar24 + 3;
          sVar12 = psVar24[2];
          uVar18 = (uint)local_ac[-1];
          fVar4 = *pfVar17;
          fVar5 = pfVar17[1];
          *(float *)(param_3 + uVar18 * 4) =
               ((float)(int)*psVar24 * pfVar17[-1] - (float)(int)sVar8 * pfVar17[-1]) * param_7 +
               (float)(int)sVar8 * pfVar17[-1];
          *(float *)(param_3 + 4 + uVar18 * 4) =
               ((float)(int)sVar11 * fVar4 - (float)(int)sVar9 * fVar2) * param_7 +
               (float)(int)sVar9 * fVar2;
          *(float *)(param_3 + 8 + uVar18 * 4) =
               ((float)(int)sVar12 * fVar5 - (float)(int)sVar10 * fVar3) * param_7 +
               (float)(int)sVar10 * fVar3;
        }
        psVar24 = psVar20;
        if ((*(uint *)(param_4 + ((int)(uint)abStack_78[local_a8 + 2] >> 5) * 4) &
            1 << (abStack_78[local_a8 + 2] & 0x1f)) != 0) {
          sVar8 = *psVar21;
          sVar9 = psVar21[1];
          sVar10 = psVar21[2];
          fVar2 = pfVar17[8];
          sVar11 = psVar20[1];
          fVar3 = pfVar17[9];
          psVar21 = psVar21 + 3;
          psVar24 = psVar20 + 3;
          sVar12 = psVar20[2];
          uVar18 = (uint)*local_ac;
          fVar4 = pfVar17[8];
          fVar5 = pfVar17[9];
          *(float *)(param_3 + uVar18 * 4) =
               ((float)(int)*psVar20 * pfVar17[7] - (float)(int)sVar8 * pfVar17[7]) * param_7 +
               (float)(int)sVar8 * pfVar17[7];
          *(float *)(param_3 + 4 + uVar18 * 4) =
               ((float)(int)sVar11 * fVar4 - (float)(int)sVar9 * fVar2) * param_7 +
               (float)(int)sVar9 * fVar2;
          *(float *)(param_3 + 8 + uVar18 * 4) =
               ((float)(int)sVar12 * fVar5 - (float)(int)sVar10 * fVar3) * param_7 +
               (float)(int)sVar10 * fVar3;
        }
        psVar20 = psVar24;
        if ((*(uint *)(param_4 + ((int)(uint)abStack_78[local_a8 + 3] >> 5) * 4) &
            1 << (abStack_78[local_a8 + 3] & 0x1f)) != 0) {
          sVar8 = *psVar21;
          sVar9 = psVar21[1];
          sVar10 = psVar21[2];
          fVar2 = pfVar17[0x10];
          sVar11 = psVar24[1];
          fVar3 = pfVar17[0x11];
          psVar21 = psVar21 + 3;
          psVar20 = psVar24 + 3;
          sVar12 = psVar24[2];
          uVar18 = (uint)local_ac[1];
          fVar4 = pfVar17[0x10];
          fVar5 = pfVar17[0x11];
          *(float *)(param_3 + uVar18 * 4) =
               ((float)(int)*psVar24 * pfVar17[0xf] - (float)(int)sVar8 * pfVar17[0xf]) * param_7 +
               (float)(int)sVar8 * pfVar17[0xf];
          *(float *)(param_3 + 4 + uVar18 * 4) =
               ((float)(int)sVar11 * fVar4 - (float)(int)sVar9 * fVar2) * param_7 +
               (float)(int)sVar9 * fVar2;
          *(float *)(param_3 + 8 + uVar18 * 4) =
               ((float)(int)sVar12 * fVar5 - (float)(int)sVar10 * fVar3) * param_7 +
               (float)(int)sVar10 * fVar3;
        }
        local_ac = local_ac + 4;
        iVar23 = local_a8 + 4;
        iVar16 = local_a8 + 7;
        pfVar17 = pfVar17 + 0x20;
        local_a8 = iVar23;
      } while (iVar16 < (int)uVar19);
    }
    if (local_a8 < (int)uVar19) {
      pfVar17 = (float *)(local_a8 * 0x20 + 0x2c + iVar14);
      do {
        if ((*(uint *)(param_4 + ((int)(uint)abStack_78[local_a8] >> 5) * 4) &
            1 << (abStack_78[local_a8] & 0x1f)) != 0) {
          sVar8 = *psVar21;
          sVar9 = psVar21[1];
          sVar10 = psVar21[2];
          sVar11 = *psVar20;
          fVar2 = *pfVar17;
          sVar12 = psVar20[1];
          fVar3 = pfVar17[1];
          psVar21 = psVar21 + 3;
          sVar13 = psVar20[2];
          uVar18 = (uint)*(ushort *)(iVar15 + local_a8 * 2);
          fVar4 = *pfVar17;
          psVar20 = psVar20 + 3;
          fVar5 = pfVar17[1];
          *(float *)(param_3 + uVar18 * 4) =
               ((float)(int)sVar11 * pfVar17[-1] - (float)(int)sVar8 * pfVar17[-1]) * param_7 +
               (float)(int)sVar8 * pfVar17[-1];
          *(float *)(param_3 + 4 + uVar18 * 4) =
               ((float)(int)sVar12 * fVar4 - (float)(int)sVar9 * fVar2) * param_7 +
               (float)(int)sVar9 * fVar2;
          *(float *)(param_3 + 8 + uVar18 * 4) =
               ((float)(int)sVar13 * fVar5 - (float)(int)sVar10 * fVar3) * param_7 +
               (float)(int)sVar10 * fVar3;
        }
        local_a8 = local_a8 + 1;
        pfVar17 = pfVar17 + 8;
      } while (local_a8 < (int)uVar19);
    }
  }
  if (*(char *)(iVar14 + 0x13) != '\0') {
    bVar6 = *(byte *)(iVar14 + 0x12);
    iVar15 = *(int *)(iVar14 + 0xc);
    pfVar17 = (float *)(iVar22 + 3 + (uint)*(ushort *)(iVar14 + 0x10) * (uint)bVar6 * 6 & 0xfffffffc
                       );
    iVar22 = 0;
    if (*(char *)(iVar14 + 0x13) != '\0') {
      pfVar25 = pfVar17 + 2;
      do {
        if ((*(uint *)(param_4 + ((int)(uint)abStack_78[iVar22] >> 5) * 4) &
            1 << (abStack_78[iVar22] & 0x1f)) != 0) {
          uVar19 = (uint)*(ushort *)(iVar15 + (uint)bVar6 * 2 + iVar22 * 2);
          *(float *)(param_3 + uVar19 * 4) = pfVar25[-2];
          *(float *)(param_3 + 4 + uVar19 * 4) = pfVar25[-1];
          *(float *)(param_3 + 8 + uVar19 * 4) = *pfVar25;
        }
        pfVar17 = (float *)(uint)*(byte *)(iVar14 + 0x13);
        iVar22 = iVar22 + 1;
        pfVar25 = pfVar25 + 3;
      } while (iVar22 < (int)pfVar17);
    }
  }
  return CONCAT31((int3)((uint)pfVar17 >> 8),1);
}


// ==== 0x635c90 FUN_00635c90

undefined4 __thiscall
FUN_00635c90(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            float param_7)

{
  short *psVar1;
  short *psVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  byte bVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  short *psVar17;
  short *psVar18;
  undefined4 uVar19;
  float *pfVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  ushort *puVar24;
  int iVar25;
  
  iVar16 = param_3;
  *(short *)(param_1 + 0x10) = (short)param_6;
  if (param_4 == 0) {
    iVar14 = *(int *)(param_1 + 0xc);
    uVar21 = (uint)*(byte *)(iVar14 + 0x12);
    iVar3 = uVar21 * 0x20 + 0x18 + iVar14;
    psVar18 = (short *)(iVar3 + uVar21 * param_6 * 6);
    iVar15 = *(int *)(iVar14 + 0xc);
    if ((char)param_5 == '\0') {
      iVar22 = 0;
      param_5 = 0;
      if (3 < uVar21) {
        param_7 = 4.2039e-45;
        psVar17 = psVar18;
        pfVar20 = (float *)(iVar14 + 0x30);
        puVar24 = (ushort *)(iVar15 + 4);
        do {
          uVar23 = (uint)puVar24[-2];
          psVar18 = psVar17 + 0xc;
          *(float *)(param_3 + uVar23 * 4) = (float)(int)*psVar17 * pfVar20[-2];
          *(float *)(param_3 + 4 + uVar23 * 4) = (float)(int)psVar17[1] * pfVar20[-1];
          *(float *)(param_3 + 8 + uVar23 * 4) = (float)(int)psVar17[2] * *pfVar20;
          uVar23 = (uint)puVar24[-1];
          *(float *)(param_3 + uVar23 * 4) = (float)(int)psVar17[3] * pfVar20[6];
          *(float *)(param_3 + 4 + uVar23 * 4) = (float)(int)psVar17[4] * pfVar20[7];
          *(float *)(param_3 + 8 + uVar23 * 4) = (float)(int)psVar17[5] * pfVar20[8];
          uVar23 = (uint)*puVar24;
          *(float *)(param_3 + uVar23 * 4) = (float)(int)psVar17[6] * pfVar20[0xe];
          *(float *)(param_3 + 4 + uVar23 * 4) = (float)(int)psVar17[7] * pfVar20[0xf];
          *(float *)(param_3 + 8 + uVar23 * 4) = (float)(int)psVar17[8] * pfVar20[0x10];
          uVar23 = (uint)puVar24[1];
          *(float *)(param_3 + uVar23 * 4) = (float)(int)psVar17[9] * pfVar20[0x16];
          *(float *)(param_3 + 4 + uVar23 * 4) = (float)(int)psVar17[10] * pfVar20[0x17];
          iVar22 = param_5 + 4;
          *(float *)(param_3 + 8 + uVar23 * 4) = (float)(int)psVar17[0xb] * pfVar20[0x18];
          param_7 = (float)((int)param_7 + 4);
          psVar17 = psVar18;
          pfVar20 = pfVar20 + 0x20;
          puVar24 = puVar24 + 4;
          param_5 = iVar22;
        } while ((int)param_7 < (int)uVar21);
      }
      if (iVar22 < (int)uVar21) {
        psVar17 = psVar18;
        pfVar20 = (float *)(iVar22 * 0x20 + 0x30 + iVar14);
        do {
          uVar23 = (uint)*(ushort *)(iVar15 + iVar22 * 2);
          psVar18 = psVar17 + 3;
          iVar22 = iVar22 + 1;
          *(float *)(param_3 + uVar23 * 4) = (float)(int)*psVar17 * pfVar20[-2];
          *(float *)(param_3 + 4 + uVar23 * 4) = (float)(int)psVar17[1] * pfVar20[-1];
          *(float *)(param_3 + 8 + uVar23 * 4) = (float)(int)psVar17[2] * *pfVar20;
          psVar17 = psVar18;
          pfVar20 = pfVar20 + 8;
        } while (iVar22 < (int)uVar21);
      }
    }
    else {
      psVar17 = (short *)(iVar3 + (param_6 + 1) * uVar21 * 6);
      iVar22 = 0;
      param_5 = 0;
      if (3 < uVar21) {
        puVar24 = (ushort *)(iVar15 + 4);
        param_3 = 3;
        pfVar20 = (float *)(iVar14 + 0x4c);
        do {
          sVar9 = psVar18[1];
          sVar10 = psVar18[2];
          fVar4 = pfVar20[-8];
          sVar11 = psVar17[1];
          fVar5 = pfVar20[-7];
          sVar12 = psVar17[2];
          uVar23 = (uint)puVar24[-2];
          fVar6 = pfVar20[-8];
          fVar7 = pfVar20[-7];
          *(float *)(iVar16 + uVar23 * 4) =
               ((float)(int)*psVar17 * pfVar20[-9] - (float)(int)*psVar18 * pfVar20[-9]) * param_7 +
               (float)(int)*psVar18 * pfVar20[-9];
          *(float *)(iVar16 + 4 + uVar23 * 4) =
               ((float)(int)sVar11 * fVar6 - (float)(int)sVar9 * fVar4) * param_7 +
               (float)(int)sVar9 * fVar4;
          *(float *)(iVar16 + 8 + uVar23 * 4) =
               ((float)(int)sVar12 * fVar7 - (float)(int)sVar10 * fVar5) * param_7 +
               (float)(int)sVar10 * fVar5;
          sVar9 = psVar18[4];
          sVar10 = psVar18[5];
          fVar4 = *pfVar20;
          sVar11 = psVar17[4];
          fVar5 = pfVar20[1];
          sVar12 = psVar17[5];
          uVar23 = (uint)puVar24[-1];
          fVar6 = *pfVar20;
          fVar7 = pfVar20[1];
          *(float *)(iVar16 + uVar23 * 4) =
               ((float)(int)psVar17[3] * pfVar20[-1] - (float)(int)psVar18[3] * pfVar20[-1]) *
               param_7 + (float)(int)psVar18[3] * pfVar20[-1];
          *(float *)(iVar16 + 4 + uVar23 * 4) =
               ((float)(int)sVar11 * fVar6 - (float)(int)sVar9 * fVar4) * param_7 +
               (float)(int)sVar9 * fVar4;
          *(float *)(iVar16 + 8 + uVar23 * 4) =
               ((float)(int)sVar12 * fVar7 - (float)(int)sVar10 * fVar5) * param_7 +
               (float)(int)sVar10 * fVar5;
          sVar9 = psVar18[7];
          sVar10 = psVar18[8];
          fVar4 = pfVar20[8];
          sVar11 = psVar17[7];
          fVar5 = pfVar20[9];
          sVar12 = psVar17[8];
          uVar23 = (uint)*puVar24;
          fVar6 = pfVar20[8];
          fVar7 = pfVar20[9];
          *(float *)(iVar16 + uVar23 * 4) =
               ((float)(int)psVar17[6] * pfVar20[7] - (float)(int)psVar18[6] * pfVar20[7]) * param_7
               + (float)(int)psVar18[6] * pfVar20[7];
          *(float *)(iVar16 + 4 + uVar23 * 4) =
               ((float)(int)sVar11 * fVar6 - (float)(int)sVar9 * fVar4) * param_7 +
               (float)(int)sVar9 * fVar4;
          *(float *)(iVar16 + 8 + uVar23 * 4) =
               ((float)(int)sVar12 * fVar7 - (float)(int)sVar10 * fVar5) * param_7 +
               (float)(int)sVar10 * fVar5;
          psVar1 = psVar18 + 9;
          sVar9 = psVar18[10];
          sVar10 = psVar18[0xb];
          psVar2 = psVar17 + 9;
          fVar4 = pfVar20[0x10];
          sVar11 = psVar17[10];
          fVar5 = pfVar20[0x11];
          fVar6 = pfVar20[0x10];
          sVar12 = psVar17[0xb];
          uVar23 = (uint)puVar24[1];
          puVar24 = puVar24 + 4;
          fVar7 = pfVar20[0x11];
          psVar18 = psVar18 + 0xc;
          psVar17 = psVar17 + 0xc;
          *(float *)(iVar16 + uVar23 * 4) =
               ((float)(int)*psVar2 * pfVar20[0xf] - (float)(int)*psVar1 * pfVar20[0xf]) * param_7 +
               (float)(int)*psVar1 * pfVar20[0xf];
          *(float *)(iVar16 + 4 + uVar23 * 4) =
               ((float)(int)sVar11 * fVar6 - (float)(int)sVar9 * fVar4) * param_7 +
               (float)(int)sVar9 * fVar4;
          *(float *)(iVar16 + 8 + uVar23 * 4) =
               ((float)(int)sVar12 * fVar7 - (float)(int)sVar10 * fVar5) * param_7 +
               (float)(int)sVar10 * fVar5;
          iVar22 = param_5 + 4;
          param_3 = param_3 + 4;
          pfVar20 = pfVar20 + 0x20;
          param_5 = iVar22;
        } while (param_3 < (int)uVar21);
      }
      if (iVar22 < (int)uVar21) {
        pfVar20 = (float *)(iVar22 * 0x20 + 0x2c + iVar14);
        do {
          sVar9 = *psVar18;
          sVar10 = psVar18[1];
          sVar11 = psVar18[2];
          fVar4 = *pfVar20;
          sVar12 = psVar17[1];
          fVar5 = pfVar20[1];
          psVar18 = psVar18 + 3;
          sVar13 = psVar17[2];
          uVar23 = (uint)*(ushort *)(iVar15 + iVar22 * 2);
          fVar6 = *pfVar20;
          iVar22 = iVar22 + 1;
          fVar7 = pfVar20[1];
          *(float *)(iVar16 + uVar23 * 4) =
               ((float)(int)*psVar17 * pfVar20[-1] - (float)(int)sVar9 * pfVar20[-1]) * param_7 +
               (float)(int)sVar9 * pfVar20[-1];
          *(float *)(iVar16 + 4 + uVar23 * 4) =
               ((float)(int)sVar12 * fVar6 - (float)(int)sVar10 * fVar4) * param_7 +
               (float)(int)sVar10 * fVar4;
          *(float *)(iVar16 + 8 + uVar23 * 4) =
               ((float)(int)sVar13 * fVar7 - (float)(int)sVar11 * fVar5) * param_7 +
               (float)(int)sVar11 * fVar5;
          pfVar20 = pfVar20 + 8;
          psVar17 = psVar17 + 3;
        } while (iVar22 < (int)uVar21);
      }
    }
    if (*(char *)(iVar14 + 0x13) != '\0') {
      bVar8 = *(byte *)(iVar14 + 0x12);
      iVar15 = *(int *)(iVar14 + 0xc);
      iVar22 = (uint)*(ushort *)(iVar14 + 0x10) * (uint)bVar8;
      psVar18 = (short *)(iVar22 * 3);
      iVar25 = 0;
      if (*(char *)(iVar14 + 0x13) != '\0') {
        psVar18 = (short *)((iVar3 + 3 + iVar22 * 6 & 0xfffffffcU) + 8);
        do {
          uVar21 = (uint)*(ushort *)(iVar15 + (uint)bVar8 * 2 + iVar25 * 2);
          *(undefined4 *)(iVar16 + uVar21 * 4) = *(undefined4 *)(psVar18 + -4);
          *(undefined4 *)(iVar16 + 4 + uVar21 * 4) = *(undefined4 *)(psVar18 + -2);
          *(undefined4 *)(iVar16 + 8 + uVar21 * 4) = *(undefined4 *)psVar18;
          iVar25 = iVar25 + 1;
          psVar18 = psVar18 + 6;
        } while (iVar25 < (int)(uint)*(byte *)(iVar14 + 0x13));
      }
    }
    return CONCAT31((int3)((uint)psVar18 >> 8),1);
  }
  uVar19 = FUN_00635440(param_2,param_3,param_4,param_5,param_6,param_7);
  return uVar19;
}


// ==== 0x6362b0 FUN_006362b0

undefined4 * __thiscall FUN_006362b0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a8590;
  FUN_00628ed0();
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x18);
  }
  return param_1;
}


// ==== 0x6362e0 FUN_006362e0

undefined4 __thiscall FUN_006362e0(int param_1,float param_2,int param_3,int param_4)

{
  short *psVar1;
  short *psVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  byte bVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  int iVar13;
  int iVar14;
  bool bVar15;
  short *psVar16;
  short *psVar17;
  undefined4 uVar18;
  float *pfVar19;
  ushort *puVar20;
  ushort *puVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  uint uVar25;
  float fStack_38;
  uint uStack_34;
  int iStack_28;
  float fStack_24;
  
  if (*(char *)(param_1 + 0x12) != '\0') {
    param_2 = (float)*(byte *)(param_1 + 0x13) * param_2;
  }
  iVar13 = *(int *)(param_1 + 0xc);
  if (param_2 < 0.0) {
    fStack_24 = param_2 + 0.499999;
  }
  else {
    fStack_24 = param_2 - 0.499999;
  }
  iStack_28 = (int)ROUND(fStack_24);
  puVar21 = *(ushort **)(iVar13 + 8);
  fStack_38 = 0.0;
  uStack_34._1_3_ = (uint3)((uint)iStack_28 >> 8);
  if (puVar21 == (ushort *)0x0) {
    if (iStack_28 < 0) {
      iVar22 = 0;
    }
    else {
      iVar22 = iStack_28;
      if ((int)(uint)*(ushort *)(iVar13 + 0x10) <= iStack_28) {
        iVar22 = *(ushort *)(iVar13 + 0x10) - 1;
      }
    }
    fStack_38 = (float)iStack_28;
    if (param_2 == fStack_38) {
      bVar15 = false;
      uStack_34 = (uint)uStack_34._1_3_ << 8;
      fStack_38 = param_2 - fStack_38;
    }
    else {
      bVar15 = true;
      uStack_34 = CONCAT31(uStack_34._1_3_,1);
      fStack_38 = param_2 - fStack_38;
    }
  }
  else {
    if (iStack_28 < (int)(uint)*puVar21) {
      iVar22 = 0;
    }
    else {
      if (*(ushort *)(param_1 + 0x10) == 0) {
        iVar24 = 0;
      }
      else {
        iVar24 = *(ushort *)(param_1 + 0x10) - 1;
      }
      puVar20 = puVar21 + iVar24;
      if (iStack_28 < (int)(uint)puVar21[iVar24]) {
        for (; (0 < iVar24 && (iStack_28 < (int)(uint)*puVar20)); puVar20 = puVar20 + -1) {
          iVar24 = iVar24 + -1;
        }
      }
      else {
        while ((iVar24 < (int)(*(ushort *)(iVar13 + 0x10) - 2) &&
               (puVar20 = puVar20 + 1, (int)(uint)*puVar20 <= iStack_28))) {
          iVar24 = iVar24 + 1;
        }
      }
      iVar22 = iVar24 + 1;
      if (iVar22 != 0) {
        fVar3 = (float)puVar21[iVar24];
        if (param_2 == fVar3) {
          bVar15 = false;
          uStack_34 = (uint)uStack_34._1_3_ << 8;
        }
        else {
          bVar15 = true;
          uStack_34 = CONCAT31(uStack_34._1_3_,1);
          fStack_38 = (param_2 - fVar3) / ((float)puVar21[iVar22] - fVar3);
        }
        goto LAB_0063647b;
      }
    }
    if (param_2 == 0.0) {
      bVar15 = false;
      uStack_34 = (uint)uStack_34._1_3_ << 8;
    }
    else {
      bVar15 = true;
      uStack_34 = CONCAT31(uStack_34._1_3_,1);
      fStack_38 = param_2 / (float)*puVar21;
    }
  }
LAB_0063647b:
  if ((int)(*(ushort *)(iVar13 + 0x10) - 1) <= iVar22) {
    bVar15 = false;
    uStack_34 = uStack_34 & 0xffffff00;
  }
  *(short *)(param_1 + 0x10) = (short)iVar22;
  if (param_4 != 0) {
    uVar18 = FUN_00635440(param_2,param_3,param_4,uStack_34,iVar22,fStack_38);
    return uVar18;
  }
  uVar25 = (uint)*(byte *)(iVar13 + 0x12);
  iVar14 = *(int *)(iVar13 + 0xc);
  iVar24 = uVar25 * 0x20 + 0x18 + iVar13;
  psVar17 = (short *)(iVar24 + uVar25 * iVar22 * 6);
  if (bVar15) {
    psVar16 = (short *)(iVar24 + (iVar22 + 1) * uVar25 * 6);
    iVar22 = 0;
    uStack_34 = 0;
    if (3 < uVar25) {
      iStack_28 = 3;
      puVar21 = (ushort *)(iVar14 + 4);
      pfVar19 = (float *)(iVar13 + 0x4c);
      do {
        sVar8 = psVar17[1];
        sVar9 = psVar17[2];
        fVar3 = pfVar19[-8];
        sVar10 = psVar16[1];
        fVar4 = pfVar19[-7];
        sVar11 = psVar16[2];
        uVar23 = (uint)puVar21[-2];
        fVar5 = pfVar19[-8];
        fVar6 = pfVar19[-7];
        *(float *)(param_3 + uVar23 * 4) =
             ((float)(int)*psVar16 * pfVar19[-9] - (float)(int)*psVar17 * pfVar19[-9]) * fStack_38 +
             (float)(int)*psVar17 * pfVar19[-9];
        *(float *)(param_3 + 4 + uVar23 * 4) =
             ((float)(int)sVar10 * fVar5 - (float)(int)sVar8 * fVar3) * fStack_38 +
             (float)(int)sVar8 * fVar3;
        *(float *)(param_3 + 8 + uVar23 * 4) =
             ((float)(int)sVar11 * fVar6 - (float)(int)sVar9 * fVar4) * fStack_38 +
             (float)(int)sVar9 * fVar4;
        sVar8 = psVar17[4];
        sVar9 = psVar17[5];
        fVar3 = *pfVar19;
        sVar10 = psVar16[4];
        fVar4 = pfVar19[1];
        sVar11 = psVar16[5];
        uVar23 = (uint)puVar21[-1];
        fVar5 = *pfVar19;
        fVar6 = pfVar19[1];
        *(float *)(param_3 + uVar23 * 4) =
             ((float)(int)psVar16[3] * pfVar19[-1] - (float)(int)psVar17[3] * pfVar19[-1]) *
             fStack_38 + (float)(int)psVar17[3] * pfVar19[-1];
        *(float *)(param_3 + 4 + uVar23 * 4) =
             ((float)(int)sVar10 * fVar5 - (float)(int)sVar8 * fVar3) * fStack_38 +
             (float)(int)sVar8 * fVar3;
        *(float *)(param_3 + 8 + uVar23 * 4) =
             ((float)(int)sVar11 * fVar6 - (float)(int)sVar9 * fVar4) * fStack_38 +
             (float)(int)sVar9 * fVar4;
        sVar8 = psVar17[7];
        sVar9 = psVar17[8];
        fVar3 = pfVar19[8];
        sVar10 = psVar16[7];
        fVar4 = pfVar19[9];
        sVar11 = psVar16[8];
        uVar23 = (uint)*puVar21;
        fVar5 = pfVar19[8];
        fVar6 = pfVar19[9];
        *(float *)(param_3 + uVar23 * 4) =
             ((float)(int)psVar16[6] * pfVar19[7] - (float)(int)psVar17[6] * pfVar19[7]) * fStack_38
             + (float)(int)psVar17[6] * pfVar19[7];
        *(float *)(param_3 + 4 + uVar23 * 4) =
             ((float)(int)sVar10 * fVar5 - (float)(int)sVar8 * fVar3) * fStack_38 +
             (float)(int)sVar8 * fVar3;
        *(float *)(param_3 + 8 + uVar23 * 4) =
             ((float)(int)sVar11 * fVar6 - (float)(int)sVar9 * fVar4) * fStack_38 +
             (float)(int)sVar9 * fVar4;
        psVar1 = psVar17 + 9;
        sVar8 = psVar17[10];
        sVar9 = psVar17[0xb];
        fVar3 = pfVar19[0x10];
        fVar4 = pfVar19[0x11];
        psVar2 = psVar16 + 9;
        sVar10 = psVar16[10];
        sVar11 = psVar16[0xb];
        fVar5 = pfVar19[0x10];
        uVar23 = (uint)puVar21[1];
        puVar21 = puVar21 + 4;
        psVar17 = psVar17 + 0xc;
        psVar16 = psVar16 + 0xc;
        fVar6 = pfVar19[0x11];
        *(float *)(param_3 + uVar23 * 4) =
             ((float)(int)*psVar2 * pfVar19[0xf] - (float)(int)*psVar1 * pfVar19[0xf]) * fStack_38 +
             (float)(int)*psVar1 * pfVar19[0xf];
        *(float *)(param_3 + 4 + uVar23 * 4) =
             ((float)(int)sVar10 * fVar5 - (float)(int)sVar8 * fVar3) * fStack_38 +
             (float)(int)sVar8 * fVar3;
        *(float *)(param_3 + 8 + uVar23 * 4) =
             ((float)(int)sVar11 * fVar6 - (float)(int)sVar9 * fVar4) * fStack_38 +
             (float)(int)sVar9 * fVar4;
        iStack_28 = iStack_28 + 4;
        iVar22 = uStack_34 + 4;
        pfVar19 = pfVar19 + 0x20;
        uStack_34 = iVar22;
      } while (iStack_28 < (int)uVar25);
    }
    if (iVar22 < (int)uVar25) {
      pfVar19 = (float *)(iVar22 * 0x20 + 0x2c + iVar13);
      do {
        sVar8 = *psVar17;
        sVar9 = psVar17[1];
        sVar10 = psVar17[2];
        fVar3 = *pfVar19;
        sVar11 = psVar16[1];
        fVar4 = pfVar19[1];
        sVar12 = psVar16[2];
        uVar23 = (uint)*(ushort *)(iVar14 + iVar22 * 2);
        fVar5 = *pfVar19;
        psVar17 = psVar17 + 3;
        iVar22 = iVar22 + 1;
        fVar6 = pfVar19[1];
        *(float *)(param_3 + uVar23 * 4) =
             ((float)(int)*psVar16 * pfVar19[-1] - (float)(int)sVar8 * pfVar19[-1]) * fStack_38 +
             (float)(int)sVar8 * pfVar19[-1];
        *(float *)(param_3 + 4 + uVar23 * 4) =
             ((float)(int)sVar11 * fVar5 - (float)(int)sVar9 * fVar3) * fStack_38 +
             (float)(int)sVar9 * fVar3;
        *(float *)(param_3 + 8 + uVar23 * 4) =
             ((float)(int)sVar12 * fVar6 - (float)(int)sVar10 * fVar4) * fStack_38 +
             (float)(int)sVar10 * fVar4;
        pfVar19 = pfVar19 + 8;
        psVar16 = psVar16 + 3;
      } while (iVar22 < (int)uVar25);
    }
  }
  else {
    iVar22 = 0;
    if (3 < uVar25) {
      iStack_28 = 3;
      pfVar19 = (float *)(iVar13 + 0x30);
      puVar21 = (ushort *)(iVar14 + 4);
      do {
        uVar23 = (uint)puVar21[-2];
        iVar22 = iVar22 + 4;
        *(float *)(param_3 + uVar23 * 4) = (float)(int)*psVar17 * pfVar19[-2];
        *(float *)(param_3 + 4 + uVar23 * 4) = (float)(int)psVar17[1] * pfVar19[-1];
        *(float *)(param_3 + 8 + uVar23 * 4) = (float)(int)psVar17[2] * *pfVar19;
        uVar23 = (uint)puVar21[-1];
        *(float *)(param_3 + uVar23 * 4) = (float)(int)psVar17[3] * pfVar19[6];
        *(float *)(param_3 + 4 + uVar23 * 4) = (float)(int)psVar17[4] * pfVar19[7];
        *(float *)(param_3 + 8 + uVar23 * 4) = (float)(int)psVar17[5] * pfVar19[8];
        uVar23 = (uint)*puVar21;
        *(float *)(param_3 + uVar23 * 4) = (float)(int)psVar17[6] * pfVar19[0xe];
        *(float *)(param_3 + 4 + uVar23 * 4) = (float)(int)psVar17[7] * pfVar19[0xf];
        *(float *)(param_3 + 8 + uVar23 * 4) = (float)(int)psVar17[8] * pfVar19[0x10];
        uVar23 = (uint)puVar21[1];
        *(float *)(param_3 + uVar23 * 4) = (float)(int)psVar17[9] * pfVar19[0x16];
        *(float *)(param_3 + 4 + uVar23 * 4) = (float)(int)psVar17[10] * pfVar19[0x17];
        *(float *)(param_3 + 8 + uVar23 * 4) = (float)(int)psVar17[0xb] * pfVar19[0x18];
        iStack_28 = iStack_28 + 4;
        psVar17 = psVar17 + 0xc;
        pfVar19 = pfVar19 + 0x20;
        puVar21 = puVar21 + 4;
      } while (iStack_28 < (int)uVar25);
    }
    if (iVar22 < (int)uVar25) {
      psVar16 = psVar17;
      pfVar19 = (float *)(iVar22 * 0x20 + 0x30 + iVar13);
      do {
        uVar23 = (uint)*(ushort *)(iVar14 + iVar22 * 2);
        psVar17 = psVar16 + 3;
        iVar22 = iVar22 + 1;
        *(float *)(param_3 + uVar23 * 4) = (float)(int)*psVar16 * pfVar19[-2];
        *(float *)(param_3 + 4 + uVar23 * 4) = (float)(int)psVar16[1] * pfVar19[-1];
        *(float *)(param_3 + 8 + uVar23 * 4) = (float)(int)psVar16[2] * *pfVar19;
        psVar16 = psVar17;
        pfVar19 = pfVar19 + 8;
      } while (iVar22 < (int)uVar25);
    }
  }
  if (*(char *)(iVar13 + 0x13) != '\0') {
    bVar7 = *(byte *)(iVar13 + 0x12);
    iVar22 = *(int *)(iVar13 + 0xc);
    psVar17 = (short *)(iVar24 + 3 + (uint)*(ushort *)(iVar13 + 0x10) * (uint)bVar7 * 6 & 0xfffffffc
                       );
    iVar24 = 0;
    if (*(char *)(iVar13 + 0x13) != '\0') {
      psVar17 = psVar17 + 4;
      do {
        uVar25 = (uint)*(ushort *)(iVar22 + (uint)bVar7 * 2 + iVar24 * 2);
        *(undefined4 *)(param_3 + uVar25 * 4) = *(undefined4 *)(psVar17 + -4);
        *(undefined4 *)(param_3 + 4 + uVar25 * 4) = *(undefined4 *)(psVar17 + -2);
        *(undefined4 *)(param_3 + 8 + uVar25 * 4) = *(undefined4 *)psVar17;
        iVar24 = iVar24 + 1;
        psVar17 = psVar17 + 6;
      } while (iVar24 < (int)(uint)*(byte *)(iVar13 + 0x13));
    }
  }
  return CONCAT31((int3)((uint)psVar17 >> 8),1);
}


// ==== 0x636564 FUN_00636564

undefined4 __fastcall FUN_00636564(float *param_1,short *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  byte bVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  int iVar11;
  short *in_EAX;
  short *psVar12;
  float *pfVar13;
  short *psVar14;
  uint unaff_EBX;
  uint uVar15;
  int unaff_EBP;
  ushort *unaff_ESI;
  int iVar16;
  int unaff_EDI;
  float10 in_ST0;
  float10 in_ST1;
  float10 in_ST2;
  float in_stack_00000010;
  int in_stack_00000014;
  int in_stack_0000001c;
  int in_stack_00000020;
  int in_stack_00000024;
  int in_stack_0000002c;
  float in_stack_00000034;
  float in_stack_00000038;
  float in_stack_00000044;
  int in_stack_00000050;
  
  while( true ) {
    *(float *)(unaff_EBP + unaff_EBX * 4) = (float)(in_ST0 + in_ST2);
    *(float *)(in_stack_00000050 + 4 + unaff_EBX * 4) =
         (float)(((float10)in_stack_00000034 - in_ST1) * (float10)in_stack_00000010 + in_ST1);
    *(float *)(in_stack_00000050 + 8 + unaff_EBX * 4) =
         (in_stack_00000038 - in_stack_00000044) * in_stack_00000010 + in_stack_00000044;
    sVar6 = in_EAX[4];
    sVar7 = in_EAX[5];
    fVar1 = *param_1;
    sVar8 = param_2[4];
    fVar2 = param_1[1];
    sVar9 = param_2[5];
    uVar15 = (uint)unaff_ESI[-1];
    fVar3 = *param_1;
    fVar4 = param_1[1];
    *(float *)(in_stack_00000050 + uVar15 * 4) =
         ((float)(int)param_2[3] * param_1[-1] - (float)(int)in_EAX[3] * param_1[-1]) *
         in_stack_00000010 + (float)(int)in_EAX[3] * param_1[-1];
    *(float *)(in_stack_00000050 + 4 + uVar15 * 4) =
         ((float)(int)sVar8 * fVar3 - (float)(int)sVar6 * fVar1) * in_stack_00000010 +
         (float)(int)sVar6 * fVar1;
    *(float *)(in_stack_00000050 + 8 + uVar15 * 4) =
         ((float)(int)sVar9 * fVar4 - (float)(int)sVar7 * fVar2) * in_stack_00000010 +
         (float)(int)sVar7 * fVar2;
    sVar6 = in_EAX[7];
    sVar7 = in_EAX[8];
    fVar1 = param_1[8];
    sVar8 = param_2[7];
    fVar2 = param_1[9];
    sVar9 = param_2[8];
    uVar15 = (uint)*unaff_ESI;
    fVar3 = param_1[8];
    fVar4 = param_1[9];
    *(float *)(in_stack_00000050 + uVar15 * 4) =
         ((float)(int)param_2[6] * param_1[7] - (float)(int)in_EAX[6] * param_1[7]) *
         in_stack_00000010 + (float)(int)in_EAX[6] * param_1[7];
    *(float *)(in_stack_00000050 + 4 + uVar15 * 4) =
         ((float)(int)sVar8 * fVar3 - (float)(int)sVar6 * fVar1) * in_stack_00000010 +
         (float)(int)sVar6 * fVar1;
    *(float *)(in_stack_00000050 + 8 + uVar15 * 4) =
         ((float)(int)sVar9 * fVar4 - (float)(int)sVar7 * fVar2) * in_stack_00000010 +
         (float)(int)sVar7 * fVar2;
    sVar6 = in_EAX[10];
    sVar7 = in_EAX[0xb];
    fVar1 = param_1[0x10];
    fVar2 = param_1[0x11];
    sVar8 = param_2[10];
    sVar9 = param_2[0xb];
    fVar3 = param_1[0x10];
    uVar15 = (uint)unaff_ESI[1];
    psVar12 = in_EAX + 0xc;
    psVar14 = param_2 + 0xc;
    fVar4 = param_1[0x11];
    *(float *)(in_stack_00000050 + uVar15 * 4) =
         ((float)(int)param_2[9] * param_1[0xf] - (float)(int)in_EAX[9] * param_1[0xf]) *
         in_stack_00000010 + (float)(int)in_EAX[9] * param_1[0xf];
    *(float *)(in_stack_00000050 + 4 + uVar15 * 4) =
         ((float)(int)sVar8 * fVar3 - (float)(int)sVar6 * fVar1) * in_stack_00000010 +
         (float)(int)sVar6 * fVar1;
    *(float *)(in_stack_00000050 + 8 + uVar15 * 4) =
         ((float)(int)sVar9 * fVar4 - (float)(int)sVar7 * fVar2) * in_stack_00000010 +
         (float)(int)sVar7 * fVar2;
    in_stack_00000020 = in_stack_00000020 + 4;
    in_stack_00000014 = in_stack_00000014 + 4;
    if (unaff_EDI <= in_stack_00000020) break;
    in_ST2 = (float10)(int)*psVar12 * (float10)param_1[0x17];
    in_ST1 = (float10)(int)in_EAX[0xd] * (float10)param_1[0x18];
    in_stack_00000044 = (float)(int)in_EAX[0xe] * param_1[0x19];
    unaff_EBX = (uint)unaff_ESI[2];
    in_stack_00000034 = (float)(int)param_2[0xd] * param_1[0x18];
    in_stack_00000038 = (float)(int)param_2[0xe] * param_1[0x19];
    in_ST0 = ((float10)(int)*psVar14 * (float10)param_1[0x17] - in_ST2) * (float10)in_stack_00000010
    ;
    in_EAX = psVar12;
    param_1 = param_1 + 0x20;
    param_2 = psVar14;
    unaff_EBP = in_stack_00000050;
    unaff_ESI = unaff_ESI + 4;
  }
  if (in_stack_00000014 < unaff_EDI) {
    pfVar13 = (float *)(in_stack_00000014 * 0x20 + 0x2c + in_stack_0000001c);
    do {
      sVar6 = *psVar12;
      sVar7 = psVar12[1];
      sVar8 = psVar12[2];
      fVar1 = *pfVar13;
      sVar9 = psVar14[1];
      fVar2 = pfVar13[1];
      sVar10 = psVar14[2];
      uVar15 = (uint)*(ushort *)(in_stack_00000024 + in_stack_00000014 * 2);
      fVar3 = *pfVar13;
      psVar12 = psVar12 + 3;
      in_stack_00000014 = in_stack_00000014 + 1;
      fVar4 = pfVar13[1];
      *(float *)(in_stack_00000050 + uVar15 * 4) =
           ((float)(int)*psVar14 * pfVar13[-1] - (float)(int)sVar6 * pfVar13[-1]) *
           in_stack_00000010 + (float)(int)sVar6 * pfVar13[-1];
      *(float *)(in_stack_00000050 + 4 + uVar15 * 4) =
           ((float)(int)sVar9 * fVar3 - (float)(int)sVar7 * fVar1) * in_stack_00000010 +
           (float)(int)sVar7 * fVar1;
      *(float *)(in_stack_00000050 + 8 + uVar15 * 4) =
           ((float)(int)sVar10 * fVar4 - (float)(int)sVar8 * fVar2) * in_stack_00000010 +
           (float)(int)sVar8 * fVar2;
      pfVar13 = pfVar13 + 8;
      psVar14 = psVar14 + 3;
    } while (in_stack_00000014 < unaff_EDI);
  }
  if (*(char *)(in_stack_0000001c + 0x13) != '\0') {
    bVar5 = *(byte *)(in_stack_0000001c + 0x12);
    iVar11 = *(int *)(in_stack_0000001c + 0xc);
    psVar12 = (short *)(in_stack_0000002c + 3 +
                        (uint)*(ushort *)(in_stack_0000001c + 0x10) * (uint)bVar5 * 6 & 0xfffffffc);
    iVar16 = 0;
    if (*(char *)(in_stack_0000001c + 0x13) != '\0') {
      psVar12 = psVar12 + 4;
      do {
        uVar15 = (uint)*(ushort *)(iVar11 + (uint)bVar5 * 2 + iVar16 * 2);
        *(undefined4 *)(in_stack_00000050 + uVar15 * 4) = *(undefined4 *)(psVar12 + -4);
        *(undefined4 *)(in_stack_00000050 + 4 + uVar15 * 4) = *(undefined4 *)(psVar12 + -2);
        *(undefined4 *)(in_stack_00000050 + 8 + uVar15 * 4) = *(undefined4 *)psVar12;
        iVar16 = iVar16 + 1;
        psVar12 = psVar12 + 6;
      } while (iVar16 < (int)(uint)*(byte *)(in_stack_0000001c + 0x13));
    }
  }
  return CONCAT31((int3)((uint)psVar12 >> 8),1);
}


// ==== 0x636974 FUN_00636974

undefined4 __fastcall FUN_00636974(float *param_1,ushort *param_2)

{
  byte bVar1;
  int iVar2;
  short *in_EAX;
  short *psVar3;
  short *psVar4;
  float *pfVar5;
  uint unaff_EBX;
  uint uVar6;
  int unaff_EBP;
  int unaff_ESI;
  int iVar7;
  int unaff_EDI;
  int in_stack_0000001c;
  int in_stack_00000020;
  int in_stack_00000024;
  int in_stack_0000002c;
  int in_stack_00000050;
  
  while( true ) {
    *(float *)(in_stack_00000050 + unaff_EBX * 4) = (float)unaff_EBP * param_1[-0x12];
    *(float *)(in_stack_00000050 + 4 + unaff_EBX * 4) = (float)(int)in_EAX[7] * param_1[-0x11];
    *(float *)(in_stack_00000050 + 8 + unaff_EBX * 4) = (float)(int)in_EAX[8] * param_1[-0x10];
    uVar6 = (uint)param_2[-3];
    *(float *)(in_stack_00000050 + uVar6 * 4) = (float)(int)in_EAX[9] * param_1[-10];
    *(float *)(in_stack_00000050 + 4 + uVar6 * 4) = (float)(int)in_EAX[10] * param_1[-9];
    *(float *)(in_stack_00000050 + 8 + uVar6 * 4) = (float)(int)in_EAX[0xb] * param_1[-8];
    in_stack_00000020 = in_stack_00000020 + 4;
    psVar4 = in_EAX + 0xc;
    if (unaff_EDI <= in_stack_00000020) break;
    uVar6 = (uint)param_2[-2];
    unaff_ESI = unaff_ESI + 4;
    *(float *)(in_stack_00000050 + uVar6 * 4) = (float)(int)*psVar4 * param_1[-2];
    *(float *)(in_stack_00000050 + 4 + uVar6 * 4) = (float)(int)in_EAX[0xd] * param_1[-1];
    *(float *)(in_stack_00000050 + 8 + uVar6 * 4) = (float)(int)in_EAX[0xe] * *param_1;
    uVar6 = (uint)param_2[-1];
    *(float *)(in_stack_00000050 + uVar6 * 4) = (float)(int)in_EAX[0xf] * param_1[6];
    *(float *)(in_stack_00000050 + 4 + uVar6 * 4) = (float)(int)in_EAX[0x10] * param_1[7];
    *(float *)(in_stack_00000050 + 8 + uVar6 * 4) = (float)(int)in_EAX[0x11] * param_1[8];
    unaff_EBP = (int)in_EAX[0x12];
    unaff_EBX = (uint)*param_2;
    in_EAX = psVar4;
    param_1 = param_1 + 0x20;
    param_2 = param_2 + 4;
  }
  if (unaff_ESI < unaff_EDI) {
    psVar3 = psVar4;
    pfVar5 = (float *)(unaff_ESI * 0x20 + 0x30 + in_stack_0000001c);
    do {
      uVar6 = (uint)*(ushort *)(in_stack_00000024 + unaff_ESI * 2);
      psVar4 = psVar3 + 3;
      unaff_ESI = unaff_ESI + 1;
      *(float *)(in_stack_00000050 + uVar6 * 4) = (float)(int)*psVar3 * pfVar5[-2];
      *(float *)(in_stack_00000050 + 4 + uVar6 * 4) = (float)(int)psVar3[1] * pfVar5[-1];
      *(float *)(in_stack_00000050 + 8 + uVar6 * 4) = (float)(int)psVar3[2] * *pfVar5;
      psVar3 = psVar4;
      pfVar5 = pfVar5 + 8;
    } while (unaff_ESI < unaff_EDI);
  }
  if (*(char *)(in_stack_0000001c + 0x13) != '\0') {
    bVar1 = *(byte *)(in_stack_0000001c + 0x12);
    iVar2 = *(int *)(in_stack_0000001c + 0xc);
    psVar4 = (short *)(in_stack_0000002c + 3 +
                       (uint)*(ushort *)(in_stack_0000001c + 0x10) * (uint)bVar1 * 6 & 0xfffffffc);
    iVar7 = 0;
    if (*(char *)(in_stack_0000001c + 0x13) != '\0') {
      psVar4 = psVar4 + 4;
      do {
        uVar6 = (uint)*(ushort *)(iVar2 + (uint)bVar1 * 2 + iVar7 * 2);
        *(undefined4 *)(in_stack_00000050 + uVar6 * 4) = *(undefined4 *)(psVar4 + -4);
        *(undefined4 *)(in_stack_00000050 + 4 + uVar6 * 4) = *(undefined4 *)(psVar4 + -2);
        *(undefined4 *)(in_stack_00000050 + 8 + uVar6 * 4) = *(undefined4 *)psVar4;
        iVar7 = iVar7 + 1;
        psVar4 = psVar4 + 6;
      } while (iVar7 < (int)(uint)*(byte *)(in_stack_0000001c + 0x13));
    }
  }
  return CONCAT31((int3)((uint)psVar4 >> 8),1);
}


// ==== 0x636b20 FUN_00636b20

undefined4 * __fastcall FUN_00636b20(undefined4 *param_1)

{
  FUN_00628eb0();
  *param_1 = &PTR_FUN_006a85f0;
  param_1[2] = 0x16;
  return param_1;
}


// ==== 0x636b40 FUN_00636b40

void __fastcall FUN_00636b40(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a85f0;
  FUN_00628ed0();
  return;
}


// ==== 0x636b50 FUN_00636b50

undefined4 __thiscall FUN_00636b50(int param_1,float *param_2)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar2 + 8) == 0) {
    uVar1 = *(ushort *)(iVar2 + 0x14);
    *param_2 = (float)uVar1;
    return CONCAT31((uint3)(byte)(uVar1 >> 8),1);
  }
  iVar2 = *(ushort *)(*(int *)(iVar2 + 8) + -4 + (uint)*(ushort *)(iVar2 + 0x14) * 2) + 1;
  *param_2 = (float)iVar2;
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}


// ==== 0x636ba0 FUN_00636ba0

void __thiscall FUN_00636ba0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(*param_1 + 0x18))(param_3,param_4,0);
  return;
}


// ==== 0x636bc0 FUN_00636bc0

undefined4 __thiscall
FUN_00636bc0(int param_1,undefined4 param_2,int param_3,int param_4,char param_5,int param_6,
            float param_7)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  ushort *puVar11;
  uint uVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  ushort *puVar17;
  uint uVar18;
  byte *pbVar19;
  
  if (param_4 != *(int *)(param_1 + 0x14)) {
    *(int *)(param_1 + 0x14) = param_4;
  }
  iVar8 = *(int *)(param_1 + 0xc);
  uVar12 = (uint)*(byte *)(iVar8 + 0x16);
  iVar9 = *(int *)(iVar8 + 0xc);
  iVar1 = iVar8 + 0x18 + uVar12 * param_6 * 8;
  if ((param_5 == '\0') || ((int)(*(ushort *)(iVar8 + 0x14) - 1) <= param_6)) {
    _param_5 = 0;
    if (uVar12 != 0) {
      puVar11 = (ushort *)(iVar1 + 4);
      do {
        uVar18 = (uint)*(byte *)(_param_5 + iVar9);
        if ((*(uint *)(param_4 + ((int)uVar18 >> 5) * 4) & 1 << (*(byte *)(_param_5 + iVar9) & 0x1f)
            ) != 0) {
          *(uint *)(param_3 + 0x10 + uVar18 * 0x30) =
               ((puVar11[-2] & 0xffff8000) << 1 | puVar11[-2] & 0x7fff) << 0xf;
          *(uint *)(param_3 + 0x14 + uVar18 * 0x30) =
               ((puVar11[-1] & 0xffff8000) << 1 | puVar11[-1] & 0x7fff) << 0xf;
          *(uint *)(param_3 + 0x14 + (uVar18 * 0xc + 1) * 4) =
               ((*puVar11 & 0xffff8000) << 1 | *puVar11 & 0x7fff) << 0xf;
          *(uint *)(param_3 + 0x14 + (uVar18 * 0xc + 2) * 4) =
               ((puVar11[1] & 0xffff8000) << 1 | puVar11[1] & 0x7fff) << 0xf;
        }
        _param_5 = _param_5 + 1;
        puVar11 = puVar11 + 4;
      } while (_param_5 < (int)uVar12);
    }
  }
  else {
    iVar2 = iVar8 + 0x18 + (param_6 + 1) * uVar12 * 8;
    _param_5 = 0;
    if (3 < uVar12) {
      puVar17 = (ushort *)(iVar1 + 0x1e);
      puVar11 = (ushort *)(iVar2 + 0xe);
      pbVar19 = (byte *)(iVar9 + 1);
      do {
        uVar18 = (uint)pbVar19[-1];
        if ((*(uint *)(param_4 + ((int)uVar18 >> 5) * 4) & 1 << (pbVar19[-1] & 0x1f)) != 0) {
          fVar13 = (float)(((puVar17[-0xf] & 0xffff8000) << 1 | puVar17[-0xf] & 0x7fff) << 0xf);
          fVar14 = (float)(((puVar17[-0xe] & 0xffff8000) << 1 | puVar17[-0xe] & 0x7fff) << 0xf);
          fVar15 = (float)(((puVar17[-0xd] & 0xffff8000) << 1 | puVar17[-0xd] & 0x7fff) << 0xf);
          fVar16 = (float)(((puVar17[-0xc] & 0xffff8000) << 1 | puVar17[-0xc] & 0x7fff) << 0xf);
          uVar5 = puVar11[-6];
          uVar6 = puVar11[-5];
          uVar7 = puVar11[-4];
          *(float *)(param_3 + 0x10 + uVar18 * 0x30) =
               ((float)(((puVar11[-7] & 0xffff8000) << 1 | puVar11[-7] & 0x7fff) << 0xf) - fVar13) *
               param_7 + fVar13;
          *(float *)(param_3 + 0x14 + uVar18 * 0x30) =
               ((float)(((uVar5 & 0xffff8000) << 1 | uVar5 & 0x7fff) << 0xf) - fVar14) * param_7 +
               fVar14;
          *(float *)(param_3 + 0x18 + uVar18 * 0x30) =
               ((float)(((uVar6 & 0xffff8000) << 1 | uVar6 & 0x7fff) << 0xf) - fVar15) * param_7 +
               fVar15;
          *(float *)(param_3 + 0x1c + uVar18 * 0x30) =
               ((float)(((uVar7 & 0xffff8000) << 1 | uVar7 & 0x7fff) << 0xf) - fVar16) * param_7 +
               fVar16;
        }
        uVar18 = (uint)*pbVar19;
        if ((*(uint *)(param_4 + ((int)uVar18 >> 5) * 4) & 1 << (*pbVar19 & 0x1f)) != 0) {
          fVar13 = (float)(((puVar17[-0xb] & 0xffff8000) << 1 | puVar17[-0xb] & 0x7fff) << 0xf);
          fVar14 = (float)(((puVar17[-10] & 0xffff8000) << 1 | puVar17[-10] & 0x7fff) << 0xf);
          uVar10 = (uint)*(ushort *)((iVar1 - iVar2) + (int)puVar11);
          fVar15 = (float)(((puVar17[-9] & 0xffff8000) << 1 | puVar17[-9] & 0x7fff) << 0xf);
          fVar16 = (float)(((uVar10 & 0xffff8000) << 1 | uVar10 & 0x7fff) << 0xf);
          uVar5 = puVar11[-2];
          uVar6 = puVar11[-1];
          uVar7 = *puVar11;
          *(float *)(param_3 + 0x10 + uVar18 * 0x30) =
               ((float)(((puVar11[-3] & 0xffff8000) << 1 | puVar11[-3] & 0x7fff) << 0xf) - fVar13) *
               param_7 + fVar13;
          *(float *)(param_3 + 0x14 + uVar18 * 0x30) =
               ((float)(((uVar5 & 0xffff8000) << 1 | uVar5 & 0x7fff) << 0xf) - fVar14) * param_7 +
               fVar14;
          *(float *)(param_3 + 0x18 + uVar18 * 0x30) =
               ((float)(((uVar6 & 0xffff8000) << 1 | uVar6 & 0x7fff) << 0xf) - fVar15) * param_7 +
               fVar15;
          *(float *)(param_3 + 0x1c + uVar18 * 0x30) =
               ((float)(((uVar7 & 0xffff8000) << 1 | uVar7 & 0x7fff) << 0xf) - fVar16) * param_7 +
               fVar16;
        }
        uVar18 = (uint)pbVar19[1];
        if ((*(uint *)(param_4 + ((int)uVar18 >> 5) * 4) & 1 << (pbVar19[1] & 0x1f)) != 0) {
          fVar13 = (float)(((puVar17[-7] & 0xffff8000) << 1 | puVar17[-7] & 0x7fff) << 0xf);
          fVar14 = (float)(((puVar17[-6] & 0xffff8000) << 1 | puVar17[-6] & 0x7fff) << 0xf);
          fVar15 = (float)(((puVar17[-5] & 0xffff8000) << 1 | puVar17[-5] & 0x7fff) << 0xf);
          fVar16 = (float)(((puVar17[-4] & 0xffff8000) << 1 | puVar17[-4] & 0x7fff) << 0xf);
          uVar5 = puVar11[2];
          uVar6 = puVar11[3];
          uVar7 = puVar11[4];
          *(float *)(param_3 + 0x10 + uVar18 * 0x30) =
               ((float)(((puVar11[1] & 0xffff8000) << 1 | puVar11[1] & 0x7fff) << 0xf) - fVar13) *
               param_7 + fVar13;
          *(float *)(param_3 + 0x14 + uVar18 * 0x30) =
               ((float)(((uVar5 & 0xffff8000) << 1 | uVar5 & 0x7fff) << 0xf) - fVar14) * param_7 +
               fVar14;
          *(float *)(param_3 + 0x18 + uVar18 * 0x30) =
               ((float)(((uVar6 & 0xffff8000) << 1 | uVar6 & 0x7fff) << 0xf) - fVar15) * param_7 +
               fVar15;
          *(float *)(param_3 + 0x1c + uVar18 * 0x30) =
               ((float)(((uVar7 & 0xffff8000) << 1 | uVar7 & 0x7fff) << 0xf) - fVar16) * param_7 +
               fVar16;
        }
        uVar18 = (uint)pbVar19[2];
        if ((*(uint *)(param_4 + ((int)uVar18 >> 5) * 4) & 1 << (pbVar19[2] & 0x1f)) != 0) {
          fVar13 = (float)(((puVar17[-3] & 0xffff8000) << 1 | puVar17[-3] & 0x7fff) << 0xf);
          fVar14 = (float)(((puVar17[-2] & 0xffff8000) << 1 | puVar17[-2] & 0x7fff) << 0xf);
          fVar15 = (float)(((puVar17[-1] & 0xffff8000) << 1 | puVar17[-1] & 0x7fff) << 0xf);
          fVar16 = (float)(((*puVar17 & 0xffff8000) << 1 | *puVar17 & 0x7fff) << 0xf);
          uVar5 = puVar11[6];
          uVar6 = puVar11[7];
          uVar7 = puVar11[8];
          *(float *)(param_3 + 0x10 + uVar18 * 0x30) =
               ((float)(((puVar11[5] & 0xffff8000) << 1 | puVar11[5] & 0x7fff) << 0xf) - fVar13) *
               param_7 + fVar13;
          *(float *)(param_3 + 0x14 + uVar18 * 0x30) =
               ((float)(((uVar5 & 0xffff8000) << 1 | uVar5 & 0x7fff) << 0xf) - fVar14) * param_7 +
               fVar14;
          *(float *)(param_3 + 0x18 + uVar18 * 0x30) =
               ((float)(((uVar6 & 0xffff8000) << 1 | uVar6 & 0x7fff) << 0xf) - fVar15) * param_7 +
               fVar15;
          *(float *)(param_3 + 0x1c + uVar18 * 0x30) =
               ((float)(((uVar7 & 0xffff8000) << 1 | uVar7 & 0x7fff) << 0xf) - fVar16) * param_7 +
               fVar16;
        }
        pbVar19 = pbVar19 + 4;
        _param_5 = _param_5 + 4;
        puVar11 = puVar11 + 0x10;
        puVar17 = puVar17 + 0x10;
      } while ((int)(pbVar19 + (2 - iVar9)) < (int)uVar12);
    }
    if (_param_5 < (int)uVar12) {
      puVar11 = (ushort *)(iVar1 + 2 + _param_5 * 8);
      puVar17 = (ushort *)(iVar2 + 6 + _param_5 * 8);
      do {
        uVar18 = (uint)*(byte *)(_param_5 + iVar9);
        if ((*(uint *)(param_4 + ((int)uVar18 >> 5) * 4) & 1 << (*(byte *)(_param_5 + iVar9) & 0x1f)
            ) != 0) {
          fVar13 = (float)(((puVar11[-1] & 0xffff8000) << 1 | puVar11[-1] & 0x7fff) << 0xf);
          fVar14 = (float)(((*puVar11 & 0xffff8000) << 1 | *puVar11 & 0x7fff) << 0xf);
          uVar10 = (uint)*(ushort *)((iVar1 - iVar2) + (int)puVar17);
          fVar15 = (float)(((puVar11[1] & 0xffff8000) << 1 | puVar11[1] & 0x7fff) << 0xf);
          fVar16 = (float)(((uVar10 & 0xffff8000) << 1 | uVar10 & 0x7fff) << 0xf);
          uVar5 = puVar17[-2];
          uVar6 = puVar17[-1];
          uVar7 = *puVar17;
          *(float *)(param_3 + 0x10 + uVar18 * 0x30) =
               ((float)(((puVar17[-3] & 0xffff8000) << 1 | puVar17[-3] & 0x7fff) << 0xf) - fVar13) *
               param_7 + fVar13;
          *(float *)(param_3 + 0x14 + uVar18 * 0x30) =
               ((float)(((uVar5 & 0xffff8000) << 1 | uVar5 & 0x7fff) << 0xf) - fVar14) * param_7 +
               fVar14;
          *(float *)(param_3 + 0x18 + uVar18 * 0x30) =
               ((float)(((uVar6 & 0xffff8000) << 1 | uVar6 & 0x7fff) << 0xf) - fVar15) * param_7 +
               fVar15;
          *(float *)(param_3 + 0x1c + uVar18 * 0x30) =
               ((float)(((uVar7 & 0xffff8000) << 1 | uVar7 & 0x7fff) << 0xf) - fVar16) * param_7 +
               fVar16;
        }
        _param_5 = _param_5 + 1;
        puVar11 = puVar11 + 4;
        puVar17 = puVar17 + 4;
      } while (_param_5 < (int)uVar12);
    }
  }
  uVar12 = (uint)*(byte *)(iVar8 + 0x17);
  if (uVar12 != 0) {
    bVar3 = *(byte *)(iVar8 + 0x16);
    iVar1 = *(int *)(iVar8 + 0xc);
    puVar11 = (ushort *)(iVar8 + 0x18 + (uint)*(ushort *)(iVar8 + 0x14) * (uint)bVar3 * 8);
    _param_5 = 0;
    if (uVar12 != 0) {
      do {
        bVar4 = *(byte *)(iVar1 + (uint)bVar3 + _param_5);
        uVar18 = (uint)bVar4;
        if ((*(uint *)(param_4 + ((int)uVar18 >> 5) * 4) & 1 << (bVar4 & 0x1f)) != 0) {
          *(uint *)(param_3 + 0x10 + uVar18 * 0x30) =
               ((*puVar11 & 0xffff8000) << 1 | *puVar11 & 0x7fff) << 0xf;
          *(uint *)(param_3 + 0x14 + uVar18 * 0x30) =
               ((puVar11[1] & 0xffff8000) << 1 | puVar11[1] & 0x7fff) << 0xf;
          *(uint *)(param_3 + 0x14 + (uVar18 * 0xc + 1) * 4) =
               ((puVar11[2] & 0xffff8000) << 1 | puVar11[2] & 0x7fff) << 0xf;
          *(uint *)(param_3 + 0x14 + (uVar18 * 0xc + 2) * 4) =
               ((puVar11[3] & 0xffff8000) << 1 | puVar11[3] & 0x7fff) << 0xf;
          puVar11 = puVar11 + 4;
        }
        _param_5 = _param_5 + 1;
      } while (_param_5 < (int)uVar12);
    }
  }
  return 1;
}


// ==== 0x637590 FUN_00637590

void __thiscall FUN_00637590(int *param_1,char param_2)

{
  char cVar1;
  int iVar2;
  
  *(char *)((int)param_1 + 0x12) = param_2;
  if ((*(char *)((int)param_1 + 0x13) == '\0') && (param_2 != '\0')) {
    iVar2 = (**(code **)(*param_1 + 0x38))();
    if (iVar2 != 0) {
      cVar1 = FUN_006353a0(CONCAT22((short)((uint)&param_2 >> 0x10),1),&param_2);
      if (cVar1 != '\0') {
        *(char *)((int)param_1 + 0x13) = param_2;
      }
    }
  }
  return;
}


// ==== 0x6375e0 FUN_006375e0

undefined4 * __thiscall FUN_006375e0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_006a85f0;
  FUN_00628ed0();
  if ((param_2 & 1) != 0) {
    (*(code *)PTR_FUN_006dfaa0)(param_1,0x18);
  }
  return param_1;
}


// ==== 0x637610 FUN_00637610

undefined4 __thiscall FUN_00637610(int param_1,float param_2,int param_3,int param_4)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  bool bVar7;
  int iVar8;
  ushort *puVar9;
  ushort *puVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  uint uVar18;
  byte *pbVar19;
  bool bVar20;
  float local_40;
  int local_38;
  
  if (*(char *)(param_1 + 0x12) != '\0') {
    param_2 = (float)*(byte *)(param_1 + 0x13) * param_2;
  }
  iVar6 = *(int *)(param_1 + 0xc);
  if (param_2 < 0.0) {
    fVar14 = param_2 + 0.499999;
  }
  else {
    fVar14 = param_2 - 0.499999;
  }
  local_38 = (int)ROUND(fVar14);
  puVar9 = *(ushort **)(iVar6 + 8);
  local_40 = 0.0;
  if (puVar9 == (ushort *)0x0) {
    if (local_38 < 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = local_38;
      if ((int)(uint)*(ushort *)(iVar6 + 0x14) <= local_38) {
        iVar8 = *(ushort *)(iVar6 + 0x14) - 1;
      }
    }
    bVar7 = param_2 != (float)local_38;
    local_40 = param_2 - (float)local_38;
    iVar11 = *(ushort *)(iVar6 + 0x14) - 1;
    bVar20 = SBORROW4(iVar8,iVar11);
    iVar11 = iVar8 - iVar11;
    local_38 = iVar8;
    goto LAB_006377c4;
  }
  if (local_38 < (int)(uint)*puVar9) {
    local_38 = 0;
LAB_0063774f:
    if (param_2 == 0.0) {
      bVar7 = false;
    }
    else {
      bVar7 = true;
      local_40 = param_2 / (float)*puVar9;
    }
  }
  else {
    if (*(ushort *)(param_1 + 0x10) == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = *(ushort *)(param_1 + 0x10) - 1;
    }
    puVar10 = puVar9 + iVar8;
    if (local_38 < (int)(uint)puVar9[iVar8]) {
      for (; (0 < iVar8 && (local_38 < (int)(uint)*puVar10)); puVar10 = puVar10 + -1) {
        iVar8 = iVar8 + -1;
      }
    }
    else {
      while ((iVar8 < (int)(*(ushort *)(iVar6 + 0x14) - 2) &&
             (puVar10 = puVar10 + 1, (int)(uint)*puVar10 <= local_38))) {
        iVar8 = iVar8 + 1;
      }
    }
    local_38 = iVar8 + 1;
    if (local_38 == 0) goto LAB_0063774f;
    fVar14 = (float)puVar9[iVar8];
    bVar7 = param_2 != fVar14;
    if (bVar7) {
      local_40 = (param_2 - fVar14) / ((float)puVar9[local_38] - fVar14);
    }
  }
  iVar11 = *(ushort *)(iVar6 + 0x14) - 1;
  bVar20 = SBORROW4(local_38,iVar11);
  iVar11 = local_38 - iVar11;
LAB_006377c4:
  if (bVar20 == iVar11 < 0) {
    bVar7 = false;
  }
  *(short *)(param_1 + 0x10) = (short)local_38;
  if (param_4 == 0) {
    if (*(int *)(param_1 + 0x14) != 0) {
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
    uVar13 = (uint)*(byte *)(iVar6 + 0x16);
    iVar8 = *(int *)(iVar6 + 0xc);
    iVar11 = param_3 + 0x10;
    puVar9 = (ushort *)(iVar6 + 0x18 + uVar13 * local_38 * 8);
    if ((bVar7) && (local_38 < (int)(*(ushort *)(iVar6 + 0x14) - 1))) {
      puVar10 = (ushort *)(iVar6 + 0x18 + (local_38 + 1) * uVar13 * 8);
      iVar12 = 0;
      if (3 < uVar13) {
        pbVar19 = (byte *)(iVar8 + 1);
        do {
          fVar14 = (float)(((*puVar9 & 0xffff8000) << 1 | *puVar9 & 0x7fff) << 0xf);
          fVar15 = (float)(((puVar9[1] & 0xffff8000) << 1 | puVar9[1] & 0x7fff) << 0xf);
          fVar16 = (float)(((puVar9[2] & 0xffff8000) << 1 | puVar9[2] & 0x7fff) << 0xf);
          fVar17 = (float)(((puVar9[3] & 0xffff8000) << 1 | puVar9[3] & 0x7fff) << 0xf);
          uVar2 = puVar10[1];
          uVar3 = puVar10[2];
          uVar4 = puVar10[3];
          uVar18 = (uint)pbVar19[-1];
          *(float *)(iVar11 + uVar18 * 0x30) =
               ((float)(((*puVar10 & 0xffff8000) << 1 | *puVar10 & 0x7fff) << 0xf) - fVar14) *
               local_40 + fVar14;
          *(float *)(param_3 + 0x14 + uVar18 * 0x30) =
               ((float)(((uVar2 & 0xffff8000) << 1 | uVar2 & 0x7fff) << 0xf) - fVar15) * local_40 +
               fVar15;
          *(float *)(param_3 + 0x18 + uVar18 * 0x30) =
               ((float)(((uVar3 & 0xffff8000) << 1 | uVar3 & 0x7fff) << 0xf) - fVar16) * local_40 +
               fVar16;
          *(float *)(param_3 + 0x1c + uVar18 * 0x30) =
               ((float)(((uVar4 & 0xffff8000) << 1 | uVar4 & 0x7fff) << 0xf) - fVar17) * local_40 +
               fVar17;
          fVar14 = (float)(((puVar9[4] & 0xffff8000) << 1 | puVar9[4] & 0x7fff) << 0xf);
          fVar15 = (float)(((puVar9[5] & 0xffff8000) << 1 | puVar9[5] & 0x7fff) << 0xf);
          fVar16 = (float)(((puVar9[6] & 0xffff8000) << 1 | puVar9[6] & 0x7fff) << 0xf);
          fVar17 = (float)(((puVar9[7] & 0xffff8000) << 1 | puVar9[7] & 0x7fff) << 0xf);
          uVar2 = puVar10[5];
          uVar3 = puVar10[6];
          uVar4 = puVar10[7];
          uVar18 = (uint)*pbVar19;
          *(float *)(iVar11 + uVar18 * 0x30) =
               ((float)(((puVar10[4] & 0xffff8000) << 1 | puVar10[4] & 0x7fff) << 0xf) - fVar14) *
               local_40 + fVar14;
          *(float *)(param_3 + 0x14 + uVar18 * 0x30) =
               ((float)(((uVar2 & 0xffff8000) << 1 | uVar2 & 0x7fff) << 0xf) - fVar15) * local_40 +
               fVar15;
          *(float *)(param_3 + 0x18 + uVar18 * 0x30) =
               ((float)(((uVar3 & 0xffff8000) << 1 | uVar3 & 0x7fff) << 0xf) - fVar16) * local_40 +
               fVar16;
          *(float *)(param_3 + 0x1c + uVar18 * 0x30) =
               ((float)(((uVar4 & 0xffff8000) << 1 | uVar4 & 0x7fff) << 0xf) - fVar17) * local_40 +
               fVar17;
          fVar14 = (float)(((puVar9[8] & 0xffff8000) << 1 | puVar9[8] & 0x7fff) << 0xf);
          fVar15 = (float)(((puVar9[9] & 0xffff8000) << 1 | puVar9[9] & 0x7fff) << 0xf);
          fVar16 = (float)(((puVar9[10] & 0xffff8000) << 1 | puVar9[10] & 0x7fff) << 0xf);
          fVar17 = (float)(((puVar9[0xb] & 0xffff8000) << 1 | puVar9[0xb] & 0x7fff) << 0xf);
          uVar2 = puVar10[9];
          uVar3 = puVar10[10];
          uVar4 = puVar10[0xb];
          uVar18 = (uint)pbVar19[1];
          *(float *)(iVar11 + uVar18 * 0x30) =
               ((float)(((puVar10[8] & 0xffff8000) << 1 | puVar10[8] & 0x7fff) << 0xf) - fVar14) *
               local_40 + fVar14;
          *(float *)(param_3 + 0x14 + uVar18 * 0x30) =
               ((float)(((uVar2 & 0xffff8000) << 1 | uVar2 & 0x7fff) << 0xf) - fVar15) * local_40 +
               fVar15;
          *(float *)(param_3 + 0x18 + uVar18 * 0x30) =
               ((float)(((uVar3 & 0xffff8000) << 1 | uVar3 & 0x7fff) << 0xf) - fVar16) * local_40 +
               fVar16;
          *(float *)(param_3 + 0x1c + uVar18 * 0x30) =
               ((float)(((uVar4 & 0xffff8000) << 1 | uVar4 & 0x7fff) << 0xf) - fVar17) * local_40 +
               fVar17;
          fVar14 = (float)(((puVar9[0xc] & 0xffff8000) << 1 | puVar9[0xc] & 0x7fff) << 0xf);
          fVar15 = (float)(((puVar9[0xd] & 0xffff8000) << 1 | puVar9[0xd] & 0x7fff) << 0xf);
          fVar16 = (float)(((puVar9[0xe] & 0xffff8000) << 1 | puVar9[0xe] & 0x7fff) << 0xf);
          fVar17 = (float)(((puVar9[0xf] & 0xffff8000) << 1 | puVar9[0xf] & 0x7fff) << 0xf);
          uVar2 = puVar10[0xd];
          uVar3 = puVar10[0xe];
          uVar4 = puVar10[0xf];
          uVar18 = (uint)pbVar19[2];
          pbVar19 = pbVar19 + 4;
          puVar9 = puVar9 + 0x10;
          *(float *)(iVar11 + uVar18 * 0x30) =
               ((float)(((puVar10[0xc] & 0xffff8000) << 1 | puVar10[0xc] & 0x7fff) << 0xf) - fVar14)
               * local_40 + fVar14;
          puVar10 = puVar10 + 0x10;
          iVar12 = iVar12 + 4;
          *(float *)(param_3 + 0x14 + uVar18 * 0x30) =
               ((float)(((uVar2 & 0xffff8000) << 1 | uVar2 & 0x7fff) << 0xf) - fVar15) * local_40 +
               fVar15;
          *(float *)(param_3 + 0x18 + uVar18 * 0x30) =
               ((float)(((uVar3 & 0xffff8000) << 1 | uVar3 & 0x7fff) << 0xf) - fVar16) * local_40 +
               fVar16;
          *(float *)(param_3 + 0x1c + uVar18 * 0x30) =
               ((float)(((uVar4 & 0xffff8000) << 1 | uVar4 & 0x7fff) << 0xf) - fVar17) * local_40 +
               fVar17;
        } while ((int)(pbVar19 + (2 - iVar8)) < (int)uVar13);
      }
      for (; iVar12 < (int)uVar13; iVar12 = iVar12 + 1) {
        fVar14 = (float)(((*puVar9 & 0xffff8000) << 1 | *puVar9 & 0x7fff) << 0xf);
        fVar15 = (float)(((puVar9[1] & 0xffff8000) << 1 | puVar9[1] & 0x7fff) << 0xf);
        fVar16 = (float)(((puVar9[2] & 0xffff8000) << 1 | puVar9[2] & 0x7fff) << 0xf);
        uVar2 = *puVar10;
        fVar17 = (float)(((puVar9[3] & 0xffff8000) << 1 | puVar9[3] & 0x7fff) << 0xf);
        uVar3 = puVar10[1];
        uVar4 = puVar10[2];
        uVar5 = puVar10[3];
        uVar18 = (uint)*(byte *)(iVar12 + iVar8);
        puVar9 = puVar9 + 4;
        puVar10 = puVar10 + 4;
        *(float *)(iVar11 + uVar18 * 0x30) =
             ((float)(((uVar2 & 0xffff8000) << 1 | uVar2 & 0x7fff) << 0xf) - fVar14) * local_40 +
             fVar14;
        *(float *)(param_3 + 0x14 + uVar18 * 0x30) =
             ((float)(((uVar3 & 0xffff8000) << 1 | uVar3 & 0x7fff) << 0xf) - fVar15) * local_40 +
             fVar15;
        *(float *)(param_3 + 0x18 + uVar18 * 0x30) =
             ((float)(((uVar4 & 0xffff8000) << 1 | uVar4 & 0x7fff) << 0xf) - fVar16) * local_40 +
             fVar16;
        *(float *)(param_3 + 0x1c + uVar18 * 0x30) =
             ((float)(((uVar5 & 0xffff8000) << 1 | uVar5 & 0x7fff) << 0xf) - fVar17) * local_40 +
             fVar17;
      }
    }
    else {
      iVar12 = 0;
      if (uVar13 != 0) {
        do {
          uVar18 = (uint)*(byte *)(iVar12 + iVar8);
          *(uint *)(iVar11 + uVar18 * 0x30) =
               ((*puVar9 & 0xffff8000) << 1 | *puVar9 & 0x7fff) << 0xf;
          *(uint *)(param_3 + 0x14 + uVar18 * 0x30) =
               ((puVar9[1] & 0xffff8000) << 1 | puVar9[1] & 0x7fff) << 0xf;
          *(uint *)(param_3 + 0x14 + (uVar18 * 0xc + 1) * 4) =
               ((puVar9[2] & 0xffff8000) << 1 | puVar9[2] & 0x7fff) << 0xf;
          puVar10 = puVar9 + 3;
          puVar9 = puVar9 + 4;
          iVar12 = iVar12 + 1;
          *(uint *)(param_3 + 0x14 + (uVar18 * 0xc + 2) * 4) =
               ((*puVar10 & 0xffff8000) << 1 | *puVar10 & 0x7fff) << 0xf;
        } while (iVar12 < (int)uVar13);
      }
    }
    uVar13 = (uint)*(byte *)(iVar6 + 0x17);
    if (uVar13 != 0) {
      bVar1 = *(byte *)(iVar6 + 0x16);
      iVar8 = *(int *)(iVar6 + 0xc);
      puVar9 = (ushort *)(iVar6 + 0x18 + (uint)*(ushort *)(iVar6 + 0x14) * (uint)bVar1 * 8);
      iVar12 = 0;
      if (uVar13 != 0) {
        do {
          uVar18 = (uint)*(byte *)(iVar12 + iVar8 + (uint)bVar1);
          *(uint *)(iVar11 + uVar18 * 0x30) =
               ((*puVar9 & 0xffff8000) << 1 | *puVar9 & 0x7fff) << 0xf;
          *(uint *)(param_3 + 0x14 + uVar18 * 0x30) =
               ((puVar9[1] & 0xffff8000) << 1 | puVar9[1] & 0x7fff) << 0xf;
          *(uint *)(param_3 + 0x14 + (uVar18 * 0xc + 1) * 4) =
               ((puVar9[2] & 0xffff8000) << 1 | puVar9[2] & 0x7fff) << 0xf;
          puVar10 = puVar9 + 3;
          puVar9 = puVar9 + 4;
          *(uint *)(param_3 + 0x14 + (uVar18 * 0xc + 2) * 4) =
               ((*puVar10 & 0xffff8000) << 1 | *puVar10 & 0x7fff) << 0xf;
          iVar12 = iVar12 + 1;
        } while (iVar12 < (int)uVar13);
      }
    }
  }
  else {
    FUN_00636bc0(param_2,param_3,param_4,bVar7,local_38,local_40);
  }
  if (*(int *)(iVar6 + 0x10) != 0) {
    FUN_00635c90(param_2,param_3,param_4,bVar7,local_38,local_40);
  }
  return 1;
}


// ==== 0x638120 FUN_00638120

void FUN_00638120(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int unaff_retaddr;
  int iVar6;
  int iStack_18;
  int iStack_14;
  int iStack_c;
  int *piStack_4;
  
  iVar4 = 0;
  *(undefined4 *)(param_2 + 0x2fc) = 0;
  iVar1 = (**(code **)(*param_1 + 0x18))(param_1,*(undefined4 *)(param_2 + 0x210));
  iVar6 = 0;
  if (0 < iVar1) {
    piVar5 = (int *)(param_2 + 0x304);
    do {
      (**(code **)(*param_1 + 0x1c))(param_1,*(undefined4 *)(param_2 + 0x210),iVar6,&iStack_18);
      if (iVar4 < 0x100) {
        iVar3 = 0;
        param_1 = piStack_4;
        if (0 < iVar4) {
          piVar2 = (int *)(param_2 + 0x304);
          do {
            if ((((piVar2[-1] == 1) && (param_2 = unaff_retaddr, *piVar2 == iStack_18)) &&
                (piVar2[1] == iStack_14)) && (piVar2[4] == iStack_c)) goto LAB_006381d8;
            iVar3 = iVar3 + 1;
            piVar2 = piVar2 + 6;
          } while (iVar3 < iVar4);
        }
        piVar5[-1] = 1;
        *piVar5 = iStack_18;
        piVar5[1] = iStack_14;
        piVar5[4] = iStack_c;
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 6;
      }
LAB_006381d8:
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar1);
  }
  *(int *)(param_2 + 0x2fc) = iVar4;
  return;
}


// ==== 0x638200 FUN_00638200

void FUN_00638200(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = &DAT_006e74b0;
  puVar3 = (undefined4 *)(param_2 + 0x1b00);
  do {
    *puVar3 = 0;
    uVar1 = *puVar4;
    iVar2 = (**(code **)(*param_1 + 0x28))
                      (param_1,*(undefined4 *)(param_2 + 0x210),1,*(undefined4 *)(param_2 + 0x220),0
                       ,3,uVar1);
    if (iVar2 == 0) {
      *puVar3 = uVar1;
    }
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 1;
  } while ((int)puVar4 < 0x6e7540);
  return;
}


// ==== 0x638260 FUN_00638260

void FUN_00638260(void)

{
  uint uVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  
  if (((*(byte *)(in_EAX + 0x250) & 0x10) == 0) || ((*(byte *)(in_EAX + 0x254) & 2) == 0)) {
    iVar2 = 1;
  }
  else {
    iVar2 = 0;
  }
  uVar3 = *(uint *)(in_EAX + 0x2f8) ^ (iVar2 << 4 ^ *(uint *)(in_EAX + 0x2f8)) & 0x10;
  uVar1 = *(uint *)(in_EAX + 0x204);
  *(uint *)(in_EAX + 0x2f8) = uVar3;
  if (uVar1 < 0x10de0030) {
    if (0x10de0027 < uVar1) {
LAB_0063843c:
      *(uint *)(in_EAX + 0x2f8) = uVar3 | 1;
      return;
    }
    if (0x10025144 < uVar1) {
      if (uVar1 < 0x10330047) {
        if (uVar1 == 0x10330046) {
LAB_0063837f:
          *(undefined4 *)(in_EAX + 700) = 1;
          *(uint *)(in_EAX + 0x2f8) = *(uint *)(in_EAX + 0x2f8) | 0x10;
          return;
        }
        if (uVar1 < 0x102b0522) {
          if (0x102b051f < uVar1) {
            return;
          }
          if (uVar1 == 0x10025157) goto LAB_0063835e;
        }
        else if (uVar1 == 0x1033002a) goto LAB_0063837f;
      }
      else {
        if (uVar1 == 0x10396326) {
          return;
        }
        if (uVar1 == 0x104c3d07) {
LAB_0063848c:
          *(undefined4 *)(in_EAX + 700) = 1;
          *(uint *)(in_EAX + 0x2f8) = *(uint *)(in_EAX + 0x2f8) | 0x20;
          goto LAB_00638558;
        }
        if (uVar1 == 0x10de0020) {
          *(uint *)(in_EAX + 0x2f8) = uVar3 | 1;
          return;
        }
      }
      goto LAB_00638502;
    }
    if (uVar1 == 0x10025144) {
LAB_0063835e:
      *(uint *)(in_EAX + 0x248) = *(uint *)(in_EAX + 0x248) & 0xffeffeff;
      return;
    }
    if (uVar1 < 0x10024c43) {
      if (uVar1 != 0x10024c42) {
        if (uVar1 < 0x10024745) {
          if (uVar1 != 0x10024744) {
            if (uVar1 == 0x3d00d1) goto LAB_00638410;
            if (uVar1 != 0x10024742) goto LAB_00638502;
          }
        }
        else if (uVar1 != 0x10024749) goto LAB_00638502;
      }
    }
    else if (((uVar1 != 0x10024c44) && (uVar1 != 0x10024c47)) && (uVar1 != 0x10024c49))
    goto LAB_00638502;
  }
  else {
    if (uVar1 < 0x3d3d000b) {
      if (uVar1 == 0x3d3d000a) goto LAB_0063843c;
      if (uVar1 < 0x121a0004) {
        if (uVar1 == 0x121a0003) {
          return;
        }
        if (uVar1 < 0x121a0002) {
          if (uVar1 == 0x121a0001) {
            *(undefined4 *)(in_EAX + 700) = 1;
            *(uint *)(in_EAX + 0x2f8) = *(uint *)(in_EAX + 0x2f8) | 1;
            return;
          }
          if (0x10de00ff < uVar1) {
            if (uVar1 < 0x10de0104) {
              return;
            }
            if (uVar1 == 0x110b0004) goto LAB_00638410;
          }
        }
        else if (uVar1 == 0x121a0002) goto LAB_0063843c;
      }
      else if (uVar1 < 0x12d2001a) {
        if (0x12d20017 < uVar1) {
          *(undefined4 *)(in_EAX + 700) = 1;
          *(uint *)(in_EAX + 0x2f8) = *(uint *)(in_EAX + 0x2f8) | 0x30;
          goto LAB_00638558;
        }
        if ((0x121a0003 < uVar1) && (uVar1 < 0x121a0006)) {
          return;
        }
      }
      else if (uVar1 == 0x3d3d0009) goto LAB_0063848c;
    }
    else if (uVar1 < 0x53338a22) {
      if (0x53338a1f < uVar1) {
        uVar3 = uVar3 & 0xfffffffb;
LAB_006384da:
        *(uint *)(in_EAX + 0x2f8) = uVar3 | 3;
        return;
      }
      if ((uVar1 == 0x53335631) || (uVar1 == 0x5333883d)) {
LAB_00638410:
        *(undefined4 *)(in_EAX + 700) = 1;
        return;
      }
      if (uVar1 == 0x53338a01) {
        *(undefined4 *)(in_EAX + 700) = 1;
        return;
      }
    }
    else {
      if (uVar1 == 0x53338a22) goto LAB_006384da;
      if (uVar1 == 0x53339102) {
        *(uint *)(in_EAX + 0x2f8) = uVar3 | 0x43;
        *(undefined4 *)(in_EAX + 0x298) = 0;
        *(undefined4 *)(in_EAX + 0x2a0) = 0;
        *(undefined4 *)(in_EAX + 0x29c) = 0;
        *(undefined4 *)(in_EAX + 0x2a4) = 0;
        return;
      }
      if (uVar1 == 0x80867800) goto LAB_00638410;
    }
LAB_00638502:
    if ((((0x10025040 < uVar1) && (uVar1 < 0x100250ff)) ||
        ((0x10025240 < uVar1 && (uVar1 < 0x100252ff)))) ||
       ((0x10025340 < uVar1 && (uVar1 < 0x100253ff)))) goto LAB_00638558;
    if (((uVar1 < 0x1002474d) || (0x10024751 < uVar1)) &&
       ((uVar1 < 0x10024c49 || (0x10024c53 < uVar1)))) {
      return;
    }
  }
  *(undefined4 *)(in_EAX + 700) = 1;
LAB_00638558:
  *(uint *)(in_EAX + 0x248) = *(uint *)(in_EAX + 0x248) & 0xffefffff;
  return;
}


// ==== 0x6385a0 FUN_006385a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006385a0(int *param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *unaff_ESI;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  undefined4 local_440;
  undefined4 local_43c;
  undefined4 local_438 [119];
  char acStack_25c [520];
  int iStack_54;
  uint uStack_50;
  
  puVar4 = &DAT_0070d7a8;
  for (iVar3 = 0x6e4; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_448 = 0;
  local_444 = 0;
  local_440 = 0;
  local_44c = 0;
  local_43c = 0;
  puVar4 = local_438;
  for (iVar3 = 0x10b; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  DAT_0070d7a8 = 0;
  _DAT_0070d9b8 = (undefined4 *)0x0;
  if (param_1 == (int *)0x0) {
    if (param_2 != 0) {
      _sprintf(param_2,"pDevice is NULL\n");
    }
    return 0;
  }
  puVar4 = &local_44c;
  piVar6 = param_1;
  iVar3 = (**(code **)(*param_1 + 0x18))();
  if (iVar3 == 0) {
    (**(code **)(*unaff_ESI + 8))(unaff_ESI);
    iVar3 = (**(code **)(*param_1 + 0x24))(param_1,&stack0xfffffbac);
    if (iVar3 == 0) {
      puVar5 = &local_44c;
      _DAT_0070d9b8 = puVar4;
      iVar3 = (**(code **)(*piVar6 + 0x14))(piVar6,puVar4,2,puVar5);
      if (iVar3 == 0) {
        _DAT_0070d9b4 = uStack_50;
        _DAT_0070d9b0 = iStack_54;
        _DAT_0070d9ac = uStack_50 & 0xffff | iStack_54 << 0x10;
        iVar3 = 0;
        do {
          cVar1 = acStack_25c[iVar3];
          (&DAT_0070d7ac)[iVar3] = cVar1;
          iVar3 = iVar3 + 1;
        } while (cVar1 != '\0');
        FUN_00638120(puVar5,&DAT_0070d7a8);
        (**(code **)(*param_1 + 0x20))(param_1,&DAT_0070d9bc);
        FUN_00638200(puVar4,&DAT_0070d7a8);
        iVar3 = (**(code **)(*param_1 + 0x1c))(param_1,&DAT_0070d9cc);
        if (iVar3 == 0) {
          uVar2 = FUN_00638260();
          DAT_0070d7a8 = 1;
          return uVar2;
        }
        if (param_2 != 0) {
          _sprintf(param_2,"IDirect3DDevice8_GetDeviceCaps failed: err = 0x%x\n",iVar3);
        }
      }
      else if (param_2 != 0) {
        _sprintf(param_2,"IDirect3D8_GetAdapterIdentifier failed: err = 0x%x\n",iVar3);
        return 0;
      }
    }
    else if (param_2 != 0) {
      _sprintf(param_2,"IDirect3DDevice8_GetCreationParameters failed: err = 0x%x\n",iVar3);
      return 0;
    }
  }
  else if (param_2 != 0) {
    _sprintf(param_2,"IDirect3DDevice8_GetDirect3D failed: err = 0x%x\n",iVar3);
    return 0;
  }
  return 0;
}


// ==== 0x638780 FUN_00638780

int FUN_00638780(uint param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    iVar1 = (param_3 >> 1) * param_4;
    uVar2 = (uint)*(ushort *)(iVar1 + param_2);
    iVar1 = iVar1 + param_2;
    if (param_1 == uVar2) break;
    if (param_1 != uVar2 && -1 < (int)(param_1 - uVar2)) {
      param_2 = iVar1 + param_4;
      param_3 = param_3 + -1;
    }
    param_3 = param_3 >> 1;
  }
  return iVar1;
}


// ==== 0x6387c0 FUN_006387c0

undefined4 FUN_006387c0(undefined4 param_1)

{
  if (*(code **)(PTR_PTR_006e7540 + 0xc) != (code *)0x0) {
    (**(code **)(PTR_PTR_006e7540 + 0xc))(param_1);
    return param_1;
  }
  return param_1;
}


// ==== 0x6387e0 FUN_006387e0

void FUN_006387e0(void)

{
  if (*(code **)(PTR_PTR_006e7540 + 0x10) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x006387ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(PTR_PTR_006e7540 + 0x10))();
    return;
  }
  return;
}


// ==== 0x6387f0 FUN_006387f0

int FUN_006387f0(int param_1,ushort *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)*(byte *)((int)param_2 + 0xb);
  iVar1 = 0;
  if (uVar4 != 0) {
    if ((*(uint *)(param_1 + 0xc) & 0x40000) == 0) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x18) + param_1);
      param_1 = *(int *)(param_1 + 0x18) + param_1;
      iVar3 = 0;
      if (iVar2 < 1) {
        return 0;
      }
      while ((*(ushort *)(param_1 + 4 + iVar3 * 4) != param_3 ||
             ((ushort)*(byte *)(param_1 + 7 + iVar3 * 4) != *param_2))) {
        iVar3 = iVar3 + 1;
        if (iVar2 <= iVar3) {
          return iVar1;
        }
      }
      param_1 = param_1 + 4 + iVar3 * 4;
    }
    else {
      param_1 = *(int *)(param_1 + 0x18) + 4 + (uint)param_2[6] * 4 + param_1;
      iVar2 = 0;
      if (uVar4 == 0) {
        return 0;
      }
      while (*(ushort *)(param_1 + iVar2 * 4) != param_3) {
        iVar2 = iVar2 + 1;
        if ((int)uVar4 <= iVar2) {
          return iVar1;
        }
      }
      param_1 = param_1 + iVar2 * 4;
    }
    if (param_1 != 0) {
      iVar1 = (int)*(char *)(param_1 + 2);
    }
  }
  return iVar1;
}


// ==== 0x638880 FUN_00638880

void FUN_00638880(undefined1 *param_1)

{
  *param_1 = 0;
                    /* WARNING: Could not recover jumptable at 0x0063888b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_006e7560)();
  return;
}


// ==== 0x6388a0 FUN_006388a0

int FUN_006388a0(int param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int unaff_EBX;
  int iVar5;
  int iVar6;
  int local_4;
  
  iVar1 = param_1;
  local_4 = 0;
  if (in_EAX == 0) {
    in_EAX = 0x20;
  }
  uVar2 = FUN_00638f20(in_EAX);
  param_1 = CONCAT31(param_1._1_3_,uVar2);
  iVar3 = FUN_00638f00(&param_1);
  param_1 = 0x10;
  if (iVar3 != 0xf) {
    param_1 = iVar3;
  }
  if (((((0 < iVar1) && (iVar1 < 0x10001)) && (0 < unaff_EBX)) &&
      ((unaff_EBX < 0x10001 && (iVar1 * unaff_EBX < 0x3b9aca01)))) &&
     (iVar3 = FUN_00638f20(iVar3), iVar3 != 0)) {
    if (-1 < param_2) {
      iVar3 = 0;
      do {
        iVar5 = iVar1 >> ((byte)iVar3 & 0x1f);
        iVar6 = unaff_EBX >> ((byte)iVar3 & 0x1f);
        if (iVar5 < 1) {
          iVar5 = 1;
        }
        if (iVar6 < 1) {
          iVar6 = 1;
        }
        iVar4 = iVar5 * param_1 + 7;
        local_4 = local_4 + ((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) * iVar6;
      } while (((iVar5 != 1) || (iVar6 != 1)) && (iVar3 = iVar3 + 1, iVar3 <= param_2));
    }
    return local_4;
  }
  return 0;
}


// ==== 0x638990 FUN_00638990

int FUN_00638990(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                int param_6,int param_7)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar2 = param_3;
  if (param_3 == 0) {
    iVar2 = 0x20;
  }
  uVar1 = FUN_00638f20(iVar2);
  param_3 = CONCAT31(param_3._1_3_,uVar1);
  iVar3 = FUN_00638f00(&param_3);
  iVar4 = FUN_006388a0(param_1,param_5);
  iVar2 = iVar4 + 0x10;
  if ((iVar3 < 9) && (param_4 != 0)) {
    if (param_4 == 0xf) {
      param_4 = 0x10;
    }
    uVar6 = 0;
    if (iVar2 != 0) {
      uVar6 = iVar4 + 0x1fU & 0xfffffff0;
    }
    if (iVar3 == 4) {
      uVar5 = 0x10;
    }
    else {
      uVar5 = (iVar3 != 8) - 1 & 0x100;
    }
    iVar2 = ((int)(uVar5 * param_4 + ((int)(uVar5 * param_4) >> 0x1f & 7U)) >> 3) + 0x10 + uVar6;
  }
  if (param_6 != 0) {
    iVar2 = iVar2 + 8 + param_6;
  }
  iVar3 = iVar2 + 0x10 + param_7;
  if (param_7 == 0) {
    iVar3 = iVar2;
  }
  return iVar3;
}


// ==== 0x638a50 FUN_00638a50

void FUN_00638a50(uint *param_1,undefined4 param_2,undefined2 param_3,int param_4,int param_5,
                 int param_6,uint param_7,int param_8)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  undefined1 *puVar5;
  uint *puVar6;
  uint *puVar7;
  
  if (param_4 == 0) {
    param_4 = 0x20;
  }
  uVar1 = FUN_00638f20(param_4);
  FUN_00641a10(param_1,0,0x10);
  *(undefined1 *)param_1 = uVar1;
  *(short *)(param_1 + 1) = (short)param_2;
  *(undefined2 *)((int)param_1 + 6) = param_3;
  param_1[3] = param_1[3] & 0xfffffff | param_6 << 0x1c;
  iVar2 = FUN_006388a0(param_2,param_6);
  puVar4 = (uint *)(iVar2 + 0x10 + (int)param_1);
  puVar6 = param_1;
  if ((param_4 < 9) && (param_5 != 0)) {
    if (param_4 == 4) {
      uVar3 = 0x10;
    }
    else {
      uVar3 = (param_4 != 8) - 1 & 0x100;
    }
    uVar1 = FUN_00638fd0(param_5);
    param_4 = 0x10;
    if (param_5 != 0xf) {
      param_4 = param_5;
    }
    puVar6 = (uint *)(((uint)((int)puVar4 + (0xf - (int)param_1)) & 0xfffffff0) + (int)param_1);
    *param_1 = ((int)puVar6 - (int)param_1) * 0x100 ^ *param_1 & 0xff;
    FUN_00641a10(puVar6,0,0x10);
    *(undefined1 *)puVar6 = uVar1;
    *(short *)(puVar6 + 1) = (short)uVar3;
    *(undefined2 *)((int)puVar6 + 6) = 1;
    if (param_5 < 0x20) {
      if ((puVar6[3] & 0x1000) == 0) {
        puVar4 = puVar6 + 4;
      }
      else {
        puVar4 = (uint *)(puVar6[4] + (int)puVar6);
      }
      FUN_00641a10(puVar4,0xffffffff,
                   (int)(param_4 * uVar3 + ((int)(param_4 * uVar3) >> 0x1f & 7U)) >> 3);
    }
    else {
      if ((puVar6[3] & 0x1000) == 0) {
        puVar4 = puVar6 + 4;
      }
      else {
        puVar4 = (uint *)(puVar6[4] + (int)puVar6);
      }
      iVar2 = 0;
      if (uVar3 != 0) {
        puVar5 = (undefined1 *)((int)puVar4 + 2);
        do {
          uVar1 = (undefined1)iVar2;
          puVar5[-2] = uVar1;
          puVar5[-1] = uVar1;
          *puVar5 = uVar1;
          puVar5[1] = 0xff;
          iVar2 = iVar2 + 1;
          puVar5 = puVar5 + 4;
        } while (iVar2 < (int)uVar3);
      }
    }
    puVar4 = (uint *)((int)puVar6 +
                     ((int)(param_4 * uVar3 + ((int)(param_4 * uVar3) >> 0x1f & 7U)) >> 3) + 0x10);
  }
  puVar7 = puVar4;
  if (param_7 != 0) {
    *puVar6 = ((int)puVar4 - (int)puVar6) * 0x100 ^ *puVar6 & 0xff;
    FUN_00641a10(puVar4,0,param_7 + 8);
    *(undefined1 *)puVar4 = 0x6f;
    puVar4[1] = param_7;
    puVar7 = (uint *)((int)puVar4 + param_7 + 8);
    puVar6 = puVar4;
  }
  if (param_8 != 0) {
    *puVar6 = ((int)puVar7 - (int)puVar6) * 0x100 ^ *puVar6 & 0xff;
    FUN_00641a10(puVar7,0,param_8 + 0x10);
    *(undefined1 *)puVar7 = 0x69;
    *(undefined2 *)((int)puVar7 + 6) = 0x10;
  }
  return;
}


// ==== 0x638c30 SHP_FormatName

/* [canon] render low (hopper+ghidra) docs/re/render.md */

int SHP_FormatName(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  undefined1 local_10 [16];
  
  iVar1 = FUN_00638990(param_1,param_2,param_3,param_4,param_5,param_7,param_8);
  if (iVar1 != 0) {
    _sprintf(local_10,"SHP%dx%dx%d",param_1,param_2,param_3);
    iVar1 = (*(code *)PTR_NullUpdate_ret_006e755c)(local_10,iVar1,0,0x10,param_6);
    if (iVar1 != 0) {
      FUN_00638a50(iVar1,param_1,param_2,param_3,param_4,param_5,param_7,param_8);
    }
    return iVar1;
  }
  return 0;
}


// ==== 0x638cd0 FUN_00638cd0

int FUN_00638cd0(uint param_1,uint param_2,int param_3,uint param_4,char param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint local_10 [4];
  
  local_10[0] = local_10[0] & 0xffffff00 | param_1 & 0xff;
  iVar6 = 0;
  iVar1 = FUN_00638f00(local_10);
  if (iVar1 == 0xf) {
    iVar1 = 0x10;
  }
  if (((param_1 == 0x21) || (param_1 == 0x20)) && (param_5 != '\0')) {
    uVar2 = param_2 & 0x1f;
    if ((uVar2 < 0x10) || (0x17 < uVar2)) {
      if ((7 < uVar2) && (uVar2 < 0x10)) {
        param_2 = param_2 + 8;
      }
    }
    else {
      param_2 = (param_2 & 0xffffffe0) + 0x18;
    }
    iVar6 = (int)(iVar1 * param_2 + ((int)(iVar1 * param_2) >> 0x1f & 7U)) >> 3;
  }
  else {
    uVar2 = 0;
    do {
      uVar3 = (int)param_2 >> ((byte)uVar2 & 0x1f);
      uVar5 = param_3 >> ((byte)uVar2 & 0x1f);
      if ((int)uVar3 < 1) {
        uVar3 = 1;
      }
      if ((int)uVar5 < 1) {
        uVar5 = 1;
      }
      if (((param_1 == 0x60) || (param_1 == 0x61)) || (param_1 == 0x62)) {
        uVar3 = uVar3 + 3 & 0xfffffffc;
        uVar5 = uVar5 + 3 & 0xfffffffc;
      }
      iVar4 = uVar3 * iVar1 + 7;
      iVar6 = iVar6 + ((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) * uVar5;
      uVar2 = uVar2 + 1;
    } while (uVar2 <= param_4);
  }
  if (iVar6 != 0) {
    iVar6 = iVar6 + 0x10;
  }
  return iVar6;
}


// ==== 0x638dd0 FUN_00638dd0

char * FUN_00638dd0(uint *param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  char *pcVar5;
  
  puVar4 = param_1;
  uVar3 = *param_1 & 0xff;
  pcVar5 = (char *)0x0;
  switch(uVar3) {
  case 0x69:
    if ((*(byte *)((int)param_1 + 6) & 0x10) != 0) {
      uVar3 = (uint)(ushort)param_1[1];
      if (uVar3 == 0) {
        uVar3 = 0x40;
      }
      return (char *)(uVar3 + 0x10);
    }
    return (char *)0x10;
  case 0x6f:
    return (char *)(param_1[1] + 8);
  case 0x70:
    puVar4 = param_1 + 1;
    do {
      uVar3 = *puVar4;
      puVar4 = (uint *)((int)puVar4 + 1);
    } while ((char)uVar3 != '\0');
    return (char *)((int)puVar4 + (5 - ((int)param_1 + 5)));
  case 0x7c:
    return (char *)(param_1[1] * 8 + 8);
  }
  if ((char)*param_1 < '\0') {
    puVar1 = param_1 + 3;
    param_1 = (uint *)0x0;
    if ((*puVar1 & 0x1000) == 0) {
      puVar4 = puVar4 + 4;
    }
    else {
      puVar4 = (uint *)(puVar4[4] + (int)puVar4);
    }
    iVar2 = FUN_00644910(puVar4,&param_1);
    if (iVar2 != 0) {
      return (char *)((int)param_1 + 0x10);
    }
  }
  else {
    pcVar5 = (char *)FUN_00638cd0(uVar3,(int)(short)param_1[1],(int)*(short *)((int)param_1 + 6),
                                  param_1[3] >> 0x1c,param_1[3] >> 0xd & 0xffffff01);
  }
  return pcVar5;
}


// ==== 0x638ee0 FUN_00638ee0

void FUN_00638ee0(undefined *param_1,undefined *param_2,undefined *param_3)

{
  PTR_NullUpdate_ret_006e7558 = param_1;
  PTR_NullUpdate_ret_006e755c = param_2;
  PTR_FUN_006e7560 = param_3;
  return;
}


// ==== 0x638f00 FUN_00638f00

undefined1 FUN_00638f00(uint *param_1)

{
  return (&DAT_006e7568)[*param_1 & 0x7f];
}


// ==== 0x638f20 FUN_00638f20

undefined4 FUN_00638f20(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0x22b < param_1) {
    if (param_1 < 0x115d) {
      if (param_1 == 0x115c) {
        return 0x6d;
      }
      if (param_1 == 0x235) {
        return 0x78;
      }
      if (param_1 == 0x378) {
        return 0x7f;
      }
      if (param_1 == 0x613) {
        return 0x7e;
      }
    }
    else if (param_1 == 0x1a0a) {
      uVar1 = 0x66;
    }
    else {
      if (param_1 == 0x22b8) {
        return 0x7d;
      }
      if (param_1 == 0x200f12) {
        return 0x6a;
      }
    }
    return uVar1;
  }
  if (param_1 != 0x22b) {
    if (0x10 < param_1) {
      if (param_1 == 0x18) {
        return 0x7f;
      }
      if (param_1 != 0x20) {
        if (param_1 != 0x1e4) {
          return 0;
        }
        return 0x68;
      }
      return 0x7d;
    }
    if (param_1 == 0x10) {
      return 0x78;
    }
    if (param_1 == 4) {
      return 0x79;
    }
    if (param_1 == 8) {
      return 0x7b;
    }
    if (param_1 != 0xf) {
      return uVar1;
    }
  }
  return 0x7e;
}


// ==== 0x638fd0 FUN_00638fd0

undefined4 FUN_00638fd0(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  switch(param_1) {
  case 0xf:
    return 0x2d;
  case 0x10:
    return 0x29;
  case 0x12:
    return 0x22;
  case 0x18:
    return 0x24;
  case 0x20:
    uVar1 = 0x2a;
  }
  return uVar1;
}


// ==== 0x639040 FUN_00639040

bool FUN_00639040(int param_1,undefined4 *param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  int iVar6;
  undefined4 uVar7;
  byte *pbVar8;
  bool bVar9;
  
  puVar4 = param_2;
  iVar3 = param_1;
  pbVar8 = (byte *)*param_2;
  bVar1 = *pbVar8;
  if (bVar1 != 0) {
    pbVar5 = (byte *)(param_1 + 0x14);
    do {
      bVar2 = *pbVar5;
      bVar9 = bVar2 < *pbVar8;
      if (bVar2 != *pbVar8) {
LAB_00639084:
        iVar6 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_00639089;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar5[1];
      bVar9 = bVar2 < pbVar8[1];
      if (bVar2 != pbVar8[1]) goto LAB_00639084;
      pbVar5 = pbVar5 + 2;
      pbVar8 = pbVar8 + 2;
    } while (bVar2 != 0);
    iVar6 = 0;
LAB_00639089:
    if (iVar6 != 0) {
      return true;
    }
  }
  iVar6 = FUN_0063dec0(*(undefined4 *)(param_1 + 0x10),param_2[1],0,&param_1,&param_2);
  if (iVar6 != 0) {
    uVar7 = FUN_0063d990(*(int *)(iVar3 + 0x10) + param_1,param_2,*(undefined4 *)(iVar3 + 8),
                         puVar4 + 2);
    puVar4[3] = uVar7;
    return false;
  }
  return bVar1 == 0;
}


// ==== 0x6390f0 FUN_006390f0

bool FUN_006390f0(int param_1,int param_2)

{
  return *(int *)(param_1 + 4) == param_2;
}


// ==== 0x639110 FUN_00639110

uint FUN_00639110(int param_1)

{
  return *(int *)(param_1 + 4) >> 5 & 0xffffffU | (uint)*(byte *)(param_1 + 0x11) << 0x18;
}


// ==== 0x639150 FUN_00639150

undefined4 FUN_00639150(void)

{
  int iVar1;
  int unaff_EDI;
  
  iVar1 = (*(uint *)(unaff_EDI + 4) & 0x1f) * 0xac + DAT_0070f36c;
  if (iVar1 == 0) {
    Log_Printf("FILE_queueop - ATTEMPT TO QUEUE FILEOP ON NON-EXISTANT DEVICE.\n");
  }
  FUN_00641e00(iVar1 + 0x14);
  FUN_00641a90(iVar1 + 0x7c);
  return *(undefined4 *)(unaff_EDI + 4);
}


// ==== 0x6391e0 FUN_006391e0

undefined4 FUN_006391e0(undefined4 param_1,int param_2)

{
  int iVar1;
  char *unaff_ESI;
  char *local_114;
  int local_108;
  char local_104 [260];
  
  iVar1 = _strchr();
  local_114 = local_104;
  local_108 = 0;
  if (iVar1 == 0) {
    local_108 = FUN_0063d1c0();
    *local_114 = '\0';
  }
  else {
    _strncpy(local_104,unaff_ESI,iVar1 - (int)unaff_ESI);
    local_114[iVar1 - (int)unaff_ESI] = '\0';
  }
  if ((param_2 != 0) && (local_108 == 0)) {
    FUN_00642330(&DAT_0070f3c8,FUN_00639040,&local_114);
  }
  return 0;
}


// ==== 0x6392f0 FUN_006392f0

void FUN_006392f0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  DWORD DVar7;
  int iVar8;
  int *piVar9;
  byte abStack_8 [4];
  undefined1 auStack_4 [4];
  
  puVar2 = (undefined4 *)(param_1 * 0xac + 0xa0 + DAT_0070f36c);
  piVar9 = (int *)(param_1 * 0xac + DAT_0070f36c);
  *piVar9 = 1;
  SetEvent((HANDLE)*puVar2);
  do {
    while( true ) {
      if (DAT_0070f3fc != 0) {
        *piVar9 = 0;
        return;
      }
      if (*piVar9 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = FUN_00642360(piVar9 + 5);
      }
      piVar1 = piVar9 + 5;
      iVar6 = FUN_00641d40(piVar1);
      piVar9[4] = iVar6;
      if ((iVar6 != 0) && (piVar9[0x2a] < (int)(uint)*(byte *)(iVar6 + 0x11))) {
        FUN_00641e00(piVar1,iVar6);
        iVar6 = 0;
        piVar9[4] = 0;
      }
      if (*piVar9 != 0) {
        FUN_00642380(piVar1,uVar5);
      }
      if (piVar9[4] != 0) break;
      FUN_00641ac0(piVar9 + 0x1f);
    }
    if ((*(byte *)(iVar6 + 0xc) & 2) != 0) goto LAB_006395c2;
    switch(*(undefined4 *)(iVar6 + 8)) {
    case 0:
      iVar8 = FUN_006391e0(*(uint *)(iVar6 + 0x24),(*(uint *)(iVar6 + 0x24) & 1) != 0);
      *(int *)(iVar6 + 0x18) = iVar8;
      if (iVar8 == 0) {
        DVar7 = GetLastError();
        *(DWORD *)(iVar6 + 0x14) = DVar7;
        *(undefined1 *)(iVar6 + 0x10) = 0xfe;
      }
      else {
        *(undefined1 *)(iVar6 + 0x10) = 1;
      }
      break;
    case 1:
switchD_006393b4_caseD_1:
      *(undefined1 *)(iVar6 + 0x10) = 1;
      break;
    case 2:
      iVar8 = FUN_0063d7e0(*(undefined4 *)(iVar6 + 0x18),*(undefined4 *)(iVar6 + 0x24));
      if (iVar8 != 0) {
        uVar5 = FUN_0063d4d0(*(undefined4 *)(iVar6 + 0x18),*(undefined4 *)(iVar6 + 0x2c),
                             *(undefined4 *)(iVar6 + 0x28));
LAB_0063941d:
        *(undefined4 *)(iVar6 + 0x28) = uVar5;
        *(undefined1 *)(iVar6 + 0x10) = 1;
      }
      goto LAB_00639427;
    case 3:
      iVar8 = FUN_0063d7e0(*(undefined4 *)(iVar6 + 0x18),*(undefined4 *)(iVar6 + 0x24));
      if (iVar8 != 0) {
        uVar5 = FUN_0063d670(*(undefined4 *)(iVar6 + 0x18),*(undefined4 *)(iVar6 + 0x2c),
                             *(undefined4 *)(iVar6 + 0x28));
        goto LAB_0063941d;
      }
LAB_00639427:
      DVar7 = GetLastError();
      *(DWORD *)(iVar6 + 0x14) = DVar7;
      if (DVar7 != 0) {
        *(undefined1 *)(iVar6 + 0x10) = 0xfe;
      }
      break;
    case 4:
      iVar8 = FUN_0063d470(*(undefined4 *)(iVar6 + 0x18),0,&param_1);
      if (iVar8 == 0) {
        *(undefined4 *)(iVar6 + 0x24) = 0;
LAB_006394d5:
        *(undefined1 *)(iVar6 + 0x10) = 0xfe;
        DVar7 = GetLastError();
        *(DWORD *)(iVar6 + 0x14) = DVar7;
      }
      else {
        *(int *)(iVar6 + 0x24) = param_1;
        *(undefined1 *)(iVar6 + 0x10) = 1;
      }
      break;
    case 5:
      iVar8 = FUN_0063da30(*(undefined4 *)(iVar6 + 0x18),*(undefined4 *)(iVar6 + 0x28));
      cVar4 = (-(iVar8 != 0) & 3U) - 2;
      *(char *)(iVar6 + 0x10) = cVar4;
      if (cVar4 == -2) {
        *(undefined1 *)(iVar6 + 0x10) = 0xfe;
        DVar7 = GetLastError();
        *(DWORD *)(iVar6 + 0x14) = DVar7;
      }
      break;
    case 6:
      iVar8 = FUN_006391e0(1,1);
      *(int *)(iVar6 + 0x18) = iVar8;
      if (iVar8 == 0) {
        *(undefined4 *)(iVar6 + 0x24) = 0;
        goto switchD_006393b4_caseD_1;
      }
      FUN_0063d900(iVar8);
      *(undefined4 *)(iVar6 + 0x24) = 1;
      *(undefined1 *)(iVar6 + 0x10) = 1;
      break;
    case 7:
      iVar8 = FUN_0063d120(*(undefined4 *)(iVar6 + 0x2c));
      if (iVar8 == 0) goto LAB_006394d5;
      *(undefined1 *)(iVar6 + 0x10) = 1;
      break;
    case 8:
      *(undefined1 *)(iVar6 + 0x10) = 1;
      *(undefined4 *)(iVar6 + 0x14) = 0;
      break;
    case 9:
      iVar8 = *(int *)(iVar6 + 0x2c);
      if (iVar8 != 0) {
        uVar5 = FUN_006391e0(9,1);
        *(undefined4 *)(iVar8 + 0xc) = uVar5;
        FUN_0063d470(uVar5,abStack_8,auStack_4);
        if ((*(int *)(iVar8 + 0xc) == 0) || ((abStack_8[0] & 8) == 0)) goto LAB_006394d5;
        *(undefined1 *)(iVar6 + 0x10) = 1;
        uVar5 = FUN_0063d9f0(*(undefined4 *)(iVar8 + 0xc));
        *(undefined4 *)(iVar8 + 0x10) = uVar5;
      }
      break;
    case 10:
      FUN_00641e90(&DAT_0070f3c8,*(undefined4 *)(iVar6 + 0x2c));
      *(undefined1 *)(iVar6 + 0x10) = 1;
      break;
    default:
      Log_Printf("FILE_devicethread - UNKNOWN TYPE OF OPERATION %d.\n",
                 *(undefined4 *)(piVar9[4] + 8));
    }
LAB_006395c2:
    if (*piVar9 == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_00642360(piVar9 + 5);
    }
    FUN_00641cb0(piVar9 + 0x12,iVar6);
    piVar9[4] = 0;
    if (*piVar9 != 0) {
      FUN_00642380(piVar9 + 5,uVar5);
    }
    if (*(code **)(iVar6 + 0x20) != (code *)0x0) {
      uVar3 = *(uint *)(iVar6 + 0xc);
      *(uint *)(iVar6 + 0xc) = uVar3 | 8;
      iVar8 = -1;
      if ((uVar3 & 2) == 0) {
        iVar8 = (int)*(char *)(iVar6 + 0x10);
      }
      (**(code **)(iVar6 + 0x20))(*(undefined4 *)(iVar6 + 4),iVar8,*(undefined4 *)(iVar6 + 0x1c));
    }
    SetEvent((HANDLE)piVar9[0x28]);
  } while( true );
}


// ==== 0x639690 FUN_00639690

void FUN_00639690(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_0070f36c != 0) {
    iVar3 = FUN_00641d40(&DAT_0070f3c8);
    while (iVar3 != 0) {
      FUN_0063d900(*(undefined4 *)(iVar3 + 0xc));
      (*DAT_006e75f0)(iVar3);
      iVar3 = FUN_00641d40(&DAT_0070f3c8);
    }
    DAT_0070f3fc = 1;
    iVar3 = 0;
    do {
      piVar1 = (int *)(iVar3 + DAT_0070f36c);
      if (*(int *)(iVar3 + DAT_0070f36c) != 0) {
        FUN_00641a90(piVar1 + 0x1f);
        iVar2 = *piVar1;
        while (iVar2 != 0) {
          FUN_0063e5c0(0);
          iVar2 = *piVar1;
        }
        FUN_00641b10(piVar1 + 0x1f);
        SetEvent((HANDLE)piVar1[0x28]);
        CloseHandle((HANDLE)piVar1[0x28]);
        FUN_00641c90(piVar1 + 0x12);
        FUN_00641c90(piVar1 + 5);
        FUN_0063f170(piVar1 + 0x21);
      }
      iVar3 = iVar3 + 0xac;
    } while (iVar3 < 0x1580);
    FUN_0063db80();
    FUN_00641c90(&DAT_0070f370);
    FUN_00641c90(&DAT_0070f3c8);
    (*DAT_006e75f0)(DAT_0070f36c);
    FUN_0063f170(&DAT_0070f3a4);
    DAT_0070f36c = 0;
  }
  return;
}


// ==== 0x6397e0 FUN_006397e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006397e0(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if (DAT_0070f36c == 0) {
    FUN_0063e850();
    if (param_1 == 0) {
      param_1 = 0x40;
    }
    if (param_3 == 0) {
      param_3 = 0x40;
    }
    DAT_0070f3fc = 0;
    FUN_00641bf0(&DAT_0070f370,0,0);
    FUN_00641bf0(&DAT_0070f3c8,0,0);
    DAT_0070f36c = param_4;
    FUN_0063f210(param_4,0x1580);
    DAT_0070f3c0 = DAT_0070f36c + 0x1580;
    iVar2 = param_3 * 0x30;
    FUN_0063f210(DAT_0070f3c0,iVar2);
    iVar1 = DAT_0070f3c0;
    for (; param_3 != 0; param_3 = param_3 + -1) {
      FUN_00641cb0(&DAT_0070f370,iVar1);
      iVar1 = iVar1 + 0x30;
    }
    CriticalSection__Init(&DAT_0070f3a4);
    _DAT_0070f3c4 = 0xffffffff;
    FUN_0063dbf0(param_1,DAT_0070f3c0 + iVar2);
    FUN_00642570(FUN_00639690);
  }
  return 1;
}


// ==== 0x6398f0 FUN_006398f0

int FUN_006398f0(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = (param_1 & 0x1f) * 0xac;
  piVar3 = (int *)(iVar2 + DAT_0070f36c);
  if (*(int *)(iVar2 + DAT_0070f36c) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00642360(piVar3 + 5);
  }
  if (*piVar3 == 0) {
LAB_00639975:
    iVar2 = -3;
  }
  else {
    if ((piVar3[4] == 0) || (*(uint *)(piVar3[4] + 4) != param_1)) {
      iVar2 = FUN_00641fb0(piVar3 + 5,FUN_006390f0,param_1);
      if (iVar2 == 0) {
        iVar2 = FUN_00641fb0(piVar3 + 0x12,FUN_006390f0,param_1);
        if (iVar2 != 0) {
          if ((*(byte *)(iVar2 + 0xc) & 2) == 0) {
            iVar2 = (int)*(char *)(iVar2 + 0x10);
          }
          else {
            iVar2 = -1;
          }
          goto LAB_0063997a;
        }
        goto LAB_00639975;
      }
    }
    iVar2 = 0;
  }
LAB_0063997a:
  if (*piVar3 != 0) {
    FUN_00642380(piVar3 + 5,uVar1);
  }
  return iVar2;
}


// ==== 0x639c00 FUN_00639c00

uint FUN_00639c00(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar3 = 0;
  iVar1 = (param_1 & 0x1f) * 0xac + DAT_0070f36c;
  if ((iVar1 == 0) || (iVar3 = FUN_006420d0(iVar1 + 0x48,FUN_006390f0,param_1), iVar3 == 0)) {
    Log_Printf("FILESYS_completeop - OPERATION NOT FOUND IN COMPLETED LIST.\n");
  }
  switch(*(undefined4 *)(iVar3 + 8)) {
  case 0:
    if (((*(byte *)(iVar3 + 0xc) & 2) == 0) || (*(int *)(iVar3 + 0x18) == 0)) {
      uVar2 = *(uint *)(iVar3 + 0x18);
    }
    else {
      FUN_0063d900(*(int *)(iVar3 + 0x18));
    }
    break;
  case 1:
    uVar2 = FUN_0063d900(*(undefined4 *)(iVar3 + 0x18));
    break;
  case 2:
  case 3:
    uVar2 = *(uint *)(iVar3 + 0x28);
    break;
  case 4:
  case 6:
    uVar2 = *(uint *)(iVar3 + 0x24);
    break;
  default:
    uVar2 = (uint)(*(char *)(iVar3 + 0x10) == '\x01');
    break;
  case 8:
    uVar2 = 0;
    break;
  case 9:
    iVar1 = *(int *)(iVar3 + 0x2c);
    if (iVar1 != 0) {
      if (((*(byte *)(iVar3 + 0xc) & 2) == 0) && (*(char *)(iVar3 + 0x10) == '\x01')) {
        FUN_00641cf0(&DAT_0070f3c8,iVar1);
        uVar2 = *(uint *)(iVar1 + 4);
      }
      else {
        if (*(int *)(iVar1 + 0xc) != 0) {
          FUN_0063d900(*(int *)(iVar1 + 0xc));
        }
        (*DAT_006e75f0)(iVar1);
      }
    }
    break;
  case 10:
    iVar1 = *(int *)(iVar3 + 0x2c);
    if (iVar1 != 0) {
      FUN_0063d900(*(undefined4 *)(iVar1 + 0xc));
      (*DAT_006e75f0)(iVar1);
      uVar2 = 1;
    }
  }
  if ((*(byte *)(iVar3 + 0xc) & 1) != 0) {
    (*DAT_006e75f0)(*(undefined4 *)(iVar3 + 0x2c));
  }
  *(undefined4 *)(iVar3 + 4) = 0;
  FUN_00641cf0(&DAT_0070f370,iVar3);
  return uVar2;
}


// ==== 0x639d70 FUN_00639d70

undefined4 FUN_00639d70(uint param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  byte bVar8;
  
  uVar3 = param_1;
  iVar7 = (param_1 & 0x1f) * 0xac;
  piVar1 = (int *)(iVar7 + DAT_0070f36c);
  if ((param_1 != 0) && (*piVar1 != 0)) {
    while( true ) {
      bVar8 = 0;
      if (*piVar1 == 0) {
        param_1 = 0;
      }
      else {
        param_1 = FUN_00642360(piVar1 + 5);
      }
      iVar5 = 0;
      if (*piVar1 != 0) {
        iVar5 = piVar1[4];
        if ((iVar5 == 0) || (*(uint *)(iVar5 + 4) != uVar3)) {
          iVar5 = FUN_00641fb0(piVar1 + 5,FUN_006390f0,uVar3);
          if (iVar5 == 0) {
            iVar5 = FUN_00641fb0(piVar1 + 0x12,FUN_006390f0,uVar3);
          }
          else {
            bVar8 = 1;
          }
        }
        else {
          bVar8 = 1;
        }
      }
      if (*piVar1 != 0) {
        FUN_00642380(piVar1 + 5,param_1);
      }
      if (!(bool)(bVar8 & iVar5 != 0)) break;
      cVar4 = FUN_0063e600(0);
      if (cVar4 == '\0') {
        puVar2 = (undefined4 *)(iVar7 + 0xa0 + DAT_0070f36c);
        WaitForSingleObject(*(HANDLE *)(iVar7 + 0xa0 + DAT_0070f36c),0xffffffff);
        ResetEvent((HANDLE)*puVar2);
      }
      else {
        FUN_0063f0a0(0);
        FUN_0063e5c0(1);
      }
    }
    uVar6 = FUN_006398f0(uVar3);
    return uVar6;
  }
  return 0xfffffffd;
}


// ==== 0x639f20 FUN_00639f20

void FUN_00639f20(uint param_1,code *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  uVar1 = param_1;
  iVar3 = 0;
  piVar4 = (int *)((param_1 & 0x1f) * 0xac + DAT_0070f36c);
  if (param_2 == (code *)0x0) {
    Log_Printf("FILESYS_callbackop - can not specify a NULL callback.\n");
  }
  if (*piVar4 == 0) {
    param_1 = 0;
  }
  else {
    param_1 = FUN_00642360(piVar4 + 5);
  }
  if (*piVar4 != 0) {
    iVar2 = piVar4[4];
    if ((iVar2 == 0) || (*(uint *)(iVar2 + 4) != uVar1)) {
      iVar2 = FUN_00641fb0(piVar4 + 5,FUN_006390f0,uVar1);
      if (iVar2 == 0) {
        iVar2 = FUN_00641fb0(piVar4 + 0x12,FUN_006390f0,uVar1);
      }
      else {
        iVar3 = 1;
      }
    }
    else {
      iVar3 = -1;
    }
    if (iVar2 != 0) {
      uVar1 = *(uint *)(iVar2 + 0xc);
      *(uint *)(iVar2 + 0xc) = uVar1 | 4;
      if (iVar3 == 0) {
        *(uint *)(iVar2 + 0xc) = uVar1 | 0xc;
        *(undefined4 *)(iVar2 + 0x20) = 0;
        (*param_2)(*(undefined4 *)(iVar2 + 4),(int)*(char *)(iVar2 + 0x10),
                   *(undefined4 *)(iVar2 + 0x1c));
      }
      else {
        *(code **)(iVar2 + 0x20) = param_2;
      }
      goto LAB_00639ff7;
    }
  }
  Log_Printf("FILESYS_callbackop - UNKNOWN FILEOP.\n");
LAB_00639ff7:
  if (*piVar4 != 0) {
    FUN_00642380(piVar4 + 5,param_1);
  }
  return;
}


// ==== 0x63a020 FUN_0063a020

void FUN_0063a020(uint param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = (param_1 & 0x1f) * 0xac + DAT_0070f36c;
  if (iVar1 != 0) {
    iVar1 = FUN_006420d0(iVar1 + 0x14,FUN_006390f0,param_1);
    if (iVar1 != 0) {
      *(undefined1 *)(iVar1 + 0x11) = param_2;
      FUN_00639150();
    }
  }
  return;
}


// ==== 0x63a150 FUN_0063a150

void FUN_0063a150(LPSTR param_1)

{
  DWORD DVar1;
  
  SetLastError(0);
  DVar1 = GetCurrentDirectoryA(0x1ff,param_1);
  if ((DVar1 == 0) || (0x1ff < DVar1)) {
    Log_Printf("getdirectory - FAILED TO FETCH, OR WAS TOO LONG (%D CHAR).\n",DVar1);
  }
  return;
}


// ==== 0x63a190 FUN_0063a190

undefined4 FUN_0063a190(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _strchr(param_1,0x7c);
  if (iVar1 == 0) {
    uVar2 = FUN_0063d080(param_1);
    return uVar2;
  }
  return 0;
}


// ==== 0x63a1e0 FUN_0063a1e0

void FUN_0063a1e0(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  HANDLE pvVar5;
  int unaff_EBX;
  int iVar6;
  
  iVar6 = unaff_EBX * 0xac;
  if (*(int *)(iVar6 + DAT_0070f36c) == 0) {
    uVar4 = FUN_00642360(&DAT_0070f370);
    iVar1 = iVar6 + 0x14 + DAT_0070f36c;
    *(undefined4 *)(iVar6 + 0x10 + DAT_0070f36c) = 0;
    FUN_00641bf0(iVar1,FUN_00639110,0);
    FUN_00641c40(iVar6 + 0x48 + DAT_0070f36c,0,0,iVar6 + 0x14 + DAT_0070f36c);
    FUN_00641a70(iVar6 + 0x7c + DAT_0070f36c);
    iVar1 = iVar6 + DAT_0070f36c;
    pvVar5 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
    *(HANDLE *)(iVar1 + 0xa0) = pvVar5;
    CriticalSection__Init(iVar1 + 0x84);
    iVar2 = DAT_0070f36c;
    iVar1 = iVar6 + 4 + DAT_0070f36c;
    *(undefined4 *)(iVar6 + 0xa4 + DAT_0070f36c) = 1;
    *(undefined4 *)(iVar6 + 0xa8 + iVar2) = 0xff;
    cVar3 = FUN_0063e950(iVar1,FUN_006392f0);
    if (cVar3 != '\0') {
      WaitForSingleObject(*(HANDLE *)(iVar6 + 0xa0 + DAT_0070f36c),0xffffffff);
      ResetEvent(*(HANDLE *)(iVar6 + 0xa0 + DAT_0070f36c));
      FUN_00642380(&DAT_0070f370,uVar4);
      return;
    }
    Log_Printf("FILE_startdevice - FAILED TO START THREAD FOR FILE SYSTEM DEVICE.\n");
    FUN_00642380(&DAT_0070f370,uVar4);
  }
  return;
}


// ==== 0x63a310 FUN_0063a310

int FUN_0063a310(undefined4 param_1,undefined1 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  
  iVar1 = FUN_00641d40(&DAT_0070f370);
  piVar4 = (int *)(param_4 * 0xac + DAT_0070f36c);
  if (iVar1 == 0) {
    Log_Printf("FILE_allocateop - NO FREE OPS LEFT TO ALLOCATE.\n");
    return 0;
  }
  if (*piVar4 == 0) {
    FUN_0063a1e0();
  }
  *(undefined1 *)(iVar1 + 0x11) = param_2;
  *(undefined4 *)(iVar1 + 8) = param_1;
  *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xfffffff0;
  *(undefined1 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = param_3;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0x2c) = 0;
  if (*piVar4 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00642360(piVar4 + 5);
  }
  *(uint *)(iVar1 + 4) = piVar4[0x29] << 5 | param_4;
  uVar3 = piVar4[0x29] + 1U & 0xffffff;
  piVar4[0x29] = uVar3;
  if (uVar3 == 0) {
    piVar4[0x29] = 1;
  }
  if (*piVar4 != 0) {
    FUN_00642380(piVar4 + 5,uVar2);
  }
  return iVar1;
}


// ==== 0x63a3f0 FileSystem_Create

/* [canon] runtime med (hopper+capstone) docs/re/misc.md */

void FileSystem_Create(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_1;
  if (param_1 == 0) {
    iVar3 = 0x40;
  }
  iVar1 = param_3;
  if (param_3 == 0) {
    iVar1 = 0x40;
  }
  uVar2 = (*DAT_006e75ec)("File System",iVar1 * 0x30 + 0x1580 + iVar3 * 0x24,0x100);
  FUN_006397e0(param_1,0,param_3,uVar2);
  return;
}


// ==== 0x63a450 FUN_0063a450

undefined4 FUN_0063a450(char *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  
  iVar2 = _strchr(param_1,0x7c);
  if (iVar2 == 0) {
    uVar3 = FUN_0063d080(param_1);
  }
  else {
    uVar3 = 0;
  }
  iVar2 = FUN_0063a310(6,param_2,param_3,uVar3);
  if (param_1 == (char *)0x0) {
    param_1 = "";
  }
  pcVar4 = param_1;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 1;
  uVar3 = (*DAT_006e75ec)(param_1,pcVar4 + (1 - (int)(param_1 + 1)),0x100);
  *(undefined4 *)(iVar2 + 0x2c) = uVar3;
  FUN_0063f1b0(uVar3,param_1,pcVar4 + (1 - (int)(param_1 + 1)));
  iVar5 = (*(uint *)(iVar2 + 4) & 0x1f) * 0xac + DAT_0070f36c;
  if (iVar5 == 0) {
    Log_Printf("FILE_queueop - ATTEMPT TO QUEUE FILEOP ON NON-EXISTANT DEVICE.\n");
  }
  FUN_00641e00(iVar5 + 0x14,iVar2);
  FUN_00641a90(iVar5 + 0x7c);
  return *(undefined4 *)(iVar2 + 4);
}


// ==== 0x63a5d0 FUN_0063a5d0

undefined4 FUN_0063a5d0(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  
  iVar2 = _strchr(param_1,0x7c);
  if (iVar2 == 0) {
    uVar3 = FUN_0063d080(param_1);
  }
  else {
    uVar3 = 0;
  }
  iVar2 = FUN_0063a310(0,param_3,param_4,uVar3);
  if (param_1 == (char *)0x0) {
    param_1 = "";
  }
  pcVar4 = param_1;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 1;
  uVar3 = (*DAT_006e75ec)(param_1,pcVar4 + (1 - (int)(param_1 + 1)),0x100);
  *(undefined4 *)(iVar2 + 0x2c) = uVar3;
  FUN_0063f1b0(uVar3,param_1,pcVar4 + (1 - (int)(param_1 + 1)));
  iVar5 = (*(uint *)(iVar2 + 4) & 0x1f) * 0xac + DAT_0070f36c;
  *(undefined4 *)(iVar2 + 0x24) = param_2;
  if (iVar5 == 0) {
    Log_Printf("FILE_queueop - ATTEMPT TO QUEUE FILEOP ON NON-EXISTANT DEVICE.\n");
  }
  FUN_00641e00(iVar5 + 0x14,iVar2);
  FUN_00641a90(iVar5 + 0x7c);
  return *(undefined4 *)(iVar2 + 4);
}


// ==== 0x63a690 FUN_0063a690

undefined4 FUN_0063a690(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_0063db00(param_1);
  iVar2 = FUN_0063a310(1,param_2,param_3,uVar1);
  iVar3 = DAT_0070f36c;
  *(undefined4 *)(iVar2 + 0x18) = param_1;
  iVar3 = (*(uint *)(iVar2 + 4) & 0x1f) * 0xac + iVar3;
  if (iVar3 == 0) {
    Log_Printf("FILE_queueop - ATTEMPT TO QUEUE FILEOP ON NON-EXISTANT DEVICE.\n");
  }
  FUN_00641e00(iVar3 + 0x14,iVar2);
  FUN_00641a90(iVar3 + 0x7c);
  return *(undefined4 *)(iVar2 + 4);
}


// ==== 0x63a700 FUN_0063a700

undefined4
FUN_0063a700(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_0063db00(param_1);
  iVar2 = FUN_0063a310(2,param_5,param_6,uVar1);
  *(undefined4 *)(iVar2 + 0x18) = param_1;
  *(undefined4 *)(iVar2 + 0x24) = param_2;
  iVar3 = (*(uint *)(iVar2 + 4) & 0x1f) * 0xac + DAT_0070f36c;
  *(undefined4 *)(iVar2 + 0x28) = param_4;
  *(undefined4 *)(iVar2 + 0x2c) = param_3;
  if (iVar3 == 0) {
    Log_Printf("FILE_queueop - ATTEMPT TO QUEUE FILEOP ON NON-EXISTANT DEVICE.\n");
  }
  FUN_00641e00(iVar3 + 0x14,iVar2);
  FUN_00641a90(iVar3 + 0x7c);
  return *(undefined4 *)(iVar2 + 4);
}


// ==== 0x63a780 FUN_0063a780

undefined4
FUN_0063a780(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_0063db00(param_1);
  iVar2 = FUN_0063a310(3,param_5,param_6,uVar1);
  *(undefined4 *)(iVar2 + 0x18) = param_1;
  *(undefined4 *)(iVar2 + 0x24) = param_2;
  iVar3 = (*(uint *)(iVar2 + 4) & 0x1f) * 0xac + DAT_0070f36c;
  *(undefined4 *)(iVar2 + 0x28) = param_4;
  *(undefined4 *)(iVar2 + 0x2c) = param_3;
  if (iVar3 == 0) {
    Log_Printf("FILE_queueop - ATTEMPT TO QUEUE FILEOP ON NON-EXISTANT DEVICE.\n");
  }
  FUN_00641e00(iVar3 + 0x14,iVar2);
  FUN_00641a90(iVar3 + 0x7c);
  return *(undefined4 *)(iVar2 + 4);
}


// ==== 0x63a800 FUN_0063a800

undefined4 FUN_0063a800(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_0063db00(param_1);
  iVar2 = FUN_0063a310(4,param_2,param_3,uVar1);
  iVar3 = DAT_0070f36c;
  *(undefined4 *)(iVar2 + 0x18) = param_1;
  iVar3 = (*(uint *)(iVar2 + 4) & 0x1f) * 0xac + iVar3;
  if (iVar3 == 0) {
    Log_Printf("FILE_queueop - ATTEMPT TO QUEUE FILEOP ON NON-EXISTANT DEVICE.\n");
  }
  FUN_00641e00(iVar3 + 0x14,iVar2);
  FUN_00641a90(iVar3 + 0x7c);
  return *(undefined4 *)(iVar2 + 4);
}


// ==== 0x63aa63 FUN_0063aa63

undefined4 FUN_0063aa63(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_ESI;
  int iVar3;
  undefined4 in_stack_00000014;
  undefined4 in_stack_00000018;
  
  uVar1 = FUN_0063db00();
  iVar2 = FUN_0063a310(10,in_stack_00000014,in_stack_00000018,uVar1);
  iVar3 = DAT_0070f36c;
  *(undefined4 *)(iVar2 + 0x2c) = unaff_ESI;
  iVar3 = (*(uint *)(iVar2 + 4) & 0x1f) * 0xac + iVar3;
  if (iVar3 == 0) {
    Log_Printf();
  }
  FUN_00641e00(iVar3 + 0x14);
  FUN_00641a90(iVar3 + 0x7c);
  return *(undefined4 *)(iVar2 + 4);
}


// ==== 0x63aad0 FUN_0063aad0

undefined4 FUN_0063aad0(code *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (DAT_0070f36c == 0) {
    Log_Printf("FILESYS_atomic - FILE SYSTEM NOT INITIALIZED, CALL FILESYS_init().\n");
  }
  if ((param_2 < 0) || (0x1f < param_2)) {
    Log_Printf("FILESYS_atomic - CALLED WITH ILLEGAL FILE DEVICE (%d).\n",param_2);
    return 0;
  }
  iVar4 = param_2 * 0xac + DAT_0070f36c;
  if (*(int *)(param_2 * 0xac + DAT_0070f36c) == 0) {
    FUN_0063a1e0();
  }
  iVar1 = iVar4 + 0x84;
  CriticalSection__Enter(iVar1);
  iVar2 = *(int *)(iVar4 + 0xa8);
  if (param_3 <= iVar2) {
    *(int *)(iVar4 + 0xa8) = param_3;
    uVar3 = (*param_1)(param_3,param_4);
    *(int *)(iVar4 + 0xa8) = iVar2;
    FUN_00641a90(iVar4 + 0x7c);
    CriticalSection__Leave(iVar1);
    return uVar3;
  }
  Log_Printf("FILESYS_atomic - CALLED AT PRIORITY (%d) LOWER THAN CURRENT DEVICE PRIORITY (%d).\n",
             param_3,iVar2);
  CriticalSection__Leave(iVar1);
  return 0;
}


// ==== 0x63aba0 FUN_0063aba0

undefined1 FUN_0063aba0(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (0x28 < iVar1) {
    FUN_0063f210(param_1,iVar1);
  }
  FUN_0063f1b0(param_1,&DAT_006e75e8,iVar1);
  return 1;
}


// ==== 0x63abd0 FUN_0063abd0

undefined4 FUN_0063abd0(int *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  if (*param_1 < 0x28) {
    FUN_0063f210(&DAT_006e75e8,0x28);
  }
  FUN_0063f1b0(&DAT_006e75e8,param_1,*param_1);
  if (DAT_006e75f4 != (char *)0x0) {
    pcVar3 = DAT_006e75f4 + 1;
    pcVar2 = DAT_006e75f4;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    cVar1 = *DAT_006e75f4;
    if (('`' < cVar1) && (cVar1 < '{')) {
      *DAT_006e75f4 = cVar1 + -0x20;
    }
    if (DAT_006e75f4[(int)(pcVar2 + (-1 - (int)pcVar3))] != '\\') {
      pcVar3 = DAT_006e75f4 + -1;
      do {
        pcVar2 = pcVar3 + 1;
        pcVar3 = pcVar3 + 1;
      } while (*pcVar2 != '\0');
      pcVar3[0] = '\\';
      pcVar3[1] = '\0';
    }
    if (DAT_006e75e8 == 0x28) {
      cVar1 = *DAT_006e7600;
      if (('`' < cVar1) && (cVar1 < '{')) {
        *DAT_006e7600 = cVar1 + -0x20;
      }
    }
  }
  return 1;
}


// ==== 0x63b280 FUN_0063b280

void FUN_0063b280(void)

{
  int iVar1;
  char cVar2;
  char *in_EAX;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  HANDLE hFile;
  int iVar6;
  DWORD DVar7;
  uint uVar8;
  char *pcVar9;
  uint *puVar10;
  char *in_stack_0000010c;
  
  *in_EAX = *in_EAX + (char)in_EAX;
  pcVar9 = in_stack_0000010c;
  do {
    cVar2 = FUN_0063d150(pcVar9);
    if (cVar2 == '\0') {
      pcVar3 = DAT_006e75f4;
      do {
        cVar2 = *pcVar3;
        pcVar3[(int)(&stack0x00000004 + -(int)DAT_006e75f4)] = cVar2;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar9;
      } while (cVar2 != '\0');
      do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      uVar5 = (int)pcVar4 - (int)pcVar9;
      pcVar3 = &stack0x00000003;
      do {
        pcVar4 = pcVar3 + 1;
        pcVar3 = pcVar3 + 1;
      } while (*pcVar4 != '\0');
      pcVar4 = pcVar9;
      for (uVar8 = uVar5 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar3 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar3 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar3 = pcVar3 + 1;
      }
      hFile = CreateFileA(&stack0x00000004,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                          (HANDLE)0x0);
      if (hFile == (HANDLE)0xffffffff) {
        iVar6 = (*DAT_006e75ec)("queued file",0x110,0);
        FUN_0063f1b0(iVar6 + 4,pcVar9,0x10c);
        FUN_00641e00(0x70f400,iVar6);
      }
      else {
        FUN_00642e60(7,"Already in cache, updating database.\n");
        iVar6 = func_0x0063b050(pcVar9);
        if (iVar6 == 0) {
          Log_Printf(PTR_s_A_fatal_error_has_occurred_in_th_006e7618);
        }
        iVar1 = DAT_0070f490;
        puVar10 = (uint *)(DAT_0070f490 + 0x10);
        DVar7 = GetFileSize(hFile,(LPDWORD)0x0);
        uVar5 = *puVar10;
        *puVar10 = *puVar10 + DVar7;
        *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + (uint)CARRY4(uVar5,DVar7);
        *(undefined1 *)(iVar6 + 0x104) = 1;
        CloseHandle(hFile);
      }
    }
    pcVar9 = pcVar9 + 0x10c;
    in_EAX = in_EAX + -1;
  } while (in_EAX != (char *)0x0);
  uRam0070f468 = 1;
  FUN_00641a90(0x70f454);
  return;
}


// ==== 0x63b28a FUN_0063b28a

void FUN_0063b28a(void)

{
  int iVar1;
  char cVar2;
  int in_EAX;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  HANDLE hFile;
  int iVar6;
  DWORD DVar7;
  uint uVar8;
  char *unaff_EBX;
  uint *puVar9;
  int iStack00000004;
  
  iStack00000004 = in_EAX;
  do {
    cVar2 = FUN_0063d150(unaff_EBX);
    if (cVar2 == '\0') {
      pcVar3 = DAT_006e75f4;
      do {
        cVar2 = *pcVar3;
        pcVar3[(int)(&stack0x00000008 + -(int)DAT_006e75f4)] = cVar2;
        pcVar3 = pcVar3 + 1;
        pcVar4 = unaff_EBX;
      } while (cVar2 != '\0');
      do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      uVar5 = (int)pcVar4 - (int)unaff_EBX;
      pcVar3 = (char *)((int)register0x00000010 + 7);
      do {
        pcVar4 = pcVar3 + 1;
        pcVar3 = pcVar3 + 1;
      } while (*pcVar4 != '\0');
      pcVar4 = unaff_EBX;
      for (uVar8 = uVar5 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar3 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar3 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar3 = pcVar3 + 1;
      }
      hFile = CreateFileA(&stack0x00000008,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                          (HANDLE)0x0);
      if (hFile == (HANDLE)0xffffffff) {
        iVar6 = (*DAT_006e75ec)("queued file",0x110,0);
        FUN_0063f1b0(iVar6 + 4,unaff_EBX,0x10c);
        FUN_00641e00(0x70f400,iVar6);
      }
      else {
        FUN_00642e60(7,"Already in cache, updating database.\n");
        iVar6 = func_0x0063b050(unaff_EBX);
        if (iVar6 == 0) {
          Log_Printf(PTR_s_A_fatal_error_has_occurred_in_th_006e7618);
        }
        iVar1 = DAT_0070f490;
        puVar9 = (uint *)(DAT_0070f490 + 0x10);
        DVar7 = GetFileSize(hFile,(LPDWORD)0x0);
        uVar5 = *puVar9;
        *puVar9 = *puVar9 + DVar7;
        *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + (uint)CARRY4(uVar5,DVar7);
        *(undefined1 *)(iVar6 + 0x104) = 1;
        CloseHandle(hFile);
      }
    }
    unaff_EBX = unaff_EBX + 0x10c;
    iStack00000004 = iStack00000004 + -1;
  } while (iStack00000004 != 0);
  uRam0070f468 = 1;
  FUN_00641a90();
  return;
}


// ==== 0x63b390 FUN_0063b390

/* WARNING: Instruction at (ram,0x0063b391) overlaps instruction at (ram,0x0063b390)
    */
/* WARNING: This function may have set the stack pointer */

void __thiscall FUN_0063b390(int param_1)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  HANDLE hFile;
  int iVar6;
  DWORD DVar7;
  uint in_EAX;
  uint uVar8;
  char *unaff_EBX;
  uint *puVar9;
  char in_CF;
  undefined4 uStack00000009;
  uint uStack00000011;
  undefined8 in_stack_00000010;
  
  uStack00000011 = (uint)((ulonglong)in_stack_00000010 >> 8);
  *(char *)(param_1 + 0x10cc3) = *(char *)(param_1 + 0x10cc3) + (char)in_EAX + in_CF;
  *(char *)(in_EAX - 0x77) = *(char *)(in_EAX - 0x77) + (char)param_1;
  uVar5 = in_EAX & 0x10;
  while (uVar5 != 0) {
    cVar2 = FUN_0063d150((int3)unaff_EBX);
    if (cVar2 == '\0') {
      pcVar3 = DAT_006e75f4;
      do {
        cVar2 = *pcVar3;
        pcVar3[(int)&stack0x00000010 + (5 - (int)DAT_006e75f4)] = cVar2;
        pcVar3 = pcVar3 + 1;
        pcVar4 = unaff_EBX;
      } while (cVar2 != '\0');
      do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      uVar5 = (int)pcVar4 - (int)unaff_EBX;
      pcVar3 = (char *)((int)&stack0x00000010 + 4);
      do {
        pcVar4 = pcVar3 + 1;
        pcVar3 = pcVar3 + 1;
      } while (*pcVar4 != '\0');
      pcVar4 = unaff_EBX;
      for (uVar8 = uVar5 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar3 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar3 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar3 = pcVar3 + 1;
      }
      hFile = CreateFileA((LPCSTR)((int)&stack0x00000010 + 5),0x80000000,0,
                          (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
      if (hFile == (HANDLE)0xffffffff) {
        iVar6 = (*DAT_006e75ec)("queued file",0x110,0);
        FUN_0063f1b0(iVar6 + 4,unaff_EBX,0x10c);
        FUN_00641e00(0x70f400,iVar6);
      }
      else {
        FUN_00642e60(7,0x6a8cfc);
        iVar6 = func_0x0063b050(unaff_EBX);
        if (iVar6 == 0) {
          Log_Printf((int3)PTR_s_A_fatal_error_has_occurred_in_th_006e7618);
        }
        iVar1 = DAT_0070f490;
        puVar9 = (uint *)(DAT_0070f490 + 0x10);
        DVar7 = GetFileSize(hFile,(LPDWORD)0x0);
        uVar5 = *puVar9;
        *puVar9 = *puVar9 + DVar7;
        *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + (uint)CARRY4(uVar5,DVar7);
        *(undefined1 *)(iVar6 + 0x104) = 1;
        CloseHandle(hFile);
      }
    }
    unaff_EBX = unaff_EBX + 0x10c;
    uVar5 = uStack00000011 - 1;
    uStack00000011 = uVar5;
  }
  uRam0070f468 = 1;
  uStack00000009 = 0x63b3b7;
  FUN_00641a90();
  return;
}


// ==== 0x63b3a0 FUN_0063b3a0

/* WARNING: Control flow encountered bad instruction data */

void FUN_0063b3a0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== 0x63b3ad FUN_0063b3ad

void FUN_0063b3ad(void)

{
  FUN_00641a90(0x10070f4);
  return;
}


// ==== 0x63c0c0 FUN_0063c0c0

void FUN_0063c0c0(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_00639c00(param_1);
  param_3[8] = 0;
  if (param_2 == 1) {
    param_3[2] = param_3[2] + iVar2;
    iVar1 = param_3[6];
    param_3[4] = param_3[4] + iVar2;
    param_3[6] = iVar1 + iVar2;
    if (iVar2 < (int)param_3[5]) {
      param_3[3] = 0;
    }
    else {
      param_3[3] = param_3[3] - iVar2;
    }
    if ((int)param_3[3] < 1) {
      return;
    }
    uVar3 = 0x2000;
    if ((int)param_3[3] < 0x2001) {
      uVar3 = param_3[3];
    }
    param_3[5] = uVar3;
    iVar2 = (*(code *)param_3[7])(param_3[1],param_3[2],iVar1 + iVar2,param_3[5],*param_3,param_3);
    param_3[8] = iVar2;
    if (iVar2 != 0) {
      FUN_00639f20(iVar2,FUN_0063c0c0);
      return;
    }
  }
  param_3[3] = 0;
  return;
}


// ==== 0x63c160 FUN_0063c160

undefined4 __thiscall FUN_0063c160(code *param_1,undefined4 param_2)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = (*param_1)(param_2);
  if (iVar1 != 0) {
    FUN_00639f20(iVar1,FUN_0063c0c0);
    do {
      do {
        FUN_00639d70(iVar1);
      } while (in_EAX != 0);
    } while (iVar1 != 0);
  }
  return 0;
}


// ==== 0x63c200 FUN_0063c200

char FUN_0063c200(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_0063a5d0(param_1,param_2,param_3,0);
  if (iVar1 != 0) {
    FUN_00639d70(iVar1);
    iVar2 = FUN_006398f0(iVar1);
    uVar3 = FUN_00639c00(iVar1);
    *param_4 = uVar3;
    return '\x01' - (iVar2 != 1);
  }
  *param_4 = 0;
  return '\0';
}


// ==== 0x63c290 FUN_0063c290

void FUN_0063c290(undefined4 param_1)

{
  FUN_0063c160(param_1);
  return;
}


// ==== 0x63c2c0 FUN_0063c2c0

bool FUN_0063c2c0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0063a690(param_1,param_2,0);
  if (iVar1 != 0) {
    FUN_00639d70(iVar1);
    iVar1 = FUN_00639c00(iVar1);
    return iVar1 != 0;
  }
  return false;
}


// ==== 0x63c420 FUN_0063c420

bool FUN_0063c420(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0063a450(param_1,param_2,0);
  if (iVar1 != 0) {
    FUN_00639d70(iVar1);
    iVar1 = FUN_00639c00(iVar1);
    return iVar1 != 0;
  }
  return false;
}


// ==== 0x63c4a0 FUN_0063c4a0

void FUN_0063c4a0(undefined4 param_1)

{
  FUN_0063c420(param_1,DAT_006e761c);
  return;
}


// ==== 0x63cd70 FUN_0063cd70

bool FUN_0063cd70(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  
  puVar1 = param_2;
  cVar2 = FUN_0063c200(*param_2,6,param_1,&param_2);
  if (cVar2 != '\0') {
    iVar3 = FUN_0063c290(param_2,0,puVar1[1],puVar1[2],param_1 + -1);
    FUN_0063c2c0(param_2,param_1 + -1);
    return iVar3 == puVar1[2];
  }
  return false;
}


// ==== 0x63cdd0 FUN_0063cdd0

bool FUN_0063cdd0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = param_2;
  local_c = param_3;
  local_14 = param_1;
  local_8 = 1;
  uVar1 = FUN_0063a190(param_1,DAT_006e761c,&local_14);
  iVar2 = FUN_0063aad0(FUN_0063cd70,uVar1);
  return iVar2 == 1;
}


// ==== 0x63ce90 FUN_0063ce90

void FUN_0063ce90(char *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  
  *param_2 = '\0';
  pcVar1 = param_1;
  do {
    cVar2 = *pcVar1;
    pcVar1 = pcVar1 + 1;
  } while (cVar2 != '\0');
  if (pcVar1 + (1 - (int)(param_1 + 1)) < (char *)0x104) {
    pcVar1 = param_1;
    do {
      cVar2 = *pcVar1;
      pcVar1 = pcVar1 + 1;
    } while (cVar2 != '\0');
    pcVar1 = pcVar1 + (1 - (int)(param_1 + 1));
  }
  else {
    pcVar1 = (char *)0x104;
  }
  FUN_0063f1b0(param_2,param_1,pcVar1);
  cVar2 = *param_2;
  pcVar1 = param_2;
  if (cVar2 == '\0') {
LAB_0063cf21:
    if (*pcVar1 != '\0') {
      param_2 = pcVar1 + 2;
      cVar2 = pcVar1[2];
      while (cVar2 != '\0') {
        if ((cVar2 == '\\') || (cVar2 == '/')) {
          if (*param_2 == '\0') goto LAB_0063cf1a;
          param_2 = param_2 + 1;
          break;
        }
        pcVar1 = param_2 + 1;
        param_2 = param_2 + 1;
        cVar2 = *pcVar1;
      }
      pcVar1 = param_2;
      if (*param_2 != '\0') {
        while ((param_2 = pcVar1, *param_2 != '\\' && (*param_2 != '/'))) {
          pcVar1 = param_2 + 1;
          if (param_2[1] == '\0') {
            param_2[2] = '\0';
            return;
          }
        }
      }
      goto LAB_0063cf1a;
    }
  }
  else {
    do {
      if (((cVar2 == '\\') || (cVar2 == '/')) && ((pcVar1[1] == '\\' || (pcVar1[1] == '/'))))
      goto LAB_0063cf21;
      cVar2 = pcVar1[1];
      pcVar1 = pcVar1 + 1;
    } while (cVar2 != '\0');
  }
  cVar2 = *param_2;
  for (; ((cVar2 != '\0' && (*param_2 != '\\')) && (*param_2 != '/')); param_2 = param_2 + 1) {
    cVar2 = param_2[1];
  }
LAB_0063cf1a:
  param_2[1] = '\0';
  return;
}


// ==== 0x63cf70 FUN_0063cf70

undefined4 FUN_0063cf70(LPCSTR param_1,LPSTR param_2,DWORD param_3)

{
  char cVar1;
  DWORD DVar2;
  LPCSTR pCVar3;
  BOOL BVar4;
  HANDLE hFindFile;
  CHAR *pCVar5;
  byte local_250 [4];
  char *local_24c;
  DWORD local_248;
  CHAR local_244 [260];
  _WIN32_FIND_DATAA local_140;
  
  DVar2 = GetFullPathNameA(param_1,param_3,param_2,&local_24c);
  if (DVar2 == 0) {
    pCVar3 = param_1;
    do {
      cVar1 = *pCVar3;
      pCVar3 = pCVar3 + 1;
    } while (cVar1 != '\0');
    if (pCVar3 + (1 - (int)(param_1 + 1)) < (char *)0x104) {
      pCVar3 = param_1;
      do {
        cVar1 = *pCVar3;
        pCVar3 = pCVar3 + 1;
      } while (cVar1 != '\0');
      FUN_0063f1b0(param_2,param_1,pCVar3 + (1 - (int)(param_1 + 1)));
      return 0;
    }
    FUN_0063f1b0(param_2,param_1,0x104);
  }
  else {
    FUN_0063ce90(param_2,local_244);
    BVar4 = GetVolumeInformationA
                      (local_244,(LPSTR)0x0,0,(LPDWORD)0x0,&local_248,(LPDWORD)local_250,(LPSTR)0x0,
                       0);
    if (BVar4 != 0) {
      if ((local_250[0] & 2) == 0) {
        CharUpperA(param_2);
      }
      if ((local_250[0] & 4) == 0) {
        hFindFile = FindFirstFileA(param_1,&local_140);
        if (hFindFile != (HANDLE)0xffffffff) {
          FindClose(hFindFile);
          pCVar5 = local_140.cFileName;
          do {
            cVar1 = *pCVar5;
            pCVar5 = pCVar5 + 1;
            *local_24c = cVar1;
            local_24c = local_24c + 1;
          } while (cVar1 != '\0');
        }
      }
      return 1;
    }
  }
  return 0;
}


// ==== 0x63d080 FUN_0063d080

int FUN_0063d080(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0063e3d0(param_1);
  if (iVar1 != 0) {
    return iVar1 + -0x40;
  }
  return 0;
}


// ==== 0x63d0a0 FUN_0063d0a0

int FUN_0063d0a0(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  CriticalSection__Enter(&DAT_0070f46c);
  iVar2 = 0;
  pcVar1 = DAT_0070f48c;
  if (0 < DAT_0070f488) {
    while (*pcVar1 != '\0') {
      iVar2 = iVar2 + 1;
      pcVar1 = pcVar1 + 0x24;
      if (DAT_0070f488 <= iVar2) {
        CriticalSection__Leave(&DAT_0070f46c);
        return iVar2;
      }
    }
    if (iVar2 < DAT_0070f488) {
      iVar3 = iVar2 * 0x24;
      FUN_0063f210(DAT_0070f48c + iVar3,0x24);
      pcVar1 = DAT_0070f48c;
      DAT_0070f48c[iVar3] = '\x01';
      pcVar1 = pcVar1 + iVar3 + 4;
      pcVar1[0] = -1;
      pcVar1[1] = -1;
      pcVar1[2] = -1;
      pcVar1[3] = -1;
    }
  }
  CriticalSection__Leave(&DAT_0070f46c);
  return iVar2;
}


// ==== 0x63d120 FUN_0063d120

void FUN_0063d120(LPCSTR param_1)

{
  SetLastError(0);
  DeleteFileA(param_1);
  return;
}


// ==== 0x63d140 __stricmp

int __cdecl __stricmp(char *_Str1,char *_Str2)

{
  int iVar1;
  
  iVar1 = __stricmp(_Str1,_Str2);
  return iVar1;
}


// ==== 0x63d150 FUN_0063d150

undefined1 FUN_0063d150(char *param_1)

{
  char cVar1;
  void *pvVar2;
  undefined1 uVar3;
  
  uVar3 = 0;
  if (DAT_0070f494 != '\0') {
    cVar1 = *param_1;
    if (((cVar1 != '\\') && (cVar1 != '/')) && (param_1[1] != ':')) {
      if (DAT_0070f490 != 0) {
        if (cVar1 == '.') {
          param_1 = param_1 + 2;
        }
        pvVar2 = _bsearch(param_1,(void *)(DAT_0070f490 + 0x128),*(size_t *)(DAT_0070f490 + 0xc),
                          0x105,__stricmp);
        if (pvVar2 != (void *)0x0) {
          uVar3 = *(undefined1 *)((int)pvVar2 + 0x104);
        }
      }
      return uVar3;
    }
  }
  return 0;
}


// ==== 0x63d1c0 FUN_0063d1c0

undefined4 FUN_0063d1c0(LPCSTR param_1,uint param_2,uint *param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  HANDLE pvVar7;
  DWORD DVar8;
  LPVOID pvVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  LPCSTR pCVar13;
  CHAR *pCVar14;
  undefined4 *puVar15;
  DWORD dwDesiredAccess;
  uint local_120;
  DWORD local_11c;
  uint local_118;
  DWORD local_114;
  undefined4 local_110;
  undefined4 local_108;
  CHAR local_104 [260];
  
  local_110 = 1;
  local_120 = 0x80;
  uVar2 = FUN_0063d0a0();
  *param_3 = 0;
  SetLastError(0);
  local_108 = param_2 & 1;
  local_11c = 0x80000000;
  if (local_108 == 0) {
    local_11c = 0xc0000000;
  }
  local_118 = (uint)(local_108 != 0);
  if ((param_2 & 2) == 0) {
    local_114 = (-(uint)((param_2 & 4) != 0) & 2) + 3;
  }
  else {
    local_114 = ((param_2 & 4) != 0) + 1;
  }
  if ((param_2 & 0x10) != 0) {
    local_120 = 0x20000080;
  }
  if ((param_2 & 0x20) != 0) {
    local_120 = local_120 | 0x8000000;
  }
  iVar12 = uVar2 * 0x24;
  *(uint *)(DAT_0070f48c + 8 + iVar12) = param_2;
  iVar3 = FUN_0063e3d0(param_1);
  iVar11 = DAT_0070f48c;
  if (iVar3 == 0) {
    cVar1 = '\0';
  }
  else {
    cVar1 = (char)iVar3 + -0x40;
  }
  *(char *)(DAT_0070f48c + 1 + iVar12) = cVar1;
  if (((param_2 & 0x40) == 0) &&
     (cVar1 = FUN_0063d150(param_1), iVar11 = DAT_0070f48c, cVar1 != '\0')) {
    *(char *)(DAT_0070f48c + 1 + iVar12) = *DAT_006e75f4 + -0x40;
    pcVar4 = DAT_006e75f4;
    do {
      cVar1 = *pcVar4;
      pcVar4[(int)(local_104 + -(int)DAT_006e75f4)] = cVar1;
      pcVar4 = pcVar4 + 1;
      pcVar5 = param_1;
    } while (cVar1 != '\0');
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar6 = (int)pcVar5 - (int)param_1;
    pCVar14 = (CHAR *)((int)&local_108 + 3);
    do {
      pcVar4 = pCVar14 + 1;
      pCVar14 = pCVar14 + 1;
    } while (*pcVar4 != '\0');
    pCVar13 = param_1;
    for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pCVar14 = *(undefined4 *)pCVar13;
      pCVar13 = pCVar13 + 4;
      pCVar14 = pCVar14 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pCVar14 = *pCVar13;
      pCVar13 = pCVar13 + 1;
      pCVar14 = pCVar14 + 1;
    }
    pvVar7 = CreateFileA(local_104,local_11c,local_118,(LPSECURITY_ATTRIBUTES)0x0,local_114,
                         local_120,(HANDLE)0x0);
    iVar11 = DAT_0070f48c;
    *(HANDLE *)(DAT_0070f48c + 4 + iVar12) = pvVar7;
  }
  puVar15 = (undefined4 *)(iVar11 + iVar12 + 4);
  iVar3 = iVar11;
  if (*(int *)(iVar11 + iVar12 + 4) == -1) {
    puVar15 = (undefined4 *)((undefined1 *)(iVar11 + iVar12) + 4);
    pvVar7 = CreateFileA(param_1,local_11c,local_118,(LPSECURITY_ATTRIBUTES)0x0,local_114,local_120,
                         (HANDLE)0x0);
    iVar3 = DAT_0070f48c;
    *puVar15 = pvVar7;
    if (pvVar7 == (HANDLE)0xffffffff) {
      *(undefined1 *)(iVar11 + iVar12) = 0;
      return 0;
    }
  }
  *(undefined4 *)(iVar11 + iVar12 + 0xc) = 0x2000;
  iVar3 = iVar3 + iVar12;
  DVar8 = GetFileSize((HANDLE)*puVar15,(LPDWORD)0x0);
  *(DWORD *)(iVar3 + 0x1c) = DVar8;
  if ((param_2 & 8) == 0) {
    *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) & 0xfffffff7;
    *(undefined4 *)(iVar3 + 0x10) = 0xffffffff;
    *(undefined4 *)(iVar3 + 0x14) = 0;
  }
  else {
    if (local_108 == 0) {
      DVar8 = 0x8000004;
      dwDesiredAccess = 2;
    }
    else {
      DVar8 = 0x8000002;
      dwDesiredAccess = 4;
    }
    pvVar7 = CreateFileMappingA(*(HANDLE *)(iVar3 + 4),(LPSECURITY_ATTRIBUTES)0x0,DVar8,0,0,
                                (LPCSTR)0x0);
    iVar3 = DAT_0070f48c;
    *(HANDLE *)(DAT_0070f48c + iVar12 + 0x10) = pvVar7;
    if (pvVar7 != (HANDLE)0x0) {
      iVar11 = iVar3 + iVar12;
      pvVar9 = MapViewOfFile(pvVar7,dwDesiredAccess,0,0,*(SIZE_T *)(iVar11 + 0x1c));
      *(LPVOID *)(iVar11 + 0x14) = pvVar9;
    }
    iVar3 = iVar3 + iVar12;
    if (*(int *)(iVar3 + 0x14) == 0) {
      *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) & 0xfffffff7;
      local_110 = 0;
    }
  }
  *(uint *)(iVar3 + 0x20) = ~(param_2 >> 6) & 1;
  *param_3 = ~uVar2;
  return local_110;
}


// ==== 0x63d470 FUN_0063d470

undefined4 FUN_0063d470(uint param_1,undefined4 *param_2,undefined4 *param_3)

{
  char *pcVar1;
  
  if ((((DAT_0070f48c != 0) && ((int)param_1 < 0)) && ((int)~param_1 < DAT_0070f488)) &&
     (pcVar1 = (char *)(DAT_0070f48c + ~param_1 * 0x24), *pcVar1 != '\0')) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(pcVar1 + 8);
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(pcVar1 + 0x1c);
    }
    return 1;
  }
  SetLastError(6);
  return 0;
}


// ==== 0x63d4d0 FUN_0063d4d0

int FUN_0063d4d0(uint param_1,LPVOID param_2,uint param_3)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  int iVar4;
  uint uVar5;
  uint nNumberOfBytesToRead;
  LPVOID lpBuffer;
  int iVar6;
  int iVar7;
  int local_4;
  
  local_4 = 0;
  if ((((DAT_0070f48c == 0) || (-1 < (int)param_1)) || (DAT_0070f488 <= (int)~param_1)) ||
     (iVar6 = ~param_1 * 0x24, *(char *)(iVar6 + DAT_0070f48c) == '\0')) {
    SetLastError(6);
    return 0;
  }
  SetLastError(0);
  iVar4 = DAT_0070f48c;
  iVar1 = *(int *)(iVar6 + 0x1c + DAT_0070f48c);
  if (iVar1 < *(int *)(iVar6 + 0x18 + DAT_0070f48c)) {
    *(int *)(iVar6 + 0x18 + DAT_0070f48c) = iVar1;
  }
  if (*(int *)(iVar6 + 0x20 + iVar4) != 0) {
    iVar1 = *(int *)(iVar6 + 0x18 + iVar4);
    iVar7 = *(int *)(iVar6 + 0x1c + iVar4);
    if (iVar7 < (int)(iVar1 + param_3)) {
      param_3 = iVar7 - iVar1;
    }
  }
  nNumberOfBytesToRead = *(uint *)(iVar6 + 0xc + iVar4);
  *(undefined1 *)(iVar6 + 2 + iVar4) = 1;
  lpBuffer = param_2;
  uVar5 = param_3;
  if (param_3 != 0) {
    while (*(char *)(iVar6 + 2 + iVar4) != '\0') {
      if (uVar5 < nNumberOfBytesToRead) {
        nNumberOfBytesToRead = uVar5;
      }
      iVar1 = *(int *)(iVar6 + 0x14 + iVar4);
      if (iVar1 == 0) {
        BVar2 = ReadFile(*(HANDLE *)(iVar6 + 4 + iVar4),lpBuffer,nNumberOfBytesToRead,&param_1,
                         (LPOVERLAPPED)0x0);
        if (BVar2 != 0) goto LAB_0063d5c0;
        DVar3 = GetLastError();
        if (DVar3 != 0x3e5) {
          local_4 = 0;
          iVar4 = DAT_0070f48c;
          break;
        }
        FUN_0063e5c0(1);
        iVar4 = DAT_0070f48c;
      }
      else {
        FUN_0063f1b0(lpBuffer,*(int *)(iVar6 + 0x18 + iVar4) + iVar1,nNumberOfBytesToRead);
        param_1 = nNumberOfBytesToRead;
        FUN_0063e5c0(0);
LAB_0063d5c0:
        iVar4 = DAT_0070f48c;
        iVar7 = *(int *)(iVar6 + 0x18 + DAT_0070f48c) + param_1;
        *(int *)(iVar6 + 0x18 + DAT_0070f48c) = iVar7;
        local_4 = local_4 + param_1;
        iVar1 = *(int *)(iVar6 + 0x1c + iVar4);
        lpBuffer = (LPVOID)((int)lpBuffer + param_1);
        if (iVar1 < iVar7) {
          *(int *)(iVar6 + 0x18 + iVar4) = iVar1;
        }
        if (param_1 < nNumberOfBytesToRead) break;
        uVar5 = param_3 - param_1;
        param_3 = uVar5;
      }
      if (uVar5 == 0) {
        *(undefined1 *)(iVar6 + 2 + iVar4) = 0;
        return local_4;
      }
    }
  }
  *(undefined1 *)(iVar6 + 2 + iVar4) = 0;
  return local_4;
}


// ==== 0x63d670 FUN_0063d670

int FUN_0063d670(uint param_1,LPCVOID param_2,uint param_3)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  int iVar4;
  int iVar5;
  LPCVOID lpBuffer;
  uint uVar6;
  int iVar7;
  uint nNumberOfBytesToWrite;
  int local_4;
  
  local_4 = 0;
  if ((((DAT_0070f48c == 0) || (-1 < (int)param_1)) || (DAT_0070f488 <= (int)~param_1)) ||
     (iVar7 = ~param_1 * 0x24, *(char *)(iVar7 + DAT_0070f48c) == '\0')) {
    SetLastError(6);
    return 0;
  }
  SetLastError(0);
  iVar4 = DAT_0070f48c;
  iVar5 = *(int *)(iVar7 + 0x1c + DAT_0070f48c);
  if (iVar5 < *(int *)(iVar7 + 0x18 + DAT_0070f48c)) {
    *(int *)(iVar7 + 0x18 + DAT_0070f48c) = iVar5;
  }
  nNumberOfBytesToWrite = *(uint *)(iVar7 + 0xc + iVar4);
  if (*(int *)(iVar7 + 0x14 + iVar4) != 0) {
    iVar5 = *(int *)(iVar7 + 0x18 + iVar4);
    iVar1 = *(int *)(iVar7 + 0x1c + iVar4);
    if (iVar1 < (int)(iVar5 + param_3)) {
      param_3 = iVar1 - iVar5;
    }
  }
  lpBuffer = param_2;
  uVar6 = param_3;
  if (param_3 == 0) {
    return 0;
  }
  do {
    if (uVar6 < nNumberOfBytesToWrite) {
      nNumberOfBytesToWrite = uVar6;
    }
    iVar5 = *(int *)(iVar7 + 0x14 + iVar4);
    if (iVar5 == 0) {
      BVar2 = WriteFile(*(HANDLE *)(iVar7 + 4 + iVar4),lpBuffer,nNumberOfBytesToWrite,&param_1,
                        (LPOVERLAPPED)0x0);
      if (BVar2 != 0) goto LAB_0063d747;
      DVar3 = GetLastError();
      if (DVar3 != 0x3e5) {
        return 0;
      }
      FUN_0063e5c0(1);
      iVar4 = DAT_0070f48c;
    }
    else {
      FUN_0063f1b0(*(int *)(iVar7 + 0x18 + iVar4) + iVar5,lpBuffer,nNumberOfBytesToWrite);
      param_1 = nNumberOfBytesToWrite;
      FUN_0063e5c0(0);
LAB_0063d747:
      iVar4 = DAT_0070f48c;
      iVar5 = *(int *)(iVar7 + 0x18 + DAT_0070f48c) + param_1;
      *(int *)(iVar7 + 0x18 + DAT_0070f48c) = iVar5;
      local_4 = local_4 + param_1;
      lpBuffer = (LPCVOID)((int)lpBuffer + param_1);
      if (param_1 < nNumberOfBytesToWrite) {
        uVar6 = 0;
      }
      else {
        uVar6 = param_3 - param_1;
      }
      param_3 = uVar6;
      if (*(int *)(iVar7 + 0x1c + iVar4) < iVar5) {
        *(int *)(iVar7 + 0x1c + iVar4) = iVar5;
      }
    }
    if (uVar6 == 0) {
      return local_4;
    }
  } while( true );
}


// ==== 0x63d7e0 FUN_0063d7e0

undefined4 FUN_0063d7e0(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  int iVar4;
  
  if ((((DAT_0070f48c != 0) && ((int)param_1 < 0)) && ((int)~param_1 < DAT_0070f488)) &&
     (iVar4 = ~param_1 * 0x24, *(char *)(iVar4 + DAT_0070f48c) != '\0')) {
    SetLastError(0);
    iVar2 = DAT_0070f48c;
    *(int *)(iVar4 + 0x18 + DAT_0070f48c) = param_2;
    iVar1 = *(int *)(iVar4 + 0x1c + iVar2);
    if (iVar1 < param_2) {
      *(int *)(iVar4 + 0x18 + iVar2) = iVar1;
    }
    else if (param_2 < 0) {
      *(undefined4 *)(iVar4 + 0x18 + iVar2) = 0;
    }
    if (*(int *)(iVar4 + 0x14 + iVar2) == 0) {
      DVar3 = SetFilePointer(*(HANDLE *)(iVar4 + 4 + iVar2),*(LONG *)(iVar4 + 0x18 + iVar2),
                             (PLONG)0x0,0);
      *(DWORD *)(iVar4 + 0x18 + DAT_0070f48c) = DVar3;
    }
    return 1;
  }
  SetLastError(6);
  return 0;
}


// ==== 0x63d900 FUN_0063d900

undefined4 FUN_0063d900(uint param_1)

{
  HANDLE hObject;
  int iVar1;
  
  if ((((DAT_0070f48c != 0) && ((int)param_1 < 0)) && ((int)~param_1 < DAT_0070f488)) &&
     (iVar1 = ~param_1 * 0x24, *(char *)(iVar1 + DAT_0070f48c) != '\0')) {
    SetLastError(0);
    if (*(int *)(iVar1 + 0x10 + DAT_0070f48c) != -1) {
      UnmapViewOfFile(*(LPCVOID *)(iVar1 + 0x14 + DAT_0070f48c));
      CloseHandle(*(HANDLE *)(iVar1 + 0x10 + DAT_0070f48c));
    }
    hObject = *(HANDLE *)(iVar1 + 4 + DAT_0070f48c);
    if (hObject != (HANDLE)0xffffffff) {
      CloseHandle(hObject);
    }
    *(undefined1 *)(iVar1 + DAT_0070f48c) = 0;
    return 1;
  }
  SetLastError(6);
  return 0;
}


// ==== 0x63d990 FUN_0063d990

undefined4 FUN_0063d990(undefined4 param_1,undefined4 param_2,undefined1 param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = FUN_0063d0a0();
  iVar1 = DAT_0070f48c + uVar2 * 0x24;
  *(undefined1 *)(iVar1 + 1) = param_3;
  *(undefined4 *)(iVar1 + 4) = 0xffffffff;
  *(undefined4 *)(iVar1 + 8) = 8;
  *(undefined4 *)(iVar1 + 0xc) = 0x2000;
  *(undefined4 *)(iVar1 + 0x10) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x14) = param_1;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = param_2;
  *(undefined4 *)(iVar1 + 0x20) = 1;
  *param_4 = ~uVar2;
  return 1;
}


// ==== 0x63d9f0 FUN_0063d9f0

undefined4 FUN_0063d9f0(uint param_1)

{
  char *pcVar1;
  
  if ((((DAT_0070f48c != 0) && ((int)param_1 < 0)) && ((int)~param_1 < DAT_0070f488)) &&
     (pcVar1 = (char *)(DAT_0070f48c + ~param_1 * 0x24), *pcVar1 != '\0')) {
    return *(undefined4 *)(pcVar1 + 0x14);
  }
  SetLastError(6);
  return 0;
}


// ==== 0x63da30 FUN_0063da30

BOOL FUN_0063da30(uint param_1,LONG param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  int iVar3;
  
  if ((((DAT_0070f48c != 0) && ((int)param_1 < 0)) && ((int)~param_1 < DAT_0070f488)) &&
     (iVar3 = ~param_1 * 0x24, *(char *)(iVar3 + DAT_0070f48c) != '\0')) {
    SetLastError(0);
    if (*(int *)(iVar3 + 0x14 + DAT_0070f48c) == 0) {
      BVar1 = SetEndOfFile(*(HANDLE *)(iVar3 + 4 + DAT_0070f48c));
      DVar2 = SetFilePointer(*(HANDLE *)(iVar3 + 4 + DAT_0070f48c),param_2,(PLONG)0x0,0);
      *(DWORD *)(iVar3 + 0x18 + DAT_0070f48c) = DVar2;
      return BVar1;
    }
    return 0;
  }
  SetLastError(6);
  return 0;
}


// ==== 0x63dac0 FUN_0063dac0

int FUN_0063dac0(uint param_1)

{
  char *pcVar1;
  char cVar2;
  
  if ((((DAT_0070f48c == 0) || (-1 < (int)param_1)) || (DAT_0070f488 <= (int)~param_1)) ||
     (pcVar1 = (char *)(DAT_0070f48c + ~param_1 * 0x24), *pcVar1 == '\0')) {
    SetLastError(6);
  }
  else {
    cVar2 = pcVar1[2];
    if (cVar2 != 0) {
      pcVar1[2] = '\0';
      return (int)cVar2;
    }
  }
  return 0;
}


// ==== 0x63db00 FUN_0063db00

int FUN_0063db00(uint param_1)

{
  char *pcVar1;
  
  if ((((DAT_0070f48c != 0) && ((int)param_1 < 0)) && ((int)~param_1 < DAT_0070f488)) &&
     (pcVar1 = (char *)(DAT_0070f48c + ~param_1 * 0x24), *pcVar1 != '\0')) {
    return (int)pcVar1[1];
  }
  SetLastError(6);
  return 0;
}


// ==== 0x63db80 FUN_0063db80

void FUN_0063db80(void)

{
  uint uVar1;
  int iVar2;
  
  if (DAT_0070f48c != 0) {
    uVar1 = 0;
    if (0 < DAT_0070f488) {
      iVar2 = 0;
      do {
        if (*(char *)(iVar2 + DAT_0070f48c) != '\0') {
          FUN_0063d900(~uVar1);
        }
        uVar1 = uVar1 + 1;
        iVar2 = iVar2 + 0x24;
      } while ((int)uVar1 < DAT_0070f488);
    }
    DAT_0070f48c = 0;
    DAT_0070f488 = 0;
    FUN_0063f170(&DAT_0070f46c);
  }
  return;
}


// ==== 0x63dbf0 FUN_0063dbf0

void FUN_0063dbf0(int param_1,undefined4 param_2)

{
  if (DAT_0070f48c != 0) {
    FUN_0063db80();
  }
  DAT_0070f488 = param_1;
  DAT_0070f48c = param_2;
  FUN_0063f210(param_2,param_1 * 0x24);
  CriticalSection__Init(&DAT_0070f46c);
  return;
}


// ==== 0x63dc30 FUN_0063dc30

uint __fastcall FUN_0063dc30(int param_1)

{
  byte *in_EAX;
  
  if (param_1 == 1) {
    return (uint)*in_EAX;
  }
  if (param_1 == 2) {
    return (uint)CONCAT11(*in_EAX,in_EAX[1]);
  }
  if (param_1 == 3) {
    return (uint)CONCAT21(CONCAT11(*in_EAX,in_EAX[1]),in_EAX[2]);
  }
  if (param_1 == 4) {
    return CONCAT31(CONCAT21(CONCAT11(*in_EAX,in_EAX[1]),in_EAX[2]),in_EAX[3]);
  }
  return 0;
}


// ==== 0x63dc80 FUN_0063dc80

int __fastcall FUN_0063dc80(char *param_1)

{
  char *in_EAX;
  int iVar1;
  int iVar2;
  
  iVar1 = _tolower((int)*param_1);
  iVar2 = _tolower((int)*in_EAX);
  iVar1 = iVar1 - iVar2;
  for (; (iVar1 == 0 && (*param_1 != '\0')); param_1 = param_1 + 1) {
    in_EAX = in_EAX + 1;
    iVar1 = _tolower((int)param_1[1]);
    iVar2 = _tolower((int)*in_EAX);
    iVar1 = iVar1 - iVar2;
  }
  return iVar1;
}


// ==== 0x63dcd0 FUN_0063dcd0

ulonglong FUN_0063dcd0(void)

{
  int in_EAX;
  uint uVar1;
  undefined4 uVar2;
  int unaff_EDI;
  
  if (in_EAX < 5) {
    uVar1 = FUN_0063dc30();
    return (ulonglong)uVar1;
  }
  uVar2 = FUN_0063dc30();
  return CONCAT44(uVar2,CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(unaff_EDI + -4 + in_EAX),
                                                   *(undefined1 *)(unaff_EDI + -3 + in_EAX)),
                                          *(undefined1 *)(unaff_EDI + -2 + in_EAX)),
                                 *(undefined1 *)(unaff_EDI + -1 + in_EAX)));
}


// ==== 0x63dd20 FUN_0063dd20

undefined4 FUN_0063dd20(byte *param_1)

{
  short sVar1;
  undefined4 uVar2;
  
  sVar1 = CONCAT11(*param_1,param_1[1]);
  uVar2 = 0;
  if (sVar1 == -0x3f05) {
    return 1;
  }
  if (CONCAT31(CONCAT21(sVar1,param_1[2]),param_1[3]) == 0x42494746) {
    return 2;
  }
  if (((uint)CONCAT11(param_1[1],param_1[2]) << 8 | (uint)*param_1 << 0x18) == 0x42494700) {
    uVar2 = 3;
  }
  return uVar2;
}


// ==== 0x63dd90 FUN_0063dd90

int FUN_0063dd90(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0063dd20(param_1);
  if (iVar1 == 1) {
    return CONCAT11(*(undefined1 *)(param_1 + 2),*(undefined1 *)(param_1 + 3)) + 4;
  }
  if ((1 < iVar1) && (iVar1 < 4)) {
    return CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0xd))
                             ,*(undefined1 *)(param_1 + 0xe)),*(undefined1 *)(param_1 + 0xf));
  }
  return 0;
}


// ==== 0x63dec0 FUN_0063dec0

char * FUN_0063dec0(int param_1,int param_2,int param_3,undefined4 *param_4,undefined4 *param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  int local_8;
  int local_4;
  
  iVar2 = param_1;
  local_8 = 0;
  local_4 = 0;
  iVar3 = FUN_0063dd90(param_1);
  cVar1 = *(char *)(iVar3 + -8 + param_1);
  iVar3 = iVar3 + -8 + param_1;
  if (((('@' < cVar1) && (cVar1 < '[')) || (('`' < cVar1 && (cVar1 < '{')))) &&
     ((((('/' < *(char *)(iVar3 + 1) && (*(char *)(iVar3 + 1) < ':')) &&
        ('/' < *(char *)(iVar3 + 2))) &&
       ((*(char *)(iVar3 + 2) < ':' && ('/' < *(char *)(iVar3 + 3))))) &&
      (*(char *)(iVar3 + 3) < ':')))) {
    local_4 = 8;
  }
  iVar6 = 4;
  pcVar7 = (char *)(param_1 + 0x10);
  param_1 = 4;
  iVar3 = FUN_0063dd90(iVar2);
  pcVar5 = (char *)(iVar3 + (iVar2 - local_4));
  iVar3 = FUN_0063dd20(iVar2);
  if (iVar3 == 1) {
    iVar6 = 3;
    pcVar7 = (char *)(iVar2 + 6);
    param_1 = 3;
  }
  else if ((iVar3 == 3) && (iVar6 = *(char *)(iVar2 + 3) + -0x30, param_1 = iVar6, 4 < iVar6)) {
    param_1 = 4;
  }
  if (param_2 == 0) {
    while (pcVar7 < pcVar5) {
      pcVar7 = pcVar7 + param_1 + iVar6;
      if (local_8 == param_3) goto LAB_0063e02c;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      local_8 = local_8 + 1;
    }
  }
  else {
    while (pcVar7 < pcVar5) {
      pcVar7 = pcVar7 + param_1 + iVar6;
      iVar3 = FUN_0063dc80();
      if (iVar3 == 0) {
LAB_0063e02c:
        if (param_4 != (undefined4 *)0x0) {
          uVar4 = FUN_0063dcd0();
          *param_4 = uVar4;
        }
        if (param_5 != (undefined4 *)0x0) {
          uVar4 = FUN_0063dc30();
          *param_5 = uVar4;
        }
        return pcVar7;
      }
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
    }
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  return (char *)0x0;
}


// ==== 0x63e300 FUN_0063e300

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

int FUN_0063e300(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  DWORD DVar2;
  int iVar3;
  char *pcVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined4 uStackY_20;
  undefined4 uStackY_1c;
  
  SetLastError(0);
  uStackY_1c = 0x63e31a;
  DVar2 = GetLogicalDriveStringsA(0,(LPSTR)0x0);
  iVar7 = -(DVar2 + 0x803 & 0xfffffffc);
  pcVar4 = &stack0xfffffff0 + iVar7;
  *(DWORD *)(&stack0xffffffec + iVar7) = DVar2 + 0x7ff;
  *(undefined1 **)(&stack0xffffffe8 + iVar7) = &stack0xfffffff0 + iVar7;
  *(undefined4 *)((int)&uStackY_1c + iVar7) = param_1;
  *(undefined4 *)((int)&uStackY_20 + iVar7) = 0x63e340;
  iVar3 = FUN_0063cf70();
  if (iVar3 == 0) {
    *(undefined1 **)(&stack0xffffffec + iVar7) = &stack0xfffffff0 + iVar7;
    *(undefined4 *)(&stack0xffffffe8 + iVar7) = 0x63e34d;
    FUN_0063a150();
  }
  *(undefined4 *)(&stack0xffffffec + iVar7) = param_2;
  *(undefined1 **)(&stack0xffffffe8 + iVar7) = &stack0xfffffff0 + iVar7;
  *(undefined4 *)((int)&uStackY_1c + iVar7) = 0x63e35a;
  FUN_0063ce90();
  *(undefined1 **)(&stack0xffffffec + iVar7) = &stack0xfffffff0 + iVar7;
  *(DWORD *)(&stack0xffffffe8 + iVar7) = DVar2;
  puVar5 = (undefined1 *)((int)&uStackY_1c + iVar7);
  *(undefined4 *)((int)&uStackY_1c + iVar7) = 0x63e361;
  GetLogicalDriveStringsA(*(DWORD *)(&stack0xffffffe8 + iVar7),*(LPSTR *)(&stack0xffffffec + iVar7))
  ;
  puVar6 = puVar5 + -4;
  *(undefined4 *)(puVar5 + -4) = 0x63e367;
  DVar2 = GetLogicalDrives();
  iVar7 = 0;
  while (*pcVar4 != '\0') {
    if ((DVar2 & 1 << ((byte)iVar7 & 0x1f)) != 0) {
      *(undefined4 *)(puVar6 + -4) = param_2;
      *(char **)(puVar6 + -8) = pcVar4;
      *(undefined4 *)(puVar6 + -0xc) = 0x63e38c;
      iVar3 = __stricmp(*(char **)(puVar6 + -8),*(char **)(puVar6 + -4));
      if (iVar3 == 0) break;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
    }
    iVar7 = iVar7 + 1;
    if (0x1f < iVar7) {
      return 0;
    }
  }
  if (0x1f < iVar7) {
    return 0;
  }
  return iVar7 + 0x41;
}


// ==== 0x63e3d0 FUN_0063e3d0

int FUN_0063e3d0(LPCSTR param_1)

{
  DWORD DVar1;
  LPSTR local_10c;
  char local_108;
  char local_107;
  
  local_10c = (LPSTR)_strchr(param_1,0x7c);
  if (local_10c == (LPSTR)0x0) {
    if (param_1 == (LPCSTR)0x0) {
      param_1 = ".";
    }
    DVar1 = GetFullPathNameA(param_1,0x105,&local_108,&local_10c);
    CharUpperA(&local_108);
    if ((1 < (int)DVar1) && (local_107 == ':')) {
      return (int)local_108;
    }
  }
  return 0;
}


// ==== 0x63e4d0 FUN_0063e4d0

undefined4 FUN_0063e4d0(undefined4 *param_1)

{
  *param_1 = 0;
  if ((code *)param_1[1] != (code *)0x0) {
    (*(code *)param_1[1])();
    return 0;
  }
  (*(code *)param_1[2])(param_1[3]);
  return 0;
}


// ==== 0x63e510 FUN_0063e510

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063e510(void)

{
  if (DAT_0070f4e8 != 0) {
    DAT_0070f4e8 = 0;
    CloseHandle(DAT_0070f4f0);
    DAT_0070f4f0 = (HANDLE)0x0;
    _DAT_0070f4ec = 0;
  }
  return;
}


// ==== 0x63e580 FUN_0063e580

void FUN_0063e580(int param_1)

{
  HANDLE hThread;
  
  if (param_1 == -1) {
    hThread = GetCurrentThread();
  }
  else {
    hThread = *(HANDLE *)(param_1 + 4);
  }
  if (hThread != (HANDLE)0x0) {
    TerminateThread(hThread,0);
  }
  CloseHandle(hThread);
  return;
}


// ==== 0x63e5c0 FUN_0063e5c0

void FUN_0063e5c0(DWORD param_1)

{
  SleepEx(param_1,1);
  return;
}


// ==== 0x63e600 FUN_0063e600

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0063e600(int param_1)

{
  DWORD DVar1;
  
  if (param_1 == 0) {
    DVar1 = GetCurrentThreadId();
    return DVar1 == _DAT_0070f4ec;
  }
  if (param_1 == -1) {
    return true;
  }
  DVar1 = GetCurrentThreadId();
  return *(DWORD *)(param_1 + 8) == DVar1;
}


// ==== 0x63e6f0 FUN_0063e6f0

undefined4 FUN_0063e6f0(int param_1,undefined4 param_2)

{
  HANDLE hThread;
  
  hThread = DAT_0070f4f0;
  if (param_1 != 0) {
    if (param_1 == -1) {
      hThread = GetCurrentThread();
    }
    else {
      hThread = *(HANDLE *)(param_1 + 4);
    }
  }
  if (hThread != (HANDLE)0x0) {
    switch(param_2) {
    default:
      SetThreadPriority(hThread,0);
      return 1;
    case 1:
      SetThreadPriority(hThread,1);
      return 1;
    case 2:
      SetThreadPriority(hThread,2);
      return 1;
    case 3:
      SetThreadPriority(hThread,0xf);
      return 1;
    case 0xfffffffd:
      SetThreadPriority(hThread,-0xf);
      return 1;
    case 0xfffffffe:
      SetThreadPriority(hThread,-2);
      return 1;
    case 0xffffffff:
      SetThreadPriority(hThread,-1);
      return 1;
    }
  }
  return 0;
}


// ==== 0x63e7e0 FUN_0063e7e0

undefined1 FUN_0063e7e0(int param_1,DWORD param_2)

{
  DWORD DVar1;
  int iVar2;
  BOOL BVar3;
  int iVar4;
  
  iVar2 = FUN_0063fc90();
  DVar1 = param_2;
  iVar2 = iVar2 + param_2;
  do {
    BVar3 = GetExitCodeThread(*(HANDLE *)(param_1 + 4),&param_2);
    if ((BVar3 != 0) && (param_2 != 0x103)) {
      return 1;
    }
  } while ((DVar1 == 0) || (iVar4 = FUN_0063fc90(), iVar2 < iVar4));
  return 0;
}


// ==== 0x63e850 FUN_0063e850

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063e850(void)

{
  HANDLE hTargetProcessHandle;
  HANDLE hSourceHandle;
  HANDLE hSourceProcessHandle;
  LPHANDLE lpTargetHandle;
  DWORD dwDesiredAccess;
  BOOL bInheritHandle;
  DWORD dwOptions;
  
  if (DAT_0070f4e8 == 0) {
    _DAT_0070f4ec = GetCurrentThreadId();
    dwOptions = 2;
    bInheritHandle = 0;
    dwDesiredAccess = 0;
    lpTargetHandle = (LPHANDLE)&DAT_0070f4f0;
    hTargetProcessHandle = GetCurrentProcess();
    hSourceHandle = GetCurrentThread();
    hSourceProcessHandle = GetCurrentProcess();
    DuplicateHandle(hSourceProcessHandle,hSourceHandle,hTargetProcessHandle,lpTargetHandle,
                    dwDesiredAccess,bInheritHandle,dwOptions);
    FUN_00642570(FUN_0063e510);
    DAT_0070f4e8 = 1;
  }
  return;
}


// ==== 0x63e8b0 FUN_0063e8b0

undefined1
FUN_0063e8b0(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined4 param_5)

{
  undefined1 uVar1;
  uintptr_t uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar1 = 0;
  (*(code *)PTR_FUN_006e80b0)(1);
  uStack_c = param_2;
  uStack_8 = 0;
  uStack_10 = __beginthreadex((void *)0x0,param_4,FUN_0063e4d0,&uStack_10,4,(uint *)(param_1 + 8));
  if (uStack_10 != 0) {
    uVar1 = 1;
    *(uintptr_t *)(param_1 + 4) = uStack_10;
    FUN_0063e6f0(param_1,param_5);
    ResumeThread(*(HANDLE *)(param_1 + 4));
    while (uStack_10 != 0) {
      SleepEx(1,1);
    }
  }
  (*(code *)PTR_FUN_006e80b0)(0);
  return uVar1;
}


// ==== 0x63e950 FUN_0063e950

undefined1
FUN_0063e950(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5,
            undefined4 param_6)

{
  undefined1 uVar1;
  uintptr_t uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar1 = 0;
  (*(code *)PTR_FUN_006e80b0)(1);
  uStack_8 = param_2;
  uStack_4 = param_3;
  uStack_c = 0;
  uStack_10 = __beginthreadex((void *)0x0,param_5,FUN_0063e4d0,&uStack_10,4,(uint *)(param_1 + 8));
  if (uStack_10 != 0) {
    uVar1 = 1;
    *(uintptr_t *)(param_1 + 4) = uStack_10;
    FUN_0063e6f0(param_1,param_6);
    ResumeThread(*(HANDLE *)(param_1 + 4));
    while (uStack_10 != 0) {
      SleepEx(1,1);
    }
  }
  (*(code *)PTR_FUN_006e80b0)(0);
  return uVar1;
}


// ==== 0x63ea00 FUN_0063ea00

void FUN_0063ea00(void)

{
  uint uVar1;
  
  FUN_00641a70(&DAT_0070f51c);
  DAT_0070f510 = 1;
  FUN_00641ac0(&DAT_0070f51c);
  while (DAT_0070f4f4 != 0) {
    DAT_0070fe24 = DAT_0070fe24 + 1;
    DAT_0070fe28 = DAT_0070fe28 + 1;
    GetTickCount();
    uVar1 = 0;
    do {
      if (*(code **)((int)&DAT_0070fe00 + uVar1) != (code *)0x0) {
        (**(code **)((int)&DAT_0070fe00 + uVar1))();
      }
      uVar1 = uVar1 + 4;
    } while (uVar1 < 0x20);
    FUN_00641ac0(&DAT_0070f51c);
  }
  FUN_00641b10(&DAT_0070f51c);
  DAT_0070f510 = 0;
  DAT_0070fe20 = 0;
  return;
}


// ==== 0x63eaa0 FUN_0063eaa0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063eaa0(void)

{
  DWORD DVar1;
  UINT uDelay;
  
  DAT_0070f508 = DAT_0070f508 + ((int)(DAT_0070f514 + DAT_0070f518) >> 0x10);
  DAT_0070f518 = DAT_0070f514 + DAT_0070f518 & 0xffff;
  if (DAT_0070f4f4 != 0) {
    DVar1 = GetTickCount();
    uDelay = (DAT_0070f508 - DVar1) - 1;
    if ((int)uDelay < 1) {
      if ((int)uDelay < -1000) {
        DVar1 = GetTickCount();
        DAT_0070f508 = DVar1 + 1;
        _DAT_0070f528 = _DAT_0070f528 + 1;
      }
      uDelay = 1;
    }
    DAT_0070f50c = timeSetEvent(uDelay,DAT_0070f4f8,FUN_0063eaa0,0,0);
    if (DAT_0070f50c == 0) {
      DAT_0070f4f4 = DAT_0070f50c;
      DAT_0070fe20 = DAT_0070f50c;
      timeEndPeriod(DAT_0070f4f8);
    }
  }
  if ((DAT_0070f510 != 0) && (DAT_0070f524 == 0)) {
    FUN_00641a90(&DAT_0070f51c);
  }
  FUN_00643230();
  return;
}


// ==== 0x63eb90 FUN_0063eb90

void FUN_0063eb90(void)

{
  if (DAT_0070f4f4 != 0) {
    DAT_0070fe20 = 0;
    DAT_0070f4f4 = 0;
    if (DAT_0070f50c != 0) {
      timeKillEvent(DAT_0070f50c);
    }
    timeEndPeriod(DAT_0070f4f8);
    if (DAT_0070f510 != 0) {
      FUN_00641a90(&DAT_0070f51c);
    }
    while ((DAT_0070f50c != 0 && (DAT_0070f510 != 0))) {
      FUN_0063e5c0(1);
    }
  }
  DAT_0070f518 = 0;
  DAT_0070f524 = 0;
  DAT_0070f4f8 = 0;
  DAT_0070f50c = 0;
  return;
}


// ==== 0x63ec20 FUN_0063ec20

int FUN_0063ec20(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  MMRESULT MVar3;
  int iVar4;
  DWORD DVar5;
  DWORD DVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int local_c;
  timecaps_tag local_8;
  
  local_c = 5;
  if (DAT_0070f52c == 0) {
    DAT_0070f52c = 1;
    puVar9 = &DAT_0070fe00;
    for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
  }
  do {
    FUN_0063eb90();
    if (param_1 == 0) {
LAB_0063ec83:
      param_1 = 100;
    }
    else if ((param_1 < 1) || (10000 < param_1)) {
      Log_Printf("TIMER_init - BAD TIMER FREQUENCY SPECIFIED %d\n",param_1);
      goto LAB_0063ec83;
    }
    DAT_0070f514 = (int)(0x3e80000 / (longlong)param_1);
    DAT_0070f518 = 0;
    DAT_0070fe24 = 0;
    MVar3 = timeGetDevCaps(&local_8,8);
    if (MVar3 != 0) {
      Log_Printf("TIMER_init - MULTIMEDIA TIMER NOT FOUND.\n");
      DAT_0070fe20 = 0;
      DAT_0070f4f4 = 0;
      return 0;
    }
    local_8.wPeriodMin = 1;
    local_8.wPeriodMax = 1;
    DAT_0070f4f8 = 1;
    if (DAT_0070f514 < 0x10000) {
      Log_Printf("TIMER_init - MULTIMEDIA TIMER CANNOT SUPPORT THIS FREQUENCY.\n");
      DAT_0070fe20 = 0;
      DAT_0070f4f4 = 0;
      return 0;
    }
    FUN_0063f210(&DAT_0070f4fc,0xc);
    cVar2 = FUN_0063e8b0(&DAT_0070f4fc,FUN_0063ea00,0,0,2);
    if (cVar2 == '\0') {
      Log_Printf("TIMER_init - FAILED TO CREATE TIMER THREAD.\n");
      DAT_0070fe20 = 0;
      DAT_0070f4f4 = 0;
      return 0;
    }
    MVar3 = timeBeginPeriod(DAT_0070f4f8);
    if (MVar3 != 0) {
      DAT_0070fe20 = 0;
      DAT_0070f4f4 = 0;
      FUN_00641a90(&DAT_0070f51c);
      Log_Printf("TIMER_init - FAILED TO INITIALIZE MULTIMEDIA TIMER : 0x%x.\n",MVar3);
      return DAT_0070fe20;
    }
    FUN_00642570(FUN_0063eb90);
    uVar1 = DAT_0070f524;
    DAT_0070f4f4 = param_1;
    DAT_0070fe20 = param_1;
    if ((param_1 != 0) && (DAT_0070f50c == 0)) {
      DAT_0070f524 = 1;
      DAT_0070f508 = GetTickCount();
      FUN_0063eaa0(0,0,0,0,0);
    }
    DAT_0070f524 = uVar1;
    iVar4 = FUN_0063fc90();
    DVar5 = GetTickCount();
    iVar8 = DAT_0070fe20 * 5;
    DVar6 = GetTickCount();
    while (((int)DVar6 < (int)(DVar5 + iVar8) && (iVar7 = FUN_0063fc90(), iVar4 == iVar7))) {
      FUN_0063e5c0(1);
      DVar6 = GetTickCount();
    }
    iVar8 = FUN_0063fc90();
    if (iVar4 == iVar8) {
      FUN_0063eb90();
    }
    if (DAT_0070fe20 != 0) {
      return DAT_0070fe20;
    }
    local_c = local_c + -1;
    if (local_c == 0) {
      Log_Printf("TIMER_init - FAILED TO INITIALIZE WINDOWS MULTIMEDIA TIMER, TRY RE-RUNNING.\n");
      return DAT_0070fe20;
    }
  } while( true );
}


// ==== 0x63eea0 FUN_0063eea0

void FUN_0063eea0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar1 = -1;
  if (param_2 == -1) {
    param_2 = 0;
  }
  else if (param_2 == 0) {
    param_2 = 1;
  }
  iVar3 = DAT_0070f630 + 1;
  piVar5 = &DAT_0070f540;
  iVar4 = 2;
  do {
    if (piVar5[-4] == param_1) {
LAB_0063eef7:
      iVar2 = iVar4 + -2;
    }
    else {
      iVar2 = iVar1;
      if ((piVar5[-4] == 0) && (iVar1 == -1)) {
        if (DAT_0070f630 == 0) goto LAB_0063eef7;
        DAT_0070f630 = DAT_0070f630 + -1;
      }
    }
    if (*piVar5 == param_1) {
LAB_0063ef10:
      iVar2 = iVar4 + -1;
    }
    else if ((*piVar5 == 0) && (iVar2 == -1)) {
      if (DAT_0070f630 == 0) goto LAB_0063ef10;
      DAT_0070f630 = DAT_0070f630 + -1;
    }
    iVar1 = iVar4;
    if ((((piVar5[4] != param_1) && (iVar1 = iVar2, piVar5[4] == 0)) && (iVar2 == -1)) &&
       (iVar1 = iVar4, DAT_0070f630 != 0)) {
      DAT_0070f630 = DAT_0070f630 + -1;
      iVar1 = iVar2;
    }
    if (piVar5[8] == param_1) {
LAB_0063ef43:
      iVar1 = iVar4 + 1;
    }
    else if ((piVar5[8] == 0) && (iVar1 == -1)) {
      if (DAT_0070f630 == 0) goto LAB_0063ef43;
      DAT_0070f630 = DAT_0070f630 + -1;
    }
    if (piVar5[0xc] == param_1) {
LAB_0063ef5d:
      iVar1 = iVar4 + 2;
    }
    else if ((piVar5[0xc] == 0) && (iVar1 == -1)) {
      if (DAT_0070f630 == 0) goto LAB_0063ef5d;
      DAT_0070f630 = DAT_0070f630 + -1;
    }
    if (piVar5[0x10] == param_1) {
LAB_0063ef77:
      iVar1 = iVar4 + 3;
    }
    else if ((piVar5[0x10] == 0) && (iVar1 == -1)) {
      if (DAT_0070f630 == 0) goto LAB_0063ef77;
      DAT_0070f630 = DAT_0070f630 + -1;
    }
    if (piVar5[0x14] == param_1) {
LAB_0063ef91:
      iVar1 = iVar4 + 4;
    }
    else if ((piVar5[0x14] == 0) && (iVar1 == -1)) {
      if (DAT_0070f630 == 0) goto LAB_0063ef91;
      DAT_0070f630 = DAT_0070f630 + -1;
    }
    if (piVar5[0x18] == param_1) {
LAB_0063efab:
      iVar1 = iVar4 + 5;
    }
    else if ((piVar5[0x18] == 0) && (iVar1 == -1)) {
      if (DAT_0070f630 == 0) goto LAB_0063efab;
      DAT_0070f630 = DAT_0070f630 + -1;
    }
    iVar2 = iVar4 + 6;
    piVar5 = piVar5 + 0x20;
    iVar4 = iVar4 + 8;
    if (0xf < iVar2) {
      DAT_0070f630 = iVar3;
      if (iVar1 == -1) {
        Log_Printf("SYNCTASK_add - LIST FULL\n");
        DAT_0070f630 = DAT_0070f630 + -1;
        return;
      }
      param_3 = DAT_0070fe28 + param_3;
      (&DAT_0070f530)[iVar1 * 4] = param_1;
      (&DAT_0070f534)[iVar1 * 4] = param_2;
      (&DAT_0070f538)[iVar1 * 4] = param_3;
      (&DAT_0070f53c)[iVar1 * 4] = 0;
      DAT_0070f630 = DAT_0070f630 + -1;
      return;
    }
  } while( true );
}


// ==== 0x63f020 FUN_0063f020

void FUN_0063f020(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_0070f540;
  do {
    if (piVar1[-4] == param_1) {
LAB_0063f086:
      if ((iVar2 < 0x10) && ((&DAT_0070f530)[iVar2 * 4] == param_1)) {
        (&DAT_0070f530)[iVar2 * 4] = 0;
      }
      return;
    }
    if (*piVar1 == param_1) {
      iVar2 = iVar2 + 1;
      goto LAB_0063f086;
    }
    if (piVar1[4] == param_1) {
      iVar2 = iVar2 + 2;
      goto LAB_0063f086;
    }
    if (piVar1[8] == param_1) {
      iVar2 = iVar2 + 3;
      goto LAB_0063f086;
    }
    if (piVar1[0xc] == param_1) {
      iVar2 = iVar2 + 4;
      goto LAB_0063f086;
    }
    if (piVar1[0x10] == param_1) {
      iVar2 = iVar2 + 5;
      goto LAB_0063f086;
    }
    if (piVar1[0x14] == param_1) {
      iVar2 = iVar2 + 6;
      goto LAB_0063f086;
    }
    if (piVar1[0x18] == param_1) {
      iVar2 = iVar2 + 7;
      goto LAB_0063f086;
    }
    piVar1 = piVar1 + 0x20;
    iVar2 = iVar2 + 8;
    if (0x70f63f < (int)piVar1) {
      return;
    }
  } while( true );
}


// ==== 0x63f0a0 FUN_0063f0a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0063f0a0(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  uVar4 = 0;
  _DAT_0070f634 = DAT_0070fe28;
  piVar3 = &DAT_0070f538;
  do {
    if ((((code *)piVar3[-2] != (code *)0x0) && (*piVar3 <= DAT_0070fe28)) && (piVar3[1] == 0)) {
      iVar2 = DAT_0070fe28 - *piVar3;
      piVar3[1] = 1;
      uVar1 = (*(code *)piVar3[-2])(param_1,iVar2);
      uVar4 = uVar4 | uVar1;
      *piVar3 = DAT_0070fe28 + piVar3[-1];
      piVar3[1] = 0;
    }
    piVar3 = piVar3 + 4;
  } while ((int)piVar3 < 0x70f638);
  return uVar4;
}


// ==== 0x63f150 CriticalSection::Init

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

uint CriticalSection__Init(int param_1)

{
  uint extraout_EAX;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return extraout_EAX & 0xffffff00;
}


// ==== 0x63f170 FUN_0063f170

void FUN_0063f170(undefined4 *param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  *param_1 = 0x6d757446;
  return;
}


// ==== 0x63f190 CriticalSection::Enter

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void CriticalSection__Enter(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}


// ==== 0x63f1a0 CriticalSection::Leave

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void CriticalSection__Leave(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}


// ==== 0x63f1b0 FUN_0063f1b0

void FUN_0063f1b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (DAT_0070fddc != 0) {
    FUN_00643550(param_1,param_2,param_3);
    return;
  }
  if (DAT_0070fde0 != 0) {
    FUN_00643440();
    return;
  }
  if (DAT_0070fdd8 != 0) {
    FUN_00643350(param_1,param_2,param_3);
    return;
  }
  FUN_00643250();
  return;
}


// ==== 0x63f210 FUN_0063f210

void FUN_0063f210(undefined4 param_1,undefined4 param_2)

{
  if (DAT_0070fde0 != 0) {
    FUN_00643910(param_1,0,param_2);
    return;
  }
  if (DAT_0070fddc != 0) {
    FUN_00643860(param_1,0,param_2);
    return;
  }
  if (DAT_0070fdd8 != 0) {
    FUN_006437b0(param_1,0,param_2);
    return;
  }
  FUN_006436f0(param_1,0,param_2);
  return;
}


// ==== 0x63f2a0 FUN_0063f2a0

undefined4 FUN_0063f2a0(void)

{
  LSTATUS LVar1;
  undefined4 local_10;
  HKEY local_c;
  DWORD local_8 [2];
  
  local_10 = 0;
  local_8[1] = 4;
  LVar1 = RegOpenKeyA((HKEY)0x80000002,"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",&local_c
                     );
  if (LVar1 == 0) {
    local_8[0] = 4;
    RegQueryValueExA(local_c,"~MHz",(LPDWORD)0x0,local_8 + 1,(LPBYTE)&local_10,local_8);
    RegCloseKey(local_c);
  }
  return local_10;
}


// ==== 0x63f340 FUN_0063f340

void FUN_0063f340(uint param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  LARGE_INTEGER local_10;
  int local_4;
  
  local_4 = 0;
  local_10.s.LowPart = 0;
  iVar4 = 1000000;
  QueryPerformanceCounter(&local_10);
  uVar2 = local_10.s.HighPart;
  uVar1 = local_10.s.LowPart;
  do {
    local_10.s.LowPart = 0;
    QueryPerformanceCounter(&local_10);
    if ((local_10.s.LowPart == uVar1) && (local_10.s.HighPart == uVar2)) {
      bVar5 = iVar4 != 0;
      iVar4 = iVar4 + -1;
      local_4 = local_4 + -1 + (uint)bVar5;
      if (iVar4 == 0 && local_4 == 0) {
        return;
      }
    }
    uVar3 = (local_10.s.HighPart - uVar2) - (uint)(local_10.s.LowPart < (uint)uVar1);
  } while ((uVar3 < param_2) || ((uVar3 <= param_2 && (local_10.s.LowPart - uVar1 < param_1))));
  return;
}


// ==== 0x63f3f0 FUN_0063f3f0

undefined8 FUN_0063f3f0(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  LARGE_INTEGER local_8;
  
  QueryPerformanceFrequency(&local_8);
  iVar8 = 0;
  local_8.QuadPart = (LONGLONG)__aulldiv(local_8.s.LowPart,local_8.s.HighPart,5,0);
  uVar5 = 0;
  uVar7 = 0;
  do {
    FUN_0063f340(1,0);
    uVar1 = rdtsc();
    FUN_0063f340(local_8.s);
    uVar2 = rdtsc();
    uVar3 = (int)uVar2 - (int)uVar1;
    uVar6 = uVar5;
    uVar4 = uVar7;
    if ((((iVar8 != 0) && (uVar6 = uVar7, uVar4 = uVar3, uVar7 <= uVar3)) && (uVar7 != 0)) &&
       ((uVar3 < uVar5 || (uVar6 = uVar5, uVar4 = uVar7, uVar5 == 0)))) {
      uVar6 = uVar3;
      uVar4 = uVar7;
    }
    iVar8 = iVar8 + 1;
    uVar5 = uVar6;
    uVar7 = uVar4;
  } while (iVar8 < 5);
  if (uVar6 != 0) {
    uVar4 = uVar6;
  }
  return CONCAT44((int)((ulonglong)uVar2 >> 0x20),uVar4);
}


// ==== 0x63f7c0 FUN_0063f7c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0063f7c0(void)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  bool bVar8;
  uint local_cc;
  uint local_c8;
  uint local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  _SYSTEM_INFO local_b8;
  _OSVERSIONINFOA local_94;
  
  lVar2 = CONCAT44(DAT_0070f6bc,DAT_0070f6b8);
  if (DAT_0070f6b0 == '\0') {
    DAT_0070fde4 = 0;
    DAT_0070fde0 = 0;
    DAT_0070fdf4 = 0;
    DAT_0070fdd8 = 0;
    DAT_006e769c = 0;
    DAT_0070fdd4 = 0;
    DAT_0070fdd0 = 0;
    DAT_0070fdcc = 0;
    DAT_0070fddc = 0;
    DAT_0070fde8 = 0;
    DAT_006e76a4 = 0;
    DAT_006e76a0 = 0;
    DAT_0070fdf8 = 0;
    DAT_0070fdec = 0;
    DAT_0070fdf0 = 0;
    DAT_006e76a8 = 0;
    _DAT_0070f638 = _DAT_0070f638 & 0xffffff00;
    iVar3 = FUN_00643a00();
    if (iVar3 == 0) {
      DAT_0070fdf0 = FUN_00643a39();
    }
    else {
      GetSystemInfo(&local_b8);
      DAT_006e769c = local_b8.dwNumberOfProcessors;
      local_bc = 0;
      FUN_00643a1b(&local_cc,0);
      uVar5 = local_cc;
      _DAT_0070f638 = local_c8;
      _DAT_0070f63c = local_c4;
      _DAT_0070f640 = local_c0;
      DAT_0070f644 = 0;
      if (0 < (int)local_cc) {
        iVar3 = 0xd;
        bVar8 = true;
        pcVar4 = &DAT_0070f638;
        pcVar7 = "GenuineIntel";
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar8 = *pcVar4 == *pcVar7;
          pcVar4 = pcVar4 + 1;
          pcVar7 = pcVar7 + 1;
        } while (bVar8);
        if (bVar8) {
          DAT_006e76a8 = 1;
        }
        else {
          iVar3 = 0xd;
          bVar8 = true;
          pcVar4 = &DAT_0070f638;
          pcVar7 = "AuthenticAMD";
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar8 = *pcVar4 == *pcVar7;
            pcVar4 = pcVar4 + 1;
            pcVar7 = pcVar7 + 1;
          } while (bVar8);
          if (bVar8) {
            DAT_0070fdec = 1;
          }
          else {
            iVar3 = 0xd;
            bVar8 = true;
            pcVar4 = &DAT_0070f638;
            pcVar7 = "CyrixInstead";
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar8 = *pcVar4 == *pcVar7;
              pcVar4 = pcVar4 + 1;
              pcVar7 = pcVar7 + 1;
            } while (bVar8);
            if (bVar8) {
              DAT_0070fdf0 = 1;
            }
            else {
              iVar3 = 0xd;
              bVar8 = true;
              pcVar4 = &DAT_0070f638;
              pcVar7 = "CentaurHauls";
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar8 = *pcVar4 == *pcVar7;
                pcVar4 = pcVar4 + 1;
                pcVar7 = pcVar7 + 1;
              } while (bVar8);
              if (bVar8) {
                DAT_0070fdf8 = 1;
              }
            }
          }
        }
        FUN_00643a1b(&local_cc,1);
        DAT_0070fdcc = (int)local_cc >> 8 & 0xf;
        DAT_0070fdd0 = (int)local_cc >> 4 & 0xf;
        DAT_0070fdd4 = local_cc & 0xf;
        if (5 < DAT_0070fdcc) {
          DAT_006e76a0 = 1;
        }
        FUN_00643a1b(&local_cc,0x80000000);
        if ((DAT_0070fdec != 0) && (0x80000000 < local_cc)) {
          FUN_00643a1b(&local_cc,0x80000001);
          DAT_0070fdf4 = local_c4 >> 0x1f;
          DAT_0070fddc = local_c4 >> 0x16 & 1;
        }
        FUN_00643a1b(&local_cc,1);
        DAT_0070fde4 = local_c4 >> 0x1a & 1;
        DAT_0070fdd8 = local_c4 >> 0x17 & 1;
        DAT_0070fde0 = local_c4 >> 0x19 & 1;
        DAT_006e76a4 = local_c4 >> 4 & 1;
        DAT_0070fde8 = local_c4 >> 0xf & 1;
        if (DAT_0070fde0 != 0) {
          DAT_0070fddc = 1;
        }
        pcVar4 = _getenv("ISMMX");
        if (pcVar4 != (char *)0x0) {
          DAT_0070fdd8 = _atoi(pcVar4);
        }
        pcVar4 = _getenv("ISK3D");
        if (pcVar4 != (char *)0x0) {
          DAT_0070fdf4 = _atoi(pcVar4);
        }
        local_94.dwOSVersionInfoSize = 0x94;
        GetVersionExA(&local_94);
        if ((local_94.dwPlatformId == 1) && (local_94.dwMinorVersion == 0)) {
          DAT_0070fde4 = 0;
          DAT_0070fde0 = 0;
        }
        pcVar4 = _getenv("ISSSE");
        if (pcVar4 != (char *)0x0) {
          DAT_0070fde0 = _atoi(pcVar4);
        }
        pcVar4 = _getenv("ISSSE2");
        if (pcVar4 != (char *)0x0) {
          DAT_0070fde4 = _atoi(pcVar4);
        }
        pcVar4 = _getenv("ISMOVNT");
        if (pcVar4 != (char *)0x0) {
          DAT_0070fddc = _atoi(pcVar4);
        }
        if (1 < (int)uVar5) {
          FUN_00643a1b(&local_cc,2);
        }
      }
    }
    uVar5 = FUN_0063f2a0();
    uVar6 = 1000000;
    if (uVar5 == 0) {
      uVar5 = FUN_0063f3f0();
      uVar6 = 5;
    }
    lVar2 = (ulonglong)uVar6 * (ulonglong)uVar5;
    DAT_0070f6b4 = (int)lVar2;
    if (((int)((ulonglong)lVar2 >> 0x20) != 0) || (DAT_0070f6b4 == -1)) {
      DAT_0070f6b4 = -1;
    }
    DAT_0070f6b0 = '\x01';
  }
  DAT_0070f6bc = (undefined4)((ulonglong)lVar2 >> 0x20);
  DAT_0070f6b8 = (undefined4)lVar2;
  if (DAT_0070f6b4 == 0) {
    FUN_0063f210(&DAT_0070f648,0x68);
    return DAT_0070f6b4;
  }
  _DAT_0070f648 = lVar2;
  pcVar4 = (char *)FUN_00643a60();
  pcVar7 = &DAT_0070f650;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar7 = cVar1;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  _DAT_0070f660 = DAT_006e769c;
  iVar3 = 0;
  do {
    pcVar4 = &DAT_0070f638 + iVar3;
    (&DAT_0070f664)[iVar3] = *pcVar4;
    iVar3 = iVar3 + 1;
  } while (*pcVar4 != '\0');
  _DAT_0070f674 = DAT_0070fdcc;
  _DAT_0070f678 = DAT_0070fdd0;
  _DAT_0070f67c = DAT_0070fdd4;
  _DAT_0070f680 = DAT_006e76a0;
  _DAT_0070f684 = DAT_006e76a8;
  _DAT_0070f688 = DAT_0070fdec;
  _DAT_0070f68c = DAT_0070fdf0;
  _DAT_0070f690 = DAT_0070fdf8;
  _DAT_0070f694 = DAT_006e76a4;
  _DAT_0070f698 = DAT_0070fde8;
  _DAT_0070f69c = DAT_0070fddc;
  _DAT_0070f6a0 = DAT_0070fdd8;
  _DAT_0070f6a4 = DAT_0070fde0;
  _DAT_0070f6a8 = DAT_0070fde4;
  _DAT_0070f6ac = DAT_0070fdf4;
  return DAT_0070f6b4;
}


// ==== 0x63fc80 FUN_0063fc80

undefined * FUN_0063fc80(void)

{
  return &DAT_0070f648;
}


// ==== 0x63fc90 FUN_0063fc90

undefined4 FUN_0063fc90(void)

{
  return DAT_0070fe24;
}


// ==== 0x63fd90 FUN_0063fd90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063fd90(void)

{
  _DAT_0070fdb8 = _DAT_0070fdb8 + 1;
  return;
}


// ==== 0x63fe60 FUN_0063fe60

int FUN_0063fe60(int *param_1,int *param_2)

{
  return *param_1 - *param_2;
}


// ==== 0x640000 FUN_00640000

undefined4 FUN_00640000(void)

{
  return 0;
}


// ==== 0x64002c FUN_0064002c

undefined4 FUN_0064002c(void)

{
  byte *in_EAX;
  
  *in_EAX = *in_EAX | (byte)in_EAX;
  FUN_0063f020(FUN_00640030);
  FUN_00642540();
  return 0;
}


// ==== 0x640030 FUN_00640030

undefined4 FUN_00640030(void)

{
  FUN_0063f020(FUN_00640030);
  FUN_00642540();
  return 0;
}


// ==== 0x640049 FUN_00640049

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00640049(undefined2 param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = _DAT_0070f70c;
  CriticalSection__Enter(0x70f6d4);
  *(undefined2 *)(iVar1 * 4 + 0x70fc22) = param_1;
  *(undefined1 *)(iVar1 * 4 + 0x70fc20) = param_2;
  _DAT_0070f70c = (_DAT_0070f70c + 1) % _DAT_0070f700;
  if (_DAT_0070fd64 == _DAT_0070f70c) {
    _DAT_0070fd64 = (_DAT_0070fd64 + 1) % _DAT_0070f700;
  }
  CriticalSection__Leave(0x70f6d4);
  return;
}


// ==== 0x64004b FUN_0064004b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064004b(undefined2 param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = _DAT_0070f70c;
  CriticalSection__Enter(0x70f6d4);
  *(undefined2 *)(iVar1 * 4 + 0x70fc22) = param_1;
  *(undefined1 *)(iVar1 * 4 + 0x70fc20) = param_2;
  _DAT_0070f70c = (_DAT_0070f70c + 1) % _DAT_0070f700;
  if (_DAT_0070fd64 == _DAT_0070f70c) {
    _DAT_0070fd64 = (_DAT_0070fd64 + 1) % _DAT_0070f700;
  }
  CriticalSection__Leave(0x70f6d4);
  return;
}


// ==== 0x640063 FUN_00640063

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00640063(void)

{
  ushort in_AX;
  int unaff_ESI;
  undefined4 uStack00000005;
  undefined4 in_stack_00000010;
  
  *(ushort *)(unaff_ESI * 4 + 0x70fc22) = in_AX & 0xff0c;
  *(undefined1 *)(unaff_ESI * 4 + 0x70fc20) = in_stack_00000010._1_1_;
  _DAT_0070f70c = (_DAT_0070f70c + 1) % _DAT_0070f700;
  if (_DAT_0070fd64 == _DAT_0070f70c) {
    _DAT_0070fd64 = (_DAT_0070fd64 + 1) % _DAT_0070f700;
  }
  uStack00000005 = 0x70f6d4;
  CriticalSection__Leave();
  return;
}


// ==== 0x640064 FUN_00640064

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00640064(void)

{
  ushort in_AX;
  int unaff_ESI;
  undefined4 uStack00000004;
  undefined1 in_stack_00000010;
  
  *(ushort *)(unaff_ESI * 4 + 0x70fc22) = in_AX & 0xff0c;
  *(undefined1 *)(unaff_ESI * 4 + 0x70fc20) = in_stack_00000010;
  _DAT_0070f70c = (_DAT_0070f70c + 1) % _DAT_0070f700;
  if (_DAT_0070fd64 == _DAT_0070f70c) {
    _DAT_0070fd64 = (_DAT_0070fd64 + 1) % _DAT_0070f700;
  }
  uStack00000004 = 0x70f6d4;
  CriticalSection__Leave();
  return;
}


// ==== 0x64006a FUN_0064006a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0064006a(undefined1 param_1)

{
  undefined2 in_AX;
  int unaff_ESI;
  undefined4 uStack00000004;
  
  *(undefined2 *)(unaff_ESI * 4 + 0x70fc22) = in_AX;
  *(undefined1 *)(unaff_ESI * 4 + 0x70fc20) = param_1;
  _DAT_0070f70c = (_DAT_0070f70c + 1) % _DAT_0070f700;
  if (_DAT_0070fd64 == _DAT_0070f70c) {
    _DAT_0070fd64 = (_DAT_0070fd64 + 1) % _DAT_0070f700;
  }
  uStack00000004 = 0x70f6d4;
  CriticalSection__Leave();
  return;
}


// ==== 0x64006b FUN_0064006b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0064006b(undefined1 param_1)

{
  undefined4 in_EAX;
  int unaff_ESI;
  undefined4 uStack00000004;
  
  *(undefined4 *)(unaff_ESI * 4 + 0x70fc22) = in_EAX;
  *(undefined1 *)(unaff_ESI * 4 + 0x70fc20) = param_1;
  _DAT_0070f70c = (_DAT_0070f70c + 1) % _DAT_0070f700;
  if (_DAT_0070fd64 == _DAT_0070f70c) {
    _DAT_0070fd64 = (_DAT_0070fd64 + 1) % _DAT_0070f700;
  }
  uStack00000004 = 0x70f6d4;
  CriticalSection__Leave();
  return;
}


// ==== 0x64010a FUN_0064010a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall FUN_0064010a(undefined4 param_1,int param_2)

{
  int iVar1;
  uint in_EAX;
  int unaff_EDI;
  
  _DAT_0070fd64 = param_2;
  while ((_DAT_0070fd64 = (_DAT_0070fd64 + 1) % _DAT_0070f700, _DAT_0070fd64 != _DAT_0070f70c &&
         (in_EAX == 0))) {
    iVar1 = *(int *)(_DAT_0070fd64 * 4 + 0x70fc20);
    in_EAX = iVar1 >> 0x10;
    unaff_EDI = (int)(char)iVar1;
    if (in_EAX == 0) {
      in_EAX = FUN_00683ed0();
    }
  }
  CriticalSection__Leave();
  return unaff_EDI << 0x10 | in_EAX;
}


// ==== 0x6401d0 FUN_006401d0

undefined4 FUN_006401d0(undefined4 param_1)

{
  int in_EAX;
  
  if ((in_EAX == 0x104) || (in_EAX == 0x100)) {
    switch(param_1) {
    case 0x21:
    case 0x69:
      return 0x4900;
    case 0x22:
    case 99:
      return 0x5100;
    case 0x23:
    case 0x61:
      return 0x4f00;
    case 0x24:
    case 0x67:
      return 0x4700;
    case 0x25:
    case 100:
      return 0x4b00;
    case 0x26:
    case 0x68:
      return 0x4800;
    case 0x27:
    case 0x66:
      return 0x4d00;
    case 0x28:
    case 0x62:
      return 0x5000;
    case 0x2d:
    case 0x60:
      return 0x5200;
    case 0x2e:
      return 0x5300;
    case 0x65:
      return 0x4c00;
    case 0x70:
      return 0x3b00;
    case 0x71:
      return 0x3c00;
    case 0x72:
      return 0x3d00;
    case 0x73:
      return 0x3e00;
    case 0x74:
      return 0x3f00;
    case 0x75:
      return 0x4000;
    case 0x76:
      return 0x4100;
    case 0x77:
      return 0x4200;
    case 0x78:
      return 0x4300;
    case 0x79:
      return 0x4400;
    case 0x7a:
      return 0x8700;
    case 0x7b:
      return 0x8800;
    }
  }
  return 0;
}


// ==== 0x640a10 FUN_00640a10

undefined4 FUN_00640a10(int param_1,HWND param_2)

{
  undefined4 *in_stack_00000018;
  tagPAINTSTRUCT tStack_40;
  
  if (((param_1 != 0) && (DAT_0070fcc8 == param_2)) && (param_2 != (HWND)0x0)) {
    if (*(int *)(param_1 + 0x14) != 0) {
      SetForegroundWindow(param_2);
    }
    (*(code *)PTR_FUN_006e80b0)(1);
    BeginPaint(*(HWND *)(param_1 + 0xc),&tStack_40);
    EndPaint(*(HWND *)(param_1 + 0xc),&tStack_40);
    (*(code *)PTR_FUN_006e80b0)(0);
    if ((PTR_FUN_006e7698 != (undefined *)0x0) && (*(int *)(param_1 + 0x14) == 0)) {
      (*(code *)PTR_FUN_006e7698)();
    }
    *in_stack_00000018 = 1;
  }
  return 1;
}


// ==== 0x640af0 FUN_00640af0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00640af0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 in_EAX;
  undefined3 uVar3;
  void *pvVar1;
  int iVar2;
  undefined3 extraout_var;
  char cVar4;
  undefined4 auStack_8 [2];
  
  uVar3 = (undefined3)((uint)in_EAX >> 8);
  cVar4 = '\0';
  if (DAT_006e768c != '\0') {
    CriticalSection__Enter(&DAT_0070fca0);
    auStack_8[0] = param_2;
    pvVar1 = _bsearch(auStack_8,(void *)0x70f710,_DAT_0070fd70,8,FUN_0063fe60);
    if (pvVar1 != (void *)0x0) {
      iVar2 = (**(code **)((int)pvVar1 + 4))(&DAT_0070fcbc,param_1,param_2,param_3,param_4,param_5);
      cVar4 = '\x01' - (iVar2 != 1);
    }
    CriticalSection__Leave(&DAT_0070fca0);
    uVar3 = extraout_var;
  }
  return CONCAT31(uVar3,cVar4);
}


// ==== 0x640bc0 FUN_00640bc0

HWND FUN_00640bc0(void)

{
  int nWidth;
  int nHeight;
  HWND pHVar1;
  uint uVar2;
  DWORD dwExStyle;
  int *unaff_ESI;
  tagRECT local_10;
  
  uVar2 = DAT_006e7690;
  if (unaff_ESI[5] == 0) {
    uVar2 = DAT_006e7690 | 0xca0000;
    dwExStyle = 0x40100;
    if ((DAT_006e7690 & 0x10000) != 0) {
      dwExStyle = 0x40000;
    }
    if (unaff_ESI[3] == 0) {
      local_10.top = -0x2000;
      local_10.left = -0x2000;
    }
    else {
      local_10.top = unaff_ESI[7];
      local_10.left = unaff_ESI[6];
    }
    local_10.bottom = unaff_ESI[1] + local_10.top;
    local_10.right = *unaff_ESI + local_10.left;
    AdjustWindowRectEx(&local_10,uVar2,0,dwExStyle);
    unaff_ESI[6] = local_10.left;
    nWidth = local_10.right - local_10.left;
    unaff_ESI[7] = local_10.top;
    nHeight = local_10.bottom - local_10.top;
  }
  else {
    unaff_ESI[6] = 0;
    unaff_ESI[7] = 0;
    nWidth = GetSystemMetrics(0);
    nHeight = GetSystemMetrics(1);
    uVar2 = uVar2 | 0x80000000;
    dwExStyle = 8;
  }
  pHVar1 = CreateWindowExA(dwExStyle,DAT_0070fdb0,DAT_0070fdb0,uVar2 | 0x2000000,unaff_ESI[6],
                           unaff_ESI[7],nWidth,nHeight,(HWND)0x0,(HMENU)0x0,DAT_0070fdb4,(LPVOID)0x0
                          );
  if (pHVar1 != (HWND)0x0) {
    SetCursor((HCURSOR)0x0);
    if (unaff_ESI[5] != 0) {
      ShowCursor(0);
    }
    if (DAT_0070fda8 == 0) {
      FUN_00643b60(0,0);
      FUN_00643b60(1,0);
      FUN_00643b60(2,0);
    }
  }
  return pHVar1;
}


