// ==== 0x661120 FUN_00661120

void FUN_00661120(undefined4 *param_1,byte param_2,int param_3)

{
  param_1[1] = 0;
  param_1[8] = 0;
  *(undefined2 *)(param_1 + 10) = 0;
  *(undefined2 *)((int)param_1 + 0x2a) = 0;
  *param_1 = FUN_00660f10;
  if (param_3 != 0) {
    *(undefined2 *)((int)param_1 + 0x2a) = 1;
    if ((param_2 & 2) != 0) {
      param_1[9] = FUN_00661cc0;
      param_1[0xb] = 0;
      param_1[0xc] = 0;
      param_1[0xd] = 0;
      param_1[0xe] = 0;
      return;
    }
    if ((param_2 & 4) != 0) {
      param_1[9] = FUN_00661ac0;
      param_1[0xb] = 0;
      param_1[0xc] = 0;
      param_1[0xd] = 0;
      param_1[0xe] = 0;
      return;
    }
    param_1[9] = FUN_00661780;
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    return;
  }
  if ((param_2 & 2) != 0) {
    param_1[9] = FUN_00662130;
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    return;
  }
  if ((param_2 & 4) != 0) {
    param_1[9] = FUN_00662030;
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    return;
  }
  param_1[9] = FUN_00661f60;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  return;
}


// ==== 0x6611f0 FUN_006611f0

void FUN_006611f0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  return;
}


// ==== 0x661210 FUN_00661210

void FUN_00661210(float *param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  if (3 < param_2) {
    iVar5 = 3;
    pfVar2 = (float *)(param_3 + 4);
    pfVar3 = (float *)(param_4 + 0xc);
    do {
      pfVar3[-3] = param_1[3] * param_1[0xc] +
                   (*param_1 + param_1[6]) * param_1[9] +
                   (param_1[4] + param_1[2]) * param_1[0xb] +
                   (param_1[5] + param_1[1]) * param_1[10] + (pfVar2[-1] + param_1[7]) * param_1[8];
      param_1[7] = param_1[6];
      param_1[6] = param_1[5];
      param_1[5] = param_1[4];
      param_1[4] = param_1[3];
      param_1[3] = param_1[2];
      param_1[2] = param_1[1];
      param_1[1] = *param_1;
      fVar1 = pfVar2[-1];
      *param_1 = fVar1;
      *(float *)((int)pfVar2 + (param_4 - param_3)) =
           param_1[3] * param_1[0xc] +
           (param_1[4] + param_1[2]) * param_1[0xb] +
           (param_1[5] + param_1[1]) * param_1[10] +
           (*pfVar2 + param_1[7]) * param_1[8] + (fVar1 + param_1[6]) * param_1[9];
      param_1[7] = param_1[6];
      param_1[6] = param_1[5];
      param_1[5] = param_1[4];
      param_1[4] = param_1[3];
      param_1[3] = param_1[2];
      param_1[2] = param_1[1];
      param_1[1] = *param_1;
      fVar1 = *pfVar2;
      *param_1 = fVar1;
      iVar5 = iVar5 + 4;
      iVar4 = iVar4 + 4;
      pfVar3[-1] = param_1[3] * param_1[0xc] +
                   (param_1[4] + param_1[2]) * param_1[0xb] +
                   (param_1[5] + param_1[1]) * param_1[10] +
                   (pfVar2[1] + param_1[7]) * param_1[8] + (fVar1 + param_1[6]) * param_1[9];
      param_1[7] = param_1[6];
      param_1[6] = param_1[5];
      param_1[5] = param_1[4];
      param_1[4] = param_1[3];
      param_1[3] = param_1[2];
      param_1[2] = param_1[1];
      param_1[1] = *param_1;
      fVar1 = pfVar2[1];
      *param_1 = fVar1;
      *pfVar3 = param_1[3] * param_1[0xc] +
                (param_1[4] + param_1[2]) * param_1[0xb] +
                (param_1[5] + param_1[1]) * param_1[10] +
                (pfVar2[2] + param_1[7]) * param_1[8] + (fVar1 + param_1[6]) * param_1[9];
      param_1[7] = param_1[6];
      param_1[6] = param_1[5];
      param_1[5] = param_1[4];
      param_1[4] = param_1[3];
      param_1[3] = param_1[2];
      param_1[2] = param_1[1];
      param_1[1] = *param_1;
      *param_1 = pfVar2[2];
      pfVar2 = pfVar2 + 4;
      pfVar3 = pfVar3 + 4;
    } while (iVar5 < param_2);
  }
  if (iVar4 < param_2) {
    param_2 = param_2 - iVar4;
    pfVar2 = (float *)(param_3 + iVar4 * 4);
    do {
      param_2 = param_2 + -1;
      *(float *)((int)pfVar2 + (param_4 - param_3)) =
           param_1[3] * param_1[0xc] +
           (*param_1 + param_1[6]) * param_1[9] +
           (param_1[4] + param_1[2]) * param_1[0xb] +
           (param_1[5] + param_1[1]) * param_1[10] + (param_1[7] + *pfVar2) * param_1[8];
      param_1[7] = param_1[6];
      param_1[6] = param_1[5];
      param_1[5] = param_1[4];
      param_1[4] = param_1[3];
      param_1[3] = param_1[2];
      param_1[2] = param_1[1];
      param_1[1] = *param_1;
      *param_1 = *pfVar2;
      pfVar2 = pfVar2 + 1;
    } while (param_2 != 0);
  }
  return;
}


// ==== 0x661460 FUN_00661460

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00661460(int param_1,int param_2)

{
  float fVar1;
  uint uVar2;
  float *pfVar3;
  float *pfVar4;
  bool bVar5;
  float10 fVar6;
  float10 fVar7;
  uint local_8;
  float local_4;
  
  if (((param_2 == 3) || (param_2 == 4)) && (0.8 < *(float *)(param_1 + 0x34))) {
    *(undefined4 *)(param_1 + 0x34) = 0x3f4ccccd;
  }
  if (param_2 == 2) {
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x38);
    local_8 = 1;
    pfVar3 = (float *)(param_1 + 0x2c);
    do {
      fVar1 = (float)(int)local_8;
      fVar6 = (float10)SNDI_sin(fVar1 * 3.1415927 * *(float *)(param_1 + 0x38));
      local_8 = local_8 + 1;
      *pfVar3 = (float)(fVar6 / (float10)(fVar1 * 3.1415927));
      pfVar3 = pfVar3 + -1;
    } while ((int)local_8 < 5);
  }
  else if (param_2 == 3) {
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x34);
    local_8 = 1;
    pfVar3 = (float *)(param_1 + 0x2c);
    do {
      fVar1 = (float)(int)local_8;
      fVar6 = (float10)SNDI_sin(fVar1 * 3.1415927 * *(float *)(param_1 + 0x34));
      local_8 = local_8 + 1;
      *pfVar3 = (float)(fVar6 / (float10)(fVar1 * 3.1415927));
      pfVar3 = pfVar3 + -1;
    } while ((int)local_8 < 5);
  }
  else if (param_2 == 4) {
    local_8 = 1;
    *(float *)(param_1 + 0x30) = *(float *)(param_1 + 0x38) - *(float *)(param_1 + 0x34);
    pfVar3 = (float *)(param_1 + 0x2c);
    do {
      fVar1 = (float)(int)local_8 * 3.1415927;
      fVar6 = (float10)SNDI_sin((*(float *)(param_1 + 0x38) - *(float *)(param_1 + 0x34)) * fVar1 *
                                _K_HALF);
      fVar7 = (float10)FUN_006590b0((*(float *)(param_1 + 0x38) + *(float *)(param_1 + 0x34)) *
                                    fVar1 * _K_HALF);
      fVar7 = fVar7 * (float10)(float)(fVar6 / (float10)fVar1);
      local_8 = local_8 + 1;
      *pfVar3 = (float)(fVar7 + fVar7);
      pfVar3 = pfVar3 + -1;
    } while ((int)local_8 < 5);
  }
  pfVar3 = (float *)(param_1 + 0x20);
  local_4 = 0.0;
  local_8 = 0;
  pfVar4 = pfVar3;
  do {
    if ((param_2 == 2) || (param_2 == 4)) {
      fVar6 = (float10)FUN_006590b0((float)(int)local_8 * 0.7853982);
      fVar6 = ((float10)0.54 - fVar6 * (float10)0.46) * (float10)*pfVar4;
      *pfVar4 = (float)fVar6;
LAB_00661656:
      fVar6 = fVar6 + (float10)local_4;
LAB_0066165a:
      local_4 = (float)fVar6;
    }
    else if (param_2 == 3) {
      fVar6 = (float10)FUN_006590b0((float)(int)local_8 * 0.7853982);
      uVar2 = local_8 & 0x80000001;
      bVar5 = uVar2 == 0;
      fVar6 = -(((float10)0.54 - fVar6 * (float10)0.46) * (float10)*pfVar4);
      fVar1 = (float)fVar6;
      *pfVar4 = (float)fVar6;
      if ((int)uVar2 < 0) {
        bVar5 = (uVar2 - 1 | 0xfffffffe) == 0xffffffff;
      }
      if (bVar5) {
        fVar6 = (float10)fVar1;
        goto LAB_00661656;
      }
      fVar6 = (float10)local_4 - (float10)fVar1;
      goto LAB_0066165a;
    }
    local_8 = local_8 + 1;
    pfVar4 = pfVar4 + 1;
    if (4 < (int)local_8) {
      if (param_2 == 3) {
        *(float *)(param_1 + 0x30) = *(float *)(param_1 + 0x30) + _K_ONE;
        local_4 = local_4 + _K_ONE;
      }
      fVar1 = (local_4 + local_4) - *(float *)(param_1 + 0x30);
      if (fVar1 < 0.0) {
        fVar1 = fVar1 * -1.0;
      }
      fVar1 = _K_ONE / fVar1;
      *pfVar3 = fVar1 * *pfVar3;
      *(float *)(param_1 + 0x24) = fVar1 * *(float *)(param_1 + 0x24);
      *(float *)(param_1 + 0x28) = fVar1 * *(float *)(param_1 + 0x28);
      *(float *)(param_1 + 0x2c) = fVar1 * *(float *)(param_1 + 0x2c);
      *(float *)(param_1 + 0x30) = fVar1 * *(float *)(param_1 + 0x30);
      return;
    }
  } while( true );
}


// ==== 0x6616e0 FUN_006616e0

int FUN_006616e0(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00662340(param_1,(int)(param_2 + (param_2 >> 0x1f & 0xfU)) >> 4);
  return iVar1 << 4;
}


// ==== 0x661700 FUN_00661700

void FUN_00661700(void)

{
  return;
}


// ==== 0x661780 FUN_00661780

void FUN_00661780(int param_1,int param_2,int param_3,int *param_4,uint *param_5,int param_6,
                 uint param_7)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  float fVar4;
  uint *puVar5;
  float *pfVar6;
  int iVar7;
  uint uVar8;
  
  puVar5 = param_5;
  uVar8 = param_6 << 0x10 | param_7 >> 0x10;
  iVar7 = 0;
  *param_5 = (uint)*(ushort *)((int)param_5 + 2);
  if (3 < param_1) {
    param_5 = (uint *)0x3;
    pfVar6 = (float *)(param_3 + 8);
    do {
      fVar4 = (float)(int)*puVar5;
      if ((int)*puVar5 < 0) {
        fVar4 = fVar4 + 4.2949673e+09;
      }
      fVar4 = fVar4 * 1.5258e-05;
      iVar2 = *param_4;
      fVar1 = *(float *)(param_2 + 4 + iVar2 * 4);
      pfVar6[-2] = (*(float *)(param_2 + 4 + iVar2 * 4) - *(float *)(param_2 + -4 + iVar2 * 4)) *
                   0.5 * fVar4 +
                   ((fVar1 + fVar1 + *(float *)(param_2 + -4 + iVar2 * 4)) -
                   (*(float *)(param_2 + iVar2 * 4) * 5.0 + *(float *)(param_2 + 8 + iVar2 * 4)) *
                   0.5) * fVar4 * fVar4 +
                   fVar4 * fVar4 * fVar4 *
                   (((*(float *)(param_2 + iVar2 * 4) - *(float *)(param_2 + 4 + iVar2 * 4)) * 3.0 -
                    *(float *)(param_2 + -4 + iVar2 * 4)) + *(float *)(param_2 + 8 + iVar2 * 4)) *
                   0.5 + *(float *)(param_2 + iVar2 * 4);
      uVar3 = *puVar5;
      *puVar5 = uVar3 + uVar8;
      *param_4 = *param_4 + (uVar3 + uVar8 >> 0x10);
      *(undefined2 *)((int)puVar5 + 2) = 0;
      fVar4 = (float)(int)*puVar5;
      if ((int)*puVar5 < 0) {
        fVar4 = fVar4 + 4.2949673e+09;
      }
      fVar4 = fVar4 * 1.5258e-05;
      iVar2 = *param_4;
      fVar1 = *(float *)(param_2 + 4 + iVar2 * 4);
      pfVar6[-1] = (*(float *)(param_2 + 4 + iVar2 * 4) - *(float *)(param_2 + -4 + iVar2 * 4)) *
                   0.5 * fVar4 +
                   ((fVar1 + fVar1 + *(float *)(param_2 + -4 + iVar2 * 4)) -
                   (*(float *)(param_2 + iVar2 * 4) * 5.0 + *(float *)(param_2 + 8 + iVar2 * 4)) *
                   0.5) * fVar4 * fVar4 +
                   fVar4 * fVar4 * fVar4 *
                   (((*(float *)(param_2 + iVar2 * 4) - *(float *)(param_2 + 4 + iVar2 * 4)) * 3.0 -
                    *(float *)(param_2 + -4 + iVar2 * 4)) + *(float *)(param_2 + 8 + iVar2 * 4)) *
                   0.5 + *(float *)(param_2 + iVar2 * 4);
      uVar3 = *puVar5;
      *puVar5 = uVar3 + uVar8;
      *param_4 = *param_4 + (uVar3 + uVar8 >> 0x10);
      *(undefined2 *)((int)puVar5 + 2) = 0;
      fVar4 = (float)(int)*puVar5;
      if ((int)*puVar5 < 0) {
        fVar4 = fVar4 + 4.2949673e+09;
      }
      fVar4 = fVar4 * 1.5258e-05;
      iVar2 = *param_4;
      fVar1 = *(float *)(param_2 + 4 + iVar2 * 4);
      *pfVar6 = (*(float *)(param_2 + 4 + iVar2 * 4) - *(float *)(param_2 + -4 + iVar2 * 4)) * 0.5 *
                fVar4 + ((fVar1 + fVar1 + *(float *)(param_2 + -4 + iVar2 * 4)) -
                        (*(float *)(param_2 + iVar2 * 4) * 5.0 + *(float *)(param_2 + 8 + iVar2 * 4)
                        ) * 0.5) * fVar4 * fVar4 +
                        fVar4 * fVar4 * fVar4 *
                        (((*(float *)(param_2 + iVar2 * 4) - *(float *)(param_2 + 4 + iVar2 * 4)) *
                          3.0 - *(float *)(param_2 + -4 + iVar2 * 4)) +
                        *(float *)(param_2 + 8 + iVar2 * 4)) * 0.5 + *(float *)(param_2 + iVar2 * 4)
      ;
      uVar3 = *puVar5;
      *puVar5 = uVar3 + uVar8;
      *param_4 = *param_4 + (uVar3 + uVar8 >> 0x10);
      *(undefined2 *)((int)puVar5 + 2) = 0;
      fVar4 = (float)(int)*puVar5;
      if ((int)*puVar5 < 0) {
        fVar4 = fVar4 + 4.2949673e+09;
      }
      fVar4 = fVar4 * 1.5258e-05;
      iVar2 = *param_4;
      iVar7 = iVar7 + 4;
      fVar1 = *(float *)(param_2 + 4 + iVar2 * 4);
      pfVar6[1] = (*(float *)(param_2 + 4 + iVar2 * 4) - *(float *)(param_2 + -4 + iVar2 * 4)) * 0.5
                  * fVar4 + ((fVar1 + fVar1 + *(float *)(param_2 + -4 + iVar2 * 4)) -
                            (*(float *)(param_2 + iVar2 * 4) * 5.0 +
                            *(float *)(param_2 + 8 + iVar2 * 4)) * 0.5) * fVar4 * fVar4 +
                            fVar4 * fVar4 * fVar4 *
                            (((*(float *)(param_2 + iVar2 * 4) - *(float *)(param_2 + 4 + iVar2 * 4)
                              ) * 3.0 - *(float *)(param_2 + -4 + iVar2 * 4)) +
                            *(float *)(param_2 + 8 + iVar2 * 4)) * 0.5 +
                  *(float *)(param_2 + iVar2 * 4);
      uVar3 = *puVar5;
      *puVar5 = uVar3 + uVar8;
      *param_4 = *param_4 + (uVar3 + uVar8 >> 0x10);
      param_5 = (uint *)((int)param_5 + 4);
      *(undefined2 *)((int)puVar5 + 2) = 0;
      pfVar6 = pfVar6 + 4;
    } while ((int)param_5 < param_1);
  }
  for (; iVar7 < param_1; iVar7 = iVar7 + 1) {
    fVar4 = (float)(int)*puVar5;
    if ((int)*puVar5 < 0) {
      fVar4 = fVar4 + 4.2949673e+09;
    }
    fVar4 = fVar4 * 1.5258e-05;
    iVar2 = *param_4;
    fVar1 = *(float *)(param_2 + 4 + iVar2 * 4);
    *(float *)(param_3 + iVar7 * 4) =
         (*(float *)(param_2 + 4 + iVar2 * 4) - *(float *)(param_2 + -4 + iVar2 * 4)) * 0.5 * fVar4
         + ((fVar1 + fVar1 + *(float *)(param_2 + -4 + iVar2 * 4)) -
           (*(float *)(param_2 + iVar2 * 4) * 5.0 + *(float *)(param_2 + 8 + iVar2 * 4)) * 0.5) *
           fVar4 * fVar4 +
           fVar4 * fVar4 * fVar4 *
           (((*(float *)(param_2 + iVar2 * 4) - *(float *)(param_2 + 4 + iVar2 * 4)) * 3.0 -
            *(float *)(param_2 + -4 + iVar2 * 4)) + *(float *)(param_2 + 8 + iVar2 * 4)) * 0.5 +
         *(float *)(param_2 + iVar2 * 4);
    uVar3 = *puVar5;
    *puVar5 = uVar3 + uVar8;
    *param_4 = *param_4 + (uVar3 + uVar8 >> 0x10);
    *(undefined2 *)((int)puVar5 + 2) = 0;
  }
  *puVar5 = *puVar5 << 0x10;
  return;
}


// ==== 0x661ac0 FUN_00661ac0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 __fastcall
FUN_00661ac0(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,undefined8 *param_5,
            int *param_6,uint *param_7,int param_8,uint param_9)

{
  undefined4 in_EAX;
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  
  uVar2 = *param_7;
  DAT_006eb04a._0_2_ = (undefined2)(uVar2 >> 0x10);
  iVar4 = *param_6;
  uVar1 = uVar2;
  while (1 < (int)param_3) {
    param_3 = param_3 - 2;
    uVar15 = PackedIntToFloatingDwordConv
                       ((ulonglong)CONCAT22(DAT_006eb04a._2_2_,(undefined2)DAT_006eb04a),
                        (ulonglong)CONCAT22(DAT_006eb04a._2_2_,(undefined2)DAT_006eb04a));
    uVar16 = PackedFloatingMUL(uVar15,_DAT_006eb040);
    uVar1 = uVar2 + param_9;
    iVar3 = iVar4 + param_8 + (uint)CARRY4(uVar2,param_9);
    DAT_006eb04a._0_2_ = (undefined2)(uVar1 >> 0x10);
    uVar15 = CONCAT44(*(undefined4 *)(param_4 + -4 + iVar3 * 4),
                      *(undefined4 *)(param_4 + -4 + iVar4 * 4));
    uVar13 = CONCAT44(*(undefined4 *)(param_4 + iVar3 * 4),*(undefined4 *)(param_4 + iVar4 * 4));
    uVar12 = CONCAT44(*(undefined4 *)(param_4 + 4 + iVar3 * 4),
                      *(undefined4 *)(param_4 + 4 + iVar4 * 4));
    uVar11 = CONCAT44(*(undefined4 *)(param_4 + 8 + iVar3 * 4),
                      *(undefined4 *)(param_4 + 8 + iVar4 * 4));
    uVar10 = PackedIntToFloatingDwordConv
                       ((ulonglong)CONCAT22(DAT_006eb04a._2_2_,(undefined2)DAT_006eb04a),
                        (ulonglong)CONCAT22(DAT_006eb04a._2_2_,(undefined2)DAT_006eb04a));
    uVar10 = PackedFloatingMUL(uVar10,_DAT_006eb040);
    uVar17 = CONCAT44((int)uVar10,(int)uVar16);
    uVar2 = uVar1 + param_9;
    iVar4 = iVar3 + param_8 + (uint)CARRY4(uVar1,param_9);
    _DAT_006eb048 = (undefined2)uVar2;
    DAT_006eb04a._0_2_ = (undefined2)(uVar2 >> 0x10);
    uVar16 = PackedFloatingMUL(CONCAT44(uRam006eb05c,DAT_006eb058),uVar12);
    uVar10 = PackedFloatingSUB(uVar13,uVar12);
    uVar16 = PackedFloatingADD(uVar16,uVar15);
    uVar10 = PackedFloatingMUL(uVar10,_DAT_006eb060);
    uVar10 = PackedFloatingSUB(uVar10,uVar15);
    uVar14 = PackedFloatingMUL(CONCAT44(uRam006eb06c,DAT_006eb068),uVar13);
    uVar10 = PackedFloatingADD(uVar10,uVar11);
    uVar14 = PackedFloatingADD(uVar14,uVar11);
    uVar11 = PackedFloatingMUL(uVar10,_DAT_006eb050);
    uVar10 = PackedFloatingMUL(uVar14,_DAT_006eb050);
    uVar10 = PackedFloatingSUB(uVar16,uVar10);
    uVar15 = PackedFloatingSUB(uVar12,uVar15);
    uVar15 = PackedFloatingMUL(uVar15,_DAT_006eb050);
    uVar16 = PackedFloatingMUL(uVar15,uVar17);
    uVar15 = PackedFloatingMUL(uVar17,uVar17);
    uVar12 = PackedFloatingMUL(uVar10,uVar15);
    uVar15 = PackedFloatingMUL(uVar15,uVar15);
    uVar15 = PackedFloatingMUL(uVar11,uVar15);
    uVar12 = PackedFloatingADD(uVar16,uVar12);
    uVar15 = PackedFloatingADD(uVar13,uVar15);
    uVar15 = PackedFloatingADD(uVar15,uVar12);
    *param_5 = uVar15;
    uVar1 = CONCAT22((undefined2)DAT_006eb04a,_DAT_006eb048);
    param_5 = param_5 + 1;
  }
  while( true ) {
    DAT_006eb04a._0_2_ = (undefined2)(uVar1 >> 0x10);
    _DAT_006eb048 = (undefined2)uVar1;
    if ((param_3 & 1) == 0) break;
    uVar6 = (ulonglong)*(uint *)(param_4 + -4 + iVar4 * 4);
    uVar7 = (ulonglong)*(uint *)(param_4 + iVar4 * 4);
    uVar8 = (ulonglong)*(uint *)(param_4 + 4 + iVar4 * 4);
    uVar9 = (ulonglong)*(uint *)(param_4 + 8 + iVar4 * 4);
    uVar15 = PackedIntToFloatingDwordConv
                       ((ulonglong)CONCAT22(DAT_006eb04a._2_2_,(undefined2)DAT_006eb04a),
                        (ulonglong)CONCAT22(DAT_006eb04a._2_2_,(undefined2)DAT_006eb04a));
    uVar11 = PackedFloatingMUL(uVar15,_DAT_006eb040);
    uVar15 = PackedFloatingSUB(uVar7,uVar8);
    uVar15 = PackedFloatingMUL(uVar15,_DAT_006eb060);
    uVar15 = PackedFloatingSUB(uVar15,uVar6);
    uVar15 = PackedFloatingADD(uVar15,uVar9);
    uVar15 = PackedFloatingMUL(uVar15,_DAT_006eb050);
    uVar13 = PackedFloatingMUL((ulonglong)DAT_006eb058,uVar8);
    uVar13 = PackedFloatingADD(uVar13,uVar6);
    uVar12 = PackedFloatingMUL((ulonglong)DAT_006eb068,uVar7);
    uVar12 = PackedFloatingADD(uVar12,uVar9);
    uVar12 = PackedFloatingMUL(uVar12,_DAT_006eb050);
    uVar13 = PackedFloatingSUB(uVar13,uVar12);
    uVar12 = PackedFloatingSUB(uVar8,uVar6);
    uVar12 = PackedFloatingMUL(uVar12,_DAT_006eb050);
    uVar12 = PackedFloatingMUL(uVar12,uVar11);
    uVar11 = PackedFloatingMUL(uVar11,uVar11);
    uVar13 = PackedFloatingMUL(uVar13,uVar11);
    uVar11 = PackedFloatingMUL(uVar11,uVar11);
    uVar15 = PackedFloatingMUL(uVar15,uVar11);
    uVar13 = PackedFloatingADD(uVar12,uVar13);
    uVar15 = PackedFloatingADD(uVar7,uVar15);
    uVar15 = PackedFloatingADD(uVar15,uVar13);
    bVar5 = CARRY4(uVar2,param_9);
    uVar2 = uVar2 + param_9;
    iVar4 = iVar4 + param_8 + (uint)bVar5;
    *(int *)param_5 = (int)uVar15;
    param_5 = (undefined8 *)((int)param_5 + 4);
    param_3 = param_3 - 1;
    uVar1 = uVar2;
  }
  FastExitMediaState();
  *param_7 = uVar2;
  *param_6 = iVar4;
  return CONCAT44(param_2,in_EAX);
}


// ==== 0x661cc0 FUN_00661cc0

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_00661cc0(uint param_1,int param_2,float *param_3,int *param_4,uint *param_5,int param_6,
            uint param_7)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
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
  int iStack_28;
  
  DAT_006eb110 = &iStack_28;
  uVar3 = *param_5;
  iVar4 = *param_4;
  for (; 3 < (int)param_1; param_1 = param_1 - 4) {
    DAT_006eb0c0._0_4_ = uVar3 >> 1;
    _DAT_006eb080 = *(float *)(param_2 + -4 + iVar4 * 4);
    _DAT_006eb090 = *(float *)(param_2 + iVar4 * 4);
    _DAT_006eb0a0 = *(float *)(param_2 + 4 + iVar4 * 4);
    _DAT_006eb0b0 = *(float *)(param_2 + 8 + iVar4 * 4);
    iVar4 = iVar4 + param_6 + (uint)CARRY4((uint)DAT_006eb0c0 * 2,param_7);
    DAT_006eb0c0._4_4_ = (uint)DAT_006eb0c0 * 2 + param_7 >> 1;
    _DAT_006eb084 = *(float *)(param_2 + -4 + iVar4 * 4);
    _DAT_006eb094 = *(float *)(param_2 + iVar4 * 4);
    _DAT_006eb0a4 = *(float *)(param_2 + 4 + iVar4 * 4);
    _DAT_006eb0b4 = *(float *)(param_2 + 8 + iVar4 * 4);
    iVar4 = iVar4 + param_6 + (uint)CARRY4(DAT_006eb0c0._4_4_ * 2,param_7);
    DAT_006eb0c8._0_4_ = DAT_006eb0c0._4_4_ * 2 + param_7 >> 1;
    _DAT_006eb088 = *(float *)(param_2 + -4 + iVar4 * 4);
    _DAT_006eb098 = *(float *)(param_2 + iVar4 * 4);
    _DAT_006eb0a8 = *(float *)(param_2 + 4 + iVar4 * 4);
    _DAT_006eb0b8 = *(float *)(param_2 + 8 + iVar4 * 4);
    iVar4 = iVar4 + param_6 + (uint)CARRY4((uint)DAT_006eb0c8 * 2,param_7);
    DAT_006eb0c8._4_4_ = (uint)DAT_006eb0c8 * 2 + param_7 >> 1;
    _DAT_006eb08c = *(float *)(param_2 + -4 + iVar4 * 4);
    _DAT_006eb09c = *(float *)(param_2 + iVar4 * 4);
    uVar3 = DAT_006eb0c8._4_4_ * 2 + param_7;
    _DAT_006eb0ac = *(float *)(param_2 + 4 + iVar4 * 4);
    _DAT_006eb0bc = *(float *)(param_2 + 8 + iVar4 * 4);
    iVar4 = iVar4 + param_6 + (uint)CARRY4(DAT_006eb0c8._4_4_ * 2,param_7);
    fVar17 = (float)(uint)DAT_006eb0c0 * _DAT_006eb070;
    fVar19 = (float)DAT_006eb0c0._4_4_ * fRam006eb074;
    fVar21 = (float)(uint)DAT_006eb0c8 * fRam006eb078;
    fVar23 = (float)DAT_006eb0c8._4_4_ * fRam006eb07c;
    fVar8 = fRam006eb0e4 * _DAT_006eb0a4 + _DAT_006eb084;
    fVar9 = fRam006eb0e8 * _DAT_006eb0a8 + _DAT_006eb088;
    fVar10 = fRam006eb0ec * _DAT_006eb0ac + _DAT_006eb08c;
    fVar11 = (fRam006eb104 * _DAT_006eb094 + _DAT_006eb0b4) * fRam006eb0d4;
    fVar13 = (fRam006eb108 * _DAT_006eb098 + _DAT_006eb0b8) * fRam006eb0d8;
    fVar15 = (fRam006eb10c * _DAT_006eb09c + _DAT_006eb0bc) * fRam006eb0dc;
    fVar12 = (_DAT_006eb0a4 - _DAT_006eb084) * fRam006eb0d4;
    fVar14 = (_DAT_006eb0a8 - _DAT_006eb088) * fRam006eb0d8;
    fVar16 = (_DAT_006eb0ac - _DAT_006eb08c) * fRam006eb0dc;
    fVar18 = fVar17 * fVar17;
    fVar20 = fVar19 * fVar19;
    fVar22 = fVar21 * fVar21;
    fVar24 = fVar23 * fVar23;
    fVar5 = _DAT_006eb094 +
            (((_DAT_006eb094 - _DAT_006eb0a4) * fRam006eb0f4 - _DAT_006eb084) + _DAT_006eb0b4) *
            fRam006eb0d4 * fVar20 * fVar20;
    fVar6 = _DAT_006eb098 +
            (((_DAT_006eb098 - _DAT_006eb0a8) * fRam006eb0f8 - _DAT_006eb088) + _DAT_006eb0b8) *
            fRam006eb0d8 * fVar22 * fVar22;
    fVar7 = _DAT_006eb09c +
            (((_DAT_006eb09c - _DAT_006eb0ac) * fRam006eb0fc - _DAT_006eb08c) + _DAT_006eb0bc) *
            fRam006eb0dc * fVar24 * fVar24;
    *param_3 = _DAT_006eb090 +
               (((_DAT_006eb090 - _DAT_006eb0a0) * _DAT_006eb0f0 - _DAT_006eb080) + _DAT_006eb0b0) *
               _DAT_006eb0d0 * fVar18 * fVar18 +
               (_DAT_006eb0a0 - _DAT_006eb080) * _DAT_006eb0d0 * fVar17 +
               ((DAT_006eb0e0 * _DAT_006eb0a0 + _DAT_006eb080) -
               (DAT_006eb100 * _DAT_006eb090 + _DAT_006eb0b0) * _DAT_006eb0d0) * fVar18;
    param_3[1] = fVar5 + fVar12 * fVar19 + (fVar8 - fVar11) * fVar20;
    param_3[2] = fVar6 + fVar14 * fVar21 + (fVar9 - fVar13) * fVar22;
    param_3[3] = fVar7 + fVar16 * fVar23 + (fVar10 - fVar15) * fVar24;
    param_3 = param_3 + 4;
  }
  for (; piVar2 = DAT_006eb110, (param_1 & 3) != 0; param_1 = param_1 - 1) {
    DAT_006eb0c0._0_4_ = uVar3 >> 1;
    fVar5 = *(float *)(param_2 + -4 + iVar4 * 4);
    fVar6 = *(float *)(param_2 + iVar4 * 4);
    uVar3 = (uint)DAT_006eb0c0 * 2 + param_7;
    fVar7 = *(float *)(param_2 + 4 + iVar4 * 4);
    fVar8 = *(float *)(param_2 + 8 + iVar4 * 4);
    iVar4 = iVar4 + param_6 + (uint)CARRY4((uint)DAT_006eb0c0 * 2,param_7);
    fVar9 = (float)(uint)DAT_006eb0c0 * _DAT_006eb070;
    fVar10 = fVar9 * fVar9;
    *param_3 = fVar6 + (((fVar6 - fVar7) * _DAT_006eb0f0 - fVar5) + fVar8) * _DAT_006eb0d0 *
                       fVar10 * fVar10 +
               (fVar7 - fVar5) * _DAT_006eb0d0 * fVar9 +
               ((DAT_006eb0e0 * fVar7 + fVar5) - (DAT_006eb100 * fVar6 + fVar8) * _DAT_006eb0d0) *
               fVar10;
    param_3 = param_3 + 1;
  }
  piVar1 = *(int **)(*DAT_006eb110 + 0x14);
  **(uint **)(*DAT_006eb110 + 0x18) = uVar3;
  *piVar1 = iVar4;
  return CONCAT44(piVar2[6],piVar2[8]);
}


// ==== 0x661f60 FUN_00661f60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 __fastcall
FUN_00661f60(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,float *param_5,
            int *param_6,uint *param_7,int param_8,uint param_9)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined4 in_EAX;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  
  uVar5 = *param_7;
  iVar7 = *param_6;
  _DAT_006eb120 = uVar5;
  for (; 1 < (int)param_3; param_3 = param_3 - 2) {
    lVar3 = CONCAT44(uRam006eb124,_DAT_006eb120);
    uVar4 = uVar5 + param_9;
    iVar6 = iVar7 + param_8 + (uint)CARRY4(uVar5,param_9);
    _DAT_006eb120 = uVar4;
    *param_5 = (float)lVar3 *
               (*(float *)(param_4 + 4 + iVar7 * 4) - *(float *)(param_4 + iVar7 * 4)) *
               _DAT_006eb128 + *(float *)(param_4 + iVar7 * 4);
    lVar3 = CONCAT44(uRam006eb124,_DAT_006eb120);
    uVar5 = uVar4 + param_9;
    iVar7 = iVar6 + param_8 + (uint)CARRY4(uVar4,param_9);
    _DAT_006eb120 = uVar5;
    param_5[1] = (float)lVar3 *
                 (*(float *)(param_4 + 4 + iVar6 * 4) - *(float *)(param_4 + iVar6 * 4)) *
                 _DAT_006eb128 + *(float *)(param_4 + iVar6 * 4);
    param_5 = param_5 + 2;
  }
  for (; (param_3 & 1) != 0; param_3 = param_3 - 1) {
    iVar2 = iVar7 * 4;
    iVar6 = iVar7 * 4;
    lVar3 = CONCAT44(uRam006eb124,_DAT_006eb120);
    bVar8 = CARRY4(uVar5,param_9);
    uVar5 = uVar5 + param_9;
    iVar1 = iVar7 * 4;
    iVar7 = iVar7 + param_8 + (uint)bVar8;
    _DAT_006eb120 = uVar5;
    *param_5 = (float)lVar3 * (*(float *)(param_4 + 4 + iVar2) - *(float *)(param_4 + iVar6)) *
               _DAT_006eb128 + *(float *)(param_4 + iVar1);
    param_5 = param_5 + 1;
  }
  *param_7 = uVar5;
  *param_6 = iVar7;
  return CONCAT44(param_2,in_EAX);
}


// ==== 0x662030 FUN_00662030

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 __fastcall
FUN_00662030(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,undefined4 *param_5,
            int *param_6,uint *param_7,int param_8,uint param_9)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 in_EAX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  
  uVar2 = DAT_006eb130;
  uVar4 = *param_7;
  DAT_006eb13a._0_2_ = (undefined2)(uVar4 >> 0x10);
  iVar6 = *param_6;
  while (1 < (int)param_3) {
    param_3 = param_3 - 2;
    uVar1 = CONCAT22(DAT_006eb13a._2_2_,(undefined2)DAT_006eb13a);
    uVar9 = (ulonglong)*(uint *)(param_4 + iVar6 * 4);
    uVar3 = uVar4 + param_9;
    iVar5 = iVar6 + param_8 + (uint)CARRY4(uVar4,param_9);
    DAT_006eb13a._0_2_ = (undefined2)(uVar3 >> 0x10);
    uVar12 = (ulonglong)*(uint *)(param_4 + iVar5 * 4);
    uVar8 = PackedIntToFloatingDwordConv((ulonglong)uVar1,(ulonglong)uVar1);
    uVar10 = PackedIntToFloatingDwordConv
                       ((ulonglong)CONCAT22(DAT_006eb13a._2_2_,(undefined2)DAT_006eb13a),
                        (ulonglong)CONCAT22(DAT_006eb13a._2_2_,(undefined2)DAT_006eb13a));
    uVar8 = PackedFloatingMUL(uVar8,uVar2);
    uVar11 = PackedFloatingMUL(uVar10,uVar2);
    uVar10 = PackedFloatingSUB((ulonglong)*(uint *)(param_4 + 4 + iVar6 * 4),uVar9);
    uVar13 = PackedFloatingSUB((ulonglong)*(uint *)(param_4 + 4 + iVar5 * 4),uVar12);
    uVar8 = PackedFloatingMUL(uVar8,uVar10);
    uVar10 = PackedFloatingMUL(uVar11,uVar13);
    uVar8 = PackedFloatingADD(uVar8,uVar9);
    uVar10 = PackedFloatingADD(uVar10,uVar12);
    *param_5 = (int)uVar8;
    param_5[1] = (int)uVar10;
    uVar4 = uVar3 + param_9;
    iVar6 = iVar5 + param_8 + (uint)CARRY4(uVar3,param_9);
    param_5 = param_5 + 2;
    DAT_006eb13a._0_2_ = (undefined2)(uVar4 >> 0x10);
  }
  while( true ) {
    DAT_006eb13a._0_2_ = (undefined2)(uVar4 >> 0x10);
    _DAT_006eb138 = (undefined2)uVar4;
    if ((param_3 & 1) == 0) break;
    uVar9 = (ulonglong)*(uint *)(param_4 + iVar6 * 4);
    uVar8 = PackedIntToFloatingDwordConv
                      ((ulonglong)CONCAT22(DAT_006eb13a._2_2_,(undefined2)DAT_006eb13a),
                       (ulonglong)CONCAT22(DAT_006eb13a._2_2_,(undefined2)DAT_006eb13a));
    uVar8 = PackedFloatingMUL(uVar8,uVar2);
    uVar10 = PackedFloatingSUB((ulonglong)*(uint *)(param_4 + 4 + iVar6 * 4),uVar9);
    uVar8 = PackedFloatingMUL(uVar8,uVar10);
    uVar8 = PackedFloatingADD(uVar8,uVar9);
    bVar7 = CARRY4(uVar4,param_9);
    uVar4 = uVar4 + param_9;
    iVar6 = iVar6 + param_8 + (uint)bVar7;
    *param_5 = (int)uVar8;
    param_5 = param_5 + 1;
    param_3 = param_3 - 1;
  }
  FastExitMediaState();
  *param_7 = uVar4;
  *param_6 = iVar6;
  return CONCAT44(param_2,in_EAX);
}


// ==== 0x662130 FUN_00662130

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 __fastcall
FUN_00662130(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,float *param_5,
            int *param_6,uint *param_7,int param_8,uint param_9)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 in_EAX;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  
  fVar5 = fRam006eb14c;
  fVar4 = fRam006eb148;
  fVar2 = fRam006eb144;
  fVar3 = _DAT_006eb140;
  uVar6 = *param_7;
  iVar12 = *param_6;
  for (; 7 < (int)param_3; param_3 = param_3 - 8) {
    DAT_006eb180._0_4_ = uVar6 >> 1;
    iVar1 = iVar12 * 4;
    _DAT_006eb150 = *(float *)(param_4 + iVar12 * 4);
    iVar9 = iVar12 + param_8 + (uint)CARRY4((uint)DAT_006eb180 * 2,param_9);
    DAT_006eb180._4_4_ = (uint)DAT_006eb180 * 2 + param_9 >> 1;
    _DAT_006eb154 = *(float *)(param_4 + iVar9 * 4);
    iVar10 = iVar9 + param_8 + (uint)CARRY4(DAT_006eb180._4_4_ * 2,param_9);
    DAT_006eb188._0_4_ = DAT_006eb180._4_4_ * 2 + param_9 >> 1;
    _DAT_006eb158 = *(float *)(param_4 + iVar10 * 4);
    iVar11 = iVar10 + param_8 + (uint)CARRY4((uint)DAT_006eb188 * 2,param_9);
    DAT_006eb188._4_4_ = (uint)DAT_006eb188 * 2 + param_9 >> 1;
    _DAT_006eb15c = *(float *)(param_4 + iVar11 * 4);
    iVar12 = iVar11 + param_8 + (uint)CARRY4(DAT_006eb188._4_4_ * 2,param_9);
    DAT_006eb190._0_4_ = DAT_006eb188._4_4_ * 2 + param_9 >> 1;
    _DAT_006eb170 = *(float *)(param_4 + 4 + iVar12 * 4);
    _DAT_006eb160 = *(float *)(param_4 + iVar12 * 4);
    iVar12 = iVar12 + param_8 + (uint)CARRY4((uint)DAT_006eb190 * 2,param_9);
    DAT_006eb190._4_4_ = (uint)DAT_006eb190 * 2 + param_9 >> 1;
    _DAT_006eb174 = *(float *)(param_4 + 4 + iVar12 * 4);
    _DAT_006eb164 = *(float *)(param_4 + iVar12 * 4);
    iVar12 = iVar12 + param_8 + (uint)CARRY4(DAT_006eb190._4_4_ * 2,param_9);
    DAT_006eb198._0_4_ = DAT_006eb190._4_4_ * 2 + param_9 >> 1;
    _DAT_006eb178 = *(float *)(param_4 + 4 + iVar12 * 4);
    _DAT_006eb168 = *(float *)(param_4 + iVar12 * 4);
    iVar12 = iVar12 + param_8 + (uint)CARRY4((uint)DAT_006eb198 * 2,param_9);
    DAT_006eb198._4_4_ = (uint)DAT_006eb198 * 2 + param_9 >> 1;
    _DAT_006eb17c = *(float *)(param_4 + 4 + iVar12 * 4);
    _DAT_006eb16c = *(float *)(param_4 + iVar12 * 4);
    uVar6 = DAT_006eb198._4_4_ * 2 + param_9;
    iVar12 = iVar12 + param_8 + (uint)CARRY4(DAT_006eb198._4_4_ * 2,param_9);
    fVar13 = (*(float *)(param_4 + 4 + iVar9 * 4) - _DAT_006eb154) *
             (float)DAT_006eb180._4_4_ * fVar2 + _DAT_006eb154;
    fVar14 = (*(float *)(param_4 + 4 + iVar10 * 4) - _DAT_006eb158) *
             (float)(uint)DAT_006eb188 * fVar4 + _DAT_006eb158;
    fVar15 = (*(float *)(param_4 + 4 + iVar11 * 4) - _DAT_006eb15c) *
             (float)DAT_006eb188._4_4_ * fVar5 + _DAT_006eb15c;
    fVar16 = (_DAT_006eb170 - _DAT_006eb160) * (float)(uint)DAT_006eb190 * fVar3 + _DAT_006eb160;
    fVar17 = (_DAT_006eb174 - _DAT_006eb164) * (float)DAT_006eb190._4_4_ * fVar2 + _DAT_006eb164;
    fVar18 = (_DAT_006eb178 - _DAT_006eb168) * (float)(uint)DAT_006eb198 * fVar4 + _DAT_006eb168;
    fVar19 = (_DAT_006eb17c - _DAT_006eb16c) * (float)DAT_006eb198._4_4_ * fVar5 + _DAT_006eb16c;
    *param_5 = (*(float *)(param_4 + 4 + iVar1) - _DAT_006eb150) * (float)(uint)DAT_006eb180 * fVar3
               + _DAT_006eb150;
    param_5[1] = fVar13;
    param_5[2] = fVar14;
    param_5[3] = fVar15;
    param_5[4] = fVar16;
    param_5[5] = fVar17;
    param_5[6] = fVar18;
    param_5[7] = fVar19;
    param_5 = param_5 + 8;
  }
  for (; (param_3 & 7) != 0; param_3 = param_3 - 1) {
    uVar7 = uVar6 >> 1;
    iVar1 = iVar12 * 4;
    fVar2 = *(float *)(param_4 + iVar12 * 4);
    uVar8 = uVar7 * 2;
    uVar6 = uVar8 + param_9;
    iVar12 = iVar12 + param_8 + (uint)CARRY4(uVar8,param_9);
    *param_5 = fVar2 + (*(float *)(param_4 + 4 + iVar1) - fVar2) * (float)uVar7 * fVar3;
    param_5 = param_5 + 1;
  }
  *param_7 = uVar6;
  *param_6 = iVar12;
  return CONCAT44(param_2,in_EAX);
}


// ==== 0x662340 FUN_00662340

int FUN_00662340(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (param_1 * param_2) / 1000;
  if (iVar3 < 3) {
    iVar3 = 3;
  }
  do {
    do {
      iVar2 = 0;
      do {
        iVar1 = iVar2;
        if (iVar1 * iVar1 - iVar3 == 0) goto LAB_0066237f;
        iVar2 = iVar1 + 1;
      } while (iVar1 * iVar1 < iVar3);
      iVar1 = iVar1 + -1;
LAB_0066237f:
      iVar1 = iVar1 + 1;
      iVar2 = 2;
    } while (iVar1 < 2);
    do {
      if (iVar3 % iVar2 == 0) {
        iVar3 = iVar3 + 1;
        break;
      }
      if (iVar2 == iVar1) {
        return iVar3;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= iVar1);
  } while( true );
}


// ==== 0x6623c0 FUN_006623c0

int FUN_006623c0(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = *param_1;
  uVar3 = 0xe;
  if (uVar1 != *param_2) {
    return (uint)uVar1 - (uint)*param_2;
  }
  if (uVar1 == 2) {
    uVar3 = 6;
  }
  iVar2 = FUN_00668c60(param_1 + 1,param_2 + 1,uVar3);
  return iVar2;
}


// ==== 0x662410 FUN_00662410

undefined4 FUN_00662410(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    *(undefined1 *)(iVar2 + 4 + param_1) = 0;
    bVar1 = *param_2;
    while (('/' < (char)bVar1 && ((char)bVar1 < ':'))) {
      param_2 = param_2 + 1;
      *(byte *)(iVar2 + 4 + param_1) = *(char *)(iVar2 + 4 + param_1) * '\n' + (bVar1 & 0xf);
      bVar1 = *param_2;
    }
    if ((int)(char)*param_2 != ((2 < iVar2) - 1 & 0x2e)) break;
    iVar2 = iVar2 + 1;
    param_2 = param_2 + 1;
    if (3 < iVar2) {
      return 0;
    }
  }
  *(undefined1 *)(param_1 + 5) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  return 0xffffffff;
}


// ==== 0x662490 FUN_00662490

char * FUN_00662490(int param_1,char *param_2,int param_3)

{
  ulonglong uVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (0 < param_3) {
    if (0xf < param_3) {
      uVar2 = (uint)*(byte *)(param_1 + 4);
      pcVar4 = param_2;
      if (99 < uVar2) {
        uVar1 = (ulonglong)uVar2 % 100;
        *param_2 = (char)((ulonglong)uVar2 / 100) + '0';
        uVar2 = (uint)(uVar1 % 10);
        param_2[1] = (char)(uVar1 / 10) + '0';
        pcVar4 = param_2 + 2;
      }
      if (9 < uVar2) {
        uVar3 = uVar2 / 10;
        uVar2 = uVar2 % 10;
        *pcVar4 = (char)uVar3 + '0';
        pcVar4 = pcVar4 + 1;
      }
      *pcVar4 = (char)uVar2 + '0';
      pcVar4[1] = '.';
      uVar2 = (uint)*(byte *)(param_1 + 5);
      pcVar5 = pcVar4 + 2;
      if (99 < uVar2) {
        uVar1 = (ulonglong)uVar2 % 100;
        *pcVar5 = (char)((ulonglong)uVar2 / 100) + '0';
        uVar2 = (uint)(uVar1 % 10);
        pcVar4[3] = (char)(uVar1 / 10) + '0';
        pcVar5 = pcVar4 + 4;
      }
      if (9 < uVar2) {
        uVar3 = uVar2 / 10;
        uVar2 = uVar2 % 10;
        *pcVar5 = (char)uVar3 + '0';
        pcVar5 = pcVar5 + 1;
      }
      *pcVar5 = (char)uVar2 + '0';
      pcVar5[1] = '.';
      uVar2 = (uint)*(byte *)(param_1 + 6);
      pcVar4 = pcVar5 + 2;
      if (99 < uVar2) {
        uVar1 = (ulonglong)uVar2 % 100;
        *pcVar4 = (char)((ulonglong)uVar2 / 100) + '0';
        uVar2 = (uint)(uVar1 % 10);
        pcVar5[3] = (char)(uVar1 / 10) + '0';
        pcVar4 = pcVar5 + 4;
      }
      if (9 < uVar2) {
        uVar3 = uVar2 / 10;
        uVar2 = uVar2 % 10;
        *pcVar4 = (char)uVar3 + '0';
        pcVar4 = pcVar4 + 1;
      }
      *pcVar4 = (char)uVar2 + '0';
      pcVar4[1] = '.';
      uVar2 = (uint)*(byte *)(param_1 + 7);
      pcVar5 = pcVar4 + 2;
      if (99 < uVar2) {
        uVar1 = (ulonglong)uVar2 % 100;
        *pcVar5 = (char)((ulonglong)uVar2 / 100) + '0';
        uVar2 = (uint)(uVar1 % 10);
        pcVar4[3] = (char)(uVar1 / 10) + '0';
        pcVar5 = pcVar4 + 4;
      }
      if (9 < uVar2) {
        uVar3 = uVar2 / 10;
        uVar2 = uVar2 % 10;
        *pcVar5 = (char)uVar3 + '0';
        pcVar5 = pcVar5 + 1;
      }
      *pcVar5 = (char)uVar2 + '0';
      pcVar5[1] = '\0';
      return param_2;
    }
    *param_2 = '\0';
  }
  return (char *)0x0;
}


// ==== 0x6625d0 FUN_006625d0

ushort FUN_006625d0(ushort param_1)

{
  return param_1 << 8 | param_1 >> 8;
}


// ==== 0x6625f0 FUN_006625f0

uint FUN_006625f0(uint param_1)

{
  return (((param_1 & 0xff) << 8 | param_1 >> 8 & 0xff) << 8 | param_1 >> 0x10 & 0xff) << 8 |
         param_1 >> 0x18;
}


// ==== 0x662620 FUN_00662620

undefined2 FUN_00662620(undefined2 param_1)

{
  return CONCAT11((char)param_1,(char)((ushort)param_1 >> 8));
}


// ==== 0x662640 FUN_00662640

undefined4 FUN_00662640(undefined4 param_1)

{
  return CONCAT31(CONCAT21(CONCAT11((char)param_1,(char)((uint)param_1 >> 8)),
                           (char)((uint)param_1 >> 0x10)),(char)((uint)param_1 >> 0x18));
}


// ==== 0x662670 FUN_00662670

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined * FUN_00662670(undefined4 param_1)

{
  uint unaff_retaddr;
  undefined1 local_14 [4];
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  local_d = (undefined1)param_1;
  local_e = (undefined1)((uint)param_1 >> 8);
  local_f = (undefined1)((uint)param_1 >> 0x10);
  local_10 = (undefined1)((uint)param_1 >> 0x18);
  FUN_00662490(local_14,&DAT_00717700,0x14);
  return &DAT_00717700;
}


// ==== 0x6626d0 FUN_006626d0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006626d0(undefined4 param_1)

{
  uint unaff_retaddr;
  undefined1 local_14 [4];
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  FUN_00662410(local_14,param_1);
  return CONCAT31(CONCAT21(CONCAT11(local_10,local_f),local_e),local_d);
}


// ==== 0x662730 FUN_00662730

byte FUN_00662730(uint *param_1,int *param_2,int *param_3,byte *param_4)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  
  bVar2 = *param_4;
  while (('\0' < (char)bVar2 && ((char)bVar2 < '!'))) {
    pbVar1 = param_4 + 1;
    param_4 = param_4 + 1;
    bVar2 = *pbVar1;
  }
  uVar3 = 0;
LAB_00662752:
  do {
    bVar2 = *param_4;
    if (((char)bVar2 < '0') || ('9' < (char)bVar2)) {
      if (bVar2 != 0x2e) {
        bVar5 = uVar3 != 0;
        *param_1 = uVar3;
        bVar2 = *param_4;
        while ((bVar2 != 0x3a && (bVar2 != 0))) {
          pbVar1 = param_4 + 1;
          param_4 = param_4 + 1;
          bVar2 = *pbVar1;
        }
        iVar4 = 0;
        if (*param_4 == 0x3a) {
          param_4 = param_4 + 1;
          bVar2 = *param_4;
          while (('/' < (char)bVar2 && ((char)bVar2 < ':'))) {
            param_4 = param_4 + 1;
            iVar4 = (bVar2 & 0xf) + iVar4 * 10;
            bVar2 = *param_4;
          }
          bVar5 = bVar5 | 2;
        }
        *param_2 = iVar4;
        if (param_3 != (int *)0x0) {
          iVar4 = 0;
          if (*param_4 == 0x3a) {
            param_4 = param_4 + 1;
            bVar2 = *param_4;
            while (('/' < (char)bVar2 && ((char)bVar2 < ':'))) {
              param_4 = param_4 + 1;
              iVar4 = (bVar2 & 0xf) + iVar4 * 10;
              bVar2 = *param_4;
            }
            bVar5 = bVar5 | 4;
          }
          *param_3 = iVar4;
        }
        return bVar5;
      }
    }
    else if (bVar2 != 0x2e) {
      uVar3 = uVar3 + (uVar3 & 0xff) * 9 + (bVar2 & 0xf);
      param_4 = param_4 + 1;
      goto LAB_00662752;
    }
    uVar3 = uVar3 << 8;
    param_4 = param_4 + 1;
  } while( true );
}


// ==== 0x662820 FUN_00662820

void FUN_00662820(undefined2 *param_1,undefined4 param_2)

{
  undefined2 *puVar1;
  undefined2 local_4 [2];
  
  puVar1 = param_1;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *param_1 = 2;
  FUN_00662730(&param_1,local_4,0,param_2);
  *(char *)((int)puVar1 + 7) = (char)param_1;
  *(char *)(puVar1 + 3) = (char)((uint)param_1 >> 8);
  *(char *)((int)puVar1 + 5) = (char)((uint)param_1 >> 0x10);
  *(char *)(puVar1 + 2) = (char)((uint)param_1 >> 0x18);
  *(char *)(puVar1 + 1) = (char)((ushort)local_4[0] >> 8);
  *(char *)((int)puVar1 + 3) = (char)local_4[0];
  return;
}


// ==== 0x662880 FUN_00662880

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00662880(PUCHAR param_1)

{
  _NCB *p_Var1;
  UCHAR UVar2;
  int iVar3;
  undefined4 *puVar4;
  uint unaff_retaddr;
  _NCB local_44;
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  puVar4 = (undefined4 *)&stack0xffffffb8;
  p_Var1 = &local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined4 *)p_Var1 = 0;
    p_Var1 = (_NCB *)((int)p_Var1 + 4);
  }
  local_44.ncb_command = '2';
  local_44.ncb_lana_num = 0;
  while (UVar2 = Netbios(&local_44), UVar2 != '\0') {
    local_44.ncb_lana_num = local_44.ncb_lana_num + 1;
    if (9 < local_44.ncb_lana_num) {
      return 0xffffffff;
    }
  }
  if (9 < local_44.ncb_lana_num) {
    return 0xffffffff;
  }
  for (iVar3 = 0x10; puVar4 = puVar4 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
  }
  builtin_memcpy(local_44.ncb_callname,"*           ",0xc);
  builtin_memcpy(local_44.ncb_callname + 0xc,"    ",4);
  local_44.ncb_command = '3';
  local_44.ncb_name[0] = '\0';
  local_44.ncb_buffer = param_1;
  local_44.ncb_length = 0xf0;
  UVar2 = Netbios(&local_44);
  if (UVar2 != '\0') {
    return 0xffffffff;
  }
  return 0;
}


// ==== 0x662960 FUN_00662960

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined * FUN_00662960(void)

{
  uint unaff_retaddr;
  byte local_f4;
  byte bStack_f3;
  byte bStack_f2;
  byte bStack_f1;
  byte bStack_f0;
  byte bStack_ef;
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  DAT_00717798 = 0;
  FUN_00662880(&local_f4);
  DAT_0071779a = "70123456789abcdef*               "[(local_f4 & 0xf) + 1];
  DAT_0071779c = "70123456789abcdef*               "[(bStack_f3 & 0xf) + 1];
  DAT_00717799 = "70123456789abcdef*               "[(local_f4 >> 4) + 1];
  DAT_0071779e = "70123456789abcdef*               "[(bStack_f2 & 0xf) + 1];
  DAT_0071779b = "70123456789abcdef*               "[(bStack_f3 >> 4) + 1];
  DAT_007177a0 = "70123456789abcdef*               "[(bStack_f1 & 0xf) + 1];
  DAT_0071779d = "70123456789abcdef*               "[(bStack_f2 >> 4) + 1];
  DAT_007177a2 = "70123456789abcdef*               "[(bStack_f0 & 0xf) + 1];
  DAT_0071779f = "70123456789abcdef*               "[(bStack_f1 >> 4) + 1];
  DAT_007177a1 = "70123456789abcdef*               "[(bStack_f0 >> 4) + 1];
  DAT_007177a4 = "70123456789abcdef*               "[(bStack_ef & 0xf) + 1];
  DAT_00717798 = 0x24;
  DAT_007177a3 = "70123456789abcdef*               "[(bStack_ef >> 4) + 1];
  DAT_007177a5 = 0;
  return &DAT_00717798;
}


// ==== 0x662a90 FUN_00662a90

undefined4 FUN_00662a90(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0x6f70656e) {
    return DAT_007177a8;
  }
  if (param_1 == 0x6f6e6c6e) {
    return DAT_007177b0;
  }
  if (param_1 == 0x636f6e6e) {
    return DAT_007177ac;
  }
  if (param_1 == 0x61646472) {
    uVar1 = FUN_006634a0();
    return uVar1;
  }
  return 0xffffffff;
}


// ==== 0x662ad0 FUN_00662ad0

int FUN_00662ad0(void)

{
  int in_EAX;
  int iVar1;
  
  if (in_EAX < 0) {
    iVar1 = Ordinal_111();
    if ((iVar1 != 0x2733) && (iVar1 != 0x2746)) {
      if (iVar1 == 0x2743) {
        return -5;
      }
      if (iVar1 == 0x2749) {
        return -2;
      }
      return (iVar1 == 0x274d) - 7;
    }
    in_EAX = 0;
  }
  return in_EAX;
}


// ==== 0x662b20 FUN_00662b20

void FUN_00662b20(undefined4 *param_1)

{
  int iVar1;
  DWORD DVar2;
  
  DVar2 = GetTickCount();
  FUN_00668d60(0);
  for (param_1 = (undefined4 *)*param_1; iVar1 = DAT_007177c0, param_1 != (undefined4 *)0x0;
      param_1 = (undefined4 *)*param_1) {
    if ((((param_1[0x11] != 0) && ((code *)param_1[0x13] != (code *)0x0)) && (param_1[0x10] != -1))
       && ((uint)param_1[0x11] < DVar2 - param_1[0x10])) {
      param_1[0x10] = 0xffffffff;
      (*(code *)param_1[0x13])(param_1,0,param_1[0x12]);
      DVar2 = GetTickCount();
      param_1[0x10] = DVar2;
    }
  }
  while (iVar1 != 0) {
    DAT_007177c0 = *(int *)(iVar1 + 4);
    FUN_00447030(iVar1);
    iVar1 = DAT_007177c0;
  }
  DAT_007177c0 = iVar1;
  FUN_00668df0();
  return;
}


// ==== 0x662bc0 FUN_00662bc0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00662bc0(void)

{
  int iVar1;
  undefined2 unaff_DI;
  undefined4 *puVar2;
  uint unaff_retaddr;
  undefined4 local_1a0 [101];
  uint local_c;
  
  local_c = DAT_006eb720 ^ unaff_retaddr;
  FUN_00668f40();
  FUN_00668e20(FUN_00662b20,&DAT_007177bc);
  puVar2 = local_1a0;
  for (iVar1 = 100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  Ordinal_115(2,local_1a0);
  DAT_007177b8 = (uint)CONCAT11((char)unaff_DI,(char)((ushort)unaff_DI >> 8));
  return;
}


// ==== 0x662c30 FUN_00662c30

undefined4 * FUN_00662c30(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 unaff_EBP;
  undefined4 *puVar4;
  undefined4 uStack_10;
  
  uStack_10 = param_3;
  iVar1 = Ordinal_23();
  if (iVar1 == -1) {
    return (undefined4 *)0x0;
  }
  puVar2 = (undefined4 *)FUN_00549460(0x50);
  puVar4 = puVar2;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar2[6] = iVar1;
  Ordinal_10(iVar1,0x8004667e,&uStack_10);
  if (param_2 == 2) {
    Ordinal_21(iVar1,0xffff,0x20,&stack0xffffffe4,4);
  }
  puVar2[2] = param_2;
  puVar2[3] = param_2;
  puVar2[4] = unaff_EBP;
  FUN_00668d60(0);
  *puVar2 = DAT_007177bc;
  DAT_007177bc = puVar2;
  FUN_00668df0(0);
  return puVar2;
}


// ==== 0x662ce0 FUN_00662ce0

undefined4 FUN_00662ce0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  FUN_00668d60(0);
  piVar3 = &DAT_007177bc;
  iVar2 = DAT_007177bc;
  do {
    if (iVar2 == 0) {
LAB_00662d13:
      FUN_00668df0(0);
      FUN_00668e50();
      Ordinal_22(param_1[6],2);
      Ordinal_3(param_1[6]);
      param_1[6] = -1;
      FUN_00668d60(0);
      param_1[1] = (int)DAT_007177c0;
      DAT_007177c0 = param_1;
      FUN_00668df0(0);
      return 0;
    }
    piVar1 = (int *)*piVar3;
    if (piVar1 == param_1) {
      *piVar3 = *param_1;
      goto LAB_00662d13;
    }
    iVar2 = *piVar1;
    piVar3 = piVar1;
  } while( true );
}


// ==== 0x662d70 FUN_00662d70

void FUN_00662d70(int param_1,undefined4 param_2,undefined4 param_3)

{
  Ordinal_2(*(undefined4 *)(param_1 + 0x18),param_2,param_3);
  FUN_00662ad0();
  return;
}


// ==== 0x662d90 FUN_00662d90

void FUN_00662d90(int param_1,undefined4 param_2,undefined4 param_3)

{
  Ordinal_4(*(undefined4 *)(param_1 + 0x18),param_2,param_3);
  FUN_00662ad0();
  return;
}


// ==== 0x662db0 FUN_00662db0

void FUN_00662db0(int param_1,undefined4 param_2)

{
  Ordinal_13(*(undefined4 *)(param_1 + 0x18),param_2);
  FUN_00662ad0();
  return;
}


// ==== 0x662dd0 FUN_00662dd0

undefined4 * FUN_00662dd0(int param_1,int param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar3 = (undefined4 *)0x0;
  if (*(int *)(param_1 + 0x18) == -1) {
    return (undefined4 *)0x0;
  }
  if ((param_2 != 0) && (*param_3 < 0x10)) {
    return (undefined4 *)0x0;
  }
  if ((*(int *)(param_1 + 8) == 2) &&
     (iVar1 = Ordinal_1(*(int *)(param_1 + 0x18),param_2,param_3), iVar1 != -1)) {
    Ordinal_10(iVar1,0x8004667e,&stack0xfffffff0);
    puVar3 = (undefined4 *)FUN_00549460(0x50);
    puVar4 = puVar3;
    for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    puVar3[6] = iVar1;
    puVar3[2] = *(undefined4 *)(param_1 + 8);
    puVar3[3] = *(undefined4 *)(param_1 + 0xc);
    puVar3[4] = *(undefined4 *)(param_1 + 0x10);
    FUN_00668d60(0);
    *puVar3 = DAT_007177bc;
    DAT_007177bc = puVar3;
    FUN_00668df0(0);
  }
  return puVar3;
}


// ==== 0x662e80 FUN_00662e80

void FUN_00662e80(uint param_1,byte *param_2,int param_3,undefined4 param_4,int param_5,
                 undefined4 param_6)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  
  pbVar5 = param_2;
  uVar2 = param_1;
  iVar3 = param_3;
  if (*(int *)(param_1 + 0xc) == 3) {
    puVar1 = (undefined4 *)(param_1 + 0x18);
    param_1 = (uint)param_2[8];
    Ordinal_21(*puVar1,0,4,&param_1,4);
    uVar4 = *pbVar5 & 0xf;
    iVar3 = param_3 + uVar4 * -4;
    pbVar5 = pbVar5 + uVar4 * 4;
    if (iVar3 < 0) {
      iVar3 = 0;
    }
  }
  if (param_5 != 0) {
    Ordinal_20(*(undefined4 *)(uVar2 + 0x18),pbVar5,iVar3,0,param_5,param_6);
    FUN_00662ad0();
    return;
  }
  Ordinal_19(*(undefined4 *)(uVar2 + 0x18),pbVar5,iVar3,0);
  FUN_00662ad0();
  return;
}


// ==== 0x662f00 FUN_00662f00

int FUN_00662f00(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
                undefined4 param_6)

{
  int iVar1;
  DWORD DVar2;
  byte unaff_retaddr;
  
  if (param_5 == 0) {
    iVar1 = Ordinal_16(*(undefined4 *)(param_1 + 0x18),param_2,param_3,0);
  }
  else {
    iVar1 = Ordinal_17(*(undefined4 *)(param_1 + 0x18),param_2,param_3,0,param_5,param_6);
    if (0 < iVar1) {
      DVar2 = GetTickCount();
      *(char *)(param_5 + 0xb) = (char)DVar2;
      *(char *)(param_5 + 10) = (char)(DVar2 >> 8);
      *(char *)(param_5 + 9) = (char)(DVar2 >> 0x10);
      *(char *)(param_5 + 8) = (char)(DVar2 >> 0x18);
    }
  }
  if (iVar1 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = FUN_00662ad0();
  }
  if ((unaff_retaddr & 0x20) != 0) {
    if (iVar1 == -1) {
      return 0;
    }
    if (iVar1 == 0) {
      iVar1 = -1;
    }
  }
  return iVar1;
}


// ==== 0x662f90 FUN_00662f90

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00662f90(int param_1,int param_2,undefined4 *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint unaff_retaddr;
  int iVar4;
  undefined4 uStack_148;
  undefined4 *puStack_144;
  undefined4 *puStack_140;
  undefined1 *puStack_13c;
  int iStack_138;
  undefined4 *puStack_134;
  undefined1 local_118 [4];
  undefined4 uStack_114;
  undefined4 uStack_110;
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  if (param_3 != (undefined4 *)0x0) {
    puVar3 = param_3;
    for (uVar2 = param_4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    for (param_4 = param_4 & 3; param_4 != 0; param_4 = param_4 - 1) {
      *(undefined1 *)puVar3 = 0;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  iStack_138 = *(int *)(param_1 + 0x18);
  if (iStack_138 == -1) {
    return 0xfffffff9;
  }
  if (param_2 != 0x636f6e6e) {
    if (param_2 == 0x62696e64) {
      puStack_134 = param_3;
      puStack_13c = (undefined1 *)0x663024;
      Ordinal_6();
      return 0;
    }
    if (param_2 != 0x70656572) {
      if (param_2 != 0x73746174) {
        return 0xffffffff;
      }
      puStack_134 = (undefined4 *)local_118;
      puStack_13c = (undefined1 *)0x663097;
      Ordinal_5();
      puStack_13c = (undefined1 *)0x66309c;
      iVar1 = FUN_00662ad0();
      if (iVar1 == -2) {
        return 0;
      }
      uStack_110 = *(undefined4 *)(param_1 + 0x18);
      puStack_13c = &stack0xfffffed4;
      puStack_140 = &uStack_114;
      puStack_144 = &uStack_114;
      uStack_148 = 0;
      uStack_114 = 1;
      iVar1 = Ordinal_18(1);
      if (iVar1 == 0) {
        return 0;
      }
      iVar4 = 0x1007;
      uStack_148 = 4;
      iVar1 = Ordinal_7(*(undefined4 *)(param_1 + 0x18),0xffff,0x1007,&puStack_144,&uStack_148);
      if (iVar1 != 0) {
        return 0;
      }
      if (iVar4 != 0) {
        return 0;
      }
      return 1;
    }
  }
  puStack_134 = param_3;
  puStack_13c = (undefined1 *)0x663057;
  Ordinal_5();
  return 0;
}


// ==== 0x663160 FUN_00663160

undefined4
FUN_00663160(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  *(undefined4 *)(param_1 + 0x44) = param_3;
  *(undefined4 *)(param_1 + 0x3c) = param_2;
  *(undefined4 *)(param_1 + 0x48) = param_4;
  *(undefined4 *)(param_1 + 0x4c) = param_5;
  return 0;
}


// ==== 0x663190 FUN_00663190

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00663190(undefined4 *param_1,uint param_2,short *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  short *psVar4;
  undefined4 unaff_EDI;
  undefined4 *puVar5;
  uint unaff_retaddr;
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  if (param_2 != param_4) {
    return 0xffffffff;
  }
  if (*param_3 == 2) {
    psVar4 = param_3;
    puVar5 = param_1;
    for (uVar3 = param_2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar5 = *(undefined4 *)psVar4;
      psVar4 = psVar4 + 2;
      puVar5 = puVar5 + 1;
    }
    for (param_2 = param_2 & 3; param_2 != 0; param_2 = param_2 - 1) {
      *(char *)puVar5 = (char)*psVar4;
      psVar4 = (short *)((int)psVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    *(undefined1 *)((int)param_1 + 7) = 0;
    *(undefined1 *)((int)param_1 + 6) = 0;
    *(undefined1 *)((int)param_1 + 5) = 0;
    *(undefined1 *)(param_1 + 1) = 0;
    iVar1 = Ordinal_23(2,2,0);
    if (iVar1 != -1) {
      if (0x1ff < DAT_007177b8) {
        iVar2 = WSAIoctl(iVar1,0xc8000014,param_3,param_1,&stack0xffffffe0,0x10,&local_4,0,0);
        if (iVar2 < 0) {
          Ordinal_111();
        }
        param_1[1] = unaff_EDI;
        if (CONCAT31(CONCAT21(CONCAT11((char)unaff_EDI,*(undefined1 *)((int)param_1 + 5)),
                              *(undefined1 *)((int)param_1 + 6)),*(undefined1 *)((int)param_1 + 7))
            == 0x7f000001) {
          param_1[1] = *(undefined4 *)(param_3 + 2);
        }
      }
      if (CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 1),*(undefined1 *)((int)param_1 + 5)),
                   *(undefined1 *)((int)param_1 + 6)) == 0 && *(char *)((int)param_1 + 7) == '\0') {
        iVar2 = Ordinal_4(iVar1,param_3,param_1);
        if (iVar2 == 0) {
          iVar2 = Ordinal_6(iVar1,&stack0xffffffe0,&local_4);
          if (iVar2 == 0) {
            param_1[1] = unaff_EDI;
          }
        }
      }
      Ordinal_3(iVar1);
    }
    return 0;
  }
  for (uVar3 = param_2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  for (param_2 = param_2 & 3; param_2 != 0; param_2 = param_2 - 1) {
    *(undefined1 *)param_1 = 0;
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  return 0xfffffffd;
}


// ==== 0x663300 FUN_00663300

undefined4 FUN_00663300(undefined4 *param_1)

{
  return *param_1;
}


// ==== 0x663310 FUN_00663310

void FUN_00663310(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedExchange((LONG *)(param_1 + 0x54),1);
  if (LVar1 != 0) {
    FUN_00447030(param_1);
  }
  return;
}


// ==== 0x663330 FUN_00663330

undefined4 FUN_00663330(undefined4 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 *puVar5;
  int iVar6;
  LONG LVar7;
  
  iVar6 = Ordinal_52(param_1 + 4);
  if (iVar6 == 0) {
    *param_1 = 0xffffffff;
  }
  else {
    puVar5 = (undefined1 *)**(undefined4 **)(iVar6 + 0xc);
    uVar1 = puVar5[2];
    uVar2 = *puVar5;
    uVar3 = puVar5[1];
    uVar4 = puVar5[3];
    *param_1 = 1;
    param_1[1] = CONCAT31(CONCAT21(CONCAT11(uVar2,uVar3),uVar1),uVar4);
  }
  LVar7 = InterlockedExchange(param_1 + 0x15,1);
  if (LVar7 != 0) {
    FUN_00447030(param_1);
  }
  return 0;
}


// ==== 0x663390 FUN_00663390

undefined4 * FUN_00663390(byte *param_1,DWORD param_2)

{
  byte bVar1;
  undefined4 *lpParameter;
  HANDLE hObject;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  if ((int)param_2 < 0) {
    return (undefined4 *)0x0;
  }
  lpParameter = (undefined4 *)FUN_00549460(0x5c);
  puVar5 = lpParameter;
  for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  lpParameter[2] = FUN_00663300;
  lpParameter[3] = FUN_00663310;
  bVar1 = *param_1;
  pbVar3 = param_1;
  if (bVar1 == 0) {
LAB_006633e6:
    if (*pbVar3 != 0) {
      puVar5 = lpParameter + 4;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *(undefined4 *)param_1;
        param_1 = param_1 + 4;
        puVar5 = puVar5 + 1;
      }
      *(undefined1 *)((int)lpParameter + 0x4f) = 0;
      hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00663330,lpParameter,0,&param_2);
      if (hObject != (HANDLE)0x0) {
        CloseHandle(hObject);
      }
      return lpParameter;
    }
  }
  else {
    do {
      if ((bVar1 != 0x2e) && (((char)bVar1 < '0' || ('9' < (char)bVar1)))) goto LAB_006633e6;
      bVar1 = pbVar3[1];
      pbVar3 = pbVar3 + 1;
    } while (bVar1 != 0);
  }
  iVar2 = 0;
  while( true ) {
    uVar4 = 0;
    bVar1 = *param_1;
    while (('/' < (char)bVar1 && ((char)bVar1 < ':'))) {
      param_1 = param_1 + 1;
      uVar4 = (bVar1 & 0xf) + uVar4 * 10;
      bVar1 = *param_1;
    }
    if (((int)(char)*param_1 != ((2 < iVar2) - 1 & 0x2e)) || (0xff < (int)uVar4)) break;
    param_1 = param_1 + 1;
    iVar2 = iVar2 + 1;
    lpParameter[1] = lpParameter[1] << 8 | uVar4;
    *lpParameter = 1;
    if (3 < iVar2) {
      return lpParameter;
    }
  }
  *lpParameter = 0xfffffffe;
  lpParameter[1] = 0;
  return lpParameter;
}


// ==== 0x6634a0 FUN_006634a0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_006634a0(void)

{
  uint unaff_retaddr;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_24 = 0x4f000002;
  local_20 = 0x101a8c0;
  local_8 = 0;
  FUN_00663190(&local_14,0x10,&local_24,0x10);
  return (((local_10 & 0xff) << 8 | local_10 >> 8 & 0xff) << 8 | local_10 >> 0x10 & 0xff) << 8 |
         local_10 >> 0x18;
}


// ==== 0x663540 FUN_00663540

undefined4 * FUN_00663540(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)FUN_00549460(0xac);
  if (puVar1 != (undefined4 *)0x0) {
    puVar3 = puVar1;
    for (iVar2 = 0x2b; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
  }
  return puVar1;
}


// ==== 0x663570 FUN_00663570

void FUN_00663570(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0x7c);
  iVar2 = 4;
  do {
    iVar1 = *piVar3;
    if (iVar1 != 0) {
      (**(code **)(iVar1 + 4))(iVar1);
    }
    *piVar3 = 0;
    piVar3 = piVar3 + 3;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (*(int *)(param_1 + 0x68) != 0) {
    FUN_006698c0(*(int *)(param_1 + 0x68));
    *(undefined4 *)(param_1 + 0x68) = 0;
  }
  if (*(int *)(param_1 + 100) != 0) {
    FUN_006698c0(*(int *)(param_1 + 100));
    *(undefined4 *)(param_1 + 100) = 0;
  }
  *(undefined4 *)(param_1 + 0x78) = 0;
  return;
}


// ==== 0x6635d0 FUN_006635d0

undefined4 FUN_006635d0(int param_1,uint param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  
  if (param_2 == 0xffffffff) {
    param_2 = 3;
  }
  else if (param_2 == 0) {
    param_2 = 0x101;
  }
  else if (param_2 == 1) {
    param_2 = 0x102;
  }
  pcVar3 = param_3;
  do {
    cVar1 = *pcVar3;
    pcVar3[(param_1 - (int)param_3) + 0x24] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  *(uint *)(param_1 + 0x6c) = param_2 >> 1 & 1;
  *(uint *)(param_1 + 0x78) = param_2 & 0xfffffffc;
  if ((param_2 & 0xfffffffc) == 0) {
    *(undefined4 *)(param_1 + 0x78) = 0x100;
  }
  piVar6 = (int *)(param_1 + 0x7c);
  iVar5 = 4;
  piVar7 = piVar6;
  do {
    iVar2 = *piVar7;
    if (iVar2 != 0) {
      (**(code **)(iVar2 + 4))(iVar2);
    }
    *piVar7 = 0;
    piVar7[1] = 0;
    piVar7 = piVar7 + 3;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if (((byte)param_2 & 3) != 3) {
    if ((param_2 & 0x100) != 0) {
      iVar5 = FUN_0066d8f0(0x20e,0x20,0x20);
      *piVar6 = iVar5;
      *(undefined4 *)(param_1 + 0x84) = 0;
    }
    if ((param_2 & 0x400) != 0) {
      uVar4 = FUN_0066bf40(0x20e,0x20,0x20);
      *(undefined4 *)(param_1 + 0x88) = uVar4;
      *(undefined4 *)(param_1 + 0x90) = 0;
    }
    if ((param_2 & 0x200) != 0) {
      uVar4 = FUN_0066b000(0x20e,0x20,0x20);
      *(undefined4 *)(param_1 + 0x94) = uVar4;
      if ((*piVar6 == 0) && (*(int *)(param_1 + 0x88) == 0)) {
        uVar4 = 0;
      }
      else {
        uVar4 = 5000;
      }
      *(undefined4 *)(param_1 + 0x9c) = uVar4;
    }
    if ((param_2 & 0x800) != 0) {
      uVar4 = FUN_0066a3e0(0x20e,0x20,0x20);
      *(undefined4 *)(param_1 + 0xa0) = uVar4;
      *(undefined4 *)(param_1 + 0xa8) = 0;
    }
    iVar5 = 4;
    do {
      iVar2 = *piVar6;
      if (iVar2 != 0) {
        if ((param_2 & 2) == 0) {
          if ((param_2 & 1) != 0) {
            (**(code **)(iVar2 + 0x10))(iVar2,param_3);
          }
        }
        else {
          (**(code **)(iVar2 + 0x18))(iVar2,param_3);
        }
      }
      piVar6 = piVar6 + 3;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    return 0;
  }
  if (*(int *)(param_1 + 0x68) == 0) {
    uVar4 = FUN_00669720(8);
    *(undefined4 *)(param_1 + 0x68) = uVar4;
    NullUpdate_ret(uVar4);
  }
  FUN_00669430(*(undefined4 *)(param_1 + 0x68),"GmUtil",param_3,&DAT_006b9172,
               "TCP:~1:1024\tUDP:~1:1024",0);
  return 0;
}


// ==== 0x6637b0 FUN_006637b0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006637b0(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint unaff_retaddr;
  uint local_108;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  uVar4 = 0;
  if (*(int *)(param_1 + 0x68) != 0) {
    uVar1 = 0;
    piVar3 = (int *)(param_1 + 0x7c);
    do {
      if (*piVar3 != 0) break;
      uVar1 = uVar1 + 1;
      piVar3 = piVar3 + 3;
    } while (uVar1 < 4);
    if (uVar1 == 4) {
      uVar1 = FUN_00669660(*(int *)(param_1 + 0x68),"GmUtil",param_1 + 0x24,&local_108,0);
      if (uVar1 != 0) {
        if (local_108 < uVar1) {
          *(uint *)(param_1 + 0x74) = local_108;
          *(uint *)(param_1 + 0x70) = uVar1;
          _sprintf(local_104,"%d.%d.%d.%d%s",uVar1 >> 0x18,uVar1 >> 0x10 & 0xff,uVar1 >> 8 & 0xff,
                   uVar1 & 0xff);
          FUN_006635d0(param_1,*(uint *)(param_1 + 0x78) | 2,local_104);
        }
        else {
          *(uint *)(param_1 + 0x70) = local_108;
          *(uint *)(param_1 + 0x74) = uVar1;
          _sprintf(local_104,&DAT_006cc568,param_1 + 0x24);
          FUN_006635d0(param_1,*(uint *)(param_1 + 0x78) | 1,local_104);
        }
      }
    }
  }
  uVar1 = 0;
  piVar3 = (int *)(param_1 + 0x7c);
  do {
    iVar2 = *piVar3;
    if (iVar2 != 0) {
      if (uVar4 == 0) {
        uVar4 = (**(code **)(iVar2 + 0x28))(iVar2);
      }
      iVar2 = (**(code **)(*piVar3 + 0x24))(*piVar3);
      if (iVar2 == 3) {
        if (piVar3[1] == 0) {
          piVar3[1] = uVar4;
        }
        if ((uint)(piVar3[2] + piVar3[1]) <= uVar4) {
          if ((int)uVar1 < 0) {
            return 0;
          }
          uVar4 = 0;
          piVar3 = (int *)(param_1 + 0x7c);
          do {
            if ((uVar4 != uVar1) && (iVar2 = *piVar3, iVar2 != 0)) {
              (**(code **)(iVar2 + 4))(iVar2);
              *piVar3 = 0;
            }
            uVar4 = uVar4 + 1;
            piVar3 = piVar3 + 3;
          } while (uVar4 < 4);
          if (*(int *)(param_1 + 100) != 0) {
            FUN_006698c0(*(int *)(param_1 + 100));
            *(undefined4 *)(param_1 + 100) = 0;
          }
          if (*(int *)(param_1 + 0x68) != 0) {
            FUN_006698c0(*(int *)(param_1 + 0x68));
            *(undefined4 *)(param_1 + 0x68) = 0;
          }
          return *(undefined4 *)(param_1 + 0x7c + uVar1 * 0xc);
        }
      }
    }
    uVar1 = uVar1 + 1;
    piVar3 = piVar3 + 3;
    if (3 < uVar1) {
      return 0;
    }
  } while( true );
}


// ==== 0x663960 FUN_00663960

void FUN_00663960(undefined4 param_1)

{
  FUN_00663570(param_1);
  FUN_00447030(param_1);
  return;
}


// ==== 0x663980 FUN_00663980

int FUN_00663980(void)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined2 uVar3;
  int in_EAX;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int *unaff_ESI;
  undefined4 uStack_4;
  
  bVar2 = false;
  iVar4 = (**(code **)(*unaff_ESI + 0x28))(*unaff_ESI);
  if (unaff_ESI[0x72] == 0) {
    return 1;
  }
  if (0x200 < *(ushort *)(in_EAX + 4)) {
    return -1;
  }
  if (((*(byte *)(in_EAX + 6) & 0x40) != 0) || (0xfa < (uint)(iVar4 - unaff_ESI[5]))) {
    uVar5 = FUN_006625f0(iVar4);
    uVar6 = FUN_006625f0((unaff_ESI[4] - unaff_ESI[3]) + iVar4);
    uVar3 = FUN_006625d0((unaff_ESI[8] + 1 + unaff_ESI[7]) / 2);
    uStack_4 = CONCAT22(uStack_4._2_2_,uVar3);
    puVar1 = (undefined4 *)(*(ushort *)(in_EAX + 4) + 8 + in_EAX);
    *puVar1 = uVar6;
    puVar1[1] = uVar5;
    puVar1[2] = uStack_4;
    *(short *)(in_EAX + 4) = *(short *)(in_EAX + 4) + 0xc;
    *(byte *)(in_EAX + 6) = *(byte *)(in_EAX + 6) | 0x40;
    bVar2 = true;
  }
  *(undefined1 *)(*(ushort *)(in_EAX + 4) + 8 + in_EAX) = *(undefined1 *)(in_EAX + 6);
  iVar7 = (**(code **)(*unaff_ESI + 0x2c))
                    (*unaff_ESI,in_EAX + 8,*(ushort *)(in_EAX + 4) + 1,
                     (*(byte *)(in_EAX + 6) & 0xbf) == 6);
  if (bVar2) {
    *(short *)(in_EAX + 4) = *(short *)(in_EAX + 4) + -0xc;
    *(byte *)(in_EAX + 6) = *(byte *)(in_EAX + 6) ^ 0x40;
  }
  if (0 < iVar7) {
    unaff_ESI[2] = iVar4;
    if (bVar2) {
      unaff_ESI[5] = iVar4;
    }
    unaff_ESI[0x5d] = unaff_ESI[0x5d] + *(ushort *)(in_EAX + 4) + 1;
    unaff_ESI[0x5e] = unaff_ESI[0x5e] + 1;
    unaff_ESI[0xe] = unaff_ESI[0xe] + *(ushort *)(in_EAX + 4) + 1;
    unaff_ESI[0x10] = iVar4;
    if ((unaff_ESI[0x12] != 0) && (100 < (uint)(iVar4 - unaff_ESI[0x12]))) {
      unaff_ESI[0x12] = 0;
      unaff_ESI[0x14] = iVar4;
    }
    if ((unaff_ESI[0x14] != 0) && (100 < (uint)(iVar4 - unaff_ESI[0x14]))) {
      unaff_ESI[0x14] = 0;
      unaff_ESI[0x12] = iVar4;
    }
  }
  return iVar7;
}


// ==== 0x663ae0 FUN_00663ae0

undefined4 FUN_00663ae0(void)

{
  undefined4 *puVar1;
  int *piVar2;
  byte bVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ushort uVar7;
  short sVar8;
  int *in_EAX;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  int local_14;
  int iStack_10;
  undefined4 uStack_4;
  
  if (in_EAX[99] - in_EAX[0x62] < 0x21b) {
    return 0;
  }
  puVar13 = (uint *)(in_EAX[0x61] + in_EAX[0x62]);
  iVar9 = (**(code **)(*in_EAX + 0x34))(*in_EAX,puVar13 + 2,0x210,&local_14);
  if ((0 < iVar9) && (iVar9 < 0x20f)) {
    *(short *)(puVar13 + 1) = (short)iVar9;
    iVar9 = (**(code **)(*in_EAX + 0x28))(*in_EAX);
    in_EAX[9] = iVar9;
    in_EAX[10] = in_EAX[10] + 1;
    in_EAX[0x11] = iVar9;
    in_EAX[0xf] = in_EAX[0xf] + (uint)(ushort)puVar13[1];
    if ((in_EAX[0x13] != 0) && (100 < (uint)(iVar9 - in_EAX[0x13]))) {
      in_EAX[0x13] = 0;
      in_EAX[0x15] = iVar9;
    }
    if ((in_EAX[0x15] != 0) && (100 < (uint)(iVar9 - in_EAX[0x15]))) {
      in_EAX[0x15] = 0;
      in_EAX[0x13] = iVar9;
    }
    *(short *)(puVar13 + 1) = (short)puVar13[1] + -1;
    bVar3 = *(byte *)((ushort)puVar13[1] + 8 + (int)puVar13);
    *(byte *)((int)puVar13 + 6) = bVar3;
    if ((bVar3 & 0x40) != 0) {
      uVar7 = (ushort)puVar13[1] - 0xc;
      *(ushort *)(puVar13 + 1) = uVar7;
      puVar1 = (undefined4 *)(uVar7 + 8 + (int)puVar13);
      uVar5 = *puVar1;
      uVar6 = puVar1[1];
      uStack_4 = puVar1[2];
      *(byte *)((int)puVar13 + 6) = *(byte *)((int)puVar13 + 6) ^ 0x40;
      iVar9 = local_14 - in_EAX[3];
      if (iVar9 < 10) {
        iVar9 = 10;
      }
      in_EAX[3] = local_14;
      iVar10 = FUN_00662640(uVar6);
      in_EAX[4] = iVar10;
      uVar11 = FUN_00662620(uStack_4);
      in_EAX[0xc] = uVar11 & 0xffff;
      sVar8 = FUN_00662640(uVar5);
      sVar8 = (short)in_EAX[3] - sVar8;
      if ((-1 < sVar8) && (sVar8 < 0x9c5)) {
        iVar10 = (int)sVar8;
        if (iVar9 < 0x400) {
          iStack_10 = 0x400 - iVar9;
          iVar12 = iVar10 - in_EAX[7];
          if (iVar12 < 0) {
            iVar12 = -iVar12;
          }
          iVar12 = in_EAX[8] * iStack_10 + iVar12 * iVar9;
          in_EAX[8] = (int)(iVar12 + (iVar12 >> 0x1f & 0x3ffU)) >> 10;
          iVar9 = in_EAX[7] * iStack_10 + iVar10 * iVar9;
          in_EAX[7] = (int)(iVar9 + (iVar9 >> 0x1f & 0x3ffU)) >> 10;
        }
        else {
          in_EAX[7] = iVar10;
          in_EAX[8] = 0;
        }
        in_EAX[0xb] = in_EAX[8] + in_EAX[7];
        if ((uint)(local_14 - in_EAX[6]) < 0xfa) {
          piVar2 = in_EAX + in_EAX[0x1c] * 2 + 0x1d;
          if (iVar10 < (int)(uint)*(ushort *)(in_EAX + in_EAX[0x1c] * 2 + 0x1d)) {
            *(short *)piVar2 = sVar8;
          }
          if ((int)(uint)*(ushort *)((int)piVar2 + 2) < iVar10) {
            *(short *)((int)piVar2 + 2) = sVar8;
          }
          uVar7 = *(ushort *)((int)piVar2 + 6);
          *(ushort *)((int)piVar2 + 6) = uVar7 + 1;
          *(short *)(piVar2 + 1) =
               (short)((int)((uint)*(ushort *)(piVar2 + 1) * (uint)uVar7 + iVar10) /
                      (int)(uVar7 + 1));
        }
        else {
          in_EAX[6] = local_14;
          uVar11 = in_EAX[0x1c] + 1U & 0x1f;
          in_EAX[0x1c] = uVar11;
          *(short *)(in_EAX + uVar11 * 2 + 0x1d) = sVar8;
          *(short *)((int)in_EAX + uVar11 * 8 + 0x76) = sVar8;
          *(short *)(in_EAX + uVar11 * 2 + 0x1e) = sVar8;
          *(undefined2 *)((int)in_EAX + uVar11 * 8 + 0x7a) = 1;
        }
        in_EAX[0x1b] = local_14;
      }
    }
    cVar4 = *(char *)((int)puVar13 + 6);
    if (cVar4 == '\x01') {
      if (0 < (short)puVar13[2]) {
        *(short *)(puVar13 + 2) = (short)puVar13[2] + -1;
        FUN_00663980();
      }
      return 1;
    }
    if (cVar4 == '\x03') {
      (**(code **)(*in_EAX + 0x1c))(*in_EAX);
      return 1;
    }
    if (cVar4 != '\0') {
      uVar11 = (ushort)puVar13[1] + 0xb & 0x7ffc;
      *puVar13 = uVar11;
      in_EAX[0x62] = in_EAX[0x62] + uVar11;
    }
    return 1;
  }
  return 0;
}


// ==== 0x663d90 FUN_00663d90

undefined4 FUN_00663d90(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  if (0 < *(int *)(unaff_ESI + 0x1c4)) {
    return 0;
  }
  *(undefined4 *)(unaff_ESI + 0x1c4) = 1;
  uVar1 = FUN_00663ae0();
  *(undefined4 *)(unaff_ESI + 0x1c4) = 0;
  return uVar1;
}


// ==== 0x663dc0 FUN_00663dc0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_00663dc0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = FUN_00663d90();
  while (0 < iVar3) {
    param_1[0x70] = param_1[0x70] + 1;
    iVar3 = FUN_00663d90();
  }
  param_1[0x6d] = 0;
  iVar3 = (**(code **)(*param_1 + 0x28))(*param_1);
  param_1[9] = iVar3;
  uVar4 = iVar3 - param_1[0x19];
  param_1[10] = param_1[10] + 1;
  if (999 < uVar4) {
    iVar1 = param_1[0x5d];
    iVar2 = *param_1;
    param_1[0x5d] = 0;
    param_1[0x16] = (uint)(iVar1 * 1000) / uVar4;
    iVar1 = param_1[0x5e];
    param_1[0x5e] = 0;
    param_1[0x17] = (uint)(iVar1 * 1000) / uVar4;
    param_1[0x18] =
         (uint)((((*(int *)(iVar2 + 0x60) - param_1[0x60]) * 0x29 - param_1[0x5f]) +
                *(int *)(iVar2 + 0x58)) * 1000) / uVar4;
    param_1[0x5f] = *(int *)(iVar2 + 0x58);
    param_1[0x60] = *(int *)(iVar2 + 0x60);
    param_1[0x19] = iVar3;
  }
  if ((param_1[0x12] != 0) && (100 < (uint)(iVar3 - param_1[0x12]))) {
    param_1[0x12] = 0;
    param_1[0x14] = iVar3;
  }
  if (((param_1[0x14] != 0) && (100 < (uint)(iVar3 - param_1[0x14]))) &&
     ((uint)(iVar3 - param_1[0x10]) < 0x32)) {
    param_1[0x14] = 0;
    param_1[0x12] = iVar3;
  }
  if ((param_1[0x13] != 0) && (100 < (uint)(iVar3 - param_1[0x13]))) {
    param_1[0x13] = 0;
    param_1[0x15] = iVar3;
  }
  if (((param_1[0x15] != 0) && (100 < (uint)(iVar3 - param_1[0x15]))) &&
     ((uint)(iVar3 - param_1[0x11]) < 0x32)) {
    param_1[0x15] = 0;
    param_1[0x13] = iVar3;
  }
  if (((500 < (uint)(iVar3 - param_1[2])) &&
      (iVar3 = (**(code **)(*param_1 + 0x2c))(*param_1,0,0,0), 0 < iVar3)) && (iVar3 < 8)) {
    FUN_00663980();
  }
  return;
}


// ==== 0x663f60 FUN_00663f60

void FUN_00663f60(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x44);
  iVar2 = FUN_00668d10(iVar1 + 400);
  if (iVar2 != 0) {
    FUN_00663dc0();
    if (((0 < *(int *)(iVar1 + 0x188)) && (*(code **)(iVar1 + 0x1bc) != (code *)0x0)) &&
       (0 < *(int *)(iVar1 + 0x1c0))) {
      *(undefined4 *)(iVar1 + 0x1c0) = 0;
      (**(code **)(iVar1 + 0x1bc))(*(undefined4 *)(iVar1 + 0x1b8),1);
    }
    FUN_00668df0(iVar1 + 400);
    return;
  }
  *(int *)(iVar1 + 0x1b4) = *(int *)(iVar1 + 0x1b4) + 1;
  return;
}


// ==== 0x663fe0 FUN_00663fe0

int * FUN_00663fe0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined2 *puVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = (int *)FUN_00549460(0x1cc);
  piVar4 = piVar1;
  for (iVar3 = 0x73; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  *piVar1 = param_1;
  piVar1[1] = param_2;
  if (param_3 < 0x1000) {
    param_3 = 0x1000;
  }
  iVar3 = FUN_00549460(param_3);
  piVar1[0x61] = iVar3;
  piVar1[99] = param_3;
  piVar1[7] = 0;
  piVar1[8] = 0;
  iVar3 = (**(code **)(param_1 + 0x28))(param_1);
  piVar1[0xd] = iVar3;
  piVar1[0x14] = iVar3;
  piVar1[0x15] = iVar3;
  piVar1[0x11] = iVar3;
  piVar1[0x10] = iVar3;
  piVar1[0x19] = iVar3;
  *(undefined1 *)(piVar1 + 0x1a) = 0;
  *(undefined1 *)((int)piVar1 + 0x69) = 0;
  puVar2 = (undefined2 *)((int)piVar1 + 0x76);
  iVar3 = 0x20;
  do {
    puVar2[-1] = 200;
    *puVar2 = 200;
    puVar2[1] = 200;
    puVar2[2] = 1;
    puVar2 = puVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_00668cc0(piVar1 + 100);
  *(int **)(param_1 + 0x44) = piVar1;
  (**(code **)(param_1 + 0x20))(param_1,FUN_00663f60);
  piVar1[0x72] = 1;
  return piVar1;
}


// ==== 0x6640b0 FUN_006640b0

void FUN_006640b0(int *param_1)

{
  (**(code **)(*param_1 + 0x20))(*param_1,0);
  if (param_1[1] != 0) {
    (**(code **)(*param_1 + 4))(*param_1);
  }
  FUN_00447030(param_1[0x61]);
  FUN_00668cf0(param_1 + 100);
  FUN_00447030(param_1);
  return;
}


// ==== 0x664100 FUN_00664100

int * FUN_00664100(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = param_1 + 9;
  do {
    iVar3 = param_1[10];
    iVar2 = (**(code **)(*param_1 + 0x28))(*param_1);
    *piVar1 = iVar2;
  } while (param_1[10] != iVar3);
  iVar3 = (**(code **)(*param_1 + 0x24))(*param_1);
  *(bool *)(param_1 + 0x1a) = iVar3 == 2;
  if ((iVar3 != 2) && (iVar3 != 3)) {
    *(undefined1 *)((int)param_1 + 0x69) = 0;
    return piVar1;
  }
  *(undefined1 *)((int)param_1 + 0x69) = 1;
  return piVar1;
}


// ==== 0x664160 FUN_00664160

int FUN_00664160(int *param_1,uint *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  FUN_00668d60(param_1 + 100);
  for (; 0 < param_3; param_3 = param_3 - uVar2) {
    if (*(char *)((int)param_2 + 6) == '\x03') {
      (**(code **)(*param_1 + 0x1c))(*param_1);
    }
    else {
      iVar1 = FUN_00663980();
      if (iVar1 < 1) break;
    }
    uVar2 = (ushort)param_2[1] + 0x1b & 0x7ffc;
    iVar3 = iVar3 + uVar2;
    *param_2 = uVar2;
    if (param_3 == 1) break;
    param_2 = (uint *)((int)param_2 + uVar2);
  }
  if (0 < param_1[0x6d]) {
    FUN_00663dc0();
  }
  FUN_00668df0(param_1 + 100);
  return iVar3;
}


// ==== 0x6641f0 FUN_006641f0

uint FUN_006641f0(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  iVar1 = param_1 + 400;
  FUN_00668d60(iVar1);
  if (*(int *)(param_1 + 0x188) == 0) {
    do {
      iVar2 = FUN_00663d90();
    } while (0 < iVar2);
  }
  uVar4 = *(uint *)(param_1 + 0x188);
  if (uVar4 != 0) {
    if (param_3 == 1) {
      param_3 = **(int **)(param_1 + 0x184);
    }
    if (param_3 < (int)uVar4) {
      piVar6 = *(int **)(param_1 + 0x184);
      iVar2 = *piVar6;
      uVar4 = 0;
      if (iVar2 <= param_3) {
        do {
          uVar4 = uVar4 + iVar2;
          iVar2 = *(int *)((int)piVar6 + uVar4);
        } while ((int)(iVar2 + uVar4) <= param_3);
        if (0 < (int)uVar4) {
          if (param_2 != (int *)0x0) {
            for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
              *param_2 = *piVar6;
              piVar6 = piVar6 + 1;
              param_2 = param_2 + 1;
            }
            for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
              *(char *)param_2 = (char)*piVar6;
              piVar6 = (int *)((int)piVar6 + 1);
              param_2 = (int *)((int)param_2 + 1);
            }
          }
          uVar5 = *(int *)(param_1 + 0x188) - uVar4;
          puVar7 = (undefined4 *)((int)*(undefined4 **)(param_1 + 0x184) + uVar4);
          puVar8 = *(undefined4 **)(param_1 + 0x184);
          for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
            puVar7 = (undefined4 *)((int)puVar7 + 1);
            puVar8 = (undefined4 *)((int)puVar8 + 1);
          }
          *(int *)(param_1 + 0x188) = *(int *)(param_1 + 0x188) - uVar4;
        }
      }
      FUN_00668df0(iVar1);
      return uVar4;
    }
    if (param_2 != (int *)0x0) {
      piVar6 = *(int **)(param_1 + 0x184);
      for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *param_2 = *piVar6;
        piVar6 = piVar6 + 1;
        param_2 = param_2 + 1;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(char *)param_2 = (char)*piVar6;
        piVar6 = (int *)((int)piVar6 + 1);
        param_2 = (int *)((int)param_2 + 1);
      }
    }
    uVar4 = *(uint *)(param_1 + 0x188);
    *(undefined4 *)(param_1 + 0x188) = 0;
    FUN_00668df0(iVar1);
    return uVar4;
  }
  FUN_00668df0(iVar1);
  return 0;
}


// ==== 0x664310 FUN_00664310

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00664310(undefined4 param_1)

{
  int unaff_ESI;
  uint unaff_retaddr;
  undefined1 local_1004 [4096];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  _vsprintf(local_1004,param_1,&stack0x00000008);
  if (*(code **)(unaff_ESI + 0x700) != (code *)0x0) {
    (**(code **)(unaff_ESI + 0x700))(*(undefined4 *)(unaff_ESI + 0x6fc),local_1004);
  }
  return;
}


// ==== 0x664380 FUN_00664380

void FUN_00664380(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)FUN_00549460(0x44);
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[1] = param_1;
    puVar3[0xf] = param_3;
    puVar3[0xe] = param_2;
    puVar3[0x10] = 0;
    *puVar3 = *(undefined4 *)(in_EAX + 0x704);
    piVar1 = (int *)(in_EAX + 0x6f4);
    *(uint *)(in_EAX + 0x704) = *(int *)(in_EAX + 0x704) + 1U & 0x7fffffff;
    iVar2 = *piVar1;
    while ((iVar2 != 0 && (*(int *)(iVar2 + 4) != 0x70696e67))) {
      piVar1 = (int *)(iVar2 + 0x40);
      iVar2 = *piVar1;
    }
    iVar2 = *piVar1;
    *piVar1 = (int)puVar3;
    puVar3[0x10] = iVar2;
  }
  return;
}


// ==== 0x664400 FUN_00664400

bool __fastcall FUN_00664400(undefined4 param_1,undefined4 *param_2)

{
  int in_EAX;
  int iVar1;
  int unaff_EBX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = param_2;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  puVar3 = *(undefined4 **)(unaff_EBX + 0x6f4);
  if ((puVar3 != (undefined4 *)0x0) && ((puVar3[1] == in_EAX || (in_EAX == 0x44515545)))) {
    *(undefined4 *)(unaff_EBX + 0x6f4) = puVar3[0x10];
    puVar2 = puVar3;
    for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_2 = *puVar2;
      puVar2 = puVar2 + 1;
      param_2 = param_2 + 1;
    }
    FUN_00447030(puVar3);
  }
  return *(int *)(unaff_EBX + 0x6f4) != 0;
}


// ==== 0x664460 FUN_00664460

undefined4 __fastcall FUN_00664460(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int in_EAX;
  int iVar3;
  int unaff_EBX;
  undefined4 *puVar4;
  
  piVar1 = (int *)(unaff_EBX + 0x6f4);
  iVar3 = *piVar1;
  while( true ) {
    if (iVar3 == 0) {
      return 0;
    }
    puVar2 = (undefined4 *)*piVar1;
    if ((puVar2[1] == 0x70696e67) &&
       ((puVar2[2] == param_2 || ((param_2 == -1 && ((int)puVar2[3] < in_EAX)))))) break;
    piVar1 = puVar2 + 0x10;
    iVar3 = *piVar1;
  }
  *piVar1 = puVar2[0x10];
  puVar4 = puVar2;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_3 = *puVar4;
    puVar4 = puVar4 + 1;
    param_3 = param_3 + 1;
  }
  FUN_00447030(puVar2);
  *(int *)(unaff_EBX + 0x6f8) = *(int *)(unaff_EBX + 0x6f8) + -1;
  return 1;
}


// ==== 0x6644d0 FUN_006644d0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006644d0(void)

{
  int iVar1;
  
  do {
    iVar1 = FUN_00664400();
  } while (iVar1 != 0);
  return;
}


// ==== 0x664520 FUN_00664520

void __thiscall FUN_00664520(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  
  if ((((*(int *)(unaff_EBX + 0x4a0) != 0) &&
       (iVar1 = FUN_0066dd40(*(int *)(unaff_EBX + 0x4a0),param_1), iVar1 != 0)) &&
      (iVar2 = FUN_00666ea0(*(undefined4 *)(unaff_EBX + 0x4a4),iVar1), iVar2 != 0)) &&
     (param_2 != *(int *)(iVar2 + 0x10))) {
    *(int *)(iVar2 + 0x10) = param_2;
    _sprintf(iVar2 + 0x14,&DAT_006ca778,param_2);
    FUN_00666e50(*(undefined4 *)(unaff_EBX + 0x4a4),iVar1,iVar2);
  }
  return;
}


// ==== 0x664590 FUN_00664590

void FUN_00664590(void)

{
  int iVar1;
  int unaff_EBX;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar2 = (int *)(unaff_EBX + 0x4a8);
  do {
    if ((piVar2[-2] != 0) && (*piVar2 != 0)) {
      iVar1 = FUN_00666fe0(piVar2[-1]);
      if (0 < iVar1) {
        (*(code *)*piVar2)();
      }
    }
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 5;
  } while (iVar3 < 10);
  return;
}


// ==== 0x664600 FUN_00664600

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00664600(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint unaff_retaddr;
  undefined4 uStack_278;
  undefined4 uStack_274;
  undefined4 uStack_270;
  undefined1 *puStack_26c;
  char acStack_268 [32];
  undefined1 auStack_248 [24];
  char acStack_230 [32];
  code *pcStack_210;
  undefined4 uStack_20c;
  undefined1 auStack_204 [512];
  uint uStack_4;
  
  uStack_4 = DAT_006eb720 ^ unaff_retaddr;
  iVar1 = FUN_00664460(auStack_248,acStack_268);
  if (iVar1 == 0) {
    acStack_268[0] = '\0';
  }
  else {
    _strncpy(acStack_268,acStack_230,0x1f);
    if (pcStack_210 != (code *)0x0) {
      auStack_204[0] = 0;
      FUN_00667950(auStack_204,0x200,&DAT_006bd3bc,acStack_268);
      FUN_00667690(auStack_204,0x200,&DAT_006aac3c,param_1);
      FUN_00667690(auStack_204,0x200,&DAT_006aac34,param_2);
      puStack_26c = auStack_204;
      uStack_278 = 0;
      uStack_274 = 0x70696e67;
      uStack_270 = 0;
      (*pcStack_210)(param_3,&uStack_278,uStack_20c);
    }
  }
  if (*(int *)(param_3 + 0x4a0) != 0) {
    iVar1 = 0;
    iVar2 = FUN_00666f30(*(undefined4 *)(param_3 + 0x4a4),0);
    while (iVar2 != 0) {
      if (*(int *)(iVar2 + 100) == param_1) {
        _sprintf(iVar2 + 0x5c,&DAT_006aac2c,param_2);
        iVar2 = FUN_0064c660(*(undefined4 *)(param_3 + 0x4a4));
        if (iVar1 < iVar2) {
          FUN_00666fc0(*(undefined4 *)(param_3 + 0x4a4),1);
        }
      }
      iVar1 = iVar1 + 1;
      iVar2 = FUN_00666f30(*(undefined4 *)(param_3 + 0x4a4),iVar1);
    }
  }
  if (*(int *)(param_3 + 0x4b4) != 0) {
    iVar1 = 0;
    iVar2 = FUN_00666f30(*(undefined4 *)(param_3 + 0x4b8),0);
    while (iVar2 != 0) {
      iVar3 = __stricmp((char *)(iVar2 + 8),acStack_268);
      if (iVar3 == 0) {
        _sprintf(iVar2 + 0x28,&DAT_006aac2c,param_2);
        FUN_00666fc0(*(undefined4 *)(param_3 + 0x4b8),1);
      }
      iVar1 = iVar1 + 1;
      iVar2 = FUN_00666f30(*(undefined4 *)(param_3 + 0x4b8),iVar1);
    }
  }
  return;
}


// ==== 0x664800 FUN_00664800

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00664800(void)

{
  int iVar1;
  undefined4 *unaff_ESI;
  uint unaff_retaddr;
  undefined4 uVar2;
  undefined4 uStack_268;
  undefined4 uStack_264;
  undefined4 uStack_260;
  undefined1 *puStack_25c;
  undefined1 auStack_248 [8];
  undefined4 uStack_240;
  undefined1 auStack_230 [32];
  code *pcStack_210;
  undefined1 auStack_204 [512];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  FUN_006688b0(unaff_ESI[1]);
  uVar2 = *unaff_ESI;
  GetTickCount();
  iVar1 = FUN_00664460(auStack_248,&uStack_268,uVar2);
  while (iVar1 != 0) {
    if (pcStack_210 != (code *)0x0) {
      puStack_25c = auStack_204;
      uStack_268 = 0;
      uStack_264 = 0x70696e67;
      uStack_260 = 0xffffffff;
      auStack_204[0] = 0;
      FUN_00667950(auStack_204,0x200,&DAT_006bd3bc,auStack_230);
      FUN_00667690(auStack_204,0x200,&DAT_006aac3c,uStack_240);
      FUN_00667690(auStack_204,0x200,&DAT_006aac34,0);
      (*pcStack_210)();
    }
    iVar1 = FUN_00664460(auStack_248,&uStack_268);
  }
  return;
}


// ==== 0x664920 FUN_00664920

void FUN_00664920(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x18) = 0;
  *(undefined4 *)(in_EAX + 0x1c) = 0xffffffff;
  *(undefined4 *)(in_EAX + 0x20) = 0;
  return;
}


// ==== 0x664930 FUN_00664930

void __thiscall FUN_00664930(uint param_1,undefined4 param_2)

{
  int in_EAX;
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(uint *)(in_EAX + 8) = *(uint *)(in_EAX + 8) | param_1;
  *(undefined4 *)(in_EAX + 0xc) = 0x7465726d;
  iVar1 = FUN_00664920();
  if (*(code **)(iVar1 + 0x6e4) != (code *)0x0) {
    local_8 = param_2;
    local_10 = 3;
    local_c = 0x64697363;
    local_4 = 0;
    (**(code **)(iVar1 + 0x6e4))(iVar1,&local_10,*(undefined4 *)(iVar1 + 0x6e8));
  }
  return;
}


// ==== 0x664990 FUN_00664990

void FUN_00664990(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  param_1[3] = 0x6f66666c;
  FUN_0066e040(*param_1);
  piVar4 = param_1 + 0x128;
  iVar3 = 10;
  do {
    if (*piVar4 != 0) {
      iVar1 = FUN_0066dac0(*piVar4);
      while (iVar1 != 0) {
        uVar2 = FUN_00666eb0(piVar4[1],iVar1);
        FUN_00447030(uVar2);
        iVar1 = FUN_0066dac0(*piVar4);
      }
    }
    piVar4 = piVar4 + 5;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = param_1[0x1bd];
  while (iVar3 != 0) {
    iVar3 = param_1[0x1bd];
    param_1[0x1bd] = *(undefined4 *)(iVar3 + 0x40);
    FUN_00447030(iVar3);
    iVar3 = param_1[0x1bd];
  }
  FUN_00664920();
  param_1[0x1be] = 0;
  param_1[0x1c1] = 0;
  return;
}


// ==== 0x664a40 FUN_00664a40

void FUN_00664a40(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  
  FUN_00664990(param_1);
  piVar1 = param_1 + 0x128;
  iVar2 = 10;
  do {
    if (*piVar1 != 0) {
      FUN_0066da20(*piVar1);
      FUN_00666da0(piVar1[1]);
    }
    piVar1 = piVar1 + 5;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_00668870(param_1[1]);
  FUN_0066def0(*param_1);
  FUN_00447030(param_1);
  return;
}


// ==== 0x664aa0 FUN_00664aa0

void FUN_00664aa0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x6cc + param_2 * 8) = param_3;
  *(undefined4 *)(param_1 + 0x6d0 + param_2 * 8) = param_4;
  return;
}


// ==== 0x664ac0 FUN_00664ac0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00664ac0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  DWORD DVar2;
  uint unaff_retaddr;
  undefined1 auStack_104 [256];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  param_1[0x15a] = param_3;
  param_1[0x15b] = param_2;
  FUN_006644d0();
  param_1[0x1b1] = 0;
  FUN_00664920();
  iVar1 = FUN_00664380(0x736b6579,param_4,param_5);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  FUN_0066e040(*param_1);
  FUN_0066dfd0(*param_1,param_1[0x15b],param_1[0x15a]);
  FUN_00664310("connecting to %08x:%d\n",param_1[0x15b],param_1[0x15a]);
  FUN_00667650(auStack_104,0x100,param_1 + 0xd);
  FUN_0066e6a0(*param_1,0x40646972,0,auStack_104,0xffffffff);
  param_1[3] = 0x72646972;
  DVar2 = GetTickCount();
  param_1[4] = DVar2 + 120000;
  DVar2 = GetTickCount();
  param_1[5] = DVar2;
  *(undefined1 *)(param_1 + 0x15c) = 0;
  return 0;
}


// ==== 0x664c00 FUN_00664c00

undefined4 FUN_00664c00(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((-1 < param_2) && (param_2 < 10)) {
    param_1 = param_1 + param_2 * 0x14;
    *(undefined4 *)(param_1 + 0x4a8) = param_3;
    *(undefined4 *)(param_1 + 0x4ac) = param_4;
    uVar1 = FUN_0066ddd0(1000,2000);
    *(undefined4 *)(param_1 + 0x4a0) = uVar1;
    uVar1 = FUN_00666d60(100,100,0);
    *(undefined4 *)(param_1 + 0x4a4) = uVar1;
    FUN_006670b0(uVar1,*(undefined4 *)(param_1 + 0x4a0));
    uVar1 = *(undefined4 *)(param_1 + 0x4a4);
  }
  return uVar1;
}


// ==== 0x664c70 FUN_00664c70

void FUN_00664c70(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (((-1 < param_2) && (param_2 < 10)) && (param_3 != 0)) {
    uVar1 = FUN_006670c0(param_3);
    iVar2 = FUN_0066dac0(uVar1);
    while (iVar2 != 0) {
      uVar3 = FUN_00666eb0(param_3,iVar2);
      FUN_00447030(uVar3);
      iVar2 = FUN_0066dac0(uVar1);
    }
    FUN_0066da20(uVar1);
    FUN_00666da0(param_3);
    param_1 = param_1 + param_2 * 0x14;
    if (*(int *)(param_1 + 0x4a4) == param_3) {
      *(undefined4 *)(param_1 + 0x4a0) = 0;
      *(undefined4 *)(param_1 + 0x4a4) = 0;
    }
    *(undefined4 *)(param_1 + 0x4a8) = 0;
    *(undefined4 *)(param_1 + 0x4ac) = 0;
  }
  return;
}


// ==== 0x664d00 FUN_00664d00

undefined4 FUN_00664d00(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((-1 < param_2) && (param_2 < 10)) &&
     (iVar1 = *(int *)(param_1 + 0x4a0 + param_2 * 0x14), iVar1 != 0)) {
    uVar2 = FUN_0066dc20(iVar1,param_3);
    return uVar2;
  }
  return 0;
}


// ==== 0x664d40 FUN_00664d40

undefined4 FUN_00664d40(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((-1 < param_2) && (param_2 < 10)) &&
     (iVar1 = *(int *)(param_1 + 0x4a0 + param_2 * 0x14), iVar1 != 0)) {
    uVar2 = FUN_0066dd40(iVar1,param_3);
    return uVar2;
  }
  return 0;
}


// ==== 0x664d80 FUN_00664d80

uint FUN_00664d80(int param_1,int param_2)

{
  if ((param_2 == 0x75736572) || (param_2 == 0x61636374)) {
    return param_1 + 0x134;
  }
  if (param_2 == 0x70657273) {
    return param_1 + 0x174;
  }
  if (param_2 == 0x726f6f6d) {
    return param_1 + 0x1c0;
  }
  if (param_2 == 0x706c6179) {
    if (*(int *)(param_1 + 0x45c) != 0) {
      return param_1 + 0x200;
    }
  }
  else if (param_2 == 0x646f776e) {
    return param_1 + 0x570U & -(uint)(*(char *)(param_1 + 0x570) != '\0');
  }
  return 0;
}


// ==== 0x664e00 FUN_00664e00

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00664e00(undefined4 *param_1,int param_2,undefined1 *param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint unaff_retaddr;
  undefined1 local_224;
  undefined1 local_223 [31];
  undefined1 local_204 [512];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  iVar3 = param_1[3];
  if ((((iVar3 != 0x69646c65) && (iVar3 != 0x61757468)) && (iVar3 != 0x61636374)) &&
     (iVar3 != 0x736b6579)) {
    return 0xffffffff;
  }
  puVar1 = (undefined4 *)FUN_00664380(param_2,param_4,param_5);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xfffffffe;
  }
  else {
    if (((param_2 == 0x61757468) || (param_2 == 0x61636374)) || (param_2 == 0x70617373)) {
      FUN_00667650(local_204,0x200,param_3);
      FUN_00667d10(local_204,0x200,param_1 + 0xd);
      uVar2 = FUN_00667530(local_204,&DAT_006bd1cc,local_223,0x1f,&DAT_006b9172);
      FUN_00668130(uVar2);
      if (*(char *)(param_1 + 9) == '\0') {
        FUN_00667b60(local_204,0x200,&DAT_006bd1cc,param_1 + 0x19d,local_223);
        FUN_00667690(local_204,0x200,&DAT_006aac5c,param_1[0x19c]);
        param_3 = local_204;
      }
      else {
        local_224 = 0x7e;
        FUN_0066ea80(local_223,0x1f,local_223,param_1 + 9,0x10,0x10);
        FUN_00667950(local_204,0x200,&DAT_006bd1cc,&local_224);
        param_3 = local_204;
      }
    }
    if (param_2 == 0x736e6170) {
      uVar2 = FUN_00667530(param_3,&DAT_006bd368,0);
      iVar3 = FUN_00667ec0(uVar2);
      if ((5 < iVar3) && (iVar3 < 10)) {
        if (param_1[iVar3 * 5 + 0x128] != 0) {
          iVar4 = FUN_0066dac0(param_1[iVar3 * 5 + 0x128]);
          while (iVar4 != 0) {
            uVar2 = FUN_00666eb0(param_1[iVar3 * 5 + 0x129],iVar4);
            FUN_00447030(uVar2);
            iVar4 = FUN_0066dac0(param_1[iVar3 * 5 + 0x128]);
          }
        }
      }
      param_1[0x1b0] = 0;
      param_1[0x1b1] = param_1[0x1b1] + 1;
    }
    FUN_0066e6a0(*param_1,param_2,0,param_3,0xffffffff);
    uVar2 = *puVar1;
  }
  return uVar2;
}


// ==== 0x665060 FUN_00665060

undefined4
FUN_00665060(int param_1,char *param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  DWORD DVar3;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if ((((iVar1 != 0x636f6e6e) && (iVar1 != 0x69646c65)) && (iVar1 != 0x61757468)) &&
     (iVar1 != 0x61636374)) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 4) == 0) {
    return 0xfffffffe;
  }
  if (0x3f < *(int *)(param_1 + 0x6f8)) {
    return 0xfffffffd;
  }
  puVar2 = (undefined4 *)FUN_00664380(0x70696e67,param_5,param_6);
  if (puVar2 == (undefined4 *)0x0) {
    return 0xfffffffc;
  }
  *(int *)(param_1 + 0x6f8) = *(int *)(param_1 + 0x6f8) + 1;
  puVar2[2] = param_3;
  DVar3 = GetTickCount();
  puVar2[3] = DVar3 + param_4;
  _strncpy((char *)(puVar2 + 6),param_2,0x1f);
  FUN_00668b40(*(undefined4 *)(param_1 + 4),param_3,FUN_00664600,param_1);
  return *puVar2;
}


// ==== 0x665120 FUN_00665120

uint FUN_00665120(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 8);
  uVar2 = uVar1 - 1 & uVar1;
  *(uint *)(param_1 + 8) = uVar2;
  return uVar2 ^ uVar1;
}


// ==== 0x665140 FUN_00665140

void FUN_00665140(undefined4 param_1,int param_2)

{
  char *pcVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_2 + 8);
  iVar5 = *(int *)(param_2 + 4);
  pcVar1 = *(char **)(param_2 + 0xc);
  if (iVar4 == 0) {
    iVar4 = 0x2d2d2d2d;
  }
  if (iVar5 == -1) {
    iVar5 = 0x2a2a2a2a;
    if (iVar4 == -1) {
      iVar4 = 0x636f6e6e;
    }
    else {
      iVar4 = ((iVar4 != -0x1010102) - 1 & 0x373c4636) + 0x2d2d2d2d;
    }
  }
  FUN_00664310("recv: %c%c%c%c/%c%c%c%c\n",iVar5 >> 0x18,iVar5 >> 0x10,iVar5 >> 8,iVar5,
               iVar4 >> 0x18,iVar4 >> 0x10,iVar4 >> 8,iVar4);
  cVar3 = *pcVar1;
  iVar4 = 0;
  bVar2 = false;
  if (cVar3 != '\0') {
    do {
      if (cVar3 == '\x7f') break;
      if ((((cVar3 < ' ') && (cVar3 != '\t')) && (cVar3 != '\n')) && (cVar3 != '\r')) {
        bVar2 = true;
        break;
      }
      cVar3 = pcVar1[iVar4 + 1];
      iVar4 = iVar4 + 1;
    } while (cVar3 != '\0');
    if (iVar4 != 0) {
      if (bVar2) {
        FUN_00664310(" [binary data]\n");
        return;
      }
      if (iVar4 < 0xf1) {
        FUN_00664310(&DAT_006cc580,pcVar1);
        return;
      }
      FUN_00664310(" [long data]\n");
      return;
    }
  }
  FUN_00664310(" [null data]\n");
  return;
}


// ==== 0x665240 FUN_00665240

void FUN_00665240(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  DWORD DVar3;
  
  if (*(int *)(param_2 + 4) == 0x70696e67) {
    uVar1 = FUN_00667530(*(undefined4 *)(param_2 + 0xc),&DAT_006aac34,0);
    iVar2 = FUN_00667ec0(uVar1);
    if (iVar2 == 0) {
      FUN_00664310("server ICMP timeout\n");
      iVar2 = *(int *)(param_1 + 0x20) + 1;
      *(int *)(param_1 + 0x20) = iVar2;
      if (iVar2 != 3) {
        DVar3 = GetTickCount();
        *(DWORD *)(param_1 + 0x18) = DVar3;
        return;
      }
    }
    else {
      *(int *)(param_1 + 0x1c) = iVar2;
      DVar3 = GetTickCount();
      *(DWORD *)(param_1 + 0x18) = DVar3 + 30000;
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}


// ==== 0x6652b0 FUN_006652b0

void FUN_006652b0(void)

{
  int unaff_ESI;
  
  FUN_00668bc0(*(undefined4 *)(unaff_ESI + 4),*(undefined4 *)(unaff_ESI + 0x56c));
  FUN_00665060();
  return;
}


// ==== 0x6652f0 FUN_006652f0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006652f0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint unaff_retaddr;
  undefined1 local_24 [32];
  uint local_4;
  
  puVar1 = param_1;
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  uVar2 = FUN_00667530(param_2,"IDENT",0xffffffff);
  uVar2 = FUN_00667ec0(uVar2);
  *param_1 = uVar2;
  uVar2 = FUN_00667530(param_2,&DAT_006bd3bc,param_1 + 1,0x20,&DAT_006b9172);
  FUN_00668130(uVar2);
  uVar2 = FUN_00667530(param_2,&DAT_006bd28c,param_1 + 0x11,0x20,&DAT_006b9172);
  FUN_00668130(uVar2);
  uVar2 = FUN_00667530(param_2,&DAT_006aad28,param_1 + 0x19,0x20,&DAT_006b9172);
  FUN_00668130(uVar2);
  uVar2 = FUN_00667530(param_2,"PARAMS",param_1 + 0x71,0x80,&DAT_006b9172);
  FUN_00668130(uVar2);
  uVar2 = FUN_00667530(param_2,"USERFLAGS",0);
  uVar2 = FUN_00667ec0(uVar2);
  param_1[0x91] = uVar2;
  uVar2 = FUN_00667530(param_2,"SYSFLAGS",0);
  uVar2 = FUN_00667ec0(uVar2);
  param_1[0x92] = uVar2;
  uVar2 = FUN_00667530(param_2,"COUNT",0);
  uVar2 = FUN_00667ec0(uVar2);
  param_1[0x93] = uVar2;
  uVar2 = FUN_00667530(param_2,&DAT_006bd320,0);
  uVar2 = FUN_00668590(uVar2);
  param_1[0x97] = uVar2;
  uVar2 = FUN_00667530(param_2,"MINSIZE",0);
  uVar2 = FUN_00667ec0(uVar2);
  param_1[0x94] = uVar2;
  uVar2 = FUN_00667530(param_2,"MAXSIZE",0);
  uVar2 = FUN_00667ec0(uVar2);
  param_1[0x95] = uVar2;
  uVar2 = FUN_00667530(param_2,&DAT_006aacf0,param_1 + 9,0x20,&DAT_006b9172);
  FUN_00668130(uVar2);
  uVar2 = FUN_00667530(param_2,&DAT_006bd328,param_1 + 0x98,0x40,&DAT_006b9172);
  FUN_00668130(uVar2);
  uVar2 = FUN_00667530(param_2,&DAT_006aace8,0);
  uVar2 = FUN_00667ec0(uVar2);
  param_1[0x96] = uVar2;
  iVar4 = 0;
  if (0 < (int)param_1[0x93]) {
    puVar3 = param_1 + 0x61;
    param_1 = param_1 + 0x21;
    do {
      _sprintf(local_24,"OPPO%d",iVar4);
      uVar2 = FUN_00667530(param_2,local_24,param_1,0x20,&DAT_006b9172);
      FUN_00668130(uVar2);
      _sprintf(local_24,"ADDR%d",iVar4);
      uVar2 = FUN_00667530(param_2,local_24,0);
      uVar2 = FUN_00667f50(uVar2);
      puVar3[8] = uVar2;
      _sprintf(local_24,"OPID%d",iVar4);
      uVar2 = FUN_00667530(param_2,local_24,0);
      uVar2 = FUN_00667ec0(uVar2);
      *puVar3 = uVar2;
      iVar4 = iVar4 + 1;
      param_1 = param_1 + 8;
      puVar3 = puVar3 + 1;
    } while (iVar4 < (int)puVar1[0x93]);
  }
  return;
}


// ==== 0x6655c0 FUN_006655c0

undefined4 * FUN_006655c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)FUN_00549460(0x708);
  if (puVar1 != (undefined4 *)0x0) {
    puVar4 = puVar1;
    for (iVar3 = 0x1c2; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    if (param_1 != 0) {
      iVar3 = _strchr(param_1,0x3d);
      if (iVar3 == 0) {
        FUN_00667950(puVar1 + 0xd,0x100,&DAT_006bd138,param_1);
      }
      else {
        FUN_00667650(puVar1 + 0xd,0x100);
      }
    }
    uVar2 = FUN_0066de50(0x8000);
    *puVar1 = uVar2;
    uVar2 = FUN_006687e0(0x40);
    puVar1[1] = uVar2;
    puVar1[0x1bf] = param_2;
    puVar1[0x1c0] = param_3;
    FUN_00664990(puVar1);
  }
  return puVar1;
}


// ==== 0x665660 FUN_00665660

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00665660(int *param_1)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  char *pcVar12;
  int *piVar13;
  byte *pbVar14;
  undefined4 *puVar15;
  int iVar16;
  int *piVar17;
  undefined4 *puVar18;
  uint unaff_retaddr;
  undefined1 *puStack_370;
  int iStack_36c;
  uint uStack_368;
  int iStack_364;
  undefined4 uStack_360;
  int iStack_35c;
  uint uStack_358;
  undefined1 *puStack_354;
  uint local_350;
  int *piStack_34c;
  code *pcStack_310;
  undefined4 uStack_30c;
  undefined1 auStack_304 [256];
  byte bStack_204;
  byte abStack_203 [511];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  if (*param_1 != 0) {
    uVar3 = GetTickCount();
    local_350 = uVar3;
    if (param_1[3] != 0x6f66666c) {
      iVar4 = param_1[5];
      if ((iVar4 != 0) && (5000 < (int)(uVar3 - iVar4))) {
        param_1[4] = param_1[4] + (uVar3 - iVar4);
      }
      if ((int)(param_1[4] - uVar3) < 0) {
        FUN_00664930(0x74696d65);
      }
    }
    param_1[5] = uVar3;
    if ((param_1[3] != 0x7465726d) && (param_1[3] != 0x6f66666c)) {
      FUN_00664800();
      iVar4 = FUN_0066e780(*param_1,&iStack_36c,&uStack_368,&puStack_370);
      while (-1 < iVar4) {
        param_1[4] = uVar3 + 60000;
        if (iStack_36c == 0x7e706e67) {
          if (param_1[7] != -1) {
            FUN_00667650(auStack_304,0x100,puStack_370);
            FUN_00667690(auStack_304,0x100,&DAT_006aadac,param_1[7]);
            puStack_370 = auStack_304;
            iVar4 = -1;
          }
          FUN_0066e6a0(*param_1,iStack_36c,uStack_368,puStack_370,iVar4);
        }
        else {
          uStack_360 = 0;
          iStack_35c = iStack_36c;
          uStack_358 = uStack_368;
          puStack_354 = puStack_370;
          if ((code *)param_1[0x1b3] != (code *)0x0) {
            (*(code *)param_1[0x1b3])(param_1,&uStack_360,param_1[0x1b4]);
          }
          FUN_00664400();
          if (pcStack_310 != (code *)0x0) {
            (*pcStack_310)(param_1,&uStack_360,uStack_30c);
          }
          if (param_1[3] == 0x72646972) {
            if (iStack_36c == 0x40646972) {
              uVar5 = FUN_0066df40(*param_1,0x6c707274);
              iVar4 = FUN_0066df40(*param_1,0x6c616472);
              param_1[0x1ae] = iVar4;
              iVar4 = FUN_00667530(puStack_370,"DIRECT");
              if (iVar4 == 0) {
                uVar6 = FUN_00667530(puStack_370,&DAT_006aac3c,0);
                iVar4 = FUN_00667f50(uVar6);
                param_1[0x15b] = iVar4;
                uVar6 = FUN_00667530(puStack_370,&DAT_006aad9c,0);
                iVar4 = FUN_00667ec0(uVar6);
                param_1[0x15a] = iVar4;
              }
              uVar6 = FUN_00667530(puStack_370,&DAT_006aad94,0);
              iVar4 = FUN_00667ec0(uVar6);
              param_1[0x19c] = iVar4;
              uVar6 = FUN_00667530(puStack_370,&DAT_006aac5c,param_1 + 0x19d,0x40,&DAT_006b9172);
              FUN_00668130(uVar6);
              FUN_0066e040(*param_1);
              if (param_1[0x15b] != 0) {
                param_1[3] = 0x636f6e6e;
                FUN_006652b0();
                FUN_00664310("connecting to %08x:%d\n",param_1[0x15b],param_1[0x15a]);
                FUN_0066dfd0(*param_1,param_1[0x15b],param_1[0x15a]);
                auStack_304[0] = 0;
                FUN_006677e0(auStack_304,0x100,&DAT_006aac3c,param_1[0x1ae]);
                FUN_00667690(auStack_304,0x100,&DAT_006aad9c,uVar5);
                FUN_0066e6a0(*param_1,0x61646472,0,auStack_304,0xffffffff);
                break;
              }
              uVar5 = FUN_00667530(puStack_370,&DAT_006aad8c,param_1 + 0x15c,0x100,&DAT_006b9172);
              FUN_00668130(uVar5);
              param_1[2] = param_1[2] | 0x400;
            }
            iStack_36c = 0;
          }
          else if ((iStack_36c == -1) && (uStack_368 == 0xffffffff)) {
            auStack_304[0] = 0;
            FUN_00667aa0(auStack_304,0x100,&DAT_006aad84,"Public Key",10);
            FUN_0066e6a0(*param_1,0x736b6579,0,auStack_304,0xffffffff);
            param_1[0x1af] = 1;
            param_1[3] = 0x736b6579;
            iStack_36c = 0x636f6e6e;
            uStack_368 = 0;
            goto LAB_00666b17;
          }
          if ((param_1[3] == 0x736b6579) &&
             (((iStack_36c == 0x736b6579 || (iStack_36c == 0x73656c65)) && (uStack_368 == 0)))) {
            if (iStack_36c == 0x736b6579) {
              uVar5 = FUN_00667530(puStack_370,&DAT_006aad84,param_1 + 9,0x10);
              FUN_00668270(uVar5);
            }
            param_1[2] = param_1[2] | 1;
            param_1[3] = 0x69646c65;
            iStack_36c = 0x636f6e6e;
            uStack_368 = 0;
            param_1[6] = uVar3;
            if ((code *)param_1[0x1b9] == (code *)0x0) goto LAB_00666b17;
            uStack_358 = 0;
            puStack_354 = (undefined1 *)0x0;
            uStack_360 = 3;
            iStack_35c = 0x636f6e6e;
            (*(code *)param_1[0x1b9])(param_1,&uStack_360,param_1[0x1ba]);
          }
          if ((iStack_36c == -1) && (uStack_368 == 0xfefefefe)) {
            if (param_1[3] == 0x636f6e6e) goto LAB_00666b17;
            FUN_00664930(0xfefefefe);
          }
          if (uStack_368 == 0x61757468) {
            FUN_00664930(0x61757468);
          }
          if (iStack_36c == 0x61757468) {
            if (uStack_368 != 0) goto LAB_00666b17;
            param_1[2] = param_1[2] | 2;
            param_1[3] = 0x61757468;
            uVar5 = FUN_00667530(puStack_370,&DAT_006bd3bc,param_1 + 0x4d,0x40,&DAT_006b9172);
            FUN_00668130(uVar5);
            uVar5 = FUN_00667530(puStack_370,&DAT_006aac3c,0);
            iVar4 = FUN_00667f50(uVar5);
            param_1[0x1ad] = iVar4;
          }
          if (iStack_36c == 0x61636374) {
            if (uStack_368 == 0) {
              param_1[3] = 0x61636374;
              param_1[2] = param_1[2] | 2;
            }
          }
          else {
            if (iStack_36c == 0x736e6170) {
              piVar13 = param_1 + 0x1b1;
              *piVar13 = *piVar13 + -1;
              if ((*piVar13 != 0) || (uStack_368 != 0)) goto LAB_00666b17;
              uVar5 = FUN_00667530(puStack_370,&DAT_006bd368,0);
              iVar4 = FUN_00667ec0(uVar5);
              param_1[0x1b0] = iVar4;
            }
            if (iStack_36c == 0x73656c65) {
              if (uStack_368 != 0) goto LAB_00666b17;
              uVar5 = FUN_00667530(puStack_370,&DAT_006aad70,0);
              iVar4 = FUN_00667ec0(uVar5);
              param_1[0x1af] = iVar4;
              uVar5 = FUN_00667530(puStack_370,"SLOTS",0);
              iVar4 = FUN_00667ec0(uVar5);
              param_1[0x1b2] = iVar4;
            }
            if (iStack_36c == 0x70657273) {
              if (uStack_368 != 0) goto LAB_00666b17;
              uVar5 = FUN_00667530(puStack_370,&DAT_006bd3c4,param_1 + 0x5d,0x40,&DAT_006b9172);
              FUN_00668130(uVar5);
              param_1[6] = uVar3;
            }
            if (iStack_36c == 0x2b736573) {
              piVar13 = param_1 + 0x80;
              for (iVar4 = 0xa8; iVar4 != 0; iVar4 = iVar4 + -1) {
                *piVar13 = 0;
                piVar13 = piVar13 + 1;
              }
              FUN_006652f0(param_1 + 0x80,puStack_370);
              param_1[2] = param_1[2] | 0x200;
              if ((code *)param_1[0x1bb] != (code *)0x0) {
                puStack_354 = puStack_370;
                uStack_360 = 4;
                iStack_35c = 0x706c6179;
                uStack_358 = 0;
                (*(code *)param_1[0x1bb])(param_1,&uStack_360,param_1[0x1bc]);
              }
            }
            if (iStack_36c == 0x2b6d7367) {
              if (param_1[0x1b5] == 0) goto LAB_00666b17;
              uStack_360 = 1;
              iStack_35c = 0x63686174;
              uStack_358 = 0;
              puStack_354 = puStack_370;
              uVar5 = FUN_00667530(puStack_370,&DAT_006aad64,0);
              uStack_358 = FUN_00667f10(uVar5);
              if ((uStack_358 & 4) != 0) {
                iStack_35c = 0x63617374;
              }
              if ((uStack_358 & 0x10000) != 0) {
                iStack_35c = 0x70726976;
              }
              (*(code *)param_1[0x1b5])(param_1,&uStack_360,param_1[0x1b6]);
            }
            if (iStack_36c == 0x2b77686f) {
              uVar5 = FUN_00667530(puStack_370,&DAT_006bd2ec,param_1 + 0x5d,0x40,&DAT_006b9172);
              FUN_00668130(uVar5);
              uVar5 = FUN_00667530(puStack_370,&DAT_006aad64,0);
              iVar4 = FUN_00667f10(uVar5);
              param_1[0x6d] = iVar4;
              uVar5 = FUN_00667530(puStack_370,&DAT_006aad60,0);
              iVar4 = FUN_00667ec0(uVar5);
              uVar5 = FUN_00667530(puStack_370,&DAT_006aad5c,0);
              uVar5 = FUN_00667ec0(uVar5);
              if (iVar4 != param_1[0x6e]) {
                param_1[0x6e] = iVar4;
                FUN_00664520(uVar5);
                uVar5 = FUN_00667530(puStack_370,&DAT_006a9714,param_1 + 0x70,0x40,&DAT_006b9172);
                FUN_00668130(uVar5);
                uVar5 = FUN_00667530(puStack_370,&DAT_006aad58,0);
                iVar4 = FUN_00667f10(uVar5);
                param_1[0x6f] = iVar4;
                param_1[2] = param_1[2] | 8;
                if (param_1[0x12d] != 0) {
                  iVar4 = FUN_0066dac0(param_1[0x12d]);
                  while (iVar4 != 0) {
                    uVar5 = FUN_00666eb0(param_1[0x12e],iVar4);
                    FUN_00447030(uVar5);
                    iVar4 = FUN_0066dac0(param_1[0x12d]);
                  }
                  param_1[2] = param_1[2] | 0x40;
                }
              }
            }
            if (iStack_36c == 0x2b726f6d) {
              if (param_1[0x128] == 0) goto LAB_00666b17;
              uVar5 = FUN_00667530(puStack_370,&DAT_0069edd8,0xffffffff);
              iVar4 = FUN_00667ec0(uVar5);
              if (-1 < iVar4) {
                iVar7 = FUN_00667530(puStack_370,&DAT_006bd2ec);
                if (iVar7 == 0) {
                  iVar7 = FUN_0066dd40(param_1[0x128],iVar4);
                  if (iVar7 != 0) {
                    FUN_0066dd80(param_1[0x128],iVar4);
                    uVar5 = FUN_00666eb0(param_1[0x129],iVar7);
                    FUN_00447030(uVar5);
                    param_1[2] = param_1[2] | 0x20;
                  }
                }
                else {
                  piVar8 = (int *)FUN_00549460(0x68);
                  piVar13 = piVar8;
                  for (iVar7 = 0x1a; iVar7 != 0; iVar7 = iVar7 + -1) {
                    *piVar13 = 0;
                    piVar13 = piVar13 + 1;
                  }
                  *piVar8 = iVar4;
                  uVar5 = FUN_00667530(puStack_370,&DAT_006bd2ec,piVar8 + 7,0x20,&DAT_006b9172);
                  FUN_00668130(uVar5);
                  uVar5 = FUN_00667530(puStack_370,&DAT_006aad54,piVar8 + 0xf,0x20,&DAT_006b9172);
                  FUN_00668130(uVar5);
                  uVar5 = FUN_00667530(puStack_370,&DAT_006aad64,0xffffffff);
                  iVar4 = FUN_00667f10(uVar5);
                  piVar8[2] = iVar4;
                  uVar5 = FUN_00667530(puStack_370,&DAT_006a9718,0);
                  iVar4 = FUN_00667f50(uVar5);
                  piVar8[0x19] = iVar4;
                  uVar5 = FUN_00667530(puStack_370,&DAT_006bd2e8,0);
                  iVar4 = FUN_00667ec0(uVar5);
                  piVar8[4] = iVar4;
                  uVar5 = FUN_00667530(puStack_370,&DAT_006aad50,0);
                  iVar4 = FUN_00667ec0(uVar5);
                  piVar8[3] = iVar4;
                  _sprintf(piVar8 + 5,&DAT_006ca778,piVar8[4]);
                  pcVar12 = "No";
                  if ((piVar8[2] & 0x10000U) == 0) {
                    pcVar12 = "Yes";
                  }
                  piVar13 = piVar8 + 6;
                  do {
                    cVar1 = *pcVar12;
                    pcVar12 = pcVar12 + 1;
                    *(char *)piVar13 = cVar1;
                    piVar13 = (int *)((int)piVar13 + 1);
                  } while (cVar1 != '\0');
                  piVar13 = piVar8 + 0x17;
                  *(undefined1 *)piVar13 = 0;
                  uVar5 = FUN_00667530(puStack_370,&DAT_006aad4c,0xffffffff);
                  iVar4 = FUN_00667ec0(uVar5);
                  if (iVar4 == 0) {
                    *piVar13 = 0x2d2d2d;
                  }
                  else if (0 < iVar4) {
                    _sprintf(piVar13,"~%dms",iVar4);
                  }
                  iVar4 = FUN_0066dd40(param_1[0x128],*piVar8);
                  if (iVar4 == 0) {
                    uVar5 = FUN_00666de0(param_1[0x129],piVar8);
                    FUN_0066dcd0(param_1[0x128],*piVar8,uVar5);
                  }
                  else {
                    iVar7 = FUN_00666ea0(param_1[0x129],iVar4);
                    if (iVar7 != 0) {
                      pcVar12 = (char *)(iVar7 + 0x5c);
                      if (('/' < *(char *)(iVar7 + 0x5c)) && (*(char *)(iVar7 + 0x5c) < ':')) {
                        iVar16 = (int)piVar13 - (int)pcVar12;
                        do {
                          cVar1 = *pcVar12;
                          pcVar12[iVar16] = cVar1;
                          pcVar12 = pcVar12 + 1;
                        } while (cVar1 != '\0');
                      }
                    }
                    FUN_00447030(iVar7);
                    FUN_00666e50(param_1[0x129],iVar4,piVar8);
                  }
                }
                param_1[2] = param_1[2] | 0x20;
              }
            }
            if (iStack_36c == 0x2b706f70) {
              uVar3 = local_350;
              if (param_1[0x128] == 0) goto LAB_00666b17;
              uVar5 = FUN_00667530(puStack_370,&DAT_006aad40,&bStack_204,0x200,&DAT_006b9172);
              FUN_00668130(uVar5);
              pbVar14 = &bStack_204;
              bVar2 = bStack_204;
              while (bVar2 != 0) {
                bVar2 = *pbVar14;
                iVar4 = 0;
                if ((char)bVar2 < '0') break;
                do {
                  if ('9' < (char)bVar2) break;
                  pbVar14 = pbVar14 + 1;
                  iVar4 = (bVar2 & 0xf) + iVar4 * 10;
                  bVar2 = *pbVar14;
                } while ('/' < (char)bVar2);
                if (iVar4 == 0) break;
                if (*pbVar14 != 0) {
                  pbVar14 = pbVar14 + 1;
                }
                iVar7 = 0;
                bVar2 = *pbVar14;
                while (('/' < (char)bVar2 && ((char)bVar2 < ':'))) {
                  pbVar14 = pbVar14 + 1;
                  iVar7 = (bVar2 & 0xf) + iVar7 * 10;
                  bVar2 = *pbVar14;
                }
                if (*pbVar14 != 0) {
                  pbVar14 = pbVar14 + 1;
                }
                if (iVar4 != param_1[0x6e]) {
                  FUN_00664520(iVar7);
                }
                bVar2 = *pbVar14;
              }
            }
            if (iStack_36c == 0x2b757372) {
              uVar3 = local_350;
              if (param_1[0x12d] == 0) goto LAB_00666b17;
              uVar5 = FUN_00667530(puStack_370,&DAT_0069edd8,0xffffffff);
              iVar4 = FUN_00667ec0(uVar5);
              if (-1 < iVar4) {
                iVar7 = FUN_00667530(puStack_370,&DAT_006bd2ec);
                if (iVar7 == 0) {
                  iVar7 = FUN_0066dd40(param_1[0x12d],iVar4);
                  if (iVar7 != 0) {
                    FUN_0066dd80(param_1[0x12d],iVar4);
                    uVar5 = FUN_00666eb0(param_1[0x12e],iVar7);
                    FUN_00447030(uVar5);
                  }
                }
                else {
                  piVar13 = (int *)FUN_00549460(0x1fc);
                  piVar8 = piVar13;
                  for (iVar7 = 0x7f; iVar7 != 0; iVar7 = iVar7 + -1) {
                    *piVar8 = 0;
                    piVar8 = piVar8 + 1;
                  }
                  *piVar13 = iVar4;
                  uVar5 = FUN_00667530(puStack_370,&DAT_006bd2ec,piVar13 + 2,0x20,&DAT_006b9172);
                  FUN_00668130(uVar5);
                  uVar5 = FUN_00667530(puStack_370,&DAT_006a9718,0);
                  iVar4 = FUN_00667f50(uVar5);
                  piVar13[0xc] = iVar4;
                  uVar5 = FUN_00667530(puStack_370,&DAT_006aad4c,piVar13 + 10,8,&DAT_006b9172);
                  FUN_00668130(uVar5);
                  uVar5 = FUN_00667530(puStack_370,&DAT_006aad64,0);
                  iVar4 = FUN_00667f10(uVar5);
                  piVar13[1] = iVar4;
                  uVar5 = FUN_00667530(puStack_370,&DAT_006aad3c,piVar13 + 0xe,0xc0,&DAT_006b9172);
                  FUN_00668130(uVar5);
                  uVar5 = FUN_00667530(puStack_370,&DAT_006a9714,0);
                  iVar4 = FUN_00667ec0(uVar5);
                  piVar13[0xd] = iVar4;
                  uVar5 = FUN_00667530(puStack_370,&DAT_006a9748,piVar13 + 0x3e,0x100,&DAT_006b9172)
                  ;
                  FUN_00668130(uVar5);
                  uVar5 = FUN_00667530(puStack_370,&DAT_006a9710,0);
                  iVar4 = FUN_00667ec0(uVar5);
                  piVar13[0x7e] = iVar4;
                  iStack_364 = FUN_0066dd40(param_1[0x12d],*piVar13);
                  if (iStack_364 == 0) {
                    uVar5 = FUN_00666de0(param_1[0x12e],piVar13);
                    FUN_0066dcd0(param_1[0x12d],*piVar13,uVar5);
                  }
                  else {
                    piStack_34c = (int *)FUN_00666ea0(param_1[0x12e],iStack_364);
                    piVar8 = piVar13;
                    piVar17 = piStack_34c;
                    for (iVar4 = 0x7f; iVar4 != 0; iVar4 = iVar4 + -1) {
                      *piVar17 = *piVar8;
                      piVar8 = piVar8 + 1;
                      piVar17 = piVar17 + 1;
                    }
                    FUN_00666e50(param_1[0x12e],iStack_364,piStack_34c);
                    FUN_00447030(piVar13);
                    piVar13 = piStack_34c;
                  }
                  if ((piVar13[1] & 0x200000U) != 0) {
                    param_1[0x6d] = piVar13[1];
                  }
                }
                uVar5 = FUN_00667530(puStack_370,&DAT_006bd2e8,0);
                uVar5 = FUN_00667ec0(uVar5);
                FUN_00664520(uVar5);
                param_1[2] = param_1[2] | 0x40;
              }
            }
            if (iStack_36c == 0x2b726e6b) {
              uVar3 = local_350;
              if (param_1[0x132] == 0) goto LAB_00666b17;
              uVar5 = FUN_00667530(puStack_370,&DAT_006aad38,0);
              iVar4 = FUN_00667ec0(uVar5);
              if (iVar4 == -2) {
                iVar4 = FUN_0066dac0(param_1[0x132]);
                while (iVar4 != 0) {
                  uVar5 = FUN_00666eb0(param_1[0x133],iVar4);
                  FUN_00447030(uVar5);
                  iVar4 = FUN_0066dac0(param_1[0x132]);
                }
              }
              else {
                piVar8 = (int *)FUN_00549460(0xe8);
                piVar8[1] = 0;
                uVar5 = FUN_00667530(puStack_370,&DAT_006a9718,0);
                iVar4 = FUN_00667ec0(uVar5);
                piVar13 = piVar8 + 2;
                *piVar8 = iVar4;
                uVar5 = FUN_00667530(puStack_370,&DAT_006bd2ec,piVar13,0x20,&DAT_006b9172);
                FUN_00668130(uVar5);
                uVar5 = FUN_00667530(puStack_370,&DAT_006aad3c,piVar8 + 10,0xc0,&DAT_006b9172);
                FUN_00668130(uVar5);
                iStack_364 = FUN_0066dc20(param_1[0x132],piVar13);
                if (iStack_364 == 0) {
                  if (*piVar8 < 1) {
LAB_006665ff:
                    FUN_00447030(piVar8);
                  }
                  else {
                    uVar5 = FUN_00666de0(param_1[0x133],piVar8);
                    FUN_0066dbb0(param_1[0x132],piVar13,uVar5);
                  }
                }
                else if (*piVar8 < 1) {
                  if (0 < *piVar8) goto LAB_006665ff;
                  uVar5 = FUN_0066dc70(param_1[0x132],piVar13);
                  uVar5 = FUN_00666eb0(param_1[0x133],uVar5);
                  FUN_00447030(uVar5);
                  FUN_00447030(piVar8);
                }
                else {
                  piVar9 = (int *)FUN_00666ea0(param_1[0x133],iStack_364);
                  piVar13 = piVar8;
                  piVar17 = piVar9;
                  for (iVar4 = 0x3a; iVar4 != 0; iVar4 = iVar4 + -1) {
                    *piVar17 = *piVar13;
                    piVar13 = piVar13 + 1;
                    piVar17 = piVar17 + 1;
                  }
                  FUN_00666e50(param_1[0x133],iStack_364,piVar9);
                  FUN_00447030(piVar8);
                }
              }
              param_1[2] = param_1[2] | 0x80;
            }
            if (iStack_36c == 0x2b736e70) {
              iVar4 = param_1[0x1b0];
              uVar3 = local_350;
              if (((iVar4 < 6) || (9 < iVar4)) || (param_1[iVar4 * 5 + 0x128] == 0))
              goto LAB_00666b17;
              puVar10 = (undefined4 *)FUN_00549460(0xe8);
              uVar5 = FUN_00667530(puStack_370,&DAT_006a9714,0);
              uVar5 = FUN_00667ec0(uVar5);
              puVar10[1] = uVar5;
              uVar5 = FUN_00667530(puStack_370,&DAT_006aad4c,0);
              uVar5 = FUN_00667ec0(uVar5);
              puVar15 = puVar10 + 2;
              *puVar10 = uVar5;
              uVar5 = FUN_00667530(puStack_370,&DAT_006bd2ec,puVar15,0x20,&DAT_006b9172);
              FUN_00668130(uVar5);
              uVar5 = FUN_00667530(puStack_370,&DAT_006aad3c,puVar10 + 10,0xc0,&DAT_006b9172);
              FUN_00668130(uVar5);
              iStack_364 = FUN_0066dc20(param_1[param_1[0x1b0] * 5 + 0x128],puVar15);
              if (iStack_364 == 0) {
                uVar5 = FUN_00666de0(param_1[param_1[0x1b0] * 5 + 0x129],puVar10);
                FUN_0066dbb0(param_1[param_1[0x1b0] * 5 + 0x128],puVar15,uVar5);
              }
              else {
                puVar11 = (undefined4 *)FUN_00666ea0(param_1[param_1[0x1b0] * 5 + 0x129],iStack_364)
                ;
                puVar15 = puVar10;
                puVar18 = puVar11;
                for (iVar4 = 0x3a; iVar4 != 0; iVar4 = iVar4 + -1) {
                  *puVar18 = *puVar15;
                  puVar15 = puVar15 + 1;
                  puVar18 = puVar18 + 1;
                }
                FUN_00666e50(param_1[param_1[0x1b0] * 5 + 0x129],iStack_364,puVar11);
                FUN_00447030(puVar10);
              }
              param_1[2] = param_1[2] | 0x80;
            }
            if (iStack_36c == 0x2b61676d) {
              uVar3 = local_350;
              if (param_1[0x141] == 0) goto LAB_00666b17;
              uVar5 = FUN_00667530(puStack_370,"IDENT",0xffffffff);
              iVar4 = FUN_00667ec0(uVar5);
              if (-1 < iVar4) {
                iVar7 = FUN_00667530(puStack_370,&DAT_006bd3bc);
                if (iVar7 == 0) {
                  iVar7 = FUN_0066dd40(param_1[0x141],iVar4);
                  if (iVar7 != 0) {
                    FUN_0066dd80(param_1[0x141],iVar4);
                    uVar5 = FUN_00666eb0(param_1[0x142],iVar7);
                    FUN_00447030(uVar5);
                  }
                }
                else {
                  puVar10 = (undefined4 *)FUN_00549460(0x2a0);
                  puVar15 = puVar10;
                  for (iVar7 = 0xa8; iVar7 != 0; iVar7 = iVar7 + -1) {
                    *puVar15 = 0;
                    puVar15 = puVar15 + 1;
                  }
                  FUN_006652f0(puVar10,puStack_370);
                  iStack_364 = FUN_0066dd40(param_1[0x141],iVar4);
                  if (iStack_364 == 0) {
                    uVar5 = FUN_00666de0(param_1[0x142],puVar10);
                    FUN_0066dcd0(param_1[0x141],iVar4,uVar5);
                  }
                  else {
                    puVar11 = (undefined4 *)FUN_00666ea0(param_1[0x142],iStack_364);
                    puVar15 = puVar10;
                    puVar18 = puVar11;
                    for (iVar4 = 0xa8; iVar4 != 0; iVar4 = iVar4 + -1) {
                      *puVar18 = *puVar15;
                      puVar15 = puVar15 + 1;
                      puVar18 = puVar18 + 1;
                    }
                    FUN_00666e50(param_1[0x142],iStack_364,puVar11);
                    FUN_00447030(puVar10);
                  }
                }
                param_1[2] = param_1[2] | 0x1000;
              }
            }
            if (iStack_36c == 0x2b67616d) {
              uVar3 = local_350;
              if (param_1[0x13c] == 0) goto LAB_00666b17;
              iVar4 = FUN_00667530(puStack_370,&DAT_006bd3bc);
              if (iVar4 != 0) {
                puVar10 = (undefined4 *)FUN_00549460(0x2a0);
                puVar15 = puVar10;
                for (iVar4 = 0xa8; iVar4 != 0; iVar4 = iVar4 + -1) {
                  *puVar15 = 0;
                  puVar15 = puVar15 + 1;
                }
                FUN_006652f0(puVar10,puStack_370);
                iStack_364 = FUN_0066dc20(param_1[0x13c],puVar10 + 1);
                if (iStack_364 == 0) {
                  uVar5 = FUN_00666de0(param_1[0x13d],puVar10);
                  FUN_0066dbb0(param_1[0x13c],puVar10 + 1,uVar5);
                }
                else {
                  puVar11 = (undefined4 *)FUN_00666ea0(param_1[0x13d],iStack_364);
                  puVar15 = puVar10;
                  puVar18 = puVar11;
                  for (iVar4 = 0xa8; iVar4 != 0; iVar4 = iVar4 + -1) {
                    *puVar18 = *puVar15;
                    puVar15 = puVar15 + 1;
                    puVar18 = puVar18 + 1;
                  }
                  FUN_00666e50(param_1[0x13d],iStack_364,puVar11);
                  FUN_00447030(puVar10);
                }
                param_1[2] = param_1[2] | 0x2000;
              }
            }
            if (((iStack_36c == 0x6d6f7665) || (iStack_36c == 0x726f6f6d)) && (uStack_368 == 0)) {
              uVar5 = FUN_00667530(puStack_370,"LIDENT",0xffffffff);
              iVar4 = FUN_00667ec0(uVar5);
              if (-1 < iVar4) {
                uVar5 = FUN_00667530(puStack_370,"LCOUNT",0);
                uVar5 = FUN_00667ec0(uVar5);
                FUN_00664520(uVar5);
              }
            }
            uVar3 = local_350;
            if (iStack_36c == 0x6d6f7665) {
              uVar5 = FUN_00667530(puStack_370,"IDENT",0);
              iVar4 = FUN_00667ec0(uVar5);
              uVar5 = FUN_00667530(puStack_370,"COUNT",0);
              uVar5 = FUN_00667ec0(uVar5);
              uVar3 = local_350;
              if (iVar4 != param_1[0x6e]) {
                param_1[0x6e] = iVar4;
                FUN_00664520(uVar5);
                uVar5 = FUN_00667530(puStack_370,&DAT_006bd3bc,param_1 + 0x70,0x40,&DAT_006b9172);
                FUN_00668130(uVar5);
                uVar5 = FUN_00667530(puStack_370,"FLAGS",0);
                iVar4 = FUN_00667f10(uVar5);
                param_1[0x6f] = iVar4;
                param_1[2] = param_1[2] | 8;
                if (param_1[0x12d] != 0) {
                  iVar4 = FUN_0066dac0(param_1[0x12d]);
                  while (iVar4 != 0) {
                    uVar5 = FUN_00666eb0(param_1[0x12e],iVar4);
                    FUN_00447030(uVar5);
                    iVar4 = FUN_0066dac0(param_1[0x12d]);
                  }
                  param_1[2] = param_1[2] | 0x40;
                }
                uVar3 = local_350;
                if (param_1[0x141] != 0) {
                  iVar4 = FUN_0066dac0(param_1[0x141]);
                  uVar3 = local_350;
                  while (local_350 = uVar3, iVar4 != 0) {
                    uVar5 = FUN_00666eb0(param_1[0x142],iVar4);
                    FUN_00447030(uVar5);
                    iVar4 = FUN_0066dac0(param_1[0x141]);
                    uVar3 = local_350;
                  }
                  param_1[2] = param_1[2] | 0x1000;
                }
              }
            }
          }
        }
LAB_00666b17:
        FUN_0066e840(*param_1,0,0,0,0);
        iVar4 = FUN_0066e780(*param_1,&iStack_36c,&uStack_368,&puStack_370);
      }
      FUN_00664590();
      if ((param_1[6] != 0) && ((uint)param_1[6] <= uVar3)) {
        FUN_006652b0();
        param_1[6] = uVar3 + 30000;
      }
    }
  }
  return;
}


// ==== 0x666c30 FUN_00666c30

int FUN_00666c30(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int *unaff_EBX;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 *puVar8;
  
  if (unaff_EBX[1] < 1) {
    iVar1 = *unaff_EBX;
    if (0 < iVar1) goto LAB_00666c59;
  }
  else {
    iVar1 = (unaff_EBX[6] * 100) / unaff_EBX[1];
    if (*unaff_EBX != 0) {
      iVar1 = (iVar1 + *unaff_EBX) / 2;
    }
LAB_00666c59:
    if (1 < iVar1) goto LAB_00666c63;
  }
  iVar1 = 2;
LAB_00666c63:
  piVar2 = (int *)FUN_00549460((iVar1 + 2U) * 4);
  iVar3 = 0;
  if (piVar2 != (int *)0x0) {
    piVar7 = piVar2;
    for (uVar5 = iVar1 + 2U & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *piVar7 = 0;
      piVar7 = piVar7 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)piVar7 = 0;
      piVar7 = (int *)((int)piVar7 + 1);
    }
    *piVar2 = unaff_EBX[0xf];
    piVar2[iVar1 + 1] = -1;
    unaff_EBX[0xf] = (int)piVar2;
    iVar3 = 1;
    iVar1 = piVar2[1];
    piVar2 = piVar2 + 1;
    while (iVar1 == 0) {
      *piVar2 = unaff_EBX[0xe];
      unaff_EBX[0xe] = (int)piVar2;
      iVar3 = iVar3 + 1;
      iVar1 = piVar2[1];
      piVar2 = piVar2 + 1;
    }
    iVar1 = unaff_EBX[4] + iVar3 + -1;
    unaff_EBX[4] = iVar1;
    puVar4 = (undefined4 *)FUN_00549460((unaff_EBX[6] + iVar1) * 8);
    if ((undefined4 *)unaff_EBX[0x10] != (undefined4 *)0x0) {
      puVar6 = (undefined4 *)unaff_EBX[0x10];
      puVar8 = puVar4;
      for (uVar5 = unaff_EBX[6] & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
      for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      FUN_00447030(unaff_EBX[0x10]);
    }
    unaff_EBX[0x10] = (int)puVar4;
    iVar3 = iVar3 + -1;
  }
  return iVar3;
}


// ==== 0x666d30 FUN_00666d30

void FUN_00666d30(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  (**(code **)(param_1 + 0x30))
            (*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x28),*(undefined4 *)*param_2
             ,*(undefined4 *)*param_3);
  return;
}


// ==== 0x666d60 FUN_00666d60

undefined4 * FUN_00666d60(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)FUN_00549460(0x44);
  puVar3 = puVar1;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *puVar1 = param_1;
  FUN_00666c30();
  *puVar1 = param_2;
  puVar1[1] = param_3;
  return puVar1;
}


// ==== 0x666da0 FUN_00666da0

void FUN_00666da0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  while (iVar1 != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0x3c);
    *(undefined4 *)(param_1 + 0x3c) = *puVar2;
    FUN_00447030(puVar2);
    iVar1 = *(int *)(param_1 + 0x3c);
  }
  FUN_00447030(*(undefined4 *)(param_1 + 0x40));
  FUN_00447030(param_1);
  return;
}


// ==== 0x666de0 FUN_00666de0

undefined4 * FUN_00666de0(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x38) == 0) && (iVar2 = FUN_00666c30(), iVar2 < 1)) {
    return (undefined4 *)0x0;
  }
  puVar1 = *(undefined4 **)(param_1 + 0x38);
  *(undefined4 *)(param_1 + 0x38) = *puVar1;
  *puVar1 = param_2;
  *(undefined4 **)(*(int *)(param_1 + 0x40) + *(int *)(param_1 + 0x18) * 4) = puVar1;
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
  if ((*(code **)(param_1 + 0x24) != (code *)0x0) &&
     (iVar2 = (**(code **)(param_1 + 0x24))
                        (*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x1c),*puVar1),
     iVar2 < 1)) {
    return puVar1;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  return puVar1;
}


// ==== 0x666e50 FUN_00666e50

void FUN_00666e50(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(code **)(param_1 + 0x24) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + 0x24))
                      (*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x1c),*param_2);
    if (iVar1 < 1) {
      iVar1 = (**(code **)(param_1 + 0x24))
                        (*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x1c),param_3);
      if (iVar1 < 1) goto LAB_00666e90;
    }
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
LAB_00666e90:
  *param_2 = param_3;
  return;
}


// ==== 0x666ea0 FUN_00666ea0

undefined4 FUN_00666ea0(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    return *param_2;
  }
  return 0;
}


// ==== 0x666eb0 FUN_00666eb0

undefined4 FUN_00666eb0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar3 = 0;
  if (0 < iVar1) {
    piVar4 = *(int **)(param_1 + 0x40);
    do {
      if ((undefined4 *)*piVar4 == param_2) break;
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x18));
  }
  if (iVar3 != iVar1) {
    if (iVar3 < *(int *)(param_1 + 0x14)) {
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
    }
    *(int *)(param_1 + 0x18) = iVar1 + -1;
    if (iVar3 < iVar1 + -1) {
      do {
        *(undefined4 *)(*(int *)(param_1 + 0x40) + iVar3 * 4) =
             *(undefined4 *)(*(int *)(param_1 + 0x40) + 4 + iVar3 * 4);
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0x18));
    }
    uVar2 = *param_2;
    *param_2 = *(undefined4 *)(param_1 + 0x38);
    *(undefined4 **)(param_1 + 0x38) = param_2;
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    return uVar2;
  }
  return 0;
}


// ==== 0x666f30 FUN_00666f30

undefined4 FUN_00666f30(int param_1,int param_2)

{
  if (((param_1 != 0) && (-1 < param_2)) && (param_2 < *(int *)(param_1 + 0x18))) {
    return **(undefined4 **)(*(int *)(param_1 + 0x40) + param_2 * 4);
  }
  return 0;
}


// ==== 0x666f60 FUN_00666f60

void FUN_00666f60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (0 < *(int *)(param_1 + 0x18)) {
    *(undefined4 *)(param_1 + 8) = 1;
  }
  *(undefined4 *)(param_1 + 0x2c) = param_2;
  *(undefined4 *)(param_1 + 0x28) = param_3;
  *(undefined4 *)(param_1 + 0x30) = param_4;
  return;
}


// ==== 0x666f90 FUN_00666f90

void FUN_00666f90(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (0 < *(int *)(param_1 + 0x18)) {
    *(undefined4 *)(param_1 + 8) = 1;
  }
  *(undefined4 *)(param_1 + 0x20) = param_2;
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  *(undefined4 *)(param_1 + 0x24) = param_4;
  return;
}


// ==== 0x666fc0 FUN_00666fc0

bool FUN_00666fc0(int param_1,int param_2)

{
  if (param_2 != 0) {
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  }
  return 0 < *(int *)(param_1 + 0xc);
}


// ==== 0x666fe0 FUN_00666fe0

undefined4 FUN_00666fe0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (*(int *)(param_1 + 0xc) + *(int *)(param_1 + 8) == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 8) != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0x40);
    puVar3 = puVar2 + *(int *)(param_1 + 0x18);
    puVar4 = puVar2;
    if (puVar2 != puVar3) {
      do {
        if ((*(code **)(param_1 + 0x24) == (code *)0x0) ||
           (iVar1 = (**(code **)(param_1 + 0x24))
                              (*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x1c),
                               *(undefined4 *)*puVar2), 0 < iVar1)) {
          *puVar4 = *puVar2;
          puVar4 = puVar4 + 1;
        }
        else {
          *puVar3 = *puVar2;
          puVar3 = puVar3 + 1;
        }
        puVar2 = puVar2 + 1;
      } while (puVar2 != (undefined4 *)(*(int *)(param_1 + 0x40) + *(int *)(param_1 + 0x18) * 4));
    }
    *(int *)(param_1 + 0x14) = (int)puVar4 - *(int *)(param_1 + 0x40) >> 2;
    for (puVar2 = (undefined4 *)(*(int *)(param_1 + 0x40) + *(int *)(param_1 + 0x18) * 4);
        puVar2 != puVar3; puVar2 = puVar2 + 1) {
      *puVar4 = *puVar2;
      puVar4 = puVar4 + 1;
    }
    *(int *)(param_1 + 0x18) = (int)puVar4 - *(int *)(param_1 + 0x40) >> 2;
    if (*(int *)(param_1 + 0x30) != 0) {
      FUN_0066ebc0(param_1,*(int *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x14),4,FUN_00666d30);
    }
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    return 2;
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  return 1;
}


// ==== 0x6670b0 FUN_006670b0

void FUN_006670b0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x34) = param_2;
  return;
}


// ==== 0x6670c0 FUN_006670c0

undefined4 FUN_006670c0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x34);
}


// ==== 0x6670d0 FUN_006670d0

void FUN_006670d0(void)

{
  byte bVar1;
  byte *in_EAX;
  int *unaff_ESI;
  
  *unaff_ESI = 0;
  bVar1 = *in_EAX;
  while (('/' < (char)bVar1 && ((char)bVar1 < ':'))) {
    in_EAX = in_EAX + 1;
    *unaff_ESI = (bVar1 & 0xf) + *unaff_ESI * 10;
    bVar1 = *in_EAX;
  }
  return;
}


// ==== 0x667100 FUN_00667100

undefined4 * FUN_00667100(undefined4 *param_1)

{
  int iVar1;
  ulonglong uVar2;
  uint in_EAX;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  
  uVar3 = in_EAX / 0x15180;
  uVar2 = ((ulonglong)in_EAX % 0x15180) / 0x3c;
  *param_1 = (int)(((ulonglong)in_EAX % 0x15180) % 0x3c);
  param_1[1] = (int)(uVar2 % 0x3c);
  param_1[2] = (int)(uVar2 / 0x3c);
  uVar6 = 0x7b2;
  while( true ) {
    if (((uVar6 & 3) == 0) && (((int)uVar6 % 100 != 0 || ((int)uVar6 % 400 == 0)))) {
      uVar4 = 0x16e;
    }
    else {
      uVar4 = 0x16d;
    }
    if ((int)uVar3 < (int)uVar4) break;
    uVar4 = (int)uVar3 / 0x16e + uVar6;
    if (uVar4 == uVar6) {
      uVar4 = uVar4 + 1;
    }
    iVar7 = uVar6 - 1;
    iVar1 = uVar4 - 1;
    uVar3 = uVar3 + ((iVar1 / 100 +
                      (((iVar7 / 400 + (uVar6 - uVar4) * 0x16d) - iVar1 / 400) - iVar7 / 100) +
                     ((int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2)) -
                    ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2));
    uVar6 = uVar4;
  }
  piVar5 = &DAT_006ab7d8 + (uVar4 & 1) * 0xc;
  param_1[5] = uVar6 - 0x76c;
  param_1[7] = uVar3;
  param_1[4] = 0;
  iVar7 = *piVar5;
  if (iVar7 <= (int)uVar3) {
    do {
      uVar3 = uVar3 - iVar7;
      piVar5 = piVar5 + 1;
      param_1[4] = param_1[4] + 1;
      iVar7 = *piVar5;
    } while (iVar7 <= (int)uVar3);
  }
  param_1[3] = uVar3 + 1;
  param_1[8] = 0;
  return param_1;
}


// ==== 0x667260 FUN_00667260

uint FUN_00667260(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *unaff_EDI;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  uVar2 = 0;
  uVar3 = 0xffffffff;
  do {
    uVar4 = uVar2 + uVar3 >> 1;
    FUN_00667100(&local_24);
    iVar1 = local_10 - unaff_EDI[5];
    if ((((iVar1 == 0) && (iVar1 = local_14 - unaff_EDI[4], iVar1 == 0)) &&
        (iVar1 = local_18 - unaff_EDI[3], iVar1 == 0)) &&
       (((iVar1 = local_1c - unaff_EDI[2], iVar1 == 0 &&
         (iVar1 = local_20 - unaff_EDI[1], iVar1 == 0)) &&
        (iVar1 = local_24 - *unaff_EDI, iVar1 == 0)))) break;
    if (iVar1 < 1) {
      uVar2 = uVar4 + 1;
    }
    else {
      uVar3 = uVar4 - 1;
    }
  } while (uVar2 <= uVar3);
  return (iVar1 != 0) - 1 & uVar4;
}


// ==== 0x6672e0 FUN_006672e0

char * __fastcall FUN_006672e0(undefined1 *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  char *in_EAX;
  
  if (param_2 == (char *)0x0) {
    *param_1 = 0;
    return in_EAX;
  }
  cVar2 = *param_2;
  while (cVar2 != '\0') {
    *in_EAX = cVar2;
    pcVar1 = param_2 + 1;
    in_EAX = in_EAX + 1;
    param_2 = param_2 + 1;
    cVar2 = *pcVar1;
  }
  *in_EAX = '=';
  return in_EAX + 1;
}


// ==== 0x667300 FUN_00667300

int FUN_00667300(byte *param_1,int param_2,byte *param_3)

{
  byte *pbVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte bVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  bool bVar12;
  
  if (param_1 == (byte *)0x0) {
    return -1;
  }
  if ((param_3 != (byte *)0x0) && (bVar2 = *param_3, 0x20 < bVar2)) {
    pbVar4 = param_1;
    pbVar3 = param_1;
    if (bVar2 == 0x7e) {
      if (*param_1 != 0) {
        do {
          pbVar11 = pbVar3;
          pbVar3 = pbVar11 + 1;
        } while (pbVar11[1] != 0);
        pbVar4 = pbVar3;
        if (((pbVar3 != param_1) && (0x1f < *pbVar11)) &&
           (((uint)*pbVar11 != (int)(char)DAT_006eb1a4 && (pbVar3 < param_1 + param_2 + -1)))) {
          *pbVar3 = DAT_006eb1a4;
          pbVar3 = pbVar11 + 2;
          *pbVar3 = 0;
          pbVar4 = pbVar3;
        }
      }
    }
    else if (*param_1 != 0) {
      do {
        if (0x20 < *pbVar4) {
          pbVar3 = pbVar4;
          if ((&DAT_006ab2b8)[*pbVar4] != '\x01') {
            bVar5 = (&DAT_006ab2b8)[*pbVar4];
            bVar7 = (&DAT_006ab2b8)[(char)bVar2];
            if (bVar5 == bVar7) {
              pbVar11 = param_3;
              do {
                if (bVar5 < 2) break;
                bVar5 = (&DAT_006ab2b8)[pbVar11[(int)(pbVar4 + (1 - (int)param_3))]];
                bVar7 = (&DAT_006ab2b8)[(char)pbVar11[1]];
                pbVar11 = pbVar11 + 1;
              } while (bVar5 == bVar7);
            }
            if ((uint)bVar7 + (uint)bVar5 != 2) {
              do {
                pbVar3 = pbVar4 + 1;
                pbVar4 = pbVar4 + 1;
              } while (0x1f < *pbVar3);
              goto LAB_006673ed;
            }
            bVar2 = *pbVar4;
            while (0x1f < bVar2) {
              pbVar11 = pbVar3 + 1;
              pbVar3 = pbVar3 + 1;
              bVar2 = *pbVar11;
            }
            if (*pbVar3 != 0) {
              pbVar3 = pbVar3 + 1;
            }
          }
          goto LAB_00667453;
        }
        pbVar4 = pbVar4 + 1;
LAB_006673ed:
      } while (*pbVar4 != 0);
      pbVar3 = pbVar4;
      if ((((pbVar4 != param_1) && (0x1f < pbVar4[-1])) &&
          ((uint)pbVar4[-1] != (int)(char)DAT_006eb1a4)) && (pbVar4 < param_1 + param_2 + -1)) {
        *pbVar4 = DAT_006eb1a4;
        pbVar3 = pbVar4 + 1;
        *pbVar3 = 0;
        pbVar4 = pbVar3;
      }
    }
LAB_00667453:
    iVar8 = 0;
    bVar2 = *param_3;
    while ('\x1f' < (char)bVar2) {
      iVar8 = iVar8 + 1;
      bVar2 = param_3[iVar8];
    }
    uVar9 = iVar8 + 1;
    pbVar10 = pbVar4 + (uVar9 - (int)pbVar3);
    bVar2 = *pbVar3;
    pbVar11 = pbVar3;
    while (bVar2 != 0) {
      pbVar1 = pbVar11 + 1;
      pbVar11 = pbVar11 + 1;
      bVar2 = *pbVar1;
    }
    if (((int)pbVar10 < 1) || ((int)pbVar10 <= (int)(param_1 + (param_2 - (int)pbVar11)))) {
      if (pbVar10 == (byte *)0x0) {
        bVar12 = true;
        uVar6 = uVar9;
        pbVar3 = pbVar4;
        pbVar11 = param_3;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          bVar12 = *pbVar3 == *pbVar11;
          pbVar3 = pbVar3 + 1;
          pbVar11 = pbVar11 + 1;
        } while (bVar12);
        if (bVar12) {
          return 0;
        }
      }
      else {
        if (0 < (int)pbVar10) {
          _memmove(pbVar3 + (int)pbVar10,pbVar3,(size_t)(pbVar11 + (1 - (int)pbVar3)));
        }
        if ((int)pbVar10 < 0) {
          _memmove(pbVar4,pbVar4 + -(int)pbVar10,
                   (size_t)(pbVar11 + (int)(pbVar10 + (1 - (int)pbVar4))));
        }
      }
      pbVar3 = pbVar4;
      for (uVar6 = uVar9 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pbVar3 = *(undefined4 *)param_3;
        param_3 = param_3 + 4;
        pbVar3 = pbVar3 + 4;
      }
      for (uVar6 = uVar9 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pbVar3 = *param_3;
        param_3 = param_3 + 1;
        pbVar3 = pbVar3 + 1;
      }
      if ((pbVar4[uVar9] == 0) && (DAT_006eb1a4 != 10)) {
        pbVar4[iVar8] = 0;
        return iVar8;
      }
      pbVar4[iVar8] = DAT_006eb1a4;
      return iVar8;
    }
  }
  return -1;
}


// ==== 0x667530 FUN_00667530

byte * FUN_00667530(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  if ((((param_1 != (byte *)0x0) && (bVar1 = *param_1, bVar1 != 0)) && (param_2 != (byte *)0x0)) &&
     (pbVar6 = param_2, *param_2 != 0)) {
    do {
      pbVar3 = pbVar6;
      pbVar6 = pbVar3 + 1;
    } while (pbVar3[1] != 0);
    pbVar6 = param_1 + -1;
    pbVar5 = param_1;
    do {
      if ((bVar1 == 0x3d) || (bVar1 == 0x3a)) {
        if ((pbVar6[2] < 0x20) && (*pbVar6 < 0x21)) {
          return (byte *)0x0;
        }
        if (param_1 <= pbVar6) {
          pbVar4 = pbVar3 + (int)(pbVar6 + (1 - (int)pbVar5));
          pbVar2 = pbVar6;
          do {
            if ((&DAT_006ab1b8)[*pbVar2] != (&DAT_006ab1b8)[*pbVar4]) break;
            if ((pbVar4 == param_2) && ((pbVar2 == param_1 || (pbVar2[-1] < 0x21)))) {
              if (pbVar5[1] == 0x20) {
                return pbVar5 + 2;
              }
              return pbVar5 + 1;
            }
            pbVar2 = pbVar2 + -1;
            pbVar4 = pbVar4 + -1;
          } while (param_1 <= pbVar2);
        }
      }
      bVar1 = pbVar5[1];
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    } while (bVar1 != 0);
  }
  return (byte *)0x0;
}


// ==== 0x6675e0 FUN_006675e0

undefined4 FUN_006675e0(byte *param_1,undefined4 param_2)

{
  byte *pbVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  pbVar3 = (byte *)FUN_00667530(param_1,param_2);
  pbVar4 = pbVar3;
  if (pbVar3 == (byte *)0x0) {
    return 0xffffffff;
  }
  for (; (pbVar4 != param_1 && (0x20 < pbVar4[-1])); pbVar4 = pbVar4 + -1) {
  }
  bVar2 = *pbVar3;
  while (0x1f < bVar2) {
    pbVar1 = pbVar3 + 1;
    pbVar3 = pbVar3 + 1;
    bVar2 = *pbVar1;
  }
  bVar2 = *pbVar3;
  while ((bVar2 != 0 && (bVar2 < 0x20))) {
    pbVar1 = pbVar3 + 1;
    pbVar3 = pbVar3 + 1;
    bVar2 = *pbVar1;
  }
  bVar2 = *pbVar3;
  while (bVar2 != 0) {
    *pbVar4 = bVar2;
    pbVar1 = pbVar3 + 1;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    bVar2 = *pbVar1;
  }
  *pbVar4 = 0;
  return 0;
}


// ==== 0x667650 FUN_00667650

int FUN_00667650(char *param_1,int param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = param_2;
  for (; (1 < iVar1 && (*param_3 != '\0')); param_3 = param_3 + 1) {
    *param_1 = *param_3;
    iVar1 = iVar1 + -1;
    param_1 = param_1 + 1;
  }
  if (0 < iVar1) {
    *param_1 = '\0';
  }
  return param_2 - iVar1;
}


// ==== 0x667690 FUN_00667690

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00667690(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint unaff_retaddr;
  undefined1 local_124 [288];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  pcVar2 = (char *)FUN_006672e0();
  if (param_4 < 0) {
    *pcVar2 = '-';
    pcVar2 = pcVar2 + 1;
    param_4 = -param_4;
  }
  pcVar3 = pcVar2 + 0x1f;
  *pcVar3 = '\0';
  for (; 0 < param_4; param_4 = param_4 / 10) {
    pcVar3 = pcVar3 + -1;
    *pcVar3 = (char)(param_4 % 10) + '0';
  }
  cVar1 = *pcVar3;
  if (cVar1 == '\0') {
    pcVar3 = pcVar3 + -1;
    *pcVar3 = '0';
    cVar1 = *pcVar3;
    if (cVar1 == '\0') goto LAB_00667710;
  }
  do {
    *pcVar2 = cVar1;
    cVar1 = pcVar3[1];
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
LAB_00667710:
  *pcVar2 = '\0';
  FUN_00667300(param_1,param_2,local_124);
  return;
}


// ==== 0x667750 FUN_00667750

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00667750(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  char *pcVar1;
  char *pcVar2;
  uint unaff_retaddr;
  undefined1 local_124 [288];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  pcVar1 = (char *)FUN_006672e0();
  for (pcVar2 = "@ABCDEFGHIJKLMNOPQRSTUVWXYZ0123"; (param_4 != 0 && (*pcVar2 != '\0'));
      pcVar2 = pcVar2 + 1) {
    if ((param_4 & 1) != 0) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
    }
    param_4 = (int)param_4 >> 1;
  }
  *pcVar1 = '\0';
  FUN_00667300(param_1,param_2,local_124);
  return;
}


// ==== 0x6677e0 FUN_006677e0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006677e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  ulonglong uVar1;
  byte bVar2;
  byte bVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  uint unaff_retaddr;
  undefined1 local_124 [288];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  pcVar4 = (char *)FUN_006672e0();
  bVar8 = (byte)param_4;
  bVar2 = (byte)(param_4 >> 8);
  uVar9 = param_4 >> 0x10;
  bVar7 = (byte)(param_4 >> 0x10);
  uVar5 = param_4 >> 0x18;
  bVar3 = (byte)(param_4 >> 0x18);
  if (9 < bVar3) {
    if (99 < bVar3) {
      uVar1 = (ulonglong)uVar5;
      uVar5 = uVar5 % 100;
      *pcVar4 = (char)(uVar1 / 100) + '0';
      pcVar4 = pcVar4 + 1;
    }
    *pcVar4 = (char)((ulonglong)uVar5 / 10) + '0';
    bVar3 = (byte)((ulonglong)uVar5 % 10);
    pcVar4 = pcVar4 + 1;
  }
  *pcVar4 = bVar3 + 0x30;
  pcVar4[1] = '.';
  pcVar6 = pcVar4 + 2;
  if (9 < bVar7) {
    if (99 < bVar7) {
      *pcVar6 = (char)((ulonglong)(uVar9 & 0xff) / 100) + '0';
      pcVar6 = pcVar4 + 3;
      uVar9 = (uint)(byte)((ulonglong)(uVar9 & 0xff) % 100);
    }
    *pcVar6 = (char)((ulonglong)(uVar9 & 0xff) / 10) + '0';
    bVar7 = (byte)((ulonglong)(uVar9 & 0xff) % 10);
    pcVar6 = pcVar6 + 1;
  }
  *pcVar6 = bVar7 + 0x30;
  pcVar6[1] = '.';
  pcVar4 = pcVar6 + 2;
  uVar5 = (uint)bVar2;
  if (9 < bVar2) {
    if (99 < bVar2) {
      uVar5 = (uint)bVar2 % 100;
      *pcVar4 = (char)((ulonglong)(uint)bVar2 / 100) + '0';
      pcVar4 = pcVar6 + 3;
    }
    *pcVar4 = (char)((ulonglong)uVar5 / 10) + '0';
    pcVar4 = pcVar4 + 1;
    bVar2 = (byte)(uVar5 % 10);
  }
  *pcVar4 = bVar2 + 0x30;
  pcVar4[1] = '.';
  pcVar6 = pcVar4 + 2;
  if (9 < bVar8) {
    if (99 < bVar8) {
      bVar3 = bVar8 / 100;
      bVar8 = bVar8 % 100;
      *pcVar6 = bVar3 + 0x30;
      pcVar6 = pcVar4 + 3;
    }
    bVar3 = bVar8 / 10;
    bVar8 = bVar8 % 10;
    *pcVar6 = bVar3 + 0x30;
    pcVar6 = pcVar6 + 1;
  }
  *pcVar6 = bVar8 + 0x30;
  pcVar6[1] = '\0';
  FUN_00667300(param_1,param_2,local_124);
  return;
}


// ==== 0x667950 FUN_00667950

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00667950(undefined4 param_1,undefined4 param_2,undefined4 param_3,byte *param_4)

{
  byte bVar1;
  int iVar2;
  uint *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined4 uVar6;
  int iVar7;
  byte *pbVar8;
  uint unaff_retaddr;
  undefined1 local_1204 [4607];
  undefined1 uStack_5;
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  if (param_4 == (byte *)0x0) {
    FUN_006675e0(param_1,param_3);
    return 0;
  }
  pbVar4 = (byte *)FUN_006672e0();
  puVar3 = &local_4;
  bVar1 = *param_4;
  pbVar8 = param_4;
  while (bVar1 != 0) {
    if (bVar1 == 0x20) goto LAB_006679f2;
    pbVar5 = pbVar8 + 1;
    pbVar8 = pbVar8 + 1;
    bVar1 = *pbVar5;
  }
  pbVar5 = pbVar4;
  if (*pbVar8 == 0x20) {
LAB_006679f2:
    *pbVar4 = 0x22;
    pbVar5 = pbVar4 + 1;
    puVar3 = (uint *)&uStack_5;
  }
  iVar7 = (int)puVar3 - (int)pbVar4;
  bVar1 = *param_4;
  while (bVar1 != 0) {
    if (iVar7 < 1) goto LAB_00667a5a;
    bVar1 = *param_4;
    if ((((bVar1 < 0x20) || (0x7e < bVar1)) || (bVar1 == 0x3d)) ||
       (((bVar1 == 0x22 || (bVar1 == 0x3a)) || (bVar1 == 0x25)))) {
      if (2 < iVar7) {
        *pbVar5 = 0x25;
        pbVar5[1] = "0000000000000000111111111111111122222222222222223333333333333333444444444444444455555555555555556666666666666666777777777777777788888888888888889999999999999999aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbccccccccccccccccddddddddddddddddeeeeeeeeeeeeeeeeffffffffffffffff0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
                    [*param_4];
        pbVar5[2] = "0000000000000000111111111111111122222222222222223333333333333333444444444444444455555555555555556666666666666666777777777777777788888888888888889999999999999999aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbccccccccccccccccddddddddddddddddeeeeeeeeeeeeeeeeffffffffffffffff0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
                    [*param_4 + 0x100];
        pbVar5 = pbVar5 + 3;
      }
      iVar2 = -3;
    }
    else {
      *pbVar5 = bVar1;
      pbVar5 = pbVar5 + 1;
      iVar2 = -1;
    }
    iVar7 = iVar7 + iVar2;
    pbVar4 = param_4 + 1;
    param_4 = param_4 + 1;
    bVar1 = *pbVar4;
  }
  if (iVar7 < 1) {
LAB_00667a5a:
    uVar6 = 0xffffffff;
  }
  else {
    if (*pbVar8 == 0x20) {
      *pbVar5 = 0x22;
      pbVar5 = pbVar5 + 1;
    }
    *pbVar5 = 0;
    uVar6 = FUN_00667300(param_1,param_2,local_1204);
  }
  return uVar6;
}


// ==== 0x667aa0 FUN_00667aa0

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00667aa0(undefined4 param_1,undefined4 param_2,undefined4 param_3,byte *param_4,int param_5)

{
  undefined1 *puVar1;
  char *pcVar2;
  undefined4 uVar3;
  uint unaff_retaddr;
  undefined1 local_2104 [8448];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  puVar1 = (undefined1 *)FUN_006672e0();
  *puVar1 = 0x24;
  pcVar2 = puVar1 + 1;
  if ((uint)((int)&local_4 - (int)pcVar2) < param_5 * 2 + 1U) {
    uVar3 = 0xffffffff;
  }
  else {
    if (0 < param_5) {
      do {
        *pcVar2 = "0000000000000000111111111111111122222222222222223333333333333333444444444444444455555555555555556666666666666666777777777777777788888888888888889999999999999999aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbccccccccccccccccddddddddddddddddeeeeeeeeeeeeeeeeffffffffffffffff0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
                  [*param_4];
        pcVar2[1] = "0000000000000000111111111111111122222222222222223333333333333333444444444444444455555555555555556666666666666666777777777777777788888888888888889999999999999999aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbccccccccccccccccddddddddddddddddeeeeeeeeeeeeeeeeffffffffffffffff0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
                    [*param_4 + 0x100];
        pcVar2 = pcVar2 + 2;
        param_4 = param_4 + 1;
        param_5 = param_5 + -1;
      } while (param_5 != 0);
    }
    *pcVar2 = '\0';
    uVar3 = FUN_00667300(param_1,param_2,local_2104);
  }
  return uVar3;
}


// ==== 0x667b60 FUN_00667b60

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00667b60(undefined4 param_1,undefined4 param_2,undefined4 param_3,byte *param_4,
                 byte *param_5)

{
  byte *pbVar1;
  byte bVar2;
  undefined1 *puVar3;
  char *pcVar4;
  byte bVar5;
  byte *pbVar6;
  uint unaff_retaddr;
  undefined1 local_2104 [8448];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  if ((param_4 == (byte *)0x0) || (*param_4 == 0)) {
    param_4 = &DAT_006ab838;
  }
  puVar3 = (undefined1 *)FUN_006672e0();
  *puVar3 = 0x24;
  pcVar4 = puVar3 + 1;
  bVar5 = 0;
  bVar2 = *param_5;
  pbVar6 = param_4;
  while (bVar2 != 0) {
    bVar5 = ((bVar2 ^ bVar5) >> 5 | (bVar2 ^ bVar5) << 3) ^ *pbVar6;
    pbVar1 = pbVar6 + 1;
    pbVar6 = pbVar6 + 1;
    if (*pbVar1 == 0) {
      pbVar6 = param_4;
    }
    *pcVar4 = "0000000000000000111111111111111122222222222222223333333333333333444444444444444455555555555555556666666666666666777777777777777788888888888888889999999999999999aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbccccccccccccccccddddddddddddddddeeeeeeeeeeeeeeeeffffffffffffffff0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
              [bVar5];
    pcVar4[1] = "0000000000000000111111111111111122222222222222223333333333333333444444444444444455555555555555556666666666666666777777777777777788888888888888889999999999999999aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbccccccccccccccccddddddddddddddddeeeeeeeeeeeeeeeeffffffffffffffff0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
                [bVar5 + 0x100];
    pbVar1 = param_5 + 1;
    pcVar4 = pcVar4 + 2;
    param_5 = param_5 + 1;
    bVar2 = *pbVar1;
  }
  *pcVar4 = '\0';
  FUN_00667300(param_1,param_2,local_2104);
  return;
}


// ==== 0x667c40 FUN_00667c40

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00667c40(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint unaff_retaddr;
  undefined1 local_148 [36];
  undefined1 local_124 [288];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  if (param_4 == 0) {
    FUN_0066ef60();
  }
  puVar1 = (undefined4 *)FUN_00667100(local_148);
  if (puVar1 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  uVar2 = FUN_006672e0();
  _sprintf(uVar2,"%d.%d.%d %d:%02d:%02d",puVar1[5] + 0x76c,puVar1[4] + 1,puVar1[3],puVar1[2],
           puVar1[1],*puVar1);
  uVar2 = FUN_00667300(param_1,param_2,local_124);
  return uVar2;
}


// ==== 0x667d10 FUN_00667d10

int FUN_00667d10(undefined4 param_1,undefined4 param_2,byte *param_3)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  
  bVar2 = *param_3;
  iVar4 = 0;
  do {
    if (bVar2 == 0) {
      return iVar4;
    }
    bVar2 = *param_3;
    if (bVar2 < 0x21) {
      param_3 = param_3 + 1;
    }
    else {
      if (bVar2 == 0x3d) {
        return iVar4;
      }
      if (bVar2 == 0x3a) {
        return iVar4;
      }
      iVar3 = FUN_00667300(param_1,param_2,param_3);
      if (0 < iVar3) {
        iVar4 = iVar4 + 1;
      }
      bVar2 = *param_3;
      while (0x1f < bVar2) {
        pbVar1 = param_3 + 1;
        param_3 = param_3 + 1;
        bVar2 = *pbVar1;
      }
    }
    bVar2 = *param_3;
  } while( true );
}


// ==== 0x667d70 FUN_00667d70

int FUN_00667d70(byte *param_1,int param_2,byte *param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  int iVar6;
  
  bVar1 = *param_3;
  iVar6 = param_2;
  if (bVar1 != 0) {
    puVar5 = &param_3;
    do {
      pbVar4 = param_3 + 1;
      if (iVar6 < 2) break;
      if (bVar1 < 0x21) {
        *param_1 = DAT_006eb1a4;
        param_1 = param_1 + 1;
        iVar6 = iVar6 + -1;
        bVar1 = *pbVar4;
        while ((bVar1 != 0 && ((char)bVar1 < '!'))) {
          pbVar3 = pbVar4 + 1;
          pbVar4 = pbVar4 + 1;
          bVar1 = *pbVar3;
        }
      }
      else if (bVar1 == 0x25) {
        bVar1 = *pbVar4;
        if (bVar1 != 0) {
          pbVar4 = param_3 + 2;
          if (param_1[-1] == 0x3d) {
            param_1 = param_1 + -1;
            iVar6 = iVar6 + 1;
          }
          *param_1 = 0;
          param_3 = pbVar4;
          if (bVar1 == 0x73) {
            iVar2 = FUN_00667950(param_1,iVar6,&DAT_006b9172,puVar5[1]);
          }
          else if (bVar1 == 100) {
            iVar2 = FUN_00667690(param_1,iVar6,&DAT_006b9172,puVar5[1]);
          }
          else if (bVar1 == 0x61) {
            iVar2 = FUN_006677e0(param_1,iVar6,&DAT_006b9172,puVar5[1]);
          }
          else if (bVar1 == 0x66) {
            iVar2 = FUN_00667750(param_1,iVar6,&DAT_006b9172,puVar5[1]);
          }
          else {
            if (bVar1 != 0x65) {
              if (bVar1 == 0x72) {
                pbVar3 = (byte *)puVar5[1];
                bVar1 = *pbVar3;
                puVar5 = puVar5 + 1;
                for (; (bVar1 != 0 && (0 < iVar6)); iVar6 = iVar6 + -1) {
                  *param_1 = bVar1;
                  bVar1 = pbVar3[1];
                  param_1 = param_1 + 1;
                  pbVar3 = pbVar3 + 1;
                }
              }
              goto LAB_00667e02;
            }
            iVar2 = FUN_00667c40(param_1,iVar6,&DAT_006b9172,puVar5[1]);
          }
          puVar5 = puVar5 + 1;
          if (0 < iVar2) {
            param_1 = param_1 + iVar2;
            iVar6 = iVar6 - iVar2;
          }
        }
      }
      else {
        *param_1 = bVar1;
        param_1 = param_1 + 1;
        iVar6 = iVar6 + -1;
      }
LAB_00667e02:
      bVar1 = *pbVar4;
      param_3 = pbVar4;
    } while (bVar1 != 0);
  }
  if (0 < iVar6) {
    *param_1 = 0;
  }
  return param_2 - iVar6;
}


// ==== 0x667ec0 FUN_00667ec0

int FUN_00667ec0(byte *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != (byte *)0x0) {
    iVar3 = 1;
    if (*param_1 == 0x2b) {
      param_1 = param_1 + 1;
    }
    else if (*param_1 == 0x2d) {
      param_1 = param_1 + 1;
      iVar3 = -1;
    }
    iVar2 = 0;
    bVar1 = *param_1;
    while (('/' < (char)bVar1 && ((char)bVar1 < ':'))) {
      param_1 = param_1 + 1;
      iVar2 = (bVar1 & 0xf) + iVar2 * 10;
      bVar1 = *param_1;
    }
    return iVar2 * iVar3;
  }
  return param_2;
}


// ==== 0x667f10 FUN_00667f10

uint FUN_00667f10(char *param_1,uint param_2)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == (char *)0x0) {
    return param_2;
  }
  uVar3 = 0;
  uVar2 = *(uint *)(&DAT_006ab3d8 + *param_1 * 4);
  while (uVar2 != 0) {
    uVar3 = uVar3 | uVar2;
    pcVar1 = param_1 + 1;
    param_1 = param_1 + 1;
    uVar2 = *(uint *)(&DAT_006ab3d8 + *pcVar1 * 4);
  }
  return uVar3;
}


// ==== 0x667f50 FUN_00667f50

uint FUN_00667f50(byte *param_1,uint param_2)

{
  byte bVar1;
  
  if (param_1 != (byte *)0x0) {
    param_2 = 0;
    while( true ) {
      while( true ) {
        bVar1 = *param_1;
        if (((char)bVar1 < '0') || ('9' < (char)bVar1)) break;
        param_2 = param_2 & 0xffffff00 | (bVar1 & 0xf) + (param_2 & 0xff) * 10;
        param_1 = param_1 + 1;
      }
      if (bVar1 != 0x2e) break;
      param_2 = param_2 << 8;
      param_1 = param_1 + 1;
    }
  }
  return param_2;
}


// ==== 0x667fa0 FUN_00667fa0

int FUN_00667fa0(byte *param_1,byte *param_2,int param_3,byte *param_4,int param_5,uint param_6)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  byte *pbVar5;
  
  if (param_1 != (byte *)0x0) {
    bVar4 = *param_1;
    if ((bVar4 == 0x22) || (bVar4 == 0x27)) {
      param_1 = param_1 + 1;
    }
    else {
      bVar4 = 0;
    }
    if (0 < param_5) {
      do {
        bVar1 = *param_1;
        while ((((int)(char)bVar1 != (uint)bVar4 && ('\x1f' < (char)bVar1)) &&
               ((int)(char)bVar1 != param_6))) {
          pbVar5 = param_1 + 1;
          param_1 = param_1 + 1;
          bVar1 = *pbVar5;
        }
        if ((int)(char)*param_1 != param_6) goto LAB_00668008;
        param_1 = param_1 + 1;
        param_5 = param_5 + -1;
      } while (0 < param_5);
    }
    if (param_1 != (byte *)0x0) {
      if (param_2 == (byte *)0x0) {
        iVar3 = 0;
        if (*param_1 != bVar4) {
          while ((bVar1 = *param_1, 0x1f < bVar1 && (bVar1 != param_6))) {
            if ((bVar1 == 0x25) && ((0x1f < param_1[1] && (0x1f < param_1[2])))) {
              param_1 = param_1 + 2;
            }
            pbVar5 = param_1 + 1;
            iVar3 = iVar3 + 1;
            param_1 = param_1 + 1;
            if (*pbVar5 == bVar4) {
              return iVar3;
            }
          }
        }
      }
      else {
        if (param_3 < 1) {
          return -1;
        }
        iVar3 = 1;
        if (1 < param_3) {
          do {
            bVar1 = *param_1;
            if (((bVar1 == bVar4) || (bVar1 < 0x20)) || (bVar1 == param_6)) break;
            if (bVar1 == 0x25) {
              bVar2 = param_1[1];
              if (bVar2 == 0x25) {
                *param_2 = 0x25;
                param_1 = param_1 + 2;
              }
              else {
                if ((bVar2 < 0x20) || (param_1[2] < 0x20)) goto LAB_00668118;
                *param_2 = (&DAT_006ab0b8)[param_1[2]] |
                           "0000000000000000111111111111111122222222222222223333333333333333444444444444444455555555555555556666666666666666777777777777777788888888888888889999999999999999aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbccccccccccccccccddddddddddddddddeeeeeeeeeeeeeeeeffffffffffffffff0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
                           [bVar2 + 0x200];
                param_1 = param_1 + 3;
              }
            }
            else {
LAB_00668118:
              *param_2 = bVar1;
              param_1 = param_1 + 1;
            }
            param_2 = param_2 + 1;
            iVar3 = iVar3 + 1;
          } while (iVar3 < param_3);
        }
        *param_2 = 0;
        iVar3 = iVar3 + -1;
      }
      return iVar3;
    }
  }
LAB_00668008:
  if (param_4 == (byte *)0x0) {
    return -1;
  }
  if (param_2 == (byte *)0x0) {
    pbVar5 = param_4 + 1;
    do {
      bVar4 = *param_4;
      param_4 = param_4 + 1;
    } while (bVar4 != 0);
    return (int)param_4 - (int)pbVar5;
  }
  iVar3 = 1;
  pbVar5 = param_2;
  if (1 < param_3) {
    do {
      pbVar5 = param_2;
      if (*param_4 == 0) break;
      pbVar5 = param_2 + 1;
      *param_2 = *param_4;
      param_4 = param_4 + 1;
      iVar3 = iVar3 + 1;
      param_2 = pbVar5;
    } while (iVar3 < param_3);
  }
  *pbVar5 = 0;
  return iVar3 + -1;
}


// ==== 0x668130 FUN_00668130

int FUN_00668130(byte *param_1,byte *param_2,int param_3,byte *param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  byte *pbVar5;
  
  if (param_1 != (byte *)0x0) {
    bVar4 = *param_1;
    if ((bVar4 == 0x22) || (bVar4 == 0x27)) {
      param_1 = param_1 + 1;
    }
    else {
      bVar4 = 0;
    }
    if (param_2 == (byte *)0x0) {
      iVar3 = 0;
      if (*param_1 != bVar4) {
        while (0x1f < *param_1) {
          if (((*param_1 == 0x25) && (0x1f < param_1[1])) && (0x1f < param_1[2])) {
            param_1 = param_1 + 2;
          }
          pbVar5 = param_1 + 1;
          iVar3 = iVar3 + 1;
          param_1 = param_1 + 1;
          if (*pbVar5 == bVar4) {
            return iVar3;
          }
        }
      }
    }
    else {
      if (param_3 < 1) {
        return -1;
      }
      iVar3 = 1;
      if (1 < param_3) {
        do {
          bVar1 = *param_1;
          if ((bVar1 == bVar4) || (bVar1 < 0x20)) break;
          if (bVar1 == 0x25) {
            bVar2 = param_1[1];
            if (bVar2 == 0x25) {
              *param_2 = 0x25;
              param_1 = param_1 + 2;
            }
            else {
              if ((bVar2 < 0x20) || (param_1[2] < 0x20)) goto LAB_00668258;
              *param_2 = (&DAT_006ab0b8)[param_1[2]] |
                         "0000000000000000111111111111111122222222222222223333333333333333444444444444444455555555555555556666666666666666777777777777777788888888888888889999999999999999aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbccccccccccccccccddddddddddddddddeeeeeeeeeeeeeeeeffffffffffffffff0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
                         [bVar2 + 0x200];
              param_1 = param_1 + 3;
            }
          }
          else {
LAB_00668258:
            *param_2 = bVar1;
            param_1 = param_1 + 1;
          }
          param_2 = param_2 + 1;
          iVar3 = iVar3 + 1;
        } while (iVar3 < param_3);
      }
      *param_2 = 0;
      iVar3 = iVar3 + -1;
    }
    return iVar3;
  }
  if (param_4 == (byte *)0x0) {
    return -1;
  }
  if (param_2 == (byte *)0x0) {
    pbVar5 = param_4 + 1;
    do {
      bVar4 = *param_4;
      param_4 = param_4 + 1;
    } while (bVar4 != 0);
    return (int)param_4 - (int)pbVar5;
  }
  iVar3 = 1;
  pbVar5 = param_2;
  if (1 < param_3) {
    do {
      pbVar5 = param_2;
      if (*param_4 == 0) break;
      pbVar5 = param_2 + 1;
      *param_2 = *param_4;
      param_4 = param_4 + 1;
      iVar3 = iVar3 + 1;
      param_2 = pbVar5;
    } while (iVar3 < param_3);
  }
  *pbVar5 = 0;
  return iVar3 + -1;
}


// ==== 0x668270 FUN_00668270

int FUN_00668270(char *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  byte *pbVar4;
  
  if ((param_1 != (char *)0x0) && (*param_1 == '$')) {
    if (param_2 == 0) {
      iVar1 = 0;
      pcVar3 = param_1 + 1;
      if ((byte)param_1[1] < 0x30) {
        return 0;
      }
      do {
        if ((byte)pcVar3[1] < 0x30) {
          return iVar1;
        }
        pbVar4 = (byte *)(pcVar3 + 2);
        pcVar3 = pcVar3 + 2;
        iVar1 = iVar1 + 1;
      } while (0x2f < *pbVar4);
      return iVar1;
    }
    if (0 < param_3) {
      iVar1 = 0;
      pbVar4 = (byte *)(param_1 + 1);
      if (param_3 < 1) {
        return 0;
      }
      while( true ) {
        if (*pbVar4 < 0x30) {
          return iVar1;
        }
        if (pbVar4[1] < 0x30) break;
        iVar2 = iVar1 + 1;
        *(char *)(iVar1 + param_2) =
             (&DAT_006ab0b8)[pbVar4[1]] |
             "0000000000000000111111111111111122222222222222223333333333333333444444444444444455555555555555556666666666666666777777777777777788888888888888889999999999999999aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbccccccccccccccccddddddddddddddddeeeeeeeeeeeeeeeeffffffffffffffff0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
             [*pbVar4 + 0x200];
        pbVar4 = pbVar4 + 2;
        iVar1 = iVar2;
        if (param_3 <= iVar2) {
          return iVar2;
        }
      }
      return iVar1;
    }
  }
  return -1;
}


// ==== 0x6682f0 FUN_006682f0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_006682f0(byte *param_1,uint *param_2,int param_3,byte *param_4)

{
  byte *pbVar1;
  byte bVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  uint *local_40c;
  uint *local_408;
  uint local_404 [257];
  
  local_40c = param_2;
  if (param_3 < 0) {
    local_408 = (uint *)((int)param_2 + 0xffff);
  }
  else {
    local_408 = (uint *)((int)param_2 + param_3);
  }
  if (param_1 == (byte *)0x0) {
    param_1 = &DAT_006b9172;
  }
  if (param_2 == (uint *)0x0) {
    local_40c = local_404;
  }
  puVar3 = local_40c;
  bVar2 = *param_4;
  while (bVar2 != 0) {
    if (bVar2 == 0x23) {
      param_4 = param_4 + 1;
      do {
        bVar2 = *param_4;
        if (bVar2 == 0) break;
        param_4 = param_4 + 1;
      } while (bVar2 != 0x3d);
    }
    iVar8 = 0;
    bVar2 = *param_4;
    pbVar10 = param_4;
    while (('/' < (char)bVar2 && ((char)bVar2 < ':'))) {
      pbVar10 = pbVar10 + 1;
      iVar8 = (bVar2 & 0xf) + iVar8 * 10;
      bVar2 = *pbVar10;
    }
    bVar2 = *pbVar10;
    iVar6 = 0;
    if (bVar2 == 0x61) {
      iVar4 = iVar8;
      if (iVar8 == 0) {
        iVar4 = 1;
      }
      local_40c = (uint *)((int)local_40c + iVar4);
    }
    if (bVar2 == 0x62) {
      iVar6 = 2;
    }
    if (bVar2 == 0x77) {
      iVar6 = 4;
    }
    if (bVar2 == 0x6c) {
      iVar6 = 8;
LAB_0066840c:
      bVar2 = *param_1;
      if (bVar2 == 0x2d) {
        param_1 = param_1 + 1;
      }
      uVar5 = 0;
      pbVar11 = param_1;
      do {
        param_1 = pbVar11;
        if ((char)*param_1 < '0') {
          if ((iVar6 < 1) || (*param_1 != 0x2c)) goto LAB_00668456;
          break;
        }
        uVar5 = uVar5 << 4 | (uint)(byte)(&DAT_006ab0b8)[(char)*param_1];
        iVar6 = iVar6 + -1;
        pbVar11 = param_1 + 1;
      } while (0 < iVar6);
      param_1 = param_1 + 1;
LAB_00668456:
      if (bVar2 == 0x2d) {
        uVar5 = -uVar5;
      }
      if (*pbVar10 == 0x62) {
        *(byte *)local_40c = (byte)uVar5;
        local_40c = (uint *)((int)local_40c + 1);
      }
      if (*pbVar10 == 0x77) {
        *(short *)local_40c = (short)uVar5;
        local_40c = (uint *)((int)local_40c + 2);
      }
      if (*pbVar10 == 0x6c) {
        *local_40c = uVar5;
        local_40c = local_40c + 1;
      }
    }
    else if (iVar6 != 0) goto LAB_0066840c;
    if ((*pbVar10 == 0x73) && (0 < iVar8)) {
      iVar6 = 0;
      puVar7 = local_40c;
      while (((bVar2 = *param_1, '/' < (char)bVar2 || (bVar2 == 0x25)) &&
             ((int)((1 - (int)local_40c) + (int)puVar7) < iVar8))) {
        if (bVar2 == 0x25) {
          pbVar11 = param_1 + 1;
          pbVar1 = param_1 + 2;
          param_1 = param_1 + 3;
          *(char *)puVar7 =
               "0000000000000000111111111111111122222222222222223333333333333333444444444444444455555555555555556666666666666666777777777777777788888888888888889999999999999999aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbccccccccccccccccddddddddddddddddeeeeeeeeeeeeeeeeffffffffffffffff0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
               [(char)*pbVar11 + 0x200] | (&DAT_006ab0b8)[(char)*pbVar1];
          iVar6 = iVar6 + 1;
          puVar7 = (uint *)((int)puVar7 + 1);
        }
        else {
          param_1 = param_1 + 1;
          *(byte *)puVar7 = bVar2;
          iVar6 = iVar6 + 1;
          puVar7 = (uint *)((int)puVar7 + 1);
        }
      }
      if (iVar6 < iVar8) {
        uVar9 = iVar8 - iVar6;
        pbVar11 = (byte *)(iVar6 + (int)local_40c);
        for (uVar5 = uVar9 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          pbVar11[0] = 0;
          pbVar11[1] = 0;
          pbVar11[2] = 0;
          pbVar11[3] = 0;
          pbVar11 = pbVar11 + 4;
        }
        for (uVar5 = uVar9 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pbVar11 = 0;
          pbVar11 = pbVar11 + 1;
        }
        iVar6 = iVar6 + uVar9;
      }
      local_40c = (uint *)((int)local_40c + iVar6);
      if (*param_1 == 0x2c) {
        param_1 = param_1 + 1;
      }
    }
    if (local_408 <= local_40c) break;
    param_4 = pbVar10 + 1;
    if (pbVar10[1] == 0x2a) {
      param_4 = pbVar10;
    }
    bVar2 = *param_4;
  }
  return (int)local_40c - (int)puVar3;
}


// ==== 0x668590 FUN_00668590

void FUN_00668590(char *param_1,int param_2)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  int *piVar5;
  int local_24 [4];
  int local_14;
  int local_10;
  undefined4 local_4;
  int iVar4;
  
  pcVar2 = (char *)0x0;
  if (param_1 == (char *)0x0) goto LAB_00668700;
  cVar3 = *param_1;
  if (cVar3 == '$') {
    cVar3 = param_1[1];
    pcVar1 = param_1;
    if (cVar3 < '0') goto LAB_00668700;
    do {
      iVar4 = (int)cVar3;
      cVar3 = pcVar1[2];
      param_1 = (char *)((int)pcVar2 << 4 | (uint)(byte)(&DAT_006ab0b8)[iVar4]);
      pcVar2 = param_1;
      pcVar1 = pcVar1 + 1;
    } while ('/' < cVar3);
  }
  else {
    if ((cVar3 < '0') || ('9' < cVar3)) goto LAB_00668700;
    pcVar2 = (char *)FUN_006670d0();
    if (' ' < *pcVar2) {
      if ('9' < cVar3) goto LAB_00668700;
      piVar5 = local_24;
      for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar5 = 0;
        piVar5 = piVar5 + 1;
      }
      local_4 = 0xffffffff;
      FUN_006670d0();
      FUN_006670d0();
      FUN_006670d0();
      FUN_006670d0();
      FUN_006670d0();
      FUN_006670d0();
      if ((((local_10 < 0x7b2) || (0x833 < local_10)) || (local_14 < 1)) ||
         (((0xc < local_14 || (local_24[3] < 1)) || (iVar4 = local_10, 0x1f < local_24[3])))) {
        iVar4 = 0;
      }
      if (((local_24[2] < 0) || (0x17 < local_24[2])) ||
         (((local_24[1] < 0 || (((0x3b < local_24[1] || (local_24[0] < 0)) || (0x3d < local_24[0])))
           ) || (iVar4 == 0)))) goto LAB_00668700;
      local_14 = local_14 + -1;
      local_10 = iVar4 + -0x76c;
      param_1 = (char *)FUN_00667260();
    }
  }
  if (param_1 != (char *)0x0) {
    return;
  }
LAB_00668700:
  if (param_2 != 0) {
    return;
  }
  FUN_0066ef60();
  return;
}


// ==== 0x668720 FUN_00668720

uint __fastcall FUN_00668720(undefined4 param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  int unaff_ESI;
  
  uVar1 = 0;
  if (*(uint *)(param_2 + 4) != 0) {
    piVar2 = (int *)(param_2 + 0x18);
    do {
      if (*piVar2 == unaff_ESI) {
        return uVar1;
      }
      uVar1 = uVar1 + 1;
      piVar2 = piVar2 + 4;
    } while (uVar1 < *(uint *)(param_2 + 4));
  }
  return 0xffffffff;
}


// ==== 0x668740 FUN_00668740

uint __fastcall FUN_00668740(int param_1)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  char *pcVar5;
  
  uVar3 = 0;
  uVar1 = 0;
  bVar4 = 0;
  if (*(uint *)(param_1 + 4) != 0) {
    pcVar5 = (char *)(param_1 + 0x1f);
    do {
      bVar2 = *(char *)(param_1 + 8) - *pcVar5;
      if (bVar4 < bVar2) {
        uVar1 = uVar3;
        bVar4 = bVar2;
      }
      uVar3 = uVar3 + 1;
      pcVar5 = pcVar5 + 0x10;
    } while (uVar3 < *(uint *)(param_1 + 4));
  }
  return uVar1;
}


// ==== 0x668790 FUN_00668790

undefined4 __fastcall FUN_00668790(int param_1,int param_2)

{
  longlong lVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = param_2 - *(int *)(param_1 + 0xc);
  lVar1 = (ulonglong)uVar4 * 0x10624dd3;
  uVar3 = (undefined4)lVar1;
  uVar4 = uVar4 / 1000;
  if (uVar4 != 0) {
    cVar2 = *(char *)(param_1 + 8) + (char)uVar4;
    uVar3 = CONCAT31((int3)((ulonglong)lVar1 >> 8),cVar2);
    *(char *)(param_1 + 8) = cVar2;
    *(uint *)(param_1 + 0xc) = uVar4 * 1000 + *(int *)(param_1 + 0xc);
  }
  return uVar3;
}


// ==== 0x6687c0 FUN_006687c0

uint FUN_006687c0(void)

{
  uint in_EAX;
  uint uVar1;
  
  if ((in_EAX & 0x2000) != 0) {
    return 0xfffffffe;
  }
  uVar1 = in_EAX & 0xffff0fff;
  if (uVar1 == 0) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ==== 0x6687e0 FUN_006687e0

int * FUN_006687e0(int param_1)

{
  int *piVar1;
  DWORD DVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  
  if (DAT_007177c4 != (int *)0x0) {
    DAT_007177c8 = DAT_007177c8 + 1;
    return DAT_007177c4;
  }
  uVar5 = (param_1 + -1) * 0x10 + 0x28;
  piVar1 = (int *)FUN_00549460(uVar5);
  piVar3 = (int *)0x0;
  if (piVar1 != (int *)0x0) {
    piVar3 = piVar1;
    for (uVar5 = uVar5 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *piVar3 = 0;
      piVar3 = piVar3 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)piVar3 = 0;
      piVar3 = (int *)((int)piVar3 + 1);
    }
    *piVar1 = param_1;
    DVar2 = GetTickCount();
    piVar1[4] = DVar2;
    piVar1[3] = DVar2;
    iVar4 = FUN_0066f1b0();
    piVar1[5] = iVar4;
    if (iVar4 == 0) {
      FUN_00447030(piVar1);
      return (int *)0x0;
    }
    DAT_007177c8 = 1;
    piVar3 = piVar1;
    DAT_007177c4 = piVar1;
  }
  return piVar3;
}


// ==== 0x668870 FUN_00668870

void FUN_00668870(int param_1)

{
  DAT_007177c8 = DAT_007177c8 + -1;
  if (DAT_007177c8 < 1) {
    FUN_0066f2a0(*(undefined4 *)(param_1 + 0x14));
    FUN_00447030(param_1);
    DAT_007177c4 = 0;
    DAT_007177c8 = 0;
  }
  return;
}


// ==== 0x6688b0 FUN_006688b0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006688b0(int param_1)

{
  undefined4 *puVar1;
  char cVar2;
  DWORD DVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  ushort *puVar8;
  uint unaff_retaddr;
  uint local_a0;
  undefined4 local_9c;
  uint local_98;
  int local_94;
  int iStack_90;
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  DVar3 = GetTickCount();
  FUN_00668790();
  uVar7 = 0;
  local_98 = (DVar3 - *(int *)(param_1 + 0x10)) / 100;
  local_a0 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    puVar8 = (ushort *)(param_1 + 0x1c);
    do {
      if ((char)puVar8[1] == *(char *)(param_1 + 8)) {
        if ((byte)(*(char *)(param_1 + 8) - *(char *)((int)puVar8 + 3)) < 0x3c) {
          *puVar8 = *puVar8 & 0xfff | 0x8000;
          cVar2 = *(char *)(param_1 + 8) + -1;
          *(char *)((int)puVar8 + 3) = cVar2;
          *(char *)(puVar8 + 1) = cVar2;
        }
        else {
          puVar1 = (undefined4 *)(*(int *)(param_1 + 4) * 0x10 + 8 + param_1);
          *(undefined4 *)(puVar8 + -2) = *puVar1;
          *(undefined4 *)puVar8 = puVar1[1];
          *(undefined4 *)(puVar8 + 2) = puVar1[2];
          *(undefined4 *)(puVar8 + 4) = puVar1[3];
          *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
        }
      }
      if (((*puVar8 & 0x8000) != 0) && (local_a0 < local_98)) {
        local_84[0] = 0;
        FUN_00667690(local_84,0x80,&DAT_006ab854,uVar7);
        FUN_00667690(local_84,0x80,&DAT_006aac3c,*(undefined4 *)(puVar8 + -2));
        FUN_0066f2f0(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(puVar8 + -2),local_84,0x80);
        *puVar8 = *puVar8 & 0xfff | 0x4000;
        cVar2 = *(char *)(param_1 + 8) + -1;
        *(char *)((int)puVar8 + 3) = cVar2;
        *(char *)(puVar8 + 1) = cVar2;
        local_a0 = local_a0 + 1;
        *(DWORD *)(param_1 + 0x10) = DVar3;
      }
      if (((*puVar8 & 0x4000) != 0) && ((char)(*(char *)(param_1 + 8) - (char)puVar8[1]) == '\x05'))
      {
        *puVar8 = 0x2000;
        if (*(code **)(puVar8 + 2) != (code *)0x0) {
          (**(code **)(puVar8 + 2))(*(undefined4 *)(puVar8 + -2),0x2000,*(undefined4 *)(puVar8 + 4))
          ;
        }
      }
      uVar7 = uVar7 + 1;
      puVar8 = puVar8 + 8;
    } while (uVar7 < *(uint *)(param_1 + 4));
  }
  local_9c = 0x80;
  iVar4 = FUN_0066f4d0(*(undefined4 *)(param_1 + 0x14),local_84,&local_9c,&local_94);
  do {
    if (iVar4 == 0) {
      return;
    }
    uVar5 = FUN_00667530(local_84,&DAT_006ab854,0);
    iVar4 = FUN_00667ec0(uVar5);
    if (((iVar4 < 0) || (*(int *)(param_1 + 4) <= iVar4)) ||
       (iVar6 = iVar4 * 0x10 + 0x18 + param_1, *(int *)(iVar4 * 0x10 + 0x18 + param_1) != iStack_90)
       ) {
      iVar4 = FUN_00668720();
      if (iVar4 != -1) {
        iVar6 = iVar4 * 0x10 + param_1 + 0x18;
        goto LAB_00668abd;
      }
    }
    else {
LAB_00668abd:
      if (iVar6 != 0) {
        if (0xfff < local_94) {
          local_94 = 0xfff;
        }
        *(short *)(iVar6 + 4) = (short)local_94;
        if (*(code **)(iVar6 + 8) != (code *)0x0) {
          (**(code **)(iVar6 + 8))(iStack_90,local_94,*(undefined4 *)(iVar6 + 0xc));
        }
      }
    }
    iVar4 = FUN_0066f4d0(*(undefined4 *)(param_1 + 0x14),local_84,&local_9c,&local_94);
  } while( true );
}


// ==== 0x668b40 FUN_00668b40

void FUN_00668b40(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  
  iVar1 = FUN_00668720();
  if (iVar1 != -1) {
    *(char *)((int)param_1 + iVar1 * 0x10 + 0x1f) = (char)param_1[2] + -1;
    FUN_006687c0();
    return;
  }
  iVar1 = param_1[1];
  if (iVar1 == *param_1) {
    iVar1 = FUN_00668740();
  }
  else {
    param_1[1] = iVar1 + 1;
  }
  piVar2 = param_1 + iVar1 * 4 + 6;
  *piVar2 = param_2;
  *(undefined2 *)(piVar2 + 1) = 0x8000;
  cVar3 = (char)param_1[2] + -1;
  *(char *)((int)piVar2 + 7) = cVar3;
  *(char *)((int)piVar2 + 6) = cVar3;
  piVar2[2] = param_3;
  piVar2[3] = param_4;
  FUN_006687c0();
  return;
}


// ==== 0x668bc0 FUN_00668bc0

undefined4 FUN_00668bc0(int param_1)

{
  int iVar1;
  char cVar2;
  
  iVar1 = FUN_00668720();
  if (iVar1 != -1) {
    iVar1 = iVar1 * 0x10 + 0x18 + param_1;
    *(undefined2 *)(iVar1 + 4) = 0x8000;
    cVar2 = *(char *)(param_1 + 8) + -1;
    *(char *)(iVar1 + 7) = cVar2;
    *(char *)(iVar1 + 6) = cVar2;
    return 1;
  }
  return 0;
}


// ==== 0x668c00 FUN_00668c00

undefined4 __fastcall FUN_00668c00(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar1 = FUN_00663390(param_1);
  if (iVar1 != 0) {
    iVar2 = (**(code **)(iVar1 + 8))(iVar1);
    while (iVar2 == 0) {
      Sleep(10);
      iVar2 = (**(code **)(iVar1 + 8))(iVar1);
    }
    uVar3 = *(undefined4 *)(iVar1 + 4);
    (**(code **)(iVar1 + 0xc))(iVar1);
  }
  return uVar3;
}


// ==== 0x668c50 FUN_00668c50

void FUN_00668c50(void)

{
  FUN_00668c00();
  return;
}


// ==== 0x668c60 FUN_00668c60

int FUN_00668c60(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  
  if (param_3 < 0) {
    bVar1 = *param_1;
    if (bVar1 != 0) {
      do {
        if (bVar1 != *param_2) {
          return (uint)*param_1 - (uint)*param_2;
        }
        bVar1 = param_1[1];
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
      } while (bVar1 != 0);
      return 0;
    }
  }
  else if (0 < param_3) {
    iVar2 = (int)param_2 - (int)param_1;
    do {
      if ((uint)*param_1 - (uint)param_1[iVar2] != 0) {
        return (uint)*param_1 - (uint)param_1[iVar2];
      }
      param_1 = param_1 + 1;
      param_3 = param_3 + -1;
    } while (0 < param_3);
  }
  return 0;
}


// ==== 0x668cc0 FUN_00668cc0

void FUN_00668cc0(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    param_1 = &DAT_007177d0;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  return;
}


// ==== 0x668cf0 FUN_00668cf0

void FUN_00668cf0(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    param_1 = &DAT_007177d0;
  }
  param_1[2] = 0;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  return;
}


// ==== 0x668d10 FUN_00668d10

undefined4 FUN_00668d10(DWORD *param_1)

{
  DWORD DVar1;
  LONG LVar2;
  
  if (param_1 == (DWORD *)0x0) {
    param_1 = &DAT_007177d0;
  }
  DVar1 = GetCurrentThreadId();
  if (*param_1 != DVar1) {
    LVar2 = InterlockedExchange((LONG *)(param_1 + 2),1);
    if (LVar2 != 0) {
      return 0;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
    DVar1 = GetCurrentThreadId();
    *param_1 = DVar1;
  }
  param_1[1] = param_1[1] + 1;
  return 1;
}


// ==== 0x668d60 FUN_00668d60

void FUN_00668d60(DWORD *param_1)

{
  int iVar1;
  LONG LVar2;
  DWORD DVar3;
  DWORD *local_4;
  
  if (param_1 == (DWORD *)0x0) {
    local_4 = &DAT_007177d0;
  }
  else {
    local_4 = param_1;
  }
  iVar1 = FUN_00668d10(param_1);
  if (iVar1 == 0) {
    while( true ) {
      EnterCriticalSection((LPCRITICAL_SECTION)(local_4 + 3));
      LVar2 = InterlockedExchange((LONG *)(local_4 + 2),1);
      if (LVar2 == 0) break;
      LeaveCriticalSection((LPCRITICAL_SECTION)(local_4 + 3));
      iVar1 = FUN_00668d10(param_1);
      if (iVar1 != 0) {
        return;
      }
    }
    DVar3 = GetCurrentThreadId();
    *local_4 = DVar3;
    local_4[1] = local_4[1] + 1;
  }
  return;
}


// ==== 0x668df0 FUN_00668df0

void FUN_00668df0(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    param_1 = &DAT_007177d0;
  }
  if (1 < (uint)param_1[1]) {
    param_1[1] = param_1[1] - 1;
    return;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  return;
}


// ==== 0x668e20 FUN_00668e20

void FUN_00668e20(int param_1,int param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    (&DAT_007177f8)[DAT_0071791c * 2] = param_1;
    (&DAT_007177fc)[DAT_0071791c * 2] = param_2;
    DAT_0071791c = DAT_0071791c + 1;
  }
  return;
}


// ==== 0x668e50 FUN_00668e50

void FUN_00668e50(void)

{
  FUN_00668d60(&DAT_007178f8);
  FUN_00668df0(&DAT_007178f8);
  return;
}


// ==== 0x668e70 FUN_00668e70

void FUN_00668e70(void)

{
  int iVar1;
  
  iVar1 = FUN_00668d10(&DAT_007178f8);
  if (iVar1 != 0) {
    iVar1 = 0;
    if (0 < DAT_0071791c) {
      do {
        if (((code *)(&DAT_007177f8)[iVar1 * 2] == (code *)0x0) || ((&DAT_007177fc)[iVar1 * 2] == 0)
           ) {
          (&DAT_007177f8)[iVar1 * 2] = *(undefined4 *)(&DAT_007177f0 + DAT_0071791c * 8);
          (&DAT_007177fc)[iVar1 * 2] = *(undefined4 *)(&DAT_007177f4 + DAT_0071791c * 8);
          *(undefined4 *)(&DAT_007177f0 + DAT_0071791c * 8) = 0;
          *(undefined4 *)(&DAT_007177f4 + DAT_0071791c * 8) = 0;
          DAT_0071791c = DAT_0071791c + -1;
          iVar1 = iVar1 + -1;
        }
        else {
          (*(code *)(&DAT_007177f8)[iVar1 * 2])((&DAT_007177fc)[iVar1 * 2]);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < DAT_0071791c);
    }
    FUN_00668df0(&DAT_007178f8);
  }
  return;
}


// ==== 0x668f00 FUN_00668f00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00668f00(void)

{
  _DAT_006eb1a8 = 1;
  while (DAT_00717920 != 0) {
    FUN_00668e70();
    Sleep(0x32);
  }
  _DAT_006eb1a8 = 0;
  return;
}


// ==== 0x668f40 FUN_00668f40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00668f40(void)

{
  DWORD local_4;
  
  DAT_0071791c = 0;
  _DAT_006eb1a8 = 0xffffffff;
  FUN_00668cc0(0);
  FUN_00668cc0(&DAT_007178f8);
  DAT_00717920 = (HANDLE)0x1;
  DAT_00717920 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00668f00,(LPVOID)0x0,0,&local_4);
  if (DAT_00717920 != (HANDLE)0x0) {
    SetThreadPriority(DAT_00717920,2);
    CloseHandle(DAT_00717920);
  }
  return;
}


// ==== 0x668fb0 FUN_00668fb0

void __fastcall FUN_00668fb0(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  byte *in_EAX;
  byte bVar2;
  
  do {
    bVar2 = *in_EAX;
    in_EAX = in_EAX + 1;
    if (('@' < (char)bVar2) && ((char)bVar2 < '[')) {
      bVar2 = bVar2 ^ 0x20;
    }
    bVar1 = *param_2;
    param_2 = param_2 + 1;
    if (('@' < (char)bVar1) && ((char)bVar1 < '[')) {
      bVar1 = bVar1 ^ 0x20;
    }
  } while ((bVar2 != 0) && (bVar2 == bVar1));
  return;
}


// ==== 0x668ff0 FUN_00668ff0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_00668ff0(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint unaff_retaddr;
  undefined4 local_f0;
  undefined1 local_e8;
  uint local_c;
  
  local_c = DAT_006eb720 ^ unaff_retaddr;
  puVar2 = &local_f0;
  for (iVar1 = 0x38; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_f0._0_1_ = 0x67;
  local_f0._1_1_ = 0x45;
  local_f0._2_1_ = 0x41;
  local_e8 = 0x3f;
  FUN_00662e80(*(undefined4 *)(param_2 + 0x38),&local_f0,0xe0,0,param_2 + 0x3c,0x10);
  return;
}


// ==== 0x669060 FUN_00669060

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00669060(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  DWORD DVar5;
  char *pcVar6;
  undefined4 *puVar7;
  short *psVar8;
  undefined4 *puVar9;
  short *psVar10;
  int *piVar11;
  bool bVar12;
  uint unaff_retaddr;
  uint uStack_10c;
  short local_108;
  short sStack_106;
  undefined1 uStack_104;
  undefined1 uStack_103;
  undefined1 uStack_102;
  undefined1 uStack_101;
  undefined4 local_f8;
  short local_f4;
  short sStack_f2;
  undefined1 uStack_f0;
  undefined1 uStack_ef;
  undefined1 uStack_ee;
  undefined1 uStack_ed;
  char local_e4;
  char cStack_e3;
  char cStack_e2;
  byte bStack_e1;
  int iStack_e0;
  char local_dc [32];
  char acStack_bc [64];
  char acStack_7c [120];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  iVar4 = FUN_00668d10(param_3);
  if (iVar4 != 0) {
    iVar4 = *(int *)(param_3 + 0x38);
    while (iVar4 != 0) {
      if (0 < *(int *)(param_3 + 0x30)) {
        *(undefined4 *)(param_3 + 0x30) = 0;
        FUN_00668ff0();
      }
      local_dc[0] = '\0';
      local_f8 = 0x10;
      iVar4 = FUN_00662f00(*(undefined4 *)(param_3 + 0x38),&local_e4,0xe0,0,&local_108,&local_f8);
      if ((iVar4 < 1) || (local_dc[0] == '\0')) break;
      FUN_00663190(&local_f4,0x10,&local_108,0x10);
      uStack_10c = 0;
      if ((local_f4 == local_108) && (local_108 == 2)) {
        bVar12 = true;
        iVar4 = 3;
        psVar8 = &sStack_106;
        psVar10 = &sStack_f2;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar12 = *psVar8 == *psVar10;
          psVar8 = psVar8 + 1;
          psVar10 = psVar10 + 1;
        } while (bVar12);
        uStack_10c = (uint)bVar12;
      }
      if (((local_e4 == 'g') && (cStack_e3 == 'E')) && (cStack_e2 == 'A')) {
        if ((local_dc[0] == '?') && (local_dc[1] == '\0')) {
          DVar5 = GetTickCount();
          for (iVar4 = *(int *)(param_3 + 0x24); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x100)) {
            if (DVar5 + 1000 < *(uint *)(iVar4 + 0xe0)) {
              *(DWORD *)(iVar4 + 0xe0) = DVar5 + 1000;
            }
          }
        }
        else if (acStack_bc[0] != '\0') {
          puVar9 = *(undefined4 **)(param_3 + 0x28);
          puVar3 = *(undefined4 **)(param_3 + 0x2c);
          puVar7 = (undefined4 *)0x0;
          if (puVar9 == puVar3) {
LAB_00669203:
            if (puVar7 != (undefined4 *)0x0) {
              puVar9 = puVar7;
              for (iVar4 = 0x41; iVar4 != 0; iVar4 = iVar4 + -1) {
                *puVar9 = 0;
                puVar9 = puVar9 + 1;
              }
              puVar7[1] = iStack_e0;
              pcVar6 = local_dc;
              do {
                cVar2 = *pcVar6;
                pcVar6[(int)puVar7 + (8 - (int)local_dc)] = cVar2;
                pcVar6 = pcVar6 + 1;
              } while (cVar2 != '\0');
              pcVar6 = acStack_bc;
              do {
                cVar2 = *pcVar6;
                pcVar6[(int)puVar7 + (0x28 - (int)acStack_bc)] = cVar2;
                pcVar6 = pcVar6 + 1;
              } while (cVar2 != '\0');
              *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
              puVar9 = puVar7;
            }
          }
          else {
            do {
              if ((puVar7 == (undefined4 *)0x0) && (*(char *)(puVar9 + 10) == '\0')) {
                puVar7 = puVar9;
              }
              iVar4 = FUN_00668fb0();
            } while ((((iVar4 != 0) || (iVar4 = FUN_00668fb0(), iVar4 != 0)) ||
                     (iStack_e0 != puVar9[1])) &&
                    (puVar9 = puVar9 + 0x41, puVar9 != *(undefined4 **)(param_3 + 0x2c)));
            if (puVar9 == puVar3) goto LAB_00669203;
          }
          if (puVar9 != *(undefined4 **)(param_3 + 0x2c)) {
            pcVar6 = acStack_7c;
            do {
              cVar2 = *pcVar6;
              pcVar6[(int)puVar9 + (0x68 - (int)acStack_7c)] = cVar2;
              pcVar6 = pcVar6 + 1;
            } while (cVar2 != '\0');
            DVar5 = GetTickCount();
            puVar9[0x3f] = uStack_10c;
            puVar9[0x38] = DVar5 + 1000 + (uint)bStack_e1 * 2000;
            puVar9[0x3d] = CONCAT31(CONCAT21(CONCAT11(uStack_104,uStack_103),uStack_102),uStack_101)
            ;
            puVar9[0x3e] = CONCAT31(CONCAT21(CONCAT11(uStack_f0,uStack_ef),uStack_ee),uStack_ed);
            FUN_00662490(&local_108,puVar9 + 0x39,0x10);
            *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
          }
        }
      }
      iVar4 = *(int *)(param_3 + 0x38);
    }
    DVar5 = GetTickCount();
    iVar4 = *(int *)(param_3 + 0x28);
    if (iVar4 != *(int *)(param_3 + 0x2c)) {
      do {
        if ((*(char *)(iVar4 + 0x28) != '\0') &&
           (((*(char *)(iVar4 + 0x68) == '\0' || (*(uint *)(iVar4 + 0xe0) == 0)) ||
            (*(uint *)(iVar4 + 0xe0) < DVar5)))) {
          *(undefined1 *)(iVar4 + 0x28) = 0;
          *(undefined1 *)(iVar4 + 8) = 0;
          *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
        }
        iVar4 = iVar4 + 0x104;
      } while (iVar4 != *(int *)(param_3 + 0x2c));
    }
    piVar1 = (int *)(param_3 + 0x24);
    iVar4 = *piVar1;
    piVar11 = piVar1;
    while (iVar4 != 0) {
      iVar4 = *piVar11;
      if (*(int *)(iVar4 + 0xe0) == 0) {
        *piVar11 = *(int *)(iVar4 + 0x100);
        *(undefined1 *)(iVar4 + 0x68) = 0;
        FUN_00662e80(*(undefined4 *)(param_3 + 0x38),iVar4,0xe0,0,param_3 + 0x3c,0x10);
        FUN_00447030(iVar4);
      }
      else {
        piVar11 = (int *)(iVar4 + 0x100);
      }
      iVar4 = *piVar11;
    }
    DVar5 = GetTickCount();
    for (iVar4 = *piVar1; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x100)) {
      if (*(uint *)(iVar4 + 0xe0) < DVar5) {
        FUN_00662e80(*(undefined4 *)(param_3 + 0x38),iVar4,0xe0,0,param_3 + 0x3c,0x10);
        *(uint *)(iVar4 + 0xe0) = (uint)*(byte *)(iVar4 + 3) * 1000 + DVar5;
      }
    }
    FUN_00668df0(param_3);
  }
  return 0;
}


// ==== 0x669430 FUN_00669430

undefined4
FUN_00669430(int param_1,char *param_2,char *param_3,char *param_4,char *param_5,int param_6)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  DWORD DVar6;
  
  if (param_6 == 0) {
    param_6 = 0x1e;
  }
  else if (param_6 < 2) {
    param_6 = 2;
  }
  else if (0xfa < param_6) {
    param_6 = 0xfa;
  }
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
      iVar2 = *(int *)(param_1 + 0x24);
      while( true ) {
        if (iVar2 == 0) {
          puVar5 = (undefined1 *)FUN_00549460(0x104);
          uVar3 = *(undefined4 *)(puVar5 + 0xe0);
          puVar5[6] = (char)((uint)uVar3 >> 8);
          puVar5[5] = (char)((uint)uVar3 >> 0x10);
          puVar5[7] = puVar5[0xe0];
          *puVar5 = 0x67;
          puVar5[1] = 0x45;
          puVar5[2] = 0x41;
          puVar5[3] = (char)param_6;
          puVar5[4] = (char)((uint)uVar3 >> 0x18);
          iVar2 = 8 - (int)param_2;
          do {
            cVar1 = *param_2;
            param_2[(int)(puVar5 + iVar2)] = cVar1;
            param_2 = param_2 + 1;
          } while (cVar1 != '\0');
          iVar2 = 0x28 - (int)param_3;
          do {
            cVar1 = *param_3;
            param_3[(int)(puVar5 + iVar2)] = cVar1;
            param_3 = param_3 + 1;
          } while (cVar1 != '\0');
          iVar2 = 0x68 - (int)param_5;
          do {
            cVar1 = *param_5;
            param_5[(int)(puVar5 + iVar2)] = cVar1;
            param_5 = param_5 + 1;
          } while (cVar1 != '\0');
          iVar2 = 0x48 - (int)param_4;
          do {
            cVar1 = *param_4;
            param_4[(int)(puVar5 + iVar2)] = cVar1;
            param_4 = param_4 + 1;
          } while (cVar1 != '\0');
          FUN_00662e80(*(undefined4 *)(param_1 + 0x38),puVar5,0xe0,0,param_1 + 0x3c,0x10);
          DVar6 = GetTickCount();
          *(DWORD *)(puVar5 + 0xe0) = DVar6 + 0xfa;
          FUN_00668d60(param_1);
          *(undefined4 *)(puVar5 + 0x100) = *(undefined4 *)(param_1 + 0x24);
          *(undefined1 **)(param_1 + 0x24) = puVar5;
          FUN_00668df0(param_1);
          return 0;
        }
        iVar4 = FUN_00668fb0();
        if ((iVar4 == 0) && (iVar4 = FUN_00668fb0(), iVar4 == 0)) break;
        iVar2 = *(int *)(iVar2 + 0x100);
      }
      iVar4 = FUN_00668fb0();
      if (iVar4 != 0) {
        iVar4 = (iVar2 + 0x68) - (int)param_5;
        do {
          cVar1 = *param_5;
          param_5[iVar4] = cVar1;
          param_5 = param_5 + 1;
        } while (cVar1 != '\0');
        *(undefined4 *)(iVar2 + 0xe0) = 0;
      }
      return 0;
    }
    return 0xfffffffe;
  }
  return 0xffffffff;
}


// ==== 0x6695f0 FUN_006695f0

int FUN_006695f0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  FUN_00668d60(param_1);
  iVar1 = *(int *)(param_1 + 0x24);
  do {
    if (iVar1 == 0) {
LAB_0066964c:
      FUN_00668df0(param_1);
      return (iVar1 != 0) - 1;
    }
    if (((param_2 == 0) || (iVar2 = FUN_00668fb0(), iVar2 == 0)) &&
       ((param_3 == 0 || (iVar2 = FUN_00668fb0(), iVar2 == 0)))) {
      *(undefined4 *)(iVar1 + 0xe0) = 0;
      goto LAB_0066964c;
    }
    iVar1 = *(int *)(iVar1 + 0x100);
  } while( true );
}


// ==== 0x669660 FUN_00669660

undefined4
FUN_00669660(int param_1,char *param_2,char *param_3,undefined4 *param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != 0) {
    iVar3 = *(int *)(param_1 + 0x28);
    iVar1 = *(int *)(param_1 + 0x2c);
    if (iVar3 != iVar1) {
      while (((((*(char *)(iVar3 + 0x28) == '\0' || (*(int *)(iVar3 + 0xfc) != 0)) ||
               ((param_2 != (char *)0x0 &&
                ((*param_2 != '\0' && (iVar2 = FUN_00668fb0(), iVar2 != 0)))))) ||
              ((param_3 != (char *)0x0 &&
               ((*param_3 != '\0' && (iVar2 = FUN_00668fb0(), iVar2 != 0)))))) ||
             (*(int *)(iVar3 + 0xf4) == 0))) {
        iVar3 = iVar3 + 0x104;
        if (iVar3 == iVar1) {
          return param_5;
        }
      }
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = *(undefined4 *)(iVar3 + 0xf8);
      }
      param_5 = *(undefined4 *)(iVar3 + 0xf4);
    }
  }
  return param_5;
}


// ==== 0x669720 FUN_00669720

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 * FUN_00669720(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint unaff_retaddr;
  undefined2 local_14;
  undefined2 local_12;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  if (DAT_00717934 != (undefined4 *)0x0) {
    DAT_00717930 = DAT_00717930 + 1;
    return DAT_00717934;
  }
  puVar1 = (undefined4 *)FUN_00549460(0x50);
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = puVar1;
    for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    if (param_1 < 4) {
      param_1 = 4;
    }
    puVar2 = (undefined4 *)FUN_00549460(param_1 * 0x104);
    puVar1[10] = puVar2;
    if (puVar2 != (undefined4 *)0x0) {
      puVar1[0xb] = puVar2 + param_1 * 0x41;
      uVar4 = (int)(puVar2 + param_1 * 0x41) - (int)puVar2;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar2 = 0;
        puVar2 = (undefined4 *)((int)puVar2 + 1);
      }
      puVar1[0x13] = 1;
      iVar3 = FUN_00662c30(2,2,0);
      if (iVar3 != 0) {
        DAT_00717930 = 1;
        DAT_00717934 = puVar1;
        FUN_00668cc0(puVar1);
        FUN_00668d60(puVar1);
        local_14 = 2;
        local_10 = 0;
        local_c = 0;
        local_8 = 0;
        local_12 = 0xf27;
        FUN_00662d70(iVar3,&local_14,0x10);
        puVar1[0xf] = 0xf270002;
        puVar1[0x10] = 0xffffffff;
        puVar1[0x11] = 0;
        puVar1[0x12] = 0;
        puVar1[0xc] = 1;
        puVar1[0xe] = iVar3;
        FUN_00663160(iVar3,2,100,puVar1,FUN_00669060);
        FUN_00668df0(puVar1);
        FUN_00668ff0();
        return puVar1;
      }
    }
    FUN_00447030(puVar1);
    return (undefined4 *)0x0;
  }
  return (undefined4 *)0x0;
}


// ==== 0x6698c0 FUN_006698c0

void FUN_006698c0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 != 0) {
    if (1 < DAT_00717930) {
      DAT_00717930 = DAT_00717930 + -1;
      return;
    }
    iVar1 = *(int *)(param_1 + 0x24);
    DAT_00717934 = 0;
    DAT_00717930 = 0;
    while (iVar1 != 0) {
      FUN_006695f0(param_1,*(int *)(param_1 + 0x24) + 8,*(int *)(param_1 + 0x24) + 0x28);
      FUN_00669060(*(undefined4 *)(param_1 + 0x38),0,param_1);
      iVar1 = *(int *)(param_1 + 0x24);
    }
    FUN_00668d60(param_1);
    uVar2 = *(undefined4 *)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0x38) = 0;
    FUN_00662ce0(uVar2);
    FUN_00668df0(param_1);
    FUN_00668cf0(param_1);
    FUN_00447030(*(undefined4 *)(param_1 + 0x28));
    FUN_00447030(param_1);
  }
  return;
}


// ==== 0x669960 FUN_00669960

void FUN_00669960(LPHLINE param_1,DWORD_PTR param_2,DWORD param_3,DWORD param_4)

{
  LONG LVar1;
  DWORD unaff_ESI;
  HLINEAPP unaff_EDI;
  DWORD local_14;
  lineextensionid_tag local_10;
  
  local_14 = 0;
  LVar1 = lineNegotiateAPIVersion(unaff_EDI,unaff_ESI,0x10004,0x20002,&local_14,&local_10);
  if (LVar1 == 0) {
    lineOpen(unaff_EDI,unaff_ESI,param_1,local_14,0,param_2,param_3,param_4,(LPLINECALLPARAMS)0x0);
  }
  return;
}


// ==== 0x6699c0 FUN_006699c0

LONG FUN_006699c0(void)

{
  HLINE in_EAX;
  LONG LVar1;
  
  if (in_EAX != 0xffffffff) {
    LVar1 = lineClose(in_EAX);
    return LVar1;
  }
  return -0x7fffffd5;
}


// ==== 0x6699e0 FUN_006699e0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006699e0(HLINE param_1)

{
  LONG LVar1;
  int iVar2;
  varstring_tag *pvVar3;
  uint unaff_retaddr;
  varstring_tag local_130;
  undefined4 local_118;
  uint local_c;
  
  local_c = DAT_006eb720 ^ unaff_retaddr;
  pvVar3 = &local_130;
  for (iVar2 = 0x47; iVar2 != 0; iVar2 = iVar2 + -1) {
    pvVar3->dwTotalSize = 0;
    pvVar3 = (varstring_tag *)&pvVar3->dwNeededSize;
  }
  local_130.dwTotalSize = 0x11c;
  LVar1 = lineGetID(param_1,0,0,1,&local_130,"comm/datamodem");
  if (LVar1 != 0) {
    return 0xffffffff;
  }
  return local_118;
}


// ==== 0x669a60 FUN_00669a60

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00669a60(HLINE param_1,LPHCALL param_2,DWORD param_3)

{
  char cVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  int iVar4;
  char *unaff_ESI;
  linecallparams_tag *plVar5;
  uint unaff_retaddr;
  linecallparams_tag local_480 [6];
  uint local_c;
  
  local_c = DAT_006eb720 ^ unaff_retaddr;
  plVar5 = local_480;
  for (iVar4 = 0x11c; iVar4 != 0; iVar4 = iVar4 + -1) {
    plVar5->dwTotalSize = 0;
    plVar5 = (linecallparams_tag *)&plVar5->dwBearerMode;
  }
  local_480[0].dwBearerMode = 1;
  local_480[0].dwAddressMode = 1;
  local_480[0].dwTotalSize = 0x470;
  local_480[0].dwMediaMode = 0x10;
  local_480[0].dwCallParamFlags = 2;
  local_480[0].dwAddressID = 0;
  local_480[0].dwDisplayableAddressOffset = 0x70;
  iVar4 = 0x70 - (int)unaff_ESI;
  do {
    cVar1 = *unaff_ESI;
    unaff_ESI[(int)local_480 + iVar4] = cVar1;
    unaff_ESI = unaff_ESI + 1;
  } while (cVar1 != '\0');
  pDVar3 = &local_480[0].dwPredictiveAutoTransferStates;
  do {
    DVar2 = *pDVar3;
    pDVar3 = (DWORD *)((int)pDVar3 + 1);
  } while ((char)DVar2 != '\0');
  local_480[0].dwDisplayableAddressSize =
       (int)pDVar3 - (int)((int)&local_480[0].dwPredictiveAutoTransferStates + 1);
  lineMakeCall(param_1,param_2,(LPCSTR)&local_480[0].dwPredictiveAutoTransferStates,param_3,
               local_480);
  return;
}


// ==== 0x669b20 FUN_00669b20

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00669b20(HCALL param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  LONG LVar3;
  bool bVar4;
  uint unaff_retaddr;
  CHAR local_104 [256];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  if (param_2 != 2) {
    return;
  }
  if (param_4 != 0x4000) {
    if (param_4 == 2) {
      if ((*(int *)(param_3 + 0x80) != 4) && (*(int *)(param_3 + 0x80) != 7)) {
        return;
      }
      *(HCALL *)(param_3 + 0x7c) = param_1;
      LVar3 = lineAnswer(param_1,(LPCSTR)0x0,0);
      *(LONG *)(param_3 + 0x84) = LVar3;
      bVar4 = LVar3 == 0;
    }
    else {
      bVar4 = param_4 == 0x100;
    }
    if (!bVar4) {
      return;
    }
    iVar2 = *(int *)(param_3 + 0x80);
    if ((iVar2 == 4) || (iVar2 == 3)) {
      iVar2 = FUN_006699e0(*(undefined4 *)(param_3 + 0x78));
      if (iVar2 != -1) {
        wsprintfA(local_104,"TAPI%d:",iVar2);
        if (*(int *)(param_3 + 0x80) == 3) {
          FUN_00670740(*(undefined4 *)(param_3 + 0x68),local_104);
        }
        else {
          FUN_00670660(*(undefined4 *)(param_3 + 0x68),local_104);
        }
        goto LAB_00669e34;
      }
    }
    else {
      if ((iVar2 != 7) && (iVar2 != 6)) {
        return;
      }
      iVar2 = FUN_006699e0(*(undefined4 *)(param_3 + 0x78));
      if (iVar2 != -1) {
        wsprintfA(local_104,"TAPI%d:",iVar2);
        FUN_006702d0(*(undefined4 *)(param_3 + 0x68),local_104);
LAB_00669e34:
        *(undefined4 *)(param_3 + 0x80) = 5;
        return;
      }
    }
    FUN_006699c0();
    *(undefined4 *)(param_3 + 0x78) = 0xffffffff;
    *(undefined4 *)(param_3 + 0x80) = 8;
    return;
  }
  if (*(int *)(param_3 + 0x80) == 4) {
    lineClose(*(HLINE *)(param_3 + 0x78));
    *(undefined4 *)(param_3 + 0x78) = 0xffffffff;
    FUN_00669960((undefined4 *)(param_3 + 0x78),param_3,4,0x10);
    return;
  }
  if (*(int *)(param_3 + 0x80) == 3) {
    puVar1 = (undefined4 *)(param_3 + 0x78);
    lineClose(*(HLINE *)(param_3 + 0x78));
    *puVar1 = 0xffffffff;
    iVar2 = FUN_00669960(puVar1,param_3,1,0x10);
    if (iVar2 != 0) goto LAB_00669d1d;
    iVar2 = FUN_00669a60(*puVar1,param_3 + 0x7c,0);
    *(int *)(param_3 + 0x84) = iVar2;
    if (0 < iVar2) goto LAB_00669bf3;
  }
  else {
LAB_00669bf3:
    if (*(int *)(param_3 + 0x80) != 5) {
      return;
    }
    iVar2 = FUN_006707b0(*(undefined4 *)(param_3 + 0x68));
    if ((iVar2 == 3) && (*(char *)(param_3 + 0x88) == '\0')) {
      *(undefined4 *)(param_3 + 0x80) = 7;
      FUN_006702d0(*(undefined4 *)(param_3 + 0x68),0);
      lineClose(*(HLINE *)(param_3 + 0x78));
      *(undefined4 *)(param_3 + 0x78) = 0xffffffff;
      iVar2 = FUN_00669960((undefined4 *)(param_3 + 0x78),param_3,4,0x10);
      if (iVar2 == 0) {
        return;
      }
      *(undefined4 *)(param_3 + 0x80) = 8;
      return;
    }
    if (*(int *)(param_3 + 0x80) != 5) {
      return;
    }
    iVar2 = FUN_006707b0(*(undefined4 *)(param_3 + 0x68));
    if (iVar2 != 3) {
      return;
    }
    if (*(char *)(param_3 + 0x88) == '\0') {
      return;
    }
    *(undefined4 *)(param_3 + 0x80) = 6;
    FUN_006702d0(*(undefined4 *)(param_3 + 0x68),0);
    puVar1 = (undefined4 *)(param_3 + 0x78);
    lineClose(*(HLINE *)(param_3 + 0x78));
    *puVar1 = 0xffffffff;
    iVar2 = FUN_00669960(puVar1,param_3,1,0x10);
    if (iVar2 != 0) goto LAB_00669d1d;
    iVar2 = FUN_00669a60(*puVar1,param_3 + 0x7c,0);
    *(int *)(param_3 + 0x84) = iVar2;
    if (0 < iVar2) {
      return;
    }
  }
  lineClose(*(HLINE *)(param_3 + 0x78));
  *(HLINE *)(param_3 + 0x78) = 0xffffffff;
LAB_00669d1d:
  *(undefined4 *)(param_3 + 0x80) = 8;
  return;
}


// ==== 0x669e60 FUN_00669e60

undefined4 FUN_00669e60(int param_1)

{
  HMODULE hInstance;
  int iVar1;
  code *lpfnCallback;
  LPCSTR lpszAppName;
  LPDWORD lpdwNumDevs;
  tagMSG tStack_1c;
  
  PeekMessageA(&tStack_1c,(HWND)0x0,0,0,0);
  lpszAppName = (LPCSTR)0x0;
  lpfnCallback = FUN_00669b20;
  lpdwNumDevs = (LPDWORD)(param_1 + 0x70);
  hInstance = GetModuleHandleA((LPCSTR)0x0);
  lineInitialize((LPHLINEAPP)(param_1 + 0x74),hInstance,lpfnCallback,lpszAppName,lpdwNumDevs);
  if (*(LPDWORD)(param_1 + 0x70) != 0) {
    *(undefined4 *)(param_1 + 0x80) = 2;
    iVar1 = GetMessageA(&tStack_1c,(HWND)0x0,0,0);
    while (iVar1 != 0) {
      TranslateMessage(&tStack_1c);
      DispatchMessageA(&tStack_1c);
      iVar1 = GetMessageA(&tStack_1c,(HWND)0x0,0,0);
    }
  }
  *(undefined4 *)(param_1 + 0x80) = 1;
  return 0;
}


// ==== 0x669f10 FUN_00669f10

void FUN_00669f10(LPVOID param_1)

{
  int iVar1;
  HANDLE hHeap;
  DWORD dwFlags;
  
  FUN_006700c0(*(undefined4 *)((int)param_1 + 0x68));
  lineShutdown(*(HLINEAPP *)((int)param_1 + 0x74));
  *(undefined4 *)((int)param_1 + 0x80) = 9;
  PostThreadMessageA(*(DWORD *)((int)param_1 + 0x188),0x12,0,0);
  iVar1 = *(int *)((int)param_1 + 0x80);
  while (iVar1 == 9) {
    Sleep(0);
    iVar1 = *(int *)((int)param_1 + 0x80);
  }
  dwFlags = 0;
  hHeap = GetProcessHeap();
  HeapFree(hHeap,dwFlags,param_1);
  return;
}


// ==== 0x669f80 FUN_00669f80

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00669f80(int param_1,char *param_2,LPSTR param_3,char *param_4,CHAR param_5)

{
  char cVar1;
  HLINEAPP hLineApp;
  LPSTR pCVar2;
  DWORD DVar3;
  char *pcVar4;
  LONG LVar5;
  char *pcVar6;
  int iVar7;
  linedevcaps_tag *plVar8;
  bool bVar9;
  uint unaff_retaddr;
  DWORD local_42c;
  DWORD local_424;
  lineextensionid_tag local_420;
  linedevcaps_tag local_410 [3];
  uint local_c;
  
  pCVar2 = param_3;
  local_c = DAT_006eb720 ^ unaff_retaddr;
  *param_3 = '*';
  param_3[1] = '\0';
  param_3[2] = '\0';
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
    return 0xffffffff;
  }
  if (0x3f < (int)param_4) {
    pcVar4 = param_2;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (pcVar4 + (2 - (int)(param_2 + 1)) <= param_4) {
      local_42c = 0;
      if (*(int *)(param_1 + 0x70) != 0) {
        do {
          LVar5 = lineNegotiateAPIVersion
                            (*(HLINEAPP *)(param_1 + 0x74),local_42c,0x10004,0x20002,&local_424,
                             &local_420);
          if (LVar5 == 0) {
            hLineApp = *(HLINEAPP *)(param_1 + 0x74);
            plVar8 = local_410;
            for (iVar7 = 0x100; iVar7 != 0; iVar7 = iVar7 + -1) {
              plVar8->dwTotalSize = 0;
              plVar8 = (linedevcaps_tag *)&plVar8->dwNeededSize;
            }
            local_410[0].dwTotalSize = 0x400;
            lineGetDevCaps(hLineApp,local_42c,local_424,0,local_410);
            DVar3 = local_410[0].dwLineNameOffset;
            if (local_410[0].dwRingModes != 0) {
              iVar7 = 10;
              bVar9 = true;
              pcVar4 = param_2;
              pcVar6 = "localhost";
              do {
                if (iVar7 == 0) break;
                iVar7 = iVar7 + -1;
                bVar9 = *pcVar4 == *pcVar6;
                pcVar4 = pcVar4 + 1;
                pcVar6 = pcVar6 + 1;
              } while (bVar9);
              pcVar4 = (char *)((int)&local_410[0].dwTotalSize + local_410[0].dwLineNameOffset);
              if (bVar9) {
                pcVar6 = pcVar4;
                do {
                  cVar1 = *pcVar6;
                  pcVar6 = pcVar6 + 1;
                } while (cVar1 != '\0');
                if (param_4 < pcVar6 + (2 - ((int)&local_410[0].dwTotalSize +
                                            local_410[0].dwLineNameOffset + 1))) {
                  return 0xfffffffa;
                }
                if (param_3 != pCVar2) {
                  *param_3 = param_5;
                  param_3 = param_3 + 1;
                  param_4 = param_4 + -1;
                }
                pcVar6 = pcVar4;
                do {
                  cVar1 = *pcVar6;
                  pcVar6[(int)param_3 - (int)pcVar4] = cVar1;
                  pcVar6 = pcVar6 + 1;
                } while (cVar1 != '\0');
                pcVar6 = pcVar4;
                do {
                  cVar1 = *pcVar6;
                  pcVar6 = pcVar6 + 1;
                } while (cVar1 != '\0');
                param_3 = param_3 + ((int)pcVar6 - ((int)&local_410[0].dwTotalSize + DVar3 + 1));
                do {
                  cVar1 = *pcVar4;
                  pcVar4 = pcVar4 + 1;
                } while (cVar1 != '\0');
                param_4 = param_4 + -((int)pcVar4 - ((int)&local_410[0].dwTotalSize + DVar3 + 1));
              }
              else {
                iVar7 = __stricmp(param_2,pcVar4);
                if (iVar7 == 0) {
                  wsprintfA(param_3,"%d%c",local_42c,0);
                  return 1;
                }
              }
            }
          }
          local_42c = local_42c + 1;
        } while (local_42c < *(uint *)(param_1 + 0x70));
      }
      *param_3 = '\0';
      param_3[1] = '\0';
      return 1;
    }
  }
  return 0xfffffffa;
}


// ==== 0x66a1a0 FUN_0066a1a0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0066a1a0(int param_1,byte *param_2)

{
  byte bVar1;
  uint unaff_retaddr;
  byte abStack_44 [64];
  uint uStack_4;
  
  uStack_4 = DAT_006eb720 ^ unaff_retaddr;
  if (*(int *)(param_1 + 0x80) == 2) {
    if (((char)*param_2 < '0') || ('9' < (char)*param_2)) {
      FUN_00669f80(param_1,param_2,abStack_44,0x40,0);
      param_2 = abStack_44;
    }
    *(undefined4 *)(param_1 + 0x6c) = 0;
    bVar1 = *param_2;
    while (('/' < (char)bVar1 && ((char)bVar1 < ':'))) {
      param_2 = param_2 + 1;
      *(uint *)(param_1 + 0x6c) = (bVar1 & 0xf) + *(int *)(param_1 + 0x6c) * 10;
      bVar1 = *param_2;
    }
    *(undefined1 *)(param_1 + 0x88) = 0;
    *(undefined4 *)(param_1 + 0x80) = 4;
    FUN_00669b20(*(undefined4 *)(param_1 + 0x6c),2,param_1,0x4000,0,0);
    return 0;
  }
  return 0xfffffffe;
}


// ==== 0x66a260 FUN_0066a260

undefined4 FUN_0066a260(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x68);
  if (*(int *)(iVar1 + 0xbc) != 1) {
    if (*(int *)(iVar1 + 0xbc) == 4) {
      *(undefined4 *)(iVar1 + 0xbc) = 6;
      do {
        Sleep(0);
      } while (*(int *)(iVar1 + 0xbc) == 6);
    }
    *(undefined4 *)(iVar1 + 0xbc) = 8;
    do {
      Sleep(0);
    } while (*(int *)(iVar1 + 0xbc) != 1);
    if (*(HANDLE *)(iVar1 + 0x6c) != (HANDLE)0xffffffff) {
      SetCommMask(*(HANDLE *)(iVar1 + 0x6c),2);
      PurgeComm(*(HANDLE *)(iVar1 + 0x6c),0xf);
      CloseHandle(*(HANDLE *)(iVar1 + 0x6c));
      *(undefined4 *)(iVar1 + 0x6c) = 0xffffffff;
    }
  }
  return 0;
}


// ==== 0x66a270 FUN_0066a270

undefined4 FUN_0066a270(int param_1,byte *param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  
  if (*(int *)(param_1 + 0x80) != 2) {
    return 0xfffffffe;
  }
  *(undefined4 *)(param_1 + 0x6c) = 0;
  bVar1 = *param_2;
  while (('/' < (char)bVar1 && ((char)bVar1 < ':'))) {
    param_2 = param_2 + 1;
    *(uint *)(param_1 + 0x6c) = (bVar1 & 0xf) + *(int *)(param_1 + 0x6c) * 10;
    bVar1 = *param_2;
  }
  iVar3 = _strchr(param_2,0x3a);
  if (iVar3 != 0) {
    pcVar4 = (char *)(iVar3 + 1);
    iVar3 = (param_1 + 0x88) - (int)pcVar4;
    do {
      cVar2 = *pcVar4;
      pcVar4[iVar3] = cVar2;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    *(undefined4 *)(param_1 + 0x80) = 3;
    FUN_00669b20(*(undefined4 *)(param_1 + 0x6c),2,param_1,0x4000,0,0);
    return 0;
  }
  return 0xfffffffd;
}


// ==== 0x66a300 FUN_0066a300

undefined4 FUN_0066a300(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x80) == 5) || (*(int *)(param_1 + 0x80) == 8)) {
    thunk_FUN_006706c0(*(undefined4 *)(param_1 + 0x68));
  }
  iVar1 = *(int *)(param_1 + 0x80);
  if (((iVar1 == 3) || (iVar1 == 5)) || (iVar1 == 8)) {
    lineClose(*(HLINE *)(param_1 + 0x78));
  }
  return 0;
}


// ==== 0x66a350 FUN_0066a350

undefined4 FUN_0066a350(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x80);
  if ((iVar1 == 3) || (iVar1 == 4)) {
    return 2;
  }
  if ((iVar1 == 2) || (iVar1 == 8)) {
    return 1;
  }
  if ((iVar1 == 7) || (iVar1 == 6)) {
    return 3;
  }
  if (iVar1 != 5) {
    return 4;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x68) + 0xbc);
  if ((iVar1 != 2) && (iVar1 != 3)) {
    if ((iVar1 == 1) || (iVar1 == 7)) {
      return 1;
    }
    if ((iVar1 != 4) && (iVar1 != 5)) {
      return 4;
    }
    return 3;
  }
  return 2;
}


// ==== 0x66a3b0 FUN_0066a3b0

int FUN_0066a3b0(int param_1,uint *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  
  iVar4 = *(int *)(param_1 + 0x68);
  if ((*(int *)(iVar4 + 0xbc) != 4) && (*(int *)(iVar4 + 0xbc) != 5)) {
    return -2;
  }
  iVar1 = *(int *)(iVar4 + 0xe4);
  iVar2 = *(int *)(iVar4 + 0xe0);
  if ((iVar1 + *(int *)(iVar4 + 0xdc)) % iVar2 == *(int *)(iVar4 + 0xe8)) {
    return 0;
  }
  if (param_3 == 0) {
    return (((iVar2 - *(int *)(iVar4 + 0xe8)) + iVar1) % iVar2) / *(int *)(iVar4 + 0xdc) + 1;
  }
  puVar6 = (uint *)(*(int *)(iVar4 + 0xf0) + iVar1);
  *puVar6 = param_3;
  if (*(int *)(iVar4 + 0xdc) + 0x800U < param_3 + 4) {
    return -6;
  }
  puVar7 = puVar6 + 4;
  for (uVar5 = param_3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar7 = *param_2;
    param_2 = param_2 + 1;
    puVar7 = puVar7 + 1;
  }
  for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
    *(char *)puVar7 = (char)*param_2;
    param_2 = (uint *)((int)param_2 + 1);
    puVar7 = (uint *)((int)puVar7 + 1);
  }
  puVar6[2] = *(uint *)(iVar4 + 0xf4);
  *(int *)(iVar4 + 0xf4) = *(int *)(iVar4 + 0xf4) + 1;
  puVar6[3] = *(int *)(iVar4 + 0xd8) - 1;
  DVar3 = GetTickCount();
  puVar6[1] = DVar3;
  *(int *)(iVar4 + 0xe4) =
       (*(int *)(iVar4 + 0xdc) + *(int *)(iVar4 + 0xe4)) % *(int *)(iVar4 + 0xe0);
  EnterCriticalSection((LPCRITICAL_SECTION)(iVar4 + 0x1910));
  FUN_0066fb20();
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 0x1910));
  iVar4 = (((*(int *)(iVar4 + 0xe4) - *(int *)(iVar4 + 0xe8)) + *(int *)(iVar4 + 0xe0)) %
          *(int *)(iVar4 + 0xe0)) / *(int *)(iVar4 + 0xdc);
  if (iVar4 < 1) {
    iVar4 = 1;
  }
  return iVar4;
}


// ==== 0x66a3c0 FUN_0066a3c0

undefined4 FUN_0066a3c0(int param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  iVar1 = *(int *)(param_1 + 0x68);
  if (*(int *)(iVar1 + 0xd0) == *(int *)(iVar1 + 0xcc)) {
    return 0xfffffff9;
  }
  iVar2 = *(int *)(iVar1 + 0x1928);
  while (iVar2 != 0) {
    Sleep(0);
    iVar2 = *(int *)(iVar1 + 0x1928);
  }
  uVar5 = *(uint *)(*(int *)(iVar1 + 0xd4) + *(int *)(iVar1 + 0xd0));
  puVar3 = (undefined4 *)(*(int *)(iVar1 + 0xd4) + *(int *)(iVar1 + 0xd0));
  if ((int)param_3 <= (int)uVar5) {
    uVar5 = param_3;
  }
  puVar6 = puVar3 + 4;
  for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *param_2 = *puVar6;
    puVar6 = puVar6 + 1;
    param_2 = param_2 + 1;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined1 *)param_2 = *(undefined1 *)puVar6;
    puVar6 = (undefined4 *)((int)puVar6 + 1);
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = puVar3[1];
  }
  return *puVar3;
}


// ==== 0x66a3d0 FUN_0066a3d0

int FUN_0066a3d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x68);
  iVar2 = FUN_00670940(iVar1,param_2,param_3,param_4);
  if (-1 < iVar2) {
    *(int *)(iVar1 + 0xd0) =
         (*(int *)(iVar1 + 0xc4) + *(int *)(iVar1 + 0xd0)) % *(int *)(iVar1 + 200);
  }
  return iVar2;
}


// ==== 0x66a3e0 FUN_0066a3e0

undefined4 * FUN_0066a3e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HANDLE pvVar1;
  undefined4 *lpParameter;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  DWORD DVar5;
  SIZE_T dwBytes;
  
  dwBytes = 0x18c;
  DVar5 = 0;
  pvVar1 = GetProcessHeap();
  lpParameter = HeapAlloc(pvVar1,DVar5,dwBytes);
  puVar3 = (undefined4 *)0x0;
  if (lpParameter != (undefined4 *)0x0) {
    puVar3 = lpParameter;
    for (iVar4 = 99; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    *lpParameter = FUN_0066a3e0;
    lpParameter[1] = FUN_00669f10;
    lpParameter[2] = FUN_00669f80;
    lpParameter[3] = NullUpdate_ret;
    lpParameter[4] = FUN_0066a1a0;
    lpParameter[5] = FUN_0066a260;
    lpParameter[6] = FUN_0066a270;
    lpParameter[7] = FUN_0066a300;
    lpParameter[8] = NullUpdate_ret;
    lpParameter[9] = FUN_0066a350;
    lpParameter[10] = GetTickCount;
    lpParameter[0xb] = FUN_0066a3b0;
    lpParameter[0xc] = FUN_0066a3c0;
    lpParameter[0xd] = FUN_0066a3d0;
    lpParameter[0x12] = 0x49504154;
    *(undefined1 *)(lpParameter + 0x13) = 0;
    lpParameter[0x20] = 0;
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00669e60,lpParameter,0,lpParameter + 0x62
                         );
    CloseHandle(pvVar1);
    iVar4 = lpParameter[0x20];
    while (iVar4 == 0) {
      Sleep(0);
      iVar4 = lpParameter[0x20];
    }
    if (lpParameter[0x20] == 1) {
      DVar5 = 0;
      pvVar1 = GetProcessHeap();
      HeapFree(pvVar1,DVar5,lpParameter);
      return (undefined4 *)0x0;
    }
    uVar2 = FUN_00670a10(param_1,param_2,param_3);
    lpParameter[0x1a] = uVar2;
    lpParameter[0x1e] = 0xffffffff;
    lpParameter[0x1f] = 0xffffffff;
    lpParameter[0x20] = 2;
    puVar3 = lpParameter;
  }
  return puVar3;
}


// ==== 0x66a520 FUN_0066a520

void FUN_0066a520(void)

{
  DWORD DVar1;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0xb0) = 0;
  *(undefined4 *)(unaff_ESI + 0xb4) = 0;
  *(undefined4 *)(unaff_ESI + 0xa4) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x94) = 0;
  *(undefined4 *)(unaff_ESI + 0x98) = 0;
  *(undefined4 *)(unaff_ESI + 0x88) = 0;
  DVar1 = GetTickCount();
  *(DWORD *)(unaff_ESI + 0xc0) = DVar1 - 5000;
  return;
}


// ==== 0x66a560 FUN_0066a560

undefined4 FUN_0066a560(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x80) == 4) {
    *(undefined4 *)(in_EAX + 0x84) = 0;
    *(undefined4 *)(in_EAX + 0x80) = 5;
  }
  return 0;
}


// ==== 0x66a580 FUN_0066a580

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_0066a580(void)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  int unaff_ESI;
  DWORD *pDVar4;
  uint unaff_retaddr;
  int local_1c;
  undefined4 local_18;
  undefined1 local_14 [16];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  local_1c = 0;
  if ((*(int *)(unaff_ESI + 0x80) == 2) &&
     (iVar1 = FUN_00662f90(*(undefined4 *)(unaff_ESI + 0x6c),0x73746174,0,0), 0 < iVar1)) {
    *(undefined4 *)(unaff_ESI + 0x80) = 4;
  }
  if (*(int *)(unaff_ESI + 0x80) == 3) {
    local_18 = 0x10;
    iVar1 = FUN_00662dd0(*(undefined4 *)(unaff_ESI + 0x6c),local_14,&local_18);
    if (iVar1 != 0) {
      FUN_00662ce0(*(undefined4 *)(unaff_ESI + 0x6c));
      *(int *)(unaff_ESI + 0x6c) = iVar1;
      FUN_00663160(iVar1,2,100);
      *(undefined4 *)(unaff_ESI + 0x80) = 4;
    }
  }
  iVar1 = *(int *)(unaff_ESI + 0x80);
  while( true ) {
    if ((iVar1 != 4) ||
       ((*(int *)(unaff_ESI + 0x8c) + *(int *)(unaff_ESI + 0x94)) % *(int *)(unaff_ESI + 0x90) ==
        *(int *)(unaff_ESI + 0x98))) goto LAB_0066a757;
    pDVar4 = (DWORD *)(*(int *)(unaff_ESI + 0x9c) + *(int *)(unaff_ESI + 0x94));
    iVar1 = *(int *)(unaff_ESI + 0x88);
    iVar2 = 2;
    if (1 < iVar1) {
      iVar2 = (short)pDVar4[1] + 2;
    }
    iVar1 = FUN_00662f00(*(undefined4 *)(unaff_ESI + 0x6c),iVar1 + 4 + (int)pDVar4,iVar2 - iVar1,0,0
                         ,0);
    if (iVar1 == 0) goto LAB_0066a757;
    if (iVar1 < 0) break;
    DVar3 = GetTickCount();
    *(DWORD *)(unaff_ESI + 0xc4) = DVar3;
    if (*(int *)(unaff_ESI + 0x88) == 0) {
      *pDVar4 = DVar3;
    }
    local_1c = local_1c + iVar1;
    iVar1 = *(int *)(unaff_ESI + 0x88) + iVar1;
    *(int *)(unaff_ESI + 0x88) = iVar1;
    if (((1 < iVar1) && ((short)pDVar4[1] + 2 <= iVar1)) &&
       (*(undefined4 *)(unaff_ESI + 0x88) = 0, (short)pDVar4[1] != 0)) {
      *(int *)(unaff_ESI + 0x1fc) = *(int *)(unaff_ESI + 0x1fc) + 1;
      *(int *)(unaff_ESI + 0x94) =
           (*(int *)(unaff_ESI + 0x94) + *(int *)(unaff_ESI + 0x8c)) % *(int *)(unaff_ESI + 0x90);
      if (*(code **)(unaff_ESI + 0x3c) != (code *)0x0) {
        (**(code **)(unaff_ESI + 0x3c))();
      }
      *(int *)(unaff_ESI + 0x1fc) = *(int *)(unaff_ESI + 0x1fc) + -1;
      *(uint *)(unaff_ESI + 0x200) = *(uint *)(unaff_ESI + 0x200) | 1;
    }
    iVar1 = *(int *)(unaff_ESI + 0x80);
  }
  *(undefined4 *)(unaff_ESI + 0x80) = 5;
LAB_0066a757:
  if (*(int *)(unaff_ESI + 0x80) == 4) {
    if (((*(int *)(unaff_ESI + 0xa4) < 0) &&
        (*(int *)(unaff_ESI + 0xb0) == *(int *)(unaff_ESI + 0xb4))) &&
       (DVar3 = GetTickCount(), *(int *)(unaff_ESI + 0xc0) + 0x32U < DVar3)) {
      pDVar4 = (DWORD *)(*(int *)(unaff_ESI + 0xb8) + *(int *)(unaff_ESI + 0xb0));
      DVar3 = GetTickCount();
      *pDVar4 = DVar3;
      *(undefined2 *)(pDVar4 + 1) = 0;
      *(int *)(unaff_ESI + 0xb0) =
           (*(int *)(unaff_ESI + 0xa8) + *(int *)(unaff_ESI + 0xb0)) % *(int *)(unaff_ESI + 0xac);
    }
    iVar1 = *(int *)(unaff_ESI + 0x80);
    while (iVar1 == 4) {
      if (*(int *)(unaff_ESI + 0xa4) < 0) {
        if (*(int *)(unaff_ESI + 0xb0) == *(int *)(unaff_ESI + 0xb4)) break;
        *(undefined4 *)(unaff_ESI + 0xa4) = 0;
        if (*(code **)(unaff_ESI + 0x38) != (code *)0x0) {
          (**(code **)(unaff_ESI + 0x38))();
        }
      }
      iVar2 = *(int *)(unaff_ESI + 0xb8) + *(int *)(unaff_ESI + 0xb4);
      iVar1 = FUN_00662e80(*(undefined4 *)(unaff_ESI + 0x6c),*(int *)(unaff_ESI + 0xa4) + 4 + iVar2,
                           ((int)*(short *)(iVar2 + 4) - *(int *)(unaff_ESI + 0xa4)) + 2,0,0,0);
      if (iVar1 < 1) break;
      DVar3 = GetTickCount();
      *(DWORD *)(unaff_ESI + 0xc0) = DVar3;
      iVar1 = *(int *)(unaff_ESI + 0xa4) + iVar1;
      *(int *)(unaff_ESI + 0xa4) = iVar1;
      if (iVar1 == *(short *)(iVar2 + 4) + 2) {
        *(undefined4 *)(unaff_ESI + 0xa4) = 0xffffffff;
        *(int *)(unaff_ESI + 0xb4) =
             (*(int *)(unaff_ESI + 0xa8) + *(int *)(unaff_ESI + 0xb4)) % *(int *)(unaff_ESI + 0xac);
      }
      iVar1 = *(int *)(unaff_ESI + 0x80);
    }
  }
  if ((*(int *)(unaff_ESI + 0x1fc) == 0) && (*(int *)(unaff_ESI + 0x200) != 0)) {
    *(int *)(unaff_ESI + 0x1fc) = *(int *)(unaff_ESI + 0x1fc) + 1;
    if (*(code **)(unaff_ESI + 0x204) != (code *)0x0) {
      (**(code **)(unaff_ESI + 0x204))();
    }
    *(int *)(unaff_ESI + 0x1fc) = *(int *)(unaff_ESI + 0x1fc) + -1;
    *(undefined4 *)(unaff_ESI + 0x200) = 0;
  }
  return local_1c;
}


// ==== 0x66a910 FUN_0066a910

undefined4 FUN_0066a910(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = FUN_00668d10(param_3 + 0x1d8);
  if (iVar1 != 0) {
    DVar2 = GetTickCount();
    FUN_0066a580(DVar2);
    FUN_00668df0(param_3 + 0x1d8);
  }
  return 0;
}


// ==== 0x66a950 FUN_0066a950

void FUN_0066a950(int param_1)

{
  if (*(int *)(param_1 + 0x80) == 4) {
    FUN_0066a560();
  }
  if (*(int *)(param_1 + 0x6c) != 0) {
    FUN_00662ce0(*(int *)(param_1 + 0x6c));
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  FUN_00668cf0(param_1 + 0x1d8);
  FUN_00447030(*(undefined4 *)(param_1 + 0x9c));
  FUN_00447030(*(undefined4 *)(param_1 + 0xb8));
  FUN_00447030(param_1);
  return;
}


// ==== 0x66a9b0 FUN_0066a9b0

void FUN_0066a9b0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x204) = param_2;
  *(uint *)(param_1 + 0x200) = *(uint *)(param_1 + 0x200) | 2;
  return;
}


// ==== 0x66a9d0 FUN_0066a9d0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0066a9d0(int param_1,char *param_2,char *param_3,undefined4 param_4,undefined1 param_5)

{
  int iVar1;
  char *pcVar2;
  char cVar3;
  uint unaff_retaddr;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  uint uStack_4;
  
  uStack_4 = DAT_006eb720 ^ unaff_retaddr;
  iVar1 = FUN_00668c60(param_2,"internet",0xffffffff);
  if (iVar1 == 0) {
    return 0;
  }
  *param_3 = '*';
  param_3[1] = '\0';
  param_3[2] = '\0';
  if (*(int *)(param_1 + 200) != 0) {
    return 0xfffffff8;
  }
  *(char **)(param_1 + 0x1cc) = param_3;
  *(undefined4 *)(param_1 + 0x1d0) = param_4;
  *(undefined1 *)(param_1 + 0x1d4) = param_5;
  iVar1 = FUN_00668c60(param_2,"localhost",0xffffffff);
  if (iVar1 == 0) {
    uStack_14 = 0;
    uStack_10 = 0;
    uStack_c = 0;
    uStack_24 = 2;
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_22 = 0x4f00;
    uStack_20 = 0x101a8c0;
    uStack_8 = 0;
    FUN_00663190(&uStack_14,0x10,&uStack_24,0x10);
    if (CONCAT31(CONCAT21(CONCAT11((undefined1)uStack_10,uStack_10._1_1_),uStack_10._2_1_),
                 uStack_10._3_1_) == 0) {
      uStack_10 = 0x100007f;
    }
    FUN_00662490(&uStack_14,param_3,param_4);
    return 1;
  }
  FUN_00662410(&uStack_24,param_2);
  if (CONCAT31(CONCAT21(CONCAT11((undefined1)uStack_20,uStack_20._1_1_),uStack_20._2_1_),
               uStack_20._3_1_) != 0) {
    cVar3 = *param_2;
    pcVar2 = param_3;
    if (cVar3 != '\0') {
      do {
        *pcVar2 = cVar3;
        cVar3 = pcVar2[(int)(param_2 + (1 - (int)param_3))];
        pcVar2 = pcVar2 + 1;
      } while (cVar3 != '\0');
    }
    *pcVar2 = '\0';
    pcVar2[1] = '\0';
    return 1;
  }
  *param_3 = '*';
  return 0;
}


// ==== 0x66abc0 FUN_0066abc0

undefined4 FUN_0066abc0(int param_1)

{
  if (*(int *)(param_1 + 0x80) == 3) {
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  if (*(int *)(param_1 + 0x6c) != 0) {
    FUN_00662ce0(*(int *)(param_1 + 0x6c));
  }
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 1;
  return 0;
}


// ==== 0x66ac00 FUN_0066ac00

char FUN_0066ac00(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x80);
  if ((iVar1 == 2) || (iVar1 == 3)) {
    return '\x02';
  }
  if ((iVar1 != 1) && (iVar1 != 5)) {
    return (iVar1 != 4) + '\x03';
  }
  return '\x01';
}


// ==== 0x66ac40 FUN_0066ac40

int FUN_0066ac40(int param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  int iVar4;
  uint uVar5;
  DWORD *pDVar6;
  undefined4 *puVar7;
  
  if (*(int *)(param_1 + 0x80) != 4) {
    return -2;
  }
  iVar4 = *(int *)(param_1 + 0xa8);
  iVar1 = *(int *)(param_1 + 0xb0);
  iVar2 = *(int *)(param_1 + 0xac);
  if ((iVar1 + iVar4) % iVar2 == *(int *)(param_1 + 0xb4)) {
    return 0;
  }
  if (iVar4 + -8 < (int)param_3) {
    return -6;
  }
  if (param_3 == 0) {
    return (((iVar2 - *(int *)(param_1 + 0xb4)) + iVar1) % iVar2) / iVar4 + 1;
  }
  pDVar6 = (DWORD *)(*(int *)(param_1 + 0xb8) + iVar1);
  *(short *)(pDVar6 + 1) = (short)param_3;
  puVar7 = (undefined4 *)((int)pDVar6 + 6);
  for (uVar5 = param_3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar7 = *param_2;
    param_2 = param_2 + 1;
    puVar7 = puVar7 + 1;
  }
  for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
    *(undefined1 *)puVar7 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  DVar3 = GetTickCount();
  *pDVar6 = DVar3;
  *(int *)(param_1 + 0xb0) =
       (*(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0xb0)) % *(int *)(param_1 + 0xac);
  FUN_0066a910(*(undefined4 *)(param_1 + 0x6c),0,param_1);
  iVar4 = (((*(int *)(param_1 + 0xac) - *(int *)(param_1 + 0xb4)) + *(int *)(param_1 + 0xb0)) %
          *(int *)(param_1 + 0xac)) / *(int *)(param_1 + 0xa8);
  if (iVar4 < 1) {
    iVar4 = 1;
  }
  return iVar4;
}


// ==== 0x66ad40 FUN_0066ad40

int FUN_0066ad40(int param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if (*(int *)(param_1 + 0x98) == *(int *)(param_1 + 0x94)) {
    FUN_0066a910(0,0,param_1);
  }
  if (*(int *)(param_1 + 0x98) == *(int *)(param_1 + 0x94)) {
    return -7;
  }
  puVar1 = (undefined4 *)(*(int *)(param_1 + 0x9c) + *(int *)(param_1 + 0x98));
  uVar3 = (int)*(short *)(puVar1 + 1);
  if ((int)param_3 <= (int)*(short *)(puVar1 + 1)) {
    uVar3 = param_3;
  }
  puVar4 = (undefined4 *)((int)puVar1 + 6);
  for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *param_2 = *puVar4;
    puVar4 = puVar4 + 1;
    param_2 = param_2 + 1;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)param_2 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *puVar1;
  }
  return (int)*(short *)(puVar1 + 1);
}


// ==== 0x66adc0 FUN_0066adc0

int FUN_0066adc0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0066ad40(param_1,param_2,param_3,param_4);
  if (-1 < iVar1) {
    *(int *)(param_1 + 0x98) =
         (*(int *)(param_1 + 0x8c) + *(int *)(param_1 + 0x98)) % *(int *)(param_1 + 0x90);
  }
  return iVar1;
}


// ==== 0x66ae10 FUN_0066ae10

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0066ae10(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint unaff_retaddr;
  undefined2 uStack_14;
  undefined2 uStack_12;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  uint uStack_4;
  
  uStack_4 = DAT_006eb720 ^ unaff_retaddr;
  if ((*(int *)(param_1 + 0x80) != 1) || (*(int *)(param_1 + 0x6c) != 0)) {
    return 0xfffffffe;
  }
  uStack_14 = 2;
  uStack_12 = 0;
  uStack_10 = 0;
  uStack_c = 0;
  uStack_8 = 0;
  uVar1 = FUN_00662820(&uStack_14,param_2);
  if ((uVar1 & 2) == 0) {
    return 0xfffffffd;
  }
  FUN_0066a520();
  iVar2 = FUN_00662c30(2,1,0);
  *(int *)(param_1 + 0x6c) = iVar2;
  if (iVar2 == 0) {
    return 0xfffffffc;
  }
  iVar2 = FUN_00662d70(iVar2,&uStack_14,0x10);
  if (iVar2 < 0) {
    FUN_00662ce0(*(undefined4 *)(param_1 + 0x6c));
    *(undefined4 *)(param_1 + 0x6c) = 0;
    return 0xfffffffb;
  }
  FUN_00662db0(*(undefined4 *)(param_1 + 0x6c),5);
  FUN_00663160(*(undefined4 *)(param_1 + 0x6c),2,100,param_1,FUN_0066a910);
  *(undefined4 *)(param_1 + 0x80) = 3;
  return 0;
}


// ==== 0x66af50 FUN_0066af50

undefined4 FUN_0066af50(int param_1,undefined4 param_2)

{
  undefined2 *puVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x80) != 1) || (*(int *)(param_1 + 0x6c) != 0)) {
    return 0xfffffffe;
  }
  puVar1 = (undefined2 *)(param_1 + 0x70);
  *puVar1 = 2;
  *(undefined2 *)(param_1 + 0x72) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  iVar2 = FUN_00662820(puVar1,param_2);
  if (iVar2 != 3) {
    return 0xfffffffd;
  }
  FUN_0066a520();
  iVar2 = FUN_00662c30(2,1,0);
  *(int *)(param_1 + 0x6c) = iVar2;
  if (iVar2 == 0) {
    return 0xfffffffc;
  }
  FUN_00662d90(iVar2,puVar1,0x10);
  FUN_00663160(*(undefined4 *)(param_1 + 0x6c),2,100,param_1,FUN_0066a910);
  *(undefined4 *)(param_1 + 0x80) = 2;
  return 0;
}


// ==== 0x66b000 FUN_0066b000

undefined4 * FUN_0066b000(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar1 = (undefined4 *)FUN_00549460(0x208);
  puVar3 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    puVar3 = puVar1;
    for (iVar4 = 0x82; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    *puVar1 = FUN_0066b000;
    puVar1[1] = FUN_0066a950;
    puVar1[2] = FUN_0066a9d0;
    puVar1[3] = NullUpdate_ret;
    puVar1[4] = FUN_0066ae10;
    puVar1[5] = FUN_0066abc0;
    puVar1[6] = FUN_0066af50;
    puVar1[7] = FUN_0066abc0;
    puVar1[8] = FUN_0066a9b0;
    puVar1[9] = FUN_0066ac00;
    puVar1[10] = GetTickCount;
    puVar1[0xb] = FUN_0066ac40;
    puVar1[0xc] = FUN_0066ad40;
    puVar1[0xd] = FUN_0066adc0;
    puVar1[0x12] = 0x504354;
    FUN_00668cc0(puVar1 + 0x76);
    uVar5 = param_1 + 0xbU & 0x7ffc;
    puVar1[0x23] = uVar5;
    puVar1[0x24] = uVar5 * param_2;
    uVar2 = FUN_00549460(uVar5 * param_2);
    puVar1[0x2a] = uVar5;
    puVar1[0x27] = uVar2;
    puVar1[0x2b] = uVar5 * param_3;
    uVar2 = FUN_00549460(uVar5 * param_3);
    puVar1[0x2e] = uVar2;
    puVar1[0x1b] = 0;
    puVar1[0x20] = 1;
    puVar1[0x21] = 0;
    puVar3 = puVar1;
  }
  return puVar3;
}


// ==== 0x66b110 FUN_0066b110

void FUN_0066b110(void)

{
  DWORD DVar1;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0xa8) = 0;
  *(undefined4 *)(unaff_ESI + 0xac) = 0;
  *(undefined4 *)(unaff_ESI + 0x94) = 0;
  *(undefined4 *)(unaff_ESI + 0x98) = 0;
  DVar1 = GetTickCount();
  *(DWORD *)(unaff_ESI + 0xb4) = DVar1 - 5000;
  *(undefined4 *)(unaff_ESI + 200) = 0xffffffff;
  return;
}


// ==== 0x66b150 FUN_0066b150

int FUN_0066b150(void)

{
  int in_EAX;
  int iVar1;
  DWORD DVar2;
  int iVar3;
  int unaff_EDI;
  
  iVar3 = *(int *)(in_EAX + 4) + 1;
  iVar1 = FUN_00662e80(*(undefined4 *)(unaff_EDI + 0x6c),in_EAX + 8,iVar3,0,unaff_EDI + 0x70,0x10);
  if (iVar1 != iVar3) {
    return -1;
  }
  DVar2 = GetTickCount();
  *(DWORD *)(unaff_EDI + 0xb4) = DVar2;
  *(int *)(unaff_EDI + 0x60) = *(int *)(unaff_EDI + 0x60) + 1;
  *(int *)(unaff_EDI + 0x58) = *(int *)(unaff_EDI + 0x58) + iVar3;
  return iVar3;
}


// ==== 0x66b1a0 FUN_0066b1a0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0066b1a0(void)

{
  FUN_0066b150();
  return;
}


// ==== 0x66b1e0 FUN_0066b1e0

void FUN_0066b1e0(void)

{
  int in_EAX;
  DWORD DVar1;
  
  if ((CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(in_EAX + 0x74),*(undefined1 *)(in_EAX + 0x75)),
                         *(undefined1 *)(in_EAX + 0x76)),*(undefined1 *)(in_EAX + 0x77)) != 0) &&
     (CONCAT11(*(undefined1 *)(in_EAX + 0x72),*(undefined1 *)(in_EAX + 0x73)) != 0)) {
    DVar1 = GetTickCount();
    if (999 < DVar1 - *(int *)(in_EAX + 0xb4)) {
      if (*(int *)(in_EAX + 0x80) == 1) {
        FUN_0066b1a0(0x10);
        return;
      }
      if (*(int *)(in_EAX + 0x80) == 2) {
        FUN_0066b1a0(0x11);
      }
    }
  }
  return;
}


// ==== 0x66b250 FUN_0066b250

int __thiscall FUN_0066b250(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(byte *)(*(int *)(param_1 + 0xb0) + 8 + *(int *)(param_1 + 0xac)) - 0x80;
  if (*(byte *)(param_2 + 8) - 0xc0 == iVar1) {
    iVar2 = *(int *)(param_1 + 0xa0) + *(int *)(param_1 + 0xac);
    iVar1 = iVar2 / *(int *)(param_1 + 0xa4);
    *(int *)(param_1 + 0xac) = iVar2 % *(int *)(param_1 + 0xa4);
  }
  return iVar1;
}


// ==== 0x66b290 FUN_0066b290

void FUN_0066b290(int param_1)

{
  int in_EAX;
  DWORD DVar1;
  undefined4 *unaff_ESI;
  
  DVar1 = GetTickCount();
  *(DWORD *)(in_EAX + 0xb8) = DVar1 - 1000;
  switch(*(undefined1 *)(param_1 + 8)) {
  case 0x10:
    if (*(int *)(in_EAX + 0x80) == 2) {
      *(undefined4 *)(in_EAX + 0x70) = *unaff_ESI;
      *(undefined4 *)(in_EAX + 0x74) = unaff_ESI[1];
      *(undefined4 *)(in_EAX + 0x78) = unaff_ESI[2];
      *(undefined4 *)(in_EAX + 0x7c) = unaff_ESI[3];
      *(undefined4 *)(in_EAX + 0x80) = 3;
    }
    FUN_0066b1a0(0x12);
    return;
  case 0x11:
    if (*(int *)(in_EAX + 0x80) == 1) {
      *(undefined4 *)(in_EAX + 0x70) = *unaff_ESI;
      *(undefined4 *)(in_EAX + 0x74) = unaff_ESI[1];
      *(undefined4 *)(in_EAX + 0x78) = unaff_ESI[2];
      *(undefined4 *)(in_EAX + 0x7c) = unaff_ESI[3];
      return;
    }
    break;
  case 0x12:
    if (*(int *)(in_EAX + 0x80) == 1) {
      *(undefined4 *)(in_EAX + 0x80) = 3;
      return;
    }
    break;
  case 0x14:
    if (*(int *)(in_EAX + 0x80) == 3) {
      *(undefined4 *)(in_EAX + 0x80) = 4;
    }
  }
  return;
}


// ==== 0x66b360 FUN_0066b360

uint FUN_0066b360(undefined4 *param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int unaff_EBX;
  int iVar5;
  undefined4 *puVar6;
  
  bVar1 = *(byte *)(param_1 + 2);
  if ((bVar1 < 0x40) || (0x7f < bVar1)) {
    iVar5 = *(int *)(unaff_EBX + 0x94);
    uVar4 = *(uint *)(unaff_EBX + 0x88);
    if ((int)(uVar4 + iVar5) % *(int *)(unaff_EBX + 0x90) != *(int *)(unaff_EBX + 0x98)) {
      uVar3 = bVar1 - 0x80;
      if (uVar3 != (*(uint *)(unaff_EBX + 200) + 1 & 0x3f)) {
        return (uint)(uVar3 == *(uint *)(unaff_EBX + 200));
      }
      *(uint *)(unaff_EBX + 200) = uVar3;
      goto LAB_0066b3f9;
    }
  }
  else {
    iVar2 = *(int *)(unaff_EBX + 0x90);
    iVar5 = *(int *)(unaff_EBX + 0x94);
    uVar4 = *(uint *)(unaff_EBX + 0x88);
    if (*(int *)(unaff_EBX + 0x8c) <
        (iVar2 - ((iVar2 - *(int *)(unaff_EBX + 0x98)) + iVar5) % iVar2) / (int)uVar4) {
      *(uint *)(unaff_EBX + 0xc0) = bVar1 - 0x40;
LAB_0066b3f9:
      puVar6 = (undefined4 *)(*(int *)(unaff_EBX + 0x9c) + iVar5);
      for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar6 = *param_1;
        param_1 = param_1 + 1;
        puVar6 = puVar6 + 1;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar6 = *(undefined1 *)param_1;
        param_1 = (undefined4 *)((int)param_1 + 1);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
      *(int *)(unaff_EBX + 0x200) = *(int *)(unaff_EBX + 0x200) + 1;
      *(int *)(unaff_EBX + 0x94) =
           (*(int *)(unaff_EBX + 0x88) + *(int *)(unaff_EBX + 0x94)) % *(int *)(unaff_EBX + 0x90);
      *(uint *)(unaff_EBX + 0x204) = *(uint *)(unaff_EBX + 0x204) | 1;
      if (*(code **)(unaff_EBX + 0x3c) != (code *)0x0) {
        (**(code **)(unaff_EBX + 0x3c))();
      }
      *(int *)(unaff_EBX + 0x200) = *(int *)(unaff_EBX + 0x200) + -1;
      return 1;
    }
  }
  return 0xffffffff;
}


// ==== 0x66b490 FUN_0066b490

void FUN_0066b490(void)

{
  int in_EAX;
  DWORD DVar1;
  
  if ((*(int *)(in_EAX + 0x80) == 3) && (*(int *)(in_EAX + 0xa8) == *(int *)(in_EAX + 0xac))) {
    DVar1 = GetTickCount();
    if (*(int *)(in_EAX + 0xb4) + 5000U < DVar1) {
      FUN_0066b1a0(0x13);
    }
  }
  return;
}


// ==== 0x66b4d0 FUN_0066b4d0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_0066b4d0(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint unaff_retaddr;
  undefined4 local_18;
  undefined1 local_14 [8];
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x80)) {
    while( true ) {
      if (3 < *(int *)(param_1 + 0x80)) {
        return;
      }
      if (iVar4 < 0) {
        return;
      }
      puVar5 = (undefined4 *)(*(int *)(param_1 + 0x9c) + *(int *)(param_1 + 0x94));
      pbVar1 = (byte *)(puVar5 + 2);
      local_18 = 0x10;
      iVar3 = FUN_00662f00(*(undefined4 *)(param_1 + 0x6c),pbVar1,*(undefined4 *)(param_1 + 0x88),0,
                           local_14,&local_18);
      if (iVar3 < 1) break;
      puVar5[1] = iVar3;
      bVar2 = *pbVar1;
      *puVar5 = CONCAT31(CONCAT21(CONCAT11(local_c,local_b),local_a),local_9);
      if ((bVar2 < 0x10) || (0x3f < bVar2)) {
        if (bVar2 < 0xc0) {
          iVar4 = FUN_0066b360(puVar5);
          if (((iVar4 == 1) && (bVar2 = *pbVar1, 0x7f < bVar2)) && (bVar2 < 0xc0)) {
            FUN_0066b1a0(bVar2 + 0x40);
          }
        }
        else {
          FUN_0066b250();
        }
      }
      else {
        FUN_0066b290(puVar5);
      }
      if (*(int *)(param_1 + 0x80) < 1) {
        return;
      }
    }
    if (iVar3 < 0) {
      *(undefined4 *)(param_1 + 0x80) = 4;
    }
  }
  return;
}


// ==== 0x66b610 FUN_0066b610

void FUN_0066b610(void)

{
  int in_EAX;
  DWORD DVar1;
  int iVar2;
  DWORD *pDVar3;
  
  if ((((*(int *)(in_EAX + 0x80) == 3) && (*(int *)(in_EAX + 0xa8) != *(int *)(in_EAX + 0xac))) &&
      ((pDVar3 = (DWORD *)(*(int *)(in_EAX + 0xb0) + *(int *)(in_EAX + 0xac)), *pDVar3 == 0 ||
       (DVar1 = GetTickCount(), 0xf9 < DVar1 - *pDVar3)))) && (iVar2 = FUN_0066b150(), -1 < iVar2))
  {
    DVar1 = GetTickCount();
    *pDVar3 = DVar1;
  }
  return;
}


// ==== 0x66b660 FUN_0066b660

undefined4 FUN_0066b660(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x80) == 3) {
    FUN_0066b1a0(0x14);
    *(undefined4 *)(in_EAX + 0x84) = 0;
    *(undefined4 *)(in_EAX + 0x80) = 4;
  }
  return 0;
}


// ==== 0x66b690 FUN_0066b690

void FUN_0066b690(void)

{
  int unaff_ESI;
  
  if ((*(int *)(unaff_ESI + 0x80) == 1) || (*(int *)(unaff_ESI + 0x80) == 2)) {
    FUN_0066b1e0();
  }
  FUN_0066b4d0();
  FUN_0066b490();
  FUN_0066b610();
  if ((*(int *)(unaff_ESI + 0x200) == 0) && (*(int *)(unaff_ESI + 0x204) != 0)) {
    *(int *)(unaff_ESI + 0x200) = *(int *)(unaff_ESI + 0x200) + 1;
    if (*(code **)(unaff_ESI + 0x208) != (code *)0x0) {
      (**(code **)(unaff_ESI + 0x208))();
    }
    *(int *)(unaff_ESI + 0x200) = *(int *)(unaff_ESI + 0x200) + -1;
    *(undefined4 *)(unaff_ESI + 0x204) = 0;
  }
  return;
}


// ==== 0x66b710 FUN_0066b710

undefined4 FUN_0066b710(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_00668d10(param_3 + 0x1dc);
  if (iVar1 != 0) {
    FUN_0066b690();
    FUN_00668df0(param_3 + 0x1dc);
  }
  return 0;
}


// ==== 0x66b740 FUN_0066b740

int FUN_0066b740(void)

{
  undefined4 *in_EAX;
  int unaff_ESI;
  
  *in_EAX = 0;
  *(int *)(unaff_ESI + 0xa8) =
       (*(int *)(unaff_ESI + 0xa0) + *(int *)(unaff_ESI + 0xa8)) % *(int *)(unaff_ESI + 0xa4);
  FUN_0066b710(*(undefined4 *)(unaff_ESI + 0x6c),0);
  return (((*(int *)(unaff_ESI + 0xa8) - *(int *)(unaff_ESI + 0xac)) + *(int *)(unaff_ESI + 0xa4)) %
         *(int *)(unaff_ESI + 0xa4)) / *(int *)(unaff_ESI + 0xa0);
}


// ==== 0x66b7a0 FUN_0066b7a0

void FUN_0066b7a0(int param_1)

{
  if (*(int *)(param_1 + 0x80) == 3) {
    FUN_0066b660();
  }
  if (*(int *)(param_1 + 0x6c) != 0) {
    FUN_00662ce0(*(int *)(param_1 + 0x6c));
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  FUN_00668cf0(param_1 + 0x1dc);
  FUN_00447030(*(undefined4 *)(param_1 + 0x9c));
  FUN_00447030(*(undefined4 *)(param_1 + 0xb0));
  FUN_00447030(param_1);
  return;
}


// ==== 0x66b800 FUN_0066b800

void FUN_0066b800(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x208) = param_2;
  *(uint *)(param_1 + 0x204) = *(uint *)(param_1 + 0x204) | 2;
  return;
}


// ==== 0x66b820 FUN_0066b820

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0066b820(int param_1,char *param_2,char *param_3,undefined4 param_4,undefined1 param_5)

{
  int iVar1;
  char *pcVar2;
  char cVar3;
  uint unaff_retaddr;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  uint uStack_4;
  
  uStack_4 = DAT_006eb720 ^ unaff_retaddr;
  *param_3 = '*';
  param_3[1] = '\0';
  param_3[2] = '\0';
  if (*(int *)(param_1 + 0xcc) != 0) {
    return 0xfffffff8;
  }
  *(char **)(param_1 + 0x1d0) = param_3;
  *(undefined4 *)(param_1 + 0x1d4) = param_4;
  *(undefined1 *)(param_1 + 0x1d8) = param_5;
  iVar1 = FUN_00668c60(param_2,"localhost",0xffffffff);
  if (iVar1 == 0) {
    uStack_14 = 0;
    uStack_10 = 0;
    uStack_c = 0;
    uStack_24 = 2;
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_22 = 0x4f00;
    uStack_20 = 0x101a8c0;
    uStack_8 = 0;
    FUN_00663190(&uStack_14,0x10,&uStack_24,0x10);
    if (CONCAT31(CONCAT21(CONCAT11((undefined1)uStack_10,uStack_10._1_1_),uStack_10._2_1_),
                 uStack_10._3_1_) == 0) {
      uStack_10 = 0x100007f;
    }
    FUN_00662490(&uStack_14,param_3,param_4);
    return 1;
  }
  FUN_00662410(&uStack_24,param_2);
  if (CONCAT31(CONCAT21(CONCAT11((undefined1)uStack_20,uStack_20._1_1_),uStack_20._2_1_),
               uStack_20._3_1_) != 0) {
    cVar3 = *param_2;
    pcVar2 = param_3;
    if (cVar3 != '\0') {
      do {
        *pcVar2 = cVar3;
        cVar3 = pcVar2[(int)(param_2 + (1 - (int)param_3))];
        pcVar2 = pcVar2 + 1;
      } while (cVar3 != '\0');
    }
    *pcVar2 = '\0';
    pcVar2[1] = '\0';
    return 1;
  }
  *param_3 = '*';
  return 0;
}


// ==== 0x66b9e0 FUN_0066b9e0

undefined4 FUN_0066b9e0(int param_1)

{
  if (*(int *)(param_1 + 0x6c) != 0) {
    FUN_00662ce0(*(int *)(param_1 + 0x6c));
  }
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  return 0;
}


// ==== 0x66ba10 FUN_0066ba10

char FUN_0066ba10(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x80);
  if ((iVar1 == 1) || (iVar1 == 2)) {
    return '\x02';
  }
  if ((iVar1 != 0) && (iVar1 != 4)) {
    return (iVar1 != 3) + '\x03';
  }
  return '\x01';
}


// ==== 0x66ba50 FUN_0066ba50

int FUN_0066ba50(int param_1,undefined4 *param_2,uint param_3,byte param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  if (*(int *)(param_1 + 0x80) != 3) {
    return -2;
  }
  iVar3 = *(int *)(param_1 + 0xa0);
  iVar2 = *(int *)(param_1 + 0xa8);
  iVar1 = *(int *)(param_1 + 0xa4);
  if ((iVar2 + iVar3) % iVar1 == *(int *)(param_1 + 0xac)) {
    return 0;
  }
  if (iVar3 + -0xb < (int)param_3) {
    return -6;
  }
  if (param_3 == 0) {
    return (((iVar1 - *(int *)(param_1 + 0xac)) + iVar2) % iVar1) / iVar3 + 1;
  }
  iVar2 = *(int *)(param_1 + 0xb0) + iVar2;
  *(uint *)(iVar2 + 4) = param_3;
  puVar5 = (undefined4 *)(iVar2 + 9);
  for (uVar4 = param_3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar5 = *param_2;
    param_2 = param_2 + 1;
    puVar5 = puVar5 + 1;
  }
  for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
    *(undefined1 *)puVar5 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  if ((param_4 & 1) != 0) {
    *(char *)(iVar2 + 8) = *(char *)(param_1 + 0xbc) + '@';
    *(uint *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + 1U & 0x3f;
    FUN_0066b150();
    return 1;
  }
  *(char *)(iVar2 + 8) = *(char *)(param_1 + 0xc4) + -0x80;
  *(uint *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + 1U & 0x3f;
  iVar3 = FUN_0066b740();
  if (iVar3 < 1) {
    iVar3 = 1;
  }
  return iVar3;
}


// ==== 0x66bb50 FUN_0066bb50

uint FUN_0066bb50(int param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (*(int *)(param_1 + 0x98) == *(int *)(param_1 + 0x94)) {
    FUN_0066b710(0,0,param_1);
  }
  if (*(int *)(param_1 + 0x98) == *(int *)(param_1 + 0x94)) {
    return 0xfffffff9;
  }
  puVar3 = (undefined4 *)(*(int *)(param_1 + 0x9c) + *(int *)(param_1 + 0x98));
  uVar1 = puVar3[1] - 1;
  if ((int)uVar1 < (int)param_3) {
    param_3 = uVar1;
  }
  puVar4 = (undefined4 *)((int)puVar3 + 9);
  for (uVar2 = param_3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *param_2 = *puVar4;
    puVar4 = puVar4 + 1;
    param_2 = param_2 + 1;
  }
  for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
    *(undefined1 *)param_2 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *puVar3;
  }
  return uVar1;
}


// ==== 0x66bbd0 FUN_0066bbd0

int FUN_0066bbd0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0066bb50(param_1,param_2,param_3,param_4);
  if (-1 < iVar1) {
    *(int *)(param_1 + 0x98) =
         (*(int *)(param_1 + 0x88) + *(int *)(param_1 + 0x98)) % *(int *)(param_1 + 0x90);
  }
  return iVar1;
}


// ==== 0x66bc20 FUN_0066bc20

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0066bc20(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint unaff_retaddr;
  int iStack_1c;
  int iStack_18;
  undefined2 uStack_14;
  undefined2 uStack_12;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar1 = param_1;
  uStack_4 = DAT_006eb720 ^ unaff_retaddr;
  if ((*(int *)(param_1 + 0x80) != 0) || (*(int *)(param_1 + 0x6c) != 0)) {
    return 0xfffffffe;
  }
  uStack_14 = 2;
  uStack_12 = 0;
  uStack_10 = 0;
  uStack_c = 0;
  uStack_8 = 0;
  uVar2 = FUN_00662730(&iStack_1c,&param_1,&iStack_18,param_2);
  if ((uVar2 & 2) == 0) {
    return 0xfffffffd;
  }
  uStack_12 = CONCAT11((char)param_1,(char)((uint)param_1 >> 8));
  FUN_0066b110();
  iVar3 = FUN_00662c30(2,2,0);
  *(int *)(iVar1 + 0x6c) = iVar3;
  if (iVar3 == 0) {
    return 0xfffffffc;
  }
  iVar3 = FUN_00662d70(iVar3,&uStack_14,0x10);
  if (iVar3 < 0) {
    FUN_00662ce0(*(undefined4 *)(iVar1 + 0x6c));
    *(undefined4 *)(iVar1 + 0x6c) = 0;
    return 0xfffffffb;
  }
  FUN_00663160(*(undefined4 *)(iVar1 + 0x6c),2,100,iVar1,FUN_0066b710);
  if (iStack_1c != 0) {
    if (iStack_18 == 0) {
      iStack_18 = param_1 + 1;
    }
    *(undefined4 *)(iVar1 + 0x74) = 0;
    *(char *)(iVar1 + 0x77) = (char)iStack_1c;
    *(char *)(iVar1 + 0x76) = (char)((uint)iStack_1c >> 8);
    *(char *)(iVar1 + 0x75) = (char)((uint)iStack_1c >> 0x10);
    *(undefined2 *)(iVar1 + 0x72) = 0;
    *(undefined2 *)(iVar1 + 0x70) = 2;
    *(undefined4 *)(iVar1 + 0x78) = 0;
    *(undefined4 *)(iVar1 + 0x7c) = 0;
    *(char *)(iVar1 + 0x74) = (char)((uint)iStack_1c >> 0x18);
    *(char *)(iVar1 + 0x72) = (char)((uint)iStack_18 >> 8);
    *(char *)(iVar1 + 0x73) = (char)iStack_18;
  }
  *(undefined4 *)(iVar1 + 0x80) = 2;
  return 0;
}


// ==== 0x66bdb0 FUN_0066bdb0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0066bdb0(int param_1,undefined4 param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint unaff_retaddr;
  int iStack_1c;
  undefined1 auStack_18 [4];
  undefined2 uStack_14;
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar1 = param_1;
  uStack_4 = DAT_006eb720 ^ unaff_retaddr;
  if ((*(int *)(param_1 + 0x80) != 0) || (*(int *)(param_1 + 0x6c) != 0)) {
    return 0xfffffffe;
  }
  bVar2 = FUN_00662730(auStack_18,&param_1,&iStack_1c,param_2);
  if ((bVar2 & 3) != 3) {
    return 0xfffffffd;
  }
  if (iStack_1c == 0) {
    iStack_1c = param_1;
    param_1 = param_1 + 1;
  }
  FUN_0066b110();
  iVar3 = FUN_00662c30(2,2,0);
  *(int *)(iVar1 + 0x6c) = iVar3;
  if (iVar3 == 0) {
    return 0xfffffffc;
  }
  uStack_14 = 2;
  uStack_10 = 0;
  uStack_c = 0;
  uStack_8 = 0;
  _uStack_12 = CONCAT11((char)param_1,(char)((uint)param_1 >> 8));
  iVar3 = FUN_00662d70(iVar3,&uStack_14,0x10);
  if (iVar3 < 0) {
    return 0xfffffffb;
  }
  *(undefined4 *)(iVar1 + 0x74) = 0;
  *(char *)(iVar1 + 0x77) = auStack_18[0];
  *(char *)(iVar1 + 0x76) = auStack_18[1];
  *(char *)(iVar1 + 0x75) = auStack_18[2];
  *(char *)(iVar1 + 0x74) = auStack_18[3];
  *(undefined2 *)(iVar1 + 0x72) = 0;
  *(char *)(iVar1 + 0x73) = (char)iStack_1c;
  *(undefined2 *)(iVar1 + 0x70) = 2;
  *(undefined4 *)(iVar1 + 0x78) = 0;
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(char *)(iVar1 + 0x72) = (char)((uint)iStack_1c >> 8);
  FUN_00663160(*(undefined4 *)(iVar1 + 0x6c),2,100,iVar1,FUN_0066b710);
  *(undefined4 *)(iVar1 + 0x80) = 1;
  return 0;
}


// ==== 0x66bf40 FUN_0066bf40

undefined4 * FUN_0066bf40(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar1 = (undefined4 *)FUN_00549460(0x20c);
  puVar3 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    puVar3 = puVar1;
    for (iVar4 = 0x83; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    *puVar1 = FUN_0066bf40;
    puVar1[1] = FUN_0066b7a0;
    puVar1[2] = FUN_0066b820;
    puVar1[3] = NullUpdate_ret;
    puVar1[4] = FUN_0066bc20;
    puVar1[5] = FUN_0066b9e0;
    puVar1[6] = FUN_0066bdb0;
    puVar1[7] = FUN_0066b9e0;
    puVar1[8] = FUN_0066b800;
    puVar1[9] = FUN_0066ba10;
    puVar1[10] = GetTickCount;
    puVar1[0xb] = FUN_0066ba50;
    puVar1[0xc] = FUN_0066bb50;
    puVar1[0xd] = FUN_0066bbd0;
    puVar1[0x12] = 0x505253;
    FUN_00668cc0(puVar1 + 0x77);
    uVar5 = param_1 + 0xeU & 0x7ffc;
    puVar1[0x22] = uVar5;
    puVar1[0x24] = uVar5 * param_2;
    uVar2 = FUN_00549460(uVar5 * param_2);
    puVar1[0x28] = uVar5;
    puVar1[0x27] = uVar2;
    puVar1[0x29] = uVar5 * param_3;
    uVar2 = FUN_00549460(uVar5 * param_3);
    puVar1[0x2c] = uVar2;
    puVar1[0x23] = (int)(param_2 + (param_2 >> 0x1f & 7U)) >> 3;
    puVar1[0x1b] = 0;
    puVar1[0x20] = 0;
    puVar1[0x21] = 0;
    puVar3 = puVar1;
  }
  return puVar3;
}


// ==== 0x66c060 FUN_0066c060

void FUN_0066c060(void)

{
  DWORD DVar1;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0xb0) = 0;
  *(undefined4 *)(unaff_ESI + 0xb4) = 0;
  *(undefined4 *)(unaff_ESI + 0xb8) = 0;
  *(undefined4 *)(unaff_ESI + 0xc0) = 0x65;
  *(undefined4 *)(unaff_ESI + 0x90) = 0;
  *(undefined4 *)(unaff_ESI + 0x94) = 0;
  *(undefined4 *)(unaff_ESI + 0x9c) = 0x65;
  *(undefined4 *)(unaff_ESI + 0xa4) = 0;
  DVar1 = GetTickCount();
  *(DWORD *)(unaff_ESI + 0xc4) = DVar1 - 5000;
  DVar1 = GetTickCount();
  *(DWORD *)(unaff_ESI + 200) = DVar1 - 5000;
  return;
}


// ==== 0x66c0c0 FUN_0066c0c0

int FUN_0066c0c0(void)

{
  int *in_EAX;
  int iVar1;
  DWORD DVar2;
  int iVar3;
  int unaff_EDI;
  
  iVar3 = *in_EAX + 8;
  iVar1 = FUN_00662e80(*(undefined4 *)(unaff_EDI + 0x6c),in_EAX + 2,iVar3,0,unaff_EDI + 0x70,0x10);
  if (iVar1 == iVar3) {
    DVar2 = GetTickCount();
    *(DWORD *)(unaff_EDI + 0xc4) = DVar2;
    *(int *)(unaff_EDI + 0x58) = *(int *)(unaff_EDI + 0x58) + iVar3;
    *(int *)(unaff_EDI + 0x60) = *(int *)(unaff_EDI + 0x60) + 1;
    if (in_EAX[2] != 6) {
      *(undefined4 *)(unaff_EDI + 0xa4) = 0;
      return iVar1;
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


// ==== 0x66c120 FUN_0066c120

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __fastcall FUN_0066c120(int param_1)

{
  if (*(int *)(param_1 + 0x80) == 4) {
    FUN_0066c0c0();
    *(undefined4 *)(param_1 + 0x84) = 0;
    *(undefined4 *)(param_1 + 0x80) = 5;
  }
  return 0;
}


// ==== 0x66c1a0 FUN_0066c1a0

void FUN_0066c1a0(void)

{
  int iVar1;
  int in_EAX;
  DWORD DVar2;
  int *unaff_ESI;
  bool bVar3;
  
  if (*unaff_ESI != 0) {
    return;
  }
  if (unaff_ESI[3] == *(int *)(in_EAX + 0x84)) {
    DVar2 = GetTickCount();
    *(DWORD *)(in_EAX + 200) = DVar2 - 1000;
    iVar1 = unaff_ESI[2];
    if (iVar1 == 1) {
      unaff_ESI[2] = 2;
      FUN_0066c0c0();
      return;
    }
    if (iVar1 == 2) {
      if (*(int *)(in_EAX + 0x80) != 2) {
        return;
      }
      *(undefined4 *)(in_EAX + 0x80) = 4;
      return;
    }
    if (iVar1 != 3) {
      return;
    }
    bVar3 = *(int *)(in_EAX + 0x80) == 4;
  }
  else {
    bVar3 = unaff_ESI[2] == 1;
  }
  if (bVar3) {
    *(undefined4 *)(in_EAX + 0x80) = 5;
  }
  return;
}


// ==== 0x66c220 FUN_0066c220

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_0066c220(uint param_1)

{
  DWORD DVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x84);
  while (uVar2 == 0) {
    DVar1 = GetTickCount();
    uVar2 = DVar1 ^ param_1;
    *(uint *)(param_1 + 0x84) = uVar2;
  }
  FUN_0066c0c0();
  return;
}


// ==== 0x66c2a0 FUN_0066c2a0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0066c2a0(void)

{
  DWORD DVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int unaff_EBX;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  int *piVar9;
  uint *puVar10;
  uint unaff_retaddr;
  int local_244;
  int local_23c;
  int local_238 [4];
  uint auStack_228 [135];
  uint local_c;
  
  local_c = DAT_006eb720 ^ unaff_retaddr;
  iVar5 = *(int *)(unaff_EBX + 0xb4);
  iVar6 = 0x800;
  local_244 = 0x800;
  if (iVar5 != *(int *)(unaff_EBX + 0xb8)) {
    do {
      iVar6 = iVar6 - *(int *)(*(int *)(unaff_EBX + 0xbc) + iVar5);
      iVar5 = (*(int *)(unaff_EBX + 0xa8) + iVar5) % *(int *)(unaff_EBX + 0xac);
    } while (iVar5 != *(int *)(unaff_EBX + 0xb8));
    local_244 = iVar6;
    if (0xff < iVar6) goto joined_r0x0066c48e;
    DVar1 = GetTickCount();
    if (DVar1 - *(int *)(unaff_EBX + 0xc4) < 0xfb) goto joined_r0x0066c48e;
    local_244 = 0x100;
  }
  do {
    iVar5 = 0x218;
    if (local_244 < 0x218) {
      iVar5 = local_244;
    }
    local_23c = 0;
    while ((0 < iVar5 && (iVar6 = *(int *)(unaff_EBX + 0xb8), iVar6 != *(int *)(unaff_EBX + 0xb0))))
    {
      piVar2 = (int *)(*(int *)(unaff_EBX + 0xbc) + iVar6);
      iVar5 = iVar5 + (-1 - *piVar2);
      if ((0 < local_23c) && (iVar5 < 1)) break;
      local_23c = local_23c + 1;
      *(int *)(unaff_EBX + 0xb8) = (*(int *)(unaff_EBX + 0xa8) + iVar6) % *(int *)(unaff_EBX + 0xac)
      ;
      if ((0xfa < *piVar2) || (7 < local_23c)) break;
    }
    if (local_23c == 0) {
      return;
    }
    iVar5 = ((*(int *)(unaff_EBX + 0xb8) - *(int *)(unaff_EBX + 0xa8)) + *(int *)(unaff_EBX + 0xac))
            % *(int *)(unaff_EBX + 0xac);
    uVar3 = *(int *)(*(int *)(unaff_EBX + 0xbc) + iVar5) + 0x10;
    piVar2 = (int *)(*(int *)(unaff_EBX + 0xbc) + iVar5);
    piVar9 = local_238;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *piVar9 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar9 = piVar9 + 1;
    }
    local_23c = local_23c + -1;
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(char *)piVar9 = (char)*piVar2;
      piVar2 = (int *)((int)piVar2 + 1);
      piVar9 = (int *)((int)piVar9 + 1);
    }
    if (0 < local_23c) {
      do {
        iVar5 = ((*(int *)(unaff_EBX + 0xac) - *(int *)(unaff_EBX + 0xa8)) + iVar5) %
                *(int *)(unaff_EBX + 0xac);
        puVar7 = (uint *)(*(int *)(unaff_EBX + 0xbc) + iVar5);
        if (*(code **)(unaff_EBX + 0x38) != (code *)0x0) {
          (**(code **)(unaff_EBX + 0x38))();
        }
        local_238[2] = local_238[2] + 0x10000000;
        uVar4 = *puVar7;
        puVar8 = puVar7 + 4;
        puVar10 = (uint *)((int)auStack_228 + local_238[0]);
        for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar10 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar10 = puVar10 + 1;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(char *)puVar10 = (char)*puVar8;
          puVar8 = (uint *)((int)puVar8 + 1);
          puVar10 = (uint *)((int)puVar10 + 1);
        }
        uVar4 = *puVar7;
        *(char *)((int)auStack_228 + local_238[0] + uVar4) = (char)*puVar7;
        local_238[0] = local_238[0] + uVar4 + 1;
        local_23c = local_23c + -1;
      } while (local_23c != 0);
    }
    if (iVar5 == *(int *)(unaff_EBX + 0xb4)) {
LAB_0066c55c:
      DAT_006eb1ac = 0x20000000;
    }
    else {
      do {
        if (DAT_006eb1ac < (uint)local_238[2]) break;
        iVar5 = ((*(int *)(unaff_EBX + 0xac) - *(int *)(unaff_EBX + 0xa8)) + iVar5) %
                *(int *)(unaff_EBX + 0xac);
        puVar7 = (uint *)(*(int *)(unaff_EBX + 0xbc) + iVar5);
        if (0x40 < *(int *)(*(int *)(unaff_EBX + 0xbc) + iVar5) + local_238[0]) break;
        if (*(code **)(unaff_EBX + 0x38) != (code *)0x0) {
          (**(code **)(unaff_EBX + 0x38))();
        }
        local_238[2] = local_238[2] + 0x10000000;
        uVar4 = *puVar7;
        puVar8 = puVar7 + 4;
        puVar10 = (uint *)((int)auStack_228 + local_238[0]);
        for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar10 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar10 = puVar10 + 1;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(char *)puVar10 = (char)*puVar8;
          puVar8 = (uint *)((int)puVar8 + 1);
          puVar10 = (uint *)((int)puVar10 + 1);
        }
        uVar4 = *puVar7;
        *(char *)((int)auStack_228 + local_238[0] + uVar4) = (char)*puVar7;
        local_238[0] = local_238[0] + uVar4 + 1;
      } while (iVar5 != *(int *)(unaff_EBX + 0xb4));
      if (iVar5 == *(int *)(unaff_EBX + 0xb4)) goto LAB_0066c55c;
      if (DAT_006eb1ac < 0x80000000) {
        DAT_006eb1ac = DAT_006eb1ac * 2;
      }
      else {
        DAT_006eb1ac = 0xf0000000;
      }
    }
    *(int *)(unaff_EBX + 0xa0) = *(int *)(unaff_EBX + 0x9c);
    local_238[3] = *(int *)(unaff_EBX + 0x9c) + -1;
    iVar5 = FUN_0066c0c0();
    if (iVar5 < 0) {
      return;
    }
    local_244 = local_244 - local_238[0];
joined_r0x0066c48e:
    if (local_244 < 1) {
      return;
    }
  } while( true );
}


// ==== 0x66c5d0 FUN_0066c5d0

void __fastcall FUN_0066c5d0(int param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  
  iVar1 = *(int *)(in_EAX + 8);
  if (iVar1 != 6) {
    uVar3 = *(uint *)(in_EAX + 0xc);
    if (iVar1 == 4) {
      uVar3 = uVar3 - 1;
    }
    if (*(int *)(param_1 + 0xb4) != *(int *)(param_1 + 0xb0)) {
      do {
        iVar2 = *(int *)(param_1 + 0xb4);
        if (uVar3 < *(uint *)(*(int *)(param_1 + 0xbc) + 8 + iVar2)) break;
        if (*(int *)(param_1 + 0xb8) == iVar2) {
          *(int *)(param_1 + 0xb8) =
               (*(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0xb8)) % *(int *)(param_1 + 0xac);
        }
        iVar2 = (*(int *)(param_1 + 0xa8) + iVar2) % *(int *)(param_1 + 0xac);
        *(int *)(param_1 + 0xb4) = iVar2;
      } while (iVar2 != *(int *)(param_1 + 0xb0));
    }
    if (iVar1 == 4) {
      *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0xb4);
      FUN_0066c2a0();
    }
  }
  return;
}


// ==== 0x66c680 FUN_0066c680

undefined4 FUN_0066c680(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int unaff_EBX;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  iVar1 = *(int *)(unaff_EBX + 0x90);
  uVar4 = *(uint *)(unaff_EBX + 0x88);
  iVar2 = *(int *)(unaff_EBX + 0x8c);
  if ((int)(uVar4 + iVar1) % iVar2 != *(int *)(unaff_EBX + 0x94)) {
    uVar3 = param_1[2];
    if (uVar3 != 6) {
      if (*(uint *)(unaff_EBX + 0x9c) <= uVar3) {
        if (*(uint *)(unaff_EBX + 0x9c) < uVar3) {
          param_1[2] = 4;
          param_1[3] = *(int *)(unaff_EBX + 0x9c);
          *param_1 = 0;
          FUN_0066c0c0();
          return 0xffffffff;
        }
        if (*param_1 != 0) goto LAB_0066c70a;
      }
      return 0;
    }
    if (4 < (iVar2 - ((iVar2 - *(int *)(unaff_EBX + 0x94)) + iVar1) % iVar2) / (int)uVar4) {
LAB_0066c70a:
      piVar5 = (int *)(*(int *)(unaff_EBX + 0x98) + iVar1);
      piVar6 = param_1;
      piVar7 = piVar5;
      for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *piVar7 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar7 = piVar7 + 1;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(char *)piVar7 = (char)*piVar6;
        piVar6 = (int *)((int)piVar6 + 1);
        piVar7 = (int *)((int)piVar7 + 1);
      }
      *(int *)(unaff_EBX + 0x204) = *(int *)(unaff_EBX + 0x204) + 1;
      *(int *)(unaff_EBX + 0x90) =
           (*(int *)(unaff_EBX + 0x88) + *(int *)(unaff_EBX + 0x90)) % *(int *)(unaff_EBX + 0x8c);
      if (param_1[2] != 6) {
        *(int *)(unaff_EBX + 0x9c) = *(int *)(unaff_EBX + 0x9c) + 1;
        *(int *)(unaff_EBX + 0xa4) = *(int *)(unaff_EBX + 0xa4) + *piVar5;
      }
      *(uint *)(unaff_EBX + 0x208) = *(uint *)(unaff_EBX + 0x208) | 1;
      if (*(code **)(unaff_EBX + 0x3c) != (code *)0x0) {
        (**(code **)(unaff_EBX + 0x3c))();
      }
      *(int *)(unaff_EBX + 0x204) = *(int *)(unaff_EBX + 0x204) + -1;
      return 1;
    }
  }
  return 2;
}


// ==== 0x66c7c0 FUN_0066c7c0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0066c7c0(void)

{
  FUN_0066c0c0(0);
  return;
}


// ==== 0x66c810 FUN_0066c810

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_0066c810(int param_1)

{
  if ((*(int *)(param_1 + 0xb4) != *(int *)(param_1 + 0xb0)) &&
     (*(int *)(param_1 + 0xb8) == *(int *)(param_1 + 0xb0))) {
    *(int *)(param_1 + 0xb8) =
         ((*(int *)(param_1 + 0xac) - *(int *)(param_1 + 0xa8)) + *(int *)(param_1 + 0xb8)) %
         *(int *)(param_1 + 0xac);
    FUN_0066c2a0();
    return;
  }
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x9c);
  FUN_0066c0c0();
  return;
}


// ==== 0x66c8d0 FUN_0066c8d0

int __fastcall FUN_0066c8d0(int param_1)

{
  return (((*(int *)(param_1 + 0xb0) - *(int *)(param_1 + 0xb4)) + *(int *)(param_1 + 0xac)) %
         *(int *)(param_1 + 0xac)) / *(int *)(param_1 + 0xa8);
}


// ==== 0x66c900 FUN_0066c900

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0066c900(void)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint unaff_retaddr;
  uint uStack_488;
  int local_484;
  undefined4 local_480;
  undefined4 local_47c;
  undefined4 local_478;
  uint local_474;
  undefined4 local_470;
  int local_46c;
  int local_468;
  int iStack_464;
  uint local_460;
  uint local_45c;
  uint local_458;
  undefined4 local_454;
  undefined4 auStack_450 [134];
  uint uStack_238;
  uint uStack_234;
  int iStack_230;
  int iStack_22c;
  undefined4 auStack_228 [135];
  uint local_c;
  
  local_c = DAT_006eb720 ^ unaff_retaddr;
  local_47c = 0;
  local_478 = 0;
  local_474 = 0;
  local_470 = 0;
  local_484 = 0;
  local_480 = 0;
  local_46c = 0;
  local_460 = 0xffffffff;
  iVar1 = local_484;
  iVar2 = DAT_00717960;
  for (iVar4 = DAT_00717960; local_484 = iVar1, iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x68)) {
    local_484 = *(int *)(iVar4 + 0x6c);
    if ((local_484 != 0) && (local_484 != iVar1)) {
      local_468 = 0x10;
      local_468 = FUN_00662f00(local_484,&local_458,0x220,0,&local_47c,&local_468);
      iVar2 = DAT_00717960;
      iVar1 = local_484;
      if (0 < local_468) {
        local_460 = local_468 - 8;
        local_45c = (((local_474 & 0xff) << 8 | local_474 >> 8 & 0xff) << 8 |
                    local_474 >> 0x10 & 0xff) << 8 | local_474 >> 0x18;
        local_480 = 1;
        break;
      }
    }
    local_484 = iVar1;
    iVar1 = local_484;
  }
  iVar1 = 0;
  iVar4 = 0;
  for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x68)) {
    DVar3 = GetTickCount();
    if ((((local_46c == 0) && (local_484 == *(int *)(iVar2 + 0x6c))) &&
        (*(int *)(iVar2 + 0x80) == 3)) && (local_460 == 0)) {
      if ((local_454 != 0) && (local_458 == 1)) {
        local_46c = iVar2;
      }
LAB_0066ca39:
      if (((*(int *)(iVar2 + 0x80) != 3) && (*(int *)(iVar2 + 0x80) != 5)) &&
         ((local_484 == *(int *)(iVar2 + 0x6c) &&
          (iVar4 = FUN_006623c0(iVar2 + 0x70,&local_47c), iVar4 == 0)))) {
        *(uint *)(iVar2 + 0x5c) = *(int *)(iVar2 + 0x5c) + local_460;
        *(int *)(iVar2 + 100) = *(int *)(iVar2 + 100) + 1;
        if (((local_458 == 1) || (local_458 == 2)) || (local_458 == 3)) {
          FUN_0066c1a0();
        }
        else if (*(int *)(iVar2 + 0x80) == 4) {
          if (local_458 == 4) {
            *(uint *)(iVar2 + 200) = local_45c;
            FUN_0066c5d0();
          }
          else if (local_458 < 0x10000001) {
            *(uint *)(iVar2 + 200) = local_45c;
            FUN_0066c5d0();
            FUN_0066c680(&local_460);
          }
          else {
            iStack_464 = *(int *)(iVar2 + 0x9c);
            uStack_488 = local_458 >> 0x1c;
            iStack_230 = (local_458 & 0xfffffff) - uStack_488;
            uStack_234 = local_45c;
            iStack_22c = local_454;
            *(uint *)(iVar2 + 200) = local_45c;
            do {
              uStack_238 = local_460;
              if (0 < (int)uStack_488) {
                iVar4 = local_460 - 1;
                local_460 = local_460 - 1;
                uStack_238 = (uint)*(byte *)((int)auStack_450 + iVar4);
              }
              local_460 = local_460 - uStack_238;
              puVar5 = (undefined4 *)((int)auStack_450 + local_460);
              puVar6 = auStack_228;
              for (uVar7 = uStack_238 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                *puVar6 = *puVar5;
                puVar5 = puVar5 + 1;
                puVar6 = puVar6 + 1;
              }
              for (uVar7 = uStack_238 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
                puVar5 = (undefined4 *)((int)puVar5 + 1);
                puVar6 = (undefined4 *)((int)puVar6 + 1);
              }
              FUN_0066c5d0();
              iVar4 = FUN_0066c680(&uStack_238);
              if (iVar4 < 0) {
                uStack_488 = 0;
              }
              else if ((0 < (int)uStack_488) && (iStack_464 != *(int *)(iVar2 + 0x9c))) {
                iStack_464 = *(int *)(iVar2 + 0x9c);
              }
              uStack_488 = uStack_488 - 1;
              iStack_230 = iStack_230 + 1;
            } while (-1 < (int)uStack_488);
          }
        }
        local_460 = 0xffffffff;
      }
    }
    else if (-1 < (int)local_460) goto LAB_0066ca39;
    if ((*(int *)(iVar2 + 0x80) == 2) && (1000 < DVar3 - *(int *)(iVar2 + 0xc4))) {
      FUN_0066c220();
    }
    if (*(int *)(iVar2 + 0x80) == 4) {
      if (*(int *)(iVar2 + 0xb8) != *(int *)(iVar2 + 0xb0)) {
        FUN_0066c2a0();
      }
      if (((*(int *)(iVar2 + 0x80) == 4) && (120000 < DVar3 - *(int *)(iVar2 + 200))) &&
         (DVar3 - *(int *)(iVar2 + 0xc4) < 2000)) {
        FUN_0066c120();
      }
    }
    if (((*(int *)(iVar2 + 0x80) == 3) && (*(short *)(iVar2 + 0x70) == 2)) &&
       (*(int *)(iVar2 + 0xc4) + 1000U < DVar3)) {
      FUN_0066c7c0();
    }
    if ((*(int *)(iVar2 + 0x208) == 0) && (*(int *)(iVar2 + 0xcc) + 0xfaU < DVar3)) {
      *(DWORD *)(iVar2 + 0xcc) = DVar3;
      *(undefined4 *)(iVar2 + 0x208) = 4;
    }
    if ((*(int *)(iVar2 + 0x204) == 0) && (*(int *)(iVar2 + 0x208) != 0)) {
      *(int *)(iVar2 + 0x204) = *(int *)(iVar2 + 0x204) + 1;
      if (*(code **)(iVar2 + 0x20c) != (code *)0x0) {
        (**(code **)(iVar2 + 0x20c))(iVar2,*(int *)(iVar2 + 0x208));
      }
      *(int *)(iVar2 + 0x204) = *(int *)(iVar2 + 0x204) + -1;
      *(undefined4 *)(iVar2 + 0x208) = 0;
      DVar3 = GetTickCount();
    }
    if (((*(int *)(iVar2 + 0x80) == 4) && (*(int *)(iVar2 + 0xb8) == *(int *)(iVar2 + 0xb0))) &&
       ((((uVar7 = DVar3 - *(int *)(iVar2 + 0xc4), 100 < uVar7 &&
          ((*(int *)(iVar2 + 0xa0) != *(int *)(iVar2 + 0x9c) ||
           (*(int *)(iVar2 + 0xb0) != *(int *)(iVar2 + 0xb4))))) || (0x9c4 < uVar7)) ||
        (0x7ff < *(int *)(iVar2 + 0xa4))))) {
      *(undefined4 *)(iVar2 + 0xa4) = 0;
      FUN_0066c810();
    }
    iVar1 = local_46c;
    iVar4 = DAT_00717960;
  }
  if (((-1 < (int)local_460) && (local_458 == 5)) && ((short)local_47c == 2)) {
    for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x68)) {
      if (((*(int *)(iVar4 + 0x80) == 2) && (*(short *)(iVar4 + 0x70) == 2)) &&
         (local_484 == *(int *)(iVar4 + 0x6c))) {
        *(undefined4 *)(iVar4 + 0x70) = local_47c;
        *(undefined4 *)(iVar4 + 0x74) = local_478;
        *(uint *)(iVar4 + 0x78) = local_474;
        *(undefined4 *)(iVar4 + 0x7c) = local_470;
        break;
      }
    }
  }
  if ((iVar1 != 0) && (local_460 == 0)) {
    *(undefined4 *)(iVar1 + 0x70) = local_47c;
    *(undefined4 *)(iVar1 + 0x74) = local_478;
    *(uint *)(iVar1 + 0x78) = local_474;
    *(undefined4 *)(iVar1 + 0x7c) = local_470;
    *(int *)(iVar1 + 0x84) = local_454;
    *(undefined4 *)(iVar1 + 0x80) = 4;
    FUN_0066c1a0();
  }
  return local_480;
}


// ==== 0x66ce50 FUN_0066ce50

undefined4 FUN_0066ce50(void)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = FUN_00668d10(&DAT_0071793c);
  if (iVar1 != 0) {
    DVar2 = GetTickCount();
    do {
      iVar1 = FUN_0066c900(DVar2);
    } while (0 < iVar1);
    DAT_00717938 = 0;
    FUN_00668df0(&DAT_0071793c);
    return 0;
  }
  DAT_00717938 = DAT_00717938 + 1;
  return 0;
}


// ==== 0x66ceb0 FUN_0066ceb0

void FUN_0066ceb0(void)

{
  int unaff_ESI;
  
  if (DAT_00717960 == 0) {
    FUN_00668cc0(&DAT_0071793c);
    DAT_00717938 = 0;
  }
  FUN_00668d60(&DAT_0071793c);
  *(int *)(unaff_ESI + 0x68) = DAT_00717960;
  DAT_00717960 = unaff_ESI;
  FUN_00668df0(&DAT_0071793c);
  return;
}


// ==== 0x66cf00 FUN_0066cf00

void FUN_0066cf00(void)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  
  FUN_00668d60(&DAT_0071793c);
  piVar2 = &DAT_00717960;
  iVar1 = DAT_00717960;
  while (iVar1 != unaff_ESI) {
    piVar2 = (int *)(iVar1 + 0x68);
    iVar1 = *piVar2;
  }
  *piVar2 = *(int *)(unaff_ESI + 0x68);
  FUN_00668df0(&DAT_0071793c);
  if (DAT_00717960 == 0) {
    FUN_00668cf0(&DAT_0071793c);
  }
  return;
}


// ==== 0x66cf50 FUN_0066cf50

void FUN_0066cf50(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_0066c8d0(200);
  FUN_0066cf00();
  if (*(int *)(param_1 + 0x80) == 4) {
    FUN_0066c120();
  }
  iVar1 = *(int *)(param_1 + 0x6c);
  iVar2 = DAT_00717960;
  if (iVar1 != 0) {
    for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x68)) {
      if (*(int *)(iVar2 + 0x6c) == iVar1) goto LAB_0066cfac;
    }
    FUN_00662ce0(iVar1);
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
LAB_0066cfac:
  FUN_00668cf0(param_1 + 0x1e0);
  FUN_00447030(*(undefined4 *)(param_1 + 0x98));
  FUN_00447030(*(undefined4 *)(param_1 + 0xbc));
  FUN_00447030(param_1);
  return;
}


// ==== 0x66cfe0 FUN_0066cfe0

void FUN_0066cfe0(int param_1,undefined4 param_2)

{
  FUN_00668d60(param_1 + 0x1e0);
  *(undefined4 *)(param_1 + 0x20c) = param_2;
  *(uint *)(param_1 + 0x208) = *(uint *)(param_1 + 0x208) | 2;
  FUN_00668df0(param_1 + 0x1e0);
  return;
}


// ==== 0x66d020 FUN_0066d020

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0066d020(int param_1,char *param_2,char *param_3,undefined4 param_4,undefined1 param_5)

{
  int iVar1;
  char *pcVar2;
  char cVar3;
  uint unaff_retaddr;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  uint uStack_4;
  
  uStack_4 = DAT_006eb720 ^ unaff_retaddr;
  *param_3 = '*';
  param_3[1] = '\0';
  param_3[2] = '\0';
  if (*(int *)(param_1 + 0xd0) != 0) {
    return 0xfffffff8;
  }
  *(char **)(param_1 + 0x1d4) = param_3;
  *(undefined4 *)(param_1 + 0x1d8) = param_4;
  *(undefined1 *)(param_1 + 0x1dc) = param_5;
  iVar1 = FUN_00668c60(param_2,"localhost",0xffffffff);
  if (iVar1 == 0) {
    uStack_14 = 0;
    uStack_10 = 0;
    uStack_c = 0;
    uStack_24 = 2;
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_22 = 0x4f00;
    uStack_20 = 0x101a8c0;
    uStack_8 = 0;
    FUN_00663190(&uStack_14,0x10,&uStack_24,0x10);
    if (CONCAT31(CONCAT21(CONCAT11((undefined1)uStack_10,uStack_10._1_1_),uStack_10._2_1_),
                 uStack_10._3_1_) == 0) {
      uStack_10 = 0x100007f;
    }
    FUN_00662490(&uStack_14,param_3,param_4);
    return 1;
  }
  FUN_00662410(&uStack_24,param_2);
  if (CONCAT31(CONCAT21(CONCAT11((undefined1)uStack_20,uStack_20._1_1_),uStack_20._2_1_),
               uStack_20._3_1_) != 0) {
    cVar3 = *param_2;
    pcVar2 = param_3;
    if (cVar3 != '\0') {
      do {
        *pcVar2 = cVar3;
        cVar3 = pcVar2[(int)(param_2 + (1 - (int)param_3))];
        pcVar2 = pcVar2 + 1;
      } while (cVar3 != '\0');
    }
    *pcVar2 = '\0';
    pcVar2[1] = '\0';
    return 1;
  }
  *param_3 = '*';
  return 0;
}


// ==== 0x66d1e0 FUN_0066d1e0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0066d1e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint unaff_retaddr;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  if (*(int *)(param_1 + 0x80) != 1) {
    FUN_00662ce0(param_2);
    return 0xfffffffe;
  }
  *(undefined4 *)(param_1 + 0x6c) = 0;
  FUN_0066c060();
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  local_14 = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  local_10 = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  local_c = 0;
  local_8 = 0;
  iVar2 = DAT_00717960;
  do {
    if (iVar2 == 0) {
      iVar2 = FUN_00662d70(param_2,param_3,0x10);
      if (iVar2 < 0) {
        *(undefined4 *)(param_1 + 0x80) = 0;
        FUN_00662ce0(param_2);
        return 0xfffffffb;
      }
      *(undefined4 *)(param_1 + 0x6c) = param_2;
      FUN_00663160(param_2,2,100,0,FUN_0066ce50);
LAB_0066d308:
      *(undefined4 *)(param_1 + 0x80) = 3;
      return 0;
    }
    if ((((iVar2 != param_1) && (*(int *)(iVar2 + 0x6c) != 0)) &&
        (iVar1 = FUN_00662f90(*(int *)(iVar2 + 0x6c),0x62696e64,&local_14,0x10), -1 < iVar1)) &&
       (iVar1 = FUN_006623c0(param_3,&local_14), iVar1 == 0)) {
      *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(iVar2 + 0x6c);
      FUN_00662ce0(param_2);
      goto LAB_0066d308;
    }
    iVar2 = *(int *)(iVar2 + 0x68);
  } while( true );
}


// ==== 0x66d330 FUN_0066d330

undefined4 FUN_0066d330(int param_1)

{
  FUN_0066c8d0(200);
  if (*(int *)(param_1 + 0x80) == 3) {
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  if (*(int *)(param_1 + 0x6c) != 0) {
    FUN_0066c120();
    FUN_00662ce0(*(undefined4 *)(param_1 + 0x6c));
  }
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 1;
  return 0;
}


// ==== 0x66d390 FUN_0066d390

undefined4 FUN_0066d390(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (*(int *)(param_1 + 0x80) != 1) {
    FUN_00662ce0(param_2);
    return 0xfffffffe;
  }
  *(undefined4 *)(param_1 + 0x6c) = 0;
  FUN_0066c060();
  *(undefined4 *)(param_1 + 0x70) = *param_3;
  *(undefined4 *)(param_1 + 0x74) = param_3[1];
  *(undefined4 *)(param_1 + 0x78) = param_3[2];
  *(undefined4 *)(param_1 + 0x7c) = param_3[3];
  *(undefined4 *)(param_1 + 0x6c) = param_2;
  FUN_00663160(param_2,2,100,0,FUN_0066ce50);
  *(undefined4 *)(param_1 + 0x80) = 2;
  return 0;
}


// ==== 0x66d410 FUN_0066d410

int FUN_0066d410(int param_1,uint *param_2,uint param_3,byte param_4)

{
  int iVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  
  if (*(int *)(param_1 + 0x80) != 4) {
    return -2;
  }
  iVar3 = *(int *)(param_1 + 0xa8);
  iVar5 = *(int *)(param_1 + 0xb0);
  iVar1 = *(int *)(param_1 + 0xac);
  if ((iVar5 + iVar3) % iVar1 == *(int *)(param_1 + 0xb4)) {
    return 0;
  }
  if (iVar3 + -0x10 < (int)param_3) {
    return -6;
  }
  if (param_3 == 0) {
    return (((iVar1 - *(int *)(param_1 + 0xb4)) + iVar5) % iVar1) / iVar3 + 1;
  }
  puVar6 = (uint *)(*(int *)(param_1 + 0xbc) + iVar5);
  uVar4 = param_3 >> 2;
  *puVar6 = param_3;
  puVar7 = puVar6 + 4;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar7 = *param_2;
    param_2 = param_2 + 1;
    puVar7 = puVar7 + 1;
  }
  for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
    *(char *)puVar7 = (char)*param_2;
    param_2 = (uint *)((int)param_2 + 1);
    puVar7 = (uint *)((int)puVar7 + 1);
  }
  DVar2 = GetTickCount();
  puVar6[1] = DVar2;
  if ((param_4 & 1) != 0) {
    FUN_00668d60(&DAT_0071793c);
    puVar6[2] = 6;
    puVar6[3] = *(int *)(param_1 + 0xa0) - 1;
    FUN_0066c0c0();
    FUN_00668df0(&DAT_0071793c);
    return 1;
  }
  puVar6[2] = *(uint *)(param_1 + 0xc0);
  *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xc0) + 1;
  puVar6[3] = *(int *)(param_1 + 0x9c) - 1;
  iVar3 = *(int *)(param_1 + 0xac);
  iVar5 = (*(int *)(param_1 + 0xb0) + *(int *)(param_1 + 0xa8)) % iVar3;
  *(int *)(param_1 + 0xb0) = iVar5;
  iVar3 = (((iVar5 - *(int *)(param_1 + 0xb4)) + iVar3) % iVar3) / *(int *)(param_1 + 0xa8);
  if (iVar3 < 0x10) {
    FUN_00668d60(&DAT_0071793c);
    FUN_0066c2a0();
    if (DAT_00717938 != 0) {
      DVar2 = GetTickCount();
      do {
        iVar5 = FUN_0066c900(DVar2);
      } while (0 < iVar5);
      DAT_00717938 = 0;
    }
    FUN_00668df0(&DAT_0071793c);
  }
  if (iVar3 < 1) {
    iVar3 = 1;
  }
  return iVar3;
}


// ==== 0x66d5a0 FUN_0066d5a0

uint FUN_0066d5a0(int param_1,uint *param_2,uint param_3,uint *param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  if (*(int *)(param_1 + 0x94) == *(int *)(param_1 + 0x90)) {
    FUN_0066ce50(0,0,param_1);
  }
  if (*(int *)(param_1 + 0x94) == *(int *)(param_1 + 0x90)) {
    return 0xfffffff9;
  }
  puVar1 = (uint *)(*(int *)(param_1 + 0x98) + *(int *)(param_1 + 0x94));
  uVar3 = *puVar1;
  if ((int)param_3 <= (int)*puVar1) {
    uVar3 = param_3;
  }
  puVar4 = puVar1 + 4;
  for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *param_2 = *puVar4;
    puVar4 = puVar4 + 1;
    param_2 = param_2 + 1;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(char *)param_2 = (char)*puVar4;
    puVar4 = (uint *)((int)puVar4 + 1);
    param_2 = (uint *)((int)param_2 + 1);
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = puVar1[1];
  }
  return *puVar1;
}


// ==== 0x66d620 FUN_0066d620

int FUN_0066d620(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0066d5a0(param_1,param_2,param_3,param_4);
  if (-1 < iVar1) {
    *(int *)(param_1 + 0x94) =
         (*(int *)(param_1 + 0x88) + *(int *)(param_1 + 0x94)) % *(int *)(param_1 + 0x8c);
  }
  return iVar1;
}


// ==== 0x66d670 FUN_0066d670

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_0066d670(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint unaff_retaddr;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  undefined2 uStack_14;
  undefined2 uStack_12;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  uint uStack_4;
  
  uStack_4 = DAT_006eb720 ^ unaff_retaddr;
  uStack_14 = 2;
  uStack_12 = 0;
  uStack_10 = 0;
  uStack_c = 0;
  uStack_8 = 0;
  uVar1 = FUN_00662730(&iStack_1c,&iStack_20,&iStack_18,param_2);
  if ((uVar1 & 2) == 0) {
    return -3;
  }
  uStack_12 = CONCAT11((char)iStack_20,(char)((uint)iStack_20 >> 8));
  iVar2 = FUN_00662c30(2,2,0);
  if (iVar2 == 0) {
    return -4;
  }
  iVar2 = FUN_0066d1e0(param_1,iVar2,&uStack_14);
  if ((iVar2 == 0) && (iStack_1c != 0)) {
    if (iStack_18 == 0) {
      iStack_18 = iStack_20 + 1;
    }
    *(undefined4 *)(param_1 + 0x74) = 0;
    *(char *)(param_1 + 0x77) = (char)iStack_1c;
    *(char *)(param_1 + 0x76) = (char)((uint)iStack_1c >> 8);
    *(char *)(param_1 + 0x75) = (char)((uint)iStack_1c >> 0x10);
    *(char *)(param_1 + 0x74) = (char)((uint)iStack_1c >> 0x18);
    *(undefined2 *)(param_1 + 0x72) = 0;
    *(undefined2 *)(param_1 + 0x70) = 2;
    *(undefined4 *)(param_1 + 0x78) = 0;
    *(undefined4 *)(param_1 + 0x7c) = 0;
    *(char *)(param_1 + 0x72) = (char)((uint)iStack_18 >> 8);
    *(char *)(param_1 + 0x73) = (char)iStack_18;
  }
  return iVar2;
}


// ==== 0x66d780 FUN_0066d780

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0066d780(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint unaff_retaddr;
  int iStack_30;
  int iStack_2c;
  undefined1 auStack_28 [4];
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  undefined2 uStack_12;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  uint uStack_4;
  
  uStack_4 = DAT_006eb720 ^ unaff_retaddr;
  uStack_24 = 2;
  uStack_22 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 2;
  uStack_12 = 0;
  uStack_10 = 0;
  uStack_c = 0;
  uStack_8 = 0;
  bVar1 = FUN_00662730(auStack_28,&iStack_30,&iStack_2c,param_2);
  if ((bVar1 & 3) != 3) {
    return 0xfffffffd;
  }
  if (iStack_2c == 0) {
    iStack_2c = iStack_30;
    iStack_30 = iStack_30 + 1;
  }
  iVar2 = FUN_00662c30(2,2,0);
  if (iVar2 == 0) {
    return 0xfffffffc;
  }
  uStack_12 = CONCAT11((char)iStack_30,(char)((uint)iStack_30 >> 8));
  iVar3 = FUN_00662d70(iVar2,&uStack_14,0x10);
  if (iVar3 < 0) {
    uStack_12 = 0;
    iVar3 = FUN_00662d70(iVar2,&uStack_14,0x10);
    if (iVar3 < 0) {
      FUN_00662ce0(iVar2);
      return 0xfffffffb;
    }
  }
  uStack_20 = CONCAT31(CONCAT21(CONCAT11(auStack_28[0],auStack_28[1]),auStack_28[2]),auStack_28[3]);
  uStack_22 = CONCAT11((char)iStack_2c,(char)((uint)iStack_2c >> 8));
  uVar4 = FUN_0066d390(param_1,iVar2,&uStack_24);
  return uVar4;
}


// ==== 0x66d8f0 FUN_0066d8f0

undefined4 * FUN_0066d8f0(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar1 = (undefined4 *)FUN_00549460(0x210);
  puVar3 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    puVar3 = puVar1;
    for (iVar4 = 0x84; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    *puVar1 = FUN_0066d8f0;
    puVar1[1] = FUN_0066cf50;
    puVar1[2] = FUN_0066d020;
    puVar1[3] = NullUpdate_ret;
    puVar1[4] = FUN_0066d670;
    puVar1[5] = FUN_0066d330;
    puVar1[6] = FUN_0066d780;
    puVar1[7] = FUN_0066d330;
    puVar1[8] = FUN_0066cfe0;
    puVar1[9] = FUN_0066ac00;
    puVar1[10] = GetTickCount;
    puVar1[0xb] = FUN_0066d410;
    puVar1[0xc] = FUN_0066d5a0;
    puVar1[0xd] = FUN_0066d620;
    puVar1[0x12] = 0x20504455;
    *(undefined1 *)(puVar1 + 0x13) = 0;
    FUN_00668cc0(puVar1 + 0x78);
    uVar5 = param_1 + 0x13U & 0x7ffc;
    puVar1[0x22] = uVar5;
    puVar1[0x23] = uVar5 * param_2;
    uVar2 = FUN_00549460(uVar5 * param_2);
    puVar1[0x2a] = uVar5;
    puVar1[0x26] = uVar2;
    puVar1[0x2b] = uVar5 * param_3;
    uVar2 = FUN_00549460(uVar5 * param_3);
    puVar1[0x2f] = uVar2;
    puVar1[0x1b] = 0;
    puVar1[0x1c] = 0;
    puVar1[0x1d] = 0;
    puVar1[0x1e] = 0;
    puVar1[0x1f] = 0;
    puVar1[0x20] = 1;
    puVar1[0x21] = 0;
    FUN_0066ceb0();
    puVar3 = puVar1;
  }
  return puVar3;
}


// ==== 0x66da20 FUN_0066da20

void FUN_0066da20(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  while (iVar1 != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x18) = *puVar2;
    FUN_00447030(puVar2);
    iVar1 = *(int *)(param_1 + 0x18);
  }
  FUN_00447030(*(undefined4 *)(param_1 + 0x14));
  FUN_00447030(param_1);
  return;
}


// ==== 0x66da60 FUN_0066da60

int FUN_0066da60(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_2 < 1) {
    param_2 = 1;
  }
  puVar1 = (undefined4 *)FUN_00549460((param_2 + 1) * 0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 **)(param_1 + 0x18) = puVar1;
    puVar2 = puVar1 + (param_2 + 1) * 3;
    while (puVar1 = puVar1 + 3, puVar1 != puVar2) {
      *puVar1 = *(undefined4 *)(param_1 + 0x1c);
      *(undefined4 **)(param_1 + 0x1c) = puVar1;
    }
    return param_2;
  }
  return -1;
}


// ==== 0x66dac0 FUN_0066dac0

int FUN_0066dac0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (*param_1 == 0) {
    return 0;
  }
  iVar1 = param_1[5];
  if (*(int *)(iVar1 + param_1[1] * 4) == 0) {
    do {
      iVar3 = (param_1[1] + 1) % param_1[4];
      param_1[1] = iVar3;
    } while (*(int *)(param_1[5] + iVar3 * 4) == 0);
  }
  piVar2 = *(int **)(iVar1 + param_1[1] * 4);
  *(int *)(iVar1 + param_1[1] * 4) = *piVar2;
  *piVar2 = param_1[7];
  param_1[7] = (int)piVar2;
  *param_1 = *param_1 + -1;
  return piVar2[1];
}


// ==== 0x66db20 FUN_0066db20

undefined4 __fastcall FUN_0066db20(undefined4 param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  
  uVar3 = 0;
  bVar2 = *param_2;
  while (bVar2 != 0) {
    if (' ' < (char)bVar2) {
      uVar3 = (bVar2 & 0x5f) + uVar3 * 0x83;
    }
    pbVar1 = param_2 + 1;
    param_2 = param_2 + 1;
    bVar2 = *pbVar1;
  }
  return (int)((longlong)(ulonglong)(uVar3 & 0x7fffffff) % (longlong)*(int *)(param_3 + 0x10));
}


// ==== 0x66db60 FUN_0066db60

int FUN_0066db60(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  while( true ) {
    do {
      bVar1 = (&DAT_006ab898)[*param_1];
      param_1 = param_1 + 1;
    } while (bVar1 == 1);
    do {
      bVar2 = *param_2;
      param_2 = param_2 + 1;
    } while ((&DAT_006ab898)[bVar2] == 1);
    iVar3 = (uint)bVar1 - (uint)(byte)(&DAT_006ab898)[bVar2];
    if (iVar3 != 0) break;
    if (bVar1 == 0) {
      return 0;
    }
  }
  return iVar3;
}


// ==== 0x66dbb0 FUN_0066dbb0

undefined4 FUN_0066dbb0(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_0066db20(param_1);
  if (param_1[7] == 0) {
    iVar3 = FUN_0066da60(param_1,(*param_1 * 3 + 10) / 2);
    if (iVar3 < 1) {
      return 0xffffffff;
    }
  }
  piVar1 = (int *)param_1[7];
  param_1[7] = *piVar1;
  piVar1[2] = param_2;
  piVar1[1] = param_3;
  *piVar1 = *(int *)(param_1[5] + iVar2 * 4);
  *(int **)(param_1[5] + iVar2 * 4) = piVar1;
  *param_1 = *param_1 + 1;
  return 1;
}


// ==== 0x66dc20 FUN_0066dc20

undefined4 FUN_0066dc20(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = FUN_0066db20(param_1);
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x14) + iVar2 * 4);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    iVar2 = (**(code **)(param_1 + 0x20))(puVar1[2],param_2);
    if (iVar2 == 0) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1[1];
}


// ==== 0x66dc70 FUN_0066dc70

int FUN_0066dc70(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = FUN_0066db20(param_1);
  piVar2 = *(int **)(param_1[5] + iVar3 * 4);
  piVar1 = (int *)(param_1[5] + iVar3 * 4);
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    iVar3 = (*(code *)param_1[8])(*(undefined4 *)(*piVar1 + 8),param_2);
    if (iVar3 == 0) break;
    piVar1 = (int *)*piVar1;
    piVar2 = (int *)*piVar1;
  }
  *piVar1 = *piVar2;
  *piVar2 = param_1[7];
  param_1[7] = (int)piVar2;
  *param_1 = *param_1 + -1;
  return piVar2[1];
}


// ==== 0x66dcd0 FUN_0066dcd0

undefined4 FUN_0066dcd0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_2;
  if (param_2 < 0) {
    iVar3 = -param_2;
  }
  iVar1 = param_1[4];
  if (param_1[7] == 0) {
    iVar4 = FUN_0066da60(param_1,(*param_1 * 3 + 10) / 2);
    if (iVar4 < 1) {
      return 0xffffffff;
    }
  }
  piVar2 = (int *)param_1[7];
  param_1[7] = *piVar2;
  piVar2[2] = param_2;
  piVar2[1] = param_3;
  *piVar2 = *(int *)(param_1[5] + (iVar3 % iVar1) * 4);
  *(int **)(param_1[5] + (iVar3 % iVar1) * 4) = piVar2;
  *param_1 = *param_1 + 1;
  return 1;
}


// ==== 0x66dd40 FUN_0066dd40

undefined4 FUN_0066dd40(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = param_2;
  if (param_2 < 0) {
    iVar2 = -param_2;
  }
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x14) + (iVar2 % *(int *)(param_1 + 0x10)) * 4);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    if (puVar1[2] == param_2) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1[1];
}


// ==== 0x66dd80 FUN_0066dd80

int FUN_0066dd80(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = param_2;
  if (param_2 < 0) {
    iVar4 = -param_2;
  }
  piVar1 = *(int **)(param_1[5] + (iVar4 % param_1[4]) * 4);
  piVar3 = (int *)(param_1[5] + (iVar4 % param_1[4]) * 4);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    piVar2 = (int *)*piVar3;
    if (piVar2[2] == param_2) break;
    piVar1 = (int *)*piVar2;
    piVar3 = piVar2;
  }
  *piVar3 = *piVar1;
  *piVar1 = param_1[7];
  param_1[7] = (int)piVar1;
  *param_1 = *param_1 + -1;
  return piVar1[1];
}


// ==== 0x66ddd0 FUN_0066ddd0

undefined4 * FUN_0066ddd0(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 < 1) {
    param_1 = 1;
  }
  if (param_2 < 0x10) {
    param_2 = 0x10;
  }
  puVar1 = (undefined4 *)FUN_00549460(0x24);
  puVar2 = puVar1;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar1[4] = param_2;
  puVar2 = (undefined4 *)FUN_00549460(param_2 * 4);
  puVar1[5] = puVar2;
  for (uVar4 = puVar1[4] & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  puVar1[8] = FUN_0066db60;
  if (0 < param_1) {
    FUN_0066da60(puVar1,param_1);
  }
  return puVar1;
}


// ==== 0x66de50 FUN_0066de50

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 * FUN_0066de50(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint unaff_retaddr;
  undefined1 local_194 [400];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  iVar1 = Ordinal_115(2,local_194);
  if (iVar1 != 0) {
    return (undefined4 *)0x0;
  }
  if (DAT_00717964 == 0) {
    DAT_00717964 = GetTickCount();
  }
  puVar2 = _malloc(0x4c);
  if (puVar2 != (undefined4 *)0x0) {
    puVar3 = puVar2;
    for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    *puVar2 = 0xffffffff;
    puVar2[7] = 0;
  }
  return puVar2;
}


// ==== 0x66def0 FUN_0066def0

void FUN_0066def0(int *param_1)

{
  if (*param_1 != -1) {
    Ordinal_3(*param_1);
  }
  Sleep(0x32);
  Ordinal_116();
  if ((void *)param_1[0xf] != (void *)0x0) {
    _free((void *)param_1[0xf]);
  }
  if ((void *)param_1[0xc] != (void *)0x0) {
    _free((void *)param_1[0xc]);
  }
  _free(param_1);
  return;
}


// ==== 0x66df40 FUN_0066df40

uint FUN_0066df40(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0x706f7274) {
    uVar1 = Ordinal_15(*(undefined2 *)(param_1 + 6));
    return uVar1 & 0xffff;
  }
  if (param_2 == 0x61646472) {
    uVar1 = Ordinal_14(*(undefined4 *)(param_1 + 8));
    return uVar1;
  }
  if (param_2 == 0x6c616472) {
    return *(uint *)(param_1 + 0x14);
  }
  if (param_2 == 0x6c707274) {
    return *(uint *)(param_1 + 0x18);
  }
  if (param_2 == 0x6f627566) {
    return *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x28);
  }
  if (param_2 == 0x69627566) {
    if (*(int *)(param_1 + 0x3c) != 0) {
      return *(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x38);
    }
  }
  else if (param_2 == 0x73746174) {
    return *(uint *)(param_1 + 0x1c);
  }
  return 0;
}


// ==== 0x66dfd0 FUN_0066dfd0

undefined4 FUN_0066dfd0(int *param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  if (*param_1 != -1) {
    return 0xffffffff;
  }
  if ((void *)param_1[0xf] != (void *)0x0) {
    _free((void *)param_1[0xf]);
    param_1[0xf] = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  *(undefined2 *)(param_1 + 1) = 2;
  iVar2 = Ordinal_8(param_2);
  param_1[2] = iVar2;
  uVar1 = Ordinal_9(param_2);
  *(undefined2 *)((int)param_1 + 6) = uVar1;
  param_1[7] = 2;
  param_1[8] = 0;
  return 0;
}


// ==== 0x66e040 FUN_0066e040

undefined4 FUN_0066e040(int *param_1)

{
  if (*param_1 != -1) {
    Ordinal_3(*param_1);
    *param_1 = -1;
  }
  if ((void *)param_1[0xc] != (void *)0x0) {
    _free((void *)param_1[0xc]);
    param_1[0xc] = 0;
  }
  param_1[7] = 4;
  return 0;
}


// ==== 0x66e080 FUN_0066e080

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0066e080(int *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  DWORD DVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  uint unaff_retaddr;
  ushort uStack_124;
  undefined2 uStack_122;
  undefined1 local_118 [16];
  undefined4 local_108;
  int local_104;
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  if ((param_1[7] == 3) && (*param_1 == -1)) {
    if ((void *)param_1[0xf] != (void *)0x0) {
      _free((void *)param_1[0xf]);
    }
    param_1[0xd] = 0xc;
    param_1[0xe] = 0xc;
    puVar1 = _malloc(0xd);
    param_1[0xf] = (int)puVar1;
    puVar1[3] = 0xff;
    puVar1[2] = 0xff;
    puVar1[1] = 0xff;
    *puVar1 = 0xff;
    puVar1[7] = 0xfe;
    puVar1[6] = 0xfe;
    puVar1[5] = 0xfe;
    puVar1[4] = 0xfe;
    puVar1[10] = 0;
    puVar1[9] = 0;
    puVar1[8] = 0;
    puVar1[0xb] = 0xc;
    param_1[7] = 4;
  }
  if ((param_1[7] == 4) && (param_1[0xc] != 0)) {
    param_1[7] = 2;
    param_1[8] = 0;
  }
  if (param_1[7] == 1) {
    iVar2 = Ordinal_1(*param_1,local_118);
    if (iVar2 == -1) {
      return;
    }
    Ordinal_3(*param_1);
    *param_1 = iVar2;
    param_1[7] = 3;
    param_1[10] = 0;
    if ((void *)param_1[0xf] != (void *)0x0) {
      _free((void *)param_1[0xf]);
    }
    param_1[0xd] = 0xc;
    param_1[0xe] = 0xc;
    puVar1 = _malloc(0xd);
    param_1[0xf] = (int)puVar1;
    puVar1[3] = 0xff;
    puVar1[2] = 0xff;
    puVar1[1] = 0xff;
    *puVar1 = 0xff;
    puVar1[7] = 0xff;
    puVar1[6] = 0xff;
    puVar1[5] = 0xff;
    puVar1[4] = 0xff;
    puVar1[10] = 0;
    puVar1[9] = 0;
    puVar1[8] = 0;
    puVar1[0xb] = 0xc;
  }
  if (param_1[7] == 2) {
    DVar3 = GetTickCount();
    if ((uint)param_1[8] < DVar3) {
      if (*param_1 != -1) {
        Ordinal_3();
      }
      iVar2 = Ordinal_23(2,1);
      *param_1 = iVar2;
      if (iVar2 == -1) {
        Ordinal_111();
      }
      Ordinal_10(*param_1,0x8004667e,&stack0xfffffecc);
      Ordinal_4(*param_1,param_1 + 1,0x10);
      DVar3 = GetTickCount();
      param_1[8] = DVar3 + 30000;
    }
    local_104 = *param_1;
    if (local_104 == -1) {
      return;
    }
    local_108 = 1;
    iVar2 = Ordinal_18(1,0,&local_108,&local_108);
    if (iVar2 == 0) {
      return;
    }
    iVar2 = Ordinal_7(*param_1,0xffff,0x1007,&stack0xfffffec8,&stack0xfffffec4);
    if ((iVar2 == 0) && (CONCAT22(uStack_122,uStack_124) == 0)) {
      Ordinal_6(*param_1,local_118);
      iVar2 = Ordinal_14(0);
      param_1[5] = iVar2;
      uVar4 = Ordinal_15((uint)uStack_124 << 0x10);
      param_1[6] = uVar4 & 0xffff;
      param_1[7] = 3;
      param_1[10] = 0;
      if ((void *)param_1[0xf] != (void *)0x0) {
        _free((void *)param_1[0xf]);
      }
      param_1[0xd] = 0xc;
      param_1[0xe] = 0xc;
      puVar1 = _malloc(0xd);
      param_1[0xf] = (int)puVar1;
      puVar1[3] = 0xff;
      puVar1[2] = 0xff;
      puVar1[1] = 0xff;
      *puVar1 = 0xff;
      puVar1[7] = 0xff;
      puVar1[6] = 0xff;
      puVar1[5] = 0xff;
      puVar1[4] = 0xff;
      puVar1[10] = 0;
      puVar1[9] = 0;
      puVar1[8] = 0;
      puVar1[0xb] = 0xc;
      goto LAB_0066e342;
    }
    param_1[8] = (DAT_00717964 & 0xfff) + 1000;
    DVar3 = GetTickCount();
    param_1[8] = param_1[8] + DVar3;
    DAT_00717964 = DAT_00717964 * 0x19660d + 0x3c6ef35f;
LAB_0066e3ce:
    Ordinal_3();
    *param_1 = -1;
  }
  else {
LAB_0066e342:
    if (*param_1 == -1) {
      return;
    }
    if (param_1[0xc] == 0) {
LAB_0066e405:
      if (param_1[0xf] == 0) {
        if (param_1[0xd] == param_1[0xe]) {
          param_1[0xd] = 0xc;
          param_1[0xe] = 0;
        }
        iVar2 = Ordinal_16(*param_1,param_1[0xe] + 0x40 + (int)param_1,param_1[0xd] - param_1[0xe]);
        if ((iVar2 < 0) && (iVar5 = Ordinal_111(), iVar5 != 0x2733)) {
          Ordinal_3();
          *param_1 = -1;
          return;
        }
        if (iVar2 == 0) goto LAB_0066e3ce;
        if (0 < iVar2) {
          param_1[0xe] = param_1[0xe] + iVar2;
        }
        if (param_1[0xe] == param_1[0xd]) {
          uVar4 = CONCAT31(CONCAT21(CONCAT11((char)param_1[0x12],
                                             *(undefined1 *)((int)param_1 + 0x49)),
                                    *(undefined1 *)((int)param_1 + 0x4a)),
                           *(undefined1 *)((int)param_1 + 0x4b));
          param_1[0xd] = uVar4;
          if ((uVar4 < 0xc) || (0x8000 < (int)uVar4)) goto LAB_0066e38a;
          piVar6 = _malloc(uVar4 + 1);
          uVar4 = param_1[0xe];
          param_1[0xf] = (int)piVar6;
          piVar8 = param_1 + 0x10;
          for (uVar7 = uVar4 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
            *piVar6 = *piVar8;
            piVar8 = piVar8 + 1;
            piVar6 = piVar6 + 1;
          }
          for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(char *)piVar6 = (char)*piVar8;
            piVar8 = (int *)((int)piVar8 + 1);
            piVar6 = (int *)((int)piVar6 + 1);
          }
          if (((param_1[0xe] == param_1[0xd]) && ((void *)param_1[0xc] != (void *)0x0)) &&
             (param_1[10] == param_1[9])) {
            _free((void *)param_1[0xc]);
            param_1[0xc] = 0;
          }
        }
      }
      if (param_1[0xf] == 0) {
        return;
      }
      iVar2 = param_1[0xe];
      if (param_1[0xd] <= iVar2) {
        return;
      }
      iVar2 = Ordinal_16(*param_1,iVar2 + param_1[0xf],param_1[0xd] - iVar2);
      if ((iVar2 < 0) && (iVar5 = Ordinal_111(), iVar5 != 0x2733)) goto LAB_0066e3ce;
      if (iVar2 != 0) {
        if (0 < iVar2) {
          param_1[0xe] = param_1[0xe] + iVar2;
        }
        if (param_1[0xe] != param_1[0xd]) {
          return;
        }
        if ((void *)param_1[0xc] == (void *)0x0) {
          return;
        }
        if (param_1[10] != param_1[9]) {
          return;
        }
        _free((void *)param_1[0xc]);
        param_1[0xc] = 0;
        return;
      }
    }
    else {
      iVar2 = param_1[10];
      if (iVar2 == param_1[9]) goto LAB_0066e405;
      iVar2 = Ordinal_19(*param_1,iVar2 + param_1[0xc],param_1[9] - iVar2);
      if ((-1 < iVar2) || (iVar5 = Ordinal_111(), iVar5 == 0x2733)) {
        if (0 < iVar2) {
          param_1[10] = param_1[10] + iVar2;
        }
        if (param_1[10] == param_1[9]) {
          _free((void *)param_1[0xc]);
          param_1[0xc] = 0;
        }
        goto LAB_0066e405;
      }
    }
LAB_0066e38a:
    Ordinal_3();
    *param_1 = -1;
  }
  return;
}


// ==== 0x66e590 FUN_0066e590

int FUN_0066e590(int param_1,size_t param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  bool bVar11;
  bool bVar12;
  
  puVar5 = *(undefined4 **)(param_1 + 0x30);
  iVar3 = 0;
  if (puVar5 == (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(size_t *)(param_1 + 0x2c) = param_2;
    pvVar4 = _malloc(param_2);
    *(void **)(param_1 + 0x30) = pvVar4;
    return *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24);
  }
  iVar1 = *(int *)(param_1 + 0x28);
  iVar6 = 0;
  bVar12 = SBORROW4(0,iVar1);
  iVar2 = -iVar1;
  bVar11 = iVar1 == 0;
  if (0 < iVar1) {
    do {
      iVar6 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)((int)puVar5 + iVar3 + 8),
                                         *(undefined1 *)((int)puVar5 + iVar3 + 9)),
                                *(undefined1 *)((int)puVar5 + iVar3 + 10)),
                       *(undefined1 *)((int)puVar5 + iVar3 + 0xb));
      iVar3 = iVar3 + iVar6;
    } while (iVar3 < iVar1);
    bVar12 = SBORROW4(iVar3,iVar1);
    iVar2 = iVar3 - iVar1;
    bVar11 = iVar3 == iVar1;
  }
  if (!bVar11 && bVar12 == iVar2 < 0) {
    iVar3 = iVar3 - iVar6;
  }
  if (0 < iVar3) {
    uVar7 = *(int *)(param_1 + 0x24) - iVar3;
    puVar9 = (undefined4 *)((int)puVar5 + iVar3);
    for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar5 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar5 = puVar5 + 1;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar9;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) - iVar3;
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - iVar3;
  }
  iVar3 = *(int *)(param_1 + 0x24);
  if (*(int *)(param_1 + 0x2c) - iVar3 < (int)param_2) {
    puVar5 = _malloc(iVar3 + param_2 + param_3);
    if (puVar5 == (undefined4 *)0x0) {
      return 0;
    }
    uVar8 = *(uint *)(param_1 + 0x24);
    puVar9 = *(undefined4 **)(param_1 + 0x30);
    puVar10 = puVar5;
    for (uVar7 = uVar8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    _free(*(void **)(param_1 + 0x30));
    iVar3 = *(int *)(param_1 + 0x24);
    *(undefined4 **)(param_1 + 0x30) = puVar5;
    *(size_t *)(param_1 + 0x2c) = iVar3 + param_2 + param_3;
  }
  return *(int *)(param_1 + 0x2c) - iVar3;
}


// ==== 0x66e6a0 FUN_0066e6a0

undefined4
FUN_0066e6a0(int param_1,undefined4 param_2,undefined4 param_3,char *param_4,char *param_5)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  FUN_0066e080(param_1);
  if ((int)param_5 < 0) {
    param_5 = param_4;
    do {
      cVar1 = *param_5;
      param_5 = param_5 + 1;
    } while (cVar1 != '\0');
    param_5 = param_5 + (1 - (int)(param_4 + 1));
  }
  pcVar5 = param_5 + 0xc;
  iVar2 = FUN_0066e590(param_1,pcVar5,0x8000);
  if ((int)pcVar5 <= iVar2) {
    puVar3 = (undefined1 *)(*(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x24));
    if ((char *)0xc < pcVar5) {
      pcVar6 = puVar3 + 0xc;
      for (uVar4 = (uint)param_5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)param_4;
        param_4 = param_4 + 4;
        pcVar6 = pcVar6 + 4;
      }
      for (uVar4 = (uint)param_5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar6 = *param_4;
        param_4 = param_4 + 1;
        pcVar6 = pcVar6 + 1;
      }
    }
    *(int *)(param_1 + 0x24) = (int)(pcVar5 + *(int *)(param_1 + 0x24));
    puVar3[8] = (char)((uint)pcVar5 >> 0x18);
    puVar3[9] = (char)((uint)pcVar5 >> 0x10);
    puVar3[10] = (char)((uint)pcVar5 >> 8);
    *puVar3 = (char)((uint)param_2 >> 0x18);
    puVar3[1] = (char)((uint)param_2 >> 0x10);
    puVar3[2] = (char)((uint)param_2 >> 8);
    puVar3[3] = (char)param_2;
    puVar3[4] = (char)((uint)param_3 >> 0x18);
    puVar3[5] = (char)((uint)param_3 >> 0x10);
    puVar3[0xb] = (char)pcVar5;
    puVar3[6] = (char)((uint)param_3 >> 8);
    puVar3[7] = (char)param_3;
    FUN_0066e080(param_1);
    return 0;
  }
  return 0xffffffff;
}


// ==== 0x66e780 FUN_0066e780

int FUN_0066e780(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  puVar2 = *(undefined1 **)(param_1 + 0x3c);
  if ((puVar2 == (undefined1 *)0x0) ||
     (iVar1 = *(int *)(param_1 + 0x34), *(int *)(param_1 + 0x38) != iVar1)) {
    if ((param_2 != (undefined4 *)0x0) ||
       ((param_3 != (undefined4 *)0x0 || (param_4 != (undefined4 *)0x0)))) {
      FUN_0066e080(param_1);
      puVar2 = *(undefined1 **)(param_1 + 0x3c);
      if ((puVar2 != (undefined1 *)0x0) &&
         (iVar1 = *(int *)(param_1 + 0x34), *(int *)(param_1 + 0x38) == iVar1)) goto LAB_0066e7c7;
    }
    iVar1 = -1;
  }
  else {
LAB_0066e7c7:
    iVar1 = iVar1 + -0xc;
    puVar3 = puVar2 + 0xc;
    if (iVar1 < 1) {
      puVar3 = &DAT_006b9172;
    }
    else {
      puVar3[iVar1] = 0;
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = CONCAT31(CONCAT21(CONCAT11(*puVar2,puVar2[1]),puVar2[2]),puVar2[3]);
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = CONCAT31(CONCAT21(CONCAT11(puVar2[4],puVar2[5]),puVar2[6]),puVar2[7]);
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = puVar3;
      return iVar1;
    }
  }
  return iVar1;
}


// ==== 0x66e840 FUN_0066e840

uint FUN_0066e840(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,uint param_5
                 )

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar1 = FUN_0066e780(param_1,param_2,param_3,0);
  if (-1 < (int)uVar1) {
    if ((int)uVar1 < (int)param_5) {
      param_5 = uVar1;
    }
    if (param_4 != (undefined4 *)0x0) {
      puVar3 = (undefined4 *)(*(int *)(param_1 + 0x3c) + 0xc);
      for (uVar2 = param_5 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *param_4 = *puVar3;
        puVar3 = puVar3 + 1;
        param_4 = param_4 + 1;
      }
      for (param_5 = param_5 & 3; param_5 != 0; param_5 = param_5 - 1) {
        *(undefined1 *)param_4 = *(undefined1 *)puVar3;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
        param_4 = (undefined4 *)((int)param_4 + 1);
      }
    }
    _free(*(void **)(param_1 + 0x3c));
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  return uVar1;
}


// ==== 0x66e8b0 GetTickCount

DWORD GetTickCount(void)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0066e8b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = GetTickCount();
  return DVar1;
}


// ==== 0x66e8c0 FUN_0066e8c0

void FUN_0066e8c0(int param_1,char *param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  if (DAT_00717a70 == 0) {
    DAT_00717a70 = 1;
    FUN_0066e8c0(&DAT_00717968,"hello world",0xffffffff,10);
  }
  if (param_4 < 0) {
    param_4 = -param_4;
  }
  else {
    iVar2 = 0;
    do {
      *(char *)(iVar2 + param_1) = (char)iVar2;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x100);
    *(undefined1 *)(param_1 + 0x100) = 0;
    *(undefined4 *)(param_1 + 0x104) = 0;
  }
  bVar6 = false;
  if (param_3 < 0) {
    param_3 = 0;
    if (*param_2 == '\0') {
      return;
    }
    do {
      param_3 = param_3 + 1;
    } while (param_2[param_3] != '\0');
    bVar6 = param_3 < 0;
  }
  if (param_3 != 0 && !bVar6) {
    uVar5 = 0;
    uVar4 = 0;
    if (0 < param_4 * 0x100) {
      uVar3 = 0;
      do {
        uVar5 = *(uint *)(&DAT_006ab998 + ((byte)param_2[(int)uVar4 % param_3] ^ uVar3) * 4) ^
                uVar5 >> 8;
        bVar1 = *(byte *)((uVar4 & 0xff) + param_1);
        uVar5 = *(uint *)(&DAT_006ab998 + (uVar5 & 0xff ^ (uint)bVar1) * 4) ^ uVar5 >> 8;
        uVar3 = uVar5 & 0xff;
        *(undefined1 *)((uVar4 & 0xff) + param_1) = *(undefined1 *)(uVar3 + param_1);
        uVar4 = uVar4 + 1;
        *(byte *)(uVar3 + param_1) = bVar1;
      } while ((int)uVar4 < param_4 * 0x100);
    }
  }
  return;
}


// ==== 0x66e9c0 FUN_0066e9c0

void FUN_0066e9c0(int param_1,byte *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  
  bVar3 = *(byte *)(param_1 + 0x100);
  uVar5 = *(uint *)(param_1 + 0x104);
  if (param_3 < 1) {
    *(uint *)(param_1 + 0x104) = uVar5;
    *(byte *)(param_1 + 0x100) = bVar3;
    return;
  }
  pbVar6 = (byte *)((uint)bVar3 + param_1);
  uVar4 = uVar5 & 0xff;
  do {
    uVar5 = uVar5 >> 8 ^ *(uint *)(&DAT_006ab998 + (*pbVar6 ^ uVar4) * 4);
    bVar3 = bVar3 + 1;
    pbVar6 = (byte *)((uint)bVar3 + param_1);
    bVar1 = *pbVar6;
    uVar4 = uVar5 & 0xff;
    bVar2 = *(byte *)(uVar4 + param_1);
    *pbVar6 = bVar2;
    *(byte *)(uVar4 + param_1) = bVar1;
    *param_2 = *param_2 ^ *(byte *)(((uint)bVar1 - (uint)bVar2 & 0xff) + param_1);
    param_2 = param_2 + 1;
    param_3 = param_3 + -1;
  } while (param_3 != 0);
  *(uint *)(param_1 + 0x104) = uVar5;
  *(byte *)(param_1 + 0x100) = bVar3;
  return;
}


// ==== 0x66ea80 FUN_0066ea80

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0066ea80(char *param_1,int param_2,byte *param_3,undefined4 param_4,undefined4 param_5,
            int param_6)

{
  byte bVar1;
  int iVar2;
  uint unaff_retaddr;
  byte local_10e;
  byte local_10d;
  undefined1 local_10c [264];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  local_10d = 0;
  FUN_0066e8c0(local_10c,param_4,param_5,param_6);
  FUN_0066e8c0(&DAT_00717968,param_4,param_5,-param_6);
  FUN_0066e8c0(&DAT_00717968,"ru paranoid?",0xffffffff,0xffffffff);
  if (1 < param_2) {
    iVar2 = param_2 + -1;
    param_2 = param_2 - iVar2;
    do {
      if (param_3 == (byte *)0x0) {
        FUN_0066e9c0(&DAT_00717968,&local_10e,1);
        local_10e = (local_10e & 0x3f) + 0x20;
      }
      else {
        local_10e = *param_3;
        param_3 = param_3 + 1;
        if (local_10e == 0) {
          param_3 = (byte *)0x0;
        }
      }
      if ((local_10e < 0x20) || (0x7e < local_10e)) {
        local_10e = 0x7f;
      }
      bVar1 = local_10e;
      FUN_0066e9c0(local_10c,&local_10d,1);
      *param_1 = (char)(((uint)local_10d % 0x60 + 0x40 + (uint)bVar1) % 0x60) + ' ';
      param_1 = param_1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if (0 < param_2) {
    *param_1 = '\0';
  }
  return 0;
}


// ==== 0x66ebc0 FUN_0066ebc0

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0066ebc0(undefined4 param_1,int param_2,int param_3,uint param_4,code *param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uint unaff_retaddr;
  int local_402c;
  int *piStack_4028;
  undefined4 *local_4020;
  int *local_401c [2];
  uint local_4014;
  int *piStack_4010;
  int *piStack_400c;
  int iStack_4008;
  int local_4004 [1024];
  undefined4 local_3004 [1024];
  int local_2004 [1024];
  undefined1 local_1004 [4096];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  if (1 < param_3) {
    if (param_3 < 0x400) {
      piVar5 = local_4004;
      local_401c[0] = local_2004;
      local_401c[1] = (int *)local_1004;
    }
    else {
      iVar1 = param_3 * 4;
      piVar5 = (int *)FUN_00549460(iVar1);
      local_401c[0] = (int *)FUN_00549460(iVar1);
      local_401c[1] = (int *)FUN_00549460(iVar1);
    }
    if ((int)param_4 < 0x1001) {
      local_4020 = local_3004;
    }
    else {
      local_4020 = (undefined4 *)FUN_00549460(param_4);
    }
    *local_401c[0] = param_2;
    *piVar5 = 1;
    piVar8 = piVar5;
    piVar9 = local_401c[0];
    iVar1 = param_2;
    while (iVar1 = iVar1 + param_4, iVar1 != param_3 * param_4 + param_2) {
      iVar6 = (*param_5)(param_1,*piVar9,iVar1);
      if (iVar6 < 1) {
        *piVar8 = *piVar8 + 1;
      }
      else {
        piVar8 = piVar8 + 1;
        *piVar8 = 1;
      }
      piVar9 = piVar9 + 1;
      *piVar9 = iVar1;
    }
    piVar8[1] = 0;
    piVar8[2] = 0;
    local_4014 = 0;
    if (piVar5[1] != 0) {
      do {
        iVar1 = *piVar5;
        piStack_4028 = local_401c[~local_4014 & 1];
        piVar8 = local_401c[local_4014 & 1] + iVar1;
        piStack_400c = piVar8;
        piStack_4010 = piVar5;
        iStack_4008 = piVar5[1];
        piVar9 = local_401c[local_4014 & 1];
        piVar3 = piVar8 + piVar5[1];
        piVar4 = piVar5;
        while (piVar4 = piVar4 + 2, piStack_400c = piVar8, iVar1 != 0) {
          while( true ) {
            while (piVar9 != piStack_400c) {
              if (piVar8 == piVar3) {
                *piStack_4028 = *piVar9;
                piStack_4028 = piStack_4028 + 1;
                piVar9 = piVar9 + 1;
              }
              else {
                iVar6 = (*param_5)(param_1,*piVar9,*piVar8);
                if (iVar6 < 1) {
                  *piStack_4028 = *piVar9;
                  piStack_4028 = piStack_4028 + 1;
                  piVar9 = piVar9 + 1;
                }
                else {
                  *piStack_4028 = *piVar8;
                  piStack_4028 = piStack_4028 + 1;
                  piVar8 = piVar8 + 1;
                }
              }
            }
            if (piVar8 == piVar3) break;
            *piStack_4028 = *piVar8;
            piStack_4028 = piStack_4028 + 1;
            piVar8 = piVar8 + 1;
          }
          *piStack_4010 = iStack_4008 + iVar1;
          iVar1 = *piVar4;
          piVar8 = piVar3 + iVar1;
          piStack_4010 = piStack_4010 + 1;
          iStack_4008 = piVar4[1];
          piStack_400c = piVar8;
          piVar9 = piVar3;
          piVar3 = piVar8 + piVar4[1];
        }
        *piStack_4010 = 0;
        piStack_4010[1] = 0;
        local_4014 = local_4014 + 1;
      } while (piVar5[1] != 0);
      if (local_4014 != 0) {
        piVar8 = local_401c[local_4014 & 1];
        local_402c = 0;
        if (0 < param_3) {
          do {
            if ((undefined4 *)piVar8[local_402c] != (undefined4 *)0x0) {
              puVar10 = (undefined4 *)piVar8[local_402c];
              puVar11 = local_4020;
              for (uVar7 = param_4 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                *puVar11 = *puVar10;
                puVar10 = puVar10 + 1;
                puVar11 = puVar11 + 1;
              }
              for (uVar7 = param_4 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
                puVar10 = (undefined4 *)((int)puVar10 + 1);
                puVar11 = (undefined4 *)((int)puVar11 + 1);
              }
              iVar6 = piVar8[local_402c] - param_2;
              iVar1 = local_402c;
              while (iVar2 = iVar6 / (int)param_4, iVar2 != local_402c) {
                puVar10 = (undefined4 *)piVar8[iVar2];
                puVar11 = (undefined4 *)piVar8[iVar1];
                for (uVar7 = param_4 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                  *puVar11 = *puVar10;
                  puVar10 = puVar10 + 1;
                  puVar11 = puVar11 + 1;
                }
                for (uVar7 = param_4 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                  *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
                  puVar10 = (undefined4 *)((int)puVar10 + 1);
                  puVar11 = (undefined4 *)((int)puVar11 + 1);
                }
                piVar8[iVar1] = 0;
                iVar1 = iVar2;
                iVar6 = piVar8[iVar2] - param_2;
              }
              puVar10 = local_4020;
              puVar11 = (undefined4 *)piVar8[iVar1];
              for (uVar7 = param_4 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                *puVar11 = *puVar10;
                puVar10 = puVar10 + 1;
                puVar11 = puVar11 + 1;
              }
              for (uVar7 = param_4 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
                puVar10 = (undefined4 *)((int)puVar10 + 1);
                puVar11 = (undefined4 *)((int)puVar11 + 1);
              }
              piVar8[iVar1] = 0;
            }
            local_402c = local_402c + 1;
          } while (local_402c < param_3);
        }
      }
    }
    if (piVar5 != local_4004) {
      FUN_00447030(piVar5);
      FUN_00447030(local_401c[0]);
      FUN_00447030(local_401c[1]);
    }
    if (local_4020 != local_3004) {
      FUN_00447030(local_4020);
    }
  }
  return;
}


// ==== 0x66ef60 FUN_0066ef60

void FUN_0066ef60(void)

{
  FID_conflict___time32((__time32_t *)0x0);
  return;
}


// ==== 0x66ef70 FUN_0066ef70

void FUN_0066ef70(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int in_EAX;
  undefined4 *puVar3;
  int unaff_ESI;
  
  puVar3 = (undefined4 *)FUN_00549460(in_EAX + 0x18);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = 0;
    puVar3[2] = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(unaff_ESI + 0xc),
                                           *(undefined1 *)(unaff_ESI + 0xd)),
                                  *(undefined1 *)(unaff_ESI + 0xe)),*(undefined1 *)(unaff_ESI + 0xf)
                        );
    puVar3[3] = 0;
    uVar1 = *(undefined1 *)(unaff_ESI + 0x1a);
    uVar2 = *(undefined1 *)(unaff_ESI + 0x1b);
    puVar3[4] = 0;
    *(undefined1 *)((int)puVar3 + 0x15) = 0xb;
    puVar3[1] = (uint)CONCAT11(uVar1,uVar2);
  }
  return;
}


// ==== 0x66efc0 FUN_0066efc0

undefined4 * __fastcall FUN_0066efc0(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int in_EAX;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  uVar5 = in_EAX - 0x24;
  if ((((int)uVar5 < 0) || (0x400 < uVar5)) || (*(int *)(param_2 + 0x1c) != 0x67535073)) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_00549460(in_EAX + -0xc);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0;
      puVar3[2] = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0xc),
                                             *(undefined1 *)(param_2 + 0xd)),
                                    *(undefined1 *)(param_2 + 0xe)),*(undefined1 *)(param_2 + 0xf));
      puVar3[3] = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 8),
                                             *(undefined1 *)(param_1 + 9)),
                                    *(undefined1 *)(param_1 + 10)),*(undefined1 *)(param_1 + 0xb)) -
                  *(int *)(param_2 + 0x20);
      uVar1 = *(undefined1 *)(param_2 + 0x1a);
      uVar2 = *(undefined1 *)(param_2 + 0x1b);
      puVar3[4] = uVar5;
      *(undefined1 *)((int)puVar3 + 0x15) = 0;
      puVar3[1] = (uint)CONCAT11(uVar1,uVar2);
      puVar6 = (undefined4 *)(param_2 + 0x24);
      puVar7 = puVar3 + 5;
      for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      if (puVar3[3] == 0) {
        puVar3[3] = 1;
        return puVar3;
      }
    }
  }
  return puVar3;
}


// ==== 0x66f090 FUN_0066f090

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0066f090(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint unaff_retaddr;
  int local_43c;
  undefined1 local_438 [16];
  undefined1 local_428 [20];
  char local_414;
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  local_43c = 0x10;
  local_43c = FUN_00662f00(*param_3,local_428,0x424,0,local_438,&local_43c);
  do {
    if (local_43c < 1) {
      return 0;
    }
    if (0 < (int)param_3[0xd]) {
      if (local_414 == '\0') {
        iVar4 = FUN_0066efc0();
      }
      else {
        if (local_414 != '\v') goto LAB_0066f151;
        iVar4 = FUN_0066ef70(local_438);
      }
      if (iVar4 != 0) {
        FUN_00668d60(param_3 + 3);
        piVar3 = (int *)param_3[0xc];
        piVar2 = param_3 + 0xc;
        while (piVar1 = piVar3, piVar1 != (int *)0x0) {
          piVar2 = piVar1;
          piVar3 = (int *)*piVar1;
        }
        *piVar2 = iVar4;
        param_3[0xd] = param_3[0xd] + -1;
        FUN_00668df0(param_3 + 3);
      }
    }
LAB_0066f151:
    local_43c = 0x10;
    local_43c = FUN_00662f00(*param_3,local_428,0x424,0,local_438,&local_43c);
  } while( true );
}


// ==== 0x66f1b0 FUN_0066f1b0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_0066f1b0(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint unaff_retaddr;
  undefined2 local_14;
  undefined2 local_12;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  iVar1 = FUN_00662c30(2,3,1);
  if (iVar1 == 0) {
    return (int *)0x0;
  }
  local_14 = 2;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_12 = 0x100;
  FUN_00662d70(iVar1,&local_14,0x10);
  piVar2 = (int *)FUN_00549460(0x3c);
  if (piVar2 != (int *)0x0) {
    piVar4 = piVar2;
    for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar4 = 0;
      piVar4 = piVar4 + 1;
    }
    *piVar2 = iVar1;
    piVar2[1] = 1;
    piVar2[0xd] = 8;
    piVar2[0xe] = 0x40;
    FUN_00668cc0(piVar2 + 3);
    FUN_00663160(*piVar2,2,5000,piVar2,FUN_0066f090);
    return piVar2;
  }
  return (int *)0x0;
}


// ==== 0x66f2a0 FUN_0066f2a0

void FUN_0066f2a0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    FUN_00662ce0(*param_1);
    iVar1 = param_1[0xc];
    while (iVar1 != 0) {
      puVar2 = (undefined4 *)param_1[0xc];
      param_1[0xc] = *puVar2;
      FUN_00447030(puVar2);
      iVar1 = param_1[0xc];
    }
    FUN_00668cf0(param_1 + 3);
    FUN_00447030(param_1);
  }
  return;
}


// ==== 0x66f2f0 FUN_0066f2f0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0066f2f0(undefined4 *param_1,undefined4 param_2,char *param_3,char *param_4)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  char *pcVar11;
  uint unaff_retaddr;
  int local_44c;
  undefined2 local_448;
  undefined2 local_446;
  undefined3 local_444;
  undefined1 uStack_441;
  undefined4 local_440;
  undefined4 local_43c;
  undefined4 local_438 [2];
  undefined1 local_430;
  undefined1 local_42f;
  undefined1 local_428;
  undefined1 local_427;
  undefined1 local_426;
  undefined1 local_425;
  byte local_424 [12];
  DWORD local_418;
  char local_414 [1032];
  uint local_c;
  
  local_c = DAT_006eb720 ^ unaff_retaddr;
  if (param_1 != (undefined4 *)0x0) {
    if ((int)param_4 < 0) {
      param_4 = param_3;
      do {
        cVar1 = *param_4;
        param_4 = param_4 + 1;
      } while (cVar1 != '\0');
      param_4 = param_4 + (1 - (int)(param_3 + 1));
    }
    uVar2 = (undefined1)((uint)param_2 >> 8);
    uVar3 = (undefined1)((uint)param_2 >> 0x10);
    uVar4 = (undefined1)((uint)param_2 >> 0x18);
    puVar10 = local_438;
    for (iVar6 = 0x109; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    local_446 = 0;
    local_440 = 0;
    local_43c = 0;
    iVar6 = param_1[1];
    local_430 = *(undefined1 *)(param_1 + 0xe);
    param_1[1] = iVar6 + 1;
    local_424[5] = *(byte *)(param_1 + 1);
    local_424[4] = (byte)((uint)(iVar6 + 1) >> 8);
    local_448 = 2;
    local_425 = (undefined1)param_2;
    _local_444 = CONCAT13(local_425,CONCAT21(CONCAT11(uVar2,uVar3),uVar4));
    local_438[0]._0_1_ = 0x45;
    local_42f = 1;
    local_424[0] = 8;
    if ((char *)0x400 < param_4) {
      param_4 = (char *)0x400;
    }
    pcVar11 = local_414;
    for (uVar7 = (uint)param_4 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)param_3;
      param_3 = param_3 + 4;
      pcVar11 = pcVar11 + 4;
    }
    for (uVar7 = (uint)param_4 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar11 = *param_3;
      param_3 = param_3 + 1;
      pcVar11 = pcVar11 + 1;
    }
    uVar9 = (uint)(param_4 + 3) & 0x7ffc;
    local_424[8] = 0x73;
    local_424[9] = 0x50;
    local_424[10] = 0x53;
    local_424[0xb] = 0x67;
    local_428 = uVar4;
    local_427 = uVar3;
    local_426 = uVar2;
    local_424[6] = local_424[4];
    local_424[7] = local_424[5];
    local_418 = GetTickCount();
    uVar7 = uVar9 + 0x10;
    uVar8 = 0;
    pbVar5 = local_424;
    if (1 < uVar7) {
      local_44c = (uVar9 + 0xe >> 1) + 1;
      uVar7 = uVar7 + local_44c * -2;
      do {
        uVar8 = uVar8 + (uint)*pbVar5 * 0x100 + (uint)pbVar5[1];
        pbVar5 = pbVar5 + 2;
        local_44c = local_44c + -1;
      } while (local_44c != 0);
    }
    if (0 < (int)uVar7) {
      uVar8 = uVar8 + (uint)*pbVar5 * 0x100;
    }
    uVar7 = (uVar8 >> 0x10) + (uVar8 & 0xffff);
    uVar7 = ~((uVar7 >> 0x10) + (uVar7 & 0xffff));
    local_424[3] = (byte)uVar7;
    local_424[2] = (byte)(uVar7 >> 8);
    iVar6 = FUN_00662e80(*param_1,local_438,uVar9 + 0x24,0,&local_448,0x10);
    if (-1 < iVar6) {
      return param_1[1];
    }
  }
  return 0xffffffff;
}


// ==== 0x66f4d0 FUN_0066f4d0

undefined4 FUN_0066f4d0(undefined4 *param_1,undefined4 *param_2,uint *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  uVar5 = 0;
  FUN_0066f090(*param_1,0,param_1);
  puVar1 = (undefined4 *)param_1[0xc];
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00668d60(param_1 + 3);
    uVar5 = puVar1[3];
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = uVar5;
      param_4[1] = puVar1[2];
      param_4[3] = (uint)*(byte *)((int)puVar1 + 0x15);
      iVar2 = puVar1[1];
      if (iVar2 == 0) {
        iVar2 = 1;
      }
      param_4[2] = iVar2;
    }
    if (param_3 != (uint *)0x0) {
      if ((int)puVar1[4] < (int)*param_3) {
        *param_3 = puVar1[4];
      }
      if (param_2 != (undefined4 *)0x0) {
        uVar4 = *param_3;
        puVar6 = puVar1 + 5;
        for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *param_2 = *puVar6;
          puVar6 = puVar6 + 1;
          param_2 = param_2 + 1;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)param_2 = *(undefined1 *)puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          param_2 = (undefined4 *)((int)param_2 + 1);
        }
      }
    }
    param_1[0xc] = *puVar1;
    FUN_00447030(puVar1);
    param_1[0xd] = param_1[0xd] + 1;
    FUN_00668df0(param_1 + 3);
  }
  return uVar5;
}


// ==== 0x66f590 FUN_0066f590

void FUN_0066f590(void)

{
  DWORD DVar1;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0xe4) = 0;
  *(undefined4 *)(unaff_ESI + 0xe8) = 0;
  *(undefined4 *)(unaff_ESI + 0xec) = 0;
  *(undefined4 *)(unaff_ESI + 0xf4) = 0x65;
  *(undefined4 *)(unaff_ESI + 0xcc) = 0;
  *(undefined4 *)(unaff_ESI + 0xd0) = 0;
  *(undefined4 *)(unaff_ESI + 0xd8) = 0x65;
  DVar1 = GetTickCount();
  *(DWORD *)(unaff_ESI + 0x1908) = DVar1 - 5000;
  return;
}


// ==== 0x66f5e0 FUN_0066f5e0

int __fastcall FUN_0066f5e0(byte *param_1,int param_2)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = 0;
  if (0 < param_2) {
    do {
      unaff_ESI = CONCAT22((short)((uint)unaff_ESI >> 0x10),(ushort)*param_1);
      iVar1 = iVar1 * 0xd + unaff_ESI;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return iVar1;
}


// ==== 0x66f600 FUN_0066f600

undefined4 FUN_0066f600(int param_1,uint *param_2)

{
  LPOVERLAPPED lpOverlapped;
  HANDLE hFile;
  bool bVar1;
  short sVar2;
  BOOL BVar3;
  DWORD DVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  
  uVar6 = *(uint *)(param_1 + 0x8f8);
  puVar11 = (uint *)(param_1 + 0xf8);
LAB_0066f61f:
  do {
    bVar1 = false;
LAB_0066f621:
    if ((bVar1) || ((int)uVar6 < 8)) {
      hFile = *(HANDLE *)(param_1 + 0x6c);
      lpOverlapped = (LPOVERLAPPED)(param_1 + 0x70);
      lpOverlapped->Internal = 0;
      *(undefined4 *)(param_1 + 0x74) = 0;
      *(undefined4 *)(param_1 + 0x78) = 0;
      *(undefined4 *)(param_1 + 0x7c) = 0;
      BVar3 = ReadFile(hFile,(char *)((int)puVar11 + uVar6),0x800 - uVar6,(LPDWORD)(param_1 + 0xac),
                       lpOverlapped);
      if ((BVar3 == 0) && (DVar4 = GetLastError(), DVar4 == 0x3e5)) {
        GetOverlappedResult(*(HANDLE *)(param_1 + 0x6c),lpOverlapped,(LPDWORD)(param_1 + 0xac),1);
      }
      if (*(int *)(param_1 + 0xac) != 0) {
        uVar6 = uVar6 + *(int *)(param_1 + 0xac);
        goto LAB_0066f61f;
      }
      DVar4 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x94),0);
      if (DVar4 == 0x102) {
LAB_0066f81f:
        *(uint *)(param_1 + 0x8f8) = uVar6;
        return 0;
      }
      lpOverlapped->Internal = 0;
      *(undefined4 *)(param_1 + 0x74) = 0;
      *(undefined4 *)(param_1 + 0x78) = 0;
      *(undefined4 *)(param_1 + 0x7c) = 0;
      BVar3 = WaitCommEvent(*(HANDLE *)(param_1 + 0x6c),(LPDWORD)(param_1 + 0xb0),
                            (LPOVERLAPPED)(param_1 + 0x84));
      if ((BVar3 == 0) && (DVar4 = GetLastError(), DVar4 == 0x3e5)) goto LAB_0066f81f;
      bVar1 = true;
      goto LAB_0066f621;
    }
    puVar7 = puVar11;
    if (((*(char *)puVar11 != 'G') || (*(char *)(param_1 + 0xf9) != 'S')) ||
       (*(byte *)(param_1 + 0xfa) != (byte)~*(byte *)(param_1 + 0xfb))) {
      do {
        puVar10 = puVar7;
        uVar6 = uVar6 - 1;
        if ((int)uVar6 < 1) goto LAB_0066f621;
        puVar7 = (uint *)((int)puVar10 + 1);
      } while (((*(char *)puVar7 != 'G') ||
               ((1 < (int)uVar6 && (*(char *)((int)puVar10 + 2) != 'S')))) ||
              ((3 < (int)uVar6 && (*(byte *)((int)puVar10 + 3) != (byte)~(byte)puVar10[1]))));
      if (0 < (int)uVar6) {
        puVar10 = puVar11;
        for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar10 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar10 = puVar10 + 1;
        }
        for (uVar8 = uVar6 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *(char *)puVar10 = (char)*puVar7;
          puVar7 = (uint *)((int)puVar7 + 1);
          puVar10 = (uint *)((int)puVar10 + 1);
        }
      }
      goto LAB_0066f621;
    }
    uVar8 = (uint)*(byte *)(param_1 + 0xfa);
    uVar9 = uVar8 + 8;
    if ((int)uVar6 < (int)(uVar8 + 0x10)) {
      bVar1 = true;
      goto LAB_0066f621;
    }
    if (((*(char *)(uVar8 + 0xe + (int)puVar11) == '\r') &&
        (*(char *)(uVar8 + 0xf + (int)puVar11) == '\n')) &&
       (sVar2 = FUN_0066f5e0(),
       sVar2 == CONCAT11(*(char *)(uVar8 + 0xd + (int)puVar11),*(char *)(uVar8 + 0xc + (int)puVar11)
                        ))) {
      puVar10 = param_2 + 2;
      for (uVar5 = uVar9 >> 2; puVar7 = puVar7 + 1, uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar10 = *puVar7;
        puVar10 = puVar10 + 1;
      }
      for (uVar5 = uVar9 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(char *)puVar10 = (char)*puVar7;
        puVar7 = (uint *)((int)puVar7 + 1);
        puVar10 = (uint *)((int)puVar10 + 1);
      }
      *param_2 = uVar8;
      DVar4 = GetTickCount();
      uVar6 = (uVar6 - uVar9) - 8;
      param_2[1] = DVar4;
      *(uint *)(param_1 + 0x8f8) = uVar6;
      if (uVar6 != 0) {
        puVar7 = (uint *)(uVar8 + 0x10 + (int)puVar11);
        for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
          *puVar11 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar11 = puVar11 + 1;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(char *)puVar11 = (char)*puVar7;
          puVar7 = (uint *)((int)puVar7 + 1);
          puVar11 = (uint *)((int)puVar11 + 1);
        }
      }
      return 1;
    }
    *(char *)puVar11 = '\0';
  } while( true );
}


// ==== 0x66f830 FUN_0066f830

undefined4 __fastcall FUN_0066f830(undefined4 param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  undefined2 uVar3;
  DWORD DVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  if (param_2 != (byte *)0x0) {
    iVar2 = *(int *)param_2;
    if (*(int *)(param_3 + 0x18fc) - *(int *)(param_3 + 0x1900) < iVar2 + 0x10) {
      return 0xffffffff;
    }
    pbVar1 = (byte *)(*(int *)(param_3 + 0x1904) * 0x800 + *(int *)(param_3 + 0x1900) + 0x8fc +
                     param_3);
    *pbVar1 = 0x47;
    pbVar1[1] = 0x53;
    pbVar1[2] = *param_2;
    pbVar1[3] = ~*param_2;
    pbVar6 = param_2 + 8;
    pbVar7 = pbVar1;
    for (uVar5 = iVar2 + 8U >> 2; pbVar7 = pbVar7 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pbVar7 = *(undefined4 *)pbVar6;
      pbVar6 = pbVar6 + 4;
    }
    for (uVar5 = iVar2 + 8U & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pbVar7 = *pbVar6;
      pbVar6 = pbVar6 + 1;
      pbVar7 = pbVar7 + 1;
    }
    uVar3 = FUN_0066f5e0();
    pbVar1[iVar2 + 0xc] = (byte)uVar3;
    pbVar1[iVar2 + 0xd] = (byte)((ushort)uVar3 >> 8);
    pbVar1[iVar2 + 0xe] = 0xd;
    pbVar1[iVar2 + 0xf] = 10;
    if (*(int *)(param_3 + 0x1900) == 0) {
      SetCommMask(*(HANDLE *)(param_3 + 0x6c),2);
    }
    *(int *)(param_3 + 0x1900) = *(int *)(param_3 + 0x1900) + iVar2 + 0x10;
    DVar4 = GetTickCount();
    *(DWORD *)(param_3 + 0x1908) = DVar4;
  }
  if ((*(int *)(param_3 + 0x1900) != 0) &&
     (DVar4 = WaitForSingleObject(*(HANDLE *)(param_3 + 0xa8),0), DVar4 != 0x102)) {
    WriteFile(*(HANDLE *)(param_3 + 0x6c),
              (LPCVOID)(*(int *)(param_3 + 0x1904) * 0x800 + 0x8fc + param_3),
              *(DWORD *)(param_3 + 0x1900),(LPDWORD)(param_3 + 0xb4),(LPOVERLAPPED)(param_3 + 0x98))
    ;
    *(uint *)(param_3 + 0x1904) = *(uint *)(param_3 + 0x1904) ^ 1;
    *(undefined4 *)(param_3 + 0x1900) = 0;
  }
  return 0;
}


// ==== 0x66f960 FUN_0066f960

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0066f960(void)

{
  int unaff_ESI;
  
  if ((*(int *)(unaff_ESI + 0xbc) != 1) && (*(int *)(unaff_ESI + 0xbc) != 7)) {
    FUN_0066f830();
    *(undefined4 *)(unaff_ESI + 0xc0) = 0;
    *(undefined4 *)(unaff_ESI + 0xbc) = 7;
  }
  return 0;
}


// ==== 0x66f9e0 FUN_0066f9e0

void __fastcall FUN_0066f9e0(int param_1,int *param_2)

{
  int iVar1;
  int iStack00000004;
  
  if ((*param_2 == 0) && (param_2[3] == *(int *)(param_1 + 0xc0))) {
    iVar1 = param_2[2];
    if (iVar1 == 1) {
      param_2[2] = 2;
      iStack00000004 = param_1;
      FUN_0066f830();
      return;
    }
    if (iVar1 == 2) {
      if (*(int *)(param_1 + 0xbc) == 2) {
        *(undefined4 *)(param_1 + 0xbc) = 4;
        return;
      }
    }
    else if ((iVar1 == 3) && (*(int *)(param_1 + 0xbc) == 4)) {
      *(undefined4 *)(param_1 + 0xbc) = 7;
    }
  }
  return;
}


// ==== 0x66fa40 FUN_0066fa40

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0066fa40(void)

{
  DWORD DVar1;
  uint uVar2;
  uint unaff_ESI;
  
  uVar2 = *(uint *)(unaff_ESI + 0xc0);
  while (uVar2 == 0) {
    DVar1 = GetTickCount();
    uVar2 = DVar1 ^ unaff_ESI;
    *(uint *)(unaff_ESI + 0xc0) = uVar2;
  }
  FUN_0066f830();
  return;
}


// ==== 0x66fac0 FUN_0066fac0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0066fac0(undefined4 param_1)

{
  FUN_0066f830(param_1,0);
  return;
}


// ==== 0x66fb20 FUN_0066fb20

void FUN_0066fb20(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  int *piVar3;
  
  iVar1 = *(int *)(unaff_ESI + 0xe8);
  iVar2 = 0x800;
  if (iVar1 != *(int *)(unaff_ESI + 0xec)) {
    do {
      iVar2 = iVar2 - *(int *)(*(int *)(unaff_ESI + 0xf0) + iVar1);
      iVar1 = (*(int *)(unaff_ESI + 0xdc) + iVar1) % *(int *)(unaff_ESI + 0xe0);
    } while (iVar1 != *(int *)(unaff_ESI + 0xec));
  }
  if (*(int *)(unaff_ESI + 0xec) != *(int *)(unaff_ESI + 0xe4)) {
    while ((piVar3 = (int *)(*(int *)(unaff_ESI + 0xf0) + *(int *)(unaff_ESI + 0xec)),
           *(int *)(unaff_ESI + 0xec) == *(int *)(unaff_ESI + 0xe8) || (*piVar3 <= iVar2))) {
      iVar2 = iVar2 - *piVar3;
      piVar3[3] = *(int *)(unaff_ESI + 0xd8) + -1;
      if (*(code **)(unaff_ESI + 0x38) != (code *)0x0) {
        (**(code **)(unaff_ESI + 0x38))();
      }
      iVar1 = FUN_0066f830();
      if (iVar1 < 0) {
        return;
      }
      iVar1 = (*(int *)(unaff_ESI + 0xdc) + *(int *)(unaff_ESI + 0xec)) % *(int *)(unaff_ESI + 0xe0)
      ;
      *(int *)(unaff_ESI + 0xec) = iVar1;
      if (iVar1 == *(int *)(unaff_ESI + 0xe4)) {
        return;
      }
    }
  }
  return;
}


// ==== 0x66fbf0 FUN_0066fbf0

void __fastcall FUN_0066fbf0(int param_1)

{
  int in_EAX;
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  bVar3 = *(int *)(in_EAX + 8) == 4;
  uVar2 = *(uint *)(in_EAX + 0xc);
  if (bVar3) {
    uVar2 = uVar2 - 1;
  }
  if (*(int *)(param_1 + 0xe8) != *(int *)(param_1 + 0xe4)) {
    do {
      iVar1 = *(int *)(param_1 + 0xe8);
      if (uVar2 < *(uint *)(*(int *)(param_1 + 0xf0) + 8 + iVar1)) break;
      if (*(int *)(param_1 + 0xec) == iVar1) {
        *(int *)(param_1 + 0xec) =
             (*(int *)(param_1 + 0xdc) + *(int *)(param_1 + 0xec)) % *(int *)(param_1 + 0xe0);
      }
      iVar1 = (*(int *)(param_1 + 0xdc) + iVar1) % *(int *)(param_1 + 0xe0);
      *(int *)(param_1 + 0xe8) = iVar1;
    } while (iVar1 != *(int *)(param_1 + 0xe4));
  }
  if (bVar3) {
    *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 0xe8);
    FUN_0066fb20();
  }
  return;
}


// ==== 0x66fc90 FUN_0066fc90

uint FUN_0066fc90(void)

{
  int iVar1;
  int *in_EAX;
  uint uVar2;
  uint uVar3;
  int unaff_EBX;
  int *piVar4;
  
  uVar3 = *(uint *)(unaff_EBX + 0xc4);
  iVar1 = uVar3 + *(int *)(unaff_EBX + 0xcc);
  uVar2 = iVar1 / *(int *)(unaff_EBX + 200);
  if (iVar1 % *(int *)(unaff_EBX + 200) != *(int *)(unaff_EBX + 0xd0)) {
    uVar2 = in_EAX[2];
    if (*(uint *)(unaff_EBX + 0xd8) <= uVar2) {
      if (*(uint *)(unaff_EBX + 0xd8) < uVar2) {
        in_EAX[2] = 4;
        in_EAX[3] = *(int *)(unaff_EBX + 0xd8);
        *in_EAX = 0;
        uVar3 = FUN_0066f830();
        return uVar3;
      }
      if (*in_EAX != 0) {
        piVar4 = (int *)(*(int *)(unaff_EBX + 0xd4) + *(int *)(unaff_EBX + 0xcc));
        for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *piVar4 = *in_EAX;
          in_EAX = in_EAX + 1;
          piVar4 = piVar4 + 1;
        }
        for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(char *)piVar4 = (char)*in_EAX;
          in_EAX = (int *)((int)in_EAX + 1);
          piVar4 = (int *)((int)piVar4 + 1);
        }
        *(int *)(unaff_EBX + 0x1928) = *(int *)(unaff_EBX + 0x1928) + 1;
        *(int *)(unaff_EBX + 0xcc) =
             (*(int *)(unaff_EBX + 0xc4) + *(int *)(unaff_EBX + 0xcc)) % *(int *)(unaff_EBX + 200);
        *(int *)(unaff_EBX + 0xd8) = *(int *)(unaff_EBX + 0xd8) + 1;
        if (*(code **)(unaff_EBX + 0x3c) != (code *)0x0) {
          (**(code **)(unaff_EBX + 0x3c))();
        }
        uVar2 = *(int *)(unaff_EBX + 0x1928) - 1;
        *(uint *)(unaff_EBX + 0x1928) = uVar2;
        *(uint *)(unaff_EBX + 0x192c) = *(uint *)(unaff_EBX + 0x192c) | 1;
      }
    }
  }
  return uVar2;
}


// ==== 0x66fd80 FUN_0066fd80

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0066fd80(int param_1)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  uint unaff_retaddr;
  DWORD DVar4;
  HANDLE pvStack_81c;
  undefined4 uStack_818;
  int aiStack_814 [2];
  int iStack_80c;
  int iStack_808;
  uint uStack_4;
  
  uStack_4 = DAT_006eb720 ^ unaff_retaddr;
  iVar3 = *(int *)(param_1 + 0xbc);
  do {
    if (iVar3 == 9) {
      *(undefined4 *)(param_1 + 0xbc) = 1;
      return 0;
    }
    iVar3 = *(int *)(param_1 + 0xbc);
    if (iVar3 == 8) {
      *(undefined4 *)(param_1 + 0xbc) = 1;
      goto LAB_0066fdc5;
    }
    if ((iVar3 == 1) || (iVar3 == 0)) {
LAB_0067007c:
      if (iVar3 == 7) {
LAB_00670085:
        if (*(int *)(param_1 + 0x1900) < 1) goto LAB_0066fdc5;
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1910));
        FUN_0066f830(param_1);
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1910));
        DVar4 = 0x19;
      }
      else {
LAB_0066fdc5:
        DVar4 = 0x32;
      }
      Sleep(DVar4);
    }
    else {
      if (iVar3 == 7) goto LAB_00670085;
      if (iVar3 == 5) goto LAB_0067007c;
      DVar4 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x94),0);
      if (DVar4 == 0x102) {
        pvStack_81c = *(HANDLE *)(param_1 + 0x94);
        DVar4 = 1;
        if ((0 < *(int *)(param_1 + 0x1900)) &&
           (DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xa8),0), DVar1 == 0x102)) {
          uStack_818 = *(undefined4 *)(param_1 + 0xa8);
          DVar4 = 2;
        }
        WaitForMultipleObjects(DVar4,&pvStack_81c,0,100);
      }
      aiStack_814[0] = -1;
      FUN_0066f600(param_1,aiStack_814);
      DVar4 = GetTickCount();
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1910));
      FUN_0066f830(param_1);
      if ((*(int *)(param_1 + 0xbc) == 4) && (45000 < DVar4 - *(int *)(param_1 + 0x190c))) {
        *(undefined4 *)(param_1 + 0xbc) = 6;
LAB_0066feea:
        FUN_0066f960();
      }
      else if (*(int *)(param_1 + 0xbc) == 6) goto LAB_0066feea;
      if ((*(int *)(param_1 + 0xbc) == 4) && (*(int *)(param_1 + 0xec) != *(int *)(param_1 + 0xe4)))
      {
        FUN_0066fb20();
        DVar4 = GetTickCount();
      }
      if ((*(int *)(param_1 + 0xbc) == 2) && (1000 < DVar4 - *(int *)(param_1 + 0x1908))) {
        FUN_0066fa40();
        DVar4 = GetTickCount();
      }
      if (((*(int *)(param_1 + 0xbc) == 4) && (*(int *)(param_1 + 0xec) == *(int *)(param_1 + 0xe4))
          ) && (1000 < DVar4 - *(int *)(param_1 + 0x1908))) {
        FUN_0066fac0(param_1);
        GetTickCount();
      }
      iVar3 = iStack_80c;
      iVar2 = aiStack_814[0];
      if ((-1 < aiStack_814[0]) &&
         ((*(int *)(param_1 + 0xbc) == 4 || (*(int *)(param_1 + 0xbc) == 2)))) {
        if (iStack_80c == 4) {
          FUN_0066fbf0();
        }
        else if (((iStack_80c == 1) || (iStack_80c == 2)) || (iStack_80c == 3)) {
          FUN_0066f9e0(*(undefined4 *)(param_1 + 0xb8));
          iVar3 = iStack_80c;
        }
        else {
          FUN_0066fbf0();
          FUN_0066fc90(*(undefined4 *)(param_1 + 0xb8));
          iVar3 = iStack_80c;
        }
        aiStack_814[0] = -1;
        DVar4 = GetTickCount();
        *(DWORD *)(param_1 + 0x190c) = DVar4;
        iVar2 = -1;
      }
      if ((((*(int *)(param_1 + 0xbc) == 3) && (iVar2 == 0)) && (iStack_808 != 0)) && (iVar3 == 1))
      {
        *(int *)(param_1 + 0xc0) = iStack_808;
        *(undefined4 *)(param_1 + 0xbc) = 4;
        FUN_0066f9e0(*(undefined4 *)(param_1 + 0xb8));
        aiStack_814[0] = -1;
        DVar4 = GetTickCount();
        *(DWORD *)(param_1 + 0x190c) = DVar4;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1910));
      if (*(int *)(param_1 + 0x192c) != 0) {
        if (*(code **)(param_1 + 0x1930) != (code *)0x0) {
          (**(code **)(param_1 + 0x1930))(param_1,*(int *)(param_1 + 0x192c));
        }
        *(undefined4 *)(param_1 + 0x192c) = 0;
      }
    }
    iVar3 = *(int *)(param_1 + 0xbc);
  } while( true );
}


// ==== 0x670000 FUN_00670000

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00670000(void)

{
  DWORD DVar1;
  DWORD DVar2;
  int iVar3;
  LPCRITICAL_SECTION unaff_EBP;
  int unaff_ESI;
  int iVar4;
  int unaff_EDI;
  HANDLE in_stack_00000010;
  undefined4 in_stack_00000014;
  int in_stack_00000018;
  int in_stack_00000020;
  int in_stack_00000024;
  
  iVar4 = unaff_ESI + 1;
  do {
    if ((in_stack_00000024 != 0) && (unaff_EDI == 1)) {
      *(int *)(unaff_ESI + 0xc1) = in_stack_00000024;
      *(undefined4 *)(unaff_ESI + 0xbd) = 4;
      FUN_0066f9e0(*(undefined4 *)(unaff_ESI + 0xb9));
      in_stack_00000018 = -1;
      DVar2 = GetTickCount();
      *(DWORD *)(unaff_ESI + 0x190d) = DVar2;
    }
    do {
      LeaveCriticalSection(unaff_EBP);
      if (*(int *)(unaff_ESI + 0x192d) != 0) {
        if (*(code **)(unaff_ESI + 0x1931) != (code *)0x0) {
          (**(code **)(unaff_ESI + 0x1931))(iVar4,*(int *)(unaff_ESI + 0x192d));
        }
        *(undefined4 *)(unaff_ESI + 0x192d) = 0;
      }
LAB_0066fdcd:
      if (*(int *)(unaff_ESI + 0xbd) == 9) {
        *(undefined4 *)(unaff_ESI + 0xbd) = 1;
        return 0;
      }
      iVar3 = *(int *)(unaff_ESI + 0xbd);
      if (iVar3 == 8) {
        *(undefined4 *)(unaff_ESI + 0xbd) = 1;
LAB_0066fdc5:
        DVar2 = 0x32;
        goto LAB_0066fdc7;
      }
      if ((iVar3 == 1) || (iVar3 == 0)) {
LAB_0067007c:
        if (iVar3 != 7) goto LAB_0066fdc5;
LAB_00670085:
        if (*(int *)(unaff_ESI + 0x1901) < 1) goto LAB_0066fdc5;
        EnterCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x1911));
        FUN_0066f830(iVar4);
        LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x1911));
        DVar2 = 0x19;
LAB_0066fdc7:
        Sleep(DVar2);
        goto LAB_0066fdcd;
      }
      if (iVar3 == 7) goto LAB_00670085;
      if (iVar3 == 5) goto LAB_0067007c;
      DVar2 = WaitForSingleObject(*(HANDLE *)(unaff_ESI + 0x95),0);
      if (DVar2 == 0x102) {
        in_stack_00000010 = *(HANDLE *)(unaff_ESI + 0x95);
        DVar2 = 1;
        if ((0 < *(int *)(unaff_ESI + 0x1901)) &&
           (DVar1 = WaitForSingleObject(*(HANDLE *)(unaff_ESI + 0xa9),0), DVar1 == 0x102)) {
          in_stack_00000014 = *(undefined4 *)(unaff_ESI + 0xa9);
          DVar2 = 2;
        }
        WaitForMultipleObjects(DVar2,&stack0x00000010,0,100);
      }
      in_stack_00000018 = -1;
      FUN_0066f600(iVar4,&stack0x00000018);
      DVar2 = GetTickCount();
      unaff_EBP = (LPCRITICAL_SECTION)(unaff_ESI + 0x1911);
      EnterCriticalSection(unaff_EBP);
      FUN_0066f830(iVar4);
      if ((*(int *)(unaff_ESI + 0xbd) == 4) && (45000 < DVar2 - *(int *)(unaff_ESI + 0x190d))) {
        *(undefined4 *)(unaff_ESI + 0xbd) = 6;
LAB_0066feea:
        FUN_0066f960();
      }
      else if (*(int *)(unaff_ESI + 0xbd) == 6) goto LAB_0066feea;
      if ((*(int *)(unaff_ESI + 0xbd) == 4) &&
         (*(int *)(unaff_ESI + 0xed) != *(int *)(unaff_ESI + 0xe5))) {
        FUN_0066fb20();
        DVar2 = GetTickCount();
      }
      if ((*(int *)(unaff_ESI + 0xbd) == 2) && (1000 < DVar2 - *(int *)(unaff_ESI + 0x1909))) {
        FUN_0066fa40();
        DVar2 = GetTickCount();
      }
      if (((*(int *)(unaff_ESI + 0xbd) == 4) &&
          (*(int *)(unaff_ESI + 0xed) == *(int *)(unaff_ESI + 0xe5))) &&
         (1000 < DVar2 - *(int *)(unaff_ESI + 0x1909))) {
        FUN_0066fac0(iVar4);
        GetTickCount();
      }
      unaff_EDI = in_stack_00000020;
      iVar3 = in_stack_00000018;
      if ((-1 < in_stack_00000018) &&
         ((*(int *)(unaff_ESI + 0xbd) == 4 || (*(int *)(unaff_ESI + 0xbd) == 2)))) {
        if (in_stack_00000020 == 4) {
          FUN_0066fbf0();
        }
        else if (((in_stack_00000020 == 1) || (in_stack_00000020 == 2)) || (in_stack_00000020 == 3))
        {
          FUN_0066f9e0(*(undefined4 *)(unaff_ESI + 0xb9));
          unaff_EDI = in_stack_00000020;
        }
        else {
          FUN_0066fbf0();
          FUN_0066fc90(*(undefined4 *)(unaff_ESI + 0xb9));
          unaff_EDI = in_stack_00000020;
        }
        in_stack_00000018 = -1;
        DVar2 = GetTickCount();
        *(DWORD *)(unaff_ESI + 0x190d) = DVar2;
        iVar3 = -1;
      }
    } while ((*(int *)(unaff_ESI + 0xbd) != 3) || (iVar3 != 0));
  } while( true );
}


// ==== 0x670067 FUN_00670067

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __thiscall FUN_00670067(code *param_1)

{
  DWORD DVar1;
  int iVar2;
  int unaff_ESI;
  int iVar3;
  DWORD DVar4;
  HANDLE in_stack_00000014;
  undefined4 in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000024;
  int in_stack_00000028;
  
  do {
    (*param_1)();
    do {
      *(undefined4 *)(unaff_ESI + 0x192c) = 0;
      do {
        while( true ) {
          if (*(int *)(unaff_ESI + 0xbc) == 9) {
            *(undefined4 *)(unaff_ESI + 0xbc) = 1;
            return 0;
          }
          iVar3 = *(int *)(unaff_ESI + 0xbc);
          if (iVar3 == 8) {
            *(undefined4 *)(unaff_ESI + 0xbc) = 1;
            goto LAB_0066fdc5;
          }
          if ((iVar3 != 1) && (iVar3 != 0)) break;
LAB_0067007c:
          if (iVar3 == 7) {
LAB_00670085:
            if (*(int *)(unaff_ESI + 0x1900) < 1) goto LAB_0066fdc5;
            EnterCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x1910));
            FUN_0066f830();
            LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x1910));
            DVar4 = 0x19;
          }
          else {
LAB_0066fdc5:
            DVar4 = 0x32;
          }
          Sleep(DVar4);
        }
        if (iVar3 == 7) goto LAB_00670085;
        if (iVar3 == 5) goto LAB_0067007c;
        DVar4 = WaitForSingleObject(*(HANDLE *)(unaff_ESI + 0x94),0);
        if (DVar4 == 0x102) {
          in_stack_00000014 = *(HANDLE *)(unaff_ESI + 0x94);
          DVar4 = 1;
          if ((0 < *(int *)(unaff_ESI + 0x1900)) &&
             (DVar1 = WaitForSingleObject(*(HANDLE *)(unaff_ESI + 0xa8),0), DVar1 == 0x102)) {
            in_stack_00000018 = *(undefined4 *)(unaff_ESI + 0xa8);
            DVar4 = 2;
          }
          WaitForMultipleObjects(DVar4,&stack0x00000014,0,100);
        }
        in_stack_0000001c = -1;
        FUN_0066f600();
        DVar4 = GetTickCount();
        EnterCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x1910));
        FUN_0066f830();
        if ((*(int *)(unaff_ESI + 0xbc) == 4) && (45000 < DVar4 - *(int *)(unaff_ESI + 0x190c))) {
          *(undefined4 *)(unaff_ESI + 0xbc) = 6;
LAB_0066feea:
          FUN_0066f960();
        }
        else if (*(int *)(unaff_ESI + 0xbc) == 6) goto LAB_0066feea;
        if ((*(int *)(unaff_ESI + 0xbc) == 4) &&
           (*(int *)(unaff_ESI + 0xec) != *(int *)(unaff_ESI + 0xe4))) {
          FUN_0066fb20();
          DVar4 = GetTickCount();
        }
        if ((*(int *)(unaff_ESI + 0xbc) == 2) && (1000 < DVar4 - *(int *)(unaff_ESI + 0x1908))) {
          FUN_0066fa40();
          DVar4 = GetTickCount();
        }
        if (((*(int *)(unaff_ESI + 0xbc) == 4) &&
            (*(int *)(unaff_ESI + 0xec) == *(int *)(unaff_ESI + 0xe4))) &&
           (1000 < DVar4 - *(int *)(unaff_ESI + 0x1908))) {
          FUN_0066fac0();
          GetTickCount();
        }
        iVar3 = in_stack_00000024;
        iVar2 = in_stack_0000001c;
        if ((-1 < in_stack_0000001c) &&
           ((*(int *)(unaff_ESI + 0xbc) == 4 || (*(int *)(unaff_ESI + 0xbc) == 2)))) {
          if (in_stack_00000024 == 4) {
            FUN_0066fbf0();
          }
          else if (((in_stack_00000024 == 1) || (in_stack_00000024 == 2)) ||
                  (in_stack_00000024 == 3)) {
            FUN_0066f9e0();
            iVar3 = in_stack_00000024;
          }
          else {
            FUN_0066fbf0();
            FUN_0066fc90();
            iVar3 = in_stack_00000024;
          }
          in_stack_0000001c = -1;
          DVar4 = GetTickCount();
          *(DWORD *)(unaff_ESI + 0x190c) = DVar4;
          iVar2 = -1;
        }
        if ((((*(int *)(unaff_ESI + 0xbc) == 3) && (iVar2 == 0)) && (in_stack_00000028 != 0)) &&
           (iVar3 == 1)) {
          *(int *)(unaff_ESI + 0xc0) = in_stack_00000028;
          *(undefined4 *)(unaff_ESI + 0xbc) = 4;
          FUN_0066f9e0();
          in_stack_0000001c = -1;
          DVar4 = GetTickCount();
          *(DWORD *)(unaff_ESI + 0x190c) = DVar4;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x1910));
      } while (*(int *)(unaff_ESI + 0x192c) == 0);
      param_1 = *(code **)(unaff_ESI + 0x1930);
    } while (param_1 == (code *)0x0);
  } while( true );
}


// ==== 0x6700c0 FUN_006700c0

void FUN_006700c0(LPVOID param_1)

{
  HANDLE pvVar1;
  DWORD DVar2;
  LPVOID pvVar3;
  
  if (*(int *)((int)param_1 + 0xbc) == 4) {
    *(undefined4 *)((int)param_1 + 0xbc) = 6;
    do {
      Sleep(0);
    } while (*(int *)((int)param_1 + 0xbc) == 6);
  }
  *(undefined4 *)((int)param_1 + 0xbc) = 9;
  do {
    Sleep(0);
  } while (*(int *)((int)param_1 + 0xbc) != 1);
  if (*(HANDLE *)((int)param_1 + 0x6c) != (HANDLE)0xffffffff) {
    SetCommMask(*(HANDLE *)((int)param_1 + 0x6c),2);
    PurgeComm(*(HANDLE *)((int)param_1 + 0x6c),0xf);
    CloseHandle(*(HANDLE *)((int)param_1 + 0x6c));
  }
  CloseHandle(*(HANDLE *)((int)param_1 + 0x80));
  CloseHandle(*(HANDLE *)((int)param_1 + 0x94));
  CloseHandle(*(HANDLE *)((int)param_1 + 0xa8));
  pvVar3 = *(LPVOID *)((int)param_1 + 0xd4);
  DVar2 = 0;
  pvVar1 = GetProcessHeap();
  HeapFree(pvVar1,DVar2,pvVar3);
  pvVar3 = *(LPVOID *)((int)param_1 + 0xf0);
  DVar2 = 0;
  pvVar1 = GetProcessHeap();
  HeapFree(pvVar1,DVar2,pvVar3);
  DVar2 = 0;
  pvVar1 = GetProcessHeap();
  HeapFree(pvVar1,DVar2,param_1);
  return;
}


// ==== 0x670190 FUN_00670190

undefined4 FUN_00670190(undefined4 param_1,char *param_2,LPSTR param_3,char *param_4,CHAR param_5)

{
  char cVar1;
  char *pcVar2;
  HANDLE hObject;
  int iVar3;
  undefined **ppuVar4;
  LPSTR pCVar5;
  LPCSTR lpFileName;
  char *pcVar6;
  bool bVar7;
  undefined *puStack_14;
  undefined *apuStack_10 [4];
  
  puStack_14 = &DAT_006abdd4;
  apuStack_10[0] = &DAT_006abdcc;
  apuStack_10[1] = &DAT_006abdc4;
  apuStack_10[2] = &DAT_006abdbc;
  apuStack_10[3] = (undefined *)0x0;
  *param_3 = '*';
  param_3[1] = '\0';
  param_3[2] = '\0';
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
    return 0xffffffff;
  }
  if (0x3f < (int)param_4) {
    pcVar2 = param_2;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (pcVar2 + (2 - (int)(param_2 + 1)) <= param_4) {
      iVar3 = 10;
      bVar7 = true;
      pcVar2 = param_2;
      pcVar6 = "localhost";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar2 == *pcVar6;
        pcVar2 = pcVar2 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar7);
      if (!bVar7) {
        wsprintfA(param_3,"%s%c",param_2,0);
        return 1;
      }
      lpFileName = "COM1";
      ppuVar4 = &puStack_14;
      pCVar5 = param_3;
      do {
        hObject = CreateFileA(lpFileName,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,
                              (HANDLE)0x0);
        if (hObject != (HANDLE)0xffffffff) {
          CloseHandle(hObject);
          if (pCVar5 != param_3) {
            *pCVar5 = param_5;
            pCVar5 = pCVar5 + 1;
          }
          iVar3 = wsprintfA(pCVar5,"%s",lpFileName);
          pCVar5 = pCVar5 + iVar3;
        }
        lpFileName = ppuVar4[1];
        ppuVar4 = ppuVar4 + 1;
      } while (lpFileName != (LPCSTR)0x0);
      *pCVar5 = '\0';
      pCVar5[1] = '\0';
      return 1;
    }
  }
  return 0xfffffffa;
}


// ==== 0x6702d0 FUN_006702d0

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006702d0(int param_1,char *param_2)

{
  byte bVar1;
  int iVar2;
  undefined1 *puVar3;
  HANDLE pvVar4;
  byte *pbVar5;
  int iVar6;
  byte *_Str1;
  uint unaff_retaddr;
  DWORD local_103c;
  _COMMTIMEOUTS local_1038;
  char local_1024 [4];
  byte local_1020;
  byte local_101f [27];
  _COMMCONFIG local_1004 [78];
  uint local_4;
  
  local_4 = DAT_006eb720 ^ unaff_retaddr;
  iVar6 = 0;
  local_1038.ReadIntervalTimeout = 0xffffffff;
  local_1038.ReadTotalTimeoutMultiplier = 0;
  local_1038.ReadTotalTimeoutConstant = 0;
  local_1038.WriteTotalTimeoutMultiplier = 0;
  local_1038.WriteTotalTimeoutConstant = 0;
  if ((param_2 == (char *)0x0) && (*(int *)(param_1 + 0xbc) == 4)) {
    *(undefined4 *)(param_1 + 0xbc) = 5;
    SetCommMask(*(HANDLE *)(param_1 + 0x6c),2);
    PurgeComm(*(HANDLE *)(param_1 + 0x6c),0xf);
    CloseHandle(*(HANDLE *)(param_1 + 0x6c));
    *(undefined4 *)(param_1 + 0x6c) = 0xffffffff;
  }
  else {
    if (*(int *)(param_1 + 0xbc) == 1) {
      FUN_0066f590();
    }
    else if (*(int *)(param_1 + 0xbc) != 5) {
      return 0xfffffff8;
    }
    _strncpy(local_1024,param_2,0x20);
    iVar2 = _strchr(local_1024,0x3a);
    if (iVar2 == 0) {
      _Str1 = &DAT_006b9172;
    }
    else {
      puVar3 = (undefined1 *)_strchr(local_1024,0x3a);
      *puVar3 = 0;
      iVar2 = _strchr(param_2,0x3a);
      _Str1 = (byte *)(iVar2 + 1);
    }
    iVar2 = _strncmp(local_1024,"TAPI",4);
    if (iVar2 == 0) {
      iVar6 = 0;
      pbVar5 = &local_1020;
      while (('/' < (char)local_1020 && ((char)local_1020 < ':'))) {
        pbVar5 = pbVar5 + 1;
        iVar6 = (local_1020 & 0xf) + iVar6 * 10;
        local_1020 = *pbVar5;
      }
      *(int *)(param_1 + 0x6c) = iVar6;
    }
    else {
      pvVar4 = CreateFileA(local_1024,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,
                           (HANDLE)0x0);
      *(HANDLE *)(param_1 + 0x6c) = pvVar4;
      if (pvVar4 == (HANDLE)0xffffffff) {
        return 0xfffffffc;
      }
    }
    SetupComm(*(HANDLE *)(param_1 + 0x6c),0x2000,0x1000);
    SetCommTimeouts(*(HANDLE *)(param_1 + 0x6c),&local_1038);
    SetCommMask(*(HANDLE *)(param_1 + 0x6c),2);
    if (iVar6 == 0) {
      local_1004[0].dcb.DCBlength = 0x1c;
      GetCommState(*(HANDLE *)(param_1 + 0x6c),&local_1004[0].dcb);
      local_1004[0].dcb._8_4_ = local_1004[0].dcb._8_4_ & 0xffffb497 | 0x13;
      local_1004[0].dcb.EvtChar = '\n';
      local_1004[0].dcb.ByteSize = '\b';
      local_1004[0].dcb.StopBits = '\0';
      if (_Str1 != (byte *)0x0) {
        while (*_Str1 != 0) {
          if (*_Str1 == 0x2c) {
            _Str1 = _Str1 + 1;
          }
          iVar6 = _strncmp((char *)_Str1,"+RTS",4);
          if (iVar6 == 0) {
            local_1004[0].dcb._8_4_ = local_1004[0].dcb._8_4_ & 0xffffefff | 0x2000;
          }
          iVar6 = _strncmp((char *)_Str1,"-RTS",4);
          if (iVar6 == 0) {
            local_1004[0].dcb._8_4_ = local_1004[0].dcb._8_4_ & 0xffffdfff | 0x1000;
          }
          iVar6 = _strncmp((char *)_Str1,"+CTS",4);
          if (iVar6 == 0) {
            local_1004[0].dcb._8_4_ = local_1004[0].dcb._8_4_ | 4;
          }
          iVar6 = _strncmp((char *)_Str1,"-CTS",4);
          if (iVar6 == 0) {
            local_1004[0].dcb._8_4_ = local_1004[0].dcb._8_4_ & 0xfffffffb;
          }
          if (('/' < (char)*_Str1) && ((char)*_Str1 < ':')) {
            local_1004[0].dcb.BaudRate = 0;
            bVar1 = *_Str1;
            while (('/' < (char)bVar1 && ((char)bVar1 < ':'))) {
              local_1004[0].dcb.BaudRate = (bVar1 & 0xf) + local_1004[0].dcb.BaudRate * 10;
              _Str1 = _Str1 + 1;
              bVar1 = *_Str1;
            }
          }
          bVar1 = *_Str1;
          while ((bVar1 != 0x2c && (bVar1 != 0))) {
            pbVar5 = _Str1 + 1;
            _Str1 = _Str1 + 1;
            bVar1 = *pbVar5;
          }
        }
      }
      SetCommState(*(HANDLE *)(param_1 + 0x6c),&local_1004[0].dcb);
    }
    else {
      local_103c = 0x1000;
      GetCommConfig(*(HANDLE *)(param_1 + 0x6c),local_1004,&local_103c);
      INSERT(local_1004[0].dcb._8_4_,0,0xe,1);
      INSERT(local_1004[0].dcb._8_4_,0,0xb,1);
      INSERT(local_1004[0].dcb._8_4_,0,9,1);
      INSERT(local_1004[0].dcb._8_4_,0,8,1);
      INSERT(local_1004[0].dcb._8_4_,1,0,1);
      local_1004[0].dcb.EvtChar = '\n';
      SetCommConfig(*(HANDLE *)(param_1 + 0x6c),local_1004,local_103c);
    }
    PurgeComm(*(HANDLE *)(param_1 + 0x6c),0xc);
    SetEvent(*(HANDLE *)(param_1 + 0x80));
    SetEvent(*(HANDLE *)(param_1 + 0x94));
    SetEvent(*(HANDLE *)(param_1 + 0xa8));
    *(uint *)(param_1 + 0xbc) = (*(int *)(param_1 + 0xbc) != 5) + 4;
  }
  return 0;
}


// ==== 0x670660 FUN_00670660

undefined4 FUN_00670660(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 != 0) && (*(int *)(param_1 + 0xbc) == 1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1910));
    uVar1 = FUN_006702d0(param_1,param_2);
    if (*(int *)(param_1 + 0xbc) == 5) {
      *(undefined4 *)(param_1 + 0xbc) = 3;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1910));
    return uVar1;
  }
  return 0xfffffffe;
}


// ==== 0x6706c0 FUN_006706c0

undefined4 FUN_006706c0(int param_1)

{
  if (*(int *)(param_1 + 0xbc) != 1) {
    if (*(int *)(param_1 + 0xbc) == 4) {
      *(undefined4 *)(param_1 + 0xbc) = 6;
      do {
        Sleep(0);
      } while (*(int *)(param_1 + 0xbc) == 6);
    }
    *(undefined4 *)(param_1 + 0xbc) = 8;
    do {
      Sleep(0);
    } while (*(int *)(param_1 + 0xbc) != 1);
    if (*(HANDLE *)(param_1 + 0x6c) != (HANDLE)0xffffffff) {
      SetCommMask(*(HANDLE *)(param_1 + 0x6c),2);
      PurgeComm(*(HANDLE *)(param_1 + 0x6c),0xf);
      CloseHandle(*(HANDLE *)(param_1 + 0x6c));
      *(undefined4 *)(param_1 + 0x6c) = 0xffffffff;
    }
  }
  return 0;
}


// ==== 0x670740 FUN_00670740

undefined4 FUN_00670740(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 != 0) && (*(int *)(param_1 + 0xbc) == 1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1910));
    uVar1 = FUN_006702d0(param_1,param_2);
    if (*(int *)(param_1 + 0xbc) == 5) {
      *(undefined4 *)(param_1 + 0xbc) = 2;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1910));
    return uVar1;
  }
  return 0xfffffffe;
}


// ==== 0x6707a0 thunk_FUN_006706c0

undefined4 thunk_FUN_006706c0(int param_1)

{
  if (*(int *)(param_1 + 0xbc) != 1) {
    if (*(int *)(param_1 + 0xbc) == 4) {
      *(undefined4 *)(param_1 + 0xbc) = 6;
      do {
        Sleep(0);
      } while (*(int *)(param_1 + 0xbc) == 6);
    }
    *(undefined4 *)(param_1 + 0xbc) = 8;
    do {
      Sleep(0);
    } while (*(int *)(param_1 + 0xbc) != 1);
    if (*(HANDLE *)(param_1 + 0x6c) != (HANDLE)0xffffffff) {
      SetCommMask(*(HANDLE *)(param_1 + 0x6c),2);
      PurgeComm(*(HANDLE *)(param_1 + 0x6c),0xf);
      CloseHandle(*(HANDLE *)(param_1 + 0x6c));
      *(undefined4 *)(param_1 + 0x6c) = 0xffffffff;
    }
  }
  return 0;
}


// ==== 0x6707b0 FUN_006707b0

undefined4 FUN_006707b0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xbc);
  if ((iVar1 == 2) || (iVar1 == 3)) {
    return 2;
  }
  if ((iVar1 != 1) && (iVar1 != 7)) {
    if ((iVar1 != 4) && (iVar1 != 5)) {
      return 4;
    }
    return 3;
  }
  return 1;
}


// ==== 0x6707f0 GetTickCount

DWORD GetTickCount(void)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  return DVar1;
}


// ==== 0x670800 FUN_00670800

int FUN_00670800(int param_1,uint *param_2,uint param_3)

{
  int iVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  if ((*(int *)(param_1 + 0xbc) != 4) && (*(int *)(param_1 + 0xbc) != 5)) {
    return -2;
  }
  iVar3 = *(int *)(param_1 + 0xe4);
  iVar1 = *(int *)(param_1 + 0xe0);
  if ((iVar3 + *(int *)(param_1 + 0xdc)) % iVar1 == *(int *)(param_1 + 0xe8)) {
    return 0;
  }
  if (param_3 == 0) {
    return (((iVar1 - *(int *)(param_1 + 0xe8)) + iVar3) % iVar1) / *(int *)(param_1 + 0xdc) + 1;
  }
  puVar5 = (uint *)(*(int *)(param_1 + 0xf0) + iVar3);
  *puVar5 = param_3;
  if (*(int *)(param_1 + 0xdc) + 0x800U < param_3 + 4) {
    return -6;
  }
  puVar6 = puVar5 + 4;
  for (uVar4 = param_3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar6 = *param_2;
    param_2 = param_2 + 1;
    puVar6 = puVar6 + 1;
  }
  for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
    *(char *)puVar6 = (char)*param_2;
    param_2 = (uint *)((int)param_2 + 1);
    puVar6 = (uint *)((int)puVar6 + 1);
  }
  puVar5[2] = *(uint *)(param_1 + 0xf4);
  *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + 1;
  puVar5[3] = *(int *)(param_1 + 0xd8) - 1;
  DVar2 = GetTickCount();
  puVar5[1] = DVar2;
  *(int *)(param_1 + 0xe4) =
       (*(int *)(param_1 + 0xdc) + *(int *)(param_1 + 0xe4)) % *(int *)(param_1 + 0xe0);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1910));
  FUN_0066fb20();
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1910));
  iVar3 = (((*(int *)(param_1 + 0xe4) - *(int *)(param_1 + 0xe8)) + *(int *)(param_1 + 0xe0)) %
          *(int *)(param_1 + 0xe0)) / *(int *)(param_1 + 0xdc);
  if (iVar3 < 1) {
    iVar3 = 1;
  }
  return iVar3;
}


// ==== 0x670940 FUN_00670940

undefined4 FUN_00670940(int param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  if (*(int *)(param_1 + 0xd0) == *(int *)(param_1 + 0xcc)) {
    return 0xfffffff9;
  }
  iVar1 = *(int *)(param_1 + 0x1928);
  while (iVar1 != 0) {
    Sleep(0);
    iVar1 = *(int *)(param_1 + 0x1928);
  }
  uVar4 = *(uint *)(*(int *)(param_1 + 0xd4) + *(int *)(param_1 + 0xd0));
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0xd4) + *(int *)(param_1 + 0xd0));
  if ((int)param_3 <= (int)uVar4) {
    uVar4 = param_3;
  }
  puVar5 = puVar2 + 4;
  for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *param_2 = *puVar5;
    puVar5 = puVar5 + 1;
    param_2 = param_2 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)param_2 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = puVar2[1];
  }
  return *puVar2;
}


// ==== 0x6709c0 FUN_006709c0

int FUN_006709c0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_00670940(param_1,param_2,param_3,param_4);
  if (-1 < iVar1) {
    *(int *)(param_1 + 0xd0) =
         (*(int *)(param_1 + 0xc4) + *(int *)(param_1 + 0xd0)) % *(int *)(param_1 + 200);
  }
  return iVar1;
}


// ==== 0x670a10 FUN_00670a10

undefined4 * FUN_00670a10(int param_1,int param_2,int param_3)

{
  HANDLE pvVar1;
  undefined4 *lpParameter;
  LPVOID pvVar2;
  undefined4 *puVar3;
  int iVar4;
  DWORD DVar5;
  SIZE_T SVar6;
  DWORD local_4;
  
  SVar6 = 0x1934;
  DVar5 = 0;
  pvVar1 = GetProcessHeap();
  lpParameter = HeapAlloc(pvVar1,DVar5,SVar6);
  puVar3 = (undefined4 *)0x0;
  if (lpParameter != (undefined4 *)0x0) {
    puVar3 = lpParameter;
    for (iVar4 = 0x64d; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    *lpParameter = FUN_00670a10;
    lpParameter[1] = FUN_006700c0;
    lpParameter[2] = FUN_00670190;
    lpParameter[3] = NullUpdate_ret;
    lpParameter[4] = FUN_00670660;
    lpParameter[5] = FUN_006706c0;
    lpParameter[6] = FUN_00670740;
    lpParameter[7] = thunk_FUN_006706c0;
    lpParameter[8] = NullUpdate_ret;
    lpParameter[9] = FUN_006707b0;
    lpParameter[10] = GetTickCount;
    lpParameter[0xb] = FUN_00670800;
    lpParameter[0xc] = FUN_00670940;
    lpParameter[0xd] = FUN_006709c0;
    builtin_strncpy((char *)(lpParameter + 0x12),"SERI",4);
    *(undefined2 *)(lpParameter + 0x13) = 0x4c41;
    *(undefined1 *)((int)lpParameter + 0x4e) = 0;
    InitializeCriticalSection((LPCRITICAL_SECTION)(lpParameter + 0x644));
    param_1 = param_1 + 0x10;
    SVar6 = param_1 * param_2;
    DVar5 = 0;
    lpParameter[0x31] = param_1;
    lpParameter[0x32] = SVar6;
    pvVar1 = GetProcessHeap();
    pvVar2 = HeapAlloc(pvVar1,DVar5,SVar6);
    lpParameter[0x37] = param_1;
    SVar6 = param_1 * param_3;
    lpParameter[0x38] = SVar6;
    DVar5 = 0;
    lpParameter[0x35] = pvVar2;
    pvVar1 = GetProcessHeap();
    pvVar2 = HeapAlloc(pvVar1,DVar5,SVar6);
    lpParameter[0x3c] = pvVar2;
    lpParameter[0x23e] = 0;
    lpParameter[0x641] = 0;
    lpParameter[0x640] = 0;
    lpParameter[0x63f] = 0x800;
    lpParameter[0x2f] = 1;
    lpParameter[0x30] = 0;
    DVar5 = GetCurrentThreadId();
    lpParameter[0x2e] = DVar5;
    lpParameter[0x1b] = 0xffffffff;
    pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCSTR)0x0);
    lpParameter[0x20] = pvVar1;
    pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCSTR)0x0);
    lpParameter[0x25] = pvVar1;
    pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCSTR)0x0);
    lpParameter[0x2a] = pvVar1;
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_0066fd80,lpParameter,0,&local_4);
    if (pvVar1 == (HANDLE)0x0) {
      return (undefined4 *)0x0;
    }
    SetThreadPriority(pvVar1,2);
    CloseHandle(pvVar1);
    puVar3 = lpParameter;
  }
  return puVar3;
}


// ==== 0x670bd0 Ordinal_111

void Ordinal_111(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670bd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_111();
  return;
}


// ==== 0x670bd6 Ordinal_115

void Ordinal_115(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670bd6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_115();
  return;
}


// ==== 0x670bdc Ordinal_21

void Ordinal_21(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670bdc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_21();
  return;
}


// ==== 0x670be2 Ordinal_10

void Ordinal_10(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670be2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_10();
  return;
}


// ==== 0x670be8 Ordinal_23

void Ordinal_23(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670be8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_23();
  return;
}


// ==== 0x670bee Ordinal_3

void Ordinal_3(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670bee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_3();
  return;
}


// ==== 0x670bf4 Ordinal_22

void Ordinal_22(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670bf4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_22();
  return;
}


// ==== 0x670bfa Ordinal_2

void Ordinal_2(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670bfa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_2();
  return;
}


// ==== 0x670c00 Ordinal_4

void Ordinal_4(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670c00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_4();
  return;
}


// ==== 0x670c06 Ordinal_13

void Ordinal_13(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670c06. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_13();
  return;
}


// ==== 0x670c0c Ordinal_1

void Ordinal_1(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670c0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_1();
  return;
}


// ==== 0x670c12 Ordinal_20

void Ordinal_20(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670c12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_20();
  return;
}


// ==== 0x670c18 Ordinal_19

void Ordinal_19(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670c18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_19();
  return;
}


// ==== 0x670c1e Ordinal_17

void Ordinal_17(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670c1e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_17();
  return;
}


// ==== 0x670c24 Ordinal_16

void Ordinal_16(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670c24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_16();
  return;
}


// ==== 0x670c2a Ordinal_7

void Ordinal_7(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670c2a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_7();
  return;
}


// ==== 0x670c30 Ordinal_18

void Ordinal_18(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670c30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_18();
  return;
}


// ==== 0x670c36 Ordinal_5

void Ordinal_5(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670c36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_5();
  return;
}


// ==== 0x670c3c Ordinal_6

void Ordinal_6(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670c3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_6();
  return;
}


// ==== 0x670c42 WSAIoctl

void WSAIoctl(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670c42. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WSAIoctl();
  return;
}


// ==== 0x670c48 Ordinal_52

void Ordinal_52(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670c48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_52();
  return;
}


// ==== 0x670c4e Ordinal_116

void Ordinal_116(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670c4e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_116();
  return;
}


// ==== 0x670c54 Ordinal_14

void Ordinal_14(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670c54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_14();
  return;
}


// ==== 0x670c5a Ordinal_15

void Ordinal_15(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670c5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_15();
  return;
}


// ==== 0x670c60 Ordinal_9

void Ordinal_9(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670c60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_9();
  return;
}


// ==== 0x670c66 Ordinal_8

void Ordinal_8(void)

{
                    /* WARNING: Could not recover jumptable at 0x00670c66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Ordinal_8();
  return;
}


// ==== 0x670c6c __amsg_exit

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_00717a7c != 2) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)PTR___exit_006eb1b4)(0xff);
  return;
}


// ==== 0x670c91 fast_error_exit

/* Library Function - Single Match
    _fast_error_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl fast_error_exit(undefined4 param_1)

{
  if (DAT_00717a7c != 2) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  ___crtExitProcess(0xff);
  return;
}


// ==== 0x670cb5 WinMainCRTStartup

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

undefined4 WinMainCRTStartup(void)

{
  HMODULE pHVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  bool bVar5;
  _OSVERSIONINFOA local_cc;
  
  local_cc.szCSDVersion[0x7c] = -0x33;
  local_cc.szCSDVersion[0x7d] = '\f';
  local_cc.szCSDVersion[0x7e] = 'g';
  local_cc.szCSDVersion[0x7f] = '\0';
  local_cc.dwOSVersionInfoSize = 0x94;
  GetVersionExA(&local_cc);
  DAT_00717a88 = local_cc.dwPlatformId;
  DAT_00717a94 = local_cc.dwMajorVersion;
  _DAT_00717a98 = local_cc.dwMinorVersion;
  _DAT_00717a8c = local_cc.dwBuildNumber & 0x7fff;
  if (local_cc.dwPlatformId != 2) {
    _DAT_00717a8c = _DAT_00717a8c | 0x8000;
  }
  _DAT_00717a90 = local_cc.dwMajorVersion * 0x100 + local_cc.dwMinorVersion;
  pHVar1 = GetModuleHandleA((LPCSTR)0x0);
  if (((short)pHVar1->unused == 0x5a4d) &&
     (piVar4 = (int *)((int)&pHVar1->unused + pHVar1[0xf].unused), *piVar4 == 0x4550)) {
    if ((short)piVar4[6] == 0x10b) {
      if (0xe < (uint)piVar4[0x1d]) {
        iVar2 = piVar4[0x3a];
        goto LAB_00670d74;
      }
    }
    else if (((short)piVar4[6] == 0x20b) && (0xe < (uint)piVar4[0x21])) {
      iVar2 = piVar4[0x3e];
LAB_00670d74:
      bVar5 = iVar2 != 0;
      goto LAB_00670d7a;
    }
  }
  bVar5 = false;
LAB_00670d7a:
  iVar2 = __heap_init();
  if (iVar2 == 0) {
    fast_error_exit(0x1c);
  }
  iVar2 = FUN_00675aa7();
  if (iVar2 == 0) {
    fast_error_exit(0x10);
  }
  FUN_00675812();
  iVar2 = FUN_00675614();
  if (iVar2 < 0) {
    __amsg_exit(0x1b);
  }
  DAT_00794364 = GetCommandLineA();
  DAT_00717a74 = ___crtGetEnvironmentStringsA();
  iVar2 = FUN_00675450();
  if (iVar2 < 0) {
    __amsg_exit(8);
  }
  iVar2 = __setenvp();
  if (iVar2 < 0) {
    __amsg_exit(9);
  }
  iVar2 = FUN_00671fb2();
  if (iVar2 != 0) {
    __amsg_exit(iVar2);
  }
  DAT_00717aac = DAT_00717aa8;
  uVar3 = GameFlow__Run(DAT_00717a9c,DAT_00717aa0,DAT_00717aa8);
  if (!bVar5) {
    FUN_006720ea(uVar3);
  }
  FUN_0067210c();
  return uVar3;
}


// ==== 0x670e38 FUN_00670e38

void FUN_00670e38(void)

{
  ulong _ExceptionNum;
  int unaff_EBP;
  
  _ExceptionNum = (*(_EXCEPTION_POINTERS **)(unaff_EBP + -0x14))->ExceptionRecord->ExceptionCode;
  *(ulong *)(unaff_EBP + -0x28) = _ExceptionNum;
  __XcptFilter(_ExceptionNum,*(_EXCEPTION_POINTERS **)(unaff_EBP + -0x14));
  return;
}


// ==== 0x670e4c FUN_00670e4c

/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined4 FUN_00670e4c(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x18);
  uVar2 = *(undefined4 *)(unaff_EBP + -0x28);
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    *(undefined4 *)(iVar1 + -4) = uVar2;
                    /* WARNING: Subroutine does not return */
    *(undefined4 *)(iVar1 + -8) = 0x670e5e;
    __exit(*(int *)(iVar1 + -4));
  }
  *(undefined4 *)(iVar1 + -4) = 0x670e63;
  FUN_0067211b();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x38) = 0x670e71;
  return uVar2;
}


// ==== 0x670e72 _atol

/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

long __cdecl _atol(char *_Str)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_006eb554) {
    ptVar2 = ___updatetlocinfo();
  }
  while( true ) {
    if ((int)ptVar2->lc_category[1].refcount < 2) {
      uVar3 = *(byte *)((int)ptVar2->lc_category[3].refcount + (uint)(byte)*_Str * 2) & 8;
    }
    else {
      uVar3 = _isctype(ptVar2,(uint)(byte)*_Str,8);
    }
    if (uVar3 == 0) break;
    _Str = _Str + 1;
  }
  uVar3 = (uint)(byte)*_Str;
  pbVar7 = (byte *)(_Str + 1);
  if ((uVar3 == 0x2d) || (uVar5 = uVar3, uVar3 == 0x2b)) {
    uVar5 = (uint)*pbVar7;
    pbVar7 = (byte *)(_Str + 2);
  }
  iVar4 = 0;
  while( true ) {
    if ((uVar5 < 0x30) || (0x39 < uVar5)) {
      iVar6 = -1;
    }
    else {
      iVar6 = uVar5 - 0x30;
    }
    if (iVar6 == -1) break;
    iVar4 = iVar6 + iVar4 * 10;
    uVar5 = (uint)*pbVar7;
    pbVar7 = pbVar7 + 1;
  }
  if (uVar3 == 0x2d) {
    iVar4 = -iVar4;
  }
  return iVar4;
}


// ==== 0x670efa _atoi

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

long __cdecl _atoi(char *_Str)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  
  p_Var1 = __getptd();
  ptVar2 = (pthreadlocinfo)p_Var1->_tfpecode;
  if (ptVar2 != (pthreadlocinfo)PTR_DAT_006eb554) {
    ptVar2 = ___updatetlocinfo();
  }
  while( true ) {
    if ((int)ptVar2->lc_category[1].refcount < 2) {
      uVar3 = *(byte *)((int)ptVar2->lc_category[3].refcount + (uint)(byte)*_Str * 2) & 8;
    }
    else {
      uVar3 = _isctype(ptVar2,(uint)(byte)*_Str,8);
    }
    if (uVar3 == 0) break;
    _Str = _Str + 1;
  }
  uVar3 = (uint)(byte)*_Str;
  pbVar7 = (byte *)(_Str + 1);
  if ((uVar3 == 0x2d) || (uVar5 = uVar3, uVar3 == 0x2b)) {
    uVar5 = (uint)*pbVar7;
    pbVar7 = (byte *)(_Str + 2);
  }
  iVar4 = 0;
  while( true ) {
    if ((uVar5 < 0x30) || (0x39 < uVar5)) {
      iVar6 = -1;
    }
    else {
      iVar6 = uVar5 - 0x30;
    }
    if (iVar6 == -1) break;
    iVar4 = iVar6 + iVar4 * 10;
    uVar5 = (uint)*pbVar7;
    pbVar7 = pbVar7 + 1;
  }
  if (uVar3 == 0x2d) {
    iVar4 = -iVar4;
  }
  return iVar4;
}


// ==== 0x670f00 _strrchr

/* [canon] runtime high (ghidra+hopper) docs/re/runtime.md */

char * __cdecl _strrchr(char *_Str,int _Ch)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  iVar2 = -1;
  do {
    pcVar4 = _Str;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar4 = _Str + 1;
    cVar1 = *_Str;
    _Str = pcVar4;
  } while (cVar1 != '\0');
  iVar2 = -(iVar2 + 1);
  pcVar4 = pcVar4 + -1;
  do {
    pcVar3 = pcVar4;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar3 = pcVar4 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar3;
  } while ((char)_Ch != cVar1);
  pcVar3 = pcVar3 + 1;
  if (*pcVar3 != (char)_Ch) {
    pcVar3 = (char *)0x0;
  }
  return pcVar3;
}


// ==== 0x670f2d __onexit_lk

/* Library Function - Single Match
    __onexit_lk
   
   Library: Visual Studio 2003 Release */

void __onexit_lk(void)

{
  size_t sVar1;
  void *pvVar2;
  size_t sVar3;
  undefined4 unaff_EDI;
  
  sVar1 = __msize(DAT_00793348);
  if (sVar1 < (uint)((int)DAT_00793344 + (4 - (int)DAT_00793348))) {
    sVar3 = 0x800;
    if (sVar1 < 0x800) {
      sVar3 = sVar1;
    }
    pvVar2 = _realloc(DAT_00793348,sVar3 + sVar1);
    if (pvVar2 == (void *)0x0) {
      pvVar2 = _realloc(DAT_00793348,sVar1 + 0x10);
      if (pvVar2 == (void *)0x0) {
        return;
      }
    }
    DAT_00793344 = (undefined4 *)((int)pvVar2 + ((int)DAT_00793344 - (int)DAT_00793348 >> 2) * 4);
    DAT_00793348 = pvVar2;
  }
  *DAT_00793344 = unaff_EDI;
  DAT_00793344 = DAT_00793344 + 1;
  return;
}


// ==== 0x670fad ___onexitinit

/* Library Function - Single Match
    ___onexitinit
   
   Library: Visual Studio 2003 Release */

undefined4 ___onexitinit(void)

{
  DAT_00793348 = _malloc(0x80);
  if (DAT_00793348 == (undefined4 *)0x0) {
    return 0x18;
  }
  *DAT_00793348 = 0;
  DAT_00793344 = DAT_00793348;
  return 0;
}


// ==== 0x670fd5 __onexit

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* [canon] runtime med (ghidra+hopper) docs/re/runtime.md */

_onexit_t __cdecl __onexit(_onexit_t _Func)

{
  _onexit_t p_Var1;
  
  FUN_00671fa0();
  p_Var1 = (_onexit_t)__onexit_lk();
  FUN_00671007();
  return p_Var1;
}


