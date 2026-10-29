// ==== 0x5f1bd7 FUN_005f1bd7

void FUN_005f1bd7(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined4 uVar9;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  
  PackedFloatingMUL(0x3f0000003f000000,param_3);
  PackedFloatingMUL(0x3f0000003f000000,param_2);
  uVar2 = FUN_0061bee0();
  uVar3 = FUN_0061bee0();
  uVar4 = FUN_0061bee0();
  uVar1 = (undefined4)uVar4;
  uVar9 = (undefined4)((ulonglong)uVar4 >> 0x20);
  uVar4 = CONCAT44((int)uVar3,(int)uVar3);
  uVar12 = (undefined4)((ulonglong)uVar3 >> 0x20);
  uVar10 = CONCAT44(uVar12,uVar12);
  uVar3 = PackedFloatingMUL(CONCAT44(uVar1,uVar1) ^ 0x8000000000000000,uVar10);
  uVar5 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),uVar4);
  uVar7 = PackedFloatingMUL(CONCAT44(uVar9,uVar9),uVar4);
  uVar10 = PackedFloatingMUL(CONCAT44(uVar9,uVar9) ^ 0x80000000,uVar10);
  uVar11 = CONCAT44((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  uVar3 = PackedFloatingMUL(uVar3,uVar2);
  uVar4 = PackedFloatingMUL(uVar5,uVar11);
  uVar5 = PackedFloatingMUL(uVar7,uVar11);
  uVar7 = PackedFloatingMUL(uVar10,uVar2);
  uVar2 = PackedFloatingADD(uVar3,uVar5);
  uVar5 = PackedFloatingADD(uVar4,uVar7);
  uVar3 = PackedFloatingADD(uVar2,uVar2);
  uVar4 = PackedFloatingADD(uVar5,uVar5);
  uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
  uVar9 = (undefined4)((ulonglong)uVar5 >> 0x20);
  uVar10 = CONCAT44(uVar9,uVar9);
  uVar7 = PackedFloatingMUL(uVar2,uVar3);
  uVar2 = CONCAT44((int)uVar3,(int)uVar4);
  uVar11 = PackedFloatingMUL(uVar3,uVar10);
  uVar5 = PackedFloatingMUL(CONCAT44((int)uVar5,(int)uVar5),uVar2);
  uVar3 = PackedFloatingMUL(uVar2,CONCAT44(uVar1,uVar1));
  uVar2 = PackedFloatingMUL(uVar2,uVar10);
  uVar4 = CONCAT44((int)((ulonglong)uVar5 >> 0x20),(int)((ulonglong)uVar3 >> 0x20));
  param_1[6] = 0;
  uVar10 = PackedFloatingADD(CONCAT44((int)uVar5,(int)uVar5),uVar7);
  uVar5 = PackedFloatingAccumulate(uVar7,uVar7);
  uVar2 = CONCAT44((int)((ulonglong)uVar11 >> 0x20),(int)uVar2);
  uVar6 = PackedFloatingSUBR(uVar5,0x3f8000003f800000);
  uVar7 = PackedFloatingSUBR(uVar10,0x3f8000003f800000);
  uVar5 = PackedFloatingADD(uVar4,uVar2);
  param_1[5] = uVar6 & 0xffffffff;
  uVar8 = PackedFloatingSUB(uVar4,uVar2);
  uVar6 = PackedFloatingADD(uVar3,uVar11);
  uVar2 = PackedFloatingSUB(uVar3,uVar11);
  param_1[3] = uVar6 & 0xffffffff;
  param_1[1] = uVar8 >> 0x20;
  param_1[2] = CONCAT44((int)uVar7,(int)uVar8);
  *param_1 = CONCAT44((int)uVar5,(int)((ulonglong)uVar7 >> 0x20));
  param_1[4] = CONCAT44((int)uVar2,(int)((ulonglong)uVar5 >> 0x20));
  param_1[7] = 0x3f80000000000000;
  FastExitMediaState();
  return;
}


// ==== 0x5f1d7c FUN_005f1d7c

void FUN_005f1d7c(ulonglong *param_1,uint param_2,undefined8 *param_3,undefined8 *param_4,
                 undefined8 *param_5)

{
  undefined4 uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 uVar7;
  ulonglong uVar6;
  undefined8 uVar8;
  ulonglong uVar9;
  undefined4 uVar12;
  ulonglong uVar10;
  undefined8 uVar11;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  ulonglong uVar17;
  
  *param_1 = (ulonglong)param_2;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = 0;
  *(uint *)((int)param_1 + 0x14) = param_2;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = (ulonglong)param_2;
  param_1[6] = 0;
  param_1[7] = 0x3f80000000000000;
  if (param_4 != (undefined8 *)0x0) {
    uVar15 = *param_4;
    uVar5 = param_4[1];
    uVar2 = PackedFloatingADD(uVar15,uVar15);
    uVar4 = PackedFloatingADD(uVar5,uVar5);
    uVar7 = (undefined4)((ulonglong)uVar15 >> 0x20);
    uVar12 = (undefined4)((ulonglong)uVar5 >> 0x20);
    uVar16 = CONCAT44(uVar12,uVar12);
    uVar8 = PackedFloatingMUL(uVar15,uVar2);
    uVar15 = CONCAT44((int)uVar2,(int)uVar4);
    uVar13 = PackedFloatingMUL(uVar2,uVar16);
    uVar4 = PackedFloatingMUL(CONCAT44((int)uVar5,(int)uVar5),uVar15);
    uVar5 = PackedFloatingMUL(uVar15,CONCAT44(uVar7,uVar7));
    uVar15 = PackedFloatingMUL(uVar15,uVar16);
    uVar2 = CONCAT44((int)((ulonglong)uVar4 >> 0x20),(int)((ulonglong)uVar5 >> 0x20));
    uVar16 = PackedFloatingADD(CONCAT44((int)uVar4,(int)uVar4),uVar8);
    uVar4 = PackedFloatingAccumulate(uVar8,uVar8);
    uVar15 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),(int)uVar15);
    uVar9 = PackedFloatingSUBR(uVar4,0x3f8000003f800000);
    uVar8 = PackedFloatingSUBR(uVar16,0x3f8000003f800000);
    uVar9 = uVar9 & 0xffffffff;
    uVar4 = PackedFloatingADD(uVar2,uVar15);
    uVar10 = PackedFloatingSUB(uVar2,uVar15);
    uVar6 = PackedFloatingADD(uVar5,uVar13);
    uVar5 = PackedFloatingSUB(uVar5,uVar13);
    uVar6 = uVar6 & 0xffffffff;
    uVar2 = CONCAT44((int)uVar8,(int)uVar10);
    uVar10 = uVar10 >> 0x20;
    uVar15 = CONCAT44((int)uVar4,(int)((ulonglong)uVar8 >> 0x20));
    uVar5 = CONCAT44((int)uVar5,(int)((ulonglong)uVar4 >> 0x20));
    if (param_3 == (undefined8 *)0x0) {
      uVar7 = (undefined4)(*param_1 >> 0x20);
      uVar12 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar13 = CONCAT44(uVar1,uVar1);
      uVar11 = PackedFloatingMUL(uVar15,uVar8);
      uVar4 = CONCAT44(uVar7,uVar7);
      uVar16 = PackedFloatingMUL(uVar8,uVar10);
      uVar14 = PackedFloatingMUL(uVar2,uVar4);
      uVar8 = CONCAT44(uVar12,uVar12);
      uVar4 = PackedFloatingMUL(uVar4,uVar6);
      uVar11 = PackedFloatingADD(uVar14,uVar11);
      uVar14 = PackedFloatingMUL(uVar5,uVar13);
      uVar16 = PackedFloatingADD(uVar4,uVar16);
      uVar4 = PackedFloatingMUL(uVar13,uVar9);
      uVar13 = PackedFloatingADD(uVar14,uVar11);
      uVar11 = PackedFloatingMUL(0,uVar8);
      uVar4 = PackedFloatingADD(uVar16,uVar4);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar17 = PackedFloatingADD(uVar11,uVar13);
      uVar3 = PackedFloatingADD(uVar8,uVar4);
      *param_1 = uVar17;
      param_1[1] = uVar3;
      uVar7 = (undefined4)(param_1[2] >> 0x20);
      uVar12 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar13 = CONCAT44(uVar1,uVar1);
      uVar11 = PackedFloatingMUL(uVar15,uVar8);
      uVar4 = CONCAT44(uVar7,uVar7);
      uVar16 = PackedFloatingMUL(uVar8,uVar10);
      uVar14 = PackedFloatingMUL(uVar2,uVar4);
      uVar8 = CONCAT44(uVar12,uVar12);
      uVar4 = PackedFloatingMUL(uVar4,uVar6);
      uVar11 = PackedFloatingADD(uVar14,uVar11);
      uVar14 = PackedFloatingMUL(uVar5,uVar13);
      uVar16 = PackedFloatingADD(uVar4,uVar16);
      uVar4 = PackedFloatingMUL(uVar13,uVar9);
      uVar13 = PackedFloatingADD(uVar14,uVar11);
      uVar11 = PackedFloatingMUL(0,uVar8);
      uVar4 = PackedFloatingADD(uVar16,uVar4);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar17 = PackedFloatingADD(uVar11,uVar13);
      uVar3 = PackedFloatingADD(uVar8,uVar4);
      param_1[2] = uVar17;
      param_1[3] = uVar3;
      uVar7 = (undefined4)(param_1[4] >> 0x20);
      uVar12 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar13 = CONCAT44(uVar1,uVar1);
      uVar11 = PackedFloatingMUL(uVar15,uVar8);
      uVar4 = CONCAT44(uVar7,uVar7);
      uVar16 = PackedFloatingMUL(uVar8,uVar10);
      uVar14 = PackedFloatingMUL(uVar2,uVar4);
      uVar8 = CONCAT44(uVar12,uVar12);
      uVar4 = PackedFloatingMUL(uVar4,uVar6);
      uVar11 = PackedFloatingADD(uVar14,uVar11);
      uVar14 = PackedFloatingMUL(uVar5,uVar13);
      uVar16 = PackedFloatingADD(uVar4,uVar16);
      uVar4 = PackedFloatingMUL(uVar13,uVar9);
      uVar13 = PackedFloatingADD(uVar14,uVar11);
      uVar11 = PackedFloatingMUL(0,uVar8);
      uVar4 = PackedFloatingADD(uVar16,uVar4);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar17 = PackedFloatingADD(uVar11,uVar13);
      uVar3 = PackedFloatingADD(uVar8,uVar4);
      param_1[4] = uVar17;
      param_1[5] = uVar3;
      uVar7 = (undefined4)(param_1[6] >> 0x20);
      uVar12 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar4 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar15,uVar4);
      uVar15 = CONCAT44(uVar7,uVar7);
      uVar4 = PackedFloatingMUL(uVar4,uVar10);
      uVar13 = PackedFloatingMUL(uVar2,uVar15);
      uVar2 = CONCAT44(uVar12,uVar12);
      uVar15 = PackedFloatingMUL(uVar15,uVar6);
      uVar16 = PackedFloatingADD(uVar13,uVar16);
      uVar13 = PackedFloatingMUL(uVar5,uVar8);
      uVar5 = PackedFloatingADD(uVar15,uVar4);
      uVar15 = PackedFloatingMUL(uVar8,uVar9);
      uVar4 = PackedFloatingADD(uVar13,uVar16);
      uVar8 = PackedFloatingMUL(0,uVar2);
      uVar15 = PackedFloatingADD(uVar5,uVar15);
      uVar5 = PackedFloatingMUL(uVar2,0x3f80000000000000);
      uVar6 = PackedFloatingADD(uVar8,uVar4);
      uVar10 = PackedFloatingADD(uVar5,uVar15);
      param_1[6] = uVar6;
      param_1[7] = uVar10;
    }
    else {
      uVar3 = PackedFloatingSUB(param_1[6],*param_3);
      uVar4 = PackedFloatingSUB((ulonglong)(uint)param_1[7],(ulonglong)*(uint *)(param_3 + 1));
      param_1[6] = uVar3;
      *(int *)(param_1 + 7) = (int)uVar4;
      uVar7 = (undefined4)(*param_1 >> 0x20);
      uVar12 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar13 = CONCAT44(uVar1,uVar1);
      uVar11 = PackedFloatingMUL(uVar15,uVar8);
      uVar4 = CONCAT44(uVar7,uVar7);
      uVar16 = PackedFloatingMUL(uVar8,uVar10);
      uVar14 = PackedFloatingMUL(uVar2,uVar4);
      uVar8 = CONCAT44(uVar12,uVar12);
      uVar4 = PackedFloatingMUL(uVar4,uVar6);
      uVar11 = PackedFloatingADD(uVar14,uVar11);
      uVar14 = PackedFloatingMUL(uVar5,uVar13);
      uVar16 = PackedFloatingADD(uVar4,uVar16);
      uVar4 = PackedFloatingMUL(uVar13,uVar9);
      uVar13 = PackedFloatingADD(uVar14,uVar11);
      uVar11 = PackedFloatingMUL(0,uVar8);
      uVar4 = PackedFloatingADD(uVar16,uVar4);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar17 = PackedFloatingADD(uVar11,uVar13);
      uVar3 = PackedFloatingADD(uVar8,uVar4);
      *param_1 = uVar17;
      param_1[1] = uVar3;
      uVar7 = (undefined4)(param_1[2] >> 0x20);
      uVar12 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar13 = CONCAT44(uVar1,uVar1);
      uVar11 = PackedFloatingMUL(uVar15,uVar8);
      uVar4 = CONCAT44(uVar7,uVar7);
      uVar16 = PackedFloatingMUL(uVar8,uVar10);
      uVar14 = PackedFloatingMUL(uVar2,uVar4);
      uVar8 = CONCAT44(uVar12,uVar12);
      uVar4 = PackedFloatingMUL(uVar4,uVar6);
      uVar11 = PackedFloatingADD(uVar14,uVar11);
      uVar14 = PackedFloatingMUL(uVar5,uVar13);
      uVar16 = PackedFloatingADD(uVar4,uVar16);
      uVar4 = PackedFloatingMUL(uVar13,uVar9);
      uVar13 = PackedFloatingADD(uVar14,uVar11);
      uVar11 = PackedFloatingMUL(0,uVar8);
      uVar4 = PackedFloatingADD(uVar16,uVar4);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar17 = PackedFloatingADD(uVar11,uVar13);
      uVar3 = PackedFloatingADD(uVar8,uVar4);
      param_1[2] = uVar17;
      param_1[3] = uVar3;
      uVar7 = (undefined4)(param_1[4] >> 0x20);
      uVar12 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar13 = CONCAT44(uVar1,uVar1);
      uVar11 = PackedFloatingMUL(uVar15,uVar8);
      uVar4 = CONCAT44(uVar7,uVar7);
      uVar16 = PackedFloatingMUL(uVar8,uVar10);
      uVar14 = PackedFloatingMUL(uVar2,uVar4);
      uVar8 = CONCAT44(uVar12,uVar12);
      uVar4 = PackedFloatingMUL(uVar4,uVar6);
      uVar11 = PackedFloatingADD(uVar14,uVar11);
      uVar14 = PackedFloatingMUL(uVar5,uVar13);
      uVar16 = PackedFloatingADD(uVar4,uVar16);
      uVar4 = PackedFloatingMUL(uVar13,uVar9);
      uVar13 = PackedFloatingADD(uVar14,uVar11);
      uVar11 = PackedFloatingMUL(0,uVar8);
      uVar4 = PackedFloatingADD(uVar16,uVar4);
      uVar8 = PackedFloatingMUL(uVar8,0x3f80000000000000);
      uVar17 = PackedFloatingADD(uVar11,uVar13);
      uVar3 = PackedFloatingADD(uVar8,uVar4);
      param_1[4] = uVar17;
      param_1[5] = uVar3;
      uVar7 = (undefined4)(param_1[6] >> 0x20);
      uVar12 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar4 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar15,uVar4);
      uVar15 = CONCAT44(uVar7,uVar7);
      uVar4 = PackedFloatingMUL(uVar4,uVar10);
      uVar13 = PackedFloatingMUL(uVar2,uVar15);
      uVar2 = CONCAT44(uVar12,uVar12);
      uVar15 = PackedFloatingMUL(uVar15,uVar6);
      uVar16 = PackedFloatingADD(uVar13,uVar16);
      uVar13 = PackedFloatingMUL(uVar5,uVar8);
      uVar5 = PackedFloatingADD(uVar15,uVar4);
      uVar15 = PackedFloatingMUL(uVar8,uVar9);
      uVar4 = PackedFloatingADD(uVar13,uVar16);
      uVar8 = PackedFloatingMUL(0,uVar2);
      uVar15 = PackedFloatingADD(uVar5,uVar15);
      uVar5 = PackedFloatingMUL(uVar2,0x3f80000000000000);
      uVar6 = PackedFloatingADD(uVar8,uVar4);
      uVar10 = PackedFloatingADD(uVar5,uVar15);
      param_1[6] = uVar6;
      param_1[7] = uVar10;
      uVar10 = PackedFloatingADD(param_1[6],*param_3);
      uVar15 = PackedFloatingADD((ulonglong)(uint)param_1[7],(ulonglong)*(uint *)(param_3 + 1));
      param_1[6] = uVar10;
      *(int *)(param_1 + 7) = (int)uVar15;
    }
  }
  if (param_5 != (undefined8 *)0x0) {
    uVar10 = PackedFloatingADD(*param_5,param_1[6]);
    uVar15 = PackedFloatingADD((ulonglong)*(uint *)(param_5 + 1),(ulonglong)(uint)param_1[7]);
    param_1[6] = uVar10;
    *(int *)(param_1 + 7) = (int)uVar15;
  }
  FastExitMediaState();
  return;
}


// ==== 0x5f22b0 FUN_005f22b0

void FUN_005f22b0(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined4 uVar9;
  undefined8 local_20;
  uint local_18;
  
  local_20 = *param_2;
  local_18 = *(uint *)(param_2 + 1);
  FUN_005f401f(&local_20,&local_20);
  uVar1 = FUN_0061bee0();
  uVar2 = PackedFloatingSUBR(uVar1,0x3f8000003f800000);
  uVar9 = (undefined4)((ulonglong)uVar1 >> 0x20);
  uVar4 = (ulonglong)local_18;
  uVar5 = PackedFloatingMUL(CONCAT44(local_18,local_18),local_20);
  uVar2 = CONCAT44((int)uVar2,(int)uVar2);
  uVar3 = PackedFloatingMUL(CONCAT44(local_18,(int)((ulonglong)local_20 >> 0x20)),local_20);
  uVar1 = CONCAT44((int)uVar1,(int)uVar1);
  uVar3 = PackedFloatingMUL(uVar3,uVar2);
  uVar5 = PackedFloatingMUL(uVar5,uVar2);
  uVar6 = PackedFloatingMUL(local_20,local_20);
  uVar7 = PackedFloatingMUL(uVar4,uVar4);
  uVar6 = PackedFloatingMUL(uVar6,uVar2);
  uVar7 = PackedFloatingMUL(uVar7,uVar2);
  uVar2 = PackedFloatingADD(uVar6,uVar1);
  uVar8 = PackedFloatingADD(uVar7,uVar1);
  uVar1 = CONCAT44(uVar9,uVar9);
  uVar6 = PackedFloatingMUL(local_20,uVar1);
  uVar1 = PackedFloatingMUL(uVar4,uVar1);
  param_1[6] = 0;
  uVar7 = CONCAT44((int)uVar6,(int)uVar1);
  uVar9 = (undefined4)((ulonglong)uVar6 >> 0x20);
  uVar6 = CONCAT44(uVar9,uVar9);
  param_1[5] = uVar8 & 0xffffffff;
  uVar1 = PackedFloatingSUB(uVar3,uVar7);
  uVar4 = PackedFloatingADD(uVar3,uVar7);
  uVar8 = PackedFloatingSUB(uVar5,uVar6);
  *param_1 = CONCAT44((int)uVar4,(int)uVar2);
  param_1[1] = uVar8 & 0xffffffff;
  uVar3 = PackedFloatingADD(CONCAT44((int)uVar5,(int)uVar5),uVar6);
  param_1[3] = uVar4 >> 0x20;
  param_1[7] = 0x3f80000000000000;
  param_1[4] = CONCAT44((int)((ulonglong)uVar1 >> 0x20),(int)((ulonglong)uVar3 >> 0x20));
  param_1[2] = CONCAT44((int)((ulonglong)uVar2 >> 0x20),(int)uVar1);
  FastExitMediaState();
  return;
}


// ==== 0x5f23c9 FUN_005f23c9

void FUN_005f23c9(ulonglong *param_1,undefined8 *param_2,undefined8 *param_3,ulonglong *param_4,
                 undefined8 *param_5,undefined8 *param_6,undefined8 *param_7)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined8 in_MM2;
  undefined8 uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  uint uVar11;
  ulonglong in_MM3;
  undefined8 uVar12;
  undefined8 uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  undefined8 uVar18;
  ulonglong uVar19;
  undefined8 uVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  undefined4 uVar26;
  undefined8 uVar25;
  undefined4 uVar27;
  ulonglong uVar28;
  ulonglong uVar29;
  
  if (param_4 == (ulonglong *)0x0) {
    uVar16 = PackedSwapDWords(in_MM2,0x3f800000);
    *param_1 = 0x3f800000;
    param_1[1] = 0;
    param_1[2] = uVar16;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0x3f800000;
    param_1[6] = 0;
    param_1[7] = uVar16;
  }
  else if (param_3 == (undefined8 *)0x0) {
    in_MM3 = *param_4;
    uVar16 = param_4[1];
    *param_1 = in_MM3 & 0xffffffff;
    param_1[1] = 0;
    param_1[2] = in_MM3 & 0xffffffff00000000;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = (ulonglong)(uint)uVar16;
    param_1[6] = 0;
    param_1[7] = 0x3f80000000000000;
  }
  else {
    uVar16 = *param_4;
    uVar17 = (ulonglong)(uint)param_4[1];
    uVar28 = uVar16 & 0xffffffff;
    uVar21 = uVar16 & 0xffffffff00000000;
    uVar4 = *param_3;
    uVar18 = param_3[1];
    uVar12 = PackedSwapDWords(uVar16,uVar4);
    uVar2 = PackedFloatingADD(uVar4,uVar4);
    uVar7 = PackedFloatingADD(uVar18,uVar18);
    uVar3 = PackedFloatingMUL(uVar2,uVar4);
    uVar8 = PackedFloatingMUL(uVar4,uVar7);
    uVar13 = PackedFloatingMUL(uVar12,uVar7);
    uVar12 = PackedFloatingMUL(uVar7,uVar18);
    uVar2 = PackedFloatingMUL(CONCAT44((int)((ulonglong)uVar18 >> 0x20),
                                       (int)((ulonglong)uVar4 >> 0x20)),
                              CONCAT44((int)uVar7,(int)uVar2));
    uVar4 = PackedFloatingSUBR(uVar3,0x3f8000003f800000);
    uVar14 = PackedFloatingPosNegAccumulate(uVar13,uVar13);
    uVar18 = PackedFloatingAccumulate(uVar3,uVar3);
    uVar3 = PackedFloatingPosNegAccumulate(uVar2,uVar2);
    uVar9 = PackedFloatingPosNegAccumulate(uVar8,uVar8);
    uVar4 = PackedFloatingSUB(uVar4,CONCAT44((int)uVar12,(int)uVar12));
    uVar22 = PackedSwapDWords(uVar12,uVar9);
    uVar19 = PackedFloatingSUBR(uVar18,0x3f8000003f800000);
    uVar2 = CONCAT44((int)uVar14,(int)uVar22);
    uVar10 = uVar9 & 0xffffffff;
    uVar16 = uVar19 >> 0x20;
    uVar5 = (undefined4)((ulonglong)uVar4 >> 0x20);
    uVar26 = (undefined4)((ulonglong)uVar3 >> 0x20);
    uVar18 = CONCAT44(uVar26,uVar5);
    uVar29 = uVar14 >> 0x20;
    uVar6 = (undefined4)uVar4;
    uVar1 = (undefined4)uVar3;
    uVar4 = CONCAT44(uVar6,uVar1);
    uVar27 = (undefined4)(uVar14 >> 0x20);
    uVar11 = (uint)(uVar19 >> 0x20);
    if (param_2 == (undefined8 *)0x0) {
      *param_1 = CONCAT44(uVar1,uVar5);
      param_1[2] = CONCAT44(uVar6,uVar26);
      param_1[5] = (ulonglong)uVar11;
      param_1[7] = 0x3f80000000000000;
      param_1[4] = CONCAT44(uVar27,(int)uVar9);
      param_1[6] = 0;
      param_1[3] = uVar14 & 0xffffffff;
      param_1[1] = uVar22 & 0xffffffff;
      uVar5 = (undefined4)(*param_1 >> 0x20);
      uVar6 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar28,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,0);
      uVar24 = PackedFloatingMUL(uVar21,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(0,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar17);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar9 = PackedFloatingADD(uVar13,uVar8);
      uVar14 = PackedFloatingADD(uVar7,uVar3);
      *param_1 = uVar9;
      param_1[1] = uVar14;
      uVar5 = (undefined4)(param_1[2] >> 0x20);
      uVar6 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar28,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,0);
      uVar24 = PackedFloatingMUL(uVar21,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(0,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar17);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar9 = PackedFloatingADD(uVar13,uVar8);
      uVar14 = PackedFloatingADD(uVar7,uVar3);
      param_1[2] = uVar9;
      param_1[3] = uVar14;
      uVar5 = (undefined4)(param_1[4] >> 0x20);
      uVar6 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar28,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,0);
      uVar24 = PackedFloatingMUL(uVar21,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(0,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar17);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar9 = PackedFloatingADD(uVar13,uVar8);
      uVar14 = PackedFloatingADD(uVar7,uVar3);
      param_1[4] = uVar9;
      param_1[5] = uVar14;
      uVar5 = (undefined4)(param_1[6] >> 0x20);
      uVar6 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar28,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,0);
      uVar24 = PackedFloatingMUL(uVar21,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(0,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar17);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar28 = PackedFloatingADD(uVar13,uVar8);
      uVar14 = PackedFloatingADD(uVar7,uVar3);
      param_1[6] = uVar28;
      param_1[7] = uVar14;
      uVar5 = (undefined4)(*param_1 >> 0x20);
      uVar6 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar18,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,uVar10);
      uVar24 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar29);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(uVar2,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar16);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar28 = PackedFloatingADD(uVar13,uVar8);
      uVar14 = PackedFloatingADD(uVar7,uVar3);
      *param_1 = uVar28;
      param_1[1] = uVar14;
      uVar5 = (undefined4)(param_1[2] >> 0x20);
      uVar6 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar18,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,uVar10);
      uVar24 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar29);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(uVar2,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar16);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar28 = PackedFloatingADD(uVar13,uVar8);
      uVar14 = PackedFloatingADD(uVar7,uVar3);
      param_1[2] = uVar28;
      param_1[3] = uVar14;
      uVar5 = (undefined4)(param_1[4] >> 0x20);
      uVar6 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar18,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,uVar10);
      uVar24 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar29);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(uVar2,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar16);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar28 = PackedFloatingADD(uVar13,uVar8);
      uVar14 = PackedFloatingADD(uVar7,uVar3);
      param_1[4] = uVar28;
      param_1[5] = uVar14;
      uVar5 = (undefined4)(param_1[6] >> 0x20);
      uVar6 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar3 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar12 = PackedFloatingMUL(uVar18,uVar3);
      uVar18 = CONCAT44(uVar5,uVar5);
      uVar3 = PackedFloatingMUL(uVar3,uVar10);
      uVar8 = PackedFloatingMUL(uVar4,uVar18);
      uVar4 = CONCAT44(uVar6,uVar6);
      uVar18 = PackedFloatingMUL(uVar18,uVar29);
      uVar12 = PackedFloatingADD(uVar8,uVar12);
      uVar8 = PackedFloatingMUL(uVar2,uVar7);
      uVar2 = PackedFloatingADD(uVar18,uVar3);
      uVar18 = PackedFloatingMUL(uVar7,uVar16);
      uVar3 = PackedFloatingADD(uVar8,uVar12);
      uVar7 = PackedFloatingMUL(0,uVar4);
      uVar18 = PackedFloatingADD(uVar2,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,0x3f80000000000000);
      uVar16 = PackedFloatingADD(uVar7,uVar3);
      in_MM3 = PackedFloatingADD(uVar4,uVar18);
      param_1[6] = uVar16;
      param_1[7] = in_MM3;
    }
    else {
      uVar12 = CONCAT44(uVar1,uVar5);
      uVar24 = CONCAT44(uVar6,uVar26);
      uVar15 = (ulonglong)uVar11;
      uVar25 = CONCAT44(uVar27,(int)uVar9);
      uVar14 = uVar14 & 0xffffffff;
      uVar22 = uVar22 & 0xffffffff;
      uVar3 = *param_2;
      uVar11 = *(uint *)(param_2 + 1);
      uVar9 = PackedSwapDWords(uVar22,0x3f800000);
      *param_1 = 0x3f800000;
      param_1[1] = 0;
      param_1[2] = uVar9;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0x3f800000;
      uVar19 = PackedFloatingSUB(uVar9,(ulonglong)uVar11);
      uVar9 = PackedFloatingSUB(0,uVar3);
      param_1[7] = uVar19;
      param_1[6] = uVar9;
      uVar5 = (undefined4)(*param_1 >> 0x20);
      uVar6 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar13 = CONCAT44(uVar1,uVar1);
      uVar20 = PackedFloatingMUL(uVar12,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar8 = PackedFloatingMUL(uVar7,uVar22);
      uVar23 = PackedFloatingMUL(uVar24,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar14);
      uVar20 = PackedFloatingADD(uVar23,uVar20);
      uVar23 = PackedFloatingMUL(uVar25,uVar13);
      uVar8 = PackedFloatingADD(uVar3,uVar8);
      uVar3 = PackedFloatingMUL(uVar13,uVar15);
      uVar13 = PackedFloatingADD(uVar23,uVar20);
      uVar20 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar8,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar19 = PackedFloatingADD(uVar20,uVar13);
      uVar9 = PackedFloatingADD(uVar7,uVar3);
      *param_1 = uVar19;
      param_1[1] = uVar9;
      uVar5 = (undefined4)(param_1[2] >> 0x20);
      uVar6 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar13 = CONCAT44(uVar1,uVar1);
      uVar20 = PackedFloatingMUL(uVar12,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar8 = PackedFloatingMUL(uVar7,uVar22);
      uVar23 = PackedFloatingMUL(uVar24,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar14);
      uVar20 = PackedFloatingADD(uVar23,uVar20);
      uVar23 = PackedFloatingMUL(uVar25,uVar13);
      uVar8 = PackedFloatingADD(uVar3,uVar8);
      uVar3 = PackedFloatingMUL(uVar13,uVar15);
      uVar13 = PackedFloatingADD(uVar23,uVar20);
      uVar20 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar8,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar19 = PackedFloatingADD(uVar20,uVar13);
      uVar9 = PackedFloatingADD(uVar7,uVar3);
      param_1[2] = uVar19;
      param_1[3] = uVar9;
      uVar5 = (undefined4)(param_1[4] >> 0x20);
      uVar6 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar13 = CONCAT44(uVar1,uVar1);
      uVar20 = PackedFloatingMUL(uVar12,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar8 = PackedFloatingMUL(uVar7,uVar22);
      uVar23 = PackedFloatingMUL(uVar24,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar14);
      uVar20 = PackedFloatingADD(uVar23,uVar20);
      uVar23 = PackedFloatingMUL(uVar25,uVar13);
      uVar8 = PackedFloatingADD(uVar3,uVar8);
      uVar3 = PackedFloatingMUL(uVar13,uVar15);
      uVar13 = PackedFloatingADD(uVar23,uVar20);
      uVar20 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar8,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar19 = PackedFloatingADD(uVar20,uVar13);
      uVar9 = PackedFloatingADD(uVar7,uVar3);
      param_1[4] = uVar19;
      param_1[5] = uVar9;
      uVar5 = (undefined4)(param_1[6] >> 0x20);
      uVar6 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar12,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,uVar22);
      uVar24 = PackedFloatingMUL(uVar24,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar14);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(uVar25,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar15);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar9 = PackedFloatingADD(uVar13,uVar8);
      uVar14 = PackedFloatingADD(uVar7,uVar3);
      param_1[6] = uVar9;
      param_1[7] = uVar14;
      uVar5 = (undefined4)(*param_1 >> 0x20);
      uVar6 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar28,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,0);
      uVar24 = PackedFloatingMUL(uVar21,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(0,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar17);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar9 = PackedFloatingADD(uVar13,uVar8);
      uVar14 = PackedFloatingADD(uVar7,uVar3);
      *param_1 = uVar9;
      param_1[1] = uVar14;
      uVar5 = (undefined4)(param_1[2] >> 0x20);
      uVar6 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar28,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,0);
      uVar24 = PackedFloatingMUL(uVar21,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(0,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar17);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar9 = PackedFloatingADD(uVar13,uVar8);
      uVar14 = PackedFloatingADD(uVar7,uVar3);
      param_1[2] = uVar9;
      param_1[3] = uVar14;
      uVar5 = (undefined4)(param_1[4] >> 0x20);
      uVar6 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar28,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,0);
      uVar24 = PackedFloatingMUL(uVar21,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(0,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar17);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar9 = PackedFloatingADD(uVar13,uVar8);
      uVar14 = PackedFloatingADD(uVar7,uVar3);
      param_1[4] = uVar9;
      param_1[5] = uVar14;
      uVar5 = (undefined4)(param_1[6] >> 0x20);
      uVar6 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar28,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,0);
      uVar24 = PackedFloatingMUL(uVar21,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(0,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar17);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar28 = PackedFloatingADD(uVar13,uVar8);
      uVar14 = PackedFloatingADD(uVar7,uVar3);
      param_1[6] = uVar28;
      param_1[7] = uVar14;
      uVar5 = (undefined4)(*param_1 >> 0x20);
      uVar6 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar18,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,uVar10);
      uVar24 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar29);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(uVar2,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar16);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar28 = PackedFloatingADD(uVar13,uVar8);
      uVar14 = PackedFloatingADD(uVar7,uVar3);
      *param_1 = uVar28;
      param_1[1] = uVar14;
      uVar5 = (undefined4)(param_1[2] >> 0x20);
      uVar6 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar18,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,uVar10);
      uVar24 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar29);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(uVar2,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar16);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar28 = PackedFloatingADD(uVar13,uVar8);
      uVar14 = PackedFloatingADD(uVar7,uVar3);
      param_1[2] = uVar28;
      param_1[3] = uVar14;
      uVar5 = (undefined4)(param_1[4] >> 0x20);
      uVar6 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar18,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,uVar10);
      uVar24 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar29);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(uVar2,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar16);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar28 = PackedFloatingADD(uVar13,uVar8);
      uVar14 = PackedFloatingADD(uVar7,uVar3);
      param_1[4] = uVar28;
      param_1[5] = uVar14;
      uVar5 = (undefined4)(param_1[6] >> 0x20);
      uVar6 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar3 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar12 = PackedFloatingMUL(uVar18,uVar3);
      uVar18 = CONCAT44(uVar5,uVar5);
      uVar3 = PackedFloatingMUL(uVar3,uVar10);
      uVar8 = PackedFloatingMUL(uVar4,uVar18);
      uVar4 = CONCAT44(uVar6,uVar6);
      uVar18 = PackedFloatingMUL(uVar18,uVar29);
      uVar12 = PackedFloatingADD(uVar8,uVar12);
      uVar8 = PackedFloatingMUL(uVar2,uVar7);
      uVar2 = PackedFloatingADD(uVar18,uVar3);
      uVar18 = PackedFloatingMUL(uVar7,uVar16);
      uVar3 = PackedFloatingADD(uVar8,uVar12);
      uVar7 = PackedFloatingMUL(0,uVar4);
      uVar18 = PackedFloatingADD(uVar2,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,0x3f80000000000000);
      uVar29 = PackedFloatingADD(uVar7,uVar3);
      uVar16 = PackedFloatingADD(uVar4,uVar18);
      param_1[6] = uVar29;
      param_1[7] = uVar16;
      in_MM3 = (ulonglong)(uint)param_1[7];
      uVar16 = PackedFloatingADD(*param_2,param_1[6]);
      uVar4 = PackedFloatingADD((ulonglong)*(uint *)(param_2 + 1),in_MM3);
      param_1[6] = uVar16;
      *(int *)(param_1 + 7) = (int)uVar4;
    }
  }
  if (param_6 != (undefined8 *)0x0) {
    uVar4 = *param_6;
    uVar18 = param_6[1];
    uVar12 = PackedSwapDWords(in_MM3,uVar4);
    uVar2 = PackedFloatingADD(uVar4,uVar4);
    uVar7 = PackedFloatingADD(uVar18,uVar18);
    uVar3 = PackedFloatingMUL(uVar2,uVar4);
    uVar8 = PackedFloatingMUL(uVar4,uVar7);
    uVar13 = PackedFloatingMUL(uVar12,uVar7);
    uVar12 = PackedFloatingMUL(uVar7,uVar18);
    uVar2 = PackedFloatingMUL(CONCAT44((int)((ulonglong)uVar18 >> 0x20),
                                       (int)((ulonglong)uVar4 >> 0x20)),
                              CONCAT44((int)uVar7,(int)uVar2));
    uVar4 = PackedFloatingSUBR(uVar3,0x3f8000003f800000);
    uVar29 = PackedFloatingPosNegAccumulate(uVar13,uVar13);
    uVar18 = PackedFloatingAccumulate(uVar3,uVar3);
    uVar3 = PackedFloatingPosNegAccumulate(uVar2,uVar2);
    uVar14 = PackedFloatingPosNegAccumulate(uVar8,uVar8);
    uVar4 = PackedFloatingSUB(uVar4,CONCAT44((int)uVar12,(int)uVar12));
    uVar2 = PackedSwapDWords(uVar12,uVar14);
    uVar16 = PackedFloatingSUBR(uVar18,0x3f8000003f800000);
    uVar2 = CONCAT44((int)uVar29,(int)uVar2);
    uVar14 = uVar14 & 0xffffffff;
    uVar16 = uVar16 >> 0x20;
    uVar18 = CONCAT44((int)((ulonglong)uVar3 >> 0x20),(int)((ulonglong)uVar4 >> 0x20));
    uVar29 = uVar29 >> 0x20;
    uVar4 = CONCAT44((int)uVar4,(int)uVar3);
    if (param_5 == (undefined8 *)0x0) {
      uVar5 = (undefined4)(*param_1 >> 0x20);
      uVar6 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar18,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,uVar14);
      uVar24 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar29);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(uVar2,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar16);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar9 = PackedFloatingADD(uVar13,uVar8);
      uVar28 = PackedFloatingADD(uVar7,uVar3);
      *param_1 = uVar9;
      param_1[1] = uVar28;
      uVar5 = (undefined4)(param_1[2] >> 0x20);
      uVar6 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar18,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,uVar14);
      uVar24 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar29);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(uVar2,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar16);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar9 = PackedFloatingADD(uVar13,uVar8);
      uVar28 = PackedFloatingADD(uVar7,uVar3);
      param_1[2] = uVar9;
      param_1[3] = uVar28;
      uVar5 = (undefined4)(param_1[4] >> 0x20);
      uVar6 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar18,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,uVar14);
      uVar24 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar29);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(uVar2,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar16);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar9 = PackedFloatingADD(uVar13,uVar8);
      uVar28 = PackedFloatingADD(uVar7,uVar3);
      param_1[4] = uVar9;
      param_1[5] = uVar28;
      uVar5 = (undefined4)(param_1[6] >> 0x20);
      uVar6 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar3 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar12 = PackedFloatingMUL(uVar18,uVar3);
      uVar18 = CONCAT44(uVar5,uVar5);
      uVar3 = PackedFloatingMUL(uVar3,uVar14);
      uVar8 = PackedFloatingMUL(uVar4,uVar18);
      uVar4 = CONCAT44(uVar6,uVar6);
      uVar18 = PackedFloatingMUL(uVar18,uVar29);
      uVar12 = PackedFloatingADD(uVar8,uVar12);
      uVar8 = PackedFloatingMUL(uVar2,uVar7);
      uVar2 = PackedFloatingADD(uVar18,uVar3);
      uVar18 = PackedFloatingMUL(uVar7,uVar16);
      uVar3 = PackedFloatingADD(uVar8,uVar12);
      uVar7 = PackedFloatingMUL(0,uVar4);
      uVar18 = PackedFloatingADD(uVar2,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,0x3f80000000000000);
      uVar29 = PackedFloatingADD(uVar7,uVar3);
      uVar16 = PackedFloatingADD(uVar4,uVar18);
      param_1[6] = uVar29;
      param_1[7] = uVar16;
    }
    else {
      uVar28 = PackedFloatingSUB(param_1[6],*param_5);
      uVar3 = PackedFloatingSUB((ulonglong)(uint)param_1[7],(ulonglong)*(uint *)(param_5 + 1));
      param_1[6] = uVar28;
      *(int *)(param_1 + 7) = (int)uVar3;
      uVar5 = (undefined4)(*param_1 >> 0x20);
      uVar6 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar18,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,uVar14);
      uVar24 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar29);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(uVar2,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar16);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar9 = PackedFloatingADD(uVar13,uVar8);
      uVar28 = PackedFloatingADD(uVar7,uVar3);
      *param_1 = uVar9;
      param_1[1] = uVar28;
      uVar5 = (undefined4)(param_1[2] >> 0x20);
      uVar6 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar18,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,uVar14);
      uVar24 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar29);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(uVar2,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar16);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar9 = PackedFloatingADD(uVar13,uVar8);
      uVar28 = PackedFloatingADD(uVar7,uVar3);
      param_1[2] = uVar9;
      param_1[3] = uVar28;
      uVar5 = (undefined4)(param_1[4] >> 0x20);
      uVar6 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar8 = CONCAT44(uVar1,uVar1);
      uVar13 = PackedFloatingMUL(uVar18,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar12 = PackedFloatingMUL(uVar7,uVar14);
      uVar24 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar29);
      uVar13 = PackedFloatingADD(uVar24,uVar13);
      uVar24 = PackedFloatingMUL(uVar2,uVar8);
      uVar12 = PackedFloatingADD(uVar3,uVar12);
      uVar3 = PackedFloatingMUL(uVar8,uVar16);
      uVar8 = PackedFloatingADD(uVar24,uVar13);
      uVar13 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar12,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,0x3f80000000000000);
      uVar9 = PackedFloatingADD(uVar13,uVar8);
      uVar28 = PackedFloatingADD(uVar7,uVar3);
      param_1[4] = uVar9;
      param_1[5] = uVar28;
      uVar5 = (undefined4)(param_1[6] >> 0x20);
      uVar6 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar3 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar12 = PackedFloatingMUL(uVar18,uVar3);
      uVar18 = CONCAT44(uVar5,uVar5);
      uVar3 = PackedFloatingMUL(uVar3,uVar14);
      uVar8 = PackedFloatingMUL(uVar4,uVar18);
      uVar4 = CONCAT44(uVar6,uVar6);
      uVar18 = PackedFloatingMUL(uVar18,uVar29);
      uVar12 = PackedFloatingADD(uVar8,uVar12);
      uVar8 = PackedFloatingMUL(uVar2,uVar7);
      uVar2 = PackedFloatingADD(uVar18,uVar3);
      uVar18 = PackedFloatingMUL(uVar7,uVar16);
      uVar3 = PackedFloatingADD(uVar8,uVar12);
      uVar7 = PackedFloatingMUL(0,uVar4);
      uVar18 = PackedFloatingADD(uVar2,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,0x3f80000000000000);
      uVar29 = PackedFloatingADD(uVar7,uVar3);
      uVar16 = PackedFloatingADD(uVar4,uVar18);
      param_1[6] = uVar29;
      param_1[7] = uVar16;
      uVar16 = PackedFloatingADD(param_1[6],*param_5);
      uVar4 = PackedFloatingADD((ulonglong)(uint)param_1[7],(ulonglong)*(uint *)(param_5 + 1));
      param_1[6] = uVar16;
      *(int *)(param_1 + 7) = (int)uVar4;
    }
  }
  if (param_7 != (undefined8 *)0x0) {
    uVar16 = PackedFloatingADD(param_1[6],*param_7);
    uVar4 = PackedFloatingADD((ulonglong)(uint)param_1[7],(ulonglong)*(uint *)(param_7 + 1));
    param_1[6] = uVar16;
    *(int *)(param_1 + 7) = (int)uVar4;
  }
  FastExitMediaState();
  return;
}


// ==== 0x5f351d FUN_005f351d

void FUN_005f351d(undefined8 *param_1,undefined4 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 in_MM4;
  undefined8 uVar8;
  undefined4 uVar10;
  undefined8 uVar9;
  undefined8 in_MM5;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 in_MM6;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 in_MM7;
  undefined8 uVar17;
  undefined4 uStack_2c;
  
  uVar2 = param_3[2];
  uVar3 = param_3[4];
  uVar11 = PackedSwapDWords(in_MM5,uVar2);
  uVar8 = PackedSwapDWords(in_MM4,uVar3);
  uVar1 = *param_3;
  uVar14 = PackedSwapDWords(in_MM6,param_3[6]);
  uVar17 = PackedSwapDWords(in_MM7,uVar3);
  uVar11 = PackedFloatingMUL(uVar11,uVar1);
  uVar8 = PackedFloatingMUL(uVar8,uVar1);
  uVar14 = PackedFloatingMUL(uVar14,uVar1);
  uVar1 = PackedSwapDWords(uVar1,param_3[6]);
  uVar17 = PackedFloatingMUL(uVar17,uVar2);
  uVar12 = PackedFloatingNegAccumulate(uVar11,uVar8);
  uVar2 = PackedFloatingMUL(uVar2,uVar1);
  uVar3 = PackedFloatingMUL(uVar3,uVar1);
  uVar17 = PackedFloatingNegAccumulate(uVar14,uVar17);
  uVar1 = PackedFloatingNegAccumulate(uVar2,uVar3);
  uVar2 = param_3[7];
  uVar3 = param_3[5];
  uVar4 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar10 = (undefined4)((ulonglong)uVar1 >> 0x20);
  uVar8 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar2);
  uVar6 = (undefined4)uVar1;
  uVar1 = PackedFloatingMUL(CONCAT44(uVar10,uVar10),param_3[3]);
  uVar11 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),uVar3);
  uVar1 = PackedFloatingADD(uVar8,uVar1);
  uVar14 = PackedFloatingSUB(uVar1,uVar11);
  uVar7 = (undefined4)uVar17;
  uVar5 = (undefined4)((ulonglong)uVar12 >> 0x20);
  uVar8 = PackedFloatingMUL(CONCAT44(uVar10,uVar10),param_3[1]);
  uVar1 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),uVar2);
  uVar9 = PackedFloatingMUL(CONCAT44(uVar7,uVar7),uVar3);
  uVar1 = PackedFloatingSUB(uVar1,uVar9);
  uVar17 = PackedFloatingADD(uVar1,uVar8);
  uVar8 = CONCAT44((int)uVar12,(int)uVar12);
  uVar1 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),param_3[1]);
  uVar2 = PackedFloatingMUL(uVar2,uVar8);
  uVar11 = PackedFloatingMUL(CONCAT44(uVar7,uVar7),param_3[3]);
  uVar2 = PackedFloatingADD(uVar2,uVar1);
  uVar11 = PackedFloatingSUB(uVar2,uVar11);
  uVar1 = PackedFloatingMUL(uVar8,uVar3);
  uVar13 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),param_3[3]);
  uVar2 = param_3[1];
  uVar15 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),param_3[1]);
  uVar1 = PackedFloatingSUB(uVar1,uVar13);
  uVar12 = PackedFloatingADD(uVar1,uVar15);
  uVar1 = param_3[3];
  uVar8 = param_3[5];
  uVar13 = PackedSwapDWords(uVar13,uVar1);
  uVar9 = PackedSwapDWords(uVar9,uVar8);
  uVar13 = PackedFloatingMUL(uVar13,uVar2);
  uVar15 = PackedSwapDWords(uVar15,param_3[7]);
  uVar9 = PackedFloatingMUL(uVar9,uVar2);
  uVar3 = PackedSwapDWords(uVar3,uVar8);
  uVar16 = PackedFloatingMUL(uVar15,uVar2);
  uVar2 = PackedSwapDWords(uVar2,param_3[7]);
  uVar15 = PackedFloatingNegAccumulate(uVar13,uVar9);
  uVar9 = PackedFloatingMUL(uVar3,uVar1);
  uVar3 = PackedFloatingMUL(uVar1,uVar2);
  uVar2 = PackedFloatingMUL(uVar8,uVar2);
  uVar13 = PackedFloatingNegAccumulate(uVar16,uVar9);
  uVar1 = PackedFloatingNegAccumulate(uVar3,uVar2);
  uVar2 = param_3[6];
  uVar3 = param_3[4];
  uVar10 = (undefined4)((ulonglong)uVar1 >> 0x20);
  uVar6 = (undefined4)uVar1;
  uVar4 = (undefined4)((ulonglong)uVar13 >> 0x20);
  uVar9 = PackedFloatingMUL(CONCAT44(uVar10,uVar10),param_3[2]);
  uVar1 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar2);
  uVar8 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),uVar3);
  uVar1 = PackedFloatingADD(uVar1,uVar9);
  uVar9 = PackedFloatingSUB(uVar1,uVar8);
  uVar7 = (undefined4)uVar13;
  uVar5 = (undefined4)((ulonglong)uVar15 >> 0x20);
  uVar8 = PackedFloatingMUL(CONCAT44(uVar10,uVar10),*param_3);
  uVar1 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),uVar2);
  uVar13 = PackedFloatingMUL(CONCAT44(uVar7,uVar7),uVar3);
  uVar1 = PackedFloatingSUB(uVar1,uVar13);
  uVar13 = PackedFloatingADD(uVar1,uVar8);
  uVar15 = CONCAT44((int)uVar15,(int)uVar15);
  uVar8 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),*param_3);
  uVar1 = PackedFloatingMUL(uVar2,uVar15);
  uVar16 = PackedFloatingMUL(CONCAT44(uVar7,uVar7),param_3[2]);
  uVar1 = PackedFloatingADD(uVar1,uVar8);
  uVar1 = PackedFloatingSUB(uVar1,uVar16);
  uVar8 = PackedFloatingMUL(uVar15,uVar3);
  uVar15 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),param_3[2]);
  uVar16 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),*param_3);
  uVar8 = PackedFloatingSUB(uVar8,uVar15);
  uVar15 = PackedFloatingADD(uVar8,uVar16);
  uStack_2c = (undefined4)((ulonglong)uVar13 >> 0x20);
  uVar8 = CONCAT44(uStack_2c,(int)((ulonglong)uVar9 >> 0x20));
  uVar2 = PackedFloatingMUL(CONCAT44((int)((ulonglong)uVar15 >> 0x20),
                                     (int)((ulonglong)uVar1 >> 0x20)),
                            CONCAT44((int)uVar2,(int)uVar3));
  uVar3 = PackedFloatingMUL(CONCAT44(*(undefined4 *)(param_3 + 2),(int)*param_3),uVar8);
  uVar2 = PackedFloatingNegAccumulate(uVar2,uVar3);
  uVar2 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar4 = (undefined4)uVar2;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = uVar4;
  }
  uVar3 = FloatingReciprocalAprox(uVar8,uVar2);
  uVar8 = PackedFloatingCompareEQ(0,uVar2);
  uVar2 = PackedFloatingReciprocalIter1(CONCAT44(uVar4,uVar4),uVar3);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar3);
  uVar2 = PackedFloatingMUL(uVar2,0xbf8000003f800000);
  uVar3 = PackedSwapDWords(uVar3,uVar2);
  if ((int)uVar8 == 0) {
    uVar8 = PackedFloatingMUL(uVar9,uVar3);
    uVar9 = PackedFloatingMUL(uVar13,uVar2);
    uVar14 = PackedFloatingMUL(uVar14,uVar3);
    uVar17 = PackedFloatingMUL(uVar17,uVar2);
    *param_1 = CONCAT44((int)((ulonglong)uVar9 >> 0x20),(int)((ulonglong)uVar8 >> 0x20));
    param_1[2] = CONCAT44((int)uVar9,(int)uVar8);
    param_1[4] = CONCAT44((int)((ulonglong)uVar17 >> 0x20),(int)((ulonglong)uVar14 >> 0x20));
    param_1[6] = CONCAT44((int)uVar17,(int)uVar14);
    uVar1 = PackedFloatingMUL(uVar1,uVar3);
    uVar8 = PackedFloatingMUL(uVar15,uVar2);
    uVar3 = PackedFloatingMUL(uVar11,uVar3);
    uVar2 = PackedFloatingMUL(uVar12,uVar2);
    param_1[1] = CONCAT44((int)((ulonglong)uVar8 >> 0x20),(int)((ulonglong)uVar1 >> 0x20));
    param_1[3] = CONCAT44((int)uVar8,(int)uVar1);
    param_1[5] = CONCAT44((int)((ulonglong)uVar2 >> 0x20),(int)((ulonglong)uVar3 >> 0x20));
    param_1[7] = CONCAT44((int)uVar2,(int)uVar3);
  }
  FastExitMediaState();
  return;
}


// ==== 0x5f37ff FUN_005f37ff

void FUN_005f37ff(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  
  FastExitMediaState();
  uVar2 = CONCAT44((int)param_3[2],(int)*param_3);
  uVar11 = CONCAT44((int)((ulonglong)param_3[2] >> 0x20),(int)((ulonglong)*param_3 >> 0x20));
  uVar15 = CONCAT44((int)param_3[7],(int)param_3[5]);
  uVar16 = CONCAT44((int)((ulonglong)param_3[7] >> 0x20),(int)((ulonglong)param_3[5] >> 0x20));
  uVar12 = CONCAT44((int)param_3[3],(int)param_3[1]);
  uVar13 = CONCAT44((int)((ulonglong)param_3[3] >> 0x20),(int)((ulonglong)param_3[1] >> 0x20));
  uVar5 = CONCAT44((int)((ulonglong)param_3[6] >> 0x20),(int)((ulonglong)param_3[4] >> 0x20));
  uVar4 = CONCAT44((int)param_3[6],(int)param_3[4]);
  if (param_2 != param_1) {
    uVar1 = PackedFloatingMUL(uVar2,*param_2);
    uVar3 = PackedFloatingMUL(uVar4,param_2[1]);
    uVar6 = PackedFloatingMUL(uVar2,param_2[2]);
    uVar7 = PackedFloatingMUL(uVar4,param_2[3]);
    uVar8 = PackedFloatingMUL(uVar2,param_2[4]);
    uVar9 = PackedFloatingMUL(uVar4,param_2[5]);
    uVar10 = PackedFloatingMUL(uVar2,param_2[6]);
    uVar14 = PackedFloatingMUL(uVar4,param_2[7]);
    uVar2 = PackedFloatingAccumulate(uVar1,uVar6);
    uVar4 = PackedFloatingAccumulate(uVar3,uVar7);
    uVar1 = PackedFloatingAccumulate(uVar8,uVar10);
    uVar3 = PackedFloatingAccumulate(uVar9,uVar14);
    uVar2 = PackedFloatingADD(uVar2,uVar4);
    uVar4 = PackedFloatingADD(uVar1,uVar3);
    *param_1 = uVar2;
    param_1[1] = uVar4;
    uVar2 = PackedFloatingMUL(uVar11,*param_2);
    uVar4 = PackedFloatingMUL(uVar5,param_2[1]);
    uVar1 = PackedFloatingMUL(uVar11,param_2[2]);
    uVar3 = PackedFloatingMUL(uVar5,param_2[3]);
    uVar6 = PackedFloatingMUL(uVar11,param_2[4]);
    uVar7 = PackedFloatingMUL(uVar5,param_2[5]);
    uVar11 = PackedFloatingMUL(uVar11,param_2[6]);
    uVar8 = PackedFloatingMUL(uVar5,param_2[7]);
    uVar2 = PackedFloatingAccumulate(uVar2,uVar1);
    uVar5 = PackedFloatingAccumulate(uVar4,uVar3);
    uVar11 = PackedFloatingAccumulate(uVar6,uVar11);
    uVar4 = PackedFloatingAccumulate(uVar7,uVar8);
    uVar2 = PackedFloatingADD(uVar2,uVar5);
    uVar5 = PackedFloatingADD(uVar11,uVar4);
    param_1[2] = uVar2;
    param_1[3] = uVar5;
    uVar2 = PackedFloatingMUL(uVar12,*param_2);
    uVar5 = PackedFloatingMUL(uVar15,param_2[1]);
    uVar11 = PackedFloatingMUL(uVar12,param_2[2]);
    uVar4 = PackedFloatingMUL(uVar15,param_2[3]);
    uVar1 = PackedFloatingMUL(uVar12,param_2[4]);
    uVar3 = PackedFloatingMUL(uVar15,param_2[5]);
    uVar12 = PackedFloatingMUL(uVar12,param_2[6]);
    uVar15 = PackedFloatingMUL(uVar15,param_2[7]);
    uVar2 = PackedFloatingAccumulate(uVar2,uVar11);
    uVar5 = PackedFloatingAccumulate(uVar5,uVar4);
    uVar11 = PackedFloatingAccumulate(uVar1,uVar12);
    uVar4 = PackedFloatingAccumulate(uVar3,uVar15);
    uVar2 = PackedFloatingADD(uVar2,uVar5);
    uVar5 = PackedFloatingADD(uVar11,uVar4);
    param_1[4] = uVar2;
    param_1[5] = uVar5;
    uVar2 = PackedFloatingMUL(uVar13,*param_2);
    uVar5 = PackedFloatingMUL(uVar16,param_2[1]);
    uVar11 = PackedFloatingMUL(uVar13,param_2[2]);
    uVar4 = PackedFloatingMUL(uVar16,param_2[3]);
    uVar15 = PackedFloatingMUL(uVar13,param_2[4]);
    uVar12 = PackedFloatingMUL(uVar16,param_2[5]);
    uVar13 = PackedFloatingMUL(uVar13,param_2[6]);
    uVar16 = PackedFloatingMUL(uVar16,param_2[7]);
    uVar2 = PackedFloatingAccumulate(uVar2,uVar11);
    uVar5 = PackedFloatingAccumulate(uVar5,uVar4);
    uVar13 = PackedFloatingAccumulate(uVar15,uVar13);
    uVar11 = PackedFloatingAccumulate(uVar12,uVar16);
    uVar2 = PackedFloatingADD(uVar2,uVar5);
    uVar5 = PackedFloatingADD(uVar13,uVar11);
    param_1[6] = uVar2;
    param_1[7] = uVar5;
    FastExitMediaState();
    return;
  }
  uVar1 = PackedFloatingMUL(uVar2,*param_2);
  uVar3 = PackedFloatingMUL(uVar4,param_2[1]);
  uVar6 = PackedFloatingMUL(uVar2,param_2[2]);
  uVar7 = PackedFloatingMUL(uVar4,param_2[3]);
  uVar8 = PackedFloatingMUL(uVar2,param_2[4]);
  uVar9 = PackedFloatingMUL(uVar4,param_2[5]);
  uVar10 = PackedFloatingMUL(uVar2,param_2[6]);
  uVar14 = PackedFloatingMUL(uVar4,param_2[7]);
  uVar2 = PackedFloatingAccumulate(uVar1,uVar6);
  uVar4 = PackedFloatingAccumulate(uVar3,uVar7);
  uVar1 = PackedFloatingAccumulate(uVar8,uVar10);
  uVar3 = PackedFloatingAccumulate(uVar9,uVar14);
  uVar2 = PackedFloatingADD(uVar2,uVar4);
  uVar7 = PackedFloatingADD(uVar1,uVar3);
  uVar4 = PackedFloatingMUL(uVar11,*param_2);
  uVar1 = PackedFloatingMUL(uVar5,param_2[1]);
  uVar3 = PackedFloatingMUL(uVar11,param_2[2]);
  uVar6 = PackedFloatingMUL(uVar5,param_2[3]);
  uVar8 = PackedFloatingMUL(uVar11,param_2[4]);
  uVar9 = PackedFloatingMUL(uVar5,param_2[5]);
  uVar10 = PackedFloatingMUL(uVar11,param_2[6]);
  uVar14 = PackedFloatingMUL(uVar5,param_2[7]);
  uVar5 = PackedFloatingAccumulate(uVar4,uVar3);
  uVar11 = PackedFloatingAccumulate(uVar1,uVar6);
  uVar4 = PackedFloatingAccumulate(uVar8,uVar10);
  uVar1 = PackedFloatingAccumulate(uVar9,uVar14);
  uVar5 = PackedFloatingADD(uVar5,uVar11);
  uVar6 = PackedFloatingADD(uVar4,uVar1);
  uVar11 = PackedFloatingMUL(uVar12,*param_2);
  uVar4 = PackedFloatingMUL(uVar15,param_2[1]);
  uVar1 = PackedFloatingMUL(uVar12,param_2[2]);
  uVar3 = PackedFloatingMUL(uVar15,param_2[3]);
  uVar8 = PackedFloatingMUL(uVar12,param_2[4]);
  uVar9 = PackedFloatingMUL(uVar15,param_2[5]);
  uVar12 = PackedFloatingMUL(uVar12,param_2[6]);
  uVar10 = PackedFloatingMUL(uVar15,param_2[7]);
  uVar11 = PackedFloatingAccumulate(uVar11,uVar1);
  uVar4 = PackedFloatingAccumulate(uVar4,uVar3);
  uVar15 = PackedFloatingAccumulate(uVar8,uVar12);
  uVar12 = PackedFloatingAccumulate(uVar9,uVar10);
  uVar11 = PackedFloatingADD(uVar11,uVar4);
  uVar3 = PackedFloatingADD(uVar15,uVar12);
  uVar4 = PackedFloatingMUL(uVar13,*param_2);
  uVar15 = PackedFloatingMUL(uVar16,param_2[1]);
  uVar12 = PackedFloatingMUL(uVar13,param_2[2]);
  uVar1 = PackedFloatingMUL(uVar16,param_2[3]);
  uVar8 = PackedFloatingMUL(uVar13,param_2[4]);
  uVar9 = PackedFloatingMUL(uVar16,param_2[5]);
  uVar10 = PackedFloatingMUL(uVar13,param_2[6]);
  uVar16 = PackedFloatingMUL(uVar16,param_2[7]);
  uVar13 = PackedFloatingAccumulate(uVar4,uVar12);
  uVar4 = PackedFloatingAccumulate(uVar15,uVar1);
  uVar15 = PackedFloatingAccumulate(uVar8,uVar10);
  uVar16 = PackedFloatingAccumulate(uVar9,uVar16);
  uVar13 = PackedFloatingADD(uVar13,uVar4);
  uVar4 = PackedFloatingADD(uVar15,uVar16);
  param_1[6] = uVar13;
  param_1[7] = uVar4;
  *param_1 = uVar2;
  param_1[1] = uVar7;
  param_1[2] = uVar5;
  param_1[3] = uVar6;
  param_1[4] = uVar11;
  param_1[5] = uVar3;
  FastExitMediaState();
  return;
}


// ==== 0x5f3bf7 FUN_005f3bf7

undefined8 * FUN_005f3bf7(undefined8 *param_1,undefined4 *param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 uVar4;
  undefined8 uVar3;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  undefined4 uVar11;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined4 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined4 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined4 uVar21;
  undefined8 uVar20;
  undefined4 uStack_34;
  
  uVar11 = (undefined4)((ulonglong)*param_3 >> 0x20);
  uVar2 = (undefined4)param_3[4];
  uVar16 = (undefined4)param_3[2];
  uVar12 = (undefined4)*param_3;
  uVar21 = (undefined4)((ulonglong)param_3[2] >> 0x20);
  uVar4 = (undefined4)((ulonglong)param_3[4] >> 0x20);
  uVar9 = PackedFloatingMUL(CONCAT44(uVar11,uVar11),CONCAT44(uVar2,uVar16));
  uVar13 = PackedFloatingMUL(CONCAT44(uVar12,uVar12),CONCAT44(uVar4,uVar21));
  uVar14 = PackedFloatingSUB(uVar13,uVar9);
  uVar5 = (undefined4)((ulonglong)param_3[6] >> 0x20);
  uVar8 = (undefined4)param_3[6];
  uVar17 = PackedFloatingMUL(CONCAT44(uVar4,uVar5),CONCAT44(uVar16,uVar12));
  uVar20 = PackedFloatingMUL(CONCAT44(uVar21,uVar11),CONCAT44(uVar2,uVar8));
  uVar9 = PackedFloatingMUL(CONCAT44(uVar2,uVar16),CONCAT44(uVar5,uVar5));
  uVar13 = PackedFloatingMUL(CONCAT44(uVar4,uVar21),CONCAT44(uVar8,uVar8));
  uVar18 = PackedFloatingSUB(uVar17,uVar20);
  uVar17 = PackedFloatingSUBR(uVar13,uVar9);
  uVar9 = param_3[7];
  uVar13 = param_3[5];
  uVar2 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar11 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar20 = PackedFloatingMUL(CONCAT44(uVar2,uVar2),uVar9);
  uVar5 = (undefined4)uVar17;
  uVar17 = PackedFloatingMUL(CONCAT44(uVar11,uVar11),param_3[3]);
  uVar6 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),uVar13);
  uVar17 = PackedFloatingADD(uVar20,uVar17);
  uVar3 = PackedFloatingSUB(uVar17,uVar6);
  uVar8 = (undefined4)uVar18;
  uVar4 = (undefined4)((ulonglong)uVar14 >> 0x20);
  uVar20 = PackedFloatingMUL(CONCAT44(uVar11,uVar11),param_3[1]);
  uVar17 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar9);
  uVar6 = PackedFloatingMUL(CONCAT44(uVar8,uVar8),uVar13);
  uVar17 = PackedFloatingSUB(uVar17,uVar6);
  uVar18 = PackedFloatingADD(uVar17,uVar20);
  uVar20 = CONCAT44((int)uVar14,(int)uVar14);
  uVar17 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),param_3[1]);
  uVar9 = PackedFloatingMUL(uVar9,uVar20);
  uVar6 = PackedFloatingMUL(CONCAT44(uVar8,uVar8),param_3[3]);
  uVar9 = PackedFloatingADD(uVar9,uVar17);
  uVar17 = PackedFloatingSUB(uVar9,uVar6);
  uVar9 = PackedFloatingMUL(uVar20,uVar13);
  uVar13 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),param_3[3]);
  uVar20 = PackedFloatingMUL(CONCAT44(uVar2,uVar2),param_3[1]);
  uVar9 = PackedFloatingSUB(uVar9,uVar13);
  uVar14 = PackedFloatingADD(uVar9,uVar20);
  uVar11 = (undefined4)((ulonglong)param_3[1] >> 0x20);
  uVar2 = (undefined4)param_3[5];
  uVar16 = (undefined4)param_3[3];
  uVar12 = (undefined4)param_3[1];
  uVar21 = (undefined4)((ulonglong)param_3[3] >> 0x20);
  uVar4 = (undefined4)((ulonglong)param_3[5] >> 0x20);
  uVar9 = PackedFloatingMUL(CONCAT44(uVar11,uVar11),CONCAT44(uVar2,uVar16));
  uVar13 = PackedFloatingMUL(CONCAT44(uVar12,uVar12),CONCAT44(uVar4,uVar21));
  uVar15 = PackedFloatingSUB(uVar13,uVar9);
  uVar5 = (undefined4)((ulonglong)param_3[7] >> 0x20);
  uVar8 = (undefined4)param_3[7];
  uVar20 = PackedFloatingMUL(CONCAT44(uVar4,uVar5),CONCAT44(uVar16,uVar12));
  uVar6 = PackedFloatingMUL(CONCAT44(uVar21,uVar11),CONCAT44(uVar2,uVar8));
  uVar9 = PackedFloatingMUL(CONCAT44(uVar2,uVar16),CONCAT44(uVar5,uVar5));
  uVar13 = PackedFloatingMUL(CONCAT44(uVar4,uVar21),CONCAT44(uVar8,uVar8));
  uVar19 = PackedFloatingSUB(uVar20,uVar6);
  uVar20 = PackedFloatingSUBR(uVar13,uVar9);
  uVar9 = param_3[6];
  uVar13 = param_3[4];
  uVar11 = (undefined4)((ulonglong)uVar20 >> 0x20);
  uVar5 = (undefined4)uVar20;
  uVar2 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar10 = PackedFloatingMUL(CONCAT44(uVar11,uVar11),param_3[2]);
  uVar20 = PackedFloatingMUL(CONCAT44(uVar2,uVar2),uVar9);
  uVar6 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),uVar13);
  uVar20 = PackedFloatingADD(uVar20,uVar10);
  uVar10 = PackedFloatingSUB(uVar20,uVar6);
  uVar8 = (undefined4)uVar19;
  uVar4 = (undefined4)((ulonglong)uVar15 >> 0x20);
  uVar6 = PackedFloatingMUL(CONCAT44(uVar11,uVar11),*param_3);
  uVar20 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),uVar9);
  uVar19 = PackedFloatingMUL(CONCAT44(uVar8,uVar8),uVar13);
  uVar20 = PackedFloatingSUB(uVar20,uVar19);
  uVar19 = PackedFloatingADD(uVar20,uVar6);
  uVar15 = CONCAT44((int)uVar15,(int)uVar15);
  uVar6 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),*param_3);
  uVar20 = PackedFloatingMUL(uVar9,uVar15);
  uVar7 = PackedFloatingMUL(CONCAT44(uVar8,uVar8),param_3[2]);
  uVar20 = PackedFloatingADD(uVar20,uVar6);
  uVar20 = PackedFloatingSUB(uVar20,uVar7);
  uVar6 = PackedFloatingMUL(uVar15,uVar13);
  uVar15 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),param_3[2]);
  uVar7 = PackedFloatingMUL(CONCAT44(uVar2,uVar2),*param_3);
  uVar6 = PackedFloatingSUB(uVar6,uVar15);
  uVar6 = PackedFloatingADD(uVar6,uVar7);
  uVar9 = PackedFloatingMUL(CONCAT44((int)uVar9,(int)uVar13),0xbf8000003f800000);
  uStack_34 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar13 = CONCAT44(uStack_34,(int)((ulonglong)uVar10 >> 0x20));
  uVar15 = PackedFloatingMUL(CONCAT44(*(undefined4 *)(param_3 + 2),(int)*param_3),0xbf8000003f800000
                            );
  uVar9 = PackedFloatingMUL(CONCAT44((int)((ulonglong)uVar6 >> 0x20),
                                     (int)((ulonglong)uVar20 >> 0x20)),uVar9);
  uVar15 = PackedFloatingMUL(uVar15,uVar13);
  uVar9 = PackedFloatingADD(uVar9,uVar15);
  uVar9 = PackedFloatingAccumulate(uVar9,uVar9);
  uVar2 = (undefined4)uVar9;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = uVar2;
  }
  uVar13 = FloatingReciprocalAprox(uVar13,uVar9);
  uVar15 = PackedFloatingCompareEQ(0,uVar9);
  uVar9 = PackedFloatingReciprocalIter1(CONCAT44(uVar2,uVar2),uVar13);
  uVar9 = PackedFloatingReciprocalIter2(uVar9,uVar13);
  uVar13 = PackedFloatingMUL(uVar9,0xbf8000003f800000);
  uVar9 = CONCAT44((int)uVar13,(int)((ulonglong)uVar13 >> 0x20));
  puVar1 = (undefined8 *)uVar15;
  if ((undefined8 *)uVar15 == (undefined8 *)0x0) {
    uVar10 = PackedFloatingMUL(uVar10,uVar9);
    uVar19 = PackedFloatingMUL(uVar19,uVar13);
    uVar3 = PackedFloatingMUL(uVar3,uVar9);
    uVar18 = PackedFloatingMUL(uVar18,uVar13);
    *param_1 = CONCAT44((int)((ulonglong)uVar19 >> 0x20),(int)((ulonglong)uVar10 >> 0x20));
    param_1[2] = CONCAT44((int)uVar19,(int)uVar10);
    param_1[4] = CONCAT44((int)((ulonglong)uVar18 >> 0x20),(int)((ulonglong)uVar3 >> 0x20));
    param_1[6] = CONCAT44((int)uVar18,(int)uVar3);
    uVar20 = PackedFloatingMUL(uVar20,uVar9);
    uVar6 = PackedFloatingMUL(uVar6,uVar13);
    uVar9 = PackedFloatingMUL(uVar17,uVar9);
    uVar13 = PackedFloatingMUL(uVar14,uVar13);
    param_1[1] = CONCAT44((int)((ulonglong)uVar6 >> 0x20),(int)((ulonglong)uVar20 >> 0x20));
    param_1[3] = CONCAT44((int)uVar6,(int)uVar20);
    param_1[5] = CONCAT44((int)((ulonglong)uVar13 >> 0x20),(int)((ulonglong)uVar9 >> 0x20));
    param_1[7] = CONCAT44((int)uVar13,(int)uVar9);
    puVar1 = param_1;
  }
  return puVar1;
}


// ==== 0x5f3f2b FUN_005f3f2b

undefined4 FUN_005f3f2b(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FastExitMediaState();
  FUN_005f3bf7(param_1,param_2,param_3);
  FastExitMediaState();
  return param_1;
}


// ==== 0x5f3f47 FUN_005f3f47

undefined8 * FUN_005f3f47(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  FastExitMediaState();
  uVar1 = (undefined4)*param_2;
  uVar4 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)((ulonglong)*param_2 >> 0x20);
  uVar7 = CONCAT44(uVar1,uVar1);
  uVar8 = CONCAT44(*(undefined4 *)(param_2 + 1),*(undefined4 *)(param_2 + 1));
  uVar2 = PackedFloatingMUL(uVar4,*param_3);
  uVar3 = PackedFloatingMUL(uVar7,param_3[2]);
  uVar5 = PackedFloatingMUL(uVar8,param_3[4]);
  uVar2 = PackedFloatingADD(uVar2,param_3[6]);
  uVar6 = PackedFloatingMUL(uVar4,param_3[1]);
  uVar4 = PackedFloatingADD(uVar3,uVar5);
  uVar3 = PackedFloatingMUL(uVar7,param_3[3]);
  uVar8 = PackedFloatingMUL(uVar8,param_3[5]);
  uVar7 = PackedFloatingADD(uVar6,param_3[7]);
  uVar4 = PackedFloatingADD(uVar2,uVar4);
  uVar2 = PackedFloatingADD(uVar3,uVar8);
  uVar2 = PackedFloatingADD(uVar7,uVar2);
  *param_1 = uVar4;
  param_1[1] = uVar2;
  FastExitMediaState();
  return param_1;
}


// ==== 0x5f3fb8 FUN_005f3fb8

undefined8 * FUN_005f3fb8(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  FastExitMediaState();
  uVar1 = (undefined4)*param_2;
  uVar4 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)((ulonglong)*param_2 >> 0x20);
  uVar8 = CONCAT44(uVar1,uVar1);
  uVar5 = CONCAT44(*(undefined4 *)(param_2 + 1),*(undefined4 *)(param_2 + 1));
  uVar2 = PackedFloatingMUL(uVar4,*param_3);
  uVar3 = PackedFloatingMUL(uVar8,param_3[2]);
  uVar6 = PackedFloatingMUL(uVar5,param_3[4]);
  uVar7 = PackedFloatingMUL(uVar4,param_3[1]);
  uVar4 = PackedFloatingADD(uVar3,uVar6);
  uVar8 = PackedFloatingMUL(uVar8,param_3[3]);
  uVar3 = PackedFloatingMUL(uVar5,param_3[5]);
  uVar4 = PackedFloatingADD(uVar2,uVar4);
  uVar2 = PackedFloatingADD(uVar8,uVar3);
  uVar2 = PackedFloatingADD(uVar7,uVar2);
  *param_1 = uVar4;
  *(int *)(param_1 + 1) = (int)uVar2;
  FastExitMediaState();
  return param_1;
}


// ==== 0x5f401f FUN_005f401f

void FUN_005f401f(undefined8 *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 in_MM4;
  undefined8 uVar5;
  ulonglong uVar6;
  
  FastExitMediaState();
  uVar1 = *param_2;
  uVar3 = (ulonglong)(uint)param_2[1];
  uVar2 = PackedFloatingMUL(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar3,uVar3);
  uVar2 = PackedFloatingADD(uVar2,uVar4);
  uVar2 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar5 = PackedFloatingReciprocalSQRAprox(in_MM4,uVar2);
  uVar6 = PackedFloatingCompareGT(uVar2,0x80000000800000);
  uVar4 = PackedFloatingMUL(uVar5,uVar5);
  uVar2 = PackedFloatingReciprocalSQRIter1(uVar2,uVar4);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar5);
  uVar4 = PackedFloatingMUL(uVar1 & uVar6,uVar2);
  uVar2 = PackedFloatingMUL(uVar3 & uVar6,uVar2);
  *param_1 = uVar4;
  *(int *)(param_1 + 1) = (int)uVar2;
  FastExitMediaState();
  return;
}


// ==== 0x5f407e FUN_005f407e

void FUN_005f407e(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  
  uVar2 = *param_2;
  uVar6 = (ulonglong)*(uint *)(param_2 + 1);
  uVar1 = PackedFloatingSUB(*param_3,uVar2);
  uVar3 = PackedFloatingSUB((ulonglong)*(uint *)(param_3 + 1),uVar6);
  uVar4 = PackedFloatingSUB(*param_4,uVar2);
  uVar5 = PackedFloatingSUB((ulonglong)*(uint *)(param_4 + 1),uVar6);
  uVar1 = PackedFloatingMUL(uVar1,CONCAT44(param_5,param_5));
  uVar3 = PackedFloatingMUL(uVar3,CONCAT44(param_5,param_5));
  uVar2 = PackedFloatingADD(uVar1,uVar2);
  uVar4 = PackedFloatingMUL(uVar4,CONCAT44(param_6,param_6));
  uVar1 = PackedFloatingADD(uVar3,uVar6);
  uVar3 = PackedFloatingMUL(uVar5,CONCAT44(param_6,param_6));
  uVar2 = PackedFloatingADD(uVar2,uVar4);
  uVar1 = PackedFloatingADD(uVar1,uVar3);
  *param_1 = uVar2;
  *(int *)(param_1 + 1) = (int)uVar1;
  FastExitMediaState();
  return;
}


// ==== 0x5f40ef FUN_005f40ef

void FUN_005f40ef(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                 undefined8 *param_5,uint param_6)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  FastExitMediaState();
  uVar1 = (ulonglong)param_6;
  uVar2 = PackedFloatingMUL(uVar1,uVar1);
  uVar3 = PackedFloatingMUL(uVar2,uVar1);
  uVar8 = PackedFloatingSUB(uVar3,uVar2);
  uVar5 = PackedFloatingMUL(uVar2,0x4000000040000000);
  uVar2 = PackedFloatingMUL(uVar2,0x4040000040400000);
  uVar4 = PackedFloatingMUL(uVar3,0x4000000040000000);
  uVar5 = PackedFloatingSUB(uVar3,uVar5);
  uVar3 = PackedFloatingSUB(uVar2,uVar4);
  uVar5 = PackedFloatingADD(uVar5,uVar1);
  uVar2 = PackedFloatingSUB(uVar4,uVar2);
  uVar4 = PackedFloatingADD(uVar2,0x3f8000003f800000);
  uVar6 = CONCAT44((int)uVar8,(int)uVar8);
  uVar2 = CONCAT44((int)uVar3,(int)uVar3);
  uVar8 = CONCAT44((int)uVar5,(int)uVar5);
  uVar4 = CONCAT44((int)uVar4,(int)uVar4);
  uVar9 = PackedFloatingMUL(uVar6,*param_5);
  uVar3 = PackedFloatingMUL(uVar2,*param_4);
  uVar5 = PackedFloatingMUL(uVar6,(ulonglong)*(uint *)(param_5 + 1));
  uVar2 = PackedFloatingMUL(uVar2,(ulonglong)*(uint *)(param_4 + 1));
  uVar7 = PackedFloatingMUL(uVar8,*param_3);
  uVar3 = PackedFloatingADD(uVar3,uVar9);
  uVar2 = PackedFloatingADD(uVar2,uVar5);
  uVar5 = PackedFloatingMUL(uVar4,*param_2);
  uVar6 = PackedFloatingMUL(uVar8,(ulonglong)*(uint *)(param_3 + 1));
  uVar8 = PackedFloatingMUL(uVar4,(ulonglong)*(uint *)(param_2 + 1));
  uVar4 = PackedFloatingADD(uVar5,uVar7);
  uVar5 = PackedFloatingADD(uVar8,uVar6);
  uVar3 = PackedFloatingADD(uVar3,uVar4);
  uVar2 = PackedFloatingADD(uVar2,uVar5);
  *param_1 = uVar3;
  *(int *)(param_1 + 1) = (int)uVar2;
  FastExitMediaState();
  return;
}


// ==== 0x5f41c3 FUN_005f41c3

void FUN_005f41c3(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                 undefined8 *param_5,undefined4 param_6)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  uVar1 = PackedFloatingMUL(CONCAT44(param_6,param_6),CONCAT44(param_6,param_6));
  uVar3 = CONCAT44(0x3f800000,param_6);
  uVar1 = PackedFloatingMUL(uVar1,uVar3);
  uVar3 = PackedFloatingMUL(uVar3,uVar3);
  uVar1 = PackedFloatingSUB(uVar1,uVar3);
  uVar2 = PackedFloatingMUL(uVar1,0x4000000040400000);
  uVar1 = CONCAT44((int)uVar1,(int)uVar2);
  uVar3 = PackedFloatingADD(CONCAT44((int)uVar3,(int)uVar3),
                            CONCAT44(param_6,param_6) ^ 0x8000000000000000);
  uVar4 = PackedFloatingSUB(uVar3,uVar1);
  uVar1 = PackedFloatingSUB(uVar1,uVar2 >> 0x20);
  uVar5 = (undefined4)((ulonglong)uVar4 >> 0x20);
  uVar8 = CONCAT44(uVar5,uVar5);
  uVar3 = CONCAT44((int)uVar1,(int)uVar1);
  uVar9 = CONCAT44((int)uVar4,(int)uVar4);
  uVar4 = PackedFloatingMUL(uVar8,*param_2);
  uVar5 = (undefined4)((ulonglong)uVar1 >> 0x20);
  uVar7 = CONCAT44(uVar5,uVar5);
  uVar1 = PackedFloatingMUL(uVar3,*param_3);
  uVar6 = PackedFloatingMUL(uVar9,*param_4);
  uVar8 = PackedFloatingMUL(uVar8,(ulonglong)*(uint *)(param_2 + 1));
  uVar3 = PackedFloatingMUL(uVar3,(ulonglong)*(uint *)(param_3 + 1));
  uVar1 = PackedFloatingADD(uVar1,uVar4);
  uVar9 = PackedFloatingMUL(uVar9,(ulonglong)*(uint *)(param_4 + 1));
  uVar4 = PackedFloatingADD(uVar8,uVar3);
  uVar1 = PackedFloatingADD(uVar1,uVar6);
  uVar3 = PackedFloatingMUL(uVar7,*param_5);
  uVar1 = PackedFloatingADD(uVar1,uVar3);
  uVar8 = PackedFloatingMUL(uVar7,(ulonglong)*(uint *)(param_5 + 1));
  uVar3 = PackedFloatingADD(uVar4,uVar9);
  uVar1 = PackedFloatingMUL(uVar1,0x3f0000003f000000);
  uVar3 = PackedFloatingADD(uVar3,uVar8);
  *param_1 = uVar1;
  uVar1 = PackedFloatingMUL(uVar3,0x3f0000003f000000);
  *(int *)(param_1 + 1) = (int)uVar1;
  FastExitMediaState();
  return;
}


// ==== 0x5f42ad FUN_005f42ad

undefined8 * FUN_005f42ad(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  FastExitMediaState();
  uVar1 = (undefined4)*param_2;
  uVar4 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)((ulonglong)*param_2 >> 0x20);
  uVar7 = CONCAT44(uVar1,uVar1);
  uVar8 = CONCAT44(*(undefined4 *)(param_2 + 1),*(undefined4 *)(param_2 + 1));
  uVar2 = PackedFloatingMUL(uVar4,*param_3);
  uVar3 = PackedFloatingMUL(uVar7,param_3[2]);
  uVar5 = PackedFloatingMUL(uVar8,param_3[4]);
  uVar2 = PackedFloatingADD(uVar2,param_3[6]);
  uVar6 = PackedFloatingMUL(uVar4,param_3[1]);
  uVar4 = PackedFloatingADD(uVar3,uVar5);
  uVar3 = PackedFloatingMUL(uVar7,param_3[3]);
  uVar8 = PackedFloatingMUL(uVar8,param_3[5]);
  uVar7 = PackedFloatingADD(uVar6,param_3[7]);
  uVar4 = PackedFloatingADD(uVar2,uVar4);
  uVar3 = PackedFloatingADD(uVar3,uVar8);
  uVar2 = PackedFloatingADD(uVar7,uVar3);
  uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
  uVar8 = CONCAT44(uVar1,uVar1);
  uVar7 = FloatingReciprocalAprox(uVar3,uVar8);
  uVar3 = PackedFloatingReciprocalIter1(uVar8,uVar7);
  uVar7 = PackedFloatingReciprocalIter2(uVar3,uVar7);
  uVar4 = PackedFloatingMUL(uVar4,uVar7);
  uVar2 = PackedFloatingMUL(uVar2,uVar7);
  *param_1 = uVar4;
  *(int *)(param_1 + 1) = (int)uVar2;
  FastExitMediaState();
  return param_1;
}


// ==== 0x5f4338 FUN_005f4338

undefined8 * FUN_005f4338(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  uVar1 = (undefined4)((ulonglong)*param_2 >> 0x20);
  uVar2 = (undefined4)((ulonglong)param_2[1] >> 0x20);
  uVar3 = (undefined4)*param_2;
  uVar6 = CONCAT44(uVar3,uVar3);
  uVar3 = (undefined4)param_2[1];
  uVar9 = CONCAT44(uVar3,uVar3);
  uVar7 = PackedFloatingMUL(*param_3,uVar6);
  uVar5 = CONCAT44(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar6,param_3[1]);
  uVar8 = PackedFloatingMUL(param_3[2],uVar5);
  uVar6 = CONCAT44(uVar2,uVar2);
  uVar5 = PackedFloatingMUL(uVar5,param_3[3]);
  uVar7 = PackedFloatingADD(uVar8,uVar7);
  uVar8 = PackedFloatingMUL(param_3[4],uVar9);
  uVar4 = PackedFloatingADD(uVar5,uVar4);
  uVar5 = PackedFloatingMUL(uVar9,param_3[5]);
  uVar9 = PackedFloatingADD(uVar8,uVar7);
  uVar7 = PackedFloatingMUL(param_3[6],uVar6);
  uVar4 = PackedFloatingADD(uVar4,uVar5);
  uVar6 = PackedFloatingMUL(uVar6,param_3[7]);
  uVar7 = PackedFloatingADD(uVar7,uVar9);
  uVar5 = param_2[2];
  uVar9 = PackedFloatingADD(uVar6,uVar4);
  uVar6 = param_2[3];
  *param_1 = uVar7;
  uVar4 = *param_3;
  param_1[1] = uVar9;
  uVar1 = (undefined4)((ulonglong)uVar5 >> 0x20);
  uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
  uVar3 = (undefined4)uVar5;
  uVar9 = CONCAT44(uVar3,uVar3);
  uVar3 = (undefined4)uVar6;
  uVar7 = CONCAT44(uVar3,uVar3);
  uVar8 = PackedFloatingMUL(uVar4,uVar9);
  uVar5 = CONCAT44(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar9,param_3[1]);
  uVar9 = PackedFloatingMUL(param_3[2],uVar5);
  uVar6 = CONCAT44(uVar2,uVar2);
  uVar5 = PackedFloatingMUL(uVar5,param_3[3]);
  uVar9 = PackedFloatingADD(uVar9,uVar8);
  uVar8 = PackedFloatingMUL(param_3[4],uVar7);
  uVar4 = PackedFloatingADD(uVar5,uVar4);
  uVar5 = PackedFloatingMUL(uVar7,param_3[5]);
  uVar9 = PackedFloatingADD(uVar8,uVar9);
  uVar7 = PackedFloatingMUL(param_3[6],uVar6);
  uVar4 = PackedFloatingADD(uVar4,uVar5);
  uVar6 = PackedFloatingMUL(uVar6,param_3[7]);
  uVar7 = PackedFloatingADD(uVar7,uVar9);
  uVar5 = param_2[4];
  uVar9 = PackedFloatingADD(uVar6,uVar4);
  uVar6 = param_2[5];
  param_1[2] = uVar7;
  uVar4 = *param_3;
  param_1[3] = uVar9;
  uVar1 = (undefined4)((ulonglong)uVar5 >> 0x20);
  uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
  uVar3 = (undefined4)uVar5;
  uVar9 = CONCAT44(uVar3,uVar3);
  uVar3 = (undefined4)uVar6;
  uVar7 = CONCAT44(uVar3,uVar3);
  uVar8 = PackedFloatingMUL(uVar4,uVar9);
  uVar5 = CONCAT44(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar9,param_3[1]);
  uVar9 = PackedFloatingMUL(param_3[2],uVar5);
  uVar6 = CONCAT44(uVar2,uVar2);
  uVar5 = PackedFloatingMUL(uVar5,param_3[3]);
  uVar9 = PackedFloatingADD(uVar9,uVar8);
  uVar8 = PackedFloatingMUL(param_3[4],uVar7);
  uVar4 = PackedFloatingADD(uVar5,uVar4);
  uVar5 = PackedFloatingMUL(uVar7,param_3[5]);
  uVar9 = PackedFloatingADD(uVar8,uVar9);
  uVar7 = PackedFloatingMUL(param_3[6],uVar6);
  uVar4 = PackedFloatingADD(uVar4,uVar5);
  uVar6 = PackedFloatingMUL(uVar6,param_3[7]);
  uVar7 = PackedFloatingADD(uVar7,uVar9);
  uVar5 = param_2[6];
  uVar9 = PackedFloatingADD(uVar6,uVar4);
  uVar6 = param_2[7];
  param_1[4] = uVar7;
  uVar4 = *param_3;
  param_1[5] = uVar9;
  uVar1 = (undefined4)((ulonglong)uVar5 >> 0x20);
  uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
  uVar3 = (undefined4)uVar5;
  uVar9 = CONCAT44(uVar3,uVar3);
  uVar3 = (undefined4)uVar6;
  uVar7 = CONCAT44(uVar3,uVar3);
  uVar8 = PackedFloatingMUL(uVar4,uVar9);
  uVar5 = CONCAT44(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar9,param_3[1]);
  uVar9 = PackedFloatingMUL(param_3[2],uVar5);
  uVar6 = CONCAT44(uVar2,uVar2);
  uVar5 = PackedFloatingMUL(uVar5,param_3[3]);
  uVar9 = PackedFloatingADD(uVar9,uVar8);
  uVar8 = PackedFloatingMUL(param_3[4],uVar7);
  uVar4 = PackedFloatingADD(uVar5,uVar4);
  uVar5 = PackedFloatingMUL(uVar7,param_3[5]);
  uVar9 = PackedFloatingADD(uVar8,uVar9);
  uVar7 = PackedFloatingMUL(param_3[6],uVar6);
  uVar5 = PackedFloatingADD(uVar4,uVar5);
  uVar6 = PackedFloatingMUL(uVar6,param_3[7]);
  uVar4 = PackedFloatingADD(uVar7,uVar9);
  uVar5 = PackedFloatingADD(uVar6,uVar5);
  param_1[6] = uVar4;
  param_1[7] = uVar5;
  FastExitMediaState();
  return param_1;
}


// ==== 0x5f44ff thunk_FUN_005f42ad

undefined8 * thunk_FUN_005f42ad(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  FastExitMediaState();
  uVar1 = (undefined4)*param_2;
  uVar4 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)((ulonglong)*param_2 >> 0x20);
  uVar7 = CONCAT44(uVar1,uVar1);
  uVar8 = CONCAT44(*(undefined4 *)(param_2 + 1),*(undefined4 *)(param_2 + 1));
  uVar2 = PackedFloatingMUL(uVar4,*param_3);
  uVar3 = PackedFloatingMUL(uVar7,param_3[2]);
  uVar5 = PackedFloatingMUL(uVar8,param_3[4]);
  uVar2 = PackedFloatingADD(uVar2,param_3[6]);
  uVar6 = PackedFloatingMUL(uVar4,param_3[1]);
  uVar4 = PackedFloatingADD(uVar3,uVar5);
  uVar3 = PackedFloatingMUL(uVar7,param_3[3]);
  uVar8 = PackedFloatingMUL(uVar8,param_3[5]);
  uVar7 = PackedFloatingADD(uVar6,param_3[7]);
  uVar4 = PackedFloatingADD(uVar2,uVar4);
  uVar3 = PackedFloatingADD(uVar3,uVar8);
  uVar2 = PackedFloatingADD(uVar7,uVar3);
  uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
  uVar8 = CONCAT44(uVar1,uVar1);
  uVar7 = FloatingReciprocalAprox(uVar3,uVar8);
  uVar3 = PackedFloatingReciprocalIter1(uVar8,uVar7);
  uVar7 = PackedFloatingReciprocalIter2(uVar3,uVar7);
  uVar4 = PackedFloatingMUL(uVar4,uVar7);
  uVar2 = PackedFloatingMUL(uVar2,uVar7);
  *param_1 = uVar4;
  *(int *)(param_1 + 1) = (int)uVar2;
  FastExitMediaState();
  return param_1;
}


// ==== 0x5f4504 FUN_005f4504

ulonglong *
FUN_005f4504(ulonglong *param_1,undefined4 param_2,undefined8 *param_3,undefined4 *param_4,
            undefined4 *param_5,undefined4 *param_6)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined4 uVar8;
  undefined8 uVar7;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
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
  undefined4 local_8;
  
  puVar1 = &local_44;
  switch(((param_6 != (undefined4 *)0x0) << 1 | param_5 != (undefined4 *)0x0) << 1 |
         param_4 != (undefined4 *)0x0) {
  case '\0':
    local_c = 0;
    local_10 = 0;
    local_14 = 0;
    local_18 = 0;
    local_20 = 0;
    local_24 = 0;
    local_28 = 0;
    local_2c = 0;
    local_34 = 0;
    local_38 = 0;
    local_3c = 0;
    local_40 = 0;
    local_8 = 0x3f800000;
    local_1c = 0x3f800000;
    local_30 = 0x3f800000;
    local_44 = 0x3f800000;
    break;
  case '\x01':
    puVar1 = param_4;
    break;
  case '\x02':
    puVar1 = param_5;
    break;
  case '\x03':
    FastExitMediaState();
    FUN_005f4338(&local_44,param_5,param_4);
    FastExitMediaState();
    break;
  case '\x04':
    puVar1 = param_6;
    break;
  case '\x05':
    FastExitMediaState();
    FUN_005f4338(&local_44,param_6,param_4);
    FastExitMediaState();
    break;
  case '\x06':
    FastExitMediaState();
    FUN_005f4338(&local_44,param_6,param_5);
    FastExitMediaState();
    break;
  case '\a':
    FastExitMediaState();
    FUN_005f4338(&local_44,param_6,param_5);
    FUN_005f4338(&local_44,&local_44,param_4);
    FastExitMediaState();
  }
  FUN_005f42ad(param_1,param_2,puVar1);
  if (param_3 != (undefined8 *)0x0) {
    FastExitMediaState();
    uVar4 = param_3[2];
    uVar5 = PackedIntToFloatingDwordConv(*param_3,*param_3);
    uVar6 = PackedIntToFloatingDwordConv(param_3[1],param_3[1]);
    uVar2 = PackedFloatingADD(*param_1 ^ 0x8000000000000000,0x3f8000003f800000);
    uVar6 = PackedFloatingMUL(uVar6,0x3f0000003f000000);
    uVar8 = (undefined4)((ulonglong)uVar4 >> 0x20);
    uVar7 = PackedFloatingSUB(CONCAT44(uVar8,uVar8),uVar4);
    uVar2 = PackedFloatingMUL(uVar2,uVar6);
    uVar6 = PackedFloatingMUL((ulonglong)(uint)param_1[1],uVar7);
    uVar4 = PackedFloatingADD(uVar6,uVar4);
    uVar3 = PackedFloatingADD(uVar2,uVar5);
    *param_1 = uVar3;
    *(int *)(param_1 + 1) = (int)uVar4;
    FastExitMediaState();
  }
  return param_1;
}


// ==== 0x5f468c FUN_005f468c

ulonglong *
FUN_005f468c(ulonglong *param_1,ulonglong *param_2,undefined8 *param_3,int param_4,int param_5,
            int param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 uVar7;
  undefined8 uVar6;
  undefined8 uVar8;
  unkbyte10 in_ST5;
  undefined8 uVar9;
  unkbyte10 in_ST6;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
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
  undefined4 local_8;
  
  uVar2 = (undefined8)in_ST5;
  uVar9 = (undefined8)in_ST6;
  switch(((param_6 != 0) << 1 | param_5 != 0) << 1 | param_4 != 0) {
  case '\0':
    local_c = 0;
    local_10 = 0;
    local_14 = 0;
    local_18 = 0;
    local_20 = 0;
    local_24 = 0;
    local_28 = 0;
    local_2c = 0;
    local_34 = 0;
    local_38 = 0;
    local_3c = 0;
    local_40 = 0;
    local_8 = 0x3f800000;
    local_1c = 0x3f800000;
    local_30 = 0x3f800000;
    local_44 = 0x3f800000;
    break;
  case '\x01':
    FastExitMediaState();
    FUN_005f3bf7(&local_44,0,param_4);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
    break;
  case '\x02':
    FastExitMediaState();
    FUN_005f3bf7(&local_44,0,param_5);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
    break;
  case '\x03':
    FastExitMediaState();
    FUN_005f4338(&local_44,param_5,param_4);
    FUN_005f3bf7(&local_44,0,&local_44);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
    break;
  case '\x04':
    FastExitMediaState();
    FUN_005f3bf7(&local_44,0,param_6);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
    break;
  case '\x05':
    FastExitMediaState();
    FUN_005f4338(&local_44,param_6,param_4);
    FUN_005f3bf7(&local_44,0,&local_44);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
    break;
  case '\x06':
    FastExitMediaState();
    FUN_005f4338(&local_44,param_6,param_5);
    FUN_005f3bf7(&local_44,0,&local_44);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
    break;
  case '\a':
    FastExitMediaState();
    FUN_005f4338(&local_44,param_6,param_5);
    FUN_005f4338(&local_44,&local_44,param_4);
    FUN_005f3bf7(&local_44,0,&local_44);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
  }
  if (param_3 != (undefined8 *)0x0) {
    FastExitMediaState();
    uVar4 = PackedIntToFloatingDwordConv(*param_3,*param_3);
    uVar1 = param_3[2];
    uVar5 = PackedIntToFloatingDwordConv(param_3[1],param_3[1]);
    uVar7 = (undefined4)((ulonglong)uVar5 >> 0x20);
    uVar6 = CONCAT44(uVar7,uVar7);
    uVar8 = FloatingReciprocalAprox(uVar2,uVar5);
    uVar6 = FloatingReciprocalAprox(uVar6,uVar6);
    uVar2 = PackedFloatingSUB(*param_2,uVar4);
    uVar6 = CONCAT44((int)uVar6,(int)uVar8);
    uVar4 = PackedFloatingReciprocalIter1(uVar5,uVar6);
    uVar4 = PackedFloatingReciprocalIter2(uVar4,uVar6);
    uVar4 = PackedFloatingMUL(uVar4,0x4000000040000000);
    uVar2 = PackedFloatingMUL(uVar2,uVar4);
    uVar7 = (undefined4)((ulonglong)uVar1 >> 0x20);
    uVar3 = PackedFloatingSUB(uVar2,0x3f8000003f800000);
    uVar2 = PackedFloatingSUB(CONCAT44(uVar7,uVar7),uVar1);
    uVar9 = FloatingReciprocalAprox(uVar9,uVar2);
    uVar2 = PackedFloatingReciprocalIter1(uVar2,uVar9);
    uVar9 = PackedFloatingReciprocalIter2(uVar2,uVar9);
    uVar2 = PackedFloatingSUB((ulonglong)(uint)param_2[1],uVar1);
    uVar2 = PackedFloatingMUL(uVar2,uVar9);
    *param_1 = uVar3 ^ 0x8000000000000000;
    *(int *)(param_1 + 1) = (int)uVar2;
    FastExitMediaState();
    param_2 = param_1;
  }
  FUN_005f42ad(param_1,param_2,&local_44);
  return param_1;
}


// ==== 0x5f48b2 FUN_005f48b2

ulonglong *
FUN_005f48b2(ulonglong *param_1,ulonglong *param_2,undefined8 *param_3,undefined1 *param_4,
            undefined1 *param_5,undefined1 *param_6)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar6;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 in_MM5;
  undefined8 uVar7;
  undefined8 in_MM6;
  undefined1 local_44 [64];
  
  switch(((param_6 != (undefined1 *)0x0) << 1 | param_5 != (undefined1 *)0x0) << 1 |
         param_4 != (undefined1 *)0x0) {
  case '\0':
    FUN_005f087f(local_44);
    goto switchD_005f48e8_default;
  case '\x01':
    param_6 = param_4;
    goto LAB_005f492b;
  case '\x02':
    param_6 = param_5;
    goto LAB_005f492b;
  case '\x03':
    param_6 = param_5;
    break;
  case '\x04':
    goto LAB_005f492b;
  case '\x05':
    break;
  case '\x06':
    param_4 = param_5;
    break;
  case '\a':
    FUN_005f4338(local_44,param_6,param_5);
    param_6 = local_44;
    break;
  default:
    goto switchD_005f48e8_default;
  }
  FUN_005f4338(local_44,param_6,param_4);
  param_6 = local_44;
LAB_005f492b:
  FUN_005f351d(local_44,0,param_6);
switchD_005f48e8_default:
  if (param_3 != (undefined8 *)0x0) {
    FastExitMediaState();
    uVar2 = PackedIntToFloatingDwordConv(*param_3,*param_3);
    uVar5 = param_3[2];
    uVar3 = PackedIntToFloatingDwordConv(param_3[1],param_3[1]);
    uVar6 = (undefined4)((ulonglong)uVar3 >> 0x20);
    uVar4 = CONCAT44(uVar6,uVar6);
    uVar7 = FloatingReciprocalAprox(in_MM5,uVar3);
    uVar4 = FloatingReciprocalAprox(uVar4,uVar4);
    uVar2 = PackedFloatingSUB(*param_2,uVar2);
    uVar4 = CONCAT44((int)uVar4,(int)uVar7);
    uVar3 = PackedFloatingReciprocalIter1(uVar3,uVar4);
    uVar3 = PackedFloatingReciprocalIter2(uVar3,uVar4);
    uVar3 = PackedFloatingMUL(uVar3,0x4000000040000000);
    uVar2 = PackedFloatingMUL(uVar2,uVar3);
    uVar6 = (undefined4)((ulonglong)uVar5 >> 0x20);
    uVar1 = PackedFloatingSUB(uVar2,0x3f8000003f800000);
    uVar2 = PackedFloatingSUB(CONCAT44(uVar6,uVar6),uVar5);
    uVar3 = FloatingReciprocalAprox(in_MM6,uVar2);
    uVar2 = PackedFloatingReciprocalIter1(uVar2,uVar3);
    uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar3);
    uVar5 = PackedFloatingSUB((ulonglong)(uint)param_2[1],uVar5);
    uVar5 = PackedFloatingMUL(uVar5,uVar2);
    *param_1 = uVar1 ^ 0x8000000000000000;
    *(int *)(param_1 + 1) = (int)uVar5;
    FastExitMediaState();
    param_2 = param_1;
  }
  FUN_005f42ad(param_1,param_2,local_44);
  return param_1;
}


// ==== 0x5f4a40 FUN_005f4a40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong * FUN_005f4a40(ulonglong *param_1,undefined4 *param_2,int param_3)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  int iVar10;
  
  puVar1 = param_1;
  if (param_3 < 4) {
    if (param_3 != 0) {
      FUN_005ab80f(param_1,param_2,param_3);
    }
  }
  else {
    while( true ) {
      for (; 3 < param_3; param_3 = param_3 + -4) {
        uVar7 = (ulonglong)CONCAT24((short)((uint)*param_2 >> 0x10),*param_2) & 0xffffffff0000ffff;
        uVar3 = (ulonglong)CONCAT24((short)((uint)param_2[1] >> 0x10),param_2[1]) &
                0xffffffff0000ffff;
        uVar9 = CONCAT44(-(uint)((int)((uVar7 & DAT_006df3c0) >> 0x20) == 0),
                         -(uint)((int)(uVar7 & DAT_006df3c0) == 0));
        uVar4 = CONCAT44(-(uint)((int)((uVar3 & DAT_006df3c0) >> 0x20) == 0),
                         -(uint)((int)(uVar3 & DAT_006df3c0) == 0));
        uVar6 = uVar7 & DAT_006df3e0;
        uVar8 = uVar3 & DAT_006df3e0;
        iVar10 = (int)((ulonglong)DAT_006df3d0 >> 0x20);
        uVar2 = uVar9 & _DAT_006df3f0;
        uVar5 = uVar4 & _DAT_006df3f0;
        uVar7 = PackedFloatingSUB(CONCAT44(((int)((uVar7 ^ uVar6) >> 0x20) + iVar10 +
                                           (int)(uVar2 >> 0x20)) * 0x2000,
                                           ((int)(uVar7 ^ uVar6) + (int)DAT_006df3d0 + (int)uVar2) *
                                           0x2000),uVar9 & _DAT_006df400);
        uVar9 = PackedFloatingSUB(CONCAT44(((int)((uVar3 ^ uVar8) >> 0x20) + iVar10 +
                                           (int)(uVar5 >> 0x20)) * 0x2000,
                                           ((int)(uVar3 ^ uVar8) + (int)DAT_006df3d0 + (int)uVar5) *
                                           0x2000),uVar4 & _DAT_006df400);
        *puVar1 = uVar7 | CONCAT44((int)(uVar6 >> 0x20) << 0x10,(int)uVar6 << 0x10);
        puVar1[1] = uVar9 | CONCAT44((int)(uVar8 >> 0x20) << 0x10,(int)uVar8 << 0x10);
        puVar1 = puVar1 + 2;
        param_2 = param_2 + 2;
      }
      if (param_3 == 0) break;
      param_2 = (undefined4 *)((int)param_2 + (param_3 + -4) * 2);
      puVar1 = (ulonglong *)((int)puVar1 + (param_3 + -4) * 4);
      param_3 = 4;
    }
  }
  FastExitMediaState();
  return param_1;
}


// ==== 0x5f4b80 FUN_005f4b80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong * FUN_005f4b80(ulonglong *param_1,ulonglong *param_2,int param_3)

{
  ulonglong *puVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar8;
  ulonglong uVar7;
  int iVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  
  puVar1 = param_1;
  if (param_3 < 4) {
    if (param_3 != 0) {
      FUN_005ab773(param_1,param_2,param_3);
    }
  }
  else {
    while( true ) {
      for (; 3 < param_3; param_3 = param_3 + -4) {
        uVar10 = DAT_006df430 & *param_2;
        uVar12 = DAT_006df430 & param_2[1];
        uVar11 = packssdw(CONCAT44((uint)(uVar10 >> 0x32),(uint)uVar10 >> 0x12),
                          CONCAT44((uint)(uVar12 >> 0x32),(uint)uVar12 >> 0x12));
        uVar10 = *param_2 & DAT_006df480;
        uVar6 = param_2[1] & DAT_006df480;
        uVar12 = PackedFloatingCompareGE(DAT_006df420,uVar10);
        uVar3 = PackedFloatingADD(uVar10,uVar12 & DAT_006df420);
        uVar2 = (int)uVar3 - (int)(uVar12 & _DAT_006df490);
        uVar4 = (int)((ulonglong)uVar3 >> 0x20) - (int)((uVar12 & _DAT_006df490) >> 0x20);
        uVar12 = PackedFloatingCompareGE(DAT_006df420,uVar6);
        uVar3 = PackedFloatingADD(uVar6,uVar12 & DAT_006df420);
        uVar5 = (int)uVar3 - (int)(uVar12 & _DAT_006df490);
        uVar8 = (int)((ulonglong)uVar3 >> 0x20) - (int)((uVar12 & _DAT_006df490) >> 0x20);
        uVar12 = CONCAT44(uVar4 >> 0xd,uVar2 >> 0xd) & DAT_006df450;
        uVar7 = CONCAT44(uVar8 >> 0xd,uVar5 >> 0xd) & DAT_006df450;
        uVar10 = PackedFloatingCompareGT(DAT_006df410,uVar10);
        uVar6 = PackedFloatingCompareGT(DAT_006df410,uVar6);
        iVar9 = (int)((ulonglong)DAT_006df460 >> 0x20);
        uVar10 = packssdw(CONCAT44((int)(uVar12 >> 0x20) + uVar4 + iVar9 >> 0xd,
                                   (int)uVar12 + uVar2 + (int)DAT_006df460 >> 0xd) & uVar10 |
                          ~uVar10 & DAT_006df4a0,
                          CONCAT44((int)(uVar7 >> 0x20) + uVar8 + iVar9 >> 0xd,
                                   (int)uVar7 + uVar5 + (int)DAT_006df460 >> 0xd) & uVar6 |
                          ~uVar6 & DAT_006df4a0);
        *puVar1 = uVar10 | CONCAT44((int)((ulonglong)uVar11 >> 0x20) << 2,(int)uVar11 << 2);
        puVar1 = puVar1 + 1;
        param_2 = param_2 + 2;
      }
      if (param_3 == 0) break;
      param_2 = (ulonglong *)((int)param_2 + (param_3 + -4) * 4);
      puVar1 = (ulonglong *)((int)puVar1 + (param_3 + -4) * 2);
      param_3 = 4;
    }
  }
  FastExitMediaState();
  return param_1;
}


// ==== 0x5f4cfb FUN_005f4cfb

undefined8 * FUN_005f4cfb(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  FastExitMediaState();
  uVar1 = (undefined4)*param_2;
  uVar3 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)((ulonglong)*param_2 >> 0x20);
  uVar6 = CONCAT44(uVar1,uVar1);
  uVar2 = PackedFloatingMUL(uVar3,*param_3);
  uVar4 = PackedFloatingMUL(uVar6,param_3[2]);
  uVar2 = PackedFloatingADD(uVar2,param_3[6]);
  uVar5 = PackedFloatingMUL(uVar3,param_3[1]);
  uVar6 = PackedFloatingMUL(uVar6,param_3[3]);
  uVar3 = PackedFloatingADD(uVar2,uVar4);
  uVar2 = PackedFloatingADD(uVar5,param_3[7]);
  uVar2 = PackedFloatingADD(uVar2,uVar6);
  *param_1 = uVar3;
  param_1[1] = uVar2;
  FastExitMediaState();
  return param_1;
}


// ==== 0x5f4d50 FUN_005f4d50

undefined8 * FUN_005f4d50(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 uVar4;
  undefined8 uVar3;
  
  FastExitMediaState();
  uVar1 = (undefined4)*param_2;
  uVar4 = (undefined4)((ulonglong)*param_2 >> 0x20);
  uVar2 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),*param_3);
  uVar3 = PackedFloatingMUL(CONCAT44(uVar4,uVar4),param_3[2]);
  uVar2 = PackedFloatingADD(uVar2,uVar3);
  *param_1 = uVar2;
  FastExitMediaState();
  return param_1;
}


// ==== 0x5f4d89 FUN_005f4d89

undefined8 * FUN_005f4d89(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  FastExitMediaState();
  uVar1 = (undefined4)*param_2;
  uVar3 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)((ulonglong)*param_2 >> 0x20);
  uVar6 = CONCAT44(uVar1,uVar1);
  uVar2 = PackedFloatingMUL(uVar3,*param_3);
  uVar4 = PackedFloatingMUL(uVar6,param_3[2]);
  uVar2 = PackedFloatingADD(uVar2,param_3[6]);
  uVar5 = PackedFloatingMUL(uVar3,param_3[1]);
  uVar6 = PackedFloatingMUL(uVar6,param_3[3]);
  uVar3 = PackedFloatingADD(uVar2,uVar4);
  uVar2 = PackedFloatingADD(uVar5,param_3[7]);
  uVar2 = PackedFloatingADD(uVar2,uVar6);
  uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
  uVar2 = CONCAT44(uVar1,uVar1);
  uVar6 = FloatingReciprocalAprox(uVar6,uVar2);
  uVar2 = PackedFloatingReciprocalIter1(uVar2,uVar6);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar6);
  uVar3 = PackedFloatingMUL(uVar3,uVar2);
  *param_1 = uVar3;
  FastExitMediaState();
  return param_1;
}


// ==== 0x5f4ded FUN_005f4ded

void FUN_005f4ded(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                 undefined8 *param_5,uint param_6)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  FastExitMediaState();
  uVar1 = (ulonglong)param_6;
  uVar2 = PackedFloatingMUL(uVar1,uVar1);
  uVar3 = PackedFloatingMUL(uVar2,uVar1);
  uVar6 = PackedFloatingSUB(uVar3,uVar2);
  uVar5 = PackedFloatingMUL(uVar2,0x4000000040000000);
  uVar2 = PackedFloatingMUL(uVar2,0x4040000040400000);
  uVar4 = PackedFloatingMUL(uVar3,0x4000000040000000);
  uVar5 = PackedFloatingSUB(uVar3,uVar5);
  uVar3 = PackedFloatingSUB(uVar2,uVar4);
  uVar5 = PackedFloatingADD(uVar5,uVar1);
  uVar2 = PackedFloatingSUB(uVar4,uVar2);
  uVar2 = PackedFloatingADD(uVar2,0x3f8000003f800000);
  uVar2 = PackedFloatingMUL(CONCAT44((int)uVar2,(int)uVar2),*param_2);
  uVar4 = PackedFloatingMUL(CONCAT44((int)uVar5,(int)uVar5),*param_3);
  uVar4 = PackedFloatingADD(uVar2,uVar4);
  uVar2 = PackedFloatingMUL(CONCAT44((int)uVar3,(int)uVar3),*param_4);
  uVar3 = PackedFloatingMUL(CONCAT44((int)uVar6,(int)uVar6),*param_5);
  uVar2 = PackedFloatingADD(uVar2,uVar3);
  uVar2 = PackedFloatingADD(uVar4,uVar2);
  *param_1 = uVar2;
  FastExitMediaState();
  return;
}


// ==== 0x5f4e85 FUN_005f4e85

void FUN_005f4e85(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar3 = *param_2;
  uVar1 = PackedFloatingSUB(*param_3,uVar3);
  uVar1 = PackedFloatingMUL(uVar1,CONCAT44(param_5,param_5));
  uVar2 = PackedFloatingSUB(*param_4,uVar3);
  uVar1 = PackedFloatingADD(uVar3,uVar1);
  uVar3 = PackedFloatingMUL(uVar2,CONCAT44(param_6,param_6));
  uVar3 = PackedFloatingADD(uVar1,uVar3);
  *param_1 = uVar3;
  FastExitMediaState();
  return;
}


// ==== 0x5f4ece FUN_005f4ece

void FUN_005f4ece(undefined8 *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 in_MM4;
  undefined8 uVar4;
  undefined8 uVar5;
  
  uVar1 = *param_2;
  uVar2 = PackedFloatingMUL(uVar1,uVar1);
  uVar2 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar4 = PackedFloatingReciprocalSQRAprox(in_MM4,uVar2);
  uVar3 = PackedFloatingCompareGT(uVar2,0x80000000800000);
  uVar5 = PackedFloatingMUL(uVar4,uVar4);
  uVar2 = PackedFloatingReciprocalSQRIter1(uVar5,uVar2);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar4);
  uVar2 = PackedFloatingMUL(uVar1 & uVar3,uVar2);
  *param_1 = uVar2;
  FastExitMediaState();
  return;
}


// ==== 0x5f4f11 FUN_005f4f11

void FUN_005f4f11(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                 undefined8 *param_5,undefined4 param_6)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar6;
  undefined8 uVar5;
  
  uVar1 = PackedFloatingMUL(CONCAT44(param_6,param_6),CONCAT44(param_6,param_6));
  uVar3 = CONCAT44(0x3f800000,param_6);
  uVar1 = PackedFloatingMUL(uVar1,uVar3);
  uVar4 = PackedFloatingMUL(uVar3,uVar3);
  uVar1 = PackedFloatingSUB(uVar1,uVar4);
  uVar2 = PackedFloatingMUL(uVar1,0x4000000040400000);
  uVar3 = CONCAT44((int)uVar1,(int)uVar2);
  uVar4 = PackedFloatingADD(CONCAT44((int)uVar4,(int)uVar4),
                            CONCAT44(param_6,param_6) ^ 0x8000000000000000);
  uVar4 = PackedFloatingSUB(uVar4,uVar3);
  uVar3 = PackedFloatingSUB(uVar3,uVar2 >> 0x20);
  uVar6 = (undefined4)((ulonglong)uVar4 >> 0x20);
  uVar5 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),*param_2);
  uVar6 = (undefined4)((ulonglong)uVar3 >> 0x20);
  uVar3 = PackedFloatingMUL(CONCAT44((int)uVar3,(int)uVar3),*param_3);
  uVar4 = PackedFloatingMUL(CONCAT44((int)uVar4,(int)uVar4),*param_4);
  uVar3 = PackedFloatingADD(uVar3,uVar5);
  PackedFloatingADD(uVar1,uVar2 >> 0x20);
  uVar1 = PackedFloatingADD(uVar3,uVar4);
  uVar3 = PackedFloatingMUL(CONCAT44(uVar6,uVar6),*param_5);
  uVar1 = PackedFloatingADD(uVar1,uVar3);
  uVar1 = PackedFloatingMUL(uVar1,0x3f0000003f000000);
  *param_1 = uVar1;
  FastExitMediaState();
  return;
}


// ==== 0x5f4fbc FUN_005f4fbc

undefined8 * FUN_005f4fbc(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  FastExitMediaState();
  uVar1 = (undefined4)*param_2;
  uVar5 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)((ulonglong)*param_2 >> 0x20);
  uVar8 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)param_2[1];
  uVar9 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)((ulonglong)param_2[1] >> 0x20);
  uVar6 = CONCAT44(uVar1,uVar1);
  uVar2 = PackedFloatingMUL(uVar5,*param_3);
  uVar3 = PackedFloatingMUL(uVar8,param_3[2]);
  uVar4 = PackedFloatingMUL(uVar9,param_3[4]);
  uVar7 = PackedFloatingMUL(uVar6,param_3[6]);
  uVar2 = PackedFloatingADD(uVar2,uVar3);
  uVar3 = PackedFloatingMUL(uVar5,param_3[1]);
  uVar5 = PackedFloatingADD(uVar4,uVar7);
  uVar8 = PackedFloatingMUL(uVar8,param_3[3]);
  uVar9 = PackedFloatingMUL(uVar9,param_3[5]);
  uVar4 = PackedFloatingMUL(uVar6,param_3[7]);
  uVar5 = PackedFloatingADD(uVar2,uVar5);
  uVar2 = PackedFloatingADD(uVar3,uVar8);
  uVar8 = PackedFloatingADD(uVar9,uVar4);
  uVar2 = PackedFloatingADD(uVar2,uVar8);
  *param_1 = uVar5;
  param_1[1] = uVar2;
  FastExitMediaState();
  return param_1;
}


// ==== 0x5f503e FUN_005f503e

void FUN_005f503e(undefined8 *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 in_MM4;
  undefined8 uVar5;
  ulonglong uVar6;
  
  FastExitMediaState();
  uVar1 = *param_2;
  uVar2 = param_2[1];
  uVar3 = PackedFloatingMUL(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar2,uVar2);
  uVar3 = PackedFloatingADD(uVar3,uVar4);
  uVar3 = PackedFloatingAccumulate(uVar3,uVar3);
  uVar5 = PackedFloatingReciprocalSQRAprox(in_MM4,uVar3);
  uVar6 = PackedFloatingCompareGT(uVar3,0x80000000800000);
  uVar4 = PackedFloatingMUL(uVar5,uVar5);
  uVar3 = PackedFloatingReciprocalSQRIter1(uVar3,uVar4);
  uVar3 = PackedFloatingReciprocalIter2(uVar3,uVar5);
  uVar4 = PackedFloatingMUL(uVar1 & uVar6,uVar3);
  uVar3 = PackedFloatingMUL(uVar2 & uVar6,uVar3);
  *param_1 = uVar4;
  param_1[1] = uVar3;
  FastExitMediaState();
  return;
}


// ==== 0x5f509d FUN_005f509d

void FUN_005f509d(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar7;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined4 uVar9;
  undefined8 uVar8;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined4 uVar14;
  ulonglong uVar15;
  
  FastExitMediaState();
  uVar9 = (undefined4)((ulonglong)param_4[1] >> 0x20);
  uVar1 = (undefined4)((ulonglong)param_3[1] >> 0x20);
  uVar7 = (undefined4)param_3[1];
  uVar2 = (undefined4)((ulonglong)*param_3 >> 0x20);
  uVar14 = (undefined4)param_4[1];
  uVar4 = (undefined4)((ulonglong)*param_4 >> 0x20);
  uVar8 = PackedFloatingMUL(CONCAT44(uVar9,uVar9),CONCAT44(uVar2,uVar7));
  uVar11 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),CONCAT44(uVar4,uVar14));
  uVar11 = PackedFloatingSUB(uVar8,uVar11);
  uVar3 = (undefined4)*param_4;
  uVar8 = PackedFloatingMUL(CONCAT44(uVar1,uVar2),CONCAT44(uVar3,uVar14));
  uVar1 = (undefined4)*param_3;
  uVar12 = PackedFloatingMUL(CONCAT44(uVar9,uVar4),CONCAT44(uVar1,uVar7));
  uVar10 = PackedFloatingSUB(uVar8,uVar12);
  uVar12 = PackedFloatingMUL(CONCAT44(uVar3,uVar3),CONCAT44(uVar2,uVar7));
  uVar8 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),CONCAT44(uVar4,uVar14));
  uVar13 = PackedFloatingSUB(uVar12,uVar8);
  uVar8 = param_2[1];
  uVar12 = PackedFloatingMUL(CONCAT44((int)uVar11,(int)uVar11) ^ 0x8000000000000000,
                             CONCAT44((int)*param_2,(int)((ulonglong)*param_2 >> 0x20)));
  uVar7 = (undefined4)((ulonglong)uVar11 >> 0x20);
  uVar1 = (undefined4)((ulonglong)uVar10 >> 0x20);
  uVar5 = PackedFloatingMUL(CONCAT44((int)uVar10,uVar7),uVar8);
  uVar15 = PackedFloatingMUL(CONCAT44((int)uVar13,uVar1),uVar8);
  uVar6 = PackedFloatingAccumulate(uVar5 ^ 0x8000000000000000,uVar15 ^ 0x8000000000000000);
  uVar11 = *param_2;
  uVar12 = PackedFloatingSUB(uVar12,uVar6);
  *param_1 = uVar12;
  uVar14 = (undefined4)((ulonglong)uVar13 >> 0x20);
  uVar15 = PackedFloatingMUL(CONCAT44(uVar1,uVar7) ^ 0x8000000000000000,uVar11);
  uVar5 = PackedFloatingMUL(CONCAT44((int)uVar13,(int)uVar10) ^ 0x80000000,uVar11);
  uVar8 = PackedFloatingMUL(CONCAT44((int)uVar8,(int)((ulonglong)uVar8 >> 0x20)),
                            CONCAT44(uVar14,uVar14) ^ 0x80000000);
  uVar11 = PackedFloatingAccumulate(uVar15 ^ 0x8000000000000000,uVar5 ^ 0x8000000000000000);
  uVar8 = PackedFloatingADD(uVar8,uVar11);
  param_1[1] = uVar8;
  FastExitMediaState();
  return;
}


// ==== 0x5f51cf FUN_005f51cf

void FUN_005f51cf(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  uVar2 = *param_2;
  uVar4 = param_2[1];
  uVar1 = PackedFloatingSUB(*param_3,uVar2);
  uVar3 = PackedFloatingSUB(param_3[1],uVar4);
  uVar5 = PackedFloatingSUB(*param_4,uVar2);
  uVar6 = PackedFloatingSUB(param_4[1],uVar4);
  uVar1 = PackedFloatingMUL(uVar1,CONCAT44(param_5,param_5));
  uVar3 = PackedFloatingMUL(uVar3,CONCAT44(param_5,param_5));
  uVar5 = PackedFloatingMUL(uVar5,CONCAT44(param_6,param_6));
  uVar2 = PackedFloatingADD(uVar1,uVar2);
  uVar1 = PackedFloatingMUL(uVar6,CONCAT44(param_6,param_6));
  uVar4 = PackedFloatingADD(uVar3,uVar4);
  uVar2 = PackedFloatingADD(uVar2,uVar5);
  uVar4 = PackedFloatingADD(uVar4,uVar1);
  *param_1 = uVar2;
  param_1[1] = uVar4;
  FastExitMediaState();
  return;
}


// ==== 0x5f5240 FUN_005f5240

void FUN_005f5240(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                 undefined8 *param_5,uint param_6)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  
  FastExitMediaState();
  uVar1 = (ulonglong)param_6;
  uVar2 = PackedFloatingMUL(uVar1,uVar1);
  uVar3 = PackedFloatingMUL(uVar2,uVar1);
  uVar9 = PackedFloatingSUB(uVar3,uVar2);
  uVar5 = PackedFloatingMUL(uVar2,0x4000000040000000);
  uVar2 = PackedFloatingMUL(uVar2,0x4040000040400000);
  uVar4 = PackedFloatingMUL(uVar3,0x4000000040000000);
  uVar5 = PackedFloatingSUB(uVar3,uVar5);
  uVar3 = PackedFloatingSUB(uVar2,uVar4);
  uVar5 = PackedFloatingADD(uVar5,uVar1);
  uVar2 = PackedFloatingSUB(uVar4,uVar2);
  uVar4 = PackedFloatingADD(uVar2,0x3f8000003f800000);
  uVar6 = CONCAT44((int)uVar9,(int)uVar9);
  uVar2 = CONCAT44((int)uVar3,(int)uVar3);
  uVar9 = CONCAT44((int)uVar5,(int)uVar5);
  uVar4 = CONCAT44((int)uVar4,(int)uVar4);
  uVar10 = PackedFloatingMUL(uVar6,*param_5);
  uVar3 = PackedFloatingMUL(uVar2,*param_4);
  uVar7 = PackedFloatingMUL(uVar6,param_5[1]);
  uVar2 = PackedFloatingMUL(uVar2,param_4[1]);
  uVar8 = PackedFloatingMUL(uVar9,*param_3);
  uVar5 = PackedFloatingMUL(uVar4,*param_2);
  uVar6 = PackedFloatingMUL(uVar9,param_3[1]);
  uVar9 = PackedFloatingMUL(uVar4,param_2[1]);
  uVar3 = PackedFloatingADD(uVar3,uVar10);
  uVar2 = PackedFloatingADD(uVar2,uVar7);
  uVar4 = PackedFloatingADD(uVar5,uVar8);
  uVar5 = PackedFloatingADD(uVar9,uVar6);
  uVar3 = PackedFloatingADD(uVar3,uVar4);
  uVar2 = PackedFloatingADD(uVar2,uVar5);
  *param_1 = uVar3;
  param_1[1] = uVar2;
  FastExitMediaState();
  return;
}


// ==== 0x5f5308 FUN_005f5308

void FUN_005f5308(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                 undefined8 *param_5,undefined4 param_6)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  uVar1 = PackedFloatingMUL(CONCAT44(param_6,param_6),CONCAT44(param_6,param_6));
  uVar3 = CONCAT44(0x3f800000,param_6);
  uVar1 = PackedFloatingMUL(uVar1,uVar3);
  uVar3 = PackedFloatingMUL(uVar3,uVar3);
  uVar1 = PackedFloatingSUB(uVar1,uVar3);
  uVar2 = PackedFloatingMUL(uVar1,0x4000000040400000);
  uVar1 = CONCAT44((int)uVar1,(int)uVar2);
  uVar3 = PackedFloatingADD(CONCAT44((int)uVar3,(int)uVar3),
                            CONCAT44(param_6,param_6) ^ 0x8000000000000000);
  uVar4 = PackedFloatingSUB(uVar3,uVar1);
  uVar1 = PackedFloatingSUB(uVar1,uVar2 >> 0x20);
  uVar5 = (undefined4)((ulonglong)uVar4 >> 0x20);
  uVar8 = CONCAT44(uVar5,uVar5);
  uVar3 = CONCAT44((int)uVar1,(int)uVar1);
  uVar9 = CONCAT44((int)uVar4,(int)uVar4);
  uVar4 = PackedFloatingMUL(uVar8,*param_2);
  uVar5 = (undefined4)((ulonglong)uVar1 >> 0x20);
  uVar7 = CONCAT44(uVar5,uVar5);
  uVar1 = PackedFloatingMUL(uVar3,*param_3);
  uVar6 = PackedFloatingMUL(uVar9,*param_4);
  uVar8 = PackedFloatingMUL(uVar8,param_2[1]);
  uVar3 = PackedFloatingMUL(uVar3,param_3[1]);
  uVar1 = PackedFloatingADD(uVar1,uVar4);
  uVar9 = PackedFloatingMUL(uVar9,param_4[1]);
  uVar4 = PackedFloatingADD(uVar8,uVar3);
  uVar1 = PackedFloatingADD(uVar1,uVar6);
  uVar3 = PackedFloatingMUL(uVar7,*param_5);
  uVar1 = PackedFloatingADD(uVar1,uVar3);
  uVar8 = PackedFloatingMUL(uVar7,param_5[1]);
  uVar3 = PackedFloatingADD(uVar4,uVar9);
  uVar1 = PackedFloatingMUL(uVar1,0x3f0000003f000000);
  uVar3 = PackedFloatingADD(uVar3,uVar8);
  *param_1 = uVar1;
  uVar1 = PackedFloatingMUL(uVar3,0x3f0000003f000000);
  param_1[1] = uVar1;
  FastExitMediaState();
  return;
}


// ==== 0x5f53e6 FUN_005f53e6

void FUN_005f53e6(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  FastExitMediaState();
  uVar1 = *(uint *)(param_3 + 1);
  uVar2 = PackedFloatingMUL(*param_2,*param_3);
  uVar3 = PackedFloatingMUL((ulonglong)*(uint *)(param_2 + 1),(ulonglong)uVar1);
  uVar2 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar2 = PackedFloatingADD(uVar2,uVar3);
  *param_1 = *param_3;
  *(uint *)(param_1 + 1) = uVar1;
  *(uint *)((int)param_1 + 0xc) = (uint)uVar2 ^ 0x80000000;
  FastExitMediaState();
  return;
}


// ==== 0x5f5429 FUN_005f5429

void FUN_005f5429(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  
  FastExitMediaState();
  uVar1 = *(uint *)(param_2 + 1);
  uVar2 = PackedFloatingSUB(*param_2,*param_3);
  uVar5 = PackedFloatingSUB(CONCAT44(uVar1,uVar1),
                            CONCAT44(*(undefined4 *)(param_3 + 1),*(undefined4 *)(param_4 + 1)));
  uVar7 = PackedFloatingSUB(*param_2,*param_4);
  uVar10 = PackedFloatingSUB(0,uVar7);
  uVar3 = PackedFloatingMUL(CONCAT44((int)((ulonglong)uVar10 >> 0x20),
                                     (int)((ulonglong)uVar2 >> 0x20)),uVar5);
  uVar9 = (undefined4)uVar10;
  uVar5 = PackedFloatingMUL(CONCAT44((int)uVar2,(int)((ulonglong)uVar5 >> 0x20)),
                            CONCAT44((int)uVar5,uVar9));
  uVar4 = PackedFloatingAccumulate(uVar3,uVar5);
  uVar4 = uVar4 ^ 0x8000000000000000;
  uVar2 = PackedFloatingMUL(CONCAT44(uVar9,(int)((ulonglong)uVar7 >> 0x20)),uVar2);
  uVar6 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar2 = PackedFloatingMUL(uVar4,uVar4);
  uVar3 = PackedFloatingMUL(uVar6 << 0x20,uVar6 << 0x20);
  uVar2 = PackedFloatingADD(uVar2,uVar3);
  uVar3 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar2 = PackedFloatingReciprocalSQRAprox(CONCAT44(uVar9,(int)uVar7),uVar3);
  uVar8 = PackedFloatingCompareGT(uVar3,0x80000000800000);
  uVar5 = PackedFloatingMUL(uVar2,uVar2);
  uVar3 = PackedFloatingReciprocalSQRIter1(uVar3,uVar5);
  uVar3 = PackedFloatingReciprocalIter2(uVar3,uVar2);
  uVar2 = PackedFloatingMUL(uVar4 & uVar8,uVar3);
  uVar5 = PackedFloatingMUL(uVar6 & uVar8,uVar3);
  uVar3 = PackedFloatingMUL(uVar2,*param_2);
  uVar7 = PackedFloatingMUL(uVar5,(ulonglong)uVar1);
  uVar3 = PackedFloatingAccumulate(uVar3,uVar3);
  uVar3 = PackedFloatingADD(uVar3,uVar7);
  *param_1 = uVar2;
  param_1[1] = CONCAT44((int)uVar3,(int)uVar5) ^ 0x8000000000000000;
  FastExitMediaState();
  return;
}


// ==== 0x5f550d FUN_005f550d

undefined8 *
FUN_005f550d(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  uVar3 = *param_2;
  uVar5 = param_2[1];
  uVar1 = *param_3;
  uVar2 = PackedFloatingMUL(uVar3,*param_4);
  uVar4 = PackedFloatingMUL(uVar5,(ulonglong)*(uint *)(param_4 + 1));
  uVar2 = PackedFloatingADD(uVar2,uVar4);
  uVar4 = PackedFloatingMUL(uVar3,uVar1);
  uVar6 = PackedFloatingMUL(uVar5,(ulonglong)*(uint *)(param_3 + 1));
  uVar4 = PackedFloatingADD(uVar4,uVar6);
  uVar2 = PackedFloatingSUB(uVar4,uVar2);
  uVar7 = CONCAT44(0x3f800000,*(uint *)(param_3 + 1));
  uVar4 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar2 = PackedFloatingCompareEQ(0,uVar4);
  uVar6 = FloatingReciprocalAprox(uVar6,uVar4);
  uVar3 = PackedFloatingMUL(uVar3,uVar1);
  if ((int)uVar2 != 0) {
    FastExitMediaState();
    return (undefined8 *)0x0;
  }
  uVar5 = PackedFloatingMUL(uVar5,uVar7);
  uVar2 = PackedFloatingReciprocalIter1(uVar4,uVar6);
  uVar3 = PackedFloatingADD(uVar3,uVar5);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar6);
  uVar3 = PackedFloatingAccumulate(uVar3,uVar3);
  uVar5 = PackedFloatingSUB(*param_4,uVar1);
  uVar3 = PackedFloatingMUL(uVar3,uVar2);
  uVar2 = PackedFloatingSUB((ulonglong)*(uint *)(param_4 + 1),uVar7);
  uVar5 = PackedFloatingMUL(uVar5,uVar3);
  uVar2 = PackedFloatingMUL(uVar2,uVar3);
  uVar3 = PackedFloatingADD(uVar5,uVar1);
  uVar5 = PackedFloatingADD(uVar2,uVar7);
  *param_1 = uVar3;
  *(int *)(param_1 + 1) = (int)uVar5;
  FastExitMediaState();
  return param_1;
}


// ==== 0x5f55cb FUN_005f55cb

void FUN_005f55cb(undefined8 *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 in_MM4;
  undefined8 uVar5;
  
  uVar1 = *param_2;
  uVar3 = param_2[1] & 0xffffffff;
  uVar2 = PackedFloatingMUL(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar3,uVar3);
  uVar2 = PackedFloatingADD(uVar2,uVar4);
  uVar2 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar5 = PackedFloatingReciprocalSQRAprox(in_MM4,uVar2);
  uVar3 = PackedFloatingCompareGT(uVar2,0x80000000800000);
  uVar4 = PackedFloatingMUL(uVar5,uVar5);
  uVar2 = PackedFloatingReciprocalSQRIter1(uVar2,uVar4);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar5);
  uVar4 = PackedFloatingMUL(uVar1 & uVar3,uVar2);
  uVar2 = PackedFloatingMUL(param_2[1] & uVar3,uVar2);
  *param_1 = uVar4;
  param_1[1] = uVar2;
  FastExitMediaState();
  return;
}


// ==== 0x5f562f FUN_005f562f

void FUN_005f562f(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  FastExitMediaState();
  uVar1 = (undefined4)*param_2;
  uVar5 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)((ulonglong)*param_2 >> 0x20);
  uVar8 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)param_2[1];
  uVar9 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)((ulonglong)param_2[1] >> 0x20);
  uVar6 = CONCAT44(uVar1,uVar1);
  uVar2 = PackedFloatingMUL(uVar5,*param_3);
  uVar3 = PackedFloatingMUL(uVar8,param_3[2]);
  uVar4 = PackedFloatingMUL(uVar9,param_3[4]);
  uVar7 = PackedFloatingMUL(uVar6,param_3[6]);
  uVar2 = PackedFloatingADD(uVar2,uVar3);
  uVar3 = PackedFloatingMUL(uVar5,param_3[1]);
  uVar5 = PackedFloatingADD(uVar4,uVar7);
  uVar8 = PackedFloatingMUL(uVar8,param_3[3]);
  uVar9 = PackedFloatingMUL(uVar9,param_3[5]);
  uVar4 = PackedFloatingMUL(uVar6,param_3[7]);
  uVar5 = PackedFloatingADD(uVar2,uVar5);
  uVar2 = PackedFloatingADD(uVar3,uVar8);
  uVar8 = PackedFloatingADD(uVar9,uVar4);
  uVar2 = PackedFloatingADD(uVar2,uVar8);
  *param_1 = uVar5;
  param_1[1] = uVar2;
  FastExitMediaState();
  return;
}


// ==== 0x5f56ad FUN_005f56ad

undefined4 FUN_005f56ad(uint param_1)

{
  char *in_EAX;
  undefined4 uVar1;
  int unaff_EBX;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  uVar3 = 0;
  bVar4 = param_1 == 0;
  if (param_1 != 0) {
    iVar2 = unaff_EBX - (int)in_EAX;
    do {
      if (in_EAX[iVar2] < *in_EAX) {
        return 0xffffffff;
      }
      if (*in_EAX < in_EAX[iVar2]) goto LAB_005f56da;
      uVar3 = uVar3 + 1;
      in_EAX = in_EAX + 1;
    } while (uVar3 < param_1);
    bVar4 = uVar3 == param_1;
  }
  if ((bVar4) && (*(char *)(uVar3 + unaff_EBX) != '\0')) {
LAB_005f56da:
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x5f56eb FUN_005f56eb

void __fastcall FUN_005f56eb(undefined4 *param_1)

{
  void *_Memory;
  int *piVar1;
  int iVar2;
  
  *param_1 = &PTR_FUN_006a3da8;
  _free((void *)param_1[3]);
  piVar1 = param_1 + 4;
  iVar2 = 0xb;
  do {
    while (*piVar1 != 0) {
      _Memory = (void *)*piVar1;
      *piVar1 = *(int *)((int)_Memory + 0x24);
      _free(_Memory);
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== 0x5f5722 FUN_005f5722

void * __thiscall FUN_005f5722(void *param_1,byte param_2)

{
  FUN_005f56eb();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5f573e FUN_005f573e

short * __thiscall FUN_005f573e(int param_1,int param_2,short *param_3)

{
  ushort *puVar1;
  int iVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  uint local_c;
  
  puVar1 = (ushort *)(param_3 + 5);
  if (*puVar1 == 0) {
    if (*(short *)(param_2 + 4) == 0) {
      uVar8 = (uint)(ushort)param_3[3];
      uVar3 = param_3[2];
    }
    else {
      if (*param_3 == 3) {
        uVar4 = param_3[2];
        uVar3 = param_3[3];
      }
      else {
        uVar4 = param_3[3];
        uVar3 = param_3[2];
      }
      uVar8 = (int)(uVar4 + 3) >> 2;
    }
    param_3 = (short *)(uVar8 * uVar3);
  }
  else {
    piVar6 = (int *)(param_3 + 6);
    param_3 = (short *)0x0;
    iVar5 = *(int *)(param_1 + 0xc);
    local_c = (uint)*puVar1;
    if (local_c != 0) {
      piVar6 = (int *)(*piVar6 + iVar5 + 4);
      do {
        if (*piVar6 != 0) {
          iVar2 = *piVar6 + iVar5;
          iVar7 = FUN_005f573e(param_2,iVar2);
          param_3 = (short *)((int)param_3 + iVar7 * (uint)*(ushort *)(iVar2 + 8));
        }
        piVar6 = piVar6 + 2;
        local_c = local_c - 1;
      } while (local_c != 0);
    }
  }
  return param_3;
}


// ==== 0x5f57dd FUN_005f57dd

undefined4 __thiscall FUN_005f57dd(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 8) < 0x14) || (**(uint **)(param_1 + 0xc) < 0x14)) {
    uVar1 = 0x88760b59;
  }
  else {
    *param_2 = *(uint **)(param_1 + 0xc);
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x5f57fd FUN_005f57fd

int __thiscall FUN_005f57fd(int *param_1,uint param_2,int *param_3,int *param_4,int *param_5)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  undefined8 uVar9;
  
  if (param_2 == 0) {
    return -0x7789f794;
  }
  if (param_2 < 0x10000) {
    uVar9 = FUN_005f57dd(&param_2);
    uVar5 = (uint)((ulonglong)uVar9 >> 0x20);
    if ((int)uVar9 < 0) {
      return (int)uVar9;
    }
    if (*(uint *)(param_2 + 0xc) <= uVar5 - 1) {
      return -0x7789f4a7;
    }
    iVar3 = *(int *)(param_2 + 0x10) + (uVar5 - 1) * 0x14 + param_1[3];
    *param_3 = iVar3;
    *param_4 = *(int *)(iVar3 + 0xc) + param_1[3];
    if (param_5 != (int *)0x0) {
      piVar4 = (int *)*param_3;
      pbVar6 = (byte *)(*piVar4 + param_1[3]);
      param_3 = (int *)0x1;
      for (; uVar5 < *(uint *)(param_2 + 0xc); uVar5 = uVar5 + 1) {
        piVar4 = piVar4 + 5;
        pbVar2 = (byte *)(*piVar4 + param_1[3]);
        pbVar7 = pbVar6;
        if (pbVar6 != pbVar2) {
          do {
            bVar1 = *pbVar7;
            bVar8 = bVar1 < *pbVar2;
            if (bVar1 != *pbVar2) {
LAB_005f58bb:
              iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
              goto LAB_005f58c0;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar7[1];
            bVar8 = bVar1 < pbVar2[1];
            if (bVar1 != pbVar2[1]) goto LAB_005f58bb;
            pbVar2 = pbVar2 + 2;
            pbVar7 = pbVar7 + 2;
          } while (bVar1 != 0);
          iVar3 = 0;
LAB_005f58c0:
          if (iVar3 != 0) break;
        }
        param_3 = (int *)((int)param_3 + 1);
      }
      *param_5 = (int)param_3;
    }
  }
  else if ((int)param_2 < 0) {
    if (param_3 != (int *)0x0) {
      *param_3 = -param_2;
    }
    if (param_4 != (int *)0x0) {
      *param_4 = -param_2 + 0x14;
    }
    if (param_5 != (int *)0x0) {
      *param_5 = 1;
    }
  }
  else {
    iVar3 = (**(code **)(*param_1 + 0x20))(param_1,0,param_2);
    if (iVar3 == 0) {
      return -0x7789f4a7;
    }
    iVar3 = FUN_005f57fd(iVar3,param_3,param_4,param_5);
    if (iVar3 < 0) {
      return iVar3;
    }
  }
  return 0;
}


// ==== 0x5f5941 FUN_005f5941

int __thiscall FUN_005f5941(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  bool bVar6;
  
  piVar3 = (int *)(param_1 + 0x10 +
                  ((int)(((uint)*(ushort *)(param_2 + 1) * 0x1000 +
                         (uint)*(ushort *)((int)param_2 + 6)) * 0x1000 +
                        (uint)*(ushort *)(param_2 + 2)) % 0xb) * 4);
  while (*piVar3 != 0) {
    piVar1 = (int *)*piVar3;
    iVar2 = 5;
    bVar6 = true;
    piVar4 = piVar1;
    piVar5 = param_2;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *piVar4 == *piVar5;
      piVar4 = piVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      iVar2 = 4;
      bVar6 = true;
      piVar4 = piVar1 + 5;
      piVar5 = param_3;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *piVar4 == *piVar5;
        piVar4 = piVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (bVar6);
      if (bVar6) goto LAB_005f59bc;
    }
    piVar3 = piVar1 + 9;
  }
  piVar1 = _malloc(0x28);
  *piVar3 = (int)piVar1;
  iVar2 = 0;
  if (piVar1 != (int *)0x0) {
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar1 = *param_2;
      param_2 = param_2 + 1;
      piVar1 = piVar1 + 1;
    }
    iVar2 = *piVar3;
    *(int *)(iVar2 + 0x14) = *param_3;
    *(int *)(iVar2 + 0x18) = param_3[1];
    *(int *)(iVar2 + 0x1c) = param_3[2];
    *(int *)(iVar2 + 0x20) = param_3[3];
    *(undefined4 *)(*piVar3 + 0x24) = 0;
LAB_005f59bc:
    iVar2 = -*piVar3;
  }
  return iVar2;
}


// ==== 0x5f59c7 FUN_005f59c7

/* WARNING: Removing unreachable block (ram,0x005f5be3) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005f59c7(int *param_1,int param_2,uint *param_3,uint param_4)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  float fVar8;
  float fVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  byte *pbVar13;
  float *pfVar14;
  uint local_40;
  float local_3c [4];
  ushort *local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  uint local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  if ((param_1 == (int *)0x0) || (param_4 == 0)) {
    return -0x7789f794;
  }
  iVar6 = FUN_005f57dd(&local_1c);
  if (iVar6 < 0) {
    return iVar6;
  }
  uVar7 = *(uint *)((int)local_1c + 8) & 0xffff0000;
  if (uVar7 == 0xfffe0000) {
    local_8 = 1;
LAB_005f5a22:
    iVar6 = FUN_005f57fd(param_2,&local_c,&local_2c,0);
    if (iVar6 < 0) {
      return iVar6;
    }
    uVar7 = (uint)*local_2c;
    uVar1 = local_2c[4];
    if (uVar7 == 3) {
      uVar2 = local_2c[3];
      uVar3 = local_2c[2];
    }
    else {
      uVar2 = local_2c[2];
      uVar3 = local_2c[3];
    }
    uVar12 = (uint)uVar2;
    fVar8 = (float)(uint)uVar3;
    if (param_3[1] == 0) {
      param_3[1] = (uint)local_2c[1];
      *param_3 = uVar7;
      param_3[2] = uVar12;
      param_3[4] = param_3[3] / ((int)fVar8 * uVar12);
      param_3[3] = (uint)fVar8;
    }
    sVar4 = *(short *)(local_c + 4);
    local_24 = 0.0;
    if (sVar4 == 2) {
      if ((((uVar7 == 1) && (uVar12 == 1)) && ((uint)fVar8 < 5)) &&
         ((*param_3 == 0 && (param_3[1] == 2)))) {
        *param_3 = 1;
        param_3[1] = 3;
        param_3[3] = 4;
        local_24 = 1.4013e-45;
      }
    }
    else if (((sVar4 != 1) || ((*(uint *)((int)local_1c + 8) & 0xffff) < 0x200)) &&
            ((sVar4 != 0 || ((*(uint *)((int)local_1c + 8) & 0xffff) < 0x200)))) goto LAB_005f6043;
    local_40 = (uint)uVar1;
    if (param_3[4] < (uint)uVar1) {
      local_40 = param_3[4];
    }
    if ((param_3[2] < uVar12) || (param_3[3] < (uint)fVar8)) {
      iVar6 = -0x7789f794;
    }
    else {
      sVar4 = *(short *)(local_c + 4);
      local_10 = (uint)((*param_3 == 3) != (uVar7 == 3));
      if (sVar4 == 0) {
        local_28 = 1.4013e-45;
        local_18 = fVar8;
      }
      else {
        local_18 = (float)((int)fVar8 + 3U >> 2);
        local_28 = fVar8;
      }
      uVar10 = (uint)*(ushort *)(local_c + 8);
      uVar7 = (int)local_18 * uVar12 * local_40;
      if (uVar10 <= uVar7 && uVar7 - uVar10 != 0) {
        uVar7 = uVar10;
      }
      param_2 = param_4;
      if (sVar4 == 2) {
        if (local_24 == 0.0) {
          if ((((uVar12 == param_3[2]) && (fVar8 == (float)param_3[3])) &&
              (((uint)local_28 & 3) == 0)) && ((local_10 == 0 && (param_3[1] == 3)))) {
            if (local_8 != 0) {
              iVar6 = (**(code **)(*param_1 + 0x178))();
              return iVar6;
            }
            iVar6 = (**(code **)(*param_1 + 0x1b4))
                              (param_1,*(undefined2 *)(local_c + 6),param_4,uVar7);
            return iVar6;
          }
          param_4 = 0;
          local_28 = 0.0;
          iVar6 = local_c;
          if (local_40 != 0) {
            do {
              local_14 = 0;
              if (uVar12 != 0) {
                do {
                  local_1c = 0.0;
                  local_24 = 0.0;
                  if (local_18 != 0.0) {
                    do {
                      uVar10 = 0;
                      do {
                        if ((uint)fVar8 <= (uint)local_1c) break;
                        if (local_10 == 0) {
                          local_20 = *(float *)(param_2 +
                                               (param_3[3] * local_14 + (int)local_1c) * 4);
                        }
                        else {
                          local_20 = *(float *)(param_2 +
                                               (param_3[2] * (int)local_1c + local_14) * 4);
                        }
                        uVar5 = param_3[1];
                        if (uVar5 == 1) {
                          if (local_20 == 0.0) {
LAB_005f5d0e:
                            fVar9 = 0.0;
                          }
                          else {
                            fVar9 = 1.0;
                          }
                        }
                        else if (uVar5 == 2) {
                          fVar9 = (float)(int)local_20;
                        }
                        else {
                          fVar9 = local_20;
                          if (uVar5 != 3) goto LAB_005f5d0e;
                        }
                        local_3c[uVar10] = fVar9;
                        uVar10 = uVar10 + 1;
                        local_1c = (float)((int)local_1c + 1);
                      } while (uVar10 < 4);
                      if (uVar10 < 4) {
                        pfVar14 = local_3c + uVar10;
                        for (iVar11 = 4 - uVar10; iVar11 != 0; iVar11 = iVar11 + -1) {
                          *pfVar14 = 0.0;
                          pfVar14 = pfVar14 + 1;
                        }
                      }
                      if (local_8 == 0) {
                        iVar6 = (**(code **)(*param_1 + 0x1b4))
                                          (param_1,*(ushort *)(iVar6 + 6) + param_4,local_3c,1);
                      }
                      else {
                        iVar6 = (**(code **)(*param_1 + 0x178))();
                      }
                      if (iVar6 < 0) {
                        return iVar6;
                      }
                      param_4 = param_4 + 1;
                      if (uVar7 <= param_4) goto LAB_005f5c3b;
                      local_24 = (float)((int)local_24 + 1);
                      iVar6 = local_c;
                    } while ((uint)local_24 < (uint)local_18);
                  }
                  local_14 = local_14 + 1;
                } while (local_14 < uVar12);
              }
              local_28 = (float)((int)local_28 + 1);
              param_2 = param_2 + param_3[3] * param_3[2] * 4;
            } while ((uint)local_28 < local_40);
          }
        }
        else {
          uVar12 = 0;
          if (uVar7 != 0) {
            pbVar13 = (byte *)(param_4 + 1);
            do {
              local_3c[0] = (float)pbVar13[1] * _K_BLUR_MIN_T;
              local_3c[1] = (float)*pbVar13 * _K_BLUR_MIN_T;
              local_3c[2] = (float)(*(uint *)(pbVar13 + -1) & 0xff) * _K_BLUR_MIN_T;
              local_3c[3] = (float)pbVar13[2] * _K_BLUR_MIN_T;
              if (local_8 == 0) {
                iVar6 = (**(code **)(*param_1 + 0x1b4))
                                  (param_1,*(ushort *)(local_c + 6) + uVar12,local_3c,1);
              }
              else {
                iVar6 = (**(code **)(*param_1 + 0x178))();
              }
              if (iVar6 < 0) {
                return iVar6;
              }
              uVar12 = uVar12 + 1;
              pbVar13 = pbVar13 + 4;
            } while (uVar12 < uVar7);
          }
        }
      }
      else if (sVar4 == 1) {
        if (((uVar12 == param_3[2]) && (fVar8 == (float)param_3[3])) &&
           ((((uint)local_28 & 3) == 0 && ((local_10 == 0 && (param_3[1] == 2)))))) {
          if (local_8 != 0) {
            iVar6 = (**(code **)(*param_1 + 0x180))();
            return iVar6;
          }
          iVar6 = (**(code **)(*param_1 + 0x1bc))
                            (param_1,*(undefined2 *)(local_c + 6),param_4,uVar7);
          return iVar6;
        }
        param_4 = 0;
        local_20 = 0.0;
        iVar6 = local_c;
        if (local_40 != 0) {
          do {
            local_14 = 0;
            if (uVar12 != 0) {
              do {
                local_28 = 0.0;
                local_24 = 0.0;
                if (local_18 != 0.0) {
                  do {
                    uVar10 = 0;
                    do {
                      if ((uint)fVar8 <= (uint)local_28) break;
                      if (local_10 == 0) {
                        iVar11 = param_3[3] * local_14 + (int)local_28;
                      }
                      else {
                        iVar11 = param_3[2] * (int)local_28 + local_14;
                      }
                      fVar9 = *(float *)(param_2 + iVar11 * 4);
                      uVar5 = param_3[1];
                      local_1c = fVar9;
                      if (uVar5 == 1) {
                        local_3c[uVar10] = (float)(uint)(fVar9 != 0.0);
                      }
                      else {
                        if (uVar5 != 2) {
                          if (uVar5 != 3) {
                            local_3c[uVar10] = 0.0;
                            goto LAB_005f5e93;
                          }
                          fVar9 = (float)__ftol();
                        }
                        local_3c[uVar10] = fVar9;
                      }
LAB_005f5e93:
                      uVar10 = uVar10 + 1;
                      local_28 = (float)((int)local_28 + 1);
                    } while (uVar10 < 4);
                    if (uVar10 < 4) {
                      pfVar14 = local_3c + uVar10;
                      for (iVar11 = 4 - uVar10; iVar11 != 0; iVar11 = iVar11 + -1) {
                        *pfVar14 = 0.0;
                        pfVar14 = pfVar14 + 1;
                      }
                    }
                    if (local_8 == 0) {
                      iVar6 = (**(code **)(*param_1 + 0x1bc))
                                        (param_1,*(ushort *)(iVar6 + 6) + param_4,local_3c,1);
                    }
                    else {
                      iVar6 = (**(code **)(*param_1 + 0x180))();
                    }
                    if (iVar6 < 0) {
                      return iVar6;
                    }
                    param_4 = param_4 + 1;
                    if (uVar7 <= param_4) goto LAB_005f5c3b;
                    local_24 = (float)((int)local_24 + 1);
                    iVar6 = local_c;
                  } while ((uint)local_24 < (uint)local_18);
                }
                local_14 = local_14 + 1;
              } while (local_14 < uVar12);
            }
            local_20 = (float)((int)local_20 + 1);
            param_2 = param_2 + param_3[3] * param_3[2] * 4;
          } while ((uint)local_20 < local_40);
        }
      }
      else if (sVar4 == 0) {
        if (((local_10 == 0) && (uVar12 == param_3[2])) && (fVar8 == (float)param_3[3])) {
          if (local_8 != 0) {
            iVar6 = (**(code **)(*param_1 + 0x188))();
            return iVar6;
          }
          iVar6 = (**(code **)(*param_1 + 0x1c4))
                            (param_1,*(undefined2 *)(local_c + 6),param_4,uVar7);
          return iVar6;
        }
        param_4 = 0;
        local_28 = 0.0;
        iVar6 = local_c;
        if (local_40 != 0) {
          do {
            local_14 = 0;
            if (uVar12 != 0) {
              do {
                local_18 = 0.0;
                if (fVar8 != 0.0) {
                  do {
                    if (local_10 == 0) {
                      iVar11 = param_3[3] * local_14 + (int)local_18;
                    }
                    else {
                      iVar11 = param_3[2] * (int)local_18 + local_14;
                    }
                    if (local_8 == 0) {
                      iVar6 = (**(code **)(*param_1 + 0x1c4))
                                        (param_1,*(ushort *)(iVar6 + 6) + param_4,
                                         param_2 + iVar11 * 4,1);
                    }
                    else {
                      iVar6 = (**(code **)(*param_1 + 0x188))();
                    }
                    if (iVar6 < 0) {
                      return iVar6;
                    }
                    param_4 = param_4 + 1;
                    if (uVar7 <= param_4) goto LAB_005f5c3b;
                    local_18 = (float)((int)local_18 + 1);
                    iVar6 = local_c;
                  } while ((uint)local_18 < (uint)fVar8);
                }
                local_14 = local_14 + 1;
              } while (local_14 < uVar12);
            }
            local_28 = (float)((int)local_28 + 1);
            param_2 = param_2 + param_3[3] * param_3[2] * 4;
          } while ((uint)local_28 < local_40);
        }
      }
LAB_005f5c3b:
      iVar6 = 0;
    }
  }
  else {
    if (uVar7 == 0xffff0000) {
      local_8 = 0;
      goto LAB_005f5a22;
    }
LAB_005f6043:
    iVar6 = -0x7789f4a7;
  }
  return iVar6;
}


// ==== 0x5f604f FUN_005f604f

int FUN_005f604f(int *param_1,uint param_2,int *param_3,int *param_4)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  float fVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  float *pfVar11;
  uint uVar12;
  float local_48 [4];
  short *local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  float local_28;
  int local_24;
  int local_20;
  int local_1c;
  float local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  if ((param_1 == (int *)0x0) || (param_4 == (int *)0x0)) {
    return -0x7789f794;
  }
  iVar4 = FUN_005f57dd(&local_34);
  if (iVar4 < 0) {
    return iVar4;
  }
  uVar5 = *(uint *)(local_34 + 8) & 0xffff0000;
  if (uVar5 == 0xfffe0000) {
    local_24 = 1;
  }
  else {
    if (uVar5 != 0xffff0000) {
      return -0x7789f4a7;
    }
    local_24 = 0;
  }
  iVar4 = FUN_005f57fd(param_2,&local_8,&local_38,0);
  if (iVar4 < 0) {
    return iVar4;
  }
  if (*local_38 == 3) {
    uVar1 = local_38[3];
    uVar2 = local_38[2];
  }
  else {
    uVar1 = local_38[2];
    uVar2 = local_38[3];
  }
  uVar8 = (uint)uVar1;
  uVar5 = (uint)uVar2;
  sVar3 = *(short *)(local_8 + 4);
  if (((sVar3 != 2) && ((sVar3 != 1 || ((*(uint *)(local_34 + 8) & 0xffff) < 0x200)))) &&
     ((sVar3 != 0 || ((*(uint *)(local_34 + 8) & 0xffff) < 0x200)))) {
    return -0x7789f4a7;
  }
  uVar10 = (uint)(ushort)local_38[4];
  if ((uint)param_3[4] < (uint)(ushort)local_38[4]) {
    uVar10 = param_3[4];
  }
  if (((uint)param_3[2] < uVar8) || ((uint)param_3[3] < uVar5)) {
    return -0x7789f794;
  }
  local_34 = (uint)((*param_3 == 3) != (*local_38 == 3));
  local_14 = uVar5;
  if (sVar3 != 0) {
    local_14 = uVar5 + 3 >> 2;
  }
  local_20 = local_14 * uVar8;
  local_c = local_20 * uVar10;
  if ((uint)*(ushort *)(local_8 + 8) < local_20 * uVar10) {
    local_c = (uint)*(ushort *)(local_8 + 8);
  }
  if (sVar3 == 2) {
    param_2 = 0;
    local_30 = 0;
    if (uVar10 != 0) {
      do {
        local_1c = *param_4;
        if (local_1c == 0) {
          param_2 = param_2 + local_20;
          if (local_c <= param_2) {
            return 0;
          }
        }
        else {
          local_10 = 0;
          if (uVar8 != 0) {
            do {
              local_18 = 0.0;
              local_2c = 0;
              if (local_14 != 0) {
                do {
                  uVar9 = 0;
                  do {
                    if (uVar5 <= (uint)local_18) break;
                    if (local_34 == 0) {
                      local_28 = *(float *)(local_1c + (param_3[3] * local_10 + (int)local_18) * 4);
                    }
                    else {
                      local_28 = *(float *)(local_1c + (param_3[2] * (int)local_18 + local_10) * 4);
                    }
                    iVar4 = param_3[1];
                    if (iVar4 == 1) {
                      if (local_28 == 0.0) {
LAB_005f6258:
                        fVar6 = 0.0;
                      }
                      else {
                        fVar6 = 1.0;
                      }
                    }
                    else if (iVar4 == 2) {
                      fVar6 = (float)(int)local_28;
                    }
                    else {
                      fVar6 = local_28;
                      if (iVar4 != 3) goto LAB_005f6258;
                    }
                    local_48[uVar9] = fVar6;
                    uVar9 = uVar9 + 1;
                    local_18 = (float)((int)local_18 + 1);
                  } while (uVar9 < 4);
                  if (uVar9 < 4) {
                    pfVar11 = local_48 + uVar9;
                    for (iVar4 = 4 - uVar9; iVar4 != 0; iVar4 = iVar4 + -1) {
                      *pfVar11 = 0.0;
                      pfVar11 = pfVar11 + 1;
                    }
                  }
                  if (local_24 == 0) {
                    iVar4 = (**(code **)(*param_1 + 0x1b4))
                                      (param_1,*(ushort *)(local_8 + 6) + param_2,local_48,1);
                  }
                  else {
                    iVar4 = (**(code **)(*param_1 + 0x178))();
                  }
                  if (iVar4 < 0) {
                    return iVar4;
                  }
                  param_2 = param_2 + 1;
                  if (local_c <= param_2) {
                    return 0;
                  }
                  local_2c = local_2c + 1;
                } while (local_2c < local_14);
              }
              local_10 = local_10 + 1;
            } while (local_10 < uVar8);
          }
        }
        local_30 = local_30 + 1;
        param_4 = param_4 + 1;
      } while (local_30 < uVar10);
    }
  }
  else if (sVar3 == 1) {
    param_2 = 0;
    local_28 = 0.0;
    if (uVar10 != 0) {
      do {
        local_1c = *param_4;
        if (local_1c == 0) {
          param_2 = param_2 + local_20;
          if (local_c <= param_2) {
            return 0;
          }
        }
        else {
          local_10 = 0;
          if (uVar8 != 0) {
            do {
              local_30 = 0;
              local_2c = 0;
              if (local_14 != 0) {
                do {
                  uVar9 = 0;
                  do {
                    if (uVar5 <= local_30) break;
                    if (local_34 == 0) {
                      iVar4 = param_3[3] * local_10 + local_30;
                    }
                    else {
                      iVar4 = param_3[2] * local_30 + local_10;
                    }
                    fVar6 = *(float *)(local_1c + iVar4 * 4);
                    iVar4 = param_3[1];
                    local_18 = fVar6;
                    if (iVar4 == 1) {
                      local_48[uVar9] = (float)(uint)(fVar6 != 0.0);
                    }
                    else {
                      if (iVar4 != 2) {
                        if (iVar4 != 3) {
                          local_48[uVar9] = 0.0;
                          goto LAB_005f639b;
                        }
                        fVar6 = (float)__ftol();
                      }
                      local_48[uVar9] = fVar6;
                    }
LAB_005f639b:
                    uVar9 = uVar9 + 1;
                    local_30 = local_30 + 1;
                  } while (uVar9 < 4);
                  if (uVar9 < 4) {
                    pfVar11 = local_48 + uVar9;
                    for (iVar4 = 4 - uVar9; iVar4 != 0; iVar4 = iVar4 + -1) {
                      *pfVar11 = 0.0;
                      pfVar11 = pfVar11 + 1;
                    }
                  }
                  if (local_24 == 0) {
                    iVar4 = (**(code **)(*param_1 + 0x1bc))
                                      (param_1,*(ushort *)(local_8 + 6) + param_2,local_48,1);
                  }
                  else {
                    iVar4 = (**(code **)(*param_1 + 0x180))();
                  }
                  if (iVar4 < 0) {
                    return iVar4;
                  }
                  param_2 = param_2 + 1;
                  if (local_c <= param_2) {
                    return 0;
                  }
                  local_2c = local_2c + 1;
                } while (local_2c < local_14);
              }
              local_10 = local_10 + 1;
            } while (local_10 < uVar8);
          }
        }
        local_28 = (float)((int)local_28 + 1);
        param_4 = param_4 + 1;
      } while ((uint)local_28 < uVar10);
    }
  }
  else if (sVar3 == 0) {
    param_2 = 0;
    local_30 = 0;
    if (uVar10 != 0) {
      do {
        iVar4 = *param_4;
        if (iVar4 == 0) {
          param_2 = param_2 + local_20;
          if (local_c <= param_2) {
            return 0;
          }
        }
        else {
          uVar9 = 0;
          if (uVar8 != 0) {
            do {
              uVar12 = 0;
              if (uVar5 != 0) {
                do {
                  if (local_34 == 0) {
                    iVar7 = param_3[3] * uVar9 + uVar12;
                  }
                  else {
                    iVar7 = param_3[2] * uVar12 + uVar9;
                  }
                  if (local_24 == 0) {
                    iVar7 = (**(code **)(*param_1 + 0x1c4))
                                      (param_1,*(ushort *)(local_8 + 6) + param_2,iVar4 + iVar7 * 4,
                                       1);
                  }
                  else {
                    iVar7 = (**(code **)(*param_1 + 0x188))();
                  }
                  if (iVar7 < 0) {
                    return iVar7;
                  }
                  param_2 = param_2 + 1;
                  if (local_c <= param_2) {
                    return 0;
                  }
                  uVar12 = uVar12 + 1;
                } while (uVar12 < uVar5);
              }
              uVar9 = uVar9 + 1;
            } while (uVar9 < uVar8);
          }
        }
        local_30 = local_30 + 1;
        param_4 = param_4 + 1;
      } while (local_30 < uVar10);
    }
  }
  return 0;
}


// ==== 0x5f6506 FUN_005f6506

undefined4 FUN_005f6506(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  
  *param_3 = 0;
  iVar1 = 4;
  bVar4 = true;
  piVar2 = param_2;
  piVar3 = &DAT_006abe14;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *piVar2 == *piVar3;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (bVar4);
  if (!bVar4) {
    iVar1 = 4;
    bVar4 = true;
    piVar2 = param_2;
    piVar3 = &DAT_006a08e8;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *piVar2 == *piVar3;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (bVar4);
    if (!bVar4) {
      iVar1 = 4;
      bVar4 = true;
      piVar2 = &DAT_006a08d8;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *param_2 == *piVar2;
        param_2 = param_2 + 1;
        piVar2 = piVar2 + 1;
      } while (bVar4);
      if (!bVar4) {
        return 0x80004002;
      }
    }
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}


// ==== 0x5f655e FUN_005f655e

int FUN_005f655e(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  iVar1 = iVar2 + -1;
  *(int *)(param_1 + 4) = iVar1;
  if (iVar2 == 1) {
    FUN_005f5722(1);
  }
  return iVar1;
}


// ==== 0x5f657d FUN_005f657d

undefined4 FUN_005f657d(int param_1,int *param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 == (int *)0x0) {
    uVar2 = 0x8876086c;
  }
  else if (((*(uint *)(param_1 + 8) < 0x14) || (puVar1 = *(uint **)(param_1 + 0xc), *puVar1 < 0x14))
          || (*(uint *)(param_1 + 8) <= puVar1[1])) {
    uVar2 = 0x88760b59;
  }
  else {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    if (puVar1[1] == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(param_1 + 0xc) + puVar1[1];
    }
    *param_2 = iVar3;
    param_2[1] = puVar1[2];
    param_2[2] = puVar1[3];
    uVar2 = 0;
  }
  return uVar2;
}


// ==== 0x5f65da FUN_005f65da

int FUN_005f65da(int param_1,uint param_2,int *param_3,uint *param_4)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  int *piVar4;
  uint local_10;
  ushort *local_c;
  uint *local_8;
  
  piVar3 = param_3;
  if ((param_3 == (int *)0x0) && (param_4 == (uint *)0x0)) {
    iVar1 = -0x7789f794;
  }
  else {
    iVar1 = FUN_005f57fd(param_2,&local_8,&local_c,&local_10);
    if (-1 < iVar1) {
      if (param_3 != (int *)0x0) {
        if (param_4 == (uint *)0x0) {
          param_3 = (int *)0x1;
        }
        else {
          param_3 = (int *)*param_4;
          if (local_10 <= param_3) {
            param_3 = (int *)local_10;
          }
        }
        param_2 = 0;
        if (param_3 != (int *)0x0) {
          do {
            if ((*(uint *)(param_1 + 8) <= *local_8) || (*(uint *)(param_1 + 8) <= local_8[4])) {
              return -0x7789f4a7;
            }
            piVar4 = piVar3;
            for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
              *piVar4 = 0;
              piVar4 = piVar4 + 1;
            }
            if (*local_8 == 0) {
              iVar1 = 0;
            }
            else {
              iVar1 = *(int *)(param_1 + 0xc) + *local_8;
            }
            *piVar3 = iVar1;
            piVar3[1] = (uint)(ushort)local_8[1];
            piVar3[2] = (uint)*(ushort *)((int)local_8 + 6);
            piVar3[3] = (uint)(ushort)local_8[2];
            piVar3[4] = (uint)*local_c;
            piVar3[5] = (uint)local_c[1];
            piVar3[6] = (uint)local_c[2];
            piVar3[7] = (uint)local_c[3];
            piVar3[8] = (uint)local_c[4];
            piVar3[9] = (uint)local_c[5];
            piVar3[10] = piVar3[7] * piVar3[8] * piVar3[6] * 4;
            if (local_8[4] == 0) {
              iVar1 = 0;
            }
            else {
              iVar1 = *(int *)(param_1 + 0xc) + local_8[4];
            }
            piVar3[0xb] = iVar1;
            puVar2 = local_8;
            if (param_3 != (int *)0x0) {
              puVar2 = local_8 + 5;
              piVar3 = piVar3 + 0xc;
              local_c = (ushort *)(local_8[8] + *(int *)(param_1 + 0xc));
            }
            param_2 = param_2 + 1;
            local_8 = puVar2;
          } while (param_2 < param_3);
        }
      }
      if (param_4 != (uint *)0x0) {
        *param_4 = local_10;
      }
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ==== 0x5f672a FUN_005f672a

int FUN_005f672a(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint local_24;
  short local_1e;
  short local_1c;
  int local_10;
  uint *local_c;
  int *local_8;
  
  iVar1 = param_1;
  if (param_2 == 0) {
    iVar1 = FUN_005f57dd(&param_1);
    if (((iVar1 < 0) || (*(uint *)(param_1 + 0xc) <= param_3)) || (0xfffd < param_3)) {
      iVar1 = 0;
    }
    else {
      iVar1 = param_3 + 1;
    }
  }
  else {
    iVar2 = FUN_005f57fd(param_2,&local_c,&param_2,0);
    if (((-1 < iVar2) && (param_3 < *(ushort *)(param_2 + 10))) &&
       (*(int *)(param_2 + 0xc) + (uint)*(ushort *)(param_2 + 10) * 8 <= *(uint *)(iVar1 + 8))) {
      iVar1 = *(int *)(iVar1 + 0xc);
      iVar3 = *(int *)(param_2 + 0xc) + iVar1;
      puVar4 = local_c;
      puVar5 = &local_24;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      uVar6 = 0;
      local_8 = (int *)(iVar3 + 4);
      local_10 = iVar3;
      if (*local_8 != 0) {
        while (*local_8 + 0x10U <= *(uint *)(param_1 + 8)) {
          iVar2 = *local_8 + iVar1;
          param_2 = iVar2;
          local_1c = FUN_005f573e(&local_24,iVar2);
          local_1c = local_1c * *(short *)(iVar2 + 8);
          if (uVar6 == param_3) {
            local_24 = *(uint *)(local_10 + uVar6 * 8);
            if ((local_24 != 0) && (local_24 < *(uint *)(param_1 + 8))) {
              iVar1 = FUN_005f5941(&local_24,iVar2);
              return iVar1;
            }
            break;
          }
          local_1e = local_1e + local_1c;
          local_8 = local_8 + 2;
          uVar6 = uVar6 + 1;
          if (*local_8 == 0) break;
        }
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}


// ==== 0x5f6829 FUN_005f6829

int FUN_005f6829(int *param_1,byte *param_2,char *param_3)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  byte bVar4;
  uint uVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  int *piVar11;
  undefined4 *puVar12;
  byte *pbVar13;
  undefined4 *puVar14;
  bool bVar15;
  undefined8 uVar16;
  undefined4 local_3c;
  short local_36;
  short local_34;
  undefined4 *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int *local_18;
  uint local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  if (param_3 != (char *)0x0) {
    while( true ) {
      while( true ) {
        bVar15 = false;
        iVar7 = _isspace((int)*param_3);
        while (iVar7 != 0) {
          param_3 = param_3 + 1;
          iVar7 = _isspace((int)*param_3);
        }
        if (*param_3 == '\0') {
          return (int)param_2;
        }
        if ((param_2 != (byte *)0x0) && (*param_3 == '.')) {
          param_3 = param_3 + 1;
          iVar7 = _isspace((int)*param_3);
          while (iVar7 != 0) {
            param_3 = param_3 + 1;
            iVar7 = _isspace((int)*param_3);
          }
          bVar15 = true;
        }
        cVar3 = *param_3;
        if (cVar3 == '@') {
          return 0;
        }
        if (((param_2 == (byte *)0x0) || (bVar15)) || (cVar3 != '[')) break;
        cVar3 = param_3[1];
        iVar7 = 0;
        iVar10 = 1;
        while (iVar8 = _isspace((int)cVar3), iVar8 != 0) {
          iVar10 = iVar10 + 1;
          cVar3 = param_3[iVar10];
        }
        while (iVar8 = _isdigit((int)param_3[iVar10]), iVar8 != 0) {
          iVar7 = param_3[iVar10] + -0x30 + iVar7 * 10;
          iVar10 = iVar10 + 1;
        }
        while (iVar8 = _isspace((int)param_3[iVar10]), iVar8 != 0) {
          iVar10 = iVar10 + 1;
        }
        if (param_3[iVar10] != ']') {
          return 0;
        }
        param_2 = (byte *)(**(code **)(*param_1 + 0x24))(param_1,param_2,iVar7);
        if (param_2 == (byte *)0x0) {
          return 0;
        }
        param_3 = param_3 + iVar10 + 1;
      }
      iVar7 = _isalnum((int)cVar3);
      if (((iVar7 == 0) && (*param_3 != '_')) && (*param_3 != '$')) break;
      local_10 = 1;
      while( true ) {
        pcVar1 = param_3 + local_10;
        iVar7 = _isalnum((int)*pcVar1);
        if ((iVar7 == 0) && (*pcVar1 != '_')) break;
        local_10 = local_10 + 1;
      }
      if (param_2 == (byte *)0x0) {
        uVar16 = FUN_005f57dd(&local_24);
        iVar7 = (int)((ulonglong)uVar16 >> 0x20);
        if ((int)uVar16 < 0) {
          return 0;
        }
        param_2 = *(byte **)(local_24 + 0xc);
        local_14 = *(uint *)(iVar7 + 8);
        if (local_14 < (uint)(*(int *)(local_24 + 0x10) + (int)param_2 * 0x14)) {
          return 0;
        }
        local_8 = *(int *)(iVar7 + 0xc);
        piVar11 = (int *)0x0;
        local_c = (int *)0x0;
        iVar7 = local_8 + *(int *)(local_24 + 0x10);
        if (param_2 != (byte *)0x0) {
          do {
            piVar11 = (int *)((uint)((int)param_2 + (int)local_c) >> 1);
            uVar5 = *(uint *)(iVar7 + (int)piVar11 * 0x14);
            if (uVar5 == 0) {
              return 0;
            }
            if (local_14 <= uVar5) {
              return 0;
            }
            iVar10 = FUN_005f56ad(local_10);
            if (iVar10 == 0) break;
            piVar2 = piVar11;
            if (iVar10 < 0) {
              local_c = (int *)((int)piVar11 + 1);
              piVar2 = (int *)param_2;
            }
            param_2 = (byte *)piVar2;
          } while (local_c < param_2);
        }
        if ((byte *)local_c == param_2) {
          return 0;
        }
        piVar2 = (int *)(iVar7 + (int)piVar11 * 0x14);
        pbVar9 = (byte *)(*piVar2 + local_8);
        if (piVar11 != (int *)0x0) {
          local_18 = piVar2 + -5;
          do {
            param_2 = (byte *)(*local_18 + local_8);
            pbVar13 = pbVar9;
            if (pbVar9 != param_2) {
              do {
                bVar4 = *pbVar13;
                bVar15 = bVar4 < *param_2;
                if (bVar4 != *param_2) {
LAB_005f6a61:
                  iVar7 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
                  goto LAB_005f6a66;
                }
                if (bVar4 == 0) break;
                bVar4 = pbVar13[1];
                bVar15 = bVar4 < param_2[1];
                if (bVar4 != param_2[1]) goto LAB_005f6a61;
                param_2 = param_2 + 2;
                pbVar13 = pbVar13 + 2;
              } while (bVar4 != 0);
              iVar7 = 0;
LAB_005f6a66:
              if (iVar7 != 0) break;
            }
            piVar11 = (int *)((int)piVar11 + -1);
            local_18 = local_18 + -5;
          } while (piVar11 != (int *)0x0);
        }
        if ((int *)0xfffd < piVar11) {
          return 0;
        }
        param_2 = (byte *)((int)piVar11 + 1);
      }
      else {
        iVar7 = FUN_005f57fd(param_2,&local_28,&local_1c,0);
        if (iVar7 < 0) {
          return 0;
        }
        local_18 = (int *)(uint)*(ushort *)(local_1c + 10);
        local_14 = param_1[2];
        if (local_14 < (uint)(*(int *)(local_1c + 0xc) + (int)local_18 * 8)) {
          return 0;
        }
        iVar7 = param_1[3];
        local_c = (int *)0x0;
        iVar8 = *(int *)(local_1c + 0xc) + iVar7;
        bVar15 = local_18 != (int *)0x0;
        puVar12 = local_28;
        puVar14 = &local_3c;
        local_20 = iVar8;
        local_8 = iVar7;
        for (iVar10 = 5; iVar10 != 0; iVar10 = iVar10 + -1) {
          *puVar14 = *puVar12;
          puVar12 = puVar12 + 1;
          puVar14 = puVar14 + 1;
        }
        if (bVar15) {
          do {
            uVar5 = *(uint *)((int)local_c * 8 + iVar8);
            if (uVar5 == 0) {
              return 0;
            }
            if (local_14 <= uVar5) {
              return 0;
            }
            iVar10 = *(int *)((int)local_c * 8 + 4 + iVar8);
            if (iVar10 == 0) {
              return 0;
            }
            if (local_14 < iVar10 + 0x10U) {
              return 0;
            }
            iVar10 = iVar10 + iVar7;
            local_1c = iVar10;
            sVar6 = FUN_005f573e(&local_3c,iVar10);
            sVar6 = sVar6 * *(short *)(iVar10 + 8);
            iVar7 = FUN_005f56ad(local_10);
            if (iVar7 == 0) {
              local_3c = *(undefined4 *)(local_20 + (int)local_c * 8);
              local_34 = sVar6;
              param_2 = (byte *)FUN_005f5941(&local_3c,iVar10);
              break;
            }
            local_36 = local_36 + sVar6;
            local_c = (int *)((int)local_c + 1);
            iVar8 = local_20;
            iVar7 = local_8;
          } while (local_c < local_18);
        }
        if (local_c == local_18) {
          return 0;
        }
      }
      param_3 = param_3 + local_10;
    }
  }
  return 0;
}


// ==== 0x5f6ba9 FUN_005f6ba9

undefined4 FUN_005f6ba9(undefined4 param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 local_2c;
  short local_26;
  short local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined2 local_10;
  undefined2 uStack_e;
  undefined4 uStack_c;
  undefined4 *local_8;
  
  iVar2 = FUN_005f57fd(param_2,&local_8,&param_2,0);
  uVar1 = param_3;
  if (iVar2 < 0) {
    uVar3 = 0;
  }
  else if (param_3 < *(ushort *)(param_2 + 2)) {
    local_24 = FUN_005f573e(local_8,param_2);
    puVar4 = &local_2c;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *local_8;
      local_8 = local_8 + 1;
      puVar4 = puVar4 + 1;
    }
    local_26 = local_26 + (short)uVar1 * local_24;
    local_1c = 0;
    local_18 = *param_2;
    uStack_14 = param_2[1];
    uStack_c = param_2[3];
    _local_10 = CONCAT22((short)((uint)param_2[2] >> 0x10),1);
    uVar3 = FUN_005f5941(&local_2c,&local_18);
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


// ==== 0x5f6c2c FUN_005f6c2c

int FUN_005f6c2c(uint param_1,int *param_2)

{
  int *piVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined2 *puVar7;
  int local_8;
  
  iVar6 = param_1;
  if (param_2 == (int *)0x0) {
    return -0x7789f794;
  }
  iVar4 = FUN_005f57dd(&local_8);
  if (iVar4 < 0) {
    return iVar4;
  }
  uVar5 = *(uint *)(local_8 + 8) & 0xffff0000;
  if (uVar5 == 0xfffe0000) {
    bVar3 = true;
LAB_005f6c89:
    iVar4 = *(int *)(local_8 + 0xc);
    if (iVar4 != 0) {
      if (*(uint *)(param_1 + 8) < (uint)(*(int *)(local_8 + 0x10) + iVar4 * 0x14))
      goto LAB_005f6c72;
      piVar1 = (int *)(param_1 + 0xc);
      param_1 = 0;
      if (iVar4 != 0) {
        puVar7 = (undefined2 *)(*piVar1 + *(int *)(local_8 + 0x10) + 8);
        do {
          iVar4 = *(int *)(puVar7 + 4);
          if (iVar4 != 0) {
            sVar2 = puVar7[-2];
            if (sVar2 == 2) {
              if (bVar3) {
                iVar4 = (**(code **)(*param_2 + 0x178))();
              }
              else {
                iVar4 = (**(code **)(*param_2 + 0x1b4))
                                  (param_2,puVar7[-1],*(int *)(iVar6 + 0xc) + iVar4,*puVar7);
              }
            }
            else if ((sVar2 == 1) && (bVar3)) {
              iVar4 = (**(code **)(*param_2 + 0x180))
                                (param_2,puVar7[-1],*(int *)(iVar6 + 0xc) + iVar4,*puVar7);
            }
            else {
              if ((sVar2 != 0) || (!bVar3)) goto LAB_005f6c72;
              iVar4 = (**(code **)(*param_2 + 0x188))
                                (param_2,puVar7[-1],*(int *)(iVar6 + 0xc) + iVar4,*puVar7);
            }
            if (iVar4 < 0) {
              return iVar4;
            }
          }
          param_1 = param_1 + 1;
          puVar7 = puVar7 + 10;
        } while (param_1 < *(uint *)(local_8 + 0xc));
      }
    }
    iVar6 = 0;
  }
  else {
    if (uVar5 == 0xffff0000) {
      bVar3 = false;
      goto LAB_005f6c89;
    }
LAB_005f6c72:
    iVar6 = -0x7789f4a7;
  }
  return iVar6;
}


// ==== 0x5f6d66 FUN_005f6d66

void FUN_005f6d66(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 uint param_5)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  undefined4 local_8;
  
  local_14 = 0;
  local_10 = 1;
  local_8 = 1;
  local_c = param_5 >> 2;
  local_18 = 5;
  FUN_005f59c7(param_2,param_3,&local_18,param_4);
  return;
}


// ==== 0x5f6da2 FUN_005f6da2

void FUN_005f6da2(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_18 = 0;
  local_14 = 1;
  local_10 = 1;
  local_c = 1;
  local_8 = 1;
  FUN_005f59c7(param_2,param_3,&local_18,&stack0x00000010);
  return;
}


// ==== 0x5f6dd5 FUN_005f6dd5

void FUN_005f6dd5(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_18 = 0;
  local_14 = 1;
  local_10 = 1;
  local_c = 1;
  local_8 = param_5;
  FUN_005f59c7(param_2,param_3,&local_18,param_4);
  return;
}


// ==== 0x5f6e0a FUN_005f6e0a

void FUN_005f6e0a(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_18 = 0;
  local_10 = 1;
  local_c = 1;
  local_8 = 1;
  local_14 = 2;
  FUN_005f59c7(param_2,param_3,&local_18,&stack0x00000010);
  return;
}


// ==== 0x5f6e41 FUN_005f6e41

void FUN_005f6e41(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_18 = 0;
  local_10 = 1;
  local_c = 1;
  local_8 = param_5;
  local_14 = 2;
  FUN_005f59c7(param_2,param_3,&local_18,param_4);
  return;
}


// ==== 0x5f6e7a FUN_005f6e7a

void FUN_005f6e7a(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_18 = 0;
  local_10 = 1;
  local_c = 1;
  local_8 = 1;
  local_14 = 3;
  FUN_005f59c7(param_2,param_3,&local_18,&stack0x00000010);
  return;
}


// ==== 0x5f6eb1 FUN_005f6eb1

void FUN_005f6eb1(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_18 = 0;
  local_10 = 1;
  local_c = 1;
  local_8 = param_5;
  local_14 = 3;
  FUN_005f59c7(param_2,param_3,&local_18,param_4);
  return;
}


// ==== 0x5f6eea FUN_005f6eea

void FUN_005f6eea(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_18 = 1;
  local_10 = 1;
  local_8 = 1;
  local_14 = 3;
  local_c = 4;
  FUN_005f59c7(param_2,param_3,&local_18,param_4);
  return;
}


// ==== 0x5f6f23 FUN_005f6f23

void FUN_005f6f23(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_18 = 1;
  local_10 = 1;
  local_8 = param_5;
  local_14 = 3;
  local_c = 4;
  FUN_005f59c7(param_2,param_3,&local_18,param_4);
  return;
}


// ==== 0x5f6f5f FUN_005f6f5f

void FUN_005f6f5f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = 4;
  local_c = 4;
  local_18 = 2;
  local_14 = 3;
  local_8 = 1;
  FUN_005f59c7(param_2,param_3,&local_18,param_4);
  return;
}


// ==== 0x5f6f9c FUN_005f6f9c

void FUN_005f6f9c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = 4;
  local_c = 4;
  local_8 = param_5;
  local_18 = 2;
  local_14 = 3;
  FUN_005f59c7(param_2,param_3,&local_18,param_4);
  return;
}


// ==== 0x5f6fd8 FUN_005f6fd8

void FUN_005f6fd8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = 4;
  local_c = 4;
  local_8 = param_5;
  local_18 = 2;
  local_14 = 3;
  FUN_005f604f(param_2,param_3,&local_18,param_4);
  return;
}


// ==== 0x5f7014 FUN_005f7014

void FUN_005f7014(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_18 = 3;
  local_14 = 3;
  local_10 = 4;
  local_c = 4;
  local_8 = 1;
  FUN_005f59c7(param_2,param_3,&local_18,param_4);
  return;
}


// ==== 0x5f704c FUN_005f704c

void FUN_005f704c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_18 = 3;
  local_14 = 3;
  local_10 = 4;
  local_c = 4;
  local_8 = param_5;
  FUN_005f59c7(param_2,param_3,&local_18,param_4);
  return;
}


// ==== 0x5f7083 FUN_005f7083

void FUN_005f7083(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_18 = 3;
  local_14 = 3;
  local_10 = 4;
  local_c = 4;
  local_8 = param_5;
  FUN_005f604f(param_2,param_3,&local_18,param_4);
  return;
}


// ==== 0x5f70ba FUN_005f70ba

undefined4 * __fastcall FUN_005f70ba(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_1[3] = 0;
  param_1[2] = 0;
  *param_1 = &PTR_FUN_006a3da8;
  param_1[1] = 1;
  puVar2 = param_1 + 4;
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}


// ==== 0x5f70e0 FUN_005f70e0

undefined4 FUN_005f70e0(size_t param_1,int *param_2)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 == (int *)0x0) {
    return 0x8876086c;
  }
  pvVar1 = _malloc(0x3c);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_005f70ba();
  }
  if (iVar2 == 0) {
LAB_005f710f:
    uVar3 = 0x8007000e;
  }
  else {
    if (param_1 != 0) {
      pvVar1 = _malloc(param_1);
      *(void **)(iVar2 + 0xc) = pvVar1;
      if (pvVar1 == (void *)0x0) {
        FUN_005f5722(1);
        goto LAB_005f710f;
      }
    }
    *(size_t *)(iVar2 + 8) = param_1;
    *param_2 = iVar2;
    uVar3 = 0;
  }
  return uVar3;
}


// ==== 0x5f7144 FUN_005f7144

void __fastcall FUN_005f7144(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a3e10;
  param_1[1] = 0;
  param_1[7] = 0;
  param_1[4] = 0;
  param_1[2] = 0;
  param_1[8] = 0;
  param_1[5] = 0;
  param_1[3] = 0;
  param_1[9] = 0;
  param_1[6] = 0;
  return;
}


// ==== 0x5f716a FUN_005f716a

void * __thiscall FUN_005f716a(void *param_1,byte param_2)

{
  FUN_005d7865();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5f7186 FUN_005f7186

void * __thiscall FUN_005f7186(void *param_1,byte param_2)

{
  FUN_005f7738();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5f71a2 FUN_005f71a2

int __thiscall FUN_005f71a2(int param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_8;
  
  local_8 = *(int *)(param_1 + 0x1c);
  if (*(int *)(param_1 + 4) == local_8) {
    if (local_8 == 0) {
      local_8 = 0x10;
    }
    else {
      local_8 = local_8 * 2;
    }
    puVar1 = _malloc(local_8 << 2);
    if (puVar1 == (undefined4 *)0x0) {
      if (param_2 != 0) {
        FUN_005f716a(1);
      }
      return -1;
    }
    puVar4 = *(undefined4 **)(param_1 + 0x10);
    puVar5 = puVar1;
    for (uVar2 = *(uint *)(param_1 + 4) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    puVar4 = puVar1 + *(int *)(param_1 + 4);
    for (uVar2 = local_8 - *(int *)(param_1 + 4) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    _free(*(void **)(param_1 + 0x10));
    *(int *)(param_1 + 0x1c) = local_8;
    *(undefined4 **)(param_1 + 0x10) = puVar1;
  }
  *(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 4) * 4) = param_2;
  iVar3 = *(int *)(param_1 + 4);
  *(int *)(param_1 + 4) = iVar3 + 1;
  return iVar3;
}


// ==== 0x5f725a FUN_005f725a

int __thiscall FUN_005f725a(int param_1,int *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_8;
  
  local_8 = *(int *)(param_1 + 0x20);
  if (*(int *)(param_1 + 8) == local_8) {
    if (local_8 == 0) {
      local_8 = 0x400;
    }
    else {
      local_8 = local_8 * 2;
    }
    puVar1 = _malloc(local_8 << 2);
    if (puVar1 == (undefined4 *)0x0) {
      if (param_2 != (int *)0x0) {
        FUN_005f716a(1);
      }
      return -1;
    }
    puVar4 = *(undefined4 **)(param_1 + 0x14);
    puVar5 = puVar1;
    for (uVar2 = *(uint *)(param_1 + 8) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    puVar4 = puVar1 + *(int *)(param_1 + 8);
    for (uVar2 = local_8 - *(int *)(param_1 + 8) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    _free(*(void **)(param_1 + 0x14));
    *(undefined4 **)(param_1 + 0x14) = puVar1;
    *(int *)(param_1 + 0x20) = local_8;
  }
  if (((param_2 != (int *)0x0) &&
      ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *param_2 * 4) + 4) & 0x80) != 0)) &&
     (param_2[1] == -1)) {
    param_2[6] = param_2[6] | 0x20;
    if ((*(double *)(param_2 + 4) == 0.0) || (*(double *)(param_2 + 4) == 1.0)) {
      param_2[6] = param_2[6] | 1;
    }
    iVar3 = __ftol();
    if (ABS(*(double *)(param_2 + 4) - (double)iVar3) < 1e-06) {
      param_2[6] = param_2[6] | 2;
    }
    if (0.0 <= *(double *)(param_2 + 4)) {
      param_2[6] = param_2[6] | 4;
    }
    if (*(double *)(param_2 + 4) < 0.0 != (*(double *)(param_2 + 4) == 0.0)) {
      param_2[6] = param_2[6] | 8;
    }
    if (ABS(*(double *)(param_2 + 4)) < 1.0 != (ABS(*(double *)(param_2 + 4)) == 1.0)) {
      param_2[6] = param_2[6] | 0x10;
    }
  }
  *(int **)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8) * 4) = param_2;
  iVar3 = *(int *)(param_1 + 8);
  *(int *)(param_1 + 8) = iVar3 + 1;
  return iVar3;
}


// ==== 0x5f73c0 FUN_005f73c0

int __thiscall FUN_005f73c0(int param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_8;
  
  local_8 = *(int *)(param_1 + 0x24);
  if (*(int *)(param_1 + 0xc) == local_8) {
    if (local_8 == 0) {
      local_8 = 0x100;
    }
    else {
      local_8 = local_8 * 2;
    }
    puVar1 = _malloc(local_8 << 2);
    if (puVar1 == (undefined4 *)0x0) {
      if (param_2 != 0) {
        FUN_005f7186(1);
      }
      return -1;
    }
    puVar4 = *(undefined4 **)(param_1 + 0x18);
    puVar5 = puVar1;
    for (uVar2 = *(uint *)(param_1 + 0xc) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    puVar4 = puVar1 + *(int *)(param_1 + 0xc);
    for (uVar2 = local_8 - *(int *)(param_1 + 0xc) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    _free(*(void **)(param_1 + 0x18));
    *(int *)(param_1 + 0x24) = local_8;
    *(undefined4 **)(param_1 + 0x18) = puVar1;
  }
  *(int *)(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0xc) * 4) = param_2;
  iVar3 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0xc) = iVar3 + 1;
  return iVar3;
}


// ==== 0x5f7478 FUN_005f7478

undefined4 FUN_005f7478(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  pvVar1 = _malloc(0x34);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0061c398();
  }
  if (iVar2 != 0) {
    iVar3 = FUN_0061c39b(param_1,param_2,param_3,param_4);
    if (-1 < iVar3) {
      uVar4 = FUN_005f71a2(iVar2);
      return uVar4;
    }
    FUN_005f716a(1);
  }
  return 0xffffffff;
}


// ==== 0x5f74cf FUN_005f74cf

undefined4 FUN_005f74cf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  
  pvVar1 = _malloc(0x60);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0061c398();
  }
  if (iVar2 != 0) {
    iVar2 = FUN_005f7c08(param_1,param_2,param_3,param_4);
    if (-1 < iVar2) {
      uVar3 = FUN_005f725a();
      return uVar3;
    }
    FUN_005f716a();
  }
  return 0xffffffff;
}


// ==== 0x5f752b FUN_005f752b

undefined4 FUN_005f752b(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  pvVar1 = _malloc(0x38);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_005f7709();
  }
  if (iVar2 != 0) {
    iVar3 = FUN_005f7760(param_1,param_2,param_3,0);
    if (-1 < iVar3) {
      uVar4 = FUN_005f73c0(iVar2);
      return uVar4;
    }
    FUN_005f7186(1);
  }
  return 0xffffffff;
}


// ==== 0x5f7580 FUN_005f7580

undefined4 FUN_005f7580(undefined4 param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  pvVar1 = _malloc(0x34);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0061c398();
  }
  if (iVar2 != 0) {
    iVar3 = FUN_0061c3e1(param_1);
    if (-1 < iVar3) {
      uVar4 = FUN_005f71a2(iVar2);
      return uVar4;
    }
    FUN_005f716a(1);
  }
  return 0xffffffff;
}


// ==== 0x5f75cb FUN_005f75cb

undefined4 FUN_005f75cb(undefined4 param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  pvVar1 = _malloc(0x38);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_005f7709();
  }
  if (iVar2 != 0) {
    iVar3 = FUN_005f799b(param_1);
    if (-1 < iVar3) {
      uVar4 = FUN_005f73c0(iVar2);
      return uVar4;
    }
    FUN_005f7186(1);
  }
  return 0xffffffff;
}


// ==== 0x5f7616 FUN_005f7616

undefined4 __thiscall FUN_005f7616(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *(uint *)(param_1 + 4)) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x10) + param_2 * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x5f762c FUN_005f762c

undefined4 __thiscall FUN_005f762c(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *(uint *)(param_1 + 8)) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x14) + param_2 * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x5f7642 FUN_005f7642

undefined4 __thiscall FUN_005f7642(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *(uint *)(param_1 + 0xc)) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x18) + param_2 * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x5f7658 FUN_005f7658

void __fastcall FUN_005f7658(undefined4 *param_1)

{
  uint uVar1;
  
  *param_1 = &PTR_FUN_006a3e10;
  if (param_1[4] != 0) {
    uVar1 = 0;
    if (param_1[1] != 0) {
      do {
        if (*(int *)(param_1[4] + uVar1 * 4) != 0) {
          FUN_005f716a(1);
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < (uint)param_1[1]);
    }
    _free((void *)param_1[4]);
  }
  if (param_1[5] != 0) {
    uVar1 = 0;
    if (param_1[2] != 0) {
      do {
        if (*(int *)(param_1[5] + uVar1 * 4) != 0) {
          FUN_005f716a(1);
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < (uint)param_1[2]);
    }
    _free((void *)param_1[5]);
  }
  if (param_1[6] != 0) {
    uVar1 = 0;
    if (param_1[3] != 0) {
      do {
        if (*(int *)(param_1[6] + uVar1 * 4) != 0) {
          FUN_005f7186(1);
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < (uint)param_1[3]);
    }
    _free((void *)param_1[6]);
  }
  return;
}


// ==== 0x5f76ed FUN_005f76ed

void * __thiscall FUN_005f76ed(void *param_1,byte param_2)

{
  FUN_005f7658();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5f7709 FUN_005f7709

void __fastcall FUN_005f7709(undefined4 *param_1)

{
  param_1[0xb] = 0xffffffff;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  return;
}


// ==== 0x5f7738 FUN_005f7738

void __fastcall FUN_005f7738(int param_1)

{
  _free(*(void **)(param_1 + 8));
  _free(*(void **)(param_1 + 0x10));
  _free(*(void **)(param_1 + 0x18));
  _free(*(void **)(param_1 + 0x20));
  return;
}


// ==== 0x5f7760 FUN_005f7760

undefined4 __thiscall FUN_005f7760(uint *param_1,uint param_2,uint param_3,uint param_4,int param_5)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  bool bVar7;
  uint uVar8;
  
  uVar1 = param_2 & 0xffffff;
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[3] = param_4;
  if (param_5 != 0) goto LAB_005f7924;
  uVar4 = param_2 & 0xf0000000;
  if (uVar4 == 0) {
    uVar1 = 0;
    goto LAB_005f78f0;
  }
  uVar8 = uVar1;
  uVar5 = uVar1;
  if (uVar4 != 0x10000000) {
    if (uVar4 == 0x20000000) {
      uVar8 = uVar1 * 2;
    }
    else if (uVar4 == 0x30000000) {
      uVar4 = param_2 & 0xff000000;
      if (uVar4 == 0x30000000) {
        uVar1 = uVar1 * 2;
        uVar8 = uVar1;
        uVar5 = param_4;
        if (param_4 == 0xffffffff) {
LAB_005f78cc:
          uVar8 = uVar1;
          uVar5 = 1;
        }
      }
      else if (uVar4 == 0x31000000) {
        uVar8 = 0;
      }
      else {
        if (uVar4 != 0x32000000) {
          if (uVar4 == 0x33000000) goto LAB_005f78f2;
          if (uVar4 != 0x34000000) {
            if (uVar4 != 0x35000000) goto LAB_005f78bd;
            goto LAB_005f78cc;
          }
        }
LAB_005f78f0:
        uVar8 = uVar1;
        uVar5 = 0;
      }
    }
    else if (uVar4 == 0x40000000) {
      param_2 = param_2 & 0xff000000;
      if (param_2 < 0x48000001) {
        if (param_2 == 0x48000000) {
LAB_005f7843:
          uVar8 = 6;
        }
        else {
          if (param_2 < 0x44000001) {
            if ((param_2 == 0x44000000) || (param_2 == 0x40000000)) {
              uVar8 = 4;
              uVar5 = 4;
              goto LAB_005f78f2;
            }
            if ((param_2 != 0x41000000) && (param_2 != 0x42000000)) {
              bVar7 = param_2 == 0x43000000;
              goto LAB_005f7817;
            }
          }
          else if ((param_2 != 0x45000000) && (param_2 != 0x46000000)) {
            bVar7 = param_2 == 0x47000000;
LAB_005f7817:
            uVar8 = param_3;
            uVar5 = param_4;
            if (!bVar7) goto LAB_005f78f2;
          }
LAB_005f781d:
          uVar8 = 8;
        }
      }
      else {
        if (param_2 != 0x49000000) {
          if ((param_2 != 0x4a000000) && (param_2 != 0x4b000000)) {
            if (param_2 == 0x4c000000) goto LAB_005f7843;
            if (param_2 == 0x4d000000) goto LAB_005f787f;
            if (param_2 != 0x4e000000) {
              bVar7 = param_2 == 0x4f000000;
              goto LAB_005f7817;
            }
          }
          goto LAB_005f781d;
        }
LAB_005f787f:
        uVar8 = 0xc;
      }
      uVar5 = 4;
    }
    else {
      uVar8 = param_3;
      uVar5 = param_4;
      if (uVar4 == 0x50000000) {
LAB_005f78bd:
        uVar8 = param_3;
        uVar5 = param_4;
        if ((param_2 & 0xff000000) == 0x50000000) {
          uVar8 = uVar1 * 3;
          uVar5 = uVar1;
        }
      }
    }
  }
LAB_005f78f2:
  if (param_1[1] == 0xffffffff) {
    param_1[1] = uVar8;
  }
  if (param_1[3] == 0xffffffff) {
    param_1[3] = uVar5;
  }
  if ((((param_1[1] != uVar8) || (param_1[3] != uVar5)) || (param_1[1] == 0xffffffff)) ||
     (param_1[3] == 0xffffffff)) {
    return 0x80004005;
  }
LAB_005f7924:
  pvVar2 = _malloc(param_1[1] << 2);
  param_1[2] = (uint)pvVar2;
  if (pvVar2 != (void *)0x0) {
    pvVar2 = _malloc(param_1[3] << 2);
    param_1[4] = (uint)pvVar2;
    if (pvVar2 != (void *)0x0) {
      puVar6 = (undefined4 *)param_1[2];
      for (uVar1 = param_1[1] & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar6 = 0xffffffff;
        puVar6 = puVar6 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar6 = 0xff;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
      puVar6 = (undefined4 *)param_1[4];
      for (uVar1 = param_1[3] & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar6 = 0xffffffff;
        puVar6 = puVar6 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar6 = 0xff;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
      param_1[9] = 0;
      param_1[10] = 0;
      param_1[0xc] = 0;
      param_1[0xd] = 0;
      return 0;
    }
  }
  return 0x8007000e;
}


// ==== 0x5f799b FUN_005f799b

undefined4 __thiscall FUN_005f799b(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[3] = param_2[3];
    pvVar2 = _malloc(param_1[1] << 2);
    param_1[2] = pvVar2;
    if (pvVar2 != (void *)0x0) {
      pvVar2 = _malloc(param_1[3] << 2);
      param_1[4] = pvVar2;
      if (pvVar2 != (void *)0x0) {
        puVar5 = (undefined4 *)param_2[2];
        puVar6 = (undefined4 *)param_1[2];
        for (uVar3 = param_1[1] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
        puVar5 = (undefined4 *)param_2[4];
        puVar6 = (undefined4 *)param_1[4];
        for (uVar3 = param_1[3] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
        param_1[9] = param_2[9];
        param_1[0xb] = param_2[0xb];
        param_1[0xd] = param_2[0xd];
        return 0;
      }
    }
    uVar1 = 0x8007000e;
  }
  return uVar1;
}


// ==== 0x5f7a42 FUN_005f7a42

undefined4 __thiscall FUN_005f7a42(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0x80004005;
  }
  else {
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_2 + 0x34);
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x5f7a5c FUN_005f7a5c

uint __thiscall FUN_005f7a5c(uint *param_1,int param_2,int *param_3)

{
  uint uVar1;
  
  uVar1 = *param_1 & 0xffffff;
  if (param_1[1] < uVar1 * param_2 + uVar1) {
    if (param_3 != (int *)0x0) {
      *param_3 = 0;
    }
    uVar1 = 0;
  }
  else if (param_3 != (int *)0x0) {
    *param_3 = param_1[2] + uVar1 * param_2 * 4;
  }
  return uVar1;
}


// ==== 0x5f7a96 FUN_005f7a96

bool __fastcall FUN_005f7a96(uint *param_1)

{
  return (*param_1 & 0xff000000) == 0;
}


// ==== 0x5f7aa3 FUN_005f7aa3

bool __fastcall FUN_005f7aa3(uint *param_1)

{
  return (*param_1 & 0xff000000) == 0x10000000;
}


// ==== 0x5f7ab5 FUN_005f7ab5

bool __fastcall FUN_005f7ab5(uint *param_1)

{
  return (*param_1 & 0xff000000) == 0x11000000;
}


// ==== 0x5f7ac7 FUN_005f7ac7

bool __fastcall FUN_005f7ac7(uint *param_1)

{
  return (*param_1 & 0xff000000) == 0x30000000;
}


// ==== 0x5f7ad9 FUN_005f7ad9

bool __fastcall FUN_005f7ad9(uint *param_1)

{
  return (*param_1 & 0xff000000) == 0x31000000;
}


// ==== 0x5f7aeb FUN_005f7aeb

bool __fastcall FUN_005f7aeb(uint *param_1)

{
  return (*param_1 & 0xff000000) == 0x32000000;
}


// ==== 0x5f7afd FUN_005f7afd

bool __fastcall FUN_005f7afd(uint *param_1)

{
  return (*param_1 & 0xff000000) == 0x34000000;
}


// ==== 0x5f7b0f FUN_005f7b0f

bool __fastcall FUN_005f7b0f(uint *param_1)

{
  return (*param_1 & 0xf0000000) == 0x10000000;
}


// ==== 0x5f7b21 FUN_005f7b21

bool __fastcall FUN_005f7b21(uint *param_1)

{
  return (*param_1 & 0xf0000000) == 0x20000000;
}


// ==== 0x5f7b33 FUN_005f7b33

bool __fastcall FUN_005f7b33(uint *param_1)

{
  return (*param_1 & 0xf0000000) == 0x50000000;
}


// ==== 0x5f7b45 FUN_005f7b45

bool __fastcall FUN_005f7b45(uint *param_1)

{
  return (*param_1 & 0xf0000000) == 0x40000000;
}


// ==== 0x5f7b57 FUN_005f7b57

bool __fastcall FUN_005f7b57(uint *param_1)

{
  return 0x2fffffff < (*param_1 & 0xf0000000);
}


// ==== 0x5f7b67 FUN_005f7b67

undefined4 __fastcall FUN_005f7b67(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1 & 0xff000000;
  if ((((uVar1 != 0x20000000) && (uVar1 != 0x21000000)) && (uVar1 != 0x24000000)) &&
     ((uVar1 != 0x25000000 && (uVar1 != 0x30000000)))) {
    return 0;
  }
  return 1;
}


// ==== 0x5f7b98 FUN_005f7b98

uint __thiscall FUN_005f7b98(uint *param_1,int param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  uVar1 = uVar2 & 0xff000000;
  if (uVar1 == 0) {
    uVar2 = 0;
  }
  else if ((uVar1 == 0x30000000) || (uVar1 == 0x35000000)) {
    uVar2 = 1;
  }
  else if ((uVar2 & 0xf0000000) == 0x40000000) {
    uVar2 = 4;
  }
  else {
    uVar2 = uVar2 & 0xffffff;
  }
  if (param_1[3] < uVar2 * param_2 + uVar2) {
    if (param_3 != (int *)0x0) {
      *param_3 = 0;
    }
    uVar2 = 0;
  }
  else if (param_3 != (int *)0x0) {
    *param_3 = param_1[4] + uVar2 * param_2 * 4;
  }
  return uVar2;
}


// ==== 0x5f7c08 FUN_005f7c08

undefined4 __thiscall
FUN_005f7c08(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined8 param_5)

{
  *(undefined8 *)(param_1 + 4) = param_5;
  param_1[2] = param_3;
  *param_1 = param_2;
  param_1[3] = param_4;
  param_1[1] = 0xffffffff;
  param_1[7] = 0xffffffff;
  param_1[8] = 0xffffffff;
  param_1[9] = 0xffffffff;
  param_1[10] = 0xffffffff;
  param_1[0xb] = 0xffffffff;
  param_1[0xc] = 0xffffffff;
  param_1[0xd] = 0xffffffff;
  param_1[0xe] = 0xffffffff;
  param_1[0xf] = 0xffffffff;
  param_1[0x14] = 0xffffffff;
  param_1[0x16] = 0xffffffff;
  param_1[6] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x15] = 0;
  return 0;
}


// ==== 0x5f7c63 FUN_005f7c63

undefined4 __thiscall FUN_005f7c63(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
    *(undefined8 *)(param_1 + 4) = *(undefined8 *)(param_2 + 4);
    param_1[6] = param_2[6];
    param_1[7] = param_2[7];
    param_1[8] = param_2[8];
    param_1[9] = param_2[9];
    param_1[10] = param_2[10];
    param_1[0xb] = param_2[0xb];
    param_1[0xc] = param_2[0xc];
    param_1[0xd] = param_2[0xd];
    param_1[0xe] = param_2[0xe];
    param_1[0xf] = param_2[0xf];
    param_1[0x10] = param_2[0x10];
    param_1[0x11] = param_2[0x11];
    param_1[0x12] = param_2[0x12];
    param_1[0x13] = param_2[0x13];
    param_1[0x14] = param_2[0x14];
    param_1[0x15] = param_2[0x15];
    param_1[0x16] = param_2[0x16];
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x5f7cfc FUN_005f7cfc

undefined4 __thiscall FUN_005f7cfc(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0x80004005;
  }
  else {
    *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_2 + 0x44);
    *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_2 + 0x48);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_2 + 0x4c);
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_2 + 0x50);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_2 + 0x54);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_2 + 0x58);
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x5f7d34 FUN_005f7d34

undefined4 FUN_005f7d34(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  
  puVar1 = *(uint **)(*(int *)(param_3 + 0x14) + param_2 * 4);
  puVar2 = *(uint **)(*(int *)(param_3 + 0x14) + param_1 * 4);
  if (*puVar2 < *puVar1) {
LAB_005f7d61:
    uVar3 = 0xffffffff;
  }
  else {
    if (*puVar2 == *puVar1) {
      if (*(double *)(puVar2 + 4) < *(double *)(puVar1 + 4)) goto LAB_005f7d61;
      if (*(double *)(puVar2 + 4) <= *(double *)(puVar1 + 4)) {
        return 0;
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}


// ==== 0x5f7d7e FUN_005f7d7e

uint FUN_005f7d7e(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = *(uint **)(*(int *)(param_3 + 0x14) + param_1 * 4);
  puVar2 = *(uint **)(*(int *)(param_3 + 0x14) + param_2 * 4);
  if (*puVar2 <= *puVar1) {
    if (*puVar2 < *puVar1) {
      return 1;
    }
    if (puVar2[2] <= puVar1[2]) {
      if (puVar1[2] != puVar2[2]) {
        return 1;
      }
      if (puVar2[1] <= puVar1[1]) {
        if (puVar1[1] != puVar2[1]) {
          return 1;
        }
        if (puVar2[3] <= puVar1[3]) {
          return (uint)(puVar2[3] < puVar1[3]);
        }
      }
    }
  }
  return 0xffffffff;
}


// ==== 0x5f7dd2 FUN_005f7dd2

uint FUN_005f7dd2(uint param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1 < param_2) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (uint)(param_2 < param_1);
  }
  return uVar1;
}


// ==== 0x5f7de8 FUN_005f7de8

uint FUN_005f7de8(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_3 + 0x18) + param_1 * 4) + 0x2c);
  iVar2 = *(int *)(*(int *)(*(int *)(param_3 + 0x18) + param_2 * 4) + 0x2c);
  if (iVar2 <= iVar1) {
    if (iVar2 < iVar1) {
      return 1;
    }
    if (param_2 <= param_1) {
      return (uint)(param_2 < param_1);
    }
  }
  return 0xffffffff;
}


// ==== 0x5f7e20 FUN_005f7e20

void FUN_005f7e20(code *param_1,undefined4 *param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 local_c;
  uint local_8;
  
  puVar3 = param_2;
  if (1 < param_3) {
    uVar5 = param_3 >> 1;
    if (uVar5 != 0) {
      local_8 = uVar5 * 2 + 1;
      do {
        uVar5 = uVar5 - 1;
        uVar1 = puVar3[uVar5];
        local_8 = local_8 - 2;
        uVar8 = local_8;
        param_2 = (undefined4 *)uVar5;
        while (uVar8 < param_3) {
          local_c = puVar3[uVar8];
          uVar7 = uVar8;
          if (uVar8 + 1 < param_3) {
            uVar6 = puVar3[uVar8 + 1];
            iVar4 = (*param_1)(uVar6,local_c,param_4);
            if (0 < iVar4) {
              uVar7 = uVar8 + 1;
              local_c = uVar6;
            }
          }
          iVar4 = (*param_1)(local_c,uVar1,param_4);
          if (iVar4 < 1) break;
          puVar3[(int)param_2] = puVar3[uVar7];
          param_2 = (undefined4 *)uVar7;
          uVar8 = uVar7 * 2 + 1;
        }
        puVar3[(int)param_2] = uVar1;
      } while (uVar5 != 0);
    }
    while (param_3 = param_3 - 1, param_3 != 0) {
      param_2 = (undefined4 *)0x0;
      uVar1 = puVar3[param_3];
      uVar5 = 1;
      puVar3[param_3] = *puVar3;
      if (1 < param_3) {
        do {
          uVar6 = puVar3[uVar5];
          uVar8 = uVar5;
          if (uVar5 + 1 < param_3) {
            uVar2 = puVar3[uVar5 + 1];
            iVar4 = (*param_1)(uVar2,uVar6,param_4);
            if (0 < iVar4) {
              uVar6 = uVar2;
              uVar8 = uVar5 + 1;
            }
          }
          iVar4 = (*param_1)(uVar6,uVar1,param_4);
          if (iVar4 < 1) break;
          uVar5 = uVar8 * 2 + 1;
          puVar3[(int)param_2] = puVar3[uVar8];
          param_2 = (undefined4 *)uVar8;
        } while (uVar5 < param_3);
      }
      puVar3[(int)param_2] = uVar1;
    }
  }
  return;
}


// ==== 0x5f7f35 FUN_005f7f35

undefined4 * __fastcall FUN_005f7f35(undefined4 *param_1)

{
  FUN_005f7144();
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0x12] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x13] = 0xffffffff;
  param_1[0x14] = 0xffffffff;
  param_1[0x15] = 0xffffffff;
  param_1[0x16] = 0xffffffff;
  param_1[0x17] = 0xffffffff;
  param_1[0x18] = 0xffffffff;
  param_1[0x19] = 0xffffffff;
  *param_1 = &PTR_FUN_006a3e14;
  return param_1;
}


// ==== 0x5f7f76 FUN_005f7f76

void __fastcall FUN_005f7f76(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_006a3e14;
  _free((void *)param_1[0x12]);
  FUN_005f7658();
  return;
}


// ==== 0x5f7f90 FUN_005f7f90

undefined4 __thiscall FUN_005f7f90(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  pcVar4 = (char *)0x0;
  if (param_2 != (char *)0x0) {
    pcVar2 = param_2;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = pcVar2 + (1 - (int)(param_2 + 1));
    pcVar4 = _malloc((size_t)pcVar2);
    if (pcVar4 == (char *)0x0) {
      return 0x8007000e;
    }
    pcVar5 = pcVar4;
    for (uVar3 = (uint)pcVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)param_2;
      param_2 = param_2 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar3 = (uint)pcVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar5 = *param_2;
      param_2 = param_2 + 1;
      pcVar5 = pcVar5 + 1;
    }
  }
  _free(*(void **)(param_1 + 0x48));
  *(char **)(param_1 + 0x48) = pcVar4;
  return 0;
}


// ==== 0x5f7fec FUN_005f7fec

undefined4 __fastcall FUN_005f7fec(int param_1)

{
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(uint *)(param_1 + 0x90) = *(uint *)(param_1 + 0x90) & 0xfffffffc;
  *(undefined4 *)(param_1 + 0x6c) = 0x40;
  *(undefined4 *)(param_1 + 0x70) = 0x40;
  *(undefined4 *)(param_1 + 0x78) = 0x2000;
  return 0;
}


// ==== 0x5f800a FUN_005f800a

undefined4 FUN_005f800a(uint param_1)

{
  undefined4 uVar1;
  
  param_1 = param_1 & 0xff000000;
  if ((((param_1 == 0x12000000) || (param_1 == 0x13000000)) || (param_1 == 0x14000000)) ||
     ((param_1 == 0x15000000 || (param_1 == 0x16000000)))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== 0x5f8040 FUN_005f8040

bool __fastcall FUN_005f8040(int param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  int local_c;
  uint local_8;
  
  bVar2 = false;
  uVar6 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      piVar4 = *(int **)(*(int *)(param_1 + 0x14) + uVar6 * 4);
      uVar6 = uVar6 + 1;
      piVar4[0xe] = *(uint *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar4 * 4) + 4) >> 4 & 1;
    } while (uVar6 < *(uint *)(param_1 + 8));
  }
  iVar5 = *(int *)(param_1 + 0xc);
  do {
    do {
      if (iVar5 == 0) {
        uVar6 = 0;
        if (*(int *)(param_1 + 8) != 0) {
          do {
            piVar4 = *(int **)(*(int *)(param_1 + 0x14) + uVar6 * 4);
            if ((((piVar4[0xe] == 0) && (*(int *)(param_1 + 0x4c) != *piVar4)) &&
                ((piVar4[1] != -1 ||
                 ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar4 * 4) + 5) & 2) == 0)))) &&
               ((piVar4[0xb] == -1 || (iVar5 = FUN_005f7b57(), iVar5 == 0)))) {
              *piVar4 = *(int *)(param_1 + 0x4c);
              bVar2 = true;
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 < *(uint *)(param_1 + 8));
        }
        return !bVar2;
      }
      iVar5 = iVar5 + -1;
      puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + iVar5 * 4);
      iVar3 = FUN_005f7a96();
    } while (iVar3 != 0);
    iVar3 = FUN_005f7ad9();
    if (iVar3 == 0) {
      iVar3 = FUN_005f7b0f();
      if (iVar3 == 0) {
        iVar3 = FUN_005f7b21();
        if (iVar3 == 0) {
          iVar3 = FUN_005f7b33();
          if (iVar3 == 0) {
            iVar3 = FUN_005f7aeb();
            if ((iVar3 == 0) && (iVar3 = FUN_005f7afd(), iVar3 == 0)) {
              local_8 = 0;
              if (puVar1[3] != 0) {
                piVar4 = (int *)puVar1[4];
                uVar6 = puVar1[3];
                do {
                  if (*(int *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar4 * 4) + 0x38) != 0) {
                    local_8 = local_8 + 1;
                  }
                  piVar4 = piVar4 + 1;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
                if (local_8 != 0) goto LAB_005f835c;
              }
              uVar6 = 0;
              puVar1[1] = 0;
              puVar1[3] = 0;
              goto LAB_005f8353;
            }
          }
          else {
            uVar6 = 0;
            bVar9 = puVar1[3] == 0;
            local_8 = 0;
            if (puVar1[3] != 0) {
              do {
                if (*(int *)(*(int *)(*(int *)(param_1 + 0x14) +
                                     *(int *)(puVar1[4] + local_8 * 4) * 4) + 0x38) != 0) {
                  *(undefined4 *)(puVar1[2] + uVar6 * 4) = *(undefined4 *)(puVar1[2] + local_8 * 4);
                  *(undefined4 *)(puVar1[2] + (puVar1[3] + uVar6) * 4) =
                       *(undefined4 *)(puVar1[2] + (local_8 + puVar1[3]) * 4);
                  *(undefined4 *)(puVar1[2] + (puVar1[3] * 2 + uVar6) * 4) =
                       *(undefined4 *)(puVar1[2] + (local_8 + puVar1[3] * 2) * 4);
                  *(undefined4 *)(puVar1[4] + uVar6 * 4) = *(undefined4 *)(puVar1[4] + local_8 * 4);
                  uVar6 = uVar6 + 1;
                }
                local_8 = local_8 + 1;
              } while (local_8 < puVar1[3]);
              bVar9 = uVar6 == puVar1[3];
            }
            if (!bVar9) {
              if (uVar6 == 0) {
                uVar7 = 0;
              }
              else {
                uVar7 = (*puVar1 ^ uVar6) & 0xffffff ^ *puVar1;
              }
              local_8 = 0;
              *puVar1 = uVar7;
              if (uVar6 != 0) {
                iVar3 = uVar6 << 2;
                do {
                  iVar8 = puVar1[3] + local_8;
                  local_8 = local_8 + 1;
                  *(undefined4 *)(puVar1[2] + iVar3) = *(undefined4 *)(puVar1[2] + iVar8 * 4);
                  iVar3 = iVar3 + 4;
                } while (local_8 < uVar6);
              }
              local_8 = 0;
              if (uVar6 != 0) {
                local_c = uVar6 << 3;
                do {
                  uVar7 = local_8 + 1;
                  *(undefined4 *)(puVar1[2] + local_c) =
                       *(undefined4 *)(puVar1[2] + (local_8 + puVar1[3] * 2) * 4);
                  local_c = local_c + 4;
                  local_8 = uVar7;
                } while (uVar7 < uVar6);
              }
              uVar7 = uVar6 * 3;
              goto LAB_005f8303;
            }
          }
        }
        else {
          uVar6 = 0;
          bVar9 = puVar1[3] == 0;
          local_8 = 0;
          if (puVar1[3] != 0) {
            do {
              if (*(int *)(*(int *)(*(int *)(param_1 + 0x14) + *(int *)(puVar1[4] + local_8 * 4) * 4
                                   ) + 0x38) != 0) {
                *(undefined4 *)(puVar1[2] + uVar6 * 4) = *(undefined4 *)(puVar1[2] + local_8 * 4);
                *(undefined4 *)(puVar1[2] + (puVar1[3] + uVar6) * 4) =
                     *(undefined4 *)(puVar1[2] + (local_8 + puVar1[3]) * 4);
                *(undefined4 *)(puVar1[4] + uVar6 * 4) = *(undefined4 *)(puVar1[4] + local_8 * 4);
                uVar6 = uVar6 + 1;
              }
              local_8 = local_8 + 1;
            } while (local_8 < puVar1[3]);
            bVar9 = uVar6 == puVar1[3];
          }
          if (!bVar9) {
            if (uVar6 == 0) {
              uVar7 = 0;
            }
            else {
              uVar7 = (*puVar1 ^ uVar6) & 0xffffff ^ *puVar1;
            }
            local_8 = 0;
            *puVar1 = uVar7;
            if (uVar6 != 0) {
              iVar3 = uVar6 << 2;
              do {
                iVar8 = puVar1[3] + local_8;
                local_8 = local_8 + 1;
                *(undefined4 *)(puVar1[2] + iVar3) = *(undefined4 *)(puVar1[2] + iVar8 * 4);
                iVar3 = iVar3 + 4;
              } while (local_8 < uVar6);
            }
            uVar7 = uVar6 * 2;
LAB_005f8303:
            puVar1[1] = uVar7;
            puVar1[3] = uVar6;
            goto LAB_005f8355;
          }
        }
      }
      else {
        uVar7 = 0;
        bVar9 = puVar1[3] == 0;
        local_8 = 0;
        if (puVar1[3] != 0) {
          do {
            if (*(int *)(*(int *)(*(int *)(param_1 + 0x14) + *(int *)(puVar1[4] + local_8 * 4) * 4)
                        + 0x38) != 0) {
              *(undefined4 *)(puVar1[2] + uVar7 * 4) = *(undefined4 *)(puVar1[2] + local_8 * 4);
              *(undefined4 *)(puVar1[4] + uVar7 * 4) = *(undefined4 *)(puVar1[4] + local_8 * 4);
              uVar7 = uVar7 + 1;
            }
            local_8 = local_8 + 1;
          } while (local_8 < puVar1[3]);
          bVar9 = uVar7 == puVar1[3];
        }
        if (!bVar9) {
          if (uVar7 == 0) {
            uVar6 = 0;
          }
          else {
            uVar6 = (*puVar1 ^ uVar7) & 0xffffff ^ *puVar1;
          }
          puVar1[3] = uVar7;
          puVar1[1] = uVar7;
          goto LAB_005f8353;
        }
      }
    }
    else {
      uVar7 = 0;
      bVar9 = puVar1[3] == 0;
      local_8 = 0;
      if (puVar1[3] != 0) {
        do {
          iVar3 = *(int *)(puVar1[4] + local_8 * 4);
          if (*(int *)(*(int *)(*(int *)(param_1 + 0x14) + iVar3 * 4) + 0x38) != 0) {
            *(int *)(puVar1[4] + uVar7 * 4) = iVar3;
            uVar7 = uVar7 + 1;
          }
          local_8 = local_8 + 1;
        } while (local_8 < puVar1[3]);
        bVar9 = uVar7 == puVar1[3];
      }
      if (!bVar9) {
        if (uVar7 == 0) {
          uVar6 = 0;
        }
        else {
          uVar6 = (*puVar1 ^ uVar7) & 0xffffff ^ *puVar1;
        }
        puVar1[3] = uVar7;
LAB_005f8353:
        *puVar1 = uVar6;
LAB_005f8355:
        bVar2 = true;
      }
    }
LAB_005f835c:
    uVar6 = 0;
    if (puVar1[3] != 0) {
      iVar3 = *(int *)(param_1 + 0x14);
      do {
        iVar8 = *(int *)(puVar1[4] + uVar6 * 4);
        while( true ) {
          piVar4 = (int *)(*(int *)(iVar3 + iVar8 * 4) + 4);
          iVar8 = *piVar4;
          if (iVar8 == -1) break;
          *(undefined4 *)(*(int *)(iVar3 + iVar8 * 4) + 0x38) = 1;
          iVar3 = *(int *)(param_1 + 0x14);
          iVar8 = *piVar4;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < puVar1[3]);
    }
    uVar6 = 0;
    if (puVar1[1] != 0) {
      iVar3 = *(int *)(param_1 + 0x14);
      do {
        *(undefined4 *)(*(int *)(iVar3 + *(int *)(puVar1[2] + uVar6 * 4) * 4) + 0x38) = 1;
        iVar8 = *(int *)(puVar1[2] + uVar6 * 4);
        while( true ) {
          iVar3 = *(int *)(param_1 + 0x14);
          piVar4 = (int *)(*(int *)(iVar3 + iVar8 * 4) + 4);
          iVar8 = *piVar4;
          if (iVar8 == -1) break;
          *(undefined4 *)(*(int *)(iVar3 + iVar8 * 4) + 0x38) = 1;
          iVar8 = *piVar4;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < puVar1[1]);
    }
  } while( true );
}


// ==== 0x5f8440 FUN_005f8440

undefined4 __fastcall FUN_005f8440(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  iVar4 = 0;
  uVar5 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      iVar3 = *(int *)(*(int *)(param_1 + 0x18) + uVar5 * 4);
      iVar1 = FUN_005f7a96();
      if (iVar1 == 0) {
        *(int *)(*(int *)(param_1 + 0x18) + iVar4 * 4) = iVar3;
        iVar4 = iVar4 + 1;
      }
      else if (iVar3 != 0) {
        FUN_005f7186(1);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 0xc));
  }
  if (iVar4 == *(int *)(param_1 + 0xc)) {
    uVar2 = 1;
  }
  else {
    puVar6 = (undefined4 *)(*(int *)(param_1 + 0x18) + iVar4 * 4);
    for (uVar5 = *(int *)(param_1 + 0xc) - iVar4 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar6 = 0;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    *(int *)(param_1 + 0xc) = iVar4;
    uVar2 = 0;
  }
  return uVar2;
}


// ==== 0x5f84ab FUN_005f84ab

undefined4 __thiscall FUN_005f84ab(uint param_1,uint *param_2,uint param_3,int param_4,int param_5)

{
  double dVar1;
  int *piVar2;
  uint *puVar3;
  int *piVar4;
  float10 fVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  bool bVar20;
  byte bVar22;
  ushort uVar21;
  float10 fVar23;
  undefined8 local_44;
  uint local_3c [5];
  uint local_28;
  uint local_24;
  uint local_20;
  int *local_1c;
  int *local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  int *local_8;
  
  local_c = *param_2;
  iVar8 = *(int *)(param_1 + 0x14);
  uVar19 = *(uint *)(*(int *)(iVar8 + param_4 * 4) + 0x1c);
  uVar13 = *(uint *)(*(int *)(iVar8 + param_5 * 4) + 0x1c);
  piVar10 = *(int **)(iVar8 + param_3 * 4);
  local_1c = *(int **)(iVar8 + uVar19 * 4);
  local_18 = *(int **)(iVar8 + uVar13 * 4);
  local_8 = piVar10;
  if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar10 * 4) + 4) & 1) == 0) {
    return 0;
  }
  uVar14 = local_1c[6];
  uVar18 = local_18[6];
  uVar9 = uVar14 & 0x1f;
  local_14 = uVar18 & 0x1f;
  local_10 = uVar9;
  uVar15 = piVar10[6];
  uVar12 = uVar18 & uVar14 & 0x20 | uVar15;
  local_20 = uVar15 & 0x40;
  piVar10[6] = uVar12;
  if (((uVar15 & 0xe000000) == 0) &&
     (((uVar15 = local_c & 0xff000000, uVar15 == 0x20000000 || (uVar15 == 0x21000000)) ||
      (uVar15 == 0x24000000)))) {
    uVar16 = local_18[6] | local_1c[6];
    uVar15 = 0x8000000;
    if ((((uVar16 & 0x8000000) != 0) || (uVar15 = 0x4000000, (uVar16 & 0x4000000) != 0)) ||
       (uVar15 = 0x2000000, (uVar16 & 0x2000000) != 0)) {
      piVar10[6] = uVar12 | uVar15;
    }
  }
  if ((((local_18[6] | local_1c[6]) & 0x40U) != 0) &&
     (((uVar15 = local_c & 0xff000000, uVar15 == 0x20000000 || (uVar15 == 0x21000000)) ||
      ((uVar15 == 0x24000000 || ((uVar15 == 0x25000000 || (uVar15 == 0x26000000)))))))) {
    piVar10[6] = piVar10[6] | 0x40;
  }
  local_c = local_c & 0xff000000;
  if (local_c == 0x20000000) {
    uVar15 = uVar9 | 8;
    uVar12 = uVar14 & 8;
LAB_005f873f:
    uVar12 = uVar15 & local_14 | uVar12;
LAB_005f8744:
    piVar10[6] = piVar10[6] | uVar12;
  }
  else {
    if (local_c == 0x21000000) {
      uVar15 = uVar9 | 4;
      uVar12 = uVar14 & 4;
      goto LAB_005f873f;
    }
    if ((local_c != 0x22000000) && (local_c != 0x23000000)) {
      if (local_c != 0x24000000) {
        if (local_c == 0x25000000) {
          piVar10[6] = piVar10[6] | local_14 & uVar9 & 3;
          if ((((uVar14 & 4) != 0) && ((uVar18 & 4) != 0)) ||
             (((uVar14 & 8) != 0 && ((uVar18 & 8) != 0)))) {
            piVar10[6] = piVar10[6] | 4;
          }
          if ((((uVar14 & 4) != 0) && ((uVar18 & 8) != 0)) ||
             (((uVar14 & 8) != 0 && ((uVar18 & 4) != 0)))) {
            piVar10[6] = piVar10[6] | 8;
          }
          if (local_1c == local_18) {
            piVar10[6] = piVar10[6] | 4;
          }
          else if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *local_1c * 4) + 4) & 2) == 0) ||
                  (puVar3 = *(uint **)(*(int *)(param_1 + 0x18) + local_1c[0xb] * 4),
                  (*puVar3 & 0xff000000) != 0x11000000)) {
            if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *local_18 * 4) + 4) & 2) != 0) &&
               ((puVar3 = *(uint **)(*(int *)(param_1 + 0x18) + local_18[0xb] * 4),
                (*puVar3 & 0xff000000) == 0x11000000 && (uVar15 = 0, puVar3[3] != 0)))) {
              puVar6 = (uint *)puVar3[4];
              do {
                if (*puVar6 == uVar13) break;
                uVar15 = uVar15 + 1;
                puVar6 = puVar6 + 1;
              } while (uVar15 < puVar3[3]);
              if (uVar15 < puVar3[3]) {
                bVar20 = *(uint *)(puVar3[2] + uVar15 * 4) == uVar19;
                goto LAB_005f8709;
              }
            }
          }
          else {
            uVar15 = 0;
            if (puVar3[3] != 0) {
              puVar6 = (uint *)puVar3[4];
              do {
                if (*puVar6 == uVar19) break;
                uVar15 = uVar15 + 1;
                puVar6 = puVar6 + 1;
              } while (uVar15 < puVar3[3]);
            }
            if (uVar15 < puVar3[3]) {
              bVar20 = *(uint *)(puVar3[2] + uVar15 * 4) == uVar13;
LAB_005f8709:
              if (bVar20) {
                piVar10[6] = piVar10[6] | 8;
              }
            }
          }
        }
        goto LAB_005f8747;
      }
      uVar12 = local_14 & uVar9 & 0xe;
      goto LAB_005f8744;
    }
    piVar10[6] = piVar10[6] | 0x2000017;
  }
LAB_005f8747:
  local_3c[4] = param_1;
  if (local_20 == 0) {
    if (((uVar14 & 4) == 0) || ((uVar18 & 8) == 0)) {
LAB_005f87a9:
      if ((((uVar14 & 8) != 0) && ((uVar18 & 4) != 0)) &&
         ((uVar15 = uVar19, local_c == 0x20000000 || (uVar15 = uVar13, local_c == 0x21000000))))
      goto LAB_005f9198;
      goto LAB_005f87c7;
    }
    uVar15 = uVar13;
    if ((local_c == 0x20000000) || (uVar15 = uVar19, local_c == 0x21000000)) goto LAB_005f9198;
    if (local_c != 0x22000000) {
      if (local_c != 0x23000000) goto LAB_005f87a9;
      goto LAB_005f877c;
    }
    goto LAB_005f8cca;
  }
LAB_005f87c7:
  iVar8 = *(int *)(param_1 + 0x10);
  uVar18 = *(uint *)(*(int *)(iVar8 + *local_1c * 4) + 4);
  uVar15 = uVar18 & 0x80;
  local_28 = uVar18;
  if ((((uVar15 == 0) || (local_1c[1] != -1)) ||
      ((*(byte *)(*(int *)(iVar8 + *local_18 * 4) + 4) & 0x80) == 0)) || (local_18[1] != -1)) {
    if ((local_20 != 0) ||
       (((uVar15 == 0 || (local_1c[1] != -1)) &&
        (((*(byte *)(*(int *)(iVar8 + *local_18 * 4) + 4) & 0x80) == 0 || (local_18[1] != -1)))))) {
      if (local_1c == local_18) {
        uVar15 = uVar19;
        if ((local_c == 0x20000000) || (local_c == 0x21000000)) goto LAB_005f9198;
        if (local_c == 0x22000000) {
          bVar20 = local_20 == 0;
LAB_005f8ce4:
          if (!bVar20) {
            return 0;
          }
          goto LAB_005f8cca;
        }
        if (local_c == 0x23000000) {
          if (local_20 != 0) {
            return 0;
          }
          goto LAB_005f877c;
        }
        if ((local_c == 0x25000000) && ((uVar14 & 1) != 0)) goto LAB_005f9198;
      }
      if (local_20 != 0) {
        return 0;
      }
      if (local_c == 0x24000000) {
        if (((*(byte *)(*(int *)(iVar8 + *local_18 * 4) + 4) & 2) != 0) &&
           (puVar3 = *(uint **)(*(int *)(param_1 + 0x18) + local_18[0xb] * 4),
           (*puVar3 & 0xff000000) == 0x11000000)) {
          uVar14 = puVar3[3];
          uVar15 = 0;
          if (uVar14 != 0) {
            puVar6 = (uint *)puVar3[4];
            do {
              if (*puVar6 == uVar13) break;
              uVar15 = uVar15 + 1;
              puVar6 = puVar6 + 1;
            } while (uVar15 < uVar14);
          }
          if ((uVar15 < uVar14) && (uVar19 == *(uint *)(puVar3[2] + uVar15 * 4))) goto LAB_005f8cca;
        }
        if (((uVar18 & 2) != 0) &&
           (puVar3 = *(uint **)(*(int *)(param_1 + 0x18) + local_1c[0xb] * 4),
           (*puVar3 & 0xff000000) == 0x11000000)) {
          uVar14 = puVar3[3];
          uVar15 = 0;
          if (uVar14 != 0) {
            puVar6 = (uint *)puVar3[4];
            do {
              if (*puVar6 == uVar19) break;
              uVar15 = uVar15 + 1;
              puVar6 = puVar6 + 1;
            } while (uVar15 < uVar14);
          }
          if ((uVar15 < uVar14) && (uVar13 == *(uint *)(puVar3[2] + uVar15 * 4))) goto LAB_005f8cca;
        }
        local_1c = (int *)0x0;
        do {
          local_10 = uVar19;
          local_20 = uVar13;
          if (((uint)local_1c & 4) != 0) {
            local_10 = uVar13;
            local_20 = uVar19;
          }
          if (((uint)local_1c & 2) == 0) {
LAB_005f8d91:
            iVar8 = *(int *)(param_1 + 0x14);
            piVar2 = *(int **)(iVar8 + local_10 * 4);
            if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4) + 4) & 2) != 0) &&
               (puVar3 = *(uint **)(*(int *)(param_1 + 0x18) + piVar2[0xb] * 4),
               (*puVar3 & 0xff000000) == 0x24000000)) {
              uVar14 = puVar3[3];
              uVar15 = 0;
              if (uVar14 != 0) {
                puVar6 = (uint *)puVar3[4];
                do {
                  if (local_10 == *puVar6) {
                    uVar18 = puVar3[2];
                    if (((uint)local_1c & 1) == 0) {
                      iVar17 = *(int *)(uVar18 + (uVar14 + uVar15) * 4);
                      iVar7 = *(int *)(uVar18 + uVar15 * 4);
                    }
                    else {
                      iVar17 = *(int *)(uVar18 + uVar15 * 4);
                      iVar7 = *(int *)(uVar18 + (uVar14 + uVar15) * 4);
                    }
                    local_28 = *(uint *)(*(int *)(iVar8 + iVar17 * 4) + 0x1c);
                    local_44 = (ulonglong)*(uint *)(*(int *)(iVar8 + iVar7 * 4) + 0x1c) << 0x20;
                    uVar18 = local_28;
                    break;
                  }
                  uVar15 = uVar15 + 1;
                  puVar6 = puVar6 + 1;
                  uVar18 = local_28;
                } while (uVar15 < uVar14);
              }
              if (((uint)local_1c & 2) == 0) {
                piVar2 = *(int **)(iVar8 + uVar18 * 4);
                if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4) + 4) & 2) == 0) ||
                   (puVar3 = *(uint **)(*(int *)(param_1 + 0x18) + piVar2[0xb] * 4),
                   (*puVar3 & 0xff000000) != 0x11000000)) goto LAB_005f8e7c;
                uVar14 = 0;
                if (puVar3[3] != 0) {
                  puVar6 = (uint *)puVar3[4];
                  do {
                    if (uVar18 == *puVar6) {
                      uVar18 = *(uint *)(*(int *)(iVar8 + *(int *)(puVar3[2] + uVar14 * 4) * 4) +
                                        0x1c);
                      local_28 = uVar18;
                      break;
                    }
                    uVar14 = uVar14 + 1;
                    puVar6 = puVar6 + 1;
                  } while (uVar14 < puVar3[3]);
                }
              }
              if (local_20 == uVar18) {
                piVar10[7] = local_44._4_4_;
                return 0;
              }
            }
          }
          else {
            piVar2 = *(int **)(*(int *)(param_1 + 0x14) + local_20 * 4);
            if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4) + 4) & 2) != 0) &&
               (puVar3 = *(uint **)(*(int *)(param_1 + 0x18) + piVar2[0xb] * 4),
               (*puVar3 & 0xff000000) == 0x11000000)) {
              local_18 = (int *)0x0;
              if (puVar3[3] != 0) {
                puVar6 = (uint *)puVar3[4];
                do {
                  if (local_20 == *puVar6) {
                    local_20 = *(uint *)(*(int *)(*(int *)(param_1 + 0x14) +
                                                 *(int *)(puVar3[2] + (int)local_18 * 4) * 4) + 0x1c
                                        );
                    break;
                  }
                  local_18 = (int *)((int)local_18 + 1);
                  puVar6 = puVar6 + 1;
                } while (local_18 < (int *)puVar3[3]);
              }
              goto LAB_005f8d91;
            }
          }
LAB_005f8e7c:
          local_1c = (int *)((int)local_1c + 1);
        } while (local_1c < (int *)0x8);
      }
      if (local_c == 0x25000000) {
        local_3c[0] = uVar19;
        local_3c[1] = uVar13;
        local_20 = 0;
        local_24 = 0;
        local_3c[3] = 0;
        local_3c[2] = 0;
        local_28 = 0;
        do {
          iVar8 = *(int *)((int)local_3c + local_28);
          piVar2 = *(int **)(*(int *)(param_1 + 0x14) + iVar8 * 4);
          bVar22 = *(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4) + 4);
          while ((bVar22 & 2) != 0) {
            puVar3 = *(uint **)(*(int *)(param_1 + 0x18) + piVar2[0xb] * 4);
            if ((*puVar3 & 0xff000000) == 0x11000000) {
              puVar6 = &local_24;
            }
            else {
              if ((*puVar3 & 0xff000000) != 0x12000000) break;
              puVar6 = local_3c + 2;
            }
            *(uint *)((int)puVar6 + local_28) = (uint)(*(uint *)((int)puVar6 + local_28) == 0);
            local_3c[4] = puVar3[3];
            uVar14 = 0;
            if (local_3c[4] != 0) {
              piVar10 = (int *)puVar3[4];
              do {
                if (*piVar10 == iVar8) {
                  iVar8 = *(int *)(puVar3[2] + uVar14 * 4);
                  break;
                }
                uVar14 = uVar14 + 1;
                piVar10 = piVar10 + 1;
              } while (uVar14 < local_3c[4]);
            }
            if (local_3c[4] <= uVar14) {
              return 0x80004005;
            }
            piVar2 = *(int **)(*(int *)(param_1 + 0x14) + iVar8 * 4);
            piVar10 = local_8;
            bVar22 = *(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4) + 4);
          }
          *(int *)((int)local_3c + local_28) = iVar8;
          local_28 = local_28 + 4;
        } while (local_28 < 8);
        if ((local_3c[0] == local_3c[1]) && (local_3c[2] != local_3c[3])) {
          if (local_24 == local_20) goto LAB_005f877c;
          fVar23 = (float10)-1.0;
          goto LAB_005f877e;
        }
      }
      iVar8 = *(int *)(param_1 + 0x14);
      piVar2 = *(int **)(iVar8 + uVar19 * 4);
      if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4) + 4) & 2) == 0) {
        return 0;
      }
      piVar4 = *(int **)(iVar8 + uVar13 * 4);
      if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar4 * 4) + 4) & 2) == 0) {
        return 0;
      }
      if (((local_c == 0x25000000) || (local_c == 0x22000000)) || (local_c == 0x23000000)) {
        puVar3 = *(uint **)(*(int *)(param_1 + 0x18) + piVar2[0xb] * 4);
        puVar6 = *(uint **)(*(int *)(param_1 + 0x18) + piVar4[0xb] * 4);
        if (((*puVar3 & 0xff000000) == 0x11000000) && ((*puVar6 & 0xff000000) == 0x11000000)) {
          local_20 = 0;
          if (param_2[3] != 0) {
            piVar10 = (int *)param_2[4];
            do {
              if (param_3 == *piVar10) break;
              local_20 = local_20 + 1;
              piVar10 = piVar10 + 1;
            } while (local_20 < param_2[3]);
          }
          param_3 = 0;
          if (puVar3[3] != 0) {
            puVar11 = (uint *)puVar3[4];
            do {
              if (uVar19 == *puVar11) break;
              param_3 = param_3 + 1;
              puVar11 = puVar11 + 1;
            } while (param_3 < puVar3[3]);
          }
          uVar19 = 0;
          if (puVar6[3] != 0) {
            puVar11 = (uint *)puVar6[4];
            do {
              if (uVar13 == *puVar11) break;
              uVar19 = uVar19 + 1;
              puVar11 = puVar11 + 1;
            } while (uVar19 < puVar6[3]);
          }
          if (local_c == 0x25000000) {
            iVar17 = *(int *)(puVar3[2] + param_3 * 4);
            iVar7 = *(int *)(puVar6[2] + uVar19 * 4);
          }
          else {
            iVar17 = *(int *)(puVar6[2] + uVar19 * 4);
            iVar7 = *(int *)(puVar3[2] + param_3 * 4);
          }
          *(undefined4 *)(param_2[2] + local_20 * 4) =
               *(undefined4 *)(*(int *)(iVar8 + iVar17 * 4) + 0x1c);
          *(undefined4 *)(param_2[2] + (param_2[3] + local_20) * 4) =
               *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + iVar7 * 4) + 0x1c);
          return 0;
        }
      }
      if (((local_c == 0x22000000) && ((local_14 & 1) != 0)) &&
         (puVar3 = *(uint **)(*(int *)(param_1 + 0x18) + piVar2[0xb] * 4),
         (*puVar3 & 0xff000000) == 0x11000000)) {
        param_2 = (uint *)0x0;
        if (puVar3[3] != 0) {
          puVar6 = (uint *)puVar3[4];
          do {
            if (*puVar6 == uVar19) break;
            param_2 = (uint *)((int)param_2 + 1);
            puVar6 = puVar6 + 1;
          } while (param_2 < puVar3[3]);
        }
        uVar15 = uVar13;
        if (*(uint *)(puVar3[2] + (int)param_2 * 4) == uVar13) goto LAB_005f9198;
      }
      if (local_c != 0x25000000) {
        return 0;
      }
      if (uVar19 != uVar13) {
        return 0;
      }
      puVar3 = *(uint **)(*(int *)(param_1 + 0x18) + piVar2[0xb] * 4);
      if ((*puVar3 & 0xff000000) != 0x16000000) {
        return 0;
      }
      uVar13 = 0;
      if (puVar3[3] == 0) {
        return 0;
      }
      puVar6 = (uint *)puVar3[4];
      while (*puVar6 != uVar19) {
        uVar13 = uVar13 + 1;
        puVar6 = puVar6 + 1;
        if (puVar3[3] <= uVar13) {
          return 0;
        }
      }
      iVar8 = *(int *)(iVar8 + *(int *)(puVar3[2] + uVar13 * 4) * 4);
LAB_005f9195:
      uVar15 = *(uint *)(iVar8 + 0x1c);
      goto LAB_005f9198;
    }
    if ((uVar15 == 0) || (local_1c[1] != -1)) {
      dVar1 = *(double *)(local_18 + 4);
      param_2 = (uint *)uVar19;
    }
    else {
      dVar1 = *(double *)(local_1c + 4);
      uVar9 = local_14;
      param_2 = (uint *)uVar13;
    }
    fVar23 = (float10)dVar1;
    if (local_c == 0x20000000) {
      if (((float10)1.0 <= fVar23) && ((uVar9 & 1) != 0)) goto LAB_005f8ba6;
      if (fVar23 < (float10)0.0 == (fVar23 == (float10)0.0)) {
        return 0;
      }
      if ((uVar9 & 4) == 0) {
        return 0;
      }
    }
    else if (local_c == 0x21000000) {
      if ((fVar23 < (float10)1.0) || ((uVar9 & 1) == 0)) {
        if (fVar23 < (float10)0.0 == (fVar23 == (float10)0.0)) {
          return 0;
        }
        uVar9 = uVar9 & 4;
LAB_005f8acf:
        if (uVar9 == 0) {
          return 0;
        }
LAB_005f8ba6:
        piVar10[7] = (int)param_2;
        return 0;
      }
    }
    else {
      if (local_c == 0x22000000) {
        fVar5 = (float10)0.0;
        if (param_2 == (uint *)uVar13) {
          if ((fVar23 < fVar5) && ((uVar9 & 4) != 0)) {
LAB_005f877c:
            fVar23 = (float10)1;
            goto LAB_005f877e;
          }
          if (((fVar23 < (float10)0.0) || ((uVar9 & 8) == 0)) &&
             ((fVar23 < (float10)1.0 || ((uVar9 & 1) == 0)))) {
            bVar22 = (byte)((ushort)((ushort)(NAN(fVar23) || NAN((float10)0.0)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar23 == (float10)0.0) << 0xe) >> 8);
LAB_005f8ac1:
            if ((POPCOUNT(bVar22) & 1U) == 0) {
              return 0;
            }
            uVar9 = uVar9 & 1;
            goto LAB_005f8acf;
          }
        }
        else if ((fVar23 < fVar5 == (fVar23 == fVar5)) || ((uVar9 & 4) == 0)) {
          if ((fVar23 <= (float10)0.0) || ((uVar9 & 8) == 0)) {
            uVar21 = (ushort)(fVar23 < (float10)1.0) << 8 | (ushort)(fVar23 == (float10)1.0) << 0xe;
LAB_005f8b4f:
            if (uVar21 != 0) {
              return 0;
            }
            if ((uVar9 & 1) == 0) {
              return 0;
            }
          }
          goto LAB_005f877c;
        }
      }
      else {
        if (local_c != 0x23000000) {
          if (local_c == 0x24000000) {
            if (fVar23 != (float10)0.0) {
              return 0;
            }
            goto LAB_005f8ba6;
          }
          if (local_c != 0x25000000) {
            if (local_c != 0x26000000) {
              return 0;
            }
            if (fVar23 != (float10)0.0) {
              return 0;
            }
            bVar20 = param_2 == (uint *)uVar19;
            goto LAB_005f8ce4;
          }
          if (fVar23 == (float10)0.0) goto LAB_005f8cca;
          if (fVar23 == (float10)1.0) goto LAB_005f8ba6;
          if (fVar23 != (float10)0.5) {
            return 0;
          }
          piVar2 = *(int **)(*(int *)(param_1 + 0x14) + (int)param_2 * 4);
          if ((*(byte *)(*(int *)(iVar8 + *piVar2 * 4) + 4) & 2) == 0) {
            return 0;
          }
          puVar3 = *(uint **)(*(int *)(param_1 + 0x18) + piVar2[0xb] * 4);
          if ((*puVar3 & 0xff000000) != 0x24000000) {
            return 0;
          }
          uVar19 = puVar3[3];
          uVar13 = 0;
          if (uVar19 != 0) {
            puVar6 = (uint *)puVar3[4];
            do {
              if ((uint *)*puVar6 == param_2) break;
              uVar13 = uVar13 + 1;
              puVar6 = puVar6 + 1;
            } while (uVar13 < uVar19);
          }
          if (uVar19 <= uVar13) {
            return 0;
          }
          iVar8 = *(int *)(puVar3[2] + uVar13 * 4);
          if (iVar8 != *(int *)(puVar3[2] + (uVar19 + uVar13) * 4)) {
            return 0;
          }
          iVar8 = *(int *)(*(int *)(param_1 + 0x14) + iVar8 * 4);
          goto LAB_005f9195;
        }
        fVar5 = (float10)0.0;
        if (param_2 == (uint *)uVar13) {
          if ((fVar23 >= fVar5) || ((uVar9 & 4) == 0)) {
            if ((fVar23 < (float10)0.0) || ((uVar9 & 8) == 0)) {
              uVar21 = (ushort)(fVar23 < (float10)1.0) << 8;
              goto LAB_005f8b4f;
            }
            goto LAB_005f877c;
          }
        }
        else {
          if ((fVar23 < fVar5 != (fVar23 == fVar5)) && ((uVar9 & 4) != 0)) goto LAB_005f877c;
          if (((fVar23 <= (float10)0.0) || ((uVar9 & 8) == 0)) &&
             ((fVar23 <= (float10)1.0 || ((uVar9 & 1) == 0)))) {
            bVar22 = (byte)((ushort)((ushort)(NAN(fVar23) || NAN((float10)1.0)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar23 == (float10)1.0) << 0xe) >> 8);
            goto LAB_005f8ac1;
          }
        }
      }
LAB_005f8cca:
      fVar23 = (float10)0;
    }
  }
  else {
    fVar23 = (float10)*(double *)(local_1c + 4);
    dVar1 = *(double *)(local_18 + 4);
    if (local_c == 0x20000000) {
      if ((float10)dVar1 <= fVar23) {
LAB_005f88b7:
        fVar23 = (float10)dVar1;
      }
    }
    else {
      if (local_c != 0x21000000) {
        if (local_c == 0x22000000) {
          if (fVar23 < (float10)dVar1) goto LAB_005f877c;
        }
        else {
          if (local_c != 0x23000000) {
            if (local_c == 0x24000000) {
              fVar23 = fVar23 + (float10)dVar1;
            }
            else if (local_c == 0x25000000) {
              fVar23 = fVar23 * (float10)dVar1;
            }
            else {
              if (local_c != 0x26000000) {
                return 0;
              }
              fVar23 = (float10)fpatan(fVar23,(float10)dVar1);
            }
            goto LAB_005f877e;
          }
          if ((float10)dVar1 <= fVar23) goto LAB_005f877c;
        }
        goto LAB_005f8cca;
      }
      if (fVar23 < (float10)dVar1) goto LAB_005f88b7;
    }
  }
LAB_005f877e:
  uVar15 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x50),0,0,(double)fVar23);
  piVar10 = local_8;
LAB_005f9198:
  piVar10[7] = uVar15;
  return 0;
}


// ==== 0x5f91a4 FUN_005f91a4

int __thiscall
FUN_005f91a4(int param_1,uint *param_2,int param_3,uint param_4,int param_5,int param_6)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined1 local_68 [8];
  uint *local_60;
  int *local_58;
  int *local_30;
  int local_2c;
  int *local_28;
  int local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int local_8;
  
  iVar8 = *(int *)(param_1 + 0x14);
  piVar1 = *(int **)(*(int *)(iVar8 + param_5 * 4) + 0x1c);
  iVar11 = *(int *)(*(int *)(iVar8 + param_4 * 4) + 0x1c);
  piVar2 = *(int **)(*(int *)(iVar8 + param_6 * 4) + 0x1c);
  piVar7 = *(int **)(iVar8 + param_3 * 4);
  local_c = *(int **)(iVar8 + (int)piVar1 * 4);
  piVar3 = *(int **)(iVar8 + (int)piVar2 * 4);
  uVar10 = piVar7[6];
  local_28 = *(int **)(iVar8 + iVar11 * 4);
  if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar7 * 4) + 4) & 1) == 0) {
    return 0;
  }
  uVar5 = local_c[6] & piVar3[6] & local_28[6] & 0x20U | uVar10;
  piVar7[6] = uVar5;
  if (((uVar10 & 0xe000000) != 0) || ((*param_2 & 0xff000000) != 0x50000000)) goto LAB_005f927c;
  uVar12 = local_c[6] | piVar3[6];
  if ((uVar12 & 0x8000000) == 0) {
    if ((uVar12 & 0x4000000) != 0) {
      uVar5 = uVar5 | 0x4000000;
      goto LAB_005f926d;
    }
    if ((uVar12 & 0x2000000) != 0) {
      uVar5 = uVar5 | 0x2000000;
      goto LAB_005f926d;
    }
  }
  else {
    uVar5 = uVar5 | 0x8000000;
LAB_005f926d:
    piVar7[6] = uVar5;
  }
  piVar7[6] = piVar7[6] | local_c[6] & piVar3[6] & 0x1fU;
LAB_005f927c:
  if ((((local_c[6] | piVar3[6]) & 0x40U) != 0) && ((*param_2 & 0xff000000) == 0x50000000)) {
    piVar7[6] = piVar7[6] | 0x40;
  }
  if ((*param_2 & 0xff000000) != 0x50000000) {
    return 0;
  }
  piVar6 = piVar1;
  if (((uVar10 & 0x40) != 0) || ((*(byte *)(local_28 + 6) & 4) == 0)) {
    iVar8 = *(int *)(param_1 + 0x10);
    uVar5 = *(uint *)(*(int *)(iVar8 + *local_28 * 4) + 4);
    if (((char)uVar5 < '\0') && (local_28[1] == -1)) {
      if (*(double *)(local_28 + 4) < 0.0) {
        piVar6 = piVar2;
      }
    }
    else if ((piVar1 != piVar2) &&
            ((((uVar12 = *(uint *)(*(int *)(iVar8 + *local_c * 4) + 4) & 0x80, uVar12 == 0 ||
               (local_c[1] != -1)) || ((*(byte *)(*(int *)(iVar8 + *piVar3 * 4) + 4) & 0x80) == 0))
             || ((piVar3[1] != -1 || (*(double *)(local_c + 4) != *(double *)(piVar3 + 4))))))) {
      if ((uVar10 & 0x40) != 0) {
        return 0;
      }
      if (((((local_28[1] == -1) && ((uVar5 & 2) != 0)) &&
           ((puVar4 = *(uint **)(*(int *)(param_1 + 0x18) + local_28[0xb] * 4),
            (*puVar4 & 0xff000000) == 0x11000000 &&
            (((uVar12 != 0 && (local_c[1] == -1)) && (*(double *)(local_c + 4) == 0.0)))))) &&
          (((*(byte *)(*(int *)(iVar8 + *piVar3 * 4) + 4) & 0x80) != 0 && (piVar3[1] == -1)))) &&
         (*(double *)(piVar3 + 4) == 1.0)) {
        uVar10 = 0;
        if (puVar4[3] != 0) {
          local_10 = (int *)puVar4[4];
          do {
            if (*local_10 == iVar11) break;
            local_10 = local_10 + 1;
            uVar10 = uVar10 + 1;
          } while (uVar10 < puVar4[3]);
        }
        iVar8 = *(int *)(*(int *)(*(int *)(param_1 + 0x14) + *(int *)(puVar4[2] + uVar10 * 4) * 4) +
                        0x1c);
        if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x14) + iVar8 * 4) + 0x18) & 1) != 0) {
          piVar7[7] = iVar8;
          return 0;
        }
      }
      if (local_28[1] != -1) {
        return 0;
      }
      if (((((uVar5 & 2) != 0) &&
           (puVar4 = *(uint **)(*(int *)(param_1 + 0x18) + local_28[0xb] * 4),
           (*puVar4 & 0xff000000) == 0x25000000)) &&
          ((uVar12 != 0 &&
           (((local_c[1] == -1 && (*(double *)(local_c + 4) == 0.0)) &&
            ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar3 * 4) + 4) & 0x80) != 0)))))) &&
         ((piVar3[1] == -1 && (*(double *)(piVar3 + 4) == 1.0)))) {
        uVar10 = puVar4[3];
        local_10 = (int *)0x0;
        if (uVar10 != 0) {
          piVar6 = (int *)puVar4[4];
          do {
            if (*piVar6 == iVar11) break;
            local_10 = (int *)((int)local_10 + 1);
            piVar6 = piVar6 + 1;
          } while (local_10 < uVar10);
        }
        local_18 = (int *)0x0;
        iVar8 = *(int *)(param_1 + 0x14);
        local_24 = uVar10 * 4;
        local_14 = (int *)(puVar4[2] + (int)local_10 * 4);
        piVar9 = (int *)(puVar4[2] + ((int)local_10 + uVar10) * 4);
        do {
          local_30 = *(int **)(*(int *)(iVar8 + *local_14 * 4) + 0x1c);
          local_10 = *(int **)(iVar8 + *(int *)(*(int *)(iVar8 + *piVar9 * 4) + 0x1c) * 4);
          if ((((*(byte *)(*(int *)(iVar8 + (int)local_30 * 4) + 0x18) & 1) != 0) &&
              ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *local_10 * 4) + 4) & 0x80) != 0)) &&
             ((local_10[1] == -1 && (piVar6 = local_30, *(double *)(local_10 + 4) < 0.0))))
          goto LAB_005f95c1;
          local_18 = (int *)((int)local_18 + 1);
          local_14 = local_14 + uVar10;
          piVar9 = piVar9 + -uVar10;
        } while (local_18 < 2);
      }
      if (local_28[1] != -1) {
        return 0;
      }
      if ((uVar5 & 2) == 0) {
        return 0;
      }
      puVar4 = *(uint **)(*(int *)(param_1 + 0x18) + local_28[0xb] * 4);
      if ((*puVar4 & 0xff000000) != 0x24000000) {
        return 0;
      }
      local_1c = -1;
      if ((((uVar12 != 0) && (local_c[1] == -1)) &&
          ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar3 * 4) + 4) & 0x80) != 0)) &&
         (piVar3[1] == -1)) {
        if ((*(double *)(local_c + 4) == 0.0) && (*(double *)(piVar3 + 4) == 1.0)) {
          local_1c = 0x22000001;
        }
        else if ((*(double *)(local_c + 4) == 1.0) && (*(double *)(piVar3 + 4) == 0.0)) {
          local_1c = 0x23000001;
        }
      }
      uVar10 = puVar4[3];
      uVar5 = 0;
      if (uVar10 != 0) {
        piVar7 = (int *)puVar4[4];
        do {
          if (*piVar7 == iVar11) break;
          uVar5 = uVar5 + 1;
          piVar7 = piVar7 + 1;
        } while (uVar5 < uVar10);
      }
      param_4 = 0;
      iVar8 = *(int *)(param_1 + 0x14);
      local_2c = uVar10 * 4;
      local_18 = (int *)(puVar4[2] + uVar5 * 4);
      local_14 = (int *)(puVar4[2] + (uVar10 + uVar5) * 4);
      do {
        local_20 = *(int **)(*(int *)(iVar8 + *local_18 * 4) + 0x1c);
        iVar11 = *(int *)(*(int *)(iVar8 + *local_14 * 4) + 0x1c);
        piVar7 = *(int **)(iVar8 + iVar11 * 4);
        if (((piVar7[1] == -1) &&
            ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar7 * 4) + 4) & 2) != 0)) &&
           (puVar4 = *(uint **)(*(int *)(param_1 + 0x18) + piVar7[0xb] * 4),
           (*puVar4 & 0xff000000) == 0x11000000)) {
          uVar5 = 0;
          if (puVar4[3] != 0) {
            piVar7 = (int *)puVar4[4];
            do {
              if (*piVar7 == iVar11) break;
              uVar5 = uVar5 + 1;
              piVar7 = piVar7 + 1;
              local_30 = piVar7;
            } while (uVar5 < puVar4[3]);
          }
          piVar7 = *(int **)(*(int *)(iVar8 + *(int *)(puVar4[2] + uVar5 * 4) * 4) + 0x1c);
          iVar11 = local_1c;
          if (local_1c != -1) {
LAB_005f96ec:
            local_8 = param_1;
            FUN_005f7709();
            iVar8 = FUN_005f7760(iVar11,2,1,0);
            if ((-1 < iVar8) && (iVar8 = FUN_005f7a42(param_2), -1 < iVar8)) {
              *local_58 = param_3;
              *local_60 = (uint)local_20;
              local_60[1] = (uint)piVar7;
              iVar8 = FUN_005f84ab(local_68,param_3,local_20,piVar7);
            }
            FUN_005f7738();
            return iVar8;
          }
          if ((piVar1 == piVar7) && (piVar2 == local_20)) {
            iVar11 = 0x20000001;
            goto LAB_005f96ec;
          }
          if ((piVar1 == local_20) && (piVar2 == piVar7)) {
            iVar11 = 0x21000001;
            goto LAB_005f96ec;
          }
        }
        local_18 = local_18 + uVar10;
        param_4 = param_4 + 1;
        local_14 = local_14 + -uVar10;
        if (1 < param_4) {
          return 0;
        }
      } while( true );
    }
  }
LAB_005f95c1:
  piVar7[7] = (int)piVar6;
  return 0;
}


// ==== 0x5f974c FUN_005f974c

bool __thiscall FUN_005f974c(int param_1,uint *param_2,int param_3)

{
  double dVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  bool bVar5;
  uint *puVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int *piVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  bool bVar17;
  uint local_2c;
  int local_28;
  uint local_24;
  int *local_20;
  uint local_18;
  int local_14;
  uint local_8;
  
  puVar6 = param_2;
  iVar7 = FUN_005f7ac7();
  if (iVar7 == 0) {
    return true;
  }
  iVar7 = *(int *)(param_1 + 0x14);
  piVar10 = *(int **)(iVar7 + *(int *)param_2[4] * 4);
  if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar10 * 4) + 4) & 1) == 0) {
    return true;
  }
  uVar12 = *param_2 & 0xffffff;
  if (param_3 != 0) {
    local_28 = -1;
    dVar4 = 0.0;
    local_8 = 0;
    local_14 = 0;
    local_24 = 0;
    if (uVar12 != 0) {
      piVar9 = (int *)param_2[2];
      local_20 = piVar9 + uVar12;
      do {
        iVar2 = *(int *)(*(int *)(iVar7 + *local_20 * 4) + 0x1c);
        iVar3 = *(int *)(*(int *)(iVar7 + *piVar9 * 4) + 0x1c);
        piVar14 = *(int **)(iVar7 + iVar2 * 4);
        piVar8 = *(int **)(iVar7 + iVar3 * 4);
        if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar8 * 4) + 4) & 0x80) == 0) ||
           (piVar8[1] != -1)) {
          bVar17 = false;
        }
        else {
          bVar17 = true;
        }
        if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar14 * 4) + 4) & 0x80) == 0) ||
           (piVar14[1] != -1)) {
          bVar5 = false;
        }
        else {
          bVar5 = true;
        }
        if (((bVar17) && (*(double *)(piVar8 + 4) == 0.0)) ||
           ((bVar5 && (*(double *)(piVar14 + 4) == 0.0)))) {
LAB_005f9873:
          local_8 = local_8 + 1;
        }
        else {
          if (bVar17) {
            if (bVar5) {
              dVar4 = *(double *)(piVar14 + 4) * *(double *)(piVar8 + 4) + dVar4;
              goto LAB_005f9873;
            }
            dVar1 = *(double *)(piVar8 + 4);
          }
          else {
            if (!bVar5) break;
            dVar1 = *(double *)(piVar14 + 4);
            iVar2 = iVar3;
          }
          if (dVar1 != 1.0) break;
          local_14 = local_14 + 1;
          local_28 = iVar2;
        }
        local_24 = local_24 + 1;
        local_20 = local_20 + 1;
        piVar9 = piVar9 + 1;
      } while (local_24 < uVar12);
      if (((local_14 == 1) && (uVar12 - 1 == local_8)) && (dVar4 == 0.0)) {
        *param_2 = 0;
        goto LAB_005f98e4;
      }
    }
    if (uVar12 == local_8) {
      *param_2 = 0;
      local_28 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x50),0,0,dVar4);
      piVar10[7] = local_28;
      piVar10 = *(int **)(*(int *)(param_1 + 0x14) + local_28 * 4);
LAB_005f98e4:
      piVar10[7] = local_28;
      return false;
    }
  }
  local_8 = 0;
  bVar17 = false;
  if (uVar12 != 0) {
    piVar9 = (int *)param_2[2];
    piVar10 = piVar9 + uVar12;
    local_2c = uVar12;
    do {
      piVar14 = *(int **)(iVar7 + *piVar10 * 4);
      piVar8 = *(int **)(iVar7 + *piVar9 * 4);
      if (param_3 != 0) {
        piVar8 = *(int **)(iVar7 + piVar8[7] * 4);
        piVar14 = *(int **)(iVar7 + piVar14[7] * 4);
      }
      if (((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar8 * 4) + 4) & 0x80) == 0) ||
           (piVar8[1] != -1)) || (*(double *)(piVar8 + 4) != 0.0)) &&
         ((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar14 * 4) + 4) & 0x80) == 0 ||
           (piVar14[1] != -1)) || (*(double *)(piVar14 + 4) != 0.0)))) {
        local_8 = local_8 + 1;
      }
      piVar10 = piVar10 + 1;
      piVar9 = piVar9 + 1;
      local_2c = local_2c - 1;
    } while (local_2c != 0);
    if ((local_8 < uVar12) && ((local_8 == 1 || ((*(byte *)(param_1 + 0x90) & 6) == 0)))) {
      if (local_8 == 0) {
        *param_2 = 0;
        return false;
      }
      iVar7 = uVar12 << 2;
      local_8 = 0;
      local_18 = 0;
      local_28 = iVar7;
      do {
        uVar11 = param_2[2];
        iVar2 = *(int *)(uVar11 + local_18 * 4);
        iVar3 = *(int *)(param_1 + 0x14);
        iVar13 = *(int *)(uVar11 + iVar7);
        piVar10 = *(int **)(iVar3 + iVar2 * 4);
        if (param_3 != 0) {
          piVar10 = *(int **)(iVar3 + piVar10[7] * 4);
          iVar13 = *(int *)(*(int *)(iVar3 + iVar13 * 4) + 0x1c);
        }
        piVar9 = *(int **)(iVar3 + iVar13 * 4);
        if (((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar10 * 4) + 4) & 0x80) == 0) ||
             (piVar10[1] != -1)) || (*(double *)(piVar10 + 4) != 0.0)) &&
           ((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar9 * 4) + 4) & 0x80) == 0 ||
             (piVar9[1] != -1)) || (*(double *)(piVar9 + 4) != 0.0)))) {
          *(int *)(uVar11 + local_8 * 4) = iVar2;
          local_8 = local_8 + 1;
          *(undefined4 *)(param_2[2] + local_28) = *(undefined4 *)(param_2[2] + iVar7);
          local_28 = local_28 + 4;
        }
        local_18 = local_18 + 1;
        iVar7 = iVar7 + 4;
      } while (local_18 < uVar12);
      puVar15 = (undefined4 *)(uVar12 * 4 + param_2[2]);
      puVar16 = (undefined4 *)(local_8 * 4 + param_2[2]);
      for (uVar11 = local_8 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(undefined1 *)puVar16 = *(undefined1 *)puVar15;
        puVar15 = (undefined4 *)((int)puVar15 + 1);
        puVar16 = (undefined4 *)((int)puVar16 + 1);
      }
      if (local_8 == 1) {
        uVar11 = 0x25000001;
      }
      else {
        uVar11 = local_8 & 0xffffff | 0x30000000;
      }
      *param_2 = uVar11;
      param_2[1] = local_8 * 2;
      bVar17 = uVar12 != local_8;
      param_2[3] = 1;
      uVar12 = local_8;
    }
  }
  if ((uVar12 < 2) || ((uVar12 == 2 && ((*(byte *)(param_1 + 0x90) & 0x20) == 0)))) {
    param_2 = (uint *)0x0;
    if (uVar12 != 0) {
      local_18 = uVar12 << 2;
      do {
        if (param_3 == 0) {
          piVar10 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)(puVar6[2] + (int)param_2 * 4) * 4)
          ;
          piVar9 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)(puVar6[2] + local_18) * 4);
        }
        else {
          iVar7 = *(int *)(param_1 + 0x14);
          piVar10 = *(int **)(iVar7 + *(int *)(*(int *)(iVar7 + *(int *)(puVar6[2] +
                                                                        (int)param_2 * 4) * 4) +
                                              0x1c) * 4);
          piVar9 = *(int **)(iVar7 + *(int *)(*(int *)(iVar7 + *(int *)(puVar6[2] + local_18) * 4) +
                                             0x1c) * 4);
        }
        if (((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar10 * 4) + 4) & 0x80) == 0) ||
             (piVar10[1] != -1)) || (*(double *)(piVar10 + 4) != 1.0)) &&
           ((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar9 * 4) + 4) & 0x80) == 0 ||
             (piVar9[1] != -1)) || (*(double *)(piVar9 + 4) != 1.0)))) break;
        param_2 = (uint *)((int)param_2 + 1);
        local_18 = local_18 + 4;
      } while (param_2 < uVar12);
    }
    if (param_2 == (uint *)uVar12) {
      param_2 = (uint *)0x0;
      if (uVar12 != 0) {
        local_28 = uVar12 << 2;
        do {
          piVar10 = (int *)(puVar6[2] + (int)param_2 * 4);
          if (param_3 == 0) {
            piVar9 = *(int **)(*(int *)(param_1 + 0x14) + *piVar10 * 4);
          }
          else {
            piVar9 = *(int **)(*(int *)(param_1 + 0x14) +
                              *(int *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar10 * 4) + 0x1c) * 4
                              );
          }
          if ((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar9 * 4) + 4) & 0x80) != 0) &&
              (piVar9[1] == -1)) && (*(double *)(piVar9 + 4) == 1.0)) {
            *piVar10 = *(int *)(puVar6[2] + local_28);
          }
          param_2 = (uint *)((int)param_2 + 1);
          local_28 = local_28 + 4;
        } while (param_2 < uVar12);
      }
      if (uVar12 == 2) {
        *puVar6 = 0x24000001;
        puVar6[1] = 2;
      }
      else {
        *puVar6 = 0x10000001;
        puVar6[1] = 1;
      }
      bVar17 = true;
    }
  }
  return !bVar17;
}


// ==== 0x5f9c74 FUN_005f9c74

int __thiscall FUN_005f9c74(int param_1,int param_2,int *param_3,double *param_4)

{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double local_18;
  undefined4 local_10;
  int iStack_c;
  int local_8;
  
  piVar3 = param_3;
  if (((param_2 == *param_3) ||
      (piVar8 = *(int **)(*(int *)(param_1 + 0x14) + param_2 * 4), piVar8[1] != -1)) ||
     ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar8 * 4) + 4) & 2) == 0)) {
LAB_005f9e9c:
    if ((*piVar3 != -1) && (param_2 != *piVar3)) {
      return -0x7fffbffb;
    }
    local_18 = 1.0;
    param_3 = (int *)param_2;
  }
  else {
    puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + piVar8[0xb] * 4);
    uVar2 = puVar1[3];
    uVar4 = 0;
    if (uVar2 != 0) {
      piVar8 = (int *)puVar1[4];
      do {
        if (*piVar8 == param_2) break;
        uVar4 = uVar4 + 1;
        piVar8 = piVar8 + 1;
      } while (uVar4 < uVar2);
    }
    if (uVar4 == uVar2) goto LAB_005f9e9c;
    uVar7 = *puVar1 & 0xff000000;
    if (uVar7 == 0x10000000) {
      iVar5 = FUN_005f9c74(*(undefined4 *)(puVar1[2] + uVar4 * 4),param_3,param_4);
      if (-1 < iVar5) {
        return 0;
      }
      return iVar5;
    }
    if (uVar7 == 0x11000000) {
      iVar5 = FUN_005f9c74(*(undefined4 *)(puVar1[2] + uVar4 * 4),param_3,&local_18);
      if (iVar5 < 0) {
        return iVar5;
      }
      local_18 = -local_18;
      goto LAB_005f9eb9;
    }
    if (uVar7 != 0x24000000) {
      if (uVar7 == 0x25000000) {
        local_8 = *(int *)(puVar1[2] + uVar4 * 4);
        iStack_c = *(int *)(puVar1[2] + (uVar2 + uVar4) * 4);
        if (local_8 != iStack_c) {
          iVar5 = iStack_c * 4;
          piVar8 = *(int **)(iVar5 + *(int *)(param_1 + 0x14));
          if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar8 * 4) + 4) & 0x80) != 0) &&
             (piVar8[1] == -1)) {
            param_3 = (int *)*param_3;
            iVar6 = FUN_005f9c74(local_8,&param_3,&local_18);
            if (iVar6 < 0) goto LAB_005f9e4e;
LAB_005f9e89:
            *piVar3 = (int)param_3;
            local_18 = local_18 * *(double *)(*(int *)(iVar5 + *(int *)(param_1 + 0x14)) + 0x10);
            goto LAB_005f9eb9;
          }
LAB_005f9e4e:
          iVar5 = local_8 * 4;
          piVar8 = *(int **)(iVar5 + *(int *)(param_1 + 0x14));
          if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar8 * 4) + 4) & 0x80) != 0) &&
             (piVar8[1] == -1)) {
            param_3 = (int *)*piVar3;
            iVar6 = FUN_005f9c74(iStack_c,&param_3,&local_18);
            if (-1 < iVar6) goto LAB_005f9e89;
          }
        }
      }
      goto LAB_005f9e9c;
    }
    iVar5 = *(int *)(puVar1[2] + uVar4 * 4);
    local_8 = *(int *)(puVar1[2] + (uVar2 + uVar4) * 4);
    if (iVar5 == local_8) {
      iVar5 = FUN_005f9c74(iVar5,param_3,param_4);
      if (-1 < iVar5) {
        local_18 = *param_4 + *param_4;
        goto LAB_005f9eb9;
      }
      goto LAB_005f9e9c;
    }
    param_3 = (int *)*param_3;
    iVar6 = FUN_005f9c74(iVar5,&param_3,&local_18);
    if ((iVar6 < 0) || (iVar6 = FUN_005f9c74(local_8,&param_3,&local_10), iVar6 < 0)) {
      if (*piVar3 == -1) {
        param_3 = (int *)0xffffffff;
        iVar6 = FUN_005f9c74(local_8,&param_3,&local_10);
        if ((-1 < iVar6) && (iVar5 = FUN_005f9c74(iVar5,&param_3,&local_18), -1 < iVar5))
        goto LAB_005f9dc3;
      }
      goto LAB_005f9e9c;
    }
LAB_005f9dc3:
    local_18 = (double)CONCAT44(iStack_c,local_10) + local_18;
  }
  *piVar3 = (int)param_3;
LAB_005f9eb9:
  *param_4 = local_18;
  return 0;
}


// ==== 0x5f9ec4 FUN_005f9ec4

undefined4 __fastcall FUN_005f9ec4(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  undefined4 *puVar17;
  undefined4 *puVar18;
  bool bVar19;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  uint local_3c;
  int local_38;
  int *local_34;
  int *local_30;
  uint local_2c;
  uint local_28;
  int *local_24;
  int *local_20;
  uint local_1c;
  int *local_18;
  uint local_c;
  uint local_8;
  
  local_38 = -1;
  uVar2 = *(uint *)(param_1 + 0xc);
  uVar14 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    do {
      iVar10 = *(int *)(*(int *)(param_1 + 0x10) + uVar14 * 4);
      if ((*(byte *)(iVar10 + 4) & 0x20) == 0) {
        *(undefined4 *)(iVar10 + 0x10) = 0;
        *(undefined4 *)(iVar10 + 0x14) = 0;
      }
      uVar14 = uVar14 + 1;
    } while (uVar14 < *(uint *)(param_1 + 4));
  }
  local_2c = 0;
  if (uVar2 != 0) {
    do {
      puVar3 = *(uint **)(*(int *)(param_1 + 0x18) + local_2c * 4);
      iVar10 = FUN_005f7a96();
      if (iVar10 == 0) {
        uVar14 = 0;
        if (*(int *)(param_1 + 4) != 0) {
          do {
            iVar10 = uVar14 * 4;
            uVar14 = uVar14 + 1;
            *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x10) + iVar10) + 0x14) = 0;
          } while (uVar14 < *(uint *)(param_1 + 4));
        }
        if ((puVar3[3] < 5) ||
           ((iVar10 = FUN_005f7b0f(), iVar10 == 0 && (iVar10 = FUN_005f7b21(), iVar10 == 0)))) {
          local_8 = 0;
          if (puVar3[3] != 0) {
            do {
              piVar4 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)(puVar3[4] + local_8 * 4) * 4);
              iVar10 = *(int *)(*(int *)(param_1 + 0x10) + *piVar4 * 4);
              if (((*(byte *)(iVar10 + 4) & 0x20) == 0) && (piVar4[2] == -1)) {
                piVar4[2] = *(int *)(iVar10 + 0x10);
                piVar5 = (int *)(iVar10 + 0x14);
                piVar4[3] = *piVar5;
                *piVar5 = *piVar5 + 1;
                if (*(int *)(iVar10 + 0xc) == *piVar5) {
                  *(int *)(iVar10 + 0x10) = *(int *)(iVar10 + 0x10) + 1;
                  *piVar5 = 0;
                }
              }
              local_8 = local_8 + 1;
            } while (local_8 < puVar3[3]);
          }
          uVar14 = 0;
          if (*(int *)(param_1 + 4) != 0) {
            do {
              iVar10 = *(int *)(*(int *)(param_1 + 0x10) + uVar14 * 4);
              if (*(int *)(iVar10 + 0x14) != 0) {
                *(int *)(iVar10 + 0x10) = *(int *)(iVar10 + 0x10) + 1;
                *(undefined4 *)(iVar10 + 0x14) = 0;
              }
              uVar14 = uVar14 + 1;
            } while (uVar14 < *(uint *)(param_1 + 4));
          }
        }
        else {
          iVar10 = FUN_005f7b21();
          if (iVar10 == 0) {
            local_34 = (int *)0x0;
          }
          else {
            local_34 = (int *)puVar3[3];
          }
          iVar10 = FUN_005f7b67();
          local_8 = 0;
          if (puVar3[3] != 0) {
            local_24 = (int *)((int)local_34 << 2);
            do {
              iVar15 = *(int *)(param_1 + 0x14);
              piVar4 = *(int **)(iVar15 + *(int *)(local_8 * 4 + puVar3[4]) * 4);
              iVar16 = *(int *)(*(int *)(param_1 + 0x10) + *piVar4 * 4);
              if (((*(byte *)(iVar16 + 4) & 0x20) == 0) && (piVar4[2] == -1)) {
                piVar5 = *(int **)(iVar15 + *(int *)(puVar3[2] + local_8 * 4) * 4);
                piVar6 = *(int **)(iVar15 + *(int *)((int)local_24 + puVar3[2]) * 4);
                local_18 = (int *)local_8;
                if (local_8 < puVar3[3]) {
                  local_28 = (uint)local_24;
                  do {
                    iVar15 = *(int *)(param_1 + 0x14);
                    piVar7 = *(int **)(iVar15 + *(int *)((int)local_18 * 4 + puVar3[4]) * 4);
                    if ((*piVar4 == *piVar7) && (piVar7[2] == -1)) {
                      piVar8 = *(int **)(iVar15 + *(int *)((int)local_18 * 4 + puVar3[2]) * 4);
                      piVar9 = *(int **)(iVar15 + *(int *)(local_28 + puVar3[2]) * 4);
                      if ((((*piVar5 == *piVar8) &&
                           (((piVar5[1] == piVar8[1] && (piVar5[2] == piVar8[2])) &&
                            (*piVar6 == *piVar9)))) &&
                          ((piVar6[1] == piVar9[1] && (piVar6[2] == piVar9[2])))) ||
                         ((iVar10 != 0 &&
                          (((*piVar5 == *piVar9 && (piVar5[1] == piVar9[1])) &&
                           ((piVar5[2] == piVar9[2] &&
                            (((*piVar6 == *piVar8 && (piVar6[1] == piVar8[1])) &&
                             (piVar6[2] == piVar8[2])))))))))) {
                        piVar7[2] = *(int *)(iVar16 + 0x10);
                        piVar8 = (int *)(iVar16 + 0x14);
                        piVar7[3] = *piVar8;
                        *piVar8 = *piVar8 + 1;
                        if (*(int *)(iVar16 + 0xc) == *piVar8) {
                          *(int *)(iVar16 + 0x10) = *(int *)(iVar16 + 0x10) + 1;
                          *piVar8 = 0;
                        }
                      }
                    }
                    local_18 = (int *)((int)local_18 + 1);
                    local_28 = local_28 + 4;
                  } while (local_18 < puVar3[3]);
                }
                if (*(int *)(iVar16 + 0x14) != 0) {
                  *(int *)(iVar16 + 0x10) = *(int *)(iVar16 + 0x10) + 1;
                  *(undefined4 *)(iVar16 + 0x14) = 0;
                }
              }
              local_8 = local_8 + 1;
              local_24 = (int *)((int)local_24 + 4);
            } while (local_8 < puVar3[3]);
          }
        }
        iVar10 = FUN_005f7ad9();
        if (((iVar10 == 0) && (iVar10 = FUN_005f7b0f(), iVar10 == 0)) &&
           ((iVar10 = FUN_005f7b21(), iVar10 == 0 && (iVar10 = FUN_005f7b33(), iVar10 == 0)))) {
          iVar10 = FUN_005f7ac7();
          if (iVar10 == 0) {
            if (puVar3[3] == 0) {
              iVar10 = FUN_005f75cb();
              if (iVar10 == -1) {
                return 0x8007000e;
              }
            }
            else {
              local_34 = (int *)puVar3[4];
              local_c = 0;
              piVar4 = *(int **)(*(int *)(param_1 + 0x14) + *local_34 * 4);
              if (puVar3[3] != 0) {
                local_3c = puVar3[3];
                do {
                  piVar5 = *(int **)(*(int *)(param_1 + 0x14) + *local_34 * 4);
                  if (((*piVar4 == *piVar5) && (piVar4[1] == piVar5[1])) && (piVar4[2] == piVar5[2])
                     ) {
                    local_c = local_c + 1;
                  }
                  local_34 = local_34 + 1;
                  local_3c = local_3c - 1;
                } while (local_3c != 0);
              }
              uVar14 = puVar3[3];
              if (local_c == uVar14) {
                iVar10 = FUN_005f752b(*puVar3,puVar3[1],uVar14);
                if (iVar10 == -1) {
                  return 0x8007000e;
                }
                iVar10 = *(int *)(*(int *)(param_1 + 0x18) + iVar10 * 4);
                FUN_005f7a42();
                puVar17 = (undefined4 *)puVar3[2];
                puVar18 = *(undefined4 **)(iVar10 + 8);
                for (uVar14 = puVar3[1] & 0x3fffffff; uVar14 != 0; uVar14 = uVar14 - 1) {
                  *puVar18 = *puVar17;
                  puVar17 = puVar17 + 1;
                  puVar18 = puVar18 + 1;
                }
                for (iVar15 = 0; iVar15 != 0; iVar15 = iVar15 + -1) {
                  *(undefined1 *)puVar18 = *(undefined1 *)puVar17;
                  puVar17 = (undefined4 *)((int)puVar17 + 1);
                  puVar18 = (undefined4 *)((int)puVar18 + 1);
                }
                uVar14 = puVar3[3];
                puVar17 = (undefined4 *)puVar3[4];
                puVar18 = *(undefined4 **)(iVar10 + 0x10);
              }
              else {
                iVar10 = FUN_005f752b(*puVar3,puVar3[1],uVar14);
                if (iVar10 == -1) {
                  return 0x8007000e;
                }
                iVar10 = *(int *)(*(int *)(param_1 + 0x18) + iVar10 * 4);
                FUN_005f7a42();
                *(undefined4 *)
                 (*(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x60) * 4) + 0x14) = 0;
                local_28 = 0;
                if (*(int *)(iVar10 + 0xc) != 0) {
                  do {
                    iVar15 = *(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x60) * 4);
                    iVar16 = *(int *)(iVar15 + 0x14);
                    *(int *)(iVar15 + 0x14) = iVar16 + 1;
                    iVar15 = local_28 * 4;
                    uVar11 = FUN_005f74cf(*(int *)(param_1 + 0x60),
                                          *(undefined4 *)
                                           (*(int *)(*(int *)(param_1 + 0x10) +
                                                    *(int *)(param_1 + 0x60) * 4) + 0x10),iVar16,0);
                    *(undefined4 *)(iVar15 + *(int *)(iVar10 + 0x10)) = uVar11;
                    if (*(int *)(iVar15 + *(int *)(iVar10 + 0x10)) == -1) {
                      return 0x8007000e;
                    }
                    FUN_005f7cfc();
                    local_28 = local_28 + 1;
                    *(undefined4 *)
                     (*(int *)(*(int *)(param_1 + 0x14) +
                              *(int *)(iVar15 + *(int *)(iVar10 + 0x10)) * 4) + 0x18) =
                         *(undefined4 *)
                          (*(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar15 + puVar3[4]) * 4) +
                          0x18);
                  } while (local_28 < *(uint *)(iVar10 + 0xc));
                }
                piVar4 = (int *)(*(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x60) * 4) +
                                0x10);
                *piVar4 = *piVar4 + 1;
                *(undefined4 *)
                 (*(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x60) * 4) + 0x14) = 0;
                puVar17 = (undefined4 *)puVar3[2];
                puVar18 = *(undefined4 **)(iVar10 + 8);
                for (uVar14 = *(uint *)(iVar10 + 4) & 0x3fffffff; uVar14 != 0; uVar14 = uVar14 - 1)
                {
                  *puVar18 = *puVar17;
                  puVar17 = puVar17 + 1;
                  puVar18 = puVar18 + 1;
                }
                for (iVar15 = 0; iVar15 != 0; iVar15 = iVar15 + -1) {
                  *(undefined1 *)puVar18 = *(undefined1 *)puVar17;
                  puVar17 = (undefined4 *)((int)puVar17 + 1);
                  puVar18 = (undefined4 *)((int)puVar18 + 1);
                }
                iVar15 = FUN_005f752b(puVar3[3] & 0xffffff | 0x10000000,0xffffffff,0xffffffff);
                if (iVar15 == -1) {
                  return 0x8007000e;
                }
                iVar15 = *(int *)(*(int *)(param_1 + 0x18) + iVar15 * 4);
                FUN_005f7a42();
                puVar17 = (undefined4 *)puVar3[4];
                puVar18 = *(undefined4 **)(iVar15 + 0x10);
                for (uVar14 = *(uint *)(iVar15 + 0xc) & 0x3fffffff; uVar14 != 0; uVar14 = uVar14 - 1
                    ) {
                  *puVar18 = *puVar17;
                  puVar17 = puVar17 + 1;
                  puVar18 = puVar18 + 1;
                }
                for (iVar16 = 0; iVar16 != 0; iVar16 = iVar16 + -1) {
                  *(undefined1 *)puVar18 = *(undefined1 *)puVar17;
                  puVar17 = (undefined4 *)((int)puVar17 + 1);
                  puVar18 = (undefined4 *)((int)puVar18 + 1);
                }
                uVar14 = *(uint *)(iVar15 + 4);
                puVar17 = *(undefined4 **)(iVar10 + 0x10);
                puVar18 = *(undefined4 **)(iVar15 + 8);
              }
              for (uVar14 = uVar14 & 0x3fffffff; uVar14 != 0; uVar14 = uVar14 - 1) {
                *puVar18 = *puVar17;
                puVar17 = puVar17 + 1;
                puVar18 = puVar18 + 1;
              }
              for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                *(undefined1 *)puVar18 = *(undefined1 *)puVar17;
                puVar17 = (undefined4 *)((int)puVar17 + 1);
                puVar18 = (undefined4 *)((int)puVar18 + 1);
              }
            }
          }
          else {
            uVar14 = *puVar3;
            local_c = 0;
            *(undefined4 *)
             (*(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x60) * 4) + 0x14) = 0;
            uVar14 = uVar14 & 0xffffff;
            for (uVar12 = uVar14; uVar12 != 0; uVar12 = uVar12 - local_8) {
              local_8 = 0;
              uVar1 = uVar12;
              if ((4 < uVar12) && (uVar1 = local_8, uVar14 != 0)) {
                local_20 = (int *)puVar3[2];
                local_24 = local_20 + uVar14;
                local_3c = 1;
                do {
                  if (*local_20 != -1) {
                    piVar4 = *(int **)(*(int *)(param_1 + 0x14) + *local_20 * 4);
                    piVar5 = *(int **)(*(int *)(param_1 + 0x14) + *local_24 * 4);
                    local_1c = 1;
                    local_18 = local_24;
                    local_30 = local_20;
                    for (uVar1 = local_3c; uVar1 < uVar14; uVar1 = uVar1 + 1) {
                      local_18 = local_18 + 1;
                      local_30 = local_30 + 1;
                      if (*local_18 != -1) {
                        piVar6 = *(int **)(*(int *)(param_1 + 0x14) + *local_30 * 4);
                        piVar7 = *(int **)(*(int *)(param_1 + 0x14) + *local_18 * 4);
                        if (((((*piVar4 == *piVar6) && (piVar4[1] == piVar6[1])) &&
                             (piVar4[2] == piVar6[2])) &&
                            ((*piVar5 == *piVar7 && (piVar5[1] == piVar7[1])))) &&
                           ((piVar5[2] == piVar7[2] && (local_1c = local_1c + 1, local_1c == 4))))
                        break;
                      }
                    }
                    if (local_8 < local_1c) {
                      local_8 = local_1c;
                      local_48 = *piVar4;
                      local_54 = *piVar5;
                      local_4c = piVar4[1];
                      local_50 = piVar4[2];
                      local_58 = piVar5[1];
                      local_5c = piVar5[2];
                    }
                    uVar1 = local_8;
                    if (local_8 == 4) break;
                  }
                  local_20 = local_20 + 1;
                  local_24 = local_24 + 1;
                  bVar19 = local_3c < uVar14;
                  local_3c = local_3c + 1;
                  uVar1 = local_8;
                } while (bVar19);
              }
              local_8 = uVar1;
              iVar10 = FUN_005f752b(local_8 & 0xffffff | 0x30000000,0xffffffff,0xffffffff);
              if (iVar10 == -1) {
                return 0x8007000e;
              }
              iVar10 = *(int *)(*(int *)(param_1 + 0x18) + iVar10 * 4);
              FUN_005f7a42();
              local_24 = (int *)0x0;
              local_18 = (int *)0x0;
              if (uVar14 != 0) {
                iVar15 = uVar14 << 2;
                local_34 = (int *)(local_8 << 2);
                do {
                  if (local_8 <= local_24) break;
                  iVar16 = *(int *)(puVar3[2] + (int)local_18 * 4);
                  if (iVar16 != -1) {
                    piVar4 = *(int **)(*(int *)(param_1 + 0x14) + iVar16 * 4);
                    piVar5 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)(iVar15 + puVar3[2]) * 4);
                    if ((uVar12 < 5) ||
                       (((local_48 == *piVar4 && (local_4c == piVar4[1])) &&
                        ((local_50 == piVar4[2] &&
                         (((local_54 == *piVar5 && (local_58 == piVar5[1])) &&
                          (local_5c == piVar5[2])))))))) {
                      *(int *)(*(int *)(iVar10 + 8) + (int)local_24 * 4) = iVar16;
                      *(undefined4 *)((int)local_34 + *(int *)(iVar10 + 8)) =
                           *(undefined4 *)(iVar15 + puVar3[2]);
                      *(undefined4 *)(puVar3[2] + (int)local_18 * 4) = 0xffffffff;
                      *(undefined4 *)(iVar15 + puVar3[2]) = 0xffffffff;
                      local_24 = (int *)((int)local_24 + 1);
                      local_34 = (int *)((int)local_34 + 4);
                    }
                  }
                  local_18 = (int *)((int)local_18 + 1);
                  iVar15 = iVar15 + 4;
                } while (local_18 < uVar14);
              }
              if (uVar14 < 5) {
                **(undefined4 **)(iVar10 + 0x10) = *(undefined4 *)puVar3[4];
              }
              else {
                iVar15 = *(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x60) * 4);
                iVar16 = *(int *)(iVar15 + 0x14);
                *(int *)(iVar15 + 0x14) = iVar16 + 1;
                uVar11 = FUN_005f74cf(*(int *)(param_1 + 0x60),
                                      *(undefined4 *)
                                       (*(int *)(*(int *)(param_1 + 0x10) +
                                                *(int *)(param_1 + 0x60) * 4) + 0x10),iVar16,0);
                **(undefined4 **)(iVar10 + 0x10) = uVar11;
                if (**(int **)(iVar10 + 0x10) == -1) {
                  return 0x8007000e;
                }
                iVar10 = *(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x60) * 4);
                if (*(int *)(iVar10 + 0xc) == *(int *)(iVar10 + 0x14)) {
                  *(int *)(iVar10 + 0x10) = *(int *)(iVar10 + 0x10) + 1;
                  *(undefined4 *)
                   (*(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x60) * 4) + 0x14) = 0;
                }
              }
              local_c = local_c + 1;
            }
            iVar10 = *(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x60) * 4);
            if (*(int *)(iVar10 + 0x14) != 0) {
              piVar4 = (int *)(iVar10 + 0x10);
              *piVar4 = *piVar4 + 1;
            }
            if (1 < local_c) {
              if ((local_38 == -1) &&
                 (local_38 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x50),0xffffffff,0,
                                          0x3ff0000000000000), local_38 == -1)) {
                return 0x8007000e;
              }
              do {
                local_24 = (int *)(*(int *)(param_1 + 0xc) - local_c);
                local_20 = (int *)0x0;
                *(undefined4 *)
                 (*(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x60) * 4) + 0x14) = 0;
                if (local_c != 0) {
                  local_28 = 0;
                  do {
                    uVar14 = local_c - local_28;
                    if (4 < uVar14) {
                      uVar14 = 4;
                    }
                    if (uVar14 == 1) {
                      uVar12 = 0x10000001;
                    }
                    else if (uVar14 == 2) {
                      uVar12 = 0x24000001;
                    }
                    else {
                      uVar12 = uVar14 & 0xffffff | 0x30000000;
                    }
                    iVar10 = FUN_005f752b(uVar12,0xffffffff,0xffffffff);
                    if (iVar10 == -1) {
                      return 0x8007000e;
                    }
                    iVar10 = *(int *)(*(int *)(param_1 + 0x18) + iVar10 * 4);
                    FUN_005f7a42();
                    local_3c = 0;
                    if (uVar14 != 0) {
                      local_30 = (int *)(uVar14 << 2);
                      local_34 = (int *)((int)local_24 << 2);
                      do {
                        *(undefined4 *)(*(int *)(iVar10 + 8) + local_3c * 4) =
                             **(undefined4 **)
                               (*(int *)(*(int *)(param_1 + 0x18) + (int)local_34) + 0x10);
                        if (2 < uVar14) {
                          *(int *)((int)local_30 + *(int *)(iVar10 + 8)) = local_38;
                        }
                        local_34 = (int *)((int)local_34 + 4);
                        local_30 = (int *)((int)local_30 + 4);
                        local_3c = local_3c + 1;
                      } while (local_3c < uVar14);
                    }
                    if (local_c < 5) {
                      **(undefined4 **)(iVar10 + 0x10) = *(undefined4 *)puVar3[4];
                    }
                    else {
                      iVar15 = *(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x60) * 4);
                      iVar16 = *(int *)(iVar15 + 0x14);
                      *(int *)(iVar15 + 0x14) = iVar16 + 1;
                      uVar11 = FUN_005f74cf(*(int *)(param_1 + 0x60),
                                            *(undefined4 *)
                                             (*(int *)(*(int *)(param_1 + 0x10) +
                                                      *(int *)(param_1 + 0x60) * 4) + 0x10),iVar16,0
                                           );
                      **(undefined4 **)(iVar10 + 0x10) = uVar11;
                      if (**(int **)(iVar10 + 0x10) == -1) {
                        return 0x8007000e;
                      }
                      iVar10 = *(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x60) * 4);
                      if (*(int *)(iVar10 + 0xc) == *(int *)(iVar10 + 0x14)) {
                        *(int *)(iVar10 + 0x10) = *(int *)(iVar10 + 0x10) + 1;
                        *(undefined4 *)
                         (*(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x60) * 4) + 0x14)
                             = 0;
                      }
                    }
                    local_24 = (int *)((int)local_24 + uVar14);
                    local_28 = local_28 + 4;
                    local_20 = (int *)((int)local_20 + 1);
                  } while (local_28 < local_c);
                }
                iVar10 = *(int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x60) * 4);
                if (*(int *)(iVar10 + 0x14) != 0) {
                  piVar4 = (int *)(iVar10 + 0x10);
                  *piVar4 = *piVar4 + 1;
                }
                local_c = (uint)local_20;
              } while (1 < local_20);
            }
          }
        }
        else {
          uVar14 = puVar3[3];
          while (uVar14 != 0) {
            local_34 = (int *)puVar3[4];
            piVar4 = *(int **)(*(int *)(param_1 + 0x14) + *local_34 * 4);
            local_c = 0;
            if (puVar3[3] != 0) {
              local_3c = puVar3[3];
              do {
                piVar5 = *(int **)(*(int *)(param_1 + 0x14) + *local_34 * 4);
                if (((*piVar4 == *piVar5) && (piVar4[1] == piVar5[1])) && (piVar4[2] == piVar5[2]))
                {
                  local_c = local_c + 1;
                }
                local_34 = local_34 + 1;
                local_3c = local_3c - 1;
              } while (local_3c != 0);
            }
            iVar10 = FUN_005f752b((*puVar3 ^ local_c) & 0xffffff ^ *puVar3,0xffffffff,0xffffffff);
            if (iVar10 == -1) {
              return 0x8007000e;
            }
            iVar10 = *(int *)(*(int *)(param_1 + 0x18) + iVar10 * 4);
            FUN_005f7a42();
            iVar15 = FUN_005f7ad9();
            if (iVar15 == 0) {
              iVar15 = FUN_005f7b0f();
              if (iVar15 == 0) {
                iVar15 = FUN_005f7b21();
                if (iVar15 == 0) {
                  iVar15 = FUN_005f7b33();
                  if (iVar15 == 0) goto LAB_005facad;
                  iVar15 = 0;
                  local_8 = 0;
                  local_c = 0;
                  if (puVar3[3] != 0) {
                    do {
                      iVar16 = *(int *)(puVar3[4] + local_8 * 4);
                      piVar5 = *(int **)(*(int *)(param_1 + 0x14) + iVar16 * 4);
                      if (((*piVar4 == *piVar5) && (piVar4[1] == piVar5[1])) &&
                         (piVar4[2] == piVar5[2])) {
                        *(int *)(*(int *)(iVar10 + 0x10) + iVar15 * 4) = iVar16;
                        *(undefined4 *)(*(int *)(iVar10 + 8) + iVar15 * 4) =
                             *(undefined4 *)(puVar3[2] + local_8 * 4);
                        *(undefined4 *)
                         (*(int *)(iVar10 + 8) + (*(int *)(iVar10 + 0xc) + iVar15) * 4) =
                             *(undefined4 *)(puVar3[2] + (puVar3[3] + local_8) * 4);
                        *(undefined4 *)
                         (*(int *)(iVar10 + 8) + (local_c + *(int *)(iVar10 + 0xc) * 2) * 4) =
                             *(undefined4 *)(puVar3[2] + (local_8 + puVar3[3] * 2) * 4);
                        iVar15 = local_c + 1;
                        local_c = iVar15;
                      }
                      else {
                        iVar13 = (local_8 - iVar15) * 4;
                        *(int *)(iVar13 + puVar3[4]) = iVar16;
                        *(undefined4 *)(iVar13 + puVar3[2]) =
                             *(undefined4 *)(puVar3[2] + local_8 * 4);
                        *(undefined4 *)(puVar3[2] + ((puVar3[3] - iVar15) + local_8) * 4) =
                             *(undefined4 *)(puVar3[2] + (puVar3[3] + local_8) * 4);
                        *(undefined4 *)(puVar3[2] + ((puVar3[3] * 2 - iVar15) + local_8) * 4) =
                             *(undefined4 *)(puVar3[2] + (puVar3[3] * 2 + local_8) * 4);
                      }
                      local_8 = local_8 + 1;
                    } while (local_8 < puVar3[3]);
                  }
                  uVar14 = puVar3[3] - iVar15;
                  puVar17 = (undefined4 *)(puVar3[2] + puVar3[3] * 4);
                  puVar18 = (undefined4 *)(uVar14 * 4 + puVar3[2]);
                  for (uVar12 = uVar14 & 0x3fffffff; uVar12 != 0; uVar12 = uVar12 - 1) {
                    *puVar18 = *puVar17;
                    puVar17 = puVar17 + 1;
                    puVar18 = puVar18 + 1;
                  }
                  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(undefined1 *)puVar18 = *(undefined1 *)puVar17;
                    puVar17 = (undefined4 *)((int)puVar17 + 1);
                    puVar18 = (undefined4 *)((int)puVar18 + 1);
                  }
                  iVar10 = puVar3[3] - iVar15;
                  puVar17 = (undefined4 *)(puVar3[2] + puVar3[3] * 8);
                  puVar18 = (undefined4 *)(puVar3[2] + iVar10 * 8);
                  for (; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *puVar18 = *puVar17;
                    puVar17 = puVar17 + 1;
                    puVar18 = puVar18 + 1;
                  }
                  puVar3[3] = puVar3[3] - iVar15;
                  uVar14 = puVar3[3] * 3;
                }
                else {
                  iVar15 = 0;
                  local_8 = 0;
                  local_c = 0;
                  if (puVar3[3] != 0) {
                    do {
                      iVar16 = *(int *)(puVar3[4] + local_8 * 4);
                      piVar5 = *(int **)(*(int *)(param_1 + 0x14) + iVar16 * 4);
                      if (((*piVar4 == *piVar5) && (piVar4[1] == piVar5[1])) &&
                         (piVar4[2] == piVar5[2])) {
                        *(int *)(*(int *)(iVar10 + 0x10) + iVar15 * 4) = iVar16;
                        *(undefined4 *)(*(int *)(iVar10 + 8) + iVar15 * 4) =
                             *(undefined4 *)(puVar3[2] + local_8 * 4);
                        *(undefined4 *)
                         (*(int *)(iVar10 + 8) + (*(int *)(iVar10 + 0xc) + iVar15) * 4) =
                             *(undefined4 *)(puVar3[2] + (puVar3[3] + local_8) * 4);
                        iVar15 = local_c + 1;
                        local_c = iVar15;
                      }
                      else {
                        iVar13 = (local_8 - iVar15) * 4;
                        *(int *)(iVar13 + puVar3[4]) = iVar16;
                        *(undefined4 *)(iVar13 + puVar3[2]) =
                             *(undefined4 *)(puVar3[2] + local_8 * 4);
                        *(undefined4 *)(puVar3[2] + ((puVar3[3] - iVar15) + local_8) * 4) =
                             *(undefined4 *)(puVar3[2] + (puVar3[3] + local_8) * 4);
                      }
                      local_8 = local_8 + 1;
                    } while (local_8 < puVar3[3]);
                  }
                  uVar14 = puVar3[3] - iVar15;
                  puVar17 = (undefined4 *)(puVar3[2] + puVar3[3] * 4);
                  puVar18 = (undefined4 *)(uVar14 * 4 + puVar3[2]);
                  for (uVar12 = uVar14 & 0x3fffffff; uVar12 != 0; uVar12 = uVar12 - 1) {
                    *puVar18 = *puVar17;
                    puVar17 = puVar17 + 1;
                    puVar18 = puVar18 + 1;
                  }
                  for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *(undefined1 *)puVar18 = *(undefined1 *)puVar17;
                    puVar17 = (undefined4 *)((int)puVar17 + 1);
                    puVar18 = (undefined4 *)((int)puVar18 + 1);
                  }
                  puVar3[3] = puVar3[3] - iVar15;
                  uVar14 = puVar3[3] * 2;
                }
              }
              else {
                local_8 = 0;
                local_c = 0;
                if (puVar3[3] != 0) {
                  do {
                    iVar15 = *(int *)(puVar3[4] + local_8 * 4);
                    piVar5 = *(int **)(*(int *)(param_1 + 0x14) + iVar15 * 4);
                    if (((*piVar4 == *piVar5) && (piVar4[1] == piVar5[1])) &&
                       (piVar4[2] == piVar5[2])) {
                      *(int *)(*(int *)(iVar10 + 0x10) + local_c * 4) = iVar15;
                      *(undefined4 *)(*(int *)(iVar10 + 8) + local_c * 4) =
                           *(undefined4 *)(puVar3[2] + local_8 * 4);
                      local_c = local_c + 1;
                    }
                    else {
                      iVar16 = (local_8 - local_c) * 4;
                      *(int *)(iVar16 + puVar3[4]) = iVar15;
                      *(undefined4 *)(iVar16 + puVar3[2]) = *(undefined4 *)(puVar3[2] + local_8 * 4)
                      ;
                    }
                    local_8 = local_8 + 1;
                  } while (local_8 < puVar3[3]);
                }
                puVar3[3] = puVar3[3] - local_c;
                uVar14 = puVar3[3];
              }
              puVar3[1] = uVar14;
            }
            else {
              local_8 = 0;
              local_c = 0;
              if (puVar3[3] != 0) {
                do {
                  iVar15 = *(int *)(puVar3[4] + local_8 * 4);
                  piVar5 = *(int **)(*(int *)(param_1 + 0x14) + iVar15 * 4);
                  if (((*piVar4 == *piVar5) && (piVar4[1] == piVar5[1])) && (piVar4[2] == piVar5[2])
                     ) {
                    uVar14 = *(uint *)(iVar10 + 0x10);
                    uVar12 = local_c;
                    local_c = local_c + 1;
                  }
                  else {
                    uVar12 = local_8 - local_c;
                    uVar14 = puVar3[4];
                  }
                  local_8 = local_8 + 1;
                  *(int *)(uVar14 + uVar12 * 4) = iVar15;
                } while (local_8 < puVar3[3]);
              }
              puVar3[3] = puVar3[3] - local_c;
            }
LAB_005facad:
            uVar14 = puVar3[3];
          }
        }
        *puVar3 = 0;
      }
      local_2c = local_2c + 1;
    } while (local_2c < uVar2);
  }
  return 0;
}


// ==== 0x5facd2 FUN_005facd2

int __thiscall FUN_005facd2(int param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  if (param_4 != *(int *)(param_2 + 0x30)) {
    *(int *)(param_2 + 0x30) = param_4;
    *param_3 = *param_3 + 1;
    uVar2 = 0;
    if (*(int *)(param_2 + 0x14) != 0) {
      do {
        iVar1 = FUN_005facd2(*(undefined4 *)
                              (*(int *)(param_1 + 0x18) +
                              *(int *)(*(int *)(param_2 + 0x18) + uVar2 * 4) * 4),param_3,param_4);
        if (iVar1 < 0) {
          return iVar1;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(param_2 + 0x14));
    }
  }
  return 0;
}


// ==== 0x5fad2c FUN_005fad2c

int __thiscall
FUN_005fad2c(int param_1,undefined4 param_2,undefined4 param_3,int *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = FUN_005facd2(param_2,param_3,param_5);
  uVar4 = 0;
  if (-1 < iVar2) {
    if (*(int *)(param_1 + 0xc) != 0) {
      do {
        iVar2 = *(int *)(*(int *)(param_1 + 0x18) + uVar4 * 4);
        uVar3 = 0;
        if ((*(int *)(iVar2 + 0x24) == 0) && (*(int *)(iVar2 + 0x14) != 0)) {
          do {
            iVar1 = *(int *)(*(int *)(param_1 + 0x18) +
                            *(int *)(*(int *)(iVar2 + 0x18) + uVar3 * 4) * 4);
            if (param_5 == *(int *)(iVar2 + 0x30)) {
              if (*(int *)(iVar1 + 0x24) != 0) {
                *param_4 = *param_4 + -0x10000;
              }
            }
            else if (param_5 == *(int *)(iVar1 + 0x30)) {
              *param_4 = *param_4 + 0x10000;
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < *(uint *)(iVar2 + 0x14));
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(param_1 + 0xc));
    }
    iVar2 = 0;
  }
  return iVar2;
}


// ==== 0x5fada7 FUN_005fada7

int __thiscall FUN_005fada7(int param_1,uint param_2,int param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *local_10;
  int *local_c;
  uint local_8;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x18) + param_2 * 4);
  uVar5 = 0;
  if (*(int *)(iVar2 + 0x24) == 0) {
    local_8 = param_1;
    if (*(int *)(iVar2 + 0x14) != 0) {
      do {
        local_10 = (int *)0x0;
        piVar1 = (int *)(*(int *)(iVar2 + 0x18) + uVar5 * 4);
        iVar4 = *(int *)(*(int *)(local_8 + 0x18) + *piVar1 * 4);
        local_c = (int *)0x0;
        iVar3 = FUN_005fad2c(iVar4,&local_c,&local_10,*piVar1);
        if (iVar3 < 0) {
          return iVar3;
        }
        uVar5 = uVar5 + 1;
        *(uint *)(iVar4 + 0x2c) = (uint)local_10 / ((int)local_c + 1U);
      } while (uVar5 < *(uint *)(iVar2 + 0x14));
    }
    uVar5 = local_8;
    FUN_005f7e20(FUN_005f7de8,*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x14),local_8);
    uVar6 = 0;
    if (*(int *)(iVar2 + 0x14) != 0) {
      do {
        iVar4 = FUN_005fada7(*(undefined4 *)(*(int *)(iVar2 + 0x18) + uVar6 * 4),param_3,param_4);
        if (iVar4 < 0) {
          return iVar4;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(iVar2 + 0x14));
    }
    if (*(int *)(iVar2 + 0x24) == 0) {
      local_8 = 0;
      *(undefined4 *)(iVar2 + 0x24) = 1;
      *(uint *)(param_3 + *param_4 * 4) = param_2;
      *param_4 = *param_4 + 1;
      if (*(int *)(iVar2 + 0x14) != 0) {
        do {
          iVar4 = *(int *)(uVar5 + 0x18);
          iVar3 = *(int *)(iVar4 + *(int *)(*(int *)(iVar2 + 0x18) + local_8 * 4) * 4);
          uVar6 = *(uint *)(iVar3 + 0x1c);
          param_2 = 0;
          if (uVar6 != 0) {
            local_10 = *(int **)(iVar3 + 0x20);
            uVar7 = 0xffffffff;
            local_c = local_10;
            do {
              uVar8 = uVar7;
              if ((*(int *)(*(int *)(iVar4 + *local_c * 4) + 0x24) == 0) &&
                 (uVar8 = param_2, uVar7 != 0xffffffff)) goto LAB_005faed1;
              param_2 = param_2 + 1;
              local_c = local_c + 1;
              uVar7 = uVar8;
            } while (param_2 < uVar6);
            if (uVar8 != 0xffffffff) {
LAB_005faed1:
              if (param_2 == uVar6) {
                iVar3 = *(int *)(iVar4 + local_10[uVar7] * 4);
                uVar6 = *(uint *)(iVar3 + 0x14);
                param_2 = 0;
                if (uVar6 != 0) {
                  local_c = *(int **)(iVar3 + 0x18);
                  do {
                    if (*(int *)(*(int *)(iVar4 + *local_c * 4) + 0x24) == 0) break;
                    param_2 = param_2 + 1;
                    local_c = local_c + 1;
                  } while (param_2 < uVar6);
                }
                if ((uVar6 <= param_2) &&
                   (iVar4 = FUN_005fada7(local_10[uVar7],param_3,param_4), iVar4 < 0)) {
                  return iVar4;
                }
              }
            }
          }
          local_8 = local_8 + 1;
        } while (local_8 < *(uint *)(iVar2 + 0x14));
      }
    }
  }
  return 0;
}


// ==== 0x5faf39 FUN_005faf39

int __thiscall FUN_005faf39(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_2 + (param_4 + param_3 * 4) * 4);
  if (*piVar1 == -1) {
    iVar2 = *(int *)(param_5 * 4 + *(int *)(param_1 + 0x14));
    if (*(int *)(iVar2 + 8) == -1) {
      *(int *)(iVar2 + 8) = param_3;
      *(int *)(*(int *)(param_5 * 4 + *(int *)(param_1 + 0x14)) + 0xc) = param_4;
    }
    else {
      param_5 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x50),param_3,param_4,
                             *(undefined8 *)(iVar2 + 0x10));
    }
    *piVar1 = param_5;
  }
  return *piVar1;
}


// ==== 0x5faf93 FUN_005faf93

undefined4 __thiscall
FUN_005faf93(int param_1,int *param_2,uint param_3,int param_4,int *param_5,undefined4 param_6,
            uint param_7)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  uint local_48 [4];
  int local_38 [4];
  int *local_28;
  int *local_24;
  uint local_20;
  int *local_1c;
  uint local_18;
  int *local_14;
  int *local_10;
  int local_c;
  uint local_8;
  
  local_c = param_1;
  if (param_3 == 0) {
    return 1;
  }
  if (4 < param_3) {
    param_3 = 4;
  }
  piVar3 = local_38;
  for (uVar4 = param_3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  local_8 = 0;
  if (param_3 != 0) {
    do {
      local_1c = local_38 + local_8;
      if (*local_1c == 0) {
        local_14 = (int *)0xffffffff;
        local_24 = param_2 + local_8;
        piVar3 = (int *)*local_24;
        local_20 = 0;
        if (piVar3 == (int *)0xffffffff) {
          return 0;
        }
        do {
          piVar7 = *(int **)(*(int *)(local_c + 0x14) + (int)piVar3 * 4);
          if ((piVar7[0xb] == 0xffffffff) || ((uint)piVar7[0xb] < param_7)) {
            uVar4 = local_8 + 1;
            local_18 = 1;
            if (uVar4 < param_3) {
              piVar5 = param_2 + uVar4;
              local_10 = (int *)((int)local_38 - (int)param_2);
              iVar8 = param_3 - uVar4;
              do {
                if (*(int *)(((int)local_38 - (int)param_2) + (int)piVar5) == 0) {
                  iVar2 = *piVar5;
                  while (iVar2 != -1) {
                    piVar1 = *(int **)(*(int *)(local_c + 0x14) + iVar2 * 4);
                    if ((((piVar1[0xb] == 0xffffffff) || ((uint)piVar1[0xb] < param_7)) &&
                        (*piVar7 == *piVar1)) &&
                       ((piVar7[1] == piVar1[1] && (piVar7[2] == piVar1[2])))) {
                      local_18 = local_18 + 1;
                      break;
                    }
                    iVar2 = piVar1[8];
                  }
                }
                piVar5 = piVar5 + 1;
                iVar8 = iVar8 + -1;
              } while (iVar8 != 0);
            }
            if (local_20 < local_18) {
              local_20 = local_18;
              local_14 = piVar3;
            }
          }
          piVar3 = (int *)piVar7[8];
        } while (piVar3 != (int *)0xffffffff);
        if (local_14 == (int *)0xffffffff) {
          return 0;
        }
        *local_24 = (int)local_14;
        uVar4 = local_8 + 1;
        *local_1c = 1;
        local_10 = (int *)uVar4;
        if (uVar4 < param_3) {
          local_20 = (int)param_2 - (int)local_38;
          do {
            piVar3 = local_38 + (int)local_10;
            local_24 = piVar3;
            if (*piVar3 == 0) {
              piVar7 = (int *)((int)local_38 + local_20 + (int)local_10 * 4);
              iVar8 = *piVar7;
              if (iVar8 != -1) {
                do {
                  piVar5 = *(int **)(*(int *)(local_c + 0x14) + iVar8 * 4);
                  if (((piVar5[0xb] == 0xffffffff) || ((uint)piVar5[0xb] < param_7)) &&
                     ((piVar1 = *(int **)(*(int *)(local_c + 0x14) + (int)local_14 * 4),
                      *piVar1 == *piVar5 && ((piVar1[1] == piVar5[1] && (piVar1[2] == piVar5[2])))))
                     ) {
                    *piVar7 = iVar8;
                    *piVar3 = 1;
                    break;
                  }
                  iVar8 = piVar5[8];
                } while (iVar8 != -1);
              }
            }
            local_10 = (int *)((int)local_10 + 1);
          } while (local_10 < param_3);
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < param_3);
  }
  local_8 = 1;
  if (1 < param_3) {
    piVar3 = *(int **)(*(int *)(local_c + 0x14) + *param_2 * 4);
    do {
      piVar7 = *(int **)(*(int *)(local_c + 0x14) + param_2[local_8] * 4);
      if (((*piVar7 != *piVar3) || (piVar7[1] != piVar3[1])) || (piVar7[2] != piVar3[2])) break;
      local_8 = local_8 + 1;
    } while (local_8 < param_3);
  }
  if (local_8 == param_3) {
    return 1;
  }
  if (param_4 == 0) {
    return 0;
  }
  local_18 = 0;
  local_8 = 0;
  if (param_3 != 0) {
    iVar8 = *(int *)(local_c + 0x14);
    do {
      piVar3 = *(int **)(iVar8 + param_2[local_8] * 4);
      uVar4 = 0;
      if (local_8 != 0) {
        do {
          piVar7 = *(int **)(iVar8 + param_2[uVar4] * 4);
          if (*piVar3 == *piVar7) {
            if ((((*(byte *)(*(int *)(*(int *)(local_c + 0x10) + *piVar7 * 4) + 4) & 0x80) == 0) ||
                (piVar3[1] != -1)) || (piVar7[1] != -1)) {
              if (((piVar3[1] == piVar7[1]) && (piVar3[2] == piVar7[2])) && (piVar3[3] == piVar7[3])
                 ) break;
            }
            else if (*(double *)(piVar3 + 4) == *(double *)(piVar7 + 4)) break;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < local_8);
      }
      local_48[local_8] = uVar4;
      if (local_8 == uVar4) {
        local_18 = local_18 + 1;
      }
      local_8 = local_8 + 1;
    } while (local_8 < param_3);
  }
  local_20 = 0xffffffff;
  local_24 = (int *)0x0;
  local_8 = 0;
  if (param_3 != 0) {
    local_14 = (int *)((int)local_48 - (int)param_2);
    local_10 = param_2;
    do {
      if (local_8 == *(uint *)((int)local_10 + (int)local_14)) {
        piVar3 = *(int **)(*(int *)(local_c + 0x14) + *local_10 * 4);
        if (*(int *)(local_c + 0x60) == *piVar3) {
          param_7 = 0;
          local_1c = (int *)local_18;
          piVar7 = param_2;
          do {
            if (((param_7 == *(uint *)((int)local_14 + (int)piVar7)) &&
                (piVar5 = *(int **)(*(int *)(local_c + 0x14) + *piVar7 * 4),
                *(int *)(local_c + 0x60) == *piVar5)) && (piVar3[2] == piVar5[2])) {
              local_1c = (int *)((int)local_1c - 1);
            }
            param_7 = param_7 + 1;
            piVar7 = piVar7 + 1;
          } while (param_7 < param_3);
          if (((uint)(*(int *)(param_4 + piVar3[2] * 4) + (int)local_1c) < 5) &&
             (local_1c < local_20)) {
            local_20 = (uint)local_1c;
            local_24 = (int *)local_8;
          }
        }
      }
      local_8 = local_8 + 1;
      local_10 = local_10 + 1;
    } while (local_8 < param_3);
    if (local_20 != 0xffffffff) {
      iVar8 = *(int *)(*(int *)(*(int *)(local_c + 0x14) + param_2[(int)local_24] * 4) + 8);
      local_1c = (int *)0x0;
      goto LAB_005fb35f;
    }
  }
  if (param_5 == (int *)0x0) {
    return 0;
  }
  iVar8 = *param_5;
  *param_5 = iVar8 + 1;
  local_1c = (int *)0x1;
LAB_005fb35f:
  local_8 = 0;
  local_18 = iVar8;
  if (param_3 != 0) {
    local_14 = (int *)((int)local_48 - (int)param_2);
    piVar3 = param_2;
    do {
      if ((local_8 == *(uint *)((int)piVar3 + (int)local_14)) &&
         ((piVar7 = *(int **)(*(int *)(local_c + 0x14) + *piVar3 * 4),
          *(int *)(local_c + 0x60) != *piVar7 || (iVar8 != piVar7[2])))) {
        uVar6 = 0;
      }
      else {
        uVar6 = 1;
      }
      local_8 = local_8 + 1;
      *(undefined4 *)(((int)local_38 - (int)param_2) + (int)piVar3) = uVar6;
      piVar3 = piVar3 + 1;
    } while (local_8 < param_3);
  }
  local_8 = 0;
  if (param_3 != 0) {
    param_5 = param_2;
    local_10 = (int *)((int)local_38 - (int)param_2);
    do {
      iVar8 = local_c;
      if (*(int *)((int)local_10 + (int)param_5) == 0) {
        param_7 = 0;
        local_20 = 0;
        local_24 = (int *)param_3;
        piVar3 = param_2;
        do {
          if (*(int *)((int)local_10 + (int)piVar3) == 0) {
            piVar7 = *(int **)(*(int *)(local_c + 0x14) + *piVar3 * 4);
            piVar5 = *(int **)(*(int *)(local_c + 0x14) + param_2[local_8] * 4);
            if (((*piVar5 == *piVar7) && (piVar5[1] == piVar7[1])) && (piVar5[2] == piVar7[2])) {
              param_7 = param_7 + 1;
            }
            local_20 = local_20 + 1;
          }
          piVar3 = piVar3 + 1;
          local_24 = (int *)((int)local_24 - 1);
        } while (local_24 != (int *)0x0);
        if ((local_1c == (int *)0x0) &&
           (piVar3 = *(int **)(*(int *)(local_c + 0x14) + *param_5 * 4),
           *(int *)(local_c + 0x60) == *piVar3)) {
          iVar2 = piVar3[2];
          piVar3 = (int *)(param_4 + local_18 * 4);
          if ((*(int *)(param_4 + iVar2 * 4) - param_7) + local_20 + *piVar3 < 5) {
            param_7 = 0;
            local_20 = (int)param_2 - (int)local_38;
            do {
              local_24 = (int *)(param_7 * 4);
              local_14 = local_38 + param_7;
              if (((*local_14 == 0) &&
                  (piVar7 = *(int **)(*(int *)(iVar8 + 0x14) +
                                     *(int *)((int)local_38 + local_20 + param_7 * 4) * 4),
                  *(int *)(iVar8 + 0x60) == *piVar7)) && (iVar2 == piVar7[2])) {
                *local_14 = 1;
              }
              param_7 = param_7 + 1;
            } while (param_7 < param_3);
            param_7 = 0;
            if (*(int *)(iVar8 + 8) != 0) {
              do {
                piVar7 = *(int **)(*(int *)(iVar8 + 0x14) + param_7 * 4);
                if ((*(int *)(iVar8 + 0x60) == *piVar7) && (iVar2 == piVar7[2])) {
                  piVar7[2] = local_18;
                  piVar7 = (int *)(*(int *)(*(int *)(iVar8 + 0x14) + param_7 * 4) + 0xc);
                  *piVar7 = *piVar7 + *piVar3;
                }
                param_7 = param_7 + 1;
              } while (param_7 < *(uint *)(iVar8 + 8));
            }
            piVar7 = (int *)(param_4 + iVar2 * 4);
            *piVar3 = *piVar3 + *piVar7;
            *piVar7 = 0;
            goto LAB_005fb673;
          }
        }
        iVar2 = FUN_005f752b(param_7 & 0xffffff | 0x10000000,0xffffffff,0xffffffff);
        iVar8 = local_c;
        if (iVar2 == -1) {
          return 0;
        }
        iVar2 = *(int *)(*(int *)(local_c + 0x18) + iVar2 * 4);
        FUN_005f7a42();
        piVar3 = *(int **)(*(int *)(iVar8 + 0x14) + *param_5 * 4);
        local_24 = (int *)*piVar3;
        local_14 = (int *)piVar3[2];
        local_20 = piVar3[1];
        iVar8 = 0;
        param_7 = param_3;
        piVar3 = param_2;
        do {
          if ((((*(int *)((int)local_10 + (int)piVar3) == 0) &&
               (piVar7 = *(int **)(*(int *)(local_c + 0x14) + *piVar3 * 4),
               local_24 == (int *)*piVar7)) && (local_20 == piVar7[1])) &&
             (local_14 == (int *)piVar7[2])) {
            local_28 = (int *)(param_4 + local_18 * 4);
            uVar6 = FUN_005f74cf(*(undefined4 *)(local_c + 0x60),local_18,*local_28,0);
            *(undefined4 *)(iVar8 + *(int *)(iVar2 + 0x10)) = uVar6;
            *(int *)(iVar8 + *(int *)(iVar2 + 8)) = *piVar3;
            if (*(int *)(iVar8 + *(int *)(iVar2 + 0x10)) != -1) {
              FUN_005f7cfc();
              *(undefined4 *)
               (*(int *)(*(int *)(local_c + 0x14) + *(int *)(iVar8 + *(int *)(iVar2 + 0x10)) * 4) +
               0x18) = *(undefined4 *)(*(int *)(*(int *)(local_c + 0x14) + *piVar3 * 4) + 0x18);
              *(undefined4 *)
               (*(int *)(*(int *)(local_c + 0x14) + *(int *)(iVar8 + *(int *)(iVar2 + 0x10)) * 4) +
               0x20) = *(undefined4 *)(*(int *)(*(int *)(local_c + 0x14) + *piVar3 * 4) + 0x20);
              *(undefined4 *)(*(int *)(*(int *)(local_c + 0x14) + *piVar3 * 4) + 0x20) =
                   *(undefined4 *)(iVar8 + *(int *)(iVar2 + 0x10));
            }
            *piVar3 = *(int *)(iVar8 + *(int *)(iVar2 + 0x10));
            *(undefined4 *)((int)local_10 + (int)piVar3) = 1;
            *local_28 = *local_28 + 1;
            iVar8 = iVar8 + 4;
          }
          piVar3 = piVar3 + 1;
          param_7 = param_7 - 1;
        } while (param_7 != 0);
      }
LAB_005fb673:
      local_8 = local_8 + 1;
      param_5 = param_5 + 1;
    } while (local_8 < param_3);
  }
  if (param_3 != 0) {
    piVar3 = param_2;
    do {
      *piVar3 = param_2[*(int *)((int)piVar3 + ((int)local_48 - (int)param_2))];
      piVar3 = piVar3 + 1;
      param_3 = param_3 - 1;
    } while (param_3 != 0);
  }
  return 1;
}


// ==== 0x5fb6af FUN_005fb6af

undefined4 __thiscall FUN_005fb6af(int param_1,int param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint local_8;
  
  uVar5 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    do {
      iVar7 = *(int *)(*(int *)(param_1 + 0x10) + uVar5 * 4);
      uVar6 = *(uint *)(iVar7 + 4);
      if (((uVar6 & param_3) == param_3) && ((param_4 & uVar6) == 0)) {
        *(undefined4 *)(iVar7 + 8) = 0;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 4));
  }
  uVar5 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      piVar2 = *(int **)(*(int *)(param_1 + 0x14) + uVar5 * 4);
      iVar7 = *(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4);
      if ((((*(uint *)(iVar7 + 4) & param_3) == param_3) && ((param_4 & *(uint *)(iVar7 + 4)) == 0))
         && (uVar6 = piVar2[2] + 1, *(uint *)(iVar7 + 8) <= uVar6)) {
        *(uint *)(iVar7 + 8) = uVar6;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 8));
  }
  uVar5 = 0;
  iVar7 = 0;
  bVar4 = false;
  if (*(int *)(param_1 + 4) != 0) {
    do {
      iVar3 = *(int *)(*(int *)(param_1 + 0x10) + uVar5 * 4);
      uVar6 = *(uint *)(iVar3 + 4);
      if (((uVar6 & param_3) == param_3) && ((param_4 & uVar6) == 0)) {
        *(int *)(iVar3 + 0x10) = iVar7;
        *(int *)(iVar3 + 0x18) = param_2;
        if ((uVar6 & 0x200) != 0) {
          bVar4 = true;
        }
        iVar7 = iVar7 + *(int *)(iVar3 + 8);
        *(undefined4 *)(iVar3 + 8) = 0;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 4));
  }
  local_8 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      piVar2 = *(int **)(*(int *)(param_1 + 0x14) + local_8 * 4);
      iVar3 = *(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4);
      if (((*(uint *)(iVar3 + 4) & param_3) == param_3) && ((param_4 & *(uint *)(iVar3 + 4)) == 0))
      {
        *piVar2 = *(int *)(iVar3 + 0x18);
        piVar2[2] = piVar2[2] + *(int *)(iVar3 + 0x10);
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(param_1 + 8));
  }
  *(int *)(*(int *)(param_2 * 4 + *(int *)(param_1 + 0x10)) + 8) = iVar7;
  if (bVar4) {
    pbVar1 = (byte *)(*(int *)(param_2 * 4 + *(int *)(param_1 + 0x10)) + 5);
    *pbVar1 = *pbVar1 | 2;
  }
  return 0;
}


// ==== 0x5fb7cf FUN_005fb7cf

undefined4 __thiscall
FUN_005fb7cf(int param_1,undefined4 *param_2,uint param_3,uint param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 local_24 [4];
  uint local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  iVar4 = param_3;
  local_c = param_1;
  if (param_5 != 0) {
    uVar5 = 0;
    if (param_4 != 0) {
      do {
        *(uint *)(param_3 + uVar5 * 4) = uVar5;
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_4);
    }
    local_14 = 0;
    if (param_4 != 0) {
      do {
        piVar1 = (int *)(iVar4 + local_14 * 4);
        iVar3 = *piVar1;
        param_3 = *(uint *)(*(int *)(*(int *)(param_1 + 0x14) + param_2[iVar3] * 4) + 0xc);
        local_8 = local_14;
        local_14 = local_14 + 1;
        for (uVar5 = local_14; uVar5 < param_4; uVar5 = uVar5 + 1) {
          local_10 = *(uint *)(*(int *)(*(int *)(param_1 + 0x14) +
                                       param_2[*(int *)(iVar4 + uVar5 * 4)] * 4) + 0xc);
          if ((local_10 < param_3) || ((local_10 == param_3 && (uVar5 < local_8)))) {
            local_8 = uVar5;
            param_3 = local_10;
          }
        }
        piVar2 = (int *)(iVar4 + local_8 * 4);
        *piVar1 = *piVar2;
        *piVar2 = iVar3;
      } while (local_14 < param_4);
    }
  }
  uVar5 = 0;
  if (param_4 != 0) {
    do {
      local_24[uVar5] = param_2[*(int *)(iVar4 + uVar5 * 4)];
      uVar5 = uVar5 + 1;
    } while (uVar5 < param_4);
    if (param_4 != 0) {
      puVar6 = local_24;
      for (; param_4 != 0; param_4 = param_4 - 1) {
        *param_2 = *puVar6;
        puVar6 = puVar6 + 1;
        param_2 = param_2 + 1;
      }
    }
  }
  return 0;
}


// ==== 0x5fb8ae FUN_005fb8ae

undefined4 __fastcall FUN_005fb8ae(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  int *local_18;
  undefined4 *local_14;
  uint local_10;
  uint local_8;
  
  uVar6 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    do {
      iVar9 = *(int *)(*(int *)(param_1 + 0x10) + uVar6 * 4);
      uVar6 = uVar6 + 1;
      *(undefined4 *)(iVar9 + 0x28) = 0xffffffff;
      *(undefined4 *)(iVar9 + 0x2c) = 0;
      *(undefined4 *)(iVar9 + 0x30) = 0;
    } while (uVar6 < *(uint *)(param_1 + 4));
  }
  uVar6 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      iVar9 = *(int *)(*(int *)(param_1 + 0x14) + uVar6 * 4);
      uVar6 = uVar6 + 1;
      *(undefined4 *)(iVar9 + 0x2c) = 0xffffffff;
      *(undefined4 *)(iVar9 + 0x30) = 0xffffffff;
      *(undefined4 *)(iVar9 + 0x34) = 0xffffffff;
      *(undefined4 *)(iVar9 + 0x38) = 0xffffffff;
      *(undefined4 *)(iVar9 + 0x3c) = 0;
      *(undefined4 *)(iVar9 + 0x40) = 0;
    } while (uVar6 < *(uint *)(param_1 + 8));
  }
  local_14 = (undefined4 *)0x0;
  if (*(int *)(param_1 + 0x40) != 0) {
    uVar6 = 0;
    if (*(int *)(param_1 + 4) != 0) {
      do {
        iVar9 = uVar6 * 4;
        uVar6 = uVar6 + 1;
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x10) + iVar9) + 0x10) = 0;
      } while (uVar6 < *(uint *)(param_1 + 4));
    }
    uVar6 = 0;
    if (*(int *)(param_1 + 8) != 0) {
      do {
        piVar5 = *(int **)(*(int *)(param_1 + 0x14) + uVar6 * 4);
        iVar9 = *(int *)(*(int *)(param_1 + 0x10) + *piVar5 * 4);
        if ((((*(uint *)(iVar9 + 4) & 0x20) == 0) && ((*(uint *)(iVar9 + 4) & 2) != 0)) &&
           (uVar7 = piVar5[2] + 1, *(uint *)(iVar9 + 0x10) < uVar7)) {
          *(uint *)(iVar9 + 0x10) = uVar7;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(param_1 + 8));
    }
    iVar9 = *(int *)(param_1 + 4);
    uVar6 = 0;
    if (iVar9 != 0) {
      piVar5 = *(int **)(param_1 + 0x10);
      do {
        uVar6 = uVar6 + *(int *)(*piVar5 + 0x10);
        piVar5 = piVar5 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    local_14 = _malloc(uVar6 << 4);
    if (local_14 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
    puVar10 = local_14;
    for (iVar9 = (uVar6 & 0xfffffff) << 2; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar10 = 0xffffffff;
      puVar10 = puVar10 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)puVar10 = 0xff;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    iVar9 = 0;
    uVar6 = 0;
    if (*(int *)(param_1 + 4) != 0) {
      iVar4 = *(int *)(param_1 + 0x10);
      do {
        iVar4 = *(int *)(iVar4 + uVar6 * 4);
        *(uint *)(iVar4 + 0x20) =
             -(uint)(*(int *)(iVar4 + 0x10) != 0) & (uint)(local_14 + iVar9 * 4);
        iVar4 = *(int *)(param_1 + 0x10);
        iVar9 = iVar9 + *(int *)(*(int *)(iVar4 + uVar6 * 4) + 0x10);
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(param_1 + 4));
    }
  }
  uVar6 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      iVar9 = *(int *)(*(int *)(param_1 + 0x18) + uVar6 * 4);
      if ((iVar9 != 0) && (iVar4 = FUN_005f7a96(), iVar4 == 0)) {
        local_8 = 0;
        if (*(int *)(iVar9 + 4) != 0) {
          do {
            iVar4 = *(int *)(*(int *)(iVar9 + 8) + local_8 * 4);
            while (iVar4 != -1) {
              piVar5 = *(int **)(*(int *)(param_1 + 0x14) + iVar4 * 4);
              if (uVar6 < (uint)piVar5[0xe]) {
                piVar5[0xe] = uVar6;
              }
              piVar5[0x10] = piVar5[0x10] + 1;
              piVar5[0xf] = uVar6;
              if (piVar5[1] != -1) {
                iVar4 = *(int *)(*(int *)(param_1 + 0x10) + *piVar5 * 4);
                if (uVar6 < *(uint *)(iVar4 + 0x28)) {
                  *(uint *)(iVar4 + 0x28) = uVar6;
                }
                *(int *)(iVar4 + 0x30) = *(int *)(iVar4 + 0x30) + 1;
                *(uint *)(iVar4 + 0x2c) = uVar6;
              }
              iVar4 = piVar5[1];
            }
            local_8 = local_8 + 1;
          } while (local_8 < *(uint *)(iVar9 + 4));
        }
        local_10 = 0;
        if (*(int *)(iVar9 + 0xc) != 0) {
          do {
            piVar5 = *(int **)(*(int *)(param_1 + 0x14) +
                              *(int *)(*(int *)(iVar9 + 0x10) + local_10 * 4) * 4);
            iVar4 = *(int *)(*(int *)(param_1 + 0x10) + *piVar5 * 4);
            piVar5[0xb] = uVar6;
            if ((*(int *)(param_1 + 0x40) != 0) && (iVar1 = *(int *)(iVar4 + 0x20), iVar1 != 0)) {
              iVar8 = (piVar5[3] + piVar5[2] * 4) * 4;
              iVar1 = *(int *)(iVar8 + iVar1);
              if (iVar1 != -1) {
                iVar1 = *(int *)(*(int *)(param_1 + 0x18) + iVar1 * 4);
                uVar7 = *(uint *)(iVar1 + 0xc);
                local_8 = 0;
                if (uVar7 != 0) {
                  piVar2 = *(int **)(iVar1 + 0x10);
                  local_18 = piVar2;
                  do {
                    piVar3 = *(int **)(*(int *)(param_1 + 0x14) + *local_18 * 4);
                    if ((((*piVar5 == *piVar3) && (piVar5[1] == piVar3[1])) &&
                        (piVar5[2] == piVar3[2])) && (piVar5[3] == piVar3[3])) {
                      piVar5[0xc] = piVar2[local_8];
                      piVar3[0xd] = uVar6;
                      break;
                    }
                    local_8 = local_8 + 1;
                    local_18 = local_18 + 1;
                  } while (local_8 < uVar7);
                }
              }
              *(uint *)(iVar8 + *(int *)(iVar4 + 0x20)) = uVar6;
            }
            while (piVar5[1] != -1) {
              piVar5 = *(int **)(*(int *)(param_1 + 0x14) + piVar5[1] * 4);
              if (uVar6 < (uint)piVar5[0xe]) {
                piVar5[0xe] = uVar6;
              }
              piVar5[0x10] = piVar5[0x10] + 1;
              piVar5[0xf] = uVar6;
              if (piVar5[1] != -1) {
                iVar4 = *(int *)(*(int *)(param_1 + 0x10) + *piVar5 * 4);
                if (uVar6 < *(uint *)(iVar4 + 0x28)) {
                  *(uint *)(iVar4 + 0x28) = uVar6;
                }
                *(int *)(iVar4 + 0x30) = *(int *)(iVar4 + 0x30) + 1;
                *(uint *)(iVar4 + 0x2c) = uVar6;
              }
            }
            local_10 = local_10 + 1;
          } while (local_10 < *(uint *)(iVar9 + 0xc));
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_1 + 0xc));
  }
  uVar6 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      piVar5 = *(int **)(*(int *)(param_1 + 0x14) + uVar6 * 4);
      iVar9 = *(int *)(*(int *)(param_1 + 0x10) + *piVar5 * 4);
      if (piVar5[1] == -1) {
        if (*(uint *)(iVar9 + 0x28) < (uint)piVar5[0xe]) {
          piVar5[0xe] = *(uint *)(iVar9 + 0x28);
        }
        if ((uint)piVar5[0xf] < *(uint *)(iVar9 + 0x2c)) {
          piVar5[0xf] = *(uint *)(iVar9 + 0x2c);
        }
        piVar5[0x10] = piVar5[0x10] + *(int *)(iVar9 + 0x30);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_1 + 8));
  }
  uVar6 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      iVar9 = *(int *)(*(int *)(param_1 + 0x14) + uVar6 * 4);
      if (*(int *)(iVar9 + 0x30) == -1) {
        *(undefined4 *)(iVar9 + 0x30) = 0;
      }
      else {
        iVar4 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar9 + 0x30) * 4);
        if (*(int *)(iVar4 + 0x38) == *(int *)(iVar4 + 0x3c)) {
          *(int *)(iVar9 + 0x30) = *(int *)(iVar4 + 0x2c) + 1;
        }
        else {
          *(int *)(iVar9 + 0x30) = *(int *)(iVar4 + 0x3c);
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_1 + 8));
  }
  _free(local_14);
  return 0;
}


// ==== 0x5fbbf5 FUN_005fbbf5

undefined4 __fastcall FUN_005fbbf5(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  int *piVar6;
  int local_414 [256];
  uint local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  FUN_005fb8ae();
  local_14 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x18) + local_14 * 4);
      _free(*(void **)(iVar1 + 0x18));
      _free(*(void **)(iVar1 + 0x20));
      *(undefined4 *)(iVar1 + 0x14) = 0;
      *(undefined4 *)(iVar1 + 0x18) = 0;
      *(undefined4 *)(iVar1 + 0x1c) = 0;
      *(undefined4 *)(iVar1 + 0x20) = 0;
      iVar3 = FUN_005f7a96();
      if (iVar3 == 0) {
        local_c = (int *)0x0;
        if (*(int *)(iVar1 + 0xc) != 0) {
          local_8 = *(int **)(iVar1 + 0xc);
          piVar5 = *(int **)(iVar1 + 0x10);
          do {
            piVar6 = *(int **)(*(int *)(param_1 + 0x14) + *piVar5 * 4);
            if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar6 * 4) + 4) & 5) != 0) {
              local_c = (int *)((int)local_c + piVar6[0x10]);
            }
            piVar5 = piVar5 + 1;
            local_8 = (int *)((int)local_8 + -1);
          } while (local_8 != (int *)0x0);
        }
        pvVar4 = _malloc((int)local_c << 2);
        *(void **)(iVar1 + 0x20) = pvVar4;
        if (pvVar4 == (void *)0x0) {
          return 0x8007000e;
        }
        piVar5 = (int *)0x0;
        local_c = (int *)0x0;
        if (*(int *)(iVar1 + 0xc) != 0) {
          local_8 = *(int **)(iVar1 + 0x10);
          iVar3 = *(int *)(param_1 + 0x14);
          local_10 = *(int **)(iVar1 + 0xc);
          do {
            iVar2 = *(int *)(*(int *)(iVar3 + *local_8 * 4) + 4);
            piVar6 = local_c;
            while (local_c = piVar6, iVar2 != -1) {
              piVar5 = *(int **)(iVar3 + iVar2 * 4);
              if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar5 * 4) + 4) & 2) != 0) &&
                 (piVar6 < (int *)0x100)) {
                local_c = (int *)((int)piVar6 + 1);
                local_414[(int)piVar6] = piVar5[0xb];
              }
              iVar2 = piVar5[1];
              piVar5 = local_c;
              piVar6 = local_c;
            }
            local_8 = local_8 + 1;
            local_10 = (int *)((int)local_10 + -1);
          } while (local_10 != (int *)0x0);
        }
        if (*(int *)(iVar1 + 4) != 0) {
          local_8 = *(int **)(iVar1 + 8);
          iVar3 = *(int *)(param_1 + 0x10);
          local_10 = *(int **)(iVar1 + 4);
          do {
            piVar6 = *(int **)(*(int *)(param_1 + 0x14) + *local_8 * 4);
            while( true ) {
              if (((*(byte *)(*(int *)(iVar3 + *piVar6 * 4) + 4) & 2) != 0) &&
                 (piVar5 < (int *)0x100)) {
                local_414[(int)piVar5] = piVar6[0xb];
                piVar5 = (int *)((int)piVar5 + 1);
              }
              if (piVar6[1] == -1) break;
              piVar6 = *(int **)(*(int *)(param_1 + 0x14) + piVar6[1] * 4);
            }
            local_8 = local_8 + 1;
            local_10 = (int *)((int)local_10 + -1);
          } while (local_10 != (int *)0x0);
          local_10 = (int *)0x0;
          local_c = piVar5;
        }
        if (piVar5 != (int *)0x0) {
          FUN_005f7e20(FUN_005f7dd2,local_414,piVar5,0);
          piVar6 = (int *)0x1;
          local_8 = (int *)0x1;
          piVar5 = piVar6;
          if ((int *)0x1 < local_c) {
            do {
              if (local_414[(int)piVar6] != local_414[(int)piVar6 + -1]) {
                local_414[(int)piVar5] = local_414[(int)piVar6];
                piVar5 = (int *)((int)piVar5 + 1);
              }
              piVar6 = (int *)((int)piVar6 + 1);
              local_8 = piVar5;
            } while (piVar6 < local_c);
          }
          piVar5 = local_8;
          pvVar4 = _malloc((int)local_8 << 2);
          *(void **)(iVar1 + 0x18) = pvVar4;
          if (pvVar4 == (void *)0x0) {
            return 0x8007000e;
          }
          local_10 = (int *)0x0;
          if (piVar5 != (int *)0x0) {
            do {
              iVar3 = *(int *)(*(int *)(param_1 + 0x18) + local_414[(int)local_10] * 4);
              *(int *)(*(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0x14) * 4) =
                   local_414[(int)local_10];
              *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
              *(uint *)(*(int *)(iVar3 + 0x20) + *(int *)(iVar3 + 0x1c) * 4) = local_14;
              *(int *)(iVar3 + 0x1c) = *(int *)(iVar3 + 0x1c) + 1;
              local_10 = (int *)((int)local_10 + 1);
            } while (local_10 < local_8);
          }
        }
      }
      local_14 = local_14 + 1;
    } while (local_14 < *(uint *)(param_1 + 0xc));
  }
  return 0;
}


// ==== 0x5fbe17 FUN_005fbe17

undefined4 __fastcall FUN_005fbe17(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      *(uint *)(*(int *)(*(int *)(param_1 + 0x14) + uVar1 * 4) + 0x1c) = uVar1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(param_1 + 8));
  }
  return 0;
}


// ==== 0x5fbe30 FUN_005fbe30

undefined4 __fastcall FUN_005fbe30(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint local_8;
  
  uVar5 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      iVar2 = *(int *)(*(int *)(param_1 + 0x14) + uVar5 * 4);
      iVar3 = *(int *)(iVar2 + 4);
      if (iVar3 != -1) {
        *(undefined4 *)(iVar2 + 4) =
             *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + iVar3 * 4) + 0x1c);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 8));
  }
  local_8 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      piVar4 = *(int **)(*(int *)(param_1 + 0x18) + local_8 * 4);
      if (*piVar4 != 0) {
        uVar5 = 0;
        if (piVar4[1] != 0) {
          do {
            piVar1 = (int *)(piVar4[2] + uVar5 * 4);
            uVar5 = uVar5 + 1;
            *piVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar1 * 4) + 0x1c);
          } while (uVar5 < (uint)piVar4[1]);
        }
        uVar5 = 0;
        if (piVar4[3] != 0) {
          do {
            piVar1 = (int *)(piVar4[4] + uVar5 * 4);
            uVar5 = uVar5 + 1;
            *piVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar1 * 4) + 0x1c);
          } while (uVar5 < (uint)piVar4[3]);
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(param_1 + 0xc));
  }
  return 0;
}


// ==== 0x5fbec8 FUN_005fbec8

undefined4 FUN_005fbec8(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 local_104 [255];
  undefined1 local_5;
  
  _vsnprintf(local_104,0x100,param_4,&stack0x00000014);
  iVar1 = 0;
  local_5 = 0;
  if (param_2 != 0) {
    if (*(int *)(param_2 + 4) == 2) {
      iVar1 = param_2 + 0x10;
    }
    else if (*(int *)(param_2 + 4) == 0xc) {
      iVar1 = param_2 + 0x30;
    }
  }
  FUN_005b1f01(*(undefined4 *)(param_1 + 0x2c),iVar1,param_3,&DAT_006cc568,local_104);
  *(undefined4 *)(param_1 + 0x38) = 1;
  return 0;
}


// ==== 0x5fbf37 FUN_005fbf37

undefined4 FUN_005fbf37(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 local_104 [255];
  undefined1 local_5;
  
  _vsnprintf(local_104,0x100,param_4,&stack0x00000014);
  iVar1 = 0;
  local_5 = 0;
  if (param_2 != 0) {
    if (*(int *)(param_2 + 4) == 2) {
      iVar1 = param_2 + 0x10;
    }
    else if (*(int *)(param_2 + 4) == 0xc) {
      iVar1 = param_2 + 0x30;
    }
  }
  FUN_005b1fca(*(undefined4 *)(param_1 + 0x2c),iVar1,param_3,&DAT_006cc568,local_104);
  return 0;
}


// ==== 0x5fbf9d FUN_005fbf9d

void * __thiscall FUN_005fbf9d(void *param_1,byte param_2)

{
  FUN_005f7f76();
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


// ==== 0x5fbfb9 FUN_005fbfb9

int __thiscall FUN_005fbfb9(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 == 0) {
    iVar1 = -0x7fffbffb;
  }
  else {
    param_1[0xb] = param_3;
    param_1[0xc] = param_4;
    param_1[0xd] = param_5;
    param_1[10] = param_2;
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    param_1[0x10] = 0;
    iVar1 = FUN_005f7478(&DAT_0069ee78,0,0xffffffff,4);
    param_1[0x13] = iVar1;
    iVar1 = FUN_005f7478(&DAT_0069ed74,0x189,0xffffffff,4);
    param_1[0x14] = iVar1;
    iVar1 = FUN_005f7478(&DAT_0069ecd8,0x129,0xffffffff,4);
    param_1[0x15] = iVar1;
    iVar1 = FUN_005f7478(&DAT_006a2f84,0x29,0xffffffff,4);
    param_1[0x16] = iVar1;
    iVar1 = FUN_005f7478(&DAT_006a2f38,0x32,0xffffffff,4);
    param_1[0x17] = iVar1;
    iVar1 = FUN_005f7478(&DAT_006c16ac,3,0xffffffff,4);
    param_1[0x18] = iVar1;
    iVar1 = FUN_005f7478(&DAT_006c166c,6,0xffffffff,4);
    param_1[0x19] = iVar1;
    iVar1 = FUN_005f7478(&DAT_0069ed7c,0x169,0xffffffff,4);
    param_1[0x1a] = iVar1;
    if (param_1[1] == 8) {
      piVar2 = param_1 + 0x1b;
      for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar2 = 0;
        piVar2 = piVar2 + 1;
      }
      iVar1 = (**(code **)(*param_1 + 0x10))();
      if ((-1 < iVar1) && (iVar1 = FUN_005f7f90(0), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    else {
      iVar1 = -0x7ff8fff2;
    }
  }
  return iVar1;
}


// ==== 0x5fc0d0 FUN_005fc0d0

undefined4 __fastcall FUN_005fc0d0(int param_1)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  uint local_10;
  uint local_8;
  
  uVar6 = 0;
  bVar2 = false;
  if (*(int *)(param_1 + 4) != 0) {
    do {
      iVar5 = *(int *)(*(int *)(param_1 + 0x10) + uVar6 * 4);
      *(undefined4 *)(iVar5 + 0x28) = 0xffffffff;
      *(undefined4 *)(iVar5 + 0x24) = 0xffffffff;
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_1 + 4));
  }
  uVar6 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      iVar5 = *(int *)(*(int *)(param_1 + 0x14) + uVar6 * 4);
      *(undefined4 *)(iVar5 + 0x38) = 0xffffffff;
      *(undefined4 *)(iVar5 + 0x2c) = 0xffffffff;
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_1 + 8));
  }
  uVar6 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      iVar5 = *(int *)(*(int *)(param_1 + 0x18) + uVar6 * 4);
      iVar3 = FUN_005f7a96();
      if (iVar3 == 0) {
        local_8 = 0;
        if (*(int *)(iVar5 + 4) != 0) {
          do {
            iVar3 = *(int *)(*(int *)(iVar5 + 8) + local_8 * 4);
            while( true ) {
              piVar4 = *(int **)(*(int *)(param_1 + 0x14) + iVar3 * 4);
              if (uVar6 < (uint)piVar4[0xe]) {
                piVar4[0xe] = uVar6;
              }
              if (piVar4[1] == -1) break;
              iVar3 = *(int *)(*(int *)(param_1 + 0x10) + *piVar4 * 4);
              if (uVar6 < *(uint *)(iVar3 + 0x28)) {
                *(uint *)(iVar3 + 0x28) = uVar6;
              }
              iVar3 = piVar4[1];
            }
            local_8 = local_8 + 1;
          } while (local_8 < *(uint *)(iVar5 + 4));
        }
        local_8 = 0;
        if (*(int *)(iVar5 + 0xc) != 0) {
          do {
            piVar4 = *(int **)(*(int *)(param_1 + 0x14) +
                              *(int *)(*(int *)(iVar5 + 0x10) + local_8 * 4) * 4);
            if (uVar6 < (uint)piVar4[0xb]) {
              piVar4[0xb] = uVar6;
            }
            if (piVar4[1] != -1) {
              iVar3 = *(int *)(*(int *)(param_1 + 0x10) + *piVar4 * 4);
              if (uVar6 < *(uint *)(iVar3 + 0x24)) {
                *(uint *)(iVar3 + 0x24) = uVar6;
              }
              while( true ) {
                piVar4 = *(int **)(*(int *)(param_1 + 0x14) + piVar4[1] * 4);
                if (uVar6 < (uint)piVar4[0xe]) {
                  piVar4[0xe] = uVar6;
                }
                if (piVar4[1] == -1) break;
                iVar3 = *(int *)(*(int *)(param_1 + 0x10) + *piVar4 * 4);
                if (uVar6 < *(uint *)(iVar3 + 0x28)) {
                  *(uint *)(iVar3 + 0x28) = uVar6;
                }
              }
            }
            local_8 = local_8 + 1;
          } while (local_8 < *(uint *)(iVar5 + 0xc));
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_1 + 0xc));
  }
  local_10 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      piVar4 = *(int **)(*(int *)(param_1 + 0x14) + local_10 * 4);
      iVar5 = *(int *)(*(int *)(param_1 + 0x10) + *piVar4 * 4);
      if (*(uint *)(iVar5 + 0x28) < (uint)piVar4[0xe]) {
        piVar4[0xe] = *(uint *)(iVar5 + 0x28);
      }
      if (*(uint *)(iVar5 + 0x24) < (uint)piVar4[0xb]) {
        piVar4[0xb] = *(uint *)(iVar5 + 0x24);
      }
      uVar6 = *(uint *)(iVar5 + 4);
      if ((((uVar6 & 8) == 0) && (uVar1 = piVar4[0xe], uVar1 != 0xffffffff)) &&
         (uVar1 <= (uint)piVar4[0xb])) {
        iVar5 = piVar4[0x11];
        if (((iVar5 == 0) || (*(int *)(iVar5 + 4) != 5)) ||
           ((iVar3 = *(int *)(iVar5 + 0x14), iVar3 == 0 || (*(int *)(iVar3 + 4) != 2)))) {
          FUN_005fbec8(param_1,0,0,
                       "internal error: argument used without having been initialized (A%u)",
                       local_10);
        }
        else if (*(int *)(iVar5 + 0x28) == 0) {
          FUN_005fbec8(param_1,*(undefined4 *)
                                (*(int *)(*(int *)(param_1 + 0x18) + uVar1 * 4) + 0x34),4000,
                       "variable \'%s\' used without having been completely initialized",
                       *(undefined4 *)(iVar3 + 0x18));
          *(undefined4 *)(iVar5 + 0x28) = 1;
        }
LAB_005fc30f:
        bVar2 = true;
      }
      else {
        if (((uVar6 & 0x10) != 0) && (piVar4[0xb] == -1)) {
          pcVar7 = "internal error: output argument was never initialized (A%u)";
LAB_005fc304:
          FUN_005fbec8(param_1,0,0,pcVar7,local_10);
          goto LAB_005fc30f;
        }
        if (((uVar6 & 2) == 0) && (piVar4[0xb] != -1)) {
          pcVar7 = "internal error: cannot write to argument pool (A%u)";
          goto LAB_005fc304;
        }
        if (((uVar6 & 5) == 0) && (piVar4[0xe] != -1)) {
          pcVar7 = "internal error: cannot read from argument pool (A%u)";
          goto LAB_005fc304;
        }
        if ((((*(int *)(param_1 + 0x3c) != 0) && ((uVar6 & 0x90) == 0)) && (piVar4[0xe] == -1)) &&
           (((uVar6 & 8) != 0 || ((piVar4[0xb] != -1 && (iVar5 = FUN_005f7b57(), iVar5 == 0)))))) {
          pcVar7 = "internal error: argument was never used (A%u)";
          goto LAB_005fc304;
        }
      }
      local_10 = local_10 + 1;
    } while (local_10 < *(uint *)(param_1 + 8));
    if (bVar2) {
      return 0x80004005;
    }
  }
  return 0;
}


// ==== 0x5fc336 FUN_005fc336

int __fastcall FUN_005fc336(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int *local_20;
  int *local_1c;
  uint local_18;
  void *local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  uVar8 = 0;
  local_14 = (void *)0x0;
  FUN_005fb8ae();
  local_8 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      piVar5 = *(int **)(*(int *)(param_1 + 0x14) + uVar8 * 4);
      if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar5 * 4) + 4) & 0x10) == 0) {
        piVar5[7] = uVar8;
      }
      else {
        iVar3 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),0,0,0);
        piVar5[7] = iVar3;
        if (iVar3 == -1) goto LAB_005fc59a;
        local_8 = local_8 + 1;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(param_1 + 8));
    if (local_8 != 0) {
      FUN_005fbe30();
      local_14 = _malloc(local_8 << 2);
      if (local_14 == (void *)0x0) {
LAB_005fc59a:
        local_1c = (int *)0x8007000e;
        goto LAB_005fc410;
      }
      uVar8 = 0;
      local_8 = 0;
      if (*(int *)(param_1 + 8) != 0) {
        do {
          if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) +
                                 **(int **)(*(int *)(param_1 + 0x14) + uVar8 * 4) * 4) + 4) & 0x10)
              != 0) {
            *(uint *)((int)local_14 + local_8 * 4) = uVar8;
            local_8 = local_8 + 1;
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < *(uint *)(param_1 + 8));
      }
      FUN_005f7e20(FUN_005f7d7e,local_14,local_8,param_1);
      local_18 = 0;
      if (local_8 != 0) {
        do {
          piVar5 = (int *)((int)local_14 + local_18 * 4);
          piVar6 = *(int **)(*(int *)(param_1 + 0x14) + *piVar5 * 4);
          local_10 = 1;
          local_1c = piVar5;
          uVar8 = local_18;
          while (uVar8 = uVar8 + 1, uVar8 < local_8) {
            local_1c = local_1c + 1;
            piVar1 = *(int **)(*(int *)(param_1 + 0x14) + *local_1c * 4);
            if (((*piVar6 != *piVar1) || (piVar6[1] != piVar1[1])) || (piVar6[2] != piVar1[2]))
            break;
            local_10 = local_10 + 1;
          }
          iVar3 = FUN_005f752b(local_10 & 0xffffff | 0x10000000,0xffffffff,0xffffffff);
          if (iVar3 == -1) goto LAB_005fc59a;
          iVar3 = *(int *)(*(int *)(param_1 + 0x18) + iVar3 * 4);
          local_c = 0;
          local_20 = piVar5;
          if (local_10 != 0) {
            do {
              iVar7 = *(int *)(*(int *)(param_1 + 0x14) + *local_20 * 4);
              iVar2 = *(int *)(iVar7 + 0x1c);
              iVar7 = *(int *)(iVar7 + 0x2c);
              while (iVar7 != -1) {
                iVar7 = *(int *)(*(int *)(param_1 + 0x18) + iVar7 * 4);
                if (((*(int *)(iVar7 + 0x34) != 0) && (*(int *)(*(int *)(iVar7 + 0x34) + 4) == 0xc))
                   && (local_1c = (int *)FUN_005f7a42(), (int)local_1c < 0)) goto LAB_005fc410;
                iVar4 = FUN_005f7aa3();
                if (iVar4 == 0) break;
                uVar8 = 0;
                if (*(uint *)(iVar7 + 0xc) != 0) {
                  piVar6 = *(int **)(iVar7 + 0x10);
                  do {
                    if (iVar2 == *piVar6) break;
                    uVar8 = uVar8 + 1;
                    piVar6 = piVar6 + 1;
                  } while (uVar8 < *(uint *)(iVar7 + 0xc));
                }
                iVar2 = *(int *)(*(int *)(iVar7 + 8) + uVar8 * 4);
                iVar7 = *(int *)(*(int *)(*(int *)(param_1 + 0x14) + iVar2 * 4) + 0x2c);
              }
              if (*(int *)(iVar3 + 0x34) != 0) break;
              local_c = local_c + 1;
              local_20 = local_20 + 1;
            } while (local_c < local_10);
          }
          local_c = 0;
          if (local_10 != 0) {
            do {
              iVar7 = local_c * 4;
              local_c = local_c + 1;
              *(undefined4 *)(iVar7 + *(int *)(iVar3 + 8)) =
                   *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar5 * 4) + 0x1c);
              *(int *)(iVar7 + *(int *)(iVar3 + 0x10)) = *piVar5;
              piVar5 = piVar5 + 1;
            } while (local_c < local_10);
          }
          local_18 = local_18 + local_10;
        } while (local_18 < local_8);
      }
    }
  }
  local_1c = (int *)0x0;
LAB_005fc410:
  _free(local_14);
  return (int)local_1c;
}


// ==== 0x5fc5a6 FUN_005fc5a6

uint __fastcall FUN_005fc5a6(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  bool bVar4;
  bool bVar5;
  void *_Memory;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint local_10;
  uint local_8;
  
  bVar5 = false;
  FUN_005fb8ae();
  _Memory = _malloc(*(int *)(param_1 + 8) << 2);
  if (_Memory == (void *)0x0) {
    uVar6 = 0x8007000e;
  }
  else {
    uVar6 = 0;
    local_8 = 0;
    if (*(int *)(param_1 + 8) != 0) {
      do {
        piVar2 = *(int **)(*(int *)(param_1 + 0x14) + uVar6 * 4);
        piVar2[7] = uVar6;
        uVar9 = *(uint *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4) + 4);
        if (((char)uVar9 < '\0') && ((uVar9 & 0x200) == 0)) {
          *(uint *)((int)_Memory + local_8 * 4) = uVar6;
          local_8 = local_8 + 1;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(param_1 + 8));
    }
    FUN_005f7e20(FUN_005f7d34,_Memory,local_8,param_1);
    local_10 = 1;
    bVar4 = false;
    if (1 < local_8) {
      do {
        bVar5 = bVar4;
        piVar2 = (int *)(local_10 * 4 + (int)_Memory);
        piVar1 = (int *)(local_10 * 4 + -4 + (int)_Memory);
        iVar7 = FUN_005f7d34(*(undefined4 *)
                              (*(int *)(*(int *)(param_1 + 0x14) + *piVar1 * 4) + 0x1c),*piVar2,
                             param_1);
        if (iVar7 == 0) {
          **(undefined4 **)(*(int *)(param_1 + 0x14) + *piVar2 * 4) =
               *(undefined4 *)(param_1 + 0x4c);
          *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar2 * 4) + 0x1c) =
               *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar1 * 4) + 0x1c);
          bVar5 = true;
        }
        local_10 = local_10 + 1;
        bVar4 = bVar5;
      } while (local_10 < local_8);
      if (bVar5) {
        FUN_005fbe30();
      }
    }
    uVar6 = 0;
    uVar9 = 0;
    local_8 = 0;
    bVar4 = false;
    if (*(int *)(param_1 + 8) != 0) {
      do {
        piVar2 = *(int **)(*(int *)(param_1 + 0x14) + uVar6 * 4);
        piVar2[7] = uVar6;
        iVar7 = *piVar2;
        if ((*(int *)(param_1 + 0x4c) != iVar7) &&
           (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + iVar7 * 4) + 4) & 0x20) != 0 ||
            (*(int *)(param_1 + 0x40) != 0)))) {
          *(uint *)((int)_Memory + uVar9 * 4) = uVar6;
          uVar9 = uVar9 + 1;
        }
        uVar6 = uVar6 + 1;
        local_8 = uVar9;
      } while (uVar6 < *(uint *)(param_1 + 8));
    }
    FUN_005f7e20(FUN_005f7d7e,_Memory,local_8,param_1);
    local_10 = 1;
    if (1 < local_8) {
      do {
        iVar7 = *(int *)(local_10 * 4 + (int)_Memory);
        piVar2 = (int *)(local_10 * 4 + -4 + (int)_Memory);
        iVar8 = FUN_005f7d7e(*(undefined4 *)
                              (*(int *)(*(int *)(param_1 + 0x14) + *piVar2 * 4) + 0x1c),iVar7,
                             param_1);
        if (iVar8 == 0) {
          puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x14) + iVar7 * 4);
          *puVar3 = *(undefined4 *)(param_1 + 0x4c);
          iVar7 = *(int *)(*(int *)(*(int *)(param_1 + 0x14) + *piVar2 * 4) + 0x1c);
          puVar3[7] = iVar7;
          iVar7 = *(int *)(*(int *)(param_1 + 0x14) + iVar7 * 4);
          if (*(uint *)(iVar7 + 0x44) < (uint)puVar3[0x11]) {
            *(undefined4 *)(iVar7 + 0x44) = puVar3[0x11];
            *(undefined4 *)(iVar7 + 0x48) = puVar3[0x12];
          }
          if ((*(uint *)(iVar7 + 0x18) & 0xe000000) < (puVar3[6] & 0xe000000)) {
            uVar6 = *(uint *)(iVar7 + 0x18) & 0xf1ffffff;
            *(uint *)(iVar7 + 0x18) = uVar6;
            *(uint *)(iVar7 + 0x18) = puVar3[6] & 0xe000000 | uVar6;
          }
          bVar4 = true;
        }
        local_10 = local_10 + 1;
      } while (local_10 < local_8);
      if (bVar4) {
        FUN_005fbe30();
        bVar5 = true;
      }
    }
    _free(_Memory);
    uVar6 = (uint)!bVar5;
  }
  return uVar6;
}


// ==== 0x5fc7c0 FUN_005fc7c0

undefined4 __fastcall FUN_005fc7c0(int param_1)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  int iVar8;
  int extraout_ECX;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  bVar7 = false;
  FUN_005fbe17();
  local_24 = 0;
  iVar8 = extraout_ECX;
  if (*(int *)(extraout_ECX + 0xc) != 0) {
    do {
      puVar1 = *(uint **)(*(int *)(iVar8 + 0x18) + local_24 * 4);
      iVar8 = FUN_005f7b0f();
      if ((iVar8 != 0) || (iVar8 = FUN_005f7b21(), iVar8 != 0)) {
        uVar10 = *puVar1 & 0xffffff;
        iVar8 = FUN_005f7b21();
        uVar9 = -(uint)(iVar8 != 0) & uVar10;
        iVar8 = FUN_005f7b67();
        local_8 = 1;
        if (1 < uVar10) {
          local_1c = uVar9 * 4;
          iVar11 = 4;
          local_10 = uVar10;
          do {
            local_1c = local_1c + 4;
            iVar2 = *(int *)(param_1 + 0x14);
            piVar3 = *(int **)(iVar2 + *(int *)(iVar11 + puVar1[4]) * 4);
            if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar3 * 4) + 4) & 0x10) == 0) &&
               (local_c = 0, iVar11 != 0)) {
              local_14 = uVar9 << 2;
              do {
                iVar4 = *(int *)(local_c * 4 + puVar1[4]);
                if ((iVar4 != -1) &&
                   ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + **(int **)(iVar2 + iVar4 * 4) * 4
                                       ) + 4) & 0x10) == 0)) {
                  uVar5 = puVar1[2];
                  iVar4 = *(int *)(*(int *)(iVar2 + *(int *)(iVar11 + uVar5) * 4) + 0x1c);
                  iVar6 = *(int *)(*(int *)(iVar2 + *(int *)(uVar5 + local_c * 4) * 4) + 0x1c);
                  if (((iVar4 == iVar6) &&
                      (*(int *)(*(int *)(iVar2 + *(int *)(local_1c + uVar5) * 4) + 0x1c) ==
                       *(int *)(*(int *)(iVar2 + *(int *)(local_14 + uVar5) * 4) + 0x1c))) ||
                     (((iVar8 != 0 &&
                       (iVar4 == *(int *)(*(int *)(iVar2 + *(int *)(local_14 + uVar5) * 4) + 0x1c)))
                      && (*(int *)(*(int *)(iVar2 + *(int *)(local_1c + uVar5) * 4) + 0x1c) == iVar6
                         )))) {
                    piVar3[7] = *(int *)(*(int *)(iVar2 + *(int *)(puVar1[4] + local_c * 4) * 4) +
                                        0x1c);
                    *(undefined4 *)(iVar11 + puVar1[4]) = 0xffffffff;
                    local_10 = local_10 - 1;
                    break;
                  }
                }
                local_c = local_c + 1;
                local_14 = local_14 + 4;
              } while (local_c < local_8);
            }
            local_8 = local_8 + 1;
            iVar11 = iVar11 + 4;
          } while (local_8 < uVar10);
          if (local_10 < uVar10) {
            iVar8 = 0;
            local_8 = 0;
            if (uVar10 != 0) {
              local_1c = uVar9 << 2;
              local_18 = local_1c;
              do {
                iVar11 = *(int *)(puVar1[4] + local_8 * 4);
                if (iVar11 != -1) {
                  *(int *)(iVar8 + puVar1[4]) = iVar11;
                  *(undefined4 *)(iVar8 + puVar1[2]) = *(undefined4 *)(puVar1[2] + local_8 * 4);
                  if (uVar9 != 0) {
                    *(undefined4 *)(local_1c + puVar1[2]) = *(undefined4 *)(local_18 + puVar1[2]);
                  }
                  iVar8 = iVar8 + 4;
                  local_1c = local_1c + 4;
                }
                local_8 = local_8 + 1;
                local_18 = local_18 + 4;
              } while (local_8 < uVar10);
            }
            if ((uVar9 != 0) && (local_10 != 0)) {
              iVar8 = local_10 << 2;
              iVar11 = uVar9 << 2;
              local_20 = local_10;
              do {
                *(undefined4 *)(iVar8 + puVar1[2]) = *(undefined4 *)(iVar11 + puVar1[2]);
                iVar11 = iVar11 + 4;
                iVar8 = iVar8 + 4;
                local_20 = local_20 - 1;
              } while (local_20 != 0);
            }
            *puVar1 = *puVar1 ^ (*puVar1 ^ local_10) & 0xffffff;
            uVar10 = local_10 * 2;
            if (uVar9 == 0) {
              uVar10 = local_10;
            }
            puVar1[1] = uVar10;
            puVar1[3] = local_10;
            bVar7 = true;
          }
        }
      }
      local_24 = local_24 + 1;
      iVar8 = param_1;
    } while (local_24 < *(uint *)(param_1 + 0xc));
    if (bVar7) {
      FUN_005fbe30();
      return 0;
    }
  }
  return 1;
}


// ==== 0x5fca3e FUN_005fca3e

undefined4 __fastcall FUN_005fca3e(int param_1)

{
  uint *puVar1;
  int *piVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  undefined4 *puVar14;
  int *piVar15;
  undefined4 *puVar16;
  bool bVar17;
  int *local_28;
  uint local_20;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  bVar8 = false;
  FUN_005fbe17();
  local_18 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      puVar3 = *(uint **)(*(int *)(param_1 + 0x18) + local_18 * 4);
      iVar9 = FUN_005f7a96();
      if ((iVar9 == 0) && (local_20 = 0, local_18 != 0)) {
LAB_005fca8a:
        puVar4 = *(uint **)(*(int *)(param_1 + 0x18) + local_20 * 4);
        if (((*puVar4 ^ *puVar3) & 0xff000000) != 0) {
LAB_005fd4fc:
          local_20 = local_20 + 1;
          if (local_18 <= local_20) goto LAB_005fd41f;
          goto LAB_005fca8a;
        }
        iVar9 = FUN_005f7aa3();
        if (iVar9 == 0) {
          iVar9 = FUN_005f7b0f();
          if (iVar9 == 0) {
            iVar9 = FUN_005f7b21();
            if (iVar9 != 0) {
              local_14 = 0;
              if (puVar3[3] != 0) {
                while( true ) {
                  iVar9 = *(int *)(param_1 + 0x14);
                  iVar5 = **(int **)(iVar9 + *(int *)(local_14 * 4 + puVar3[4]) * 4);
                  if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + iVar5 * 4) + 4) & 0x10) != 0)
                  break;
                  iVar12 = *(int *)(iVar9 + *(int *)(local_14 * 4 + puVar3[2]) * 4);
                  local_c = 0;
                  uVar11 = puVar4[3];
                  iVar9 = *(int *)(iVar9 + *(int *)(puVar3[2] + (puVar3[3] + local_14) * 4) * 4);
                  if (uVar11 != 0) {
                    do {
                      iVar10 = *(int *)(param_1 + 0x14);
                      if (iVar5 == **(int **)(iVar10 + *(int *)(puVar4[4] + local_c * 4) * 4)) {
                        iVar7 = *(int *)(iVar10 + *(int *)(puVar4[2] + (uVar11 + local_c) * 4) * 4);
                        iVar6 = *(int *)(iVar12 + 0x1c);
                        iVar10 = *(int *)(*(int *)(iVar10 + *(int *)(puVar4[2] + local_c * 4) * 4) +
                                         0x1c);
                        if (((iVar6 == iVar10) && (*(int *)(iVar9 + 0x1c) == *(int *)(iVar7 + 0x1c))
                            ) || ((iVar6 == *(int *)(iVar7 + 0x1c) &&
                                  ((*(int *)(iVar9 + 0x1c) == iVar10 &&
                                   (iVar10 = FUN_005f7b67(), iVar10 != 0)))))) break;
                      }
                      local_c = local_c + 1;
                      uVar11 = puVar4[3];
                    } while (local_c < uVar11);
                  }
                  if ((local_c == puVar4[3]) || (local_14 = local_14 + 1, puVar3[3] <= local_14))
                  break;
                }
              }
              goto LAB_005fcc5b;
            }
            iVar9 = FUN_005f7b33();
            if (iVar9 == 0) goto LAB_005fcd75;
            local_10 = 0;
            if (puVar3[3] != 0) {
              iVar9 = *(int *)(param_1 + 0x14);
              local_28 = (int *)(puVar3[3] << 2);
              do {
                iVar5 = **(int **)(iVar9 + *(int *)(puVar3[4] + local_10 * 4) * 4);
                if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + iVar5 * 4) + 4) & 0x10) != 0)
                break;
                uVar11 = puVar3[2];
                local_c = 0;
                uVar13 = puVar4[3];
                if (uVar13 != 0) {
                  local_14 = uVar13 << 2;
                  do {
                    if ((((iVar5 == **(int **)(iVar9 + *(int *)(puVar4[4] + local_c * 4) * 4)) &&
                         (*(int *)(*(int *)(iVar9 + *(int *)(uVar11 + local_10 * 4) * 4) + 0x1c) ==
                          *(int *)(*(int *)(iVar9 + *(int *)(puVar4[2] + local_c * 4) * 4) + 0x1c)))
                        && (*(int *)(*(int *)(iVar9 + *(int *)(uVar11 + (int)local_28) * 4) + 0x1c)
                            == *(int *)(*(int *)(iVar9 + *(int *)(puVar4[2] + local_14) * 4) + 0x1c)
                           )) && (*(int *)(*(int *)(iVar9 + *(int *)(uVar11 + (local_10 +
                                                                              puVar3[3] * 2) * 4) *
                                                            4) + 0x1c) ==
                                  *(int *)(*(int *)(iVar9 + *(int *)(puVar4[2] +
                                                                    (local_c + uVar13 * 2) * 4) * 4)
                                          + 0x1c))) break;
                    local_c = local_c + 1;
                    local_14 = local_14 + 4;
                  } while (local_c < uVar13);
                }
                if (local_c == uVar13) break;
                local_28 = (int *)((int)local_28 + 4);
                local_10 = local_10 + 1;
              } while (local_10 < puVar3[3]);
            }
            bVar17 = local_10 < puVar3[3];
          }
          else {
            local_10 = 0;
            local_14 = local_10;
            if (puVar3[3] != 0) {
              iVar9 = *(int *)(param_1 + 0x14);
              while( true ) {
                iVar5 = **(int **)(iVar9 + *(int *)(puVar3[4] + local_10 * 4) * 4);
                local_14 = local_10;
                if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + iVar5 * 4) + 4) & 0x10) != 0)
                break;
                local_14 = 0;
                if (puVar4[3] != 0) {
                  do {
                    if ((iVar5 == **(int **)(iVar9 + *(int *)(puVar4[4] + local_14 * 4) * 4)) &&
                       (*(int *)(*(int *)(iVar9 + *(int *)(local_10 * 4 + puVar3[2]) * 4) + 0x1c) ==
                        *(int *)(*(int *)(iVar9 + *(int *)(local_14 * 4 + puVar4[2]) * 4) + 0x1c)))
                    break;
                    local_14 = local_14 + 1;
                  } while (local_14 < puVar4[3]);
                }
                bVar17 = local_14 == puVar4[3];
                local_14 = local_10;
                if ((bVar17) ||
                   (local_14 = local_10 + 1, local_10 = local_14, puVar3[3] <= local_14)) break;
              }
            }
LAB_005fcc5b:
            bVar17 = local_14 < puVar3[3];
          }
          if (bVar17) goto LAB_005fd4fc;
        }
LAB_005fcd75:
        iVar9 = FUN_005f7b0f();
        if (iVar9 != 0) {
          bVar17 = puVar3[3] == 0;
          local_10 = 0;
          local_28 = (int *)0x0;
          if (puVar3[3] != 0) {
            do {
              iVar9 = *(int *)(param_1 + 0x14);
              piVar15 = *(int **)(iVar9 + *(int *)(puVar3[4] + (int)local_28 * 4) * 4);
              if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar15 * 4) + 4) & 0x10) == 0)
                 && (local_14 = 0, puVar4[3] != 0)) {
                do {
                  if ((*piVar15 == **(int **)(iVar9 + *(int *)(local_14 * 4 + puVar4[4]) * 4)) &&
                     (piVar2 = (int *)(iVar9 + *(int *)(local_14 * 4 + puVar4[2]) * 4),
                     iVar9 = *(int *)(param_1 + 0x14),
                     *(int *)(*(int *)(iVar9 + *(int *)(puVar3[2] + (int)local_28 * 4) * 4) + 0x1c)
                     == *(int *)(*piVar2 + 0x1c))) {
                    iVar9 = *(int *)(puVar4[4] + local_14 * 4);
                    piVar15[7] = iVar9;
                    iVar9 = *(int *)(*(int *)(param_1 + 0x14) + iVar9 * 4);
                    uVar11 = *(uint *)(iVar9 + 0x18);
                    if ((uVar11 & 0xe000000) < (piVar15[6] & 0xe000000U)) {
                      *(uint *)(iVar9 + 0x18) = uVar11 & 0xf1ffffff;
                      puVar1 = (uint *)(*(int *)(*(int *)(param_1 + 0x14) + piVar15[7] * 4) + 0x18);
                      *puVar1 = *puVar1 | piVar15[6] & 0xe000000U;
                    }
                    break;
                  }
                  local_14 = local_14 + 1;
                } while (local_14 < puVar4[3]);
              }
              if (piVar15[7] == *(int *)(puVar3[4] + (int)local_28 * 4)) {
                *(undefined4 *)(local_10 * 4 + puVar3[2]) =
                     *(undefined4 *)(puVar3[2] + (int)local_28 * 4);
                *(undefined4 *)(local_10 * 4 + puVar3[4]) =
                     *(undefined4 *)(puVar3[4] + (int)local_28 * 4);
                local_10 = local_10 + 1;
              }
              local_28 = (int *)((int)local_28 + 1);
            } while (local_28 < puVar3[3]);
            bVar17 = local_10 == puVar3[3];
          }
          if (!bVar17) {
            if (local_10 == 0) {
              uVar11 = 0;
            }
            else {
              uVar11 = (*puVar3 ^ local_10) & 0xffffff ^ *puVar3;
            }
            *puVar3 = uVar11;
            puVar3[3] = local_10;
            puVar3[1] = local_10;
LAB_005fd095:
            bVar8 = true;
          }
          goto LAB_005fd4fc;
        }
        iVar9 = FUN_005f7b21();
        if (iVar9 != 0) {
          local_c = 0;
          local_14 = 0;
          if (puVar3[3] != 0) {
            do {
              iVar9 = *(int *)(param_1 + 0x14);
              piVar15 = *(int **)(iVar9 + *(int *)(puVar3[4] + local_14 * 4) * 4);
              if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar15 * 4) + 4) & 0x10) == 0) {
                iVar5 = *(int *)(iVar9 + *(int *)(puVar3[2] + local_14 * 4) * 4);
                local_10 = 0;
                iVar9 = *(int *)(iVar9 + *(int *)(puVar3[2] + (puVar3[3] + local_14) * 4) * 4);
                if (puVar4[3] != 0) {
                  do {
                    iVar12 = *(int *)(param_1 + 0x14);
                    if (*piVar15 == **(int **)(iVar12 + *(int *)(puVar4[4] + local_10 * 4) * 4)) {
                      iVar10 = *(int *)(iVar12 + *(int *)(puVar4[2] + (local_10 + puVar4[3]) * 4) *
                                                 4);
                      iVar12 = *(int *)(*(int *)(iVar12 + *(int *)(puVar4[2] + local_10 * 4) * 4) +
                                       0x1c);
                      iVar7 = *(int *)(iVar5 + 0x1c);
                      if (((iVar7 == iVar12) && (*(int *)(iVar9 + 0x1c) == *(int *)(iVar10 + 0x1c)))
                         || ((iVar7 == *(int *)(iVar10 + 0x1c) &&
                             ((*(int *)(iVar9 + 0x1c) == iVar12 &&
                              (iVar12 = FUN_005f7b67(), iVar12 != 0)))))) {
                        iVar9 = *(int *)(puVar4[4] + local_10 * 4);
                        piVar15[7] = iVar9;
                        iVar9 = *(int *)(*(int *)(param_1 + 0x14) + iVar9 * 4);
                        uVar11 = *(uint *)(iVar9 + 0x18);
                        if ((uVar11 & 0xe000000) < (piVar15[6] & 0xe000000U)) {
                          *(uint *)(iVar9 + 0x18) = uVar11 & 0xf1ffffff;
                          puVar1 = (uint *)(*(int *)(*(int *)(param_1 + 0x14) + piVar15[7] * 4) +
                                           0x18);
                          *puVar1 = *puVar1 | piVar15[6] & 0xe000000U;
                        }
                        break;
                      }
                    }
                    local_10 = local_10 + 1;
                  } while (local_10 < puVar4[3]);
                }
              }
              iVar9 = *(int *)(puVar3[4] + local_14 * 4);
              if (piVar15[7] == iVar9) {
                *(int *)(puVar3[4] + local_c * 4) = iVar9;
                *(undefined4 *)(puVar3[2] + local_c * 4) = *(undefined4 *)(puVar3[2] + local_14 * 4)
                ;
                iVar9 = puVar3[3] + local_c;
                local_c = local_c + 1;
                *(undefined4 *)(puVar3[2] + iVar9 * 4) =
                     *(undefined4 *)(puVar3[2] + (local_14 + puVar3[3]) * 4);
              }
              local_14 = local_14 + 1;
            } while (local_14 < puVar3[3]);
          }
          if (local_c != puVar3[3]) {
            uVar11 = 0;
            if (local_c != 0) {
              uVar11 = (*puVar3 ^ local_c) & 0xffffff ^ *puVar3;
            }
            *puVar3 = uVar11;
            puVar14 = (undefined4 *)(puVar3[2] + puVar3[3] * 4);
            puVar16 = (undefined4 *)(puVar3[2] + local_c * 4);
            for (uVar11 = local_c & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
              *puVar16 = *puVar14;
              puVar14 = puVar14 + 1;
              puVar16 = puVar16 + 1;
            }
            for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
              *(undefined1 *)puVar16 = *(undefined1 *)puVar14;
              puVar14 = (undefined4 *)((int)puVar14 + 1);
              puVar16 = (undefined4 *)((int)puVar16 + 1);
            }
            puVar3[3] = local_c;
            local_c = local_c * 2;
LAB_005fd092:
            puVar3[1] = local_c;
            goto LAB_005fd095;
          }
          goto LAB_005fd4fc;
        }
        iVar9 = FUN_005f7b33();
        if (iVar9 != 0) {
          uVar11 = 0;
          local_c = 0;
          if (puVar3[3] != 0) {
            do {
              iVar9 = *(int *)(param_1 + 0x14);
              piVar15 = *(int **)(iVar9 + *(int *)(puVar3[4] + local_c * 4) * 4);
              if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar15 * 4) + 4) & 0x10) == 0) {
                local_14 = 0;
                if (puVar4[3] != 0) {
                  local_28 = (int *)(puVar4[3] << 2);
                  do {
                    if ((((*piVar15 == **(int **)(iVar9 + *(int *)(puVar4[4] + local_14 * 4) * 4))
                         && (*(int *)(*(int *)(iVar9 + *(int *)(puVar3[2] + local_c * 4) * 4) + 0x1c
                                     ) ==
                             *(int *)(*(int *)(iVar9 + *(int *)(puVar4[2] + local_14 * 4) * 4) +
                                     0x1c))) &&
                        (*(int *)(*(int *)(iVar9 + *(int *)(puVar3[2] + (local_c + puVar3[3]) * 4) *
                                                   4) + 0x1c) ==
                         *(int *)(*(int *)(iVar9 + *(int *)(puVar4[2] + (int)local_28) * 4) + 0x1c))
                        ) && (*(int *)(*(int *)(iVar9 + *(int *)(puVar3[2] +
                                                                (local_c + puVar3[3] * 2) * 4) * 4)
                                      + 0x1c) ==
                              *(int *)(*(int *)(iVar9 + *(int *)(puVar4[2] +
                                                                (local_14 + puVar4[3] * 2) * 4) * 4)
                                      + 0x1c))) {
                      iVar9 = *(int *)(puVar4[4] + local_14 * 4);
                      piVar15[7] = iVar9;
                      iVar9 = *(int *)(*(int *)(param_1 + 0x14) + iVar9 * 4);
                      uVar13 = *(uint *)(iVar9 + 0x18);
                      if ((uVar13 & 0xe000000) < (piVar15[6] & 0xe000000U)) {
                        *(uint *)(iVar9 + 0x18) = uVar13 & 0xf1ffffff;
                        puVar1 = (uint *)(*(int *)(*(int *)(param_1 + 0x14) + piVar15[7] * 4) + 0x18
                                         );
                        *puVar1 = *puVar1 | piVar15[6] & 0xe000000U;
                      }
                      break;
                    }
                    local_14 = local_14 + 1;
                    local_28 = (int *)((int)local_28 + 4);
                  } while (local_14 < puVar4[3]);
                }
              }
              iVar9 = *(int *)(puVar3[4] + local_c * 4);
              if (piVar15[7] == iVar9) {
                *(int *)(puVar3[4] + uVar11 * 4) = iVar9;
                *(undefined4 *)(puVar3[2] + uVar11 * 4) = *(undefined4 *)(puVar3[2] + local_c * 4);
                *(undefined4 *)(puVar3[2] + (puVar3[3] + uVar11) * 4) =
                     *(undefined4 *)(puVar3[2] + (local_c + puVar3[3]) * 4);
                *(undefined4 *)(puVar3[2] + (puVar3[3] * 2 + uVar11) * 4) =
                     *(undefined4 *)(puVar3[2] + (local_c + puVar3[3] * 2) * 4);
                uVar11 = uVar11 + 1;
              }
              local_c = local_c + 1;
            } while (local_c < puVar3[3]);
          }
          if (uVar11 != puVar3[3]) {
            if (uVar11 == 0) {
              uVar13 = 0;
            }
            else {
              uVar13 = (*puVar3 ^ uVar11) & 0xffffff ^ *puVar3;
            }
            *puVar3 = uVar13;
            puVar14 = (undefined4 *)(puVar3[2] + puVar3[3] * 4);
            puVar16 = (undefined4 *)(puVar3[2] + uVar11 * 4);
            for (uVar13 = uVar11 & 0x3fffffff; uVar13 != 0; uVar13 = uVar13 - 1) {
              *puVar16 = *puVar14;
              puVar14 = puVar14 + 1;
              puVar16 = puVar16 + 1;
            }
            for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
              *(undefined1 *)puVar16 = *(undefined1 *)puVar14;
              puVar14 = (undefined4 *)((int)puVar14 + 1);
              puVar16 = (undefined4 *)((int)puVar16 + 1);
            }
            puVar14 = (undefined4 *)(puVar3[2] + puVar3[3] * 8);
            puVar16 = (undefined4 *)(puVar3[2] + uVar11 * 8);
            for (uVar13 = uVar11 & 0x3fffffff; uVar13 != 0; uVar13 = uVar13 - 1) {
              *puVar16 = *puVar14;
              puVar14 = puVar14 + 1;
              puVar16 = puVar16 + 1;
            }
            for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
              *(undefined1 *)puVar16 = *(undefined1 *)puVar14;
              puVar14 = (undefined4 *)((int)puVar14 + 1);
              puVar16 = (undefined4 *)((int)puVar16 + 1);
            }
            puVar3[3] = uVar11;
            local_c = uVar11 * 3;
            goto LAB_005fd092;
          }
          goto LAB_005fd4fc;
        }
        iVar9 = FUN_005f7ac7();
        if (iVar9 != 0) {
          if (*puVar3 == *puVar4) {
            piVar15 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)puVar3[4] * 4);
            if ((*piVar15 == **(int **)(*(int *)(param_1 + 0x14) + *(int *)puVar4[4] * 4)) &&
               ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar15 * 4) + 4) & 0x10) == 0)) {
              local_28 = (int *)0x0;
              puVar14 = _malloc(puVar4[1] << 2);
              if (puVar14 == (undefined4 *)0x0) {
                return 0x8007000e;
              }
              local_10 = 0;
              puVar16 = puVar14;
              for (uVar11 = puVar4[1] & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
                *puVar16 = 0;
                puVar16 = puVar16 + 1;
              }
              for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                *(undefined1 *)puVar16 = 0;
                puVar16 = (undefined4 *)((int)puVar16 + 1);
              }
              if (puVar3[1] != 0) {
                do {
                  local_14 = 0;
                  if (puVar4[1] != 0) {
                    do {
                      if ((puVar14[local_14] == 0) &&
                         (*(int *)(*(int *)(*(int *)(param_1 + 0x14) +
                                           *(int *)(puVar3[2] + local_10 * 4) * 4) + 0x1c) ==
                          *(int *)(*(int *)(*(int *)(param_1 + 0x14) +
                                           *(int *)(local_14 * 4 + puVar4[2]) * 4) + 0x1c))) {
                        local_28 = (int *)((int)local_28 + 1);
                        puVar14[local_14] = 1;
                      }
                      local_14 = local_14 + 1;
                    } while (local_14 < puVar4[1]);
                  }
                  local_10 = local_10 + 1;
                } while (local_10 < puVar3[1]);
              }
              _free(puVar14);
              if (puVar3[1] <= local_28) {
                iVar9 = *(int *)puVar4[4];
                piVar15[7] = iVar9;
                iVar9 = *(int *)(*(int *)(param_1 + 0x14) + iVar9 * 4);
                uVar11 = *(uint *)(iVar9 + 0x18);
                if ((uVar11 & 0xe000000) < (piVar15[6] & 0xe000000U)) {
                  *(uint *)(iVar9 + 0x18) = uVar11 & 0xf1ffffff;
                  puVar4 = (uint *)(*(int *)(*(int *)(param_1 + 0x14) + piVar15[7] * 4) + 0x18);
                  *puVar4 = *puVar4 | piVar15[6] & 0xe000000U;
                }
                goto LAB_005fd415;
              }
            }
          }
          goto LAB_005fd4fc;
        }
        if (((*puVar3 != *puVar4) || (puVar3[1] != puVar4[1])) || (puVar3[3] != puVar4[3]))
        goto LAB_005fd4fc;
        local_14 = 0;
        if (puVar3[3] != 0) {
          piVar15 = (int *)puVar4[4];
          iVar9 = puVar3[4] - (int)piVar15;
          do {
            iVar5 = **(int **)(*(int *)(param_1 + 0x14) + *(int *)(iVar9 + (int)piVar15) * 4);
            if ((iVar5 != **(int **)(*(int *)(param_1 + 0x14) + *piVar15 * 4)) ||
               ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + iVar5 * 4) + 4) & 0x10) != 0)) break;
            local_14 = local_14 + 1;
            piVar15 = piVar15 + 1;
          } while (local_14 < puVar3[3]);
        }
        if (local_14 < puVar3[3]) goto LAB_005fd4fc;
        local_14 = 0;
        if (puVar3[1] != 0) {
          local_28 = (int *)puVar3[2];
          iVar9 = puVar4[2] - (int)local_28;
          do {
            if (*(int *)(*(int *)(*(int *)(param_1 + 0x14) + *local_28 * 4) + 0x1c) !=
                *(int *)(*(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar9 + (int)local_28) * 4) +
                        0x1c)) break;
            local_14 = local_14 + 1;
            local_28 = local_28 + 1;
          } while (local_14 < puVar3[1]);
        }
        if (local_14 < puVar3[1]) goto LAB_005fd4fc;
        local_20 = 0;
        if (puVar3[3] != 0) {
          do {
            iVar9 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)(local_20 * 4 + puVar3[4]) * 4);
            iVar5 = *(int *)(*(int *)(*(int *)(param_1 + 0x14) +
                                     *(int *)(local_20 * 4 + puVar4[4]) * 4) + 0x1c);
            *(int *)(iVar9 + 0x1c) = iVar5;
            iVar5 = *(int *)(*(int *)(param_1 + 0x14) + iVar5 * 4);
            uVar11 = *(uint *)(iVar5 + 0x18);
            if ((uVar11 & 0xe000000) < (*(uint *)(iVar9 + 0x18) & 0xe000000)) {
              *(uint *)(iVar5 + 0x18) = uVar11 & 0xf1ffffff;
              puVar1 = (uint *)(*(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar9 + 0x1c) * 4) +
                               0x18);
              *puVar1 = *puVar1 | *(uint *)(iVar9 + 0x18) & 0xe000000;
            }
            local_20 = local_20 + 1;
          } while (local_20 < puVar3[3]);
        }
LAB_005fd415:
        *puVar3 = 0;
        bVar8 = true;
      }
LAB_005fd41f:
      local_18 = local_18 + 1;
    } while (local_18 < *(uint *)(param_1 + 0xc));
    if (bVar8) {
      FUN_005fbe30();
      FUN_005fc5a6();
      return 0;
    }
  }
  return 1;
}


// ==== 0x5fd5b7 FUN_005fd5b7

uint __fastcall FUN_005fd5b7(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  double *pdVar3;
  double dVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  int *piVar12;
  uint uVar13;
  int *piVar14;
  double *pdVar15;
  double *pdVar16;
  undefined1 local_70 [8];
  int *local_68 [2];
  int local_60 [2];
  double *local_58;
  int local_54;
  double *local_50;
  double *local_4c;
  double *local_48;
  int *local_44;
  int *local_40;
  int *local_3c;
  int local_38;
  double *local_34;
  int *local_30;
  double *local_2c;
  double *local_28;
  double *local_24;
  double *local_20;
  double *local_1c;
  double *local_18;
  double *local_14;
  uint *local_10;
  uint *local_c;
  int local_8;
  
  local_38 = -1;
  local_18 = (double *)0x0;
  local_1c = (double *)0x0;
  local_8 = 0;
  FUN_005fb8ae();
  local_24 = (double *)0x0;
  if (*(int *)(param_1 + 0xc) != 0) {
LAB_005fd5e2:
    puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + (int)local_24 * 4);
    if ((puVar1[3] != 0) &&
       ((*(byte *)(*(int *)(*(int *)(param_1 + 0x14) + *(int *)puVar1[4] * 4) + 0x18) & 0x40) == 0))
    {
      if ((((*puVar1 & 0xff000000) == 0x24000000) || ((*puVar1 & 0xff000000) == 0x25000000)) &&
         (local_2c = (double *)0x0, puVar1[3] != 0)) {
        do {
          local_68[0] = (int *)(puVar1[2] + (int)local_2c * 4);
          local_c = (uint *)0x0;
          local_68[1] = (int *)(puVar1[2] + (puVar1[3] + (int)local_2c) * 4);
          local_60[0] = *(int *)(*(int *)(param_1 + 0x14) + *local_68[0] * 4);
          local_60[1] = *(undefined4 *)(*(int *)(param_1 + 0x14) + *local_68[1] * 4);
          do {
            local_10 = (uint *)(1 - (int)local_c);
            if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *(int *)local_60[(int)local_c] * 4) +
                          4) & 2) != 0) {
              local_3c = *(int **)(local_60[(int)local_c] + 0x2c);
              puVar2 = *(uint **)(*(int *)(param_1 + 0x18) + (int)local_3c * 4);
              local_28 = (double *)(*puVar1 & 0xff000000);
              if (local_28 == (double *)(*puVar2 & 0xff000000)) {
                local_14 = (double *)0x0;
                if (puVar2[3] != 0) {
                  piVar12 = (int *)puVar2[4];
                  do {
                    if (*piVar12 == *local_68[(int)local_c]) break;
                    local_14 = (double *)((int)local_14 + 1);
                    piVar12 = piVar12 + 1;
                  } while (local_14 < (double *)puVar2[3]);
                }
                local_20 = local_14;
                if (local_14 < (double *)puVar2[1]) {
                  uVar13 = puVar2[2];
                  local_44 = (int *)(uVar13 + (int)local_14 * 4);
                  local_40 = (int *)(puVar2[3] * 4);
                  local_30 = local_44;
                  do {
                    local_34 = *(double **)(*(int *)(param_1 + 0x14) + *local_30 * 4);
                    if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *(int *)local_34 * 4) + 4) &
                         0x80) != 0) && (*(int *)((int)local_34 + 4) == -1)) {
                      if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) +
                                              *(int *)local_60[(int)local_10] * 4) + 4) & 0x80) == 0
                          ) || (*(int *)(local_60[(int)local_10] + 4) != -1)) {
                        if ((*(int *)(local_60[(int)local_c] + 0x40) != 1) ||
                           ((*(int **)(local_60[(int)local_10] + 0x2c) != (int *)0xffffffff &&
                            (local_3c <= *(int **)(local_60[(int)local_10] + 0x2c)))))
                        goto LAB_005fd75e;
                        local_44 = (int *)*local_68[(int)local_10];
                        *local_68[(int)local_10] = *(int *)(uVar13 + (int)local_20 * 4);
                        *(int **)((int)local_20 * 4 + puVar2[2]) = local_44;
                        iVar6 = local_60[(int)local_c];
                        *(undefined4 *)(iVar6 + 0x44) = 0;
                        *(undefined4 *)(iVar6 + 0x48) = 0;
                      }
                      else {
                        dVar4 = 0.0;
                        if (local_28 == (double *)0x24000000) {
                          dVar4 = *(double *)
                                   (*(int *)(*(int *)(param_1 + 0x14) +
                                            *(int *)(uVar13 + (int)local_20 * 4) * 4) + 0x10) +
                                  *(double *)(local_60[(int)local_10] + 0x10);
                        }
                        else if (local_28 == (double *)0x25000000) {
                          dVar4 = *(double *)
                                   (*(int *)(*(int *)(param_1 + 0x14) +
                                            *(int *)(uVar13 + (int)local_20 * 4) * 4) + 0x10) *
                                  *(double *)(local_60[(int)local_10] + 0x10);
                        }
                        if (local_14 < local_20) {
                          iVar6 = *local_44;
                        }
                        else {
                          iVar6 = *(int *)(uVar13 + (puVar2[3] + (int)local_14) * 4);
                        }
                        *local_68[(int)local_c] = iVar6;
                        iVar6 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x50),0,0,dVar4);
                        *local_68[(int)local_10] = iVar6;
                      }
                      local_8 = 1;
                      break;
                    }
LAB_005fd75e:
                    local_20 = (double *)((int)local_20 + puVar2[3]);
                    local_30 = local_30 + puVar2[3];
                  } while (local_20 < (double *)puVar2[1]);
                }
                if (((*(int *)(local_60[(int)local_c] + 0x40) == 1) &&
                    (local_28 = (double *)((int)local_14 * 4),
                    *(int *)(puVar2[2] + (int)local_14 * 4) !=
                    *(int *)(puVar2[2] + (puVar2[3] + (int)local_14) * 4))) &&
                   ((*(uint *)(local_60[(int)local_10] + 0x2c) == 0xffffffff ||
                    (*(uint *)(local_60[(int)local_10] + 0x2c) <
                     *(uint *)(local_60[(int)local_c] + 0x2c))))) {
                  local_20 = (double *)local_68[(int)local_10];
                  local_34 = (double *)0xffffffff;
                  FUN_005f9c74(*(undefined4 *)local_20,&local_34,local_70);
                  local_48 = local_34;
                  local_4c = local_34;
                  local_50 = local_34;
                  iVar6 = FUN_005f9c74(*local_68[(int)local_c],&local_48,local_70);
                  local_10 = (uint *)(uint)(-1 < iVar6);
                  iVar6 = FUN_005f9c74(*(undefined4 *)((int)local_28 + puVar2[2]),&local_4c,local_70
                                      );
                  local_44 = (int *)(uint)(-1 < iVar6);
                  iVar6 = FUN_005f9c74(*(undefined4 *)(puVar2[2] + (puVar2[3] + (int)local_14) * 4),
                                       &local_50,local_70);
                  local_40 = (int *)(uint)(-1 < iVar6);
                  if (((local_10 == (uint *)0x0) && (local_44 != (int *)0x0)) ||
                     (*(int *)local_20 == *(int *)((int)local_28 + puVar2[2]))) {
                    local_30 = *(int **)local_20;
                    piVar12 = *(int **)(puVar2[2] + (puVar2[3] + (int)local_14) * 4);
                    if (local_30 != piVar12) {
                      *(int **)local_20 = piVar12;
                      *(int **)(puVar2[2] + (puVar2[3] + (int)local_14) * 4) = local_30;
                      iVar9 = local_60[(int)local_c];
                      *(undefined4 *)(iVar9 + 0x44) = 0;
                      *(undefined4 *)(iVar9 + 0x48) = 0;
                      local_8 = 1;
                    }
                  }
                  if (((local_10 == (uint *)0x0) && ((int *)(uint)(-1 < iVar6) != (int *)0x0)) ||
                     (*(int *)local_20 == *(int *)(puVar2[2] + (puVar2[3] + (int)local_14) * 4))) {
                    local_30 = *(int **)local_20;
                    if (local_30 != *(int **)((int)local_28 + puVar2[2])) {
                      *(int **)local_20 = *(int **)((int)local_28 + puVar2[2]);
                      *(int **)((int)local_28 + puVar2[2]) = local_30;
                      iVar6 = local_60[(int)local_c];
                      *(undefined4 *)(iVar6 + 0x44) = 0;
                      *(undefined4 *)(iVar6 + 0x48) = 0;
                      local_8 = 1;
                    }
                  }
                }
              }
            }
            local_c = (uint *)((int)local_c + 1);
          } while (local_c < (uint *)0x2);
          local_2c = (double *)((int)local_2c + 1);
        } while (local_2c < (double *)puVar1[3]);
      }
      if ((*puVar1 & 0xff000000) == 0x34000000) {
        local_2c = (double *)0x0;
        local_30 = (int *)0x0;
        if (puVar1[1] != 0) {
          piVar12 = (int *)puVar1[2];
LAB_005fda0d:
          piVar14 = *(int **)(*(int *)(param_1 + 0x14) + *piVar12 * 4);
          if ((*(byte *)(piVar14 + 6) & 4) == 0) {
            local_2c = (double *)((int)local_2c + 1);
          }
          if ((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar14 * 4) + 4) & 0x80) == 0) ||
              (piVar14[1] != -1)) ||
             ((0.0 <= *(double *)(piVar14 + 4) ||
              (pdVar15 = (double *)0x0, *(int *)(param_1 + 0x44) != 0)))) goto LAB_005fda4a;
          if (*(int *)(param_1 + 0xc) != 0) {
            do {
              if ((pdVar15 != local_24) &&
                 (*(int *)(*(int *)(param_1 + 0x18) + (int)pdVar15 * 4) != 0)) {
                FUN_005f7186();
              }
              pdVar15 = (double *)((int)pdVar15 + 1);
            } while (pdVar15 < *(double **)(param_1 + 0xc));
          }
          *(undefined4 *)(param_1 + 0xc) = 0;
          iVar6 = FUN_005f752b(0x34000001,0xffffffff,0xffffffff);
          if (iVar6 != -1) {
            uVar10 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x50),0,0,0xbff0000000000000);
            **(undefined4 **)(**(int **)(param_1 + 0x18) + 8) = uVar10;
            if (**(int **)(**(int **)(param_1 + 0x18) + 8) != -1) {
              uVar13 = 0;
              if (*(int *)(param_1 + 8) != 0) {
                local_38 = *(int *)(param_1 + 8);
                puVar11 = *(undefined4 **)(param_1 + 0x14);
                do {
                  if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *(int *)*puVar11 * 4) + 4) &
                      0x10) != 0) {
                    uVar13 = uVar13 + 1;
                  }
                  puVar11 = puVar11 + 1;
                  local_38 = local_38 + -1;
                } while (local_38 != 0);
                local_38 = 0;
              }
              iVar6 = FUN_005f752b(uVar13 & 0xffffff | 0x10000000,0xffffffff,0xffffffff);
              if ((iVar6 != -1) &&
                 (local_58 = (double *)FUN_005f74cf(*(undefined4 *)(param_1 + 0x50),0,0,0),
                 local_58 != (double *)0xffffffff)) {
                iVar6 = 0;
                uVar13 = 0;
                if (*(int *)(param_1 + 8) != 0) {
                  do {
                    if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) +
                                           **(int **)(*(int *)(param_1 + 0x14) + uVar13 * 4) * 4) +
                                  4) & 0x10) != 0) {
                      *(uint *)(iVar6 + *(int *)(*(int *)(*(int *)(param_1 + 0x18) + 4) + 0x10)) =
                           uVar13;
                      *(double **)(iVar6 + *(int *)(*(int *)(*(int *)(param_1 + 0x18) + 4) + 8)) =
                           local_58;
                      iVar6 = iVar6 + 4;
                    }
                    uVar13 = uVar13 + 1;
                  } while (uVar13 < *(uint *)(param_1 + 8));
                }
                FUN_005f7a42();
                FUN_005f7a42();
                FUN_005f7186();
                *(undefined4 *)(param_1 + 0x44) = 1;
                uVar13 = 0;
                goto LAB_005fe3e0;
              }
            }
          }
          FUN_005f7186();
          goto LAB_005fe3be;
        }
        goto LAB_005fda5e;
      }
      goto LAB_005fda6c;
    }
    goto LAB_005fe253;
  }
LAB_005fe3cc:
  local_20 = (double *)0x0;
  pdVar15 = *(double **)(param_1 + 0xc);
joined_r0x005fe3d4:
  if (pdVar15 != (double *)0x0) {
    local_14 = (double *)((int)pdVar15 + -1);
    puVar1 = *(uint **)(*(int *)(param_1 + 0x18) + (int)local_14 * 4);
    pdVar16 = (double *)puVar1[3];
    pdVar15 = local_14;
    local_28 = pdVar16;
    if (((pdVar16 != (double *)0x0) &&
        ((*(byte *)(*(int *)(*(int *)(param_1 + 0x14) + *(int *)puVar1[4] * 4) + 0x18) & 0x40) == 0)
        ) && ((uVar13 = *puVar1 & 0xff000000, uVar13 == 0x11000000 ||
              ((uVar13 == 0x24000000 || (uVar13 == 0x25000000)))))) {
      if (local_20 < pdVar16) {
        local_20 = pdVar16;
        if (pdVar16 < (double *)0x11) {
          local_20 = (double *)0x10;
        }
        _free(local_18);
        local_18 = _malloc((int)local_20 << 2);
        if (local_18 == (double *)0x0) goto LAB_005fe3be;
        _free(local_1c);
        local_1c = _malloc((int)local_20 << 3);
        if (local_1c == (double *)0x0) goto LAB_005fe3be;
      }
      local_24 = (double *)0x0;
      if (pdVar16 != (double *)0x0) {
        local_2c = local_18;
        local_34 = local_1c;
        do {
          *(undefined4 *)local_2c = 0xffffffff;
          *local_34 = 1.0;
          iVar6 = FUN_005f9c74(*(undefined4 *)(puVar1[4] + (int)local_24 * 4),local_2c,local_34);
          if ((iVar6 < 0) || (*(int *)local_2c == *(int *)(puVar1[4] + (int)local_24 * 4))) break;
          local_24 = (double *)((int)local_24 + 1);
          local_34 = local_34 + 1;
          local_2c = (double *)((int)local_2c + 4);
        } while (local_24 < pdVar16);
        pdVar15 = local_14;
        if (local_24 < pdVar16) goto joined_r0x005fe3d4;
      }
      local_24 = (double *)0x0;
      local_30 = (int *)0x1;
      local_2c = (double *)0x1;
      local_34 = (double *)0x1;
      pdVar15 = local_14;
      if (pdVar16 == (double *)0x0) {
LAB_005fe58f:
        if (*local_1c == 2.0) {
          uVar13 = (uint)pdVar16 & 0xffffff | 0x24000000;
          if (*puVar1 != uVar13) {
            *puVar1 = uVar13;
            local_34 = (double *)((int)pdVar16 * 2);
            local_8 = 1;
            if ((double *)puVar1[1] < local_34) {
              _free((void *)puVar1[2]);
              puVar11 = _malloc((int)pdVar16 << 3);
              puVar1[2] = (uint)puVar11;
              if (puVar11 == (undefined4 *)0x0) goto LAB_005fe3be;
              puVar1[1] = (uint)local_34;
              for (pdVar15 = local_34; pdVar16 = local_28, pdVar15 != (double *)0x0;
                  pdVar15 = (double *)((int)pdVar15 + -1)) {
                *puVar11 = 0xffffffff;
                puVar11 = puVar11 + 1;
              }
            }
          }
          local_2c = (double *)0x0;
          pdVar15 = local_14;
          if (pdVar16 != (double *)0x0) {
            local_34 = (double *)((int)pdVar16 << 2);
            do {
              piVar14 = (int *)((int)local_18 + (int)local_2c * 4);
              piVar12 = (int *)(puVar1[2] + (int)local_2c * 4);
              iVar6 = *piVar14;
              if (*piVar12 != iVar6) {
                *piVar12 = iVar6;
                local_8 = 1;
              }
              iVar6 = *piVar14;
              if (*(int *)(puVar1[2] + (int)local_34) != iVar6) {
                *(int *)(puVar1[2] + (int)local_34) = iVar6;
                local_8 = 1;
              }
              local_2c = (double *)((int)local_2c + 1);
              local_34 = (double *)((int)local_34 + 4);
            } while (local_2c < pdVar16);
          }
          goto joined_r0x005fe3d4;
        }
        if (*local_1c == 1.0) {
          local_2c = (double *)0x0;
          *puVar1 = (uint)pdVar16 & 0xffffff | 0x10000000;
          puVar1[1] = (uint)pdVar16;
          if (pdVar16 != (double *)0x0) {
            do {
              iVar6 = (int)local_2c * 4;
              local_2c = (double *)((int)local_2c + 1);
              *(undefined4 *)(iVar6 + puVar1[2]) = *(undefined4 *)(iVar6 + (int)local_18);
            } while (local_2c < pdVar16);
          }
        }
        else {
          if (*local_1c != 0.0) {
            if (*local_1c != -1.0) goto LAB_005fe74e;
            uVar13 = (uint)pdVar16 & 0xffffff | 0x11000000;
            if (*puVar1 != uVar13) {
              *puVar1 = uVar13;
              puVar1[1] = (uint)pdVar16;
              local_8 = 1;
            }
            local_2c = (double *)0x0;
            if (pdVar16 != (double *)0x0) {
              do {
                piVar12 = (int *)(puVar1[2] + (int)local_2c * 4);
                iVar6 = *(int *)((int)local_2c * 4 + (int)local_18);
                if (*piVar12 != iVar6) {
                  *piVar12 = iVar6;
                  local_8 = 1;
                }
                local_2c = (double *)((int)local_2c + 1);
              } while (local_2c < pdVar16);
            }
            goto joined_r0x005fe3d4;
          }
          *puVar1 = (uint)pdVar16 & 0xffffff | 0x10000000;
          puVar1[1] = (uint)pdVar16;
          if ((local_38 == -1) &&
             (local_38 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x50),0,0,0), local_38 == -1))
          goto LAB_005fe3be;
          pdVar15 = (double *)0x0;
          if (pdVar16 != (double *)0x0) {
            do {
              *(int *)(puVar1[2] + (int)pdVar15 * 4) = local_38;
              pdVar15 = (double *)((int)pdVar15 + 1);
            } while (pdVar15 < pdVar16);
          }
        }
        local_8 = 1;
        pdVar15 = local_14;
        goto joined_r0x005fe3d4;
      }
      do {
        if ((local_24 != (double *)0x0) && (local_1c[(int)local_24] != local_1c[(int)local_24 + -1])
           ) {
          local_34 = (double *)0x0;
        }
        pdVar3 = local_1c + (int)local_24;
        if ((*pdVar3 < -1.0) || (1.0 < *pdVar3)) {
          local_2c = (double *)0x0;
        }
        if ((*pdVar3 < -65504.0) || (65504.0 < *pdVar3)) {
          local_30 = (int *)0x0;
        }
        local_24 = (double *)((int)local_24 + 1);
      } while (local_24 < pdVar16);
      if (local_34 != (double *)0x0) goto LAB_005fe58f;
LAB_005fe74e:
      if ((local_30 != (int *)0x0) &&
         (((*(byte *)(param_1 + 0x92) & 8) == 0 || (local_2c != (double *)0x0)))) {
        uVar13 = (uint)pdVar16 & 0xffffff | 0x25000000;
        if (*puVar1 != uVar13) {
          *puVar1 = uVar13;
          local_34 = (double *)((int)pdVar16 * 2);
          local_8 = 1;
          if ((double *)puVar1[1] < local_34) {
            _free((void *)puVar1[2]);
            puVar11 = _malloc((int)pdVar16 << 3);
            puVar1[2] = (uint)puVar11;
            if (puVar11 == (undefined4 *)0x0) goto LAB_005fe3be;
            puVar1[1] = (uint)local_34;
            for (pdVar15 = local_34; pdVar16 = local_28, pdVar15 != (double *)0x0;
                pdVar15 = (double *)((int)pdVar15 + -1)) {
              *puVar11 = 0xffffffff;
              puVar11 = puVar11 + 1;
            }
          }
        }
        local_24 = (double *)0x0;
        pdVar15 = local_14;
        if (pdVar16 != (double *)0x0) {
          local_2c = (double *)((int)pdVar16 << 2);
          do {
            piVar12 = (int *)(puVar1[2] + (int)local_24 * 4);
            iVar6 = *(int *)((int)local_24 * 4 + (int)local_18);
            if (*piVar12 != iVar6) {
              *piVar12 = iVar6;
              local_8 = 1;
            }
            if (*(int *)((int)local_2c + puVar1[2]) == -1) {
              piVar12 = (int *)0x0;
            }
            else {
              piVar12 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)((int)local_2c + puVar1[2]) * 4
                                 );
            }
            if ((((piVar12 == (int *)0x0) ||
                 ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar12 * 4) + 4) & 0x80) == 0))
                || (piVar12[1] != -1)) || (*(double *)(piVar12 + 4) != local_1c[(int)local_24])) {
              uVar10 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x50),0,0,local_1c[(int)local_24]);
              *(undefined4 *)((int)local_2c + puVar1[2]) = uVar10;
              if (*(int *)((int)local_2c + puVar1[2]) == -1) goto LAB_005fe3be;
              local_8 = 1;
            }
            local_24 = (double *)((int)local_24 + 1);
            local_2c = (double *)((int)local_2c + 4);
            pdVar15 = local_14;
          } while (local_24 < pdVar16);
        }
      }
    }
    goto joined_r0x005fe3d4;
  }
  uVar13 = (uint)(local_8 == 0);
LAB_005fe3e0:
  _free(local_18);
  _free(local_1c);
  return uVar13;
LAB_005fda4a:
  local_30 = (int *)((int)local_30 + 1);
  piVar12 = piVar12 + 1;
  if ((int *)puVar1[1] <= local_30) goto code_r0x005fda58;
  goto LAB_005fda0d;
code_r0x005fda58:
  if (local_2c == (double *)0x0) {
LAB_005fda5e:
    *puVar1 = 0;
    puVar1[1] = 0;
    local_8 = 1;
  }
LAB_005fda6c:
  if ((((*puVar1 & 0xff000000) == 0x50000000) || ((*puVar1 & 0xff000000) == 0x34000000)) &&
     (local_28 = (double *)0x0, puVar1[3] != 0)) {
    do {
      local_40 = (int *)(puVar1[2] + (int)local_28 * 4);
      local_34 = local_24;
      pdVar15 = (double *)*local_40;
LAB_005fdc9b:
      do {
        local_2c = pdVar15;
        piVar12 = *(int **)(*(int *)(param_1 + 0x14) + (int)local_2c * 4);
        if ((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar12 * 4) + 4) & 2) == 0) ||
            (piVar12[1] != -1)) ||
           (((double *)piVar12[0xe] != local_34 || ((double *)piVar12[0xf] != local_34)))) break;
        uVar13 = puVar1[3];
        if (uVar13 < puVar1[1]) {
          puVar11 = (undefined4 *)(puVar1[2] + uVar13 * 4);
          do {
            if (local_2c == (double *)*puVar11) break;
            uVar13 = uVar13 + 1;
            puVar11 = puVar11 + 1;
          } while (uVar13 < puVar1[1]);
          if (uVar13 < puVar1[1]) break;
        }
        local_34 = (double *)piVar12[0xb];
        puVar2 = *(uint **)(*(int *)(param_1 + 0x18) + piVar12[0xb] * 4);
        local_30 = (int *)puVar2[3];
        piVar12 = (int *)0x0;
        if (local_30 != (int *)0x0) {
          piVar14 = (int *)puVar2[4];
          do {
            if ((double *)*piVar14 == local_2c) break;
            piVar14 = piVar14 + 1;
            local_44 = piVar14;
            piVar12 = (int *)((int)piVar12 + 1);
          } while (piVar12 < local_30);
        }
        if ((*puVar2 & 0xff000000) != 0x24000000) {
          if ((*puVar2 & 0xff000000) != 0x25000000) break;
          pdVar16 = *(double **)(puVar2[2] + (int)piVar12 * 4);
          pdVar3 = *(double **)(puVar2[2] + ((int)local_30 + (int)piVar12) * 4);
          pdVar15 = pdVar3;
          if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x14) + (int)pdVar16 * 4) + 0x18) & 4) == 0)
             && (pdVar15 = pdVar16,
                (*(byte *)(*(int *)(*(int *)(param_1 + 0x14) + (int)pdVar3 * 4) + 0x18) & 4) == 0))
          break;
          goto LAB_005fdc9b;
        }
        pdVar15 = *(double **)(puVar2[2] + (int)piVar12 * 4);
      } while (pdVar15 == *(double **)(puVar2[2] + ((int)local_30 + (int)piVar12) * 4));
      local_28 = (double *)((int)local_28 + 1);
      *local_40 = (int)local_2c;
    } while (local_28 < puVar1[3]);
  }
  local_28 = (double *)(*puVar1 & 0xff000000);
  if ((local_28 == (double *)0x11000000) && (puVar1[3] != 0)) {
    local_20 = (double *)puVar1[2];
    local_34 = (double *)puVar1[3];
    do {
      piVar12 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)local_20 * 4);
      if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar12 * 4) + 4) & 2) != 0) &&
         (piVar12[1] == -1)) {
        iVar6 = *(int *)(*(int *)(param_1 + 0x18) + piVar12[0xb] * 4);
        pdVar15 = *(double **)(iVar6 + 0xc);
        local_2c = (double *)0x0;
        if (pdVar15 != (double *)0x0) {
          local_30 = *(int **)(iVar6 + 0x10);
          do {
            if (*local_30 == *(int *)local_20) break;
            local_2c = (double *)((int)local_2c + 1);
            local_30 = local_30 + 1;
          } while (local_2c < pdVar15);
        }
      }
      local_20 = (double *)((int)local_20 + 4);
      local_34 = (double *)((int)local_34 + -1);
    } while (local_34 != (double *)0x0);
  }
  if ((local_28 == (double *)0x50000000) && (local_14 = (double *)0x0, puVar1[3] != 0)) {
    do {
      local_34 = (double *)(puVar1[2] + (int)local_14 * 4);
      piVar12 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)local_34 * 4);
      if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar12 * 4) + 4) & 2) != 0) &&
         (piVar12[1] == -1)) {
        puVar2 = *(uint **)(*(int *)(param_1 + 0x18) + piVar12[0xb] * 4);
        pdVar15 = (double *)puVar2[3];
        local_20 = (double *)0x0;
        if (pdVar15 != (double *)0x0) {
          piVar12 = (int *)puVar2[4];
          do {
            if (*piVar12 == *(int *)local_34) break;
            local_20 = (double *)((int)local_20 + 1);
            piVar12 = piVar12 + 1;
          } while (local_20 < pdVar15);
        }
        local_44 = (int *)(*puVar2 & 0xff000000);
        if (local_44 == (int *)0x11000000) {
          local_c = (uint *)0x1;
        }
        else {
          if (local_44 != (int *)0x25000000) goto LAB_005fdf47;
          local_c = (uint *)0x2;
        }
        local_10 = (uint *)0x0;
        if (local_c != (uint *)0x0) {
          local_54 = (int)pdVar15 * 4;
          local_58 = (double *)((int)pdVar15 * -4);
          local_2c = (double *)(puVar2[2] + (int)local_20 * 4);
          local_28 = (double *)(puVar2[2] + ((int)pdVar15 + (int)local_20) * 4);
          do {
            iVar6 = *(int *)local_2c;
            local_30 = *(int **)(*(int *)(param_1 + 0x14) + iVar6 * 4);
            if (local_44 != (int *)0x25000000) {
LAB_005fdd5a:
              if (iVar6 == *(int *)(puVar1[2] + ((int)local_14 + puVar1[3] * 2) * 4)) {
                local_3c = *(int **)(puVar1[2] + (puVar1[3] + (int)local_14) * 4);
                local_40 = *(int **)(*(int *)(param_1 + 0x14) + (int)local_3c * 4);
                if ((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *local_40 * 4) + 4) & 0x80) ==
                      0) || (local_40[1] != -1)) || (*(double *)(local_40 + 4) != 0.0))
                goto LAB_005fdda7;
                *(int *)local_34 = iVar6;
                *(int *)(puVar1[2] + (puVar1[3] + (int)local_14) * 4) = iVar6;
                *(int **)(puVar1[2] + ((int)local_14 + puVar1[3] * 2) * 4) = local_3c;
              }
              else {
LAB_005fdda7:
                if ((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *local_30 * 4) + 4) & 2) == 0)
                    || (local_30[1] != -1)) ||
                   (puVar2 = *(uint **)(*(int *)(param_1 + 0x18) + local_30[0xb] * 4),
                   (*puVar2 & 0xff000000) != 0x50000000)) goto LAB_005fde9b;
                pdVar16 = (double *)puVar2[3];
                local_20 = (double *)0x0;
                if (pdVar16 != (double *)0x0) {
                  local_30 = (int *)puVar2[4];
                  do {
                    if (*local_30 == iVar6) break;
                    local_20 = (double *)((int)local_20 + 1);
                    local_30 = local_30 + 1;
                  } while (local_20 < pdVar16);
                }
                local_40 = *(int **)(*(int *)(param_1 + 0x14) +
                                    *(int *)(puVar2[2] + ((int)pdVar16 + (int)local_20) * 4) * 4);
                local_3c = *(int **)(*(int *)(param_1 + 0x14) +
                                    *(int *)(puVar2[2] + ((int)local_20 + puVar2[3] * 2) * 4) * 4);
                if ((*(byte *)(local_40 + 6) & 8) == 0) {
                  if ((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *local_40 * 4) + 4) & 0x80)
                        == 0) || (local_40[1] != -1)) || (*(double *)(local_40 + 4) <= 0.0))
                  goto LAB_005fde9b;
                  local_30 = (int *)0x1;
                }
                else {
                  local_30 = (int *)0x0;
                }
                if ((*(byte *)(local_3c + 6) & 8) == 0) {
                  if ((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *local_3c * 4) + 4) & 0x80)
                        == 0) || (local_3c[1] != -1)) || (*(double *)(local_3c + 4) <= 0.0))
                  goto LAB_005fde9b;
                  local_2c = (double *)0x1;
                }
                else {
                  local_2c = (double *)0x0;
                }
                local_28 = *(double **)(puVar1[2] + ((int)local_14 + puVar1[3]) * 4);
                local_58 = *(double **)(puVar1[2] + ((int)local_14 + puVar1[3] * 2) * 4);
                *(undefined4 *)local_34 = *(undefined4 *)(puVar2[2] + (int)local_20 * 4);
                pdVar15 = local_58;
                if (local_30 == (int *)0x0) {
                  pdVar15 = local_28;
                }
                *(double **)(puVar1[2] + (puVar1[3] + (int)local_14) * 4) = pdVar15;
                pdVar15 = local_58;
                if (local_2c == (double *)0x0) {
                  pdVar15 = local_28;
                }
                *(double **)(puVar1[2] + ((int)local_14 + puVar1[3] * 2) * 4) = pdVar15;
              }
              local_8 = 1;
              break;
            }
            local_40 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)local_28 * 4);
            if ((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *local_40 * 4) + 4) & 0x80) != 0)
                && (local_40[1] == -1)) && (*(double *)(local_40 + 4) < 0.0)) goto LAB_005fdd5a;
LAB_005fde9b:
            local_2c = (double *)((int)local_2c + (int)pdVar15 * 4);
            local_10 = (uint *)((int)local_10 + 1);
            local_28 = (double *)((int)local_28 + (int)pdVar15 * -4);
          } while (local_10 < local_c);
        }
      }
LAB_005fdf47:
      local_14 = (double *)((int)local_14 + 1);
    } while (local_14 < (double *)puVar1[3]);
  }
  if ((*puVar1 & 0xff000000) == 0x14000000) {
    local_28 = (double *)0xffffffff;
    local_c = (uint *)0xffffffff;
    local_20 = (double *)0x0;
    if (puVar1[1] != 0) {
      do {
        iVar6 = *(int *)(puVar1[2] + (int)local_20 * 4);
        piVar12 = *(int **)(*(int *)(param_1 + 0x14) + iVar6 * 4);
        if ((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar12 * 4) + 4) & 2) != 0) &&
            (piVar12[1] == -1)) &&
           (local_10 = *(uint **)(*(int *)(param_1 + 0x18) + piVar12[0xb] * 4),
           (*local_10 & 0xff000000) == 0x25000000)) {
          local_14 = (double *)0x0;
          if ((double *)local_10[3] != (double *)0x0) {
            local_34 = (double *)local_10[4];
            do {
              if (*(int *)local_34 == iVar6) break;
              local_14 = (double *)((int)local_14 + 1);
              local_34 = (double *)((int)local_34 + 4);
            } while (local_14 < (double *)local_10[3]);
          }
          local_2c = (double *)0x0;
          local_30 = (int *)0x1;
          do {
            local_58 = *(double **)
                        (local_10[2] + (int)(local_10[3] * (int)local_2c + (int)local_14) * 4);
            piVar12 = *(int **)(*(int *)(param_1 + 0x14) + (int)local_58 * 4);
            if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar12 * 4) + 4) & 2) != 0) &&
               (piVar12[1] == -1)) {
              pdVar15 = *(double **)(*(int *)(param_1 + 0x18) + piVar12[0xb] * 4);
              local_34 = pdVar15;
              if (((ulonglong)*pdVar15 & 0xff000000) == 0x15000000) {
                if (piVar12[0x10] == 1) {
                  uVar13 = piVar12[6];
                  uVar7 = *(uint *)(*(int *)(*(int *)(param_1 + 0x14) +
                                            *(int *)(puVar1[4] + (int)local_20 * 4) * 4) + 0x18) |
                          uVar13;
                  uVar8 = uVar7 & 0xe000000;
                  uVar5 = 0x8000000;
                  if ((((uVar7 & 0x8000000) != 0) || (uVar5 = 0x4000000, (uVar7 & 0x4000000) != 0))
                     || (uVar5 = 0x2000000, (uVar7 & 0x2000000) != 0)) {
                    uVar8 = uVar5;
                  }
                  if ((uVar13 & 0xe000000) != uVar8) {
                    piVar12[6] = uVar13 & 0xf1ffffff | uVar8;
                    local_8 = 1;
                  }
                }
                if ((((*(byte *)(param_1 + 0x90) & 0x40) != 0) && (puVar1[3] == 1)) &&
                   ((*(byte *)(*(int *)(*(int *)(param_1 + 0x14) +
                                       *(int *)(puVar1[4] + (int)local_20 * 4) * 4) + 0x1b) & 2) !=
                    0)) {
                  uVar13 = 0;
                  if (*(int *)((int)pdVar15 + 0xc) != 0) {
                    local_34 = *(double **)(pdVar15 + 2);
                    do {
                      if (*(double **)local_34 == local_58) break;
                      local_34 = (double *)((int)local_34 + 4);
                      uVar13 = uVar13 + 1;
                    } while (uVar13 < *(uint *)((int)pdVar15 + 0xc));
                  }
                  local_28 = *(double **)(*(int *)(pdVar15 + 1) + uVar13 * 4);
                  local_c = *(uint **)(local_10[2] +
                                      (int)(local_10[3] * (int)local_30 + (int)local_14) * 4);
                }
              }
            }
            local_2c = (double *)((int)local_2c + 1);
            local_30 = (int *)((int)local_30 + -1);
          } while (local_2c < (double *)0x2);
        }
        local_20 = (double *)((int)local_20 + 1);
      } while (local_20 < (double *)puVar1[1]);
      if (local_28 != (double *)0xffffffff) {
        iVar6 = FUN_005f752b(0x33000004,0xffffffff,0xffffffff);
        if ((iVar6 == -1) || (iVar9 = FUN_005f752b(0x10000001,0xffffffff,0xffffffff), iVar9 == -1))
        {
          return 0x8007000e;
        }
        iVar6 = *(int *)(*(int *)(param_1 + 0x18) + iVar6 * 4);
        local_34 = *(double **)(*(int *)(param_1 + 0x18) + iVar9 * 4);
        FUN_005f7a42();
        FUN_005f7a42();
        local_2c = (double *)0x0;
        piVar12 = (int *)(iVar6 + 8);
        *(double **)(*piVar12 + 4) = local_28;
        *(double **)*piVar12 = local_28;
        *(uint **)(*piVar12 + 0xc) = local_c;
        *(uint **)(*piVar12 + 8) = local_c;
        do {
          uVar10 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),0,0,0);
          *(undefined4 *)((int)local_2c + *(int *)(iVar6 + 0x10)) = uVar10;
          iVar9 = *(int *)((int)local_2c + *(int *)(iVar6 + 0x10));
          if (iVar9 == -1) {
            return 0x8007000e;
          }
          local_2c = (double *)((int)local_2c + 4);
          puVar2 = (uint *)(*(int *)(*(int *)(param_1 + 0x14) + iVar9 * 4) + 0x18);
          *puVar2 = *puVar2 | *(uint *)(*(int *)(*(int *)(param_1 + 0x14) + *(int *)puVar1[4] * 4) +
                                       0x18) & 0xe000000;
        } while (local_2c < (double *)0x10);
        **(undefined4 **)(local_34 + 1) = *(undefined4 *)(*(int *)(iVar6 + 0x10) + 8);
        **(undefined4 **)(local_34 + 2) = *(undefined4 *)puVar1[4];
        FUN_005f7186();
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;
        pdVar15 = *(double **)(param_1 + 0xc);
        while (pdVar15 = (double *)((int)pdVar15 + -1), local_24 < pdVar15) {
          puVar11 = (undefined4 *)(*(int *)(param_1 + 0x18) + (int)pdVar15 * 4);
          *puVar11 = puVar11[-1];
        }
        *(int *)(*(int *)(param_1 + 0x18) + (int)local_24 * 4) = iVar6;
        *(double **)(*(int *)(param_1 + 0x18) + 4 + (int)local_24 * 4) = local_34;
        FUN_005fb8ae();
        local_8 = 1;
      }
    }
  }
LAB_005fe253:
  local_24 = (double *)((int)local_24 + 1);
  if (*(double **)(param_1 + 0xc) <= local_24) goto code_r0x005fe262;
  goto LAB_005fd5e2;
code_r0x005fe262:
  if (local_8 != 0) {
    return 0;
  }
  goto LAB_005fe3cc;
LAB_005fe3be:
  uVar13 = 0x8007000e;
  goto LAB_005fe3e0;
}


// ==== 0x5fe888 FUN_005fe888

undefined4 __fastcall FUN_005fe888(int param_1)

{
  int *piVar1;
  uint *puVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  bVar5 = false;
  bVar4 = false;
  bVar3 = false;
  local_c = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      piVar9 = *(int **)(*(int *)(param_1 + 0x14) + local_c * 4);
      if ((*(int *)(param_1 + 0x4c) != *piVar9) && (piVar12 = piVar9 + 1, *piVar12 != -1)) {
        if (!bVar3) {
          FUN_005fb8ae();
          bVar3 = true;
        }
        iVar7 = *piVar12;
        iVar14 = *(int *)(*(int *)(param_1 + 0x14) + iVar7 * 4);
        piVar13 = piVar12;
        if ((*(int *)(iVar14 + 0x2c) != -1) && (iVar6 = FUN_005f7aa3(), iVar6 != 0)) {
          iVar14 = *(int *)(*(int *)(param_1 + 0x18) + *(int *)(iVar14 + 0x2c) * 4);
          uVar10 = 0;
          if (*(uint *)(iVar14 + 0xc) != 0) {
            piVar13 = *(int **)(iVar14 + 0x10);
            do {
              if (*piVar13 == iVar7) break;
              uVar10 = uVar10 + 1;
              piVar13 = piVar13 + 1;
            } while (uVar10 < *(uint *)(iVar14 + 0xc));
          }
          piVar13 = (int *)(*(int *)(iVar14 + 8) + uVar10 * 4);
        }
        local_10 = *(int **)(param_1 + 0x14);
        piVar1 = (int *)local_10[*piVar13];
        uVar10 = *(uint *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar1 * 4) + 4);
        if (((char)uVar10 < '\0') && (piVar1[1] == -1)) {
          iVar7 = __ftol();
          local_8 = 0;
          uVar10 = iVar7 + piVar9[2];
          if (*(uint *)(param_1 + 8) != 0) {
            do {
              if ((((local_8 != local_c) && (piVar13 = (int *)*local_10, *piVar13 == *piVar9)) &&
                  (piVar13[1] == -1)) && ((piVar13[2] == uVar10 && (piVar13[3] == piVar9[3])))) {
                if (!bVar4) {
                  FUN_005fbe17();
                  bVar4 = true;
                }
                piVar9[7] = local_8;
                break;
              }
              local_8 = local_8 + 1;
              local_10 = local_10 + 1;
            } while (local_8 < *(uint *)(param_1 + 8));
          }
          if (local_8 == *(uint *)(param_1 + 8)) {
            *piVar12 = -1;
            piVar9[2] = uVar10;
            if (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar9 * 4) + 8) <= uVar10) {
              FUN_005fbec8(param_1,piVar9[0x11],0xfa7,"array index out of bounds");
              return 0x80004005;
            }
          }
        }
        else {
          if (((uVar10 & 2) == 0) ||
             ((piVar1[0xb] == -1 ||
              (puVar2 = *(uint **)(*(int *)(param_1 + 0x18) + piVar1[0xb] * 4),
              (*puVar2 & 0xff000000) != 0x24000000)))) goto LAB_005feb56;
          uVar10 = puVar2[3];
          uVar11 = 0;
          if (uVar10 != 0) {
            piVar9 = (int *)puVar2[4];
            do {
              if (*piVar9 == *piVar13) break;
              uVar11 = uVar11 + 1;
              piVar9 = piVar9 + 1;
            } while (uVar11 < uVar10);
          }
          iVar14 = *(int *)(puVar2[2] + uVar11 * 4);
          iVar6 = *(int *)(puVar2[2] + (uVar10 + uVar11) * 4);
          piVar9 = (int *)local_10[iVar6];
          piVar1 = (int *)local_10[iVar14];
          if (((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar1 * 4) + 4) & 0x80) == 0) ||
               (piVar1[1] != -1)) || ((piVar1[6] & 4U) == 0)) ||
             (((piVar1[6] & 2U) == 0 && ((*(byte *)(piVar9 + 6) & 2) == 0)))) {
            if ((((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar9 * 4) + 4) & 0x80) == 0) ||
                ((piVar9[1] != -1 || ((piVar9[6] & 4U) == 0)))) ||
               (((*(byte *)(piVar1 + 6) & 2) == 0 && ((piVar9[6] & 2U) == 0)))) goto LAB_005feb56;
            iVar8 = __ftol();
          }
          else {
            iVar8 = __ftol();
            iVar14 = iVar6;
          }
          if (*piVar13 == *piVar12) {
            uVar10 = 0;
            if (*(int *)(param_1 + 8) != 0) {
              do {
                iVar6 = *(int *)(*(int *)(param_1 + 0x14) + uVar10 * 4);
                if (iVar7 == *(int *)(iVar6 + 4)) {
                  *(int *)(iVar6 + 8) = *(int *)(iVar6 + 8) + iVar8;
                  *(int *)(iVar6 + 4) = iVar14;
                }
                uVar10 = uVar10 + 1;
              } while (uVar10 < *(uint *)(param_1 + 8));
            }
          }
          else {
            uVar10 = 0;
            if (*(int *)(param_1 + 8) != 0) {
              do {
                iVar6 = *(int *)(*(int *)(param_1 + 0x14) + uVar10 * 4);
                if (iVar7 == *(int *)(iVar6 + 4)) {
                  piVar9 = (int *)(iVar6 + 8);
                  *piVar9 = *piVar9 + iVar8;
                }
                uVar10 = uVar10 + 1;
              } while (uVar10 < *(uint *)(param_1 + 8));
            }
            *piVar13 = iVar14;
          }
        }
        bVar5 = true;
      }
LAB_005feb56:
      local_c = local_c + 1;
    } while (local_c < *(uint *)(param_1 + 8));
    if (bVar5) {
      if (bVar4) {
        FUN_005fbe30();
      }
      return 0;
    }
  }
  return 1;
}


// ==== 0x5feb84 FUN_005feb84

undefined4 __fastcall FUN_005feb84(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  int *piVar3;
  int *piVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint local_1c;
  uint local_18;
  uint local_10;
  uint local_c;
  uint local_8;
  
  if ((*(byte *)(param_1 + 0x90) & 1) == 0) {
    bVar5 = false;
    FUN_005fbe17();
    FUN_005fb8ae();
    local_18 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      do {
        puVar2 = *(uint **)(*(int *)(param_1 + 0x18) + local_18 * 4);
        iVar6 = FUN_005f7aa3();
        if (iVar6 != 0) {
          local_c = 0;
          if (puVar2[3] != 0) {
            do {
              iVar6 = *(int *)(local_c * 4 + puVar2[4]);
              if (iVar6 != -1) {
                piVar3 = *(int **)(*(int *)(param_1 + 0x14) + iVar6 * 4);
                if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar3 * 4) + 4) & 0x10) != 0)
                   && (piVar4 = *(int **)(*(int *)(param_1 + 0x14) +
                                         *(int *)(local_c * 4 + puVar2[2]) * 4),
                      (*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar4 * 4) + 4) & 2) != 0)) {
                  iVar6 = *(int *)(*(int *)(param_1 + 0x18) + piVar4[0xb] * 4);
                  local_1c = 0;
                  local_8 = 0;
                  if (*(int *)(iVar6 + 0xc) != 0) {
                    do {
                      iVar7 = *(int *)(*(int *)(param_1 + 0x14) +
                                      *(int *)(*(int *)(iVar6 + 0x10) + local_8 * 4) * 4);
                      if ((*(int *)(iVar7 + 4) == -1) && (*(uint *)(iVar7 + 0x40) < 2)) {
                        for (local_10 = local_c; local_10 < puVar2[3]; local_10 = local_10 + 1) {
                          if ((((*(int *)(*(int *)(iVar6 + 0x10) + local_8 * 4) ==
                                 *(int *)(puVar2[2] + local_10 * 4)) &&
                               (piVar4 = *(int **)(*(int *)(param_1 + 0x14) +
                                                  *(int *)(puVar2[4] + local_10 * 4) * 4),
                               *piVar4 == *piVar3)) && (piVar4[2] == piVar3[2])) &&
                             (((local_8 == piVar4[3] || (*(uint *)(iVar6 + 0xc) < 2)) ||
                              (iVar7 = FUN_005f7b57(), iVar7 == 0)))) {
                            local_1c = local_1c + 1;
                            break;
                          }
                        }
                      }
                      local_8 = local_8 + 1;
                    } while (local_8 < *(uint *)(iVar6 + 0xc));
                  }
                  if ((*(uint *)(iVar6 + 0xc) <= local_1c) &&
                     (local_8 = 0, *(uint *)(iVar6 + 0xc) != 0)) {
                    do {
                      for (local_10 = local_c; local_10 < puVar2[3]; local_10 = local_10 + 1) {
                        iVar7 = local_10 * 4;
                        if (*(int *)(*(int *)(iVar6 + 0x10) + local_8 * 4) ==
                            *(int *)(iVar7 + puVar2[2])) {
                          *(undefined4 *)
                           (*(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar7 + puVar2[2]) * 4) +
                           0x1c) = *(undefined4 *)(iVar7 + puVar2[4]);
                          puVar1 = (uint *)(*(int *)(*(int *)(param_1 + 0x14) +
                                                    *(int *)(iVar7 + puVar2[4]) * 4) + 0x18);
                          *puVar1 = *puVar1 | *(uint *)(*(int *)(*(int *)(param_1 + 0x14) +
                                                                *(int *)(iVar7 + puVar2[2]) * 4) +
                                                       0x18);
                          *(undefined4 *)(iVar7 + puVar2[4]) = 0xffffffff;
                          *(undefined4 *)(iVar7 + puVar2[2]) = 0xffffffff;
                        }
                      }
                      local_8 = local_8 + 1;
                    } while (local_8 < *(uint *)(iVar6 + 0xc));
                  }
                }
              }
              local_c = local_c + 1;
            } while (local_c < puVar2[3]);
          }
          uVar9 = 0;
          uVar8 = 0;
          if (puVar2[3] != 0) {
            do {
              iVar6 = *(int *)(puVar2[4] + uVar9 * 4);
              if (iVar6 != -1) {
                *(int *)(puVar2[4] + uVar8 * 4) = iVar6;
                *(undefined4 *)(puVar2[2] + uVar8 * 4) = *(undefined4 *)(puVar2[2] + uVar9 * 4);
                uVar8 = uVar8 + 1;
              }
              uVar9 = uVar9 + 1;
            } while (uVar9 < puVar2[3]);
          }
          if (uVar8 != puVar2[3]) {
            *puVar2 = -(uint)(uVar8 != 0) & (uVar8 & 0xffffff | 0x10000000);
            puVar2[3] = uVar8;
            puVar2[1] = uVar8;
            bVar5 = true;
          }
        }
        local_18 = local_18 + 1;
      } while (local_18 < *(uint *)(param_1 + 0xc));
      if (bVar5) {
        FUN_005fbe30();
        return 0;
      }
    }
  }
  return 1;
}


// ==== 0x5fede4 FUN_005fede4

bool __fastcall FUN_005fede4(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  uint local_8;
  
  uVar5 = 0;
  bVar4 = false;
  if (*(int *)(param_1 + 4) != 0) {
    do {
      iVar7 = uVar5 * 4;
      uVar5 = uVar5 + 1;
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x10) + iVar7) + 0x28) = 0;
    } while (uVar5 < *(uint *)(param_1 + 4));
  }
  uVar5 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      iVar7 = uVar5 * 4;
      uVar5 = uVar5 + 1;
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + iVar7) + 0x38) = 0;
    } while (uVar5 < *(uint *)(param_1 + 8));
  }
  local_8 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      piVar2 = *(int **)(*(int *)(param_1 + 0x18) + local_8 * 4);
      if (*piVar2 != 0) {
        uVar5 = 0;
        if (piVar2[1] != 0) {
          do {
            piVar3 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)(piVar2[2] + uVar5 * 4) * 4);
            piVar3[0xe] = piVar3[0xe] + 1;
            iVar7 = piVar3[1];
            while (iVar7 != -1) {
              piVar1 = (int *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar3 * 4) + 0x28);
              *piVar1 = *piVar1 + 1;
              piVar3 = *(int **)(*(int *)(param_1 + 0x14) + piVar3[1] * 4);
              piVar3[0xe] = piVar3[0xe] + 1;
              iVar7 = piVar3[1];
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < (uint)piVar2[1]);
        }
        uVar5 = 0;
        if (piVar2[3] != 0) {
          do {
            piVar3 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)(piVar2[4] + uVar5 * 4) * 4);
            piVar3[0xe] = piVar3[0xe] + 1;
            iVar7 = piVar3[1];
            while (iVar7 != -1) {
              piVar1 = (int *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar3 * 4) + 0x28);
              *piVar1 = *piVar1 + 1;
              piVar3 = *(int **)(*(int *)(param_1 + 0x14) + piVar3[1] * 4);
              piVar3[0xe] = piVar3[0xe] + 1;
              iVar7 = piVar3[1];
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < (uint)piVar2[3]);
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)(param_1 + 0xc));
  }
  uVar5 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    do {
      iVar7 = *(int *)(*(int *)(param_1 + 0x10) + uVar5 * 4);
      if (((*(uint *)(iVar7 + 4) & 0x200) != 0) && (*(int *)(iVar7 + 0x28) == 0)) {
        *(uint *)(iVar7 + 4) = *(uint *)(iVar7 + 4) & 0xfffffdff;
        bVar4 = true;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 4));
  }
  uVar5 = 0;
  local_8 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      piVar2 = *(int **)(*(int *)(param_1 + 0x14) + uVar5 * 4);
      if ((piVar2[1] == -1) &&
         (iVar7 = *(int *)(*(int *)(param_1 + 0x10) + *piVar2 * 4),
         (*(uint *)(iVar7 + 4) & 0x200) != 0)) {
        piVar2[0xe] = piVar2[0xe] + *(int *)(iVar7 + 0x28);
      }
      if (piVar2[0xe] == 0) {
        piVar2[7] = -1;
      }
      else {
        piVar2[7] = local_8;
        local_8 = local_8 + 1;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 8));
  }
  iVar7 = 0;
  if (local_8 == *(int *)(param_1 + 8)) {
    bVar4 = !bVar4;
  }
  else {
    FUN_005fbe30();
    uVar5 = 0;
    if (*(int *)(param_1 + 8) != 0) {
      do {
        iVar6 = *(int *)(*(int *)(param_1 + 0x14) + uVar5 * 4);
        if (*(int *)(iVar6 + 0x38) == 0) {
          FUN_005f716a(1);
        }
        else {
          *(int *)(*(int *)(param_1 + 0x14) + iVar7 * 4) = iVar6;
          iVar7 = iVar7 + 1;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(param_1 + 8));
    }
    puVar8 = (undefined4 *)(*(int *)(param_1 + 0x14) + iVar7 * 4);
    for (uVar5 = *(int *)(param_1 + 8) - iVar7 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined1 *)puVar8 = 0;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    *(int *)(param_1 + 8) = iVar7;
    bVar4 = false;
  }
  return bVar4;
}


// ==== 0x5fefac FUN_005fefac

/* WARNING: Removing unreachable block (ram,0x005ff3bb) */
/* WARNING: Removing unreachable block (ram,0x005ff3c3) */

undefined4 __thiscall FUN_005fefac(int param_1,uint *param_2,uint param_3,int param_4)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  float10 fVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  float10 fVar14;
  undefined8 uVar15;
  
  iVar7 = *(int *)(param_1 + 0x14);
  iVar10 = *(int *)(*(int *)(iVar7 + param_4 * 4) + 0x1c);
  piVar1 = *(int **)(iVar7 + param_3 * 4);
  piVar9 = *(int **)(iVar7 + iVar10 * 4);
  if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar1 * 4) + 4) & 1) == 0) {
    return 0;
  }
  uVar2 = piVar9[6];
  uVar3 = piVar1[6];
  uVar12 = uVar3 & 0x40;
  uVar13 = *param_2 & 0xff000000;
  if (uVar13 == 0x10000000) {
    piVar1[6] = uVar3 | uVar2 & 0x1f;
    goto LAB_005ff660;
  }
  uVar6 = uVar2 & 0x60 | uVar3;
  piVar1[6] = uVar6;
  if (((uVar3 & 0xe000000) == 0) &&
     ((((uVar13 == 0x11000000 || (uVar13 == 0x12000000)) || (uVar13 == 0x13000000)) ||
      ((uVar13 == 0x1c000000 || (uVar13 == 0x1d000000)))))) {
    piVar1[6] = piVar9[6] & 0xe000000U | uVar6;
  }
  uVar3 = 4;
  if (uVar13 == 0x11000000) {
    piVar1[6] = piVar1[6] | (uVar2 & 0x1f) >> 1 & 4 | (uVar2 & 4) << 1 | uVar2 & 0x13;
LAB_005ff0e7:
    uVar3 = *(uint *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar9 * 4) + 4);
    if ((-1 < (char)uVar3) || (piVar9[1] != -1)) {
      if ((uVar2 & 1) != 0) {
        if (uVar13 == 0x13000000) goto LAB_005ff3cb;
        if (uVar13 == 0x16000000) goto LAB_005ff660;
      }
      if (((uVar2 & 2) != 0) && (uVar13 == 0x13000000)) goto LAB_005ff3cb;
      if ((uVar2 & 8) != 0) {
        if (uVar13 == 0x15000000) {
          if (uVar12 != 0) {
            return 0;
          }
          if ((uVar2 & 4) != 0) {
            return 0;
          }
          FUN_005fbec8(param_1,param_2[0xd],0xfa2,"indefinite logarithm");
          return 0;
        }
        if (uVar13 == 0x16000000) {
          if (uVar12 != 0) {
            return 0;
          }
          uVar15 = 0x69f34000000fa3;
          goto LAB_005ff0af;
        }
      }
      if (uVar12 != 0) {
        return 0;
      }
      if ((uVar3 & 2) == 0) {
        return 0;
      }
      if (((((uVar13 != 0x11000000) ||
            (puVar8 = *(uint **)(*(int *)(param_1 + 0x18) + piVar9[0xb] * 4),
            (*puVar8 & 0xff000000) != 0x11000000)) &&
           ((uVar13 != 0x12000000 ||
            (puVar8 = *(uint **)(*(int *)(param_1 + 0x18) + piVar9[0xb] * 4),
            (*puVar8 & 0xff000000) != 0x12000000)))) &&
          ((uVar13 != 0x14000000 ||
           (puVar8 = *(uint **)(*(int *)(param_1 + 0x18) + piVar9[0xb] * 4),
           (*puVar8 & 0xff000000) != 0x15000000)))) &&
         ((uVar13 != 0x15000000 ||
          (puVar8 = *(uint **)(*(int *)(param_1 + 0x18) + piVar9[0xb] * 4),
          (*puVar8 & 0xff000000) != 0x14000000)))) {
LAB_005ff4c2:
        if ((uVar13 == 0x16000000) &&
           (puVar8 = *(uint **)(*(int *)(param_1 + 0x18) + piVar9[0xb] * 4),
           (*puVar8 & 0xff000000) == 0x25000000)) {
          param_2 = (uint *)0x0;
          if (puVar8[3] != 0) {
            param_3 = puVar8[3] << 2;
            do {
              if (((*(int *)(puVar8[4] + (int)param_2 * 4) == iVar10) &&
                  (iVar7 = *(int *)(puVar8[2] + (int)param_2 * 4),
                  iVar7 == *(int *)(puVar8[2] + param_3))) &&
                 ((*(byte *)(*(int *)(*(int *)(param_1 + 0x14) + iVar7 * 4) + 0x18) & 4) != 0)) {
                piVar1[7] = *(int *)(*(int *)(*(int *)(param_1 + 0x14) +
                                             *(int *)(puVar8[2] + (int)param_2 * 4) * 4) + 0x1c);
                return 0;
              }
              param_2 = (uint *)((int)param_2 + 1);
              param_3 = param_3 + 4;
            } while (param_2 < puVar8[3]);
          }
        }
        if (uVar13 != 0x14000000) {
          return 0;
        }
        puVar8 = *(uint **)(*(int *)(param_1 + 0x18) + piVar9[0xb] * 4);
        if ((*puVar8 & 0xff000000) != 0x25000000) {
          return 0;
        }
        param_2 = (uint *)0x0;
        if (puVar8[3] != 0) {
          piVar9 = (int *)puVar8[4];
          do {
            if (*piVar9 == iVar10) break;
            param_2 = (uint *)((int)param_2 + 1);
            piVar9 = piVar9 + 1;
          } while (param_2 < puVar8[3]);
        }
        param_3 = 0;
        iVar7 = (int)param_2 * 4;
        piVar9 = (int *)(puVar8[2] + iVar7);
        do {
          piVar11 = *(int **)(*(int *)(param_1 + 0x14) + *piVar9 * 4);
          if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar11 * 4) + 4) & 2) != 0) &&
             (puVar4 = *(uint **)(*(int *)(param_1 + 0x18) + piVar11[0xb] * 4),
             (*puVar4 & 0xff000000) == 0x15000000)) {
            param_2 = (uint *)0x0;
            if (puVar4[3] != 0) {
              do {
                if (*(int *)(iVar7 + puVar4[4]) == *piVar9) break;
                param_2 = (uint *)((int)param_2 + 1);
              } while (param_2 < puVar4[3]);
            }
            uVar2 = *(uint *)(*(int *)(*(int *)(param_1 + 0x14) +
                                      *(int *)(puVar4[2] + (int)param_2 * 4) * 4) + 0x18);
            if (((uVar2 & 4) != 0) && ((uVar2 & 8) != 0)) goto LAB_005ff64d;
          }
          param_3 = param_3 + 1;
          piVar9 = piVar9 + puVar8[3];
          if (1 < param_3) {
            return 0;
          }
        } while( true );
      }
      param_2 = (uint *)0x0;
      if (puVar8[3] != 0) {
        piVar11 = (int *)puVar8[4];
        do {
          if (*piVar11 == iVar10) break;
          param_2 = (uint *)((int)param_2 + 1);
          piVar11 = piVar11 + 1;
        } while (param_2 < puVar8[3]);
      }
      if (puVar8[3] <= param_2) goto LAB_005ff4c2;
      iVar10 = *(int *)(*(int *)(*(int *)(param_1 + 0x14) +
                                *(int *)(puVar8[2] + (int)param_2 * 4) * 4) + 0x1c);
      goto LAB_005ff660;
    }
    if (uVar13 < 0x17000001) {
      if (uVar13 == 0x17000000) {
        fVar14 = (float10)fsin((float10)*(double *)(piVar9 + 4));
      }
      else if (uVar13 == 0x11000000) {
        fVar14 = -(float10)*(double *)(piVar9 + 4);
      }
      else if (uVar13 == 0x12000000) {
        if ((uVar12 == 0) && (*(double *)(piVar9 + 4) == 0.0)) {
LAB_005ff3cb:
          fVar14 = (float10)0;
        }
        else {
          fVar14 = (float10)1 / (float10)*(double *)(piVar9 + 4);
        }
      }
      else if (uVar13 == 0x13000000) {
        iVar7 = _finite(*(undefined8 *)(piVar9 + 4));
        if (iVar7 == 0) goto LAB_005ff3cb;
        fVar14 = (float10)FUN_00673590(*(undefined8 *)(piVar9 + 4));
        fVar14 = (float10)*(double *)(piVar9 + 4) - fVar14;
      }
      else if (uVar13 == 0x14000000) {
        fVar14 = (float10)FUN_00673890();
      }
      else if (uVar13 == 0x15000000) {
        if ((uVar12 == 0) && (*(double *)(piVar9 + 4) == 0.0)) {
          return 0;
        }
        if (*(double *)(piVar9 + 4) < 0.0) {
          uVar15 = 0x6a3fd400000fa2;
          goto LAB_005ff304;
        }
        fVar14 = (float10)log2((float10)*(double *)(piVar9 + 4));
        fVar5 = (float10)log2((float10)2.0);
        fVar14 = ((float10)0.6931471805599453 * fVar14) / ((float10)0.6931471805599453 * fVar5);
      }
      else {
        if (uVar13 != 0x16000000) {
          return 0;
        }
        if ((uVar12 == 0) && (*(double *)(piVar9 + 4) < 0.0)) {
          uVar15 = 0x69f34000000fa3;
LAB_005ff304:
          FUN_005fbec8(param_1,param_2[0xd],uVar15);
          goto LAB_005ff3cb;
        }
        fVar14 = SQRT((float10)*(double *)(piVar9 + 4));
      }
    }
    else if (uVar13 == 0x18000000) {
      fVar14 = (float10)fcos((float10)*(double *)(piVar9 + 4));
    }
    else if (uVar13 == 0x19000000) {
      if ((uVar12 == 0) && ((*(double *)(piVar9 + 4) < -1.0 || (1.0 < *(double *)(piVar9 + 4))))) {
        uVar15 = 0x6a3fa800000fa5;
        goto LAB_005ff304;
      }
      fVar14 = (float10)FUN_00673b70();
    }
    else if (uVar13 == 0x1a000000) {
      if ((uVar12 == 0) && ((*(double *)(piVar9 + 4) < -1.0 || (1.0 < *(double *)(piVar9 + 4))))) {
        uVar15 = 0x6a3fbc00000fa6;
        goto LAB_005ff304;
      }
      fVar14 = (float10)FUN_00672e20();
    }
    else {
      if (uVar13 != 0x1b000000) {
        if ((uVar13 != 0x1c000000) && (uVar13 != 0x1d000000)) {
          return 0;
        }
        goto LAB_005ff3cb;
      }
      fVar14 = (float10)fpatan((float10)*(double *)(piVar9 + 4),(float10)1);
    }
  }
  else {
    if (uVar13 != 0x12000000) {
      uVar6 = 4;
      if (((uVar13 == 0x13000000) || (uVar6 = uVar3, uVar13 == 0x14000000)) ||
         (uVar13 == 0x16000000)) goto LAB_005ff08f;
      goto LAB_005ff0e7;
    }
    if (((uVar2 & 4) == 0) || ((uVar2 & 8) == 0)) {
      uVar6 = uVar2 & 0xc;
LAB_005ff08f:
      piVar1[6] = piVar1[6] | uVar6;
      goto LAB_005ff0e7;
    }
    uVar6 = uVar3;
    if (uVar12 != 0) goto LAB_005ff08f;
    uVar15 = 0x69f38c00000fa1;
LAB_005ff0af:
    FUN_005fbec8(param_1,param_2[0xd],uVar15);
LAB_005ff64d:
    fVar14 = (float10)0;
  }
  iVar10 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x50),0,0,(double)fVar14);
LAB_005ff660:
  piVar1[7] = iVar10;
  return 0;
}


// ==== 0x5ff66c FUN_005ff66c

int __fastcall FUN_005ff66c(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  uint *puVar9;
  uint *puVar10;
  undefined4 *puVar11;
  undefined4 local_64 [4];
  uint local_54;
  uint *local_50;
  uint *local_4c;
  uint *local_48;
  int local_44;
  undefined4 local_40;
  uint *local_3c;
  int local_38;
  uint local_34;
  uint *local_30;
  uint *local_2c;
  int local_28;
  uint *local_24;
  int local_20;
  uint *local_1c;
  uint *local_18;
  uint *local_14;
  uint local_10;
  uint local_c;
  uint *local_8;
  
  local_38 = -1;
  local_28 = param_1;
  iVar2 = FUN_005f8440();
  if (-1 < iVar2) {
    iVar2 = *(int *)(param_1 + 8);
    local_10 = 0;
    if (iVar2 != 0) {
      puVar8 = *(undefined4 **)(param_1 + 0x14);
      do {
        if ((*(int *)(param_1 + 0x60) == *(int *)*puVar8) &&
           (uVar3 = ((int *)*puVar8)[2], local_10 <= uVar3)) {
          local_10 = uVar3 + 1;
        }
        puVar8 = puVar8 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    uVar3 = *(int *)(param_1 + 0xc) + local_10;
    local_3c = _malloc(uVar3 * 4);
    if (local_3c == (uint *)0x0) {
LAB_005ff6d1:
      iVar2 = -0x7ff8fff2;
    }
    else {
      puVar10 = local_3c;
      for (uVar3 = uVar3 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined1 *)puVar10 = 0;
        puVar10 = (uint *)((int)puVar10 + 1);
      }
      uVar3 = 0;
      if (*(int *)(param_1 + 8) != 0) {
        do {
          piVar6 = *(int **)(*(int *)(param_1 + 0x14) + uVar3 * 4);
          if (*(int *)(param_1 + 0x60) == *piVar6) {
            if (local_3c[piVar6[2]] <= (uint)piVar6[3]) {
              local_3c[piVar6[2]] = piVar6[3] + 1;
            }
          }
          piVar6[8] = -1;
          uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint *)(param_1 + 8));
      }
      local_54 = *(uint *)(param_1 + 0xc);
      local_34 = 0;
      if (local_54 != 0) {
LAB_005ff72f:
        puVar10 = *(uint **)(*(int *)(param_1 + 0x18) + local_34 * 4);
        iVar2 = FUN_005f7a96();
        if (iVar2 == 0) {
          local_2c = (uint *)0x0;
          local_30 = (uint *)0x0;
          iVar2 = FUN_005f7aa3();
          if (iVar2 == 0) {
            local_2c = local_3c;
          }
          iVar2 = FUN_005f7b57();
          if (iVar2 != 0) {
            local_30 = &local_10;
          }
          if ((((*(byte *)(param_1 + 0x90) & 1) != 0) && (iVar2 = FUN_005f7aa3(), iVar2 != 0)) &&
             ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) +
                                 **(int **)(*(int *)(param_1 + 0x14) + *(int *)puVar10[4] * 4) * 4)
                        + 4) & 0x10) != 0)) {
            local_2c = local_3c;
            local_30 = &local_10;
          }
          iVar2 = 0;
          while (iVar4 = FUN_005f7a5c(iVar2,&local_40), iVar4 != 0) {
            iVar4 = FUN_005faf93(local_40,iVar4,local_2c,local_30,puVar10,0xffffffff);
            if (iVar4 == 0) {
              iVar2 = FUN_005f7b57();
              if (iVar2 == 0) {
                local_c = 0;
                local_8 = (uint *)FUN_005f7a5c(0,0);
                if (local_8 == (uint *)0x0) {
                  local_14 = (uint *)0x0;
                }
                else {
                  local_14 = (uint *)(puVar10[1] / (uint)local_8);
                }
                local_24 = (uint *)0x0;
                if (local_8 == (uint *)0x0) goto LAB_005ff83f;
                local_20 = 0;
                goto LAB_005ff8a3;
              }
              break;
            }
            iVar2 = iVar2 + 1;
          }
          iVar2 = FUN_005f752b(*puVar10,puVar10[1],puVar10[3]);
          if (iVar2 == -1) goto LAB_005ffbcb;
          puVar5 = *(uint **)(*(int *)(local_28 + 0x18) + iVar2 * 4);
          local_50 = puVar5;
          FUN_005f7a42();
          puVar8 = (undefined4 *)puVar10[2];
          puVar11 = (undefined4 *)puVar5[2];
          for (uVar3 = puVar10[1] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar11 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar11 = puVar11 + 1;
          }
          for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          puVar8 = (undefined4 *)puVar10[4];
          puVar11 = (undefined4 *)local_50[4];
          for (uVar3 = puVar10[3] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar11 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar11 = puVar11 + 1;
          }
          for (iVar2 = 0; param_1 = local_28, iVar2 != 0; iVar2 = iVar2 + -1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          goto LAB_005ff83f;
        }
        goto LAB_005ff842;
      }
LAB_005ff851:
      iVar2 = 0;
LAB_005ff853:
      _free(local_3c);
    }
  }
  return iVar2;
LAB_005ff8a3:
  do {
    local_48 = (uint *)(local_20 + puVar10[2]);
    if (*local_48 != 0xffffffff) {
      local_4c = (uint *)((int)local_24 + 1);
      local_1c = (uint *)0x1;
      if (local_4c < local_8) {
        local_2c = (uint *)(puVar10[2] + local_20 + 4);
        iVar2 = (local_20 + 4) - local_20;
        local_44 = (int)local_8 - (int)local_4c;
        do {
          if (*local_2c != 0xffffffff) {
            local_18 = (uint *)0x0;
            puVar5 = local_48;
            if (local_14 != (uint *)0x0) {
              do {
                piVar6 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)(iVar2 + (int)puVar5) * 4);
                piVar1 = *(int **)(*(int *)(param_1 + 0x14) + *puVar5 * 4);
                local_30 = puVar5;
                if (((*piVar1 != *piVar6) || (piVar1[1] != piVar6[1])) || (piVar1[2] != piVar6[2]))
                break;
                local_18 = (uint *)((int)local_18 + 1);
                local_30 = puVar5 + (int)local_8;
                puVar5 = local_30;
              } while (local_18 < local_14);
            }
            if (local_18 == local_14) {
              local_1c = (uint *)((int)local_1c + 1);
            }
          }
          local_2c = local_2c + 1;
          iVar2 = iVar2 + 4;
          local_44 = local_44 + -1;
        } while (local_44 != 0);
      }
      iVar2 = FUN_005f752b((*puVar10 ^ (uint)local_1c) & 0xffffff ^ *puVar10,0xffffffff,0xffffffff);
      if (iVar2 == -1) goto LAB_005ffbcb;
      puVar5 = *(uint **)(*(int *)(param_1 + 0x18) + iVar2 * 4);
      local_4c = puVar5;
      FUN_005f7a42();
      local_18 = local_8;
      if (local_24 < local_8) {
        local_30 = (uint *)((int)local_1c * 4 + -4);
        local_44 = (int)local_8 * 4 - local_20;
        do {
          local_18 = (uint *)((int)local_18 + -1);
          local_44 = local_44 + -4;
          if (*(int *)(puVar10[2] + (int)local_18 * 4) != -1) {
            local_2c = (uint *)0x0;
            if (local_14 != (uint *)0x0) {
              piVar6 = (int *)(puVar10[2] + local_20);
              do {
                local_50 = *(uint **)(*(int *)(param_1 + 0x14) +
                                     *(int *)(local_44 + (int)piVar6) * 4);
                local_48 = *(uint **)(*(int *)(param_1 + 0x14) + *piVar6 * 4);
                if (((*local_48 != *local_50) || (local_48[1] != local_50[1])) ||
                   (local_48[2] != local_50[2])) break;
                local_2c = (uint *)((int)local_2c + 1);
                piVar6 = piVar6 + (int)local_8;
              } while (local_2c < local_14);
              if (local_2c < local_14) goto LAB_005ffa88;
              local_2c = (uint *)0x0;
              local_48 = local_14;
              puVar9 = local_30;
              do {
                puVar8 = (undefined4 *)((int)local_2c + (int)local_18 * 4 + puVar10[2]);
                *(undefined4 *)((int)puVar9 + puVar5[2]) = *puVar8;
                *puVar8 = 0xffffffff;
                local_2c = local_2c + (int)local_8;
                puVar9 = puVar9 + (int)local_1c;
                local_48 = (uint *)((int)local_48 + -1);
                puVar5 = local_4c;
              } while (local_48 != (uint *)0x0);
            }
            iVar2 = FUN_005f7ac7();
            if (iVar2 == 0) {
              *(undefined4 *)((int)local_30 + puVar5[4]) =
                   *(undefined4 *)(puVar10[4] + (int)local_18 * 4);
            }
            local_30 = local_30 + -1;
          }
LAB_005ffa88:
        } while (local_24 < local_18);
      }
      iVar2 = FUN_005f7ac7();
      if (iVar2 != 0) {
        if (local_1c == local_8) {
          *(undefined4 *)puVar5[4] = *(undefined4 *)puVar10[4];
        }
        else {
          uVar7 = FUN_005f74cf(*(undefined4 *)(param_1 + 0x60),local_10,local_c,0);
          local_64[local_c] = uVar7;
          *(undefined4 *)puVar5[4] = uVar7;
          if (*(int *)puVar5[4] == -1) goto LAB_005ffbcb;
          local_c = local_c + 1;
        }
        iVar2 = FUN_005f974c(puVar5,0);
        if (iVar2 < 0) {
          return iVar2;
        }
      }
    }
    local_24 = (uint *)((int)local_24 + 1);
    local_20 = local_20 + 4;
  } while (local_24 < local_8);
  if (local_c != 0) {
    if (local_c == 2) {
      uVar3 = 0x24000001;
    }
    else {
      uVar3 = local_c & 0xffffff | 0x30000000;
    }
    iVar2 = FUN_005f752b(uVar3,0xffffffff,0xffffffff);
    if (iVar2 == -1) goto LAB_005ff6d1;
    puVar5 = *(uint **)(*(int *)(local_28 + 0x18) + iVar2 * 4);
    local_50 = puVar5;
    FUN_005f7a42();
    *(undefined4 *)puVar5[4] = *(undefined4 *)puVar10[4];
    puVar8 = local_64;
    puVar11 = (undefined4 *)puVar5[2];
    for (uVar3 = local_c & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar11 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar11 = puVar11 + 1;
    }
    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined1 *)puVar11 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    if (local_c != 2) {
      if ((local_38 == -1) &&
         (local_38 = FUN_005f74cf(*(undefined4 *)(local_28 + 0x50),0,0,0x3ff0000000000000),
         local_38 == -1)) {
LAB_005ffbcb:
        iVar2 = -0x7ff8fff2;
        goto LAB_005ff853;
      }
      if (local_c != 0) {
        iVar2 = local_c << 2;
        uVar3 = local_c;
        do {
          *(int *)(iVar2 + local_50[2]) = local_38;
          iVar2 = iVar2 + 4;
          uVar3 = uVar3 - 1;
        } while (uVar3 != 0);
      }
    }
    local_10 = local_10 + 1;
    param_1 = local_28;
  }
LAB_005ff83f:
  *puVar10 = 0;
LAB_005ff842:
  local_34 = local_34 + 1;
  if (local_54 <= local_34) goto LAB_005ff851;
  goto LAB_005ff72f;
}


// ==== 0x5ffbd5 FUN_005ffbd5

int * __fastcall FUN_005ffbd5(int *param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  int *piVar5;
  uint *puVar6;
  int *piVar7;
  void *pvVar8;
  undefined4 *puVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  bool bVar15;
  undefined8 uVar16;
  ulonglong uVar17;
  longlong lVar18;
  int aiStack_cc [4];
  int aiStack_bc [4];
  int aiStack_ac [4];
  uint local_9c [4];
  uint local_8c [8];
  int local_6c [4];
  undefined1 local_5c [16];
  int local_4c;
  uint local_48;
  undefined4 *local_44;
  uint *local_40;
  int *local_3c;
  uint *local_38;
  int *local_34;
  int *local_30;
  uint *local_2c;
  uint *local_28;
  uint *local_24;
  uint *local_20;
  int *local_1c;
  uint *local_18;
  int *local_14;
  uint *local_10;
  uint *local_c;
  uint *local_8;
  
  puVar1 = local_8c + 4;
  local_8 = (uint *)0x0;
  FUN_005fb8ae();
  local_18 = (uint *)0x0;
  local_44 = (undefined4 *)0x0;
  if (param_1[2] != 0) {
    puVar9 = (undefined4 *)param_1[5];
    iVar12 = param_1[2];
    do {
      if ((param_1[0x18] == *(int *)*puVar9) &&
         (puVar4 = (uint *)((int *)*puVar9)[2], local_18 <= puVar4)) {
        local_18 = (uint *)((int)puVar4 + 1);
      }
      puVar9 = puVar9 + 1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  if ((*(byte *)(param_1 + 0x24) & 1) != 0) {
    local_2c = (uint *)param_1[3];
    local_20 = (uint *)0x0;
    if ((uint *)param_1[3] != (uint *)0x0) {
      do {
        iVar12 = *(int *)(param_1[6] + (int)local_20 * 4);
        iVar2 = FUN_005f7a96();
        if (((iVar2 == 0) && (*(uint *)(iVar12 + 0xc) != 0)) &&
           ((*(byte *)(*(int *)(param_1[4] +
                               **(int **)(param_1[5] + **(int **)(iVar12 + 0x10) * 4) * 4) + 4) &
            0x10) != 0)) {
          uVar11 = 0;
          bVar15 = *(int *)(iVar12 + 4) == 0;
          if (*(int *)(iVar12 + 4) != 0) {
            local_14 = *(int **)(iVar12 + 8);
            do {
              if (uVar11 != *(uint *)(*(int *)(param_1[5] + *local_14 * 4) + 0xc)) break;
              local_14 = local_14 + 1;
              uVar11 = uVar11 + 1;
            } while (uVar11 < *(uint *)(iVar12 + 4));
            bVar15 = uVar11 == *(uint *)(iVar12 + 4);
          }
          if (!bVar15) {
            iVar2 = FUN_005f752b(*(uint *)(iVar12 + 0xc) & 0xffffff | 0x10000000,0xffffffff,
                                 0xffffffff);
            if (iVar2 == -1) goto LAB_00600f8c;
            local_14 = *(int **)(param_1[6] + iVar2 * 4);
            FUN_005f7a42();
            local_10 = (uint *)0x0;
            if (*(int *)(iVar12 + 0xc) != 0) {
              do {
                iVar2 = (int)local_10 * 4;
                *(undefined4 *)(iVar2 + local_14[4]) =
                     *(undefined4 *)(iVar2 + *(int *)(iVar12 + 0x10));
                uVar3 = FUN_005f74cf(param_1[0x18],local_18,local_10,0);
                *(undefined4 *)(iVar2 + *(int *)(iVar12 + 0x10)) = uVar3;
                *(undefined4 *)(iVar2 + local_14[2]) =
                     *(undefined4 *)(iVar2 + *(int *)(iVar12 + 0x10));
                if (*(int *)(iVar2 + local_14[2]) == -1) goto LAB_00600f8c;
                local_10 = (uint *)((int)local_10 + 1);
                *(undefined4 *)(*(int *)(param_1[5] + *(int *)(iVar2 + local_14[2]) * 4) + 0x18) =
                     *(undefined4 *)
                      (*(int *)(param_1[5] + *(int *)(iVar2 + local_14[4]) * 4) + 0x18);
              } while (local_10 < *(uint **)(iVar12 + 0xc));
            }
            local_18 = (uint *)((int)local_18 + 1);
            local_8 = (uint *)0x1;
          }
        }
        local_20 = (uint *)((int)local_20 + 1);
      } while (local_20 < local_2c);
    }
  }
  if (((*(byte *)((int)param_1 + 0x93) & 2) != 0) && (local_c = (uint *)0x0, param_1[3] != 0)) {
    do {
      local_20 = *(uint **)(param_1[6] + (int)local_c * 4);
      iVar12 = FUN_005f7b45();
      if (iVar12 != 0) {
        local_14 = (int *)0x1;
        uVar16 = CONCAT44(&local_1c,1);
        while( true ) {
          local_24 = (uint *)FUN_005f7a5c(uVar16);
          if (local_24 == (uint *)0x0) break;
          puVar4 = (uint *)0x0;
          if (local_24 != (uint *)0x0) {
            do {
              if (*(uint **)(*(int *)(param_1[5] + local_1c[(int)puVar4] * 4) + 0xc) != puVar4)
              break;
              puVar4 = (uint *)((int)puVar4 + 1);
            } while (puVar4 < local_24);
          }
          if (puVar4 != local_24) {
            puVar4 = (uint *)FUN_005f752b((uint)local_24 & 0xffffff | 0x10000000,0xffffffff,
                                          0xffffffff);
            local_2c = puVar4;
            if (puVar4 == (uint *)0xffffffff) goto LAB_00600f8c;
            iVar12 = *(int *)(param_1[6] + (int)puVar4 * 4);
            FUN_005f7a42();
            local_10 = (uint *)0x0;
            if (local_24 != (uint *)0x0) {
              do {
                puVar4 = local_10;
                iVar13 = (int)local_10 * 4;
                *(int *)(iVar13 + *(int *)(iVar12 + 8)) = local_1c[(int)local_10];
                iVar2 = FUN_005f74cf(param_1[0x18],local_18,local_10,0);
                local_1c[(int)puVar4] = iVar2;
                *(int *)(iVar13 + *(int *)(iVar12 + 0x10)) = local_1c[(int)puVar4];
                iVar2 = *(int *)(iVar13 + *(int *)(iVar12 + 0x10));
                if (iVar2 == -1) goto LAB_00600f8c;
                local_10 = (uint *)((int)local_10 + 1);
                *(undefined4 *)(*(int *)(param_1[5] + iVar2 * 4) + 0x18) =
                     *(undefined4 *)
                      (*(int *)(param_1[5] + *(int *)(iVar13 + *(int *)(iVar12 + 8)) * 4) + 0x18);
                puVar4 = local_2c;
              } while (local_10 < local_24);
            }
            for (; local_c < puVar4; puVar4 = (uint *)((int)puVar4 + -1)) {
              puVar9 = (undefined4 *)(param_1[6] + (int)puVar4 * 4);
              *puVar9 = puVar9[-1];
            }
            local_c = (uint *)((int)local_c + 1);
            local_18 = (uint *)((int)local_18 + 1);
            *(int *)(param_1[6] + (int)puVar4 * 4) = iVar12;
            local_8 = (uint *)0x1;
          }
          local_14 = (int *)((int)local_14 + 1);
          uVar16 = CONCAT44(&local_1c,local_14);
        }
      }
      local_c = (uint *)((int)local_c + 1);
    } while (local_c < (uint *)param_1[3]);
  }
  local_c = (uint *)0x0;
  if (param_1[3] != 0) {
    do {
      local_20 = *(uint **)(param_1[6] + (int)local_c * 4);
      if ((*local_20 & 0xff000000) == 0x34000000) {
        if (local_20[1] == 4) {
          piVar5 = (int *)local_20[2];
          iVar12 = param_1[5];
          local_2c = *(uint **)(iVar12 + *piVar5 * 4);
          if ((((*(byte *)(*(int *)(param_1[4] + *local_2c * 4) + 5) & 1) == 0) &&
              (local_2c[3] == 0)) &&
             ((*(int *)(*(int *)(iVar12 + piVar5[1] * 4) + 0xc) == 1 &&
              ((*(int *)(*(int *)(iVar12 + piVar5[2] * 4) + 0xc) == 2 &&
               (*(int *)(*(int *)(iVar12 + piVar5[3] * 4) + 0xc) == 3)))))) goto LAB_00600068;
        }
        puVar4 = (uint *)FUN_005f752b(0x10000004,0xffffffff,0xffffffff);
        local_2c = puVar4;
        iVar12 = FUN_005f752b(0x34000004,0xffffffff,0xffffffff);
        if ((puVar4 == (uint *)0xffffffff) || (iVar12 == -1)) goto LAB_00600f8c;
        iVar2 = *(int *)(param_1[6] + (int)puVar4 * 4);
        local_14 = *(int **)(param_1[6] + iVar12 * 4);
        FUN_005f7a42();
        FUN_005f7a42();
        local_8 = (uint *)0x0;
        do {
          if (local_8 < (uint *)local_20[1]) {
            uVar3 = *(undefined4 *)(local_20[2] + (int)local_8 * 4);
          }
          else {
            uVar3 = *(undefined4 *)((local_20[2] - 4) + (int)local_20[1] * 4);
          }
          iVar13 = (int)local_8 * 4;
          *(undefined4 *)(iVar13 + *(int *)(iVar2 + 8)) = uVar3;
          uVar3 = FUN_005f74cf(param_1[0x18],local_18,local_8,0);
          *(undefined4 *)(iVar13 + local_14[2]) = uVar3;
          *(undefined4 *)(iVar13 + *(int *)(iVar2 + 0x10)) = *(undefined4 *)(iVar13 + local_14[2]);
          iVar12 = *(int *)(iVar13 + *(int *)(iVar2 + 0x10));
          if (iVar12 == -1) goto LAB_00600f8c;
          local_8 = (uint *)((int)local_8 + 1);
          *(undefined4 *)(*(int *)(param_1[5] + iVar12 * 4) + 0x18) =
               *(undefined4 *)
                (*(int *)(param_1[5] + *(int *)(iVar13 + *(int *)(iVar2 + 8)) * 4) + 0x18);
          puVar4 = local_2c;
        } while (local_8 < (uint *)0x4);
        for (; local_c < puVar4; puVar4 = (uint *)((int)puVar4 + -1)) {
          puVar9 = (undefined4 *)(param_1[6] + (int)puVar4 * 4);
          *puVar9 = puVar9[-1];
        }
        *(int *)(param_1[6] + (int)local_c * 4) = iVar2;
        puVar4 = (uint *)((int)local_c + 1);
        local_c = puVar4;
        FUN_005f7186();
        param_1[3] = param_1[3] + -1;
        local_18 = (uint *)((int)local_18 + 1);
        *(int **)(param_1[6] + (int)puVar4 * 4) = local_14;
        local_8 = (uint *)0x1;
      }
LAB_00600068:
      local_c = (uint *)((int)local_c + 1);
    } while (local_c < (uint *)param_1[3]);
  }
  if ((*(byte *)(param_1 + 0x24) & 6) != 0) {
    local_1c = (int *)0x0;
    if (param_1[3] != 0) {
      do {
        puVar4 = *(uint **)(param_1[6] + (int)local_1c * 4);
        local_40 = puVar4;
        if (((*puVar4 & 0xff000000) == 0x10000000) &&
           (iVar12 = param_1[5],
           (*(byte *)(*(int *)(param_1[4] + **(int **)(iVar12 + *(int *)puVar4[4] * 4) * 4) + 4) &
           0x10) == 0)) {
          local_10 = (uint *)0x0;
          if (puVar4[3] != 0) {
            local_2c = *(uint **)(*(int *)(iVar12 + *(int *)puVar4[2] * 4) + 0x2c);
            local_14 = (int *)puVar4[2];
            do {
              if (local_2c != *(uint **)(*(int *)(iVar12 + *local_14 * 4) + 0x2c)) break;
              local_10 = (uint *)((int)local_10 + 1);
              local_14 = local_14 + 1;
            } while (local_10 < (uint *)puVar4[3]);
          }
          if (local_10 != (uint *)puVar4[3]) {
            puVar6 = (uint *)puVar4[1];
            local_c = (uint *)0x0;
            local_8 = (uint *)0x0;
            if (puVar6 != (uint *)0x0) {
              do {
                piVar5 = (int *)(puVar4[2] + (int)local_8 * 4);
                iVar12 = *piVar5;
                if (iVar12 != -1) {
                  local_28 = *(uint **)(*(int *)(param_1[5] + iVar12 * 4) + 0x2c);
                  uVar11 = 0;
                  if (local_8 < puVar6) {
                    local_20 = (uint *)((int)puVar6 - (int)local_8);
                    local_14 = piVar5;
                    do {
                      if ((*local_14 != -1) &&
                         (local_28 == *(uint **)(*(int *)(param_1[5] + *local_14 * 4) + 0x2c))) {
                        uVar11 = uVar11 + 1;
                      }
                      local_14 = local_14 + 1;
                      local_20 = (uint *)((int)local_20 + -1);
                    } while (local_20 != (uint *)0x0);
                  }
                  iVar12 = FUN_005f752b(uVar11 & 0xffffff | 0x10000000,0xffffffff,0xffffffff);
                  if (iVar12 == -1) goto LAB_00600f8c;
                  piVar5 = *(int **)(param_1[6] + iVar12 * 4);
                  local_30 = piVar5;
                  FUN_005f7a42();
                  local_c = (uint *)((int)local_c + 1);
                  local_10 = local_8;
                  if (local_8 < (uint *)puVar4[1]) {
                    local_20 = (uint *)0x0;
                    do {
                      iVar12 = (int)local_10 * 4;
                      if ((*(int *)(iVar12 + puVar4[2]) != -1) &&
                         (local_28 ==
                          *(uint **)(*(int *)(param_1[5] + *(int *)(iVar12 + puVar4[2]) * 4) + 0x2c)
                         )) {
                        *(undefined4 *)((int)local_20 + piVar5[4]) =
                             *(undefined4 *)(iVar12 + puVar4[4]);
                        *(undefined4 *)((int)local_20 + local_30[2]) =
                             *(undefined4 *)(iVar12 + puVar4[2]);
                        *(undefined4 *)(iVar12 + puVar4[2]) = 0xffffffff;
                        local_20 = local_20 + 1;
                        piVar5 = local_30;
                      }
                      local_10 = (uint *)((int)local_10 + 1);
                    } while (local_10 < (uint *)puVar4[1]);
                  }
                }
                local_8 = (uint *)((int)local_8 + 1);
                puVar6 = (uint *)puVar4[1];
              } while (local_8 < puVar6);
              if (local_c != (uint *)0x0) {
                puVar6 = (uint *)(param_1[6] + (param_1[3] - (int)local_c) * 4);
                puVar10 = puVar1;
                for (puVar4 = local_c; puVar4 != (uint *)0x0; puVar4 = (uint *)((int)puVar4 - 1)) {
                  *puVar10 = *puVar6;
                  puVar6 = puVar6 + 1;
                  puVar10 = puVar10 + 1;
                }
              }
            }
            piVar5 = (int *)(param_1[3] + -1);
            if (local_1c < piVar5) {
              iVar12 = ((int)piVar5 - (int)local_c) * 4;
              do {
                puVar9 = (undefined4 *)(param_1[6] + iVar12);
                iVar12 = iVar12 + -4;
                piVar5 = (int *)((int)piVar5 + -1);
                *(undefined4 *)(param_1[6] + (int)piVar5 * 4) = *puVar9;
              } while (local_1c < piVar5);
            }
            puVar4 = (uint *)0x0;
            if (local_c != (uint *)0x0) {
              iVar12 = (int)local_1c << 2;
              do {
                *(uint *)(iVar12 + param_1[6]) = puVar1[(int)puVar4];
                puVar4 = (uint *)((int)puVar4 + 1);
                iVar12 = iVar12 + 4;
              } while (puVar4 < local_c);
            }
            FUN_005f7186();
            param_1[3] = param_1[3] + -1;
            local_1c = (int *)((int)local_1c + -1 + (int)local_c);
            local_8 = (uint *)0x1;
          }
        }
        local_1c = (int *)((int)local_1c + 1);
      } while (local_1c < (int *)param_1[3]);
    }
    local_1c = (int *)0x0;
    if (param_1[3] != 0) {
      do {
        puVar4 = *(uint **)((int)local_1c * 4 + param_1[6]);
        local_2c = puVar4;
        if ((*puVar4 & 0xff000000) == 0x10000000) {
          iVar12 = param_1[5];
          if ((*(byte *)(*(int *)(param_1[4] + **(int **)(iVar12 + *(int *)puVar4[4] * 4) * 4) + 4)
              & 0x10) == 0) {
            puVar10 = (uint *)0x0;
            local_10 = (uint *)0x0;
            local_c = (uint *)0x0;
            puVar6 = (uint *)0x0;
            if (puVar4[3] != 0) {
              local_34 = (int *)puVar4[2];
              local_14 = (int *)((int)puVar4[4] - (int)local_34);
              do {
                local_20 = *(uint **)(*(int *)(iVar12 + *local_34 * 4) + 0xc);
                if (*(uint **)(*(int *)(iVar12 + *(int *)((int)local_14 + (int)local_34) * 4) + 0xc)
                    == local_20) {
                  puVar10 = (uint *)((int)puVar10 + 1);
                }
                local_24 = (uint *)0x0;
                if (local_c != (uint *)0x0) {
                  local_38 = (uint *)puVar4[2];
                  do {
                    if (*(uint **)(*(int *)(iVar12 + *local_38 * 4) + 0xc) == local_20) {
                      local_10 = (uint *)((int)local_10 + 1);
                      break;
                    }
                    local_24 = (uint *)((int)local_24 + 1);
                    local_38 = local_38 + 1;
                  } while (local_24 < local_c);
                }
                local_c = (uint *)((int)local_c + 1);
                puVar6 = (uint *)puVar4[3];
                local_34 = local_34 + 1;
              } while (local_c < puVar6);
            }
            if (((puVar10 != puVar6) && ((uint *)((int)local_10 + 1U) != puVar6)) &&
               (((uint *)0x1 < puVar10 || (local_10 != (uint *)0x0)))) {
              local_c = (uint *)0x0;
              if ((uint *)0x1 < puVar10) {
                iVar12 = FUN_005f752b((uint)puVar10 & 0xffffff | 0x10000000,0xffffffff,0xffffffff);
                if (iVar12 == -1) goto LAB_00600f8c;
                local_20 = *(uint **)(param_1[6] + iVar12 * 4);
                FUN_005f7a42();
                local_c = (uint *)0x1;
                local_10 = (uint *)0x0;
                if (puVar4[3] != 0) {
                  local_28 = (uint *)0x0;
                  do {
                    iVar12 = (int)local_10 * 4;
                    if (*(int *)(*(int *)(param_1[5] + *(int *)(iVar12 + puVar4[4]) * 4) + 0xc) ==
                        *(int *)(*(int *)(param_1[5] + *(int *)(iVar12 + puVar4[2]) * 4) + 0xc)) {
                      *(int *)((int)local_28 + local_20[4]) = *(int *)(iVar12 + puVar4[4]);
                      *(undefined4 *)((int)local_28 + local_20[2]) =
                           *(undefined4 *)(iVar12 + puVar4[2]);
                      *(undefined4 *)(iVar12 + puVar4[2]) = 0xffffffff;
                      local_28 = local_28 + 1;
                    }
                    local_10 = (uint *)((int)local_10 + 1);
                  } while (local_10 < (uint *)puVar4[3]);
                }
              }
              puVar6 = (uint *)puVar4[1];
              local_8 = (uint *)0x0;
              if (puVar6 != (uint *)0x0) {
                do {
                  piVar5 = (int *)(puVar4[2] + (int)local_8 * 4);
                  iVar12 = *piVar5;
                  if (iVar12 != -1) {
                    local_28 = *(uint **)(*(int *)(param_1[5] + iVar12 * 4) + 0xc);
                    uVar11 = 0;
                    if (local_8 < puVar6) {
                      local_20 = (uint *)((int)puVar6 - (int)local_8);
                      local_34 = piVar5;
                      do {
                        if ((*local_34 != -1) &&
                           (local_28 == *(uint **)(*(int *)(param_1[5] + *local_34 * 4) + 0xc))) {
                          uVar11 = uVar11 + 1;
                        }
                        local_34 = local_34 + 1;
                        local_20 = (uint *)((int)local_20 + -1);
                      } while (local_20 != (uint *)0x0);
                    }
                    iVar12 = FUN_005f752b(uVar11 & 0xffffff | 0x10000000,0xffffffff,0xffffffff);
                    if (iVar12 == -1) goto LAB_00600f8c;
                    piVar5 = *(int **)(param_1[6] + iVar12 * 4);
                    local_30 = piVar5;
                    FUN_005f7a42();
                    local_c = (uint *)((int)local_c + 1);
                    local_10 = local_8;
                    if (local_8 < (uint *)puVar4[1]) {
                      local_20 = (uint *)0x0;
                      do {
                        iVar12 = (int)local_10 * 4;
                        if ((*(int *)(iVar12 + puVar4[2]) != -1) &&
                           (local_28 ==
                            *(uint **)(*(int *)(param_1[5] + *(int *)(iVar12 + puVar4[2]) * 4) + 0xc
                                      ))) {
                          *(undefined4 *)((int)local_20 + piVar5[4]) =
                               *(undefined4 *)(iVar12 + puVar4[4]);
                          *(undefined4 *)((int)local_20 + local_30[2]) =
                               *(undefined4 *)(iVar12 + puVar4[2]);
                          *(undefined4 *)(iVar12 + puVar4[2]) = 0xffffffff;
                          local_20 = local_20 + 1;
                          piVar5 = local_30;
                        }
                        local_10 = (uint *)((int)local_10 + 1);
                      } while (local_10 < (uint *)puVar4[1]);
                    }
                  }
                  local_8 = (uint *)((int)local_8 + 1);
                  puVar6 = (uint *)puVar4[1];
                } while (local_8 < puVar6);
              }
              if (local_c != (uint *)0x0) {
                puVar6 = (uint *)(param_1[6] + (param_1[3] - (int)local_c) * 4);
                puVar10 = puVar1;
                for (puVar4 = local_c; puVar4 != (uint *)0x0; puVar4 = (uint *)((int)puVar4 - 1)) {
                  *puVar10 = *puVar6;
                  puVar6 = puVar6 + 1;
                  puVar10 = puVar10 + 1;
                }
              }
              piVar5 = (int *)(param_1[3] + -1);
              if (local_1c < piVar5) {
                iVar12 = ((int)piVar5 - (int)local_c) * 4;
                do {
                  puVar9 = (undefined4 *)(param_1[6] + iVar12);
                  iVar12 = iVar12 + -4;
                  piVar5 = (int *)((int)piVar5 + -1);
                  *(undefined4 *)(param_1[6] + (int)piVar5 * 4) = *puVar9;
                } while (local_1c < piVar5);
              }
              puVar4 = (uint *)0x0;
              if (local_c != (uint *)0x0) {
                iVar12 = (int)local_1c << 2;
                do {
                  *(uint *)(iVar12 + param_1[6]) = puVar1[(int)puVar4];
                  puVar4 = (uint *)((int)puVar4 + 1);
                  iVar12 = iVar12 + 4;
                } while (puVar4 < local_c);
              }
              FUN_005f7186();
              param_1[3] = param_1[3] + -1;
              local_1c = (int *)((int)local_1c + -1 + (int)local_c);
              local_8 = (uint *)0x1;
            }
          }
        }
        local_1c = (int *)((int)local_1c + 1);
      } while (local_1c < (int *)param_1[3]);
    }
  }
  if (local_8 != (uint *)0x0) {
    FUN_005fb8ae();
  }
  puVar4 = local_18;
  local_44 = _malloc((int)local_18 << 2);
  if (local_44 == (undefined4 *)0x0) {
LAB_00600f8c:
    local_14 = (int *)0x8007000e;
  }
  else {
    puVar9 = local_44;
    for (uVar11 = (uint)puVar4 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    uVar11 = 0;
    for (iVar12 = 0; iVar12 != 0; iVar12 = iVar12 + -1) {
      *(undefined1 *)puVar9 = 0;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    if (param_1[2] != 0) {
      do {
        piVar5 = *(int **)(param_1[5] + uVar11 * 4);
        piVar5[0x10] = 0;
        if (param_1[0x18] == *piVar5) {
          if ((uint)local_44[piVar5[2]] <= (uint)piVar5[3]) {
            local_44[piVar5[2]] = piVar5[3] + 1;
          }
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < (uint)param_1[2]);
    }
    puVar4 = (uint *)param_1[3];
    while (puVar4 != (uint *)0x0) {
      local_20 = (uint *)((int)puVar4 + -1);
      puVar6 = *(uint **)(param_1[6] + (int)local_20 * 4);
      iVar12 = FUN_005f7a96();
      puVar4 = local_20;
      if (iVar12 == 0) {
        uVar11 = *puVar6;
        uVar14 = uVar11 & 0xffffff;
        if (puVar6[3] != 0) {
          iVar12 = FUN_005f7ad9();
          if (iVar12 == 0) {
            iVar12 = FUN_005f7b0f();
            if (iVar12 == 0) {
              iVar12 = FUN_005f7b21();
              if (iVar12 == 0) {
                iVar12 = FUN_005f7b33();
                if (iVar12 == 0) goto LAB_00600766;
                FUN_005fb7cf(puVar6[4],local_5c,uVar14,1);
                FUN_005fb7cf(puVar6[2],local_5c,uVar14,0);
                FUN_005fb7cf(puVar6[2] + puVar6[3] * 4,local_5c,uVar14,0);
                uVar14 = puVar6[2] + puVar6[3] * 8;
              }
              else {
                FUN_005fb7cf(puVar6[4],local_5c,uVar14,1);
                FUN_005fb7cf(puVar6[2],local_5c,uVar14,0);
                uVar14 = puVar6[2] + puVar6[3] * 4;
              }
              uVar17 = (ulonglong)uVar11 & 0xffffffff00ffffff;
            }
            else {
              FUN_005fb7cf(puVar6[4],local_5c,uVar14,1);
              uVar17 = (ulonglong)uVar11 & 0xffffffff00ffffff;
              uVar14 = puVar6[2];
            }
          }
          else {
            uVar17 = CONCAT44(1,uVar11) & 0xffffffff00ffffff;
            uVar14 = puVar6[4];
          }
          FUN_005fb7cf(uVar14,local_5c,uVar17);
        }
LAB_00600766:
        local_6c[0] = 0;
        local_6c[1] = 0;
        local_6c[2] = 0;
        local_6c[3] = 0;
        iVar12 = FUN_005f7aa3();
        if (iVar12 != 0) {
          iVar12 = param_1[5];
          local_30 = *(int **)(iVar12 + *(int *)puVar6[4] * 4);
          uVar11 = *(uint *)(*(int *)(param_1[4] + *local_30 * 4) + 4);
          if ((((uVar11 & 4) == 0) &&
              ((((*(byte *)(param_1 + 0x24) & 1) == 0 || ((uVar11 & 0x10) == 0)) &&
               (param_1[0x18] == **(int **)(iVar12 + *(int *)puVar6[2] * 4))))) &&
             (local_8 = (uint *)0x0, puVar6[1] != 0)) {
            local_34 = (int *)((int)puVar6[2] - (int)local_6c);
            local_2c = (uint *)(param_1[0xd] & 8);
            do {
              iVar2 = *(int *)(iVar12 + *(int *)((int)local_6c + (int)(local_34 + (int)local_8)) * 4
                              );
              iVar13 = *(int *)(param_1[6] + *(int *)(iVar2 + 0x2c) * 4);
              if (((local_2c != (uint *)0x0) && (local_30[0x11] != 0)) &&
                 ((iVar2 = *(int *)(iVar2 + 0x44), iVar2 != 0 && (local_30[0x11] != iVar2)))) break;
              local_28 = *(uint **)(iVar13 + 0xc);
              local_10 = (uint *)0x0;
              if (local_28 != (uint *)0x0) {
                piVar5 = *(int **)(iVar13 + 0x10);
                do {
                  iVar2 = *(int *)(iVar12 + *piVar5 * 4);
                  if ((local_20 != *(uint **)(iVar2 + 0x38)) ||
                     (local_20 != *(uint **)(iVar2 + 0x3c))) break;
                  local_10 = (uint *)((int)local_10 + 1);
                  piVar5 = piVar5 + 1;
                } while (local_10 < local_28);
              }
              if (local_10 == local_28) {
                local_6c[(int)local_8] = 1;
              }
              local_8 = (uint *)((int)local_8 + 1);
            } while (local_8 < (uint *)puVar6[1]);
          }
        }
        iVar12 = FUN_005f7b0f();
        if ((iVar12 == 0) && (iVar12 = FUN_005f7b21(), iVar12 == 0)) {
          iVar12 = FUN_005f7b33();
          uVar11 = 0;
          if (iVar12 != 0) goto LAB_00600897;
          do {
            local_9c[uVar11] = uVar11;
            uVar11 = uVar11 + 1;
          } while (uVar11 < 4);
        }
        else {
LAB_00600897:
          local_10 = (uint *)0x0;
          if (puVar6[3] != 0) {
            uVar11 = puVar6[4];
            iVar12 = param_1[5];
            do {
              iVar2 = (int)local_10 * 4;
              puVar4 = local_9c + (int)local_10;
              local_10 = (uint *)((int)local_10 + 1);
              *puVar4 = *(uint *)(*(int *)(iVar12 + *(int *)(uVar11 + iVar2) * 4) + 0xc);
            } while (local_10 < (uint *)puVar6[3]);
          }
        }
        local_28 = (uint *)0x0;
        lVar18 = ZEXT48(&local_1c) << 0x20;
        while( true ) {
          local_24 = (uint *)FUN_005f7a5c(lVar18);
          if (local_24 == (uint *)0x0) break;
          local_8c[0] = 0;
          local_8c[1] = 0;
          local_8c[2] = 0;
          local_c = (uint *)0x0;
          local_30 = (int *)0x0;
          local_8c[3] = 0;
          local_8 = (uint *)0x0;
          if (local_24 == (uint *)0x0) {
LAB_00600aca:
            iVar12 = FUN_005f7aa3();
            uVar11 = 0;
            if (iVar12 == 0) {
              do {
                if ((uint *)local_8c[uVar11] == local_24) {
                  local_c = (uint *)0x1;
                  break;
                }
                uVar11 = uVar11 + 1;
              } while (uVar11 < 4);
              if (local_c != (uint *)0x0) goto LAB_00600b2f;
            }
            if ((local_30 != (int *)local_44[*(int *)(*(int *)(param_1[5] + *local_1c * 4) + 8)]) &&
               (uVar11 = 0, puVar6[3] != 0)) {
              do {
                if (local_6c[uVar11] == 0) {
                  local_c = (uint *)0x1;
                  break;
                }
                uVar11 = uVar11 + 1;
              } while (uVar11 < puVar6[3]);
              if (local_c != (uint *)0x0) goto LAB_00600b2f;
            }
            local_8 = (uint *)0x0;
            if (local_24 != (uint *)0x0) {
              do {
                if (local_6c[(int)local_8] == 0) {
                  puVar9 = *(undefined4 **)(param_1[5] + local_1c[(int)local_8] * 4);
                  if (local_8c[puVar9[3]] == 1) {
                    aiStack_ac[(int)local_8] = local_1c[(int)local_8];
                    puVar9[3] = local_9c[(int)local_8];
                  }
                  else {
                    iVar12 = FUN_005f74cf(*puVar9,puVar9[2],local_9c[(int)local_8],0);
                    aiStack_ac[(int)local_8] = iVar12;
                    if (iVar12 == -1) goto LAB_00600f8c;
                    local_3c = (int *)(iVar12 << 2);
                    FUN_005f7cfc();
                    *(undefined4 *)(*(int *)((int)local_3c + param_1[5]) + 0x18) = puVar9[6];
                    local_44[puVar9[2]] = local_44[puVar9[2]] + 1;
                    local_8c[puVar9[3]] = local_8c[puVar9[3]] - 1;
                  }
                }
                else {
                  aiStack_ac[(int)local_8] = *(int *)(puVar6[4] + (int)local_8 * 4);
                }
                local_8 = (uint *)((int)local_8 + 1);
              } while (local_8 < local_24);
            }
            local_10 = (uint *)0x0;
            if (local_24 != (uint *)0x0) {
              do {
                local_38 = *(uint **)(param_1[5] + local_1c[(int)local_10] * 4);
                if (local_38[0x10] == 0) {
                  local_18 = (uint *)0x0;
                  for (puVar4 = local_10; puVar10 = local_18, puVar4 < local_24;
                      puVar4 = (uint *)((int)puVar4 + 1)) {
                    iVar12 = *(int *)(param_1[5] + local_1c[(int)puVar4] * 4);
                    if (local_38[0xb] == *(uint *)(iVar12 + 0x2c)) {
                      local_18 = (uint *)((int)local_18 + 1);
                      aiStack_bc[(int)puVar10] = local_1c[(int)puVar4];
                      aiStack_cc[(int)puVar10] = aiStack_ac[(int)puVar4];
                      *(undefined4 *)(iVar12 + 0x40) = 1;
                    }
                  }
                  puVar4 = *(uint **)(param_1[6] + local_38[0xb] * 4);
                  iVar12 = FUN_005f7b0f();
                  if (((iVar12 != 0) || (iVar12 = FUN_005f7b21(), iVar12 != 0)) ||
                     (iVar12 = FUN_005f7b33(), iVar12 != 0)) {
                    local_8 = (uint *)0x0;
                    if (local_18 != (uint *)0x0) {
                      piVar5 = (int *)puVar4[3];
                      do {
                        local_14 = (int *)0x0;
                        if (piVar5 != (int *)0x0) {
                          piVar7 = (int *)puVar4[4];
                          do {
                            if (*piVar7 == aiStack_bc[(int)local_8]) {
                              puVar1[(int)local_8] = (uint)local_14;
                              break;
                            }
                            local_14 = (int *)((int)local_14 + 1);
                            piVar5 = (int *)puVar4[3];
                            piVar7 = piVar7 + 1;
                          } while (local_14 < piVar5);
                        }
                        local_8 = (uint *)((int)local_8 + 1);
                      } while (local_8 < local_18);
                    }
                    pvVar8 = _malloc(0x38);
                    if (pvVar8 == (void *)0x0) {
                      local_c = (uint *)0x0;
                    }
                    else {
                      local_c = (uint *)FUN_005f7709();
                    }
                    if (local_c == (uint *)0x0) goto LAB_00600f8c;
                    iVar12 = FUN_005f7b0f();
                    puVar10 = local_18;
                    if (iVar12 == 0) {
                      iVar12 = FUN_005f7b21();
                      if (iVar12 == 0) {
                        puVar10 = (uint *)((int)local_18 * 3);
                      }
                      else {
                        puVar10 = (uint *)((int)local_18 * 2);
                      }
                    }
                    local_14 = (int *)FUN_005f7760((*puVar4 ^ (uint)local_18) & 0xffffff ^ *puVar4,
                                                   puVar10,local_18,0);
                    if (-1 < (int)local_14) {
                      local_14 = (int *)FUN_005f7a42();
                      if (-1 < (int)local_14) {
                        local_8 = (uint *)0x0;
                        if (local_18 != (uint *)0x0) {
                          local_3c = (int *)((int)local_18 * 3);
                          local_40 = (uint *)((int)local_18 << 3);
                          local_30 = (int *)((int)local_18 << 2);
                          do {
                            *(int *)(local_c[4] + (int)local_8 * 4) = aiStack_cc[(int)local_8];
                            *(undefined4 *)(local_c[2] + (int)local_8 * 4) =
                                 *(undefined4 *)(puVar4[2] + puVar1[(int)local_8] * 4);
                            if ((uint)((int)local_18 * 2) <= local_c[1]) {
                              *(undefined4 *)((int)local_30 + local_c[2]) =
                                   *(undefined4 *)
                                    (puVar4[2] + (puVar4[3] + puVar1[(int)local_8]) * 4);
                            }
                            if ((int *)((int)local_18 * 3) <= (int *)local_c[1]) {
                              *(undefined4 *)((int)local_40 + local_c[2]) =
                                   *(undefined4 *)
                                    (puVar4[2] + (puVar1[(int)local_8] + puVar4[3] * 2) * 4);
                            }
                            local_8 = (uint *)((int)local_8 + 1);
                            local_30 = local_30 + 1;
                            local_40 = local_40 + 1;
                          } while (local_8 < local_18);
                        }
                        if (*(int *)(param_1[6] + local_38[0xb] * 4) != 0) {
                          FUN_005f7186();
                        }
                        *(uint **)(param_1[6] + local_38[0xb] * 4) = local_c;
                        goto LAB_00600e7a;
                      }
                    }
                    FUN_005f7186();
                    goto LAB_00600644;
                  }
                  local_14 = (int *)0x0;
                  if (puVar4[3] != 0) {
                    do {
                      local_3c = (int *)(puVar4[4] + (int)local_14 * 4);
                      puVar10 = (uint *)0x0;
                      do {
                        if (*local_3c == local_1c[(int)puVar10]) {
                          *local_3c = aiStack_ac[(int)puVar10];
                          break;
                        }
                        puVar10 = (uint *)((int)puVar10 + 1);
                      } while (puVar10 < local_24);
                      local_14 = (int *)((int)local_14 + 1);
                    } while (local_14 < (int *)puVar4[3]);
                  }
                }
LAB_00600e7a:
                local_10 = (uint *)((int)local_10 + 1);
              } while (local_10 < local_24);
            }
            puVar4 = (uint *)0x0;
            if (local_24 != (uint *)0x0) {
              do {
                local_1c[(int)puVar4] = aiStack_ac[(int)puVar4];
                piVar5 = local_1c + (int)puVar4;
                puVar4 = (uint *)((int)puVar4 + 1);
                *(undefined4 *)(*(int *)(param_1[5] + *piVar5 * 4) + 0x40) = 1;
              } while (puVar4 < local_24);
            }
          }
          else {
            do {
              local_14 = *(int **)(param_1[5] + local_1c[(int)local_8] * 4);
              if ((param_1[0x18] != *local_14) || (iVar12 = local_14[0xb], iVar12 == -1)) break;
              if (local_14[0x10] != 0) {
                local_c = (uint *)0x1;
              }
              uVar11 = local_8c[local_14[3]];
              if (uVar11 == 0) {
                local_30 = (int *)((int)local_30 + 1);
              }
              local_8c[local_14[3]] = uVar11 + 1;
              puVar4 = *(uint **)(param_1[6] + iVar12 * 4);
              local_40 = puVar4;
              iVar12 = FUN_005f7b0f();
              if (((iVar12 == 0) && (iVar12 = FUN_005f7b21(), iVar12 == 0)) &&
                 (iVar12 = FUN_005f7b33(), iVar12 == 0)) {
                if ((puVar4[3] < 2) || (local_8 == (uint *)local_14[3])) {
                  iVar12 = local_14[3];
LAB_00600a9d:
                  if (local_8c[iVar12] < 2) goto LAB_00600aa6;
                }
                local_c = (uint *)0x1;
              }
              else {
                if ((local_14[0x10] != 0) &&
                   (local_48 = local_9c[(int)local_8], local_48 != local_14[3])) {
                  local_2c = (uint *)puVar4[3];
                  local_38 = (uint *)0xffffffff;
                  local_10 = (uint *)0xffffffff;
                  local_18 = (uint *)0x0;
                  if (local_2c != (uint *)0x0) {
                    local_3c = local_1c + (int)local_8;
                    local_34 = (int *)puVar4[4];
                    local_4c = *local_3c;
                    do {
                      if (local_4c == *local_34) {
                        local_38 = local_18;
                      }
                      if (local_48 == *(uint *)(*(int *)(param_1[5] + *local_34 * 4) + 0xc)) {
                        local_10 = local_18;
                      }
                      local_18 = (uint *)((int)local_18 + 1);
                      local_34 = local_34 + 1;
                    } while (local_18 < local_2c);
                    if ((local_38 != (uint *)0xffffffff) && (local_10 != (uint *)0xffffffff)) {
                      uVar11 = puVar4[2];
                      local_4c = (int)local_10 * 4;
                      if (((*(int *)(uVar11 + (int)local_38 * 4) == *(int *)(uVar11 + local_4c)) &&
                          ((local_48 = (int)local_2c * 2, puVar4[1] < local_48 ||
                           (puVar4 = local_40,
                           *(int *)(uVar11 + ((int)local_38 + (int)local_2c) * 4) ==
                           *(int *)(uVar11 + ((int)local_10 + (int)local_2c) * 4))))) &&
                         ((puVar4[1] < (uint)((int)local_2c * 3) ||
                          (puVar4 = local_40,
                          *(int *)(uVar11 + ((int)local_38 + local_48) * 4) ==
                          *(int *)(uVar11 + ((int)local_10 + local_48) * 4))))) {
                        *local_3c = *(int *)(local_4c + puVar4[4]);
                      }
                    }
                  }
                }
                iVar12 = (**(code **)(*param_1 + 0x20))();
                if (iVar12 != 0) {
                  iVar12 = local_14[3];
                  goto LAB_00600a9d;
                }
              }
LAB_00600aa6:
              local_8 = (uint *)((int)local_8 + 1);
            } while (local_8 < local_24);
            if (local_8 < local_24) {
              local_c = (uint *)0x1;
            }
            if (local_c == (uint *)0x0) goto LAB_00600aca;
LAB_00600b2f:
            local_6c[0] = 0;
            local_6c[1] = 0;
            local_6c[2] = 0;
            local_6c[3] = 0;
          }
          local_28 = (uint *)((int)local_28 + 1);
          lVar18 = CONCAT44(&local_1c,local_28);
        }
        iVar12 = FUN_005f7aa3();
        puVar4 = local_20;
        if (iVar12 != 0) {
          uVar11 = 0;
          local_28 = (uint *)0x0;
          if (puVar6[3] != 0) {
            do {
              if (local_6c[(int)local_28] == 0) {
                *(undefined4 *)(puVar6[4] + uVar11 * 4) =
                     *(undefined4 *)(puVar6[4] + (int)local_28 * 4);
                *(undefined4 *)(puVar6[2] + uVar11 * 4) =
                     *(undefined4 *)(puVar6[2] + (int)local_28 * 4);
                uVar11 = uVar11 + 1;
              }
              else {
                iVar12 = uVar11 * 4;
                local_3c = *(int **)(param_1[5] + *(int *)(iVar12 + puVar6[4]) * 4);
                if (local_3c[0x11] == 0) {
                  local_3c[0x11] =
                       *(int *)(*(int *)(param_1[5] + *(int *)(iVar12 + puVar6[2]) * 4) + 0x44);
                  *(undefined4 *)(*(int *)(param_1[5] + *(int *)(iVar12 + puVar6[4]) * 4) + 0x48) =
                       *(undefined4 *)
                        (*(int *)(param_1[5] + *(int *)(iVar12 + puVar6[2]) * 4) + 0x48);
                }
              }
              local_28 = (uint *)((int)local_28 + 1);
            } while (local_28 < (uint *)puVar6[3]);
          }
          *puVar6 = -(uint)(uVar11 != 0) & (uVar11 & 0xffffff | 0x10000000);
          puVar6[1] = uVar11;
          puVar6[3] = uVar11;
        }
      }
    }
    local_14 = (int *)0x0;
  }
LAB_00600644:
  _free(local_44);
  return local_14;
}


// ==== 0x600fa7 FUN_00600fa7

uint __fastcall FUN_00600fa7(int param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  undefined4 *puVar11;
  uint *puVar12;
  int *piVar13;
  undefined4 *puVar14;
  int *piVar15;
  uint *puVar16;
  int local_ac [4];
  int local_9c;
  int local_98 [4];
  int local_88 [4];
  int local_78;
  undefined4 *local_74;
  int local_70 [4];
  int local_60;
  uint *local_5c;
  uint local_58;
  int local_54 [4];
  int *local_44;
  uint *local_40;
  uint local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  uint local_28;
  uint *local_24;
  int *local_20;
  uint local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  uint *local_c;
  int *local_8;
  
  uVar3 = 0;
  if ((*(byte *)(param_1 + 0x34) & 8) != 0) {
    return 0;
  }
  local_60 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    do {
      iVar9 = uVar3 * 4;
      uVar3 = uVar3 + 1;
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x10) + iVar9) + 0x10) = 0;
    } while (uVar3 < *(uint *)(param_1 + 4));
  }
  uVar3 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    do {
      piVar6 = *(int **)(*(int *)(param_1 + 0x14) + uVar3 * 4);
      iVar9 = *piVar6;
      if (*(int *)(param_1 + 0x4c) != iVar9) {
        iVar9 = *(int *)(*(int *)(param_1 + 0x10) + iVar9 * 4);
        if ((((*(uint *)(iVar9 + 4) & 2) != 0) && ((*(uint *)(iVar9 + 4) & 0x200) == 0)) &&
           (uVar7 = piVar6[2] + 1, *(uint *)(iVar9 + 0x10) < uVar7)) {
          *(uint *)(iVar9 + 0x10) = uVar7;
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 8));
  }
  uVar3 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    piVar6 = *(int **)(param_1 + 0x10);
    iVar9 = *(int *)(param_1 + 4);
    do {
      uVar3 = uVar3 + *(int *)(*piVar6 + 0x10);
      piVar6 = piVar6 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  local_74 = _malloc(uVar3 << 2);
  if (local_74 == (undefined4 *)0x0) {
LAB_00601cef:
    uVar3 = 0x8007000e;
  }
  else {
    puVar11 = local_74;
    for (uVar3 = uVar3 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar11 = 0;
      puVar11 = puVar11 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)puVar11 = 0;
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    uVar3 = 0;
    iVar9 = 0;
    if (*(int *)(param_1 + 4) != 0) {
      iVar5 = *(int *)(param_1 + 0x10);
      do {
        iVar5 = *(int *)(iVar5 + uVar3 * 4);
        *(uint *)(iVar5 + 0x1c) = -(uint)(*(int *)(iVar5 + 0x10) != 0) & (uint)(local_74 + iVar9);
        iVar5 = *(int *)(param_1 + 0x10);
        iVar9 = iVar9 + *(int *)(*(int *)(iVar5 + uVar3 * 4) + 0x10);
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(param_1 + 4));
    }
    uVar3 = 0;
    if (*(int *)(param_1 + 8) != 0) {
      do {
        piVar6 = *(int **)(*(int *)(param_1 + 0x14) + uVar3 * 4);
        if ((*(int *)(param_1 + 0x4c) != *piVar6) &&
           (iVar9 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar6 * 4) + 0x1c), iVar9 != 0))
        {
          puVar12 = (uint *)(iVar9 + piVar6[2] * 4);
          if (*puVar12 < piVar6[3] + 1U) {
            *puVar12 = piVar6[3] + 1U;
          }
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(param_1 + 8));
    }
    if ((*(uint *)(param_1 + 0x90) & 6) == 0) {
      FUN_005fb8ae();
      local_18 = (int *)0x0;
      if (*(int *)(param_1 + 0xc) != 0) {
        do {
          iVar9 = *(int *)(param_1 + 0x18);
          local_14 = *(int **)(iVar9 + (int)local_18 * 4);
          if (*local_14 == 0x24000001) {
            piVar6 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)local_14[2] * 4);
            piVar15 = *(int **)(*(int *)(param_1 + 0x14) + ((int *)local_14[2])[1] * 4);
            if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar6 * 4) + 4) & 2) != 0) &&
               ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar15 * 4) + 4) & 2) != 0)) {
              piVar6 = *(int **)(iVar9 + piVar6[0xb] * 4);
              piVar15 = *(int **)(iVar9 + piVar15[0xb] * 4);
              local_30 = piVar15;
              local_2c = piVar6;
              if (((*piVar6 == 0x25000001) || (iVar9 = FUN_005f7ac7(), iVar9 != 0)) &&
                 ((*piVar15 == 0x25000001 || (iVar9 = FUN_005f7ac7(), iVar9 != 0)))) {
                local_40 = (uint *)((uint)piVar15[1] >> 1);
                uVar3 = (uint)piVar6[1] >> 1;
                local_10 = (int *)((int)local_40 + uVar3);
                if (((int *)((~*(uint *)(param_1 + 0x90) & 0x20 | 0x40) >> 5) <= local_10) &&
                   (local_10 < (int *)0x5)) {
                  iVar9 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)piVar6[4] * 4);
                  if ((((local_18 == *(int **)(iVar9 + 0x38)) &&
                       (local_18 == *(int **)(iVar9 + 0x3c))) &&
                      (iVar9 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)piVar15[4] * 4),
                      local_18 == *(int **)(iVar9 + 0x38))) && (local_18 == *(int **)(iVar9 + 0x3c))
                     ) {
                    local_20 = (int *)local_2c[2];
                    piVar6 = local_20;
                    piVar15 = local_70;
                    for (uVar7 = uVar3 & 0x3fffffff; piVar10 = local_30, uVar7 != 0;
                        uVar7 = uVar7 - 1) {
                      *piVar15 = *piVar6;
                      piVar6 = piVar6 + 1;
                      piVar15 = piVar15 + 1;
                    }
                    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                      *(char *)piVar15 = (char)*piVar6;
                      piVar6 = (int *)((int)piVar6 + 1);
                      piVar15 = (int *)((int)piVar15 + 1);
                    }
                    local_44 = (int *)piVar10[2];
                    local_3c = (int)local_40 << 2;
                    piVar6 = local_44;
                    piVar15 = local_70 + uVar3;
                    for (uVar7 = (uint)local_40 & 0x3fffffff; piVar10 = local_20, uVar7 != 0;
                        uVar7 = uVar7 - 1) {
                      *piVar15 = *piVar6;
                      piVar6 = piVar6 + 1;
                      piVar15 = piVar15 + 1;
                    }
                    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                      *(char *)piVar15 = (char)*piVar6;
                      piVar6 = (int *)((int)piVar6 + 1);
                      piVar15 = (int *)((int)piVar15 + 1);
                    }
                    piVar6 = piVar10 + uVar3;
                    piVar15 = local_88;
                    for (uVar7 = uVar3 & 0x3fffffff; piVar10 = local_44, uVar7 != 0;
                        uVar7 = uVar7 - 1) {
                      *piVar15 = *piVar6;
                      piVar6 = piVar6 + 1;
                      piVar15 = piVar15 + 1;
                    }
                    for (iVar9 = 0; uVar7 = local_3c, iVar9 != 0; iVar9 = iVar9 + -1) {
                      *(char *)piVar15 = (char)*piVar6;
                      piVar6 = (int *)((int)piVar6 + 1);
                      piVar15 = (int *)((int)piVar15 + 1);
                    }
                    piVar6 = (int *)((int)piVar10 + local_3c);
                    piVar15 = local_88 + uVar3;
                    local_34 = (int *)(uVar3 * 4);
                    for (uVar8 = local_3c >> 2; piVar13 = local_10, piVar10 = local_14, uVar8 != 0;
                        uVar8 = uVar8 - 1) {
                      *piVar15 = *piVar6;
                      piVar6 = piVar6 + 1;
                      piVar15 = piVar15 + 1;
                    }
                    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                      *(char *)piVar15 = (char)*piVar6;
                      piVar6 = (int *)((int)piVar6 + 1);
                      piVar15 = (int *)((int)piVar15 + 1);
                    }
                    iVar9 = FUN_005faf93(local_70,piVar13,0,0,piVar10,0xffffffff);
                    if ((iVar9 == 0) ||
                       (iVar9 = FUN_005faf93(local_88,local_10,0,0,local_14,0xffffffff), iVar9 == 0)
                       ) {
                      piVar15 = local_34;
                      piVar6 = (int *)local_2c[2];
                      piVar10 = piVar6;
                      piVar13 = local_54;
                      for (uVar3 = (uint)local_34 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
                        *piVar13 = *piVar10;
                        piVar10 = piVar10 + 1;
                        piVar13 = piVar13 + 1;
                      }
                      for (uVar3 = (uint)piVar15 & 3; uVar7 = local_3c, uVar3 != 0;
                          uVar3 = uVar3 - 1) {
                        *(char *)piVar13 = (char)*piVar10;
                        piVar10 = (int *)((int)piVar10 + 1);
                        piVar13 = (int *)((int)piVar13 + 1);
                      }
                      local_44 = (int *)local_30[2];
                      puVar11 = (undefined4 *)((int)local_44 + local_3c);
                      puVar14 = (undefined4 *)((int)local_54 + (int)local_34);
                      for (uVar3 = local_3c >> 2; piVar15 = local_34, uVar3 != 0; uVar3 = uVar3 - 1)
                      {
                        *puVar14 = *puVar11;
                        puVar11 = puVar11 + 1;
                        puVar14 = puVar14 + 1;
                      }
                      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                        *(undefined1 *)puVar14 = *(undefined1 *)puVar11;
                        puVar11 = (undefined4 *)((int)puVar11 + 1);
                        puVar14 = (undefined4 *)((int)puVar14 + 1);
                      }
                      piVar6 = (int *)((int)piVar6 + (int)piVar15);
                      piVar10 = local_98;
                      for (uVar3 = (uint)piVar15 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
                        *piVar10 = *piVar6;
                        piVar6 = piVar6 + 1;
                        piVar10 = piVar10 + 1;
                      }
                      for (uVar3 = (uint)piVar15 & 3; uVar7 = local_3c, uVar3 != 0;
                          uVar3 = uVar3 - 1) {
                        *(char *)piVar10 = (char)*piVar6;
                        piVar6 = (int *)((int)piVar6 + 1);
                        piVar10 = (int *)((int)piVar10 + 1);
                      }
                      piVar6 = local_44;
                      piVar15 = (int *)((int)local_98 + (int)piVar15);
                      for (uVar3 = local_3c >> 2; piVar13 = local_10, piVar10 = local_14, uVar3 != 0
                          ; uVar3 = uVar3 - 1) {
                        *piVar15 = *piVar6;
                        piVar6 = piVar6 + 1;
                        piVar15 = piVar15 + 1;
                      }
                      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                        *(char *)piVar15 = (char)*piVar6;
                        piVar6 = (int *)((int)piVar6 + 1);
                        piVar15 = (int *)((int)piVar15 + 1);
                      }
                      iVar9 = FUN_005faf93(local_54,piVar13,0,0,piVar10,0xffffffff);
                      if ((iVar9 == 0) ||
                         (iVar9 = FUN_005faf93(local_98,local_10,0,0,local_14,0xffffffff),
                         iVar9 == 0)) goto LAB_00601424;
                      local_34 = (int *)0x1;
                    }
                    else {
                      local_34 = (int *)0x0;
                    }
                    pvVar4 = _malloc(0x38);
                    if (pvVar4 == (void *)0x0) {
                      local_38 = (int *)0x0;
                    }
                    else {
                      local_38 = (int *)FUN_005f7709();
                    }
                    piVar6 = local_38;
                    if (local_38 == (int *)0x0) goto LAB_00601cef;
                    uVar3 = FUN_005f7760((uint)local_10 & 0xffffff | 0x30000000,(int)local_10 * 2,1,
                                         0);
                    if (((int)uVar3 < 0) || (uVar3 = FUN_005f7a42(local_14), (int)uVar3 < 0))
                    goto LAB_006014dd;
                    *(undefined4 *)piVar6[4] = *(undefined4 *)local_14[4];
                    piVar6 = local_70;
                    if (local_34 != (int *)0x0) {
                      piVar6 = local_54;
                    }
                    piVar15 = (int *)local_38[2];
                    for (uVar3 = (uint)local_10 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                      *piVar15 = *piVar6;
                      piVar6 = piVar6 + 1;
                      piVar15 = piVar15 + 1;
                    }
                    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                      *(char *)piVar15 = (char)*piVar6;
                      piVar6 = (int *)((int)piVar6 + 1);
                      piVar15 = (int *)((int)piVar15 + 1);
                    }
                    piVar6 = local_88;
                    if (local_34 != (int *)0x0) {
                      piVar6 = local_98;
                    }
                    piVar15 = (int *)(local_38[2] + (int)local_10 * 4);
                    for (uVar3 = (uint)local_10 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                      *piVar15 = *piVar6;
                      piVar6 = piVar6 + 1;
                      piVar15 = piVar15 + 1;
                    }
                    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                      *(char *)piVar15 = (char)*piVar6;
                      piVar6 = (int *)((int)piVar6 + 1);
                      piVar15 = (int *)((int)piVar15 + 1);
                    }
                    *(int **)(*(int *)(param_1 + 0x18) + (int)local_18 * 4) = local_38;
                    FUN_005f7186(1);
                    *local_2c = 0;
                    *local_30 = 0;
                  }
                }
              }
            }
          }
LAB_00601424:
          local_18 = (int *)((int)local_18 + 1);
        } while (local_18 < *(int **)(param_1 + 0xc));
      }
    }
    FUN_005fb8ae();
    local_18 = (int *)0x0;
    if (*(int *)(param_1 + 0xc) != 0) {
      do {
        puVar12 = *(uint **)(*(int *)(param_1 + 0x18) + (int)local_18 * 4);
        local_40 = puVar12;
        iVar9 = FUN_005f7b0f();
        if ((((iVar9 != 0) || (iVar9 = FUN_005f7b21(), iVar9 != 0)) ||
            (iVar9 = FUN_005f7b33(), iVar9 != 0)) &&
           ((iVar9 = FUN_005f7aa3(), iVar9 != 0 || ((*(byte *)(param_1 + 0x90) & 6) == 0)))) {
          iVar9 = *(int *)(param_1 + 0x14);
          local_9c = **(int **)(iVar9 + *(int *)puVar12[4] * 4);
          local_3c = *(uint *)(*(int *)(*(int *)(param_1 + 0x10) + local_9c * 4) + 0x1c);
          if (local_3c != 0) {
            local_34 = *(int **)(param_1 + 0xc);
            local_38 = (int *)0x0;
            if (puVar12[1] != 0) {
              local_2c = (int *)puVar12[2];
              local_20 = (int *)puVar12[1];
              do {
                iVar5 = *local_2c;
                while (iVar5 != -1) {
                  piVar6 = *(int **)(iVar9 + iVar5 * 4);
                  if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar6 * 4) + 4) & 2) != 0)
                     && (local_38 < (int *)(piVar6[0xb] + 1))) {
                    local_38 = (int *)(piVar6[0xb] + 1);
                  }
                  iVar5 = piVar6[1];
                }
                local_2c = local_2c + 1;
                local_20 = (int *)((int)local_20 + -1);
              } while (local_20 != (int *)0x0);
            }
            local_44 = local_34;
            if (puVar12[3] != 0) {
              local_20 = (int *)puVar12[3];
              piVar6 = (int *)puVar12[4];
              do {
                piVar15 = *(int **)(iVar9 + *piVar6 * 4);
                if ((int *)piVar15[0xe] < local_44) {
                  local_44 = (int *)piVar15[0xe];
                }
                while (piVar15[1] != -1) {
                  piVar15 = *(int **)(iVar9 + piVar15[1] * 4);
                  if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + *piVar15 * 4) + 4) & 2) != 0)
                     && (local_38 < (int *)(piVar15[0xb] + 1))) {
                    local_38 = (int *)(piVar15[0xb] + 1);
                  }
                }
                piVar6 = piVar6 + 1;
                local_20 = (int *)((int)local_20 + -1);
              } while (local_20 != (int *)0x0);
            }
            local_14 = local_38;
LAB_00601a2f:
            if (local_14 < local_44) {
              if (local_18 == local_14) goto LAB_00601a29;
              local_5c = *(uint **)(*(int *)(param_1 + 0x18) + (int)local_14 * 4);
              local_c = local_5c;
              puVar12 = local_40;
              if (local_18 < local_14) {
                local_c = local_40;
                puVar12 = local_5c;
              }
              local_24 = puVar12;
              if (((*local_c ^ *puVar12) & 0xff000000) != 0) goto LAB_00601a29;
              piVar6 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)local_c[4] * 4);
              puVar11 = *(undefined4 **)(*(int *)(param_1 + 0x14) + *(int *)puVar12[4] * 4);
              local_10 = (int *)*puVar11;
              if ((local_10 != (int *)*piVar6) || (puVar11[1] != piVar6[1])) goto LAB_00601a29;
              local_78 = local_c[1] + puVar12[1];
              local_30 = (int *)local_c[3];
              local_28 = puVar12[3];
              local_1c = (int)local_30 + local_28;
              if (4 < local_1c) goto LAB_00601a29;
              local_2c = (int *)puVar11[2];
              local_20 = (int *)piVar6[2];
              if ((local_2c != local_20) &&
                 ((((*(byte *)(param_1 + 0x90) & 6) != 0 ||
                   ((*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + (int)local_10 * 4) + 4) & 0x10)
                    != 0)) ||
                  (4 < (uint)(*(int *)(local_3c + (int)local_20 * 4) +
                             *(int *)(local_3c + (int)local_2c * 4)))))) goto LAB_00601a29;
              local_8 = local_18;
              if (local_14 <= local_18) {
                local_8 = local_14;
              }
              iVar9 = FUN_005f7aa3();
              if ((iVar9 == 0) && (iVar9 = FUN_005f7ab5(), iVar9 == 0)) {
                iVar9 = FUN_005f7b0f();
                piVar15 = local_8;
                puVar12 = local_c;
                piVar6 = local_30;
                if (iVar9 == 0) {
                  iVar9 = FUN_005f7b21();
                  piVar6 = local_30;
                  if (iVar9 == 0) {
                    iVar9 = FUN_005f7b33();
                    piVar15 = local_30;
                    piVar6 = local_34;
                    if (iVar9 != 0) {
                      iVar9 = (int)local_30 * 4;
                      piVar6 = (int *)local_c[2];
                      piVar10 = local_54;
                      for (uVar3 = (uint)local_30 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                        *piVar10 = *piVar6;
                        piVar6 = piVar6 + 1;
                        piVar10 = piVar10 + 1;
                      }
                      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
                        *(char *)piVar10 = (char)*piVar6;
                        piVar6 = (int *)((int)piVar6 + 1);
                        piVar10 = (int *)((int)piVar10 + 1);
                      }
                      local_10 = (int *)local_24[2];
                      piVar6 = local_10;
                      piVar10 = local_54 + (int)piVar15;
                      for (uVar3 = local_28 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                        *piVar10 = *piVar6;
                        piVar6 = piVar6 + 1;
                        piVar10 = piVar10 + 1;
                      }
                      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
                        *(char *)piVar10 = (char)*piVar6;
                        piVar6 = (int *)((int)piVar6 + 1);
                        piVar10 = (int *)((int)piVar10 + 1);
                      }
                      piVar6 = (int *)(local_c[2] + iVar9);
                      piVar10 = local_70;
                      for (uVar3 = (uint)piVar15 & 0x3fffffff; piVar13 = local_10, uVar3 != 0;
                          uVar3 = uVar3 - 1) {
                        *piVar10 = *piVar6;
                        piVar6 = piVar6 + 1;
                        piVar10 = piVar10 + 1;
                      }
                      for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                        *(char *)piVar10 = (char)*piVar6;
                        piVar6 = (int *)((int)piVar6 + 1);
                        piVar10 = (int *)((int)piVar10 + 1);
                      }
                      piVar6 = piVar13 + local_28;
                      piVar10 = local_70 + (int)piVar15;
                      for (uVar3 = local_28 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                        *piVar10 = *piVar6;
                        piVar6 = piVar6 + 1;
                        piVar10 = piVar10 + 1;
                      }
                      uVar3 = local_c[2];
                      for (iVar9 = 0; piVar13 = local_8, puVar12 = local_c, iVar9 != 0;
                          iVar9 = iVar9 + -1) {
                        *(char *)piVar10 = (char)*piVar6;
                        piVar6 = (int *)((int)piVar6 + 1);
                        piVar10 = (int *)((int)piVar10 + 1);
                      }
                      piVar6 = (int *)(uVar3 + (int)local_30 * 8);
                      piVar10 = local_ac;
                      for (uVar7 = (uint)piVar15 & 0x3fffffff; uVar3 = local_28, uVar7 != 0;
                          uVar7 = uVar7 - 1) {
                        *piVar10 = *piVar6;
                        piVar6 = piVar6 + 1;
                        piVar10 = piVar10 + 1;
                      }
                      for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                        *(char *)piVar10 = (char)*piVar6;
                        piVar6 = (int *)((int)piVar6 + 1);
                        piVar10 = (int *)((int)piVar10 + 1);
                      }
                      piVar6 = local_10 + uVar3 * 2;
                      piVar15 = local_ac + (int)piVar15;
                      for (uVar7 = uVar3 & 0x3fffffff; uVar3 = local_1c, uVar7 != 0;
                          uVar7 = uVar7 - 1) {
                        *piVar15 = *piVar6;
                        piVar6 = piVar6 + 1;
                        piVar15 = piVar15 + 1;
                      }
                      for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                        *(char *)piVar15 = (char)*piVar6;
                        piVar6 = (int *)((int)piVar6 + 1);
                        piVar15 = (int *)((int)piVar15 + 1);
                      }
                      iVar5 = FUN_005faf93(local_54,uVar3,0,0,puVar12,piVar13);
                      local_58 = FUN_005faf93(local_70,local_1c,0,0,local_c,local_8);
                      iVar9 = FUN_005faf93(local_ac,local_1c,0,0,local_c,local_8);
                      piVar6 = local_34;
                      if ((iVar5 != 0) && (local_58 != 0)) goto LAB_00601990;
                    }
                  }
                  else {
                    uVar3 = (int)local_30 * 4;
                    piVar15 = (int *)local_c[2];
                    piVar10 = local_54;
                    for (uVar7 = (uint)local_30 & 0x3fffffff; puVar12 = local_24, uVar7 != 0;
                        uVar7 = uVar7 - 1) {
                      *piVar10 = *piVar15;
                      piVar15 = piVar15 + 1;
                      piVar10 = piVar10 + 1;
                    }
                    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                      *(char *)piVar10 = (char)*piVar15;
                      piVar15 = (int *)((int)piVar15 + 1);
                      piVar10 = (int *)((int)piVar10 + 1);
                    }
                    local_10 = (int *)puVar12[2];
                    piVar15 = local_10;
                    piVar10 = local_54 + (int)local_30;
                    local_30 = (int *)(local_28 << 2);
                    for (uVar7 = local_28 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
                      *piVar10 = *piVar15;
                      piVar15 = piVar15 + 1;
                      piVar10 = piVar10 + 1;
                    }
                    uVar7 = local_c[2];
                    for (iVar9 = 0; piVar13 = local_8, puVar12 = local_c, iVar9 != 0;
                        iVar9 = iVar9 + -1) {
                      *(char *)piVar10 = (char)*piVar15;
                      piVar15 = (int *)((int)piVar15 + 1);
                      piVar10 = (int *)((int)piVar10 + 1);
                    }
                    piVar15 = (int *)(uVar7 + uVar3);
                    piVar10 = local_70;
                    for (uVar8 = (uint)piVar6 & 0x3fffffff; piVar2 = local_10, uVar8 != 0;
                        uVar8 = uVar8 - 1) {
                      *piVar10 = *piVar15;
                      piVar15 = piVar15 + 1;
                      piVar10 = piVar10 + 1;
                    }
                    for (iVar9 = 0; piVar1 = local_30, iVar9 != 0; iVar9 = iVar9 + -1) {
                      *(char *)piVar10 = (char)*piVar15;
                      piVar15 = (int *)((int)piVar15 + 1);
                      piVar10 = (int *)((int)piVar10 + 1);
                    }
                    piVar15 = (int *)((int)piVar2 + (int)local_30);
                    piVar6 = local_70 + (int)piVar6;
                    local_58 = uVar3;
                    for (uVar7 = (uint)local_30 >> 2; uVar3 = local_1c, uVar7 != 0;
                        uVar7 = uVar7 - 1) {
                      *piVar6 = *piVar15;
                      piVar15 = piVar15 + 1;
                      piVar6 = piVar6 + 1;
                    }
                    for (uVar7 = (uint)piVar1 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                      *(char *)piVar6 = (char)*piVar15;
                      piVar15 = (int *)((int)piVar15 + 1);
                      piVar6 = (int *)((int)piVar6 + 1);
                    }
                    iVar9 = FUN_005faf93(local_54,uVar3,0,0,puVar12,piVar13);
                    iVar5 = FUN_005faf93(local_70,local_1c,0,0,local_c,local_8);
                    if ((iVar9 != 0) && (iVar5 != 0)) goto LAB_006019ea;
                    iVar9 = FUN_005f7b67();
                    uVar3 = local_58;
                    piVar6 = local_34;
                    if (iVar9 != 0) {
                      piVar6 = (int *)local_c[2];
                      piVar15 = local_98;
                      for (uVar7 = local_58 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                        *piVar15 = *piVar6;
                        piVar6 = piVar6 + 1;
                        piVar15 = piVar15 + 1;
                      }
                      for (uVar7 = uVar3 & 3; piVar10 = local_30, uVar7 != 0; uVar7 = uVar7 - 1) {
                        *(char *)piVar15 = (char)*piVar6;
                        piVar6 = (int *)((int)piVar6 + 1);
                        piVar15 = (int *)((int)piVar15 + 1);
                      }
                      local_10 = (int *)local_24[2];
                      puVar11 = (undefined4 *)((int)local_10 + (int)local_30);
                      puVar14 = (undefined4 *)((int)local_98 + uVar3);
                      for (uVar7 = (uint)local_30 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                        *puVar14 = *puVar11;
                        puVar11 = puVar11 + 1;
                        puVar14 = puVar14 + 1;
                      }
                      uVar7 = local_c[2];
                      for (uVar8 = (uint)piVar10 & 3; piVar6 = local_8, puVar12 = local_c,
                          uVar8 != 0; uVar8 = uVar8 - 1) {
                        *(undefined1 *)puVar14 = *(undefined1 *)puVar11;
                        puVar11 = (undefined4 *)((int)puVar11 + 1);
                        puVar14 = (undefined4 *)((int)puVar14 + 1);
                      }
                      piVar15 = (int *)(uVar7 + uVar3);
                      piVar10 = local_88;
                      for (uVar8 = uVar3 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                        *piVar10 = *piVar15;
                        piVar15 = piVar15 + 1;
                        piVar10 = piVar10 + 1;
                      }
                      for (uVar7 = uVar3 & 3; piVar13 = local_30, uVar7 != 0; uVar7 = uVar7 - 1) {
                        *(char *)piVar10 = (char)*piVar15;
                        piVar15 = (int *)((int)piVar15 + 1);
                        piVar10 = (int *)((int)piVar10 + 1);
                      }
                      piVar15 = local_10;
                      piVar10 = (int *)((int)local_88 + uVar3);
                      for (uVar7 = (uint)local_30 >> 2; uVar3 = local_1c, uVar7 != 0;
                          uVar7 = uVar7 - 1) {
                        *piVar10 = *piVar15;
                        piVar15 = piVar15 + 1;
                        piVar10 = piVar10 + 1;
                      }
                      for (uVar7 = (uint)piVar13 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                        *(char *)piVar10 = (char)*piVar15;
                        piVar15 = (int *)((int)piVar15 + 1);
                        piVar10 = (int *)((int)piVar10 + 1);
                      }
                      iVar9 = FUN_005faf93(local_98,uVar3,0,0,puVar12,piVar6);
                      iVar5 = FUN_005faf93(local_88,local_1c,0,0,local_c,local_8);
                      piVar6 = local_34;
                      if ((iVar9 != 0) && (iVar5 != 0)) {
                        local_28 = 1;
                        goto LAB_006019ee;
                      }
                    }
                  }
                }
                else {
                  piVar10 = (int *)local_c[2];
                  piVar13 = local_54;
                  for (uVar3 = (uint)local_30 & 0x3fffffff; puVar16 = local_24, uVar3 != 0;
                      uVar3 = uVar3 - 1) {
                    *piVar13 = *piVar10;
                    piVar10 = piVar10 + 1;
                    piVar13 = piVar13 + 1;
                  }
                  for (iVar9 = 0; uVar3 = local_1c, iVar9 != 0; iVar9 = iVar9 + -1) {
                    *(char *)piVar13 = (char)*piVar10;
                    piVar10 = (int *)((int)piVar10 + 1);
                    piVar13 = (int *)((int)piVar13 + 1);
                  }
                  piVar10 = (int *)puVar16[2];
                  piVar6 = local_54 + (int)piVar6;
                  for (uVar7 = local_28; uVar7 != 0; uVar7 = uVar7 - 1) {
                    *piVar6 = *piVar10;
                    piVar10 = piVar10 + 1;
                    piVar6 = piVar6 + 1;
                  }
                  iVar9 = FUN_005faf93(local_54,uVar3,0,0,puVar12,piVar15);
LAB_00601990:
                  piVar6 = local_34;
                  if (iVar9 != 0) goto LAB_006019ea;
                }
LAB_00601a24:
                while (piVar6 < *(int **)(param_1 + 0xc)) {
                  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;
                  if (*(int *)(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0xc) * 4) != 0) {
                    FUN_005f7186(1);
                  }
                }
                goto LAB_00601a29;
              }
              piVar13 = local_30;
              local_10 = (int *)puVar12[2];
              piVar15 = *(int **)(*(int *)(param_1 + 0x14) + *local_10 * 4);
              piVar10 = *(int **)(*(int *)(param_1 + 0x14) + *(int *)local_c[2] * 4);
              piVar6 = local_34;
              if (((*piVar15 != *piVar10) || (piVar15[1] != piVar10[1])) ||
                 (piVar15[2] != piVar10[2])) goto LAB_00601a24;
              piVar6 = (int *)local_c[2];
              piVar15 = local_54;
              for (uVar3 = (uint)local_30 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                *piVar15 = *piVar6;
                piVar6 = piVar6 + 1;
                piVar15 = piVar15 + 1;
              }
              for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                *(char *)piVar15 = (char)*piVar6;
                piVar6 = (int *)((int)piVar6 + 1);
                piVar15 = (int *)((int)piVar15 + 1);
              }
              piVar6 = local_10;
              piVar15 = local_54 + (int)piVar13;
              for (uVar3 = local_28; uVar3 != 0; uVar3 = uVar3 - 1) {
                *piVar15 = *piVar6;
                piVar6 = piVar6 + 1;
                piVar15 = piVar15 + 1;
              }
LAB_006019ea:
              local_28 = 0;
LAB_006019ee:
              if ((local_2c != local_20) &&
                 (piVar6 = local_34,
                 4 < (uint)(*(int *)(local_3c + (int)local_20 * 4) +
                           *(int *)(local_3c + (int)local_2c * 4)))) goto LAB_00601a24;
              pvVar4 = _malloc(0x38);
              if (pvVar4 == (void *)0x0) {
                local_8 = (int *)0x0;
              }
              else {
                local_8 = (int *)FUN_005f7709();
              }
              puVar12 = local_24;
              if (local_8 == (int *)0x0) goto LAB_00601cef;
              uVar3 = FUN_005f7760((*local_24 ^ local_1c) & 0xffffff ^ *local_24,local_78,local_1c,0
                                  );
              if ((-1 < (int)uVar3) && (uVar3 = FUN_005f7a42(puVar12), -1 < (int)uVar3)) {
                if (local_2c != local_20) {
                  uVar3 = 0;
                  if (*(int *)(param_1 + 8) != 0) {
                    do {
                      piVar6 = *(int **)(*(int *)(param_1 + 0x14) + uVar3 * 4);
                      if ((local_9c == *piVar6) && (local_2c == (int *)piVar6[2])) {
                        piVar6[2] = (int)local_20;
                        piVar6[3] = piVar6[3] + *(int *)(local_3c + (int)local_20 * 4);
                      }
                      uVar3 = uVar3 + 1;
                    } while (uVar3 < *(uint *)(param_1 + 8));
                  }
                  piVar6 = (int *)(local_3c + (int)local_20 * 4);
                  piVar15 = (int *)(local_3c + (int)local_2c * 4);
                  *piVar6 = *piVar6 + *piVar15;
                  *piVar15 = 0;
                }
                puVar11 = (undefined4 *)local_c[4];
                puVar14 = (undefined4 *)local_8[4];
                for (uVar3 = local_c[3] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                  *puVar14 = *puVar11;
                  puVar11 = puVar11 + 1;
                  puVar14 = puVar14 + 1;
                }
                for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                  *(undefined1 *)puVar14 = *(undefined1 *)puVar11;
                  puVar11 = (undefined4 *)((int)puVar11 + 1);
                  puVar14 = (undefined4 *)((int)puVar14 + 1);
                }
                puVar11 = (undefined4 *)local_24[4];
                puVar14 = (undefined4 *)(local_8[4] + local_c[3] * 4);
                for (uVar3 = local_24[3] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                  *puVar14 = *puVar11;
                  puVar11 = puVar11 + 1;
                  puVar14 = puVar14 + 1;
                }
                for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                  *(undefined1 *)puVar14 = *(undefined1 *)puVar11;
                  puVar11 = (undefined4 *)((int)puVar11 + 1);
                  puVar14 = (undefined4 *)((int)puVar14 + 1);
                }
                iVar9 = FUN_005f7b0f();
                if (iVar9 != 0) {
                  piVar6 = local_54;
                  piVar15 = (int *)local_8[2];
                  for (uVar3 = local_1c; uVar3 != 0; uVar3 = uVar3 - 1) {
                    *piVar15 = *piVar6;
                    piVar6 = piVar6 + 1;
                    piVar15 = piVar15 + 1;
                  }
                }
                iVar9 = FUN_005f7b21();
                if (iVar9 == 0) {
                  iVar9 = FUN_005f7b33();
                  if (iVar9 != 0) {
                    piVar6 = local_54;
                    piVar15 = (int *)local_8[2];
                    for (uVar3 = local_1c & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                      *piVar15 = *piVar6;
                      piVar6 = piVar6 + 1;
                      piVar15 = piVar15 + 1;
                    }
                    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                      *(char *)piVar15 = (char)*piVar6;
                      piVar6 = (int *)((int)piVar6 + 1);
                      piVar15 = (int *)((int)piVar15 + 1);
                    }
                    piVar6 = local_70;
                    piVar15 = (int *)(local_8[2] + local_1c * 4);
                    for (uVar3 = local_1c & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                      *piVar15 = *piVar6;
                      piVar6 = piVar6 + 1;
                      piVar15 = piVar15 + 1;
                    }
                    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                      *(char *)piVar15 = (char)*piVar6;
                      piVar6 = (int *)((int)piVar6 + 1);
                      piVar15 = (int *)((int)piVar15 + 1);
                    }
                    uVar3 = local_1c << 2;
                    piVar6 = local_ac;
                    piVar15 = (int *)(local_8[2] + local_1c * 8);
                    goto LAB_00601be7;
                  }
                }
                else {
                  piVar6 = local_54;
                  if (local_28 != 0) {
                    piVar6 = local_98;
                  }
                  uVar3 = local_1c * 4;
                  piVar15 = (int *)local_8[2];
                  for (uVar7 = local_1c & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
                    *piVar15 = *piVar6;
                    piVar6 = piVar6 + 1;
                    piVar15 = piVar15 + 1;
                  }
                  for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                    *(char *)piVar15 = (char)*piVar6;
                    piVar6 = (int *)((int)piVar6 + 1);
                    piVar15 = (int *)((int)piVar15 + 1);
                  }
                  piVar6 = local_70;
                  if (local_28 != 0) {
                    piVar6 = local_88;
                  }
                  piVar15 = (int *)(local_8[2] + uVar3);
LAB_00601be7:
                  for (uVar3 = uVar3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
                    *piVar15 = *piVar6;
                    piVar6 = piVar6 + 1;
                    piVar15 = piVar15 + 1;
                  }
                  for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                    *(char *)piVar15 = (char)*piVar6;
                    piVar6 = (int *)((int)piVar6 + 1);
                    piVar15 = (int *)((int)piVar15 + 1);
                  }
                }
                if (local_5c != (uint *)0x0) {
                  FUN_005f7186(1);
                }
                local_3c = (int)local_14 * 4;
                *(int **)(local_3c + *(int *)(param_1 + 0x18)) = local_8;
                *local_40 = 0;
                local_40[1] = 0;
                local_40[3] = 0;
                if (local_34 < *(int **)(param_1 + 0xc)) {
                  local_5c = (uint *)((int)*(int **)(param_1 + 0xc) - (int)local_34);
                  local_20 = (int *)((int)local_5c * 4);
                  local_40 = _malloc((size_t)local_20);
                  if (local_40 != (uint *)0x0) {
                    puVar12 = (uint *)(*(int *)(param_1 + 0x18) + (int)local_34 * 4);
                    puVar16 = local_40;
                    for (uVar3 = (uint)local_20 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
                      *puVar16 = *puVar12;
                      puVar12 = puVar12 + 1;
                      puVar16 = puVar16 + 1;
                    }
                    for (uVar3 = (uint)local_20 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
                      *(char *)puVar16 = (char)*puVar12;
                      puVar12 = (uint *)((int)puVar12 + 1);
                      puVar16 = (uint *)((int)puVar16 + 1);
                    }
                    _memmove((void *)(*(int *)(param_1 + 0x18) +
                                     (int)((int)local_5c + (int)local_14) * 4),
                             (void *)(local_3c + *(int *)(param_1 + 0x18)),
                             ((int)local_34 - (int)local_14) * 4);
                    puVar12 = local_40;
                    puVar16 = (uint *)(*(int *)(param_1 + 0x18) + local_3c);
                    for (uVar3 = (uint)local_20 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
                      *puVar16 = *puVar12;
                      puVar12 = puVar12 + 1;
                      puVar16 = puVar16 + 1;
                    }
                    for (uVar3 = (uint)local_20 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
                      *(char *)puVar16 = (char)*puVar12;
                      puVar12 = (uint *)((int)puVar12 + 1);
                      puVar16 = (uint *)((int)puVar16 + 1);
                    }
                    _free(local_40);
                    goto LAB_00601cae;
                  }
                  goto LAB_00601cef;
                }
LAB_00601cae:
                FUN_005fb8ae();
                local_18 = (int *)((int)local_38 - 1);
                local_60 = 1;
                goto LAB_00601cc3;
              }
              goto LAB_006014dd;
            }
          }
        }
LAB_00601cc3:
        local_18 = (int *)((int)local_18 + 1);
      } while (local_18 < *(int **)(param_1 + 0xc));
    }
    uVar3 = (uint)(local_60 == 0);
  }
LAB_00601cdc:
  _free(local_74);
  return uVar3;
LAB_00601a29:
  local_14 = (int *)((int)local_14 + 1);
  goto LAB_00601a2f;
LAB_006014dd:
  FUN_005f7186(1);
  goto LAB_00601cdc;
}


